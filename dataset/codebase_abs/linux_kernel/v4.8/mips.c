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
static inline void F_37 ( const char * V_42 , void * V_43 , void * V_44 )
{
T_1 * V_45 ;
F_38 ( L_7 , V_42 ) ;
F_38 ( L_8 ) ;
F_38 ( L_9 ) ;
for ( V_45 = V_43 ; V_45 < ( T_1 * ) V_44 ; ++ V_45 )
F_38 ( L_10 , * V_45 , V_45 ) ;
F_38 ( L_11 ) ;
F_38 ( L_12 , V_42 ) ;
}
struct V_1 * F_39 ( struct V_9 * V_9 , unsigned int V_46 )
{
int V_47 , V_48 ;
void * V_49 , * V_45 , * V_50 ;
int V_3 ;
struct V_1 * V_2 = F_35 ( sizeof( struct V_1 ) , V_41 ) ;
if ( ! V_2 ) {
V_47 = - V_51 ;
goto V_52;
}
V_47 = F_40 ( V_2 , V_9 , V_46 ) ;
if ( V_47 )
goto V_53;
F_12 ( L_13 , V_9 , V_46 , V_2 ) ;
if ( V_54 || V_55 )
V_48 = 0x200 + V_56 * 64 ;
else
V_48 = 0x4000 ;
V_49 = F_35 ( F_41 ( V_48 , V_57 ) , V_41 ) ;
if ( ! V_49 ) {
V_47 = - V_51 ;
goto V_58;
}
F_12 ( L_14 ,
F_41 ( V_48 , V_57 ) , V_49 ) ;
if ( ! V_59 && F_42 ( V_49 ) >= 0x20000000 ) {
F_36 ( L_15 ,
V_49 ) ;
V_47 = - V_51 ;
goto V_60;
}
V_2 -> V_4 . V_61 = V_49 ;
V_50 = V_49 + 0x2000 ;
F_43 ( V_49 , V_50 ) ;
F_43 ( V_49 + 0x180 , V_50 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
F_12 ( L_16 ,
V_49 + 0x200 + ( V_3 * V_56 ) ) ;
F_43 ( V_49 + 0x200 + V_3 * V_56 ,
V_50 ) ;
}
V_45 = V_50 ;
V_45 = F_44 ( V_45 ) ;
V_2 -> V_4 . V_62 = V_45 ;
V_45 = F_45 ( V_45 ) ;
F_38 ( L_17 ) ;
F_38 ( L_18 ) ;
F_38 ( L_19 ) ;
F_37 ( L_20 , V_2 -> V_4 . V_62 , V_45 ) ;
F_37 ( L_21 , V_49 + 0x180 , V_49 + 0x200 ) ;
F_37 ( L_22 , V_49 + 0x2000 , V_2 -> V_4 . V_62 ) ;
F_46 ( ( unsigned long ) V_49 ,
( unsigned long ) V_49 + F_41 ( V_48 , V_57 ) ) ;
V_2 -> V_4 . V_63 = F_35 ( V_57 << 1 , V_41 ) ;
if ( ! V_2 -> V_4 . V_63 ) {
V_47 = - V_51 ;
goto V_60;
}
F_12 ( L_23 , V_2 -> V_4 . V_63 ) ;
F_47 ( V_2 ) ;
V_2 -> V_4 . V_64 = - 1 ;
F_48 ( V_2 ) ;
return V_2 ;
V_60:
F_20 ( V_49 ) ;
V_58:
F_49 ( V_2 ) ;
V_53:
F_20 ( V_2 ) ;
V_52:
return F_50 ( V_47 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_4 . V_65 ) ;
F_49 ( V_2 ) ;
F_52 ( V_2 ) ;
F_20 ( V_2 -> V_4 . V_61 ) ;
F_20 ( V_2 -> V_4 . V_63 ) ;
F_20 ( V_2 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
}
int F_54 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
return - V_26 ;
}
int F_55 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
int V_70 = 0 ;
T_2 V_71 ;
if ( V_2 -> V_72 )
F_56 ( V_73 , & V_2 -> V_74 , & V_71 ) ;
if ( V_2 -> V_75 ) {
if ( ! V_2 -> V_76 )
F_57 ( V_2 , V_69 ) ;
V_2 -> V_75 = 0 ;
}
F_58 ( 1 ) ;
F_59 () ;
F_60 ( V_2 ,
F_61 ( V_2 -> V_4 . V_77 ) ) ;
F_62 () ;
F_63 () ;
F_64 ( V_2 ) ;
V_70 = V_2 -> V_4 . V_62 ( V_69 , V_2 ) ;
F_65 ( V_2 ) ;
F_66 () ;
F_67 () ;
F_68 () ;
if ( V_2 -> V_72 )
F_56 ( V_73 , & V_71 , NULL ) ;
return V_70 ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
int V_80 = ( int ) V_79 -> V_79 ;
struct V_1 * V_81 = NULL ;
if ( V_80 == 3 || V_80 == - 3 || V_80 == 4 || V_80 == - 4 )
F_12 ( L_24 , V_16 , V_79 -> V_82 ,
( int ) V_80 ) ;
if ( V_79 -> V_82 == - 1 )
V_81 = V_2 ;
else
V_81 = V_2 -> V_9 -> V_22 [ V_79 -> V_82 ] ;
if ( V_80 == 2 || V_80 == 3 || V_80 == 4 ) {
V_13 -> V_83 ( V_81 , V_79 ) ;
} else if ( V_80 == - 2 || V_80 == - 3 || V_80 == - 4 ) {
V_13 -> V_84 ( V_81 , V_79 ) ;
} else {
F_36 ( L_25 , V_16 ,
V_79 -> V_82 , V_79 -> V_79 ) ;
return - V_85 ;
}
V_81 -> V_4 . V_86 = 0 ;
if ( F_70 ( & V_81 -> V_87 ) )
F_71 ( & V_81 -> V_87 ) ;
return 0 ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
return - V_26 ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
return - V_26 ;
}
static unsigned long F_74 ( struct V_1 * V_2 )
{
unsigned long V_90 ;
V_90 = F_75 ( V_91 ) ;
if ( F_76 ( & V_2 -> V_4 ) ) {
V_90 += F_75 ( V_92 ) + 48 ;
if ( V_93 . V_94 & V_95 )
V_90 += 16 ;
}
if ( F_77 ( & V_2 -> V_4 ) )
V_90 += F_75 ( V_96 ) + 32 ;
V_90 += F_78 ( V_2 -> V_4 . V_97 ) ;
V_90 += V_13 -> V_98 ( V_2 ) ;
return V_90 ;
}
static int F_79 ( struct V_1 * V_2 , T_3 T_4 * V_99 )
{
T_3 V_100 ;
unsigned int V_3 ;
if ( F_80 ( V_99 , V_91 ,
sizeof( V_91 ) ) )
return - V_101 ;
V_99 += F_75 ( V_91 ) ;
if ( F_76 ( & V_2 -> V_4 ) ) {
if ( F_80 ( V_99 , V_92 ,
sizeof( V_92 ) ) )
return - V_101 ;
V_99 += F_75 ( V_92 ) ;
for ( V_3 = 0 ; V_3 < 32 ; ++ V_3 ) {
V_100 = F_81 ( V_3 ) ;
if ( F_80 ( V_99 , & V_100 , sizeof( V_100 ) ) )
return - V_101 ;
++ V_99 ;
if ( V_3 & 1 && ! ( V_93 . V_94 & V_95 ) )
continue;
V_100 = F_82 ( V_3 ) ;
if ( F_80 ( V_99 , & V_100 , sizeof( V_100 ) ) )
return - V_101 ;
++ V_99 ;
}
}
if ( F_77 ( & V_2 -> V_4 ) ) {
if ( F_80 ( V_99 , V_96 ,
sizeof( V_96 ) ) )
return - V_101 ;
V_99 += F_75 ( V_96 ) ;
for ( V_3 = 0 ; V_3 < 32 ; ++ V_3 ) {
V_100 = F_83 ( V_3 ) ;
if ( F_80 ( V_99 , & V_100 , sizeof( V_100 ) ) )
return - V_101 ;
++ V_99 ;
}
}
for ( V_3 = 0 ; V_3 < 6 ; ++ V_3 ) {
if ( ! ( V_2 -> V_4 . V_97 & F_84 ( V_3 + 2 ) ) )
continue;
if ( F_80 ( V_99 , & V_102 [ V_3 ] ,
sizeof( V_102 [ V_3 ] ) ) )
return - V_101 ;
++ V_99 ;
}
return V_13 -> V_103 ( V_2 , V_99 ) ;
}
static int F_85 ( struct V_1 * V_2 ,
const struct V_104 * V_105 )
{
struct V_106 * V_77 = V_2 -> V_4 . V_77 ;
struct V_107 * V_108 = & V_2 -> V_4 . V_108 ;
int V_90 ;
T_5 V_109 ;
T_5 V_110 [ 2 ] ;
unsigned int V_111 ;
switch ( V_105 -> V_46 ) {
case V_112 ... V_113 :
V_109 = ( long ) V_2 -> V_4 . V_114 [ V_105 -> V_46 - V_112 ] ;
break;
#ifndef F_86
case V_115 :
V_109 = ( long ) V_2 -> V_4 . V_116 ;
break;
case V_117 :
V_109 = ( long ) V_2 -> V_4 . V_118 ;
break;
#endif
case V_119 :
V_109 = ( long ) V_2 -> V_4 . V_120 ;
break;
case F_81 ( 0 ) ... F_81 ( 31 ) :
if ( ! F_87 ( & V_2 -> V_4 ) )
return - V_85 ;
V_111 = V_105 -> V_46 - F_81 ( 0 ) ;
if ( F_88 ( V_77 ) & V_121 )
V_109 = F_89 ( & V_108 -> V_122 [ V_111 ] , 0 ) ;
else
V_109 = F_89 ( & V_108 -> V_122 [ V_111 & ~ 1 ] , V_111 & 1 ) ;
break;
case F_82 ( 0 ) ... F_82 ( 31 ) :
if ( ! F_87 ( & V_2 -> V_4 ) )
return - V_85 ;
V_111 = V_105 -> V_46 - F_82 ( 0 ) ;
if ( V_111 & 1 && ! ( F_88 ( V_77 ) & V_121 ) )
return - V_85 ;
V_109 = F_90 ( & V_108 -> V_122 [ V_111 ] , 0 ) ;
break;
case V_123 :
if ( ! F_87 ( & V_2 -> V_4 ) )
return - V_85 ;
V_109 = V_93 . V_94 ;
break;
case V_124 :
if ( ! F_87 ( & V_2 -> V_4 ) )
return - V_85 ;
V_109 = V_108 -> V_125 ;
break;
case F_83 ( 0 ) ... F_83 ( 31 ) :
if ( ! F_91 ( & V_2 -> V_4 ) )
return - V_85 ;
if ( ! ( F_88 ( V_77 ) & V_121 ) )
return - V_85 ;
V_111 = V_105 -> V_46 - F_83 ( 0 ) ;
#ifdef F_92
V_110 [ 0 ] = F_90 ( & V_108 -> V_122 [ V_111 ] , 0 ) ;
V_110 [ 1 ] = F_90 ( & V_108 -> V_122 [ V_111 ] , 1 ) ;
#else
V_110 [ 0 ] = F_90 ( & V_108 -> V_122 [ V_111 ] , 1 ) ;
V_110 [ 1 ] = F_90 ( & V_108 -> V_122 [ V_111 ] , 0 ) ;
#endif
break;
case V_126 :
if ( ! F_91 ( & V_2 -> V_4 ) )
return - V_85 ;
V_109 = V_93 . V_127 ;
break;
case V_128 :
if ( ! F_91 ( & V_2 -> V_4 ) )
return - V_85 ;
V_109 = V_108 -> V_129 ;
break;
case V_130 :
V_109 = ( long ) F_93 ( V_77 ) ;
break;
case V_131 :
V_109 = ( long ) F_94 ( V_77 ) ;
break;
case V_132 :
V_109 = ( long ) F_95 ( V_77 ) ;
break;
case V_133 :
V_109 = ( long ) F_96 ( V_77 ) ;
break;
case V_134 :
V_109 = ( long ) F_97 ( V_77 ) ;
break;
case V_135 :
V_109 = ( long ) F_98 ( V_77 ) ;
break;
case V_136 :
V_109 = ( long ) F_99 ( V_77 ) ;
break;
case V_137 :
V_109 = ( long ) F_100 ( V_77 ) ;
break;
case V_138 :
V_109 = ( long ) F_101 ( V_77 ) ;
break;
case V_139 :
V_109 = ( long ) F_88 ( V_77 ) ;
break;
case V_140 :
V_109 = ( long ) F_61 ( V_77 ) ;
break;
case V_141 :
V_109 = ( long ) F_102 ( V_77 ) ;
break;
case V_142 :
V_109 = ( long ) F_103 ( V_77 ) ;
break;
case V_143 :
V_109 = ( long ) F_104 ( V_77 ) ;
break;
case V_144 :
V_109 = ( long ) F_105 ( V_77 ) ;
break;
case V_145 :
V_109 = ( long ) F_106 ( V_77 ) ;
break;
case V_146 :
V_109 = ( long ) F_107 ( V_77 ) ;
break;
case V_147 :
V_109 = ( long ) F_108 ( V_77 ) ;
break;
case V_148 :
V_109 = ( long ) F_109 ( V_77 ) ;
break;
case V_149 :
V_109 = ( long ) F_110 ( V_77 ) ;
break;
case V_150 :
V_109 = ( long ) F_111 ( V_77 ) ;
break;
case V_151 ... V_152 :
V_111 = V_105 -> V_46 - V_151 + 2 ;
if ( ! ( V_2 -> V_4 . V_97 & F_84 ( V_111 ) ) )
return - V_85 ;
switch ( V_111 ) {
case 2 :
V_109 = ( long ) F_112 ( V_77 ) ;
break;
case 3 :
V_109 = ( long ) F_113 ( V_77 ) ;
break;
case 4 :
V_109 = ( long ) F_114 ( V_77 ) ;
break;
case 5 :
V_109 = ( long ) F_115 ( V_77 ) ;
break;
case 6 :
V_109 = ( long ) F_116 ( V_77 ) ;
break;
case 7 :
V_109 = ( long ) F_117 ( V_77 ) ;
break;
}
break;
default:
V_90 = V_13 -> V_153 ( V_2 , V_105 , & V_109 ) ;
if ( V_90 )
return V_90 ;
break;
}
if ( ( V_105 -> V_46 & V_154 ) == V_155 ) {
T_3 T_4 * V_156 = ( T_3 T_4 * ) ( long ) V_105 -> V_157 ;
return F_118 ( V_109 , V_156 ) ;
} else if ( ( V_105 -> V_46 & V_154 ) == V_158 ) {
T_1 T_4 * V_159 = ( T_1 T_4 * ) ( long ) V_105 -> V_157 ;
T_1 V_160 = ( T_1 ) V_109 ;
return F_118 ( V_160 , V_159 ) ;
} else if ( ( V_105 -> V_46 & V_154 ) == V_161 ) {
void T_4 * V_162 = ( void T_4 * ) ( long ) V_105 -> V_157 ;
return F_80 ( V_162 , V_110 , 16 ) ? - V_101 : 0 ;
} else {
return - V_85 ;
}
}
static int F_119 ( struct V_1 * V_2 ,
const struct V_104 * V_105 )
{
struct V_106 * V_77 = V_2 -> V_4 . V_77 ;
struct V_107 * V_108 = & V_2 -> V_4 . V_108 ;
T_5 V_109 ;
T_5 V_110 [ 2 ] ;
unsigned int V_111 ;
if ( ( V_105 -> V_46 & V_154 ) == V_155 ) {
T_3 T_4 * V_156 = ( T_3 T_4 * ) ( long ) V_105 -> V_157 ;
if ( F_120 ( V_109 , V_156 ) != 0 )
return - V_101 ;
} else if ( ( V_105 -> V_46 & V_154 ) == V_158 ) {
T_1 T_4 * V_159 = ( T_1 T_4 * ) ( long ) V_105 -> V_157 ;
T_6 V_160 ;
if ( F_120 ( V_160 , V_159 ) != 0 )
return - V_101 ;
V_109 = ( T_5 ) V_160 ;
} else if ( ( V_105 -> V_46 & V_154 ) == V_161 ) {
void T_4 * V_162 = ( void T_4 * ) ( long ) V_105 -> V_157 ;
return F_121 ( V_110 , V_162 , 16 ) ? - V_101 : 0 ;
} else {
return - V_85 ;
}
switch ( V_105 -> V_46 ) {
case V_112 :
break;
case V_163 ... V_113 :
V_2 -> V_4 . V_114 [ V_105 -> V_46 - V_112 ] = V_109 ;
break;
#ifndef F_86
case V_115 :
V_2 -> V_4 . V_116 = V_109 ;
break;
case V_117 :
V_2 -> V_4 . V_118 = V_109 ;
break;
#endif
case V_119 :
V_2 -> V_4 . V_120 = V_109 ;
break;
case F_81 ( 0 ) ... F_81 ( 31 ) :
if ( ! F_87 ( & V_2 -> V_4 ) )
return - V_85 ;
V_111 = V_105 -> V_46 - F_81 ( 0 ) ;
if ( F_88 ( V_77 ) & V_121 )
F_122 ( & V_108 -> V_122 [ V_111 ] , 0 , V_109 ) ;
else
F_122 ( & V_108 -> V_122 [ V_111 & ~ 1 ] , V_111 & 1 , V_109 ) ;
break;
case F_82 ( 0 ) ... F_82 ( 31 ) :
if ( ! F_87 ( & V_2 -> V_4 ) )
return - V_85 ;
V_111 = V_105 -> V_46 - F_82 ( 0 ) ;
if ( V_111 & 1 && ! ( F_88 ( V_77 ) & V_121 ) )
return - V_85 ;
F_123 ( & V_108 -> V_122 [ V_111 ] , 0 , V_109 ) ;
break;
case V_123 :
if ( ! F_87 ( & V_2 -> V_4 ) )
return - V_85 ;
break;
case V_124 :
if ( ! F_87 ( & V_2 -> V_4 ) )
return - V_85 ;
V_108 -> V_125 = V_109 ;
break;
case F_83 ( 0 ) ... F_83 ( 31 ) :
if ( ! F_91 ( & V_2 -> V_4 ) )
return - V_85 ;
V_111 = V_105 -> V_46 - F_83 ( 0 ) ;
#ifdef F_92
F_123 ( & V_108 -> V_122 [ V_111 ] , 0 , V_110 [ 0 ] ) ;
F_123 ( & V_108 -> V_122 [ V_111 ] , 1 , V_110 [ 1 ] ) ;
#else
F_123 ( & V_108 -> V_122 [ V_111 ] , 1 , V_110 [ 0 ] ) ;
F_123 ( & V_108 -> V_122 [ V_111 ] , 0 , V_110 [ 1 ] ) ;
#endif
break;
case V_126 :
if ( ! F_91 ( & V_2 -> V_4 ) )
return - V_85 ;
break;
case V_128 :
if ( ! F_91 ( & V_2 -> V_4 ) )
return - V_85 ;
V_108 -> V_129 = V_109 ;
break;
case V_130 :
F_124 ( V_77 , V_109 ) ;
break;
case V_131 :
F_125 ( V_77 , V_109 ) ;
break;
case V_132 :
F_126 ( V_77 , V_109 ) ;
break;
case V_133 :
F_127 ( V_77 , V_109 ) ;
break;
case V_134 :
F_128 ( V_77 , V_109 ) ;
break;
case V_135 :
F_129 ( V_77 , V_109 ) ;
break;
case V_136 :
F_130 ( V_77 , V_109 ) ;
break;
case V_137 :
F_131 ( V_77 , V_109 ) ;
break;
case V_139 :
F_132 ( V_77 , V_109 ) ;
break;
case V_141 :
F_133 ( V_77 , V_109 ) ;
break;
case V_142 :
F_134 ( V_77 , V_109 ) ;
break;
case V_150 :
F_135 ( V_77 , V_109 ) ;
break;
case V_151 ... V_152 :
V_111 = V_105 -> V_46 - V_151 + 2 ;
if ( ! ( V_2 -> V_4 . V_97 & F_84 ( V_111 ) ) )
return - V_85 ;
switch ( V_111 ) {
case 2 :
F_136 ( V_77 , V_109 ) ;
break;
case 3 :
F_137 ( V_77 , V_109 ) ;
break;
case 4 :
F_138 ( V_77 , V_109 ) ;
break;
case 5 :
F_139 ( V_77 , V_109 ) ;
break;
case 6 :
F_140 ( V_77 , V_109 ) ;
break;
case 7 :
F_141 ( V_77 , V_109 ) ;
break;
}
break;
default:
return V_13 -> V_164 ( V_2 , V_105 , V_109 ) ;
}
return 0 ;
}
static int F_142 ( struct V_1 * V_2 ,
struct V_165 * V_166 )
{
int V_70 = 0 ;
if ( ! F_143 ( V_2 -> V_9 , V_166 -> V_166 ) )
return - V_85 ;
if ( V_166 -> V_167 )
return - V_85 ;
if ( V_166 -> args [ 0 ] )
return - V_85 ;
switch ( V_166 -> V_166 ) {
case V_168 :
V_2 -> V_4 . V_169 = true ;
break;
case V_170 :
V_2 -> V_4 . V_171 = true ;
break;
default:
V_70 = - V_85 ;
break;
}
return V_70 ;
}
long F_144 ( struct V_23 * V_24 , unsigned int V_25 ,
unsigned long V_12 )
{
struct V_1 * V_2 = V_24 -> V_172 ;
void T_4 * V_173 = ( void T_4 * ) V_12 ;
long V_70 ;
switch ( V_25 ) {
case V_174 :
case V_175 : {
struct V_104 V_105 ;
if ( F_121 ( & V_105 , V_173 , sizeof( V_105 ) ) )
return - V_101 ;
if ( V_25 == V_174 )
return F_119 ( V_2 , & V_105 ) ;
else
return F_85 ( V_2 , & V_105 ) ;
}
case V_176 : {
struct V_177 T_4 * V_178 = V_173 ;
struct V_177 V_179 ;
unsigned V_180 ;
if ( F_121 ( & V_179 , V_178 , sizeof( V_179 ) ) )
return - V_101 ;
V_180 = V_179 . V_180 ;
V_179 . V_180 = F_74 ( V_2 ) ;
if ( F_80 ( V_178 , & V_179 , sizeof( V_179 ) ) )
return - V_101 ;
if ( V_180 < V_179 . V_180 )
return - V_181 ;
return F_79 ( V_2 , V_178 -> V_105 ) ;
}
case V_182 :
V_70 = F_1 ( V_2 ) ;
break;
case V_183 :
{
struct V_78 V_79 ;
V_70 = - V_101 ;
if ( F_121 ( & V_79 , V_173 , sizeof( V_79 ) ) )
goto V_52;
F_12 ( L_26 , V_2 -> V_184 , V_16 ,
V_79 . V_79 ) ;
V_70 = F_69 ( V_2 , & V_79 ) ;
break;
}
case V_185 : {
struct V_165 V_166 ;
V_70 = - V_101 ;
if ( F_121 ( & V_166 , V_173 , sizeof( V_166 ) ) )
goto V_52;
V_70 = F_142 ( V_2 , & V_166 ) ;
break;
}
default:
V_70 = - V_26 ;
}
V_52:
return V_70 ;
}
int F_145 ( struct V_9 * V_9 , struct V_186 * log )
{
struct V_187 * V_188 ;
struct V_27 * V_30 ;
unsigned long V_189 , V_190 ;
int V_191 = 0 ;
int V_70 ;
unsigned long V_180 ;
F_23 ( & V_9 -> V_192 ) ;
V_70 = F_146 ( V_9 , log , & V_191 ) ;
if ( V_70 )
goto V_52;
if ( V_191 ) {
V_188 = V_187 ( V_9 ) ;
V_30 = F_147 ( V_188 , log -> V_28 ) ;
V_189 = V_30 -> V_193 << V_40 ;
V_190 = V_189 + ( V_30 -> V_29 << V_40 ) ;
F_148 ( L_27 , V_16 , V_189 ,
V_190 ) ;
V_180 = F_149 ( V_30 ) ;
memset ( V_30 -> V_194 , 0 , V_180 ) ;
}
V_70 = 0 ;
V_52:
F_26 ( & V_9 -> V_192 ) ;
return V_70 ;
}
long F_150 ( struct V_23 * V_24 , unsigned int V_25 , unsigned long V_12 )
{
long V_70 ;
switch ( V_25 ) {
default:
V_70 = - V_26 ;
}
return V_70 ;
}
int F_151 ( void * V_195 )
{
if ( V_13 ) {
F_36 ( L_28 ) ;
return - V_196 ;
}
return F_152 ( & V_13 ) ;
}
void F_153 ( void )
{
V_13 = NULL ;
}
int F_154 ( struct V_1 * V_2 ,
struct V_197 * V_198 )
{
return - V_26 ;
}
int F_155 ( struct V_1 * V_2 ,
struct V_197 * V_198 )
{
return - V_26 ;
}
void F_156 ( struct V_1 * V_2 )
{
}
int F_157 ( struct V_1 * V_2 , struct V_199 * V_108 )
{
return - V_26 ;
}
int F_158 ( struct V_1 * V_2 , struct V_199 * V_108 )
{
return - V_26 ;
}
int F_159 ( struct V_1 * V_2 , struct V_200 * V_201 )
{
return V_202 ;
}
int F_143 ( struct V_9 * V_9 , long V_203 )
{
int V_70 ;
switch ( V_203 ) {
case V_204 :
case V_205 :
V_70 = 1 ;
break;
case V_206 :
V_70 = V_207 ;
break;
case V_168 :
V_70 = ! ! V_208 ;
break;
case V_170 :
V_70 = V_209 && ! ( V_93 . V_127 & V_210 ) ;
break;
default:
V_70 = 0 ;
break;
}
return V_70 ;
}
int F_160 ( struct V_1 * V_2 )
{
return F_161 ( V_2 ) ;
}
int F_162 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_106 * V_77 ;
if ( ! V_2 )
return - 1 ;
F_12 ( L_29 ) ;
F_12 ( L_30 , V_2 -> V_4 . V_120 ) ;
F_12 ( L_31 , V_2 -> V_4 . V_7 ) ;
for ( V_3 = 0 ; V_3 < 32 ; V_3 += 4 ) {
F_12 ( L_32 , V_3 ,
V_2 -> V_4 . V_114 [ V_3 ] ,
V_2 -> V_4 . V_114 [ V_3 + 1 ] ,
V_2 -> V_4 . V_114 [ V_3 + 2 ] , V_2 -> V_4 . V_114 [ V_3 + 3 ] ) ;
}
F_12 ( L_33 , V_2 -> V_4 . V_116 ) ;
F_12 ( L_34 , V_2 -> V_4 . V_118 ) ;
V_77 = V_2 -> V_4 . V_77 ;
F_12 ( L_35 ,
F_88 ( V_77 ) ,
F_61 ( V_77 ) ) ;
F_12 ( L_36 , F_102 ( V_77 ) ) ;
return 0 ;
}
int F_163 ( struct V_1 * V_2 , struct V_211 * V_212 )
{
int V_3 ;
for ( V_3 = 1 ; V_3 < F_75 ( V_2 -> V_4 . V_114 ) ; V_3 ++ )
V_2 -> V_4 . V_114 [ V_3 ] = V_212 -> V_213 [ V_3 ] ;
V_2 -> V_4 . V_114 [ 0 ] = 0 ;
V_2 -> V_4 . V_116 = V_212 -> V_116 ;
V_2 -> V_4 . V_118 = V_212 -> V_118 ;
V_2 -> V_4 . V_120 = V_212 -> V_120 ;
return 0 ;
}
int F_164 ( struct V_1 * V_2 , struct V_211 * V_212 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_75 ( V_2 -> V_4 . V_114 ) ; V_3 ++ )
V_212 -> V_213 [ V_3 ] = V_2 -> V_4 . V_114 [ V_3 ] ;
V_212 -> V_116 = V_2 -> V_4 . V_116 ;
V_212 -> V_118 = V_2 -> V_4 . V_118 ;
V_212 -> V_120 = V_2 -> V_4 . V_120 ;
return 0 ;
}
static void F_165 ( unsigned long V_214 )
{
struct V_1 * V_2 = (struct V_1 * ) V_214 ;
V_13 -> V_215 ( V_2 ) ;
V_2 -> V_4 . V_86 = 0 ;
if ( F_70 ( & V_2 -> V_87 ) )
F_71 ( & V_2 -> V_87 ) ;
}
static enum V_216 F_166 ( struct V_217 * V_218 )
{
struct V_1 * V_2 ;
V_2 = F_167 ( V_218 , struct V_1 , V_4 . V_65 ) ;
F_165 ( ( unsigned long ) V_2 ) ;
return F_168 ( V_2 ) ;
}
int F_169 ( struct V_1 * V_2 )
{
V_13 -> V_219 ( V_2 ) ;
F_170 ( & V_2 -> V_4 . V_65 , V_220 ,
V_221 ) ;
V_2 -> V_4 . V_65 . V_222 = F_166 ;
return 0 ;
}
int F_171 ( struct V_1 * V_2 ,
struct V_223 * V_224 )
{
return 0 ;
}
int F_172 ( struct V_1 * V_2 )
{
return V_13 -> V_225 ( V_2 ) ;
}
static void F_173 ( void )
{
T_1 V_226 = F_174 () ;
if ( V_227 )
V_226 |= ( V_228 ) ;
F_175 ( V_226 ) ;
F_176 () ;
}
int F_177 ( struct V_68 * V_69 , struct V_1 * V_2 )
{
T_1 V_229 = V_2 -> V_4 . V_230 ;
T_1 V_231 = ( V_229 >> V_232 ) & 0x1f ;
T_1 T_4 * V_233 = ( T_1 T_4 * ) V_2 -> V_4 . V_120 ;
unsigned long V_234 = V_2 -> V_4 . V_235 ;
enum V_236 V_237 = V_238 ;
int V_90 = V_239 ;
F_66 () ;
V_69 -> V_240 = V_241 ;
V_69 -> V_242 = 1 ;
F_173 () ;
F_68 () ;
F_12 ( L_37 ,
V_229 , V_233 , V_69 , V_2 ) ;
F_178 ( V_2 , V_231 ) ;
V_237 = F_179 ( V_229 , V_233 , V_69 , V_2 ) ;
if ( V_237 == V_243 ) {
goto V_244;
} else if ( V_237 == V_245 ) {
V_69 -> V_240 = V_246 ;
V_90 = V_247 ;
goto V_244;
}
switch ( V_231 ) {
case V_248 :
F_12 ( L_38 , V_2 -> V_184 , V_233 ) ;
++ V_2 -> V_249 . V_250 ;
if ( F_180 () )
F_181 () ;
V_90 = V_239 ;
break;
case V_251 :
F_12 ( L_39 , V_233 ) ;
++ V_2 -> V_249 . V_252 ;
V_90 = V_13 -> V_253 ( V_2 ) ;
if ( V_69 -> V_240 == V_254 )
V_90 = V_247 ;
break;
case V_255 :
++ V_2 -> V_249 . V_256 ;
V_90 = V_13 -> V_257 ( V_2 ) ;
break;
case V_258 :
F_12 ( L_40 ,
V_229 , F_88 ( V_2 -> V_4 . V_77 ) , V_233 ,
V_234 ) ;
++ V_2 -> V_249 . V_259 ;
V_90 = V_13 -> V_260 ( V_2 ) ;
break;
case V_261 :
F_12 ( L_41 ,
V_229 , V_233 , V_234 ) ;
++ V_2 -> V_249 . V_262 ;
V_90 = V_13 -> V_263 ( V_2 ) ;
break;
case V_264 :
++ V_2 -> V_249 . V_265 ;
V_90 = V_13 -> V_266 ( V_2 ) ;
break;
case V_267 :
++ V_2 -> V_249 . V_268 ;
V_90 = V_13 -> V_269 ( V_2 ) ;
break;
case V_270 :
++ V_2 -> V_249 . V_271 ;
V_90 = V_13 -> V_272 ( V_2 ) ;
break;
case V_273 :
++ V_2 -> V_249 . V_274 ;
V_90 = V_13 -> V_275 ( V_2 ) ;
break;
case V_276 :
++ V_2 -> V_249 . V_277 ;
V_90 = V_13 -> V_278 ( V_2 ) ;
break;
case V_279 :
++ V_2 -> V_249 . V_280 ;
V_90 = V_13 -> V_281 ( V_2 ) ;
break;
case V_282 :
++ V_2 -> V_249 . V_283 ;
V_90 = V_13 -> V_284 ( V_2 ) ;
break;
case V_285 :
++ V_2 -> V_249 . V_286 ;
V_90 = V_13 -> V_287 ( V_2 ) ;
break;
case V_288 :
++ V_2 -> V_249 . V_289 ;
V_90 = V_13 -> V_290 ( V_2 ) ;
break;
default:
F_36 ( L_42 ,
V_231 , V_233 , F_182 ( V_233 , V_2 ) , V_234 ,
F_88 ( V_2 -> V_4 . V_77 ) ) ;
F_162 ( V_2 ) ;
V_69 -> V_240 = V_246 ;
V_90 = V_247 ;
break;
}
V_244:
F_59 () ;
if ( V_237 == V_238 && ! ( V_90 & V_247 ) )
F_60 ( V_2 , V_229 ) ;
if ( ! ( V_90 & V_247 ) ) {
if ( F_183 ( V_291 ) ) {
V_69 -> V_240 = V_292 ;
V_90 = ( - V_293 << 2 ) | V_247 ;
++ V_2 -> V_249 . V_294 ;
F_178 ( V_2 , V_295 ) ;
}
}
if ( V_90 == V_239 ) {
F_184 ( V_2 ) ;
if ( F_87 ( & V_2 -> V_4 ) &&
F_174 () & V_296 )
F_185 ( & V_2 -> V_4 ) ;
if ( F_91 ( & V_2 -> V_4 ) &&
F_186 () & V_297 )
F_187 ( & V_2 -> V_4 ) ;
}
F_63 () ;
return V_90 ;
}
void F_188 ( struct V_1 * V_2 )
{
struct V_106 * V_77 = V_2 -> V_4 . V_77 ;
unsigned int V_298 , V_299 ;
F_189 () ;
V_298 = F_88 ( V_77 ) ;
if ( V_209 && V_298 & V_296 && ! ( V_298 & V_121 ) &&
V_2 -> V_4 . V_300 & V_301 )
F_190 ( V_2 ) ;
F_191 ( V_296 | V_121 , V_298 ) ;
if ( V_302 ) {
V_299 = F_109 ( V_77 ) ;
F_192 ( V_303 , V_299 ) ;
}
F_193 () ;
if ( ! ( V_2 -> V_4 . V_300 & V_304 ) ) {
F_194 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_300 |= V_304 ;
F_195 ( V_2 , V_305 , V_306 ) ;
} else {
F_195 ( V_2 , V_307 , V_306 ) ;
}
F_196 () ;
}
void F_197 ( struct V_1 * V_2 )
{
struct V_106 * V_77 = V_2 -> V_4 . V_77 ;
unsigned int V_298 , V_299 ;
F_189 () ;
if ( F_87 ( & V_2 -> V_4 ) ) {
V_298 = F_88 ( V_77 ) ;
if ( ! ( V_298 & V_121 ) &&
( V_2 -> V_4 . V_300 & ( V_304 |
V_301 ) ) == V_304 )
F_190 ( V_2 ) ;
F_191 ( V_296 | V_121 , V_298 ) ;
if ( V_298 & V_296 && V_302 ) {
V_299 = F_109 ( V_77 ) ;
F_192 ( V_303 , V_299 ) ;
}
}
F_198 ( V_297 ) ;
F_193 () ;
switch ( V_2 -> V_4 . V_300 & ( V_304 | V_301 ) ) {
case V_304 :
F_199 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_300 |= V_301 ;
F_195 ( V_2 , V_305 , V_308 ) ;
break;
case 0 :
F_200 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_300 |= V_301 ;
if ( F_87 ( & V_2 -> V_4 ) )
V_2 -> V_4 . V_300 |= V_304 ;
F_195 ( V_2 , V_305 ,
V_309 ) ;
break;
default:
F_195 ( V_2 , V_307 , V_308 ) ;
break;
}
F_196 () ;
}
void F_201 ( struct V_1 * V_2 )
{
F_189 () ;
if ( V_209 && V_2 -> V_4 . V_300 & V_301 ) {
F_202 () ;
F_195 ( V_2 , V_310 , V_308 ) ;
V_2 -> V_4 . V_300 &= ~ V_301 ;
}
if ( V_2 -> V_4 . V_300 & V_304 ) {
F_203 ( V_296 | V_121 ) ;
F_195 ( V_2 , V_310 , V_306 ) ;
V_2 -> V_4 . V_300 &= ~ V_304 ;
}
F_196 () ;
}
void F_190 ( struct V_1 * V_2 )
{
F_189 () ;
if ( V_209 && V_2 -> V_4 . V_300 & V_301 ) {
F_198 ( V_297 ) ;
F_193 () ;
F_204 ( & V_2 -> V_4 ) ;
F_195 ( V_2 , V_311 , V_309 ) ;
F_202 () ;
if ( V_2 -> V_4 . V_300 & V_304 ) {
F_203 ( V_296 | V_121 ) ;
F_205 () ;
}
V_2 -> V_4 . V_300 &= ~ ( V_304 | V_301 ) ;
} else if ( V_2 -> V_4 . V_300 & V_304 ) {
F_206 ( V_296 ) ;
F_193 () ;
F_207 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_300 &= ~ V_304 ;
F_195 ( V_2 , V_311 , V_306 ) ;
F_203 ( V_296 | V_121 ) ;
F_205 () ;
}
F_196 () ;
}
static int F_208 ( struct V_312 * V_313 ,
unsigned long V_314 , void * V_315 )
{
struct V_316 * args = (struct V_316 * ) V_315 ;
struct V_317 * V_212 = args -> V_212 ;
unsigned long V_120 ;
if ( V_314 != V_318 && V_314 != V_319 )
return V_320 ;
if ( ! ( V_291 -> V_167 & V_321 ) )
return V_320 ;
F_209 ( F_210 ( V_212 ) ) ;
V_120 = F_211 ( V_212 ) ;
switch ( V_314 ) {
case V_318 :
if ( V_120 != ( unsigned long ) & F_185 + 4 )
return V_320 ;
break;
case V_319 :
if ( ! V_209 ||
V_120 < ( unsigned long ) & F_187 + 4 ||
V_120 > ( unsigned long ) & F_187 + 8 )
return V_320 ;
break;
}
F_211 ( V_212 ) += 4 ;
return V_322 ;
}
static int T_7 F_212 ( void )
{
int V_90 ;
V_90 = F_213 () ;
if ( V_90 )
return V_90 ;
V_90 = F_214 ( NULL , sizeof( struct V_1 ) , 0 , V_323 ) ;
if ( V_90 )
return V_90 ;
F_215 ( & V_324 ) ;
return 0 ;
}
static void T_8 F_216 ( void )
{
F_217 () ;
F_218 ( & V_324 ) ;
}
