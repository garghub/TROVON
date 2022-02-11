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
V_32 -> V_108 = ( V_107 != 0 ) ;
V_2 = F_68 ( V_32 , struct V_1 , V_32 ) ;
if ( V_107 )
F_21 ( V_2 ) ;
else
F_20 ( V_2 ) ;
return 0 ;
}
static int F_73 ( struct V_104 * V_32 , int V_109 )
{
struct V_1 * V_2 ;
if ( ! V_32 )
return - V_105 ;
V_2 = F_68 ( V_32 , struct V_1 , V_32 ) ;
if ( V_109 ) {
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
static int F_75 ( struct V_104 * V_32 , unsigned int V_110 )
{
return - V_111 ;
}
static int F_76 ( struct V_1 * V_2 )
{
int V_112 = 0 ;
if ( V_2 -> V_113 . V_114 )
V_112 = F_77 ( V_2 -> V_113 . V_114 ) ? 1 : 0 ;
else
V_112 = - 1 ;
return V_112 ;
}
static void F_78 ( struct V_115 * V_116 )
{
struct V_117 * V_113 = F_68 ( V_116 ,
struct V_117 , V_118 ) ;
struct V_1 * V_2 =
F_68 ( V_113 , struct V_1 , V_113 ) ;
int V_119 = - 1 ;
int V_112 ;
int V_10 ;
if ( ! V_2 -> V_113 . V_114 )
return;
for ( V_10 = 0 ; V_10 < ( V_120 / V_121 ) ;
V_10 ++ ) {
V_112 = F_76 ( V_2 ) ;
if ( ( V_119 == V_112 ) && ( V_112 == 0 ) ) {
F_79 ( & V_2 -> V_13 -> V_2 , L_7 ) ;
if ( V_2 -> V_29
&& V_2 -> V_29 -> V_30 ) {
V_2 -> V_29 -> V_30 (
& V_2 -> V_32 ) ;
}
if ( V_2 -> V_113 . V_122 )
F_25 ( V_2 ) ;
else
F_24 ( V_2 ) ;
return;
}
V_119 = V_112 ;
F_18 ( V_121 ) ;
}
}
static void F_80 ( struct V_115 * V_116 )
{
struct V_117 * V_113 = F_68 ( V_116 ,
struct V_117 , V_123 ) ;
struct V_1 * V_2 =
F_68 ( V_113 , struct V_1 , V_113 ) ;
int V_112 ;
if ( ! V_2 -> V_113 . V_114 )
return;
F_18 ( V_121 ) ;
V_112 = F_76 ( V_2 ) ;
if ( V_112 == 1 ) {
F_79 ( & V_2 -> V_13 -> V_2 , L_8 ) ;
F_24 ( V_2 ) ;
return;
}
}
static T_3 F_81 ( int V_124 , void * V_42 )
{
struct V_1 * V_2 = (struct V_1 * ) V_42 ;
if ( ! V_2 -> V_113 . V_114 || ! V_2 -> V_113 . V_122 )
return V_125 ;
if ( F_76 ( V_2 ) )
F_82 ( & V_2 -> V_113 . V_123 ) ;
else
F_82 ( & V_2 -> V_113 . V_118 ) ;
return V_126 ;
}
static int F_83 ( struct V_1 * V_2 , int V_127 )
{
int V_128 ;
int V_129 = 0 ;
V_2 -> V_113 . V_114 = 0 ;
V_2 -> V_113 . V_122 = 0 ;
if ( V_127 <= - 1 )
return - V_105 ;
V_128 = F_84 ( V_127 ) ;
if ( ! V_128 ) {
F_65 ( L_9 ,
V_14 , V_127 ) ;
return - V_105 ;
}
V_128 = F_85 ( V_127 , L_10 ) ;
if ( V_128 ) {
F_65 ( L_11 ,
V_14 , V_127 , V_128 ) ;
return - V_105 ;
}
V_2 -> V_113 . V_114 = V_127 ;
F_86 ( V_127 ) ;
F_87 ( & V_2 -> V_113 . V_118 , F_78 ) ;
V_129 = F_88 ( V_127 ) ;
if ( V_129 > 0 ) {
F_89 ( V_129 , V_130 ) ;
V_128 = F_90 ( V_129 , F_81 , 0 ,
L_12 , V_2 ) ;
if ( ! V_128 ) {
V_2 -> V_113 . V_122 = V_129 ;
F_87 ( & V_2 -> V_113 . V_123 ,
F_80 ) ;
} else {
F_65 ( L_13 ,
V_14 , V_129 , V_128 ) ;
}
}
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
if ( V_2 -> V_113 . V_122 )
F_92 ( V_2 -> V_113 . V_122 , V_2 ) ;
if ( V_2 -> V_113 . V_114 )
F_93 ( V_2 -> V_113 . V_114 ) ;
}
static void F_94 ( struct V_7 * V_8 , struct V_131 * V_132 ,
int V_133 )
__releases( &dev->lock
static void F_95 ( struct V_7 * V_8 )
{
struct V_131 * V_132 ;
V_8 -> V_134 = 1 ;
while ( ! F_96 ( & V_8 -> V_135 ) ) {
V_132 = F_97 ( V_8 -> V_135 . V_136 , struct V_131 , V_135 ) ;
F_94 ( V_8 , V_132 , - V_137 ) ;
}
}
static void F_98 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
struct V_138 * V_139 = V_132 -> V_140 ;
unsigned V_141 = V_132 -> V_142 ;
T_4 V_143 ;
T_4 V_46 = ( T_4 ) V_139 -> V_136 ;
V_139 -> V_136 = 0x00 ;
for (; V_141 > 1 ; -- V_141 ) {
V_139 = F_99 ( V_46 ) ;
V_143 = ( T_4 ) V_139 -> V_136 ;
F_100 ( V_2 -> V_144 , V_139 , V_46 ) ;
V_139 -> V_136 = 0x00 ;
V_46 = V_143 ;
}
V_132 -> V_142 = 1 ;
}
static int F_101 ( struct V_7 * V_8 ,
struct V_131 * V_132 ,
unsigned long V_145 ,
T_5 V_146 )
{
struct V_138 * V_139 = V_132 -> V_140 , * V_147 ;
unsigned long V_148 = V_132 -> V_132 . V_149 , V_141 = 0 ;
T_4 V_150 ;
unsigned V_151 = 1 ;
if ( V_132 -> V_142 > 1 )
F_98 ( V_8 -> V_2 , V_132 ) ;
if ( V_132 -> V_152 == V_153 )
V_139 -> V_154 = V_132 -> V_132 . V_152 ;
else
V_139 -> V_154 = V_132 -> V_152 ;
V_139 -> V_133 = V_155 ;
for (; ; V_148 -= V_145 , ++ V_151 ) {
V_139 -> V_133 = V_155 | F_102 ( V_145 , V_148 ) ;
if ( V_148 <= V_145 )
break;
V_147 = V_139 ;
V_139 = F_103 ( V_8 -> V_2 -> V_144 , V_146 ,
& V_150 ) ;
if ( ! V_139 )
goto V_156;
V_141 += V_145 ;
V_139 -> V_154 = V_132 -> V_140 -> V_154 + V_141 ;
V_147 -> V_136 = V_150 ;
}
V_132 -> V_157 = V_139 ;
V_139 -> V_133 |= V_158 ;
V_139 -> V_136 = V_132 -> V_159 ;
V_132 -> V_142 = V_151 ;
return 0 ;
V_156:
if ( V_151 > 1 ) {
V_132 -> V_142 = V_151 ;
F_98 ( V_8 -> V_2 , V_132 ) ;
}
V_132 -> V_142 = 1 ;
return - V_160 ;
}
static int F_104 ( struct V_7 * V_8 , struct V_131 * V_132 ,
T_5 V_161 )
{
int V_162 ;
V_162 = F_101 ( V_8 , V_132 , V_8 -> V_8 . V_163 , V_161 ) ;
if ( V_162 ) {
F_65 ( L_14 , V_14 , V_162 ) ;
return V_162 ;
}
if ( V_8 -> V_33 )
V_132 -> V_140 -> V_133 = ( V_132 -> V_140 -> V_133 &
~ V_164 ) | V_165 ;
return 0 ;
}
static void F_105 ( struct V_7 * V_8 , struct V_131 * V_132 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_94 ( V_8 , V_132 , 0 ) ;
if ( V_2 -> V_166 ) {
F_41 ( V_2 ) ;
V_2 -> V_166 = 0 ;
}
if ( ! V_2 -> V_167 && V_2 -> V_168 ) {
F_56 ( & ( V_2 -> V_8 [ V_169 ] ) ) ;
V_2 -> V_168 = 0 ;
}
}
static void F_106 ( struct V_7 * V_8 ,
struct V_131 * V_132 )
{
struct V_138 * V_140 ;
F_40 ( V_8 -> V_2 , V_52 ) ;
V_140 = V_132 -> V_140 ;
while ( 1 ) {
V_140 -> V_133 = ( V_140 -> V_133 & ~ V_164 ) |
V_165 ;
if ( ( V_140 -> V_133 & V_158 ) == V_158 )
break;
V_140 = F_99 ( V_140 -> V_136 ) ;
}
F_35 ( V_8 , V_132 -> V_159 ) ;
V_132 -> V_170 = 1 ;
F_45 ( V_8 -> V_2 , V_171 << V_8 -> V_67 ) ;
F_39 ( V_8 -> V_2 , V_52 ) ;
F_56 ( V_8 ) ;
F_37 ( V_8 ) ;
}
static int F_107 ( struct V_172 * V_173 ,
const struct V_70 * V_71 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned long V_174 ;
if ( ! V_173 || ( V_173 -> V_175 == V_176 ) || ! V_71 ||
( V_71 -> V_177 != V_178 ) || ! V_71 -> V_179 )
return - V_105 ;
V_8 = F_68 ( V_173 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_29 || ( V_2 -> V_32 . V_180 == V_181 ) )
return - V_137 ;
F_70 ( & V_2 -> V_31 , V_174 ) ;
V_8 -> V_8 . V_71 = V_71 ;
V_8 -> V_134 = 0 ;
F_59 ( V_8 , & V_8 -> V_2 -> V_182 , V_71 ) ;
V_8 -> V_8 . V_163 = F_60 ( V_71 ) ;
F_45 ( V_8 -> V_2 , F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
F_71 ( & V_2 -> V_31 , V_174 ) ;
return 0 ;
}
static int F_109 ( struct V_172 * V_173 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned long V_174 ;
if ( ! V_173 )
return - V_105 ;
V_8 = F_68 ( V_173 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ( V_173 -> V_175 == V_176 ) || ! V_8 -> V_8 . V_71 )
return - V_105 ;
F_70 ( & V_8 -> V_2 -> V_31 , V_174 ) ;
F_95 ( V_8 ) ;
V_8 -> V_134 = 1 ;
F_63 ( V_8 ) ;
F_44 ( V_8 -> V_2 , F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
V_8 -> V_8 . V_71 = NULL ;
F_110 ( & V_8 -> V_135 ) ;
F_71 ( & V_8 -> V_2 -> V_31 , V_174 ) ;
return 0 ;
}
static struct V_183 * F_111 ( struct V_172 * V_173 ,
T_5 V_161 )
{
struct V_131 * V_132 ;
struct V_7 * V_8 ;
struct V_138 * V_184 ;
struct V_1 * V_2 ;
if ( ! V_173 )
return NULL ;
V_8 = F_68 ( V_173 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
V_132 = F_112 ( sizeof *V_132 , V_161 ) ;
if ( ! V_132 )
return NULL ;
V_132 -> V_132 . V_152 = V_153 ;
V_132 -> V_152 = V_153 ;
F_110 ( & V_132 -> V_135 ) ;
if ( ! V_8 -> V_2 -> V_150 )
return & V_132 -> V_132 ;
V_184 = F_103 ( V_8 -> V_2 -> V_144 , V_161 ,
& V_132 -> V_159 ) ;
if ( NULL == V_184 ) {
F_113 ( V_132 ) ;
return NULL ;
}
V_184 -> V_133 |= V_155 ;
V_184 -> V_154 = F_114 ( V_153 ) ;
V_132 -> V_140 = V_184 ;
V_132 -> V_157 = V_184 ;
V_132 -> V_142 = 1 ;
return & V_132 -> V_132 ;
}
static void F_115 ( struct V_172 * V_173 ,
struct V_183 * V_185 )
{
struct V_7 * V_8 ;
struct V_131 * V_132 ;
struct V_1 * V_2 ;
if ( ! V_173 || ! V_185 )
return;
V_8 = F_68 ( V_173 , struct V_7 , V_8 ) ;
V_132 = F_68 ( V_185 , struct V_131 , V_132 ) ;
V_2 = V_8 -> V_2 ;
if ( ! F_96 ( & V_132 -> V_135 ) )
F_13 ( & V_2 -> V_13 -> V_2 , L_15 ,
V_14 , V_173 -> V_175 , V_132 ) ;
if ( V_132 -> V_140 != NULL ) {
if ( V_132 -> V_142 > 1 )
F_98 ( V_8 -> V_2 , V_132 ) ;
F_100 ( V_8 -> V_2 -> V_144 , V_132 -> V_140 ,
V_132 -> V_159 ) ;
}
F_113 ( V_132 ) ;
}
static int F_116 ( struct V_172 * V_173 , struct V_183 * V_185 ,
T_5 V_161 )
{
int V_162 = 0 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_131 * V_132 ;
unsigned long V_174 ;
if ( ! V_173 || ! V_185 || ! V_185 -> V_186 || ! V_185 -> V_187 )
return - V_105 ;
V_8 = F_68 ( V_173 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_8 -> V_8 . V_71 && V_8 -> V_67 )
return - V_105 ;
V_132 = F_68 ( V_185 , struct V_131 , V_132 ) ;
if ( ! F_96 ( & V_132 -> V_135 ) )
return - V_105 ;
if ( ! V_2 -> V_29 || ( V_2 -> V_32 . V_180 == V_181 ) )
return - V_137 ;
F_70 ( & V_2 -> V_31 , V_174 ) ;
if ( V_185 -> V_149 &&
( ( V_185 -> V_152 == V_153 ) || ! V_185 -> V_152 ) ) {
if ( ! ( ( unsigned long ) ( V_185 -> V_187 ) & 0x03 ) ) {
if ( V_8 -> V_33 )
V_185 -> V_152 = F_117 ( & V_2 -> V_13 -> V_2 ,
V_185 -> V_187 ,
V_185 -> V_149 ,
V_188 ) ;
else
V_185 -> V_152 = F_117 ( & V_2 -> V_13 -> V_2 ,
V_185 -> V_187 ,
V_185 -> V_149 ,
V_189 ) ;
} else {
V_132 -> V_187 = F_112 ( V_185 -> V_149 , V_190 ) ;
if ( ! V_132 -> V_187 ) {
V_162 = - V_160 ;
goto V_191;
}
if ( V_8 -> V_33 ) {
memcpy ( V_132 -> V_187 , V_185 -> V_187 , V_185 -> V_149 ) ;
V_132 -> V_152 = F_117 ( & V_2 -> V_13 -> V_2 ,
V_132 -> V_187 ,
V_185 -> V_149 ,
V_188 ) ;
} else
V_132 -> V_152 = F_117 ( & V_2 -> V_13 -> V_2 ,
V_132 -> V_187 ,
V_185 -> V_149 ,
V_189 ) ;
}
V_132 -> V_192 = 1 ;
}
if ( V_185 -> V_149 > 0 ) {
V_162 = F_104 ( V_8 , V_132 , V_190 ) ;
if ( V_162 )
goto V_191;
}
V_185 -> V_193 = 0 ;
V_185 -> V_133 = - V_194 ;
V_132 -> V_195 = 0 ;
if ( F_96 ( & V_8 -> V_135 ) && ! V_8 -> V_134 ) {
if ( ! V_185 -> V_149 ) {
F_105 ( V_8 , V_132 ) ;
V_162 = 0 ;
goto V_191;
}
if ( ! V_8 -> V_33 ) {
F_106 ( V_8 , V_132 ) ;
} else {
F_64 ( V_8 ) ;
F_56 ( V_8 ) ;
F_45 ( V_8 -> V_2 , ( 1 << V_8 -> V_67 ) ) ;
}
}
if ( V_132 != NULL )
F_118 ( & V_132 -> V_135 , & V_8 -> V_135 ) ;
V_191:
F_71 ( & V_2 -> V_31 , V_174 ) ;
return V_162 ;
}
static int F_119 ( struct V_172 * V_173 ,
struct V_183 * V_185 )
{
struct V_7 * V_8 ;
struct V_131 * V_132 ;
struct V_1 * V_2 ;
unsigned long V_106 ;
int V_196 = - V_105 ;
V_8 = F_68 ( V_173 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_173 || ! V_185 || ( ! V_8 -> V_8 . V_71 && V_8 -> V_67 ) )
return V_196 ;
V_132 = F_68 ( V_185 , struct V_131 , V_132 ) ;
F_70 ( & V_8 -> V_2 -> V_31 , V_106 ) ;
F_120 (req, &ep->queue, queue) {
if ( & V_132 -> V_132 == V_185 ) {
F_55 ( V_8 ) ;
if ( ! F_96 ( & V_132 -> V_135 ) )
F_94 ( V_8 , V_132 , - V_197 ) ;
V_196 = 0 ;
break;
}
}
F_71 ( & V_8 -> V_2 -> V_31 , V_106 ) ;
return V_196 ;
}
static int F_121 ( struct V_172 * V_173 , int V_198 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned long V_174 ;
int V_196 ;
if ( ! V_173 )
return - V_105 ;
V_8 = F_68 ( V_173 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_8 -> V_8 . V_71 && ! V_8 -> V_67 )
return - V_105 ;
if ( ! V_8 -> V_2 -> V_29 || ( V_8 -> V_2 -> V_32 . V_180 == V_181 ) )
return - V_137 ;
F_70 ( & V_199 , V_174 ) ;
if ( F_96 ( & V_8 -> V_135 ) ) {
if ( V_198 ) {
if ( V_8 -> V_67 == V_200 )
V_8 -> V_2 -> V_167 = 1 ;
F_29 ( V_8 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 ,
V_8 -> V_67 ) ) ;
} else {
F_30 ( V_8 ) ;
}
V_196 = 0 ;
} else {
V_196 = - V_201 ;
}
F_71 ( & V_199 , V_174 ) ;
return V_196 ;
}
static int F_122 ( struct V_172 * V_173 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned long V_174 ;
int V_196 ;
if ( ! V_173 )
return - V_105 ;
V_8 = F_68 ( V_173 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_8 -> V_8 . V_71 && ! V_8 -> V_67 )
return - V_105 ;
if ( ! V_8 -> V_2 -> V_29 || ( V_8 -> V_2 -> V_32 . V_180 == V_181 ) )
return - V_137 ;
F_70 ( & V_199 , V_174 ) ;
if ( ! F_96 ( & V_8 -> V_135 ) ) {
V_196 = - V_201 ;
} else {
if ( V_8 -> V_67 == V_200 )
V_8 -> V_2 -> V_167 = 1 ;
F_29 ( V_8 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
V_8 -> V_2 -> V_202 = 1 ;
V_196 = 0 ;
}
F_71 ( & V_199 , V_174 ) ;
return V_196 ;
}
static void F_123 ( struct V_172 * V_173 )
{
struct V_7 * V_8 ;
if ( ! V_173 )
return;
V_8 = F_68 ( V_173 , struct V_7 , V_8 ) ;
if ( V_8 -> V_8 . V_71 || ! V_8 -> V_67 )
F_58 ( V_8 , V_8 -> V_33 ) ;
}
static void F_124 ( struct V_203 * V_204 )
{
static T_1 V_205 ;
if ( ! V_204 )
return;
V_204 -> V_206 = ++ V_205 ;
memset ( & V_204 -> V_207 , 0xFF , sizeof V_204 -> V_207 ) ;
V_204 -> V_133 = V_165 ;
}
static void F_125 ( struct V_7 * V_8 )
{
struct V_131 * V_132 ;
struct V_138 * V_140 ;
if ( F_51 ( V_8 ) & V_49 )
return;
if ( F_96 ( & V_8 -> V_135 ) )
return;
V_132 = F_97 ( V_8 -> V_135 . V_136 , struct V_131 , V_135 ) ;
if ( V_132 -> V_170 )
return;
if ( ! V_132 -> V_140 )
return;
F_64 ( V_8 ) ;
V_132 -> V_170 = 1 ;
F_35 ( V_8 , 0 ) ;
V_140 = V_132 -> V_140 ;
while ( 1 ) {
V_140 -> V_133 = ( V_140 -> V_133 & ~ V_164 ) |
V_165 ;
if ( ( V_140 -> V_133 & V_158 ) == V_158 )
break;
V_140 = F_99 ( V_140 -> V_136 ) ;
}
F_35 ( V_8 , V_132 -> V_159 ) ;
F_39 ( V_8 -> V_2 , V_54 ) ;
F_36 ( V_8 ) ;
F_45 ( V_8 -> V_2 , F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
F_56 ( V_8 ) ;
}
static void F_126 ( struct V_7 * V_8 )
{
struct V_131 * V_132 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_96 ( & V_8 -> V_135 ) )
return;
V_132 = F_97 ( V_8 -> V_135 . V_136 , struct V_131 , V_135 ) ;
if ( ( V_132 -> V_157 -> V_133 & V_164 ) !=
V_208 )
return;
if ( ( V_132 -> V_157 -> V_133 & V_209 ) !=
V_210 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_16
L_17 ,
( V_132 -> V_157 -> V_133 & V_209 ) ,
( int ) ( V_8 -> V_211 ) ) ;
return;
}
V_132 -> V_132 . V_193 = V_132 -> V_132 . V_149 ;
V_132 -> V_157 -> V_133 = V_155 | V_158 ;
V_132 -> V_140 -> V_133 = V_155 | V_158 ;
F_94 ( V_8 , V_132 , 0 ) ;
V_132 -> V_170 = 0 ;
if ( ! F_96 ( & V_8 -> V_135 ) ) {
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
struct V_131 * V_132 ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_10 ;
struct V_138 * V_139 ;
T_4 V_46 ;
if ( F_96 ( & V_8 -> V_135 ) )
return;
V_132 = F_97 ( V_8 -> V_135 . V_136 , struct V_131 , V_135 ) ;
F_40 ( V_8 -> V_2 , V_52 ) ;
F_35 ( V_8 , 0 ) ;
if ( ( V_132 -> V_157 -> V_133 & V_164 ) ==
V_208 )
V_139 = V_132 -> V_157 ;
else
V_139 = V_132 -> V_140 ;
while ( 1 ) {
if ( ( V_139 -> V_133 & V_209 ) != V_210 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_18
L_17 ,
( V_132 -> V_140 -> V_133 & V_209 ) ,
( int ) ( V_8 -> V_211 ) ) ;
return;
}
if ( ( V_139 -> V_133 & V_164 ) == V_208 )
if ( V_139 -> V_133 & V_158 ) {
V_10 = V_139 -> V_133 & V_212 ;
break;
}
if ( V_139 == V_132 -> V_157 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_19 ) ;
return;
}
V_46 = ( T_4 ) V_139 -> V_136 ;
V_139 = F_99 ( V_46 ) ;
}
if ( ! V_10 && ( V_132 -> V_132 . V_149 == V_213 ) )
V_10 = V_213 ;
V_132 -> V_140 -> V_133 |= V_158 ;
V_139 -> V_133 |= V_155 ;
V_132 -> V_170 = 0 ;
V_132 -> V_132 . V_193 = V_10 ;
F_94 ( V_8 , V_132 , 0 ) ;
if ( ! F_96 ( & V_8 -> V_135 ) ) {
V_132 = F_97 ( V_8 -> V_135 . V_136 , struct V_131 , V_135 ) ;
F_106 ( V_8 , V_132 ) ;
}
}
static void F_128 ( struct V_1 * V_2 , int V_214 )
{
T_1 V_211 ;
struct V_7 * V_8 ;
V_8 = & V_2 -> V_8 [ F_61 ( V_214 ) ] ;
V_211 = V_8 -> V_211 ;
V_8 -> V_211 = 0 ;
if ( ! ( V_211 & ( V_87 | V_215 | V_216 |
V_217 | V_218 | V_219 |
V_220 | V_221 ) ) )
return;
if ( ( V_211 & V_215 ) )
return;
if ( V_211 & V_216 )
return;
if ( V_211 & V_220 ) {
F_29 ( V_8 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
}
if ( V_211 & V_218 ) {
if ( ! V_2 -> V_202 ) {
F_30 ( V_8 ) ;
} else {
F_29 ( V_8 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
}
}
if ( V_211 & V_217 )
F_126 ( V_8 ) ;
if ( ( V_211 & V_87 ) && ! ( V_211 & V_220 ) &&
! ( V_211 & V_217 ) && ! ( V_211 & V_219 ) )
F_125 ( V_8 ) ;
}
static void F_129 ( struct V_1 * V_2 , int V_214 )
{
T_1 V_211 ;
struct V_7 * V_8 ;
struct V_131 * V_132 = NULL ;
V_8 = & V_2 -> V_8 [ F_62 ( V_214 ) ] ;
V_211 = V_8 -> V_211 ;
V_8 -> V_211 = 0 ;
if ( ( V_211 & V_215 ) && ( ! F_96 ( & V_8 -> V_135 ) ) ) {
V_132 = F_97 ( V_8 -> V_135 . V_136 , struct V_131 ,
V_135 ) ;
if ( ( V_132 -> V_157 -> V_133 & V_164 ) !=
V_208 ) {
if ( ! V_132 -> V_170 )
F_106 ( V_8 , V_132 ) ;
return;
}
}
if ( V_211 & V_216 )
return;
if ( V_211 & V_220 ) {
F_29 ( V_8 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
}
if ( V_211 & V_218 ) {
if ( ! V_2 -> V_202 ) {
F_30 ( V_8 ) ;
} else {
F_29 ( V_8 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
}
}
if ( ( ( V_211 & V_222 ) >> V_223 ) ==
V_224 ) {
if ( V_8 -> V_2 -> V_202 == 1 ) {
F_29 ( V_8 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
} else {
F_127 ( V_8 ) ;
}
}
if ( F_96 ( & V_8 -> V_135 ) )
F_39 ( V_2 , V_52 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
T_1 V_211 ;
struct V_7 * V_8 ;
struct V_7 * V_225 ;
V_8 = & V_2 -> V_8 [ V_169 ] ;
V_225 = & V_2 -> V_8 [ V_226 ] ;
V_211 = V_8 -> V_211 ;
V_8 -> V_211 = 0 ;
if ( ! ( V_211 & ( V_87 | V_215 | V_216 |
V_217 | V_218 | V_219 |
V_221 ) ) )
return;
if ( ( V_211 & V_215 ) )
return;
if ( V_211 & V_216 )
return;
if ( ( V_211 & V_217 ) && ( ! V_2 -> V_167 ) ) {
F_126 ( V_8 ) ;
F_40 ( V_2 , V_52 ) ;
V_225 -> V_140 -> V_133 = ( V_225 -> V_140 -> V_133 &
~ V_164 ) |
V_165 ;
F_56 ( V_225 ) ;
F_39 ( V_2 , V_52 ) ;
F_37 ( V_225 ) ;
}
if ( ( V_211 & V_87 ) && ! ( V_211 & V_217 ) &&
! ( V_211 & V_219 ) )
F_125 ( V_8 ) ;
}
static void F_131 ( struct V_1 * V_2 )
__releases( &dev->lock
static void F_132 ( struct V_1 * V_2 , int V_214 )
{
struct V_7 * V_8 ;
struct V_131 * V_132 ;
V_8 = & V_2 -> V_8 [ F_61 ( V_214 ) ] ;
if ( ! F_96 ( & V_8 -> V_135 ) ) {
V_132 = F_97 ( V_8 -> V_135 . V_136 , struct V_131 , V_135 ) ;
F_45 ( V_8 -> V_2 ,
F_108 ( V_8 -> V_33 , V_8 -> V_67 ) ) ;
F_56 ( V_8 ) ;
}
}
static void F_133 ( struct V_1 * V_2 , T_1 V_227 )
{
int V_141 ;
struct V_7 * V_8 ;
for ( V_141 = 0 ; V_141 < V_228 ; V_141 ++ ) {
if ( V_227 & ( 0x1 << V_141 ) ) {
V_8 = & V_2 -> V_8 [ F_61 ( V_141 ) ] ;
V_8 -> V_211 = F_53 ( V_8 ) ;
F_54 ( V_8 , V_8 -> V_211 ) ;
}
if ( V_227 & ( 0x10000 << V_141 ) ) {
V_8 = & V_2 -> V_8 [ F_62 ( V_141 ) ] ;
V_8 -> V_211 = F_53 ( V_8 ) ;
F_54 ( V_8 , V_8 -> V_211 ) ;
}
}
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
T_1 V_5 ;
V_8 = & V_2 -> V_8 [ V_169 ] ;
F_52 ( V_8 ) ;
F_58 ( V_8 , V_8 -> V_33 ) ;
F_32 ( V_8 , V_229 , V_8 -> V_33 ) ;
F_33 ( V_8 , V_230 ) ;
V_8 -> V_140 = NULL ;
V_8 -> V_204 = NULL ;
V_8 -> V_159 = 0 ;
V_8 -> V_231 = 0 ;
V_8 = & V_2 -> V_8 [ V_226 ] ;
F_52 ( V_8 ) ;
F_58 ( V_8 , V_8 -> V_33 ) ;
F_32 ( V_8 , V_232 , V_8 -> V_33 ) ;
F_33 ( V_8 , V_233 ) ;
V_5 = V_233 << V_86 ;
F_14 ( V_8 -> V_2 , V_5 , V_226 ) ;
F_124 ( V_8 -> V_204 ) ;
F_34 ( V_8 , V_8 -> V_231 ) ;
F_35 ( V_8 , V_8 -> V_159 ) ;
V_8 -> V_140 -> V_133 = V_158 ;
V_8 -> V_140 -> V_154 = V_2 -> V_150 ;
V_8 -> V_140 -> V_136 = V_8 -> V_159 ;
F_56 ( V_8 ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_141 ;
F_40 ( V_2 , V_54 ) ;
F_40 ( V_2 , V_52 ) ;
F_44 ( V_2 , V_92 ) ;
F_49 ( V_2 , V_92 ) ;
for ( V_141 = 0 ; V_141 < V_234 ; V_141 ++ ) {
V_8 = & V_2 -> V_8 [ V_141 ] ;
F_54 ( V_8 , V_235 ) ;
F_52 ( V_8 ) ;
F_35 ( V_8 , 0 ) ;
F_14 ( V_8 -> V_2 , 0x00 , V_141 ) ;
}
V_2 -> V_167 = 0 ;
V_2 -> V_202 = 0 ;
V_2 -> V_168 = 0 ;
V_2 -> V_166 = 0 ;
for ( V_141 = 0 ; V_141 < ( V_228 * 2 ) ; V_141 ++ ) {
V_8 = & V_2 -> V_8 [ V_141 ] ;
F_55 ( V_8 ) ;
F_58 ( V_8 , V_8 -> V_33 ) ;
F_95 ( V_8 ) ;
}
if ( V_2 -> V_29 ) {
F_27 ( & V_2 -> V_31 ) ;
F_136 ( & V_2 -> V_32 , V_2 -> V_29 ) ;
F_28 ( & V_2 -> V_31 ) ;
}
}
static void F_137 ( struct V_1 * V_2 )
{
T_1 V_236 , V_237 ;
T_1 V_180 = V_238 ;
V_236 = F_50 ( V_2 ) ;
V_237 = ( V_236 & V_239 ) >>
V_240 ;
switch ( V_237 ) {
case V_241 :
V_180 = V_242 ;
break;
case V_243 :
V_180 = V_238 ;
break;
case V_244 :
V_180 = V_245 ;
break;
default:
F_138 () ;
}
V_2 -> V_32 . V_180 = V_180 ;
F_134 ( V_2 ) ;
F_45 ( V_2 , V_246 | V_171 ) ;
F_39 ( V_2 , V_54 ) ;
F_39 ( V_2 , V_52 ) ;
F_37 ( & ( V_2 -> V_8 [ V_226 ] ) ) ;
F_43 ( V_2 , V_25 | V_247 |
V_248 | V_26 |
V_249 | V_250 ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
T_1 V_3 , V_236 = 0 ;
int V_141 , V_196 ;
V_236 = F_50 ( V_2 ) ;
V_2 -> V_182 . V_82 = ( V_236 & V_251 ) >>
V_252 ;
V_2 -> V_182 . V_84 = ( V_236 & V_253 ) >>
V_254 ;
V_2 -> V_166 = 1 ;
memset ( & V_2 -> V_255 , 0 , sizeof V_2 -> V_255 ) ;
V_2 -> V_255 . V_256 = V_257 ;
V_2 -> V_255 . V_258 = V_259 ;
V_2 -> V_255 . V_260 = F_140 ( V_2 -> V_182 . V_84 ) ;
V_2 -> V_255 . V_261 = F_140 ( V_2 -> V_182 . V_82 ) ;
V_3 = F_16 ( V_2 , V_226 ) ;
V_3 = ( V_3 & ~ V_262 ) |
( V_2 -> V_182 . V_82 << V_83 ) ;
V_3 = ( V_3 & ~ V_263 ) |
( V_2 -> V_182 . V_84 << V_85 ) ;
F_14 ( V_2 , V_3 , V_226 ) ;
for ( V_141 = 0 ; V_141 < V_228 * 2 ; V_141 ++ ) {
F_30 ( & ( V_2 -> V_8 [ V_141 ] ) ) ;
V_2 -> V_8 [ V_141 ] . V_134 = 0 ;
}
V_2 -> V_167 = 0 ;
F_27 ( & V_2 -> V_31 ) ;
V_196 = V_2 -> V_29 -> V_264 ( & V_2 -> V_32 , & V_2 -> V_255 ) ;
F_28 ( & V_2 -> V_31 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
int V_141 , V_196 ;
T_1 V_3 , V_236 = 0 ;
V_236 = F_50 ( V_2 ) ;
V_2 -> V_166 = 1 ;
V_2 -> V_182 . V_80 = ( V_236 & V_265 ) >>
V_266 ;
memset ( & V_2 -> V_255 , 0 , sizeof V_2 -> V_255 ) ;
V_2 -> V_255 . V_256 = V_267 ;
V_2 -> V_255 . V_260 = F_140 ( V_2 -> V_182 . V_80 ) ;
V_3 = F_16 ( V_2 , V_226 ) ;
V_3 = ( V_3 & ~ V_268 ) |
( V_2 -> V_182 . V_80 << V_81 ) ;
F_14 ( V_2 , V_3 , V_226 ) ;
for ( V_141 = 0 ; V_141 < V_228 * 2 ; V_141 ++ ) {
F_30 ( & ( V_2 -> V_8 [ V_141 ] ) ) ;
V_2 -> V_8 [ V_141 ] . V_134 = 0 ;
}
V_2 -> V_167 = 0 ;
F_27 ( & V_2 -> V_31 ) ;
V_196 = V_2 -> V_29 -> V_264 ( & V_2 -> V_32 , & V_2 -> V_255 ) ;
F_28 ( & V_2 -> V_31 ) ;
}
static void F_142 ( struct V_1 * V_2 , T_1 V_269 )
{
int V_112 ;
if ( V_269 & V_25 ) {
F_135 ( V_2 ) ;
F_79 ( & V_2 -> V_13 -> V_2 , L_20 ) ;
}
if ( V_269 & V_26 ) {
F_137 ( V_2 ) ;
F_79 ( & V_2 -> V_13 -> V_2 , L_21 ) ;
}
if ( V_269 & V_249 )
F_139 ( V_2 ) ;
if ( V_269 & V_250 )
F_141 ( V_2 ) ;
if ( V_269 & V_247 ) {
if ( V_2 -> V_29
&& V_2 -> V_29 -> V_270 ) {
F_27 ( & V_2 -> V_31 ) ;
V_2 -> V_29 -> V_270 ( & V_2 -> V_32 ) ;
F_28 ( & V_2 -> V_31 ) ;
}
V_112 = F_76 ( V_2 ) ;
if ( ( V_2 -> V_28 == 0 )
&& ( V_112 != 1 ) ) {
if ( V_2 -> V_29 && V_2 -> V_29 -> V_30 ) {
F_27 ( & V_2 -> V_31 ) ;
V_2 -> V_29 -> V_30 ( & V_2 -> V_32 ) ;
F_28 ( & V_2 -> V_31 ) ;
}
F_24 ( V_2 ) ;
} else if ( ( V_2 -> V_28 == 0 )
&& ( V_112 == 1 )
&& ! V_2 -> V_113 . V_122 )
F_82 ( & V_2 -> V_113 . V_118 ) ;
F_79 ( & V_2 -> V_13 -> V_2 , L_22 ) ;
}
if ( V_269 & V_271 )
F_79 ( & V_2 -> V_13 -> V_2 , L_23 ) ;
if ( V_269 & V_248 )
F_79 ( & V_2 -> V_13 -> V_2 , L_24 ) ;
if ( V_269 & V_272 )
F_79 ( & V_2 -> V_13 -> V_2 , L_25 ) ;
}
static T_3 F_143 ( int V_124 , void * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
T_1 V_269 , V_227 ;
int V_141 ;
V_269 = F_46 ( V_2 ) ;
V_227 = F_48 ( V_2 ) ;
if ( V_269 == V_227 )
if ( V_269 == F_1 ( V_2 , V_21 ) ) {
F_79 ( & V_2 -> V_13 -> V_2 , L_26 ) ;
F_3 ( V_2 , V_88 , V_89 ) ;
return V_126 ;
}
if ( V_269 )
F_47 ( V_2 , V_269 ) ;
if ( V_227 )
F_49 ( V_2 , V_227 ) ;
if ( ! V_269 && ! V_227 )
return V_125 ;
F_28 ( & V_2 -> V_31 ) ;
if ( V_269 )
F_142 ( V_2 , V_269 ) ;
if ( V_227 ) {
F_133 ( V_2 , V_227 ) ;
if ( V_227 & V_246 ) {
F_130 ( V_2 ) ;
F_132 ( V_2 , 0 ) ;
}
if ( V_227 & V_171 )
F_131 ( V_2 ) ;
for ( V_141 = 1 ; V_141 < V_228 ; V_141 ++ ) {
if ( V_227 & ( 1 << V_141 ) ) {
F_128 ( V_2 , V_141 ) ;
F_132 ( V_2 , V_141 ) ;
}
}
for ( V_141 = V_273 + 1 ; V_141 < ( V_273 +
V_228 ) ; V_141 ++ )
if ( V_227 & ( 1 << V_141 ) )
F_129 ( V_2 , V_141 -
V_273 ) ;
}
F_27 ( & V_2 -> V_31 ) ;
return V_126 ;
}
static void F_144 ( struct V_1 * V_2 )
{
F_45 ( V_2 , V_246 |
V_171 ) ;
F_43 ( V_2 , V_25 | V_247 |
V_248 | V_26 |
V_249 | V_250 ) ;
}
static void F_145 ( struct V_274 * V_13 )
{
struct V_1 * V_2 = F_146 ( V_13 ) ;
F_113 ( V_2 ) ;
}
static void F_147 ( struct V_1 * V_2 )
{
const char * const V_275 [] = {
V_176 , L_27 , L_28 , L_29 , L_30 , L_31 ,
L_32 , L_33 , L_34 , L_35 , L_36 , L_37 ,
L_38 , L_39 , L_40 , L_41 , L_42 , L_43 ,
L_44 , L_45 , L_46 , L_47 , L_48 , L_49 ,
L_50 , L_51 , L_52 , L_53 , L_54 , L_55 ,
L_56 , L_57 ,
} ;
int V_141 ;
V_2 -> V_32 . V_180 = V_181 ;
F_110 ( & V_2 -> V_32 . V_276 ) ;
memset ( V_2 -> V_8 , 0 , sizeof V_2 -> V_8 ) ;
for ( V_141 = 0 ; V_141 < V_234 ; V_141 ++ ) {
struct V_7 * V_8 = & V_2 -> V_8 [ V_141 ] ;
V_8 -> V_2 = V_2 ;
V_8 -> V_134 = 1 ;
V_8 -> V_67 = V_141 / 2 ;
V_8 -> V_33 = ~ V_141 & 1 ;
V_8 -> V_8 . V_175 = V_275 [ V_141 ] ;
V_8 -> V_8 . V_277 = & V_278 ;
if ( V_8 -> V_33 )
V_8 -> V_9 = V_8 -> V_67 * V_279 ;
else
V_8 -> V_9 = ( V_273 + V_8 -> V_67 ) *
V_279 ;
F_148 ( & V_8 -> V_8 , V_280 ) ;
F_118 ( & V_8 -> V_8 . V_276 , & V_2 -> V_32 . V_276 ) ;
F_110 ( & V_8 -> V_135 ) ;
}
F_148 ( & V_2 -> V_8 [ V_169 ] . V_8 , V_230 ) ;
F_148 ( & V_2 -> V_8 [ V_226 ] . V_8 , V_233 ) ;
F_149 ( & V_2 -> V_8 [ V_169 ] . V_8 . V_276 ) ;
F_149 ( & V_2 -> V_8 [ V_226 ] . V_8 . V_276 ) ;
V_2 -> V_32 . V_281 = & V_2 -> V_8 [ V_169 ] . V_8 ;
F_110 ( & V_2 -> V_32 . V_281 -> V_276 ) ;
}
static int F_150 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
F_147 ( V_2 ) ;
F_83 ( V_2 , V_127 ) ;
return 0 ;
}
static int F_151 ( struct V_1 * V_2 )
{
struct V_203 * V_204 ;
struct V_138 * V_140 ;
V_2 -> V_144 = F_152 ( L_58 , V_2 -> V_13 ,
sizeof( struct V_138 ) , 0 , 0 ) ;
if ( ! V_2 -> V_144 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_59 ,
V_14 ) ;
return - V_160 ;
}
V_2 -> V_282 = F_152 ( L_60 , V_2 -> V_13 ,
sizeof( struct V_203 ) , 0 , 0 ) ;
if ( ! V_2 -> V_282 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_61 ,
V_14 ) ;
return - V_160 ;
}
V_204 = F_103 ( V_2 -> V_282 , V_283 ,
& V_2 -> V_8 [ V_226 ] . V_231 ) ;
if ( ! V_204 ) {
F_13 ( & V_2 -> V_13 -> V_2 ,
L_62 , V_14 ) ;
return - V_160 ;
}
V_2 -> V_8 [ V_226 ] . V_204 = V_204 ;
V_140 = F_103 ( V_2 -> V_144 , V_283 ,
& V_2 -> V_8 [ V_226 ] . V_159 ) ;
if ( ! V_140 ) {
F_13 ( & V_2 -> V_13 -> V_2 ,
L_63 , V_14 ) ;
return - V_160 ;
}
V_2 -> V_8 [ V_226 ] . V_140 = V_140 ;
V_2 -> V_8 [ V_169 ] . V_204 = NULL ;
V_2 -> V_8 [ V_169 ] . V_231 = 0 ;
V_2 -> V_8 [ V_169 ] . V_140 = NULL ;
V_2 -> V_8 [ V_169 ] . V_159 = 0 ;
V_2 -> V_284 = F_112 ( V_232 * 4 , V_283 ) ;
if ( ! V_2 -> V_284 )
return - V_160 ;
V_2 -> V_150 = F_117 ( & V_2 -> V_13 -> V_2 , V_2 -> V_284 ,
V_232 * 4 ,
V_189 ) ;
return 0 ;
}
static int F_153 ( struct V_104 * V_285 ,
struct V_286 * V_29 )
{
struct V_1 * V_2 = F_154 ( V_285 ) ;
V_29 -> V_29 . V_287 = NULL ;
V_2 -> V_29 = V_29 ;
F_144 ( V_2 ) ;
if ( ( F_76 ( V_2 ) != 0 ) || ! V_2 -> V_113 . V_122 )
F_23 ( V_2 ) ;
V_2 -> V_288 = 1 ;
return 0 ;
}
static int F_155 ( struct V_104 * V_285 )
{
struct V_1 * V_2 = F_154 ( V_285 ) ;
F_42 ( V_2 , V_91 ) ;
V_2 -> V_29 = NULL ;
V_2 -> V_288 = 0 ;
F_22 ( V_2 ) ;
return 0 ;
}
static void F_156 ( struct V_289 * V_13 )
{
struct V_1 * V_2 = F_157 ( V_13 ) ;
F_42 ( V_2 , V_91 ) ;
F_44 ( V_2 , V_92 ) ;
F_22 ( V_2 ) ;
}
static void F_158 ( struct V_289 * V_13 )
{
struct V_1 * V_2 = F_157 ( V_13 ) ;
F_159 ( & V_2 -> V_32 ) ;
if ( V_2 -> V_29 )
F_13 ( & V_13 -> V_2 ,
L_64 , V_14 ) ;
if ( V_2 -> V_144 )
F_160 ( V_2 -> V_144 ) ;
if ( V_2 -> V_282 ) {
if ( V_2 -> V_8 [ V_226 ] . V_204 ) {
F_100 ( V_2 -> V_282 ,
V_2 -> V_8 [ V_226 ] . V_204 ,
V_2 -> V_8 [ V_226 ] . V_231 ) ;
}
if ( V_2 -> V_8 [ V_226 ] . V_140 ) {
F_100 ( V_2 -> V_282 ,
V_2 -> V_8 [ V_226 ] . V_140 ,
V_2 -> V_8 [ V_226 ] . V_159 ) ;
}
F_160 ( V_2 -> V_282 ) ;
}
if ( V_2 -> V_150 )
F_161 ( & V_2 -> V_13 -> V_2 , V_2 -> V_150 ,
V_232 * 4 , V_189 ) ;
F_113 ( V_2 -> V_284 ) ;
F_91 ( V_2 ) ;
F_66 ( V_2 ) ;
if ( V_2 -> V_290 )
F_92 ( V_13 -> V_124 , V_2 ) ;
if ( V_2 -> V_4 )
F_162 ( V_2 -> V_4 ) ;
if ( V_2 -> V_291 )
F_163 ( V_2 -> V_292 ,
F_164 ( V_13 , V_2 -> V_293 ) ) ;
if ( V_2 -> V_294 )
F_165 ( V_13 ) ;
F_113 ( V_2 ) ;
}
static int F_166 ( struct V_289 * V_13 , T_6 V_295 )
{
struct V_1 * V_2 = F_157 ( V_13 ) ;
F_42 ( V_2 , V_91 ) ;
F_44 ( V_2 , V_92 ) ;
F_165 ( V_13 ) ;
F_167 ( V_13 , V_296 , 0 ) ;
if ( F_168 ( V_13 ) ) {
F_13 ( & V_13 -> V_2 ,
L_65 , V_14 ) ;
return - V_160 ;
}
F_169 ( V_13 , F_170 ( V_13 , V_295 ) ) ;
return 0 ;
}
static int F_171 ( struct V_289 * V_13 )
{
int V_196 ;
F_169 ( V_13 , V_297 ) ;
F_172 ( V_13 ) ;
V_196 = F_173 ( V_13 ) ;
if ( V_196 ) {
F_13 ( & V_13 -> V_2 , L_66 , V_14 ) ;
return V_196 ;
}
F_167 ( V_13 , V_296 , 0 ) ;
return 0 ;
}
static int F_174 ( struct V_289 * V_13 ,
const struct V_298 * V_299 )
{
unsigned long V_300 ;
unsigned long V_151 ;
int V_162 ;
struct V_1 * V_2 ;
V_2 = F_112 ( sizeof *V_2 , V_283 ) ;
if ( ! V_2 ) {
F_65 ( L_67 , V_14 ) ;
return - V_160 ;
}
if ( F_173 ( V_13 ) < 0 ) {
F_113 ( V_2 ) ;
F_65 ( L_66 , V_14 ) ;
return - V_301 ;
}
V_2 -> V_294 = 1 ;
F_175 ( V_13 , V_2 ) ;
if ( V_299 -> V_274 == V_302 )
V_2 -> V_293 = V_303 ;
else
V_2 -> V_293 = V_304 ;
V_300 = F_176 ( V_13 , V_2 -> V_293 ) ;
V_151 = F_164 ( V_13 , V_2 -> V_293 ) ;
if ( ! F_177 ( V_300 , V_151 , V_305 ) ) {
F_13 ( & V_13 -> V_2 , L_68 , V_14 ) ;
V_162 = - V_306 ;
goto V_307;
}
V_2 -> V_292 = V_300 ;
V_2 -> V_291 = 1 ;
V_2 -> V_4 = F_178 ( V_300 , V_151 ) ;
if ( ! V_2 -> V_4 ) {
F_65 ( L_69 , V_14 ) ;
V_162 = - V_160 ;
goto V_307;
}
if ( ! V_13 -> V_124 ) {
F_13 ( & V_13 -> V_2 , L_70 , V_14 ) ;
V_162 = - V_301 ;
goto V_307;
}
if ( F_150 ( V_2 ) ) {
V_162 = - V_301 ;
goto V_307;
}
if ( F_90 ( V_13 -> V_124 , F_143 , V_308 , V_305 ,
V_2 ) ) {
F_13 ( & V_13 -> V_2 , L_71 , V_14 ,
V_13 -> V_124 ) ;
V_162 = - V_301 ;
goto V_307;
}
V_2 -> V_124 = V_13 -> V_124 ;
V_2 -> V_290 = 1 ;
F_179 ( V_13 ) ;
F_180 ( V_13 ) ;
F_181 ( & V_2 -> V_31 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_32 . V_277 = & V_309 ;
V_162 = F_151 ( V_2 ) ;
if ( V_162 )
goto V_307;
V_2 -> V_32 . V_175 = V_305 ;
V_2 -> V_32 . V_310 = V_242 ;
F_22 ( V_2 ) ;
V_162 = F_182 ( & V_13 -> V_2 , & V_2 -> V_32 ,
F_145 ) ;
if ( V_162 )
goto V_307;
return 0 ;
V_307:
F_158 ( V_13 ) ;
return V_162 ;
}
