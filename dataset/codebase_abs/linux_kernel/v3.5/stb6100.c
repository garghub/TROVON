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
T_1 V_28 [ V_18 + 1 ] ;
struct V_10 V_11 = {
. V_12 = V_8 -> V_13 -> V_14 ,
. V_15 = 0 ,
. V_17 = V_28 ,
. V_18 = V_18 + 1
} ;
if ( F_4 ( V_27 < 1 || V_27 + V_18 > V_3 ) ) {
F_5 ( V_20 , V_21 , 1 , L_5 ,
V_27 , V_18 ) ;
return - V_26 ;
}
memcpy ( & V_28 [ 1 ] , V_17 , V_18 ) ;
V_28 [ 0 ] = V_27 ;
if ( F_4 ( V_20 > V_23 ) ) {
int V_2 ;
F_5 ( V_20 , V_23 , 1 , L_6 , V_8 -> V_13 -> V_14 , V_27 , V_18 ) ;
for ( V_2 = 0 ; V_2 < V_18 ; V_2 ++ )
F_5 ( V_20 , V_23 , 1 , L_3 , V_24 [ V_27 + V_2 ] , V_17 [ V_2 ] ) ;
}
V_9 = F_3 ( V_8 -> V_19 , & V_11 , 1 ) ;
if ( F_4 ( V_9 != 1 ) ) {
F_5 ( V_20 , V_21 , 1 , L_7 ,
( unsigned int ) V_8 -> V_13 -> V_14 , V_27 , V_18 , V_9 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_8 ( struct V_7 * V_8 , T_1 V_25 , T_1 V_29 )
{
if ( F_4 ( V_25 >= V_3 ) ) {
F_5 ( V_20 , V_21 , 1 , L_4 , V_25 ) ;
return - V_22 ;
}
V_29 = ( V_29 & V_4 [ V_25 ] . V_5 ) | V_4 [ V_25 ] . V_6 ;
return F_7 ( V_8 , & V_29 , V_25 , 1 ) ;
}
static int F_9 ( struct V_30 * V_31 , T_2 * V_32 )
{
int V_9 ;
struct V_7 * V_8 = V_31 -> V_33 ;
V_9 = F_6 ( V_8 , V_34 ) ;
if ( V_9 < 0 ) {
F_5 ( V_20 , V_21 , 1 , L_8 , V_35 ) ;
return V_9 ;
}
return ( V_9 & V_36 ) ? V_37 : 0 ;
}
static int F_10 ( struct V_30 * V_31 , T_2 * V_38 )
{
int V_9 ;
T_1 V_39 ;
struct V_7 * V_8 = V_31 -> V_33 ;
V_9 = F_6 ( V_8 , V_40 ) ;
if ( V_9 < 0 )
return V_9 ;
V_39 = V_9 & V_41 ;
V_8 -> V_32 . V_38 = ( V_39 + 5 ) * 2000 ;
* V_38 = V_8 -> V_38 = V_8 -> V_32 . V_38 * 1000 ;
F_5 ( V_20 , V_23 , 1 , L_9 , V_8 -> V_38 ) ;
return 0 ;
}
static int F_11 ( struct V_30 * V_31 , T_2 V_38 )
{
T_2 V_42 ;
int V_9 ;
struct V_7 * V_8 = V_31 -> V_33 ;
F_5 ( V_20 , V_23 , 1 , L_10 , V_38 ) ;
V_38 /= 2 ;
if ( V_38 >= 36000000 )
V_42 = 31 ;
else if ( V_38 <= 5000000 )
V_42 = 0 ;
else
V_42 = ( V_38 + 500000 ) / 1000000 - 5 ;
V_9 = F_8 ( V_8 , V_43 , 0x0d | V_44 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_8 ( V_8 , V_40 , 0xc0 | V_42 ) ;
if ( V_9 < 0 )
return V_9 ;
F_12 ( 5 ) ;
V_9 = F_8 ( V_8 , V_43 , 0x0d ) ;
if ( V_9 < 0 )
return V_9 ;
F_12 ( 10 ) ;
return 0 ;
}
static int F_13 ( struct V_30 * V_31 , T_2 * V_45 )
{
int V_9 ;
T_2 V_46 , V_47 , V_48 ;
int V_49 , V_50 ;
struct V_7 * V_8 = V_31 -> V_33 ;
T_1 V_1 [ V_3 ] ;
V_9 = F_2 ( V_8 , V_1 ) ;
if ( V_9 < 0 )
return V_9 ;
V_50 = ( V_1 [ V_51 ] & V_52 ) >> V_53 ;
V_49 = ( V_1 [ V_54 ] & V_55 ) >> V_56 ;
V_46 = V_1 [ V_57 ] ;
V_47 = ( ( V_1 [ V_54 ] & V_58 ) << 8 ) | V_1 [ V_59 ] ;
V_48 = ( V_47 * V_8 -> V_60 >> ( 9 - V_49 ) ) + ( V_46 * V_8 -> V_60 << V_49 ) ;
* V_45 = V_8 -> V_45 = V_48 >> ( V_50 + 1 ) ;
F_5 ( V_20 , V_23 , 1 ,
L_11 ,
V_8 -> V_45 , V_50 , V_49 , V_8 -> V_60 , V_48 , V_46 , V_47 ) ;
return 0 ;
}
static int F_14 ( struct V_30 * V_31 , T_2 V_45 )
{
int V_9 ;
const struct V_61 * V_62 ;
struct V_7 * V_8 = V_31 -> V_33 ;
struct V_63 * V_64 = & V_31 -> V_65 ;
T_2 V_66 = 0 , V_48 , V_46 , V_47 ;
T_1 V_1 [ V_3 ] ;
T_1 V_67 , V_49 , V_50 ;
F_5 ( V_20 , V_23 , 1 , L_12 ) ;
if ( V_31 -> V_68 . V_69 ) {
F_5 ( V_20 , V_23 , 1 , L_13 ) ;
V_31 -> V_68 . V_69 ( V_31 ) ;
}
V_66 = V_64 -> V_70 ;
V_9 = F_8 ( V_8 , V_43 , 0x4d | V_44 ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_71 ] = 0xeb ;
V_9 = F_8 ( V_8 , V_71 , V_1 [ V_71 ] ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_45 <= 1075000 )
V_50 = 1 ;
else
V_50 = 0 ;
V_1 [ V_51 ] = 0xe0 | ( V_50 << V_53 ) ;
for ( V_62 = V_72 ;
( V_62 -> V_73 != 0 ) && ! F_15 ( V_45 , V_62 -> V_74 , V_62 -> V_73 ) ;
V_62 ++ ) ;
if ( V_62 -> V_73 == 0 ) {
F_16 ( V_75 L_14 , V_35 , V_45 ) ;
return - V_26 ;
}
V_1 [ V_51 ] = ( V_1 [ V_51 ] & ~ V_76 ) | V_62 -> V_25 ;
V_9 = F_8 ( V_8 , V_51 , V_1 [ V_51 ] ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ( V_45 > 1075000 ) && ( V_45 <= 1325000 ) )
V_49 = 0 ;
else
V_49 = 1 ;
V_48 = V_45 << ( 1 + V_50 ) ;
V_46 = V_48 / ( V_8 -> V_60 << V_49 ) ;
V_47 = F_17 ( ( V_48 - ( V_46 * V_8 -> V_60 << V_49 ) )
<< ( 9 - V_49 ) , V_8 -> V_60 ) ;
V_1 [ V_57 ] = V_46 ;
V_9 = F_8 ( V_8 , V_57 , V_1 [ V_57 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_59 ] = V_47 ;
V_9 = F_8 ( V_8 , V_59 , V_1 [ V_59 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_54 ] = ( 0x38 & ~ V_55 ) | ( V_49 << V_56 ) ;
V_1 [ V_54 ] = ( V_1 [ V_54 ] & ~ V_58 ) | ( ( V_47 >> 8 ) & V_58 ) ;
V_9 = F_8 ( V_8 , V_54 , V_1 [ V_54 ] ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_66 >= 15000000 )
V_67 = 9 ;
else if ( V_66 >= 5000000 )
V_67 = 11 ;
else
V_67 = 14 ;
V_1 [ V_77 ] = ( 0x10 & ~ V_78 ) | V_67 ;
V_1 [ V_77 ] &= ~ V_79 ;
V_1 [ V_77 ] |= ( 1 << 5 ) ;
V_9 = F_8 ( V_8 , V_77 , V_1 [ V_77 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_80 ] = 0xcc ;
V_9 = F_8 ( V_8 , V_80 , V_1 [ V_80 ] ) ;
if ( V_9 < 0 )
return V_9 ;
F_5 ( V_20 , V_23 , 1 ,
L_15 ,
V_45 , V_66 , ( unsigned int ) V_67 , ( unsigned int ) V_50 ,
( unsigned int ) V_49 , V_8 -> V_60 ,
V_62 -> V_25 , V_48 , V_46 , V_47 ) ;
V_1 [ V_81 ] = 0x8f ;
V_9 = F_8 ( V_8 , V_81 , V_1 [ V_81 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_82 ] = 0xde ;
V_9 = F_8 ( V_8 , V_82 , V_1 [ V_82 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_71 ] = 0xfb ;
V_9 = F_8 ( V_8 , V_71 , V_1 [ V_71 ] ) ;
if ( V_9 < 0 )
return V_9 ;
F_12 ( 2 ) ;
V_1 [ V_51 ] &= ~ V_83 ;
V_9 = F_8 ( V_8 , V_51 , V_1 [ V_51 ] ) ;
if ( V_9 < 0 )
return V_9 ;
F_12 ( 10 ) ;
V_1 [ V_51 ] &= ~ V_84 ;
V_1 [ V_51 ] |= V_83 ;
V_9 = F_8 ( V_8 , V_51 , V_1 [ V_51 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_8 ( V_8 , V_43 , 0x0d ) ;
if ( V_9 < 0 )
return V_9 ;
F_12 ( 10 ) ;
return 0 ;
}
static int F_18 ( struct V_30 * V_31 )
{
return 0 ;
}
static int F_19 ( struct V_30 * V_31 )
{
struct V_7 * V_8 = V_31 -> V_33 ;
struct V_85 * V_32 = & V_8 -> V_32 ;
V_32 -> V_86 = 125000 ;
V_32 -> V_87 = 0 ;
V_32 -> V_88 = 27000000 ;
V_32 -> V_89 = 1 ;
V_32 -> V_38 = 36000 ;
V_8 -> V_38 = V_32 -> V_38 * 1000 ;
V_8 -> V_60 = V_32 -> V_88 / 1000 ;
return 0 ;
}
static int F_20 ( struct V_30 * V_31 ,
enum V_90 V_91 ,
struct V_85 * V_8 )
{
switch ( V_91 ) {
case V_92 :
F_13 ( V_31 , & V_8 -> V_45 ) ;
break;
case V_93 :
break;
case V_94 :
break;
case V_95 :
F_10 ( V_31 , & V_8 -> V_38 ) ;
break;
case V_96 :
break;
default:
break;
}
return 0 ;
}
static int F_21 ( struct V_30 * V_31 ,
enum V_90 V_91 ,
struct V_85 * V_8 )
{
struct V_7 * V_97 = V_31 -> V_33 ;
switch ( V_91 ) {
case V_92 :
F_14 ( V_31 , V_8 -> V_45 ) ;
V_97 -> V_45 = V_8 -> V_45 ;
break;
case V_93 :
break;
case V_94 :
break;
case V_95 :
F_11 ( V_31 , V_8 -> V_38 ) ;
V_97 -> V_38 = V_8 -> V_38 ;
break;
case V_96 :
break;
default:
break;
}
return 0 ;
}
struct V_30 * F_22 ( struct V_30 * V_31 ,
const struct V_98 * V_13 ,
struct V_99 * V_19 )
{
struct V_7 * V_8 = NULL ;
V_8 = F_23 ( sizeof ( struct V_7 ) , V_100 ) ;
if ( V_8 == NULL )
goto error;
V_8 -> V_13 = V_13 ;
V_8 -> V_19 = V_19 ;
V_8 -> V_101 = V_31 ;
V_8 -> V_60 = V_13 -> V_88 / 1000 ;
V_31 -> V_33 = V_8 ;
V_31 -> V_68 . V_102 = V_103 ;
F_16 ( L_16 , V_35 ) ;
return V_31 ;
error:
F_24 ( V_8 ) ;
return NULL ;
}
static int F_25 ( struct V_30 * V_31 )
{
struct V_7 * V_8 = V_31 -> V_33 ;
V_31 -> V_33 = NULL ;
F_24 ( V_8 ) ;
return 0 ;
}
