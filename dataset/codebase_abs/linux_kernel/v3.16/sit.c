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
F_53 ( V_95 ) ;
F_54 ( V_4 ) ;
}
static int F_55 ( struct V_83 * V_84 )
{
const struct V_85 * V_14 = ( const struct V_85 * ) V_84 -> V_96 ;
struct V_97 * V_98 ;
struct V_83 * V_99 ;
if ( ! F_56 ( V_84 , V_14 -> V_100 * 4 + sizeof( struct V_101 ) + 8 ) )
return 1 ;
V_99 = F_57 ( V_84 , V_71 ) ;
if ( ! V_99 )
return 1 ;
F_58 ( V_99 ) ;
F_59 ( V_99 , V_14 -> V_100 * 4 ) ;
F_60 ( V_99 ) ;
V_98 = F_61 ( F_18 ( V_84 -> V_4 ) , & F_48 ( V_99 ) -> V_15 , NULL , 0 , 0 ) ;
if ( V_98 && V_98 -> V_102 . V_4 )
V_99 -> V_4 = V_98 -> V_102 . V_4 ;
F_62 ( V_99 , V_103 , V_104 , 0 ) ;
if ( V_98 )
F_63 ( V_98 ) ;
F_64 ( V_99 ) ;
return 0 ;
}
static int F_65 ( struct V_83 * V_84 , T_4 V_105 )
{
const struct V_85 * V_14 = ( const struct V_85 * ) V_84 -> V_96 ;
const int type = F_66 ( V_84 ) -> type ;
const int V_106 = F_66 ( V_84 ) -> V_106 ;
struct V_1 * V_9 ;
int V_36 ;
switch ( type ) {
default:
case V_107 :
return 0 ;
case V_108 :
switch ( V_106 ) {
case V_109 :
return 0 ;
default:
break;
}
break;
case V_110 :
if ( V_106 != V_111 )
return 0 ;
break;
case V_112 :
break;
}
V_36 = - V_113 ;
V_9 = F_1 ( F_18 ( V_84 -> V_4 ) ,
V_84 -> V_4 ,
V_14 -> V_16 ,
V_14 -> V_15 ) ;
if ( V_9 == NULL )
goto V_37;
if ( type == V_108 && V_106 == V_114 ) {
F_67 ( V_84 , F_18 ( V_84 -> V_4 ) , V_105 ,
V_9 -> V_13 . V_17 , 0 , V_115 , 0 ) ;
V_36 = 0 ;
goto V_37;
}
if ( type == V_112 ) {
F_68 ( V_84 , F_18 ( V_84 -> V_4 ) , V_9 -> V_13 . V_17 , 0 ,
V_115 , 0 ) ;
V_36 = 0 ;
goto V_37;
}
if ( V_9 -> V_13 . V_14 . V_16 == 0 )
goto V_37;
V_36 = 0 ;
if ( ! F_55 ( V_84 ) )
goto V_37;
if ( V_9 -> V_13 . V_14 . V_116 == 0 && type == V_110 )
goto V_37;
if ( F_69 ( V_117 , V_9 -> V_118 + V_119 ) )
V_9 -> V_120 ++ ;
else
V_9 -> V_120 = 1 ;
V_9 -> V_118 = V_117 ;
V_37:
return V_36 ;
}
static inline bool F_70 ( struct V_1 * V_95 , const T_1 V_121 ,
const struct V_91 * V_122 )
{
T_1 V_123 = 0 ;
if ( F_71 ( V_95 , V_122 , & V_123 ) && V_121 != V_123 )
return true ;
return false ;
}
static bool F_72 ( const struct V_1 * V_95 ,
const struct V_91 * V_124 )
{
int V_125 ;
#ifdef F_13
V_125 = V_95 -> V_30 . V_33 + 32
- V_95 -> V_30 . V_34 ;
#else
V_125 = 48 ;
#endif
return F_73 ( V_124 , V_125 , V_95 -> V_4 ) ;
}
static bool F_74 ( struct V_83 * V_84 ,
const struct V_85 * V_14 ,
struct V_1 * V_95 )
{
const struct V_101 * V_126 ;
if ( V_95 -> V_4 -> V_42 & V_43 ) {
if ( ! F_47 ( V_84 , V_14 , V_95 ) )
return true ;
return false ;
}
if ( V_95 -> V_4 -> V_19 & V_127 )
return false ;
V_126 = F_48 ( V_84 ) ;
if ( F_75 ( F_70 ( V_95 , V_14 -> V_15 , & V_126 -> V_15 ) ) ) {
F_76 ( L_2 ,
& V_14 -> V_15 , & V_126 -> V_15 ,
& V_14 -> V_16 , & V_126 -> V_16 ) ;
return true ;
}
if ( F_77 ( ! F_70 ( V_95 , V_14 -> V_16 , & V_126 -> V_16 ) ) )
return false ;
if ( F_72 ( V_95 , & V_126 -> V_16 ) )
return false ;
F_76 ( L_3 ,
& V_14 -> V_15 , & V_126 -> V_15 ,
& V_14 -> V_16 , & V_126 -> V_16 ) ;
return true ;
}
static int F_78 ( struct V_83 * V_84 )
{
const struct V_85 * V_14 = F_79 ( V_84 ) ;
struct V_1 * V_95 ;
int V_36 ;
V_95 = F_1 ( F_18 ( V_84 -> V_4 ) , V_84 -> V_4 ,
V_14 -> V_15 , V_14 -> V_16 ) ;
if ( V_95 != NULL ) {
struct V_128 * V_129 ;
if ( V_95 -> V_13 . V_14 . V_130 != V_115 &&
V_95 -> V_13 . V_14 . V_130 != 0 )
goto V_37;
V_84 -> V_131 = V_84 -> V_132 ;
F_60 ( V_84 ) ;
F_80 ( V_84 ) -> V_19 = 0 ;
V_84 -> V_130 = F_81 ( V_133 ) ;
if ( F_74 ( V_84 , V_14 , V_95 ) ) {
V_95 -> V_4 -> V_134 . V_135 ++ ;
goto V_37;
}
F_82 ( V_84 , V_95 -> V_4 , V_95 -> V_2 ) ;
V_36 = F_83 ( V_14 , V_84 ) ;
if ( F_75 ( V_36 ) ) {
if ( V_136 )
F_84 ( L_4 ,
& V_14 -> V_15 , V_14 -> V_137 ) ;
if ( V_36 > 1 ) {
++ V_95 -> V_4 -> V_134 . V_138 ;
++ V_95 -> V_4 -> V_134 . V_135 ;
goto V_37;
}
}
V_129 = F_85 ( V_95 -> V_4 -> V_129 ) ;
F_86 ( & V_129 -> V_139 ) ;
V_129 -> V_140 ++ ;
V_129 -> V_141 += V_84 -> V_63 ;
F_87 ( & V_129 -> V_139 ) ;
F_88 ( V_84 ) ;
return 0 ;
}
return 1 ;
V_37:
F_64 ( V_84 ) ;
return 0 ;
}
static int F_89 ( struct V_83 * V_84 )
{
const struct V_85 * V_14 ;
struct V_1 * V_95 ;
V_14 = F_79 ( V_84 ) ;
V_95 = F_1 ( F_18 ( V_84 -> V_4 ) , V_84 -> V_4 ,
V_14 -> V_15 , V_14 -> V_16 ) ;
if ( V_95 != NULL ) {
if ( V_95 -> V_13 . V_14 . V_130 != V_142 &&
V_95 -> V_13 . V_14 . V_130 != 0 )
goto V_143;
if ( ! F_90 ( NULL , V_144 , V_84 ) )
goto V_143;
if ( F_91 ( V_84 , 0 , V_145 . V_146 ) )
goto V_143;
return F_92 ( V_95 , V_84 , & V_145 , V_136 ) ;
}
return 1 ;
V_143:
F_64 ( V_84 ) ;
return 0 ;
}
static bool F_71 ( struct V_1 * V_95 , const struct V_91 * V_124 ,
T_1 * V_147 )
{
#ifdef F_13
if ( F_93 ( V_124 , & V_95 -> V_30 . V_31 ,
V_95 -> V_30 . V_33 ) ) {
unsigned int V_148 , V_149 ;
int V_150 ;
T_4 V_151 ;
V_148 = V_95 -> V_30 . V_33 >> 5 ;
V_149 = V_95 -> V_30 . V_33 & 0x1f ;
V_151 = ( F_94 ( V_124 -> V_93 [ V_148 ] ) << V_149 ) >>
V_95 -> V_30 . V_34 ;
V_150 = V_149 - V_95 -> V_30 . V_34 ;
if ( V_150 > 0 )
V_151 |= F_94 ( V_124 -> V_93 [ V_148 + 1 ] ) >>
( 32 - V_150 ) ;
* V_147 = V_95 -> V_30 . V_32 | F_16 ( V_151 ) ;
return true ;
}
#else
if ( V_124 -> V_152 [ 0 ] == F_81 ( 0x2002 ) ) {
memcpy ( V_147 , & V_124 -> V_152 [ 1 ] , 4 ) ;
return true ;
}
#endif
return false ;
}
static inline T_1 F_95 ( struct V_1 * V_95 ,
const struct V_91 * V_124 )
{
T_1 V_102 = 0 ;
F_71 ( V_95 , V_124 , & V_102 ) ;
return V_102 ;
}
static T_5 F_96 ( struct V_83 * V_84 ,
struct V_3 * V_4 )
{
struct V_1 * V_95 = F_14 ( V_4 ) ;
const struct V_85 * V_153 = & V_95 -> V_13 . V_14 ;
const struct V_101 * V_154 = F_48 ( V_84 ) ;
T_6 V_137 = V_95 -> V_13 . V_14 . V_137 ;
T_7 V_155 = V_153 -> V_156 ;
struct V_157 * V_98 ;
struct V_3 * V_158 ;
unsigned int V_159 ;
T_1 V_102 = V_153 -> V_16 ;
struct V_160 V_161 ;
int V_162 ;
const struct V_91 * V_92 ;
int V_163 ;
T_6 V_116 ;
int V_36 ;
if ( V_84 -> V_130 != F_81 ( V_133 ) )
goto V_164;
if ( V_137 == 1 )
V_137 = F_97 ( V_154 ) ;
if ( V_4 -> V_42 & V_43 ) {
struct V_165 * V_166 = NULL ;
bool V_167 = false ;
if ( F_98 ( V_84 ) )
V_166 = F_99 ( F_98 ( V_84 ) , & V_154 -> V_16 ) ;
if ( V_166 == NULL ) {
F_100 ( L_5 ) ;
goto V_164;
}
V_92 = ( const struct V_91 * ) & V_166 -> V_168 ;
V_163 = F_101 ( V_92 ) ;
if ( ( V_163 & V_169 ) &&
F_49 ( V_92 ) )
V_102 = V_92 -> V_93 [ 3 ] ;
else
V_167 = true ;
F_102 ( V_166 ) ;
if ( V_167 )
goto V_164;
}
if ( ! V_102 )
V_102 = F_95 ( V_95 , & V_154 -> V_16 ) ;
if ( ! V_102 ) {
struct V_165 * V_166 = NULL ;
bool V_167 = false ;
if ( F_98 ( V_84 ) )
V_166 = F_99 ( F_98 ( V_84 ) , & V_154 -> V_16 ) ;
if ( V_166 == NULL ) {
F_100 ( L_5 ) ;
goto V_164;
}
V_92 = ( const struct V_91 * ) & V_166 -> V_168 ;
V_163 = F_101 ( V_92 ) ;
if ( V_163 == V_170 ) {
V_92 = & F_48 ( V_84 ) -> V_16 ;
V_163 = F_101 ( V_92 ) ;
}
if ( ( V_163 & V_171 ) != 0 )
V_102 = V_92 -> V_93 [ 3 ] ;
else
V_167 = true ;
F_102 ( V_166 ) ;
if ( V_167 )
goto V_164;
}
V_98 = F_103 ( V_95 -> V_2 , & V_161 , NULL ,
V_102 , V_153 -> V_15 ,
0 , 0 ,
V_115 , F_104 ( V_137 ) ,
V_95 -> V_13 . V_17 ) ;
if ( F_105 ( V_98 ) ) {
V_4 -> V_134 . V_172 ++ ;
goto V_173;
}
if ( V_98 -> V_174 != V_175 ) {
F_106 ( V_98 ) ;
V_4 -> V_134 . V_172 ++ ;
goto V_173;
}
V_158 = V_98 -> V_102 . V_4 ;
if ( V_158 == V_4 ) {
F_106 ( V_98 ) ;
V_4 -> V_134 . V_176 ++ ;
goto V_164;
}
if ( V_155 ) {
V_162 = F_107 ( & V_98 -> V_102 ) - sizeof( struct V_85 ) ;
if ( V_162 < 68 ) {
V_4 -> V_134 . V_176 ++ ;
F_106 ( V_98 ) ;
goto V_164;
}
if ( V_162 < V_177 ) {
V_162 = V_177 ;
V_155 = 0 ;
}
if ( V_95 -> V_13 . V_14 . V_16 && F_98 ( V_84 ) )
F_98 ( V_84 ) -> V_178 -> V_179 ( F_98 ( V_84 ) , NULL , V_84 , V_162 ) ;
if ( V_84 -> V_63 > V_162 && ! F_108 ( V_84 ) ) {
F_62 ( V_84 , V_180 , 0 , V_162 ) ;
F_106 ( V_98 ) ;
goto V_164;
}
}
if ( V_95 -> V_120 > 0 ) {
if ( F_69 ( V_117 ,
V_95 -> V_118 + V_119 ) ) {
V_95 -> V_120 -- ;
F_109 ( V_84 ) ;
} else
V_95 -> V_120 = 0 ;
}
V_159 = F_110 ( V_158 ) + sizeof( struct V_85 ) ;
if ( F_111 ( V_84 ) < V_159 || F_112 ( V_84 ) ||
( F_113 ( V_84 ) && ! F_114 ( V_84 , 0 ) ) ) {
struct V_83 * V_181 = F_115 ( V_84 , V_159 ) ;
if ( ! V_181 ) {
F_106 ( V_98 ) ;
V_4 -> V_134 . V_182 ++ ;
F_64 ( V_84 ) ;
return V_183 ;
}
if ( V_84 -> V_184 )
F_116 ( V_181 , V_84 -> V_184 ) ;
F_117 ( V_84 ) ;
V_84 = V_181 ;
V_154 = F_48 ( V_84 ) ;
}
V_116 = V_153 -> V_116 ;
if ( V_116 == 0 )
V_116 = V_154 -> V_185 ;
V_137 = F_118 ( V_137 , F_97 ( V_154 ) ) ;
V_84 = F_119 ( V_84 , false , V_186 ) ;
if ( F_105 ( V_84 ) ) {
F_106 ( V_98 ) ;
goto V_37;
}
V_36 = F_120 ( V_84 -> V_184 , V_98 , V_84 , V_161 . V_15 , V_161 . V_16 ,
V_115 , V_137 , V_116 , V_155 ,
! F_121 ( V_95 -> V_2 , F_18 ( V_4 ) ) ) ;
F_122 ( V_36 , & V_4 -> V_134 , V_4 -> V_129 ) ;
return V_183 ;
V_173:
F_109 ( V_84 ) ;
V_164:
F_64 ( V_84 ) ;
V_37:
V_4 -> V_134 . V_187 ++ ;
return V_183 ;
}
static T_5 F_123 ( struct V_83 * V_84 , struct V_3 * V_4 )
{
struct V_1 * V_95 = F_14 ( V_4 ) ;
const struct V_85 * V_153 = & V_95 -> V_13 . V_14 ;
V_84 = F_119 ( V_84 , false , V_188 ) ;
if ( F_105 ( V_84 ) )
goto V_37;
F_124 ( V_84 , V_4 , V_153 , V_142 ) ;
return V_183 ;
V_37:
V_4 -> V_134 . V_187 ++ ;
return V_183 ;
}
static T_5 F_125 ( struct V_83 * V_84 ,
struct V_3 * V_4 )
{
switch ( V_84 -> V_130 ) {
case F_81 ( V_189 ) :
F_123 ( V_84 , V_4 ) ;
break;
case F_81 ( V_133 ) :
F_96 ( V_84 , V_4 ) ;
break;
default:
goto V_190;
}
return V_183 ;
V_190:
V_4 -> V_134 . V_187 ++ ;
F_64 ( V_84 ) ;
return V_183 ;
}
static void F_126 ( struct V_3 * V_4 )
{
struct V_3 * V_158 = NULL ;
struct V_1 * V_95 ;
const struct V_85 * V_14 ;
struct V_160 V_161 ;
V_95 = F_14 ( V_4 ) ;
V_14 = & V_95 -> V_13 . V_14 ;
if ( V_14 -> V_16 ) {
struct V_157 * V_98 = F_103 ( V_95 -> V_2 , & V_161 ,
NULL ,
V_14 -> V_16 , V_14 -> V_15 ,
0 , 0 ,
V_115 ,
F_104 ( V_14 -> V_137 ) ,
V_95 -> V_13 . V_17 ) ;
if ( ! F_105 ( V_98 ) ) {
V_158 = V_98 -> V_102 . V_4 ;
F_106 ( V_98 ) ;
}
V_4 -> V_19 |= V_127 ;
}
if ( ! V_158 && V_95 -> V_13 . V_17 )
V_158 = F_127 ( V_95 -> V_2 , V_95 -> V_13 . V_17 ) ;
if ( V_158 ) {
V_4 -> V_191 = V_158 -> V_191 + sizeof( struct V_85 ) ;
V_4 -> V_162 = V_158 -> V_162 - sizeof( struct V_85 ) ;
if ( V_4 -> V_162 < V_177 )
V_4 -> V_162 = V_177 ;
}
V_4 -> V_18 = V_95 -> V_13 . V_17 ;
}
static void F_128 ( struct V_1 * V_9 , struct V_22 * V_74 )
{
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
F_8 ( V_11 , V_9 ) ;
F_129 () ;
V_9 -> V_13 . V_14 . V_15 = V_74 -> V_14 . V_15 ;
V_9 -> V_13 . V_14 . V_16 = V_74 -> V_14 . V_16 ;
memcpy ( V_9 -> V_4 -> V_192 , & V_74 -> V_14 . V_15 , 4 ) ;
memcpy ( V_9 -> V_4 -> V_193 , & V_74 -> V_14 . V_16 , 4 ) ;
F_11 ( V_11 , V_9 ) ;
V_9 -> V_13 . V_14 . V_116 = V_74 -> V_14 . V_116 ;
V_9 -> V_13 . V_14 . V_137 = V_74 -> V_14 . V_137 ;
if ( V_9 -> V_13 . V_17 != V_74 -> V_17 ) {
V_9 -> V_13 . V_17 = V_74 -> V_17 ;
F_126 ( V_9 -> V_4 ) ;
}
F_53 ( V_9 ) ;
F_130 ( V_9 -> V_4 ) ;
}
static int F_131 ( struct V_1 * V_9 ,
struct V_194 * V_30 )
{
struct V_91 V_31 ;
T_1 V_32 ;
if ( V_30 -> V_34 > 32 ||
V_30 -> V_33 + ( 32 - V_30 -> V_34 ) > 64 )
return - V_75 ;
F_132 ( & V_31 , & V_30 -> V_31 , V_30 -> V_33 ) ;
if ( ! F_133 ( & V_31 , & V_30 -> V_31 ) )
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
F_53 ( V_9 ) ;
F_130 ( V_9 -> V_4 ) ;
return 0 ;
}
static int
F_134 ( struct V_3 * V_4 , struct V_195 * V_196 , int V_197 )
{
int V_36 = 0 ;
struct V_22 V_74 ;
struct V_56 V_55 ;
struct V_1 * V_9 = F_14 ( V_4 ) ;
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
#ifdef F_13
struct V_194 V_30 ;
#endif
switch ( V_197 ) {
case V_198 :
#ifdef F_13
case V_199 :
#endif
if ( V_4 == V_11 -> V_29 ) {
if ( F_30 ( & V_74 , V_196 -> V_200 . V_201 , sizeof( V_74 ) ) ) {
V_36 = - V_65 ;
break;
}
V_9 = F_22 ( V_2 , & V_74 , 0 ) ;
if ( V_9 == NULL )
V_9 = F_14 ( V_4 ) ;
}
V_36 = - V_65 ;
if ( V_197 == V_198 ) {
memcpy ( & V_74 , & V_9 -> V_13 , sizeof( V_74 ) ) ;
if ( F_35 ( V_196 -> V_200 . V_201 , & V_74 ,
sizeof( V_74 ) ) )
goto V_202;
#ifdef F_13
} else {
V_30 . V_31 = V_9 -> V_30 . V_31 ;
V_30 . V_32 = V_9 -> V_30 . V_32 ;
V_30 . V_33 = V_9 -> V_30 . V_33 ;
V_30 . V_34 = V_9 -> V_30 . V_34 ;
if ( F_35 ( V_196 -> V_200 . V_201 , & V_30 ,
sizeof( V_30 ) ) )
goto V_202;
#endif
}
V_36 = 0 ;
break;
case V_203 :
case V_204 :
V_36 = - V_205 ;
if ( ! F_135 ( V_2 -> V_206 , V_68 ) )
goto V_202;
V_36 = - V_65 ;
if ( F_30 ( & V_74 , V_196 -> V_200 . V_201 , sizeof( V_74 ) ) )
goto V_202;
V_36 = - V_75 ;
if ( V_74 . V_14 . V_130 != V_115 &&
V_74 . V_14 . V_130 != V_142 &&
V_74 . V_14 . V_130 != 0 )
goto V_202;
if ( V_74 . V_14 . V_207 != 4 ||
V_74 . V_14 . V_100 != 5 || ( V_74 . V_14 . V_156 & F_81 ( ~ V_208 ) ) )
goto V_202;
if ( V_74 . V_14 . V_116 )
V_74 . V_14 . V_156 |= F_81 ( V_208 ) ;
V_9 = F_22 ( V_2 , & V_74 , V_197 == V_203 ) ;
if ( V_4 != V_11 -> V_29 && V_197 == V_204 ) {
if ( V_9 != NULL ) {
if ( V_9 -> V_4 != V_4 ) {
V_36 = - V_76 ;
break;
}
} else {
if ( ( ( V_4 -> V_19 & V_127 ) && ! V_74 . V_14 . V_16 ) ||
( ! ( V_4 -> V_19 & V_127 ) && V_74 . V_14 . V_16 ) ) {
V_36 = - V_75 ;
break;
}
V_9 = F_14 ( V_4 ) ;
}
F_128 ( V_9 , & V_74 ) ;
}
if ( V_9 ) {
V_36 = 0 ;
if ( F_35 ( V_196 -> V_200 . V_201 , & V_9 -> V_13 , sizeof( V_74 ) ) )
V_36 = - V_65 ;
} else
V_36 = ( V_197 == V_203 ? - V_78 : - V_113 ) ;
break;
case V_209 :
V_36 = - V_205 ;
if ( ! F_135 ( V_2 -> V_206 , V_68 ) )
goto V_202;
if ( V_4 == V_11 -> V_29 ) {
V_36 = - V_65 ;
if ( F_30 ( & V_74 , V_196 -> V_200 . V_201 , sizeof( V_74 ) ) )
goto V_202;
V_36 = - V_113 ;
if ( ( V_9 = F_22 ( V_2 , & V_74 , 0 ) ) == NULL )
goto V_202;
V_36 = - V_205 ;
if ( V_9 == F_14 ( V_11 -> V_29 ) )
goto V_202;
V_4 = V_9 -> V_4 ;
}
F_136 ( V_4 ) ;
V_36 = 0 ;
break;
case V_210 :
V_36 = - V_75 ;
if ( V_4 == V_11 -> V_29 )
goto V_202;
V_36 = F_29 ( V_9 , V_196 -> V_200 . V_201 ) ;
break;
case V_211 :
case V_212 :
case V_213 :
V_36 = - V_205 ;
if ( ! F_135 ( V_2 -> V_206 , V_68 ) )
goto V_202;
V_36 = - V_75 ;
if ( V_4 == V_11 -> V_29 )
goto V_202;
V_36 = - V_65 ;
if ( F_30 ( & V_55 , V_196 -> V_200 . V_201 , sizeof( V_55 ) ) )
goto V_202;
switch ( V_197 ) {
case V_212 :
V_36 = F_44 ( V_9 , & V_55 ) ;
break;
case V_211 :
case V_213 :
V_36 = F_38 ( V_9 , & V_55 , V_197 == V_213 ) ;
break;
}
F_53 ( V_9 ) ;
F_130 ( V_4 ) ;
break;
#ifdef F_13
case V_214 :
case V_215 :
case V_216 :
V_36 = - V_205 ;
if ( ! F_135 ( V_2 -> V_206 , V_68 ) )
goto V_202;
V_36 = - V_65 ;
if ( F_30 ( & V_30 , V_196 -> V_200 . V_201 ,
sizeof( V_30 ) ) )
goto V_202;
if ( V_197 != V_216 ) {
V_36 = F_131 ( V_9 , & V_30 ) ;
if ( V_36 < 0 )
goto V_202;
} else
F_12 ( V_4 , V_11 ) ;
V_36 = 0 ;
break;
#endif
default:
V_36 = - V_75 ;
}
V_202:
return V_36 ;
}
static int F_137 ( struct V_3 * V_4 , int V_217 )
{
if ( V_217 < V_177 || V_217 > 0xFFF8 - sizeof( struct V_85 ) )
return - V_75 ;
V_4 -> V_162 = V_217 ;
return 0 ;
}
static void F_26 ( struct V_3 * V_4 )
{
struct V_1 * V_95 = F_14 ( V_4 ) ;
F_138 ( V_95 -> V_218 ) ;
F_138 ( V_4 -> V_129 ) ;
F_139 ( V_4 ) ;
}
static void V_51 ( struct V_3 * V_4 )
{
V_4 -> V_219 = & V_220 ;
V_4 -> V_221 = F_26 ;
V_4 -> type = V_222 ;
V_4 -> V_191 = V_223 + sizeof( struct V_85 ) ;
V_4 -> V_162 = V_224 - sizeof( struct V_85 ) ;
V_4 -> V_19 = V_225 ;
V_4 -> V_42 &= ~ V_226 ;
V_4 -> V_18 = 0 ;
V_4 -> V_227 = 4 ;
V_4 -> V_228 |= V_229 ;
V_4 -> V_228 |= V_230 ;
V_4 -> V_231 |= V_230 ;
}
static int F_19 ( struct V_3 * V_4 )
{
struct V_1 * V_95 = F_14 ( V_4 ) ;
V_95 -> V_4 = V_4 ;
V_95 -> V_2 = F_18 ( V_4 ) ;
memcpy ( V_4 -> V_192 , & V_95 -> V_13 . V_14 . V_15 , 4 ) ;
memcpy ( V_4 -> V_193 , & V_95 -> V_13 . V_14 . V_16 , 4 ) ;
F_126 ( V_4 ) ;
V_4 -> V_129 = F_140 ( struct V_128 ) ;
if ( ! V_4 -> V_129 )
return - V_72 ;
V_95 -> V_218 = F_141 ( struct V_232 ) ;
if ( ! V_95 -> V_218 ) {
F_138 ( V_4 -> V_129 ) ;
return - V_72 ;
}
return 0 ;
}
static int T_8 F_142 ( struct V_3 * V_4 )
{
struct V_1 * V_95 = F_14 ( V_4 ) ;
struct V_85 * V_14 = & V_95 -> V_13 . V_14 ;
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
V_95 -> V_4 = V_4 ;
V_95 -> V_2 = F_18 ( V_4 ) ;
strcpy ( V_95 -> V_13 . V_44 , V_4 -> V_44 ) ;
V_14 -> V_207 = 4 ;
V_14 -> V_130 = V_115 ;
V_14 -> V_100 = 5 ;
V_14 -> V_116 = 64 ;
V_4 -> V_129 = F_140 ( struct V_128 ) ;
if ( ! V_4 -> V_129 )
return - V_72 ;
V_95 -> V_218 = F_141 ( struct V_232 ) ;
if ( ! V_95 -> V_218 ) {
F_138 ( V_4 -> V_129 ) ;
return - V_72 ;
}
F_21 ( V_4 ) ;
F_10 ( V_11 -> V_21 [ 0 ] , V_95 ) ;
return 0 ;
}
static int F_143 ( struct V_233 * V_234 [] , struct V_233 * V_96 [] )
{
T_6 V_146 ;
if ( ! V_96 || ! V_96 [ V_235 ] )
return 0 ;
V_146 = F_144 ( V_96 [ V_235 ] ) ;
if ( V_146 != V_115 &&
V_146 != V_142 &&
V_146 != 0 )
return - V_75 ;
return 0 ;
}
static void F_145 ( struct V_233 * V_96 [] ,
struct V_22 * V_13 )
{
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_14 . V_207 = 4 ;
V_13 -> V_14 . V_130 = V_115 ;
V_13 -> V_14 . V_100 = 5 ;
V_13 -> V_14 . V_116 = 64 ;
if ( ! V_96 )
return;
if ( V_96 [ V_236 ] )
V_13 -> V_17 = F_146 ( V_96 [ V_236 ] ) ;
if ( V_96 [ V_237 ] )
V_13 -> V_14 . V_15 = F_147 ( V_96 [ V_237 ] ) ;
if ( V_96 [ V_238 ] )
V_13 -> V_14 . V_16 = F_147 ( V_96 [ V_238 ] ) ;
if ( V_96 [ V_239 ] ) {
V_13 -> V_14 . V_116 = F_144 ( V_96 [ V_239 ] ) ;
if ( V_13 -> V_14 . V_116 )
V_13 -> V_14 . V_156 = F_81 ( V_208 ) ;
}
if ( V_96 [ V_240 ] )
V_13 -> V_14 . V_137 = F_144 ( V_96 [ V_240 ] ) ;
if ( ! V_96 [ V_241 ] || F_144 ( V_96 [ V_241 ] ) )
V_13 -> V_14 . V_156 = F_81 ( V_208 ) ;
if ( V_96 [ V_242 ] )
V_13 -> V_40 = F_148 ( V_96 [ V_242 ] ) ;
if ( V_96 [ V_235 ] )
V_13 -> V_14 . V_130 = F_144 ( V_96 [ V_235 ] ) ;
}
static bool F_149 ( struct V_233 * V_96 [] ,
struct V_194 * V_30 )
{
bool V_64 = false ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
if ( ! V_96 )
return V_64 ;
if ( V_96 [ V_243 ] ) {
V_64 = true ;
F_150 ( & V_30 -> V_31 , V_96 [ V_243 ] ,
sizeof( struct V_91 ) ) ;
}
if ( V_96 [ V_244 ] ) {
V_64 = true ;
V_30 -> V_32 =
F_147 ( V_96 [ V_244 ] ) ;
}
if ( V_96 [ V_245 ] ) {
V_64 = true ;
V_30 -> V_33 = F_151 ( V_96 [ V_245 ] ) ;
}
if ( V_96 [ V_246 ] ) {
V_64 = true ;
V_30 -> V_34 =
F_151 ( V_96 [ V_246 ] ) ;
}
return V_64 ;
}
static int F_152 ( struct V_2 * V_247 , struct V_3 * V_4 ,
struct V_233 * V_234 [] , struct V_233 * V_96 [] )
{
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_1 * V_48 ;
#ifdef F_13
struct V_194 V_30 ;
#endif
int V_36 ;
V_48 = F_14 ( V_4 ) ;
F_145 ( V_96 , & V_48 -> V_13 ) ;
if ( F_22 ( V_2 , & V_48 -> V_13 , 0 ) )
return - V_76 ;
V_36 = F_17 ( V_4 ) ;
if ( V_36 < 0 )
return V_36 ;
#ifdef F_13
if ( F_149 ( V_96 , & V_30 ) )
V_36 = F_131 ( V_48 , & V_30 ) ;
#endif
return V_36 ;
}
static int F_153 ( struct V_3 * V_4 , struct V_233 * V_234 [] ,
struct V_233 * V_96 [] )
{
struct V_1 * V_9 = F_14 ( V_4 ) ;
struct V_22 V_74 ;
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
#ifdef F_13
struct V_194 V_30 ;
#endif
if ( V_4 == V_11 -> V_29 )
return - V_75 ;
F_145 ( V_96 , & V_74 ) ;
if ( ( ( V_4 -> V_19 & V_127 ) && ! V_74 . V_14 . V_16 ) ||
( ! ( V_4 -> V_19 & V_127 ) && V_74 . V_14 . V_16 ) )
return - V_75 ;
V_9 = F_22 ( V_2 , & V_74 , 0 ) ;
if ( V_9 ) {
if ( V_9 -> V_4 != V_4 )
return - V_76 ;
} else
V_9 = F_14 ( V_4 ) ;
F_128 ( V_9 , & V_74 ) ;
#ifdef F_13
if ( F_149 ( V_96 , & V_30 ) )
return F_131 ( V_9 , & V_30 ) ;
#endif
return 0 ;
}
static T_9 F_154 ( const struct V_3 * V_4 )
{
return
F_155 ( 4 ) +
F_155 ( 4 ) +
F_155 ( 4 ) +
F_155 ( 1 ) +
F_155 ( 1 ) +
F_155 ( 1 ) +
F_155 ( 2 ) +
F_155 ( 1 ) +
#ifdef F_13
F_155 ( sizeof( struct V_91 ) ) +
F_155 ( 4 ) +
F_155 ( 2 ) +
F_155 ( 2 ) +
#endif
0 ;
}
static int F_156 ( struct V_83 * V_84 , const struct V_3 * V_4 )
{
struct V_1 * V_95 = F_14 ( V_4 ) ;
struct V_22 * V_248 = & V_95 -> V_13 ;
if ( F_157 ( V_84 , V_236 , V_248 -> V_17 ) ||
F_158 ( V_84 , V_237 , V_248 -> V_14 . V_15 ) ||
F_158 ( V_84 , V_238 , V_248 -> V_14 . V_16 ) ||
F_159 ( V_84 , V_239 , V_248 -> V_14 . V_116 ) ||
F_159 ( V_84 , V_240 , V_248 -> V_14 . V_137 ) ||
F_159 ( V_84 , V_241 ,
! ! ( V_248 -> V_14 . V_156 & F_81 ( V_208 ) ) ) ||
F_159 ( V_84 , V_235 , V_248 -> V_14 . V_130 ) ||
F_160 ( V_84 , V_242 , V_248 -> V_40 ) )
goto V_249;
#ifdef F_13
if ( F_161 ( V_84 , V_243 , sizeof( struct V_91 ) ,
& V_95 -> V_30 . V_31 ) ||
F_158 ( V_84 , V_244 ,
V_95 -> V_30 . V_32 ) ||
F_162 ( V_84 , V_245 ,
V_95 -> V_30 . V_33 ) ||
F_162 ( V_84 , V_246 ,
V_95 -> V_30 . V_34 ) )
goto V_249;
#endif
return 0 ;
V_249:
return - V_250 ;
}
static void F_163 ( struct V_3 * V_4 , struct V_251 * V_80 )
{
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
if ( V_4 != V_11 -> V_29 )
F_164 ( V_4 , V_80 ) ;
}
static void T_10 F_165 ( struct V_2 * V_2 ,
struct V_251 * V_80 )
{
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
struct V_3 * V_4 , * V_252 ;
int V_24 ;
F_166 (net, dev, aux)
if ( V_4 -> V_45 == & V_46 )
F_164 ( V_4 , V_80 ) ;
for ( V_24 = 1 ; V_24 < 4 ; V_24 ++ ) {
int V_23 ;
for ( V_23 = 0 ; V_23 < V_253 ; V_23 ++ ) {
struct V_1 * V_9 ;
V_9 = F_9 ( V_11 -> V_25 [ V_24 ] [ V_23 ] ) ;
while ( V_9 != NULL ) {
if ( ! F_121 ( F_18 ( V_9 -> V_4 ) , V_2 ) )
F_164 ( V_9 -> V_4 ,
V_80 ) ;
V_9 = F_9 ( V_9 -> V_28 ) ;
}
}
}
}
static int T_8 F_167 ( struct V_2 * V_2 )
{
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
struct V_1 * V_9 ;
int V_36 ;
V_11 -> V_25 [ 0 ] = V_11 -> V_21 ;
V_11 -> V_25 [ 1 ] = V_11 -> V_254 ;
V_11 -> V_25 [ 2 ] = V_11 -> V_255 ;
V_11 -> V_25 [ 3 ] = V_11 -> V_256 ;
V_11 -> V_29 = F_24 ( sizeof( struct V_1 ) , L_6 ,
V_51 ) ;
if ( ! V_11 -> V_29 ) {
V_36 = - V_72 ;
goto V_257;
}
F_25 ( V_11 -> V_29 , V_2 ) ;
V_11 -> V_29 -> V_45 = & V_46 ;
V_11 -> V_29 -> V_228 |= V_258 ;
V_36 = F_142 ( V_11 -> V_29 ) ;
if ( V_36 )
goto V_259;
F_12 ( V_11 -> V_29 , V_11 ) ;
if ( ( V_36 = F_168 ( V_11 -> V_29 ) ) )
goto V_260;
V_9 = F_14 ( V_11 -> V_29 ) ;
strcpy ( V_9 -> V_13 . V_44 , V_11 -> V_29 -> V_44 ) ;
return 0 ;
V_260:
F_54 ( V_11 -> V_29 ) ;
V_259:
F_26 ( V_11 -> V_29 ) ;
V_257:
return V_36 ;
}
static void T_10 F_169 ( struct V_2 * V_2 )
{
F_170 ( V_261 ) ;
F_171 () ;
F_165 ( V_2 , & V_261 ) ;
F_172 ( & V_261 ) ;
F_173 () ;
}
static void T_11 F_174 ( void )
{
F_175 ( & V_46 ) ;
F_176 ( & V_262 , V_263 ) ;
F_176 ( & V_264 , V_265 ) ;
F_177 ( & V_266 ) ;
F_178 () ;
}
static int T_12 F_179 ( void )
{
int V_36 ;
F_180 ( L_7 ) ;
V_36 = F_181 ( & V_266 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_182 ( & V_262 , V_263 ) ;
if ( V_36 < 0 ) {
F_180 ( L_8 , V_267 ) ;
goto V_268;
}
V_36 = F_182 ( & V_264 , V_265 ) ;
if ( V_36 < 0 ) {
F_180 ( L_9 , V_267 ) ;
goto V_269;
}
V_36 = F_183 ( & V_46 ) ;
if ( V_36 < 0 )
goto V_270;
V_37:
return V_36 ;
V_270:
F_176 ( & V_264 , V_265 ) ;
V_269:
F_176 ( & V_262 , V_263 ) ;
V_268:
F_177 ( & V_266 ) ;
goto V_37;
}
