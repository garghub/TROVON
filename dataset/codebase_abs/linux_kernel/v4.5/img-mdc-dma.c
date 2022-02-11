static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_1 F_5 ( struct V_6 * V_7 , T_1 V_3 )
{
return F_1 ( V_7 -> V_2 , V_7 -> V_8 * 0x040 + V_3 ) ;
}
static inline void F_6 ( struct V_6 * V_7 , T_1 V_5 , T_1 V_3 )
{
F_3 ( V_7 -> V_2 , V_5 , V_7 -> V_8 * 0x040 + V_3 ) ;
}
static inline struct V_6 * F_7 ( struct V_9 * V_10 )
{
return F_8 ( F_9 ( V_10 ) , struct V_6 , V_11 ) ;
}
static inline struct V_12 * F_10 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_8 ( V_14 , struct V_15 , V_17 ) ;
return F_8 ( V_16 , struct V_12 , V_18 ) ;
}
static inline struct V_19 * F_11 ( struct V_1 * V_2 )
{
return V_2 -> V_20 . V_21 ;
}
static inline unsigned int F_12 ( unsigned int V_22 )
{
return F_13 ( V_22 ) - 1 ;
}
static inline void F_14 ( struct V_23 * V_24 ,
unsigned int V_22 )
{
V_24 -> V_25 |= F_12 ( V_22 ) <<
V_26 ;
}
static inline void F_15 ( struct V_23 * V_24 ,
unsigned int V_22 )
{
V_24 -> V_25 |= F_12 ( V_22 ) <<
V_27 ;
}
static void F_16 ( struct V_6 * V_7 ,
struct V_23 * V_24 ,
enum V_28 V_29 ,
T_2 V_30 , T_2 V_31 , T_3 V_32 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned int V_33 , V_34 ;
V_24 -> V_25 = V_35 | V_36 |
V_37 | V_38 |
V_39 ;
V_24 -> V_40 =
( V_7 -> V_41 << V_42 ) |
( V_7 -> V_41 << V_43 ) |
( V_7 -> V_41 << V_44 ) ;
V_24 -> V_45 = V_30 ;
V_24 -> V_46 = V_31 ;
V_24 -> V_47 = V_32 - 1 ;
V_24 -> V_48 = 0 ;
V_24 -> V_49 = 0 ;
V_24 -> V_50 = V_51 |
V_52 ;
V_24 -> V_53 = NULL ;
if ( F_17 ( V_31 , V_2 -> V_54 ) &&
F_17 ( V_30 , V_2 -> V_54 ) )
V_33 = V_2 -> V_54 * V_2 -> V_55 ;
else
V_33 = V_2 -> V_54 * ( V_2 -> V_55 - 1 ) ;
if ( V_29 == V_56 ) {
V_24 -> V_25 |= V_57 ;
V_24 -> V_40 |= V_58 ;
F_14 ( V_24 , V_2 -> V_54 ) ;
F_15 ( V_24 , V_7 -> V_59 . V_60 ) ;
V_34 = F_18 ( V_33 , V_7 -> V_59 . V_61 *
V_7 -> V_59 . V_60 ) ;
} else if ( V_29 == V_62 ) {
V_24 -> V_25 |= V_63 ;
V_24 -> V_40 |= V_58 ;
F_14 ( V_24 , V_7 -> V_59 . V_64 ) ;
F_15 ( V_24 , V_2 -> V_54 ) ;
V_34 = F_18 ( V_33 , V_7 -> V_59 . V_65 *
V_7 -> V_59 . V_64 ) ;
} else {
V_24 -> V_25 |= V_57 |
V_63 ;
F_14 ( V_24 , V_2 -> V_54 ) ;
F_15 ( V_24 , V_2 -> V_54 ) ;
V_34 = V_33 ;
}
V_24 -> V_40 |= ( V_34 - 1 ) <<
V_66 ;
}
static void F_19 ( struct V_12 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_68 -> V_2 ;
struct V_23 * V_69 , * V_70 ;
T_2 V_71 , V_72 ;
V_69 = V_67 -> V_73 ;
V_71 = V_67 -> V_74 ;
while ( V_69 ) {
V_70 = V_69 -> V_53 ;
V_72 = V_69 -> V_48 ;
F_20 ( V_2 -> V_75 , V_69 , V_71 ) ;
V_69 = V_70 ;
V_71 = V_72 ;
}
}
static void F_21 ( struct V_15 * V_18 )
{
struct V_12 * V_67 = F_10 ( & V_18 -> V_17 ) ;
F_19 ( V_67 ) ;
F_22 ( V_67 ) ;
}
static struct V_13 * F_23 (
struct V_9 * V_68 , T_2 V_76 , T_2 V_30 , T_3 V_32 ,
unsigned long V_77 )
{
struct V_6 * V_7 = F_7 ( V_68 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_12 * V_67 ;
struct V_23 * V_69 , * V_78 = NULL ;
T_2 V_71 , V_79 ;
if ( ! V_32 )
return NULL ;
V_67 = F_24 ( sizeof( * V_67 ) , V_80 ) ;
if ( ! V_67 )
return NULL ;
V_67 -> V_68 = V_7 ;
V_67 -> V_81 = V_32 ;
while ( V_32 > 0 ) {
T_3 V_47 ;
V_69 = F_25 ( V_2 -> V_75 , V_80 , & V_71 ) ;
if ( ! V_69 )
goto V_82;
if ( V_78 ) {
V_78 -> V_48 = V_71 ;
V_78 -> V_53 = V_69 ;
} else {
V_67 -> V_74 = V_71 ;
V_67 -> V_73 = V_69 ;
}
V_47 = F_26 ( T_3 , V_2 -> V_83 , V_32 ) ;
F_16 ( V_7 , V_69 , V_84 , V_30 , V_76 ,
V_47 ) ;
V_78 = V_69 ;
V_79 = V_71 ;
V_67 -> V_85 ++ ;
V_30 += V_47 ;
V_76 += V_47 ;
V_32 -= V_47 ;
}
return F_27 ( & V_7 -> V_11 , & V_67 -> V_18 , V_77 ) ;
V_82:
F_21 ( & V_67 -> V_18 ) ;
return NULL ;
}
static int F_28 ( struct V_6 * V_7 ,
enum V_28 V_29 )
{
enum V_86 V_87 ;
if ( V_29 == V_56 )
V_87 = V_7 -> V_59 . V_60 ;
else
V_87 = V_7 -> V_59 . V_64 ;
switch ( V_87 ) {
case V_88 :
case V_89 :
case V_90 :
case V_91 :
break;
default:
return - V_92 ;
}
if ( V_87 > V_7 -> V_2 -> V_54 )
return - V_92 ;
return 0 ;
}
static struct V_13 * F_29 (
struct V_9 * V_68 , T_2 V_93 , T_3 V_94 ,
T_3 V_95 , enum V_28 V_29 ,
unsigned long V_77 )
{
struct V_6 * V_7 = F_7 ( V_68 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_12 * V_67 ;
struct V_23 * V_69 , * V_78 = NULL ;
T_2 V_71 , V_79 ;
if ( ! V_94 && ! V_95 )
return NULL ;
if ( ! F_30 ( V_29 ) )
return NULL ;
if ( F_28 ( V_7 , V_29 ) < 0 )
return NULL ;
V_67 = F_24 ( sizeof( * V_67 ) , V_80 ) ;
if ( ! V_67 )
return NULL ;
V_67 -> V_68 = V_7 ;
V_67 -> V_96 = true ;
V_67 -> V_81 = V_94 ;
V_67 -> V_97 = F_31 ( V_95 ,
V_2 -> V_83 ) ;
while ( V_94 > 0 ) {
T_3 V_98 = F_18 ( V_95 , V_94 ) ;
while ( V_98 > 0 ) {
T_3 V_47 ;
V_69 = F_25 ( V_2 -> V_75 , V_80 ,
& V_71 ) ;
if ( ! V_69 )
goto V_82;
if ( ! V_78 ) {
V_67 -> V_74 = V_71 ;
V_67 -> V_73 = V_69 ;
} else {
V_78 -> V_48 = V_71 ;
V_78 -> V_53 = V_69 ;
}
V_47 = F_26 ( T_3 , V_2 -> V_83 ,
V_98 ) ;
if ( V_29 == V_56 ) {
F_16 ( V_7 , V_69 , V_29 ,
V_93 ,
V_7 -> V_59 . V_99 ,
V_47 ) ;
} else {
F_16 ( V_7 , V_69 , V_29 ,
V_7 -> V_59 . V_100 ,
V_93 ,
V_47 ) ;
}
V_78 = V_69 ;
V_79 = V_71 ;
V_67 -> V_85 ++ ;
V_93 += V_47 ;
V_94 -= V_47 ;
V_98 -= V_47 ;
}
}
V_78 -> V_48 = V_67 -> V_74 ;
return F_27 ( & V_7 -> V_11 , & V_67 -> V_18 , V_77 ) ;
V_82:
F_21 ( & V_67 -> V_18 ) ;
return NULL ;
}
static struct V_13 * F_32 (
struct V_9 * V_68 , struct V_101 * V_102 ,
unsigned int V_103 , enum V_28 V_29 ,
unsigned long V_77 , void * V_104 )
{
struct V_6 * V_7 = F_7 ( V_68 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_12 * V_67 ;
struct V_101 * V_105 ;
struct V_23 * V_69 , * V_78 = NULL ;
T_2 V_71 , V_79 ;
unsigned int V_106 ;
if ( ! V_102 )
return NULL ;
if ( ! F_30 ( V_29 ) )
return NULL ;
if ( F_28 ( V_7 , V_29 ) < 0 )
return NULL ;
V_67 = F_24 ( sizeof( * V_67 ) , V_80 ) ;
if ( ! V_67 )
return NULL ;
V_67 -> V_68 = V_7 ;
F_33 (sgl, sg, sg_len, i) {
T_2 V_107 = F_34 ( V_105 ) ;
T_3 V_94 = F_35 ( V_105 ) ;
while ( V_94 > 0 ) {
T_3 V_47 ;
V_69 = F_25 ( V_2 -> V_75 , V_80 ,
& V_71 ) ;
if ( ! V_69 )
goto V_82;
if ( ! V_78 ) {
V_67 -> V_74 = V_71 ;
V_67 -> V_73 = V_69 ;
} else {
V_78 -> V_48 = V_71 ;
V_78 -> V_53 = V_69 ;
}
V_47 = F_26 ( T_3 , V_2 -> V_83 ,
V_94 ) ;
if ( V_29 == V_56 ) {
F_16 ( V_7 , V_69 , V_29 , V_107 ,
V_7 -> V_59 . V_99 ,
V_47 ) ;
} else {
F_16 ( V_7 , V_69 , V_29 ,
V_7 -> V_59 . V_100 ,
V_107 , V_47 ) ;
}
V_78 = V_69 ;
V_79 = V_71 ;
V_67 -> V_85 ++ ;
V_67 -> V_81 += V_47 ;
V_107 += V_47 ;
V_94 -= V_47 ;
}
}
return F_27 ( & V_7 -> V_11 , & V_67 -> V_18 , V_77 ) ;
V_82:
F_21 ( & V_67 -> V_18 ) ;
return NULL ;
}
static void F_36 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_15 * V_18 ;
struct V_12 * V_67 ;
T_1 V_5 ;
V_18 = F_37 ( & V_7 -> V_11 ) ;
if ( ! V_18 )
return;
F_38 ( & V_18 -> V_108 ) ;
V_67 = F_10 ( & V_18 -> V_17 ) ;
V_7 -> V_109 = V_67 ;
F_39 ( F_11 ( V_2 ) , L_1 ,
V_7 -> V_8 ) ;
V_2 -> V_110 -> V_111 ( V_7 ) ;
V_5 = F_5 ( V_7 , V_112 ) ;
V_5 |= V_36 | V_35 |
V_37 | V_38 |
V_39 ;
F_6 ( V_7 , V_5 , V_112 ) ;
V_5 = ( V_7 -> V_41 << V_42 ) |
( V_7 -> V_41 << V_43 ) |
( V_7 -> V_41 << V_44 ) ;
F_6 ( V_7 , V_5 , V_113 ) ;
F_6 ( V_7 , V_67 -> V_74 , V_114 ) ;
V_5 = F_5 ( V_7 , V_115 ) ;
V_5 |= V_51 ;
F_6 ( V_7 , V_5 , V_115 ) ;
}
static void F_40 ( struct V_9 * V_68 )
{
struct V_6 * V_7 = F_7 ( V_68 ) ;
unsigned long V_77 ;
F_41 ( & V_7 -> V_11 . V_116 , V_77 ) ;
if ( F_42 ( & V_7 -> V_11 ) && ! V_7 -> V_109 )
F_36 ( V_7 ) ;
F_43 ( & V_7 -> V_11 . V_116 , V_77 ) ;
}
static enum V_117 F_44 ( struct V_9 * V_68 ,
T_4 V_118 , struct V_119 * V_120 )
{
struct V_6 * V_7 = F_7 ( V_68 ) ;
struct V_12 * V_67 ;
struct V_15 * V_18 ;
unsigned long V_77 ;
T_3 V_22 = 0 ;
int V_121 ;
V_121 = F_45 ( V_68 , V_118 , V_120 ) ;
if ( V_121 == V_122 )
return V_121 ;
if ( ! V_120 )
return V_121 ;
F_41 ( & V_7 -> V_11 . V_116 , V_77 ) ;
V_18 = F_46 ( & V_7 -> V_11 , V_118 ) ;
if ( V_18 ) {
V_67 = F_10 ( & V_18 -> V_17 ) ;
V_22 = V_67 -> V_81 ;
} else if ( V_7 -> V_109 && V_7 -> V_109 -> V_18 . V_17 . V_118 == V_118 ) {
struct V_23 * V_24 ;
T_1 V_123 , V_124 , V_125 , V_126 , V_127 ;
int V_106 , V_128 ;
V_67 = V_7 -> V_109 ;
do {
V_123 = F_5 ( V_7 , V_129 ) &
~ V_130 ;
V_127 = F_5 ( V_7 ,
V_131 ) ;
V_124 = F_5 ( V_7 , V_129 ) &
~ V_130 ;
} while ( V_123 != V_124 );
V_125 = ( V_123 >> V_132 ) &
V_133 ;
V_126 = ( V_123 >> V_134 ) &
V_135 ;
V_128 = ( V_125 - V_126 ) %
( V_133 + 1 ) ;
if ( ! V_67 -> V_136 )
V_128 -- ;
else
V_128 += V_67 -> V_137 ;
V_22 = V_67 -> V_81 ;
V_24 = V_67 -> V_73 ;
for ( V_106 = 0 ; V_106 < V_128 ; V_106 ++ ) {
V_22 -= V_24 -> V_47 + 1 ;
V_24 = V_24 -> V_53 ;
}
if ( V_24 ) {
if ( V_127 != V_138 )
V_22 -= V_24 -> V_47 - V_127 ;
else
V_22 -= V_24 -> V_47 + 1 ;
}
}
F_43 ( & V_7 -> V_11 . V_116 , V_77 ) ;
F_47 ( V_120 , V_22 ) ;
return V_121 ;
}
static unsigned int F_48 ( struct V_6 * V_7 )
{
T_1 V_5 , V_126 , V_139 , V_140 ;
unsigned int V_121 ;
V_5 = F_5 ( V_7 , V_129 ) ;
V_126 = ( V_5 >> V_134 ) &
V_135 ;
do {
V_5 = F_5 ( V_7 , V_129 ) ;
V_139 = ( V_5 >> V_132 ) &
V_133 ;
V_5 &= ~ ( ( V_135 <<
V_134 ) |
V_130 ) ;
V_5 |= V_139 << V_134 ;
F_6 ( V_7 , V_5 , V_129 ) ;
V_5 = F_5 ( V_7 , V_129 ) ;
V_140 = ( V_5 >> V_132 ) &
V_133 ;
} while ( V_139 != V_140 );
if ( V_139 >= V_126 )
V_121 = V_139 - V_126 ;
else
V_121 = ( ( V_135 + 1 ) -
V_126 ) + V_139 ;
return V_121 ;
}
static int F_49 ( struct V_9 * V_68 )
{
struct V_6 * V_7 = F_7 ( V_68 ) ;
struct V_12 * V_67 ;
unsigned long V_77 ;
F_50 ( V_141 ) ;
F_41 ( & V_7 -> V_11 . V_116 , V_77 ) ;
F_6 ( V_7 , V_142 ,
V_115 ) ;
V_67 = V_7 -> V_109 ;
V_7 -> V_109 = NULL ;
F_51 ( & V_7 -> V_11 , & V_141 ) ;
F_48 ( V_7 ) ;
F_43 ( & V_7 -> V_11 . V_116 , V_77 ) ;
if ( V_67 )
F_21 ( & V_67 -> V_18 ) ;
F_52 ( & V_7 -> V_11 , & V_141 ) ;
return 0 ;
}
static int F_53 ( struct V_9 * V_68 ,
struct V_143 * V_59 )
{
struct V_6 * V_7 = F_7 ( V_68 ) ;
unsigned long V_77 ;
F_41 ( & V_7 -> V_11 . V_116 , V_77 ) ;
V_7 -> V_59 = * V_59 ;
F_43 ( & V_7 -> V_11 . V_116 , V_77 ) ;
return 0 ;
}
static void F_54 ( struct V_9 * V_68 )
{
struct V_6 * V_7 = F_7 ( V_68 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_49 ( V_68 ) ;
V_2 -> V_110 -> V_144 ( V_7 ) ;
}
static T_5 F_55 ( int V_145 , void * V_146 )
{
struct V_6 * V_7 = (struct V_6 * ) V_146 ;
struct V_12 * V_67 ;
unsigned int V_106 , V_147 ;
F_56 ( & V_7 -> V_11 . V_116 ) ;
F_39 ( F_11 ( V_7 -> V_2 ) , L_2 , V_7 -> V_8 ) ;
V_147 = F_48 ( V_7 ) ;
if ( ! V_147 )
goto V_148;
V_67 = V_7 -> V_109 ;
if ( ! V_67 ) {
F_57 ( F_11 ( V_7 -> V_2 ) ,
L_3 ,
V_7 -> V_8 ) ;
goto V_148;
}
for ( V_106 = 0 ; V_106 < V_147 ; V_106 ++ ) {
if ( ! V_67 -> V_136 ) {
V_67 -> V_136 = true ;
continue;
}
V_67 -> V_137 ++ ;
if ( V_67 -> V_96 ) {
V_67 -> V_137 %= V_67 -> V_85 ;
if ( V_67 -> V_137 % V_67 -> V_97 == 0 )
F_58 ( & V_67 -> V_18 ) ;
} else if ( V_67 -> V_137 == V_67 -> V_85 ) {
V_7 -> V_109 = NULL ;
F_59 ( & V_67 -> V_18 ) ;
F_36 ( V_7 ) ;
break;
}
}
V_148:
F_60 ( & V_7 -> V_11 . V_116 ) ;
return V_149 ;
}
static struct V_9 * F_61 ( struct V_150 * V_151 ,
struct V_152 * V_153 )
{
struct V_1 * V_2 = V_153 -> V_154 ;
struct V_9 * V_68 ;
if ( V_151 -> V_155 != 3 )
return NULL ;
F_62 (chan, &mdma->dma_dev.channels, device_node) {
struct V_6 * V_7 = F_7 ( V_68 ) ;
if ( ! ( V_151 -> args [ 1 ] & F_63 ( V_7 -> V_8 ) ) )
continue;
if ( F_64 ( V_68 ) ) {
V_7 -> V_156 = V_151 -> args [ 0 ] ;
V_7 -> V_41 = V_151 -> args [ 2 ] ;
return V_68 ;
}
}
return NULL ;
}
static void F_65 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_66 ( V_2 -> V_157 ,
F_67 ( V_7 -> V_8 ) ,
V_158 <<
F_68 ( V_7 -> V_8 ) ,
V_7 -> V_156 <<
F_68 ( V_7 -> V_8 ) ) ;
}
static void F_69 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_66 ( V_2 -> V_157 ,
F_67 ( V_7 -> V_8 ) ,
V_158 <<
F_68 ( V_7 -> V_8 ) ,
0 ) ;
}
static int F_70 ( struct V_159 * V_160 )
{
struct V_1 * V_2 ;
struct V_161 * V_162 ;
const struct V_163 * V_164 ;
unsigned int V_106 ;
T_1 V_5 ;
int V_121 ;
V_2 = F_71 ( & V_160 -> V_21 , sizeof( * V_2 ) , V_165 ) ;
if ( ! V_2 )
return - V_166 ;
F_72 ( V_160 , V_2 ) ;
V_164 = F_73 ( V_167 , & V_160 -> V_21 ) ;
V_2 -> V_110 = V_164 -> V_168 ;
V_162 = F_74 ( V_160 , V_169 , 0 ) ;
V_2 -> V_4 = F_75 ( & V_160 -> V_21 , V_162 ) ;
if ( F_76 ( V_2 -> V_4 ) )
return F_77 ( V_2 -> V_4 ) ;
V_2 -> V_157 = F_78 ( V_160 -> V_21 . V_170 ,
L_4 ) ;
if ( F_76 ( V_2 -> V_157 ) )
return F_77 ( V_2 -> V_157 ) ;
V_2 -> V_171 = F_79 ( & V_160 -> V_21 , L_5 ) ;
if ( F_76 ( V_2 -> V_171 ) )
return F_77 ( V_2 -> V_171 ) ;
V_121 = F_80 ( V_2 -> V_171 ) ;
if ( V_121 )
return V_121 ;
F_81 ( V_2 -> V_20 . V_172 ) ;
F_82 ( V_173 , V_2 -> V_20 . V_172 ) ;
F_82 ( V_174 , V_2 -> V_20 . V_172 ) ;
F_82 ( V_175 , V_2 -> V_20 . V_172 ) ;
F_82 ( V_176 , V_2 -> V_20 . V_172 ) ;
V_5 = F_1 ( V_2 , V_177 ) ;
V_2 -> V_178 = ( V_5 >> V_179 ) &
V_180 ;
V_2 -> V_181 =
1 << ( ( V_5 >> V_182 ) &
V_183 ) ;
V_2 -> V_54 =
( 1 << ( ( V_5 >> V_184 ) &
V_185 ) ) / 8 ;
V_2 -> V_83 = V_138 + 1 - V_2 -> V_54 ;
F_83 ( V_160 -> V_21 . V_170 , L_6 ,
& V_2 -> V_178 ) ;
V_121 = F_83 ( V_160 -> V_21 . V_170 ,
L_7 ,
& V_2 -> V_55 ) ;
if ( V_121 )
goto V_186;
V_2 -> V_20 . V_21 = & V_160 -> V_21 ;
V_2 -> V_20 . V_187 = F_32 ;
V_2 -> V_20 . V_188 = F_29 ;
V_2 -> V_20 . V_189 = F_23 ;
V_2 -> V_20 . V_190 = F_54 ;
V_2 -> V_20 . V_191 = F_44 ;
V_2 -> V_20 . V_192 = F_40 ;
V_2 -> V_20 . V_193 = F_49 ;
V_2 -> V_20 . V_194 = F_53 ;
V_2 -> V_20 . V_195 = F_63 ( V_62 ) | F_63 ( V_56 ) ;
V_2 -> V_20 . V_196 = V_197 ;
for ( V_106 = 1 ; V_106 <= V_2 -> V_54 ; V_106 <<= 1 ) {
V_2 -> V_20 . V_198 |= F_63 ( V_106 ) ;
V_2 -> V_20 . V_199 |= F_63 ( V_106 ) ;
}
F_84 ( & V_2 -> V_20 . V_200 ) ;
for ( V_106 = 0 ; V_106 < V_2 -> V_178 ; V_106 ++ ) {
struct V_6 * V_7 = & V_2 -> V_200 [ V_106 ] ;
V_7 -> V_2 = V_2 ;
V_7 -> V_8 = V_106 ;
V_7 -> V_145 = F_85 ( V_160 , V_106 ) ;
if ( V_7 -> V_145 < 0 ) {
V_121 = V_7 -> V_145 ;
goto V_186;
}
V_121 = F_86 ( & V_160 -> V_21 , V_7 -> V_145 , F_55 ,
V_201 ,
F_87 ( & V_160 -> V_21 ) , V_7 ) ;
if ( V_121 < 0 )
goto V_186;
V_7 -> V_11 . V_202 = F_21 ;
F_88 ( & V_7 -> V_11 , & V_2 -> V_20 ) ;
}
V_2 -> V_75 = F_89 ( F_87 ( & V_160 -> V_21 ) , & V_160 -> V_21 ,
sizeof( struct V_23 ) ,
4 , 0 ) ;
if ( ! V_2 -> V_75 ) {
V_121 = - V_166 ;
goto V_186;
}
V_121 = F_90 ( & V_2 -> V_20 ) ;
if ( V_121 )
goto V_186;
V_121 = F_91 ( V_160 -> V_21 . V_170 , F_61 , V_2 ) ;
if ( V_121 )
goto V_203;
F_92 ( & V_160 -> V_21 , L_8 ,
V_2 -> V_178 , V_2 -> V_181 ) ;
return 0 ;
V_203:
F_93 ( & V_2 -> V_20 ) ;
V_186:
F_94 ( V_2 -> V_171 ) ;
return V_121 ;
}
static int F_95 ( struct V_159 * V_160 )
{
struct V_1 * V_2 = F_96 ( V_160 ) ;
struct V_6 * V_7 , * V_70 ;
F_97 ( V_160 -> V_21 . V_170 ) ;
F_93 ( & V_2 -> V_20 ) ;
F_98 (mchan, next, &mdma->dma_dev.channels,
vc.chan.device_node) {
F_38 ( & V_7 -> V_11 . V_68 . V_204 ) ;
F_99 ( & V_160 -> V_21 , V_7 -> V_145 , V_7 ) ;
F_100 ( & V_7 -> V_11 . V_205 ) ;
}
F_94 ( V_2 -> V_171 ) ;
return 0 ;
}
