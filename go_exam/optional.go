package main

import "fmt"

func main() {
	fmt.Println("vim-go")
}

type Optional struct {
	_isValid bool
	value    interface{}
}

func (o *Optional) identity(v interface{}) Optional {
	return Optional{_isValid: true, value: v}
}

type OptionalFunc func(interface{}) Optional

func (o *Optional) compose(f OptionalFunc, g OptionalFunc) OptionalFunc {
	return func(x interface{}) Optional {
		o1 := f(x)
		if o1._isValid {
			return g(o1.value)
		} else {
			return Optional{_isValid: false}
		}
	}
}
