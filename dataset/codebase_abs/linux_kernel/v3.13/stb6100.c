static inline void F_1 ( T_1 V_1 [] )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
V_1 [ V_2 ] = ( V_1 [ V_2 ] & V_4 [ V_2 ] . V_5 ) | V_4 [ V_2 ] . V_6 ;
}
static int F_2 ( struct V_7 * V_8 , T_1 V_1 [] )
{
int V_9 ;
struct V_10 V_11 = {
. V_12 = V_8 -> V_13 -> V_14 ,
. V_15 = V_16 ,
. V_17 = V_1 ,
. V_18 = V_3
} ;
V_9 = F_3 ( V_8 -> V_19 , & V_11 , 1 ) ;
if ( F_4 ( V_9 != 1 ) ) {
F_5 ( V_20 , V_21 , 1 , L_1 ,
V_8 -> V_13 -> V_14 , V_9 ) ;
return - V_22 ;
}
if ( F_4 ( V_20 > V_23 ) ) {
int V_2 ;
F_5 ( V_20 , V_23 , 1 , L_2 , V_8 -> V_13 -> V_14 ) ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
F_5 ( V_20 , V_23 , 1 , L_3 , V_24 [ V_2 ] , V_1 [ V_2 ] ) ;
}
return 0 ;
}
static int F_6 ( struct V_7 * V_8 , T_1 V_25 )
{
T_1 V_1 [ V_3 ] ;
struct V_10 V_11 = {
. V_12 = V_8 -> V_13 -> V_14 + V_25 ,
. V_15 = V_16 ,
. V_17 = V_1 ,
. V_18 = 1
} ;
F_3 ( V_8 -> V_19 , & V_11 , 1 ) ;
if ( F_4 ( V_25 >= V_3 ) ) {
F_5 ( V_20 , V_21 , 1 , L_4 , V_25 ) ;
return - V_26 ;
}
if ( F_4 ( V_20 > V_23 ) ) {
F_5 ( V_20 , V_23 , 1 , L_2 , V_8 -> V_13 -> V_14 ) ;
F_5 ( V_20 , V_23 , 1 , L_3 , V_24 [ V_25 ] , V_1 [ 0 ] ) ;
}
return ( unsigned int ) V_1 [ 0 ] ;
}
static int F_7 ( struct V_7 * V_8 , T_1 V_17 [] , int V_27 , int V_18 )
{
int V_9 ;
T_1 V_28 [ V_29 ] ;
struct V_10 V_11 = {
. V_12 = V_8 -> V_13 -> V_14 ,
. V_15 = 0 ,
. V_17 = V_28 ,
. V_18 = V_18 + 1
} ;
if ( 1 + V_18 > sizeof( V_17 ) ) {
F_8 ( V_30
L_5 ,
V_31 , V_18 ) ;
return - V_26 ;
}
if ( F_4 ( V_27 < 1 || V_27 + V_18 > V_3 ) ) {
F_5 ( V_20 , V_21 , 1 , L_6 ,
V_27 , V_18 ) ;
return - V_26 ;
}
memcpy ( & V_28 [ 1 ] , V_17 , V_18 ) ;
V_28 [ 0 ] = V_27 ;
if ( F_4 ( V_20 > V_23 ) ) {
int V_2 ;
F_5 ( V_20 , V_23 , 1 , L_7 , V_8 -> V_13 -> V_14 , V_27 , V_18 ) ;
for ( V_2 = 0 ; V_2 < V_18 ; V_2 ++ )
F_5 ( V_20 , V_23 , 1 , L_3 , V_24 [ V_27 + V_2 ] , V_17 [ V_2 ] ) ;
}
V_9 = F_3 ( V_8 -> V_19 , & V_11 , 1 ) ;
if ( F_4 ( V_9 != 1 ) ) {
F_5 ( V_20 , V_21 , 1 , L_8 ,
( unsigned int ) V_8 -> V_13 -> V_14 , V_27 , V_18 , V_9 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_9 ( struct V_7 * V_8 , T_1 V_25 , T_1 V_32 )
{
if ( F_4 ( V_25 >= V_3 ) ) {
F_5 ( V_20 , V_21 , 1 , L_4 , V_25 ) ;
return - V_22 ;
}
V_32 = ( V_32 & V_4 [ V_25 ] . V_5 ) | V_4 [ V_25 ] . V_6 ;
return F_7 ( V_8 , & V_32 , V_25 , 1 ) ;
}
static int F_10 ( struct V_33 * V_34 , T_2 * V_35 )
{
int V_9 ;
struct V_7 * V_8 = V_34 -> V_36 ;
V_9 = F_6 ( V_8 , V_37 ) ;
if ( V_9 < 0 ) {
F_5 ( V_20 , V_21 , 1 , L_9 , V_38 ) ;
return V_9 ;
}
return ( V_9 & V_39 ) ? V_40 : 0 ;
}
static int F_11 ( struct V_33 * V_34 , T_2 * V_41 )
{
int V_9 ;
T_1 V_42 ;
struct V_7 * V_8 = V_34 -> V_36 ;
V_9 = F_6 ( V_8 , V_43 ) ;
if ( V_9 < 0 )
return V_9 ;
V_42 = V_9 & V_44 ;
V_8 -> V_35 . V_41 = ( V_42 + 5 ) * 2000 ;
* V_41 = V_8 -> V_41 = V_8 -> V_35 . V_41 * 1000 ;
F_5 ( V_20 , V_23 , 1 , L_10 , V_8 -> V_41 ) ;
return 0 ;
}
static int F_12 ( struct V_33 * V_34 , T_2 V_41 )
{
T_2 V_45 ;
int V_9 ;
struct V_7 * V_8 = V_34 -> V_36 ;
F_5 ( V_20 , V_23 , 1 , L_11 , V_41 ) ;
V_41 /= 2 ;
if ( V_41 >= 36000000 )
V_45 = 31 ;
else if ( V_41 <= 5000000 )
V_45 = 0 ;
else
V_45 = ( V_41 + 500000 ) / 1000000 - 5 ;
V_9 = F_9 ( V_8 , V_46 , 0x0d | V_47 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_9 ( V_8 , V_43 , 0xc0 | V_45 ) ;
if ( V_9 < 0 )
return V_9 ;
F_13 ( 5 ) ;
V_9 = F_9 ( V_8 , V_46 , 0x0d ) ;
if ( V_9 < 0 )
return V_9 ;
F_13 ( 10 ) ;
return 0 ;
}
static int F_14 ( struct V_33 * V_34 , T_2 * V_48 )
{
int V_9 ;
T_2 V_49 , V_50 , V_51 ;
int V_52 , V_53 ;
struct V_7 * V_8 = V_34 -> V_36 ;
T_1 V_1 [ V_3 ] ;
V_9 = F_2 ( V_8 , V_1 ) ;
if ( V_9 < 0 )
return V_9 ;
V_53 = ( V_1 [ V_54 ] & V_55 ) >> V_56 ;
V_52 = ( V_1 [ V_57 ] & V_58 ) >> V_59 ;
V_49 = V_1 [ V_60 ] ;
V_50 = ( ( V_1 [ V_57 ] & V_61 ) << 8 ) | V_1 [ V_62 ] ;
V_51 = ( V_50 * V_8 -> V_63 >> ( 9 - V_52 ) ) + ( V_49 * V_8 -> V_63 << V_52 ) ;
* V_48 = V_8 -> V_48 = V_51 >> ( V_53 + 1 ) ;
F_5 ( V_20 , V_23 , 1 ,
L_12 ,
V_8 -> V_48 , V_53 , V_52 , V_8 -> V_63 , V_51 , V_49 , V_50 ) ;
return 0 ;
}
static int F_15 ( struct V_33 * V_34 , T_2 V_48 )
{
int V_9 ;
const struct V_64 * V_65 ;
struct V_7 * V_8 = V_34 -> V_36 ;
struct V_66 * V_67 = & V_34 -> V_68 ;
T_2 V_69 = 0 , V_51 , V_49 , V_50 ;
T_1 V_1 [ V_3 ] ;
T_1 V_70 , V_52 , V_53 ;
F_5 ( V_20 , V_23 , 1 , L_13 ) ;
if ( V_34 -> V_71 . V_72 ) {
F_5 ( V_20 , V_23 , 1 , L_14 ) ;
V_34 -> V_71 . V_72 ( V_34 ) ;
}
V_69 = V_67 -> V_73 ;
V_9 = F_9 ( V_8 , V_46 , 0x4d | V_47 ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_74 ] = 0xeb ;
V_9 = F_9 ( V_8 , V_74 , V_1 [ V_74 ] ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_48 <= 1075000 )
V_53 = 1 ;
else
V_53 = 0 ;
V_1 [ V_54 ] = 0xe0 | ( V_53 << V_56 ) ;
for ( V_65 = V_75 ;
( V_65 -> V_76 != 0 ) && ! F_16 ( V_48 , V_65 -> V_77 , V_65 -> V_76 ) ;
V_65 ++ ) ;
if ( V_65 -> V_76 == 0 ) {
F_8 ( V_78 L_15 , V_38 , V_48 ) ;
return - V_26 ;
}
V_1 [ V_54 ] = ( V_1 [ V_54 ] & ~ V_79 ) | V_65 -> V_25 ;
V_9 = F_9 ( V_8 , V_54 , V_1 [ V_54 ] ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ( V_48 > 1075000 ) && ( V_48 <= 1325000 ) )
V_52 = 0 ;
else
V_52 = 1 ;
V_51 = V_48 << ( 1 + V_53 ) ;
V_49 = V_51 / ( V_8 -> V_63 << V_52 ) ;
V_50 = F_17 ( ( V_51 - ( V_49 * V_8 -> V_63 << V_52 ) )
<< ( 9 - V_52 ) , V_8 -> V_63 ) ;
V_1 [ V_60 ] = V_49 ;
V_9 = F_9 ( V_8 , V_60 , V_1 [ V_60 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_62 ] = V_50 ;
V_9 = F_9 ( V_8 , V_62 , V_1 [ V_62 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_57 ] = ( 0x38 & ~ V_58 ) | ( V_52 << V_59 ) ;
V_1 [ V_57 ] = ( V_1 [ V_57 ] & ~ V_61 ) | ( ( V_50 >> 8 ) & V_61 ) ;
V_9 = F_9 ( V_8 , V_57 , V_1 [ V_57 ] ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_69 >= 15000000 )
V_70 = 9 ;
else if ( V_69 >= 5000000 )
V_70 = 11 ;
else
V_70 = 14 ;
V_1 [ V_80 ] = ( 0x10 & ~ V_81 ) | V_70 ;
V_1 [ V_80 ] &= ~ V_82 ;
V_1 [ V_80 ] |= ( 1 << 5 ) ;
V_9 = F_9 ( V_8 , V_80 , V_1 [ V_80 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_83 ] = 0xcc ;
V_9 = F_9 ( V_8 , V_83 , V_1 [ V_83 ] ) ;
if ( V_9 < 0 )
return V_9 ;
F_5 ( V_20 , V_23 , 1 ,
L_16 ,
V_48 , V_69 , ( unsigned int ) V_70 , ( unsigned int ) V_53 ,
( unsigned int ) V_52 , V_8 -> V_63 ,
V_65 -> V_25 , V_51 , V_49 , V_50 ) ;
V_1 [ V_84 ] = 0x8f ;
V_9 = F_9 ( V_8 , V_84 , V_1 [ V_84 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_85 ] = 0xde ;
V_9 = F_9 ( V_8 , V_85 , V_1 [ V_85 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_74 ] = 0xfb ;
V_9 = F_9 ( V_8 , V_74 , V_1 [ V_74 ] ) ;
if ( V_9 < 0 )
return V_9 ;
F_13 ( 2 ) ;
V_1 [ V_54 ] &= ~ V_86 ;
V_9 = F_9 ( V_8 , V_54 , V_1 [ V_54 ] ) ;
if ( V_9 < 0 )
return V_9 ;
F_13 ( 10 ) ;
V_1 [ V_54 ] &= ~ V_87 ;
V_1 [ V_54 ] |= V_86 ;
V_9 = F_9 ( V_8 , V_54 , V_1 [ V_54 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_9 ( V_8 , V_46 , 0x0d ) ;
if ( V_9 < 0 )
return V_9 ;
F_13 ( 10 ) ;
return 0 ;
}
static int F_18 ( struct V_33 * V_34 )
{
return 0 ;
}
static int F_19 ( struct V_33 * V_34 )
{
struct V_7 * V_8 = V_34 -> V_36 ;
struct V_88 * V_35 = & V_8 -> V_35 ;
V_35 -> V_89 = 125000 ;
V_35 -> V_90 = 0 ;
V_35 -> V_91 = 27000000 ;
V_35 -> V_92 = 1 ;
V_35 -> V_41 = 36000 ;
V_8 -> V_41 = V_35 -> V_41 * 1000 ;
V_8 -> V_63 = V_35 -> V_91 / 1000 ;
return 0 ;
}
static int F_20 ( struct V_33 * V_34 ,
enum V_93 V_94 ,
struct V_88 * V_8 )
{
switch ( V_94 ) {
case V_95 :
F_14 ( V_34 , & V_8 -> V_48 ) ;
break;
case V_96 :
break;
case V_97 :
break;
case V_98 :
F_11 ( V_34 , & V_8 -> V_41 ) ;
break;
case V_99 :
break;
default:
break;
}
return 0 ;
}
static int F_21 ( struct V_33 * V_34 ,
enum V_93 V_94 ,
struct V_88 * V_8 )
{
struct V_7 * V_100 = V_34 -> V_36 ;
switch ( V_94 ) {
case V_95 :
F_15 ( V_34 , V_8 -> V_48 ) ;
V_100 -> V_48 = V_8 -> V_48 ;
break;
case V_96 :
break;
case V_97 :
break;
case V_98 :
F_12 ( V_34 , V_8 -> V_41 ) ;
V_100 -> V_41 = V_8 -> V_41 ;
break;
case V_99 :
break;
default:
break;
}
return 0 ;
}
struct V_33 * F_22 ( struct V_33 * V_34 ,
const struct V_101 * V_13 ,
struct V_102 * V_19 )
{
struct V_7 * V_8 = NULL ;
V_8 = F_23 ( sizeof ( struct V_7 ) , V_103 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_13 = V_13 ;
V_8 -> V_19 = V_19 ;
V_8 -> V_104 = V_34 ;
V_8 -> V_63 = V_13 -> V_91 / 1000 ;
V_34 -> V_36 = V_8 ;
V_34 -> V_71 . V_105 = V_106 ;
F_8 ( L_17 , V_38 ) ;
return V_34 ;
}
static int F_24 ( struct V_33 * V_34 )
{
struct V_7 * V_8 = V_34 -> V_36 ;
V_34 -> V_36 = NULL ;
F_25 ( V_8 ) ;
return 0 ;
}
