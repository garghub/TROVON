void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
#ifdef F_2
#define F_3 ( T_2 , T_3 ) regs->gp[X] = mc->gregs[REG_##Y]
#define F_4 ( T_2 ) regs->gp[X] = mc->gregs[REG_##X]
#define F_5 ( T_2 ) regs->gp[X] = mc->gregs[REG_##X] & 0xffff;
#define F_6 ( T_2 ) regs->gp[X] = (mc->gregs[REG_##X] & 0xffff) | 3;
F_5 ( V_4 ) ; F_5 ( V_5 ) ; F_5 ( V_6 ) ; F_5 ( V_7 ) ;
F_4 ( V_8 ) ; F_4 ( V_9 ) ; F_4 ( V_10 ) ;
F_3 ( V_11 , V_12 ) ;
F_4 ( V_13 ) ; F_4 ( V_14 ) ; F_4 ( V_15 ) ; F_4 ( V_16 ) ;
F_4 ( V_17 ) ; F_6 ( V_18 ) ; F_4 ( V_19 ) ; F_6 ( V_20 ) ;
#else
#define F_3 ( T_2 , T_3 ) regs->gp[X/sizeof(unsigned long)] = mc->gregs[REG_##Y]
#define F_4 ( T_2 ) regs->gp[X/sizeof(unsigned long)] = mc->gregs[REG_##X]
F_4 ( V_21 ) ; F_4 ( V_22 ) ; F_4 ( V_23 ) ; F_4 ( V_24 ) ;
F_4 ( V_25 ) ; F_4 ( V_26 ) ; F_4 ( V_27 ) ; F_4 ( V_28 ) ;
F_4 ( V_29 ) ; F_4 ( V_30 ) ; F_4 ( V_31 ) ; F_4 ( V_32 ) ;
F_4 ( V_33 ) ; F_4 ( V_34 ) ; F_4 ( V_35 ) ; F_4 ( V_36 ) ;
F_4 ( V_37 ) ;
F_3 ( V_38 , V_19 ) ;
F_3 ( V_18 , V_39 ) ;
V_2 -> V_40 [ V_18 / sizeof( unsigned long )] &= 0xffff ;
V_2 -> V_40 [ V_18 / sizeof( unsigned long )] |= 3 ;
#endif
}
