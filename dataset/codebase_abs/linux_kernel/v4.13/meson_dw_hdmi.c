static inline int F_1 ( struct V_1 * V_2 ,
const char * V_3 )
{
return F_2 ( V_2 -> V_4 -> V_5 , V_3 ) ;
}
static unsigned int F_3 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
unsigned long V_7 ;
unsigned int V_8 ;
F_4 ( & V_9 , V_7 ) ;
F_5 ( V_6 & 0xffff , V_2 -> V_10 + V_11 ) ;
F_5 ( V_6 & 0xffff , V_2 -> V_10 + V_11 ) ;
V_8 = F_6 ( V_2 -> V_10 + V_12 ) ;
V_8 = F_6 ( V_2 -> V_10 + V_12 ) ;
F_7 ( & V_9 , V_7 ) ;
return V_8 ;
}
static inline void F_8 ( struct V_1 * V_2 ,
unsigned int V_6 , unsigned int V_8 )
{
unsigned long V_7 ;
F_4 ( & V_9 , V_7 ) ;
F_5 ( V_6 & 0xffff , V_2 -> V_10 + V_11 ) ;
F_5 ( V_6 & 0xffff , V_2 -> V_10 + V_11 ) ;
F_5 ( V_8 , V_2 -> V_10 + V_12 ) ;
F_7 ( & V_9 , V_7 ) ;
}
static inline void F_9 ( struct V_1 * V_2 ,
unsigned int V_6 ,
unsigned int V_13 ,
unsigned int V_14 )
{
unsigned int V_8 = F_3 ( V_2 , V_6 ) ;
V_8 &= ~ V_13 ;
V_8 |= V_14 ;
F_8 ( V_2 , V_6 , V_8 ) ;
}
static unsigned int F_10 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
unsigned long V_7 ;
unsigned int V_8 ;
F_4 ( & V_9 , V_7 ) ;
F_5 ( V_6 & 0xffff , V_2 -> V_10 + V_15 ) ;
F_5 ( V_6 & 0xffff , V_2 -> V_10 + V_15 ) ;
V_8 = F_6 ( V_2 -> V_10 + V_16 ) ;
V_8 = F_6 ( V_2 -> V_10 + V_16 ) ;
F_7 ( & V_9 , V_7 ) ;
return V_8 ;
}
static inline void F_11 ( struct V_1 * V_2 ,
unsigned int V_6 , unsigned int V_8 )
{
unsigned long V_7 ;
F_4 ( & V_9 , V_7 ) ;
F_5 ( V_6 & 0xffff , V_2 -> V_10 + V_15 ) ;
F_5 ( V_6 & 0xffff , V_2 -> V_10 + V_15 ) ;
F_5 ( V_8 , V_2 -> V_10 + V_16 ) ;
F_7 ( & V_9 , V_7 ) ;
}
static inline void F_12 ( struct V_1 * V_2 ,
unsigned int V_6 ,
unsigned int V_13 ,
unsigned int V_14 )
{
unsigned int V_8 = F_10 ( V_2 , V_6 ) ;
V_8 &= ~ V_13 ;
V_8 |= V_14 ;
F_11 ( V_2 , V_6 , V_8 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
unsigned int V_21 = V_18 -> clock ;
if ( F_1 ( V_2 , L_1 ) ||
F_1 ( V_2 , L_2 ) ) {
if ( V_21 >= 371250 ) {
F_14 ( V_20 -> V_22 , V_23 , 0x333d3282 ) ;
F_14 ( V_20 -> V_22 , V_24 , 0x2136315b ) ;
} else if ( V_21 >= 297000 ) {
F_14 ( V_20 -> V_22 , V_23 , 0x33303382 ) ;
F_14 ( V_20 -> V_22 , V_24 , 0x2036315b ) ;
} else if ( V_21 >= 148500 ) {
F_14 ( V_20 -> V_22 , V_23 , 0x33303362 ) ;
F_14 ( V_20 -> V_22 , V_24 , 0x2016315b ) ;
} else {
F_14 ( V_20 -> V_22 , V_23 , 0x33604142 ) ;
F_14 ( V_20 -> V_22 , V_24 , 0x0016315b ) ;
}
} else if ( F_1 ( V_2 ,
L_3 ) ) {
if ( V_21 >= 371250 ) {
F_14 ( V_20 -> V_22 , V_23 , 0x33353245 ) ;
F_14 ( V_20 -> V_22 , V_24 , 0x2100115b ) ;
} else if ( V_21 >= 297000 ) {
F_14 ( V_20 -> V_22 , V_23 , 0x33634283 ) ;
F_14 ( V_20 -> V_22 , V_24 , 0xb000115b ) ;
} else {
F_14 ( V_20 -> V_22 , V_23 , 0x33632122 ) ;
F_14 ( V_20 -> V_22 , V_24 , 0x2000115b ) ;
}
}
}
static inline void F_15 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
F_16 ( V_20 -> V_22 , V_25 , 0xf , 0xf ) ;
F_17 ( 2 ) ;
F_16 ( V_20 -> V_22 , V_25 , 0xf , 0xe ) ;
F_17 ( 2 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
int V_26 = F_19 ( V_18 ) ;
unsigned int V_27 ;
unsigned int V_28 ;
unsigned int V_29 ;
V_27 = V_18 -> clock ;
if ( V_18 -> V_7 & V_30 )
V_27 *= 2 ;
V_28 = V_27 ;
V_29 = V_27 ;
if ( F_20 ( V_26 ) )
V_28 *= 2 ;
V_27 = F_21 ( V_28 , V_29 ) ;
if ( V_18 -> V_7 & V_30 )
V_28 /= 2 ;
F_22 ( L_4 ,
V_27 , V_28 , V_29 ,
V_20 -> V_31 . V_32 ) ;
F_23 ( V_20 , V_33 , V_27 ,
V_28 , V_29 , V_20 -> V_31 . V_32 ) ;
}
static int F_24 ( struct V_2 * V_34 , void * V_8 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
struct V_19 * V_20 = V_2 -> V_20 ;
unsigned int V_35 =
F_25 ( V_20 -> V_36 + F_26 ( V_37 ) ) ;
F_22 ( L_5 , V_18 -> V_38 . V_39 , V_18 -> V_40 ) ;
F_16 ( V_20 -> V_22 , V_41 , 0xffff , 0x100 ) ;
F_16 ( V_20 -> V_22 , V_42 , 0xff << 8 , 0 ) ;
F_8 ( V_2 , V_43 , 0 ) ;
F_9 ( V_2 , V_44 ,
0x3 , 0x3 ) ;
F_9 ( V_2 , V_44 ,
0x3 << 4 , 0x3 << 4 ) ;
F_8 ( V_2 , V_45 , F_27 ( 12 ) ) ;
F_8 ( V_2 , V_46 , 0x001f001f ) ;
F_8 ( V_2 , V_47 , 0x001f001f ) ;
F_8 ( V_2 , V_48 , 0x1 ) ;
F_28 ( 20 ) ;
F_8 ( V_2 , V_48 , 0x2 ) ;
F_13 ( V_2 , V_18 ) ;
F_16 ( V_20 -> V_22 , V_25 ,
0xffff << 16 , 0x0390 << 16 ) ;
if ( F_1 ( V_2 , L_1 ) ||
F_1 ( V_2 , L_2 ) )
F_16 ( V_20 -> V_22 , V_25 ,
F_27 ( 17 ) , 0 ) ;
else
F_16 ( V_20 -> V_22 , V_25 ,
F_27 ( 17 ) , F_27 ( 17 ) ) ;
F_16 ( V_20 -> V_22 , V_25 , 0xf , 0 ) ;
F_28 ( 100 ) ;
F_15 ( V_2 ) ;
F_15 ( V_2 ) ;
F_15 ( V_2 ) ;
if ( V_20 -> V_31 . V_32 )
F_29 ( 0 , V_20 -> V_36 + F_26 ( V_49 ) ) ;
else
F_29 ( 0 , V_20 -> V_36 + F_26 ( V_50 ) ) ;
F_30 ( 0x3 , 0 ,
V_20 -> V_36 + F_26 ( V_37 ) ) ;
F_30 ( 0xf << 8 , 0 ,
V_20 -> V_36 + F_26 ( V_37 ) ) ;
if ( V_20 -> V_31 . V_32 )
F_29 ( 1 , V_20 -> V_36 + F_26 ( V_49 ) ) ;
else
F_29 ( 1 , V_20 -> V_36 + F_26 ( V_50 ) ) ;
F_30 ( 0xf << 8 , V_35 & ( 0xf << 8 ) ,
V_20 -> V_36 + F_26 ( V_37 ) ) ;
if ( V_20 -> V_31 . V_32 )
F_30 ( 0x3 , V_51 ,
V_20 -> V_36 + F_26 ( V_37 ) ) ;
else
F_30 ( 0x3 , V_52 ,
V_20 -> V_36 + F_26 ( V_37 ) ) ;
return 0 ;
}
static void F_31 ( struct V_2 * V_34 ,
void * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
struct V_19 * V_20 = V_2 -> V_20 ;
F_22 ( L_6 ) ;
F_14 ( V_20 -> V_22 , V_23 , 0 ) ;
}
static enum V_53 F_32 ( struct V_2 * V_34 ,
void * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
return ! ! F_3 ( V_2 , V_54 ) ?
V_55 : V_56 ;
}
static void F_33 ( struct V_2 * V_34 ,
void * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
F_8 ( V_2 , V_57 ,
( 0xa << 12 ) | 0xa0 ) ;
F_8 ( V_2 , V_58 ,
V_59 | V_60 ) ;
F_9 ( V_2 , V_61 ,
V_59 | V_60 ,
V_59 | V_60 ) ;
}
static T_1 F_34 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
T_2 V_64 ;
V_64 = F_3 ( V_2 , V_65 ) ;
F_8 ( V_2 , V_58 , V_64 ) ;
if ( V_64 & ( V_59 | V_60 ) ) {
V_2 -> V_66 = V_64 ;
return V_67 ;
}
if ( V_64 & 1 )
return V_68 ;
return V_69 ;
}
static T_1 F_35 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
T_2 V_64 = V_2 -> V_66 ;
if ( V_64 & ( V_59 | V_60 ) ) {
bool V_70 = false ;
if ( V_64 & V_59 )
V_70 = true ;
F_36 ( V_2 -> V_4 , V_70 ,
V_70 ) ;
F_37 ( V_2 -> V_71 . V_4 ) ;
}
return V_69 ;
}
static enum V_72
F_38 ( struct V_73 * V_74 ,
const struct V_17 * V_18 )
{
unsigned int V_27 ;
unsigned int V_28 ;
unsigned int V_29 ;
int V_26 = F_19 ( V_18 ) ;
F_22 ( L_7 ,
V_18 -> V_38 . V_39 , V_18 -> V_40 , V_18 -> V_75 , V_18 -> clock ,
V_18 -> V_76 , V_18 -> V_77 ,
V_18 -> V_78 , V_18 -> V_79 ,
V_18 -> V_80 , V_18 -> V_81 ,
V_18 -> V_82 , V_18 -> V_83 , V_18 -> type , V_18 -> V_7 ) ;
if ( ! V_26 )
return V_84 ;
if ( ! F_39 ( V_26 ) )
return V_84 ;
V_27 = V_18 -> clock ;
if ( V_18 -> V_7 & V_30 )
V_27 *= 2 ;
V_28 = V_27 ;
V_29 = V_27 ;
if ( F_20 ( V_26 ) )
V_28 *= 2 ;
V_27 = F_21 ( V_28 , V_29 ) ;
if ( V_18 -> V_7 & V_30 )
V_28 /= 2 ;
F_40 ( V_74 -> V_4 -> V_4 , L_8 , V_85 ,
V_27 , V_28 , V_29 ) ;
switch ( V_27 ) {
case 54000 :
case 74250 :
case 148500 :
case 297000 :
case 594000 :
return V_86 ;
}
return V_87 ;
}
static void F_41 ( struct V_88 * V_71 )
{
F_42 ( V_71 ) ;
}
static int F_43 ( struct V_88 * V_71 ,
struct V_89 * V_90 ,
struct V_91 * V_92 )
{
return 0 ;
}
static void F_44 ( struct V_88 * V_71 )
{
struct V_1 * V_2 = F_45 ( V_71 ) ;
struct V_19 * V_20 = V_2 -> V_20 ;
F_22 ( L_6 ) ;
F_30 ( 0x3 , 0 ,
V_20 -> V_36 + F_26 ( V_37 ) ) ;
F_29 ( 0 , V_20 -> V_36 + F_26 ( V_49 ) ) ;
F_29 ( 0 , V_20 -> V_36 + F_26 ( V_50 ) ) ;
}
static void F_46 ( struct V_88 * V_71 )
{
struct V_1 * V_2 = F_45 ( V_71 ) ;
struct V_19 * V_20 = V_2 -> V_20 ;
F_22 ( L_9 , V_20 -> V_31 . V_32 ? L_10 : L_11 ) ;
if ( V_20 -> V_31 . V_32 )
F_29 ( 1 , V_20 -> V_36 + F_26 ( V_49 ) ) ;
else
F_29 ( 1 , V_20 -> V_36 + F_26 ( V_50 ) ) ;
}
static void F_47 ( struct V_88 * V_71 ,
struct V_17 * V_18 ,
struct V_17 * V_93 )
{
struct V_1 * V_2 = F_45 ( V_71 ) ;
struct V_19 * V_20 = V_2 -> V_20 ;
int V_26 = F_19 ( V_18 ) ;
F_22 ( L_12 ,
V_18 -> V_38 . V_39 , V_18 -> V_40 , V_26 ) ;
if ( ! V_26 )
return;
F_48 ( V_20 , V_26 , V_18 ) ;
F_18 ( V_2 , V_18 ) ;
F_29 ( 0 , V_20 -> V_36 + F_26 ( V_94 ) ) ;
}
static int F_49 ( void * V_95 , unsigned int V_96 ,
unsigned int * V_97 )
{
* V_97 = F_10 ( V_95 , V_96 ) ;
return 0 ;
}
static int F_50 ( void * V_95 , unsigned int V_96 ,
unsigned int V_14 )
{
F_11 ( V_95 , V_96 , V_14 ) ;
return 0 ;
}
static bool F_51 ( struct V_98 * V_4 )
{
struct V_99 * V_100 , * V_101 ;
V_100 = F_52 ( V_4 -> V_5 , 1 , 0 ) ;
if ( ! V_100 )
return false ;
V_101 = F_53 ( V_100 ) ;
if ( V_101 ) {
F_54 ( V_100 ) ;
return true ;
}
F_54 ( V_100 ) ;
F_54 ( V_101 ) ;
return false ;
}
static int F_55 ( struct V_98 * V_4 , struct V_98 * V_102 ,
void * V_8 )
{
struct V_103 * V_104 = F_56 ( V_4 ) ;
struct V_1 * V_1 ;
struct V_105 * V_106 = V_8 ;
struct V_19 * V_20 = V_106 -> V_107 ;
struct V_108 * V_109 ;
struct V_88 * V_71 ;
struct V_110 * V_111 ;
int V_62 ;
int V_112 ;
F_22 ( L_6 ) ;
if ( ! F_51 ( V_4 ) ) {
F_57 ( V_106 -> V_4 , L_13 ) ;
return - V_113 ;
}
V_1 = F_58 ( V_4 , sizeof( * V_1 ) ,
V_114 ) ;
if ( ! V_1 )
return - V_115 ;
V_1 -> V_20 = V_20 ;
V_1 -> V_4 = V_4 ;
V_109 = & V_1 -> V_109 ;
V_71 = & V_1 -> V_71 ;
V_1 -> V_116 = F_59 ( V_4 ,
L_14 ) ;
if ( F_60 ( V_1 -> V_116 ) ) {
F_61 ( V_4 , L_15 ) ;
return F_62 ( V_1 -> V_116 ) ;
}
V_1 -> V_117 = F_59 ( V_4 ,
L_16 ) ;
if ( F_60 ( V_1 -> V_117 ) ) {
F_61 ( V_4 , L_17 ) ;
return F_62 ( V_1 -> V_117 ) ;
}
V_1 -> V_118 = F_59 ( V_4 ,
L_18 ) ;
if ( F_60 ( V_1 -> V_118 ) ) {
F_61 ( V_4 , L_19 ) ;
return F_62 ( V_1 -> V_118 ) ;
}
V_111 = F_63 ( V_104 , V_119 , 0 ) ;
V_1 -> V_10 = F_64 ( V_4 , V_111 ) ;
if ( F_60 ( V_1 -> V_10 ) )
return F_62 ( V_1 -> V_10 ) ;
V_1 -> V_120 = F_65 ( V_4 , L_20 ) ;
if ( F_60 ( V_1 -> V_120 ) ) {
F_61 ( V_4 , L_21 ) ;
return F_62 ( V_1 -> V_120 ) ;
}
F_66 ( V_1 -> V_120 ) ;
V_1 -> V_121 = F_65 ( V_4 , L_22 ) ;
if ( F_60 ( V_1 -> V_121 ) ) {
F_61 ( V_4 , L_23 ) ;
return F_62 ( V_1 -> V_121 ) ;
}
F_66 ( V_1 -> V_121 ) ;
V_109 -> V_122 = F_67 ( V_4 , NULL , V_1 ,
& V_123 ) ;
if ( F_60 ( V_109 -> V_122 ) )
return F_62 ( V_109 -> V_122 ) ;
V_62 = F_68 ( V_104 , 0 ) ;
if ( V_62 < 0 ) {
F_61 ( V_4 , L_24 ) ;
return V_62 ;
}
V_112 = F_69 ( V_4 , V_62 , F_34 ,
F_35 , V_124 ,
L_25 , V_1 ) ;
if ( V_112 ) {
F_61 ( V_4 , L_26 ) ;
return V_112 ;
}
F_70 ( V_71 , & V_125 ) ;
V_112 = F_71 ( V_106 , V_71 , & V_126 ,
V_127 , L_27 ) ;
if ( V_112 ) {
F_61 ( V_20 -> V_4 , L_28 ) ;
return V_112 ;
}
V_71 -> V_128 = F_27 ( 0 ) ;
F_22 ( L_29 ) ;
F_16 ( V_20 -> V_22 , V_41 , 0xffff , 0x100 ) ;
F_16 ( V_20 -> V_22 , V_42 , 0xff << 8 , 0 ) ;
F_72 ( V_1 -> V_116 ) ;
F_72 ( V_1 -> V_117 ) ;
F_72 ( V_1 -> V_118 ) ;
F_30 ( F_27 ( 15 ) , F_27 ( 15 ) ,
V_1 -> V_10 + V_129 ) ;
F_30 ( F_27 ( 15 ) , F_27 ( 15 ) ,
V_1 -> V_10 + V_130 ) ;
F_8 ( V_1 , V_43 , 0 ) ;
F_28 ( 20 ) ;
F_8 ( V_1 , V_44 , 0xff ) ;
F_8 ( V_1 , V_58 ,
V_131 ) ;
F_8 ( V_1 , V_61 ,
V_131 ) ;
V_109 -> V_132 = F_38 ;
V_109 -> V_133 = & V_134 ;
V_109 -> V_135 = L_30 ;
V_109 -> V_136 = V_1 ;
V_109 -> V_137 = V_138 ;
V_109 -> V_139 = V_140 ;
V_112 = F_73 ( V_104 , V_71 , & V_1 -> V_109 ) ;
if ( V_112 )
return V_112 ;
F_22 ( L_31 ) ;
return 0 ;
}
static void F_74 ( struct V_98 * V_4 , struct V_98 * V_102 ,
void * V_8 )
{
F_75 ( V_4 ) ;
}
static int F_76 ( struct V_103 * V_104 )
{
return F_77 ( & V_104 -> V_4 , & V_141 ) ;
}
static int F_78 ( struct V_103 * V_104 )
{
F_79 ( & V_104 -> V_4 , & V_141 ) ;
return 0 ;
}
