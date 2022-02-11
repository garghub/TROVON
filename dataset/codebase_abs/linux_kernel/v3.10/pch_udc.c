static inline T_1 F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
unsigned long V_5 , unsigned long V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned long V_6 )
{
F_3 ( V_2 , F_1 ( V_2 , V_3 ) | V_6 , V_3 ) ;
}
static inline void F_6 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned long V_6 )
{
F_3 ( V_2 , F_1 ( V_2 , V_3 ) & ~ ( V_6 ) , V_3 ) ;
}
static inline T_1 F_7 ( struct V_7 * V_8 , unsigned long V_3 )
{
return F_2 ( V_8 -> V_2 -> V_4 + V_8 -> V_9 + V_3 ) ;
}
static inline void F_8 ( struct V_7 * V_8 ,
unsigned long V_5 , unsigned long V_3 )
{
F_4 ( V_5 , V_8 -> V_2 -> V_4 + V_8 -> V_9 + V_3 ) ;
}
static inline void F_9 ( struct V_7 * V_8 ,
unsigned long V_3 ,
unsigned long V_6 )
{
F_8 ( V_8 , F_7 ( V_8 , V_3 ) | V_6 , V_3 ) ;
}
static inline void F_10 ( struct V_7 * V_8 ,
unsigned long V_3 ,
unsigned long V_6 )
{
F_8 ( V_8 , F_7 ( V_8 , V_3 ) & ~ ( V_6 ) , V_3 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_10 = 200 ;
while ( ( F_1 ( V_2 , V_11 ) & V_12 )
&& -- V_10 )
F_12 () ;
if ( ! V_10 )
F_13 ( & V_2 -> V_13 -> V_2 , L_1 , V_14 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned long V_5 ,
unsigned int V_8 )
{
unsigned long V_3 = F_15 ( V_8 ) ;
F_11 ( V_2 ) ;
F_3 ( V_2 , V_5 , V_3 ) ;
F_11 ( V_2 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 , unsigned int V_8 )
{
unsigned long V_3 = F_15 ( V_8 ) ;
F_11 ( V_2 ) ;
F_1 ( V_2 , V_3 ) ;
F_11 ( V_2 ) ;
return F_1 ( V_2 , V_3 ) ;
}
static inline void F_17 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_15 , V_16 ) ;
F_18 ( 1 ) ;
F_6 ( V_2 , V_15 , V_16 ) ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
T_1 V_17 = F_1 ( V_2 , V_18 ) ;
return ( V_17 & V_19 ) >> V_20 ;
}
static inline void F_20 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_21 , V_22 ) ;
}
static inline void F_21 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_21 , V_22 ) ;
}
static inline void F_22 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_15 , V_23 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_15 , V_16 ) ;
F_6 ( V_2 , V_15 , V_23 ) ;
F_18 ( 1 ) ;
F_6 ( V_2 , V_15 , V_16 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
F_6 ( V_2 , V_24 ,
V_25 | V_26 ) ;
F_5 ( V_2 , V_15 , V_16 ) ;
F_6 ( V_2 , V_15 , V_23 ) ;
F_18 ( 1 ) ;
F_6 ( V_2 , V_15 , V_16 ) ;
}
static inline void F_26 ( struct V_1 * V_2 ,
int V_27 )
{
if ( V_27 ) {
F_24 ( V_2 ) ;
V_2 -> V_28 = 1 ;
} else {
if ( V_2 -> V_29 && V_2 -> V_29 -> V_30 ) {
F_27 ( & V_2 -> V_31 ) ;
V_2 -> V_29 -> V_30 ( & V_2 -> V_32 ) ;
F_28 ( & V_2 -> V_31 ) ;
}
F_22 ( V_2 ) ;
V_2 -> V_28 = 0 ;
}
}
static void F_29 ( struct V_7 * V_8 )
{
if ( V_8 -> V_33 ) {
F_9 ( V_8 , V_34 , V_35 ) ;
F_9 ( V_8 , V_34 , V_36 ) ;
} else {
F_9 ( V_8 , V_34 , V_36 ) ;
}
}
static inline void F_30 ( struct V_7 * V_8 )
{
F_10 ( V_8 , V_34 , V_36 ) ;
F_9 ( V_8 , V_34 , V_37 ) ;
}
static inline void F_31 ( struct V_7 * V_8 ,
T_2 type )
{
F_8 ( V_8 , ( ( type << V_38 ) &
V_39 ) , V_34 ) ;
}
static void F_32 ( struct V_7 * V_8 ,
T_1 V_40 , T_1 V_41 )
{
T_1 V_42 ;
if ( V_41 ) {
V_42 = F_7 ( V_8 , V_43 ) ;
V_42 = ( V_42 & 0xffff0000 ) | ( V_40 & 0xffff ) ;
F_8 ( V_8 , V_42 , V_43 ) ;
} else {
V_42 = F_7 ( V_8 , V_44 ) ;
V_42 = ( V_40 << 16 ) | ( V_42 & 0xffff ) ;
F_8 ( V_8 , V_42 , V_44 ) ;
}
}
static void F_33 ( struct V_7 * V_8 , T_1 V_45 )
{
T_1 V_42 = F_7 ( V_8 , V_44 ) ;
V_42 = ( V_42 & 0xffff0000 ) | ( V_45 & 0xffff ) ;
F_8 ( V_8 , V_42 , V_44 ) ;
}
static inline void F_34 ( struct V_7 * V_8 , T_1 V_46 )
{
F_8 ( V_8 , V_46 , V_47 ) ;
}
static inline void F_35 ( struct V_7 * V_8 , T_1 V_46 )
{
F_8 ( V_8 , V_46 , V_48 ) ;
}
static inline void F_36 ( struct V_7 * V_8 )
{
F_9 ( V_8 , V_34 , V_49 ) ;
}
static inline void F_37 ( struct V_7 * V_8 )
{
F_9 ( V_8 , V_34 , V_50 ) ;
}
static inline void F_38 ( struct V_7 * V_8 )
{
F_10 ( V_8 , V_34 , V_50 ) ;
}
static inline void F_39 ( struct V_1 * V_2 , int V_51 )
{
if ( V_51 == V_52 )
F_5 ( V_2 , V_15 , V_53 ) ;
else if ( V_51 == V_54 )
F_5 ( V_2 , V_15 , V_55 ) ;
}
static inline void F_40 ( struct V_1 * V_2 , int V_51 )
{
if ( V_51 == V_52 )
F_6 ( V_2 , V_15 , V_53 ) ;
else if ( V_51 == V_54 )
F_6 ( V_2 , V_15 , V_55 ) ;
}
static inline void F_41 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_15 , V_56 ) ;
}
static inline void F_42 ( struct V_1 * V_2 ,
T_1 V_57 )
{
F_5 ( V_2 , V_24 , V_57 ) ;
}
static inline void F_43 ( struct V_1 * V_2 ,
T_1 V_57 )
{
F_6 ( V_2 , V_24 , V_57 ) ;
}
static inline void F_44 ( struct V_1 * V_2 ,
T_1 V_57 )
{
F_5 ( V_2 , V_58 , V_57 ) ;
}
static inline void F_45 ( struct V_1 * V_2 ,
T_1 V_57 )
{
F_6 ( V_2 , V_58 , V_57 ) ;
}
static inline T_1 F_46 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_59 ) ;
}
static inline void F_47 ( struct V_1 * V_2 ,
T_1 V_5 )
{
F_3 ( V_2 , V_5 , V_59 ) ;
}
static inline T_1 F_48 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_60 ) ;
}
static inline void F_49 ( struct V_1 * V_2 ,
T_1 V_5 )
{
F_3 ( V_2 , V_5 , V_60 ) ;
}
static inline T_1 F_50 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_18 ) ;
}
static inline T_1 F_51 ( struct V_7 * V_8 )
{
return F_7 ( V_8 , V_34 ) ;
}
static inline void F_52 ( struct V_7 * V_8 )
{
return F_8 ( V_8 , 0 , V_34 ) ;
}
static inline T_1 F_53 ( struct V_7 * V_8 )
{
return F_7 ( V_8 , V_61 ) ;
}
static inline void F_54 ( struct V_7 * V_8 ,
T_1 V_62 )
{
return F_8 ( V_8 , V_62 , V_61 ) ;
}
static inline void F_55 ( struct V_7 * V_8 )
{
F_9 ( V_8 , V_34 , V_63 ) ;
}
static void F_56 ( struct V_7 * V_8 )
{
unsigned int V_64 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! ( F_7 ( V_8 , V_34 ) & V_65 ) )
return;
if ( ! V_8 -> V_33 ) {
V_64 = 10000 ;
while ( ! ( F_53 ( V_8 ) & V_66 ) &&
-- V_64 )
F_57 ( 5 ) ;
if ( ! V_64 )
F_13 ( & V_2 -> V_13 -> V_2 , L_2 ,
V_14 ) ;
}
V_64 = 10000 ;
while ( ( F_51 ( V_8 ) & V_65 ) && -- V_64 ) {
F_9 ( V_8 , V_34 , V_37 ) ;
F_57 ( 5 ) ;
}
if ( ! V_64 )
F_13 ( & V_2 -> V_13 -> V_2 , L_3 ,
V_14 , V_8 -> V_67 , ( V_8 -> V_33 ? L_4 : L_5 ) ) ;
}
static void F_58 ( struct V_7 * V_8 , int V_51 )
{
if ( V_51 ) {
F_9 ( V_8 , V_34 , V_35 ) ;
return;
}
}
static void F_59 ( struct V_7 * V_8 ,
struct V_68 * V_69 ,
const struct V_70 * V_71 )
{
T_1 V_5 = 0 ;
T_1 V_72 = 0 ;
F_31 ( V_8 , V_71 -> V_73 ) ;
if ( V_8 -> V_33 )
V_72 = V_74 ;
else
V_72 = V_75 ;
F_32 ( V_8 , V_72 , V_8 -> V_33 ) ;
F_33 ( V_8 , F_60 ( V_71 ) ) ;
F_55 ( V_8 ) ;
F_58 ( V_8 , V_8 -> V_33 ) ;
V_5 = V_8 -> V_67 << V_76 | V_8 -> V_33 << V_77 |
( ( V_71 -> V_73 & V_78 ) <<
V_79 ) |
( V_69 -> V_80 << V_81 ) |
( V_69 -> V_82 << V_83 ) |
( V_69 -> V_84 << V_85 ) |
F_60 ( V_71 ) << V_86 ;
if ( V_8 -> V_33 )
F_14 ( V_8 -> V_2 , V_5 , F_61 ( V_8 -> V_67 ) ) ;
else
F_14 ( V_8 -> V_2 , V_5 , F_62 ( V_8 -> V_67 ) ) ;
}
static void F_63 ( struct V_7 * V_8 )
{
if ( V_8 -> V_33 ) {
F_8 ( V_8 , V_35 , V_34 ) ;
F_8 ( V_8 , V_63 , V_34 ) ;
F_9 ( V_8 , V_61 , V_87 ) ;
} else {
F_8 ( V_8 , V_63 , V_34 ) ;
}
F_8 ( V_8 , 0 , V_48 ) ;
}
static void F_64 ( struct V_7 * V_8 )
{
unsigned int V_10 = 10000 ;
while ( ( F_51 ( V_8 ) & V_36 ) && -- V_10 )
F_57 ( 5 ) ;
if ( ! V_10 )
F_13 ( & V_8 -> V_2 -> V_13 -> V_2 , L_1 , V_14 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( NULL == V_2 ) {
F_65 ( L_6 , V_14 ) ;
return;
}
F_3 ( V_2 , V_88 , V_89 ) ;
F_3 ( V_2 , V_88 | V_90 , V_89 ) ;
F_18 ( 1 ) ;
F_3 ( V_2 , V_88 , V_89 ) ;
F_3 ( V_2 , 0x00 , V_89 ) ;
F_18 ( 1 ) ;
F_5 ( V_2 , V_24 , V_91 ) ;
F_5 ( V_2 , V_59 , V_91 ) ;
F_5 ( V_2 , V_58 , V_92 ) ;
F_5 ( V_2 , V_60 , V_92 ) ;
if ( V_93 )
F_5 ( V_2 , V_21 , V_94 |
V_22 | V_95 ) ;
else
F_5 ( V_2 , V_21 , V_94 |
V_22 | V_96 ) ;
F_5 ( V_2 , V_15 ,
( V_97 << V_98 ) |
( V_99 << V_100 ) |
V_101 | V_102 |
V_103 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_24 , V_91 ) ;
F_5 ( V_2 , V_58 , V_92 ) ;
F_22 ( V_2 ) ;
}
static int F_67 ( struct V_104 * V_32 )
{
struct V_1 * V_2 ;
if ( ! V_32 )
return - V_105 ;
V_2 = F_68 ( V_32 , struct V_1 , V_32 ) ;
return F_19 ( V_2 ) ;
}
static int F_69 ( struct V_104 * V_32 )
{
struct V_1 * V_2 ;
unsigned long V_106 ;
if ( ! V_32 )
return - V_105 ;
V_2 = F_68 ( V_32 , struct V_1 , V_32 ) ;
F_70 ( & V_2 -> V_31 , V_106 ) ;
F_17 ( V_2 ) ;
F_71 ( & V_2 -> V_31 , V_106 ) ;
return 0 ;
}
static int F_72 ( struct V_104 * V_32 , int V_107 )
{
struct V_1 * V_2 ;
if ( ! V_32 )
return - V_105 ;
V_2 = F_68 ( V_32 , struct V_1 , V_32 ) ;
if ( V_107 )
F_21 ( V_2 ) ;
else
F_20 ( V_2 ) ;
return 0 ;
}
static int F_73 ( struct V_104 * V_32 , int V_108 )
{
struct V_1 * V_2 ;
if ( ! V_32 )
return - V_105 ;
V_2 = F_68 ( V_32 , struct V_1 , V_32 ) ;
if ( V_108 ) {
F_24 ( V_2 ) ;
} else {
if ( V_2 -> V_29 && V_2 -> V_29 -> V_30 ) {
F_27 ( & V_2 -> V_31 ) ;
V_2 -> V_29 -> V_30 ( & V_2 -> V_32 ) ;
F_28 ( & V_2 -> V_31 ) ;
}
F_22 ( V_2 ) ;
}
return 0 ;
}
static int F_74 ( struct V_104 * V_32 , int V_27 )
{
struct V_1 * V_2 ;
if ( ! V_32 )
return - V_105 ;
V_2 = F_68 ( V_32 , struct V_1 , V_32 ) ;
F_26 ( V_2 , V_27 ) ;
return 0 ;
}
static int F_75 ( struct V_104 * V_32 , unsigned int V_109 )
{
return - V_110 ;
}
static int F_76 ( struct V_1 * V_2 )
{
int V_111 = 0 ;
if ( V_2 -> V_112 . V_113 )
V_111 = F_77 ( V_2 -> V_112 . V_113 ) ? 1 : 0 ;
else
V_111 = - 1 ;
return V_111 ;
}
static void F_78 ( struct V_114 * V_115 )
{
struct V_116 * V_112 = F_68 ( V_115 ,
struct V_116 , V_117 ) ;
struct V_1 * V_2 =
F_68 ( V_112 , struct V_1 , V_112 ) ;
int V_118 = - 1 ;
int V_111 ;
int V_10 ;
if ( ! V_2 -> V_112 . V_113 )
return;
for ( V_10 = 0 ; V_10 < ( V_119 / V_120 ) ;
V_10 ++ ) {
V_111 = F_76 ( V_2 ) ;
if ( ( V_118 == V_111 ) && ( V_111 == 0 ) ) {
F_79 ( & V_2 -> V_13 -> V_2 , L_7 ) ;
if ( V_2 -> V_29
&& V_2 -> V_29 -> V_30 ) {
V_2 -> V_29 -> V_30 (
& V_2 -> V_32 ) ;
}
if ( V_2 -> V_112 . V_121 )
F_25 ( V_2 ) ;
else
F_24 ( V_2 ) ;
return;
}
V_118 = V_111 ;
F_18 ( V_120 ) ;
}
}
static void F_80 ( struct V_114 * V_115 )
{
struct V_116 * V_112 = F_68 ( V_115 ,
struct V_116 , V_122 ) ;
struct V_1 * V_2 =
F_68 ( V_112 , struct V_1 , V_112 ) ;
int V_111 ;
if ( ! V_2 -> V_112 . V_113 )
return;
F_18 ( V_120 ) ;
V_111 = F_76 ( V_2 ) ;
if ( V_111 == 1 ) {
F_79 ( & V_2 -> V_13 -> V_2 , L_8 ) ;
F_24 ( V_2 ) ;
return;
}
}
static T_3 F_81 ( int V_123 , void * V_42 )
{
struct V_1 * V_2 = (struct V_1 * ) V_42 ;
if ( ! V_2 -> V_112 . V_113 || ! V_2 -> V_112 . V_121 )
return V_124 ;
if ( F_76 ( V_2 ) )
F_82 ( & V_2 -> V_112 . V_122 ) ;
else
F_82 ( & V_2 -> V_112 . V_117 ) ;
return V_125 ;
}
static int F_83 ( struct V_1 * V_2 , int V_126 )
{
int V_127 ;
int V_128 = 0 ;
V_2 -> V_112 . V_113 = 0 ;
V_2 -> V_112 . V_121 = 0 ;
if ( V_126 <= - 1 )
return - V_105 ;
V_127 = F_84 ( V_126 ) ;
if ( ! V_127 ) {
F_65 ( L_9 ,
V_14 , V_126 ) ;
return - V_105 ;
}
V_127 = F_85 ( V_126 , L_10 ) ;
if ( V_127 ) {
F_65 ( L_11 ,
V_14 , V_126 , V_127 ) ;
return - V_105 ;
}
V_2 -> V_112 . V_113 = V_126 ;
F_86 ( V_126 ) ;
F_87 ( & V_2 -> V_112 . V_117 , F_78 ) ;
V_128 = F_88 ( V_126 ) ;
if ( V_128 > 0 ) {
F_89 ( V_128 , V_129 ) ;
V_127 = F_90 ( V_128 , F_81 , 0 ,
L_12 , V_2 ) ;
if ( ! V_127 ) {
V_2 -> V_112 . V_121 = V_128 ;
F_87 ( & V_2 -> V_112 . V_122 ,
F_80 ) ;
} else {
F_65 ( L_13 ,
V_14 , V_128 , V_127 ) ;
}
}
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
if ( V_2 -> V_112 . V_121 )
F_92 ( V_2 -> V_112 . V_121 , V_2 ) ;
if ( V_2 -> V_112 . V_113 )
F_93 ( V_2 -> V_112 . V_113 ) ;
}
static void F_94 ( struct V_7 * V_8 , struct V_130 * V_131 ,
int V_132 )
__releases( &dev->lock
static void F_95 ( struct V_7 * V_8 )
{
struct V_130 * V_131 ;
V_8 -> V_133 = 1 ;
while ( ! F_96 ( & V_8 -> V_134 ) ) {
V_131 = F_97 ( V_8 -> V_134 . V_135 , struct V_130 , V_134 ) ;
F_94 ( V_8 , V_131 , - V_136 ) ;
}
}
static void F_98 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
struct V_137 * V_138 = V_131 -> V_139 ;
unsigned V_140 = V_131 -> V_141 ;
T_4 V_142 ;
T_4 V_46 = ( T_4 ) V_138 -> V_135 ;
V_138 -> V_135 = 0x00 ;
for (; V_140 > 1 ; -- V_140 ) {
V_138 = F_99 ( V_46 ) ;
V_142 = ( T_4 ) V_138 -> V_135 ;
F_100 ( V_2 -> V_143 , V_138 , V_46 ) ;
V_138 -> V_135 = 0x00 ;
V_46 = V_142 ;
}
V_131 -> V_141 = 1 ;
}
static int F_101 ( struct V_7 * V_8 ,
struct V_130 * V_131 ,
unsigned long V_144 ,
T_5 V_145 )
{
struct V_137 * V_138 = V_131 -> V_139 , * V_146 ;
unsigned long V_147 = V_131 -> V_131 . V_148 , V_140 = 0 ;
T_4 V_149 ;
unsigned V_150 = 1 ;
if ( V_131 -> V_141 > 1 )
F_98 ( V_8 -> V_2 , V_131 ) ;
if ( V_131 -> V_151 == V_152 )
V_138 -> V_153 = V_131 -> V_131 . V_151 ;
else
V_138 -> V_153 = V_131 -> V_151 ;
V_138 -> V_132 = V_154 ;
for (; ; V_147 -= V_144 , ++ V_150 ) {
V_138 -> V_132 = V_154 | F_102 ( V_144 , V_147 ) ;
if ( V_147 <= V_144 )
break;
V_146 = V_138 ;
V_138 = F_103 ( V_8 -> V_2 -> V_143 , V_145 ,
& V_149 ) ;
if ( ! V_138 )
goto V_155;
V_140 += V_144 ;
V_138 -> V_153 = V_131 -> V_139 -> V_153 + V_140 ;
V_146 -> V_135 = V_149 ;
}
V_131 -> V_156 = V_138 ;
V_138 -> V_132 |= V_157 ;
V_138 -> V_135 = V_131 -> V_158 ;
V_131 -> V_141 = V_150 ;
return 0 ;
V_155:
if ( V_150 > 1 ) {
V_131 -> V_141 = V_150 ;
F_98 ( V_8 -> V_2 , V_131 ) ;
}
V_131 -> V_141 = 1 ;
return - V_159 ;
}
static int F_104 ( struct V_7 * V_8 , struct V_130 * V_131 ,
T_5 V_160 )
{
int V_161 ;
V_161 = F_101 ( V_8 , V_131 , V_8 -> V_8 . V_162 , V_160 ) ;
if ( V_161 ) {
F_65 ( L_14 , V_14 , V_161 ) ;
return V_161 ;
}
if ( V_8 -> V_33 )
V_131 -> V_139 -> V_132 = ( V_131 -> V_139 -> V_132 &
~ V_163 ) | V_164 ;
return 0 ;
}
static void F_105 ( struct V_7 * V_8 , struct V_130 * V_131 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_94 ( V_8 , V_131 , 0 ) ;
if ( V_2 -> V_165 ) {
F_41 ( V_2 ) ;
V_2 -> V_165 = 0 ;
}
if ( ! V_2 -> V_166 && V_2 -> V_167 ) {
F_56 ( & ( V_2 -> V_8 [ V_168 ] ) ) ;
V_2 -> V_167 = 0 ;
}
}
static void F_106 ( struct V_7 * V_8 ,
struct V_130 * V_131 )
{
struct V_137 * V_139 ;
F_40 ( V_8 -> V_2 , V_52 ) ;
V_139 = V_131 -> V_139 ;
while ( 1 ) {
V_139 -> V_132 = ( V_139 -> V_132 & ~ V_163 ) |
V_164 ;
if ( ( V_139 -> V_132 & V_157 ) == V_157 )
break;
V_139 = F_99 ( V_139 -> V_135 ) ;
}
F_35 ( V_8 , V_131 -> V_158 ) ;
V_131 -> V_169 = 1 ;
F_45 ( V_8 -> V_2 , V_170 << V_8 -> V_67 ) ;
F_39 ( V_8 -> V_2 , V_52 ) ;
F_56 ( V_8 ) ;
F_37 ( V_8 ) ;
}
static int F_107 ( struct V_171 * V_172 ,
const struct V_70 * V_71 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned long V_173 ;
if ( ! V_172 || ( V_172 -> V_174 == V_175 ) || ! V_71 ||
( V_71 -> V_176 != V_177 ) || ! V_71 -> V_178 )
return - V_105 ;
V_8 = F_68 ( V_172 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_29 || ( V_2 -> V_32 . V_179 == V_180 ) )
return - V_136 ;
F_70 ( & V_2 -> V_31 , V_173 ) ;
V_8 -> V_8 . V_71 = V_71 ;
V_8 -> V_133 = 0 ;
F_59 ( V_8 , & V_8 -> V_2 -> V_181 , V_71 ) ;
V_8 -> V_8 . V_162 = F_60 ( V_71 ) ;
F_45 ( V_8 -> V_2 , F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
F_71 ( & V_2 -> V_31 , V_173 ) ;
return 0 ;
}
static int F_109 ( struct V_171 * V_172 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned long V_173 ;
if ( ! V_172 )
return - V_105 ;
V_8 = F_68 ( V_172 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ( V_172 -> V_174 == V_175 ) || ! V_8 -> V_8 . V_71 )
return - V_105 ;
F_70 ( & V_8 -> V_2 -> V_31 , V_173 ) ;
F_95 ( V_8 ) ;
V_8 -> V_133 = 1 ;
F_63 ( V_8 ) ;
F_44 ( V_8 -> V_2 , F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
V_8 -> V_8 . V_71 = NULL ;
F_110 ( & V_8 -> V_134 ) ;
F_71 ( & V_8 -> V_2 -> V_31 , V_173 ) ;
return 0 ;
}
static struct V_182 * F_111 ( struct V_171 * V_172 ,
T_5 V_160 )
{
struct V_130 * V_131 ;
struct V_7 * V_8 ;
struct V_137 * V_183 ;
struct V_1 * V_2 ;
if ( ! V_172 )
return NULL ;
V_8 = F_68 ( V_172 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
V_131 = F_112 ( sizeof *V_131 , V_160 ) ;
if ( ! V_131 )
return NULL ;
V_131 -> V_131 . V_151 = V_152 ;
V_131 -> V_151 = V_152 ;
F_110 ( & V_131 -> V_134 ) ;
if ( ! V_8 -> V_2 -> V_149 )
return & V_131 -> V_131 ;
V_183 = F_103 ( V_8 -> V_2 -> V_143 , V_160 ,
& V_131 -> V_158 ) ;
if ( NULL == V_183 ) {
F_113 ( V_131 ) ;
return NULL ;
}
V_183 -> V_132 |= V_154 ;
V_183 -> V_153 = F_114 ( V_152 ) ;
V_131 -> V_139 = V_183 ;
V_131 -> V_156 = V_183 ;
V_131 -> V_141 = 1 ;
return & V_131 -> V_131 ;
}
static void F_115 ( struct V_171 * V_172 ,
struct V_182 * V_184 )
{
struct V_7 * V_8 ;
struct V_130 * V_131 ;
struct V_1 * V_2 ;
if ( ! V_172 || ! V_184 )
return;
V_8 = F_68 ( V_172 , struct V_7 , V_8 ) ;
V_131 = F_68 ( V_184 , struct V_130 , V_131 ) ;
V_2 = V_8 -> V_2 ;
if ( ! F_96 ( & V_131 -> V_134 ) )
F_13 ( & V_2 -> V_13 -> V_2 , L_15 ,
V_14 , V_172 -> V_174 , V_131 ) ;
if ( V_131 -> V_139 != NULL ) {
if ( V_131 -> V_141 > 1 )
F_98 ( V_8 -> V_2 , V_131 ) ;
F_100 ( V_8 -> V_2 -> V_143 , V_131 -> V_139 ,
V_131 -> V_158 ) ;
}
F_113 ( V_131 ) ;
}
static int F_116 ( struct V_171 * V_172 , struct V_182 * V_184 ,
T_5 V_160 )
{
int V_161 = 0 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_130 * V_131 ;
unsigned long V_173 ;
if ( ! V_172 || ! V_184 || ! V_184 -> V_185 || ! V_184 -> V_186 )
return - V_105 ;
V_8 = F_68 ( V_172 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_8 -> V_8 . V_71 && V_8 -> V_67 )
return - V_105 ;
V_131 = F_68 ( V_184 , struct V_130 , V_131 ) ;
if ( ! F_96 ( & V_131 -> V_134 ) )
return - V_105 ;
if ( ! V_2 -> V_29 || ( V_2 -> V_32 . V_179 == V_180 ) )
return - V_136 ;
F_70 ( & V_2 -> V_31 , V_173 ) ;
if ( V_184 -> V_148 &&
( ( V_184 -> V_151 == V_152 ) || ! V_184 -> V_151 ) ) {
if ( ! ( ( unsigned long ) ( V_184 -> V_186 ) & 0x03 ) ) {
if ( V_8 -> V_33 )
V_184 -> V_151 = F_117 ( & V_2 -> V_13 -> V_2 ,
V_184 -> V_186 ,
V_184 -> V_148 ,
V_187 ) ;
else
V_184 -> V_151 = F_117 ( & V_2 -> V_13 -> V_2 ,
V_184 -> V_186 ,
V_184 -> V_148 ,
V_188 ) ;
} else {
V_131 -> V_186 = F_112 ( V_184 -> V_148 , V_189 ) ;
if ( ! V_131 -> V_186 ) {
V_161 = - V_159 ;
goto V_190;
}
if ( V_8 -> V_33 ) {
memcpy ( V_131 -> V_186 , V_184 -> V_186 , V_184 -> V_148 ) ;
V_131 -> V_151 = F_117 ( & V_2 -> V_13 -> V_2 ,
V_131 -> V_186 ,
V_184 -> V_148 ,
V_187 ) ;
} else
V_131 -> V_151 = F_117 ( & V_2 -> V_13 -> V_2 ,
V_131 -> V_186 ,
V_184 -> V_148 ,
V_188 ) ;
}
V_131 -> V_191 = 1 ;
}
if ( V_184 -> V_148 > 0 ) {
V_161 = F_104 ( V_8 , V_131 , V_189 ) ;
if ( V_161 )
goto V_190;
}
V_184 -> V_192 = 0 ;
V_184 -> V_132 = - V_193 ;
V_131 -> V_194 = 0 ;
if ( F_96 ( & V_8 -> V_134 ) && ! V_8 -> V_133 ) {
if ( ! V_184 -> V_148 ) {
F_105 ( V_8 , V_131 ) ;
V_161 = 0 ;
goto V_190;
}
if ( ! V_8 -> V_33 ) {
F_106 ( V_8 , V_131 ) ;
} else {
F_64 ( V_8 ) ;
F_56 ( V_8 ) ;
F_45 ( V_8 -> V_2 , ( 1 << V_8 -> V_67 ) ) ;
}
}
if ( V_131 != NULL )
F_118 ( & V_131 -> V_134 , & V_8 -> V_134 ) ;
V_190:
F_71 ( & V_2 -> V_31 , V_173 ) ;
return V_161 ;
}
static int F_119 ( struct V_171 * V_172 ,
struct V_182 * V_184 )
{
struct V_7 * V_8 ;
struct V_130 * V_131 ;
struct V_1 * V_2 ;
unsigned long V_106 ;
int V_195 = - V_105 ;
V_8 = F_68 ( V_172 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_172 || ! V_184 || ( ! V_8 -> V_8 . V_71 && V_8 -> V_67 ) )
return V_195 ;
V_131 = F_68 ( V_184 , struct V_130 , V_131 ) ;
F_70 ( & V_8 -> V_2 -> V_31 , V_106 ) ;
F_120 (req, &ep->queue, queue) {
if ( & V_131 -> V_131 == V_184 ) {
F_55 ( V_8 ) ;
if ( ! F_96 ( & V_131 -> V_134 ) )
F_94 ( V_8 , V_131 , - V_196 ) ;
V_195 = 0 ;
break;
}
}
F_71 ( & V_8 -> V_2 -> V_31 , V_106 ) ;
return V_195 ;
}
static int F_121 ( struct V_171 * V_172 , int V_197 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned long V_173 ;
int V_195 ;
if ( ! V_172 )
return - V_105 ;
V_8 = F_68 ( V_172 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_8 -> V_8 . V_71 && ! V_8 -> V_67 )
return - V_105 ;
if ( ! V_8 -> V_2 -> V_29 || ( V_8 -> V_2 -> V_32 . V_179 == V_180 ) )
return - V_136 ;
F_70 ( & V_198 , V_173 ) ;
if ( F_96 ( & V_8 -> V_134 ) ) {
if ( V_197 ) {
if ( V_8 -> V_67 == V_199 )
V_8 -> V_2 -> V_166 = 1 ;
F_29 ( V_8 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 ,
V_8 -> V_67 ) ) ;
} else {
F_30 ( V_8 ) ;
}
V_195 = 0 ;
} else {
V_195 = - V_200 ;
}
F_71 ( & V_198 , V_173 ) ;
return V_195 ;
}
static int F_122 ( struct V_171 * V_172 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned long V_173 ;
int V_195 ;
if ( ! V_172 )
return - V_105 ;
V_8 = F_68 ( V_172 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_8 -> V_8 . V_71 && ! V_8 -> V_67 )
return - V_105 ;
if ( ! V_8 -> V_2 -> V_29 || ( V_8 -> V_2 -> V_32 . V_179 == V_180 ) )
return - V_136 ;
F_70 ( & V_198 , V_173 ) ;
if ( ! F_96 ( & V_8 -> V_134 ) ) {
V_195 = - V_200 ;
} else {
if ( V_8 -> V_67 == V_199 )
V_8 -> V_2 -> V_166 = 1 ;
F_29 ( V_8 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
V_8 -> V_2 -> V_201 = 1 ;
V_195 = 0 ;
}
F_71 ( & V_198 , V_173 ) ;
return V_195 ;
}
static void F_123 ( struct V_171 * V_172 )
{
struct V_7 * V_8 ;
if ( ! V_172 )
return;
V_8 = F_68 ( V_172 , struct V_7 , V_8 ) ;
if ( V_8 -> V_8 . V_71 || ! V_8 -> V_67 )
F_58 ( V_8 , V_8 -> V_33 ) ;
}
static void F_124 ( struct V_202 * V_203 )
{
static T_1 V_204 ;
if ( ! V_203 )
return;
V_203 -> V_205 = ++ V_204 ;
memset ( & V_203 -> V_206 , 0xFF , sizeof V_203 -> V_206 ) ;
V_203 -> V_132 = V_164 ;
}
static void F_125 ( struct V_7 * V_8 )
{
struct V_130 * V_131 ;
struct V_137 * V_139 ;
if ( F_51 ( V_8 ) & V_49 )
return;
if ( F_96 ( & V_8 -> V_134 ) )
return;
V_131 = F_97 ( V_8 -> V_134 . V_135 , struct V_130 , V_134 ) ;
if ( V_131 -> V_169 )
return;
if ( ! V_131 -> V_139 )
return;
F_64 ( V_8 ) ;
V_131 -> V_169 = 1 ;
F_35 ( V_8 , 0 ) ;
V_139 = V_131 -> V_139 ;
while ( 1 ) {
V_139 -> V_132 = ( V_139 -> V_132 & ~ V_163 ) |
V_164 ;
if ( ( V_139 -> V_132 & V_157 ) == V_157 )
break;
V_139 = F_99 ( V_139 -> V_135 ) ;
}
F_35 ( V_8 , V_131 -> V_158 ) ;
F_39 ( V_8 -> V_2 , V_54 ) ;
F_36 ( V_8 ) ;
F_45 ( V_8 -> V_2 , F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
F_56 ( V_8 ) ;
}
static void F_126 ( struct V_7 * V_8 )
{
struct V_130 * V_131 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_96 ( & V_8 -> V_134 ) )
return;
V_131 = F_97 ( V_8 -> V_134 . V_135 , struct V_130 , V_134 ) ;
if ( ( V_131 -> V_156 -> V_132 & V_163 ) !=
V_207 )
return;
if ( ( V_131 -> V_156 -> V_132 & V_208 ) !=
V_209 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_16
L_17 ,
( V_131 -> V_156 -> V_132 & V_208 ) ,
( int ) ( V_8 -> V_210 ) ) ;
return;
}
V_131 -> V_131 . V_192 = V_131 -> V_131 . V_148 ;
V_131 -> V_156 -> V_132 = V_154 | V_157 ;
V_131 -> V_139 -> V_132 = V_154 | V_157 ;
F_94 ( V_8 , V_131 , 0 ) ;
V_131 -> V_169 = 0 ;
if ( ! F_96 ( & V_8 -> V_134 ) ) {
F_64 ( V_8 ) ;
F_56 ( V_8 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
} else {
F_44 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
}
}
static void F_127 ( struct V_7 * V_8 )
{
struct V_130 * V_131 ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_10 ;
struct V_137 * V_138 ;
T_4 V_46 ;
if ( F_96 ( & V_8 -> V_134 ) )
return;
V_131 = F_97 ( V_8 -> V_134 . V_135 , struct V_130 , V_134 ) ;
F_40 ( V_8 -> V_2 , V_52 ) ;
F_35 ( V_8 , 0 ) ;
if ( ( V_131 -> V_156 -> V_132 & V_163 ) ==
V_207 )
V_138 = V_131 -> V_156 ;
else
V_138 = V_131 -> V_139 ;
while ( 1 ) {
if ( ( V_138 -> V_132 & V_208 ) != V_209 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_18
L_17 ,
( V_131 -> V_139 -> V_132 & V_208 ) ,
( int ) ( V_8 -> V_210 ) ) ;
return;
}
if ( ( V_138 -> V_132 & V_163 ) == V_207 )
if ( V_138 -> V_132 & V_157 ) {
V_10 = V_138 -> V_132 & V_211 ;
break;
}
if ( V_138 == V_131 -> V_156 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_19 ) ;
return;
}
V_46 = ( T_4 ) V_138 -> V_135 ;
V_138 = F_99 ( V_46 ) ;
}
if ( ! V_10 && ( V_131 -> V_131 . V_148 == V_212 ) )
V_10 = V_212 ;
V_131 -> V_139 -> V_132 |= V_157 ;
V_138 -> V_132 |= V_154 ;
V_131 -> V_169 = 0 ;
V_131 -> V_131 . V_192 = V_10 ;
F_94 ( V_8 , V_131 , 0 ) ;
if ( ! F_96 ( & V_8 -> V_134 ) ) {
V_131 = F_97 ( V_8 -> V_134 . V_135 , struct V_130 , V_134 ) ;
F_106 ( V_8 , V_131 ) ;
}
}
static void F_128 ( struct V_1 * V_2 , int V_213 )
{
T_1 V_210 ;
struct V_7 * V_8 ;
V_8 = & V_2 -> V_8 [ F_61 ( V_213 ) ] ;
V_210 = V_8 -> V_210 ;
V_8 -> V_210 = 0 ;
if ( ! ( V_210 & ( V_87 | V_214 | V_215 |
V_216 | V_217 | V_218 |
V_219 | V_220 ) ) )
return;
if ( ( V_210 & V_214 ) )
return;
if ( V_210 & V_215 )
return;
if ( V_210 & V_219 ) {
F_29 ( V_8 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
}
if ( V_210 & V_217 ) {
if ( ! V_2 -> V_201 ) {
F_30 ( V_8 ) ;
} else {
F_29 ( V_8 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
}
}
if ( V_210 & V_216 )
F_126 ( V_8 ) ;
if ( ( V_210 & V_87 ) && ! ( V_210 & V_219 ) &&
! ( V_210 & V_216 ) && ! ( V_210 & V_218 ) )
F_125 ( V_8 ) ;
}
static void F_129 ( struct V_1 * V_2 , int V_213 )
{
T_1 V_210 ;
struct V_7 * V_8 ;
struct V_130 * V_131 = NULL ;
V_8 = & V_2 -> V_8 [ F_62 ( V_213 ) ] ;
V_210 = V_8 -> V_210 ;
V_8 -> V_210 = 0 ;
if ( ( V_210 & V_214 ) && ( ! F_96 ( & V_8 -> V_134 ) ) ) {
V_131 = F_97 ( V_8 -> V_134 . V_135 , struct V_130 ,
V_134 ) ;
if ( ( V_131 -> V_156 -> V_132 & V_163 ) !=
V_207 ) {
if ( ! V_131 -> V_169 )
F_106 ( V_8 , V_131 ) ;
return;
}
}
if ( V_210 & V_215 )
return;
if ( V_210 & V_219 ) {
F_29 ( V_8 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
}
if ( V_210 & V_217 ) {
if ( ! V_2 -> V_201 ) {
F_30 ( V_8 ) ;
} else {
F_29 ( V_8 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
}
}
if ( ( ( V_210 & V_221 ) >> V_222 ) ==
V_223 ) {
if ( V_8 -> V_2 -> V_201 == 1 ) {
F_29 ( V_8 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
} else {
F_127 ( V_8 ) ;
}
}
if ( F_96 ( & V_8 -> V_134 ) )
F_39 ( V_2 , V_52 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
T_1 V_210 ;
struct V_7 * V_8 ;
struct V_7 * V_224 ;
V_8 = & V_2 -> V_8 [ V_168 ] ;
V_224 = & V_2 -> V_8 [ V_225 ] ;
V_210 = V_8 -> V_210 ;
V_8 -> V_210 = 0 ;
if ( ! ( V_210 & ( V_87 | V_214 | V_215 |
V_216 | V_217 | V_218 |
V_220 ) ) )
return;
if ( ( V_210 & V_214 ) )
return;
if ( V_210 & V_215 )
return;
if ( ( V_210 & V_216 ) && ( ! V_2 -> V_166 ) ) {
F_126 ( V_8 ) ;
F_40 ( V_2 , V_52 ) ;
V_224 -> V_139 -> V_132 = ( V_224 -> V_139 -> V_132 &
~ V_163 ) |
V_164 ;
F_56 ( V_224 ) ;
F_39 ( V_2 , V_52 ) ;
F_37 ( V_224 ) ;
}
if ( ( V_210 & V_87 ) && ! ( V_210 & V_216 ) &&
! ( V_210 & V_218 ) )
F_125 ( V_8 ) ;
}
static void F_131 ( struct V_1 * V_2 )
__releases( &dev->lock
static void F_132 ( struct V_1 * V_2 , int V_213 )
{
struct V_7 * V_8 ;
struct V_130 * V_131 ;
V_8 = & V_2 -> V_8 [ F_61 ( V_213 ) ] ;
if ( ! F_96 ( & V_8 -> V_134 ) ) {
V_131 = F_97 ( V_8 -> V_134 . V_135 , struct V_130 , V_134 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
F_56 ( V_8 ) ;
}
}
static void F_133 ( struct V_1 * V_2 , T_1 V_226 )
{
int V_140 ;
struct V_7 * V_8 ;
for ( V_140 = 0 ; V_140 < V_227 ; V_140 ++ ) {
if ( V_226 & ( 0x1 << V_140 ) ) {
V_8 = & V_2 -> V_8 [ F_61 ( V_140 ) ] ;
V_8 -> V_210 = F_53 ( V_8 ) ;
F_54 ( V_8 , V_8 -> V_210 ) ;
}
if ( V_226 & ( 0x10000 << V_140 ) ) {
V_8 = & V_2 -> V_8 [ F_62 ( V_140 ) ] ;
V_8 -> V_210 = F_53 ( V_8 ) ;
F_54 ( V_8 , V_8 -> V_210 ) ;
}
}
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
T_1 V_5 ;
V_8 = & V_2 -> V_8 [ V_168 ] ;
F_52 ( V_8 ) ;
F_58 ( V_8 , V_8 -> V_33 ) ;
F_32 ( V_8 , V_228 , V_8 -> V_33 ) ;
F_33 ( V_8 , V_229 ) ;
V_8 -> V_139 = NULL ;
V_8 -> V_203 = NULL ;
V_8 -> V_158 = 0 ;
V_8 -> V_230 = 0 ;
V_8 = & V_2 -> V_8 [ V_225 ] ;
F_52 ( V_8 ) ;
F_58 ( V_8 , V_8 -> V_33 ) ;
F_32 ( V_8 , V_231 , V_8 -> V_33 ) ;
F_33 ( V_8 , V_232 ) ;
V_5 = V_232 << V_86 ;
F_14 ( V_8 -> V_2 , V_5 , V_225 ) ;
F_124 ( V_8 -> V_203 ) ;
F_34 ( V_8 , V_8 -> V_230 ) ;
F_35 ( V_8 , V_8 -> V_158 ) ;
V_8 -> V_139 -> V_132 = V_157 ;
V_8 -> V_139 -> V_153 = V_2 -> V_149 ;
V_8 -> V_139 -> V_135 = V_8 -> V_158 ;
F_56 ( V_8 ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_140 ;
F_40 ( V_2 , V_54 ) ;
F_40 ( V_2 , V_52 ) ;
F_44 ( V_2 , V_92 ) ;
F_49 ( V_2 , V_92 ) ;
for ( V_140 = 0 ; V_140 < V_233 ; V_140 ++ ) {
V_8 = & V_2 -> V_8 [ V_140 ] ;
F_54 ( V_8 , V_234 ) ;
F_52 ( V_8 ) ;
F_35 ( V_8 , 0 ) ;
F_14 ( V_8 -> V_2 , 0x00 , V_140 ) ;
}
V_2 -> V_166 = 0 ;
V_2 -> V_201 = 0 ;
V_2 -> V_167 = 0 ;
V_2 -> V_165 = 0 ;
for ( V_140 = 0 ; V_140 < ( V_227 * 2 ) ; V_140 ++ ) {
V_8 = & V_2 -> V_8 [ V_140 ] ;
F_55 ( V_8 ) ;
F_58 ( V_8 , V_8 -> V_33 ) ;
F_95 ( V_8 ) ;
}
if ( V_2 -> V_29 && V_2 -> V_29 -> V_30 ) {
F_27 ( & V_2 -> V_31 ) ;
V_2 -> V_29 -> V_30 ( & V_2 -> V_32 ) ;
F_28 ( & V_2 -> V_31 ) ;
}
}
static void F_136 ( struct V_1 * V_2 )
{
T_1 V_235 , V_236 ;
T_1 V_179 = V_237 ;
V_235 = F_50 ( V_2 ) ;
V_236 = ( V_235 & V_238 ) >>
V_239 ;
switch ( V_236 ) {
case V_240 :
V_179 = V_241 ;
break;
case V_242 :
V_179 = V_237 ;
break;
case V_243 :
V_179 = V_244 ;
break;
default:
F_137 () ;
}
V_2 -> V_32 . V_179 = V_179 ;
F_134 ( V_2 ) ;
F_45 ( V_2 , V_245 | V_170 ) ;
F_39 ( V_2 , V_54 ) ;
F_39 ( V_2 , V_52 ) ;
F_37 ( & ( V_2 -> V_8 [ V_225 ] ) ) ;
F_43 ( V_2 , V_25 | V_246 |
V_247 | V_26 |
V_248 | V_249 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
T_1 V_3 , V_235 = 0 ;
int V_140 , V_195 ;
V_235 = F_50 ( V_2 ) ;
V_2 -> V_181 . V_82 = ( V_235 & V_250 ) >>
V_251 ;
V_2 -> V_181 . V_84 = ( V_235 & V_252 ) >>
V_253 ;
V_2 -> V_165 = 1 ;
memset ( & V_2 -> V_254 , 0 , sizeof V_2 -> V_254 ) ;
V_2 -> V_254 . V_255 = V_256 ;
V_2 -> V_254 . V_257 = V_258 ;
V_2 -> V_254 . V_259 = F_139 ( V_2 -> V_181 . V_84 ) ;
V_2 -> V_254 . V_260 = F_139 ( V_2 -> V_181 . V_82 ) ;
V_3 = F_16 ( V_2 , V_225 ) ;
V_3 = ( V_3 & ~ V_261 ) |
( V_2 -> V_181 . V_82 << V_83 ) ;
V_3 = ( V_3 & ~ V_262 ) |
( V_2 -> V_181 . V_84 << V_85 ) ;
F_14 ( V_2 , V_3 , V_225 ) ;
for ( V_140 = 0 ; V_140 < V_227 * 2 ; V_140 ++ ) {
F_30 ( & ( V_2 -> V_8 [ V_140 ] ) ) ;
V_2 -> V_8 [ V_140 ] . V_133 = 0 ;
}
V_2 -> V_166 = 0 ;
F_27 ( & V_2 -> V_31 ) ;
V_195 = V_2 -> V_29 -> V_263 ( & V_2 -> V_32 , & V_2 -> V_254 ) ;
F_28 ( & V_2 -> V_31 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
int V_140 , V_195 ;
T_1 V_3 , V_235 = 0 ;
V_235 = F_50 ( V_2 ) ;
V_2 -> V_165 = 1 ;
V_2 -> V_181 . V_80 = ( V_235 & V_264 ) >>
V_265 ;
memset ( & V_2 -> V_254 , 0 , sizeof V_2 -> V_254 ) ;
V_2 -> V_254 . V_255 = V_266 ;
V_2 -> V_254 . V_259 = F_139 ( V_2 -> V_181 . V_80 ) ;
V_3 = F_16 ( V_2 , V_225 ) ;
V_3 = ( V_3 & ~ V_267 ) |
( V_2 -> V_181 . V_80 << V_81 ) ;
F_14 ( V_2 , V_3 , V_225 ) ;
for ( V_140 = 0 ; V_140 < V_227 * 2 ; V_140 ++ ) {
F_30 ( & ( V_2 -> V_8 [ V_140 ] ) ) ;
V_2 -> V_8 [ V_140 ] . V_133 = 0 ;
}
V_2 -> V_166 = 0 ;
F_27 ( & V_2 -> V_31 ) ;
V_195 = V_2 -> V_29 -> V_263 ( & V_2 -> V_32 , & V_2 -> V_254 ) ;
F_28 ( & V_2 -> V_31 ) ;
}
static void F_141 ( struct V_1 * V_2 , T_1 V_268 )
{
int V_111 ;
if ( V_268 & V_25 ) {
F_135 ( V_2 ) ;
F_79 ( & V_2 -> V_13 -> V_2 , L_20 ) ;
}
if ( V_268 & V_26 ) {
F_136 ( V_2 ) ;
F_79 ( & V_2 -> V_13 -> V_2 , L_21 ) ;
}
if ( V_268 & V_248 )
F_138 ( V_2 ) ;
if ( V_268 & V_249 )
F_140 ( V_2 ) ;
if ( V_268 & V_246 ) {
if ( V_2 -> V_29
&& V_2 -> V_29 -> V_269 ) {
F_27 ( & V_2 -> V_31 ) ;
V_2 -> V_29 -> V_269 ( & V_2 -> V_32 ) ;
F_28 ( & V_2 -> V_31 ) ;
}
V_111 = F_76 ( V_2 ) ;
if ( ( V_2 -> V_28 == 0 )
&& ( V_111 != 1 ) ) {
if ( V_2 -> V_29 && V_2 -> V_29 -> V_30 ) {
F_27 ( & V_2 -> V_31 ) ;
V_2 -> V_29 -> V_30 ( & V_2 -> V_32 ) ;
F_28 ( & V_2 -> V_31 ) ;
}
F_24 ( V_2 ) ;
} else if ( ( V_2 -> V_28 == 0 )
&& ( V_111 == 1 )
&& ! V_2 -> V_112 . V_121 )
F_82 ( & V_2 -> V_112 . V_117 ) ;
F_79 ( & V_2 -> V_13 -> V_2 , L_22 ) ;
}
if ( V_268 & V_270 )
F_79 ( & V_2 -> V_13 -> V_2 , L_23 ) ;
if ( V_268 & V_247 )
F_79 ( & V_2 -> V_13 -> V_2 , L_24 ) ;
if ( V_268 & V_271 )
F_79 ( & V_2 -> V_13 -> V_2 , L_25 ) ;
}
static T_3 F_142 ( int V_123 , void * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
T_1 V_268 , V_226 ;
int V_140 ;
V_268 = F_46 ( V_2 ) ;
V_226 = F_48 ( V_2 ) ;
if ( V_268 == V_226 )
if ( V_268 == F_1 ( V_2 , V_21 ) ) {
F_79 ( & V_2 -> V_13 -> V_2 , L_26 ) ;
F_3 ( V_2 , V_88 , V_89 ) ;
return V_125 ;
}
if ( V_268 )
F_47 ( V_2 , V_268 ) ;
if ( V_226 )
F_49 ( V_2 , V_226 ) ;
if ( ! V_268 && ! V_226 )
return V_124 ;
F_28 ( & V_2 -> V_31 ) ;
if ( V_268 )
F_141 ( V_2 , V_268 ) ;
if ( V_226 ) {
F_133 ( V_2 , V_226 ) ;
if ( V_226 & V_245 ) {
F_130 ( V_2 ) ;
F_132 ( V_2 , 0 ) ;
}
if ( V_226 & V_170 )
F_131 ( V_2 ) ;
for ( V_140 = 1 ; V_140 < V_227 ; V_140 ++ ) {
if ( V_226 & ( 1 << V_140 ) ) {
F_128 ( V_2 , V_140 ) ;
F_132 ( V_2 , V_140 ) ;
}
}
for ( V_140 = V_272 + 1 ; V_140 < ( V_272 +
V_227 ) ; V_140 ++ )
if ( V_226 & ( 1 << V_140 ) )
F_129 ( V_2 , V_140 -
V_272 ) ;
}
F_27 ( & V_2 -> V_31 ) ;
return V_125 ;
}
static void F_143 ( struct V_1 * V_2 )
{
F_45 ( V_2 , V_245 |
V_170 ) ;
F_43 ( V_2 , V_25 | V_246 |
V_247 | V_26 |
V_248 | V_249 ) ;
}
static void F_144 ( struct V_273 * V_13 )
{
struct V_1 * V_2 = F_145 ( V_13 ) ;
F_113 ( V_2 ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
const char * const V_274 [] = {
V_175 , L_27 , L_28 , L_29 , L_30 , L_31 ,
L_32 , L_33 , L_34 , L_35 , L_36 , L_37 ,
L_38 , L_39 , L_40 , L_41 , L_42 , L_43 ,
L_44 , L_45 , L_46 , L_47 , L_48 , L_49 ,
L_50 , L_51 , L_52 , L_53 , L_54 , L_55 ,
L_56 , L_57 ,
} ;
int V_140 ;
V_2 -> V_32 . V_179 = V_180 ;
F_110 ( & V_2 -> V_32 . V_275 ) ;
memset ( V_2 -> V_8 , 0 , sizeof V_2 -> V_8 ) ;
for ( V_140 = 0 ; V_140 < V_233 ; V_140 ++ ) {
struct V_7 * V_8 = & V_2 -> V_8 [ V_140 ] ;
V_8 -> V_2 = V_2 ;
V_8 -> V_133 = 1 ;
V_8 -> V_67 = V_140 / 2 ;
V_8 -> V_33 = ~ V_140 & 1 ;
V_8 -> V_8 . V_174 = V_274 [ V_140 ] ;
V_8 -> V_8 . V_276 = & V_277 ;
if ( V_8 -> V_33 )
V_8 -> V_9 = V_8 -> V_67 * V_278 ;
else
V_8 -> V_9 = ( V_272 + V_8 -> V_67 ) *
V_278 ;
V_8 -> V_8 . V_162 = V_279 ;
F_118 ( & V_8 -> V_8 . V_275 , & V_2 -> V_32 . V_275 ) ;
F_110 ( & V_8 -> V_134 ) ;
}
V_2 -> V_8 [ V_168 ] . V_8 . V_162 = V_229 ;
V_2 -> V_8 [ V_225 ] . V_8 . V_162 = V_232 ;
F_147 ( & V_2 -> V_8 [ V_168 ] . V_8 . V_275 ) ;
F_147 ( & V_2 -> V_8 [ V_225 ] . V_8 . V_275 ) ;
V_2 -> V_32 . V_280 = & V_2 -> V_8 [ V_168 ] . V_8 ;
F_110 ( & V_2 -> V_32 . V_280 -> V_275 ) ;
}
static int F_148 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
F_146 ( V_2 ) ;
F_83 ( V_2 , V_126 ) ;
return 0 ;
}
static int F_149 ( struct V_1 * V_2 )
{
struct V_202 * V_203 ;
struct V_137 * V_139 ;
V_2 -> V_143 = F_150 ( L_58 , V_2 -> V_13 ,
sizeof( struct V_137 ) , 0 , 0 ) ;
if ( ! V_2 -> V_143 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_59 ,
V_14 ) ;
return - V_159 ;
}
V_2 -> V_281 = F_150 ( L_60 , V_2 -> V_13 ,
sizeof( struct V_202 ) , 0 , 0 ) ;
if ( ! V_2 -> V_281 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_61 ,
V_14 ) ;
return - V_159 ;
}
V_203 = F_103 ( V_2 -> V_281 , V_282 ,
& V_2 -> V_8 [ V_225 ] . V_230 ) ;
if ( ! V_203 ) {
F_13 ( & V_2 -> V_13 -> V_2 ,
L_62 , V_14 ) ;
return - V_159 ;
}
V_2 -> V_8 [ V_225 ] . V_203 = V_203 ;
V_139 = F_103 ( V_2 -> V_143 , V_282 ,
& V_2 -> V_8 [ V_225 ] . V_158 ) ;
if ( ! V_139 ) {
F_13 ( & V_2 -> V_13 -> V_2 ,
L_63 , V_14 ) ;
return - V_159 ;
}
V_2 -> V_8 [ V_225 ] . V_139 = V_139 ;
V_2 -> V_8 [ V_168 ] . V_203 = NULL ;
V_2 -> V_8 [ V_168 ] . V_230 = 0 ;
V_2 -> V_8 [ V_168 ] . V_139 = NULL ;
V_2 -> V_8 [ V_168 ] . V_158 = 0 ;
V_2 -> V_283 = F_112 ( V_231 * 4 , V_282 ) ;
if ( ! V_2 -> V_283 )
return - V_159 ;
V_2 -> V_149 = F_117 ( & V_2 -> V_13 -> V_2 , V_2 -> V_283 ,
V_231 * 4 ,
V_188 ) ;
return 0 ;
}
static int F_151 ( struct V_104 * V_284 ,
struct V_285 * V_29 )
{
struct V_1 * V_2 = F_152 ( V_284 ) ;
V_29 -> V_29 . V_286 = NULL ;
V_2 -> V_29 = V_29 ;
F_143 ( V_2 ) ;
if ( ( F_76 ( V_2 ) != 0 ) || ! V_2 -> V_112 . V_121 )
F_23 ( V_2 ) ;
V_2 -> V_287 = 1 ;
return 0 ;
}
static int F_153 ( struct V_104 * V_284 ,
struct V_285 * V_29 )
{
struct V_1 * V_2 = F_152 ( V_284 ) ;
F_42 ( V_2 , V_91 ) ;
V_2 -> V_29 = NULL ;
V_2 -> V_287 = 0 ;
F_22 ( V_2 ) ;
return 0 ;
}
static void F_154 ( struct V_288 * V_13 )
{
struct V_1 * V_2 = F_155 ( V_13 ) ;
F_42 ( V_2 , V_91 ) ;
F_44 ( V_2 , V_92 ) ;
F_22 ( V_2 ) ;
}
static void F_156 ( struct V_288 * V_13 )
{
struct V_1 * V_2 = F_155 ( V_13 ) ;
F_157 ( & V_2 -> V_32 ) ;
if ( V_2 -> V_29 )
F_13 ( & V_13 -> V_2 ,
L_64 , V_14 ) ;
if ( V_2 -> V_143 )
F_158 ( V_2 -> V_143 ) ;
if ( V_2 -> V_281 ) {
if ( V_2 -> V_8 [ V_225 ] . V_203 ) {
F_100 ( V_2 -> V_281 ,
V_2 -> V_8 [ V_225 ] . V_203 ,
V_2 -> V_8 [ V_225 ] . V_230 ) ;
}
if ( V_2 -> V_8 [ V_225 ] . V_139 ) {
F_100 ( V_2 -> V_281 ,
V_2 -> V_8 [ V_225 ] . V_139 ,
V_2 -> V_8 [ V_225 ] . V_158 ) ;
}
F_158 ( V_2 -> V_281 ) ;
}
if ( V_2 -> V_149 )
F_159 ( & V_2 -> V_13 -> V_2 , V_2 -> V_149 ,
V_231 * 4 , V_188 ) ;
F_113 ( V_2 -> V_283 ) ;
F_91 ( V_2 ) ;
F_66 ( V_2 ) ;
if ( V_2 -> V_289 )
F_92 ( V_13 -> V_123 , V_2 ) ;
if ( V_2 -> V_4 )
F_160 ( V_2 -> V_4 ) ;
if ( V_2 -> V_290 )
F_161 ( V_2 -> V_291 ,
F_162 ( V_13 , V_292 ) ) ;
if ( V_2 -> V_293 )
F_163 ( V_13 ) ;
F_113 ( V_2 ) ;
F_164 ( V_13 , NULL ) ;
}
static int F_165 ( struct V_288 * V_13 , T_6 V_294 )
{
struct V_1 * V_2 = F_155 ( V_13 ) ;
F_42 ( V_2 , V_91 ) ;
F_44 ( V_2 , V_92 ) ;
F_163 ( V_13 ) ;
F_166 ( V_13 , V_295 , 0 ) ;
if ( F_167 ( V_13 ) ) {
F_13 ( & V_13 -> V_2 ,
L_65 , V_14 ) ;
return - V_159 ;
}
F_168 ( V_13 , F_169 ( V_13 , V_294 ) ) ;
return 0 ;
}
static int F_170 ( struct V_288 * V_13 )
{
int V_195 ;
F_168 ( V_13 , V_296 ) ;
F_171 ( V_13 ) ;
V_195 = F_172 ( V_13 ) ;
if ( V_195 ) {
F_13 ( & V_13 -> V_2 , L_66 , V_14 ) ;
return V_195 ;
}
F_166 ( V_13 , V_295 , 0 ) ;
return 0 ;
}
static int F_173 ( struct V_288 * V_13 ,
const struct V_297 * V_298 )
{
unsigned long V_299 ;
unsigned long V_150 ;
int V_161 ;
struct V_1 * V_2 ;
V_2 = F_112 ( sizeof *V_2 , V_282 ) ;
if ( ! V_2 ) {
F_65 ( L_67 , V_14 ) ;
return - V_159 ;
}
if ( F_172 ( V_13 ) < 0 ) {
F_113 ( V_2 ) ;
F_65 ( L_66 , V_14 ) ;
return - V_300 ;
}
V_2 -> V_293 = 1 ;
F_164 ( V_13 , V_2 ) ;
V_299 = F_174 ( V_13 , 1 ) ;
V_150 = F_162 ( V_13 , 1 ) ;
if ( ! F_175 ( V_299 , V_150 , V_301 ) ) {
F_13 ( & V_13 -> V_2 , L_68 , V_14 ) ;
V_161 = - V_302 ;
goto V_303;
}
V_2 -> V_291 = V_299 ;
V_2 -> V_290 = 1 ;
V_2 -> V_4 = F_176 ( V_299 , V_150 ) ;
if ( ! V_2 -> V_4 ) {
F_65 ( L_69 , V_14 ) ;
V_161 = - V_159 ;
goto V_303;
}
if ( ! V_13 -> V_123 ) {
F_13 ( & V_13 -> V_2 , L_70 , V_14 ) ;
V_161 = - V_300 ;
goto V_303;
}
if ( F_148 ( V_2 ) ) {
V_161 = - V_300 ;
goto V_303;
}
if ( F_90 ( V_13 -> V_123 , F_142 , V_304 , V_301 ,
V_2 ) ) {
F_13 ( & V_13 -> V_2 , L_71 , V_14 ,
V_13 -> V_123 ) ;
V_161 = - V_300 ;
goto V_303;
}
V_2 -> V_123 = V_13 -> V_123 ;
V_2 -> V_289 = 1 ;
F_177 ( V_13 ) ;
F_178 ( V_13 ) ;
F_179 ( & V_2 -> V_31 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_32 . V_276 = & V_305 ;
V_161 = F_149 ( V_2 ) ;
if ( V_161 )
goto V_303;
V_2 -> V_32 . V_174 = V_301 ;
V_2 -> V_32 . V_306 = V_241 ;
F_22 ( V_2 ) ;
V_161 = F_180 ( & V_13 -> V_2 , & V_2 -> V_32 ,
F_144 ) ;
if ( V_161 )
goto V_303;
return 0 ;
V_303:
F_156 ( V_13 ) ;
return V_161 ;
}
