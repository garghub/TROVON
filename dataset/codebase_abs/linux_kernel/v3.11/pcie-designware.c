static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static inline int F_2 ( void * V_5 , int V_6 , int V_7 , T_1 * V_8 )
{
* V_8 = F_3 ( V_5 ) ;
if ( V_7 == 1 )
* V_8 = ( * V_8 >> ( 8 * ( V_6 & 3 ) ) ) & 0xff ;
else if ( V_7 == 2 )
* V_8 = ( * V_8 >> ( 8 * ( V_6 & 3 ) ) ) & 0xffff ;
else if ( V_7 != 4 )
return V_9 ;
return V_10 ;
}
static inline int F_4 ( void * V_5 , int V_6 , int V_7 , T_1 V_8 )
{
if ( V_7 == 4 )
F_5 ( V_8 , V_5 ) ;
else if ( V_7 == 2 )
F_6 ( V_8 , V_5 + ( V_6 & 2 ) ) ;
else if ( V_7 == 1 )
F_7 ( V_8 , V_5 + ( V_6 & 3 ) ) ;
else
return V_9 ;
return V_10 ;
}
static void F_8 ( struct V_1 * V_11 , bool V_12 )
{
T_1 V_8 ;
if ( V_12 ) {
V_8 = F_3 ( V_11 -> V_13 + V_14 ) ;
V_8 |= V_15 ;
F_5 ( V_8 , V_11 -> V_13 + V_14 ) ;
} else {
V_8 = F_3 ( V_11 -> V_13 + V_14 ) ;
V_8 &= ~ V_15 ;
F_5 ( V_8 , V_11 -> V_13 + V_14 ) ;
}
}
static void F_9 ( struct V_1 * V_11 , bool V_12 )
{
T_1 V_8 ;
if ( V_12 ) {
V_8 = F_3 ( V_11 -> V_13 + V_16 ) ;
V_8 |= V_15 ;
F_5 ( V_8 , V_11 -> V_13 + V_16 ) ;
} else {
V_8 = F_3 ( V_11 -> V_13 + V_16 ) ;
V_8 &= ~ V_15 ;
F_5 ( V_8 , V_11 -> V_13 + V_16 ) ;
}
}
static inline void F_10 ( struct V_1 * V_11 , void * V_17 , T_1 * V_8 )
{
F_9 ( V_11 , true ) ;
* V_8 = F_3 ( V_17 ) ;
F_9 ( V_11 , false ) ;
return;
}
static inline void F_11 ( struct V_1 * V_11 , T_1 V_8 , void * V_17 )
{
F_8 ( V_11 , true ) ;
F_5 ( V_8 , V_17 ) ;
F_8 ( V_11 , false ) ;
return;
}
static int F_12 ( struct V_1 * V_11 , int V_6 , int V_7 ,
T_1 * V_8 )
{
int V_18 ;
F_9 ( V_11 , true ) ;
V_18 = F_2 ( V_11 -> V_17 + ( V_6 & ~ 0x3 ) , V_6 , V_7 , V_8 ) ;
F_9 ( V_11 , false ) ;
return V_18 ;
}
static int F_13 ( struct V_1 * V_11 , int V_6 , int V_7 ,
T_1 V_8 )
{
int V_18 ;
F_8 ( V_11 , true ) ;
V_18 = F_4 ( V_11 -> V_17 + ( V_6 & ~ 0x3 ) , V_6 , V_7 , V_8 ) ;
F_8 ( V_11 , false ) ;
return V_18 ;
}
static void F_14 ( struct V_1 * V_11 , T_1 V_19 )
{
T_1 V_8 ;
void T_2 * V_17 = V_11 -> V_17 ;
V_8 = V_20 | V_21 ;
F_11 ( V_11 , V_8 , V_17 + V_22 ) ;
F_11 ( V_11 , V_11 -> V_23 , V_17 + V_24 ) ;
F_11 ( V_11 , ( V_11 -> V_23 >> 32 ) , V_17 + V_25 ) ;
F_11 ( V_11 , V_11 -> V_23 + V_11 -> V_26 . V_27 - 1 ,
V_17 + V_28 ) ;
F_11 ( V_11 , V_19 , V_17 + V_29 ) ;
F_11 ( V_11 , 0 , V_17 + V_30 ) ;
F_11 ( V_11 , V_31 , V_17 + V_32 ) ;
V_8 = V_33 ;
F_11 ( V_11 , V_8 , V_17 + V_34 ) ;
}
static void F_15 ( struct V_1 * V_11 , T_1 V_19 )
{
T_1 V_8 ;
void T_2 * V_17 = V_11 -> V_17 ;
V_8 = V_20 | V_35 ;
F_11 ( V_11 , V_8 , V_17 + V_22 ) ;
F_11 ( V_11 , V_36 , V_17 + V_32 ) ;
V_8 = V_33 ;
F_11 ( V_11 , V_8 , V_17 + V_34 ) ;
F_11 ( V_11 , V_11 -> V_37 , V_17 + V_24 ) ;
F_11 ( V_11 , ( V_11 -> V_37 >> 32 ) , V_17 + V_25 ) ;
F_11 ( V_11 , V_11 -> V_37 + V_11 -> V_26 . V_38 - 1 ,
V_17 + V_28 ) ;
F_11 ( V_11 , V_19 , V_17 + V_29 ) ;
F_11 ( V_11 , 0 , V_17 + V_30 ) ;
}
static void F_16 ( struct V_1 * V_11 )
{
T_1 V_8 ;
void T_2 * V_17 = V_11 -> V_17 ;
V_8 = V_20 | V_21 ;
F_11 ( V_11 , V_8 , V_17 + V_22 ) ;
F_11 ( V_11 , V_39 , V_17 + V_32 ) ;
V_8 = V_33 ;
F_11 ( V_11 , V_8 , V_17 + V_34 ) ;
F_11 ( V_11 , V_11 -> V_40 , V_17 + V_24 ) ;
F_11 ( V_11 , ( V_11 -> V_40 >> 32 ) , V_17 + V_25 ) ;
F_11 ( V_11 , V_11 -> V_40 + V_11 -> V_26 . V_41 - 1 ,
V_17 + V_28 ) ;
F_11 ( V_11 , V_11 -> V_26 . V_42 ,
V_17 + V_29 ) ;
F_11 ( V_11 , F_17 ( V_11 -> V_26 . V_42 ) ,
V_17 + V_30 ) ;
}
static void F_18 ( struct V_1 * V_11 )
{
T_1 V_8 ;
void T_2 * V_17 = V_11 -> V_17 ;
V_8 = V_20 | V_35 ;
F_11 ( V_11 , V_8 , V_17 + V_22 ) ;
F_11 ( V_11 , V_43 , V_17 + V_32 ) ;
V_8 = V_33 ;
F_11 ( V_11 , V_8 , V_17 + V_34 ) ;
F_11 ( V_11 , V_11 -> V_44 , V_17 + V_24 ) ;
F_11 ( V_11 , ( V_11 -> V_44 >> 32 ) , V_17 + V_25 ) ;
F_11 ( V_11 , V_11 -> V_44 + V_11 -> V_26 . V_45 - 1 ,
V_17 + V_28 ) ;
F_11 ( V_11 , V_11 -> V_26 . V_46 ,
V_17 + V_29 ) ;
F_11 ( V_11 , F_17 ( V_11 -> V_26 . V_46 ) ,
V_17 + V_30 ) ;
}
static int F_19 ( struct V_1 * V_11 , struct V_47 * V_48 ,
T_1 V_49 , int V_6 , int V_7 , T_1 * V_8 )
{
int V_18 = V_10 ;
T_1 V_50 , V_19 ;
V_19 = F_20 ( V_48 -> V_51 ) | F_21 ( F_22 ( V_49 ) ) |
F_23 ( F_24 ( V_49 ) ) ;
V_50 = V_6 & ~ 0x3 ;
if ( V_48 -> V_52 -> V_51 == V_11 -> V_53 ) {
F_14 ( V_11 , V_19 ) ;
V_18 = F_2 ( V_11 -> V_54 + V_50 , V_6 , V_7 , V_8 ) ;
F_16 ( V_11 ) ;
} else {
F_15 ( V_11 , V_19 ) ;
V_18 = F_2 ( V_11 -> V_55 + V_50 , V_6 , V_7 , V_8 ) ;
F_18 ( V_11 ) ;
}
return V_18 ;
}
static int F_25 ( struct V_1 * V_11 , struct V_47 * V_48 ,
T_1 V_49 , int V_6 , int V_7 , T_1 V_8 )
{
int V_18 = V_10 ;
T_1 V_50 , V_19 ;
V_19 = F_20 ( V_48 -> V_51 ) | F_21 ( F_22 ( V_49 ) ) |
F_23 ( F_24 ( V_49 ) ) ;
V_50 = V_6 & ~ 0x3 ;
if ( V_48 -> V_52 -> V_51 == V_11 -> V_53 ) {
F_14 ( V_11 , V_19 ) ;
V_18 = F_4 ( V_11 -> V_54 + V_50 , V_6 , V_7 , V_8 ) ;
F_16 ( V_11 ) ;
} else {
F_15 ( V_11 , V_19 ) ;
V_18 = F_4 ( V_11 -> V_55 + V_50 , V_6 , V_7 , V_8 ) ;
F_18 ( V_11 ) ;
}
return V_18 ;
}
static int F_26 ( int V_56 , struct V_2 * V_3 )
{
struct V_1 * V_11 ;
V_11 = F_1 ( V_3 ) ;
if ( ! V_11 )
return 0 ;
if ( V_57 < V_58 && V_11 -> V_26 . V_45 > 0 ) {
V_3 -> V_59 = V_57 - V_11 -> V_26 . V_46 ;
F_27 ( V_3 -> V_59 , V_11 -> V_60 . V_61 ) ;
V_57 += V_62 ;
F_28 ( & V_3 -> V_63 , & V_11 -> V_60 ,
V_3 -> V_59 ) ;
}
V_3 -> V_64 = V_11 -> V_65 . V_61 - V_11 -> V_26 . V_42 ;
F_28 ( & V_3 -> V_63 , & V_11 -> V_65 , V_3 -> V_64 ) ;
return 1 ;
}
static int F_29 ( struct V_1 * V_11 )
{
T_1 V_8 = F_3 ( V_11 -> V_13 + V_66 ) ;
if ( V_8 == V_67 )
return 1 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_11 ,
struct V_47 * V_48 , int V_68 )
{
if ( V_48 -> V_51 != V_11 -> V_53 ) {
if ( ! F_29 ( V_11 ) )
return 0 ;
}
if ( V_48 -> V_51 == V_11 -> V_53 && V_68 > 0 )
return 0 ;
if ( V_48 -> V_69 == V_11 -> V_53 && V_68 > 0 )
return 0 ;
return 1 ;
}
static int F_31 ( struct V_47 * V_48 , T_1 V_49 , int V_6 ,
int V_7 , T_1 * V_8 )
{
struct V_1 * V_11 = F_1 ( V_48 -> V_70 ) ;
unsigned long V_71 ;
int V_18 ;
if ( ! V_11 ) {
F_32 () ;
return - V_72 ;
}
if ( F_30 ( V_11 , V_48 , F_22 ( V_49 ) ) == 0 ) {
* V_8 = 0xffffffff ;
return V_73 ;
}
F_33 ( & V_11 -> V_74 , V_71 ) ;
if ( V_48 -> V_51 != V_11 -> V_53 )
V_18 = F_19 ( V_11 , V_48 , V_49 ,
V_6 , V_7 , V_8 ) ;
else
V_18 = F_12 ( V_11 , V_6 , V_7 , V_8 ) ;
F_34 ( & V_11 -> V_74 , V_71 ) ;
return V_18 ;
}
static int F_35 ( struct V_47 * V_48 , T_1 V_49 ,
int V_6 , int V_7 , T_1 V_8 )
{
struct V_1 * V_11 = F_1 ( V_48 -> V_70 ) ;
unsigned long V_71 ;
int V_18 ;
if ( ! V_11 ) {
F_32 () ;
return - V_72 ;
}
if ( F_30 ( V_11 , V_48 , F_22 ( V_49 ) ) == 0 )
return V_73 ;
F_33 ( & V_11 -> V_74 , V_71 ) ;
if ( V_48 -> V_51 != V_11 -> V_53 )
V_18 = F_25 ( V_11 , V_48 , V_49 ,
V_6 , V_7 , V_8 ) ;
else
V_18 = F_13 ( V_11 , V_6 , V_7 , V_8 ) ;
F_34 ( & V_11 -> V_74 , V_71 ) ;
return V_18 ;
}
static struct V_47 * F_36 ( int V_56 ,
struct V_2 * V_3 )
{
struct V_47 * V_48 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
if ( V_11 ) {
V_11 -> V_53 = V_3 -> V_75 ;
V_48 = F_37 ( NULL , V_3 -> V_75 , & V_76 ,
V_3 , & V_3 -> V_63 ) ;
} else {
V_48 = NULL ;
F_32 () ;
}
return V_48 ;
}
static int F_38 ( const struct V_77 * V_68 , T_3 V_78 , T_3 V_79 )
{
struct V_1 * V_11 = F_1 ( V_68 -> V_48 -> V_70 ) ;
return V_11 -> V_80 ;
}
static void F_39 ( struct V_1 * V_11 )
{
struct V_81 * V_26 = & V_11 -> V_26 ;
void T_2 * V_17 = V_11 -> V_17 ;
T_1 V_8 ;
T_1 V_82 ;
T_1 V_83 ;
F_10 ( V_11 , V_17 + V_84 , & V_8 ) ;
V_8 &= ~ V_85 ;
V_8 |= V_86 ;
F_11 ( V_11 , V_8 , V_17 + V_84 ) ;
F_10 ( V_11 , V_17 + V_87 , & V_8 ) ;
V_8 &= ~ V_88 ;
V_8 |= V_89 ;
F_11 ( V_11 , V_8 , V_17 + V_87 ) ;
F_11 ( V_11 , 0x00000004 , V_17 + V_90 ) ;
F_11 ( V_11 , 0x00000004 , V_17 + V_91 ) ;
F_10 ( V_11 , V_17 + V_92 , & V_8 ) ;
V_8 &= 0xffff00ff ;
V_8 |= 0x00000100 ;
F_11 ( V_11 , V_8 , V_17 + V_92 ) ;
F_10 ( V_11 , V_17 + V_93 , & V_8 ) ;
V_8 &= 0xff000000 ;
V_8 |= 0x00010100 ;
F_11 ( V_11 , V_8 , V_17 + V_93 ) ;
V_82 = ( ( T_1 ) V_11 -> V_40 & 0xfff00000 ) >> 16 ;
V_83 = ( V_26 -> V_41 + ( T_1 ) V_11 -> V_40 ) & 0xfff00000 ;
V_8 = V_83 | V_82 ;
F_11 ( V_11 , V_8 , V_17 + V_94 ) ;
F_10 ( V_11 , V_17 + V_95 , & V_8 ) ;
V_8 &= 0xffff0000 ;
V_8 |= V_96 | V_97 |
V_98 | V_99 ;
F_11 ( V_11 , V_8 , V_17 + V_95 ) ;
}
static void F_40 ( struct V_1 * V_11 )
{
T_1 V_8 ;
void T_2 * V_13 = V_11 -> V_13 ;
V_8 = F_3 ( V_13 + V_100 ) ;
V_8 &= ~ V_101 ;
F_5 ( V_8 , V_13 + V_100 ) ;
F_5 ( 0 , V_13 + V_102 ) ;
F_5 ( 0 , V_13 + V_103 ) ;
F_5 ( 0 , V_13 + V_104 ) ;
}
static void F_41 ( struct V_1 * V_11 )
{
T_1 V_8 ;
void T_2 * V_13 = V_11 -> V_13 ;
void T_2 * V_105 = V_11 -> V_105 ;
V_8 = F_3 ( V_13 + V_100 ) ;
V_8 |= V_101 ;
F_5 ( V_8 , V_13 + V_100 ) ;
F_5 ( 1 , V_13 + V_103 ) ;
F_5 ( 1 , V_13 + V_104 ) ;
F_5 ( 1 , V_13 + V_106 ) ;
F_5 ( 0 , V_13 + V_106 ) ;
F_5 ( 1 , V_105 + V_107 ) ;
}
static void F_42 ( struct V_1 * V_11 )
{
void T_2 * V_105 = V_11 -> V_105 ;
F_5 ( 0 , V_105 + V_107 ) ;
F_5 ( 1 , V_105 + V_108 ) ;
}
static void F_43 ( struct V_1 * V_11 )
{
void T_2 * V_13 = V_11 -> V_13 ;
void T_2 * V_105 = V_11 -> V_105 ;
F_5 ( 0 , V_105 + V_108 ) ;
F_5 ( 1 , V_13 + V_102 ) ;
F_5 ( 0 , V_105 + V_109 ) ;
F_5 ( 0 , V_105 + V_110 ) ;
F_5 ( 0 , V_105 + V_111 ) ;
F_5 ( 0 , V_105 + V_112 ) ;
}
static void F_44 ( struct V_1 * V_11 )
{
void T_2 * V_113 = V_11 -> V_113 ;
F_5 ( 0x29 , V_113 + V_114 ) ;
F_5 ( 0xd5 , V_113 + V_115 ) ;
F_5 ( 0x14 , V_113 + V_116 ) ;
F_5 ( 0x12 , V_113 + V_117 ) ;
F_5 ( 0x7f , V_113 + V_118 ) ;
F_5 ( 0x0 , V_113 + V_119 ) ;
F_5 ( 0xe7 , V_113 + V_120 ) ;
F_5 ( 0x82 , V_113 + V_121 ) ;
F_5 ( 0x82 , V_113 + V_122 ) ;
F_5 ( 0x82 , V_113 + V_123 ) ;
F_5 ( 0x82 , V_113 + V_124 ) ;
F_5 ( 0x39 , V_113 + V_119 ) ;
F_5 ( 0x39 , V_113 + V_125 ) ;
F_5 ( 0x39 , V_113 + V_126 ) ;
F_5 ( 0x39 , V_113 + V_127 ) ;
F_5 ( 0x20 , V_113 + V_128 ) ;
F_5 ( 0xa0 , V_113 + V_129 ) ;
F_5 ( 0xa0 , V_113 + V_130 ) ;
F_5 ( 0xa0 , V_113 + V_131 ) ;
}
static void F_45 ( struct V_1 * V_11 )
{
if ( V_11 -> V_132 >= 0 )
F_46 ( V_11 -> V_68 , V_11 -> V_132 ,
V_133 , L_1 ) ;
return;
}
static int F_47 ( struct V_1 * V_11 )
{
T_1 V_8 ;
int V_134 = 0 ;
void T_2 * V_13 = V_11 -> V_13 ;
void T_2 * V_105 = V_11 -> V_105 ;
void T_2 * V_113 = V_11 -> V_113 ;
if ( F_29 ( V_11 ) ) {
F_48 ( V_11 -> V_68 , L_2 ) ;
return 0 ;
}
F_40 ( V_11 ) ;
F_42 ( V_11 ) ;
F_43 ( V_11 ) ;
F_44 ( V_11 ) ;
F_5 ( 1 , V_105 + V_109 ) ;
F_49 ( 500 ) ;
F_5 ( 0 , V_105 + V_109 ) ;
F_41 ( V_11 ) ;
F_39 ( V_11 ) ;
F_45 ( V_11 ) ;
F_5 ( V_67 , V_13 + V_135 ) ;
while ( ! F_29 ( V_11 ) ) {
F_50 ( 100 ) ;
V_134 ++ ;
if ( V_134 == 10 ) {
while ( F_3 ( V_113 + V_136 ) == 0 ) {
V_8 = F_3 ( V_105 + V_136 ) ;
F_51 ( V_11 -> V_68 , L_3 , V_8 ) ;
}
F_48 ( V_11 -> V_68 , L_4 ) ;
return - V_72 ;
}
}
F_51 ( V_11 -> V_68 , L_5 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_11 )
{
T_1 V_8 ;
void T_2 * V_13 = V_11 -> V_13 ;
V_8 = F_3 ( V_13 + V_137 ) ;
F_5 ( V_8 , V_13 + V_137 ) ;
return;
}
static void F_53 ( struct V_1 * V_11 )
{
T_1 V_8 ;
void T_2 * V_13 = V_11 -> V_13 ;
V_8 = V_138 | V_139 |
V_140 | V_141 ,
F_5 ( V_8 , V_13 + V_142 ) ;
return;
}
static T_4 F_54 ( int V_80 , void * V_143 )
{
struct V_1 * V_11 = V_143 ;
F_52 ( V_11 ) ;
return V_144 ;
}
static void F_55 ( struct V_1 * V_11 )
{
F_53 ( V_11 ) ;
return;
}
static void F_56 ( struct V_1 * V_11 )
{
struct V_81 * V_26 = & V_11 -> V_26 ;
T_1 V_8 ;
V_11 -> V_23 = V_11 -> V_145 . V_61 ;
V_11 -> V_37 = V_11 -> V_145 . V_61 + V_26 -> V_27 ;
V_11 -> V_44 = V_11 -> V_60 . V_61 ;
V_11 -> V_40 = V_11 -> V_65 . V_61 ;
F_47 ( V_11 ) ;
F_13 ( V_11 , V_90 , 4 , 0 ) ;
F_13 ( V_11 , V_146 , 2 , V_147 ) ;
F_12 ( V_11 , V_87 , 4 , & V_8 ) ;
V_8 |= V_148 ;
F_13 ( V_11 , V_87 , 4 , V_8 ) ;
F_55 ( V_11 ) ;
}
static int F_57 ( struct V_1 * V_11 , struct V_149 * V_150 )
{
struct V_151 * V_13 ;
struct V_151 * V_113 ;
struct V_151 * V_105 ;
int V_18 ;
V_13 = F_58 ( V_150 , V_152 , 0 ) ;
if ( ! V_13 ) {
F_48 ( & V_150 -> V_68 , L_6 ) ;
return - V_72 ;
}
V_11 -> V_13 = F_59 ( & V_150 -> V_68 , V_13 ) ;
if ( F_60 ( V_11 -> V_13 ) )
return F_61 ( V_11 -> V_13 ) ;
V_113 = F_58 ( V_150 , V_152 , 1 ) ;
if ( ! V_113 ) {
F_48 ( & V_150 -> V_68 , L_7 ) ;
return - V_72 ;
}
V_11 -> V_113 = F_59 ( & V_150 -> V_68 , V_113 ) ;
if ( F_60 ( V_11 -> V_113 ) )
return F_61 ( V_11 -> V_113 ) ;
V_105 = F_58 ( V_150 , V_152 , 2 ) ;
if ( ! V_105 ) {
F_48 ( & V_150 -> V_68 , L_8 ) ;
return - V_72 ;
}
V_11 -> V_105 = F_59 ( & V_150 -> V_68 , V_105 ) ;
if ( F_60 ( V_11 -> V_105 ) )
return F_61 ( V_11 -> V_105 ) ;
V_11 -> V_80 = F_62 ( V_150 , 1 ) ;
if ( ! V_11 -> V_80 ) {
F_48 ( & V_150 -> V_68 , L_9 ) ;
return - V_153 ;
}
V_18 = F_63 ( & V_150 -> V_68 , V_11 -> V_80 , F_54 ,
V_154 , L_10 , V_11 ) ;
if ( V_18 ) {
F_48 ( & V_150 -> V_68 , L_11 ) ;
return V_18 ;
}
V_11 -> V_17 = F_64 ( & V_150 -> V_68 , V_11 -> V_145 . V_61 ,
F_65 ( & V_11 -> V_145 ) ) ;
if ( ! V_11 -> V_17 ) {
F_48 ( & V_150 -> V_68 , L_12 ) ;
return - V_155 ;
}
V_11 -> V_53 = - 1 ;
F_66 ( & V_11 -> V_74 ) ;
F_56 ( V_11 ) ;
V_11 -> V_54 = F_64 ( & V_150 -> V_68 , V_11 -> V_23 ,
V_11 -> V_26 . V_27 ) ;
if ( ! V_11 -> V_54 ) {
F_48 ( V_11 -> V_68 , L_13 ) ;
return - V_155 ;
}
V_11 -> V_55 = F_64 ( & V_150 -> V_68 , V_11 -> V_37 ,
V_11 -> V_26 . V_38 ) ;
if ( ! V_11 -> V_55 ) {
F_48 ( V_11 -> V_68 , L_12 ) ;
return - V_155 ;
}
return 0 ;
}
static int T_5 F_67 ( struct V_149 * V_150 )
{
struct V_1 * V_11 ;
struct V_156 * V_157 = V_150 -> V_68 . V_158 ;
struct V_159 V_160 ;
struct V_161 V_162 ;
int V_18 ;
V_11 = F_68 ( & V_150 -> V_68 , sizeof( * V_11 ) , V_163 ) ;
if ( ! V_11 ) {
F_48 ( & V_150 -> V_68 , L_14 ) ;
return - V_155 ;
}
V_11 -> V_68 = & V_150 -> V_68 ;
if ( F_69 ( & V_162 , V_157 ) ) {
F_48 ( & V_150 -> V_68 , L_15 ) ;
return - V_72 ;
}
F_70 (&parser, &range) {
unsigned long V_164 = V_160 . V_71 & V_165 ;
if ( V_164 == V_166 ) {
F_71 ( & V_160 , V_157 , & V_11 -> V_60 ) ;
V_11 -> V_60 . V_167 = L_16 ;
V_11 -> V_60 . V_61 = F_72 ( V_168 ,
V_169 ,
V_160 . V_170 + V_57 ) ;
V_11 -> V_60 . V_171 = F_73 ( V_168 ,
V_172 ,
V_160 . V_170 + V_160 . V_7
+ V_57 ) ;
V_11 -> V_26 . V_45 = F_65 ( & V_11 -> V_60 ) ;
V_11 -> V_26 . V_46 = V_160 . V_170 ;
}
if ( V_164 == V_152 ) {
F_71 ( & V_160 , V_157 , & V_11 -> V_65 ) ;
V_11 -> V_65 . V_167 = L_17 ;
V_11 -> V_26 . V_41 = F_65 ( & V_11 -> V_65 ) ;
V_11 -> V_26 . V_42 = V_160 . V_170 ;
}
if ( V_164 == 0 ) {
F_71 ( & V_160 , V_157 , & V_11 -> V_145 ) ;
V_11 -> V_26 . V_27 = F_65 ( & V_11 -> V_145 ) / 2 ;
V_11 -> V_26 . V_38 = F_65 ( & V_11 -> V_145 ) / 2 ;
}
}
V_11 -> V_132 = F_74 ( V_157 , L_18 , 0 ) ;
V_11 -> V_173 = F_75 ( & V_150 -> V_68 , L_19 ) ;
if ( F_60 ( V_11 -> V_173 ) ) {
F_48 ( & V_150 -> V_68 , L_20 ) ;
return F_61 ( V_11 -> V_173 ) ;
}
V_18 = F_76 ( V_11 -> V_173 ) ;
if ( V_18 )
return V_18 ;
V_11 -> V_174 = F_75 ( & V_150 -> V_68 , L_21 ) ;
if ( F_60 ( V_11 -> V_174 ) ) {
F_48 ( & V_150 -> V_68 , L_22 ) ;
V_18 = F_61 ( V_11 -> V_174 ) ;
goto V_175;
}
V_18 = F_76 ( V_11 -> V_174 ) ;
if ( V_18 )
goto V_175;
V_18 = F_57 ( V_11 , V_150 ) ;
if ( V_18 < 0 )
goto V_176;
V_11 -> V_177 = V_178 . V_179 ;
V_178 . V_179 = 1 ;
V_178 . V_4 = ( void * * ) & V_11 ;
F_77 ( & V_178 ) ;
F_78 () ;
#ifdef F_79
V_178 . V_180 ++ ;
#endif
F_80 ( V_150 , V_11 ) ;
return 0 ;
V_176:
F_81 ( V_11 -> V_174 ) ;
V_175:
F_81 ( V_11 -> V_173 ) ;
return V_18 ;
}
static int T_6 F_82 ( struct V_149 * V_150 )
{
struct V_1 * V_11 = F_83 ( V_150 ) ;
F_81 ( V_11 -> V_174 ) ;
F_81 ( V_11 -> V_173 ) ;
return 0 ;
}
static int F_84 ( unsigned long V_5 , unsigned int V_181 ,
struct V_182 * V_183 )
{
unsigned long V_184 = F_85 ( V_183 ) ;
unsigned long V_185 = * ( unsigned long * ) V_184 ;
F_86 ( 1 , L_23 ) ;
if ( ( V_185 & 0x0c100000 ) == 0x04100000 ) {
int V_186 = ( V_185 >> 12 ) & 15 ;
unsigned long V_8 ;
if ( V_185 & 0x00400000 )
V_8 = 255 ;
else
V_8 = - 1 ;
V_183 -> V_187 [ V_186 ] = V_8 ;
V_183 -> V_188 += 4 ;
return 0 ;
}
if ( ( V_185 & 0x0e100090 ) == 0x00100090 ) {
int V_186 = ( V_185 >> 12 ) & 15 ;
V_183 -> V_187 [ V_186 ] = - 1 ;
V_183 -> V_188 += 4 ;
return 0 ;
}
return 1 ;
}
static int T_5 F_87 ( void )
{
F_88 ( 16 + 6 , F_84 , V_189 , 0 ,
L_24 ) ;
F_89 ( & V_190 , F_67 ) ;
return 0 ;
}
