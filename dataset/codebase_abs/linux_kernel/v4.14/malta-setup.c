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
T_2 V_10 ;
if ( V_11 == V_12 ) {
if ( V_13 & V_14 ) {
V_13 |= V_15 ;
F_5 ( L_2 ) ;
V_9 = 1 ;
}
if ( strstr ( F_6 () , L_3 ) ) {
V_13 &= ~ V_16 ;
V_17 = V_17 &
~ ( V_18 |
V_19 ) ;
F_5 ( L_4 ) ;
} else {
V_13 |= V_16 ;
V_17 |=
( V_18 |
V_19 ) ;
F_5 ( L_5 ) ;
}
} else if ( F_7 ( 0 ) != 0 ) {
F_5 ( L_6 ) ;
V_10 = F_8 ( ( T_2 * ) F_9 ( V_20 ) ) ;
if ( ! ( V_10 & V_21 ) ) {
F_10 ( L_7 ) ;
return 0 ;
}
V_9 = 1 ;
}
V_22 = V_9 ;
return V_9 ;
}
static void T_1 F_11 ( void )
{
#ifdef F_12
if ( F_4 () ) {
if ( V_23 == V_24 )
F_5 ( L_8 ) ;
else
F_5 ( L_9 ) ;
} else {
if ( V_23 == V_25 )
F_5 ( L_10 ) ;
else
F_5 ( L_11 ) ;
}
#else
if ( ! F_4 () )
F_13 ( L_12 ) ;
#endif
}
static void T_1 F_14 ( void )
{
unsigned int T_3 * V_26 =
( unsigned int * ) F_15 ( V_27 , sizeof( unsigned int ) ) ;
int V_28 = ( F_8 ( V_26 ) >> 2 ) & 0x07 ;
static const int V_29 [] V_30 = {
33 , 20 , 25 , 30 , 12 , 16 , 37 , 10
} ;
int V_31 = V_29 [ V_28 ] ;
char * V_32 , * V_33 = F_6 () ;
V_32 = strstr ( V_33 , L_13 ) ;
if ( V_32 && ( V_32 == V_33 || V_32 [ - 1 ] == ' ' ) )
return;
if ( V_31 != 33 ) {
F_16 ( L_14 ,
V_31 ) ;
V_33 += strlen ( V_33 ) ;
sprintf ( V_33 , L_15 , V_31 ) ;
if ( V_31 < 20 || V_31 > 66 )
F_16 ( L_16
L_17 ) ;
}
}
static void T_1 F_17 ( void )
{
V_34 = (struct V_34 ) {
. V_35 = 0 ,
. V_36 = 25 ,
. V_37 = 0 ,
. V_38 = 0 ,
. V_39 = 0 ,
. V_40 = 80 ,
. V_41 = 0 ,
. V_42 = 0 ,
. V_43 = 0 ,
. V_44 = 25 ,
. V_45 = V_46 ,
. V_47 = 16
} ;
}
static void T_1 F_18 ( void )
{
char * V_33 ;
V_33 = F_6 () ;
if ( strstr ( V_33 , L_18 ) ) {
V_48 |= V_49 ;
F_5 ( L_19 ) ;
} else
V_48 &= ~ V_49 ;
#ifdef F_19
if ( V_13 & V_14 ) {
V_13 |= V_15 ;
F_5 ( L_2 ) ;
V_33 = F_6 () ;
if ( strstr ( V_33 , L_3 ) ) {
V_13 &= ~ V_16 ;
V_17 = V_17 &
~ ( V_18 |
V_19 ) ;
F_5 ( L_4 ) ;
} else {
V_13 |= V_16 ;
V_17 |=
( V_18 |
V_19 ) ;
F_5 ( L_5 ) ;
}
} else
F_13 ( L_20 ) ;
#endif
}
void T_1 * F_20 ( void )
{
return ( void * ) V_50 ;
}
void T_1 F_21 ( void )
{
unsigned int V_51 ;
void * V_52 = F_20 () ;
V_52 = F_22 ( V_52 ) ;
F_23 ( V_52 ) ;
if ( F_24 ( V_53 ) )
F_5 ( L_21 ) ;
F_25 () ;
for ( V_51 = 0 ; V_51 < F_26 ( V_54 ) ; V_51 ++ )
F_27 ( & V_55 , V_54 + V_51 ) ;
F_28 ( 4 ) ;
#ifdef F_19
if ( V_11 != V_12 )
F_13 ( L_20 ) ;
#endif
if ( V_11 == V_12 )
F_18 () ;
F_11 () ;
F_14 () ;
#ifdef F_29
F_2 () ;
#endif
#if F_30 ( V_56 ) && F_30 ( V_57 )
F_17 () ;
#endif
}
