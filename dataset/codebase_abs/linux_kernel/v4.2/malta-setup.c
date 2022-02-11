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
char * V_27 , * V_28 = F_6 () ;
V_27 = strstr ( V_28 , L_13 ) ;
if ( V_27 && ( V_27 == V_28 || V_27 [ - 1 ] == ' ' ) )
return;
if ( V_26 != 33 ) {
F_15 ( L_14 ,
V_26 ) ;
V_28 += strlen ( V_28 ) ;
sprintf ( V_28 , L_15 , V_26 ) ;
if ( V_26 < 20 || V_26 > 66 )
F_15 ( L_16
L_17 ) ;
}
}
static void T_1 F_16 ( void )
{
V_29 = (struct V_29 ) {
. V_30 = 0 ,
. V_31 = 25 ,
. V_32 = 0 ,
. V_33 = 0 ,
. V_34 = 0 ,
. V_35 = 80 ,
. V_36 = 0 ,
. V_37 = 0 ,
. V_38 = 0 ,
. V_39 = 25 ,
. V_40 = V_41 ,
. V_42 = 16
} ;
}
static void T_1 F_17 ( void )
{
char * V_28 ;
V_28 = F_6 () ;
if ( strstr ( V_28 , L_18 ) ) {
V_43 |= V_44 ;
F_5 ( L_19 ) ;
} else
V_43 &= ~ V_44 ;
#ifdef F_18
if ( V_12 & V_13 ) {
V_12 |= V_14 ;
F_5 ( L_2 ) ;
V_28 = F_6 () ;
if ( strstr ( V_28 , L_3 ) ) {
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
F_11 ( L_20 ) ;
#endif
}
void T_1 F_19 ( void )
{
unsigned int V_45 ;
F_20 ( V_46 ) ;
if ( F_21 ( V_47 ) )
F_5 ( L_21 ) ;
F_22 () ;
for ( V_45 = 0 ; V_45 < F_23 ( V_48 ) ; V_45 ++ )
F_24 ( & V_49 , V_48 + V_45 ) ;
F_25 ( 4 ) ;
#ifdef F_18
if ( V_10 != V_11 )
F_11 ( L_20 ) ;
#endif
if ( V_10 == V_11 )
F_17 () ;
F_9 () ;
F_12 () ;
#ifdef F_26
F_2 () ;
#endif
#if F_27 ( V_50 ) && F_27 ( V_51 )
F_16 () ;
#endif
V_52 = V_53 ;
V_54 = V_55 ;
}
