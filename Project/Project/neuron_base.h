#ifndef _NEURON_BASE_
#define _NEURON_BASE_

#ifndef NULL
#include <vcruntime.h>
#endif

namespace n {

	using _value_t		= float;
	using act_code_t	= size_t;

	class neuron_base {
	public:
		neuron_base();
		virtual ~neuron_base() = NULL;

		virtual _value_t activate(act_code_t) = NULL;

		inline _value_t getVal();

	protected:
		act_code_t act_code;
		_value_t _value;
	};

	using _Nodeptr = neuron_base*;

}

#endif