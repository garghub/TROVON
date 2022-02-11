static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_1 , unsigned int V_4 ,
unsigned int * V_5 )
{
return F_4 ( V_1 -> V_6 , V_4 , V_5 , sizeof( V_7 ) ) ;
}
static int F_5 ( struct V_1 * V_1 , unsigned int V_4 , V_7 V_5 )
{
return F_6 ( V_1 -> V_6 , V_4 , & V_5 , sizeof( V_7 ) ) ;
}
static int F_7 ( struct V_2 * V_3 , enum V_8 V_9 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_4 ;
int V_10 ;
switch ( V_9 ) {
case V_11 :
V_4 = ( V_12 << V_13 ) |
( V_12 << V_14 ) ;
break;
case V_15 :
V_4 = ( V_16 << V_13 ) |
( V_16 << V_14 ) ;
break;
case V_17 :
V_4 = ( V_18 << V_13 ) |
( V_18 << V_14 ) |
( V_19 <<
V_20 ) ;
break;
case V_21 :
V_4 = ( V_18 << V_13 ) |
( V_18 << V_14 ) |
( V_22 <<
V_20 ) ;
break;
case V_23 :
V_4 = ( V_18 << V_13 ) |
( V_18 << V_14 ) |
( V_24 <<
V_20 ) ;
break;
case V_25 :
default:
V_4 = ( V_26 << V_13 ) |
( V_26 << V_14 ) ;
break;
}
V_10 = F_8 ( V_1 -> V_6 , V_27 , V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 ,
enum V_8 V_9 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_4 = V_28 ;
switch ( V_9 ) {
default:
case V_17 :
V_4 |= ( V_19 <<
V_20 ) ;
break;
case V_21 :
V_4 |= ( V_22 <<
V_20 ) ;
break;
case V_23 :
V_4 |= ( V_24 <<
V_20 ) ;
break;
}
return F_8 ( V_1 -> V_6 , V_27 , V_4 ) ;
}
static enum V_8 F_10 ( unsigned int V_9 , bool V_29 )
{
switch ( V_9 ) {
case 0x1 :
return V_29 ? V_17 : V_11 ;
case 0x2 :
return V_29 ? V_21 : V_15 ;
case 0x3 :
if ( V_29 )
return V_23 ;
case 0x0 :
default:
return V_25 ;
}
}
static int F_11 ( struct V_2 * V_3 ,
enum V_8 * V_30 , enum V_8 * V_31 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_4 ;
int V_10 ;
V_10 = F_12 ( V_1 -> V_6 , V_32 , & V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_30 = F_10 ( ( V_4 >> V_33 ) &
V_34 ,
V_4 & V_35 ) ;
* V_31 = F_10 ( ( V_4 >> V_36 ) &
V_37 ,
V_4 & V_35 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
enum V_38 V_39 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_10 ;
V_10 = F_8 ( V_1 -> V_6 , V_40 ,
( V_39 == V_41 ) ?
V_42 : 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , bool V_43 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_10 ;
V_10 = F_8 ( V_1 -> V_6 , V_44 ,
V_43 ? V_45 : 0 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , bool V_46 ,
enum V_47 V_48 , enum V_49 V_50 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_4 ;
int V_10 ;
V_4 = V_51 << V_52 ;
if ( V_48 == V_53 )
V_4 |= V_54 ;
if ( V_50 == V_55 )
V_4 |= V_56 ;
V_10 = F_8 ( V_1 -> V_6 , V_57 , V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , bool V_43 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_4 = 0 ;
int V_10 ;
if ( V_43 )
V_4 = V_58 | V_59 ;
V_10 = F_8 ( V_1 -> V_6 , V_60 , V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_4 ;
int V_10 ;
V_10 = F_12 ( V_1 -> V_6 , V_61 , & V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
return ! ! ( V_4 & V_62 ) ;
}
static int F_18 ( struct V_2 * V_3 , bool V_63 , bool V_29 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_10 ;
if ( ! V_63 ) {
V_10 = F_8 ( V_1 -> V_6 , V_64 ,
V_65 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( ! V_29 ) {
V_10 = F_8 ( V_1 -> V_6 , V_64 ,
V_66 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_63 ) {
V_10 = F_8 ( V_1 -> V_6 , V_64 ,
V_67 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_29 ) {
V_10 = F_8 ( V_1 -> V_6 , V_64 ,
V_68 ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
static int F_19 ( struct V_2 * V_3 ,
enum V_69 type ,
const struct V_70 * V_71 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_4 , V_72 , V_73 ;
int V_10 ;
V_72 = V_71 ? F_20 ( V_71 -> V_73 ) * 4 : 0 ;
V_10 = F_8 ( V_1 -> V_6 , V_74 , V_72 + 2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_73 = V_71 ? V_71 -> V_73 : 0 ;
V_10 = F_5 ( V_1 , V_75 , V_73 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_72 > 0 ) {
V_10 = F_6 ( V_1 -> V_6 , V_76 ,
& V_71 -> V_77 , V_72 ) ;
if ( V_10 < 0 )
return V_10 ;
}
V_4 = ( V_78 << V_79 ) |
( type << V_80 ) ;
V_10 = F_8 ( V_1 -> V_6 , V_81 , V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_82 = V_83 + F_22 ( 2000 ) ;
unsigned int V_4 ;
int V_10 ;
while ( F_23 ( V_83 , V_82 ) ) {
V_10 = F_12 ( V_1 -> V_6 , V_61 , & V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! ( V_4 & V_84 ) )
break;
F_24 ( 10000 , 20000 ) ;
}
if ( F_25 ( V_83 , V_82 ) )
return - V_85 ;
V_10 = F_5 ( V_1 , V_86 , 0xffff ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_1 -> V_87 )
V_4 = V_62 ;
else
V_4 = 0 ;
V_10 = F_8 ( V_1 -> V_6 , V_88 , V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_89 | V_90 |
V_91 | V_92 |
V_93 | V_94 ;
if ( V_1 -> V_87 )
V_4 |= V_95 ;
return F_5 ( V_1 , V_96 , V_4 ) ;
}
static T_1 F_26 ( int V_97 , void * V_98 )
{
struct V_1 * V_1 = V_98 ;
unsigned int V_99 , V_4 ;
F_3 ( V_1 , V_86 , & V_99 ) ;
if ( V_99 & ~ V_92 )
F_5 ( V_1 , V_86 ,
V_99 & ~ V_92 ) ;
if ( V_99 & V_94 )
F_27 ( V_1 -> V_100 ) ;
if ( V_99 & V_95 ) {
F_12 ( V_1 -> V_6 , V_88 , & V_4 ) ;
if ( V_4 == 0xff )
F_28 ( V_1 -> V_100 ) ;
else
F_29 ( V_1 -> V_100 ) ;
}
if ( V_99 & V_92 ) {
struct V_70 V_71 ;
unsigned int V_72 ;
F_12 ( V_1 -> V_6 , V_101 , & V_72 ) ;
F_3 ( V_1 , V_102 , & V_4 ) ;
V_71 . V_73 = V_4 ;
if ( F_30 ( V_72 > sizeof( V_71 . V_77 ) ) )
V_72 = sizeof( V_71 . V_77 ) ;
if ( V_72 > 0 )
F_4 ( V_1 -> V_6 , V_103 ,
& V_71 . V_77 , V_72 ) ;
F_5 ( V_1 , V_86 , V_92 ) ;
F_31 ( V_1 -> V_100 , & V_71 ) ;
}
if ( V_99 & V_93 )
F_32 ( V_1 -> V_100 ) ;
if ( V_99 & V_89 )
F_33 ( V_1 -> V_100 , V_104 ) ;
else if ( V_99 & V_91 )
F_33 ( V_1 -> V_100 , V_105 ) ;
else if ( V_99 & V_90 )
F_33 ( V_1 -> V_100 , V_106 ) ;
return V_107 ;
}
static int F_34 ( struct V_1 * V_1 )
{
V_1 -> V_87 = true ;
V_1 -> V_3 . V_108 = & V_109 ;
return 0 ;
}
static int F_35 ( struct V_110 * V_111 ,
const struct V_112 * V_113 )
{
struct V_1 * V_1 ;
int V_114 ;
V_1 = F_36 ( & V_111 -> V_115 , sizeof( * V_1 ) , V_116 ) ;
if ( ! V_1 )
return - V_117 ;
V_1 -> V_111 = V_111 ;
V_1 -> V_115 = & V_111 -> V_115 ;
F_37 ( V_111 , V_1 ) ;
V_1 -> V_6 = F_38 ( V_111 , & V_118 ) ;
if ( F_39 ( V_1 -> V_6 ) )
return F_40 ( V_1 -> V_6 ) ;
V_1 -> V_3 . V_119 = F_21 ;
V_1 -> V_3 . V_120 = F_17 ;
V_1 -> V_3 . V_121 = F_18 ;
V_1 -> V_3 . V_122 = F_7 ;
V_1 -> V_3 . V_123 = F_11 ;
V_1 -> V_3 . V_124 = F_13 ;
V_1 -> V_3 . V_125 = F_14 ;
V_1 -> V_3 . V_126 = F_9 ;
V_1 -> V_3 . V_127 = F_16 ;
V_1 -> V_3 . V_128 = F_15 ;
V_1 -> V_3 . V_129 = F_19 ;
V_114 = F_34 ( V_1 ) ;
if ( V_114 < 0 )
return V_114 ;
F_5 ( V_1 , V_96 , 0 ) ;
V_114 = F_41 ( V_1 -> V_115 , V_111 -> V_97 , NULL ,
F_26 ,
V_130 | V_131 ,
F_42 ( V_1 -> V_115 ) , V_1 ) ;
if ( V_114 < 0 )
return V_114 ;
V_1 -> V_100 = F_43 ( V_1 -> V_115 , & V_1 -> V_3 ) ;
return F_44 ( V_1 -> V_100 ) ;
}
static int F_45 ( struct V_110 * V_111 )
{
struct V_1 * V_1 = F_46 ( V_111 ) ;
F_47 ( V_1 -> V_100 ) ;
return 0 ;
}
