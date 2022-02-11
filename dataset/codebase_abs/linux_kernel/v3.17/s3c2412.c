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
static int T_1 F_15 ( void )
{
return F_16 ( & V_31 , NULL ) ;
}
int T_1 F_17 ( void )
{
F_18 ( L_6 ) ;
#ifdef F_19
F_20 ( & V_32 ) ;
F_20 ( & V_33 ) ;
#endif
return F_21 ( & V_34 ) ;
}
