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
T_3 V_143 , V_144 ;
int V_106 = 0 ;
F_32 ( & V_7 -> V_97 ) ;
if ( F_39 ( & V_7 -> V_98 ) ) {
V_106 = - V_99 ;
goto V_89;
}
V_142 = F_67 ( sizeof( * V_142 ) , V_145 ) ;
if ( ! V_142 ) {
V_106 = - V_25 ;
goto V_89;
}
if ( ! F_57 ( V_142 , ( void V_110 * ) V_105 -> V_111 ,
sizeof( * V_142 ) ) ) {
V_7 -> V_12 . V_100 . V_146 = V_142 -> V_146 ;
V_143 = V_61 . V_147 >> 16 & 0xfff ;
V_144 = V_61 . V_147 & 0xfff ;
if ( V_143 && V_142 -> V_147 ) {
if ( V_142 -> V_147 > V_144 )
V_7 -> V_12 . V_100 . V_147 = V_144 ;
else if ( V_142 -> V_147 < V_143 )
V_7 -> V_12 . V_100 . V_147 = V_143 ;
else
V_7 -> V_12 . V_100 . V_147 = V_142 -> V_147 ;
}
memcpy ( V_7 -> V_12 . V_100 . V_102 , V_142 -> V_102 ,
V_148 ) ;
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
case V_149 :
V_106 = F_66 ( V_7 , V_105 ) ;
break;
}
return V_106 ;
}
static int F_70 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
struct V_141 * V_142 ;
int V_106 = 0 ;
V_142 = F_67 ( sizeof( * V_142 ) , V_145 ) ;
if ( ! V_142 ) {
V_106 = - V_25 ;
goto V_89;
}
V_142 -> V_146 = V_7 -> V_12 . V_100 . V_146 ;
V_142 -> V_147 = V_7 -> V_12 . V_100 . V_147 ;
memcpy ( & V_142 -> V_102 , V_7 -> V_12 . V_100 . V_102 ,
V_148 ) ;
if ( F_62 ( ( void V_110 * ) V_105 -> V_111 , V_142 , sizeof( * V_142 ) ) )
V_106 = - V_112 ;
F_68 ( V_142 ) ;
V_89:
return V_106 ;
}
static int F_71 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
struct V_150 * V_151 ;
int V_106 = 0 ;
V_151 = F_67 ( sizeof( * V_151 ) , V_145 ) ;
if ( ! V_151 ) {
V_106 = - V_25 ;
goto V_89;
}
F_72 ( (struct V_146 * ) & V_151 -> V_146 ) ;
V_151 -> V_147 = V_61 . V_147 ;
memcpy ( & V_151 -> V_101 , V_7 -> V_12 . V_100 . V_101 ,
V_148 ) ;
memcpy ( ( unsigned long * ) & V_151 -> V_102 , V_152 . V_153 ,
V_148 ) ;
if ( F_62 ( ( void V_110 * ) V_105 -> V_111 , V_151 , sizeof( * V_151 ) ) )
V_106 = - V_112 ;
F_68 ( V_151 ) ;
V_89:
return V_106 ;
}
static int F_73 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
int V_106 = - V_113 ;
switch ( V_105 -> V_105 ) {
case V_149 :
V_106 = F_70 ( V_7 , V_105 ) ;
break;
case V_154 :
V_106 = F_71 ( V_7 , V_105 ) ;
break;
}
return V_106 ;
}
static int F_74 ( struct V_7 * V_7 , struct V_104 * V_105 )
{
int V_106 ;
switch ( V_105 -> V_155 ) {
case V_156 :
V_106 = F_43 ( V_7 , V_105 ) ;
break;
case V_157 :
V_106 = F_60 ( V_7 , V_105 ) ;
break;
case V_158 :
V_106 = F_69 ( V_7 , V_105 ) ;
break;
case V_159 :
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
switch ( V_105 -> V_155 ) {
case V_156 :
V_106 = F_41 ( V_7 , V_105 ) ;
break;
case V_157 :
V_106 = F_65 ( V_7 , V_105 ) ;
break;
case V_158 :
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
switch ( V_105 -> V_155 ) {
case V_156 :
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
case V_157 :
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
case V_158 :
switch ( V_105 -> V_105 ) {
case V_149 :
case V_154 :
V_106 = 0 ;
break;
default:
V_106 = - V_113 ;
break;
}
break;
case V_159 :
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
static long F_77 ( struct V_7 * V_7 , struct V_160 * args )
{
T_4 * V_161 ;
T_5 V_162 ;
unsigned long V_163 ;
int V_10 , V_36 = 0 ;
if ( args -> V_94 != 0 )
return - V_34 ;
if ( ! F_78 ( V_81 -> V_80 ) )
return V_164 ;
if ( args -> V_165 < 1 || args -> V_165 > V_166 )
return - V_34 ;
V_161 = F_79 ( args -> V_165 , sizeof( T_4 ) ,
V_145 | V_167 ) ;
if ( ! V_161 )
V_161 = F_80 ( sizeof( T_4 ) * args -> V_165 ) ;
if ( ! V_161 )
return - V_25 ;
for ( V_10 = 0 ; V_10 < args -> V_165 ; V_10 ++ ) {
V_162 = F_81 ( V_7 , args -> V_168 + V_10 ) ;
if ( F_82 ( V_162 ) ) {
V_36 = - V_112 ;
goto V_89;
}
V_163 = F_83 ( V_81 -> V_80 , V_162 ) ;
if ( F_84 ( V_163 ) ) {
V_36 = V_163 ;
goto V_89;
}
V_161 [ V_10 ] = V_163 ;
}
V_36 = F_62 ( ( T_4 V_110 * ) args -> V_169 , V_161 ,
sizeof( T_4 ) * args -> V_165 ) ;
if ( V_36 )
V_36 = - V_112 ;
V_89:
F_85 ( V_161 ) ;
return V_36 ;
}
static long F_86 ( struct V_7 * V_7 , struct V_160 * args )
{
T_4 * V_161 ;
T_5 V_162 ;
int V_10 , V_36 = 0 ;
if ( args -> V_94 != 0 )
return - V_34 ;
if ( args -> V_165 < 1 || args -> V_165 > V_166 )
return - V_34 ;
V_161 = F_79 ( args -> V_165 , sizeof( T_4 ) ,
V_145 | V_167 ) ;
if ( ! V_161 )
V_161 = F_80 ( sizeof( T_4 ) * args -> V_165 ) ;
if ( ! V_161 )
return - V_25 ;
V_36 = F_57 ( V_161 , ( T_4 V_110 * ) args -> V_169 ,
sizeof( T_4 ) * args -> V_165 ) ;
if ( V_36 ) {
V_36 = - V_112 ;
goto V_89;
}
V_36 = F_87 () ;
if ( V_36 )
goto V_89;
for ( V_10 = 0 ; V_10 < args -> V_165 ; V_10 ++ ) {
V_162 = F_81 ( V_7 , args -> V_168 + V_10 ) ;
if ( F_82 ( V_162 ) ) {
V_36 = - V_112 ;
goto V_89;
}
if ( V_161 [ V_10 ] & 0x01 ) {
V_36 = - V_34 ;
goto V_89;
}
V_36 = F_88 ( V_81 -> V_80 , V_162 ,
( unsigned long ) V_161 [ V_10 ] , 0 ) ;
if ( V_36 )
goto V_89;
}
V_89:
F_85 ( V_161 ) ;
return V_36 ;
}
long F_89 ( struct V_29 * V_30 ,
unsigned int V_31 , unsigned long V_32 )
{
struct V_7 * V_7 = V_30 -> V_170 ;
void V_110 * V_171 = ( void V_110 * ) V_32 ;
struct V_104 V_105 ;
int V_36 ;
switch ( V_31 ) {
case V_172 : {
struct V_173 V_174 ;
V_36 = - V_112 ;
if ( F_57 ( & V_174 , V_171 , sizeof( V_174 ) ) )
break;
V_36 = F_90 ( V_7 , & V_174 ) ;
break;
}
case V_175 : {
struct V_92 V_93 ;
V_36 = - V_112 ;
if ( F_57 ( & V_93 , V_171 , sizeof( V_93 ) ) )
break;
V_36 = F_37 ( V_7 , & V_93 ) ;
break;
}
case V_176 : {
struct V_177 V_178 ;
V_36 = - V_34 ;
if ( V_7 -> V_12 . V_95 ) {
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_36 = F_91 ( V_7 , & V_178 , 0 , 0 ) ;
}
break;
}
case V_179 : {
V_36 = - V_112 ;
if ( F_57 ( & V_105 , ( void V_110 * ) V_32 , sizeof( V_105 ) ) )
break;
V_36 = F_74 ( V_7 , & V_105 ) ;
break;
}
case V_180 : {
V_36 = - V_112 ;
if ( F_57 ( & V_105 , ( void V_110 * ) V_32 , sizeof( V_105 ) ) )
break;
V_36 = F_75 ( V_7 , & V_105 ) ;
break;
}
case V_181 : {
V_36 = - V_112 ;
if ( F_57 ( & V_105 , ( void V_110 * ) V_32 , sizeof( V_105 ) ) )
break;
V_36 = F_76 ( V_7 , & V_105 ) ;
break;
}
case V_182 : {
struct V_160 args ;
V_36 = - V_112 ;
if ( F_57 ( & args , V_171 ,
sizeof( struct V_160 ) ) )
break;
V_36 = F_77 ( V_7 , & args ) ;
break;
}
case V_183 : {
struct V_160 args ;
V_36 = - V_112 ;
if ( F_57 ( & args , V_171 ,
sizeof( struct V_160 ) ) )
break;
V_36 = F_86 ( V_7 , & args ) ;
break;
}
default:
V_36 = - V_184 ;
}
return V_36 ;
}
static int F_92 ( T_2 * V_185 )
{
T_6 V_186 = 0x04000000UL ;
T_6 V_187 = 0 ;
memset ( V_185 , 0 , 128 ) ;
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
return V_187 ;
}
static int F_93 ( void )
{
T_2 V_185 [ 128 ] ;
int V_187 ;
if ( F_24 ( 12 ) ) {
V_187 = F_92 ( V_185 ) ;
if ( V_187 )
F_94 ( L_23 , V_187 ) ;
else
return V_185 [ 0 ] & 0x40 ;
}
return 0 ;
}
static void F_95 ( struct V_7 * V_7 )
{
V_7 -> V_12 . V_128 . V_188 = ( V_189 ) ( unsigned long ) V_7 -> V_12 . V_128 . V_129 ;
if ( F_93 () )
V_7 -> V_12 . V_128 . V_188 |= V_190 ;
else
V_7 -> V_12 . V_128 . V_188 |= V_191 ;
}
static V_109 F_96 ( void )
{
struct V_146 V_146 ;
F_72 ( & V_146 ) ;
V_146 . V_192 = 0xff ;
return * ( ( V_109 * ) & V_146 ) ;
}
static void F_97 ( struct V_7 * V_7 )
{
if ( ! F_52 ( V_7 , 76 ) )
return;
V_7 -> V_12 . V_128 . V_129 = & V_7 -> V_12 . V_193 -> V_129 ;
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
if ( V_7 -> V_12 . V_194 )
F_99 ( V_7 -> V_12 . V_195 , sizeof( struct V_196 ) ) ;
else
F_100 ( ( unsigned long ) ( V_7 -> V_12 . V_195 ) ) ;
V_7 -> V_12 . V_195 = NULL ;
}
int F_101 ( struct V_7 * V_7 , unsigned long type )
{
int V_10 , V_197 ;
char V_198 [ 16 ] ;
static unsigned long V_199 ;
V_197 = - V_34 ;
#ifdef F_23
if ( type & ~ V_200 )
goto V_201;
if ( ( type & V_200 ) && ( ! F_102 ( V_202 ) ) )
goto V_201;
#else
if ( type )
goto V_201;
#endif
V_197 = F_21 () ;
if ( V_197 )
goto V_201;
V_197 = - V_25 ;
V_7 -> V_12 . V_194 = 0 ;
F_103 ( & V_7 -> V_12 . V_203 ) ;
V_7 -> V_12 . V_195 = (struct V_204 * ) F_104 ( V_145 ) ;
if ( ! V_7 -> V_12 . V_195 )
goto V_201;
F_105 ( & V_205 ) ;
V_199 += 16 ;
if ( V_199 + sizeof( struct V_204 ) > V_206 )
V_199 = 0 ;
V_7 -> V_12 . V_195 = (struct V_204 * )
( ( char * ) V_7 -> V_12 . V_195 + V_199 ) ;
F_106 ( & V_205 ) ;
sprintf ( V_198 , L_24 , V_81 -> V_207 ) ;
V_7 -> V_12 . V_208 = F_15 ( V_198 , 32 , 1 , 7 * sizeof( long ) ) ;
if ( ! V_7 -> V_12 . V_208 )
goto V_201;
V_7 -> V_12 . V_193 =
(struct V_193 * ) F_104 ( V_145 | V_209 ) ;
if ( ! V_7 -> V_12 . V_193 )
goto V_201;
memcpy ( V_7 -> V_12 . V_100 . V_101 , V_152 . V_153 ,
V_148 ) ;
for ( V_10 = 0 ; V_10 < V_210 ; V_10 ++ ) {
if ( V_10 < F_1 () )
V_7 -> V_12 . V_100 . V_101 [ V_10 ] &= V_1 [ V_10 ] ;
else
V_7 -> V_12 . V_100 . V_101 [ V_10 ] = 0UL ;
}
V_7 -> V_12 . V_100 . V_102 = V_7 -> V_12 . V_193 -> V_102 ;
memcpy ( V_7 -> V_12 . V_100 . V_102 , V_7 -> V_12 . V_100 . V_101 ,
V_148 ) ;
V_7 -> V_12 . V_100 . V_146 = F_96 () ;
V_7 -> V_12 . V_100 . V_147 = V_61 . V_147 & 0x0fff ;
F_97 ( V_7 ) ;
F_107 ( & V_7 -> V_12 . V_211 . V_97 ) ;
for ( V_10 = 0 ; V_10 < V_212 ; V_10 ++ )
F_108 ( & V_7 -> V_12 . V_211 . V_213 [ V_10 ] ) ;
F_109 ( & V_7 -> V_12 . V_214 ) ;
F_110 ( & V_7 -> V_12 . V_215 ) ;
F_16 ( V_7 -> V_12 . V_208 , & V_26 ) ;
F_38 ( V_7 , 3 , L_25 , type ) ;
if ( type & V_200 ) {
V_7 -> V_12 . V_77 = NULL ;
V_7 -> V_12 . V_108 = V_122 ;
} else {
if ( V_61 . V_216 == V_217 )
V_7 -> V_12 . V_108 = V_218 ;
else
V_7 -> V_12 . V_108 = F_111 (unsigned long, TASK_MAX_SIZE,
sclp.hamax + 1 ) ;
V_7 -> V_12 . V_77 = F_49 ( V_81 -> V_80 , V_7 -> V_12 . V_108 - 1 ) ;
if ( ! V_7 -> V_12 . V_77 )
goto V_201;
V_7 -> V_12 . V_77 -> V_125 = V_7 ;
V_7 -> V_12 . V_77 -> V_219 = 0 ;
}
V_7 -> V_12 . V_220 = 0 ;
V_7 -> V_12 . V_95 = 0 ;
V_7 -> V_12 . V_13 = 0 ;
F_107 ( & V_7 -> V_12 . V_221 ) ;
F_112 ( 3 , L_26 , V_7 , V_81 -> V_207 ) ;
return 0 ;
V_201:
F_100 ( ( unsigned long ) V_7 -> V_12 . V_193 ) ;
F_17 ( V_7 -> V_12 . V_208 ) ;
F_98 ( V_7 ) ;
F_112 ( 3 , L_27 , V_197 ) ;
return V_197 ;
}
void F_113 ( struct V_8 * V_9 )
{
F_114 ( V_9 , 3 , L_2 , L_28 ) ;
F_115 ( V_9 -> V_222 ) ;
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
F_121 ( V_223 , V_9 ) ;
}
static void F_122 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm)
F_113 ( V_9 ) ;
F_32 ( & V_7 -> V_97 ) ;
for ( V_10 = 0 ; V_10 < F_39 ( & V_7 -> V_98 ) ; V_10 ++ )
V_7 -> V_224 [ V_10 ] = NULL ;
F_123 ( & V_7 -> V_98 , 0 ) ;
F_36 ( & V_7 -> V_97 ) ;
}
void F_124 ( struct V_7 * V_7 )
{
F_122 ( V_7 ) ;
F_98 ( V_7 ) ;
F_17 ( V_7 -> V_12 . V_208 ) ;
F_100 ( ( unsigned long ) V_7 -> V_12 . V_193 ) ;
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
F_128 ( & V_9 -> V_7 -> V_12 . V_203 ) ;
if ( V_9 -> V_7 -> V_12 . V_194 ) {
struct V_196 * V_195 = V_9 -> V_7 -> V_12 . V_195 ;
F_129 ( V_9 -> V_222 , ( unsigned long * ) V_195 -> V_225 ) ;
V_195 -> V_226 [ V_9 -> V_222 ] . V_227 = 0 ;
} else {
struct V_204 * V_195 = V_9 -> V_7 -> V_12 . V_195 ;
F_129 ( V_9 -> V_222 , ( unsigned long * ) & V_195 -> V_225 ) ;
V_195 -> V_226 [ V_9 -> V_222 ] . V_227 = 0 ;
}
F_130 ( & V_9 -> V_7 -> V_12 . V_203 ) ;
}
static void F_131 ( struct V_8 * V_9 )
{
F_128 ( & V_9 -> V_7 -> V_12 . V_203 ) ;
if ( V_9 -> V_7 -> V_12 . V_194 ) {
struct V_196 * V_195 = V_9 -> V_7 -> V_12 . V_195 ;
V_195 -> V_226 [ V_9 -> V_222 ] . V_227 = ( V_228 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_229 = ( V_189 ) ( ( ( V_228 ) V_195 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_230 = ( V_189 ) ( V_228 ) V_195 & ~ 0x3fU ;
V_9 -> V_12 . V_14 -> V_231 |= 0x04U ;
F_132 ( V_9 -> V_222 , ( unsigned long * ) V_195 -> V_225 ) ;
} else {
struct V_204 * V_195 = V_9 -> V_7 -> V_12 . V_195 ;
V_195 -> V_226 [ V_9 -> V_222 ] . V_227 = ( V_228 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_229 = ( V_189 ) ( ( ( V_228 ) V_195 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_230 = ( V_189 ) ( V_228 ) V_195 ;
F_132 ( V_9 -> V_222 , ( unsigned long * ) & V_195 -> V_225 ) ;
}
F_130 ( & V_9 -> V_7 -> V_12 . V_203 ) ;
}
static inline void F_133 ( struct V_232 * V_233 , struct V_234 * V_235 )
{
V_233 -> V_227 = V_235 -> V_227 ;
V_233 -> V_236 . V_237 = V_235 -> V_236 . V_237 ;
V_233 -> V_236 . V_238 = V_235 -> V_236 . V_238 ;
}
static void F_134 ( struct V_196 * V_233 , struct V_204 * V_235 )
{
int V_10 ;
V_233 -> V_239 = V_235 -> V_239 ;
V_233 -> V_225 [ 0 ] = V_235 -> V_225 ;
for ( V_10 = 0 ; V_10 < V_64 ; V_10 ++ )
F_133 ( & V_233 -> V_226 [ V_10 ] , & V_235 -> V_226 [ V_10 ] ) ;
}
static int F_135 ( struct V_7 * V_7 )
{
struct V_204 * V_240 = V_7 -> V_12 . V_195 ;
struct V_196 * V_241 ;
struct V_8 * V_9 ;
unsigned int V_242 ;
T_6 V_230 , V_229 ;
V_241 = F_136 ( sizeof( * V_241 ) , V_145 | V_243 ) ;
if ( ! V_241 )
return - V_25 ;
V_229 = ( T_6 ) ( ( V_109 ) ( V_241 ) >> 32 ) ;
V_230 = ( T_6 ) ( V_109 ) ( V_241 ) & ~ 0x3fU ;
F_137 ( V_7 ) ;
F_138 ( & V_7 -> V_12 . V_203 ) ;
F_134 ( V_241 , V_240 ) ;
F_7 (vcpu_idx, vcpu, kvm) {
V_9 -> V_12 . V_14 -> V_229 = V_229 ;
V_9 -> V_12 . V_14 -> V_230 = V_230 ;
V_9 -> V_12 . V_14 -> V_231 |= 0x04U ;
}
V_7 -> V_12 . V_195 = V_241 ;
V_7 -> V_12 . V_194 = 1 ;
F_139 ( & V_7 -> V_12 . V_203 ) ;
F_140 ( V_7 ) ;
F_100 ( ( unsigned long ) V_240 ) ;
F_38 ( V_7 , 2 , L_30 ,
V_240 , V_7 -> V_12 . V_195 ) ;
return 0 ;
}
static int F_141 ( struct V_7 * V_7 , unsigned int V_244 )
{
int V_197 ;
if ( V_244 < V_64 )
return true ;
if ( ! V_61 . V_62 )
return false ;
F_32 ( & V_7 -> V_97 ) ;
V_197 = V_7 -> V_12 . V_194 ? 0 : F_135 ( V_7 ) ;
F_36 ( & V_7 -> V_97 ) ;
return V_197 == 0 && V_244 < V_63 ;
}
int F_142 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_245 = V_246 ;
F_117 ( V_9 ) ;
V_9 -> V_247 -> V_248 = V_249 |
V_250 |
V_251 |
V_252 |
V_253 |
V_254 ;
if ( F_52 ( V_9 -> V_7 , 64 ) )
V_9 -> V_247 -> V_248 |= V_255 ;
if ( V_70 )
V_9 -> V_247 -> V_248 |= V_256 ;
else
V_9 -> V_247 -> V_248 |= V_257 ;
if ( F_47 ( V_9 -> V_7 ) )
return F_127 ( V_9 ) ;
return 0 ;
}
static void F_143 ( struct V_8 * V_9 )
{
F_144 ( V_9 -> V_12 . V_16 != 0 ) ;
F_145 ( & V_9 -> V_12 . V_258 ) ;
V_9 -> V_12 . V_16 = F_146 () ;
F_147 ( & V_9 -> V_12 . V_258 ) ;
}
static void F_148 ( struct V_8 * V_9 )
{
F_144 ( V_9 -> V_12 . V_16 == 0 ) ;
F_145 ( & V_9 -> V_12 . V_258 ) ;
V_9 -> V_12 . V_14 -> V_259 -= F_146 () - V_9 -> V_12 . V_16 ;
V_9 -> V_12 . V_16 = 0 ;
F_147 ( & V_9 -> V_12 . V_258 ) ;
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
void F_155 ( struct V_8 * V_9 , V_228 V_259 )
{
F_152 () ;
F_145 ( & V_9 -> V_12 . V_258 ) ;
if ( V_9 -> V_12 . V_15 )
V_9 -> V_12 . V_16 = F_146 () ;
V_9 -> V_12 . V_14 -> V_259 = V_259 ;
F_147 ( & V_9 -> V_12 . V_258 ) ;
F_153 () ;
}
V_228 F_156 ( struct V_8 * V_9 )
{
unsigned int V_260 ;
V_228 V_261 ;
if ( F_157 ( ! V_9 -> V_12 . V_15 ) )
return V_9 -> V_12 . V_14 -> V_259 ;
F_152 () ;
do {
V_260 = F_158 ( & V_9 -> V_12 . V_258 ) ;
F_144 ( ( V_260 & 1 ) && F_159 () == V_9 -> V_226 ) ;
V_261 = V_9 -> V_12 . V_14 -> V_259 ;
if ( F_160 ( V_9 -> V_12 . V_16 ) )
V_261 -= F_146 () - V_9 -> V_12 . V_16 ;
} while ( F_161 ( & V_9 -> V_12 . V_258 , V_260 & ~ 1 ) );
F_153 () ;
return V_261 ;
}
void F_162 ( struct V_8 * V_9 , int V_226 )
{
F_163 () ;
V_9 -> V_12 . V_262 . V_263 = V_81 -> V_264 . V_265 . V_263 ;
V_9 -> V_12 . V_262 . V_266 = V_81 -> V_264 . V_265 . V_266 ;
if ( V_70 )
V_81 -> V_264 . V_265 . V_266 = V_9 -> V_247 -> V_235 . V_266 . V_267 ;
else
V_81 -> V_264 . V_265 . V_266 = V_9 -> V_247 -> V_235 . V_266 . V_268 ;
V_81 -> V_264 . V_265 . V_263 = V_9 -> V_247 -> V_235 . V_266 . V_263 ;
if ( F_164 ( V_81 -> V_264 . V_265 . V_263 ) )
V_81 -> V_264 . V_265 . V_263 = 0 ;
F_165 ( V_9 -> V_12 . V_269 ) ;
F_166 ( V_9 -> V_247 -> V_235 . V_266 . V_270 ) ;
F_167 ( V_9 -> V_12 . V_77 ) ;
F_168 ( V_271 , & V_9 -> V_12 . V_14 -> V_272 ) ;
if ( V_9 -> V_12 . V_15 && ! F_169 ( V_9 ) )
F_143 ( V_9 ) ;
V_9 -> V_226 = V_226 ;
}
void F_170 ( struct V_8 * V_9 )
{
V_9 -> V_226 = - 1 ;
if ( V_9 -> V_12 . V_15 && ! F_169 ( V_9 ) )
F_148 ( V_9 ) ;
F_171 ( V_271 , & V_9 -> V_12 . V_14 -> V_272 ) ;
F_172 ( V_9 -> V_12 . V_77 ) ;
F_163 () ;
V_9 -> V_247 -> V_235 . V_266 . V_263 = V_81 -> V_264 . V_265 . V_263 ;
V_81 -> V_264 . V_265 . V_263 = V_9 -> V_12 . V_262 . V_263 ;
V_81 -> V_264 . V_265 . V_266 = V_9 -> V_12 . V_262 . V_266 ;
F_165 ( V_9 -> V_247 -> V_235 . V_266 . V_270 ) ;
F_166 ( V_9 -> V_12 . V_269 ) ;
}
static void F_173 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_273 . V_274 = 0UL ;
V_9 -> V_12 . V_14 -> V_273 . V_111 = 0UL ;
F_174 ( V_9 , 0 ) ;
F_155 ( V_9 , 0 ) ;
V_9 -> V_12 . V_14 -> V_275 = 0UL ;
V_9 -> V_12 . V_14 -> V_276 = 0 ;
memset ( V_9 -> V_12 . V_14 -> V_277 , 0 , 16 * sizeof( V_228 ) ) ;
V_9 -> V_12 . V_14 -> V_277 [ 0 ] = 0xE0UL ;
V_9 -> V_12 . V_14 -> V_277 [ 14 ] = 0xC2000000UL ;
F_163 () ;
V_81 -> V_264 . V_265 . V_263 = 0 ;
V_9 -> V_12 . V_14 -> V_278 = 1 ;
V_9 -> V_12 . V_14 -> V_279 = 0 ;
V_9 -> V_12 . V_245 = V_246 ;
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
V_9 -> V_12 . V_14 -> V_280 &= ~ ( V_281 | V_282 ) ;
if ( V_9 -> V_7 -> V_12 . V_128 . V_131 )
V_9 -> V_12 . V_14 -> V_280 |= V_281 ;
if ( V_9 -> V_7 -> V_12 . V_128 . V_134 )
V_9 -> V_12 . V_14 -> V_280 |= V_282 ;
V_9 -> V_12 . V_14 -> V_188 = V_9 -> V_7 -> V_12 . V_128 . V_188 ;
}
void F_119 ( struct V_8 * V_9 )
{
F_100 ( V_9 -> V_12 . V_14 -> V_283 ) ;
V_9 -> V_12 . V_14 -> V_283 = 0 ;
}
int F_178 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_283 = F_104 ( V_145 ) ;
if ( ! V_9 -> V_12 . V_14 -> V_283 )
return - V_25 ;
V_9 -> V_12 . V_14 -> V_231 |= 0x80 ;
V_9 -> V_12 . V_14 -> V_231 &= ~ 0x08 ;
return 0 ;
}
static void F_179 ( struct V_8 * V_9 )
{
struct V_284 * V_100 = & V_9 -> V_7 -> V_12 . V_100 ;
V_9 -> V_12 . V_14 -> V_147 = V_100 -> V_147 ;
if ( F_52 ( V_9 -> V_7 , 7 ) )
V_9 -> V_12 . V_14 -> V_285 = ( T_6 ) ( V_109 ) V_100 -> V_102 ;
}
int F_180 ( struct V_8 * V_9 )
{
int V_197 = 0 ;
F_123 ( & V_9 -> V_12 . V_14 -> V_272 , V_286 |
V_287 |
V_288 ) ;
if ( F_52 ( V_9 -> V_7 , 78 ) )
F_168 ( V_289 , & V_9 -> V_12 . V_14 -> V_272 ) ;
else if ( F_52 ( V_9 -> V_7 , 8 ) )
F_168 ( V_290 , & V_9 -> V_12 . V_14 -> V_272 ) ;
F_179 ( V_9 ) ;
V_9 -> V_12 . V_14 -> V_291 = 0x02 ;
if ( F_52 ( V_9 -> V_7 , 9 ) )
V_9 -> V_12 . V_14 -> V_291 |= 0x04 ;
if ( F_52 ( V_9 -> V_7 , 50 ) && F_52 ( V_9 -> V_7 , 73 ) )
V_9 -> V_12 . V_14 -> V_291 |= 0x10 ;
if ( F_52 ( V_9 -> V_7 , 8 ) )
V_9 -> V_12 . V_14 -> V_231 |= 0x08 ;
V_9 -> V_12 . V_14 -> V_292 = 0xC1002000U ;
if ( V_61 . V_293 )
V_9 -> V_12 . V_14 -> V_292 |= 1 ;
if ( V_61 . V_294 )
V_9 -> V_12 . V_14 -> V_292 |= 0x10000000U ;
if ( F_52 ( V_9 -> V_7 , 64 ) )
V_9 -> V_12 . V_14 -> V_280 |= 0x01 ;
if ( F_52 ( V_9 -> V_7 , 129 ) ) {
V_9 -> V_12 . V_14 -> V_292 |= 0x00020000 ;
V_9 -> V_12 . V_14 -> V_295 |= 0x20000000 ;
}
V_9 -> V_12 . V_14 -> V_296 = ( unsigned long ) & V_9 -> V_247 -> V_235 . V_266 . V_297 ;
V_9 -> V_12 . V_14 -> V_298 |= V_299 | V_300 | V_301 ;
if ( V_9 -> V_7 -> V_12 . V_118 ) {
V_197 = F_178 ( V_9 ) ;
if ( V_197 )
return V_197 ;
}
F_181 ( & V_9 -> V_12 . V_302 , V_303 , V_304 ) ;
V_9 -> V_12 . V_302 . V_305 = V_306 ;
F_54 ( V_9 ) ;
return V_197 ;
}
struct V_8 * F_182 ( struct V_7 * V_7 ,
unsigned int V_244 )
{
struct V_8 * V_9 ;
struct V_307 * V_307 ;
int V_197 = - V_34 ;
if ( ! F_47 ( V_7 ) && ! F_141 ( V_7 , V_244 ) )
goto V_89;
V_197 = - V_25 ;
V_9 = F_183 ( V_223 , V_145 ) ;
if ( ! V_9 )
goto V_89;
V_307 = (struct V_307 * ) F_104 ( V_145 ) ;
if ( ! V_307 )
goto V_308;
V_9 -> V_12 . V_14 = & V_307 -> V_14 ;
V_9 -> V_12 . V_14 -> V_309 = ( unsigned long ) & V_307 -> V_310 ;
V_9 -> V_12 . V_14 -> V_311 = V_244 ;
F_107 ( & V_9 -> V_12 . V_312 . V_97 ) ;
V_9 -> V_12 . V_312 . V_211 = & V_7 -> V_12 . V_211 ;
V_9 -> V_12 . V_312 . V_313 = & V_9 -> V_313 ;
V_9 -> V_12 . V_312 . V_272 = & V_9 -> V_12 . V_14 -> V_272 ;
F_184 ( & V_9 -> V_12 . V_258 ) ;
V_197 = F_185 ( V_9 , V_7 , V_244 ) ;
if ( V_197 )
goto V_314;
F_38 ( V_7 , 3 , L_31 , V_244 , V_9 ,
V_9 -> V_12 . V_14 ) ;
F_186 ( V_244 , V_9 , V_9 -> V_12 . V_14 ) ;
return V_9 ;
V_314:
F_100 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
V_308:
F_121 ( V_223 , V_9 ) ;
V_89:
return F_187 ( V_197 ) ;
}
int F_188 ( struct V_8 * V_9 )
{
return F_189 ( V_9 , 0 ) ;
}
void F_190 ( struct V_8 * V_9 )
{
F_168 ( V_315 , & V_9 -> V_12 . V_14 -> V_316 ) ;
F_55 ( V_9 ) ;
}
void F_191 ( struct V_8 * V_9 )
{
F_171 ( V_315 , & V_9 -> V_12 . V_14 -> V_316 ) ;
}
static void F_192 ( struct V_8 * V_9 )
{
F_168 ( V_317 , & V_9 -> V_12 . V_14 -> V_316 ) ;
F_55 ( V_9 ) ;
}
static void F_193 ( struct V_8 * V_9 )
{
F_171 ( V_317 , & V_9 -> V_12 . V_14 -> V_316 ) ;
}
void F_55 ( struct V_8 * V_9 )
{
F_168 ( V_318 , & V_9 -> V_12 . V_14 -> V_272 ) ;
while ( V_9 -> V_12 . V_14 -> V_319 & V_320 )
F_194 () ;
}
void F_195 ( int V_321 , struct V_8 * V_9 )
{
F_196 ( V_321 , V_9 ) ;
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
F_195 ( V_322 , V_9 ) ;
}
}
}
int F_198 ( struct V_8 * V_9 )
{
F_199 () ;
return 0 ;
}
static int F_200 ( struct V_8 * V_9 ,
struct V_323 * V_324 )
{
int V_36 = - V_34 ;
switch ( V_324 -> V_244 ) {
case V_325 :
V_36 = F_42 ( V_9 -> V_12 . V_14 -> V_276 ,
( T_6 V_110 * ) V_324 -> V_111 ) ;
break;
case V_326 :
V_36 = F_42 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_109 V_110 * ) V_324 -> V_111 ) ;
break;
case V_327 :
V_36 = F_42 ( F_156 ( V_9 ) ,
( V_109 V_110 * ) V_324 -> V_111 ) ;
break;
case V_328 :
V_36 = F_42 ( V_9 -> V_12 . V_14 -> V_275 ,
( V_109 V_110 * ) V_324 -> V_111 ) ;
break;
case V_329 :
V_36 = F_42 ( V_9 -> V_12 . V_245 ,
( V_109 V_110 * ) V_324 -> V_111 ) ;
break;
case V_330 :
V_36 = F_42 ( V_9 -> V_12 . V_331 ,
( V_109 V_110 * ) V_324 -> V_111 ) ;
break;
case V_332 :
V_36 = F_42 ( V_9 -> V_12 . V_333 ,
( V_109 V_110 * ) V_324 -> V_111 ) ;
break;
case V_334 :
V_36 = F_42 ( V_9 -> V_12 . V_14 -> V_279 ,
( V_109 V_110 * ) V_324 -> V_111 ) ;
break;
case V_335 :
V_36 = F_42 ( V_9 -> V_12 . V_14 -> V_278 ,
( V_109 V_110 * ) V_324 -> V_111 ) ;
break;
default:
break;
}
return V_36 ;
}
static int F_201 ( struct V_8 * V_9 ,
struct V_323 * V_324 )
{
int V_36 = - V_34 ;
V_228 V_5 ;
switch ( V_324 -> V_244 ) {
case V_325 :
V_36 = F_48 ( V_9 -> V_12 . V_14 -> V_276 ,
( T_6 V_110 * ) V_324 -> V_111 ) ;
break;
case V_326 :
V_36 = F_48 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_109 V_110 * ) V_324 -> V_111 ) ;
break;
case V_327 :
V_36 = F_48 ( V_5 , ( V_109 V_110 * ) V_324 -> V_111 ) ;
if ( ! V_36 )
F_155 ( V_9 , V_5 ) ;
break;
case V_328 :
V_36 = F_48 ( V_9 -> V_12 . V_14 -> V_275 ,
( V_109 V_110 * ) V_324 -> V_111 ) ;
break;
case V_329 :
V_36 = F_48 ( V_9 -> V_12 . V_245 ,
( V_109 V_110 * ) V_324 -> V_111 ) ;
if ( V_9 -> V_12 . V_245 == V_246 )
F_117 ( V_9 ) ;
break;
case V_330 :
V_36 = F_48 ( V_9 -> V_12 . V_331 ,
( V_109 V_110 * ) V_324 -> V_111 ) ;
break;
case V_332 :
V_36 = F_48 ( V_9 -> V_12 . V_333 ,
( V_109 V_110 * ) V_324 -> V_111 ) ;
break;
case V_334 :
V_36 = F_48 ( V_9 -> V_12 . V_14 -> V_279 ,
( V_109 V_110 * ) V_324 -> V_111 ) ;
break;
case V_335 :
V_36 = F_48 ( V_9 -> V_12 . V_14 -> V_278 ,
( V_109 V_110 * ) V_324 -> V_111 ) ;
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
int F_203 ( struct V_8 * V_9 , struct V_336 * V_266 )
{
memcpy ( & V_9 -> V_247 -> V_235 . V_266 . V_337 , & V_266 -> V_337 , sizeof( V_266 -> V_337 ) ) ;
return 0 ;
}
int F_204 ( struct V_8 * V_9 , struct V_336 * V_266 )
{
memcpy ( & V_266 -> V_337 , & V_9 -> V_247 -> V_235 . V_266 . V_337 , sizeof( V_266 -> V_337 ) ) ;
return 0 ;
}
int F_205 ( struct V_8 * V_9 ,
struct V_338 * V_339 )
{
memcpy ( & V_9 -> V_247 -> V_235 . V_266 . V_270 , & V_339 -> V_270 , sizeof( V_339 -> V_270 ) ) ;
memcpy ( & V_9 -> V_12 . V_14 -> V_277 , & V_339 -> V_340 , sizeof( V_339 -> V_340 ) ) ;
F_166 ( V_9 -> V_247 -> V_235 . V_266 . V_270 ) ;
return 0 ;
}
int F_206 ( struct V_8 * V_9 ,
struct V_338 * V_339 )
{
memcpy ( & V_339 -> V_270 , & V_9 -> V_247 -> V_235 . V_266 . V_270 , sizeof( V_339 -> V_270 ) ) ;
memcpy ( & V_339 -> V_340 , & V_9 -> V_12 . V_14 -> V_277 , sizeof( V_339 -> V_340 ) ) ;
return 0 ;
}
int F_207 ( struct V_8 * V_9 , struct V_341 * V_265 )
{
F_163 () ;
if ( F_164 ( V_265 -> V_263 ) )
return - V_34 ;
V_81 -> V_264 . V_265 . V_263 = V_265 -> V_263 ;
if ( V_70 )
F_208 ( V_81 -> V_264 . V_265 . V_342 , ( V_343 * ) V_265 -> V_268 ) ;
else
memcpy ( V_81 -> V_264 . V_265 . V_268 , & V_265 -> V_268 , sizeof( V_265 -> V_268 ) ) ;
return 0 ;
}
int F_209 ( struct V_8 * V_9 , struct V_341 * V_265 )
{
F_163 () ;
if ( V_70 )
F_210 ( ( V_343 * ) V_265 -> V_268 , V_81 -> V_264 . V_265 . V_342 ) ;
else
memcpy ( V_265 -> V_268 , V_81 -> V_264 . V_265 . V_268 , sizeof( V_265 -> V_268 ) ) ;
V_265 -> V_263 = V_81 -> V_264 . V_265 . V_263 ;
return 0 ;
}
static int F_211 ( struct V_8 * V_9 , T_7 V_344 )
{
int V_197 = 0 ;
if ( ! F_212 ( V_9 ) )
V_197 = - V_99 ;
else {
V_9 -> V_247 -> V_345 = V_344 . V_274 ;
V_9 -> V_247 -> V_346 = V_344 . V_111 ;
}
return V_197 ;
}
int F_213 ( struct V_8 * V_9 ,
struct V_347 * V_348 )
{
return - V_34 ;
}
int F_214 ( struct V_8 * V_9 ,
struct V_349 * V_350 )
{
int V_197 = 0 ;
V_9 -> V_351 = 0 ;
F_215 ( V_9 ) ;
if ( V_350 -> V_352 & ~ V_353 )
return - V_34 ;
if ( V_350 -> V_352 & V_354 ) {
V_9 -> V_351 = V_350 -> V_352 ;
F_168 ( V_355 , & V_9 -> V_12 . V_14 -> V_272 ) ;
if ( V_350 -> V_352 & V_356 )
V_197 = F_216 ( V_9 , V_350 ) ;
} else {
F_171 ( V_355 , & V_9 -> V_12 . V_14 -> V_272 ) ;
V_9 -> V_12 . V_357 . V_358 = 0 ;
}
if ( V_197 ) {
V_9 -> V_351 = 0 ;
F_215 ( V_9 ) ;
F_171 ( V_355 , & V_9 -> V_12 . V_14 -> V_272 ) ;
}
return V_197 ;
}
int F_217 ( struct V_8 * V_9 ,
struct V_359 * V_360 )
{
return F_212 ( V_9 ) ? V_361 :
V_362 ;
}
int F_218 ( struct V_8 * V_9 ,
struct V_359 * V_360 )
{
int V_197 = 0 ;
V_9 -> V_7 -> V_12 . V_363 = 1 ;
switch ( V_360 -> V_360 ) {
case V_361 :
F_176 ( V_9 ) ;
break;
case V_362 :
F_219 ( V_9 ) ;
break;
case V_364 :
case V_365 :
default:
V_197 = - V_113 ;
}
return V_197 ;
}
static bool F_220 ( struct V_8 * V_9 )
{
return F_39 ( & V_9 -> V_12 . V_14 -> V_272 ) & V_366 ;
}
static int F_221 ( struct V_8 * V_9 )
{
V_367:
F_193 ( V_9 ) ;
if ( ! V_9 -> V_368 )
return 0 ;
if ( F_222 ( V_322 , V_9 ) ) {
int V_197 ;
V_197 = F_223 ( V_9 -> V_12 . V_77 ,
F_197 ( V_9 ) ,
V_206 * 2 ) ;
if ( V_197 )
return V_197 ;
goto V_367;
}
if ( F_222 ( V_369 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_370 = 0xffff ;
goto V_367;
}
if ( F_222 ( V_371 , V_9 ) ) {
if ( ! F_220 ( V_9 ) ) {
F_224 ( V_9 -> V_222 , 1 ) ;
F_168 ( V_366 ,
& V_9 -> V_12 . V_14 -> V_272 ) ;
}
goto V_367;
}
if ( F_222 ( V_372 , V_9 ) ) {
if ( F_220 ( V_9 ) ) {
F_224 ( V_9 -> V_222 , 0 ) ;
F_171 ( V_366 ,
& V_9 -> V_12 . V_14 -> V_272 ) ;
}
goto V_367;
}
F_225 ( V_373 , & V_9 -> V_368 ) ;
return 0 ;
}
void F_59 ( struct V_7 * V_7 , V_109 V_374 )
{
struct V_8 * V_9 ;
int V_10 ;
F_32 ( & V_7 -> V_97 ) ;
F_152 () ;
V_7 -> V_12 . V_13 = V_374 - F_226 () ;
F_137 ( V_7 ) ;
F_7 (i, vcpu, kvm)
V_9 -> V_12 . V_14 -> V_13 = V_7 -> V_12 . V_13 ;
F_140 ( V_7 ) ;
F_153 () ;
F_36 ( & V_7 -> V_97 ) ;
}
long F_227 ( struct V_8 * V_9 , T_8 V_375 , int V_376 )
{
return F_228 ( V_9 -> V_12 . V_77 , V_375 ,
V_376 ? V_377 : 0 ) ;
}
static void F_229 ( struct V_8 * V_9 , bool V_378 ,
unsigned long V_379 )
{
struct V_173 V_380 ;
struct V_381 V_382 ;
if ( V_378 ) {
V_382 . V_383 . V_35 . V_384 = V_379 ;
V_382 . type = V_385 ;
F_144 ( F_230 ( V_9 , & V_382 ) ) ;
} else {
V_380 . type = V_386 ;
V_380 . V_387 = V_379 ;
F_144 ( F_90 ( V_9 -> V_7 , & V_380 ) ) ;
}
}
void F_231 ( struct V_8 * V_9 ,
struct V_388 * V_389 )
{
F_232 ( V_9 , V_389 -> V_12 . V_245 ) ;
F_229 ( V_9 , true , V_389 -> V_12 . V_245 ) ;
}
void F_233 ( struct V_8 * V_9 ,
struct V_388 * V_389 )
{
F_234 ( V_9 , V_389 -> V_12 . V_245 ) ;
F_229 ( V_9 , false , V_389 -> V_12 . V_245 ) ;
}
void F_235 ( struct V_8 * V_9 ,
struct V_388 * V_389 )
{
}
bool F_236 ( struct V_8 * V_9 )
{
return true ;
}
static int F_237 ( struct V_8 * V_9 )
{
T_9 V_162 ;
struct V_390 V_12 ;
int V_197 ;
if ( V_9 -> V_12 . V_245 == V_246 )
return 0 ;
if ( ( V_9 -> V_12 . V_14 -> V_273 . V_274 & V_9 -> V_12 . V_333 ) !=
V_9 -> V_12 . V_331 )
return 0 ;
if ( F_238 ( V_9 ) )
return 0 ;
if ( F_189 ( V_9 , 0 ) )
return 0 ;
if ( ! ( V_9 -> V_12 . V_14 -> V_277 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_9 -> V_12 . V_77 -> V_219 )
return 0 ;
V_162 = F_81 ( V_9 -> V_7 , F_239 ( V_81 -> V_264 . V_391 ) ) ;
V_162 += V_81 -> V_264 . V_391 & ~ V_392 ;
if ( F_240 ( V_9 , V_9 -> V_12 . V_245 , & V_12 . V_245 , 8 ) )
return 0 ;
V_197 = F_241 ( V_9 , V_81 -> V_264 . V_391 , V_162 , & V_12 ) ;
return V_197 ;
}
static int F_242 ( struct V_8 * V_9 )
{
int V_197 , V_272 ;
F_243 ( V_9 ) ;
V_9 -> V_12 . V_14 -> V_393 = V_9 -> V_247 -> V_235 . V_266 . V_337 [ 14 ] ;
V_9 -> V_12 . V_14 -> V_394 = V_9 -> V_247 -> V_235 . V_266 . V_337 [ 15 ] ;
if ( F_244 () )
F_245 () ;
if ( F_246 ( V_395 ) )
F_247 () ;
if ( ! F_47 ( V_9 -> V_7 ) ) {
V_197 = F_248 ( V_9 ) ;
if ( V_197 )
return V_197 ;
}
V_197 = F_221 ( V_9 ) ;
if ( V_197 )
return V_197 ;
if ( F_249 ( V_9 ) ) {
F_250 ( V_9 ) ;
F_251 ( V_9 ) ;
}
V_9 -> V_12 . V_14 -> V_396 = 0 ;
V_272 = F_39 ( & V_9 -> V_12 . V_14 -> V_272 ) ;
F_114 ( V_9 , 6 , L_33 , V_272 ) ;
F_252 ( V_9 , V_272 ) ;
return 0 ;
}
static int F_253 ( struct V_8 * V_9 )
{
struct V_397 V_398 = {
. V_399 = V_400 ,
} ;
T_2 V_401 , V_402 ;
int V_197 ;
F_114 ( V_9 , 3 , L_2 , L_34 ) ;
F_254 ( V_9 ) ;
V_197 = F_255 ( V_9 , & V_401 , 1 ) ;
V_402 = F_256 ( V_401 ) ;
if ( V_197 < 0 ) {
return V_197 ;
} else if ( V_197 ) {
V_398 = V_9 -> V_12 . V_403 ;
V_402 = 4 ;
}
V_398 . V_94 = V_402 | V_404 ;
F_257 ( V_9 , V_402 ) ;
return F_258 ( V_9 , & V_398 ) ;
}
static int F_259 ( struct V_8 * V_9 , int V_405 )
{
F_114 ( V_9 , 6 , L_35 ,
V_9 -> V_12 . V_14 -> V_396 ) ;
F_260 ( V_9 , V_9 -> V_12 . V_14 -> V_396 ) ;
if ( F_249 ( V_9 ) )
F_261 ( V_9 ) ;
V_9 -> V_247 -> V_235 . V_266 . V_337 [ 14 ] = V_9 -> V_12 . V_14 -> V_393 ;
V_9 -> V_247 -> V_235 . V_266 . V_337 [ 15 ] = V_9 -> V_12 . V_14 -> V_394 ;
if ( V_9 -> V_12 . V_14 -> V_396 > 0 ) {
int V_197 = F_262 ( V_9 ) ;
if ( V_197 != - V_406 )
return V_197 ;
V_9 -> V_247 -> V_405 = V_407 ;
V_9 -> V_247 -> V_408 . V_396 = V_9 -> V_12 . V_14 -> V_396 ;
V_9 -> V_247 -> V_408 . V_409 = V_9 -> V_12 . V_14 -> V_409 ;
V_9 -> V_247 -> V_408 . V_410 = V_9 -> V_12 . V_14 -> V_410 ;
return - V_411 ;
} else if ( V_405 != - V_112 ) {
V_9 -> V_412 . V_413 ++ ;
return 0 ;
} else if ( F_47 ( V_9 -> V_7 ) ) {
V_9 -> V_247 -> V_405 = V_414 ;
V_9 -> V_247 -> V_415 . V_416 =
V_81 -> V_264 . V_391 ;
V_9 -> V_247 -> V_415 . V_417 = 0x10 ;
return - V_411 ;
} else if ( V_81 -> V_264 . V_418 ) {
F_263 ( V_9 ) ;
V_81 -> V_264 . V_418 = 0 ;
if ( F_237 ( V_9 ) )
return 0 ;
return F_227 ( V_9 , V_81 -> V_264 . V_391 , 1 ) ;
}
return F_253 ( V_9 ) ;
}
static int F_264 ( struct V_8 * V_9 )
{
int V_197 , V_405 ;
V_9 -> V_419 = F_44 ( & V_9 -> V_7 -> V_120 ) ;
do {
V_197 = F_242 ( V_9 ) ;
if ( V_197 )
break;
F_46 ( & V_9 -> V_7 -> V_120 , V_9 -> V_419 ) ;
F_265 () ;
F_266 () ;
F_150 ( V_9 ) ;
F_267 () ;
V_405 = F_268 ( V_9 -> V_12 . V_14 ,
V_9 -> V_247 -> V_235 . V_266 . V_337 ) ;
F_265 () ;
F_149 ( V_9 ) ;
F_269 () ;
F_267 () ;
V_9 -> V_419 = F_44 ( & V_9 -> V_7 -> V_120 ) ;
V_197 = F_259 ( V_9 , V_405 ) ;
} while ( ! F_270 ( V_81 ) && ! F_271 ( V_9 ) && ! V_197 );
F_46 ( & V_9 -> V_7 -> V_120 , V_9 -> V_419 ) ;
return V_197 ;
}
static void F_272 ( struct V_8 * V_9 , struct V_420 * V_420 )
{
V_9 -> V_12 . V_14 -> V_273 . V_274 = V_420 -> V_345 ;
V_9 -> V_12 . V_14 -> V_273 . V_111 = V_420 -> V_346 ;
if ( V_420 -> V_421 & V_249 )
F_174 ( V_9 , V_420 -> V_235 . V_266 . V_422 ) ;
if ( V_420 -> V_421 & V_252 ) {
memcpy ( & V_9 -> V_12 . V_14 -> V_277 , & V_420 -> V_235 . V_266 . V_340 , 128 ) ;
F_196 ( V_369 , V_9 ) ;
}
if ( V_420 -> V_421 & V_253 ) {
F_155 ( V_9 , V_420 -> V_235 . V_266 . V_259 ) ;
V_9 -> V_12 . V_14 -> V_275 = V_420 -> V_235 . V_266 . V_275 ;
V_9 -> V_12 . V_14 -> V_276 = V_420 -> V_235 . V_266 . V_276 ;
V_9 -> V_12 . V_14 -> V_279 = V_420 -> V_235 . V_266 . V_279 ;
V_9 -> V_12 . V_14 -> V_278 = V_420 -> V_235 . V_266 . V_278 ;
}
if ( V_420 -> V_421 & V_254 ) {
V_9 -> V_12 . V_245 = V_420 -> V_235 . V_266 . V_423 ;
V_9 -> V_12 . V_333 = V_420 -> V_235 . V_266 . V_424 ;
V_9 -> V_12 . V_331 = V_420 -> V_235 . V_266 . V_425 ;
if ( V_9 -> V_12 . V_245 == V_246 )
F_117 ( V_9 ) ;
}
V_420 -> V_421 = 0 ;
}
static void F_273 ( struct V_8 * V_9 , struct V_420 * V_420 )
{
V_420 -> V_345 = V_9 -> V_12 . V_14 -> V_273 . V_274 ;
V_420 -> V_346 = V_9 -> V_12 . V_14 -> V_273 . V_111 ;
V_420 -> V_235 . V_266 . V_422 = F_197 ( V_9 ) ;
memcpy ( & V_420 -> V_235 . V_266 . V_340 , & V_9 -> V_12 . V_14 -> V_277 , 128 ) ;
V_420 -> V_235 . V_266 . V_259 = F_156 ( V_9 ) ;
V_420 -> V_235 . V_266 . V_275 = V_9 -> V_12 . V_14 -> V_275 ;
V_420 -> V_235 . V_266 . V_276 = V_9 -> V_12 . V_14 -> V_276 ;
V_420 -> V_235 . V_266 . V_279 = V_9 -> V_12 . V_14 -> V_279 ;
V_420 -> V_235 . V_266 . V_278 = V_9 -> V_12 . V_14 -> V_278 ;
V_420 -> V_235 . V_266 . V_423 = V_9 -> V_12 . V_245 ;
V_420 -> V_235 . V_266 . V_424 = V_9 -> V_12 . V_333 ;
V_420 -> V_235 . V_266 . V_425 = V_9 -> V_12 . V_331 ;
}
int F_274 ( struct V_8 * V_9 , struct V_420 * V_420 )
{
int V_197 ;
T_10 V_426 ;
if ( F_271 ( V_9 ) ) {
F_275 ( V_9 ) ;
return 0 ;
}
if ( V_9 -> V_427 )
F_276 ( V_428 , & V_9 -> V_429 , & V_426 ) ;
if ( ! F_175 ( V_9 -> V_7 ) ) {
F_219 ( V_9 ) ;
} else if ( F_212 ( V_9 ) ) {
F_277 ( L_36 ,
V_9 -> V_222 ) ;
return - V_34 ;
}
F_272 ( V_9 , V_420 ) ;
F_151 ( V_9 ) ;
F_278 () ;
V_197 = F_264 ( V_9 ) ;
if ( F_270 ( V_81 ) && ! V_197 ) {
V_420 -> V_405 = V_430 ;
V_197 = - V_431 ;
}
if ( F_271 ( V_9 ) && ! V_197 ) {
F_275 ( V_9 ) ;
V_197 = 0 ;
}
if ( V_197 == - V_411 ) {
V_197 = 0 ;
}
F_154 ( V_9 ) ;
F_273 ( V_9 , V_420 ) ;
if ( V_9 -> V_427 )
F_276 ( V_428 , & V_426 , NULL ) ;
V_9 -> V_412 . V_432 ++ ;
return V_197 ;
}
int F_279 ( struct V_8 * V_9 , unsigned long V_375 )
{
unsigned char V_433 = 1 ;
V_343 V_268 [ V_434 ] ;
unsigned int V_435 ;
V_109 V_436 , V_259 ;
int V_197 ;
V_435 = F_197 ( V_9 ) ;
if ( V_375 == V_437 ) {
if ( F_280 ( V_9 , 163 , & V_433 , 1 ) )
return - V_112 ;
V_375 = 0 ;
} else if ( V_375 == V_438 ) {
if ( F_281 ( V_9 , 163 , & V_433 , 1 ) )
return - V_112 ;
V_375 = V_435 ;
} else
V_375 -= V_439 ;
if ( V_70 ) {
F_210 ( V_268 , ( V_440 * ) V_9 -> V_247 -> V_235 . V_266 . V_267 ) ;
V_197 = F_280 ( V_9 , V_375 + V_439 ,
V_268 , 128 ) ;
} else {
V_197 = F_280 ( V_9 , V_375 + V_439 ,
V_9 -> V_247 -> V_235 . V_266 . V_268 , 128 ) ;
}
V_197 |= F_280 ( V_9 , V_375 + V_441 ,
V_9 -> V_247 -> V_235 . V_266 . V_337 , 128 ) ;
V_197 |= F_280 ( V_9 , V_375 + V_442 ,
& V_9 -> V_12 . V_14 -> V_273 , 16 ) ;
V_197 |= F_280 ( V_9 , V_375 + V_443 ,
& V_435 , 4 ) ;
V_197 |= F_280 ( V_9 , V_375 + V_444 ,
& V_9 -> V_247 -> V_235 . V_266 . V_263 , 4 ) ;
V_197 |= F_280 ( V_9 , V_375 + V_445 ,
& V_9 -> V_12 . V_14 -> V_276 , 4 ) ;
V_259 = F_156 ( V_9 ) ;
V_197 |= F_280 ( V_9 , V_375 + V_446 ,
& V_259 , 8 ) ;
V_436 = V_9 -> V_12 . V_14 -> V_275 >> 8 ;
V_197 |= F_280 ( V_9 , V_375 + V_447 ,
& V_436 , 8 ) ;
V_197 |= F_280 ( V_9 , V_375 + V_448 ,
& V_9 -> V_247 -> V_235 . V_266 . V_270 , 64 ) ;
V_197 |= F_280 ( V_9 , V_375 + V_449 ,
& V_9 -> V_12 . V_14 -> V_277 , 128 ) ;
return V_197 ? - V_112 : 0 ;
}
int F_282 ( struct V_8 * V_9 , unsigned long V_111 )
{
F_163 () ;
V_9 -> V_247 -> V_235 . V_266 . V_263 = V_81 -> V_264 . V_265 . V_263 ;
F_165 ( V_9 -> V_247 -> V_235 . V_266 . V_270 ) ;
return F_279 ( V_9 , V_111 ) ;
}
int F_283 ( struct V_8 * V_9 ,
unsigned long V_375 )
{
if ( ! ( V_375 & ~ 0x3ff ) )
return 0 ;
return F_280 ( V_9 , V_375 & ~ 0x3ff ,
( void * ) & V_9 -> V_247 -> V_235 . V_266 . V_267 , 512 ) ;
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
F_222 ( V_371 , V_9 ) ;
F_195 ( V_372 , V_9 ) ;
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
F_222 ( V_372 , V_9 ) ;
F_195 ( V_371 , V_9 ) ;
}
void F_219 ( struct V_8 * V_9 )
{
int V_10 , V_98 , V_450 = 0 ;
if ( ! F_212 ( V_9 ) )
return;
F_288 ( V_9 -> V_222 , 1 ) ;
F_105 ( & V_9 -> V_7 -> V_12 . V_221 ) ;
V_98 = F_39 ( & V_9 -> V_7 -> V_98 ) ;
for ( V_10 = 0 ; V_10 < V_98 ; V_10 ++ ) {
if ( ! F_212 ( V_9 -> V_7 -> V_224 [ V_10 ] ) )
V_450 ++ ;
}
if ( V_450 == 0 ) {
F_287 ( V_9 ) ;
} else if ( V_450 == 1 ) {
F_286 ( V_9 -> V_7 ) ;
}
F_171 ( V_288 , & V_9 -> V_12 . V_14 -> V_272 ) ;
F_196 ( V_369 , V_9 ) ;
F_106 ( & V_9 -> V_7 -> V_12 . V_221 ) ;
return;
}
void F_176 ( struct V_8 * V_9 )
{
int V_10 , V_98 , V_450 = 0 ;
struct V_8 * V_451 = NULL ;
if ( F_212 ( V_9 ) )
return;
F_288 ( V_9 -> V_222 , 0 ) ;
F_105 ( & V_9 -> V_7 -> V_12 . V_221 ) ;
V_98 = F_39 ( & V_9 -> V_7 -> V_98 ) ;
F_289 ( V_9 ) ;
F_168 ( V_288 , & V_9 -> V_12 . V_14 -> V_272 ) ;
F_285 ( V_9 ) ;
for ( V_10 = 0 ; V_10 < V_98 ; V_10 ++ ) {
if ( ! F_212 ( V_9 -> V_7 -> V_224 [ V_10 ] ) ) {
V_450 ++ ;
V_451 = V_9 -> V_7 -> V_224 [ V_10 ] ;
}
}
if ( V_450 == 1 ) {
F_287 ( V_451 ) ;
}
F_106 ( & V_9 -> V_7 -> V_12 . V_221 ) ;
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
if ( ! V_9 -> V_7 -> V_12 . V_220 ) {
V_9 -> V_7 -> V_12 . V_220 = 1 ;
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
struct V_452 * V_453 )
{
void V_110 * V_454 = ( void V_110 * ) V_453 -> V_455 ;
void * V_456 = NULL ;
int V_36 , V_419 ;
const V_109 V_457 = V_458
| V_459 ;
if ( V_453 -> V_94 & ~ V_457 )
return - V_34 ;
if ( V_453 -> V_460 > V_58 )
return - V_123 ;
if ( ! ( V_453 -> V_94 & V_459 ) ) {
V_456 = F_80 ( V_453 -> V_460 ) ;
if ( ! V_456 )
return - V_25 ;
}
V_419 = F_44 ( & V_9 -> V_7 -> V_120 ) ;
switch ( V_453 -> V_461 ) {
case V_462 :
if ( V_453 -> V_94 & V_459 ) {
V_36 = F_293 ( V_9 , V_453 -> V_463 , V_453 -> V_464 ,
V_453 -> V_460 , V_465 ) ;
break;
}
V_36 = F_294 ( V_9 , V_453 -> V_463 , V_453 -> V_464 , V_456 , V_453 -> V_460 ) ;
if ( V_36 == 0 ) {
if ( F_62 ( V_454 , V_456 , V_453 -> V_460 ) )
V_36 = - V_112 ;
}
break;
case V_466 :
if ( V_453 -> V_94 & V_459 ) {
V_36 = F_293 ( V_9 , V_453 -> V_463 , V_453 -> V_464 ,
V_453 -> V_460 , V_467 ) ;
break;
}
if ( F_57 ( V_456 , V_454 , V_453 -> V_460 ) ) {
V_36 = - V_112 ;
break;
}
V_36 = F_295 ( V_9 , V_453 -> V_463 , V_453 -> V_464 , V_456 , V_453 -> V_460 ) ;
break;
default:
V_36 = - V_34 ;
}
F_46 ( & V_9 -> V_7 -> V_120 , V_419 ) ;
if ( V_36 > 0 && ( V_453 -> V_94 & V_458 ) != 0 )
F_258 ( V_9 , & V_9 -> V_12 . V_403 ) ;
F_296 ( V_456 ) ;
return V_36 ;
}
long F_297 ( struct V_29 * V_30 ,
unsigned int V_31 , unsigned long V_32 )
{
struct V_8 * V_9 = V_30 -> V_170 ;
void V_110 * V_171 = ( void V_110 * ) V_32 ;
int V_114 ;
long V_36 ;
switch ( V_31 ) {
case V_468 : {
struct V_381 V_469 ;
V_36 = - V_112 ;
if ( F_57 ( & V_469 , V_171 , sizeof( V_469 ) ) )
break;
V_36 = F_230 ( V_9 , & V_469 ) ;
break;
}
case V_172 : {
struct V_173 V_174 ;
struct V_381 V_469 ;
V_36 = - V_112 ;
if ( F_57 ( & V_174 , V_171 , sizeof( V_174 ) ) )
break;
if ( F_298 ( & V_174 , & V_469 ) )
return - V_34 ;
V_36 = F_230 ( V_9 , & V_469 ) ;
break;
}
case V_470 :
V_114 = F_44 ( & V_9 -> V_7 -> V_120 ) ;
V_36 = F_282 ( V_9 , V_32 ) ;
F_46 ( & V_9 -> V_7 -> V_120 , V_114 ) ;
break;
case V_471 : {
T_7 V_344 ;
V_36 = - V_112 ;
if ( F_57 ( & V_344 , V_171 , sizeof( V_344 ) ) )
break;
V_36 = F_211 ( V_9 , V_344 ) ;
break;
}
case V_472 :
V_36 = F_202 ( V_9 ) ;
break;
case V_473 :
case V_474 : {
struct V_323 V_324 ;
V_36 = - V_112 ;
if ( F_57 ( & V_324 , V_171 , sizeof( V_324 ) ) )
break;
if ( V_31 == V_473 )
V_36 = F_201 ( V_9 , & V_324 ) ;
else
V_36 = F_200 ( V_9 , & V_324 ) ;
break;
}
#ifdef F_23
case V_475 : {
struct V_476 V_477 ;
if ( F_57 ( & V_477 , V_171 , sizeof( V_477 ) ) ) {
V_36 = - V_112 ;
break;
}
if ( ! F_47 ( V_9 -> V_7 ) ) {
V_36 = - V_34 ;
break;
}
V_36 = F_299 ( V_9 -> V_12 . V_77 , V_477 . V_478 ,
V_477 . V_479 , V_477 . V_480 ) ;
break;
}
case V_481 : {
struct V_476 V_477 ;
if ( F_57 ( & V_477 , V_171 , sizeof( V_477 ) ) ) {
V_36 = - V_112 ;
break;
}
if ( ! F_47 ( V_9 -> V_7 ) ) {
V_36 = - V_34 ;
break;
}
V_36 = F_300 ( V_9 -> V_12 . V_77 , V_477 . V_479 ,
V_477 . V_480 ) ;
break;
}
#endif
case V_482 : {
V_36 = F_228 ( V_9 -> V_12 . V_77 , V_32 , 0 ) ;
break;
}
case V_175 :
{
struct V_92 V_93 ;
V_36 = - V_112 ;
if ( F_57 ( & V_93 , V_171 , sizeof( V_93 ) ) )
break;
V_36 = F_290 ( V_9 , & V_93 ) ;
break;
}
case V_483 : {
struct V_452 V_484 ;
if ( F_57 ( & V_484 , V_171 , sizeof( V_484 ) ) == 0 )
V_36 = F_292 ( V_9 , & V_484 ) ;
else
V_36 = - V_112 ;
break;
}
case V_485 : {
struct V_486 V_487 ;
V_36 = - V_112 ;
if ( F_57 ( & V_487 , V_171 , sizeof( V_487 ) ) )
break;
if ( V_487 . V_488 > V_489 ||
V_487 . V_488 == 0 ||
V_487 . V_488 % sizeof( struct V_381 ) > 0 ) {
V_36 = - V_34 ;
break;
}
V_36 = F_301 ( V_9 ,
( void V_110 * ) V_487 . V_455 ,
V_487 . V_488 ) ;
break;
}
case V_490 : {
struct V_486 V_487 ;
V_36 = - V_112 ;
if ( F_57 ( & V_487 , V_171 , sizeof( V_487 ) ) )
break;
if ( V_487 . V_488 == 0 ) {
V_36 = - V_34 ;
break;
}
V_36 = F_302 ( V_9 ,
( V_491 V_110 * ) V_487 . V_455 ,
V_487 . V_488 ) ;
break;
}
default:
V_36 = - V_184 ;
}
return V_36 ;
}
int F_303 ( struct V_8 * V_9 , struct V_492 * V_493 )
{
#ifdef F_23
if ( ( V_493 -> V_494 == V_495 )
&& ( F_47 ( V_9 -> V_7 ) ) ) {
V_493 -> V_496 = F_304 ( V_9 -> V_12 . V_14 ) ;
F_305 ( V_493 -> V_496 ) ;
return 0 ;
}
#endif
return V_497 ;
}
int F_306 ( struct V_7 * V_7 , struct V_72 * V_88 ,
unsigned long V_79 )
{
return 0 ;
}
int F_307 ( struct V_7 * V_7 ,
struct V_72 * V_73 ,
const struct V_498 * V_499 ,
enum V_500 V_501 )
{
if ( V_499 -> V_502 & 0xffffful )
return - V_34 ;
if ( V_499 -> V_503 & 0xffffful )
return - V_34 ;
if ( V_499 -> V_504 + V_499 -> V_503 > V_7 -> V_12 . V_108 )
return - V_34 ;
return 0 ;
}
void F_308 ( struct V_7 * V_7 ,
const struct V_498 * V_499 ,
const struct V_72 * V_505 ,
const struct V_72 * V_124 ,
enum V_500 V_501 )
{
int V_197 ;
if ( V_505 -> V_502 == V_499 -> V_502 &&
V_505 -> V_78 * V_206 == V_499 -> V_504 &&
V_505 -> V_79 * V_206 == V_499 -> V_503 )
return;
V_197 = F_299 ( V_7 -> V_12 . V_77 , V_499 -> V_502 ,
V_499 -> V_504 , V_499 -> V_503 ) ;
if ( V_197 )
F_309 ( L_38 ) ;
return;
}
static inline unsigned long F_310 ( int V_10 )
{
unsigned int V_506 = ( V_61 . V_507 << V_10 * 2 ) >> 30 ;
return 0x0000ffffffffffffUL >> ( V_506 << 4 ) ;
}
void F_311 ( struct V_8 * V_9 )
{
V_9 -> V_508 = false ;
}
static int T_11 F_312 ( void )
{
int V_10 ;
if ( ! V_61 . V_509 ) {
F_313 ( L_39 ) ;
return - V_510 ;
}
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ )
V_1 [ V_10 ] |=
V_152 . V_153 [ V_10 ] & F_310 ( V_10 ) ;
return F_314 ( NULL , sizeof( struct V_8 ) , 0 , V_511 ) ;
}
static void T_12 F_315 ( void )
{
F_316 () ;
}
