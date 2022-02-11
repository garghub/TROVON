static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 (i) {
V_2 -> V_4 . V_5 [ V_3 ] = 0 ;
V_2 -> V_4 . V_6 [ V_3 ] = 0 ;
}
return 0 ;
}
int F_3 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_4 . V_7 ) ;
}
int F_4 ( struct V_1 * V_2 )
{
return 1 ;
}
int F_5 ( void )
{
return 0 ;
}
int F_6 ( void )
{
return 0 ;
}
void F_7 ( void * V_8 )
{
* ( int * ) V_8 = 0 ;
}
static void F_8 ( struct V_9 * V_9 )
{
unsigned long V_10 ;
V_10 = F_9 () ;
F_10 ( V_10 + 1 ) ;
F_11 () ;
V_9 -> V_4 . V_11 = V_10 ;
F_12 ( L_1 , F_13 () ,
V_9 -> V_4 . V_11 ) ;
}
static void F_14 ( void * V_12 )
{
struct V_9 * V_9 = (struct V_9 * ) V_12 ;
F_8 ( V_9 ) ;
V_13 -> V_14 ( V_9 ) ;
}
int F_15 ( struct V_9 * V_9 , unsigned long type )
{
if ( F_16 ( & V_15 ) == 1 ) {
F_12 ( L_2 ,
V_16 ) ;
F_17 ( F_14 , V_9 , 1 ) ;
}
return 0 ;
}
void F_18 ( struct V_9 * V_9 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
for ( V_3 = 0 ; V_3 < V_9 -> V_4 . V_17 ; V_3 ++ ) {
if ( V_9 -> V_4 . V_18 [ V_3 ] != V_19 )
F_19 ( V_9 -> V_4 . V_18 [ V_3 ] ) ;
}
F_20 ( V_9 -> V_4 . V_18 ) ;
F_21 (i, vcpu, kvm) {
F_22 ( V_2 ) ;
}
F_23 ( & V_9 -> V_20 ) ;
for ( V_3 = 0 ; V_3 < F_24 ( & V_9 -> V_21 ) ; V_3 ++ )
V_9 -> V_22 [ V_3 ] = NULL ;
F_25 ( & V_9 -> V_21 , 0 ) ;
F_26 ( & V_9 -> V_20 ) ;
}
static void F_27 ( void * V_12 )
{
F_10 ( 0 ) ;
F_11 () ;
F_28 () ;
}
void F_29 ( struct V_9 * V_9 )
{
F_18 ( V_9 ) ;
if ( F_30 ( & V_15 ) == 0 ) {
F_12 ( L_3 ,
V_16 ) ;
F_17 ( F_27 , NULL , 1 ) ;
}
}
long F_31 ( struct V_23 * V_24 , unsigned int V_25 ,
unsigned long V_12 )
{
return - V_26 ;
}
int F_32 ( struct V_9 * V_9 , struct V_27 * V_28 ,
unsigned long V_29 )
{
return 0 ;
}
int F_33 ( struct V_9 * V_9 ,
struct V_27 * V_30 ,
struct V_31 * V_32 ,
enum V_33 V_34 )
{
return 0 ;
}
void F_34 ( struct V_9 * V_9 ,
struct V_31 * V_32 ,
const struct V_27 * V_35 ,
enum V_33 V_34 )
{
unsigned long V_29 = 0 ;
int V_3 ;
F_12 ( L_4 ,
V_16 , V_9 , V_32 -> V_28 , V_32 -> V_36 ,
V_32 -> V_37 , V_32 -> V_38 ) ;
if ( ! V_9 -> V_4 . V_18 ) {
if ( V_32 -> V_28 == 0 )
V_29 = V_32 -> V_37 >> V_39 ;
if ( V_29 ) {
V_9 -> V_4 . V_17 = V_29 ;
V_9 -> V_4 . V_18 =
F_35 ( V_29 * sizeof( unsigned long ) , V_40 ) ;
if ( ! V_9 -> V_4 . V_18 ) {
F_36 ( L_5 ) ;
return;
}
F_12 ( L_6 ,
V_29 , V_9 -> V_4 . V_18 ) ;
for ( V_3 = 0 ; V_3 < V_29 ; V_3 ++ )
V_9 -> V_4 . V_18 [ V_3 ] = V_19 ;
}
}
}
struct V_1 * F_37 ( struct V_9 * V_9 , unsigned int V_41 )
{
int V_42 , V_43 , V_44 ;
void * V_45 ;
int V_3 ;
struct V_1 * V_2 = F_35 ( sizeof( struct V_1 ) , V_40 ) ;
if ( ! V_2 ) {
V_42 = - V_46 ;
goto V_47;
}
V_42 = F_38 ( V_2 , V_9 , V_41 ) ;
if ( V_42 )
goto V_48;
F_12 ( L_7 , V_9 , V_41 , V_2 ) ;
if ( V_49 || V_50 )
V_43 = 0x200 + V_51 * 64 ;
else
V_43 = 0x4000 ;
V_2 -> V_4 . V_52 = ( void * ) F_39 () ;
V_45 = F_35 ( F_40 ( V_43 , V_53 ) , V_40 ) ;
if ( ! V_45 ) {
V_42 = - V_46 ;
goto V_48;
}
F_12 ( L_8 ,
F_40 ( V_43 , V_53 ) , V_45 ) ;
V_2 -> V_4 . V_54 = V_45 ;
memcpy ( V_45 , V_55 ,
V_56 - V_55 ) ;
memcpy ( V_45 + 0x180 , V_55 ,
V_56 - V_55 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
F_12 ( L_9 ,
V_45 + 0x200 + ( V_3 * V_51 ) ) ;
memcpy ( V_45 + 0x200 + ( V_3 * V_51 ) , V_55 ,
V_56 - V_55 ) ;
}
V_44 = 0x2000 ;
F_12 ( L_10 ,
V_45 + V_44 ,
V_57 - V_58 ) ;
memcpy ( V_45 + V_44 , V_58 ,
V_57 - V_58 ) ;
F_41 ( ( unsigned long ) V_45 ,
( unsigned long ) V_45 + F_40 ( V_43 , V_53 ) ) ;
V_2 -> V_4 . V_59 = F_35 ( V_53 << 1 , V_40 ) ;
if ( ! V_2 -> V_4 . V_59 ) {
V_42 = - V_46 ;
goto V_60;
}
F_12 ( L_11 , V_2 -> V_4 . V_59 ) ;
F_42 ( V_2 ) ;
V_2 -> V_4 . V_61 = - 1 ;
F_43 ( V_2 ) ;
return V_2 ;
V_60:
F_20 ( V_45 ) ;
V_48:
F_20 ( V_2 ) ;
V_47:
return F_44 ( V_42 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_45 ( & V_2 -> V_4 . V_62 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_20 ( V_2 -> V_4 . V_54 ) ;
F_20 ( V_2 -> V_4 . V_59 ) ;
F_20 ( V_2 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
return - V_26 ;
}
int F_50 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
int V_67 = 0 ;
T_1 V_68 ;
if ( V_2 -> V_69 )
F_51 ( V_70 , & V_2 -> V_71 , & V_68 ) ;
if ( V_2 -> V_72 ) {
if ( ! V_2 -> V_73 )
F_52 ( V_2 , V_66 ) ;
V_2 -> V_72 = 0 ;
}
F_53 ( 1 ) ;
F_54 () ;
F_55 ( V_2 ,
F_56 ( V_2 -> V_4 . V_74 ) ) ;
F_57 () ;
F_58 () ;
V_67 = F_59 ( V_66 , V_2 ) ;
F_60 () ;
F_61 () ;
F_62 () ;
if ( V_2 -> V_69 )
F_51 ( V_70 , & V_68 , NULL ) ;
return V_67 ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_75 * V_76 )
{
int V_77 = ( int ) V_76 -> V_76 ;
struct V_1 * V_78 = NULL ;
if ( V_77 == 3 || V_77 == - 3 || V_77 == 4 || V_77 == - 4 )
F_12 ( L_12 , V_16 , V_76 -> V_79 ,
( int ) V_77 ) ;
if ( V_76 -> V_79 == - 1 )
V_78 = V_2 ;
else
V_78 = V_2 -> V_9 -> V_22 [ V_76 -> V_79 ] ;
if ( V_77 == 2 || V_77 == 3 || V_77 == 4 ) {
V_13 -> V_80 ( V_78 , V_76 ) ;
} else if ( V_77 == - 2 || V_77 == - 3 || V_77 == - 4 ) {
V_13 -> V_81 ( V_78 , V_76 ) ;
} else {
F_36 ( L_13 , V_16 ,
V_76 -> V_79 , V_76 -> V_76 ) ;
return - V_82 ;
}
V_78 -> V_4 . V_83 = 0 ;
if ( F_64 ( & V_78 -> V_84 ) )
F_65 ( & V_78 -> V_84 ) ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
return - V_26 ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
return - V_26 ;
}
static int F_68 ( struct V_1 * V_2 ,
const struct V_87 * V_88 )
{
struct V_89 * V_74 = V_2 -> V_4 . V_74 ;
int V_90 ;
T_2 V_91 ;
switch ( V_88 -> V_41 ) {
case V_92 ... V_93 :
V_91 = ( long ) V_2 -> V_4 . V_94 [ V_88 -> V_41 - V_92 ] ;
break;
case V_95 :
V_91 = ( long ) V_2 -> V_4 . V_96 ;
break;
case V_97 :
V_91 = ( long ) V_2 -> V_4 . V_98 ;
break;
case V_99 :
V_91 = ( long ) V_2 -> V_4 . V_100 ;
break;
case V_101 :
V_91 = ( long ) F_69 ( V_74 ) ;
break;
case V_102 :
V_91 = ( long ) F_70 ( V_74 ) ;
break;
case V_103 :
V_91 = ( long ) F_71 ( V_74 ) ;
break;
case V_104 :
V_91 = ( long ) F_72 ( V_74 ) ;
break;
case V_105 :
V_91 = ( long ) F_73 ( V_74 ) ;
break;
case V_106 :
V_91 = ( long ) F_74 ( V_74 ) ;
break;
case V_107 :
V_91 = ( long ) F_75 ( V_74 ) ;
break;
case V_108 :
V_91 = ( long ) F_76 ( V_74 ) ;
break;
case V_109 :
V_91 = ( long ) F_77 ( V_74 ) ;
break;
case V_110 :
V_91 = ( long ) F_78 ( V_74 ) ;
break;
case V_111 :
V_91 = ( long ) F_56 ( V_74 ) ;
break;
case V_112 :
V_91 = ( long ) F_79 ( V_74 ) ;
break;
case V_113 :
V_91 = ( long ) F_80 ( V_74 ) ;
break;
case V_114 :
V_91 = ( long ) F_81 ( V_74 ) ;
break;
case V_115 :
V_91 = ( long ) F_82 ( V_74 ) ;
break;
case V_116 :
V_91 = ( long ) F_83 ( V_74 ) ;
break;
case V_117 :
V_91 = ( long ) F_84 ( V_74 ) ;
break;
case V_118 :
V_91 = ( long ) F_85 ( V_74 ) ;
break;
case V_119 :
case V_120 :
case V_121 :
case V_122 :
V_90 = V_13 -> V_123 ( V_2 , V_88 , & V_91 ) ;
if ( V_90 )
return V_90 ;
break;
default:
return - V_82 ;
}
if ( ( V_88 -> V_41 & V_124 ) == V_125 ) {
T_3 T_4 * V_126 = ( T_3 T_4 * ) ( long ) V_88 -> V_127 ;
return F_86 ( V_91 , V_126 ) ;
} else if ( ( V_88 -> V_41 & V_124 ) == V_128 ) {
T_5 T_4 * V_129 = ( T_5 T_4 * ) ( long ) V_88 -> V_127 ;
T_5 V_130 = ( T_5 ) V_91 ;
return F_86 ( V_130 , V_129 ) ;
} else {
return - V_82 ;
}
}
static int F_87 ( struct V_1 * V_2 ,
const struct V_87 * V_88 )
{
struct V_89 * V_74 = V_2 -> V_4 . V_74 ;
T_3 V_91 ;
if ( ( V_88 -> V_41 & V_124 ) == V_125 ) {
T_3 T_4 * V_126 = ( T_3 T_4 * ) ( long ) V_88 -> V_127 ;
if ( F_88 ( V_91 , V_126 ) != 0 )
return - V_131 ;
} else if ( ( V_88 -> V_41 & V_124 ) == V_128 ) {
T_5 T_4 * V_129 = ( T_5 T_4 * ) ( long ) V_88 -> V_127 ;
T_6 V_130 ;
if ( F_88 ( V_130 , V_129 ) != 0 )
return - V_131 ;
V_91 = ( T_2 ) V_130 ;
} else {
return - V_82 ;
}
switch ( V_88 -> V_41 ) {
case V_92 :
break;
case V_132 ... V_93 :
V_2 -> V_4 . V_94 [ V_88 -> V_41 - V_92 ] = V_91 ;
break;
case V_95 :
V_2 -> V_4 . V_96 = V_91 ;
break;
case V_97 :
V_2 -> V_4 . V_98 = V_91 ;
break;
case V_99 :
V_2 -> V_4 . V_100 = V_91 ;
break;
case V_101 :
F_89 ( V_74 , V_91 ) ;
break;
case V_102 :
F_90 ( V_74 , V_91 ) ;
break;
case V_103 :
F_91 ( V_74 , V_91 ) ;
break;
case V_104 :
F_92 ( V_74 , V_91 ) ;
break;
case V_105 :
F_93 ( V_74 , V_91 ) ;
break;
case V_106 :
F_94 ( V_74 , V_91 ) ;
break;
case V_107 :
F_95 ( V_74 , V_91 ) ;
break;
case V_108 :
F_96 ( V_74 , V_91 ) ;
break;
case V_110 :
F_97 ( V_74 , V_91 ) ;
break;
case V_112 :
F_98 ( V_74 , V_91 ) ;
break;
case V_113 :
F_99 ( V_74 , V_91 ) ;
break;
case V_119 :
case V_109 :
case V_111 :
case V_120 :
case V_121 :
case V_122 :
return V_13 -> V_133 ( V_2 , V_88 , V_91 ) ;
default:
return - V_82 ;
}
return 0 ;
}
long F_100 ( struct V_23 * V_24 , unsigned int V_25 ,
unsigned long V_12 )
{
struct V_1 * V_2 = V_24 -> V_134 ;
void T_4 * V_135 = ( void T_4 * ) V_12 ;
long V_67 ;
switch ( V_25 ) {
case V_136 :
case V_137 : {
struct V_87 V_88 ;
if ( F_101 ( & V_88 , V_135 , sizeof( V_88 ) ) )
return - V_131 ;
if ( V_25 == V_136 )
return F_87 ( V_2 , & V_88 ) ;
else
return F_68 ( V_2 , & V_88 ) ;
}
case V_138 : {
struct V_139 T_4 * V_140 = V_135 ;
T_3 T_4 * V_141 ;
struct V_139 V_142 ;
unsigned V_143 ;
if ( F_101 ( & V_142 , V_140 , sizeof( V_142 ) ) )
return - V_131 ;
V_143 = V_142 . V_143 ;
V_142 . V_143 = F_102 ( V_144 ) ;
if ( F_103 ( V_140 , & V_142 , sizeof( V_142 ) ) )
return - V_131 ;
if ( V_143 < V_142 . V_143 )
return - V_145 ;
V_141 = V_140 -> V_88 ;
if ( F_103 ( V_141 , V_144 ,
sizeof( V_144 ) ) )
return - V_131 ;
return 0 ;
}
case V_146 :
V_67 = F_1 ( V_2 ) ;
break;
case V_147 :
{
struct V_75 V_76 ;
V_67 = - V_131 ;
if ( F_101 ( & V_76 , V_135 , sizeof( V_76 ) ) )
goto V_47;
F_12 ( L_14 , V_2 -> V_148 , V_16 ,
V_76 . V_76 ) ;
V_67 = F_63 ( V_2 , & V_76 ) ;
break;
}
default:
V_67 = - V_26 ;
}
V_47:
return V_67 ;
}
int F_104 ( struct V_9 * V_9 , struct V_149 * log )
{
struct V_27 * V_30 ;
unsigned long V_150 , V_151 ;
int V_152 = 0 ;
int V_67 ;
unsigned long V_143 ;
F_23 ( & V_9 -> V_153 ) ;
V_67 = F_105 ( V_9 , log , & V_152 ) ;
if ( V_67 )
goto V_47;
if ( V_152 ) {
V_30 = & V_9 -> V_154 -> V_154 [ log -> V_28 ] ;
V_150 = V_30 -> V_155 << V_39 ;
V_151 = V_150 + ( V_30 -> V_29 << V_39 ) ;
F_106 ( L_15 , V_16 , V_150 ,
V_151 ) ;
V_143 = F_107 ( V_30 ) ;
memset ( V_30 -> V_156 , 0 , V_143 ) ;
}
V_67 = 0 ;
V_47:
F_26 ( & V_9 -> V_153 ) ;
return V_67 ;
}
long F_108 ( struct V_23 * V_24 , unsigned int V_25 , unsigned long V_12 )
{
long V_67 ;
switch ( V_25 ) {
default:
V_67 = - V_26 ;
}
return V_67 ;
}
int F_109 ( void * V_157 )
{
if ( V_13 ) {
F_36 ( L_16 ) ;
return - V_158 ;
}
return F_110 ( & V_13 ) ;
}
void F_111 ( void )
{
V_13 = NULL ;
}
int F_112 ( struct V_1 * V_2 ,
struct V_159 * V_160 )
{
return - V_26 ;
}
int F_113 ( struct V_1 * V_2 ,
struct V_159 * V_160 )
{
return - V_26 ;
}
void F_114 ( struct V_1 * V_2 )
{
}
int F_115 ( struct V_1 * V_2 , struct V_161 * V_162 )
{
return - V_26 ;
}
int F_116 ( struct V_1 * V_2 , struct V_161 * V_162 )
{
return - V_26 ;
}
int F_117 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
return V_165 ;
}
int F_118 ( struct V_9 * V_9 , long V_166 )
{
int V_67 ;
switch ( V_166 ) {
case V_167 :
V_67 = 1 ;
break;
case V_168 :
V_67 = V_169 ;
break;
default:
V_67 = 0 ;
break;
}
return V_67 ;
}
int F_119 ( struct V_1 * V_2 )
{
return F_120 ( V_2 ) ;
}
int F_121 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_89 * V_74 ;
if ( ! V_2 )
return - 1 ;
F_12 ( L_17 ) ;
F_12 ( L_18 , V_2 -> V_4 . V_100 ) ;
F_12 ( L_19 , V_2 -> V_4 . V_7 ) ;
for ( V_3 = 0 ; V_3 < 32 ; V_3 += 4 ) {
F_12 ( L_20 , V_3 ,
V_2 -> V_4 . V_94 [ V_3 ] ,
V_2 -> V_4 . V_94 [ V_3 + 1 ] ,
V_2 -> V_4 . V_94 [ V_3 + 2 ] , V_2 -> V_4 . V_94 [ V_3 + 3 ] ) ;
}
F_12 ( L_21 , V_2 -> V_4 . V_96 ) ;
F_12 ( L_22 , V_2 -> V_4 . V_98 ) ;
V_74 = V_2 -> V_4 . V_74 ;
F_12 ( L_23 ,
F_78 ( V_74 ) ,
F_56 ( V_74 ) ) ;
F_12 ( L_24 , F_79 ( V_74 ) ) ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 , struct V_170 * V_171 )
{
int V_3 ;
for ( V_3 = 1 ; V_3 < F_102 ( V_2 -> V_4 . V_94 ) ; V_3 ++ )
V_2 -> V_4 . V_94 [ V_3 ] = V_171 -> V_172 [ V_3 ] ;
V_2 -> V_4 . V_94 [ 0 ] = 0 ;
V_2 -> V_4 . V_96 = V_171 -> V_96 ;
V_2 -> V_4 . V_98 = V_171 -> V_98 ;
V_2 -> V_4 . V_100 = V_171 -> V_100 ;
return 0 ;
}
int F_123 ( struct V_1 * V_2 , struct V_170 * V_171 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_102 ( V_2 -> V_4 . V_94 ) ; V_3 ++ )
V_171 -> V_172 [ V_3 ] = V_2 -> V_4 . V_94 [ V_3 ] ;
V_171 -> V_96 = V_2 -> V_4 . V_96 ;
V_171 -> V_98 = V_2 -> V_4 . V_98 ;
V_171 -> V_100 = V_2 -> V_4 . V_100 ;
return 0 ;
}
static void F_124 ( unsigned long V_173 )
{
struct V_1 * V_2 = (struct V_1 * ) V_173 ;
V_13 -> V_174 ( V_2 ) ;
V_2 -> V_4 . V_83 = 0 ;
if ( F_64 ( & V_2 -> V_84 ) )
F_65 ( & V_2 -> V_84 ) ;
}
static enum V_175 F_125 ( struct V_176 * V_177 )
{
struct V_1 * V_2 ;
V_2 = F_126 ( V_177 , struct V_1 , V_4 . V_62 ) ;
F_124 ( ( unsigned long ) V_2 ) ;
return F_127 ( V_2 ) ;
}
int F_128 ( struct V_1 * V_2 )
{
V_13 -> V_178 ( V_2 ) ;
F_129 ( & V_2 -> V_4 . V_62 , V_179 ,
V_180 ) ;
V_2 -> V_4 . V_62 . V_181 = F_125 ;
return 0 ;
}
int F_130 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
return 0 ;
}
int F_131 ( struct V_1 * V_2 )
{
return V_13 -> V_184 ( V_2 ) ;
}
static void F_132 ( void )
{
T_7 V_185 = F_133 () ;
if ( V_186 )
V_185 |= ( V_187 ) ;
F_134 ( V_185 ) ;
F_135 () ;
}
int F_136 ( struct V_65 * V_66 , struct V_1 * V_2 )
{
T_7 V_188 = V_2 -> V_4 . V_189 ;
T_7 V_190 = ( V_188 >> V_191 ) & 0x1f ;
T_7 T_4 * V_192 = ( T_7 T_4 * ) V_2 -> V_4 . V_100 ;
unsigned long V_193 = V_2 -> V_4 . V_194 ;
enum V_195 V_196 = V_197 ;
int V_90 = V_198 ;
F_60 () ;
V_66 -> V_199 = V_200 ;
V_66 -> V_201 = 1 ;
F_132 () ;
F_62 () ;
F_12 ( L_25 ,
V_188 , V_192 , V_66 , V_2 ) ;
V_196 = F_137 ( V_188 , V_192 , V_66 , V_2 ) ;
if ( V_196 == V_202 ) {
goto V_203;
} else if ( V_196 == V_204 ) {
V_66 -> V_199 = V_205 ;
V_90 = V_206 ;
goto V_203;
}
switch ( V_190 ) {
case V_207 :
F_12 ( L_26 , V_2 -> V_148 , V_192 ) ;
++ V_2 -> V_208 . V_209 ;
F_138 ( V_2 , V_210 ) ;
if ( F_139 () )
F_140 () ;
V_90 = V_198 ;
break;
case V_211 :
F_12 ( L_27 , V_192 ) ;
++ V_2 -> V_208 . V_212 ;
F_138 ( V_2 , V_213 ) ;
V_90 = V_13 -> V_214 ( V_2 ) ;
if ( V_66 -> V_199 == V_215 )
V_90 = V_206 ;
break;
case V_216 :
++ V_2 -> V_208 . V_217 ;
F_138 ( V_2 , V_218 ) ;
V_90 = V_13 -> V_219 ( V_2 ) ;
break;
case V_220 :
F_12 ( L_28 ,
V_188 , F_78 ( V_2 -> V_4 . V_74 ) , V_192 ,
V_193 ) ;
++ V_2 -> V_208 . V_221 ;
F_138 ( V_2 , V_222 ) ;
V_90 = V_13 -> V_223 ( V_2 ) ;
break;
case V_224 :
F_12 ( L_29 ,
V_188 , V_192 , V_193 ) ;
++ V_2 -> V_208 . V_225 ;
F_138 ( V_2 , V_226 ) ;
V_90 = V_13 -> V_227 ( V_2 ) ;
break;
case V_228 :
++ V_2 -> V_208 . V_229 ;
F_138 ( V_2 , V_230 ) ;
V_90 = V_13 -> V_231 ( V_2 ) ;
break;
case V_232 :
++ V_2 -> V_208 . V_233 ;
F_138 ( V_2 , V_234 ) ;
V_90 = V_13 -> V_235 ( V_2 ) ;
break;
case V_236 :
++ V_2 -> V_208 . V_237 ;
F_138 ( V_2 , V_238 ) ;
V_90 = V_13 -> V_239 ( V_2 ) ;
break;
case V_240 :
++ V_2 -> V_208 . V_241 ;
F_138 ( V_2 , V_242 ) ;
V_90 = V_13 -> V_243 ( V_2 ) ;
break;
case V_244 :
++ V_2 -> V_208 . V_245 ;
F_138 ( V_2 , V_246 ) ;
V_90 = V_13 -> V_247 ( V_2 ) ;
break;
default:
F_36 ( L_30 ,
V_190 , V_192 , F_141 ( V_192 , V_2 ) , V_193 ,
F_78 ( V_2 -> V_4 . V_74 ) ) ;
F_121 ( V_2 ) ;
V_66 -> V_199 = V_205 ;
V_90 = V_206 ;
break;
}
V_203:
F_54 () ;
if ( V_196 == V_197 && ! ( V_90 & V_206 ) )
F_55 ( V_2 , V_188 ) ;
if ( ! ( V_90 & V_206 ) ) {
if ( F_142 ( V_248 ) ) {
V_66 -> V_199 = V_249 ;
V_90 = ( - V_250 << 2 ) | V_206 ;
++ V_2 -> V_208 . V_251 ;
F_138 ( V_2 , V_252 ) ;
}
}
F_58 () ;
return V_90 ;
}
int T_8 F_143 ( void )
{
int V_90 ;
V_90 = F_144 ( NULL , sizeof( struct V_1 ) , 0 , V_253 ) ;
if ( V_90 )
return V_90 ;
V_254 = V_255 ;
F_19 = V_256 ;
V_257 = V_258 ;
F_145 ( L_31 ) ;
return 0 ;
}
void T_9 F_146 ( void )
{
F_147 () ;
V_254 = NULL ;
F_19 = NULL ;
V_257 = NULL ;
F_145 ( L_32 ) ;
}
