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
V_34 = V_59 . V_60 ? V_61
: V_62 ;
break;
case V_63 :
V_34 = V_64 ;
break;
case V_65 :
V_34 = V_66 ;
break;
case V_67 :
V_34 = V_68 ;
break;
case V_69 :
V_34 = F_24 ( 64 ) ;
break;
default:
V_34 = 0 ;
}
return V_34 ;
}
static void F_25 ( struct V_7 * V_7 ,
struct V_70 * V_71 )
{
T_1 V_72 , V_73 ;
unsigned long V_74 ;
struct V_75 * V_75 = V_7 -> V_12 . V_75 ;
F_26 ( & V_75 -> V_76 -> V_77 ) ;
V_73 = V_71 -> V_78 + V_71 -> V_79 ;
for ( V_72 = V_71 -> V_78 ; V_72 <= V_73 ; V_72 ++ ) {
V_74 = F_27 ( V_71 , V_72 ) ;
if ( F_28 ( V_74 , V_75 ) )
F_29 ( V_7 , V_72 ) ;
}
F_30 ( & V_75 -> V_76 -> V_77 ) ;
}
int F_31 ( struct V_7 * V_7 ,
struct V_80 * log )
{
int V_34 ;
unsigned long V_81 ;
struct V_82 * V_83 ;
struct V_70 * V_71 ;
int V_84 = 0 ;
F_32 ( & V_7 -> V_85 ) ;
V_34 = - V_32 ;
if ( log -> V_86 >= V_64 )
goto V_87;
V_83 = V_82 ( V_7 ) ;
V_71 = F_33 ( V_83 , log -> V_86 ) ;
V_34 = - V_88 ;
if ( ! V_71 -> V_89 )
goto V_87;
F_25 ( V_7 , V_71 ) ;
V_34 = F_34 ( V_7 , log , & V_84 ) ;
if ( V_34 )
goto V_87;
if ( V_84 ) {
V_81 = F_35 ( V_71 ) ;
memset ( V_71 -> V_89 , 0 , V_81 ) ;
}
V_34 = 0 ;
V_87:
F_36 ( & V_7 -> V_85 ) ;
return V_34 ;
}
static int F_37 ( struct V_7 * V_7 , struct V_90 * V_91 )
{
int V_34 ;
if ( V_91 -> V_92 )
return - V_32 ;
switch ( V_91 -> V_91 ) {
case V_47 :
F_38 ( V_7 , 3 , L_2 , L_3 ) ;
V_7 -> V_12 . V_93 = 1 ;
V_34 = 0 ;
break;
case V_51 :
F_38 ( V_7 , 3 , L_2 , L_4 ) ;
V_7 -> V_12 . V_94 = 1 ;
V_34 = 0 ;
break;
case V_67 :
F_32 ( & V_7 -> V_95 ) ;
if ( F_39 ( & V_7 -> V_96 ) ) {
V_34 = - V_97 ;
} else if ( V_68 ) {
F_40 ( V_7 -> V_12 . V_98 . V_99 -> V_100 , 129 ) ;
F_40 ( V_7 -> V_12 . V_98 . V_99 -> V_101 , 129 ) ;
V_34 = 0 ;
} else
V_34 = - V_32 ;
F_36 ( & V_7 -> V_95 ) ;
F_38 ( V_7 , 3 , L_5 ,
V_34 ? L_6 : L_7 ) ;
break;
case V_69 :
V_34 = - V_32 ;
F_32 ( & V_7 -> V_95 ) ;
if ( F_39 ( & V_7 -> V_96 ) ) {
V_34 = - V_97 ;
} else if ( F_24 ( 64 ) ) {
F_40 ( V_7 -> V_12 . V_98 . V_99 -> V_100 , 64 ) ;
F_40 ( V_7 -> V_12 . V_98 . V_99 -> V_101 , 64 ) ;
V_34 = 0 ;
}
F_36 ( & V_7 -> V_95 ) ;
F_38 ( V_7 , 3 , L_8 ,
V_34 ? L_6 : L_7 ) ;
break;
case V_52 :
F_38 ( V_7 , 3 , L_2 , L_9 ) ;
V_7 -> V_12 . V_102 = 1 ;
V_34 = 0 ;
break;
default:
V_34 = - V_32 ;
break;
}
return V_34 ;
}
static int F_41 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
int V_105 ;
switch ( V_104 -> V_104 ) {
case V_106 :
V_105 = 0 ;
F_38 ( V_7 , 3 , L_10 ,
V_7 -> V_12 . V_107 ) ;
if ( F_42 ( V_7 -> V_12 . V_107 , ( V_108 V_109 * ) V_104 -> V_110 ) )
V_105 = - V_111 ;
break;
default:
V_105 = - V_112 ;
break;
}
return V_105 ;
}
static int F_43 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
int V_105 ;
unsigned int V_113 ;
switch ( V_104 -> V_104 ) {
case V_114 :
V_105 = - V_32 ;
if ( ! V_115 || ! V_116 )
break;
V_105 = - V_97 ;
F_38 ( V_7 , 3 , L_2 , L_11 ) ;
F_32 ( & V_7 -> V_95 ) ;
if ( F_39 ( & V_7 -> V_96 ) == 0 ) {
V_7 -> V_12 . V_117 = 1 ;
V_105 = 0 ;
}
F_36 ( & V_7 -> V_95 ) ;
break;
case V_118 :
V_105 = - V_32 ;
if ( ! V_7 -> V_12 . V_117 )
break;
F_38 ( V_7 , 3 , L_2 , L_12 ) ;
F_32 ( & V_7 -> V_95 ) ;
V_113 = F_44 ( & V_7 -> V_119 ) ;
F_45 ( V_7 -> V_12 . V_75 -> V_76 ) ;
F_46 ( & V_7 -> V_119 , V_113 ) ;
F_36 ( & V_7 -> V_95 ) ;
V_105 = 0 ;
break;
case V_106 : {
unsigned long V_120 ;
if ( F_47 ( V_7 ) )
return - V_32 ;
if ( F_48 ( V_120 , ( V_108 V_109 * ) V_104 -> V_110 ) )
return - V_111 ;
if ( V_7 -> V_12 . V_107 != V_121 &&
V_120 > V_7 -> V_12 . V_107 )
return - V_122 ;
if ( ! V_120 )
return - V_32 ;
if ( V_120 != V_121 )
V_120 -= 1 ;
V_105 = - V_97 ;
F_32 ( & V_7 -> V_95 ) ;
if ( F_39 ( & V_7 -> V_96 ) == 0 ) {
struct V_75 * V_123 = F_49 ( V_124 -> V_76 , V_120 ) ;
if ( ! V_123 ) {
V_105 = - V_23 ;
} else {
F_50 ( V_7 -> V_12 . V_75 ) ;
V_123 -> V_125 = V_7 ;
V_7 -> V_12 . V_75 = V_123 ;
V_105 = 0 ;
}
}
F_36 ( & V_7 -> V_95 ) ;
F_38 ( V_7 , 3 , L_13 , V_120 ) ;
F_38 ( V_7 , 3 , L_14 ,
( void * ) V_7 -> V_12 . V_75 -> V_126 ) ;
break;
}
default:
V_105 = - V_112 ;
break;
}
return V_105 ;
}
static int F_51 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
struct V_8 * V_9 ;
int V_10 ;
if ( ! F_52 ( V_7 , 76 ) )
return - V_32 ;
F_32 ( & V_7 -> V_95 ) ;
switch ( V_104 -> V_104 ) {
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
F_36 ( & V_7 -> V_95 ) ;
return - V_112 ;
}
F_7 (i, vcpu, kvm) {
F_54 ( V_9 ) ;
F_55 ( V_9 ) ;
}
F_36 ( & V_7 -> V_95 ) ;
return 0 ;
}
static int F_56 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
T_2 V_137 ;
if ( F_57 ( & V_137 , ( void V_109 * ) V_104 -> V_110 ,
sizeof( V_137 ) ) )
return - V_111 ;
if ( V_137 != 0 )
return - V_32 ;
F_38 ( V_7 , 3 , L_19 , V_137 ) ;
return 0 ;
}
static int F_58 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
V_108 V_138 ;
if ( F_57 ( & V_138 , ( void V_109 * ) V_104 -> V_110 , sizeof( V_138 ) ) )
return - V_111 ;
F_59 ( V_7 , V_138 ) ;
F_38 ( V_7 , 3 , L_20 , V_138 ) ;
return 0 ;
}
static int F_60 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
int V_105 ;
if ( V_104 -> V_92 )
return - V_32 ;
switch ( V_104 -> V_104 ) {
case V_139 :
V_105 = F_56 ( V_7 , V_104 ) ;
break;
case V_140 :
V_105 = F_58 ( V_7 , V_104 ) ;
break;
default:
V_105 = - V_112 ;
break;
}
return V_105 ;
}
static int F_61 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
T_2 V_137 = 0 ;
if ( F_62 ( ( void V_109 * ) V_104 -> V_110 , & V_137 ,
sizeof( V_137 ) ) )
return - V_111 ;
F_38 ( V_7 , 3 , L_21 , V_137 ) ;
return 0 ;
}
static int F_63 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
V_108 V_138 ;
V_138 = F_64 ( V_7 ) ;
if ( F_62 ( ( void V_109 * ) V_104 -> V_110 , & V_138 , sizeof( V_138 ) ) )
return - V_111 ;
F_38 ( V_7 , 3 , L_22 , V_138 ) ;
return 0 ;
}
static int F_65 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
int V_105 ;
if ( V_104 -> V_92 )
return - V_32 ;
switch ( V_104 -> V_104 ) {
case V_139 :
V_105 = F_61 ( V_7 , V_104 ) ;
break;
case V_140 :
V_105 = F_63 ( V_7 , V_104 ) ;
break;
default:
V_105 = - V_112 ;
break;
}
return V_105 ;
}
static int F_66 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
struct V_141 * V_142 ;
int V_105 = 0 ;
F_32 ( & V_7 -> V_95 ) ;
if ( F_39 ( & V_7 -> V_96 ) ) {
V_105 = - V_97 ;
goto V_87;
}
V_142 = F_67 ( sizeof( * V_142 ) , V_143 ) ;
if ( ! V_142 ) {
V_105 = - V_23 ;
goto V_87;
}
if ( ! F_57 ( V_142 , ( void V_109 * ) V_104 -> V_110 ,
sizeof( * V_142 ) ) ) {
memcpy ( & V_7 -> V_12 . V_98 . V_144 , & V_142 -> V_145 ,
sizeof( struct V_145 ) ) ;
V_7 -> V_12 . V_98 . V_146 = V_142 -> V_146 ;
memcpy ( V_7 -> V_12 . V_98 . V_99 -> V_101 , V_142 -> V_147 ,
V_148 ) ;
} else
V_105 = - V_111 ;
F_68 ( V_142 ) ;
V_87:
F_36 ( & V_7 -> V_95 ) ;
return V_105 ;
}
static int F_69 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
int V_105 = - V_112 ;
switch ( V_104 -> V_104 ) {
case V_149 :
V_105 = F_66 ( V_7 , V_104 ) ;
break;
}
return V_105 ;
}
static int F_70 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
struct V_141 * V_142 ;
int V_105 = 0 ;
V_142 = F_67 ( sizeof( * V_142 ) , V_143 ) ;
if ( ! V_142 ) {
V_105 = - V_23 ;
goto V_87;
}
memcpy ( & V_142 -> V_145 , & V_7 -> V_12 . V_98 . V_144 , sizeof( struct V_145 ) ) ;
V_142 -> V_146 = V_7 -> V_12 . V_98 . V_146 ;
memcpy ( & V_142 -> V_147 , V_7 -> V_12 . V_98 . V_99 -> V_101 , V_148 ) ;
if ( F_62 ( ( void V_109 * ) V_104 -> V_110 , V_142 , sizeof( * V_142 ) ) )
V_105 = - V_111 ;
F_68 ( V_142 ) ;
V_87:
return V_105 ;
}
static int F_71 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
struct V_150 * V_151 ;
int V_105 = 0 ;
V_151 = F_67 ( sizeof( * V_151 ) , V_143 ) ;
if ( ! V_151 ) {
V_105 = - V_23 ;
goto V_87;
}
F_72 ( (struct V_145 * ) & V_151 -> V_145 ) ;
V_151 -> V_146 = V_59 . V_146 ;
memcpy ( & V_151 -> V_152 , V_7 -> V_12 . V_98 . V_99 -> V_100 ,
V_148 ) ;
memcpy ( ( unsigned long * ) & V_151 -> V_147 , V_153 . V_154 ,
V_148 ) ;
if ( F_62 ( ( void V_109 * ) V_104 -> V_110 , V_151 , sizeof( * V_151 ) ) )
V_105 = - V_111 ;
F_68 ( V_151 ) ;
V_87:
return V_105 ;
}
static int F_73 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
int V_105 = - V_112 ;
switch ( V_104 -> V_104 ) {
case V_149 :
V_105 = F_70 ( V_7 , V_104 ) ;
break;
case V_155 :
V_105 = F_71 ( V_7 , V_104 ) ;
break;
}
return V_105 ;
}
static int F_74 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
int V_105 ;
switch ( V_104 -> V_156 ) {
case V_157 :
V_105 = F_43 ( V_7 , V_104 ) ;
break;
case V_158 :
V_105 = F_60 ( V_7 , V_104 ) ;
break;
case V_159 :
V_105 = F_69 ( V_7 , V_104 ) ;
break;
case V_160 :
V_105 = F_51 ( V_7 , V_104 ) ;
break;
default:
V_105 = - V_112 ;
break;
}
return V_105 ;
}
static int F_75 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
int V_105 ;
switch ( V_104 -> V_156 ) {
case V_157 :
V_105 = F_41 ( V_7 , V_104 ) ;
break;
case V_158 :
V_105 = F_65 ( V_7 , V_104 ) ;
break;
case V_159 :
V_105 = F_73 ( V_7 , V_104 ) ;
break;
default:
V_105 = - V_112 ;
break;
}
return V_105 ;
}
static int F_76 ( struct V_7 * V_7 , struct V_103 * V_104 )
{
int V_105 ;
switch ( V_104 -> V_156 ) {
case V_157 :
switch ( V_104 -> V_104 ) {
case V_114 :
case V_118 :
case V_106 :
V_105 = 0 ;
break;
default:
V_105 = - V_112 ;
break;
}
break;
case V_158 :
switch ( V_104 -> V_104 ) {
case V_140 :
case V_139 :
V_105 = 0 ;
break;
default:
V_105 = - V_112 ;
break;
}
break;
case V_159 :
switch ( V_104 -> V_104 ) {
case V_149 :
case V_155 :
V_105 = 0 ;
break;
default:
V_105 = - V_112 ;
break;
}
break;
case V_160 :
switch ( V_104 -> V_104 ) {
case V_127 :
case V_132 :
case V_135 :
case V_136 :
V_105 = 0 ;
break;
default:
V_105 = - V_112 ;
break;
}
break;
default:
V_105 = - V_112 ;
break;
}
return V_105 ;
}
static long F_77 ( struct V_7 * V_7 , struct V_161 * args )
{
T_3 * V_162 ;
T_4 V_163 ;
unsigned long V_164 ;
int V_10 , V_34 = 0 ;
if ( args -> V_92 != 0 )
return - V_32 ;
if ( ! F_78 ( V_124 -> V_76 ) )
return V_165 ;
if ( args -> V_166 < 1 || args -> V_166 > V_167 )
return - V_32 ;
V_162 = F_79 ( args -> V_166 , sizeof( T_3 ) ,
V_143 | V_168 ) ;
if ( ! V_162 )
V_162 = F_80 ( sizeof( T_3 ) * args -> V_166 ) ;
if ( ! V_162 )
return - V_23 ;
for ( V_10 = 0 ; V_10 < args -> V_166 ; V_10 ++ ) {
V_163 = F_81 ( V_7 , args -> V_169 + V_10 ) ;
if ( F_82 ( V_163 ) ) {
V_34 = - V_111 ;
goto V_87;
}
V_164 = F_83 ( V_124 -> V_76 , V_163 ) ;
if ( F_84 ( V_164 ) ) {
V_34 = V_164 ;
goto V_87;
}
V_162 [ V_10 ] = V_164 ;
}
V_34 = F_62 ( ( T_3 V_109 * ) args -> V_170 , V_162 ,
sizeof( T_3 ) * args -> V_166 ) ;
if ( V_34 )
V_34 = - V_111 ;
V_87:
F_85 ( V_162 ) ;
return V_34 ;
}
static long F_86 ( struct V_7 * V_7 , struct V_161 * args )
{
T_3 * V_162 ;
T_4 V_163 ;
int V_10 , V_34 = 0 ;
if ( args -> V_92 != 0 )
return - V_32 ;
if ( args -> V_166 < 1 || args -> V_166 > V_167 )
return - V_32 ;
V_162 = F_79 ( args -> V_166 , sizeof( T_3 ) ,
V_143 | V_168 ) ;
if ( ! V_162 )
V_162 = F_80 ( sizeof( T_3 ) * args -> V_166 ) ;
if ( ! V_162 )
return - V_23 ;
V_34 = F_57 ( V_162 , ( T_3 V_109 * ) args -> V_170 ,
sizeof( T_3 ) * args -> V_166 ) ;
if ( V_34 ) {
V_34 = - V_111 ;
goto V_87;
}
V_34 = F_87 () ;
if ( V_34 )
goto V_87;
for ( V_10 = 0 ; V_10 < args -> V_166 ; V_10 ++ ) {
V_163 = F_81 ( V_7 , args -> V_169 + V_10 ) ;
if ( F_82 ( V_163 ) ) {
V_34 = - V_111 ;
goto V_87;
}
if ( V_162 [ V_10 ] & 0x01 ) {
V_34 = - V_32 ;
goto V_87;
}
V_34 = F_88 ( V_124 -> V_76 , V_163 ,
( unsigned long ) V_162 [ V_10 ] , 0 ) ;
if ( V_34 )
goto V_87;
}
V_87:
F_85 ( V_162 ) ;
return V_34 ;
}
long F_89 ( struct V_27 * V_28 ,
unsigned int V_29 , unsigned long V_30 )
{
struct V_7 * V_7 = V_28 -> V_171 ;
void V_109 * V_172 = ( void V_109 * ) V_30 ;
struct V_103 V_104 ;
int V_34 ;
switch ( V_29 ) {
case V_173 : {
struct V_174 V_175 ;
V_34 = - V_111 ;
if ( F_57 ( & V_175 , V_172 , sizeof( V_175 ) ) )
break;
V_34 = F_90 ( V_7 , & V_175 ) ;
break;
}
case V_176 : {
struct V_90 V_91 ;
V_34 = - V_111 ;
if ( F_57 ( & V_91 , V_172 , sizeof( V_91 ) ) )
break;
V_34 = F_37 ( V_7 , & V_91 ) ;
break;
}
case V_177 : {
struct V_178 V_179 ;
V_34 = - V_32 ;
if ( V_7 -> V_12 . V_93 ) {
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
V_34 = F_91 ( V_7 , & V_179 , 0 , 0 ) ;
}
break;
}
case V_180 : {
V_34 = - V_111 ;
if ( F_57 ( & V_104 , ( void V_109 * ) V_30 , sizeof( V_104 ) ) )
break;
V_34 = F_74 ( V_7 , & V_104 ) ;
break;
}
case V_181 : {
V_34 = - V_111 ;
if ( F_57 ( & V_104 , ( void V_109 * ) V_30 , sizeof( V_104 ) ) )
break;
V_34 = F_75 ( V_7 , & V_104 ) ;
break;
}
case V_182 : {
V_34 = - V_111 ;
if ( F_57 ( & V_104 , ( void V_109 * ) V_30 , sizeof( V_104 ) ) )
break;
V_34 = F_76 ( V_7 , & V_104 ) ;
break;
}
case V_183 : {
struct V_161 args ;
V_34 = - V_111 ;
if ( F_57 ( & args , V_172 ,
sizeof( struct V_161 ) ) )
break;
V_34 = F_77 ( V_7 , & args ) ;
break;
}
case V_184 : {
struct V_161 args ;
V_34 = - V_111 ;
if ( F_57 ( & args , V_172 ,
sizeof( struct V_161 ) ) )
break;
V_34 = F_86 ( V_7 , & args ) ;
break;
}
default:
V_34 = - V_185 ;
}
return V_34 ;
}
static int F_92 ( T_2 * V_186 )
{
T_5 V_187 = 0x04000000UL ;
T_5 V_188 = 0 ;
memset ( V_186 , 0 , 128 ) ;
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
return V_188 ;
}
static int F_93 ( void )
{
T_2 V_186 [ 128 ] ;
int V_188 ;
if ( F_24 ( 12 ) ) {
V_188 = F_92 ( V_186 ) ;
if ( V_188 )
F_94 ( L_23 , V_188 ) ;
else
return V_186 [ 0 ] & 0x40 ;
}
return 0 ;
}
static void F_95 ( struct V_7 * V_7 )
{
V_7 -> V_12 . V_128 . V_189 = ( V_190 ) ( unsigned long ) V_7 -> V_12 . V_128 . V_129 ;
if ( F_93 () )
V_7 -> V_12 . V_128 . V_189 |= V_191 ;
else
V_7 -> V_12 . V_128 . V_189 |= V_192 ;
}
static void F_96 ( struct V_145 * V_144 )
{
F_72 ( V_144 ) ;
V_144 -> V_193 = 0xff ;
}
static int F_97 ( struct V_7 * V_7 )
{
if ( ! F_52 ( V_7 , 76 ) )
return 0 ;
V_7 -> V_12 . V_128 . V_129 = F_67 ( sizeof( * V_7 -> V_12 . V_128 . V_129 ) ,
V_143 | V_194 ) ;
if ( ! V_7 -> V_12 . V_128 . V_129 )
return - V_23 ;
F_95 ( V_7 ) ;
V_7 -> V_12 . V_128 . V_131 = 1 ;
V_7 -> V_12 . V_128 . V_134 = 1 ;
F_53 ( V_7 -> V_12 . V_128 . V_129 -> V_130 ,
sizeof( V_7 -> V_12 . V_128 . V_129 -> V_130 ) ) ;
F_53 ( V_7 -> V_12 . V_128 . V_129 -> V_133 ,
sizeof( V_7 -> V_12 . V_128 . V_129 -> V_133 ) ) ;
return 0 ;
}
static void F_98 ( struct V_7 * V_7 )
{
if ( V_7 -> V_12 . V_195 )
F_99 ( V_7 -> V_12 . V_196 , sizeof( struct V_197 ) ) ;
else
F_100 ( ( unsigned long ) ( V_7 -> V_12 . V_196 ) ) ;
V_7 -> V_12 . V_196 = NULL ;
}
int F_101 ( struct V_7 * V_7 , unsigned long type )
{
int V_10 , V_198 ;
char V_199 [ 16 ] ;
static unsigned long V_200 ;
V_198 = - V_32 ;
#ifdef F_23
if ( type & ~ V_201 )
goto V_202;
if ( ( type & V_201 ) && ( ! F_102 ( V_203 ) ) )
goto V_202;
#else
if ( type )
goto V_202;
#endif
V_198 = F_21 () ;
if ( V_198 )
goto V_202;
V_198 = - V_23 ;
V_7 -> V_12 . V_195 = 0 ;
F_103 ( & V_7 -> V_12 . V_204 ) ;
V_7 -> V_12 . V_196 = (struct V_205 * ) F_104 ( V_143 ) ;
if ( ! V_7 -> V_12 . V_196 )
goto V_202;
F_105 ( & V_206 ) ;
V_200 += 16 ;
if ( V_200 + sizeof( struct V_205 ) > V_207 )
V_200 = 0 ;
V_7 -> V_12 . V_196 = (struct V_205 * )
( ( char * ) V_7 -> V_12 . V_196 + V_200 ) ;
F_106 ( & V_206 ) ;
sprintf ( V_199 , L_24 , V_124 -> V_208 ) ;
V_7 -> V_12 . V_209 = F_15 ( V_199 , 32 , 1 , 7 * sizeof( long ) ) ;
if ( ! V_7 -> V_12 . V_209 )
goto V_202;
V_7 -> V_12 . V_98 . V_99 =
(struct V_210 * ) F_104 ( V_143 | V_194 ) ;
if ( ! V_7 -> V_12 . V_98 . V_99 )
goto V_202;
memcpy ( V_7 -> V_12 . V_98 . V_99 -> V_100 , V_153 . V_154 ,
V_148 ) ;
for ( V_10 = 0 ; V_10 < V_211 ; V_10 ++ ) {
if ( V_10 < F_1 () )
V_7 -> V_12 . V_98 . V_99 -> V_100 [ V_10 ] &= V_1 [ V_10 ] ;
else
V_7 -> V_12 . V_98 . V_99 -> V_100 [ V_10 ] = 0UL ;
}
memcpy ( V_7 -> V_12 . V_98 . V_99 -> V_101 , V_7 -> V_12 . V_98 . V_99 -> V_100 ,
V_148 ) ;
F_96 ( & V_7 -> V_12 . V_98 . V_144 ) ;
V_7 -> V_12 . V_98 . V_146 = V_59 . V_146 & 0x0fff ;
if ( F_97 ( V_7 ) < 0 )
goto V_202;
F_107 ( & V_7 -> V_12 . V_212 . V_95 ) ;
for ( V_10 = 0 ; V_10 < V_213 ; V_10 ++ )
F_108 ( & V_7 -> V_12 . V_212 . V_214 [ V_10 ] ) ;
F_109 ( & V_7 -> V_12 . V_215 ) ;
F_110 ( & V_7 -> V_12 . V_216 ) ;
F_16 ( V_7 -> V_12 . V_209 , & V_24 ) ;
F_38 ( V_7 , 3 , L_25 , type ) ;
if ( type & V_201 ) {
V_7 -> V_12 . V_75 = NULL ;
V_7 -> V_12 . V_107 = V_121 ;
} else {
if ( V_59 . V_217 == V_218 )
V_7 -> V_12 . V_107 = V_219 ;
else
V_7 -> V_12 . V_107 = F_111 (unsigned long, TASK_MAX_SIZE,
sclp.hamax + 1 ) ;
V_7 -> V_12 . V_75 = F_49 ( V_124 -> V_76 , V_7 -> V_12 . V_107 - 1 ) ;
if ( ! V_7 -> V_12 . V_75 )
goto V_202;
V_7 -> V_12 . V_75 -> V_125 = V_7 ;
V_7 -> V_12 . V_75 -> V_220 = 0 ;
}
V_7 -> V_12 . V_221 = 0 ;
V_7 -> V_12 . V_93 = 0 ;
V_7 -> V_12 . V_13 = 0 ;
F_107 ( & V_7 -> V_12 . V_222 ) ;
F_112 ( 3 , L_26 , V_7 , V_124 -> V_208 ) ;
return 0 ;
V_202:
F_68 ( V_7 -> V_12 . V_128 . V_129 ) ;
F_100 ( ( unsigned long ) V_7 -> V_12 . V_98 . V_99 ) ;
F_17 ( V_7 -> V_12 . V_209 ) ;
F_98 ( V_7 ) ;
F_112 ( 3 , L_27 , V_198 ) ;
return V_198 ;
}
void F_113 ( struct V_8 * V_9 )
{
F_114 ( V_9 , 3 , L_2 , L_28 ) ;
F_115 ( V_9 -> V_223 ) ;
F_116 ( V_9 ) ;
F_117 ( V_9 ) ;
if ( ! F_47 ( V_9 -> V_7 ) )
F_118 ( V_9 ) ;
if ( F_47 ( V_9 -> V_7 ) )
F_50 ( V_9 -> V_12 . V_75 ) ;
if ( V_9 -> V_7 -> V_12 . V_117 )
F_119 ( V_9 ) ;
F_100 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
F_120 ( V_9 ) ;
F_121 ( V_224 , V_9 ) ;
}
static void F_122 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm)
F_113 ( V_9 ) ;
F_32 ( & V_7 -> V_95 ) ;
for ( V_10 = 0 ; V_10 < F_39 ( & V_7 -> V_96 ) ; V_10 ++ )
V_7 -> V_225 [ V_10 ] = NULL ;
F_123 ( & V_7 -> V_96 , 0 ) ;
F_36 ( & V_7 -> V_95 ) ;
}
void F_124 ( struct V_7 * V_7 )
{
F_122 ( V_7 ) ;
F_100 ( ( unsigned long ) V_7 -> V_12 . V_98 . V_99 ) ;
F_98 ( V_7 ) ;
F_17 ( V_7 -> V_12 . V_209 ) ;
F_68 ( V_7 -> V_12 . V_128 . V_129 ) ;
if ( ! F_47 ( V_7 ) )
F_50 ( V_7 -> V_12 . V_75 ) ;
F_125 ( V_7 ) ;
F_126 ( V_7 ) ;
F_112 ( 3 , L_29 , V_7 ) ;
}
static int F_127 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_75 = F_49 ( V_124 -> V_76 , - 1UL ) ;
if ( ! V_9 -> V_12 . V_75 )
return - V_23 ;
V_9 -> V_12 . V_75 -> V_125 = V_9 -> V_7 ;
return 0 ;
}
static void F_118 ( struct V_8 * V_9 )
{
F_128 ( & V_9 -> V_7 -> V_12 . V_204 ) ;
if ( V_9 -> V_7 -> V_12 . V_195 ) {
struct V_197 * V_196 = V_9 -> V_7 -> V_12 . V_196 ;
F_129 ( V_9 -> V_223 , ( unsigned long * ) V_196 -> V_226 ) ;
V_196 -> V_227 [ V_9 -> V_223 ] . V_228 = 0 ;
} else {
struct V_205 * V_196 = V_9 -> V_7 -> V_12 . V_196 ;
F_129 ( V_9 -> V_223 , ( unsigned long * ) & V_196 -> V_226 ) ;
V_196 -> V_227 [ V_9 -> V_223 ] . V_228 = 0 ;
}
F_130 ( & V_9 -> V_7 -> V_12 . V_204 ) ;
}
static void F_131 ( struct V_8 * V_9 )
{
F_128 ( & V_9 -> V_7 -> V_12 . V_204 ) ;
if ( V_9 -> V_7 -> V_12 . V_195 ) {
struct V_197 * V_196 = V_9 -> V_7 -> V_12 . V_196 ;
V_196 -> V_227 [ V_9 -> V_223 ] . V_228 = ( V_229 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_230 = ( V_190 ) ( ( ( V_229 ) V_196 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_231 = ( V_190 ) ( V_229 ) V_196 & ~ 0x3fU ;
V_9 -> V_12 . V_14 -> V_232 |= 0x04U ;
F_132 ( V_9 -> V_223 , ( unsigned long * ) V_196 -> V_226 ) ;
} else {
struct V_205 * V_196 = V_9 -> V_7 -> V_12 . V_196 ;
V_196 -> V_227 [ V_9 -> V_223 ] . V_228 = ( V_229 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_230 = ( V_190 ) ( ( ( V_229 ) V_196 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_231 = ( V_190 ) ( V_229 ) V_196 ;
F_132 ( V_9 -> V_223 , ( unsigned long * ) & V_196 -> V_226 ) ;
}
F_130 ( & V_9 -> V_7 -> V_12 . V_204 ) ;
}
static inline void F_133 ( struct V_233 * V_234 , struct V_235 * V_236 )
{
V_234 -> V_228 = V_236 -> V_228 ;
V_234 -> V_237 . V_238 = V_236 -> V_237 . V_238 ;
V_234 -> V_237 . V_239 = V_236 -> V_237 . V_239 ;
}
static void F_134 ( struct V_197 * V_234 , struct V_205 * V_236 )
{
int V_10 ;
V_234 -> V_240 = V_236 -> V_240 ;
V_234 -> V_226 [ 0 ] = V_236 -> V_226 ;
for ( V_10 = 0 ; V_10 < V_62 ; V_10 ++ )
F_133 ( & V_234 -> V_227 [ V_10 ] , & V_236 -> V_227 [ V_10 ] ) ;
}
static int F_135 ( struct V_7 * V_7 )
{
struct V_205 * V_241 = V_7 -> V_12 . V_196 ;
struct V_197 * V_242 ;
struct V_8 * V_9 ;
unsigned int V_243 ;
T_5 V_231 , V_230 ;
V_242 = F_136 ( sizeof( * V_242 ) , V_143 | V_244 ) ;
if ( ! V_242 )
return - V_23 ;
V_230 = ( T_5 ) ( ( V_108 ) ( V_242 ) >> 32 ) ;
V_231 = ( T_5 ) ( V_108 ) ( V_242 ) & ~ 0x3fU ;
F_137 ( V_7 ) ;
F_138 ( & V_7 -> V_12 . V_204 ) ;
F_134 ( V_242 , V_241 ) ;
F_7 (vcpu_idx, vcpu, kvm) {
V_9 -> V_12 . V_14 -> V_230 = V_230 ;
V_9 -> V_12 . V_14 -> V_231 = V_231 ;
V_9 -> V_12 . V_14 -> V_232 |= 0x04U ;
}
V_7 -> V_12 . V_196 = V_242 ;
V_7 -> V_12 . V_195 = 1 ;
F_139 ( & V_7 -> V_12 . V_204 ) ;
F_140 ( V_7 ) ;
F_100 ( ( unsigned long ) V_241 ) ;
F_38 ( V_7 , 2 , L_30 ,
V_241 , V_7 -> V_12 . V_196 ) ;
return 0 ;
}
static int F_141 ( struct V_7 * V_7 , unsigned int V_245 )
{
int V_198 ;
if ( V_245 < V_62 )
return true ;
if ( ! V_59 . V_60 )
return false ;
F_32 ( & V_7 -> V_95 ) ;
V_198 = V_7 -> V_12 . V_195 ? 0 : F_135 ( V_7 ) ;
F_36 ( & V_7 -> V_95 ) ;
return V_198 == 0 && V_245 < V_61 ;
}
int F_142 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_246 = V_247 ;
F_117 ( V_9 ) ;
V_9 -> V_248 -> V_249 = V_250 |
V_251 |
V_252 |
V_253 |
V_254 |
V_255 ;
if ( F_52 ( V_9 -> V_7 , 64 ) )
V_9 -> V_248 -> V_249 |= V_256 ;
if ( F_52 ( V_9 -> V_7 , 129 ) )
V_9 -> V_248 -> V_249 |= V_257 ;
if ( F_47 ( V_9 -> V_7 ) )
return F_127 ( V_9 ) ;
return 0 ;
}
void F_143 ( struct V_8 * V_9 , int V_227 )
{
F_144 () ;
V_9 -> V_12 . V_258 . V_259 = V_124 -> V_260 . V_261 . V_259 ;
V_9 -> V_12 . V_258 . V_262 = V_124 -> V_260 . V_261 . V_262 ;
V_124 -> V_260 . V_261 . V_262 = V_9 -> V_248 -> V_236 . V_262 . V_263 ;
V_124 -> V_260 . V_261 . V_259 = V_9 -> V_248 -> V_236 . V_262 . V_259 ;
if ( F_145 ( V_124 -> V_260 . V_261 . V_259 ) )
V_124 -> V_260 . V_261 . V_259 = 0 ;
F_146 ( V_9 -> V_12 . V_264 ) ;
F_147 ( V_9 -> V_248 -> V_236 . V_262 . V_265 ) ;
F_148 ( V_9 -> V_12 . V_75 ) ;
F_149 ( V_266 , & V_9 -> V_12 . V_14 -> V_267 ) ;
}
void F_150 ( struct V_8 * V_9 )
{
F_151 ( V_266 , & V_9 -> V_12 . V_14 -> V_267 ) ;
F_152 ( V_9 -> V_12 . V_75 ) ;
F_144 () ;
V_9 -> V_248 -> V_236 . V_262 . V_259 = V_124 -> V_260 . V_261 . V_259 ;
V_124 -> V_260 . V_261 . V_259 = V_9 -> V_12 . V_258 . V_259 ;
V_124 -> V_260 . V_261 . V_262 = V_9 -> V_12 . V_258 . V_262 ;
F_146 ( V_9 -> V_248 -> V_236 . V_262 . V_265 ) ;
F_147 ( V_9 -> V_12 . V_264 ) ;
}
static void F_153 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_268 . V_100 = 0UL ;
V_9 -> V_12 . V_14 -> V_268 . V_110 = 0UL ;
F_154 ( V_9 , 0 ) ;
V_9 -> V_12 . V_14 -> V_269 = 0UL ;
V_9 -> V_12 . V_14 -> V_270 = 0UL ;
V_9 -> V_12 . V_14 -> V_271 = 0 ;
memset ( V_9 -> V_12 . V_14 -> V_272 , 0 , 16 * sizeof( V_229 ) ) ;
V_9 -> V_12 . V_14 -> V_272 [ 0 ] = 0xE0UL ;
V_9 -> V_12 . V_14 -> V_272 [ 14 ] = 0xC2000000UL ;
F_144 () ;
V_124 -> V_260 . V_261 . V_259 = 0 ;
V_9 -> V_12 . V_14 -> V_273 = 1 ;
V_9 -> V_12 . V_14 -> V_274 = 0 ;
V_9 -> V_12 . V_246 = V_247 ;
F_117 ( V_9 ) ;
if ( ! F_155 ( V_9 -> V_7 ) )
F_156 ( V_9 ) ;
F_116 ( V_9 ) ;
}
void F_157 ( struct V_8 * V_9 )
{
F_32 ( & V_9 -> V_7 -> V_95 ) ;
F_158 () ;
V_9 -> V_12 . V_14 -> V_13 = V_9 -> V_7 -> V_12 . V_13 ;
F_159 () ;
F_36 ( & V_9 -> V_7 -> V_95 ) ;
if ( ! F_47 ( V_9 -> V_7 ) ) {
V_9 -> V_12 . V_75 = V_9 -> V_7 -> V_12 . V_75 ;
F_131 ( V_9 ) ;
}
}
static void F_54 ( struct V_8 * V_9 )
{
if ( ! F_52 ( V_9 -> V_7 , 76 ) )
return;
V_9 -> V_12 . V_14 -> V_275 &= ~ ( V_276 | V_277 ) ;
if ( V_9 -> V_7 -> V_12 . V_128 . V_131 )
V_9 -> V_12 . V_14 -> V_275 |= V_276 ;
if ( V_9 -> V_7 -> V_12 . V_128 . V_134 )
V_9 -> V_12 . V_14 -> V_275 |= V_277 ;
V_9 -> V_12 . V_14 -> V_189 = V_9 -> V_7 -> V_12 . V_128 . V_189 ;
}
void F_119 ( struct V_8 * V_9 )
{
F_100 ( V_9 -> V_12 . V_14 -> V_278 ) ;
V_9 -> V_12 . V_14 -> V_278 = 0 ;
}
int F_160 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_278 = F_104 ( V_143 ) ;
if ( ! V_9 -> V_12 . V_14 -> V_278 )
return - V_23 ;
V_9 -> V_12 . V_14 -> V_232 |= 0x80 ;
V_9 -> V_12 . V_14 -> V_232 &= ~ 0x08 ;
return 0 ;
}
static void F_161 ( struct V_8 * V_9 )
{
struct V_279 * V_98 = & V_9 -> V_7 -> V_12 . V_98 ;
V_9 -> V_12 . V_144 = V_98 -> V_144 ;
V_9 -> V_12 . V_14 -> V_146 = V_98 -> V_146 ;
V_9 -> V_12 . V_14 -> V_99 = ( int ) ( long ) V_98 -> V_99 -> V_101 ;
}
int F_162 ( struct V_8 * V_9 )
{
int V_198 = 0 ;
F_123 ( & V_9 -> V_12 . V_14 -> V_267 , V_280 |
V_281 |
V_282 ) ;
if ( F_52 ( V_9 -> V_7 , 78 ) )
F_149 ( V_283 , & V_9 -> V_12 . V_14 -> V_267 ) ;
else if ( F_52 ( V_9 -> V_7 , 8 ) )
F_149 ( V_284 , & V_9 -> V_12 . V_14 -> V_267 ) ;
F_161 ( V_9 ) ;
V_9 -> V_12 . V_14 -> V_285 = 6 ;
if ( F_52 ( V_9 -> V_7 , 50 ) && F_52 ( V_9 -> V_7 , 73 ) )
V_9 -> V_12 . V_14 -> V_285 |= 0x10 ;
V_9 -> V_12 . V_14 -> V_232 = 8 ;
V_9 -> V_12 . V_14 -> V_286 = 0xC1002000U ;
if ( V_59 . V_287 )
V_9 -> V_12 . V_14 -> V_286 |= 1 ;
if ( V_59 . V_288 )
V_9 -> V_12 . V_14 -> V_286 |= 0x10000000U ;
if ( F_52 ( V_9 -> V_7 , 64 ) )
V_9 -> V_12 . V_14 -> V_275 |= 0x01 ;
if ( F_52 ( V_9 -> V_7 , 129 ) ) {
V_9 -> V_12 . V_14 -> V_286 |= 0x00020000 ;
V_9 -> V_12 . V_14 -> V_289 |= 0x20000000 ;
}
V_9 -> V_12 . V_14 -> V_290 = ( unsigned long ) & V_9 -> V_248 -> V_236 . V_262 . V_291 ;
V_9 -> V_12 . V_14 -> V_292 |= V_293 | V_294 | V_295 ;
if ( V_9 -> V_7 -> V_12 . V_117 ) {
V_198 = F_160 ( V_9 ) ;
if ( V_198 )
return V_198 ;
}
F_163 ( & V_9 -> V_12 . V_296 , V_297 , V_298 ) ;
V_9 -> V_12 . V_296 . V_299 = V_300 ;
F_54 ( V_9 ) ;
return V_198 ;
}
struct V_8 * F_164 ( struct V_7 * V_7 ,
unsigned int V_245 )
{
struct V_8 * V_9 ;
struct V_301 * V_301 ;
int V_198 = - V_32 ;
if ( ! F_47 ( V_7 ) && ! F_141 ( V_7 , V_245 ) )
goto V_87;
V_198 = - V_23 ;
V_9 = F_165 ( V_224 , V_143 ) ;
if ( ! V_9 )
goto V_87;
V_301 = (struct V_301 * ) F_104 ( V_143 ) ;
if ( ! V_301 )
goto V_302;
V_9 -> V_12 . V_14 = & V_301 -> V_14 ;
V_9 -> V_12 . V_14 -> V_303 = ( unsigned long ) & V_301 -> V_304 ;
V_9 -> V_12 . V_14 -> V_305 = V_245 ;
F_107 ( & V_9 -> V_12 . V_306 . V_95 ) ;
V_9 -> V_12 . V_306 . V_212 = & V_7 -> V_12 . V_212 ;
V_9 -> V_12 . V_306 . V_307 = & V_9 -> V_307 ;
V_9 -> V_12 . V_306 . V_267 = & V_9 -> V_12 . V_14 -> V_267 ;
V_198 = F_166 ( V_9 , V_7 , V_245 ) ;
if ( V_198 )
goto V_308;
F_38 ( V_7 , 3 , L_31 , V_245 , V_9 ,
V_9 -> V_12 . V_14 ) ;
F_167 ( V_245 , V_9 , V_9 -> V_12 . V_14 ) ;
return V_9 ;
V_308:
F_100 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
V_302:
F_121 ( V_224 , V_9 ) ;
V_87:
return F_168 ( V_198 ) ;
}
int F_169 ( struct V_8 * V_9 )
{
return F_170 ( V_9 , 0 ) ;
}
void F_171 ( struct V_8 * V_9 )
{
F_149 ( V_309 , & V_9 -> V_12 . V_14 -> V_310 ) ;
F_55 ( V_9 ) ;
}
void F_172 ( struct V_8 * V_9 )
{
F_151 ( V_309 , & V_9 -> V_12 . V_14 -> V_310 ) ;
}
static void F_173 ( struct V_8 * V_9 )
{
F_149 ( V_311 , & V_9 -> V_12 . V_14 -> V_310 ) ;
F_55 ( V_9 ) ;
}
static void F_174 ( struct V_8 * V_9 )
{
F_151 ( V_311 , & V_9 -> V_12 . V_14 -> V_310 ) ;
}
void F_55 ( struct V_8 * V_9 )
{
F_149 ( V_312 , & V_9 -> V_12 . V_14 -> V_267 ) ;
while ( V_9 -> V_12 . V_14 -> V_313 & V_314 )
F_175 () ;
}
void F_176 ( int V_315 , struct V_8 * V_9 )
{
F_177 ( V_315 , V_9 ) ;
F_173 ( V_9 ) ;
}
static void V_18 ( struct V_75 * V_75 , unsigned long V_74 )
{
int V_10 ;
struct V_7 * V_7 = V_75 -> V_125 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
if ( F_178 ( V_9 ) == ( V_74 & ~ 0x1000UL ) ) {
F_114 ( V_9 , 2 , L_32 , V_74 ) ;
F_176 ( V_316 , V_9 ) ;
}
}
}
int F_179 ( struct V_8 * V_9 )
{
F_180 () ;
return 0 ;
}
static int F_181 ( struct V_8 * V_9 ,
struct V_317 * V_318 )
{
int V_34 = - V_32 ;
switch ( V_318 -> V_245 ) {
case V_319 :
V_34 = F_42 ( V_9 -> V_12 . V_14 -> V_271 ,
( T_5 V_109 * ) V_318 -> V_110 ) ;
break;
case V_320 :
V_34 = F_42 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_108 V_109 * ) V_318 -> V_110 ) ;
break;
case V_321 :
V_34 = F_42 ( V_9 -> V_12 . V_14 -> V_269 ,
( V_108 V_109 * ) V_318 -> V_110 ) ;
break;
case V_322 :
V_34 = F_42 ( V_9 -> V_12 . V_14 -> V_270 ,
( V_108 V_109 * ) V_318 -> V_110 ) ;
break;
case V_323 :
V_34 = F_42 ( V_9 -> V_12 . V_246 ,
( V_108 V_109 * ) V_318 -> V_110 ) ;
break;
case V_324 :
V_34 = F_42 ( V_9 -> V_12 . V_325 ,
( V_108 V_109 * ) V_318 -> V_110 ) ;
break;
case V_326 :
V_34 = F_42 ( V_9 -> V_12 . V_327 ,
( V_108 V_109 * ) V_318 -> V_110 ) ;
break;
case V_328 :
V_34 = F_42 ( V_9 -> V_12 . V_14 -> V_274 ,
( V_108 V_109 * ) V_318 -> V_110 ) ;
break;
case V_329 :
V_34 = F_42 ( V_9 -> V_12 . V_14 -> V_273 ,
( V_108 V_109 * ) V_318 -> V_110 ) ;
break;
default:
break;
}
return V_34 ;
}
static int F_182 ( struct V_8 * V_9 ,
struct V_317 * V_318 )
{
int V_34 = - V_32 ;
switch ( V_318 -> V_245 ) {
case V_319 :
V_34 = F_48 ( V_9 -> V_12 . V_14 -> V_271 ,
( T_5 V_109 * ) V_318 -> V_110 ) ;
break;
case V_320 :
V_34 = F_48 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_108 V_109 * ) V_318 -> V_110 ) ;
break;
case V_321 :
V_34 = F_48 ( V_9 -> V_12 . V_14 -> V_269 ,
( V_108 V_109 * ) V_318 -> V_110 ) ;
break;
case V_322 :
V_34 = F_48 ( V_9 -> V_12 . V_14 -> V_270 ,
( V_108 V_109 * ) V_318 -> V_110 ) ;
break;
case V_323 :
V_34 = F_48 ( V_9 -> V_12 . V_246 ,
( V_108 V_109 * ) V_318 -> V_110 ) ;
if ( V_9 -> V_12 . V_246 == V_247 )
F_117 ( V_9 ) ;
break;
case V_324 :
V_34 = F_48 ( V_9 -> V_12 . V_325 ,
( V_108 V_109 * ) V_318 -> V_110 ) ;
break;
case V_326 :
V_34 = F_48 ( V_9 -> V_12 . V_327 ,
( V_108 V_109 * ) V_318 -> V_110 ) ;
break;
case V_328 :
V_34 = F_48 ( V_9 -> V_12 . V_14 -> V_274 ,
( V_108 V_109 * ) V_318 -> V_110 ) ;
break;
case V_329 :
V_34 = F_48 ( V_9 -> V_12 . V_14 -> V_273 ,
( V_108 V_109 * ) V_318 -> V_110 ) ;
break;
default:
break;
}
return V_34 ;
}
static int F_183 ( struct V_8 * V_9 )
{
F_153 ( V_9 ) ;
return 0 ;
}
int F_184 ( struct V_8 * V_9 , struct V_330 * V_262 )
{
memcpy ( & V_9 -> V_248 -> V_236 . V_262 . V_331 , & V_262 -> V_331 , sizeof( V_262 -> V_331 ) ) ;
return 0 ;
}
int F_185 ( struct V_8 * V_9 , struct V_330 * V_262 )
{
memcpy ( & V_262 -> V_331 , & V_9 -> V_248 -> V_236 . V_262 . V_331 , sizeof( V_262 -> V_331 ) ) ;
return 0 ;
}
int F_186 ( struct V_8 * V_9 ,
struct V_332 * V_333 )
{
memcpy ( & V_9 -> V_248 -> V_236 . V_262 . V_265 , & V_333 -> V_265 , sizeof( V_333 -> V_265 ) ) ;
memcpy ( & V_9 -> V_12 . V_14 -> V_272 , & V_333 -> V_334 , sizeof( V_333 -> V_334 ) ) ;
F_147 ( V_9 -> V_248 -> V_236 . V_262 . V_265 ) ;
return 0 ;
}
int F_187 ( struct V_8 * V_9 ,
struct V_332 * V_333 )
{
memcpy ( & V_333 -> V_265 , & V_9 -> V_248 -> V_236 . V_262 . V_265 , sizeof( V_333 -> V_265 ) ) ;
memcpy ( & V_333 -> V_334 , & V_9 -> V_12 . V_14 -> V_272 , sizeof( V_333 -> V_334 ) ) ;
return 0 ;
}
int F_188 ( struct V_8 * V_9 , struct V_335 * V_261 )
{
F_144 () ;
if ( F_145 ( V_261 -> V_259 ) )
return - V_32 ;
V_124 -> V_260 . V_261 . V_259 = V_261 -> V_259 ;
if ( V_68 )
F_189 ( V_124 -> V_260 . V_261 . V_336 , ( V_337 * ) V_261 -> V_338 ) ;
else
memcpy ( V_124 -> V_260 . V_261 . V_338 , & V_261 -> V_338 , sizeof( V_261 -> V_338 ) ) ;
return 0 ;
}
int F_190 ( struct V_8 * V_9 , struct V_335 * V_261 )
{
F_144 () ;
if ( V_68 )
F_191 ( ( V_337 * ) V_261 -> V_338 , V_124 -> V_260 . V_261 . V_336 ) ;
else
memcpy ( V_261 -> V_338 , V_124 -> V_260 . V_261 . V_338 , sizeof( V_261 -> V_338 ) ) ;
V_261 -> V_259 = V_124 -> V_260 . V_261 . V_259 ;
return 0 ;
}
static int F_192 ( struct V_8 * V_9 , T_6 V_339 )
{
int V_198 = 0 ;
if ( ! F_193 ( V_9 ) )
V_198 = - V_97 ;
else {
V_9 -> V_248 -> V_340 = V_339 . V_100 ;
V_9 -> V_248 -> V_341 = V_339 . V_110 ;
}
return V_198 ;
}
int F_194 ( struct V_8 * V_9 ,
struct V_342 * V_343 )
{
return - V_32 ;
}
int F_195 ( struct V_8 * V_9 ,
struct V_344 * V_345 )
{
int V_198 = 0 ;
V_9 -> V_346 = 0 ;
F_196 ( V_9 ) ;
if ( V_345 -> V_347 & ~ V_348 )
return - V_32 ;
if ( V_345 -> V_347 & V_349 ) {
V_9 -> V_346 = V_345 -> V_347 ;
F_149 ( V_350 , & V_9 -> V_12 . V_14 -> V_267 ) ;
if ( V_345 -> V_347 & V_351 )
V_198 = F_197 ( V_9 , V_345 ) ;
} else {
F_151 ( V_350 , & V_9 -> V_12 . V_14 -> V_267 ) ;
V_9 -> V_12 . V_352 . V_353 = 0 ;
}
if ( V_198 ) {
V_9 -> V_346 = 0 ;
F_196 ( V_9 ) ;
F_151 ( V_350 , & V_9 -> V_12 . V_14 -> V_267 ) ;
}
return V_198 ;
}
int F_198 ( struct V_8 * V_9 ,
struct V_354 * V_355 )
{
return F_193 ( V_9 ) ? V_356 :
V_357 ;
}
int F_199 ( struct V_8 * V_9 ,
struct V_354 * V_355 )
{
int V_198 = 0 ;
V_9 -> V_7 -> V_12 . V_358 = 1 ;
switch ( V_355 -> V_355 ) {
case V_356 :
F_156 ( V_9 ) ;
break;
case V_357 :
F_200 ( V_9 ) ;
break;
case V_359 :
case V_360 :
default:
V_198 = - V_112 ;
}
return V_198 ;
}
static bool F_201 ( struct V_8 * V_9 )
{
return F_39 ( & V_9 -> V_12 . V_14 -> V_267 ) & V_361 ;
}
static int F_202 ( struct V_8 * V_9 )
{
V_362:
F_174 ( V_9 ) ;
if ( ! V_9 -> V_363 )
return 0 ;
if ( F_203 ( V_316 , V_9 ) ) {
int V_198 ;
V_198 = F_204 ( V_9 -> V_12 . V_75 ,
F_178 ( V_9 ) ,
V_207 * 2 ) ;
if ( V_198 )
return V_198 ;
goto V_362;
}
if ( F_203 ( V_364 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_365 = 0xffff ;
goto V_362;
}
if ( F_203 ( V_366 , V_9 ) ) {
if ( ! F_201 ( V_9 ) ) {
F_205 ( V_9 -> V_223 , 1 ) ;
F_149 ( V_361 ,
& V_9 -> V_12 . V_14 -> V_267 ) ;
}
goto V_362;
}
if ( F_203 ( V_367 , V_9 ) ) {
if ( F_201 ( V_9 ) ) {
F_205 ( V_9 -> V_223 , 0 ) ;
F_151 ( V_361 ,
& V_9 -> V_12 . V_14 -> V_267 ) ;
}
goto V_362;
}
F_206 ( V_368 , & V_9 -> V_363 ) ;
return 0 ;
}
void F_59 ( struct V_7 * V_7 , V_108 V_369 )
{
struct V_8 * V_9 ;
int V_10 ;
F_32 ( & V_7 -> V_95 ) ;
F_158 () ;
V_7 -> V_12 . V_13 = V_369 - F_207 () ;
F_137 ( V_7 ) ;
F_7 (i, vcpu, kvm)
V_9 -> V_12 . V_14 -> V_13 = V_7 -> V_12 . V_13 ;
F_140 ( V_7 ) ;
F_159 () ;
F_36 ( & V_7 -> V_95 ) ;
}
long F_208 ( struct V_8 * V_9 , T_7 V_370 , int V_371 )
{
return F_209 ( V_9 -> V_12 . V_75 , V_370 ,
V_371 ? V_372 : 0 ) ;
}
static void F_210 ( struct V_8 * V_9 , bool V_373 ,
unsigned long V_374 )
{
struct V_174 V_375 ;
struct V_376 V_377 ;
if ( V_373 ) {
V_377 . V_378 . V_33 . V_379 = V_374 ;
V_377 . type = V_380 ;
F_211 ( F_212 ( V_9 , & V_377 ) ) ;
} else {
V_375 . type = V_381 ;
V_375 . V_382 = V_374 ;
F_211 ( F_90 ( V_9 -> V_7 , & V_375 ) ) ;
}
}
void F_213 ( struct V_8 * V_9 ,
struct V_383 * V_384 )
{
F_214 ( V_9 , V_384 -> V_12 . V_246 ) ;
F_210 ( V_9 , true , V_384 -> V_12 . V_246 ) ;
}
void F_215 ( struct V_8 * V_9 ,
struct V_383 * V_384 )
{
F_216 ( V_9 , V_384 -> V_12 . V_246 ) ;
F_210 ( V_9 , false , V_384 -> V_12 . V_246 ) ;
}
void F_217 ( struct V_8 * V_9 ,
struct V_383 * V_384 )
{
}
bool F_218 ( struct V_8 * V_9 )
{
return true ;
}
static int F_219 ( struct V_8 * V_9 )
{
T_8 V_163 ;
struct V_385 V_12 ;
int V_198 ;
if ( V_9 -> V_12 . V_246 == V_247 )
return 0 ;
if ( ( V_9 -> V_12 . V_14 -> V_268 . V_100 & V_9 -> V_12 . V_327 ) !=
V_9 -> V_12 . V_325 )
return 0 ;
if ( F_220 ( V_9 ) )
return 0 ;
if ( F_170 ( V_9 , 0 ) )
return 0 ;
if ( ! ( V_9 -> V_12 . V_14 -> V_272 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_9 -> V_12 . V_75 -> V_220 )
return 0 ;
V_163 = F_81 ( V_9 -> V_7 , F_221 ( V_124 -> V_260 . V_386 ) ) ;
V_163 += V_124 -> V_260 . V_386 & ~ V_387 ;
if ( F_222 ( V_9 , V_9 -> V_12 . V_246 , & V_12 . V_246 , 8 ) )
return 0 ;
V_198 = F_223 ( V_9 , V_124 -> V_260 . V_386 , V_163 , & V_12 ) ;
return V_198 ;
}
static int F_224 ( struct V_8 * V_9 )
{
int V_198 , V_267 ;
F_225 ( V_9 ) ;
V_9 -> V_12 . V_14 -> V_388 = V_9 -> V_248 -> V_236 . V_262 . V_331 [ 14 ] ;
V_9 -> V_12 . V_14 -> V_389 = V_9 -> V_248 -> V_236 . V_262 . V_331 [ 15 ] ;
if ( F_226 () )
F_227 () ;
if ( F_228 ( V_390 ) )
F_229 () ;
if ( ! F_47 ( V_9 -> V_7 ) ) {
V_198 = F_230 ( V_9 ) ;
if ( V_198 )
return V_198 ;
}
V_198 = F_202 ( V_9 ) ;
if ( V_198 )
return V_198 ;
if ( F_231 ( V_9 ) ) {
F_232 ( V_9 ) ;
F_233 ( V_9 ) ;
}
V_9 -> V_12 . V_14 -> V_391 = 0 ;
V_267 = F_39 ( & V_9 -> V_12 . V_14 -> V_267 ) ;
F_114 ( V_9 , 6 , L_33 , V_267 ) ;
F_234 ( V_9 , V_267 ) ;
return 0 ;
}
static int F_235 ( struct V_8 * V_9 )
{
T_6 * V_339 = & V_9 -> V_12 . V_14 -> V_268 ;
T_2 V_392 ;
int V_198 ;
F_114 ( V_9 , 3 , L_2 , L_34 ) ;
F_236 ( V_9 ) ;
V_198 = F_237 ( V_9 , V_339 -> V_110 , 0 , & V_392 , 1 ) ;
if ( V_198 )
return F_238 ( V_9 , V_198 ) ;
V_339 -> V_110 = F_239 ( * V_339 , - F_240 ( V_392 ) ) ;
return F_241 ( V_9 , V_393 ) ;
}
static int F_242 ( struct V_8 * V_9 , int V_394 )
{
F_114 ( V_9 , 6 , L_35 ,
V_9 -> V_12 . V_14 -> V_391 ) ;
F_243 ( V_9 , V_9 -> V_12 . V_14 -> V_391 ) ;
if ( F_231 ( V_9 ) )
F_244 ( V_9 ) ;
V_9 -> V_248 -> V_236 . V_262 . V_331 [ 14 ] = V_9 -> V_12 . V_14 -> V_388 ;
V_9 -> V_248 -> V_236 . V_262 . V_331 [ 15 ] = V_9 -> V_12 . V_14 -> V_389 ;
if ( V_9 -> V_12 . V_14 -> V_391 > 0 ) {
int V_198 = F_245 ( V_9 ) ;
if ( V_198 != - V_395 )
return V_198 ;
V_9 -> V_248 -> V_394 = V_396 ;
V_9 -> V_248 -> V_397 . V_391 = V_9 -> V_12 . V_14 -> V_391 ;
V_9 -> V_248 -> V_397 . V_398 = V_9 -> V_12 . V_14 -> V_398 ;
V_9 -> V_248 -> V_397 . V_399 = V_9 -> V_12 . V_14 -> V_399 ;
return - V_400 ;
} else if ( V_394 != - V_111 ) {
V_9 -> V_401 . V_402 ++ ;
return 0 ;
} else if ( F_47 ( V_9 -> V_7 ) ) {
V_9 -> V_248 -> V_394 = V_403 ;
V_9 -> V_248 -> V_404 . V_405 =
V_124 -> V_260 . V_386 ;
V_9 -> V_248 -> V_404 . V_406 = 0x10 ;
return - V_400 ;
} else if ( V_124 -> V_260 . V_407 ) {
F_246 ( V_9 ) ;
V_124 -> V_260 . V_407 = 0 ;
if ( F_219 ( V_9 ) )
return 0 ;
return F_208 ( V_9 , V_124 -> V_260 . V_386 , 1 ) ;
}
return F_235 ( V_9 ) ;
}
static int F_247 ( struct V_8 * V_9 )
{
int V_198 , V_394 ;
V_9 -> V_408 = F_44 ( & V_9 -> V_7 -> V_119 ) ;
do {
V_198 = F_224 ( V_9 ) ;
if ( V_198 )
break;
F_46 ( & V_9 -> V_7 -> V_119 , V_9 -> V_408 ) ;
F_248 () ;
F_249 () ;
F_250 () ;
V_394 = F_251 ( V_9 -> V_12 . V_14 ,
V_9 -> V_248 -> V_236 . V_262 . V_331 ) ;
F_248 () ;
F_252 () ;
F_250 () ;
V_9 -> V_408 = F_44 ( & V_9 -> V_7 -> V_119 ) ;
V_198 = F_242 ( V_9 , V_394 ) ;
} while ( ! F_253 ( V_124 ) && ! F_254 ( V_9 ) && ! V_198 );
F_46 ( & V_9 -> V_7 -> V_119 , V_9 -> V_408 ) ;
return V_198 ;
}
static void F_255 ( struct V_8 * V_9 , struct V_409 * V_409 )
{
V_9 -> V_12 . V_14 -> V_268 . V_100 = V_409 -> V_340 ;
V_9 -> V_12 . V_14 -> V_268 . V_110 = V_409 -> V_341 ;
if ( V_409 -> V_410 & V_250 )
F_154 ( V_9 , V_409 -> V_236 . V_262 . V_411 ) ;
if ( V_409 -> V_410 & V_253 ) {
memcpy ( & V_9 -> V_12 . V_14 -> V_272 , & V_409 -> V_236 . V_262 . V_334 , 128 ) ;
F_177 ( V_364 , V_9 ) ;
}
if ( V_409 -> V_410 & V_254 ) {
V_9 -> V_12 . V_14 -> V_269 = V_409 -> V_236 . V_262 . V_269 ;
V_9 -> V_12 . V_14 -> V_270 = V_409 -> V_236 . V_262 . V_270 ;
V_9 -> V_12 . V_14 -> V_271 = V_409 -> V_236 . V_262 . V_271 ;
V_9 -> V_12 . V_14 -> V_274 = V_409 -> V_236 . V_262 . V_274 ;
V_9 -> V_12 . V_14 -> V_273 = V_409 -> V_236 . V_262 . V_273 ;
}
if ( V_409 -> V_410 & V_255 ) {
V_9 -> V_12 . V_246 = V_409 -> V_236 . V_262 . V_412 ;
V_9 -> V_12 . V_327 = V_409 -> V_236 . V_262 . V_413 ;
V_9 -> V_12 . V_325 = V_409 -> V_236 . V_262 . V_414 ;
if ( V_9 -> V_12 . V_246 == V_247 )
F_117 ( V_9 ) ;
}
V_409 -> V_410 = 0 ;
}
static void F_256 ( struct V_8 * V_9 , struct V_409 * V_409 )
{
V_409 -> V_340 = V_9 -> V_12 . V_14 -> V_268 . V_100 ;
V_409 -> V_341 = V_9 -> V_12 . V_14 -> V_268 . V_110 ;
V_409 -> V_236 . V_262 . V_411 = F_178 ( V_9 ) ;
memcpy ( & V_409 -> V_236 . V_262 . V_334 , & V_9 -> V_12 . V_14 -> V_272 , 128 ) ;
V_409 -> V_236 . V_262 . V_269 = V_9 -> V_12 . V_14 -> V_269 ;
V_409 -> V_236 . V_262 . V_270 = V_9 -> V_12 . V_14 -> V_270 ;
V_409 -> V_236 . V_262 . V_271 = V_9 -> V_12 . V_14 -> V_271 ;
V_409 -> V_236 . V_262 . V_274 = V_9 -> V_12 . V_14 -> V_274 ;
V_409 -> V_236 . V_262 . V_273 = V_9 -> V_12 . V_14 -> V_273 ;
V_409 -> V_236 . V_262 . V_412 = V_9 -> V_12 . V_246 ;
V_409 -> V_236 . V_262 . V_413 = V_9 -> V_12 . V_327 ;
V_409 -> V_236 . V_262 . V_414 = V_9 -> V_12 . V_325 ;
}
int F_257 ( struct V_8 * V_9 , struct V_409 * V_409 )
{
int V_198 ;
T_9 V_415 ;
if ( F_254 ( V_9 ) ) {
F_258 ( V_9 ) ;
return 0 ;
}
if ( V_9 -> V_416 )
F_259 ( V_417 , & V_9 -> V_418 , & V_415 ) ;
if ( ! F_155 ( V_9 -> V_7 ) ) {
F_200 ( V_9 ) ;
} else if ( F_193 ( V_9 ) ) {
F_260 ( L_36 ,
V_9 -> V_223 ) ;
return - V_32 ;
}
F_255 ( V_9 , V_409 ) ;
F_261 () ;
V_198 = F_247 ( V_9 ) ;
if ( F_253 ( V_124 ) && ! V_198 ) {
V_409 -> V_394 = V_419 ;
V_198 = - V_420 ;
}
if ( F_254 ( V_9 ) && ! V_198 ) {
F_258 ( V_9 ) ;
V_198 = 0 ;
}
if ( V_198 == - V_400 ) {
V_198 = 0 ;
}
F_256 ( V_9 , V_409 ) ;
if ( V_9 -> V_416 )
F_259 ( V_417 , & V_415 , NULL ) ;
V_9 -> V_401 . V_421 ++ ;
return V_198 ;
}
int F_262 ( struct V_8 * V_9 , unsigned long V_370 )
{
unsigned char V_422 = 1 ;
V_337 V_338 [ V_423 ] ;
unsigned int V_424 ;
V_108 V_425 ;
int V_198 ;
V_424 = F_178 ( V_9 ) ;
if ( V_370 == V_426 ) {
if ( F_263 ( V_9 , 163 , & V_422 , 1 ) )
return - V_111 ;
V_370 = 0 ;
} else if ( V_370 == V_427 ) {
if ( F_264 ( V_9 , 163 , & V_422 , 1 ) )
return - V_111 ;
V_370 = V_424 ;
} else
V_370 -= V_428 ;
if ( V_68 ) {
F_191 ( V_338 , ( V_429 * ) V_9 -> V_248 -> V_236 . V_262 . V_263 ) ;
V_198 = F_263 ( V_9 , V_370 + V_428 ,
V_338 , 128 ) ;
} else {
V_198 = F_263 ( V_9 , V_370 + V_428 ,
V_9 -> V_248 -> V_236 . V_262 . V_263 , 128 ) ;
}
V_198 |= F_263 ( V_9 , V_370 + V_430 ,
V_9 -> V_248 -> V_236 . V_262 . V_331 , 128 ) ;
V_198 |= F_263 ( V_9 , V_370 + V_431 ,
& V_9 -> V_12 . V_14 -> V_268 , 16 ) ;
V_198 |= F_263 ( V_9 , V_370 + V_432 ,
& V_424 , 4 ) ;
V_198 |= F_263 ( V_9 , V_370 + V_433 ,
& V_9 -> V_248 -> V_236 . V_262 . V_259 , 4 ) ;
V_198 |= F_263 ( V_9 , V_370 + V_434 ,
& V_9 -> V_12 . V_14 -> V_271 , 4 ) ;
V_198 |= F_263 ( V_9 , V_370 + V_435 ,
& V_9 -> V_12 . V_14 -> V_269 , 8 ) ;
V_425 = V_9 -> V_12 . V_14 -> V_270 >> 8 ;
V_198 |= F_263 ( V_9 , V_370 + V_436 ,
& V_425 , 8 ) ;
V_198 |= F_263 ( V_9 , V_370 + V_437 ,
& V_9 -> V_248 -> V_236 . V_262 . V_265 , 64 ) ;
V_198 |= F_263 ( V_9 , V_370 + V_438 ,
& V_9 -> V_12 . V_14 -> V_272 , 128 ) ;
return V_198 ? - V_111 : 0 ;
}
int F_265 ( struct V_8 * V_9 , unsigned long V_110 )
{
F_144 () ;
V_9 -> V_248 -> V_236 . V_262 . V_259 = V_124 -> V_260 . V_261 . V_259 ;
F_146 ( V_9 -> V_248 -> V_236 . V_262 . V_265 ) ;
return F_262 ( V_9 , V_110 ) ;
}
int F_266 ( struct V_8 * V_9 ,
unsigned long V_370 )
{
if ( ! ( V_370 & ~ 0x3ff ) )
return 0 ;
return F_263 ( V_9 , V_370 & ~ 0x3ff ,
( void * ) & V_9 -> V_248 -> V_236 . V_262 . V_263 , 512 ) ;
}
int F_267 ( struct V_8 * V_9 , unsigned long V_110 )
{
if ( ! F_52 ( V_9 -> V_7 , 129 ) )
return 0 ;
F_144 () ;
return F_266 ( V_9 , V_110 ) ;
}
static void F_268 ( struct V_8 * V_9 )
{
F_203 ( V_366 , V_9 ) ;
F_176 ( V_367 , V_9 ) ;
}
static void F_269 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
F_268 ( V_9 ) ;
}
}
static void F_270 ( struct V_8 * V_9 )
{
F_203 ( V_367 , V_9 ) ;
F_176 ( V_366 , V_9 ) ;
}
void F_200 ( struct V_8 * V_9 )
{
int V_10 , V_96 , V_439 = 0 ;
if ( ! F_193 ( V_9 ) )
return;
F_271 ( V_9 -> V_223 , 1 ) ;
F_105 ( & V_9 -> V_7 -> V_12 . V_222 ) ;
V_96 = F_39 ( & V_9 -> V_7 -> V_96 ) ;
for ( V_10 = 0 ; V_10 < V_96 ; V_10 ++ ) {
if ( ! F_193 ( V_9 -> V_7 -> V_225 [ V_10 ] ) )
V_439 ++ ;
}
if ( V_439 == 0 ) {
F_270 ( V_9 ) ;
} else if ( V_439 == 1 ) {
F_269 ( V_9 -> V_7 ) ;
}
F_151 ( V_282 , & V_9 -> V_12 . V_14 -> V_267 ) ;
F_177 ( V_364 , V_9 ) ;
F_106 ( & V_9 -> V_7 -> V_12 . V_222 ) ;
return;
}
void F_156 ( struct V_8 * V_9 )
{
int V_10 , V_96 , V_439 = 0 ;
struct V_8 * V_440 = NULL ;
if ( F_193 ( V_9 ) )
return;
F_271 ( V_9 -> V_223 , 0 ) ;
F_105 ( & V_9 -> V_7 -> V_12 . V_222 ) ;
V_96 = F_39 ( & V_9 -> V_7 -> V_96 ) ;
F_272 ( V_9 ) ;
F_149 ( V_282 , & V_9 -> V_12 . V_14 -> V_267 ) ;
F_268 ( V_9 ) ;
for ( V_10 = 0 ; V_10 < V_96 ; V_10 ++ ) {
if ( ! F_193 ( V_9 -> V_7 -> V_225 [ V_10 ] ) ) {
V_439 ++ ;
V_440 = V_9 -> V_7 -> V_225 [ V_10 ] ;
}
}
if ( V_439 == 1 ) {
F_270 ( V_440 ) ;
}
F_106 ( & V_9 -> V_7 -> V_12 . V_222 ) ;
return;
}
static int F_273 ( struct V_8 * V_9 ,
struct V_90 * V_91 )
{
int V_34 ;
if ( V_91 -> V_92 )
return - V_32 ;
switch ( V_91 -> V_91 ) {
case V_43 :
if ( ! V_9 -> V_7 -> V_12 . V_221 ) {
V_9 -> V_7 -> V_12 . V_221 = 1 ;
F_38 ( V_9 -> V_7 , 3 , L_2 , L_37 ) ;
F_274 ( V_9 -> V_7 ) ;
}
V_34 = 0 ;
break;
default:
V_34 = - V_32 ;
break;
}
return V_34 ;
}
static long F_275 ( struct V_8 * V_9 ,
struct V_441 * V_442 )
{
void V_109 * V_443 = ( void V_109 * ) V_442 -> V_444 ;
void * V_445 = NULL ;
int V_34 , V_408 ;
const V_108 V_446 = V_447
| V_448 ;
if ( V_442 -> V_92 & ~ V_446 )
return - V_32 ;
if ( V_442 -> V_449 > V_56 )
return - V_122 ;
if ( ! ( V_442 -> V_92 & V_448 ) ) {
V_445 = F_80 ( V_442 -> V_449 ) ;
if ( ! V_445 )
return - V_23 ;
}
V_408 = F_44 ( & V_9 -> V_7 -> V_119 ) ;
switch ( V_442 -> V_450 ) {
case V_451 :
if ( V_442 -> V_92 & V_448 ) {
V_34 = F_276 ( V_9 , V_442 -> V_452 , V_442 -> V_453 , V_442 -> V_449 , false ) ;
break;
}
V_34 = F_237 ( V_9 , V_442 -> V_452 , V_442 -> V_453 , V_445 , V_442 -> V_449 ) ;
if ( V_34 == 0 ) {
if ( F_62 ( V_443 , V_445 , V_442 -> V_449 ) )
V_34 = - V_111 ;
}
break;
case V_454 :
if ( V_442 -> V_92 & V_448 ) {
V_34 = F_276 ( V_9 , V_442 -> V_452 , V_442 -> V_453 , V_442 -> V_449 , true ) ;
break;
}
if ( F_57 ( V_445 , V_443 , V_442 -> V_449 ) ) {
V_34 = - V_111 ;
break;
}
V_34 = F_277 ( V_9 , V_442 -> V_452 , V_442 -> V_453 , V_445 , V_442 -> V_449 ) ;
break;
default:
V_34 = - V_32 ;
}
F_46 ( & V_9 -> V_7 -> V_119 , V_408 ) ;
if ( V_34 > 0 && ( V_442 -> V_92 & V_447 ) != 0 )
F_278 ( V_9 , & V_9 -> V_12 . V_455 ) ;
F_279 ( V_445 ) ;
return V_34 ;
}
long F_280 ( struct V_27 * V_28 ,
unsigned int V_29 , unsigned long V_30 )
{
struct V_8 * V_9 = V_28 -> V_171 ;
void V_109 * V_172 = ( void V_109 * ) V_30 ;
int V_113 ;
long V_34 ;
switch ( V_29 ) {
case V_456 : {
struct V_376 V_457 ;
V_34 = - V_111 ;
if ( F_57 ( & V_457 , V_172 , sizeof( V_457 ) ) )
break;
V_34 = F_212 ( V_9 , & V_457 ) ;
break;
}
case V_173 : {
struct V_174 V_175 ;
struct V_376 V_457 ;
V_34 = - V_111 ;
if ( F_57 ( & V_175 , V_172 , sizeof( V_175 ) ) )
break;
if ( F_281 ( & V_175 , & V_457 ) )
return - V_32 ;
V_34 = F_212 ( V_9 , & V_457 ) ;
break;
}
case V_458 :
V_113 = F_44 ( & V_9 -> V_7 -> V_119 ) ;
V_34 = F_265 ( V_9 , V_30 ) ;
F_46 ( & V_9 -> V_7 -> V_119 , V_113 ) ;
break;
case V_459 : {
T_6 V_339 ;
V_34 = - V_111 ;
if ( F_57 ( & V_339 , V_172 , sizeof( V_339 ) ) )
break;
V_34 = F_192 ( V_9 , V_339 ) ;
break;
}
case V_460 :
V_34 = F_183 ( V_9 ) ;
break;
case V_461 :
case V_462 : {
struct V_317 V_318 ;
V_34 = - V_111 ;
if ( F_57 ( & V_318 , V_172 , sizeof( V_318 ) ) )
break;
if ( V_29 == V_461 )
V_34 = F_182 ( V_9 , & V_318 ) ;
else
V_34 = F_181 ( V_9 , & V_318 ) ;
break;
}
#ifdef F_23
case V_463 : {
struct V_464 V_465 ;
if ( F_57 ( & V_465 , V_172 , sizeof( V_465 ) ) ) {
V_34 = - V_111 ;
break;
}
if ( ! F_47 ( V_9 -> V_7 ) ) {
V_34 = - V_32 ;
break;
}
V_34 = F_282 ( V_9 -> V_12 . V_75 , V_465 . V_466 ,
V_465 . V_467 , V_465 . V_468 ) ;
break;
}
case V_469 : {
struct V_464 V_465 ;
if ( F_57 ( & V_465 , V_172 , sizeof( V_465 ) ) ) {
V_34 = - V_111 ;
break;
}
if ( ! F_47 ( V_9 -> V_7 ) ) {
V_34 = - V_32 ;
break;
}
V_34 = F_283 ( V_9 -> V_12 . V_75 , V_465 . V_467 ,
V_465 . V_468 ) ;
break;
}
#endif
case V_470 : {
V_34 = F_209 ( V_9 -> V_12 . V_75 , V_30 , 0 ) ;
break;
}
case V_176 :
{
struct V_90 V_91 ;
V_34 = - V_111 ;
if ( F_57 ( & V_91 , V_172 , sizeof( V_91 ) ) )
break;
V_34 = F_273 ( V_9 , & V_91 ) ;
break;
}
case V_471 : {
struct V_441 V_472 ;
if ( F_57 ( & V_472 , V_172 , sizeof( V_472 ) ) == 0 )
V_34 = F_275 ( V_9 , & V_472 ) ;
else
V_34 = - V_111 ;
break;
}
case V_473 : {
struct V_474 V_475 ;
V_34 = - V_111 ;
if ( F_57 ( & V_475 , V_172 , sizeof( V_475 ) ) )
break;
if ( V_475 . V_476 > V_477 ||
V_475 . V_476 == 0 ||
V_475 . V_476 % sizeof( struct V_376 ) > 0 ) {
V_34 = - V_32 ;
break;
}
V_34 = F_284 ( V_9 ,
( void V_109 * ) V_475 . V_444 ,
V_475 . V_476 ) ;
break;
}
case V_478 : {
struct V_474 V_475 ;
V_34 = - V_111 ;
if ( F_57 ( & V_475 , V_172 , sizeof( V_475 ) ) )
break;
if ( V_475 . V_476 == 0 ) {
V_34 = - V_32 ;
break;
}
V_34 = F_285 ( V_9 ,
( V_479 V_109 * ) V_475 . V_444 ,
V_475 . V_476 ) ;
break;
}
default:
V_34 = - V_185 ;
}
return V_34 ;
}
int F_286 ( struct V_8 * V_9 , struct V_480 * V_481 )
{
#ifdef F_23
if ( ( V_481 -> V_482 == V_483 )
&& ( F_47 ( V_9 -> V_7 ) ) ) {
V_481 -> V_484 = F_287 ( V_9 -> V_12 . V_14 ) ;
F_288 ( V_481 -> V_484 ) ;
return 0 ;
}
#endif
return V_485 ;
}
int F_289 ( struct V_7 * V_7 , struct V_70 * V_86 ,
unsigned long V_79 )
{
return 0 ;
}
int F_290 ( struct V_7 * V_7 ,
struct V_70 * V_71 ,
const struct V_486 * V_487 ,
enum V_488 V_489 )
{
if ( V_487 -> V_490 & 0xffffful )
return - V_32 ;
if ( V_487 -> V_491 & 0xffffful )
return - V_32 ;
if ( V_487 -> V_492 + V_487 -> V_491 > V_7 -> V_12 . V_107 )
return - V_32 ;
return 0 ;
}
void F_291 ( struct V_7 * V_7 ,
const struct V_486 * V_487 ,
const struct V_70 * V_493 ,
const struct V_70 * V_123 ,
enum V_488 V_489 )
{
int V_198 ;
if ( V_493 -> V_490 == V_487 -> V_490 &&
V_493 -> V_78 * V_207 == V_487 -> V_492 &&
V_493 -> V_79 * V_207 == V_487 -> V_491 )
return;
V_198 = F_282 ( V_7 -> V_12 . V_75 , V_487 -> V_490 ,
V_487 -> V_492 , V_487 -> V_491 ) ;
if ( V_198 )
F_292 ( L_38 ) ;
return;
}
static int T_10 F_293 ( void )
{
if ( ! V_59 . V_494 ) {
F_294 ( L_39 ) ;
return - V_495 ;
}
return F_295 ( NULL , sizeof( struct V_8 ) , 0 , V_496 ) ;
}
static void T_11 F_296 ( void )
{
F_297 () ;
}
