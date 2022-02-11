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
const struct V_31 * V_32 ,
enum V_33 V_34 )
{
return 0 ;
}
void F_34 ( struct V_9 * V_9 ,
const struct V_31 * V_32 ,
const struct V_27 * V_35 ,
const struct V_27 * V_36 ,
enum V_33 V_34 )
{
unsigned long V_29 = 0 ;
int V_3 ;
F_12 ( L_4 ,
V_16 , V_9 , V_32 -> V_28 , V_32 -> V_37 ,
V_32 -> V_38 , V_32 -> V_39 ) ;
if ( ! V_9 -> V_4 . V_18 ) {
if ( V_32 -> V_28 == 0 )
V_29 = V_32 -> V_38 >> V_40 ;
if ( V_29 ) {
V_9 -> V_4 . V_17 = V_29 ;
V_9 -> V_4 . V_18 =
F_35 ( V_29 * sizeof( unsigned long ) , V_41 ) ;
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
struct V_1 * F_37 ( struct V_9 * V_9 , unsigned int V_42 )
{
int V_43 , V_44 , V_45 ;
void * V_46 ;
int V_3 ;
struct V_1 * V_2 = F_35 ( sizeof( struct V_1 ) , V_41 ) ;
if ( ! V_2 ) {
V_43 = - V_47 ;
goto V_48;
}
V_43 = F_38 ( V_2 , V_9 , V_42 ) ;
if ( V_43 )
goto V_49;
F_12 ( L_7 , V_9 , V_42 , V_2 ) ;
if ( V_50 || V_51 )
V_44 = 0x200 + V_52 * 64 ;
else
V_44 = 0x4000 ;
V_2 -> V_4 . V_53 = ( void * ) F_39 () ;
V_46 = F_35 ( F_40 ( V_44 , V_54 ) , V_41 ) ;
if ( ! V_46 ) {
V_43 = - V_47 ;
goto V_55;
}
F_12 ( L_8 ,
F_40 ( V_44 , V_54 ) , V_46 ) ;
V_2 -> V_4 . V_56 = V_46 ;
memcpy ( V_46 , V_57 ,
V_58 - V_57 ) ;
memcpy ( V_46 + 0x180 , V_57 ,
V_58 - V_57 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
F_12 ( L_9 ,
V_46 + 0x200 + ( V_3 * V_52 ) ) ;
memcpy ( V_46 + 0x200 + ( V_3 * V_52 ) , V_57 ,
V_58 - V_57 ) ;
}
V_45 = 0x2000 ;
F_12 ( L_10 ,
V_46 + V_45 ,
V_59 - V_60 ) ;
memcpy ( V_46 + V_45 , V_60 ,
V_59 - V_60 ) ;
F_41 ( ( unsigned long ) V_46 ,
( unsigned long ) V_46 + F_40 ( V_44 , V_54 ) ) ;
V_2 -> V_4 . V_61 = F_35 ( V_54 << 1 , V_41 ) ;
if ( ! V_2 -> V_4 . V_61 ) {
V_43 = - V_47 ;
goto V_62;
}
F_12 ( L_11 , V_2 -> V_4 . V_61 ) ;
F_42 ( V_2 ) ;
V_2 -> V_4 . V_63 = - 1 ;
F_43 ( V_2 ) ;
return V_2 ;
V_62:
F_20 ( V_46 ) ;
V_55:
F_44 ( V_2 ) ;
V_49:
F_20 ( V_2 ) ;
V_48:
return F_45 ( V_43 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_46 ( & V_2 -> V_4 . V_64 ) ;
F_44 ( V_2 ) ;
F_47 ( V_2 ) ;
F_20 ( V_2 -> V_4 . V_56 ) ;
F_20 ( V_2 -> V_4 . V_61 ) ;
F_20 ( V_2 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
return - V_26 ;
}
int F_50 ( struct V_1 * V_2 , struct V_67 * V_68 )
{
int V_69 = 0 ;
T_1 V_70 ;
if ( V_2 -> V_71 )
F_51 ( V_72 , & V_2 -> V_73 , & V_70 ) ;
if ( V_2 -> V_74 ) {
if ( ! V_2 -> V_75 )
F_52 ( V_2 , V_68 ) ;
V_2 -> V_74 = 0 ;
}
F_53 ( 1 ) ;
F_54 () ;
F_55 ( V_2 ,
F_56 ( V_2 -> V_4 . V_76 ) ) ;
F_57 () ;
F_58 () ;
V_69 = F_59 ( V_68 , V_2 ) ;
F_60 () ;
F_61 () ;
F_62 () ;
if ( V_2 -> V_71 )
F_51 ( V_72 , & V_70 , NULL ) ;
return V_69 ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
int V_79 = ( int ) V_78 -> V_78 ;
struct V_1 * V_80 = NULL ;
if ( V_79 == 3 || V_79 == - 3 || V_79 == 4 || V_79 == - 4 )
F_12 ( L_12 , V_16 , V_78 -> V_81 ,
( int ) V_79 ) ;
if ( V_78 -> V_81 == - 1 )
V_80 = V_2 ;
else
V_80 = V_2 -> V_9 -> V_22 [ V_78 -> V_81 ] ;
if ( V_79 == 2 || V_79 == 3 || V_79 == 4 ) {
V_13 -> V_82 ( V_80 , V_78 ) ;
} else if ( V_79 == - 2 || V_79 == - 3 || V_79 == - 4 ) {
V_13 -> V_83 ( V_80 , V_78 ) ;
} else {
F_36 ( L_13 , V_16 ,
V_78 -> V_81 , V_78 -> V_78 ) ;
return - V_84 ;
}
V_80 -> V_4 . V_85 = 0 ;
if ( F_64 ( & V_80 -> V_86 ) )
F_65 ( & V_80 -> V_86 ) ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
return - V_26 ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
return - V_26 ;
}
static int F_68 ( struct V_1 * V_2 ,
const struct V_89 * V_90 )
{
struct V_91 * V_76 = V_2 -> V_4 . V_76 ;
struct V_92 * V_93 = & V_2 -> V_4 . V_93 ;
int V_94 ;
T_2 V_95 ;
T_2 V_96 [ 2 ] ;
unsigned int V_97 ;
switch ( V_90 -> V_42 ) {
case V_98 ... V_99 :
V_95 = ( long ) V_2 -> V_4 . V_100 [ V_90 -> V_42 - V_98 ] ;
break;
case V_101 :
V_95 = ( long ) V_2 -> V_4 . V_102 ;
break;
case V_103 :
V_95 = ( long ) V_2 -> V_4 . V_104 ;
break;
case V_105 :
V_95 = ( long ) V_2 -> V_4 . V_106 ;
break;
case F_69 ( 0 ) ... F_69 ( 31 ) :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_84 ;
V_97 = V_90 -> V_42 - F_69 ( 0 ) ;
if ( F_71 ( V_76 ) & V_107 )
V_95 = F_72 ( & V_93 -> V_108 [ V_97 ] , 0 ) ;
else
V_95 = F_72 ( & V_93 -> V_108 [ V_97 & ~ 1 ] , V_97 & 1 ) ;
break;
case F_73 ( 0 ) ... F_73 ( 31 ) :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_84 ;
V_97 = V_90 -> V_42 - F_73 ( 0 ) ;
if ( V_97 & 1 && ! ( F_71 ( V_76 ) & V_107 ) )
return - V_84 ;
V_95 = F_74 ( & V_93 -> V_108 [ V_97 ] , 0 ) ;
break;
case V_109 :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_84 ;
V_95 = V_110 . V_111 ;
break;
case V_112 :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_84 ;
V_95 = V_93 -> V_113 ;
break;
case F_75 ( 0 ) ... F_75 ( 31 ) :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_84 ;
if ( ! ( F_71 ( V_76 ) & V_107 ) )
return - V_84 ;
V_97 = V_90 -> V_42 - F_75 ( 0 ) ;
#ifdef F_77
V_96 [ 0 ] = F_74 ( & V_93 -> V_108 [ V_97 ] , 0 ) ;
V_96 [ 1 ] = F_74 ( & V_93 -> V_108 [ V_97 ] , 1 ) ;
#else
V_96 [ 0 ] = F_74 ( & V_93 -> V_108 [ V_97 ] , 1 ) ;
V_96 [ 1 ] = F_74 ( & V_93 -> V_108 [ V_97 ] , 0 ) ;
#endif
break;
case V_114 :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_84 ;
V_95 = V_110 . V_115 ;
break;
case V_116 :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_84 ;
V_95 = V_93 -> V_117 ;
break;
case V_118 :
V_95 = ( long ) F_78 ( V_76 ) ;
break;
case V_119 :
V_95 = ( long ) F_79 ( V_76 ) ;
break;
case V_120 :
V_95 = ( long ) F_80 ( V_76 ) ;
break;
case V_121 :
V_95 = ( long ) F_81 ( V_76 ) ;
break;
case V_122 :
V_95 = ( long ) F_82 ( V_76 ) ;
break;
case V_123 :
V_95 = ( long ) F_83 ( V_76 ) ;
break;
case V_124 :
V_95 = ( long ) F_84 ( V_76 ) ;
break;
case V_125 :
V_95 = ( long ) F_85 ( V_76 ) ;
break;
case V_126 :
V_95 = ( long ) F_86 ( V_76 ) ;
break;
case V_127 :
V_95 = ( long ) F_71 ( V_76 ) ;
break;
case V_128 :
V_95 = ( long ) F_56 ( V_76 ) ;
break;
case V_129 :
V_95 = ( long ) F_87 ( V_76 ) ;
break;
case V_130 :
V_95 = ( long ) F_88 ( V_76 ) ;
break;
case V_131 :
V_95 = ( long ) F_89 ( V_76 ) ;
break;
case V_132 :
V_95 = ( long ) F_90 ( V_76 ) ;
break;
case V_133 :
V_95 = ( long ) F_91 ( V_76 ) ;
break;
case V_134 :
V_95 = ( long ) F_92 ( V_76 ) ;
break;
case V_135 :
V_95 = ( long ) F_93 ( V_76 ) ;
break;
case V_136 :
V_95 = ( long ) F_94 ( V_76 ) ;
break;
case V_137 :
V_95 = ( long ) F_95 ( V_76 ) ;
break;
case V_138 :
V_95 = ( long ) F_96 ( V_76 ) ;
break;
case V_139 :
case V_140 :
case V_141 :
case V_142 :
V_94 = V_13 -> V_143 ( V_2 , V_90 , & V_95 ) ;
if ( V_94 )
return V_94 ;
break;
default:
return - V_84 ;
}
if ( ( V_90 -> V_42 & V_144 ) == V_145 ) {
T_3 T_4 * V_146 = ( T_3 T_4 * ) ( long ) V_90 -> V_147 ;
return F_97 ( V_95 , V_146 ) ;
} else if ( ( V_90 -> V_42 & V_144 ) == V_148 ) {
T_5 T_4 * V_149 = ( T_5 T_4 * ) ( long ) V_90 -> V_147 ;
T_5 V_150 = ( T_5 ) V_95 ;
return F_97 ( V_150 , V_149 ) ;
} else if ( ( V_90 -> V_42 & V_144 ) == V_151 ) {
void T_4 * V_152 = ( void T_4 * ) ( long ) V_90 -> V_147 ;
return F_98 ( V_152 , V_96 , 16 ) ? - V_153 : 0 ;
} else {
return - V_84 ;
}
}
static int F_99 ( struct V_1 * V_2 ,
const struct V_89 * V_90 )
{
struct V_91 * V_76 = V_2 -> V_4 . V_76 ;
struct V_92 * V_93 = & V_2 -> V_4 . V_93 ;
T_2 V_95 ;
T_2 V_96 [ 2 ] ;
unsigned int V_97 ;
if ( ( V_90 -> V_42 & V_144 ) == V_145 ) {
T_3 T_4 * V_146 = ( T_3 T_4 * ) ( long ) V_90 -> V_147 ;
if ( F_100 ( V_95 , V_146 ) != 0 )
return - V_153 ;
} else if ( ( V_90 -> V_42 & V_144 ) == V_148 ) {
T_5 T_4 * V_149 = ( T_5 T_4 * ) ( long ) V_90 -> V_147 ;
T_6 V_150 ;
if ( F_100 ( V_150 , V_149 ) != 0 )
return - V_153 ;
V_95 = ( T_2 ) V_150 ;
} else if ( ( V_90 -> V_42 & V_144 ) == V_151 ) {
void T_4 * V_152 = ( void T_4 * ) ( long ) V_90 -> V_147 ;
return F_101 ( V_96 , V_152 , 16 ) ? - V_153 : 0 ;
} else {
return - V_84 ;
}
switch ( V_90 -> V_42 ) {
case V_98 :
break;
case V_154 ... V_99 :
V_2 -> V_4 . V_100 [ V_90 -> V_42 - V_98 ] = V_95 ;
break;
case V_101 :
V_2 -> V_4 . V_102 = V_95 ;
break;
case V_103 :
V_2 -> V_4 . V_104 = V_95 ;
break;
case V_105 :
V_2 -> V_4 . V_106 = V_95 ;
break;
case F_69 ( 0 ) ... F_69 ( 31 ) :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_84 ;
V_97 = V_90 -> V_42 - F_69 ( 0 ) ;
if ( F_71 ( V_76 ) & V_107 )
F_102 ( & V_93 -> V_108 [ V_97 ] , 0 , V_95 ) ;
else
F_102 ( & V_93 -> V_108 [ V_97 & ~ 1 ] , V_97 & 1 , V_95 ) ;
break;
case F_73 ( 0 ) ... F_73 ( 31 ) :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_84 ;
V_97 = V_90 -> V_42 - F_73 ( 0 ) ;
if ( V_97 & 1 && ! ( F_71 ( V_76 ) & V_107 ) )
return - V_84 ;
F_103 ( & V_93 -> V_108 [ V_97 ] , 0 , V_95 ) ;
break;
case V_109 :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_84 ;
break;
case V_112 :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_84 ;
V_93 -> V_113 = V_95 ;
break;
case F_75 ( 0 ) ... F_75 ( 31 ) :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_84 ;
V_97 = V_90 -> V_42 - F_75 ( 0 ) ;
#ifdef F_77
F_103 ( & V_93 -> V_108 [ V_97 ] , 0 , V_96 [ 0 ] ) ;
F_103 ( & V_93 -> V_108 [ V_97 ] , 1 , V_96 [ 1 ] ) ;
#else
F_103 ( & V_93 -> V_108 [ V_97 ] , 1 , V_96 [ 0 ] ) ;
F_103 ( & V_93 -> V_108 [ V_97 ] , 0 , V_96 [ 1 ] ) ;
#endif
break;
case V_114 :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_84 ;
break;
case V_116 :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_84 ;
V_93 -> V_117 = V_95 ;
break;
case V_118 :
F_104 ( V_76 , V_95 ) ;
break;
case V_119 :
F_105 ( V_76 , V_95 ) ;
break;
case V_120 :
F_106 ( V_76 , V_95 ) ;
break;
case V_121 :
F_107 ( V_76 , V_95 ) ;
break;
case V_122 :
F_108 ( V_76 , V_95 ) ;
break;
case V_123 :
F_109 ( V_76 , V_95 ) ;
break;
case V_124 :
F_110 ( V_76 , V_95 ) ;
break;
case V_125 :
F_111 ( V_76 , V_95 ) ;
break;
case V_127 :
F_112 ( V_76 , V_95 ) ;
break;
case V_129 :
F_113 ( V_76 , V_95 ) ;
break;
case V_130 :
F_114 ( V_76 , V_95 ) ;
break;
case V_138 :
F_115 ( V_76 , V_95 ) ;
break;
case V_139 :
case V_126 :
case V_128 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_140 :
case V_141 :
case V_142 :
return V_13 -> V_155 ( V_2 , V_90 , V_95 ) ;
default:
return - V_84 ;
}
return 0 ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_156 * V_157 )
{
int V_69 = 0 ;
if ( ! F_117 ( V_2 -> V_9 , V_157 -> V_157 ) )
return - V_84 ;
if ( V_157 -> V_158 )
return - V_84 ;
if ( V_157 -> args [ 0 ] )
return - V_84 ;
switch ( V_157 -> V_157 ) {
case V_159 :
V_2 -> V_4 . V_160 = true ;
break;
case V_161 :
V_2 -> V_4 . V_162 = true ;
break;
default:
V_69 = - V_84 ;
break;
}
return V_69 ;
}
long F_118 ( struct V_23 * V_24 , unsigned int V_25 ,
unsigned long V_12 )
{
struct V_1 * V_2 = V_24 -> V_163 ;
void T_4 * V_164 = ( void T_4 * ) V_12 ;
long V_69 ;
switch ( V_25 ) {
case V_165 :
case V_166 : {
struct V_89 V_90 ;
if ( F_101 ( & V_90 , V_164 , sizeof( V_90 ) ) )
return - V_153 ;
if ( V_25 == V_165 )
return F_99 ( V_2 , & V_90 ) ;
else
return F_68 ( V_2 , & V_90 ) ;
}
case V_167 : {
struct V_168 T_4 * V_169 = V_164 ;
T_3 T_4 * V_170 ;
struct V_168 V_171 ;
unsigned V_172 ;
if ( F_101 ( & V_171 , V_169 , sizeof( V_171 ) ) )
return - V_153 ;
V_172 = V_171 . V_172 ;
V_171 . V_172 = F_119 ( V_173 ) ;
if ( F_98 ( V_169 , & V_171 , sizeof( V_171 ) ) )
return - V_153 ;
if ( V_172 < V_171 . V_172 )
return - V_174 ;
V_170 = V_169 -> V_90 ;
if ( F_98 ( V_170 , V_173 ,
sizeof( V_173 ) ) )
return - V_153 ;
return 0 ;
}
case V_175 :
V_69 = F_1 ( V_2 ) ;
break;
case V_176 :
{
struct V_77 V_78 ;
V_69 = - V_153 ;
if ( F_101 ( & V_78 , V_164 , sizeof( V_78 ) ) )
goto V_48;
F_12 ( L_14 , V_2 -> V_177 , V_16 ,
V_78 . V_78 ) ;
V_69 = F_63 ( V_2 , & V_78 ) ;
break;
}
case V_178 : {
struct V_156 V_157 ;
V_69 = - V_153 ;
if ( F_101 ( & V_157 , V_164 , sizeof( V_157 ) ) )
goto V_48;
V_69 = F_116 ( V_2 , & V_157 ) ;
break;
}
default:
V_69 = - V_26 ;
}
V_48:
return V_69 ;
}
int F_120 ( struct V_9 * V_9 , struct V_179 * log )
{
struct V_180 * V_181 ;
struct V_27 * V_30 ;
unsigned long V_182 , V_183 ;
int V_184 = 0 ;
int V_69 ;
unsigned long V_172 ;
F_23 ( & V_9 -> V_185 ) ;
V_69 = F_121 ( V_9 , log , & V_184 ) ;
if ( V_69 )
goto V_48;
if ( V_184 ) {
V_181 = V_180 ( V_9 ) ;
V_30 = F_122 ( V_181 , log -> V_28 ) ;
V_182 = V_30 -> V_186 << V_40 ;
V_183 = V_182 + ( V_30 -> V_29 << V_40 ) ;
F_123 ( L_15 , V_16 , V_182 ,
V_183 ) ;
V_172 = F_124 ( V_30 ) ;
memset ( V_30 -> V_187 , 0 , V_172 ) ;
}
V_69 = 0 ;
V_48:
F_26 ( & V_9 -> V_185 ) ;
return V_69 ;
}
long F_125 ( struct V_23 * V_24 , unsigned int V_25 , unsigned long V_12 )
{
long V_69 ;
switch ( V_25 ) {
default:
V_69 = - V_26 ;
}
return V_69 ;
}
int F_126 ( void * V_188 )
{
if ( V_13 ) {
F_36 ( L_16 ) ;
return - V_189 ;
}
return F_127 ( & V_13 ) ;
}
void F_128 ( void )
{
V_13 = NULL ;
}
int F_129 ( struct V_1 * V_2 ,
struct V_190 * V_191 )
{
return - V_26 ;
}
int F_130 ( struct V_1 * V_2 ,
struct V_190 * V_191 )
{
return - V_26 ;
}
void F_131 ( struct V_1 * V_2 )
{
}
int F_132 ( struct V_1 * V_2 , struct V_192 * V_93 )
{
return - V_26 ;
}
int F_133 ( struct V_1 * V_2 , struct V_192 * V_93 )
{
return - V_26 ;
}
int F_134 ( struct V_1 * V_2 , struct V_193 * V_194 )
{
return V_195 ;
}
int F_117 ( struct V_9 * V_9 , long V_196 )
{
int V_69 ;
switch ( V_196 ) {
case V_197 :
case V_198 :
V_69 = 1 ;
break;
case V_199 :
V_69 = V_200 ;
break;
case V_159 :
V_69 = ! ! V_201 ;
break;
case V_161 :
V_69 = V_202 && ! ( V_110 . V_115 & V_203 ) ;
break;
default:
V_69 = 0 ;
break;
}
return V_69 ;
}
int F_135 ( struct V_1 * V_2 )
{
return F_136 ( V_2 ) ;
}
int F_137 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_91 * V_76 ;
if ( ! V_2 )
return - 1 ;
F_12 ( L_17 ) ;
F_12 ( L_18 , V_2 -> V_4 . V_106 ) ;
F_12 ( L_19 , V_2 -> V_4 . V_7 ) ;
for ( V_3 = 0 ; V_3 < 32 ; V_3 += 4 ) {
F_12 ( L_20 , V_3 ,
V_2 -> V_4 . V_100 [ V_3 ] ,
V_2 -> V_4 . V_100 [ V_3 + 1 ] ,
V_2 -> V_4 . V_100 [ V_3 + 2 ] , V_2 -> V_4 . V_100 [ V_3 + 3 ] ) ;
}
F_12 ( L_21 , V_2 -> V_4 . V_102 ) ;
F_12 ( L_22 , V_2 -> V_4 . V_104 ) ;
V_76 = V_2 -> V_4 . V_76 ;
F_12 ( L_23 ,
F_71 ( V_76 ) ,
F_56 ( V_76 ) ) ;
F_12 ( L_24 , F_87 ( V_76 ) ) ;
return 0 ;
}
int F_138 ( struct V_1 * V_2 , struct V_204 * V_205 )
{
int V_3 ;
for ( V_3 = 1 ; V_3 < F_119 ( V_2 -> V_4 . V_100 ) ; V_3 ++ )
V_2 -> V_4 . V_100 [ V_3 ] = V_205 -> V_206 [ V_3 ] ;
V_2 -> V_4 . V_100 [ 0 ] = 0 ;
V_2 -> V_4 . V_102 = V_205 -> V_102 ;
V_2 -> V_4 . V_104 = V_205 -> V_104 ;
V_2 -> V_4 . V_106 = V_205 -> V_106 ;
return 0 ;
}
int F_139 ( struct V_1 * V_2 , struct V_204 * V_205 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_119 ( V_2 -> V_4 . V_100 ) ; V_3 ++ )
V_205 -> V_206 [ V_3 ] = V_2 -> V_4 . V_100 [ V_3 ] ;
V_205 -> V_102 = V_2 -> V_4 . V_102 ;
V_205 -> V_104 = V_2 -> V_4 . V_104 ;
V_205 -> V_106 = V_2 -> V_4 . V_106 ;
return 0 ;
}
static void F_140 ( unsigned long V_207 )
{
struct V_1 * V_2 = (struct V_1 * ) V_207 ;
V_13 -> V_208 ( V_2 ) ;
V_2 -> V_4 . V_85 = 0 ;
if ( F_64 ( & V_2 -> V_86 ) )
F_65 ( & V_2 -> V_86 ) ;
}
static enum V_209 F_141 ( struct V_210 * V_211 )
{
struct V_1 * V_2 ;
V_2 = F_142 ( V_211 , struct V_1 , V_4 . V_64 ) ;
F_140 ( ( unsigned long ) V_2 ) ;
return F_143 ( V_2 ) ;
}
int F_144 ( struct V_1 * V_2 )
{
V_13 -> V_212 ( V_2 ) ;
F_145 ( & V_2 -> V_4 . V_64 , V_213 ,
V_214 ) ;
V_2 -> V_4 . V_64 . V_215 = F_141 ;
return 0 ;
}
int F_146 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
return 0 ;
}
int F_147 ( struct V_1 * V_2 )
{
return V_13 -> V_218 ( V_2 ) ;
}
static void F_148 ( void )
{
T_7 V_219 = F_149 () ;
if ( V_220 )
V_219 |= ( V_221 ) ;
F_150 ( V_219 ) ;
F_151 () ;
}
int F_152 ( struct V_67 * V_68 , struct V_1 * V_2 )
{
T_7 V_222 = V_2 -> V_4 . V_223 ;
T_7 V_224 = ( V_222 >> V_225 ) & 0x1f ;
T_7 T_4 * V_226 = ( T_7 T_4 * ) V_2 -> V_4 . V_106 ;
unsigned long V_227 = V_2 -> V_4 . V_228 ;
enum V_229 V_230 = V_231 ;
int V_94 = V_232 ;
F_60 () ;
V_68 -> V_233 = V_234 ;
V_68 -> V_235 = 1 ;
F_148 () ;
F_62 () ;
F_12 ( L_25 ,
V_222 , V_226 , V_68 , V_2 ) ;
V_230 = F_153 ( V_222 , V_226 , V_68 , V_2 ) ;
if ( V_230 == V_236 ) {
goto V_237;
} else if ( V_230 == V_238 ) {
V_68 -> V_233 = V_239 ;
V_94 = V_240 ;
goto V_237;
}
switch ( V_224 ) {
case V_241 :
F_12 ( L_26 , V_2 -> V_177 , V_226 ) ;
++ V_2 -> V_242 . V_243 ;
F_154 ( V_2 , V_244 ) ;
if ( F_155 () )
F_156 () ;
V_94 = V_232 ;
break;
case V_245 :
F_12 ( L_27 , V_226 ) ;
++ V_2 -> V_242 . V_246 ;
F_154 ( V_2 , V_247 ) ;
V_94 = V_13 -> V_248 ( V_2 ) ;
if ( V_68 -> V_233 == V_249 )
V_94 = V_240 ;
break;
case V_250 :
++ V_2 -> V_242 . V_251 ;
F_154 ( V_2 , V_252 ) ;
V_94 = V_13 -> V_253 ( V_2 ) ;
break;
case V_254 :
F_12 ( L_28 ,
V_222 , F_71 ( V_2 -> V_4 . V_76 ) , V_226 ,
V_227 ) ;
++ V_2 -> V_242 . V_255 ;
F_154 ( V_2 , V_256 ) ;
V_94 = V_13 -> V_257 ( V_2 ) ;
break;
case V_258 :
F_12 ( L_29 ,
V_222 , V_226 , V_227 ) ;
++ V_2 -> V_242 . V_259 ;
F_154 ( V_2 , V_260 ) ;
V_94 = V_13 -> V_261 ( V_2 ) ;
break;
case V_262 :
++ V_2 -> V_242 . V_263 ;
F_154 ( V_2 , V_264 ) ;
V_94 = V_13 -> V_265 ( V_2 ) ;
break;
case V_266 :
++ V_2 -> V_242 . V_267 ;
F_154 ( V_2 , V_268 ) ;
V_94 = V_13 -> V_269 ( V_2 ) ;
break;
case V_270 :
++ V_2 -> V_242 . V_271 ;
F_154 ( V_2 , V_272 ) ;
V_94 = V_13 -> V_273 ( V_2 ) ;
break;
case V_274 :
++ V_2 -> V_242 . V_275 ;
F_154 ( V_2 , V_276 ) ;
V_94 = V_13 -> V_277 ( V_2 ) ;
break;
case V_278 :
++ V_2 -> V_242 . V_279 ;
F_154 ( V_2 , V_280 ) ;
V_94 = V_13 -> V_281 ( V_2 ) ;
break;
case V_282 :
++ V_2 -> V_242 . V_283 ;
F_154 ( V_2 , V_284 ) ;
V_94 = V_13 -> V_285 ( V_2 ) ;
break;
case V_286 :
++ V_2 -> V_242 . V_287 ;
F_154 ( V_2 , V_288 ) ;
V_94 = V_13 -> V_289 ( V_2 ) ;
break;
case V_290 :
++ V_2 -> V_242 . V_291 ;
F_154 ( V_2 , V_292 ) ;
V_94 = V_13 -> V_293 ( V_2 ) ;
break;
case V_294 :
++ V_2 -> V_242 . V_295 ;
F_154 ( V_2 , V_296 ) ;
V_94 = V_13 -> V_297 ( V_2 ) ;
break;
default:
F_36 ( L_30 ,
V_224 , V_226 , F_157 ( V_226 , V_2 ) , V_227 ,
F_71 ( V_2 -> V_4 . V_76 ) ) ;
F_137 ( V_2 ) ;
V_68 -> V_233 = V_239 ;
V_94 = V_240 ;
break;
}
V_237:
F_54 () ;
if ( V_230 == V_231 && ! ( V_94 & V_240 ) )
F_55 ( V_2 , V_222 ) ;
if ( ! ( V_94 & V_240 ) ) {
if ( F_158 ( V_298 ) ) {
V_68 -> V_233 = V_299 ;
V_94 = ( - V_300 << 2 ) | V_240 ;
++ V_2 -> V_242 . V_301 ;
F_154 ( V_2 , V_302 ) ;
}
}
if ( V_94 == V_232 ) {
if ( F_70 ( & V_2 -> V_4 ) &&
F_149 () & V_303 )
F_159 ( & V_2 -> V_4 ) ;
if ( F_76 ( & V_2 -> V_4 ) &&
F_160 () & V_304 )
F_161 ( & V_2 -> V_4 ) ;
}
F_58 () ;
return V_94 ;
}
void F_162 ( struct V_1 * V_2 )
{
struct V_91 * V_76 = V_2 -> V_4 . V_76 ;
unsigned int V_305 , V_306 ;
F_163 () ;
V_305 = F_71 ( V_76 ) ;
if ( V_202 && V_305 & V_303 && ! ( V_305 & V_107 ) &&
V_2 -> V_4 . V_307 & V_308 )
F_164 ( V_2 ) ;
F_165 ( V_303 | V_107 , V_305 ) ;
if ( V_309 ) {
V_306 = F_94 ( V_76 ) ;
F_166 ( V_310 , V_306 ) ;
}
F_167 () ;
if ( ! ( V_2 -> V_4 . V_307 & V_311 ) ) {
F_168 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_307 |= V_311 ;
}
F_169 () ;
}
void F_170 ( struct V_1 * V_2 )
{
struct V_91 * V_76 = V_2 -> V_4 . V_76 ;
unsigned int V_305 , V_306 ;
F_163 () ;
if ( F_70 ( & V_2 -> V_4 ) ) {
V_305 = F_71 ( V_76 ) ;
if ( ! ( V_305 & V_107 ) &&
( V_2 -> V_4 . V_307 & ( V_311 |
V_308 ) ) == V_311 )
F_164 ( V_2 ) ;
F_165 ( V_303 | V_107 , V_305 ) ;
if ( V_305 & V_303 && V_309 ) {
V_306 = F_94 ( V_76 ) ;
F_166 ( V_310 , V_306 ) ;
}
}
F_171 ( V_304 ) ;
F_167 () ;
switch ( V_2 -> V_4 . V_307 & ( V_311 | V_308 ) ) {
case V_311 :
F_172 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_307 |= V_308 ;
break;
case 0 :
F_173 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_307 |= V_308 ;
if ( F_70 ( & V_2 -> V_4 ) )
V_2 -> V_4 . V_307 |= V_311 ;
break;
default:
break;
}
F_169 () ;
}
void F_174 ( struct V_1 * V_2 )
{
F_163 () ;
if ( V_202 && V_2 -> V_4 . V_307 & V_308 ) {
F_175 () ;
V_2 -> V_4 . V_307 &= ~ V_308 ;
}
if ( V_2 -> V_4 . V_307 & V_311 ) {
F_176 ( V_303 | V_107 ) ;
V_2 -> V_4 . V_307 &= ~ V_311 ;
}
F_169 () ;
}
void F_164 ( struct V_1 * V_2 )
{
F_163 () ;
if ( V_202 && V_2 -> V_4 . V_307 & V_308 ) {
F_171 ( V_304 ) ;
F_167 () ;
F_177 ( & V_2 -> V_4 ) ;
F_175 () ;
if ( V_2 -> V_4 . V_307 & V_311 )
F_176 ( V_303 | V_107 ) ;
V_2 -> V_4 . V_307 &= ~ ( V_311 | V_308 ) ;
} else if ( V_2 -> V_4 . V_307 & V_311 ) {
F_178 ( V_303 ) ;
F_167 () ;
F_179 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_307 &= ~ V_311 ;
F_176 ( V_303 | V_107 ) ;
}
F_169 () ;
}
static int F_180 ( struct V_312 * V_313 ,
unsigned long V_314 , void * V_315 )
{
struct V_316 * args = (struct V_316 * ) V_315 ;
struct V_317 * V_205 = args -> V_205 ;
unsigned long V_106 ;
if ( V_314 != V_318 && V_314 != V_319 )
return V_320 ;
if ( ! ( V_298 -> V_158 & V_321 ) )
return V_320 ;
F_181 ( F_182 ( V_205 ) ) ;
V_106 = F_183 ( V_205 ) ;
switch ( V_314 ) {
case V_318 :
if ( V_106 != ( unsigned long ) & F_159 + 4 )
return V_320 ;
break;
case V_319 :
if ( ! V_202 ||
V_106 < ( unsigned long ) & F_161 + 4 ||
V_106 > ( unsigned long ) & F_161 + 8 )
return V_320 ;
break;
}
F_183 ( V_205 ) += 4 ;
return V_322 ;
}
static int T_8 F_184 ( void )
{
int V_94 ;
V_94 = F_185 ( NULL , sizeof( struct V_1 ) , 0 , V_323 ) ;
if ( V_94 )
return V_94 ;
F_186 ( & V_324 ) ;
V_325 = V_326 ;
F_19 = V_327 ;
V_328 = V_329 ;
return 0 ;
}
static void T_9 F_187 ( void )
{
F_188 () ;
V_325 = NULL ;
F_19 = NULL ;
V_328 = NULL ;
F_189 ( & V_324 ) ;
}
