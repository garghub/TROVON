static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
int V_5 ;
F_2 (i) {
const struct V_6 * V_7 = F_3 ( V_3 -> V_7 , V_5 ) ;
T_1 V_8 , V_9 , V_10 , V_11 ;
unsigned int V_12 ;
do {
V_12 = F_4 ( & V_7 -> V_13 ) ;
V_8 = V_7 -> V_8 ;
V_10 = V_7 -> V_10 ;
V_9 = V_7 -> V_9 ;
V_11 = V_7 -> V_11 ;
} while ( F_5 ( & V_7 -> V_13 , V_12 ) );
V_4 -> V_8 += V_8 ;
V_4 -> V_10 += V_10 ;
V_4 -> V_9 += V_9 ;
V_4 -> V_11 += V_11 ;
}
V_4 -> V_14 = V_3 -> V_15 . V_14 ;
V_4 -> V_16 = V_3 -> V_15 . V_16 ;
V_4 -> V_17 = V_3 -> V_15 . V_17 ;
V_4 -> V_18 = V_3 -> V_15 . V_18 ;
V_4 -> V_19 = V_3 -> V_15 . V_19 ;
V_4 -> V_20 = V_3 -> V_15 . V_20 ;
return V_4 ;
}
static struct V_21 * F_6 ( struct V_22 * V_22 ,
struct V_2 * V_3 , T_2 V_23 , T_2 V_24 )
{
unsigned int V_25 = F_7 ( V_23 ) ;
unsigned int V_26 = F_7 ( V_24 ) ;
struct V_21 * V_27 ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
F_9 (sitn->tunnels_r_l[h0 ^ h1]) {
if ( V_24 == V_27 -> V_31 . V_32 . V_33 &&
V_23 == V_27 -> V_31 . V_32 . V_34 &&
( ! V_3 || ! V_27 -> V_31 . V_35 || V_3 -> V_36 == V_27 -> V_31 . V_35 ) &&
( V_27 -> V_3 -> V_37 & V_38 ) )
return V_27 ;
}
F_9 (sitn->tunnels_r[h0]) {
if ( V_23 == V_27 -> V_31 . V_32 . V_34 &&
( ! V_3 || ! V_27 -> V_31 . V_35 || V_3 -> V_36 == V_27 -> V_31 . V_35 ) &&
( V_27 -> V_3 -> V_37 & V_38 ) )
return V_27 ;
}
F_9 (sitn->tunnels_l[h1]) {
if ( V_24 == V_27 -> V_31 . V_32 . V_33 &&
( ! V_3 || ! V_27 -> V_31 . V_35 || V_3 -> V_36 == V_27 -> V_31 . V_35 ) &&
( V_27 -> V_3 -> V_37 & V_38 ) )
return V_27 ;
}
V_27 = F_10 ( V_29 -> V_39 [ 0 ] ) ;
if ( ( V_27 != NULL ) && ( V_27 -> V_3 -> V_37 & V_38 ) )
return V_27 ;
return NULL ;
}
static struct V_21 T_3 * * F_11 ( struct V_28 * V_29 ,
struct V_40 * V_31 )
{
T_2 V_23 = V_31 -> V_32 . V_34 ;
T_2 V_24 = V_31 -> V_32 . V_33 ;
unsigned int V_41 = 0 ;
int V_42 = 0 ;
if ( V_23 ) {
V_42 |= 2 ;
V_41 ^= F_7 ( V_23 ) ;
}
if ( V_24 ) {
V_42 |= 1 ;
V_41 ^= F_7 ( V_24 ) ;
}
return & V_29 -> V_43 [ V_42 ] [ V_41 ] ;
}
static inline struct V_21 T_3 * * F_12 ( struct V_28 * V_29 ,
struct V_21 * V_27 )
{
return F_11 ( V_29 , & V_27 -> V_31 ) ;
}
static void F_13 ( struct V_28 * V_29 , struct V_21 * V_27 )
{
struct V_21 T_3 * * V_44 ;
struct V_21 * V_45 ;
for ( V_44 = F_12 ( V_29 , V_27 ) ;
( V_45 = F_14 ( * V_44 ) ) != NULL ;
V_44 = & V_45 -> V_46 ) {
if ( V_27 == V_45 ) {
F_15 ( * V_44 , V_27 -> V_46 ) ;
break;
}
}
}
static void F_16 ( struct V_28 * V_29 , struct V_21 * V_27 )
{
struct V_21 T_3 * * V_44 = F_12 ( V_29 , V_27 ) ;
F_15 ( V_27 -> V_46 , F_14 ( * V_44 ) ) ;
F_15 ( * V_44 , V_27 ) ;
}
static void F_17 ( struct V_2 * V_3 , struct V_28 * V_29 )
{
#ifdef F_18
struct V_21 * V_27 = F_19 ( V_3 ) ;
if ( V_27 -> V_3 == V_29 -> V_47 ) {
F_20 ( & V_27 -> V_48 . V_49 , F_21 ( 0x20020000 ) , 0 , 0 , 0 ) ;
V_27 -> V_48 . V_50 = 0 ;
V_27 -> V_48 . V_51 = 16 ;
V_27 -> V_48 . V_52 = 0 ;
} else {
struct V_21 * V_53 = F_19 ( V_29 -> V_47 ) ;
memcpy ( & V_27 -> V_48 , & V_53 -> V_48 , sizeof( V_27 -> V_48 ) ) ;
}
#endif
}
static struct V_21 * F_22 ( struct V_22 * V_22 ,
struct V_40 * V_31 , int V_54 )
{
T_2 V_23 = V_31 -> V_32 . V_34 ;
T_2 V_24 = V_31 -> V_32 . V_33 ;
struct V_21 * V_27 , * V_55 ;
struct V_21 T_3 * * V_44 ;
struct V_2 * V_3 ;
char V_56 [ V_57 ] ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
for ( V_44 = F_11 ( V_29 , V_31 ) ;
( V_27 = F_14 ( * V_44 ) ) != NULL ;
V_44 = & V_27 -> V_46 ) {
if ( V_24 == V_27 -> V_31 . V_32 . V_33 &&
V_23 == V_27 -> V_31 . V_32 . V_34 &&
V_31 -> V_35 == V_27 -> V_31 . V_35 ) {
if ( V_54 )
return NULL ;
else
return V_27 ;
}
}
if ( ! V_54 )
goto V_58;
if ( V_31 -> V_56 [ 0 ] )
F_23 ( V_56 , V_31 -> V_56 , V_57 ) ;
else
strcpy ( V_56 , L_1 ) ;
V_3 = F_24 ( sizeof( * V_27 ) , V_56 , V_59 ) ;
if ( V_3 == NULL )
return NULL ;
F_25 ( V_3 , V_22 ) ;
V_55 = F_19 ( V_3 ) ;
V_55 -> V_31 = * V_31 ;
if ( F_26 ( V_3 ) < 0 )
goto V_60;
F_17 ( V_3 , V_29 ) ;
if ( V_31 -> V_61 & V_62 )
V_3 -> V_63 |= V_64 ;
if ( F_27 ( V_3 ) < 0 )
goto V_60;
strcpy ( V_55 -> V_31 . V_56 , V_3 -> V_56 ) ;
F_28 ( V_3 ) ;
F_16 ( V_29 , V_55 ) ;
return V_55 ;
V_60:
F_29 ( V_3 ) ;
V_58:
return NULL ;
}
static struct V_65 *
F_30 ( struct V_21 * V_27 , T_2 V_66 )
{
struct V_65 * V_67 ;
F_31 (t->prl)
if ( V_67 -> V_66 == V_66 )
break;
return V_67 ;
}
static int F_32 ( struct V_21 * V_27 ,
struct V_68 T_4 * V_69 )
{
struct V_68 V_70 , * V_71 ;
struct V_65 * V_67 ;
unsigned int V_72 , V_73 = 0 , V_74 , V_75 ;
int V_76 = 0 ;
if ( F_33 ( & V_70 , V_69 , sizeof( V_70 ) ) )
return - V_77 ;
V_72 = V_70 . V_78 / sizeof( V_70 ) ;
if ( V_72 > 1 && V_70 . V_66 != F_21 ( V_79 ) )
V_72 = 1 ;
V_71 = ( V_72 <= 1 || F_34 ( V_80 ) ) ?
F_35 ( V_72 , sizeof( * V_71 ) , V_81 ) :
NULL ;
F_36 () ;
V_74 = V_27 -> V_82 < V_72 ? V_27 -> V_82 : V_72 ;
if ( ! V_71 ) {
V_71 = F_35 ( V_74 , sizeof( * V_71 ) , V_83 ) ;
if ( ! V_71 ) {
V_76 = - V_84 ;
goto V_85;
}
}
V_73 = 0 ;
F_31 (t->prl) {
if ( V_73 >= V_72 )
break;
if ( V_70 . V_66 != F_21 ( V_79 ) && V_67 -> V_66 != V_70 . V_66 )
continue;
V_71 [ V_73 ] . V_66 = V_67 -> V_66 ;
V_71 [ V_73 ] . V_37 = V_67 -> V_37 ;
V_73 ++ ;
if ( V_70 . V_66 != F_21 ( V_79 ) )
break;
}
V_85:
F_37 () ;
V_75 = sizeof( * V_71 ) * V_73 ;
V_76 = 0 ;
if ( ( V_75 && F_38 ( V_69 + 1 , V_71 , V_75 ) ) || F_39 ( V_75 , & V_69 -> V_78 ) )
V_76 = - V_77 ;
F_40 ( V_71 ) ;
return V_76 ;
}
static int
F_41 ( struct V_21 * V_27 , struct V_68 * V_69 , int V_86 )
{
struct V_65 * V_87 ;
int V_88 = 0 ;
if ( V_69 -> V_66 == F_21 ( V_79 ) )
return - V_89 ;
F_42 () ;
for ( V_87 = F_14 ( V_27 -> V_67 ) ; V_87 ; V_87 = F_14 ( V_87 -> V_46 ) ) {
if ( V_87 -> V_66 == V_69 -> V_66 ) {
if ( V_86 ) {
V_87 -> V_37 = V_69 -> V_37 ;
goto V_85;
}
V_88 = - V_90 ;
goto V_85;
}
}
if ( V_86 ) {
V_88 = - V_91 ;
goto V_85;
}
V_87 = F_43 ( sizeof( struct V_65 ) , V_81 ) ;
if ( ! V_87 ) {
V_88 = - V_92 ;
goto V_85;
}
V_87 -> V_46 = V_27 -> V_67 ;
V_87 -> V_66 = V_69 -> V_66 ;
V_87 -> V_37 = V_69 -> V_37 ;
V_27 -> V_82 ++ ;
F_15 ( V_27 -> V_67 , V_87 ) ;
V_85:
return V_88 ;
}
static void F_44 ( struct V_93 * V_94 )
{
struct V_65 * V_87 , * V_95 ;
V_87 = F_45 ( V_94 , struct V_65 , V_93 ) ;
do {
V_95 = F_46 ( V_87 -> V_46 , 1 ) ;
F_40 ( V_87 ) ;
V_87 = V_95 ;
} while ( V_87 );
}
static int
F_47 ( struct V_21 * V_27 , struct V_68 * V_69 )
{
struct V_65 * V_96 ;
struct V_65 T_3 * * V_87 ;
int V_88 = 0 ;
F_42 () ;
if ( V_69 && V_69 -> V_66 != F_21 ( V_79 ) ) {
for ( V_87 = & V_27 -> V_67 ;
( V_96 = F_14 ( * V_87 ) ) != NULL ;
V_87 = & V_96 -> V_46 ) {
if ( V_96 -> V_66 == V_69 -> V_66 ) {
* V_87 = V_96 -> V_46 ;
F_48 ( V_96 , V_93 ) ;
V_27 -> V_82 -- ;
goto V_85;
}
}
V_88 = - V_91 ;
} else {
V_96 = F_14 ( V_27 -> V_67 ) ;
if ( V_96 ) {
V_27 -> V_82 = 0 ;
F_49 ( & V_96 -> V_93 , F_44 ) ;
V_27 -> V_67 = NULL ;
}
}
V_85:
return V_88 ;
}
static int
F_50 ( struct V_97 * V_98 , const struct V_99 * V_32 , struct V_21 * V_27 )
{
struct V_65 * V_87 ;
int V_100 = 1 ;
F_36 () ;
V_87 = F_30 ( V_27 , V_32 -> V_33 ) ;
if ( V_87 ) {
if ( V_87 -> V_37 & V_101 )
V_98 -> V_102 = V_103 ;
else
V_98 -> V_102 = V_104 ;
} else {
const struct V_105 * V_106 = & F_51 ( V_98 ) -> V_33 ;
if ( F_52 ( V_106 ) &&
( V_106 -> V_107 [ 3 ] == V_32 -> V_33 ) &&
F_53 ( V_106 , V_27 -> V_3 ) )
V_98 -> V_102 = V_108 ;
else
V_100 = 0 ;
}
F_37 () ;
return V_100 ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_22 * V_22 = F_55 ( V_3 ) ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
if ( V_3 == V_29 -> V_47 ) {
F_56 ( V_29 -> V_39 [ 0 ] , NULL ) ;
} else {
F_13 ( V_29 , F_19 ( V_3 ) ) ;
F_47 ( F_19 ( V_3 ) , NULL ) ;
}
F_57 ( V_3 ) ;
}
static int F_58 ( struct V_97 * V_98 , T_5 V_109 )
{
const struct V_99 * V_32 = ( const struct V_99 * ) V_98 -> V_110 ;
const int type = F_59 ( V_98 ) -> type ;
const int V_111 = F_59 ( V_98 ) -> V_111 ;
struct V_21 * V_27 ;
int V_88 ;
switch ( type ) {
default:
case V_112 :
return 0 ;
case V_113 :
switch ( V_111 ) {
case V_114 :
case V_115 :
return 0 ;
case V_116 :
return 0 ;
default:
break;
}
break;
case V_117 :
if ( V_111 != V_118 )
return 0 ;
break;
}
V_88 = - V_119 ;
F_36 () ;
V_27 = F_6 ( F_55 ( V_98 -> V_3 ) ,
V_98 -> V_3 ,
V_32 -> V_34 ,
V_32 -> V_33 ) ;
if ( V_27 == NULL || V_27 -> V_31 . V_32 . V_34 == 0 )
goto V_85;
V_88 = 0 ;
if ( V_27 -> V_31 . V_32 . V_120 == 0 && type == V_117 )
goto V_85;
if ( F_60 ( V_121 , V_27 -> V_122 + V_123 ) )
V_27 -> V_124 ++ ;
else
V_27 -> V_124 = 1 ;
V_27 -> V_122 = V_121 ;
V_85:
F_37 () ;
return V_88 ;
}
static inline void F_61 ( const struct V_99 * V_32 , struct V_97 * V_98 )
{
if ( F_62 ( V_32 -> V_125 ) )
F_63 ( F_51 ( V_98 ) ) ;
}
static int F_64 ( struct V_97 * V_98 )
{
const struct V_99 * V_32 ;
struct V_21 * V_126 ;
if ( ! F_65 ( V_98 , sizeof( struct V_127 ) ) )
goto V_85;
V_32 = F_66 ( V_98 ) ;
F_36 () ;
V_126 = F_6 ( F_55 ( V_98 -> V_3 ) , V_98 -> V_3 ,
V_32 -> V_33 , V_32 -> V_34 ) ;
if ( V_126 != NULL ) {
struct V_6 * V_7 ;
F_67 ( V_98 ) ;
V_98 -> V_128 = V_98 -> V_129 ;
F_68 ( V_98 ) ;
F_69 ( V_98 ) -> V_37 = 0 ;
V_98 -> V_130 = F_70 ( V_131 ) ;
V_98 -> V_132 = V_133 ;
if ( ( V_126 -> V_3 -> V_63 & V_64 ) &&
! F_50 ( V_98 , V_32 , V_126 ) ) {
V_126 -> V_3 -> V_15 . V_14 ++ ;
F_37 () ;
F_71 ( V_98 ) ;
return 0 ;
}
V_7 = F_72 ( V_126 -> V_3 -> V_7 ) ;
V_7 -> V_8 ++ ;
V_7 -> V_9 += V_98 -> V_75 ;
F_73 ( V_98 , V_126 -> V_3 ) ;
F_61 ( V_32 , V_98 ) ;
F_74 ( V_98 ) ;
F_37 () ;
return 0 ;
}
F_37 () ;
return 1 ;
V_85:
F_71 ( V_98 ) ;
return 0 ;
}
static inline
T_2 F_75 ( const struct V_105 * V_134 , struct V_21 * V_126 )
{
T_2 V_135 = 0 ;
#ifdef F_18
if ( F_76 ( V_134 , & V_126 -> V_48 . V_49 ,
V_126 -> V_48 . V_51 ) ) {
unsigned int V_136 , V_137 ;
int V_138 ;
T_5 V_139 ;
V_136 = V_126 -> V_48 . V_51 >> 5 ;
V_137 = V_126 -> V_48 . V_51 & 0x1f ;
V_139 = ( F_77 ( V_134 -> V_107 [ V_136 ] ) << V_137 ) >>
V_126 -> V_48 . V_52 ;
V_138 = V_137 - V_126 -> V_48 . V_52 ;
if ( V_138 > 0 )
V_139 |= F_77 ( V_134 -> V_107 [ V_136 + 1 ] ) >>
( 32 - V_138 ) ;
V_135 = V_126 -> V_48 . V_50 | F_21 ( V_139 ) ;
}
#else
if ( V_134 -> V_140 [ 0 ] == F_70 ( 0x2002 ) ) {
memcpy ( & V_135 , & V_134 -> V_140 [ 1 ] , 4 ) ;
}
#endif
return V_135 ;
}
static T_6 F_78 ( struct V_97 * V_98 ,
struct V_2 * V_3 )
{
struct V_21 * V_126 = F_19 ( V_3 ) ;
struct V_6 * V_7 ;
const struct V_99 * V_141 = & V_126 -> V_31 . V_32 ;
const struct V_127 * V_142 = F_51 ( V_98 ) ;
T_7 V_125 = V_126 -> V_31 . V_32 . V_125 ;
T_8 V_143 = V_141 -> V_144 ;
struct V_145 * V_146 ;
struct V_2 * V_147 ;
struct V_99 * V_32 ;
unsigned int V_148 ;
T_2 V_135 = V_141 -> V_34 ;
struct V_149 V_150 ;
int V_151 ;
const struct V_105 * V_106 ;
int V_152 ;
if ( V_98 -> V_130 != F_70 ( V_131 ) )
goto V_153;
if ( V_125 == 1 )
V_125 = F_79 ( V_142 ) ;
if ( V_3 -> V_63 & V_64 ) {
struct V_154 * V_155 = NULL ;
bool V_156 = false ;
if ( F_80 ( V_98 ) )
V_155 = F_81 ( F_80 ( V_98 ) , & V_142 -> V_34 ) ;
if ( V_155 == NULL ) {
F_82 ( L_2 ) ;
goto V_153;
}
V_106 = ( const struct V_105 * ) & V_155 -> V_157 ;
V_152 = F_83 ( V_106 ) ;
if ( ( V_152 & V_158 ) &&
F_52 ( V_106 ) )
V_135 = V_106 -> V_107 [ 3 ] ;
else
V_156 = true ;
F_84 ( V_155 ) ;
if ( V_156 )
goto V_153;
}
if ( ! V_135 )
V_135 = F_75 ( & V_142 -> V_34 , V_126 ) ;
if ( ! V_135 ) {
struct V_154 * V_155 = NULL ;
bool V_156 = false ;
if ( F_80 ( V_98 ) )
V_155 = F_81 ( F_80 ( V_98 ) , & V_142 -> V_34 ) ;
if ( V_155 == NULL ) {
F_82 ( L_2 ) ;
goto V_153;
}
V_106 = ( const struct V_105 * ) & V_155 -> V_157 ;
V_152 = F_83 ( V_106 ) ;
if ( V_152 == V_159 ) {
V_106 = & F_51 ( V_98 ) -> V_34 ;
V_152 = F_83 ( V_106 ) ;
}
if ( ( V_152 & V_160 ) != 0 )
V_135 = V_106 -> V_107 [ 3 ] ;
else
V_156 = true ;
F_84 ( V_155 ) ;
if ( V_156 )
goto V_153;
}
V_146 = F_85 ( F_55 ( V_3 ) , & V_150 , NULL ,
V_135 , V_141 -> V_33 ,
0 , 0 ,
V_161 , F_86 ( V_125 ) ,
V_126 -> V_31 . V_35 ) ;
if ( F_87 ( V_146 ) ) {
V_3 -> V_15 . V_17 ++ ;
goto V_162;
}
if ( V_146 -> V_163 != V_164 ) {
F_88 ( V_146 ) ;
V_3 -> V_15 . V_17 ++ ;
goto V_162;
}
V_147 = V_146 -> V_135 . V_3 ;
if ( V_147 == V_3 ) {
F_88 ( V_146 ) ;
V_3 -> V_15 . V_165 ++ ;
goto V_153;
}
if ( V_143 ) {
V_151 = F_89 ( & V_146 -> V_135 ) - sizeof( struct V_99 ) ;
if ( V_151 < 68 ) {
V_3 -> V_15 . V_165 ++ ;
F_88 ( V_146 ) ;
goto V_153;
}
if ( V_151 < V_166 ) {
V_151 = V_166 ;
V_143 = 0 ;
}
if ( V_126 -> V_31 . V_32 . V_34 && F_80 ( V_98 ) )
F_80 ( V_98 ) -> V_167 -> V_168 ( F_80 ( V_98 ) , V_151 ) ;
if ( V_98 -> V_75 > V_151 ) {
F_90 ( V_98 , V_169 , 0 , V_151 ) ;
F_88 ( V_146 ) ;
goto V_153;
}
}
if ( V_126 -> V_124 > 0 ) {
if ( F_60 ( V_121 ,
V_126 -> V_122 + V_123 ) ) {
V_126 -> V_124 -- ;
F_91 ( V_98 ) ;
} else
V_126 -> V_124 = 0 ;
}
V_148 = F_92 ( V_147 ) + sizeof( struct V_99 ) ;
if ( F_93 ( V_98 ) < V_148 || F_94 ( V_98 ) ||
( F_95 ( V_98 ) && ! F_96 ( V_98 , 0 ) ) ) {
struct V_97 * V_170 = F_97 ( V_98 , V_148 ) ;
if ( ! V_170 ) {
F_88 ( V_146 ) ;
V_3 -> V_15 . V_18 ++ ;
F_98 ( V_98 ) ;
return V_171 ;
}
if ( V_98 -> V_172 )
F_99 ( V_170 , V_98 -> V_172 ) ;
F_98 ( V_98 ) ;
V_98 = V_170 ;
V_142 = F_51 ( V_98 ) ;
}
V_98 -> V_173 = V_98 -> V_129 ;
F_100 ( V_98 , sizeof( struct V_99 ) ) ;
F_68 ( V_98 ) ;
memset ( & ( F_69 ( V_98 ) -> V_174 ) , 0 , sizeof( F_69 ( V_98 ) -> V_174 ) ) ;
F_69 ( V_98 ) -> V_37 = 0 ;
F_101 ( V_98 ) ;
F_102 ( V_98 , & V_146 -> V_135 ) ;
V_32 = F_66 ( V_98 ) ;
V_32 -> V_175 = 4 ;
V_32 -> V_176 = sizeof( struct V_99 ) >> 2 ;
V_32 -> V_144 = V_143 ;
V_32 -> V_130 = V_161 ;
V_32 -> V_125 = F_103 ( V_125 , F_79 ( V_142 ) ) ;
V_32 -> V_34 = V_150 . V_34 ;
V_32 -> V_33 = V_150 . V_33 ;
if ( ( V_32 -> V_120 = V_141 -> V_120 ) == 0 )
V_32 -> V_120 = V_142 -> V_177 ;
F_104 ( V_98 ) ;
V_7 = F_72 ( V_3 -> V_7 ) ;
F_105 ( V_7 , & V_3 -> V_15 ) ;
return V_171 ;
V_162:
F_91 ( V_98 ) ;
V_153:
V_3 -> V_15 . V_20 ++ ;
F_98 ( V_98 ) ;
return V_171 ;
}
static void F_106 ( struct V_2 * V_3 )
{
struct V_2 * V_147 = NULL ;
struct V_21 * V_126 ;
const struct V_99 * V_32 ;
struct V_149 V_150 ;
V_126 = F_19 ( V_3 ) ;
V_32 = & V_126 -> V_31 . V_32 ;
if ( V_32 -> V_34 ) {
struct V_145 * V_146 = F_85 ( F_55 ( V_3 ) , & V_150 , NULL ,
V_32 -> V_34 , V_32 -> V_33 ,
0 , 0 ,
V_161 ,
F_86 ( V_32 -> V_125 ) ,
V_126 -> V_31 . V_35 ) ;
if ( ! F_87 ( V_146 ) ) {
V_147 = V_146 -> V_135 . V_3 ;
F_88 ( V_146 ) ;
}
V_3 -> V_37 |= V_178 ;
}
if ( ! V_147 && V_126 -> V_31 . V_35 )
V_147 = F_107 ( F_55 ( V_3 ) , V_126 -> V_31 . V_35 ) ;
if ( V_147 ) {
V_3 -> V_179 = V_147 -> V_179 + sizeof( struct V_99 ) ;
V_3 -> V_151 = V_147 -> V_151 - sizeof( struct V_99 ) ;
if ( V_3 -> V_151 < V_166 )
V_3 -> V_151 = V_166 ;
}
V_3 -> V_36 = V_126 -> V_31 . V_35 ;
}
static int
F_108 ( struct V_2 * V_3 , struct V_180 * V_181 , int V_182 )
{
int V_88 = 0 ;
struct V_40 V_87 ;
struct V_68 V_67 ;
struct V_21 * V_27 ;
struct V_22 * V_22 = F_55 ( V_3 ) ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
#ifdef F_18
struct V_183 V_48 ;
#endif
switch ( V_182 ) {
case V_184 :
#ifdef F_18
case V_185 :
#endif
V_27 = NULL ;
if ( V_3 == V_29 -> V_47 ) {
if ( F_33 ( & V_87 , V_181 -> V_186 . V_187 , sizeof( V_87 ) ) ) {
V_88 = - V_77 ;
break;
}
V_27 = F_22 ( V_22 , & V_87 , 0 ) ;
}
if ( V_27 == NULL )
V_27 = F_19 ( V_3 ) ;
V_88 = - V_77 ;
if ( V_182 == V_184 ) {
memcpy ( & V_87 , & V_27 -> V_31 , sizeof( V_87 ) ) ;
if ( F_38 ( V_181 -> V_186 . V_187 , & V_87 ,
sizeof( V_87 ) ) )
goto V_188;
#ifdef F_18
} else {
V_48 . V_49 = V_27 -> V_48 . V_49 ;
V_48 . V_50 = V_27 -> V_48 . V_50 ;
V_48 . V_51 = V_27 -> V_48 . V_51 ;
V_48 . V_52 = V_27 -> V_48 . V_52 ;
if ( F_38 ( V_181 -> V_186 . V_187 , & V_48 ,
sizeof( V_48 ) ) )
goto V_188;
#endif
}
V_88 = 0 ;
break;
case V_189 :
case V_190 :
V_88 = - V_191 ;
if ( ! F_34 ( V_80 ) )
goto V_188;
V_88 = - V_77 ;
if ( F_33 ( & V_87 , V_181 -> V_186 . V_187 , sizeof( V_87 ) ) )
goto V_188;
V_88 = - V_89 ;
if ( V_87 . V_32 . V_175 != 4 || V_87 . V_32 . V_130 != V_161 ||
V_87 . V_32 . V_176 != 5 || ( V_87 . V_32 . V_144 & F_70 ( ~ V_192 ) ) )
goto V_188;
if ( V_87 . V_32 . V_120 )
V_87 . V_32 . V_144 |= F_70 ( V_192 ) ;
V_27 = F_22 ( V_22 , & V_87 , V_182 == V_189 ) ;
if ( V_3 != V_29 -> V_47 && V_182 == V_190 ) {
if ( V_27 != NULL ) {
if ( V_27 -> V_3 != V_3 ) {
V_88 = - V_90 ;
break;
}
} else {
if ( ( ( V_3 -> V_37 & V_178 ) && ! V_87 . V_32 . V_34 ) ||
( ! ( V_3 -> V_37 & V_178 ) && V_87 . V_32 . V_34 ) ) {
V_88 = - V_89 ;
break;
}
V_27 = F_19 ( V_3 ) ;
F_13 ( V_29 , V_27 ) ;
F_109 () ;
V_27 -> V_31 . V_32 . V_33 = V_87 . V_32 . V_33 ;
V_27 -> V_31 . V_32 . V_34 = V_87 . V_32 . V_34 ;
memcpy ( V_3 -> V_193 , & V_87 . V_32 . V_33 , 4 ) ;
memcpy ( V_3 -> V_194 , & V_87 . V_32 . V_34 , 4 ) ;
F_16 ( V_29 , V_27 ) ;
F_110 ( V_3 ) ;
}
}
if ( V_27 ) {
V_88 = 0 ;
if ( V_182 == V_190 ) {
V_27 -> V_31 . V_32 . V_120 = V_87 . V_32 . V_120 ;
V_27 -> V_31 . V_32 . V_125 = V_87 . V_32 . V_125 ;
if ( V_27 -> V_31 . V_35 != V_87 . V_35 ) {
V_27 -> V_31 . V_35 = V_87 . V_35 ;
F_106 ( V_3 ) ;
F_110 ( V_3 ) ;
}
}
if ( F_38 ( V_181 -> V_186 . V_187 , & V_27 -> V_31 , sizeof( V_87 ) ) )
V_88 = - V_77 ;
} else
V_88 = ( V_182 == V_189 ? - V_92 : - V_119 ) ;
break;
case V_195 :
V_88 = - V_191 ;
if ( ! F_34 ( V_80 ) )
goto V_188;
if ( V_3 == V_29 -> V_47 ) {
V_88 = - V_77 ;
if ( F_33 ( & V_87 , V_181 -> V_186 . V_187 , sizeof( V_87 ) ) )
goto V_188;
V_88 = - V_119 ;
if ( ( V_27 = F_22 ( V_22 , & V_87 , 0 ) ) == NULL )
goto V_188;
V_88 = - V_191 ;
if ( V_27 == F_19 ( V_29 -> V_47 ) )
goto V_188;
V_3 = V_27 -> V_3 ;
}
F_111 ( V_3 ) ;
V_88 = 0 ;
break;
case V_196 :
V_88 = - V_89 ;
if ( V_3 == V_29 -> V_47 )
goto V_188;
V_88 = - V_119 ;
if ( ! ( V_27 = F_19 ( V_3 ) ) )
goto V_188;
V_88 = F_32 ( V_27 , V_181 -> V_186 . V_187 ) ;
break;
case V_197 :
case V_198 :
case V_199 :
V_88 = - V_191 ;
if ( ! F_34 ( V_80 ) )
goto V_188;
V_88 = - V_89 ;
if ( V_3 == V_29 -> V_47 )
goto V_188;
V_88 = - V_77 ;
if ( F_33 ( & V_67 , V_181 -> V_186 . V_187 , sizeof( V_67 ) ) )
goto V_188;
V_88 = - V_119 ;
if ( ! ( V_27 = F_19 ( V_3 ) ) )
goto V_188;
switch ( V_182 ) {
case V_198 :
V_88 = F_47 ( V_27 , & V_67 ) ;
break;
case V_197 :
case V_199 :
V_88 = F_41 ( V_27 , & V_67 , V_182 == V_199 ) ;
break;
}
F_110 ( V_3 ) ;
break;
#ifdef F_18
case V_200 :
case V_201 :
case V_202 :
V_88 = - V_191 ;
if ( ! F_34 ( V_80 ) )
goto V_188;
V_88 = - V_77 ;
if ( F_33 ( & V_48 , V_181 -> V_186 . V_187 ,
sizeof( V_48 ) ) )
goto V_188;
V_27 = F_19 ( V_3 ) ;
if ( V_182 != V_202 ) {
struct V_105 V_49 ;
T_2 V_50 ;
V_88 = - V_89 ;
if ( V_48 . V_52 > 32 ||
V_48 . V_51 + ( 32 - V_48 . V_52 ) > 64 )
goto V_188;
F_112 ( & V_49 , & V_48 . V_49 ,
V_48 . V_51 ) ;
if ( ! F_113 ( & V_49 , & V_48 . V_49 ) )
goto V_188;
if ( V_48 . V_52 )
V_50 = V_48 . V_50 &
F_21 ( 0xffffffffUL <<
( 32 - V_48 . V_52 ) ) ;
else
V_50 = 0 ;
if ( V_50 != V_48 . V_50 )
goto V_188;
V_27 -> V_48 . V_49 = V_49 ;
V_27 -> V_48 . V_50 = V_50 ;
V_27 -> V_48 . V_51 = V_48 . V_51 ;
V_27 -> V_48 . V_52 = V_48 . V_52 ;
} else
F_17 ( V_3 , V_29 ) ;
V_88 = 0 ;
break;
#endif
default:
V_88 = - V_89 ;
}
V_188:
return V_88 ;
}
static int F_114 ( struct V_2 * V_3 , int V_203 )
{
if ( V_203 < V_166 || V_203 > 0xFFF8 - sizeof( struct V_99 ) )
return - V_89 ;
V_3 -> V_151 = V_203 ;
return 0 ;
}
static void F_29 ( struct V_2 * V_3 )
{
F_115 ( V_3 -> V_7 ) ;
F_116 ( V_3 ) ;
}
static void V_59 ( struct V_2 * V_3 )
{
V_3 -> V_204 = & V_205 ;
V_3 -> V_206 = F_29 ;
V_3 -> type = V_207 ;
V_3 -> V_179 = V_208 + sizeof( struct V_99 ) ;
V_3 -> V_151 = V_209 - sizeof( struct V_99 ) ;
V_3 -> V_37 = V_210 ;
V_3 -> V_63 &= ~ V_211 ;
V_3 -> V_36 = 0 ;
V_3 -> V_212 = 4 ;
V_3 -> V_213 |= V_214 ;
V_3 -> V_213 |= V_215 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_21 * V_126 = F_19 ( V_3 ) ;
V_126 -> V_3 = V_3 ;
memcpy ( V_3 -> V_193 , & V_126 -> V_31 . V_32 . V_33 , 4 ) ;
memcpy ( V_3 -> V_194 , & V_126 -> V_31 . V_32 . V_34 , 4 ) ;
F_106 ( V_3 ) ;
V_3 -> V_7 = F_117 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_84 ;
return 0 ;
}
static int T_9 F_118 ( struct V_2 * V_3 )
{
struct V_21 * V_126 = F_19 ( V_3 ) ;
struct V_99 * V_32 = & V_126 -> V_31 . V_32 ;
struct V_22 * V_22 = F_55 ( V_3 ) ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
V_126 -> V_3 = V_3 ;
strcpy ( V_126 -> V_31 . V_56 , V_3 -> V_56 ) ;
V_32 -> V_175 = 4 ;
V_32 -> V_130 = V_161 ;
V_32 -> V_176 = 5 ;
V_32 -> V_120 = 64 ;
V_3 -> V_7 = F_117 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_84 ;
F_28 ( V_3 ) ;
F_15 ( V_29 -> V_39 [ 0 ] , V_126 ) ;
return 0 ;
}
static void T_10 F_119 ( struct V_28 * V_29 , struct V_216 * V_94 )
{
int V_42 ;
for ( V_42 = 1 ; V_42 < 4 ; V_42 ++ ) {
int V_41 ;
for ( V_41 = 0 ; V_41 < V_217 ; V_41 ++ ) {
struct V_21 * V_27 ;
V_27 = F_14 ( V_29 -> V_43 [ V_42 ] [ V_41 ] ) ;
while ( V_27 != NULL ) {
F_120 ( V_27 -> V_3 , V_94 ) ;
V_27 = F_14 ( V_27 -> V_46 ) ;
}
}
}
}
static int T_9 F_121 ( struct V_22 * V_22 )
{
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
struct V_21 * V_27 ;
int V_88 ;
V_29 -> V_43 [ 0 ] = V_29 -> V_39 ;
V_29 -> V_43 [ 1 ] = V_29 -> V_218 ;
V_29 -> V_43 [ 2 ] = V_29 -> V_219 ;
V_29 -> V_43 [ 3 ] = V_29 -> V_220 ;
V_29 -> V_47 = F_24 ( sizeof( struct V_21 ) , L_3 ,
V_59 ) ;
if ( ! V_29 -> V_47 ) {
V_88 = - V_84 ;
goto V_221;
}
F_25 ( V_29 -> V_47 , V_22 ) ;
V_88 = F_118 ( V_29 -> V_47 ) ;
if ( V_88 )
goto V_222;
F_17 ( V_29 -> V_47 , V_29 ) ;
if ( ( V_88 = F_122 ( V_29 -> V_47 ) ) )
goto V_223;
V_27 = F_19 ( V_29 -> V_47 ) ;
strcpy ( V_27 -> V_31 . V_56 , V_29 -> V_47 -> V_56 ) ;
return 0 ;
V_223:
F_57 ( V_29 -> V_47 ) ;
V_222:
F_29 ( V_29 -> V_47 ) ;
V_221:
return V_88 ;
}
static void T_10 F_123 ( struct V_22 * V_22 )
{
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
F_124 ( V_224 ) ;
F_125 () ;
F_119 ( V_29 , & V_224 ) ;
F_120 ( V_29 -> V_47 , & V_224 ) ;
F_126 ( & V_224 ) ;
F_127 () ;
}
static void T_11 F_128 ( void )
{
F_129 ( & V_225 , V_226 ) ;
F_130 ( & V_227 ) ;
F_131 () ;
}
static int T_12 F_132 ( void )
{
int V_88 ;
F_133 ( L_4 ) ;
V_88 = F_134 ( & V_227 ) ;
if ( V_88 < 0 )
return V_88 ;
V_88 = F_135 ( & V_225 , V_226 ) ;
if ( V_88 < 0 ) {
F_130 ( & V_227 ) ;
F_133 ( L_5 , V_228 ) ;
}
return V_88 ;
}
