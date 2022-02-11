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
if ( 1 + V_18 > sizeof( V_28 ) ) {
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
T_2 V_43 ;
struct V_7 * V_8 = V_34 -> V_36 ;
V_9 = F_6 ( V_8 , V_44 ) ;
if ( V_9 < 0 )
return V_9 ;
V_42 = V_9 & V_45 ;
V_43 = ( V_42 + 5 ) * 2000 ;
* V_41 = V_8 -> V_41 = V_43 * 1000 ;
F_5 ( V_20 , V_23 , 1 , L_10 , V_8 -> V_41 ) ;
return 0 ;
}
static int F_12 ( struct V_33 * V_34 , T_2 V_41 )
{
T_2 V_46 ;
int V_9 ;
struct V_7 * V_8 = V_34 -> V_36 ;
F_5 ( V_20 , V_23 , 1 , L_11 , V_41 ) ;
V_41 /= 2 ;
if ( V_41 >= 36000000 )
V_46 = 31 ;
else if ( V_41 <= 5000000 )
V_46 = 0 ;
else
V_46 = ( V_41 + 500000 ) / 1000000 - 5 ;
V_9 = F_9 ( V_8 , V_47 , 0x0d | V_48 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_9 ( V_8 , V_44 , 0xc0 | V_46 ) ;
if ( V_9 < 0 )
return V_9 ;
F_13 ( 5 ) ;
V_9 = F_9 ( V_8 , V_47 , 0x0d ) ;
if ( V_9 < 0 )
return V_9 ;
F_13 ( 10 ) ;
return 0 ;
}
static int F_14 ( struct V_33 * V_34 , T_2 * V_49 )
{
int V_9 ;
T_2 V_50 , V_51 , V_52 ;
int V_53 , V_54 ;
struct V_7 * V_8 = V_34 -> V_36 ;
T_1 V_1 [ V_3 ] ;
V_9 = F_2 ( V_8 , V_1 ) ;
if ( V_9 < 0 )
return V_9 ;
V_54 = ( V_1 [ V_55 ] & V_56 ) >> V_57 ;
V_53 = ( V_1 [ V_58 ] & V_59 ) >> V_60 ;
V_50 = V_1 [ V_61 ] ;
V_51 = ( ( V_1 [ V_58 ] & V_62 ) << 8 ) | V_1 [ V_63 ] ;
V_52 = ( V_51 * V_8 -> V_64 >> ( 9 - V_53 ) ) + ( V_50 * V_8 -> V_64 << V_53 ) ;
* V_49 = V_8 -> V_49 = V_52 >> ( V_54 + 1 ) ;
F_5 ( V_20 , V_23 , 1 ,
L_12 ,
V_8 -> V_49 , V_54 , V_53 , V_8 -> V_64 , V_52 , V_50 , V_51 ) ;
return 0 ;
}
static int F_15 ( struct V_33 * V_34 , T_2 V_49 )
{
int V_9 ;
const struct V_65 * V_66 ;
struct V_7 * V_8 = V_34 -> V_36 ;
struct V_67 * V_68 = & V_34 -> V_69 ;
T_2 V_70 = 0 , V_52 , V_50 , V_51 ;
T_1 V_1 [ V_3 ] ;
T_1 V_71 , V_53 , V_54 ;
F_5 ( V_20 , V_23 , 1 , L_13 ) ;
if ( V_34 -> V_72 . V_73 ) {
F_5 ( V_20 , V_23 , 1 , L_14 ) ;
V_34 -> V_72 . V_73 ( V_34 , V_68 ) ;
}
V_70 = V_68 -> V_74 ;
V_9 = F_9 ( V_8 , V_47 , 0x4d | V_48 ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_75 ] = 0xeb ;
V_9 = F_9 ( V_8 , V_75 , V_1 [ V_75 ] ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_49 <= 1075000 )
V_54 = 1 ;
else
V_54 = 0 ;
V_1 [ V_55 ] = 0xe0 | ( V_54 << V_57 ) ;
for ( V_66 = V_76 ;
( V_66 -> V_77 != 0 ) && ! F_16 ( V_49 , V_66 -> V_78 , V_66 -> V_77 ) ;
V_66 ++ ) ;
if ( V_66 -> V_77 == 0 ) {
F_8 ( V_79 L_15 , V_38 , V_49 ) ;
return - V_26 ;
}
V_1 [ V_55 ] = ( V_1 [ V_55 ] & ~ V_80 ) | V_66 -> V_25 ;
V_9 = F_9 ( V_8 , V_55 , V_1 [ V_55 ] ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ( V_49 > 1075000 ) && ( V_49 <= 1325000 ) )
V_53 = 0 ;
else
V_53 = 1 ;
V_52 = V_49 << ( 1 + V_54 ) ;
V_50 = V_52 / ( V_8 -> V_64 << V_53 ) ;
V_51 = F_17 ( ( V_52 - ( V_50 * V_8 -> V_64 << V_53 ) )
<< ( 9 - V_53 ) , V_8 -> V_64 ) ;
V_1 [ V_61 ] = V_50 ;
V_9 = F_9 ( V_8 , V_61 , V_1 [ V_61 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_63 ] = V_51 ;
V_9 = F_9 ( V_8 , V_63 , V_1 [ V_63 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_58 ] = ( 0x38 & ~ V_59 ) | ( V_53 << V_60 ) ;
V_1 [ V_58 ] = ( V_1 [ V_58 ] & ~ V_62 ) | ( ( V_51 >> 8 ) & V_62 ) ;
V_9 = F_9 ( V_8 , V_58 , V_1 [ V_58 ] ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_70 >= 15000000 )
V_71 = 9 ;
else if ( V_70 >= 5000000 )
V_71 = 11 ;
else
V_71 = 14 ;
V_1 [ V_81 ] = ( 0x10 & ~ V_82 ) | V_71 ;
V_1 [ V_81 ] &= ~ V_83 ;
V_1 [ V_81 ] |= ( 1 << 5 ) ;
V_9 = F_9 ( V_8 , V_81 , V_1 [ V_81 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_84 ] = 0xcc ;
V_9 = F_9 ( V_8 , V_84 , V_1 [ V_84 ] ) ;
if ( V_9 < 0 )
return V_9 ;
F_5 ( V_20 , V_23 , 1 ,
L_16 ,
V_49 , V_70 , ( unsigned int ) V_71 , ( unsigned int ) V_54 ,
( unsigned int ) V_53 , V_8 -> V_64 ,
V_66 -> V_25 , V_52 , V_50 , V_51 ) ;
V_1 [ V_85 ] = 0x8f ;
V_9 = F_9 ( V_8 , V_85 , V_1 [ V_85 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_86 ] = 0xde ;
V_9 = F_9 ( V_8 , V_86 , V_1 [ V_86 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 [ V_75 ] = 0xfb ;
V_9 = F_9 ( V_8 , V_75 , V_1 [ V_75 ] ) ;
if ( V_9 < 0 )
return V_9 ;
F_13 ( 2 ) ;
V_1 [ V_55 ] &= ~ V_87 ;
V_9 = F_9 ( V_8 , V_55 , V_1 [ V_55 ] ) ;
if ( V_9 < 0 )
return V_9 ;
F_13 ( 10 ) ;
V_1 [ V_55 ] &= ~ V_88 ;
V_1 [ V_55 ] |= V_87 ;
V_9 = F_9 ( V_8 , V_55 , V_1 [ V_55 ] ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_9 ( V_8 , V_47 , 0x0d ) ;
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
int V_89 = 27000000 ;
V_8 -> V_41 = 36000000 ;
V_8 -> V_64 = V_89 / 1000 ;
return 0 ;
}
static int F_20 ( struct V_33 * V_34 )
{
struct V_67 * V_90 = & V_34 -> V_69 ;
if ( V_90 -> V_49 > 0 )
F_15 ( V_34 , V_90 -> V_49 ) ;
if ( V_90 -> V_91 > 0 )
F_12 ( V_34 , V_90 -> V_91 ) ;
return 0 ;
}
struct V_33 * F_21 ( struct V_33 * V_34 ,
const struct V_92 * V_13 ,
struct V_93 * V_19 )
{
struct V_7 * V_8 = NULL ;
V_8 = F_22 ( sizeof ( struct V_7 ) , V_94 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_13 = V_13 ;
V_8 -> V_19 = V_19 ;
V_8 -> V_95 = V_34 ;
V_8 -> V_64 = V_13 -> V_96 / 1000 ;
V_34 -> V_36 = V_8 ;
V_34 -> V_72 . V_97 = V_98 ;
F_8 ( L_17 , V_38 ) ;
return V_34 ;
}
static int F_23 ( struct V_33 * V_34 )
{
struct V_7 * V_8 = V_34 -> V_36 ;
V_34 -> V_36 = NULL ;
F_24 ( V_8 ) ;
return 0 ;
}
