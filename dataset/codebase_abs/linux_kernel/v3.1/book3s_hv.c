void F_1 ( struct V_1 * V_2 , int V_3 )
{
V_4 -> V_5 . V_1 = V_2 ;
V_4 -> V_5 . V_6 = V_2 -> V_7 . V_8 ;
}
void F_2 ( struct V_1 * V_2 )
{
}
void F_3 ( struct V_1 * V_2 )
{
T_1 V_9 ;
unsigned long V_10 ;
V_9 = F_4 () ;
if ( V_9 >= V_2 -> V_7 . V_11 && ! F_5 ( V_2 ) )
F_6 ( V_2 ) ;
if ( V_2 -> V_7 . V_12 )
return;
if ( V_2 -> V_7 . V_11 != ~ ( T_1 ) 0 ) {
V_10 = ( V_2 -> V_7 . V_11 - V_9 ) * V_13 /
V_14 ;
F_7 ( & V_2 -> V_7 . V_15 , F_8 ( 0 , V_10 ) ,
V_16 ) ;
}
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
V_2 -> V_17 . V_18 ++ ;
if ( V_2 -> V_7 . V_11 != ~ ( T_1 ) 0 )
F_11 ( & V_2 -> V_7 . V_15 ) ;
F_12 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 , T_1 V_19 )
{
V_2 -> V_7 . V_20 . V_19 = V_19 ;
}
void F_14 ( struct V_1 * V_2 , T_2 V_21 )
{
V_2 -> V_7 . V_21 = V_21 ;
}
void F_15 ( struct V_1 * V_2 )
{
int V_22 ;
F_16 ( L_1 , V_2 , V_2 -> V_23 ) ;
F_16 ( L_2 ,
V_2 -> V_7 . V_24 , V_2 -> V_7 . V_20 . V_19 , V_2 -> V_7 . V_25 ) ;
for ( V_22 = 0 ; V_22 < 16 ; ++ V_22 )
F_16 ( L_3 ,
V_22 , F_17 ( V_2 , V_22 ) ,
V_22 + 16 , F_17 ( V_2 , V_22 + 16 ) ) ;
F_16 ( L_4 ,
V_2 -> V_7 . V_26 , V_2 -> V_7 . V_27 ) ;
F_16 ( L_5 ,
V_2 -> V_7 . V_20 . V_28 , V_2 -> V_7 . V_20 . V_29 ) ;
F_16 ( L_6 ,
V_2 -> V_7 . V_20 . V_30 , V_2 -> V_7 . V_20 . V_31 ) ;
F_16 ( L_7 ,
V_2 -> V_7 . V_20 . V_32 , V_2 -> V_7 . V_20 . V_33 ) ;
F_16 ( L_8 ,
V_2 -> V_7 . V_34 , V_2 -> V_7 . V_35 , V_2 -> V_7 . V_20 . V_36 ) ;
F_16 ( L_9 , V_2 -> V_7 . V_20 . V_37 ) ;
F_16 ( L_10 ,
V_2 -> V_7 . V_38 , V_2 -> V_7 . V_39 ) ;
F_16 ( L_11 , V_2 -> V_7 . V_40 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_7 . V_40 ; ++ V_22 )
F_16 ( L_12 ,
V_2 -> V_7 . V_41 [ V_22 ] . V_42 , V_2 -> V_7 . V_41 [ V_22 ] . V_43 ) ;
F_16 ( L_13 ,
V_2 -> V_44 -> V_7 . V_45 , V_2 -> V_44 -> V_7 . V_46 ,
V_2 -> V_7 . V_47 ) ;
}
struct V_1 * F_18 ( struct V_44 * V_44 , int V_48 )
{
int V_22 ;
struct V_1 * V_49 , * V_50 = NULL ;
F_19 ( & V_44 -> V_51 ) ;
F_20 (r, v, kvm) {
if ( V_49 -> V_23 == V_48 ) {
V_50 = V_49 ;
break;
}
}
F_21 ( & V_44 -> V_51 ) ;
return V_50 ;
}
static void F_22 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
V_53 -> V_54 = 1 ;
V_53 -> V_55 = 1 ;
}
static unsigned long F_23 ( struct V_1 * V_2 ,
unsigned long V_56 ,
unsigned long V_57 , unsigned long V_53 )
{
struct V_44 * V_44 = V_2 -> V_44 ;
unsigned long V_58 , V_59 , V_60 ;
unsigned long V_61 ;
void * V_62 ;
struct V_1 * V_63 ;
V_63 = F_18 ( V_44 , V_57 ) ;
if ( ! V_63 )
return V_64 ;
V_56 >>= 63 - 18 ;
V_56 &= 7 ;
if ( V_56 == 0 || V_56 == 4 )
return V_64 ;
if ( V_56 < 4 ) {
if ( V_53 & 0x7f )
return V_64 ;
V_58 = V_53 >> V_44 -> V_7 . V_65 ;
V_61 = V_53 & ( V_44 -> V_7 . V_66 - 1 ) ;
if ( V_58 >= V_44 -> V_7 . V_67 )
return V_64 ;
if ( V_44 -> V_7 . V_68 [ V_58 ] . V_69 == 0 )
return V_64 ;
V_59 = V_44 -> V_7 . V_68 [ V_58 ] . V_69 << V_70 ;
V_59 |= V_61 ;
V_62 = F_24 ( V_59 ) ;
if ( V_56 <= 1 )
V_60 = * ( unsigned short * ) ( V_62 + 4 ) ;
else
V_60 = * ( unsigned int * ) ( V_62 + 4 ) ;
if ( V_61 + V_60 > V_44 -> V_7 . V_66 )
return V_64 ;
switch ( V_56 ) {
case 1 :
if ( V_60 < 640 )
return V_64 ;
V_63 -> V_7 . V_53 = V_62 ;
F_22 ( V_2 , V_62 ) ;
break;
case 2 :
if ( V_60 < 48 )
return V_64 ;
if ( ! V_63 -> V_7 . V_53 )
return V_71 ;
V_60 -= V_60 % 48 ;
V_63 -> V_7 . V_72 = V_62 ;
V_63 -> V_7 . V_73 = V_62 + V_60 ;
break;
case 3 :
if ( V_60 < 8 )
return V_64 ;
if ( ! V_63 -> V_7 . V_53 )
return V_71 ;
V_63 -> V_7 . V_74 = V_62 ;
V_60 = ( V_60 - 16 ) / 16 ;
V_63 -> V_7 . V_74 = V_62 ;
break;
}
} else {
switch ( V_56 ) {
case 5 :
if ( V_63 -> V_7 . V_74 || V_63 -> V_7 . V_72 )
return V_71 ;
V_63 -> V_7 . V_53 = NULL ;
break;
case 6 :
V_63 -> V_7 . V_72 = NULL ;
break;
case 7 :
V_63 -> V_7 . V_74 = NULL ;
break;
}
}
return V_75 ;
}
int F_25 ( struct V_1 * V_2 )
{
unsigned long V_76 = F_17 ( V_2 , 3 ) ;
unsigned long V_77 , V_50 = V_75 ;
struct V_1 * V_63 ;
switch ( V_76 ) {
case V_78 :
V_2 -> V_7 . V_20 . V_19 |= V_79 ;
V_2 -> V_7 . V_80 = 1 ;
F_26 () ;
if ( ! V_2 -> V_7 . V_81 )
F_3 ( V_2 ) ;
else
V_2 -> V_7 . V_81 = 0 ;
F_26 () ;
V_2 -> V_7 . V_80 = 0 ;
break;
case V_82 :
V_77 = F_17 ( V_2 , 4 ) ;
V_63 = F_18 ( V_2 -> V_44 , V_77 ) ;
if ( ! V_63 ) {
V_50 = V_64 ;
break;
}
V_63 -> V_7 . V_81 = 1 ;
F_26 () ;
if ( V_2 -> V_7 . V_80 ) {
if ( F_27 ( & V_2 -> V_83 ) ) {
F_28 ( & V_2 -> V_83 ) ;
V_2 -> V_17 . V_18 ++ ;
}
}
break;
case V_84 :
break;
case V_85 :
V_50 = F_23 ( V_2 , F_17 ( V_2 , 4 ) ,
F_17 ( V_2 , 5 ) ,
F_17 ( V_2 , 6 ) ) ;
break;
default:
return V_86 ;
}
F_29 ( V_2 , 3 , V_50 ) ;
V_2 -> V_7 . V_87 = 0 ;
return V_88 ;
}
static int F_30 ( struct V_89 * V_90 , struct V_1 * V_2 ,
struct V_91 * V_92 )
{
int V_22 = V_86 ;
V_2 -> V_17 . V_93 ++ ;
V_90 -> V_94 = V_95 ;
V_90 -> V_96 = 1 ;
switch ( V_2 -> V_7 . V_25 ) {
case V_97 :
V_2 -> V_17 . V_98 ++ ;
V_22 = V_88 ;
break;
case V_99 :
V_2 -> V_17 . V_100 ++ ;
V_22 = V_88 ;
break;
case V_101 :
V_22 = V_88 ;
break;
case V_102 :
{
T_3 V_56 ;
V_56 = V_2 -> V_7 . V_20 . V_19 & 0x1f0000ull ;
F_31 ( V_2 , V_56 ) ;
V_22 = V_88 ;
break;
}
case V_103 :
{
int V_104 ;
if ( V_2 -> V_7 . V_20 . V_19 & V_105 ) {
F_32 ( V_2 , V_103 ) ;
V_22 = V_88 ;
break;
}
V_90 -> V_106 . V_107 = F_17 ( V_2 , 3 ) ;
for ( V_104 = 0 ; V_104 < 9 ; ++ V_104 )
V_90 -> V_106 . args [ V_104 ] = F_17 ( V_2 , 4 + V_104 ) ;
V_90 -> V_94 = V_108 ;
V_2 -> V_7 . V_87 = 1 ;
V_22 = V_86 ;
break;
}
case V_109 :
V_2 -> V_7 . V_20 . V_36 = V_2 -> V_7 . V_39 ;
V_2 -> V_7 . V_20 . V_37 = V_2 -> V_7 . V_38 ;
F_33 ( V_2 , V_110 , 0 ) ;
V_22 = V_88 ;
break;
case V_111 :
F_33 ( V_2 , V_112 ,
0x08000000 ) ;
V_22 = V_88 ;
break;
case V_113 :
F_31 ( V_2 , 0x80000 ) ;
V_22 = V_88 ;
break;
default:
F_15 ( V_2 ) ;
F_34 ( V_114 L_14 ,
V_2 -> V_7 . V_25 , F_35 ( V_2 ) ,
V_2 -> V_7 . V_20 . V_19 ) ;
V_22 = V_86 ;
F_36 () ;
break;
}
if ( ! ( V_22 & V_86 ) ) {
if ( F_37 ( V_92 ) ) {
V_2 -> V_17 . V_115 ++ ;
V_90 -> V_94 = V_116 ;
V_22 = - V_117 ;
} else {
F_38 ( V_2 ) ;
}
}
return V_22 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
int V_104 ;
V_119 -> V_21 = V_2 -> V_7 . V_21 ;
memset ( V_119 , 0 , sizeof( struct V_118 ) ) ;
for ( V_104 = 0 ; V_104 < V_2 -> V_7 . V_40 ; V_104 ++ ) {
V_119 -> V_120 . V_121 . V_122 . V_41 [ V_104 ] . V_123 = V_2 -> V_7 . V_41 [ V_104 ] . V_42 ;
V_119 -> V_120 . V_121 . V_122 . V_41 [ V_104 ] . V_124 = V_2 -> V_7 . V_41 [ V_104 ] . V_43 ;
}
return 0 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
int V_104 , V_125 ;
F_14 ( V_2 , V_119 -> V_21 ) ;
V_125 = 0 ;
for ( V_104 = 0 ; V_104 < V_2 -> V_7 . V_126 ; V_104 ++ ) {
if ( V_119 -> V_120 . V_121 . V_122 . V_41 [ V_104 ] . V_123 & V_127 ) {
V_2 -> V_7 . V_41 [ V_125 ] . V_42 = V_119 -> V_120 . V_121 . V_122 . V_41 [ V_104 ] . V_123 ;
V_2 -> V_7 . V_41 [ V_125 ] . V_43 = V_119 -> V_120 . V_121 . V_122 . V_41 [ V_104 ] . V_124 ;
++ V_125 ;
}
}
V_2 -> V_7 . V_40 = V_125 ;
return 0 ;
}
int F_41 ( void )
{
if ( F_42 ( V_128 ) )
return 0 ;
return - V_129 ;
}
struct V_1 * F_43 ( struct V_44 * V_44 , unsigned int V_48 )
{
struct V_1 * V_2 ;
int V_130 = - V_131 ;
int V_132 ;
struct V_133 * V_8 ;
V_132 = V_48 / V_134 ;
if ( V_132 >= V_135 )
goto V_136;
V_130 = - V_137 ;
V_2 = F_44 ( sizeof( struct V_1 ) , V_138 ) ;
if ( ! V_2 )
goto V_136;
V_130 = F_45 ( V_2 , V_44 , V_48 ) ;
if ( V_130 )
goto V_139;
V_2 -> V_7 . V_140 = & V_2 -> V_7 . V_20 ;
V_2 -> V_7 . V_141 = - 1 ;
V_2 -> V_7 . V_142 [ 0 ] = V_143 ;
V_2 -> V_7 . V_144 = V_145 ;
V_2 -> V_7 . V_21 = F_46 ( V_146 ) ;
F_14 ( V_2 , V_2 -> V_7 . V_21 ) ;
F_47 ( V_2 ) ;
V_2 -> V_7 . V_147 = V_148 ;
F_48 ( & V_2 -> V_7 . V_149 ) ;
F_19 ( & V_44 -> V_51 ) ;
V_8 = V_44 -> V_7 . V_150 [ V_132 ] ;
if ( ! V_8 ) {
V_8 = F_44 ( sizeof( struct V_133 ) , V_138 ) ;
if ( V_8 ) {
F_49 ( & V_8 -> V_151 ) ;
F_50 ( & V_8 -> V_51 ) ;
}
V_44 -> V_7 . V_150 [ V_132 ] = V_8 ;
}
F_21 ( & V_44 -> V_51 ) ;
if ( ! V_8 )
goto V_139;
F_51 ( & V_8 -> V_51 ) ;
++ V_8 -> V_152 ;
++ V_8 -> V_153 ;
F_52 ( & V_8 -> V_51 ) ;
V_2 -> V_7 . V_8 = V_8 ;
return V_2 ;
V_139:
F_53 ( V_2 ) ;
V_136:
return F_54 ( V_130 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
F_56 ( V_2 ) ;
F_53 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_133 * V_154 = V_2 -> V_7 . V_8 ;
F_51 ( & V_154 -> V_51 ) ;
V_2 -> V_7 . V_147 = V_148 ;
++ V_154 -> V_153 ;
if ( V_154 -> V_155 > 0 &&
V_154 -> V_155 + V_154 -> V_153 == V_154 -> V_152 ) {
V_2 = F_57 ( & V_154 -> V_151 , struct V_1 ,
V_7 . V_156 ) ;
F_58 ( & V_2 -> V_7 . V_149 ) ;
}
F_52 ( & V_154 -> V_51 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_133 * V_154 = V_2 -> V_7 . V_8 ;
F_51 ( & V_154 -> V_51 ) ;
V_2 -> V_7 . V_147 = V_157 ;
-- V_154 -> V_153 ;
F_52 ( & V_154 -> V_51 ) ;
}
static void F_59 ( struct V_133 * V_154 ,
struct V_1 * V_2 )
{
struct V_1 * V_49 ;
if ( V_2 -> V_7 . V_147 != V_158 )
return;
V_2 -> V_7 . V_147 = V_157 ;
-- V_154 -> V_155 ;
V_49 = V_2 ;
F_60 ( V_49 , & V_154 -> V_151 , V_7 . V_156 )
-- V_49 -> V_7 . V_159 ;
F_61 ( & V_2 -> V_7 . V_156 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_160 * V_161 ;
struct V_133 * V_154 = V_2 -> V_7 . V_8 ;
V_3 = V_154 -> V_162 + V_2 -> V_7 . V_159 ;
V_161 = & V_163 [ V_3 ] ;
V_161 -> V_5 . V_1 = V_2 ;
V_161 -> V_5 . V_6 = V_154 ;
F_63 () ;
#ifdef F_64
if ( V_2 -> V_7 . V_159 ) {
V_161 -> V_164 = 0x80 ;
V_161 -> V_5 . V_165 = V_166 ;
F_65 () ;
F_66 ( V_3 ) ;
++ V_154 -> V_167 ;
}
#endif
}
static void F_67 ( struct V_133 * V_154 )
{
int V_104 ;
F_68 () ;
V_104 = 0 ;
while ( V_154 -> V_168 < V_154 -> V_167 ) {
if ( ++ V_104 >= 1000000 ) {
F_16 ( L_15 ,
V_154 -> V_168 , V_154 -> V_167 ) ;
break;
}
F_69 () ;
}
F_70 () ;
}
static int F_71 ( void )
{
int V_3 = F_72 () ;
int V_169 = F_73 ( V_3 ) ;
if ( V_169 )
return 0 ;
while ( ++ V_169 < V_134 )
if ( F_74 ( V_3 + V_169 ) )
return 0 ;
return 1 ;
}
static int F_75 ( struct V_133 * V_154 )
{
struct V_1 * V_2 , * V_170 ;
long V_50 ;
T_1 V_9 ;
F_76 (vcpu, &vc->runnable_threads, arch.run_list)
if ( F_37 ( V_2 -> V_7 . V_171 ) )
return 0 ;
if ( V_134 > 1 && ! F_71 () ) {
F_76 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_7 . V_50 = - V_172 ;
goto V_136;
}
V_154 -> V_167 = 0 ;
V_154 -> V_168 = 0 ;
V_154 -> V_173 = 0 ;
V_154 -> V_174 = 1 ;
V_154 -> V_165 = 0 ;
V_154 -> V_162 = F_72 () ;
F_76 (vcpu, &vc->runnable_threads, arch.run_list)
F_62 ( V_2 ) ;
V_2 = F_57 ( & V_154 -> V_151 , struct V_1 ,
V_7 . V_156 ) ;
F_52 ( & V_154 -> V_51 ) ;
F_77 () ;
F_78 () ;
F_79 ( NULL , V_2 ) ;
F_51 ( & V_154 -> V_51 ) ;
if ( V_154 -> V_168 < V_154 -> V_167 )
F_67 ( V_154 ) ;
V_154 -> V_174 = 2 ;
F_52 ( & V_154 -> V_51 ) ;
F_26 () ;
F_80 () ;
F_81 () ;
F_82 ( V_2 ) ;
V_9 = F_4 () ;
F_76 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_9 < V_2 -> V_7 . V_11 &&
F_5 ( V_2 ) )
F_83 ( V_2 ) ;
if ( ! V_2 -> V_7 . V_25 ) {
if ( F_37 ( V_2 -> V_7 . V_171 ) ) {
V_2 -> V_7 . V_89 -> V_94 = V_116 ;
V_2 -> V_7 . V_50 = - V_117 ;
}
continue;
}
V_50 = F_30 ( V_2 -> V_7 . V_89 , V_2 ,
V_2 -> V_7 . V_171 ) ;
V_2 -> V_7 . V_50 = V_50 ;
V_2 -> V_7 . V_25 = 0 ;
}
F_51 ( & V_154 -> V_51 ) ;
V_136:
V_154 -> V_174 = 0 ;
F_84 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( V_2 -> V_7 . V_50 != V_88 ) {
F_59 ( V_154 , V_2 ) ;
F_58 ( & V_2 -> V_7 . V_149 ) ;
}
}
return 1 ;
}
static int F_85 ( struct V_89 * V_89 , struct V_1 * V_2 )
{
int V_159 ;
int V_175 ;
struct V_133 * V_154 ;
F_86 ( V_176 ) ;
if ( F_37 ( V_177 ) ) {
V_89 -> V_94 = V_116 ;
return - V_117 ;
}
if ( ! V_2 -> V_44 -> V_7 . V_178 && F_42 ( V_179 ) )
return - V_180 ;
V_89 -> V_94 = 0 ;
V_2 -> V_7 . V_50 = V_88 ;
V_2 -> V_7 . V_25 = 0 ;
F_87 ( V_177 ) ;
F_88 ( V_177 ) ;
F_89 ( V_177 ) ;
V_154 = V_2 -> V_7 . V_8 ;
F_51 ( & V_154 -> V_51 ) ;
if ( V_2 -> V_7 . V_147 == V_148 )
-- V_154 -> V_153 ;
V_2 -> V_7 . V_147 = V_158 ;
V_159 = V_154 -> V_155 ;
V_2 -> V_7 . V_171 = V_177 ;
V_2 -> V_7 . V_89 = V_89 ;
V_2 -> V_7 . V_159 = V_159 ;
F_90 ( & V_2 -> V_7 . V_156 , & V_154 -> V_151 ) ;
++ V_154 -> V_155 ;
V_175 = V_181 ;
while ( V_2 -> V_7 . V_147 == V_158 ) {
if ( F_37 ( V_177 ) ) {
if ( ! V_154 -> V_174 ) {
V_89 -> V_94 = V_116 ;
V_2 -> V_7 . V_50 = - V_117 ;
break;
}
V_175 = V_182 ;
F_91 ( V_154 -> V_162 ) ;
}
if ( ! V_154 -> V_174 &&
V_154 -> V_155 + V_154 -> V_153 == V_154 -> V_152 ) {
if ( F_75 ( V_154 ) )
continue;
}
if ( V_154 -> V_174 == 1 && F_92 ( V_154 ) == 0 )
F_62 ( V_2 ) ;
F_93 ( & V_2 -> V_7 . V_149 , & V_176 , V_175 ) ;
F_52 ( & V_154 -> V_51 ) ;
F_94 () ;
F_95 ( & V_2 -> V_7 . V_149 , & V_176 ) ;
F_51 ( & V_154 -> V_51 ) ;
}
if ( V_2 -> V_7 . V_147 == V_158 )
F_59 ( V_154 , V_2 ) ;
F_52 ( & V_154 -> V_51 ) ;
return V_2 -> V_7 . V_50 ;
}
int F_96 ( struct V_89 * V_90 , struct V_1 * V_2 )
{
int V_22 ;
do {
V_22 = F_85 ( V_90 , V_2 ) ;
if ( V_90 -> V_94 == V_108 &&
! ( V_2 -> V_7 . V_20 . V_19 & V_105 ) ) {
V_22 = F_25 ( V_2 ) ;
F_38 ( V_2 ) ;
}
} while ( V_22 == V_88 );
return V_22 ;
}
static long F_97 ( unsigned long V_183 )
{
return F_98 ( ( V_183 >> V_184 )
* sizeof( T_1 ) , V_185 ) / V_185 ;
}
static void F_99 ( struct V_186 * V_187 )
{
struct V_44 * V_44 = V_187 -> V_44 ;
int V_104 ;
F_19 ( & V_44 -> V_51 ) ;
F_61 ( & V_187 -> V_188 ) ;
for ( V_104 = 0 ; V_104 < F_97 ( V_187 -> V_183 ) ; V_104 ++ )
F_100 ( V_187 -> V_189 [ V_104 ] ) ;
F_53 ( V_187 ) ;
F_21 ( & V_44 -> V_51 ) ;
F_101 ( V_44 ) ;
}
static int F_102 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
struct V_186 * V_187 = V_191 -> V_194 -> V_195 ;
struct V_196 * V_196 ;
if ( V_193 -> V_197 >= F_97 ( V_187 -> V_183 ) )
return V_198 ;
V_196 = V_187 -> V_189 [ V_193 -> V_197 ] ;
F_103 ( V_196 ) ;
V_193 -> V_196 = V_196 ;
return 0 ;
}
static int F_104 ( struct V_199 * V_199 , struct V_190 * V_191 )
{
V_191 -> V_200 = & V_201 ;
return 0 ;
}
static int F_105 ( struct V_202 * V_202 , struct V_199 * V_203 )
{
struct V_186 * V_187 = V_203 -> V_195 ;
F_99 ( V_187 ) ;
return 0 ;
}
long F_106 ( struct V_44 * V_44 ,
struct V_204 * args )
{
struct V_186 * V_187 = NULL ;
long V_205 ;
int V_50 = - V_137 ;
int V_104 ;
F_76 (stt, &kvm->arch.spapr_tce_tables, list) {
if ( V_187 -> V_206 == args -> V_206 )
return - V_172 ;
}
V_205 = F_97 ( args -> V_183 ) ;
V_187 = F_44 ( sizeof( * V_187 ) + V_205 * sizeof( struct V_196 * ) ,
V_138 ) ;
if ( ! V_187 )
goto V_207;
V_187 -> V_206 = args -> V_206 ;
V_187 -> V_183 = args -> V_183 ;
V_187 -> V_44 = V_44 ;
for ( V_104 = 0 ; V_104 < V_205 ; V_104 ++ ) {
V_187 -> V_189 [ V_104 ] = F_107 ( V_138 | V_208 ) ;
if ( ! V_187 -> V_189 [ V_104 ] )
goto V_207;
}
F_108 ( V_44 ) ;
F_19 ( & V_44 -> V_51 ) ;
F_109 ( & V_187 -> V_188 , & V_44 -> V_7 . V_209 ) ;
F_21 ( & V_44 -> V_51 ) ;
return F_110 ( L_16 , & V_210 ,
V_187 , V_211 ) ;
V_207:
if ( V_187 ) {
for ( V_104 = 0 ; V_104 < V_205 ; V_104 ++ )
if ( V_187 -> V_189 [ V_104 ] )
F_100 ( V_187 -> V_189 [ V_104 ] ) ;
F_53 ( V_187 ) ;
}
return V_50 ;
}
static inline int F_111 ( unsigned long V_212 )
{
switch ( V_212 ) {
case 32ul << 20 :
if ( F_42 ( V_213 ) )
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
static int F_112 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
struct V_214 * V_215 = V_191 -> V_194 -> V_195 ;
struct V_196 * V_196 ;
if ( V_193 -> V_197 >= V_215 -> V_205 )
return V_198 ;
V_196 = F_113 ( V_215 -> V_216 + V_193 -> V_197 ) ;
F_103 ( V_196 ) ;
V_193 -> V_196 = V_196 ;
return 0 ;
}
static int F_114 ( struct V_199 * V_199 , struct V_190 * V_191 )
{
V_191 -> V_217 |= V_218 ;
V_191 -> V_200 = & V_219 ;
return 0 ;
}
static int F_115 ( struct V_202 * V_202 , struct V_199 * V_203 )
{
struct V_214 * V_215 = V_203 -> V_195 ;
F_116 ( V_215 ) ;
return 0 ;
}
long F_117 ( struct V_44 * V_44 , struct V_220 * V_50 )
{
struct V_214 * V_215 ;
long V_221 ;
V_215 = F_118 () ;
if ( ! V_215 )
return - V_137 ;
V_221 = F_110 ( L_17 , & V_222 , V_215 , V_211 ) ;
if ( V_221 < 0 )
F_116 ( V_215 ) ;
V_50 -> V_212 = V_215 -> V_205 << V_70 ;
return V_221 ;
}
static struct V_196 * F_119 ( unsigned long V_223 )
{
struct V_196 * V_196 [ 1 ] ;
int V_205 ;
F_120 () ;
V_205 = F_121 ( V_223 , 1 , 1 , V_196 ) ;
if ( F_122 ( V_205 != 1 ) )
return 0 ;
return V_196 [ 0 ] ;
}
int F_123 ( struct V_44 * V_44 ,
struct V_224 * V_225 )
{
unsigned long V_226 , V_227 ;
unsigned long V_104 , V_205 , V_228 ;
unsigned long V_229 ;
struct V_230 * V_231 ;
unsigned long V_232 ;
struct V_214 * V_215 = NULL ;
struct V_196 * V_196 ;
V_227 = V_233 ;
V_226 = 1ul << V_227 ;
if ( ( V_225 -> V_234 & ( V_226 - 1 ) ) ||
( V_225 -> V_235 & ( V_226 - 1 ) ) ) {
F_16 ( L_18 ,
V_225 -> V_234 , V_225 -> V_235 ) ;
return - V_131 ;
}
V_205 = V_225 -> V_234 >> V_227 ;
V_228 = ( V_225 -> V_235 + V_225 -> V_234 ) >> V_227 ;
if ( V_228 > ( 1ul << ( V_236 - V_233 ) ) )
return - V_131 ;
if ( V_225 -> V_235 == 0 && V_44 -> V_7 . V_178 )
return - V_131 ;
if ( V_228 > V_44 -> V_7 . V_67 )
V_44 -> V_7 . V_67 = V_228 ;
if ( V_225 -> V_235 == 0 ) {
struct V_190 * V_191 ;
F_124 ( & V_177 -> V_237 -> V_238 ) ;
V_191 = F_125 ( V_177 -> V_237 , V_225 -> V_239 ) ;
if ( V_191 && V_191 -> V_194 &&
V_191 -> V_194 -> V_240 == & V_222 &&
V_225 -> V_239 == V_191 -> V_241 )
V_215 = V_191 -> V_194 -> V_195 ;
F_126 ( & V_177 -> V_237 -> V_238 ) ;
if ( ! V_215 && F_42 ( V_179 ) ) {
F_16 ( L_19 ) ;
return - V_131 ;
}
}
if ( V_215 ) {
unsigned long V_212 ;
unsigned long V_45 ;
long V_242 ;
V_212 = V_215 -> V_205 << V_70 ;
if ( V_212 > V_225 -> V_234 )
V_212 = V_225 -> V_234 ;
V_242 = F_111 ( V_212 ) ;
if ( V_242 < 0 ) {
F_16 ( L_20 , V_212 ) ;
return - V_131 ;
}
F_127 ( & V_215 -> V_243 ) ;
V_44 -> V_7 . V_178 = V_215 ;
V_44 -> V_7 . V_244 = V_212 >> V_227 ;
V_45 = V_44 -> V_7 . V_45 ;
if ( F_42 ( V_179 ) ) {
V_45 &= ~ ( ( 1ul << V_245 ) |
( 3ul << V_246 ) ) ;
V_45 |= ( ( V_242 >> 2 ) << V_245 ) |
( ( V_242 & 3 ) << V_246 ) ;
V_45 |= ( ( V_215 -> V_216 >> ( 26 - V_70 ) ) & 0xffff )
<< V_247 ;
} else {
V_45 &= ~ ( V_248 | V_249 ) ;
V_45 |= V_242 << V_250 ;
V_44 -> V_7 . V_251 = V_44 -> V_7 . V_178 -> V_216 << V_70 ;
}
V_44 -> V_7 . V_45 = V_45 ;
F_128 ( L_21 ,
V_215 -> V_216 << V_70 , V_212 , V_45 ) ;
}
V_229 = V_225 -> V_235 >> V_227 ;
V_231 = V_44 -> V_7 . V_68 + V_229 ;
for ( V_104 = 0 ; V_104 < V_205 ; ++ V_104 , ++ V_229 ) {
if ( V_215 && V_229 < V_44 -> V_7 . V_244 ) {
V_231 [ V_104 ] . V_69 = V_215 -> V_216 +
( V_229 << ( V_227 - V_70 ) ) ;
continue;
}
V_232 = V_225 -> V_239 + ( V_104 << V_227 ) ;
V_196 = F_119 ( V_232 ) ;
if ( ! V_196 ) {
F_16 ( L_22 , V_232 ) ;
goto V_130;
}
if ( ! F_129 ( V_196 ) ||
F_130 ( V_196 ) != ( V_233 - V_70 ) ) {
F_16 ( L_23 ,
V_232 , F_130 ( V_196 ) ) ;
goto V_130;
}
V_231 [ V_104 ] . V_69 = F_131 ( V_196 ) ;
}
return 0 ;
V_130:
return - V_131 ;
}
void F_132 ( struct V_44 * V_44 ,
struct V_224 * V_225 )
{
if ( V_225 -> V_235 == 0 && V_225 -> V_234 != 0 &&
! V_44 -> V_7 . V_178 )
F_133 ( V_44 , V_225 ) ;
}
int F_134 ( struct V_44 * V_44 )
{
long V_22 ;
unsigned long V_205 = 1ul << ( V_236 - V_233 ) ;
long V_130 = - V_137 ;
unsigned long V_45 ;
V_22 = F_135 ( V_44 ) ;
if ( V_22 )
return V_22 ;
F_49 ( & V_44 -> V_7 . V_209 ) ;
V_44 -> V_7 . V_68 = F_44 ( V_205 * sizeof( struct V_230 ) ,
V_138 ) ;
if ( ! V_44 -> V_7 . V_68 ) {
F_16 ( L_24 ,
V_205 * sizeof( struct V_230 ) ) ;
goto V_252;
}
V_44 -> V_7 . V_67 = 0 ;
V_44 -> V_7 . V_66 = 1ul << V_233 ;
V_44 -> V_7 . V_65 = V_233 ;
V_44 -> V_7 . V_178 = NULL ;
V_44 -> V_7 . V_244 = 0 ;
V_44 -> V_7 . V_253 = F_46 ( V_254 ) ;
if ( F_42 ( V_179 ) ) {
unsigned long V_255 = V_44 -> V_7 . V_255 ;
V_44 -> V_7 . V_256 = 0 ;
V_44 -> V_7 . V_257 = V_45 = F_46 ( V_258 ) ;
V_45 &= ~ ( ( 3 << V_259 ) | ( 0xful << V_260 ) ) ;
V_45 |= ( ( V_255 >> 4 ) << V_259 ) |
( ( V_255 & 0xf ) << V_260 ) ;
} else {
V_44 -> V_7 . V_256 = F_46 ( V_261 ) ;
V_44 -> V_7 . V_257 = V_45 = F_46 ( V_262 ) ;
V_45 &= V_263 | V_264 ;
V_45 |= ( 4UL << V_265 ) | V_266 |
V_248 | V_249 ;
}
V_44 -> V_7 . V_45 = V_45 ;
return 0 ;
V_252:
F_136 ( V_44 ) ;
return V_130 ;
}
void F_137 ( struct V_44 * V_44 )
{
struct V_230 * V_231 ;
unsigned long V_104 ;
if ( V_44 -> V_7 . V_68 ) {
V_231 = V_44 -> V_7 . V_68 ;
V_44 -> V_7 . V_68 = NULL ;
for ( V_104 = V_44 -> V_7 . V_244 ; V_104 < V_44 -> V_7 . V_67 ; ++ V_104 )
if ( V_231 [ V_104 ] . V_69 )
F_138 ( F_113 ( V_231 [ V_104 ] . V_69 ) ) ;
F_53 ( V_231 ) ;
}
if ( V_44 -> V_7 . V_178 ) {
F_116 ( V_44 -> V_7 . V_178 ) ;
V_44 -> V_7 . V_178 = NULL ;
}
F_136 ( V_44 ) ;
F_139 ( ! F_140 ( & V_44 -> V_7 . V_209 ) ) ;
}
void F_141 ( struct V_1 * V_2 , T_3 V_267 , T_3 V_268 )
{
}
int F_142 ( struct V_89 * V_90 , struct V_1 * V_2 ,
unsigned int V_269 , int * V_270 )
{
return V_271 ;
}
int F_143 ( struct V_1 * V_2 , int V_272 , int V_273 )
{
return V_271 ;
}
int F_144 ( struct V_1 * V_2 , int V_272 , int V_274 )
{
return V_271 ;
}
static int F_145 ( void )
{
int V_22 ;
V_22 = F_146 ( NULL , sizeof( struct V_1 ) , 0 , V_275 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_147 () ;
return V_22 ;
}
static void F_148 ( void )
{
F_149 () ;
}
