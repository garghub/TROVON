unsigned long F_1 ( void )
{
F_2 ( F_3 ( V_1 ) > V_2 ) ;
return F_3 ( V_1 ) ;
}
int F_4 ( void )
{
return 0 ;
}
static int F_5 ( struct V_3 * V_4 , unsigned long V_5 ,
void * V_6 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
unsigned long long * V_11 = V_6 ;
F_6 (kvm, &vm_list, vm_list) {
V_7 -> V_12 . V_13 -= * V_11 ;
F_7 (i, vcpu, kvm) {
V_9 -> V_12 . V_14 -> V_13 -= * V_11 ;
}
}
return V_15 ;
}
int F_8 ( void )
{
V_16 . V_17 = V_18 ;
F_9 ( & V_16 ) ;
F_10 ( & V_19 ,
& V_20 ) ;
return 0 ;
}
void F_11 ( void )
{
F_12 ( & V_16 ) ;
F_13 ( & V_19 ,
& V_20 ) ;
}
int F_14 ( void * V_21 )
{
V_22 = F_15 ( L_1 , 32 , 1 , 7 * sizeof( long ) ) ;
if ( ! V_22 )
return - V_23 ;
if ( F_16 ( V_22 , & V_24 ) ) {
F_17 ( V_22 ) ;
return - V_23 ;
}
return F_18 ( & V_25 , V_26 ) ;
}
void F_19 ( void )
{
F_17 ( V_22 ) ;
}
long F_20 ( struct V_27 * V_28 ,
unsigned int V_29 , unsigned long V_30 )
{
if ( V_29 == V_31 )
return F_21 () ;
return - V_32 ;
}
int F_22 ( struct V_7 * V_7 , long V_33 )
{
int V_34 ;
switch ( V_33 ) {
case V_35 :
case V_36 :
case V_37 :
#ifdef F_23
case V_38 :
#endif
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
V_34 = 1 ;
break;
case V_55 :
V_34 = V_56 ;
break;
case V_57 :
case V_58 :
V_34 = V_59 ;
break;
case V_60 :
V_34 = V_61 ;
break;
case V_62 :
V_34 = V_63 ;
break;
case V_64 :
V_34 = V_65 ;
break;
default:
V_34 = 0 ;
}
return V_34 ;
}
static void F_24 ( struct V_7 * V_7 ,
struct V_66 * V_67 )
{
T_1 V_68 , V_69 ;
unsigned long V_70 ;
struct V_71 * V_71 = V_7 -> V_12 . V_71 ;
F_25 ( & V_71 -> V_72 -> V_73 ) ;
V_69 = V_67 -> V_74 + V_67 -> V_75 ;
for ( V_68 = V_67 -> V_74 ; V_68 <= V_69 ; V_68 ++ ) {
V_70 = F_26 ( V_67 , V_68 ) ;
if ( F_27 ( V_70 , V_71 ) )
F_28 ( V_7 , V_68 ) ;
}
F_29 ( & V_71 -> V_72 -> V_73 ) ;
}
int F_30 ( struct V_7 * V_7 ,
struct V_76 * log )
{
int V_34 ;
unsigned long V_77 ;
struct V_78 * V_79 ;
struct V_66 * V_67 ;
int V_80 = 0 ;
F_31 ( & V_7 -> V_81 ) ;
V_34 = - V_32 ;
if ( log -> V_82 >= V_61 )
goto V_83;
V_79 = V_78 ( V_7 ) ;
V_67 = F_32 ( V_79 , log -> V_82 ) ;
V_34 = - V_84 ;
if ( ! V_67 -> V_85 )
goto V_83;
F_24 ( V_7 , V_67 ) ;
V_34 = F_33 ( V_7 , log , & V_80 ) ;
if ( V_34 )
goto V_83;
if ( V_80 ) {
V_77 = F_34 ( V_67 ) ;
memset ( V_67 -> V_85 , 0 , V_77 ) ;
}
V_34 = 0 ;
V_83:
F_35 ( & V_7 -> V_81 ) ;
return V_34 ;
}
static int F_36 ( struct V_7 * V_7 , struct V_86 * V_87 )
{
int V_34 ;
if ( V_87 -> V_88 )
return - V_32 ;
switch ( V_87 -> V_87 ) {
case V_47 :
F_37 ( V_7 , 3 , L_2 , L_3 ) ;
V_7 -> V_12 . V_89 = 1 ;
V_34 = 0 ;
break;
case V_51 :
F_37 ( V_7 , 3 , L_2 , L_4 ) ;
V_7 -> V_12 . V_90 = 1 ;
V_34 = 0 ;
break;
case V_64 :
if ( V_65 ) {
F_38 ( V_7 -> V_12 . V_91 . V_92 -> V_93 , 129 ) ;
F_38 ( V_7 -> V_12 . V_91 . V_92 -> V_94 , 129 ) ;
V_34 = 0 ;
} else
V_34 = - V_32 ;
F_37 ( V_7 , 3 , L_5 ,
V_34 ? L_6 : L_7 ) ;
break;
case V_52 :
F_37 ( V_7 , 3 , L_2 , L_8 ) ;
V_7 -> V_12 . V_95 = 1 ;
V_34 = 0 ;
break;
default:
V_34 = - V_32 ;
break;
}
return V_34 ;
}
static int F_39 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
int V_98 ;
switch ( V_97 -> V_97 ) {
case V_99 :
V_98 = 0 ;
F_37 ( V_7 , 3 , L_9 ,
V_7 -> V_12 . V_71 -> V_100 ) ;
if ( F_40 ( V_7 -> V_12 . V_71 -> V_100 , ( V_101 V_102 * ) V_97 -> V_103 ) )
V_98 = - V_104 ;
break;
default:
V_98 = - V_105 ;
break;
}
return V_98 ;
}
static int F_41 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
int V_98 ;
unsigned int V_106 ;
switch ( V_97 -> V_97 ) {
case V_107 :
V_98 = - V_32 ;
if ( ! V_108 || ! V_109 )
break;
V_98 = - V_110 ;
F_37 ( V_7 , 3 , L_2 , L_10 ) ;
F_31 ( & V_7 -> V_111 ) ;
if ( F_42 ( & V_7 -> V_112 ) == 0 ) {
V_7 -> V_12 . V_113 = 1 ;
V_98 = 0 ;
}
F_35 ( & V_7 -> V_111 ) ;
break;
case V_114 :
V_98 = - V_32 ;
if ( ! V_7 -> V_12 . V_113 )
break;
F_37 ( V_7 , 3 , L_2 , L_11 ) ;
F_31 ( & V_7 -> V_111 ) ;
V_106 = F_43 ( & V_7 -> V_115 ) ;
F_44 ( V_7 -> V_12 . V_71 -> V_72 ) ;
F_45 ( & V_7 -> V_115 , V_106 ) ;
F_35 ( & V_7 -> V_111 ) ;
V_98 = 0 ;
break;
case V_99 : {
unsigned long V_116 ;
if ( F_46 ( V_7 ) )
return - V_32 ;
if ( F_47 ( V_116 , ( V_101 V_102 * ) V_97 -> V_103 ) )
return - V_104 ;
if ( V_116 > V_7 -> V_12 . V_71 -> V_100 )
return - V_117 ;
V_98 = - V_110 ;
F_31 ( & V_7 -> V_111 ) ;
if ( F_42 ( & V_7 -> V_112 ) == 0 ) {
struct V_71 * V_118 = F_48 ( V_119 -> V_72 , V_116 ) ;
if ( ! V_118 ) {
V_98 = - V_23 ;
} else {
F_49 ( V_7 -> V_12 . V_71 ) ;
V_118 -> V_120 = V_7 ;
V_7 -> V_12 . V_71 = V_118 ;
V_98 = 0 ;
}
}
F_35 ( & V_7 -> V_111 ) ;
F_37 ( V_7 , 3 , L_12 , V_116 ) ;
break;
}
default:
V_98 = - V_105 ;
break;
}
return V_98 ;
}
static int F_50 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
struct V_8 * V_9 ;
int V_10 ;
if ( ! F_51 ( V_7 , 76 ) )
return - V_32 ;
F_31 ( & V_7 -> V_111 ) ;
switch ( V_97 -> V_97 ) {
case V_121 :
F_52 (
V_7 -> V_12 . V_122 . V_123 -> V_124 ,
sizeof( V_7 -> V_12 . V_122 . V_123 -> V_124 ) ) ;
V_7 -> V_12 . V_122 . V_125 = 1 ;
F_37 ( V_7 , 3 , L_2 , L_13 ) ;
break;
case V_126 :
F_52 (
V_7 -> V_12 . V_122 . V_123 -> V_127 ,
sizeof( V_7 -> V_12 . V_122 . V_123 -> V_127 ) ) ;
V_7 -> V_12 . V_122 . V_128 = 1 ;
F_37 ( V_7 , 3 , L_2 , L_14 ) ;
break;
case V_129 :
V_7 -> V_12 . V_122 . V_125 = 0 ;
memset ( V_7 -> V_12 . V_122 . V_123 -> V_124 , 0 ,
sizeof( V_7 -> V_12 . V_122 . V_123 -> V_124 ) ) ;
F_37 ( V_7 , 3 , L_2 , L_15 ) ;
break;
case V_130 :
V_7 -> V_12 . V_122 . V_128 = 0 ;
memset ( V_7 -> V_12 . V_122 . V_123 -> V_127 , 0 ,
sizeof( V_7 -> V_12 . V_122 . V_123 -> V_127 ) ) ;
F_37 ( V_7 , 3 , L_2 , L_16 ) ;
break;
default:
F_35 ( & V_7 -> V_111 ) ;
return - V_105 ;
}
F_7 (i, vcpu, kvm) {
F_53 ( V_9 ) ;
F_54 ( V_9 ) ;
}
F_35 ( & V_7 -> V_111 ) ;
return 0 ;
}
static int F_55 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
T_2 V_131 ;
if ( F_56 ( & V_131 , ( void V_102 * ) V_97 -> V_103 ,
sizeof( V_131 ) ) )
return - V_104 ;
if ( V_131 != 0 )
return - V_32 ;
F_37 ( V_7 , 3 , L_17 , V_131 ) ;
return 0 ;
}
static int F_57 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
struct V_8 * V_132 ;
unsigned int V_133 ;
V_101 V_134 , V_135 ;
int V_34 ;
if ( F_56 ( & V_135 , ( void V_102 * ) V_97 -> V_103 , sizeof( V_135 ) ) )
return - V_104 ;
V_34 = F_58 ( & V_134 ) ;
if ( V_34 )
return V_34 ;
F_31 ( & V_7 -> V_111 ) ;
F_59 () ;
V_7 -> V_12 . V_13 = V_135 - V_134 ;
F_60 ( V_7 ) ;
F_7 (vcpu_idx, cur_vcpu, kvm)
V_132 -> V_12 . V_14 -> V_13 = V_7 -> V_12 . V_13 ;
F_61 ( V_7 ) ;
F_62 () ;
F_35 ( & V_7 -> V_111 ) ;
F_37 ( V_7 , 3 , L_18 , V_135 ) ;
return 0 ;
}
static int F_63 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
int V_98 ;
if ( V_97 -> V_88 )
return - V_32 ;
switch ( V_97 -> V_97 ) {
case V_136 :
V_98 = F_55 ( V_7 , V_97 ) ;
break;
case V_137 :
V_98 = F_57 ( V_7 , V_97 ) ;
break;
default:
V_98 = - V_105 ;
break;
}
return V_98 ;
}
static int F_64 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
T_2 V_131 = 0 ;
if ( F_65 ( ( void V_102 * ) V_97 -> V_103 , & V_131 ,
sizeof( V_131 ) ) )
return - V_104 ;
F_37 ( V_7 , 3 , L_19 , V_131 ) ;
return 0 ;
}
static int F_66 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
V_101 V_134 , V_135 ;
int V_34 ;
V_34 = F_58 ( & V_134 ) ;
if ( V_34 )
return V_34 ;
F_59 () ;
V_135 = V_134 + V_7 -> V_12 . V_13 ;
F_62 () ;
if ( F_65 ( ( void V_102 * ) V_97 -> V_103 , & V_135 , sizeof( V_135 ) ) )
return - V_104 ;
F_37 ( V_7 , 3 , L_20 , V_135 ) ;
return 0 ;
}
static int F_67 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
int V_98 ;
if ( V_97 -> V_88 )
return - V_32 ;
switch ( V_97 -> V_97 ) {
case V_136 :
V_98 = F_64 ( V_7 , V_97 ) ;
break;
case V_137 :
V_98 = F_66 ( V_7 , V_97 ) ;
break;
default:
V_98 = - V_105 ;
break;
}
return V_98 ;
}
static int F_68 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
struct V_138 * V_139 ;
int V_98 = 0 ;
F_31 ( & V_7 -> V_111 ) ;
if ( F_42 ( & V_7 -> V_112 ) ) {
V_98 = - V_110 ;
goto V_83;
}
V_139 = F_69 ( sizeof( * V_139 ) , V_140 ) ;
if ( ! V_139 ) {
V_98 = - V_23 ;
goto V_83;
}
if ( ! F_56 ( V_139 , ( void V_102 * ) V_97 -> V_103 ,
sizeof( * V_139 ) ) ) {
memcpy ( & V_7 -> V_12 . V_91 . V_141 , & V_139 -> V_142 ,
sizeof( struct V_142 ) ) ;
V_7 -> V_12 . V_91 . V_143 = V_139 -> V_143 ;
memcpy ( V_7 -> V_12 . V_91 . V_92 -> V_94 , V_139 -> V_144 ,
V_145 ) ;
} else
V_98 = - V_104 ;
F_70 ( V_139 ) ;
V_83:
F_35 ( & V_7 -> V_111 ) ;
return V_98 ;
}
static int F_71 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
int V_98 = - V_105 ;
switch ( V_97 -> V_97 ) {
case V_146 :
V_98 = F_68 ( V_7 , V_97 ) ;
break;
}
return V_98 ;
}
static int F_72 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
struct V_138 * V_139 ;
int V_98 = 0 ;
V_139 = F_69 ( sizeof( * V_139 ) , V_140 ) ;
if ( ! V_139 ) {
V_98 = - V_23 ;
goto V_83;
}
memcpy ( & V_139 -> V_142 , & V_7 -> V_12 . V_91 . V_141 , sizeof( struct V_142 ) ) ;
V_139 -> V_143 = V_7 -> V_12 . V_91 . V_143 ;
memcpy ( & V_139 -> V_144 , V_7 -> V_12 . V_91 . V_92 -> V_94 , V_145 ) ;
if ( F_65 ( ( void V_102 * ) V_97 -> V_103 , V_139 , sizeof( * V_139 ) ) )
V_98 = - V_104 ;
F_70 ( V_139 ) ;
V_83:
return V_98 ;
}
static int F_73 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
struct V_147 * V_148 ;
int V_98 = 0 ;
V_148 = F_69 ( sizeof( * V_148 ) , V_140 ) ;
if ( ! V_148 ) {
V_98 = - V_23 ;
goto V_83;
}
F_74 ( (struct V_142 * ) & V_148 -> V_142 ) ;
V_148 -> V_143 = V_149 . V_143 ;
memcpy ( & V_148 -> V_150 , V_7 -> V_12 . V_91 . V_92 -> V_93 ,
V_145 ) ;
memcpy ( ( unsigned long * ) & V_148 -> V_144 , V_151 . V_152 ,
V_145 ) ;
if ( F_65 ( ( void V_102 * ) V_97 -> V_103 , V_148 , sizeof( * V_148 ) ) )
V_98 = - V_104 ;
F_70 ( V_148 ) ;
V_83:
return V_98 ;
}
static int F_75 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
int V_98 = - V_105 ;
switch ( V_97 -> V_97 ) {
case V_146 :
V_98 = F_72 ( V_7 , V_97 ) ;
break;
case V_153 :
V_98 = F_73 ( V_7 , V_97 ) ;
break;
}
return V_98 ;
}
static int F_76 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
int V_98 ;
switch ( V_97 -> V_154 ) {
case V_155 :
V_98 = F_41 ( V_7 , V_97 ) ;
break;
case V_156 :
V_98 = F_63 ( V_7 , V_97 ) ;
break;
case V_157 :
V_98 = F_71 ( V_7 , V_97 ) ;
break;
case V_158 :
V_98 = F_50 ( V_7 , V_97 ) ;
break;
default:
V_98 = - V_105 ;
break;
}
return V_98 ;
}
static int F_77 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
int V_98 ;
switch ( V_97 -> V_154 ) {
case V_155 :
V_98 = F_39 ( V_7 , V_97 ) ;
break;
case V_156 :
V_98 = F_67 ( V_7 , V_97 ) ;
break;
case V_157 :
V_98 = F_75 ( V_7 , V_97 ) ;
break;
default:
V_98 = - V_105 ;
break;
}
return V_98 ;
}
static int F_78 ( struct V_7 * V_7 , struct V_96 * V_97 )
{
int V_98 ;
switch ( V_97 -> V_154 ) {
case V_155 :
switch ( V_97 -> V_97 ) {
case V_107 :
case V_114 :
case V_99 :
V_98 = 0 ;
break;
default:
V_98 = - V_105 ;
break;
}
break;
case V_156 :
switch ( V_97 -> V_97 ) {
case V_137 :
case V_136 :
V_98 = 0 ;
break;
default:
V_98 = - V_105 ;
break;
}
break;
case V_157 :
switch ( V_97 -> V_97 ) {
case V_146 :
case V_153 :
V_98 = 0 ;
break;
default:
V_98 = - V_105 ;
break;
}
break;
case V_158 :
switch ( V_97 -> V_97 ) {
case V_121 :
case V_126 :
case V_129 :
case V_130 :
V_98 = 0 ;
break;
default:
V_98 = - V_105 ;
break;
}
break;
default:
V_98 = - V_105 ;
break;
}
return V_98 ;
}
static long F_79 ( struct V_7 * V_7 , struct V_159 * args )
{
T_3 * V_160 ;
T_4 V_161 ;
unsigned long V_162 ;
int V_10 , V_34 = 0 ;
if ( args -> V_88 != 0 )
return - V_32 ;
if ( ! F_80 ( V_119 -> V_72 ) )
return V_163 ;
if ( args -> V_164 < 1 || args -> V_164 > V_165 )
return - V_32 ;
V_160 = F_81 ( args -> V_164 , sizeof( T_3 ) ,
V_140 | V_166 ) ;
if ( ! V_160 )
V_160 = F_82 ( sizeof( T_3 ) * args -> V_164 ) ;
if ( ! V_160 )
return - V_23 ;
for ( V_10 = 0 ; V_10 < args -> V_164 ; V_10 ++ ) {
V_161 = F_83 ( V_7 , args -> V_167 + V_10 ) ;
if ( F_84 ( V_161 ) ) {
V_34 = - V_104 ;
goto V_83;
}
V_162 = F_85 ( V_119 -> V_72 , V_161 ) ;
if ( F_86 ( V_162 ) ) {
V_34 = V_162 ;
goto V_83;
}
V_160 [ V_10 ] = V_162 ;
}
V_34 = F_65 ( ( T_3 V_102 * ) args -> V_168 , V_160 ,
sizeof( T_3 ) * args -> V_164 ) ;
if ( V_34 )
V_34 = - V_104 ;
V_83:
F_87 ( V_160 ) ;
return V_34 ;
}
static long F_88 ( struct V_7 * V_7 , struct V_159 * args )
{
T_3 * V_160 ;
T_4 V_161 ;
int V_10 , V_34 = 0 ;
if ( args -> V_88 != 0 )
return - V_32 ;
if ( args -> V_164 < 1 || args -> V_164 > V_165 )
return - V_32 ;
V_160 = F_81 ( args -> V_164 , sizeof( T_3 ) ,
V_140 | V_166 ) ;
if ( ! V_160 )
V_160 = F_82 ( sizeof( T_3 ) * args -> V_164 ) ;
if ( ! V_160 )
return - V_23 ;
V_34 = F_56 ( V_160 , ( T_3 V_102 * ) args -> V_168 ,
sizeof( T_3 ) * args -> V_164 ) ;
if ( V_34 ) {
V_34 = - V_104 ;
goto V_83;
}
V_34 = F_89 () ;
if ( V_34 )
goto V_83;
for ( V_10 = 0 ; V_10 < args -> V_164 ; V_10 ++ ) {
V_161 = F_83 ( V_7 , args -> V_167 + V_10 ) ;
if ( F_84 ( V_161 ) ) {
V_34 = - V_104 ;
goto V_83;
}
if ( V_160 [ V_10 ] & 0x01 ) {
V_34 = - V_32 ;
goto V_83;
}
V_34 = F_90 ( V_119 -> V_72 , V_161 ,
( unsigned long ) V_160 [ V_10 ] , 0 ) ;
if ( V_34 )
goto V_83;
}
V_83:
F_87 ( V_160 ) ;
return V_34 ;
}
long F_91 ( struct V_27 * V_28 ,
unsigned int V_29 , unsigned long V_30 )
{
struct V_7 * V_7 = V_28 -> V_169 ;
void V_102 * V_170 = ( void V_102 * ) V_30 ;
struct V_96 V_97 ;
int V_34 ;
switch ( V_29 ) {
case V_171 : {
struct V_172 V_173 ;
V_34 = - V_104 ;
if ( F_56 ( & V_173 , V_170 , sizeof( V_173 ) ) )
break;
V_34 = F_92 ( V_7 , & V_173 ) ;
break;
}
case V_174 : {
struct V_86 V_87 ;
V_34 = - V_104 ;
if ( F_56 ( & V_87 , V_170 , sizeof( V_87 ) ) )
break;
V_34 = F_36 ( V_7 , & V_87 ) ;
break;
}
case V_175 : {
struct V_176 V_177 ;
V_34 = - V_32 ;
if ( V_7 -> V_12 . V_89 ) {
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_34 = F_93 ( V_7 , & V_177 , 0 , 0 ) ;
}
break;
}
case V_178 : {
V_34 = - V_104 ;
if ( F_56 ( & V_97 , ( void V_102 * ) V_30 , sizeof( V_97 ) ) )
break;
V_34 = F_76 ( V_7 , & V_97 ) ;
break;
}
case V_179 : {
V_34 = - V_104 ;
if ( F_56 ( & V_97 , ( void V_102 * ) V_30 , sizeof( V_97 ) ) )
break;
V_34 = F_77 ( V_7 , & V_97 ) ;
break;
}
case V_180 : {
V_34 = - V_104 ;
if ( F_56 ( & V_97 , ( void V_102 * ) V_30 , sizeof( V_97 ) ) )
break;
V_34 = F_78 ( V_7 , & V_97 ) ;
break;
}
case V_181 : {
struct V_159 args ;
V_34 = - V_104 ;
if ( F_56 ( & args , V_170 ,
sizeof( struct V_159 ) ) )
break;
V_34 = F_79 ( V_7 , & args ) ;
break;
}
case V_182 : {
struct V_159 args ;
V_34 = - V_104 ;
if ( F_56 ( & args , V_170 ,
sizeof( struct V_159 ) ) )
break;
V_34 = F_88 ( V_7 , & args ) ;
break;
}
default:
V_34 = - V_183 ;
}
return V_34 ;
}
static int F_94 ( T_2 * V_184 )
{
T_5 V_185 = 0x04000000UL ;
T_5 V_186 = 0 ;
memset ( V_184 , 0 , 128 ) ;
asm volatile(
"lgr 0,%1\n"
"lgr 2,%2\n"
".long 0xb2af0000\n"
"0: ipm %0\n"
"srl %0,28\n"
"1:\n"
EX_TABLE(0b, 1b)
: "+r" (cc)
: "r" (fcn_code), "r" (config)
: "cc", "0", "2", "memory"
);
return V_186 ;
}
static int F_95 ( void )
{
T_2 V_184 [ 128 ] ;
int V_186 ;
if ( F_96 ( 2 ) && F_96 ( 12 ) ) {
V_186 = F_94 ( V_184 ) ;
if ( V_186 )
F_97 ( L_21 , V_186 ) ;
else
return V_184 [ 0 ] & 0x40 ;
}
return 0 ;
}
static void F_98 ( struct V_7 * V_7 )
{
V_7 -> V_12 . V_122 . V_187 = ( V_188 ) ( unsigned long ) V_7 -> V_12 . V_122 . V_123 ;
if ( F_95 () )
V_7 -> V_12 . V_122 . V_187 |= V_189 ;
else
V_7 -> V_12 . V_122 . V_187 |= V_190 ;
}
static void F_99 ( struct V_142 * V_141 )
{
F_74 ( V_141 ) ;
V_141 -> V_191 = 0xff ;
}
static int F_100 ( struct V_7 * V_7 )
{
if ( ! F_51 ( V_7 , 76 ) )
return 0 ;
V_7 -> V_12 . V_122 . V_123 = F_69 ( sizeof( * V_7 -> V_12 . V_122 . V_123 ) ,
V_140 | V_192 ) ;
if ( ! V_7 -> V_12 . V_122 . V_123 )
return - V_23 ;
F_98 ( V_7 ) ;
V_7 -> V_12 . V_122 . V_125 = 1 ;
V_7 -> V_12 . V_122 . V_128 = 1 ;
F_52 ( V_7 -> V_12 . V_122 . V_123 -> V_124 ,
sizeof( V_7 -> V_12 . V_122 . V_123 -> V_124 ) ) ;
F_52 ( V_7 -> V_12 . V_122 . V_123 -> V_127 ,
sizeof( V_7 -> V_12 . V_122 . V_123 -> V_127 ) ) ;
return 0 ;
}
int F_101 ( struct V_7 * V_7 , unsigned long type )
{
int V_10 , V_193 ;
char V_194 [ 16 ] ;
static unsigned long V_195 ;
V_193 = - V_32 ;
#ifdef F_23
if ( type & ~ V_196 )
goto V_197;
if ( ( type & V_196 ) && ( ! F_102 ( V_198 ) ) )
goto V_197;
#else
if ( type )
goto V_197;
#endif
V_193 = F_21 () ;
if ( V_193 )
goto V_197;
V_193 = - V_23 ;
V_7 -> V_12 . V_199 = (struct V_200 * ) F_103 ( V_140 ) ;
if ( ! V_7 -> V_12 . V_199 )
goto V_197;
F_104 ( & V_201 ) ;
V_195 = ( V_195 + 16 ) & 0x7f0 ;
V_7 -> V_12 . V_199 = (struct V_200 * ) ( ( char * ) V_7 -> V_12 . V_199 + V_195 ) ;
F_105 ( & V_201 ) ;
sprintf ( V_194 , L_22 , V_119 -> V_202 ) ;
V_7 -> V_12 . V_203 = F_15 ( V_194 , 32 , 1 , 7 * sizeof( long ) ) ;
if ( ! V_7 -> V_12 . V_203 )
goto V_197;
V_7 -> V_12 . V_91 . V_92 =
(struct V_204 * ) F_103 ( V_140 | V_192 ) ;
if ( ! V_7 -> V_12 . V_91 . V_92 )
goto V_197;
memcpy ( V_7 -> V_12 . V_91 . V_92 -> V_93 , V_151 . V_152 ,
V_145 ) ;
for ( V_10 = 0 ; V_10 < V_205 ; V_10 ++ ) {
if ( V_10 < F_1 () )
V_7 -> V_12 . V_91 . V_92 -> V_93 [ V_10 ] &= V_1 [ V_10 ] ;
else
V_7 -> V_12 . V_91 . V_92 -> V_93 [ V_10 ] = 0UL ;
}
memcpy ( V_7 -> V_12 . V_91 . V_92 -> V_94 , V_7 -> V_12 . V_91 . V_92 -> V_93 ,
V_145 ) ;
F_99 ( & V_7 -> V_12 . V_91 . V_141 ) ;
V_7 -> V_12 . V_91 . V_143 = V_149 . V_143 & 0x0fff ;
if ( F_100 ( V_7 ) < 0 )
goto V_197;
F_106 ( & V_7 -> V_12 . V_206 . V_111 ) ;
for ( V_10 = 0 ; V_10 < V_207 ; V_10 ++ )
F_107 ( & V_7 -> V_12 . V_206 . V_208 [ V_10 ] ) ;
F_108 ( & V_7 -> V_12 . V_209 ) ;
F_109 ( & V_7 -> V_12 . V_210 ) ;
F_16 ( V_7 -> V_12 . V_203 , & V_24 ) ;
F_37 ( V_7 , 3 , L_23 , type ) ;
if ( type & V_196 ) {
V_7 -> V_12 . V_71 = NULL ;
} else {
V_7 -> V_12 . V_71 = F_48 ( V_119 -> V_72 , ( 1UL << 44 ) - 1 ) ;
if ( ! V_7 -> V_12 . V_71 )
goto V_197;
V_7 -> V_12 . V_71 -> V_120 = V_7 ;
V_7 -> V_12 . V_71 -> V_211 = 0 ;
}
V_7 -> V_12 . V_212 = 0 ;
V_7 -> V_12 . V_89 = 0 ;
V_7 -> V_12 . V_13 = 0 ;
F_106 ( & V_7 -> V_12 . V_213 ) ;
F_110 ( 3 , L_24 , V_7 , V_119 -> V_202 ) ;
return 0 ;
V_197:
F_70 ( V_7 -> V_12 . V_122 . V_123 ) ;
F_111 ( ( unsigned long ) V_7 -> V_12 . V_91 . V_92 ) ;
F_17 ( V_7 -> V_12 . V_203 ) ;
F_111 ( ( unsigned long ) ( V_7 -> V_12 . V_199 ) ) ;
F_110 ( 3 , L_25 , V_193 ) ;
return V_193 ;
}
void F_112 ( struct V_8 * V_9 )
{
F_113 ( V_9 , 3 , L_2 , L_26 ) ;
F_114 ( V_9 -> V_214 ) ;
F_115 ( V_9 ) ;
F_116 ( V_9 ) ;
if ( ! F_46 ( V_9 -> V_7 ) ) {
F_117 ( 63 - V_9 -> V_214 ,
( unsigned long * ) & V_9 -> V_7 -> V_12 . V_199 -> V_215 ) ;
if ( V_9 -> V_7 -> V_12 . V_199 -> V_216 [ V_9 -> V_214 ] . V_217 ==
( V_218 ) V_9 -> V_12 . V_14 )
V_9 -> V_7 -> V_12 . V_199 -> V_216 [ V_9 -> V_214 ] . V_217 = 0 ;
}
F_118 () ;
if ( F_46 ( V_9 -> V_7 ) )
F_49 ( V_9 -> V_12 . V_71 ) ;
if ( V_9 -> V_7 -> V_12 . V_113 )
F_119 ( V_9 ) ;
F_111 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
F_120 ( V_9 ) ;
F_121 ( V_219 , V_9 ) ;
}
static void F_122 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm)
F_112 ( V_9 ) ;
F_31 ( & V_7 -> V_111 ) ;
for ( V_10 = 0 ; V_10 < F_42 ( & V_7 -> V_112 ) ; V_10 ++ )
V_7 -> V_220 [ V_10 ] = NULL ;
F_123 ( & V_7 -> V_112 , 0 ) ;
F_35 ( & V_7 -> V_111 ) ;
}
void F_124 ( struct V_7 * V_7 )
{
F_122 ( V_7 ) ;
F_111 ( ( unsigned long ) V_7 -> V_12 . V_91 . V_92 ) ;
F_111 ( ( unsigned long ) ( V_7 -> V_12 . V_199 ) ) ;
F_17 ( V_7 -> V_12 . V_203 ) ;
F_70 ( V_7 -> V_12 . V_122 . V_123 ) ;
if ( ! F_46 ( V_7 ) )
F_49 ( V_7 -> V_12 . V_71 ) ;
F_125 ( V_7 ) ;
F_126 ( V_7 ) ;
F_110 ( 3 , L_27 , V_7 ) ;
}
static int F_127 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_71 = F_48 ( V_119 -> V_72 , - 1UL ) ;
if ( ! V_9 -> V_12 . V_71 )
return - V_23 ;
V_9 -> V_12 . V_71 -> V_120 = V_9 -> V_7 ;
return 0 ;
}
int F_128 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_221 = V_222 ;
F_116 ( V_9 ) ;
V_9 -> V_223 -> V_224 = V_225 |
V_226 |
V_227 |
V_228 |
V_229 |
V_230 ;
if ( F_51 ( V_9 -> V_7 , 129 ) )
V_9 -> V_223 -> V_224 |= V_231 ;
if ( F_46 ( V_9 -> V_7 ) )
return F_127 ( V_9 ) ;
return 0 ;
}
static inline void F_129 ( struct V_232 * V_233 )
{
V_233 -> V_234 = V_119 -> V_235 . V_232 . V_234 ;
V_233 -> V_88 = V_119 -> V_235 . V_232 . V_88 ;
V_233 -> V_236 = V_119 -> V_235 . V_232 . V_236 ;
}
static inline void F_130 ( struct V_232 * V_237 )
{
V_119 -> V_235 . V_232 . V_234 = V_237 -> V_234 ;
V_119 -> V_235 . V_232 . V_88 = V_237 -> V_88 ;
V_119 -> V_235 . V_232 . V_236 = V_237 -> V_236 ;
}
void F_131 ( struct V_8 * V_9 , int V_216 )
{
F_132 () ;
F_129 ( & V_9 -> V_12 . V_238 ) ;
if ( F_51 ( V_9 -> V_7 , 129 ) ) {
V_119 -> V_235 . V_232 . V_234 = V_9 -> V_223 -> V_239 . V_236 . V_234 ;
V_119 -> V_235 . V_232 . V_88 = V_240 ;
V_119 -> V_235 . V_232 . V_241 =
( V_242 * ) & V_9 -> V_223 -> V_239 . V_236 . V_243 ;
F_133 () ;
} else
F_130 ( & V_9 -> V_12 . V_244 ) ;
if ( F_134 ( V_119 -> V_235 . V_232 . V_234 ) )
V_119 -> V_235 . V_232 . V_234 = 0 ;
F_135 ( V_9 -> V_12 . V_245 ) ;
F_136 ( V_9 -> V_223 -> V_239 . V_236 . V_246 ) ;
F_137 ( V_9 -> V_12 . V_71 ) ;
F_138 ( V_247 , & V_9 -> V_12 . V_14 -> V_248 ) ;
}
void F_139 ( struct V_8 * V_9 )
{
F_140 ( V_247 , & V_9 -> V_12 . V_14 -> V_248 ) ;
F_141 ( V_9 -> V_12 . V_71 ) ;
F_132 () ;
if ( F_51 ( V_9 -> V_7 , 129 ) )
V_9 -> V_223 -> V_239 . V_236 . V_234 = V_119 -> V_235 . V_232 . V_234 ;
else
F_129 ( & V_9 -> V_12 . V_244 ) ;
F_130 ( & V_9 -> V_12 . V_238 ) ;
F_135 ( V_9 -> V_223 -> V_239 . V_236 . V_246 ) ;
F_136 ( V_9 -> V_12 . V_245 ) ;
}
static void F_142 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_249 . V_93 = 0UL ;
V_9 -> V_12 . V_14 -> V_249 . V_103 = 0UL ;
F_143 ( V_9 , 0 ) ;
V_9 -> V_12 . V_14 -> V_250 = 0UL ;
V_9 -> V_12 . V_14 -> V_251 = 0UL ;
V_9 -> V_12 . V_14 -> V_252 = 0 ;
memset ( V_9 -> V_12 . V_14 -> V_253 , 0 , 16 * sizeof( V_218 ) ) ;
V_9 -> V_12 . V_14 -> V_253 [ 0 ] = 0xE0UL ;
V_9 -> V_12 . V_14 -> V_253 [ 14 ] = 0xC2000000UL ;
V_9 -> V_12 . V_244 . V_234 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_9 -> V_12 . V_14 -> V_254 = 1 ;
V_9 -> V_12 . V_14 -> V_255 = 0 ;
V_9 -> V_12 . V_221 = V_222 ;
F_116 ( V_9 ) ;
if ( ! F_144 ( V_9 -> V_7 ) )
F_145 ( V_9 ) ;
F_115 ( V_9 ) ;
}
void F_146 ( struct V_8 * V_9 )
{
F_31 ( & V_9 -> V_7 -> V_111 ) ;
F_59 () ;
V_9 -> V_12 . V_14 -> V_13 = V_9 -> V_7 -> V_12 . V_13 ;
F_62 () ;
F_35 ( & V_9 -> V_7 -> V_111 ) ;
if ( ! F_46 ( V_9 -> V_7 ) )
V_9 -> V_12 . V_71 = V_9 -> V_7 -> V_12 . V_71 ;
}
static void F_53 ( struct V_8 * V_9 )
{
if ( ! F_51 ( V_9 -> V_7 , 76 ) )
return;
V_9 -> V_12 . V_14 -> V_256 &= ~ ( V_257 | V_258 ) ;
if ( V_9 -> V_7 -> V_12 . V_122 . V_125 )
V_9 -> V_12 . V_14 -> V_256 |= V_257 ;
if ( V_9 -> V_7 -> V_12 . V_122 . V_128 )
V_9 -> V_12 . V_14 -> V_256 |= V_258 ;
V_9 -> V_12 . V_14 -> V_187 = V_9 -> V_7 -> V_12 . V_122 . V_187 ;
}
void F_119 ( struct V_8 * V_9 )
{
F_111 ( V_9 -> V_12 . V_14 -> V_259 ) ;
V_9 -> V_12 . V_14 -> V_259 = 0 ;
}
int F_147 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_259 = F_103 ( V_140 ) ;
if ( ! V_9 -> V_12 . V_14 -> V_259 )
return - V_23 ;
V_9 -> V_12 . V_14 -> V_260 |= 0x80 ;
V_9 -> V_12 . V_14 -> V_260 &= ~ 0x08 ;
return 0 ;
}
static void F_148 ( struct V_8 * V_9 )
{
struct V_261 * V_91 = & V_9 -> V_7 -> V_12 . V_91 ;
V_9 -> V_12 . V_141 = V_91 -> V_141 ;
V_9 -> V_12 . V_14 -> V_143 = V_91 -> V_143 ;
V_9 -> V_12 . V_14 -> V_92 = ( int ) ( long ) V_91 -> V_92 -> V_94 ;
}
int F_149 ( struct V_8 * V_9 )
{
int V_193 = 0 ;
F_123 ( & V_9 -> V_12 . V_14 -> V_248 , V_262 |
V_263 |
V_264 ) ;
if ( F_51 ( V_9 -> V_7 , 78 ) )
F_138 ( V_265 , & V_9 -> V_12 . V_14 -> V_248 ) ;
else if ( F_51 ( V_9 -> V_7 , 8 ) )
F_138 ( V_266 , & V_9 -> V_12 . V_14 -> V_248 ) ;
F_148 ( V_9 ) ;
V_9 -> V_12 . V_14 -> V_267 = 6 ;
if ( F_51 ( V_9 -> V_7 , 50 ) && F_51 ( V_9 -> V_7 , 73 ) )
V_9 -> V_12 . V_14 -> V_267 |= 0x10 ;
V_9 -> V_12 . V_14 -> V_260 = 8 ;
V_9 -> V_12 . V_14 -> V_268 = 0xC1002000U ;
if ( V_149 . V_269 )
V_9 -> V_12 . V_14 -> V_268 |= 1 ;
if ( V_149 . V_270 )
V_9 -> V_12 . V_14 -> V_268 |= 0x10000000U ;
if ( F_51 ( V_9 -> V_7 , 129 ) ) {
V_9 -> V_12 . V_14 -> V_268 |= 0x00020000 ;
V_9 -> V_12 . V_14 -> V_271 |= 0x20000000 ;
}
V_9 -> V_12 . V_14 -> V_272 |= V_273 | V_274 | V_275 ;
if ( V_9 -> V_7 -> V_12 . V_113 ) {
V_193 = F_147 ( V_9 ) ;
if ( V_193 )
return V_193 ;
}
F_150 ( & V_9 -> V_12 . V_276 , V_277 , V_278 ) ;
V_9 -> V_12 . V_276 . V_279 = V_280 ;
F_53 ( V_9 ) ;
return V_193 ;
}
struct V_8 * F_151 ( struct V_7 * V_7 ,
unsigned int V_281 )
{
struct V_8 * V_9 ;
struct V_282 * V_282 ;
int V_193 = - V_32 ;
if ( V_281 >= V_59 )
goto V_83;
V_193 = - V_23 ;
V_9 = F_152 ( V_219 , V_140 ) ;
if ( ! V_9 )
goto V_83;
V_282 = (struct V_282 * ) F_103 ( V_140 ) ;
if ( ! V_282 )
goto V_283;
V_9 -> V_12 . V_14 = & V_282 -> V_14 ;
V_9 -> V_12 . V_14 -> V_284 = ( unsigned long ) & V_282 -> V_285 ;
V_9 -> V_12 . V_14 -> V_286 = V_281 ;
if ( ! F_46 ( V_7 ) ) {
if ( ! V_7 -> V_12 . V_199 ) {
F_153 ( 1 ) ;
goto V_283;
}
if ( ! V_7 -> V_12 . V_199 -> V_216 [ V_281 ] . V_217 )
V_7 -> V_12 . V_199 -> V_216 [ V_281 ] . V_217 =
( V_218 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_287 =
( V_188 ) ( ( ( V_218 ) V_7 -> V_12 . V_199 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_288 = ( V_188 ) ( V_218 ) V_7 -> V_12 . V_199 ;
F_154 ( 63 - V_281 , ( unsigned long * ) & V_7 -> V_12 . V_199 -> V_215 ) ;
}
F_106 ( & V_9 -> V_12 . V_289 . V_111 ) ;
V_9 -> V_12 . V_289 . V_206 = & V_7 -> V_12 . V_206 ;
V_9 -> V_12 . V_289 . V_290 = & V_9 -> V_290 ;
V_9 -> V_12 . V_289 . V_248 = & V_9 -> V_12 . V_14 -> V_248 ;
V_9 -> V_12 . V_244 . V_291 = F_69 ( sizeof( V_292 ) * V_293 ,
V_140 ) ;
if ( ! V_9 -> V_12 . V_244 . V_291 ) {
V_193 = - V_23 ;
goto V_294;
}
V_193 = F_155 ( V_9 , V_7 , V_281 ) ;
if ( V_193 )
goto V_294;
F_37 ( V_7 , 3 , L_28 , V_281 , V_9 ,
V_9 -> V_12 . V_14 ) ;
F_156 ( V_281 , V_9 , V_9 -> V_12 . V_14 ) ;
return V_9 ;
V_294:
F_111 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
V_283:
F_121 ( V_219 , V_9 ) ;
V_83:
return F_157 ( V_193 ) ;
}
int F_158 ( struct V_8 * V_9 )
{
return F_159 ( V_9 , 0 ) ;
}
void F_160 ( struct V_8 * V_9 )
{
F_138 ( V_295 , & V_9 -> V_12 . V_14 -> V_296 ) ;
F_54 ( V_9 ) ;
}
void F_161 ( struct V_8 * V_9 )
{
F_140 ( V_295 , & V_9 -> V_12 . V_14 -> V_296 ) ;
}
static void F_162 ( struct V_8 * V_9 )
{
F_138 ( V_297 , & V_9 -> V_12 . V_14 -> V_296 ) ;
F_54 ( V_9 ) ;
}
static void F_163 ( struct V_8 * V_9 )
{
F_140 ( V_297 , & V_9 -> V_12 . V_14 -> V_296 ) ;
}
void F_54 ( struct V_8 * V_9 )
{
F_138 ( V_298 , & V_9 -> V_12 . V_14 -> V_248 ) ;
while ( V_9 -> V_12 . V_14 -> V_299 & V_300 )
F_164 () ;
}
void F_165 ( int V_301 , struct V_8 * V_9 )
{
F_166 ( V_301 , V_9 ) ;
F_162 ( V_9 ) ;
}
static void V_18 ( struct V_71 * V_71 , unsigned long V_70 )
{
int V_10 ;
struct V_7 * V_7 = V_71 -> V_120 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
if ( F_167 ( V_9 ) == ( V_70 & ~ 0x1000UL ) ) {
F_113 ( V_9 , 2 , L_29 , V_70 ) ;
F_165 ( V_302 , V_9 ) ;
}
}
}
int F_168 ( struct V_8 * V_9 )
{
F_169 () ;
return 0 ;
}
static int F_170 ( struct V_8 * V_9 ,
struct V_303 * V_304 )
{
int V_34 = - V_32 ;
switch ( V_304 -> V_281 ) {
case V_305 :
V_34 = F_40 ( V_9 -> V_12 . V_14 -> V_252 ,
( T_5 V_102 * ) V_304 -> V_103 ) ;
break;
case V_306 :
V_34 = F_40 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_101 V_102 * ) V_304 -> V_103 ) ;
break;
case V_307 :
V_34 = F_40 ( V_9 -> V_12 . V_14 -> V_250 ,
( V_101 V_102 * ) V_304 -> V_103 ) ;
break;
case V_308 :
V_34 = F_40 ( V_9 -> V_12 . V_14 -> V_251 ,
( V_101 V_102 * ) V_304 -> V_103 ) ;
break;
case V_309 :
V_34 = F_40 ( V_9 -> V_12 . V_221 ,
( V_101 V_102 * ) V_304 -> V_103 ) ;
break;
case V_310 :
V_34 = F_40 ( V_9 -> V_12 . V_311 ,
( V_101 V_102 * ) V_304 -> V_103 ) ;
break;
case V_312 :
V_34 = F_40 ( V_9 -> V_12 . V_313 ,
( V_101 V_102 * ) V_304 -> V_103 ) ;
break;
case V_314 :
V_34 = F_40 ( V_9 -> V_12 . V_14 -> V_255 ,
( V_101 V_102 * ) V_304 -> V_103 ) ;
break;
case V_315 :
V_34 = F_40 ( V_9 -> V_12 . V_14 -> V_254 ,
( V_101 V_102 * ) V_304 -> V_103 ) ;
break;
default:
break;
}
return V_34 ;
}
static int F_171 ( struct V_8 * V_9 ,
struct V_303 * V_304 )
{
int V_34 = - V_32 ;
switch ( V_304 -> V_281 ) {
case V_305 :
V_34 = F_47 ( V_9 -> V_12 . V_14 -> V_252 ,
( T_5 V_102 * ) V_304 -> V_103 ) ;
break;
case V_306 :
V_34 = F_47 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_101 V_102 * ) V_304 -> V_103 ) ;
break;
case V_307 :
V_34 = F_47 ( V_9 -> V_12 . V_14 -> V_250 ,
( V_101 V_102 * ) V_304 -> V_103 ) ;
break;
case V_308 :
V_34 = F_47 ( V_9 -> V_12 . V_14 -> V_251 ,
( V_101 V_102 * ) V_304 -> V_103 ) ;
break;
case V_309 :
V_34 = F_47 ( V_9 -> V_12 . V_221 ,
( V_101 V_102 * ) V_304 -> V_103 ) ;
if ( V_9 -> V_12 . V_221 == V_222 )
F_116 ( V_9 ) ;
break;
case V_310 :
V_34 = F_47 ( V_9 -> V_12 . V_311 ,
( V_101 V_102 * ) V_304 -> V_103 ) ;
break;
case V_312 :
V_34 = F_47 ( V_9 -> V_12 . V_313 ,
( V_101 V_102 * ) V_304 -> V_103 ) ;
break;
case V_314 :
V_34 = F_47 ( V_9 -> V_12 . V_14 -> V_255 ,
( V_101 V_102 * ) V_304 -> V_103 ) ;
break;
case V_315 :
V_34 = F_47 ( V_9 -> V_12 . V_14 -> V_254 ,
( V_101 V_102 * ) V_304 -> V_103 ) ;
break;
default:
break;
}
return V_34 ;
}
static int F_172 ( struct V_8 * V_9 )
{
F_142 ( V_9 ) ;
return 0 ;
}
int F_173 ( struct V_8 * V_9 , struct V_316 * V_236 )
{
memcpy ( & V_9 -> V_223 -> V_239 . V_236 . V_317 , & V_236 -> V_317 , sizeof( V_236 -> V_317 ) ) ;
return 0 ;
}
int F_174 ( struct V_8 * V_9 , struct V_316 * V_236 )
{
memcpy ( & V_236 -> V_317 , & V_9 -> V_223 -> V_239 . V_236 . V_317 , sizeof( V_236 -> V_317 ) ) ;
return 0 ;
}
int F_175 ( struct V_8 * V_9 ,
struct V_318 * V_319 )
{
memcpy ( & V_9 -> V_223 -> V_239 . V_236 . V_246 , & V_319 -> V_246 , sizeof( V_319 -> V_246 ) ) ;
memcpy ( & V_9 -> V_12 . V_14 -> V_253 , & V_319 -> V_320 , sizeof( V_319 -> V_320 ) ) ;
F_136 ( V_9 -> V_223 -> V_239 . V_236 . V_246 ) ;
return 0 ;
}
int F_176 ( struct V_8 * V_9 ,
struct V_318 * V_319 )
{
memcpy ( & V_319 -> V_246 , & V_9 -> V_223 -> V_239 . V_236 . V_246 , sizeof( V_319 -> V_246 ) ) ;
memcpy ( & V_319 -> V_320 , & V_9 -> V_12 . V_14 -> V_253 , sizeof( V_319 -> V_320 ) ) ;
return 0 ;
}
int F_177 ( struct V_8 * V_9 , struct V_321 * V_232 )
{
if ( F_134 ( V_232 -> V_234 ) )
return - V_32 ;
memcpy ( V_9 -> V_12 . V_244 . V_291 , & V_232 -> V_291 , sizeof( V_232 -> V_291 ) ) ;
V_9 -> V_12 . V_244 . V_234 = V_232 -> V_234 ;
F_132 () ;
F_130 ( & V_9 -> V_12 . V_244 ) ;
return 0 ;
}
int F_178 ( struct V_8 * V_9 , struct V_321 * V_232 )
{
memcpy ( & V_232 -> V_291 , V_9 -> V_12 . V_244 . V_291 , sizeof( V_232 -> V_291 ) ) ;
V_232 -> V_234 = V_9 -> V_12 . V_244 . V_234 ;
return 0 ;
}
static int F_179 ( struct V_8 * V_9 , T_6 V_322 )
{
int V_193 = 0 ;
if ( ! F_180 ( V_9 ) )
V_193 = - V_110 ;
else {
V_9 -> V_223 -> V_323 = V_322 . V_93 ;
V_9 -> V_223 -> V_324 = V_322 . V_103 ;
}
return V_193 ;
}
int F_181 ( struct V_8 * V_9 ,
struct V_325 * V_326 )
{
return - V_32 ;
}
int F_182 ( struct V_8 * V_9 ,
struct V_327 * V_328 )
{
int V_193 = 0 ;
V_9 -> V_329 = 0 ;
F_183 ( V_9 ) ;
if ( V_328 -> V_330 & ~ V_331 )
return - V_32 ;
if ( V_328 -> V_330 & V_332 ) {
V_9 -> V_329 = V_328 -> V_330 ;
F_138 ( V_333 , & V_9 -> V_12 . V_14 -> V_248 ) ;
if ( V_328 -> V_330 & V_334 )
V_193 = F_184 ( V_9 , V_328 ) ;
} else {
F_140 ( V_333 , & V_9 -> V_12 . V_14 -> V_248 ) ;
V_9 -> V_12 . V_335 . V_336 = 0 ;
}
if ( V_193 ) {
V_9 -> V_329 = 0 ;
F_183 ( V_9 ) ;
F_140 ( V_333 , & V_9 -> V_12 . V_14 -> V_248 ) ;
}
return V_193 ;
}
int F_185 ( struct V_8 * V_9 ,
struct V_337 * V_338 )
{
return F_180 ( V_9 ) ? V_339 :
V_340 ;
}
int F_186 ( struct V_8 * V_9 ,
struct V_337 * V_338 )
{
int V_193 = 0 ;
V_9 -> V_7 -> V_12 . V_341 = 1 ;
switch ( V_338 -> V_338 ) {
case V_339 :
F_145 ( V_9 ) ;
break;
case V_340 :
F_187 ( V_9 ) ;
break;
case V_342 :
case V_343 :
default:
V_193 = - V_105 ;
}
return V_193 ;
}
static bool F_188 ( struct V_8 * V_9 )
{
return F_42 ( & V_9 -> V_12 . V_14 -> V_248 ) & V_344 ;
}
static int F_189 ( struct V_8 * V_9 )
{
V_345:
F_163 ( V_9 ) ;
if ( ! V_9 -> V_346 )
return 0 ;
if ( F_190 ( V_302 , V_9 ) ) {
int V_193 ;
V_193 = F_191 ( V_9 -> V_12 . V_71 ,
F_167 ( V_9 ) ,
V_347 * 2 ) ;
if ( V_193 )
return V_193 ;
goto V_345;
}
if ( F_190 ( V_348 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_349 = 0xffff ;
goto V_345;
}
if ( F_190 ( V_350 , V_9 ) ) {
if ( ! F_188 ( V_9 ) ) {
F_192 ( V_9 -> V_214 , 1 ) ;
F_138 ( V_344 ,
& V_9 -> V_12 . V_14 -> V_248 ) ;
}
goto V_345;
}
if ( F_190 ( V_351 , V_9 ) ) {
if ( F_188 ( V_9 ) ) {
F_192 ( V_9 -> V_214 , 0 ) ;
F_140 ( V_344 ,
& V_9 -> V_12 . V_14 -> V_248 ) ;
}
goto V_345;
}
F_117 ( V_352 , & V_9 -> V_346 ) ;
return 0 ;
}
long F_193 ( struct V_8 * V_9 , T_7 V_353 , int V_354 )
{
return F_194 ( V_9 -> V_12 . V_71 , V_353 ,
V_354 ? V_355 : 0 ) ;
}
static void F_195 ( struct V_8 * V_9 , bool V_356 ,
unsigned long V_357 )
{
struct V_172 V_358 ;
struct V_359 V_360 ;
if ( V_356 ) {
V_360 . V_361 . V_33 . V_362 = V_357 ;
V_360 . type = V_363 ;
F_153 ( F_196 ( V_9 , & V_360 ) ) ;
} else {
V_358 . type = V_364 ;
V_358 . V_365 = V_357 ;
F_153 ( F_92 ( V_9 -> V_7 , & V_358 ) ) ;
}
}
void F_197 ( struct V_8 * V_9 ,
struct V_366 * V_367 )
{
F_198 ( V_9 , V_367 -> V_12 . V_221 ) ;
F_195 ( V_9 , true , V_367 -> V_12 . V_221 ) ;
}
void F_199 ( struct V_8 * V_9 ,
struct V_366 * V_367 )
{
F_200 ( V_9 , V_367 -> V_12 . V_221 ) ;
F_195 ( V_9 , false , V_367 -> V_12 . V_221 ) ;
}
void F_201 ( struct V_8 * V_9 ,
struct V_366 * V_367 )
{
}
bool F_202 ( struct V_8 * V_9 )
{
return true ;
}
static int F_203 ( struct V_8 * V_9 )
{
T_8 V_161 ;
struct V_368 V_12 ;
int V_193 ;
if ( V_9 -> V_12 . V_221 == V_222 )
return 0 ;
if ( ( V_9 -> V_12 . V_14 -> V_249 . V_93 & V_9 -> V_12 . V_313 ) !=
V_9 -> V_12 . V_311 )
return 0 ;
if ( F_204 ( V_9 ) )
return 0 ;
if ( F_159 ( V_9 , 0 ) )
return 0 ;
if ( ! ( V_9 -> V_12 . V_14 -> V_253 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_9 -> V_12 . V_71 -> V_211 )
return 0 ;
V_161 = F_83 ( V_9 -> V_7 , F_205 ( V_119 -> V_235 . V_369 ) ) ;
V_161 += V_119 -> V_235 . V_369 & ~ V_370 ;
if ( F_206 ( V_9 , V_9 -> V_12 . V_221 , & V_12 . V_221 , 8 ) )
return 0 ;
V_193 = F_207 ( V_9 , V_119 -> V_235 . V_369 , V_161 , & V_12 ) ;
return V_193 ;
}
static int F_208 ( struct V_8 * V_9 )
{
int V_193 , V_248 ;
F_209 ( V_9 ) ;
memcpy ( & V_9 -> V_12 . V_14 -> V_371 , & V_9 -> V_223 -> V_239 . V_236 . V_317 [ 14 ] , 16 ) ;
if ( F_210 () )
F_211 () ;
if ( F_212 ( V_372 ) )
F_213 () ;
if ( ! F_46 ( V_9 -> V_7 ) ) {
V_193 = F_214 ( V_9 ) ;
if ( V_193 )
return V_193 ;
}
V_193 = F_189 ( V_9 ) ;
if ( V_193 )
return V_193 ;
if ( F_215 ( V_9 ) ) {
F_216 ( V_9 ) ;
F_217 ( V_9 ) ;
}
V_9 -> V_12 . V_14 -> V_373 = 0 ;
V_248 = F_42 ( & V_9 -> V_12 . V_14 -> V_248 ) ;
F_113 ( V_9 , 6 , L_30 , V_248 ) ;
F_218 ( V_9 , V_248 ) ;
return 0 ;
}
static int F_219 ( struct V_8 * V_9 )
{
T_6 * V_322 = & V_9 -> V_12 . V_14 -> V_249 ;
T_2 V_374 ;
int V_193 ;
F_113 ( V_9 , 3 , L_2 , L_31 ) ;
F_220 ( V_9 ) ;
V_193 = F_221 ( V_9 , V_322 -> V_103 , 0 , & V_374 , 1 ) ;
if ( V_193 )
return F_222 ( V_9 , V_193 ) ;
V_322 -> V_103 = F_223 ( * V_322 , - F_224 ( V_374 ) ) ;
return F_225 ( V_9 , V_375 ) ;
}
static int F_226 ( struct V_8 * V_9 , int V_376 )
{
int V_193 = - 1 ;
F_113 ( V_9 , 6 , L_32 ,
V_9 -> V_12 . V_14 -> V_373 ) ;
F_227 ( V_9 , V_9 -> V_12 . V_14 -> V_373 ) ;
if ( F_215 ( V_9 ) )
F_228 ( V_9 ) ;
if ( V_376 >= 0 ) {
V_193 = 0 ;
} else if ( F_46 ( V_9 -> V_7 ) ) {
V_9 -> V_223 -> V_376 = V_377 ;
V_9 -> V_223 -> V_378 . V_379 =
V_119 -> V_235 . V_369 ;
V_9 -> V_223 -> V_378 . V_380 = 0x10 ;
V_193 = - V_381 ;
} else if ( V_119 -> V_235 . V_382 ) {
F_229 ( V_9 ) ;
V_119 -> V_235 . V_382 = 0 ;
if ( F_203 ( V_9 ) ) {
V_193 = 0 ;
} else {
T_7 V_353 = V_119 -> V_235 . V_369 ;
V_193 = F_193 ( V_9 , V_353 , 1 ) ;
}
}
if ( V_193 == - 1 )
V_193 = F_219 ( V_9 ) ;
memcpy ( & V_9 -> V_223 -> V_239 . V_236 . V_317 [ 14 ] , & V_9 -> V_12 . V_14 -> V_371 , 16 ) ;
if ( V_193 == 0 ) {
if ( F_46 ( V_9 -> V_7 ) )
V_193 = V_9 -> V_12 . V_14 -> V_373 ? - V_383 : 0 ;
else
V_193 = F_230 ( V_9 ) ;
}
return V_193 ;
}
static int F_231 ( struct V_8 * V_9 )
{
int V_193 , V_376 ;
V_9 -> V_384 = F_43 ( & V_9 -> V_7 -> V_115 ) ;
do {
V_193 = F_208 ( V_9 ) ;
if ( V_193 )
break;
F_45 ( & V_9 -> V_7 -> V_115 , V_9 -> V_384 ) ;
F_232 () ;
F_233 () ;
F_234 () ;
V_376 = F_235 ( V_9 -> V_12 . V_14 ,
V_9 -> V_223 -> V_239 . V_236 . V_317 ) ;
F_232 () ;
F_236 () ;
F_234 () ;
V_9 -> V_384 = F_43 ( & V_9 -> V_7 -> V_115 ) ;
V_193 = F_226 ( V_9 , V_376 ) ;
} while ( ! F_237 ( V_119 ) && ! F_238 ( V_9 ) && ! V_193 );
F_45 ( & V_9 -> V_7 -> V_115 , V_9 -> V_384 ) ;
return V_193 ;
}
static void F_239 ( struct V_8 * V_9 , struct V_385 * V_385 )
{
V_9 -> V_12 . V_14 -> V_249 . V_93 = V_385 -> V_323 ;
V_9 -> V_12 . V_14 -> V_249 . V_103 = V_385 -> V_324 ;
if ( V_385 -> V_386 & V_225 )
F_143 ( V_9 , V_385 -> V_239 . V_236 . V_387 ) ;
if ( V_385 -> V_386 & V_228 ) {
memcpy ( & V_9 -> V_12 . V_14 -> V_253 , & V_385 -> V_239 . V_236 . V_320 , 128 ) ;
F_166 ( V_348 , V_9 ) ;
}
if ( V_385 -> V_386 & V_229 ) {
V_9 -> V_12 . V_14 -> V_250 = V_385 -> V_239 . V_236 . V_250 ;
V_9 -> V_12 . V_14 -> V_251 = V_385 -> V_239 . V_236 . V_251 ;
V_9 -> V_12 . V_14 -> V_252 = V_385 -> V_239 . V_236 . V_252 ;
V_9 -> V_12 . V_14 -> V_255 = V_385 -> V_239 . V_236 . V_255 ;
V_9 -> V_12 . V_14 -> V_254 = V_385 -> V_239 . V_236 . V_254 ;
}
if ( V_385 -> V_386 & V_230 ) {
V_9 -> V_12 . V_221 = V_385 -> V_239 . V_236 . V_388 ;
V_9 -> V_12 . V_313 = V_385 -> V_239 . V_236 . V_389 ;
V_9 -> V_12 . V_311 = V_385 -> V_239 . V_236 . V_390 ;
if ( V_9 -> V_12 . V_221 == V_222 )
F_116 ( V_9 ) ;
}
V_385 -> V_386 = 0 ;
}
static void F_240 ( struct V_8 * V_9 , struct V_385 * V_385 )
{
V_385 -> V_323 = V_9 -> V_12 . V_14 -> V_249 . V_93 ;
V_385 -> V_324 = V_9 -> V_12 . V_14 -> V_249 . V_103 ;
V_385 -> V_239 . V_236 . V_387 = F_167 ( V_9 ) ;
memcpy ( & V_385 -> V_239 . V_236 . V_320 , & V_9 -> V_12 . V_14 -> V_253 , 128 ) ;
V_385 -> V_239 . V_236 . V_250 = V_9 -> V_12 . V_14 -> V_250 ;
V_385 -> V_239 . V_236 . V_251 = V_9 -> V_12 . V_14 -> V_251 ;
V_385 -> V_239 . V_236 . V_252 = V_9 -> V_12 . V_14 -> V_252 ;
V_385 -> V_239 . V_236 . V_255 = V_9 -> V_12 . V_14 -> V_255 ;
V_385 -> V_239 . V_236 . V_254 = V_9 -> V_12 . V_14 -> V_254 ;
V_385 -> V_239 . V_236 . V_388 = V_9 -> V_12 . V_221 ;
V_385 -> V_239 . V_236 . V_389 = V_9 -> V_12 . V_313 ;
V_385 -> V_239 . V_236 . V_390 = V_9 -> V_12 . V_311 ;
}
int F_241 ( struct V_8 * V_9 , struct V_385 * V_385 )
{
int V_193 ;
T_9 V_391 ;
if ( F_238 ( V_9 ) ) {
F_242 ( V_9 ) ;
return 0 ;
}
if ( V_9 -> V_392 )
F_243 ( V_393 , & V_9 -> V_394 , & V_391 ) ;
if ( ! F_144 ( V_9 -> V_7 ) ) {
F_187 ( V_9 ) ;
} else if ( F_180 ( V_9 ) ) {
F_244 ( L_33 ,
V_9 -> V_214 ) ;
return - V_32 ;
}
F_239 ( V_9 , V_385 ) ;
F_245 () ;
V_193 = F_231 ( V_9 ) ;
if ( F_237 ( V_119 ) && ! V_193 ) {
V_385 -> V_376 = V_395 ;
V_193 = - V_396 ;
}
if ( F_238 ( V_9 ) && ! V_193 ) {
F_242 ( V_9 ) ;
V_193 = 0 ;
}
if ( V_193 == - V_383 ) {
V_385 -> V_376 = V_397 ;
V_385 -> V_398 . V_373 = V_9 -> V_12 . V_14 -> V_373 ;
V_385 -> V_398 . V_399 = V_9 -> V_12 . V_14 -> V_399 ;
V_385 -> V_398 . V_400 = V_9 -> V_12 . V_14 -> V_400 ;
V_193 = 0 ;
}
if ( V_193 == - V_381 ) {
V_193 = 0 ;
}
F_240 ( V_9 , V_385 ) ;
if ( V_9 -> V_392 )
F_243 ( V_393 , & V_391 , NULL ) ;
V_9 -> V_401 . V_402 ++ ;
return V_193 ;
}
int F_246 ( struct V_8 * V_9 , unsigned long V_353 )
{
unsigned char V_403 = 1 ;
unsigned int V_404 ;
V_101 V_405 ;
int V_193 ;
if ( V_353 == V_406 ) {
if ( F_247 ( V_9 , 163 , & V_403 , 1 ) )
return - V_104 ;
V_353 = V_407 ;
} else if ( V_353 == V_408 ) {
if ( F_248 ( V_9 , 163 , & V_403 , 1 ) )
return - V_104 ;
V_353 = F_249 ( V_9 , V_407 ) ;
}
V_193 = F_247 ( V_9 , V_353 + F_250 ( struct V_409 , V_410 ) ,
V_9 -> V_12 . V_244 . V_291 , 128 ) ;
V_193 |= F_247 ( V_9 , V_353 + F_250 ( struct V_409 , V_411 ) ,
V_9 -> V_223 -> V_239 . V_236 . V_317 , 128 ) ;
V_193 |= F_247 ( V_9 , V_353 + F_250 ( struct V_409 , V_322 ) ,
& V_9 -> V_12 . V_14 -> V_249 , 16 ) ;
V_404 = F_167 ( V_9 ) ;
V_193 |= F_247 ( V_9 , V_353 + F_250 ( struct V_409 , V_412 ) ,
& V_404 , 4 ) ;
V_193 |= F_247 ( V_9 ,
V_353 + F_250 ( struct V_409 , V_413 ) ,
& V_9 -> V_12 . V_244 . V_234 , 4 ) ;
V_193 |= F_247 ( V_9 , V_353 + F_250 ( struct V_409 , V_414 ) ,
& V_9 -> V_12 . V_14 -> V_252 , 4 ) ;
V_193 |= F_247 ( V_9 , V_353 + F_250 ( struct V_409 , V_415 ) ,
& V_9 -> V_12 . V_14 -> V_250 , 8 ) ;
V_405 = V_9 -> V_12 . V_14 -> V_251 >> 8 ;
V_193 |= F_247 ( V_9 , V_353 + F_250 ( struct V_409 , V_416 ) ,
& V_405 , 8 ) ;
V_193 |= F_247 ( V_9 , V_353 + F_250 ( struct V_409 , V_417 ) ,
& V_9 -> V_223 -> V_239 . V_236 . V_246 , 64 ) ;
V_193 |= F_247 ( V_9 , V_353 + F_250 ( struct V_409 , V_418 ) ,
& V_9 -> V_12 . V_14 -> V_253 , 128 ) ;
return V_193 ? - V_104 : 0 ;
}
int F_251 ( struct V_8 * V_9 , unsigned long V_103 )
{
F_132 () ;
if ( F_51 ( V_9 -> V_7 , 129 ) ) {
F_252 ( ! F_253 ( V_119 ) ) ;
V_9 -> V_12 . V_244 . V_234 = V_119 -> V_235 . V_232 . V_234 ;
F_254 ( V_9 -> V_12 . V_244 . V_291 ,
V_119 -> V_235 . V_232 . V_241 ) ;
} else
F_129 ( & V_9 -> V_12 . V_244 ) ;
F_135 ( V_9 -> V_223 -> V_239 . V_236 . V_246 ) ;
return F_246 ( V_9 , V_103 ) ;
}
int F_255 ( struct V_8 * V_9 ,
unsigned long V_353 )
{
if ( ! ( V_353 & ~ 0x3ff ) )
return 0 ;
return F_247 ( V_9 , V_353 & ~ 0x3ff ,
( void * ) & V_9 -> V_223 -> V_239 . V_236 . V_243 , 512 ) ;
}
int F_256 ( struct V_8 * V_9 , unsigned long V_103 )
{
if ( ! F_51 ( V_9 -> V_7 , 129 ) )
return 0 ;
F_132 () ;
return F_255 ( V_9 , V_103 ) ;
}
static void F_257 ( struct V_8 * V_9 )
{
F_190 ( V_350 , V_9 ) ;
F_165 ( V_351 , V_9 ) ;
}
static void F_258 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
F_257 ( V_9 ) ;
}
}
static void F_259 ( struct V_8 * V_9 )
{
F_190 ( V_351 , V_9 ) ;
F_165 ( V_350 , V_9 ) ;
}
void F_187 ( struct V_8 * V_9 )
{
int V_10 , V_112 , V_419 = 0 ;
if ( ! F_180 ( V_9 ) )
return;
F_260 ( V_9 -> V_214 , 1 ) ;
F_104 ( & V_9 -> V_7 -> V_12 . V_213 ) ;
V_112 = F_42 ( & V_9 -> V_7 -> V_112 ) ;
for ( V_10 = 0 ; V_10 < V_112 ; V_10 ++ ) {
if ( ! F_180 ( V_9 -> V_7 -> V_220 [ V_10 ] ) )
V_419 ++ ;
}
if ( V_419 == 0 ) {
F_259 ( V_9 ) ;
} else if ( V_419 == 1 ) {
F_258 ( V_9 -> V_7 ) ;
}
F_140 ( V_264 , & V_9 -> V_12 . V_14 -> V_248 ) ;
F_166 ( V_348 , V_9 ) ;
F_105 ( & V_9 -> V_7 -> V_12 . V_213 ) ;
return;
}
void F_145 ( struct V_8 * V_9 )
{
int V_10 , V_112 , V_419 = 0 ;
struct V_8 * V_420 = NULL ;
if ( F_180 ( V_9 ) )
return;
F_260 ( V_9 -> V_214 , 0 ) ;
F_104 ( & V_9 -> V_7 -> V_12 . V_213 ) ;
V_112 = F_42 ( & V_9 -> V_7 -> V_112 ) ;
F_261 ( V_9 ) ;
F_138 ( V_264 , & V_9 -> V_12 . V_14 -> V_248 ) ;
F_257 ( V_9 ) ;
for ( V_10 = 0 ; V_10 < V_112 ; V_10 ++ ) {
if ( ! F_180 ( V_9 -> V_7 -> V_220 [ V_10 ] ) ) {
V_419 ++ ;
V_420 = V_9 -> V_7 -> V_220 [ V_10 ] ;
}
}
if ( V_419 == 1 ) {
F_259 ( V_420 ) ;
}
F_105 ( & V_9 -> V_7 -> V_12 . V_213 ) ;
return;
}
static int F_262 ( struct V_8 * V_9 ,
struct V_86 * V_87 )
{
int V_34 ;
if ( V_87 -> V_88 )
return - V_32 ;
switch ( V_87 -> V_87 ) {
case V_43 :
if ( ! V_9 -> V_7 -> V_12 . V_212 ) {
V_9 -> V_7 -> V_12 . V_212 = 1 ;
F_37 ( V_9 -> V_7 , 3 , L_2 , L_34 ) ;
F_263 ( V_9 -> V_7 ) ;
}
V_34 = 0 ;
break;
default:
V_34 = - V_32 ;
break;
}
return V_34 ;
}
static long F_264 ( struct V_8 * V_9 ,
struct V_421 * V_422 )
{
void V_102 * V_423 = ( void V_102 * ) V_422 -> V_424 ;
void * V_425 = NULL ;
int V_34 , V_384 ;
const V_101 V_426 = V_427
| V_428 ;
if ( V_422 -> V_88 & ~ V_426 )
return - V_32 ;
if ( V_422 -> V_429 > V_56 )
return - V_117 ;
if ( ! ( V_422 -> V_88 & V_428 ) ) {
V_425 = F_82 ( V_422 -> V_429 ) ;
if ( ! V_425 )
return - V_23 ;
}
V_384 = F_43 ( & V_9 -> V_7 -> V_115 ) ;
switch ( V_422 -> V_430 ) {
case V_431 :
if ( V_422 -> V_88 & V_428 ) {
V_34 = F_265 ( V_9 , V_422 -> V_432 , V_422 -> V_433 , V_422 -> V_429 , false ) ;
break;
}
V_34 = F_221 ( V_9 , V_422 -> V_432 , V_422 -> V_433 , V_425 , V_422 -> V_429 ) ;
if ( V_34 == 0 ) {
if ( F_65 ( V_423 , V_425 , V_422 -> V_429 ) )
V_34 = - V_104 ;
}
break;
case V_434 :
if ( V_422 -> V_88 & V_428 ) {
V_34 = F_265 ( V_9 , V_422 -> V_432 , V_422 -> V_433 , V_422 -> V_429 , true ) ;
break;
}
if ( F_56 ( V_425 , V_423 , V_422 -> V_429 ) ) {
V_34 = - V_104 ;
break;
}
V_34 = F_266 ( V_9 , V_422 -> V_432 , V_422 -> V_433 , V_425 , V_422 -> V_429 ) ;
break;
default:
V_34 = - V_32 ;
}
F_45 ( & V_9 -> V_7 -> V_115 , V_384 ) ;
if ( V_34 > 0 && ( V_422 -> V_88 & V_427 ) != 0 )
F_267 ( V_9 , & V_9 -> V_12 . V_435 ) ;
F_268 ( V_425 ) ;
return V_34 ;
}
long F_269 ( struct V_27 * V_28 ,
unsigned int V_29 , unsigned long V_30 )
{
struct V_8 * V_9 = V_28 -> V_169 ;
void V_102 * V_170 = ( void V_102 * ) V_30 ;
int V_106 ;
long V_34 ;
switch ( V_29 ) {
case V_436 : {
struct V_359 V_437 ;
V_34 = - V_104 ;
if ( F_56 ( & V_437 , V_170 , sizeof( V_437 ) ) )
break;
V_34 = F_196 ( V_9 , & V_437 ) ;
break;
}
case V_171 : {
struct V_172 V_173 ;
struct V_359 V_437 ;
V_34 = - V_104 ;
if ( F_56 ( & V_173 , V_170 , sizeof( V_173 ) ) )
break;
if ( F_270 ( & V_173 , & V_437 ) )
return - V_32 ;
V_34 = F_196 ( V_9 , & V_437 ) ;
break;
}
case V_438 :
V_106 = F_43 ( & V_9 -> V_7 -> V_115 ) ;
V_34 = F_251 ( V_9 , V_30 ) ;
F_45 ( & V_9 -> V_7 -> V_115 , V_106 ) ;
break;
case V_439 : {
T_6 V_322 ;
V_34 = - V_104 ;
if ( F_56 ( & V_322 , V_170 , sizeof( V_322 ) ) )
break;
V_34 = F_179 ( V_9 , V_322 ) ;
break;
}
case V_440 :
V_34 = F_172 ( V_9 ) ;
break;
case V_441 :
case V_442 : {
struct V_303 V_304 ;
V_34 = - V_104 ;
if ( F_56 ( & V_304 , V_170 , sizeof( V_304 ) ) )
break;
if ( V_29 == V_441 )
V_34 = F_171 ( V_9 , & V_304 ) ;
else
V_34 = F_170 ( V_9 , & V_304 ) ;
break;
}
#ifdef F_23
case V_443 : {
struct V_444 V_445 ;
if ( F_56 ( & V_445 , V_170 , sizeof( V_445 ) ) ) {
V_34 = - V_104 ;
break;
}
if ( ! F_46 ( V_9 -> V_7 ) ) {
V_34 = - V_32 ;
break;
}
V_34 = F_271 ( V_9 -> V_12 . V_71 , V_445 . V_446 ,
V_445 . V_447 , V_445 . V_448 ) ;
break;
}
case V_449 : {
struct V_444 V_445 ;
if ( F_56 ( & V_445 , V_170 , sizeof( V_445 ) ) ) {
V_34 = - V_104 ;
break;
}
if ( ! F_46 ( V_9 -> V_7 ) ) {
V_34 = - V_32 ;
break;
}
V_34 = F_272 ( V_9 -> V_12 . V_71 , V_445 . V_447 ,
V_445 . V_448 ) ;
break;
}
#endif
case V_450 : {
V_34 = F_194 ( V_9 -> V_12 . V_71 , V_30 , 0 ) ;
break;
}
case V_174 :
{
struct V_86 V_87 ;
V_34 = - V_104 ;
if ( F_56 ( & V_87 , V_170 , sizeof( V_87 ) ) )
break;
V_34 = F_262 ( V_9 , & V_87 ) ;
break;
}
case V_451 : {
struct V_421 V_452 ;
if ( F_56 ( & V_452 , V_170 , sizeof( V_452 ) ) == 0 )
V_34 = F_264 ( V_9 , & V_452 ) ;
else
V_34 = - V_104 ;
break;
}
case V_453 : {
struct V_454 V_455 ;
V_34 = - V_104 ;
if ( F_56 ( & V_455 , V_170 , sizeof( V_455 ) ) )
break;
if ( V_455 . V_456 > V_457 ||
V_455 . V_456 == 0 ||
V_455 . V_456 % sizeof( struct V_359 ) > 0 ) {
V_34 = - V_32 ;
break;
}
V_34 = F_273 ( V_9 ,
( void V_102 * ) V_455 . V_424 ,
V_455 . V_456 ) ;
break;
}
case V_458 : {
struct V_454 V_455 ;
V_34 = - V_104 ;
if ( F_56 ( & V_455 , V_170 , sizeof( V_455 ) ) )
break;
if ( V_455 . V_456 == 0 ) {
V_34 = - V_32 ;
break;
}
V_34 = F_274 ( V_9 ,
( V_459 V_102 * ) V_455 . V_424 ,
V_455 . V_456 ) ;
break;
}
default:
V_34 = - V_183 ;
}
return V_34 ;
}
int F_275 ( struct V_8 * V_9 , struct V_460 * V_461 )
{
#ifdef F_23
if ( ( V_461 -> V_462 == V_463 )
&& ( F_46 ( V_9 -> V_7 ) ) ) {
V_461 -> V_464 = F_276 ( V_9 -> V_12 . V_14 ) ;
F_277 ( V_461 -> V_464 ) ;
return 0 ;
}
#endif
return V_465 ;
}
int F_278 ( struct V_7 * V_7 , struct V_66 * V_82 ,
unsigned long V_75 )
{
return 0 ;
}
int F_279 ( struct V_7 * V_7 ,
struct V_66 * V_67 ,
const struct V_466 * V_467 ,
enum V_468 V_469 )
{
if ( V_467 -> V_470 & 0xffffful )
return - V_32 ;
if ( V_467 -> V_471 & 0xffffful )
return - V_32 ;
return 0 ;
}
void F_280 ( struct V_7 * V_7 ,
const struct V_466 * V_467 ,
const struct V_66 * V_472 ,
const struct V_66 * V_118 ,
enum V_468 V_469 )
{
int V_193 ;
if ( V_472 -> V_470 == V_467 -> V_470 &&
V_472 -> V_74 * V_347 == V_467 -> V_473 &&
V_472 -> V_75 * V_347 == V_467 -> V_471 )
return;
V_193 = F_271 ( V_7 -> V_12 . V_71 , V_467 -> V_470 ,
V_467 -> V_473 , V_467 -> V_471 ) ;
if ( V_193 )
F_281 ( L_35 ) ;
return;
}
static int T_10 F_282 ( void )
{
return F_283 ( NULL , sizeof( struct V_8 ) , 0 , V_474 ) ;
}
static void T_11 F_284 ( void )
{
F_285 () ;
}
