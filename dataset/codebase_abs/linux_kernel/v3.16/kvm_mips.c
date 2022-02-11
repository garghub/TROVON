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
int F_5 ( void * V_8 )
{
return 0 ;
}
void F_6 ( void * V_8 )
{
}
int F_7 ( void )
{
return 0 ;
}
void F_8 ( void )
{
}
void F_9 ( void * V_9 )
{
int * V_10 = ( int * ) V_9 ;
* V_10 = 0 ;
return;
}
static void F_10 ( struct V_11 * V_11 )
{
unsigned long V_12 ;
V_12 = F_11 () ;
F_12 ( V_12 + 1 ) ;
F_13 () ;
V_11 -> V_4 . V_13 = V_12 ;
F_14 ( L_1 , F_15 () ,
V_11 -> V_4 . V_13 ) ;
}
static void F_16 ( void * V_14 )
{
struct V_11 * V_11 = (struct V_11 * ) V_14 ;
F_10 ( V_11 ) ;
V_15 -> V_16 ( V_11 ) ;
}
int F_17 ( struct V_11 * V_11 , unsigned long type )
{
if ( F_18 ( & V_17 ) == 1 ) {
F_14 ( L_2 ,
V_18 ) ;
F_19 ( F_16 , V_11 , 1 ) ;
}
return 0 ;
}
void F_20 ( struct V_11 * V_11 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
for ( V_3 = 0 ; V_3 < V_11 -> V_4 . V_19 ; V_3 ++ ) {
if ( V_11 -> V_4 . V_20 [ V_3 ] != V_21 )
F_21 ( V_11 -> V_4 . V_20 [ V_3 ] ) ;
}
F_22 ( V_11 -> V_4 . V_20 ) ;
F_23 (i, vcpu, kvm) {
F_24 ( V_2 ) ;
}
F_25 ( & V_11 -> V_22 ) ;
for ( V_3 = 0 ; V_3 < F_26 ( & V_11 -> V_23 ) ; V_3 ++ )
V_11 -> V_24 [ V_3 ] = NULL ;
F_27 ( & V_11 -> V_23 , 0 ) ;
F_28 ( & V_11 -> V_22 ) ;
}
void F_29 ( struct V_11 * V_11 )
{
}
static void F_30 ( void * V_14 )
{
F_12 ( 0 ) ;
F_13 () ;
F_31 () ;
}
void F_32 ( struct V_11 * V_11 )
{
F_20 ( V_11 ) ;
if ( F_33 ( & V_17 ) == 0 ) {
F_14 ( L_3 ,
V_18 ) ;
F_19 ( F_30 , NULL , 1 ) ;
}
}
long
F_34 ( struct V_25 * V_26 , unsigned int V_27 , unsigned long V_14 )
{
return - V_28 ;
}
void F_35 ( struct V_11 * V_11 , struct V_29 * free ,
struct V_29 * V_30 )
{
}
int F_36 ( struct V_11 * V_11 , struct V_29 * V_31 ,
unsigned long V_32 )
{
return 0 ;
}
void F_37 ( struct V_11 * V_11 )
{
}
int F_38 ( struct V_11 * V_11 ,
struct V_29 * V_33 ,
struct V_34 * V_35 ,
enum V_36 V_37 )
{
return 0 ;
}
void F_39 ( struct V_11 * V_11 ,
struct V_34 * V_35 ,
const struct V_29 * V_38 ,
enum V_36 V_37 )
{
unsigned long V_32 = 0 ;
int V_3 , V_39 = 0 ;
F_14 ( L_4 ,
V_18 , V_11 , V_35 -> V_31 , V_35 -> V_40 ,
V_35 -> V_41 , V_35 -> V_42 ) ;
if ( ! V_11 -> V_4 . V_20 ) {
if ( V_35 -> V_31 == 0 )
V_32 = V_35 -> V_41 >> V_43 ;
if ( V_32 ) {
V_11 -> V_4 . V_19 = V_32 ;
V_11 -> V_4 . V_20 =
F_40 ( V_32 * sizeof( unsigned long ) , V_44 ) ;
if ( ! V_11 -> V_4 . V_20 ) {
F_41 ( L_5 ) ;
V_39 = - V_45 ;
goto V_46;
}
F_14 ( L_6 ,
V_32 , V_11 -> V_4 . V_20 ) ;
for ( V_3 = 0 ; V_3 < V_32 ; V_3 ++ ) {
V_11 -> V_4 . V_20 [ V_3 ] = V_21 ;
}
}
}
V_46:
return;
}
void F_42 ( struct V_11 * V_11 )
{
}
void F_43 ( struct V_11 * V_11 ,
struct V_29 * V_31 )
{
}
void F_44 ( struct V_11 * V_11 )
{
}
struct V_1 * F_45 ( struct V_11 * V_11 , unsigned int V_47 )
{
extern char V_48 [] , V_49 [] ;
extern char V_50 [] , V_51 [] ;
int V_39 , V_52 , V_53 ;
void * V_54 ;
int V_3 ;
struct V_1 * V_2 = F_40 ( sizeof( struct V_1 ) , V_44 ) ;
if ( ! V_2 ) {
V_39 = - V_45 ;
goto V_46;
}
V_39 = F_46 ( V_2 , V_11 , V_47 ) ;
if ( V_39 )
goto V_55;
F_14 ( L_7 , V_11 , V_47 , V_2 ) ;
if ( V_56 || V_57 ) {
V_52 = 0x200 + V_58 * 64 ;
} else {
V_52 = 0x4000 ;
}
V_2 -> V_4 . V_59 = ( void * ) F_47 () ;
V_54 = F_40 ( F_48 ( V_52 , V_60 ) , V_44 ) ;
if ( ! V_54 ) {
V_39 = - V_45 ;
goto V_55;
}
F_14 ( L_8 ,
F_48 ( V_52 , V_60 ) , V_54 ) ;
V_2 -> V_4 . V_61 = V_54 ;
memcpy ( V_54 , V_48 ,
V_49 - V_48 ) ;
memcpy ( V_54 + 0x180 , V_48 ,
V_49 - V_48 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
F_14 ( L_9 ,
V_54 + 0x200 + ( V_3 * V_58 ) ) ;
memcpy ( V_54 + 0x200 + ( V_3 * V_58 ) , V_48 ,
V_49 - V_48 ) ;
}
V_53 = 0x2000 ;
F_14 ( L_10 ,
V_54 + V_53 ,
V_51 - V_50 ) ;
memcpy ( V_54 + V_53 , V_50 ,
V_51 - V_50 ) ;
F_49 ( ( unsigned long ) V_54 ,
( unsigned long ) V_54 + F_48 ( V_52 , V_60 ) ) ;
V_2 -> V_4 . V_62 = F_40 ( V_60 << 1 , V_44 ) ;
if ( ! V_2 -> V_4 . V_62 ) {
V_39 = - V_45 ;
goto V_63;
}
F_14 ( L_11 , V_2 -> V_4 . V_62 ) ;
F_50 ( V_2 ) ;
V_2 -> V_4 . V_64 = - 1 ;
F_51 ( V_2 ) ;
return V_2 ;
V_63:
F_22 ( V_54 ) ;
V_55:
F_22 ( V_2 ) ;
V_46:
return F_52 ( V_39 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
F_53 ( & V_2 -> V_4 . V_65 ) ;
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
F_22 ( V_2 -> V_4 . V_61 ) ;
F_22 ( V_2 -> V_4 . V_62 ) ;
F_22 ( V_2 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
}
int
F_57 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
return - V_28 ;
}
int F_58 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
int V_10 = 0 ;
T_1 V_70 ;
if ( V_2 -> V_71 )
F_59 ( V_72 , & V_2 -> V_73 , & V_70 ) ;
if ( V_2 -> V_74 ) {
if ( ! V_2 -> V_75 )
F_60 ( V_2 , V_69 ) ;
V_2 -> V_74 = 0 ;
}
F_61 () ;
F_62 ( V_2 ,
F_63 ( V_2 -> V_4 . V_76 ) ) ;
F_64 () ;
V_10 = F_65 ( V_69 , V_2 ) ;
F_66 () ;
F_67 () ;
if ( V_2 -> V_71 )
F_59 ( V_72 , & V_70 , NULL ) ;
return V_10 ;
}
int
F_68 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
int V_79 = ( int ) V_78 -> V_78 ;
struct V_1 * V_80 = NULL ;
if ( V_79 == 3 || V_79 == - 3 || V_79 == 4 || V_79 == - 4 )
F_14 ( L_12 , V_18 , V_78 -> V_81 ,
( int ) V_79 ) ;
if ( V_78 -> V_81 == - 1 )
V_80 = V_2 ;
else
V_80 = V_2 -> V_11 -> V_24 [ V_78 -> V_81 ] ;
if ( V_79 == 2 || V_79 == 3 || V_79 == 4 ) {
V_15 -> V_82 ( V_80 , V_78 ) ;
} else if ( V_79 == - 2 || V_79 == - 3 || V_79 == - 4 ) {
V_15 -> V_83 ( V_80 , V_78 ) ;
} else {
F_41 ( L_13 , V_18 ,
V_78 -> V_81 , V_78 -> V_78 ) ;
return - V_84 ;
}
V_80 -> V_4 . V_85 = 0 ;
if ( F_69 ( & V_80 -> V_86 ) ) {
F_70 ( & V_80 -> V_86 ) ;
}
return 0 ;
}
int
F_71 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
return - V_28 ;
}
int
F_72 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
return - V_28 ;
}
static int F_73 ( struct V_1 * V_2 ,
const struct V_89 * V_90 )
{
struct V_91 * V_76 = V_2 -> V_4 . V_76 ;
int V_92 ;
T_2 V_93 ;
switch ( V_90 -> V_47 ) {
case V_94 ... V_95 :
V_93 = ( long ) V_2 -> V_4 . V_96 [ V_90 -> V_47 - V_94 ] ;
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
V_93 = ( long ) F_74 ( V_76 ) ;
break;
case V_104 :
V_93 = ( long ) F_75 ( V_76 ) ;
break;
case V_105 :
V_93 = ( long ) F_76 ( V_76 ) ;
break;
case V_106 :
V_93 = ( long ) F_77 ( V_76 ) ;
break;
case V_107 :
V_93 = ( long ) F_78 ( V_76 ) ;
break;
case V_108 :
V_93 = ( long ) F_79 ( V_76 ) ;
break;
case V_109 :
V_93 = ( long ) F_80 ( V_76 ) ;
break;
case V_110 :
V_93 = ( long ) F_81 ( V_76 ) ;
break;
case V_111 :
V_93 = ( long ) F_82 ( V_76 ) ;
break;
case V_112 :
V_93 = ( long ) F_83 ( V_76 ) ;
break;
case V_113 :
V_93 = ( long ) F_63 ( V_76 ) ;
break;
case V_114 :
V_93 = ( long ) F_84 ( V_76 ) ;
break;
case V_115 :
V_93 = ( long ) F_85 ( V_76 ) ;
break;
case V_116 :
V_93 = ( long ) F_86 ( V_76 ) ;
break;
case V_117 :
V_93 = ( long ) F_87 ( V_76 ) ;
break;
case V_118 :
V_93 = ( long ) F_88 ( V_76 ) ;
break;
case V_119 :
V_93 = ( long ) F_89 ( V_76 ) ;
break;
case V_120 :
V_93 = ( long ) F_90 ( V_76 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
V_92 = V_15 -> V_125 ( V_2 , V_90 , & V_93 ) ;
if ( V_92 )
return V_92 ;
break;
default:
return - V_84 ;
}
if ( ( V_90 -> V_47 & V_126 ) == V_127 ) {
T_3 T_4 * V_128 = ( T_3 T_4 * ) ( long ) V_90 -> V_129 ;
return F_91 ( V_93 , V_128 ) ;
} else if ( ( V_90 -> V_47 & V_126 ) == V_130 ) {
T_5 T_4 * V_131 = ( T_5 T_4 * ) ( long ) V_90 -> V_129 ;
T_5 V_132 = ( T_5 ) V_93 ;
return F_91 ( V_132 , V_131 ) ;
} else {
return - V_84 ;
}
}
static int F_92 ( struct V_1 * V_2 ,
const struct V_89 * V_90 )
{
struct V_91 * V_76 = V_2 -> V_4 . V_76 ;
T_3 V_93 ;
if ( ( V_90 -> V_47 & V_126 ) == V_127 ) {
T_3 T_4 * V_128 = ( T_3 T_4 * ) ( long ) V_90 -> V_129 ;
if ( F_93 ( V_93 , V_128 ) != 0 )
return - V_133 ;
} else if ( ( V_90 -> V_47 & V_126 ) == V_130 ) {
T_5 T_4 * V_131 = ( T_5 T_4 * ) ( long ) V_90 -> V_129 ;
T_6 V_132 ;
if ( F_93 ( V_132 , V_131 ) != 0 )
return - V_133 ;
V_93 = ( T_2 ) V_132 ;
} else {
return - V_84 ;
}
switch ( V_90 -> V_47 ) {
case V_94 :
break;
case V_134 ... V_95 :
V_2 -> V_4 . V_96 [ V_90 -> V_47 - V_94 ] = V_93 ;
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
F_94 ( V_76 , V_93 ) ;
break;
case V_104 :
F_95 ( V_76 , V_93 ) ;
break;
case V_105 :
F_96 ( V_76 , V_93 ) ;
break;
case V_106 :
F_97 ( V_76 , V_93 ) ;
break;
case V_107 :
F_98 ( V_76 , V_93 ) ;
break;
case V_108 :
F_99 ( V_76 , V_93 ) ;
break;
case V_109 :
F_100 ( V_76 , V_93 ) ;
break;
case V_110 :
F_101 ( V_76 , V_93 ) ;
break;
case V_112 :
F_102 ( V_76 , V_93 ) ;
break;
case V_114 :
F_103 ( V_76 , V_93 ) ;
break;
case V_115 :
F_104 ( V_76 , V_93 ) ;
break;
case V_121 :
case V_111 :
case V_113 :
case V_122 :
case V_123 :
case V_124 :
return V_15 -> V_135 ( V_2 , V_90 , V_93 ) ;
default:
return - V_84 ;
}
return 0 ;
}
long
F_105 ( struct V_25 * V_26 , unsigned int V_27 , unsigned long V_14 )
{
struct V_1 * V_2 = V_26 -> V_136 ;
void T_4 * V_137 = ( void T_4 * ) V_14 ;
long V_10 ;
switch ( V_27 ) {
case V_138 :
case V_139 : {
struct V_89 V_90 ;
if ( F_106 ( & V_90 , V_137 , sizeof( V_90 ) ) )
return - V_133 ;
if ( V_27 == V_138 )
return F_92 ( V_2 , & V_90 ) ;
else
return F_73 ( V_2 , & V_90 ) ;
}
case V_140 : {
struct V_141 T_4 * V_142 = V_137 ;
T_3 T_4 * V_143 ;
struct V_141 V_144 ;
unsigned V_145 ;
if ( F_106 ( & V_144 , V_142 , sizeof( V_144 ) ) )
return - V_133 ;
V_145 = V_144 . V_145 ;
V_144 . V_145 = F_107 ( V_146 ) ;
if ( F_108 ( V_142 , & V_144 , sizeof( V_144 ) ) )
return - V_133 ;
if ( V_145 < V_144 . V_145 )
return - V_147 ;
V_143 = V_142 -> V_90 ;
if ( F_108 ( V_143 , V_146 ,
sizeof( V_146 ) ) )
return - V_133 ;
return 0 ;
}
case V_148 :
V_10 = F_1 ( V_2 ) ;
break;
case V_149 :
{
struct V_77 V_78 ;
V_10 = - V_133 ;
if ( F_106 ( & V_78 , V_137 , sizeof( V_78 ) ) )
goto V_46;
F_14 ( L_14 , V_2 -> V_150 , V_18 ,
V_78 . V_78 ) ;
V_10 = F_68 ( V_2 , & V_78 ) ;
break;
}
default:
V_10 = - V_28 ;
}
V_46:
return V_10 ;
}
int F_109 ( struct V_11 * V_11 , struct V_151 * log )
{
struct V_29 * V_33 ;
unsigned long V_152 , V_153 ;
int V_154 = 0 ;
int V_10 ;
unsigned long V_145 ;
F_25 ( & V_11 -> V_155 ) ;
V_10 = F_110 ( V_11 , log , & V_154 ) ;
if ( V_10 )
goto V_46;
if ( V_154 ) {
V_33 = & V_11 -> V_156 -> V_156 [ log -> V_31 ] ;
V_152 = V_33 -> V_157 << V_43 ;
V_153 = V_152 + ( V_33 -> V_32 << V_43 ) ;
F_111 ( L_15 , V_18 , V_152 ,
V_153 ) ;
V_145 = F_112 ( V_33 ) ;
memset ( V_33 -> V_158 , 0 , V_145 ) ;
}
V_10 = 0 ;
V_46:
F_28 ( & V_11 -> V_155 ) ;
return V_10 ;
}
long F_113 ( struct V_25 * V_26 , unsigned int V_27 , unsigned long V_14 )
{
long V_10 ;
switch ( V_27 ) {
default:
V_10 = - V_28 ;
}
return V_10 ;
}
int F_114 ( void * V_159 )
{
int V_92 ;
if ( V_15 ) {
F_41 ( L_16 ) ;
return - V_160 ;
}
V_92 = F_115 ( & V_15 ) ;
return V_92 ;
}
void F_116 ( void )
{
V_15 = NULL ;
}
int
F_117 ( struct V_1 * V_2 , struct V_161 * V_162 )
{
return - V_28 ;
}
int
F_118 ( struct V_1 * V_2 , struct V_161 * V_162 )
{
return - V_28 ;
}
int F_119 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_120 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
return - V_28 ;
}
int F_121 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
return - V_28 ;
}
int F_122 ( struct V_1 * V_2 , struct V_165 * V_166 )
{
return V_167 ;
}
int F_123 ( long V_168 )
{
int V_10 ;
switch ( V_168 ) {
case V_169 :
V_10 = 1 ;
break;
case V_170 :
V_10 = V_171 ;
break;
default:
V_10 = 0 ;
break;
}
return V_10 ;
}
int F_124 ( struct V_1 * V_2 )
{
return F_125 ( V_2 ) ;
}
int F_126 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_91 * V_76 ;
if ( ! V_2 )
return - 1 ;
F_111 ( L_17 ) ;
F_111 ( L_18 , V_2 -> V_4 . V_102 ) ;
F_111 ( L_19 , V_2 -> V_4 . V_7 ) ;
for ( V_3 = 0 ; V_3 < 32 ; V_3 += 4 ) {
F_111 ( L_20 , V_3 ,
V_2 -> V_4 . V_96 [ V_3 ] ,
V_2 -> V_4 . V_96 [ V_3 + 1 ] ,
V_2 -> V_4 . V_96 [ V_3 + 2 ] , V_2 -> V_4 . V_96 [ V_3 + 3 ] ) ;
}
F_111 ( L_21 , V_2 -> V_4 . V_98 ) ;
F_111 ( L_22 , V_2 -> V_4 . V_100 ) ;
V_76 = V_2 -> V_4 . V_76 ;
F_111 ( L_23 ,
F_83 ( V_76 ) , F_63 ( V_76 ) ) ;
F_111 ( L_24 , F_84 ( V_76 ) ) ;
return 0 ;
}
int F_127 ( struct V_1 * V_2 , struct V_172 * V_173 )
{
int V_3 ;
for ( V_3 = 1 ; V_3 < F_107 ( V_2 -> V_4 . V_96 ) ; V_3 ++ )
V_2 -> V_4 . V_96 [ V_3 ] = V_173 -> V_174 [ V_3 ] ;
V_2 -> V_4 . V_96 [ 0 ] = 0 ;
V_2 -> V_4 . V_98 = V_173 -> V_98 ;
V_2 -> V_4 . V_100 = V_173 -> V_100 ;
V_2 -> V_4 . V_102 = V_173 -> V_102 ;
return 0 ;
}
int F_128 ( struct V_1 * V_2 , struct V_172 * V_173 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_107 ( V_2 -> V_4 . V_96 ) ; V_3 ++ )
V_173 -> V_174 [ V_3 ] = V_2 -> V_4 . V_96 [ V_3 ] ;
V_173 -> V_98 = V_2 -> V_4 . V_98 ;
V_173 -> V_100 = V_2 -> V_4 . V_100 ;
V_173 -> V_102 = V_2 -> V_4 . V_102 ;
return 0 ;
}
static void F_129 ( unsigned long V_175 )
{
struct V_1 * V_2 = (struct V_1 * ) V_175 ;
V_15 -> V_176 ( V_2 ) ;
V_2 -> V_4 . V_85 = 0 ;
if ( F_69 ( & V_2 -> V_86 ) ) {
F_70 ( & V_2 -> V_86 ) ;
}
}
static enum V_177 F_130 ( struct V_178 * V_179 )
{
struct V_1 * V_2 ;
V_2 = F_131 ( V_179 , struct V_1 , V_4 . V_65 ) ;
F_129 ( ( unsigned long ) V_2 ) ;
return F_132 ( V_2 ) ;
}
int F_133 ( struct V_1 * V_2 )
{
V_15 -> V_180 ( V_2 ) ;
F_134 ( & V_2 -> V_4 . V_65 , V_181 ,
V_182 ) ;
V_2 -> V_4 . V_65 . V_183 = F_130 ;
return 0 ;
}
void F_135 ( struct V_1 * V_2 )
{
return;
}
int
F_136 ( struct V_1 * V_2 , struct V_184 * V_185 )
{
return 0 ;
}
int F_137 ( struct V_1 * V_2 )
{
return V_15 -> V_186 ( V_2 ) ;
}
static
void F_138 ( void )
{
T_7 V_187 = F_139 () ;
if ( V_188 )
V_187 |= ( V_189 ) ;
if ( V_190 )
V_187 |= ( V_191 ) ;
F_140 ( V_187 ) ;
F_141 () ;
}
int F_142 ( struct V_68 * V_69 , struct V_1 * V_2 )
{
T_7 V_192 = V_2 -> V_4 . V_193 ;
T_7 V_194 = ( V_192 >> V_195 ) & 0x1f ;
T_7 T_4 * V_196 = ( T_7 T_4 * ) V_2 -> V_4 . V_102 ;
unsigned long V_197 = V_2 -> V_4 . V_198 ;
enum V_199 V_200 = V_201 ;
int V_92 = V_202 ;
V_69 -> V_203 = V_204 ;
V_69 -> V_205 = 1 ;
F_138 () ;
F_67 () ;
F_14 ( L_25 ,
V_192 , V_196 , V_69 , V_2 ) ;
V_200 = F_143 ( V_192 , V_196 , V_69 , V_2 ) ;
if ( V_200 == V_206 ) {
goto V_207;
} else if ( V_200 == V_208 ) {
V_69 -> V_203 = V_209 ;
V_92 = V_210 ;
goto V_207;
}
switch ( V_194 ) {
case V_211 :
F_14 ( L_26 , V_2 -> V_150 , V_196 ) ;
++ V_2 -> V_212 . V_213 ;
F_144 ( V_2 , V_214 ) ;
if ( F_145 () ) {
F_146 () ;
}
V_92 = V_202 ;
break;
case V_215 :
F_14 ( L_27 , V_196 ) ;
++ V_2 -> V_212 . V_216 ;
F_144 ( V_2 , V_217 ) ;
V_92 = V_15 -> V_218 ( V_2 ) ;
if ( V_69 -> V_203 == V_219 ) {
V_92 = V_210 ;
}
break;
case V_220 :
++ V_2 -> V_212 . V_221 ;
F_144 ( V_2 , V_222 ) ;
V_92 = V_15 -> V_223 ( V_2 ) ;
break;
case V_224 :
F_14
( L_28 ,
V_192 , F_83 ( V_2 -> V_4 . V_76 ) , V_196 ,
V_197 ) ;
++ V_2 -> V_212 . V_225 ;
F_144 ( V_2 , V_226 ) ;
V_92 = V_15 -> V_227 ( V_2 ) ;
break;
case V_228 :
F_14 ( L_29 ,
V_192 , V_196 , V_197 ) ;
++ V_2 -> V_212 . V_229 ;
F_144 ( V_2 , V_230 ) ;
V_92 = V_15 -> V_231 ( V_2 ) ;
break;
case V_232 :
++ V_2 -> V_212 . V_233 ;
F_144 ( V_2 , V_234 ) ;
V_92 = V_15 -> V_235 ( V_2 ) ;
break;
case V_236 :
++ V_2 -> V_212 . V_237 ;
F_144 ( V_2 , V_238 ) ;
V_92 = V_15 -> V_239 ( V_2 ) ;
break;
case V_240 :
++ V_2 -> V_212 . V_241 ;
F_144 ( V_2 , V_242 ) ;
V_92 = V_15 -> V_243 ( V_2 ) ;
break;
case V_244 :
++ V_2 -> V_212 . V_245 ;
F_144 ( V_2 , V_246 ) ;
V_92 = V_15 -> V_247 ( V_2 ) ;
break;
case V_248 :
++ V_2 -> V_212 . V_249 ;
F_144 ( V_2 , V_250 ) ;
V_92 = V_15 -> V_251 ( V_2 ) ;
break;
default:
F_41
( L_30 ,
V_194 , V_196 , F_147 ( V_196 , V_2 ) , V_197 ,
F_83 ( V_2 -> V_4 . V_76 ) ) ;
F_126 ( V_2 ) ;
V_69 -> V_203 = V_209 ;
V_92 = V_210 ;
break;
}
V_207:
F_61 () ;
if ( V_200 == V_201 && ! ( V_92 & V_210 ) )
F_62 ( V_2 , V_192 ) ;
if ( ! ( V_92 & V_210 ) ) {
if ( F_148 ( V_252 ) ) {
V_69 -> V_203 = V_253 ;
V_92 = ( - V_254 << 2 ) | V_210 ;
++ V_2 -> V_212 . V_255 ;
F_144 ( V_2 , V_256 ) ;
}
}
return V_92 ;
}
int T_8 F_149 ( void )
{
int V_92 ;
V_92 = F_150 ( NULL , sizeof( struct V_1 ) , 0 , V_257 ) ;
if ( V_92 )
return V_92 ;
V_258 = V_259 ;
F_21 = V_260 ;
V_261 = V_262 ;
F_151 ( L_31 ) ;
return 0 ;
}
void T_9 F_152 ( void )
{
F_153 () ;
V_258 = NULL ;
F_21 = NULL ;
V_261 = NULL ;
F_151 ( L_32 ) ;
}
