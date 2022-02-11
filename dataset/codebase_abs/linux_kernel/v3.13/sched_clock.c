static T_1 T_2 F_1 ( void )
{
return ( T_1 ) ( V_1 - V_2 ) ;
}
static T_1 T_2 F_2 ( void )
{
return F_3 () ;
}
static inline T_1 T_2 F_4 ( T_1 V_3 , T_3 V_4 , T_3 V_5 )
{
return ( V_3 * V_4 ) >> V_5 ;
}
unsigned long long T_2 F_5 ( void )
{
T_1 V_6 ;
T_1 V_7 ;
T_1 V_3 ;
unsigned long V_8 ;
if ( V_9 . V_10 )
return V_9 . V_6 ;
do {
V_8 = F_6 ( & V_9 . V_8 ) ;
V_7 = V_9 . V_7 ;
V_6 = V_9 . V_6 ;
} while ( F_7 ( & V_9 . V_8 , V_8 ) );
V_3 = F_8 () ;
V_3 = ( V_3 - V_7 ) & V_11 ;
return V_6 + F_4 ( V_3 , V_9 . V_4 , V_9 . V_5 ) ;
}
static void T_2 F_9 ( void )
{
unsigned long V_12 ;
T_1 V_3 ;
T_1 V_13 ;
V_3 = F_8 () ;
V_13 = V_9 . V_6 +
F_4 ( ( V_3 - V_9 . V_7 ) & V_11 ,
V_9 . V_4 , V_9 . V_5 ) ;
F_10 ( V_12 ) ;
F_11 ( & V_9 . V_8 ) ;
V_9 . V_6 = V_13 ;
V_9 . V_7 = V_3 ;
F_12 ( & V_9 . V_8 ) ;
F_13 ( V_12 ) ;
}
static enum V_14 F_14 ( struct V_15 * V_16 )
{
F_9 () ;
F_15 ( V_16 , V_9 . V_17 ) ;
return V_18 ;
}
void T_4 F_16 ( T_1 (* F_17)( void ) , int V_19 ,
unsigned long V_20 )
{
unsigned long V_21 ;
T_1 V_22 , V_23 ;
char V_24 ;
if ( V_9 . V_20 > V_20 )
return;
F_18 ( ! F_19 () ) ;
F_8 = F_17 ;
V_11 = F_20 ( V_19 ) ;
V_9 . V_20 = V_20 ;
F_21 ( & V_9 . V_4 , & V_9 . V_5 , V_20 , V_25 , 3600 ) ;
V_21 = V_20 ;
if ( V_21 >= 4000000 ) {
V_21 /= 1000000 ;
V_24 = 'M' ;
} else if ( V_21 >= 1000 ) {
V_21 /= 1000 ;
V_24 = 'k' ;
} else
V_24 = ' ' ;
V_23 = F_22 ( V_9 . V_4 , V_9 . V_5 , 0 , V_11 ) ;
V_9 . V_17 = F_23 ( V_23 - ( V_23 >> 3 ) ) ;
V_22 = F_4 ( 1ULL , V_9 . V_4 , V_9 . V_5 ) ;
F_24 ( L_1 ,
V_19 , V_21 , V_24 , V_22 , V_23 ) ;
F_9 () ;
V_9 . V_6 = 0 ;
if ( V_26 > 0 || ( V_26 == - 1 && V_20 >= 1000000 ) )
F_25 () ;
F_26 ( L_2 , F_17 ) ;
}
void T_4 F_27 ( T_3 (* F_17)( void ) , int V_19 , unsigned long V_20 )
{
F_3 = F_17 ;
F_16 ( F_2 , V_19 , V_20 ) ;
}
void T_4 F_28 ( void )
{
if ( F_8 == F_1 )
F_16 ( F_1 , V_27 , V_28 ) ;
F_9 () ;
F_29 ( & V_29 , V_30 , V_31 ) ;
V_29 . V_32 = F_14 ;
F_30 ( & V_29 , V_9 . V_17 , V_31 ) ;
}
static int F_31 ( void )
{
F_14 ( & V_29 ) ;
V_9 . V_10 = true ;
return 0 ;
}
static void F_32 ( void )
{
V_9 . V_7 = F_8 () ;
V_9 . V_10 = false ;
}
static int T_4 F_33 ( void )
{
F_34 ( & V_33 ) ;
return 0 ;
}
