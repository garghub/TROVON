int F_1 ( void )
{
V_1 = 1 ;
return 0 ;
}
void F_2 ( void )
{
V_1 = 0 ;
}
int F_3 ( struct V_2 * V_3 )
{
return ! ! ( V_3 -> V_4 . V_5 ) ;
}
int F_4 ( struct V_2 * V_3 )
{
return 1 ;
}
int F_5 ( void )
{
return V_6 -> V_7 () ;
}
void F_6 ( void )
{
V_6 -> V_8 () ;
}
int F_7 ( void )
{
return 0 ;
}
void F_8 ( void * V_9 )
{
* ( int * ) V_9 = 0 ;
}
int F_9 ( struct V_10 * V_10 , unsigned long type )
{
switch ( type ) {
#ifdef F_10
case V_11 :
#else
case V_12 :
#endif
break;
default:
return - V_13 ;
} ;
V_10 -> V_4 . V_14 . V_15 = F_11 () ;
if ( ! V_10 -> V_4 . V_14 . V_15 )
return - V_16 ;
return 0 ;
}
bool F_12 ( void )
{
return false ;
}
int F_13 ( struct V_2 * V_3 )
{
return 0 ;
}
void F_14 ( struct V_10 * V_10 )
{
unsigned int V_17 ;
struct V_2 * V_3 ;
F_15 (i, vcpu, kvm) {
F_16 ( V_3 ) ;
}
F_17 ( & V_10 -> V_18 ) ;
for ( V_17 = 0 ; V_17 < F_18 ( & V_10 -> V_19 ) ; V_17 ++ )
V_10 -> V_20 [ V_17 ] = NULL ;
F_19 ( & V_10 -> V_19 , 0 ) ;
F_20 ( & V_10 -> V_18 ) ;
}
static void F_21 ( struct V_10 * V_10 )
{
F_22 ( ! F_23 ( V_10 , 0 , ~ 0 ) ) ;
F_24 ( NULL , V_10 -> V_4 . V_14 . V_15 ) ;
}
void F_25 ( struct V_10 * V_10 )
{
F_14 ( V_10 ) ;
F_21 ( V_10 ) ;
}
long F_26 ( struct V_21 * V_22 , unsigned int V_23 ,
unsigned long V_24 )
{
return - V_25 ;
}
int F_27 ( struct V_10 * V_10 , struct V_26 * V_27 ,
unsigned long V_28 )
{
return 0 ;
}
void F_28 ( struct V_10 * V_10 )
{
F_23 ( V_10 , 0 , ~ 0 ) ;
V_6 -> V_29 ( V_10 ) ;
}
void F_29 ( struct V_10 * V_10 ,
struct V_26 * V_27 )
{
F_30 ( & V_10 -> V_30 ) ;
F_23 ( V_10 , V_27 -> V_31 ,
V_27 -> V_31 + V_27 -> V_28 - 1 ) ;
V_6 -> V_32 ( V_10 , V_27 ) ;
F_31 ( & V_10 -> V_30 ) ;
}
int F_32 ( struct V_10 * V_10 ,
struct V_26 * V_33 ,
const struct V_34 * V_35 ,
enum V_36 V_37 )
{
return 0 ;
}
void F_33 ( struct V_10 * V_10 ,
const struct V_34 * V_35 ,
const struct V_26 * V_38 ,
const struct V_26 * V_39 ,
enum V_36 V_37 )
{
int V_40 ;
F_34 ( L_1 ,
V_41 , V_10 , V_35 -> V_27 , V_35 -> V_42 ,
V_35 -> V_43 , V_35 -> V_44 ) ;
if ( V_37 == V_45 &&
( ! ( V_38 -> V_46 & V_47 ) &&
V_39 -> V_46 & V_47 ) ) {
F_30 ( & V_10 -> V_30 ) ;
V_40 = F_35 ( V_10 , V_39 -> V_31 ,
V_39 -> V_31 + V_39 -> V_28 - 1 ) ;
if ( V_40 )
V_6 -> V_32 ( V_10 , V_39 ) ;
F_31 ( & V_10 -> V_30 ) ;
}
}
static inline void F_36 ( const char * V_48 , void * V_49 , void * V_50 )
{
T_1 * V_51 ;
F_37 ( L_2 , V_48 ) ;
F_37 ( L_3 ) ;
F_37 ( L_4 ) ;
for ( V_51 = V_49 ; V_51 < ( T_1 * ) V_50 ; ++ V_51 )
F_37 ( L_5 , * V_51 , V_51 ) ;
F_37 ( L_6 ) ;
F_37 ( L_7 , V_48 ) ;
}
struct V_2 * F_38 ( struct V_10 * V_10 , unsigned int V_52 )
{
int V_53 , V_54 ;
void * V_55 , * V_51 , * V_56 , * V_57 , * V_58 ;
int V_17 ;
struct V_2 * V_3 = F_39 ( sizeof( struct V_2 ) , V_59 ) ;
if ( ! V_3 ) {
V_53 = - V_16 ;
goto V_60;
}
V_53 = F_40 ( V_3 , V_10 , V_52 ) ;
if ( V_53 )
goto V_61;
F_34 ( L_8 , V_10 , V_52 , V_3 ) ;
if ( V_62 || V_63 )
V_54 = 0x200 + V_64 * 64 ;
else
V_54 = 0x4000 ;
V_55 = F_39 ( F_41 ( V_54 , V_65 ) , V_59 ) ;
if ( ! V_55 ) {
V_53 = - V_16 ;
goto V_66;
}
F_34 ( L_9 ,
F_41 ( V_54 , V_65 ) , V_55 ) ;
if ( ! V_67 && F_42 ( V_55 ) >= 0x20000000 ) {
F_43 ( L_10 ,
V_55 ) ;
V_53 = - V_16 ;
goto V_68;
}
V_3 -> V_4 . V_69 = V_55 ;
V_56 = V_55 + 0x2000 ;
V_57 = V_55 ;
if ( F_44 ( F_10 ) && F_44 ( V_70 ) )
V_57 += 0x080 ;
V_58 = F_45 ( V_57 , V_56 ) ;
F_46 ( V_55 + 0x180 , V_56 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
F_34 ( L_11 ,
V_55 + 0x200 + ( V_17 * V_64 ) ) ;
F_46 ( V_55 + 0x200 + V_17 * V_64 ,
V_56 ) ;
}
V_51 = V_56 ;
V_51 = F_47 ( V_51 ) ;
V_3 -> V_4 . V_71 = V_51 ;
V_51 = F_48 ( V_51 ) ;
F_37 ( L_12 ) ;
F_37 ( L_13 ) ;
F_37 ( L_14 ) ;
F_36 ( L_15 , V_3 -> V_4 . V_71 , V_51 ) ;
F_36 ( L_16 , V_57 , V_58 ) ;
F_36 ( L_17 , V_55 + 0x180 , V_55 + 0x200 ) ;
F_36 ( L_18 , V_55 + 0x2000 , V_3 -> V_4 . V_71 ) ;
F_49 ( ( unsigned long ) V_55 ,
( unsigned long ) V_55 + F_41 ( V_54 , V_65 ) ) ;
V_3 -> V_4 . V_72 = F_39 ( V_65 << 1 , V_59 ) ;
if ( ! V_3 -> V_4 . V_72 ) {
V_53 = - V_16 ;
goto V_68;
}
F_34 ( L_19 , V_3 -> V_4 . V_72 ) ;
F_50 ( V_3 ) ;
V_3 -> V_4 . V_73 = - 1 ;
V_3 -> V_4 . V_74 = - 1 ;
return V_3 ;
V_68:
F_51 ( V_55 ) ;
V_66:
F_52 ( V_3 ) ;
V_61:
F_51 ( V_3 ) ;
V_60:
return F_53 ( V_53 ) ;
}
void F_16 ( struct V_2 * V_3 )
{
F_54 ( & V_3 -> V_4 . V_75 ) ;
F_52 ( V_3 ) ;
F_55 ( V_3 ) ;
F_56 ( V_3 ) ;
F_51 ( V_3 -> V_4 . V_69 ) ;
F_51 ( V_3 -> V_4 . V_72 ) ;
F_51 ( V_3 ) ;
}
void F_57 ( struct V_2 * V_3 )
{
F_16 ( V_3 ) ;
}
int F_58 ( struct V_2 * V_3 ,
struct V_76 * V_77 )
{
return - V_25 ;
}
int F_59 ( struct V_2 * V_3 , struct V_78 * V_79 )
{
int V_80 = - V_81 ;
T_2 V_82 ;
if ( V_3 -> V_83 )
F_60 ( V_84 , & V_3 -> V_85 , & V_82 ) ;
if ( V_3 -> V_86 ) {
if ( ! V_3 -> V_87 )
F_61 ( V_3 , V_79 ) ;
V_3 -> V_86 = 0 ;
}
if ( V_79 -> V_88 )
goto V_60;
F_62 ( 1 ) ;
F_63 () ;
F_64 () ;
F_65 ( V_3 ) ;
F_66 ( V_3 -> V_89 , V_90 ) ;
V_80 = V_6 -> V_71 ( V_79 , V_3 ) ;
F_67 ( V_3 ) ;
F_68 () ;
F_69 () ;
V_60:
if ( V_3 -> V_83 )
F_60 ( V_84 , & V_82 , NULL ) ;
return V_80 ;
}
int F_70 ( struct V_2 * V_3 ,
struct V_91 * V_92 )
{
int V_93 = ( int ) V_92 -> V_92 ;
struct V_2 * V_94 = NULL ;
if ( V_93 == 3 || V_93 == - 3 || V_93 == 4 || V_93 == - 4 )
F_34 ( L_20 , V_41 , V_92 -> V_95 ,
( int ) V_93 ) ;
if ( V_92 -> V_95 == - 1 )
V_94 = V_3 ;
else
V_94 = V_3 -> V_10 -> V_20 [ V_92 -> V_95 ] ;
if ( V_93 == 2 || V_93 == 3 || V_93 == 4 ) {
V_6 -> V_96 ( V_94 , V_92 ) ;
} else if ( V_93 == - 2 || V_93 == - 3 || V_93 == - 4 ) {
V_6 -> V_97 ( V_94 , V_92 ) ;
} else {
F_43 ( L_21 , V_41 ,
V_92 -> V_95 , V_92 -> V_92 ) ;
return - V_13 ;
}
V_94 -> V_4 . V_98 = 0 ;
if ( F_71 ( & V_94 -> V_99 ) )
F_72 ( & V_94 -> V_99 ) ;
return 0 ;
}
int F_73 ( struct V_2 * V_3 ,
struct V_100 * V_101 )
{
return - V_25 ;
}
int F_74 ( struct V_2 * V_3 ,
struct V_100 * V_101 )
{
return - V_25 ;
}
static unsigned long F_75 ( struct V_2 * V_3 )
{
unsigned long V_102 ;
V_102 = F_76 ( V_103 ) ;
if ( F_77 ( & V_3 -> V_4 ) ) {
V_102 += F_76 ( V_104 ) + 48 ;
if ( V_105 . V_106 & V_107 )
V_102 += 16 ;
}
if ( F_78 ( & V_3 -> V_4 ) )
V_102 += F_76 ( V_108 ) + 32 ;
V_102 += V_6 -> V_109 ( V_3 ) ;
return V_102 ;
}
static int F_79 ( struct V_2 * V_3 , T_3 T_4 * V_110 )
{
T_3 V_111 ;
unsigned int V_17 ;
if ( F_80 ( V_110 , V_103 ,
sizeof( V_103 ) ) )
return - V_112 ;
V_110 += F_76 ( V_103 ) ;
if ( F_77 ( & V_3 -> V_4 ) ) {
if ( F_80 ( V_110 , V_104 ,
sizeof( V_104 ) ) )
return - V_112 ;
V_110 += F_76 ( V_104 ) ;
for ( V_17 = 0 ; V_17 < 32 ; ++ V_17 ) {
V_111 = F_81 ( V_17 ) ;
if ( F_80 ( V_110 , & V_111 , sizeof( V_111 ) ) )
return - V_112 ;
++ V_110 ;
if ( V_17 & 1 && ! ( V_105 . V_106 & V_107 ) )
continue;
V_111 = F_82 ( V_17 ) ;
if ( F_80 ( V_110 , & V_111 , sizeof( V_111 ) ) )
return - V_112 ;
++ V_110 ;
}
}
if ( F_78 ( & V_3 -> V_4 ) ) {
if ( F_80 ( V_110 , V_108 ,
sizeof( V_108 ) ) )
return - V_112 ;
V_110 += F_76 ( V_108 ) ;
for ( V_17 = 0 ; V_17 < 32 ; ++ V_17 ) {
V_111 = F_83 ( V_17 ) ;
if ( F_80 ( V_110 , & V_111 , sizeof( V_111 ) ) )
return - V_112 ;
++ V_110 ;
}
}
return V_6 -> V_113 ( V_3 , V_110 ) ;
}
static int F_84 ( struct V_2 * V_3 ,
const struct V_114 * V_115 )
{
struct V_116 * V_117 = V_3 -> V_4 . V_117 ;
struct V_118 * V_119 = & V_3 -> V_4 . V_119 ;
int V_102 ;
T_5 V_120 ;
T_5 V_121 [ 2 ] ;
unsigned int V_122 ;
switch ( V_115 -> V_52 ) {
case V_123 ... V_124 :
V_120 = ( long ) V_3 -> V_4 . V_125 [ V_115 -> V_52 - V_123 ] ;
break;
#ifndef F_85
case V_126 :
V_120 = ( long ) V_3 -> V_4 . V_127 ;
break;
case V_128 :
V_120 = ( long ) V_3 -> V_4 . V_129 ;
break;
#endif
case V_130 :
V_120 = ( long ) V_3 -> V_4 . V_131 ;
break;
case F_81 ( 0 ) ... F_81 ( 31 ) :
if ( ! F_86 ( & V_3 -> V_4 ) )
return - V_13 ;
V_122 = V_115 -> V_52 - F_81 ( 0 ) ;
if ( F_87 ( V_117 ) & V_132 )
V_120 = F_88 ( & V_119 -> V_133 [ V_122 ] , 0 ) ;
else
V_120 = F_88 ( & V_119 -> V_133 [ V_122 & ~ 1 ] , V_122 & 1 ) ;
break;
case F_82 ( 0 ) ... F_82 ( 31 ) :
if ( ! F_86 ( & V_3 -> V_4 ) )
return - V_13 ;
V_122 = V_115 -> V_52 - F_82 ( 0 ) ;
if ( V_122 & 1 && ! ( F_87 ( V_117 ) & V_132 ) )
return - V_13 ;
V_120 = F_89 ( & V_119 -> V_133 [ V_122 ] , 0 ) ;
break;
case V_134 :
if ( ! F_86 ( & V_3 -> V_4 ) )
return - V_13 ;
V_120 = V_105 . V_106 ;
break;
case V_135 :
if ( ! F_86 ( & V_3 -> V_4 ) )
return - V_13 ;
V_120 = V_119 -> V_136 ;
break;
case F_83 ( 0 ) ... F_83 ( 31 ) :
if ( ! F_90 ( & V_3 -> V_4 ) )
return - V_13 ;
if ( ! ( F_87 ( V_117 ) & V_132 ) )
return - V_13 ;
V_122 = V_115 -> V_52 - F_83 ( 0 ) ;
#ifdef F_91
V_121 [ 0 ] = F_89 ( & V_119 -> V_133 [ V_122 ] , 0 ) ;
V_121 [ 1 ] = F_89 ( & V_119 -> V_133 [ V_122 ] , 1 ) ;
#else
V_121 [ 0 ] = F_89 ( & V_119 -> V_133 [ V_122 ] , 1 ) ;
V_121 [ 1 ] = F_89 ( & V_119 -> V_133 [ V_122 ] , 0 ) ;
#endif
break;
case V_137 :
if ( ! F_90 ( & V_3 -> V_4 ) )
return - V_13 ;
V_120 = V_105 . V_138 ;
break;
case V_139 :
if ( ! F_90 ( & V_3 -> V_4 ) )
return - V_13 ;
V_120 = V_119 -> V_140 ;
break;
default:
V_102 = V_6 -> V_141 ( V_3 , V_115 , & V_120 ) ;
if ( V_102 )
return V_102 ;
break;
}
if ( ( V_115 -> V_52 & V_142 ) == V_143 ) {
T_3 T_4 * V_144 = ( T_3 T_4 * ) ( long ) V_115 -> V_145 ;
return F_92 ( V_120 , V_144 ) ;
} else if ( ( V_115 -> V_52 & V_142 ) == V_146 ) {
T_1 T_4 * V_147 = ( T_1 T_4 * ) ( long ) V_115 -> V_145 ;
T_1 V_148 = ( T_1 ) V_120 ;
return F_92 ( V_148 , V_147 ) ;
} else if ( ( V_115 -> V_52 & V_142 ) == V_149 ) {
void T_4 * V_150 = ( void T_4 * ) ( long ) V_115 -> V_145 ;
return F_80 ( V_150 , V_121 , 16 ) ? - V_112 : 0 ;
} else {
return - V_13 ;
}
}
static int F_93 ( struct V_2 * V_3 ,
const struct V_114 * V_115 )
{
struct V_116 * V_117 = V_3 -> V_4 . V_117 ;
struct V_118 * V_119 = & V_3 -> V_4 . V_119 ;
T_5 V_120 ;
T_5 V_121 [ 2 ] ;
unsigned int V_122 ;
if ( ( V_115 -> V_52 & V_142 ) == V_143 ) {
T_3 T_4 * V_144 = ( T_3 T_4 * ) ( long ) V_115 -> V_145 ;
if ( F_94 ( V_120 , V_144 ) != 0 )
return - V_112 ;
} else if ( ( V_115 -> V_52 & V_142 ) == V_146 ) {
T_1 T_4 * V_147 = ( T_1 T_4 * ) ( long ) V_115 -> V_145 ;
T_6 V_148 ;
if ( F_94 ( V_148 , V_147 ) != 0 )
return - V_112 ;
V_120 = ( T_5 ) V_148 ;
} else if ( ( V_115 -> V_52 & V_142 ) == V_149 ) {
void T_4 * V_150 = ( void T_4 * ) ( long ) V_115 -> V_145 ;
return F_95 ( V_121 , V_150 , 16 ) ? - V_112 : 0 ;
} else {
return - V_13 ;
}
switch ( V_115 -> V_52 ) {
case V_123 :
break;
case V_151 ... V_124 :
V_3 -> V_4 . V_125 [ V_115 -> V_52 - V_123 ] = V_120 ;
break;
#ifndef F_85
case V_126 :
V_3 -> V_4 . V_127 = V_120 ;
break;
case V_128 :
V_3 -> V_4 . V_129 = V_120 ;
break;
#endif
case V_130 :
V_3 -> V_4 . V_131 = V_120 ;
break;
case F_81 ( 0 ) ... F_81 ( 31 ) :
if ( ! F_86 ( & V_3 -> V_4 ) )
return - V_13 ;
V_122 = V_115 -> V_52 - F_81 ( 0 ) ;
if ( F_87 ( V_117 ) & V_132 )
F_96 ( & V_119 -> V_133 [ V_122 ] , 0 , V_120 ) ;
else
F_96 ( & V_119 -> V_133 [ V_122 & ~ 1 ] , V_122 & 1 , V_120 ) ;
break;
case F_82 ( 0 ) ... F_82 ( 31 ) :
if ( ! F_86 ( & V_3 -> V_4 ) )
return - V_13 ;
V_122 = V_115 -> V_52 - F_82 ( 0 ) ;
if ( V_122 & 1 && ! ( F_87 ( V_117 ) & V_132 ) )
return - V_13 ;
F_97 ( & V_119 -> V_133 [ V_122 ] , 0 , V_120 ) ;
break;
case V_134 :
if ( ! F_86 ( & V_3 -> V_4 ) )
return - V_13 ;
break;
case V_135 :
if ( ! F_86 ( & V_3 -> V_4 ) )
return - V_13 ;
V_119 -> V_136 = V_120 ;
break;
case F_83 ( 0 ) ... F_83 ( 31 ) :
if ( ! F_90 ( & V_3 -> V_4 ) )
return - V_13 ;
V_122 = V_115 -> V_52 - F_83 ( 0 ) ;
#ifdef F_91
F_97 ( & V_119 -> V_133 [ V_122 ] , 0 , V_121 [ 0 ] ) ;
F_97 ( & V_119 -> V_133 [ V_122 ] , 1 , V_121 [ 1 ] ) ;
#else
F_97 ( & V_119 -> V_133 [ V_122 ] , 1 , V_121 [ 0 ] ) ;
F_97 ( & V_119 -> V_133 [ V_122 ] , 0 , V_121 [ 1 ] ) ;
#endif
break;
case V_137 :
if ( ! F_90 ( & V_3 -> V_4 ) )
return - V_13 ;
break;
case V_139 :
if ( ! F_90 ( & V_3 -> V_4 ) )
return - V_13 ;
V_119 -> V_140 = V_120 ;
break;
default:
return V_6 -> V_152 ( V_3 , V_115 , V_120 ) ;
}
return 0 ;
}
static int F_98 ( struct V_2 * V_3 ,
struct V_153 * V_154 )
{
int V_80 = 0 ;
if ( ! F_99 ( V_3 -> V_10 , V_154 -> V_154 ) )
return - V_13 ;
if ( V_154 -> V_46 )
return - V_13 ;
if ( V_154 -> args [ 0 ] )
return - V_13 ;
switch ( V_154 -> V_154 ) {
case V_155 :
V_3 -> V_4 . V_156 = true ;
break;
case V_157 :
V_3 -> V_4 . V_158 = true ;
break;
default:
V_80 = - V_13 ;
break;
}
return V_80 ;
}
long F_100 ( struct V_21 * V_22 , unsigned int V_23 ,
unsigned long V_24 )
{
struct V_2 * V_3 = V_22 -> V_159 ;
void T_4 * V_160 = ( void T_4 * ) V_24 ;
long V_80 ;
switch ( V_23 ) {
case V_161 :
case V_162 : {
struct V_114 V_115 ;
if ( F_95 ( & V_115 , V_160 , sizeof( V_115 ) ) )
return - V_112 ;
if ( V_23 == V_161 )
return F_93 ( V_3 , & V_115 ) ;
else
return F_84 ( V_3 , & V_115 ) ;
}
case V_163 : {
struct V_164 T_4 * V_165 = V_160 ;
struct V_164 V_166 ;
unsigned V_167 ;
if ( F_95 ( & V_166 , V_165 , sizeof( V_166 ) ) )
return - V_112 ;
V_167 = V_166 . V_167 ;
V_166 . V_167 = F_75 ( V_3 ) ;
if ( F_80 ( V_165 , & V_166 , sizeof( V_166 ) ) )
return - V_112 ;
if ( V_167 < V_166 . V_167 )
return - V_168 ;
return F_79 ( V_3 , V_165 -> V_115 ) ;
}
case V_169 :
{
struct V_91 V_92 ;
if ( F_95 ( & V_92 , V_160 , sizeof( V_92 ) ) )
return - V_112 ;
F_34 ( L_22 , V_3 -> V_170 , V_41 ,
V_92 . V_92 ) ;
V_80 = F_70 ( V_3 , & V_92 ) ;
break;
}
case V_171 : {
struct V_153 V_154 ;
if ( F_95 ( & V_154 , V_160 , sizeof( V_154 ) ) )
return - V_112 ;
V_80 = F_98 ( V_3 , & V_154 ) ;
break;
}
default:
V_80 = - V_25 ;
}
return V_80 ;
}
int F_101 ( struct V_10 * V_10 , struct V_172 * log )
{
struct V_173 * V_174 ;
struct V_26 * V_33 ;
bool V_175 = false ;
int V_80 ;
F_17 ( & V_10 -> V_176 ) ;
V_80 = F_102 ( V_10 , log , & V_175 ) ;
if ( V_175 ) {
V_174 = V_173 ( V_10 ) ;
V_33 = F_103 ( V_174 , log -> V_27 ) ;
V_6 -> V_32 ( V_10 , V_33 ) ;
}
F_20 ( & V_10 -> V_176 ) ;
return V_80 ;
}
long F_104 ( struct V_21 * V_22 , unsigned int V_23 , unsigned long V_24 )
{
long V_80 ;
switch ( V_23 ) {
default:
V_80 = - V_25 ;
}
return V_80 ;
}
int F_105 ( void * V_177 )
{
if ( V_6 ) {
F_43 ( L_23 ) ;
return - V_178 ;
}
return F_106 ( & V_6 ) ;
}
void F_107 ( void )
{
V_6 = NULL ;
}
int F_108 ( struct V_2 * V_3 ,
struct V_179 * V_180 )
{
return - V_25 ;
}
int F_109 ( struct V_2 * V_3 ,
struct V_179 * V_180 )
{
return - V_25 ;
}
void F_110 ( struct V_2 * V_3 )
{
}
int F_111 ( struct V_2 * V_3 , struct V_181 * V_119 )
{
return - V_25 ;
}
int F_112 ( struct V_2 * V_3 , struct V_181 * V_119 )
{
return - V_25 ;
}
int F_113 ( struct V_2 * V_3 , struct V_182 * V_183 )
{
return V_184 ;
}
int F_99 ( struct V_10 * V_10 , long V_185 )
{
int V_80 ;
switch ( V_185 ) {
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
V_80 = 1 ;
break;
case V_191 :
V_80 = F_114 () ;
break;
case V_192 :
V_80 = V_193 ;
break;
case V_155 :
V_80 = ! ! V_194 ;
break;
case V_157 :
V_80 = V_195 && ! ( V_105 . V_138 & V_196 ) ;
break;
default:
V_80 = V_6 -> V_197 ( V_10 , V_185 ) ;
break;
}
return V_80 ;
}
int F_115 ( struct V_2 * V_3 )
{
return F_116 ( V_3 ) ||
F_117 ( V_3 -> V_4 . V_117 ) & V_198 ;
}
int F_118 ( struct V_2 * V_3 )
{
int V_17 ;
struct V_116 * V_117 ;
if ( ! V_3 )
return - 1 ;
F_34 ( L_24 ) ;
F_34 ( L_25 , V_3 -> V_4 . V_131 ) ;
F_34 ( L_26 , V_3 -> V_4 . V_5 ) ;
for ( V_17 = 0 ; V_17 < 32 ; V_17 += 4 ) {
F_34 ( L_27 , V_17 ,
V_3 -> V_4 . V_125 [ V_17 ] ,
V_3 -> V_4 . V_125 [ V_17 + 1 ] ,
V_3 -> V_4 . V_125 [ V_17 + 2 ] , V_3 -> V_4 . V_125 [ V_17 + 3 ] ) ;
}
F_34 ( L_28 , V_3 -> V_4 . V_127 ) ;
F_34 ( L_29 , V_3 -> V_4 . V_129 ) ;
V_117 = V_3 -> V_4 . V_117 ;
F_34 ( L_30 ,
F_87 ( V_117 ) ,
F_117 ( V_117 ) ) ;
F_34 ( L_31 , F_119 ( V_117 ) ) ;
return 0 ;
}
int F_120 ( struct V_2 * V_3 , struct V_199 * V_200 )
{
int V_17 ;
for ( V_17 = 1 ; V_17 < F_76 ( V_3 -> V_4 . V_125 ) ; V_17 ++ )
V_3 -> V_4 . V_125 [ V_17 ] = V_200 -> V_201 [ V_17 ] ;
V_3 -> V_4 . V_125 [ 0 ] = 0 ;
V_3 -> V_4 . V_127 = V_200 -> V_127 ;
V_3 -> V_4 . V_129 = V_200 -> V_129 ;
V_3 -> V_4 . V_131 = V_200 -> V_131 ;
return 0 ;
}
int F_121 ( struct V_2 * V_3 , struct V_199 * V_200 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < F_76 ( V_3 -> V_4 . V_125 ) ; V_17 ++ )
V_200 -> V_201 [ V_17 ] = V_3 -> V_4 . V_125 [ V_17 ] ;
V_200 -> V_127 = V_3 -> V_4 . V_127 ;
V_200 -> V_129 = V_3 -> V_4 . V_129 ;
V_200 -> V_131 = V_3 -> V_4 . V_131 ;
return 0 ;
}
static void F_122 ( unsigned long V_202 )
{
struct V_2 * V_3 = (struct V_2 * ) V_202 ;
V_6 -> V_203 ( V_3 ) ;
V_3 -> V_4 . V_98 = 0 ;
if ( F_71 ( & V_3 -> V_99 ) )
F_72 ( & V_3 -> V_99 ) ;
}
static enum V_204 F_123 ( struct V_205 * V_206 )
{
struct V_2 * V_3 ;
V_3 = F_124 ( V_206 , struct V_2 , V_4 . V_75 ) ;
F_122 ( ( unsigned long ) V_3 ) ;
return F_125 ( V_3 ) ;
}
int F_126 ( struct V_2 * V_3 )
{
int V_53 ;
V_53 = V_6 -> V_207 ( V_3 ) ;
if ( V_53 )
return V_53 ;
F_127 ( & V_3 -> V_4 . V_75 , V_208 ,
V_209 ) ;
V_3 -> V_4 . V_75 . V_210 = F_123 ;
return 0 ;
}
void F_128 ( struct V_2 * V_3 )
{
V_6 -> V_211 ( V_3 ) ;
}
int F_129 ( struct V_2 * V_3 ,
struct V_212 * V_213 )
{
return 0 ;
}
int F_130 ( struct V_2 * V_3 )
{
return V_6 -> V_214 ( V_3 ) ;
}
static void F_131 ( void )
{
T_1 V_215 = F_132 () ;
if ( V_216 )
V_215 |= ( V_217 ) ;
F_133 ( V_215 ) ;
F_134 () ;
}
int F_135 ( struct V_78 * V_79 , struct V_2 * V_3 )
{
T_1 V_218 = V_3 -> V_4 . V_219 ;
T_1 V_220 = ( V_218 >> V_221 ) & 0x1f ;
T_1 T_4 * V_222 = ( T_1 T_4 * ) V_3 -> V_4 . V_131 ;
unsigned long V_223 = V_3 -> V_4 . V_224 ;
enum V_225 V_226 = V_227 ;
T_1 V_228 ;
int V_102 = V_229 ;
V_3 -> V_89 = V_230 ;
if ( ! F_44 ( F_10 ) )
F_136 () ;
V_79 -> V_231 = V_232 ;
V_79 -> V_233 = 1 ;
F_131 () ;
F_69 () ;
F_34 ( L_32 ,
V_218 , V_222 , V_79 , V_3 ) ;
F_137 ( V_3 , V_220 ) ;
if ( ! F_44 ( F_10 ) ) {
V_226 = F_138 ( V_218 , V_222 , V_79 , V_3 ) ;
if ( V_226 == V_234 ) {
goto V_235;
} else if ( V_226 == V_236 ) {
V_79 -> V_231 = V_237 ;
V_102 = V_238 ;
goto V_235;
}
}
switch ( V_220 ) {
case V_239 :
F_34 ( L_33 , V_3 -> V_170 , V_222 ) ;
++ V_3 -> V_240 . V_241 ;
if ( F_139 () )
F_140 () ;
V_102 = V_229 ;
break;
case V_242 :
F_34 ( L_34 , V_222 ) ;
++ V_3 -> V_240 . V_243 ;
V_102 = V_6 -> V_244 ( V_3 ) ;
if ( V_79 -> V_231 == V_245 )
V_102 = V_238 ;
break;
case V_246 :
++ V_3 -> V_240 . V_247 ;
V_102 = V_6 -> V_248 ( V_3 ) ;
break;
case V_249 :
F_34 ( L_35 ,
V_218 , F_87 ( V_3 -> V_4 . V_117 ) , V_222 ,
V_223 ) ;
++ V_3 -> V_240 . V_250 ;
V_102 = V_6 -> V_251 ( V_3 ) ;
break;
case V_252 :
F_34 ( L_36 ,
V_218 , V_222 , V_223 ) ;
++ V_3 -> V_240 . V_253 ;
V_102 = V_6 -> V_254 ( V_3 ) ;
break;
case V_255 :
++ V_3 -> V_240 . V_256 ;
V_102 = V_6 -> V_257 ( V_3 ) ;
break;
case V_258 :
++ V_3 -> V_240 . V_259 ;
V_102 = V_6 -> V_260 ( V_3 ) ;
break;
case V_261 :
++ V_3 -> V_240 . V_262 ;
V_102 = V_6 -> V_263 ( V_3 ) ;
break;
case V_264 :
++ V_3 -> V_240 . V_265 ;
V_102 = V_6 -> V_266 ( V_3 ) ;
break;
case V_267 :
++ V_3 -> V_240 . V_268 ;
V_102 = V_6 -> V_269 ( V_3 ) ;
break;
case V_270 :
++ V_3 -> V_240 . V_271 ;
V_102 = V_6 -> V_272 ( V_3 ) ;
break;
case V_273 :
++ V_3 -> V_240 . V_274 ;
V_102 = V_6 -> V_275 ( V_3 ) ;
break;
case V_276 :
++ V_3 -> V_240 . V_277 ;
V_102 = V_6 -> V_278 ( V_3 ) ;
break;
case V_279 :
++ V_3 -> V_240 . V_280 ;
V_102 = V_6 -> V_281 ( V_3 ) ;
break;
case V_282 :
V_102 = V_6 -> V_283 ( V_3 ) ;
break;
default:
if ( V_218 & V_284 )
V_222 += 1 ;
V_228 = 0 ;
F_141 ( V_222 , V_3 , & V_228 ) ;
F_43 ( L_37 ,
V_220 , V_222 , V_228 , V_223 ,
F_87 ( V_3 -> V_4 . V_117 ) ) ;
F_118 ( V_3 ) ;
V_79 -> V_231 = V_237 ;
V_102 = V_238 ;
break;
}
V_235:
F_63 () ;
if ( V_102 == V_229 )
F_142 ( V_3 ) ;
if ( V_226 == V_227 && ! ( V_102 & V_238 ) )
F_143 ( V_3 , V_218 ) ;
if ( ! ( V_102 & V_238 ) ) {
if ( F_144 ( V_285 ) ) {
V_79 -> V_231 = V_286 ;
V_102 = ( - V_81 << 2 ) | V_238 ;
++ V_3 -> V_240 . V_287 ;
F_137 ( V_3 , V_288 ) ;
}
}
if ( V_102 == V_229 ) {
F_145 ( V_3 ) ;
F_66 ( V_3 -> V_89 , V_90 ) ;
V_6 -> V_289 ( V_79 , V_3 ) ;
if ( F_86 ( & V_3 -> V_4 ) &&
F_132 () & V_290 )
F_146 ( & V_3 -> V_4 ) ;
if ( F_90 ( & V_3 -> V_4 ) &&
F_147 () & V_291 )
F_148 ( & V_3 -> V_4 ) ;
}
if ( ! F_44 ( F_10 ) )
F_149 () ;
return V_102 ;
}
void F_150 ( struct V_2 * V_3 )
{
struct V_116 * V_117 = V_3 -> V_4 . V_117 ;
unsigned int V_292 , V_293 ;
F_151 () ;
V_292 = F_87 ( V_117 ) ;
if ( V_195 && V_292 & V_290 && ! ( V_292 & V_132 ) &&
V_3 -> V_4 . V_294 & V_295 )
F_152 ( V_3 ) ;
F_153 ( V_290 | V_132 , V_292 ) ;
if ( V_296 ) {
V_293 = F_154 ( V_117 ) ;
F_155 ( V_297 , V_293 ) ;
}
F_156 () ;
if ( ! ( V_3 -> V_4 . V_294 & V_298 ) ) {
F_157 ( & V_3 -> V_4 ) ;
V_3 -> V_4 . V_294 |= V_298 ;
F_158 ( V_3 , V_299 , V_300 ) ;
} else {
F_158 ( V_3 , V_301 , V_300 ) ;
}
F_159 () ;
}
void F_160 ( struct V_2 * V_3 )
{
struct V_116 * V_117 = V_3 -> V_4 . V_117 ;
unsigned int V_292 , V_293 ;
F_151 () ;
if ( F_86 ( & V_3 -> V_4 ) ) {
V_292 = F_87 ( V_117 ) ;
if ( ! ( V_292 & V_132 ) &&
( V_3 -> V_4 . V_294 & ( V_298 |
V_295 ) ) == V_298 )
F_152 ( V_3 ) ;
F_153 ( V_290 | V_132 , V_292 ) ;
if ( V_292 & V_290 && V_296 ) {
V_293 = F_154 ( V_117 ) ;
F_155 ( V_297 , V_293 ) ;
}
}
F_161 ( V_291 ) ;
F_156 () ;
switch ( V_3 -> V_4 . V_294 & ( V_298 | V_295 ) ) {
case V_298 :
F_162 ( & V_3 -> V_4 ) ;
V_3 -> V_4 . V_294 |= V_295 ;
F_158 ( V_3 , V_299 , V_302 ) ;
break;
case 0 :
F_163 ( & V_3 -> V_4 ) ;
V_3 -> V_4 . V_294 |= V_295 ;
if ( F_86 ( & V_3 -> V_4 ) )
V_3 -> V_4 . V_294 |= V_298 ;
F_158 ( V_3 , V_299 ,
V_303 ) ;
break;
default:
F_158 ( V_3 , V_301 , V_302 ) ;
break;
}
F_159 () ;
}
void F_164 ( struct V_2 * V_3 )
{
F_151 () ;
if ( V_195 && V_3 -> V_4 . V_294 & V_295 ) {
F_165 () ;
F_158 ( V_3 , V_304 , V_302 ) ;
V_3 -> V_4 . V_294 &= ~ V_295 ;
}
if ( V_3 -> V_4 . V_294 & V_298 ) {
F_166 ( V_290 | V_132 ) ;
F_158 ( V_3 , V_304 , V_300 ) ;
V_3 -> V_4 . V_294 &= ~ V_298 ;
}
F_159 () ;
}
void F_152 ( struct V_2 * V_3 )
{
F_151 () ;
if ( V_195 && V_3 -> V_4 . V_294 & V_295 ) {
if ( ! F_44 ( F_10 ) ) {
F_161 ( V_291 ) ;
F_156 () ;
}
F_167 ( & V_3 -> V_4 ) ;
F_158 ( V_3 , V_305 , V_303 ) ;
F_165 () ;
if ( V_3 -> V_4 . V_294 & V_298 ) {
F_166 ( V_290 | V_132 ) ;
F_168 () ;
}
V_3 -> V_4 . V_294 &= ~ ( V_298 | V_295 ) ;
} else if ( V_3 -> V_4 . V_294 & V_298 ) {
if ( ! F_44 ( F_10 ) ) {
F_169 ( V_290 ) ;
F_156 () ;
}
F_170 ( & V_3 -> V_4 ) ;
V_3 -> V_4 . V_294 &= ~ V_298 ;
F_158 ( V_3 , V_305 , V_300 ) ;
F_166 ( V_290 | V_132 ) ;
F_168 () ;
}
F_159 () ;
}
static int F_171 ( struct V_306 * V_307 ,
unsigned long V_308 , void * V_309 )
{
struct V_310 * args = (struct V_310 * ) V_309 ;
struct V_311 * V_200 = args -> V_200 ;
unsigned long V_131 ;
if ( V_308 != V_312 && V_308 != V_313 )
return V_314 ;
if ( ! ( V_285 -> V_46 & V_315 ) )
return V_314 ;
F_172 ( F_173 ( V_200 ) ) ;
V_131 = F_174 ( V_200 ) ;
switch ( V_308 ) {
case V_312 :
if ( V_131 != ( unsigned long ) & F_146 + 4 )
return V_314 ;
break;
case V_313 :
if ( ! V_195 ||
V_131 < ( unsigned long ) & F_148 + 4 ||
V_131 > ( unsigned long ) & F_148 + 8 )
return V_314 ;
break;
}
F_174 ( V_200 ) += 4 ;
return V_316 ;
}
static int T_7 F_175 ( void )
{
int V_102 ;
V_102 = F_176 () ;
if ( V_102 )
return V_102 ;
V_102 = F_177 ( NULL , sizeof( struct V_2 ) , 0 , V_317 ) ;
if ( V_102 )
return V_102 ;
F_178 ( & V_318 ) ;
return 0 ;
}
static void T_8 F_179 ( void )
{
F_180 () ;
F_181 ( & V_318 ) ;
}
