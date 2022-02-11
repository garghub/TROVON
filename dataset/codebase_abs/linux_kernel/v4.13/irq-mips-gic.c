static inline T_1 F_1 ( unsigned int V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline T_2 F_3 ( unsigned int V_1 )
{
return F_4 ( V_2 + V_1 ) ;
}
static inline unsigned long F_5 ( unsigned int V_1 )
{
if ( ! V_3 )
return F_1 ( V_1 ) ;
else
return F_3 ( V_1 ) ;
}
static inline void F_6 ( unsigned int V_1 , T_1 V_4 )
{
return F_7 ( V_4 , V_2 + V_1 ) ;
}
static inline void F_8 ( unsigned int V_1 , T_2 V_4 )
{
return F_9 ( V_4 , V_2 + V_1 ) ;
}
static inline void F_10 ( unsigned int V_1 , unsigned long V_4 )
{
if ( ! V_3 )
return F_6 ( V_1 , ( T_1 ) V_4 ) ;
else
return F_8 ( V_1 , ( T_2 ) V_4 ) ;
}
static inline void F_11 ( unsigned int V_1 , unsigned long V_5 ,
unsigned long V_4 )
{
unsigned long V_6 ;
V_6 = F_5 ( V_1 ) ;
V_6 &= ~ V_5 ;
V_6 |= V_4 ;
F_10 ( V_1 , V_6 ) ;
}
static inline void F_12 ( unsigned int V_7 )
{
F_10 ( F_13 ( V_8 , V_9 ) + F_14 ( V_7 ) ,
1ul << F_15 ( V_7 ) ) ;
}
static inline void F_16 ( unsigned int V_7 )
{
F_10 ( F_13 ( V_8 , V_10 ) + F_14 ( V_7 ) ,
1ul << F_15 ( V_7 ) ) ;
}
static inline void F_17 ( unsigned int V_7 , unsigned int V_11 )
{
F_11 ( F_13 ( V_8 , V_12 ) +
F_14 ( V_7 ) , 1ul << F_15 ( V_7 ) ,
( unsigned long ) V_11 << F_15 ( V_7 ) ) ;
}
static inline void F_18 ( unsigned int V_7 , unsigned int V_13 )
{
F_11 ( F_13 ( V_8 , V_14 ) +
F_14 ( V_7 ) , 1ul << F_15 ( V_7 ) ,
( unsigned long ) V_13 << F_15 ( V_7 ) ) ;
}
static inline void F_19 ( unsigned int V_7 , unsigned int V_15 )
{
F_11 ( F_13 ( V_8 , V_16 ) + F_14 ( V_7 ) ,
1ul << F_15 ( V_7 ) ,
( unsigned long ) V_15 << F_15 ( V_7 ) ) ;
}
static inline void F_20 ( unsigned int V_7 , unsigned int V_17 )
{
F_6 ( F_13 ( V_8 , V_18 ) +
F_21 ( V_7 ) , V_19 | V_17 ) ;
}
static inline void F_22 ( unsigned int V_7 , unsigned int V_20 )
{
F_10 ( F_13 ( V_8 , V_21 ) +
F_23 ( V_7 , V_20 ) ,
F_24 ( V_20 ) ) ;
}
T_2 T_3 F_25 ( void )
{
unsigned int V_22 , V_23 , V_24 ;
if ( V_3 )
return ( T_2 ) F_5 ( F_13 ( V_8 , V_25 ) ) ;
do {
V_22 = F_1 ( F_13 ( V_8 , V_26 ) ) ;
V_24 = F_1 ( F_13 ( V_8 , V_27 ) ) ;
V_23 = F_1 ( F_13 ( V_8 , V_26 ) ) ;
} while ( V_23 != V_22 );
return ( ( ( T_2 ) V_22 ) << 32 ) + V_24 ;
}
unsigned int F_26 ( void )
{
unsigned int V_28 , V_29 ;
V_29 = F_5 ( F_13 ( V_8 , V_30 ) ) ;
V_28 = 32 + 4 * ( ( V_29 & V_31 ) >>
V_32 ) ;
return V_28 ;
}
void T_3 F_27 ( T_2 V_33 )
{
if ( V_3 ) {
F_10 ( F_13 ( V_34 , V_35 ) , V_33 ) ;
} else {
F_6 ( F_13 ( V_34 , V_36 ) ,
( int ) ( V_33 >> 32 ) ) ;
F_6 ( F_13 ( V_34 , V_37 ) ,
( int ) ( V_33 & 0xffffffff ) ) ;
}
}
void T_3 F_28 ( T_2 V_33 , int V_38 )
{
unsigned long V_39 ;
F_29 ( V_39 ) ;
F_10 ( F_13 ( V_34 , V_40 ) , F_30 ( V_38 ) ) ;
if ( V_3 ) {
F_10 ( F_13 ( V_41 , V_35 ) , V_33 ) ;
} else {
F_6 ( F_13 ( V_41 , V_36 ) ,
( int ) ( V_33 >> 32 ) ) ;
F_6 ( F_13 ( V_41 , V_37 ) ,
( int ) ( V_33 & 0xffffffff ) ) ;
}
F_31 ( V_39 ) ;
}
T_2 F_32 ( void )
{
unsigned int V_22 , V_24 ;
if ( V_3 )
return ( T_2 ) F_5 ( F_13 ( V_34 , V_35 ) ) ;
V_22 = F_1 ( F_13 ( V_34 , V_36 ) ) ;
V_24 = F_1 ( F_13 ( V_34 , V_37 ) ) ;
return ( ( ( T_2 ) V_22 ) << 32 ) + V_24 ;
}
void F_33 ( void )
{
T_1 V_42 ;
V_42 = F_5 ( F_13 ( V_8 , V_30 ) ) ;
V_42 &= ~ ( 1 << V_43 ) ;
F_10 ( F_13 ( V_8 , V_30 ) , V_42 ) ;
}
void F_34 ( void )
{
T_1 V_42 ;
V_42 = F_5 ( F_13 ( V_8 , V_30 ) ) ;
V_42 |= 1 << V_43 ;
F_10 ( F_13 ( V_8 , V_30 ) , V_42 ) ;
}
unsigned F_35 ( void )
{
unsigned long V_44 ;
V_44 = F_5 ( F_13 ( V_34 , V_45 ) ) ;
return V_44 & V_46 ;
}
static bool F_36 ( int V_7 )
{
T_1 V_47 ;
if ( V_48 )
return true ;
V_47 = F_1 ( F_13 ( V_34 , V_49 ) ) ;
switch ( V_7 ) {
case V_50 :
return V_47 & V_51 ;
case V_52 :
return V_47 & V_53 ;
case V_54 :
return V_47 & V_55 ;
case V_56 :
case V_57 :
return V_47 & V_58 ;
default:
return true ;
}
}
static void F_37 ( int V_59 , int V_60 )
{
V_59 -= V_61 ;
F_10 ( F_13 ( V_34 , V_62 ) +
F_38 ( V_59 ) , V_60 ) ;
}
static void F_39 ( struct V_63 * V_64 , unsigned int V_38 )
{
T_4 V_65 = F_40 ( F_41 ( V_64 ) ) ;
F_10 ( F_13 ( V_8 , V_66 ) , F_42 ( V_65 ) ) ;
}
int F_43 ( void )
{
if ( ! F_36 ( V_50 ) )
return V_67 + V_68 ;
return F_44 ( V_69 ,
F_45 ( V_50 ) ) ;
}
int F_46 ( void )
{
if ( ! F_36 ( V_52 ) ) {
if ( V_70 < 0 )
return - 1 ;
return V_67 + V_70 ;
}
return F_44 ( V_69 ,
F_45 ( V_52 ) ) ;
}
int F_47 ( void )
{
if ( ! F_36 ( V_54 ) ) {
if ( V_71 < 0 )
return - 1 ;
return V_67 + V_71 ;
}
return F_44 ( V_69 ,
F_45 ( V_54 ) ) ;
}
int F_48 ( struct V_72 * V_73 )
{
if ( ! V_74 )
return - 1 ;
V_73 -> V_75 = V_76 + V_77 ;
V_73 -> V_78 = V_73 -> V_75 + ( V_79 - 1 ) ;
return 0 ;
}
static void F_49 ( bool V_80 )
{
unsigned int V_81 , V_7 , V_82 , V_83 = V_3 ? 8 : 4 ;
unsigned long * V_84 ;
unsigned long V_85 , V_86 ;
F_50 ( V_87 , V_88 ) ;
F_50 ( V_89 , V_88 ) ;
V_84 = V_90 [ F_51 () ] . V_84 ;
V_85 = F_13 ( V_8 , V_91 ) ;
V_86 = F_13 ( V_8 , V_92 ) ;
for ( V_81 = 0 ; V_81 < F_52 ( V_93 ) ; V_81 ++ ) {
V_87 [ V_81 ] = F_5 ( V_85 ) ;
V_89 [ V_81 ] = F_5 ( V_86 ) ;
V_85 += V_83 ;
V_86 += V_83 ;
if ( ! F_53 ( V_94 ) || V_3 )
continue;
V_87 [ V_81 ] |= ( T_2 ) F_5 ( V_85 ) << 32 ;
V_89 [ V_81 ] |= ( T_2 ) F_5 ( V_86 ) << 32 ;
V_85 += V_83 ;
V_86 += V_83 ;
}
F_54 ( V_87 , V_87 , V_89 , V_93 ) ;
F_54 ( V_87 , V_87 , V_84 , V_93 ) ;
F_55 (intr, pending, gic_shared_intrs) {
V_82 = F_56 ( V_69 ,
F_57 ( V_7 ) ) ;
if ( V_80 )
F_58 ( V_82 ) ;
else
F_59 ( V_82 ) ;
}
}
static void F_60 ( struct V_63 * V_64 )
{
F_12 ( F_40 ( V_64 -> V_65 ) ) ;
}
static void F_61 ( struct V_63 * V_64 )
{
F_16 ( F_40 ( V_64 -> V_65 ) ) ;
}
static void F_62 ( struct V_63 * V_64 )
{
unsigned int V_59 = F_40 ( V_64 -> V_65 ) ;
F_10 ( F_13 ( V_8 , V_66 ) , F_63 ( V_59 ) ) ;
}
static int F_64 ( struct V_63 * V_64 , unsigned int type )
{
unsigned int V_59 = F_40 ( V_64 -> V_65 ) ;
unsigned long V_39 ;
bool V_95 ;
F_65 ( & V_96 , V_39 ) ;
switch ( type & V_97 ) {
case V_98 :
F_17 ( V_59 , V_99 ) ;
F_18 ( V_59 , V_100 ) ;
F_19 ( V_59 , V_101 ) ;
V_95 = true ;
break;
case V_102 :
F_17 ( V_59 , V_103 ) ;
F_18 ( V_59 , V_100 ) ;
F_19 ( V_59 , V_101 ) ;
V_95 = true ;
break;
case V_104 :
F_18 ( V_59 , V_100 ) ;
F_19 ( V_59 , V_105 ) ;
V_95 = true ;
break;
case V_106 :
F_17 ( V_59 , V_99 ) ;
F_18 ( V_59 , V_107 ) ;
F_19 ( V_59 , V_101 ) ;
V_95 = false ;
break;
case V_108 :
default:
F_17 ( V_59 , V_103 ) ;
F_18 ( V_59 , V_107 ) ;
F_19 ( V_59 , V_101 ) ;
V_95 = false ;
break;
}
if ( V_95 )
F_66 ( V_64 , & V_109 ,
V_110 , NULL ) ;
else
F_66 ( V_64 , & V_111 ,
V_112 , NULL ) ;
F_67 ( & V_96 , V_39 ) ;
return 0 ;
}
static int F_68 ( struct V_63 * V_64 , const struct V_113 * V_113 ,
bool V_114 )
{
unsigned int V_59 = F_40 ( V_64 -> V_65 ) ;
T_5 V_115 = V_116 ;
unsigned long V_39 ;
int V_81 ;
F_69 ( & V_115 , V_113 , V_117 ) ;
if ( F_70 ( & V_115 ) )
return - V_118 ;
F_65 ( & V_96 , V_39 ) ;
F_22 ( V_59 , F_30 ( F_71 ( & V_115 ) ) ) ;
for ( V_81 = 0 ; V_81 < F_72 ( V_119 , V_120 ) ; V_81 ++ )
F_73 ( V_59 , V_90 [ V_81 ] . V_84 ) ;
F_74 ( V_59 , V_90 [ F_71 ( & V_115 ) ] . V_84 ) ;
F_75 ( F_76 ( V_64 ) , V_113 ) ;
F_67 ( & V_96 , V_39 ) ;
return V_121 ;
}
static void F_77 ( bool V_80 )
{
unsigned long V_87 , V_122 ;
unsigned int V_7 , V_82 ;
V_87 = F_1 ( F_13 ( V_34 , V_123 ) ) ;
V_122 = F_1 ( F_13 ( V_34 , V_124 ) ) ;
F_54 ( & V_87 , & V_87 , & V_122 , V_125 ) ;
F_55 (intr, &pending, GIC_NUM_LOCAL_INTRS) {
V_82 = F_56 ( V_69 ,
F_45 ( V_7 ) ) ;
if ( V_80 )
F_58 ( V_82 ) ;
else
F_59 ( V_82 ) ;
}
}
static void F_78 ( struct V_63 * V_64 )
{
int V_7 = F_79 ( V_64 -> V_65 ) ;
F_6 ( F_13 ( V_34 , V_126 ) , 1 << V_7 ) ;
}
static void F_80 ( struct V_63 * V_64 )
{
int V_7 = F_79 ( V_64 -> V_65 ) ;
F_6 ( F_13 ( V_34 , V_127 ) , 1 << V_7 ) ;
}
static void F_81 ( struct V_63 * V_64 )
{
int V_7 = F_79 ( V_64 -> V_65 ) ;
int V_81 ;
unsigned long V_39 ;
F_65 ( & V_96 , V_39 ) ;
for ( V_81 = 0 ; V_81 < V_119 ; V_81 ++ ) {
F_10 ( F_13 ( V_34 , V_40 ) ,
F_30 ( V_81 ) ) ;
F_6 ( F_13 ( V_41 , V_126 ) , 1 << V_7 ) ;
}
F_67 ( & V_96 , V_39 ) ;
}
static void F_82 ( struct V_63 * V_64 )
{
int V_7 = F_79 ( V_64 -> V_65 ) ;
int V_81 ;
unsigned long V_39 ;
F_65 ( & V_96 , V_39 ) ;
for ( V_81 = 0 ; V_81 < V_119 ; V_81 ++ ) {
F_10 ( F_13 ( V_34 , V_40 ) ,
F_30 ( V_81 ) ) ;
F_6 ( F_13 ( V_41 , V_127 ) , 1 << V_7 ) ;
}
F_67 ( & V_96 , V_39 ) ;
}
static void F_83 ( void )
{
F_77 ( false ) ;
F_49 ( false ) ;
}
static void F_84 ( struct V_128 * V_129 )
{
F_77 ( true ) ;
F_49 ( true ) ;
}
static void T_6 F_85 ( void )
{
unsigned int V_81 ;
V_130 = & F_37 ;
for ( V_81 = 0 ; V_81 < V_93 ; V_81 ++ ) {
F_17 ( V_81 , V_103 ) ;
F_18 ( V_81 , V_107 ) ;
F_12 ( V_81 ) ;
}
for ( V_81 = 0 ; V_81 < V_119 ; V_81 ++ ) {
unsigned int V_131 ;
F_10 ( F_13 ( V_34 , V_40 ) ,
F_30 ( V_81 ) ) ;
for ( V_131 = 0 ; V_131 < V_125 ; V_131 ++ ) {
if ( ! F_36 ( V_131 ) )
continue;
F_6 ( F_13 ( V_41 , V_126 ) , 1 << V_131 ) ;
}
}
}
static int F_86 ( struct V_132 * V_64 , unsigned int V_82 ,
T_4 V_133 )
{
int V_7 = F_79 ( V_133 ) ;
int V_134 = 0 ;
int V_81 ;
unsigned long V_39 ;
if ( ! F_36 ( V_7 ) )
return - V_135 ;
F_65 ( & V_96 , V_39 ) ;
for ( V_81 = 0 ; V_81 < V_119 ; V_81 ++ ) {
T_1 V_4 = V_19 | V_136 ;
F_10 ( F_13 ( V_34 , V_40 ) ,
F_30 ( V_81 ) ) ;
switch ( V_7 ) {
case V_137 :
F_6 ( F_13 ( V_41 , V_138 ) , V_4 ) ;
break;
case V_139 :
F_6 ( F_13 ( V_41 , V_140 ) ,
V_4 ) ;
break;
case V_50 :
V_4 = V_19 | V_141 ;
F_6 ( F_13 ( V_41 , V_142 ) ,
V_4 ) ;
break;
case V_52 :
F_6 ( F_13 ( V_41 , V_143 ) ,
V_4 ) ;
break;
case V_56 :
F_6 ( F_13 ( V_41 , V_144 ) ,
V_4 ) ;
break;
case V_57 :
F_6 ( F_13 ( V_41 , V_145 ) ,
V_4 ) ;
break;
case V_54 :
F_6 ( F_13 ( V_41 , V_146 ) , V_4 ) ;
break;
default:
F_87 ( L_1 , V_7 ) ;
V_134 = - V_118 ;
break;
}
}
F_67 ( & V_96 , V_39 ) ;
return V_134 ;
}
static int F_88 ( struct V_132 * V_64 , unsigned int V_82 ,
T_4 V_133 , unsigned int V_20 )
{
int V_7 = F_40 ( V_133 ) ;
unsigned long V_39 ;
int V_81 ;
F_65 ( & V_96 , V_39 ) ;
F_20 ( V_7 , V_136 ) ;
F_22 ( V_7 , F_30 ( V_20 ) ) ;
for ( V_81 = 0 ; V_81 < F_72 ( V_119 , V_120 ) ; V_81 ++ )
F_73 ( V_7 , V_90 [ V_81 ] . V_84 ) ;
F_74 ( V_7 , V_90 [ V_20 ] . V_84 ) ;
F_67 ( & V_96 , V_39 ) ;
return 0 ;
}
static int F_89 ( struct V_132 * V_64 , struct V_147 * V_148 ,
const T_1 * V_149 , unsigned int V_150 ,
T_4 * V_151 ,
unsigned int * V_152 )
{
if ( V_150 != 3 )
return - V_118 ;
if ( V_149 [ 0 ] == V_153 )
* V_151 = F_57 ( V_149 [ 1 ] ) ;
else if ( V_149 [ 0 ] == V_154 )
* V_151 = F_45 ( V_149 [ 1 ] ) ;
else
return - V_118 ;
* V_152 = V_149 [ 2 ] & V_97 ;
return 0 ;
}
static int F_90 ( struct V_132 * V_64 , unsigned int V_82 ,
T_4 V_65 )
{
int V_155 ;
if ( V_65 >= V_156 ) {
if ( F_91 ( F_40 ( V_65 ) , V_157 ) )
return - V_158 ;
V_155 = F_92 ( V_64 , V_82 , V_65 ,
& V_111 ,
NULL ) ;
if ( V_155 )
return V_155 ;
return F_88 ( V_64 , V_82 , V_65 , 0 ) ;
}
switch ( F_79 ( V_65 ) ) {
case V_50 :
case V_52 :
case V_54 :
V_155 = F_92 ( V_64 , V_82 , V_65 ,
& V_159 ,
NULL ) ;
if ( V_155 )
return V_155 ;
F_93 ( V_82 , V_160 ) ;
break;
default:
V_155 = F_92 ( V_64 , V_82 , V_65 ,
& V_161 ,
NULL ) ;
if ( V_155 )
return V_155 ;
F_93 ( V_82 , V_162 ) ;
F_94 ( V_82 ) ;
break;
}
return F_86 ( V_64 , V_82 , V_65 ) ;
}
static int F_95 ( struct V_132 * V_64 , unsigned int V_82 ,
unsigned int V_163 , void * V_164 )
{
struct V_165 * V_166 = V_164 ;
T_4 V_65 ;
if ( V_166 -> V_167 [ 0 ] == V_153 )
V_65 = F_57 ( V_166 -> V_167 [ 1 ] ) ;
else
V_65 = F_45 ( V_166 -> V_167 [ 1 ] ) ;
return F_90 ( V_64 , V_82 , V_65 ) ;
}
void F_96 ( struct V_132 * V_64 , unsigned int V_82 ,
unsigned int V_163 )
{
}
static int F_97 ( struct V_132 * V_64 , struct V_147 * V_148 ,
const T_1 * V_149 , unsigned int V_150 ,
T_4 * V_151 ,
unsigned int * V_152 )
{
* V_151 = 0 ;
* V_152 = V_102 ;
return 0 ;
}
static int F_98 ( struct V_132 * V_64 , unsigned int V_82 ,
unsigned int V_163 , void * V_164 )
{
struct V_113 * V_168 = V_164 ;
T_4 V_65 , V_169 ;
int V_38 , V_134 , V_81 ;
V_169 = F_99 ( V_170 , V_93 ) ;
if ( V_169 == V_93 )
return - V_171 ;
for ( V_81 = V_169 ; V_81 < V_163 ; V_81 ++ ) {
if ( ! F_91 ( V_81 , V_170 ) )
return - V_158 ;
}
F_100 ( V_170 , V_169 , V_163 ) ;
V_81 = 0 ;
F_101 (cpu, ipimask) {
V_65 = F_57 ( V_169 + V_81 ) ;
V_134 = F_92 ( V_64 , V_82 + V_81 , V_65 ,
& V_109 ,
NULL ) ;
if ( V_134 )
goto error;
V_134 = F_92 ( V_64 -> V_172 , V_82 + V_81 , V_65 ,
& V_109 ,
NULL ) ;
if ( V_134 )
goto error;
V_134 = F_102 ( V_82 + V_81 , V_102 ) ;
if ( V_134 )
goto error;
V_134 = F_88 ( V_64 , V_82 + V_81 , V_65 , V_38 ) ;
if ( V_134 )
goto error;
V_81 ++ ;
}
return 0 ;
error:
F_103 ( V_170 , V_169 , V_163 ) ;
return V_134 ;
}
void F_104 ( struct V_132 * V_64 , unsigned int V_82 ,
unsigned int V_163 )
{
T_4 V_169 ;
struct V_63 * V_173 ;
V_173 = F_105 ( V_82 ) ;
if ( ! V_173 )
return;
V_169 = F_40 ( F_41 ( V_173 ) ) ;
F_103 ( V_170 , V_169 , V_163 ) ;
}
int F_106 ( struct V_132 * V_64 , struct V_147 * V_174 ,
enum V_175 V_176 )
{
bool V_177 ;
switch ( V_176 ) {
case V_178 :
V_177 = V_64 -> V_176 == V_176 ;
return ( ! V_174 || F_107 ( V_64 -> V_179 ) == V_174 ) && V_177 ;
break;
default:
return 0 ;
}
}
static void T_6 F_108 ( unsigned long V_180 ,
unsigned long V_181 ,
unsigned int V_182 , unsigned int V_183 ,
struct V_147 * V_174 )
{
unsigned int V_42 , V_38 ;
unsigned int V_184 [ 2 ] ;
V_76 = V_180 ;
V_2 = F_109 ( V_180 , V_181 ) ;
V_42 = F_5 ( F_13 ( V_8 , V_30 ) ) ;
V_93 = ( V_42 & V_185 ) >>
V_186 ;
V_93 = ( ( V_93 + 1 ) * 8 ) ;
V_119 = ( V_42 & V_187 ) >>
V_188 ;
V_119 = V_119 + 1 ;
if ( V_48 ) {
F_110 (cpu) {
F_10 ( F_13 ( V_34 , V_40 ) ,
F_30 ( V_38 ) ) ;
F_10 ( F_13 ( V_41 , V_49 ) ,
V_189 ) ;
}
V_136 = 0 ;
V_141 = V_136 ;
F_111 ( V_136 + V_61 ,
F_83 ) ;
} else {
V_136 = V_182 - V_190 ;
F_112 ( V_67 + V_182 ,
F_84 ) ;
if ( F_53 ( V_191 ) &&
F_36 ( V_50 ) ) {
V_141 = F_1 ( F_13 ( V_34 ,
V_142 ) ) &
V_192 ;
F_112 ( V_67 +
V_190 +
V_141 ,
F_84 ) ;
} else {
V_141 = V_136 ;
}
}
V_69 = F_113 ( V_174 , V_125 +
V_93 , V_183 ,
& V_193 , NULL ) ;
if ( ! V_69 )
F_114 ( L_2 ) ;
V_194 = F_115 ( V_69 ,
V_195 ,
V_125 + V_93 ,
V_174 , & V_196 , NULL ) ;
if ( ! V_194 )
F_114 ( L_3 ) ;
F_116 ( V_194 , V_178 ) ;
if ( V_174 &&
! F_117 ( V_174 , L_4 , V_184 , 2 ) ) {
F_103 ( V_157 , V_184 [ 0 ] , V_184 [ 1 ] ) ;
} else {
F_103 ( V_157 ,
V_93 - 2 * V_119 ,
2 * V_119 ) ;
}
F_118 ( V_170 , V_157 , V_88 ) ;
F_85 () ;
}
void T_6 F_119 ( unsigned long V_180 ,
unsigned long V_181 ,
unsigned int V_182 , unsigned int V_183 )
{
F_108 ( V_180 , V_181 , V_182 , V_183 , NULL ) ;
}
static int T_6 F_120 ( struct V_147 * V_174 ,
struct V_147 * V_172 )
{
struct V_72 V_197 ;
unsigned int V_182 , V_81 = 0 , V_198 = 0 ;
T_7 V_2 ;
T_8 V_199 ;
while ( ! F_121 ( V_174 , L_5 ,
V_81 ++ , & V_182 ) )
V_198 |= F_122 ( V_182 ) ;
for ( V_182 = 2 ; V_182 < 8 ; V_182 ++ ) {
if ( ! ( V_198 & F_122 ( V_182 ) ) )
break;
}
if ( V_182 == 8 ) {
F_87 ( L_6 ) ;
return - V_200 ;
}
if ( F_123 ( V_174 , 0 , & V_197 ) ) {
if ( F_124 () ) {
V_2 = F_125 () &
~ V_201 ;
V_199 = 0x20000 ;
} else {
F_87 ( L_7 ) ;
return - V_200 ;
}
} else {
V_2 = V_197 . V_75 ;
V_199 = F_126 ( & V_197 ) ;
}
if ( F_124 () ) {
F_127 ( V_2 | V_201 ) ;
F_128 () ;
}
V_74 = true ;
F_108 ( V_2 , V_199 , V_182 , 0 , V_174 ) ;
return 0 ;
}
