const char * F_1 ( void )
{
return L_1 ;
}
static void T_1 F_2 ( void )
{
F_3 ( V_1 , V_2 ) ;
F_3 ( V_3 , V_2 ) ;
F_3 ( V_4 , V_5 ) ;
F_3 ( V_6 , V_2 ) ;
F_3 ( V_7 , V_5 ) ;
F_3 ( V_8 , V_2 ) ;
}
static void T_1 F_4 ( void )
{
unsigned int T_2 * V_9 =
( unsigned int * ) F_5 ( V_10 , sizeof( unsigned int ) ) ;
int V_11 = ( F_6 ( V_9 ) >> 2 ) & 0x07 ;
static const int V_12 [] V_13 = {
33 , 20 , 25 , 30 , 12 , 16 , 37 , 10
} ;
int V_14 = V_12 [ V_11 ] ;
char * V_15 = F_7 () ;
if ( V_14 != 33 && ! strstr ( V_15 , L_2 ) ) {
F_8 ( V_16 L_3
L_4 , V_14 ) ;
V_15 += strlen ( V_15 ) ;
sprintf ( V_15 , L_5 , V_14 ) ;
if ( V_14 < 20 || V_14 > 66 )
F_8 ( V_16 L_6
L_7 ) ;
}
}
static void T_1 F_9 ( void )
{
V_17 = (struct V_17 ) {
. V_18 = 0 ,
. V_19 = 25 ,
. V_20 = 0 ,
. V_21 = 0 ,
. V_22 = 0 ,
. V_23 = 80 ,
. V_24 = 0 ,
. V_25 = 0 ,
. V_26 = 0 ,
. V_27 = 25 ,
. V_28 = V_29 ,
. V_30 = 16
} ;
}
static void T_1 F_10 ( void )
{
char * V_15 ;
V_15 = F_7 () ;
if ( strstr ( V_15 , L_8 ) ) {
V_31 |= V_32 ;
F_8 ( V_33 L_9 ) ;
} else
V_31 &= ~ V_32 ;
#ifdef F_11
if ( V_34 & V_35 ) {
V_34 |= V_36 ;
F_8 ( V_33 L_10 ) ;
V_15 = F_7 () ;
if ( strstr ( V_15 , L_11 ) ) {
V_34 &= ~ V_37 ;
V_38 = V_38 &
~ ( V_39 |
V_40 ) ;
F_8 ( V_33 L_12 ) ;
} else {
V_34 |= V_37 ;
V_38 |=
( V_39 |
V_40 ) ;
F_8 ( V_33 L_13 ) ;
}
} else
F_12 ( L_14 ) ;
#endif
}
void T_1 F_13 ( void )
{
unsigned int V_41 ;
F_14 () ;
for ( V_41 = 0 ; V_41 < F_15 ( V_42 ) ; V_41 ++ )
F_16 ( & V_43 , V_42 + V_41 ) ;
F_17 ( 4 ) ;
#ifdef F_11
if ( V_44 != V_45 )
F_12 ( L_14 ) ;
#endif
if ( V_44 == V_45 )
F_10 () ;
#ifdef F_18
F_4 () ;
#endif
#ifdef F_19
F_2 () ;
#endif
#if F_20 ( V_46 ) && F_20 ( V_47 )
F_9 () ;
#endif
V_48 = V_49 ;
V_50 = V_51 ;
}
