static T_1 F_1 ( void )
{
struct V_1 V_2 , V_3 ;
T_1 V_4 ;
F_2 ( & V_2 ) ;
V_2 . V_5 = 0x0f00 ;
F_3 ( 0x10 , & V_2 , & V_3 ) ;
V_4 = V_3 . V_6 ;
if ( V_4 != 3 && V_4 != 7 )
V_4 = 3 ;
V_2 . V_5 = V_4 ;
F_3 ( 0x10 , & V_2 , NULL ) ;
V_7 = 1 ;
return V_4 ;
}
static void F_4 ( void )
{
struct V_1 V_2 ;
F_2 ( & V_2 ) ;
V_2 . V_5 = 0x1112 ;
F_3 ( 0x10 , & V_2 , NULL ) ;
V_2 . V_5 = 0x1200 ;
V_2 . V_8 = 0x20 ;
F_3 ( 0x10 , & V_2 , NULL ) ;
V_2 . V_5 = 0x1201 ;
V_2 . V_8 = 0x34 ;
F_3 ( 0x10 , & V_2 , NULL ) ;
V_2 . V_5 = 0x0100 ;
V_2 . V_9 = 0x0607 ;
F_3 ( 0x10 , & V_2 , NULL ) ;
}
static void F_5 ( void )
{
struct V_1 V_2 ;
F_2 ( & V_2 ) ;
V_2 . V_5 = 0x1111 ;
F_3 ( 0x10 , & V_2 , NULL ) ;
V_2 . V_5 = 0x1201 ;
V_2 . V_8 = 0x34 ;
F_3 ( 0x10 , & V_2 , NULL ) ;
V_2 . V_5 = 0x0100 ;
V_2 . V_9 = 0x0b0c ;
F_3 ( 0x10 , & V_2 , NULL ) ;
}
static void F_6 ( void )
{
struct V_1 V_2 ;
F_2 ( & V_2 ) ;
V_2 . V_5 = 0x1201 ;
V_2 . V_8 = 0x30 ;
F_3 ( 0x10 , & V_2 , NULL ) ;
V_2 . V_5 = 0x0003 ;
F_3 ( 0x10 , & V_2 , NULL ) ;
F_4 () ;
}
T_2 F_7 ( void )
{
return ( F_8 ( 0x3cc ) & 1 ) ? 0x3d4 : 0x3b4 ;
}
static void F_9 ( void )
{
T_2 V_10 ;
T_1 V_11 ;
V_10 = F_7 () ;
F_10 ( 0x0c , V_10 , 0x11 ) ;
F_10 ( 0x0b , V_10 , 0x06 ) ;
F_10 ( 0x3e , V_10 , 0x07 ) ;
F_10 ( 0xea , V_10 , 0x10 ) ;
F_10 ( 0xdf , V_10 , 0x12 ) ;
F_10 ( 0xe7 , V_10 , 0x15 ) ;
F_10 ( 0x04 , V_10 , 0x16 ) ;
V_11 = F_8 ( 0x3cc ) ;
V_11 &= 0x0d ;
V_11 |= 0xe2 ;
F_11 ( V_11 , 0x3c2 ) ;
}
static void F_12 ( int V_12 )
{
T_2 V_10 ;
T_1 V_13 ;
int V_14 = V_12 - 1 ;
V_10 = F_7 () ;
V_13 = 0x3c | ( ( V_14 >> ( 8 - 1 ) ) & 0x02 ) | ( ( V_14 >> ( 9 - 6 ) ) & 0x40 ) ;
F_10 ( V_13 , V_10 , 0x07 ) ;
F_10 ( V_14 , V_10 , 0x12 ) ;
}
static void F_13 ( void )
{
F_9 () ;
F_12 ( 30 * 16 ) ;
}
static void F_14 ( void )
{
F_9 () ;
F_5 () ;
F_12 ( 34 * 14 ) ;
}
static void F_15 ( void )
{
F_9 () ;
F_4 () ;
F_12 ( 60 * 8 ) ;
}
static int F_16 ( struct V_15 * V_4 )
{
F_1 () ;
V_16 = V_4 -> V_17 ;
V_18 = V_4 -> V_19 ;
switch ( V_4 -> V_4 ) {
case V_20 :
break;
case V_21 :
F_4 () ;
break;
case V_22 :
F_6 () ;
break;
case V_23 :
F_5 () ;
break;
case V_24 :
F_13 () ;
break;
case V_25 :
F_14 () ;
break;
case V_26 :
F_15 () ;
break;
}
return 0 ;
}
static int F_17 ( void )
{
static const char * V_27 [] = {
L_1 , L_2 , L_3
} ;
static struct V_15 * V_28 [] = {
V_29 ,
V_30 ,
V_31 ,
} ;
static int V_32 [] = {
sizeof( V_29 ) / sizeof( struct V_15 ) ,
sizeof( V_30 ) / sizeof( struct V_15 ) ,
sizeof( V_31 ) / sizeof( struct V_15 ) ,
} ;
struct V_1 V_2 , V_3 ;
F_2 ( & V_2 ) ;
V_2 . V_5 = 0x1200 ;
V_2 . V_8 = 0x10 ;
F_3 ( 0x10 , & V_2 , & V_3 ) ;
#ifndef F_18
V_33 . V_34 . V_35 = V_3 . V_36 ;
#endif
if ( V_3 . V_8 != 0x10 ) {
V_2 . V_5 = 0x1a00 ;
F_3 ( 0x10 , & V_2 , & V_3 ) ;
if ( V_3 . V_6 == 0x1a ) {
V_37 = V_38 ;
#ifndef F_18
V_33 . V_34 . V_39 = 1 ;
#endif
} else {
V_37 = V_40 ;
}
} else {
V_37 = V_41 ;
}
V_42 . V_43 = V_28 [ V_37 ] ;
V_42 . V_27 = V_27 [ V_37 ] ;
return V_32 [ V_37 ] ;
}
