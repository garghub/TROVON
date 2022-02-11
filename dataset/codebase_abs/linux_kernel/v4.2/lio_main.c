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
memset ( V_103 , 0 , sizeof( struct V_102 ) ) ;
V_103 -> V_109 =
( ( F_74 ( V_110 ) >> 2 ) * V_111 ) ;
V_103 -> V_105 = F_73 ( V_103 -> V_109 + 8 , V_108 ) ;
if ( ! V_103 -> V_105 ) {
F_70 ( V_103 ) ;
break;
}
if ( ( ( unsigned long ) V_103 -> V_105 ) & 7 ) {
V_103 -> V_106 = 8 - ( ( ( unsigned long ) V_103 -> V_105 ) & 7 ) ;
V_103 -> V_105 = (struct V_112 * )
( ( unsigned long ) V_103 -> V_105 + V_103 -> V_106 ) ;
}
F_75 ( & V_103 -> V_113 , & V_82 -> V_104 ) ;
}
if ( V_18 == V_82 -> V_107 )
return 0 ;
F_69 ( V_82 ) ;
return 1 ;
}
static void F_76 ( struct V_85 * V_86 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
if ( F_18 ( & V_82 -> V_84 ) & V_114 ) {
struct V_115 * V_88 = & V_82 -> V_88 ;
if ( V_88 -> V_89 . V_90 . V_63 ) {
F_77 ( V_82 , V_89 , V_82 -> V_86 , L_6 ,
V_88 -> V_89 . V_90 . V_116 ,
( V_88 -> V_89 . V_90 . V_117 ) ? L_7 : L_8 ) ;
} else {
F_77 ( V_82 , V_89 , V_82 -> V_86 , L_9 ) ;
}
}
}
static inline void F_78 ( struct V_85 * V_86 ,
union V_118 * V_119 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
if ( ( V_82 -> V_120 ) && ( V_82 -> V_88 . V_89 . V_121 != V_119 -> V_121 ) ) {
V_82 -> V_88 . V_89 . V_121 = V_119 -> V_121 ;
F_76 ( V_86 ) ;
if ( V_82 -> V_88 . V_89 . V_90 . V_63 ) {
F_79 ( V_86 ) ;
F_57 ( V_86 ) ;
} else {
F_80 ( V_86 ) ;
F_60 ( V_86 ) ;
}
}
}
static
void F_81 ( struct V_4 * V_5 )
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
static int F_82 ( struct V_4 * V_5 )
{
int V_131 , V_132 ;
V_132 = F_83 ( V_5 -> V_50 ) ;
if ( V_132 )
F_84 ( & V_5 -> V_50 -> V_37 , L_10 ,
V_132 ) ;
else
V_5 -> V_75 |= V_76 ;
V_131 = F_85 ( V_5 -> V_50 -> V_74 , V_133 ,
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
static int F_86 ( struct V_50 * V_1 , const struct V_135 * V_136 )
{
struct V_4 * V_96 = NULL ;
struct V_137 * V_138 ;
V_96 = F_87 ( V_1 -> V_139 ,
sizeof( struct V_6 ) ) ;
if ( ! V_96 ) {
F_20 ( & V_1 -> V_37 , L_13 ) ;
return - V_140 ;
}
F_88 ( & V_1 -> V_37 , L_14 ,
( T_1 ) V_1 -> V_141 , ( T_1 ) V_1 -> V_139 ) ;
F_89 ( V_1 , V_96 ) ;
V_96 -> V_50 = ( void * ) V_1 ;
V_138 = & V_137 [ V_96 -> V_142 ] ;
F_90 ( & V_138 -> V_143 ) ;
F_90 ( & V_138 -> V_144 ) ;
V_138 -> V_50 = V_1 ;
if ( V_96 -> V_142 == 0 )
F_91 ( & V_145 ) ;
if ( F_92 ( V_96 ) ) {
F_93 ( V_1 ) ;
return - V_140 ;
}
F_34 ( & V_96 -> V_50 -> V_37 , L_15 ) ;
return 0 ;
}
static void F_94 ( struct V_4 * V_5 )
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
F_95 ( V_5 ) ;
case V_152 :
if ( F_17 ( V_5 ) )
F_20 ( & V_5 -> V_50 -> V_37 , L_1 ) ;
if ( F_96 ( V_5 ) )
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
F_97 ( 100 ) ;
for ( V_18 = 0 ; V_18 < V_9 ; V_18 ++ ) {
if ( ! ( V_5 -> V_10 . V_11 & ( 1UL << V_18 ) ) )
continue;
F_98 ( V_5 , V_18 ) ;
}
for ( V_18 = 0 ; V_18 < V_156 ; V_18 ++ ) {
V_138 = & V_137 [ V_18 ] ;
if ( V_138 -> V_50 ) {
V_137 [ V_5 -> V_142 ] . V_157 = 0 ;
F_91 ( & V_137 [ V_5 -> V_142 ] . V_143 ) ;
V_137 [ V_5 -> V_142 ] . V_158 = 0 ;
F_91 ( & V_137 [ V_5 -> V_142 ] . V_144 ) ;
}
}
case V_159 :
F_99 ( V_5 ) ;
case V_160 :
F_100 ( V_5 ) ;
case V_161 :
for ( V_18 = 0 ; V_18 < V_51 ; V_18 ++ ) {
if ( ! ( V_5 -> V_10 . V_53 & ( 1UL << V_18 ) ) )
continue;
F_101 ( V_5 , V_18 ) ;
}
case V_162 :
F_102 ( V_5 ) ;
F_103 ( & V_5 -> V_163 . V_164 ) ;
case V_165 :
F_104 ( V_5 , 0 ) ;
F_104 ( V_5 , 1 ) ;
case V_166 :
break;
}
F_105 ( & V_7 -> V_14 ) ;
}
static void F_106 ( struct V_82 * V_82 , int V_167 )
{
struct V_168 V_169 ;
struct V_170 V_171 ;
memset ( & V_169 , 0 , sizeof( struct V_168 ) ) ;
V_169 . V_172 . V_90 . V_173 = V_174 ;
V_169 . V_172 . V_90 . V_175 = V_82 -> V_88 . V_176 ;
V_169 . V_172 . V_90 . V_177 = V_167 ;
V_169 . V_178 = ( V_121 ) V_82 -> V_86 ;
V_171 . V_179 = V_180 ;
if ( F_107 ( V_82 -> V_96 , & V_169 , V_171 ) < 0 )
F_77 ( V_82 , V_181 , V_82 -> V_86 , L_18 ) ;
}
static void F_108 ( struct V_4 * V_5 , int V_176 )
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
F_106 ( V_82 , 0 ) ;
if ( F_18 ( & V_82 -> V_84 ) & V_183 )
F_50 ( V_86 ) ;
if ( F_18 ( & V_82 -> V_84 ) & V_114 )
F_109 ( V_86 ) ;
F_69 ( V_82 ) ;
F_110 ( V_86 ) ;
V_5 -> V_182 [ V_176 ] . V_86 = NULL ;
}
static int F_111 ( struct V_4 * V_5 )
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
F_112 ( V_5 , V_82 -> V_88 . V_187 [ V_184 ] ) ;
}
for ( V_18 = 0 ; V_18 < V_5 -> V_185 ; V_18 ++ )
F_108 ( V_5 , V_18 ) ;
F_34 ( & V_5 -> V_50 -> V_37 , L_23 ) ;
return 0 ;
}
static void F_93 ( struct V_50 * V_1 )
{
struct V_4 * V_96 = F_37 ( V_1 ) ;
F_34 ( & V_96 -> V_50 -> V_37 , L_24 ) ;
if ( V_96 -> V_148 && ( V_96 -> V_148 == V_188 ) )
F_111 ( V_96 ) ;
F_94 ( V_96 ) ;
F_88 ( & V_96 -> V_50 -> V_37 , L_25 ) ;
F_113 ( V_96 ) ;
}
static int F_114 ( struct V_4 * V_5 )
{
T_1 V_189 , V_190 ;
int V_191 = 1 ;
F_27 ( V_5 -> V_50 , 0 , & V_189 ) ;
F_27 ( V_5 -> V_50 , 8 , & V_190 ) ;
V_5 -> V_190 = V_190 & 0xff ;
switch ( V_189 ) {
case V_192 :
V_5 -> V_40 = V_42 ;
V_191 = F_115 ( V_5 ) ;
break;
case V_193 :
V_5 -> V_40 = V_41 ;
V_191 = F_116 ( V_5 ) ;
break;
default:
F_20 ( & V_5 -> V_50 -> V_37 , L_26 ,
V_189 ) ;
}
if ( ! V_191 )
F_88 ( & V_5 -> V_50 -> V_37 , L_27 ,
F_117 ( V_5 ) ,
F_118 ( V_5 ) ,
F_119 ( V_5 ) -> V_194 ) ;
return V_191 ;
}
static int F_120 ( struct V_4 * V_5 )
{
if ( F_121 ( V_5 -> V_50 ) ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_28 ) ;
return 1 ;
}
if ( F_122 ( & V_5 -> V_50 -> V_37 , F_123 ( 64 ) ) ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_29 ) ;
return 1 ;
}
F_124 ( V_5 -> V_50 ) ;
return 0 ;
}
static inline int F_125 ( struct V_82 * V_82 , struct V_27 * V_28 )
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
static void F_126 ( void * V_23 )
{
struct V_27 * V_28 ;
struct V_25 * V_26 ;
struct V_82 * V_82 ;
V_26 = (struct V_25 * ) V_23 ;
V_28 = V_26 -> V_28 ;
V_82 = V_26 -> V_82 ;
F_127 ( & V_82 -> V_96 -> V_50 -> V_37 , V_26 -> V_196 , V_28 -> V_36 ,
V_197 ) ;
F_125 ( V_82 , V_28 ) ;
F_128 ( (struct V_27 * ) V_28 ) ;
}
static void F_129 ( void * V_23 )
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
V_198 = F_130 ( V_28 ) -> V_199 ;
F_127 ( & V_82 -> V_96 -> V_50 -> V_37 ,
V_103 -> V_105 [ 0 ] . V_200 [ 0 ] , ( V_28 -> V_36 - V_28 -> V_201 ) ,
V_197 ) ;
V_18 = 1 ;
while ( V_198 -- ) {
struct V_202 * V_203 = & F_130 ( V_28 ) -> V_198 [ V_18 - 1 ] ;
F_131 ( ( V_82 -> V_96 ) -> V_50 ,
V_103 -> V_105 [ ( V_18 >> 2 ) ] . V_200 [ ( V_18 & 3 ) ] ,
V_203 -> V_204 , V_197 ) ;
V_18 ++ ;
}
F_127 ( & V_82 -> V_96 -> V_50 -> V_37 ,
V_26 -> V_196 , V_103 -> V_109 ,
V_197 ) ;
F_132 ( & V_82 -> V_56 ) ;
F_75 ( & V_103 -> V_113 , & V_82 -> V_104 ) ;
F_133 ( & V_82 -> V_56 ) ;
F_125 ( V_82 , V_28 ) ;
F_128 ( (struct V_27 * ) V_28 ) ;
}
static void F_134 ( void * V_23 )
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
V_198 = F_130 ( V_28 ) -> V_199 ;
F_127 ( & V_82 -> V_96 -> V_50 -> V_37 ,
V_103 -> V_105 [ 0 ] . V_200 [ 0 ] , ( V_28 -> V_36 - V_28 -> V_201 ) ,
V_197 ) ;
V_18 = 1 ;
while ( V_198 -- ) {
struct V_202 * V_203 = & F_130 ( V_28 ) -> V_198 [ V_18 - 1 ] ;
F_131 ( ( V_82 -> V_96 ) -> V_50 ,
V_103 -> V_105 [ ( V_18 >> 2 ) ] . V_200 [ ( V_18 & 3 ) ] ,
V_203 -> V_204 , V_197 ) ;
V_18 ++ ;
}
F_127 ( & V_82 -> V_96 -> V_50 -> V_37 ,
V_26 -> V_196 , V_103 -> V_109 ,
V_197 ) ;
F_132 ( & V_82 -> V_56 ) ;
F_75 ( & V_103 -> V_113 , & V_82 -> V_104 ) ;
F_133 ( & V_82 -> V_56 ) ;
F_125 ( V_82 , V_28 ) ;
}
static int F_135 ( struct V_206 * V_207 , T_5 V_208 )
{
struct V_82 * V_82 = F_136 ( V_207 , struct V_82 , V_209 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_82 -> V_96 ;
V_121 V_210 , V_211 ;
unsigned long V_75 ;
bool V_212 = false ;
if ( V_208 < 0 ) {
V_212 = true ;
V_208 = - V_208 ;
}
V_211 = ( V_121 ) V_208 << 32 ;
F_137 ( V_211 , V_5 -> V_213 ) ;
F_138 ( & V_82 -> V_214 , V_75 ) ;
V_210 = F_139 ( V_5 , V_215 ) ;
if ( V_212 )
V_210 -= V_211 ;
else
V_210 += V_211 ;
F_140 ( V_5 , V_210 , V_215 ) ;
F_141 ( & V_82 -> V_214 , V_75 ) ;
return 0 ;
}
static int F_142 ( struct V_206 * V_207 , T_6 V_211 )
{
unsigned long V_75 ;
struct V_82 * V_82 = F_136 ( V_207 , struct V_82 , V_209 ) ;
F_138 ( & V_82 -> V_214 , V_75 ) ;
V_82 -> V_216 += V_211 ;
F_141 ( & V_82 -> V_214 , V_75 ) ;
return 0 ;
}
static int F_143 ( struct V_206 * V_207 ,
struct V_217 * V_218 )
{
V_121 V_219 ;
T_1 V_220 ;
unsigned long V_75 ;
struct V_82 * V_82 = F_136 ( V_207 , struct V_82 , V_209 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_82 -> V_96 ;
F_138 ( & V_82 -> V_214 , V_75 ) ;
V_219 = F_139 ( V_5 , V_221 ) ;
V_219 += V_82 -> V_216 ;
F_141 ( & V_82 -> V_214 , V_75 ) ;
V_218 -> V_222 = F_144 ( V_219 , 1000000000ULL , & V_220 ) ;
V_218 -> V_223 = V_220 ;
return 0 ;
}
static int F_145 ( struct V_206 * V_207 ,
const struct V_217 * V_218 )
{
V_121 V_219 ;
unsigned long V_75 ;
struct V_82 * V_82 = F_136 ( V_207 , struct V_82 , V_209 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_82 -> V_96 ;
V_219 = F_146 ( V_218 ) ;
F_138 ( & V_82 -> V_214 , V_75 ) ;
F_140 ( V_5 , V_219 , V_221 ) ;
V_82 -> V_216 = 0 ;
F_141 ( & V_82 -> V_214 , V_75 ) ;
return 0 ;
}
static int F_147 ( struct V_206 * V_207 ,
struct V_224 * V_225 , int V_226 )
{
return - V_227 ;
}
static void F_148 ( struct V_85 * V_86 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_82 -> V_96 ;
F_149 ( & V_82 -> V_214 ) ;
snprintf ( V_82 -> V_209 . V_228 , 16 , L_30 , V_86 -> V_228 ) ;
V_82 -> V_209 . V_229 = V_230 ;
V_82 -> V_209 . V_231 = 250000000 ;
V_82 -> V_209 . V_232 = 0 ;
V_82 -> V_209 . V_233 = 0 ;
V_82 -> V_209 . V_234 = 0 ;
V_82 -> V_209 . V_235 = 0 ;
V_82 -> V_209 . V_236 = F_135 ;
V_82 -> V_209 . V_237 = F_142 ;
V_82 -> V_209 . V_238 = F_143 ;
V_82 -> V_209 . V_239 = F_145 ;
V_82 -> V_209 . V_240 = F_147 ;
V_82 -> V_216 = 0 ;
V_82 -> V_241 = F_150 ( & V_82 -> V_209 ,
& V_5 -> V_50 -> V_37 ) ;
if ( F_151 ( V_82 -> V_241 ) )
V_82 -> V_241 = NULL ;
}
static void F_152 ( struct V_4 * V_5 )
{
V_121 V_242 , V_243 ;
V_242 = ( V_121 ) V_244 << 32 ;
F_137 ( V_242 , V_5 -> V_213 ) ;
F_140 ( V_5 , V_242 , V_215 ) ;
V_243 = F_139 ( V_5 , V_245 ) ;
F_140 ( V_5 , V_243 | 0x01 , V_245 ) ;
}
static int F_153 ( struct V_4 * V_5 )
{
int V_191 = 0 ;
const struct V_246 * V_247 ;
char V_248 [ V_249 ] ;
char * V_250 ;
if ( strncmp ( V_251 , V_252 ,
sizeof( V_252 ) ) == 0 ) {
F_88 ( & V_5 -> V_50 -> V_37 , L_31 ) ;
return V_191 ;
}
if ( V_251 [ 0 ] == '\0' )
V_250 = V_253 ;
else
V_250 = V_251 ;
sprintf ( V_248 , L_32 , V_254 , V_255 ,
F_119 ( V_5 ) -> V_194 , V_250 ,
V_256 ) ;
V_191 = F_154 ( & V_247 , V_248 , & V_5 -> V_50 -> V_37 ) ;
if ( V_191 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_33 ,
V_248 ) ;
return V_191 ;
}
V_191 = F_155 ( V_5 , V_247 -> V_257 , V_247 -> V_204 ) ;
F_156 ( V_247 ) ;
return V_191 ;
}
static int F_157 ( struct V_4 * V_5 , int V_2 , int V_258 ,
int V_259 , void * V_260 )
{
int V_92 = 0 ;
F_34 ( & V_5 -> V_50 -> V_37 , L_34 , V_2 ) ;
V_92 = F_158 ( V_5 , V_2 , V_258 , V_259 , V_260 ) ;
if ( V_92 == - 1 )
return V_92 ;
if ( V_92 == 1 ) {
F_34 ( & V_5 -> V_50 -> V_37 , L_35 , V_2 ) ;
return 0 ;
}
F_159 ( V_5 , V_2 , 1 ) ;
F_160 ( V_5 -> V_12 [ V_2 ] -> V_261 ,
V_5 -> V_12 [ V_2 ] -> V_262 ) ;
return V_92 ;
}
static void F_161 ( struct V_4 * V_5 ,
T_1 V_63 ,
void * V_23 )
{
struct V_29 * V_30 = (struct V_29 * ) V_23 ;
struct V_263 * V_264 ;
struct V_265 * V_266 ;
V_264 = (struct V_263 * ) V_30 -> V_267 ;
V_266 = (struct V_265 * ) V_30 -> V_268 ;
V_5 = F_162 ( V_266 -> V_142 ) ;
if ( V_264 -> V_63 )
F_20 ( & V_5 -> V_50 -> V_37 , L_36 ,
F_163 ( V_264 -> V_63 ) ) ;
F_164 ( V_266 -> V_269 ) = 1 ;
F_165 () ;
F_166 ( & V_266 -> V_270 ) ;
}
static T_7 F_167 ( struct V_85 * V_37 , struct V_27 * V_28 ,
void * V_271 , T_8 V_272 )
{
int V_273 ;
struct V_82 * V_82 ;
V_82 = F_62 ( V_37 ) ;
V_273 = F_168 ( V_28 ) ?
F_169 ( V_28 ) : F_170 () ;
return ( T_7 ) ( V_273 & ( V_82 -> V_88 . V_95 - 1 ) ) ;
}
static void
F_171 ( T_1 V_142 ,
void * V_274 ,
T_1 V_36 ,
union V_275 * V_276 ,
void * V_277 )
{
struct V_278 * V_279 = V_277 ;
struct V_4 * V_5 = F_162 ( V_142 ) ;
struct V_27 * V_28 = (struct V_27 * ) V_274 ;
struct V_280 * V_281 ;
V_121 V_219 ;
struct V_85 * V_86 =
(struct V_85 * ) V_5 -> V_182 [ V_276 -> V_282 . V_89 ] . V_86 ;
struct V_123 * V_12 = F_136 ( V_277 , struct V_123 ,
V_279 ) ;
if ( V_86 ) {
int V_283 ;
struct V_82 * V_82 = F_62 ( V_86 ) ;
if ( ! F_47 ( V_82 , V_183 ) ) {
F_128 ( V_28 ) ;
V_12 -> V_60 . V_284 ++ ;
return;
}
V_28 -> V_37 = V_86 ;
if ( V_276 -> V_282 . V_285 ) {
if ( F_47 ( V_82 ,
V_286 ) ) {
memcpy ( & V_219 , ( V_28 -> V_257 ) , sizeof( V_219 ) ) ;
V_281 = F_172 ( V_28 ) ;
V_281 -> V_287 =
F_173 ( V_219 + V_82 -> V_216 ) ;
}
F_174 ( V_28 , sizeof( V_219 ) ) ;
}
V_28 -> V_288 = F_175 ( V_28 , V_28 -> V_37 ) ;
if ( ( V_86 -> V_289 & V_290 ) &&
( V_276 -> V_282 . V_291 == V_292 ) )
V_28 -> V_293 = V_294 ;
else
V_28 -> V_293 = V_295 ;
V_283 = F_176 ( V_279 , V_28 ) != V_296 ;
if ( V_283 ) {
V_12 -> V_60 . V_297 += V_36 ;
V_12 -> V_60 . V_298 ++ ;
V_86 -> V_299 = V_300 ;
} else {
V_12 -> V_60 . V_284 ++ ;
F_77 ( V_82 , V_181 , V_82 -> V_86 ,
L_37 ,
V_12 -> V_2 , V_12 -> V_60 . V_284 ) ;
}
} else {
F_128 ( V_28 ) ;
}
}
static void F_177 ( void * V_277 )
{
struct V_278 * V_279 = V_277 ;
F_178 ( V_279 ) ;
}
static void F_179 ( void * V_301 )
{
struct V_123 * V_12 = V_301 ;
int V_302 = F_170 () ;
if ( V_12 -> V_303 == V_302 ) {
F_178 ( & V_12 -> V_279 ) ;
} else {
struct V_304 * V_305 = & V_12 -> V_305 ;
V_305 -> V_306 = F_177 ;
V_305 -> V_307 = & V_12 -> V_279 ;
V_305 -> V_75 = 0 ;
F_180 ( V_12 -> V_303 , V_305 ) ;
}
}
static int F_181 ( struct V_123 * V_12 , int V_308 )
{
int V_309 ;
struct V_82 * V_82 = F_62 ( V_12 -> V_279 . V_37 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
V_309 = F_182 ( V_5 , V_12 -> V_2 ,
V_310 ,
V_308 ) ;
if ( V_309 < 0 ) {
F_77 ( V_82 , V_181 , V_82 -> V_86 ,
L_38 , V_12 -> V_2 ) ;
goto V_311;
}
if ( V_309 > V_308 )
F_20 ( & V_5 -> V_50 -> V_37 , L_39 ,
V_65 , V_309 , V_308 ) ;
return V_309 ;
V_311:
F_183 ( & V_12 -> V_279 ) ;
F_182 ( V_5 , V_12 -> V_2 , V_312 ,
0 ) ;
return 0 ;
}
static int F_184 ( struct V_278 * V_279 , int V_308 )
{
struct V_123 * V_12 ;
int V_309 ;
V_12 = F_136 ( V_279 , struct V_123 , V_279 ) ;
V_309 = F_181 ( V_12 , V_308 ) ;
if ( V_309 < V_308 ) {
F_183 ( V_279 ) ;
F_182 ( V_12 -> V_96 , V_12 -> V_2 ,
V_312 , 0 ) ;
return 0 ;
}
return V_309 ;
}
static inline int F_185 ( struct V_4 * V_313 ,
struct V_85 * V_85 )
{
static int V_314 = 1 ;
static struct V_315 V_316 ;
static int V_303 ;
static int V_317 ;
struct V_123 * V_12 ;
struct V_278 * V_279 ;
int V_91 , V_2 , V_318 = 0 ;
struct V_82 * V_82 ;
int V_319 ;
V_82 = F_62 ( V_85 ) ;
if ( V_314 ) {
V_314 = 0 ;
memset ( & V_316 , 0 , sizeof( struct V_315 ) ) ;
V_316 . V_320 = F_171 ;
V_316 . V_128 = 1 ;
V_316 . V_129 = F_179 ;
V_303 = 0 ;
V_317 = F_186 () ;
}
for ( V_91 = 0 ; V_91 < V_82 -> V_88 . V_186 ; V_91 ++ ) {
V_2 = V_82 -> V_88 . V_187 [ V_91 ] ;
V_318 = F_157 ( V_313 , V_2 ,
F_187
( F_119 ( V_313 ) ,
V_82 -> V_176 ) ,
F_188
( F_119 ( V_313 ) ,
V_82 -> V_176 ) , NULL ) ;
if ( V_318 ) {
F_20 ( & V_313 -> V_50 -> V_37 ,
L_40 ,
V_65 ) ;
return 1 ;
}
V_12 = V_313 -> V_12 [ V_2 ] ;
V_279 = & V_12 -> V_279 ;
F_189 ( V_85 , V_279 , F_184 , 64 ) ;
V_12 -> V_303 = V_303 ;
V_303 ++ ;
if ( V_303 >= V_317 )
V_303 = 0 ;
F_190 ( V_313 , V_2 , & V_316 ) ;
}
for ( V_91 = 0 ; V_91 < V_82 -> V_88 . V_95 ; V_91 ++ ) {
V_319 = F_191 ( F_119
( V_313 ) ,
V_82 -> V_176 ) ;
V_318 = F_192 ( V_313 , V_82 -> V_88 . V_94 [ V_91 ] ,
V_319 ,
F_11 ( V_85 , V_91 ) ) ;
if ( V_318 ) {
F_20 ( & V_313 -> V_50 -> V_37 ,
L_41 ,
V_65 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_193 ( struct V_321 * V_164 )
{
struct V_322 * V_323 = (struct V_322 * ) V_164 ;
struct V_82 * V_82 = (struct V_82 * ) V_323 -> V_268 ;
if ( ! F_47 ( V_82 , V_183 ) )
return;
F_65 ( V_82 ) ;
F_194 ( V_82 -> V_324 . V_325 ,
& V_82 -> V_324 . V_323 . V_164 , F_195 ( 1 ) ) ;
}
static inline void F_196 ( struct V_85 * V_86 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
V_82 -> V_324 . V_325 = F_197 ( L_42 ) ;
if ( ! V_82 -> V_324 . V_325 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_43 ) ;
return;
}
F_198 ( & V_82 -> V_324 . V_323 . V_164 ,
F_193 ) ;
V_82 -> V_324 . V_323 . V_268 = V_82 ;
F_194 ( V_82 -> V_324 . V_325 ,
& V_82 -> V_324 . V_323 . V_164 , F_195 ( 1 ) ) ;
}
static int F_199 ( struct V_85 * V_86 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
struct V_278 * V_279 , * V_326 ;
F_200 (napi, n, &netdev->napi_list, dev_list)
F_201 ( V_279 ) ;
F_148 ( V_86 ) ;
F_48 ( V_82 , V_183 ) ;
F_196 ( V_86 ) ;
F_61 ( V_86 ) ;
F_77 ( V_82 , V_327 , V_82 -> V_86 , L_44 ) ;
F_202 ( V_230 ) ;
F_106 ( V_82 , 1 ) ;
V_82 -> V_120 = 1 ;
F_88 ( & V_5 -> V_50 -> V_37 , L_45 ,
V_86 -> V_228 ) ;
return 0 ;
}
static int F_203 ( struct V_85 * V_86 )
{
struct V_278 * V_279 , * V_326 ;
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
F_77 ( V_82 , V_328 , V_82 -> V_86 , L_46 ) ;
V_82 -> V_120 = 0 ;
V_82 -> V_88 . V_89 . V_90 . V_63 = 0 ;
F_80 ( V_86 ) ;
F_106 ( V_82 , 0 ) ;
F_103 ( & V_82 -> V_324 . V_323 . V_164 ) ;
F_204 ( V_82 -> V_324 . V_325 ) ;
F_205 ( V_82 -> V_324 . V_325 ) ;
if ( V_82 -> V_241 ) {
F_206 ( V_82 -> V_241 ) ;
V_82 -> V_241 = NULL ;
}
F_49 ( V_82 , V_183 ) ;
F_207 ( V_329 , & V_82 -> V_86 -> V_77 ) ;
F_200 (napi, n, &netdev->napi_list, dev_list)
F_208 ( V_279 ) ;
F_50 ( V_86 ) ;
F_88 ( & V_5 -> V_50 -> V_37 , L_47 , V_86 -> V_228 ) ;
F_209 ( V_230 ) ;
return 0 ;
}
void F_210 ( void * V_330 )
{
struct V_168 * V_169 = (struct V_168 * ) V_330 ;
struct V_85 * V_86 = (struct V_85 * ) V_169 -> V_178 ;
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
switch ( V_169 -> V_172 . V_90 . V_173 ) {
case V_331 :
case V_332 :
break;
case V_333 :
F_77 ( V_82 , V_334 , V_82 -> V_86 , L_48 ,
F_163 ( V_169 -> V_335 [ 0 ] ) ) ;
F_88 ( & V_5 -> V_50 -> V_37 , L_49 ,
V_86 -> V_228 , F_163 ( V_169 -> V_335 [ 0 ] ) ) ;
memcpy ( V_86 -> V_336 , ( ( V_337 * ) & V_169 -> V_335 [ 0 ] ) + 2 , V_338 ) ;
break;
case V_339 :
F_77 ( V_82 , V_334 , V_82 -> V_86 , L_50 ,
V_86 -> V_340 , V_169 -> V_172 . V_90 . V_177 ) ;
F_88 ( & V_5 -> V_50 -> V_37 , L_51 ,
V_86 -> V_228 , V_86 -> V_340 ,
V_169 -> V_172 . V_90 . V_177 ) ;
V_86 -> V_340 = V_169 -> V_172 . V_90 . V_177 ;
break;
case V_341 :
F_77 ( V_82 , V_334 , V_82 -> V_86 , L_52 ) ;
break;
case V_342 :
F_88 ( & V_5 -> V_50 -> V_37 , L_53 , V_86 -> V_228 ) ;
break;
case V_343 :
F_88 ( & V_5 -> V_50 -> V_37 , L_54 ,
V_86 -> V_228 ) ;
break;
case V_344 :
F_88 ( & V_5 -> V_50 -> V_37 , L_53 , V_86 -> V_228 ) ;
break;
case V_345 :
F_88 ( & V_5 -> V_50 -> V_37 , L_54 ,
V_86 -> V_228 ) ;
break;
case V_346 :
F_88 ( & V_5 -> V_50 -> V_37 , L_55 ,
V_86 -> V_228 ) ;
break;
default:
F_20 ( & V_5 -> V_50 -> V_37 , L_56 , V_65 ,
V_169 -> V_172 . V_90 . V_173 ) ;
}
}
static inline enum V_347 F_211 ( struct V_85 * V_86 )
{
enum V_347 V_348 = V_349 ;
if ( V_86 -> V_75 & V_350 )
V_348 |= V_351 ;
if ( V_86 -> V_75 & V_352 )
V_348 |= V_353 ;
if ( V_86 -> V_75 & V_354 ) {
V_348 |= V_355 ;
if ( F_212 ( V_86 ) > V_356 )
V_348 |= V_353 ;
}
if ( V_86 -> V_75 & V_357 )
V_348 |= V_358 ;
return V_348 ;
}
static void F_213 ( struct V_85 * V_86 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
struct V_168 V_169 ;
struct V_170 V_171 ;
struct V_359 * V_360 ;
V_121 * V_361 ;
int V_191 , V_18 ;
int V_362 = F_214 ( F_212 ( V_86 ) , V_356 ) ;
memset ( & V_169 , 0 , sizeof( struct V_168 ) ) ;
V_169 . V_172 . V_121 = 0 ;
V_169 . V_172 . V_90 . V_173 = V_332 ;
V_169 . V_172 . V_90 . V_175 = V_82 -> V_88 . V_176 ;
V_169 . V_172 . V_90 . V_177 = F_211 ( V_86 ) ;
V_169 . V_172 . V_90 . V_363 = V_362 ;
V_169 . V_172 . V_90 . V_364 = V_362 ;
V_169 . V_178 = ( V_121 ) V_86 ;
V_169 . V_365 = F_210 ;
V_18 = 0 ;
V_361 = & V_169 . V_335 [ 0 ] ;
F_215 (ha, netdev) {
* V_361 = 0 ;
memcpy ( ( ( V_337 * ) V_361 ) + 2 , V_360 -> V_366 , V_338 ) ;
if ( ++ V_361 > & V_169 . V_335 [ V_362 ] )
break;
}
V_169 . V_367 = 0 ;
V_171 . V_179 = V_180 ;
V_191 = F_107 ( V_82 -> V_96 , & V_169 , V_171 ) ;
if ( V_191 < 0 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_57 ,
V_191 ) ;
}
}
static int F_216 ( struct V_85 * V_86 , void * V_368 )
{
int V_191 = 0 ;
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
struct V_369 * V_366 = (struct V_369 * ) V_368 ;
struct V_168 V_169 ;
struct V_170 V_171 ;
if ( ( ! F_217 ( V_366 -> V_370 ) ) ||
( F_47 ( V_82 , V_183 ) ) )
return - V_371 ;
memset ( & V_169 , 0 , sizeof( struct V_168 ) ) ;
V_169 . V_172 . V_121 = 0 ;
V_169 . V_172 . V_90 . V_173 = V_333 ;
V_169 . V_172 . V_90 . V_175 = V_82 -> V_88 . V_176 ;
V_169 . V_172 . V_90 . V_177 = 0 ;
V_169 . V_172 . V_90 . V_364 = 1 ;
V_169 . V_178 = ( V_121 ) V_86 ;
V_169 . V_365 = F_210 ;
V_169 . V_367 = 100 ;
V_169 . V_335 [ 0 ] = 0 ;
memcpy ( ( V_337 * ) & V_169 . V_335 [ 0 ] + 2 , V_366 -> V_370 , V_338 ) ;
V_171 . V_179 = V_372 ;
V_191 = F_107 ( V_82 -> V_96 , & V_169 , V_171 ) ;
if ( V_191 < 0 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_58 ) ;
return - V_140 ;
}
memcpy ( V_86 -> V_336 , V_366 -> V_370 , V_86 -> V_373 ) ;
memcpy ( ( ( V_337 * ) & V_82 -> V_88 . V_374 ) + 2 , V_366 -> V_370 , V_338 ) ;
return 0 ;
}
static struct V_375 * F_218 ( struct V_85 * V_86 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_375 * V_60 = & V_86 -> V_60 ;
struct V_4 * V_5 ;
V_121 V_376 = 0 , V_377 = 0 , V_378 = 0 ;
struct V_379 * V_380 ;
struct V_381 * V_382 ;
int V_18 , V_383 , V_122 ;
V_5 = V_82 -> V_96 ;
for ( V_18 = 0 ; V_18 < V_82 -> V_88 . V_95 ; V_18 ++ ) {
V_383 = V_82 -> V_88 . V_94 [ V_18 ] ;
V_382 = & V_5 -> V_54 [ V_383 ] -> V_60 ;
V_376 += V_382 -> V_384 ;
V_377 += V_382 -> V_385 ;
V_378 += V_382 -> V_386 ;
}
V_60 -> V_387 = V_376 ;
V_60 -> V_388 = V_378 ;
V_60 -> V_385 = V_377 ;
V_376 = 0 ;
V_377 = 0 ;
V_378 = 0 ;
for ( V_18 = 0 ; V_18 < V_82 -> V_88 . V_186 ; V_18 ++ ) {
V_122 = V_82 -> V_88 . V_187 [ V_18 ] ;
V_380 = & V_5 -> V_12 [ V_122 ] -> V_60 ;
V_376 += V_380 -> V_298 ;
V_377 += ( V_380 -> V_284 +
V_380 -> V_389 +
V_380 -> V_390 +
V_380 -> V_391 ) ;
V_378 += V_380 -> V_297 ;
}
V_60 -> V_392 = V_378 ;
V_60 -> V_393 = V_376 ;
V_60 -> V_284 = V_377 ;
return V_60 ;
}
static int F_219 ( struct V_85 * V_86 , int V_394 )
{
struct V_82 * V_82 = F_62 ( V_86 ) ;
struct V_4 * V_5 = V_82 -> V_96 ;
struct V_168 V_169 ;
struct V_170 V_171 ;
int V_395 = V_394 + V_396 ;
int V_191 = 0 ;
if ( ( V_395 < V_397 ) ||
( V_395 > V_398 ) ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_59 , V_394 ) ;
F_20 ( & V_5 -> V_50 -> V_37 , L_60 ,
( V_397 - V_396 ) ,
( V_398 - V_396 ) ) ;
return - V_399 ;
}
memset ( & V_169 , 0 , sizeof( struct V_168 ) ) ;
V_169 . V_172 . V_121 = 0 ;
V_169 . V_172 . V_90 . V_173 = V_339 ;
V_169 . V_172 . V_90 . V_175 = V_82 -> V_88 . V_176 ;
V_169 . V_172 . V_90 . V_177 = V_394 ;
V_169 . V_367 = 100 ;
V_169 . V_178 = ( V_121 ) V_86 ;
V_169 . V_365 = F_210 ;
V_171 . V_179 = V_372 ;
V_191 = F_107 ( V_82 -> V_96 , & V_169 , V_171 ) ;
if ( V_191 < 0 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_61 ) ;
return - 1 ;
}
V_82 -> V_340 = V_394 ;
return 0 ;
}
static int F_220 ( struct V_85 * V_86 , struct V_400 * V_401 , int V_173 )
{
struct V_402 V_403 ;
struct V_82 * V_82 = F_62 ( V_86 ) ;
if ( F_221 ( & V_403 , V_401 -> V_404 , sizeof( V_403 ) ) )
return - V_405 ;
if ( V_403 . V_75 )
return - V_399 ;
switch ( V_403 . V_406 ) {
case V_407 :
case V_408 :
break;
default:
return - V_409 ;
}
switch ( V_403 . V_410 ) {
case V_411 :
break;
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
case V_423 :
case V_424 :
case V_425 :
V_403 . V_410 = V_412 ;
break;
default:
return - V_409 ;
}
if ( V_403 . V_410 == V_412 )
F_48 ( V_82 , V_286 ) ;
else
F_49 ( V_82 , V_286 ) ;
return F_222 ( V_401 -> V_404 , & V_403 , sizeof( V_403 ) ) ? - V_405 : 0 ;
}
static int F_223 ( struct V_85 * V_86 , struct V_400 * V_401 , int V_173 )
{
switch ( V_173 ) {
case V_426 :
return F_220 ( V_86 , V_401 , V_173 ) ;
default:
return - V_227 ;
}
}
static void F_224 ( struct V_4 * V_5 ,
T_1 V_63 ,
void * V_23 )
{
struct V_25 * V_26 ;
struct V_29 * V_30 ;
struct V_427 * V_264 ;
struct V_82 * V_82 ;
struct V_27 * V_28 = (struct V_27 * ) V_23 ;
V_26 = (struct V_25 * ) V_28 -> V_205 ;
V_82 = V_26 -> V_82 ;
V_30 = V_26 -> V_30 ;
V_5 = V_82 -> V_96 ;
V_264 = (struct V_427 * ) V_30 -> V_267 ;
if ( V_63 != V_428 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_62 ,
F_163 ( V_63 ) ) ;
V_264 -> V_429 = 0 ;
}
F_225 ( & V_264 -> V_429 , 1 ) ;
if ( F_226 ( ( F_130 ( V_28 ) -> V_430 | V_431 ) != 0 ) ) {
struct V_280 V_218 ;
V_121 V_219 = V_264 -> V_429 ;
F_77 ( V_82 , V_384 , V_82 -> V_86 ,
L_63 ,
V_28 , ( unsigned long long ) V_219 ) ;
V_218 . V_287 = F_173 ( V_219 + V_82 -> V_216 ) ;
F_227 ( V_28 , & V_218 ) ;
}
F_228 ( V_5 , V_30 ) ;
F_128 ( V_28 ) ;
}
static inline int F_229 ( struct V_4 * V_5 ,
struct V_432 * V_433 ,
struct V_25 * V_26 ,
int V_434 )
{
int V_318 ;
struct V_29 * V_30 ;
struct V_435 * V_436 ;
struct V_437 * V_438 ;
struct V_82 * V_82 ;
int V_439 ;
V_82 = V_26 -> V_82 ;
V_30 = F_230 ( V_5 , & V_433 -> V_173 ,
sizeof( struct V_427 ) ) ;
V_26 -> V_30 = V_30 ;
if ( ! V_30 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_64 ) ;
return V_440 ;
}
if ( V_433 -> V_24 == V_31 )
V_433 -> V_24 = V_34 ;
else if ( V_433 -> V_24 == V_32 )
V_433 -> V_24 = V_33 ;
V_30 -> V_441 = F_224 ;
V_30 -> V_35 = V_26 -> V_28 ;
V_30 -> V_383 = V_433 -> V_2 ;
V_436 = (struct V_435 * ) & V_30 -> V_173 . V_436 ;
V_438 = (struct V_437 * ) & V_30 -> V_173 . V_438 ;
V_439 = ! V_434 ;
V_318 = F_231 ( V_5 , V_30 -> V_383 , V_439 , & V_30 -> V_173 ,
V_30 , V_436 -> V_442 , V_433 -> V_24 ) ;
if ( V_318 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_65 ,
V_318 ) ;
F_228 ( V_5 , V_30 ) ;
} else {
F_77 ( V_82 , V_443 , V_82 -> V_86 , L_66 ) ;
}
return V_318 ;
}
static inline int F_232 ( struct V_27 * V_28 )
{
return ( V_28 -> V_288 == F_233 ( V_444 ) ) &&
( F_234 ( V_28 ) -> V_445 == 4 ) ;
}
static inline int F_235 ( struct V_27 * V_28 )
{
return V_28 -> V_288 == F_233 ( V_446 ) ;
}
static inline int F_236 ( struct V_27 * V_28 )
{
return ( F_234 ( V_28 ) -> V_447 & F_233 ( V_448 | V_449 ) ) ? 1 : 0 ;
}
static inline int F_237 ( struct V_27 * V_28 )
{
return ( V_28 -> V_288 == F_233 ( V_450 ) ) &&
( F_238 ( V_28 ) -> V_445 == 6 ) ;
}
static inline int F_239 ( struct V_27 * V_28 )
{
return ( F_238 ( V_28 ) -> V_451 != V_452 ) &&
( F_238 ( V_28 ) -> V_451 != V_453 ) ;
}
static inline int F_240 ( struct V_27 * V_28 )
{
return ( F_234 ( V_28 ) -> V_288 == V_452 ) ||
( F_234 ( V_28 ) -> V_288 == V_453 ) ;
}
static inline T_1 F_241 ( struct V_27 * V_28 )
{
T_1 V_454 ;
struct V_455 * V_455 = F_234 ( V_28 ) ;
V_454 = F_242 ( 0 , & V_455 -> V_288 , 1 ) ;
V_454 = F_242 ( V_454 , ( V_337 * ) & V_455 -> V_456 , 8 ) ;
V_454 = F_242 ( V_454 , F_243 ( V_28 ) , 4 ) ;
return V_454 ;
}
static inline T_1 F_244 ( struct V_27 * V_28 )
{
T_1 V_454 ;
struct V_457 * V_457 = F_238 ( V_28 ) ;
V_454 = F_242 ( 0 , & V_457 -> V_451 , 1 ) ;
V_454 = F_242 ( V_454 , ( V_337 * ) & V_457 -> V_456 , 32 ) ;
V_454 = F_242 ( V_454 , F_243 ( V_28 ) , 4 ) ;
return V_454 ;
}
static int F_245 ( struct V_27 * V_28 , struct V_85 * V_86 )
{
struct V_82 * V_82 ;
struct V_25 * V_26 ;
union V_458 V_459 ;
struct V_432 V_433 ;
struct V_4 * V_5 ;
struct V_381 * V_60 ;
int V_460 = 0 , V_63 = 0 ;
int V_461 = 0 , V_383 = 0 ;
int V_434 ;
T_1 V_454 = 0 ;
V_82 = F_62 ( V_86 ) ;
V_5 = V_82 -> V_96 ;
if ( F_51 ( V_86 ) ) {
V_460 = V_28 -> V_195 ;
V_461 = ( V_460 & ( V_82 -> V_88 . V_95 - 1 ) ) ;
V_383 = V_82 -> V_88 . V_94 [ V_461 ] ;
} else {
V_383 = V_82 -> V_19 ;
}
V_60 = & V_5 -> V_54 [ V_383 ] -> V_60 ;
if ( ! ( F_18 ( & V_82 -> V_84 ) & V_183 ) ||
( ! V_82 -> V_88 . V_89 . V_90 . V_63 ) ||
( V_28 -> V_36 <= 0 ) ) {
F_77 ( V_82 , V_462 , V_82 -> V_86 ,
L_67 ,
V_82 -> V_88 . V_89 . V_90 . V_63 ) ;
goto V_463;
}
V_26 = (struct V_25 * ) V_28 -> V_205 ;
V_26 -> V_82 = V_82 ;
V_26 -> V_28 = V_28 ;
V_26 -> V_30 = NULL ;
memset ( & V_433 , 0 , sizeof( struct V_432 ) ) ;
V_433 . V_23 = ( void * ) V_26 ;
V_433 . V_2 = V_383 ;
if ( F_51 ( V_86 ) ) {
if ( F_66 ( V_5 , V_433 . V_2 ) ) {
F_77 ( V_82 , V_462 , V_82 -> V_86 , L_68 ,
V_433 . V_2 ) ;
V_60 -> V_464 ++ ;
return V_465 ;
}
} else {
if ( F_66 ( V_5 , V_82 -> V_19 ) ) {
V_60 -> V_464 ++ ;
F_77 ( V_82 , V_462 , V_82 -> V_86 , L_68 ,
V_433 . V_2 ) ;
return V_465 ;
}
}
V_433 . V_466 = V_28 -> V_36 ;
V_459 . V_121 = 0 ;
V_459 . V_90 . V_176 = V_82 -> V_88 . V_176 ;
if ( V_28 -> V_293 == V_467 ) {
if ( F_232 ( V_28 ) && ! F_236 ( V_28 ) && F_240 ( V_28 ) ) {
V_454 = F_241 ( V_28 ) ;
V_459 . V_90 . V_468 = sizeof( struct V_469 ) + 1 ;
if ( F_234 ( V_28 ) -> V_470 > 5 )
V_459 . V_90 . V_471 =
V_472 ;
} else if ( F_237 ( V_28 ) ) {
V_454 = F_244 ( V_28 ) ;
V_459 . V_90 . V_468 = sizeof( struct V_469 ) + 1 ;
if ( F_239 ( V_28 ) )
V_459 . V_90 . V_471 =
V_473 ;
} else if ( F_235 ( V_28 ) ) {
if ( F_246 ( V_28 ) -> V_474
== F_233 ( V_444 ) &&
! F_236 ( V_28 ) && F_240 ( V_28 ) ) {
V_454 = F_241 ( V_28 ) ;
V_459 . V_90 . V_468 =
sizeof( struct V_475 ) + 1 ;
if ( F_234 ( V_28 ) -> V_470 > 5 )
V_459 . V_90 . V_471 =
V_472 ;
} else if ( F_246 ( V_28 ) -> V_474
== F_233 ( V_450 ) ) {
V_454 = F_244 ( V_28 ) ;
V_459 . V_90 . V_468 =
sizeof( struct V_475 ) + 1 ;
if ( F_239 ( V_28 ) )
V_459 . V_90 . V_471 =
V_473 ;
}
}
}
if ( F_226 ( F_130 ( V_28 ) -> V_430 & V_476 ) ) {
F_130 ( V_28 ) -> V_430 |= V_431 ;
V_459 . V_90 . V_429 = 1 ;
}
if ( F_130 ( V_28 ) -> V_199 == 0 ) {
V_459 . V_90 . V_477 . V_466 = V_28 -> V_36 ;
F_247 ( & V_433 . V_173 , & V_459 , V_454 ) ;
V_433 . V_173 . V_196 = F_248 ( & V_5 -> V_50 -> V_37 ,
V_28 -> V_257 ,
V_28 -> V_36 ,
V_197 ) ;
if ( F_249 ( & V_5 -> V_50 -> V_37 , V_433 . V_173 . V_196 ) ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_69 ,
V_65 ) ;
return V_465 ;
}
V_26 -> V_196 = V_433 . V_173 . V_196 ;
V_433 . V_24 = V_31 ;
} else {
int V_18 , V_198 ;
struct V_202 * V_203 ;
struct V_102 * V_103 ;
F_132 ( & V_82 -> V_56 ) ;
V_103 = (struct V_102 * ) F_67 ( & V_82 -> V_104 ) ;
F_133 ( & V_82 -> V_56 ) ;
if ( ! V_103 ) {
F_77 ( V_82 , V_462 , V_82 -> V_86 ,
L_70 ) ;
goto V_463;
}
V_459 . V_90 . V_478 = 1 ;
V_459 . V_90 . V_477 . V_479 = ( F_130 ( V_28 ) -> V_199 + 1 ) ;
F_247 ( & V_433 . V_173 , & V_459 , V_454 ) ;
memset ( V_103 -> V_105 , 0 , V_103 -> V_109 ) ;
V_103 -> V_105 [ 0 ] . V_200 [ 0 ] = F_248 ( & V_5 -> V_50 -> V_37 ,
V_28 -> V_257 ,
( V_28 -> V_36 - V_28 -> V_201 ) ,
V_197 ) ;
if ( F_249 ( & V_5 -> V_50 -> V_37 , V_103 -> V_105 [ 0 ] . V_200 [ 0 ] ) ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_71 ,
V_65 ) ;
return V_465 ;
}
F_250 ( & V_103 -> V_105 [ 0 ] , ( V_28 -> V_36 - V_28 -> V_201 ) , 0 ) ;
V_198 = F_130 ( V_28 ) -> V_199 ;
V_18 = 1 ;
while ( V_198 -- ) {
V_203 = & F_130 ( V_28 ) -> V_198 [ V_18 - 1 ] ;
V_103 -> V_105 [ ( V_18 >> 2 ) ] . V_200 [ ( V_18 & 3 ) ] =
F_251 ( & V_5 -> V_50 -> V_37 ,
V_203 -> V_480 . V_368 ,
V_203 -> V_481 ,
V_203 -> V_204 ,
V_197 ) ;
F_250 ( & V_103 -> V_105 [ ( V_18 >> 2 ) ] , V_203 -> V_204 , ( V_18 & 3 ) ) ;
V_18 ++ ;
}
V_433 . V_173 . V_196 = F_248 ( & V_5 -> V_50 -> V_37 ,
V_103 -> V_105 , V_103 -> V_109 ,
V_197 ) ;
if ( F_249 ( & V_5 -> V_50 -> V_37 , V_433 . V_173 . V_196 ) ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_72 ,
V_65 ) ;
F_127 ( & V_5 -> V_50 -> V_37 , V_103 -> V_105 [ 0 ] . V_200 [ 0 ] ,
V_28 -> V_36 - V_28 -> V_201 ,
V_197 ) ;
return V_465 ;
}
V_26 -> V_196 = V_433 . V_173 . V_196 ;
V_26 -> V_103 = V_103 ;
V_433 . V_24 = V_32 ;
}
if ( F_130 ( V_28 ) -> V_482 ) {
struct V_483 * V_484 =
(struct V_483 * ) & V_433 . V_173 . V_484 ;
union V_485 * V_485 = (union V_485 * ) & V_433 . V_173 . V_486 [ 0 ] ;
V_484 -> V_36 = 1 ;
V_485 -> V_90 . V_482 = F_130 ( V_28 ) -> V_482 ;
V_485 -> V_90 . V_487 = F_130 ( V_28 ) -> V_487 ;
}
V_434 = V_28 -> V_434 ;
if ( F_226 ( V_459 . V_90 . V_429 ) )
V_63 = F_229 ( V_5 , & V_433 , V_26 , V_434 ) ;
else
V_63 = F_252 ( V_5 , & V_433 , V_434 ) ;
if ( V_63 == V_440 )
goto V_463;
F_77 ( V_82 , V_443 , V_82 -> V_86 , L_73 ) ;
if ( V_63 == V_488 )
F_64 ( V_82 -> V_86 , V_461 ) ;
V_86 -> V_489 = V_300 ;
V_60 -> V_384 ++ ;
V_60 -> V_386 += V_28 -> V_36 ;
return V_490 ;
V_463:
V_60 -> V_385 ++ ;
F_77 ( V_82 , V_462 , V_82 -> V_86 , L_74 ,
V_383 , V_60 -> V_385 ) ;
F_127 ( & V_5 -> V_50 -> V_37 , V_433 . V_173 . V_196 ,
V_433 . V_466 , V_197 ) ;
F_128 ( V_28 ) ;
return V_490 ;
}
static void F_253 ( struct V_85 * V_86 )
{
struct V_82 * V_82 ;
V_82 = F_62 ( V_86 ) ;
F_77 ( V_82 , V_462 , V_82 -> V_86 ,
L_75 ,
V_86 -> V_60 . V_385 ) ;
V_86 -> V_489 = V_300 ;
F_57 ( V_86 ) ;
}
int F_254 ( struct V_85 * V_86 , int V_173 )
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
V_169 . V_172 . V_90 . V_177 = V_491 | V_492 ;
V_169 . V_367 = 100 ;
V_169 . V_178 = ( V_121 ) V_86 ;
V_169 . V_365 = F_210 ;
V_171 . V_179 = V_180 ;
V_191 = F_107 ( V_82 -> V_96 , & V_169 , V_171 ) ;
if ( V_191 < 0 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_76 ,
V_191 ) ;
}
return V_191 ;
}
static T_9 F_255 ( struct V_85 * V_86 ,
T_9 V_493 )
{
struct V_82 * V_82 = F_256 ( V_86 ) ;
if ( ( V_493 & V_290 ) &&
! ( V_82 -> V_494 & V_290 ) )
V_493 &= ~ V_290 ;
if ( ( V_493 & V_495 ) &&
! ( V_82 -> V_494 & V_495 ) )
V_493 &= ~ V_495 ;
if ( ( V_493 & V_496 ) && ! ( V_82 -> V_494 & V_496 ) )
V_493 &= ~ V_496 ;
if ( ( V_493 & V_497 ) && ! ( V_82 -> V_494 & V_497 ) )
V_493 &= ~ V_497 ;
if ( ( V_493 & V_498 ) && ! ( V_82 -> V_494 & V_498 ) )
V_493 &= ~ V_498 ;
if ( ! ( V_493 & V_290 ) && ( V_86 -> V_289 & V_498 ) &&
( V_82 -> V_494 & V_498 ) )
V_493 &= ~ V_498 ;
return V_493 ;
}
static int F_257 ( struct V_85 * V_86 ,
T_9 V_289 )
{
struct V_82 * V_82 = F_256 ( V_86 ) ;
if ( ! ( ( V_86 -> V_289 ^ V_289 ) & V_498 ) )
return 0 ;
if ( ( V_289 & V_498 ) && ( V_82 -> V_494 & V_498 ) )
F_254 ( V_86 , V_342 ) ;
else if ( ! ( V_289 & V_498 ) &&
( V_82 -> V_494 & V_498 ) )
F_254 ( V_86 , V_343 ) ;
return 0 ;
}
static int T_10 F_258 ( void )
{
int V_18 ;
struct V_137 * V_138 ;
F_90 ( & V_145 ) ;
F_259 ( V_499 ) ;
if ( F_43 () )
return - V_399 ;
F_260 ( & V_145 , F_195 ( 1000 ) ) ;
for ( V_18 = 0 ; V_18 < V_156 ; V_18 ++ ) {
V_138 = & V_137 [ V_18 ] ;
if ( V_138 -> V_50 ) {
F_261 ( & V_138 -> V_143 ) ;
if ( ! V_138 -> V_157 ) {
F_20 ( & V_138 -> V_50 -> V_37 ,
L_77 ) ;
F_45 () ;
return - V_500 ;
}
}
}
for ( V_18 = 0 ; V_18 < V_156 ; V_18 ++ ) {
V_138 = & V_137 [ V_18 ] ;
if ( V_138 -> V_50 ) {
F_260 ( & V_138 -> V_144 ,
F_195 ( 30000 ) ) ;
if ( ! V_138 -> V_158 ) {
F_20 ( & V_138 -> V_50 -> V_37 ,
L_78 ) ;
F_45 () ;
return - V_500 ;
}
}
}
return 0 ;
}
static int F_262 ( struct V_501 * V_502 , void * V_23 )
{
struct V_4 * V_5 = (struct V_4 * ) V_23 ;
struct V_503 * V_504 = V_502 -> V_504 ;
int V_176 = 0 ;
union V_118 * V_119 ;
int V_18 ;
if ( ( V_504 -> V_505 [ 0 ] != sizeof( * V_119 ) ) ||
( V_504 -> V_276 . V_506 . V_176 > V_5 -> V_185 ) ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_79 ,
V_504 -> V_505 [ 0 ] ,
V_504 -> V_276 . V_506 . V_176 ) ;
goto V_507;
}
V_176 = V_504 -> V_276 . V_506 . V_176 ;
V_119 = (union V_118 * ) F_263 ( V_504 -> V_508 [ 0 ] ) ;
F_225 ( ( V_121 * ) V_119 , ( sizeof( union V_118 ) ) >> 3 ) ;
F_78 ( V_5 -> V_182 [ V_176 ] . V_86 , V_119 ) ;
V_507:
for ( V_18 = 0 ; V_18 < V_504 -> V_509 ; V_18 ++ )
F_128 ( V_504 -> V_508 [ V_18 ] ) ;
F_264 ( V_502 ) ;
return 0 ;
}
static int F_265 ( struct V_4 * V_313 )
{
struct V_82 * V_82 = NULL ;
struct V_85 * V_86 ;
V_337 V_510 [ 6 ] , V_18 , V_184 ;
struct V_29 * V_30 ;
struct V_265 * V_266 ;
struct V_263 * V_264 ;
struct V_511 * V_182 ;
int V_318 , V_512 , V_513 , V_2 ;
V_121 V_514 ;
int V_515 = F_266 () ;
union V_516 V_517 ;
unsigned int V_518 ;
unsigned int V_519 ;
T_1 V_520 , V_521 ;
F_267 ( V_313 , V_522 ,
V_523 ,
F_262 , V_313 ) ;
F_268 ( V_313 , V_31 ,
F_126 ) ;
F_268 ( V_313 , V_32 ,
F_129 ) ;
F_268 ( V_313 , V_33 ,
F_134 ) ;
for ( V_18 = 0 ; V_18 < V_313 -> V_185 ; V_18 ++ ) {
V_520 = sizeof( struct V_263 ) ;
V_521 = sizeof( struct V_265 ) ;
V_30 = (struct V_29 * )
F_269 ( V_313 , 0 ,
V_520 , V_521 ) ;
V_264 = (struct V_263 * ) V_30 -> V_267 ;
V_266 = (struct V_265 * ) V_30 -> V_268 ;
V_512 =
F_270 ( F_119 ( V_313 ) , V_18 ) ;
V_513 =
F_271 ( F_119 ( V_313 ) , V_18 ) ;
V_518 =
F_272 ( F_119 ( V_313 ) , V_18 ) ;
V_519 =
F_273 ( F_119 ( V_313 ) , V_18 ) ;
if ( V_512 > V_515 )
V_512 = V_515 ;
if ( V_513 > V_515 )
V_513 = V_515 ;
F_34 ( & V_313 -> V_50 -> V_37 ,
L_80 ,
V_18 , V_512 , V_513 ) ;
F_164 ( V_266 -> V_269 ) = 0 ;
V_266 -> V_142 = F_274 ( V_313 ) ;
F_275 ( & V_266 -> V_270 ) ;
V_517 . V_121 = 0 ;
V_517 . V_90 . V_512 = V_512 ;
V_517 . V_90 . V_513 = V_513 ;
V_517 . V_90 . V_518 = V_518 ;
V_517 . V_90 . V_519 = V_519 ;
F_276 ( V_313 , V_30 , V_522 ,
V_524 , V_18 ,
V_517 . V_121 , 0 ) ;
V_30 -> V_441 = F_161 ;
V_30 -> V_35 = V_30 ;
V_30 -> V_367 = 1000 ;
V_318 = F_277 ( V_313 , V_30 ) ;
if ( V_318 ) {
F_20 ( & V_313 -> V_50 -> V_37 ,
L_81 ,
V_318 ) ;
goto V_525;
}
F_278 ( & V_266 -> V_270 , & V_266 -> V_269 ) ;
V_318 = V_264 -> V_63 ;
if ( V_318 ) {
F_20 ( & V_313 -> V_50 -> V_37 , L_82 ) ;
goto V_525;
}
F_225 ( ( V_121 * ) ( & V_264 -> V_526 ) ,
( sizeof( struct V_527 ) ) >> 3 ) ;
V_512 = F_279 ( V_264 -> V_526 . V_528 ) ;
V_513 = F_279 ( V_264 -> V_526 . V_529 ) ;
if ( ! ( V_512 ) || ! ( V_513 ) ) {
F_20 ( & V_313 -> V_50 -> V_37 ,
L_83 ,
V_264 -> V_526 . V_528 ,
V_264 -> V_526 . V_529 ) ;
goto V_525;
}
F_34 ( & V_313 -> V_50 -> V_37 ,
L_84 ,
V_18 , V_264 -> V_526 . V_528 , V_264 -> V_526 . V_529 ,
V_512 , V_513 ) ;
V_86 = F_280 ( V_530 , V_512 ) ;
if ( ! V_86 ) {
F_20 ( & V_313 -> V_50 -> V_37 , L_85 ) ;
goto V_525;
}
V_182 = & V_313 -> V_182 [ V_18 ] ;
V_182 -> V_86 = V_86 ;
if ( V_512 > 1 )
V_531 . V_532 = F_167 ;
V_86 -> V_533 = & V_531 ;
V_82 = F_62 ( V_86 ) ;
memset ( V_82 , 0 , sizeof( struct V_82 ) ) ;
V_82 -> V_88 . V_176 = V_264 -> V_526 . V_176 ;
V_82 -> V_176 = V_264 -> V_526 . V_176 ;
V_82 -> V_88 . V_186 = V_513 ;
V_82 -> V_88 . V_95 = V_512 ;
V_514 = V_264 -> V_526 . V_529 ;
for ( V_184 = 0 ; V_184 < V_513 ; V_184 ++ ) {
V_2 = F_281 ( V_514 ) ;
V_514 &= ( ~ ( 1UL << V_2 ) ) ;
V_82 -> V_88 . V_187 [ V_184 ] = V_2 ;
}
V_514 = V_264 -> V_526 . V_528 ;
for ( V_184 = 0 ; V_184 < V_512 ; V_184 ++ ) {
V_2 = F_281 ( V_514 ) ;
V_514 &= ( ~ ( 1UL << V_2 ) ) ;
V_82 -> V_88 . V_94 [ V_184 ] = V_2 ;
}
V_82 -> V_88 . V_374 = V_264 -> V_526 . V_88 . V_374 ;
V_82 -> V_88 . V_534 = V_264 -> V_526 . V_88 . V_534 ;
V_82 -> V_88 . V_89 . V_121 = V_264 -> V_526 . V_88 . V_89 . V_121 ;
V_82 -> V_535 = F_282 ( V_536 , V_537 ) ;
V_82 -> V_494 = V_538
| V_539 | V_540
| V_541 | V_290
| V_496 | V_497
| V_498 ;
F_283 ( V_86 , V_542 ) ;
V_86 -> V_289 = V_82 -> V_494 ;
V_86 -> V_543 = V_82 -> V_494 ;
V_86 -> V_544 = V_82 -> V_494 ;
V_82 -> V_96 = V_313 ;
V_82 -> V_545 = V_182 ;
V_82 -> V_86 = V_86 ;
F_149 ( & V_82 -> V_56 ) ;
F_34 ( & V_313 -> V_50 -> V_37 ,
L_86 , V_18 ,
V_82 -> V_88 . V_534 , F_163 ( V_82 -> V_88 . V_374 ) ) ;
F_225 ( & V_82 -> V_88 . V_374 , 1 ) ;
for ( V_184 = 0 ; V_184 < 6 ; V_184 ++ )
V_510 [ V_184 ] = * ( ( V_337 * ) ( ( ( V_337 * ) & V_82 -> V_88 . V_374 ) + 2 + V_184 ) ) ;
F_284 ( V_86 -> V_336 , V_510 ) ;
if ( F_185 ( V_313 , V_86 ) ) {
F_20 ( & V_313 -> V_50 -> V_37 , L_87 ) ;
goto V_525;
}
F_48 ( V_82 , V_546 ) ;
V_82 -> V_19 = V_82 -> V_88 . V_94 [ 0 ] ;
V_82 -> V_547 = V_82 -> V_88 . V_187 [ 0 ] ;
V_82 -> V_107 = F_285 ( V_313 , V_82 -> V_19 ) ;
V_82 -> V_548 = F_286 ( V_313 , V_82 -> V_547 ) ;
if ( F_71 ( V_82 ) ) {
F_20 ( & V_313 -> V_50 -> V_37 ,
L_88 ) ;
goto V_525;
}
F_287 ( V_86 ) ;
F_254 ( V_86 , V_342 ) ;
if ( ( V_536 != - 1 ) && ( V_536 & V_549 ) )
F_254 ( V_86 , V_344 ) ;
if ( F_288 ( V_86 ) ) {
F_20 ( & V_313 -> V_50 -> V_37 , L_89 ) ;
goto V_525;
}
F_34 ( & V_313 -> V_50 -> V_37 ,
L_90 ,
V_18 , V_510 [ 0 ] , V_510 [ 1 ] , V_510 [ 2 ] , V_510 [ 3 ] , V_510 [ 4 ] , V_510 [ 5 ] ) ;
F_80 ( V_86 ) ;
if ( V_82 -> V_88 . V_89 . V_90 . V_63 ) {
F_79 ( V_86 ) ;
F_61 ( V_86 ) ;
} else {
F_80 ( V_86 ) ;
}
F_48 ( V_82 , V_114 ) ;
F_34 ( & V_313 -> V_50 -> V_37 ,
L_91 , V_18 ) ;
F_228 ( V_313 , V_30 ) ;
}
return 0 ;
V_525:
F_228 ( V_313 , V_30 ) ;
while ( V_18 -- ) {
F_20 ( & V_313 -> V_50 -> V_37 ,
L_92 , V_18 ) ;
F_108 ( V_313 , V_18 ) ;
}
return - V_550 ;
}
static int F_289 ( struct V_4 * V_5 )
{
struct V_551 * V_552 ;
int V_318 = 0 ;
int V_553 = F_290 ( F_119 ( V_5 ) ) ;
F_34 ( & V_5 -> V_50 -> V_37 , L_93 ) ;
V_5 -> V_185 = V_553 ;
memset ( V_5 -> V_182 , 0 ,
sizeof( struct V_511 ) * V_553 ) ;
V_318 = F_265 ( V_5 ) ;
if ( V_318 ) {
F_20 ( & V_5 -> V_50 -> V_37 , L_94 ) ;
goto V_554;
}
F_152 ( V_5 ) ;
V_552 = & ( (struct V_4 * ) V_5 ) -> V_555 ;
V_552 -> V_556 = 1 ;
V_552 -> V_557 = V_558 ;
V_552 -> V_559 = V_560 ;
V_552 -> V_561 = V_562 ;
V_552 -> V_563 = V_564 ;
V_552 -> V_565 = V_566 ;
V_552 -> V_567 = V_568 ;
V_552 -> V_569 = V_570 ;
F_34 ( & V_5 -> V_50 -> V_37 , L_95 ) ;
return V_318 ;
V_554:
V_5 -> V_185 = 0 ;
return V_318 ;
}
static void F_291 ( struct V_321 * V_164 )
{
struct V_4 * V_5 ;
struct V_322 * V_323 = (struct V_322 * ) V_164 ;
V_5 = (struct V_4 * ) V_323 -> V_268 ;
if ( F_18 ( & V_5 -> V_63 ) == V_146 )
return;
if ( F_18 ( & V_5 -> V_63 ) != V_147 ) {
F_292 ( & V_5 -> V_163 . V_164 ,
V_571 ) ;
return;
}
F_30 ( & V_5 -> V_63 , V_146 ) ;
if ( V_5 -> V_148 && V_5 -> V_148 == V_188 ) {
F_34 ( & V_5 -> V_50 -> V_37 , L_96 ) ;
if ( F_289 ( V_5 ) )
F_20 ( & V_5 -> V_50 -> V_37 , L_97 ) ;
else
V_137 [ V_5 -> V_142 ] . V_158 = 1 ;
} else {
F_20 ( & V_5 -> V_50 -> V_37 ,
L_98 ,
V_5 -> V_148 ) ;
}
F_91 ( & V_137 [ V_5 -> V_142 ] . V_144 ) ;
}
static int F_92 ( struct V_4 * V_313 )
{
int V_184 , V_191 ;
struct V_6 * V_7 =
(struct V_6 * ) V_313 -> V_8 ;
F_30 ( & V_313 -> V_63 , V_166 ) ;
if ( F_120 ( V_313 ) )
return 1 ;
if ( F_114 ( V_313 ) ) {
F_20 ( & V_313 -> V_50 -> V_37 , L_99 ) ;
return 1 ;
}
F_30 ( & V_313 -> V_63 , V_165 ) ;
V_313 -> V_148 = V_149 ;
if ( V_313 -> V_71 . V_154 ( V_313 ) )
return 1 ;
if ( F_293 ( V_313 ) )
return 1 ;
F_267 ( V_313 , V_522 ,
V_572 ,
V_573 ,
V_313 ) ;
F_198 ( & V_313 -> V_163 . V_164 , F_291 ) ;
V_313 -> V_163 . V_268 = ( void * ) V_313 ;
F_292 ( & V_313 -> V_163 . V_164 ,
V_571 ) ;
F_30 ( & V_313 -> V_63 , V_162 ) ;
F_294 ( V_313 ) ;
if ( F_295 ( V_313 ) ) {
F_20 ( & V_313 -> V_50 -> V_37 ,
L_100 ) ;
for ( V_184 = 0 ; V_184 < V_313 -> V_574 ; V_184 ++ )
F_101 ( V_313 , V_184 ) ;
return 1 ;
}
F_30 ( & V_313 -> V_63 , V_161 ) ;
if ( F_296 ( V_313 ) ) {
F_20 ( & V_313 -> V_50 -> V_37 , L_101 ) ;
return 1 ;
}
F_30 ( & V_313 -> V_63 , V_160 ) ;
if ( F_297 ( V_313 ) ) {
F_20 ( & V_313 -> V_50 -> V_37 , L_102 ) ;
return 1 ;
}
F_30 ( & V_313 -> V_63 , V_159 ) ;
if ( F_298 ( V_313 ) ) {
F_20 ( & V_313 -> V_50 -> V_37 , L_103 ) ;
for ( V_184 = 0 ; V_184 < V_313 -> V_575 ; V_184 ++ )
F_98 ( V_313 , V_184 ) ;
}
F_30 ( & V_313 -> V_63 , V_155 ) ;
V_191 = V_313 -> V_71 . V_576 ( V_313 ) ;
if ( V_191 ) {
F_20 ( & V_313 -> V_50 -> V_37 ,
L_104 ) ;
return V_191 ;
}
F_34 ( & V_313 -> V_50 -> V_37 , L_105 ) ;
F_299 ( & V_7 -> V_14 , F_1 ,
( unsigned long ) V_313 ) ;
F_82 ( V_313 ) ;
V_313 -> V_71 . V_577 ( V_313 -> V_73 ) ;
V_313 -> V_71 . V_578 ( V_313 ) ;
F_30 ( & V_313 -> V_63 , V_152 ) ;
F_34 ( & V_313 -> V_50 -> V_37 , L_106 ) ;
if ( V_579 == 0 ) {
F_88 ( & V_313 -> V_50 -> V_37 ,
L_107 ) ;
}
F_6 ( V_49 * V_580 ) ;
V_191 = F_300 ( V_313 , & V_579 ) ;
if ( V_191 ) {
F_20 ( & V_313 -> V_50 -> V_37 ,
L_108 ,
V_191 ) ;
return 1 ;
}
if ( F_301 ( V_313 , 1000 ) != 0 ) {
F_20 ( & V_313 -> V_50 -> V_37 , L_109 ) ;
return 1 ;
}
F_34 ( & V_313 -> V_50 -> V_37 , L_110 ) ;
V_191 = F_302 ( V_313 ) ;
if ( V_191 ) {
F_20 ( & V_313 -> V_50 -> V_37 , L_111 ) ;
return 1 ;
}
V_191 = F_303 ( V_313 , 0 ) ;
if ( V_191 ) {
F_20 ( & V_313 -> V_50 -> V_37 , L_112 ) ;
return 1 ;
}
F_30 ( & V_313 -> V_63 , V_151 ) ;
F_34 ( & V_313 -> V_50 -> V_37 , L_113 ) ;
V_191 = F_153 ( V_313 ) ;
if ( V_191 ) {
F_20 ( & V_313 -> V_50 -> V_37 , L_114 ) ;
return 1 ;
}
V_137 [ V_313 -> V_142 ] . V_157 = 1 ;
F_91 ( & V_137 [ V_313 -> V_142 ] . V_143 ) ;
F_30 ( & V_313 -> V_63 , V_150 ) ;
for ( V_184 = 0 ; V_184 < V_313 -> V_575 ; V_184 ++ )
F_160 ( V_313 -> V_12 [ V_184 ] -> V_261 ,
V_313 -> V_12 [ V_184 ] -> V_262 ) ;
return 0 ;
}
static void T_11 F_304 ( void )
{
F_45 () ;
F_26 ( L_115 ) ;
}
