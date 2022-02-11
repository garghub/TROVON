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
static int T_1 F_4 ( void )
{
int V_9 = 0 ;
if ( V_10 == V_11 ) {
if ( V_12 & V_13 ) {
V_12 |= V_14 ;
F_5 ( L_2 ) ;
V_9 = 1 ;
}
if ( strstr ( F_6 () , L_3 ) ) {
V_12 &= ~ V_15 ;
V_16 = V_16 &
~ ( V_17 |
V_18 ) ;
F_5 ( L_4 ) ;
} else {
V_12 |= V_15 ;
V_16 |=
( V_17 |
V_18 ) ;
F_5 ( L_5 ) ;
}
} else if ( F_7 () != 0 ) {
F_5 ( L_6 ) ;
if ( ( * ( unsigned int * ) 0xbf403000 & 0x81 ) != 0x81 ) {
F_8 ( L_7 ) ;
return 0 ;
}
V_9 = 1 ;
}
V_19 = V_9 ;
return V_9 ;
}
static void T_1 F_9 ( void )
{
#ifdef F_10
if ( F_4 () ) {
if ( V_20 == 0 )
F_5 ( L_8 ) ;
else
F_5 ( L_9 ) ;
} else {
if ( V_20 == 1 )
F_5 ( L_10 ) ;
else
F_5 ( L_11 ) ;
}
#else
if ( ! F_4 () )
F_11 ( L_12 ) ;
#endif
}
static void T_1 F_12 ( void )
{
unsigned int T_2 * V_21 =
( unsigned int * ) F_13 ( V_22 , sizeof( unsigned int ) ) ;
int V_23 = ( F_14 ( V_21 ) >> 2 ) & 0x07 ;
static const int V_24 [] V_25 = {
33 , 20 , 25 , 30 , 12 , 16 , 37 , 10
} ;
int V_26 = V_24 [ V_23 ] ;
char * V_27 = F_6 () ;
if ( V_26 != 33 && ! strstr ( V_27 , L_13 ) ) {
F_15 ( L_14 ,
V_26 ) ;
V_27 += strlen ( V_27 ) ;
sprintf ( V_27 , L_15 , V_26 ) ;
if ( V_26 < 20 || V_26 > 66 )
F_15 ( L_16 ) ;
}
}
static void T_1 F_16 ( void )
{
V_28 = (struct V_28 ) {
. V_29 = 0 ,
. V_30 = 25 ,
. V_31 = 0 ,
. V_32 = 0 ,
. V_33 = 0 ,
. V_34 = 80 ,
. V_35 = 0 ,
. V_36 = 0 ,
. V_37 = 0 ,
. V_38 = 25 ,
. V_39 = V_40 ,
. V_41 = 16
} ;
}
static void T_1 F_17 ( void )
{
char * V_27 ;
V_27 = F_6 () ;
if ( strstr ( V_27 , L_17 ) ) {
V_42 |= V_43 ;
F_5 ( L_18 ) ;
} else
V_42 &= ~ V_43 ;
#ifdef F_18
if ( V_12 & V_13 ) {
V_12 |= V_14 ;
F_5 ( L_2 ) ;
V_27 = F_6 () ;
if ( strstr ( V_27 , L_3 ) ) {
V_12 &= ~ V_15 ;
V_16 = V_16 &
~ ( V_17 |
V_18 ) ;
F_5 ( L_4 ) ;
} else {
V_12 |= V_15 ;
V_16 |=
( V_17 |
V_18 ) ;
F_5 ( L_5 ) ;
}
} else
F_11 ( L_19 ) ;
#endif
}
void T_1 F_19 ( void )
{
unsigned int V_44 ;
F_20 () ;
for ( V_44 = 0 ; V_44 < F_21 ( V_45 ) ; V_44 ++ )
F_22 ( & V_46 , V_45 + V_44 ) ;
F_23 ( 4 ) ;
#ifdef F_18
if ( V_10 != V_11 )
F_11 ( L_19 ) ;
#endif
if ( V_10 == V_11 )
F_17 () ;
F_9 () ;
#ifdef F_24
F_12 () ;
#endif
#ifdef F_25
F_2 () ;
#endif
#if F_26 ( V_47 ) && F_26 ( V_48 )
F_16 () ;
#endif
V_49 = V_50 ;
V_51 = V_52 ;
}
