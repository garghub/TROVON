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
goto V_49;
}
F_12 ( L_8 ,
F_40 ( V_44 , V_54 ) , V_46 ) ;
V_2 -> V_4 . V_55 = V_46 ;
memcpy ( V_46 , V_56 ,
V_57 - V_56 ) ;
memcpy ( V_46 + 0x180 , V_56 ,
V_57 - V_56 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
F_12 ( L_9 ,
V_46 + 0x200 + ( V_3 * V_52 ) ) ;
memcpy ( V_46 + 0x200 + ( V_3 * V_52 ) , V_56 ,
V_57 - V_56 ) ;
}
V_45 = 0x2000 ;
F_12 ( L_10 ,
V_46 + V_45 ,
V_58 - V_59 ) ;
memcpy ( V_46 + V_45 , V_59 ,
V_58 - V_59 ) ;
F_41 ( ( unsigned long ) V_46 ,
( unsigned long ) V_46 + F_40 ( V_44 , V_54 ) ) ;
V_2 -> V_4 . V_60 = F_35 ( V_54 << 1 , V_41 ) ;
if ( ! V_2 -> V_4 . V_60 ) {
V_43 = - V_47 ;
goto V_61;
}
F_12 ( L_11 , V_2 -> V_4 . V_60 ) ;
F_42 ( V_2 ) ;
V_2 -> V_4 . V_62 = - 1 ;
F_43 ( V_2 ) ;
return V_2 ;
V_61:
F_20 ( V_46 ) ;
V_49:
F_20 ( V_2 ) ;
V_48:
return F_44 ( V_43 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_45 ( & V_2 -> V_4 . V_63 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_20 ( V_2 -> V_4 . V_55 ) ;
F_20 ( V_2 -> V_4 . V_60 ) ;
F_20 ( V_2 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
return - V_26 ;
}
int F_50 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
int V_68 = 0 ;
T_1 V_69 ;
if ( V_2 -> V_70 )
F_51 ( V_71 , & V_2 -> V_72 , & V_69 ) ;
if ( V_2 -> V_73 ) {
if ( ! V_2 -> V_74 )
F_52 ( V_2 , V_67 ) ;
V_2 -> V_73 = 0 ;
}
F_53 ( 1 ) ;
F_54 () ;
F_55 ( V_2 ,
F_56 ( V_2 -> V_4 . V_75 ) ) ;
F_57 () ;
F_58 () ;
V_68 = F_59 ( V_67 , V_2 ) ;
F_60 () ;
F_61 () ;
F_62 () ;
if ( V_2 -> V_70 )
F_51 ( V_71 , & V_69 , NULL ) ;
return V_68 ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_76 * V_77 )
{
int V_78 = ( int ) V_77 -> V_77 ;
struct V_1 * V_79 = NULL ;
if ( V_78 == 3 || V_78 == - 3 || V_78 == 4 || V_78 == - 4 )
F_12 ( L_12 , V_16 , V_77 -> V_80 ,
( int ) V_78 ) ;
if ( V_77 -> V_80 == - 1 )
V_79 = V_2 ;
else
V_79 = V_2 -> V_9 -> V_22 [ V_77 -> V_80 ] ;
if ( V_78 == 2 || V_78 == 3 || V_78 == 4 ) {
V_13 -> V_81 ( V_79 , V_77 ) ;
} else if ( V_78 == - 2 || V_78 == - 3 || V_78 == - 4 ) {
V_13 -> V_82 ( V_79 , V_77 ) ;
} else {
F_36 ( L_13 , V_16 ,
V_77 -> V_80 , V_77 -> V_77 ) ;
return - V_83 ;
}
V_79 -> V_4 . V_84 = 0 ;
if ( F_64 ( & V_79 -> V_85 ) )
F_65 ( & V_79 -> V_85 ) ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
return - V_26 ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
return - V_26 ;
}
static int F_68 ( struct V_1 * V_2 ,
const struct V_88 * V_89 )
{
struct V_90 * V_75 = V_2 -> V_4 . V_75 ;
struct V_91 * V_92 = & V_2 -> V_4 . V_92 ;
int V_93 ;
T_2 V_94 ;
T_2 V_95 [ 2 ] ;
unsigned int V_96 ;
switch ( V_89 -> V_42 ) {
case V_97 ... V_98 :
V_94 = ( long ) V_2 -> V_4 . V_99 [ V_89 -> V_42 - V_97 ] ;
break;
case V_100 :
V_94 = ( long ) V_2 -> V_4 . V_101 ;
break;
case V_102 :
V_94 = ( long ) V_2 -> V_4 . V_103 ;
break;
case V_104 :
V_94 = ( long ) V_2 -> V_4 . V_105 ;
break;
case F_69 ( 0 ) ... F_69 ( 31 ) :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_83 ;
V_96 = V_89 -> V_42 - F_69 ( 0 ) ;
if ( F_71 ( V_75 ) & V_106 )
V_94 = F_72 ( & V_92 -> V_107 [ V_96 ] , 0 ) ;
else
V_94 = F_72 ( & V_92 -> V_107 [ V_96 & ~ 1 ] , V_96 & 1 ) ;
break;
case F_73 ( 0 ) ... F_73 ( 31 ) :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_83 ;
V_96 = V_89 -> V_42 - F_73 ( 0 ) ;
if ( V_96 & 1 && ! ( F_71 ( V_75 ) & V_106 ) )
return - V_83 ;
V_94 = F_74 ( & V_92 -> V_107 [ V_96 ] , 0 ) ;
break;
case V_108 :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_83 ;
V_94 = V_109 . V_110 ;
break;
case V_111 :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_83 ;
V_94 = V_92 -> V_112 ;
break;
case F_75 ( 0 ) ... F_75 ( 31 ) :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_83 ;
if ( ! ( F_71 ( V_75 ) & V_106 ) )
return - V_83 ;
V_96 = V_89 -> V_42 - F_75 ( 0 ) ;
#ifdef F_77
V_95 [ 0 ] = F_74 ( & V_92 -> V_107 [ V_96 ] , 0 ) ;
V_95 [ 1 ] = F_74 ( & V_92 -> V_107 [ V_96 ] , 1 ) ;
#else
V_95 [ 0 ] = F_74 ( & V_92 -> V_107 [ V_96 ] , 1 ) ;
V_95 [ 1 ] = F_74 ( & V_92 -> V_107 [ V_96 ] , 0 ) ;
#endif
break;
case V_113 :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_83 ;
V_94 = V_109 . V_114 ;
break;
case V_115 :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_83 ;
V_94 = V_92 -> V_116 ;
break;
case V_117 :
V_94 = ( long ) F_78 ( V_75 ) ;
break;
case V_118 :
V_94 = ( long ) F_79 ( V_75 ) ;
break;
case V_119 :
V_94 = ( long ) F_80 ( V_75 ) ;
break;
case V_120 :
V_94 = ( long ) F_81 ( V_75 ) ;
break;
case V_121 :
V_94 = ( long ) F_82 ( V_75 ) ;
break;
case V_122 :
V_94 = ( long ) F_83 ( V_75 ) ;
break;
case V_123 :
V_94 = ( long ) F_84 ( V_75 ) ;
break;
case V_124 :
V_94 = ( long ) F_85 ( V_75 ) ;
break;
case V_125 :
V_94 = ( long ) F_86 ( V_75 ) ;
break;
case V_126 :
V_94 = ( long ) F_71 ( V_75 ) ;
break;
case V_127 :
V_94 = ( long ) F_56 ( V_75 ) ;
break;
case V_128 :
V_94 = ( long ) F_87 ( V_75 ) ;
break;
case V_129 :
V_94 = ( long ) F_88 ( V_75 ) ;
break;
case V_130 :
V_94 = ( long ) F_89 ( V_75 ) ;
break;
case V_131 :
V_94 = ( long ) F_90 ( V_75 ) ;
break;
case V_132 :
V_94 = ( long ) F_91 ( V_75 ) ;
break;
case V_133 :
V_94 = ( long ) F_92 ( V_75 ) ;
break;
case V_134 :
V_94 = ( long ) F_93 ( V_75 ) ;
break;
case V_135 :
V_94 = ( long ) F_94 ( V_75 ) ;
break;
case V_136 :
V_94 = ( long ) F_95 ( V_75 ) ;
break;
case V_137 :
V_94 = ( long ) F_96 ( V_75 ) ;
break;
case V_138 :
case V_139 :
case V_140 :
case V_141 :
V_93 = V_13 -> V_142 ( V_2 , V_89 , & V_94 ) ;
if ( V_93 )
return V_93 ;
break;
default:
return - V_83 ;
}
if ( ( V_89 -> V_42 & V_143 ) == V_144 ) {
T_3 T_4 * V_145 = ( T_3 T_4 * ) ( long ) V_89 -> V_146 ;
return F_97 ( V_94 , V_145 ) ;
} else if ( ( V_89 -> V_42 & V_143 ) == V_147 ) {
T_5 T_4 * V_148 = ( T_5 T_4 * ) ( long ) V_89 -> V_146 ;
T_5 V_149 = ( T_5 ) V_94 ;
return F_97 ( V_149 , V_148 ) ;
} else if ( ( V_89 -> V_42 & V_143 ) == V_150 ) {
void T_4 * V_151 = ( void T_4 * ) ( long ) V_89 -> V_146 ;
return F_98 ( V_151 , V_95 , 16 ) ;
} else {
return - V_83 ;
}
}
static int F_99 ( struct V_1 * V_2 ,
const struct V_88 * V_89 )
{
struct V_90 * V_75 = V_2 -> V_4 . V_75 ;
struct V_91 * V_92 = & V_2 -> V_4 . V_92 ;
T_2 V_94 ;
T_2 V_95 [ 2 ] ;
unsigned int V_96 ;
if ( ( V_89 -> V_42 & V_143 ) == V_144 ) {
T_3 T_4 * V_145 = ( T_3 T_4 * ) ( long ) V_89 -> V_146 ;
if ( F_100 ( V_94 , V_145 ) != 0 )
return - V_152 ;
} else if ( ( V_89 -> V_42 & V_143 ) == V_147 ) {
T_5 T_4 * V_148 = ( T_5 T_4 * ) ( long ) V_89 -> V_146 ;
T_6 V_149 ;
if ( F_100 ( V_149 , V_148 ) != 0 )
return - V_152 ;
V_94 = ( T_2 ) V_149 ;
} else if ( ( V_89 -> V_42 & V_143 ) == V_150 ) {
void T_4 * V_151 = ( void T_4 * ) ( long ) V_89 -> V_146 ;
return F_101 ( V_95 , V_151 , 16 ) ;
} else {
return - V_83 ;
}
switch ( V_89 -> V_42 ) {
case V_97 :
break;
case V_153 ... V_98 :
V_2 -> V_4 . V_99 [ V_89 -> V_42 - V_97 ] = V_94 ;
break;
case V_100 :
V_2 -> V_4 . V_101 = V_94 ;
break;
case V_102 :
V_2 -> V_4 . V_103 = V_94 ;
break;
case V_104 :
V_2 -> V_4 . V_105 = V_94 ;
break;
case F_69 ( 0 ) ... F_69 ( 31 ) :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_83 ;
V_96 = V_89 -> V_42 - F_69 ( 0 ) ;
if ( F_71 ( V_75 ) & V_106 )
F_102 ( & V_92 -> V_107 [ V_96 ] , 0 , V_94 ) ;
else
F_102 ( & V_92 -> V_107 [ V_96 & ~ 1 ] , V_96 & 1 , V_94 ) ;
break;
case F_73 ( 0 ) ... F_73 ( 31 ) :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_83 ;
V_96 = V_89 -> V_42 - F_73 ( 0 ) ;
if ( V_96 & 1 && ! ( F_71 ( V_75 ) & V_106 ) )
return - V_83 ;
F_103 ( & V_92 -> V_107 [ V_96 ] , 0 , V_94 ) ;
break;
case V_108 :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_83 ;
break;
case V_111 :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_83 ;
V_92 -> V_112 = V_94 ;
break;
case F_75 ( 0 ) ... F_75 ( 31 ) :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_83 ;
V_96 = V_89 -> V_42 - F_75 ( 0 ) ;
#ifdef F_77
F_103 ( & V_92 -> V_107 [ V_96 ] , 0 , V_95 [ 0 ] ) ;
F_103 ( & V_92 -> V_107 [ V_96 ] , 1 , V_95 [ 1 ] ) ;
#else
F_103 ( & V_92 -> V_107 [ V_96 ] , 1 , V_95 [ 0 ] ) ;
F_103 ( & V_92 -> V_107 [ V_96 ] , 0 , V_95 [ 1 ] ) ;
#endif
break;
case V_113 :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_83 ;
break;
case V_115 :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_83 ;
V_92 -> V_116 = V_94 ;
break;
case V_117 :
F_104 ( V_75 , V_94 ) ;
break;
case V_118 :
F_105 ( V_75 , V_94 ) ;
break;
case V_119 :
F_106 ( V_75 , V_94 ) ;
break;
case V_120 :
F_107 ( V_75 , V_94 ) ;
break;
case V_121 :
F_108 ( V_75 , V_94 ) ;
break;
case V_122 :
F_109 ( V_75 , V_94 ) ;
break;
case V_123 :
F_110 ( V_75 , V_94 ) ;
break;
case V_124 :
F_111 ( V_75 , V_94 ) ;
break;
case V_126 :
F_112 ( V_75 , V_94 ) ;
break;
case V_128 :
F_113 ( V_75 , V_94 ) ;
break;
case V_129 :
F_114 ( V_75 , V_94 ) ;
break;
case V_137 :
F_115 ( V_75 , V_94 ) ;
break;
case V_138 :
case V_125 :
case V_127 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_139 :
case V_140 :
case V_141 :
return V_13 -> V_154 ( V_2 , V_89 , V_94 ) ;
default:
return - V_83 ;
}
return 0 ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_155 * V_156 )
{
int V_68 = 0 ;
if ( ! F_117 ( V_2 -> V_9 , V_156 -> V_156 ) )
return - V_83 ;
if ( V_156 -> V_157 )
return - V_83 ;
if ( V_156 -> args [ 0 ] )
return - V_83 ;
switch ( V_156 -> V_156 ) {
case V_158 :
V_2 -> V_4 . V_159 = true ;
break;
case V_160 :
V_2 -> V_4 . V_161 = true ;
break;
default:
V_68 = - V_83 ;
break;
}
return V_68 ;
}
long F_118 ( struct V_23 * V_24 , unsigned int V_25 ,
unsigned long V_12 )
{
struct V_1 * V_2 = V_24 -> V_162 ;
void T_4 * V_163 = ( void T_4 * ) V_12 ;
long V_68 ;
switch ( V_25 ) {
case V_164 :
case V_165 : {
struct V_88 V_89 ;
if ( F_101 ( & V_89 , V_163 , sizeof( V_89 ) ) )
return - V_152 ;
if ( V_25 == V_164 )
return F_99 ( V_2 , & V_89 ) ;
else
return F_68 ( V_2 , & V_89 ) ;
}
case V_166 : {
struct V_167 T_4 * V_168 = V_163 ;
T_3 T_4 * V_169 ;
struct V_167 V_170 ;
unsigned V_171 ;
if ( F_101 ( & V_170 , V_168 , sizeof( V_170 ) ) )
return - V_152 ;
V_171 = V_170 . V_171 ;
V_170 . V_171 = F_119 ( V_172 ) ;
if ( F_98 ( V_168 , & V_170 , sizeof( V_170 ) ) )
return - V_152 ;
if ( V_171 < V_170 . V_171 )
return - V_173 ;
V_169 = V_168 -> V_89 ;
if ( F_98 ( V_169 , V_172 ,
sizeof( V_172 ) ) )
return - V_152 ;
return 0 ;
}
case V_174 :
V_68 = F_1 ( V_2 ) ;
break;
case V_175 :
{
struct V_76 V_77 ;
V_68 = - V_152 ;
if ( F_101 ( & V_77 , V_163 , sizeof( V_77 ) ) )
goto V_48;
F_12 ( L_14 , V_2 -> V_176 , V_16 ,
V_77 . V_77 ) ;
V_68 = F_63 ( V_2 , & V_77 ) ;
break;
}
case V_177 : {
struct V_155 V_156 ;
V_68 = - V_152 ;
if ( F_101 ( & V_156 , V_163 , sizeof( V_156 ) ) )
goto V_48;
V_68 = F_116 ( V_2 , & V_156 ) ;
break;
}
default:
V_68 = - V_26 ;
}
V_48:
return V_68 ;
}
int F_120 ( struct V_9 * V_9 , struct V_178 * log )
{
struct V_179 * V_180 ;
struct V_27 * V_30 ;
unsigned long V_181 , V_182 ;
int V_183 = 0 ;
int V_68 ;
unsigned long V_171 ;
F_23 ( & V_9 -> V_184 ) ;
V_68 = F_121 ( V_9 , log , & V_183 ) ;
if ( V_68 )
goto V_48;
if ( V_183 ) {
V_180 = V_179 ( V_9 ) ;
V_30 = F_122 ( V_180 , log -> V_28 ) ;
V_181 = V_30 -> V_185 << V_40 ;
V_182 = V_181 + ( V_30 -> V_29 << V_40 ) ;
F_123 ( L_15 , V_16 , V_181 ,
V_182 ) ;
V_171 = F_124 ( V_30 ) ;
memset ( V_30 -> V_186 , 0 , V_171 ) ;
}
V_68 = 0 ;
V_48:
F_26 ( & V_9 -> V_184 ) ;
return V_68 ;
}
long F_125 ( struct V_23 * V_24 , unsigned int V_25 , unsigned long V_12 )
{
long V_68 ;
switch ( V_25 ) {
default:
V_68 = - V_26 ;
}
return V_68 ;
}
int F_126 ( void * V_187 )
{
if ( V_13 ) {
F_36 ( L_16 ) ;
return - V_188 ;
}
return F_127 ( & V_13 ) ;
}
void F_128 ( void )
{
V_13 = NULL ;
}
int F_129 ( struct V_1 * V_2 ,
struct V_189 * V_190 )
{
return - V_26 ;
}
int F_130 ( struct V_1 * V_2 ,
struct V_189 * V_190 )
{
return - V_26 ;
}
void F_131 ( struct V_1 * V_2 )
{
}
int F_132 ( struct V_1 * V_2 , struct V_191 * V_92 )
{
return - V_26 ;
}
int F_133 ( struct V_1 * V_2 , struct V_191 * V_92 )
{
return - V_26 ;
}
int F_134 ( struct V_1 * V_2 , struct V_192 * V_193 )
{
return V_194 ;
}
int F_117 ( struct V_9 * V_9 , long V_195 )
{
int V_68 ;
switch ( V_195 ) {
case V_196 :
case V_197 :
V_68 = 1 ;
break;
case V_198 :
V_68 = V_199 ;
break;
case V_158 :
V_68 = ! ! V_200 ;
break;
case V_160 :
V_68 = V_201 && ! ( V_109 . V_114 & V_202 ) ;
break;
default:
V_68 = 0 ;
break;
}
return V_68 ;
}
int F_135 ( struct V_1 * V_2 )
{
return F_136 ( V_2 ) ;
}
int F_137 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_90 * V_75 ;
if ( ! V_2 )
return - 1 ;
F_12 ( L_17 ) ;
F_12 ( L_18 , V_2 -> V_4 . V_105 ) ;
F_12 ( L_19 , V_2 -> V_4 . V_7 ) ;
for ( V_3 = 0 ; V_3 < 32 ; V_3 += 4 ) {
F_12 ( L_20 , V_3 ,
V_2 -> V_4 . V_99 [ V_3 ] ,
V_2 -> V_4 . V_99 [ V_3 + 1 ] ,
V_2 -> V_4 . V_99 [ V_3 + 2 ] , V_2 -> V_4 . V_99 [ V_3 + 3 ] ) ;
}
F_12 ( L_21 , V_2 -> V_4 . V_101 ) ;
F_12 ( L_22 , V_2 -> V_4 . V_103 ) ;
V_75 = V_2 -> V_4 . V_75 ;
F_12 ( L_23 ,
F_71 ( V_75 ) ,
F_56 ( V_75 ) ) ;
F_12 ( L_24 , F_87 ( V_75 ) ) ;
return 0 ;
}
int F_138 ( struct V_1 * V_2 , struct V_203 * V_204 )
{
int V_3 ;
for ( V_3 = 1 ; V_3 < F_119 ( V_2 -> V_4 . V_99 ) ; V_3 ++ )
V_2 -> V_4 . V_99 [ V_3 ] = V_204 -> V_205 [ V_3 ] ;
V_2 -> V_4 . V_99 [ 0 ] = 0 ;
V_2 -> V_4 . V_101 = V_204 -> V_101 ;
V_2 -> V_4 . V_103 = V_204 -> V_103 ;
V_2 -> V_4 . V_105 = V_204 -> V_105 ;
return 0 ;
}
int F_139 ( struct V_1 * V_2 , struct V_203 * V_204 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_119 ( V_2 -> V_4 . V_99 ) ; V_3 ++ )
V_204 -> V_205 [ V_3 ] = V_2 -> V_4 . V_99 [ V_3 ] ;
V_204 -> V_101 = V_2 -> V_4 . V_101 ;
V_204 -> V_103 = V_2 -> V_4 . V_103 ;
V_204 -> V_105 = V_2 -> V_4 . V_105 ;
return 0 ;
}
static void F_140 ( unsigned long V_206 )
{
struct V_1 * V_2 = (struct V_1 * ) V_206 ;
V_13 -> V_207 ( V_2 ) ;
V_2 -> V_4 . V_84 = 0 ;
if ( F_64 ( & V_2 -> V_85 ) )
F_65 ( & V_2 -> V_85 ) ;
}
static enum V_208 F_141 ( struct V_209 * V_210 )
{
struct V_1 * V_2 ;
V_2 = F_142 ( V_210 , struct V_1 , V_4 . V_63 ) ;
F_140 ( ( unsigned long ) V_2 ) ;
return F_143 ( V_2 ) ;
}
int F_144 ( struct V_1 * V_2 )
{
V_13 -> V_211 ( V_2 ) ;
F_145 ( & V_2 -> V_4 . V_63 , V_212 ,
V_213 ) ;
V_2 -> V_4 . V_63 . V_214 = F_141 ;
return 0 ;
}
int F_146 ( struct V_1 * V_2 ,
struct V_215 * V_216 )
{
return 0 ;
}
int F_147 ( struct V_1 * V_2 )
{
return V_13 -> V_217 ( V_2 ) ;
}
static void F_148 ( void )
{
T_7 V_218 = F_149 () ;
if ( V_219 )
V_218 |= ( V_220 ) ;
F_150 ( V_218 ) ;
F_151 () ;
}
int F_152 ( struct V_66 * V_67 , struct V_1 * V_2 )
{
T_7 V_221 = V_2 -> V_4 . V_222 ;
T_7 V_223 = ( V_221 >> V_224 ) & 0x1f ;
T_7 T_4 * V_225 = ( T_7 T_4 * ) V_2 -> V_4 . V_105 ;
unsigned long V_226 = V_2 -> V_4 . V_227 ;
enum V_228 V_229 = V_230 ;
int V_93 = V_231 ;
F_60 () ;
V_67 -> V_232 = V_233 ;
V_67 -> V_234 = 1 ;
F_148 () ;
F_62 () ;
F_12 ( L_25 ,
V_221 , V_225 , V_67 , V_2 ) ;
V_229 = F_153 ( V_221 , V_225 , V_67 , V_2 ) ;
if ( V_229 == V_235 ) {
goto V_236;
} else if ( V_229 == V_237 ) {
V_67 -> V_232 = V_238 ;
V_93 = V_239 ;
goto V_236;
}
switch ( V_223 ) {
case V_240 :
F_12 ( L_26 , V_2 -> V_176 , V_225 ) ;
++ V_2 -> V_241 . V_242 ;
F_154 ( V_2 , V_243 ) ;
if ( F_155 () )
F_156 () ;
V_93 = V_231 ;
break;
case V_244 :
F_12 ( L_27 , V_225 ) ;
++ V_2 -> V_241 . V_245 ;
F_154 ( V_2 , V_246 ) ;
V_93 = V_13 -> V_247 ( V_2 ) ;
if ( V_67 -> V_232 == V_248 )
V_93 = V_239 ;
break;
case V_249 :
++ V_2 -> V_241 . V_250 ;
F_154 ( V_2 , V_251 ) ;
V_93 = V_13 -> V_252 ( V_2 ) ;
break;
case V_253 :
F_12 ( L_28 ,
V_221 , F_71 ( V_2 -> V_4 . V_75 ) , V_225 ,
V_226 ) ;
++ V_2 -> V_241 . V_254 ;
F_154 ( V_2 , V_255 ) ;
V_93 = V_13 -> V_256 ( V_2 ) ;
break;
case V_257 :
F_12 ( L_29 ,
V_221 , V_225 , V_226 ) ;
++ V_2 -> V_241 . V_258 ;
F_154 ( V_2 , V_259 ) ;
V_93 = V_13 -> V_260 ( V_2 ) ;
break;
case V_261 :
++ V_2 -> V_241 . V_262 ;
F_154 ( V_2 , V_263 ) ;
V_93 = V_13 -> V_264 ( V_2 ) ;
break;
case V_265 :
++ V_2 -> V_241 . V_266 ;
F_154 ( V_2 , V_267 ) ;
V_93 = V_13 -> V_268 ( V_2 ) ;
break;
case V_269 :
++ V_2 -> V_241 . V_270 ;
F_154 ( V_2 , V_271 ) ;
V_93 = V_13 -> V_272 ( V_2 ) ;
break;
case V_273 :
++ V_2 -> V_241 . V_274 ;
F_154 ( V_2 , V_275 ) ;
V_93 = V_13 -> V_276 ( V_2 ) ;
break;
case V_277 :
++ V_2 -> V_241 . V_278 ;
F_154 ( V_2 , V_279 ) ;
V_93 = V_13 -> V_280 ( V_2 ) ;
break;
case V_281 :
++ V_2 -> V_241 . V_282 ;
F_154 ( V_2 , V_283 ) ;
V_93 = V_13 -> V_284 ( V_2 ) ;
break;
case V_285 :
++ V_2 -> V_241 . V_286 ;
F_154 ( V_2 , V_287 ) ;
V_93 = V_13 -> V_288 ( V_2 ) ;
break;
case V_289 :
++ V_2 -> V_241 . V_290 ;
F_154 ( V_2 , V_291 ) ;
V_93 = V_13 -> V_292 ( V_2 ) ;
break;
case V_293 :
++ V_2 -> V_241 . V_294 ;
F_154 ( V_2 , V_295 ) ;
V_93 = V_13 -> V_296 ( V_2 ) ;
break;
default:
F_36 ( L_30 ,
V_223 , V_225 , F_157 ( V_225 , V_2 ) , V_226 ,
F_71 ( V_2 -> V_4 . V_75 ) ) ;
F_137 ( V_2 ) ;
V_67 -> V_232 = V_238 ;
V_93 = V_239 ;
break;
}
V_236:
F_54 () ;
if ( V_229 == V_230 && ! ( V_93 & V_239 ) )
F_55 ( V_2 , V_221 ) ;
if ( ! ( V_93 & V_239 ) ) {
if ( F_158 ( V_297 ) ) {
V_67 -> V_232 = V_298 ;
V_93 = ( - V_299 << 2 ) | V_239 ;
++ V_2 -> V_241 . V_300 ;
F_154 ( V_2 , V_301 ) ;
}
}
if ( V_93 == V_231 ) {
if ( F_70 ( & V_2 -> V_4 ) &&
F_149 () & V_302 )
F_159 ( & V_2 -> V_4 ) ;
if ( F_76 ( & V_2 -> V_4 ) &&
F_160 () & V_303 )
F_161 ( & V_2 -> V_4 ) ;
}
F_58 () ;
return V_93 ;
}
void F_162 ( struct V_1 * V_2 )
{
struct V_90 * V_75 = V_2 -> V_4 . V_75 ;
unsigned int V_304 , V_305 ;
F_163 () ;
V_304 = F_71 ( V_75 ) ;
if ( V_201 && V_304 & V_302 && ! ( V_304 & V_106 ) &&
V_2 -> V_4 . V_306 & V_307 )
F_164 ( V_2 ) ;
F_165 ( V_302 | V_106 , V_304 ) ;
if ( V_308 ) {
V_305 = F_94 ( V_75 ) ;
F_166 ( V_309 , V_305 ) ;
}
F_167 () ;
if ( ! ( V_2 -> V_4 . V_306 & V_310 ) ) {
F_168 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_306 |= V_310 ;
}
F_169 () ;
}
void F_170 ( struct V_1 * V_2 )
{
struct V_90 * V_75 = V_2 -> V_4 . V_75 ;
unsigned int V_304 , V_305 ;
F_163 () ;
if ( F_70 ( & V_2 -> V_4 ) ) {
V_304 = F_71 ( V_75 ) ;
if ( ! ( V_304 & V_106 ) &&
( V_2 -> V_4 . V_306 & ( V_310 |
V_307 ) ) == V_310 )
F_164 ( V_2 ) ;
F_165 ( V_302 | V_106 , V_304 ) ;
if ( V_304 & V_302 && V_308 ) {
V_305 = F_94 ( V_75 ) ;
F_166 ( V_309 , V_305 ) ;
}
}
F_171 ( V_303 ) ;
F_167 () ;
switch ( V_2 -> V_4 . V_306 & ( V_310 | V_307 ) ) {
case V_310 :
F_172 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_306 |= V_307 ;
break;
case 0 :
F_173 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_306 |= V_307 ;
if ( F_70 ( & V_2 -> V_4 ) )
V_2 -> V_4 . V_306 |= V_310 ;
break;
default:
break;
}
F_169 () ;
}
void F_174 ( struct V_1 * V_2 )
{
F_163 () ;
if ( V_201 && V_2 -> V_4 . V_306 & V_307 ) {
F_175 () ;
V_2 -> V_4 . V_306 &= ~ V_307 ;
}
if ( V_2 -> V_4 . V_306 & V_310 ) {
F_176 ( V_302 | V_106 ) ;
V_2 -> V_4 . V_306 &= ~ V_310 ;
}
F_169 () ;
}
void F_164 ( struct V_1 * V_2 )
{
F_163 () ;
if ( V_201 && V_2 -> V_4 . V_306 & V_307 ) {
F_171 ( V_303 ) ;
F_167 () ;
F_177 ( & V_2 -> V_4 ) ;
F_175 () ;
if ( V_2 -> V_4 . V_306 & V_310 )
F_176 ( V_302 | V_106 ) ;
V_2 -> V_4 . V_306 &= ~ ( V_310 | V_307 ) ;
} else if ( V_2 -> V_4 . V_306 & V_310 ) {
F_178 ( V_302 ) ;
F_167 () ;
F_179 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_306 &= ~ V_310 ;
F_176 ( V_302 | V_106 ) ;
}
F_169 () ;
}
static int F_180 ( struct V_311 * V_312 ,
unsigned long V_313 , void * V_314 )
{
struct V_315 * args = (struct V_315 * ) V_314 ;
struct V_316 * V_204 = args -> V_204 ;
unsigned long V_105 ;
if ( V_313 != V_317 && V_313 != V_318 )
return V_319 ;
if ( ! ( V_297 -> V_157 & V_320 ) )
return V_319 ;
F_181 ( F_182 ( V_204 ) ) ;
V_105 = F_183 ( V_204 ) ;
switch ( V_313 ) {
case V_317 :
if ( V_105 != ( unsigned long ) & F_159 + 4 )
return V_319 ;
break;
case V_318 :
if ( ! V_201 ||
V_105 < ( unsigned long ) & F_161 + 4 ||
V_105 > ( unsigned long ) & F_161 + 8 )
return V_319 ;
break;
}
F_183 ( V_204 ) += 4 ;
return V_321 ;
}
int T_8 F_184 ( void )
{
int V_93 ;
V_93 = F_185 ( NULL , sizeof( struct V_1 ) , 0 , V_322 ) ;
if ( V_93 )
return V_93 ;
F_186 ( & V_323 ) ;
V_324 = V_325 ;
F_19 = V_326 ;
V_327 = V_328 ;
return 0 ;
}
void T_9 F_187 ( void )
{
F_188 () ;
V_324 = NULL ;
F_19 = NULL ;
V_327 = NULL ;
F_189 ( & V_323 ) ;
}
