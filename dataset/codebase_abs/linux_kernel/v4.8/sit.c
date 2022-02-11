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
F_52 ( & V_98 -> V_99 ) ;
F_53 ( V_4 ) ;
}
static int F_54 ( struct V_86 * V_87 , T_4 V_100 )
{
const struct V_88 * V_14 = ( const struct V_88 * ) V_87 -> V_101 ;
const int type = F_55 ( V_87 ) -> type ;
const int V_102 = F_55 ( V_87 ) -> V_102 ;
unsigned int V_103 = 0 ;
struct V_1 * V_9 ;
int V_36 ;
switch ( type ) {
default:
case V_104 :
return 0 ;
case V_105 :
switch ( V_102 ) {
case V_106 :
return 0 ;
default:
break;
}
break;
case V_107 :
if ( V_102 != V_108 )
return 0 ;
V_103 = F_55 ( V_87 ) -> V_109 . V_110 [ 1 ] * 4 ;
break;
case V_111 :
break;
}
V_36 = - V_112 ;
V_9 = F_1 ( F_18 ( V_87 -> V_4 ) ,
V_87 -> V_4 ,
V_14 -> V_16 ,
V_14 -> V_15 ) ;
if ( ! V_9 )
goto V_47;
if ( type == V_105 && V_102 == V_113 ) {
F_56 ( V_87 , F_18 ( V_87 -> V_4 ) , V_100 ,
V_9 -> V_13 . V_17 , 0 , V_14 -> V_114 , 0 ) ;
V_36 = 0 ;
goto V_47;
}
if ( type == V_111 ) {
F_57 ( V_87 , F_18 ( V_87 -> V_4 ) , V_9 -> V_13 . V_17 , 0 ,
V_14 -> V_114 , 0 ) ;
V_36 = 0 ;
goto V_47;
}
V_36 = 0 ;
if ( ! F_58 ( V_87 , V_14 -> V_115 * 4 , type , V_103 ) )
goto V_47;
if ( V_9 -> V_13 . V_14 . V_16 == 0 )
goto V_47;
if ( V_9 -> V_13 . V_14 . V_116 == 0 && type == V_107 )
goto V_47;
if ( F_59 ( V_117 , V_9 -> V_118 + V_119 ) )
V_9 -> V_120 ++ ;
else
V_9 -> V_120 = 1 ;
V_9 -> V_118 = V_117 ;
V_47:
return V_36 ;
}
static inline bool F_60 ( struct V_1 * V_98 , const T_1 V_121 ,
const struct V_94 * V_122 )
{
T_1 V_123 = 0 ;
if ( F_61 ( V_98 , V_122 , & V_123 ) && V_121 != V_123 )
return true ;
return false ;
}
static bool F_62 ( const struct V_1 * V_98 ,
const struct V_94 * V_124 )
{
int V_125 ;
#ifdef F_13
V_125 = V_98 -> V_30 . V_33 + 32
- V_98 -> V_30 . V_34 ;
#else
V_125 = 48 ;
#endif
return F_63 ( V_124 , V_125 , V_98 -> V_4 ) ;
}
static bool F_64 ( struct V_86 * V_87 ,
const struct V_88 * V_14 ,
struct V_1 * V_98 )
{
const struct V_126 * V_127 ;
if ( V_98 -> V_4 -> V_43 & V_44 ) {
if ( ! F_46 ( V_87 , V_14 , V_98 ) )
return true ;
return false ;
}
if ( V_98 -> V_4 -> V_19 & V_128 )
return false ;
V_127 = F_47 ( V_87 ) ;
if ( F_65 ( F_60 ( V_98 , V_14 -> V_15 , & V_127 -> V_15 ) ) ) {
F_66 ( L_2 ,
& V_14 -> V_15 , & V_127 -> V_15 ,
& V_14 -> V_16 , & V_127 -> V_16 ) ;
return true ;
}
if ( F_67 ( ! F_60 ( V_98 , V_14 -> V_16 , & V_127 -> V_16 ) ) )
return false ;
if ( F_62 ( V_98 , & V_127 -> V_16 ) )
return false ;
F_66 ( L_3 ,
& V_14 -> V_15 , & V_127 -> V_15 ,
& V_14 -> V_16 , & V_127 -> V_16 ) ;
return true ;
}
static int F_68 ( struct V_86 * V_87 )
{
const struct V_88 * V_14 = F_69 ( V_87 ) ;
struct V_1 * V_98 ;
int V_36 ;
V_98 = F_1 ( F_18 ( V_87 -> V_4 ) , V_87 -> V_4 ,
V_14 -> V_15 , V_14 -> V_16 ) ;
if ( V_98 ) {
struct V_129 * V_130 ;
if ( V_98 -> V_13 . V_14 . V_114 != V_131 &&
V_98 -> V_13 . V_14 . V_114 != 0 )
goto V_47;
V_87 -> V_132 = V_87 -> V_133 ;
F_70 ( V_87 ) ;
F_71 ( V_87 ) -> V_19 = 0 ;
V_87 -> V_4 = V_98 -> V_4 ;
if ( F_64 ( V_87 , V_14 , V_98 ) ) {
V_98 -> V_4 -> V_134 . V_135 ++ ;
goto V_47;
}
if ( F_72 ( V_87 , 0 , F_73 ( V_136 ) ,
! F_74 ( V_98 -> V_2 , F_18 ( V_98 -> V_4 ) ) ) )
goto V_47;
V_36 = F_75 ( V_14 , V_87 ) ;
if ( F_65 ( V_36 ) ) {
if ( V_137 )
F_76 ( L_4 ,
& V_14 -> V_15 , V_14 -> V_138 ) ;
if ( V_36 > 1 ) {
++ V_98 -> V_4 -> V_134 . V_139 ;
++ V_98 -> V_4 -> V_134 . V_135 ;
goto V_47;
}
}
V_130 = F_77 ( V_98 -> V_4 -> V_130 ) ;
F_78 ( & V_130 -> V_140 ) ;
V_130 -> V_141 ++ ;
V_130 -> V_142 += V_87 -> V_66 ;
F_79 ( & V_130 -> V_140 ) ;
F_80 ( V_87 ) ;
return 0 ;
}
return 1 ;
V_47:
F_81 ( V_87 ) ;
return 0 ;
}
static int F_82 ( struct V_86 * V_87 , T_5 V_143 )
{
const struct V_88 * V_14 ;
struct V_1 * V_98 ;
V_14 = F_69 ( V_87 ) ;
V_98 = F_1 ( F_18 ( V_87 -> V_4 ) , V_87 -> V_4 ,
V_14 -> V_15 , V_14 -> V_16 ) ;
if ( V_98 ) {
const struct V_144 * V_145 ;
if ( V_98 -> V_13 . V_14 . V_114 != V_143 &&
V_98 -> V_13 . V_14 . V_114 != 0 )
goto V_146;
if ( ! F_83 ( NULL , V_147 , V_87 ) )
goto V_146;
#if F_84 ( V_148 )
if ( V_143 == V_149 )
V_145 = & V_150 ;
else
#endif
V_145 = & V_151 ;
if ( F_72 ( V_87 , 0 , V_145 -> V_152 , false ) )
goto V_146;
return F_85 ( V_98 , V_87 , V_145 , NULL , V_137 ) ;
}
return 1 ;
V_146:
F_81 ( V_87 ) ;
return 0 ;
}
static int F_86 ( struct V_86 * V_87 )
{
return F_82 ( V_87 , V_153 ) ;
}
static int F_87 ( struct V_86 * V_87 )
{
return F_82 ( V_87 , V_149 ) ;
}
static bool F_61 ( struct V_1 * V_98 , const struct V_94 * V_124 ,
T_1 * V_154 )
{
#ifdef F_13
if ( F_88 ( V_124 , & V_98 -> V_30 . V_31 ,
V_98 -> V_30 . V_33 ) ) {
unsigned int V_155 , V_156 ;
int V_157 ;
T_4 V_158 ;
V_155 = V_98 -> V_30 . V_33 >> 5 ;
V_156 = V_98 -> V_30 . V_33 & 0x1f ;
V_158 = ( F_89 ( V_124 -> V_96 [ V_155 ] ) << V_156 ) >>
V_98 -> V_30 . V_34 ;
V_157 = V_156 - V_98 -> V_30 . V_34 ;
if ( V_157 > 0 )
V_158 |= F_89 ( V_124 -> V_96 [ V_155 + 1 ] ) >>
( 32 - V_157 ) ;
* V_154 = V_98 -> V_30 . V_32 | F_16 ( V_158 ) ;
return true ;
}
#else
if ( V_124 -> V_159 [ 0 ] == F_73 ( 0x2002 ) ) {
memcpy ( V_154 , & V_124 -> V_159 [ 1 ] , 4 ) ;
return true ;
}
#endif
return false ;
}
static inline T_1 F_90 ( struct V_1 * V_98 ,
const struct V_94 * V_124 )
{
T_1 V_160 = 0 ;
F_61 ( V_98 , V_124 , & V_160 ) ;
return V_160 ;
}
static T_6 F_91 ( struct V_86 * V_87 ,
struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
const struct V_88 * V_161 = & V_98 -> V_13 . V_14 ;
const struct V_126 * V_162 = F_47 ( V_87 ) ;
T_5 V_138 = V_98 -> V_13 . V_14 . V_138 ;
T_7 V_163 = V_161 -> V_164 ;
struct V_165 * V_166 ;
struct V_3 * V_167 ;
unsigned int V_168 ;
T_1 V_160 = V_161 -> V_16 ;
struct V_169 V_170 ;
int V_171 ;
const struct V_94 * V_95 ;
int V_172 ;
T_5 V_116 ;
T_5 V_114 = V_131 ;
int V_173 = V_98 -> V_174 + sizeof( struct V_88 ) ;
if ( V_138 == 1 )
V_138 = F_92 ( V_162 ) ;
if ( V_4 -> V_43 & V_44 ) {
struct V_175 * V_176 = NULL ;
bool V_177 = false ;
if ( F_93 ( V_87 ) )
V_176 = F_94 ( F_93 ( V_87 ) , & V_162 -> V_16 ) ;
if ( ! V_176 ) {
F_95 ( L_5 ) ;
goto V_178;
}
V_95 = ( const struct V_94 * ) & V_176 -> V_179 ;
V_172 = F_96 ( V_95 ) ;
if ( ( V_172 & V_180 ) &&
F_48 ( V_95 ) )
V_160 = V_95 -> V_96 [ 3 ] ;
else
V_177 = true ;
F_97 ( V_176 ) ;
if ( V_177 )
goto V_178;
}
if ( ! V_160 )
V_160 = F_90 ( V_98 , & V_162 -> V_16 ) ;
if ( ! V_160 ) {
struct V_175 * V_176 = NULL ;
bool V_177 = false ;
if ( F_93 ( V_87 ) )
V_176 = F_94 ( F_93 ( V_87 ) , & V_162 -> V_16 ) ;
if ( ! V_176 ) {
F_95 ( L_5 ) ;
goto V_178;
}
V_95 = ( const struct V_94 * ) & V_176 -> V_179 ;
V_172 = F_96 ( V_95 ) ;
if ( V_172 == V_181 ) {
V_95 = & F_47 ( V_87 ) -> V_16 ;
V_172 = F_96 ( V_95 ) ;
}
if ( ( V_172 & V_182 ) != 0 )
V_160 = V_95 -> V_96 [ 3 ] ;
else
V_177 = true ;
F_97 ( V_176 ) ;
if ( V_177 )
goto V_178;
}
V_166 = F_98 ( V_98 -> V_2 , & V_170 , NULL ,
V_160 , V_161 -> V_15 ,
0 , 0 ,
V_131 , F_99 ( V_138 ) ,
V_98 -> V_13 . V_17 ) ;
if ( F_100 ( V_166 ) ) {
V_4 -> V_134 . V_183 ++ ;
goto V_184;
}
if ( V_166 -> V_185 != V_186 ) {
F_101 ( V_166 ) ;
V_4 -> V_134 . V_183 ++ ;
goto V_184;
}
V_167 = V_166 -> V_160 . V_4 ;
if ( V_167 == V_4 ) {
F_101 ( V_166 ) ;
V_4 -> V_134 . V_187 ++ ;
goto V_178;
}
if ( F_102 ( V_87 , V_188 ) ) {
F_101 ( V_166 ) ;
goto V_178;
}
if ( V_163 ) {
V_171 = F_103 ( & V_166 -> V_160 ) - V_173 ;
if ( V_171 < 68 ) {
V_4 -> V_134 . V_187 ++ ;
F_101 ( V_166 ) ;
goto V_178;
}
if ( V_171 < V_189 ) {
V_171 = V_189 ;
V_163 = 0 ;
}
if ( V_98 -> V_13 . V_14 . V_16 && F_93 ( V_87 ) )
F_93 ( V_87 ) -> V_190 -> V_191 ( F_93 ( V_87 ) , NULL , V_87 , V_171 ) ;
if ( V_87 -> V_66 > V_171 && ! F_104 ( V_87 ) ) {
F_105 ( V_87 , V_192 , 0 , V_171 ) ;
F_101 ( V_166 ) ;
goto V_178;
}
}
if ( V_98 -> V_120 > 0 ) {
if ( F_59 ( V_117 ,
V_98 -> V_118 + V_119 ) ) {
V_98 -> V_120 -- ;
F_106 ( V_87 ) ;
} else
V_98 -> V_120 = 0 ;
}
V_168 = F_107 ( V_167 ) + V_173 ;
if ( F_108 ( V_87 ) < V_168 || F_109 ( V_87 ) ||
( F_110 ( V_87 ) && ! F_111 ( V_87 , 0 ) ) ) {
struct V_86 * V_193 = F_112 ( V_87 , V_168 ) ;
if ( ! V_193 ) {
F_101 ( V_166 ) ;
V_4 -> V_134 . V_194 ++ ;
F_81 ( V_87 ) ;
return V_195 ;
}
if ( V_87 -> V_196 )
F_113 ( V_193 , V_87 -> V_196 ) ;
F_114 ( V_87 ) ;
V_87 = V_193 ;
V_162 = F_47 ( V_87 ) ;
}
V_116 = V_161 -> V_116 ;
if ( V_116 == 0 )
V_116 = V_162 -> V_197 ;
V_138 = F_115 ( V_138 , F_92 ( V_162 ) ) ;
if ( F_116 ( V_87 , V_98 , & V_114 , & V_170 ) < 0 ) {
F_101 ( V_166 ) ;
goto V_178;
}
F_117 ( V_87 , V_131 ) ;
F_118 ( NULL , V_166 , V_87 , V_170 . V_15 , V_170 . V_16 , V_114 , V_138 , V_116 ,
V_163 , ! F_74 ( V_98 -> V_2 , F_18 ( V_4 ) ) ) ;
return V_195 ;
V_184:
F_106 ( V_87 ) ;
V_178:
F_81 ( V_87 ) ;
V_4 -> V_134 . V_198 ++ ;
return V_195 ;
}
static T_6 F_119 ( struct V_86 * V_87 ,
struct V_3 * V_4 , T_5 V_143 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
const struct V_88 * V_161 = & V_98 -> V_13 . V_14 ;
if ( F_102 ( V_87 , V_188 ) )
goto V_178;
F_117 ( V_87 , V_143 ) ;
F_120 ( V_87 , V_4 , V_161 , V_143 ) ;
return V_195 ;
V_178:
F_81 ( V_87 ) ;
V_4 -> V_134 . V_198 ++ ;
return V_195 ;
}
static T_6 F_121 ( struct V_86 * V_87 ,
struct V_3 * V_4 )
{
switch ( V_87 -> V_114 ) {
case F_73 ( V_199 ) :
F_119 ( V_87 , V_4 , V_153 ) ;
break;
case F_73 ( V_136 ) :
F_91 ( V_87 , V_4 ) ;
break;
#if F_84 ( V_148 )
case F_73 ( V_200 ) :
F_119 ( V_87 , V_4 , V_149 ) ;
break;
#endif
default:
goto V_201;
}
return V_195 ;
V_201:
V_4 -> V_134 . V_198 ++ ;
F_81 ( V_87 ) ;
return V_195 ;
}
static void F_122 ( struct V_3 * V_4 )
{
struct V_3 * V_167 = NULL ;
struct V_1 * V_98 ;
const struct V_88 * V_14 ;
struct V_169 V_170 ;
V_98 = F_14 ( V_4 ) ;
V_14 = & V_98 -> V_13 . V_14 ;
if ( V_14 -> V_16 ) {
struct V_165 * V_166 = F_98 ( V_98 -> V_2 , & V_170 ,
NULL ,
V_14 -> V_16 , V_14 -> V_15 ,
0 , 0 ,
V_131 ,
F_99 ( V_14 -> V_138 ) ,
V_98 -> V_13 . V_17 ) ;
if ( ! F_100 ( V_166 ) ) {
V_167 = V_166 -> V_160 . V_4 ;
F_101 ( V_166 ) ;
}
V_4 -> V_19 |= V_128 ;
}
if ( ! V_167 && V_98 -> V_13 . V_17 )
V_167 = F_123 ( V_98 -> V_2 , V_98 -> V_13 . V_17 ) ;
if ( V_167 ) {
int V_173 = V_98 -> V_174 + sizeof( struct V_88 ) ;
V_4 -> V_202 = V_167 -> V_202 + sizeof( struct V_88 ) ;
V_4 -> V_171 = V_167 -> V_171 - V_173 ;
if ( V_4 -> V_171 < V_189 )
V_4 -> V_171 = V_189 ;
}
}
static void F_124 ( struct V_1 * V_9 , struct V_22 * V_77 )
{
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
F_8 ( V_11 , V_9 ) ;
F_125 () ;
V_9 -> V_13 . V_14 . V_15 = V_77 -> V_14 . V_15 ;
V_9 -> V_13 . V_14 . V_16 = V_77 -> V_14 . V_16 ;
memcpy ( V_9 -> V_4 -> V_37 , & V_77 -> V_14 . V_15 , 4 ) ;
memcpy ( V_9 -> V_4 -> V_38 , & V_77 -> V_14 . V_16 , 4 ) ;
F_11 ( V_11 , V_9 ) ;
V_9 -> V_13 . V_14 . V_116 = V_77 -> V_14 . V_116 ;
V_9 -> V_13 . V_14 . V_138 = V_77 -> V_14 . V_138 ;
if ( V_9 -> V_13 . V_17 != V_77 -> V_17 ) {
V_9 -> V_13 . V_17 = V_77 -> V_17 ;
F_122 ( V_9 -> V_4 ) ;
}
F_52 ( & V_9 -> V_99 ) ;
F_126 ( V_9 -> V_4 ) ;
}
static int F_127 ( struct V_1 * V_9 ,
struct V_203 * V_30 )
{
struct V_94 V_31 ;
T_1 V_32 ;
if ( V_30 -> V_34 > 32 ||
V_30 -> V_33 + ( 32 - V_30 -> V_34 ) > 64 )
return - V_78 ;
F_128 ( & V_31 , & V_30 -> V_31 , V_30 -> V_33 ) ;
if ( ! F_129 ( & V_31 , & V_30 -> V_31 ) )
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
F_52 ( & V_9 -> V_99 ) ;
F_126 ( V_9 -> V_4 ) ;
return 0 ;
}
bool F_130 ( T_5 V_143 )
{
return V_143 == V_131 ||
V_143 == V_153 ||
#if F_84 ( V_148 )
V_143 == V_149 ||
#endif
V_143 == 0 ;
}
static int
F_131 ( struct V_3 * V_4 , struct V_204 * V_205 , int V_206 )
{
int V_36 = 0 ;
struct V_22 V_77 ;
struct V_59 V_58 ;
struct V_1 * V_9 = F_14 ( V_4 ) ;
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
#ifdef F_13
struct V_203 V_30 ;
#endif
switch ( V_206 ) {
case V_207 :
#ifdef F_13
case V_208 :
#endif
if ( V_4 == V_11 -> V_29 ) {
if ( F_29 ( & V_77 , V_205 -> V_209 . V_210 , sizeof( V_77 ) ) ) {
V_36 = - V_68 ;
break;
}
V_9 = F_21 ( V_2 , & V_77 , 0 ) ;
if ( ! V_9 )
V_9 = F_14 ( V_4 ) ;
}
V_36 = - V_68 ;
if ( V_206 == V_207 ) {
memcpy ( & V_77 , & V_9 -> V_13 , sizeof( V_77 ) ) ;
if ( F_34 ( V_205 -> V_209 . V_210 , & V_77 ,
sizeof( V_77 ) ) )
goto V_211;
#ifdef F_13
} else {
V_30 . V_31 = V_9 -> V_30 . V_31 ;
V_30 . V_32 = V_9 -> V_30 . V_32 ;
V_30 . V_33 = V_9 -> V_30 . V_33 ;
V_30 . V_34 = V_9 -> V_30 . V_34 ;
if ( F_34 ( V_205 -> V_209 . V_210 , & V_30 ,
sizeof( V_30 ) ) )
goto V_211;
#endif
}
V_36 = 0 ;
break;
case V_212 :
case V_213 :
V_36 = - V_214 ;
if ( ! F_132 ( V_2 -> V_215 , V_71 ) )
goto V_211;
V_36 = - V_68 ;
if ( F_29 ( & V_77 , V_205 -> V_209 . V_210 , sizeof( V_77 ) ) )
goto V_211;
V_36 = - V_78 ;
if ( ! F_130 ( V_77 . V_14 . V_114 ) )
goto V_211;
if ( V_77 . V_14 . V_216 != 4 ||
V_77 . V_14 . V_115 != 5 || ( V_77 . V_14 . V_164 & F_73 ( ~ V_217 ) ) )
goto V_211;
if ( V_77 . V_14 . V_116 )
V_77 . V_14 . V_164 |= F_73 ( V_217 ) ;
V_9 = F_21 ( V_2 , & V_77 , V_206 == V_212 ) ;
if ( V_4 != V_11 -> V_29 && V_206 == V_213 ) {
if ( V_9 ) {
if ( V_9 -> V_4 != V_4 ) {
V_36 = - V_79 ;
break;
}
} else {
if ( ( ( V_4 -> V_19 & V_128 ) && ! V_77 . V_14 . V_16 ) ||
( ! ( V_4 -> V_19 & V_128 ) && V_77 . V_14 . V_16 ) ) {
V_36 = - V_78 ;
break;
}
V_9 = F_14 ( V_4 ) ;
}
F_124 ( V_9 , & V_77 ) ;
}
if ( V_9 ) {
V_36 = 0 ;
if ( F_34 ( V_205 -> V_209 . V_210 , & V_9 -> V_13 , sizeof( V_77 ) ) )
V_36 = - V_68 ;
} else
V_36 = ( V_206 == V_212 ? - V_81 : - V_112 ) ;
break;
case V_218 :
V_36 = - V_214 ;
if ( ! F_132 ( V_2 -> V_215 , V_71 ) )
goto V_211;
if ( V_4 == V_11 -> V_29 ) {
V_36 = - V_68 ;
if ( F_29 ( & V_77 , V_205 -> V_209 . V_210 , sizeof( V_77 ) ) )
goto V_211;
V_36 = - V_112 ;
V_9 = F_21 ( V_2 , & V_77 , 0 ) ;
if ( ! V_9 )
goto V_211;
V_36 = - V_214 ;
if ( V_9 == F_14 ( V_11 -> V_29 ) )
goto V_211;
V_4 = V_9 -> V_4 ;
}
F_133 ( V_4 ) ;
V_36 = 0 ;
break;
case V_219 :
V_36 = - V_78 ;
if ( V_4 == V_11 -> V_29 )
goto V_211;
V_36 = F_28 ( V_9 , V_205 -> V_209 . V_210 ) ;
break;
case V_220 :
case V_221 :
case V_222 :
V_36 = - V_214 ;
if ( ! F_132 ( V_2 -> V_215 , V_71 ) )
goto V_211;
V_36 = - V_78 ;
if ( V_4 == V_11 -> V_29 )
goto V_211;
V_36 = - V_68 ;
if ( F_29 ( & V_58 , V_205 -> V_209 . V_210 , sizeof( V_58 ) ) )
goto V_211;
switch ( V_206 ) {
case V_221 :
V_36 = F_43 ( V_9 , & V_58 ) ;
break;
case V_220 :
case V_222 :
V_36 = F_37 ( V_9 , & V_58 , V_206 == V_222 ) ;
break;
}
F_52 ( & V_9 -> V_99 ) ;
F_126 ( V_4 ) ;
break;
#ifdef F_13
case V_223 :
case V_224 :
case V_225 :
V_36 = - V_214 ;
if ( ! F_132 ( V_2 -> V_215 , V_71 ) )
goto V_211;
V_36 = - V_68 ;
if ( F_29 ( & V_30 , V_205 -> V_209 . V_210 ,
sizeof( V_30 ) ) )
goto V_211;
if ( V_206 != V_225 ) {
V_36 = F_127 ( V_9 , & V_30 ) ;
if ( V_36 < 0 )
goto V_211;
} else
F_12 ( V_4 , V_11 ) ;
V_36 = 0 ;
break;
#endif
default:
V_36 = - V_78 ;
}
V_211:
return V_36 ;
}
static int F_134 ( struct V_3 * V_4 , int V_226 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
int V_173 = V_98 -> V_174 + sizeof( struct V_88 ) ;
if ( V_226 < V_189 || V_226 > 0xFFF8 - V_173 )
return - V_78 ;
V_4 -> V_171 = V_226 ;
return 0 ;
}
static void F_25 ( struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
F_135 ( & V_98 -> V_99 ) ;
F_136 ( V_4 -> V_130 ) ;
F_137 ( V_4 ) ;
}
static void V_54 ( struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
int V_173 = V_98 -> V_174 + sizeof( struct V_88 ) ;
V_4 -> V_227 = & V_228 ;
V_4 -> V_229 = F_25 ;
V_4 -> type = V_230 ;
V_4 -> V_202 = V_231 + V_173 ;
V_4 -> V_171 = V_232 - V_173 ;
V_4 -> V_19 = V_233 ;
F_138 ( V_4 ) ;
V_4 -> V_234 = 4 ;
V_4 -> V_235 |= V_236 ;
V_4 -> V_235 |= V_237 ;
V_4 -> V_238 |= V_237 ;
}
static int F_139 ( struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
int V_36 ;
V_98 -> V_4 = V_4 ;
V_98 -> V_2 = F_18 ( V_4 ) ;
strcpy ( V_98 -> V_13 . V_50 , V_4 -> V_50 ) ;
F_122 ( V_4 ) ;
V_4 -> V_130 = F_140 ( struct V_129 ) ;
if ( ! V_4 -> V_130 )
return - V_75 ;
V_36 = F_141 ( & V_98 -> V_99 , V_72 ) ;
if ( V_36 ) {
F_136 ( V_4 -> V_130 ) ;
return V_36 ;
}
return 0 ;
}
static void T_8 F_142 ( struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
struct V_88 * V_14 = & V_98 -> V_13 . V_14 ;
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
V_14 -> V_216 = 4 ;
V_14 -> V_114 = V_131 ;
V_14 -> V_115 = 5 ;
V_14 -> V_116 = 64 ;
F_20 ( V_4 ) ;
F_10 ( V_11 -> V_21 [ 0 ] , V_98 ) ;
}
static int F_143 ( struct V_239 * V_240 [] , struct V_239 * V_101 [] )
{
T_5 V_152 ;
if ( ! V_101 || ! V_101 [ V_241 ] )
return 0 ;
V_152 = F_144 ( V_101 [ V_241 ] ) ;
if ( ! F_130 ( V_152 ) )
return - V_78 ;
return 0 ;
}
static void F_145 ( struct V_239 * V_101 [] ,
struct V_22 * V_13 )
{
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_14 . V_216 = 4 ;
V_13 -> V_14 . V_114 = V_131 ;
V_13 -> V_14 . V_115 = 5 ;
V_13 -> V_14 . V_116 = 64 ;
if ( ! V_101 )
return;
if ( V_101 [ V_242 ] )
V_13 -> V_17 = F_146 ( V_101 [ V_242 ] ) ;
if ( V_101 [ V_243 ] )
V_13 -> V_14 . V_15 = F_147 ( V_101 [ V_243 ] ) ;
if ( V_101 [ V_244 ] )
V_13 -> V_14 . V_16 = F_147 ( V_101 [ V_244 ] ) ;
if ( V_101 [ V_245 ] ) {
V_13 -> V_14 . V_116 = F_144 ( V_101 [ V_245 ] ) ;
if ( V_13 -> V_14 . V_116 )
V_13 -> V_14 . V_164 = F_73 ( V_217 ) ;
}
if ( V_101 [ V_246 ] )
V_13 -> V_14 . V_138 = F_144 ( V_101 [ V_246 ] ) ;
if ( ! V_101 [ V_247 ] || F_144 ( V_101 [ V_247 ] ) )
V_13 -> V_14 . V_164 = F_73 ( V_217 ) ;
if ( V_101 [ V_248 ] )
V_13 -> V_41 = F_148 ( V_101 [ V_248 ] ) ;
if ( V_101 [ V_241 ] )
V_13 -> V_14 . V_114 = F_144 ( V_101 [ V_241 ] ) ;
}
static bool F_149 ( struct V_239 * V_101 [] ,
struct F_116 * V_249 )
{
bool V_67 = false ;
memset ( V_249 , 0 , sizeof( * V_249 ) ) ;
if ( ! V_101 )
return V_67 ;
if ( V_101 [ V_250 ] ) {
V_67 = true ;
V_249 -> type = F_150 ( V_101 [ V_250 ] ) ;
}
if ( V_101 [ V_251 ] ) {
V_67 = true ;
V_249 -> V_19 = F_150 ( V_101 [ V_251 ] ) ;
}
if ( V_101 [ V_252 ] ) {
V_67 = true ;
V_249 -> V_253 = F_148 ( V_101 [ V_252 ] ) ;
}
if ( V_101 [ V_254 ] ) {
V_67 = true ;
V_249 -> V_255 = F_148 ( V_101 [ V_254 ] ) ;
}
return V_67 ;
}
static bool F_151 ( struct V_239 * V_101 [] ,
struct V_203 * V_30 )
{
bool V_67 = false ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
if ( ! V_101 )
return V_67 ;
if ( V_101 [ V_256 ] ) {
V_67 = true ;
V_30 -> V_31 = F_152 ( V_101 [ V_256 ] ) ;
}
if ( V_101 [ V_257 ] ) {
V_67 = true ;
V_30 -> V_32 =
F_147 ( V_101 [ V_257 ] ) ;
}
if ( V_101 [ V_258 ] ) {
V_67 = true ;
V_30 -> V_33 = F_150 ( V_101 [ V_258 ] ) ;
}
if ( V_101 [ V_259 ] ) {
V_67 = true ;
V_30 -> V_34 =
F_150 ( V_101 [ V_259 ] ) ;
}
return V_67 ;
}
static int F_153 ( struct V_2 * V_260 , struct V_3 * V_4 ,
struct V_239 * V_240 [] , struct V_239 * V_101 [] )
{
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_1 * V_49 ;
struct F_116 V_249 ;
#ifdef F_13
struct V_203 V_30 ;
#endif
int V_36 ;
V_49 = F_14 ( V_4 ) ;
if ( F_149 ( V_101 , & V_249 ) ) {
V_36 = F_154 ( V_49 , & V_249 ) ;
if ( V_36 < 0 )
return V_36 ;
}
F_145 ( V_101 , & V_49 -> V_13 ) ;
if ( F_21 ( V_2 , & V_49 -> V_13 , 0 ) )
return - V_79 ;
V_36 = F_17 ( V_4 ) ;
if ( V_36 < 0 )
return V_36 ;
#ifdef F_13
if ( F_151 ( V_101 , & V_30 ) )
V_36 = F_127 ( V_49 , & V_30 ) ;
#endif
return V_36 ;
}
static int F_155 ( struct V_3 * V_4 , struct V_239 * V_240 [] ,
struct V_239 * V_101 [] )
{
struct V_1 * V_9 = F_14 ( V_4 ) ;
struct V_22 V_77 ;
struct F_116 V_249 ;
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
#ifdef F_13
struct V_203 V_30 ;
#endif
int V_36 ;
if ( V_4 == V_11 -> V_29 )
return - V_78 ;
if ( F_149 ( V_101 , & V_249 ) ) {
V_36 = F_154 ( V_9 , & V_249 ) ;
if ( V_36 < 0 )
return V_36 ;
}
F_145 ( V_101 , & V_77 ) ;
if ( ( ( V_4 -> V_19 & V_128 ) && ! V_77 . V_14 . V_16 ) ||
( ! ( V_4 -> V_19 & V_128 ) && V_77 . V_14 . V_16 ) )
return - V_78 ;
V_9 = F_21 ( V_2 , & V_77 , 0 ) ;
if ( V_9 ) {
if ( V_9 -> V_4 != V_4 )
return - V_79 ;
} else
V_9 = F_14 ( V_4 ) ;
F_124 ( V_9 , & V_77 ) ;
#ifdef F_13
if ( F_151 ( V_101 , & V_30 ) )
return F_127 ( V_9 , & V_30 ) ;
#endif
return 0 ;
}
static T_9 F_156 ( const struct V_3 * V_4 )
{
return
F_157 ( 4 ) +
F_157 ( 4 ) +
F_157 ( 4 ) +
F_157 ( 1 ) +
F_157 ( 1 ) +
F_157 ( 1 ) +
F_157 ( 2 ) +
F_157 ( 1 ) +
#ifdef F_13
F_157 ( sizeof( struct V_94 ) ) +
F_157 ( 4 ) +
F_157 ( 2 ) +
F_157 ( 2 ) +
#endif
F_157 ( 2 ) +
F_157 ( 2 ) +
F_157 ( 2 ) +
F_157 ( 2 ) +
0 ;
}
static int F_158 ( struct V_86 * V_87 , const struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
struct V_22 * V_261 = & V_98 -> V_13 ;
if ( F_159 ( V_87 , V_242 , V_261 -> V_17 ) ||
F_160 ( V_87 , V_243 , V_261 -> V_14 . V_15 ) ||
F_160 ( V_87 , V_244 , V_261 -> V_14 . V_16 ) ||
F_161 ( V_87 , V_245 , V_261 -> V_14 . V_116 ) ||
F_161 ( V_87 , V_246 , V_261 -> V_14 . V_138 ) ||
F_161 ( V_87 , V_247 ,
! ! ( V_261 -> V_14 . V_164 & F_73 ( V_217 ) ) ) ||
F_161 ( V_87 , V_241 , V_261 -> V_14 . V_114 ) ||
F_162 ( V_87 , V_248 , V_261 -> V_41 ) )
goto V_262;
#ifdef F_13
if ( F_163 ( V_87 , V_256 ,
& V_98 -> V_30 . V_31 ) ||
F_160 ( V_87 , V_257 ,
V_98 -> V_30 . V_32 ) ||
F_164 ( V_87 , V_258 ,
V_98 -> V_30 . V_33 ) ||
F_164 ( V_87 , V_259 ,
V_98 -> V_30 . V_34 ) )
goto V_262;
#endif
if ( F_164 ( V_87 , V_250 ,
V_98 -> V_263 . type ) ||
F_162 ( V_87 , V_252 ,
V_98 -> V_263 . V_253 ) ||
F_162 ( V_87 , V_254 ,
V_98 -> V_263 . V_255 ) ||
F_164 ( V_87 , V_251 ,
V_98 -> V_263 . V_19 ) )
goto V_262;
return 0 ;
V_262:
return - V_264 ;
}
static void F_165 ( struct V_3 * V_4 , struct V_265 * V_83 )
{
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
if ( V_4 != V_11 -> V_29 )
F_166 ( V_4 , V_83 ) ;
}
static void T_10 F_167 ( struct V_2 * V_2 ,
struct V_265 * V_83 )
{
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
struct V_3 * V_4 , * V_266 ;
int V_24 ;
F_168 (net, dev, aux)
if ( V_4 -> V_45 == & V_46 )
F_166 ( V_4 , V_83 ) ;
for ( V_24 = 1 ; V_24 < 4 ; V_24 ++ ) {
int V_23 ;
for ( V_23 = 0 ; V_23 < V_267 ; V_23 ++ ) {
struct V_1 * V_9 ;
V_9 = F_9 ( V_11 -> V_25 [ V_24 ] [ V_23 ] ) ;
while ( V_9 ) {
if ( ! F_74 ( F_18 ( V_9 -> V_4 ) , V_2 ) )
F_166 ( V_9 -> V_4 ,
V_83 ) ;
V_9 = F_9 ( V_9 -> V_28 ) ;
}
}
}
}
static int T_8 F_169 ( struct V_2 * V_2 )
{
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
struct V_1 * V_9 ;
int V_36 ;
V_11 -> V_25 [ 0 ] = V_11 -> V_21 ;
V_11 -> V_25 [ 1 ] = V_11 -> V_268 ;
V_11 -> V_25 [ 2 ] = V_11 -> V_269 ;
V_11 -> V_25 [ 3 ] = V_11 -> V_270 ;
V_11 -> V_29 = F_23 ( sizeof( struct V_1 ) , L_6 ,
V_53 ,
V_54 ) ;
if ( ! V_11 -> V_29 ) {
V_36 = - V_75 ;
goto V_271;
}
F_24 ( V_11 -> V_29 , V_2 ) ;
V_11 -> V_29 -> V_45 = & V_46 ;
V_11 -> V_29 -> V_235 |= V_272 ;
V_36 = F_170 ( V_11 -> V_29 ) ;
if ( V_36 )
goto V_273;
F_12 ( V_11 -> V_29 , V_11 ) ;
F_142 ( V_11 -> V_29 ) ;
V_9 = F_14 ( V_11 -> V_29 ) ;
strcpy ( V_9 -> V_13 . V_50 , V_11 -> V_29 -> V_50 ) ;
return 0 ;
V_273:
F_25 ( V_11 -> V_29 ) ;
V_271:
return V_36 ;
}
static void T_10 F_171 ( struct V_2 * V_2 )
{
F_172 ( V_274 ) ;
F_173 () ;
F_167 ( V_2 , & V_274 ) ;
F_174 ( & V_274 ) ;
F_175 () ;
}
static void T_11 F_176 ( void )
{
F_177 ( & V_46 ) ;
F_178 ( & V_275 , V_276 ) ;
F_178 ( & V_277 , V_278 ) ;
#if F_84 ( V_148 )
F_178 ( & V_279 , V_280 ) ;
#endif
F_179 ( & V_281 ) ;
F_180 () ;
}
static int T_12 F_181 ( void )
{
int V_36 ;
F_182 ( L_7 ) ;
V_36 = F_183 ( & V_281 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_184 ( & V_275 , V_276 ) ;
if ( V_36 < 0 ) {
F_182 ( L_8 , V_282 ) ;
goto V_283;
}
V_36 = F_184 ( & V_277 , V_278 ) ;
if ( V_36 < 0 ) {
F_182 ( L_9 , V_282 ) ;
goto V_284;
}
#if F_84 ( V_148 )
V_36 = F_184 ( & V_279 , V_280 ) ;
if ( V_36 < 0 ) {
F_182 ( L_10 , V_282 ) ;
goto V_285;
}
#endif
V_36 = F_185 ( & V_46 ) ;
if ( V_36 < 0 )
goto V_286;
V_47:
return V_36 ;
V_286:
#if F_84 ( V_148 )
F_178 ( & V_279 , V_280 ) ;
V_285:
#endif
F_178 ( & V_277 , V_278 ) ;
V_284:
F_178 ( & V_275 , V_276 ) ;
V_283:
F_179 ( & V_281 ) ;
goto V_47;
}
