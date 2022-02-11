static inline void F_1 ( struct V_1 * V_2 ) {
F_2 ( L_1 ,
( int ) V_2 ,
( int ) V_2 -> V_3 -> V_4 [ 1 ] , ( int ) V_2 -> V_3 -> V_4 [ 0 ]
) ;
F_2 ( L_2 ,
F_3 ( V_2 -> V_3 , V_2 -> V_5 ) ,
F_4 ( V_2 -> V_3 , V_2 -> V_6 ) ,
F_4 ( V_2 -> V_3 , V_2 -> V_7 )
) ;
}
static inline void F_5 ( struct V_8 * V_9 )
{
char * V_10 = NULL ;
switch ( V_9 -> V_11 [ 0 ] ) {
case V_12 : V_10 = L_3 ; break;
case V_13 : V_10 = L_4 ; break;
case V_14 : V_10 = L_5 ; break;
case V_15 : V_10 = L_6 ; break;
case V_16 : V_10 = L_7 ; break;
case V_17 : V_10 = L_8 ; break;
case V_18 : V_10 = L_9 ; break;
case V_19 : V_10 = L_10 ; break;
case V_20 : V_10 = L_11 ; break;
case V_21 : V_10 = L_12 ; break;
case V_22 : V_10 = L_13 ; break;
case V_23 : V_10 = L_14 ; break;
case V_24 : V_10 = L_15 ; break;
case V_25 : V_10 = L_16 ; break;
case V_26 : V_10 = L_17 ; break;
case V_27 : V_10 = L_18 ; break;
case V_28 : V_10 = L_19 ; break;
case V_29 : V_10 = L_20 ; break;
case V_30 : V_10 = L_21 ; break;
case V_31 : V_10 = L_22 ; break;
case V_32 : V_10 = L_23 ; break;
case V_33 : V_10 = L_24 ; break;
case V_34 : V_10 = L_25 ; break;
case V_35 : V_10 = L_26 ; break;
case V_36 : V_10 = L_27 ; break;
case V_37 : V_10 = L_28 ; break;
case V_38 : V_10 = L_29 ; break;
case V_39 : V_10 = L_30 ; break;
case V_40 : V_10 = L_31 ; break;
case V_41 : V_10 = L_32 ; break;
case V_42 : V_10 = L_33 ; break;
case V_43 : V_10 = L_34 ; break;
case V_44 : V_10 = L_35 ; break;
case V_45 : V_10 = L_36 ; break;
case V_46 : V_10 = L_37 ; break;
case V_47 : V_10 = L_38 ; break;
case V_48 : V_10 = L_39 ; break;
case V_49 : V_10 = L_40 ; break;
case V_50 : V_10 = L_41 ; break;
case V_51 : V_10 = L_42 ; break;
case V_52 : V_10 = L_43 ; break;
case V_53 : V_10 = L_44 ; break;
case V_54 : V_10 = L_45 ; break;
case V_55 : V_10 = L_46 ; break;
case V_56 : V_10 = L_47 ; break;
case V_57 : V_10 = L_48 ; break;
case V_58 : V_10 = L_49 ; break;
case V_59 : V_10 = L_50 ; break;
case V_60 : V_10 = L_51 ; break;
case V_61 : V_10 = L_52 ; break;
case V_62 : V_10 = L_53 ; break;
case V_63 : V_10 = L_54 ; break;
case V_64 : V_10 = L_55 ; break;
case V_65 : V_10 = L_56 ; break;
case V_66 : V_10 = L_57 ; break;
case V_67 : V_10 = L_58 ; break;
case V_68 : V_10 = L_59 ; break;
case V_69 : V_10 = L_60 ; break;
case V_70 : V_10 = L_61 ; break;
case V_71 : V_10 = L_62 ; break;
case V_72 : V_10 = L_63 ; break;
case V_73 : V_10 = L_64 ; break;
case V_74 : V_10 = L_65 ; break;
case V_75 : V_10 = L_66 ; break;
default:
F_2 ( L_67 ) ;
goto V_76;
break;
}
F_2 ( L_68 , V_10 , V_9 -> V_77 ) ;
V_76:
F_2 ( L_69 ,
V_9 -> V_11 [ 0 ] , V_9 -> V_11 [ 1 ] , V_9 -> V_11 [ 2 ] , V_9 -> V_11 [ 3 ] , V_9 -> V_11 [ 4 ] , V_9 -> V_11 [ 5 ] ,
V_9 -> V_11 [ 6 ] , V_9 -> V_11 [ 7 ] , V_9 -> V_11 [ 8 ] , V_9 -> V_11 [ 9 ] ) ;
}
static inline void F_5 ( struct V_8 * V_78 )
{
}
static inline void F_1 ( struct V_1 * V_78 )
{
}
static inline void F_6 ( struct V_1 * V_2 ) {
F_7 () ;
F_1 ( V_2 ) ;
F_8 ( V_2 -> V_79 ) ;
}
static int F_9 ( struct V_80 * V_81 )
{
V_81 -> V_82 = 0x24 ;
return 0 ;
}
static int F_10 ( struct V_80 * V_81 )
{
F_11 ( V_81 -> V_83 , ( 512 - 1 ) ) ;
return 0 ;
}
static int F_12 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) ( V_9 -> V_84 -> V_85 -> V_86 [ 0 ] ) ;
F_7 () ;
F_6 ( V_2 ) ;
return V_87 ;
}
static int F_13 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) ( V_9 -> V_84 -> V_85 -> V_86 [ 0 ] ) ;
int V_88 ;
F_7 () ;
F_1 ( V_2 ) ;
V_88 = F_14 ( V_2 -> V_3 , V_2 -> V_89 ) ;
if ( V_88 == 0 ) {
V_88 = F_15 ( V_2 -> V_3 ) ;
F_16 ( V_2 -> V_3 ) ;
}
return V_88 ? V_87 : V_90 ;
}
static inline
void F_17 ( struct V_79 * V_91 ,
int V_92 ,
void * V_93 ,
unsigned V_94 ,
T_1 V_95 )
{
int V_96 ;
F_18 () ;
F_19 ( V_91 ,
V_97 -> V_98 -> V_3 ,
V_92 ,
V_93 ,
V_94 ,
V_95 ,
V_97
) ;
V_96 = F_20 ( V_91 , V_99 ) ;
if ( F_21 ( V_96 ) ) {
F_22 ( L_70 , ( int ) V_96 ) ;
V_97 -> V_9 -> V_88 = V_100 << 16 ;
F_23 ( V_91 ) ;
}
}
static void F_23 ( struct V_79 * V_91 )
{
F_18 () ;
if ( F_24 ( V_97 -> V_101 != NULL ) )
V_97 -> V_101 ( V_97 -> V_9 ) ;
}
static void F_25 ( struct V_79 * V_91 )
{
F_18 () ;
V_97 -> V_9 -> V_88 &= V_102 ;
V_97 -> V_9 -> V_88 |= ( unsigned ) ( * V_97 -> V_103 ) << 1 ;
F_23 ( V_91 ) ;
}
static void F_26 ( struct V_79 * V_91 )
{
F_18 () ;
F_17 ( V_91 ,
F_4 ( V_97 -> V_98 -> V_3 ,
V_97 -> V_98 -> V_6 ) ,
V_97 -> V_103 ,
1 ,
F_25 ) ;
}
static void F_27 ( struct V_79 * V_91 )
{
int V_104 = V_91 -> V_104 ;
F_18 () ;
if ( V_97 -> V_105 != V_91 -> V_106 ) {
F_28 ( V_97 -> V_9 , V_97 -> V_105 -
V_91 -> V_106 ) ;
} else if ( F_21 ( V_104 ) ) {
V_97 -> V_9 -> V_88 = ( V_104 == - V_107 ? V_108 : V_100 ) << 16 ;
}
F_26 ( V_91 ) ;
}
static void F_29 ( struct V_79 * V_91 )
{
int V_104 = V_91 -> V_104 ;
F_18 () ;
if ( F_21 ( V_104 ) ) {
if ( V_104 == - V_107 ) {
F_7 () ;
V_97 -> V_9 -> V_88 = V_108 << 16 ;
} else {
F_7 () ;
V_97 -> V_9 -> V_88 = V_100 << 16 ;
}
F_23 ( V_91 ) ;
return;
}
if ( V_97 -> V_9 -> V_11 [ 0 ] == V_14 ) {
F_17 ( V_91 ,
V_97 -> V_109 ,
V_97 -> V_9 -> V_110 ,
V_97 -> V_105 ,
F_27 ) ;
} else { if ( V_97 -> V_93 ) {
F_17 ( V_91 ,
V_97 -> V_109 ,
V_97 -> V_93 ,
V_97 -> V_105 ,
F_30 ( V_97 -> V_9 ) > 1 ?
V_111 : F_27 ) ;
} else {
F_26 ( V_91 ) ;
}
}
}
static void V_111 ( struct V_79 * V_91 )
{
struct V_112 * V_113 ;
int V_104 = V_91 -> V_104 ;
F_18 () ;
F_2 ( L_71 , V_97 -> V_114 ,
F_30 ( V_97 -> V_9 ) ) ;
if ( F_21 ( V_104 ) ) {
V_97 -> V_9 -> V_88 = ( V_104 == - V_107 ? V_108 : V_100 ) << 16 ;
F_23 ( V_91 ) ;
}
V_113 = F_31 ( V_97 -> V_9 ) ;
V_97 -> V_114 ++ ;
F_17 ( V_91 ,
V_97 -> V_109 ,
F_32 ( & V_113 [ V_97 -> V_114 ] ) ,
V_113 [ V_97 -> V_114 ] . V_94 ,
V_97 -> V_114 + 1 == F_30 ( V_97 -> V_9 ) ?
F_27 : V_111 ) ;
}
static void
F_33 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_92 ;
struct V_112 * V_113 ;
F_7 () ;
V_2 -> V_97 . V_98 = V_2 ;
V_2 -> V_97 . V_9 = V_9 ;
V_2 -> V_97 . V_114 = 0 ;
if ( ! F_34 ( V_9 ) ) {
V_2 -> V_97 . V_93 = NULL ;
V_2 -> V_97 . V_105 = 0 ;
return;
} else {
V_113 = F_31 ( V_9 ) ;
V_2 -> V_97 . V_93 = F_32 ( & V_113 [ 0 ] ) ;
V_2 -> V_97 . V_105 = V_113 [ 0 ] . V_94 ;
}
if ( ! memcmp ( V_9 -> V_11 , V_115 , V_116 )
) { V_92 = F_4 ( V_2 -> V_3 , V_2 -> V_7 ) ;
F_2 ( L_72 ,
( int ) V_2 -> V_7 ) ;
} else if ( F_35 ( V_9 -> V_11 [ 0 ] ) ) {
V_92 = F_4 ( V_2 -> V_3 , V_2 -> V_6 ) ;
F_2 ( L_73 ,
( int ) V_2 -> V_6 ) ;
} else {
F_2 ( L_74 ,
( int ) V_2 -> V_5 ) ;
V_92 = F_3 ( V_2 -> V_3 , V_2 -> V_5 ) ;
}
V_2 -> V_97 . V_109 = V_92 ;
}
static int
F_36 ( struct V_8 * V_9 , T_2 V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) ( V_9 -> V_84 -> V_85 -> V_86 [ 0 ] ) ;
int V_117 = 0 ;
int V_96 ;
F_7 () ;
F_5 ( V_9 ) ;
F_1 ( V_2 ) ;
if ( V_9 -> V_84 -> V_118 || V_9 -> V_84 -> V_119 || V_9 -> V_84 -> V_120 ) {
F_2 ( L_75 , ( int ) V_9 -> V_84 -> V_118 , ( int ) V_9 -> V_84 -> V_119 , ( int ) V_9 -> V_84 -> V_120 ) ;
F_2 ( L_76 ) ;
V_9 -> V_88 = V_121 << 16 ;
if( F_24 ( V_95 != NULL ) )
V_95 ( V_9 ) ;
goto V_76;
}
F_19 ( V_2 -> V_79 ,
V_2 -> V_3 ,
F_3 ( V_2 -> V_3 , V_2 -> V_5 ) ,
V_9 -> V_11 ,
V_9 -> V_77 ,
F_29 ,
& V_2 -> V_97
) ;
F_33 ( V_9 , V_2 ) ;
V_2 -> V_97 . V_101 = V_95 ;
V_96 = F_20 ( V_2 -> V_79 , V_99 ) ;
if( F_21 ( V_96 ) ) {
F_37 ( L_77 , ( int ) V_96 ) ;
V_9 -> V_88 = V_100 << 16 ;
if( F_24 ( V_95 != NULL ) )
V_95 ( V_9 ) ;
}
V_76:
return V_117 ;
}
static int F_38 ( struct V_122 * V_123 ,
const struct V_124 * V_119 )
{
int V_125 ;
int V_5 = - 1 ;
int V_126 [ 3 ] ;
int * V_127 = V_126 ;
int V_128 = - V_129 ;
struct V_1 * V_130 ;
struct V_131 * V_132 = F_39 ( V_123 ) ;
struct V_133 * V_134 ;
F_7 () ;
F_2 ( L_78 , ( int ) V_132 ) ;
F_2 ( L_79 ,
F_40 ( V_132 -> V_135 . V_136 ) ,
F_40 ( V_132 -> V_135 . V_137 ) ) ;
F_7 () ;
V_134 = V_123 -> V_138 ;
if ( V_134 -> V_2 . V_139 != V_140 ) {
F_41 ( L_80 ,
( int ) V_140 , ( int ) V_134 -> V_2 . V_139 ) ;
return - V_141 ;
}
for( V_125 = 0 ; V_125 < V_134 -> V_2 . V_139 ; V_125 ++ ) {
if ( ( V_134 -> V_142 [ V_125 ] . V_2 . V_143 &
V_144 ) != V_145 ) {
F_41 ( L_81 ,
( int ) V_134 -> V_142 [ V_125 ] . V_2 . V_146 ) ;
} else {
if ( V_134 -> V_142 [ V_125 ] . V_2 . V_146 &
V_147 )
* V_127 ++
= V_134 -> V_142 [ V_125 ] . V_2 . V_146 &
V_148 ;
else {
if ( V_5 != - 1 ) {
F_41 ( L_82 ) ;
return - V_141 ;
}
V_5 = V_134 -> V_142 [ V_125 ] . V_2 . V_146 &
V_148 ;
}
}
}
if ( V_5 == - 1 ) {
F_41 ( L_83 ) ;
return - V_141 ;
}
V_130 = F_42 ( sizeof( struct V_1 ) , V_149 ) ;
if ( ! V_130 )
goto V_76;
V_130 -> V_79 = F_43 ( 0 , V_149 ) ;
if ( ! V_130 -> V_79 )
goto V_150;
V_130 -> V_97 . V_103 = F_44 ( 1 , V_149 ) ;
if ( ! V_130 -> V_97 . V_103 )
goto V_151;
V_130 -> V_3 = V_132 ;
V_130 -> V_89 = V_123 ;
V_130 -> V_5 = V_5 ;
V_130 -> V_6 = V_126 [ 0 ] ;
V_130 -> V_7 = V_126 [ 1 ] ;
if ( V_130 -> V_5 != V_152 )
F_41 ( L_84 ,
( int ) V_130 -> V_5 ) ;
if ( V_130 -> V_6 != V_153 )
F_41 ( L_85 ,
( int ) V_130 -> V_6 ) ;
if ( V_130 -> V_7 != V_154 )
F_41 ( L_86 ,
( int ) V_130 -> V_7 ) ;
V_130 -> V_85 = F_45 ( & V_155 ,
sizeof( V_130 ) ) ;
if ( ! V_130 -> V_85 )
goto V_156;
V_130 -> V_85 -> V_86 [ 0 ] = ( unsigned long ) V_130 ;
if ( F_46 ( V_130 -> V_85 , & V_132 -> V_132 ) ) {
V_128 = - V_157 ;
goto V_158;
}
F_47 ( V_130 -> V_85 ) ;
F_48 ( V_123 , V_130 ) ;
return 0 ;
V_158:
F_49 ( V_130 -> V_85 ) ;
V_156:
F_50 ( V_130 -> V_97 . V_103 ) ;
V_151:
F_51 ( V_130 -> V_79 ) ;
V_150:
F_50 ( V_130 ) ;
V_76:
return V_128 ;
}
static void F_52 ( struct V_122 * V_123 )
{
struct V_1 * V_2 = F_53 ( V_123 ) ;
F_48 ( V_123 , NULL ) ;
F_8 ( V_2 -> V_79 ) ;
F_54 ( V_2 -> V_85 ) ;
F_49 ( V_2 -> V_85 ) ;
F_51 ( V_2 -> V_79 ) ;
F_50 ( V_2 -> V_97 . V_103 ) ;
F_50 ( V_2 ) ;
}
