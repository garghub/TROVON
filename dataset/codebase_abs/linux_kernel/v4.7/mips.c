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
#ifdef F_41
V_45 += V_59 - V_60 ;
memcpy ( V_46 + V_45 , ( char * ) V_61 ,
V_62 - ( char * ) V_61 ) ;
V_2 -> V_4 . V_63 = V_46 + V_45 ;
#else
V_2 -> V_4 . V_63 = V_61 ;
#endif
F_42 ( ( unsigned long ) V_46 ,
( unsigned long ) V_46 + F_40 ( V_44 , V_54 ) ) ;
V_2 -> V_4 . V_64 = F_35 ( V_54 << 1 , V_41 ) ;
if ( ! V_2 -> V_4 . V_64 ) {
V_43 = - V_47 ;
goto V_65;
}
F_12 ( L_11 , V_2 -> V_4 . V_64 ) ;
F_43 ( V_2 ) ;
V_2 -> V_4 . V_66 = - 1 ;
F_44 ( V_2 ) ;
return V_2 ;
V_65:
F_20 ( V_46 ) ;
V_55:
F_45 ( V_2 ) ;
V_49:
F_20 ( V_2 ) ;
V_48:
return F_46 ( V_43 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_47 ( & V_2 -> V_4 . V_67 ) ;
F_45 ( V_2 ) ;
F_48 ( V_2 ) ;
F_20 ( V_2 -> V_4 . V_56 ) ;
F_20 ( V_2 -> V_4 . V_64 ) ;
F_20 ( V_2 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
return - V_26 ;
}
int F_51 ( struct V_1 * V_2 , struct V_70 * V_71 )
{
int V_72 = 0 ;
T_1 V_73 ;
if ( V_2 -> V_74 )
F_52 ( V_75 , & V_2 -> V_76 , & V_73 ) ;
if ( V_2 -> V_77 ) {
if ( ! V_2 -> V_78 )
F_53 ( V_2 , V_71 ) ;
V_2 -> V_77 = 0 ;
}
F_54 ( 1 ) ;
F_55 () ;
F_56 ( V_2 ,
F_57 ( V_2 -> V_4 . V_79 ) ) ;
F_58 () ;
F_59 () ;
V_72 = V_2 -> V_4 . V_63 ( V_71 , V_2 ) ;
F_60 () ;
F_61 () ;
F_62 () ;
if ( V_2 -> V_74 )
F_52 ( V_75 , & V_73 , NULL ) ;
return V_72 ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_80 * V_81 )
{
int V_82 = ( int ) V_81 -> V_81 ;
struct V_1 * V_83 = NULL ;
if ( V_82 == 3 || V_82 == - 3 || V_82 == 4 || V_82 == - 4 )
F_12 ( L_12 , V_16 , V_81 -> V_84 ,
( int ) V_82 ) ;
if ( V_81 -> V_84 == - 1 )
V_83 = V_2 ;
else
V_83 = V_2 -> V_9 -> V_22 [ V_81 -> V_84 ] ;
if ( V_82 == 2 || V_82 == 3 || V_82 == 4 ) {
V_13 -> V_85 ( V_83 , V_81 ) ;
} else if ( V_82 == - 2 || V_82 == - 3 || V_82 == - 4 ) {
V_13 -> V_86 ( V_83 , V_81 ) ;
} else {
F_36 ( L_13 , V_16 ,
V_81 -> V_84 , V_81 -> V_81 ) ;
return - V_87 ;
}
V_83 -> V_4 . V_88 = 0 ;
if ( F_64 ( & V_83 -> V_89 ) )
F_65 ( & V_83 -> V_89 ) ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 ,
struct V_90 * V_91 )
{
return - V_26 ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_90 * V_91 )
{
return - V_26 ;
}
static int F_68 ( struct V_1 * V_2 ,
const struct V_92 * V_93 )
{
struct V_94 * V_79 = V_2 -> V_4 . V_79 ;
struct V_95 * V_96 = & V_2 -> V_4 . V_96 ;
int V_97 ;
T_2 V_98 ;
T_2 V_99 [ 2 ] ;
unsigned int V_100 ;
switch ( V_93 -> V_42 ) {
case V_101 ... V_102 :
V_98 = ( long ) V_2 -> V_4 . V_103 [ V_93 -> V_42 - V_101 ] ;
break;
case V_104 :
V_98 = ( long ) V_2 -> V_4 . V_105 ;
break;
case V_106 :
V_98 = ( long ) V_2 -> V_4 . V_107 ;
break;
case V_108 :
V_98 = ( long ) V_2 -> V_4 . V_109 ;
break;
case F_69 ( 0 ) ... F_69 ( 31 ) :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_87 ;
V_100 = V_93 -> V_42 - F_69 ( 0 ) ;
if ( F_71 ( V_79 ) & V_110 )
V_98 = F_72 ( & V_96 -> V_111 [ V_100 ] , 0 ) ;
else
V_98 = F_72 ( & V_96 -> V_111 [ V_100 & ~ 1 ] , V_100 & 1 ) ;
break;
case F_73 ( 0 ) ... F_73 ( 31 ) :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_87 ;
V_100 = V_93 -> V_42 - F_73 ( 0 ) ;
if ( V_100 & 1 && ! ( F_71 ( V_79 ) & V_110 ) )
return - V_87 ;
V_98 = F_74 ( & V_96 -> V_111 [ V_100 ] , 0 ) ;
break;
case V_112 :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_87 ;
V_98 = V_113 . V_114 ;
break;
case V_115 :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_87 ;
V_98 = V_96 -> V_116 ;
break;
case F_75 ( 0 ) ... F_75 ( 31 ) :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_87 ;
if ( ! ( F_71 ( V_79 ) & V_110 ) )
return - V_87 ;
V_100 = V_93 -> V_42 - F_75 ( 0 ) ;
#ifdef F_77
V_99 [ 0 ] = F_74 ( & V_96 -> V_111 [ V_100 ] , 0 ) ;
V_99 [ 1 ] = F_74 ( & V_96 -> V_111 [ V_100 ] , 1 ) ;
#else
V_99 [ 0 ] = F_74 ( & V_96 -> V_111 [ V_100 ] , 1 ) ;
V_99 [ 1 ] = F_74 ( & V_96 -> V_111 [ V_100 ] , 0 ) ;
#endif
break;
case V_117 :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_87 ;
V_98 = V_113 . V_118 ;
break;
case V_119 :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_87 ;
V_98 = V_96 -> V_120 ;
break;
case V_121 :
V_98 = ( long ) F_78 ( V_79 ) ;
break;
case V_122 :
V_98 = ( long ) F_79 ( V_79 ) ;
break;
case V_123 :
V_98 = ( long ) F_80 ( V_79 ) ;
break;
case V_124 :
V_98 = ( long ) F_81 ( V_79 ) ;
break;
case V_125 :
V_98 = ( long ) F_82 ( V_79 ) ;
break;
case V_126 :
V_98 = ( long ) F_83 ( V_79 ) ;
break;
case V_127 :
V_98 = ( long ) F_84 ( V_79 ) ;
break;
case V_128 :
V_98 = ( long ) F_85 ( V_79 ) ;
break;
case V_129 :
V_98 = ( long ) F_86 ( V_79 ) ;
break;
case V_130 :
V_98 = ( long ) F_71 ( V_79 ) ;
break;
case V_131 :
V_98 = ( long ) F_57 ( V_79 ) ;
break;
case V_132 :
V_98 = ( long ) F_87 ( V_79 ) ;
break;
case V_133 :
V_98 = ( long ) F_88 ( V_79 ) ;
break;
case V_134 :
V_98 = ( long ) F_89 ( V_79 ) ;
break;
case V_135 :
V_98 = ( long ) F_90 ( V_79 ) ;
break;
case V_136 :
V_98 = ( long ) F_91 ( V_79 ) ;
break;
case V_137 :
V_98 = ( long ) F_92 ( V_79 ) ;
break;
case V_138 :
V_98 = ( long ) F_93 ( V_79 ) ;
break;
case V_139 :
V_98 = ( long ) F_94 ( V_79 ) ;
break;
case V_140 :
V_98 = ( long ) F_95 ( V_79 ) ;
break;
case V_141 :
V_98 = ( long ) F_96 ( V_79 ) ;
break;
case V_142 :
case V_143 :
case V_144 :
case V_145 :
V_97 = V_13 -> V_146 ( V_2 , V_93 , & V_98 ) ;
if ( V_97 )
return V_97 ;
break;
default:
return - V_87 ;
}
if ( ( V_93 -> V_42 & V_147 ) == V_148 ) {
T_3 T_4 * V_149 = ( T_3 T_4 * ) ( long ) V_93 -> V_150 ;
return F_97 ( V_98 , V_149 ) ;
} else if ( ( V_93 -> V_42 & V_147 ) == V_151 ) {
T_5 T_4 * V_152 = ( T_5 T_4 * ) ( long ) V_93 -> V_150 ;
T_5 V_153 = ( T_5 ) V_98 ;
return F_97 ( V_153 , V_152 ) ;
} else if ( ( V_93 -> V_42 & V_147 ) == V_154 ) {
void T_4 * V_155 = ( void T_4 * ) ( long ) V_93 -> V_150 ;
return F_98 ( V_155 , V_99 , 16 ) ? - V_156 : 0 ;
} else {
return - V_87 ;
}
}
static int F_99 ( struct V_1 * V_2 ,
const struct V_92 * V_93 )
{
struct V_94 * V_79 = V_2 -> V_4 . V_79 ;
struct V_95 * V_96 = & V_2 -> V_4 . V_96 ;
T_2 V_98 ;
T_2 V_99 [ 2 ] ;
unsigned int V_100 ;
if ( ( V_93 -> V_42 & V_147 ) == V_148 ) {
T_3 T_4 * V_149 = ( T_3 T_4 * ) ( long ) V_93 -> V_150 ;
if ( F_100 ( V_98 , V_149 ) != 0 )
return - V_156 ;
} else if ( ( V_93 -> V_42 & V_147 ) == V_151 ) {
T_5 T_4 * V_152 = ( T_5 T_4 * ) ( long ) V_93 -> V_150 ;
T_6 V_153 ;
if ( F_100 ( V_153 , V_152 ) != 0 )
return - V_156 ;
V_98 = ( T_2 ) V_153 ;
} else if ( ( V_93 -> V_42 & V_147 ) == V_154 ) {
void T_4 * V_155 = ( void T_4 * ) ( long ) V_93 -> V_150 ;
return F_101 ( V_99 , V_155 , 16 ) ? - V_156 : 0 ;
} else {
return - V_87 ;
}
switch ( V_93 -> V_42 ) {
case V_101 :
break;
case V_157 ... V_102 :
V_2 -> V_4 . V_103 [ V_93 -> V_42 - V_101 ] = V_98 ;
break;
case V_104 :
V_2 -> V_4 . V_105 = V_98 ;
break;
case V_106 :
V_2 -> V_4 . V_107 = V_98 ;
break;
case V_108 :
V_2 -> V_4 . V_109 = V_98 ;
break;
case F_69 ( 0 ) ... F_69 ( 31 ) :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_87 ;
V_100 = V_93 -> V_42 - F_69 ( 0 ) ;
if ( F_71 ( V_79 ) & V_110 )
F_102 ( & V_96 -> V_111 [ V_100 ] , 0 , V_98 ) ;
else
F_102 ( & V_96 -> V_111 [ V_100 & ~ 1 ] , V_100 & 1 , V_98 ) ;
break;
case F_73 ( 0 ) ... F_73 ( 31 ) :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_87 ;
V_100 = V_93 -> V_42 - F_73 ( 0 ) ;
if ( V_100 & 1 && ! ( F_71 ( V_79 ) & V_110 ) )
return - V_87 ;
F_103 ( & V_96 -> V_111 [ V_100 ] , 0 , V_98 ) ;
break;
case V_112 :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_87 ;
break;
case V_115 :
if ( ! F_70 ( & V_2 -> V_4 ) )
return - V_87 ;
V_96 -> V_116 = V_98 ;
break;
case F_75 ( 0 ) ... F_75 ( 31 ) :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_87 ;
V_100 = V_93 -> V_42 - F_75 ( 0 ) ;
#ifdef F_77
F_103 ( & V_96 -> V_111 [ V_100 ] , 0 , V_99 [ 0 ] ) ;
F_103 ( & V_96 -> V_111 [ V_100 ] , 1 , V_99 [ 1 ] ) ;
#else
F_103 ( & V_96 -> V_111 [ V_100 ] , 1 , V_99 [ 0 ] ) ;
F_103 ( & V_96 -> V_111 [ V_100 ] , 0 , V_99 [ 1 ] ) ;
#endif
break;
case V_117 :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_87 ;
break;
case V_119 :
if ( ! F_76 ( & V_2 -> V_4 ) )
return - V_87 ;
V_96 -> V_120 = V_98 ;
break;
case V_121 :
F_104 ( V_79 , V_98 ) ;
break;
case V_122 :
F_105 ( V_79 , V_98 ) ;
break;
case V_123 :
F_106 ( V_79 , V_98 ) ;
break;
case V_124 :
F_107 ( V_79 , V_98 ) ;
break;
case V_125 :
F_108 ( V_79 , V_98 ) ;
break;
case V_126 :
F_109 ( V_79 , V_98 ) ;
break;
case V_127 :
F_110 ( V_79 , V_98 ) ;
break;
case V_128 :
F_111 ( V_79 , V_98 ) ;
break;
case V_130 :
F_112 ( V_79 , V_98 ) ;
break;
case V_132 :
F_113 ( V_79 , V_98 ) ;
break;
case V_133 :
F_114 ( V_79 , V_98 ) ;
break;
case V_141 :
F_115 ( V_79 , V_98 ) ;
break;
case V_142 :
case V_129 :
case V_131 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_143 :
case V_144 :
case V_145 :
return V_13 -> V_158 ( V_2 , V_93 , V_98 ) ;
default:
return - V_87 ;
}
return 0 ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_159 * V_160 )
{
int V_72 = 0 ;
if ( ! F_117 ( V_2 -> V_9 , V_160 -> V_160 ) )
return - V_87 ;
if ( V_160 -> V_161 )
return - V_87 ;
if ( V_160 -> args [ 0 ] )
return - V_87 ;
switch ( V_160 -> V_160 ) {
case V_162 :
V_2 -> V_4 . V_163 = true ;
break;
case V_164 :
V_2 -> V_4 . V_165 = true ;
break;
default:
V_72 = - V_87 ;
break;
}
return V_72 ;
}
long F_118 ( struct V_23 * V_24 , unsigned int V_25 ,
unsigned long V_12 )
{
struct V_1 * V_2 = V_24 -> V_166 ;
void T_4 * V_167 = ( void T_4 * ) V_12 ;
long V_72 ;
switch ( V_25 ) {
case V_168 :
case V_169 : {
struct V_92 V_93 ;
if ( F_101 ( & V_93 , V_167 , sizeof( V_93 ) ) )
return - V_156 ;
if ( V_25 == V_168 )
return F_99 ( V_2 , & V_93 ) ;
else
return F_68 ( V_2 , & V_93 ) ;
}
case V_170 : {
struct V_171 T_4 * V_172 = V_167 ;
T_3 T_4 * V_173 ;
struct V_171 V_174 ;
unsigned V_175 ;
if ( F_101 ( & V_174 , V_172 , sizeof( V_174 ) ) )
return - V_156 ;
V_175 = V_174 . V_175 ;
V_174 . V_175 = F_119 ( V_176 ) ;
if ( F_98 ( V_172 , & V_174 , sizeof( V_174 ) ) )
return - V_156 ;
if ( V_175 < V_174 . V_175 )
return - V_177 ;
V_173 = V_172 -> V_93 ;
if ( F_98 ( V_173 , V_176 ,
sizeof( V_176 ) ) )
return - V_156 ;
return 0 ;
}
case V_178 :
V_72 = F_1 ( V_2 ) ;
break;
case V_179 :
{
struct V_80 V_81 ;
V_72 = - V_156 ;
if ( F_101 ( & V_81 , V_167 , sizeof( V_81 ) ) )
goto V_48;
F_12 ( L_14 , V_2 -> V_180 , V_16 ,
V_81 . V_81 ) ;
V_72 = F_63 ( V_2 , & V_81 ) ;
break;
}
case V_181 : {
struct V_159 V_160 ;
V_72 = - V_156 ;
if ( F_101 ( & V_160 , V_167 , sizeof( V_160 ) ) )
goto V_48;
V_72 = F_116 ( V_2 , & V_160 ) ;
break;
}
default:
V_72 = - V_26 ;
}
V_48:
return V_72 ;
}
int F_120 ( struct V_9 * V_9 , struct V_182 * log )
{
struct V_183 * V_184 ;
struct V_27 * V_30 ;
unsigned long V_185 , V_186 ;
int V_187 = 0 ;
int V_72 ;
unsigned long V_175 ;
F_23 ( & V_9 -> V_188 ) ;
V_72 = F_121 ( V_9 , log , & V_187 ) ;
if ( V_72 )
goto V_48;
if ( V_187 ) {
V_184 = V_183 ( V_9 ) ;
V_30 = F_122 ( V_184 , log -> V_28 ) ;
V_185 = V_30 -> V_189 << V_40 ;
V_186 = V_185 + ( V_30 -> V_29 << V_40 ) ;
F_123 ( L_15 , V_16 , V_185 ,
V_186 ) ;
V_175 = F_124 ( V_30 ) ;
memset ( V_30 -> V_190 , 0 , V_175 ) ;
}
V_72 = 0 ;
V_48:
F_26 ( & V_9 -> V_188 ) ;
return V_72 ;
}
long F_125 ( struct V_23 * V_24 , unsigned int V_25 , unsigned long V_12 )
{
long V_72 ;
switch ( V_25 ) {
default:
V_72 = - V_26 ;
}
return V_72 ;
}
int F_126 ( void * V_191 )
{
if ( V_13 ) {
F_36 ( L_16 ) ;
return - V_192 ;
}
return F_127 ( & V_13 ) ;
}
void F_128 ( void )
{
V_13 = NULL ;
}
int F_129 ( struct V_1 * V_2 ,
struct V_193 * V_194 )
{
return - V_26 ;
}
int F_130 ( struct V_1 * V_2 ,
struct V_193 * V_194 )
{
return - V_26 ;
}
void F_131 ( struct V_1 * V_2 )
{
}
int F_132 ( struct V_1 * V_2 , struct V_195 * V_96 )
{
return - V_26 ;
}
int F_133 ( struct V_1 * V_2 , struct V_195 * V_96 )
{
return - V_26 ;
}
int F_134 ( struct V_1 * V_2 , struct V_196 * V_197 )
{
return V_198 ;
}
int F_117 ( struct V_9 * V_9 , long V_199 )
{
int V_72 ;
switch ( V_199 ) {
case V_200 :
case V_201 :
V_72 = 1 ;
break;
case V_202 :
V_72 = V_203 ;
break;
case V_162 :
V_72 = ! ! V_204 ;
break;
case V_164 :
V_72 = V_205 && ! ( V_113 . V_118 & V_206 ) ;
break;
default:
V_72 = 0 ;
break;
}
return V_72 ;
}
int F_135 ( struct V_1 * V_2 )
{
return F_136 ( V_2 ) ;
}
int F_137 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_94 * V_79 ;
if ( ! V_2 )
return - 1 ;
F_12 ( L_17 ) ;
F_12 ( L_18 , V_2 -> V_4 . V_109 ) ;
F_12 ( L_19 , V_2 -> V_4 . V_7 ) ;
for ( V_3 = 0 ; V_3 < 32 ; V_3 += 4 ) {
F_12 ( L_20 , V_3 ,
V_2 -> V_4 . V_103 [ V_3 ] ,
V_2 -> V_4 . V_103 [ V_3 + 1 ] ,
V_2 -> V_4 . V_103 [ V_3 + 2 ] , V_2 -> V_4 . V_103 [ V_3 + 3 ] ) ;
}
F_12 ( L_21 , V_2 -> V_4 . V_105 ) ;
F_12 ( L_22 , V_2 -> V_4 . V_107 ) ;
V_79 = V_2 -> V_4 . V_79 ;
F_12 ( L_23 ,
F_71 ( V_79 ) ,
F_57 ( V_79 ) ) ;
F_12 ( L_24 , F_87 ( V_79 ) ) ;
return 0 ;
}
int F_138 ( struct V_1 * V_2 , struct V_207 * V_208 )
{
int V_3 ;
for ( V_3 = 1 ; V_3 < F_119 ( V_2 -> V_4 . V_103 ) ; V_3 ++ )
V_2 -> V_4 . V_103 [ V_3 ] = V_208 -> V_209 [ V_3 ] ;
V_2 -> V_4 . V_103 [ 0 ] = 0 ;
V_2 -> V_4 . V_105 = V_208 -> V_105 ;
V_2 -> V_4 . V_107 = V_208 -> V_107 ;
V_2 -> V_4 . V_109 = V_208 -> V_109 ;
return 0 ;
}
int F_139 ( struct V_1 * V_2 , struct V_207 * V_208 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_119 ( V_2 -> V_4 . V_103 ) ; V_3 ++ )
V_208 -> V_209 [ V_3 ] = V_2 -> V_4 . V_103 [ V_3 ] ;
V_208 -> V_105 = V_2 -> V_4 . V_105 ;
V_208 -> V_107 = V_2 -> V_4 . V_107 ;
V_208 -> V_109 = V_2 -> V_4 . V_109 ;
return 0 ;
}
static void F_140 ( unsigned long V_210 )
{
struct V_1 * V_2 = (struct V_1 * ) V_210 ;
V_13 -> V_211 ( V_2 ) ;
V_2 -> V_4 . V_88 = 0 ;
if ( F_64 ( & V_2 -> V_89 ) )
F_65 ( & V_2 -> V_89 ) ;
}
static enum V_212 F_141 ( struct V_213 * V_214 )
{
struct V_1 * V_2 ;
V_2 = F_142 ( V_214 , struct V_1 , V_4 . V_67 ) ;
F_140 ( ( unsigned long ) V_2 ) ;
return F_143 ( V_2 ) ;
}
int F_144 ( struct V_1 * V_2 )
{
V_13 -> V_215 ( V_2 ) ;
F_145 ( & V_2 -> V_4 . V_67 , V_216 ,
V_217 ) ;
V_2 -> V_4 . V_67 . V_218 = F_141 ;
return 0 ;
}
int F_146 ( struct V_1 * V_2 ,
struct V_219 * V_220 )
{
return 0 ;
}
int F_147 ( struct V_1 * V_2 )
{
return V_13 -> V_221 ( V_2 ) ;
}
static void F_148 ( void )
{
T_7 V_222 = F_149 () ;
if ( V_223 )
V_222 |= ( V_224 ) ;
F_150 ( V_222 ) ;
F_151 () ;
}
int F_152 ( struct V_70 * V_71 , struct V_1 * V_2 )
{
T_7 V_225 = V_2 -> V_4 . V_226 ;
T_7 V_227 = ( V_225 >> V_228 ) & 0x1f ;
T_7 T_4 * V_229 = ( T_7 T_4 * ) V_2 -> V_4 . V_109 ;
unsigned long V_230 = V_2 -> V_4 . V_231 ;
enum V_232 V_233 = V_234 ;
int V_97 = V_235 ;
F_60 () ;
V_71 -> V_236 = V_237 ;
V_71 -> V_238 = 1 ;
F_148 () ;
F_62 () ;
F_12 ( L_25 ,
V_225 , V_229 , V_71 , V_2 ) ;
V_233 = F_153 ( V_225 , V_229 , V_71 , V_2 ) ;
if ( V_233 == V_239 ) {
goto V_240;
} else if ( V_233 == V_241 ) {
V_71 -> V_236 = V_242 ;
V_97 = V_243 ;
goto V_240;
}
switch ( V_227 ) {
case V_244 :
F_12 ( L_26 , V_2 -> V_180 , V_229 ) ;
++ V_2 -> V_245 . V_246 ;
F_154 ( V_2 , V_247 ) ;
if ( F_155 () )
F_156 () ;
V_97 = V_235 ;
break;
case V_248 :
F_12 ( L_27 , V_229 ) ;
++ V_2 -> V_245 . V_249 ;
F_154 ( V_2 , V_250 ) ;
V_97 = V_13 -> V_251 ( V_2 ) ;
if ( V_71 -> V_236 == V_252 )
V_97 = V_243 ;
break;
case V_253 :
++ V_2 -> V_245 . V_254 ;
F_154 ( V_2 , V_255 ) ;
V_97 = V_13 -> V_256 ( V_2 ) ;
break;
case V_257 :
F_12 ( L_28 ,
V_225 , F_71 ( V_2 -> V_4 . V_79 ) , V_229 ,
V_230 ) ;
++ V_2 -> V_245 . V_258 ;
F_154 ( V_2 , V_259 ) ;
V_97 = V_13 -> V_260 ( V_2 ) ;
break;
case V_261 :
F_12 ( L_29 ,
V_225 , V_229 , V_230 ) ;
++ V_2 -> V_245 . V_262 ;
F_154 ( V_2 , V_263 ) ;
V_97 = V_13 -> V_264 ( V_2 ) ;
break;
case V_265 :
++ V_2 -> V_245 . V_266 ;
F_154 ( V_2 , V_267 ) ;
V_97 = V_13 -> V_268 ( V_2 ) ;
break;
case V_269 :
++ V_2 -> V_245 . V_270 ;
F_154 ( V_2 , V_271 ) ;
V_97 = V_13 -> V_272 ( V_2 ) ;
break;
case V_273 :
++ V_2 -> V_245 . V_274 ;
F_154 ( V_2 , V_275 ) ;
V_97 = V_13 -> V_276 ( V_2 ) ;
break;
case V_277 :
++ V_2 -> V_245 . V_278 ;
F_154 ( V_2 , V_279 ) ;
V_97 = V_13 -> V_280 ( V_2 ) ;
break;
case V_281 :
++ V_2 -> V_245 . V_282 ;
F_154 ( V_2 , V_283 ) ;
V_97 = V_13 -> V_284 ( V_2 ) ;
break;
case V_285 :
++ V_2 -> V_245 . V_286 ;
F_154 ( V_2 , V_287 ) ;
V_97 = V_13 -> V_288 ( V_2 ) ;
break;
case V_289 :
++ V_2 -> V_245 . V_290 ;
F_154 ( V_2 , V_291 ) ;
V_97 = V_13 -> V_292 ( V_2 ) ;
break;
case V_293 :
++ V_2 -> V_245 . V_294 ;
F_154 ( V_2 , V_295 ) ;
V_97 = V_13 -> V_296 ( V_2 ) ;
break;
case V_297 :
++ V_2 -> V_245 . V_298 ;
F_154 ( V_2 , V_299 ) ;
V_97 = V_13 -> V_300 ( V_2 ) ;
break;
default:
F_36 ( L_30 ,
V_227 , V_229 , F_157 ( V_229 , V_2 ) , V_230 ,
F_71 ( V_2 -> V_4 . V_79 ) ) ;
F_137 ( V_2 ) ;
V_71 -> V_236 = V_242 ;
V_97 = V_243 ;
break;
}
V_240:
F_55 () ;
if ( V_233 == V_234 && ! ( V_97 & V_243 ) )
F_56 ( V_2 , V_225 ) ;
if ( ! ( V_97 & V_243 ) ) {
if ( F_158 ( V_301 ) ) {
V_71 -> V_236 = V_302 ;
V_97 = ( - V_303 << 2 ) | V_243 ;
++ V_2 -> V_245 . V_304 ;
F_154 ( V_2 , V_305 ) ;
}
}
if ( V_97 == V_235 ) {
if ( F_70 ( & V_2 -> V_4 ) &&
F_149 () & V_306 )
F_159 ( & V_2 -> V_4 ) ;
if ( F_76 ( & V_2 -> V_4 ) &&
F_160 () & V_307 )
F_161 ( & V_2 -> V_4 ) ;
}
F_59 () ;
return V_97 ;
}
void F_162 ( struct V_1 * V_2 )
{
struct V_94 * V_79 = V_2 -> V_4 . V_79 ;
unsigned int V_308 , V_309 ;
F_163 () ;
V_308 = F_71 ( V_79 ) ;
if ( V_205 && V_308 & V_306 && ! ( V_308 & V_110 ) &&
V_2 -> V_4 . V_310 & V_311 )
F_164 ( V_2 ) ;
F_165 ( V_306 | V_110 , V_308 ) ;
if ( V_312 ) {
V_309 = F_94 ( V_79 ) ;
F_166 ( V_313 , V_309 ) ;
}
F_167 () ;
if ( ! ( V_2 -> V_4 . V_310 & V_314 ) ) {
F_168 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_310 |= V_314 ;
}
F_169 () ;
}
void F_170 ( struct V_1 * V_2 )
{
struct V_94 * V_79 = V_2 -> V_4 . V_79 ;
unsigned int V_308 , V_309 ;
F_163 () ;
if ( F_70 ( & V_2 -> V_4 ) ) {
V_308 = F_71 ( V_79 ) ;
if ( ! ( V_308 & V_110 ) &&
( V_2 -> V_4 . V_310 & ( V_314 |
V_311 ) ) == V_314 )
F_164 ( V_2 ) ;
F_165 ( V_306 | V_110 , V_308 ) ;
if ( V_308 & V_306 && V_312 ) {
V_309 = F_94 ( V_79 ) ;
F_166 ( V_313 , V_309 ) ;
}
}
F_171 ( V_307 ) ;
F_167 () ;
switch ( V_2 -> V_4 . V_310 & ( V_314 | V_311 ) ) {
case V_314 :
F_172 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_310 |= V_311 ;
break;
case 0 :
F_173 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_310 |= V_311 ;
if ( F_70 ( & V_2 -> V_4 ) )
V_2 -> V_4 . V_310 |= V_314 ;
break;
default:
break;
}
F_169 () ;
}
void F_174 ( struct V_1 * V_2 )
{
F_163 () ;
if ( V_205 && V_2 -> V_4 . V_310 & V_311 ) {
F_175 () ;
V_2 -> V_4 . V_310 &= ~ V_311 ;
}
if ( V_2 -> V_4 . V_310 & V_314 ) {
F_176 ( V_306 | V_110 ) ;
V_2 -> V_4 . V_310 &= ~ V_314 ;
}
F_169 () ;
}
void F_164 ( struct V_1 * V_2 )
{
F_163 () ;
if ( V_205 && V_2 -> V_4 . V_310 & V_311 ) {
F_171 ( V_307 ) ;
F_167 () ;
F_177 ( & V_2 -> V_4 ) ;
F_175 () ;
if ( V_2 -> V_4 . V_310 & V_314 ) {
F_176 ( V_306 | V_110 ) ;
F_178 () ;
}
V_2 -> V_4 . V_310 &= ~ ( V_314 | V_311 ) ;
} else if ( V_2 -> V_4 . V_310 & V_314 ) {
F_179 ( V_306 ) ;
F_167 () ;
F_180 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_310 &= ~ V_314 ;
F_176 ( V_306 | V_110 ) ;
F_178 () ;
}
F_169 () ;
}
static int F_181 ( struct V_315 * V_316 ,
unsigned long V_317 , void * V_318 )
{
struct V_319 * args = (struct V_319 * ) V_318 ;
struct V_320 * V_208 = args -> V_208 ;
unsigned long V_109 ;
if ( V_317 != V_321 && V_317 != V_322 )
return V_323 ;
if ( ! ( V_301 -> V_161 & V_324 ) )
return V_323 ;
F_182 ( F_183 ( V_208 ) ) ;
V_109 = F_184 ( V_208 ) ;
switch ( V_317 ) {
case V_321 :
if ( V_109 != ( unsigned long ) & F_159 + 4 )
return V_323 ;
break;
case V_322 :
if ( ! V_205 ||
V_109 < ( unsigned long ) & F_161 + 4 ||
V_109 > ( unsigned long ) & F_161 + 8 )
return V_323 ;
break;
}
F_184 ( V_208 ) += 4 ;
return V_325 ;
}
static int T_8 F_185 ( void )
{
int V_97 ;
V_97 = F_186 ( NULL , sizeof( struct V_1 ) , 0 , V_326 ) ;
if ( V_97 )
return V_97 ;
F_187 ( & V_327 ) ;
V_328 = V_329 ;
F_19 = V_330 ;
V_331 = V_332 ;
return 0 ;
}
static void T_9 F_188 ( void )
{
F_189 () ;
V_328 = NULL ;
F_19 = NULL ;
V_331 = NULL ;
F_190 ( & V_327 ) ;
}
