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
struct V_1 * V_95 = F_14 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_95 -> V_2 , V_12 ) ;
if ( V_4 == V_11 -> V_29 ) {
F_52 ( V_11 -> V_21 [ 0 ] , NULL ) ;
} else {
F_8 ( V_11 , V_95 ) ;
F_44 ( V_95 , NULL ) ;
}
F_53 ( V_4 ) ;
}
static int F_54 ( struct V_83 * V_84 , T_4 V_96 )
{
const struct V_85 * V_14 = ( const struct V_85 * ) V_84 -> V_97 ;
const int type = F_55 ( V_84 ) -> type ;
const int V_98 = F_55 ( V_84 ) -> V_98 ;
struct V_1 * V_9 ;
int V_36 ;
switch ( type ) {
default:
case V_99 :
return 0 ;
case V_100 :
switch ( V_98 ) {
case V_101 :
case V_102 :
return 0 ;
default:
break;
}
break;
case V_103 :
if ( V_98 != V_104 )
return 0 ;
break;
case V_105 :
break;
}
V_36 = - V_106 ;
V_9 = F_1 ( F_18 ( V_84 -> V_4 ) ,
V_84 -> V_4 ,
V_14 -> V_16 ,
V_14 -> V_15 ) ;
if ( V_9 == NULL )
goto V_37;
if ( type == V_100 && V_98 == V_107 ) {
F_56 ( V_84 , F_18 ( V_84 -> V_4 ) , V_96 ,
V_9 -> V_4 -> V_108 , 0 , V_109 , 0 ) ;
V_36 = 0 ;
goto V_37;
}
if ( type == V_105 ) {
F_57 ( V_84 , F_18 ( V_84 -> V_4 ) , V_9 -> V_4 -> V_108 , 0 ,
V_109 , 0 ) ;
V_36 = 0 ;
goto V_37;
}
if ( V_9 -> V_13 . V_14 . V_16 == 0 )
goto V_37;
V_36 = 0 ;
if ( V_9 -> V_13 . V_14 . V_110 == 0 && type == V_103 )
goto V_37;
if ( F_58 ( V_111 , V_9 -> V_112 + V_113 ) )
V_9 -> V_114 ++ ;
else
V_9 -> V_114 = 1 ;
V_9 -> V_112 = V_111 ;
V_37:
return V_36 ;
}
static inline bool F_59 ( struct V_1 * V_95 , const T_1 V_115 ,
const struct V_91 * V_116 )
{
T_1 V_117 = 0 ;
if ( F_60 ( V_95 , V_116 , & V_117 ) && V_115 != V_117 )
return true ;
return false ;
}
static bool F_61 ( const struct V_1 * V_95 ,
const struct V_91 * V_118 )
{
int V_119 ;
#ifdef F_13
V_119 = V_95 -> V_30 . V_33 + 32
- V_95 -> V_30 . V_34 ;
#else
V_119 = 48 ;
#endif
return F_62 ( V_118 , V_119 , V_95 -> V_4 ) ;
}
static bool F_63 ( struct V_83 * V_84 ,
const struct V_85 * V_14 ,
struct V_1 * V_95 )
{
const struct V_120 * V_121 ;
if ( V_95 -> V_4 -> V_42 & V_43 ) {
if ( ! F_47 ( V_84 , V_14 , V_95 ) )
return true ;
return false ;
}
if ( V_95 -> V_4 -> V_19 & V_122 )
return false ;
V_121 = F_48 ( V_84 ) ;
if ( F_64 ( F_59 ( V_95 , V_14 -> V_15 , & V_121 -> V_15 ) ) ) {
F_65 ( L_2 ,
& V_14 -> V_15 , & V_121 -> V_15 ,
& V_14 -> V_16 , & V_121 -> V_16 ) ;
return true ;
}
if ( F_66 ( ! F_59 ( V_95 , V_14 -> V_16 , & V_121 -> V_16 ) ) )
return false ;
if ( F_61 ( V_95 , & V_121 -> V_16 ) )
return false ;
F_65 ( L_3 ,
& V_14 -> V_15 , & V_121 -> V_15 ,
& V_14 -> V_16 , & V_121 -> V_16 ) ;
return true ;
}
static int F_67 ( struct V_83 * V_84 )
{
const struct V_85 * V_14 = F_68 ( V_84 ) ;
struct V_1 * V_95 ;
int V_36 ;
V_95 = F_1 ( F_18 ( V_84 -> V_4 ) , V_84 -> V_4 ,
V_14 -> V_15 , V_14 -> V_16 ) ;
if ( V_95 != NULL ) {
struct V_123 * V_124 ;
if ( V_95 -> V_13 . V_14 . V_125 != V_109 &&
V_95 -> V_13 . V_14 . V_125 != 0 )
goto V_37;
V_84 -> V_126 = V_84 -> V_127 ;
F_69 ( V_84 ) ;
F_70 ( V_84 ) -> V_19 = 0 ;
V_84 -> V_125 = F_71 ( V_128 ) ;
if ( F_63 ( V_84 , V_14 , V_95 ) ) {
V_95 -> V_4 -> V_129 . V_130 ++ ;
goto V_37;
}
F_72 ( V_84 , V_95 -> V_4 , V_95 -> V_2 ) ;
V_36 = F_73 ( V_14 , V_84 ) ;
if ( F_64 ( V_36 ) ) {
if ( V_131 )
F_74 ( L_4 ,
& V_14 -> V_15 , V_14 -> V_132 ) ;
if ( V_36 > 1 ) {
++ V_95 -> V_4 -> V_129 . V_133 ;
++ V_95 -> V_4 -> V_129 . V_130 ;
goto V_37;
}
}
V_124 = F_75 ( V_95 -> V_4 -> V_124 ) ;
V_124 -> V_134 ++ ;
V_124 -> V_135 += V_84 -> V_63 ;
F_76 ( V_84 ) ;
return 0 ;
}
return 1 ;
V_37:
F_77 ( V_84 ) ;
return 0 ;
}
static int F_78 ( struct V_83 * V_84 )
{
const struct V_85 * V_14 ;
struct V_1 * V_95 ;
V_14 = F_68 ( V_84 ) ;
V_95 = F_1 ( F_18 ( V_84 -> V_4 ) , V_84 -> V_4 ,
V_14 -> V_15 , V_14 -> V_16 ) ;
if ( V_95 != NULL ) {
if ( V_95 -> V_13 . V_14 . V_125 != V_136 &&
V_95 -> V_13 . V_14 . V_125 != 0 )
goto V_137;
if ( ! F_79 ( NULL , V_138 , V_84 ) )
goto V_137;
if ( F_80 ( V_84 , 0 , V_139 . V_140 ) )
goto V_137;
return F_81 ( V_95 , V_84 , & V_139 , V_131 ) ;
}
return 1 ;
V_137:
F_77 ( V_84 ) ;
return 0 ;
}
static bool F_60 ( struct V_1 * V_95 , const struct V_91 * V_118 ,
T_1 * V_141 )
{
#ifdef F_13
if ( F_82 ( V_118 , & V_95 -> V_30 . V_31 ,
V_95 -> V_30 . V_33 ) ) {
unsigned int V_142 , V_143 ;
int V_144 ;
T_4 V_145 ;
V_142 = V_95 -> V_30 . V_33 >> 5 ;
V_143 = V_95 -> V_30 . V_33 & 0x1f ;
V_145 = ( F_83 ( V_118 -> V_93 [ V_142 ] ) << V_143 ) >>
V_95 -> V_30 . V_34 ;
V_144 = V_143 - V_95 -> V_30 . V_34 ;
if ( V_144 > 0 )
V_145 |= F_83 ( V_118 -> V_93 [ V_142 + 1 ] ) >>
( 32 - V_144 ) ;
* V_141 = V_95 -> V_30 . V_32 | F_16 ( V_145 ) ;
return true ;
}
#else
if ( V_118 -> V_146 [ 0 ] == F_71 ( 0x2002 ) ) {
memcpy ( V_141 , & V_118 -> V_146 [ 1 ] , 4 ) ;
return true ;
}
#endif
return false ;
}
static inline T_1 F_84 ( struct V_1 * V_95 ,
const struct V_91 * V_118 )
{
T_1 V_147 = 0 ;
F_60 ( V_95 , V_118 , & V_147 ) ;
return V_147 ;
}
static T_5 F_85 ( struct V_83 * V_84 ,
struct V_3 * V_4 )
{
struct V_1 * V_95 = F_14 ( V_4 ) ;
const struct V_85 * V_148 = & V_95 -> V_13 . V_14 ;
const struct V_120 * V_149 = F_48 ( V_84 ) ;
T_6 V_132 = V_95 -> V_13 . V_14 . V_132 ;
T_7 V_150 = V_148 -> V_151 ;
struct V_152 * V_153 ;
struct V_3 * V_154 ;
unsigned int V_155 ;
T_1 V_147 = V_148 -> V_16 ;
struct V_156 V_157 ;
int V_158 ;
const struct V_91 * V_92 ;
int V_159 ;
T_6 V_110 ;
int V_36 ;
if ( V_84 -> V_125 != F_71 ( V_128 ) )
goto V_160;
if ( V_132 == 1 )
V_132 = F_86 ( V_149 ) ;
if ( V_4 -> V_42 & V_43 ) {
struct V_161 * V_162 = NULL ;
bool V_163 = false ;
if ( F_87 ( V_84 ) )
V_162 = F_88 ( F_87 ( V_84 ) , & V_149 -> V_16 ) ;
if ( V_162 == NULL ) {
F_89 ( L_5 ) ;
goto V_160;
}
V_92 = ( const struct V_91 * ) & V_162 -> V_164 ;
V_159 = F_90 ( V_92 ) ;
if ( ( V_159 & V_165 ) &&
F_49 ( V_92 ) )
V_147 = V_92 -> V_93 [ 3 ] ;
else
V_163 = true ;
F_91 ( V_162 ) ;
if ( V_163 )
goto V_160;
}
if ( ! V_147 )
V_147 = F_84 ( V_95 , & V_149 -> V_16 ) ;
if ( ! V_147 ) {
struct V_161 * V_162 = NULL ;
bool V_163 = false ;
if ( F_87 ( V_84 ) )
V_162 = F_88 ( F_87 ( V_84 ) , & V_149 -> V_16 ) ;
if ( V_162 == NULL ) {
F_89 ( L_5 ) ;
goto V_160;
}
V_92 = ( const struct V_91 * ) & V_162 -> V_164 ;
V_159 = F_90 ( V_92 ) ;
if ( V_159 == V_166 ) {
V_92 = & F_48 ( V_84 ) -> V_16 ;
V_159 = F_90 ( V_92 ) ;
}
if ( ( V_159 & V_167 ) != 0 )
V_147 = V_92 -> V_93 [ 3 ] ;
else
V_163 = true ;
F_91 ( V_162 ) ;
if ( V_163 )
goto V_160;
}
V_153 = F_92 ( V_95 -> V_2 , & V_157 , NULL ,
V_147 , V_148 -> V_15 ,
0 , 0 ,
V_109 , F_93 ( V_132 ) ,
V_95 -> V_13 . V_17 ) ;
if ( F_94 ( V_153 ) ) {
V_4 -> V_129 . V_168 ++ ;
goto V_169;
}
if ( V_153 -> V_170 != V_171 ) {
F_95 ( V_153 ) ;
V_4 -> V_129 . V_168 ++ ;
goto V_169;
}
V_154 = V_153 -> V_147 . V_4 ;
if ( V_154 == V_4 ) {
F_95 ( V_153 ) ;
V_4 -> V_129 . V_172 ++ ;
goto V_160;
}
if ( V_150 ) {
V_158 = F_96 ( & V_153 -> V_147 ) - sizeof( struct V_85 ) ;
if ( V_158 < 68 ) {
V_4 -> V_129 . V_172 ++ ;
F_95 ( V_153 ) ;
goto V_160;
}
if ( V_158 < V_173 ) {
V_158 = V_173 ;
V_150 = 0 ;
}
if ( V_95 -> V_13 . V_14 . V_16 && F_87 ( V_84 ) )
F_87 ( V_84 ) -> V_174 -> V_175 ( F_87 ( V_84 ) , NULL , V_84 , V_158 ) ;
if ( V_84 -> V_63 > V_158 ) {
F_97 ( V_84 , V_176 , 0 , V_158 ) ;
F_95 ( V_153 ) ;
goto V_160;
}
}
if ( V_95 -> V_114 > 0 ) {
if ( F_58 ( V_111 ,
V_95 -> V_112 + V_113 ) ) {
V_95 -> V_114 -- ;
F_98 ( V_84 ) ;
} else
V_95 -> V_114 = 0 ;
}
V_155 = F_99 ( V_154 ) + sizeof( struct V_85 ) ;
if ( F_100 ( V_84 ) < V_155 || F_101 ( V_84 ) ||
( F_102 ( V_84 ) && ! F_103 ( V_84 , 0 ) ) ) {
struct V_83 * V_177 = F_104 ( V_84 , V_155 ) ;
if ( ! V_177 ) {
F_95 ( V_153 ) ;
V_4 -> V_129 . V_178 ++ ;
F_105 ( V_84 ) ;
return V_179 ;
}
if ( V_84 -> V_180 )
F_106 ( V_177 , V_84 -> V_180 ) ;
F_105 ( V_84 ) ;
V_84 = V_177 ;
V_149 = F_48 ( V_84 ) ;
}
V_110 = V_148 -> V_110 ;
if ( V_110 == 0 )
V_110 = V_149 -> V_181 ;
V_132 = F_107 ( V_132 , F_86 ( V_149 ) ) ;
if ( F_66 ( ! V_84 -> V_182 ) ) {
F_108 ( V_84 ) ;
V_84 -> V_182 = 1 ;
}
V_36 = F_109 ( V_153 , V_84 , V_157 . V_15 , V_157 . V_16 , V_109 , V_132 ,
V_110 , V_150 , ! F_110 ( V_95 -> V_2 , F_18 ( V_4 ) ) ) ;
F_111 ( V_36 , & V_4 -> V_129 , V_4 -> V_124 ) ;
return V_179 ;
V_169:
F_98 ( V_84 ) ;
V_160:
V_4 -> V_129 . V_183 ++ ;
F_105 ( V_84 ) ;
return V_179 ;
}
static T_5 F_112 ( struct V_83 * V_84 , struct V_3 * V_4 )
{
struct V_1 * V_95 = F_14 ( V_4 ) ;
const struct V_85 * V_148 = & V_95 -> V_13 . V_14 ;
if ( F_66 ( ! V_84 -> V_182 ) ) {
F_108 ( V_84 ) ;
V_84 -> V_182 = 1 ;
}
F_113 ( V_84 , V_4 , V_148 , V_136 ) ;
return V_179 ;
}
static T_5 F_114 ( struct V_83 * V_84 ,
struct V_3 * V_4 )
{
switch ( V_84 -> V_125 ) {
case F_71 ( V_184 ) :
F_112 ( V_84 , V_4 ) ;
break;
case F_71 ( V_128 ) :
F_85 ( V_84 , V_4 ) ;
break;
default:
goto V_185;
}
return V_179 ;
V_185:
V_4 -> V_129 . V_183 ++ ;
F_105 ( V_84 ) ;
return V_179 ;
}
static void F_115 ( struct V_3 * V_4 )
{
struct V_3 * V_154 = NULL ;
struct V_1 * V_95 ;
const struct V_85 * V_14 ;
struct V_156 V_157 ;
V_95 = F_14 ( V_4 ) ;
V_14 = & V_95 -> V_13 . V_14 ;
if ( V_14 -> V_16 ) {
struct V_152 * V_153 = F_92 ( V_95 -> V_2 , & V_157 ,
NULL ,
V_14 -> V_16 , V_14 -> V_15 ,
0 , 0 ,
V_109 ,
F_93 ( V_14 -> V_132 ) ,
V_95 -> V_13 . V_17 ) ;
if ( ! F_94 ( V_153 ) ) {
V_154 = V_153 -> V_147 . V_4 ;
F_95 ( V_153 ) ;
}
V_4 -> V_19 |= V_122 ;
}
if ( ! V_154 && V_95 -> V_13 . V_17 )
V_154 = F_116 ( V_95 -> V_2 , V_95 -> V_13 . V_17 ) ;
if ( V_154 ) {
V_4 -> V_186 = V_154 -> V_186 + sizeof( struct V_85 ) ;
V_4 -> V_158 = V_154 -> V_158 - sizeof( struct V_85 ) ;
if ( V_4 -> V_158 < V_173 )
V_4 -> V_158 = V_173 ;
}
V_4 -> V_18 = V_95 -> V_13 . V_17 ;
}
static void F_117 ( struct V_1 * V_9 , struct V_22 * V_74 )
{
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
F_8 ( V_11 , V_9 ) ;
F_118 () ;
V_9 -> V_13 . V_14 . V_15 = V_74 -> V_14 . V_15 ;
V_9 -> V_13 . V_14 . V_16 = V_74 -> V_14 . V_16 ;
memcpy ( V_9 -> V_4 -> V_187 , & V_74 -> V_14 . V_15 , 4 ) ;
memcpy ( V_9 -> V_4 -> V_188 , & V_74 -> V_14 . V_16 , 4 ) ;
F_11 ( V_11 , V_9 ) ;
V_9 -> V_13 . V_14 . V_110 = V_74 -> V_14 . V_110 ;
V_9 -> V_13 . V_14 . V_132 = V_74 -> V_14 . V_132 ;
if ( V_9 -> V_13 . V_17 != V_74 -> V_17 ) {
V_9 -> V_13 . V_17 = V_74 -> V_17 ;
F_115 ( V_9 -> V_4 ) ;
}
F_119 ( V_9 -> V_4 ) ;
}
static int F_120 ( struct V_1 * V_9 ,
struct V_189 * V_30 )
{
struct V_91 V_31 ;
T_1 V_32 ;
if ( V_30 -> V_34 > 32 ||
V_30 -> V_33 + ( 32 - V_30 -> V_34 ) > 64 )
return - V_75 ;
F_121 ( & V_31 , & V_30 -> V_31 , V_30 -> V_33 ) ;
if ( ! F_122 ( & V_31 , & V_30 -> V_31 ) )
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
F_119 ( V_9 -> V_4 ) ;
return 0 ;
}
static int
F_123 ( struct V_3 * V_4 , struct V_190 * V_191 , int V_192 )
{
int V_36 = 0 ;
struct V_22 V_74 ;
struct V_56 V_55 ;
struct V_1 * V_9 ;
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
#ifdef F_13
struct V_189 V_30 ;
#endif
switch ( V_192 ) {
case V_193 :
#ifdef F_13
case V_194 :
#endif
V_9 = NULL ;
if ( V_4 == V_11 -> V_29 ) {
if ( F_30 ( & V_74 , V_191 -> V_195 . V_196 , sizeof( V_74 ) ) ) {
V_36 = - V_65 ;
break;
}
V_9 = F_22 ( V_2 , & V_74 , 0 ) ;
}
if ( V_9 == NULL )
V_9 = F_14 ( V_4 ) ;
V_36 = - V_65 ;
if ( V_192 == V_193 ) {
memcpy ( & V_74 , & V_9 -> V_13 , sizeof( V_74 ) ) ;
if ( F_35 ( V_191 -> V_195 . V_196 , & V_74 ,
sizeof( V_74 ) ) )
goto V_197;
#ifdef F_13
} else {
V_30 . V_31 = V_9 -> V_30 . V_31 ;
V_30 . V_32 = V_9 -> V_30 . V_32 ;
V_30 . V_33 = V_9 -> V_30 . V_33 ;
V_30 . V_34 = V_9 -> V_30 . V_34 ;
if ( F_35 ( V_191 -> V_195 . V_196 , & V_30 ,
sizeof( V_30 ) ) )
goto V_197;
#endif
}
V_36 = 0 ;
break;
case V_198 :
case V_199 :
V_36 = - V_200 ;
if ( ! F_124 ( V_2 -> V_201 , V_68 ) )
goto V_197;
V_36 = - V_65 ;
if ( F_30 ( & V_74 , V_191 -> V_195 . V_196 , sizeof( V_74 ) ) )
goto V_197;
V_36 = - V_75 ;
if ( V_74 . V_14 . V_125 != V_109 &&
V_74 . V_14 . V_125 != V_136 &&
V_74 . V_14 . V_125 != 0 )
goto V_197;
if ( V_74 . V_14 . V_202 != 4 ||
V_74 . V_14 . V_203 != 5 || ( V_74 . V_14 . V_151 & F_71 ( ~ V_204 ) ) )
goto V_197;
if ( V_74 . V_14 . V_110 )
V_74 . V_14 . V_151 |= F_71 ( V_204 ) ;
V_9 = F_22 ( V_2 , & V_74 , V_192 == V_198 ) ;
if ( V_4 != V_11 -> V_29 && V_192 == V_199 ) {
if ( V_9 != NULL ) {
if ( V_9 -> V_4 != V_4 ) {
V_36 = - V_76 ;
break;
}
} else {
if ( ( ( V_4 -> V_19 & V_122 ) && ! V_74 . V_14 . V_16 ) ||
( ! ( V_4 -> V_19 & V_122 ) && V_74 . V_14 . V_16 ) ) {
V_36 = - V_75 ;
break;
}
V_9 = F_14 ( V_4 ) ;
}
F_117 ( V_9 , & V_74 ) ;
}
if ( V_9 ) {
V_36 = 0 ;
if ( F_35 ( V_191 -> V_195 . V_196 , & V_9 -> V_13 , sizeof( V_74 ) ) )
V_36 = - V_65 ;
} else
V_36 = ( V_192 == V_198 ? - V_78 : - V_106 ) ;
break;
case V_205 :
V_36 = - V_200 ;
if ( ! F_124 ( V_2 -> V_201 , V_68 ) )
goto V_197;
if ( V_4 == V_11 -> V_29 ) {
V_36 = - V_65 ;
if ( F_30 ( & V_74 , V_191 -> V_195 . V_196 , sizeof( V_74 ) ) )
goto V_197;
V_36 = - V_106 ;
if ( ( V_9 = F_22 ( V_2 , & V_74 , 0 ) ) == NULL )
goto V_197;
V_36 = - V_200 ;
if ( V_9 == F_14 ( V_11 -> V_29 ) )
goto V_197;
V_4 = V_9 -> V_4 ;
}
F_125 ( V_4 ) ;
V_36 = 0 ;
break;
case V_206 :
V_36 = - V_75 ;
if ( V_4 == V_11 -> V_29 )
goto V_197;
V_36 = - V_106 ;
if ( ! ( V_9 = F_14 ( V_4 ) ) )
goto V_197;
V_36 = F_29 ( V_9 , V_191 -> V_195 . V_196 ) ;
break;
case V_207 :
case V_208 :
case V_209 :
V_36 = - V_200 ;
if ( ! F_124 ( V_2 -> V_201 , V_68 ) )
goto V_197;
V_36 = - V_75 ;
if ( V_4 == V_11 -> V_29 )
goto V_197;
V_36 = - V_65 ;
if ( F_30 ( & V_55 , V_191 -> V_195 . V_196 , sizeof( V_55 ) ) )
goto V_197;
V_36 = - V_106 ;
if ( ! ( V_9 = F_14 ( V_4 ) ) )
goto V_197;
switch ( V_192 ) {
case V_208 :
V_36 = F_44 ( V_9 , & V_55 ) ;
break;
case V_207 :
case V_209 :
V_36 = F_38 ( V_9 , & V_55 , V_192 == V_209 ) ;
break;
}
F_119 ( V_4 ) ;
break;
#ifdef F_13
case V_210 :
case V_211 :
case V_212 :
V_36 = - V_200 ;
if ( ! F_124 ( V_2 -> V_201 , V_68 ) )
goto V_197;
V_36 = - V_65 ;
if ( F_30 ( & V_30 , V_191 -> V_195 . V_196 ,
sizeof( V_30 ) ) )
goto V_197;
V_9 = F_14 ( V_4 ) ;
if ( V_192 != V_212 ) {
V_36 = F_120 ( V_9 , & V_30 ) ;
if ( V_36 < 0 )
goto V_197;
} else
F_12 ( V_4 , V_11 ) ;
V_36 = 0 ;
break;
#endif
default:
V_36 = - V_75 ;
}
V_197:
return V_36 ;
}
static int F_126 ( struct V_3 * V_4 , int V_213 )
{
if ( V_213 < V_173 || V_213 > 0xFFF8 - sizeof( struct V_85 ) )
return - V_75 ;
V_4 -> V_158 = V_213 ;
return 0 ;
}
static void F_26 ( struct V_3 * V_4 )
{
F_127 ( V_4 -> V_124 ) ;
F_128 ( V_4 ) ;
}
static void V_51 ( struct V_3 * V_4 )
{
V_4 -> V_214 = & V_215 ;
V_4 -> V_216 = F_26 ;
V_4 -> type = V_217 ;
V_4 -> V_186 = V_218 + sizeof( struct V_85 ) ;
V_4 -> V_158 = V_219 - sizeof( struct V_85 ) ;
V_4 -> V_19 = V_220 ;
V_4 -> V_42 &= ~ V_221 ;
V_4 -> V_18 = 0 ;
V_4 -> V_222 = 4 ;
V_4 -> V_223 |= V_224 ;
}
static int F_19 ( struct V_3 * V_4 )
{
struct V_1 * V_95 = F_14 ( V_4 ) ;
V_95 -> V_4 = V_4 ;
V_95 -> V_2 = F_18 ( V_4 ) ;
memcpy ( V_4 -> V_187 , & V_95 -> V_13 . V_14 . V_15 , 4 ) ;
memcpy ( V_4 -> V_188 , & V_95 -> V_13 . V_14 . V_16 , 4 ) ;
F_115 ( V_4 ) ;
V_4 -> V_124 = F_129 ( struct V_123 ) ;
if ( ! V_4 -> V_124 )
return - V_72 ;
return 0 ;
}
static int T_8 F_130 ( struct V_3 * V_4 )
{
struct V_1 * V_95 = F_14 ( V_4 ) ;
struct V_85 * V_14 = & V_95 -> V_13 . V_14 ;
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
V_95 -> V_4 = V_4 ;
V_95 -> V_2 = F_18 ( V_4 ) ;
strcpy ( V_95 -> V_13 . V_44 , V_4 -> V_44 ) ;
V_14 -> V_202 = 4 ;
V_14 -> V_125 = V_109 ;
V_14 -> V_203 = 5 ;
V_14 -> V_110 = 64 ;
V_4 -> V_124 = F_129 ( struct V_123 ) ;
if ( ! V_4 -> V_124 )
return - V_72 ;
F_21 ( V_4 ) ;
F_10 ( V_11 -> V_21 [ 0 ] , V_95 ) ;
return 0 ;
}
static int F_131 ( struct V_225 * V_226 [] , struct V_225 * V_97 [] )
{
T_6 V_140 ;
if ( ! V_97 || ! V_97 [ V_227 ] )
return 0 ;
V_140 = F_132 ( V_97 [ V_227 ] ) ;
if ( V_140 != V_109 &&
V_140 != V_136 &&
V_140 != 0 )
return - V_75 ;
return 0 ;
}
static void F_133 ( struct V_225 * V_97 [] ,
struct V_22 * V_13 )
{
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_14 . V_202 = 4 ;
V_13 -> V_14 . V_125 = V_109 ;
V_13 -> V_14 . V_203 = 5 ;
V_13 -> V_14 . V_110 = 64 ;
if ( ! V_97 )
return;
if ( V_97 [ V_228 ] )
V_13 -> V_17 = F_134 ( V_97 [ V_228 ] ) ;
if ( V_97 [ V_229 ] )
V_13 -> V_14 . V_15 = F_135 ( V_97 [ V_229 ] ) ;
if ( V_97 [ V_230 ] )
V_13 -> V_14 . V_16 = F_135 ( V_97 [ V_230 ] ) ;
if ( V_97 [ V_231 ] ) {
V_13 -> V_14 . V_110 = F_132 ( V_97 [ V_231 ] ) ;
if ( V_13 -> V_14 . V_110 )
V_13 -> V_14 . V_151 = F_71 ( V_204 ) ;
}
if ( V_97 [ V_232 ] )
V_13 -> V_14 . V_132 = F_132 ( V_97 [ V_232 ] ) ;
if ( ! V_97 [ V_233 ] || F_132 ( V_97 [ V_233 ] ) )
V_13 -> V_14 . V_151 = F_71 ( V_204 ) ;
if ( V_97 [ V_234 ] )
V_13 -> V_40 = F_136 ( V_97 [ V_234 ] ) ;
if ( V_97 [ V_227 ] )
V_13 -> V_14 . V_125 = F_132 ( V_97 [ V_227 ] ) ;
}
static bool F_137 ( struct V_225 * V_97 [] ,
struct V_189 * V_30 )
{
bool V_64 = false ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
if ( ! V_97 )
return V_64 ;
if ( V_97 [ V_235 ] ) {
V_64 = true ;
F_138 ( & V_30 -> V_31 , V_97 [ V_235 ] ,
sizeof( struct V_91 ) ) ;
}
if ( V_97 [ V_236 ] ) {
V_64 = true ;
V_30 -> V_32 =
F_135 ( V_97 [ V_236 ] ) ;
}
if ( V_97 [ V_237 ] ) {
V_64 = true ;
V_30 -> V_33 = F_139 ( V_97 [ V_237 ] ) ;
}
if ( V_97 [ V_238 ] ) {
V_64 = true ;
V_30 -> V_34 =
F_139 ( V_97 [ V_238 ] ) ;
}
return V_64 ;
}
static int F_140 ( struct V_2 * V_239 , struct V_3 * V_4 ,
struct V_225 * V_226 [] , struct V_225 * V_97 [] )
{
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_1 * V_48 ;
#ifdef F_13
struct V_189 V_30 ;
#endif
int V_36 ;
V_48 = F_14 ( V_4 ) ;
F_133 ( V_97 , & V_48 -> V_13 ) ;
if ( F_22 ( V_2 , & V_48 -> V_13 , 0 ) )
return - V_76 ;
V_36 = F_17 ( V_4 ) ;
if ( V_36 < 0 )
return V_36 ;
#ifdef F_13
if ( F_137 ( V_97 , & V_30 ) )
V_36 = F_120 ( V_48 , & V_30 ) ;
#endif
return V_36 ;
}
static int F_141 ( struct V_3 * V_4 , struct V_225 * V_226 [] ,
struct V_225 * V_97 [] )
{
struct V_1 * V_9 = F_14 ( V_4 ) ;
struct V_22 V_74 ;
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
#ifdef F_13
struct V_189 V_30 ;
#endif
if ( V_4 == V_11 -> V_29 )
return - V_75 ;
F_133 ( V_97 , & V_74 ) ;
if ( ( ( V_4 -> V_19 & V_122 ) && ! V_74 . V_14 . V_16 ) ||
( ! ( V_4 -> V_19 & V_122 ) && V_74 . V_14 . V_16 ) )
return - V_75 ;
V_9 = F_22 ( V_2 , & V_74 , 0 ) ;
if ( V_9 ) {
if ( V_9 -> V_4 != V_4 )
return - V_76 ;
} else
V_9 = F_14 ( V_4 ) ;
F_117 ( V_9 , & V_74 ) ;
#ifdef F_13
if ( F_137 ( V_97 , & V_30 ) )
return F_120 ( V_9 , & V_30 ) ;
#endif
return 0 ;
}
static T_9 F_142 ( const struct V_3 * V_4 )
{
return
F_143 ( 4 ) +
F_143 ( 4 ) +
F_143 ( 4 ) +
F_143 ( 1 ) +
F_143 ( 1 ) +
F_143 ( 1 ) +
F_143 ( 2 ) +
F_143 ( 1 ) +
#ifdef F_13
F_143 ( sizeof( struct V_91 ) ) +
F_143 ( 4 ) +
F_143 ( 2 ) +
F_143 ( 2 ) +
#endif
0 ;
}
static int F_144 ( struct V_83 * V_84 , const struct V_3 * V_4 )
{
struct V_1 * V_95 = F_14 ( V_4 ) ;
struct V_22 * V_240 = & V_95 -> V_13 ;
if ( F_145 ( V_84 , V_228 , V_240 -> V_17 ) ||
F_146 ( V_84 , V_229 , V_240 -> V_14 . V_15 ) ||
F_146 ( V_84 , V_230 , V_240 -> V_14 . V_16 ) ||
F_147 ( V_84 , V_231 , V_240 -> V_14 . V_110 ) ||
F_147 ( V_84 , V_232 , V_240 -> V_14 . V_132 ) ||
F_147 ( V_84 , V_233 ,
! ! ( V_240 -> V_14 . V_151 & F_71 ( V_204 ) ) ) ||
F_147 ( V_84 , V_227 , V_240 -> V_14 . V_125 ) ||
F_148 ( V_84 , V_234 , V_240 -> V_40 ) )
goto V_241;
#ifdef F_13
if ( F_149 ( V_84 , V_235 , sizeof( struct V_91 ) ,
& V_95 -> V_30 . V_31 ) ||
F_146 ( V_84 , V_236 ,
V_95 -> V_30 . V_32 ) ||
F_150 ( V_84 , V_237 ,
V_95 -> V_30 . V_33 ) ||
F_150 ( V_84 , V_238 ,
V_95 -> V_30 . V_34 ) )
goto V_241;
#endif
return 0 ;
V_241:
return - V_242 ;
}
static void T_10 F_151 ( struct V_10 * V_11 , struct V_243 * V_80 )
{
struct V_2 * V_2 = F_18 ( V_11 -> V_29 ) ;
struct V_3 * V_4 , * V_244 ;
int V_24 ;
F_152 (net, dev, aux)
if ( V_4 -> V_45 == & V_46 )
F_153 ( V_4 , V_80 ) ;
for ( V_24 = 1 ; V_24 < 4 ; V_24 ++ ) {
int V_23 ;
for ( V_23 = 0 ; V_23 < V_245 ; V_23 ++ ) {
struct V_1 * V_9 ;
V_9 = F_9 ( V_11 -> V_25 [ V_24 ] [ V_23 ] ) ;
while ( V_9 != NULL ) {
if ( ! F_110 ( F_18 ( V_9 -> V_4 ) , V_2 ) )
F_153 ( V_9 -> V_4 ,
V_80 ) ;
V_9 = F_9 ( V_9 -> V_28 ) ;
}
}
}
}
static int T_8 F_154 ( struct V_2 * V_2 )
{
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
struct V_1 * V_9 ;
int V_36 ;
V_11 -> V_25 [ 0 ] = V_11 -> V_21 ;
V_11 -> V_25 [ 1 ] = V_11 -> V_246 ;
V_11 -> V_25 [ 2 ] = V_11 -> V_247 ;
V_11 -> V_25 [ 3 ] = V_11 -> V_248 ;
V_11 -> V_29 = F_24 ( sizeof( struct V_1 ) , L_6 ,
V_51 ) ;
if ( ! V_11 -> V_29 ) {
V_36 = - V_72 ;
goto V_249;
}
F_25 ( V_11 -> V_29 , V_2 ) ;
V_11 -> V_29 -> V_45 = & V_46 ;
V_11 -> V_29 -> V_223 |= V_250 ;
V_36 = F_130 ( V_11 -> V_29 ) ;
if ( V_36 )
goto V_251;
F_12 ( V_11 -> V_29 , V_11 ) ;
if ( ( V_36 = F_155 ( V_11 -> V_29 ) ) )
goto V_252;
V_9 = F_14 ( V_11 -> V_29 ) ;
strcpy ( V_9 -> V_13 . V_44 , V_11 -> V_29 -> V_44 ) ;
return 0 ;
V_252:
F_53 ( V_11 -> V_29 ) ;
V_251:
F_26 ( V_11 -> V_29 ) ;
V_249:
return V_36 ;
}
static void T_10 F_156 ( struct V_2 * V_2 )
{
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
F_157 ( V_253 ) ;
F_158 () ;
F_151 ( V_11 , & V_253 ) ;
F_159 ( & V_253 ) ;
F_160 () ;
}
static void T_11 F_161 ( void )
{
F_162 ( & V_46 ) ;
F_163 ( & V_254 , V_255 ) ;
F_163 ( & V_256 , V_257 ) ;
F_164 ( & V_258 ) ;
F_165 () ;
}
static int T_12 F_166 ( void )
{
int V_36 ;
F_167 ( L_7 ) ;
V_36 = F_168 ( & V_258 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_169 ( & V_254 , V_255 ) ;
if ( V_36 < 0 ) {
F_167 ( L_8 , V_259 ) ;
goto V_260;
}
V_36 = F_169 ( & V_256 , V_257 ) ;
if ( V_36 < 0 ) {
F_167 ( L_9 , V_259 ) ;
goto V_261;
}
V_36 = F_170 ( & V_46 ) ;
if ( V_36 < 0 )
goto V_262;
V_37:
return V_36 ;
V_262:
F_163 ( & V_256 , V_257 ) ;
V_261:
F_163 ( & V_254 , V_255 ) ;
V_260:
F_164 ( & V_258 ) ;
goto V_37;
}
