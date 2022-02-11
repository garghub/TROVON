static T_1 T_2 F_1 ( void )
{
return ( T_1 ) ( V_1 - V_2 ) ;
}
static inline T_3 F_2 ( T_3 V_3 , T_1 V_4 , T_1 V_5 )
{
return ( V_3 * V_4 ) >> V_5 ;
}
static unsigned long long F_3 ( T_1 V_3 , T_1 V_6 )
{
T_3 V_7 ;
T_1 V_8 ;
if ( V_9 . V_10 )
return V_9 . V_7 ;
do {
V_8 = V_9 . V_8 ;
F_4 () ;
V_7 = V_9 . V_7 ;
F_4 () ;
} while ( V_8 != V_9 . V_11 );
return V_7 + F_2 ( ( V_3 - V_8 ) & V_6 , V_9 . V_4 , V_9 . V_5 ) ;
}
static void T_2 F_5 ( void )
{
unsigned long V_12 ;
T_1 V_3 ;
T_3 V_13 ;
V_3 = F_6 () ;
V_13 = V_9 . V_7 +
F_2 ( ( V_3 - V_9 . V_8 ) & V_14 ,
V_9 . V_4 , V_9 . V_5 ) ;
F_7 ( V_12 ) ;
V_9 . V_8 = V_3 ;
F_8 () ;
V_9 . V_7 = V_13 ;
F_8 () ;
V_9 . V_11 = V_3 ;
F_9 ( V_12 ) ;
}
static void F_10 ( unsigned long V_15 )
{
F_11 ( & V_16 , F_12 ( V_1 + V_15 ) ) ;
F_5 () ;
}
void T_4 F_13 ( T_1 (* F_14)( void ) , int V_17 , unsigned long V_18 )
{
unsigned long V_19 , V_20 ;
T_3 V_21 , V_22 ;
char V_23 ;
F_15 ( V_17 > 32 ) ;
F_16 ( ! F_17 () ) ;
F_16 ( F_6 != F_1 ) ;
F_6 = F_14 ;
V_14 = ( 1 << V_17 ) - 1 ;
F_18 ( & V_9 . V_4 , & V_9 . V_5 , V_18 , V_24 , 0 ) ;
V_19 = V_18 ;
if ( V_19 >= 4000000 ) {
V_19 /= 1000000 ;
V_23 = 'M' ;
} else if ( V_19 >= 1000 ) {
V_19 /= 1000 ;
V_23 = 'k' ;
} else
V_23 = ' ' ;
V_22 = F_2 ( ( 1ULL << V_17 ) - 1 , V_9 . V_4 , V_9 . V_5 ) ;
F_19 ( V_22 , V_25 ) ;
V_20 = V_22 ;
V_21 = F_2 ( 1ULL , V_9 . V_4 , V_9 . V_5 ) ;
F_20 ( L_1 ,
V_17 , V_19 , V_23 , V_21 , V_20 ) ;
V_16 . V_26 = F_21 ( V_20 - ( V_20 / 10 ) ) ;
F_5 () ;
V_9 . V_7 = 0 ;
if ( V_27 > 0 || ( V_27 == - 1 && V_18 >= 1000000 ) )
F_22 () ;
F_23 ( L_2 , F_14 ) ;
}
unsigned long long T_2 F_24 ( void )
{
T_1 V_3 = F_6 () ;
return F_3 ( V_3 , V_14 ) ;
}
void T_4 F_25 ( void )
{
if ( F_6 == F_1 )
F_13 ( F_1 , 32 , V_28 ) ;
F_10 ( V_16 . V_26 ) ;
}
static int F_26 ( void )
{
F_10 ( V_16 . V_26 ) ;
V_9 . V_10 = true ;
return 0 ;
}
static void F_27 ( void )
{
V_9 . V_8 = F_6 () ;
V_9 . V_11 = V_9 . V_8 ;
V_9 . V_10 = false ;
}
static int T_4 F_28 ( void )
{
F_29 ( & V_29 ) ;
return 0 ;
}
