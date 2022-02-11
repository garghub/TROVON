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
T_1 V_24 ;
if ( V_3 -> V_15 -> V_20 == 2 )
V_24 = V_3 -> V_25 ;
else
V_24 = V_3 -> V_25 * 8 / V_3 -> V_15 -> V_26 ;
F_5 ( V_7 , V_8 , V_27 , V_24 ) ;
F_5 ( V_7 , V_8 , V_28 , V_3 -> V_29 ) ;
F_5 ( V_7 , V_8 , V_30 , V_3 -> V_31 *
( V_3 -> V_15 -> V_26 == 32 ? 2 : 1 ) ) ;
F_5 ( V_7 , V_8 , V_32 , V_3 -> V_33 [ 0 ] ) ;
if ( V_3 -> V_15 -> V_20 == 2 ) {
V_8 = ( V_8 + 1 ) % 8 ;
F_5 ( V_7 , V_8 , V_28 , V_3 -> V_29 ) ;
F_5 ( V_7 , V_8 , V_30 , V_3 -> V_31 *
( V_3 -> V_15 -> V_26 == 16 ? 2 : 1 ) / 2 ) ;
F_5 ( V_7 , V_8 , V_32 , V_3 -> V_33 [ 1 ] ) ;
}
}
void F_13 ( struct V_1 * V_3 ,
struct V_34 * V_35 )
{
struct V_36 * V_37 ;
V_3 -> V_25 = V_35 -> V_38 [ 0 ] ;
V_37 = F_14 ( V_35 , 0 ) ;
V_3 -> V_33 [ 0 ] = V_37 -> V_39 + V_35 -> V_40 [ 0 ] ;
if ( V_3 -> V_15 -> V_20 == 2 ) {
V_37 = F_14 ( V_35 , 1 ) ;
V_3 -> V_33 [ 1 ] = V_37 -> V_39 + V_35 -> V_40 [ 1 ] ;
}
}
static void F_15 ( struct V_1 * V_3 ,
unsigned int V_8 )
{
struct V_6 * V_7 = V_3 -> V_16 ;
T_1 V_41 ;
T_1 V_42 ;
if ( V_3 -> V_15 -> V_43 != V_44 )
F_5 ( V_7 , V_8 , V_45 , V_46 ) ;
else
F_5 ( V_7 , V_8 , V_45 ,
V_47 | V_3 -> V_48 ) ;
V_42 = V_49 | V_3 -> V_15 -> V_42 ;
if ( ( V_3 -> V_41 & V_50 ) == V_51 )
V_42 |= V_52 ;
if ( V_3 -> V_15 -> V_43 == V_53 )
V_42 |= V_54 ;
F_5 ( V_7 , V_8 , V_55 , V_42 ) ;
switch ( V_3 -> V_15 -> V_43 ) {
case V_56 :
V_41 = ( ( V_3 -> V_41 & 0xf80000 ) >> 8 )
| ( ( V_3 -> V_41 & 0x00fc00 ) >> 5 )
| ( ( V_3 -> V_41 & 0x0000f8 ) >> 3 ) ;
F_5 ( V_7 , V_8 , V_57 , V_41 ) ;
break;
case V_58 :
case V_44 :
V_41 = ( ( V_3 -> V_41 & 0xf80000 ) >> 9 )
| ( ( V_3 -> V_41 & 0x00f800 ) >> 6 )
| ( ( V_3 -> V_41 & 0x0000f8 ) >> 3 ) ;
F_5 ( V_7 , V_8 , V_57 , V_41 ) ;
break;
case V_59 :
case V_60 :
F_5 ( V_7 , V_8 , V_61 ,
V_62 | ( V_3 -> V_41 & 0xffffff ) ) ;
break;
}
}
static void F_16 ( struct V_1 * V_3 ,
unsigned int V_8 )
{
struct V_6 * V_7 = V_3 -> V_16 ;
T_1 V_63 = V_64 ;
T_1 V_65 ;
V_65 = F_3 ( V_7 , V_8 , V_66 ) ;
V_65 &= ~ V_67 ;
V_65 |= V_3 -> V_15 -> V_68 | V_69 ;
F_15 ( V_3 , V_8 ) ;
if ( V_3 -> V_15 -> V_20 == 2 ) {
if ( V_3 -> V_23 != V_8 ) {
if ( V_3 -> V_15 -> V_43 == V_70 ||
V_3 -> V_15 -> V_43 == V_71 )
V_63 |= V_72 ;
if ( V_3 -> V_15 -> V_43 == V_71 )
V_63 |= V_73 ;
V_63 |= V_74 ;
} else {
V_63 |= V_75 ;
}
}
F_5 ( V_7 , V_8 , V_76 , V_63 ) ;
F_5 ( V_7 , V_8 , V_66 , V_65 ) ;
F_5 ( V_7 , V_8 , V_77 , V_3 -> V_78 ) ;
F_5 ( V_7 , V_8 , V_79 , V_3 -> V_80 ) ;
F_5 ( V_7 , V_8 , V_81 , V_3 -> V_82 ) ;
F_5 ( V_7 , V_8 , V_83 , V_3 -> V_84 ) ;
F_5 ( V_7 , V_8 , V_85 , 0 ) ;
F_5 ( V_7 , V_8 , V_86 , 4095 ) ;
F_5 ( V_7 , V_8 , V_87 , 0 ) ;
F_5 ( V_7 , V_8 , V_88 , 0 ) ;
}
void F_17 ( struct V_1 * V_3 )
{
F_16 ( V_3 , V_3 -> V_23 ) ;
if ( V_3 -> V_15 -> V_20 == 2 )
F_16 ( V_3 , ( V_3 -> V_23 + 1 ) % 8 ) ;
F_12 ( V_3 ) ;
}
static int
F_18 ( struct V_2 * V_3 , struct V_89 * V_90 ,
struct V_34 * V_35 , int V_91 , int V_92 ,
unsigned int V_93 , unsigned int V_94 ,
T_2 V_29 , T_2 V_31 ,
T_2 V_95 , T_2 V_96 )
{
struct V_1 * V_97 = F_1 ( V_3 ) ;
struct V_98 * V_99 = V_97 -> V_16 -> V_10 ;
const struct V_14 * V_15 ;
unsigned int V_100 ;
int V_18 ;
V_15 = V_14 ( V_35 -> V_101 ) ;
if ( V_15 == NULL ) {
F_19 ( V_99 -> V_10 , L_1 , V_102 ,
V_35 -> V_101 ) ;
return - V_103 ;
}
if ( V_95 >> 16 != V_93 || V_96 >> 16 != V_94 ) {
F_19 ( V_99 -> V_10 , L_2 , V_102 ) ;
return - V_103 ;
}
V_100 = V_97 -> V_15 ? V_97 -> V_15 -> V_20 : 0 ;
if ( V_15 -> V_20 != V_100 ) {
F_11 ( V_97 ) ;
V_18 = F_7 ( V_97 , V_15 ) ;
if ( V_18 < 0 )
return V_18 ;
}
V_97 -> V_90 = V_90 ;
V_97 -> V_15 = V_15 ;
V_97 -> V_29 = V_29 >> 16 ;
V_97 -> V_31 = V_31 >> 16 ;
V_97 -> V_82 = V_91 ;
V_97 -> V_84 = V_92 ;
V_97 -> V_78 = V_93 ;
V_97 -> V_80 = V_94 ;
F_13 ( V_97 , V_35 ) ;
F_17 ( V_97 ) ;
F_8 ( & V_97 -> V_16 -> V_20 . V_21 ) ;
V_97 -> V_104 = true ;
F_20 ( V_97 -> V_90 ) ;
F_10 ( & V_97 -> V_16 -> V_20 . V_21 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_97 = F_1 ( V_3 ) ;
if ( ! V_97 -> V_104 )
return 0 ;
F_8 ( & V_97 -> V_16 -> V_20 . V_21 ) ;
V_97 -> V_104 = false ;
F_20 ( V_97 -> V_90 ) ;
F_10 ( & V_97 -> V_16 -> V_20 . V_21 ) ;
F_11 ( V_97 ) ;
V_97 -> V_90 = NULL ;
V_97 -> V_15 = NULL ;
return 0 ;
}
static void F_22 ( struct V_1 * V_3 , T_1 V_48 )
{
if ( V_3 -> V_48 == V_48 )
return;
V_3 -> V_48 = V_48 ;
if ( ! V_3 -> V_104 || V_3 -> V_15 -> V_43 != V_44 )
return;
F_15 ( V_3 , V_3 -> V_23 ) ;
}
static void F_23 ( struct V_1 * V_3 ,
T_1 V_41 )
{
if ( V_3 -> V_41 == V_41 )
return;
V_3 -> V_41 = V_41 ;
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
F_20 ( V_3 -> V_90 ) ;
V_22:
F_10 ( & V_3 -> V_16 -> V_20 . V_21 ) ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_106 * V_107 ,
T_3 V_108 )
{
struct V_1 * V_97 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_97 -> V_16 ;
if ( V_107 == V_7 -> V_20 . V_48 )
F_22 ( V_97 , V_108 ) ;
else if ( V_107 == V_7 -> V_20 . V_41 )
F_23 ( V_97 , V_108 ) ;
else if ( V_107 == V_7 -> V_20 . V_105 )
F_24 ( V_97 , V_108 ) ;
else
return - V_103 ;
return 0 ;
}
int F_26 ( struct V_6 * V_7 )
{
struct V_109 * V_20 = & V_7 -> V_20 ;
struct V_98 * V_99 = V_7 -> V_10 ;
unsigned int V_17 ;
F_27 ( & V_20 -> V_21 ) ;
V_20 -> free = 0xff ;
V_20 -> V_48 =
F_28 ( V_99 -> V_110 , 0 , L_3 , 0 , 255 ) ;
if ( V_20 -> V_48 == NULL )
return - V_111 ;
V_20 -> V_41 =
F_28 ( V_99 -> V_110 , 0 , L_4 ,
0 , 0x01ffffff ) ;
if ( V_20 -> V_41 == NULL )
return - V_111 ;
V_20 -> V_105 =
F_28 ( V_99 -> V_110 , 0 , L_5 , 1 , 7 ) ;
if ( V_20 -> V_105 == NULL )
return - V_111 ;
for ( V_17 = 0 ; V_17 < F_9 ( V_20 -> V_20 ) ; ++ V_17 ) {
struct V_1 * V_3 = & V_20 -> V_20 [ V_17 ] ;
V_3 -> V_16 = V_7 ;
V_3 -> V_23 = - 1 ;
V_3 -> V_48 = 255 ;
V_3 -> V_41 = V_51 ;
V_3 -> V_105 = 0 ;
}
return 0 ;
}
int F_29 ( struct V_6 * V_7 )
{
struct V_109 * V_20 = & V_7 -> V_20 ;
struct V_98 * V_99 = V_7 -> V_10 ;
unsigned int V_112 ;
unsigned int V_17 ;
int V_18 ;
V_112 = ( ( 1 << V_99 -> V_113 ) - 1 ) & ( 3 << ( 2 * V_7 -> V_8 ) ) ;
for ( V_17 = 0 ; V_17 < V_114 ; ++ V_17 ) {
struct V_4 * V_3 ;
V_3 = F_30 ( V_99 -> V_10 , sizeof( * V_3 ) , V_115 ) ;
if ( V_3 == NULL )
return - V_111 ;
V_3 -> V_5 = & V_20 -> V_20 [ V_17 + 2 ] ;
V_3 -> V_5 -> V_105 = 1 ;
V_18 = F_31 ( V_99 -> V_110 , & V_3 -> V_3 , V_112 ,
& V_116 , V_117 ,
F_9 ( V_117 ) , false ) ;
if ( V_18 < 0 )
return V_18 ;
F_32 ( & V_3 -> V_3 . V_118 ,
V_20 -> V_48 , 255 ) ;
F_32 ( & V_3 -> V_3 . V_118 ,
V_20 -> V_41 ,
V_51 ) ;
F_32 ( & V_3 -> V_3 . V_118 ,
V_20 -> V_105 , 1 ) ;
}
return 0 ;
}
