int main ( void )
{
#ifdef F_1
F_2 ( V_1 , V_2 , V_3 ) ;
F_2 ( V_4 , V_5 , V_6 ) ;
F_2 ( V_7 , V_5 , V_8 ) ;
F_2 ( V_9 , V_5 , V_10 ) ;
F_3 () ;
#endif
#ifdef F_4
F_2 ( V_11 , V_12 , V_13 ) ;
F_3 () ;
#define F_5 ( T_1 ) OFFSET(IA32_SIGCONTEXT_ ## entry, sigcontext_ia32, entry)
F_5 ( V_14 ) ;
F_5 ( V_15 ) ;
F_5 ( V_16 ) ;
F_5 ( V_17 ) ;
F_5 ( V_18 ) ;
F_5 ( V_19 ) ;
F_5 ( V_20 ) ;
F_5 ( V_21 ) ;
F_5 ( V_22 ) ;
F_3 () ;
#undef F_5
F_2 ( V_23 , V_24 , V_25 . V_26 ) ;
F_3 () ;
#endif
#define F_5 ( T_1 ) OFFSET(pt_regs_ ## entry, pt_regs, entry)
F_5 ( V_15 ) ;
F_5 ( V_16 ) ;
F_5 ( V_17 ) ;
F_5 ( V_21 ) ;
F_5 ( V_20 ) ;
F_5 ( V_18 ) ;
F_5 ( V_19 ) ;
F_5 ( V_27 ) ;
F_5 ( V_28 ) ;
F_5 ( V_29 ) ;
F_5 ( V_30 ) ;
F_5 ( V_31 ) ;
F_5 ( V_32 ) ;
F_5 ( V_33 ) ;
F_5 ( V_34 ) ;
F_5 ( V_35 ) ;
F_3 () ;
#undef F_5
#define F_5 ( T_1 ) OFFSET(saved_context_ ## entry, saved_context, entry)
F_5 ( V_36 ) ;
F_5 ( V_37 ) ;
F_5 ( V_38 ) ;
F_5 ( V_39 ) ;
F_5 ( V_40 ) ;
F_5 ( V_41 ) ;
F_3 () ;
#undef F_5
F_2 ( V_42 , V_43 , V_44 . V_45 ) ;
F_3 () ;
DEFINE ( V_46 , sizeof( V_47 ) - 1 ) ;
DEFINE ( V_48 , sizeof( V_47 ) ) ;
DEFINE ( V_49 , sizeof( V_50 ) - 1 ) ;
DEFINE ( V_51 , sizeof( V_50 ) ) ;
return 0 ;
}
