static void
F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
unsigned int V_4 , V_5 ;
V_4 = F_2 ( V_6 , V_7 ) ;
if ( V_4 & V_8 ) {
F_3 () ;
if( V_4 == V_8 )
return;
}
V_4 >>= 1 ;
V_5 = V_9 ;
while ( V_4 ) {
if ( V_4 & 1 )
F_4 ( V_5 ) ;
V_5 ++ ;
V_4 >>= 1 ;
}
}
static T_1
F_5 ( int V_5 , void * V_10 )
{
F_1 ( 0 , NULL ) ;
return V_11 ;
}
static void inline F_6 ( unsigned int V_5 )
{
unsigned int V_12 ;
V_12 = 2 << ( ( V_5 == V_13 ) ? 4 : ( V_5 - V_9 ) ) ;
F_2 ( V_6 , V_14 ) &= ~ V_12 ;
}
static void inline F_7 ( struct V_15 * V_16 )
{
F_6 ( V_16 -> V_5 ) ;
}
static void inline F_8 ( struct V_15 * V_16 )
{
unsigned int V_12 ;
V_12 = 2 << ( ( V_16 -> V_5 == V_13 ) ? 4 : ( V_16 -> V_5 - V_9 ) ) ;
F_2 ( V_6 , V_14 ) |= V_12 ;
}
void T_2 F_9 ( void )
{
V_17 = V_18 ;
F_2 ( V_6 , V_19 ) = V_20 ;
F_2 ( V_6 , V_21 ) = V_22 ;
F_2 ( V_6 , V_21 ) = V_23 | V_24 ;
F_2 ( V_6 , V_14 ) = V_25 | V_26 ;
F_10 ( V_27 , & V_28 ) ;
}
void T_2 F_11 ( void )
{
int V_5 ;
F_2 ( V_29 , V_30 ) = 0x0 ;
for ( V_5 = V_9 ;
V_5 < F_12 ( V_31 ) ; V_5 ++ ) {
F_6 ( V_5 ) ;
F_13 ( V_5 , & V_32 ,
V_33 ) ;
F_14 ( V_5 , V_34 ) ;
}
F_15 ( V_35 , F_1 ) ;
F_16 () ;
}
void T_2 F_17 ( void )
{
F_2 ( V_36 , V_37 ) |= V_38 | V_39 | V_40 ;
F_2 ( V_41 , V_42 ) = V_43 ;
F_2 ( V_44 , V_42 ) = V_43 ;
#ifdef F_18
F_2 ( V_45 , V_42 ) = V_43 ;
F_2 ( V_46 , V_42 ) = V_43 ;
F_19 ( V_47 ) = V_48 | V_49 |
V_50 | V_51 ;
#endif
( void ) F_20 ( V_52 , F_21 ( V_52 ) ) ;
}
