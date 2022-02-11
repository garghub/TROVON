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
if ( V_9 && ( V_9 -> V_4 -> V_19 & V_20 ) )
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
memcpy ( V_4 -> V_37 , & V_9 -> V_13 . V_14 . V_15 , 4 ) ;
memcpy ( V_4 -> V_38 , & V_9 -> V_13 . V_14 . V_16 , 4 ) ;
if ( ( V_39 V_40 ) V_9 -> V_13 . V_41 & V_42 )
V_4 -> V_43 |= V_44 ;
V_4 -> V_45 = & V_46 ;
V_36 = F_19 ( V_4 ) ;
if ( V_36 < 0 )
goto V_47;
F_12 ( V_4 , V_11 ) ;
F_20 ( V_4 ) ;
F_11 ( V_11 , V_9 ) ;
return 0 ;
V_47:
return V_36 ;
}
static struct V_1 * F_21 ( struct V_2 * V_2 ,
struct V_22 * V_13 , int V_48 )
{
T_1 V_5 = V_13 -> V_14 . V_16 ;
T_1 V_6 = V_13 -> V_14 . V_15 ;
struct V_1 * V_9 , * V_49 ;
struct V_1 T_2 * * V_26 ;
struct V_3 * V_4 ;
char V_50 [ V_51 ] ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
for ( V_26 = F_6 ( V_11 , V_13 ) ;
( V_9 = F_9 ( * V_26 ) ) != NULL ;
V_26 = & V_9 -> V_28 ) {
if ( V_6 == V_9 -> V_13 . V_14 . V_15 &&
V_5 == V_9 -> V_13 . V_14 . V_16 &&
V_13 -> V_17 == V_9 -> V_13 . V_17 ) {
if ( V_48 )
return NULL ;
else
return V_9 ;
}
}
if ( ! V_48 )
goto V_52;
if ( V_13 -> V_50 [ 0 ] )
F_22 ( V_50 , V_13 -> V_50 , V_51 ) ;
else
strcpy ( V_50 , L_1 ) ;
V_4 = F_23 ( sizeof( * V_9 ) , V_50 , V_53 ,
V_54 ) ;
if ( ! V_4 )
return NULL ;
F_24 ( V_4 , V_2 ) ;
V_49 = F_14 ( V_4 ) ;
V_49 -> V_13 = * V_13 ;
if ( F_17 ( V_4 ) < 0 )
goto V_55;
return V_49 ;
V_55:
F_25 ( V_4 ) ;
V_52:
return NULL ;
}
static struct V_56 *
F_26 ( struct V_1 * V_9 , T_1 V_57 )
{
struct V_56 * V_58 ;
F_27 (t->prl)
if ( V_58 -> V_57 == V_57 )
break;
return V_58 ;
}
static int F_28 ( struct V_1 * V_9 ,
struct V_59 T_3 * V_60 )
{
struct V_59 V_61 , * V_62 ;
struct V_56 * V_58 ;
unsigned int V_63 , V_64 = 0 , V_65 , V_66 ;
int V_67 = 0 ;
if ( F_29 ( & V_61 , V_60 , sizeof( V_61 ) ) )
return - V_68 ;
V_63 = V_61 . V_69 / sizeof( V_61 ) ;
if ( V_63 > 1 && V_61 . V_57 != F_16 ( V_70 ) )
V_63 = 1 ;
V_62 = ( V_63 <= 1 || F_30 ( V_71 ) ) ?
F_31 ( V_63 , sizeof( * V_62 ) , V_72 ) :
NULL ;
F_32 () ;
V_65 = V_9 -> V_73 < V_63 ? V_9 -> V_73 : V_63 ;
if ( ! V_62 ) {
V_62 = F_31 ( V_65 , sizeof( * V_62 ) , V_74 ) ;
if ( ! V_62 ) {
V_67 = - V_75 ;
goto V_47;
}
}
V_64 = 0 ;
F_27 (t->prl) {
if ( V_64 >= V_63 )
break;
if ( V_61 . V_57 != F_16 ( V_70 ) && V_58 -> V_57 != V_61 . V_57 )
continue;
V_62 [ V_64 ] . V_57 = V_58 -> V_57 ;
V_62 [ V_64 ] . V_19 = V_58 -> V_19 ;
V_64 ++ ;
if ( V_61 . V_57 != F_16 ( V_70 ) )
break;
}
V_47:
F_33 () ;
V_66 = sizeof( * V_62 ) * V_64 ;
V_67 = 0 ;
if ( ( V_66 && F_34 ( V_60 + 1 , V_62 , V_66 ) ) || F_35 ( V_66 , & V_60 -> V_69 ) )
V_67 = - V_68 ;
F_36 ( V_62 ) ;
return V_67 ;
}
static int
F_37 ( struct V_1 * V_9 , struct V_59 * V_60 , int V_76 )
{
struct V_56 * V_77 ;
int V_36 = 0 ;
if ( V_60 -> V_57 == F_16 ( V_70 ) )
return - V_78 ;
F_38 () ;
for ( V_77 = F_9 ( V_9 -> V_58 ) ; V_77 ; V_77 = F_9 ( V_77 -> V_28 ) ) {
if ( V_77 -> V_57 == V_60 -> V_57 ) {
if ( V_76 ) {
V_77 -> V_19 = V_60 -> V_19 ;
goto V_47;
}
V_36 = - V_79 ;
goto V_47;
}
}
if ( V_76 ) {
V_36 = - V_80 ;
goto V_47;
}
V_77 = F_39 ( sizeof( struct V_56 ) , V_72 ) ;
if ( ! V_77 ) {
V_36 = - V_81 ;
goto V_47;
}
V_77 -> V_28 = V_9 -> V_58 ;
V_77 -> V_57 = V_60 -> V_57 ;
V_77 -> V_19 = V_60 -> V_19 ;
V_9 -> V_73 ++ ;
F_10 ( V_9 -> V_58 , V_77 ) ;
V_47:
return V_36 ;
}
static void F_40 ( struct V_82 * V_83 )
{
struct V_56 * V_77 , * V_84 ;
V_77 = F_41 ( V_83 , struct V_56 , V_82 ) ;
do {
V_84 = F_42 ( V_77 -> V_28 , 1 ) ;
F_36 ( V_77 ) ;
V_77 = V_84 ;
} while ( V_77 );
}
static int
F_43 ( struct V_1 * V_9 , struct V_59 * V_60 )
{
struct V_56 * V_85 ;
struct V_56 T_2 * * V_77 ;
int V_36 = 0 ;
F_38 () ;
if ( V_60 && V_60 -> V_57 != F_16 ( V_70 ) ) {
for ( V_77 = & V_9 -> V_58 ;
( V_85 = F_9 ( * V_77 ) ) != NULL ;
V_77 = & V_85 -> V_28 ) {
if ( V_85 -> V_57 == V_60 -> V_57 ) {
* V_77 = V_85 -> V_28 ;
F_44 ( V_85 , V_82 ) ;
V_9 -> V_73 -- ;
goto V_47;
}
}
V_36 = - V_80 ;
} else {
V_85 = F_9 ( V_9 -> V_58 ) ;
if ( V_85 ) {
V_9 -> V_73 = 0 ;
F_45 ( & V_85 -> V_82 , F_40 ) ;
V_9 -> V_58 = NULL ;
}
}
V_47:
return V_36 ;
}
static int
F_46 ( struct V_86 * V_87 , const struct V_88 * V_14 , struct V_1 * V_9 )
{
struct V_56 * V_77 ;
int V_89 = 1 ;
F_32 () ;
V_77 = F_26 ( V_9 , V_14 -> V_15 ) ;
if ( V_77 ) {
if ( V_77 -> V_19 & V_90 )
V_87 -> V_91 = V_92 ;
else
V_87 -> V_91 = V_93 ;
} else {
const struct V_94 * V_95 = & F_47 ( V_87 ) -> V_15 ;
if ( F_48 ( V_95 ) &&
( V_95 -> V_96 [ 3 ] == V_14 -> V_15 ) &&
F_49 ( V_95 , V_9 -> V_4 ) )
V_87 -> V_91 = V_97 ;
else
V_89 = 0 ;
}
F_33 () ;
return V_89 ;
}
static void F_50 ( struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_98 -> V_2 , V_12 ) ;
if ( V_4 == V_11 -> V_29 ) {
F_51 ( V_11 -> V_21 [ 0 ] , NULL ) ;
} else {
F_8 ( V_11 , V_98 ) ;
F_43 ( V_98 , NULL ) ;
}
F_52 ( V_98 ) ;
F_53 ( V_4 ) ;
}
static int F_54 ( struct V_86 * V_87 )
{
int V_99 = ( ( const struct V_88 * ) V_87 -> V_100 ) -> V_99 * 4 ;
struct V_101 * V_102 ;
struct V_86 * V_103 ;
if ( ! F_55 ( V_87 , V_99 + sizeof( struct V_104 ) + 8 ) )
return 1 ;
V_103 = F_56 ( V_87 , V_74 ) ;
if ( ! V_103 )
return 1 ;
F_57 ( V_103 ) ;
F_58 ( V_103 , V_99 ) ;
F_59 ( V_103 ) ;
V_102 = F_60 ( F_18 ( V_87 -> V_4 ) , & F_47 ( V_103 ) -> V_15 , NULL , 0 , 0 ) ;
if ( V_102 && V_102 -> V_105 . V_4 )
V_103 -> V_4 = V_102 -> V_105 . V_4 ;
F_61 ( V_103 , V_106 , V_107 , 0 ) ;
if ( V_102 )
F_62 ( V_102 ) ;
F_63 ( V_103 ) ;
return 0 ;
}
static int F_64 ( struct V_86 * V_87 , T_4 V_108 )
{
const struct V_88 * V_14 = ( const struct V_88 * ) V_87 -> V_100 ;
const int type = F_65 ( V_87 ) -> type ;
const int V_109 = F_65 ( V_87 ) -> V_109 ;
struct V_1 * V_9 ;
int V_36 ;
switch ( type ) {
default:
case V_110 :
return 0 ;
case V_111 :
switch ( V_109 ) {
case V_112 :
return 0 ;
default:
break;
}
break;
case V_113 :
if ( V_109 != V_114 )
return 0 ;
break;
case V_115 :
break;
}
V_36 = - V_116 ;
V_9 = F_1 ( F_18 ( V_87 -> V_4 ) ,
V_87 -> V_4 ,
V_14 -> V_16 ,
V_14 -> V_15 ) ;
if ( ! V_9 )
goto V_47;
if ( type == V_111 && V_109 == V_117 ) {
F_66 ( V_87 , F_18 ( V_87 -> V_4 ) , V_108 ,
V_9 -> V_13 . V_17 , 0 , V_118 , 0 ) ;
V_36 = 0 ;
goto V_47;
}
if ( type == V_115 ) {
F_67 ( V_87 , F_18 ( V_87 -> V_4 ) , V_9 -> V_13 . V_17 , 0 ,
V_118 , 0 ) ;
V_36 = 0 ;
goto V_47;
}
if ( V_9 -> V_13 . V_14 . V_16 == 0 )
goto V_47;
V_36 = 0 ;
if ( ! F_54 ( V_87 ) )
goto V_47;
if ( V_9 -> V_13 . V_14 . V_119 == 0 && type == V_113 )
goto V_47;
if ( F_68 ( V_120 , V_9 -> V_121 + V_122 ) )
V_9 -> V_123 ++ ;
else
V_9 -> V_123 = 1 ;
V_9 -> V_121 = V_120 ;
V_47:
return V_36 ;
}
static inline bool F_69 ( struct V_1 * V_98 , const T_1 V_124 ,
const struct V_94 * V_125 )
{
T_1 V_126 = 0 ;
if ( F_70 ( V_98 , V_125 , & V_126 ) && V_124 != V_126 )
return true ;
return false ;
}
static bool F_71 ( const struct V_1 * V_98 ,
const struct V_94 * V_127 )
{
int V_128 ;
#ifdef F_13
V_128 = V_98 -> V_30 . V_33 + 32
- V_98 -> V_30 . V_34 ;
#else
V_128 = 48 ;
#endif
return F_72 ( V_127 , V_128 , V_98 -> V_4 ) ;
}
static bool F_73 ( struct V_86 * V_87 ,
const struct V_88 * V_14 ,
struct V_1 * V_98 )
{
const struct V_104 * V_129 ;
if ( V_98 -> V_4 -> V_43 & V_44 ) {
if ( ! F_46 ( V_87 , V_14 , V_98 ) )
return true ;
return false ;
}
if ( V_98 -> V_4 -> V_19 & V_130 )
return false ;
V_129 = F_47 ( V_87 ) ;
if ( F_74 ( F_69 ( V_98 , V_14 -> V_15 , & V_129 -> V_15 ) ) ) {
F_75 ( L_2 ,
& V_14 -> V_15 , & V_129 -> V_15 ,
& V_14 -> V_16 , & V_129 -> V_16 ) ;
return true ;
}
if ( F_76 ( ! F_69 ( V_98 , V_14 -> V_16 , & V_129 -> V_16 ) ) )
return false ;
if ( F_71 ( V_98 , & V_129 -> V_16 ) )
return false ;
F_75 ( L_3 ,
& V_14 -> V_15 , & V_129 -> V_15 ,
& V_14 -> V_16 , & V_129 -> V_16 ) ;
return true ;
}
static int F_77 ( struct V_86 * V_87 )
{
const struct V_88 * V_14 = F_78 ( V_87 ) ;
struct V_1 * V_98 ;
int V_36 ;
V_98 = F_1 ( F_18 ( V_87 -> V_4 ) , V_87 -> V_4 ,
V_14 -> V_15 , V_14 -> V_16 ) ;
if ( V_98 ) {
struct V_131 * V_132 ;
if ( V_98 -> V_13 . V_14 . V_133 != V_118 &&
V_98 -> V_13 . V_14 . V_133 != 0 )
goto V_47;
V_87 -> V_134 = V_87 -> V_135 ;
F_59 ( V_87 ) ;
F_79 ( V_87 ) -> V_19 = 0 ;
V_87 -> V_133 = F_80 ( V_136 ) ;
if ( F_73 ( V_87 , V_14 , V_98 ) ) {
V_98 -> V_4 -> V_137 . V_138 ++ ;
goto V_47;
}
F_81 ( V_87 , V_98 -> V_4 , V_98 -> V_2 ) ;
V_36 = F_82 ( V_14 , V_87 ) ;
if ( F_74 ( V_36 ) ) {
if ( V_139 )
F_83 ( L_4 ,
& V_14 -> V_15 , V_14 -> V_140 ) ;
if ( V_36 > 1 ) {
++ V_98 -> V_4 -> V_137 . V_141 ;
++ V_98 -> V_4 -> V_137 . V_138 ;
goto V_47;
}
}
V_132 = F_84 ( V_98 -> V_4 -> V_132 ) ;
F_85 ( & V_132 -> V_142 ) ;
V_132 -> V_143 ++ ;
V_132 -> V_144 += V_87 -> V_66 ;
F_86 ( & V_132 -> V_142 ) ;
F_87 ( V_87 ) ;
return 0 ;
}
return 1 ;
V_47:
F_63 ( V_87 ) ;
return 0 ;
}
static int F_88 ( struct V_86 * V_87 )
{
const struct V_88 * V_14 ;
struct V_1 * V_98 ;
V_14 = F_78 ( V_87 ) ;
V_98 = F_1 ( F_18 ( V_87 -> V_4 ) , V_87 -> V_4 ,
V_14 -> V_15 , V_14 -> V_16 ) ;
if ( V_98 ) {
if ( V_98 -> V_13 . V_14 . V_133 != V_145 &&
V_98 -> V_13 . V_14 . V_133 != 0 )
goto V_146;
if ( ! F_89 ( NULL , V_147 , V_87 ) )
goto V_146;
if ( F_90 ( V_87 , 0 , V_148 . V_149 ) )
goto V_146;
return F_91 ( V_98 , V_87 , & V_148 , NULL , V_139 ) ;
}
return 1 ;
V_146:
F_63 ( V_87 ) ;
return 0 ;
}
static bool F_70 ( struct V_1 * V_98 , const struct V_94 * V_127 ,
T_1 * V_150 )
{
#ifdef F_13
if ( F_92 ( V_127 , & V_98 -> V_30 . V_31 ,
V_98 -> V_30 . V_33 ) ) {
unsigned int V_151 , V_152 ;
int V_153 ;
T_4 V_154 ;
V_151 = V_98 -> V_30 . V_33 >> 5 ;
V_152 = V_98 -> V_30 . V_33 & 0x1f ;
V_154 = ( F_93 ( V_127 -> V_96 [ V_151 ] ) << V_152 ) >>
V_98 -> V_30 . V_34 ;
V_153 = V_152 - V_98 -> V_30 . V_34 ;
if ( V_153 > 0 )
V_154 |= F_93 ( V_127 -> V_96 [ V_151 + 1 ] ) >>
( 32 - V_153 ) ;
* V_150 = V_98 -> V_30 . V_32 | F_16 ( V_154 ) ;
return true ;
}
#else
if ( V_127 -> V_155 [ 0 ] == F_80 ( 0x2002 ) ) {
memcpy ( V_150 , & V_127 -> V_155 [ 1 ] , 4 ) ;
return true ;
}
#endif
return false ;
}
static inline T_1 F_94 ( struct V_1 * V_98 ,
const struct V_94 * V_127 )
{
T_1 V_105 = 0 ;
F_70 ( V_98 , V_127 , & V_105 ) ;
return V_105 ;
}
static T_5 F_95 ( struct V_86 * V_87 ,
struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
const struct V_88 * V_156 = & V_98 -> V_13 . V_14 ;
const struct V_104 * V_157 = F_47 ( V_87 ) ;
T_6 V_140 = V_98 -> V_13 . V_14 . V_140 ;
T_7 V_158 = V_156 -> V_159 ;
struct V_160 * V_102 ;
struct V_3 * V_161 ;
unsigned int V_162 ;
T_1 V_105 = V_156 -> V_16 ;
struct V_163 V_164 ;
int V_165 ;
const struct V_94 * V_95 ;
int V_166 ;
T_6 V_119 ;
T_6 V_133 = V_118 ;
int V_167 = V_98 -> V_168 + sizeof( struct V_88 ) ;
if ( V_87 -> V_133 != F_80 ( V_136 ) )
goto V_169;
if ( V_140 == 1 )
V_140 = F_96 ( V_157 ) ;
if ( V_4 -> V_43 & V_44 ) {
struct V_170 * V_171 = NULL ;
bool V_172 = false ;
if ( F_97 ( V_87 ) )
V_171 = F_98 ( F_97 ( V_87 ) , & V_157 -> V_16 ) ;
if ( ! V_171 ) {
F_99 ( L_5 ) ;
goto V_169;
}
V_95 = ( const struct V_94 * ) & V_171 -> V_173 ;
V_166 = F_100 ( V_95 ) ;
if ( ( V_166 & V_174 ) &&
F_48 ( V_95 ) )
V_105 = V_95 -> V_96 [ 3 ] ;
else
V_172 = true ;
F_101 ( V_171 ) ;
if ( V_172 )
goto V_169;
}
if ( ! V_105 )
V_105 = F_94 ( V_98 , & V_157 -> V_16 ) ;
if ( ! V_105 ) {
struct V_170 * V_171 = NULL ;
bool V_172 = false ;
if ( F_97 ( V_87 ) )
V_171 = F_98 ( F_97 ( V_87 ) , & V_157 -> V_16 ) ;
if ( ! V_171 ) {
F_99 ( L_5 ) ;
goto V_169;
}
V_95 = ( const struct V_94 * ) & V_171 -> V_173 ;
V_166 = F_100 ( V_95 ) ;
if ( V_166 == V_175 ) {
V_95 = & F_47 ( V_87 ) -> V_16 ;
V_166 = F_100 ( V_95 ) ;
}
if ( ( V_166 & V_176 ) != 0 )
V_105 = V_95 -> V_96 [ 3 ] ;
else
V_172 = true ;
F_101 ( V_171 ) ;
if ( V_172 )
goto V_169;
}
V_102 = F_102 ( V_98 -> V_2 , & V_164 , NULL ,
V_105 , V_156 -> V_15 ,
0 , 0 ,
V_118 , F_103 ( V_140 ) ,
V_98 -> V_13 . V_17 ) ;
if ( F_104 ( V_102 ) ) {
V_4 -> V_137 . V_177 ++ ;
goto V_178;
}
if ( V_102 -> V_179 != V_180 ) {
F_105 ( V_102 ) ;
V_4 -> V_137 . V_177 ++ ;
goto V_178;
}
V_161 = V_102 -> V_105 . V_4 ;
if ( V_161 == V_4 ) {
F_105 ( V_102 ) ;
V_4 -> V_137 . V_181 ++ ;
goto V_169;
}
V_87 = F_106 ( V_87 , false , V_182 ) ;
if ( F_104 ( V_87 ) ) {
F_105 ( V_102 ) ;
goto V_47;
}
if ( V_158 ) {
V_165 = F_107 ( & V_102 -> V_105 ) - V_167 ;
if ( V_165 < 68 ) {
V_4 -> V_137 . V_181 ++ ;
F_105 ( V_102 ) ;
goto V_169;
}
if ( V_165 < V_183 ) {
V_165 = V_183 ;
V_158 = 0 ;
}
if ( V_98 -> V_13 . V_14 . V_16 && F_97 ( V_87 ) )
F_97 ( V_87 ) -> V_184 -> V_185 ( F_97 ( V_87 ) , NULL , V_87 , V_165 ) ;
if ( V_87 -> V_66 > V_165 && ! F_108 ( V_87 ) ) {
F_61 ( V_87 , V_186 , 0 , V_165 ) ;
F_105 ( V_102 ) ;
goto V_169;
}
}
if ( V_98 -> V_123 > 0 ) {
if ( F_68 ( V_120 ,
V_98 -> V_121 + V_122 ) ) {
V_98 -> V_123 -- ;
F_109 ( V_87 ) ;
} else
V_98 -> V_123 = 0 ;
}
V_162 = F_110 ( V_161 ) + V_167 ;
if ( F_111 ( V_87 ) < V_162 || F_112 ( V_87 ) ||
( F_113 ( V_87 ) && ! F_114 ( V_87 , 0 ) ) ) {
struct V_86 * V_187 = F_115 ( V_87 , V_162 ) ;
if ( ! V_187 ) {
F_105 ( V_102 ) ;
V_4 -> V_137 . V_188 ++ ;
F_63 ( V_87 ) ;
return V_189 ;
}
if ( V_87 -> V_190 )
F_116 ( V_187 , V_87 -> V_190 ) ;
F_117 ( V_87 ) ;
V_87 = V_187 ;
V_157 = F_47 ( V_87 ) ;
}
V_119 = V_156 -> V_119 ;
if ( V_119 == 0 )
V_119 = V_157 -> V_191 ;
V_140 = F_118 ( V_140 , F_96 ( V_157 ) ) ;
if ( F_119 ( V_87 , V_98 , & V_133 , & V_164 ) < 0 ) {
F_105 ( V_102 ) ;
goto V_169;
}
F_120 ( V_87 , V_118 ) ;
F_121 ( NULL , V_102 , V_87 , V_164 . V_15 , V_164 . V_16 , V_133 , V_140 , V_119 ,
V_158 , ! F_122 ( V_98 -> V_2 , F_18 ( V_4 ) ) ) ;
return V_189 ;
V_178:
F_109 ( V_87 ) ;
V_169:
F_63 ( V_87 ) ;
V_47:
V_4 -> V_137 . V_192 ++ ;
return V_189 ;
}
static T_5 F_123 ( struct V_86 * V_87 , struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
const struct V_88 * V_156 = & V_98 -> V_13 . V_14 ;
V_87 = F_106 ( V_87 , false , V_193 ) ;
if ( F_104 ( V_87 ) )
goto V_47;
F_120 ( V_87 , V_145 ) ;
F_124 ( V_87 , V_4 , V_156 , V_145 ) ;
return V_189 ;
V_47:
V_4 -> V_137 . V_192 ++ ;
return V_189 ;
}
static T_5 F_125 ( struct V_86 * V_87 ,
struct V_3 * V_4 )
{
switch ( V_87 -> V_133 ) {
case F_80 ( V_194 ) :
F_123 ( V_87 , V_4 ) ;
break;
case F_80 ( V_136 ) :
F_95 ( V_87 , V_4 ) ;
break;
default:
goto V_195;
}
return V_189 ;
V_195:
V_4 -> V_137 . V_192 ++ ;
F_63 ( V_87 ) ;
return V_189 ;
}
static void F_126 ( struct V_3 * V_4 )
{
struct V_3 * V_161 = NULL ;
struct V_1 * V_98 ;
const struct V_88 * V_14 ;
struct V_163 V_164 ;
V_98 = F_14 ( V_4 ) ;
V_14 = & V_98 -> V_13 . V_14 ;
if ( V_14 -> V_16 ) {
struct V_160 * V_102 = F_102 ( V_98 -> V_2 , & V_164 ,
NULL ,
V_14 -> V_16 , V_14 -> V_15 ,
0 , 0 ,
V_118 ,
F_103 ( V_14 -> V_140 ) ,
V_98 -> V_13 . V_17 ) ;
if ( ! F_104 ( V_102 ) ) {
V_161 = V_102 -> V_105 . V_4 ;
F_105 ( V_102 ) ;
}
V_4 -> V_19 |= V_130 ;
}
if ( ! V_161 && V_98 -> V_13 . V_17 )
V_161 = F_127 ( V_98 -> V_2 , V_98 -> V_13 . V_17 ) ;
if ( V_161 ) {
int V_167 = V_98 -> V_168 + sizeof( struct V_88 ) ;
V_4 -> V_196 = V_161 -> V_196 + sizeof( struct V_88 ) ;
V_4 -> V_165 = V_161 -> V_165 - V_167 ;
if ( V_4 -> V_165 < V_183 )
V_4 -> V_165 = V_183 ;
}
}
static void F_128 ( struct V_1 * V_9 , struct V_22 * V_77 )
{
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
F_8 ( V_11 , V_9 ) ;
F_129 () ;
V_9 -> V_13 . V_14 . V_15 = V_77 -> V_14 . V_15 ;
V_9 -> V_13 . V_14 . V_16 = V_77 -> V_14 . V_16 ;
memcpy ( V_9 -> V_4 -> V_37 , & V_77 -> V_14 . V_15 , 4 ) ;
memcpy ( V_9 -> V_4 -> V_38 , & V_77 -> V_14 . V_16 , 4 ) ;
F_11 ( V_11 , V_9 ) ;
V_9 -> V_13 . V_14 . V_119 = V_77 -> V_14 . V_119 ;
V_9 -> V_13 . V_14 . V_140 = V_77 -> V_14 . V_140 ;
if ( V_9 -> V_13 . V_17 != V_77 -> V_17 ) {
V_9 -> V_13 . V_17 = V_77 -> V_17 ;
F_126 ( V_9 -> V_4 ) ;
}
F_52 ( V_9 ) ;
F_130 ( V_9 -> V_4 ) ;
}
static int F_131 ( struct V_1 * V_9 ,
struct V_197 * V_30 )
{
struct V_94 V_31 ;
T_1 V_32 ;
if ( V_30 -> V_34 > 32 ||
V_30 -> V_33 + ( 32 - V_30 -> V_34 ) > 64 )
return - V_78 ;
F_132 ( & V_31 , & V_30 -> V_31 , V_30 -> V_33 ) ;
if ( ! F_133 ( & V_31 , & V_30 -> V_31 ) )
return - V_78 ;
if ( V_30 -> V_34 )
V_32 = V_30 -> V_32 &
F_16 ( 0xffffffffUL <<
( 32 - V_30 -> V_34 ) ) ;
else
V_32 = 0 ;
if ( V_32 != V_30 -> V_32 )
return - V_78 ;
V_9 -> V_30 . V_31 = V_31 ;
V_9 -> V_30 . V_32 = V_32 ;
V_9 -> V_30 . V_33 = V_30 -> V_33 ;
V_9 -> V_30 . V_34 = V_30 -> V_34 ;
F_52 ( V_9 ) ;
F_130 ( V_9 -> V_4 ) ;
return 0 ;
}
static int
F_134 ( struct V_3 * V_4 , struct V_198 * V_199 , int V_200 )
{
int V_36 = 0 ;
struct V_22 V_77 ;
struct V_59 V_58 ;
struct V_1 * V_9 = F_14 ( V_4 ) ;
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
#ifdef F_13
struct V_197 V_30 ;
#endif
switch ( V_200 ) {
case V_201 :
#ifdef F_13
case V_202 :
#endif
if ( V_4 == V_11 -> V_29 ) {
if ( F_29 ( & V_77 , V_199 -> V_203 . V_204 , sizeof( V_77 ) ) ) {
V_36 = - V_68 ;
break;
}
V_9 = F_21 ( V_2 , & V_77 , 0 ) ;
if ( ! V_9 )
V_9 = F_14 ( V_4 ) ;
}
V_36 = - V_68 ;
if ( V_200 == V_201 ) {
memcpy ( & V_77 , & V_9 -> V_13 , sizeof( V_77 ) ) ;
if ( F_34 ( V_199 -> V_203 . V_204 , & V_77 ,
sizeof( V_77 ) ) )
goto V_205;
#ifdef F_13
} else {
V_30 . V_31 = V_9 -> V_30 . V_31 ;
V_30 . V_32 = V_9 -> V_30 . V_32 ;
V_30 . V_33 = V_9 -> V_30 . V_33 ;
V_30 . V_34 = V_9 -> V_30 . V_34 ;
if ( F_34 ( V_199 -> V_203 . V_204 , & V_30 ,
sizeof( V_30 ) ) )
goto V_205;
#endif
}
V_36 = 0 ;
break;
case V_206 :
case V_207 :
V_36 = - V_208 ;
if ( ! F_135 ( V_2 -> V_209 , V_71 ) )
goto V_205;
V_36 = - V_68 ;
if ( F_29 ( & V_77 , V_199 -> V_203 . V_204 , sizeof( V_77 ) ) )
goto V_205;
V_36 = - V_78 ;
if ( V_77 . V_14 . V_133 != V_118 &&
V_77 . V_14 . V_133 != V_145 &&
V_77 . V_14 . V_133 != 0 )
goto V_205;
if ( V_77 . V_14 . V_210 != 4 ||
V_77 . V_14 . V_99 != 5 || ( V_77 . V_14 . V_159 & F_80 ( ~ V_211 ) ) )
goto V_205;
if ( V_77 . V_14 . V_119 )
V_77 . V_14 . V_159 |= F_80 ( V_211 ) ;
V_9 = F_21 ( V_2 , & V_77 , V_200 == V_206 ) ;
if ( V_4 != V_11 -> V_29 && V_200 == V_207 ) {
if ( V_9 ) {
if ( V_9 -> V_4 != V_4 ) {
V_36 = - V_79 ;
break;
}
} else {
if ( ( ( V_4 -> V_19 & V_130 ) && ! V_77 . V_14 . V_16 ) ||
( ! ( V_4 -> V_19 & V_130 ) && V_77 . V_14 . V_16 ) ) {
V_36 = - V_78 ;
break;
}
V_9 = F_14 ( V_4 ) ;
}
F_128 ( V_9 , & V_77 ) ;
}
if ( V_9 ) {
V_36 = 0 ;
if ( F_34 ( V_199 -> V_203 . V_204 , & V_9 -> V_13 , sizeof( V_77 ) ) )
V_36 = - V_68 ;
} else
V_36 = ( V_200 == V_206 ? - V_81 : - V_116 ) ;
break;
case V_212 :
V_36 = - V_208 ;
if ( ! F_135 ( V_2 -> V_209 , V_71 ) )
goto V_205;
if ( V_4 == V_11 -> V_29 ) {
V_36 = - V_68 ;
if ( F_29 ( & V_77 , V_199 -> V_203 . V_204 , sizeof( V_77 ) ) )
goto V_205;
V_36 = - V_116 ;
V_9 = F_21 ( V_2 , & V_77 , 0 ) ;
if ( ! V_9 )
goto V_205;
V_36 = - V_208 ;
if ( V_9 == F_14 ( V_11 -> V_29 ) )
goto V_205;
V_4 = V_9 -> V_4 ;
}
F_136 ( V_4 ) ;
V_36 = 0 ;
break;
case V_213 :
V_36 = - V_78 ;
if ( V_4 == V_11 -> V_29 )
goto V_205;
V_36 = F_28 ( V_9 , V_199 -> V_203 . V_204 ) ;
break;
case V_214 :
case V_215 :
case V_216 :
V_36 = - V_208 ;
if ( ! F_135 ( V_2 -> V_209 , V_71 ) )
goto V_205;
V_36 = - V_78 ;
if ( V_4 == V_11 -> V_29 )
goto V_205;
V_36 = - V_68 ;
if ( F_29 ( & V_58 , V_199 -> V_203 . V_204 , sizeof( V_58 ) ) )
goto V_205;
switch ( V_200 ) {
case V_215 :
V_36 = F_43 ( V_9 , & V_58 ) ;
break;
case V_214 :
case V_216 :
V_36 = F_37 ( V_9 , & V_58 , V_200 == V_216 ) ;
break;
}
F_52 ( V_9 ) ;
F_130 ( V_4 ) ;
break;
#ifdef F_13
case V_217 :
case V_218 :
case V_219 :
V_36 = - V_208 ;
if ( ! F_135 ( V_2 -> V_209 , V_71 ) )
goto V_205;
V_36 = - V_68 ;
if ( F_29 ( & V_30 , V_199 -> V_203 . V_204 ,
sizeof( V_30 ) ) )
goto V_205;
if ( V_200 != V_219 ) {
V_36 = F_131 ( V_9 , & V_30 ) ;
if ( V_36 < 0 )
goto V_205;
} else
F_12 ( V_4 , V_11 ) ;
V_36 = 0 ;
break;
#endif
default:
V_36 = - V_78 ;
}
V_205:
return V_36 ;
}
static int F_137 ( struct V_3 * V_4 , int V_220 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
int V_167 = V_98 -> V_168 + sizeof( struct V_88 ) ;
if ( V_220 < V_183 || V_220 > 0xFFF8 - V_167 )
return - V_78 ;
V_4 -> V_165 = V_220 ;
return 0 ;
}
static void F_25 ( struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
F_138 ( V_98 -> V_221 ) ;
F_138 ( V_4 -> V_132 ) ;
F_139 ( V_4 ) ;
}
static void V_54 ( struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
int V_167 = V_98 -> V_168 + sizeof( struct V_88 ) ;
V_4 -> V_222 = & V_223 ;
V_4 -> V_224 = F_25 ;
V_4 -> type = V_225 ;
V_4 -> V_196 = V_226 + V_167 ;
V_4 -> V_165 = V_227 - V_167 ;
V_4 -> V_19 = V_228 ;
F_140 ( V_4 ) ;
V_4 -> V_229 = 4 ;
V_4 -> V_230 |= V_231 ;
V_4 -> V_230 |= V_232 ;
V_4 -> V_233 |= V_232 ;
}
static int F_141 ( struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
V_98 -> V_4 = V_4 ;
V_98 -> V_2 = F_18 ( V_4 ) ;
strcpy ( V_98 -> V_13 . V_50 , V_4 -> V_50 ) ;
F_126 ( V_4 ) ;
V_4 -> V_132 = F_142 ( struct V_131 ) ;
if ( ! V_4 -> V_132 )
return - V_75 ;
V_98 -> V_221 = F_143 ( struct V_234 ) ;
if ( ! V_98 -> V_221 ) {
F_138 ( V_4 -> V_132 ) ;
return - V_75 ;
}
return 0 ;
}
static void T_8 F_144 ( struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
struct V_88 * V_14 = & V_98 -> V_13 . V_14 ;
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
V_14 -> V_210 = 4 ;
V_14 -> V_133 = V_118 ;
V_14 -> V_99 = 5 ;
V_14 -> V_119 = 64 ;
F_20 ( V_4 ) ;
F_10 ( V_11 -> V_21 [ 0 ] , V_98 ) ;
}
static int F_145 ( struct V_235 * V_236 [] , struct V_235 * V_100 [] )
{
T_6 V_149 ;
if ( ! V_100 || ! V_100 [ V_237 ] )
return 0 ;
V_149 = F_146 ( V_100 [ V_237 ] ) ;
if ( V_149 != V_118 &&
V_149 != V_145 &&
V_149 != 0 )
return - V_78 ;
return 0 ;
}
static void F_147 ( struct V_235 * V_100 [] ,
struct V_22 * V_13 )
{
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_14 . V_210 = 4 ;
V_13 -> V_14 . V_133 = V_118 ;
V_13 -> V_14 . V_99 = 5 ;
V_13 -> V_14 . V_119 = 64 ;
if ( ! V_100 )
return;
if ( V_100 [ V_238 ] )
V_13 -> V_17 = F_148 ( V_100 [ V_238 ] ) ;
if ( V_100 [ V_239 ] )
V_13 -> V_14 . V_15 = F_149 ( V_100 [ V_239 ] ) ;
if ( V_100 [ V_240 ] )
V_13 -> V_14 . V_16 = F_149 ( V_100 [ V_240 ] ) ;
if ( V_100 [ V_241 ] ) {
V_13 -> V_14 . V_119 = F_146 ( V_100 [ V_241 ] ) ;
if ( V_13 -> V_14 . V_119 )
V_13 -> V_14 . V_159 = F_80 ( V_211 ) ;
}
if ( V_100 [ V_242 ] )
V_13 -> V_14 . V_140 = F_146 ( V_100 [ V_242 ] ) ;
if ( ! V_100 [ V_243 ] || F_146 ( V_100 [ V_243 ] ) )
V_13 -> V_14 . V_159 = F_80 ( V_211 ) ;
if ( V_100 [ V_244 ] )
V_13 -> V_41 = F_150 ( V_100 [ V_244 ] ) ;
if ( V_100 [ V_237 ] )
V_13 -> V_14 . V_133 = F_146 ( V_100 [ V_237 ] ) ;
}
static bool F_151 ( struct V_235 * V_100 [] ,
struct F_119 * V_245 )
{
bool V_67 = false ;
memset ( V_245 , 0 , sizeof( * V_245 ) ) ;
if ( ! V_100 )
return V_67 ;
if ( V_100 [ V_246 ] ) {
V_67 = true ;
V_245 -> type = F_152 ( V_100 [ V_246 ] ) ;
}
if ( V_100 [ V_247 ] ) {
V_67 = true ;
V_245 -> V_19 = F_152 ( V_100 [ V_247 ] ) ;
}
if ( V_100 [ V_248 ] ) {
V_67 = true ;
V_245 -> V_249 = F_150 ( V_100 [ V_248 ] ) ;
}
if ( V_100 [ V_250 ] ) {
V_67 = true ;
V_245 -> V_251 = F_150 ( V_100 [ V_250 ] ) ;
}
return V_67 ;
}
static bool F_153 ( struct V_235 * V_100 [] ,
struct V_197 * V_30 )
{
bool V_67 = false ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
if ( ! V_100 )
return V_67 ;
if ( V_100 [ V_252 ] ) {
V_67 = true ;
V_30 -> V_31 = F_154 ( V_100 [ V_252 ] ) ;
}
if ( V_100 [ V_253 ] ) {
V_67 = true ;
V_30 -> V_32 =
F_149 ( V_100 [ V_253 ] ) ;
}
if ( V_100 [ V_254 ] ) {
V_67 = true ;
V_30 -> V_33 = F_152 ( V_100 [ V_254 ] ) ;
}
if ( V_100 [ V_255 ] ) {
V_67 = true ;
V_30 -> V_34 =
F_152 ( V_100 [ V_255 ] ) ;
}
return V_67 ;
}
static int F_155 ( struct V_2 * V_256 , struct V_3 * V_4 ,
struct V_235 * V_236 [] , struct V_235 * V_100 [] )
{
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_1 * V_49 ;
struct F_119 V_245 ;
#ifdef F_13
struct V_197 V_30 ;
#endif
int V_36 ;
V_49 = F_14 ( V_4 ) ;
if ( F_151 ( V_100 , & V_245 ) ) {
V_36 = F_156 ( V_49 , & V_245 ) ;
if ( V_36 < 0 )
return V_36 ;
}
F_147 ( V_100 , & V_49 -> V_13 ) ;
if ( F_21 ( V_2 , & V_49 -> V_13 , 0 ) )
return - V_79 ;
V_36 = F_17 ( V_4 ) ;
if ( V_36 < 0 )
return V_36 ;
#ifdef F_13
if ( F_153 ( V_100 , & V_30 ) )
V_36 = F_131 ( V_49 , & V_30 ) ;
#endif
return V_36 ;
}
static int F_157 ( struct V_3 * V_4 , struct V_235 * V_236 [] ,
struct V_235 * V_100 [] )
{
struct V_1 * V_9 = F_14 ( V_4 ) ;
struct V_22 V_77 ;
struct F_119 V_245 ;
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
#ifdef F_13
struct V_197 V_30 ;
#endif
int V_36 ;
if ( V_4 == V_11 -> V_29 )
return - V_78 ;
if ( F_151 ( V_100 , & V_245 ) ) {
V_36 = F_156 ( V_9 , & V_245 ) ;
if ( V_36 < 0 )
return V_36 ;
}
F_147 ( V_100 , & V_77 ) ;
if ( ( ( V_4 -> V_19 & V_130 ) && ! V_77 . V_14 . V_16 ) ||
( ! ( V_4 -> V_19 & V_130 ) && V_77 . V_14 . V_16 ) )
return - V_78 ;
V_9 = F_21 ( V_2 , & V_77 , 0 ) ;
if ( V_9 ) {
if ( V_9 -> V_4 != V_4 )
return - V_79 ;
} else
V_9 = F_14 ( V_4 ) ;
F_128 ( V_9 , & V_77 ) ;
#ifdef F_13
if ( F_153 ( V_100 , & V_30 ) )
return F_131 ( V_9 , & V_30 ) ;
#endif
return 0 ;
}
static T_9 F_158 ( const struct V_3 * V_4 )
{
return
F_159 ( 4 ) +
F_159 ( 4 ) +
F_159 ( 4 ) +
F_159 ( 1 ) +
F_159 ( 1 ) +
F_159 ( 1 ) +
F_159 ( 2 ) +
F_159 ( 1 ) +
#ifdef F_13
F_159 ( sizeof( struct V_94 ) ) +
F_159 ( 4 ) +
F_159 ( 2 ) +
F_159 ( 2 ) +
#endif
F_159 ( 2 ) +
F_159 ( 2 ) +
F_159 ( 2 ) +
F_159 ( 2 ) +
0 ;
}
static int F_160 ( struct V_86 * V_87 , const struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
struct V_22 * V_257 = & V_98 -> V_13 ;
if ( F_161 ( V_87 , V_238 , V_257 -> V_17 ) ||
F_162 ( V_87 , V_239 , V_257 -> V_14 . V_15 ) ||
F_162 ( V_87 , V_240 , V_257 -> V_14 . V_16 ) ||
F_163 ( V_87 , V_241 , V_257 -> V_14 . V_119 ) ||
F_163 ( V_87 , V_242 , V_257 -> V_14 . V_140 ) ||
F_163 ( V_87 , V_243 ,
! ! ( V_257 -> V_14 . V_159 & F_80 ( V_211 ) ) ) ||
F_163 ( V_87 , V_237 , V_257 -> V_14 . V_133 ) ||
F_164 ( V_87 , V_244 , V_257 -> V_41 ) )
goto V_258;
#ifdef F_13
if ( F_165 ( V_87 , V_252 ,
& V_98 -> V_30 . V_31 ) ||
F_162 ( V_87 , V_253 ,
V_98 -> V_30 . V_32 ) ||
F_166 ( V_87 , V_254 ,
V_98 -> V_30 . V_33 ) ||
F_166 ( V_87 , V_255 ,
V_98 -> V_30 . V_34 ) )
goto V_258;
#endif
if ( F_166 ( V_87 , V_246 ,
V_98 -> V_259 . type ) ||
F_164 ( V_87 , V_248 ,
V_98 -> V_259 . V_249 ) ||
F_164 ( V_87 , V_250 ,
V_98 -> V_259 . V_251 ) ||
F_166 ( V_87 , V_247 ,
V_98 -> V_259 . V_19 ) )
goto V_258;
return 0 ;
V_258:
return - V_260 ;
}
static void F_167 ( struct V_3 * V_4 , struct V_261 * V_83 )
{
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
if ( V_4 != V_11 -> V_29 )
F_168 ( V_4 , V_83 ) ;
}
static void T_10 F_169 ( struct V_2 * V_2 ,
struct V_261 * V_83 )
{
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
struct V_3 * V_4 , * V_262 ;
int V_24 ;
F_170 (net, dev, aux)
if ( V_4 -> V_45 == & V_46 )
F_168 ( V_4 , V_83 ) ;
for ( V_24 = 1 ; V_24 < 4 ; V_24 ++ ) {
int V_23 ;
for ( V_23 = 0 ; V_23 < V_263 ; V_23 ++ ) {
struct V_1 * V_9 ;
V_9 = F_9 ( V_11 -> V_25 [ V_24 ] [ V_23 ] ) ;
while ( V_9 ) {
if ( ! F_122 ( F_18 ( V_9 -> V_4 ) , V_2 ) )
F_168 ( V_9 -> V_4 ,
V_83 ) ;
V_9 = F_9 ( V_9 -> V_28 ) ;
}
}
}
}
static int T_8 F_171 ( struct V_2 * V_2 )
{
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
struct V_1 * V_9 ;
int V_36 ;
V_11 -> V_25 [ 0 ] = V_11 -> V_21 ;
V_11 -> V_25 [ 1 ] = V_11 -> V_264 ;
V_11 -> V_25 [ 2 ] = V_11 -> V_265 ;
V_11 -> V_25 [ 3 ] = V_11 -> V_266 ;
V_11 -> V_29 = F_23 ( sizeof( struct V_1 ) , L_6 ,
V_53 ,
V_54 ) ;
if ( ! V_11 -> V_29 ) {
V_36 = - V_75 ;
goto V_267;
}
F_24 ( V_11 -> V_29 , V_2 ) ;
V_11 -> V_29 -> V_45 = & V_46 ;
V_11 -> V_29 -> V_230 |= V_268 ;
V_36 = F_172 ( V_11 -> V_29 ) ;
if ( V_36 )
goto V_269;
F_12 ( V_11 -> V_29 , V_11 ) ;
F_144 ( V_11 -> V_29 ) ;
V_9 = F_14 ( V_11 -> V_29 ) ;
strcpy ( V_9 -> V_13 . V_50 , V_11 -> V_29 -> V_50 ) ;
return 0 ;
V_269:
F_25 ( V_11 -> V_29 ) ;
V_267:
return V_36 ;
}
static void T_10 F_173 ( struct V_2 * V_2 )
{
F_174 ( V_270 ) ;
F_175 () ;
F_169 ( V_2 , & V_270 ) ;
F_176 ( & V_270 ) ;
F_177 () ;
}
static void T_11 F_178 ( void )
{
F_179 ( & V_46 ) ;
F_180 ( & V_271 , V_272 ) ;
F_180 ( & V_273 , V_274 ) ;
F_181 ( & V_275 ) ;
F_182 () ;
}
static int T_12 F_183 ( void )
{
int V_36 ;
F_184 ( L_7 ) ;
V_36 = F_185 ( & V_275 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_186 ( & V_271 , V_272 ) ;
if ( V_36 < 0 ) {
F_184 ( L_8 , V_276 ) ;
goto V_277;
}
V_36 = F_186 ( & V_273 , V_274 ) ;
if ( V_36 < 0 ) {
F_184 ( L_9 , V_276 ) ;
goto V_278;
}
V_36 = F_187 ( & V_46 ) ;
if ( V_36 < 0 )
goto V_279;
V_47:
return V_36 ;
V_279:
F_180 ( & V_273 , V_274 ) ;
V_278:
F_180 ( & V_271 , V_272 ) ;
V_277:
F_181 ( & V_275 ) ;
goto V_47;
}
