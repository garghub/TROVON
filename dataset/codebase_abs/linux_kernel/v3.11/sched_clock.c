static T_1 T_2 F_1 ( void )
{
return ( T_1 ) ( V_1 - V_2 ) ;
}
static inline T_3 T_2 F_2 ( T_3 V_3 , T_1 V_4 , T_1 V_5 )
{
return ( V_3 * V_4 ) >> V_5 ;
}
static unsigned long long T_2 F_3 ( void )
{
T_3 V_6 ;
T_1 V_7 ;
T_1 V_3 ;
if ( V_8 . V_9 )
return V_8 . V_6 ;
do {
V_7 = V_8 . V_7 ;
F_4 () ;
V_6 = V_8 . V_6 ;
F_4 () ;
} while ( V_7 != V_8 . V_10 );
V_3 = F_5 () ;
V_3 = ( V_3 - V_7 ) & V_11 ;
return V_6 + F_2 ( V_3 , V_8 . V_4 , V_8 . V_5 ) ;
}
static void T_2 F_6 ( void )
{
unsigned long V_12 ;
T_1 V_3 ;
T_3 V_13 ;
V_3 = F_5 () ;
V_13 = V_8 . V_6 +
F_2 ( ( V_3 - V_8 . V_7 ) & V_11 ,
V_8 . V_4 , V_8 . V_5 ) ;
F_7 ( V_12 ) ;
V_8 . V_10 = V_3 ;
F_8 () ;
V_8 . V_6 = V_13 ;
F_8 () ;
V_8 . V_7 = V_3 ;
F_9 ( V_12 ) ;
}
static void F_10 ( unsigned long V_14 )
{
F_11 ( & V_15 , F_12 ( V_1 + V_14 ) ) ;
F_6 () ;
}
void T_4 F_13 ( T_1 (* F_14)( void ) , int V_16 , unsigned long V_17 )
{
unsigned long V_18 , V_19 ;
T_3 V_20 , V_21 ;
char V_22 ;
if ( V_8 . V_17 > V_17 )
return;
F_15 ( V_16 > 32 ) ;
F_16 ( ! F_17 () ) ;
F_5 = F_14 ;
V_11 = ( 1ULL << V_16 ) - 1 ;
V_8 . V_17 = V_17 ;
F_18 ( & V_8 . V_4 , & V_8 . V_5 , V_17 , V_23 , 0 ) ;
V_18 = V_17 ;
if ( V_18 >= 4000000 ) {
V_18 /= 1000000 ;
V_22 = 'M' ;
} else if ( V_18 >= 1000 ) {
V_18 /= 1000 ;
V_22 = 'k' ;
} else
V_22 = ' ' ;
V_21 = F_2 ( ( 1ULL << V_16 ) - 1 , V_8 . V_4 , V_8 . V_5 ) ;
F_19 ( V_21 , V_24 ) ;
V_19 = V_21 ;
V_20 = F_2 ( 1ULL , V_8 . V_4 , V_8 . V_5 ) ;
F_20 ( L_1 ,
V_16 , V_18 , V_22 , V_20 , V_19 ) ;
V_15 . V_25 = F_21 ( V_19 - ( V_19 / 10 ) ) ;
F_6 () ;
V_8 . V_6 = 0 ;
if ( V_26 > 0 || ( V_26 == - 1 && V_17 >= 1000000 ) )
F_22 () ;
F_23 ( L_2 , F_14 ) ;
}
unsigned long long T_2 F_24 ( void )
{
return F_25 () ;
}
void T_4 F_26 ( void )
{
if ( F_5 == F_1 )
F_13 ( F_1 , 32 , V_27 ) ;
F_10 ( V_15 . V_25 ) ;
}
static int F_27 ( void )
{
F_10 ( V_15 . V_25 ) ;
V_8 . V_9 = true ;
return 0 ;
}
static void F_28 ( void )
{
V_8 . V_7 = F_5 () ;
V_8 . V_10 = V_8 . V_7 ;
V_8 . V_9 = false ;
}
static int T_4 F_29 ( void )
{
F_30 ( & V_28 ) ;
return 0 ;
}
