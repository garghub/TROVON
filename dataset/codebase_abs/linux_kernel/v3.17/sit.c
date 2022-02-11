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
V_4 = F_24 ( sizeof( * V_9 ) , V_44 , V_51 ,
V_52 ) ;
if ( V_4 == NULL )
return NULL ;
F_25 ( V_4 , V_2 ) ;
V_48 = F_14 ( V_4 ) ;
V_48 -> V_13 = * V_13 ;
if ( F_17 ( V_4 ) < 0 )
goto V_53;
return V_48 ;
V_53:
F_26 ( V_4 ) ;
V_50:
return NULL ;
}
static struct V_54 *
F_27 ( struct V_1 * V_9 , T_1 V_55 )
{
struct V_54 * V_56 ;
F_28 (t->prl)
if ( V_56 -> V_55 == V_55 )
break;
return V_56 ;
}
static int F_29 ( struct V_1 * V_9 ,
struct V_57 T_3 * V_58 )
{
struct V_57 V_59 , * V_60 ;
struct V_54 * V_56 ;
unsigned int V_61 , V_62 = 0 , V_63 , V_64 ;
int V_65 = 0 ;
if ( F_30 ( & V_59 , V_58 , sizeof( V_59 ) ) )
return - V_66 ;
V_61 = V_59 . V_67 / sizeof( V_59 ) ;
if ( V_61 > 1 && V_59 . V_55 != F_16 ( V_68 ) )
V_61 = 1 ;
V_60 = ( V_61 <= 1 || F_31 ( V_69 ) ) ?
F_32 ( V_61 , sizeof( * V_60 ) , V_70 ) :
NULL ;
F_33 () ;
V_63 = V_9 -> V_71 < V_61 ? V_9 -> V_71 : V_61 ;
if ( ! V_60 ) {
V_60 = F_32 ( V_63 , sizeof( * V_60 ) , V_72 ) ;
if ( ! V_60 ) {
V_65 = - V_73 ;
goto V_37;
}
}
V_62 = 0 ;
F_28 (t->prl) {
if ( V_62 >= V_61 )
break;
if ( V_59 . V_55 != F_16 ( V_68 ) && V_56 -> V_55 != V_59 . V_55 )
continue;
V_60 [ V_62 ] . V_55 = V_56 -> V_55 ;
V_60 [ V_62 ] . V_19 = V_56 -> V_19 ;
V_62 ++ ;
if ( V_59 . V_55 != F_16 ( V_68 ) )
break;
}
V_37:
F_34 () ;
V_64 = sizeof( * V_60 ) * V_62 ;
V_65 = 0 ;
if ( ( V_64 && F_35 ( V_58 + 1 , V_60 , V_64 ) ) || F_36 ( V_64 , & V_58 -> V_67 ) )
V_65 = - V_66 ;
F_37 ( V_60 ) ;
return V_65 ;
}
static int
F_38 ( struct V_1 * V_9 , struct V_57 * V_58 , int V_74 )
{
struct V_54 * V_75 ;
int V_36 = 0 ;
if ( V_58 -> V_55 == F_16 ( V_68 ) )
return - V_76 ;
F_39 () ;
for ( V_75 = F_9 ( V_9 -> V_56 ) ; V_75 ; V_75 = F_9 ( V_75 -> V_28 ) ) {
if ( V_75 -> V_55 == V_58 -> V_55 ) {
if ( V_74 ) {
V_75 -> V_19 = V_58 -> V_19 ;
goto V_37;
}
V_36 = - V_77 ;
goto V_37;
}
}
if ( V_74 ) {
V_36 = - V_78 ;
goto V_37;
}
V_75 = F_40 ( sizeof( struct V_54 ) , V_70 ) ;
if ( ! V_75 ) {
V_36 = - V_79 ;
goto V_37;
}
V_75 -> V_28 = V_9 -> V_56 ;
V_75 -> V_55 = V_58 -> V_55 ;
V_75 -> V_19 = V_58 -> V_19 ;
V_9 -> V_71 ++ ;
F_10 ( V_9 -> V_56 , V_75 ) ;
V_37:
return V_36 ;
}
static void F_41 ( struct V_80 * V_81 )
{
struct V_54 * V_75 , * V_82 ;
V_75 = F_42 ( V_81 , struct V_54 , V_80 ) ;
do {
V_82 = F_43 ( V_75 -> V_28 , 1 ) ;
F_37 ( V_75 ) ;
V_75 = V_82 ;
} while ( V_75 );
}
static int
F_44 ( struct V_1 * V_9 , struct V_57 * V_58 )
{
struct V_54 * V_83 ;
struct V_54 T_2 * * V_75 ;
int V_36 = 0 ;
F_39 () ;
if ( V_58 && V_58 -> V_55 != F_16 ( V_68 ) ) {
for ( V_75 = & V_9 -> V_56 ;
( V_83 = F_9 ( * V_75 ) ) != NULL ;
V_75 = & V_83 -> V_28 ) {
if ( V_83 -> V_55 == V_58 -> V_55 ) {
* V_75 = V_83 -> V_28 ;
F_45 ( V_83 , V_80 ) ;
V_9 -> V_71 -- ;
goto V_37;
}
}
V_36 = - V_78 ;
} else {
V_83 = F_9 ( V_9 -> V_56 ) ;
if ( V_83 ) {
V_9 -> V_71 = 0 ;
F_46 ( & V_83 -> V_80 , F_41 ) ;
V_9 -> V_56 = NULL ;
}
}
V_37:
return V_36 ;
}
static int
F_47 ( struct V_84 * V_85 , const struct V_86 * V_14 , struct V_1 * V_9 )
{
struct V_54 * V_75 ;
int V_87 = 1 ;
F_33 () ;
V_75 = F_27 ( V_9 , V_14 -> V_15 ) ;
if ( V_75 ) {
if ( V_75 -> V_19 & V_88 )
V_85 -> V_89 = V_90 ;
else
V_85 -> V_89 = V_91 ;
} else {
const struct V_92 * V_93 = & F_48 ( V_85 ) -> V_15 ;
if ( F_49 ( V_93 ) &&
( V_93 -> V_94 [ 3 ] == V_14 -> V_15 ) &&
F_50 ( V_93 , V_9 -> V_4 ) )
V_85 -> V_89 = V_95 ;
else
V_87 = 0 ;
}
F_34 () ;
return V_87 ;
}
static void F_51 ( struct V_3 * V_4 )
{
struct V_1 * V_96 = F_14 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_96 -> V_2 , V_12 ) ;
if ( V_4 == V_11 -> V_29 ) {
F_52 ( V_11 -> V_21 [ 0 ] , NULL ) ;
} else {
F_8 ( V_11 , V_96 ) ;
F_44 ( V_96 , NULL ) ;
}
F_53 ( V_96 ) ;
F_54 ( V_4 ) ;
}
static int F_55 ( struct V_84 * V_85 )
{
const struct V_86 * V_14 = ( const struct V_86 * ) V_85 -> V_97 ;
struct V_98 * V_99 ;
struct V_84 * V_100 ;
if ( ! F_56 ( V_85 , V_14 -> V_101 * 4 + sizeof( struct V_102 ) + 8 ) )
return 1 ;
V_100 = F_57 ( V_85 , V_72 ) ;
if ( ! V_100 )
return 1 ;
F_58 ( V_100 ) ;
F_59 ( V_100 , V_14 -> V_101 * 4 ) ;
F_60 ( V_100 ) ;
V_99 = F_61 ( F_18 ( V_85 -> V_4 ) , & F_48 ( V_100 ) -> V_15 , NULL , 0 , 0 ) ;
if ( V_99 && V_99 -> V_103 . V_4 )
V_100 -> V_4 = V_99 -> V_103 . V_4 ;
F_62 ( V_100 , V_104 , V_105 , 0 ) ;
if ( V_99 )
F_63 ( V_99 ) ;
F_64 ( V_100 ) ;
return 0 ;
}
static int F_65 ( struct V_84 * V_85 , T_4 V_106 )
{
const struct V_86 * V_14 = ( const struct V_86 * ) V_85 -> V_97 ;
const int type = F_66 ( V_85 ) -> type ;
const int V_107 = F_66 ( V_85 ) -> V_107 ;
struct V_1 * V_9 ;
int V_36 ;
switch ( type ) {
default:
case V_108 :
return 0 ;
case V_109 :
switch ( V_107 ) {
case V_110 :
return 0 ;
default:
break;
}
break;
case V_111 :
if ( V_107 != V_112 )
return 0 ;
break;
case V_113 :
break;
}
V_36 = - V_114 ;
V_9 = F_1 ( F_18 ( V_85 -> V_4 ) ,
V_85 -> V_4 ,
V_14 -> V_16 ,
V_14 -> V_15 ) ;
if ( V_9 == NULL )
goto V_37;
if ( type == V_109 && V_107 == V_115 ) {
F_67 ( V_85 , F_18 ( V_85 -> V_4 ) , V_106 ,
V_9 -> V_13 . V_17 , 0 , V_116 , 0 ) ;
V_36 = 0 ;
goto V_37;
}
if ( type == V_113 ) {
F_68 ( V_85 , F_18 ( V_85 -> V_4 ) , V_9 -> V_13 . V_17 , 0 ,
V_116 , 0 ) ;
V_36 = 0 ;
goto V_37;
}
if ( V_9 -> V_13 . V_14 . V_16 == 0 )
goto V_37;
V_36 = 0 ;
if ( ! F_55 ( V_85 ) )
goto V_37;
if ( V_9 -> V_13 . V_14 . V_117 == 0 && type == V_111 )
goto V_37;
if ( F_69 ( V_118 , V_9 -> V_119 + V_120 ) )
V_9 -> V_121 ++ ;
else
V_9 -> V_121 = 1 ;
V_9 -> V_119 = V_118 ;
V_37:
return V_36 ;
}
static inline bool F_70 ( struct V_1 * V_96 , const T_1 V_122 ,
const struct V_92 * V_123 )
{
T_1 V_124 = 0 ;
if ( F_71 ( V_96 , V_123 , & V_124 ) && V_122 != V_124 )
return true ;
return false ;
}
static bool F_72 ( const struct V_1 * V_96 ,
const struct V_92 * V_125 )
{
int V_126 ;
#ifdef F_13
V_126 = V_96 -> V_30 . V_33 + 32
- V_96 -> V_30 . V_34 ;
#else
V_126 = 48 ;
#endif
return F_73 ( V_125 , V_126 , V_96 -> V_4 ) ;
}
static bool F_74 ( struct V_84 * V_85 ,
const struct V_86 * V_14 ,
struct V_1 * V_96 )
{
const struct V_102 * V_127 ;
if ( V_96 -> V_4 -> V_42 & V_43 ) {
if ( ! F_47 ( V_85 , V_14 , V_96 ) )
return true ;
return false ;
}
if ( V_96 -> V_4 -> V_19 & V_128 )
return false ;
V_127 = F_48 ( V_85 ) ;
if ( F_75 ( F_70 ( V_96 , V_14 -> V_15 , & V_127 -> V_15 ) ) ) {
F_76 ( L_2 ,
& V_14 -> V_15 , & V_127 -> V_15 ,
& V_14 -> V_16 , & V_127 -> V_16 ) ;
return true ;
}
if ( F_77 ( ! F_70 ( V_96 , V_14 -> V_16 , & V_127 -> V_16 ) ) )
return false ;
if ( F_72 ( V_96 , & V_127 -> V_16 ) )
return false ;
F_76 ( L_3 ,
& V_14 -> V_15 , & V_127 -> V_15 ,
& V_14 -> V_16 , & V_127 -> V_16 ) ;
return true ;
}
static int F_78 ( struct V_84 * V_85 )
{
const struct V_86 * V_14 = F_79 ( V_85 ) ;
struct V_1 * V_96 ;
int V_36 ;
V_96 = F_1 ( F_18 ( V_85 -> V_4 ) , V_85 -> V_4 ,
V_14 -> V_15 , V_14 -> V_16 ) ;
if ( V_96 != NULL ) {
struct V_129 * V_130 ;
if ( V_96 -> V_13 . V_14 . V_131 != V_116 &&
V_96 -> V_13 . V_14 . V_131 != 0 )
goto V_37;
V_85 -> V_132 = V_85 -> V_133 ;
F_60 ( V_85 ) ;
F_80 ( V_85 ) -> V_19 = 0 ;
V_85 -> V_131 = F_81 ( V_134 ) ;
if ( F_74 ( V_85 , V_14 , V_96 ) ) {
V_96 -> V_4 -> V_135 . V_136 ++ ;
goto V_37;
}
F_82 ( V_85 , V_96 -> V_4 , V_96 -> V_2 ) ;
V_36 = F_83 ( V_14 , V_85 ) ;
if ( F_75 ( V_36 ) ) {
if ( V_137 )
F_84 ( L_4 ,
& V_14 -> V_15 , V_14 -> V_138 ) ;
if ( V_36 > 1 ) {
++ V_96 -> V_4 -> V_135 . V_139 ;
++ V_96 -> V_4 -> V_135 . V_136 ;
goto V_37;
}
}
V_130 = F_85 ( V_96 -> V_4 -> V_130 ) ;
F_86 ( & V_130 -> V_140 ) ;
V_130 -> V_141 ++ ;
V_130 -> V_142 += V_85 -> V_64 ;
F_87 ( & V_130 -> V_140 ) ;
F_88 ( V_85 ) ;
return 0 ;
}
return 1 ;
V_37:
F_64 ( V_85 ) ;
return 0 ;
}
static int F_89 ( struct V_84 * V_85 )
{
const struct V_86 * V_14 ;
struct V_1 * V_96 ;
V_14 = F_79 ( V_85 ) ;
V_96 = F_1 ( F_18 ( V_85 -> V_4 ) , V_85 -> V_4 ,
V_14 -> V_15 , V_14 -> V_16 ) ;
if ( V_96 != NULL ) {
if ( V_96 -> V_13 . V_14 . V_131 != V_143 &&
V_96 -> V_13 . V_14 . V_131 != 0 )
goto V_144;
if ( ! F_90 ( NULL , V_145 , V_85 ) )
goto V_144;
if ( F_91 ( V_85 , 0 , V_146 . V_147 ) )
goto V_144;
return F_92 ( V_96 , V_85 , & V_146 , V_137 ) ;
}
return 1 ;
V_144:
F_64 ( V_85 ) ;
return 0 ;
}
static bool F_71 ( struct V_1 * V_96 , const struct V_92 * V_125 ,
T_1 * V_148 )
{
#ifdef F_13
if ( F_93 ( V_125 , & V_96 -> V_30 . V_31 ,
V_96 -> V_30 . V_33 ) ) {
unsigned int V_149 , V_150 ;
int V_151 ;
T_4 V_152 ;
V_149 = V_96 -> V_30 . V_33 >> 5 ;
V_150 = V_96 -> V_30 . V_33 & 0x1f ;
V_152 = ( F_94 ( V_125 -> V_94 [ V_149 ] ) << V_150 ) >>
V_96 -> V_30 . V_34 ;
V_151 = V_150 - V_96 -> V_30 . V_34 ;
if ( V_151 > 0 )
V_152 |= F_94 ( V_125 -> V_94 [ V_149 + 1 ] ) >>
( 32 - V_151 ) ;
* V_148 = V_96 -> V_30 . V_32 | F_16 ( V_152 ) ;
return true ;
}
#else
if ( V_125 -> V_153 [ 0 ] == F_81 ( 0x2002 ) ) {
memcpy ( V_148 , & V_125 -> V_153 [ 1 ] , 4 ) ;
return true ;
}
#endif
return false ;
}
static inline T_1 F_95 ( struct V_1 * V_96 ,
const struct V_92 * V_125 )
{
T_1 V_103 = 0 ;
F_71 ( V_96 , V_125 , & V_103 ) ;
return V_103 ;
}
static T_5 F_96 ( struct V_84 * V_85 ,
struct V_3 * V_4 )
{
struct V_1 * V_96 = F_14 ( V_4 ) ;
const struct V_86 * V_154 = & V_96 -> V_13 . V_14 ;
const struct V_102 * V_155 = F_48 ( V_85 ) ;
T_6 V_138 = V_96 -> V_13 . V_14 . V_138 ;
T_7 V_156 = V_154 -> V_157 ;
struct V_158 * V_99 ;
struct V_3 * V_159 ;
unsigned int V_160 ;
T_1 V_103 = V_154 -> V_16 ;
struct V_161 V_162 ;
int V_163 ;
const struct V_92 * V_93 ;
int V_164 ;
T_6 V_117 ;
int V_36 ;
if ( V_85 -> V_131 != F_81 ( V_134 ) )
goto V_165;
if ( V_138 == 1 )
V_138 = F_97 ( V_155 ) ;
if ( V_4 -> V_42 & V_43 ) {
struct V_166 * V_167 = NULL ;
bool V_168 = false ;
if ( F_98 ( V_85 ) )
V_167 = F_99 ( F_98 ( V_85 ) , & V_155 -> V_16 ) ;
if ( V_167 == NULL ) {
F_100 ( L_5 ) ;
goto V_165;
}
V_93 = ( const struct V_92 * ) & V_167 -> V_169 ;
V_164 = F_101 ( V_93 ) ;
if ( ( V_164 & V_170 ) &&
F_49 ( V_93 ) )
V_103 = V_93 -> V_94 [ 3 ] ;
else
V_168 = true ;
F_102 ( V_167 ) ;
if ( V_168 )
goto V_165;
}
if ( ! V_103 )
V_103 = F_95 ( V_96 , & V_155 -> V_16 ) ;
if ( ! V_103 ) {
struct V_166 * V_167 = NULL ;
bool V_168 = false ;
if ( F_98 ( V_85 ) )
V_167 = F_99 ( F_98 ( V_85 ) , & V_155 -> V_16 ) ;
if ( V_167 == NULL ) {
F_100 ( L_5 ) ;
goto V_165;
}
V_93 = ( const struct V_92 * ) & V_167 -> V_169 ;
V_164 = F_101 ( V_93 ) ;
if ( V_164 == V_171 ) {
V_93 = & F_48 ( V_85 ) -> V_16 ;
V_164 = F_101 ( V_93 ) ;
}
if ( ( V_164 & V_172 ) != 0 )
V_103 = V_93 -> V_94 [ 3 ] ;
else
V_168 = true ;
F_102 ( V_167 ) ;
if ( V_168 )
goto V_165;
}
V_99 = F_103 ( V_96 -> V_2 , & V_162 , NULL ,
V_103 , V_154 -> V_15 ,
0 , 0 ,
V_116 , F_104 ( V_138 ) ,
V_96 -> V_13 . V_17 ) ;
if ( F_105 ( V_99 ) ) {
V_4 -> V_135 . V_173 ++ ;
goto V_174;
}
if ( V_99 -> V_175 != V_176 ) {
F_106 ( V_99 ) ;
V_4 -> V_135 . V_173 ++ ;
goto V_174;
}
V_159 = V_99 -> V_103 . V_4 ;
if ( V_159 == V_4 ) {
F_106 ( V_99 ) ;
V_4 -> V_135 . V_177 ++ ;
goto V_165;
}
if ( V_156 ) {
V_163 = F_107 ( & V_99 -> V_103 ) - sizeof( struct V_86 ) ;
if ( V_163 < 68 ) {
V_4 -> V_135 . V_177 ++ ;
F_106 ( V_99 ) ;
goto V_165;
}
if ( V_163 < V_178 ) {
V_163 = V_178 ;
V_156 = 0 ;
}
if ( V_96 -> V_13 . V_14 . V_16 && F_98 ( V_85 ) )
F_98 ( V_85 ) -> V_179 -> V_180 ( F_98 ( V_85 ) , NULL , V_85 , V_163 ) ;
if ( V_85 -> V_64 > V_163 && ! F_108 ( V_85 ) ) {
F_62 ( V_85 , V_181 , 0 , V_163 ) ;
F_106 ( V_99 ) ;
goto V_165;
}
}
if ( V_96 -> V_121 > 0 ) {
if ( F_69 ( V_118 ,
V_96 -> V_119 + V_120 ) ) {
V_96 -> V_121 -- ;
F_109 ( V_85 ) ;
} else
V_96 -> V_121 = 0 ;
}
V_160 = F_110 ( V_159 ) + sizeof( struct V_86 ) ;
if ( F_111 ( V_85 ) < V_160 || F_112 ( V_85 ) ||
( F_113 ( V_85 ) && ! F_114 ( V_85 , 0 ) ) ) {
struct V_84 * V_182 = F_115 ( V_85 , V_160 ) ;
if ( ! V_182 ) {
F_106 ( V_99 ) ;
V_4 -> V_135 . V_183 ++ ;
F_64 ( V_85 ) ;
return V_184 ;
}
if ( V_85 -> V_185 )
F_116 ( V_182 , V_85 -> V_185 ) ;
F_117 ( V_85 ) ;
V_85 = V_182 ;
V_155 = F_48 ( V_85 ) ;
}
V_117 = V_154 -> V_117 ;
if ( V_117 == 0 )
V_117 = V_155 -> V_186 ;
V_138 = F_118 ( V_138 , F_97 ( V_155 ) ) ;
V_85 = F_119 ( V_85 , false , V_187 ) ;
if ( F_105 ( V_85 ) ) {
F_106 ( V_99 ) ;
goto V_37;
}
V_36 = F_120 ( V_85 -> V_185 , V_99 , V_85 , V_162 . V_15 , V_162 . V_16 ,
V_116 , V_138 , V_117 , V_156 ,
! F_121 ( V_96 -> V_2 , F_18 ( V_4 ) ) ) ;
F_122 ( V_36 , & V_4 -> V_135 , V_4 -> V_130 ) ;
return V_184 ;
V_174:
F_109 ( V_85 ) ;
V_165:
F_64 ( V_85 ) ;
V_37:
V_4 -> V_135 . V_188 ++ ;
return V_184 ;
}
static T_5 F_123 ( struct V_84 * V_85 , struct V_3 * V_4 )
{
struct V_1 * V_96 = F_14 ( V_4 ) ;
const struct V_86 * V_154 = & V_96 -> V_13 . V_14 ;
V_85 = F_119 ( V_85 , false , V_189 ) ;
if ( F_105 ( V_85 ) )
goto V_37;
F_124 ( V_85 , V_4 , V_154 , V_143 ) ;
return V_184 ;
V_37:
V_4 -> V_135 . V_188 ++ ;
return V_184 ;
}
static T_5 F_125 ( struct V_84 * V_85 ,
struct V_3 * V_4 )
{
switch ( V_85 -> V_131 ) {
case F_81 ( V_190 ) :
F_123 ( V_85 , V_4 ) ;
break;
case F_81 ( V_134 ) :
F_96 ( V_85 , V_4 ) ;
break;
default:
goto V_191;
}
return V_184 ;
V_191:
V_4 -> V_135 . V_188 ++ ;
F_64 ( V_85 ) ;
return V_184 ;
}
static void F_126 ( struct V_3 * V_4 )
{
struct V_3 * V_159 = NULL ;
struct V_1 * V_96 ;
const struct V_86 * V_14 ;
struct V_161 V_162 ;
V_96 = F_14 ( V_4 ) ;
V_14 = & V_96 -> V_13 . V_14 ;
if ( V_14 -> V_16 ) {
struct V_158 * V_99 = F_103 ( V_96 -> V_2 , & V_162 ,
NULL ,
V_14 -> V_16 , V_14 -> V_15 ,
0 , 0 ,
V_116 ,
F_104 ( V_14 -> V_138 ) ,
V_96 -> V_13 . V_17 ) ;
if ( ! F_105 ( V_99 ) ) {
V_159 = V_99 -> V_103 . V_4 ;
F_106 ( V_99 ) ;
}
V_4 -> V_19 |= V_128 ;
}
if ( ! V_159 && V_96 -> V_13 . V_17 )
V_159 = F_127 ( V_96 -> V_2 , V_96 -> V_13 . V_17 ) ;
if ( V_159 ) {
V_4 -> V_192 = V_159 -> V_192 + sizeof( struct V_86 ) ;
V_4 -> V_163 = V_159 -> V_163 - sizeof( struct V_86 ) ;
if ( V_4 -> V_163 < V_178 )
V_4 -> V_163 = V_178 ;
}
V_4 -> V_193 = V_96 -> V_13 . V_17 ;
}
static void F_128 ( struct V_1 * V_9 , struct V_22 * V_75 )
{
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
F_8 ( V_11 , V_9 ) ;
F_129 () ;
V_9 -> V_13 . V_14 . V_15 = V_75 -> V_14 . V_15 ;
V_9 -> V_13 . V_14 . V_16 = V_75 -> V_14 . V_16 ;
memcpy ( V_9 -> V_4 -> V_194 , & V_75 -> V_14 . V_15 , 4 ) ;
memcpy ( V_9 -> V_4 -> V_195 , & V_75 -> V_14 . V_16 , 4 ) ;
F_11 ( V_11 , V_9 ) ;
V_9 -> V_13 . V_14 . V_117 = V_75 -> V_14 . V_117 ;
V_9 -> V_13 . V_14 . V_138 = V_75 -> V_14 . V_138 ;
if ( V_9 -> V_13 . V_17 != V_75 -> V_17 ) {
V_9 -> V_13 . V_17 = V_75 -> V_17 ;
F_126 ( V_9 -> V_4 ) ;
}
F_53 ( V_9 ) ;
F_130 ( V_9 -> V_4 ) ;
}
static int F_131 ( struct V_1 * V_9 ,
struct V_196 * V_30 )
{
struct V_92 V_31 ;
T_1 V_32 ;
if ( V_30 -> V_34 > 32 ||
V_30 -> V_33 + ( 32 - V_30 -> V_34 ) > 64 )
return - V_76 ;
F_132 ( & V_31 , & V_30 -> V_31 , V_30 -> V_33 ) ;
if ( ! F_133 ( & V_31 , & V_30 -> V_31 ) )
return - V_76 ;
if ( V_30 -> V_34 )
V_32 = V_30 -> V_32 &
F_16 ( 0xffffffffUL <<
( 32 - V_30 -> V_34 ) ) ;
else
V_32 = 0 ;
if ( V_32 != V_30 -> V_32 )
return - V_76 ;
V_9 -> V_30 . V_31 = V_31 ;
V_9 -> V_30 . V_32 = V_32 ;
V_9 -> V_30 . V_33 = V_30 -> V_33 ;
V_9 -> V_30 . V_34 = V_30 -> V_34 ;
F_53 ( V_9 ) ;
F_130 ( V_9 -> V_4 ) ;
return 0 ;
}
static int
F_134 ( struct V_3 * V_4 , struct V_197 * V_198 , int V_199 )
{
int V_36 = 0 ;
struct V_22 V_75 ;
struct V_57 V_56 ;
struct V_1 * V_9 = F_14 ( V_4 ) ;
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
#ifdef F_13
struct V_196 V_30 ;
#endif
switch ( V_199 ) {
case V_200 :
#ifdef F_13
case V_201 :
#endif
if ( V_4 == V_11 -> V_29 ) {
if ( F_30 ( & V_75 , V_198 -> V_202 . V_203 , sizeof( V_75 ) ) ) {
V_36 = - V_66 ;
break;
}
V_9 = F_22 ( V_2 , & V_75 , 0 ) ;
if ( V_9 == NULL )
V_9 = F_14 ( V_4 ) ;
}
V_36 = - V_66 ;
if ( V_199 == V_200 ) {
memcpy ( & V_75 , & V_9 -> V_13 , sizeof( V_75 ) ) ;
if ( F_35 ( V_198 -> V_202 . V_203 , & V_75 ,
sizeof( V_75 ) ) )
goto V_204;
#ifdef F_13
} else {
V_30 . V_31 = V_9 -> V_30 . V_31 ;
V_30 . V_32 = V_9 -> V_30 . V_32 ;
V_30 . V_33 = V_9 -> V_30 . V_33 ;
V_30 . V_34 = V_9 -> V_30 . V_34 ;
if ( F_35 ( V_198 -> V_202 . V_203 , & V_30 ,
sizeof( V_30 ) ) )
goto V_204;
#endif
}
V_36 = 0 ;
break;
case V_205 :
case V_206 :
V_36 = - V_207 ;
if ( ! F_135 ( V_2 -> V_208 , V_69 ) )
goto V_204;
V_36 = - V_66 ;
if ( F_30 ( & V_75 , V_198 -> V_202 . V_203 , sizeof( V_75 ) ) )
goto V_204;
V_36 = - V_76 ;
if ( V_75 . V_14 . V_131 != V_116 &&
V_75 . V_14 . V_131 != V_143 &&
V_75 . V_14 . V_131 != 0 )
goto V_204;
if ( V_75 . V_14 . V_209 != 4 ||
V_75 . V_14 . V_101 != 5 || ( V_75 . V_14 . V_157 & F_81 ( ~ V_210 ) ) )
goto V_204;
if ( V_75 . V_14 . V_117 )
V_75 . V_14 . V_157 |= F_81 ( V_210 ) ;
V_9 = F_22 ( V_2 , & V_75 , V_199 == V_205 ) ;
if ( V_4 != V_11 -> V_29 && V_199 == V_206 ) {
if ( V_9 != NULL ) {
if ( V_9 -> V_4 != V_4 ) {
V_36 = - V_77 ;
break;
}
} else {
if ( ( ( V_4 -> V_19 & V_128 ) && ! V_75 . V_14 . V_16 ) ||
( ! ( V_4 -> V_19 & V_128 ) && V_75 . V_14 . V_16 ) ) {
V_36 = - V_76 ;
break;
}
V_9 = F_14 ( V_4 ) ;
}
F_128 ( V_9 , & V_75 ) ;
}
if ( V_9 ) {
V_36 = 0 ;
if ( F_35 ( V_198 -> V_202 . V_203 , & V_9 -> V_13 , sizeof( V_75 ) ) )
V_36 = - V_66 ;
} else
V_36 = ( V_199 == V_205 ? - V_79 : - V_114 ) ;
break;
case V_211 :
V_36 = - V_207 ;
if ( ! F_135 ( V_2 -> V_208 , V_69 ) )
goto V_204;
if ( V_4 == V_11 -> V_29 ) {
V_36 = - V_66 ;
if ( F_30 ( & V_75 , V_198 -> V_202 . V_203 , sizeof( V_75 ) ) )
goto V_204;
V_36 = - V_114 ;
if ( ( V_9 = F_22 ( V_2 , & V_75 , 0 ) ) == NULL )
goto V_204;
V_36 = - V_207 ;
if ( V_9 == F_14 ( V_11 -> V_29 ) )
goto V_204;
V_4 = V_9 -> V_4 ;
}
F_136 ( V_4 ) ;
V_36 = 0 ;
break;
case V_212 :
V_36 = - V_76 ;
if ( V_4 == V_11 -> V_29 )
goto V_204;
V_36 = F_29 ( V_9 , V_198 -> V_202 . V_203 ) ;
break;
case V_213 :
case V_214 :
case V_215 :
V_36 = - V_207 ;
if ( ! F_135 ( V_2 -> V_208 , V_69 ) )
goto V_204;
V_36 = - V_76 ;
if ( V_4 == V_11 -> V_29 )
goto V_204;
V_36 = - V_66 ;
if ( F_30 ( & V_56 , V_198 -> V_202 . V_203 , sizeof( V_56 ) ) )
goto V_204;
switch ( V_199 ) {
case V_214 :
V_36 = F_44 ( V_9 , & V_56 ) ;
break;
case V_213 :
case V_215 :
V_36 = F_38 ( V_9 , & V_56 , V_199 == V_215 ) ;
break;
}
F_53 ( V_9 ) ;
F_130 ( V_4 ) ;
break;
#ifdef F_13
case V_216 :
case V_217 :
case V_218 :
V_36 = - V_207 ;
if ( ! F_135 ( V_2 -> V_208 , V_69 ) )
goto V_204;
V_36 = - V_66 ;
if ( F_30 ( & V_30 , V_198 -> V_202 . V_203 ,
sizeof( V_30 ) ) )
goto V_204;
if ( V_199 != V_218 ) {
V_36 = F_131 ( V_9 , & V_30 ) ;
if ( V_36 < 0 )
goto V_204;
} else
F_12 ( V_4 , V_11 ) ;
V_36 = 0 ;
break;
#endif
default:
V_36 = - V_76 ;
}
V_204:
return V_36 ;
}
static int F_137 ( struct V_3 * V_4 , int V_219 )
{
if ( V_219 < V_178 || V_219 > 0xFFF8 - sizeof( struct V_86 ) )
return - V_76 ;
V_4 -> V_163 = V_219 ;
return 0 ;
}
static void F_26 ( struct V_3 * V_4 )
{
struct V_1 * V_96 = F_14 ( V_4 ) ;
F_138 ( V_96 -> V_220 ) ;
F_138 ( V_4 -> V_130 ) ;
F_139 ( V_4 ) ;
}
static void V_52 ( struct V_3 * V_4 )
{
V_4 -> V_221 = & V_222 ;
V_4 -> V_223 = F_26 ;
V_4 -> type = V_224 ;
V_4 -> V_192 = V_225 + sizeof( struct V_86 ) ;
V_4 -> V_163 = V_226 - sizeof( struct V_86 ) ;
V_4 -> V_19 = V_227 ;
V_4 -> V_42 &= ~ V_228 ;
V_4 -> V_193 = 0 ;
V_4 -> V_229 = 4 ;
V_4 -> V_230 |= V_231 ;
V_4 -> V_230 |= V_232 ;
V_4 -> V_233 |= V_232 ;
}
static int F_19 ( struct V_3 * V_4 )
{
struct V_1 * V_96 = F_14 ( V_4 ) ;
V_96 -> V_4 = V_4 ;
V_96 -> V_2 = F_18 ( V_4 ) ;
memcpy ( V_4 -> V_194 , & V_96 -> V_13 . V_14 . V_15 , 4 ) ;
memcpy ( V_4 -> V_195 , & V_96 -> V_13 . V_14 . V_16 , 4 ) ;
F_126 ( V_4 ) ;
V_4 -> V_130 = F_140 ( struct V_129 ) ;
if ( ! V_4 -> V_130 )
return - V_73 ;
V_96 -> V_220 = F_141 ( struct V_234 ) ;
if ( ! V_96 -> V_220 ) {
F_138 ( V_4 -> V_130 ) ;
return - V_73 ;
}
return 0 ;
}
static int T_8 F_142 ( struct V_3 * V_4 )
{
struct V_1 * V_96 = F_14 ( V_4 ) ;
struct V_86 * V_14 = & V_96 -> V_13 . V_14 ;
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
V_96 -> V_4 = V_4 ;
V_96 -> V_2 = F_18 ( V_4 ) ;
strcpy ( V_96 -> V_13 . V_44 , V_4 -> V_44 ) ;
V_14 -> V_209 = 4 ;
V_14 -> V_131 = V_116 ;
V_14 -> V_101 = 5 ;
V_14 -> V_117 = 64 ;
V_4 -> V_130 = F_140 ( struct V_129 ) ;
if ( ! V_4 -> V_130 )
return - V_73 ;
V_96 -> V_220 = F_141 ( struct V_234 ) ;
if ( ! V_96 -> V_220 ) {
F_138 ( V_4 -> V_130 ) ;
return - V_73 ;
}
F_21 ( V_4 ) ;
F_10 ( V_11 -> V_21 [ 0 ] , V_96 ) ;
return 0 ;
}
static int F_143 ( struct V_235 * V_236 [] , struct V_235 * V_97 [] )
{
T_6 V_147 ;
if ( ! V_97 || ! V_97 [ V_237 ] )
return 0 ;
V_147 = F_144 ( V_97 [ V_237 ] ) ;
if ( V_147 != V_116 &&
V_147 != V_143 &&
V_147 != 0 )
return - V_76 ;
return 0 ;
}
static void F_145 ( struct V_235 * V_97 [] ,
struct V_22 * V_13 )
{
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_14 . V_209 = 4 ;
V_13 -> V_14 . V_131 = V_116 ;
V_13 -> V_14 . V_101 = 5 ;
V_13 -> V_14 . V_117 = 64 ;
if ( ! V_97 )
return;
if ( V_97 [ V_238 ] )
V_13 -> V_17 = F_146 ( V_97 [ V_238 ] ) ;
if ( V_97 [ V_239 ] )
V_13 -> V_14 . V_15 = F_147 ( V_97 [ V_239 ] ) ;
if ( V_97 [ V_240 ] )
V_13 -> V_14 . V_16 = F_147 ( V_97 [ V_240 ] ) ;
if ( V_97 [ V_241 ] ) {
V_13 -> V_14 . V_117 = F_144 ( V_97 [ V_241 ] ) ;
if ( V_13 -> V_14 . V_117 )
V_13 -> V_14 . V_157 = F_81 ( V_210 ) ;
}
if ( V_97 [ V_242 ] )
V_13 -> V_14 . V_138 = F_144 ( V_97 [ V_242 ] ) ;
if ( ! V_97 [ V_243 ] || F_144 ( V_97 [ V_243 ] ) )
V_13 -> V_14 . V_157 = F_81 ( V_210 ) ;
if ( V_97 [ V_244 ] )
V_13 -> V_40 = F_148 ( V_97 [ V_244 ] ) ;
if ( V_97 [ V_237 ] )
V_13 -> V_14 . V_131 = F_144 ( V_97 [ V_237 ] ) ;
}
static bool F_149 ( struct V_235 * V_97 [] ,
struct V_196 * V_30 )
{
bool V_65 = false ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
if ( ! V_97 )
return V_65 ;
if ( V_97 [ V_245 ] ) {
V_65 = true ;
F_150 ( & V_30 -> V_31 , V_97 [ V_245 ] ,
sizeof( struct V_92 ) ) ;
}
if ( V_97 [ V_246 ] ) {
V_65 = true ;
V_30 -> V_32 =
F_147 ( V_97 [ V_246 ] ) ;
}
if ( V_97 [ V_247 ] ) {
V_65 = true ;
V_30 -> V_33 = F_151 ( V_97 [ V_247 ] ) ;
}
if ( V_97 [ V_248 ] ) {
V_65 = true ;
V_30 -> V_34 =
F_151 ( V_97 [ V_248 ] ) ;
}
return V_65 ;
}
static int F_152 ( struct V_2 * V_249 , struct V_3 * V_4 ,
struct V_235 * V_236 [] , struct V_235 * V_97 [] )
{
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_1 * V_48 ;
#ifdef F_13
struct V_196 V_30 ;
#endif
int V_36 ;
V_48 = F_14 ( V_4 ) ;
F_145 ( V_97 , & V_48 -> V_13 ) ;
if ( F_22 ( V_2 , & V_48 -> V_13 , 0 ) )
return - V_77 ;
V_36 = F_17 ( V_4 ) ;
if ( V_36 < 0 )
return V_36 ;
#ifdef F_13
if ( F_149 ( V_97 , & V_30 ) )
V_36 = F_131 ( V_48 , & V_30 ) ;
#endif
return V_36 ;
}
static int F_153 ( struct V_3 * V_4 , struct V_235 * V_236 [] ,
struct V_235 * V_97 [] )
{
struct V_1 * V_9 = F_14 ( V_4 ) ;
struct V_22 V_75 ;
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
#ifdef F_13
struct V_196 V_30 ;
#endif
if ( V_4 == V_11 -> V_29 )
return - V_76 ;
F_145 ( V_97 , & V_75 ) ;
if ( ( ( V_4 -> V_19 & V_128 ) && ! V_75 . V_14 . V_16 ) ||
( ! ( V_4 -> V_19 & V_128 ) && V_75 . V_14 . V_16 ) )
return - V_76 ;
V_9 = F_22 ( V_2 , & V_75 , 0 ) ;
if ( V_9 ) {
if ( V_9 -> V_4 != V_4 )
return - V_77 ;
} else
V_9 = F_14 ( V_4 ) ;
F_128 ( V_9 , & V_75 ) ;
#ifdef F_13
if ( F_149 ( V_97 , & V_30 ) )
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
F_155 ( sizeof( struct V_92 ) ) +
F_155 ( 4 ) +
F_155 ( 2 ) +
F_155 ( 2 ) +
#endif
0 ;
}
static int F_156 ( struct V_84 * V_85 , const struct V_3 * V_4 )
{
struct V_1 * V_96 = F_14 ( V_4 ) ;
struct V_22 * V_250 = & V_96 -> V_13 ;
if ( F_157 ( V_85 , V_238 , V_250 -> V_17 ) ||
F_158 ( V_85 , V_239 , V_250 -> V_14 . V_15 ) ||
F_158 ( V_85 , V_240 , V_250 -> V_14 . V_16 ) ||
F_159 ( V_85 , V_241 , V_250 -> V_14 . V_117 ) ||
F_159 ( V_85 , V_242 , V_250 -> V_14 . V_138 ) ||
F_159 ( V_85 , V_243 ,
! ! ( V_250 -> V_14 . V_157 & F_81 ( V_210 ) ) ) ||
F_159 ( V_85 , V_237 , V_250 -> V_14 . V_131 ) ||
F_160 ( V_85 , V_244 , V_250 -> V_40 ) )
goto V_251;
#ifdef F_13
if ( F_161 ( V_85 , V_245 , sizeof( struct V_92 ) ,
& V_96 -> V_30 . V_31 ) ||
F_158 ( V_85 , V_246 ,
V_96 -> V_30 . V_32 ) ||
F_162 ( V_85 , V_247 ,
V_96 -> V_30 . V_33 ) ||
F_162 ( V_85 , V_248 ,
V_96 -> V_30 . V_34 ) )
goto V_251;
#endif
return 0 ;
V_251:
return - V_252 ;
}
static void F_163 ( struct V_3 * V_4 , struct V_253 * V_81 )
{
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
if ( V_4 != V_11 -> V_29 )
F_164 ( V_4 , V_81 ) ;
}
static void T_10 F_165 ( struct V_2 * V_2 ,
struct V_253 * V_81 )
{
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
struct V_3 * V_4 , * V_254 ;
int V_24 ;
F_166 (net, dev, aux)
if ( V_4 -> V_45 == & V_46 )
F_164 ( V_4 , V_81 ) ;
for ( V_24 = 1 ; V_24 < 4 ; V_24 ++ ) {
int V_23 ;
for ( V_23 = 0 ; V_23 < V_255 ; V_23 ++ ) {
struct V_1 * V_9 ;
V_9 = F_9 ( V_11 -> V_25 [ V_24 ] [ V_23 ] ) ;
while ( V_9 != NULL ) {
if ( ! F_121 ( F_18 ( V_9 -> V_4 ) , V_2 ) )
F_164 ( V_9 -> V_4 ,
V_81 ) ;
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
V_11 -> V_25 [ 1 ] = V_11 -> V_256 ;
V_11 -> V_25 [ 2 ] = V_11 -> V_257 ;
V_11 -> V_25 [ 3 ] = V_11 -> V_258 ;
V_11 -> V_29 = F_24 ( sizeof( struct V_1 ) , L_6 ,
V_51 ,
V_52 ) ;
if ( ! V_11 -> V_29 ) {
V_36 = - V_73 ;
goto V_259;
}
F_25 ( V_11 -> V_29 , V_2 ) ;
V_11 -> V_29 -> V_45 = & V_46 ;
V_11 -> V_29 -> V_230 |= V_260 ;
V_36 = F_142 ( V_11 -> V_29 ) ;
if ( V_36 )
goto V_261;
F_12 ( V_11 -> V_29 , V_11 ) ;
if ( ( V_36 = F_168 ( V_11 -> V_29 ) ) )
goto V_262;
V_9 = F_14 ( V_11 -> V_29 ) ;
strcpy ( V_9 -> V_13 . V_44 , V_11 -> V_29 -> V_44 ) ;
return 0 ;
V_262:
F_54 ( V_11 -> V_29 ) ;
V_261:
F_26 ( V_11 -> V_29 ) ;
V_259:
return V_36 ;
}
static void T_10 F_169 ( struct V_2 * V_2 )
{
F_170 ( V_263 ) ;
F_171 () ;
F_165 ( V_2 , & V_263 ) ;
F_172 ( & V_263 ) ;
F_173 () ;
}
static void T_11 F_174 ( void )
{
F_175 ( & V_46 ) ;
F_176 ( & V_264 , V_265 ) ;
F_176 ( & V_266 , V_267 ) ;
F_177 ( & V_268 ) ;
F_178 () ;
}
static int T_12 F_179 ( void )
{
int V_36 ;
F_180 ( L_7 ) ;
V_36 = F_181 ( & V_268 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_182 ( & V_264 , V_265 ) ;
if ( V_36 < 0 ) {
F_180 ( L_8 , V_269 ) ;
goto V_270;
}
V_36 = F_182 ( & V_266 , V_267 ) ;
if ( V_36 < 0 ) {
F_180 ( L_9 , V_269 ) ;
goto V_271;
}
V_36 = F_183 ( & V_46 ) ;
if ( V_36 < 0 )
goto V_272;
V_37:
return V_36 ;
V_272:
F_176 ( & V_266 , V_267 ) ;
V_271:
F_176 ( & V_264 , V_265 ) ;
V_270:
F_177 ( & V_268 ) ;
goto V_37;
}
