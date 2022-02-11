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
if ( V_9 -> V_12 . V_15 )
V_9 -> V_12 . V_16 += * V_11 ;
}
}
return V_17 ;
}
int F_8 ( void )
{
V_18 . V_19 = V_20 ;
F_9 ( & V_18 ) ;
F_10 ( & V_21 ,
& V_22 ) ;
return 0 ;
}
void F_11 ( void )
{
F_12 ( & V_18 ) ;
F_13 ( & V_21 ,
& V_22 ) ;
}
int F_14 ( void * V_23 )
{
V_24 = F_15 ( L_1 , 32 , 1 , 7 * sizeof( long ) ) ;
if ( ! V_24 )
return - V_25 ;
if ( F_16 ( V_24 , & V_26 ) ) {
F_17 ( V_24 ) ;
return - V_25 ;
}
return F_18 ( & V_27 , V_28 ) ;
}
void F_19 ( void )
{
F_17 ( V_24 ) ;
}
long F_20 ( struct V_29 * V_30 ,
unsigned int V_31 , unsigned long V_32 )
{
if ( V_31 == V_33 )
return F_21 () ;
return - V_34 ;
}
int F_22 ( struct V_7 * V_7 , long V_35 )
{
int V_36 ;
switch ( V_35 ) {
case V_37 :
case V_38 :
case V_39 :
#ifdef F_23
case V_40 :
#endif
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
case V_55 :
case V_56 :
V_36 = 1 ;
break;
case V_57 :
V_36 = V_58 ;
break;
case V_59 :
case V_60 :
V_36 = V_61 . V_62 ? V_63
: V_64 ;
break;
case V_65 :
V_36 = V_66 ;
break;
case V_67 :
V_36 = V_68 ;
break;
case V_69 :
V_36 = V_70 ;
break;
case V_71 :
V_36 = F_24 ( 64 ) ;
break;
default:
V_36 = 0 ;
}
return V_36 ;
}
static void F_25 ( struct V_7 * V_7 ,
struct V_72 * V_73 )
{
T_1 V_74 , V_75 ;
unsigned long V_76 ;
struct V_77 * V_77 = V_7 -> V_12 . V_77 ;
V_75 = V_73 -> V_78 + V_73 -> V_79 ;
for ( V_74 = V_73 -> V_78 ; V_74 <= V_75 ; V_74 ++ ) {
V_76 = F_26 ( V_73 , V_74 ) ;
if ( F_27 ( V_77 -> V_80 , V_76 ) )
F_28 ( V_7 , V_74 ) ;
if ( F_29 ( V_81 ) )
return;
F_30 () ;
}
}
int F_31 ( struct V_7 * V_7 ,
struct V_82 * log )
{
int V_36 ;
unsigned long V_83 ;
struct V_84 * V_85 ;
struct V_72 * V_73 ;
int V_86 = 0 ;
F_32 ( & V_7 -> V_87 ) ;
V_36 = - V_34 ;
if ( log -> V_88 >= V_66 )
goto V_89;
V_85 = V_84 ( V_7 ) ;
V_73 = F_33 ( V_85 , log -> V_88 ) ;
V_36 = - V_90 ;
if ( ! V_73 -> V_91 )
goto V_89;
F_25 ( V_7 , V_73 ) ;
V_36 = F_34 ( V_7 , log , & V_86 ) ;
if ( V_36 )
goto V_89;
if ( V_86 ) {
V_83 = F_35 ( V_73 ) ;
memset ( V_73 -> V_91 , 0 , V_83 ) ;
}
V_36 = 0 ;
V_89:
F_36 ( & V_7 -> V_87 ) ;
return V_36 ;
}
static int F_37 ( struct V_7 * V_7 , struct V_92 * V_93 )
{
int V_36 ;
if ( V_93 -> V_94 )
return - V_34 ;
switch ( V_93 -> V_93 ) {
case V_49 :
F_38 ( V_7 , 3 , L_2 , L_3 ) ;
V_7 -> V_12 . V_95 = 1 ;
V_36 = 0 ;
break;
case V_53 :
F_38 ( V_7 , 3 , L_2 , L_4 ) ;
V_7 -> V_12 . V_96 = 1 ;
V_36 = 0 ;
break;
case V_69 :
F_32 ( & V_7 -> V_97 ) ;
if ( F_39 ( & V_7 -> V_98 ) ) {
V_36 = - V_99 ;
} else if ( V_70 ) {
F_40 ( V_7 -> V_12 . V_100 . V_101 , 129 ) ;
F_40 ( V_7 -> V_12 . V_100 . V_102 , 129 ) ;
V_36 = 0 ;
} else
V_36 = - V_34 ;
F_36 ( & V_7 -> V_97 ) ;
F_38 ( V_7 , 3 , L_5 ,
V_36 ? L_6 : L_7 ) ;
break;
case V_71 :
V_36 = - V_34 ;
F_32 ( & V_7 -> V_97 ) ;
if ( F_39 ( & V_7 -> V_98 ) ) {
V_36 = - V_99 ;
} else if ( F_24 ( 64 ) ) {
F_40 ( V_7 -> V_12 . V_100 . V_101 , 64 ) ;
F_40 ( V_7 -> V_12 . V_100 . V_102 , 64 ) ;
V_36 = 0 ;
}
F_36 ( & V_7 -> V_97 ) ;
F_38 ( V_7 , 3 , L_8 ,
V_36 ? L_6 : L_7 ) ;
break;
case V_54 :
F_38 ( V_7 , 3 , L_2 , L_9 ) ;
V_7 -> V_12 . V_103 = 1 ;
V_36 = 0 ;
break;
default:
V_36 = - V_34 ;
break;
}
return V_36 ;
}
static int F_41 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
int V_106 ;
switch ( V_105 -> V_105 ) {
case V_107 :
V_106 = 0 ;
F_38 ( V_7 , 3 , L_10 ,
V_7 -> V_12 . V_108 ) ;
if ( F_42 ( V_7 -> V_12 . V_108 , ( V_109 V_110 * ) V_105 -> V_111 ) )
V_106 = - V_112 ;
break;
default:
V_106 = - V_113 ;
break;
}
return V_106 ;
}
static int F_43 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
int V_106 ;
unsigned int V_114 ;
switch ( V_105 -> V_105 ) {
case V_115 :
V_106 = - V_34 ;
if ( ! V_116 || ! V_117 )
break;
V_106 = - V_99 ;
F_38 ( V_7 , 3 , L_2 , L_11 ) ;
F_32 ( & V_7 -> V_97 ) ;
if ( F_39 ( & V_7 -> V_98 ) == 0 ) {
V_7 -> V_12 . V_118 = 1 ;
V_106 = 0 ;
}
F_36 ( & V_7 -> V_97 ) ;
break;
case V_119 :
V_106 = - V_34 ;
if ( ! V_7 -> V_12 . V_118 )
break;
F_38 ( V_7 , 3 , L_2 , L_12 ) ;
F_32 ( & V_7 -> V_97 ) ;
V_114 = F_44 ( & V_7 -> V_120 ) ;
F_45 ( V_7 -> V_12 . V_77 -> V_80 ) ;
F_46 ( & V_7 -> V_120 , V_114 ) ;
F_36 ( & V_7 -> V_97 ) ;
V_106 = 0 ;
break;
case V_107 : {
unsigned long V_121 ;
if ( F_47 ( V_7 ) )
return - V_34 ;
if ( F_48 ( V_121 , ( V_109 V_110 * ) V_105 -> V_111 ) )
return - V_112 ;
if ( V_7 -> V_12 . V_108 != V_122 &&
V_121 > V_7 -> V_12 . V_108 )
return - V_123 ;
if ( ! V_121 )
return - V_34 ;
if ( V_121 != V_122 )
V_121 -= 1 ;
V_106 = - V_99 ;
F_32 ( & V_7 -> V_97 ) ;
if ( F_39 ( & V_7 -> V_98 ) == 0 ) {
struct V_77 * V_124 = F_49 ( V_81 -> V_80 , V_121 ) ;
if ( ! V_124 ) {
V_106 = - V_25 ;
} else {
F_50 ( V_7 -> V_12 . V_77 ) ;
V_124 -> V_125 = V_7 ;
V_7 -> V_12 . V_77 = V_124 ;
V_106 = 0 ;
}
}
F_36 ( & V_7 -> V_97 ) ;
F_38 ( V_7 , 3 , L_13 , V_121 ) ;
F_38 ( V_7 , 3 , L_14 ,
( void * ) V_7 -> V_12 . V_77 -> V_126 ) ;
break;
}
default:
V_106 = - V_113 ;
break;
}
return V_106 ;
}
static int F_51 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
struct V_8 * V_9 ;
int V_10 ;
if ( ! F_52 ( V_7 , 76 ) )
return - V_34 ;
F_32 ( & V_7 -> V_97 ) ;
switch ( V_105 -> V_105 ) {
case V_127 :
F_53 (
V_7 -> V_12 . V_128 . V_129 -> V_130 ,
sizeof( V_7 -> V_12 . V_128 . V_129 -> V_130 ) ) ;
V_7 -> V_12 . V_128 . V_131 = 1 ;
F_38 ( V_7 , 3 , L_2 , L_15 ) ;
break;
case V_132 :
F_53 (
V_7 -> V_12 . V_128 . V_129 -> V_133 ,
sizeof( V_7 -> V_12 . V_128 . V_129 -> V_133 ) ) ;
V_7 -> V_12 . V_128 . V_134 = 1 ;
F_38 ( V_7 , 3 , L_2 , L_16 ) ;
break;
case V_135 :
V_7 -> V_12 . V_128 . V_131 = 0 ;
memset ( V_7 -> V_12 . V_128 . V_129 -> V_130 , 0 ,
sizeof( V_7 -> V_12 . V_128 . V_129 -> V_130 ) ) ;
F_38 ( V_7 , 3 , L_2 , L_17 ) ;
break;
case V_136 :
V_7 -> V_12 . V_128 . V_134 = 0 ;
memset ( V_7 -> V_12 . V_128 . V_129 -> V_133 , 0 ,
sizeof( V_7 -> V_12 . V_128 . V_129 -> V_133 ) ) ;
F_38 ( V_7 , 3 , L_2 , L_18 ) ;
break;
default:
F_36 ( & V_7 -> V_97 ) ;
return - V_113 ;
}
F_7 (i, vcpu, kvm) {
F_54 ( V_9 ) ;
F_55 ( V_9 ) ;
}
F_36 ( & V_7 -> V_97 ) ;
return 0 ;
}
static int F_56 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
T_2 V_137 ;
if ( F_57 ( & V_137 , ( void V_110 * ) V_105 -> V_111 ,
sizeof( V_137 ) ) )
return - V_112 ;
if ( V_137 != 0 )
return - V_34 ;
F_38 ( V_7 , 3 , L_19 , V_137 ) ;
return 0 ;
}
static int F_58 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
V_109 V_138 ;
if ( F_57 ( & V_138 , ( void V_110 * ) V_105 -> V_111 , sizeof( V_138 ) ) )
return - V_112 ;
F_59 ( V_7 , V_138 ) ;
F_38 ( V_7 , 3 , L_20 , V_138 ) ;
return 0 ;
}
static int F_60 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
int V_106 ;
if ( V_105 -> V_94 )
return - V_34 ;
switch ( V_105 -> V_105 ) {
case V_139 :
V_106 = F_56 ( V_7 , V_105 ) ;
break;
case V_140 :
V_106 = F_58 ( V_7 , V_105 ) ;
break;
default:
V_106 = - V_113 ;
break;
}
return V_106 ;
}
static int F_61 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
T_2 V_137 = 0 ;
if ( F_62 ( ( void V_110 * ) V_105 -> V_111 , & V_137 ,
sizeof( V_137 ) ) )
return - V_112 ;
F_38 ( V_7 , 3 , L_21 , V_137 ) ;
return 0 ;
}
static int F_63 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
V_109 V_138 ;
V_138 = F_64 ( V_7 ) ;
if ( F_62 ( ( void V_110 * ) V_105 -> V_111 , & V_138 , sizeof( V_138 ) ) )
return - V_112 ;
F_38 ( V_7 , 3 , L_22 , V_138 ) ;
return 0 ;
}
static int F_65 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
int V_106 ;
if ( V_105 -> V_94 )
return - V_34 ;
switch ( V_105 -> V_105 ) {
case V_139 :
V_106 = F_61 ( V_7 , V_105 ) ;
break;
case V_140 :
V_106 = F_63 ( V_7 , V_105 ) ;
break;
default:
V_106 = - V_113 ;
break;
}
return V_106 ;
}
static int F_66 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
struct V_141 * V_142 ;
int V_106 = 0 ;
F_32 ( & V_7 -> V_97 ) ;
if ( F_39 ( & V_7 -> V_98 ) ) {
V_106 = - V_99 ;
goto V_89;
}
V_142 = F_67 ( sizeof( * V_142 ) , V_143 ) ;
if ( ! V_142 ) {
V_106 = - V_25 ;
goto V_89;
}
if ( ! F_57 ( V_142 , ( void V_110 * ) V_105 -> V_111 ,
sizeof( * V_142 ) ) ) {
memcpy ( & V_7 -> V_12 . V_100 . V_144 , & V_142 -> V_145 ,
sizeof( struct V_145 ) ) ;
V_7 -> V_12 . V_100 . V_146 = V_142 -> V_146 ;
memcpy ( V_7 -> V_12 . V_100 . V_102 , V_142 -> V_102 ,
V_147 ) ;
} else
V_106 = - V_112 ;
F_68 ( V_142 ) ;
V_89:
F_36 ( & V_7 -> V_97 ) ;
return V_106 ;
}
static int F_69 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
int V_106 = - V_113 ;
switch ( V_105 -> V_105 ) {
case V_148 :
V_106 = F_66 ( V_7 , V_105 ) ;
break;
}
return V_106 ;
}
static int F_70 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
struct V_141 * V_142 ;
int V_106 = 0 ;
V_142 = F_67 ( sizeof( * V_142 ) , V_143 ) ;
if ( ! V_142 ) {
V_106 = - V_25 ;
goto V_89;
}
memcpy ( & V_142 -> V_145 , & V_7 -> V_12 . V_100 . V_144 , sizeof( struct V_145 ) ) ;
V_142 -> V_146 = V_7 -> V_12 . V_100 . V_146 ;
memcpy ( & V_142 -> V_102 , V_7 -> V_12 . V_100 . V_102 ,
V_147 ) ;
if ( F_62 ( ( void V_110 * ) V_105 -> V_111 , V_142 , sizeof( * V_142 ) ) )
V_106 = - V_112 ;
F_68 ( V_142 ) ;
V_89:
return V_106 ;
}
static int F_71 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
struct V_149 * V_150 ;
int V_106 = 0 ;
V_150 = F_67 ( sizeof( * V_150 ) , V_143 ) ;
if ( ! V_150 ) {
V_106 = - V_25 ;
goto V_89;
}
F_72 ( (struct V_145 * ) & V_150 -> V_145 ) ;
V_150 -> V_146 = V_61 . V_146 ;
memcpy ( & V_150 -> V_101 , V_7 -> V_12 . V_100 . V_101 ,
V_147 ) ;
memcpy ( ( unsigned long * ) & V_150 -> V_102 , V_151 . V_152 ,
V_147 ) ;
if ( F_62 ( ( void V_110 * ) V_105 -> V_111 , V_150 , sizeof( * V_150 ) ) )
V_106 = - V_112 ;
F_68 ( V_150 ) ;
V_89:
return V_106 ;
}
static int F_73 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
int V_106 = - V_113 ;
switch ( V_105 -> V_105 ) {
case V_148 :
V_106 = F_70 ( V_7 , V_105 ) ;
break;
case V_153 :
V_106 = F_71 ( V_7 , V_105 ) ;
break;
}
return V_106 ;
}
static int F_74 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
int V_106 ;
switch ( V_105 -> V_154 ) {
case V_155 :
V_106 = F_43 ( V_7 , V_105 ) ;
break;
case V_156 :
V_106 = F_60 ( V_7 , V_105 ) ;
break;
case V_157 :
V_106 = F_69 ( V_7 , V_105 ) ;
break;
case V_158 :
V_106 = F_51 ( V_7 , V_105 ) ;
break;
default:
V_106 = - V_113 ;
break;
}
return V_106 ;
}
static int F_75 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
int V_106 ;
switch ( V_105 -> V_154 ) {
case V_155 :
V_106 = F_41 ( V_7 , V_105 ) ;
break;
case V_156 :
V_106 = F_65 ( V_7 , V_105 ) ;
break;
case V_157 :
V_106 = F_73 ( V_7 , V_105 ) ;
break;
default:
V_106 = - V_113 ;
break;
}
return V_106 ;
}
static int F_76 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
int V_106 ;
switch ( V_105 -> V_154 ) {
case V_155 :
switch ( V_105 -> V_105 ) {
case V_115 :
case V_119 :
case V_107 :
V_106 = 0 ;
break;
default:
V_106 = - V_113 ;
break;
}
break;
case V_156 :
switch ( V_105 -> V_105 ) {
case V_140 :
case V_139 :
V_106 = 0 ;
break;
default:
V_106 = - V_113 ;
break;
}
break;
case V_157 :
switch ( V_105 -> V_105 ) {
case V_148 :
case V_153 :
V_106 = 0 ;
break;
default:
V_106 = - V_113 ;
break;
}
break;
case V_158 :
switch ( V_105 -> V_105 ) {
case V_127 :
case V_132 :
case V_135 :
case V_136 :
V_106 = 0 ;
break;
default:
V_106 = - V_113 ;
break;
}
break;
default:
V_106 = - V_113 ;
break;
}
return V_106 ;
}
static long F_77 ( struct V_7 * V_7 , struct V_159 * args )
{
T_3 * V_160 ;
T_4 V_161 ;
unsigned long V_162 ;
int V_10 , V_36 = 0 ;
if ( args -> V_94 != 0 )
return - V_34 ;
if ( ! F_78 ( V_81 -> V_80 ) )
return V_163 ;
if ( args -> V_164 < 1 || args -> V_164 > V_165 )
return - V_34 ;
V_160 = F_79 ( args -> V_164 , sizeof( T_3 ) ,
V_143 | V_166 ) ;
if ( ! V_160 )
V_160 = F_80 ( sizeof( T_3 ) * args -> V_164 ) ;
if ( ! V_160 )
return - V_25 ;
for ( V_10 = 0 ; V_10 < args -> V_164 ; V_10 ++ ) {
V_161 = F_81 ( V_7 , args -> V_167 + V_10 ) ;
if ( F_82 ( V_161 ) ) {
V_36 = - V_112 ;
goto V_89;
}
V_162 = F_83 ( V_81 -> V_80 , V_161 ) ;
if ( F_84 ( V_162 ) ) {
V_36 = V_162 ;
goto V_89;
}
V_160 [ V_10 ] = V_162 ;
}
V_36 = F_62 ( ( T_3 V_110 * ) args -> V_168 , V_160 ,
sizeof( T_3 ) * args -> V_164 ) ;
if ( V_36 )
V_36 = - V_112 ;
V_89:
F_85 ( V_160 ) ;
return V_36 ;
}
static long F_86 ( struct V_7 * V_7 , struct V_159 * args )
{
T_3 * V_160 ;
T_4 V_161 ;
int V_10 , V_36 = 0 ;
if ( args -> V_94 != 0 )
return - V_34 ;
if ( args -> V_164 < 1 || args -> V_164 > V_165 )
return - V_34 ;
V_160 = F_79 ( args -> V_164 , sizeof( T_3 ) ,
V_143 | V_166 ) ;
if ( ! V_160 )
V_160 = F_80 ( sizeof( T_3 ) * args -> V_164 ) ;
if ( ! V_160 )
return - V_25 ;
V_36 = F_57 ( V_160 , ( T_3 V_110 * ) args -> V_168 ,
sizeof( T_3 ) * args -> V_164 ) ;
if ( V_36 ) {
V_36 = - V_112 ;
goto V_89;
}
V_36 = F_87 () ;
if ( V_36 )
goto V_89;
for ( V_10 = 0 ; V_10 < args -> V_164 ; V_10 ++ ) {
V_161 = F_81 ( V_7 , args -> V_167 + V_10 ) ;
if ( F_82 ( V_161 ) ) {
V_36 = - V_112 ;
goto V_89;
}
if ( V_160 [ V_10 ] & 0x01 ) {
V_36 = - V_34 ;
goto V_89;
}
V_36 = F_88 ( V_81 -> V_80 , V_161 ,
( unsigned long ) V_160 [ V_10 ] , 0 ) ;
if ( V_36 )
goto V_89;
}
V_89:
F_85 ( V_160 ) ;
return V_36 ;
}
long F_89 ( struct V_29 * V_30 ,
unsigned int V_31 , unsigned long V_32 )
{
struct V_7 * V_7 = V_30 -> V_169 ;
void V_110 * V_170 = ( void V_110 * ) V_32 ;
struct V_104 V_105 ;
int V_36 ;
switch ( V_31 ) {
case V_171 : {
struct V_172 V_173 ;
V_36 = - V_112 ;
if ( F_57 ( & V_173 , V_170 , sizeof( V_173 ) ) )
break;
V_36 = F_90 ( V_7 , & V_173 ) ;
break;
}
case V_174 : {
struct V_92 V_93 ;
V_36 = - V_112 ;
if ( F_57 ( & V_93 , V_170 , sizeof( V_93 ) ) )
break;
V_36 = F_37 ( V_7 , & V_93 ) ;
break;
}
case V_175 : {
struct V_176 V_177 ;
V_36 = - V_34 ;
if ( V_7 -> V_12 . V_95 ) {
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_36 = F_91 ( V_7 , & V_177 , 0 , 0 ) ;
}
break;
}
case V_178 : {
V_36 = - V_112 ;
if ( F_57 ( & V_105 , ( void V_110 * ) V_32 , sizeof( V_105 ) ) )
break;
V_36 = F_74 ( V_7 , & V_105 ) ;
break;
}
case V_179 : {
V_36 = - V_112 ;
if ( F_57 ( & V_105 , ( void V_110 * ) V_32 , sizeof( V_105 ) ) )
break;
V_36 = F_75 ( V_7 , & V_105 ) ;
break;
}
case V_180 : {
V_36 = - V_112 ;
if ( F_57 ( & V_105 , ( void V_110 * ) V_32 , sizeof( V_105 ) ) )
break;
V_36 = F_76 ( V_7 , & V_105 ) ;
break;
}
case V_181 : {
struct V_159 args ;
V_36 = - V_112 ;
if ( F_57 ( & args , V_170 ,
sizeof( struct V_159 ) ) )
break;
V_36 = F_77 ( V_7 , & args ) ;
break;
}
case V_182 : {
struct V_159 args ;
V_36 = - V_112 ;
if ( F_57 ( & args , V_170 ,
sizeof( struct V_159 ) ) )
break;
V_36 = F_86 ( V_7 , & args ) ;
break;
}
default:
V_36 = - V_183 ;
}
return V_36 ;
}
static int F_92 ( T_2 * V_184 )
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
static int F_93 ( void )
{
T_2 V_184 [ 128 ] ;
int V_186 ;
if ( F_24 ( 12 ) ) {
V_186 = F_92 ( V_184 ) ;
if ( V_186 )
F_94 ( L_23 , V_186 ) ;
else
return V_184 [ 0 ] & 0x40 ;
}
return 0 ;
}
static void F_95 ( struct V_7 * V_7 )
{
V_7 -> V_12 . V_128 . V_187 = ( V_188 ) ( unsigned long ) V_7 -> V_12 . V_128 . V_129 ;
if ( F_93 () )
V_7 -> V_12 . V_128 . V_187 |= V_189 ;
else
V_7 -> V_12 . V_128 . V_187 |= V_190 ;
}
static void F_96 ( struct V_145 * V_144 )
{
F_72 ( V_144 ) ;
V_144 -> V_191 = 0xff ;
}
static void F_97 ( struct V_7 * V_7 )
{
if ( ! F_52 ( V_7 , 76 ) )
return;
V_7 -> V_12 . V_128 . V_129 = & V_7 -> V_12 . V_192 -> V_129 ;
F_95 ( V_7 ) ;
V_7 -> V_12 . V_128 . V_131 = 1 ;
V_7 -> V_12 . V_128 . V_134 = 1 ;
F_53 ( V_7 -> V_12 . V_128 . V_129 -> V_130 ,
sizeof( V_7 -> V_12 . V_128 . V_129 -> V_130 ) ) ;
F_53 ( V_7 -> V_12 . V_128 . V_129 -> V_133 ,
sizeof( V_7 -> V_12 . V_128 . V_129 -> V_133 ) ) ;
}
static void F_98 ( struct V_7 * V_7 )
{
if ( V_7 -> V_12 . V_193 )
F_99 ( V_7 -> V_12 . V_194 , sizeof( struct V_195 ) ) ;
else
F_100 ( ( unsigned long ) ( V_7 -> V_12 . V_194 ) ) ;
V_7 -> V_12 . V_194 = NULL ;
}
int F_101 ( struct V_7 * V_7 , unsigned long type )
{
int V_10 , V_196 ;
char V_197 [ 16 ] ;
static unsigned long V_198 ;
V_196 = - V_34 ;
#ifdef F_23
if ( type & ~ V_199 )
goto V_200;
if ( ( type & V_199 ) && ( ! F_102 ( V_201 ) ) )
goto V_200;
#else
if ( type )
goto V_200;
#endif
V_196 = F_21 () ;
if ( V_196 )
goto V_200;
V_196 = - V_25 ;
V_7 -> V_12 . V_193 = 0 ;
F_103 ( & V_7 -> V_12 . V_202 ) ;
V_7 -> V_12 . V_194 = (struct V_203 * ) F_104 ( V_143 ) ;
if ( ! V_7 -> V_12 . V_194 )
goto V_200;
F_105 ( & V_204 ) ;
V_198 += 16 ;
if ( V_198 + sizeof( struct V_203 ) > V_205 )
V_198 = 0 ;
V_7 -> V_12 . V_194 = (struct V_203 * )
( ( char * ) V_7 -> V_12 . V_194 + V_198 ) ;
F_106 ( & V_204 ) ;
sprintf ( V_197 , L_24 , V_81 -> V_206 ) ;
V_7 -> V_12 . V_207 = F_15 ( V_197 , 32 , 1 , 7 * sizeof( long ) ) ;
if ( ! V_7 -> V_12 . V_207 )
goto V_200;
V_7 -> V_12 . V_192 =
(struct V_192 * ) F_104 ( V_143 | V_208 ) ;
if ( ! V_7 -> V_12 . V_192 )
goto V_200;
memcpy ( V_7 -> V_12 . V_100 . V_101 , V_151 . V_152 ,
V_147 ) ;
for ( V_10 = 0 ; V_10 < V_209 ; V_10 ++ ) {
if ( V_10 < F_1 () )
V_7 -> V_12 . V_100 . V_101 [ V_10 ] &= V_1 [ V_10 ] ;
else
V_7 -> V_12 . V_100 . V_101 [ V_10 ] = 0UL ;
}
V_7 -> V_12 . V_100 . V_102 = V_7 -> V_12 . V_192 -> V_102 ;
memcpy ( V_7 -> V_12 . V_100 . V_102 , V_7 -> V_12 . V_100 . V_101 ,
V_147 ) ;
F_96 ( & V_7 -> V_12 . V_100 . V_144 ) ;
V_7 -> V_12 . V_100 . V_146 = V_61 . V_146 & 0x0fff ;
F_97 ( V_7 ) ;
F_107 ( & V_7 -> V_12 . V_210 . V_97 ) ;
for ( V_10 = 0 ; V_10 < V_211 ; V_10 ++ )
F_108 ( & V_7 -> V_12 . V_210 . V_212 [ V_10 ] ) ;
F_109 ( & V_7 -> V_12 . V_213 ) ;
F_110 ( & V_7 -> V_12 . V_214 ) ;
F_16 ( V_7 -> V_12 . V_207 , & V_26 ) ;
F_38 ( V_7 , 3 , L_25 , type ) ;
if ( type & V_199 ) {
V_7 -> V_12 . V_77 = NULL ;
V_7 -> V_12 . V_108 = V_122 ;
} else {
if ( V_61 . V_215 == V_216 )
V_7 -> V_12 . V_108 = V_217 ;
else
V_7 -> V_12 . V_108 = F_111 (unsigned long, TASK_MAX_SIZE,
sclp.hamax + 1 ) ;
V_7 -> V_12 . V_77 = F_49 ( V_81 -> V_80 , V_7 -> V_12 . V_108 - 1 ) ;
if ( ! V_7 -> V_12 . V_77 )
goto V_200;
V_7 -> V_12 . V_77 -> V_125 = V_7 ;
V_7 -> V_12 . V_77 -> V_218 = 0 ;
}
V_7 -> V_12 . V_219 = 0 ;
V_7 -> V_12 . V_95 = 0 ;
V_7 -> V_12 . V_13 = 0 ;
F_107 ( & V_7 -> V_12 . V_220 ) ;
F_112 ( 3 , L_26 , V_7 , V_81 -> V_206 ) ;
return 0 ;
V_200:
F_100 ( ( unsigned long ) V_7 -> V_12 . V_192 ) ;
F_17 ( V_7 -> V_12 . V_207 ) ;
F_98 ( V_7 ) ;
F_112 ( 3 , L_27 , V_196 ) ;
return V_196 ;
}
void F_113 ( struct V_8 * V_9 )
{
F_114 ( V_9 , 3 , L_2 , L_28 ) ;
F_115 ( V_9 -> V_221 ) ;
F_116 ( V_9 ) ;
F_117 ( V_9 ) ;
if ( ! F_47 ( V_9 -> V_7 ) )
F_118 ( V_9 ) ;
if ( F_47 ( V_9 -> V_7 ) )
F_50 ( V_9 -> V_12 . V_77 ) ;
if ( V_9 -> V_7 -> V_12 . V_118 )
F_119 ( V_9 ) ;
F_100 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
F_120 ( V_9 ) ;
F_121 ( V_222 , V_9 ) ;
}
static void F_122 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm)
F_113 ( V_9 ) ;
F_32 ( & V_7 -> V_97 ) ;
for ( V_10 = 0 ; V_10 < F_39 ( & V_7 -> V_98 ) ; V_10 ++ )
V_7 -> V_223 [ V_10 ] = NULL ;
F_123 ( & V_7 -> V_98 , 0 ) ;
F_36 ( & V_7 -> V_97 ) ;
}
void F_124 ( struct V_7 * V_7 )
{
F_122 ( V_7 ) ;
F_98 ( V_7 ) ;
F_17 ( V_7 -> V_12 . V_207 ) ;
F_100 ( ( unsigned long ) V_7 -> V_12 . V_192 ) ;
if ( ! F_47 ( V_7 ) )
F_50 ( V_7 -> V_12 . V_77 ) ;
F_125 ( V_7 ) ;
F_126 ( V_7 ) ;
F_112 ( 3 , L_29 , V_7 ) ;
}
static int F_127 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_77 = F_49 ( V_81 -> V_80 , - 1UL ) ;
if ( ! V_9 -> V_12 . V_77 )
return - V_25 ;
V_9 -> V_12 . V_77 -> V_125 = V_9 -> V_7 ;
return 0 ;
}
static void F_118 ( struct V_8 * V_9 )
{
F_128 ( & V_9 -> V_7 -> V_12 . V_202 ) ;
if ( V_9 -> V_7 -> V_12 . V_193 ) {
struct V_195 * V_194 = V_9 -> V_7 -> V_12 . V_194 ;
F_129 ( V_9 -> V_221 , ( unsigned long * ) V_194 -> V_224 ) ;
V_194 -> V_225 [ V_9 -> V_221 ] . V_226 = 0 ;
} else {
struct V_203 * V_194 = V_9 -> V_7 -> V_12 . V_194 ;
F_129 ( V_9 -> V_221 , ( unsigned long * ) & V_194 -> V_224 ) ;
V_194 -> V_225 [ V_9 -> V_221 ] . V_226 = 0 ;
}
F_130 ( & V_9 -> V_7 -> V_12 . V_202 ) ;
}
static void F_131 ( struct V_8 * V_9 )
{
F_128 ( & V_9 -> V_7 -> V_12 . V_202 ) ;
if ( V_9 -> V_7 -> V_12 . V_193 ) {
struct V_195 * V_194 = V_9 -> V_7 -> V_12 . V_194 ;
V_194 -> V_225 [ V_9 -> V_221 ] . V_226 = ( V_227 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_228 = ( V_188 ) ( ( ( V_227 ) V_194 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_229 = ( V_188 ) ( V_227 ) V_194 & ~ 0x3fU ;
V_9 -> V_12 . V_14 -> V_230 |= 0x04U ;
F_132 ( V_9 -> V_221 , ( unsigned long * ) V_194 -> V_224 ) ;
} else {
struct V_203 * V_194 = V_9 -> V_7 -> V_12 . V_194 ;
V_194 -> V_225 [ V_9 -> V_221 ] . V_226 = ( V_227 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_228 = ( V_188 ) ( ( ( V_227 ) V_194 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_229 = ( V_188 ) ( V_227 ) V_194 ;
F_132 ( V_9 -> V_221 , ( unsigned long * ) & V_194 -> V_224 ) ;
}
F_130 ( & V_9 -> V_7 -> V_12 . V_202 ) ;
}
static inline void F_133 ( struct V_231 * V_232 , struct V_233 * V_234 )
{
V_232 -> V_226 = V_234 -> V_226 ;
V_232 -> V_235 . V_236 = V_234 -> V_235 . V_236 ;
V_232 -> V_235 . V_237 = V_234 -> V_235 . V_237 ;
}
static void F_134 ( struct V_195 * V_232 , struct V_203 * V_234 )
{
int V_10 ;
V_232 -> V_238 = V_234 -> V_238 ;
V_232 -> V_224 [ 0 ] = V_234 -> V_224 ;
for ( V_10 = 0 ; V_10 < V_64 ; V_10 ++ )
F_133 ( & V_232 -> V_225 [ V_10 ] , & V_234 -> V_225 [ V_10 ] ) ;
}
static int F_135 ( struct V_7 * V_7 )
{
struct V_203 * V_239 = V_7 -> V_12 . V_194 ;
struct V_195 * V_240 ;
struct V_8 * V_9 ;
unsigned int V_241 ;
T_5 V_229 , V_228 ;
V_240 = F_136 ( sizeof( * V_240 ) , V_143 | V_242 ) ;
if ( ! V_240 )
return - V_25 ;
V_228 = ( T_5 ) ( ( V_109 ) ( V_240 ) >> 32 ) ;
V_229 = ( T_5 ) ( V_109 ) ( V_240 ) & ~ 0x3fU ;
F_137 ( V_7 ) ;
F_138 ( & V_7 -> V_12 . V_202 ) ;
F_134 ( V_240 , V_239 ) ;
F_7 (vcpu_idx, vcpu, kvm) {
V_9 -> V_12 . V_14 -> V_228 = V_228 ;
V_9 -> V_12 . V_14 -> V_229 = V_229 ;
V_9 -> V_12 . V_14 -> V_230 |= 0x04U ;
}
V_7 -> V_12 . V_194 = V_240 ;
V_7 -> V_12 . V_193 = 1 ;
F_139 ( & V_7 -> V_12 . V_202 ) ;
F_140 ( V_7 ) ;
F_100 ( ( unsigned long ) V_239 ) ;
F_38 ( V_7 , 2 , L_30 ,
V_239 , V_7 -> V_12 . V_194 ) ;
return 0 ;
}
static int F_141 ( struct V_7 * V_7 , unsigned int V_243 )
{
int V_196 ;
if ( V_243 < V_64 )
return true ;
if ( ! V_61 . V_62 )
return false ;
F_32 ( & V_7 -> V_97 ) ;
V_196 = V_7 -> V_12 . V_193 ? 0 : F_135 ( V_7 ) ;
F_36 ( & V_7 -> V_97 ) ;
return V_196 == 0 && V_243 < V_63 ;
}
int F_142 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_244 = V_245 ;
F_117 ( V_9 ) ;
V_9 -> V_246 -> V_247 = V_248 |
V_249 |
V_250 |
V_251 |
V_252 |
V_253 ;
if ( F_52 ( V_9 -> V_7 , 64 ) )
V_9 -> V_246 -> V_247 |= V_254 ;
if ( V_70 )
V_9 -> V_246 -> V_247 |= V_255 ;
else
V_9 -> V_246 -> V_247 |= V_256 ;
if ( F_47 ( V_9 -> V_7 ) )
return F_127 ( V_9 ) ;
return 0 ;
}
static void F_143 ( struct V_8 * V_9 )
{
F_144 ( V_9 -> V_12 . V_16 != 0 ) ;
F_145 ( & V_9 -> V_12 . V_257 ) ;
V_9 -> V_12 . V_16 = F_146 () ;
F_147 ( & V_9 -> V_12 . V_257 ) ;
}
static void F_148 ( struct V_8 * V_9 )
{
F_144 ( V_9 -> V_12 . V_16 == 0 ) ;
F_145 ( & V_9 -> V_12 . V_257 ) ;
V_9 -> V_12 . V_14 -> V_258 -= F_146 () - V_9 -> V_12 . V_16 ;
V_9 -> V_12 . V_16 = 0 ;
F_147 ( & V_9 -> V_12 . V_257 ) ;
}
static void F_149 ( struct V_8 * V_9 )
{
F_144 ( V_9 -> V_12 . V_15 ) ;
V_9 -> V_12 . V_15 = true ;
F_143 ( V_9 ) ;
}
static void F_150 ( struct V_8 * V_9 )
{
F_144 ( ! V_9 -> V_12 . V_15 ) ;
F_148 ( V_9 ) ;
V_9 -> V_12 . V_15 = false ;
}
static void F_151 ( struct V_8 * V_9 )
{
F_152 () ;
F_149 ( V_9 ) ;
F_153 () ;
}
static void F_154 ( struct V_8 * V_9 )
{
F_152 () ;
F_150 ( V_9 ) ;
F_153 () ;
}
void F_155 ( struct V_8 * V_9 , V_227 V_258 )
{
F_152 () ;
F_145 ( & V_9 -> V_12 . V_257 ) ;
if ( V_9 -> V_12 . V_15 )
V_9 -> V_12 . V_16 = F_146 () ;
V_9 -> V_12 . V_14 -> V_258 = V_258 ;
F_147 ( & V_9 -> V_12 . V_257 ) ;
F_153 () ;
}
V_227 F_156 ( struct V_8 * V_9 )
{
unsigned int V_259 ;
V_227 V_260 ;
if ( F_157 ( ! V_9 -> V_12 . V_15 ) )
return V_9 -> V_12 . V_14 -> V_258 ;
F_152 () ;
do {
V_259 = F_158 ( & V_9 -> V_12 . V_257 ) ;
F_144 ( ( V_259 & 1 ) && F_159 () == V_9 -> V_225 ) ;
V_260 = V_9 -> V_12 . V_14 -> V_258 ;
if ( F_160 ( V_9 -> V_12 . V_16 ) )
V_260 -= F_146 () - V_9 -> V_12 . V_16 ;
} while ( F_161 ( & V_9 -> V_12 . V_257 , V_259 & ~ 1 ) );
F_153 () ;
return V_260 ;
}
void F_162 ( struct V_8 * V_9 , int V_225 )
{
F_163 () ;
V_9 -> V_12 . V_261 . V_262 = V_81 -> V_263 . V_264 . V_262 ;
V_9 -> V_12 . V_261 . V_265 = V_81 -> V_263 . V_264 . V_265 ;
if ( V_70 )
V_81 -> V_263 . V_264 . V_265 = V_9 -> V_246 -> V_234 . V_265 . V_266 ;
else
V_81 -> V_263 . V_264 . V_265 = V_9 -> V_246 -> V_234 . V_265 . V_267 ;
V_81 -> V_263 . V_264 . V_262 = V_9 -> V_246 -> V_234 . V_265 . V_262 ;
if ( F_164 ( V_81 -> V_263 . V_264 . V_262 ) )
V_81 -> V_263 . V_264 . V_262 = 0 ;
F_165 ( V_9 -> V_12 . V_268 ) ;
F_166 ( V_9 -> V_246 -> V_234 . V_265 . V_269 ) ;
F_167 ( V_9 -> V_12 . V_77 ) ;
F_168 ( V_270 , & V_9 -> V_12 . V_14 -> V_271 ) ;
if ( V_9 -> V_12 . V_15 && ! F_169 ( V_9 ) )
F_143 ( V_9 ) ;
V_9 -> V_225 = V_225 ;
}
void F_170 ( struct V_8 * V_9 )
{
V_9 -> V_225 = - 1 ;
if ( V_9 -> V_12 . V_15 && ! F_169 ( V_9 ) )
F_148 ( V_9 ) ;
F_171 ( V_270 , & V_9 -> V_12 . V_14 -> V_271 ) ;
F_172 ( V_9 -> V_12 . V_77 ) ;
F_163 () ;
V_9 -> V_246 -> V_234 . V_265 . V_262 = V_81 -> V_263 . V_264 . V_262 ;
V_81 -> V_263 . V_264 . V_262 = V_9 -> V_12 . V_261 . V_262 ;
V_81 -> V_263 . V_264 . V_265 = V_9 -> V_12 . V_261 . V_265 ;
F_165 ( V_9 -> V_246 -> V_234 . V_265 . V_269 ) ;
F_166 ( V_9 -> V_12 . V_268 ) ;
}
static void F_173 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_272 . V_273 = 0UL ;
V_9 -> V_12 . V_14 -> V_272 . V_111 = 0UL ;
F_174 ( V_9 , 0 ) ;
F_155 ( V_9 , 0 ) ;
V_9 -> V_12 . V_14 -> V_274 = 0UL ;
V_9 -> V_12 . V_14 -> V_275 = 0 ;
memset ( V_9 -> V_12 . V_14 -> V_276 , 0 , 16 * sizeof( V_227 ) ) ;
V_9 -> V_12 . V_14 -> V_276 [ 0 ] = 0xE0UL ;
V_9 -> V_12 . V_14 -> V_276 [ 14 ] = 0xC2000000UL ;
F_163 () ;
V_81 -> V_263 . V_264 . V_262 = 0 ;
V_9 -> V_12 . V_14 -> V_277 = 1 ;
V_9 -> V_12 . V_14 -> V_278 = 0 ;
V_9 -> V_12 . V_244 = V_245 ;
F_117 ( V_9 ) ;
if ( ! F_175 ( V_9 -> V_7 ) )
F_176 ( V_9 ) ;
F_116 ( V_9 ) ;
}
void F_177 ( struct V_8 * V_9 )
{
F_32 ( & V_9 -> V_7 -> V_97 ) ;
F_152 () ;
V_9 -> V_12 . V_14 -> V_13 = V_9 -> V_7 -> V_12 . V_13 ;
F_153 () ;
F_36 ( & V_9 -> V_7 -> V_97 ) ;
if ( ! F_47 ( V_9 -> V_7 ) ) {
V_9 -> V_12 . V_77 = V_9 -> V_7 -> V_12 . V_77 ;
F_131 ( V_9 ) ;
}
}
static void F_54 ( struct V_8 * V_9 )
{
if ( ! F_52 ( V_9 -> V_7 , 76 ) )
return;
V_9 -> V_12 . V_14 -> V_279 &= ~ ( V_280 | V_281 ) ;
if ( V_9 -> V_7 -> V_12 . V_128 . V_131 )
V_9 -> V_12 . V_14 -> V_279 |= V_280 ;
if ( V_9 -> V_7 -> V_12 . V_128 . V_134 )
V_9 -> V_12 . V_14 -> V_279 |= V_281 ;
V_9 -> V_12 . V_14 -> V_187 = V_9 -> V_7 -> V_12 . V_128 . V_187 ;
}
void F_119 ( struct V_8 * V_9 )
{
F_100 ( V_9 -> V_12 . V_14 -> V_282 ) ;
V_9 -> V_12 . V_14 -> V_282 = 0 ;
}
int F_178 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_282 = F_104 ( V_143 ) ;
if ( ! V_9 -> V_12 . V_14 -> V_282 )
return - V_25 ;
V_9 -> V_12 . V_14 -> V_230 |= 0x80 ;
V_9 -> V_12 . V_14 -> V_230 &= ~ 0x08 ;
return 0 ;
}
static void F_179 ( struct V_8 * V_9 )
{
struct V_283 * V_100 = & V_9 -> V_7 -> V_12 . V_100 ;
V_9 -> V_12 . V_144 = V_100 -> V_144 ;
V_9 -> V_12 . V_14 -> V_146 = V_100 -> V_146 ;
if ( F_52 ( V_9 -> V_7 , 7 ) )
V_9 -> V_12 . V_14 -> V_284 = ( T_5 ) ( V_109 ) V_100 -> V_102 ;
}
int F_180 ( struct V_8 * V_9 )
{
int V_196 = 0 ;
F_123 ( & V_9 -> V_12 . V_14 -> V_271 , V_285 |
V_286 |
V_287 ) ;
if ( F_52 ( V_9 -> V_7 , 78 ) )
F_168 ( V_288 , & V_9 -> V_12 . V_14 -> V_271 ) ;
else if ( F_52 ( V_9 -> V_7 , 8 ) )
F_168 ( V_289 , & V_9 -> V_12 . V_14 -> V_271 ) ;
F_179 ( V_9 ) ;
V_9 -> V_12 . V_14 -> V_290 = 6 ;
if ( F_52 ( V_9 -> V_7 , 50 ) && F_52 ( V_9 -> V_7 , 73 ) )
V_9 -> V_12 . V_14 -> V_290 |= 0x10 ;
V_9 -> V_12 . V_14 -> V_230 = 8 ;
V_9 -> V_12 . V_14 -> V_291 = 0xC1002000U ;
if ( V_61 . V_292 )
V_9 -> V_12 . V_14 -> V_291 |= 1 ;
if ( V_61 . V_293 )
V_9 -> V_12 . V_14 -> V_291 |= 0x10000000U ;
if ( F_52 ( V_9 -> V_7 , 64 ) )
V_9 -> V_12 . V_14 -> V_279 |= 0x01 ;
if ( F_52 ( V_9 -> V_7 , 129 ) ) {
V_9 -> V_12 . V_14 -> V_291 |= 0x00020000 ;
V_9 -> V_12 . V_14 -> V_294 |= 0x20000000 ;
}
V_9 -> V_12 . V_14 -> V_295 = ( unsigned long ) & V_9 -> V_246 -> V_234 . V_265 . V_296 ;
V_9 -> V_12 . V_14 -> V_297 |= V_298 | V_299 | V_300 ;
if ( V_9 -> V_7 -> V_12 . V_118 ) {
V_196 = F_178 ( V_9 ) ;
if ( V_196 )
return V_196 ;
}
F_181 ( & V_9 -> V_12 . V_301 , V_302 , V_303 ) ;
V_9 -> V_12 . V_301 . V_304 = V_305 ;
F_54 ( V_9 ) ;
return V_196 ;
}
struct V_8 * F_182 ( struct V_7 * V_7 ,
unsigned int V_243 )
{
struct V_8 * V_9 ;
struct V_306 * V_306 ;
int V_196 = - V_34 ;
if ( ! F_47 ( V_7 ) && ! F_141 ( V_7 , V_243 ) )
goto V_89;
V_196 = - V_25 ;
V_9 = F_183 ( V_222 , V_143 ) ;
if ( ! V_9 )
goto V_89;
V_306 = (struct V_306 * ) F_104 ( V_143 ) ;
if ( ! V_306 )
goto V_307;
V_9 -> V_12 . V_14 = & V_306 -> V_14 ;
V_9 -> V_12 . V_14 -> V_308 = ( unsigned long ) & V_306 -> V_309 ;
V_9 -> V_12 . V_14 -> V_310 = V_243 ;
F_107 ( & V_9 -> V_12 . V_311 . V_97 ) ;
V_9 -> V_12 . V_311 . V_210 = & V_7 -> V_12 . V_210 ;
V_9 -> V_12 . V_311 . V_312 = & V_9 -> V_312 ;
V_9 -> V_12 . V_311 . V_271 = & V_9 -> V_12 . V_14 -> V_271 ;
F_184 ( & V_9 -> V_12 . V_257 ) ;
V_196 = F_185 ( V_9 , V_7 , V_243 ) ;
if ( V_196 )
goto V_313;
F_38 ( V_7 , 3 , L_31 , V_243 , V_9 ,
V_9 -> V_12 . V_14 ) ;
F_186 ( V_243 , V_9 , V_9 -> V_12 . V_14 ) ;
return V_9 ;
V_313:
F_100 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
V_307:
F_121 ( V_222 , V_9 ) ;
V_89:
return F_187 ( V_196 ) ;
}
int F_188 ( struct V_8 * V_9 )
{
return F_189 ( V_9 , 0 ) ;
}
void F_190 ( struct V_8 * V_9 )
{
F_168 ( V_314 , & V_9 -> V_12 . V_14 -> V_315 ) ;
F_55 ( V_9 ) ;
}
void F_191 ( struct V_8 * V_9 )
{
F_171 ( V_314 , & V_9 -> V_12 . V_14 -> V_315 ) ;
}
static void F_192 ( struct V_8 * V_9 )
{
F_168 ( V_316 , & V_9 -> V_12 . V_14 -> V_315 ) ;
F_55 ( V_9 ) ;
}
static void F_193 ( struct V_8 * V_9 )
{
F_171 ( V_316 , & V_9 -> V_12 . V_14 -> V_315 ) ;
}
void F_55 ( struct V_8 * V_9 )
{
F_168 ( V_317 , & V_9 -> V_12 . V_14 -> V_271 ) ;
while ( V_9 -> V_12 . V_14 -> V_318 & V_319 )
F_194 () ;
}
void F_195 ( int V_320 , struct V_8 * V_9 )
{
F_196 ( V_320 , V_9 ) ;
F_192 ( V_9 ) ;
}
static void V_20 ( struct V_77 * V_77 , unsigned long V_76 )
{
int V_10 ;
struct V_7 * V_7 = V_77 -> V_125 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
if ( F_197 ( V_9 ) == ( V_76 & ~ 0x1000UL ) ) {
F_114 ( V_9 , 2 , L_32 , V_76 ) ;
F_195 ( V_321 , V_9 ) ;
}
}
}
int F_198 ( struct V_8 * V_9 )
{
F_199 () ;
return 0 ;
}
static int F_200 ( struct V_8 * V_9 ,
struct V_322 * V_323 )
{
int V_36 = - V_34 ;
switch ( V_323 -> V_243 ) {
case V_324 :
V_36 = F_42 ( V_9 -> V_12 . V_14 -> V_275 ,
( T_5 V_110 * ) V_323 -> V_111 ) ;
break;
case V_325 :
V_36 = F_42 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_109 V_110 * ) V_323 -> V_111 ) ;
break;
case V_326 :
V_36 = F_42 ( F_156 ( V_9 ) ,
( V_109 V_110 * ) V_323 -> V_111 ) ;
break;
case V_327 :
V_36 = F_42 ( V_9 -> V_12 . V_14 -> V_274 ,
( V_109 V_110 * ) V_323 -> V_111 ) ;
break;
case V_328 :
V_36 = F_42 ( V_9 -> V_12 . V_244 ,
( V_109 V_110 * ) V_323 -> V_111 ) ;
break;
case V_329 :
V_36 = F_42 ( V_9 -> V_12 . V_330 ,
( V_109 V_110 * ) V_323 -> V_111 ) ;
break;
case V_331 :
V_36 = F_42 ( V_9 -> V_12 . V_332 ,
( V_109 V_110 * ) V_323 -> V_111 ) ;
break;
case V_333 :
V_36 = F_42 ( V_9 -> V_12 . V_14 -> V_278 ,
( V_109 V_110 * ) V_323 -> V_111 ) ;
break;
case V_334 :
V_36 = F_42 ( V_9 -> V_12 . V_14 -> V_277 ,
( V_109 V_110 * ) V_323 -> V_111 ) ;
break;
default:
break;
}
return V_36 ;
}
static int F_201 ( struct V_8 * V_9 ,
struct V_322 * V_323 )
{
int V_36 = - V_34 ;
V_227 V_5 ;
switch ( V_323 -> V_243 ) {
case V_324 :
V_36 = F_48 ( V_9 -> V_12 . V_14 -> V_275 ,
( T_5 V_110 * ) V_323 -> V_111 ) ;
break;
case V_325 :
V_36 = F_48 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_109 V_110 * ) V_323 -> V_111 ) ;
break;
case V_326 :
V_36 = F_48 ( V_5 , ( V_109 V_110 * ) V_323 -> V_111 ) ;
if ( ! V_36 )
F_155 ( V_9 , V_5 ) ;
break;
case V_327 :
V_36 = F_48 ( V_9 -> V_12 . V_14 -> V_274 ,
( V_109 V_110 * ) V_323 -> V_111 ) ;
break;
case V_328 :
V_36 = F_48 ( V_9 -> V_12 . V_244 ,
( V_109 V_110 * ) V_323 -> V_111 ) ;
if ( V_9 -> V_12 . V_244 == V_245 )
F_117 ( V_9 ) ;
break;
case V_329 :
V_36 = F_48 ( V_9 -> V_12 . V_330 ,
( V_109 V_110 * ) V_323 -> V_111 ) ;
break;
case V_331 :
V_36 = F_48 ( V_9 -> V_12 . V_332 ,
( V_109 V_110 * ) V_323 -> V_111 ) ;
break;
case V_333 :
V_36 = F_48 ( V_9 -> V_12 . V_14 -> V_278 ,
( V_109 V_110 * ) V_323 -> V_111 ) ;
break;
case V_334 :
V_36 = F_48 ( V_9 -> V_12 . V_14 -> V_277 ,
( V_109 V_110 * ) V_323 -> V_111 ) ;
break;
default:
break;
}
return V_36 ;
}
static int F_202 ( struct V_8 * V_9 )
{
F_173 ( V_9 ) ;
return 0 ;
}
int F_203 ( struct V_8 * V_9 , struct V_335 * V_265 )
{
memcpy ( & V_9 -> V_246 -> V_234 . V_265 . V_336 , & V_265 -> V_336 , sizeof( V_265 -> V_336 ) ) ;
return 0 ;
}
int F_204 ( struct V_8 * V_9 , struct V_335 * V_265 )
{
memcpy ( & V_265 -> V_336 , & V_9 -> V_246 -> V_234 . V_265 . V_336 , sizeof( V_265 -> V_336 ) ) ;
return 0 ;
}
int F_205 ( struct V_8 * V_9 ,
struct V_337 * V_338 )
{
memcpy ( & V_9 -> V_246 -> V_234 . V_265 . V_269 , & V_338 -> V_269 , sizeof( V_338 -> V_269 ) ) ;
memcpy ( & V_9 -> V_12 . V_14 -> V_276 , & V_338 -> V_339 , sizeof( V_338 -> V_339 ) ) ;
F_166 ( V_9 -> V_246 -> V_234 . V_265 . V_269 ) ;
return 0 ;
}
int F_206 ( struct V_8 * V_9 ,
struct V_337 * V_338 )
{
memcpy ( & V_338 -> V_269 , & V_9 -> V_246 -> V_234 . V_265 . V_269 , sizeof( V_338 -> V_269 ) ) ;
memcpy ( & V_338 -> V_339 , & V_9 -> V_12 . V_14 -> V_276 , sizeof( V_338 -> V_339 ) ) ;
return 0 ;
}
int F_207 ( struct V_8 * V_9 , struct V_340 * V_264 )
{
F_163 () ;
if ( F_164 ( V_264 -> V_262 ) )
return - V_34 ;
V_81 -> V_263 . V_264 . V_262 = V_264 -> V_262 ;
if ( V_70 )
F_208 ( V_81 -> V_263 . V_264 . V_341 , ( V_342 * ) V_264 -> V_267 ) ;
else
memcpy ( V_81 -> V_263 . V_264 . V_267 , & V_264 -> V_267 , sizeof( V_264 -> V_267 ) ) ;
return 0 ;
}
int F_209 ( struct V_8 * V_9 , struct V_340 * V_264 )
{
F_163 () ;
if ( V_70 )
F_210 ( ( V_342 * ) V_264 -> V_267 , V_81 -> V_263 . V_264 . V_341 ) ;
else
memcpy ( V_264 -> V_267 , V_81 -> V_263 . V_264 . V_267 , sizeof( V_264 -> V_267 ) ) ;
V_264 -> V_262 = V_81 -> V_263 . V_264 . V_262 ;
return 0 ;
}
static int F_211 ( struct V_8 * V_9 , T_6 V_343 )
{
int V_196 = 0 ;
if ( ! F_212 ( V_9 ) )
V_196 = - V_99 ;
else {
V_9 -> V_246 -> V_344 = V_343 . V_273 ;
V_9 -> V_246 -> V_345 = V_343 . V_111 ;
}
return V_196 ;
}
int F_213 ( struct V_8 * V_9 ,
struct V_346 * V_347 )
{
return - V_34 ;
}
int F_214 ( struct V_8 * V_9 ,
struct V_348 * V_349 )
{
int V_196 = 0 ;
V_9 -> V_350 = 0 ;
F_215 ( V_9 ) ;
if ( V_349 -> V_351 & ~ V_352 )
return - V_34 ;
if ( V_349 -> V_351 & V_353 ) {
V_9 -> V_350 = V_349 -> V_351 ;
F_168 ( V_354 , & V_9 -> V_12 . V_14 -> V_271 ) ;
if ( V_349 -> V_351 & V_355 )
V_196 = F_216 ( V_9 , V_349 ) ;
} else {
F_171 ( V_354 , & V_9 -> V_12 . V_14 -> V_271 ) ;
V_9 -> V_12 . V_356 . V_357 = 0 ;
}
if ( V_196 ) {
V_9 -> V_350 = 0 ;
F_215 ( V_9 ) ;
F_171 ( V_354 , & V_9 -> V_12 . V_14 -> V_271 ) ;
}
return V_196 ;
}
int F_217 ( struct V_8 * V_9 ,
struct V_358 * V_359 )
{
return F_212 ( V_9 ) ? V_360 :
V_361 ;
}
int F_218 ( struct V_8 * V_9 ,
struct V_358 * V_359 )
{
int V_196 = 0 ;
V_9 -> V_7 -> V_12 . V_362 = 1 ;
switch ( V_359 -> V_359 ) {
case V_360 :
F_176 ( V_9 ) ;
break;
case V_361 :
F_219 ( V_9 ) ;
break;
case V_363 :
case V_364 :
default:
V_196 = - V_113 ;
}
return V_196 ;
}
static bool F_220 ( struct V_8 * V_9 )
{
return F_39 ( & V_9 -> V_12 . V_14 -> V_271 ) & V_365 ;
}
static int F_221 ( struct V_8 * V_9 )
{
V_366:
F_193 ( V_9 ) ;
if ( ! V_9 -> V_367 )
return 0 ;
if ( F_222 ( V_321 , V_9 ) ) {
int V_196 ;
V_196 = F_223 ( V_9 -> V_12 . V_77 ,
F_197 ( V_9 ) ,
V_205 * 2 ) ;
if ( V_196 )
return V_196 ;
goto V_366;
}
if ( F_222 ( V_368 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_369 = 0xffff ;
goto V_366;
}
if ( F_222 ( V_370 , V_9 ) ) {
if ( ! F_220 ( V_9 ) ) {
F_224 ( V_9 -> V_221 , 1 ) ;
F_168 ( V_365 ,
& V_9 -> V_12 . V_14 -> V_271 ) ;
}
goto V_366;
}
if ( F_222 ( V_371 , V_9 ) ) {
if ( F_220 ( V_9 ) ) {
F_224 ( V_9 -> V_221 , 0 ) ;
F_171 ( V_365 ,
& V_9 -> V_12 . V_14 -> V_271 ) ;
}
goto V_366;
}
F_225 ( V_372 , & V_9 -> V_367 ) ;
return 0 ;
}
void F_59 ( struct V_7 * V_7 , V_109 V_373 )
{
struct V_8 * V_9 ;
int V_10 ;
F_32 ( & V_7 -> V_97 ) ;
F_152 () ;
V_7 -> V_12 . V_13 = V_373 - F_226 () ;
F_137 ( V_7 ) ;
F_7 (i, vcpu, kvm)
V_9 -> V_12 . V_14 -> V_13 = V_7 -> V_12 . V_13 ;
F_140 ( V_7 ) ;
F_153 () ;
F_36 ( & V_7 -> V_97 ) ;
}
long F_227 ( struct V_8 * V_9 , T_7 V_374 , int V_375 )
{
return F_228 ( V_9 -> V_12 . V_77 , V_374 ,
V_375 ? V_376 : 0 ) ;
}
static void F_229 ( struct V_8 * V_9 , bool V_377 ,
unsigned long V_378 )
{
struct V_172 V_379 ;
struct V_380 V_381 ;
if ( V_377 ) {
V_381 . V_382 . V_35 . V_383 = V_378 ;
V_381 . type = V_384 ;
F_144 ( F_230 ( V_9 , & V_381 ) ) ;
} else {
V_379 . type = V_385 ;
V_379 . V_386 = V_378 ;
F_144 ( F_90 ( V_9 -> V_7 , & V_379 ) ) ;
}
}
void F_231 ( struct V_8 * V_9 ,
struct V_387 * V_388 )
{
F_232 ( V_9 , V_388 -> V_12 . V_244 ) ;
F_229 ( V_9 , true , V_388 -> V_12 . V_244 ) ;
}
void F_233 ( struct V_8 * V_9 ,
struct V_387 * V_388 )
{
F_234 ( V_9 , V_388 -> V_12 . V_244 ) ;
F_229 ( V_9 , false , V_388 -> V_12 . V_244 ) ;
}
void F_235 ( struct V_8 * V_9 ,
struct V_387 * V_388 )
{
}
bool F_236 ( struct V_8 * V_9 )
{
return true ;
}
static int F_237 ( struct V_8 * V_9 )
{
T_8 V_161 ;
struct V_389 V_12 ;
int V_196 ;
if ( V_9 -> V_12 . V_244 == V_245 )
return 0 ;
if ( ( V_9 -> V_12 . V_14 -> V_272 . V_273 & V_9 -> V_12 . V_332 ) !=
V_9 -> V_12 . V_330 )
return 0 ;
if ( F_238 ( V_9 ) )
return 0 ;
if ( F_189 ( V_9 , 0 ) )
return 0 ;
if ( ! ( V_9 -> V_12 . V_14 -> V_276 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_9 -> V_12 . V_77 -> V_218 )
return 0 ;
V_161 = F_81 ( V_9 -> V_7 , F_239 ( V_81 -> V_263 . V_390 ) ) ;
V_161 += V_81 -> V_263 . V_390 & ~ V_391 ;
if ( F_240 ( V_9 , V_9 -> V_12 . V_244 , & V_12 . V_244 , 8 ) )
return 0 ;
V_196 = F_241 ( V_9 , V_81 -> V_263 . V_390 , V_161 , & V_12 ) ;
return V_196 ;
}
static int F_242 ( struct V_8 * V_9 )
{
int V_196 , V_271 ;
F_243 ( V_9 ) ;
V_9 -> V_12 . V_14 -> V_392 = V_9 -> V_246 -> V_234 . V_265 . V_336 [ 14 ] ;
V_9 -> V_12 . V_14 -> V_393 = V_9 -> V_246 -> V_234 . V_265 . V_336 [ 15 ] ;
if ( F_244 () )
F_245 () ;
if ( F_246 ( V_394 ) )
F_247 () ;
if ( ! F_47 ( V_9 -> V_7 ) ) {
V_196 = F_248 ( V_9 ) ;
if ( V_196 )
return V_196 ;
}
V_196 = F_221 ( V_9 ) ;
if ( V_196 )
return V_196 ;
if ( F_249 ( V_9 ) ) {
F_250 ( V_9 ) ;
F_251 ( V_9 ) ;
}
V_9 -> V_12 . V_14 -> V_395 = 0 ;
V_271 = F_39 ( & V_9 -> V_12 . V_14 -> V_271 ) ;
F_114 ( V_9 , 6 , L_33 , V_271 ) ;
F_252 ( V_9 , V_271 ) ;
return 0 ;
}
static int F_253 ( struct V_8 * V_9 )
{
struct V_396 V_397 = {
. V_398 = V_399 ,
} ;
T_2 V_400 , V_401 ;
int V_196 ;
F_114 ( V_9 , 3 , L_2 , L_34 ) ;
F_254 ( V_9 ) ;
V_196 = F_255 ( V_9 , & V_400 , 1 ) ;
V_401 = F_256 ( V_400 ) ;
if ( V_196 < 0 ) {
return V_196 ;
} else if ( V_196 ) {
V_397 = V_9 -> V_12 . V_402 ;
V_401 = 4 ;
}
V_397 . V_94 = V_401 | V_403 ;
F_257 ( V_9 , V_401 ) ;
return F_258 ( V_9 , & V_397 ) ;
}
static int F_259 ( struct V_8 * V_9 , int V_404 )
{
F_114 ( V_9 , 6 , L_35 ,
V_9 -> V_12 . V_14 -> V_395 ) ;
F_260 ( V_9 , V_9 -> V_12 . V_14 -> V_395 ) ;
if ( F_249 ( V_9 ) )
F_261 ( V_9 ) ;
V_9 -> V_246 -> V_234 . V_265 . V_336 [ 14 ] = V_9 -> V_12 . V_14 -> V_392 ;
V_9 -> V_246 -> V_234 . V_265 . V_336 [ 15 ] = V_9 -> V_12 . V_14 -> V_393 ;
if ( V_9 -> V_12 . V_14 -> V_395 > 0 ) {
int V_196 = F_262 ( V_9 ) ;
if ( V_196 != - V_405 )
return V_196 ;
V_9 -> V_246 -> V_404 = V_406 ;
V_9 -> V_246 -> V_407 . V_395 = V_9 -> V_12 . V_14 -> V_395 ;
V_9 -> V_246 -> V_407 . V_408 = V_9 -> V_12 . V_14 -> V_408 ;
V_9 -> V_246 -> V_407 . V_409 = V_9 -> V_12 . V_14 -> V_409 ;
return - V_410 ;
} else if ( V_404 != - V_112 ) {
V_9 -> V_411 . V_412 ++ ;
return 0 ;
} else if ( F_47 ( V_9 -> V_7 ) ) {
V_9 -> V_246 -> V_404 = V_413 ;
V_9 -> V_246 -> V_414 . V_415 =
V_81 -> V_263 . V_390 ;
V_9 -> V_246 -> V_414 . V_416 = 0x10 ;
return - V_410 ;
} else if ( V_81 -> V_263 . V_417 ) {
F_263 ( V_9 ) ;
V_81 -> V_263 . V_417 = 0 ;
if ( F_237 ( V_9 ) )
return 0 ;
return F_227 ( V_9 , V_81 -> V_263 . V_390 , 1 ) ;
}
return F_253 ( V_9 ) ;
}
static int F_264 ( struct V_8 * V_9 )
{
int V_196 , V_404 ;
V_9 -> V_418 = F_44 ( & V_9 -> V_7 -> V_120 ) ;
do {
V_196 = F_242 ( V_9 ) ;
if ( V_196 )
break;
F_46 ( & V_9 -> V_7 -> V_120 , V_9 -> V_418 ) ;
F_265 () ;
F_266 () ;
F_150 ( V_9 ) ;
F_267 () ;
V_404 = F_268 ( V_9 -> V_12 . V_14 ,
V_9 -> V_246 -> V_234 . V_265 . V_336 ) ;
F_265 () ;
F_149 ( V_9 ) ;
F_269 () ;
F_267 () ;
V_9 -> V_418 = F_44 ( & V_9 -> V_7 -> V_120 ) ;
V_196 = F_259 ( V_9 , V_404 ) ;
} while ( ! F_270 ( V_81 ) && ! F_271 ( V_9 ) && ! V_196 );
F_46 ( & V_9 -> V_7 -> V_120 , V_9 -> V_418 ) ;
return V_196 ;
}
static void F_272 ( struct V_8 * V_9 , struct V_419 * V_419 )
{
V_9 -> V_12 . V_14 -> V_272 . V_273 = V_419 -> V_344 ;
V_9 -> V_12 . V_14 -> V_272 . V_111 = V_419 -> V_345 ;
if ( V_419 -> V_420 & V_248 )
F_174 ( V_9 , V_419 -> V_234 . V_265 . V_421 ) ;
if ( V_419 -> V_420 & V_251 ) {
memcpy ( & V_9 -> V_12 . V_14 -> V_276 , & V_419 -> V_234 . V_265 . V_339 , 128 ) ;
F_196 ( V_368 , V_9 ) ;
}
if ( V_419 -> V_420 & V_252 ) {
F_155 ( V_9 , V_419 -> V_234 . V_265 . V_258 ) ;
V_9 -> V_12 . V_14 -> V_274 = V_419 -> V_234 . V_265 . V_274 ;
V_9 -> V_12 . V_14 -> V_275 = V_419 -> V_234 . V_265 . V_275 ;
V_9 -> V_12 . V_14 -> V_278 = V_419 -> V_234 . V_265 . V_278 ;
V_9 -> V_12 . V_14 -> V_277 = V_419 -> V_234 . V_265 . V_277 ;
}
if ( V_419 -> V_420 & V_253 ) {
V_9 -> V_12 . V_244 = V_419 -> V_234 . V_265 . V_422 ;
V_9 -> V_12 . V_332 = V_419 -> V_234 . V_265 . V_423 ;
V_9 -> V_12 . V_330 = V_419 -> V_234 . V_265 . V_424 ;
if ( V_9 -> V_12 . V_244 == V_245 )
F_117 ( V_9 ) ;
}
V_419 -> V_420 = 0 ;
}
static void F_273 ( struct V_8 * V_9 , struct V_419 * V_419 )
{
V_419 -> V_344 = V_9 -> V_12 . V_14 -> V_272 . V_273 ;
V_419 -> V_345 = V_9 -> V_12 . V_14 -> V_272 . V_111 ;
V_419 -> V_234 . V_265 . V_421 = F_197 ( V_9 ) ;
memcpy ( & V_419 -> V_234 . V_265 . V_339 , & V_9 -> V_12 . V_14 -> V_276 , 128 ) ;
V_419 -> V_234 . V_265 . V_258 = F_156 ( V_9 ) ;
V_419 -> V_234 . V_265 . V_274 = V_9 -> V_12 . V_14 -> V_274 ;
V_419 -> V_234 . V_265 . V_275 = V_9 -> V_12 . V_14 -> V_275 ;
V_419 -> V_234 . V_265 . V_278 = V_9 -> V_12 . V_14 -> V_278 ;
V_419 -> V_234 . V_265 . V_277 = V_9 -> V_12 . V_14 -> V_277 ;
V_419 -> V_234 . V_265 . V_422 = V_9 -> V_12 . V_244 ;
V_419 -> V_234 . V_265 . V_423 = V_9 -> V_12 . V_332 ;
V_419 -> V_234 . V_265 . V_424 = V_9 -> V_12 . V_330 ;
}
int F_274 ( struct V_8 * V_9 , struct V_419 * V_419 )
{
int V_196 ;
T_9 V_425 ;
if ( F_271 ( V_9 ) ) {
F_275 ( V_9 ) ;
return 0 ;
}
if ( V_9 -> V_426 )
F_276 ( V_427 , & V_9 -> V_428 , & V_425 ) ;
if ( ! F_175 ( V_9 -> V_7 ) ) {
F_219 ( V_9 ) ;
} else if ( F_212 ( V_9 ) ) {
F_277 ( L_36 ,
V_9 -> V_221 ) ;
return - V_34 ;
}
F_272 ( V_9 , V_419 ) ;
F_151 ( V_9 ) ;
F_278 () ;
V_196 = F_264 ( V_9 ) ;
if ( F_270 ( V_81 ) && ! V_196 ) {
V_419 -> V_404 = V_429 ;
V_196 = - V_430 ;
}
if ( F_271 ( V_9 ) && ! V_196 ) {
F_275 ( V_9 ) ;
V_196 = 0 ;
}
if ( V_196 == - V_410 ) {
V_196 = 0 ;
}
F_154 ( V_9 ) ;
F_273 ( V_9 , V_419 ) ;
if ( V_9 -> V_426 )
F_276 ( V_427 , & V_425 , NULL ) ;
V_9 -> V_411 . V_431 ++ ;
return V_196 ;
}
int F_279 ( struct V_8 * V_9 , unsigned long V_374 )
{
unsigned char V_432 = 1 ;
V_342 V_267 [ V_433 ] ;
unsigned int V_434 ;
V_109 V_435 , V_258 ;
int V_196 ;
V_434 = F_197 ( V_9 ) ;
if ( V_374 == V_436 ) {
if ( F_280 ( V_9 , 163 , & V_432 , 1 ) )
return - V_112 ;
V_374 = 0 ;
} else if ( V_374 == V_437 ) {
if ( F_281 ( V_9 , 163 , & V_432 , 1 ) )
return - V_112 ;
V_374 = V_434 ;
} else
V_374 -= V_438 ;
if ( V_70 ) {
F_210 ( V_267 , ( V_439 * ) V_9 -> V_246 -> V_234 . V_265 . V_266 ) ;
V_196 = F_280 ( V_9 , V_374 + V_438 ,
V_267 , 128 ) ;
} else {
V_196 = F_280 ( V_9 , V_374 + V_438 ,
V_9 -> V_246 -> V_234 . V_265 . V_267 , 128 ) ;
}
V_196 |= F_280 ( V_9 , V_374 + V_440 ,
V_9 -> V_246 -> V_234 . V_265 . V_336 , 128 ) ;
V_196 |= F_280 ( V_9 , V_374 + V_441 ,
& V_9 -> V_12 . V_14 -> V_272 , 16 ) ;
V_196 |= F_280 ( V_9 , V_374 + V_442 ,
& V_434 , 4 ) ;
V_196 |= F_280 ( V_9 , V_374 + V_443 ,
& V_9 -> V_246 -> V_234 . V_265 . V_262 , 4 ) ;
V_196 |= F_280 ( V_9 , V_374 + V_444 ,
& V_9 -> V_12 . V_14 -> V_275 , 4 ) ;
V_258 = F_156 ( V_9 ) ;
V_196 |= F_280 ( V_9 , V_374 + V_445 ,
& V_258 , 8 ) ;
V_435 = V_9 -> V_12 . V_14 -> V_274 >> 8 ;
V_196 |= F_280 ( V_9 , V_374 + V_446 ,
& V_435 , 8 ) ;
V_196 |= F_280 ( V_9 , V_374 + V_447 ,
& V_9 -> V_246 -> V_234 . V_265 . V_269 , 64 ) ;
V_196 |= F_280 ( V_9 , V_374 + V_448 ,
& V_9 -> V_12 . V_14 -> V_276 , 128 ) ;
return V_196 ? - V_112 : 0 ;
}
int F_282 ( struct V_8 * V_9 , unsigned long V_111 )
{
F_163 () ;
V_9 -> V_246 -> V_234 . V_265 . V_262 = V_81 -> V_263 . V_264 . V_262 ;
F_165 ( V_9 -> V_246 -> V_234 . V_265 . V_269 ) ;
return F_279 ( V_9 , V_111 ) ;
}
int F_283 ( struct V_8 * V_9 ,
unsigned long V_374 )
{
if ( ! ( V_374 & ~ 0x3ff ) )
return 0 ;
return F_280 ( V_9 , V_374 & ~ 0x3ff ,
( void * ) & V_9 -> V_246 -> V_234 . V_265 . V_266 , 512 ) ;
}
int F_284 ( struct V_8 * V_9 , unsigned long V_111 )
{
if ( ! F_52 ( V_9 -> V_7 , 129 ) )
return 0 ;
F_163 () ;
return F_283 ( V_9 , V_111 ) ;
}
static void F_285 ( struct V_8 * V_9 )
{
F_222 ( V_370 , V_9 ) ;
F_195 ( V_371 , V_9 ) ;
}
static void F_286 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
F_285 ( V_9 ) ;
}
}
static void F_287 ( struct V_8 * V_9 )
{
F_222 ( V_371 , V_9 ) ;
F_195 ( V_370 , V_9 ) ;
}
void F_219 ( struct V_8 * V_9 )
{
int V_10 , V_98 , V_449 = 0 ;
if ( ! F_212 ( V_9 ) )
return;
F_288 ( V_9 -> V_221 , 1 ) ;
F_105 ( & V_9 -> V_7 -> V_12 . V_220 ) ;
V_98 = F_39 ( & V_9 -> V_7 -> V_98 ) ;
for ( V_10 = 0 ; V_10 < V_98 ; V_10 ++ ) {
if ( ! F_212 ( V_9 -> V_7 -> V_223 [ V_10 ] ) )
V_449 ++ ;
}
if ( V_449 == 0 ) {
F_287 ( V_9 ) ;
} else if ( V_449 == 1 ) {
F_286 ( V_9 -> V_7 ) ;
}
F_171 ( V_287 , & V_9 -> V_12 . V_14 -> V_271 ) ;
F_196 ( V_368 , V_9 ) ;
F_106 ( & V_9 -> V_7 -> V_12 . V_220 ) ;
return;
}
void F_176 ( struct V_8 * V_9 )
{
int V_10 , V_98 , V_449 = 0 ;
struct V_8 * V_450 = NULL ;
if ( F_212 ( V_9 ) )
return;
F_288 ( V_9 -> V_221 , 0 ) ;
F_105 ( & V_9 -> V_7 -> V_12 . V_220 ) ;
V_98 = F_39 ( & V_9 -> V_7 -> V_98 ) ;
F_289 ( V_9 ) ;
F_168 ( V_287 , & V_9 -> V_12 . V_14 -> V_271 ) ;
F_285 ( V_9 ) ;
for ( V_10 = 0 ; V_10 < V_98 ; V_10 ++ ) {
if ( ! F_212 ( V_9 -> V_7 -> V_223 [ V_10 ] ) ) {
V_449 ++ ;
V_450 = V_9 -> V_7 -> V_223 [ V_10 ] ;
}
}
if ( V_449 == 1 ) {
F_287 ( V_450 ) ;
}
F_106 ( & V_9 -> V_7 -> V_12 . V_220 ) ;
return;
}
static int F_290 ( struct V_8 * V_9 ,
struct V_92 * V_93 )
{
int V_36 ;
if ( V_93 -> V_94 )
return - V_34 ;
switch ( V_93 -> V_93 ) {
case V_45 :
if ( ! V_9 -> V_7 -> V_12 . V_219 ) {
V_9 -> V_7 -> V_12 . V_219 = 1 ;
F_38 ( V_9 -> V_7 , 3 , L_2 , L_37 ) ;
F_291 ( V_9 -> V_7 ) ;
}
V_36 = 0 ;
break;
default:
V_36 = - V_34 ;
break;
}
return V_36 ;
}
static long F_292 ( struct V_8 * V_9 ,
struct V_451 * V_452 )
{
void V_110 * V_453 = ( void V_110 * ) V_452 -> V_454 ;
void * V_455 = NULL ;
int V_36 , V_418 ;
const V_109 V_456 = V_457
| V_458 ;
if ( V_452 -> V_94 & ~ V_456 )
return - V_34 ;
if ( V_452 -> V_459 > V_58 )
return - V_123 ;
if ( ! ( V_452 -> V_94 & V_458 ) ) {
V_455 = F_80 ( V_452 -> V_459 ) ;
if ( ! V_455 )
return - V_25 ;
}
V_418 = F_44 ( & V_9 -> V_7 -> V_120 ) ;
switch ( V_452 -> V_460 ) {
case V_461 :
if ( V_452 -> V_94 & V_458 ) {
V_36 = F_293 ( V_9 , V_452 -> V_462 , V_452 -> V_463 ,
V_452 -> V_459 , V_464 ) ;
break;
}
V_36 = F_294 ( V_9 , V_452 -> V_462 , V_452 -> V_463 , V_455 , V_452 -> V_459 ) ;
if ( V_36 == 0 ) {
if ( F_62 ( V_453 , V_455 , V_452 -> V_459 ) )
V_36 = - V_112 ;
}
break;
case V_465 :
if ( V_452 -> V_94 & V_458 ) {
V_36 = F_293 ( V_9 , V_452 -> V_462 , V_452 -> V_463 ,
V_452 -> V_459 , V_466 ) ;
break;
}
if ( F_57 ( V_455 , V_453 , V_452 -> V_459 ) ) {
V_36 = - V_112 ;
break;
}
V_36 = F_295 ( V_9 , V_452 -> V_462 , V_452 -> V_463 , V_455 , V_452 -> V_459 ) ;
break;
default:
V_36 = - V_34 ;
}
F_46 ( & V_9 -> V_7 -> V_120 , V_418 ) ;
if ( V_36 > 0 && ( V_452 -> V_94 & V_457 ) != 0 )
F_258 ( V_9 , & V_9 -> V_12 . V_402 ) ;
F_296 ( V_455 ) ;
return V_36 ;
}
long F_297 ( struct V_29 * V_30 ,
unsigned int V_31 , unsigned long V_32 )
{
struct V_8 * V_9 = V_30 -> V_169 ;
void V_110 * V_170 = ( void V_110 * ) V_32 ;
int V_114 ;
long V_36 ;
switch ( V_31 ) {
case V_467 : {
struct V_380 V_468 ;
V_36 = - V_112 ;
if ( F_57 ( & V_468 , V_170 , sizeof( V_468 ) ) )
break;
V_36 = F_230 ( V_9 , & V_468 ) ;
break;
}
case V_171 : {
struct V_172 V_173 ;
struct V_380 V_468 ;
V_36 = - V_112 ;
if ( F_57 ( & V_173 , V_170 , sizeof( V_173 ) ) )
break;
if ( F_298 ( & V_173 , & V_468 ) )
return - V_34 ;
V_36 = F_230 ( V_9 , & V_468 ) ;
break;
}
case V_469 :
V_114 = F_44 ( & V_9 -> V_7 -> V_120 ) ;
V_36 = F_282 ( V_9 , V_32 ) ;
F_46 ( & V_9 -> V_7 -> V_120 , V_114 ) ;
break;
case V_470 : {
T_6 V_343 ;
V_36 = - V_112 ;
if ( F_57 ( & V_343 , V_170 , sizeof( V_343 ) ) )
break;
V_36 = F_211 ( V_9 , V_343 ) ;
break;
}
case V_471 :
V_36 = F_202 ( V_9 ) ;
break;
case V_472 :
case V_473 : {
struct V_322 V_323 ;
V_36 = - V_112 ;
if ( F_57 ( & V_323 , V_170 , sizeof( V_323 ) ) )
break;
if ( V_31 == V_472 )
V_36 = F_201 ( V_9 , & V_323 ) ;
else
V_36 = F_200 ( V_9 , & V_323 ) ;
break;
}
#ifdef F_23
case V_474 : {
struct V_475 V_476 ;
if ( F_57 ( & V_476 , V_170 , sizeof( V_476 ) ) ) {
V_36 = - V_112 ;
break;
}
if ( ! F_47 ( V_9 -> V_7 ) ) {
V_36 = - V_34 ;
break;
}
V_36 = F_299 ( V_9 -> V_12 . V_77 , V_476 . V_477 ,
V_476 . V_478 , V_476 . V_479 ) ;
break;
}
case V_480 : {
struct V_475 V_476 ;
if ( F_57 ( & V_476 , V_170 , sizeof( V_476 ) ) ) {
V_36 = - V_112 ;
break;
}
if ( ! F_47 ( V_9 -> V_7 ) ) {
V_36 = - V_34 ;
break;
}
V_36 = F_300 ( V_9 -> V_12 . V_77 , V_476 . V_478 ,
V_476 . V_479 ) ;
break;
}
#endif
case V_481 : {
V_36 = F_228 ( V_9 -> V_12 . V_77 , V_32 , 0 ) ;
break;
}
case V_174 :
{
struct V_92 V_93 ;
V_36 = - V_112 ;
if ( F_57 ( & V_93 , V_170 , sizeof( V_93 ) ) )
break;
V_36 = F_290 ( V_9 , & V_93 ) ;
break;
}
case V_482 : {
struct V_451 V_483 ;
if ( F_57 ( & V_483 , V_170 , sizeof( V_483 ) ) == 0 )
V_36 = F_292 ( V_9 , & V_483 ) ;
else
V_36 = - V_112 ;
break;
}
case V_484 : {
struct V_485 V_486 ;
V_36 = - V_112 ;
if ( F_57 ( & V_486 , V_170 , sizeof( V_486 ) ) )
break;
if ( V_486 . V_487 > V_488 ||
V_486 . V_487 == 0 ||
V_486 . V_487 % sizeof( struct V_380 ) > 0 ) {
V_36 = - V_34 ;
break;
}
V_36 = F_301 ( V_9 ,
( void V_110 * ) V_486 . V_454 ,
V_486 . V_487 ) ;
break;
}
case V_489 : {
struct V_485 V_486 ;
V_36 = - V_112 ;
if ( F_57 ( & V_486 , V_170 , sizeof( V_486 ) ) )
break;
if ( V_486 . V_487 == 0 ) {
V_36 = - V_34 ;
break;
}
V_36 = F_302 ( V_9 ,
( V_490 V_110 * ) V_486 . V_454 ,
V_486 . V_487 ) ;
break;
}
default:
V_36 = - V_183 ;
}
return V_36 ;
}
int F_303 ( struct V_8 * V_9 , struct V_491 * V_492 )
{
#ifdef F_23
if ( ( V_492 -> V_493 == V_494 )
&& ( F_47 ( V_9 -> V_7 ) ) ) {
V_492 -> V_495 = F_304 ( V_9 -> V_12 . V_14 ) ;
F_305 ( V_492 -> V_495 ) ;
return 0 ;
}
#endif
return V_496 ;
}
int F_306 ( struct V_7 * V_7 , struct V_72 * V_88 ,
unsigned long V_79 )
{
return 0 ;
}
int F_307 ( struct V_7 * V_7 ,
struct V_72 * V_73 ,
const struct V_497 * V_498 ,
enum V_499 V_500 )
{
if ( V_498 -> V_501 & 0xffffful )
return - V_34 ;
if ( V_498 -> V_502 & 0xffffful )
return - V_34 ;
if ( V_498 -> V_503 + V_498 -> V_502 > V_7 -> V_12 . V_108 )
return - V_34 ;
return 0 ;
}
void F_308 ( struct V_7 * V_7 ,
const struct V_497 * V_498 ,
const struct V_72 * V_504 ,
const struct V_72 * V_124 ,
enum V_499 V_500 )
{
int V_196 ;
if ( V_504 -> V_501 == V_498 -> V_501 &&
V_504 -> V_78 * V_205 == V_498 -> V_503 &&
V_504 -> V_79 * V_205 == V_498 -> V_502 )
return;
V_196 = F_299 ( V_7 -> V_12 . V_77 , V_498 -> V_501 ,
V_498 -> V_503 , V_498 -> V_502 ) ;
if ( V_196 )
F_309 ( L_38 ) ;
return;
}
static int T_10 F_310 ( void )
{
if ( ! V_61 . V_505 ) {
F_311 ( L_39 ) ;
return - V_506 ;
}
return F_312 ( NULL , sizeof( struct V_8 ) , 0 , V_507 ) ;
}
static void T_11 F_313 ( void )
{
F_314 () ;
}
