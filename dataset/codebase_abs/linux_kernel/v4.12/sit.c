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
F_31 ( V_63 , sizeof( * V_62 ) , V_72 | V_73 ) :
NULL ;
F_32 () ;
V_65 = V_9 -> V_74 < V_63 ? V_9 -> V_74 : V_63 ;
if ( ! V_62 ) {
V_62 = F_31 ( V_65 , sizeof( * V_62 ) , V_75 ) ;
if ( ! V_62 ) {
V_67 = - V_76 ;
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
F_37 ( struct V_1 * V_9 , struct V_59 * V_60 , int V_77 )
{
struct V_56 * V_78 ;
int V_36 = 0 ;
if ( V_60 -> V_57 == F_16 ( V_70 ) )
return - V_79 ;
F_38 () ;
for ( V_78 = F_9 ( V_9 -> V_58 ) ; V_78 ; V_78 = F_9 ( V_78 -> V_28 ) ) {
if ( V_78 -> V_57 == V_60 -> V_57 ) {
if ( V_77 ) {
V_78 -> V_19 = V_60 -> V_19 ;
goto V_47;
}
V_36 = - V_80 ;
goto V_47;
}
}
if ( V_77 ) {
V_36 = - V_81 ;
goto V_47;
}
V_78 = F_39 ( sizeof( struct V_56 ) , V_72 ) ;
if ( ! V_78 ) {
V_36 = - V_82 ;
goto V_47;
}
V_78 -> V_28 = V_9 -> V_58 ;
V_78 -> V_57 = V_60 -> V_57 ;
V_78 -> V_19 = V_60 -> V_19 ;
V_9 -> V_74 ++ ;
F_10 ( V_9 -> V_58 , V_78 ) ;
V_47:
return V_36 ;
}
static void F_40 ( struct V_83 * V_84 )
{
struct V_56 * V_78 , * V_85 ;
V_78 = F_41 ( V_84 , struct V_56 , V_83 ) ;
do {
V_85 = F_42 ( V_78 -> V_28 , 1 ) ;
F_36 ( V_78 ) ;
V_78 = V_85 ;
} while ( V_78 );
}
static int
F_43 ( struct V_1 * V_9 , struct V_59 * V_60 )
{
struct V_56 * V_86 ;
struct V_56 T_2 * * V_78 ;
int V_36 = 0 ;
F_38 () ;
if ( V_60 && V_60 -> V_57 != F_16 ( V_70 ) ) {
for ( V_78 = & V_9 -> V_58 ;
( V_86 = F_9 ( * V_78 ) ) != NULL ;
V_78 = & V_86 -> V_28 ) {
if ( V_86 -> V_57 == V_60 -> V_57 ) {
* V_78 = V_86 -> V_28 ;
F_44 ( V_86 , V_83 ) ;
V_9 -> V_74 -- ;
goto V_47;
}
}
V_36 = - V_81 ;
} else {
V_86 = F_9 ( V_9 -> V_58 ) ;
if ( V_86 ) {
V_9 -> V_74 = 0 ;
F_45 ( & V_86 -> V_83 , F_40 ) ;
V_9 -> V_58 = NULL ;
}
}
V_47:
return V_36 ;
}
static int
F_46 ( struct V_87 * V_88 , const struct V_89 * V_14 , struct V_1 * V_9 )
{
struct V_56 * V_78 ;
int V_90 = 1 ;
F_32 () ;
V_78 = F_26 ( V_9 , V_14 -> V_15 ) ;
if ( V_78 ) {
if ( V_78 -> V_19 & V_91 )
V_88 -> V_92 = V_93 ;
else
V_88 -> V_92 = V_94 ;
} else {
const struct V_95 * V_96 = & F_47 ( V_88 ) -> V_15 ;
if ( F_48 ( V_96 ) &&
( V_96 -> V_97 [ 3 ] == V_14 -> V_15 ) &&
F_49 ( V_96 , V_9 -> V_4 ) )
V_88 -> V_92 = V_98 ;
else
V_90 = 0 ;
}
F_33 () ;
return V_90 ;
}
static void F_50 ( struct V_3 * V_4 )
{
struct V_1 * V_99 = F_14 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_99 -> V_2 , V_12 ) ;
if ( V_4 == V_11 -> V_29 ) {
F_51 ( V_11 -> V_21 [ 0 ] , NULL ) ;
} else {
F_8 ( V_11 , V_99 ) ;
F_43 ( V_99 , NULL ) ;
}
F_52 ( & V_99 -> V_100 ) ;
F_53 ( V_4 ) ;
}
static int F_54 ( struct V_87 * V_88 , T_4 V_101 )
{
const struct V_89 * V_14 = ( const struct V_89 * ) V_88 -> V_102 ;
const int type = F_55 ( V_88 ) -> type ;
const int V_103 = F_55 ( V_88 ) -> V_103 ;
unsigned int V_104 = 0 ;
struct V_1 * V_9 ;
int V_36 ;
switch ( type ) {
default:
case V_105 :
return 0 ;
case V_106 :
switch ( V_103 ) {
case V_107 :
return 0 ;
default:
break;
}
break;
case V_108 :
if ( V_103 != V_109 )
return 0 ;
V_104 = F_55 ( V_88 ) -> V_110 . V_111 [ 1 ] * 4 ;
break;
case V_112 :
break;
}
V_36 = - V_113 ;
V_9 = F_1 ( F_18 ( V_88 -> V_4 ) ,
V_88 -> V_4 ,
V_14 -> V_16 ,
V_14 -> V_15 ) ;
if ( ! V_9 )
goto V_47;
if ( type == V_106 && V_103 == V_114 ) {
F_56 ( V_88 , F_18 ( V_88 -> V_4 ) , V_101 ,
V_9 -> V_13 . V_17 , 0 , V_14 -> V_115 , 0 ) ;
V_36 = 0 ;
goto V_47;
}
if ( type == V_112 ) {
F_57 ( V_88 , F_18 ( V_88 -> V_4 ) , V_9 -> V_13 . V_17 , 0 ,
V_14 -> V_115 , 0 ) ;
V_36 = 0 ;
goto V_47;
}
V_36 = 0 ;
if ( ! F_58 ( V_88 , V_14 -> V_116 * 4 , type , V_104 ) )
goto V_47;
if ( V_9 -> V_13 . V_14 . V_16 == 0 )
goto V_47;
if ( V_9 -> V_13 . V_14 . V_117 == 0 && type == V_108 )
goto V_47;
if ( F_59 ( V_118 , V_9 -> V_119 + V_120 ) )
V_9 -> V_121 ++ ;
else
V_9 -> V_121 = 1 ;
V_9 -> V_119 = V_118 ;
V_47:
return V_36 ;
}
static inline bool F_60 ( struct V_1 * V_99 , const T_1 V_122 ,
const struct V_95 * V_123 )
{
T_1 V_124 = 0 ;
if ( F_61 ( V_99 , V_123 , & V_124 ) && V_122 != V_124 )
return true ;
return false ;
}
static bool F_62 ( const struct V_1 * V_99 ,
const struct V_95 * V_125 )
{
int V_126 ;
#ifdef F_13
V_126 = V_99 -> V_30 . V_33 + 32
- V_99 -> V_30 . V_34 ;
#else
V_126 = 48 ;
#endif
return F_63 ( V_125 , V_126 , V_99 -> V_4 ) ;
}
static bool F_64 ( struct V_87 * V_88 ,
const struct V_89 * V_14 ,
struct V_1 * V_99 )
{
const struct V_127 * V_128 ;
if ( V_99 -> V_4 -> V_43 & V_44 ) {
if ( ! F_46 ( V_88 , V_14 , V_99 ) )
return true ;
return false ;
}
if ( V_99 -> V_4 -> V_19 & V_129 )
return false ;
V_128 = F_47 ( V_88 ) ;
if ( F_65 ( F_60 ( V_99 , V_14 -> V_15 , & V_128 -> V_15 ) ) ) {
F_66 ( L_2 ,
& V_14 -> V_15 , & V_128 -> V_15 ,
& V_14 -> V_16 , & V_128 -> V_16 ) ;
return true ;
}
if ( F_67 ( ! F_60 ( V_99 , V_14 -> V_16 , & V_128 -> V_16 ) ) )
return false ;
if ( F_62 ( V_99 , & V_128 -> V_16 ) )
return false ;
F_66 ( L_3 ,
& V_14 -> V_15 , & V_128 -> V_15 ,
& V_14 -> V_16 , & V_128 -> V_16 ) ;
return true ;
}
static int F_68 ( struct V_87 * V_88 )
{
const struct V_89 * V_14 = F_69 ( V_88 ) ;
struct V_1 * V_99 ;
int V_36 ;
V_99 = F_1 ( F_18 ( V_88 -> V_4 ) , V_88 -> V_4 ,
V_14 -> V_15 , V_14 -> V_16 ) ;
if ( V_99 ) {
struct V_130 * V_131 ;
if ( V_99 -> V_13 . V_14 . V_115 != V_132 &&
V_99 -> V_13 . V_14 . V_115 != 0 )
goto V_47;
V_88 -> V_133 = V_88 -> V_134 ;
F_70 ( V_88 ) ;
F_71 ( V_88 ) -> V_19 = 0 ;
V_88 -> V_4 = V_99 -> V_4 ;
if ( F_64 ( V_88 , V_14 , V_99 ) ) {
V_99 -> V_4 -> V_135 . V_136 ++ ;
goto V_47;
}
if ( F_72 ( V_88 , 0 , F_73 ( V_137 ) ,
! F_74 ( V_99 -> V_2 , F_18 ( V_99 -> V_4 ) ) ) )
goto V_47;
V_36 = F_75 ( V_14 , V_88 ) ;
if ( F_65 ( V_36 ) ) {
if ( V_138 )
F_76 ( L_4 ,
& V_14 -> V_15 , V_14 -> V_139 ) ;
if ( V_36 > 1 ) {
++ V_99 -> V_4 -> V_135 . V_140 ;
++ V_99 -> V_4 -> V_135 . V_136 ;
goto V_47;
}
}
V_131 = F_77 ( V_99 -> V_4 -> V_131 ) ;
F_78 ( & V_131 -> V_141 ) ;
V_131 -> V_142 ++ ;
V_131 -> V_143 += V_88 -> V_66 ;
F_79 ( & V_131 -> V_141 ) ;
F_80 ( V_88 ) ;
return 0 ;
}
return 1 ;
V_47:
F_81 ( V_88 ) ;
return 0 ;
}
static int F_82 ( struct V_87 * V_88 , T_5 V_144 )
{
const struct V_89 * V_14 ;
struct V_1 * V_99 ;
V_14 = F_69 ( V_88 ) ;
V_99 = F_1 ( F_18 ( V_88 -> V_4 ) , V_88 -> V_4 ,
V_14 -> V_15 , V_14 -> V_16 ) ;
if ( V_99 ) {
const struct V_145 * V_146 ;
if ( V_99 -> V_13 . V_14 . V_115 != V_144 &&
V_99 -> V_13 . V_14 . V_115 != 0 )
goto V_147;
if ( ! F_83 ( NULL , V_148 , V_88 ) )
goto V_147;
#if F_84 ( V_149 )
if ( V_144 == V_150 )
V_146 = & V_151 ;
else
#endif
V_146 = & V_152 ;
if ( F_72 ( V_88 , 0 , V_146 -> V_153 , false ) )
goto V_147;
return F_85 ( V_99 , V_88 , V_146 , NULL , V_138 ) ;
}
return 1 ;
V_147:
F_81 ( V_88 ) ;
return 0 ;
}
static int F_86 ( struct V_87 * V_88 )
{
return F_82 ( V_88 , V_154 ) ;
}
static int F_87 ( struct V_87 * V_88 )
{
return F_82 ( V_88 , V_150 ) ;
}
static bool F_61 ( struct V_1 * V_99 , const struct V_95 * V_125 ,
T_1 * V_155 )
{
#ifdef F_13
if ( F_88 ( V_125 , & V_99 -> V_30 . V_31 ,
V_99 -> V_30 . V_33 ) ) {
unsigned int V_156 , V_157 ;
int V_158 ;
T_4 V_159 ;
V_156 = V_99 -> V_30 . V_33 >> 5 ;
V_157 = V_99 -> V_30 . V_33 & 0x1f ;
V_159 = ( F_89 ( V_125 -> V_97 [ V_156 ] ) << V_157 ) >>
V_99 -> V_30 . V_34 ;
V_158 = V_157 - V_99 -> V_30 . V_34 ;
if ( V_158 > 0 )
V_159 |= F_89 ( V_125 -> V_97 [ V_156 + 1 ] ) >>
( 32 - V_158 ) ;
* V_155 = V_99 -> V_30 . V_32 | F_16 ( V_159 ) ;
return true ;
}
#else
if ( V_125 -> V_160 [ 0 ] == F_73 ( 0x2002 ) ) {
memcpy ( V_155 , & V_125 -> V_160 [ 1 ] , 4 ) ;
return true ;
}
#endif
return false ;
}
static inline T_1 F_90 ( struct V_1 * V_99 ,
const struct V_95 * V_125 )
{
T_1 V_161 = 0 ;
F_61 ( V_99 , V_125 , & V_161 ) ;
return V_161 ;
}
static T_6 F_91 ( struct V_87 * V_88 ,
struct V_3 * V_4 )
{
struct V_1 * V_99 = F_14 ( V_4 ) ;
const struct V_89 * V_162 = & V_99 -> V_13 . V_14 ;
const struct V_127 * V_163 = F_47 ( V_88 ) ;
T_5 V_139 = V_99 -> V_13 . V_14 . V_139 ;
T_7 V_164 = V_162 -> V_165 ;
struct V_166 * V_167 ;
struct V_3 * V_168 ;
unsigned int V_169 ;
T_1 V_161 = V_162 -> V_16 ;
struct V_170 V_171 ;
int V_172 ;
const struct V_95 * V_96 ;
int V_173 ;
T_5 V_117 ;
T_5 V_115 = V_132 ;
int V_174 = V_99 -> V_175 + sizeof( struct V_89 ) ;
if ( V_139 == 1 )
V_139 = F_92 ( V_163 ) ;
if ( V_4 -> V_43 & V_44 ) {
struct V_176 * V_177 = NULL ;
bool V_178 = false ;
if ( F_93 ( V_88 ) )
V_177 = F_94 ( F_93 ( V_88 ) , & V_163 -> V_16 ) ;
if ( ! V_177 ) {
F_95 ( L_5 ) ;
goto V_179;
}
V_96 = ( const struct V_95 * ) & V_177 -> V_180 ;
V_173 = F_96 ( V_96 ) ;
if ( ( V_173 & V_181 ) &&
F_48 ( V_96 ) )
V_161 = V_96 -> V_97 [ 3 ] ;
else
V_178 = true ;
F_97 ( V_177 ) ;
if ( V_178 )
goto V_179;
}
if ( ! V_161 )
V_161 = F_90 ( V_99 , & V_163 -> V_16 ) ;
if ( ! V_161 ) {
struct V_176 * V_177 = NULL ;
bool V_178 = false ;
if ( F_93 ( V_88 ) )
V_177 = F_94 ( F_93 ( V_88 ) , & V_163 -> V_16 ) ;
if ( ! V_177 ) {
F_95 ( L_5 ) ;
goto V_179;
}
V_96 = ( const struct V_95 * ) & V_177 -> V_180 ;
V_173 = F_96 ( V_96 ) ;
if ( V_173 == V_182 ) {
V_96 = & F_47 ( V_88 ) -> V_16 ;
V_173 = F_96 ( V_96 ) ;
}
if ( ( V_173 & V_183 ) != 0 )
V_161 = V_96 -> V_97 [ 3 ] ;
else
V_178 = true ;
F_97 ( V_177 ) ;
if ( V_178 )
goto V_179;
}
F_98 ( & V_171 , V_99 -> V_13 . V_17 , V_99 -> V_184 ,
F_99 ( V_139 ) , V_185 , V_132 ,
0 , V_161 , V_162 -> V_15 , 0 , 0 ,
F_100 ( V_99 -> V_2 , NULL ) ) ;
V_167 = F_101 ( V_99 -> V_2 , & V_171 , NULL ) ;
if ( F_102 ( V_167 ) ) {
V_4 -> V_135 . V_186 ++ ;
goto V_187;
}
if ( V_167 -> V_188 != V_189 ) {
F_103 ( V_167 ) ;
V_4 -> V_135 . V_186 ++ ;
goto V_187;
}
V_168 = V_167 -> V_161 . V_4 ;
if ( V_168 == V_4 ) {
F_103 ( V_167 ) ;
V_4 -> V_135 . V_190 ++ ;
goto V_179;
}
if ( F_104 ( V_88 , V_191 ) ) {
F_103 ( V_167 ) ;
goto V_179;
}
if ( V_164 ) {
V_172 = F_105 ( & V_167 -> V_161 ) - V_174 ;
if ( V_172 < 68 ) {
V_4 -> V_135 . V_190 ++ ;
F_103 ( V_167 ) ;
goto V_179;
}
if ( V_172 < V_192 ) {
V_172 = V_192 ;
V_164 = 0 ;
}
if ( V_99 -> V_13 . V_14 . V_16 && F_93 ( V_88 ) )
F_93 ( V_88 ) -> V_193 -> V_194 ( F_93 ( V_88 ) , NULL , V_88 , V_172 ) ;
if ( V_88 -> V_66 > V_172 && ! F_106 ( V_88 ) ) {
F_107 ( V_88 , V_195 , 0 , V_172 ) ;
F_103 ( V_167 ) ;
goto V_179;
}
}
if ( V_99 -> V_121 > 0 ) {
if ( F_59 ( V_118 ,
V_99 -> V_119 + V_120 ) ) {
V_99 -> V_121 -- ;
F_108 ( V_88 ) ;
} else
V_99 -> V_121 = 0 ;
}
V_169 = F_109 ( V_168 ) + V_174 ;
if ( F_110 ( V_88 ) < V_169 || F_111 ( V_88 ) ||
( F_112 ( V_88 ) && ! F_113 ( V_88 , 0 ) ) ) {
struct V_87 * V_196 = F_114 ( V_88 , V_169 ) ;
if ( ! V_196 ) {
F_103 ( V_167 ) ;
V_4 -> V_135 . V_197 ++ ;
F_81 ( V_88 ) ;
return V_198 ;
}
if ( V_88 -> V_199 )
F_115 ( V_196 , V_88 -> V_199 ) ;
F_116 ( V_88 ) ;
V_88 = V_196 ;
V_163 = F_47 ( V_88 ) ;
}
V_117 = V_162 -> V_117 ;
if ( V_117 == 0 )
V_117 = V_163 -> V_200 ;
V_139 = F_117 ( V_139 , F_92 ( V_163 ) ) ;
if ( F_118 ( V_88 , V_99 , & V_115 , & V_171 ) < 0 ) {
F_103 ( V_167 ) ;
goto V_179;
}
F_119 ( V_88 , V_132 ) ;
F_120 ( NULL , V_167 , V_88 , V_171 . V_15 , V_171 . V_16 , V_115 , V_139 , V_117 ,
V_164 , ! F_74 ( V_99 -> V_2 , F_18 ( V_4 ) ) ) ;
return V_198 ;
V_187:
F_108 ( V_88 ) ;
V_179:
F_81 ( V_88 ) ;
V_4 -> V_135 . V_201 ++ ;
return V_198 ;
}
static T_6 F_121 ( struct V_87 * V_88 ,
struct V_3 * V_4 , T_5 V_144 )
{
struct V_1 * V_99 = F_14 ( V_4 ) ;
const struct V_89 * V_162 = & V_99 -> V_13 . V_14 ;
if ( F_104 ( V_88 , V_191 ) )
goto V_179;
F_119 ( V_88 , V_144 ) ;
F_122 ( V_88 , V_4 , V_162 , V_144 ) ;
return V_198 ;
V_179:
F_81 ( V_88 ) ;
V_4 -> V_135 . V_201 ++ ;
return V_198 ;
}
static T_6 F_123 ( struct V_87 * V_88 ,
struct V_3 * V_4 )
{
switch ( V_88 -> V_115 ) {
case F_73 ( V_202 ) :
F_121 ( V_88 , V_4 , V_154 ) ;
break;
case F_73 ( V_137 ) :
F_91 ( V_88 , V_4 ) ;
break;
#if F_84 ( V_149 )
case F_73 ( V_203 ) :
F_121 ( V_88 , V_4 , V_150 ) ;
break;
#endif
default:
goto V_204;
}
return V_198 ;
V_204:
V_4 -> V_135 . V_201 ++ ;
F_81 ( V_88 ) ;
return V_198 ;
}
static void F_124 ( struct V_3 * V_4 )
{
struct V_3 * V_168 = NULL ;
struct V_1 * V_99 ;
const struct V_89 * V_14 ;
struct V_170 V_171 ;
V_99 = F_14 ( V_4 ) ;
V_14 = & V_99 -> V_13 . V_14 ;
if ( V_14 -> V_16 ) {
struct V_166 * V_167 = F_125 ( V_99 -> V_2 , & V_171 ,
NULL ,
V_14 -> V_16 , V_14 -> V_15 ,
0 , 0 ,
V_132 ,
F_99 ( V_14 -> V_139 ) ,
V_99 -> V_13 . V_17 ) ;
if ( ! F_102 ( V_167 ) ) {
V_168 = V_167 -> V_161 . V_4 ;
F_103 ( V_167 ) ;
}
V_4 -> V_19 |= V_129 ;
}
if ( ! V_168 && V_99 -> V_13 . V_17 )
V_168 = F_126 ( V_99 -> V_2 , V_99 -> V_13 . V_17 ) ;
if ( V_168 ) {
int V_174 = V_99 -> V_175 + sizeof( struct V_89 ) ;
V_4 -> V_205 = V_168 -> V_205 + sizeof( struct V_89 ) ;
V_4 -> V_172 = V_168 -> V_172 - V_174 ;
if ( V_4 -> V_172 < V_192 )
V_4 -> V_172 = V_192 ;
}
}
static void F_127 ( struct V_1 * V_9 , struct V_22 * V_78 ,
T_8 V_184 )
{
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
F_8 ( V_11 , V_9 ) ;
F_128 () ;
V_9 -> V_13 . V_14 . V_15 = V_78 -> V_14 . V_15 ;
V_9 -> V_13 . V_14 . V_16 = V_78 -> V_14 . V_16 ;
memcpy ( V_9 -> V_4 -> V_37 , & V_78 -> V_14 . V_15 , 4 ) ;
memcpy ( V_9 -> V_4 -> V_38 , & V_78 -> V_14 . V_16 , 4 ) ;
F_11 ( V_11 , V_9 ) ;
V_9 -> V_13 . V_14 . V_117 = V_78 -> V_14 . V_117 ;
V_9 -> V_13 . V_14 . V_139 = V_78 -> V_14 . V_139 ;
if ( V_9 -> V_13 . V_17 != V_78 -> V_17 || V_9 -> V_184 != V_184 ) {
V_9 -> V_13 . V_17 = V_78 -> V_17 ;
V_9 -> V_184 = V_184 ;
F_124 ( V_9 -> V_4 ) ;
}
F_52 ( & V_9 -> V_100 ) ;
F_129 ( V_9 -> V_4 ) ;
}
static int F_130 ( struct V_1 * V_9 ,
struct V_206 * V_30 )
{
struct V_95 V_31 ;
T_1 V_32 ;
if ( V_30 -> V_34 > 32 ||
V_30 -> V_33 + ( 32 - V_30 -> V_34 ) > 64 )
return - V_79 ;
F_131 ( & V_31 , & V_30 -> V_31 , V_30 -> V_33 ) ;
if ( ! F_132 ( & V_31 , & V_30 -> V_31 ) )
return - V_79 ;
if ( V_30 -> V_34 )
V_32 = V_30 -> V_32 &
F_16 ( 0xffffffffUL <<
( 32 - V_30 -> V_34 ) ) ;
else
V_32 = 0 ;
if ( V_32 != V_30 -> V_32 )
return - V_79 ;
V_9 -> V_30 . V_31 = V_31 ;
V_9 -> V_30 . V_32 = V_32 ;
V_9 -> V_30 . V_33 = V_30 -> V_33 ;
V_9 -> V_30 . V_34 = V_30 -> V_34 ;
F_52 ( & V_9 -> V_100 ) ;
F_129 ( V_9 -> V_4 ) ;
return 0 ;
}
static bool F_133 ( T_5 V_144 )
{
return V_144 == V_132 ||
V_144 == V_154 ||
#if F_84 ( V_149 )
V_144 == V_150 ||
#endif
V_144 == 0 ;
}
static int
F_134 ( struct V_3 * V_4 , struct V_207 * V_208 , int V_209 )
{
int V_36 = 0 ;
struct V_22 V_78 ;
struct V_59 V_58 ;
struct V_1 * V_9 = F_14 ( V_4 ) ;
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
#ifdef F_13
struct V_206 V_30 ;
#endif
switch ( V_209 ) {
case V_210 :
#ifdef F_13
case V_211 :
#endif
if ( V_4 == V_11 -> V_29 ) {
if ( F_29 ( & V_78 , V_208 -> V_212 . V_213 , sizeof( V_78 ) ) ) {
V_36 = - V_68 ;
break;
}
V_9 = F_21 ( V_2 , & V_78 , 0 ) ;
if ( ! V_9 )
V_9 = F_14 ( V_4 ) ;
}
V_36 = - V_68 ;
if ( V_209 == V_210 ) {
memcpy ( & V_78 , & V_9 -> V_13 , sizeof( V_78 ) ) ;
if ( F_34 ( V_208 -> V_212 . V_213 , & V_78 ,
sizeof( V_78 ) ) )
goto V_214;
#ifdef F_13
} else {
V_30 . V_31 = V_9 -> V_30 . V_31 ;
V_30 . V_32 = V_9 -> V_30 . V_32 ;
V_30 . V_33 = V_9 -> V_30 . V_33 ;
V_30 . V_34 = V_9 -> V_30 . V_34 ;
if ( F_34 ( V_208 -> V_212 . V_213 , & V_30 ,
sizeof( V_30 ) ) )
goto V_214;
#endif
}
V_36 = 0 ;
break;
case V_215 :
case V_216 :
V_36 = - V_217 ;
if ( ! F_135 ( V_2 -> V_218 , V_71 ) )
goto V_214;
V_36 = - V_68 ;
if ( F_29 ( & V_78 , V_208 -> V_212 . V_213 , sizeof( V_78 ) ) )
goto V_214;
V_36 = - V_79 ;
if ( ! F_133 ( V_78 . V_14 . V_115 ) )
goto V_214;
if ( V_78 . V_14 . V_219 != 4 ||
V_78 . V_14 . V_116 != 5 || ( V_78 . V_14 . V_165 & F_73 ( ~ V_220 ) ) )
goto V_214;
if ( V_78 . V_14 . V_117 )
V_78 . V_14 . V_165 |= F_73 ( V_220 ) ;
V_9 = F_21 ( V_2 , & V_78 , V_209 == V_215 ) ;
if ( V_4 != V_11 -> V_29 && V_209 == V_216 ) {
if ( V_9 ) {
if ( V_9 -> V_4 != V_4 ) {
V_36 = - V_80 ;
break;
}
} else {
if ( ( ( V_4 -> V_19 & V_129 ) && ! V_78 . V_14 . V_16 ) ||
( ! ( V_4 -> V_19 & V_129 ) && V_78 . V_14 . V_16 ) ) {
V_36 = - V_79 ;
break;
}
V_9 = F_14 ( V_4 ) ;
}
F_127 ( V_9 , & V_78 , V_9 -> V_184 ) ;
}
if ( V_9 ) {
V_36 = 0 ;
if ( F_34 ( V_208 -> V_212 . V_213 , & V_9 -> V_13 , sizeof( V_78 ) ) )
V_36 = - V_68 ;
} else
V_36 = ( V_209 == V_215 ? - V_82 : - V_113 ) ;
break;
case V_221 :
V_36 = - V_217 ;
if ( ! F_135 ( V_2 -> V_218 , V_71 ) )
goto V_214;
if ( V_4 == V_11 -> V_29 ) {
V_36 = - V_68 ;
if ( F_29 ( & V_78 , V_208 -> V_212 . V_213 , sizeof( V_78 ) ) )
goto V_214;
V_36 = - V_113 ;
V_9 = F_21 ( V_2 , & V_78 , 0 ) ;
if ( ! V_9 )
goto V_214;
V_36 = - V_217 ;
if ( V_9 == F_14 ( V_11 -> V_29 ) )
goto V_214;
V_4 = V_9 -> V_4 ;
}
F_136 ( V_4 ) ;
V_36 = 0 ;
break;
case V_222 :
V_36 = - V_79 ;
if ( V_4 == V_11 -> V_29 )
goto V_214;
V_36 = F_28 ( V_9 , V_208 -> V_212 . V_213 ) ;
break;
case V_223 :
case V_224 :
case V_225 :
V_36 = - V_217 ;
if ( ! F_135 ( V_2 -> V_218 , V_71 ) )
goto V_214;
V_36 = - V_79 ;
if ( V_4 == V_11 -> V_29 )
goto V_214;
V_36 = - V_68 ;
if ( F_29 ( & V_58 , V_208 -> V_212 . V_213 , sizeof( V_58 ) ) )
goto V_214;
switch ( V_209 ) {
case V_224 :
V_36 = F_43 ( V_9 , & V_58 ) ;
break;
case V_223 :
case V_225 :
V_36 = F_37 ( V_9 , & V_58 , V_209 == V_225 ) ;
break;
}
F_52 ( & V_9 -> V_100 ) ;
F_129 ( V_4 ) ;
break;
#ifdef F_13
case V_226 :
case V_227 :
case V_228 :
V_36 = - V_217 ;
if ( ! F_135 ( V_2 -> V_218 , V_71 ) )
goto V_214;
V_36 = - V_68 ;
if ( F_29 ( & V_30 , V_208 -> V_212 . V_213 ,
sizeof( V_30 ) ) )
goto V_214;
if ( V_209 != V_228 ) {
V_36 = F_130 ( V_9 , & V_30 ) ;
if ( V_36 < 0 )
goto V_214;
} else
F_12 ( V_4 , V_11 ) ;
V_36 = 0 ;
break;
#endif
default:
V_36 = - V_79 ;
}
V_214:
return V_36 ;
}
static void F_137 ( struct V_3 * V_4 )
{
struct V_1 * V_99 = F_14 ( V_4 ) ;
F_138 ( & V_99 -> V_100 ) ;
F_139 ( V_4 -> V_131 ) ;
}
static void V_54 ( struct V_3 * V_4 )
{
struct V_1 * V_99 = F_14 ( V_4 ) ;
int V_174 = V_99 -> V_175 + sizeof( struct V_89 ) ;
V_4 -> V_229 = & V_230 ;
V_4 -> V_231 = true ;
V_4 -> V_232 = F_137 ;
V_4 -> type = V_233 ;
V_4 -> V_205 = V_234 + V_174 ;
V_4 -> V_172 = V_235 - V_174 ;
V_4 -> V_236 = V_192 ;
V_4 -> V_237 = 0xFFF8 - V_174 ;
V_4 -> V_19 = V_238 ;
F_140 ( V_4 ) ;
V_4 -> V_239 = 4 ;
V_4 -> V_240 |= V_241 ;
V_4 -> V_240 |= V_242 ;
V_4 -> V_243 |= V_242 ;
}
static int F_141 ( struct V_3 * V_4 )
{
struct V_1 * V_99 = F_14 ( V_4 ) ;
int V_36 ;
V_99 -> V_4 = V_4 ;
V_99 -> V_2 = F_18 ( V_4 ) ;
strcpy ( V_99 -> V_13 . V_50 , V_4 -> V_50 ) ;
F_124 ( V_4 ) ;
V_4 -> V_131 = F_142 ( struct V_130 ) ;
if ( ! V_4 -> V_131 )
return - V_76 ;
V_36 = F_143 ( & V_99 -> V_100 , V_72 ) ;
if ( V_36 ) {
F_139 ( V_4 -> V_131 ) ;
V_4 -> V_131 = NULL ;
return V_36 ;
}
return 0 ;
}
static void T_9 F_144 ( struct V_3 * V_4 )
{
struct V_1 * V_99 = F_14 ( V_4 ) ;
struct V_89 * V_14 = & V_99 -> V_13 . V_14 ;
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
V_14 -> V_219 = 4 ;
V_14 -> V_115 = V_132 ;
V_14 -> V_116 = 5 ;
V_14 -> V_117 = 64 ;
F_20 ( V_4 ) ;
F_10 ( V_11 -> V_21 [ 0 ] , V_99 ) ;
}
static int F_145 ( struct V_244 * V_245 [] , struct V_244 * V_102 [] )
{
T_5 V_153 ;
if ( ! V_102 || ! V_102 [ V_246 ] )
return 0 ;
V_153 = F_146 ( V_102 [ V_246 ] ) ;
if ( ! F_133 ( V_153 ) )
return - V_79 ;
return 0 ;
}
static void F_147 ( struct V_244 * V_102 [] ,
struct V_22 * V_13 ,
T_8 * V_184 )
{
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_14 . V_219 = 4 ;
V_13 -> V_14 . V_115 = V_132 ;
V_13 -> V_14 . V_116 = 5 ;
V_13 -> V_14 . V_117 = 64 ;
if ( ! V_102 )
return;
if ( V_102 [ V_247 ] )
V_13 -> V_17 = F_148 ( V_102 [ V_247 ] ) ;
if ( V_102 [ V_248 ] )
V_13 -> V_14 . V_15 = F_149 ( V_102 [ V_248 ] ) ;
if ( V_102 [ V_249 ] )
V_13 -> V_14 . V_16 = F_149 ( V_102 [ V_249 ] ) ;
if ( V_102 [ V_250 ] ) {
V_13 -> V_14 . V_117 = F_146 ( V_102 [ V_250 ] ) ;
if ( V_13 -> V_14 . V_117 )
V_13 -> V_14 . V_165 = F_73 ( V_220 ) ;
}
if ( V_102 [ V_251 ] )
V_13 -> V_14 . V_139 = F_146 ( V_102 [ V_251 ] ) ;
if ( ! V_102 [ V_252 ] || F_146 ( V_102 [ V_252 ] ) )
V_13 -> V_14 . V_165 = F_73 ( V_220 ) ;
if ( V_102 [ V_253 ] )
V_13 -> V_41 = F_150 ( V_102 [ V_253 ] ) ;
if ( V_102 [ V_246 ] )
V_13 -> V_14 . V_115 = F_146 ( V_102 [ V_246 ] ) ;
if ( V_102 [ V_254 ] )
* V_184 = F_148 ( V_102 [ V_254 ] ) ;
}
static bool F_151 ( struct V_244 * V_102 [] ,
struct F_118 * V_255 )
{
bool V_67 = false ;
memset ( V_255 , 0 , sizeof( * V_255 ) ) ;
if ( ! V_102 )
return V_67 ;
if ( V_102 [ V_256 ] ) {
V_67 = true ;
V_255 -> type = F_152 ( V_102 [ V_256 ] ) ;
}
if ( V_102 [ V_257 ] ) {
V_67 = true ;
V_255 -> V_19 = F_152 ( V_102 [ V_257 ] ) ;
}
if ( V_102 [ V_258 ] ) {
V_67 = true ;
V_255 -> V_259 = F_150 ( V_102 [ V_258 ] ) ;
}
if ( V_102 [ V_260 ] ) {
V_67 = true ;
V_255 -> V_261 = F_150 ( V_102 [ V_260 ] ) ;
}
return V_67 ;
}
static bool F_153 ( struct V_244 * V_102 [] ,
struct V_206 * V_30 )
{
bool V_67 = false ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
if ( ! V_102 )
return V_67 ;
if ( V_102 [ V_262 ] ) {
V_67 = true ;
V_30 -> V_31 = F_154 ( V_102 [ V_262 ] ) ;
}
if ( V_102 [ V_263 ] ) {
V_67 = true ;
V_30 -> V_32 =
F_149 ( V_102 [ V_263 ] ) ;
}
if ( V_102 [ V_264 ] ) {
V_67 = true ;
V_30 -> V_33 = F_152 ( V_102 [ V_264 ] ) ;
}
if ( V_102 [ V_265 ] ) {
V_67 = true ;
V_30 -> V_34 =
F_152 ( V_102 [ V_265 ] ) ;
}
return V_67 ;
}
static int F_155 ( struct V_2 * V_266 , struct V_3 * V_4 ,
struct V_244 * V_245 [] , struct V_244 * V_102 [] )
{
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_1 * V_49 ;
struct F_118 V_255 ;
#ifdef F_13
struct V_206 V_30 ;
#endif
int V_36 ;
V_49 = F_14 ( V_4 ) ;
if ( F_151 ( V_102 , & V_255 ) ) {
V_36 = F_156 ( V_49 , & V_255 ) ;
if ( V_36 < 0 )
return V_36 ;
}
F_147 ( V_102 , & V_49 -> V_13 , & V_49 -> V_184 ) ;
if ( F_21 ( V_2 , & V_49 -> V_13 , 0 ) )
return - V_80 ;
V_36 = F_17 ( V_4 ) ;
if ( V_36 < 0 )
return V_36 ;
#ifdef F_13
if ( F_153 ( V_102 , & V_30 ) )
V_36 = F_130 ( V_49 , & V_30 ) ;
#endif
return V_36 ;
}
static int F_157 ( struct V_3 * V_4 , struct V_244 * V_245 [] ,
struct V_244 * V_102 [] )
{
struct V_1 * V_9 = F_14 ( V_4 ) ;
struct V_22 V_78 ;
struct F_118 V_255 ;
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
#ifdef F_13
struct V_206 V_30 ;
#endif
T_8 V_184 = V_9 -> V_184 ;
int V_36 ;
if ( V_4 == V_11 -> V_29 )
return - V_79 ;
if ( F_151 ( V_102 , & V_255 ) ) {
V_36 = F_156 ( V_9 , & V_255 ) ;
if ( V_36 < 0 )
return V_36 ;
}
F_147 ( V_102 , & V_78 , & V_184 ) ;
if ( ( ( V_4 -> V_19 & V_129 ) && ! V_78 . V_14 . V_16 ) ||
( ! ( V_4 -> V_19 & V_129 ) && V_78 . V_14 . V_16 ) )
return - V_79 ;
V_9 = F_21 ( V_2 , & V_78 , 0 ) ;
if ( V_9 ) {
if ( V_9 -> V_4 != V_4 )
return - V_80 ;
} else
V_9 = F_14 ( V_4 ) ;
F_127 ( V_9 , & V_78 , V_184 ) ;
#ifdef F_13
if ( F_153 ( V_102 , & V_30 ) )
return F_130 ( V_9 , & V_30 ) ;
#endif
return 0 ;
}
static T_10 F_158 ( const struct V_3 * V_4 )
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
F_159 ( sizeof( struct V_95 ) ) +
F_159 ( 4 ) +
F_159 ( 2 ) +
F_159 ( 2 ) +
#endif
F_159 ( 2 ) +
F_159 ( 2 ) +
F_159 ( 2 ) +
F_159 ( 2 ) +
F_159 ( 4 ) +
0 ;
}
static int F_160 ( struct V_87 * V_88 , const struct V_3 * V_4 )
{
struct V_1 * V_99 = F_14 ( V_4 ) ;
struct V_22 * V_267 = & V_99 -> V_13 ;
if ( F_161 ( V_88 , V_247 , V_267 -> V_17 ) ||
F_162 ( V_88 , V_248 , V_267 -> V_14 . V_15 ) ||
F_162 ( V_88 , V_249 , V_267 -> V_14 . V_16 ) ||
F_163 ( V_88 , V_250 , V_267 -> V_14 . V_117 ) ||
F_163 ( V_88 , V_251 , V_267 -> V_14 . V_139 ) ||
F_163 ( V_88 , V_252 ,
! ! ( V_267 -> V_14 . V_165 & F_73 ( V_220 ) ) ) ||
F_163 ( V_88 , V_246 , V_267 -> V_14 . V_115 ) ||
F_164 ( V_88 , V_253 , V_267 -> V_41 ) ||
F_161 ( V_88 , V_254 , V_99 -> V_184 ) )
goto V_268;
#ifdef F_13
if ( F_165 ( V_88 , V_262 ,
& V_99 -> V_30 . V_31 ) ||
F_162 ( V_88 , V_263 ,
V_99 -> V_30 . V_32 ) ||
F_166 ( V_88 , V_264 ,
V_99 -> V_30 . V_33 ) ||
F_166 ( V_88 , V_265 ,
V_99 -> V_30 . V_34 ) )
goto V_268;
#endif
if ( F_166 ( V_88 , V_256 ,
V_99 -> V_269 . type ) ||
F_164 ( V_88 , V_258 ,
V_99 -> V_269 . V_259 ) ||
F_164 ( V_88 , V_260 ,
V_99 -> V_269 . V_261 ) ||
F_166 ( V_88 , V_257 ,
V_99 -> V_269 . V_19 ) )
goto V_268;
return 0 ;
V_268:
return - V_270 ;
}
static void F_167 ( struct V_3 * V_4 , struct V_271 * V_84 )
{
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
if ( V_4 != V_11 -> V_29 )
F_168 ( V_4 , V_84 ) ;
}
static void T_11 F_169 ( struct V_2 * V_2 ,
struct V_271 * V_84 )
{
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
struct V_3 * V_4 , * V_272 ;
int V_24 ;
F_170 (net, dev, aux)
if ( V_4 -> V_45 == & V_46 )
F_168 ( V_4 , V_84 ) ;
for ( V_24 = 1 ; V_24 < 4 ; V_24 ++ ) {
int V_23 ;
for ( V_23 = 0 ; V_23 < V_273 ; V_23 ++ ) {
struct V_1 * V_9 ;
V_9 = F_9 ( V_11 -> V_25 [ V_24 ] [ V_23 ] ) ;
while ( V_9 ) {
if ( ! F_74 ( F_18 ( V_9 -> V_4 ) , V_2 ) )
F_168 ( V_9 -> V_4 ,
V_84 ) ;
V_9 = F_9 ( V_9 -> V_28 ) ;
}
}
}
}
static int T_9 F_171 ( struct V_2 * V_2 )
{
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
struct V_1 * V_9 ;
int V_36 ;
V_11 -> V_25 [ 0 ] = V_11 -> V_21 ;
V_11 -> V_25 [ 1 ] = V_11 -> V_274 ;
V_11 -> V_25 [ 2 ] = V_11 -> V_275 ;
V_11 -> V_25 [ 3 ] = V_11 -> V_276 ;
V_11 -> V_29 = F_23 ( sizeof( struct V_1 ) , L_6 ,
V_53 ,
V_54 ) ;
if ( ! V_11 -> V_29 ) {
V_36 = - V_76 ;
goto V_277;
}
F_24 ( V_11 -> V_29 , V_2 ) ;
V_11 -> V_29 -> V_45 = & V_46 ;
V_11 -> V_29 -> V_240 |= V_278 ;
V_36 = F_172 ( V_11 -> V_29 ) ;
if ( V_36 )
goto V_279;
F_12 ( V_11 -> V_29 , V_11 ) ;
F_144 ( V_11 -> V_29 ) ;
V_9 = F_14 ( V_11 -> V_29 ) ;
strcpy ( V_9 -> V_13 . V_50 , V_11 -> V_29 -> V_50 ) ;
return 0 ;
V_279:
F_137 ( V_11 -> V_29 ) ;
V_277:
return V_36 ;
}
static void T_11 F_173 ( struct V_2 * V_2 )
{
F_174 ( V_280 ) ;
F_175 () ;
F_169 ( V_2 , & V_280 ) ;
F_176 ( & V_280 ) ;
F_177 () ;
}
static void T_12 F_178 ( void )
{
F_179 ( & V_46 ) ;
F_180 ( & V_281 , V_282 ) ;
F_180 ( & V_283 , V_284 ) ;
#if F_84 ( V_149 )
F_180 ( & V_285 , V_286 ) ;
#endif
F_181 ( & V_287 ) ;
F_182 () ;
}
static int T_13 F_183 ( void )
{
int V_36 ;
F_184 ( L_7 ) ;
V_36 = F_185 ( & V_287 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_186 ( & V_281 , V_282 ) ;
if ( V_36 < 0 ) {
F_184 ( L_8 , V_288 ) ;
goto V_289;
}
V_36 = F_186 ( & V_283 , V_284 ) ;
if ( V_36 < 0 ) {
F_184 ( L_9 , V_288 ) ;
goto V_290;
}
#if F_84 ( V_149 )
V_36 = F_186 ( & V_285 , V_286 ) ;
if ( V_36 < 0 ) {
F_184 ( L_10 , V_288 ) ;
goto V_291;
}
#endif
V_36 = F_187 ( & V_46 ) ;
if ( V_36 < 0 )
goto V_292;
V_47:
return V_36 ;
V_292:
#if F_84 ( V_149 )
F_180 ( & V_285 , V_286 ) ;
V_291:
#endif
F_180 ( & V_283 , V_284 ) ;
V_290:
F_180 ( & V_281 , V_282 ) ;
V_289:
F_181 ( & V_287 ) ;
goto V_47;
}
