static void T_1 F_1 ( void )
{
if ( F_2 () )
V_1 . V_2 = V_3 ;
else
V_1 . V_2 = V_4 ;
F_3 ( & V_1 ) ;
}
static inline void F_1 ( void ) {}
static void T_1 F_4 ( void )
{
F_3 ( & V_5 ) ;
}
static inline void F_4 ( void ) {}
static void T_1 F_5 ( void )
{
if ( F_2 () ) {
V_6 [ 0 ] . V_7 = V_8 ;
V_6 [ 1 ] . V_7 = V_9 ;
} else {
V_6 [ 0 ] . V_7 = V_10 ;
V_6 [ 1 ] . V_7 = V_11 ;
}
F_3 ( & V_12 ) ;
}
static inline void F_5 ( void ) {}
static int T_1 F_6 ( char * V_13 )
{
int V_14 = F_7 ( V_13 , NULL , 0 ) ;
switch ( V_14 ) {
case V_15 :
V_16 = & V_17 ;
break;
case V_18 :
V_16 = & V_19 ;
break;
case V_20 :
V_16 = & V_21 ;
break;
case V_22 :
V_16 = & V_23 ;
break;
case V_24 :
V_16 = & V_25 ;
break;
case V_26 :
V_16 = & V_27 ;
break;
default:
V_16 = & V_21 ;
break;
}
return 1 ;
}
static void T_1 F_8 ( void )
{
F_9 ( NULL , V_16 ) ;
}
static inline void F_8 ( void ) {}
static int F_10 ( void )
{
F_11 () ;
V_28 [ 0 ] = F_12 ( V_29 ) ;
V_28 [ 1 ] = F_12 ( V_30 ) ;
V_28 [ 2 ] = F_12 ( V_31 ) ;
V_32 = 0x0 ;
V_33 = 0xff400000 ;
V_34 = 0x00000005 ;
V_35 = 0x80000000 ;
V_36 = 0x00000000 ;
V_37 = 0x00000000 ;
V_38 = 0xC0018800 ;
V_39 = 0x004F0002 ;
V_40 = 0x6021C000 ;
V_41 = 0x00020000 ;
return 0 ;
}
static void F_13 ( void )
{
F_14 () ;
F_15 ( V_28 [ 0 ] , V_29 ) ;
F_15 ( V_28 [ 1 ] , V_30 ) ;
F_15 ( V_28 [ 2 ] , V_31 ) ;
}
static int T_1 F_16 ( void )
{
F_17 ( & V_42 ) ;
return 0 ;
}
static int T_1 F_16 ( void ) { return 0 ; }
static void T_1 F_18 ( void )
{
F_19 ( NULL ) ;
}
static inline void F_18 ( void ) {}
static void T_1 F_20 ( void )
{
F_21 ( NULL ) ;
F_22 ( NULL ) ;
F_23 ( NULL ) ;
F_16 () ;
if ( F_2 () )
F_24 () ;
else
F_25 () ;
F_1 () ;
F_8 () ;
F_18 () ;
F_4 () ;
F_5 () ;
}
static void T_1 F_26 ( void )
{
if ( F_2 () ) {
F_27 () ;
F_28 ( V_43 ) ;
} else {
F_29 () ;
F_28 ( V_44 ) ;
}
}
static void T_1 F_30 ( void )
{
if ( F_2 () )
F_31 () ;
if ( F_32 () )
F_33 () ;
F_34 ( V_45 , F_35 ( V_45 ) ) ;
V_46 = V_47 ;
}
static void T_1 F_30 ( void )
{
if ( F_2 () )
F_31 () ;
if ( F_32 () )
F_33 () ;
}
