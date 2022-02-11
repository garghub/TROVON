void F_1 ( struct V_1 * V_2 , int V_3 )
{
V_4 -> V_5 . V_1 = V_2 ;
V_4 -> V_5 . V_6 = V_2 -> V_7 . V_8 ;
}
void F_2 ( struct V_1 * V_2 )
{
}
void F_3 ( struct V_1 * V_2 , T_1 V_9 )
{
V_2 -> V_7 . V_10 . V_9 = V_9 ;
F_4 ( V_2 ) ;
}
void F_5 ( struct V_1 * V_2 , T_2 V_11 )
{
V_2 -> V_7 . V_11 = V_11 ;
}
void F_6 ( struct V_1 * V_2 )
{
int V_12 ;
F_7 ( L_1 , V_2 , V_2 -> V_13 ) ;
F_7 ( L_2 ,
V_2 -> V_7 . V_14 , V_2 -> V_7 . V_10 . V_9 , V_2 -> V_7 . V_15 ) ;
for ( V_12 = 0 ; V_12 < 16 ; ++ V_12 )
F_7 ( L_3 ,
V_12 , F_8 ( V_2 , V_12 ) ,
V_12 + 16 , F_8 ( V_2 , V_12 + 16 ) ) ;
F_7 ( L_4 ,
V_2 -> V_7 . V_16 , V_2 -> V_7 . V_17 ) ;
F_7 ( L_5 ,
V_2 -> V_7 . V_10 . V_18 , V_2 -> V_7 . V_10 . V_19 ) ;
F_7 ( L_6 ,
V_2 -> V_7 . V_10 . V_20 , V_2 -> V_7 . V_10 . V_21 ) ;
F_7 ( L_7 ,
V_2 -> V_7 . V_10 . V_22 , V_2 -> V_7 . V_10 . V_23 ) ;
F_7 ( L_8 ,
V_2 -> V_7 . V_24 , V_2 -> V_7 . V_25 , V_2 -> V_7 . V_10 . V_26 ) ;
F_7 ( L_9 , V_2 -> V_7 . V_10 . V_27 ) ;
F_7 ( L_10 ,
V_2 -> V_7 . V_28 , V_2 -> V_7 . V_29 ) ;
F_7 ( L_11 , V_2 -> V_7 . V_30 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_7 . V_30 ; ++ V_12 )
F_7 ( L_12 ,
V_2 -> V_7 . V_31 [ V_12 ] . V_32 , V_2 -> V_7 . V_31 [ V_12 ] . V_33 ) ;
F_7 ( L_13 ,
V_2 -> V_34 -> V_7 . V_35 , V_2 -> V_34 -> V_7 . V_36 ,
V_2 -> V_7 . V_37 ) ;
}
struct V_1 * F_9 ( struct V_34 * V_34 , int V_38 )
{
int V_12 ;
struct V_1 * V_39 , * V_40 = NULL ;
F_10 ( & V_34 -> V_41 ) ;
F_11 (r, v, kvm) {
if ( V_39 -> V_13 == V_38 ) {
V_40 = V_39 ;
break;
}
}
F_12 ( & V_34 -> V_41 ) ;
return V_40 ;
}
static void F_13 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
V_43 -> V_44 = 1 ;
V_43 -> V_45 = 1 ;
}
static unsigned long F_14 ( struct V_1 * V_2 ,
unsigned long V_46 ,
unsigned long V_47 , unsigned long V_43 )
{
struct V_34 * V_34 = V_2 -> V_34 ;
unsigned long V_48 , V_49 , V_50 ;
unsigned long V_51 ;
void * V_52 ;
struct V_1 * V_53 ;
V_53 = F_9 ( V_34 , V_47 ) ;
if ( ! V_53 )
return V_54 ;
V_46 >>= 63 - 18 ;
V_46 &= 7 ;
if ( V_46 == 0 || V_46 == 4 )
return V_54 ;
if ( V_46 < 4 ) {
if ( V_43 & 0x7f )
return V_54 ;
V_48 = V_43 >> V_34 -> V_7 . V_55 ;
V_51 = V_43 & ( V_34 -> V_7 . V_56 - 1 ) ;
if ( V_48 >= V_34 -> V_7 . V_57 )
return V_54 ;
if ( V_34 -> V_7 . V_58 [ V_48 ] . V_59 == 0 )
return V_54 ;
V_49 = V_34 -> V_7 . V_58 [ V_48 ] . V_59 << V_60 ;
V_49 |= V_51 ;
V_52 = F_15 ( V_49 ) ;
if ( V_46 <= 1 )
V_50 = * ( unsigned short * ) ( V_52 + 4 ) ;
else
V_50 = * ( unsigned int * ) ( V_52 + 4 ) ;
if ( V_51 + V_50 > V_34 -> V_7 . V_56 )
return V_54 ;
switch ( V_46 ) {
case 1 :
if ( V_50 < 640 )
return V_54 ;
V_53 -> V_7 . V_43 = V_52 ;
F_13 ( V_2 , V_52 ) ;
break;
case 2 :
if ( V_50 < 48 )
return V_54 ;
if ( ! V_53 -> V_7 . V_43 )
return V_61 ;
V_50 -= V_50 % 48 ;
V_53 -> V_7 . V_62 = V_52 ;
V_53 -> V_7 . V_63 = V_52 + V_50 ;
break;
case 3 :
if ( V_50 < 8 )
return V_54 ;
if ( ! V_53 -> V_7 . V_43 )
return V_61 ;
V_53 -> V_7 . V_64 = V_52 ;
V_50 = ( V_50 - 16 ) / 16 ;
V_53 -> V_7 . V_64 = V_52 ;
break;
}
} else {
switch ( V_46 ) {
case 5 :
if ( V_53 -> V_7 . V_64 || V_53 -> V_7 . V_62 )
return V_61 ;
V_53 -> V_7 . V_43 = NULL ;
break;
case 6 :
V_53 -> V_7 . V_62 = NULL ;
break;
case 7 :
V_53 -> V_7 . V_64 = NULL ;
break;
}
}
return V_65 ;
}
int F_16 ( struct V_1 * V_2 )
{
unsigned long V_66 = F_8 ( V_2 , 3 ) ;
unsigned long V_67 , V_40 = V_65 ;
struct V_1 * V_53 ;
switch ( V_66 ) {
case V_68 :
break;
case V_69 :
V_67 = F_8 ( V_2 , 4 ) ;
V_53 = F_9 ( V_2 -> V_34 , V_67 ) ;
if ( ! V_53 ) {
V_40 = V_54 ;
break;
}
V_53 -> V_7 . V_70 = 1 ;
F_17 () ;
if ( V_2 -> V_7 . V_71 ) {
if ( F_18 ( & V_2 -> V_72 ) ) {
F_19 ( & V_2 -> V_72 ) ;
V_2 -> V_73 . V_74 ++ ;
}
}
break;
case V_75 :
break;
case V_76 :
V_40 = F_14 ( V_2 , F_8 ( V_2 , 4 ) ,
F_8 ( V_2 , 5 ) ,
F_8 ( V_2 , 6 ) ) ;
break;
default:
return V_77 ;
}
F_20 ( V_2 , 3 , V_40 ) ;
V_2 -> V_7 . V_78 = 0 ;
return V_79 ;
}
static int F_21 ( struct V_80 * V_81 , struct V_1 * V_2 ,
struct V_82 * V_83 )
{
int V_12 = V_77 ;
V_2 -> V_73 . V_84 ++ ;
V_81 -> V_85 = V_86 ;
V_81 -> V_87 = 1 ;
switch ( V_2 -> V_7 . V_15 ) {
case V_88 :
V_2 -> V_73 . V_89 ++ ;
V_12 = V_79 ;
break;
case V_90 :
V_2 -> V_73 . V_91 ++ ;
V_12 = V_79 ;
break;
case V_92 :
V_12 = V_79 ;
break;
case V_93 :
{
T_3 V_46 ;
V_46 = V_2 -> V_7 . V_10 . V_9 & 0x1f0000ull ;
F_22 ( V_2 , V_46 ) ;
V_12 = V_79 ;
break;
}
case V_94 :
{
int V_95 ;
if ( V_2 -> V_7 . V_10 . V_9 & V_96 ) {
F_23 ( V_2 , V_94 ) ;
V_12 = V_79 ;
break;
}
V_81 -> V_97 . V_98 = F_8 ( V_2 , 3 ) ;
for ( V_95 = 0 ; V_95 < 9 ; ++ V_95 )
V_81 -> V_97 . args [ V_95 ] = F_8 ( V_2 , 4 + V_95 ) ;
V_81 -> V_85 = V_99 ;
V_2 -> V_7 . V_78 = 1 ;
V_12 = V_77 ;
break;
}
case V_100 :
V_2 -> V_7 . V_10 . V_26 = V_2 -> V_7 . V_29 ;
V_2 -> V_7 . V_10 . V_27 = V_2 -> V_7 . V_28 ;
F_24 ( V_2 , V_101 , 0 ) ;
V_12 = V_79 ;
break;
case V_102 :
F_24 ( V_2 , V_103 ,
0x08000000 ) ;
V_12 = V_79 ;
break;
case V_104 :
F_22 ( V_2 , 0x80000 ) ;
V_12 = V_79 ;
break;
default:
F_6 ( V_2 ) ;
F_25 ( V_105 L_14 ,
V_2 -> V_7 . V_15 , F_26 ( V_2 ) ,
V_2 -> V_7 . V_10 . V_9 ) ;
V_12 = V_77 ;
F_27 () ;
break;
}
return V_12 ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
int V_95 ;
V_107 -> V_11 = V_2 -> V_7 . V_11 ;
memset ( V_107 , 0 , sizeof( struct V_106 ) ) ;
for ( V_95 = 0 ; V_95 < V_2 -> V_7 . V_30 ; V_95 ++ ) {
V_107 -> V_108 . V_109 . V_110 . V_31 [ V_95 ] . V_111 = V_2 -> V_7 . V_31 [ V_95 ] . V_32 ;
V_107 -> V_108 . V_109 . V_110 . V_31 [ V_95 ] . V_112 = V_2 -> V_7 . V_31 [ V_95 ] . V_33 ;
}
return 0 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
int V_95 , V_113 ;
F_5 ( V_2 , V_107 -> V_11 ) ;
V_113 = 0 ;
for ( V_95 = 0 ; V_95 < V_2 -> V_7 . V_114 ; V_95 ++ ) {
if ( V_107 -> V_108 . V_109 . V_110 . V_31 [ V_95 ] . V_111 & V_115 ) {
V_2 -> V_7 . V_31 [ V_113 ] . V_32 = V_107 -> V_108 . V_109 . V_110 . V_31 [ V_95 ] . V_111 ;
V_2 -> V_7 . V_31 [ V_113 ] . V_33 = V_107 -> V_108 . V_109 . V_110 . V_31 [ V_95 ] . V_112 ;
++ V_113 ;
}
}
V_2 -> V_7 . V_30 = V_113 ;
return 0 ;
}
int F_30 ( void )
{
if ( F_31 ( V_116 ) )
return 0 ;
return - V_117 ;
}
struct V_1 * F_32 ( struct V_34 * V_34 , unsigned int V_38 )
{
struct V_1 * V_2 ;
int V_118 = - V_119 ;
int V_120 ;
struct V_121 * V_8 ;
V_120 = V_38 / V_122 ;
if ( V_120 >= V_123 )
goto V_124;
V_118 = - V_125 ;
V_2 = F_33 ( sizeof( struct V_1 ) , V_126 ) ;
if ( ! V_2 )
goto V_124;
V_118 = F_34 ( V_2 , V_34 , V_38 ) ;
if ( V_118 )
goto V_127;
V_2 -> V_7 . V_128 = & V_2 -> V_7 . V_10 ;
V_2 -> V_7 . V_129 = - 1 ;
V_2 -> V_7 . V_130 [ 0 ] = V_131 ;
V_2 -> V_7 . V_132 = V_133 ;
V_2 -> V_7 . V_11 = F_35 ( V_134 ) ;
F_5 ( V_2 , V_2 -> V_7 . V_11 ) ;
F_36 ( V_2 ) ;
V_2 -> V_7 . V_135 = V_136 ;
F_37 ( & V_2 -> V_7 . V_137 ) ;
F_10 ( & V_34 -> V_41 ) ;
V_8 = V_34 -> V_7 . V_138 [ V_120 ] ;
if ( ! V_8 ) {
V_8 = F_33 ( sizeof( struct V_121 ) , V_126 ) ;
if ( V_8 ) {
F_38 ( & V_8 -> V_139 ) ;
F_39 ( & V_8 -> V_41 ) ;
F_37 ( & V_8 -> V_72 ) ;
}
V_34 -> V_7 . V_138 [ V_120 ] = V_8 ;
}
F_12 ( & V_34 -> V_41 ) ;
if ( ! V_8 )
goto V_127;
F_40 ( & V_8 -> V_41 ) ;
++ V_8 -> V_140 ;
F_41 ( & V_8 -> V_41 ) ;
V_2 -> V_7 . V_8 = V_8 ;
V_2 -> V_7 . V_141 = V_142 ;
F_42 ( V_2 ) ;
return V_2 ;
V_127:
F_43 ( V_2 ) ;
V_124:
return F_44 ( V_118 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
F_46 ( V_2 ) ;
F_43 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
unsigned long V_143 , V_144 ;
V_144 = F_48 () ;
if ( V_144 > V_2 -> V_7 . V_145 ) {
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
return;
}
V_143 = ( V_2 -> V_7 . V_145 - V_144 ) * V_146
/ V_147 ;
F_51 ( & V_2 -> V_7 . V_148 , F_52 ( 0 , V_143 ) ,
V_149 ) ;
V_2 -> V_7 . V_150 = 1 ;
}
static void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_7 . V_71 = 0 ;
if ( V_2 -> V_7 . V_150 ) {
F_53 ( & V_2 -> V_7 . V_148 ) ;
V_2 -> V_7 . V_150 = 0 ;
}
}
static void F_54 ( struct V_121 * V_151 ,
struct V_1 * V_2 )
{
struct V_1 * V_39 ;
if ( V_2 -> V_7 . V_135 != V_152 )
return;
V_2 -> V_7 . V_135 = V_153 ;
-- V_151 -> V_154 ;
++ V_151 -> V_155 ;
V_39 = V_2 ;
F_55 ( V_39 , & V_151 -> V_139 , V_7 . V_156 )
-- V_39 -> V_7 . V_157 ;
F_56 ( & V_2 -> V_7 . V_156 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_158 * V_159 ;
struct V_121 * V_151 = V_2 -> V_7 . V_8 ;
if ( V_2 -> V_7 . V_150 ) {
F_53 ( & V_2 -> V_7 . V_148 ) ;
V_2 -> V_7 . V_150 = 0 ;
}
V_3 = V_151 -> V_160 + V_2 -> V_7 . V_157 ;
V_159 = & V_161 [ V_3 ] ;
V_159 -> V_5 . V_1 = V_2 ;
V_159 -> V_5 . V_6 = V_151 ;
V_159 -> V_5 . V_162 = 0 ;
V_2 -> V_3 = V_151 -> V_160 ;
F_58 () ;
#if F_59 ( V_163 ) && F_59 ( V_164 )
if ( V_2 -> V_7 . V_157 ) {
V_159 -> V_165 = 0x80 ;
F_60 () ;
F_61 ( V_3 ) ;
++ V_151 -> V_166 ;
}
#endif
}
static void F_62 ( struct V_121 * V_151 )
{
int V_95 ;
F_63 () ;
V_95 = 0 ;
while ( V_151 -> V_167 < V_151 -> V_166 ) {
if ( ++ V_95 >= 1000000 ) {
F_7 ( L_15 ,
V_151 -> V_167 , V_151 -> V_166 ) ;
break;
}
F_64 () ;
}
F_65 () ;
}
static int F_66 ( void )
{
int V_3 = F_67 () ;
int V_168 = F_68 ( V_3 ) ;
if ( V_168 )
return 0 ;
while ( ++ V_168 < V_122 )
if ( F_69 ( V_3 + V_168 ) )
return 0 ;
return 1 ;
}
static int F_70 ( struct V_121 * V_151 )
{
struct V_1 * V_2 , * V_169 , * V_170 ;
long V_40 ;
T_1 V_144 ;
int V_157 ;
F_71 (vcpu, &vc->runnable_threads, arch.run_list)
if ( F_72 ( V_2 -> V_7 . V_171 ) )
return 0 ;
if ( V_122 > 1 && ! F_66 () ) {
F_71 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_7 . V_40 = - V_172 ;
goto V_124;
}
V_157 = 0 ;
V_169 = NULL ;
F_71 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( ! V_2 -> V_7 . V_71 ) {
if ( ! V_157 )
V_169 = V_2 ;
V_2 -> V_7 . V_157 = V_157 ++ ;
}
}
if ( ! V_169 )
return 0 ;
F_71 (vcpu, &vc->runnable_threads, arch.run_list)
if ( V_2 -> V_7 . V_71 )
V_2 -> V_7 . V_157 = V_157 ++ ;
V_151 -> V_166 = 0 ;
V_151 -> V_167 = 0 ;
V_151 -> V_173 = 0 ;
V_151 -> V_174 = V_175 ;
V_151 -> V_176 = 0 ;
V_151 -> V_160 = F_67 () ;
V_151 -> V_177 = 0 ;
F_71 (vcpu, &vc->runnable_threads, arch.run_list)
F_57 ( V_2 ) ;
F_73 () ;
F_41 ( & V_151 -> V_41 ) ;
F_74 () ;
F_75 ( NULL , V_169 ) ;
F_40 ( & V_151 -> V_41 ) ;
F_71 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_3 = - 1 ;
if ( V_151 -> V_167 < V_151 -> V_166 )
F_62 ( V_151 ) ;
V_151 -> V_174 = V_178 ;
F_41 ( & V_151 -> V_41 ) ;
F_17 () ;
F_76 () ;
F_77 () ;
F_78 ( V_2 ) ;
V_144 = F_48 () ;
F_71 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_144 < V_2 -> V_7 . V_145 &&
F_79 ( V_2 ) )
F_80 ( V_2 ) ;
V_40 = V_79 ;
if ( V_2 -> V_7 . V_15 )
V_40 = F_21 ( V_2 -> V_7 . V_80 , V_2 ,
V_2 -> V_7 . V_171 ) ;
V_2 -> V_7 . V_40 = V_40 ;
V_2 -> V_7 . V_15 = 0 ;
if ( V_2 -> V_7 . V_71 ) {
if ( V_40 != V_79 )
F_4 ( V_2 ) ;
else
F_47 ( V_2 ) ;
}
}
F_40 ( & V_151 -> V_41 ) ;
V_124:
V_151 -> V_174 = V_179 ;
F_81 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( V_2 -> V_7 . V_40 != V_79 ) {
F_54 ( V_151 , V_2 ) ;
F_82 ( & V_2 -> V_7 . V_137 ) ;
}
}
return 1 ;
}
static void F_83 ( struct V_1 * V_2 , int V_180 )
{
F_84 ( V_181 ) ;
F_85 ( & V_2 -> V_7 . V_137 , & V_181 , V_180 ) ;
if ( V_2 -> V_7 . V_135 == V_152 )
F_86 () ;
F_87 ( & V_2 -> V_7 . V_137 , & V_181 ) ;
}
static void F_88 ( struct V_121 * V_151 )
{
F_84 ( V_181 ) ;
struct V_1 * V_39 ;
int V_182 = 1 ;
F_85 ( & V_151 -> V_72 , & V_181 , V_183 ) ;
V_151 -> V_174 = V_184 ;
F_41 ( & V_151 -> V_41 ) ;
F_71 (v, &vc->runnable_threads, arch.run_list) {
if ( ! V_39 -> V_7 . V_71 || V_39 -> V_7 . V_185 ) {
V_182 = 0 ;
break;
}
}
if ( V_182 )
F_86 () ;
F_87 ( & V_151 -> V_72 , & V_181 ) ;
F_40 ( & V_151 -> V_41 ) ;
V_151 -> V_174 = V_179 ;
}
static int F_89 ( struct V_80 * V_80 , struct V_1 * V_2 )
{
int V_186 ;
int V_187 ;
struct V_121 * V_151 ;
struct V_1 * V_39 , * V_188 ;
V_80 -> V_85 = 0 ;
V_2 -> V_7 . V_40 = V_79 ;
V_2 -> V_7 . V_15 = 0 ;
V_151 = V_2 -> V_7 . V_8 ;
F_40 ( & V_151 -> V_41 ) ;
V_2 -> V_7 . V_71 = 0 ;
V_2 -> V_7 . V_171 = V_189 ;
V_2 -> V_7 . V_80 = V_80 ;
V_187 = V_2 -> V_7 . V_135 ;
V_2 -> V_7 . V_135 = V_152 ;
F_90 ( & V_2 -> V_7 . V_156 , & V_151 -> V_139 ) ;
++ V_151 -> V_154 ;
if ( V_187 == V_136 ) {
if ( V_151 -> V_174 == V_175 &&
F_91 ( V_151 ) == 0 ) {
V_2 -> V_7 . V_157 = V_151 -> V_154 - 1 ;
F_57 ( V_2 ) ;
}
} else if ( V_187 == V_153 )
-- V_151 -> V_155 ;
while ( V_2 -> V_7 . V_135 == V_152 &&
! F_72 ( V_189 ) ) {
if ( V_151 -> V_155 || V_151 -> V_174 != V_179 ) {
F_41 ( & V_151 -> V_41 ) ;
F_83 ( V_2 , V_183 ) ;
F_40 ( & V_151 -> V_41 ) ;
continue;
}
V_186 = 0 ;
F_71 (v, &vc->runnable_threads, arch.run_list)
V_186 += V_39 -> V_7 . V_71 ;
if ( V_186 == V_151 -> V_154 )
F_88 ( V_151 ) ;
else
F_70 ( V_151 ) ;
F_81 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_50 ( V_39 ) ;
if ( F_72 ( V_39 -> V_7 . V_171 ) ) {
F_54 ( V_151 , V_39 ) ;
V_39 -> V_73 . V_190 ++ ;
V_39 -> V_7 . V_80 -> V_85 = V_191 ;
V_39 -> V_7 . V_40 = - V_192 ;
F_82 ( & V_39 -> V_7 . V_137 ) ;
}
}
}
if ( F_72 ( V_189 ) ) {
if ( V_151 -> V_174 == V_175 ||
V_151 -> V_174 == V_178 ) {
F_41 ( & V_151 -> V_41 ) ;
F_83 ( V_2 , V_193 ) ;
F_40 ( & V_151 -> V_41 ) ;
}
if ( V_2 -> V_7 . V_135 == V_152 ) {
F_54 ( V_151 , V_2 ) ;
V_2 -> V_73 . V_190 ++ ;
V_80 -> V_85 = V_191 ;
V_2 -> V_7 . V_40 = - V_192 ;
}
}
F_41 ( & V_151 -> V_41 ) ;
return V_2 -> V_7 . V_40 ;
}
int F_92 ( struct V_80 * V_81 , struct V_1 * V_2 )
{
int V_12 ;
if ( ! V_2 -> V_7 . V_194 ) {
V_81 -> V_85 = V_195 ;
return - V_119 ;
}
if ( F_72 ( V_189 ) ) {
V_81 -> V_85 = V_191 ;
return - V_192 ;
}
if ( ! V_2 -> V_34 -> V_7 . V_196 && F_31 ( V_197 ) )
return - V_198 ;
F_93 ( V_189 ) ;
F_94 ( V_189 ) ;
F_95 ( V_189 ) ;
V_2 -> V_7 . V_199 = & V_2 -> V_7 . V_8 -> V_72 ;
do {
V_12 = F_89 ( V_81 , V_2 ) ;
if ( V_81 -> V_85 == V_99 &&
! ( V_2 -> V_7 . V_10 . V_9 & V_96 ) ) {
V_12 = F_16 ( V_2 ) ;
F_50 ( V_2 ) ;
}
} while ( V_12 == V_79 );
return V_12 ;
}
static long F_96 ( unsigned long V_200 )
{
return F_97 ( ( V_200 >> V_201 )
* sizeof( T_1 ) , V_202 ) / V_202 ;
}
static void F_98 ( struct V_203 * V_204 )
{
struct V_34 * V_34 = V_204 -> V_34 ;
int V_95 ;
F_10 ( & V_34 -> V_41 ) ;
F_56 ( & V_204 -> V_205 ) ;
for ( V_95 = 0 ; V_95 < F_96 ( V_204 -> V_200 ) ; V_95 ++ )
F_99 ( V_204 -> V_206 [ V_95 ] ) ;
F_43 ( V_204 ) ;
F_12 ( & V_34 -> V_41 ) ;
F_100 ( V_34 ) ;
}
static int F_101 ( struct V_207 * V_208 , struct V_209 * V_210 )
{
struct V_203 * V_204 = V_208 -> V_211 -> V_212 ;
struct V_213 * V_213 ;
if ( V_210 -> V_214 >= F_96 ( V_204 -> V_200 ) )
return V_215 ;
V_213 = V_204 -> V_206 [ V_210 -> V_214 ] ;
F_102 ( V_213 ) ;
V_210 -> V_213 = V_213 ;
return 0 ;
}
static int F_103 ( struct V_216 * V_216 , struct V_207 * V_208 )
{
V_208 -> V_217 = & V_218 ;
return 0 ;
}
static int F_104 ( struct V_219 * V_219 , struct V_216 * V_220 )
{
struct V_203 * V_204 = V_220 -> V_212 ;
F_98 ( V_204 ) ;
return 0 ;
}
long F_105 ( struct V_34 * V_34 ,
struct V_221 * args )
{
struct V_203 * V_204 = NULL ;
long V_222 ;
int V_40 = - V_125 ;
int V_95 ;
F_71 (stt, &kvm->arch.spapr_tce_tables, list) {
if ( V_204 -> V_223 == args -> V_223 )
return - V_172 ;
}
V_222 = F_96 ( args -> V_200 ) ;
V_204 = F_33 ( sizeof( * V_204 ) + V_222 * sizeof( struct V_213 * ) ,
V_126 ) ;
if ( ! V_204 )
goto V_224;
V_204 -> V_223 = args -> V_223 ;
V_204 -> V_200 = args -> V_200 ;
V_204 -> V_34 = V_34 ;
for ( V_95 = 0 ; V_95 < V_222 ; V_95 ++ ) {
V_204 -> V_206 [ V_95 ] = F_106 ( V_126 | V_225 ) ;
if ( ! V_204 -> V_206 [ V_95 ] )
goto V_224;
}
F_107 ( V_34 ) ;
F_10 ( & V_34 -> V_41 ) ;
F_108 ( & V_204 -> V_205 , & V_34 -> V_7 . V_226 ) ;
F_12 ( & V_34 -> V_41 ) ;
return F_109 ( L_16 , & V_227 ,
V_204 , V_228 ) ;
V_224:
if ( V_204 ) {
for ( V_95 = 0 ; V_95 < V_222 ; V_95 ++ )
if ( V_204 -> V_206 [ V_95 ] )
F_99 ( V_204 -> V_206 [ V_95 ] ) ;
F_43 ( V_204 ) ;
}
return V_40 ;
}
static inline int F_110 ( unsigned long V_229 )
{
switch ( V_229 ) {
case 32ul << 20 :
if ( F_31 ( V_230 ) )
return 8 ;
return - 1 ;
case 64ul << 20 :
return 3 ;
case 128ul << 20 :
return 7 ;
case 256ul << 20 :
return 4 ;
case 1ul << 30 :
return 2 ;
case 16ul << 30 :
return 1 ;
case 256ul << 30 :
return 0 ;
default:
return - 1 ;
}
}
static int F_111 ( struct V_207 * V_208 , struct V_209 * V_210 )
{
struct V_231 * V_232 = V_208 -> V_211 -> V_212 ;
struct V_213 * V_213 ;
if ( V_210 -> V_214 >= V_232 -> V_222 )
return V_215 ;
V_213 = F_112 ( V_232 -> V_233 + V_210 -> V_214 ) ;
F_102 ( V_213 ) ;
V_210 -> V_213 = V_213 ;
return 0 ;
}
static int F_113 ( struct V_216 * V_216 , struct V_207 * V_208 )
{
V_208 -> V_234 |= V_235 ;
V_208 -> V_217 = & V_236 ;
return 0 ;
}
static int F_114 ( struct V_219 * V_219 , struct V_216 * V_220 )
{
struct V_231 * V_232 = V_220 -> V_212 ;
F_115 ( V_232 ) ;
return 0 ;
}
long F_116 ( struct V_34 * V_34 , struct V_237 * V_40 )
{
struct V_231 * V_232 ;
long V_238 ;
V_232 = F_117 () ;
if ( ! V_232 )
return - V_125 ;
V_238 = F_109 ( L_17 , & V_239 , V_232 , V_228 ) ;
if ( V_238 < 0 )
F_115 ( V_232 ) ;
V_40 -> V_229 = V_232 -> V_222 << V_60 ;
return V_238 ;
}
static struct V_213 * F_118 ( unsigned long V_240 )
{
struct V_213 * V_213 [ 1 ] ;
int V_222 ;
F_119 () ;
V_222 = F_120 ( V_240 , 1 , 1 , V_213 ) ;
if ( F_121 ( V_222 != 1 ) )
return 0 ;
return V_213 [ 0 ] ;
}
int F_122 ( struct V_34 * V_34 ,
struct V_241 * V_242 )
{
unsigned long V_243 , V_244 ;
unsigned long V_95 , V_222 , V_245 ;
unsigned long V_246 ;
struct V_247 * V_248 ;
unsigned long V_249 ;
struct V_231 * V_232 = NULL ;
struct V_213 * V_213 ;
V_244 = V_250 ;
V_243 = 1ul << V_244 ;
if ( ( V_242 -> V_251 & ( V_243 - 1 ) ) ||
( V_242 -> V_252 & ( V_243 - 1 ) ) ) {
F_7 ( L_18 ,
V_242 -> V_251 , V_242 -> V_252 ) ;
return - V_119 ;
}
V_222 = V_242 -> V_251 >> V_244 ;
V_245 = ( V_242 -> V_252 + V_242 -> V_251 ) >> V_244 ;
if ( V_245 > ( 1ul << ( V_253 - V_250 ) ) )
return - V_119 ;
if ( V_242 -> V_252 == 0 && V_34 -> V_7 . V_196 )
return - V_119 ;
if ( V_245 > V_34 -> V_7 . V_57 )
V_34 -> V_7 . V_57 = V_245 ;
if ( V_242 -> V_252 == 0 ) {
struct V_207 * V_208 ;
F_123 ( & V_189 -> V_254 -> V_255 ) ;
V_208 = F_124 ( V_189 -> V_254 , V_242 -> V_256 ) ;
if ( V_208 && V_208 -> V_211 &&
V_208 -> V_211 -> V_257 == & V_239 &&
V_242 -> V_256 == V_208 -> V_258 )
V_232 = V_208 -> V_211 -> V_212 ;
F_125 ( & V_189 -> V_254 -> V_255 ) ;
if ( ! V_232 && F_31 ( V_197 ) ) {
F_7 ( L_19 ) ;
return - V_119 ;
}
}
if ( V_232 ) {
unsigned long V_229 ;
unsigned long V_35 ;
long V_259 ;
V_229 = V_232 -> V_222 << V_60 ;
if ( V_229 > V_242 -> V_251 )
V_229 = V_242 -> V_251 ;
V_259 = F_110 ( V_229 ) ;
if ( V_259 < 0 ) {
F_7 ( L_20 , V_229 ) ;
return - V_119 ;
}
F_126 ( & V_232 -> V_260 ) ;
V_34 -> V_7 . V_196 = V_232 ;
V_34 -> V_7 . V_261 = V_229 >> V_244 ;
V_35 = V_34 -> V_7 . V_35 ;
if ( F_31 ( V_197 ) ) {
V_35 &= ~ ( ( 1ul << V_262 ) |
( 3ul << V_263 ) ) ;
V_35 |= ( ( V_259 >> 2 ) << V_262 ) |
( ( V_259 & 3 ) << V_263 ) ;
V_35 |= ( ( V_232 -> V_233 >> ( 26 - V_60 ) ) & 0xffff )
<< V_264 ;
} else {
V_35 &= ~ ( V_265 | V_266 ) ;
V_35 |= V_259 << V_267 ;
V_34 -> V_7 . V_268 = V_34 -> V_7 . V_196 -> V_233 << V_60 ;
}
V_34 -> V_7 . V_35 = V_35 ;
F_127 ( L_21 ,
V_232 -> V_233 << V_60 , V_229 , V_35 ) ;
}
V_246 = V_242 -> V_252 >> V_244 ;
V_248 = V_34 -> V_7 . V_58 + V_246 ;
for ( V_95 = 0 ; V_95 < V_222 ; ++ V_95 , ++ V_246 ) {
if ( V_232 && V_246 < V_34 -> V_7 . V_261 ) {
V_248 [ V_95 ] . V_59 = V_232 -> V_233 +
( V_246 << ( V_244 - V_60 ) ) ;
continue;
}
V_249 = V_242 -> V_256 + ( V_95 << V_244 ) ;
V_213 = F_118 ( V_249 ) ;
if ( ! V_213 ) {
F_7 ( L_22 , V_249 ) ;
goto V_118;
}
if ( ! F_128 ( V_213 ) ||
F_129 ( V_213 ) != ( V_250 - V_60 ) ) {
F_7 ( L_23 ,
V_249 , F_129 ( V_213 ) ) ;
goto V_118;
}
V_248 [ V_95 ] . V_59 = F_130 ( V_213 ) ;
}
return 0 ;
V_118:
return - V_119 ;
}
void F_131 ( struct V_34 * V_34 ,
struct V_241 * V_242 )
{
if ( V_242 -> V_252 == 0 && V_242 -> V_251 != 0 &&
! V_34 -> V_7 . V_196 )
F_132 ( V_34 , V_242 ) ;
}
int F_133 ( struct V_34 * V_34 )
{
long V_12 ;
unsigned long V_222 = 1ul << ( V_253 - V_250 ) ;
long V_118 = - V_125 ;
unsigned long V_35 ;
V_12 = F_134 ( V_34 ) ;
if ( V_12 )
return V_12 ;
F_38 ( & V_34 -> V_7 . V_226 ) ;
V_34 -> V_7 . V_58 = F_33 ( V_222 * sizeof( struct V_247 ) ,
V_126 ) ;
if ( ! V_34 -> V_7 . V_58 ) {
F_7 ( L_24 ,
V_222 * sizeof( struct V_247 ) ) ;
goto V_269;
}
V_34 -> V_7 . V_57 = 0 ;
V_34 -> V_7 . V_56 = 1ul << V_250 ;
V_34 -> V_7 . V_55 = V_250 ;
V_34 -> V_7 . V_196 = NULL ;
V_34 -> V_7 . V_261 = 0 ;
V_34 -> V_7 . V_270 = F_35 ( V_271 ) ;
if ( F_31 ( V_197 ) ) {
unsigned long V_272 = V_34 -> V_7 . V_272 ;
V_34 -> V_7 . V_273 = 0 ;
V_34 -> V_7 . V_274 = V_35 = F_35 ( V_275 ) ;
V_35 &= ~ ( ( 3 << V_276 ) | ( 0xful << V_277 ) ) ;
V_35 |= ( ( V_272 >> 4 ) << V_276 ) |
( ( V_272 & 0xf ) << V_277 ) ;
} else {
V_34 -> V_7 . V_273 = F_35 ( V_278 ) ;
V_34 -> V_7 . V_274 = V_35 = F_35 ( V_279 ) ;
V_35 &= V_280 | V_281 ;
V_35 |= ( 4UL << V_282 ) | V_283 |
V_265 | V_266 ;
}
V_34 -> V_7 . V_35 = V_35 ;
return 0 ;
V_269:
F_135 ( V_34 ) ;
return V_118 ;
}
void F_136 ( struct V_34 * V_34 )
{
struct V_247 * V_248 ;
unsigned long V_95 ;
if ( V_34 -> V_7 . V_58 ) {
V_248 = V_34 -> V_7 . V_58 ;
V_34 -> V_7 . V_58 = NULL ;
for ( V_95 = V_34 -> V_7 . V_261 ; V_95 < V_34 -> V_7 . V_57 ; ++ V_95 )
if ( V_248 [ V_95 ] . V_59 )
F_137 ( F_112 ( V_248 [ V_95 ] . V_59 ) ) ;
F_43 ( V_248 ) ;
}
if ( V_34 -> V_7 . V_196 ) {
F_115 ( V_34 -> V_7 . V_196 ) ;
V_34 -> V_7 . V_196 = NULL ;
}
F_135 ( V_34 ) ;
F_138 ( ! F_139 ( & V_34 -> V_7 . V_226 ) ) ;
}
void F_140 ( struct V_1 * V_2 , T_3 V_284 , T_3 V_285 )
{
}
int F_141 ( struct V_80 * V_81 , struct V_1 * V_2 ,
unsigned int V_286 , int * V_287 )
{
return V_288 ;
}
int F_142 ( struct V_1 * V_2 , int V_289 , int V_290 )
{
return V_288 ;
}
int F_143 ( struct V_1 * V_2 , int V_289 , int V_291 )
{
return V_288 ;
}
static int F_144 ( void )
{
int V_12 ;
V_12 = F_145 ( NULL , sizeof( struct V_1 ) , 0 , V_292 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_146 () ;
return V_12 ;
}
static void F_147 ( void )
{
F_148 () ;
}
