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
static inline void F_24 ( struct V_1 * V_2 ,
int V_24 )
{
if ( V_24 )
F_23 ( V_2 ) ;
else
F_22 ( V_2 ) ;
}
static void F_25 ( struct V_7 * V_8 )
{
if ( V_8 -> V_25 ) {
F_9 ( V_8 , V_26 , V_27 ) ;
F_9 ( V_8 , V_26 , V_28 ) ;
} else {
F_9 ( V_8 , V_26 , V_28 ) ;
}
}
static inline void F_26 ( struct V_7 * V_8 )
{
F_10 ( V_8 , V_26 , V_28 ) ;
F_9 ( V_8 , V_26 , V_29 ) ;
}
static inline void F_27 ( struct V_7 * V_8 ,
T_2 type )
{
F_8 ( V_8 , ( ( type << V_30 ) &
V_31 ) , V_26 ) ;
}
static void F_28 ( struct V_7 * V_8 ,
T_1 V_32 , T_1 V_33 )
{
T_1 V_34 ;
if ( V_33 ) {
V_34 = F_7 ( V_8 , V_35 ) ;
V_34 = ( V_34 & 0xffff0000 ) | ( V_32 & 0xffff ) ;
F_8 ( V_8 , V_34 , V_35 ) ;
} else {
V_34 = F_7 ( V_8 , V_36 ) ;
V_34 = ( V_32 << 16 ) | ( V_34 & 0xffff ) ;
F_8 ( V_8 , V_34 , V_36 ) ;
}
}
static void F_29 ( struct V_7 * V_8 , T_1 V_37 )
{
T_1 V_34 = F_7 ( V_8 , V_36 ) ;
V_34 = ( V_34 & 0xffff0000 ) | ( V_37 & 0xffff ) ;
F_8 ( V_8 , V_34 , V_36 ) ;
}
static inline void F_30 ( struct V_7 * V_8 , T_1 V_38 )
{
F_8 ( V_8 , V_38 , V_39 ) ;
}
static inline void F_31 ( struct V_7 * V_8 , T_1 V_38 )
{
F_8 ( V_8 , V_38 , V_40 ) ;
}
static inline void F_32 ( struct V_7 * V_8 )
{
F_9 ( V_8 , V_26 , V_41 ) ;
}
static inline void F_33 ( struct V_7 * V_8 )
{
F_9 ( V_8 , V_26 , V_42 ) ;
}
static inline void F_34 ( struct V_7 * V_8 )
{
F_10 ( V_8 , V_26 , V_42 ) ;
}
static inline void F_35 ( struct V_1 * V_2 , int V_43 )
{
if ( V_43 == V_44 )
F_5 ( V_2 , V_15 , V_45 ) ;
else if ( V_43 == V_46 )
F_5 ( V_2 , V_15 , V_47 ) ;
}
static inline void F_36 ( struct V_1 * V_2 , int V_43 )
{
if ( V_43 == V_44 )
F_6 ( V_2 , V_15 , V_45 ) ;
else if ( V_43 == V_46 )
F_6 ( V_2 , V_15 , V_47 ) ;
}
static inline void F_37 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_15 , V_48 ) ;
}
static inline void F_38 ( struct V_1 * V_2 ,
T_1 V_49 )
{
F_5 ( V_2 , V_50 , V_49 ) ;
}
static inline void F_39 ( struct V_1 * V_2 ,
T_1 V_49 )
{
F_6 ( V_2 , V_50 , V_49 ) ;
}
static inline void F_40 ( struct V_1 * V_2 ,
T_1 V_49 )
{
F_5 ( V_2 , V_51 , V_49 ) ;
}
static inline void F_41 ( struct V_1 * V_2 ,
T_1 V_49 )
{
F_6 ( V_2 , V_51 , V_49 ) ;
}
static inline T_1 F_42 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_52 ) ;
}
static inline void F_43 ( struct V_1 * V_2 ,
T_1 V_5 )
{
F_3 ( V_2 , V_5 , V_52 ) ;
}
static inline T_1 F_44 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_53 ) ;
}
static inline void F_45 ( struct V_1 * V_2 ,
T_1 V_5 )
{
F_3 ( V_2 , V_5 , V_53 ) ;
}
static inline T_1 F_46 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_18 ) ;
}
static inline T_1 F_47 ( struct V_7 * V_8 )
{
return F_7 ( V_8 , V_26 ) ;
}
static inline void F_48 ( struct V_7 * V_8 )
{
return F_8 ( V_8 , 0 , V_26 ) ;
}
static inline T_1 F_49 ( struct V_7 * V_8 )
{
return F_7 ( V_8 , V_54 ) ;
}
static inline void F_50 ( struct V_7 * V_8 ,
T_1 V_55 )
{
return F_8 ( V_8 , V_55 , V_54 ) ;
}
static inline void F_51 ( struct V_7 * V_8 )
{
F_9 ( V_8 , V_26 , V_56 ) ;
}
static void F_52 ( struct V_7 * V_8 )
{
unsigned int V_57 = 0 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! ( F_7 ( V_8 , V_26 ) & V_58 ) )
return;
if ( ! V_8 -> V_25 ) {
V_57 = 10000 ;
while ( ! ( F_49 ( V_8 ) & V_59 ) &&
-- V_57 )
F_53 ( 5 ) ;
if ( ! V_57 )
F_13 ( & V_2 -> V_13 -> V_2 , L_2 ,
V_14 ) ;
}
V_57 = 10000 ;
while ( ( F_47 ( V_8 ) & V_58 ) && -- V_57 ) {
F_9 ( V_8 , V_26 , V_29 ) ;
F_53 ( 5 ) ;
}
if ( ! V_57 )
F_13 ( & V_2 -> V_13 -> V_2 , L_3 ,
V_14 , V_8 -> V_60 , ( V_8 -> V_25 ? L_4 : L_5 ) ) ;
}
static void F_54 ( struct V_7 * V_8 , int V_43 )
{
if ( V_43 ) {
F_9 ( V_8 , V_26 , V_27 ) ;
return;
}
}
static void F_55 ( struct V_7 * V_8 ,
struct V_61 * V_62 ,
const struct V_63 * V_64 )
{
T_1 V_5 = 0 ;
T_1 V_65 = 0 ;
F_27 ( V_8 , V_64 -> V_66 ) ;
if ( V_8 -> V_25 )
V_65 = V_67 ;
else
V_65 = V_68 ;
F_28 ( V_8 , V_65 , V_8 -> V_25 ) ;
F_29 ( V_8 , F_56 ( V_64 -> V_69 ) ) ;
F_51 ( V_8 ) ;
F_54 ( V_8 , V_8 -> V_25 ) ;
V_5 = V_8 -> V_60 << V_70 | V_8 -> V_25 << V_71 |
( ( V_64 -> V_66 & V_72 ) <<
V_73 ) |
( V_62 -> V_74 << V_75 ) |
( V_62 -> V_76 << V_77 ) |
( V_62 -> V_78 << V_79 ) |
F_56 ( V_64 -> V_69 ) << V_80 ;
if ( V_8 -> V_25 )
F_14 ( V_8 -> V_2 , V_5 , F_57 ( V_8 -> V_60 ) ) ;
else
F_14 ( V_8 -> V_2 , V_5 , F_58 ( V_8 -> V_60 ) ) ;
}
static void F_59 ( struct V_7 * V_8 )
{
if ( V_8 -> V_25 ) {
F_8 ( V_8 , V_27 , V_26 ) ;
F_8 ( V_8 , V_56 , V_26 ) ;
F_9 ( V_8 , V_54 , V_81 ) ;
} else {
F_8 ( V_8 , V_56 , V_26 ) ;
}
F_8 ( V_8 , 0 , V_40 ) ;
}
static void F_60 ( struct V_7 * V_8 )
{
unsigned int V_10 = 10000 ;
while ( ( F_47 ( V_8 ) & V_28 ) && -- V_10 )
F_53 ( 5 ) ;
if ( ! V_10 )
F_13 ( & V_8 -> V_2 -> V_13 -> V_2 , L_1 , V_14 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
if ( NULL == V_2 ) {
F_62 ( L_6 , V_14 ) ;
return;
}
F_3 ( V_2 , V_82 , V_83 ) ;
F_3 ( V_2 , V_82 | V_84 , V_83 ) ;
F_18 ( 1 ) ;
F_3 ( V_2 , V_82 , V_83 ) ;
F_3 ( V_2 , 0x00 , V_83 ) ;
F_18 ( 1 ) ;
F_5 ( V_2 , V_50 , V_85 ) ;
F_5 ( V_2 , V_52 , V_85 ) ;
F_5 ( V_2 , V_51 , V_86 ) ;
F_5 ( V_2 , V_53 , V_86 ) ;
if ( V_87 )
F_5 ( V_2 , V_21 , V_88 |
V_22 | V_89 ) ;
else
F_5 ( V_2 , V_21 , V_88 |
V_22 | V_90 ) ;
F_5 ( V_2 , V_15 ,
( V_91 << V_92 ) |
( V_93 << V_94 ) |
V_95 | V_96 |
V_97 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_50 , V_85 ) ;
F_5 ( V_2 , V_51 , V_86 ) ;
F_22 ( V_2 ) ;
}
static int F_64 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
if ( ! V_99 )
return - V_100 ;
V_2 = F_65 ( V_99 , struct V_1 , V_99 ) ;
return F_19 ( V_2 ) ;
}
static int F_66 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
unsigned long V_101 ;
if ( ! V_99 )
return - V_100 ;
V_2 = F_65 ( V_99 , struct V_1 , V_99 ) ;
F_67 ( & V_2 -> V_102 , V_101 ) ;
F_17 ( V_2 ) ;
F_68 ( & V_2 -> V_102 , V_101 ) ;
return 0 ;
}
static int F_69 ( struct V_98 * V_99 , int V_103 )
{
struct V_1 * V_2 ;
if ( ! V_99 )
return - V_100 ;
V_2 = F_65 ( V_99 , struct V_1 , V_99 ) ;
if ( V_103 )
F_21 ( V_2 ) ;
else
F_20 ( V_2 ) ;
return 0 ;
}
static int F_70 ( struct V_98 * V_99 , int V_104 )
{
struct V_1 * V_2 ;
if ( ! V_99 )
return - V_100 ;
V_2 = F_65 ( V_99 , struct V_1 , V_99 ) ;
F_24 ( V_2 , V_104 ) ;
return 0 ;
}
static int F_71 ( struct V_98 * V_99 , int V_24 )
{
struct V_1 * V_2 ;
if ( ! V_99 )
return - V_100 ;
V_2 = F_65 ( V_99 , struct V_1 , V_99 ) ;
F_24 ( V_2 , V_24 ) ;
return 0 ;
}
static int F_72 ( struct V_98 * V_99 , unsigned int V_105 )
{
return - V_106 ;
}
static void F_73 ( struct V_7 * V_8 , struct V_107 * V_108 ,
int V_109 )
{
struct V_1 * V_2 ;
unsigned V_110 = V_8 -> V_110 ;
F_74 ( & V_108 -> V_111 ) ;
if ( V_108 -> V_108 . V_109 == - V_112 )
V_108 -> V_108 . V_109 = V_109 ;
else
V_109 = V_108 -> V_108 . V_109 ;
V_2 = V_8 -> V_2 ;
if ( V_108 -> V_113 ) {
if ( V_108 -> V_114 == V_115 ) {
if ( V_8 -> V_25 )
F_75 ( & V_2 -> V_13 -> V_2 , V_108 -> V_108 . V_114 ,
V_108 -> V_108 . V_116 ,
V_117 ) ;
else
F_75 ( & V_2 -> V_13 -> V_2 , V_108 -> V_108 . V_114 ,
V_108 -> V_108 . V_116 ,
V_118 ) ;
V_108 -> V_108 . V_114 = V_115 ;
} else {
if ( V_8 -> V_25 )
F_75 ( & V_2 -> V_13 -> V_2 , V_108 -> V_114 ,
V_108 -> V_108 . V_116 ,
V_117 ) ;
else {
F_75 ( & V_2 -> V_13 -> V_2 , V_108 -> V_114 ,
V_108 -> V_108 . V_116 ,
V_118 ) ;
memcpy ( V_108 -> V_108 . V_119 , V_108 -> V_119 , V_108 -> V_108 . V_116 ) ;
}
F_76 ( V_108 -> V_119 ) ;
V_108 -> V_114 = V_115 ;
}
V_108 -> V_113 = 0 ;
}
V_8 -> V_110 = 1 ;
F_77 ( & V_2 -> V_102 ) ;
if ( ! V_8 -> V_25 )
F_34 ( V_8 ) ;
V_108 -> V_108 . V_120 ( & V_8 -> V_8 , & V_108 -> V_108 ) ;
F_78 ( & V_2 -> V_102 ) ;
V_8 -> V_110 = V_110 ;
}
static void F_79 ( struct V_7 * V_8 )
{
struct V_107 * V_108 ;
V_8 -> V_110 = 1 ;
while ( ! F_80 ( & V_8 -> V_111 ) ) {
V_108 = F_81 ( V_8 -> V_111 . V_121 , struct V_107 , V_111 ) ;
F_73 ( V_8 , V_108 , - V_122 ) ;
}
}
static void F_82 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
struct V_123 * V_124 = V_108 -> V_125 ;
unsigned V_126 = V_108 -> V_127 ;
T_3 V_128 ;
T_3 V_38 = ( T_3 ) V_124 -> V_121 ;
V_124 -> V_121 = 0x00 ;
for (; V_126 > 1 ; -- V_126 ) {
V_124 = F_83 ( V_38 ) ;
V_128 = ( T_3 ) V_124 -> V_121 ;
F_84 ( V_2 -> V_129 , V_124 , V_38 ) ;
V_124 -> V_121 = 0x00 ;
V_38 = V_128 ;
}
V_108 -> V_127 = 1 ;
}
static int F_85 ( struct V_7 * V_8 ,
struct V_107 * V_108 ,
unsigned long V_130 ,
T_4 V_131 )
{
struct V_123 * V_124 = V_108 -> V_125 , * V_132 ;
unsigned long V_133 = V_108 -> V_108 . V_116 , V_126 = 0 ;
T_3 V_134 ;
unsigned V_135 = 1 ;
if ( V_108 -> V_127 > 1 )
F_82 ( V_8 -> V_2 , V_108 ) ;
if ( V_108 -> V_114 == V_115 )
V_124 -> V_136 = V_108 -> V_108 . V_114 ;
else
V_124 -> V_136 = V_108 -> V_114 ;
V_124 -> V_109 = V_137 ;
for (; ; V_133 -= V_130 , ++ V_135 ) {
V_124 -> V_109 = V_137 | F_86 ( V_130 , V_133 ) ;
if ( V_133 <= V_130 )
break;
V_132 = V_124 ;
V_124 = F_87 ( V_8 -> V_2 -> V_129 , V_131 ,
& V_134 ) ;
if ( ! V_124 )
goto V_138;
V_126 += V_130 ;
V_124 -> V_136 = V_108 -> V_125 -> V_136 + V_126 ;
V_132 -> V_121 = V_134 ;
}
V_108 -> V_139 = V_124 ;
V_124 -> V_109 |= V_140 ;
V_124 -> V_121 = V_108 -> V_141 ;
V_108 -> V_127 = V_135 ;
return 0 ;
V_138:
if ( V_135 > 1 ) {
V_108 -> V_127 = V_135 ;
F_82 ( V_8 -> V_2 , V_108 ) ;
}
V_108 -> V_127 = 1 ;
return - V_142 ;
}
static int F_88 ( struct V_7 * V_8 , struct V_107 * V_108 ,
T_4 V_143 )
{
int V_144 ;
V_144 = F_85 ( V_8 , V_108 , V_8 -> V_8 . V_145 , V_143 ) ;
if ( V_144 ) {
F_62 ( L_7 , V_14 , V_144 ) ;
return V_144 ;
}
if ( V_8 -> V_25 )
V_108 -> V_125 -> V_109 = ( V_108 -> V_125 -> V_109 &
~ V_146 ) | V_147 ;
return 0 ;
}
static void F_89 ( struct V_7 * V_8 , struct V_107 * V_108 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_73 ( V_8 , V_108 , 0 ) ;
if ( V_2 -> V_148 ) {
F_37 ( V_2 ) ;
V_2 -> V_148 = 0 ;
}
if ( ! V_2 -> V_149 && V_2 -> V_150 ) {
F_52 ( & ( V_2 -> V_8 [ V_151 ] ) ) ;
V_2 -> V_150 = 0 ;
}
}
static void F_90 ( struct V_7 * V_8 ,
struct V_107 * V_108 )
{
struct V_123 * V_125 ;
F_36 ( V_8 -> V_2 , V_44 ) ;
V_125 = V_108 -> V_125 ;
while ( 1 ) {
V_125 -> V_109 = ( V_125 -> V_109 & ~ V_146 ) |
V_147 ;
if ( ( V_125 -> V_109 & V_140 ) == V_140 )
break;
V_125 = F_83 ( V_125 -> V_121 ) ;
}
F_31 ( V_8 , V_108 -> V_141 ) ;
V_108 -> V_152 = 1 ;
F_41 ( V_8 -> V_2 , V_153 << V_8 -> V_60 ) ;
F_35 ( V_8 -> V_2 , V_44 ) ;
F_52 ( V_8 ) ;
F_33 ( V_8 ) ;
}
static int F_91 ( struct V_154 * V_155 ,
const struct V_63 * V_64 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned long V_156 ;
if ( ! V_155 || ( V_155 -> V_157 == V_158 ) || ! V_64 ||
( V_64 -> V_159 != V_160 ) || ! V_64 -> V_69 )
return - V_100 ;
V_8 = F_65 ( V_155 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_2 -> V_161 || ( V_2 -> V_99 . V_162 == V_163 ) )
return - V_122 ;
F_67 ( & V_2 -> V_102 , V_156 ) ;
V_8 -> V_64 = V_64 ;
V_8 -> V_110 = 0 ;
F_55 ( V_8 , & V_8 -> V_2 -> V_164 , V_64 ) ;
V_8 -> V_8 . V_145 = F_56 ( V_64 -> V_69 ) ;
F_41 ( V_8 -> V_2 , F_92 ( V_8 -> V_25 , V_8 -> V_60 ) ) ;
F_68 ( & V_2 -> V_102 , V_156 ) ;
return 0 ;
}
static int F_93 ( struct V_154 * V_155 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned long V_156 ;
if ( ! V_155 )
return - V_100 ;
V_8 = F_65 ( V_155 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ( V_155 -> V_157 == V_158 ) || ! V_8 -> V_64 )
return - V_100 ;
F_67 ( & V_8 -> V_2 -> V_102 , V_156 ) ;
F_79 ( V_8 ) ;
V_8 -> V_110 = 1 ;
F_59 ( V_8 ) ;
F_40 ( V_8 -> V_2 , F_92 ( V_8 -> V_25 , V_8 -> V_60 ) ) ;
V_8 -> V_64 = NULL ;
F_94 ( & V_8 -> V_111 ) ;
F_68 ( & V_8 -> V_2 -> V_102 , V_156 ) ;
return 0 ;
}
static struct V_165 * F_95 ( struct V_154 * V_155 ,
T_4 V_143 )
{
struct V_107 * V_108 ;
struct V_7 * V_8 ;
struct V_123 * V_166 ;
struct V_1 * V_2 ;
if ( ! V_155 )
return NULL ;
V_8 = F_65 ( V_155 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
V_108 = F_96 ( sizeof *V_108 , V_143 ) ;
if ( ! V_108 )
return NULL ;
V_108 -> V_108 . V_114 = V_115 ;
V_108 -> V_114 = V_115 ;
F_94 ( & V_108 -> V_111 ) ;
if ( ! V_8 -> V_2 -> V_134 )
return & V_108 -> V_108 ;
V_166 = F_87 ( V_8 -> V_2 -> V_129 , V_143 ,
& V_108 -> V_141 ) ;
if ( NULL == V_166 ) {
F_76 ( V_108 ) ;
return NULL ;
}
V_166 -> V_109 |= V_137 ;
V_166 -> V_136 = F_97 ( V_115 ) ;
V_108 -> V_125 = V_166 ;
V_108 -> V_139 = V_166 ;
V_108 -> V_127 = 1 ;
return & V_108 -> V_108 ;
}
static void F_98 ( struct V_154 * V_155 ,
struct V_165 * V_167 )
{
struct V_7 * V_8 ;
struct V_107 * V_108 ;
struct V_1 * V_2 ;
if ( ! V_155 || ! V_167 )
return;
V_8 = F_65 ( V_155 , struct V_7 , V_8 ) ;
V_108 = F_65 ( V_167 , struct V_107 , V_108 ) ;
V_2 = V_8 -> V_2 ;
if ( ! F_80 ( & V_108 -> V_111 ) )
F_13 ( & V_2 -> V_13 -> V_2 , L_8 ,
V_14 , V_155 -> V_157 , V_108 ) ;
if ( V_108 -> V_125 != NULL ) {
if ( V_108 -> V_127 > 1 )
F_82 ( V_8 -> V_2 , V_108 ) ;
F_84 ( V_8 -> V_2 -> V_129 , V_108 -> V_125 ,
V_108 -> V_141 ) ;
}
F_76 ( V_108 ) ;
}
static int F_99 ( struct V_154 * V_155 , struct V_165 * V_167 ,
T_4 V_143 )
{
int V_144 = 0 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_107 * V_108 ;
unsigned long V_156 ;
if ( ! V_155 || ! V_167 || ! V_167 -> V_120 || ! V_167 -> V_119 )
return - V_100 ;
V_8 = F_65 ( V_155 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_8 -> V_64 && V_8 -> V_60 )
return - V_100 ;
V_108 = F_65 ( V_167 , struct V_107 , V_108 ) ;
if ( ! F_80 ( & V_108 -> V_111 ) )
return - V_100 ;
if ( ! V_2 -> V_161 || ( V_2 -> V_99 . V_162 == V_163 ) )
return - V_122 ;
F_67 ( & V_2 -> V_102 , V_156 ) ;
if ( V_167 -> V_116 &&
( ( V_167 -> V_114 == V_115 ) || ! V_167 -> V_114 ) ) {
if ( ! ( ( unsigned long ) ( V_167 -> V_119 ) & 0x03 ) ) {
if ( V_8 -> V_25 )
V_167 -> V_114 = F_100 ( & V_2 -> V_13 -> V_2 ,
V_167 -> V_119 ,
V_167 -> V_116 ,
V_117 ) ;
else
V_167 -> V_114 = F_100 ( & V_2 -> V_13 -> V_2 ,
V_167 -> V_119 ,
V_167 -> V_116 ,
V_118 ) ;
} else {
V_108 -> V_119 = F_96 ( V_167 -> V_116 , V_168 ) ;
if ( ! V_108 -> V_119 ) {
V_144 = - V_142 ;
goto V_169;
}
if ( V_8 -> V_25 ) {
memcpy ( V_108 -> V_119 , V_167 -> V_119 , V_167 -> V_116 ) ;
V_108 -> V_114 = F_100 ( & V_2 -> V_13 -> V_2 ,
V_108 -> V_119 ,
V_167 -> V_116 ,
V_117 ) ;
} else
V_108 -> V_114 = F_100 ( & V_2 -> V_13 -> V_2 ,
V_108 -> V_119 ,
V_167 -> V_116 ,
V_118 ) ;
}
V_108 -> V_113 = 1 ;
}
if ( V_167 -> V_116 > 0 ) {
V_144 = F_88 ( V_8 , V_108 , V_168 ) ;
if ( V_144 )
goto V_169;
}
V_167 -> V_170 = 0 ;
V_167 -> V_109 = - V_112 ;
V_108 -> V_171 = 0 ;
if ( F_80 ( & V_8 -> V_111 ) && ! V_8 -> V_110 ) {
if ( ! V_167 -> V_116 ) {
F_89 ( V_8 , V_108 ) ;
V_144 = 0 ;
goto V_169;
}
if ( ! V_8 -> V_25 ) {
F_90 ( V_8 , V_108 ) ;
} else {
F_60 ( V_8 ) ;
F_52 ( V_8 ) ;
F_41 ( V_8 -> V_2 , ( 1 << V_8 -> V_60 ) ) ;
}
}
if ( V_108 != NULL )
F_101 ( & V_108 -> V_111 , & V_8 -> V_111 ) ;
V_169:
F_68 ( & V_2 -> V_102 , V_156 ) ;
return V_144 ;
}
static int F_102 ( struct V_154 * V_155 ,
struct V_165 * V_167 )
{
struct V_7 * V_8 ;
struct V_107 * V_108 ;
struct V_1 * V_2 ;
unsigned long V_101 ;
int V_172 = - V_100 ;
V_8 = F_65 ( V_155 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_155 || ! V_167 || ( ! V_8 -> V_64 && V_8 -> V_60 ) )
return V_172 ;
V_108 = F_65 ( V_167 , struct V_107 , V_108 ) ;
F_67 ( & V_8 -> V_2 -> V_102 , V_101 ) ;
F_103 (req, &ep->queue, queue) {
if ( & V_108 -> V_108 == V_167 ) {
F_51 ( V_8 ) ;
if ( ! F_80 ( & V_108 -> V_111 ) )
F_73 ( V_8 , V_108 , - V_173 ) ;
V_172 = 0 ;
break;
}
}
F_68 ( & V_8 -> V_2 -> V_102 , V_101 ) ;
return V_172 ;
}
static int F_104 ( struct V_154 * V_155 , int V_174 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned long V_156 ;
int V_172 ;
if ( ! V_155 )
return - V_100 ;
V_8 = F_65 ( V_155 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_8 -> V_64 && ! V_8 -> V_60 )
return - V_100 ;
if ( ! V_8 -> V_2 -> V_161 || ( V_8 -> V_2 -> V_99 . V_162 == V_163 ) )
return - V_122 ;
F_67 ( & V_175 , V_156 ) ;
if ( F_80 ( & V_8 -> V_111 ) ) {
if ( V_174 ) {
if ( V_8 -> V_60 == V_176 )
V_8 -> V_2 -> V_149 = 1 ;
F_25 ( V_8 ) ;
F_41 ( V_8 -> V_2 ,
F_92 ( V_8 -> V_25 ,
V_8 -> V_60 ) ) ;
} else {
F_26 ( V_8 ) ;
}
V_172 = 0 ;
} else {
V_172 = - V_177 ;
}
F_68 ( & V_175 , V_156 ) ;
return V_172 ;
}
static int F_105 ( struct V_154 * V_155 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned long V_156 ;
int V_172 ;
if ( ! V_155 )
return - V_100 ;
V_8 = F_65 ( V_155 , struct V_7 , V_8 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_8 -> V_64 && ! V_8 -> V_60 )
return - V_100 ;
if ( ! V_8 -> V_2 -> V_161 || ( V_8 -> V_2 -> V_99 . V_162 == V_163 ) )
return - V_122 ;
F_67 ( & V_175 , V_156 ) ;
if ( ! F_80 ( & V_8 -> V_111 ) ) {
V_172 = - V_177 ;
} else {
if ( V_8 -> V_60 == V_176 )
V_8 -> V_2 -> V_149 = 1 ;
F_25 ( V_8 ) ;
F_41 ( V_8 -> V_2 ,
F_92 ( V_8 -> V_25 , V_8 -> V_60 ) ) ;
V_8 -> V_2 -> V_178 = 1 ;
V_172 = 0 ;
}
F_68 ( & V_175 , V_156 ) ;
return V_172 ;
}
static void F_106 ( struct V_154 * V_155 )
{
struct V_7 * V_8 ;
if ( ! V_155 )
return;
V_8 = F_65 ( V_155 , struct V_7 , V_8 ) ;
if ( V_8 -> V_64 || ! V_8 -> V_60 )
F_54 ( V_8 , V_8 -> V_25 ) ;
}
static void F_107 ( struct V_179 * V_180 )
{
static T_1 V_181 ;
if ( ! V_180 )
return;
V_180 -> V_182 = ++ V_181 ;
memset ( & V_180 -> V_183 , 0xFF , sizeof V_180 -> V_183 ) ;
V_180 -> V_109 = V_147 ;
}
static void F_108 ( struct V_7 * V_8 )
{
struct V_107 * V_108 ;
struct V_123 * V_125 ;
if ( F_47 ( V_8 ) & V_41 )
return;
if ( F_80 ( & V_8 -> V_111 ) )
return;
V_108 = F_81 ( V_8 -> V_111 . V_121 , struct V_107 , V_111 ) ;
if ( V_108 -> V_152 )
return;
if ( ! V_108 -> V_125 )
return;
F_60 ( V_8 ) ;
V_108 -> V_152 = 1 ;
F_31 ( V_8 , 0 ) ;
V_125 = V_108 -> V_125 ;
while ( 1 ) {
V_125 -> V_109 = ( V_125 -> V_109 & ~ V_146 ) |
V_147 ;
if ( ( V_125 -> V_109 & V_140 ) == V_140 )
break;
V_125 = F_83 ( V_125 -> V_121 ) ;
}
F_31 ( V_8 , V_108 -> V_141 ) ;
F_35 ( V_8 -> V_2 , V_46 ) ;
F_32 ( V_8 ) ;
F_41 ( V_8 -> V_2 , F_92 ( V_8 -> V_25 , V_8 -> V_60 ) ) ;
F_52 ( V_8 ) ;
}
static void F_109 ( struct V_7 * V_8 )
{
struct V_107 * V_108 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_80 ( & V_8 -> V_111 ) )
return;
V_108 = F_81 ( V_8 -> V_111 . V_121 , struct V_107 , V_111 ) ;
if ( ( V_108 -> V_139 -> V_109 & V_146 ) !=
V_184 )
return;
if ( ( V_108 -> V_139 -> V_109 & V_185 ) !=
V_186 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_9
L_10 ,
( V_108 -> V_139 -> V_109 & V_185 ) ,
( int ) ( V_8 -> V_187 ) ) ;
return;
}
V_108 -> V_108 . V_170 = V_108 -> V_108 . V_116 ;
V_108 -> V_139 -> V_109 = V_137 | V_140 ;
V_108 -> V_125 -> V_109 = V_137 | V_140 ;
F_73 ( V_8 , V_108 , 0 ) ;
V_108 -> V_152 = 0 ;
if ( ! F_80 ( & V_8 -> V_111 ) ) {
F_60 ( V_8 ) ;
F_52 ( V_8 ) ;
F_41 ( V_8 -> V_2 ,
F_92 ( V_8 -> V_25 , V_8 -> V_60 ) ) ;
} else {
F_40 ( V_8 -> V_2 ,
F_92 ( V_8 -> V_25 , V_8 -> V_60 ) ) ;
}
}
static void F_110 ( struct V_7 * V_8 )
{
struct V_107 * V_108 ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_10 ;
struct V_123 * V_124 ;
T_3 V_38 ;
if ( F_80 ( & V_8 -> V_111 ) )
return;
V_108 = F_81 ( V_8 -> V_111 . V_121 , struct V_107 , V_111 ) ;
F_36 ( V_8 -> V_2 , V_44 ) ;
F_31 ( V_8 , 0 ) ;
if ( ( V_108 -> V_139 -> V_109 & V_146 ) ==
V_184 )
V_124 = V_108 -> V_139 ;
else
V_124 = V_108 -> V_125 ;
while ( 1 ) {
if ( ( V_124 -> V_109 & V_185 ) != V_186 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_11
L_10 ,
( V_108 -> V_125 -> V_109 & V_185 ) ,
( int ) ( V_8 -> V_187 ) ) ;
return;
}
if ( ( V_124 -> V_109 & V_146 ) == V_184 )
if ( V_124 -> V_109 | V_140 ) {
V_10 = V_124 -> V_109 & V_188 ;
break;
}
if ( V_124 == V_108 -> V_139 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_12 ) ;
return;
}
V_38 = ( T_3 ) V_124 -> V_121 ;
V_124 = F_83 ( V_38 ) ;
}
if ( ! V_10 && ( V_108 -> V_108 . V_116 == V_189 ) )
V_10 = V_189 ;
V_108 -> V_125 -> V_109 |= V_140 ;
V_124 -> V_109 |= V_137 ;
V_108 -> V_152 = 0 ;
V_108 -> V_108 . V_170 = V_10 ;
F_73 ( V_8 , V_108 , 0 ) ;
if ( ! F_80 ( & V_8 -> V_111 ) ) {
V_108 = F_81 ( V_8 -> V_111 . V_121 , struct V_107 , V_111 ) ;
F_90 ( V_8 , V_108 ) ;
}
}
static void F_111 ( struct V_1 * V_2 , int V_190 )
{
T_1 V_187 ;
struct V_7 * V_8 ;
V_8 = & V_2 -> V_8 [ F_57 ( V_190 ) ] ;
V_187 = V_8 -> V_187 ;
V_8 -> V_187 = 0 ;
if ( ! ( V_187 & ( V_81 | V_191 | V_192 |
V_193 | V_194 | V_195 |
V_196 | V_197 ) ) )
return;
if ( ( V_187 & V_191 ) )
return;
if ( V_187 & V_192 )
return;
if ( V_187 & V_196 ) {
F_25 ( V_8 ) ;
F_41 ( V_8 -> V_2 ,
F_92 ( V_8 -> V_25 , V_8 -> V_60 ) ) ;
}
if ( V_187 & V_194 ) {
if ( ! V_2 -> V_178 ) {
F_26 ( V_8 ) ;
} else {
F_25 ( V_8 ) ;
F_41 ( V_8 -> V_2 ,
F_92 ( V_8 -> V_25 , V_8 -> V_60 ) ) ;
}
}
if ( V_187 & V_193 )
F_109 ( V_8 ) ;
if ( ( V_187 & V_81 ) && ! ( V_187 & V_196 ) &&
! ( V_187 & V_193 ) && ! ( V_187 & V_195 ) )
F_108 ( V_8 ) ;
}
static void F_112 ( struct V_1 * V_2 , int V_190 )
{
T_1 V_187 ;
struct V_7 * V_8 ;
struct V_107 * V_108 = NULL ;
V_8 = & V_2 -> V_8 [ F_58 ( V_190 ) ] ;
V_187 = V_8 -> V_187 ;
V_8 -> V_187 = 0 ;
if ( ( V_187 & V_191 ) && ( ! F_80 ( & V_8 -> V_111 ) ) ) {
V_108 = F_81 ( V_8 -> V_111 . V_121 , struct V_107 ,
V_111 ) ;
if ( ( V_108 -> V_139 -> V_109 & V_146 ) !=
V_184 ) {
if ( ! V_108 -> V_152 )
F_90 ( V_8 , V_108 ) ;
return;
}
}
if ( V_187 & V_192 )
return;
if ( V_187 & V_196 ) {
F_25 ( V_8 ) ;
F_41 ( V_8 -> V_2 ,
F_92 ( V_8 -> V_25 , V_8 -> V_60 ) ) ;
}
if ( V_187 & V_194 ) {
if ( ! V_2 -> V_178 ) {
F_26 ( V_8 ) ;
} else {
F_25 ( V_8 ) ;
F_41 ( V_8 -> V_2 ,
F_92 ( V_8 -> V_25 , V_8 -> V_60 ) ) ;
}
}
if ( ( ( V_187 & V_198 ) >> V_199 ) ==
V_200 ) {
if ( V_8 -> V_2 -> V_178 == 1 ) {
F_25 ( V_8 ) ;
F_41 ( V_8 -> V_2 ,
F_92 ( V_8 -> V_25 , V_8 -> V_60 ) ) ;
} else {
F_110 ( V_8 ) ;
}
}
if ( F_80 ( & V_8 -> V_111 ) )
F_35 ( V_2 , V_44 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
T_1 V_187 ;
struct V_7 * V_8 ;
struct V_7 * V_201 ;
V_8 = & V_2 -> V_8 [ V_151 ] ;
V_201 = & V_2 -> V_8 [ V_202 ] ;
V_187 = V_8 -> V_187 ;
V_8 -> V_187 = 0 ;
if ( ! ( V_187 & ( V_81 | V_191 | V_192 |
V_193 | V_194 | V_195 |
V_197 ) ) )
return;
if ( ( V_187 & V_191 ) )
return;
if ( V_187 & V_192 )
return;
if ( ( V_187 & V_193 ) && ( ! V_2 -> V_149 ) ) {
F_109 ( V_8 ) ;
F_36 ( V_2 , V_44 ) ;
V_201 -> V_125 -> V_109 = ( V_201 -> V_125 -> V_109 &
~ V_146 ) |
V_147 ;
F_52 ( V_201 ) ;
F_35 ( V_2 , V_44 ) ;
F_33 ( V_201 ) ;
}
if ( ( V_187 & V_81 ) && ! ( V_187 & V_193 ) &&
! ( V_187 & V_195 ) )
F_108 ( V_8 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
T_1 V_55 ;
int V_203 ;
struct V_7 * V_8 ;
V_8 = & V_2 -> V_8 [ V_202 ] ;
V_55 = V_8 -> V_187 ;
V_8 -> V_187 = 0 ;
if ( ( ( V_55 & V_198 ) >> V_199 ) ==
V_204 ) {
V_2 -> V_149 = 0 ;
V_2 -> V_8 [ V_151 ] . V_110 = 0 ;
V_2 -> V_8 [ V_202 ] . V_110 = 0 ;
V_2 -> V_205 = V_8 -> V_180 -> V_183 ;
F_107 ( V_8 -> V_180 ) ;
F_36 ( V_2 , V_44 ) ;
F_54 ( & ( V_2 -> V_8 [ V_151 ] ) ,
V_2 -> V_8 [ V_151 ] . V_25 ) ;
if ( ( V_2 -> V_205 . V_206 & V_207 ) )
V_2 -> V_99 . V_208 = & V_2 -> V_8 [ V_151 ] . V_8 ;
else
V_2 -> V_99 . V_208 = & V_8 -> V_8 ;
F_77 ( & V_2 -> V_102 ) ;
if ( ( V_2 -> V_205 . V_206 == 0x21 ) &&
( V_2 -> V_205 . V_209 == 0xFF ) )
V_2 -> V_178 = 0 ;
V_203 = V_2 -> V_161 -> V_210 ( & V_2 -> V_99 ,
& V_2 -> V_205 ) ;
F_78 ( & V_2 -> V_102 ) ;
if ( V_2 -> V_205 . V_206 & V_207 ) {
V_8 -> V_125 -> V_109 = ( V_8 -> V_125 -> V_109 &
~ V_146 ) |
V_147 ;
F_31 ( V_8 , V_8 -> V_141 ) ;
}
if ( V_203 >= 0 && V_203 <
V_211 ) {
F_52 ( & ( V_2 -> V_8 [ V_151 ] ) ) ;
if ( ! ( V_2 -> V_205 . V_206 & V_207 ) ) {
F_35 ( V_2 , V_44 ) ;
F_52 ( V_8 ) ;
}
} else if ( V_203 < 0 ) {
F_25 ( & ( V_2 -> V_8 [ V_151 ] ) ) ;
F_41 ( V_8 -> V_2 ,
F_92 ( V_8 -> V_25 , V_8 -> V_60 ) ) ;
V_2 -> V_149 = 0 ;
F_35 ( V_2 , V_44 ) ;
} else {
V_2 -> V_150 = 1 ;
}
} else if ( ( ( ( V_55 & V_198 ) >> V_199 ) ==
V_200 ) && ! V_2 -> V_149 ) {
F_36 ( V_2 , V_44 ) ;
F_31 ( V_8 , 0 ) ;
if ( ! F_80 ( & V_8 -> V_111 ) ) {
V_8 -> V_187 = V_55 ;
F_112 ( V_2 , V_176 ) ;
}
F_35 ( V_2 , V_44 ) ;
}
F_33 ( V_8 ) ;
}
static void F_115 ( struct V_1 * V_2 , int V_190 )
{
struct V_7 * V_8 ;
struct V_107 * V_108 ;
V_8 = & V_2 -> V_8 [ F_57 ( V_190 ) ] ;
if ( ! F_80 ( & V_8 -> V_111 ) ) {
V_108 = F_81 ( V_8 -> V_111 . V_121 , struct V_107 , V_111 ) ;
F_41 ( V_8 -> V_2 ,
F_92 ( V_8 -> V_25 , V_8 -> V_60 ) ) ;
F_52 ( V_8 ) ;
}
}
static void F_116 ( struct V_1 * V_2 , T_1 V_212 )
{
int V_126 ;
struct V_7 * V_8 ;
for ( V_126 = 0 ; V_126 < V_213 ; V_126 ++ ) {
if ( V_212 & ( 0x1 << V_126 ) ) {
V_8 = & V_2 -> V_8 [ F_57 ( V_126 ) ] ;
V_8 -> V_187 = F_49 ( V_8 ) ;
F_50 ( V_8 , V_8 -> V_187 ) ;
}
if ( V_212 & ( 0x10000 << V_126 ) ) {
V_8 = & V_2 -> V_8 [ F_58 ( V_126 ) ] ;
V_8 -> V_187 = F_49 ( V_8 ) ;
F_50 ( V_8 , V_8 -> V_187 ) ;
}
}
}
static void F_117 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
T_1 V_5 ;
V_8 = & V_2 -> V_8 [ V_151 ] ;
F_48 ( V_8 ) ;
F_54 ( V_8 , V_8 -> V_25 ) ;
F_28 ( V_8 , V_214 , V_8 -> V_25 ) ;
F_29 ( V_8 , V_211 ) ;
V_8 -> V_125 = NULL ;
V_8 -> V_180 = NULL ;
V_8 -> V_141 = 0 ;
V_8 -> V_215 = 0 ;
V_8 = & V_2 -> V_8 [ V_202 ] ;
F_48 ( V_8 ) ;
F_54 ( V_8 , V_8 -> V_25 ) ;
F_28 ( V_8 , V_216 , V_8 -> V_25 ) ;
F_29 ( V_8 , V_217 ) ;
V_5 = V_217 << V_80 ;
F_14 ( V_8 -> V_2 , V_5 , V_202 ) ;
F_107 ( V_8 -> V_180 ) ;
F_30 ( V_8 , V_8 -> V_215 ) ;
F_31 ( V_8 , V_8 -> V_141 ) ;
V_8 -> V_125 -> V_109 = V_140 ;
V_8 -> V_125 -> V_136 = V_2 -> V_134 ;
V_8 -> V_125 -> V_121 = V_8 -> V_141 ;
F_52 ( V_8 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_126 ;
F_36 ( V_2 , V_46 ) ;
F_36 ( V_2 , V_44 ) ;
F_40 ( V_2 , V_86 ) ;
F_45 ( V_2 , V_86 ) ;
for ( V_126 = 0 ; V_126 < V_218 ; V_126 ++ ) {
V_8 = & V_2 -> V_8 [ V_126 ] ;
F_50 ( V_8 , V_219 ) ;
F_48 ( V_8 ) ;
F_31 ( V_8 , 0 ) ;
F_14 ( V_8 -> V_2 , 0x00 , V_126 ) ;
}
V_2 -> V_149 = 0 ;
V_2 -> V_178 = 0 ;
V_2 -> V_150 = 0 ;
V_2 -> V_148 = 0 ;
for ( V_126 = 0 ; V_126 < ( V_213 * 2 ) ; V_126 ++ ) {
V_8 = & V_2 -> V_8 [ V_126 ] ;
F_51 ( V_8 ) ;
F_54 ( V_8 , V_8 -> V_25 ) ;
F_79 ( V_8 ) ;
}
if ( V_2 -> V_161 && V_2 -> V_161 -> V_220 )
V_2 -> V_161 -> V_220 ( & V_2 -> V_99 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
T_1 V_221 , V_222 ;
T_1 V_162 = V_223 ;
V_221 = F_46 ( V_2 ) ;
V_222 = ( V_221 & V_224 ) >>
V_225 ;
switch ( V_222 ) {
case V_226 :
V_162 = V_227 ;
break;
case V_228 :
V_162 = V_223 ;
break;
case V_229 :
V_162 = V_230 ;
break;
default:
F_120 () ;
}
V_2 -> V_99 . V_162 = V_162 ;
F_117 ( V_2 ) ;
F_41 ( V_2 , V_231 | V_153 ) ;
F_35 ( V_2 , V_46 ) ;
F_35 ( V_2 , V_44 ) ;
F_33 ( & ( V_2 -> V_8 [ V_202 ] ) ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
T_1 V_3 , V_221 = 0 ;
int V_126 , V_172 ;
V_221 = F_46 ( V_2 ) ;
V_2 -> V_164 . V_76 = ( V_221 & V_232 ) >>
V_233 ;
V_2 -> V_164 . V_78 = ( V_221 & V_234 ) >>
V_235 ;
V_2 -> V_148 = 1 ;
memset ( & V_2 -> V_205 , 0 , sizeof V_2 -> V_205 ) ;
V_2 -> V_205 . V_209 = V_236 ;
V_2 -> V_205 . V_206 = V_237 ;
V_2 -> V_205 . V_238 = F_122 ( V_2 -> V_164 . V_78 ) ;
V_2 -> V_205 . V_239 = F_122 ( V_2 -> V_164 . V_76 ) ;
V_3 = F_16 ( V_2 , V_202 ) ;
V_3 = ( V_3 & ~ V_240 ) |
( V_2 -> V_164 . V_76 << V_77 ) ;
V_3 = ( V_3 & ~ V_241 ) |
( V_2 -> V_164 . V_78 << V_79 ) ;
F_14 ( V_2 , V_3 , V_202 ) ;
for ( V_126 = 0 ; V_126 < V_213 * 2 ; V_126 ++ ) {
F_26 ( & ( V_2 -> V_8 [ V_126 ] ) ) ;
V_2 -> V_8 [ V_126 ] . V_110 = 0 ;
}
V_2 -> V_149 = 0 ;
F_77 ( & V_2 -> V_102 ) ;
V_172 = V_2 -> V_161 -> V_210 ( & V_2 -> V_99 , & V_2 -> V_205 ) ;
F_78 ( & V_2 -> V_102 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
int V_126 , V_172 ;
T_1 V_3 , V_221 = 0 ;
V_221 = F_46 ( V_2 ) ;
V_2 -> V_148 = 1 ;
V_2 -> V_164 . V_74 = ( V_221 & V_242 ) >>
V_243 ;
memset ( & V_2 -> V_205 , 0 , sizeof V_2 -> V_205 ) ;
V_2 -> V_205 . V_209 = V_244 ;
V_2 -> V_205 . V_238 = F_122 ( V_2 -> V_164 . V_74 ) ;
V_3 = F_16 ( V_2 , V_202 ) ;
V_3 = ( V_3 & ~ V_245 ) |
( V_2 -> V_164 . V_74 << V_75 ) ;
F_14 ( V_2 , V_3 , V_202 ) ;
for ( V_126 = 0 ; V_126 < V_213 * 2 ; V_126 ++ ) {
F_26 ( & ( V_2 -> V_8 [ V_126 ] ) ) ;
V_2 -> V_8 [ V_126 ] . V_110 = 0 ;
}
V_2 -> V_149 = 0 ;
F_77 ( & V_2 -> V_102 ) ;
V_172 = V_2 -> V_161 -> V_210 ( & V_2 -> V_99 , & V_2 -> V_205 ) ;
F_78 ( & V_2 -> V_102 ) ;
}
static void F_124 ( struct V_1 * V_2 , T_1 V_246 )
{
if ( V_246 & V_247 )
F_118 ( V_2 ) ;
if ( V_246 & V_248 )
F_119 ( V_2 ) ;
if ( V_246 & V_249 )
F_121 ( V_2 ) ;
if ( V_246 & V_250 )
F_123 ( V_2 ) ;
if ( V_246 & V_251 )
F_125 ( & V_2 -> V_13 -> V_2 , L_13 ) ;
if ( V_246 & V_252 )
F_125 ( & V_2 -> V_13 -> V_2 , L_14 ) ;
if ( V_246 & V_253 )
F_125 ( & V_2 -> V_13 -> V_2 , L_15 ) ;
if ( V_246 & V_254 )
F_125 ( & V_2 -> V_13 -> V_2 , L_16 ) ;
}
static T_5 F_126 ( int V_255 , void * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
T_1 V_246 , V_212 ;
int V_126 ;
V_246 = F_42 ( V_2 ) ;
V_212 = F_44 ( V_2 ) ;
if ( V_246 )
F_43 ( V_2 , V_246 ) ;
if ( V_212 )
F_45 ( V_2 , V_212 ) ;
if ( ! V_246 && ! V_212 )
return V_256 ;
F_78 ( & V_2 -> V_102 ) ;
if ( V_246 )
F_124 ( V_2 , V_246 ) ;
if ( V_212 ) {
F_116 ( V_2 , V_212 ) ;
if ( V_212 & V_231 ) {
F_113 ( V_2 ) ;
F_115 ( V_2 , 0 ) ;
}
if ( V_212 & V_153 )
F_114 ( V_2 ) ;
for ( V_126 = 1 ; V_126 < V_213 ; V_126 ++ ) {
if ( V_212 & ( 1 << V_126 ) ) {
F_111 ( V_2 , V_126 ) ;
F_115 ( V_2 , V_126 ) ;
}
}
for ( V_126 = V_257 + 1 ; V_126 < ( V_257 +
V_213 ) ; V_126 ++ )
if ( V_212 & ( 1 << V_126 ) )
F_112 ( V_2 , V_126 -
V_257 ) ;
}
F_77 ( & V_2 -> V_102 ) ;
return V_258 ;
}
static void F_127 ( struct V_1 * V_2 )
{
F_41 ( V_2 , V_231 |
V_153 ) ;
F_39 ( V_2 , V_247 | V_251 |
V_253 | V_248 |
V_249 | V_250 ) ;
}
static void F_128 ( struct V_259 * V_13 )
{
struct V_1 * V_2 = F_129 ( V_13 ) ;
F_76 ( V_2 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
const char * const V_260 [] = {
V_158 , L_17 , L_18 , L_19 , L_20 , L_21 ,
L_22 , L_23 , L_24 , L_25 , L_26 , L_27 ,
L_28 , L_29 , L_30 , L_31 , L_32 , L_33 ,
L_34 , L_35 , L_36 , L_37 , L_38 , L_39 ,
L_40 , L_41 , L_42 , L_43 , L_44 , L_45 ,
L_46 , L_47 ,
} ;
int V_126 ;
V_2 -> V_99 . V_162 = V_163 ;
F_94 ( & V_2 -> V_99 . V_261 ) ;
memset ( V_2 -> V_8 , 0 , sizeof V_2 -> V_8 ) ;
for ( V_126 = 0 ; V_126 < V_218 ; V_126 ++ ) {
struct V_7 * V_8 = & V_2 -> V_8 [ V_126 ] ;
V_8 -> V_2 = V_2 ;
V_8 -> V_110 = 1 ;
V_8 -> V_60 = V_126 / 2 ;
V_8 -> V_25 = ~ V_126 & 1 ;
V_8 -> V_8 . V_157 = V_260 [ V_126 ] ;
V_8 -> V_8 . V_262 = & V_263 ;
if ( V_8 -> V_25 )
V_8 -> V_9 = V_8 -> V_60 * V_264 ;
else
V_8 -> V_9 = ( V_257 + V_8 -> V_60 ) *
V_264 ;
V_8 -> V_8 . V_145 = V_265 ;
F_101 ( & V_8 -> V_8 . V_261 , & V_2 -> V_99 . V_261 ) ;
F_94 ( & V_8 -> V_111 ) ;
}
V_2 -> V_8 [ V_151 ] . V_8 . V_145 = V_211 ;
V_2 -> V_8 [ V_202 ] . V_8 . V_145 = V_217 ;
F_74 ( & V_2 -> V_8 [ V_151 ] . V_8 . V_261 ) ;
F_74 ( & V_2 -> V_8 [ V_202 ] . V_8 . V_261 ) ;
V_2 -> V_99 . V_208 = & V_2 -> V_8 [ V_151 ] . V_8 ;
F_94 ( & V_2 -> V_99 . V_208 -> V_261 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
F_61 ( V_2 ) ;
F_130 ( V_2 ) ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_179 * V_180 ;
struct V_123 * V_125 ;
V_2 -> V_129 = F_133 ( L_48 , V_2 -> V_13 ,
sizeof( struct V_123 ) , 0 , 0 ) ;
if ( ! V_2 -> V_129 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_49 ,
V_14 ) ;
return - V_142 ;
}
V_2 -> V_266 = F_133 ( L_50 , V_2 -> V_13 ,
sizeof( struct V_179 ) , 0 , 0 ) ;
if ( ! V_2 -> V_266 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_51 ,
V_14 ) ;
return - V_142 ;
}
V_180 = F_87 ( V_2 -> V_266 , V_267 ,
& V_2 -> V_8 [ V_202 ] . V_215 ) ;
if ( ! V_180 ) {
F_13 ( & V_2 -> V_13 -> V_2 ,
L_52 , V_14 ) ;
return - V_142 ;
}
V_2 -> V_8 [ V_202 ] . V_180 = V_180 ;
V_125 = F_87 ( V_2 -> V_129 , V_267 ,
& V_2 -> V_8 [ V_202 ] . V_141 ) ;
if ( ! V_125 ) {
F_13 ( & V_2 -> V_13 -> V_2 ,
L_53 , V_14 ) ;
return - V_142 ;
}
V_2 -> V_8 [ V_202 ] . V_125 = V_125 ;
V_2 -> V_8 [ V_151 ] . V_180 = NULL ;
V_2 -> V_8 [ V_151 ] . V_215 = 0 ;
V_2 -> V_8 [ V_151 ] . V_125 = NULL ;
V_2 -> V_8 [ V_151 ] . V_141 = 0 ;
V_2 -> V_268 = F_96 ( V_216 * 4 , V_267 ) ;
if ( ! V_2 -> V_268 )
return - V_142 ;
V_2 -> V_134 = F_100 ( & V_2 -> V_13 -> V_2 , V_2 -> V_268 ,
V_216 * 4 ,
V_118 ) ;
return 0 ;
}
static int F_134 ( struct V_269 * V_161 ,
int (* F_135)( struct V_98 * ) )
{
struct V_1 * V_2 = V_270 ;
int V_144 ;
if ( ! V_161 || ( V_161 -> V_162 == V_163 ) || ! F_135 ||
! V_161 -> V_210 || ! V_161 -> V_271 || ! V_161 -> V_220 ) {
F_13 ( & V_2 -> V_13 -> V_2 ,
L_54 , V_14 ) ;
return - V_100 ;
}
if ( ! V_2 )
return - V_272 ;
if ( V_2 -> V_161 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_55 , V_14 ) ;
return - V_273 ;
}
V_161 -> V_161 . V_274 = NULL ;
V_2 -> V_161 = V_161 ;
V_2 -> V_99 . V_2 . V_161 = & V_161 -> V_161 ;
V_144 = F_135 ( & V_2 -> V_99 ) ;
if ( V_144 ) {
F_13 ( & V_2 -> V_13 -> V_2 , L_56 ,
V_14 , V_161 -> V_161 . V_157 , V_144 ) ;
V_2 -> V_161 = NULL ;
V_2 -> V_99 . V_2 . V_161 = NULL ;
return V_144 ;
}
F_127 ( V_2 ) ;
F_23 ( V_2 ) ;
V_2 -> V_275 = 1 ;
return 0 ;
}
static int F_136 ( struct V_269 * V_161 )
{
struct V_1 * V_2 = V_270 ;
if ( ! V_2 )
return - V_272 ;
if ( ! V_161 || ( V_161 != V_2 -> V_161 ) ) {
F_13 ( & V_2 -> V_13 -> V_2 ,
L_54 , V_14 ) ;
return - V_100 ;
}
F_38 ( V_2 , V_85 ) ;
V_161 -> V_220 ( & V_2 -> V_99 ) ;
V_161 -> V_271 ( & V_2 -> V_99 ) ;
V_2 -> V_99 . V_2 . V_161 = NULL ;
V_2 -> V_161 = NULL ;
V_2 -> V_275 = 0 ;
F_22 ( V_2 ) ;
return 0 ;
}
static void F_137 ( struct V_276 * V_13 )
{
struct V_1 * V_2 = F_138 ( V_13 ) ;
F_38 ( V_2 , V_85 ) ;
F_40 ( V_2 , V_86 ) ;
F_22 ( V_2 ) ;
}
static void F_139 ( struct V_276 * V_13 )
{
struct V_1 * V_2 = F_138 ( V_13 ) ;
F_140 ( & V_2 -> V_99 ) ;
if ( V_2 -> V_161 )
F_13 ( & V_13 -> V_2 ,
L_57 , V_14 ) ;
if ( V_2 -> V_129 )
F_141 ( V_2 -> V_129 ) ;
if ( V_2 -> V_266 ) {
if ( V_2 -> V_8 [ V_202 ] . V_180 ) {
F_84 ( V_2 -> V_266 ,
V_2 -> V_8 [ V_202 ] . V_180 ,
V_2 -> V_8 [ V_202 ] . V_215 ) ;
}
if ( V_2 -> V_8 [ V_202 ] . V_125 ) {
F_84 ( V_2 -> V_266 ,
V_2 -> V_8 [ V_202 ] . V_125 ,
V_2 -> V_8 [ V_202 ] . V_141 ) ;
}
F_141 ( V_2 -> V_266 ) ;
}
if ( V_2 -> V_134 )
F_75 ( & V_2 -> V_13 -> V_2 , V_2 -> V_134 ,
V_216 * 4 , V_118 ) ;
F_76 ( V_2 -> V_268 ) ;
F_63 ( V_2 ) ;
if ( V_2 -> V_277 )
F_142 ( V_13 -> V_255 , V_2 ) ;
if ( V_2 -> V_4 )
F_143 ( V_2 -> V_4 ) ;
if ( V_2 -> V_278 )
F_144 ( V_2 -> V_279 ,
F_145 ( V_13 , V_280 ) ) ;
if ( V_2 -> V_281 )
F_146 ( V_13 ) ;
if ( V_2 -> V_282 )
F_147 ( & V_2 -> V_99 . V_2 ) ;
F_76 ( V_2 ) ;
F_148 ( V_13 , NULL ) ;
}
static int F_149 ( struct V_276 * V_13 , T_6 V_283 )
{
struct V_1 * V_2 = F_138 ( V_13 ) ;
F_38 ( V_2 , V_85 ) ;
F_40 ( V_2 , V_86 ) ;
F_146 ( V_13 ) ;
F_150 ( V_13 , V_284 , 0 ) ;
if ( F_151 ( V_13 ) ) {
F_13 ( & V_13 -> V_2 ,
L_58 , V_14 ) ;
return - V_142 ;
}
F_152 ( V_13 , F_153 ( V_13 , V_283 ) ) ;
return 0 ;
}
static int F_154 ( struct V_276 * V_13 )
{
int V_172 ;
F_152 ( V_13 , V_285 ) ;
F_155 ( V_13 ) ;
V_172 = F_156 ( V_13 ) ;
if ( V_172 ) {
F_13 ( & V_13 -> V_2 , L_59 , V_14 ) ;
return V_172 ;
}
F_150 ( V_13 , V_284 , 0 ) ;
return 0 ;
}
static int F_157 ( struct V_276 * V_13 ,
const struct V_286 * V_287 )
{
unsigned long V_288 ;
unsigned long V_135 ;
int V_144 ;
struct V_1 * V_2 ;
if ( V_270 ) {
F_62 ( L_60 , V_14 ) ;
return - V_273 ;
}
V_2 = F_96 ( sizeof *V_2 , V_267 ) ;
if ( ! V_2 ) {
F_62 ( L_61 , V_14 ) ;
return - V_142 ;
}
if ( F_156 ( V_13 ) < 0 ) {
F_76 ( V_2 ) ;
F_62 ( L_59 , V_14 ) ;
return - V_272 ;
}
V_2 -> V_281 = 1 ;
F_148 ( V_13 , V_2 ) ;
V_288 = F_158 ( V_13 , 1 ) ;
V_135 = F_145 ( V_13 , 1 ) ;
if ( ! F_159 ( V_288 , V_135 , V_289 ) ) {
F_13 ( & V_13 -> V_2 , L_62 , V_14 ) ;
V_144 = - V_273 ;
goto V_290;
}
V_2 -> V_279 = V_288 ;
V_2 -> V_278 = 1 ;
V_2 -> V_4 = F_160 ( V_288 , V_135 ) ;
if ( ! V_2 -> V_4 ) {
F_62 ( L_63 , V_14 ) ;
V_144 = - V_142 ;
goto V_290;
}
if ( ! V_13 -> V_255 ) {
F_13 ( & V_13 -> V_2 , L_64 , V_14 ) ;
V_144 = - V_272 ;
goto V_290;
}
V_270 = V_2 ;
if ( F_131 ( V_2 ) )
goto V_290;
if ( F_161 ( V_13 -> V_255 , F_126 , V_291 , V_289 ,
V_2 ) ) {
F_13 ( & V_13 -> V_2 , L_65 , V_14 ,
V_13 -> V_255 ) ;
V_144 = - V_272 ;
goto V_290;
}
V_2 -> V_255 = V_13 -> V_255 ;
V_2 -> V_277 = 1 ;
F_162 ( V_13 ) ;
F_163 ( V_13 ) ;
F_164 ( & V_2 -> V_102 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_99 . V_262 = & V_292 ;
V_144 = F_132 ( V_2 ) ;
if ( V_144 )
goto V_290;
F_165 ( & V_2 -> V_99 . V_2 , L_66 ) ;
V_2 -> V_99 . V_2 . V_293 = & V_13 -> V_2 ;
V_2 -> V_99 . V_2 . V_294 = V_13 -> V_2 . V_294 ;
V_2 -> V_99 . V_2 . V_295 = F_128 ;
V_2 -> V_99 . V_157 = V_289 ;
V_2 -> V_99 . V_296 = 1 ;
V_144 = F_166 ( & V_2 -> V_99 . V_2 ) ;
if ( V_144 )
goto V_290;
V_2 -> V_282 = 1 ;
F_22 ( V_2 ) ;
V_144 = F_167 ( & V_13 -> V_2 , & V_2 -> V_99 ) ;
if ( V_144 )
goto V_290;
return 0 ;
V_290:
F_139 ( V_13 ) ;
return V_144 ;
}
static int T_7 F_168 ( void )
{
return F_169 ( & V_297 ) ;
}
static void T_8 F_170 ( void )
{
F_171 ( & V_297 ) ;
}
