static struct V_1 * F_1 ( struct V_2 * V_2 ,
struct V_3 * V_4 , T_1 V_5 , T_1 V_6 )
{
unsigned int V_7 = F_2 ( V_5 ) ;
unsigned int V_8 = F_2 ( V_6 ) ;
struct V_1 * V_9 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
F_4 (t, sitn->tunnels_r_l[h0 ^ h1]) {
if ( V_6 == V_9 -> V_13 . V_14 . V_15 &&
V_5 == V_9 -> V_13 . V_14 . V_16 &&
( ! V_4 || ! V_9 -> V_13 . V_17 || V_4 -> V_18 == V_9 -> V_13 . V_17 ) &&
( V_9 -> V_4 -> V_19 & V_20 ) )
return V_9 ;
}
F_4 (t, sitn->tunnels_r[h0]) {
if ( V_5 == V_9 -> V_13 . V_14 . V_16 &&
( ! V_4 || ! V_9 -> V_13 . V_17 || V_4 -> V_18 == V_9 -> V_13 . V_17 ) &&
( V_9 -> V_4 -> V_19 & V_20 ) )
return V_9 ;
}
F_4 (t, sitn->tunnels_l[h1]) {
if ( V_6 == V_9 -> V_13 . V_14 . V_15 &&
( ! V_4 || ! V_9 -> V_13 . V_17 || V_4 -> V_18 == V_9 -> V_13 . V_17 ) &&
( V_9 -> V_4 -> V_19 & V_20 ) )
return V_9 ;
}
V_9 = F_5 ( V_11 -> V_21 [ 0 ] ) ;
if ( ( V_9 != NULL ) && ( V_9 -> V_4 -> V_19 & V_20 ) )
return V_9 ;
return NULL ;
}
static struct V_1 T_2 * * F_6 ( struct V_10 * V_11 ,
struct V_22 * V_13 )
{
T_1 V_5 = V_13 -> V_14 . V_16 ;
T_1 V_6 = V_13 -> V_14 . V_15 ;
unsigned int V_23 = 0 ;
int V_24 = 0 ;
if ( V_5 ) {
V_24 |= 2 ;
V_23 ^= F_2 ( V_5 ) ;
}
if ( V_6 ) {
V_24 |= 1 ;
V_23 ^= F_2 ( V_6 ) ;
}
return & V_11 -> V_25 [ V_24 ] [ V_23 ] ;
}
static inline struct V_1 T_2 * * F_7 ( struct V_10 * V_11 ,
struct V_1 * V_9 )
{
return F_6 ( V_11 , & V_9 -> V_13 ) ;
}
static void F_8 ( struct V_10 * V_11 , struct V_1 * V_9 )
{
struct V_1 T_2 * * V_26 ;
struct V_1 * V_27 ;
for ( V_26 = F_7 ( V_11 , V_9 ) ;
( V_27 = F_9 ( * V_26 ) ) != NULL ;
V_26 = & V_27 -> V_28 ) {
if ( V_9 == V_27 ) {
F_10 ( * V_26 , V_9 -> V_28 ) ;
break;
}
}
}
static void F_11 ( struct V_10 * V_11 , struct V_1 * V_9 )
{
struct V_1 T_2 * * V_26 = F_7 ( V_11 , V_9 ) ;
F_10 ( V_9 -> V_28 , F_9 ( * V_26 ) ) ;
F_10 ( * V_26 , V_9 ) ;
}
static void F_12 ( struct V_3 * V_4 , struct V_10 * V_11 )
{
#ifdef F_13
struct V_1 * V_9 = F_14 ( V_4 ) ;
if ( V_9 -> V_4 == V_11 -> V_29 ) {
F_15 ( & V_9 -> V_30 . V_31 , F_16 ( 0x20020000 ) , 0 , 0 , 0 ) ;
V_9 -> V_30 . V_32 = 0 ;
V_9 -> V_30 . V_33 = 16 ;
V_9 -> V_30 . V_34 = 0 ;
} else {
struct V_1 * V_35 = F_14 ( V_11 -> V_29 ) ;
memcpy ( & V_9 -> V_30 , & V_35 -> V_30 , sizeof( V_9 -> V_30 ) ) ;
}
#endif
}
static int F_17 ( struct V_3 * V_4 )
{
struct V_1 * V_9 = F_14 ( V_4 ) ;
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
int V_36 ;
V_36 = F_19 ( V_4 ) ;
if ( V_36 < 0 )
goto V_37;
F_12 ( V_4 , V_11 ) ;
if ( ( V_38 V_39 ) V_9 -> V_13 . V_40 & V_41 )
V_4 -> V_42 |= V_43 ;
V_36 = F_20 ( V_4 ) ;
if ( V_36 < 0 )
goto V_37;
strcpy ( V_9 -> V_13 . V_44 , V_4 -> V_44 ) ;
V_4 -> V_45 = & V_46 ;
F_21 ( V_4 ) ;
F_11 ( V_11 , V_9 ) ;
return 0 ;
V_37:
return V_36 ;
}
static struct V_1 * F_22 ( struct V_2 * V_2 ,
struct V_22 * V_13 , int V_47 )
{
T_1 V_5 = V_13 -> V_14 . V_16 ;
T_1 V_6 = V_13 -> V_14 . V_15 ;
struct V_1 * V_9 , * V_48 ;
struct V_1 T_2 * * V_26 ;
struct V_3 * V_4 ;
char V_44 [ V_49 ] ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
for ( V_26 = F_6 ( V_11 , V_13 ) ;
( V_9 = F_9 ( * V_26 ) ) != NULL ;
V_26 = & V_9 -> V_28 ) {
if ( V_6 == V_9 -> V_13 . V_14 . V_15 &&
V_5 == V_9 -> V_13 . V_14 . V_16 &&
V_13 -> V_17 == V_9 -> V_13 . V_17 ) {
if ( V_47 )
return NULL ;
else
return V_9 ;
}
}
if ( ! V_47 )
goto V_50;
if ( V_13 -> V_44 [ 0 ] )
F_23 ( V_44 , V_13 -> V_44 , V_49 ) ;
else
strcpy ( V_44 , L_1 ) ;
V_4 = F_24 ( sizeof( * V_9 ) , V_44 , V_51 ) ;
if ( V_4 == NULL )
return NULL ;
F_25 ( V_4 , V_2 ) ;
V_48 = F_14 ( V_4 ) ;
V_48 -> V_13 = * V_13 ;
if ( F_17 ( V_4 ) < 0 )
goto V_52;
return V_48 ;
V_52:
F_26 ( V_4 ) ;
V_50:
return NULL ;
}
static struct V_53 *
F_27 ( struct V_1 * V_9 , T_1 V_54 )
{
struct V_53 * V_55 ;
F_28 (t->prl)
if ( V_55 -> V_54 == V_54 )
break;
return V_55 ;
}
static int F_29 ( struct V_1 * V_9 ,
struct V_56 T_3 * V_57 )
{
struct V_56 V_58 , * V_59 ;
struct V_53 * V_55 ;
unsigned int V_60 , V_61 = 0 , V_62 , V_63 ;
int V_64 = 0 ;
if ( F_30 ( & V_58 , V_57 , sizeof( V_58 ) ) )
return - V_65 ;
V_60 = V_58 . V_66 / sizeof( V_58 ) ;
if ( V_60 > 1 && V_58 . V_54 != F_16 ( V_67 ) )
V_60 = 1 ;
V_59 = ( V_60 <= 1 || F_31 ( V_68 ) ) ?
F_32 ( V_60 , sizeof( * V_59 ) , V_69 ) :
NULL ;
F_33 () ;
V_62 = V_9 -> V_70 < V_60 ? V_9 -> V_70 : V_60 ;
if ( ! V_59 ) {
V_59 = F_32 ( V_62 , sizeof( * V_59 ) , V_71 ) ;
if ( ! V_59 ) {
V_64 = - V_72 ;
goto V_37;
}
}
V_61 = 0 ;
F_28 (t->prl) {
if ( V_61 >= V_60 )
break;
if ( V_58 . V_54 != F_16 ( V_67 ) && V_55 -> V_54 != V_58 . V_54 )
continue;
V_59 [ V_61 ] . V_54 = V_55 -> V_54 ;
V_59 [ V_61 ] . V_19 = V_55 -> V_19 ;
V_61 ++ ;
if ( V_58 . V_54 != F_16 ( V_67 ) )
break;
}
V_37:
F_34 () ;
V_63 = sizeof( * V_59 ) * V_61 ;
V_64 = 0 ;
if ( ( V_63 && F_35 ( V_57 + 1 , V_59 , V_63 ) ) || F_36 ( V_63 , & V_57 -> V_66 ) )
V_64 = - V_65 ;
F_37 ( V_59 ) ;
return V_64 ;
}
static int
F_38 ( struct V_1 * V_9 , struct V_56 * V_57 , int V_73 )
{
struct V_53 * V_74 ;
int V_36 = 0 ;
if ( V_57 -> V_54 == F_16 ( V_67 ) )
return - V_75 ;
F_39 () ;
for ( V_74 = F_9 ( V_9 -> V_55 ) ; V_74 ; V_74 = F_9 ( V_74 -> V_28 ) ) {
if ( V_74 -> V_54 == V_57 -> V_54 ) {
if ( V_73 ) {
V_74 -> V_19 = V_57 -> V_19 ;
goto V_37;
}
V_36 = - V_76 ;
goto V_37;
}
}
if ( V_73 ) {
V_36 = - V_77 ;
goto V_37;
}
V_74 = F_40 ( sizeof( struct V_53 ) , V_69 ) ;
if ( ! V_74 ) {
V_36 = - V_78 ;
goto V_37;
}
V_74 -> V_28 = V_9 -> V_55 ;
V_74 -> V_54 = V_57 -> V_54 ;
V_74 -> V_19 = V_57 -> V_19 ;
V_9 -> V_70 ++ ;
F_10 ( V_9 -> V_55 , V_74 ) ;
V_37:
return V_36 ;
}
static void F_41 ( struct V_79 * V_80 )
{
struct V_53 * V_74 , * V_81 ;
V_74 = F_42 ( V_80 , struct V_53 , V_79 ) ;
do {
V_81 = F_43 ( V_74 -> V_28 , 1 ) ;
F_37 ( V_74 ) ;
V_74 = V_81 ;
} while ( V_74 );
}
static int
F_44 ( struct V_1 * V_9 , struct V_56 * V_57 )
{
struct V_53 * V_82 ;
struct V_53 T_2 * * V_74 ;
int V_36 = 0 ;
F_39 () ;
if ( V_57 && V_57 -> V_54 != F_16 ( V_67 ) ) {
for ( V_74 = & V_9 -> V_55 ;
( V_82 = F_9 ( * V_74 ) ) != NULL ;
V_74 = & V_82 -> V_28 ) {
if ( V_82 -> V_54 == V_57 -> V_54 ) {
* V_74 = V_82 -> V_28 ;
F_45 ( V_82 , V_79 ) ;
V_9 -> V_70 -- ;
goto V_37;
}
}
V_36 = - V_77 ;
} else {
V_82 = F_9 ( V_9 -> V_55 ) ;
if ( V_82 ) {
V_9 -> V_70 = 0 ;
F_46 ( & V_82 -> V_79 , F_41 ) ;
V_9 -> V_55 = NULL ;
}
}
V_37:
return V_36 ;
}
static int
F_47 ( struct V_83 * V_84 , const struct V_85 * V_14 , struct V_1 * V_9 )
{
struct V_53 * V_74 ;
int V_86 = 1 ;
F_33 () ;
V_74 = F_27 ( V_9 , V_14 -> V_15 ) ;
if ( V_74 ) {
if ( V_74 -> V_19 & V_87 )
V_84 -> V_88 = V_89 ;
else
V_84 -> V_88 = V_90 ;
} else {
const struct V_91 * V_92 = & F_48 ( V_84 ) -> V_15 ;
if ( F_49 ( V_92 ) &&
( V_92 -> V_93 [ 3 ] == V_14 -> V_15 ) &&
F_50 ( V_92 , V_9 -> V_4 ) )
V_84 -> V_88 = V_94 ;
else
V_86 = 0 ;
}
F_34 () ;
return V_86 ;
}
static void F_51 ( struct V_3 * V_4 )
{
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
if ( V_4 == V_11 -> V_29 ) {
F_52 ( V_11 -> V_21 [ 0 ] , NULL ) ;
} else {
F_8 ( V_11 , F_14 ( V_4 ) ) ;
F_44 ( F_14 ( V_4 ) , NULL ) ;
}
F_53 ( V_4 ) ;
}
static int F_54 ( struct V_83 * V_84 , T_4 V_95 )
{
const struct V_85 * V_14 = ( const struct V_85 * ) V_84 -> V_96 ;
const int type = F_55 ( V_84 ) -> type ;
const int V_97 = F_55 ( V_84 ) -> V_97 ;
struct V_1 * V_9 ;
int V_36 ;
switch ( type ) {
default:
case V_98 :
return 0 ;
case V_99 :
switch ( V_97 ) {
case V_100 :
case V_101 :
return 0 ;
default:
break;
}
break;
case V_102 :
if ( V_97 != V_103 )
return 0 ;
break;
case V_104 :
break;
}
V_36 = - V_105 ;
V_9 = F_1 ( F_18 ( V_84 -> V_4 ) ,
V_84 -> V_4 ,
V_14 -> V_16 ,
V_14 -> V_15 ) ;
if ( V_9 == NULL )
goto V_37;
if ( type == V_99 && V_97 == V_106 ) {
F_56 ( V_84 , F_18 ( V_84 -> V_4 ) , V_95 ,
V_9 -> V_4 -> V_107 , 0 , V_108 , 0 ) ;
V_36 = 0 ;
goto V_37;
}
if ( type == V_104 ) {
F_57 ( V_84 , F_18 ( V_84 -> V_4 ) , V_9 -> V_4 -> V_107 , 0 ,
V_108 , 0 ) ;
V_36 = 0 ;
goto V_37;
}
if ( V_9 -> V_13 . V_14 . V_16 == 0 )
goto V_37;
V_36 = 0 ;
if ( V_9 -> V_13 . V_14 . V_109 == 0 && type == V_102 )
goto V_37;
if ( F_58 ( V_110 , V_9 -> V_111 + V_112 ) )
V_9 -> V_113 ++ ;
else
V_9 -> V_113 = 1 ;
V_9 -> V_111 = V_110 ;
V_37:
return V_36 ;
}
static inline bool F_59 ( struct V_1 * V_114 , const T_1 V_115 ,
const struct V_91 * V_116 )
{
T_1 V_117 = 0 ;
if ( F_60 ( V_114 , V_116 , & V_117 ) && V_115 != V_117 )
return true ;
return false ;
}
static int F_61 ( struct V_83 * V_84 )
{
const struct V_85 * V_14 = F_62 ( V_84 ) ;
struct V_1 * V_114 ;
int V_36 ;
V_114 = F_1 ( F_18 ( V_84 -> V_4 ) , V_84 -> V_4 ,
V_14 -> V_15 , V_14 -> V_16 ) ;
if ( V_114 != NULL ) {
struct V_118 * V_119 ;
F_63 ( V_84 ) ;
V_84 -> V_120 = V_84 -> V_121 ;
F_64 ( V_84 ) ;
F_65 ( V_84 ) -> V_19 = 0 ;
V_84 -> V_122 = F_66 ( V_123 ) ;
V_84 -> V_124 = V_125 ;
if ( V_114 -> V_4 -> V_42 & V_43 ) {
if ( ! F_47 ( V_84 , V_14 , V_114 ) ) {
V_114 -> V_4 -> V_126 . V_127 ++ ;
goto V_37;
}
} else {
if ( F_59 ( V_114 , V_14 -> V_15 ,
& F_48 ( V_84 ) -> V_15 ) ||
F_59 ( V_114 , V_14 -> V_16 ,
& F_48 ( V_84 ) -> V_16 ) ) {
V_114 -> V_4 -> V_126 . V_127 ++ ;
goto V_37;
}
}
F_67 ( V_84 , V_114 -> V_4 ) ;
V_36 = F_68 ( V_14 , V_84 ) ;
if ( F_69 ( V_36 ) ) {
if ( V_128 )
F_70 ( L_2 ,
& V_14 -> V_15 , V_14 -> V_129 ) ;
if ( V_36 > 1 ) {
++ V_114 -> V_4 -> V_126 . V_130 ;
++ V_114 -> V_4 -> V_126 . V_127 ;
goto V_37;
}
}
V_119 = F_71 ( V_114 -> V_4 -> V_119 ) ;
V_119 -> V_131 ++ ;
V_119 -> V_132 += V_84 -> V_63 ;
F_72 ( V_84 ) ;
return 0 ;
}
return 1 ;
V_37:
F_73 ( V_84 ) ;
return 0 ;
}
static bool F_60 ( struct V_1 * V_114 , const struct V_91 * V_133 ,
T_1 * V_134 )
{
#ifdef F_13
if ( F_74 ( V_133 , & V_114 -> V_30 . V_31 ,
V_114 -> V_30 . V_33 ) ) {
unsigned int V_135 , V_136 ;
int V_137 ;
T_4 V_138 ;
V_135 = V_114 -> V_30 . V_33 >> 5 ;
V_136 = V_114 -> V_30 . V_33 & 0x1f ;
V_138 = ( F_75 ( V_133 -> V_93 [ V_135 ] ) << V_136 ) >>
V_114 -> V_30 . V_34 ;
V_137 = V_136 - V_114 -> V_30 . V_34 ;
if ( V_137 > 0 )
V_138 |= F_75 ( V_133 -> V_93 [ V_135 + 1 ] ) >>
( 32 - V_137 ) ;
* V_134 = V_114 -> V_30 . V_32 | F_16 ( V_138 ) ;
return true ;
}
#else
if ( V_133 -> V_139 [ 0 ] == F_66 ( 0x2002 ) ) {
memcpy ( V_134 , & V_133 -> V_139 [ 1 ] , 4 ) ;
return true ;
}
#endif
return false ;
}
static inline T_1 F_76 ( struct V_1 * V_114 ,
const struct V_91 * V_133 )
{
T_1 V_140 = 0 ;
F_60 ( V_114 , V_133 , & V_140 ) ;
return V_140 ;
}
static T_5 F_77 ( struct V_83 * V_84 ,
struct V_3 * V_4 )
{
struct V_1 * V_114 = F_14 ( V_4 ) ;
const struct V_85 * V_141 = & V_114 -> V_13 . V_14 ;
const struct V_142 * V_143 = F_48 ( V_84 ) ;
T_6 V_129 = V_114 -> V_13 . V_14 . V_129 ;
T_7 V_144 = V_141 -> V_145 ;
struct V_146 * V_147 ;
struct V_3 * V_148 ;
struct V_85 * V_14 ;
unsigned int V_149 ;
T_1 V_140 = V_141 -> V_16 ;
struct V_150 V_151 ;
int V_152 ;
const struct V_91 * V_92 ;
int V_153 ;
if ( V_84 -> V_122 != F_66 ( V_123 ) )
goto V_154;
if ( V_129 == 1 )
V_129 = F_78 ( V_143 ) ;
if ( V_4 -> V_42 & V_43 ) {
struct V_155 * V_156 = NULL ;
bool V_157 = false ;
if ( F_79 ( V_84 ) )
V_156 = F_80 ( F_79 ( V_84 ) , & V_143 -> V_16 ) ;
if ( V_156 == NULL ) {
F_81 ( L_3 ) ;
goto V_154;
}
V_92 = ( const struct V_91 * ) & V_156 -> V_158 ;
V_153 = F_82 ( V_92 ) ;
if ( ( V_153 & V_159 ) &&
F_49 ( V_92 ) )
V_140 = V_92 -> V_93 [ 3 ] ;
else
V_157 = true ;
F_83 ( V_156 ) ;
if ( V_157 )
goto V_154;
}
if ( ! V_140 )
V_140 = F_76 ( V_114 , & V_143 -> V_16 ) ;
if ( ! V_140 ) {
struct V_155 * V_156 = NULL ;
bool V_157 = false ;
if ( F_79 ( V_84 ) )
V_156 = F_80 ( F_79 ( V_84 ) , & V_143 -> V_16 ) ;
if ( V_156 == NULL ) {
F_81 ( L_3 ) ;
goto V_154;
}
V_92 = ( const struct V_91 * ) & V_156 -> V_158 ;
V_153 = F_82 ( V_92 ) ;
if ( V_153 == V_160 ) {
V_92 = & F_48 ( V_84 ) -> V_16 ;
V_153 = F_82 ( V_92 ) ;
}
if ( ( V_153 & V_161 ) != 0 )
V_140 = V_92 -> V_93 [ 3 ] ;
else
V_157 = true ;
F_83 ( V_156 ) ;
if ( V_157 )
goto V_154;
}
V_147 = F_84 ( F_18 ( V_4 ) , & V_151 , NULL ,
V_140 , V_141 -> V_15 ,
0 , 0 ,
V_108 , F_85 ( V_129 ) ,
V_114 -> V_13 . V_17 ) ;
if ( F_86 ( V_147 ) ) {
V_4 -> V_126 . V_162 ++ ;
goto V_163;
}
if ( V_147 -> V_164 != V_165 ) {
F_87 ( V_147 ) ;
V_4 -> V_126 . V_162 ++ ;
goto V_163;
}
V_148 = V_147 -> V_140 . V_4 ;
if ( V_148 == V_4 ) {
F_87 ( V_147 ) ;
V_4 -> V_126 . V_166 ++ ;
goto V_154;
}
if ( V_144 ) {
V_152 = F_88 ( & V_147 -> V_140 ) - sizeof( struct V_85 ) ;
if ( V_152 < 68 ) {
V_4 -> V_126 . V_166 ++ ;
F_87 ( V_147 ) ;
goto V_154;
}
if ( V_152 < V_167 ) {
V_152 = V_167 ;
V_144 = 0 ;
}
if ( V_114 -> V_13 . V_14 . V_16 && F_79 ( V_84 ) )
F_79 ( V_84 ) -> V_168 -> V_169 ( F_79 ( V_84 ) , NULL , V_84 , V_152 ) ;
if ( V_84 -> V_63 > V_152 ) {
F_89 ( V_84 , V_170 , 0 , V_152 ) ;
F_87 ( V_147 ) ;
goto V_154;
}
}
if ( V_114 -> V_113 > 0 ) {
if ( F_58 ( V_110 ,
V_114 -> V_111 + V_112 ) ) {
V_114 -> V_113 -- ;
F_90 ( V_84 ) ;
} else
V_114 -> V_113 = 0 ;
}
V_149 = F_91 ( V_148 ) + sizeof( struct V_85 ) ;
if ( F_92 ( V_84 ) < V_149 || F_93 ( V_84 ) ||
( F_94 ( V_84 ) && ! F_95 ( V_84 , 0 ) ) ) {
struct V_83 * V_171 = F_96 ( V_84 , V_149 ) ;
if ( ! V_171 ) {
F_87 ( V_147 ) ;
V_4 -> V_126 . V_172 ++ ;
F_97 ( V_84 ) ;
return V_173 ;
}
if ( V_84 -> V_174 )
F_98 ( V_171 , V_84 -> V_174 ) ;
F_97 ( V_84 ) ;
V_84 = V_171 ;
V_143 = F_48 ( V_84 ) ;
}
V_84 -> V_175 = V_84 -> V_121 ;
F_99 ( V_84 , sizeof( struct V_85 ) ) ;
F_64 ( V_84 ) ;
memset ( & ( F_65 ( V_84 ) -> V_176 ) , 0 , sizeof( F_65 ( V_84 ) -> V_176 ) ) ;
F_65 ( V_84 ) -> V_19 = 0 ;
F_100 ( V_84 ) ;
F_101 ( V_84 , & V_147 -> V_140 ) ;
V_14 = F_62 ( V_84 ) ;
V_14 -> V_177 = 4 ;
V_14 -> V_178 = sizeof( struct V_85 ) >> 2 ;
V_14 -> V_145 = V_144 ;
V_14 -> V_122 = V_108 ;
V_14 -> V_129 = F_102 ( V_129 , F_78 ( V_143 ) ) ;
V_14 -> V_16 = V_151 . V_16 ;
V_14 -> V_15 = V_151 . V_15 ;
if ( ( V_14 -> V_109 = V_141 -> V_109 ) == 0 )
V_14 -> V_109 = V_143 -> V_179 ;
V_84 -> V_180 = V_181 ;
F_103 ( V_14 , F_79 ( V_84 ) , NULL ) ;
F_104 ( V_84 , V_4 ) ;
return V_173 ;
V_163:
F_90 ( V_84 ) ;
V_154:
V_4 -> V_126 . V_182 ++ ;
F_97 ( V_84 ) ;
return V_173 ;
}
static void F_105 ( struct V_3 * V_4 )
{
struct V_3 * V_148 = NULL ;
struct V_1 * V_114 ;
const struct V_85 * V_14 ;
struct V_150 V_151 ;
V_114 = F_14 ( V_4 ) ;
V_14 = & V_114 -> V_13 . V_14 ;
if ( V_14 -> V_16 ) {
struct V_146 * V_147 = F_84 ( F_18 ( V_4 ) , & V_151 , NULL ,
V_14 -> V_16 , V_14 -> V_15 ,
0 , 0 ,
V_108 ,
F_85 ( V_14 -> V_129 ) ,
V_114 -> V_13 . V_17 ) ;
if ( ! F_86 ( V_147 ) ) {
V_148 = V_147 -> V_140 . V_4 ;
F_87 ( V_147 ) ;
}
V_4 -> V_19 |= V_183 ;
}
if ( ! V_148 && V_114 -> V_13 . V_17 )
V_148 = F_106 ( F_18 ( V_4 ) , V_114 -> V_13 . V_17 ) ;
if ( V_148 ) {
V_4 -> V_184 = V_148 -> V_184 + sizeof( struct V_85 ) ;
V_4 -> V_152 = V_148 -> V_152 - sizeof( struct V_85 ) ;
if ( V_4 -> V_152 < V_167 )
V_4 -> V_152 = V_167 ;
}
V_4 -> V_18 = V_114 -> V_13 . V_17 ;
}
static void F_107 ( struct V_1 * V_9 , struct V_22 * V_74 )
{
struct V_2 * V_2 = F_18 ( V_9 -> V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
F_8 ( V_11 , V_9 ) ;
F_108 () ;
V_9 -> V_13 . V_14 . V_15 = V_74 -> V_14 . V_15 ;
V_9 -> V_13 . V_14 . V_16 = V_74 -> V_14 . V_16 ;
memcpy ( V_9 -> V_4 -> V_185 , & V_74 -> V_14 . V_15 , 4 ) ;
memcpy ( V_9 -> V_4 -> V_186 , & V_74 -> V_14 . V_16 , 4 ) ;
F_11 ( V_11 , V_9 ) ;
V_9 -> V_13 . V_14 . V_109 = V_74 -> V_14 . V_109 ;
V_9 -> V_13 . V_14 . V_129 = V_74 -> V_14 . V_129 ;
if ( V_9 -> V_13 . V_17 != V_74 -> V_17 ) {
V_9 -> V_13 . V_17 = V_74 -> V_17 ;
F_105 ( V_9 -> V_4 ) ;
}
F_109 ( V_9 -> V_4 ) ;
}
static int F_110 ( struct V_1 * V_9 ,
struct V_187 * V_30 )
{
struct V_91 V_31 ;
T_1 V_32 ;
if ( V_30 -> V_34 > 32 ||
V_30 -> V_33 + ( 32 - V_30 -> V_34 ) > 64 )
return - V_75 ;
F_111 ( & V_31 , & V_30 -> V_31 , V_30 -> V_33 ) ;
if ( ! F_112 ( & V_31 , & V_30 -> V_31 ) )
return - V_75 ;
if ( V_30 -> V_34 )
V_32 = V_30 -> V_32 &
F_16 ( 0xffffffffUL <<
( 32 - V_30 -> V_34 ) ) ;
else
V_32 = 0 ;
if ( V_32 != V_30 -> V_32 )
return - V_75 ;
V_9 -> V_30 . V_31 = V_31 ;
V_9 -> V_30 . V_32 = V_32 ;
V_9 -> V_30 . V_33 = V_30 -> V_33 ;
V_9 -> V_30 . V_34 = V_30 -> V_34 ;
F_109 ( V_9 -> V_4 ) ;
return 0 ;
}
static int
F_113 ( struct V_3 * V_4 , struct V_188 * V_189 , int V_190 )
{
int V_36 = 0 ;
struct V_22 V_74 ;
struct V_56 V_55 ;
struct V_1 * V_9 ;
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
#ifdef F_13
struct V_187 V_30 ;
#endif
switch ( V_190 ) {
case V_191 :
#ifdef F_13
case V_192 :
#endif
V_9 = NULL ;
if ( V_4 == V_11 -> V_29 ) {
if ( F_30 ( & V_74 , V_189 -> V_193 . V_194 , sizeof( V_74 ) ) ) {
V_36 = - V_65 ;
break;
}
V_9 = F_22 ( V_2 , & V_74 , 0 ) ;
}
if ( V_9 == NULL )
V_9 = F_14 ( V_4 ) ;
V_36 = - V_65 ;
if ( V_190 == V_191 ) {
memcpy ( & V_74 , & V_9 -> V_13 , sizeof( V_74 ) ) ;
if ( F_35 ( V_189 -> V_193 . V_194 , & V_74 ,
sizeof( V_74 ) ) )
goto V_195;
#ifdef F_13
} else {
V_30 . V_31 = V_9 -> V_30 . V_31 ;
V_30 . V_32 = V_9 -> V_30 . V_32 ;
V_30 . V_33 = V_9 -> V_30 . V_33 ;
V_30 . V_34 = V_9 -> V_30 . V_34 ;
if ( F_35 ( V_189 -> V_193 . V_194 , & V_30 ,
sizeof( V_30 ) ) )
goto V_195;
#endif
}
V_36 = 0 ;
break;
case V_196 :
case V_197 :
V_36 = - V_198 ;
if ( ! F_114 ( V_2 -> V_199 , V_68 ) )
goto V_195;
V_36 = - V_65 ;
if ( F_30 ( & V_74 , V_189 -> V_193 . V_194 , sizeof( V_74 ) ) )
goto V_195;
V_36 = - V_75 ;
if ( V_74 . V_14 . V_177 != 4 || V_74 . V_14 . V_122 != V_108 ||
V_74 . V_14 . V_178 != 5 || ( V_74 . V_14 . V_145 & F_66 ( ~ V_200 ) ) )
goto V_195;
if ( V_74 . V_14 . V_109 )
V_74 . V_14 . V_145 |= F_66 ( V_200 ) ;
V_9 = F_22 ( V_2 , & V_74 , V_190 == V_196 ) ;
if ( V_4 != V_11 -> V_29 && V_190 == V_197 ) {
if ( V_9 != NULL ) {
if ( V_9 -> V_4 != V_4 ) {
V_36 = - V_76 ;
break;
}
} else {
if ( ( ( V_4 -> V_19 & V_183 ) && ! V_74 . V_14 . V_16 ) ||
( ! ( V_4 -> V_19 & V_183 ) && V_74 . V_14 . V_16 ) ) {
V_36 = - V_75 ;
break;
}
V_9 = F_14 ( V_4 ) ;
}
F_107 ( V_9 , & V_74 ) ;
}
if ( V_9 ) {
V_36 = 0 ;
if ( F_35 ( V_189 -> V_193 . V_194 , & V_9 -> V_13 , sizeof( V_74 ) ) )
V_36 = - V_65 ;
} else
V_36 = ( V_190 == V_196 ? - V_78 : - V_105 ) ;
break;
case V_201 :
V_36 = - V_198 ;
if ( ! F_114 ( V_2 -> V_199 , V_68 ) )
goto V_195;
if ( V_4 == V_11 -> V_29 ) {
V_36 = - V_65 ;
if ( F_30 ( & V_74 , V_189 -> V_193 . V_194 , sizeof( V_74 ) ) )
goto V_195;
V_36 = - V_105 ;
if ( ( V_9 = F_22 ( V_2 , & V_74 , 0 ) ) == NULL )
goto V_195;
V_36 = - V_198 ;
if ( V_9 == F_14 ( V_11 -> V_29 ) )
goto V_195;
V_4 = V_9 -> V_4 ;
}
F_115 ( V_4 ) ;
V_36 = 0 ;
break;
case V_202 :
V_36 = - V_75 ;
if ( V_4 == V_11 -> V_29 )
goto V_195;
V_36 = - V_105 ;
if ( ! ( V_9 = F_14 ( V_4 ) ) )
goto V_195;
V_36 = F_29 ( V_9 , V_189 -> V_193 . V_194 ) ;
break;
case V_203 :
case V_204 :
case V_205 :
V_36 = - V_198 ;
if ( ! F_114 ( V_2 -> V_199 , V_68 ) )
goto V_195;
V_36 = - V_75 ;
if ( V_4 == V_11 -> V_29 )
goto V_195;
V_36 = - V_65 ;
if ( F_30 ( & V_55 , V_189 -> V_193 . V_194 , sizeof( V_55 ) ) )
goto V_195;
V_36 = - V_105 ;
if ( ! ( V_9 = F_14 ( V_4 ) ) )
goto V_195;
switch ( V_190 ) {
case V_204 :
V_36 = F_44 ( V_9 , & V_55 ) ;
break;
case V_203 :
case V_205 :
V_36 = F_38 ( V_9 , & V_55 , V_190 == V_205 ) ;
break;
}
F_109 ( V_4 ) ;
break;
#ifdef F_13
case V_206 :
case V_207 :
case V_208 :
V_36 = - V_198 ;
if ( ! F_114 ( V_2 -> V_199 , V_68 ) )
goto V_195;
V_36 = - V_65 ;
if ( F_30 ( & V_30 , V_189 -> V_193 . V_194 ,
sizeof( V_30 ) ) )
goto V_195;
V_9 = F_14 ( V_4 ) ;
if ( V_190 != V_208 ) {
V_36 = F_110 ( V_9 , & V_30 ) ;
if ( V_36 < 0 )
goto V_195;
} else
F_12 ( V_4 , V_11 ) ;
V_36 = 0 ;
break;
#endif
default:
V_36 = - V_75 ;
}
V_195:
return V_36 ;
}
static int F_116 ( struct V_3 * V_4 , int V_209 )
{
if ( V_209 < V_167 || V_209 > 0xFFF8 - sizeof( struct V_85 ) )
return - V_75 ;
V_4 -> V_152 = V_209 ;
return 0 ;
}
static void F_26 ( struct V_3 * V_4 )
{
F_117 ( V_4 -> V_119 ) ;
F_118 ( V_4 ) ;
}
static void V_51 ( struct V_3 * V_4 )
{
V_4 -> V_210 = & V_211 ;
V_4 -> V_212 = F_26 ;
V_4 -> type = V_213 ;
V_4 -> V_184 = V_214 + sizeof( struct V_85 ) ;
V_4 -> V_152 = V_215 - sizeof( struct V_85 ) ;
V_4 -> V_19 = V_216 ;
V_4 -> V_42 &= ~ V_217 ;
V_4 -> V_18 = 0 ;
V_4 -> V_218 = 4 ;
V_4 -> V_219 |= V_220 ;
V_4 -> V_219 |= V_221 ;
}
static int F_19 ( struct V_3 * V_4 )
{
struct V_1 * V_114 = F_14 ( V_4 ) ;
V_114 -> V_4 = V_4 ;
memcpy ( V_4 -> V_185 , & V_114 -> V_13 . V_14 . V_15 , 4 ) ;
memcpy ( V_4 -> V_186 , & V_114 -> V_13 . V_14 . V_16 , 4 ) ;
F_105 ( V_4 ) ;
V_4 -> V_119 = F_119 ( struct V_118 ) ;
if ( ! V_4 -> V_119 )
return - V_72 ;
return 0 ;
}
static int T_8 F_120 ( struct V_3 * V_4 )
{
struct V_1 * V_114 = F_14 ( V_4 ) ;
struct V_85 * V_14 = & V_114 -> V_13 . V_14 ;
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
V_114 -> V_4 = V_4 ;
strcpy ( V_114 -> V_13 . V_44 , V_4 -> V_44 ) ;
V_14 -> V_177 = 4 ;
V_14 -> V_122 = V_108 ;
V_14 -> V_178 = 5 ;
V_14 -> V_109 = 64 ;
V_4 -> V_119 = F_119 ( struct V_118 ) ;
if ( ! V_4 -> V_119 )
return - V_72 ;
F_21 ( V_4 ) ;
F_10 ( V_11 -> V_21 [ 0 ] , V_114 ) ;
return 0 ;
}
static void F_121 ( struct V_222 * V_96 [] ,
struct V_22 * V_13 )
{
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_14 . V_177 = 4 ;
V_13 -> V_14 . V_122 = V_108 ;
V_13 -> V_14 . V_178 = 5 ;
V_13 -> V_14 . V_109 = 64 ;
if ( ! V_96 )
return;
if ( V_96 [ V_223 ] )
V_13 -> V_17 = F_122 ( V_96 [ V_223 ] ) ;
if ( V_96 [ V_224 ] )
V_13 -> V_14 . V_15 = F_123 ( V_96 [ V_224 ] ) ;
if ( V_96 [ V_225 ] )
V_13 -> V_14 . V_16 = F_123 ( V_96 [ V_225 ] ) ;
if ( V_96 [ V_226 ] ) {
V_13 -> V_14 . V_109 = F_124 ( V_96 [ V_226 ] ) ;
if ( V_13 -> V_14 . V_109 )
V_13 -> V_14 . V_145 = F_66 ( V_200 ) ;
}
if ( V_96 [ V_227 ] )
V_13 -> V_14 . V_129 = F_124 ( V_96 [ V_227 ] ) ;
if ( ! V_96 [ V_228 ] || F_124 ( V_96 [ V_228 ] ) )
V_13 -> V_14 . V_145 = F_66 ( V_200 ) ;
if ( V_96 [ V_229 ] )
V_13 -> V_40 = F_125 ( V_96 [ V_229 ] ) ;
}
static bool F_126 ( struct V_222 * V_96 [] ,
struct V_187 * V_30 )
{
bool V_64 = false ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
if ( ! V_96 )
return V_64 ;
if ( V_96 [ V_230 ] ) {
V_64 = true ;
F_127 ( & V_30 -> V_31 , V_96 [ V_230 ] ,
sizeof( struct V_91 ) ) ;
}
if ( V_96 [ V_231 ] ) {
V_64 = true ;
V_30 -> V_32 =
F_123 ( V_96 [ V_231 ] ) ;
}
if ( V_96 [ V_232 ] ) {
V_64 = true ;
V_30 -> V_33 = F_128 ( V_96 [ V_232 ] ) ;
}
if ( V_96 [ V_233 ] ) {
V_64 = true ;
V_30 -> V_34 =
F_128 ( V_96 [ V_233 ] ) ;
}
return V_64 ;
}
static int F_129 ( struct V_2 * V_234 , struct V_3 * V_4 ,
struct V_222 * V_235 [] , struct V_222 * V_96 [] )
{
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_1 * V_48 ;
#ifdef F_13
struct V_187 V_30 ;
#endif
int V_36 ;
V_48 = F_14 ( V_4 ) ;
F_121 ( V_96 , & V_48 -> V_13 ) ;
if ( F_22 ( V_2 , & V_48 -> V_13 , 0 ) )
return - V_76 ;
V_36 = F_17 ( V_4 ) ;
if ( V_36 < 0 )
return V_36 ;
#ifdef F_13
if ( F_126 ( V_96 , & V_30 ) )
V_36 = F_110 ( V_48 , & V_30 ) ;
#endif
return V_36 ;
}
static int F_130 ( struct V_3 * V_4 , struct V_222 * V_235 [] ,
struct V_222 * V_96 [] )
{
struct V_1 * V_9 ;
struct V_22 V_74 ;
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
#ifdef F_13
struct V_187 V_30 ;
#endif
if ( V_4 == V_11 -> V_29 )
return - V_75 ;
F_121 ( V_96 , & V_74 ) ;
if ( ( ( V_4 -> V_19 & V_183 ) && ! V_74 . V_14 . V_16 ) ||
( ! ( V_4 -> V_19 & V_183 ) && V_74 . V_14 . V_16 ) )
return - V_75 ;
V_9 = F_22 ( V_2 , & V_74 , 0 ) ;
if ( V_9 ) {
if ( V_9 -> V_4 != V_4 )
return - V_76 ;
} else
V_9 = F_14 ( V_4 ) ;
F_107 ( V_9 , & V_74 ) ;
#ifdef F_13
if ( F_126 ( V_96 , & V_30 ) )
return F_110 ( V_9 , & V_30 ) ;
#endif
return 0 ;
}
static T_9 F_131 ( const struct V_3 * V_4 )
{
return
F_132 ( 4 ) +
F_132 ( 4 ) +
F_132 ( 4 ) +
F_132 ( 1 ) +
F_132 ( 1 ) +
F_132 ( 1 ) +
F_132 ( 2 ) +
#ifdef F_13
F_132 ( sizeof( struct V_91 ) ) +
F_132 ( 4 ) +
F_132 ( 2 ) +
F_132 ( 2 ) +
#endif
0 ;
}
static int F_133 ( struct V_83 * V_84 , const struct V_3 * V_4 )
{
struct V_1 * V_114 = F_14 ( V_4 ) ;
struct V_22 * V_236 = & V_114 -> V_13 ;
if ( F_134 ( V_84 , V_223 , V_236 -> V_17 ) ||
F_135 ( V_84 , V_224 , V_236 -> V_14 . V_15 ) ||
F_135 ( V_84 , V_225 , V_236 -> V_14 . V_16 ) ||
F_136 ( V_84 , V_226 , V_236 -> V_14 . V_109 ) ||
F_136 ( V_84 , V_227 , V_236 -> V_14 . V_129 ) ||
F_136 ( V_84 , V_228 ,
! ! ( V_236 -> V_14 . V_145 & F_66 ( V_200 ) ) ) ||
F_137 ( V_84 , V_229 , V_236 -> V_40 ) )
goto V_237;
#ifdef F_13
if ( F_138 ( V_84 , V_230 , sizeof( struct V_91 ) ,
& V_114 -> V_30 . V_31 ) ||
F_135 ( V_84 , V_231 ,
V_114 -> V_30 . V_32 ) ||
F_139 ( V_84 , V_232 ,
V_114 -> V_30 . V_33 ) ||
F_139 ( V_84 , V_233 ,
V_114 -> V_30 . V_34 ) )
goto V_237;
#endif
return 0 ;
V_237:
return - V_238 ;
}
static void T_10 F_140 ( struct V_10 * V_11 , struct V_239 * V_80 )
{
int V_24 ;
for ( V_24 = 1 ; V_24 < 4 ; V_24 ++ ) {
int V_23 ;
for ( V_23 = 0 ; V_23 < V_240 ; V_23 ++ ) {
struct V_1 * V_9 ;
V_9 = F_9 ( V_11 -> V_25 [ V_24 ] [ V_23 ] ) ;
while ( V_9 != NULL ) {
F_141 ( V_9 -> V_4 , V_80 ) ;
V_9 = F_9 ( V_9 -> V_28 ) ;
}
}
}
}
static int T_8 F_142 ( struct V_2 * V_2 )
{
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
struct V_1 * V_9 ;
int V_36 ;
V_11 -> V_25 [ 0 ] = V_11 -> V_21 ;
V_11 -> V_25 [ 1 ] = V_11 -> V_241 ;
V_11 -> V_25 [ 2 ] = V_11 -> V_242 ;
V_11 -> V_25 [ 3 ] = V_11 -> V_243 ;
V_11 -> V_29 = F_24 ( sizeof( struct V_1 ) , L_4 ,
V_51 ) ;
if ( ! V_11 -> V_29 ) {
V_36 = - V_72 ;
goto V_244;
}
F_25 ( V_11 -> V_29 , V_2 ) ;
V_36 = F_120 ( V_11 -> V_29 ) ;
if ( V_36 )
goto V_245;
F_12 ( V_11 -> V_29 , V_11 ) ;
if ( ( V_36 = F_143 ( V_11 -> V_29 ) ) )
goto V_246;
V_9 = F_14 ( V_11 -> V_29 ) ;
strcpy ( V_9 -> V_13 . V_44 , V_11 -> V_29 -> V_44 ) ;
return 0 ;
V_246:
F_53 ( V_11 -> V_29 ) ;
V_245:
F_26 ( V_11 -> V_29 ) ;
V_244:
return V_36 ;
}
static void T_10 F_144 ( struct V_2 * V_2 )
{
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
F_145 ( V_247 ) ;
F_146 () ;
F_140 ( V_11 , & V_247 ) ;
F_141 ( V_11 -> V_29 , & V_247 ) ;
F_147 ( & V_247 ) ;
F_148 () ;
}
static void T_11 F_149 ( void )
{
F_150 ( & V_46 ) ;
F_151 ( & V_248 , V_249 ) ;
F_152 ( & V_250 ) ;
F_153 () ;
}
static int T_12 F_154 ( void )
{
int V_36 ;
F_155 ( L_5 ) ;
V_36 = F_156 ( & V_250 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_157 ( & V_248 , V_249 ) ;
if ( V_36 < 0 ) {
F_155 ( L_6 , V_251 ) ;
goto V_252;
}
V_36 = F_158 ( & V_46 ) ;
if ( V_36 < 0 )
goto V_253;
V_37:
return V_36 ;
V_253:
F_151 ( & V_248 , V_249 ) ;
V_252:
F_152 ( & V_250 ) ;
goto V_37;
}
