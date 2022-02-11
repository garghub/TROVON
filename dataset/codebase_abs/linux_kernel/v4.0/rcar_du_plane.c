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
bool V_24 ;
T_1 V_25 ;
V_24 = V_3 -> V_26 -> V_27 . V_28 & V_29 ;
if ( V_3 -> V_15 -> V_20 == 2 )
V_25 = V_3 -> V_30 ;
else
V_25 = V_3 -> V_30 * 8 / V_3 -> V_15 -> V_31 ;
if ( V_24 && V_3 -> V_15 -> V_31 == 32 )
V_25 *= 2 ;
F_5 ( V_7 , V_8 , V_32 , V_25 ) ;
F_5 ( V_7 , V_8 , V_33 , V_3 -> V_34 ) ;
F_5 ( V_7 , V_8 , V_35 , V_3 -> V_36 *
( ! V_24 && V_3 -> V_15 -> V_31 == 32 ? 2 : 1 ) ) ;
F_5 ( V_7 , V_8 , V_37 , V_3 -> V_38 [ 0 ] ) ;
if ( V_3 -> V_15 -> V_20 == 2 ) {
V_8 = ( V_8 + 1 ) % 8 ;
F_5 ( V_7 , V_8 , V_32 , V_3 -> V_30 ) ;
F_5 ( V_7 , V_8 , V_33 , V_3 -> V_34 ) ;
F_5 ( V_7 , V_8 , V_35 , V_3 -> V_36 *
( V_3 -> V_15 -> V_31 == 16 ? 2 : 1 ) / 2 ) ;
F_5 ( V_7 , V_8 , V_37 , V_3 -> V_38 [ 1 ] ) ;
}
}
void F_13 ( struct V_1 * V_3 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 ;
V_3 -> V_30 = V_40 -> V_43 [ 0 ] ;
V_42 = F_14 ( V_40 , 0 ) ;
V_3 -> V_38 [ 0 ] = V_42 -> V_44 + V_40 -> V_45 [ 0 ] ;
if ( V_3 -> V_15 -> V_20 == 2 ) {
V_42 = F_14 ( V_40 , 1 ) ;
V_3 -> V_38 [ 1 ] = V_42 -> V_44 + V_40 -> V_45 [ 1 ] ;
}
}
static void F_15 ( struct V_1 * V_3 ,
unsigned int V_8 )
{
struct V_6 * V_7 = V_3 -> V_16 ;
T_1 V_46 ;
T_1 V_47 ;
if ( V_3 -> V_15 -> V_48 != V_49 )
F_5 ( V_7 , V_8 , V_50 , V_51 ) ;
else
F_5 ( V_7 , V_8 , V_50 ,
V_52 | V_3 -> V_53 ) ;
V_47 = V_54 | V_3 -> V_15 -> V_47 ;
if ( ( V_3 -> V_46 & V_55 ) == V_56 )
V_47 |= V_57 ;
if ( V_3 -> V_15 -> V_48 == V_58 )
V_47 |= V_59 ;
F_5 ( V_7 , V_8 , V_60 , V_47 ) ;
switch ( V_3 -> V_15 -> V_48 ) {
case V_61 :
V_46 = ( ( V_3 -> V_46 & 0xf80000 ) >> 8 )
| ( ( V_3 -> V_46 & 0x00fc00 ) >> 5 )
| ( ( V_3 -> V_46 & 0x0000f8 ) >> 3 ) ;
F_5 ( V_7 , V_8 , V_62 , V_46 ) ;
break;
case V_63 :
case V_49 :
V_46 = ( ( V_3 -> V_46 & 0xf80000 ) >> 9 )
| ( ( V_3 -> V_46 & 0x00f800 ) >> 6 )
| ( ( V_3 -> V_46 & 0x0000f8 ) >> 3 ) ;
F_5 ( V_7 , V_8 , V_62 , V_46 ) ;
break;
case V_64 :
case V_65 :
F_5 ( V_7 , V_8 , V_66 ,
V_67 | ( V_3 -> V_46 & 0xffffff ) ) ;
break;
}
}
static void F_16 ( struct V_1 * V_3 ,
unsigned int V_8 )
{
struct V_6 * V_7 = V_3 -> V_16 ;
T_1 V_68 = V_69 ;
T_1 V_70 ;
V_70 = F_3 ( V_7 , V_8 , V_71 ) ;
V_70 &= ~ V_72 ;
V_70 |= V_3 -> V_15 -> V_73 | V_74 ;
F_15 ( V_3 , V_8 ) ;
if ( V_3 -> V_15 -> V_20 == 2 ) {
if ( V_3 -> V_23 != V_8 ) {
if ( V_3 -> V_15 -> V_48 == V_75 ||
V_3 -> V_15 -> V_48 == V_76 )
V_68 |= V_77 ;
if ( V_3 -> V_15 -> V_48 == V_76 )
V_68 |= V_78 ;
V_68 |= V_79 ;
} else {
V_68 |= V_80 ;
}
}
F_5 ( V_7 , V_8 , V_81 , V_68 ) ;
F_5 ( V_7 , V_8 , V_71 , V_70 ) ;
F_5 ( V_7 , V_8 , V_82 , V_3 -> V_83 ) ;
F_5 ( V_7 , V_8 , V_84 , V_3 -> V_85 ) ;
F_5 ( V_7 , V_8 , V_86 , V_3 -> V_87 ) ;
F_5 ( V_7 , V_8 , V_88 , V_3 -> V_89 ) ;
F_5 ( V_7 , V_8 , V_90 , 0 ) ;
F_5 ( V_7 , V_8 , V_91 , 4095 ) ;
F_5 ( V_7 , V_8 , V_92 , 0 ) ;
F_5 ( V_7 , V_8 , V_93 , 0 ) ;
}
void F_17 ( struct V_1 * V_3 )
{
F_16 ( V_3 , V_3 -> V_23 ) ;
if ( V_3 -> V_15 -> V_20 == 2 )
F_16 ( V_3 , ( V_3 -> V_23 + 1 ) % 8 ) ;
F_12 ( V_3 ) ;
}
static int
F_18 ( struct V_2 * V_3 , struct V_94 * V_26 ,
struct V_39 * V_40 , int V_95 , int V_96 ,
unsigned int V_97 , unsigned int V_98 ,
T_2 V_34 , T_2 V_36 ,
T_2 V_99 , T_2 V_100 )
{
struct V_1 * V_101 = F_1 ( V_3 ) ;
struct V_102 * V_103 = V_101 -> V_16 -> V_10 ;
const struct V_14 * V_15 ;
unsigned int V_104 ;
int V_18 ;
V_15 = V_14 ( V_40 -> V_105 ) ;
if ( V_15 == NULL ) {
F_19 ( V_103 -> V_10 , L_1 , V_106 ,
V_40 -> V_105 ) ;
return - V_107 ;
}
if ( V_99 >> 16 != V_97 || V_100 >> 16 != V_98 ) {
F_19 ( V_103 -> V_10 , L_2 , V_106 ) ;
return - V_107 ;
}
V_104 = V_101 -> V_15 ? V_101 -> V_15 -> V_20 : 0 ;
if ( V_15 -> V_20 != V_104 ) {
F_11 ( V_101 ) ;
V_18 = F_7 ( V_101 , V_15 ) ;
if ( V_18 < 0 )
return V_18 ;
}
V_101 -> V_26 = V_26 ;
V_101 -> V_15 = V_15 ;
V_101 -> V_34 = V_34 >> 16 ;
V_101 -> V_36 = V_36 >> 16 ;
V_101 -> V_87 = V_95 ;
V_101 -> V_89 = V_96 ;
V_101 -> V_83 = V_97 ;
V_101 -> V_85 = V_98 ;
F_13 ( V_101 , V_40 ) ;
F_17 ( V_101 ) ;
F_8 ( & V_101 -> V_16 -> V_20 . V_21 ) ;
V_101 -> V_108 = true ;
F_20 ( V_101 -> V_26 ) ;
F_10 ( & V_101 -> V_16 -> V_20 . V_21 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_101 = F_1 ( V_3 ) ;
if ( ! V_101 -> V_108 )
return 0 ;
F_8 ( & V_101 -> V_16 -> V_20 . V_21 ) ;
V_101 -> V_108 = false ;
F_20 ( V_101 -> V_26 ) ;
F_10 ( & V_101 -> V_16 -> V_20 . V_21 ) ;
F_11 ( V_101 ) ;
V_101 -> V_26 = NULL ;
V_101 -> V_15 = NULL ;
return 0 ;
}
static void F_22 ( struct V_1 * V_3 , T_1 V_53 )
{
if ( V_3 -> V_53 == V_53 )
return;
V_3 -> V_53 = V_53 ;
if ( ! V_3 -> V_108 || V_3 -> V_15 -> V_48 != V_49 )
return;
F_15 ( V_3 , V_3 -> V_23 ) ;
}
static void F_23 ( struct V_1 * V_3 ,
T_1 V_46 )
{
if ( V_3 -> V_46 == V_46 )
return;
V_3 -> V_46 = V_46 ;
if ( ! V_3 -> V_108 )
return;
F_15 ( V_3 , V_3 -> V_23 ) ;
}
static void F_24 ( struct V_1 * V_3 ,
unsigned int V_109 )
{
F_8 ( & V_3 -> V_16 -> V_20 . V_21 ) ;
if ( V_3 -> V_109 == V_109 )
goto V_22;
V_3 -> V_109 = V_109 ;
if ( ! V_3 -> V_108 )
goto V_22;
F_20 ( V_3 -> V_26 ) ;
V_22:
F_10 ( & V_3 -> V_16 -> V_20 . V_21 ) ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_110 * V_111 ,
T_3 V_112 )
{
struct V_1 * V_101 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_101 -> V_16 ;
if ( V_111 == V_7 -> V_20 . V_53 )
F_22 ( V_101 , V_112 ) ;
else if ( V_111 == V_7 -> V_20 . V_46 )
F_23 ( V_101 , V_112 ) ;
else if ( V_111 == V_7 -> V_20 . V_109 )
F_24 ( V_101 , V_112 ) ;
else
return - V_107 ;
return 0 ;
}
int F_26 ( struct V_6 * V_7 )
{
struct V_113 * V_20 = & V_7 -> V_20 ;
struct V_102 * V_103 = V_7 -> V_10 ;
unsigned int V_17 ;
F_27 ( & V_20 -> V_21 ) ;
V_20 -> free = 0xff ;
V_20 -> V_53 =
F_28 ( V_103 -> V_114 , 0 , L_3 , 0 , 255 ) ;
if ( V_20 -> V_53 == NULL )
return - V_115 ;
V_20 -> V_46 =
F_28 ( V_103 -> V_114 , 0 , L_4 ,
0 , 0x01ffffff ) ;
if ( V_20 -> V_46 == NULL )
return - V_115 ;
V_20 -> V_109 =
F_28 ( V_103 -> V_114 , 0 , L_5 , 1 , 7 ) ;
if ( V_20 -> V_109 == NULL )
return - V_115 ;
for ( V_17 = 0 ; V_17 < F_9 ( V_20 -> V_20 ) ; ++ V_17 ) {
struct V_1 * V_3 = & V_20 -> V_20 [ V_17 ] ;
V_3 -> V_16 = V_7 ;
V_3 -> V_23 = - 1 ;
V_3 -> V_53 = 255 ;
V_3 -> V_46 = V_56 ;
V_3 -> V_109 = 0 ;
}
return 0 ;
}
int F_29 ( struct V_6 * V_7 )
{
struct V_113 * V_20 = & V_7 -> V_20 ;
struct V_102 * V_103 = V_7 -> V_10 ;
unsigned int V_116 ;
unsigned int V_17 ;
int V_18 ;
V_116 = ( ( 1 << V_103 -> V_117 ) - 1 ) & ( 3 << ( 2 * V_7 -> V_8 ) ) ;
for ( V_17 = 0 ; V_17 < V_118 ; ++ V_17 ) {
struct V_4 * V_3 ;
V_3 = F_30 ( V_103 -> V_10 , sizeof( * V_3 ) , V_119 ) ;
if ( V_3 == NULL )
return - V_115 ;
V_3 -> V_5 = & V_20 -> V_20 [ V_17 + 2 ] ;
V_3 -> V_5 -> V_109 = 1 ;
V_18 = F_31 ( V_103 -> V_114 , & V_3 -> V_3 , V_116 ,
& V_120 , V_121 ,
F_9 ( V_121 ) , false ) ;
if ( V_18 < 0 )
return V_18 ;
F_32 ( & V_3 -> V_3 . V_122 ,
V_20 -> V_53 , 255 ) ;
F_32 ( & V_3 -> V_3 . V_122 ,
V_20 -> V_46 ,
V_56 ) ;
F_32 ( & V_3 -> V_3 . V_122 ,
V_20 -> V_109 , 1 ) ;
}
return 0 ;
}
