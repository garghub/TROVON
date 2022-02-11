static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 (i) {
V_2 -> V_4 . V_5 [ V_3 ] = 0 ;
V_2 -> V_4 . V_6 [ V_3 ] = 0 ;
}
return 0 ;
}
T_1 F_3 ( struct V_7 * V_7 , T_1 V_8 )
{
return V_8 ;
}
int F_4 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_4 . V_9 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
return 1 ;
}
int F_6 ( void * V_10 )
{
return 0 ;
}
void F_7 ( void * V_10 )
{
}
int F_8 ( void )
{
return 0 ;
}
void F_9 ( void )
{
}
void F_10 ( void * V_11 )
{
int * V_12 = ( int * ) V_11 ;
* V_12 = 0 ;
return;
}
static void F_11 ( struct V_7 * V_7 )
{
unsigned long V_13 ;
V_13 = F_12 () ;
F_13 ( V_13 + 1 ) ;
F_14 () ;
V_7 -> V_4 . V_14 = V_13 ;
F_15 ( L_1 , F_16 () ,
V_7 -> V_4 . V_14 ) ;
}
static void F_17 ( void * V_15 )
{
struct V_7 * V_7 = (struct V_7 * ) V_15 ;
F_11 ( V_7 ) ;
V_16 -> V_17 ( V_7 ) ;
}
int F_18 ( struct V_7 * V_7 , unsigned long type )
{
if ( F_19 ( & V_18 ) == 1 ) {
F_20 ( L_2 ,
V_19 ) ;
F_21 ( F_17 , V_7 , 1 ) ;
}
return 0 ;
}
void F_22 ( struct V_7 * V_7 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
for ( V_3 = 0 ; V_3 < V_7 -> V_4 . V_20 ; V_3 ++ ) {
if ( V_7 -> V_4 . V_21 [ V_3 ] != V_22 )
F_23 ( V_7 -> V_4 . V_21 [ V_3 ] ) ;
}
if ( V_7 -> V_4 . V_21 )
F_24 ( V_7 -> V_4 . V_21 ) ;
F_25 (i, vcpu, kvm) {
F_26 ( V_2 ) ;
}
F_27 ( & V_7 -> V_23 ) ;
for ( V_3 = 0 ; V_3 < F_28 ( & V_7 -> V_24 ) ; V_3 ++ )
V_7 -> V_25 [ V_3 ] = NULL ;
F_29 ( & V_7 -> V_24 , 0 ) ;
F_30 ( & V_7 -> V_23 ) ;
}
void F_31 ( struct V_7 * V_7 )
{
}
static void F_32 ( void * V_15 )
{
F_13 ( 0 ) ;
F_14 () ;
F_33 () ;
}
void F_34 ( struct V_7 * V_7 )
{
F_22 ( V_7 ) ;
if ( F_35 ( & V_18 ) == 0 ) {
F_20 ( L_3 ,
V_19 ) ;
F_21 ( F_32 , NULL , 1 ) ;
}
}
long
F_36 ( struct V_26 * V_27 , unsigned int V_28 , unsigned long V_15 )
{
return - V_29 ;
}
void F_37 ( struct V_30 * free ,
struct V_30 * V_31 )
{
}
int F_38 ( struct V_30 * V_32 , unsigned long V_33 )
{
return 0 ;
}
int F_39 ( struct V_7 * V_7 ,
struct V_30 * V_34 ,
struct V_35 * V_36 ,
enum V_37 V_38 )
{
return 0 ;
}
void F_40 ( struct V_7 * V_7 ,
struct V_35 * V_36 ,
const struct V_30 * V_39 ,
enum V_37 V_38 )
{
unsigned long V_33 = 0 ;
int V_3 , V_40 = 0 ;
F_15 ( L_4 ,
V_19 , V_7 , V_36 -> V_32 , V_36 -> V_41 ,
V_36 -> V_42 , V_36 -> V_43 ) ;
if ( ! V_7 -> V_4 . V_21 ) {
if ( V_36 -> V_32 == 0 )
V_33 = V_36 -> V_42 >> V_44 ;
if ( V_33 ) {
V_7 -> V_4 . V_20 = V_33 ;
V_7 -> V_4 . V_21 =
F_41 ( V_33 * sizeof( unsigned long ) , V_45 ) ;
if ( ! V_7 -> V_4 . V_21 ) {
F_42 ( L_5 ) ;
V_40 = - V_46 ;
goto V_47;
}
F_20
( L_6 ,
V_33 , V_7 -> V_4 . V_21 ) ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
V_7 -> V_4 . V_21 [ V_3 ] = V_22 ;
}
}
}
V_47:
return;
}
void F_43 ( struct V_7 * V_7 )
{
}
void F_44 ( struct V_7 * V_7 ,
struct V_30 * V_32 )
{
}
void F_45 ( struct V_7 * V_7 )
{
}
struct V_1 * F_46 ( struct V_7 * V_7 , unsigned int V_48 )
{
extern char V_49 [] , V_50 [] ;
extern char V_51 [] , V_52 [] ;
int V_40 , V_53 , V_54 ;
void * V_55 ;
int V_3 ;
struct V_1 * V_2 = F_41 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_2 ) {
V_40 = - V_46 ;
goto V_47;
}
V_40 = F_47 ( V_2 , V_7 , V_48 ) ;
if ( V_40 )
goto V_56;
F_20 ( L_7 , V_7 , V_48 , V_2 ) ;
if ( V_57 || V_58 ) {
V_53 = 0x200 + V_59 * 64 ;
} else {
V_53 = 0x200 ;
}
V_2 -> V_4 . V_60 = ( void * ) F_48 () ;
V_55 = F_41 ( F_49 ( V_53 , V_61 ) , V_45 ) ;
if ( ! V_55 ) {
V_40 = - V_46 ;
goto V_56;
}
F_20 ( L_8 ,
F_49 ( V_53 , V_61 ) , V_55 ) ;
V_2 -> V_4 . V_62 = V_55 ;
memcpy ( V_55 , V_49 ,
V_50 - V_49 ) ;
memcpy ( V_55 + 0x180 , V_49 ,
V_50 - V_49 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
F_15 ( L_9 ,
V_55 + 0x200 + ( V_3 * V_59 ) ) ;
memcpy ( V_55 + 0x200 + ( V_3 * V_59 ) , V_49 ,
V_50 - V_49 ) ;
}
V_54 = 0x2000 ;
F_20 ( L_10 ,
V_55 + V_54 ,
V_52 - V_51 ) ;
memcpy ( V_55 + V_54 , V_51 ,
V_52 - V_51 ) ;
F_50 ( ( unsigned long ) V_55 , F_49 ( V_53 , V_61 ) ) ;
V_2 -> V_4 . V_63 = F_41 ( V_61 << 1 , V_45 ) ;
if ( ! V_2 -> V_4 . V_63 ) {
V_40 = - V_46 ;
goto V_64;
}
F_20 ( L_11 , V_2 -> V_4 . V_63 ) ;
F_51 ( V_2 ) ;
V_2 -> V_4 . V_65 = - 1 ;
F_52 ( V_2 ) ;
return V_2 ;
V_64:
F_24 ( V_55 ) ;
V_56:
F_24 ( V_2 ) ;
V_47:
return F_53 ( V_40 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_54 ( & V_2 -> V_4 . V_66 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( V_2 -> V_4 . V_62 )
F_24 ( V_2 -> V_4 . V_62 ) ;
if ( V_2 -> V_4 . V_63 )
F_24 ( V_2 -> V_4 . V_63 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
}
int
F_58 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
return - V_29 ;
}
int F_59 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
int V_12 = 0 ;
T_2 V_71 ;
if ( V_2 -> V_72 )
F_60 ( V_73 , & V_2 -> V_74 , & V_71 ) ;
if ( V_2 -> V_75 ) {
if ( ! V_2 -> V_76 )
F_61 ( V_2 , V_70 ) ;
V_2 -> V_75 = 0 ;
}
F_62 ( V_2 ,
F_63 ( V_2 -> V_4 . V_77 ) ) ;
F_64 () ;
F_65 () ;
V_12 = F_66 ( V_70 , V_2 ) ;
F_67 () ;
F_68 () ;
if ( V_2 -> V_72 )
F_60 ( V_73 , & V_71 , NULL ) ;
return V_12 ;
}
int
F_69 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
int V_80 = ( int ) V_79 -> V_79 ;
struct V_1 * V_81 = NULL ;
if ( V_80 == 3 || V_80 == - 3 || V_80 == 4 || V_80 == - 4 )
F_15 ( L_12 , V_19 , V_79 -> V_82 ,
( int ) V_80 ) ;
if ( V_79 -> V_82 == - 1 )
V_81 = V_2 ;
else
V_81 = V_2 -> V_7 -> V_25 [ V_79 -> V_82 ] ;
if ( V_80 == 2 || V_80 == 3 || V_80 == 4 ) {
V_16 -> V_83 ( V_81 , V_79 ) ;
} else if ( V_80 == - 2 || V_80 == - 3 || V_80 == - 4 ) {
V_16 -> V_84 ( V_81 , V_79 ) ;
} else {
F_42 ( L_13 , V_19 ,
V_79 -> V_82 , V_79 -> V_79 ) ;
return - V_85 ;
}
V_81 -> V_4 . V_86 = 0 ;
if ( F_70 ( & V_81 -> V_87 ) ) {
F_71 ( & V_81 -> V_87 ) ;
}
return 0 ;
}
int
F_72 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
return - V_29 ;
}
int
F_73 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
return - V_29 ;
}
static int F_74 ( struct V_1 * V_2 ,
const struct V_90 * V_91 )
{
struct V_92 * V_77 = V_2 -> V_4 . V_77 ;
T_3 V_93 ;
switch ( V_91 -> V_48 ) {
case V_94 ... V_95 :
V_93 = ( long ) V_2 -> V_4 . V_96 [ V_91 -> V_48 - V_94 ] ;
break;
case V_97 :
V_93 = ( long ) V_2 -> V_4 . V_98 ;
break;
case V_99 :
V_93 = ( long ) V_2 -> V_4 . V_100 ;
break;
case V_101 :
V_93 = ( long ) V_2 -> V_4 . V_102 ;
break;
case V_103 :
V_93 = ( long ) F_75 ( V_77 ) ;
break;
case V_104 :
V_93 = ( long ) F_76 ( V_77 ) ;
break;
case V_105 :
V_93 = ( long ) F_77 ( V_77 ) ;
break;
case V_106 :
V_93 = ( long ) F_78 ( V_77 ) ;
break;
case V_107 :
V_93 = ( long ) F_79 ( V_77 ) ;
break;
case V_108 :
V_93 = ( long ) F_80 ( V_77 ) ;
break;
case V_109 :
V_93 = ( long ) F_81 ( V_77 ) ;
break;
case V_110 :
V_93 = ( long ) F_63 ( V_77 ) ;
break;
case V_111 :
V_93 = ( long ) F_82 ( V_77 ) ;
break;
case V_112 :
V_93 = ( long ) F_83 ( V_77 ) ;
break;
case V_113 :
V_93 = ( long ) F_84 ( V_77 ) ;
break;
case V_114 :
V_93 = ( long ) F_85 ( V_77 ) ;
break;
case V_115 :
V_93 = ( long ) F_86 ( V_77 ) ;
break;
case V_116 :
V_93 = ( long ) F_87 ( V_77 ) ;
break;
default:
return - V_85 ;
}
if ( ( V_91 -> V_48 & V_117 ) == V_118 ) {
T_4 T_5 * V_119 = ( T_4 T_5 * ) ( long ) V_91 -> V_120 ;
return F_88 ( V_93 , V_119 ) ;
} else if ( ( V_91 -> V_48 & V_117 ) == V_121 ) {
T_6 T_5 * V_122 = ( T_6 T_5 * ) ( long ) V_91 -> V_120 ;
T_6 V_123 = ( T_6 ) V_93 ;
return F_88 ( V_123 , V_122 ) ;
} else {
return - V_85 ;
}
}
static int F_89 ( struct V_1 * V_2 ,
const struct V_90 * V_91 )
{
struct V_92 * V_77 = V_2 -> V_4 . V_77 ;
T_4 V_93 ;
if ( ( V_91 -> V_48 & V_117 ) == V_118 ) {
T_4 T_5 * V_119 = ( T_4 T_5 * ) ( long ) V_91 -> V_120 ;
if ( F_90 ( V_93 , V_119 ) != 0 )
return - V_124 ;
} else if ( ( V_91 -> V_48 & V_117 ) == V_121 ) {
T_6 T_5 * V_122 = ( T_6 T_5 * ) ( long ) V_91 -> V_120 ;
T_7 V_123 ;
if ( F_90 ( V_123 , V_122 ) != 0 )
return - V_124 ;
V_93 = ( T_3 ) V_123 ;
} else {
return - V_85 ;
}
switch ( V_91 -> V_48 ) {
case V_94 :
break;
case V_125 ... V_95 :
V_2 -> V_4 . V_96 [ V_91 -> V_48 - V_94 ] = V_93 ;
break;
case V_97 :
V_2 -> V_4 . V_98 = V_93 ;
break;
case V_99 :
V_2 -> V_4 . V_100 = V_93 ;
break;
case V_101 :
V_2 -> V_4 . V_102 = V_93 ;
break;
case V_103 :
F_91 ( V_77 , V_93 ) ;
break;
case V_104 :
F_92 ( V_77 , V_93 ) ;
break;
case V_105 :
F_93 ( V_77 , V_93 ) ;
break;
case V_106 :
F_94 ( V_77 , V_93 ) ;
break;
case V_107 :
F_95 ( V_77 , V_93 ) ;
break;
case V_108 :
F_96 ( V_77 , V_93 ) ;
break;
case V_109 :
F_97 ( V_77 , V_93 ) ;
break;
case V_110 :
F_98 ( V_77 , V_93 ) ;
break;
case V_111 :
F_99 ( V_77 , V_93 ) ;
break;
default:
return - V_85 ;
}
return 0 ;
}
long
F_100 ( struct V_26 * V_27 , unsigned int V_28 , unsigned long V_15 )
{
struct V_1 * V_2 = V_27 -> V_126 ;
void T_5 * V_127 = ( void T_5 * ) V_15 ;
long V_12 ;
switch ( V_28 ) {
case V_128 :
case V_129 : {
struct V_90 V_91 ;
if ( F_101 ( & V_91 , V_127 , sizeof( V_91 ) ) )
return - V_124 ;
if ( V_28 == V_128 )
return F_89 ( V_2 , & V_91 ) ;
else
return F_74 ( V_2 , & V_91 ) ;
}
case V_130 : {
struct V_131 T_5 * V_132 = V_127 ;
T_4 T_5 * V_133 ;
struct V_131 V_134 ;
unsigned V_135 ;
if ( F_101 ( & V_134 , V_132 , sizeof( V_134 ) ) )
return - V_124 ;
V_135 = V_134 . V_135 ;
V_134 . V_135 = F_102 ( V_136 ) ;
if ( F_103 ( V_132 , & V_134 , sizeof( V_134 ) ) )
return - V_124 ;
if ( V_135 < V_134 . V_135 )
return - V_137 ;
V_133 = V_132 -> V_91 ;
if ( F_103 ( V_133 , V_136 ,
sizeof( V_136 ) ) )
return - V_124 ;
return 0 ;
}
case V_138 :
V_12 = F_1 ( V_2 ) ;
break;
case V_139 :
{
struct V_78 V_79 ;
V_12 = - V_124 ;
if ( F_101 ( & V_79 , V_127 , sizeof( V_79 ) ) )
goto V_47;
F_15 ( L_14 , V_2 -> V_140 , V_19 ,
V_79 . V_79 ) ;
V_12 = F_69 ( V_2 , & V_79 ) ;
break;
}
default:
V_12 = - V_29 ;
}
V_47:
return V_12 ;
}
int F_104 ( struct V_7 * V_7 , struct V_141 * log )
{
struct V_30 * V_34 ;
unsigned long V_142 , V_143 ;
int V_144 = 0 ;
int V_12 ;
unsigned long V_135 ;
F_27 ( & V_7 -> V_145 ) ;
V_12 = F_105 ( V_7 , log , & V_144 ) ;
if ( V_12 )
goto V_47;
if ( V_144 ) {
V_34 = & V_7 -> V_146 -> V_146 [ log -> V_32 ] ;
V_142 = V_34 -> V_147 << V_44 ;
V_143 = V_142 + ( V_34 -> V_33 << V_44 ) ;
F_106 ( L_15 , V_19 , V_142 ,
V_143 ) ;
V_135 = F_107 ( V_34 ) ;
memset ( V_34 -> V_148 , 0 , V_135 ) ;
}
V_12 = 0 ;
V_47:
F_30 ( & V_7 -> V_145 ) ;
return V_12 ;
}
long F_108 ( struct V_26 * V_27 , unsigned int V_28 , unsigned long V_15 )
{
long V_12 ;
switch ( V_28 ) {
default:
V_12 = - V_29 ;
}
return V_12 ;
}
int F_109 ( void * V_149 )
{
int V_150 ;
if ( V_16 ) {
F_42 ( L_16 ) ;
return - V_151 ;
}
V_150 = F_110 ( & V_16 ) ;
return V_150 ;
}
void F_111 ( void )
{
V_16 = NULL ;
}
int
F_112 ( struct V_1 * V_2 , struct V_152 * V_153 )
{
return - V_29 ;
}
int
F_113 ( struct V_1 * V_2 , struct V_152 * V_153 )
{
return - V_29 ;
}
int F_114 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_115 ( struct V_1 * V_2 , struct V_154 * V_155 )
{
return - V_29 ;
}
int F_116 ( struct V_1 * V_2 , struct V_154 * V_155 )
{
return - V_29 ;
}
int F_117 ( struct V_1 * V_2 , struct V_156 * V_157 )
{
return V_158 ;
}
int F_118 ( long V_159 )
{
int V_12 ;
switch ( V_159 ) {
case V_160 :
V_12 = 1 ;
break;
case V_161 :
V_12 = V_162 ;
break;
default:
V_12 = 0 ;
break;
}
return V_12 ;
}
int F_119 ( struct V_1 * V_2 )
{
return F_120 ( V_2 ) ;
}
int F_121 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_92 * V_77 ;
if ( ! V_2 )
return - 1 ;
F_106 ( L_17 ) ;
F_106 ( L_18 , V_2 -> V_4 . V_102 ) ; ;
F_106 ( L_19 , V_2 -> V_4 . V_9 ) ;
for ( V_3 = 0 ; V_3 < 32 ; V_3 += 4 ) {
F_106 ( L_20 , V_3 ,
V_2 -> V_4 . V_96 [ V_3 ] ,
V_2 -> V_4 . V_96 [ V_3 + 1 ] ,
V_2 -> V_4 . V_96 [ V_3 + 2 ] , V_2 -> V_4 . V_96 [ V_3 + 3 ] ) ;
}
F_106 ( L_21 , V_2 -> V_4 . V_98 ) ;
F_106 ( L_22 , V_2 -> V_4 . V_100 ) ;
V_77 = V_2 -> V_4 . V_77 ;
F_106 ( L_23 ,
F_81 ( V_77 ) , F_63 ( V_77 ) ) ;
F_106 ( L_24 , F_122 ( V_77 ) ) ;
return 0 ;
}
int F_123 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
int V_3 ;
for ( V_3 = 1 ; V_3 < F_102 ( V_2 -> V_4 . V_96 ) ; V_3 ++ )
V_2 -> V_4 . V_96 [ V_3 ] = V_164 -> V_165 [ V_3 ] ;
V_2 -> V_4 . V_96 [ 0 ] = 0 ;
V_2 -> V_4 . V_98 = V_164 -> V_98 ;
V_2 -> V_4 . V_100 = V_164 -> V_100 ;
V_2 -> V_4 . V_102 = V_164 -> V_102 ;
return 0 ;
}
int F_124 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_102 ( V_2 -> V_4 . V_96 ) ; V_3 ++ )
V_164 -> V_165 [ V_3 ] = V_2 -> V_4 . V_96 [ V_3 ] ;
V_164 -> V_98 = V_2 -> V_4 . V_98 ;
V_164 -> V_100 = V_2 -> V_4 . V_100 ;
V_164 -> V_102 = V_2 -> V_4 . V_102 ;
return 0 ;
}
void F_125 ( unsigned long V_166 )
{
struct V_1 * V_2 = (struct V_1 * ) V_166 ;
V_16 -> V_167 ( V_2 ) ;
V_2 -> V_4 . V_86 = 0 ;
if ( F_70 ( & V_2 -> V_87 ) ) {
F_71 ( & V_2 -> V_87 ) ;
}
}
enum V_168 F_126 ( struct V_169 * V_170 )
{
struct V_1 * V_2 ;
V_2 = F_127 ( V_170 , struct V_1 , V_4 . V_66 ) ;
F_125 ( ( unsigned long ) V_2 ) ;
F_128 ( & V_2 -> V_4 . V_66 ,
F_129 ( 0 , F_130 ( 10 ) ) ) ;
return V_171 ;
}
int F_131 ( struct V_1 * V_2 )
{
V_16 -> V_172 ( V_2 ) ;
F_132 ( & V_2 -> V_4 . V_66 , V_173 ,
V_174 ) ;
V_2 -> V_4 . V_66 . V_175 = F_126 ;
F_133 ( V_2 ) ;
return 0 ;
}
void F_134 ( struct V_1 * V_2 )
{
return;
}
int
F_135 ( struct V_1 * V_2 , struct V_176 * V_177 )
{
return 0 ;
}
int F_136 ( struct V_1 * V_2 )
{
return V_16 -> V_178 ( V_2 ) ;
}
static
void F_137 ( void )
{
T_8 V_179 = F_138 () ;
if ( V_180 )
V_179 |= ( V_181 ) ;
if ( V_182 )
V_179 |= ( V_183 ) ;
F_139 ( V_179 ) ;
F_140 () ;
}
int F_141 ( struct V_69 * V_70 , struct V_1 * V_2 )
{
T_8 V_184 = V_2 -> V_4 . V_185 ;
T_8 V_186 = ( V_184 >> V_187 ) & 0x1f ;
T_8 T_5 * V_188 = ( T_8 T_5 * ) V_2 -> V_4 . V_102 ;
unsigned long V_189 = V_2 -> V_4 . V_190 ;
enum V_191 V_192 = V_193 ;
int V_150 = V_194 ;
V_70 -> V_195 = V_196 ;
V_70 -> V_197 = 1 ;
F_137 () ;
F_68 () ;
F_15 ( L_25 ,
V_184 , V_188 , V_70 , V_2 ) ;
V_192 = F_142 ( V_184 , V_188 , V_70 , V_2 ) ;
if ( V_192 == V_198 ) {
goto V_199;
} else if ( V_192 == V_200 ) {
V_70 -> V_195 = V_201 ;
V_150 = V_202 ;
goto V_199;
}
switch ( V_186 ) {
case V_203 :
F_15 ( L_26 , V_2 -> V_140 , V_188 ) ;
++ V_2 -> V_204 . V_205 ;
F_143 ( V_2 , V_206 ) ;
if ( F_144 () ) {
F_145 () ;
}
V_150 = V_194 ;
break;
case V_207 :
F_15 ( L_27 , V_188 ) ;
++ V_2 -> V_204 . V_208 ;
F_143 ( V_2 , V_209 ) ;
V_150 = V_16 -> V_210 ( V_2 ) ;
if ( V_70 -> V_195 == V_211 ) {
V_150 = V_202 ;
}
break;
case V_212 :
++ V_2 -> V_204 . V_213 ;
F_143 ( V_2 , V_214 ) ;
V_150 = V_16 -> V_215 ( V_2 ) ;
break;
case V_216 :
F_15
( L_28 ,
V_184 , F_81 ( V_2 -> V_4 . V_77 ) , V_188 ,
V_189 ) ;
++ V_2 -> V_204 . V_217 ;
F_143 ( V_2 , V_218 ) ;
V_150 = V_16 -> V_219 ( V_2 ) ;
break;
case V_220 :
F_15 ( L_29 ,
V_184 , V_188 , V_189 ) ;
++ V_2 -> V_204 . V_221 ;
F_143 ( V_2 , V_222 ) ;
V_150 = V_16 -> V_223 ( V_2 ) ;
break;
case V_224 :
++ V_2 -> V_204 . V_225 ;
F_143 ( V_2 , V_226 ) ;
V_150 = V_16 -> V_227 ( V_2 ) ;
break;
case V_228 :
++ V_2 -> V_204 . V_229 ;
F_143 ( V_2 , V_230 ) ;
V_150 = V_16 -> V_231 ( V_2 ) ;
break;
case V_232 :
++ V_2 -> V_204 . V_233 ;
F_143 ( V_2 , V_234 ) ;
V_150 = V_16 -> V_235 ( V_2 ) ;
break;
case V_236 :
++ V_2 -> V_204 . V_237 ;
F_143 ( V_2 , V_238 ) ;
V_150 = V_16 -> V_239 ( V_2 ) ;
break;
case V_240 :
++ V_2 -> V_204 . V_241 ;
F_143 ( V_2 , V_242 ) ;
V_150 = V_16 -> V_243 ( V_2 ) ;
break;
default:
F_42
( L_30 ,
V_186 , V_188 , F_146 ( V_188 , V_2 ) , V_189 ,
F_81 ( V_2 -> V_4 . V_77 ) ) ;
F_121 ( V_2 ) ;
V_70 -> V_195 = V_201 ;
V_150 = V_202 ;
break;
}
V_199:
F_64 () ;
if ( V_192 == V_193 && ! ( V_150 & V_202 ) )
F_62 ( V_2 , V_184 ) ;
if ( ! ( V_150 & V_202 ) ) {
if ( F_147 ( V_244 ) ) {
V_70 -> V_195 = V_245 ;
V_150 = ( - V_246 << 2 ) | V_202 ;
++ V_2 -> V_204 . V_247 ;
F_143 ( V_2 , V_248 ) ;
}
}
return V_150 ;
}
int T_9 F_148 ( void )
{
int V_150 ;
V_150 = F_149 ( NULL , sizeof( struct V_1 ) , 0 , V_249 ) ;
if ( V_150 )
return V_150 ;
V_250 = V_251 ;
F_23 = V_252 ;
V_253 = V_254 ;
F_150 ( L_31 ) ;
return 0 ;
}
void T_10 F_151 ( void )
{
F_152 () ;
V_250 = NULL ;
F_23 = NULL ;
V_253 = NULL ;
F_150 ( L_32 ) ;
}
