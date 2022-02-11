int main ( void )
{
#ifdef F_1
F_2 ( V_1 , V_2 , V_3 ) ;
F_2 ( V_4 , V_5 , V_6 ) ;
F_2 ( V_7 , V_5 , V_8 ) ;
F_3 () ;
#endif
#if F_4 ( V_9 ) && F_4 ( V_10 )
F_2 ( V_11 , V_12 , V_13 ) ;
F_3 () ;
#endif
#define F_5 ( T_1 ) OFFSET(pt_regs_ ## entry, pt_regs, entry)
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
F_5 ( V_27 ) ;
F_5 ( V_28 ) ;
F_5 ( V_29 ) ;
F_3 () ;
#undef F_5
#define F_5 ( T_1 ) OFFSET(saved_context_ ## entry, saved_context, entry)
F_5 ( V_30 ) ;
F_5 ( V_31 ) ;
F_5 ( V_32 ) ;
F_5 ( V_33 ) ;
F_5 ( V_34 ) ;
F_5 ( V_35 ) ;
F_3 () ;
#undef F_5
F_2 ( V_36 , V_37 , V_38 . V_39 ) ;
F_2 ( V_40 , V_37 , V_38 . V_41 ) ;
F_3 () ;
#ifdef F_6
DEFINE ( V_42 , F_7 ( union V_43 , V_44 ) ) ;
F_3 () ;
#endif
DEFINE ( V_45 , sizeof( V_46 ) - 1 ) ;
DEFINE ( V_47 , sizeof( V_46 ) ) ;
DEFINE ( V_48 , sizeof( V_49 ) - 1 ) ;
DEFINE ( V_50 , sizeof( V_49 ) ) ;
return 0 ;
}
