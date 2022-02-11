static void T_1 F_1 ( void )
{
F_2 ( 88 , V_1 | V_2 ) ;
F_2 ( 89 , V_1 | V_2 ) ;
F_2 ( 124 , V_1 | V_2 ) ;
F_3 ( L_1 , V_1 | V_2 ) ;
if ( F_4 () ) {
F_3 ( L_2 ,
V_1 | V_2 ) ;
F_3 ( L_3 , 0 ) ;
F_3 ( L_4 , 0 ) ;
V_3 [ 5 ] = 0 ;
V_4 [ 2 ] = 15 ;
V_4 [ 6 ] = 18 ;
} else {
F_3 ( L_5 , V_1 | V_2 ) ;
F_3 ( L_6 , 0 ) ;
F_3 ( L_4 , 0 ) ;
}
F_3 ( L_7 , 0 ) ;
F_3 ( L_8 , 0 ) ;
F_3 ( L_9 , 0 ) ;
F_3 ( L_10 , 0 ) ;
F_3 ( L_11 , 0 ) ;
F_5 ( & V_5 ) ;
}
static inline void F_1 ( void )
{
}
static T_2 F_6 ( void )
{
return ( F_7 ( V_6 ) &
( V_7 | V_8 |
V_9 | V_10 |
V_11 | V_12 ) ) ;
}
static T_2 F_8 ( void )
{
T_2 V_13 ;
V_13 = F_6 () ;
if ( ( V_13 & 0xF ) == 0xd )
return 1 ;
if ( V_13 & 0x2 )
return 1 ;
else
return 0 ;
}
static void T_1 F_9 ( void )
{
if ( F_8 () )
V_14 . V_15 |= V_16 ;
F_2 ( V_14 . V_17 , V_18 ) ;
F_10 ( & V_14 ) ;
}
static inline void F_9 ( void )
{
}
static void T_1 F_11 ( void )
{
unsigned long V_19 ;
if ( F_12 ( V_20 , V_21 , & V_19 ) < 0 ) {
F_13 ( L_12 ) ;
return;
}
V_22 . V_23 = V_19 ;
V_22 . V_24 = V_19 + V_21 - 1 ;
}
static void T_1 F_14 ( void )
{
F_15 ( V_25 , V_26 ) ;
F_1 () ;
V_27 [ 0 ] . V_28 = F_16 ( 125 ) ;
F_17 ( 1 , V_27 ,
F_18 ( V_27 ) ) ;
F_19 ( V_29 , F_18 ( V_29 ) ) ;
F_20 () ;
F_21 ( NULL , NULL ) ;
F_11 () ;
F_9 () ;
F_22 ( & V_30 ) ;
}
