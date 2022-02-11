static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [] = { V_3 , V_4 } ;
struct V_7 V_8 = { . V_9 = 0 , . V_6 = V_6 , . V_10 = 2 } ;
V_8 . V_11 = V_2 -> V_12 -> V_13 ;
if ( V_14 >= 2 )
F_2 ( L_1 , V_15 , V_3 , V_4 ) ;
V_5 = F_3 ( V_2 -> V_16 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_2 ( L_2 ,
V_15 , V_3 , V_4 , V_5 ) ;
return ( V_5 != 1 ) ? - V_17 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_18 )
{
int V_5 ;
T_1 V_19 = V_2 -> V_12 -> V_13 ;
T_1 V_20 [] = { V_3 } ;
T_1 V_21 [] = { 0 } ;
struct V_7 V_8 [] = {
{ . V_11 = V_19 , . V_9 = 0 , . V_6 = V_20 , . V_10 = 1 } ,
{ . V_11 = V_19 , . V_9 = V_22 , . V_6 = V_21 , . V_10 = 1 } ,
} ;
V_5 = F_3 ( V_2 -> V_16 , V_8 , 2 ) ;
if ( V_5 != 2 ) {
F_2 ( L_3 , V_15 , V_3 , V_5 ) ;
return - V_17 ;
}
* V_18 = V_21 [ 0 ] ;
if ( V_14 >= 2 )
F_2 ( L_1 ,
V_15 , V_3 , V_21 [ 0 ] ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_23 , T_1 V_4 )
{
int V_5 ;
T_1 V_24 ;
V_4 &= V_23 ;
V_5 = F_4 ( V_2 , V_3 , & V_24 ) ;
if ( V_5 != 0 )
return V_5 ;
V_24 &= ~ V_23 ;
V_24 |= V_4 ;
V_5 = F_1 ( V_2 , V_3 , V_24 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_25 [ 3 ] ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 3 ; V_26 ++ ) {
F_1 ( V_2 , V_27 , V_26 + 1 ) ;
F_4 ( V_2 , V_28 , & V_25 [ V_26 ] ) ;
}
V_2 -> V_29 = V_25 [ 0 ] >> 4 ;
V_2 -> V_30 = V_25 [ 0 ] & 0x0F ;
V_2 -> V_31 = V_25 [ 1 ] & 0x0F ;
V_2 -> V_32 = V_25 [ 1 ] >> 4 ;
V_2 -> V_33 = V_25 [ 2 ] & 0x0F ;
V_2 -> V_34 = V_25 [ 2 ] >> 4 ;
F_2 ( L_4 , V_2 -> V_29 ) ;
F_2 ( L_5 , V_2 -> V_30 ) ;
F_2 ( L_6 , V_2 -> V_31 ) ;
F_2 ( L_7 , V_2 -> V_32 ) ;
F_2 ( L_8 , V_2 -> V_33 ) ;
F_2 ( L_9 , V_2 -> V_34 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_35 )
{
T_1 V_24 ;
V_24 = ( V_35 / 2 ) ;
if ( V_24 == 2 )
V_24 = 0x7 ;
else
V_24 -= 8 ;
F_5 ( V_2 , V_36 , 0x07 , V_24 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_37 )
{
T_1 V_38 ;
if ( V_37 == 8000000 )
V_38 = V_2 -> V_34 ;
else
V_38 = V_2 -> V_33 ;
F_5 ( V_2 , V_39 , 0xF0 , V_38 << 4 ) ;
return 0 ;
}
int F_9 ( T_2 V_40 , T_2 V_41 , T_2 * V_42 , T_2 * V_43 )
{
T_2 V_44 ;
T_2 V_45 , V_46 = 0 ;
int V_26 ;
if ( 0 == V_41 )
return - 1 ;
V_45 = V_40 / V_41 ;
V_44 = V_40 - V_45 * V_41 ;
for ( V_26 = 0 ; V_26 < 31 ; V_26 ++ ) {
V_44 <<= 1 ;
if ( V_44 >= V_41 ) {
V_46 += 1 ;
V_44 -= V_41 ;
}
V_46 <<= 1 ;
}
* V_42 = V_45 ;
* V_43 = V_46 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_47 )
{
T_1 V_48 ;
T_1 V_49 ;
T_2 V_50 ;
T_2 V_42 , V_43 ;
F_9 ( V_47 / 1000 , V_2 -> V_12 -> V_51 * 1000 ,
& V_42 , & V_43 ) ;
V_43 >>= 12 ;
F_1 ( V_2 , V_52 , V_42 ) ;
F_5 ( V_2 , V_53 , 0x0F , V_43 >> 16 ) ;
F_1 ( V_2 , V_54 , V_43 >> 8 ) ;
F_1 ( V_2 , V_55 , V_43 ) ;
V_49 = ( V_47 < 725000000 ) ?
V_2 -> V_29 : V_2 -> V_30 ;
V_50 = V_2 -> V_31 ;
V_50 += ( V_2 -> V_32 - V_2 -> V_31 )
* ( V_47 / 1000 - 470000 ) / ( 780000 - 470000 ) ;
V_48 = V_50 ;
F_2 ( L_10 , V_48 ) ;
V_48 |= V_49 << 4 ;
F_1 ( V_2 , V_56 , V_48 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_57 , V_58 ;
T_1 V_59 , V_60 ;
T_1 V_61 ;
T_1 V_62 , V_63 ;
T_1 V_64 ;
T_1 V_65 , V_66 , V_67 ;
F_4 ( V_2 , V_68 , & V_57 ) ;
F_4 ( V_2 , V_69 , & V_58 ) ;
V_59 = ( V_57 >> 6 ) & 0x01 ;
V_60 = ( V_57 >> 5 ) & 0x01 ;
V_61 = ( V_57 >> 4 ) & 0x01 ;
V_62 = ( V_57 >> 3 ) & 0x01 ;
V_63 = ( V_57 >> 2 ) & 0x01 ;
V_64 = V_57 & 0x01 ;
V_65 = V_58 >> 6 ;
V_66 = ( V_58 >> 3 ) & 0x7 ;
V_67 = V_58 & 0x7 ;
F_2 ( L_11 ,
V_60 , V_59 ) ;
F_2 ( L_12 , V_61 ) ;
F_2 ( L_13 ,
V_62 , V_63 ) ;
F_2 ( L_14 , V_64 ) ;
F_2 ( L_15 , V_65 , V_66 , V_67 ) ;
}
static int F_12 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_72 ;
struct V_73 * V_74 = & V_71 -> V_75 ;
int V_5 ;
switch ( V_74 -> V_76 ) {
case 7000000 :
case 8000000 :
V_2 -> V_77 = V_74 -> V_77 ;
break;
default:
F_13 ( V_78 L_16 ,
V_74 -> V_76 ) ;
return - V_79 ;
}
F_2 ( L_17 , V_15 , V_74 -> V_77 ) ;
if ( V_71 -> V_80 . V_81 )
V_71 -> V_80 . V_81 ( V_71 , 1 ) ;
F_8 ( V_2 , V_74 -> V_76 ) ;
V_5 = F_10 ( V_2 , V_2 -> V_77 ) ;
F_14 ( 50 ) ;
F_11 ( V_2 ) ;
if ( V_71 -> V_80 . V_81 )
V_71 -> V_80 . V_81 ( V_71 , 0 ) ;
if ( V_5 != 0 )
return - V_82 ;
return 0 ;
}
static int F_15 ( struct V_70 * V_71 , T_2 * V_47 )
{
struct V_1 * V_2 = V_71 -> V_72 ;
F_2 ( L_18 , V_15 ) ;
* V_47 = V_2 -> V_77 ;
return 0 ;
}
static int F_16 ( struct V_70 * V_71 , T_2 * V_37 )
{
struct V_1 * V_2 = V_71 -> V_72 ;
F_2 ( L_18 , V_15 ) ;
* V_37 = V_2 -> V_83 ;
return 0 ;
}
static int F_17 ( struct V_70 * V_71 , T_2 * V_57 )
{
struct V_1 * V_2 = V_71 -> V_72 ;
T_3 V_84 = 0 ;
F_2 ( L_18 , V_15 ) ;
if ( V_71 -> V_80 . V_81 )
V_71 -> V_80 . V_81 ( V_71 , 1 ) ;
F_11 ( V_2 ) ;
* V_57 = V_84 ;
if ( V_71 -> V_80 . V_81 )
V_71 -> V_80 . V_81 ( V_71 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_70 * V_71 )
{
F_2 ( L_18 , V_15 ) ;
return 0 ;
}
static int F_19 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_72 ;
F_2 ( L_18 , V_15 ) ;
if ( V_71 -> V_80 . V_81 )
V_71 -> V_80 . V_81 ( V_71 , 1 ) ;
F_1 ( V_2 , V_53 , 0x18 ) ;
F_1 ( V_2 , V_85 , 0x01 ) ;
F_1 ( V_2 , V_36 , 0x7A ) ;
F_1 ( V_2 , V_86 , 0x08 ) ;
F_1 ( V_2 , V_87 , 0x40 ) ;
F_1 ( V_2 , V_88 , 0x84 ) ;
F_1 ( V_2 , V_39 , 0xC3 ) ;
F_1 ( V_2 , V_89 , 0x75 ) ;
F_1 ( V_2 , V_90 , 0x00 ) ;
F_1 ( V_2 , V_27 , 0x00 ) ;
F_7 ( V_2 , V_2 -> V_12 -> V_51 ) ;
F_6 ( V_2 ) ;
F_8 ( V_2 , 8000000 ) ;
if ( V_71 -> V_80 . V_81 )
V_71 -> V_80 . V_81 ( V_71 , 0 ) ;
return 0 ;
}
static int F_20 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_72 ;
F_2 ( L_18 , V_15 ) ;
F_21 ( V_2 ) ;
V_71 -> V_72 = NULL ;
return 0 ;
}
struct V_70 * F_22 ( struct V_70 * V_71 ,
struct V_91 * V_16 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = NULL ;
F_2 ( L_19 , V_15 ,
V_16 ? F_23 ( V_16 ) : - 1 ,
V_93 ? V_93 -> V_13 : - 1 ) ;
V_2 = F_24 ( sizeof( struct V_1 ) , V_94 ) ;
if ( V_2 == NULL )
return NULL ;
memcpy ( & V_71 -> V_80 . V_95 , & V_96 ,
sizeof( struct V_97 ) ) ;
V_2 -> V_12 = V_93 ;
V_2 -> V_16 = V_16 ;
V_71 -> V_72 = V_2 ;
F_19 ( V_71 ) ;
F_11 ( V_2 ) ;
return V_71 ;
}
