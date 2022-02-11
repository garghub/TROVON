int main ( void )
{
#ifdef F_1
F_2 ( V_1 , V_2 , V_3 ) ;
F_2 ( V_4 , V_2 , V_5 ) ;
F_3 () ;
#endif
#if F_4 ( V_6 ) && F_4 ( V_7 )
F_2 ( V_8 , V_9 , V_10 ) ;
F_3 () ;
#endif
#define F_5 ( T_1 ) OFFSET(pt_regs_ ## entry, pt_regs, entry)
F_5 ( V_11 ) ;
F_5 ( V_12 ) ;
F_5 ( V_13 ) ;
F_5 ( V_14 ) ;
F_5 ( V_15 ) ;
F_5 ( V_16 ) ;
F_5 ( V_17 ) ;
F_5 ( V_18 ) ;
F_5 ( V_19 ) ;
F_5 ( V_20 ) ;
F_5 ( V_21 ) ;
F_5 ( V_22 ) ;
F_5 ( V_23 ) ;
F_5 ( V_24 ) ;
F_5 ( V_25 ) ;
F_5 ( V_26 ) ;
F_3 () ;
#undef F_5
#define F_5 ( T_1 ) OFFSET(saved_context_ ## entry, saved_context, entry)
F_5 ( V_27 ) ;
F_5 ( V_28 ) ;
F_5 ( V_29 ) ;
F_5 ( V_30 ) ;
F_5 ( V_31 ) ;
F_5 ( V_32 ) ;
F_3 () ;
#undef F_5
F_2 ( V_33 , V_34 , V_35 . V_36 ) ;
F_2 ( V_37 , V_34 , V_35 . V_38 ) ;
F_3 () ;
#ifdef F_6
DEFINE ( V_39 , F_7 ( union V_40 , V_41 ) ) ;
F_3 () ;
#endif
DEFINE ( V_42 , sizeof( V_43 ) - 1 ) ;
DEFINE ( V_44 , sizeof( V_43 ) ) ;
DEFINE ( V_45 , sizeof( V_46 ) - 1 ) ;
DEFINE ( V_47 , sizeof( V_46 ) ) ;
return 0 ;
}
