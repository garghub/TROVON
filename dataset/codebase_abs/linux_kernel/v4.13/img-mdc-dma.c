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
T_2 V_71 ;
if ( ! V_32 )
return NULL ;
V_67 = F_24 ( sizeof( * V_67 ) , V_79 ) ;
if ( ! V_67 )
return NULL ;
V_67 -> V_68 = V_7 ;
V_67 -> V_80 = V_32 ;
while ( V_32 > 0 ) {
T_3 V_47 ;
V_69 = F_25 ( V_2 -> V_75 , V_79 , & V_71 ) ;
if ( ! V_69 )
goto V_81;
if ( V_78 ) {
V_78 -> V_48 = V_71 ;
V_78 -> V_53 = V_69 ;
} else {
V_67 -> V_74 = V_71 ;
V_67 -> V_73 = V_69 ;
}
V_47 = F_26 ( T_3 , V_2 -> V_82 , V_32 ) ;
F_16 ( V_7 , V_69 , V_83 , V_30 , V_76 ,
V_47 ) ;
V_78 = V_69 ;
V_67 -> V_84 ++ ;
V_30 += V_47 ;
V_76 += V_47 ;
V_32 -= V_47 ;
}
return F_27 ( & V_7 -> V_11 , & V_67 -> V_18 , V_77 ) ;
V_81:
F_21 ( & V_67 -> V_18 ) ;
return NULL ;
}
static int F_28 ( struct V_6 * V_7 ,
enum V_28 V_29 )
{
enum V_85 V_86 ;
if ( V_29 == V_56 )
V_86 = V_7 -> V_59 . V_60 ;
else
V_86 = V_7 -> V_59 . V_64 ;
switch ( V_86 ) {
case V_87 :
case V_88 :
case V_89 :
case V_90 :
break;
default:
return - V_91 ;
}
if ( V_86 > V_7 -> V_2 -> V_54 )
return - V_91 ;
return 0 ;
}
static struct V_13 * F_29 (
struct V_9 * V_68 , T_2 V_92 , T_3 V_93 ,
T_3 V_94 , enum V_28 V_29 ,
unsigned long V_77 )
{
struct V_6 * V_7 = F_7 ( V_68 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_12 * V_67 ;
struct V_23 * V_69 , * V_78 = NULL ;
T_2 V_71 ;
if ( ! V_93 && ! V_94 )
return NULL ;
if ( ! F_30 ( V_29 ) )
return NULL ;
if ( F_28 ( V_7 , V_29 ) < 0 )
return NULL ;
V_67 = F_24 ( sizeof( * V_67 ) , V_79 ) ;
if ( ! V_67 )
return NULL ;
V_67 -> V_68 = V_7 ;
V_67 -> V_95 = true ;
V_67 -> V_80 = V_93 ;
V_67 -> V_96 = F_31 ( V_94 ,
V_2 -> V_82 ) ;
while ( V_93 > 0 ) {
T_3 V_97 = F_18 ( V_94 , V_93 ) ;
while ( V_97 > 0 ) {
T_3 V_47 ;
V_69 = F_25 ( V_2 -> V_75 , V_79 ,
& V_71 ) ;
if ( ! V_69 )
goto V_81;
if ( ! V_78 ) {
V_67 -> V_74 = V_71 ;
V_67 -> V_73 = V_69 ;
} else {
V_78 -> V_48 = V_71 ;
V_78 -> V_53 = V_69 ;
}
V_47 = F_26 ( T_3 , V_2 -> V_82 ,
V_97 ) ;
if ( V_29 == V_56 ) {
F_16 ( V_7 , V_69 , V_29 ,
V_92 ,
V_7 -> V_59 . V_98 ,
V_47 ) ;
} else {
F_16 ( V_7 , V_69 , V_29 ,
V_7 -> V_59 . V_99 ,
V_92 ,
V_47 ) ;
}
V_78 = V_69 ;
V_67 -> V_84 ++ ;
V_92 += V_47 ;
V_93 -= V_47 ;
V_97 -= V_47 ;
}
}
V_78 -> V_48 = V_67 -> V_74 ;
return F_27 ( & V_7 -> V_11 , & V_67 -> V_18 , V_77 ) ;
V_81:
F_21 ( & V_67 -> V_18 ) ;
return NULL ;
}
static struct V_13 * F_32 (
struct V_9 * V_68 , struct V_100 * V_101 ,
unsigned int V_102 , enum V_28 V_29 ,
unsigned long V_77 , void * V_103 )
{
struct V_6 * V_7 = F_7 ( V_68 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_12 * V_67 ;
struct V_100 * V_104 ;
struct V_23 * V_69 , * V_78 = NULL ;
T_2 V_71 ;
unsigned int V_105 ;
if ( ! V_101 )
return NULL ;
if ( ! F_30 ( V_29 ) )
return NULL ;
if ( F_28 ( V_7 , V_29 ) < 0 )
return NULL ;
V_67 = F_24 ( sizeof( * V_67 ) , V_79 ) ;
if ( ! V_67 )
return NULL ;
V_67 -> V_68 = V_7 ;
F_33 (sgl, sg, sg_len, i) {
T_2 V_106 = F_34 ( V_104 ) ;
T_3 V_93 = F_35 ( V_104 ) ;
while ( V_93 > 0 ) {
T_3 V_47 ;
V_69 = F_25 ( V_2 -> V_75 , V_79 ,
& V_71 ) ;
if ( ! V_69 )
goto V_81;
if ( ! V_78 ) {
V_67 -> V_74 = V_71 ;
V_67 -> V_73 = V_69 ;
} else {
V_78 -> V_48 = V_71 ;
V_78 -> V_53 = V_69 ;
}
V_47 = F_26 ( T_3 , V_2 -> V_82 ,
V_93 ) ;
if ( V_29 == V_56 ) {
F_16 ( V_7 , V_69 , V_29 , V_106 ,
V_7 -> V_59 . V_98 ,
V_47 ) ;
} else {
F_16 ( V_7 , V_69 , V_29 ,
V_7 -> V_59 . V_99 ,
V_106 , V_47 ) ;
}
V_78 = V_69 ;
V_67 -> V_84 ++ ;
V_67 -> V_80 += V_47 ;
V_106 += V_47 ;
V_93 -= V_47 ;
}
}
return F_27 ( & V_7 -> V_11 , & V_67 -> V_18 , V_77 ) ;
V_81:
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
F_38 ( & V_18 -> V_107 ) ;
V_67 = F_10 ( & V_18 -> V_17 ) ;
V_7 -> V_108 = V_67 ;
F_39 ( F_11 ( V_2 ) , L_1 ,
V_7 -> V_8 ) ;
V_2 -> V_109 -> V_110 ( V_7 ) ;
V_5 = F_5 ( V_7 , V_111 ) ;
V_5 |= V_36 | V_35 |
V_37 | V_38 |
V_39 ;
F_6 ( V_7 , V_5 , V_111 ) ;
V_5 = ( V_7 -> V_41 << V_42 ) |
( V_7 -> V_41 << V_43 ) |
( V_7 -> V_41 << V_44 ) ;
F_6 ( V_7 , V_5 , V_112 ) ;
F_6 ( V_7 , V_67 -> V_74 , V_113 ) ;
V_5 = F_5 ( V_7 , V_114 ) ;
V_5 |= V_51 ;
F_6 ( V_7 , V_5 , V_114 ) ;
}
static void F_40 ( struct V_9 * V_68 )
{
struct V_6 * V_7 = F_7 ( V_68 ) ;
unsigned long V_77 ;
F_41 ( & V_7 -> V_11 . V_115 , V_77 ) ;
if ( F_42 ( & V_7 -> V_11 ) && ! V_7 -> V_108 )
F_36 ( V_7 ) ;
F_43 ( & V_7 -> V_11 . V_115 , V_77 ) ;
}
static enum V_116 F_44 ( struct V_9 * V_68 ,
T_4 V_117 , struct V_118 * V_119 )
{
struct V_6 * V_7 = F_7 ( V_68 ) ;
struct V_12 * V_67 ;
struct V_15 * V_18 ;
unsigned long V_77 ;
T_3 V_22 = 0 ;
int V_120 ;
V_120 = F_45 ( V_68 , V_117 , V_119 ) ;
if ( V_120 == V_121 )
return V_120 ;
if ( ! V_119 )
return V_120 ;
F_41 ( & V_7 -> V_11 . V_115 , V_77 ) ;
V_18 = F_46 ( & V_7 -> V_11 , V_117 ) ;
if ( V_18 ) {
V_67 = F_10 ( & V_18 -> V_17 ) ;
V_22 = V_67 -> V_80 ;
} else if ( V_7 -> V_108 && V_7 -> V_108 -> V_18 . V_17 . V_117 == V_117 ) {
struct V_23 * V_24 ;
T_1 V_122 , V_123 , V_124 , V_125 , V_126 ;
int V_105 , V_127 ;
V_67 = V_7 -> V_108 ;
do {
V_122 = F_5 ( V_7 , V_128 ) &
~ V_129 ;
V_126 = F_5 ( V_7 ,
V_130 ) ;
V_123 = F_5 ( V_7 , V_128 ) &
~ V_129 ;
} while ( V_122 != V_123 );
V_124 = ( V_122 >> V_131 ) &
V_132 ;
V_125 = ( V_122 >> V_133 ) &
V_134 ;
V_127 = ( V_124 - V_125 ) %
( V_132 + 1 ) ;
if ( ! V_67 -> V_135 )
V_127 -- ;
else
V_127 += V_67 -> V_136 ;
V_22 = V_67 -> V_80 ;
V_24 = V_67 -> V_73 ;
for ( V_105 = 0 ; V_105 < V_127 ; V_105 ++ ) {
V_22 -= V_24 -> V_47 + 1 ;
V_24 = V_24 -> V_53 ;
}
if ( V_24 ) {
if ( V_126 != V_137 )
V_22 -= V_24 -> V_47 - V_126 ;
else
V_22 -= V_24 -> V_47 + 1 ;
}
}
F_43 ( & V_7 -> V_11 . V_115 , V_77 ) ;
F_47 ( V_119 , V_22 ) ;
return V_120 ;
}
static unsigned int F_48 ( struct V_6 * V_7 )
{
T_1 V_5 , V_125 , V_138 , V_139 ;
unsigned int V_120 ;
V_5 = F_5 ( V_7 , V_128 ) ;
V_125 = ( V_5 >> V_133 ) &
V_134 ;
do {
V_5 = F_5 ( V_7 , V_128 ) ;
V_138 = ( V_5 >> V_131 ) &
V_132 ;
V_5 &= ~ ( ( V_134 <<
V_133 ) |
V_129 ) ;
V_5 |= V_138 << V_133 ;
F_6 ( V_7 , V_5 , V_128 ) ;
V_5 = F_5 ( V_7 , V_128 ) ;
V_139 = ( V_5 >> V_131 ) &
V_132 ;
} while ( V_138 != V_139 );
if ( V_138 >= V_125 )
V_120 = V_138 - V_125 ;
else
V_120 = ( ( V_134 + 1 ) -
V_125 ) + V_138 ;
return V_120 ;
}
static int F_49 ( struct V_9 * V_68 )
{
struct V_6 * V_7 = F_7 ( V_68 ) ;
struct V_12 * V_67 ;
unsigned long V_77 ;
F_50 ( V_140 ) ;
F_41 ( & V_7 -> V_11 . V_115 , V_77 ) ;
F_6 ( V_7 , V_141 ,
V_114 ) ;
V_67 = V_7 -> V_108 ;
V_7 -> V_108 = NULL ;
F_51 ( & V_7 -> V_11 , & V_140 ) ;
F_48 ( V_7 ) ;
F_43 ( & V_7 -> V_11 . V_115 , V_77 ) ;
if ( V_67 )
F_21 ( & V_67 -> V_18 ) ;
F_52 ( & V_7 -> V_11 , & V_140 ) ;
return 0 ;
}
static int F_53 ( struct V_9 * V_68 ,
struct V_142 * V_59 )
{
struct V_6 * V_7 = F_7 ( V_68 ) ;
unsigned long V_77 ;
F_41 ( & V_7 -> V_11 . V_115 , V_77 ) ;
V_7 -> V_59 = * V_59 ;
F_43 ( & V_7 -> V_11 . V_115 , V_77 ) ;
return 0 ;
}
static void F_54 ( struct V_9 * V_68 )
{
struct V_6 * V_7 = F_7 ( V_68 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_49 ( V_68 ) ;
V_2 -> V_109 -> V_143 ( V_7 ) ;
}
static T_5 F_55 ( int V_144 , void * V_145 )
{
struct V_6 * V_7 = (struct V_6 * ) V_145 ;
struct V_12 * V_67 ;
unsigned int V_105 , V_146 ;
F_56 ( & V_7 -> V_11 . V_115 ) ;
F_39 ( F_11 ( V_7 -> V_2 ) , L_2 , V_7 -> V_8 ) ;
V_146 = F_48 ( V_7 ) ;
if ( ! V_146 )
goto V_147;
V_67 = V_7 -> V_108 ;
if ( ! V_67 ) {
F_57 ( F_11 ( V_7 -> V_2 ) ,
L_3 ,
V_7 -> V_8 ) ;
goto V_147;
}
for ( V_105 = 0 ; V_105 < V_146 ; V_105 ++ ) {
if ( ! V_67 -> V_135 ) {
V_67 -> V_135 = true ;
continue;
}
V_67 -> V_136 ++ ;
if ( V_67 -> V_95 ) {
V_67 -> V_136 %= V_67 -> V_84 ;
if ( V_67 -> V_136 % V_67 -> V_96 == 0 )
F_58 ( & V_67 -> V_18 ) ;
} else if ( V_67 -> V_136 == V_67 -> V_84 ) {
V_7 -> V_108 = NULL ;
F_59 ( & V_67 -> V_18 ) ;
F_36 ( V_7 ) ;
break;
}
}
V_147:
F_60 ( & V_7 -> V_11 . V_115 ) ;
return V_148 ;
}
static struct V_9 * F_61 ( struct V_149 * V_150 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_153 ;
struct V_9 * V_68 ;
if ( V_150 -> V_154 != 3 )
return NULL ;
F_62 (chan, &mdma->dma_dev.channels, device_node) {
struct V_6 * V_7 = F_7 ( V_68 ) ;
if ( ! ( V_150 -> args [ 1 ] & F_63 ( V_7 -> V_8 ) ) )
continue;
if ( F_64 ( V_68 ) ) {
V_7 -> V_155 = V_150 -> args [ 0 ] ;
V_7 -> V_41 = V_150 -> args [ 2 ] ;
return V_68 ;
}
}
return NULL ;
}
static void F_65 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_66 ( V_2 -> V_156 ,
F_67 ( V_7 -> V_8 ) ,
V_157 <<
F_68 ( V_7 -> V_8 ) ,
V_7 -> V_155 <<
F_68 ( V_7 -> V_8 ) ) ;
}
static void F_69 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_66 ( V_2 -> V_156 ,
F_67 ( V_7 -> V_8 ) ,
V_157 <<
F_68 ( V_7 -> V_8 ) ,
0 ) ;
}
static int F_70 ( struct V_158 * V_159 )
{
struct V_1 * V_2 ;
struct V_160 * V_161 ;
unsigned int V_105 ;
T_1 V_5 ;
int V_120 ;
V_2 = F_71 ( & V_159 -> V_21 , sizeof( * V_2 ) , V_162 ) ;
if ( ! V_2 )
return - V_163 ;
F_72 ( V_159 , V_2 ) ;
V_2 -> V_109 = F_73 ( & V_159 -> V_21 ) ;
V_161 = F_74 ( V_159 , V_164 , 0 ) ;
V_2 -> V_4 = F_75 ( & V_159 -> V_21 , V_161 ) ;
if ( F_76 ( V_2 -> V_4 ) )
return F_77 ( V_2 -> V_4 ) ;
V_2 -> V_156 = F_78 ( V_159 -> V_21 . V_165 ,
L_4 ) ;
if ( F_76 ( V_2 -> V_156 ) )
return F_77 ( V_2 -> V_156 ) ;
V_2 -> V_166 = F_79 ( & V_159 -> V_21 , L_5 ) ;
if ( F_76 ( V_2 -> V_166 ) )
return F_77 ( V_2 -> V_166 ) ;
V_120 = F_80 ( V_2 -> V_166 ) ;
if ( V_120 )
return V_120 ;
F_81 ( V_2 -> V_20 . V_167 ) ;
F_82 ( V_168 , V_2 -> V_20 . V_167 ) ;
F_82 ( V_169 , V_2 -> V_20 . V_167 ) ;
F_82 ( V_170 , V_2 -> V_20 . V_167 ) ;
F_82 ( V_171 , V_2 -> V_20 . V_167 ) ;
V_5 = F_1 ( V_2 , V_172 ) ;
V_2 -> V_173 = ( V_5 >> V_174 ) &
V_175 ;
V_2 -> V_176 =
1 << ( ( V_5 >> V_177 ) &
V_178 ) ;
V_2 -> V_54 =
( 1 << ( ( V_5 >> V_179 ) &
V_180 ) ) / 8 ;
V_2 -> V_82 = V_137 + 1 - V_2 -> V_54 ;
F_83 ( V_159 -> V_21 . V_165 , L_6 ,
& V_2 -> V_173 ) ;
V_120 = F_83 ( V_159 -> V_21 . V_165 ,
L_7 ,
& V_2 -> V_55 ) ;
if ( V_120 )
goto V_181;
V_2 -> V_20 . V_21 = & V_159 -> V_21 ;
V_2 -> V_20 . V_182 = F_32 ;
V_2 -> V_20 . V_183 = F_29 ;
V_2 -> V_20 . V_184 = F_23 ;
V_2 -> V_20 . V_185 = F_54 ;
V_2 -> V_20 . V_186 = F_44 ;
V_2 -> V_20 . V_187 = F_40 ;
V_2 -> V_20 . V_188 = F_49 ;
V_2 -> V_20 . V_189 = F_53 ;
V_2 -> V_20 . V_190 = F_63 ( V_62 ) | F_63 ( V_56 ) ;
V_2 -> V_20 . V_191 = V_192 ;
for ( V_105 = 1 ; V_105 <= V_2 -> V_54 ; V_105 <<= 1 ) {
V_2 -> V_20 . V_193 |= F_63 ( V_105 ) ;
V_2 -> V_20 . V_194 |= F_63 ( V_105 ) ;
}
F_84 ( & V_2 -> V_20 . V_195 ) ;
for ( V_105 = 0 ; V_105 < V_2 -> V_173 ; V_105 ++ ) {
struct V_6 * V_7 = & V_2 -> V_195 [ V_105 ] ;
V_7 -> V_2 = V_2 ;
V_7 -> V_8 = V_105 ;
V_7 -> V_144 = F_85 ( V_159 , V_105 ) ;
if ( V_7 -> V_144 < 0 ) {
V_120 = V_7 -> V_144 ;
goto V_181;
}
V_120 = F_86 ( & V_159 -> V_21 , V_7 -> V_144 , F_55 ,
V_196 ,
F_87 ( & V_159 -> V_21 ) , V_7 ) ;
if ( V_120 < 0 )
goto V_181;
V_7 -> V_11 . V_197 = F_21 ;
F_88 ( & V_7 -> V_11 , & V_2 -> V_20 ) ;
}
V_2 -> V_75 = F_89 ( F_87 ( & V_159 -> V_21 ) , & V_159 -> V_21 ,
sizeof( struct V_23 ) ,
4 , 0 ) ;
if ( ! V_2 -> V_75 ) {
V_120 = - V_163 ;
goto V_181;
}
V_120 = F_90 ( & V_2 -> V_20 ) ;
if ( V_120 )
goto V_181;
V_120 = F_91 ( V_159 -> V_21 . V_165 , F_61 , V_2 ) ;
if ( V_120 )
goto V_198;
F_92 ( & V_159 -> V_21 , L_8 ,
V_2 -> V_173 , V_2 -> V_176 ) ;
return 0 ;
V_198:
F_93 ( & V_2 -> V_20 ) ;
V_181:
F_94 ( V_2 -> V_166 ) ;
return V_120 ;
}
static int F_95 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = F_96 ( V_159 ) ;
struct V_6 * V_7 , * V_70 ;
F_97 ( V_159 -> V_21 . V_165 ) ;
F_93 ( & V_2 -> V_20 ) ;
F_98 (mchan, next, &mdma->dma_dev.channels,
vc.chan.device_node) {
F_38 ( & V_7 -> V_11 . V_68 . V_199 ) ;
F_99 ( & V_159 -> V_21 , V_7 -> V_144 , V_7 ) ;
F_100 ( & V_7 -> V_11 . V_200 ) ;
}
F_94 ( V_2 -> V_166 ) ;
return 0 ;
}
