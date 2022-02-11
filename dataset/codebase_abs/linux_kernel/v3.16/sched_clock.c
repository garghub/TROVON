static T_1 T_2 F_1 ( void )
{
return ( T_1 ) ( V_1 - V_2 ) ;
}
static inline T_1 T_2 F_2 ( T_1 V_3 , T_3 V_4 , T_3 V_5 )
{
return ( V_3 * V_4 ) >> V_5 ;
}
unsigned long long T_2 F_3 ( void )
{
T_1 V_6 ;
T_1 V_7 ;
T_1 V_3 ;
unsigned long V_8 ;
if ( V_9 . V_10 )
return V_9 . V_6 ;
do {
V_8 = F_4 ( & V_9 . V_8 ) ;
V_7 = V_9 . V_7 ;
V_6 = V_9 . V_6 ;
} while ( F_5 ( & V_9 . V_8 , V_8 ) );
V_3 = F_6 () ;
V_3 = ( V_3 - V_7 ) & V_11 ;
return V_6 + F_2 ( V_3 , V_9 . V_4 , V_9 . V_5 ) ;
}
static void T_2 F_7 ( void )
{
unsigned long V_12 ;
T_1 V_3 ;
T_1 V_13 ;
V_3 = F_6 () ;
V_13 = V_9 . V_6 +
F_2 ( ( V_3 - V_9 . V_7 ) & V_11 ,
V_9 . V_4 , V_9 . V_5 ) ;
F_8 ( V_12 ) ;
F_9 ( & V_9 . V_8 ) ;
V_9 . V_6 = V_13 ;
V_9 . V_7 = V_3 ;
F_10 ( & V_9 . V_8 ) ;
F_11 ( V_12 ) ;
}
static enum V_14 F_12 ( struct V_15 * V_16 )
{
F_7 () ;
F_13 ( V_16 , V_9 . V_17 ) ;
return V_18 ;
}
void T_4 F_14 ( T_1 (* F_15)( void ) , int V_19 ,
unsigned long V_20 )
{
T_1 V_21 , V_22 , V_23 , V_24 , V_3 , V_13 ;
T_3 V_25 , V_26 ;
T_5 V_27 ;
unsigned long V_28 ;
char V_29 ;
if ( V_9 . V_20 > V_20 )
return;
F_16 ( ! F_17 () ) ;
F_18 ( & V_25 , & V_26 , V_20 , V_30 , 3600 ) ;
V_23 = F_19 ( V_19 ) ;
V_22 = F_20 ( V_25 , V_26 , 0 , V_23 ) ;
V_27 = F_21 ( V_22 - ( V_22 >> 3 ) ) ;
V_24 = F_15 () ;
V_3 = F_6 () ;
V_13 = V_9 . V_6 + F_2 ( ( V_3 - V_9 . V_7 ) & V_11 ,
V_9 . V_4 , V_9 . V_5 ) ;
F_9 ( & V_9 . V_8 ) ;
F_6 = F_15 ;
V_11 = V_23 ;
V_9 . V_20 = V_20 ;
V_9 . V_17 = V_27 ;
V_9 . V_4 = V_25 ;
V_9 . V_5 = V_26 ;
V_9 . V_7 = V_24 ;
V_9 . V_6 = V_13 ;
F_10 ( & V_9 . V_8 ) ;
V_28 = V_20 ;
if ( V_28 >= 4000000 ) {
V_28 /= 1000000 ;
V_29 = 'M' ;
} else if ( V_28 >= 1000 ) {
V_28 /= 1000 ;
V_29 = 'k' ;
} else
V_29 = ' ' ;
V_21 = F_2 ( 1ULL , V_25 , V_26 ) ;
F_22 ( L_1 ,
V_19 , V_28 , V_29 , V_21 , V_22 ) ;
if ( V_31 > 0 || ( V_31 == - 1 && V_20 >= 1000000 ) )
F_23 () ;
F_24 ( L_2 , F_15 ) ;
}
void T_4 F_25 ( void )
{
if ( F_6 == F_1 )
F_14 ( F_1 , V_32 , V_33 ) ;
F_7 () ;
F_26 ( & V_34 , V_35 , V_36 ) ;
V_34 . V_37 = F_12 ;
F_27 ( & V_34 , V_9 . V_17 , V_36 ) ;
}
static int F_28 ( void )
{
F_7 () ;
F_29 ( & V_34 ) ;
V_9 . V_10 = true ;
return 0 ;
}
static void F_30 ( void )
{
V_9 . V_7 = F_6 () ;
F_27 ( & V_34 , V_9 . V_17 , V_36 ) ;
V_9 . V_10 = false ;
}
static int T_4 F_31 ( void )
{
F_32 ( & V_38 ) ;
return 0 ;
}
