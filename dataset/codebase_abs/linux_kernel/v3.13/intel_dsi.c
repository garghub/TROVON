static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 )
{
T_1 V_6 = F_2 ( V_2 , V_3 ) ;
V_6 &= ~ V_5 ;
V_6 |= V_4 ;
F_3 ( V_2 , V_3 , V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_7 ) ;
F_1 ( V_2 , 0x6D , 0x00010000 , 0x00030000 ) ;
F_6 ( 20 ) ;
F_1 ( V_2 , 0x6E , 0x00010000 , 0x00030000 ) ;
F_6 ( 20 ) ;
F_1 ( V_2 , 0x6F , 0x00010000 , 0x00030000 ) ;
F_6 ( 20 ) ;
F_1 ( V_2 , 0x00 , 0x00008000 , 0x00008000 ) ;
F_6 ( 20 ) ;
F_1 ( V_2 , 0x00 , 0x00000000 , 0x00008000 ) ;
F_6 ( 20 ) ;
F_1 ( V_2 , 0x6B , 0x00020000 , 0x00030000 ) ;
F_6 ( 20 ) ;
F_1 ( V_2 , 0x6C , 0x00020000 , 0x00030000 ) ;
F_6 ( 20 ) ;
F_1 ( V_2 , 0x6D , 0x00020000 , 0x00030000 ) ;
F_6 ( 20 ) ;
F_1 ( V_2 , 0x6E , 0x00020000 , 0x00030000 ) ;
F_6 ( 20 ) ;
F_1 ( V_2 , 0x6F , 0x00020000 , 0x00030000 ) ;
F_7 ( & V_2 -> V_7 ) ;
F_6 ( 100 ) ;
}
static struct V_8 * F_8 ( struct V_9 * V_10 )
{
return F_9 ( F_10 ( V_10 ) ,
struct V_8 , V_11 ) ;
}
static inline bool F_11 ( struct V_8 * V_8 )
{
return V_8 -> V_12 . type == V_13 ;
}
static inline bool F_12 ( struct V_8 * V_8 )
{
return V_8 -> V_12 . type == V_14 ;
}
static void F_13 ( struct V_15 * V_16 )
{
F_14 ( L_1 ) ;
}
static bool F_15 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_8 * V_8 = F_9 ( V_16 , struct V_8 ,
V_11 ) ;
struct V_19 * V_19 = V_8 -> V_20 ;
struct V_21 * V_22 = V_19 -> V_23 . V_22 ;
struct V_21 * V_24 = & V_18 -> V_24 ;
struct V_21 * V_25 = & V_18 -> V_26 ;
F_14 ( L_1 ) ;
if ( V_22 )
F_16 ( V_22 , V_24 ) ;
if ( V_8 -> V_12 . V_27 -> V_28 )
return V_8 -> V_12 . V_27 -> V_28 ( & V_8 -> V_12 ,
V_25 , V_24 ) ;
return true ;
}
static void F_17 ( struct V_15 * V_16 )
{
F_14 ( L_1 ) ;
F_18 ( V_16 ) ;
}
static void F_19 ( struct V_15 * V_16 )
{
F_14 ( L_1 ) ;
}
static void F_20 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_11 . V_12 -> V_29 ;
struct V_30 * V_30 = F_21 ( V_16 -> V_11 . V_31 ) ;
struct V_8 * V_8 = F_22 ( & V_16 -> V_11 ) ;
int V_32 = V_30 -> V_32 ;
T_1 V_33 ;
F_14 ( L_1 ) ;
V_33 = F_23 ( F_24 ( V_32 ) ) ;
if ( ( V_33 & V_34 ) == 0 ) {
V_33 &= ~ V_35 ;
F_25 ( F_24 ( V_32 ) , V_33 | V_34 ) ;
} else if ( V_33 & V_35 ) {
V_33 &= ~ V_35 ;
F_25 ( F_24 ( V_32 ) , V_33 | V_36 ) ;
F_6 ( 2 ) ;
F_25 ( F_24 ( V_32 ) , V_33 ) ;
}
if ( F_12 ( V_8 ) )
F_25 ( F_26 ( V_32 ) , 8 * 4 ) ;
if ( F_11 ( V_8 ) ) {
F_6 ( 20 ) ;
F_27 ( V_8 , V_37 ) ;
F_6 ( 100 ) ;
V_33 = F_23 ( F_28 ( V_32 ) ) ;
F_25 ( F_28 ( V_32 ) , V_33 | V_38 ) ;
F_29 ( F_28 ( V_32 ) ) ;
}
V_8 -> V_12 . V_27 -> V_39 ( & V_8 -> V_12 ) ;
}
static void F_30 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_11 . V_12 -> V_29 ;
struct V_30 * V_30 = F_21 ( V_16 -> V_11 . V_31 ) ;
struct V_8 * V_8 = F_22 ( & V_16 -> V_11 ) ;
int V_32 = V_30 -> V_32 ;
T_1 V_33 ;
F_14 ( L_1 ) ;
V_8 -> V_12 . V_27 -> V_40 ( & V_8 -> V_12 ) ;
if ( F_11 ( V_8 ) ) {
F_27 ( V_8 , V_41 ) ;
F_6 ( 10 ) ;
V_33 = F_23 ( F_28 ( V_32 ) ) ;
F_25 ( F_28 ( V_32 ) , V_33 & ~ V_38 ) ;
F_29 ( F_28 ( V_32 ) ) ;
F_6 ( 2 ) ;
}
V_33 = F_23 ( F_24 ( V_32 ) ) ;
if ( V_33 & V_34 ) {
V_33 &= ~ V_34 ;
V_33 &= ~ V_35 ;
F_25 ( F_24 ( V_32 ) , V_33 ) ;
}
}
static void F_31 ( struct V_15 * V_16 )
{
F_14 ( L_1 ) ;
F_32 ( V_16 ) ;
}
static bool F_33 ( struct V_15 * V_16 ,
enum V_32 * V_32 )
{
struct V_1 * V_2 = V_16 -> V_11 . V_12 -> V_29 ;
T_1 V_42 , V_43 ;
enum V_32 V_44 ;
F_14 ( L_1 ) ;
for ( V_44 = V_45 ; V_44 <= V_46 ; V_44 ++ ) {
V_42 = F_23 ( F_28 ( V_44 ) ) ;
V_43 = F_23 ( F_34 ( V_44 ) ) ;
if ( ( V_42 & V_38 ) || ( V_43 & V_47 ) ) {
if ( F_23 ( F_24 ( V_44 ) ) & V_34 ) {
* V_32 = V_44 ;
return true ;
}
}
}
return false ;
}
static void F_35 ( struct V_15 * V_16 ,
struct V_17 * V_48 )
{
F_14 ( L_1 ) ;
}
static int F_36 ( struct V_9 * V_10 ,
struct V_21 * V_25 )
{
struct V_19 * V_19 = F_37 ( V_10 ) ;
struct V_21 * V_22 = V_19 -> V_23 . V_22 ;
struct V_8 * V_8 = F_8 ( V_10 ) ;
F_14 ( L_1 ) ;
if ( V_25 -> V_49 & V_50 ) {
F_14 ( L_2 ) ;
return V_51 ;
}
if ( V_22 ) {
if ( V_25 -> V_52 > V_22 -> V_52 )
return V_53 ;
if ( V_25 -> V_54 > V_22 -> V_54 )
return V_53 ;
}
return V_8 -> V_12 . V_27 -> V_55 ( & V_8 -> V_12 , V_25 ) ;
}
static T_2 F_38 ( T_1 V_56 , unsigned int V_57 )
{
switch ( V_56 ) {
case V_58 :
default:
return 20 * V_57 ;
case V_59 :
return 10 * V_57 ;
case V_60 :
return 5 * V_57 ;
}
}
static T_2 F_39 ( T_2 V_61 , int V_62 , int V_63 )
{
return F_40 ( F_40 ( V_61 * V_62 , 8 ) , V_63 ) ;
}
static void F_41 ( struct V_64 * V_16 ,
const struct V_21 * V_25 )
{
struct V_65 * V_12 = V_16 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_29 ;
struct V_30 * V_30 = F_21 ( V_16 -> V_31 ) ;
struct V_8 * V_8 = F_22 ( V_16 ) ;
int V_32 = V_30 -> V_32 ;
unsigned int V_62 = V_30 -> V_18 . V_66 ;
unsigned int V_63 = V_8 -> V_63 ;
T_2 V_67 , V_68 , V_69 , V_70 , V_71 , V_72 , V_73 ;
V_67 = V_25 -> V_52 ;
V_68 = V_25 -> V_74 - V_25 -> V_52 ;
V_69 = V_25 -> V_75 - V_25 -> V_74 ;
V_70 = V_25 -> V_76 - V_25 -> V_75 ;
V_71 = V_25 -> V_77 - V_25 -> V_54 ;
V_72 = V_25 -> V_78 - V_25 -> V_77 ;
V_73 = V_25 -> V_79 - V_25 -> V_78 ;
V_67 = F_39 ( V_67 , V_62 , V_63 ) ;
V_68 = F_39 ( V_68 , V_62 , V_63 ) ;
V_69 = F_39 ( V_69 , V_62 , V_63 ) ;
V_70 = F_39 ( V_70 , V_62 , V_63 ) ;
F_25 ( F_42 ( V_32 ) , V_67 ) ;
F_25 ( F_43 ( V_32 ) , V_68 ) ;
F_25 ( F_44 ( V_32 ) , V_69 ) ;
F_25 ( F_45 ( V_32 ) , V_70 ) ;
F_25 ( F_46 ( V_32 ) , V_71 ) ;
F_25 ( F_47 ( V_32 ) , V_72 ) ;
F_25 ( F_48 ( V_32 ) , V_73 ) ;
}
static void F_49 ( struct V_15 * V_15 )
{
struct V_64 * V_16 = & V_15 -> V_11 ;
struct V_65 * V_12 = V_16 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_29 ;
struct V_30 * V_30 = F_21 ( V_16 -> V_31 ) ;
struct V_8 * V_8 = F_22 ( V_16 ) ;
struct V_21 * V_24 =
& V_30 -> V_18 . V_24 ;
int V_32 = V_30 -> V_32 ;
unsigned int V_62 = V_30 -> V_18 . V_66 ;
T_1 V_4 , V_6 ;
F_14 ( L_3 , F_50 ( V_32 ) ) ;
F_18 ( V_15 ) ;
F_4 ( V_2 ) ;
V_6 = F_23 ( F_51 ( 0 ) ) ;
V_6 &= ~ V_80 ;
F_25 ( F_51 ( 0 ) , V_6 | V_58 ) ;
V_6 = F_23 ( F_51 ( V_32 ) ) ;
V_6 &= ~ V_81 ;
F_25 ( F_51 ( V_32 ) , V_6 | V_82 ) ;
F_25 ( F_52 ( V_32 ) , 0xffffffff ) ;
F_25 ( F_53 ( V_32 ) , 0xffffffff ) ;
F_25 ( F_54 ( V_32 ) ,
0x3c << V_83 |
0x1f << V_84 |
0xc5 << V_85 |
0x1f << V_86 ) ;
F_25 ( F_55 ( V_32 ) ,
V_24 -> V_54 << V_87 |
V_24 -> V_52 << V_88 ) ;
F_41 ( V_16 , V_24 ) ;
V_4 = V_8 -> V_63 << V_89 ;
if ( F_12 ( V_8 ) ) {
V_4 |= V_8 -> V_90 << V_91 ;
V_4 |= V_92 ;
} else {
V_4 |= V_8 -> V_90 << V_93 ;
V_4 |= V_8 -> V_94 ;
}
F_25 ( F_34 ( V_32 ) , V_4 ) ;
if ( F_11 ( V_8 ) &&
V_8 -> V_95 == V_96 ) {
F_25 ( F_56 ( V_32 ) ,
F_39 ( V_24 -> V_76 , V_62 ,
V_8 -> V_63 ) + 1 ) ;
} else {
F_25 ( F_56 ( V_32 ) ,
F_39 ( V_24 -> V_79 *
V_24 -> V_76 ,
V_62 , V_8 -> V_63 ) + 1 ) ;
}
F_25 ( F_57 ( V_32 ) , 8309 ) ;
F_25 ( F_58 ( V_32 ) , 0x14 ) ;
F_25 ( F_59 ( V_32 ) , 0xffff ) ;
F_25 ( F_60 ( V_32 ) , F_38 ( V_58 , 100 ) ) ;
F_25 ( F_61 ( V_32 ) , V_8 -> V_97 ) ;
F_25 ( F_62 ( V_32 ) , 0x46 ) ;
F_25 ( F_63 ( V_32 ) , 4 ) ;
F_25 ( F_64 ( V_32 ) , 0x820 ) ;
F_25 ( F_65 ( V_32 ) ,
0xa << V_98 |
0x14 << V_99 ) ;
if ( F_11 ( V_8 ) )
F_25 ( F_66 ( V_32 ) ,
V_8 -> V_95 ) ;
}
static enum V_100
F_67 ( struct V_9 * V_10 , bool V_101 )
{
struct V_8 * V_8 = F_8 ( V_10 ) ;
F_14 ( L_1 ) ;
return V_8 -> V_12 . V_27 -> V_102 ( & V_8 -> V_12 ) ;
}
static int F_68 ( struct V_9 * V_10 )
{
struct V_19 * V_19 = F_37 ( V_10 ) ;
struct V_21 * V_25 ;
F_14 ( L_1 ) ;
if ( ! V_19 -> V_23 . V_22 ) {
F_14 ( L_4 ) ;
return 0 ;
}
V_25 = F_69 ( V_10 -> V_12 ,
V_19 -> V_23 . V_22 ) ;
if ( ! V_25 ) {
F_14 ( L_5 ) ;
return 0 ;
}
F_70 ( V_10 , V_25 ) ;
return 1 ;
}
static void F_71 ( struct V_9 * V_10 )
{
struct V_19 * V_19 = F_37 ( V_10 ) ;
F_14 ( L_1 ) ;
F_72 ( & V_19 -> V_23 ) ;
F_73 ( V_10 ) ;
F_74 ( V_10 ) ;
}
bool F_75 ( struct V_65 * V_12 )
{
struct V_8 * V_8 ;
struct V_15 * V_15 ;
struct V_64 * V_16 ;
struct V_19 * V_19 ;
struct V_9 * V_10 ;
struct V_21 * V_22 = NULL ;
const struct V_103 * V_104 ;
unsigned int V_105 ;
F_14 ( L_1 ) ;
V_8 = F_76 ( sizeof( * V_8 ) , V_106 ) ;
if ( ! V_8 )
return false ;
V_19 = F_76 ( sizeof( * V_19 ) , V_106 ) ;
if ( ! V_19 ) {
F_74 ( V_8 ) ;
return false ;
}
V_15 = & V_8 -> V_11 ;
V_16 = & V_15 -> V_11 ;
V_8 -> V_20 = V_19 ;
V_10 = & V_19 -> V_11 ;
F_77 ( V_12 , V_16 , & V_107 , V_108 ) ;
V_15 -> V_109 = F_13 ;
V_15 -> V_110 = F_15 ;
V_15 -> V_111 = F_17 ;
V_15 -> V_112 = F_19 ;
V_15 -> V_39 = F_20 ;
V_15 -> V_113 = F_49 ;
V_15 -> V_40 = F_30 ;
V_15 -> V_114 = F_31 ;
V_15 -> V_115 = F_33 ;
V_15 -> V_116 = F_35 ;
V_19 -> V_115 = V_117 ;
for ( V_105 = 0 ; V_105 < F_78 ( V_118 ) ; V_105 ++ ) {
V_104 = & V_118 [ V_105 ] ;
V_8 -> V_12 = * V_104 ;
if ( V_104 -> V_27 -> V_119 ( & V_8 -> V_12 ) )
break;
}
if ( V_105 == F_78 ( V_118 ) ) {
F_14 ( L_6 ) ;
goto V_120;
}
V_15 -> type = V_121 ;
V_15 -> V_122 = ( 1 << 0 ) ;
V_15 -> V_123 = false ;
F_79 ( V_12 , V_10 , & V_124 ,
V_125 ) ;
F_80 ( V_10 , & V_126 ) ;
V_10 -> V_127 . V_128 = V_129 ;
V_10 -> V_130 = false ;
V_10 -> V_131 = false ;
F_81 ( V_19 , V_15 ) ;
F_82 ( V_10 ) ;
V_22 = V_104 -> V_27 -> V_132 ( & V_8 -> V_12 ) ;
if ( ! V_22 ) {
F_14 ( L_4 ) ;
goto V_120;
}
V_22 -> type |= V_133 ;
F_83 ( & V_19 -> V_23 , V_22 ) ;
return true ;
V_120:
F_84 ( & V_15 -> V_11 ) ;
F_74 ( V_8 ) ;
F_74 ( V_19 ) ;
return false ;
}
