static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_4 , V_3 ) -> V_5 ;
}
static T_1 F_3 ( struct V_6 * V_7 ,
unsigned int V_8 , T_1 V_9 )
{
return F_4 ( V_7 -> V_10 ,
V_7 -> V_11 + V_8 * V_12 + V_9 ) ;
}
static void F_5 ( struct V_6 * V_7 ,
unsigned int V_8 , T_1 V_9 , T_1 V_13 )
{
F_6 ( V_7 -> V_10 , V_7 -> V_11 + V_8 * V_12 + V_9 ,
V_13 ) ;
}
int F_7 ( struct V_1 * V_3 ,
const struct V_14 * V_15 )
{
struct V_6 * V_7 = V_3 -> V_16 ;
unsigned int V_17 ;
int V_18 = - V_19 ;
F_8 ( & V_7 -> V_20 . V_21 ) ;
for ( V_17 = 0 ; V_17 < F_9 ( V_7 -> V_20 . V_20 ) ; ++ V_17 ) {
if ( ! ( V_7 -> V_20 . free & ( 1 << V_17 ) ) )
continue;
if ( V_15 -> V_20 == 1 ||
V_7 -> V_20 . free & ( 1 << ( ( V_17 + 1 ) % 8 ) ) )
break;
}
if ( V_17 == F_9 ( V_7 -> V_20 . V_20 ) )
goto V_22;
V_7 -> V_20 . free &= ~ ( 1 << V_17 ) ;
if ( V_15 -> V_20 == 2 )
V_7 -> V_20 . free &= ~ ( 1 << ( ( V_17 + 1 ) % 8 ) ) ;
V_3 -> V_23 = V_17 ;
V_18 = 0 ;
V_22:
F_10 ( & V_7 -> V_20 . V_21 ) ;
return V_18 ;
}
void F_11 ( struct V_1 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_16 ;
if ( V_3 -> V_23 == - 1 )
return;
F_8 ( & V_7 -> V_20 . V_21 ) ;
V_7 -> V_20 . free |= 1 << V_3 -> V_23 ;
if ( V_3 -> V_15 -> V_20 == 2 )
V_7 -> V_20 . free |= 1 << ( ( V_3 -> V_23 + 1 ) % 8 ) ;
F_10 ( & V_7 -> V_20 . V_21 ) ;
V_3 -> V_23 = - 1 ;
}
void F_12 ( struct V_1 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_16 ;
unsigned int V_8 = V_3 -> V_23 ;
F_5 ( V_7 , V_8 , V_24 , V_3 -> V_25 ) ;
F_5 ( V_7 , V_8 , V_26 , V_3 -> V_27 *
( V_3 -> V_15 -> V_28 == 32 ? 2 : 1 ) ) ;
F_5 ( V_7 , V_8 , V_29 , V_3 -> V_30 [ 0 ] ) ;
if ( V_3 -> V_15 -> V_20 == 2 ) {
V_8 = ( V_8 + 1 ) % 8 ;
F_5 ( V_7 , V_8 , V_24 , V_3 -> V_25 ) ;
F_5 ( V_7 , V_8 , V_26 , V_3 -> V_27 *
( V_3 -> V_15 -> V_28 == 16 ? 2 : 1 ) / 2 ) ;
F_5 ( V_7 , V_8 , V_29 , V_3 -> V_30 [ 1 ] ) ;
}
}
void F_13 ( struct V_1 * V_3 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 ;
V_34 = F_14 ( V_32 , 0 ) ;
V_3 -> V_30 [ 0 ] = V_34 -> V_35 + V_32 -> V_36 [ 0 ] ;
if ( V_3 -> V_15 -> V_20 == 2 ) {
V_34 = F_14 ( V_32 , 1 ) ;
V_3 -> V_30 [ 1 ] = V_34 -> V_35 + V_32 -> V_36 [ 1 ] ;
}
}
static void F_15 ( struct V_1 * V_3 ,
unsigned int V_8 )
{
struct V_6 * V_7 = V_3 -> V_16 ;
T_1 V_37 ;
T_1 V_38 ;
if ( V_3 -> V_15 -> V_39 != V_40 )
F_5 ( V_7 , V_8 , V_41 , V_42 ) ;
else
F_5 ( V_7 , V_8 , V_41 ,
V_43 | V_3 -> V_44 ) ;
V_38 = V_45 | V_3 -> V_15 -> V_38 ;
if ( ( V_3 -> V_37 & V_46 ) == V_47 )
V_38 |= V_48 ;
if ( V_3 -> V_15 -> V_39 == V_49 )
V_38 |= V_50 ;
F_5 ( V_7 , V_8 , V_51 , V_38 ) ;
switch ( V_3 -> V_15 -> V_39 ) {
case V_52 :
V_37 = ( ( V_3 -> V_37 & 0xf80000 ) >> 8 )
| ( ( V_3 -> V_37 & 0x00fc00 ) >> 5 )
| ( ( V_3 -> V_37 & 0x0000f8 ) >> 3 ) ;
F_5 ( V_7 , V_8 , V_53 , V_37 ) ;
break;
case V_54 :
case V_40 :
V_37 = ( ( V_3 -> V_37 & 0xf80000 ) >> 9 )
| ( ( V_3 -> V_37 & 0x00f800 ) >> 6 )
| ( ( V_3 -> V_37 & 0x0000f8 ) >> 3 ) ;
F_5 ( V_7 , V_8 , V_53 , V_37 ) ;
break;
case V_55 :
case V_56 :
F_5 ( V_7 , V_8 , V_57 ,
V_58 | ( V_3 -> V_37 & 0xffffff ) ) ;
break;
}
}
static void F_16 ( struct V_1 * V_3 ,
unsigned int V_8 )
{
struct V_6 * V_7 = V_3 -> V_16 ;
T_1 V_59 = V_60 ;
T_1 V_61 ;
T_1 V_62 ;
V_61 = F_3 ( V_7 , V_8 , V_63 ) ;
V_61 &= ~ V_64 ;
V_61 |= V_3 -> V_15 -> V_65 | V_66 ;
F_15 ( V_3 , V_8 ) ;
if ( V_3 -> V_15 -> V_20 == 2 ) {
if ( V_3 -> V_23 != V_8 ) {
if ( V_3 -> V_15 -> V_39 == V_67 ||
V_3 -> V_15 -> V_39 == V_68 )
V_59 |= V_69 ;
if ( V_3 -> V_15 -> V_39 == V_68 )
V_59 |= V_70 ;
V_59 |= V_71 ;
} else {
V_59 |= V_72 ;
}
}
F_5 ( V_7 , V_8 , V_73 , V_59 ) ;
F_5 ( V_7 , V_8 , V_63 , V_61 ) ;
if ( V_3 -> V_15 -> V_20 == 2 )
V_62 = V_3 -> V_74 ;
else
V_62 = V_3 -> V_74 * 8 / V_3 -> V_15 -> V_28 ;
F_5 ( V_7 , V_8 , V_75 , V_62 ) ;
F_5 ( V_7 , V_8 , V_76 , V_3 -> V_77 ) ;
F_5 ( V_7 , V_8 , V_78 , V_3 -> V_79 ) ;
F_5 ( V_7 , V_8 , V_80 , V_3 -> V_81 ) ;
F_5 ( V_7 , V_8 , V_82 , V_3 -> V_83 ) ;
F_5 ( V_7 , V_8 , V_84 , 0 ) ;
F_5 ( V_7 , V_8 , V_85 , 4095 ) ;
F_5 ( V_7 , V_8 , V_86 , 0 ) ;
F_5 ( V_7 , V_8 , V_87 , 0 ) ;
}
void F_17 ( struct V_1 * V_3 )
{
F_16 ( V_3 , V_3 -> V_23 ) ;
if ( V_3 -> V_15 -> V_20 == 2 )
F_16 ( V_3 , ( V_3 -> V_23 + 1 ) % 8 ) ;
F_12 ( V_3 ) ;
}
static int
F_18 ( struct V_2 * V_3 , struct V_88 * V_89 ,
struct V_31 * V_32 , int V_90 , int V_91 ,
unsigned int V_92 , unsigned int V_93 ,
T_2 V_25 , T_2 V_27 ,
T_2 V_94 , T_2 V_95 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
struct V_97 * V_98 = V_96 -> V_16 -> V_10 ;
const struct V_14 * V_15 ;
unsigned int V_99 ;
int V_18 ;
V_15 = V_14 ( V_32 -> V_100 ) ;
if ( V_15 == NULL ) {
F_19 ( V_98 -> V_10 , L_1 , V_101 ,
V_32 -> V_100 ) ;
return - V_102 ;
}
if ( V_94 >> 16 != V_92 || V_95 >> 16 != V_93 ) {
F_19 ( V_98 -> V_10 , L_2 , V_101 ) ;
return - V_102 ;
}
V_99 = V_96 -> V_15 ? V_96 -> V_15 -> V_20 : 0 ;
if ( V_15 -> V_20 != V_99 ) {
F_11 ( V_96 ) ;
V_18 = F_7 ( V_96 , V_15 ) ;
if ( V_18 < 0 )
return V_18 ;
}
V_96 -> V_89 = V_89 ;
V_96 -> V_15 = V_15 ;
V_96 -> V_74 = V_32 -> V_103 [ 0 ] ;
V_96 -> V_25 = V_25 >> 16 ;
V_96 -> V_27 = V_27 >> 16 ;
V_96 -> V_81 = V_90 ;
V_96 -> V_83 = V_91 ;
V_96 -> V_77 = V_92 ;
V_96 -> V_79 = V_93 ;
F_13 ( V_96 , V_32 ) ;
F_17 ( V_96 ) ;
F_8 ( & V_96 -> V_16 -> V_20 . V_21 ) ;
V_96 -> V_104 = true ;
F_20 ( V_96 -> V_89 ) ;
F_10 ( & V_96 -> V_16 -> V_20 . V_21 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
if ( ! V_96 -> V_104 )
return 0 ;
F_8 ( & V_96 -> V_16 -> V_20 . V_21 ) ;
V_96 -> V_104 = false ;
F_20 ( V_96 -> V_89 ) ;
F_10 ( & V_96 -> V_16 -> V_20 . V_21 ) ;
F_11 ( V_96 ) ;
V_96 -> V_89 = NULL ;
V_96 -> V_15 = NULL ;
return 0 ;
}
static void F_22 ( struct V_1 * V_3 , T_1 V_44 )
{
if ( V_3 -> V_44 == V_44 )
return;
V_3 -> V_44 = V_44 ;
if ( ! V_3 -> V_104 || V_3 -> V_15 -> V_39 != V_40 )
return;
F_15 ( V_3 , V_3 -> V_23 ) ;
}
static void F_23 ( struct V_1 * V_3 ,
T_1 V_37 )
{
if ( V_3 -> V_37 == V_37 )
return;
V_3 -> V_37 = V_37 ;
if ( ! V_3 -> V_104 )
return;
F_15 ( V_3 , V_3 -> V_23 ) ;
}
static void F_24 ( struct V_1 * V_3 ,
unsigned int V_105 )
{
F_8 ( & V_3 -> V_16 -> V_20 . V_21 ) ;
if ( V_3 -> V_105 == V_105 )
goto V_22;
V_3 -> V_105 = V_105 ;
if ( ! V_3 -> V_104 )
goto V_22;
F_20 ( V_3 -> V_89 ) ;
V_22:
F_10 ( & V_3 -> V_16 -> V_20 . V_21 ) ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_106 * V_107 ,
T_3 V_108 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_96 -> V_16 ;
if ( V_107 == V_7 -> V_20 . V_44 )
F_22 ( V_96 , V_108 ) ;
else if ( V_107 == V_7 -> V_20 . V_37 )
F_23 ( V_96 , V_108 ) ;
else if ( V_107 == V_7 -> V_20 . V_105 )
F_24 ( V_96 , V_108 ) ;
else
return - V_102 ;
return 0 ;
}
int F_26 ( struct V_6 * V_7 )
{
struct V_109 * V_20 = & V_7 -> V_20 ;
struct V_97 * V_98 = V_7 -> V_10 ;
unsigned int V_17 ;
F_27 ( & V_20 -> V_21 ) ;
V_20 -> free = 0xff ;
V_20 -> V_44 =
F_28 ( V_98 -> V_110 , 0 , L_3 , 0 , 255 ) ;
if ( V_20 -> V_44 == NULL )
return - V_111 ;
V_20 -> V_37 =
F_28 ( V_98 -> V_110 , 0 , L_4 ,
0 , 0x01ffffff ) ;
if ( V_20 -> V_37 == NULL )
return - V_111 ;
V_20 -> V_105 =
F_28 ( V_98 -> V_110 , 0 , L_5 , 1 , 7 ) ;
if ( V_20 -> V_105 == NULL )
return - V_111 ;
for ( V_17 = 0 ; V_17 < F_9 ( V_20 -> V_20 ) ; ++ V_17 ) {
struct V_1 * V_3 = & V_20 -> V_20 [ V_17 ] ;
V_3 -> V_16 = V_7 ;
V_3 -> V_23 = - 1 ;
V_3 -> V_44 = 255 ;
V_3 -> V_37 = V_47 ;
V_3 -> V_105 = 0 ;
}
return 0 ;
}
int F_29 ( struct V_6 * V_7 )
{
struct V_109 * V_20 = & V_7 -> V_20 ;
struct V_97 * V_98 = V_7 -> V_10 ;
unsigned int V_112 ;
unsigned int V_17 ;
int V_18 ;
V_112 = ( ( 1 << V_98 -> V_113 ) - 1 ) & ( 3 << ( 2 * V_7 -> V_8 ) ) ;
for ( V_17 = 0 ; V_17 < V_114 ; ++ V_17 ) {
struct V_4 * V_3 ;
V_3 = F_30 ( V_98 -> V_10 , sizeof( * V_3 ) , V_115 ) ;
if ( V_3 == NULL )
return - V_111 ;
V_3 -> V_5 = & V_20 -> V_20 [ V_17 + 2 ] ;
V_3 -> V_5 -> V_105 = 1 ;
V_18 = F_31 ( V_98 -> V_110 , & V_3 -> V_3 , V_112 ,
& V_116 , V_117 ,
F_9 ( V_117 ) , false ) ;
if ( V_18 < 0 )
return V_18 ;
F_32 ( & V_3 -> V_3 . V_118 ,
V_20 -> V_44 , 255 ) ;
F_32 ( & V_3 -> V_3 . V_118 ,
V_20 -> V_37 ,
V_47 ) ;
F_32 ( & V_3 -> V_3 . V_118 ,
V_20 -> V_105 , 1 ) ;
}
return 0 ;
}
