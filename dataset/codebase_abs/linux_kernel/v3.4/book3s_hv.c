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
unsigned long V_48 , V_49 ;
void * V_50 ;
struct V_1 * V_51 ;
int V_52 = V_53 ;
V_51 = F_9 ( V_34 , V_47 ) ;
if ( ! V_51 )
return V_53 ;
V_46 >>= 63 - 18 ;
V_46 &= 7 ;
if ( V_46 == 0 || V_46 == 4 )
return V_53 ;
if ( V_46 < 4 ) {
if ( V_43 & 0x7f )
return V_53 ;
if ( V_46 >= 2 && ! V_51 -> V_7 . V_43 )
return V_54 ;
V_50 = F_15 ( V_34 , V_43 , & V_49 ) ;
if ( V_50 == NULL )
return V_53 ;
if ( V_46 <= 1 )
V_48 = * ( unsigned short * ) ( V_50 + 4 ) ;
else
V_48 = * ( unsigned int * ) ( V_50 + 4 ) ;
if ( V_48 > V_49 )
goto V_55;
switch ( V_46 ) {
case 1 :
if ( V_48 < 640 )
goto V_55;
if ( V_51 -> V_7 . V_43 )
F_16 ( V_34 , V_2 -> V_7 . V_43 ) ;
V_51 -> V_7 . V_43 = V_50 ;
F_13 ( V_2 , V_50 ) ;
break;
case 2 :
if ( V_48 < 48 )
goto V_55;
V_48 -= V_48 % 48 ;
if ( V_51 -> V_7 . V_56 )
F_16 ( V_34 , V_2 -> V_7 . V_56 ) ;
V_51 -> V_7 . V_56 = V_50 ;
V_51 -> V_7 . V_57 = V_50 + V_48 ;
break;
case 3 :
if ( V_48 < 16 )
goto V_55;
if ( V_51 -> V_7 . V_58 )
F_16 ( V_34 , V_2 -> V_7 . V_58 ) ;
V_51 -> V_7 . V_58 = V_50 ;
break;
}
} else {
switch ( V_46 ) {
case 5 :
if ( V_51 -> V_7 . V_58 || V_51 -> V_7 . V_56 )
return V_54 ;
if ( ! V_51 -> V_7 . V_43 )
break;
F_16 ( V_34 , V_51 -> V_7 . V_43 ) ;
V_51 -> V_7 . V_43 = NULL ;
break;
case 6 :
if ( ! V_51 -> V_7 . V_56 )
break;
F_16 ( V_34 , V_51 -> V_7 . V_56 ) ;
V_51 -> V_7 . V_56 = NULL ;
break;
case 7 :
if ( ! V_51 -> V_7 . V_58 )
break;
F_16 ( V_34 , V_51 -> V_7 . V_58 ) ;
V_51 -> V_7 . V_58 = NULL ;
break;
}
}
return V_59 ;
V_55:
F_16 ( V_34 , V_50 ) ;
return V_52 ;
}
int F_17 ( struct V_1 * V_2 )
{
unsigned long V_60 = F_8 ( V_2 , 3 ) ;
unsigned long V_61 , V_40 = V_59 ;
struct V_1 * V_51 ;
switch ( V_60 ) {
case V_62 :
V_40 = F_18 ( V_2 , F_8 ( V_2 , 4 ) ,
F_8 ( V_2 , 5 ) ,
F_8 ( V_2 , 6 ) ,
F_8 ( V_2 , 7 ) ) ;
break;
case V_63 :
break;
case V_64 :
V_61 = F_8 ( V_2 , 4 ) ;
V_51 = F_9 ( V_2 -> V_34 , V_61 ) ;
if ( ! V_51 ) {
V_40 = V_53 ;
break;
}
V_51 -> V_7 . V_65 = 1 ;
F_19 () ;
if ( V_2 -> V_7 . V_66 ) {
if ( F_20 ( & V_2 -> V_67 ) ) {
F_21 ( & V_2 -> V_67 ) ;
V_2 -> V_68 . V_69 ++ ;
}
}
break;
case V_70 :
break;
case V_71 :
V_40 = F_14 ( V_2 , F_8 ( V_2 , 4 ) ,
F_8 ( V_2 , 5 ) ,
F_8 ( V_2 , 6 ) ) ;
break;
default:
return V_72 ;
}
F_22 ( V_2 , 3 , V_40 ) ;
V_2 -> V_7 . V_73 = 0 ;
return V_74 ;
}
static int F_23 ( struct V_75 * V_76 , struct V_1 * V_2 ,
struct V_77 * V_78 )
{
int V_12 = V_72 ;
V_2 -> V_68 . V_79 ++ ;
V_76 -> V_80 = V_81 ;
V_76 -> V_82 = 1 ;
switch ( V_2 -> V_7 . V_15 ) {
case V_83 :
V_2 -> V_68 . V_84 ++ ;
V_12 = V_74 ;
break;
case V_85 :
V_2 -> V_68 . V_86 ++ ;
V_12 = V_74 ;
break;
case V_87 :
V_12 = V_74 ;
break;
case V_88 :
{
T_3 V_46 ;
V_46 = V_2 -> V_7 . V_10 . V_9 & 0x1f0000ull ;
F_24 ( V_2 , V_46 ) ;
V_12 = V_74 ;
break;
}
case V_89 :
{
int V_90 ;
if ( V_2 -> V_7 . V_10 . V_9 & V_91 ) {
F_25 ( V_2 , V_89 ) ;
V_12 = V_74 ;
break;
}
V_76 -> V_92 . V_93 = F_8 ( V_2 , 3 ) ;
for ( V_90 = 0 ; V_90 < 9 ; ++ V_90 )
V_76 -> V_92 . args [ V_90 ] = F_8 ( V_2 , 4 + V_90 ) ;
V_76 -> V_80 = V_94 ;
V_2 -> V_7 . V_73 = 1 ;
V_12 = V_72 ;
break;
}
case V_95 :
V_12 = F_26 ( V_76 , V_2 ,
V_2 -> V_7 . V_28 , V_2 -> V_7 . V_29 ) ;
break;
case V_96 :
V_12 = F_26 ( V_76 , V_2 ,
F_27 ( V_2 ) , 0 ) ;
break;
case V_97 :
F_24 ( V_2 , 0x80000 ) ;
V_12 = V_74 ;
break;
default:
F_6 ( V_2 ) ;
F_28 ( V_98 L_14 ,
V_2 -> V_7 . V_15 , F_27 ( V_2 ) ,
V_2 -> V_7 . V_10 . V_9 ) ;
V_12 = V_72 ;
F_29 () ;
break;
}
return V_12 ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_99 * V_100 )
{
int V_90 ;
V_100 -> V_11 = V_2 -> V_7 . V_11 ;
memset ( V_100 , 0 , sizeof( struct V_99 ) ) ;
for ( V_90 = 0 ; V_90 < V_2 -> V_7 . V_30 ; V_90 ++ ) {
V_100 -> V_101 . V_102 . V_103 . V_31 [ V_90 ] . V_104 = V_2 -> V_7 . V_31 [ V_90 ] . V_32 ;
V_100 -> V_101 . V_102 . V_103 . V_31 [ V_90 ] . V_105 = V_2 -> V_7 . V_31 [ V_90 ] . V_33 ;
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_99 * V_100 )
{
int V_90 , V_106 ;
F_5 ( V_2 , V_100 -> V_11 ) ;
V_106 = 0 ;
for ( V_90 = 0 ; V_90 < V_2 -> V_7 . V_107 ; V_90 ++ ) {
if ( V_100 -> V_101 . V_102 . V_103 . V_31 [ V_90 ] . V_104 & V_108 ) {
V_2 -> V_7 . V_31 [ V_106 ] . V_32 = V_100 -> V_101 . V_102 . V_103 . V_31 [ V_90 ] . V_104 ;
V_2 -> V_7 . V_31 [ V_106 ] . V_33 = V_100 -> V_101 . V_102 . V_103 . V_31 [ V_90 ] . V_105 ;
++ V_106 ;
}
}
V_2 -> V_7 . V_30 = V_106 ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , struct V_109 * V_110 )
{
int V_12 = - V_111 ;
switch ( V_110 -> V_38 ) {
case V_112 :
V_12 = F_33 ( 0 , ( T_1 V_113 * ) V_110 -> V_114 ) ;
break;
default:
break;
}
return V_12 ;
}
int F_34 ( struct V_1 * V_2 , struct V_109 * V_110 )
{
int V_12 = - V_111 ;
switch ( V_110 -> V_38 ) {
case V_112 :
{
T_1 V_115 ;
V_12 = F_35 ( V_115 , ( T_1 V_113 * ) V_110 -> V_114 ) ;
if ( ! V_12 && ( V_115 != 0 ) )
V_12 = - V_111 ;
break;
}
default:
break;
}
return V_12 ;
}
int F_36 ( void )
{
if ( F_37 ( V_116 ) )
return 0 ;
return - V_117 ;
}
struct V_1 * F_38 ( struct V_34 * V_34 , unsigned int V_38 )
{
struct V_1 * V_2 ;
int V_52 = - V_111 ;
int V_118 ;
struct V_119 * V_8 ;
V_118 = V_38 / V_120 ;
if ( V_118 >= V_121 )
goto V_122;
V_52 = - V_123 ;
V_2 = F_39 ( V_124 , V_125 ) ;
if ( ! V_2 )
goto V_122;
V_52 = F_40 ( V_2 , V_34 , V_38 ) ;
if ( V_52 )
goto V_126;
V_2 -> V_7 . V_127 = & V_2 -> V_7 . V_10 ;
V_2 -> V_7 . V_128 = - 1 ;
V_2 -> V_7 . V_129 [ 0 ] = V_130 ;
V_2 -> V_7 . V_131 = V_132 ;
V_2 -> V_7 . V_11 = F_41 ( V_133 ) ;
F_5 ( V_2 , V_2 -> V_7 . V_11 ) ;
F_42 ( V_2 ) ;
V_2 -> V_7 . V_134 = V_135 ;
F_43 ( & V_2 -> V_7 . V_136 ) ;
F_10 ( & V_34 -> V_41 ) ;
V_8 = V_34 -> V_7 . V_137 [ V_118 ] ;
if ( ! V_8 ) {
V_8 = F_44 ( sizeof( struct V_119 ) , V_125 ) ;
if ( V_8 ) {
F_45 ( & V_8 -> V_138 ) ;
F_46 ( & V_8 -> V_41 ) ;
F_43 ( & V_8 -> V_67 ) ;
}
V_34 -> V_7 . V_137 [ V_118 ] = V_8 ;
}
F_12 ( & V_34 -> V_41 ) ;
if ( ! V_8 )
goto V_126;
F_47 ( & V_8 -> V_41 ) ;
++ V_8 -> V_139 ;
F_48 ( & V_8 -> V_41 ) ;
V_2 -> V_7 . V_8 = V_8 ;
V_2 -> V_7 . V_140 = V_141 ;
F_49 ( V_2 ) ;
return V_2 ;
V_126:
F_50 ( V_124 , V_2 ) ;
V_122:
return F_51 ( V_52 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 . V_56 )
F_16 ( V_2 -> V_34 , V_2 -> V_7 . V_56 ) ;
if ( V_2 -> V_7 . V_58 )
F_16 ( V_2 -> V_34 , V_2 -> V_7 . V_58 ) ;
if ( V_2 -> V_7 . V_43 )
F_16 ( V_2 -> V_34 , V_2 -> V_7 . V_43 ) ;
F_53 ( V_2 ) ;
F_50 ( V_124 , V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
unsigned long V_142 , V_143 ;
V_143 = F_55 () ;
if ( V_143 > V_2 -> V_7 . V_144 ) {
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
return;
}
V_142 = ( V_2 -> V_7 . V_144 - V_143 ) * V_145
/ V_146 ;
F_58 ( & V_2 -> V_7 . V_147 , F_59 ( 0 , V_142 ) ,
V_148 ) ;
V_2 -> V_7 . V_149 = 1 ;
}
static void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_7 . V_66 = 0 ;
if ( V_2 -> V_7 . V_149 ) {
F_60 ( & V_2 -> V_7 . V_147 ) ;
V_2 -> V_7 . V_149 = 0 ;
}
}
static void F_61 ( struct V_119 * V_150 ,
struct V_1 * V_2 )
{
struct V_1 * V_39 ;
if ( V_2 -> V_7 . V_134 != V_151 )
return;
V_2 -> V_7 . V_134 = V_152 ;
-- V_150 -> V_153 ;
++ V_150 -> V_154 ;
V_39 = V_2 ;
F_62 ( V_39 , & V_150 -> V_138 , V_7 . V_155 )
-- V_39 -> V_7 . V_156 ;
F_63 ( & V_2 -> V_7 . V_155 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_157 * V_158 ;
struct V_119 * V_150 = V_2 -> V_7 . V_8 ;
if ( V_2 -> V_7 . V_149 ) {
F_60 ( & V_2 -> V_7 . V_147 ) ;
V_2 -> V_7 . V_149 = 0 ;
}
V_3 = V_150 -> V_159 + V_2 -> V_7 . V_156 ;
V_158 = & V_160 [ V_3 ] ;
V_158 -> V_5 . V_1 = V_2 ;
V_158 -> V_5 . V_6 = V_150 ;
V_158 -> V_5 . V_161 = 0 ;
V_2 -> V_3 = V_150 -> V_159 ;
F_65 () ;
#if F_66 ( V_162 ) && F_66 ( V_163 )
if ( V_2 -> V_7 . V_156 ) {
V_158 -> V_164 = 0x80 ;
F_67 () ;
F_68 ( V_3 ) ;
++ V_150 -> V_165 ;
}
#endif
}
static void F_69 ( struct V_119 * V_150 )
{
int V_90 ;
F_70 () ;
V_90 = 0 ;
while ( V_150 -> V_166 < V_150 -> V_165 ) {
if ( ++ V_90 >= 1000000 ) {
F_7 ( L_15 ,
V_150 -> V_166 , V_150 -> V_165 ) ;
break;
}
F_71 () ;
}
F_72 () ;
}
static int F_73 ( void )
{
int V_3 = F_74 () ;
int V_167 = F_75 ( V_3 ) ;
if ( V_167 )
return 0 ;
while ( ++ V_167 < V_120 )
if ( F_76 ( V_3 + V_167 ) )
return 0 ;
return 1 ;
}
static int F_77 ( struct V_119 * V_150 )
{
struct V_1 * V_2 , * V_168 , * V_169 ;
long V_40 ;
T_1 V_143 ;
int V_156 ;
F_78 (vcpu, &vc->runnable_threads, arch.run_list)
if ( F_79 ( V_2 -> V_7 . V_170 ) )
return 0 ;
if ( V_120 > 1 && ! F_73 () ) {
F_78 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_7 . V_40 = - V_171 ;
goto V_122;
}
V_156 = 0 ;
V_168 = NULL ;
F_78 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( ! V_2 -> V_7 . V_66 ) {
if ( ! V_156 )
V_168 = V_2 ;
V_2 -> V_7 . V_156 = V_156 ++ ;
}
}
if ( ! V_168 )
return 0 ;
F_78 (vcpu, &vc->runnable_threads, arch.run_list)
if ( V_2 -> V_7 . V_66 )
V_2 -> V_7 . V_156 = V_156 ++ ;
V_150 -> V_165 = 0 ;
V_150 -> V_166 = 0 ;
V_150 -> V_172 = 0 ;
V_150 -> V_173 = V_174 ;
V_150 -> V_175 = 0 ;
V_150 -> V_159 = F_74 () ;
V_150 -> V_176 = 0 ;
F_78 (vcpu, &vc->runnable_threads, arch.run_list)
F_64 ( V_2 ) ;
F_80 () ;
F_48 ( & V_150 -> V_41 ) ;
F_81 () ;
F_82 ( NULL , V_168 ) ;
F_47 ( & V_150 -> V_41 ) ;
F_78 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_3 = - 1 ;
if ( V_150 -> V_166 < V_150 -> V_165 )
F_69 ( V_150 ) ;
V_150 -> V_173 = V_177 ;
F_48 ( & V_150 -> V_41 ) ;
F_19 () ;
F_83 () ;
F_84 () ;
F_85 ( V_2 ) ;
V_143 = F_55 () ;
F_78 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_143 < V_2 -> V_7 . V_144 &&
F_86 ( V_2 ) )
F_87 ( V_2 ) ;
V_40 = V_74 ;
if ( V_2 -> V_7 . V_15 )
V_40 = F_23 ( V_2 -> V_7 . V_75 , V_2 ,
V_2 -> V_7 . V_170 ) ;
V_2 -> V_7 . V_40 = V_40 ;
V_2 -> V_7 . V_15 = 0 ;
if ( V_2 -> V_7 . V_66 ) {
if ( V_40 != V_74 )
F_4 ( V_2 ) ;
else
F_54 ( V_2 ) ;
}
}
F_47 ( & V_150 -> V_41 ) ;
V_122:
V_150 -> V_173 = V_178 ;
F_88 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( V_2 -> V_7 . V_40 != V_74 ) {
F_61 ( V_150 , V_2 ) ;
F_89 ( & V_2 -> V_7 . V_136 ) ;
}
}
return 1 ;
}
static void F_90 ( struct V_1 * V_2 , int V_179 )
{
F_91 ( V_180 ) ;
F_92 ( & V_2 -> V_7 . V_136 , & V_180 , V_179 ) ;
if ( V_2 -> V_7 . V_134 == V_151 )
F_93 () ;
F_94 ( & V_2 -> V_7 . V_136 , & V_180 ) ;
}
static void F_95 ( struct V_119 * V_150 )
{
F_91 ( V_180 ) ;
struct V_1 * V_39 ;
int V_181 = 1 ;
F_92 ( & V_150 -> V_67 , & V_180 , V_182 ) ;
V_150 -> V_173 = V_183 ;
F_48 ( & V_150 -> V_41 ) ;
F_78 (v, &vc->runnable_threads, arch.run_list) {
if ( ! V_39 -> V_7 . V_66 || V_39 -> V_7 . V_184 ) {
V_181 = 0 ;
break;
}
}
if ( V_181 )
F_93 () ;
F_94 ( & V_150 -> V_67 , & V_180 ) ;
F_47 ( & V_150 -> V_41 ) ;
V_150 -> V_173 = V_178 ;
}
static int F_96 ( struct V_75 * V_75 , struct V_1 * V_2 )
{
int V_185 ;
int V_186 ;
struct V_119 * V_150 ;
struct V_1 * V_39 , * V_187 ;
V_75 -> V_80 = 0 ;
V_2 -> V_7 . V_40 = V_74 ;
V_2 -> V_7 . V_15 = 0 ;
V_150 = V_2 -> V_7 . V_8 ;
F_47 ( & V_150 -> V_41 ) ;
V_2 -> V_7 . V_66 = 0 ;
V_2 -> V_7 . V_170 = V_188 ;
V_2 -> V_7 . V_75 = V_75 ;
V_186 = V_2 -> V_7 . V_134 ;
V_2 -> V_7 . V_134 = V_151 ;
F_97 ( & V_2 -> V_7 . V_155 , & V_150 -> V_138 ) ;
++ V_150 -> V_153 ;
if ( V_186 == V_135 ) {
if ( V_150 -> V_173 == V_174 &&
F_98 ( V_150 ) == 0 ) {
V_2 -> V_7 . V_156 = V_150 -> V_153 - 1 ;
F_64 ( V_2 ) ;
}
} else if ( V_186 == V_152 )
-- V_150 -> V_154 ;
while ( V_2 -> V_7 . V_134 == V_151 &&
! F_79 ( V_188 ) ) {
if ( V_150 -> V_154 || V_150 -> V_173 != V_178 ) {
F_48 ( & V_150 -> V_41 ) ;
F_90 ( V_2 , V_182 ) ;
F_47 ( & V_150 -> V_41 ) ;
continue;
}
V_185 = 0 ;
F_78 (v, &vc->runnable_threads, arch.run_list)
V_185 += V_39 -> V_7 . V_66 ;
if ( V_185 == V_150 -> V_153 )
F_95 ( V_150 ) ;
else
F_77 ( V_150 ) ;
F_88 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_57 ( V_39 ) ;
if ( F_79 ( V_39 -> V_7 . V_170 ) ) {
F_61 ( V_150 , V_39 ) ;
V_39 -> V_68 . V_189 ++ ;
V_39 -> V_7 . V_75 -> V_80 = V_190 ;
V_39 -> V_7 . V_40 = - V_191 ;
F_89 ( & V_39 -> V_7 . V_136 ) ;
}
}
}
if ( F_79 ( V_188 ) ) {
if ( V_150 -> V_173 == V_174 ||
V_150 -> V_173 == V_177 ) {
F_48 ( & V_150 -> V_41 ) ;
F_90 ( V_2 , V_192 ) ;
F_47 ( & V_150 -> V_41 ) ;
}
if ( V_2 -> V_7 . V_134 == V_151 ) {
F_61 ( V_150 , V_2 ) ;
V_2 -> V_68 . V_189 ++ ;
V_75 -> V_80 = V_190 ;
V_2 -> V_7 . V_40 = - V_191 ;
}
}
F_48 ( & V_150 -> V_41 ) ;
return V_2 -> V_7 . V_40 ;
}
int F_99 ( struct V_75 * V_76 , struct V_1 * V_2 )
{
int V_12 ;
if ( ! V_2 -> V_7 . V_193 ) {
V_76 -> V_80 = V_194 ;
return - V_111 ;
}
F_57 ( V_2 ) ;
if ( F_79 ( V_188 ) ) {
V_76 -> V_80 = V_190 ;
return - V_191 ;
}
if ( ! V_2 -> V_34 -> V_7 . V_195 ) {
V_12 = F_100 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
F_101 ( V_188 ) ;
F_102 ( V_188 ) ;
F_103 ( V_188 ) ;
V_2 -> V_7 . V_196 = & V_2 -> V_7 . V_8 -> V_67 ;
V_2 -> V_7 . V_197 = V_188 -> V_198 -> V_199 ;
do {
V_12 = F_96 ( V_76 , V_2 ) ;
if ( V_76 -> V_80 == V_94 &&
! ( V_2 -> V_7 . V_10 . V_9 & V_91 ) ) {
V_12 = F_17 ( V_2 ) ;
F_57 ( V_2 ) ;
}
} while ( V_12 == V_74 );
return V_12 ;
}
static long F_104 ( unsigned long V_200 )
{
return F_105 ( ( V_200 >> V_201 )
* sizeof( T_1 ) , V_202 ) / V_202 ;
}
static void F_106 ( struct V_203 * V_204 )
{
struct V_34 * V_34 = V_204 -> V_34 ;
int V_90 ;
F_10 ( & V_34 -> V_41 ) ;
F_63 ( & V_204 -> V_205 ) ;
for ( V_90 = 0 ; V_90 < F_104 ( V_204 -> V_200 ) ; V_90 ++ )
F_107 ( V_204 -> V_206 [ V_90 ] ) ;
F_108 ( V_204 ) ;
F_12 ( & V_34 -> V_41 ) ;
F_109 ( V_34 ) ;
}
static int F_110 ( struct V_207 * V_208 , struct V_209 * V_210 )
{
struct V_203 * V_204 = V_208 -> V_211 -> V_212 ;
struct V_213 * V_213 ;
if ( V_210 -> V_214 >= F_104 ( V_204 -> V_200 ) )
return V_215 ;
V_213 = V_204 -> V_206 [ V_210 -> V_214 ] ;
F_111 ( V_213 ) ;
V_210 -> V_213 = V_213 ;
return 0 ;
}
static int F_112 ( struct V_216 * V_216 , struct V_207 * V_208 )
{
V_208 -> V_217 = & V_218 ;
return 0 ;
}
static int F_113 ( struct V_219 * V_219 , struct V_216 * V_220 )
{
struct V_203 * V_204 = V_220 -> V_212 ;
F_106 ( V_204 ) ;
return 0 ;
}
long F_114 ( struct V_34 * V_34 ,
struct V_221 * args )
{
struct V_203 * V_204 = NULL ;
long V_222 ;
int V_40 = - V_123 ;
int V_90 ;
F_78 (stt, &kvm->arch.spapr_tce_tables, list) {
if ( V_204 -> V_223 == args -> V_223 )
return - V_171 ;
}
V_222 = F_104 ( args -> V_200 ) ;
V_204 = F_44 ( sizeof( * V_204 ) + V_222 * sizeof( struct V_213 * ) ,
V_125 ) ;
if ( ! V_204 )
goto V_224;
V_204 -> V_223 = args -> V_223 ;
V_204 -> V_200 = args -> V_200 ;
V_204 -> V_34 = V_34 ;
for ( V_90 = 0 ; V_90 < V_222 ; V_90 ++ ) {
V_204 -> V_206 [ V_90 ] = F_115 ( V_125 | V_225 ) ;
if ( ! V_204 -> V_206 [ V_90 ] )
goto V_224;
}
F_116 ( V_34 ) ;
F_10 ( & V_34 -> V_41 ) ;
F_117 ( & V_204 -> V_205 , & V_34 -> V_7 . V_226 ) ;
F_12 ( & V_34 -> V_41 ) ;
return F_118 ( L_16 , & V_227 ,
V_204 , V_228 ) ;
V_224:
if ( V_204 ) {
for ( V_90 = 0 ; V_90 < V_222 ; V_90 ++ )
if ( V_204 -> V_206 [ V_90 ] )
F_107 ( V_204 -> V_206 [ V_90 ] ) ;
F_108 ( V_204 ) ;
}
return V_40 ;
}
static inline int F_119 ( unsigned long V_229 )
{
switch ( V_229 ) {
case 32ul << 20 :
if ( F_37 ( V_230 ) )
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
static int F_120 ( struct V_207 * V_208 , struct V_209 * V_210 )
{
struct V_231 * V_232 = V_208 -> V_211 -> V_212 ;
struct V_213 * V_213 ;
if ( V_210 -> V_214 >= V_232 -> V_222 )
return V_215 ;
V_213 = F_121 ( V_232 -> V_233 + V_210 -> V_214 ) ;
F_111 ( V_213 ) ;
V_210 -> V_213 = V_213 ;
return 0 ;
}
static int F_122 ( struct V_216 * V_216 , struct V_207 * V_208 )
{
V_208 -> V_234 |= V_235 ;
V_208 -> V_217 = & V_236 ;
return 0 ;
}
static int F_123 ( struct V_219 * V_219 , struct V_216 * V_220 )
{
struct V_231 * V_232 = V_220 -> V_212 ;
F_124 ( V_232 ) ;
return 0 ;
}
long F_125 ( struct V_34 * V_34 , struct V_237 * V_40 )
{
struct V_231 * V_232 ;
long V_238 ;
V_232 = F_126 () ;
if ( ! V_232 )
return - V_123 ;
V_238 = F_118 ( L_17 , & V_239 , V_232 , V_228 ) ;
if ( V_238 < 0 )
F_124 ( V_232 ) ;
V_40 -> V_229 = V_232 -> V_222 << V_240 ;
return V_238 ;
}
int F_127 ( struct V_34 * V_34 , struct V_241 * log )
{
struct V_242 * V_243 ;
int V_12 ;
unsigned long V_244 ;
F_10 ( & V_34 -> V_245 ) ;
V_12 = - V_111 ;
if ( log -> V_246 >= V_247 )
goto V_122;
V_243 = F_128 ( V_34 -> V_248 , log -> V_246 ) ;
V_12 = - V_249 ;
if ( ! V_243 -> V_250 )
goto V_122;
V_244 = F_129 ( V_243 ) ;
memset ( V_243 -> V_250 , 0 , V_244 ) ;
V_12 = F_130 ( V_34 , V_243 ) ;
if ( V_12 )
goto V_122;
V_12 = - V_251 ;
if ( F_131 ( log -> V_250 , V_243 -> V_250 , V_244 ) )
goto V_122;
V_12 = 0 ;
V_122:
F_12 ( & V_34 -> V_245 ) ;
return V_12 ;
}
static unsigned long F_132 ( unsigned long V_252 )
{
unsigned long V_253 = 0 ;
if ( V_252 > 0x1000 ) {
V_253 = V_254 ;
if ( V_252 == 0x10000 )
V_253 |= V_255 ;
}
return V_253 ;
}
int F_133 ( struct V_34 * V_34 ,
struct V_256 * V_257 )
{
unsigned long V_222 ;
unsigned long * V_258 ;
V_258 = V_34 -> V_7 . V_259 [ V_257 -> V_246 ] ;
if ( ! V_34 -> V_7 . V_260 && ! V_258 ) {
V_222 = V_257 -> V_261 >> V_240 ;
V_258 = F_134 ( V_222 * sizeof( unsigned long ) ) ;
if ( ! V_258 )
return - V_123 ;
V_34 -> V_7 . V_259 [ V_257 -> V_246 ] = V_258 ;
V_34 -> V_7 . V_262 [ V_257 -> V_246 ] = V_222 ;
}
return 0 ;
}
static void F_135 ( struct V_34 * V_34 , int V_263 )
{
unsigned long * V_264 ;
unsigned long V_106 , V_222 , V_265 ;
struct V_213 * V_213 ;
V_264 = V_34 -> V_7 . V_259 [ V_263 ] ;
V_222 = V_34 -> V_7 . V_262 [ V_263 ] ;
if ( V_264 ) {
F_47 ( & V_34 -> V_7 . V_266 ) ;
for ( V_106 = 0 ; V_106 < V_222 ; V_106 ++ ) {
if ( ! ( V_264 [ V_106 ] & V_267 ) )
continue;
V_265 = V_264 [ V_106 ] >> V_240 ;
V_213 = F_121 ( V_265 ) ;
F_136 ( V_213 ) ;
F_137 ( V_213 ) ;
}
V_34 -> V_7 . V_259 [ V_263 ] = NULL ;
F_48 ( & V_34 -> V_7 . V_266 ) ;
F_138 ( V_264 ) ;
}
}
void F_139 ( struct V_34 * V_34 ,
struct V_256 * V_257 )
{
}
static int F_100 ( struct V_1 * V_2 )
{
int V_52 = 0 ;
struct V_34 * V_34 = V_2 -> V_34 ;
struct V_231 * V_232 = NULL ;
unsigned long V_268 ;
struct V_242 * V_243 ;
struct V_207 * V_208 ;
unsigned long V_35 , V_253 ;
unsigned long V_252 , V_269 ;
unsigned long V_229 ;
unsigned long V_270 ;
unsigned long * V_264 ;
unsigned long V_90 , V_222 ;
F_10 ( & V_34 -> V_41 ) ;
if ( V_34 -> V_7 . V_195 )
goto V_122;
V_243 = F_140 ( V_34 , 0 ) ;
V_52 = - V_111 ;
if ( ! V_243 || ( V_243 -> V_46 & V_271 ) )
goto V_122;
V_268 = V_243 -> V_272 ;
F_141 ( & V_188 -> V_198 -> V_273 ) ;
V_208 = F_142 ( V_188 -> V_198 , V_268 ) ;
if ( ! V_208 || V_208 -> V_274 > V_268 || ( V_208 -> V_234 & V_275 ) )
goto V_276;
V_252 = F_143 ( V_208 ) ;
V_269 = F_144 ( V_252 ) ;
if ( V_208 -> V_211 && V_208 -> V_211 -> V_277 == & V_239 &&
V_268 == V_208 -> V_274 )
V_232 = V_208 -> V_211 -> V_212 ;
F_145 ( & V_188 -> V_198 -> V_273 ) ;
if ( ! V_232 ) {
V_52 = - V_278 ;
if ( F_37 ( V_279 ) ) {
F_7 ( L_18 ) ;
goto V_122;
}
V_52 = - V_111 ;
if ( ! ( V_252 == 0x1000 || V_252 == 0x10000 ||
V_252 == 0x1000000 ) )
goto V_122;
V_253 = F_132 ( V_252 ) ;
V_34 -> V_7 . V_280 = V_253 | V_281 |
( V_282 << V_283 ) ;
V_35 = V_34 -> V_7 . V_35 & ~ V_284 ;
V_35 |= V_253 << ( V_285 - 4 ) ;
V_34 -> V_7 . V_35 = V_35 ;
F_146 ( V_2 , V_243 , V_269 ) ;
} else {
V_229 = V_232 -> V_222 ;
if ( V_229 > V_243 -> V_222 )
V_229 = V_243 -> V_222 ;
V_229 <<= V_240 ;
V_270 = F_119 ( V_229 ) ;
V_52 = - V_111 ;
if ( V_270 < 0 ) {
F_7 ( L_19 , V_229 ) ;
goto V_122;
}
F_147 ( & V_232 -> V_286 ) ;
V_34 -> V_7 . V_287 = V_232 ;
V_35 = V_34 -> V_7 . V_35 ;
if ( F_37 ( V_279 ) ) {
V_35 &= ~ ( ( 1ul << V_288 ) |
( 3ul << V_289 ) ) ;
V_35 |= ( ( V_270 >> 2 ) << V_288 ) |
( ( V_270 & 3 ) << V_289 ) ;
V_35 |= ( ( V_232 -> V_233 >> ( 26 - V_240 ) ) & 0xffff )
<< V_290 ;
} else {
V_35 &= ~ ( V_291 | V_292 ) ;
V_35 |= V_270 << V_293 ;
V_34 -> V_7 . V_294 = V_34 -> V_7 . V_287 -> V_233 << V_240 ;
}
V_34 -> V_7 . V_35 = V_35 ;
F_148 ( L_20 ,
V_232 -> V_233 << V_240 , V_229 , V_35 ) ;
V_222 = V_232 -> V_222 ;
V_269 = F_144 ( V_222 ) ;
V_264 = V_34 -> V_7 . V_259 [ V_243 -> V_38 ] ;
F_47 ( & V_34 -> V_7 . V_266 ) ;
for ( V_90 = 0 ; V_90 < V_222 ; ++ V_90 )
V_264 [ V_90 ] = ( ( V_232 -> V_233 + V_90 ) << V_240 ) + V_269 ;
F_48 ( & V_34 -> V_7 . V_266 ) ;
}
F_65 () ;
V_34 -> V_7 . V_195 = 1 ;
V_52 = 0 ;
V_122:
F_12 ( & V_34 -> V_41 ) ;
return V_52 ;
V_276:
F_145 ( & V_188 -> V_198 -> V_273 ) ;
goto V_122;
}
int F_149 ( struct V_34 * V_34 )
{
long V_12 ;
unsigned long V_35 ;
V_12 = F_150 ( V_34 ) ;
if ( V_12 )
return V_12 ;
F_45 ( & V_34 -> V_7 . V_226 ) ;
V_34 -> V_7 . V_287 = NULL ;
V_34 -> V_7 . V_295 = F_41 ( V_296 ) ;
if ( F_37 ( V_279 ) ) {
unsigned long V_297 = V_34 -> V_7 . V_297 ;
V_34 -> V_7 . V_298 = 0 ;
V_34 -> V_7 . V_299 = V_35 = F_41 ( V_300 ) ;
V_35 &= ~ ( ( 3 << V_301 ) | ( 0xful << V_302 ) ) ;
V_35 |= ( ( V_297 >> 4 ) << V_301 ) |
( ( V_297 & 0xf ) << V_302 ) ;
} else {
V_34 -> V_7 . V_298 = F_41 ( V_303 ) ;
V_34 -> V_7 . V_299 = V_35 = F_41 ( V_304 ) ;
V_35 &= V_305 | V_306 ;
V_35 |= ( 4UL << V_307 ) | V_308 |
V_291 | V_309 ;
V_34 -> V_7 . V_280 = V_281 |
( V_282 << V_283 ) ;
}
V_34 -> V_7 . V_35 = V_35 ;
V_34 -> V_7 . V_260 = ! ! F_37 ( V_230 ) ;
F_46 ( & V_34 -> V_7 . V_266 ) ;
return 0 ;
}
void F_151 ( struct V_34 * V_34 )
{
unsigned long V_90 ;
if ( ! V_34 -> V_7 . V_260 )
for ( V_90 = 0 ; V_90 < V_310 ; V_90 ++ )
F_135 ( V_34 , V_90 ) ;
if ( V_34 -> V_7 . V_287 ) {
F_124 ( V_34 -> V_7 . V_287 ) ;
V_34 -> V_7 . V_287 = NULL ;
}
F_152 ( V_34 ) ;
F_153 ( ! F_154 ( & V_34 -> V_7 . V_226 ) ) ;
}
void F_155 ( struct V_1 * V_2 , T_3 V_311 , T_3 V_312 )
{
}
int F_156 ( struct V_75 * V_76 , struct V_1 * V_2 ,
unsigned int V_313 , int * V_314 )
{
return V_315 ;
}
int F_157 ( struct V_1 * V_2 , int V_316 , int V_317 )
{
return V_315 ;
}
int F_158 ( struct V_1 * V_2 , int V_316 , int V_318 )
{
return V_315 ;
}
static int F_159 ( void )
{
int V_12 ;
V_12 = F_160 ( NULL , sizeof( struct V_1 ) , 0 , V_319 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_161 () ;
return V_12 ;
}
static void F_162 ( void )
{
F_163 () ;
}
