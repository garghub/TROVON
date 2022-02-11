static T_1 F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
return F_2 ( V_2 -> V_5 ,
V_2 -> V_6 + V_3 * V_7 + V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 , T_1 V_8 )
{
F_4 ( V_2 -> V_5 , V_2 -> V_6 + V_3 * V_7 + V_4 ,
V_8 ) ;
}
static void F_5 ( struct V_9 * V_10 )
{
struct V_11 * V_12 =
F_6 ( V_10 -> V_10 . V_12 ) ;
struct V_13 * V_14 = V_10 -> V_10 . V_12 -> V_14 ;
struct V_1 * V_2 = V_10 -> V_15 ;
unsigned int V_16 = V_12 -> V_12 . V_16 >> 16 ;
unsigned int V_17 = V_12 -> V_12 . V_17 >> 16 ;
unsigned int V_3 = V_12 -> V_18 ;
struct V_19 * V_20 ;
bool V_21 ;
T_1 V_22 ;
V_21 = V_12 -> V_12 . V_23 -> V_12 -> V_24 . V_25
& V_26 ;
if ( V_12 -> V_27 -> V_28 == 2 )
V_22 = V_14 -> V_29 [ 0 ] ;
else
V_22 = V_14 -> V_29 [ 0 ] * 8 / V_12 -> V_27 -> V_30 ;
if ( V_21 && V_12 -> V_27 -> V_30 == 32 )
V_22 *= 2 ;
F_3 ( V_2 , V_3 , V_31 , V_22 ) ;
F_3 ( V_2 , V_3 , V_32 , V_16 ) ;
F_3 ( V_2 , V_3 , V_33 , V_17 *
( ! V_21 && V_12 -> V_27 -> V_30 == 32 ? 2 : 1 ) ) ;
V_20 = F_7 ( V_14 , 0 ) ;
F_3 ( V_2 , V_3 , V_34 , V_20 -> V_35 + V_14 -> V_36 [ 0 ] ) ;
if ( V_12 -> V_27 -> V_28 == 2 ) {
V_3 = ( V_3 + 1 ) % 8 ;
F_3 ( V_2 , V_3 , V_31 , V_14 -> V_29 [ 0 ] ) ;
F_3 ( V_2 , V_3 , V_32 , V_16 ) ;
F_3 ( V_2 , V_3 , V_33 , V_17 *
( V_12 -> V_27 -> V_30 == 16 ? 2 : 1 ) / 2 ) ;
V_20 = F_7 ( V_14 , 1 ) ;
F_3 ( V_2 , V_3 , V_34 ,
V_20 -> V_35 + V_14 -> V_36 [ 1 ] ) ;
}
}
static void F_8 ( struct V_9 * V_10 ,
unsigned int V_3 )
{
struct V_11 * V_12 =
F_6 ( V_10 -> V_10 . V_12 ) ;
struct V_1 * V_2 = V_10 -> V_15 ;
T_1 V_37 ;
T_1 V_38 ;
if ( V_12 -> V_27 -> V_39 != V_40 )
F_3 ( V_2 , V_3 , V_41 , V_42 ) ;
else
F_3 ( V_2 , V_3 , V_41 ,
V_43 | V_12 -> V_44 ) ;
V_38 = V_45 | V_12 -> V_27 -> V_38 ;
if ( ( V_12 -> V_37 & V_46 ) == V_47 )
V_38 |= V_48 ;
if ( V_12 -> V_27 -> V_39 == V_49 )
V_38 |= V_50 ;
F_3 ( V_2 , V_3 , V_51 , V_38 ) ;
switch ( V_12 -> V_27 -> V_39 ) {
case V_52 :
V_37 = ( ( V_12 -> V_37 & 0xf80000 ) >> 8 )
| ( ( V_12 -> V_37 & 0x00fc00 ) >> 5 )
| ( ( V_12 -> V_37 & 0x0000f8 ) >> 3 ) ;
F_3 ( V_2 , V_3 , V_53 , V_37 ) ;
break;
case V_54 :
case V_40 :
V_37 = ( ( V_12 -> V_37 & 0xf80000 ) >> 9 )
| ( ( V_12 -> V_37 & 0x00f800 ) >> 6 )
| ( ( V_12 -> V_37 & 0x0000f8 ) >> 3 ) ;
F_3 ( V_2 , V_3 , V_53 , V_37 ) ;
break;
case V_55 :
case V_56 :
F_3 ( V_2 , V_3 , V_57 ,
V_58 | ( V_12 -> V_37 & 0xffffff ) ) ;
break;
}
}
static void F_9 ( struct V_9 * V_10 ,
unsigned int V_3 )
{
struct V_11 * V_12 =
F_6 ( V_10 -> V_10 . V_12 ) ;
struct V_1 * V_2 = V_10 -> V_15 ;
T_1 V_59 = V_60 ;
T_1 V_61 ;
V_61 = F_1 ( V_2 , V_3 , V_62 ) ;
V_61 &= ~ V_63 ;
V_61 |= V_12 -> V_27 -> V_64 | V_65 ;
F_8 ( V_10 , V_3 ) ;
if ( V_12 -> V_27 -> V_28 == 2 ) {
if ( V_12 -> V_18 != V_3 ) {
if ( V_12 -> V_27 -> V_39 == V_66 ||
V_12 -> V_27 -> V_39 == V_67 )
V_59 |= V_68 ;
if ( V_12 -> V_27 -> V_39 == V_67 )
V_59 |= V_69 ;
V_59 |= V_70 ;
} else {
V_59 |= V_71 ;
}
}
F_3 ( V_2 , V_3 , V_72 , V_59 ) ;
F_3 ( V_2 , V_3 , V_62 , V_61 ) ;
F_3 ( V_2 , V_3 , V_73 , V_10 -> V_10 . V_12 -> V_74 ) ;
F_3 ( V_2 , V_3 , V_75 , V_10 -> V_10 . V_12 -> V_76 ) ;
F_3 ( V_2 , V_3 , V_77 , V_10 -> V_10 . V_12 -> V_78 ) ;
F_3 ( V_2 , V_3 , V_79 , V_10 -> V_10 . V_12 -> V_80 ) ;
F_3 ( V_2 , V_3 , V_81 , 0 ) ;
F_3 ( V_2 , V_3 , V_82 , 4095 ) ;
F_3 ( V_2 , V_3 , V_83 , 0 ) ;
F_3 ( V_2 , V_3 , V_84 , 0 ) ;
}
void F_10 ( struct V_9 * V_10 )
{
struct V_11 * V_12 =
F_6 ( V_10 -> V_10 . V_12 ) ;
F_9 ( V_10 , V_12 -> V_18 ) ;
if ( V_12 -> V_27 -> V_28 == 2 )
F_9 ( V_10 , ( V_12 -> V_18 + 1 ) % 8 ) ;
F_5 ( V_10 ) ;
}
static int F_11 ( struct V_85 * V_10 ,
struct V_86 * V_12 )
{
struct V_11 * V_87 = F_6 ( V_12 ) ;
struct V_9 * V_88 = F_12 ( V_10 ) ;
struct V_89 * V_90 = V_88 -> V_15 -> V_5 ;
if ( ! V_12 -> V_14 || ! V_12 -> V_23 ) {
V_87 -> V_27 = NULL ;
return 0 ;
}
if ( V_12 -> V_91 >> 16 != V_12 -> V_74 ||
V_12 -> V_92 >> 16 != V_12 -> V_76 ) {
F_13 ( V_90 -> V_5 , L_1 , V_93 ) ;
return - V_94 ;
}
V_87 -> V_27 = F_14 ( V_12 -> V_14 -> V_95 ) ;
if ( V_87 -> V_27 == NULL ) {
F_13 ( V_90 -> V_5 , L_2 , V_93 ,
V_12 -> V_14 -> V_95 ) ;
return - V_94 ;
}
return 0 ;
}
static void F_15 ( struct V_85 * V_10 ,
struct V_86 * V_96 )
{
struct V_9 * V_88 = F_12 ( V_10 ) ;
if ( V_10 -> V_12 -> V_23 )
F_10 ( V_88 ) ;
}
static void F_16 ( struct V_85 * V_10 )
{
struct V_11 * V_12 ;
if ( V_10 -> V_12 && V_10 -> V_12 -> V_14 )
F_17 ( V_10 -> V_12 -> V_14 ) ;
F_18 ( V_10 -> V_12 ) ;
V_10 -> V_12 = NULL ;
V_12 = F_19 ( sizeof( * V_12 ) , V_97 ) ;
if ( V_12 == NULL )
return;
V_12 -> V_18 = - 1 ;
V_12 -> V_44 = 255 ;
V_12 -> V_37 = V_47 ;
V_12 -> V_98 = V_10 -> type == V_99 ? 0 : 1 ;
V_10 -> V_12 = & V_12 -> V_12 ;
V_10 -> V_12 -> V_10 = V_10 ;
}
static struct V_86 *
F_20 ( struct V_85 * V_10 )
{
struct V_11 * V_12 ;
struct V_11 * V_100 ;
V_12 = F_6 ( V_10 -> V_12 ) ;
V_100 = F_21 ( V_12 , sizeof( * V_12 ) , V_97 ) ;
if ( V_100 == NULL )
return NULL ;
if ( V_100 -> V_12 . V_14 )
F_22 ( V_100 -> V_12 . V_14 ) ;
return & V_100 -> V_12 ;
}
static void F_23 ( struct V_85 * V_10 ,
struct V_86 * V_12 )
{
if ( V_12 -> V_14 )
F_17 ( V_12 -> V_14 ) ;
F_18 ( F_6 ( V_12 ) ) ;
}
static int F_24 ( struct V_85 * V_10 ,
struct V_86 * V_12 ,
struct V_101 * V_102 ,
T_2 V_103 )
{
struct V_11 * V_87 = F_6 ( V_12 ) ;
struct V_9 * V_88 = F_12 ( V_10 ) ;
struct V_1 * V_2 = V_88 -> V_15 ;
if ( V_102 == V_2 -> V_28 . V_44 )
V_87 -> V_44 = V_103 ;
else if ( V_102 == V_2 -> V_28 . V_37 )
V_87 -> V_37 = V_103 ;
else if ( V_102 == V_2 -> V_28 . V_98 )
V_87 -> V_98 = V_103 ;
else
return - V_94 ;
return 0 ;
}
static int F_25 ( struct V_85 * V_10 ,
const struct V_86 * V_12 , struct V_101 * V_102 ,
T_2 * V_103 )
{
const struct V_11 * V_87 =
F_26 ( V_12 , const struct V_11 , V_12 ) ;
struct V_9 * V_88 = F_12 ( V_10 ) ;
struct V_1 * V_2 = V_88 -> V_15 ;
if ( V_102 == V_2 -> V_28 . V_44 )
* V_103 = V_87 -> V_44 ;
else if ( V_102 == V_2 -> V_28 . V_37 )
* V_103 = V_87 -> V_37 ;
else if ( V_102 == V_2 -> V_28 . V_98 )
* V_103 = V_87 -> V_98 ;
else
return - V_94 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_104 * V_28 = & V_2 -> V_28 ;
struct V_89 * V_90 = V_2 -> V_5 ;
unsigned int V_105 ;
unsigned int V_106 ;
unsigned int V_107 ;
unsigned int V_108 ;
int V_109 ;
V_28 -> V_44 =
F_28 ( V_90 -> V_110 , 0 , L_3 , 0 , 255 ) ;
if ( V_28 -> V_44 == NULL )
return - V_111 ;
V_28 -> V_37 =
F_28 ( V_90 -> V_110 , 0 , L_4 ,
0 , 0x01ffffff ) ;
if ( V_28 -> V_37 == NULL )
return - V_111 ;
V_28 -> V_98 =
F_28 ( V_90 -> V_110 , 0 , L_5 , 1 , 7 ) ;
if ( V_28 -> V_98 == NULL )
return - V_111 ;
V_106 = F_29 ( V_90 -> V_106 - 2 * V_2 -> V_3 , 2U ) ;
V_105 = V_106 + 7 ;
V_107 = ( ( 1 << V_90 -> V_106 ) - 1 ) & ( 3 << ( 2 * V_2 -> V_3 ) ) ;
for ( V_108 = 0 ; V_108 < V_105 ; ++ V_108 ) {
enum V_112 type = V_108 < V_106
? V_99
: V_113 ;
struct V_9 * V_10 = & V_28 -> V_28 [ V_108 ] ;
V_10 -> V_15 = V_2 ;
V_109 = F_30 ( V_90 -> V_110 , & V_10 -> V_10 , V_107 ,
& V_114 , V_115 ,
F_31 ( V_115 ) , type ) ;
if ( V_109 < 0 )
return V_109 ;
F_32 ( & V_10 -> V_10 ,
& V_116 ) ;
if ( type == V_99 )
continue;
F_33 ( & V_10 -> V_10 . V_117 ,
V_28 -> V_44 , 255 ) ;
F_33 ( & V_10 -> V_10 . V_117 ,
V_28 -> V_37 ,
V_47 ) ;
F_33 ( & V_10 -> V_10 . V_117 ,
V_28 -> V_98 , 1 ) ;
}
return 0 ;
}
