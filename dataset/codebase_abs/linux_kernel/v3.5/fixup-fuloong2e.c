int T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
int V_5 = 0 ;
if ( V_3 == V_6 ) {
switch ( F_2 ( V_2 -> V_7 ) ) {
case 2 :
V_5 = 10 ;
break;
case 3 :
V_5 = 11 ;
break;
case 5 :
V_5 = 9 ;
break;
}
} else {
V_5 = V_8 + 25 + V_4 ;
}
return V_5 ;
}
int F_3 ( struct V_1 * V_2 )
{
return 0 ;
}
static void T_3 F_4 ( struct V_1 * V_9 )
{
unsigned int V_10 ;
F_5 ( V_9 , 0xe0 , & V_10 ) ;
F_6 ( V_9 , 0xe0 , ( V_10 & ~ 7 ) | 0x4 ) ;
F_6 ( V_9 , 0xe4 , 1 << 5 ) ;
}
static void T_3 F_7 ( struct V_1 * V_9 )
{
unsigned char V_11 ;
V_6 = F_8 ( V_9 -> V_7 ) ;
F_9 ( V_12 L_1 ) ;
F_10 ( V_9 , 0x40 , 0x08 ) ;
F_10 ( V_9 , 0x41 , 0x01 ) ;
F_10 ( V_9 , 0x45 , 0x00 ) ;
F_10 ( V_9 , 0x46 , 0xe0 ) ;
F_10 ( V_9 , 0x47 , 0xe6 ) ;
F_11 ( 0x2e , 0x4d1 ) ;
F_10 ( V_9 , 0x48 , 0x01 ) ;
F_10 ( V_9 , 0x4a , 0x84 ) ;
F_10 ( V_9 , 0x50 , 0x0e ) ;
F_10 ( V_9 , 0x51 , 0x76 ) ;
F_10 ( V_9 , 0x52 , 0x34 ) ;
F_10 ( V_9 , 0x54 , 0x00 ) ;
F_10 ( V_9 , 0x55 , 0x90 ) ;
F_10 ( V_9 , 0x56 , 0xba ) ;
F_10 ( V_9 , 0x57 , 0xd0 ) ;
F_12 ( V_9 , 0x85 , & V_11 ) ;
V_11 &= ~ ( 0x3 << 2 ) ;
F_10 ( V_9 , 0x85 , V_11 ) ;
F_9 ( V_12 L_2 ) ;
}
static void T_3 F_13 ( struct V_1 * V_9 )
{
F_9 ( V_12 L_3 ) ;
F_10 ( V_9 , V_13 , 48 ) ;
F_10 ( V_9 , V_14 ,
V_15 | V_16 |
V_17 ) ;
F_10 ( V_9 , 0x40 , 0x0b ) ;
F_10 ( V_9 , 0x42 , 0x09 ) ;
#if 1
F_10 ( V_9 , 0x41 , 0x02 ) ;
F_10 ( V_9 , 0x43 , 0x0a ) ;
F_10 ( V_9 , 0x44 , 0x00 ) ;
F_10 ( V_9 , 0x45 , 0x00 ) ;
#else
F_10 ( V_9 , 0x41 , 0xc2 ) ;
F_10 ( V_9 , 0x43 , 0x35 ) ;
F_10 ( V_9 , 0x44 , 0x1c ) ;
F_10 ( V_9 , 0x45 , 0x10 ) ;
#endif
F_9 ( V_12 L_4 ) ;
}
static void T_3 F_14 ( struct V_1 * V_9 )
{
F_10 ( V_9 , V_18 , 10 ) ;
}
static void T_3 F_15 ( struct V_1 * V_9 )
{
F_10 ( V_9 , V_18 , 11 ) ;
}
static void T_3 F_16 ( struct V_1 * V_9 )
{
unsigned int V_10 ;
unsigned char V_11 ;
F_10 ( V_9 , V_14 ,
V_15 | V_16 |
V_17 ) ;
F_5 ( V_9 , 0x4 , & V_10 ) ;
F_6 ( V_9 , 0x4 , V_10 | 1 ) ;
F_10 ( V_9 , 0x3c , 9 ) ;
F_12 ( V_9 , 0x8 , & V_11 ) ;
F_10 ( V_9 , 0x41 , 0xcc ) ;
F_10 ( V_9 , 0x42 , 0x20 ) ;
F_17 ( V_9 , 0x2c , 0x1005 ) ;
F_17 ( V_9 , 0x2e , 0x4710 ) ;
F_5 ( V_9 , 0x2c , & V_10 ) ;
F_10 ( V_9 , 0x42 , 0x0 ) ;
}
