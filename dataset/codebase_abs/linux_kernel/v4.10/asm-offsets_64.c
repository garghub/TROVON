int main ( void )
{
#ifdef F_1
F_2 ( V_1 , V_2 , V_3 ) ;
F_2 ( V_4 , V_5 , V_6 ) ;
F_2 ( V_7 , V_5 , V_8 ) ;
F_3 () ;
#endif
#define F_4 ( T_1 ) OFFSET(pt_regs_ ## entry, pt_regs, entry)
F_4 ( V_9 ) ;
F_4 ( V_10 ) ;
F_4 ( V_11 ) ;
F_4 ( V_12 ) ;
F_4 ( V_13 ) ;
F_4 ( V_14 ) ;
F_4 ( V_15 ) ;
F_4 ( V_16 ) ;
F_4 ( V_17 ) ;
F_4 ( V_18 ) ;
F_4 ( V_19 ) ;
F_4 ( V_20 ) ;
F_4 ( V_21 ) ;
F_4 ( V_22 ) ;
F_4 ( V_23 ) ;
F_4 ( V_24 ) ;
F_3 () ;
#undef F_4
#define F_4 ( T_1 ) OFFSET(saved_context_ ## entry, saved_context, entry)
F_4 ( V_25 ) ;
F_4 ( V_26 ) ;
F_4 ( V_27 ) ;
F_4 ( V_28 ) ;
F_4 ( V_29 ) ;
F_4 ( V_30 ) ;
F_3 () ;
#undef F_4
F_2 ( V_31 , V_32 , V_33 . V_34 ) ;
F_2 ( V_35 , V_32 , V_33 . V_36 ) ;
F_3 () ;
#ifdef F_5
DEFINE ( V_37 , F_6 ( union V_38 , V_39 ) ) ;
F_3 () ;
#endif
DEFINE ( V_40 , sizeof( V_41 ) - 1 ) ;
DEFINE ( V_42 , sizeof( V_41 ) ) ;
DEFINE ( V_43 , sizeof( V_44 ) - 1 ) ;
DEFINE ( V_45 , sizeof( V_44 ) ) ;
return 0 ;
}
