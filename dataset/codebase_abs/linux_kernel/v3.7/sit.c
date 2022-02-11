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
default:
break;
}
break;
case V_116 :
if ( V_111 != V_117 )
return 0 ;
break;
case V_118 :
break;
}
V_88 = - V_119 ;
V_27 = F_6 ( F_55 ( V_98 -> V_3 ) ,
V_98 -> V_3 ,
V_32 -> V_34 ,
V_32 -> V_33 ) ;
if ( V_27 == NULL )
goto V_85;
if ( type == V_113 && V_111 == V_120 ) {
F_60 ( V_98 , F_55 ( V_98 -> V_3 ) , V_109 ,
V_27 -> V_3 -> V_121 , 0 , V_122 , 0 ) ;
V_88 = 0 ;
goto V_85;
}
if ( type == V_118 ) {
F_61 ( V_98 , F_55 ( V_98 -> V_3 ) , V_27 -> V_3 -> V_121 , 0 ,
V_122 , 0 ) ;
V_88 = 0 ;
goto V_85;
}
if ( V_27 -> V_31 . V_32 . V_34 == 0 )
goto V_85;
V_88 = 0 ;
if ( V_27 -> V_31 . V_32 . V_123 == 0 && type == V_116 )
goto V_85;
if ( F_62 ( V_124 , V_27 -> V_125 + V_126 ) )
V_27 -> V_127 ++ ;
else
V_27 -> V_127 = 1 ;
V_27 -> V_125 = V_124 ;
V_85:
return V_88 ;
}
static inline void F_63 ( const struct V_99 * V_32 , struct V_97 * V_98 )
{
if ( F_64 ( V_32 -> V_128 ) )
F_65 ( F_51 ( V_98 ) ) ;
}
static int F_66 ( struct V_97 * V_98 )
{
const struct V_99 * V_32 ;
struct V_21 * V_129 ;
if ( ! F_67 ( V_98 , sizeof( struct V_130 ) ) )
goto V_85;
V_32 = F_68 ( V_98 ) ;
V_129 = F_6 ( F_55 ( V_98 -> V_3 ) , V_98 -> V_3 ,
V_32 -> V_33 , V_32 -> V_34 ) ;
if ( V_129 != NULL ) {
struct V_6 * V_7 ;
F_69 ( V_98 ) ;
V_98 -> V_131 = V_98 -> V_132 ;
F_70 ( V_98 ) ;
F_71 ( V_98 ) -> V_37 = 0 ;
V_98 -> V_133 = F_72 ( V_134 ) ;
V_98 -> V_135 = V_136 ;
if ( ( V_129 -> V_3 -> V_63 & V_64 ) &&
! F_50 ( V_98 , V_32 , V_129 ) ) {
V_129 -> V_3 -> V_15 . V_14 ++ ;
F_73 ( V_98 ) ;
return 0 ;
}
V_7 = F_74 ( V_129 -> V_3 -> V_7 ) ;
V_7 -> V_8 ++ ;
V_7 -> V_9 += V_98 -> V_75 ;
F_75 ( V_98 , V_129 -> V_3 ) ;
F_63 ( V_32 , V_98 ) ;
F_76 ( V_98 ) ;
return 0 ;
}
return 1 ;
V_85:
F_73 ( V_98 ) ;
return 0 ;
}
static inline
T_2 F_77 ( const struct V_105 * V_137 , struct V_21 * V_129 )
{
T_2 V_138 = 0 ;
#ifdef F_18
if ( F_78 ( V_137 , & V_129 -> V_48 . V_49 ,
V_129 -> V_48 . V_51 ) ) {
unsigned int V_139 , V_140 ;
int V_141 ;
T_5 V_142 ;
V_139 = V_129 -> V_48 . V_51 >> 5 ;
V_140 = V_129 -> V_48 . V_51 & 0x1f ;
V_142 = ( F_79 ( V_137 -> V_107 [ V_139 ] ) << V_140 ) >>
V_129 -> V_48 . V_52 ;
V_141 = V_140 - V_129 -> V_48 . V_52 ;
if ( V_141 > 0 )
V_142 |= F_79 ( V_137 -> V_107 [ V_139 + 1 ] ) >>
( 32 - V_141 ) ;
V_138 = V_129 -> V_48 . V_50 | F_21 ( V_142 ) ;
}
#else
if ( V_137 -> V_143 [ 0 ] == F_72 ( 0x2002 ) ) {
memcpy ( & V_138 , & V_137 -> V_143 [ 1 ] , 4 ) ;
}
#endif
return V_138 ;
}
static T_6 F_80 ( struct V_97 * V_98 ,
struct V_2 * V_3 )
{
struct V_21 * V_129 = F_19 ( V_3 ) ;
struct V_6 * V_7 ;
const struct V_99 * V_144 = & V_129 -> V_31 . V_32 ;
const struct V_130 * V_145 = F_51 ( V_98 ) ;
T_7 V_128 = V_129 -> V_31 . V_32 . V_128 ;
T_8 V_146 = V_144 -> V_147 ;
struct V_148 * V_149 ;
struct V_2 * V_150 ;
struct V_99 * V_32 ;
unsigned int V_151 ;
T_2 V_138 = V_144 -> V_34 ;
struct V_152 V_153 ;
int V_154 ;
const struct V_105 * V_106 ;
int V_155 ;
if ( V_98 -> V_133 != F_72 ( V_134 ) )
goto V_156;
if ( V_128 == 1 )
V_128 = F_81 ( V_145 ) ;
if ( V_3 -> V_63 & V_64 ) {
struct V_157 * V_158 = NULL ;
bool V_159 = false ;
if ( F_82 ( V_98 ) )
V_158 = F_83 ( F_82 ( V_98 ) , & V_145 -> V_34 ) ;
if ( V_158 == NULL ) {
F_84 ( L_2 ) ;
goto V_156;
}
V_106 = ( const struct V_105 * ) & V_158 -> V_160 ;
V_155 = F_85 ( V_106 ) ;
if ( ( V_155 & V_161 ) &&
F_52 ( V_106 ) )
V_138 = V_106 -> V_107 [ 3 ] ;
else
V_159 = true ;
F_86 ( V_158 ) ;
if ( V_159 )
goto V_156;
}
if ( ! V_138 )
V_138 = F_77 ( & V_145 -> V_34 , V_129 ) ;
if ( ! V_138 ) {
struct V_157 * V_158 = NULL ;
bool V_159 = false ;
if ( F_82 ( V_98 ) )
V_158 = F_83 ( F_82 ( V_98 ) , & V_145 -> V_34 ) ;
if ( V_158 == NULL ) {
F_84 ( L_2 ) ;
goto V_156;
}
V_106 = ( const struct V_105 * ) & V_158 -> V_160 ;
V_155 = F_85 ( V_106 ) ;
if ( V_155 == V_162 ) {
V_106 = & F_51 ( V_98 ) -> V_34 ;
V_155 = F_85 ( V_106 ) ;
}
if ( ( V_155 & V_163 ) != 0 )
V_138 = V_106 -> V_107 [ 3 ] ;
else
V_159 = true ;
F_86 ( V_158 ) ;
if ( V_159 )
goto V_156;
}
V_149 = F_87 ( F_55 ( V_3 ) , & V_153 , NULL ,
V_138 , V_144 -> V_33 ,
0 , 0 ,
V_122 , F_88 ( V_128 ) ,
V_129 -> V_31 . V_35 ) ;
if ( F_89 ( V_149 ) ) {
V_3 -> V_15 . V_17 ++ ;
goto V_164;
}
if ( V_149 -> V_165 != V_166 ) {
F_90 ( V_149 ) ;
V_3 -> V_15 . V_17 ++ ;
goto V_164;
}
V_150 = V_149 -> V_138 . V_3 ;
if ( V_150 == V_3 ) {
F_90 ( V_149 ) ;
V_3 -> V_15 . V_167 ++ ;
goto V_156;
}
if ( V_146 ) {
V_154 = F_91 ( & V_149 -> V_138 ) - sizeof( struct V_99 ) ;
if ( V_154 < 68 ) {
V_3 -> V_15 . V_167 ++ ;
F_90 ( V_149 ) ;
goto V_156;
}
if ( V_154 < V_168 ) {
V_154 = V_168 ;
V_146 = 0 ;
}
if ( V_129 -> V_31 . V_32 . V_34 && F_82 ( V_98 ) )
F_82 ( V_98 ) -> V_169 -> V_170 ( F_82 ( V_98 ) , NULL , V_98 , V_154 ) ;
if ( V_98 -> V_75 > V_154 ) {
F_92 ( V_98 , V_171 , 0 , V_154 ) ;
F_90 ( V_149 ) ;
goto V_156;
}
}
if ( V_129 -> V_127 > 0 ) {
if ( F_62 ( V_124 ,
V_129 -> V_125 + V_126 ) ) {
V_129 -> V_127 -- ;
F_93 ( V_98 ) ;
} else
V_129 -> V_127 = 0 ;
}
V_151 = F_94 ( V_150 ) + sizeof( struct V_99 ) ;
if ( F_95 ( V_98 ) < V_151 || F_96 ( V_98 ) ||
( F_97 ( V_98 ) && ! F_98 ( V_98 , 0 ) ) ) {
struct V_97 * V_172 = F_99 ( V_98 , V_151 ) ;
if ( ! V_172 ) {
F_90 ( V_149 ) ;
V_3 -> V_15 . V_18 ++ ;
F_100 ( V_98 ) ;
return V_173 ;
}
if ( V_98 -> V_174 )
F_101 ( V_172 , V_98 -> V_174 ) ;
F_100 ( V_98 ) ;
V_98 = V_172 ;
V_145 = F_51 ( V_98 ) ;
}
V_98 -> V_175 = V_98 -> V_132 ;
F_102 ( V_98 , sizeof( struct V_99 ) ) ;
F_70 ( V_98 ) ;
memset ( & ( F_71 ( V_98 ) -> V_176 ) , 0 , sizeof( F_71 ( V_98 ) -> V_176 ) ) ;
F_71 ( V_98 ) -> V_37 = 0 ;
F_103 ( V_98 ) ;
F_104 ( V_98 , & V_149 -> V_138 ) ;
V_32 = F_68 ( V_98 ) ;
V_32 -> V_177 = 4 ;
V_32 -> V_178 = sizeof( struct V_99 ) >> 2 ;
V_32 -> V_147 = V_146 ;
V_32 -> V_133 = V_122 ;
V_32 -> V_128 = F_105 ( V_128 , F_81 ( V_145 ) ) ;
V_32 -> V_34 = V_153 . V_34 ;
V_32 -> V_33 = V_153 . V_33 ;
if ( ( V_32 -> V_123 = V_144 -> V_123 ) == 0 )
V_32 -> V_123 = V_145 -> V_179 ;
F_106 ( V_98 ) ;
V_7 = F_74 ( V_3 -> V_7 ) ;
F_107 ( V_7 , & V_3 -> V_15 ) ;
return V_173 ;
V_164:
F_93 ( V_98 ) ;
V_156:
V_3 -> V_15 . V_20 ++ ;
F_100 ( V_98 ) ;
return V_173 ;
}
static void F_108 ( struct V_2 * V_3 )
{
struct V_2 * V_150 = NULL ;
struct V_21 * V_129 ;
const struct V_99 * V_32 ;
struct V_152 V_153 ;
V_129 = F_19 ( V_3 ) ;
V_32 = & V_129 -> V_31 . V_32 ;
if ( V_32 -> V_34 ) {
struct V_148 * V_149 = F_87 ( F_55 ( V_3 ) , & V_153 , NULL ,
V_32 -> V_34 , V_32 -> V_33 ,
0 , 0 ,
V_122 ,
F_88 ( V_32 -> V_128 ) ,
V_129 -> V_31 . V_35 ) ;
if ( ! F_89 ( V_149 ) ) {
V_150 = V_149 -> V_138 . V_3 ;
F_90 ( V_149 ) ;
}
V_3 -> V_37 |= V_180 ;
}
if ( ! V_150 && V_129 -> V_31 . V_35 )
V_150 = F_109 ( F_55 ( V_3 ) , V_129 -> V_31 . V_35 ) ;
if ( V_150 ) {
V_3 -> V_181 = V_150 -> V_181 + sizeof( struct V_99 ) ;
V_3 -> V_154 = V_150 -> V_154 - sizeof( struct V_99 ) ;
if ( V_3 -> V_154 < V_168 )
V_3 -> V_154 = V_168 ;
}
V_3 -> V_36 = V_129 -> V_31 . V_35 ;
}
static int
F_110 ( struct V_2 * V_3 , struct V_182 * V_183 , int V_184 )
{
int V_88 = 0 ;
struct V_40 V_87 ;
struct V_68 V_67 ;
struct V_21 * V_27 ;
struct V_22 * V_22 = F_55 ( V_3 ) ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
#ifdef F_18
struct V_185 V_48 ;
#endif
switch ( V_184 ) {
case V_186 :
#ifdef F_18
case V_187 :
#endif
V_27 = NULL ;
if ( V_3 == V_29 -> V_47 ) {
if ( F_33 ( & V_87 , V_183 -> V_188 . V_189 , sizeof( V_87 ) ) ) {
V_88 = - V_77 ;
break;
}
V_27 = F_22 ( V_22 , & V_87 , 0 ) ;
}
if ( V_27 == NULL )
V_27 = F_19 ( V_3 ) ;
V_88 = - V_77 ;
if ( V_184 == V_186 ) {
memcpy ( & V_87 , & V_27 -> V_31 , sizeof( V_87 ) ) ;
if ( F_38 ( V_183 -> V_188 . V_189 , & V_87 ,
sizeof( V_87 ) ) )
goto V_190;
#ifdef F_18
} else {
V_48 . V_49 = V_27 -> V_48 . V_49 ;
V_48 . V_50 = V_27 -> V_48 . V_50 ;
V_48 . V_51 = V_27 -> V_48 . V_51 ;
V_48 . V_52 = V_27 -> V_48 . V_52 ;
if ( F_38 ( V_183 -> V_188 . V_189 , & V_48 ,
sizeof( V_48 ) ) )
goto V_190;
#endif
}
V_88 = 0 ;
break;
case V_191 :
case V_192 :
V_88 = - V_193 ;
if ( ! F_34 ( V_80 ) )
goto V_190;
V_88 = - V_77 ;
if ( F_33 ( & V_87 , V_183 -> V_188 . V_189 , sizeof( V_87 ) ) )
goto V_190;
V_88 = - V_89 ;
if ( V_87 . V_32 . V_177 != 4 || V_87 . V_32 . V_133 != V_122 ||
V_87 . V_32 . V_178 != 5 || ( V_87 . V_32 . V_147 & F_72 ( ~ V_194 ) ) )
goto V_190;
if ( V_87 . V_32 . V_123 )
V_87 . V_32 . V_147 |= F_72 ( V_194 ) ;
V_27 = F_22 ( V_22 , & V_87 , V_184 == V_191 ) ;
if ( V_3 != V_29 -> V_47 && V_184 == V_192 ) {
if ( V_27 != NULL ) {
if ( V_27 -> V_3 != V_3 ) {
V_88 = - V_90 ;
break;
}
} else {
if ( ( ( V_3 -> V_37 & V_180 ) && ! V_87 . V_32 . V_34 ) ||
( ! ( V_3 -> V_37 & V_180 ) && V_87 . V_32 . V_34 ) ) {
V_88 = - V_89 ;
break;
}
V_27 = F_19 ( V_3 ) ;
F_13 ( V_29 , V_27 ) ;
F_111 () ;
V_27 -> V_31 . V_32 . V_33 = V_87 . V_32 . V_33 ;
V_27 -> V_31 . V_32 . V_34 = V_87 . V_32 . V_34 ;
memcpy ( V_3 -> V_195 , & V_87 . V_32 . V_33 , 4 ) ;
memcpy ( V_3 -> V_196 , & V_87 . V_32 . V_34 , 4 ) ;
F_16 ( V_29 , V_27 ) ;
F_112 ( V_3 ) ;
}
}
if ( V_27 ) {
V_88 = 0 ;
if ( V_184 == V_192 ) {
V_27 -> V_31 . V_32 . V_123 = V_87 . V_32 . V_123 ;
V_27 -> V_31 . V_32 . V_128 = V_87 . V_32 . V_128 ;
if ( V_27 -> V_31 . V_35 != V_87 . V_35 ) {
V_27 -> V_31 . V_35 = V_87 . V_35 ;
F_108 ( V_3 ) ;
F_112 ( V_3 ) ;
}
}
if ( F_38 ( V_183 -> V_188 . V_189 , & V_27 -> V_31 , sizeof( V_87 ) ) )
V_88 = - V_77 ;
} else
V_88 = ( V_184 == V_191 ? - V_92 : - V_119 ) ;
break;
case V_197 :
V_88 = - V_193 ;
if ( ! F_34 ( V_80 ) )
goto V_190;
if ( V_3 == V_29 -> V_47 ) {
V_88 = - V_77 ;
if ( F_33 ( & V_87 , V_183 -> V_188 . V_189 , sizeof( V_87 ) ) )
goto V_190;
V_88 = - V_119 ;
if ( ( V_27 = F_22 ( V_22 , & V_87 , 0 ) ) == NULL )
goto V_190;
V_88 = - V_193 ;
if ( V_27 == F_19 ( V_29 -> V_47 ) )
goto V_190;
V_3 = V_27 -> V_3 ;
}
F_113 ( V_3 ) ;
V_88 = 0 ;
break;
case V_198 :
V_88 = - V_89 ;
if ( V_3 == V_29 -> V_47 )
goto V_190;
V_88 = - V_119 ;
if ( ! ( V_27 = F_19 ( V_3 ) ) )
goto V_190;
V_88 = F_32 ( V_27 , V_183 -> V_188 . V_189 ) ;
break;
case V_199 :
case V_200 :
case V_201 :
V_88 = - V_193 ;
if ( ! F_34 ( V_80 ) )
goto V_190;
V_88 = - V_89 ;
if ( V_3 == V_29 -> V_47 )
goto V_190;
V_88 = - V_77 ;
if ( F_33 ( & V_67 , V_183 -> V_188 . V_189 , sizeof( V_67 ) ) )
goto V_190;
V_88 = - V_119 ;
if ( ! ( V_27 = F_19 ( V_3 ) ) )
goto V_190;
switch ( V_184 ) {
case V_200 :
V_88 = F_47 ( V_27 , & V_67 ) ;
break;
case V_199 :
case V_201 :
V_88 = F_41 ( V_27 , & V_67 , V_184 == V_201 ) ;
break;
}
F_112 ( V_3 ) ;
break;
#ifdef F_18
case V_202 :
case V_203 :
case V_204 :
V_88 = - V_193 ;
if ( ! F_34 ( V_80 ) )
goto V_190;
V_88 = - V_77 ;
if ( F_33 ( & V_48 , V_183 -> V_188 . V_189 ,
sizeof( V_48 ) ) )
goto V_190;
V_27 = F_19 ( V_3 ) ;
if ( V_184 != V_204 ) {
struct V_105 V_49 ;
T_2 V_50 ;
V_88 = - V_89 ;
if ( V_48 . V_52 > 32 ||
V_48 . V_51 + ( 32 - V_48 . V_52 ) > 64 )
goto V_190;
F_114 ( & V_49 , & V_48 . V_49 ,
V_48 . V_51 ) ;
if ( ! F_115 ( & V_49 , & V_48 . V_49 ) )
goto V_190;
if ( V_48 . V_52 )
V_50 = V_48 . V_50 &
F_21 ( 0xffffffffUL <<
( 32 - V_48 . V_52 ) ) ;
else
V_50 = 0 ;
if ( V_50 != V_48 . V_50 )
goto V_190;
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
V_190:
return V_88 ;
}
static int F_116 ( struct V_2 * V_3 , int V_205 )
{
if ( V_205 < V_168 || V_205 > 0xFFF8 - sizeof( struct V_99 ) )
return - V_89 ;
V_3 -> V_154 = V_205 ;
return 0 ;
}
static void F_29 ( struct V_2 * V_3 )
{
F_117 ( V_3 -> V_7 ) ;
F_118 ( V_3 ) ;
}
static void V_59 ( struct V_2 * V_3 )
{
V_3 -> V_206 = & V_207 ;
V_3 -> V_208 = F_29 ;
V_3 -> type = V_209 ;
V_3 -> V_181 = V_210 + sizeof( struct V_99 ) ;
V_3 -> V_154 = V_211 - sizeof( struct V_99 ) ;
V_3 -> V_37 = V_212 ;
V_3 -> V_63 &= ~ V_213 ;
V_3 -> V_36 = 0 ;
V_3 -> V_214 = 4 ;
V_3 -> V_215 |= V_216 ;
V_3 -> V_215 |= V_217 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_21 * V_129 = F_19 ( V_3 ) ;
V_129 -> V_3 = V_3 ;
memcpy ( V_3 -> V_195 , & V_129 -> V_31 . V_32 . V_33 , 4 ) ;
memcpy ( V_3 -> V_196 , & V_129 -> V_31 . V_32 . V_34 , 4 ) ;
F_108 ( V_3 ) ;
V_3 -> V_7 = F_119 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_84 ;
return 0 ;
}
static int T_9 F_120 ( struct V_2 * V_3 )
{
struct V_21 * V_129 = F_19 ( V_3 ) ;
struct V_99 * V_32 = & V_129 -> V_31 . V_32 ;
struct V_22 * V_22 = F_55 ( V_3 ) ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
V_129 -> V_3 = V_3 ;
strcpy ( V_129 -> V_31 . V_56 , V_3 -> V_56 ) ;
V_32 -> V_177 = 4 ;
V_32 -> V_133 = V_122 ;
V_32 -> V_178 = 5 ;
V_32 -> V_123 = 64 ;
V_3 -> V_7 = F_119 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_84 ;
F_28 ( V_3 ) ;
F_15 ( V_29 -> V_39 [ 0 ] , V_129 ) ;
return 0 ;
}
static void T_10 F_121 ( struct V_28 * V_29 , struct V_218 * V_94 )
{
int V_42 ;
for ( V_42 = 1 ; V_42 < 4 ; V_42 ++ ) {
int V_41 ;
for ( V_41 = 0 ; V_41 < V_219 ; V_41 ++ ) {
struct V_21 * V_27 ;
V_27 = F_14 ( V_29 -> V_43 [ V_42 ] [ V_41 ] ) ;
while ( V_27 != NULL ) {
F_122 ( V_27 -> V_3 , V_94 ) ;
V_27 = F_14 ( V_27 -> V_46 ) ;
}
}
}
}
static int T_9 F_123 ( struct V_22 * V_22 )
{
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
struct V_21 * V_27 ;
int V_88 ;
V_29 -> V_43 [ 0 ] = V_29 -> V_39 ;
V_29 -> V_43 [ 1 ] = V_29 -> V_220 ;
V_29 -> V_43 [ 2 ] = V_29 -> V_221 ;
V_29 -> V_43 [ 3 ] = V_29 -> V_222 ;
V_29 -> V_47 = F_24 ( sizeof( struct V_21 ) , L_3 ,
V_59 ) ;
if ( ! V_29 -> V_47 ) {
V_88 = - V_84 ;
goto V_223;
}
F_25 ( V_29 -> V_47 , V_22 ) ;
V_88 = F_120 ( V_29 -> V_47 ) ;
if ( V_88 )
goto V_224;
F_17 ( V_29 -> V_47 , V_29 ) ;
if ( ( V_88 = F_124 ( V_29 -> V_47 ) ) )
goto V_225;
V_27 = F_19 ( V_29 -> V_47 ) ;
strcpy ( V_27 -> V_31 . V_56 , V_29 -> V_47 -> V_56 ) ;
return 0 ;
V_225:
F_57 ( V_29 -> V_47 ) ;
V_224:
F_29 ( V_29 -> V_47 ) ;
V_223:
return V_88 ;
}
static void T_10 F_125 ( struct V_22 * V_22 )
{
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
F_126 ( V_226 ) ;
F_127 () ;
F_121 ( V_29 , & V_226 ) ;
F_122 ( V_29 -> V_47 , & V_226 ) ;
F_128 ( & V_226 ) ;
F_129 () ;
}
static void T_11 F_130 ( void )
{
F_131 ( & V_227 , V_228 ) ;
F_132 ( & V_229 ) ;
F_133 () ;
}
static int T_12 F_134 ( void )
{
int V_88 ;
F_135 ( L_4 ) ;
V_88 = F_136 ( & V_229 ) ;
if ( V_88 < 0 )
return V_88 ;
V_88 = F_137 ( & V_227 , V_228 ) ;
if ( V_88 < 0 ) {
F_132 ( & V_229 ) ;
F_135 ( L_5 , V_230 ) ;
}
return V_88 ;
}
