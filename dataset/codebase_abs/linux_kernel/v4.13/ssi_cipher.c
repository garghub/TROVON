static int F_1 ( struct V_1 * V_2 , T_1 V_3 ) {
switch ( V_2 -> V_4 ) {
case V_5 :
switch ( V_3 ) {
case V_6 :
case V_7 :
if ( F_2 ( ( V_2 -> V_8 != V_9 ) &&
( V_2 -> V_8 != V_10 ) &&
( V_2 -> V_8 != V_11 ) ) )
return 0 ;
break;
case V_12 :
return 0 ;
case ( V_7 * 2 ) :
case ( V_12 * 2 ) :
if ( F_2 ( ( V_2 -> V_8 == V_9 ) ||
( V_2 -> V_8 == V_10 ) ||
( V_2 -> V_8 == V_11 ) ) )
return 0 ;
break;
default:
break;
}
case V_13 :
if ( F_2 ( V_3 == V_14 ||
V_3 == V_15 ) )
return 0 ;
break;
#if V_16
case V_17 :
if ( F_2 ( V_3 == V_18 ) )
return 0 ;
break;
#endif
default:
break;
}
return - V_19 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ) {
switch ( V_2 -> V_4 ) {
case V_5 :
switch ( V_2 -> V_8 ) {
case V_9 :
if ( ( V_3 >= V_20 ) &&
( V_3 <= V_21 ) &&
F_4 ( V_3 , V_22 ) )
return 0 ;
break;
case V_23 :
if ( F_2 ( V_3 >= V_22 ) )
return 0 ;
break;
case V_24 :
case V_25 :
return 0 ;
case V_26 :
case V_27 :
case V_10 :
case V_11 :
if ( F_2 ( F_4 ( V_3 , V_22 ) ) )
return 0 ;
break;
default:
break;
}
break;
case V_13 :
if ( F_2 ( F_4 ( V_3 , V_28 ) ) )
return 0 ;
break;
#if V_16
case V_17 :
switch ( V_2 -> V_8 ) {
case V_29 :
if ( F_2 ( F_4 ( V_3 , V_30 ) ) )
return 0 ;
break;
case V_31 :
return 0 ;
default:
break;
}
break;
#endif
default:
break;
}
return - V_19 ;
}
static unsigned int F_5 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_6 ( V_33 -> V_36 , struct V_34 , V_37 ) ;
if ( ( V_35 -> V_37 . V_38 & V_39 ) == V_40 )
return V_35 -> V_37 . V_41 . V_42 ;
if ( ( V_35 -> V_37 . V_38 & V_39 ) == V_43 )
return V_35 -> V_37 . V_44 . V_42 ;
return 0 ;
}
static int F_7 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
struct V_37 * V_45 = V_33 -> V_36 ;
struct V_34 * V_35 =
F_6 ( V_45 , struct V_34 , V_37 ) ;
struct V_46 * V_47 ;
int V_48 = 0 ;
unsigned int V_49 = F_5 ( V_33 ) ;
F_9 ( L_1 , V_2 ,
F_10 ( V_33 ) ) ;
F_11 () ;
V_2 -> V_8 = V_35 -> V_8 ;
V_2 -> V_4 = V_35 -> V_4 ;
V_2 -> V_50 = V_35 -> V_50 ;
V_47 = & V_2 -> V_50 -> V_51 -> V_47 ;
V_2 -> V_52 . V_53 = F_12 ( V_49 , V_54 | V_55 ) ;
if ( ! V_2 -> V_52 . V_53 ) {
F_13 ( L_2 ) ;
V_48 = - V_56 ;
}
F_9 ( L_3 ,
V_2 -> V_52 . V_53 ) ;
V_2 -> V_52 . V_57 = F_14 ( V_47 , ( void * ) V_2 -> V_52 . V_53 ,
V_49 , V_58 ) ;
if ( F_15 ( V_47 , V_2 -> V_52 . V_57 ) ) {
F_13 ( L_4 ,
V_49 , V_2 -> V_52 . V_53 ) ;
return - V_56 ;
}
F_9 ( L_5 ,
V_49 , V_2 -> V_52 . V_53 ,
( unsigned long long ) V_2 -> V_52 . V_57 ) ;
if ( V_2 -> V_8 == V_10 ) {
V_2 -> V_59 = F_16 ( L_6 , 0 , 0 ) ;
if ( F_17 ( V_2 -> V_59 ) ) {
F_13 ( L_7 ) ;
return F_18 ( V_2 -> V_59 ) ;
}
}
return V_48 ;
}
static void F_19 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
struct V_46 * V_47 = & V_2 -> V_50 -> V_51 -> V_47 ;
unsigned int V_49 = F_5 ( V_33 ) ;
F_9 ( L_8 ,
F_8 ( V_33 ) , F_10 ( V_33 ) ) ;
if ( V_2 -> V_8 == V_10 ) {
F_20 ( V_2 -> V_59 ) ;
V_2 -> V_59 = NULL ;
}
F_21 ( V_47 , V_2 -> V_52 . V_57 , V_49 ,
V_58 ) ;
F_9 ( L_9 ,
( unsigned long long ) V_2 -> V_52 . V_57 ) ;
F_22 ( V_2 -> V_52 . V_53 ) ;
F_9 ( L_10 , V_2 -> V_52 . V_53 ) ;
}
static int F_23 ( const T_2 * V_53 , unsigned int V_60 )
{
#ifdef F_24
struct V_61 * V_62 = (struct V_61 * ) V_53 ;
if ( F_25 ( ( memcmp ( ( T_2 * ) V_62 -> V_63 , ( T_2 * ) V_62 -> V_64 , sizeof( V_62 -> V_63 ) ) == 0 ) ||
( memcmp ( ( T_2 * ) V_62 -> V_65 , ( T_2 * ) V_62 -> V_64 , sizeof( V_62 -> V_65 ) ) == 0 ) ) ) {
return - V_66 ;
}
#endif
return 0 ;
}
static int F_26 ( const T_2 * V_53 , unsigned int V_60 )
{
#ifdef F_24
int V_67 = V_60 >> 1 ;
if ( F_25 ( memcmp ( V_53 , & V_53 [ V_67 ] , V_67 ) == 0 ) )
return - V_66 ;
#endif
return 0 ;
}
static enum V_68 F_27 ( int V_69 )
{
switch ( V_69 ) {
case 0 :
return V_70 ;
case 1 :
return V_71 ;
case 2 :
return V_72 ;
case 3 :
return V_73 ;
}
return V_74 ;
}
static inline void
F_28 (
struct V_32 * V_33 ,
struct V_75 * V_76 ,
unsigned int V_77 ,
unsigned int V_78 ,
struct V_79 V_80 [] ,
unsigned int * V_81 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
int V_8 = V_2 -> V_8 ;
int V_4 = V_2 -> V_4 ;
int V_82 = V_76 -> V_83 . V_84 ;
T_3 V_57 = V_2 -> V_52 . V_57 ;
unsigned int V_85 = V_2 -> V_60 ;
T_3 V_86 = V_76 -> V_83 . V_86 ;
unsigned int V_87 = V_78 ;
struct V_34 * V_35 = F_6 ( V_33 -> V_36 , struct V_34 , V_37 ) ;
if ( ( V_35 -> V_37 . V_38 & V_88 ) == V_89 )
V_87 = 512 ;
if ( ( V_35 -> V_37 . V_38 & V_88 ) == V_90 )
V_87 = 4096 ;
switch ( V_8 ) {
case V_27 :
case V_23 :
case V_25 :
case V_24 :
F_29 ( & V_80 [ * V_81 ] ) ;
F_30 ( & V_80 [ * V_81 ] , V_91 , V_86 , V_77 ,
V_92 ) ;
F_31 ( & V_80 [ * V_81 ] , V_82 ) ;
F_32 ( & V_80 [ * V_81 ] , V_4 ) ;
F_33 ( & V_80 [ * V_81 ] , V_8 ) ;
if ( ( V_8 == V_25 ) ||
( V_8 == V_24 ) ) {
F_34 ( & V_80 [ * V_81 ] , V_93 ) ;
} else {
F_34 ( & V_80 [ * V_81 ] , V_94 ) ;
}
( * V_81 ) ++ ;
case V_26 :
F_29 ( & V_80 [ * V_81 ] ) ;
F_33 ( & V_80 [ * V_81 ] , V_8 ) ;
F_31 ( & V_80 [ * V_81 ] , V_82 ) ;
if ( V_4 == V_5 ) {
if ( F_35 ( V_33 ) ) {
F_36 ( & V_80 [ * V_81 ] ,
V_2 -> V_95 . V_96 ) ;
} else {
F_30 ( & V_80 [ * V_81 ] , V_91 ,
V_57 , ( ( V_85 == 24 ) ?
V_97 :
V_85 ) , V_92 ) ;
}
F_37 ( & V_80 [ * V_81 ] , V_85 ) ;
} else {
F_30 ( & V_80 [ * V_81 ] , V_91 , V_57 ,
V_85 , V_92 ) ;
F_38 ( & V_80 [ * V_81 ] , V_85 ) ;
}
F_32 ( & V_80 [ * V_81 ] , V_4 ) ;
F_34 ( & V_80 [ * V_81 ] , V_98 ) ;
( * V_81 ) ++ ;
break;
case V_9 :
case V_10 :
case V_11 :
F_29 ( & V_80 [ * V_81 ] ) ;
F_33 ( & V_80 [ * V_81 ] , V_8 ) ;
F_31 ( & V_80 [ * V_81 ] , V_82 ) ;
if ( F_35 ( V_33 ) ) {
F_36 ( & V_80 [ * V_81 ] ,
V_2 -> V_95 . V_96 ) ;
} else {
F_30 ( & V_80 [ * V_81 ] , V_91 , V_57 ,
( V_85 / 2 ) , V_92 ) ;
}
F_37 ( & V_80 [ * V_81 ] , ( V_85 / 2 ) ) ;
F_32 ( & V_80 [ * V_81 ] , V_4 ) ;
F_34 ( & V_80 [ * V_81 ] , V_98 ) ;
( * V_81 ) ++ ;
F_29 ( & V_80 [ * V_81 ] ) ;
F_33 ( & V_80 [ * V_81 ] , V_8 ) ;
F_31 ( & V_80 [ * V_81 ] , V_82 ) ;
if ( F_35 ( V_33 ) ) {
F_36 ( & V_80 [ * V_81 ] ,
V_2 -> V_95 . V_99 ) ;
} else {
F_30 ( & V_80 [ * V_81 ] , V_91 ,
( V_57 + ( V_85 / 2 ) ) ,
( V_85 / 2 ) , V_92 ) ;
}
F_39 ( & V_80 [ * V_81 ] , V_87 ) ;
F_32 ( & V_80 [ * V_81 ] , V_100 ) ;
F_37 ( & V_80 [ * V_81 ] , ( V_85 / 2 ) ) ;
F_34 ( & V_80 [ * V_81 ] , V_101 ) ;
( * V_81 ) ++ ;
F_29 ( & V_80 [ * V_81 ] ) ;
F_34 ( & V_80 [ * V_81 ] , V_93 ) ;
F_33 ( & V_80 [ * V_81 ] , V_8 ) ;
F_31 ( & V_80 [ * V_81 ] , V_82 ) ;
F_37 ( & V_80 [ * V_81 ] , ( V_85 / 2 ) ) ;
F_32 ( & V_80 [ * V_81 ] , V_4 ) ;
F_30 ( & V_80 [ * V_81 ] , V_91 , V_86 ,
V_102 , V_92 ) ;
( * V_81 ) ++ ;
break;
default:
F_13 ( L_11 , V_8 ) ;
F_40 () ;
}
}
static inline void F_41 (
struct V_32 * V_33 ,
struct V_75 * V_76 ,
unsigned int V_77 ,
struct V_79 V_80 [] ,
unsigned int * V_81 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
int V_82 = V_76 -> V_83 . V_84 ;
F_29 ( & V_80 [ * V_81 ] ) ;
F_33 ( & V_80 [ * V_81 ] , V_2 -> V_8 ) ;
F_31 ( & V_80 [ * V_81 ] , V_82 ) ;
F_30 ( & V_80 [ * V_81 ] , V_91 , V_2 -> V_52 . V_57 ,
V_103 , V_92 ) ;
F_32 ( & V_80 [ * V_81 ] , V_2 -> V_4 ) ;
F_34 ( & V_80 [ * V_81 ] , V_98 ) ;
( * V_81 ) ++ ;
F_29 ( & V_80 [ * V_81 ] ) ;
F_30 ( & V_80 [ * V_81 ] , V_91 ,
( V_2 -> V_52 . V_57 + V_103 ) ,
V_104 , V_92 ) ;
F_42 ( & V_80 [ * V_81 ] , V_2 -> V_105 ) ;
F_32 ( & V_80 [ * V_81 ] , V_2 -> V_4 ) ;
F_33 ( & V_80 [ * V_81 ] , V_2 -> V_8 ) ;
F_31 ( & V_80 [ * V_81 ] , V_82 ) ;
F_34 ( & V_80 [ * V_81 ] , V_94 ) ;
( * V_81 ) ++ ;
F_29 ( & V_80 [ * V_81 ] ) ;
F_30 ( & V_80 [ * V_81 ] , V_91 , V_76 -> V_83 . V_86 ,
V_77 , V_92 ) ;
F_31 ( & V_80 [ * V_81 ] , V_82 ) ;
F_32 ( & V_80 [ * V_81 ] , V_2 -> V_4 ) ;
F_33 ( & V_80 [ * V_81 ] , V_2 -> V_8 ) ;
F_34 ( & V_80 [ * V_81 ] , V_93 ) ;
( * V_81 ) ++ ;
}
static inline void
F_43 (
struct V_32 * V_33 ,
struct V_75 * V_76 ,
struct V_106 * V_107 , struct V_106 * V_108 ,
unsigned int V_78 ,
void * V_109 ,
struct V_79 V_80 [] ,
unsigned int * V_81 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
unsigned int V_4 = V_2 -> V_4 ;
switch ( V_2 -> V_4 ) {
case V_5 :
V_4 = V_110 ;
break;
case V_13 :
V_4 = V_111 ;
break;
#if V_16
case V_17 :
V_4 = V_112 ;
break;
#endif
default:
F_13 ( L_12 , V_4 ) ;
return;
}
if ( F_2 ( V_76 -> V_113 == V_114 ) ) {
F_9 ( L_13 ,
( unsigned long long ) F_44 ( V_108 ) ,
V_78 ) ;
F_9 ( L_13 ,
( unsigned long long ) F_44 ( V_107 ) ,
V_78 ) ;
F_29 ( & V_80 [ * V_81 ] ) ;
F_30 ( & V_80 [ * V_81 ] , V_91 , F_44 ( V_108 ) ,
V_78 , V_92 ) ;
F_45 ( & V_80 [ * V_81 ] , F_44 ( V_107 ) ,
V_78 , V_92 , ( ! V_109 ? 0 : 1 ) ) ;
if ( V_109 )
F_46 ( & V_80 [ * V_81 ] ) ;
F_32 ( & V_80 [ * V_81 ] , V_4 ) ;
( * V_81 ) ++ ;
} else {
F_9 ( L_14
L_15 ,
( unsigned long long ) V_76 -> V_115 . V_116 ,
V_76 -> V_115 . V_117 ,
( unsigned int ) V_2 -> V_50 -> V_118 ) ;
F_29 ( & V_80 [ * V_81 ] ) ;
F_30 ( & V_80 [ * V_81 ] , V_91 ,
V_76 -> V_115 . V_116 ,
V_76 -> V_115 . V_117 , V_92 ) ;
F_47 ( & V_80 [ * V_81 ] ,
V_2 -> V_50 -> V_118 ,
V_76 -> V_115 . V_117 ) ;
F_32 ( & V_80 [ * V_81 ] , V_119 ) ;
( * V_81 ) ++ ;
F_29 ( & V_80 [ * V_81 ] ) ;
F_30 ( & V_80 [ * V_81 ] , V_120 ,
V_2 -> V_50 -> V_118 ,
V_76 -> V_121 , V_92 ) ;
if ( V_76 -> V_122 == 0 ) {
F_9 ( L_16
L_17 ,
( unsigned int ) V_2 -> V_50 -> V_118 ,
( unsigned int ) V_2 -> V_50 -> V_118 ) ;
F_48 ( & V_80 [ * V_81 ] ,
V_2 -> V_50 -> V_118 ,
V_76 -> V_121 , V_92 ,
( ! V_109 ? 0 : 1 ) ) ;
} else {
F_9 ( L_18
L_19 ,
( unsigned int ) V_2 -> V_50 -> V_118 ,
( unsigned int ) V_2 -> V_50 -> V_118 +
( T_1 ) V_123 *
V_76 -> V_124 ) ;
F_48 ( & V_80 [ * V_81 ] ,
( V_2 -> V_50 -> V_118 +
( V_123 *
V_76 -> V_121 ) ) ,
V_76 -> V_125 , V_92 ,
( ! V_109 ? 0 : 1 ) ) ;
}
if ( V_109 )
F_46 ( & V_80 [ * V_81 ] ) ;
F_32 ( & V_80 [ * V_81 ] , V_4 ) ;
( * V_81 ) ++ ;
}
}
static int F_49 ( struct V_46 * V_47 ,
struct V_1 * V_2 ,
struct V_75 * V_76 ,
struct V_106 * V_107 ,
struct V_106 * V_108 ,
unsigned int V_77 ,
void * V_109 ,
void T_4 * V_126 )
{
int V_127 = 0 ;
T_1 V_128 ;
F_50 ( V_47 , V_76 , V_77 , V_108 , V_107 ) ;
V_128 = V_2 -> V_50 -> V_128 ;
if ( V_2 -> V_4 == V_119 && V_2 -> V_50 -> V_128 > 0 )
V_2 -> V_50 -> V_128 -- ;
if ( V_109 ) {
F_51 ( V_109 , V_127 ) ;
return 0 ;
}
return V_127 ;
}
static int F_52 (
struct V_32 * V_33 ,
struct V_75 * V_76 ,
struct V_106 * V_107 , struct V_106 * V_108 ,
unsigned int V_78 ,
void * V_129 ,
unsigned int V_77 ,
void * V_109 ,
enum V_130 V_82 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
struct V_46 * V_47 = & V_2 -> V_50 -> V_51 -> V_47 ;
struct V_79 V_80 [ V_131 ] ;
struct V_132 V_133 = {} ;
int V_48 , V_134 = 0 , V_135 = 0 ;
F_9 ( L_20 ,
( ( V_82 == V_136 ) ? L_21 : L_22 ) ,
V_109 , V_129 , V_78 ) ;
F_11 () ;
if ( F_25 ( F_3 ( V_2 , V_78 ) ) ) {
F_13 ( L_23 , V_78 ) ;
F_53 ( V_33 , V_137 ) ;
return - V_19 ;
}
if ( V_78 == 0 ) {
return 0 ;
}
if ( ( ( V_78 % V_22 ) == 0 ) && ( V_2 -> V_8 == V_23 ) ) {
V_2 -> V_8 = V_27 ;
V_135 = 1 ;
}
V_133 . V_138 = ( void * ) V_139 ;
V_133 . V_140 = ( void * ) V_109 ;
#ifdef F_54
V_133 . V_84 = ( V_82 == V_141 ) ?
V_142 : V_143 ;
#endif
V_76 -> V_83 . V_84 = V_82 ;
V_48 = F_55 ( V_2 -> V_50 , V_76 , V_77 , V_78 , V_129 , V_108 , V_107 ) ;
if ( F_25 ( V_48 != 0 ) ) {
F_13 ( L_24 ) ;
goto V_144;
}
#if V_16
if ( V_2 -> V_4 == V_17 )
F_41 ( V_33 , V_76 , V_77 ,
V_80 , & V_134 ) ;
else
#endif
F_28 ( V_33 , V_76 , V_77 , V_78 ,
V_80 , & V_134 ) ;
F_43 ( V_33 ,
V_76 ,
V_107 , V_108 ,
V_78 ,
V_109 ,
V_80 , & V_134 ) ;
if ( V_76 -> V_145 ) {
V_133 . V_146 [ 0 ] = V_76 -> V_83 . V_86 ;
V_133 . V_147 = 1 ;
V_133 . V_148 = V_77 ;
}
V_48 = F_56 ( V_2 -> V_50 , & V_133 , V_80 , V_134 , ( ! V_109 ) ? 0 : 1 ) ;
if ( V_109 ) {
if ( F_25 ( V_48 != - V_149 ) ) {
F_50 ( V_47 , V_76 , V_77 , V_108 , V_107 ) ;
}
} else {
if ( V_48 != 0 ) {
F_50 ( V_47 , V_76 , V_77 , V_108 , V_107 ) ;
} else {
V_48 = F_49 ( V_47 , V_2 , V_76 , V_107 ,
V_108 , V_77 , NULL ,
V_2 -> V_50 -> V_126 ) ;
}
}
V_144:
if ( V_135 != 0 )
V_2 -> V_8 = V_23 ;
return V_48 ;
}
static void V_139 ( struct V_46 * V_47 , void * V_133 , void T_4 * V_126 )
{
struct V_150 * V_109 = (struct V_150 * ) V_133 ;
struct V_75 * V_76 = F_57 ( V_109 ) ;
struct V_151 * V_33 = F_58 ( V_109 ) ;
struct V_1 * V_2 = F_59 ( V_33 ) ;
unsigned int V_77 = F_60 ( V_33 ) ;
F_61 () ;
F_49 ( V_47 , V_2 , V_76 , V_109 -> V_107 , V_109 -> V_108 ,
V_77 , V_109 , V_126 ) ;
}
static int F_62 ( struct V_32 * V_33 )
{
struct V_152 * V_153 = & V_33 -> V_154 ;
V_153 -> V_155 = sizeof( struct V_75 ) ;
return F_7 ( V_33 ) ;
}
static int F_63 ( struct V_151 * V_33 ,
const T_2 * V_53 ,
unsigned int V_60 )
{
return F_64 ( F_65 ( V_33 ) , V_53 , V_60 ) ;
}
static int F_66 ( struct V_150 * V_156 )
{
struct V_151 * V_157 = F_58 ( V_156 ) ;
struct V_32 * V_33 = F_65 ( V_157 ) ;
struct V_75 * V_76 = F_57 ( V_156 ) ;
unsigned int V_77 = F_60 ( V_157 ) ;
V_76 -> V_158 = V_156 -> V_129 ;
V_76 -> V_145 = false ;
return F_52 ( V_33 , V_76 , V_156 -> V_107 , V_156 -> V_108 , V_156 -> V_78 , V_156 -> V_129 , V_77 , ( void * ) V_156 , V_136 ) ;
}
static int F_67 ( struct V_150 * V_156 )
{
struct V_151 * V_157 = F_58 ( V_156 ) ;
struct V_32 * V_33 = F_65 ( V_157 ) ;
struct V_75 * V_76 = F_57 ( V_156 ) ;
unsigned int V_77 = F_60 ( V_157 ) ;
V_76 -> V_158 = V_156 -> V_129 ;
V_76 -> V_145 = false ;
return F_52 ( V_33 , V_76 , V_156 -> V_107 , V_156 -> V_108 , V_156 -> V_78 , V_156 -> V_129 , V_77 , ( void * ) V_156 , V_141 ) ;
}
static
struct V_34 * F_68 ( struct V_159 * V_160 )
{
struct V_34 * V_161 ;
struct V_37 * V_45 ;
V_161 = F_69 ( sizeof( struct V_34 ) , V_54 ) ;
if ( ! V_161 ) {
F_13 ( L_25 ) ;
return F_70 ( - V_56 ) ;
}
V_45 = & V_161 -> V_37 ;
snprintf ( V_45 -> V_162 , V_163 , L_26 , V_160 -> V_164 ) ;
snprintf ( V_45 -> V_165 , V_163 , L_26 ,
V_160 -> V_166 ) ;
V_45 -> V_167 = V_168 ;
V_45 -> V_169 = V_170 ;
V_45 -> V_171 = V_160 -> V_172 ;
V_45 -> V_173 = 0 ;
V_45 -> V_174 = sizeof( struct V_1 ) ;
V_45 -> V_175 = F_62 ;
V_45 -> V_176 = F_19 ;
V_45 -> V_177 = & V_178 ;
V_45 -> V_41 = V_160 -> V_179 ;
V_45 -> V_38 = V_180 | V_181 |
V_160 -> type ;
V_161 -> V_8 = V_160 -> V_8 ;
V_161 -> V_4 = V_160 -> V_4 ;
return V_161 ;
}
int F_71 ( struct V_182 * V_50 )
{
struct V_34 * V_161 , * V_183 ;
struct V_184 * V_185 =
V_50 -> V_185 ;
struct V_46 * V_47 ;
V_47 = & V_50 -> V_51 -> V_47 ;
if ( V_185 ) {
F_72 (t_alg, n,
&blkcipher_handle->blkcipher_alg_list,
entry) {
F_73 ( & V_161 -> V_37 ) ;
F_74 ( & V_161 -> V_186 ) ;
F_22 ( V_161 ) ;
}
F_22 ( V_185 ) ;
V_50 -> V_185 = NULL ;
}
return 0 ;
}
int F_75 ( struct V_182 * V_50 )
{
struct V_184 * V_187 ;
struct V_34 * V_161 ;
int V_48 = - V_56 ;
int V_45 ;
V_187 = F_12 ( sizeof( struct V_184 ) ,
V_54 ) ;
if ( ! V_187 )
return - V_56 ;
V_50 -> V_185 = V_187 ;
F_76 ( & V_187 -> V_188 ) ;
F_9 ( L_27 , F_77 ( V_189 ) ) ;
for ( V_45 = 0 ; V_45 < F_77 ( V_189 ) ; V_45 ++ ) {
F_9 ( L_28 , V_189 [ V_45 ] . V_166 ) ;
V_161 = F_68 ( & V_189 [ V_45 ] ) ;
if ( F_17 ( V_161 ) ) {
V_48 = F_18 ( V_161 ) ;
F_13 ( L_29 ,
V_189 [ V_45 ] . V_166 ) ;
goto V_190;
}
V_161 -> V_50 = V_50 ;
F_9 ( L_30 , V_189 [ V_45 ] . V_166 ) ;
V_48 = F_78 ( & V_161 -> V_37 ) ;
F_9 ( L_31 ,
V_161 -> V_37 . V_165 , V_48 ) ;
if ( F_25 ( V_48 != 0 ) ) {
F_13 ( L_32 ,
V_161 -> V_37 . V_165 ) ;
F_22 ( V_161 ) ;
goto V_190;
} else {
F_79 ( & V_161 -> V_186 ,
& V_187 -> V_188 ) ;
F_9 ( L_33 ,
V_161 -> V_37 . V_165 ) ;
}
}
return 0 ;
V_190:
F_71 ( V_50 ) ;
return V_48 ;
}
