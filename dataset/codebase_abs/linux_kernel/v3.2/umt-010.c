static int F_1 ( struct V_1 * V_2 )
{
static T_1 V_3 [] = { 0x89 , 0xb8 , 0x2d } ;
static T_1 V_4 [] = { 0x50 , 0x80 } ;
static T_1 V_5 [] = { 0x8b , 0x00 } ;
static T_1 V_6 [] = { 0x8E , 0x40 } ;
static T_1 V_7 [] = { 0x67 , 0x10 , 0xa0 } ;
static T_1 V_8 [] = { 0x6a , 0xff } ;
static T_1 V_9 [] = { 0x6d , 0xff } ;
static T_1 V_10 [] = { 0x70 , 0x40 } ;
static T_1 V_11 [] = { 0x7b , 0x03 } ;
static T_1 V_12 [] = { 0x7d , 0x0f } ;
static T_1 V_13 [] = { 0x53 , 0x50 } ;
static T_1 V_14 [] = { 0x56 , 0x31 , 0x06 } ;
F_2 ( V_2 , V_3 , sizeof( V_3 ) ) ;
F_3 ( 2000 ) ;
F_2 ( V_2 , V_4 , sizeof( V_4 ) ) ;
F_2 ( V_2 , V_5 , sizeof( V_5 ) ) ;
F_2 ( V_2 , V_6 , sizeof( V_6 ) ) ;
F_2 ( V_2 , V_7 , sizeof( V_7 ) ) ;
F_2 ( V_2 , V_8 , sizeof( V_8 ) ) ;
F_2 ( V_2 , V_9 , sizeof( V_9 ) ) ;
F_2 ( V_2 , V_10 , sizeof( V_10 ) ) ;
F_2 ( V_2 , V_11 , sizeof( V_11 ) ) ;
F_2 ( V_2 , V_12 , sizeof( V_12 ) ) ;
F_2 ( V_2 , V_13 , sizeof( V_13 ) ) ;
F_2 ( V_2 , V_14 , sizeof( V_14 ) ) ;
return 0 ;
}
static int F_4 ( struct V_15 * V_16 )
{
struct V_17 V_18 ;
memset ( & V_18 , 0 , sizeof( struct V_17 ) ) ;
V_18 . V_19 = F_1 ;
V_18 . V_20 = 0xf ;
V_16 -> V_21 [ 0 ] . V_2 = F_5 ( V_22 , & V_18 , & V_16 -> V_23 -> V_24 ) ;
return 0 ;
}
static int F_6 ( struct V_15 * V_16 )
{
F_5 ( V_25 , V_16 -> V_21 [ 0 ] . V_2 , 0x61 , NULL , V_26 ) ;
return 0 ;
}
static int F_7 ( struct V_27 * V_28 ,
const struct V_29 * V_30 )
{
if ( 0 == F_8 ( V_28 , & V_31 ,
V_32 , NULL , V_33 ) )
return 0 ;
return - V_34 ;
}
static int T_2 F_9 ( void )
{
int V_35 ;
if ( ( V_35 = F_10 ( & V_36 ) ) ) {
F_11 ( L_1 , V_35 ) ;
return V_35 ;
}
return 0 ;
}
static void T_3 F_12 ( void )
{
F_13 ( & V_36 ) ;
}
