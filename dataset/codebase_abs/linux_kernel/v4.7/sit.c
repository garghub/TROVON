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
static int F_54 ( struct V_86 * V_87 )
{
int V_100 = ( ( const struct V_88 * ) V_87 -> V_101 ) -> V_100 * 4 ;
struct V_102 * V_103 ;
struct V_86 * V_104 ;
if ( ! F_55 ( V_87 , V_100 + sizeof( struct V_105 ) + 8 ) )
return 1 ;
V_104 = F_56 ( V_87 , V_74 ) ;
if ( ! V_104 )
return 1 ;
F_57 ( V_104 ) ;
F_58 ( V_104 , V_100 ) ;
F_59 ( V_104 ) ;
V_103 = F_60 ( F_18 ( V_87 -> V_4 ) , & F_47 ( V_104 ) -> V_15 , NULL , 0 , 0 ) ;
if ( V_103 && V_103 -> V_106 . V_4 )
V_104 -> V_4 = V_103 -> V_106 . V_4 ;
F_61 ( V_104 , V_107 , V_108 , 0 ) ;
if ( V_103 )
F_62 ( V_103 ) ;
F_63 ( V_104 ) ;
return 0 ;
}
static int F_64 ( struct V_86 * V_87 , T_4 V_109 )
{
const struct V_88 * V_14 = ( const struct V_88 * ) V_87 -> V_101 ;
const int type = F_65 ( V_87 ) -> type ;
const int V_110 = F_65 ( V_87 ) -> V_110 ;
struct V_1 * V_9 ;
int V_36 ;
switch ( type ) {
default:
case V_111 :
return 0 ;
case V_112 :
switch ( V_110 ) {
case V_113 :
return 0 ;
default:
break;
}
break;
case V_114 :
if ( V_110 != V_115 )
return 0 ;
break;
case V_116 :
break;
}
V_36 = - V_117 ;
V_9 = F_1 ( F_18 ( V_87 -> V_4 ) ,
V_87 -> V_4 ,
V_14 -> V_16 ,
V_14 -> V_15 ) ;
if ( ! V_9 )
goto V_47;
if ( type == V_112 && V_110 == V_118 ) {
F_66 ( V_87 , F_18 ( V_87 -> V_4 ) , V_109 ,
V_9 -> V_13 . V_17 , 0 , V_14 -> V_119 , 0 ) ;
V_36 = 0 ;
goto V_47;
}
if ( type == V_116 ) {
F_67 ( V_87 , F_18 ( V_87 -> V_4 ) , V_9 -> V_13 . V_17 , 0 ,
V_14 -> V_119 , 0 ) ;
V_36 = 0 ;
goto V_47;
}
if ( V_9 -> V_13 . V_14 . V_16 == 0 )
goto V_47;
V_36 = 0 ;
if ( ! F_54 ( V_87 ) )
goto V_47;
if ( V_9 -> V_13 . V_14 . V_120 == 0 && type == V_114 )
goto V_47;
if ( F_68 ( V_121 , V_9 -> V_122 + V_123 ) )
V_9 -> V_124 ++ ;
else
V_9 -> V_124 = 1 ;
V_9 -> V_122 = V_121 ;
V_47:
return V_36 ;
}
static inline bool F_69 ( struct V_1 * V_98 , const T_1 V_125 ,
const struct V_94 * V_126 )
{
T_1 V_127 = 0 ;
if ( F_70 ( V_98 , V_126 , & V_127 ) && V_125 != V_127 )
return true ;
return false ;
}
static bool F_71 ( const struct V_1 * V_98 ,
const struct V_94 * V_128 )
{
int V_129 ;
#ifdef F_13
V_129 = V_98 -> V_30 . V_33 + 32
- V_98 -> V_30 . V_34 ;
#else
V_129 = 48 ;
#endif
return F_72 ( V_128 , V_129 , V_98 -> V_4 ) ;
}
static bool F_73 ( struct V_86 * V_87 ,
const struct V_88 * V_14 ,
struct V_1 * V_98 )
{
const struct V_105 * V_130 ;
if ( V_98 -> V_4 -> V_43 & V_44 ) {
if ( ! F_46 ( V_87 , V_14 , V_98 ) )
return true ;
return false ;
}
if ( V_98 -> V_4 -> V_19 & V_131 )
return false ;
V_130 = F_47 ( V_87 ) ;
if ( F_74 ( F_69 ( V_98 , V_14 -> V_15 , & V_130 -> V_15 ) ) ) {
F_75 ( L_2 ,
& V_14 -> V_15 , & V_130 -> V_15 ,
& V_14 -> V_16 , & V_130 -> V_16 ) ;
return true ;
}
if ( F_76 ( ! F_69 ( V_98 , V_14 -> V_16 , & V_130 -> V_16 ) ) )
return false ;
if ( F_71 ( V_98 , & V_130 -> V_16 ) )
return false ;
F_75 ( L_3 ,
& V_14 -> V_15 , & V_130 -> V_15 ,
& V_14 -> V_16 , & V_130 -> V_16 ) ;
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
struct V_132 * V_133 ;
if ( V_98 -> V_13 . V_14 . V_119 != V_134 &&
V_98 -> V_13 . V_14 . V_119 != 0 )
goto V_47;
V_87 -> V_135 = V_87 -> V_136 ;
F_59 ( V_87 ) ;
F_79 ( V_87 ) -> V_19 = 0 ;
V_87 -> V_4 = V_98 -> V_4 ;
if ( F_73 ( V_87 , V_14 , V_98 ) ) {
V_98 -> V_4 -> V_137 . V_138 ++ ;
goto V_47;
}
if ( F_80 ( V_87 , 0 , F_81 ( V_139 ) ,
! F_82 ( V_98 -> V_2 , F_18 ( V_98 -> V_4 ) ) ) )
goto V_47;
V_36 = F_83 ( V_14 , V_87 ) ;
if ( F_74 ( V_36 ) ) {
if ( V_140 )
F_84 ( L_4 ,
& V_14 -> V_15 , V_14 -> V_141 ) ;
if ( V_36 > 1 ) {
++ V_98 -> V_4 -> V_137 . V_142 ;
++ V_98 -> V_4 -> V_137 . V_138 ;
goto V_47;
}
}
V_133 = F_85 ( V_98 -> V_4 -> V_133 ) ;
F_86 ( & V_133 -> V_143 ) ;
V_133 -> V_144 ++ ;
V_133 -> V_145 += V_87 -> V_66 ;
F_87 ( & V_133 -> V_143 ) ;
F_88 ( V_87 ) ;
return 0 ;
}
return 1 ;
V_47:
F_63 ( V_87 ) ;
return 0 ;
}
static int F_89 ( struct V_86 * V_87 )
{
const struct V_88 * V_14 ;
struct V_1 * V_98 ;
V_14 = F_78 ( V_87 ) ;
V_98 = F_1 ( F_18 ( V_87 -> V_4 ) , V_87 -> V_4 ,
V_14 -> V_15 , V_14 -> V_16 ) ;
if ( V_98 ) {
if ( V_98 -> V_13 . V_14 . V_119 != V_146 &&
V_98 -> V_13 . V_14 . V_119 != 0 )
goto V_147;
if ( ! F_90 ( NULL , V_148 , V_87 ) )
goto V_147;
if ( F_80 ( V_87 , 0 , V_149 . V_150 , false ) )
goto V_147;
return F_91 ( V_98 , V_87 , & V_149 , NULL , V_140 ) ;
}
return 1 ;
V_147:
F_63 ( V_87 ) ;
return 0 ;
}
static bool F_70 ( struct V_1 * V_98 , const struct V_94 * V_128 ,
T_1 * V_151 )
{
#ifdef F_13
if ( F_92 ( V_128 , & V_98 -> V_30 . V_31 ,
V_98 -> V_30 . V_33 ) ) {
unsigned int V_152 , V_153 ;
int V_154 ;
T_4 V_155 ;
V_152 = V_98 -> V_30 . V_33 >> 5 ;
V_153 = V_98 -> V_30 . V_33 & 0x1f ;
V_155 = ( F_93 ( V_128 -> V_96 [ V_152 ] ) << V_153 ) >>
V_98 -> V_30 . V_34 ;
V_154 = V_153 - V_98 -> V_30 . V_34 ;
if ( V_154 > 0 )
V_155 |= F_93 ( V_128 -> V_96 [ V_152 + 1 ] ) >>
( 32 - V_154 ) ;
* V_151 = V_98 -> V_30 . V_32 | F_16 ( V_155 ) ;
return true ;
}
#else
if ( V_128 -> V_156 [ 0 ] == F_81 ( 0x2002 ) ) {
memcpy ( V_151 , & V_128 -> V_156 [ 1 ] , 4 ) ;
return true ;
}
#endif
return false ;
}
static inline T_1 F_94 ( struct V_1 * V_98 ,
const struct V_94 * V_128 )
{
T_1 V_106 = 0 ;
F_70 ( V_98 , V_128 , & V_106 ) ;
return V_106 ;
}
static T_5 F_95 ( struct V_86 * V_87 ,
struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
const struct V_88 * V_157 = & V_98 -> V_13 . V_14 ;
const struct V_105 * V_158 = F_47 ( V_87 ) ;
T_6 V_141 = V_98 -> V_13 . V_14 . V_141 ;
T_7 V_159 = V_157 -> V_160 ;
struct V_161 * V_103 ;
struct V_3 * V_162 ;
unsigned int V_163 ;
T_1 V_106 = V_157 -> V_16 ;
struct V_164 V_165 ;
int V_166 ;
const struct V_94 * V_95 ;
int V_167 ;
T_6 V_120 ;
T_6 V_119 = V_134 ;
int V_168 = V_98 -> V_169 + sizeof( struct V_88 ) ;
if ( V_87 -> V_119 != F_81 ( V_139 ) )
goto V_170;
if ( V_141 == 1 )
V_141 = F_96 ( V_158 ) ;
if ( V_4 -> V_43 & V_44 ) {
struct V_171 * V_172 = NULL ;
bool V_173 = false ;
if ( F_97 ( V_87 ) )
V_172 = F_98 ( F_97 ( V_87 ) , & V_158 -> V_16 ) ;
if ( ! V_172 ) {
F_99 ( L_5 ) ;
goto V_170;
}
V_95 = ( const struct V_94 * ) & V_172 -> V_174 ;
V_167 = F_100 ( V_95 ) ;
if ( ( V_167 & V_175 ) &&
F_48 ( V_95 ) )
V_106 = V_95 -> V_96 [ 3 ] ;
else
V_173 = true ;
F_101 ( V_172 ) ;
if ( V_173 )
goto V_170;
}
if ( ! V_106 )
V_106 = F_94 ( V_98 , & V_158 -> V_16 ) ;
if ( ! V_106 ) {
struct V_171 * V_172 = NULL ;
bool V_173 = false ;
if ( F_97 ( V_87 ) )
V_172 = F_98 ( F_97 ( V_87 ) , & V_158 -> V_16 ) ;
if ( ! V_172 ) {
F_99 ( L_5 ) ;
goto V_170;
}
V_95 = ( const struct V_94 * ) & V_172 -> V_174 ;
V_167 = F_100 ( V_95 ) ;
if ( V_167 == V_176 ) {
V_95 = & F_47 ( V_87 ) -> V_16 ;
V_167 = F_100 ( V_95 ) ;
}
if ( ( V_167 & V_177 ) != 0 )
V_106 = V_95 -> V_96 [ 3 ] ;
else
V_173 = true ;
F_101 ( V_172 ) ;
if ( V_173 )
goto V_170;
}
V_103 = F_102 ( V_98 -> V_2 , & V_165 , NULL ,
V_106 , V_157 -> V_15 ,
0 , 0 ,
V_134 , F_103 ( V_141 ) ,
V_98 -> V_13 . V_17 ) ;
if ( F_104 ( V_103 ) ) {
V_4 -> V_137 . V_178 ++ ;
goto V_179;
}
if ( V_103 -> V_180 != V_181 ) {
F_105 ( V_103 ) ;
V_4 -> V_137 . V_178 ++ ;
goto V_179;
}
V_162 = V_103 -> V_106 . V_4 ;
if ( V_162 == V_4 ) {
F_105 ( V_103 ) ;
V_4 -> V_137 . V_182 ++ ;
goto V_170;
}
if ( F_106 ( V_87 , V_183 ) ) {
F_105 ( V_103 ) ;
goto V_170;
}
if ( V_159 ) {
V_166 = F_107 ( & V_103 -> V_106 ) - V_168 ;
if ( V_166 < 68 ) {
V_4 -> V_137 . V_182 ++ ;
F_105 ( V_103 ) ;
goto V_170;
}
if ( V_166 < V_184 ) {
V_166 = V_184 ;
V_159 = 0 ;
}
if ( V_98 -> V_13 . V_14 . V_16 && F_97 ( V_87 ) )
F_97 ( V_87 ) -> V_185 -> V_186 ( F_97 ( V_87 ) , NULL , V_87 , V_166 ) ;
if ( V_87 -> V_66 > V_166 && ! F_108 ( V_87 ) ) {
F_61 ( V_87 , V_187 , 0 , V_166 ) ;
F_105 ( V_103 ) ;
goto V_170;
}
}
if ( V_98 -> V_124 > 0 ) {
if ( F_68 ( V_121 ,
V_98 -> V_122 + V_123 ) ) {
V_98 -> V_124 -- ;
F_109 ( V_87 ) ;
} else
V_98 -> V_124 = 0 ;
}
V_163 = F_110 ( V_162 ) + V_168 ;
if ( F_111 ( V_87 ) < V_163 || F_112 ( V_87 ) ||
( F_113 ( V_87 ) && ! F_114 ( V_87 , 0 ) ) ) {
struct V_86 * V_188 = F_115 ( V_87 , V_163 ) ;
if ( ! V_188 ) {
F_105 ( V_103 ) ;
V_4 -> V_137 . V_189 ++ ;
F_63 ( V_87 ) ;
return V_190 ;
}
if ( V_87 -> V_191 )
F_116 ( V_188 , V_87 -> V_191 ) ;
F_117 ( V_87 ) ;
V_87 = V_188 ;
V_158 = F_47 ( V_87 ) ;
}
V_120 = V_157 -> V_120 ;
if ( V_120 == 0 )
V_120 = V_158 -> V_192 ;
V_141 = F_118 ( V_141 , F_96 ( V_158 ) ) ;
if ( F_119 ( V_87 , V_98 , & V_119 , & V_165 ) < 0 ) {
F_105 ( V_103 ) ;
goto V_170;
}
F_120 ( V_87 , V_134 ) ;
F_121 ( NULL , V_103 , V_87 , V_165 . V_15 , V_165 . V_16 , V_119 , V_141 , V_120 ,
V_159 , ! F_82 ( V_98 -> V_2 , F_18 ( V_4 ) ) ) ;
return V_190 ;
V_179:
F_109 ( V_87 ) ;
V_170:
F_63 ( V_87 ) ;
V_4 -> V_137 . V_193 ++ ;
return V_190 ;
}
static T_5 F_122 ( struct V_86 * V_87 , struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
const struct V_88 * V_157 = & V_98 -> V_13 . V_14 ;
if ( F_106 ( V_87 , V_183 ) )
goto V_170;
F_120 ( V_87 , V_146 ) ;
F_123 ( V_87 , V_4 , V_157 , V_146 ) ;
return V_190 ;
V_170:
F_63 ( V_87 ) ;
V_4 -> V_137 . V_193 ++ ;
return V_190 ;
}
static T_5 F_124 ( struct V_86 * V_87 ,
struct V_3 * V_4 )
{
switch ( V_87 -> V_119 ) {
case F_81 ( V_194 ) :
F_122 ( V_87 , V_4 ) ;
break;
case F_81 ( V_139 ) :
F_95 ( V_87 , V_4 ) ;
break;
default:
goto V_195;
}
return V_190 ;
V_195:
V_4 -> V_137 . V_193 ++ ;
F_63 ( V_87 ) ;
return V_190 ;
}
static void F_125 ( struct V_3 * V_4 )
{
struct V_3 * V_162 = NULL ;
struct V_1 * V_98 ;
const struct V_88 * V_14 ;
struct V_164 V_165 ;
V_98 = F_14 ( V_4 ) ;
V_14 = & V_98 -> V_13 . V_14 ;
if ( V_14 -> V_16 ) {
struct V_161 * V_103 = F_102 ( V_98 -> V_2 , & V_165 ,
NULL ,
V_14 -> V_16 , V_14 -> V_15 ,
0 , 0 ,
V_134 ,
F_103 ( V_14 -> V_141 ) ,
V_98 -> V_13 . V_17 ) ;
if ( ! F_104 ( V_103 ) ) {
V_162 = V_103 -> V_106 . V_4 ;
F_105 ( V_103 ) ;
}
V_4 -> V_19 |= V_131 ;
}
if ( ! V_162 && V_98 -> V_13 . V_17 )
V_162 = F_126 ( V_98 -> V_2 , V_98 -> V_13 . V_17 ) ;
if ( V_162 ) {
int V_168 = V_98 -> V_169 + sizeof( struct V_88 ) ;
V_4 -> V_196 = V_162 -> V_196 + sizeof( struct V_88 ) ;
V_4 -> V_166 = V_162 -> V_166 - V_168 ;
if ( V_4 -> V_166 < V_184 )
V_4 -> V_166 = V_184 ;
}
}
static void F_127 ( struct V_1 * V_9 , struct V_22 * V_77 )
{
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
F_8 ( V_11 , V_9 ) ;
F_128 () ;
V_9 -> V_13 . V_14 . V_15 = V_77 -> V_14 . V_15 ;
V_9 -> V_13 . V_14 . V_16 = V_77 -> V_14 . V_16 ;
memcpy ( V_9 -> V_4 -> V_37 , & V_77 -> V_14 . V_15 , 4 ) ;
memcpy ( V_9 -> V_4 -> V_38 , & V_77 -> V_14 . V_16 , 4 ) ;
F_11 ( V_11 , V_9 ) ;
V_9 -> V_13 . V_14 . V_120 = V_77 -> V_14 . V_120 ;
V_9 -> V_13 . V_14 . V_141 = V_77 -> V_14 . V_141 ;
if ( V_9 -> V_13 . V_17 != V_77 -> V_17 ) {
V_9 -> V_13 . V_17 = V_77 -> V_17 ;
F_125 ( V_9 -> V_4 ) ;
}
F_52 ( & V_9 -> V_99 ) ;
F_129 ( V_9 -> V_4 ) ;
}
static int F_130 ( struct V_1 * V_9 ,
struct V_197 * V_30 )
{
struct V_94 V_31 ;
T_1 V_32 ;
if ( V_30 -> V_34 > 32 ||
V_30 -> V_33 + ( 32 - V_30 -> V_34 ) > 64 )
return - V_78 ;
F_131 ( & V_31 , & V_30 -> V_31 , V_30 -> V_33 ) ;
if ( ! F_132 ( & V_31 , & V_30 -> V_31 ) )
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
F_129 ( V_9 -> V_4 ) ;
return 0 ;
}
static int
F_133 ( struct V_3 * V_4 , struct V_198 * V_199 , int V_200 )
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
if ( ! F_134 ( V_2 -> V_209 , V_71 ) )
goto V_205;
V_36 = - V_68 ;
if ( F_29 ( & V_77 , V_199 -> V_203 . V_204 , sizeof( V_77 ) ) )
goto V_205;
V_36 = - V_78 ;
if ( V_77 . V_14 . V_119 != V_134 &&
V_77 . V_14 . V_119 != V_146 &&
V_77 . V_14 . V_119 != 0 )
goto V_205;
if ( V_77 . V_14 . V_210 != 4 ||
V_77 . V_14 . V_100 != 5 || ( V_77 . V_14 . V_160 & F_81 ( ~ V_211 ) ) )
goto V_205;
if ( V_77 . V_14 . V_120 )
V_77 . V_14 . V_160 |= F_81 ( V_211 ) ;
V_9 = F_21 ( V_2 , & V_77 , V_200 == V_206 ) ;
if ( V_4 != V_11 -> V_29 && V_200 == V_207 ) {
if ( V_9 ) {
if ( V_9 -> V_4 != V_4 ) {
V_36 = - V_79 ;
break;
}
} else {
if ( ( ( V_4 -> V_19 & V_131 ) && ! V_77 . V_14 . V_16 ) ||
( ! ( V_4 -> V_19 & V_131 ) && V_77 . V_14 . V_16 ) ) {
V_36 = - V_78 ;
break;
}
V_9 = F_14 ( V_4 ) ;
}
F_127 ( V_9 , & V_77 ) ;
}
if ( V_9 ) {
V_36 = 0 ;
if ( F_34 ( V_199 -> V_203 . V_204 , & V_9 -> V_13 , sizeof( V_77 ) ) )
V_36 = - V_68 ;
} else
V_36 = ( V_200 == V_206 ? - V_81 : - V_117 ) ;
break;
case V_212 :
V_36 = - V_208 ;
if ( ! F_134 ( V_2 -> V_209 , V_71 ) )
goto V_205;
if ( V_4 == V_11 -> V_29 ) {
V_36 = - V_68 ;
if ( F_29 ( & V_77 , V_199 -> V_203 . V_204 , sizeof( V_77 ) ) )
goto V_205;
V_36 = - V_117 ;
V_9 = F_21 ( V_2 , & V_77 , 0 ) ;
if ( ! V_9 )
goto V_205;
V_36 = - V_208 ;
if ( V_9 == F_14 ( V_11 -> V_29 ) )
goto V_205;
V_4 = V_9 -> V_4 ;
}
F_135 ( V_4 ) ;
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
if ( ! F_134 ( V_2 -> V_209 , V_71 ) )
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
F_52 ( & V_9 -> V_99 ) ;
F_129 ( V_4 ) ;
break;
#ifdef F_13
case V_217 :
case V_218 :
case V_219 :
V_36 = - V_208 ;
if ( ! F_134 ( V_2 -> V_209 , V_71 ) )
goto V_205;
V_36 = - V_68 ;
if ( F_29 ( & V_30 , V_199 -> V_203 . V_204 ,
sizeof( V_30 ) ) )
goto V_205;
if ( V_200 != V_219 ) {
V_36 = F_130 ( V_9 , & V_30 ) ;
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
static int F_136 ( struct V_3 * V_4 , int V_220 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
int V_168 = V_98 -> V_169 + sizeof( struct V_88 ) ;
if ( V_220 < V_184 || V_220 > 0xFFF8 - V_168 )
return - V_78 ;
V_4 -> V_166 = V_220 ;
return 0 ;
}
static void F_25 ( struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
F_137 ( & V_98 -> V_99 ) ;
F_138 ( V_4 -> V_133 ) ;
F_139 ( V_4 ) ;
}
static void V_54 ( struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
int V_168 = V_98 -> V_169 + sizeof( struct V_88 ) ;
V_4 -> V_221 = & V_222 ;
V_4 -> V_223 = F_25 ;
V_4 -> type = V_224 ;
V_4 -> V_196 = V_225 + V_168 ;
V_4 -> V_166 = V_226 - V_168 ;
V_4 -> V_19 = V_227 ;
F_140 ( V_4 ) ;
V_4 -> V_228 = 4 ;
V_4 -> V_229 |= V_230 ;
V_4 -> V_229 |= V_231 ;
V_4 -> V_232 |= V_231 ;
}
static int F_141 ( struct V_3 * V_4 )
{
struct V_1 * V_98 = F_14 ( V_4 ) ;
int V_36 ;
V_98 -> V_4 = V_4 ;
V_98 -> V_2 = F_18 ( V_4 ) ;
strcpy ( V_98 -> V_13 . V_50 , V_4 -> V_50 ) ;
F_125 ( V_4 ) ;
V_4 -> V_133 = F_142 ( struct V_132 ) ;
if ( ! V_4 -> V_133 )
return - V_75 ;
V_36 = F_143 ( & V_98 -> V_99 , V_72 ) ;
if ( V_36 ) {
F_138 ( V_4 -> V_133 ) ;
return V_36 ;
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
V_14 -> V_119 = V_134 ;
V_14 -> V_100 = 5 ;
V_14 -> V_120 = 64 ;
F_20 ( V_4 ) ;
F_10 ( V_11 -> V_21 [ 0 ] , V_98 ) ;
}
static int F_145 ( struct V_233 * V_234 [] , struct V_233 * V_101 [] )
{
T_6 V_150 ;
if ( ! V_101 || ! V_101 [ V_235 ] )
return 0 ;
V_150 = F_146 ( V_101 [ V_235 ] ) ;
if ( V_150 != V_134 &&
V_150 != V_146 &&
V_150 != 0 )
return - V_78 ;
return 0 ;
}
static void F_147 ( struct V_233 * V_101 [] ,
struct V_22 * V_13 )
{
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_14 . V_210 = 4 ;
V_13 -> V_14 . V_119 = V_134 ;
V_13 -> V_14 . V_100 = 5 ;
V_13 -> V_14 . V_120 = 64 ;
if ( ! V_101 )
return;
if ( V_101 [ V_236 ] )
V_13 -> V_17 = F_148 ( V_101 [ V_236 ] ) ;
if ( V_101 [ V_237 ] )
V_13 -> V_14 . V_15 = F_149 ( V_101 [ V_237 ] ) ;
if ( V_101 [ V_238 ] )
V_13 -> V_14 . V_16 = F_149 ( V_101 [ V_238 ] ) ;
if ( V_101 [ V_239 ] ) {
V_13 -> V_14 . V_120 = F_146 ( V_101 [ V_239 ] ) ;
if ( V_13 -> V_14 . V_120 )
V_13 -> V_14 . V_160 = F_81 ( V_211 ) ;
}
if ( V_101 [ V_240 ] )
V_13 -> V_14 . V_141 = F_146 ( V_101 [ V_240 ] ) ;
if ( ! V_101 [ V_241 ] || F_146 ( V_101 [ V_241 ] ) )
V_13 -> V_14 . V_160 = F_81 ( V_211 ) ;
if ( V_101 [ V_242 ] )
V_13 -> V_41 = F_150 ( V_101 [ V_242 ] ) ;
if ( V_101 [ V_235 ] )
V_13 -> V_14 . V_119 = F_146 ( V_101 [ V_235 ] ) ;
}
static bool F_151 ( struct V_233 * V_101 [] ,
struct F_119 * V_243 )
{
bool V_67 = false ;
memset ( V_243 , 0 , sizeof( * V_243 ) ) ;
if ( ! V_101 )
return V_67 ;
if ( V_101 [ V_244 ] ) {
V_67 = true ;
V_243 -> type = F_152 ( V_101 [ V_244 ] ) ;
}
if ( V_101 [ V_245 ] ) {
V_67 = true ;
V_243 -> V_19 = F_152 ( V_101 [ V_245 ] ) ;
}
if ( V_101 [ V_246 ] ) {
V_67 = true ;
V_243 -> V_247 = F_150 ( V_101 [ V_246 ] ) ;
}
if ( V_101 [ V_248 ] ) {
V_67 = true ;
V_243 -> V_249 = F_150 ( V_101 [ V_248 ] ) ;
}
return V_67 ;
}
static bool F_153 ( struct V_233 * V_101 [] ,
struct V_197 * V_30 )
{
bool V_67 = false ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
if ( ! V_101 )
return V_67 ;
if ( V_101 [ V_250 ] ) {
V_67 = true ;
V_30 -> V_31 = F_154 ( V_101 [ V_250 ] ) ;
}
if ( V_101 [ V_251 ] ) {
V_67 = true ;
V_30 -> V_32 =
F_149 ( V_101 [ V_251 ] ) ;
}
if ( V_101 [ V_252 ] ) {
V_67 = true ;
V_30 -> V_33 = F_152 ( V_101 [ V_252 ] ) ;
}
if ( V_101 [ V_253 ] ) {
V_67 = true ;
V_30 -> V_34 =
F_152 ( V_101 [ V_253 ] ) ;
}
return V_67 ;
}
static int F_155 ( struct V_2 * V_254 , struct V_3 * V_4 ,
struct V_233 * V_234 [] , struct V_233 * V_101 [] )
{
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_1 * V_49 ;
struct F_119 V_243 ;
#ifdef F_13
struct V_197 V_30 ;
#endif
int V_36 ;
V_49 = F_14 ( V_4 ) ;
if ( F_151 ( V_101 , & V_243 ) ) {
V_36 = F_156 ( V_49 , & V_243 ) ;
if ( V_36 < 0 )
return V_36 ;
}
F_147 ( V_101 , & V_49 -> V_13 ) ;
if ( F_21 ( V_2 , & V_49 -> V_13 , 0 ) )
return - V_79 ;
V_36 = F_17 ( V_4 ) ;
if ( V_36 < 0 )
return V_36 ;
#ifdef F_13
if ( F_153 ( V_101 , & V_30 ) )
V_36 = F_130 ( V_49 , & V_30 ) ;
#endif
return V_36 ;
}
static int F_157 ( struct V_3 * V_4 , struct V_233 * V_234 [] ,
struct V_233 * V_101 [] )
{
struct V_1 * V_9 = F_14 ( V_4 ) ;
struct V_22 V_77 ;
struct F_119 V_243 ;
struct V_2 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
#ifdef F_13
struct V_197 V_30 ;
#endif
int V_36 ;
if ( V_4 == V_11 -> V_29 )
return - V_78 ;
if ( F_151 ( V_101 , & V_243 ) ) {
V_36 = F_156 ( V_9 , & V_243 ) ;
if ( V_36 < 0 )
return V_36 ;
}
F_147 ( V_101 , & V_77 ) ;
if ( ( ( V_4 -> V_19 & V_131 ) && ! V_77 . V_14 . V_16 ) ||
( ! ( V_4 -> V_19 & V_131 ) && V_77 . V_14 . V_16 ) )
return - V_78 ;
V_9 = F_21 ( V_2 , & V_77 , 0 ) ;
if ( V_9 ) {
if ( V_9 -> V_4 != V_4 )
return - V_79 ;
} else
V_9 = F_14 ( V_4 ) ;
F_127 ( V_9 , & V_77 ) ;
#ifdef F_13
if ( F_153 ( V_101 , & V_30 ) )
return F_130 ( V_9 , & V_30 ) ;
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
struct V_22 * V_255 = & V_98 -> V_13 ;
if ( F_161 ( V_87 , V_236 , V_255 -> V_17 ) ||
F_162 ( V_87 , V_237 , V_255 -> V_14 . V_15 ) ||
F_162 ( V_87 , V_238 , V_255 -> V_14 . V_16 ) ||
F_163 ( V_87 , V_239 , V_255 -> V_14 . V_120 ) ||
F_163 ( V_87 , V_240 , V_255 -> V_14 . V_141 ) ||
F_163 ( V_87 , V_241 ,
! ! ( V_255 -> V_14 . V_160 & F_81 ( V_211 ) ) ) ||
F_163 ( V_87 , V_235 , V_255 -> V_14 . V_119 ) ||
F_164 ( V_87 , V_242 , V_255 -> V_41 ) )
goto V_256;
#ifdef F_13
if ( F_165 ( V_87 , V_250 ,
& V_98 -> V_30 . V_31 ) ||
F_162 ( V_87 , V_251 ,
V_98 -> V_30 . V_32 ) ||
F_166 ( V_87 , V_252 ,
V_98 -> V_30 . V_33 ) ||
F_166 ( V_87 , V_253 ,
V_98 -> V_30 . V_34 ) )
goto V_256;
#endif
if ( F_166 ( V_87 , V_244 ,
V_98 -> V_257 . type ) ||
F_164 ( V_87 , V_246 ,
V_98 -> V_257 . V_247 ) ||
F_164 ( V_87 , V_248 ,
V_98 -> V_257 . V_249 ) ||
F_166 ( V_87 , V_245 ,
V_98 -> V_257 . V_19 ) )
goto V_256;
return 0 ;
V_256:
return - V_258 ;
}
static void F_167 ( struct V_3 * V_4 , struct V_259 * V_83 )
{
struct V_2 * V_2 = F_18 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
if ( V_4 != V_11 -> V_29 )
F_168 ( V_4 , V_83 ) ;
}
static void T_10 F_169 ( struct V_2 * V_2 ,
struct V_259 * V_83 )
{
struct V_10 * V_11 = F_3 ( V_2 , V_12 ) ;
struct V_3 * V_4 , * V_260 ;
int V_24 ;
F_170 (net, dev, aux)
if ( V_4 -> V_45 == & V_46 )
F_168 ( V_4 , V_83 ) ;
for ( V_24 = 1 ; V_24 < 4 ; V_24 ++ ) {
int V_23 ;
for ( V_23 = 0 ; V_23 < V_261 ; V_23 ++ ) {
struct V_1 * V_9 ;
V_9 = F_9 ( V_11 -> V_25 [ V_24 ] [ V_23 ] ) ;
while ( V_9 ) {
if ( ! F_82 ( F_18 ( V_9 -> V_4 ) , V_2 ) )
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
V_11 -> V_25 [ 1 ] = V_11 -> V_262 ;
V_11 -> V_25 [ 2 ] = V_11 -> V_263 ;
V_11 -> V_25 [ 3 ] = V_11 -> V_264 ;
V_11 -> V_29 = F_23 ( sizeof( struct V_1 ) , L_6 ,
V_53 ,
V_54 ) ;
if ( ! V_11 -> V_29 ) {
V_36 = - V_75 ;
goto V_265;
}
F_24 ( V_11 -> V_29 , V_2 ) ;
V_11 -> V_29 -> V_45 = & V_46 ;
V_11 -> V_29 -> V_229 |= V_266 ;
V_36 = F_172 ( V_11 -> V_29 ) ;
if ( V_36 )
goto V_267;
F_12 ( V_11 -> V_29 , V_11 ) ;
F_144 ( V_11 -> V_29 ) ;
V_9 = F_14 ( V_11 -> V_29 ) ;
strcpy ( V_9 -> V_13 . V_50 , V_11 -> V_29 -> V_50 ) ;
return 0 ;
V_267:
F_25 ( V_11 -> V_29 ) ;
V_265:
return V_36 ;
}
static void T_10 F_173 ( struct V_2 * V_2 )
{
F_174 ( V_268 ) ;
F_175 () ;
F_169 ( V_2 , & V_268 ) ;
F_176 ( & V_268 ) ;
F_177 () ;
}
static void T_11 F_178 ( void )
{
F_179 ( & V_46 ) ;
F_180 ( & V_269 , V_270 ) ;
F_180 ( & V_271 , V_272 ) ;
F_181 ( & V_273 ) ;
F_182 () ;
}
static int T_12 F_183 ( void )
{
int V_36 ;
F_184 ( L_7 ) ;
V_36 = F_185 ( & V_273 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_186 ( & V_269 , V_270 ) ;
if ( V_36 < 0 ) {
F_184 ( L_8 , V_274 ) ;
goto V_275;
}
V_36 = F_186 ( & V_271 , V_272 ) ;
if ( V_36 < 0 ) {
F_184 ( L_9 , V_274 ) ;
goto V_276;
}
V_36 = F_187 ( & V_46 ) ;
if ( V_36 < 0 )
goto V_277;
V_47:
return V_36 ;
V_277:
F_180 ( & V_271 , V_272 ) ;
V_276:
F_180 ( & V_269 , V_270 ) ;
V_275:
F_181 ( & V_273 ) ;
goto V_47;
}
