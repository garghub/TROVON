static void F_1 ( unsigned long V_1 )
{
int V_2 ;
int V_3 = 0 ;
struct V_4 * V_5 = (struct V_4 * ) V_1 ;
struct V_6 * V_7 =
(struct V_6 * ) V_5 -> V_8 ;
for ( V_2 = 0 ; V_2 < V_9 ; V_2 ++ ) {
if ( ! ( V_5 -> V_10 . V_11 & ( 1UL << V_2 ) ) )
continue;
V_3 |= F_2 ( V_5 , V_5 -> V_12 [ V_2 ] ,
V_13 ) ;
}
if ( V_3 )
F_3 ( & V_7 -> V_14 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
struct V_6 * V_7 =
(struct V_6 * ) V_5 -> V_8 ;
int V_15 = 100 , V_16 = 0 , V_17 = 0 ;
int V_18 ;
do {
V_17 = 0 ;
for ( V_18 = 0 ; V_18 < V_9 ; V_18 ++ ) {
if ( ! ( V_5 -> V_10 . V_11 & ( 1UL << V_18 ) ) )
continue;
V_16 += F_5 ( V_5 ,
V_5 -> V_12 [ V_18 ] ) ;
}
if ( V_16 > 0 ) {
V_17 += V_16 ;
F_3 ( & V_7 -> V_14 ) ;
}
V_16 = 0 ;
F_6 ( 1 ) ;
} while ( V_15 -- && V_17 );
return V_16 ;
}
void F_7 ( void * V_19 , unsigned int V_20 ,
unsigned int V_21 )
{
struct V_22 * V_22 = V_19 ;
F_8 ( V_22 , V_20 , V_21 ) ;
}
void F_9 ( void * V_23 , int V_24 ,
unsigned int * V_20 ,
unsigned int * V_21 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 = NULL ;
struct V_29 * V_30 ;
switch ( V_24 ) {
case V_31 :
case V_32 :
V_26 = V_23 ;
V_28 = V_26 -> V_28 ;
break;
case V_33 :
case V_34 :
V_30 = V_23 ;
V_28 = V_30 -> V_35 ;
break;
default:
return;
}
( * V_20 ) ++ ;
* V_21 += V_28 -> V_36 ;
}
void F_10 ( void * V_23 , int V_24 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_22 * V_19 ;
switch ( V_24 ) {
case V_31 :
case V_32 :
V_26 = V_23 ;
V_28 = V_26 -> V_28 ;
break;
case V_33 :
case V_34 :
V_30 = V_23 ;
V_28 = V_30 -> V_35 ;
break;
default:
return;
}
V_19 = F_11 ( V_28 -> V_37 , F_12 ( V_28 ) ) ;
F_13 ( V_19 , V_28 -> V_36 ) ;
}
int F_14 ( T_1 V_38 )
{
return ( V_39 >> ( V_38 ) ) & 0x1 ;
}
static void F_15 ( struct V_4 * V_5 )
{
if ( ( V_5 -> V_40 == V_41 ) ||
( V_5 -> V_40 == V_42 ) ) {
F_16 ( V_5 , V_43 , 0 ) ;
F_16 ( V_5 , V_44 , 0 ) ;
}
}
static int F_17 ( struct V_4 * V_5 )
{
int V_18 , V_45 = 0 ;
for ( V_18 = 0 ; V_18 < 100 ; V_18 ++ ) {
V_45 =
F_18 ( & V_5 -> V_46
[ V_47 ] . V_48 ) ;
if ( V_45 )
F_6 ( V_49 / 10 ) ;
else
break;
}
if ( V_45 )
return 1 ;
return 0 ;
}
static inline void F_19 ( struct V_4 * V_5 )
{
int V_18 ;
F_15 ( V_5 ) ;
F_6 ( 100 ) ;
if ( F_17 ( V_5 ) )
F_20 ( & V_5 -> V_50 -> V_37 , L_1 ) ;
for ( V_18 = 0 ; V_18 < V_51 ; V_18 ++ ) {
struct V_52 * V_53 ;
if ( ! ( V_5 -> V_10 . V_53 & ( 1UL << V_18 ) ) )
continue;
V_53 = V_5 -> V_54 [ V_18 ] ;
if ( F_18 ( & V_53 -> V_55 ) ) {
F_21 ( & V_53 -> V_56 ) ;
V_53 -> V_57 = 0 ;
V_53 -> V_58 = V_53 -> V_59 ;
V_53 -> V_60 . V_61 +=
F_18 ( & V_53 -> V_55 ) ;
F_22 ( V_5 , V_53 ) ;
F_23 ( & V_53 -> V_56 ) ;
}
}
F_24 ( V_5 , 1 ) ;
}
static void F_25 ( struct V_50 * V_37 )
{
int V_62 = 0x100 ;
T_1 V_63 , V_64 ;
F_26 ( L_2 , V_65 ) ;
F_27 ( V_37 , V_62 + V_66 , & V_63 ) ;
F_27 ( V_37 , V_62 + V_67 , & V_64 ) ;
if ( V_37 -> V_68 == V_69 )
V_63 &= ~ V_64 ;
else
V_63 &= V_64 ;
F_28 ( V_37 , V_62 + V_66 , V_63 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
F_30 ( & V_5 -> V_63 , V_70 ) ;
F_31 ( V_5 -> V_50 ) ;
V_5 -> V_71 . V_72 ( V_5 -> V_73 ) ;
F_19 ( V_5 ) ;
F_32 ( V_5 -> V_50 -> V_74 , V_5 ) ;
if ( V_5 -> V_75 & V_76 )
F_33 ( V_5 -> V_50 ) ;
F_34 ( & V_5 -> V_50 -> V_37 , L_3 ,
F_35 ( & V_5 -> V_63 ) ) ;
F_25 ( V_5 -> V_50 ) ;
}
static T_2 F_36 ( struct V_50 * V_1 ,
T_3 V_77 )
{
struct V_4 * V_5 = F_37 ( V_1 ) ;
if ( V_77 == V_69 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_4 ) ;
F_25 ( V_5 -> V_50 ) ;
return V_78 ;
}
F_20 ( & V_5 -> V_50 -> V_37 , L_5 ) ;
F_29 ( V_5 ) ;
return V_79 ;
}
static T_2 F_38 ( struct V_50 * V_1 )
{
return V_80 ;
}
static T_2 F_39 ( struct V_50 * V_1 )
{
return V_80 ;
}
static void F_40 ( struct V_50 * V_1 )
{
}
static int F_41 ( struct V_50 * V_1 , T_4 V_77 )
{
return 0 ;
}
static int F_42 ( struct V_50 * V_1 )
{
return 0 ;
}
static int F_43 ( void )
{
return F_44 ( & V_81 ) ;
}
static void F_45 ( void )
{
F_46 ( & V_81 ) ;
}
static inline int F_47 ( struct V_82 * V_82 , int V_83 )
{
return F_18 ( & V_82 -> V_84 ) & V_83 ;
}
static inline void F_48 ( struct V_82 * V_82 , int V_83 )
{
F_30 ( & V_82 -> V_84 , ( F_18 ( & V_82 -> V_84 ) | V_83 ) ) ;
}
static inline void F_49 ( struct V_82 * V_82 , int V_83 )
{
F_30 ( & V_82 -> V_84 , ( F_18 ( & V_82 -> V_84 ) & ~ ( V_83 ) ) ) ;
}
static inline void F_50 ( struct V_85 * V_86 )
{
if ( F_51 ( V_86 ) ) {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_86 -> V_87 ; V_18 ++ )
F_52 ( V_86 , V_18 ) ;
} else {
F_53 ( V_86 ) ;
}
}
static inline void F_54 ( struct V_85 * V_86 )
{
if ( F_51 ( V_86 ) ) {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_86 -> V_87 ; V_18 ++ )
F_55 ( V_86 , V_18 ) ;
} else {
F_56 ( V_86 ) ;
}
}
static inline void F_57 ( struct V_85 * V_86 )
{
if ( F_51 ( V_86 ) ) {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_86 -> V_87 ; V_18 ++ )
F_58 ( V_86 , V_18 ) ;
} else {
F_59 ( V_86 ) ;
}
}
static void F_60 ( struct V_85 * V_86 )
{
F_50 ( V_86 ) ;
}
static void F_61 ( struct V_85 * V_86 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
if ( V_82 -> V_88 . V_89 . V_90 . V_63 ) {
F_54 ( V_86 ) ;
return;
}
}
static inline void F_63 ( struct V_85 * V_86 , int V_91 )
{
if ( F_51 ( V_86 ) )
F_58 ( V_86 , V_91 ) ;
else
F_59 ( V_86 ) ;
}
static inline void F_64 ( struct V_85 * V_86 , int V_91 )
{
if ( F_51 ( V_86 ) )
F_52 ( V_86 , V_91 ) ;
else
F_53 ( V_86 ) ;
}
static inline int F_65 ( struct V_82 * V_82 )
{
int V_92 = 0 ;
if ( F_51 ( V_82 -> V_86 ) ) {
int V_93 = V_82 -> V_86 -> V_87 ;
int V_91 , V_53 = 0 ;
for ( V_91 = 0 ; V_91 < V_93 ; V_91 ++ ) {
V_53 = V_82 -> V_88 . V_94 [ V_91 & ( V_82 -> V_88 . V_95 - 1 ) ] ;
if ( F_66 ( V_82 -> V_96 , V_53 ) )
continue;
F_63 ( V_82 -> V_86 , V_91 ) ;
V_92 ++ ;
}
} else {
if ( F_66 ( V_82 -> V_96 , V_82 -> V_19 ) )
return 0 ;
F_63 ( V_82 -> V_86 , V_82 -> V_19 ) ;
V_92 = 1 ;
}
return V_92 ;
}
static inline struct V_97 * F_67 ( struct V_97 * V_98 )
{
struct V_97 * V_99 ;
if ( ( V_98 -> V_100 == V_98 ) && ( V_98 -> V_101 == V_98 ) )
V_99 = NULL ;
else
V_99 = V_98 -> V_101 ;
if ( V_99 )
F_68 ( V_99 ) ;
return V_99 ;
}
static void F_69 ( struct V_82 * V_82 )
{
struct V_102 * V_103 ;
do {
V_103 = (struct V_102 * )
F_67 ( & V_82 -> V_104 ) ;
if ( V_103 ) {
if ( V_103 -> V_105 )
F_70 ( ( void * ) ( ( unsigned long ) V_103 -> V_105 -
V_103 -> V_106 ) ) ;
F_70 ( V_103 ) ;
}
} while ( V_103 );
}
static int F_71 ( struct V_82 * V_82 )
{
int V_18 ;
struct V_102 * V_103 ;
F_72 ( & V_82 -> V_104 ) ;
for ( V_18 = 0 ; V_18 < V_82 -> V_107 ; V_18 ++ ) {
V_103 = F_73 ( sizeof( * V_103 ) , V_108 ) ;
if ( ! V_103 )
break;
V_103 -> V_109 =
( ( F_74 ( V_110 ) >> 2 ) * V_111 ) ;
V_103 -> V_105 = F_75 ( V_103 -> V_109 + 8 , V_108 ) ;
if ( ! V_103 -> V_105 ) {
F_70 ( V_103 ) ;
break;
}
if ( ( ( unsigned long ) V_103 -> V_105 ) & 7 ) {
V_103 -> V_106 = 8 - ( ( ( unsigned long ) V_103 -> V_105 ) & 7 ) ;
V_103 -> V_105 = (struct V_112 * )
( ( unsigned long ) V_103 -> V_105 + V_103 -> V_106 ) ;
}
F_76 ( & V_103 -> V_113 , & V_82 -> V_104 ) ;
}
if ( V_18 == V_82 -> V_107 )
return 0 ;
F_69 ( V_82 ) ;
return 1 ;
}
static void F_77 ( struct V_85 * V_86 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
if ( F_18 ( & V_82 -> V_84 ) & V_114 ) {
struct V_115 * V_88 = & V_82 -> V_88 ;
if ( V_88 -> V_89 . V_90 . V_63 ) {
F_78 ( V_82 , V_89 , V_82 -> V_86 , L_6 ,
V_88 -> V_89 . V_90 . V_116 ,
( V_88 -> V_89 . V_90 . V_117 ) ? L_7 : L_8 ) ;
} else {
F_78 ( V_82 , V_89 , V_82 -> V_86 , L_9 ) ;
}
}
}
static inline void F_79 ( struct V_85 * V_86 ,
union V_118 * V_119 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
if ( ( V_82 -> V_120 ) && ( V_82 -> V_88 . V_89 . V_121 != V_119 -> V_121 ) ) {
V_82 -> V_88 . V_89 . V_121 = V_119 -> V_121 ;
F_77 ( V_86 ) ;
if ( V_82 -> V_88 . V_89 . V_90 . V_63 ) {
F_80 ( V_86 ) ;
F_57 ( V_86 ) ;
} else {
F_81 ( V_86 ) ;
F_60 ( V_86 ) ;
}
}
}
static
void F_82 ( struct V_4 * V_5 )
{
struct V_6 * V_7 =
(struct V_6 * ) V_5 -> V_8 ;
V_121 V_122 ;
struct V_123 * V_12 ;
if ( V_5 -> V_124 & V_125 ) {
for ( V_122 = 0 ; V_122 < V_9 ; V_122 ++ ) {
if ( ! ( V_5 -> V_126 & ( 1 << V_122 ) ) )
continue;
V_12 = V_5 -> V_12 [ V_122 ] ;
if ( V_12 -> V_127 . V_128 ) {
V_12 -> V_127 . V_129 ( V_12 ) ;
V_7 -> V_130 |= ( 1 << V_122 ) ;
} else {
F_3 ( & V_7 -> V_14 ) ;
}
}
}
}
static int F_83 ( struct V_4 * V_5 )
{
int V_131 , V_132 ;
V_132 = F_84 ( V_5 -> V_50 ) ;
if ( V_132 )
F_85 ( & V_5 -> V_50 -> V_37 , L_10 ,
V_132 ) ;
else
V_5 -> V_75 |= V_76 ;
V_131 = F_86 ( V_5 -> V_50 -> V_74 , V_133 ,
V_134 , L_11 , V_5 ) ;
if ( V_131 ) {
if ( V_5 -> V_75 & V_76 )
F_33 ( V_5 -> V_50 ) ;
F_20 ( & V_5 -> V_50 -> V_37 , L_12 ,
V_131 ) ;
return 1 ;
}
return 0 ;
}
static int F_87 ( struct V_50 * V_1 , const struct V_135 * V_136 )
{
struct V_4 * V_96 = NULL ;
struct V_137 * V_138 ;
V_96 = F_88 ( V_1 -> V_139 ,
sizeof( struct V_6 ) ) ;
if ( ! V_96 ) {
F_20 ( & V_1 -> V_37 , L_13 ) ;
return - V_140 ;
}
F_89 ( & V_1 -> V_37 , L_14 ,
( T_1 ) V_1 -> V_141 , ( T_1 ) V_1 -> V_139 ) ;
F_90 ( V_1 , V_96 ) ;
V_96 -> V_50 = ( void * ) V_1 ;
V_138 = & V_137 [ V_96 -> V_142 ] ;
F_91 ( & V_138 -> V_143 ) ;
F_91 ( & V_138 -> V_144 ) ;
V_138 -> V_50 = V_1 ;
if ( V_96 -> V_142 == 0 )
F_92 ( & V_145 ) ;
if ( F_93 ( V_96 ) ) {
F_94 ( V_1 ) ;
return - V_140 ;
}
F_34 ( & V_96 -> V_50 -> V_37 , L_15 ) ;
return 0 ;
}
static void F_95 ( struct V_4 * V_5 )
{
int V_18 ;
struct V_6 * V_7 =
(struct V_6 * ) V_5 -> V_8 ;
struct V_137 * V_138 ;
switch ( F_18 ( & V_5 -> V_63 ) ) {
case V_146 :
case V_147 :
F_30 ( & V_5 -> V_63 , V_70 ) ;
V_5 -> V_148 = V_149 ;
F_34 ( & V_5 -> V_50 -> V_37 , L_3 ,
F_35 ( & V_5 -> V_63 ) ) ;
F_6 ( V_49 / 10 ) ;
case V_150 :
case V_151 :
F_96 ( V_5 ) ;
case V_152 :
if ( F_17 ( V_5 ) )
F_20 ( & V_5 -> V_50 -> V_37 , L_1 ) ;
if ( F_97 ( V_5 ) )
F_20 ( & V_5 -> V_50 -> V_37 , L_16 ) ;
V_5 -> V_71 . V_153 ( V_5 ) ;
if ( F_4 ( V_5 ) )
F_20 ( & V_5 -> V_50 -> V_37 , L_17 ) ;
V_5 -> V_71 . V_72 ( V_5 -> V_73 ) ;
F_32 ( V_5 -> V_50 -> V_74 , V_5 ) ;
if ( V_5 -> V_75 & V_76 )
F_33 ( V_5 -> V_50 ) ;
V_5 -> V_71 . V_154 ( V_5 ) ;
F_31 ( V_5 -> V_50 ) ;
case V_70 :
case V_155 :
F_98 ( 100 ) ;
for ( V_18 = 0 ; V_18 < V_9 ; V_18 ++ ) {
if ( ! ( V_5 -> V_10 . V_11 & ( 1UL << V_18 ) ) )
continue;
F_99 ( V_5 , V_18 ) ;
}
for ( V_18 = 0 ; V_18 < V_156 ; V_18 ++ ) {
V_138 = & V_137 [ V_18 ] ;
if ( V_138 -> V_50 ) {
V_137 [ V_5 -> V_142 ] . V_157 = 0 ;
F_92 ( & V_137 [ V_5 -> V_142 ] . V_143 ) ;
V_137 [ V_5 -> V_142 ] . V_158 = 0 ;
F_92 ( & V_137 [ V_5 -> V_142 ] . V_144 ) ;
}
}
case V_159 :
F_100 ( V_5 ) ;
case V_160 :
F_101 ( V_5 ) ;
case V_161 :
for ( V_18 = 0 ; V_18 < V_51 ; V_18 ++ ) {
if ( ! ( V_5 -> V_10 . V_53 & ( 1UL << V_18 ) ) )
continue;
F_102 ( V_5 , V_18 ) ;
}
case V_162 :
F_103 ( V_5 ) ;
F_104 ( & V_5 -> V_163 . V_164 ) ;
case V_165 :
F_105 ( V_5 , 0 ) ;
F_105 ( V_5 , 1 ) ;
case V_166 :
break;
}
F_106 ( & V_7 -> V_14 ) ;
}
static void F_107 ( struct V_82 * V_82 , int V_167 )
{
struct V_168 V_169 ;
struct V_170 V_171 ;
memset ( & V_169 , 0 , sizeof( struct V_168 ) ) ;
V_169 . V_172 . V_90 . V_173 = V_174 ;
V_169 . V_172 . V_90 . V_175 = V_82 -> V_88 . V_176 ;
V_169 . V_172 . V_90 . V_177 = V_167 ;
V_169 . V_178 = ( V_121 ) V_82 -> V_86 ;
V_171 . V_179 = V_180 ;
if ( F_108 ( V_82 -> V_96 , & V_169 , V_171 ) < 0 )
F_78 ( V_82 , V_181 , V_82 -> V_86 , L_18 ) ;
}
static void F_109 ( struct V_4 * V_5 , int V_176 )
{
struct V_85 * V_86 = V_5 -> V_182 [ V_176 ] . V_86 ;
struct V_82 * V_82 ;
if ( ! V_86 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_19 ,
V_65 , V_176 ) ;
return;
}
V_82 = F_62 ( V_86 ) ;
F_34 ( & V_5 -> V_50 -> V_37 , L_20 ) ;
F_107 ( V_82 , 0 ) ;
if ( F_18 ( & V_82 -> V_84 ) & V_183 )
F_50 ( V_86 ) ;
if ( F_18 ( & V_82 -> V_84 ) & V_114 )
F_110 ( V_86 ) ;
F_69 ( V_82 ) ;
F_111 ( V_86 ) ;
V_5 -> V_182 [ V_176 ] . V_86 = NULL ;
}
static int F_112 ( struct V_4 * V_5 )
{
int V_18 , V_184 ;
struct V_82 * V_82 ;
F_34 ( & V_5 -> V_50 -> V_37 , L_21 ) ;
if ( ! V_5 -> V_185 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_22 ) ;
return 1 ;
}
for ( V_18 = 0 ; V_18 < V_5 -> V_185 ; V_18 ++ ) {
V_82 = F_62 ( V_5 -> V_182 [ V_18 ] . V_86 ) ;
for ( V_184 = 0 ; V_184 < V_82 -> V_88 . V_186 ; V_184 ++ )
F_113 ( V_5 , V_82 -> V_88 . V_187 [ V_184 ] ) ;
}
for ( V_18 = 0 ; V_18 < V_5 -> V_185 ; V_18 ++ )
F_109 ( V_5 , V_18 ) ;
F_34 ( & V_5 -> V_50 -> V_37 , L_23 ) ;
return 0 ;
}
static void F_94 ( struct V_50 * V_1 )
{
struct V_4 * V_96 = F_37 ( V_1 ) ;
F_34 ( & V_96 -> V_50 -> V_37 , L_24 ) ;
if ( V_96 -> V_148 && ( V_96 -> V_148 == V_188 ) )
F_112 ( V_96 ) ;
F_95 ( V_96 ) ;
F_89 ( & V_96 -> V_50 -> V_37 , L_25 ) ;
F_114 ( V_96 ) ;
}
static int F_115 ( struct V_4 * V_5 )
{
T_1 V_189 , V_190 ;
int V_191 = 1 ;
F_27 ( V_5 -> V_50 , 0 , & V_189 ) ;
F_27 ( V_5 -> V_50 , 8 , & V_190 ) ;
V_5 -> V_190 = V_190 & 0xff ;
switch ( V_189 ) {
case V_192 :
V_5 -> V_40 = V_42 ;
V_191 = F_116 ( V_5 ) ;
break;
case V_193 :
V_5 -> V_40 = V_41 ;
V_191 = F_117 ( V_5 ) ;
break;
default:
F_20 ( & V_5 -> V_50 -> V_37 , L_26 ,
V_189 ) ;
}
if ( ! V_191 )
F_89 ( & V_5 -> V_50 -> V_37 , L_27 ,
F_118 ( V_5 ) ,
F_119 ( V_5 ) ,
F_120 ( V_5 ) -> V_194 ) ;
return V_191 ;
}
static int F_121 ( struct V_4 * V_5 )
{
if ( F_122 ( V_5 -> V_50 ) ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_28 ) ;
return 1 ;
}
if ( F_123 ( & V_5 -> V_50 -> V_37 , F_124 ( 64 ) ) ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_29 ) ;
return 1 ;
}
F_125 ( V_5 -> V_50 ) ;
return 0 ;
}
static inline int F_126 ( struct V_82 * V_82 , struct V_27 * V_28 )
{
int V_91 = 0 , V_53 = 0 ;
if ( F_51 ( V_82 -> V_86 ) ) {
V_91 = V_28 -> V_195 ;
V_53 = V_82 -> V_88 . V_94 [ ( V_91 & ( V_82 -> V_88 . V_95 - 1 ) ) ] ;
} else {
V_53 = V_82 -> V_19 ;
}
if ( F_66 ( V_82 -> V_96 , V_53 ) )
return 0 ;
F_63 ( V_82 -> V_86 , V_91 ) ;
return 1 ;
}
static void F_127 ( void * V_23 )
{
struct V_27 * V_28 ;
struct V_25 * V_26 ;
struct V_82 * V_82 ;
V_26 = (struct V_25 * ) V_23 ;
V_28 = V_26 -> V_28 ;
V_82 = V_26 -> V_82 ;
F_128 ( & V_82 -> V_96 -> V_50 -> V_37 , V_26 -> V_196 , V_28 -> V_36 ,
V_197 ) ;
F_126 ( V_82 , V_28 ) ;
F_129 ( (struct V_27 * ) V_28 ) ;
}
static void F_130 ( void * V_23 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_82 * V_82 ;
struct V_102 * V_103 ;
int V_18 , V_198 ;
V_26 = (struct V_25 * ) V_23 ;
V_28 = V_26 -> V_28 ;
V_82 = V_26 -> V_82 ;
V_103 = V_26 -> V_103 ;
V_198 = F_131 ( V_28 ) -> V_199 ;
F_128 ( & V_82 -> V_96 -> V_50 -> V_37 ,
V_103 -> V_105 [ 0 ] . V_200 [ 0 ] , ( V_28 -> V_36 - V_28 -> V_201 ) ,
V_197 ) ;
V_18 = 1 ;
while ( V_198 -- ) {
struct V_202 * V_203 = & F_131 ( V_28 ) -> V_198 [ V_18 - 1 ] ;
F_132 ( ( V_82 -> V_96 ) -> V_50 ,
V_103 -> V_105 [ ( V_18 >> 2 ) ] . V_200 [ ( V_18 & 3 ) ] ,
V_203 -> V_204 , V_197 ) ;
V_18 ++ ;
}
F_128 ( & V_82 -> V_96 -> V_50 -> V_37 ,
V_26 -> V_196 , V_103 -> V_109 ,
V_197 ) ;
F_133 ( & V_82 -> V_56 ) ;
F_76 ( & V_103 -> V_113 , & V_82 -> V_104 ) ;
F_134 ( & V_82 -> V_56 ) ;
F_126 ( V_82 , V_28 ) ;
F_129 ( (struct V_27 * ) V_28 ) ;
}
static void F_135 ( void * V_23 )
{
struct V_29 * V_30 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_82 * V_82 ;
struct V_102 * V_103 ;
int V_18 , V_198 ;
V_30 = (struct V_29 * ) V_23 ;
V_28 = (struct V_27 * ) V_30 -> V_35 ;
V_26 = (struct V_25 * ) & V_28 -> V_205 ;
V_82 = V_26 -> V_82 ;
V_103 = V_26 -> V_103 ;
V_198 = F_131 ( V_28 ) -> V_199 ;
F_128 ( & V_82 -> V_96 -> V_50 -> V_37 ,
V_103 -> V_105 [ 0 ] . V_200 [ 0 ] , ( V_28 -> V_36 - V_28 -> V_201 ) ,
V_197 ) ;
V_18 = 1 ;
while ( V_198 -- ) {
struct V_202 * V_203 = & F_131 ( V_28 ) -> V_198 [ V_18 - 1 ] ;
F_132 ( ( V_82 -> V_96 ) -> V_50 ,
V_103 -> V_105 [ ( V_18 >> 2 ) ] . V_200 [ ( V_18 & 3 ) ] ,
V_203 -> V_204 , V_197 ) ;
V_18 ++ ;
}
F_128 ( & V_82 -> V_96 -> V_50 -> V_37 ,
V_26 -> V_196 , V_103 -> V_109 ,
V_197 ) ;
F_133 ( & V_82 -> V_56 ) ;
F_76 ( & V_103 -> V_113 , & V_82 -> V_104 ) ;
F_134 ( & V_82 -> V_56 ) ;
F_126 ( V_82 , V_28 ) ;
}
static int F_136 ( struct V_206 * V_207 , T_5 V_208 )
{
struct V_82 * V_82 = F_137 ( V_207 , struct V_82 , V_209 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_82 -> V_96 ;
V_121 V_210 , V_211 ;
unsigned long V_75 ;
bool V_212 = false ;
if ( V_208 < 0 ) {
V_212 = true ;
V_208 = - V_208 ;
}
V_211 = ( V_121 ) V_208 << 32 ;
F_138 ( V_211 , V_5 -> V_213 ) ;
F_139 ( & V_82 -> V_214 , V_75 ) ;
V_210 = F_140 ( V_5 , V_215 ) ;
if ( V_212 )
V_210 -= V_211 ;
else
V_210 += V_211 ;
F_141 ( V_5 , V_210 , V_215 ) ;
F_142 ( & V_82 -> V_214 , V_75 ) ;
return 0 ;
}
static int F_143 ( struct V_206 * V_207 , T_6 V_211 )
{
unsigned long V_75 ;
struct V_82 * V_82 = F_137 ( V_207 , struct V_82 , V_209 ) ;
F_139 ( & V_82 -> V_214 , V_75 ) ;
V_82 -> V_216 += V_211 ;
F_142 ( & V_82 -> V_214 , V_75 ) ;
return 0 ;
}
static int F_144 ( struct V_206 * V_207 ,
struct V_217 * V_218 )
{
V_121 V_219 ;
unsigned long V_75 ;
struct V_82 * V_82 = F_137 ( V_207 , struct V_82 , V_209 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_82 -> V_96 ;
F_139 ( & V_82 -> V_214 , V_75 ) ;
V_219 = F_140 ( V_5 , V_220 ) ;
V_219 += V_82 -> V_216 ;
F_142 ( & V_82 -> V_214 , V_75 ) ;
* V_218 = F_145 ( V_219 ) ;
return 0 ;
}
static int F_146 ( struct V_206 * V_207 ,
const struct V_217 * V_218 )
{
V_121 V_219 ;
unsigned long V_75 ;
struct V_82 * V_82 = F_137 ( V_207 , struct V_82 , V_209 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_82 -> V_96 ;
V_219 = F_147 ( V_218 ) ;
F_139 ( & V_82 -> V_214 , V_75 ) ;
F_141 ( V_5 , V_219 , V_220 ) ;
V_82 -> V_216 = 0 ;
F_142 ( & V_82 -> V_214 , V_75 ) ;
return 0 ;
}
static int F_148 ( struct V_206 * V_207 ,
struct V_221 * V_222 , int V_223 )
{
return - V_224 ;
}
static void F_149 ( struct V_85 * V_86 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_82 -> V_96 ;
F_150 ( & V_82 -> V_214 ) ;
snprintf ( V_82 -> V_209 . V_225 , 16 , L_30 , V_86 -> V_225 ) ;
V_82 -> V_209 . V_226 = V_227 ;
V_82 -> V_209 . V_228 = 250000000 ;
V_82 -> V_209 . V_229 = 0 ;
V_82 -> V_209 . V_230 = 0 ;
V_82 -> V_209 . V_231 = 0 ;
V_82 -> V_209 . V_232 = 0 ;
V_82 -> V_209 . V_233 = F_136 ;
V_82 -> V_209 . V_234 = F_143 ;
V_82 -> V_209 . V_235 = F_144 ;
V_82 -> V_209 . V_236 = F_146 ;
V_82 -> V_209 . V_237 = F_148 ;
V_82 -> V_216 = 0 ;
V_82 -> V_238 = F_151 ( & V_82 -> V_209 ,
& V_5 -> V_50 -> V_37 ) ;
if ( F_152 ( V_82 -> V_238 ) )
V_82 -> V_238 = NULL ;
}
static void F_153 ( struct V_4 * V_5 )
{
V_121 V_239 , V_240 ;
V_239 = ( V_121 ) V_241 << 32 ;
F_138 ( V_239 , V_5 -> V_213 ) ;
F_141 ( V_5 , V_239 , V_215 ) ;
V_240 = F_140 ( V_5 , V_242 ) ;
F_141 ( V_5 , V_240 | 0x01 , V_242 ) ;
}
static int F_154 ( struct V_4 * V_5 )
{
int V_191 = 0 ;
const struct V_243 * V_244 ;
char V_245 [ V_246 ] ;
char * V_247 ;
if ( strncmp ( V_248 , V_249 ,
sizeof( V_249 ) ) == 0 ) {
F_89 ( & V_5 -> V_50 -> V_37 , L_31 ) ;
return V_191 ;
}
if ( V_248 [ 0 ] == '\0' )
V_247 = V_250 ;
else
V_247 = V_248 ;
sprintf ( V_245 , L_32 , V_251 , V_252 ,
F_120 ( V_5 ) -> V_194 , V_247 ,
V_253 ) ;
V_191 = F_155 ( & V_244 , V_245 , & V_5 -> V_50 -> V_37 ) ;
if ( V_191 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_33 ,
V_245 ) ;
return V_191 ;
}
V_191 = F_156 ( V_5 , V_244 -> V_254 , V_244 -> V_204 ) ;
F_157 ( V_244 ) ;
return V_191 ;
}
static int F_158 ( struct V_4 * V_5 , int V_2 , int V_255 ,
int V_256 , void * V_257 )
{
int V_92 = 0 ;
F_34 ( & V_5 -> V_50 -> V_37 , L_34 , V_2 ) ;
V_92 = F_159 ( V_5 , V_2 , V_255 , V_256 , V_257 ) ;
if ( V_92 < 0 )
return V_92 ;
if ( V_92 == 1 ) {
F_34 ( & V_5 -> V_50 -> V_37 , L_35 , V_2 ) ;
return 0 ;
}
F_160 ( V_5 , V_2 , 1 ) ;
F_161 ( V_5 -> V_12 [ V_2 ] -> V_258 ,
V_5 -> V_12 [ V_2 ] -> V_259 ) ;
return V_92 ;
}
static void F_162 ( struct V_4 * V_5 ,
T_1 V_63 ,
void * V_23 )
{
struct V_29 * V_30 = (struct V_29 * ) V_23 ;
struct V_260 * V_261 ;
struct V_262 * V_263 ;
V_261 = (struct V_260 * ) V_30 -> V_264 ;
V_263 = (struct V_262 * ) V_30 -> V_265 ;
V_5 = F_163 ( V_263 -> V_142 ) ;
if ( V_261 -> V_63 )
F_20 ( & V_5 -> V_50 -> V_37 , L_36 ,
F_164 ( V_261 -> V_63 ) ) ;
F_165 ( V_263 -> V_266 ) = 1 ;
F_166 () ;
F_167 ( & V_263 -> V_267 ) ;
}
static T_7 F_168 ( struct V_85 * V_37 , struct V_27 * V_28 ,
void * V_268 , T_8 V_269 )
{
int V_270 ;
struct V_82 * V_82 ;
V_82 = F_62 ( V_37 ) ;
V_270 = F_169 ( V_28 ) ?
F_170 ( V_28 ) : F_171 () ;
return ( T_7 ) ( V_270 & ( V_82 -> V_88 . V_95 - 1 ) ) ;
}
static void
F_172 ( T_1 V_142 ,
void * V_271 ,
T_1 V_36 ,
union V_272 * V_273 ,
void * V_274 )
{
struct V_275 * V_276 = V_274 ;
struct V_4 * V_5 = F_163 ( V_142 ) ;
struct V_27 * V_28 = (struct V_27 * ) V_271 ;
struct V_277 * V_278 ;
V_121 V_219 ;
struct V_85 * V_86 =
(struct V_85 * ) V_5 -> V_182 [ V_273 -> V_279 . V_89 ] . V_86 ;
struct V_123 * V_12 = F_137 ( V_274 , struct V_123 ,
V_276 ) ;
if ( V_86 ) {
int V_280 ;
struct V_82 * V_82 = F_62 ( V_86 ) ;
if ( ! F_47 ( V_82 , V_183 ) ) {
F_129 ( V_28 ) ;
V_12 -> V_60 . V_281 ++ ;
return;
}
V_28 -> V_37 = V_86 ;
if ( V_273 -> V_279 . V_282 ) {
if ( F_47 ( V_82 ,
V_283 ) ) {
memcpy ( & V_219 , ( V_28 -> V_254 ) , sizeof( V_219 ) ) ;
V_278 = F_173 ( V_28 ) ;
V_278 -> V_284 =
F_174 ( V_219 + V_82 -> V_216 ) ;
}
F_175 ( V_28 , sizeof( V_219 ) ) ;
}
V_28 -> V_285 = F_176 ( V_28 , V_28 -> V_37 ) ;
if ( ( V_86 -> V_286 & V_287 ) &&
( V_273 -> V_279 . V_288 == V_289 ) )
V_28 -> V_290 = V_291 ;
else
V_28 -> V_290 = V_292 ;
V_280 = F_177 ( V_276 , V_28 ) != V_293 ;
if ( V_280 ) {
V_12 -> V_60 . V_294 += V_36 ;
V_12 -> V_60 . V_295 ++ ;
V_86 -> V_296 = V_297 ;
} else {
V_12 -> V_60 . V_281 ++ ;
F_78 ( V_82 , V_181 , V_82 -> V_86 ,
L_37 ,
V_12 -> V_2 , V_12 -> V_60 . V_281 ) ;
}
} else {
F_129 ( V_28 ) ;
}
}
static void F_178 ( void * V_274 )
{
struct V_275 * V_276 = V_274 ;
F_179 ( V_276 ) ;
}
static void F_180 ( void * V_298 )
{
struct V_123 * V_12 = V_298 ;
int V_299 = F_171 () ;
if ( V_12 -> V_300 == V_299 ) {
F_179 ( & V_12 -> V_276 ) ;
} else {
struct V_301 * V_302 = & V_12 -> V_302 ;
V_302 -> V_303 = F_178 ;
V_302 -> V_304 = & V_12 -> V_276 ;
V_302 -> V_75 = 0 ;
F_181 ( V_12 -> V_300 , V_302 ) ;
}
}
static int F_182 ( struct V_123 * V_12 , int V_305 )
{
int V_306 ;
struct V_82 * V_82 = F_62 ( V_12 -> V_276 . V_37 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
V_306 = F_183 ( V_5 , V_12 -> V_2 ,
V_307 ,
V_305 ) ;
if ( V_306 < 0 ) {
F_78 ( V_82 , V_181 , V_82 -> V_86 ,
L_38 , V_12 -> V_2 ) ;
goto V_308;
}
if ( V_306 > V_305 )
F_20 ( & V_5 -> V_50 -> V_37 , L_39 ,
V_65 , V_306 , V_305 ) ;
return V_306 ;
V_308:
F_184 ( & V_12 -> V_276 ) ;
F_183 ( V_5 , V_12 -> V_2 , V_309 ,
0 ) ;
return 0 ;
}
static int F_185 ( struct V_275 * V_276 , int V_305 )
{
struct V_123 * V_12 ;
int V_306 ;
V_12 = F_137 ( V_276 , struct V_123 , V_276 ) ;
V_306 = F_182 ( V_12 , V_305 ) ;
if ( V_306 < V_305 ) {
F_184 ( V_276 ) ;
F_183 ( V_12 -> V_96 , V_12 -> V_2 ,
V_309 , 0 ) ;
return 0 ;
}
return V_306 ;
}
static inline int F_186 ( struct V_4 * V_310 ,
struct V_85 * V_85 )
{
static int V_311 = 1 ;
static struct V_312 V_313 ;
static int V_300 ;
static int V_314 ;
struct V_123 * V_12 ;
struct V_275 * V_276 ;
int V_91 , V_2 , V_315 = 0 ;
struct V_82 * V_82 ;
int V_316 ;
V_82 = F_62 ( V_85 ) ;
if ( V_311 ) {
V_311 = 0 ;
memset ( & V_313 , 0 , sizeof( struct V_312 ) ) ;
V_313 . V_317 = F_172 ;
V_313 . V_128 = 1 ;
V_313 . V_129 = F_180 ;
V_300 = 0 ;
V_314 = F_187 () ;
}
for ( V_91 = 0 ; V_91 < V_82 -> V_88 . V_186 ; V_91 ++ ) {
V_2 = V_82 -> V_88 . V_187 [ V_91 ] ;
V_315 = F_158 ( V_310 , V_2 ,
F_188
( F_120 ( V_310 ) ,
V_82 -> V_176 ) ,
F_189
( F_120 ( V_310 ) ,
V_82 -> V_176 ) , NULL ) ;
if ( V_315 ) {
F_20 ( & V_310 -> V_50 -> V_37 ,
L_40 ,
V_65 ) ;
return 1 ;
}
V_12 = V_310 -> V_12 [ V_2 ] ;
V_276 = & V_12 -> V_276 ;
F_190 ( V_85 , V_276 , F_185 , 64 ) ;
V_12 -> V_300 = V_300 ;
V_300 ++ ;
if ( V_300 >= V_314 )
V_300 = 0 ;
F_191 ( V_310 , V_2 , & V_313 ) ;
}
for ( V_91 = 0 ; V_91 < V_82 -> V_88 . V_95 ; V_91 ++ ) {
V_316 = F_192 ( F_120
( V_310 ) ,
V_82 -> V_176 ) ;
V_315 = F_193 ( V_310 , V_82 -> V_88 . V_94 [ V_91 ] ,
V_316 ,
F_11 ( V_85 , V_91 ) ) ;
if ( V_315 ) {
F_20 ( & V_310 -> V_50 -> V_37 ,
L_41 ,
V_65 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_194 ( struct V_318 * V_164 )
{
struct V_319 * V_320 = (struct V_319 * ) V_164 ;
struct V_82 * V_82 = (struct V_82 * ) V_320 -> V_265 ;
if ( ! F_47 ( V_82 , V_183 ) )
return;
F_65 ( V_82 ) ;
F_195 ( V_82 -> V_321 . V_322 ,
& V_82 -> V_321 . V_320 . V_164 , F_196 ( 1 ) ) ;
}
static inline void F_197 ( struct V_85 * V_86 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
V_82 -> V_321 . V_322 = F_198 ( L_42 ) ;
if ( ! V_82 -> V_321 . V_322 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_43 ) ;
return;
}
F_199 ( & V_82 -> V_321 . V_320 . V_164 ,
F_194 ) ;
V_82 -> V_321 . V_320 . V_265 = V_82 ;
F_195 ( V_82 -> V_321 . V_322 ,
& V_82 -> V_321 . V_320 . V_164 , F_196 ( 1 ) ) ;
}
static int F_200 ( struct V_85 * V_86 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
struct V_275 * V_276 , * V_323 ;
F_201 (napi, n, &netdev->napi_list, dev_list)
F_202 ( V_276 ) ;
F_149 ( V_86 ) ;
F_48 ( V_82 , V_183 ) ;
F_197 ( V_86 ) ;
F_61 ( V_86 ) ;
F_78 ( V_82 , V_324 , V_82 -> V_86 , L_44 ) ;
F_203 ( V_227 ) ;
F_107 ( V_82 , 1 ) ;
V_82 -> V_120 = 1 ;
F_89 ( & V_5 -> V_50 -> V_37 , L_45 ,
V_86 -> V_225 ) ;
return 0 ;
}
static int F_204 ( struct V_85 * V_86 )
{
struct V_275 * V_276 , * V_323 ;
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
F_78 ( V_82 , V_325 , V_82 -> V_86 , L_46 ) ;
V_82 -> V_120 = 0 ;
V_82 -> V_88 . V_89 . V_90 . V_63 = 0 ;
F_81 ( V_86 ) ;
F_107 ( V_82 , 0 ) ;
F_104 ( & V_82 -> V_321 . V_320 . V_164 ) ;
F_205 ( V_82 -> V_321 . V_322 ) ;
F_206 ( V_82 -> V_321 . V_322 ) ;
if ( V_82 -> V_238 ) {
F_207 ( V_82 -> V_238 ) ;
V_82 -> V_238 = NULL ;
}
F_49 ( V_82 , V_183 ) ;
F_208 ( V_326 , & V_82 -> V_86 -> V_77 ) ;
F_201 (napi, n, &netdev->napi_list, dev_list)
F_209 ( V_276 ) ;
F_50 ( V_86 ) ;
F_89 ( & V_5 -> V_50 -> V_37 , L_47 , V_86 -> V_225 ) ;
F_210 ( V_227 ) ;
return 0 ;
}
void F_211 ( void * V_327 )
{
struct V_168 * V_169 = (struct V_168 * ) V_327 ;
struct V_85 * V_86 = (struct V_85 * ) V_169 -> V_178 ;
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
switch ( V_169 -> V_172 . V_90 . V_173 ) {
case V_328 :
case V_329 :
break;
case V_330 :
F_78 ( V_82 , V_331 , V_82 -> V_86 , L_48 ,
F_164 ( V_169 -> V_332 [ 0 ] ) ) ;
F_89 ( & V_5 -> V_50 -> V_37 , L_49 ,
V_86 -> V_225 , F_164 ( V_169 -> V_332 [ 0 ] ) ) ;
memcpy ( V_86 -> V_333 , ( ( V_334 * ) & V_169 -> V_332 [ 0 ] ) + 2 , V_335 ) ;
break;
case V_336 :
F_78 ( V_82 , V_331 , V_82 -> V_86 , L_50 ,
V_86 -> V_337 , V_169 -> V_172 . V_90 . V_177 ) ;
F_89 ( & V_5 -> V_50 -> V_37 , L_51 ,
V_86 -> V_225 , V_86 -> V_337 ,
V_169 -> V_172 . V_90 . V_177 ) ;
V_86 -> V_337 = V_169 -> V_172 . V_90 . V_177 ;
break;
case V_338 :
F_78 ( V_82 , V_331 , V_82 -> V_86 , L_52 ) ;
break;
case V_339 :
F_89 ( & V_5 -> V_50 -> V_37 , L_53 , V_86 -> V_225 ) ;
break;
case V_340 :
F_89 ( & V_5 -> V_50 -> V_37 , L_54 ,
V_86 -> V_225 ) ;
break;
case V_341 :
F_89 ( & V_5 -> V_50 -> V_37 , L_53 , V_86 -> V_225 ) ;
break;
case V_342 :
F_89 ( & V_5 -> V_50 -> V_37 , L_54 ,
V_86 -> V_225 ) ;
break;
case V_343 :
F_89 ( & V_5 -> V_50 -> V_37 , L_55 ,
V_86 -> V_225 ) ;
break;
default:
F_20 ( & V_5 -> V_50 -> V_37 , L_56 , V_65 ,
V_169 -> V_172 . V_90 . V_173 ) ;
}
}
static inline enum V_344 F_212 ( struct V_85 * V_86 )
{
enum V_344 V_345 = V_346 ;
if ( V_86 -> V_75 & V_347 )
V_345 |= V_348 ;
if ( V_86 -> V_75 & V_349 )
V_345 |= V_350 ;
if ( V_86 -> V_75 & V_351 ) {
V_345 |= V_352 ;
if ( F_213 ( V_86 ) > V_353 )
V_345 |= V_350 ;
}
if ( V_86 -> V_75 & V_354 )
V_345 |= V_355 ;
return V_345 ;
}
static void F_214 ( struct V_85 * V_86 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
struct V_168 V_169 ;
struct V_170 V_171 ;
struct V_356 * V_357 ;
V_121 * V_358 ;
int V_191 , V_18 ;
int V_359 = F_215 ( F_213 ( V_86 ) , V_353 ) ;
memset ( & V_169 , 0 , sizeof( struct V_168 ) ) ;
V_169 . V_172 . V_121 = 0 ;
V_169 . V_172 . V_90 . V_173 = V_329 ;
V_169 . V_172 . V_90 . V_175 = V_82 -> V_88 . V_176 ;
V_169 . V_172 . V_90 . V_177 = F_212 ( V_86 ) ;
V_169 . V_172 . V_90 . V_360 = V_359 ;
V_169 . V_172 . V_90 . V_361 = V_359 ;
V_169 . V_178 = ( V_121 ) V_86 ;
V_169 . V_362 = F_211 ;
V_18 = 0 ;
V_358 = & V_169 . V_332 [ 0 ] ;
F_216 (ha, netdev) {
* V_358 = 0 ;
memcpy ( ( ( V_334 * ) V_358 ) + 2 , V_357 -> V_363 , V_335 ) ;
if ( ++ V_358 > & V_169 . V_332 [ V_359 ] )
break;
}
V_169 . V_364 = 0 ;
V_171 . V_179 = V_180 ;
V_191 = F_108 ( V_82 -> V_96 , & V_169 , V_171 ) ;
if ( V_191 < 0 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_57 ,
V_191 ) ;
}
}
static int F_217 ( struct V_85 * V_86 , void * V_365 )
{
int V_191 = 0 ;
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
struct V_366 * V_363 = (struct V_366 * ) V_365 ;
struct V_168 V_169 ;
struct V_170 V_171 ;
if ( ( ! F_218 ( V_363 -> V_367 ) ) ||
( F_47 ( V_82 , V_183 ) ) )
return - V_368 ;
memset ( & V_169 , 0 , sizeof( struct V_168 ) ) ;
V_169 . V_172 . V_121 = 0 ;
V_169 . V_172 . V_90 . V_173 = V_330 ;
V_169 . V_172 . V_90 . V_175 = V_82 -> V_88 . V_176 ;
V_169 . V_172 . V_90 . V_177 = 0 ;
V_169 . V_172 . V_90 . V_361 = 1 ;
V_169 . V_178 = ( V_121 ) V_86 ;
V_169 . V_362 = F_211 ;
V_169 . V_364 = 100 ;
V_169 . V_332 [ 0 ] = 0 ;
memcpy ( ( V_334 * ) & V_169 . V_332 [ 0 ] + 2 , V_363 -> V_367 , V_335 ) ;
V_171 . V_179 = V_369 ;
V_191 = F_108 ( V_82 -> V_96 , & V_169 , V_171 ) ;
if ( V_191 < 0 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_58 ) ;
return - V_140 ;
}
memcpy ( V_86 -> V_333 , V_363 -> V_367 , V_86 -> V_370 ) ;
memcpy ( ( ( V_334 * ) & V_82 -> V_88 . V_371 ) + 2 , V_363 -> V_367 , V_335 ) ;
return 0 ;
}
static struct V_372 * F_219 ( struct V_85 * V_86 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_372 * V_60 = & V_86 -> V_60 ;
struct V_4 * V_5 ;
V_121 V_373 = 0 , V_374 = 0 , V_375 = 0 ;
struct V_376 * V_377 ;
struct V_378 * V_379 ;
int V_18 , V_380 , V_122 ;
V_5 = V_82 -> V_96 ;
for ( V_18 = 0 ; V_18 < V_82 -> V_88 . V_95 ; V_18 ++ ) {
V_380 = V_82 -> V_88 . V_94 [ V_18 ] ;
V_379 = & V_5 -> V_54 [ V_380 ] -> V_60 ;
V_373 += V_379 -> V_381 ;
V_374 += V_379 -> V_382 ;
V_375 += V_379 -> V_383 ;
}
V_60 -> V_384 = V_373 ;
V_60 -> V_385 = V_375 ;
V_60 -> V_382 = V_374 ;
V_373 = 0 ;
V_374 = 0 ;
V_375 = 0 ;
for ( V_18 = 0 ; V_18 < V_82 -> V_88 . V_186 ; V_18 ++ ) {
V_122 = V_82 -> V_88 . V_187 [ V_18 ] ;
V_377 = & V_5 -> V_12 [ V_122 ] -> V_60 ;
V_373 += V_377 -> V_295 ;
V_374 += ( V_377 -> V_281 +
V_377 -> V_386 +
V_377 -> V_387 +
V_377 -> V_388 ) ;
V_375 += V_377 -> V_294 ;
}
V_60 -> V_389 = V_375 ;
V_60 -> V_390 = V_373 ;
V_60 -> V_281 = V_374 ;
return V_60 ;
}
static int F_220 ( struct V_85 * V_86 , int V_391 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
struct V_168 V_169 ;
struct V_170 V_171 ;
int V_392 = V_391 + V_393 ;
int V_191 = 0 ;
if ( ( V_392 < V_394 ) ||
( V_392 > V_395 ) ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_59 , V_391 ) ;
F_20 ( & V_5 -> V_50 -> V_37 , L_60 ,
( V_394 - V_393 ) ,
( V_395 - V_393 ) ) ;
return - V_396 ;
}
memset ( & V_169 , 0 , sizeof( struct V_168 ) ) ;
V_169 . V_172 . V_121 = 0 ;
V_169 . V_172 . V_90 . V_173 = V_336 ;
V_169 . V_172 . V_90 . V_175 = V_82 -> V_88 . V_176 ;
V_169 . V_172 . V_90 . V_177 = V_391 ;
V_169 . V_364 = 100 ;
V_169 . V_178 = ( V_121 ) V_86 ;
V_169 . V_362 = F_211 ;
V_171 . V_179 = V_369 ;
V_191 = F_108 ( V_82 -> V_96 , & V_169 , V_171 ) ;
if ( V_191 < 0 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_61 ) ;
return - 1 ;
}
V_82 -> V_337 = V_391 ;
return 0 ;
}
static int F_221 ( struct V_85 * V_86 , struct V_397 * V_398 , int V_173 )
{
struct V_399 V_400 ;
struct V_82 * V_82 = F_62 ( V_86 ) ;
if ( F_222 ( & V_400 , V_398 -> V_401 , sizeof( V_400 ) ) )
return - V_402 ;
if ( V_400 . V_75 )
return - V_396 ;
switch ( V_400 . V_403 ) {
case V_404 :
case V_405 :
break;
default:
return - V_406 ;
}
switch ( V_400 . V_407 ) {
case V_408 :
break;
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
V_400 . V_407 = V_409 ;
break;
default:
return - V_406 ;
}
if ( V_400 . V_407 == V_409 )
F_48 ( V_82 , V_283 ) ;
else
F_49 ( V_82 , V_283 ) ;
return F_223 ( V_398 -> V_401 , & V_400 , sizeof( V_400 ) ) ? - V_402 : 0 ;
}
static int F_224 ( struct V_85 * V_86 , struct V_397 * V_398 , int V_173 )
{
switch ( V_173 ) {
case V_423 :
return F_221 ( V_86 , V_398 , V_173 ) ;
default:
return - V_224 ;
}
}
static void F_225 ( struct V_4 * V_5 ,
T_1 V_63 ,
void * V_23 )
{
struct V_25 * V_26 ;
struct V_29 * V_30 ;
struct V_424 * V_261 ;
struct V_82 * V_82 ;
struct V_27 * V_28 = (struct V_27 * ) V_23 ;
V_26 = (struct V_25 * ) V_28 -> V_205 ;
V_82 = V_26 -> V_82 ;
V_30 = V_26 -> V_30 ;
V_5 = V_82 -> V_96 ;
V_261 = (struct V_424 * ) V_30 -> V_264 ;
if ( V_63 != V_425 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_62 ,
F_164 ( V_63 ) ) ;
V_261 -> V_426 = 0 ;
}
F_226 ( & V_261 -> V_426 , 1 ) ;
if ( F_227 ( ( F_131 ( V_28 ) -> V_427 & V_428 ) != 0 ) ) {
struct V_277 V_218 ;
V_121 V_219 = V_261 -> V_426 ;
F_78 ( V_82 , V_381 , V_82 -> V_86 ,
L_63 ,
V_28 , ( unsigned long long ) V_219 ) ;
V_218 . V_284 = F_174 ( V_219 + V_82 -> V_216 ) ;
F_228 ( V_28 , & V_218 ) ;
}
F_229 ( V_5 , V_30 ) ;
F_129 ( V_28 ) ;
}
static inline int F_230 ( struct V_4 * V_5 ,
struct V_429 * V_430 ,
struct V_25 * V_26 ,
int V_431 )
{
int V_315 ;
struct V_29 * V_30 ;
struct V_432 * V_433 ;
struct V_434 * V_435 ;
struct V_82 * V_82 ;
int V_436 ;
V_82 = V_26 -> V_82 ;
V_30 = F_231 ( V_5 , & V_430 -> V_173 ,
sizeof( struct V_424 ) ) ;
V_26 -> V_30 = V_30 ;
if ( ! V_30 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_64 ) ;
return V_437 ;
}
if ( V_430 -> V_24 == V_31 )
V_430 -> V_24 = V_34 ;
else if ( V_430 -> V_24 == V_32 )
V_430 -> V_24 = V_33 ;
V_30 -> V_438 = F_225 ;
V_30 -> V_35 = V_26 -> V_28 ;
V_30 -> V_380 = V_430 -> V_2 ;
V_433 = (struct V_432 * ) & V_30 -> V_173 . V_433 ;
V_435 = (struct V_434 * ) & V_30 -> V_173 . V_435 ;
V_436 = ! V_431 ;
V_315 = F_232 ( V_5 , V_30 -> V_380 , V_436 , & V_30 -> V_173 ,
V_30 , V_433 -> V_439 , V_430 -> V_24 ) ;
if ( V_315 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_65 ,
V_315 ) ;
F_229 ( V_5 , V_30 ) ;
} else {
F_78 ( V_82 , V_440 , V_82 -> V_86 , L_66 ) ;
}
return V_315 ;
}
static inline int F_233 ( struct V_27 * V_28 )
{
return ( V_28 -> V_285 == F_234 ( V_441 ) ) &&
( F_235 ( V_28 ) -> V_442 == 4 ) ;
}
static inline int F_236 ( struct V_27 * V_28 )
{
return V_28 -> V_285 == F_234 ( V_443 ) ;
}
static inline int F_237 ( struct V_27 * V_28 )
{
return ( F_235 ( V_28 ) -> V_444 & F_234 ( V_445 | V_446 ) ) ? 1 : 0 ;
}
static inline int F_238 ( struct V_27 * V_28 )
{
return ( V_28 -> V_285 == F_234 ( V_447 ) ) &&
( F_239 ( V_28 ) -> V_442 == 6 ) ;
}
static inline int F_240 ( struct V_27 * V_28 )
{
return ( F_239 ( V_28 ) -> V_448 != V_449 ) &&
( F_239 ( V_28 ) -> V_448 != V_450 ) ;
}
static inline int F_241 ( struct V_27 * V_28 )
{
return ( F_235 ( V_28 ) -> V_285 == V_449 ) ||
( F_235 ( V_28 ) -> V_285 == V_450 ) ;
}
static inline T_1 F_242 ( struct V_27 * V_28 )
{
T_1 V_451 ;
struct V_452 * V_452 = F_235 ( V_28 ) ;
V_451 = F_243 ( 0 , & V_452 -> V_285 , 1 ) ;
V_451 = F_243 ( V_451 , ( V_334 * ) & V_452 -> V_453 , 8 ) ;
V_451 = F_243 ( V_451 , F_244 ( V_28 ) , 4 ) ;
return V_451 ;
}
static inline T_1 F_245 ( struct V_27 * V_28 )
{
T_1 V_451 ;
struct V_454 * V_454 = F_239 ( V_28 ) ;
V_451 = F_243 ( 0 , & V_454 -> V_448 , 1 ) ;
V_451 = F_243 ( V_451 , ( V_334 * ) & V_454 -> V_453 , 32 ) ;
V_451 = F_243 ( V_451 , F_244 ( V_28 ) , 4 ) ;
return V_451 ;
}
static int F_246 ( struct V_27 * V_28 , struct V_85 * V_86 )
{
struct V_82 * V_82 ;
struct V_25 * V_26 ;
union V_455 V_456 ;
struct V_429 V_430 ;
struct V_4 * V_5 ;
struct V_378 * V_60 ;
int V_457 = 0 , V_63 = 0 ;
int V_458 = 0 , V_380 = 0 ;
int V_431 ;
T_1 V_451 = 0 ;
V_82 = F_62 ( V_86 ) ;
V_5 = V_82 -> V_96 ;
if ( F_51 ( V_86 ) ) {
V_457 = V_28 -> V_195 ;
V_458 = ( V_457 & ( V_82 -> V_88 . V_95 - 1 ) ) ;
V_380 = V_82 -> V_88 . V_94 [ V_458 ] ;
} else {
V_380 = V_82 -> V_19 ;
}
V_60 = & V_5 -> V_54 [ V_380 ] -> V_60 ;
if ( ! ( F_18 ( & V_82 -> V_84 ) & V_183 ) ||
( ! V_82 -> V_88 . V_89 . V_90 . V_63 ) ||
( V_28 -> V_36 <= 0 ) ) {
F_78 ( V_82 , V_459 , V_82 -> V_86 ,
L_67 ,
V_82 -> V_88 . V_89 . V_90 . V_63 ) ;
goto V_460;
}
V_26 = (struct V_25 * ) V_28 -> V_205 ;
V_26 -> V_82 = V_82 ;
V_26 -> V_28 = V_28 ;
V_26 -> V_30 = NULL ;
memset ( & V_430 , 0 , sizeof( struct V_429 ) ) ;
V_430 . V_23 = ( void * ) V_26 ;
V_430 . V_2 = V_380 ;
if ( F_51 ( V_86 ) ) {
if ( F_66 ( V_5 , V_430 . V_2 ) ) {
F_78 ( V_82 , V_459 , V_82 -> V_86 , L_68 ,
V_430 . V_2 ) ;
V_60 -> V_461 ++ ;
return V_462 ;
}
} else {
if ( F_66 ( V_5 , V_82 -> V_19 ) ) {
V_60 -> V_461 ++ ;
F_78 ( V_82 , V_459 , V_82 -> V_86 , L_68 ,
V_430 . V_2 ) ;
return V_462 ;
}
}
V_430 . V_463 = V_28 -> V_36 ;
V_456 . V_121 = 0 ;
V_456 . V_90 . V_176 = V_82 -> V_88 . V_176 ;
if ( V_28 -> V_290 == V_464 ) {
if ( F_233 ( V_28 ) && ! F_237 ( V_28 ) && F_241 ( V_28 ) ) {
V_451 = F_242 ( V_28 ) ;
V_456 . V_90 . V_465 = sizeof( struct V_466 ) + 1 ;
if ( F_235 ( V_28 ) -> V_467 > 5 )
V_456 . V_90 . V_468 =
V_469 ;
} else if ( F_238 ( V_28 ) ) {
V_451 = F_245 ( V_28 ) ;
V_456 . V_90 . V_465 = sizeof( struct V_466 ) + 1 ;
if ( F_240 ( V_28 ) )
V_456 . V_90 . V_468 =
V_470 ;
} else if ( F_236 ( V_28 ) ) {
if ( F_247 ( V_28 ) -> V_471
== F_234 ( V_441 ) &&
! F_237 ( V_28 ) && F_241 ( V_28 ) ) {
V_451 = F_242 ( V_28 ) ;
V_456 . V_90 . V_465 =
sizeof( struct V_472 ) + 1 ;
if ( F_235 ( V_28 ) -> V_467 > 5 )
V_456 . V_90 . V_468 =
V_469 ;
} else if ( F_247 ( V_28 ) -> V_471
== F_234 ( V_447 ) ) {
V_451 = F_245 ( V_28 ) ;
V_456 . V_90 . V_465 =
sizeof( struct V_472 ) + 1 ;
if ( F_240 ( V_28 ) )
V_456 . V_90 . V_468 =
V_470 ;
}
}
}
if ( F_227 ( F_131 ( V_28 ) -> V_427 & V_473 ) ) {
F_131 ( V_28 ) -> V_427 |= V_428 ;
V_456 . V_90 . V_426 = 1 ;
}
if ( F_131 ( V_28 ) -> V_199 == 0 ) {
V_456 . V_90 . V_474 . V_463 = V_28 -> V_36 ;
F_248 ( & V_430 . V_173 , & V_456 , V_451 ) ;
V_430 . V_173 . V_196 = F_249 ( & V_5 -> V_50 -> V_37 ,
V_28 -> V_254 ,
V_28 -> V_36 ,
V_197 ) ;
if ( F_250 ( & V_5 -> V_50 -> V_37 , V_430 . V_173 . V_196 ) ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_69 ,
V_65 ) ;
return V_462 ;
}
V_26 -> V_196 = V_430 . V_173 . V_196 ;
V_430 . V_24 = V_31 ;
} else {
int V_18 , V_198 ;
struct V_202 * V_203 ;
struct V_102 * V_103 ;
F_133 ( & V_82 -> V_56 ) ;
V_103 = (struct V_102 * ) F_67 ( & V_82 -> V_104 ) ;
F_134 ( & V_82 -> V_56 ) ;
if ( ! V_103 ) {
F_78 ( V_82 , V_459 , V_82 -> V_86 ,
L_70 ) ;
goto V_475;
}
V_456 . V_90 . V_476 = 1 ;
V_456 . V_90 . V_474 . V_477 = ( F_131 ( V_28 ) -> V_199 + 1 ) ;
F_248 ( & V_430 . V_173 , & V_456 , V_451 ) ;
memset ( V_103 -> V_105 , 0 , V_103 -> V_109 ) ;
V_103 -> V_105 [ 0 ] . V_200 [ 0 ] = F_249 ( & V_5 -> V_50 -> V_37 ,
V_28 -> V_254 ,
( V_28 -> V_36 - V_28 -> V_201 ) ,
V_197 ) ;
if ( F_250 ( & V_5 -> V_50 -> V_37 , V_103 -> V_105 [ 0 ] . V_200 [ 0 ] ) ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_71 ,
V_65 ) ;
return V_462 ;
}
F_251 ( & V_103 -> V_105 [ 0 ] , ( V_28 -> V_36 - V_28 -> V_201 ) , 0 ) ;
V_198 = F_131 ( V_28 ) -> V_199 ;
V_18 = 1 ;
while ( V_198 -- ) {
V_203 = & F_131 ( V_28 ) -> V_198 [ V_18 - 1 ] ;
V_103 -> V_105 [ ( V_18 >> 2 ) ] . V_200 [ ( V_18 & 3 ) ] =
F_252 ( & V_5 -> V_50 -> V_37 ,
V_203 -> V_478 . V_365 ,
V_203 -> V_479 ,
V_203 -> V_204 ,
V_197 ) ;
F_251 ( & V_103 -> V_105 [ ( V_18 >> 2 ) ] , V_203 -> V_204 , ( V_18 & 3 ) ) ;
V_18 ++ ;
}
V_430 . V_173 . V_196 = F_249 ( & V_5 -> V_50 -> V_37 ,
V_103 -> V_105 , V_103 -> V_109 ,
V_197 ) ;
if ( F_250 ( & V_5 -> V_50 -> V_37 , V_430 . V_173 . V_196 ) ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_72 ,
V_65 ) ;
F_128 ( & V_5 -> V_50 -> V_37 , V_103 -> V_105 [ 0 ] . V_200 [ 0 ] ,
V_28 -> V_36 - V_28 -> V_201 ,
V_197 ) ;
return V_462 ;
}
V_26 -> V_196 = V_430 . V_173 . V_196 ;
V_26 -> V_103 = V_103 ;
V_430 . V_24 = V_32 ;
}
if ( F_131 ( V_28 ) -> V_480 ) {
struct V_481 * V_482 =
(struct V_481 * ) & V_430 . V_173 . V_482 ;
union V_483 * V_483 = (union V_483 * ) & V_430 . V_173 . V_484 [ 0 ] ;
V_482 -> V_36 = 1 ;
V_483 -> V_90 . V_480 = F_131 ( V_28 ) -> V_480 ;
V_483 -> V_90 . V_485 = F_131 ( V_28 ) -> V_485 ;
}
V_431 = V_28 -> V_431 ;
if ( F_227 ( V_456 . V_90 . V_426 ) )
V_63 = F_230 ( V_5 , & V_430 , V_26 , V_431 ) ;
else
V_63 = F_253 ( V_5 , & V_430 , V_431 ) ;
if ( V_63 == V_437 )
goto V_475;
F_78 ( V_82 , V_440 , V_82 -> V_86 , L_73 ) ;
if ( V_63 == V_486 )
F_64 ( V_82 -> V_86 , V_458 ) ;
F_254 ( V_86 ) ;
V_60 -> V_381 ++ ;
V_60 -> V_383 += V_28 -> V_36 ;
return V_487 ;
V_475:
F_128 ( & V_5 -> V_50 -> V_37 , V_430 . V_173 . V_196 ,
V_430 . V_463 , V_197 ) ;
V_460:
V_60 -> V_382 ++ ;
F_78 ( V_82 , V_459 , V_82 -> V_86 , L_74 ,
V_380 , V_60 -> V_382 ) ;
F_129 ( V_28 ) ;
return V_487 ;
}
static void F_255 ( struct V_85 * V_86 )
{
struct V_82 * V_82 ;
V_82 = F_62 ( V_86 ) ;
F_78 ( V_82 , V_459 , V_82 -> V_86 ,
L_75 ,
V_86 -> V_60 . V_382 ) ;
F_254 ( V_86 ) ;
F_57 ( V_86 ) ;
}
int F_256 ( struct V_85 * V_86 , int V_173 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
struct V_168 V_169 ;
struct V_170 V_171 ;
int V_191 = 0 ;
memset ( & V_169 , 0 , sizeof( struct V_168 ) ) ;
V_169 . V_172 . V_121 = 0 ;
V_169 . V_172 . V_90 . V_173 = V_173 ;
V_169 . V_172 . V_90 . V_175 = V_82 -> V_88 . V_176 ;
V_169 . V_172 . V_90 . V_177 = V_488 | V_489 ;
V_169 . V_364 = 100 ;
V_169 . V_178 = ( V_121 ) V_86 ;
V_169 . V_362 = F_211 ;
V_171 . V_179 = V_180 ;
V_191 = F_108 ( V_82 -> V_96 , & V_169 , V_171 ) ;
if ( V_191 < 0 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_76 ,
V_191 ) ;
}
return V_191 ;
}
static T_9 F_257 ( struct V_85 * V_86 ,
T_9 V_490 )
{
struct V_82 * V_82 = F_258 ( V_86 ) ;
if ( ( V_490 & V_287 ) &&
! ( V_82 -> V_491 & V_287 ) )
V_490 &= ~ V_287 ;
if ( ( V_490 & V_492 ) &&
! ( V_82 -> V_491 & V_492 ) )
V_490 &= ~ V_492 ;
if ( ( V_490 & V_493 ) && ! ( V_82 -> V_491 & V_493 ) )
V_490 &= ~ V_493 ;
if ( ( V_490 & V_494 ) && ! ( V_82 -> V_491 & V_494 ) )
V_490 &= ~ V_494 ;
if ( ( V_490 & V_495 ) && ! ( V_82 -> V_491 & V_495 ) )
V_490 &= ~ V_495 ;
if ( ! ( V_490 & V_287 ) && ( V_86 -> V_286 & V_495 ) &&
( V_82 -> V_491 & V_495 ) )
V_490 &= ~ V_495 ;
return V_490 ;
}
static int F_259 ( struct V_85 * V_86 ,
T_9 V_286 )
{
struct V_82 * V_82 = F_258 ( V_86 ) ;
if ( ! ( ( V_86 -> V_286 ^ V_286 ) & V_495 ) )
return 0 ;
if ( ( V_286 & V_495 ) && ( V_82 -> V_491 & V_495 ) )
F_256 ( V_86 , V_339 ) ;
else if ( ! ( V_286 & V_495 ) &&
( V_82 -> V_491 & V_495 ) )
F_256 ( V_86 , V_340 ) ;
return 0 ;
}
static int T_10 F_260 ( void )
{
int V_18 ;
struct V_137 * V_138 ;
F_91 ( & V_145 ) ;
F_261 ( V_496 ) ;
if ( F_43 () )
return - V_396 ;
F_262 ( & V_145 , F_196 ( 1000 ) ) ;
for ( V_18 = 0 ; V_18 < V_156 ; V_18 ++ ) {
V_138 = & V_137 [ V_18 ] ;
if ( V_138 -> V_50 ) {
F_263 ( & V_138 -> V_143 ) ;
if ( ! V_138 -> V_157 ) {
F_20 ( & V_138 -> V_50 -> V_37 ,
L_77 ) ;
F_45 () ;
return - V_497 ;
}
}
}
for ( V_18 = 0 ; V_18 < V_156 ; V_18 ++ ) {
V_138 = & V_137 [ V_18 ] ;
if ( V_138 -> V_50 ) {
F_262 ( & V_138 -> V_144 ,
F_196 ( 30000 ) ) ;
if ( ! V_138 -> V_158 ) {
F_20 ( & V_138 -> V_50 -> V_37 ,
L_78 ) ;
F_45 () ;
return - V_497 ;
}
}
}
return 0 ;
}
static int F_264 ( struct V_498 * V_499 , void * V_23 )
{
struct V_4 * V_5 = (struct V_4 * ) V_23 ;
struct V_500 * V_501 = V_499 -> V_501 ;
int V_176 = 0 ;
union V_118 * V_119 ;
int V_18 ;
if ( ( V_501 -> V_502 [ 0 ] != sizeof( * V_119 ) ) ||
( V_501 -> V_273 . V_503 . V_176 > V_5 -> V_185 ) ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_79 ,
V_501 -> V_502 [ 0 ] ,
V_501 -> V_273 . V_503 . V_176 ) ;
goto V_504;
}
V_176 = V_501 -> V_273 . V_503 . V_176 ;
V_119 = (union V_118 * ) F_265 ( V_501 -> V_505 [ 0 ] ) ;
F_226 ( ( V_121 * ) V_119 , ( sizeof( union V_118 ) ) >> 3 ) ;
F_79 ( V_5 -> V_182 [ V_176 ] . V_86 , V_119 ) ;
V_504:
for ( V_18 = 0 ; V_18 < V_501 -> V_506 ; V_18 ++ )
F_129 ( V_501 -> V_505 [ V_18 ] ) ;
F_266 ( V_499 ) ;
return 0 ;
}
static int F_267 ( struct V_4 * V_310 )
{
struct V_82 * V_82 = NULL ;
struct V_85 * V_86 ;
V_334 V_507 [ 6 ] , V_18 , V_184 ;
struct V_29 * V_30 ;
struct V_262 * V_263 ;
struct V_260 * V_261 ;
struct V_508 * V_182 ;
int V_315 , V_509 , V_510 , V_2 ;
V_121 V_511 ;
int V_512 = F_268 () ;
union V_513 V_514 ;
unsigned int V_515 ;
unsigned int V_516 ;
T_1 V_517 , V_518 ;
F_269 ( V_310 , V_519 ,
V_520 ,
F_264 , V_310 ) ;
F_270 ( V_310 , V_31 ,
F_127 ) ;
F_270 ( V_310 , V_32 ,
F_130 ) ;
F_270 ( V_310 , V_33 ,
F_135 ) ;
for ( V_18 = 0 ; V_18 < V_310 -> V_185 ; V_18 ++ ) {
V_517 = sizeof( struct V_260 ) ;
V_518 = sizeof( struct V_262 ) ;
V_30 = (struct V_29 * )
F_271 ( V_310 , 0 ,
V_517 , V_518 ) ;
V_261 = (struct V_260 * ) V_30 -> V_264 ;
V_263 = (struct V_262 * ) V_30 -> V_265 ;
V_509 =
F_272 ( F_120 ( V_310 ) , V_18 ) ;
V_510 =
F_273 ( F_120 ( V_310 ) , V_18 ) ;
V_515 =
F_274 ( F_120 ( V_310 ) , V_18 ) ;
V_516 =
F_275 ( F_120 ( V_310 ) , V_18 ) ;
if ( V_509 > V_512 )
V_509 = V_512 ;
if ( V_510 > V_512 )
V_510 = V_512 ;
F_34 ( & V_310 -> V_50 -> V_37 ,
L_80 ,
V_18 , V_509 , V_510 ) ;
F_165 ( V_263 -> V_266 ) = 0 ;
V_263 -> V_142 = F_276 ( V_310 ) ;
F_277 ( & V_263 -> V_267 ) ;
V_514 . V_121 = 0 ;
V_514 . V_90 . V_509 = V_509 ;
V_514 . V_90 . V_510 = V_510 ;
V_514 . V_90 . V_515 = V_515 ;
V_514 . V_90 . V_516 = V_516 ;
F_278 ( V_310 , V_30 , V_519 ,
V_521 , V_18 ,
V_514 . V_121 , 0 ) ;
V_30 -> V_438 = F_162 ;
V_30 -> V_35 = V_30 ;
V_30 -> V_364 = 1000 ;
V_315 = F_279 ( V_310 , V_30 ) ;
if ( V_315 ) {
F_20 ( & V_310 -> V_50 -> V_37 ,
L_81 ,
V_315 ) ;
goto V_522;
}
F_280 ( & V_263 -> V_267 , & V_263 -> V_266 ) ;
V_315 = V_261 -> V_63 ;
if ( V_315 ) {
F_20 ( & V_310 -> V_50 -> V_37 , L_82 ) ;
goto V_522;
}
F_226 ( ( V_121 * ) ( & V_261 -> V_523 ) ,
( sizeof( struct V_524 ) ) >> 3 ) ;
V_509 = F_281 ( V_261 -> V_523 . V_525 ) ;
V_510 = F_281 ( V_261 -> V_523 . V_526 ) ;
if ( ! ( V_509 ) || ! ( V_510 ) ) {
F_20 ( & V_310 -> V_50 -> V_37 ,
L_83 ,
V_261 -> V_523 . V_525 ,
V_261 -> V_523 . V_526 ) ;
goto V_522;
}
F_34 ( & V_310 -> V_50 -> V_37 ,
L_84 ,
V_18 , V_261 -> V_523 . V_525 , V_261 -> V_523 . V_526 ,
V_509 , V_510 ) ;
V_86 = F_282 ( V_527 , V_509 ) ;
if ( ! V_86 ) {
F_20 ( & V_310 -> V_50 -> V_37 , L_85 ) ;
goto V_522;
}
V_182 = & V_310 -> V_182 [ V_18 ] ;
V_182 -> V_86 = V_86 ;
if ( V_509 > 1 )
V_528 . V_529 = F_168 ;
V_86 -> V_530 = & V_528 ;
V_82 = F_62 ( V_86 ) ;
memset ( V_82 , 0 , sizeof( struct V_82 ) ) ;
V_82 -> V_88 . V_176 = V_261 -> V_523 . V_176 ;
V_82 -> V_176 = V_261 -> V_523 . V_176 ;
V_82 -> V_88 . V_186 = V_510 ;
V_82 -> V_88 . V_95 = V_509 ;
V_511 = V_261 -> V_523 . V_526 ;
for ( V_184 = 0 ; V_184 < V_510 ; V_184 ++ ) {
V_2 = F_283 ( V_511 ) ;
V_511 &= ( ~ ( 1UL << V_2 ) ) ;
V_82 -> V_88 . V_187 [ V_184 ] = V_2 ;
}
V_511 = V_261 -> V_523 . V_525 ;
for ( V_184 = 0 ; V_184 < V_509 ; V_184 ++ ) {
V_2 = F_283 ( V_511 ) ;
V_511 &= ( ~ ( 1UL << V_2 ) ) ;
V_82 -> V_88 . V_94 [ V_184 ] = V_2 ;
}
V_82 -> V_88 . V_371 = V_261 -> V_523 . V_88 . V_371 ;
V_82 -> V_88 . V_531 = V_261 -> V_523 . V_88 . V_531 ;
V_82 -> V_88 . V_89 . V_121 = V_261 -> V_523 . V_88 . V_89 . V_121 ;
V_82 -> V_532 = F_284 ( V_533 , V_534 ) ;
V_82 -> V_491 = V_535
| V_536 | V_537
| V_538 | V_287
| V_493 | V_494
| V_495 ;
F_285 ( V_86 , V_539 ) ;
V_86 -> V_286 = V_82 -> V_491 ;
V_86 -> V_540 = V_82 -> V_491 ;
V_86 -> V_541 = V_82 -> V_491 ;
V_82 -> V_96 = V_310 ;
V_82 -> V_542 = V_182 ;
V_82 -> V_86 = V_86 ;
F_150 ( & V_82 -> V_56 ) ;
F_34 ( & V_310 -> V_50 -> V_37 ,
L_86 , V_18 ,
V_82 -> V_88 . V_531 , F_164 ( V_82 -> V_88 . V_371 ) ) ;
F_226 ( & V_82 -> V_88 . V_371 , 1 ) ;
for ( V_184 = 0 ; V_184 < 6 ; V_184 ++ )
V_507 [ V_184 ] = * ( ( V_334 * ) ( ( ( V_334 * ) & V_82 -> V_88 . V_371 ) + 2 + V_184 ) ) ;
F_286 ( V_86 -> V_333 , V_507 ) ;
if ( F_186 ( V_310 , V_86 ) ) {
F_20 ( & V_310 -> V_50 -> V_37 , L_87 ) ;
goto V_522;
}
F_48 ( V_82 , V_543 ) ;
V_82 -> V_19 = V_82 -> V_88 . V_94 [ 0 ] ;
V_82 -> V_544 = V_82 -> V_88 . V_187 [ 0 ] ;
V_82 -> V_107 = F_287 ( V_310 , V_82 -> V_19 ) ;
V_82 -> V_545 = F_288 ( V_310 , V_82 -> V_544 ) ;
if ( F_71 ( V_82 ) ) {
F_20 ( & V_310 -> V_50 -> V_37 ,
L_88 ) ;
goto V_522;
}
F_289 ( V_86 ) ;
F_256 ( V_86 , V_339 ) ;
if ( ( V_533 != - 1 ) && ( V_533 & V_546 ) )
F_256 ( V_86 , V_341 ) ;
if ( F_290 ( V_86 ) ) {
F_20 ( & V_310 -> V_50 -> V_37 , L_89 ) ;
goto V_522;
}
F_34 ( & V_310 -> V_50 -> V_37 ,
L_90 ,
V_18 , V_507 [ 0 ] , V_507 [ 1 ] , V_507 [ 2 ] , V_507 [ 3 ] , V_507 [ 4 ] , V_507 [ 5 ] ) ;
F_81 ( V_86 ) ;
if ( V_82 -> V_88 . V_89 . V_90 . V_63 ) {
F_80 ( V_86 ) ;
F_61 ( V_86 ) ;
} else {
F_81 ( V_86 ) ;
}
F_48 ( V_82 , V_114 ) ;
F_34 ( & V_310 -> V_50 -> V_37 ,
L_91 , V_18 ) ;
F_229 ( V_310 , V_30 ) ;
}
return 0 ;
V_522:
F_229 ( V_310 , V_30 ) ;
while ( V_18 -- ) {
F_20 ( & V_310 -> V_50 -> V_37 ,
L_92 , V_18 ) ;
F_109 ( V_310 , V_18 ) ;
}
return - V_547 ;
}
static int F_291 ( struct V_4 * V_5 )
{
struct V_548 * V_549 ;
int V_315 = 0 ;
int V_550 = F_292 ( F_120 ( V_5 ) ) ;
F_34 ( & V_5 -> V_50 -> V_37 , L_93 ) ;
V_5 -> V_185 = V_550 ;
memset ( V_5 -> V_182 , 0 ,
sizeof( struct V_508 ) * V_550 ) ;
V_315 = F_267 ( V_5 ) ;
if ( V_315 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_94 ) ;
goto V_551;
}
F_153 ( V_5 ) ;
V_549 = & ( (struct V_4 * ) V_5 ) -> V_552 ;
V_549 -> V_553 = 1 ;
V_549 -> V_554 = V_555 ;
V_549 -> V_556 = V_557 ;
V_549 -> V_558 = V_559 ;
V_549 -> V_560 = V_561 ;
V_549 -> V_562 = V_563 ;
V_549 -> V_564 = V_565 ;
V_549 -> V_566 = V_567 ;
F_34 ( & V_5 -> V_50 -> V_37 , L_95 ) ;
return V_315 ;
V_551:
V_5 -> V_185 = 0 ;
return V_315 ;
}
static void F_293 ( struct V_318 * V_164 )
{
struct V_4 * V_5 ;
struct V_319 * V_320 = (struct V_319 * ) V_164 ;
V_5 = (struct V_4 * ) V_320 -> V_265 ;
if ( F_18 ( & V_5 -> V_63 ) == V_146 )
return;
if ( F_18 ( & V_5 -> V_63 ) != V_147 ) {
F_294 ( & V_5 -> V_163 . V_164 ,
V_568 ) ;
return;
}
F_30 ( & V_5 -> V_63 , V_146 ) ;
if ( V_5 -> V_148 && V_5 -> V_148 == V_188 ) {
F_34 ( & V_5 -> V_50 -> V_37 , L_96 ) ;
if ( F_291 ( V_5 ) )
F_20 ( & V_5 -> V_50 -> V_37 , L_97 ) ;
else
V_137 [ V_5 -> V_142 ] . V_158 = 1 ;
} else {
F_20 ( & V_5 -> V_50 -> V_37 ,
L_98 ,
V_5 -> V_148 ) ;
}
F_92 ( & V_137 [ V_5 -> V_142 ] . V_144 ) ;
}
static int F_93 ( struct V_4 * V_310 )
{
int V_184 , V_191 ;
struct V_6 * V_7 =
(struct V_6 * ) V_310 -> V_8 ;
F_30 ( & V_310 -> V_63 , V_166 ) ;
if ( F_121 ( V_310 ) )
return 1 ;
if ( F_115 ( V_310 ) ) {
F_20 ( & V_310 -> V_50 -> V_37 , L_99 ) ;
return 1 ;
}
F_30 ( & V_310 -> V_63 , V_165 ) ;
V_310 -> V_148 = V_149 ;
if ( V_310 -> V_71 . V_154 ( V_310 ) )
return 1 ;
if ( F_295 ( V_310 ) )
return 1 ;
F_269 ( V_310 , V_519 ,
V_569 ,
V_570 ,
V_310 ) ;
F_199 ( & V_310 -> V_163 . V_164 , F_293 ) ;
V_310 -> V_163 . V_265 = ( void * ) V_310 ;
F_294 ( & V_310 -> V_163 . V_164 ,
V_568 ) ;
F_30 ( & V_310 -> V_63 , V_162 ) ;
F_296 ( V_310 ) ;
if ( F_297 ( V_310 ) ) {
F_20 ( & V_310 -> V_50 -> V_37 ,
L_100 ) ;
for ( V_184 = 0 ; V_184 < V_310 -> V_571 ; V_184 ++ )
F_102 ( V_310 , V_184 ) ;
return 1 ;
}
F_30 ( & V_310 -> V_63 , V_161 ) ;
if ( F_298 ( V_310 ) ) {
F_20 ( & V_310 -> V_50 -> V_37 , L_101 ) ;
return 1 ;
}
F_30 ( & V_310 -> V_63 , V_160 ) ;
if ( F_299 ( V_310 ) ) {
F_20 ( & V_310 -> V_50 -> V_37 , L_102 ) ;
return 1 ;
}
F_30 ( & V_310 -> V_63 , V_159 ) ;
if ( F_300 ( V_310 ) ) {
F_20 ( & V_310 -> V_50 -> V_37 , L_103 ) ;
for ( V_184 = 0 ; V_184 < V_310 -> V_572 ; V_184 ++ )
F_99 ( V_310 , V_184 ) ;
}
F_30 ( & V_310 -> V_63 , V_155 ) ;
V_191 = V_310 -> V_71 . V_573 ( V_310 ) ;
if ( V_191 ) {
F_20 ( & V_310 -> V_50 -> V_37 ,
L_104 ) ;
return V_191 ;
}
F_34 ( & V_310 -> V_50 -> V_37 , L_105 ) ;
F_301 ( & V_7 -> V_14 , F_1 ,
( unsigned long ) V_310 ) ;
F_83 ( V_310 ) ;
V_310 -> V_71 . V_574 ( V_310 -> V_73 ) ;
V_310 -> V_71 . V_575 ( V_310 ) ;
F_30 ( & V_310 -> V_63 , V_152 ) ;
F_34 ( & V_310 -> V_50 -> V_37 , L_106 ) ;
if ( V_576 == 0 ) {
F_89 ( & V_310 -> V_50 -> V_37 ,
L_107 ) ;
}
F_6 ( V_49 * V_577 ) ;
V_191 = F_302 ( V_310 , & V_576 ) ;
if ( V_191 ) {
F_20 ( & V_310 -> V_50 -> V_37 ,
L_108 ,
V_191 ) ;
return 1 ;
}
if ( F_303 ( V_310 , 1000 ) != 0 ) {
F_20 ( & V_310 -> V_50 -> V_37 , L_109 ) ;
return 1 ;
}
F_34 ( & V_310 -> V_50 -> V_37 , L_110 ) ;
V_191 = F_304 ( V_310 ) ;
if ( V_191 ) {
F_20 ( & V_310 -> V_50 -> V_37 , L_111 ) ;
return 1 ;
}
V_191 = F_305 ( V_310 , 0 ) ;
if ( V_191 ) {
F_20 ( & V_310 -> V_50 -> V_37 , L_112 ) ;
return 1 ;
}
F_30 ( & V_310 -> V_63 , V_151 ) ;
F_34 ( & V_310 -> V_50 -> V_37 , L_113 ) ;
V_191 = F_154 ( V_310 ) ;
if ( V_191 ) {
F_20 ( & V_310 -> V_50 -> V_37 , L_114 ) ;
return 1 ;
}
V_137 [ V_310 -> V_142 ] . V_157 = 1 ;
F_92 ( & V_137 [ V_310 -> V_142 ] . V_143 ) ;
F_30 ( & V_310 -> V_63 , V_150 ) ;
for ( V_184 = 0 ; V_184 < V_310 -> V_572 ; V_184 ++ )
F_161 ( V_310 -> V_12 [ V_184 ] -> V_258 ,
V_310 -> V_12 [ V_184 ] -> V_259 ) ;
return 0 ;
}
static void T_11 F_306 ( void )
{
F_45 () ;
F_26 ( L_115 ) ;
}
