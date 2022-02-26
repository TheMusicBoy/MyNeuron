#ifndef _NEURON_BASE_
#define _NEURON_BASE_

#ifndef NULL
#include <vcruntime.h>
#endif

#include <list>

namespace n {

	using _value_t		= float;
	using act_code_t	= size_t;
	using weight		= float;

	class neuron_base {
	public:
		neuron_base();

		virtual _value_t activate(act_code_t) = NULL;

		virtual inline _value_t getVal();

	protected:
		act_code_t act_code;
		_value_t _value;
	};

	using neuron_ptr = neuron_base*;

	struct Synaps;

	struct Synaps_ptr {
		Synaps_ptr(Synaps* ptr);
		~Synaps_ptr();

		inline Synaps& operator*();
		
		Synaps* synaps;
	};

	class ineuron_base : virtual public neuron_base {
	public:
		ineuron_base();
		virtual ~ineuron_base();

		virtual void addOutput(Synaps_ptr output_neuron);

	protected:
		
		std::list<Synaps_ptr> output_neurons;

	};

	using ineuron_ptr = ineuron_base*;

	class oneuron_base : virtual public neuron_base {
	public:
		oneuron_base();
		virtual ~oneuron_base() = NULL;

		virtual void addInput(Synaps_ptr input_neuron);

	protected:

		std::list<Synaps_ptr> input_neurons;
	};

	using oneuron_ptr = oneuron_base*;

	struct Synaps {
		Synaps(ineuron_ptr input_ptr, oneuron_ptr output_ptr);
		ineuron_ptr input;
		oneuron_ptr output;
		weight weight;
	};

	class mneuron_base : virtual public ineuron_base, virtual public oneuron_base {
	public:
		mneuron_base();
		~mneuron_base();
	};
}

#endif