#include "neuron_base.h"

namespace n {

	neuron_base::neuron_base() : act_code(NULL), _value(NULL) {}

	inline _value_t neuron_base::getVal() {
		return _value;
	}

}