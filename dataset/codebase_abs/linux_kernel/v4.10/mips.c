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
bool F_18 ( void )
{
return false ;
}
int F_19 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_20 ( struct V_9 * V_9 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
for ( V_3 = 0 ; V_3 < V_9 -> V_4 . V_17 ; V_3 ++ ) {
if ( V_9 -> V_4 . V_18 [ V_3 ] != V_19 )
F_21 ( V_9 -> V_4 . V_18 [ V_3 ] ) ;
}
F_22 ( V_9 -> V_4 . V_18 ) ;
F_23 (i, vcpu, kvm) {
F_24 ( V_2 ) ;
}
F_25 ( & V_9 -> V_20 ) ;
for ( V_3 = 0 ; V_3 < F_26 ( & V_9 -> V_21 ) ; V_3 ++ )
V_9 -> V_22 [ V_3 ] = NULL ;
F_27 ( & V_9 -> V_21 , 0 ) ;
F_28 ( & V_9 -> V_20 ) ;
}
static void F_29 ( void * V_12 )
{
F_10 ( 0 ) ;
F_11 () ;
F_30 () ;
}
void F_31 ( struct V_9 * V_9 )
{
F_20 ( V_9 ) ;
if ( F_32 ( & V_15 ) == 0 ) {
F_12 ( L_3 ,
V_16 ) ;
F_17 ( F_29 , NULL , 1 ) ;
}
}
long F_33 ( struct V_23 * V_24 , unsigned int V_25 ,
unsigned long V_12 )
{
return - V_26 ;
}
int F_34 ( struct V_9 * V_9 , struct V_27 * V_28 ,
unsigned long V_29 )
{
return 0 ;
}
int F_35 ( struct V_9 * V_9 ,
struct V_27 * V_30 ,
const struct V_31 * V_32 ,
enum V_33 V_34 )
{
return 0 ;
}
void F_36 ( struct V_9 * V_9 ,
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
F_37 ( V_29 * sizeof( unsigned long ) , V_41 ) ;
if ( ! V_9 -> V_4 . V_18 ) {
F_38 ( L_5 ) ;
return;
}
F_12 ( L_6 ,
V_29 , V_9 -> V_4 . V_18 ) ;
for ( V_3 = 0 ; V_3 < V_29 ; V_3 ++ )
V_9 -> V_4 . V_18 [ V_3 ] = V_19 ;
}
}
}
static inline void F_39 ( const char * V_42 , void * V_43 , void * V_44 )
{
T_1 * V_45 ;
F_40 ( L_7 , V_42 ) ;
F_40 ( L_8 ) ;
F_40 ( L_9 ) ;
for ( V_45 = V_43 ; V_45 < ( T_1 * ) V_44 ; ++ V_45 )
F_40 ( L_10 , * V_45 , V_45 ) ;
F_40 ( L_11 ) ;
F_40 ( L_12 , V_42 ) ;
}
struct V_1 * F_41 ( struct V_9 * V_9 , unsigned int V_46 )
{
int V_47 , V_48 ;
void * V_49 , * V_45 , * V_50 ;
int V_3 ;
struct V_1 * V_2 = F_37 ( sizeof( struct V_1 ) , V_41 ) ;
if ( ! V_2 ) {
V_47 = - V_51 ;
goto V_52;
}
V_47 = F_42 ( V_2 , V_9 , V_46 ) ;
if ( V_47 )
goto V_53;
F_12 ( L_13 , V_9 , V_46 , V_2 ) ;
if ( V_54 || V_55 )
V_48 = 0x200 + V_56 * 64 ;
else
V_48 = 0x4000 ;
V_49 = F_37 ( F_43 ( V_48 , V_57 ) , V_41 ) ;
if ( ! V_49 ) {
V_47 = - V_51 ;
goto V_58;
}
F_12 ( L_14 ,
F_43 ( V_48 , V_57 ) , V_49 ) ;
if ( ! V_59 && F_44 ( V_49 ) >= 0x20000000 ) {
F_38 ( L_15 ,
V_49 ) ;
V_47 = - V_51 ;
goto V_60;
}
V_2 -> V_4 . V_61 = V_49 ;
V_50 = V_49 + 0x2000 ;
F_45 ( V_49 , V_50 ) ;
F_45 ( V_49 + 0x180 , V_50 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
F_12 ( L_16 ,
V_49 + 0x200 + ( V_3 * V_56 ) ) ;
F_45 ( V_49 + 0x200 + V_3 * V_56 ,
V_50 ) ;
}
V_45 = V_50 ;
V_45 = F_46 ( V_45 ) ;
V_2 -> V_4 . V_62 = V_45 ;
V_45 = F_47 ( V_45 ) ;
F_40 ( L_17 ) ;
F_40 ( L_18 ) ;
F_40 ( L_19 ) ;
F_39 ( L_20 , V_2 -> V_4 . V_62 , V_45 ) ;
F_39 ( L_21 , V_49 + 0x180 , V_49 + 0x200 ) ;
F_39 ( L_22 , V_49 + 0x2000 , V_2 -> V_4 . V_62 ) ;
F_48 ( ( unsigned long ) V_49 ,
( unsigned long ) V_49 + F_43 ( V_48 , V_57 ) ) ;
V_2 -> V_4 . V_63 = F_37 ( V_57 << 1 , V_41 ) ;
if ( ! V_2 -> V_4 . V_63 ) {
V_47 = - V_51 ;
goto V_60;
}
F_12 ( L_23 , V_2 -> V_4 . V_63 ) ;
F_49 ( V_2 ) ;
V_2 -> V_4 . V_64 = - 1 ;
F_50 ( V_2 ) ;
return V_2 ;
V_60:
F_22 ( V_49 ) ;
V_58:
F_51 ( V_2 ) ;
V_53:
F_22 ( V_2 ) ;
V_52:
return F_52 ( V_47 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
F_53 ( & V_2 -> V_4 . V_65 ) ;
F_51 ( V_2 ) ;
F_54 ( V_2 ) ;
F_22 ( V_2 -> V_4 . V_61 ) ;
F_22 ( V_2 -> V_4 . V_63 ) ;
F_22 ( V_2 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
return - V_26 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = V_2 -> V_4 . V_69 ;
int V_3 , V_70 = F_13 () ;
unsigned int V_71 ;
if ( ! F_58 ( V_2 ) ) {
V_71 = F_59 ( V_69 ) & V_72 ;
if ( V_71 != V_2 -> V_4 . V_73 ) {
F_60 ( & V_2 -> V_4 . V_74 , V_70 ,
V_2 ) ;
V_2 -> V_4 . V_6 [ V_70 ] =
V_2 -> V_4 . V_74 . V_75 . V_76 [ V_70 ] ;
F_2 (i)
if ( V_3 != V_70 )
V_2 -> V_4 . V_6 [ V_70 ] = 0 ;
V_2 -> V_4 . V_73 = V_71 ;
}
}
}
int F_61 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
int V_79 = 0 ;
T_2 V_80 ;
if ( V_2 -> V_81 )
F_62 ( V_82 , & V_2 -> V_83 , & V_80 ) ;
if ( V_2 -> V_84 ) {
if ( ! V_2 -> V_85 )
F_63 ( V_2 , V_78 ) ;
V_2 -> V_84 = 0 ;
}
F_64 ( 1 ) ;
F_65 () ;
F_66 ( V_2 ,
F_67 ( V_2 -> V_4 . V_69 ) ) ;
F_68 () ;
F_69 () ;
F_70 ( V_2 ) ;
F_57 ( V_2 ) ;
V_79 = V_2 -> V_4 . V_62 ( V_78 , V_2 ) ;
F_71 ( V_2 ) ;
F_72 () ;
F_73 () ;
F_74 () ;
if ( V_2 -> V_81 )
F_62 ( V_82 , & V_80 , NULL ) ;
return V_79 ;
}
int F_75 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
int V_88 = ( int ) V_87 -> V_87 ;
struct V_1 * V_89 = NULL ;
if ( V_88 == 3 || V_88 == - 3 || V_88 == 4 || V_88 == - 4 )
F_12 ( L_24 , V_16 , V_87 -> V_70 ,
( int ) V_88 ) ;
if ( V_87 -> V_70 == - 1 )
V_89 = V_2 ;
else
V_89 = V_2 -> V_9 -> V_22 [ V_87 -> V_70 ] ;
if ( V_88 == 2 || V_88 == 3 || V_88 == 4 ) {
V_13 -> V_90 ( V_89 , V_87 ) ;
} else if ( V_88 == - 2 || V_88 == - 3 || V_88 == - 4 ) {
V_13 -> V_91 ( V_89 , V_87 ) ;
} else {
F_38 ( L_25 , V_16 ,
V_87 -> V_70 , V_87 -> V_87 ) ;
return - V_92 ;
}
V_89 -> V_4 . V_93 = 0 ;
if ( F_76 ( & V_89 -> V_94 ) )
F_77 ( & V_89 -> V_94 ) ;
return 0 ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
return - V_26 ;
}
int F_79 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
return - V_26 ;
}
static unsigned long F_80 ( struct V_1 * V_2 )
{
unsigned long V_97 ;
V_97 = F_81 ( V_98 ) ;
if ( F_82 ( & V_2 -> V_4 ) ) {
V_97 += F_81 ( V_99 ) + 48 ;
if ( V_100 . V_101 & V_102 )
V_97 += 16 ;
}
if ( F_83 ( & V_2 -> V_4 ) )
V_97 += F_81 ( V_103 ) + 32 ;
V_97 += F_84 ( V_2 -> V_4 . V_104 ) ;
V_97 += V_13 -> V_105 ( V_2 ) ;
return V_97 ;
}
static int F_85 ( struct V_1 * V_2 , T_3 T_4 * V_106 )
{
T_3 V_107 ;
unsigned int V_3 ;
if ( F_86 ( V_106 , V_98 ,
sizeof( V_98 ) ) )
return - V_108 ;
V_106 += F_81 ( V_98 ) ;
if ( F_82 ( & V_2 -> V_4 ) ) {
if ( F_86 ( V_106 , V_99 ,
sizeof( V_99 ) ) )
return - V_108 ;
V_106 += F_81 ( V_99 ) ;
for ( V_3 = 0 ; V_3 < 32 ; ++ V_3 ) {
V_107 = F_87 ( V_3 ) ;
if ( F_86 ( V_106 , & V_107 , sizeof( V_107 ) ) )
return - V_108 ;
++ V_106 ;
if ( V_3 & 1 && ! ( V_100 . V_101 & V_102 ) )
continue;
V_107 = F_88 ( V_3 ) ;
if ( F_86 ( V_106 , & V_107 , sizeof( V_107 ) ) )
return - V_108 ;
++ V_106 ;
}
}
if ( F_83 ( & V_2 -> V_4 ) ) {
if ( F_86 ( V_106 , V_103 ,
sizeof( V_103 ) ) )
return - V_108 ;
V_106 += F_81 ( V_103 ) ;
for ( V_3 = 0 ; V_3 < 32 ; ++ V_3 ) {
V_107 = F_89 ( V_3 ) ;
if ( F_86 ( V_106 , & V_107 , sizeof( V_107 ) ) )
return - V_108 ;
++ V_106 ;
}
}
for ( V_3 = 0 ; V_3 < 6 ; ++ V_3 ) {
if ( ! ( V_2 -> V_4 . V_104 & F_90 ( V_3 + 2 ) ) )
continue;
if ( F_86 ( V_106 , & V_109 [ V_3 ] ,
sizeof( V_109 [ V_3 ] ) ) )
return - V_108 ;
++ V_106 ;
}
return V_13 -> V_110 ( V_2 , V_106 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
const struct V_111 * V_112 )
{
struct V_68 * V_69 = V_2 -> V_4 . V_69 ;
struct V_113 * V_114 = & V_2 -> V_4 . V_114 ;
int V_97 ;
T_5 V_115 ;
T_5 V_116 [ 2 ] ;
unsigned int V_117 ;
switch ( V_112 -> V_46 ) {
case V_118 ... V_119 :
V_115 = ( long ) V_2 -> V_4 . V_120 [ V_112 -> V_46 - V_118 ] ;
break;
#ifndef F_92
case V_121 :
V_115 = ( long ) V_2 -> V_4 . V_122 ;
break;
case V_123 :
V_115 = ( long ) V_2 -> V_4 . V_124 ;
break;
#endif
case V_125 :
V_115 = ( long ) V_2 -> V_4 . V_126 ;
break;
case F_87 ( 0 ) ... F_87 ( 31 ) :
if ( ! F_93 ( & V_2 -> V_4 ) )
return - V_92 ;
V_117 = V_112 -> V_46 - F_87 ( 0 ) ;
if ( F_94 ( V_69 ) & V_127 )
V_115 = F_95 ( & V_114 -> V_128 [ V_117 ] , 0 ) ;
else
V_115 = F_95 ( & V_114 -> V_128 [ V_117 & ~ 1 ] , V_117 & 1 ) ;
break;
case F_88 ( 0 ) ... F_88 ( 31 ) :
if ( ! F_93 ( & V_2 -> V_4 ) )
return - V_92 ;
V_117 = V_112 -> V_46 - F_88 ( 0 ) ;
if ( V_117 & 1 && ! ( F_94 ( V_69 ) & V_127 ) )
return - V_92 ;
V_115 = F_96 ( & V_114 -> V_128 [ V_117 ] , 0 ) ;
break;
case V_129 :
if ( ! F_93 ( & V_2 -> V_4 ) )
return - V_92 ;
V_115 = V_100 . V_101 ;
break;
case V_130 :
if ( ! F_93 ( & V_2 -> V_4 ) )
return - V_92 ;
V_115 = V_114 -> V_131 ;
break;
case F_89 ( 0 ) ... F_89 ( 31 ) :
if ( ! F_97 ( & V_2 -> V_4 ) )
return - V_92 ;
if ( ! ( F_94 ( V_69 ) & V_127 ) )
return - V_92 ;
V_117 = V_112 -> V_46 - F_89 ( 0 ) ;
#ifdef F_98
V_116 [ 0 ] = F_96 ( & V_114 -> V_128 [ V_117 ] , 0 ) ;
V_116 [ 1 ] = F_96 ( & V_114 -> V_128 [ V_117 ] , 1 ) ;
#else
V_116 [ 0 ] = F_96 ( & V_114 -> V_128 [ V_117 ] , 1 ) ;
V_116 [ 1 ] = F_96 ( & V_114 -> V_128 [ V_117 ] , 0 ) ;
#endif
break;
case V_132 :
if ( ! F_97 ( & V_2 -> V_4 ) )
return - V_92 ;
V_115 = V_100 . V_133 ;
break;
case V_134 :
if ( ! F_97 ( & V_2 -> V_4 ) )
return - V_92 ;
V_115 = V_114 -> V_135 ;
break;
case V_136 :
V_115 = ( long ) F_99 ( V_69 ) ;
break;
case V_137 :
V_115 = ( long ) F_100 ( V_69 ) ;
break;
case V_138 :
V_115 = ( long ) F_101 ( V_69 ) ;
break;
case V_139 :
V_115 = ( long ) F_102 ( V_69 ) ;
break;
case V_140 :
V_115 = ( long ) F_103 ( V_69 ) ;
break;
case V_141 :
V_115 = ( long ) F_104 ( V_69 ) ;
break;
case V_142 :
V_115 = ( long ) F_105 ( V_69 ) ;
break;
case V_143 :
V_115 = ( long ) F_59 ( V_69 ) ;
break;
case V_144 :
V_115 = ( long ) F_106 ( V_69 ) ;
break;
case V_145 :
V_115 = ( long ) F_94 ( V_69 ) ;
break;
case V_146 :
V_115 = ( long ) F_67 ( V_69 ) ;
break;
case V_147 :
V_115 = ( long ) F_107 ( V_69 ) ;
break;
case V_148 :
V_115 = ( long ) F_108 ( V_69 ) ;
break;
case V_149 :
V_115 = ( long ) F_109 ( V_69 ) ;
break;
case V_150 :
V_115 = ( long ) F_110 ( V_69 ) ;
break;
case V_151 :
V_115 = ( long ) F_111 ( V_69 ) ;
break;
case V_152 :
V_115 = ( long ) F_112 ( V_69 ) ;
break;
case V_153 :
V_115 = ( long ) F_113 ( V_69 ) ;
break;
case V_154 :
V_115 = ( long ) F_114 ( V_69 ) ;
break;
case V_155 :
V_115 = ( long ) F_115 ( V_69 ) ;
break;
case V_156 :
V_115 = ( long ) F_116 ( V_69 ) ;
break;
case V_157 ... V_158 :
V_117 = V_112 -> V_46 - V_157 + 2 ;
if ( ! ( V_2 -> V_4 . V_104 & F_90 ( V_117 ) ) )
return - V_92 ;
switch ( V_117 ) {
case 2 :
V_115 = ( long ) F_117 ( V_69 ) ;
break;
case 3 :
V_115 = ( long ) F_118 ( V_69 ) ;
break;
case 4 :
V_115 = ( long ) F_119 ( V_69 ) ;
break;
case 5 :
V_115 = ( long ) F_120 ( V_69 ) ;
break;
case 6 :
V_115 = ( long ) F_121 ( V_69 ) ;
break;
case 7 :
V_115 = ( long ) F_122 ( V_69 ) ;
break;
}
break;
default:
V_97 = V_13 -> V_159 ( V_2 , V_112 , & V_115 ) ;
if ( V_97 )
return V_97 ;
break;
}
if ( ( V_112 -> V_46 & V_160 ) == V_161 ) {
T_3 T_4 * V_162 = ( T_3 T_4 * ) ( long ) V_112 -> V_163 ;
return F_123 ( V_115 , V_162 ) ;
} else if ( ( V_112 -> V_46 & V_160 ) == V_164 ) {
T_1 T_4 * V_165 = ( T_1 T_4 * ) ( long ) V_112 -> V_163 ;
T_1 V_166 = ( T_1 ) V_115 ;
return F_123 ( V_166 , V_165 ) ;
} else if ( ( V_112 -> V_46 & V_160 ) == V_167 ) {
void T_4 * V_168 = ( void T_4 * ) ( long ) V_112 -> V_163 ;
return F_86 ( V_168 , V_116 , 16 ) ? - V_108 : 0 ;
} else {
return - V_92 ;
}
}
static int F_124 ( struct V_1 * V_2 ,
const struct V_111 * V_112 )
{
struct V_68 * V_69 = V_2 -> V_4 . V_69 ;
struct V_113 * V_114 = & V_2 -> V_4 . V_114 ;
T_5 V_115 ;
T_5 V_116 [ 2 ] ;
unsigned int V_117 ;
if ( ( V_112 -> V_46 & V_160 ) == V_161 ) {
T_3 T_4 * V_162 = ( T_3 T_4 * ) ( long ) V_112 -> V_163 ;
if ( F_125 ( V_115 , V_162 ) != 0 )
return - V_108 ;
} else if ( ( V_112 -> V_46 & V_160 ) == V_164 ) {
T_1 T_4 * V_165 = ( T_1 T_4 * ) ( long ) V_112 -> V_163 ;
T_6 V_166 ;
if ( F_125 ( V_166 , V_165 ) != 0 )
return - V_108 ;
V_115 = ( T_5 ) V_166 ;
} else if ( ( V_112 -> V_46 & V_160 ) == V_167 ) {
void T_4 * V_168 = ( void T_4 * ) ( long ) V_112 -> V_163 ;
return F_126 ( V_116 , V_168 , 16 ) ? - V_108 : 0 ;
} else {
return - V_92 ;
}
switch ( V_112 -> V_46 ) {
case V_118 :
break;
case V_169 ... V_119 :
V_2 -> V_4 . V_120 [ V_112 -> V_46 - V_118 ] = V_115 ;
break;
#ifndef F_92
case V_121 :
V_2 -> V_4 . V_122 = V_115 ;
break;
case V_123 :
V_2 -> V_4 . V_124 = V_115 ;
break;
#endif
case V_125 :
V_2 -> V_4 . V_126 = V_115 ;
break;
case F_87 ( 0 ) ... F_87 ( 31 ) :
if ( ! F_93 ( & V_2 -> V_4 ) )
return - V_92 ;
V_117 = V_112 -> V_46 - F_87 ( 0 ) ;
if ( F_94 ( V_69 ) & V_127 )
F_127 ( & V_114 -> V_128 [ V_117 ] , 0 , V_115 ) ;
else
F_127 ( & V_114 -> V_128 [ V_117 & ~ 1 ] , V_117 & 1 , V_115 ) ;
break;
case F_88 ( 0 ) ... F_88 ( 31 ) :
if ( ! F_93 ( & V_2 -> V_4 ) )
return - V_92 ;
V_117 = V_112 -> V_46 - F_88 ( 0 ) ;
if ( V_117 & 1 && ! ( F_94 ( V_69 ) & V_127 ) )
return - V_92 ;
F_128 ( & V_114 -> V_128 [ V_117 ] , 0 , V_115 ) ;
break;
case V_129 :
if ( ! F_93 ( & V_2 -> V_4 ) )
return - V_92 ;
break;
case V_130 :
if ( ! F_93 ( & V_2 -> V_4 ) )
return - V_92 ;
V_114 -> V_131 = V_115 ;
break;
case F_89 ( 0 ) ... F_89 ( 31 ) :
if ( ! F_97 ( & V_2 -> V_4 ) )
return - V_92 ;
V_117 = V_112 -> V_46 - F_89 ( 0 ) ;
#ifdef F_98
F_128 ( & V_114 -> V_128 [ V_117 ] , 0 , V_116 [ 0 ] ) ;
F_128 ( & V_114 -> V_128 [ V_117 ] , 1 , V_116 [ 1 ] ) ;
#else
F_128 ( & V_114 -> V_128 [ V_117 ] , 1 , V_116 [ 0 ] ) ;
F_128 ( & V_114 -> V_128 [ V_117 ] , 0 , V_116 [ 1 ] ) ;
#endif
break;
case V_132 :
if ( ! F_97 ( & V_2 -> V_4 ) )
return - V_92 ;
break;
case V_134 :
if ( ! F_97 ( & V_2 -> V_4 ) )
return - V_92 ;
V_114 -> V_135 = V_115 ;
break;
case V_136 :
F_129 ( V_69 , V_115 ) ;
break;
case V_137 :
F_130 ( V_69 , V_115 ) ;
break;
case V_138 :
F_131 ( V_69 , V_115 ) ;
break;
case V_139 :
F_132 ( V_69 , V_115 ) ;
break;
case V_140 :
F_133 ( V_69 , V_115 ) ;
break;
case V_141 :
F_134 ( V_69 , V_115 ) ;
break;
case V_142 :
F_135 ( V_69 , V_115 ) ;
break;
case V_143 :
F_136 ( V_69 , V_115 ) ;
break;
case V_145 :
F_137 ( V_69 , V_115 ) ;
break;
case V_147 :
F_138 ( V_69 , V_115 ) ;
break;
case V_148 :
F_139 ( V_69 , V_115 ) ;
break;
case V_156 :
F_140 ( V_69 , V_115 ) ;
break;
case V_157 ... V_158 :
V_117 = V_112 -> V_46 - V_157 + 2 ;
if ( ! ( V_2 -> V_4 . V_104 & F_90 ( V_117 ) ) )
return - V_92 ;
switch ( V_117 ) {
case 2 :
F_141 ( V_69 , V_115 ) ;
break;
case 3 :
F_142 ( V_69 , V_115 ) ;
break;
case 4 :
F_143 ( V_69 , V_115 ) ;
break;
case 5 :
F_144 ( V_69 , V_115 ) ;
break;
case 6 :
F_145 ( V_69 , V_115 ) ;
break;
case 7 :
F_146 ( V_69 , V_115 ) ;
break;
}
break;
default:
return V_13 -> V_170 ( V_2 , V_112 , V_115 ) ;
}
return 0 ;
}
static int F_147 ( struct V_1 * V_2 ,
struct V_171 * V_172 )
{
int V_79 = 0 ;
if ( ! F_148 ( V_2 -> V_9 , V_172 -> V_172 ) )
return - V_92 ;
if ( V_172 -> V_173 )
return - V_92 ;
if ( V_172 -> args [ 0 ] )
return - V_92 ;
switch ( V_172 -> V_172 ) {
case V_174 :
V_2 -> V_4 . V_175 = true ;
break;
case V_176 :
V_2 -> V_4 . V_177 = true ;
break;
default:
V_79 = - V_92 ;
break;
}
return V_79 ;
}
long F_149 ( struct V_23 * V_24 , unsigned int V_25 ,
unsigned long V_12 )
{
struct V_1 * V_2 = V_24 -> V_178 ;
void T_4 * V_179 = ( void T_4 * ) V_12 ;
long V_79 ;
switch ( V_25 ) {
case V_180 :
case V_181 : {
struct V_111 V_112 ;
if ( F_126 ( & V_112 , V_179 , sizeof( V_112 ) ) )
return - V_108 ;
if ( V_25 == V_180 )
return F_124 ( V_2 , & V_112 ) ;
else
return F_91 ( V_2 , & V_112 ) ;
}
case V_182 : {
struct V_183 T_4 * V_184 = V_179 ;
struct V_183 V_185 ;
unsigned V_186 ;
if ( F_126 ( & V_185 , V_184 , sizeof( V_185 ) ) )
return - V_108 ;
V_186 = V_185 . V_186 ;
V_185 . V_186 = F_80 ( V_2 ) ;
if ( F_86 ( V_184 , & V_185 , sizeof( V_185 ) ) )
return - V_108 ;
if ( V_186 < V_185 . V_186 )
return - V_187 ;
return F_85 ( V_2 , V_184 -> V_112 ) ;
}
case V_188 :
V_79 = F_1 ( V_2 ) ;
break;
case V_189 :
{
struct V_86 V_87 ;
V_79 = - V_108 ;
if ( F_126 ( & V_87 , V_179 , sizeof( V_87 ) ) )
goto V_52;
F_12 ( L_26 , V_2 -> V_190 , V_16 ,
V_87 . V_87 ) ;
V_79 = F_75 ( V_2 , & V_87 ) ;
break;
}
case V_191 : {
struct V_171 V_172 ;
V_79 = - V_108 ;
if ( F_126 ( & V_172 , V_179 , sizeof( V_172 ) ) )
goto V_52;
V_79 = F_147 ( V_2 , & V_172 ) ;
break;
}
default:
V_79 = - V_26 ;
}
V_52:
return V_79 ;
}
int F_150 ( struct V_9 * V_9 , struct V_192 * log )
{
struct V_193 * V_194 ;
struct V_27 * V_30 ;
unsigned long V_195 , V_196 ;
int V_197 = 0 ;
int V_79 ;
unsigned long V_186 ;
F_25 ( & V_9 -> V_198 ) ;
V_79 = F_151 ( V_9 , log , & V_197 ) ;
if ( V_79 )
goto V_52;
if ( V_197 ) {
V_194 = V_193 ( V_9 ) ;
V_30 = F_152 ( V_194 , log -> V_28 ) ;
V_195 = V_30 -> V_199 << V_40 ;
V_196 = V_195 + ( V_30 -> V_29 << V_40 ) ;
F_153 ( L_27 , V_16 , V_195 ,
V_196 ) ;
V_186 = F_154 ( V_30 ) ;
memset ( V_30 -> V_200 , 0 , V_186 ) ;
}
V_79 = 0 ;
V_52:
F_28 ( & V_9 -> V_198 ) ;
return V_79 ;
}
long F_155 ( struct V_23 * V_24 , unsigned int V_25 , unsigned long V_12 )
{
long V_79 ;
switch ( V_25 ) {
default:
V_79 = - V_26 ;
}
return V_79 ;
}
int F_156 ( void * V_201 )
{
if ( V_13 ) {
F_38 ( L_28 ) ;
return - V_202 ;
}
return F_157 ( & V_13 ) ;
}
void F_158 ( void )
{
V_13 = NULL ;
}
int F_159 ( struct V_1 * V_2 ,
struct V_203 * V_204 )
{
return - V_26 ;
}
int F_160 ( struct V_1 * V_2 ,
struct V_203 * V_204 )
{
return - V_26 ;
}
void F_161 ( struct V_1 * V_2 )
{
}
int F_162 ( struct V_1 * V_2 , struct V_205 * V_114 )
{
return - V_26 ;
}
int F_163 ( struct V_1 * V_2 , struct V_205 * V_114 )
{
return - V_26 ;
}
int F_164 ( struct V_1 * V_2 , struct V_206 * V_207 )
{
return V_208 ;
}
int F_148 ( struct V_9 * V_9 , long V_209 )
{
int V_79 ;
switch ( V_209 ) {
case V_210 :
case V_211 :
V_79 = 1 ;
break;
case V_212 :
V_79 = V_213 ;
break;
case V_174 :
V_79 = ! ! V_214 ;
break;
case V_176 :
V_79 = V_215 && ! ( V_100 . V_133 & V_216 ) ;
break;
default:
V_79 = 0 ;
break;
}
return V_79 ;
}
int F_165 ( struct V_1 * V_2 )
{
return F_166 ( V_2 ) ;
}
int F_167 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_68 * V_69 ;
if ( ! V_2 )
return - 1 ;
F_12 ( L_29 ) ;
F_12 ( L_30 , V_2 -> V_4 . V_126 ) ;
F_12 ( L_31 , V_2 -> V_4 . V_7 ) ;
for ( V_3 = 0 ; V_3 < 32 ; V_3 += 4 ) {
F_12 ( L_32 , V_3 ,
V_2 -> V_4 . V_120 [ V_3 ] ,
V_2 -> V_4 . V_120 [ V_3 + 1 ] ,
V_2 -> V_4 . V_120 [ V_3 + 2 ] , V_2 -> V_4 . V_120 [ V_3 + 3 ] ) ;
}
F_12 ( L_33 , V_2 -> V_4 . V_122 ) ;
F_12 ( L_34 , V_2 -> V_4 . V_124 ) ;
V_69 = V_2 -> V_4 . V_69 ;
F_12 ( L_35 ,
F_94 ( V_69 ) ,
F_67 ( V_69 ) ) ;
F_12 ( L_36 , F_107 ( V_69 ) ) ;
return 0 ;
}
int F_168 ( struct V_1 * V_2 , struct V_217 * V_218 )
{
int V_3 ;
for ( V_3 = 1 ; V_3 < F_81 ( V_2 -> V_4 . V_120 ) ; V_3 ++ )
V_2 -> V_4 . V_120 [ V_3 ] = V_218 -> V_219 [ V_3 ] ;
V_2 -> V_4 . V_120 [ 0 ] = 0 ;
V_2 -> V_4 . V_122 = V_218 -> V_122 ;
V_2 -> V_4 . V_124 = V_218 -> V_124 ;
V_2 -> V_4 . V_126 = V_218 -> V_126 ;
return 0 ;
}
int F_169 ( struct V_1 * V_2 , struct V_217 * V_218 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_81 ( V_2 -> V_4 . V_120 ) ; V_3 ++ )
V_218 -> V_219 [ V_3 ] = V_2 -> V_4 . V_120 [ V_3 ] ;
V_218 -> V_122 = V_2 -> V_4 . V_122 ;
V_218 -> V_124 = V_2 -> V_4 . V_124 ;
V_218 -> V_126 = V_2 -> V_4 . V_126 ;
return 0 ;
}
static void F_170 ( unsigned long V_220 )
{
struct V_1 * V_2 = (struct V_1 * ) V_220 ;
V_13 -> V_221 ( V_2 ) ;
V_2 -> V_4 . V_93 = 0 ;
if ( F_76 ( & V_2 -> V_94 ) )
F_77 ( & V_2 -> V_94 ) ;
}
static enum V_222 F_171 ( struct V_223 * V_224 )
{
struct V_1 * V_2 ;
V_2 = F_172 ( V_224 , struct V_1 , V_4 . V_65 ) ;
F_170 ( ( unsigned long ) V_2 ) ;
return F_173 ( V_2 ) ;
}
int F_174 ( struct V_1 * V_2 )
{
V_13 -> V_225 ( V_2 ) ;
F_175 ( & V_2 -> V_4 . V_65 , V_226 ,
V_227 ) ;
V_2 -> V_4 . V_65 . V_228 = F_171 ;
return 0 ;
}
int F_176 ( struct V_1 * V_2 ,
struct V_229 * V_230 )
{
return 0 ;
}
int F_177 ( struct V_1 * V_2 )
{
return V_13 -> V_231 ( V_2 ) ;
}
static void F_178 ( void )
{
T_1 V_232 = F_179 () ;
if ( V_233 )
V_232 |= ( V_234 ) ;
F_180 ( V_232 ) ;
F_181 () ;
}
int F_182 ( struct V_77 * V_78 , struct V_1 * V_2 )
{
T_1 V_235 = V_2 -> V_4 . V_236 ;
T_1 V_237 = ( V_235 >> V_238 ) & 0x1f ;
T_1 T_4 * V_239 = ( T_1 T_4 * ) V_2 -> V_4 . V_126 ;
unsigned long V_240 = V_2 -> V_4 . V_241 ;
enum V_242 V_243 = V_244 ;
int V_97 = V_245 ;
F_72 () ;
V_78 -> V_246 = V_247 ;
V_78 -> V_248 = 1 ;
F_178 () ;
F_74 () ;
F_12 ( L_37 ,
V_235 , V_239 , V_78 , V_2 ) ;
F_183 ( V_2 , V_237 ) ;
V_243 = F_184 ( V_235 , V_239 , V_78 , V_2 ) ;
if ( V_243 == V_249 ) {
goto V_250;
} else if ( V_243 == V_251 ) {
V_78 -> V_246 = V_252 ;
V_97 = V_253 ;
goto V_250;
}
switch ( V_237 ) {
case V_254 :
F_12 ( L_38 , V_2 -> V_190 , V_239 ) ;
++ V_2 -> V_255 . V_256 ;
if ( F_185 () )
F_186 () ;
V_97 = V_245 ;
break;
case V_257 :
F_12 ( L_39 , V_239 ) ;
++ V_2 -> V_255 . V_258 ;
V_97 = V_13 -> V_259 ( V_2 ) ;
if ( V_78 -> V_246 == V_260 )
V_97 = V_253 ;
break;
case V_261 :
++ V_2 -> V_255 . V_262 ;
V_97 = V_13 -> V_263 ( V_2 ) ;
break;
case V_264 :
F_12 ( L_40 ,
V_235 , F_94 ( V_2 -> V_4 . V_69 ) , V_239 ,
V_240 ) ;
++ V_2 -> V_255 . V_265 ;
V_97 = V_13 -> V_266 ( V_2 ) ;
break;
case V_267 :
F_12 ( L_41 ,
V_235 , V_239 , V_240 ) ;
++ V_2 -> V_255 . V_268 ;
V_97 = V_13 -> V_269 ( V_2 ) ;
break;
case V_270 :
++ V_2 -> V_255 . V_271 ;
V_97 = V_13 -> V_272 ( V_2 ) ;
break;
case V_273 :
++ V_2 -> V_255 . V_274 ;
V_97 = V_13 -> V_275 ( V_2 ) ;
break;
case V_276 :
++ V_2 -> V_255 . V_277 ;
V_97 = V_13 -> V_278 ( V_2 ) ;
break;
case V_279 :
++ V_2 -> V_255 . V_280 ;
V_97 = V_13 -> V_281 ( V_2 ) ;
break;
case V_282 :
++ V_2 -> V_255 . V_283 ;
V_97 = V_13 -> V_284 ( V_2 ) ;
break;
case V_285 :
++ V_2 -> V_255 . V_286 ;
V_97 = V_13 -> V_287 ( V_2 ) ;
break;
case V_288 :
++ V_2 -> V_255 . V_289 ;
V_97 = V_13 -> V_290 ( V_2 ) ;
break;
case V_291 :
++ V_2 -> V_255 . V_292 ;
V_97 = V_13 -> V_293 ( V_2 ) ;
break;
case V_294 :
++ V_2 -> V_255 . V_295 ;
V_97 = V_13 -> V_296 ( V_2 ) ;
break;
default:
F_38 ( L_42 ,
V_237 , V_239 , F_187 ( V_239 , V_2 ) , V_240 ,
F_94 ( V_2 -> V_4 . V_69 ) ) ;
F_167 ( V_2 ) ;
V_78 -> V_246 = V_252 ;
V_97 = V_253 ;
break;
}
V_250:
F_65 () ;
if ( V_243 == V_244 && ! ( V_97 & V_253 ) )
F_66 ( V_2 , V_235 ) ;
if ( ! ( V_97 & V_253 ) ) {
if ( F_188 ( V_297 ) ) {
V_78 -> V_246 = V_298 ;
V_97 = ( - V_299 << 2 ) | V_253 ;
++ V_2 -> V_255 . V_300 ;
F_183 ( V_2 , V_301 ) ;
}
}
if ( V_97 == V_245 ) {
F_189 ( V_2 ) ;
F_57 ( V_2 ) ;
if ( F_93 ( & V_2 -> V_4 ) &&
F_179 () & V_302 )
F_190 ( & V_2 -> V_4 ) ;
if ( F_97 ( & V_2 -> V_4 ) &&
F_191 () & V_303 )
F_192 ( & V_2 -> V_4 ) ;
}
F_69 () ;
return V_97 ;
}
void F_193 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = V_2 -> V_4 . V_69 ;
unsigned int V_304 , V_305 ;
F_194 () ;
V_304 = F_94 ( V_69 ) ;
if ( V_215 && V_304 & V_302 && ! ( V_304 & V_127 ) &&
V_2 -> V_4 . V_306 & V_307 )
F_195 ( V_2 ) ;
F_196 ( V_302 | V_127 , V_304 ) ;
if ( V_308 ) {
V_305 = F_114 ( V_69 ) ;
F_197 ( V_309 , V_305 ) ;
}
F_198 () ;
if ( ! ( V_2 -> V_4 . V_306 & V_310 ) ) {
F_199 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_306 |= V_310 ;
F_200 ( V_2 , V_311 , V_312 ) ;
} else {
F_200 ( V_2 , V_313 , V_312 ) ;
}
F_201 () ;
}
void F_202 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = V_2 -> V_4 . V_69 ;
unsigned int V_304 , V_305 ;
F_194 () ;
if ( F_93 ( & V_2 -> V_4 ) ) {
V_304 = F_94 ( V_69 ) ;
if ( ! ( V_304 & V_127 ) &&
( V_2 -> V_4 . V_306 & ( V_310 |
V_307 ) ) == V_310 )
F_195 ( V_2 ) ;
F_196 ( V_302 | V_127 , V_304 ) ;
if ( V_304 & V_302 && V_308 ) {
V_305 = F_114 ( V_69 ) ;
F_197 ( V_309 , V_305 ) ;
}
}
F_203 ( V_303 ) ;
F_198 () ;
switch ( V_2 -> V_4 . V_306 & ( V_310 | V_307 ) ) {
case V_310 :
F_204 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_306 |= V_307 ;
F_200 ( V_2 , V_311 , V_314 ) ;
break;
case 0 :
F_205 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_306 |= V_307 ;
if ( F_93 ( & V_2 -> V_4 ) )
V_2 -> V_4 . V_306 |= V_310 ;
F_200 ( V_2 , V_311 ,
V_315 ) ;
break;
default:
F_200 ( V_2 , V_313 , V_314 ) ;
break;
}
F_201 () ;
}
void F_206 ( struct V_1 * V_2 )
{
F_194 () ;
if ( V_215 && V_2 -> V_4 . V_306 & V_307 ) {
F_207 () ;
F_200 ( V_2 , V_316 , V_314 ) ;
V_2 -> V_4 . V_306 &= ~ V_307 ;
}
if ( V_2 -> V_4 . V_306 & V_310 ) {
F_208 ( V_302 | V_127 ) ;
F_200 ( V_2 , V_316 , V_312 ) ;
V_2 -> V_4 . V_306 &= ~ V_310 ;
}
F_201 () ;
}
void F_195 ( struct V_1 * V_2 )
{
F_194 () ;
if ( V_215 && V_2 -> V_4 . V_306 & V_307 ) {
F_203 ( V_303 ) ;
F_198 () ;
F_209 ( & V_2 -> V_4 ) ;
F_200 ( V_2 , V_317 , V_315 ) ;
F_207 () ;
if ( V_2 -> V_4 . V_306 & V_310 ) {
F_208 ( V_302 | V_127 ) ;
F_210 () ;
}
V_2 -> V_4 . V_306 &= ~ ( V_310 | V_307 ) ;
} else if ( V_2 -> V_4 . V_306 & V_310 ) {
F_211 ( V_302 ) ;
F_198 () ;
F_212 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_306 &= ~ V_310 ;
F_200 ( V_2 , V_317 , V_312 ) ;
F_208 ( V_302 | V_127 ) ;
F_210 () ;
}
F_201 () ;
}
static int F_213 ( struct V_318 * V_319 ,
unsigned long V_320 , void * V_321 )
{
struct V_322 * args = (struct V_322 * ) V_321 ;
struct V_323 * V_218 = args -> V_218 ;
unsigned long V_126 ;
if ( V_320 != V_324 && V_320 != V_325 )
return V_326 ;
if ( ! ( V_297 -> V_173 & V_327 ) )
return V_326 ;
F_214 ( F_215 ( V_218 ) ) ;
V_126 = F_216 ( V_218 ) ;
switch ( V_320 ) {
case V_324 :
if ( V_126 != ( unsigned long ) & F_190 + 4 )
return V_326 ;
break;
case V_325 :
if ( ! V_215 ||
V_126 < ( unsigned long ) & F_192 + 4 ||
V_126 > ( unsigned long ) & F_192 + 8 )
return V_326 ;
break;
}
F_216 ( V_218 ) += 4 ;
return V_328 ;
}
static int T_7 F_217 ( void )
{
int V_97 ;
V_97 = F_218 () ;
if ( V_97 )
return V_97 ;
V_97 = F_219 ( NULL , sizeof( struct V_1 ) , 0 , V_329 ) ;
if ( V_97 )
return V_97 ;
F_220 ( & V_330 ) ;
return 0 ;
}
static void T_8 F_221 ( void )
{
F_222 () ;
F_223 ( & V_330 ) ;
}
