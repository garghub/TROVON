static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_4 , V_3 ) -> V_5 ;
}
static T_1 F_3 ( struct V_6 * V_7 ,
unsigned int V_8 , T_1 V_9 )
{
return F_4 ( V_7 , V_8 * V_10 + V_9 ) ;
}
static void F_5 ( struct V_6 * V_7 ,
unsigned int V_8 , T_1 V_9 , T_1 V_11 )
{
F_6 ( V_7 , V_8 * V_10 + V_9 , V_11 ) ;
}
int F_7 ( struct V_1 * V_3 ,
const struct V_12 * V_13 )
{
struct V_6 * V_7 = V_3 -> V_14 ;
unsigned int V_15 ;
int V_16 = - V_17 ;
F_8 ( & V_7 -> V_18 . V_19 ) ;
for ( V_15 = 0 ; V_15 < F_9 ( V_7 -> V_18 . V_18 ) ; ++ V_15 ) {
if ( ! ( V_7 -> V_18 . free & ( 1 << V_15 ) ) )
continue;
if ( V_13 -> V_18 == 1 ||
V_7 -> V_18 . free & ( 1 << ( ( V_15 + 1 ) % 8 ) ) )
break;
}
if ( V_15 == F_9 ( V_7 -> V_18 . V_18 ) )
goto V_20;
V_7 -> V_18 . free &= ~ ( 1 << V_15 ) ;
if ( V_13 -> V_18 == 2 )
V_7 -> V_18 . free &= ~ ( 1 << ( ( V_15 + 1 ) % 8 ) ) ;
V_3 -> V_21 = V_15 ;
V_16 = 0 ;
V_20:
F_10 ( & V_7 -> V_18 . V_19 ) ;
return V_16 ;
}
void F_11 ( struct V_1 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_14 ;
if ( V_3 -> V_21 == - 1 )
return;
F_8 ( & V_7 -> V_18 . V_19 ) ;
V_7 -> V_18 . free |= 1 << V_3 -> V_21 ;
if ( V_3 -> V_13 -> V_18 == 2 )
V_7 -> V_18 . free |= 1 << ( ( V_3 -> V_21 + 1 ) % 8 ) ;
F_10 ( & V_7 -> V_18 . V_19 ) ;
V_3 -> V_21 = - 1 ;
}
void F_12 ( struct V_1 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_14 ;
unsigned int V_8 = V_3 -> V_21 ;
F_5 ( V_7 , V_8 , V_22 , V_3 -> V_23 ) ;
F_5 ( V_7 , V_8 , V_24 , V_3 -> V_25 *
( V_3 -> V_13 -> V_26 == 32 ? 2 : 1 ) ) ;
F_5 ( V_7 , V_8 , V_27 , V_3 -> V_28 [ 0 ] ) ;
if ( V_3 -> V_13 -> V_18 == 2 ) {
V_8 = ( V_8 + 1 ) % 8 ;
F_5 ( V_7 , V_8 , V_22 , V_3 -> V_23 ) ;
F_5 ( V_7 , V_8 , V_24 , V_3 -> V_25 *
( V_3 -> V_13 -> V_26 == 16 ? 2 : 1 ) / 2 ) ;
F_5 ( V_7 , V_8 , V_27 , V_3 -> V_28 [ 1 ] ) ;
}
}
void F_13 ( struct V_1 * V_3 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 ;
V_32 = F_14 ( V_30 , 0 ) ;
V_3 -> V_28 [ 0 ] = V_32 -> V_33 + V_30 -> V_34 [ 0 ] ;
if ( V_3 -> V_13 -> V_18 == 2 ) {
V_32 = F_14 ( V_30 , 1 ) ;
V_3 -> V_28 [ 1 ] = V_32 -> V_33 + V_30 -> V_34 [ 1 ] ;
}
}
static void F_15 ( struct V_1 * V_3 ,
unsigned int V_8 )
{
struct V_6 * V_7 = V_3 -> V_14 ;
T_1 V_35 ;
T_1 V_36 ;
if ( V_3 -> V_13 -> V_37 != V_38 )
F_5 ( V_7 , V_8 , V_39 , V_40 ) ;
else
F_5 ( V_7 , V_8 , V_39 ,
V_41 | V_3 -> V_42 ) ;
V_36 = V_43 | V_3 -> V_13 -> V_36 ;
if ( ( V_3 -> V_35 & V_44 ) == V_45 )
V_36 |= V_46 ;
if ( V_3 -> V_13 -> V_37 == V_47 )
V_36 |= V_48 ;
F_5 ( V_7 , V_8 , V_49 , V_36 ) ;
switch ( V_3 -> V_13 -> V_37 ) {
case V_50 :
V_35 = ( ( V_3 -> V_35 & 0xf80000 ) >> 8 )
| ( ( V_3 -> V_35 & 0x00fc00 ) >> 5 )
| ( ( V_3 -> V_35 & 0x0000f8 ) >> 3 ) ;
F_5 ( V_7 , V_8 , V_51 , V_35 ) ;
break;
case V_52 :
case V_38 :
V_35 = ( ( V_3 -> V_35 & 0xf80000 ) >> 9 )
| ( ( V_3 -> V_35 & 0x00f800 ) >> 6 )
| ( ( V_3 -> V_35 & 0x0000f8 ) >> 3 ) ;
F_5 ( V_7 , V_8 , V_51 , V_35 ) ;
break;
case V_53 :
case V_54 :
F_5 ( V_7 , V_8 , V_55 ,
V_56 | ( V_3 -> V_35 & 0xffffff ) ) ;
break;
}
}
static void F_16 ( struct V_1 * V_3 ,
unsigned int V_8 )
{
struct V_6 * V_7 = V_3 -> V_14 ;
T_1 V_57 = V_58 ;
T_1 V_59 ;
T_1 V_60 ;
V_59 = F_3 ( V_7 , V_8 , V_61 ) ;
V_59 &= ~ V_62 ;
V_59 |= V_3 -> V_13 -> V_63 | V_64 ;
F_15 ( V_3 , V_8 ) ;
if ( V_3 -> V_13 -> V_18 == 2 ) {
if ( V_3 -> V_21 != V_8 ) {
if ( V_3 -> V_13 -> V_37 == V_65 ||
V_3 -> V_13 -> V_37 == V_66 )
V_57 |= V_67 ;
if ( V_3 -> V_13 -> V_37 == V_66 )
V_57 |= V_68 ;
V_57 |= V_69 ;
} else {
V_57 |= V_70 ;
}
}
F_5 ( V_7 , V_8 , V_71 , V_57 ) ;
F_5 ( V_7 , V_8 , V_61 , V_59 ) ;
if ( V_3 -> V_13 -> V_18 == 2 )
V_60 = V_3 -> V_72 ;
else
V_60 = V_3 -> V_72 * 8 / V_3 -> V_13 -> V_26 ;
F_5 ( V_7 , V_8 , V_73 , V_60 ) ;
F_5 ( V_7 , V_8 , V_74 , V_3 -> V_75 ) ;
F_5 ( V_7 , V_8 , V_76 , V_3 -> V_77 ) ;
F_5 ( V_7 , V_8 , V_78 , V_3 -> V_79 ) ;
F_5 ( V_7 , V_8 , V_80 , V_3 -> V_81 ) ;
F_5 ( V_7 , V_8 , V_82 , 0 ) ;
F_5 ( V_7 , V_8 , V_83 , 4095 ) ;
F_5 ( V_7 , V_8 , V_84 , 0 ) ;
F_5 ( V_7 , V_8 , V_85 , 0 ) ;
}
void F_17 ( struct V_1 * V_3 )
{
F_16 ( V_3 , V_3 -> V_21 ) ;
if ( V_3 -> V_13 -> V_18 == 2 )
F_16 ( V_3 , ( V_3 -> V_21 + 1 ) % 8 ) ;
F_12 ( V_3 ) ;
}
static int
F_18 ( struct V_2 * V_3 , struct V_86 * V_87 ,
struct V_29 * V_30 , int V_88 , int V_89 ,
unsigned int V_90 , unsigned int V_91 ,
T_2 V_23 , T_2 V_25 ,
T_2 V_92 , T_2 V_93 )
{
struct V_1 * V_94 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_3 -> V_14 -> V_95 ;
const struct V_12 * V_13 ;
unsigned int V_96 ;
int V_16 ;
V_13 = V_12 ( V_30 -> V_97 ) ;
if ( V_13 == NULL ) {
F_19 ( V_7 -> V_14 , L_1 , V_98 ,
V_30 -> V_97 ) ;
return - V_99 ;
}
if ( V_92 >> 16 != V_90 || V_93 >> 16 != V_91 ) {
F_19 ( V_7 -> V_14 , L_2 , V_98 ) ;
return - V_99 ;
}
V_96 = V_94 -> V_13 ? V_94 -> V_13 -> V_18 : 0 ;
if ( V_13 -> V_18 != V_96 ) {
F_11 ( V_94 ) ;
V_16 = F_7 ( V_94 , V_13 ) ;
if ( V_16 < 0 )
return V_16 ;
}
V_94 -> V_87 = V_87 ;
V_94 -> V_13 = V_13 ;
V_94 -> V_72 = V_30 -> V_100 [ 0 ] ;
V_94 -> V_23 = V_23 >> 16 ;
V_94 -> V_25 = V_25 >> 16 ;
V_94 -> V_79 = V_88 ;
V_94 -> V_81 = V_89 ;
V_94 -> V_75 = V_90 ;
V_94 -> V_77 = V_91 ;
F_13 ( V_94 , V_30 ) ;
F_17 ( V_94 ) ;
F_8 ( & V_7 -> V_18 . V_19 ) ;
V_94 -> V_101 = true ;
F_20 ( V_94 -> V_87 ) ;
F_10 ( & V_7 -> V_18 . V_19 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_14 -> V_95 ;
struct V_1 * V_94 = F_1 ( V_3 ) ;
if ( ! V_94 -> V_101 )
return 0 ;
F_8 ( & V_7 -> V_18 . V_19 ) ;
V_94 -> V_101 = false ;
F_20 ( V_94 -> V_87 ) ;
F_10 ( & V_7 -> V_18 . V_19 ) ;
F_11 ( V_94 ) ;
V_94 -> V_87 = NULL ;
V_94 -> V_13 = NULL ;
return 0 ;
}
static void F_22 ( struct V_1 * V_3 , T_1 V_42 )
{
if ( V_3 -> V_42 == V_42 )
return;
V_3 -> V_42 = V_42 ;
if ( ! V_3 -> V_101 || V_3 -> V_13 -> V_37 != V_38 )
return;
F_15 ( V_3 , V_3 -> V_21 ) ;
}
static void F_23 ( struct V_1 * V_3 ,
T_1 V_35 )
{
if ( V_3 -> V_35 == V_35 )
return;
V_3 -> V_35 = V_35 ;
if ( ! V_3 -> V_101 )
return;
F_15 ( V_3 , V_3 -> V_21 ) ;
}
static void F_24 ( struct V_1 * V_3 ,
unsigned int V_102 )
{
struct V_6 * V_7 = V_3 -> V_14 ;
F_8 ( & V_7 -> V_18 . V_19 ) ;
if ( V_3 -> V_102 == V_102 )
goto V_20;
V_3 -> V_102 = V_102 ;
if ( ! V_3 -> V_101 )
goto V_20;
F_20 ( V_3 -> V_87 ) ;
V_20:
F_10 ( & V_7 -> V_18 . V_19 ) ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_103 * V_104 ,
T_3 V_105 )
{
struct V_6 * V_7 = V_3 -> V_14 -> V_95 ;
struct V_1 * V_94 = F_1 ( V_3 ) ;
if ( V_104 == V_7 -> V_18 . V_42 )
F_22 ( V_94 , V_105 ) ;
else if ( V_104 == V_7 -> V_18 . V_35 )
F_23 ( V_94 , V_105 ) ;
else if ( V_104 == V_7 -> V_18 . V_102 )
F_24 ( V_94 , V_105 ) ;
else
return - V_99 ;
return 0 ;
}
int F_26 ( struct V_6 * V_7 )
{
unsigned int V_15 ;
F_27 ( & V_7 -> V_18 . V_19 ) ;
V_7 -> V_18 . free = 0xff ;
V_7 -> V_18 . V_42 =
F_28 ( V_7 -> V_106 , 0 , L_3 , 0 , 255 ) ;
if ( V_7 -> V_18 . V_42 == NULL )
return - V_107 ;
V_7 -> V_18 . V_35 =
F_28 ( V_7 -> V_106 , 0 , L_4 ,
0 , 0x01ffffff ) ;
if ( V_7 -> V_18 . V_35 == NULL )
return - V_107 ;
V_7 -> V_18 . V_102 =
F_28 ( V_7 -> V_106 , 0 , L_5 , 1 , 7 ) ;
if ( V_7 -> V_18 . V_102 == NULL )
return - V_107 ;
for ( V_15 = 0 ; V_15 < F_9 ( V_7 -> V_18 . V_18 ) ; ++ V_15 ) {
struct V_1 * V_3 = & V_7 -> V_18 . V_18 [ V_15 ] ;
V_3 -> V_14 = V_7 ;
V_3 -> V_21 = - 1 ;
V_3 -> V_42 = 255 ;
V_3 -> V_35 = V_45 ;
V_3 -> V_102 = 0 ;
}
return 0 ;
}
int F_29 ( struct V_6 * V_7 )
{
unsigned int V_15 ;
int V_16 ;
for ( V_15 = 0 ; V_15 < V_108 ; ++ V_15 ) {
struct V_4 * V_3 ;
V_3 = F_30 ( V_7 -> V_14 , sizeof( * V_3 ) , V_109 ) ;
if ( V_3 == NULL )
return - V_107 ;
V_3 -> V_5 = & V_7 -> V_18 . V_18 [ V_15 + 2 ] ;
V_3 -> V_5 -> V_102 = 1 ;
V_16 = F_31 ( V_7 -> V_106 , & V_3 -> V_3 ,
( 1 << V_7 -> V_110 ) - 1 ,
& V_111 , V_112 ,
F_9 ( V_112 ) , false ) ;
if ( V_16 < 0 )
return V_16 ;
F_32 ( & V_3 -> V_3 . V_113 ,
V_7 -> V_18 . V_42 , 255 ) ;
F_32 ( & V_3 -> V_3 . V_113 ,
V_7 -> V_18 . V_35 ,
V_45 ) ;
F_32 ( & V_3 -> V_3 . V_113 ,
V_7 -> V_18 . V_102 , 1 ) ;
}
return 0 ;
}
