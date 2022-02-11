static inline void F_1 ( void )
{
V_1 = V_2 + 0x10 ;
}
void T_1 F_2 ( struct V_3 * V_4 , int V_5 )
{
F_3 ( L_1 , V_6 , V_4 , V_5 ) ;
V_7 . V_8 = L_2 ;
V_9 . V_8 = L_3 ;
F_4 ( L_4 ) ;
V_7 . V_10 [ 1 ] . V_11 = V_12 ;
V_7 . V_10 [ 1 ] . V_13 = V_12 ;
V_14 . V_8 = L_5 ;
V_14 . V_10 [ 0 ] . V_13 = V_15 + 0x24 ;
V_16 . V_8 = L_5 ;
V_16 . V_10 [ 0 ] . V_11 = V_15 + V_17 ;
V_16 . V_10 [ 0 ] . V_13 = V_15 + V_17 + 0x24 ;
}
static void F_5 ( void )
{
unsigned long V_18 ;
V_18 = F_6 ( V_19 ) ;
V_18 &= ~ V_20 ;
V_18 |= V_21 ;
F_7 ( V_18 , V_19 ) ;
F_8 () ;
}
void F_9 ( enum V_22 V_23 , const char * V_24 )
{
if ( V_23 == V_25 )
F_10 ( 0 ) ;
F_7 ( 0x00 , V_26 ) ;
F_7 ( V_27 , V_28 ) ;
F_11 ( 1 ) ;
}
void T_1 F_12 ( void )
{
F_1 () ;
V_29 = F_5 ;
F_13 ( V_30 , F_14 ( V_30 ) ) ;
}
void T_2 F_15 ( void )
{
struct V_31 * V_32 ;
unsigned long V_18 ;
unsigned long V_33 ;
unsigned long V_34 ;
unsigned long V_35 ;
unsigned long V_36 ;
V_32 = F_16 ( NULL , L_6 ) ;
V_33 = F_17 ( V_32 ) ;
F_18 ( V_32 ) ;
V_34 = F_19 ( F_6 ( V_37 ) , V_33 * 2 ) ;
V_38 . V_39 = V_34 ;
V_18 = F_6 ( V_40 ) ;
V_35 = V_34 / ( ( V_18 & V_41 ) + 1 ) ;
V_35 /= ( ( V_18 & V_42 ) ? 2 : 1 ) ;
V_36 = V_35 / ( ( V_18 & V_43 ) ? 2 : 1 ) ;
F_20 ( L_7 ,
F_21 ( V_34 ) , F_21 ( V_35 ) , F_21 ( V_36 ) ) ;
F_22 ( V_34 , V_35 , V_36 ) ;
}
void T_1 F_23 ( int V_33 )
{
F_24 ( V_33 ) ;
F_15 () ;
F_25 () ;
}
static int T_1 F_26 ( void )
{
return F_27 ( & V_44 , NULL ) ;
}
int T_1 F_28 ( void )
{
F_20 ( L_8 ) ;
#ifdef F_29
F_30 ( & V_45 ) ;
F_30 ( & V_46 ) ;
#endif
return F_31 ( & V_47 ) ;
}
