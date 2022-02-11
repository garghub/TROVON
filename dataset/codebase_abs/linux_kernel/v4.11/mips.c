int F_1 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 . V_4 ) ;
}
int F_2 ( struct V_1 * V_2 )
{
return 1 ;
}
int F_3 ( void )
{
return 0 ;
}
int F_4 ( void )
{
return 0 ;
}
void F_5 ( void * V_5 )
{
* ( int * ) V_5 = 0 ;
}
int F_6 ( struct V_6 * V_6 , unsigned long type )
{
V_6 -> V_3 . V_7 . V_8 = F_7 () ;
if ( ! V_6 -> V_3 . V_7 . V_8 )
return - V_9 ;
return 0 ;
}
bool F_8 ( void )
{
return false ;
}
int F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_10 ( struct V_6 * V_6 )
{
unsigned int V_10 ;
struct V_1 * V_2 ;
F_11 (i, vcpu, kvm) {
F_12 ( V_2 ) ;
}
F_13 ( & V_6 -> V_11 ) ;
for ( V_10 = 0 ; V_10 < F_14 ( & V_6 -> V_12 ) ; V_10 ++ )
V_6 -> V_13 [ V_10 ] = NULL ;
F_15 ( & V_6 -> V_12 , 0 ) ;
F_16 ( & V_6 -> V_11 ) ;
}
static void F_17 ( struct V_6 * V_6 )
{
F_18 ( ! F_19 ( V_6 , 0 , ~ 0 ) ) ;
F_20 ( NULL , V_6 -> V_3 . V_7 . V_8 ) ;
}
void F_21 ( struct V_6 * V_6 )
{
F_10 ( V_6 ) ;
F_17 ( V_6 ) ;
}
long F_22 ( struct V_14 * V_15 , unsigned int V_16 ,
unsigned long V_17 )
{
return - V_18 ;
}
int F_23 ( struct V_6 * V_6 , struct V_19 * V_20 ,
unsigned long V_21 )
{
return 0 ;
}
void F_24 ( struct V_6 * V_6 )
{
F_19 ( V_6 , 0 , ~ 0 ) ;
V_22 -> V_23 ( V_6 ) ;
}
void F_25 ( struct V_6 * V_6 ,
struct V_19 * V_20 )
{
F_26 ( & V_6 -> V_24 ) ;
F_19 ( V_6 , V_20 -> V_25 ,
V_20 -> V_25 + V_20 -> V_21 - 1 ) ;
V_22 -> V_26 ( V_6 , V_20 ) ;
F_27 ( & V_6 -> V_24 ) ;
}
int F_28 ( struct V_6 * V_6 ,
struct V_19 * V_27 ,
const struct V_28 * V_29 ,
enum V_30 V_31 )
{
return 0 ;
}
void F_29 ( struct V_6 * V_6 ,
const struct V_28 * V_29 ,
const struct V_19 * V_32 ,
const struct V_19 * V_33 ,
enum V_30 V_31 )
{
int V_34 ;
F_30 ( L_1 ,
V_35 , V_6 , V_29 -> V_20 , V_29 -> V_36 ,
V_29 -> V_37 , V_29 -> V_38 ) ;
if ( V_31 == V_39 &&
( ! ( V_32 -> V_40 & V_41 ) &&
V_33 -> V_40 & V_41 ) ) {
F_26 ( & V_6 -> V_24 ) ;
V_34 = F_31 ( V_6 , V_33 -> V_25 ,
V_33 -> V_25 + V_33 -> V_21 - 1 ) ;
if ( V_34 )
V_22 -> V_26 ( V_6 , V_33 ) ;
F_27 ( & V_6 -> V_24 ) ;
}
}
static inline void F_32 ( const char * V_42 , void * V_43 , void * V_44 )
{
T_1 * V_45 ;
F_33 ( L_2 , V_42 ) ;
F_33 ( L_3 ) ;
F_33 ( L_4 ) ;
for ( V_45 = V_43 ; V_45 < ( T_1 * ) V_44 ; ++ V_45 )
F_33 ( L_5 , * V_45 , V_45 ) ;
F_33 ( L_6 ) ;
F_33 ( L_7 , V_42 ) ;
}
struct V_1 * F_34 ( struct V_6 * V_6 , unsigned int V_46 )
{
int V_47 , V_48 ;
void * V_49 , * V_45 , * V_50 , * V_51 , * V_52 ;
int V_10 ;
struct V_1 * V_2 = F_35 ( sizeof( struct V_1 ) , V_53 ) ;
if ( ! V_2 ) {
V_47 = - V_9 ;
goto V_54;
}
V_47 = F_36 ( V_2 , V_6 , V_46 ) ;
if ( V_47 )
goto V_55;
F_30 ( L_8 , V_6 , V_46 , V_2 ) ;
if ( V_56 || V_57 )
V_48 = 0x200 + V_58 * 64 ;
else
V_48 = 0x4000 ;
V_49 = F_35 ( F_37 ( V_48 , V_59 ) , V_53 ) ;
if ( ! V_49 ) {
V_47 = - V_9 ;
goto V_60;
}
F_30 ( L_9 ,
F_37 ( V_48 , V_59 ) , V_49 ) ;
if ( ! V_61 && F_38 ( V_49 ) >= 0x20000000 ) {
F_39 ( L_10 ,
V_49 ) ;
V_47 = - V_9 ;
goto V_62;
}
V_2 -> V_3 . V_63 = V_49 ;
V_50 = V_49 + 0x2000 ;
V_51 = V_49 ;
V_52 = F_40 ( V_51 , V_50 ) ;
F_41 ( V_49 + 0x180 , V_50 ) ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
F_30 ( L_11 ,
V_49 + 0x200 + ( V_10 * V_58 ) ) ;
F_41 ( V_49 + 0x200 + V_10 * V_58 ,
V_50 ) ;
}
V_45 = V_50 ;
V_45 = F_42 ( V_45 ) ;
V_2 -> V_3 . V_64 = V_45 ;
V_45 = F_43 ( V_45 ) ;
F_33 ( L_12 ) ;
F_33 ( L_13 ) ;
F_33 ( L_14 ) ;
F_32 ( L_15 , V_2 -> V_3 . V_64 , V_45 ) ;
F_32 ( L_16 , V_51 , V_52 ) ;
F_32 ( L_17 , V_49 + 0x180 , V_49 + 0x200 ) ;
F_32 ( L_18 , V_49 + 0x2000 , V_2 -> V_3 . V_64 ) ;
F_44 ( ( unsigned long ) V_49 ,
( unsigned long ) V_49 + F_37 ( V_48 , V_59 ) ) ;
V_2 -> V_3 . V_65 = F_35 ( V_59 << 1 , V_53 ) ;
if ( ! V_2 -> V_3 . V_65 ) {
V_47 = - V_9 ;
goto V_62;
}
F_30 ( L_19 , V_2 -> V_3 . V_65 ) ;
F_45 ( V_2 ) ;
V_2 -> V_3 . V_66 = - 1 ;
F_46 ( V_2 ) ;
return V_2 ;
V_62:
F_47 ( V_49 ) ;
V_60:
F_48 ( V_2 ) ;
V_55:
F_47 ( V_2 ) ;
V_54:
return F_49 ( V_47 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_50 ( & V_2 -> V_3 . V_67 ) ;
F_48 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
F_47 ( V_2 -> V_3 . V_63 ) ;
F_47 ( V_2 -> V_3 . V_65 ) ;
F_47 ( V_2 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
}
int F_54 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
return - V_18 ;
}
int F_55 ( struct V_1 * V_2 , struct V_70 * V_71 )
{
int V_72 = - V_73 ;
T_2 V_74 ;
if ( V_2 -> V_75 )
F_56 ( V_76 , & V_2 -> V_77 , & V_74 ) ;
if ( V_2 -> V_78 ) {
if ( ! V_2 -> V_79 )
F_57 ( V_2 , V_71 ) ;
V_2 -> V_78 = 0 ;
}
if ( V_71 -> V_80 )
goto V_54;
F_58 ( 1 ) ;
F_59 () ;
F_60 () ;
F_61 ( V_2 ) ;
F_62 ( V_2 -> V_81 , V_82 ) ;
V_72 = V_22 -> V_64 ( V_71 , V_2 ) ;
F_63 ( V_2 ) ;
F_64 () ;
F_65 () ;
V_54:
if ( V_2 -> V_75 )
F_56 ( V_76 , & V_74 , NULL ) ;
return V_72 ;
}
int F_66 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
int V_85 = ( int ) V_84 -> V_84 ;
struct V_1 * V_86 = NULL ;
if ( V_85 == 3 || V_85 == - 3 || V_85 == 4 || V_85 == - 4 )
F_30 ( L_20 , V_35 , V_84 -> V_87 ,
( int ) V_85 ) ;
if ( V_84 -> V_87 == - 1 )
V_86 = V_2 ;
else
V_86 = V_2 -> V_6 -> V_13 [ V_84 -> V_87 ] ;
if ( V_85 == 2 || V_85 == 3 || V_85 == 4 ) {
V_22 -> V_88 ( V_86 , V_84 ) ;
} else if ( V_85 == - 2 || V_85 == - 3 || V_85 == - 4 ) {
V_22 -> V_89 ( V_86 , V_84 ) ;
} else {
F_39 ( L_21 , V_35 ,
V_84 -> V_87 , V_84 -> V_84 ) ;
return - V_90 ;
}
V_86 -> V_3 . V_91 = 0 ;
if ( F_67 ( & V_86 -> V_92 ) )
F_68 ( & V_86 -> V_92 ) ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
return - V_18 ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
return - V_18 ;
}
static unsigned long F_71 ( struct V_1 * V_2 )
{
unsigned long V_95 ;
V_95 = F_72 ( V_96 ) ;
if ( F_73 ( & V_2 -> V_3 ) ) {
V_95 += F_72 ( V_97 ) + 48 ;
if ( V_98 . V_99 & V_100 )
V_95 += 16 ;
}
if ( F_74 ( & V_2 -> V_3 ) )
V_95 += F_72 ( V_101 ) + 32 ;
V_95 += V_22 -> V_102 ( V_2 ) ;
return V_95 ;
}
static int F_75 ( struct V_1 * V_2 , T_3 T_4 * V_103 )
{
T_3 V_104 ;
unsigned int V_10 ;
if ( F_76 ( V_103 , V_96 ,
sizeof( V_96 ) ) )
return - V_105 ;
V_103 += F_72 ( V_96 ) ;
if ( F_73 ( & V_2 -> V_3 ) ) {
if ( F_76 ( V_103 , V_97 ,
sizeof( V_97 ) ) )
return - V_105 ;
V_103 += F_72 ( V_97 ) ;
for ( V_10 = 0 ; V_10 < 32 ; ++ V_10 ) {
V_104 = F_77 ( V_10 ) ;
if ( F_76 ( V_103 , & V_104 , sizeof( V_104 ) ) )
return - V_105 ;
++ V_103 ;
if ( V_10 & 1 && ! ( V_98 . V_99 & V_100 ) )
continue;
V_104 = F_78 ( V_10 ) ;
if ( F_76 ( V_103 , & V_104 , sizeof( V_104 ) ) )
return - V_105 ;
++ V_103 ;
}
}
if ( F_74 ( & V_2 -> V_3 ) ) {
if ( F_76 ( V_103 , V_101 ,
sizeof( V_101 ) ) )
return - V_105 ;
V_103 += F_72 ( V_101 ) ;
for ( V_10 = 0 ; V_10 < 32 ; ++ V_10 ) {
V_104 = F_79 ( V_10 ) ;
if ( F_76 ( V_103 , & V_104 , sizeof( V_104 ) ) )
return - V_105 ;
++ V_103 ;
}
}
return V_22 -> V_106 ( V_2 , V_103 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
const struct V_107 * V_108 )
{
struct V_109 * V_110 = V_2 -> V_3 . V_110 ;
struct V_111 * V_112 = & V_2 -> V_3 . V_112 ;
int V_95 ;
T_5 V_113 ;
T_5 V_114 [ 2 ] ;
unsigned int V_115 ;
switch ( V_108 -> V_46 ) {
case V_116 ... V_117 :
V_113 = ( long ) V_2 -> V_3 . V_118 [ V_108 -> V_46 - V_116 ] ;
break;
#ifndef F_81
case V_119 :
V_113 = ( long ) V_2 -> V_3 . V_120 ;
break;
case V_121 :
V_113 = ( long ) V_2 -> V_3 . V_122 ;
break;
#endif
case V_123 :
V_113 = ( long ) V_2 -> V_3 . V_124 ;
break;
case F_77 ( 0 ) ... F_77 ( 31 ) :
if ( ! F_82 ( & V_2 -> V_3 ) )
return - V_90 ;
V_115 = V_108 -> V_46 - F_77 ( 0 ) ;
if ( F_83 ( V_110 ) & V_125 )
V_113 = F_84 ( & V_112 -> V_126 [ V_115 ] , 0 ) ;
else
V_113 = F_84 ( & V_112 -> V_126 [ V_115 & ~ 1 ] , V_115 & 1 ) ;
break;
case F_78 ( 0 ) ... F_78 ( 31 ) :
if ( ! F_82 ( & V_2 -> V_3 ) )
return - V_90 ;
V_115 = V_108 -> V_46 - F_78 ( 0 ) ;
if ( V_115 & 1 && ! ( F_83 ( V_110 ) & V_125 ) )
return - V_90 ;
V_113 = F_85 ( & V_112 -> V_126 [ V_115 ] , 0 ) ;
break;
case V_127 :
if ( ! F_82 ( & V_2 -> V_3 ) )
return - V_90 ;
V_113 = V_98 . V_99 ;
break;
case V_128 :
if ( ! F_82 ( & V_2 -> V_3 ) )
return - V_90 ;
V_113 = V_112 -> V_129 ;
break;
case F_79 ( 0 ) ... F_79 ( 31 ) :
if ( ! F_86 ( & V_2 -> V_3 ) )
return - V_90 ;
if ( ! ( F_83 ( V_110 ) & V_125 ) )
return - V_90 ;
V_115 = V_108 -> V_46 - F_79 ( 0 ) ;
#ifdef F_87
V_114 [ 0 ] = F_85 ( & V_112 -> V_126 [ V_115 ] , 0 ) ;
V_114 [ 1 ] = F_85 ( & V_112 -> V_126 [ V_115 ] , 1 ) ;
#else
V_114 [ 0 ] = F_85 ( & V_112 -> V_126 [ V_115 ] , 1 ) ;
V_114 [ 1 ] = F_85 ( & V_112 -> V_126 [ V_115 ] , 0 ) ;
#endif
break;
case V_130 :
if ( ! F_86 ( & V_2 -> V_3 ) )
return - V_90 ;
V_113 = V_98 . V_131 ;
break;
case V_132 :
if ( ! F_86 ( & V_2 -> V_3 ) )
return - V_90 ;
V_113 = V_112 -> V_133 ;
break;
default:
V_95 = V_22 -> V_134 ( V_2 , V_108 , & V_113 ) ;
if ( V_95 )
return V_95 ;
break;
}
if ( ( V_108 -> V_46 & V_135 ) == V_136 ) {
T_3 T_4 * V_137 = ( T_3 T_4 * ) ( long ) V_108 -> V_138 ;
return F_88 ( V_113 , V_137 ) ;
} else if ( ( V_108 -> V_46 & V_135 ) == V_139 ) {
T_1 T_4 * V_140 = ( T_1 T_4 * ) ( long ) V_108 -> V_138 ;
T_1 V_141 = ( T_1 ) V_113 ;
return F_88 ( V_141 , V_140 ) ;
} else if ( ( V_108 -> V_46 & V_135 ) == V_142 ) {
void T_4 * V_143 = ( void T_4 * ) ( long ) V_108 -> V_138 ;
return F_76 ( V_143 , V_114 , 16 ) ? - V_105 : 0 ;
} else {
return - V_90 ;
}
}
static int F_89 ( struct V_1 * V_2 ,
const struct V_107 * V_108 )
{
struct V_109 * V_110 = V_2 -> V_3 . V_110 ;
struct V_111 * V_112 = & V_2 -> V_3 . V_112 ;
T_5 V_113 ;
T_5 V_114 [ 2 ] ;
unsigned int V_115 ;
if ( ( V_108 -> V_46 & V_135 ) == V_136 ) {
T_3 T_4 * V_137 = ( T_3 T_4 * ) ( long ) V_108 -> V_138 ;
if ( F_90 ( V_113 , V_137 ) != 0 )
return - V_105 ;
} else if ( ( V_108 -> V_46 & V_135 ) == V_139 ) {
T_1 T_4 * V_140 = ( T_1 T_4 * ) ( long ) V_108 -> V_138 ;
T_6 V_141 ;
if ( F_90 ( V_141 , V_140 ) != 0 )
return - V_105 ;
V_113 = ( T_5 ) V_141 ;
} else if ( ( V_108 -> V_46 & V_135 ) == V_142 ) {
void T_4 * V_143 = ( void T_4 * ) ( long ) V_108 -> V_138 ;
return F_91 ( V_114 , V_143 , 16 ) ? - V_105 : 0 ;
} else {
return - V_90 ;
}
switch ( V_108 -> V_46 ) {
case V_116 :
break;
case V_144 ... V_117 :
V_2 -> V_3 . V_118 [ V_108 -> V_46 - V_116 ] = V_113 ;
break;
#ifndef F_81
case V_119 :
V_2 -> V_3 . V_120 = V_113 ;
break;
case V_121 :
V_2 -> V_3 . V_122 = V_113 ;
break;
#endif
case V_123 :
V_2 -> V_3 . V_124 = V_113 ;
break;
case F_77 ( 0 ) ... F_77 ( 31 ) :
if ( ! F_82 ( & V_2 -> V_3 ) )
return - V_90 ;
V_115 = V_108 -> V_46 - F_77 ( 0 ) ;
if ( F_83 ( V_110 ) & V_125 )
F_92 ( & V_112 -> V_126 [ V_115 ] , 0 , V_113 ) ;
else
F_92 ( & V_112 -> V_126 [ V_115 & ~ 1 ] , V_115 & 1 , V_113 ) ;
break;
case F_78 ( 0 ) ... F_78 ( 31 ) :
if ( ! F_82 ( & V_2 -> V_3 ) )
return - V_90 ;
V_115 = V_108 -> V_46 - F_78 ( 0 ) ;
if ( V_115 & 1 && ! ( F_83 ( V_110 ) & V_125 ) )
return - V_90 ;
F_93 ( & V_112 -> V_126 [ V_115 ] , 0 , V_113 ) ;
break;
case V_127 :
if ( ! F_82 ( & V_2 -> V_3 ) )
return - V_90 ;
break;
case V_128 :
if ( ! F_82 ( & V_2 -> V_3 ) )
return - V_90 ;
V_112 -> V_129 = V_113 ;
break;
case F_79 ( 0 ) ... F_79 ( 31 ) :
if ( ! F_86 ( & V_2 -> V_3 ) )
return - V_90 ;
V_115 = V_108 -> V_46 - F_79 ( 0 ) ;
#ifdef F_87
F_93 ( & V_112 -> V_126 [ V_115 ] , 0 , V_114 [ 0 ] ) ;
F_93 ( & V_112 -> V_126 [ V_115 ] , 1 , V_114 [ 1 ] ) ;
#else
F_93 ( & V_112 -> V_126 [ V_115 ] , 1 , V_114 [ 0 ] ) ;
F_93 ( & V_112 -> V_126 [ V_115 ] , 0 , V_114 [ 1 ] ) ;
#endif
break;
case V_130 :
if ( ! F_86 ( & V_2 -> V_3 ) )
return - V_90 ;
break;
case V_132 :
if ( ! F_86 ( & V_2 -> V_3 ) )
return - V_90 ;
V_112 -> V_133 = V_113 ;
break;
default:
return V_22 -> V_145 ( V_2 , V_108 , V_113 ) ;
}
return 0 ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
int V_72 = 0 ;
if ( ! F_95 ( V_2 -> V_6 , V_147 -> V_147 ) )
return - V_90 ;
if ( V_147 -> V_40 )
return - V_90 ;
if ( V_147 -> args [ 0 ] )
return - V_90 ;
switch ( V_147 -> V_147 ) {
case V_148 :
V_2 -> V_3 . V_149 = true ;
break;
case V_150 :
V_2 -> V_3 . V_151 = true ;
break;
default:
V_72 = - V_90 ;
break;
}
return V_72 ;
}
long F_96 ( struct V_14 * V_15 , unsigned int V_16 ,
unsigned long V_17 )
{
struct V_1 * V_2 = V_15 -> V_152 ;
void T_4 * V_153 = ( void T_4 * ) V_17 ;
long V_72 ;
switch ( V_16 ) {
case V_154 :
case V_155 : {
struct V_107 V_108 ;
if ( F_91 ( & V_108 , V_153 , sizeof( V_108 ) ) )
return - V_105 ;
if ( V_16 == V_154 )
return F_89 ( V_2 , & V_108 ) ;
else
return F_80 ( V_2 , & V_108 ) ;
}
case V_156 : {
struct V_157 T_4 * V_158 = V_153 ;
struct V_157 V_159 ;
unsigned V_160 ;
if ( F_91 ( & V_159 , V_158 , sizeof( V_159 ) ) )
return - V_105 ;
V_160 = V_159 . V_160 ;
V_159 . V_160 = F_71 ( V_2 ) ;
if ( F_76 ( V_158 , & V_159 , sizeof( V_159 ) ) )
return - V_105 ;
if ( V_160 < V_159 . V_160 )
return - V_161 ;
return F_75 ( V_2 , V_158 -> V_108 ) ;
}
case V_162 :
{
struct V_83 V_84 ;
if ( F_91 ( & V_84 , V_153 , sizeof( V_84 ) ) )
return - V_105 ;
F_30 ( L_22 , V_2 -> V_163 , V_35 ,
V_84 . V_84 ) ;
V_72 = F_66 ( V_2 , & V_84 ) ;
break;
}
case V_164 : {
struct V_146 V_147 ;
if ( F_91 ( & V_147 , V_153 , sizeof( V_147 ) ) )
return - V_105 ;
V_72 = F_94 ( V_2 , & V_147 ) ;
break;
}
default:
V_72 = - V_18 ;
}
return V_72 ;
}
int F_97 ( struct V_6 * V_6 , struct V_165 * log )
{
struct V_166 * V_167 ;
struct V_19 * V_27 ;
bool V_168 = false ;
int V_72 ;
F_13 ( & V_6 -> V_169 ) ;
V_72 = F_98 ( V_6 , log , & V_168 ) ;
if ( V_168 ) {
V_167 = V_166 ( V_6 ) ;
V_27 = F_99 ( V_167 , log -> V_20 ) ;
V_22 -> V_26 ( V_6 , V_27 ) ;
}
F_16 ( & V_6 -> V_169 ) ;
return V_72 ;
}
long F_100 ( struct V_14 * V_15 , unsigned int V_16 , unsigned long V_17 )
{
long V_72 ;
switch ( V_16 ) {
default:
V_72 = - V_18 ;
}
return V_72 ;
}
int F_101 ( void * V_170 )
{
if ( V_22 ) {
F_39 ( L_23 ) ;
return - V_171 ;
}
return F_102 ( & V_22 ) ;
}
void F_103 ( void )
{
V_22 = NULL ;
}
int F_104 ( struct V_1 * V_2 ,
struct V_172 * V_173 )
{
return - V_18 ;
}
int F_105 ( struct V_1 * V_2 ,
struct V_172 * V_173 )
{
return - V_18 ;
}
void F_106 ( struct V_1 * V_2 )
{
}
int F_107 ( struct V_1 * V_2 , struct V_174 * V_112 )
{
return - V_18 ;
}
int F_108 ( struct V_1 * V_2 , struct V_174 * V_112 )
{
return - V_18 ;
}
int F_109 ( struct V_1 * V_2 , struct V_175 * V_176 )
{
return V_177 ;
}
int F_95 ( struct V_6 * V_6 , long V_178 )
{
int V_72 ;
switch ( V_178 ) {
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
V_72 = 1 ;
break;
case V_184 :
V_72 = V_185 ;
break;
case V_186 :
V_72 = F_110 () ;
break;
case V_187 :
V_72 = V_188 ;
break;
case V_148 :
V_72 = ! ! V_189 ;
break;
case V_150 :
V_72 = V_190 && ! ( V_98 . V_131 & V_191 ) ;
break;
default:
V_72 = 0 ;
break;
}
return V_72 ;
}
int F_111 ( struct V_1 * V_2 )
{
return F_112 ( V_2 ) ;
}
int F_113 ( struct V_1 * V_2 )
{
int V_10 ;
struct V_109 * V_110 ;
if ( ! V_2 )
return - 1 ;
F_30 ( L_24 ) ;
F_30 ( L_25 , V_2 -> V_3 . V_124 ) ;
F_30 ( L_26 , V_2 -> V_3 . V_4 ) ;
for ( V_10 = 0 ; V_10 < 32 ; V_10 += 4 ) {
F_30 ( L_27 , V_10 ,
V_2 -> V_3 . V_118 [ V_10 ] ,
V_2 -> V_3 . V_118 [ V_10 + 1 ] ,
V_2 -> V_3 . V_118 [ V_10 + 2 ] , V_2 -> V_3 . V_118 [ V_10 + 3 ] ) ;
}
F_30 ( L_28 , V_2 -> V_3 . V_120 ) ;
F_30 ( L_29 , V_2 -> V_3 . V_122 ) ;
V_110 = V_2 -> V_3 . V_110 ;
F_30 ( L_30 ,
F_83 ( V_110 ) ,
F_114 ( V_110 ) ) ;
F_30 ( L_31 , F_115 ( V_110 ) ) ;
return 0 ;
}
int F_116 ( struct V_1 * V_2 , struct V_192 * V_193 )
{
int V_10 ;
for ( V_10 = 1 ; V_10 < F_72 ( V_2 -> V_3 . V_118 ) ; V_10 ++ )
V_2 -> V_3 . V_118 [ V_10 ] = V_193 -> V_194 [ V_10 ] ;
V_2 -> V_3 . V_118 [ 0 ] = 0 ;
V_2 -> V_3 . V_120 = V_193 -> V_120 ;
V_2 -> V_3 . V_122 = V_193 -> V_122 ;
V_2 -> V_3 . V_124 = V_193 -> V_124 ;
return 0 ;
}
int F_117 ( struct V_1 * V_2 , struct V_192 * V_193 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < F_72 ( V_2 -> V_3 . V_118 ) ; V_10 ++ )
V_193 -> V_194 [ V_10 ] = V_2 -> V_3 . V_118 [ V_10 ] ;
V_193 -> V_120 = V_2 -> V_3 . V_120 ;
V_193 -> V_122 = V_2 -> V_3 . V_122 ;
V_193 -> V_124 = V_2 -> V_3 . V_124 ;
return 0 ;
}
static void F_118 ( unsigned long V_195 )
{
struct V_1 * V_2 = (struct V_1 * ) V_195 ;
V_22 -> V_196 ( V_2 ) ;
V_2 -> V_3 . V_91 = 0 ;
if ( F_67 ( & V_2 -> V_92 ) )
F_68 ( & V_2 -> V_92 ) ;
}
static enum V_197 F_119 ( struct V_198 * V_199 )
{
struct V_1 * V_2 ;
V_2 = F_120 ( V_199 , struct V_1 , V_3 . V_67 ) ;
F_118 ( ( unsigned long ) V_2 ) ;
return F_121 ( V_2 ) ;
}
int F_122 ( struct V_1 * V_2 )
{
int V_47 ;
V_47 = V_22 -> V_200 ( V_2 ) ;
if ( V_47 )
return V_47 ;
F_123 ( & V_2 -> V_3 . V_67 , V_201 ,
V_202 ) ;
V_2 -> V_3 . V_67 . V_203 = F_119 ;
return 0 ;
}
void F_124 ( struct V_1 * V_2 )
{
V_22 -> V_204 ( V_2 ) ;
}
int F_125 ( struct V_1 * V_2 ,
struct V_205 * V_206 )
{
return 0 ;
}
int F_126 ( struct V_1 * V_2 )
{
return V_22 -> V_207 ( V_2 ) ;
}
static void F_127 ( void )
{
T_1 V_208 = F_128 () ;
if ( V_209 )
V_208 |= ( V_210 ) ;
F_129 ( V_208 ) ;
F_130 () ;
}
int F_131 ( struct V_70 * V_71 , struct V_1 * V_2 )
{
T_1 V_211 = V_2 -> V_3 . V_212 ;
T_1 V_213 = ( V_211 >> V_214 ) & 0x1f ;
T_1 T_4 * V_215 = ( T_1 T_4 * ) V_2 -> V_3 . V_124 ;
unsigned long V_216 = V_2 -> V_3 . V_217 ;
enum V_218 V_219 = V_220 ;
T_1 V_221 ;
int V_95 = V_222 ;
V_2 -> V_81 = V_223 ;
F_132 () ;
V_71 -> V_224 = V_225 ;
V_71 -> V_226 = 1 ;
F_127 () ;
F_65 () ;
F_30 ( L_32 ,
V_211 , V_215 , V_71 , V_2 ) ;
F_133 ( V_2 , V_213 ) ;
V_219 = F_134 ( V_211 , V_215 , V_71 , V_2 ) ;
if ( V_219 == V_227 ) {
goto V_228;
} else if ( V_219 == V_229 ) {
V_71 -> V_224 = V_230 ;
V_95 = V_231 ;
goto V_228;
}
switch ( V_213 ) {
case V_232 :
F_30 ( L_33 , V_2 -> V_163 , V_215 ) ;
++ V_2 -> V_233 . V_234 ;
if ( F_135 () )
F_136 () ;
V_95 = V_222 ;
break;
case V_235 :
F_30 ( L_34 , V_215 ) ;
++ V_2 -> V_233 . V_236 ;
V_95 = V_22 -> V_237 ( V_2 ) ;
if ( V_71 -> V_224 == V_238 )
V_95 = V_231 ;
break;
case V_239 :
++ V_2 -> V_233 . V_240 ;
V_95 = V_22 -> V_241 ( V_2 ) ;
break;
case V_242 :
F_30 ( L_35 ,
V_211 , F_83 ( V_2 -> V_3 . V_110 ) , V_215 ,
V_216 ) ;
++ V_2 -> V_233 . V_243 ;
V_95 = V_22 -> V_244 ( V_2 ) ;
break;
case V_245 :
F_30 ( L_36 ,
V_211 , V_215 , V_216 ) ;
++ V_2 -> V_233 . V_246 ;
V_95 = V_22 -> V_247 ( V_2 ) ;
break;
case V_248 :
++ V_2 -> V_233 . V_249 ;
V_95 = V_22 -> V_250 ( V_2 ) ;
break;
case V_251 :
++ V_2 -> V_233 . V_252 ;
V_95 = V_22 -> V_253 ( V_2 ) ;
break;
case V_254 :
++ V_2 -> V_233 . V_255 ;
V_95 = V_22 -> V_256 ( V_2 ) ;
break;
case V_257 :
++ V_2 -> V_233 . V_258 ;
V_95 = V_22 -> V_259 ( V_2 ) ;
break;
case V_260 :
++ V_2 -> V_233 . V_261 ;
V_95 = V_22 -> V_262 ( V_2 ) ;
break;
case V_263 :
++ V_2 -> V_233 . V_264 ;
V_95 = V_22 -> V_265 ( V_2 ) ;
break;
case V_266 :
++ V_2 -> V_233 . V_267 ;
V_95 = V_22 -> V_268 ( V_2 ) ;
break;
case V_269 :
++ V_2 -> V_233 . V_270 ;
V_95 = V_22 -> V_271 ( V_2 ) ;
break;
case V_272 :
++ V_2 -> V_233 . V_273 ;
V_95 = V_22 -> V_274 ( V_2 ) ;
break;
default:
if ( V_211 & V_275 )
V_215 += 1 ;
V_221 = 0 ;
F_137 ( V_215 , V_2 , & V_221 ) ;
F_39 ( L_37 ,
V_213 , V_215 , V_221 , V_216 ,
F_83 ( V_2 -> V_3 . V_110 ) ) ;
F_113 ( V_2 ) ;
V_71 -> V_224 = V_230 ;
V_95 = V_231 ;
break;
}
V_228:
F_59 () ;
if ( V_219 == V_220 && ! ( V_95 & V_231 ) )
F_138 ( V_2 , V_211 ) ;
if ( ! ( V_95 & V_231 ) ) {
if ( F_139 ( V_276 ) ) {
V_71 -> V_224 = V_277 ;
V_95 = ( - V_73 << 2 ) | V_231 ;
++ V_2 -> V_233 . V_278 ;
F_133 ( V_2 , V_279 ) ;
}
}
if ( V_95 == V_222 ) {
F_140 ( V_2 ) ;
F_62 ( V_2 -> V_81 , V_82 ) ;
V_22 -> V_280 ( V_71 , V_2 ) ;
if ( F_82 ( & V_2 -> V_3 ) &&
F_128 () & V_281 )
F_141 ( & V_2 -> V_3 ) ;
if ( F_86 ( & V_2 -> V_3 ) &&
F_142 () & V_282 )
F_143 ( & V_2 -> V_3 ) ;
}
F_144 () ;
return V_95 ;
}
void F_145 ( struct V_1 * V_2 )
{
struct V_109 * V_110 = V_2 -> V_3 . V_110 ;
unsigned int V_283 , V_284 ;
F_146 () ;
V_283 = F_83 ( V_110 ) ;
if ( V_190 && V_283 & V_281 && ! ( V_283 & V_125 ) &&
V_2 -> V_3 . V_285 & V_286 )
F_147 ( V_2 ) ;
F_148 ( V_281 | V_125 , V_283 ) ;
if ( V_287 ) {
V_284 = F_149 ( V_110 ) ;
F_150 ( V_288 , V_284 ) ;
}
F_151 () ;
if ( ! ( V_2 -> V_3 . V_285 & V_289 ) ) {
F_152 ( & V_2 -> V_3 ) ;
V_2 -> V_3 . V_285 |= V_289 ;
F_153 ( V_2 , V_290 , V_291 ) ;
} else {
F_153 ( V_2 , V_292 , V_291 ) ;
}
F_154 () ;
}
void F_155 ( struct V_1 * V_2 )
{
struct V_109 * V_110 = V_2 -> V_3 . V_110 ;
unsigned int V_283 , V_284 ;
F_146 () ;
if ( F_82 ( & V_2 -> V_3 ) ) {
V_283 = F_83 ( V_110 ) ;
if ( ! ( V_283 & V_125 ) &&
( V_2 -> V_3 . V_285 & ( V_289 |
V_286 ) ) == V_289 )
F_147 ( V_2 ) ;
F_148 ( V_281 | V_125 , V_283 ) ;
if ( V_283 & V_281 && V_287 ) {
V_284 = F_149 ( V_110 ) ;
F_150 ( V_288 , V_284 ) ;
}
}
F_156 ( V_282 ) ;
F_151 () ;
switch ( V_2 -> V_3 . V_285 & ( V_289 | V_286 ) ) {
case V_289 :
F_157 ( & V_2 -> V_3 ) ;
V_2 -> V_3 . V_285 |= V_286 ;
F_153 ( V_2 , V_290 , V_293 ) ;
break;
case 0 :
F_158 ( & V_2 -> V_3 ) ;
V_2 -> V_3 . V_285 |= V_286 ;
if ( F_82 ( & V_2 -> V_3 ) )
V_2 -> V_3 . V_285 |= V_289 ;
F_153 ( V_2 , V_290 ,
V_294 ) ;
break;
default:
F_153 ( V_2 , V_292 , V_293 ) ;
break;
}
F_154 () ;
}
void F_159 ( struct V_1 * V_2 )
{
F_146 () ;
if ( V_190 && V_2 -> V_3 . V_285 & V_286 ) {
F_160 () ;
F_153 ( V_2 , V_295 , V_293 ) ;
V_2 -> V_3 . V_285 &= ~ V_286 ;
}
if ( V_2 -> V_3 . V_285 & V_289 ) {
F_161 ( V_281 | V_125 ) ;
F_153 ( V_2 , V_295 , V_291 ) ;
V_2 -> V_3 . V_285 &= ~ V_289 ;
}
F_154 () ;
}
void F_147 ( struct V_1 * V_2 )
{
F_146 () ;
if ( V_190 && V_2 -> V_3 . V_285 & V_286 ) {
F_156 ( V_282 ) ;
F_151 () ;
F_162 ( & V_2 -> V_3 ) ;
F_153 ( V_2 , V_296 , V_294 ) ;
F_160 () ;
if ( V_2 -> V_3 . V_285 & V_289 ) {
F_161 ( V_281 | V_125 ) ;
F_163 () ;
}
V_2 -> V_3 . V_285 &= ~ ( V_289 | V_286 ) ;
} else if ( V_2 -> V_3 . V_285 & V_289 ) {
F_164 ( V_281 ) ;
F_151 () ;
F_165 ( & V_2 -> V_3 ) ;
V_2 -> V_3 . V_285 &= ~ V_289 ;
F_153 ( V_2 , V_296 , V_291 ) ;
F_161 ( V_281 | V_125 ) ;
F_163 () ;
}
F_154 () ;
}
static int F_166 ( struct V_297 * V_298 ,
unsigned long V_299 , void * V_300 )
{
struct V_301 * args = (struct V_301 * ) V_300 ;
struct V_302 * V_193 = args -> V_193 ;
unsigned long V_124 ;
if ( V_299 != V_303 && V_299 != V_304 )
return V_305 ;
if ( ! ( V_276 -> V_40 & V_306 ) )
return V_305 ;
F_167 ( F_168 ( V_193 ) ) ;
V_124 = F_169 ( V_193 ) ;
switch ( V_299 ) {
case V_303 :
if ( V_124 != ( unsigned long ) & F_141 + 4 )
return V_305 ;
break;
case V_304 :
if ( ! V_190 ||
V_124 < ( unsigned long ) & F_143 + 4 ||
V_124 > ( unsigned long ) & F_143 + 8 )
return V_305 ;
break;
}
F_169 ( V_193 ) += 4 ;
return V_307 ;
}
static int T_7 F_170 ( void )
{
int V_95 ;
V_95 = F_171 () ;
if ( V_95 )
return V_95 ;
V_95 = F_172 ( NULL , sizeof( struct V_1 ) , 0 , V_308 ) ;
if ( V_95 )
return V_95 ;
F_173 ( & V_309 ) ;
return 0 ;
}
static void T_8 F_174 ( void )
{
F_175 () ;
F_176 ( & V_309 ) ;
}
