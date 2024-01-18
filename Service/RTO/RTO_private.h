/******************  name : Eman Abd Elhamed  ********************/
/******************  Date :   24 november 2023   ********************/
/******************   SW  :       RTO       ********************/
/******************  version :     1.0       ********************/
#ifndef RTO_PRIVATE_H
#define RTO_PRIVATE_H

typedef struct
{
	u16 first_delay;
	u16 periodicity;
	void(*pf)(void);
}RTO_TCB;

static ES_t  RTO_enum_Scheduler(void);

#endif
