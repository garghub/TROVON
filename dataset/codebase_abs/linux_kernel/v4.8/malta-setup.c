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
} else if ( F_7 () != 0 ) {
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
if ( V_23 == 0 )
F_5 ( L_8 ) ;
else
F_5 ( L_9 ) ;
} else {
if ( V_23 == 1 )
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
unsigned int T_3 * V_24 =
( unsigned int * ) F_15 ( V_25 , sizeof( unsigned int ) ) ;
int V_26 = ( F_8 ( V_24 ) >> 2 ) & 0x07 ;
static const int V_27 [] V_28 = {
33 , 20 , 25 , 30 , 12 , 16 , 37 , 10
} ;
int V_29 = V_27 [ V_26 ] ;
char * V_30 , * V_31 = F_6 () ;
V_30 = strstr ( V_31 , L_13 ) ;
if ( V_30 && ( V_30 == V_31 || V_30 [ - 1 ] == ' ' ) )
return;
if ( V_29 != 33 ) {
F_16 ( L_14 ,
V_29 ) ;
V_31 += strlen ( V_31 ) ;
sprintf ( V_31 , L_15 , V_29 ) ;
if ( V_29 < 20 || V_29 > 66 )
F_16 ( L_16
L_17 ) ;
}
}
static void T_1 F_17 ( void )
{
V_32 = (struct V_32 ) {
. V_33 = 0 ,
. V_34 = 25 ,
. V_35 = 0 ,
. V_36 = 0 ,
. V_37 = 0 ,
. V_38 = 80 ,
. V_39 = 0 ,
. V_40 = 0 ,
. V_41 = 0 ,
. V_42 = 25 ,
. V_43 = V_44 ,
. V_45 = 16
} ;
}
static void T_1 F_18 ( void )
{
char * V_31 ;
V_31 = F_6 () ;
if ( strstr ( V_31 , L_18 ) ) {
V_46 |= V_47 ;
F_5 ( L_19 ) ;
} else
V_46 &= ~ V_47 ;
#ifdef F_19
if ( V_13 & V_14 ) {
V_13 |= V_15 ;
F_5 ( L_2 ) ;
V_31 = F_6 () ;
if ( strstr ( V_31 , L_3 ) ) {
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
return ( void * ) V_48 ;
}
void T_1 F_21 ( void )
{
unsigned int V_49 ;
void * V_50 = F_20 () ;
V_50 = F_22 ( V_50 ) ;
F_23 ( V_50 ) ;
if ( F_24 ( V_51 ) )
F_5 ( L_21 ) ;
F_25 () ;
for ( V_49 = 0 ; V_49 < F_26 ( V_52 ) ; V_49 ++ )
F_27 ( & V_53 , V_52 + V_49 ) ;
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
#if F_30 ( V_54 ) && F_30 ( V_55 )
F_17 () ;
#endif
V_56 = V_57 ;
V_58 = V_59 ;
}
