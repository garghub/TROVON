static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 [] = { 0x00 , V_3 , V_4 } ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_5 , . V_12 = 3 } ;
int V_13 ;
V_13 = F_2 ( V_2 -> V_14 , & V_7 , 1 ) ;
if ( V_13 != 1 )
F_3 ( L_1
L_2 , V_15 , V_3 , V_4 , V_13 ) ;
return ( V_13 != 1 ) ? - V_16 : 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_17 [] = { 0x00 , V_3 } ;
T_1 V_18 [] = { 0 } ;
struct V_6 V_7 [] = {
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_17 , . V_12 = 2 } ,
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = V_19 , . V_5 = V_18 , . V_12 = 1 }
} ;
int V_13 ;
V_13 = F_2 ( V_2 -> V_14 , V_7 , 2 ) ;
if ( V_13 != 2 )
F_3 ( L_3
L_4 , V_15 , V_3 , V_13 ) ;
return V_18 [ 0 ] ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_20 , enum V_21 V_22 )
{
V_20 |= V_2 -> V_20 & 0x62 ;
if ( V_23 == V_22 ) {
if ( ! V_2 -> V_9 -> V_24 ) V_20 |= 0x20 ;
else V_20 &= ~ 0x20 ;
} else if ( V_25 == V_22 ) {
if ( ! V_2 -> V_9 -> V_24 ) V_20 &= ~ 0x20 ;
else V_20 |= 0x20 ;
}
F_1 ( V_2 , 0x00 , V_20 & 0xfe ) ;
F_1 ( V_2 , 0x00 , V_20 | 0x01 ) ;
V_2 -> V_20 = V_20 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_26 )
{
T_3 V_27 ;
T_3 V_28 ;
T_4 V_29 = 0 ;
T_5 V_30 = 0 ;
T_2 V_31 ;
T_2 V_32 ;
T_2 V_33 ;
T_6 V_34 ;
T_6 V_35 ;
if ( V_26 > V_2 -> V_9 -> V_36 / 2 )
V_26 = V_2 -> V_9 -> V_36 / 2 ;
if ( V_26 < 500000 )
V_26 = 500000 ;
if ( V_26 < V_2 -> V_9 -> V_36 / 16 )
V_30 = 1 ;
if ( V_26 < V_2 -> V_9 -> V_36 / 32 )
V_30 = 2 ;
if ( V_26 < V_2 -> V_9 -> V_36 / 64 )
V_30 = 3 ;
V_35 = V_2 -> V_9 -> V_36 * 10 ;
V_34 = V_35 ; F_7 ( V_34 , 123 ) ;
if ( V_26 < V_34 )
V_29 = 1 ;
V_34 = V_35 ; F_7 ( V_34 , 160 ) ;
if ( V_26 < V_34 )
V_29 = 0 ;
V_34 = V_35 ; F_7 ( V_34 , 246 ) ;
if ( V_26 < V_34 )
V_29 = 1 ;
V_34 = V_35 ; F_7 ( V_34 , 320 ) ;
if ( V_26 < V_34 )
V_29 = 0 ;
V_34 = V_35 ; F_7 ( V_34 , 492 ) ;
if ( V_26 < V_34 )
V_29 = 1 ;
V_34 = V_35 ; F_7 ( V_34 , 640 ) ;
if ( V_26 < V_34 )
V_29 = 0 ;
V_34 = V_35 ; F_7 ( V_34 , 984 ) ;
if ( V_26 < V_34 )
V_29 = 1 ;
V_32 = V_2 -> V_9 -> V_36 >> 4 ;
V_26 <<= V_30 ;
V_31 = ( V_26 << 4 ) / V_32 ;
V_33 = ( ( V_26 << 4 ) % V_32 ) << 8 ;
V_31 = ( V_31 << 8 ) + V_33 / V_32 ;
V_33 = ( V_33 % V_32 ) << 8 ;
V_31 = ( V_31 << 8 ) + F_8 ( V_33 , V_32 ) ;
V_27 = V_31 ;
V_28 = ( ( ( V_2 -> V_9 -> V_36 << 5 ) / V_26 ) + 1 ) / 2 ;
if ( V_28 > 0xFF )
V_28 = 0xFF ;
V_29 = ( V_29 << 4 ) | V_37 [ 0x0E ] ;
V_30 = ( V_30 << 6 ) | V_37 [ 0x03 ] ;
F_1 ( V_2 , 0x03 , V_30 ) ;
F_1 ( V_2 , 0x0a , V_27 & 0xff ) ;
F_1 ( V_2 , 0x0b , ( V_27 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x0c , ( V_27 >> 16 ) & 0x3f ) ;
F_1 ( V_2 , 0x0d , V_28 ) ;
F_1 ( V_2 , 0x0e , V_29 ) ;
return 0 ;
}
static int F_9 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
int V_41 ;
F_1 ( V_2 , 0 , 0 ) ;
for ( V_41 = 0 ; V_41 < sizeof( V_37 ) ; V_41 ++ )
F_1 ( V_2 , V_41 , V_37 [ V_41 ] ) ;
if ( V_2 -> V_9 -> V_42 )
F_1 ( V_2 , 2 , V_37 [ 2 ] | 0x08 ) ;
F_1 ( V_2 , 0x34 , V_2 -> V_43 ) ;
return 0 ;
}
static int F_10 ( struct V_38 * V_39 )
{
struct V_44 * V_45 = & V_39 -> V_46 ;
struct V_1 * V_2 = V_39 -> V_40 ;
static const T_1 V_47 [] = { 0x00 , 0x04 , 0x08 , 0x0c , 0x10 } ;
static const T_1 V_48 [] = { 140 , 140 , 106 , 100 , 92 } ;
static const T_1 V_49 [] = { 135 , 100 , 70 , 54 , 38 } ;
static const T_1 V_50 [] = { 162 , 116 , 67 , 52 , 35 } ;
static const T_1 V_51 [] = { 145 , 150 , 106 , 126 , 107 } ;
int V_52 = V_45 -> V_53 - V_54 ;
if ( V_52 < 0 || V_52 > 4 )
return - V_55 ;
if ( V_39 -> V_56 . V_57 . V_58 ) {
V_39 -> V_56 . V_57 . V_58 ( V_39 ) ;
if ( V_39 -> V_56 . V_59 ) V_39 -> V_56 . V_59 ( V_39 , 0 ) ;
}
F_6 ( V_2 , V_45 -> V_60 ) ;
F_1 ( V_2 , 0x34 , V_2 -> V_43 ) ;
F_1 ( V_2 , 0x01 , V_48 [ V_52 ] ) ;
F_1 ( V_2 , 0x05 , V_49 [ V_52 ] ) ;
F_1 ( V_2 , 0x08 , V_50 [ V_52 ] ) ;
F_1 ( V_2 , 0x09 , V_51 [ V_52 ] ) ;
F_5 ( V_2 , V_47 [ V_52 ] , V_45 -> V_22 ) ;
F_1 ( V_2 , 2 , V_37 [ 2 ] | ( V_2 -> V_9 -> V_42 ? 0x08 : 0 ) ) ;
return 0 ;
}
static int F_11 ( struct V_38 * V_39 ,
enum V_61 * V_62 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
int V_63 ;
* V_62 = 0 ;
V_63 = F_4 ( V_2 , 0x11 ) ;
if ( V_63 & 1 )
* V_62 |= V_64 ;
if ( V_63 & 2 )
* V_62 |= V_65 ;
if ( V_63 & 2 )
* V_62 |= V_66 ;
if ( V_63 & 4 )
* V_62 |= V_67 ;
if ( V_63 & 8 )
* V_62 |= V_68 ;
return 0 ;
}
static int F_12 ( struct V_38 * V_39 , T_2 * V_69 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
T_2 V_70 = F_4 ( V_2 , 0x14 ) |
( F_4 ( V_2 , 0x15 ) << 8 ) |
( ( F_4 ( V_2 , 0x16 ) & 0x0f ) << 16 ) ;
* V_69 = 10 * V_70 ;
return 0 ;
}
static int F_13 ( struct V_38 * V_39 , T_5 * V_71 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
T_1 V_72 = F_4 ( V_2 , 0x17 ) ;
* V_71 = ( V_72 << 8 ) | V_72 ;
return 0 ;
}
static int F_14 ( struct V_38 * V_39 , T_5 * V_73 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
T_1 V_74 = ~ F_4 ( V_2 , 0x18 ) ;
* V_73 = ( V_74 << 8 ) | V_74 ;
return 0 ;
}
static int F_15 ( struct V_38 * V_39 , T_2 * V_75 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
* V_75 = F_4 ( V_2 , 0x13 ) & 0x7f ;
if ( * V_75 == 0x7f )
* V_75 = 0xffffffff ;
F_1 ( V_2 , 0x10 , V_37 [ 0x10 ] & 0xdf ) ;
F_1 ( V_2 , 0x10 , V_37 [ 0x10 ] ) ;
return 0 ;
}
static int F_16 ( struct V_38 * V_39 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
int V_63 ;
T_7 V_76 = 0 ;
V_63 = F_4 ( V_2 , 0x11 ) ;
V_76 = F_4 ( V_2 , 0x19 ) ;
if ( V_77 ) {
F_3 ( V_63 & 2 ? L_5 :
L_6 , V_76 , - ( ( T_3 ) V_45 -> V_60 * V_76 ) >> 10 ) ;
}
if ( ! V_2 -> V_9 -> V_24 ) {
V_45 -> V_22 = ( V_2 -> V_20 & 0x20 ) ? V_23 : V_25 ;
} else {
V_45 -> V_22 = ( ! ( V_2 -> V_20 & 0x20 ) ) ? V_23 : V_25 ;
}
V_45 -> V_53 = ( ( V_2 -> V_20 >> 2 ) & 7 ) + V_54 ;
V_45 -> V_78 = V_79 ;
V_45 -> V_80 = ( ( V_45 -> V_80 + 31250 ) / 62500 ) * 62500 ;
if ( V_63 & 2 )
V_45 -> V_80 -= ( ( T_3 ) V_45 -> V_60 * V_76 ) >> 10 ;
return 0 ;
}
static int F_17 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
F_1 ( V_2 , 0x1b , 0x02 ) ;
F_1 ( V_2 , 0x00 , 0x80 ) ;
return 0 ;
}
static int F_18 ( struct V_38 * V_39 , struct V_81 * V_82 )
{
V_82 -> V_83 = 200 ;
V_82 -> V_84 = 0 ;
V_82 -> V_85 = 0 ;
return 0 ;
}
static void F_19 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
F_20 ( V_2 ) ;
}
struct V_38 * F_21 ( const struct V_86 * V_9 ,
struct V_87 * V_14 ,
T_1 V_43 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_22 ( sizeof( struct V_1 ) , V_88 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_20 = V_37 [ 0 ] ;
V_2 -> V_9 = V_9 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_43 = V_43 ;
if ( ( F_4 ( V_2 , 0x1a ) & 0xf0 ) != 0x70 )
goto error;
if ( V_77 )
F_3 ( L_7 , V_2 -> V_43 ) ;
memcpy ( & V_2 -> V_89 . V_56 , & V_90 , sizeof( struct V_91 ) ) ;
V_2 -> V_89 . V_56 . V_92 . V_93 = ( V_2 -> V_9 -> V_36 / 2 ) / 64 ;
V_2 -> V_89 . V_56 . V_92 . V_94 = ( V_2 -> V_9 -> V_36 / 2 ) / 4 ;
V_2 -> V_89 . V_40 = V_2 ;
return & V_2 -> V_89 ;
error:
F_20 ( V_2 ) ;
return NULL ;
}
