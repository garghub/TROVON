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
F_31 ( & V_7 -> V_91 ) ;
if ( F_38 ( & V_7 -> V_92 ) ) {
V_34 = - V_93 ;
} else if ( V_65 ) {
F_39 ( V_7 -> V_12 . V_94 . V_95 -> V_96 , 129 ) ;
F_39 ( V_7 -> V_12 . V_94 . V_95 -> V_97 , 129 ) ;
V_34 = 0 ;
} else
V_34 = - V_32 ;
F_35 ( & V_7 -> V_91 ) ;
F_37 ( V_7 , 3 , L_5 ,
V_34 ? L_6 : L_7 ) ;
break;
case V_52 :
F_37 ( V_7 , 3 , L_2 , L_8 ) ;
V_7 -> V_12 . V_98 = 1 ;
V_34 = 0 ;
break;
default:
V_34 = - V_32 ;
break;
}
return V_34 ;
}
static int F_40 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
int V_101 ;
switch ( V_100 -> V_100 ) {
case V_102 :
V_101 = 0 ;
F_37 ( V_7 , 3 , L_9 ,
V_7 -> V_12 . V_71 -> V_103 ) ;
if ( F_41 ( V_7 -> V_12 . V_71 -> V_103 , ( V_104 V_105 * ) V_100 -> V_106 ) )
V_101 = - V_107 ;
break;
default:
V_101 = - V_108 ;
break;
}
return V_101 ;
}
static int F_42 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
int V_101 ;
unsigned int V_109 ;
switch ( V_100 -> V_100 ) {
case V_110 :
V_101 = - V_32 ;
if ( ! V_111 || ! V_112 )
break;
V_101 = - V_93 ;
F_37 ( V_7 , 3 , L_2 , L_10 ) ;
F_31 ( & V_7 -> V_91 ) ;
if ( F_38 ( & V_7 -> V_92 ) == 0 ) {
V_7 -> V_12 . V_113 = 1 ;
V_101 = 0 ;
}
F_35 ( & V_7 -> V_91 ) ;
break;
case V_114 :
V_101 = - V_32 ;
if ( ! V_7 -> V_12 . V_113 )
break;
F_37 ( V_7 , 3 , L_2 , L_11 ) ;
F_31 ( & V_7 -> V_91 ) ;
V_109 = F_43 ( & V_7 -> V_115 ) ;
F_44 ( V_7 -> V_12 . V_71 -> V_72 ) ;
F_45 ( & V_7 -> V_115 , V_109 ) ;
F_35 ( & V_7 -> V_91 ) ;
V_101 = 0 ;
break;
case V_102 : {
unsigned long V_116 ;
if ( F_46 ( V_7 ) )
return - V_32 ;
if ( F_47 ( V_116 , ( V_104 V_105 * ) V_100 -> V_106 ) )
return - V_107 ;
if ( V_116 > V_7 -> V_12 . V_71 -> V_103 )
return - V_117 ;
V_101 = - V_93 ;
F_31 ( & V_7 -> V_91 ) ;
if ( F_38 ( & V_7 -> V_92 ) == 0 ) {
struct V_71 * V_118 = F_48 ( V_119 -> V_72 , V_116 ) ;
if ( ! V_118 ) {
V_101 = - V_23 ;
} else {
F_49 ( V_7 -> V_12 . V_71 ) ;
V_118 -> V_120 = V_7 ;
V_7 -> V_12 . V_71 = V_118 ;
V_101 = 0 ;
}
}
F_35 ( & V_7 -> V_91 ) ;
F_37 ( V_7 , 3 , L_12 , V_116 ) ;
break;
}
default:
V_101 = - V_108 ;
break;
}
return V_101 ;
}
static int F_50 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
struct V_8 * V_9 ;
int V_10 ;
if ( ! F_51 ( V_7 , 76 ) )
return - V_32 ;
F_31 ( & V_7 -> V_91 ) ;
switch ( V_100 -> V_100 ) {
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
F_35 ( & V_7 -> V_91 ) ;
return - V_108 ;
}
F_7 (i, vcpu, kvm) {
F_53 ( V_9 ) ;
F_54 ( V_9 ) ;
}
F_35 ( & V_7 -> V_91 ) ;
return 0 ;
}
static int F_55 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
T_2 V_131 ;
if ( F_56 ( & V_131 , ( void V_105 * ) V_100 -> V_106 ,
sizeof( V_131 ) ) )
return - V_107 ;
if ( V_131 != 0 )
return - V_32 ;
F_37 ( V_7 , 3 , L_17 , V_131 ) ;
return 0 ;
}
static int F_57 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
V_104 V_132 ;
if ( F_56 ( & V_132 , ( void V_105 * ) V_100 -> V_106 , sizeof( V_132 ) ) )
return - V_107 ;
F_58 ( V_7 , V_132 ) ;
F_37 ( V_7 , 3 , L_18 , V_132 ) ;
return 0 ;
}
static int F_59 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
int V_101 ;
if ( V_100 -> V_88 )
return - V_32 ;
switch ( V_100 -> V_100 ) {
case V_133 :
V_101 = F_55 ( V_7 , V_100 ) ;
break;
case V_134 :
V_101 = F_57 ( V_7 , V_100 ) ;
break;
default:
V_101 = - V_108 ;
break;
}
return V_101 ;
}
static int F_60 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
T_2 V_131 = 0 ;
if ( F_61 ( ( void V_105 * ) V_100 -> V_106 , & V_131 ,
sizeof( V_131 ) ) )
return - V_107 ;
F_37 ( V_7 , 3 , L_19 , V_131 ) ;
return 0 ;
}
static int F_62 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
V_104 V_132 ;
V_132 = F_63 ( V_7 ) ;
if ( F_61 ( ( void V_105 * ) V_100 -> V_106 , & V_132 , sizeof( V_132 ) ) )
return - V_107 ;
F_37 ( V_7 , 3 , L_20 , V_132 ) ;
return 0 ;
}
static int F_64 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
int V_101 ;
if ( V_100 -> V_88 )
return - V_32 ;
switch ( V_100 -> V_100 ) {
case V_133 :
V_101 = F_60 ( V_7 , V_100 ) ;
break;
case V_134 :
V_101 = F_62 ( V_7 , V_100 ) ;
break;
default:
V_101 = - V_108 ;
break;
}
return V_101 ;
}
static int F_65 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
struct V_135 * V_136 ;
int V_101 = 0 ;
F_31 ( & V_7 -> V_91 ) ;
if ( F_38 ( & V_7 -> V_92 ) ) {
V_101 = - V_93 ;
goto V_83;
}
V_136 = F_66 ( sizeof( * V_136 ) , V_137 ) ;
if ( ! V_136 ) {
V_101 = - V_23 ;
goto V_83;
}
if ( ! F_56 ( V_136 , ( void V_105 * ) V_100 -> V_106 ,
sizeof( * V_136 ) ) ) {
memcpy ( & V_7 -> V_12 . V_94 . V_138 , & V_136 -> V_139 ,
sizeof( struct V_139 ) ) ;
V_7 -> V_12 . V_94 . V_140 = V_136 -> V_140 ;
memcpy ( V_7 -> V_12 . V_94 . V_95 -> V_97 , V_136 -> V_141 ,
V_142 ) ;
} else
V_101 = - V_107 ;
F_67 ( V_136 ) ;
V_83:
F_35 ( & V_7 -> V_91 ) ;
return V_101 ;
}
static int F_68 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
int V_101 = - V_108 ;
switch ( V_100 -> V_100 ) {
case V_143 :
V_101 = F_65 ( V_7 , V_100 ) ;
break;
}
return V_101 ;
}
static int F_69 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
struct V_135 * V_136 ;
int V_101 = 0 ;
V_136 = F_66 ( sizeof( * V_136 ) , V_137 ) ;
if ( ! V_136 ) {
V_101 = - V_23 ;
goto V_83;
}
memcpy ( & V_136 -> V_139 , & V_7 -> V_12 . V_94 . V_138 , sizeof( struct V_139 ) ) ;
V_136 -> V_140 = V_7 -> V_12 . V_94 . V_140 ;
memcpy ( & V_136 -> V_141 , V_7 -> V_12 . V_94 . V_95 -> V_97 , V_142 ) ;
if ( F_61 ( ( void V_105 * ) V_100 -> V_106 , V_136 , sizeof( * V_136 ) ) )
V_101 = - V_107 ;
F_67 ( V_136 ) ;
V_83:
return V_101 ;
}
static int F_70 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
struct V_144 * V_145 ;
int V_101 = 0 ;
V_145 = F_66 ( sizeof( * V_145 ) , V_137 ) ;
if ( ! V_145 ) {
V_101 = - V_23 ;
goto V_83;
}
F_71 ( (struct V_139 * ) & V_145 -> V_139 ) ;
V_145 -> V_140 = V_146 . V_140 ;
memcpy ( & V_145 -> V_147 , V_7 -> V_12 . V_94 . V_95 -> V_96 ,
V_142 ) ;
memcpy ( ( unsigned long * ) & V_145 -> V_141 , V_148 . V_149 ,
V_142 ) ;
if ( F_61 ( ( void V_105 * ) V_100 -> V_106 , V_145 , sizeof( * V_145 ) ) )
V_101 = - V_107 ;
F_67 ( V_145 ) ;
V_83:
return V_101 ;
}
static int F_72 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
int V_101 = - V_108 ;
switch ( V_100 -> V_100 ) {
case V_143 :
V_101 = F_69 ( V_7 , V_100 ) ;
break;
case V_150 :
V_101 = F_70 ( V_7 , V_100 ) ;
break;
}
return V_101 ;
}
static int F_73 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
int V_101 ;
switch ( V_100 -> V_151 ) {
case V_152 :
V_101 = F_42 ( V_7 , V_100 ) ;
break;
case V_153 :
V_101 = F_59 ( V_7 , V_100 ) ;
break;
case V_154 :
V_101 = F_68 ( V_7 , V_100 ) ;
break;
case V_155 :
V_101 = F_50 ( V_7 , V_100 ) ;
break;
default:
V_101 = - V_108 ;
break;
}
return V_101 ;
}
static int F_74 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
int V_101 ;
switch ( V_100 -> V_151 ) {
case V_152 :
V_101 = F_40 ( V_7 , V_100 ) ;
break;
case V_153 :
V_101 = F_64 ( V_7 , V_100 ) ;
break;
case V_154 :
V_101 = F_72 ( V_7 , V_100 ) ;
break;
default:
V_101 = - V_108 ;
break;
}
return V_101 ;
}
static int F_75 ( struct V_7 * V_7 , struct V_99 * V_100 )
{
int V_101 ;
switch ( V_100 -> V_151 ) {
case V_152 :
switch ( V_100 -> V_100 ) {
case V_110 :
case V_114 :
case V_102 :
V_101 = 0 ;
break;
default:
V_101 = - V_108 ;
break;
}
break;
case V_153 :
switch ( V_100 -> V_100 ) {
case V_134 :
case V_133 :
V_101 = 0 ;
break;
default:
V_101 = - V_108 ;
break;
}
break;
case V_154 :
switch ( V_100 -> V_100 ) {
case V_143 :
case V_150 :
V_101 = 0 ;
break;
default:
V_101 = - V_108 ;
break;
}
break;
case V_155 :
switch ( V_100 -> V_100 ) {
case V_121 :
case V_126 :
case V_129 :
case V_130 :
V_101 = 0 ;
break;
default:
V_101 = - V_108 ;
break;
}
break;
default:
V_101 = - V_108 ;
break;
}
return V_101 ;
}
static long F_76 ( struct V_7 * V_7 , struct V_156 * args )
{
T_3 * V_157 ;
T_4 V_158 ;
unsigned long V_159 ;
int V_10 , V_34 = 0 ;
if ( args -> V_88 != 0 )
return - V_32 ;
if ( ! F_77 ( V_119 -> V_72 ) )
return V_160 ;
if ( args -> V_161 < 1 || args -> V_161 > V_162 )
return - V_32 ;
V_157 = F_78 ( args -> V_161 , sizeof( T_3 ) ,
V_137 | V_163 ) ;
if ( ! V_157 )
V_157 = F_79 ( sizeof( T_3 ) * args -> V_161 ) ;
if ( ! V_157 )
return - V_23 ;
for ( V_10 = 0 ; V_10 < args -> V_161 ; V_10 ++ ) {
V_158 = F_80 ( V_7 , args -> V_164 + V_10 ) ;
if ( F_81 ( V_158 ) ) {
V_34 = - V_107 ;
goto V_83;
}
V_159 = F_82 ( V_119 -> V_72 , V_158 ) ;
if ( F_83 ( V_159 ) ) {
V_34 = V_159 ;
goto V_83;
}
V_157 [ V_10 ] = V_159 ;
}
V_34 = F_61 ( ( T_3 V_105 * ) args -> V_165 , V_157 ,
sizeof( T_3 ) * args -> V_161 ) ;
if ( V_34 )
V_34 = - V_107 ;
V_83:
F_84 ( V_157 ) ;
return V_34 ;
}
static long F_85 ( struct V_7 * V_7 , struct V_156 * args )
{
T_3 * V_157 ;
T_4 V_158 ;
int V_10 , V_34 = 0 ;
if ( args -> V_88 != 0 )
return - V_32 ;
if ( args -> V_161 < 1 || args -> V_161 > V_162 )
return - V_32 ;
V_157 = F_78 ( args -> V_161 , sizeof( T_3 ) ,
V_137 | V_163 ) ;
if ( ! V_157 )
V_157 = F_79 ( sizeof( T_3 ) * args -> V_161 ) ;
if ( ! V_157 )
return - V_23 ;
V_34 = F_56 ( V_157 , ( T_3 V_105 * ) args -> V_165 ,
sizeof( T_3 ) * args -> V_161 ) ;
if ( V_34 ) {
V_34 = - V_107 ;
goto V_83;
}
V_34 = F_86 () ;
if ( V_34 )
goto V_83;
for ( V_10 = 0 ; V_10 < args -> V_161 ; V_10 ++ ) {
V_158 = F_80 ( V_7 , args -> V_164 + V_10 ) ;
if ( F_81 ( V_158 ) ) {
V_34 = - V_107 ;
goto V_83;
}
if ( V_157 [ V_10 ] & 0x01 ) {
V_34 = - V_32 ;
goto V_83;
}
V_34 = F_87 ( V_119 -> V_72 , V_158 ,
( unsigned long ) V_157 [ V_10 ] , 0 ) ;
if ( V_34 )
goto V_83;
}
V_83:
F_84 ( V_157 ) ;
return V_34 ;
}
long F_88 ( struct V_27 * V_28 ,
unsigned int V_29 , unsigned long V_30 )
{
struct V_7 * V_7 = V_28 -> V_166 ;
void V_105 * V_167 = ( void V_105 * ) V_30 ;
struct V_99 V_100 ;
int V_34 ;
switch ( V_29 ) {
case V_168 : {
struct V_169 V_170 ;
V_34 = - V_107 ;
if ( F_56 ( & V_170 , V_167 , sizeof( V_170 ) ) )
break;
V_34 = F_89 ( V_7 , & V_170 ) ;
break;
}
case V_171 : {
struct V_86 V_87 ;
V_34 = - V_107 ;
if ( F_56 ( & V_87 , V_167 , sizeof( V_87 ) ) )
break;
V_34 = F_36 ( V_7 , & V_87 ) ;
break;
}
case V_172 : {
struct V_173 V_174 ;
V_34 = - V_32 ;
if ( V_7 -> V_12 . V_89 ) {
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
V_34 = F_90 ( V_7 , & V_174 , 0 , 0 ) ;
}
break;
}
case V_175 : {
V_34 = - V_107 ;
if ( F_56 ( & V_100 , ( void V_105 * ) V_30 , sizeof( V_100 ) ) )
break;
V_34 = F_73 ( V_7 , & V_100 ) ;
break;
}
case V_176 : {
V_34 = - V_107 ;
if ( F_56 ( & V_100 , ( void V_105 * ) V_30 , sizeof( V_100 ) ) )
break;
V_34 = F_74 ( V_7 , & V_100 ) ;
break;
}
case V_177 : {
V_34 = - V_107 ;
if ( F_56 ( & V_100 , ( void V_105 * ) V_30 , sizeof( V_100 ) ) )
break;
V_34 = F_75 ( V_7 , & V_100 ) ;
break;
}
case V_178 : {
struct V_156 args ;
V_34 = - V_107 ;
if ( F_56 ( & args , V_167 ,
sizeof( struct V_156 ) ) )
break;
V_34 = F_76 ( V_7 , & args ) ;
break;
}
case V_179 : {
struct V_156 args ;
V_34 = - V_107 ;
if ( F_56 ( & args , V_167 ,
sizeof( struct V_156 ) ) )
break;
V_34 = F_85 ( V_7 , & args ) ;
break;
}
default:
V_34 = - V_180 ;
}
return V_34 ;
}
static int F_91 ( T_2 * V_181 )
{
T_5 V_182 = 0x04000000UL ;
T_5 V_183 = 0 ;
memset ( V_181 , 0 , 128 ) ;
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
return V_183 ;
}
static int F_92 ( void )
{
T_2 V_181 [ 128 ] ;
int V_183 ;
if ( F_93 ( 2 ) && F_93 ( 12 ) ) {
V_183 = F_91 ( V_181 ) ;
if ( V_183 )
F_94 ( L_21 , V_183 ) ;
else
return V_181 [ 0 ] & 0x40 ;
}
return 0 ;
}
static void F_95 ( struct V_7 * V_7 )
{
V_7 -> V_12 . V_122 . V_184 = ( V_185 ) ( unsigned long ) V_7 -> V_12 . V_122 . V_123 ;
if ( F_92 () )
V_7 -> V_12 . V_122 . V_184 |= V_186 ;
else
V_7 -> V_12 . V_122 . V_184 |= V_187 ;
}
static void F_96 ( struct V_139 * V_138 )
{
F_71 ( V_138 ) ;
V_138 -> V_188 = 0xff ;
}
static int F_97 ( struct V_7 * V_7 )
{
if ( ! F_51 ( V_7 , 76 ) )
return 0 ;
V_7 -> V_12 . V_122 . V_123 = F_66 ( sizeof( * V_7 -> V_12 . V_122 . V_123 ) ,
V_137 | V_189 ) ;
if ( ! V_7 -> V_12 . V_122 . V_123 )
return - V_23 ;
F_95 ( V_7 ) ;
V_7 -> V_12 . V_122 . V_125 = 1 ;
V_7 -> V_12 . V_122 . V_128 = 1 ;
F_52 ( V_7 -> V_12 . V_122 . V_123 -> V_124 ,
sizeof( V_7 -> V_12 . V_122 . V_123 -> V_124 ) ) ;
F_52 ( V_7 -> V_12 . V_122 . V_123 -> V_127 ,
sizeof( V_7 -> V_12 . V_122 . V_123 -> V_127 ) ) ;
return 0 ;
}
int F_98 ( struct V_7 * V_7 , unsigned long type )
{
int V_10 , V_190 ;
char V_191 [ 16 ] ;
static unsigned long V_192 ;
V_190 = - V_32 ;
#ifdef F_23
if ( type & ~ V_193 )
goto V_194;
if ( ( type & V_193 ) && ( ! F_99 ( V_195 ) ) )
goto V_194;
#else
if ( type )
goto V_194;
#endif
V_190 = F_21 () ;
if ( V_190 )
goto V_194;
V_190 = - V_23 ;
V_7 -> V_12 . V_196 = (struct V_197 * ) F_100 ( V_137 ) ;
if ( ! V_7 -> V_12 . V_196 )
goto V_194;
F_101 ( & V_198 ) ;
V_192 += 16 ;
if ( V_192 + sizeof( struct V_197 ) > V_199 )
V_192 = 0 ;
V_7 -> V_12 . V_196 = (struct V_197 * ) ( ( char * ) V_7 -> V_12 . V_196 + V_192 ) ;
F_102 ( & V_198 ) ;
sprintf ( V_191 , L_22 , V_119 -> V_200 ) ;
V_7 -> V_12 . V_201 = F_15 ( V_191 , 32 , 1 , 7 * sizeof( long ) ) ;
if ( ! V_7 -> V_12 . V_201 )
goto V_194;
V_7 -> V_12 . V_94 . V_95 =
(struct V_202 * ) F_100 ( V_137 | V_189 ) ;
if ( ! V_7 -> V_12 . V_94 . V_95 )
goto V_194;
memcpy ( V_7 -> V_12 . V_94 . V_95 -> V_96 , V_148 . V_149 ,
V_142 ) ;
for ( V_10 = 0 ; V_10 < V_203 ; V_10 ++ ) {
if ( V_10 < F_1 () )
V_7 -> V_12 . V_94 . V_95 -> V_96 [ V_10 ] &= V_1 [ V_10 ] ;
else
V_7 -> V_12 . V_94 . V_95 -> V_96 [ V_10 ] = 0UL ;
}
memcpy ( V_7 -> V_12 . V_94 . V_95 -> V_97 , V_7 -> V_12 . V_94 . V_95 -> V_96 ,
V_142 ) ;
F_96 ( & V_7 -> V_12 . V_94 . V_138 ) ;
V_7 -> V_12 . V_94 . V_140 = V_146 . V_140 & 0x0fff ;
if ( F_97 ( V_7 ) < 0 )
goto V_194;
F_103 ( & V_7 -> V_12 . V_204 . V_91 ) ;
for ( V_10 = 0 ; V_10 < V_205 ; V_10 ++ )
F_104 ( & V_7 -> V_12 . V_204 . V_206 [ V_10 ] ) ;
F_105 ( & V_7 -> V_12 . V_207 ) ;
F_106 ( & V_7 -> V_12 . V_208 ) ;
F_16 ( V_7 -> V_12 . V_201 , & V_24 ) ;
F_37 ( V_7 , 3 , L_23 , type ) ;
if ( type & V_193 ) {
V_7 -> V_12 . V_71 = NULL ;
} else {
V_7 -> V_12 . V_71 = F_48 ( V_119 -> V_72 , ( 1UL << 44 ) - 1 ) ;
if ( ! V_7 -> V_12 . V_71 )
goto V_194;
V_7 -> V_12 . V_71 -> V_120 = V_7 ;
V_7 -> V_12 . V_71 -> V_209 = 0 ;
}
V_7 -> V_12 . V_210 = 0 ;
V_7 -> V_12 . V_89 = 0 ;
V_7 -> V_12 . V_13 = 0 ;
F_103 ( & V_7 -> V_12 . V_211 ) ;
F_107 ( 3 , L_24 , V_7 , V_119 -> V_200 ) ;
return 0 ;
V_194:
F_67 ( V_7 -> V_12 . V_122 . V_123 ) ;
F_108 ( ( unsigned long ) V_7 -> V_12 . V_94 . V_95 ) ;
F_17 ( V_7 -> V_12 . V_201 ) ;
F_108 ( ( unsigned long ) ( V_7 -> V_12 . V_196 ) ) ;
F_107 ( 3 , L_25 , V_190 ) ;
return V_190 ;
}
void F_109 ( struct V_8 * V_9 )
{
F_110 ( V_9 , 3 , L_2 , L_26 ) ;
F_111 ( V_9 -> V_212 ) ;
F_112 ( V_9 ) ;
F_113 ( V_9 ) ;
if ( ! F_46 ( V_9 -> V_7 ) ) {
F_114 ( 63 - V_9 -> V_212 ,
( unsigned long * ) & V_9 -> V_7 -> V_12 . V_196 -> V_213 ) ;
if ( V_9 -> V_7 -> V_12 . V_196 -> V_214 [ V_9 -> V_212 ] . V_215 ==
( V_216 ) V_9 -> V_12 . V_14 )
V_9 -> V_7 -> V_12 . V_196 -> V_214 [ V_9 -> V_212 ] . V_215 = 0 ;
}
F_115 () ;
if ( F_46 ( V_9 -> V_7 ) )
F_49 ( V_9 -> V_12 . V_71 ) ;
if ( V_9 -> V_7 -> V_12 . V_113 )
F_116 ( V_9 ) ;
F_108 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
F_117 ( V_9 ) ;
F_118 ( V_217 , V_9 ) ;
}
static void F_119 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm)
F_109 ( V_9 ) ;
F_31 ( & V_7 -> V_91 ) ;
for ( V_10 = 0 ; V_10 < F_38 ( & V_7 -> V_92 ) ; V_10 ++ )
V_7 -> V_218 [ V_10 ] = NULL ;
F_120 ( & V_7 -> V_92 , 0 ) ;
F_35 ( & V_7 -> V_91 ) ;
}
void F_121 ( struct V_7 * V_7 )
{
F_119 ( V_7 ) ;
F_108 ( ( unsigned long ) V_7 -> V_12 . V_94 . V_95 ) ;
F_108 ( ( unsigned long ) ( V_7 -> V_12 . V_196 ) ) ;
F_17 ( V_7 -> V_12 . V_201 ) ;
F_67 ( V_7 -> V_12 . V_122 . V_123 ) ;
if ( ! F_46 ( V_7 ) )
F_49 ( V_7 -> V_12 . V_71 ) ;
F_122 ( V_7 ) ;
F_123 ( V_7 ) ;
F_107 ( 3 , L_27 , V_7 ) ;
}
static int F_124 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_71 = F_48 ( V_119 -> V_72 , - 1UL ) ;
if ( ! V_9 -> V_12 . V_71 )
return - V_23 ;
V_9 -> V_12 . V_71 -> V_120 = V_9 -> V_7 ;
return 0 ;
}
int F_125 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_219 = V_220 ;
F_113 ( V_9 ) ;
V_9 -> V_221 -> V_222 = V_223 |
V_224 |
V_225 |
V_226 |
V_227 |
V_228 ;
if ( F_51 ( V_9 -> V_7 , 129 ) )
V_9 -> V_221 -> V_222 |= V_229 ;
if ( F_46 ( V_9 -> V_7 ) )
return F_124 ( V_9 ) ;
return 0 ;
}
static inline void F_126 ( struct V_230 * V_231 )
{
V_231 -> V_232 = V_119 -> V_233 . V_230 . V_232 ;
V_231 -> V_234 = V_119 -> V_233 . V_230 . V_234 ;
}
static inline void F_127 ( struct V_230 * V_235 )
{
V_119 -> V_233 . V_230 . V_232 = V_235 -> V_232 ;
V_119 -> V_233 . V_230 . V_234 = V_235 -> V_234 ;
}
void F_128 ( struct V_8 * V_9 , int V_214 )
{
F_129 () ;
F_126 ( & V_9 -> V_12 . V_236 ) ;
if ( F_51 ( V_9 -> V_7 , 129 ) ) {
V_119 -> V_233 . V_230 . V_232 = V_9 -> V_221 -> V_237 . V_234 . V_232 ;
V_119 -> V_233 . V_230 . V_238 =
( V_239 * ) & V_9 -> V_221 -> V_237 . V_234 . V_240 ;
} else
F_127 ( & V_9 -> V_12 . V_241 ) ;
if ( F_130 ( V_119 -> V_233 . V_230 . V_232 ) )
V_119 -> V_233 . V_230 . V_232 = 0 ;
F_131 ( V_9 -> V_12 . V_242 ) ;
F_132 ( V_9 -> V_221 -> V_237 . V_234 . V_243 ) ;
F_133 ( V_9 -> V_12 . V_71 ) ;
F_134 ( V_244 , & V_9 -> V_12 . V_14 -> V_245 ) ;
}
void F_135 ( struct V_8 * V_9 )
{
F_136 ( V_244 , & V_9 -> V_12 . V_14 -> V_245 ) ;
F_137 ( V_9 -> V_12 . V_71 ) ;
F_129 () ;
if ( F_51 ( V_9 -> V_7 , 129 ) )
V_9 -> V_221 -> V_237 . V_234 . V_232 = V_119 -> V_233 . V_230 . V_232 ;
else
F_126 ( & V_9 -> V_12 . V_241 ) ;
F_127 ( & V_9 -> V_12 . V_236 ) ;
F_131 ( V_9 -> V_221 -> V_237 . V_234 . V_243 ) ;
F_132 ( V_9 -> V_12 . V_242 ) ;
}
static void F_138 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_246 . V_96 = 0UL ;
V_9 -> V_12 . V_14 -> V_246 . V_106 = 0UL ;
F_139 ( V_9 , 0 ) ;
V_9 -> V_12 . V_14 -> V_247 = 0UL ;
V_9 -> V_12 . V_14 -> V_248 = 0UL ;
V_9 -> V_12 . V_14 -> V_249 = 0 ;
memset ( V_9 -> V_12 . V_14 -> V_250 , 0 , 16 * sizeof( V_216 ) ) ;
V_9 -> V_12 . V_14 -> V_250 [ 0 ] = 0xE0UL ;
V_9 -> V_12 . V_14 -> V_250 [ 14 ] = 0xC2000000UL ;
V_9 -> V_12 . V_241 . V_232 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_9 -> V_12 . V_14 -> V_251 = 1 ;
V_9 -> V_12 . V_14 -> V_252 = 0 ;
V_9 -> V_12 . V_219 = V_220 ;
F_113 ( V_9 ) ;
if ( ! F_140 ( V_9 -> V_7 ) )
F_141 ( V_9 ) ;
F_112 ( V_9 ) ;
}
void F_142 ( struct V_8 * V_9 )
{
F_31 ( & V_9 -> V_7 -> V_91 ) ;
F_143 () ;
V_9 -> V_12 . V_14 -> V_13 = V_9 -> V_7 -> V_12 . V_13 ;
F_144 () ;
F_35 ( & V_9 -> V_7 -> V_91 ) ;
if ( ! F_46 ( V_9 -> V_7 ) )
V_9 -> V_12 . V_71 = V_9 -> V_7 -> V_12 . V_71 ;
}
static void F_53 ( struct V_8 * V_9 )
{
if ( ! F_51 ( V_9 -> V_7 , 76 ) )
return;
V_9 -> V_12 . V_14 -> V_253 &= ~ ( V_254 | V_255 ) ;
if ( V_9 -> V_7 -> V_12 . V_122 . V_125 )
V_9 -> V_12 . V_14 -> V_253 |= V_254 ;
if ( V_9 -> V_7 -> V_12 . V_122 . V_128 )
V_9 -> V_12 . V_14 -> V_253 |= V_255 ;
V_9 -> V_12 . V_14 -> V_184 = V_9 -> V_7 -> V_12 . V_122 . V_184 ;
}
void F_116 ( struct V_8 * V_9 )
{
F_108 ( V_9 -> V_12 . V_14 -> V_256 ) ;
V_9 -> V_12 . V_14 -> V_256 = 0 ;
}
int F_145 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_256 = F_100 ( V_137 ) ;
if ( ! V_9 -> V_12 . V_14 -> V_256 )
return - V_23 ;
V_9 -> V_12 . V_14 -> V_257 |= 0x80 ;
V_9 -> V_12 . V_14 -> V_257 &= ~ 0x08 ;
return 0 ;
}
static void F_146 ( struct V_8 * V_9 )
{
struct V_258 * V_94 = & V_9 -> V_7 -> V_12 . V_94 ;
V_9 -> V_12 . V_138 = V_94 -> V_138 ;
V_9 -> V_12 . V_14 -> V_140 = V_94 -> V_140 ;
V_9 -> V_12 . V_14 -> V_95 = ( int ) ( long ) V_94 -> V_95 -> V_97 ;
}
int F_147 ( struct V_8 * V_9 )
{
int V_190 = 0 ;
F_120 ( & V_9 -> V_12 . V_14 -> V_245 , V_259 |
V_260 |
V_261 ) ;
if ( F_51 ( V_9 -> V_7 , 78 ) )
F_134 ( V_262 , & V_9 -> V_12 . V_14 -> V_245 ) ;
else if ( F_51 ( V_9 -> V_7 , 8 ) )
F_134 ( V_263 , & V_9 -> V_12 . V_14 -> V_245 ) ;
F_146 ( V_9 ) ;
V_9 -> V_12 . V_14 -> V_264 = 6 ;
if ( F_51 ( V_9 -> V_7 , 50 ) && F_51 ( V_9 -> V_7 , 73 ) )
V_9 -> V_12 . V_14 -> V_264 |= 0x10 ;
V_9 -> V_12 . V_14 -> V_257 = 8 ;
V_9 -> V_12 . V_14 -> V_265 = 0xC1002000U ;
if ( V_146 . V_266 )
V_9 -> V_12 . V_14 -> V_265 |= 1 ;
if ( V_146 . V_267 )
V_9 -> V_12 . V_14 -> V_265 |= 0x10000000U ;
if ( F_51 ( V_9 -> V_7 , 129 ) ) {
V_9 -> V_12 . V_14 -> V_265 |= 0x00020000 ;
V_9 -> V_12 . V_14 -> V_268 |= 0x20000000 ;
}
V_9 -> V_12 . V_14 -> V_269 |= V_270 | V_271 | V_272 ;
if ( V_9 -> V_7 -> V_12 . V_113 ) {
V_190 = F_145 ( V_9 ) ;
if ( V_190 )
return V_190 ;
}
F_148 ( & V_9 -> V_12 . V_273 , V_274 , V_275 ) ;
V_9 -> V_12 . V_273 . V_276 = V_277 ;
F_53 ( V_9 ) ;
return V_190 ;
}
struct V_8 * F_149 ( struct V_7 * V_7 ,
unsigned int V_278 )
{
struct V_8 * V_9 ;
struct V_279 * V_279 ;
int V_190 = - V_32 ;
if ( V_278 >= V_59 )
goto V_83;
V_190 = - V_23 ;
V_9 = F_150 ( V_217 , V_137 ) ;
if ( ! V_9 )
goto V_83;
V_279 = (struct V_279 * ) F_100 ( V_137 ) ;
if ( ! V_279 )
goto V_280;
V_9 -> V_12 . V_14 = & V_279 -> V_14 ;
V_9 -> V_12 . V_14 -> V_281 = ( unsigned long ) & V_279 -> V_282 ;
V_9 -> V_12 . V_14 -> V_283 = V_278 ;
if ( ! F_46 ( V_7 ) ) {
if ( ! V_7 -> V_12 . V_196 ) {
F_151 ( 1 ) ;
goto V_280;
}
if ( ! V_7 -> V_12 . V_196 -> V_214 [ V_278 ] . V_215 )
V_7 -> V_12 . V_196 -> V_214 [ V_278 ] . V_215 =
( V_216 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_284 =
( V_185 ) ( ( ( V_216 ) V_7 -> V_12 . V_196 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_285 = ( V_185 ) ( V_216 ) V_7 -> V_12 . V_196 ;
F_152 ( 63 - V_278 , ( unsigned long * ) & V_7 -> V_12 . V_196 -> V_213 ) ;
}
F_103 ( & V_9 -> V_12 . V_286 . V_91 ) ;
V_9 -> V_12 . V_286 . V_204 = & V_7 -> V_12 . V_204 ;
V_9 -> V_12 . V_286 . V_287 = & V_9 -> V_287 ;
V_9 -> V_12 . V_286 . V_245 = & V_9 -> V_12 . V_14 -> V_245 ;
V_9 -> V_12 . V_241 . V_288 = F_66 ( sizeof( V_289 ) * V_290 ,
V_137 ) ;
if ( ! V_9 -> V_12 . V_241 . V_288 ) {
V_190 = - V_23 ;
goto V_291;
}
V_190 = F_153 ( V_9 , V_7 , V_278 ) ;
if ( V_190 )
goto V_291;
F_37 ( V_7 , 3 , L_28 , V_278 , V_9 ,
V_9 -> V_12 . V_14 ) ;
F_154 ( V_278 , V_9 , V_9 -> V_12 . V_14 ) ;
return V_9 ;
V_291:
F_108 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
V_280:
F_118 ( V_217 , V_9 ) ;
V_83:
return F_155 ( V_190 ) ;
}
int F_156 ( struct V_8 * V_9 )
{
return F_157 ( V_9 , 0 ) ;
}
void F_158 ( struct V_8 * V_9 )
{
F_134 ( V_292 , & V_9 -> V_12 . V_14 -> V_293 ) ;
F_54 ( V_9 ) ;
}
void F_159 ( struct V_8 * V_9 )
{
F_136 ( V_292 , & V_9 -> V_12 . V_14 -> V_293 ) ;
}
static void F_160 ( struct V_8 * V_9 )
{
F_134 ( V_294 , & V_9 -> V_12 . V_14 -> V_293 ) ;
F_54 ( V_9 ) ;
}
static void F_161 ( struct V_8 * V_9 )
{
F_136 ( V_294 , & V_9 -> V_12 . V_14 -> V_293 ) ;
}
void F_54 ( struct V_8 * V_9 )
{
F_134 ( V_295 , & V_9 -> V_12 . V_14 -> V_245 ) ;
while ( V_9 -> V_12 . V_14 -> V_296 & V_297 )
F_162 () ;
}
void F_163 ( int V_298 , struct V_8 * V_9 )
{
F_164 ( V_298 , V_9 ) ;
F_160 ( V_9 ) ;
}
static void V_18 ( struct V_71 * V_71 , unsigned long V_70 )
{
int V_10 ;
struct V_7 * V_7 = V_71 -> V_120 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
if ( F_165 ( V_9 ) == ( V_70 & ~ 0x1000UL ) ) {
F_110 ( V_9 , 2 , L_29 , V_70 ) ;
F_163 ( V_299 , V_9 ) ;
}
}
}
int F_166 ( struct V_8 * V_9 )
{
F_167 () ;
return 0 ;
}
static int F_168 ( struct V_8 * V_9 ,
struct V_300 * V_301 )
{
int V_34 = - V_32 ;
switch ( V_301 -> V_278 ) {
case V_302 :
V_34 = F_41 ( V_9 -> V_12 . V_14 -> V_249 ,
( T_5 V_105 * ) V_301 -> V_106 ) ;
break;
case V_303 :
V_34 = F_41 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_104 V_105 * ) V_301 -> V_106 ) ;
break;
case V_304 :
V_34 = F_41 ( V_9 -> V_12 . V_14 -> V_247 ,
( V_104 V_105 * ) V_301 -> V_106 ) ;
break;
case V_305 :
V_34 = F_41 ( V_9 -> V_12 . V_14 -> V_248 ,
( V_104 V_105 * ) V_301 -> V_106 ) ;
break;
case V_306 :
V_34 = F_41 ( V_9 -> V_12 . V_219 ,
( V_104 V_105 * ) V_301 -> V_106 ) ;
break;
case V_307 :
V_34 = F_41 ( V_9 -> V_12 . V_308 ,
( V_104 V_105 * ) V_301 -> V_106 ) ;
break;
case V_309 :
V_34 = F_41 ( V_9 -> V_12 . V_310 ,
( V_104 V_105 * ) V_301 -> V_106 ) ;
break;
case V_311 :
V_34 = F_41 ( V_9 -> V_12 . V_14 -> V_252 ,
( V_104 V_105 * ) V_301 -> V_106 ) ;
break;
case V_312 :
V_34 = F_41 ( V_9 -> V_12 . V_14 -> V_251 ,
( V_104 V_105 * ) V_301 -> V_106 ) ;
break;
default:
break;
}
return V_34 ;
}
static int F_169 ( struct V_8 * V_9 ,
struct V_300 * V_301 )
{
int V_34 = - V_32 ;
switch ( V_301 -> V_278 ) {
case V_302 :
V_34 = F_47 ( V_9 -> V_12 . V_14 -> V_249 ,
( T_5 V_105 * ) V_301 -> V_106 ) ;
break;
case V_303 :
V_34 = F_47 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_104 V_105 * ) V_301 -> V_106 ) ;
break;
case V_304 :
V_34 = F_47 ( V_9 -> V_12 . V_14 -> V_247 ,
( V_104 V_105 * ) V_301 -> V_106 ) ;
break;
case V_305 :
V_34 = F_47 ( V_9 -> V_12 . V_14 -> V_248 ,
( V_104 V_105 * ) V_301 -> V_106 ) ;
break;
case V_306 :
V_34 = F_47 ( V_9 -> V_12 . V_219 ,
( V_104 V_105 * ) V_301 -> V_106 ) ;
if ( V_9 -> V_12 . V_219 == V_220 )
F_113 ( V_9 ) ;
break;
case V_307 :
V_34 = F_47 ( V_9 -> V_12 . V_308 ,
( V_104 V_105 * ) V_301 -> V_106 ) ;
break;
case V_309 :
V_34 = F_47 ( V_9 -> V_12 . V_310 ,
( V_104 V_105 * ) V_301 -> V_106 ) ;
break;
case V_311 :
V_34 = F_47 ( V_9 -> V_12 . V_14 -> V_252 ,
( V_104 V_105 * ) V_301 -> V_106 ) ;
break;
case V_312 :
V_34 = F_47 ( V_9 -> V_12 . V_14 -> V_251 ,
( V_104 V_105 * ) V_301 -> V_106 ) ;
break;
default:
break;
}
return V_34 ;
}
static int F_170 ( struct V_8 * V_9 )
{
F_138 ( V_9 ) ;
return 0 ;
}
int F_171 ( struct V_8 * V_9 , struct V_313 * V_234 )
{
memcpy ( & V_9 -> V_221 -> V_237 . V_234 . V_314 , & V_234 -> V_314 , sizeof( V_234 -> V_314 ) ) ;
return 0 ;
}
int F_172 ( struct V_8 * V_9 , struct V_313 * V_234 )
{
memcpy ( & V_234 -> V_314 , & V_9 -> V_221 -> V_237 . V_234 . V_314 , sizeof( V_234 -> V_314 ) ) ;
return 0 ;
}
int F_173 ( struct V_8 * V_9 ,
struct V_315 * V_316 )
{
memcpy ( & V_9 -> V_221 -> V_237 . V_234 . V_243 , & V_316 -> V_243 , sizeof( V_316 -> V_243 ) ) ;
memcpy ( & V_9 -> V_12 . V_14 -> V_250 , & V_316 -> V_317 , sizeof( V_316 -> V_317 ) ) ;
F_132 ( V_9 -> V_221 -> V_237 . V_234 . V_243 ) ;
return 0 ;
}
int F_174 ( struct V_8 * V_9 ,
struct V_315 * V_316 )
{
memcpy ( & V_316 -> V_243 , & V_9 -> V_221 -> V_237 . V_234 . V_243 , sizeof( V_316 -> V_243 ) ) ;
memcpy ( & V_316 -> V_317 , & V_9 -> V_12 . V_14 -> V_250 , sizeof( V_316 -> V_317 ) ) ;
return 0 ;
}
int F_175 ( struct V_8 * V_9 , struct V_318 * V_230 )
{
if ( F_130 ( V_230 -> V_232 ) )
return - V_32 ;
memcpy ( V_9 -> V_12 . V_241 . V_288 , & V_230 -> V_288 , sizeof( V_230 -> V_288 ) ) ;
V_9 -> V_12 . V_241 . V_232 = V_230 -> V_232 ;
F_129 () ;
F_127 ( & V_9 -> V_12 . V_241 ) ;
return 0 ;
}
int F_176 ( struct V_8 * V_9 , struct V_318 * V_230 )
{
memcpy ( & V_230 -> V_288 , V_9 -> V_12 . V_241 . V_288 , sizeof( V_230 -> V_288 ) ) ;
V_230 -> V_232 = V_9 -> V_12 . V_241 . V_232 ;
return 0 ;
}
static int F_177 ( struct V_8 * V_9 , T_6 V_319 )
{
int V_190 = 0 ;
if ( ! F_178 ( V_9 ) )
V_190 = - V_93 ;
else {
V_9 -> V_221 -> V_320 = V_319 . V_96 ;
V_9 -> V_221 -> V_321 = V_319 . V_106 ;
}
return V_190 ;
}
int F_179 ( struct V_8 * V_9 ,
struct V_322 * V_323 )
{
return - V_32 ;
}
int F_180 ( struct V_8 * V_9 ,
struct V_324 * V_325 )
{
int V_190 = 0 ;
V_9 -> V_326 = 0 ;
F_181 ( V_9 ) ;
if ( V_325 -> V_327 & ~ V_328 )
return - V_32 ;
if ( V_325 -> V_327 & V_329 ) {
V_9 -> V_326 = V_325 -> V_327 ;
F_134 ( V_330 , & V_9 -> V_12 . V_14 -> V_245 ) ;
if ( V_325 -> V_327 & V_331 )
V_190 = F_182 ( V_9 , V_325 ) ;
} else {
F_136 ( V_330 , & V_9 -> V_12 . V_14 -> V_245 ) ;
V_9 -> V_12 . V_332 . V_333 = 0 ;
}
if ( V_190 ) {
V_9 -> V_326 = 0 ;
F_181 ( V_9 ) ;
F_136 ( V_330 , & V_9 -> V_12 . V_14 -> V_245 ) ;
}
return V_190 ;
}
int F_183 ( struct V_8 * V_9 ,
struct V_334 * V_335 )
{
return F_178 ( V_9 ) ? V_336 :
V_337 ;
}
int F_184 ( struct V_8 * V_9 ,
struct V_334 * V_335 )
{
int V_190 = 0 ;
V_9 -> V_7 -> V_12 . V_338 = 1 ;
switch ( V_335 -> V_335 ) {
case V_336 :
F_141 ( V_9 ) ;
break;
case V_337 :
F_185 ( V_9 ) ;
break;
case V_339 :
case V_340 :
default:
V_190 = - V_108 ;
}
return V_190 ;
}
static bool F_186 ( struct V_8 * V_9 )
{
return F_38 ( & V_9 -> V_12 . V_14 -> V_245 ) & V_341 ;
}
static int F_187 ( struct V_8 * V_9 )
{
V_342:
F_161 ( V_9 ) ;
if ( ! V_9 -> V_343 )
return 0 ;
if ( F_188 ( V_299 , V_9 ) ) {
int V_190 ;
V_190 = F_189 ( V_9 -> V_12 . V_71 ,
F_165 ( V_9 ) ,
V_199 * 2 ) ;
if ( V_190 )
return V_190 ;
goto V_342;
}
if ( F_188 ( V_344 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_345 = 0xffff ;
goto V_342;
}
if ( F_188 ( V_346 , V_9 ) ) {
if ( ! F_186 ( V_9 ) ) {
F_190 ( V_9 -> V_212 , 1 ) ;
F_134 ( V_341 ,
& V_9 -> V_12 . V_14 -> V_245 ) ;
}
goto V_342;
}
if ( F_188 ( V_347 , V_9 ) ) {
if ( F_186 ( V_9 ) ) {
F_190 ( V_9 -> V_212 , 0 ) ;
F_136 ( V_341 ,
& V_9 -> V_12 . V_14 -> V_245 ) ;
}
goto V_342;
}
F_114 ( V_348 , & V_9 -> V_343 ) ;
return 0 ;
}
void F_58 ( struct V_7 * V_7 , V_104 V_349 )
{
struct V_8 * V_9 ;
int V_10 ;
F_31 ( & V_7 -> V_91 ) ;
F_143 () ;
V_7 -> V_12 . V_13 = V_349 - F_191 () ;
F_192 ( V_7 ) ;
F_7 (i, vcpu, kvm)
V_9 -> V_12 . V_14 -> V_13 = V_7 -> V_12 . V_13 ;
F_193 ( V_7 ) ;
F_144 () ;
F_35 ( & V_7 -> V_91 ) ;
}
long F_194 ( struct V_8 * V_9 , T_7 V_350 , int V_351 )
{
return F_195 ( V_9 -> V_12 . V_71 , V_350 ,
V_351 ? V_352 : 0 ) ;
}
static void F_196 ( struct V_8 * V_9 , bool V_353 ,
unsigned long V_354 )
{
struct V_169 V_355 ;
struct V_356 V_357 ;
if ( V_353 ) {
V_357 . V_358 . V_33 . V_359 = V_354 ;
V_357 . type = V_360 ;
F_151 ( F_197 ( V_9 , & V_357 ) ) ;
} else {
V_355 . type = V_361 ;
V_355 . V_362 = V_354 ;
F_151 ( F_89 ( V_9 -> V_7 , & V_355 ) ) ;
}
}
void F_198 ( struct V_8 * V_9 ,
struct V_363 * V_364 )
{
F_199 ( V_9 , V_364 -> V_12 . V_219 ) ;
F_196 ( V_9 , true , V_364 -> V_12 . V_219 ) ;
}
void F_200 ( struct V_8 * V_9 ,
struct V_363 * V_364 )
{
F_201 ( V_9 , V_364 -> V_12 . V_219 ) ;
F_196 ( V_9 , false , V_364 -> V_12 . V_219 ) ;
}
void F_202 ( struct V_8 * V_9 ,
struct V_363 * V_364 )
{
}
bool F_203 ( struct V_8 * V_9 )
{
return true ;
}
static int F_204 ( struct V_8 * V_9 )
{
T_8 V_158 ;
struct V_365 V_12 ;
int V_190 ;
if ( V_9 -> V_12 . V_219 == V_220 )
return 0 ;
if ( ( V_9 -> V_12 . V_14 -> V_246 . V_96 & V_9 -> V_12 . V_310 ) !=
V_9 -> V_12 . V_308 )
return 0 ;
if ( F_205 ( V_9 ) )
return 0 ;
if ( F_157 ( V_9 , 0 ) )
return 0 ;
if ( ! ( V_9 -> V_12 . V_14 -> V_250 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_9 -> V_12 . V_71 -> V_209 )
return 0 ;
V_158 = F_80 ( V_9 -> V_7 , F_206 ( V_119 -> V_233 . V_366 ) ) ;
V_158 += V_119 -> V_233 . V_366 & ~ V_367 ;
if ( F_207 ( V_9 , V_9 -> V_12 . V_219 , & V_12 . V_219 , 8 ) )
return 0 ;
V_190 = F_208 ( V_9 , V_119 -> V_233 . V_366 , V_158 , & V_12 ) ;
return V_190 ;
}
static int F_209 ( struct V_8 * V_9 )
{
int V_190 , V_245 ;
F_210 ( V_9 ) ;
memcpy ( & V_9 -> V_12 . V_14 -> V_368 , & V_9 -> V_221 -> V_237 . V_234 . V_314 [ 14 ] , 16 ) ;
if ( F_211 () )
F_212 () ;
if ( F_213 ( V_369 ) )
F_214 () ;
if ( ! F_46 ( V_9 -> V_7 ) ) {
V_190 = F_215 ( V_9 ) ;
if ( V_190 )
return V_190 ;
}
V_190 = F_187 ( V_9 ) ;
if ( V_190 )
return V_190 ;
if ( F_216 ( V_9 ) ) {
F_217 ( V_9 ) ;
F_218 ( V_9 ) ;
}
V_9 -> V_12 . V_14 -> V_370 = 0 ;
V_245 = F_38 ( & V_9 -> V_12 . V_14 -> V_245 ) ;
F_110 ( V_9 , 6 , L_30 , V_245 ) ;
F_219 ( V_9 , V_245 ) ;
return 0 ;
}
static int F_220 ( struct V_8 * V_9 )
{
T_6 * V_319 = & V_9 -> V_12 . V_14 -> V_246 ;
T_2 V_371 ;
int V_190 ;
F_110 ( V_9 , 3 , L_2 , L_31 ) ;
F_221 ( V_9 ) ;
V_190 = F_222 ( V_9 , V_319 -> V_106 , 0 , & V_371 , 1 ) ;
if ( V_190 )
return F_223 ( V_9 , V_190 ) ;
V_319 -> V_106 = F_224 ( * V_319 , - F_225 ( V_371 ) ) ;
return F_226 ( V_9 , V_372 ) ;
}
static int F_227 ( struct V_8 * V_9 , int V_373 )
{
int V_190 = - 1 ;
F_110 ( V_9 , 6 , L_32 ,
V_9 -> V_12 . V_14 -> V_370 ) ;
F_228 ( V_9 , V_9 -> V_12 . V_14 -> V_370 ) ;
if ( F_216 ( V_9 ) )
F_229 ( V_9 ) ;
if ( V_373 >= 0 ) {
V_190 = 0 ;
} else if ( F_46 ( V_9 -> V_7 ) ) {
V_9 -> V_221 -> V_373 = V_374 ;
V_9 -> V_221 -> V_375 . V_376 =
V_119 -> V_233 . V_366 ;
V_9 -> V_221 -> V_375 . V_377 = 0x10 ;
V_190 = - V_378 ;
} else if ( V_119 -> V_233 . V_379 ) {
F_230 ( V_9 ) ;
V_119 -> V_233 . V_379 = 0 ;
if ( F_204 ( V_9 ) ) {
V_190 = 0 ;
} else {
T_7 V_350 = V_119 -> V_233 . V_366 ;
V_190 = F_194 ( V_9 , V_350 , 1 ) ;
}
}
if ( V_190 == - 1 )
V_190 = F_220 ( V_9 ) ;
memcpy ( & V_9 -> V_221 -> V_237 . V_234 . V_314 [ 14 ] , & V_9 -> V_12 . V_14 -> V_368 , 16 ) ;
if ( V_190 == 0 ) {
if ( F_46 ( V_9 -> V_7 ) )
V_190 = V_9 -> V_12 . V_14 -> V_370 ? - V_380 : 0 ;
else
V_190 = F_231 ( V_9 ) ;
}
return V_190 ;
}
static int F_232 ( struct V_8 * V_9 )
{
int V_190 , V_373 ;
V_9 -> V_381 = F_43 ( & V_9 -> V_7 -> V_115 ) ;
do {
V_190 = F_209 ( V_9 ) ;
if ( V_190 )
break;
F_45 ( & V_9 -> V_7 -> V_115 , V_9 -> V_381 ) ;
F_233 () ;
F_234 () ;
F_235 () ;
V_373 = F_236 ( V_9 -> V_12 . V_14 ,
V_9 -> V_221 -> V_237 . V_234 . V_314 ) ;
F_233 () ;
F_237 () ;
F_235 () ;
V_9 -> V_381 = F_43 ( & V_9 -> V_7 -> V_115 ) ;
V_190 = F_227 ( V_9 , V_373 ) ;
} while ( ! F_238 ( V_119 ) && ! F_239 ( V_9 ) && ! V_190 );
F_45 ( & V_9 -> V_7 -> V_115 , V_9 -> V_381 ) ;
return V_190 ;
}
static void F_240 ( struct V_8 * V_9 , struct V_382 * V_382 )
{
V_9 -> V_12 . V_14 -> V_246 . V_96 = V_382 -> V_320 ;
V_9 -> V_12 . V_14 -> V_246 . V_106 = V_382 -> V_321 ;
if ( V_382 -> V_383 & V_223 )
F_139 ( V_9 , V_382 -> V_237 . V_234 . V_384 ) ;
if ( V_382 -> V_383 & V_226 ) {
memcpy ( & V_9 -> V_12 . V_14 -> V_250 , & V_382 -> V_237 . V_234 . V_317 , 128 ) ;
F_164 ( V_344 , V_9 ) ;
}
if ( V_382 -> V_383 & V_227 ) {
V_9 -> V_12 . V_14 -> V_247 = V_382 -> V_237 . V_234 . V_247 ;
V_9 -> V_12 . V_14 -> V_248 = V_382 -> V_237 . V_234 . V_248 ;
V_9 -> V_12 . V_14 -> V_249 = V_382 -> V_237 . V_234 . V_249 ;
V_9 -> V_12 . V_14 -> V_252 = V_382 -> V_237 . V_234 . V_252 ;
V_9 -> V_12 . V_14 -> V_251 = V_382 -> V_237 . V_234 . V_251 ;
}
if ( V_382 -> V_383 & V_228 ) {
V_9 -> V_12 . V_219 = V_382 -> V_237 . V_234 . V_385 ;
V_9 -> V_12 . V_310 = V_382 -> V_237 . V_234 . V_386 ;
V_9 -> V_12 . V_308 = V_382 -> V_237 . V_234 . V_387 ;
if ( V_9 -> V_12 . V_219 == V_220 )
F_113 ( V_9 ) ;
}
V_382 -> V_383 = 0 ;
}
static void F_241 ( struct V_8 * V_9 , struct V_382 * V_382 )
{
V_382 -> V_320 = V_9 -> V_12 . V_14 -> V_246 . V_96 ;
V_382 -> V_321 = V_9 -> V_12 . V_14 -> V_246 . V_106 ;
V_382 -> V_237 . V_234 . V_384 = F_165 ( V_9 ) ;
memcpy ( & V_382 -> V_237 . V_234 . V_317 , & V_9 -> V_12 . V_14 -> V_250 , 128 ) ;
V_382 -> V_237 . V_234 . V_247 = V_9 -> V_12 . V_14 -> V_247 ;
V_382 -> V_237 . V_234 . V_248 = V_9 -> V_12 . V_14 -> V_248 ;
V_382 -> V_237 . V_234 . V_249 = V_9 -> V_12 . V_14 -> V_249 ;
V_382 -> V_237 . V_234 . V_252 = V_9 -> V_12 . V_14 -> V_252 ;
V_382 -> V_237 . V_234 . V_251 = V_9 -> V_12 . V_14 -> V_251 ;
V_382 -> V_237 . V_234 . V_385 = V_9 -> V_12 . V_219 ;
V_382 -> V_237 . V_234 . V_386 = V_9 -> V_12 . V_310 ;
V_382 -> V_237 . V_234 . V_387 = V_9 -> V_12 . V_308 ;
}
int F_242 ( struct V_8 * V_9 , struct V_382 * V_382 )
{
int V_190 ;
T_9 V_388 ;
if ( F_239 ( V_9 ) ) {
F_243 ( V_9 ) ;
return 0 ;
}
if ( V_9 -> V_389 )
F_244 ( V_390 , & V_9 -> V_391 , & V_388 ) ;
if ( ! F_140 ( V_9 -> V_7 ) ) {
F_185 ( V_9 ) ;
} else if ( F_178 ( V_9 ) ) {
F_245 ( L_33 ,
V_9 -> V_212 ) ;
return - V_32 ;
}
F_240 ( V_9 , V_382 ) ;
F_246 () ;
V_190 = F_232 ( V_9 ) ;
if ( F_238 ( V_119 ) && ! V_190 ) {
V_382 -> V_373 = V_392 ;
V_190 = - V_393 ;
}
if ( F_239 ( V_9 ) && ! V_190 ) {
F_243 ( V_9 ) ;
V_190 = 0 ;
}
if ( V_190 == - V_380 ) {
V_382 -> V_373 = V_394 ;
V_382 -> V_395 . V_370 = V_9 -> V_12 . V_14 -> V_370 ;
V_382 -> V_395 . V_396 = V_9 -> V_12 . V_14 -> V_396 ;
V_382 -> V_395 . V_397 = V_9 -> V_12 . V_14 -> V_397 ;
V_190 = 0 ;
}
if ( V_190 == - V_378 ) {
V_190 = 0 ;
}
F_241 ( V_9 , V_382 ) ;
if ( V_9 -> V_389 )
F_244 ( V_390 , & V_388 , NULL ) ;
V_9 -> V_398 . V_399 ++ ;
return V_190 ;
}
int F_247 ( struct V_8 * V_9 , unsigned long V_350 )
{
unsigned char V_400 = 1 ;
unsigned int V_401 ;
V_104 V_402 ;
int V_190 ;
if ( V_350 == V_403 ) {
if ( F_248 ( V_9 , 163 , & V_400 , 1 ) )
return - V_107 ;
V_350 = V_404 ;
} else if ( V_350 == V_405 ) {
if ( F_249 ( V_9 , 163 , & V_400 , 1 ) )
return - V_107 ;
V_350 = F_250 ( V_9 , V_404 ) ;
}
V_190 = F_248 ( V_9 , V_350 + F_251 ( struct V_406 , V_407 ) ,
V_9 -> V_12 . V_241 . V_288 , 128 ) ;
V_190 |= F_248 ( V_9 , V_350 + F_251 ( struct V_406 , V_408 ) ,
V_9 -> V_221 -> V_237 . V_234 . V_314 , 128 ) ;
V_190 |= F_248 ( V_9 , V_350 + F_251 ( struct V_406 , V_319 ) ,
& V_9 -> V_12 . V_14 -> V_246 , 16 ) ;
V_401 = F_165 ( V_9 ) ;
V_190 |= F_248 ( V_9 , V_350 + F_251 ( struct V_406 , V_409 ) ,
& V_401 , 4 ) ;
V_190 |= F_248 ( V_9 ,
V_350 + F_251 ( struct V_406 , V_410 ) ,
& V_9 -> V_12 . V_241 . V_232 , 4 ) ;
V_190 |= F_248 ( V_9 , V_350 + F_251 ( struct V_406 , V_411 ) ,
& V_9 -> V_12 . V_14 -> V_249 , 4 ) ;
V_190 |= F_248 ( V_9 , V_350 + F_251 ( struct V_406 , V_412 ) ,
& V_9 -> V_12 . V_14 -> V_247 , 8 ) ;
V_402 = V_9 -> V_12 . V_14 -> V_248 >> 8 ;
V_190 |= F_248 ( V_9 , V_350 + F_251 ( struct V_406 , V_413 ) ,
& V_402 , 8 ) ;
V_190 |= F_248 ( V_9 , V_350 + F_251 ( struct V_406 , V_414 ) ,
& V_9 -> V_221 -> V_237 . V_234 . V_243 , 64 ) ;
V_190 |= F_248 ( V_9 , V_350 + F_251 ( struct V_406 , V_415 ) ,
& V_9 -> V_12 . V_14 -> V_250 , 128 ) ;
return V_190 ? - V_107 : 0 ;
}
int F_252 ( struct V_8 * V_9 , unsigned long V_106 )
{
F_129 () ;
if ( F_51 ( V_9 -> V_7 , 129 ) ) {
V_9 -> V_12 . V_241 . V_232 = V_119 -> V_233 . V_230 . V_232 ;
F_253 ( V_9 -> V_12 . V_241 . V_288 ,
V_119 -> V_233 . V_230 . V_238 ) ;
} else
F_126 ( & V_9 -> V_12 . V_241 ) ;
F_131 ( V_9 -> V_221 -> V_237 . V_234 . V_243 ) ;
return F_247 ( V_9 , V_106 ) ;
}
int F_254 ( struct V_8 * V_9 ,
unsigned long V_350 )
{
if ( ! ( V_350 & ~ 0x3ff ) )
return 0 ;
return F_248 ( V_9 , V_350 & ~ 0x3ff ,
( void * ) & V_9 -> V_221 -> V_237 . V_234 . V_240 , 512 ) ;
}
int F_255 ( struct V_8 * V_9 , unsigned long V_106 )
{
if ( ! F_51 ( V_9 -> V_7 , 129 ) )
return 0 ;
F_129 () ;
return F_254 ( V_9 , V_106 ) ;
}
static void F_256 ( struct V_8 * V_9 )
{
F_188 ( V_346 , V_9 ) ;
F_163 ( V_347 , V_9 ) ;
}
static void F_257 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
F_256 ( V_9 ) ;
}
}
static void F_258 ( struct V_8 * V_9 )
{
F_188 ( V_347 , V_9 ) ;
F_163 ( V_346 , V_9 ) ;
}
void F_185 ( struct V_8 * V_9 )
{
int V_10 , V_92 , V_416 = 0 ;
if ( ! F_178 ( V_9 ) )
return;
F_259 ( V_9 -> V_212 , 1 ) ;
F_101 ( & V_9 -> V_7 -> V_12 . V_211 ) ;
V_92 = F_38 ( & V_9 -> V_7 -> V_92 ) ;
for ( V_10 = 0 ; V_10 < V_92 ; V_10 ++ ) {
if ( ! F_178 ( V_9 -> V_7 -> V_218 [ V_10 ] ) )
V_416 ++ ;
}
if ( V_416 == 0 ) {
F_258 ( V_9 ) ;
} else if ( V_416 == 1 ) {
F_257 ( V_9 -> V_7 ) ;
}
F_136 ( V_261 , & V_9 -> V_12 . V_14 -> V_245 ) ;
F_164 ( V_344 , V_9 ) ;
F_102 ( & V_9 -> V_7 -> V_12 . V_211 ) ;
return;
}
void F_141 ( struct V_8 * V_9 )
{
int V_10 , V_92 , V_416 = 0 ;
struct V_8 * V_417 = NULL ;
if ( F_178 ( V_9 ) )
return;
F_259 ( V_9 -> V_212 , 0 ) ;
F_101 ( & V_9 -> V_7 -> V_12 . V_211 ) ;
V_92 = F_38 ( & V_9 -> V_7 -> V_92 ) ;
F_260 ( V_9 ) ;
F_134 ( V_261 , & V_9 -> V_12 . V_14 -> V_245 ) ;
F_256 ( V_9 ) ;
for ( V_10 = 0 ; V_10 < V_92 ; V_10 ++ ) {
if ( ! F_178 ( V_9 -> V_7 -> V_218 [ V_10 ] ) ) {
V_416 ++ ;
V_417 = V_9 -> V_7 -> V_218 [ V_10 ] ;
}
}
if ( V_416 == 1 ) {
F_258 ( V_417 ) ;
}
F_102 ( & V_9 -> V_7 -> V_12 . V_211 ) ;
return;
}
static int F_261 ( struct V_8 * V_9 ,
struct V_86 * V_87 )
{
int V_34 ;
if ( V_87 -> V_88 )
return - V_32 ;
switch ( V_87 -> V_87 ) {
case V_43 :
if ( ! V_9 -> V_7 -> V_12 . V_210 ) {
V_9 -> V_7 -> V_12 . V_210 = 1 ;
F_37 ( V_9 -> V_7 , 3 , L_2 , L_34 ) ;
F_262 ( V_9 -> V_7 ) ;
}
V_34 = 0 ;
break;
default:
V_34 = - V_32 ;
break;
}
return V_34 ;
}
static long F_263 ( struct V_8 * V_9 ,
struct V_418 * V_419 )
{
void V_105 * V_420 = ( void V_105 * ) V_419 -> V_421 ;
void * V_422 = NULL ;
int V_34 , V_381 ;
const V_104 V_423 = V_424
| V_425 ;
if ( V_419 -> V_88 & ~ V_423 )
return - V_32 ;
if ( V_419 -> V_426 > V_56 )
return - V_117 ;
if ( ! ( V_419 -> V_88 & V_425 ) ) {
V_422 = F_79 ( V_419 -> V_426 ) ;
if ( ! V_422 )
return - V_23 ;
}
V_381 = F_43 ( & V_9 -> V_7 -> V_115 ) ;
switch ( V_419 -> V_427 ) {
case V_428 :
if ( V_419 -> V_88 & V_425 ) {
V_34 = F_264 ( V_9 , V_419 -> V_429 , V_419 -> V_430 , V_419 -> V_426 , false ) ;
break;
}
V_34 = F_222 ( V_9 , V_419 -> V_429 , V_419 -> V_430 , V_422 , V_419 -> V_426 ) ;
if ( V_34 == 0 ) {
if ( F_61 ( V_420 , V_422 , V_419 -> V_426 ) )
V_34 = - V_107 ;
}
break;
case V_431 :
if ( V_419 -> V_88 & V_425 ) {
V_34 = F_264 ( V_9 , V_419 -> V_429 , V_419 -> V_430 , V_419 -> V_426 , true ) ;
break;
}
if ( F_56 ( V_422 , V_420 , V_419 -> V_426 ) ) {
V_34 = - V_107 ;
break;
}
V_34 = F_265 ( V_9 , V_419 -> V_429 , V_419 -> V_430 , V_422 , V_419 -> V_426 ) ;
break;
default:
V_34 = - V_32 ;
}
F_45 ( & V_9 -> V_7 -> V_115 , V_381 ) ;
if ( V_34 > 0 && ( V_419 -> V_88 & V_424 ) != 0 )
F_266 ( V_9 , & V_9 -> V_12 . V_432 ) ;
F_267 ( V_422 ) ;
return V_34 ;
}
long F_268 ( struct V_27 * V_28 ,
unsigned int V_29 , unsigned long V_30 )
{
struct V_8 * V_9 = V_28 -> V_166 ;
void V_105 * V_167 = ( void V_105 * ) V_30 ;
int V_109 ;
long V_34 ;
switch ( V_29 ) {
case V_433 : {
struct V_356 V_434 ;
V_34 = - V_107 ;
if ( F_56 ( & V_434 , V_167 , sizeof( V_434 ) ) )
break;
V_34 = F_197 ( V_9 , & V_434 ) ;
break;
}
case V_168 : {
struct V_169 V_170 ;
struct V_356 V_434 ;
V_34 = - V_107 ;
if ( F_56 ( & V_170 , V_167 , sizeof( V_170 ) ) )
break;
if ( F_269 ( & V_170 , & V_434 ) )
return - V_32 ;
V_34 = F_197 ( V_9 , & V_434 ) ;
break;
}
case V_435 :
V_109 = F_43 ( & V_9 -> V_7 -> V_115 ) ;
V_34 = F_252 ( V_9 , V_30 ) ;
F_45 ( & V_9 -> V_7 -> V_115 , V_109 ) ;
break;
case V_436 : {
T_6 V_319 ;
V_34 = - V_107 ;
if ( F_56 ( & V_319 , V_167 , sizeof( V_319 ) ) )
break;
V_34 = F_177 ( V_9 , V_319 ) ;
break;
}
case V_437 :
V_34 = F_170 ( V_9 ) ;
break;
case V_438 :
case V_439 : {
struct V_300 V_301 ;
V_34 = - V_107 ;
if ( F_56 ( & V_301 , V_167 , sizeof( V_301 ) ) )
break;
if ( V_29 == V_438 )
V_34 = F_169 ( V_9 , & V_301 ) ;
else
V_34 = F_168 ( V_9 , & V_301 ) ;
break;
}
#ifdef F_23
case V_440 : {
struct V_441 V_442 ;
if ( F_56 ( & V_442 , V_167 , sizeof( V_442 ) ) ) {
V_34 = - V_107 ;
break;
}
if ( ! F_46 ( V_9 -> V_7 ) ) {
V_34 = - V_32 ;
break;
}
V_34 = F_270 ( V_9 -> V_12 . V_71 , V_442 . V_443 ,
V_442 . V_444 , V_442 . V_445 ) ;
break;
}
case V_446 : {
struct V_441 V_442 ;
if ( F_56 ( & V_442 , V_167 , sizeof( V_442 ) ) ) {
V_34 = - V_107 ;
break;
}
if ( ! F_46 ( V_9 -> V_7 ) ) {
V_34 = - V_32 ;
break;
}
V_34 = F_271 ( V_9 -> V_12 . V_71 , V_442 . V_444 ,
V_442 . V_445 ) ;
break;
}
#endif
case V_447 : {
V_34 = F_195 ( V_9 -> V_12 . V_71 , V_30 , 0 ) ;
break;
}
case V_171 :
{
struct V_86 V_87 ;
V_34 = - V_107 ;
if ( F_56 ( & V_87 , V_167 , sizeof( V_87 ) ) )
break;
V_34 = F_261 ( V_9 , & V_87 ) ;
break;
}
case V_448 : {
struct V_418 V_449 ;
if ( F_56 ( & V_449 , V_167 , sizeof( V_449 ) ) == 0 )
V_34 = F_263 ( V_9 , & V_449 ) ;
else
V_34 = - V_107 ;
break;
}
case V_450 : {
struct V_451 V_452 ;
V_34 = - V_107 ;
if ( F_56 ( & V_452 , V_167 , sizeof( V_452 ) ) )
break;
if ( V_452 . V_453 > V_454 ||
V_452 . V_453 == 0 ||
V_452 . V_453 % sizeof( struct V_356 ) > 0 ) {
V_34 = - V_32 ;
break;
}
V_34 = F_272 ( V_9 ,
( void V_105 * ) V_452 . V_421 ,
V_452 . V_453 ) ;
break;
}
case V_455 : {
struct V_451 V_452 ;
V_34 = - V_107 ;
if ( F_56 ( & V_452 , V_167 , sizeof( V_452 ) ) )
break;
if ( V_452 . V_453 == 0 ) {
V_34 = - V_32 ;
break;
}
V_34 = F_273 ( V_9 ,
( V_456 V_105 * ) V_452 . V_421 ,
V_452 . V_453 ) ;
break;
}
default:
V_34 = - V_180 ;
}
return V_34 ;
}
int F_274 ( struct V_8 * V_9 , struct V_457 * V_458 )
{
#ifdef F_23
if ( ( V_458 -> V_459 == V_460 )
&& ( F_46 ( V_9 -> V_7 ) ) ) {
V_458 -> V_461 = F_275 ( V_9 -> V_12 . V_14 ) ;
F_276 ( V_458 -> V_461 ) ;
return 0 ;
}
#endif
return V_462 ;
}
int F_277 ( struct V_7 * V_7 , struct V_66 * V_82 ,
unsigned long V_75 )
{
return 0 ;
}
int F_278 ( struct V_7 * V_7 ,
struct V_66 * V_67 ,
const struct V_463 * V_464 ,
enum V_465 V_466 )
{
if ( V_464 -> V_467 & 0xffffful )
return - V_32 ;
if ( V_464 -> V_468 & 0xffffful )
return - V_32 ;
return 0 ;
}
void F_279 ( struct V_7 * V_7 ,
const struct V_463 * V_464 ,
const struct V_66 * V_469 ,
const struct V_66 * V_118 ,
enum V_465 V_466 )
{
int V_190 ;
if ( V_469 -> V_467 == V_464 -> V_467 &&
V_469 -> V_74 * V_199 == V_464 -> V_470 &&
V_469 -> V_75 * V_199 == V_464 -> V_468 )
return;
V_190 = F_270 ( V_7 -> V_12 . V_71 , V_464 -> V_467 ,
V_464 -> V_470 , V_464 -> V_468 ) ;
if ( V_190 )
F_280 ( L_35 ) ;
return;
}
static int T_10 F_281 ( void )
{
return F_282 ( NULL , sizeof( struct V_8 ) , 0 , V_471 ) ;
}
static void T_11 F_283 ( void )
{
F_284 () ;
}
