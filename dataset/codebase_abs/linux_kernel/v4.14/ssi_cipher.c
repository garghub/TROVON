static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
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
if ( F_2 ( V_3 == V_14 || V_3 == V_15 ) )
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
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
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
F_9 ( L_1 ,
V_2 , F_10 ( V_33 ) ) ;
V_2 -> V_8 = V_35 -> V_8 ;
V_2 -> V_4 = V_35 -> V_4 ;
V_2 -> V_50 = V_35 -> V_50 ;
V_47 = & V_2 -> V_50 -> V_51 -> V_47 ;
V_2 -> V_52 . V_53 = F_11 ( V_49 , V_54 | V_55 ) ;
if ( ! V_2 -> V_52 . V_53 ) {
F_12 ( L_2 ) ;
V_48 = - V_56 ;
}
F_9 ( L_3 ,
V_2 -> V_52 . V_53 ) ;
V_2 -> V_52 . V_57 = F_13 ( V_47 , ( void * ) V_2 -> V_52 . V_53 ,
V_49 ,
V_58 ) ;
if ( F_14 ( V_47 , V_2 -> V_52 . V_57 ) ) {
F_12 ( L_4 ,
V_49 , V_2 -> V_52 . V_53 ) ;
return - V_56 ;
}
F_9 ( L_5 ,
V_49 , V_2 -> V_52 . V_53 ,
V_2 -> V_52 . V_57 ) ;
if ( V_2 -> V_8 == V_10 ) {
V_2 -> V_59 = F_15 ( L_6 , 0 , 0 ) ;
if ( F_16 ( V_2 -> V_59 ) ) {
F_12 ( L_7 ) ;
return F_17 ( V_2 -> V_59 ) ;
}
}
return V_48 ;
}
static void F_18 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
struct V_46 * V_47 = & V_2 -> V_50 -> V_51 -> V_47 ;
unsigned int V_49 = F_5 ( V_33 ) ;
F_9 ( L_8 ,
F_8 ( V_33 ) , F_10 ( V_33 ) ) ;
if ( V_2 -> V_8 == V_10 ) {
F_19 ( V_2 -> V_59 ) ;
V_2 -> V_59 = NULL ;
}
F_20 ( V_47 , V_2 -> V_52 . V_57 , V_49 ,
V_58 ) ;
F_9 ( L_9 ,
V_2 -> V_52 . V_57 ) ;
F_21 ( V_2 -> V_52 . V_53 ) ;
F_9 ( L_10 , V_2 -> V_52 . V_53 ) ;
}
static int F_22 ( const T_2 * V_53 , unsigned int V_60 )
{
struct V_61 * V_62 = (struct V_61 * ) V_53 ;
if ( F_23 ( ( memcmp ( ( T_2 * ) V_62 -> V_63 , ( T_2 * ) V_62 -> V_64 , sizeof( V_62 -> V_63 ) ) == 0 ) ||
( memcmp ( ( T_2 * ) V_62 -> V_65 , ( T_2 * ) V_62 -> V_64 , sizeof( V_62 -> V_65 ) ) == 0 ) ) ) {
return - V_66 ;
}
return 0 ;
}
static enum V_67 F_24 ( int V_68 )
{
switch ( V_68 ) {
case 0 :
return V_69 ;
case 1 :
return V_70 ;
case 2 :
return V_71 ;
case 3 :
return V_72 ;
}
return V_73 ;
}
static inline void
F_25 (
struct V_32 * V_33 ,
struct V_74 * V_75 ,
unsigned int V_76 ,
unsigned int V_77 ,
struct V_78 V_79 [] ,
unsigned int * V_80 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
int V_8 = V_2 -> V_8 ;
int V_4 = V_2 -> V_4 ;
int V_81 = V_75 -> V_82 . V_83 ;
T_3 V_57 = V_2 -> V_52 . V_57 ;
unsigned int V_84 = V_2 -> V_60 ;
T_3 V_85 = V_75 -> V_82 . V_85 ;
unsigned int V_86 = V_77 ;
struct V_34 * V_35 = F_6 ( V_33 -> V_36 , struct V_34 , V_37 ) ;
if ( ( V_35 -> V_37 . V_38 & V_87 ) == V_88 )
V_86 = 512 ;
if ( ( V_35 -> V_37 . V_38 & V_87 ) == V_89 )
V_86 = 4096 ;
switch ( V_8 ) {
case V_27 :
case V_23 :
case V_25 :
case V_24 :
F_26 ( & V_79 [ * V_80 ] ) ;
F_27 ( & V_79 [ * V_80 ] , V_90 , V_85 , V_76 ,
V_91 ) ;
F_28 ( & V_79 [ * V_80 ] , V_81 ) ;
F_29 ( & V_79 [ * V_80 ] , V_4 ) ;
F_30 ( & V_79 [ * V_80 ] , V_8 ) ;
if ( ( V_8 == V_25 ) ||
( V_8 == V_24 ) ) {
F_31 ( & V_79 [ * V_80 ] , V_92 ) ;
} else {
F_31 ( & V_79 [ * V_80 ] , V_93 ) ;
}
( * V_80 ) ++ ;
case V_26 :
F_26 ( & V_79 [ * V_80 ] ) ;
F_30 ( & V_79 [ * V_80 ] , V_8 ) ;
F_28 ( & V_79 [ * V_80 ] , V_81 ) ;
if ( V_4 == V_5 ) {
if ( F_32 ( V_33 ) ) {
F_33 ( & V_79 [ * V_80 ] ,
V_2 -> V_94 . V_95 ) ;
} else {
F_27 ( & V_79 [ * V_80 ] , V_90 ,
V_57 , ( ( V_84 == 24 ) ?
V_96 :
V_84 ) , V_91 ) ;
}
F_34 ( & V_79 [ * V_80 ] , V_84 ) ;
} else {
F_27 ( & V_79 [ * V_80 ] , V_90 , V_57 ,
V_84 , V_91 ) ;
F_35 ( & V_79 [ * V_80 ] , V_84 ) ;
}
F_29 ( & V_79 [ * V_80 ] , V_4 ) ;
F_31 ( & V_79 [ * V_80 ] , V_97 ) ;
( * V_80 ) ++ ;
break;
case V_9 :
case V_10 :
case V_11 :
F_26 ( & V_79 [ * V_80 ] ) ;
F_30 ( & V_79 [ * V_80 ] , V_8 ) ;
F_28 ( & V_79 [ * V_80 ] , V_81 ) ;
if ( F_32 ( V_33 ) ) {
F_33 ( & V_79 [ * V_80 ] ,
V_2 -> V_94 . V_95 ) ;
} else {
F_27 ( & V_79 [ * V_80 ] , V_90 , V_57 ,
( V_84 / 2 ) , V_91 ) ;
}
F_34 ( & V_79 [ * V_80 ] , ( V_84 / 2 ) ) ;
F_29 ( & V_79 [ * V_80 ] , V_4 ) ;
F_31 ( & V_79 [ * V_80 ] , V_97 ) ;
( * V_80 ) ++ ;
F_26 ( & V_79 [ * V_80 ] ) ;
F_30 ( & V_79 [ * V_80 ] , V_8 ) ;
F_28 ( & V_79 [ * V_80 ] , V_81 ) ;
if ( F_32 ( V_33 ) ) {
F_33 ( & V_79 [ * V_80 ] ,
V_2 -> V_94 . V_98 ) ;
} else {
F_27 ( & V_79 [ * V_80 ] , V_90 ,
( V_57 + ( V_84 / 2 ) ) ,
( V_84 / 2 ) , V_91 ) ;
}
F_36 ( & V_79 [ * V_80 ] , V_86 ) ;
F_29 ( & V_79 [ * V_80 ] , V_99 ) ;
F_34 ( & V_79 [ * V_80 ] , ( V_84 / 2 ) ) ;
F_31 ( & V_79 [ * V_80 ] , V_100 ) ;
( * V_80 ) ++ ;
F_26 ( & V_79 [ * V_80 ] ) ;
F_31 ( & V_79 [ * V_80 ] , V_92 ) ;
F_30 ( & V_79 [ * V_80 ] , V_8 ) ;
F_28 ( & V_79 [ * V_80 ] , V_81 ) ;
F_34 ( & V_79 [ * V_80 ] , ( V_84 / 2 ) ) ;
F_29 ( & V_79 [ * V_80 ] , V_4 ) ;
F_27 ( & V_79 [ * V_80 ] , V_90 , V_85 ,
V_101 , V_91 ) ;
( * V_80 ) ++ ;
break;
default:
F_12 ( L_11 , V_8 ) ;
F_37 () ;
}
}
static inline void F_38 (
struct V_32 * V_33 ,
struct V_74 * V_75 ,
unsigned int V_76 ,
struct V_78 V_79 [] ,
unsigned int * V_80 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
int V_81 = V_75 -> V_82 . V_83 ;
F_26 ( & V_79 [ * V_80 ] ) ;
F_30 ( & V_79 [ * V_80 ] , V_2 -> V_8 ) ;
F_28 ( & V_79 [ * V_80 ] , V_81 ) ;
F_27 ( & V_79 [ * V_80 ] , V_90 , V_2 -> V_52 . V_57 ,
V_102 , V_91 ) ;
F_29 ( & V_79 [ * V_80 ] , V_2 -> V_4 ) ;
F_31 ( & V_79 [ * V_80 ] , V_97 ) ;
( * V_80 ) ++ ;
F_26 ( & V_79 [ * V_80 ] ) ;
F_27 ( & V_79 [ * V_80 ] , V_90 ,
( V_2 -> V_52 . V_57 + V_102 ) ,
V_103 , V_91 ) ;
F_39 ( & V_79 [ * V_80 ] , V_2 -> V_104 ) ;
F_29 ( & V_79 [ * V_80 ] , V_2 -> V_4 ) ;
F_30 ( & V_79 [ * V_80 ] , V_2 -> V_8 ) ;
F_28 ( & V_79 [ * V_80 ] , V_81 ) ;
F_31 ( & V_79 [ * V_80 ] , V_93 ) ;
( * V_80 ) ++ ;
F_26 ( & V_79 [ * V_80 ] ) ;
F_27 ( & V_79 [ * V_80 ] , V_90 , V_75 -> V_82 . V_85 ,
V_76 , V_91 ) ;
F_28 ( & V_79 [ * V_80 ] , V_81 ) ;
F_29 ( & V_79 [ * V_80 ] , V_2 -> V_4 ) ;
F_30 ( & V_79 [ * V_80 ] , V_2 -> V_8 ) ;
F_31 ( & V_79 [ * V_80 ] , V_92 ) ;
( * V_80 ) ++ ;
}
static inline void
F_40 (
struct V_32 * V_33 ,
struct V_74 * V_75 ,
struct V_105 * V_106 , struct V_105 * V_107 ,
unsigned int V_77 ,
void * V_108 ,
struct V_78 V_79 [] ,
unsigned int * V_80 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
unsigned int V_4 = V_2 -> V_4 ;
switch ( V_2 -> V_4 ) {
case V_5 :
V_4 = V_109 ;
break;
case V_13 :
V_4 = V_110 ;
break;
#if V_16
case V_17 :
V_4 = V_111 ;
break;
#endif
default:
F_12 ( L_12 , V_4 ) ;
return;
}
if ( F_2 ( V_75 -> V_112 == V_113 ) ) {
F_9 ( L_13 ,
F_41 ( V_107 ) , V_77 ) ;
F_9 ( L_13 ,
F_41 ( V_106 ) , V_77 ) ;
F_26 ( & V_79 [ * V_80 ] ) ;
F_27 ( & V_79 [ * V_80 ] , V_90 , F_41 ( V_107 ) ,
V_77 , V_91 ) ;
F_42 ( & V_79 [ * V_80 ] , F_41 ( V_106 ) ,
V_77 , V_91 , ( ! V_108 ? 0 : 1 ) ) ;
if ( V_108 )
F_43 ( & V_79 [ * V_80 ] ) ;
F_29 ( & V_79 [ * V_80 ] , V_4 ) ;
( * V_80 ) ++ ;
} else {
F_9 ( L_14
L_15 ,
V_75 -> V_114 . V_115 ,
V_75 -> V_114 . V_116 ,
( unsigned int ) V_2 -> V_50 -> V_117 ) ;
F_26 ( & V_79 [ * V_80 ] ) ;
F_27 ( & V_79 [ * V_80 ] , V_90 ,
V_75 -> V_114 . V_115 ,
V_75 -> V_114 . V_116 , V_91 ) ;
F_44 ( & V_79 [ * V_80 ] ,
V_2 -> V_50 -> V_117 ,
V_75 -> V_114 . V_116 ) ;
F_29 ( & V_79 [ * V_80 ] , V_118 ) ;
( * V_80 ) ++ ;
F_26 ( & V_79 [ * V_80 ] ) ;
F_27 ( & V_79 [ * V_80 ] , V_119 ,
V_2 -> V_50 -> V_117 ,
V_75 -> V_120 , V_91 ) ;
if ( V_75 -> V_121 == 0 ) {
F_9 ( L_16
L_17 ,
( unsigned int ) V_2 -> V_50 -> V_117 ,
( unsigned int ) V_2 -> V_50 -> V_117 ) ;
F_45 ( & V_79 [ * V_80 ] ,
V_2 -> V_50 -> V_117 ,
V_75 -> V_120 , V_91 ,
( ! V_108 ? 0 : 1 ) ) ;
} else {
F_9 ( L_18
L_19 ,
( unsigned int ) V_2 -> V_50 -> V_117 ,
( unsigned int ) V_2 -> V_50 -> V_117 +
( T_1 ) V_122 *
V_75 -> V_123 ) ;
F_45 ( & V_79 [ * V_80 ] ,
( V_2 -> V_50 -> V_117 +
( V_122 *
V_75 -> V_120 ) ) ,
V_75 -> V_124 , V_91 ,
( ! V_108 ? 0 : 1 ) ) ;
}
if ( V_108 )
F_43 ( & V_79 [ * V_80 ] ) ;
F_29 ( & V_79 [ * V_80 ] , V_4 ) ;
( * V_80 ) ++ ;
}
}
static int F_46 ( struct V_46 * V_47 ,
struct V_1 * V_2 ,
struct V_74 * V_75 ,
struct V_105 * V_106 ,
struct V_105 * V_107 ,
unsigned int V_76 ,
void * V_108 ,
void T_4 * V_125 )
{
int V_126 = 0 ;
T_1 V_127 ;
struct V_128 * V_129 = (struct V_128 * ) V_108 ;
F_47 ( V_47 , V_75 , V_76 , V_107 , V_106 ) ;
V_127 = V_2 -> V_50 -> V_127 ;
if ( V_2 -> V_4 == V_118 && V_2 -> V_50 -> V_127 > 0 )
V_2 -> V_50 -> V_127 -- ;
if ( V_108 ) {
if ( V_75 -> V_82 . V_83 == V_130 ) {
memcpy ( V_129 -> V_131 , V_75 -> V_132 , V_76 ) ;
F_21 ( V_75 -> V_132 ) ;
} else {
F_48 ( V_129 -> V_131 , V_129 -> V_106 ,
( V_129 -> V_77 - V_76 ) ,
V_76 , 0 ) ;
}
F_49 ( V_108 , V_126 ) ;
return 0 ;
}
return V_126 ;
}
static int F_50 (
struct V_32 * V_33 ,
struct V_74 * V_75 ,
struct V_105 * V_106 , struct V_105 * V_107 ,
unsigned int V_77 ,
void * V_131 ,
unsigned int V_76 ,
void * V_108 ,
enum V_133 V_81 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
struct V_46 * V_47 = & V_2 -> V_50 -> V_51 -> V_47 ;
struct V_78 V_79 [ V_134 ] ;
struct V_135 V_136 = {} ;
int V_48 , V_137 = 0 , V_138 = 0 ;
F_9 ( L_20 ,
( ( V_81 == V_139 ) ? L_21 : L_22 ) ,
V_108 , V_131 , V_77 ) ;
if ( F_23 ( F_3 ( V_2 , V_77 ) ) ) {
F_12 ( L_23 , V_77 ) ;
F_51 ( V_33 , V_140 ) ;
V_48 = - V_19 ;
goto V_141;
}
if ( V_77 == 0 ) {
V_48 = 0 ;
goto V_141;
}
if ( ( ( V_77 % V_22 ) == 0 ) && ( V_2 -> V_8 == V_23 ) ) {
V_2 -> V_8 = V_27 ;
V_138 = 1 ;
}
V_136 . V_142 = ( void * ) V_143 ;
V_136 . V_144 = ( void * ) V_108 ;
#ifdef F_52
V_136 . V_83 = ( V_81 == V_130 ) ?
V_145 : V_146 ;
#endif
V_75 -> V_82 . V_83 = V_81 ;
V_48 = F_53 ( V_2 -> V_50 , V_75 , V_76 , V_77 , V_131 , V_107 , V_106 ) ;
if ( F_23 ( V_48 != 0 ) ) {
F_12 ( L_24 ) ;
goto V_141;
}
#if V_16
if ( V_2 -> V_4 == V_17 )
F_38 ( V_33 , V_75 , V_76 ,
V_79 , & V_137 ) ;
else
#endif
F_25 ( V_33 , V_75 , V_76 , V_77 ,
V_79 , & V_137 ) ;
F_40 ( V_33 , V_75 , V_106 , V_107 , V_77 , V_108 ,
V_79 , & V_137 ) ;
if ( V_75 -> V_147 ) {
V_136 . V_148 [ 0 ] = V_75 -> V_82 . V_85 ;
V_136 . V_149 = 1 ;
V_136 . V_150 = V_76 ;
}
V_48 = F_54 ( V_2 -> V_50 , & V_136 , V_79 , V_137 , ( ! V_108 ) ? 0 : 1 ) ;
if ( V_108 ) {
if ( F_23 ( V_48 != - V_151 ) ) {
F_47 ( V_47 , V_75 , V_76 , V_107 , V_106 ) ;
}
} else {
if ( V_48 != 0 ) {
F_47 ( V_47 , V_75 , V_76 , V_107 , V_106 ) ;
} else {
V_48 = F_46 ( V_47 , V_2 , V_75 , V_106 ,
V_107 , V_76 , NULL ,
V_2 -> V_50 -> V_125 ) ;
}
}
V_141:
if ( V_138 != 0 )
V_2 -> V_8 = V_23 ;
if ( V_48 != - V_151 )
F_21 ( V_75 -> V_132 ) ;
return V_48 ;
}
static void V_143 ( struct V_46 * V_47 , void * V_136 , void T_4 * V_125 )
{
struct V_128 * V_108 = (struct V_128 * ) V_136 ;
struct V_74 * V_75 = F_55 ( V_108 ) ;
struct V_152 * V_33 = F_56 ( V_108 ) ;
struct V_1 * V_2 = F_57 ( V_33 ) ;
unsigned int V_76 = F_58 ( V_33 ) ;
F_46 ( V_47 , V_2 , V_75 , V_108 -> V_106 , V_108 -> V_107 ,
V_76 , V_108 , V_125 ) ;
}
static int F_59 ( struct V_32 * V_33 )
{
struct V_153 * V_154 = & V_33 -> V_155 ;
V_154 -> V_156 = sizeof( struct V_74 ) ;
return F_7 ( V_33 ) ;
}
static int F_60 ( struct V_152 * V_33 ,
const T_2 * V_53 ,
unsigned int V_60 )
{
return F_61 ( F_62 ( V_33 ) , V_53 , V_60 ) ;
}
static int F_63 ( struct V_128 * V_129 )
{
struct V_152 * V_157 = F_56 ( V_129 ) ;
struct V_32 * V_33 = F_62 ( V_157 ) ;
struct V_74 * V_75 = F_55 ( V_129 ) ;
unsigned int V_76 = F_58 ( V_157 ) ;
V_75 -> V_147 = false ;
return F_50 ( V_33 , V_75 , V_129 -> V_106 , V_129 -> V_107 , V_129 -> V_77 , V_129 -> V_131 , V_76 , ( void * ) V_129 , V_139 ) ;
}
static int F_64 ( struct V_128 * V_129 )
{
struct V_152 * V_157 = F_56 ( V_129 ) ;
struct V_32 * V_33 = F_62 ( V_157 ) ;
struct V_74 * V_75 = F_55 ( V_129 ) ;
unsigned int V_76 = F_58 ( V_157 ) ;
V_75 -> V_132 = F_11 ( V_76 , V_54 ) ;
if ( ! V_75 -> V_132 )
return - V_56 ;
F_48 ( V_75 -> V_132 , V_129 -> V_107 ,
( V_129 -> V_77 - V_76 ) , V_76 , 0 ) ;
V_75 -> V_147 = false ;
return F_50 ( V_33 , V_75 , V_129 -> V_106 , V_129 -> V_107 , V_129 -> V_77 , V_129 -> V_131 , V_76 , ( void * ) V_129 , V_130 ) ;
}
static
struct V_34 * F_65 ( struct V_158 * V_159 )
{
struct V_34 * V_160 ;
struct V_37 * V_45 ;
V_160 = F_66 ( sizeof( * V_160 ) , V_54 ) ;
if ( ! V_160 ) {
F_12 ( L_25 ) ;
return F_67 ( - V_56 ) ;
}
V_45 = & V_160 -> V_37 ;
snprintf ( V_45 -> V_161 , V_162 , L_26 , V_159 -> V_163 ) ;
snprintf ( V_45 -> V_164 , V_162 , L_26 ,
V_159 -> V_165 ) ;
V_45 -> V_166 = V_167 ;
V_45 -> V_168 = V_169 ;
V_45 -> V_170 = V_159 -> V_171 ;
V_45 -> V_172 = 0 ;
V_45 -> V_173 = sizeof( struct V_1 ) ;
V_45 -> V_174 = F_59 ;
V_45 -> V_175 = F_18 ;
V_45 -> V_176 = & V_177 ;
V_45 -> V_41 = V_159 -> V_178 ;
V_45 -> V_38 = V_179 | V_180 |
V_159 -> type ;
V_160 -> V_8 = V_159 -> V_8 ;
V_160 -> V_4 = V_159 -> V_4 ;
return V_160 ;
}
int F_68 ( struct V_181 * V_50 )
{
struct V_34 * V_160 , * V_182 ;
struct V_183 * V_184 =
V_50 -> V_184 ;
struct V_46 * V_47 ;
V_47 = & V_50 -> V_51 -> V_47 ;
if ( V_184 ) {
F_69 (t_alg, n,
&blkcipher_handle->blkcipher_alg_list,
entry) {
F_70 ( & V_160 -> V_37 ) ;
F_71 ( & V_160 -> V_185 ) ;
F_21 ( V_160 ) ;
}
F_21 ( V_184 ) ;
V_50 -> V_184 = NULL ;
}
return 0 ;
}
int F_72 ( struct V_181 * V_50 )
{
struct V_183 * V_186 ;
struct V_34 * V_160 ;
int V_48 = - V_56 ;
int V_45 ;
V_186 = F_11 ( sizeof( * V_186 ) , V_54 ) ;
if ( ! V_186 )
return - V_56 ;
V_50 -> V_184 = V_186 ;
F_73 ( & V_186 -> V_187 ) ;
F_9 ( L_27 , F_74 ( V_188 ) ) ;
for ( V_45 = 0 ; V_45 < F_74 ( V_188 ) ; V_45 ++ ) {
F_9 ( L_28 , V_188 [ V_45 ] . V_165 ) ;
V_160 = F_65 ( & V_188 [ V_45 ] ) ;
if ( F_16 ( V_160 ) ) {
V_48 = F_17 ( V_160 ) ;
F_12 ( L_29 ,
V_188 [ V_45 ] . V_165 ) ;
goto V_189;
}
V_160 -> V_50 = V_50 ;
F_9 ( L_30 , V_188 [ V_45 ] . V_165 ) ;
V_48 = F_75 ( & V_160 -> V_37 ) ;
F_9 ( L_31 ,
V_160 -> V_37 . V_164 , V_48 ) ;
if ( F_23 ( V_48 != 0 ) ) {
F_12 ( L_32 ,
V_160 -> V_37 . V_164 ) ;
F_21 ( V_160 ) ;
goto V_189;
} else {
F_76 ( & V_160 -> V_185 ,
& V_186 -> V_187 ) ;
F_9 ( L_33 ,
V_160 -> V_37 . V_164 ) ;
}
}
return 0 ;
V_189:
F_68 ( V_50 ) ;
return V_48 ;
}
