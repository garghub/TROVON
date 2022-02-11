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
static int F_5 ( struct V_1 * V_2 , T_1 V_20 , T_2 V_21 )
{
V_20 |= V_2 -> V_20 & 0x62 ;
if ( V_22 == V_21 ) {
if ( ! V_2 -> V_9 -> V_23 ) V_20 |= 0x20 ;
else V_20 &= ~ 0x20 ;
} else if ( V_24 == V_21 ) {
if ( ! V_2 -> V_9 -> V_23 ) V_20 &= ~ 0x20 ;
else V_20 |= 0x20 ;
}
F_1 ( V_2 , 0x00 , V_20 & 0xfe ) ;
F_1 ( V_2 , 0x00 , V_20 | 0x01 ) ;
V_2 -> V_20 = V_20 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_3 V_25 )
{
T_4 V_26 ;
T_4 V_27 ;
T_5 V_28 = 0 ;
T_6 V_29 = 0 ;
T_3 V_30 ;
T_3 V_31 ;
T_3 V_32 ;
T_7 V_33 ;
T_7 V_34 ;
if ( V_25 > V_2 -> V_9 -> V_35 / 2 )
V_25 = V_2 -> V_9 -> V_35 / 2 ;
if ( V_25 < 500000 )
V_25 = 500000 ;
if ( V_25 < V_2 -> V_9 -> V_35 / 16 )
V_29 = 1 ;
if ( V_25 < V_2 -> V_9 -> V_35 / 32 )
V_29 = 2 ;
if ( V_25 < V_2 -> V_9 -> V_35 / 64 )
V_29 = 3 ;
V_34 = V_2 -> V_9 -> V_35 * 10 ;
V_33 = V_34 ; F_7 ( V_33 , 123 ) ;
if ( V_25 < V_33 )
V_28 = 1 ;
V_33 = V_34 ; F_7 ( V_33 , 160 ) ;
if ( V_25 < V_33 )
V_28 = 0 ;
V_33 = V_34 ; F_7 ( V_33 , 246 ) ;
if ( V_25 < V_33 )
V_28 = 1 ;
V_33 = V_34 ; F_7 ( V_33 , 320 ) ;
if ( V_25 < V_33 )
V_28 = 0 ;
V_33 = V_34 ; F_7 ( V_33 , 492 ) ;
if ( V_25 < V_33 )
V_28 = 1 ;
V_33 = V_34 ; F_7 ( V_33 , 640 ) ;
if ( V_25 < V_33 )
V_28 = 0 ;
V_33 = V_34 ; F_7 ( V_33 , 984 ) ;
if ( V_25 < V_33 )
V_28 = 1 ;
V_31 = V_2 -> V_9 -> V_35 >> 4 ;
V_25 <<= V_29 ;
V_30 = ( V_25 << 4 ) / V_31 ;
V_32 = ( ( V_25 << 4 ) % V_31 ) << 8 ;
V_30 = ( V_30 << 8 ) + V_32 / V_31 ;
V_32 = ( V_32 % V_31 ) << 8 ;
V_30 = ( V_30 << 8 ) + F_8 ( V_32 , V_31 ) ;
V_26 = V_30 ;
V_27 = ( ( ( V_2 -> V_9 -> V_35 << 5 ) / V_25 ) + 1 ) / 2 ;
if ( V_27 > 0xFF )
V_27 = 0xFF ;
V_28 = ( V_28 << 4 ) | V_36 [ 0x0E ] ;
V_29 = ( V_29 << 6 ) | V_36 [ 0x03 ] ;
F_1 ( V_2 , 0x03 , V_29 ) ;
F_1 ( V_2 , 0x0a , V_26 & 0xff ) ;
F_1 ( V_2 , 0x0b , ( V_26 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x0c , ( V_26 >> 16 ) & 0x3f ) ;
F_1 ( V_2 , 0x0d , V_27 ) ;
F_1 ( V_2 , 0x0e , V_28 ) ;
return 0 ;
}
static int F_9 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
int V_40 ;
F_1 ( V_2 , 0 , 0 ) ;
for ( V_40 = 0 ; V_40 < sizeof( V_36 ) ; V_40 ++ )
F_1 ( V_2 , V_40 , V_36 [ V_40 ] ) ;
if ( V_2 -> V_9 -> V_41 )
F_1 ( V_2 , 2 , V_36 [ 2 ] | 0x08 ) ;
F_1 ( V_2 , 0x34 , V_2 -> V_42 ) ;
return 0 ;
}
static int F_10 ( struct V_37 * V_38 )
{
struct V_43 * V_44 = & V_38 -> V_45 ;
struct V_1 * V_2 = V_38 -> V_39 ;
static const T_1 V_46 [] = { 0x00 , 0x04 , 0x08 , 0x0c , 0x10 } ;
static const T_1 V_47 [] = { 140 , 140 , 106 , 100 , 92 } ;
static const T_1 V_48 [] = { 135 , 100 , 70 , 54 , 38 } ;
static const T_1 V_49 [] = { 162 , 116 , 67 , 52 , 35 } ;
static const T_1 V_50 [] = { 145 , 150 , 106 , 126 , 107 } ;
int V_51 = V_44 -> V_52 - V_53 ;
if ( V_51 < 0 || V_51 > 4 )
return - V_54 ;
if ( V_38 -> V_55 . V_56 . V_57 ) {
V_38 -> V_55 . V_56 . V_57 ( V_38 ) ;
if ( V_38 -> V_55 . V_58 ) V_38 -> V_55 . V_58 ( V_38 , 0 ) ;
}
F_6 ( V_2 , V_44 -> V_59 ) ;
F_1 ( V_2 , 0x34 , V_2 -> V_42 ) ;
F_1 ( V_2 , 0x01 , V_47 [ V_51 ] ) ;
F_1 ( V_2 , 0x05 , V_48 [ V_51 ] ) ;
F_1 ( V_2 , 0x08 , V_49 [ V_51 ] ) ;
F_1 ( V_2 , 0x09 , V_50 [ V_51 ] ) ;
F_5 ( V_2 , V_46 [ V_51 ] , V_44 -> V_21 ) ;
F_1 ( V_2 , 2 , V_36 [ 2 ] | ( V_2 -> V_9 -> V_41 ? 0x08 : 0 ) ) ;
return 0 ;
}
static int F_11 ( struct V_37 * V_38 , T_8 * V_60 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
int V_61 ;
* V_60 = 0 ;
V_61 = F_4 ( V_2 , 0x11 ) ;
if ( V_61 & 1 )
* V_60 |= V_62 ;
if ( V_61 & 2 )
* V_60 |= V_63 ;
if ( V_61 & 2 )
* V_60 |= V_64 ;
if ( V_61 & 4 )
* V_60 |= V_65 ;
if ( V_61 & 8 )
* V_60 |= V_66 ;
return 0 ;
}
static int F_12 ( struct V_37 * V_38 , T_3 * V_67 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
T_3 V_68 = F_4 ( V_2 , 0x14 ) |
( F_4 ( V_2 , 0x15 ) << 8 ) |
( ( F_4 ( V_2 , 0x16 ) & 0x0f ) << 16 ) ;
* V_67 = 10 * V_68 ;
return 0 ;
}
static int F_13 ( struct V_37 * V_38 , T_6 * V_69 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
T_1 V_70 = F_4 ( V_2 , 0x17 ) ;
* V_69 = ( V_70 << 8 ) | V_70 ;
return 0 ;
}
static int F_14 ( struct V_37 * V_38 , T_6 * V_71 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
T_1 V_72 = ~ F_4 ( V_2 , 0x18 ) ;
* V_71 = ( V_72 << 8 ) | V_72 ;
return 0 ;
}
static int F_15 ( struct V_37 * V_38 , T_3 * V_73 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
* V_73 = F_4 ( V_2 , 0x13 ) & 0x7f ;
if ( * V_73 == 0x7f )
* V_73 = 0xffffffff ;
F_1 ( V_2 , 0x10 , V_36 [ 0x10 ] & 0xdf ) ;
F_1 ( V_2 , 0x10 , V_36 [ 0x10 ] ) ;
return 0 ;
}
static int F_16 ( struct V_37 * V_38 )
{
struct V_43 * V_44 = & V_38 -> V_45 ;
struct V_1 * V_2 = V_38 -> V_39 ;
int V_61 ;
T_9 V_74 = 0 ;
V_61 = F_4 ( V_2 , 0x11 ) ;
V_74 = F_4 ( V_2 , 0x19 ) ;
if ( V_75 ) {
F_3 ( V_61 & 2 ? L_5 :
L_6 , V_74 , - ( ( T_4 ) V_44 -> V_59 * V_74 ) >> 10 ) ;
}
if ( ! V_2 -> V_9 -> V_23 ) {
V_44 -> V_21 = ( V_2 -> V_20 & 0x20 ) ? V_22 : V_24 ;
} else {
V_44 -> V_21 = ( ! ( V_2 -> V_20 & 0x20 ) ) ? V_22 : V_24 ;
}
V_44 -> V_52 = ( ( V_2 -> V_20 >> 2 ) & 7 ) + V_53 ;
V_44 -> V_76 = V_77 ;
V_44 -> V_78 = ( ( V_44 -> V_78 + 31250 ) / 62500 ) * 62500 ;
if ( V_61 & 2 )
V_44 -> V_78 -= ( ( T_4 ) V_44 -> V_59 * V_74 ) >> 10 ;
return 0 ;
}
static int F_17 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
F_1 ( V_2 , 0x1b , 0x02 ) ;
F_1 ( V_2 , 0x00 , 0x80 ) ;
return 0 ;
}
static int F_18 ( struct V_37 * V_38 , struct V_79 * V_80 )
{
V_80 -> V_81 = 200 ;
V_80 -> V_82 = 0 ;
V_80 -> V_83 = 0 ;
return 0 ;
}
static void F_19 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
F_20 ( V_2 ) ;
}
struct V_37 * F_21 ( const struct V_84 * V_9 ,
struct V_85 * V_14 ,
T_1 V_42 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_22 ( sizeof( struct V_1 ) , V_86 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_20 = V_36 [ 0 ] ;
V_2 -> V_9 = V_9 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_42 = V_42 ;
if ( ( F_4 ( V_2 , 0x1a ) & 0xf0 ) != 0x70 )
goto error;
if ( V_75 )
F_3 ( L_7 , V_2 -> V_42 ) ;
memcpy ( & V_2 -> V_87 . V_55 , & V_88 , sizeof( struct V_89 ) ) ;
V_2 -> V_87 . V_55 . V_90 . V_91 = ( V_2 -> V_9 -> V_35 / 2 ) / 64 ;
V_2 -> V_87 . V_55 . V_90 . V_92 = ( V_2 -> V_9 -> V_35 / 2 ) / 4 ;
V_2 -> V_87 . V_39 = V_2 ;
return & V_2 -> V_87 ;
error:
F_20 ( V_2 ) ;
return NULL ;
}
