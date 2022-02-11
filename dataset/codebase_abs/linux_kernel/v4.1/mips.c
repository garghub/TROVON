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
struct V_90 * V_91 = & V_2 -> V_4 . V_91 ;
int V_92 ;
T_2 V_93 ;
T_2 V_94 [ 2 ] ;
unsigned int V_95 ;
switch ( V_88 -> V_41 ) {
case V_96 ... V_97 :
V_93 = ( long ) V_2 -> V_4 . V_98 [ V_88 -> V_41 - V_96 ] ;
break;
case V_99 :
V_93 = ( long ) V_2 -> V_4 . V_100 ;
break;
case V_101 :
V_93 = ( long ) V_2 -> V_4 . V_102 ;
break;
case V_103 :
V_93 = ( long ) V_2 -> V_4 . V_104 ;
break;
case F_69 ( 0 ) ... F_69 ( 31 ) :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_82 ;
V_95 = V_88 -> V_41 - F_69 ( 0 ) ;
if ( F_71 ( V_74 ) & V_105 )
V_93 = F_72 ( & V_91 -> V_106 [ V_95 ] , 0 ) ;
else
V_93 = F_72 ( & V_91 -> V_106 [ V_95 & ~ 1 ] , V_95 & 1 ) ;
break;
case F_73 ( 0 ) ... F_73 ( 31 ) :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_82 ;
V_95 = V_88 -> V_41 - F_73 ( 0 ) ;
if ( V_95 & 1 && ! ( F_71 ( V_74 ) & V_105 ) )
return - V_82 ;
V_93 = F_74 ( & V_91 -> V_106 [ V_95 ] , 0 ) ;
break;
case V_107 :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_82 ;
V_93 = V_108 . V_109 ;
break;
case V_110 :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_82 ;
V_93 = V_91 -> V_111 ;
break;
case F_75 ( 0 ) ... F_75 ( 31 ) :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_82 ;
if ( ! ( F_71 ( V_74 ) & V_105 ) )
return - V_82 ;
V_95 = V_88 -> V_41 - F_75 ( 0 ) ;
#ifdef F_77
V_94 [ 0 ] = F_74 ( & V_91 -> V_106 [ V_95 ] , 0 ) ;
V_94 [ 1 ] = F_74 ( & V_91 -> V_106 [ V_95 ] , 1 ) ;
#else
V_94 [ 0 ] = F_74 ( & V_91 -> V_106 [ V_95 ] , 1 ) ;
V_94 [ 1 ] = F_74 ( & V_91 -> V_106 [ V_95 ] , 0 ) ;
#endif
break;
case V_112 :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_82 ;
V_93 = V_108 . V_113 ;
break;
case V_114 :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_82 ;
V_93 = V_91 -> V_115 ;
break;
case V_116 :
V_93 = ( long ) F_78 ( V_74 ) ;
break;
case V_117 :
V_93 = ( long ) F_79 ( V_74 ) ;
break;
case V_118 :
V_93 = ( long ) F_80 ( V_74 ) ;
break;
case V_119 :
V_93 = ( long ) F_81 ( V_74 ) ;
break;
case V_120 :
V_93 = ( long ) F_82 ( V_74 ) ;
break;
case V_121 :
V_93 = ( long ) F_83 ( V_74 ) ;
break;
case V_122 :
V_93 = ( long ) F_84 ( V_74 ) ;
break;
case V_123 :
V_93 = ( long ) F_85 ( V_74 ) ;
break;
case V_124 :
V_93 = ( long ) F_86 ( V_74 ) ;
break;
case V_125 :
V_93 = ( long ) F_71 ( V_74 ) ;
break;
case V_126 :
V_93 = ( long ) F_56 ( V_74 ) ;
break;
case V_127 :
V_93 = ( long ) F_87 ( V_74 ) ;
break;
case V_128 :
V_93 = ( long ) F_88 ( V_74 ) ;
break;
case V_129 :
V_93 = ( long ) F_89 ( V_74 ) ;
break;
case V_130 :
V_93 = ( long ) F_90 ( V_74 ) ;
break;
case V_131 :
V_93 = ( long ) F_91 ( V_74 ) ;
break;
case V_132 :
V_93 = ( long ) F_92 ( V_74 ) ;
break;
case V_133 :
V_93 = ( long ) F_93 ( V_74 ) ;
break;
case V_134 :
V_93 = ( long ) F_94 ( V_74 ) ;
break;
case V_135 :
V_93 = ( long ) F_95 ( V_74 ) ;
break;
case V_136 :
V_93 = ( long ) F_96 ( V_74 ) ;
break;
case V_137 :
case V_138 :
case V_139 :
case V_140 :
V_92 = V_13 -> V_141 ( V_2 , V_88 , & V_93 ) ;
if ( V_92 )
return V_92 ;
break;
default:
return - V_82 ;
}
if ( ( V_88 -> V_41 & V_142 ) == V_143 ) {
T_3 T_4 * V_144 = ( T_3 T_4 * ) ( long ) V_88 -> V_145 ;
return F_97 ( V_93 , V_144 ) ;
} else if ( ( V_88 -> V_41 & V_142 ) == V_146 ) {
T_5 T_4 * V_147 = ( T_5 T_4 * ) ( long ) V_88 -> V_145 ;
T_5 V_148 = ( T_5 ) V_93 ;
return F_97 ( V_148 , V_147 ) ;
} else if ( ( V_88 -> V_41 & V_142 ) == V_149 ) {
void T_4 * V_150 = ( void T_4 * ) ( long ) V_88 -> V_145 ;
return F_98 ( V_150 , V_94 , 16 ) ;
} else {
return - V_82 ;
}
}
static int F_99 ( struct V_1 * V_2 ,
const struct V_87 * V_88 )
{
struct V_89 * V_74 = V_2 -> V_4 . V_74 ;
struct V_90 * V_91 = & V_2 -> V_4 . V_91 ;
T_2 V_93 ;
T_2 V_94 [ 2 ] ;
unsigned int V_95 ;
if ( ( V_88 -> V_41 & V_142 ) == V_143 ) {
T_3 T_4 * V_144 = ( T_3 T_4 * ) ( long ) V_88 -> V_145 ;
if ( F_100 ( V_93 , V_144 ) != 0 )
return - V_151 ;
} else if ( ( V_88 -> V_41 & V_142 ) == V_146 ) {
T_5 T_4 * V_147 = ( T_5 T_4 * ) ( long ) V_88 -> V_145 ;
T_6 V_148 ;
if ( F_100 ( V_148 , V_147 ) != 0 )
return - V_151 ;
V_93 = ( T_2 ) V_148 ;
} else if ( ( V_88 -> V_41 & V_142 ) == V_149 ) {
void T_4 * V_150 = ( void T_4 * ) ( long ) V_88 -> V_145 ;
return F_101 ( V_94 , V_150 , 16 ) ;
} else {
return - V_82 ;
}
switch ( V_88 -> V_41 ) {
case V_96 :
break;
case V_152 ... V_97 :
V_2 -> V_4 . V_98 [ V_88 -> V_41 - V_96 ] = V_93 ;
break;
case V_99 :
V_2 -> V_4 . V_100 = V_93 ;
break;
case V_101 :
V_2 -> V_4 . V_102 = V_93 ;
break;
case V_103 :
V_2 -> V_4 . V_104 = V_93 ;
break;
case F_69 ( 0 ) ... F_69 ( 31 ) :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_82 ;
V_95 = V_88 -> V_41 - F_69 ( 0 ) ;
if ( F_71 ( V_74 ) & V_105 )
F_102 ( & V_91 -> V_106 [ V_95 ] , 0 , V_93 ) ;
else
F_102 ( & V_91 -> V_106 [ V_95 & ~ 1 ] , V_95 & 1 , V_93 ) ;
break;
case F_73 ( 0 ) ... F_73 ( 31 ) :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_82 ;
V_95 = V_88 -> V_41 - F_73 ( 0 ) ;
if ( V_95 & 1 && ! ( F_71 ( V_74 ) & V_105 ) )
return - V_82 ;
F_103 ( & V_91 -> V_106 [ V_95 ] , 0 , V_93 ) ;
break;
case V_107 :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_82 ;
break;
case V_110 :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_82 ;
V_91 -> V_111 = V_93 ;
break;
case F_75 ( 0 ) ... F_75 ( 31 ) :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_82 ;
V_95 = V_88 -> V_41 - F_75 ( 0 ) ;
#ifdef F_77
F_103 ( & V_91 -> V_106 [ V_95 ] , 0 , V_94 [ 0 ] ) ;
F_103 ( & V_91 -> V_106 [ V_95 ] , 1 , V_94 [ 1 ] ) ;
#else
F_103 ( & V_91 -> V_106 [ V_95 ] , 1 , V_94 [ 0 ] ) ;
F_103 ( & V_91 -> V_106 [ V_95 ] , 0 , V_94 [ 1 ] ) ;
#endif
break;
case V_112 :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_82 ;
break;
case V_114 :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_82 ;
V_91 -> V_115 = V_93 ;
break;
case V_116 :
F_104 ( V_74 , V_93 ) ;
break;
case V_117 :
F_105 ( V_74 , V_93 ) ;
break;
case V_118 :
F_106 ( V_74 , V_93 ) ;
break;
case V_119 :
F_107 ( V_74 , V_93 ) ;
break;
case V_120 :
F_108 ( V_74 , V_93 ) ;
break;
case V_121 :
F_109 ( V_74 , V_93 ) ;
break;
case V_122 :
F_110 ( V_74 , V_93 ) ;
break;
case V_123 :
F_111 ( V_74 , V_93 ) ;
break;
case V_125 :
F_112 ( V_74 , V_93 ) ;
break;
case V_127 :
F_113 ( V_74 , V_93 ) ;
break;
case V_128 :
F_114 ( V_74 , V_93 ) ;
break;
case V_136 :
F_115 ( V_74 , V_93 ) ;
break;
case V_137 :
case V_124 :
case V_126 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_138 :
case V_139 :
case V_140 :
return V_13 -> V_153 ( V_2 , V_88 , V_93 ) ;
default:
return - V_82 ;
}
return 0 ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_154 * V_155 )
{
int V_67 = 0 ;
if ( ! F_117 ( V_2 -> V_9 , V_155 -> V_155 ) )
return - V_82 ;
if ( V_155 -> V_156 )
return - V_82 ;
if ( V_155 -> args [ 0 ] )
return - V_82 ;
switch ( V_155 -> V_155 ) {
case V_157 :
V_2 -> V_4 . V_158 = true ;
break;
case V_159 :
V_2 -> V_4 . V_160 = true ;
break;
default:
V_67 = - V_82 ;
break;
}
return V_67 ;
}
long F_118 ( struct V_23 * V_24 , unsigned int V_25 ,
unsigned long V_12 )
{
struct V_1 * V_2 = V_24 -> V_161 ;
void T_4 * V_162 = ( void T_4 * ) V_12 ;
long V_67 ;
switch ( V_25 ) {
case V_163 :
case V_164 : {
struct V_87 V_88 ;
if ( F_101 ( & V_88 , V_162 , sizeof( V_88 ) ) )
return - V_151 ;
if ( V_25 == V_163 )
return F_99 ( V_2 , & V_88 ) ;
else
return F_68 ( V_2 , & V_88 ) ;
}
case V_165 : {
struct V_166 T_4 * V_167 = V_162 ;
T_3 T_4 * V_168 ;
struct V_166 V_169 ;
unsigned V_170 ;
if ( F_101 ( & V_169 , V_167 , sizeof( V_169 ) ) )
return - V_151 ;
V_170 = V_169 . V_170 ;
V_169 . V_170 = F_119 ( V_171 ) ;
if ( F_98 ( V_167 , & V_169 , sizeof( V_169 ) ) )
return - V_151 ;
if ( V_170 < V_169 . V_170 )
return - V_172 ;
V_168 = V_167 -> V_88 ;
if ( F_98 ( V_168 , V_171 ,
sizeof( V_171 ) ) )
return - V_151 ;
return 0 ;
}
case V_173 :
V_67 = F_1 ( V_2 ) ;
break;
case V_174 :
{
struct V_75 V_76 ;
V_67 = - V_151 ;
if ( F_101 ( & V_76 , V_162 , sizeof( V_76 ) ) )
goto V_47;
F_12 ( L_14 , V_2 -> V_175 , V_16 ,
V_76 . V_76 ) ;
V_67 = F_63 ( V_2 , & V_76 ) ;
break;
}
case V_176 : {
struct V_154 V_155 ;
V_67 = - V_151 ;
if ( F_101 ( & V_155 , V_162 , sizeof( V_155 ) ) )
goto V_47;
V_67 = F_116 ( V_2 , & V_155 ) ;
break;
}
default:
V_67 = - V_26 ;
}
V_47:
return V_67 ;
}
int F_120 ( struct V_9 * V_9 , struct V_177 * log )
{
struct V_27 * V_30 ;
unsigned long V_178 , V_179 ;
int V_180 = 0 ;
int V_67 ;
unsigned long V_170 ;
F_23 ( & V_9 -> V_181 ) ;
V_67 = F_121 ( V_9 , log , & V_180 ) ;
if ( V_67 )
goto V_47;
if ( V_180 ) {
V_30 = & V_9 -> V_182 -> V_182 [ log -> V_28 ] ;
V_178 = V_30 -> V_183 << V_39 ;
V_179 = V_178 + ( V_30 -> V_29 << V_39 ) ;
F_122 ( L_15 , V_16 , V_178 ,
V_179 ) ;
V_170 = F_123 ( V_30 ) ;
memset ( V_30 -> V_184 , 0 , V_170 ) ;
}
V_67 = 0 ;
V_47:
F_26 ( & V_9 -> V_181 ) ;
return V_67 ;
}
long F_124 ( struct V_23 * V_24 , unsigned int V_25 , unsigned long V_12 )
{
long V_67 ;
switch ( V_25 ) {
default:
V_67 = - V_26 ;
}
return V_67 ;
}
int F_125 ( void * V_185 )
{
if ( V_13 ) {
F_36 ( L_16 ) ;
return - V_186 ;
}
return F_126 ( & V_13 ) ;
}
void F_127 ( void )
{
V_13 = NULL ;
}
int F_128 ( struct V_1 * V_2 ,
struct V_187 * V_188 )
{
return - V_26 ;
}
int F_129 ( struct V_1 * V_2 ,
struct V_187 * V_188 )
{
return - V_26 ;
}
void F_130 ( struct V_1 * V_2 )
{
}
int F_131 ( struct V_1 * V_2 , struct V_189 * V_91 )
{
return - V_26 ;
}
int F_132 ( struct V_1 * V_2 , struct V_189 * V_91 )
{
return - V_26 ;
}
int F_133 ( struct V_1 * V_2 , struct V_190 * V_191 )
{
return V_192 ;
}
int F_117 ( struct V_9 * V_9 , long V_193 )
{
int V_67 ;
switch ( V_193 ) {
case V_194 :
case V_195 :
V_67 = 1 ;
break;
case V_196 :
V_67 = V_197 ;
break;
case V_157 :
V_67 = ! ! V_198 ;
break;
case V_159 :
V_67 = V_199 && ! ( V_108 . V_113 & V_200 ) ;
break;
default:
V_67 = 0 ;
break;
}
return V_67 ;
}
int F_134 ( struct V_1 * V_2 )
{
return F_135 ( V_2 ) ;
}
int F_136 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_89 * V_74 ;
if ( ! V_2 )
return - 1 ;
F_12 ( L_17 ) ;
F_12 ( L_18 , V_2 -> V_4 . V_104 ) ;
F_12 ( L_19 , V_2 -> V_4 . V_7 ) ;
for ( V_3 = 0 ; V_3 < 32 ; V_3 += 4 ) {
F_12 ( L_20 , V_3 ,
V_2 -> V_4 . V_98 [ V_3 ] ,
V_2 -> V_4 . V_98 [ V_3 + 1 ] ,
V_2 -> V_4 . V_98 [ V_3 + 2 ] , V_2 -> V_4 . V_98 [ V_3 + 3 ] ) ;
}
F_12 ( L_21 , V_2 -> V_4 . V_100 ) ;
F_12 ( L_22 , V_2 -> V_4 . V_102 ) ;
V_74 = V_2 -> V_4 . V_74 ;
F_12 ( L_23 ,
F_71 ( V_74 ) ,
F_56 ( V_74 ) ) ;
F_12 ( L_24 , F_87 ( V_74 ) ) ;
return 0 ;
}
int F_137 ( struct V_1 * V_2 , struct V_201 * V_202 )
{
int V_3 ;
for ( V_3 = 1 ; V_3 < F_119 ( V_2 -> V_4 . V_98 ) ; V_3 ++ )
V_2 -> V_4 . V_98 [ V_3 ] = V_202 -> V_203 [ V_3 ] ;
V_2 -> V_4 . V_98 [ 0 ] = 0 ;
V_2 -> V_4 . V_100 = V_202 -> V_100 ;
V_2 -> V_4 . V_102 = V_202 -> V_102 ;
V_2 -> V_4 . V_104 = V_202 -> V_104 ;
return 0 ;
}
int F_138 ( struct V_1 * V_2 , struct V_201 * V_202 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_119 ( V_2 -> V_4 . V_98 ) ; V_3 ++ )
V_202 -> V_203 [ V_3 ] = V_2 -> V_4 . V_98 [ V_3 ] ;
V_202 -> V_100 = V_2 -> V_4 . V_100 ;
V_202 -> V_102 = V_2 -> V_4 . V_102 ;
V_202 -> V_104 = V_2 -> V_4 . V_104 ;
return 0 ;
}
static void F_139 ( unsigned long V_204 )
{
struct V_1 * V_2 = (struct V_1 * ) V_204 ;
V_13 -> V_205 ( V_2 ) ;
V_2 -> V_4 . V_83 = 0 ;
if ( F_64 ( & V_2 -> V_84 ) )
F_65 ( & V_2 -> V_84 ) ;
}
static enum V_206 F_140 ( struct V_207 * V_208 )
{
struct V_1 * V_2 ;
V_2 = F_141 ( V_208 , struct V_1 , V_4 . V_62 ) ;
F_139 ( ( unsigned long ) V_2 ) ;
return F_142 ( V_2 ) ;
}
int F_143 ( struct V_1 * V_2 )
{
V_13 -> V_209 ( V_2 ) ;
F_144 ( & V_2 -> V_4 . V_62 , V_210 ,
V_211 ) ;
V_2 -> V_4 . V_62 . V_212 = F_140 ;
return 0 ;
}
int F_145 ( struct V_1 * V_2 ,
struct V_213 * V_214 )
{
return 0 ;
}
int F_146 ( struct V_1 * V_2 )
{
return V_13 -> V_215 ( V_2 ) ;
}
static void F_147 ( void )
{
T_7 V_216 = F_148 () ;
if ( V_217 )
V_216 |= ( V_218 ) ;
F_149 ( V_216 ) ;
F_150 () ;
}
int F_151 ( struct V_65 * V_66 , struct V_1 * V_2 )
{
T_7 V_219 = V_2 -> V_4 . V_220 ;
T_7 V_221 = ( V_219 >> V_222 ) & 0x1f ;
T_7 T_4 * V_223 = ( T_7 T_4 * ) V_2 -> V_4 . V_104 ;
unsigned long V_224 = V_2 -> V_4 . V_225 ;
enum V_226 V_227 = V_228 ;
int V_92 = V_229 ;
F_60 () ;
V_66 -> V_230 = V_231 ;
V_66 -> V_232 = 1 ;
F_147 () ;
F_62 () ;
F_12 ( L_25 ,
V_219 , V_223 , V_66 , V_2 ) ;
V_227 = F_152 ( V_219 , V_223 , V_66 , V_2 ) ;
if ( V_227 == V_233 ) {
goto V_234;
} else if ( V_227 == V_235 ) {
V_66 -> V_230 = V_236 ;
V_92 = V_237 ;
goto V_234;
}
switch ( V_221 ) {
case V_238 :
F_12 ( L_26 , V_2 -> V_175 , V_223 ) ;
++ V_2 -> V_239 . V_240 ;
F_153 ( V_2 , V_241 ) ;
if ( F_154 () )
F_155 () ;
V_92 = V_229 ;
break;
case V_242 :
F_12 ( L_27 , V_223 ) ;
++ V_2 -> V_239 . V_243 ;
F_153 ( V_2 , V_244 ) ;
V_92 = V_13 -> V_245 ( V_2 ) ;
if ( V_66 -> V_230 == V_246 )
V_92 = V_237 ;
break;
case V_247 :
++ V_2 -> V_239 . V_248 ;
F_153 ( V_2 , V_249 ) ;
V_92 = V_13 -> V_250 ( V_2 ) ;
break;
case V_251 :
F_12 ( L_28 ,
V_219 , F_71 ( V_2 -> V_4 . V_74 ) , V_223 ,
V_224 ) ;
++ V_2 -> V_239 . V_252 ;
F_153 ( V_2 , V_253 ) ;
V_92 = V_13 -> V_254 ( V_2 ) ;
break;
case V_255 :
F_12 ( L_29 ,
V_219 , V_223 , V_224 ) ;
++ V_2 -> V_239 . V_256 ;
F_153 ( V_2 , V_257 ) ;
V_92 = V_13 -> V_258 ( V_2 ) ;
break;
case V_259 :
++ V_2 -> V_239 . V_260 ;
F_153 ( V_2 , V_261 ) ;
V_92 = V_13 -> V_262 ( V_2 ) ;
break;
case V_263 :
++ V_2 -> V_239 . V_264 ;
F_153 ( V_2 , V_265 ) ;
V_92 = V_13 -> V_266 ( V_2 ) ;
break;
case V_267 :
++ V_2 -> V_239 . V_268 ;
F_153 ( V_2 , V_269 ) ;
V_92 = V_13 -> V_270 ( V_2 ) ;
break;
case V_271 :
++ V_2 -> V_239 . V_272 ;
F_153 ( V_2 , V_273 ) ;
V_92 = V_13 -> V_274 ( V_2 ) ;
break;
case V_275 :
++ V_2 -> V_239 . V_276 ;
F_153 ( V_2 , V_277 ) ;
V_92 = V_13 -> V_278 ( V_2 ) ;
break;
case V_279 :
++ V_2 -> V_239 . V_280 ;
F_153 ( V_2 , V_281 ) ;
V_92 = V_13 -> V_282 ( V_2 ) ;
break;
case V_283 :
++ V_2 -> V_239 . V_284 ;
F_153 ( V_2 , V_285 ) ;
V_92 = V_13 -> V_286 ( V_2 ) ;
break;
case V_287 :
++ V_2 -> V_239 . V_288 ;
F_153 ( V_2 , V_289 ) ;
V_92 = V_13 -> V_290 ( V_2 ) ;
break;
case V_291 :
++ V_2 -> V_239 . V_292 ;
F_153 ( V_2 , V_293 ) ;
V_92 = V_13 -> V_294 ( V_2 ) ;
break;
default:
F_36 ( L_30 ,
V_221 , V_223 , F_156 ( V_223 , V_2 ) , V_224 ,
F_71 ( V_2 -> V_4 . V_74 ) ) ;
F_136 ( V_2 ) ;
V_66 -> V_230 = V_236 ;
V_92 = V_237 ;
break;
}
V_234:
F_54 () ;
if ( V_227 == V_228 && ! ( V_92 & V_237 ) )
F_55 ( V_2 , V_219 ) ;
if ( ! ( V_92 & V_237 ) ) {
if ( F_157 ( V_295 ) ) {
V_66 -> V_230 = V_296 ;
V_92 = ( - V_297 << 2 ) | V_237 ;
++ V_2 -> V_239 . V_298 ;
F_153 ( V_2 , V_299 ) ;
}
}
if ( V_92 == V_229 ) {
if ( F_70 ( & V_2 -> V_4 ) &&
F_148 () & V_300 )
F_158 ( & V_2 -> V_4 ) ;
if ( F_76 ( & V_2 -> V_4 ) &&
F_159 () & V_301 )
F_160 ( & V_2 -> V_4 ) ;
}
F_58 () ;
return V_92 ;
}
void F_161 ( struct V_1 * V_2 )
{
struct V_89 * V_74 = V_2 -> V_4 . V_74 ;
unsigned int V_302 , V_303 ;
F_162 () ;
V_302 = F_71 ( V_74 ) ;
if ( V_199 && V_302 & V_300 && ! ( V_302 & V_105 ) &&
V_2 -> V_4 . V_304 & V_305 )
F_163 ( V_2 ) ;
F_164 ( V_300 | V_105 , V_302 ) ;
if ( V_306 ) {
V_303 = F_94 ( V_74 ) ;
F_165 ( V_307 , V_303 ) ;
}
F_166 () ;
if ( ! ( V_2 -> V_4 . V_304 & V_308 ) ) {
F_167 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_304 |= V_308 ;
}
F_168 () ;
}
void F_169 ( struct V_1 * V_2 )
{
struct V_89 * V_74 = V_2 -> V_4 . V_74 ;
unsigned int V_302 , V_303 ;
F_162 () ;
if ( F_70 ( & V_2 -> V_4 ) ) {
V_302 = F_71 ( V_74 ) ;
if ( ! ( V_302 & V_105 ) &&
( V_2 -> V_4 . V_304 & ( V_308 |
V_305 ) ) == V_308 )
F_163 ( V_2 ) ;
F_164 ( V_300 | V_105 , V_302 ) ;
if ( V_302 & V_300 && V_306 ) {
V_303 = F_94 ( V_74 ) ;
F_165 ( V_307 , V_303 ) ;
}
}
F_170 ( V_301 ) ;
F_166 () ;
switch ( V_2 -> V_4 . V_304 & ( V_308 | V_305 ) ) {
case V_308 :
F_171 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_304 |= V_305 ;
break;
case 0 :
F_172 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_304 |= V_305 ;
if ( F_70 ( & V_2 -> V_4 ) )
V_2 -> V_4 . V_304 |= V_308 ;
break;
default:
break;
}
F_168 () ;
}
void F_173 ( struct V_1 * V_2 )
{
F_162 () ;
if ( V_199 && V_2 -> V_4 . V_304 & V_305 ) {
F_174 () ;
V_2 -> V_4 . V_304 &= ~ V_305 ;
}
if ( V_2 -> V_4 . V_304 & V_308 ) {
F_175 ( V_300 | V_105 ) ;
V_2 -> V_4 . V_304 &= ~ V_308 ;
}
F_168 () ;
}
void F_163 ( struct V_1 * V_2 )
{
F_162 () ;
if ( V_199 && V_2 -> V_4 . V_304 & V_305 ) {
F_170 ( V_301 ) ;
F_166 () ;
F_176 ( & V_2 -> V_4 ) ;
F_174 () ;
if ( V_2 -> V_4 . V_304 & V_308 )
F_175 ( V_300 | V_105 ) ;
V_2 -> V_4 . V_304 &= ~ ( V_308 | V_305 ) ;
} else if ( V_2 -> V_4 . V_304 & V_308 ) {
F_177 ( V_300 ) ;
F_166 () ;
F_178 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_304 &= ~ V_308 ;
F_175 ( V_300 | V_105 ) ;
}
F_168 () ;
}
static int F_179 ( struct V_309 * V_310 ,
unsigned long V_311 , void * V_312 )
{
struct V_313 * args = (struct V_313 * ) V_312 ;
struct V_314 * V_202 = args -> V_202 ;
unsigned long V_104 ;
if ( V_311 != V_315 && V_311 != V_316 )
return V_317 ;
if ( ! ( V_295 -> V_156 & V_318 ) )
return V_317 ;
F_180 ( F_181 ( V_202 ) ) ;
V_104 = F_182 ( V_202 ) ;
switch ( V_311 ) {
case V_315 :
if ( V_104 != ( unsigned long ) & F_158 + 4 )
return V_317 ;
break;
case V_316 :
if ( ! V_199 ||
V_104 < ( unsigned long ) & F_160 + 4 ||
V_104 > ( unsigned long ) & F_160 + 8 )
return V_317 ;
break;
}
F_182 ( V_202 ) += 4 ;
return V_319 ;
}
int T_8 F_183 ( void )
{
int V_92 ;
V_92 = F_184 ( NULL , sizeof( struct V_1 ) , 0 , V_320 ) ;
if ( V_92 )
return V_92 ;
F_185 ( & V_321 ) ;
V_322 = V_323 ;
F_19 = V_324 ;
V_325 = V_326 ;
return 0 ;
}
void T_9 F_186 ( void )
{
F_187 () ;
V_322 = NULL ;
F_19 = NULL ;
V_325 = NULL ;
F_188 ( & V_321 ) ;
}
