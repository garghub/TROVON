static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 , T_1 V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_4 ( & V_4 -> V_3 ) ;
T_1 V_9 [ 2 ] ;
int V_10 ;
V_9 [ 0 ] = V_5 ;
V_9 [ 1 ] = V_6 ;
V_4 -> V_11 [ V_5 ] = V_6 ;
F_5 ( 1 , V_12 , V_8 , L_1 , V_5 , V_6 ) ;
for ( V_10 = 0 ; V_10 < 3 ; ) {
if ( F_6 ( V_8 , V_9 , 2 ) == 2 )
break;
V_10 ++ ;
F_7 ( V_8 , L_2 ,
V_10 , V_5 ) ;
F_8 ( F_9 ( 100 ) ) ;
}
if ( V_10 == 3 ) {
F_7 ( V_8 , L_3 ) ;
return - 1 ;
}
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , T_2 V_13 )
{
F_11 ( 1 , V_12 , V_3 , L_4 , ( unsigned long long ) V_13 ) ;
if ( ! ( V_13 & V_14 ) )
return - V_15 ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 ,
T_3 V_16 , T_3 V_17 , T_3 V_18 )
{
static const T_4 V_19 [] = {
0xc8 , 0xcc ,
0xca , 0x91 ,
0xcc , 0x24 ,
0xda , 0x00 ,
0xdc , 0x24 ,
0xde , 0x02 ,
0x70 , 0xEB , 0x90 , 0x80 , 0xB0 , 0x80 ,
0x72 , 0xA2 , 0x92 , 0x8E , 0xB2 , 0x2C ,
0x74 , 0x83 , 0x94 , 0x2C , 0xB4 , 0x9C ,
0x76 , 0x70 , 0x96 , 0x3A , 0xB6 , 0x48 ,
0x78 , 0x54 , 0x98 , 0xC6 , 0xB8 , 0xB8 ,
0x7A , 0x41 , 0x9A , 0xD4 , 0xBA , 0x64 ,
0x7C , 0x23 , 0x9C , 0x72 , 0xBC , 0xD4 ,
0x7E , 0x10 , 0x9E , 0x80 , 0xBE , 0x80 ,
0x60 , 0xEB , 0x80 , 0x80 , 0xc0 , 0x80 ,
0x62 , 0xA2 , 0x82 , 0x8E , 0xc2 , 0x2C ,
0x64 , 0x83 , 0x84 , 0x2C , 0xc4 , 0x9C ,
0x66 , 0x70 , 0x86 , 0x3A , 0xc6 , 0x48 ,
0x68 , 0x54 , 0x88 , 0xC6 , 0xc8 , 0xB8 ,
0x6A , 0x41 , 0x8A , 0xD4 , 0xcA , 0x64 ,
0x6C , 0x23 , 0x8C , 0x72 , 0xcC , 0xD4 ,
0x6E , 0x10 , 0x8E , 0x80 , 0xcE , 0x80 ,
} ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_13 ( V_19 ) / 2 ; V_21 += 2 )
F_3 ( V_4 , V_19 [ V_21 ] , V_19 [ V_21 + 1 ] ) ;
V_20 = V_4 -> V_11 [ 0xdc ] ;
if ( V_16 == 0 )
V_20 |= 0x40 ;
else
V_20 &= ~ 0x40 ;
F_3 ( V_4 , 0xdc , V_20 ) ;
V_20 = V_4 -> V_11 [ 0xcc ] ;
if ( V_16 == 2 )
V_20 |= 0x01 ;
else
V_20 &= ~ 0x01 ;
F_3 ( V_4 , 0xcc , V_20 ) ;
F_11 ( 1 , V_12 , V_3 , L_5 , V_16 ) ;
switch ( V_16 ) {
case 0 :
case 1 :
case 2 :
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , struct V_22 * V_23 )
{
struct V_7 * V_8 = F_4 ( V_3 ) ;
return F_15 ( V_8 , V_23 , V_24 , 0 ) ;
}
static int F_16 ( struct V_7 * V_8 ,
const struct V_25 * V_26 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
F_17 ( V_8 , L_6 ,
V_8 -> V_27 << 1 , V_8 -> V_28 -> V_29 ) ;
V_4 = F_18 ( sizeof( * V_4 ) , V_30 ) ;
if ( V_4 == NULL )
return - V_31 ;
V_3 = & V_4 -> V_3 ;
F_19 ( V_3 , V_8 , & V_32 ) ;
return 0 ;
}
static int F_20 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_21 ( V_8 ) ;
F_22 ( V_3 ) ;
F_23 ( F_1 ( V_3 ) ) ;
return 0 ;
}
static T_5 int F_24 ( void )
{
return F_25 ( & V_33 ) ;
}
static T_6 void F_26 ( void )
{
F_27 ( & V_33 ) ;
}
