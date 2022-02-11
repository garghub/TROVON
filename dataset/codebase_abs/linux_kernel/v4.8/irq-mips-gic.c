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
T_3 F_25 ( void )
{
unsigned int V_22 , V_23 , V_24 ;
if ( V_3 )
return ( T_3 ) F_5 ( F_13 ( V_8 , V_25 ) ) ;
do {
V_22 = F_1 ( F_13 ( V_8 , V_26 ) ) ;
V_24 = F_1 ( F_13 ( V_8 , V_27 ) ) ;
V_23 = F_1 ( F_13 ( V_8 , V_26 ) ) ;
} while ( V_23 != V_22 );
return ( ( ( T_3 ) V_22 ) << 32 ) + V_24 ;
}
unsigned int F_26 ( void )
{
unsigned int V_28 , V_29 ;
V_29 = F_5 ( F_13 ( V_8 , V_30 ) ) ;
V_28 = 32 + 4 * ( ( V_29 & V_31 ) >>
V_32 ) ;
return V_28 ;
}
void F_27 ( T_3 V_33 )
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
void F_28 ( T_3 V_33 , int V_38 )
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
T_3 F_32 ( void )
{
unsigned int V_22 , V_24 ;
if ( V_3 )
return ( T_3 ) F_5 ( F_13 ( V_34 , V_35 ) ) ;
V_22 = F_1 ( F_13 ( V_34 , V_36 ) ) ;
V_24 = F_1 ( F_13 ( V_34 , V_37 ) ) ;
return ( ( ( T_3 ) V_22 ) << 32 ) + V_24 ;
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
V_7 = F_55 ( V_87 , V_93 ) ;
while ( V_7 != V_93 ) {
V_82 = F_56 ( V_69 ,
F_57 ( V_7 ) ) ;
if ( V_80 )
F_58 ( V_82 ) ;
else
F_59 ( V_82 ) ;
F_60 ( V_87 , V_7 , 1 ) ;
V_7 = F_55 ( V_87 , V_93 ) ;
}
}
static void F_61 ( struct V_63 * V_64 )
{
F_12 ( F_40 ( V_64 -> V_65 ) ) ;
}
static void F_62 ( struct V_63 * V_64 )
{
F_16 ( F_40 ( V_64 -> V_65 ) ) ;
}
static void F_63 ( struct V_63 * V_64 )
{
unsigned int V_59 = F_40 ( V_64 -> V_65 ) ;
F_10 ( F_13 ( V_8 , V_66 ) , F_64 ( V_59 ) ) ;
}
static int F_65 ( struct V_63 * V_64 , unsigned int type )
{
unsigned int V_59 = F_40 ( V_64 -> V_65 ) ;
unsigned long V_39 ;
bool V_95 ;
F_66 ( & V_96 , V_39 ) ;
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
F_67 ( V_64 , & V_109 ,
V_110 , NULL ) ;
else
F_67 ( V_64 , & V_111 ,
V_112 , NULL ) ;
F_68 ( & V_96 , V_39 ) ;
return 0 ;
}
static int F_69 ( struct V_63 * V_64 , const struct V_113 * V_113 ,
bool V_114 )
{
unsigned int V_59 = F_40 ( V_64 -> V_65 ) ;
T_5 V_115 = V_116 ;
unsigned long V_39 ;
int V_81 ;
F_70 ( & V_115 , V_113 , V_117 ) ;
if ( F_71 ( & V_115 ) )
return - V_118 ;
F_66 ( & V_96 , V_39 ) ;
F_22 ( V_59 , F_30 ( F_72 ( & V_115 ) ) ) ;
for ( V_81 = 0 ; V_81 < F_73 ( V_119 , V_120 ) ; V_81 ++ )
F_74 ( V_59 , V_90 [ V_81 ] . V_84 ) ;
F_75 ( V_59 , V_90 [ F_72 ( & V_115 ) ] . V_84 ) ;
F_76 ( F_77 ( V_64 ) , V_113 ) ;
F_68 ( & V_96 , V_39 ) ;
return V_121 ;
}
static void F_78 ( bool V_80 )
{
unsigned long V_87 , V_122 ;
unsigned int V_7 , V_82 ;
V_87 = F_1 ( F_13 ( V_34 , V_123 ) ) ;
V_122 = F_1 ( F_13 ( V_34 , V_124 ) ) ;
F_54 ( & V_87 , & V_87 , & V_122 , V_125 ) ;
V_7 = F_55 ( & V_87 , V_125 ) ;
while ( V_7 != V_125 ) {
V_82 = F_56 ( V_69 ,
F_45 ( V_7 ) ) ;
if ( V_80 )
F_58 ( V_82 ) ;
else
F_59 ( V_82 ) ;
F_60 ( & V_87 , V_7 , 1 ) ;
V_7 = F_55 ( & V_87 , V_125 ) ;
}
}
static void F_79 ( struct V_63 * V_64 )
{
int V_7 = F_80 ( V_64 -> V_65 ) ;
F_6 ( F_13 ( V_34 , V_126 ) , 1 << V_7 ) ;
}
static void F_81 ( struct V_63 * V_64 )
{
int V_7 = F_80 ( V_64 -> V_65 ) ;
F_6 ( F_13 ( V_34 , V_127 ) , 1 << V_7 ) ;
}
static void F_82 ( struct V_63 * V_64 )
{
int V_7 = F_80 ( V_64 -> V_65 ) ;
int V_81 ;
unsigned long V_39 ;
F_66 ( & V_96 , V_39 ) ;
for ( V_81 = 0 ; V_81 < V_119 ; V_81 ++ ) {
F_10 ( F_13 ( V_34 , V_40 ) ,
F_30 ( V_81 ) ) ;
F_6 ( F_13 ( V_41 , V_126 ) , 1 << V_7 ) ;
}
F_68 ( & V_96 , V_39 ) ;
}
static void F_83 ( struct V_63 * V_64 )
{
int V_7 = F_80 ( V_64 -> V_65 ) ;
int V_81 ;
unsigned long V_39 ;
F_66 ( & V_96 , V_39 ) ;
for ( V_81 = 0 ; V_81 < V_119 ; V_81 ++ ) {
F_10 ( F_13 ( V_34 , V_40 ) ,
F_30 ( V_81 ) ) ;
F_6 ( F_13 ( V_41 , V_127 ) , 1 << V_7 ) ;
}
F_68 ( & V_96 , V_39 ) ;
}
static void F_84 ( void )
{
F_78 ( false ) ;
F_49 ( false ) ;
}
static void F_85 ( struct V_128 * V_129 )
{
F_78 ( true ) ;
F_49 ( true ) ;
}
static void T_6 F_86 ( void )
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
static int F_87 ( struct V_132 * V_64 , unsigned int V_82 ,
T_4 V_133 )
{
int V_7 = F_80 ( V_133 ) ;
int V_134 = 0 ;
int V_81 ;
unsigned long V_39 ;
if ( ! F_36 ( V_7 ) )
return - V_135 ;
F_66 ( & V_96 , V_39 ) ;
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
F_88 ( L_1 , V_7 ) ;
V_134 = - V_118 ;
break;
}
}
F_68 ( & V_96 , V_39 ) ;
return V_134 ;
}
static int F_89 ( struct V_132 * V_64 , unsigned int V_82 ,
T_4 V_133 , unsigned int V_20 )
{
int V_7 = F_40 ( V_133 ) ;
unsigned long V_39 ;
int V_81 ;
F_66 ( & V_96 , V_39 ) ;
F_20 ( V_7 , V_136 ) ;
F_22 ( V_7 , F_30 ( V_20 ) ) ;
for ( V_81 = 0 ; V_81 < F_73 ( V_119 , V_120 ) ; V_81 ++ )
F_74 ( V_7 , V_90 [ V_81 ] . V_84 ) ;
F_75 ( V_7 , V_90 [ V_20 ] . V_84 ) ;
F_68 ( & V_96 , V_39 ) ;
return 0 ;
}
static int F_90 ( struct V_132 * V_64 , unsigned int V_82 ,
unsigned int V_65 )
{
struct V_147 * V_148 ;
int V_149 ;
if ( V_65 >= V_150 ) {
V_149 = F_91 ( V_64 , V_82 , V_65 ,
& V_111 ,
NULL ) ;
} else {
switch ( F_80 ( V_65 ) ) {
case V_50 :
case V_52 :
case V_54 :
V_148 = & V_151 ;
F_92 ( V_82 , V_152 ) ;
break;
default:
V_148 = & V_153 ;
F_92 ( V_82 , V_154 ) ;
F_93 ( V_82 ) ;
break;
}
V_149 = F_91 ( V_64 , V_82 , V_65 ,
V_148 , NULL ) ;
}
return V_149 ;
}
static int F_94 ( struct V_132 * V_64 , unsigned int V_82 ,
unsigned int V_155 , void * V_156 )
{
struct V_157 * V_158 = V_156 ;
T_4 V_65 , V_159 ;
int V_38 , V_134 , V_81 ;
if ( V_158 -> type == V_160 ) {
if ( ( V_158 -> V_65 >= V_150 ) &&
F_95 ( F_40 ( V_158 -> V_65 ) , V_161 ) )
return - V_162 ;
return F_90 ( V_64 , V_82 , V_158 -> V_65 ) ;
} else {
V_159 = F_55 ( V_161 , V_93 ) ;
if ( V_159 == V_93 ) {
return - V_163 ;
}
for ( V_81 = V_159 ; V_81 < V_155 ; V_81 ++ ) {
if ( ! F_95 ( V_81 , V_161 ) )
return - V_162 ;
}
F_60 ( V_161 , V_159 , V_155 ) ;
V_81 = 0 ;
F_96 (cpu, spec->ipimask) {
V_65 = F_57 ( V_159 + V_81 ) ;
V_134 = F_91 ( V_64 , V_82 + V_81 , V_65 ,
& V_111 ,
NULL ) ;
if ( V_134 )
goto error;
F_92 ( V_82 + V_81 , V_112 ) ;
V_134 = F_89 ( V_64 , V_82 + V_81 , V_65 , V_38 ) ;
if ( V_134 )
goto error;
V_81 ++ ;
}
V_158 -> V_65 = V_159 ;
}
return 0 ;
error:
F_97 ( V_161 , V_159 , V_155 ) ;
return V_134 ;
}
void F_98 ( struct V_132 * V_64 , unsigned int V_82 ,
unsigned int V_155 )
{
T_4 V_159 ;
struct V_63 * V_164 ;
V_164 = F_99 ( V_82 ) ;
if ( ! V_164 )
return;
V_159 = F_40 ( F_41 ( V_164 ) ) ;
F_97 ( V_161 , V_159 , V_155 ) ;
}
int F_100 ( struct V_132 * V_64 , struct V_165 * V_166 ,
enum V_167 V_168 )
{
return 0 ;
}
static int F_101 ( struct V_132 * V_64 , struct V_165 * V_169 ,
const T_1 * V_170 , unsigned int V_171 ,
T_4 * V_172 ,
unsigned int * V_173 )
{
if ( V_171 != 3 )
return - V_118 ;
if ( V_170 [ 0 ] == V_174 )
* V_172 = F_57 ( V_170 [ 1 ] ) ;
else if ( V_170 [ 0 ] == V_175 )
* V_172 = F_45 ( V_170 [ 1 ] ) ;
else
return - V_118 ;
* V_173 = V_170 [ 2 ] & V_97 ;
return 0 ;
}
static int F_102 ( struct V_132 * V_64 , unsigned int V_82 ,
unsigned int V_155 , void * V_156 )
{
struct V_176 * V_177 = V_156 ;
struct V_157 V_158 = {
. type = V_160 ,
} ;
int V_81 , V_134 ;
if ( V_177 -> V_178 [ 0 ] == V_174 )
V_158 . V_65 = F_57 ( V_177 -> V_178 [ 1 ] ) ;
else
V_158 . V_65 = F_45 ( V_177 -> V_178 [ 1 ] ) ;
V_134 = F_103 ( V_64 , V_82 , V_155 , & V_158 ) ;
if ( V_134 )
return V_134 ;
for ( V_81 = 0 ; V_81 < V_155 ; V_81 ++ ) {
V_134 = F_90 ( V_64 , V_82 + V_81 , V_158 . V_65 + V_81 ) ;
if ( V_134 )
goto error;
}
return 0 ;
error:
F_104 ( V_64 , V_82 , V_155 ) ;
return V_134 ;
}
void F_105 ( struct V_132 * V_64 , unsigned int V_82 ,
unsigned int V_155 )
{
return;
}
static void F_106 ( struct V_132 * V_179 ,
struct V_63 * V_64 )
{
if ( F_80 ( V_64 -> V_65 ) < V_125 )
F_87 ( V_179 , V_64 -> V_59 , V_64 -> V_65 ) ;
else
F_89 ( V_179 , V_64 -> V_59 , V_64 -> V_65 , 0 ) ;
}
static int F_107 ( struct V_132 * V_64 , struct V_165 * V_169 ,
const T_1 * V_170 , unsigned int V_171 ,
T_4 * V_172 ,
unsigned int * V_173 )
{
* V_172 = 0 ;
* V_173 = V_102 ;
return 0 ;
}
static int F_108 ( struct V_132 * V_64 , unsigned int V_82 ,
unsigned int V_155 , void * V_156 )
{
struct V_113 * V_180 = V_156 ;
struct V_157 V_158 = {
. type = V_181 ,
. V_180 = V_180
} ;
int V_134 , V_81 ;
V_134 = F_103 ( V_64 , V_82 , V_155 , & V_158 ) ;
if ( V_134 )
return V_134 ;
for ( V_81 = 0 ; V_81 < V_155 ; V_81 ++ ) {
V_134 = F_91 ( V_64 , V_82 + V_81 ,
F_57 ( V_158 . V_65 + V_81 ) ,
& V_109 ,
NULL ) ;
if ( V_134 )
goto error;
V_134 = F_109 ( V_82 + V_81 , V_102 ) ;
if ( V_134 )
goto error;
}
return 0 ;
error:
F_104 ( V_64 , V_82 , V_155 ) ;
return V_134 ;
}
void F_110 ( struct V_132 * V_64 , unsigned int V_82 ,
unsigned int V_155 )
{
F_104 ( V_64 , V_82 , V_155 ) ;
}
int F_111 ( struct V_132 * V_64 , struct V_165 * V_166 ,
enum V_167 V_168 )
{
bool V_182 ;
switch ( V_168 ) {
case V_183 :
V_182 = V_64 -> V_168 == V_168 ;
return ( ! V_166 || F_112 ( V_64 -> V_184 ) == V_166 ) && V_182 ;
break;
default:
return 0 ;
}
}
static void T_6 F_113 ( unsigned long V_185 ,
unsigned long V_186 ,
unsigned int V_187 , unsigned int V_188 ,
struct V_165 * V_166 )
{
unsigned int V_42 , V_38 ;
unsigned int V_189 [ 2 ] ;
V_76 = V_185 ;
V_2 = F_114 ( V_185 , V_186 ) ;
V_42 = F_5 ( F_13 ( V_8 , V_30 ) ) ;
V_93 = ( V_42 & V_190 ) >>
V_191 ;
V_93 = ( ( V_93 + 1 ) * 8 ) ;
V_119 = ( V_42 & V_192 ) >>
V_193 ;
V_119 = V_119 + 1 ;
if ( V_48 ) {
F_115 (cpu) {
F_10 ( F_13 ( V_34 , V_40 ) ,
F_30 ( V_38 ) ) ;
F_10 ( F_13 ( V_41 , V_49 ) ,
V_194 ) ;
}
V_136 = 0 ;
V_141 = V_136 ;
F_116 ( V_136 + V_61 ,
F_84 ) ;
} else {
V_136 = V_187 - V_195 ;
F_117 ( V_67 + V_187 ,
F_85 ) ;
if ( F_53 ( V_196 ) &&
F_36 ( V_50 ) ) {
V_141 = F_1 ( F_13 ( V_34 ,
V_142 ) ) &
V_197 ;
F_117 ( V_67 +
V_195 +
V_141 ,
F_85 ) ;
} else {
V_141 = V_136 ;
}
}
V_69 = F_118 ( V_166 , V_125 +
V_93 , V_188 ,
& V_198 , NULL ) ;
if ( ! V_69 )
F_119 ( L_2 ) ;
V_69 -> V_199 = L_3 ;
V_200 = F_120 ( V_69 , 0 ,
V_125 + V_93 ,
V_166 , & V_201 , NULL ) ;
if ( ! V_200 )
F_119 ( L_4 ) ;
V_200 -> V_199 = L_5 ;
V_202 = F_120 ( V_69 ,
V_203 ,
V_125 + V_93 ,
V_166 , & V_204 , NULL ) ;
if ( ! V_202 )
F_119 ( L_6 ) ;
V_202 -> V_199 = L_7 ;
V_202 -> V_168 = V_183 ;
if ( V_166 &&
! F_121 ( V_166 , L_8 , V_189 , 2 ) ) {
F_97 ( V_161 , V_189 [ 0 ] , V_189 [ 1 ] ) ;
} else {
F_97 ( V_161 ,
V_93 - 2 * V_119 ,
2 * V_119 ) ;
}
F_86 () ;
}
void T_6 F_122 ( unsigned long V_185 ,
unsigned long V_186 ,
unsigned int V_187 , unsigned int V_188 )
{
F_113 ( V_185 , V_186 , V_187 , V_188 , NULL ) ;
}
static int T_6 F_123 ( struct V_165 * V_166 ,
struct V_165 * V_205 )
{
struct V_72 V_206 ;
unsigned int V_187 , V_81 = 0 , V_207 = 0 ;
T_7 V_2 ;
T_8 V_208 ;
while ( ! F_124 ( V_166 , L_9 ,
V_81 ++ , & V_187 ) )
V_207 |= F_125 ( V_187 ) ;
for ( V_187 = 2 ; V_187 < 8 ; V_187 ++ ) {
if ( ! ( V_207 & F_125 ( V_187 ) ) )
break;
}
if ( V_187 == 8 ) {
F_88 ( L_10 ) ;
return - V_209 ;
}
if ( F_126 ( V_166 , 0 , & V_206 ) ) {
if ( F_127 () ) {
V_2 = F_128 () &
~ V_210 ;
V_208 = 0x20000 ;
} else {
F_88 ( L_11 ) ;
return - V_209 ;
}
} else {
V_2 = V_206 . V_75 ;
V_208 = F_129 ( & V_206 ) ;
}
if ( F_127 () )
F_130 ( V_2 | V_210 ) ;
V_74 = true ;
F_113 ( V_2 , V_208 , V_187 , 0 , V_166 ) ;
return 0 ;
}
