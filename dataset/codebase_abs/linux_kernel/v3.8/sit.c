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
V_4 -> V_21 = V_3 -> V_15 . V_21 ;
return V_4 ;
}
static struct V_22 * F_6 ( struct V_23 * V_23 ,
struct V_2 * V_3 , T_2 V_24 , T_2 V_25 )
{
unsigned int V_26 = F_7 ( V_24 ) ;
unsigned int V_27 = F_7 ( V_25 ) ;
struct V_22 * V_28 ;
struct V_29 * V_30 = F_8 ( V_23 , V_31 ) ;
F_9 (t, sitn->tunnels_r_l[h0 ^ h1]) {
if ( V_25 == V_28 -> V_32 . V_33 . V_34 &&
V_24 == V_28 -> V_32 . V_33 . V_35 &&
( ! V_3 || ! V_28 -> V_32 . V_36 || V_3 -> V_37 == V_28 -> V_32 . V_36 ) &&
( V_28 -> V_3 -> V_38 & V_39 ) )
return V_28 ;
}
F_9 (t, sitn->tunnels_r[h0]) {
if ( V_24 == V_28 -> V_32 . V_33 . V_35 &&
( ! V_3 || ! V_28 -> V_32 . V_36 || V_3 -> V_37 == V_28 -> V_32 . V_36 ) &&
( V_28 -> V_3 -> V_38 & V_39 ) )
return V_28 ;
}
F_9 (t, sitn->tunnels_l[h1]) {
if ( V_25 == V_28 -> V_32 . V_33 . V_34 &&
( ! V_3 || ! V_28 -> V_32 . V_36 || V_3 -> V_37 == V_28 -> V_32 . V_36 ) &&
( V_28 -> V_3 -> V_38 & V_39 ) )
return V_28 ;
}
V_28 = F_10 ( V_30 -> V_40 [ 0 ] ) ;
if ( ( V_28 != NULL ) && ( V_28 -> V_3 -> V_38 & V_39 ) )
return V_28 ;
return NULL ;
}
static struct V_22 T_3 * * F_11 ( struct V_29 * V_30 ,
struct V_41 * V_32 )
{
T_2 V_24 = V_32 -> V_33 . V_35 ;
T_2 V_25 = V_32 -> V_33 . V_34 ;
unsigned int V_42 = 0 ;
int V_43 = 0 ;
if ( V_24 ) {
V_43 |= 2 ;
V_42 ^= F_7 ( V_24 ) ;
}
if ( V_25 ) {
V_43 |= 1 ;
V_42 ^= F_7 ( V_25 ) ;
}
return & V_30 -> V_44 [ V_43 ] [ V_42 ] ;
}
static inline struct V_22 T_3 * * F_12 ( struct V_29 * V_30 ,
struct V_22 * V_28 )
{
return F_11 ( V_30 , & V_28 -> V_32 ) ;
}
static void F_13 ( struct V_29 * V_30 , struct V_22 * V_28 )
{
struct V_22 T_3 * * V_45 ;
struct V_22 * V_46 ;
for ( V_45 = F_12 ( V_30 , V_28 ) ;
( V_46 = F_14 ( * V_45 ) ) != NULL ;
V_45 = & V_46 -> V_47 ) {
if ( V_28 == V_46 ) {
F_15 ( * V_45 , V_28 -> V_47 ) ;
break;
}
}
}
static void F_16 ( struct V_29 * V_30 , struct V_22 * V_28 )
{
struct V_22 T_3 * * V_45 = F_12 ( V_30 , V_28 ) ;
F_15 ( V_28 -> V_47 , F_14 ( * V_45 ) ) ;
F_15 ( * V_45 , V_28 ) ;
}
static void F_17 ( struct V_2 * V_3 , struct V_29 * V_30 )
{
#ifdef F_18
struct V_22 * V_28 = F_19 ( V_3 ) ;
if ( V_28 -> V_3 == V_30 -> V_48 ) {
F_20 ( & V_28 -> V_49 . V_50 , F_21 ( 0x20020000 ) , 0 , 0 , 0 ) ;
V_28 -> V_49 . V_51 = 0 ;
V_28 -> V_49 . V_52 = 16 ;
V_28 -> V_49 . V_53 = 0 ;
} else {
struct V_22 * V_54 = F_19 ( V_30 -> V_48 ) ;
memcpy ( & V_28 -> V_49 , & V_54 -> V_49 , sizeof( V_28 -> V_49 ) ) ;
}
#endif
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_22 * V_28 = F_19 ( V_3 ) ;
struct V_23 * V_23 = F_23 ( V_3 ) ;
struct V_29 * V_30 = F_8 ( V_23 , V_31 ) ;
int V_55 ;
V_55 = F_24 ( V_3 ) ;
if ( V_55 < 0 )
goto V_56;
F_17 ( V_3 , V_30 ) ;
if ( ( V_57 V_58 ) V_28 -> V_32 . V_59 & V_60 )
V_3 -> V_61 |= V_62 ;
V_55 = F_25 ( V_3 ) ;
if ( V_55 < 0 )
goto V_56;
strcpy ( V_28 -> V_32 . V_63 , V_3 -> V_63 ) ;
V_3 -> V_64 = & V_65 ;
F_26 ( V_3 ) ;
F_16 ( V_30 , V_28 ) ;
return 0 ;
V_56:
return V_55 ;
}
static struct V_22 * F_27 ( struct V_23 * V_23 ,
struct V_41 * V_32 , int V_66 )
{
T_2 V_24 = V_32 -> V_33 . V_35 ;
T_2 V_25 = V_32 -> V_33 . V_34 ;
struct V_22 * V_28 , * V_67 ;
struct V_22 T_3 * * V_45 ;
struct V_2 * V_3 ;
char V_63 [ V_68 ] ;
struct V_29 * V_30 = F_8 ( V_23 , V_31 ) ;
for ( V_45 = F_11 ( V_30 , V_32 ) ;
( V_28 = F_14 ( * V_45 ) ) != NULL ;
V_45 = & V_28 -> V_47 ) {
if ( V_25 == V_28 -> V_32 . V_33 . V_34 &&
V_24 == V_28 -> V_32 . V_33 . V_35 &&
V_32 -> V_36 == V_28 -> V_32 . V_36 ) {
if ( V_66 )
return NULL ;
else
return V_28 ;
}
}
if ( ! V_66 )
goto V_69;
if ( V_32 -> V_63 [ 0 ] )
F_28 ( V_63 , V_32 -> V_63 , V_68 ) ;
else
strcpy ( V_63 , L_1 ) ;
V_3 = F_29 ( sizeof( * V_28 ) , V_63 , V_70 ) ;
if ( V_3 == NULL )
return NULL ;
F_30 ( V_3 , V_23 ) ;
V_67 = F_19 ( V_3 ) ;
V_67 -> V_32 = * V_32 ;
if ( F_22 ( V_3 ) < 0 )
goto V_71;
return V_67 ;
V_71:
F_31 ( V_3 ) ;
V_69:
return NULL ;
}
static struct V_72 *
F_32 ( struct V_22 * V_28 , T_2 V_73 )
{
struct V_72 * V_74 ;
F_33 (t->prl)
if ( V_74 -> V_73 == V_73 )
break;
return V_74 ;
}
static int F_34 ( struct V_22 * V_28 ,
struct V_75 T_4 * V_76 )
{
struct V_75 V_77 , * V_78 ;
struct V_72 * V_74 ;
unsigned int V_79 , V_80 = 0 , V_81 , V_82 ;
int V_83 = 0 ;
if ( F_35 ( & V_77 , V_76 , sizeof( V_77 ) ) )
return - V_84 ;
V_79 = V_77 . V_85 / sizeof( V_77 ) ;
if ( V_79 > 1 && V_77 . V_73 != F_21 ( V_86 ) )
V_79 = 1 ;
V_78 = ( V_79 <= 1 || F_36 ( V_87 ) ) ?
F_37 ( V_79 , sizeof( * V_78 ) , V_88 ) :
NULL ;
F_38 () ;
V_81 = V_28 -> V_89 < V_79 ? V_28 -> V_89 : V_79 ;
if ( ! V_78 ) {
V_78 = F_37 ( V_81 , sizeof( * V_78 ) , V_90 ) ;
if ( ! V_78 ) {
V_83 = - V_91 ;
goto V_56;
}
}
V_80 = 0 ;
F_33 (t->prl) {
if ( V_80 >= V_79 )
break;
if ( V_77 . V_73 != F_21 ( V_86 ) && V_74 -> V_73 != V_77 . V_73 )
continue;
V_78 [ V_80 ] . V_73 = V_74 -> V_73 ;
V_78 [ V_80 ] . V_38 = V_74 -> V_38 ;
V_80 ++ ;
if ( V_77 . V_73 != F_21 ( V_86 ) )
break;
}
V_56:
F_39 () ;
V_82 = sizeof( * V_78 ) * V_80 ;
V_83 = 0 ;
if ( ( V_82 && F_40 ( V_76 + 1 , V_78 , V_82 ) ) || F_41 ( V_82 , & V_76 -> V_85 ) )
V_83 = - V_84 ;
F_42 ( V_78 ) ;
return V_83 ;
}
static int
F_43 ( struct V_22 * V_28 , struct V_75 * V_76 , int V_92 )
{
struct V_72 * V_93 ;
int V_55 = 0 ;
if ( V_76 -> V_73 == F_21 ( V_86 ) )
return - V_94 ;
F_44 () ;
for ( V_93 = F_14 ( V_28 -> V_74 ) ; V_93 ; V_93 = F_14 ( V_93 -> V_47 ) ) {
if ( V_93 -> V_73 == V_76 -> V_73 ) {
if ( V_92 ) {
V_93 -> V_38 = V_76 -> V_38 ;
goto V_56;
}
V_55 = - V_95 ;
goto V_56;
}
}
if ( V_92 ) {
V_55 = - V_96 ;
goto V_56;
}
V_93 = F_45 ( sizeof( struct V_72 ) , V_88 ) ;
if ( ! V_93 ) {
V_55 = - V_97 ;
goto V_56;
}
V_93 -> V_47 = V_28 -> V_74 ;
V_93 -> V_73 = V_76 -> V_73 ;
V_93 -> V_38 = V_76 -> V_38 ;
V_28 -> V_89 ++ ;
F_15 ( V_28 -> V_74 , V_93 ) ;
V_56:
return V_55 ;
}
static void F_46 ( struct V_98 * V_99 )
{
struct V_72 * V_93 , * V_100 ;
V_93 = F_47 ( V_99 , struct V_72 , V_98 ) ;
do {
V_100 = F_48 ( V_93 -> V_47 , 1 ) ;
F_42 ( V_93 ) ;
V_93 = V_100 ;
} while ( V_93 );
}
static int
F_49 ( struct V_22 * V_28 , struct V_75 * V_76 )
{
struct V_72 * V_101 ;
struct V_72 T_3 * * V_93 ;
int V_55 = 0 ;
F_44 () ;
if ( V_76 && V_76 -> V_73 != F_21 ( V_86 ) ) {
for ( V_93 = & V_28 -> V_74 ;
( V_101 = F_14 ( * V_93 ) ) != NULL ;
V_93 = & V_101 -> V_47 ) {
if ( V_101 -> V_73 == V_76 -> V_73 ) {
* V_93 = V_101 -> V_47 ;
F_50 ( V_101 , V_98 ) ;
V_28 -> V_89 -- ;
goto V_56;
}
}
V_55 = - V_96 ;
} else {
V_101 = F_14 ( V_28 -> V_74 ) ;
if ( V_101 ) {
V_28 -> V_89 = 0 ;
F_51 ( & V_101 -> V_98 , F_46 ) ;
V_28 -> V_74 = NULL ;
}
}
V_56:
return V_55 ;
}
static int
F_52 ( struct V_102 * V_103 , const struct V_104 * V_33 , struct V_22 * V_28 )
{
struct V_72 * V_93 ;
int V_105 = 1 ;
F_38 () ;
V_93 = F_32 ( V_28 , V_33 -> V_34 ) ;
if ( V_93 ) {
if ( V_93 -> V_38 & V_106 )
V_103 -> V_107 = V_108 ;
else
V_103 -> V_107 = V_109 ;
} else {
const struct V_110 * V_111 = & F_53 ( V_103 ) -> V_34 ;
if ( F_54 ( V_111 ) &&
( V_111 -> V_112 [ 3 ] == V_33 -> V_34 ) &&
F_55 ( V_111 , V_28 -> V_3 ) )
V_103 -> V_107 = V_113 ;
else
V_105 = 0 ;
}
F_39 () ;
return V_105 ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_23 * V_23 = F_23 ( V_3 ) ;
struct V_29 * V_30 = F_8 ( V_23 , V_31 ) ;
if ( V_3 == V_30 -> V_48 ) {
F_57 ( V_30 -> V_40 [ 0 ] , NULL ) ;
} else {
F_13 ( V_30 , F_19 ( V_3 ) ) ;
F_49 ( F_19 ( V_3 ) , NULL ) ;
}
F_58 ( V_3 ) ;
}
static int F_59 ( struct V_102 * V_103 , T_5 V_114 )
{
const struct V_104 * V_33 = ( const struct V_104 * ) V_103 -> V_115 ;
const int type = F_60 ( V_103 ) -> type ;
const int V_116 = F_60 ( V_103 ) -> V_116 ;
struct V_22 * V_28 ;
int V_55 ;
switch ( type ) {
default:
case V_117 :
return 0 ;
case V_118 :
switch ( V_116 ) {
case V_119 :
case V_120 :
return 0 ;
default:
break;
}
break;
case V_121 :
if ( V_116 != V_122 )
return 0 ;
break;
case V_123 :
break;
}
V_55 = - V_124 ;
V_28 = F_6 ( F_23 ( V_103 -> V_3 ) ,
V_103 -> V_3 ,
V_33 -> V_35 ,
V_33 -> V_34 ) ;
if ( V_28 == NULL )
goto V_56;
if ( type == V_118 && V_116 == V_125 ) {
F_61 ( V_103 , F_23 ( V_103 -> V_3 ) , V_114 ,
V_28 -> V_3 -> V_126 , 0 , V_127 , 0 ) ;
V_55 = 0 ;
goto V_56;
}
if ( type == V_123 ) {
F_62 ( V_103 , F_23 ( V_103 -> V_3 ) , V_28 -> V_3 -> V_126 , 0 ,
V_127 , 0 ) ;
V_55 = 0 ;
goto V_56;
}
if ( V_28 -> V_32 . V_33 . V_35 == 0 )
goto V_56;
V_55 = 0 ;
if ( V_28 -> V_32 . V_33 . V_128 == 0 && type == V_121 )
goto V_56;
if ( F_63 ( V_129 , V_28 -> V_130 + V_131 ) )
V_28 -> V_132 ++ ;
else
V_28 -> V_132 = 1 ;
V_28 -> V_130 = V_129 ;
V_56:
return V_55 ;
}
static int F_64 ( struct V_102 * V_103 )
{
const struct V_104 * V_33 ;
struct V_22 * V_133 ;
int V_55 ;
if ( ! F_65 ( V_103 , sizeof( struct V_134 ) ) )
goto V_56;
V_33 = F_66 ( V_103 ) ;
V_133 = F_6 ( F_23 ( V_103 -> V_3 ) , V_103 -> V_3 ,
V_33 -> V_34 , V_33 -> V_35 ) ;
if ( V_133 != NULL ) {
struct V_6 * V_7 ;
F_67 ( V_103 ) ;
V_103 -> V_135 = V_103 -> V_136 ;
F_68 ( V_103 ) ;
F_69 ( V_103 ) -> V_38 = 0 ;
V_103 -> V_137 = F_70 ( V_138 ) ;
V_103 -> V_139 = V_140 ;
if ( ( V_133 -> V_3 -> V_61 & V_62 ) &&
! F_52 ( V_103 , V_33 , V_133 ) ) {
V_133 -> V_3 -> V_15 . V_14 ++ ;
goto V_56;
}
F_71 ( V_103 , V_133 -> V_3 ) ;
V_55 = F_72 ( V_33 , V_103 ) ;
if ( F_73 ( V_55 ) ) {
if ( V_141 )
F_74 ( L_2 ,
& V_33 -> V_34 , V_33 -> V_142 ) ;
if ( V_55 > 1 ) {
++ V_133 -> V_3 -> V_15 . V_16 ;
++ V_133 -> V_3 -> V_15 . V_14 ;
goto V_56;
}
}
V_7 = F_75 ( V_133 -> V_3 -> V_7 ) ;
V_7 -> V_8 ++ ;
V_7 -> V_9 += V_103 -> V_82 ;
F_76 ( V_103 ) ;
return 0 ;
}
return 1 ;
V_56:
F_77 ( V_103 ) ;
return 0 ;
}
static inline
T_2 F_78 ( const struct V_110 * V_143 , struct V_22 * V_133 )
{
T_2 V_144 = 0 ;
#ifdef F_18
if ( F_79 ( V_143 , & V_133 -> V_49 . V_50 ,
V_133 -> V_49 . V_52 ) ) {
unsigned int V_145 , V_146 ;
int V_147 ;
T_5 V_148 ;
V_145 = V_133 -> V_49 . V_52 >> 5 ;
V_146 = V_133 -> V_49 . V_52 & 0x1f ;
V_148 = ( F_80 ( V_143 -> V_112 [ V_145 ] ) << V_146 ) >>
V_133 -> V_49 . V_53 ;
V_147 = V_146 - V_133 -> V_49 . V_53 ;
if ( V_147 > 0 )
V_148 |= F_80 ( V_143 -> V_112 [ V_145 + 1 ] ) >>
( 32 - V_147 ) ;
V_144 = V_133 -> V_49 . V_51 | F_21 ( V_148 ) ;
}
#else
if ( V_143 -> V_149 [ 0 ] == F_70 ( 0x2002 ) ) {
memcpy ( & V_144 , & V_143 -> V_149 [ 1 ] , 4 ) ;
}
#endif
return V_144 ;
}
static T_6 F_81 ( struct V_102 * V_103 ,
struct V_2 * V_3 )
{
struct V_22 * V_133 = F_19 ( V_3 ) ;
const struct V_104 * V_150 = & V_133 -> V_32 . V_33 ;
const struct V_134 * V_151 = F_53 ( V_103 ) ;
T_7 V_142 = V_133 -> V_32 . V_33 . V_142 ;
T_8 V_152 = V_150 -> V_153 ;
struct V_154 * V_155 ;
struct V_2 * V_156 ;
struct V_104 * V_33 ;
unsigned int V_157 ;
T_2 V_144 = V_150 -> V_35 ;
struct V_158 V_159 ;
int V_160 ;
const struct V_110 * V_111 ;
int V_161 ;
if ( V_103 -> V_137 != F_70 ( V_138 ) )
goto V_162;
if ( V_142 == 1 )
V_142 = F_82 ( V_151 ) ;
if ( V_3 -> V_61 & V_62 ) {
struct V_163 * V_164 = NULL ;
bool V_165 = false ;
if ( F_83 ( V_103 ) )
V_164 = F_84 ( F_83 ( V_103 ) , & V_151 -> V_35 ) ;
if ( V_164 == NULL ) {
F_85 ( L_3 ) ;
goto V_162;
}
V_111 = ( const struct V_110 * ) & V_164 -> V_166 ;
V_161 = F_86 ( V_111 ) ;
if ( ( V_161 & V_167 ) &&
F_54 ( V_111 ) )
V_144 = V_111 -> V_112 [ 3 ] ;
else
V_165 = true ;
F_87 ( V_164 ) ;
if ( V_165 )
goto V_162;
}
if ( ! V_144 )
V_144 = F_78 ( & V_151 -> V_35 , V_133 ) ;
if ( ! V_144 ) {
struct V_163 * V_164 = NULL ;
bool V_165 = false ;
if ( F_83 ( V_103 ) )
V_164 = F_84 ( F_83 ( V_103 ) , & V_151 -> V_35 ) ;
if ( V_164 == NULL ) {
F_85 ( L_3 ) ;
goto V_162;
}
V_111 = ( const struct V_110 * ) & V_164 -> V_166 ;
V_161 = F_86 ( V_111 ) ;
if ( V_161 == V_168 ) {
V_111 = & F_53 ( V_103 ) -> V_35 ;
V_161 = F_86 ( V_111 ) ;
}
if ( ( V_161 & V_169 ) != 0 )
V_144 = V_111 -> V_112 [ 3 ] ;
else
V_165 = true ;
F_87 ( V_164 ) ;
if ( V_165 )
goto V_162;
}
V_155 = F_88 ( F_23 ( V_3 ) , & V_159 , NULL ,
V_144 , V_150 -> V_34 ,
0 , 0 ,
V_127 , F_89 ( V_142 ) ,
V_133 -> V_32 . V_36 ) ;
if ( F_90 ( V_155 ) ) {
V_3 -> V_15 . V_18 ++ ;
goto V_170;
}
if ( V_155 -> V_171 != V_172 ) {
F_91 ( V_155 ) ;
V_3 -> V_15 . V_18 ++ ;
goto V_170;
}
V_156 = V_155 -> V_144 . V_3 ;
if ( V_156 == V_3 ) {
F_91 ( V_155 ) ;
V_3 -> V_15 . V_173 ++ ;
goto V_162;
}
if ( V_152 ) {
V_160 = F_92 ( & V_155 -> V_144 ) - sizeof( struct V_104 ) ;
if ( V_160 < 68 ) {
V_3 -> V_15 . V_173 ++ ;
F_91 ( V_155 ) ;
goto V_162;
}
if ( V_160 < V_174 ) {
V_160 = V_174 ;
V_152 = 0 ;
}
if ( V_133 -> V_32 . V_33 . V_35 && F_83 ( V_103 ) )
F_83 ( V_103 ) -> V_175 -> V_176 ( F_83 ( V_103 ) , NULL , V_103 , V_160 ) ;
if ( V_103 -> V_82 > V_160 ) {
F_93 ( V_103 , V_177 , 0 , V_160 ) ;
F_91 ( V_155 ) ;
goto V_162;
}
}
if ( V_133 -> V_132 > 0 ) {
if ( F_63 ( V_129 ,
V_133 -> V_130 + V_131 ) ) {
V_133 -> V_132 -- ;
F_94 ( V_103 ) ;
} else
V_133 -> V_132 = 0 ;
}
V_157 = F_95 ( V_156 ) + sizeof( struct V_104 ) ;
if ( F_96 ( V_103 ) < V_157 || F_97 ( V_103 ) ||
( F_98 ( V_103 ) && ! F_99 ( V_103 , 0 ) ) ) {
struct V_102 * V_178 = F_100 ( V_103 , V_157 ) ;
if ( ! V_178 ) {
F_91 ( V_155 ) ;
V_3 -> V_15 . V_19 ++ ;
F_101 ( V_103 ) ;
return V_179 ;
}
if ( V_103 -> V_180 )
F_102 ( V_178 , V_103 -> V_180 ) ;
F_101 ( V_103 ) ;
V_103 = V_178 ;
V_151 = F_53 ( V_103 ) ;
}
V_103 -> V_181 = V_103 -> V_136 ;
F_103 ( V_103 , sizeof( struct V_104 ) ) ;
F_68 ( V_103 ) ;
memset ( & ( F_69 ( V_103 ) -> V_182 ) , 0 , sizeof( F_69 ( V_103 ) -> V_182 ) ) ;
F_69 ( V_103 ) -> V_38 = 0 ;
F_104 ( V_103 ) ;
F_105 ( V_103 , & V_155 -> V_144 ) ;
V_33 = F_66 ( V_103 ) ;
V_33 -> V_183 = 4 ;
V_33 -> V_184 = sizeof( struct V_104 ) >> 2 ;
V_33 -> V_153 = V_152 ;
V_33 -> V_137 = V_127 ;
V_33 -> V_142 = F_106 ( V_142 , F_82 ( V_151 ) ) ;
V_33 -> V_35 = V_159 . V_35 ;
V_33 -> V_34 = V_159 . V_34 ;
if ( ( V_33 -> V_128 = V_150 -> V_128 ) == 0 )
V_33 -> V_128 = V_151 -> V_185 ;
F_107 ( V_103 , V_3 ) ;
return V_179 ;
V_170:
F_94 ( V_103 ) ;
V_162:
V_3 -> V_15 . V_21 ++ ;
F_101 ( V_103 ) ;
return V_179 ;
}
static void F_108 ( struct V_2 * V_3 )
{
struct V_2 * V_156 = NULL ;
struct V_22 * V_133 ;
const struct V_104 * V_33 ;
struct V_158 V_159 ;
V_133 = F_19 ( V_3 ) ;
V_33 = & V_133 -> V_32 . V_33 ;
if ( V_33 -> V_35 ) {
struct V_154 * V_155 = F_88 ( F_23 ( V_3 ) , & V_159 , NULL ,
V_33 -> V_35 , V_33 -> V_34 ,
0 , 0 ,
V_127 ,
F_89 ( V_33 -> V_142 ) ,
V_133 -> V_32 . V_36 ) ;
if ( ! F_90 ( V_155 ) ) {
V_156 = V_155 -> V_144 . V_3 ;
F_91 ( V_155 ) ;
}
V_3 -> V_38 |= V_186 ;
}
if ( ! V_156 && V_133 -> V_32 . V_36 )
V_156 = F_109 ( F_23 ( V_3 ) , V_133 -> V_32 . V_36 ) ;
if ( V_156 ) {
V_3 -> V_187 = V_156 -> V_187 + sizeof( struct V_104 ) ;
V_3 -> V_160 = V_156 -> V_160 - sizeof( struct V_104 ) ;
if ( V_3 -> V_160 < V_174 )
V_3 -> V_160 = V_174 ;
}
V_3 -> V_37 = V_133 -> V_32 . V_36 ;
}
static void F_110 ( struct V_22 * V_28 , struct V_41 * V_93 )
{
struct V_23 * V_23 = F_23 ( V_28 -> V_3 ) ;
struct V_29 * V_30 = F_8 ( V_23 , V_31 ) ;
F_13 ( V_30 , V_28 ) ;
F_111 () ;
V_28 -> V_32 . V_33 . V_34 = V_93 -> V_33 . V_34 ;
V_28 -> V_32 . V_33 . V_35 = V_93 -> V_33 . V_35 ;
memcpy ( V_28 -> V_3 -> V_188 , & V_93 -> V_33 . V_34 , 4 ) ;
memcpy ( V_28 -> V_3 -> V_189 , & V_93 -> V_33 . V_35 , 4 ) ;
F_16 ( V_30 , V_28 ) ;
V_28 -> V_32 . V_33 . V_128 = V_93 -> V_33 . V_128 ;
V_28 -> V_32 . V_33 . V_142 = V_93 -> V_33 . V_142 ;
if ( V_28 -> V_32 . V_36 != V_93 -> V_36 ) {
V_28 -> V_32 . V_36 = V_93 -> V_36 ;
F_108 ( V_28 -> V_3 ) ;
}
F_112 ( V_28 -> V_3 ) ;
}
static int F_113 ( struct V_22 * V_28 ,
struct V_190 * V_49 )
{
struct V_110 V_50 ;
T_2 V_51 ;
if ( V_49 -> V_53 > 32 ||
V_49 -> V_52 + ( 32 - V_49 -> V_53 ) > 64 )
return - V_94 ;
F_114 ( & V_50 , & V_49 -> V_50 , V_49 -> V_52 ) ;
if ( ! F_115 ( & V_50 , & V_49 -> V_50 ) )
return - V_94 ;
if ( V_49 -> V_53 )
V_51 = V_49 -> V_51 &
F_21 ( 0xffffffffUL <<
( 32 - V_49 -> V_53 ) ) ;
else
V_51 = 0 ;
if ( V_51 != V_49 -> V_51 )
return - V_94 ;
V_28 -> V_49 . V_50 = V_50 ;
V_28 -> V_49 . V_51 = V_51 ;
V_28 -> V_49 . V_52 = V_49 -> V_52 ;
V_28 -> V_49 . V_53 = V_49 -> V_53 ;
F_112 ( V_28 -> V_3 ) ;
return 0 ;
}
static int
F_116 ( struct V_2 * V_3 , struct V_191 * V_192 , int V_193 )
{
int V_55 = 0 ;
struct V_41 V_93 ;
struct V_75 V_74 ;
struct V_22 * V_28 ;
struct V_23 * V_23 = F_23 ( V_3 ) ;
struct V_29 * V_30 = F_8 ( V_23 , V_31 ) ;
#ifdef F_18
struct V_190 V_49 ;
#endif
switch ( V_193 ) {
case V_194 :
#ifdef F_18
case V_195 :
#endif
V_28 = NULL ;
if ( V_3 == V_30 -> V_48 ) {
if ( F_35 ( & V_93 , V_192 -> V_196 . V_197 , sizeof( V_93 ) ) ) {
V_55 = - V_84 ;
break;
}
V_28 = F_27 ( V_23 , & V_93 , 0 ) ;
}
if ( V_28 == NULL )
V_28 = F_19 ( V_3 ) ;
V_55 = - V_84 ;
if ( V_193 == V_194 ) {
memcpy ( & V_93 , & V_28 -> V_32 , sizeof( V_93 ) ) ;
if ( F_40 ( V_192 -> V_196 . V_197 , & V_93 ,
sizeof( V_93 ) ) )
goto V_198;
#ifdef F_18
} else {
V_49 . V_50 = V_28 -> V_49 . V_50 ;
V_49 . V_51 = V_28 -> V_49 . V_51 ;
V_49 . V_52 = V_28 -> V_49 . V_52 ;
V_49 . V_53 = V_28 -> V_49 . V_53 ;
if ( F_40 ( V_192 -> V_196 . V_197 , & V_49 ,
sizeof( V_49 ) ) )
goto V_198;
#endif
}
V_55 = 0 ;
break;
case V_199 :
case V_200 :
V_55 = - V_201 ;
if ( ! F_117 ( V_23 -> V_202 , V_87 ) )
goto V_198;
V_55 = - V_84 ;
if ( F_35 ( & V_93 , V_192 -> V_196 . V_197 , sizeof( V_93 ) ) )
goto V_198;
V_55 = - V_94 ;
if ( V_93 . V_33 . V_183 != 4 || V_93 . V_33 . V_137 != V_127 ||
V_93 . V_33 . V_184 != 5 || ( V_93 . V_33 . V_153 & F_70 ( ~ V_203 ) ) )
goto V_198;
if ( V_93 . V_33 . V_128 )
V_93 . V_33 . V_153 |= F_70 ( V_203 ) ;
V_28 = F_27 ( V_23 , & V_93 , V_193 == V_199 ) ;
if ( V_3 != V_30 -> V_48 && V_193 == V_200 ) {
if ( V_28 != NULL ) {
if ( V_28 -> V_3 != V_3 ) {
V_55 = - V_95 ;
break;
}
} else {
if ( ( ( V_3 -> V_38 & V_186 ) && ! V_93 . V_33 . V_35 ) ||
( ! ( V_3 -> V_38 & V_186 ) && V_93 . V_33 . V_35 ) ) {
V_55 = - V_94 ;
break;
}
V_28 = F_19 ( V_3 ) ;
}
F_110 ( V_28 , & V_93 ) ;
}
if ( V_28 ) {
V_55 = 0 ;
if ( F_40 ( V_192 -> V_196 . V_197 , & V_28 -> V_32 , sizeof( V_93 ) ) )
V_55 = - V_84 ;
} else
V_55 = ( V_193 == V_199 ? - V_97 : - V_124 ) ;
break;
case V_204 :
V_55 = - V_201 ;
if ( ! F_117 ( V_23 -> V_202 , V_87 ) )
goto V_198;
if ( V_3 == V_30 -> V_48 ) {
V_55 = - V_84 ;
if ( F_35 ( & V_93 , V_192 -> V_196 . V_197 , sizeof( V_93 ) ) )
goto V_198;
V_55 = - V_124 ;
if ( ( V_28 = F_27 ( V_23 , & V_93 , 0 ) ) == NULL )
goto V_198;
V_55 = - V_201 ;
if ( V_28 == F_19 ( V_30 -> V_48 ) )
goto V_198;
V_3 = V_28 -> V_3 ;
}
F_118 ( V_3 ) ;
V_55 = 0 ;
break;
case V_205 :
V_55 = - V_94 ;
if ( V_3 == V_30 -> V_48 )
goto V_198;
V_55 = - V_124 ;
if ( ! ( V_28 = F_19 ( V_3 ) ) )
goto V_198;
V_55 = F_34 ( V_28 , V_192 -> V_196 . V_197 ) ;
break;
case V_206 :
case V_207 :
case V_208 :
V_55 = - V_201 ;
if ( ! F_117 ( V_23 -> V_202 , V_87 ) )
goto V_198;
V_55 = - V_94 ;
if ( V_3 == V_30 -> V_48 )
goto V_198;
V_55 = - V_84 ;
if ( F_35 ( & V_74 , V_192 -> V_196 . V_197 , sizeof( V_74 ) ) )
goto V_198;
V_55 = - V_124 ;
if ( ! ( V_28 = F_19 ( V_3 ) ) )
goto V_198;
switch ( V_193 ) {
case V_207 :
V_55 = F_49 ( V_28 , & V_74 ) ;
break;
case V_206 :
case V_208 :
V_55 = F_43 ( V_28 , & V_74 , V_193 == V_208 ) ;
break;
}
F_112 ( V_3 ) ;
break;
#ifdef F_18
case V_209 :
case V_210 :
case V_211 :
V_55 = - V_201 ;
if ( ! F_117 ( V_23 -> V_202 , V_87 ) )
goto V_198;
V_55 = - V_84 ;
if ( F_35 ( & V_49 , V_192 -> V_196 . V_197 ,
sizeof( V_49 ) ) )
goto V_198;
V_28 = F_19 ( V_3 ) ;
if ( V_193 != V_211 ) {
V_55 = F_113 ( V_28 , & V_49 ) ;
if ( V_55 < 0 )
goto V_198;
} else
F_17 ( V_3 , V_30 ) ;
V_55 = 0 ;
break;
#endif
default:
V_55 = - V_94 ;
}
V_198:
return V_55 ;
}
static int F_119 ( struct V_2 * V_3 , int V_212 )
{
if ( V_212 < V_174 || V_212 > 0xFFF8 - sizeof( struct V_104 ) )
return - V_94 ;
V_3 -> V_160 = V_212 ;
return 0 ;
}
static void F_31 ( struct V_2 * V_3 )
{
F_120 ( V_3 -> V_7 ) ;
F_121 ( V_3 ) ;
}
static void V_70 ( struct V_2 * V_3 )
{
V_3 -> V_213 = & V_214 ;
V_3 -> V_215 = F_31 ;
V_3 -> type = V_216 ;
V_3 -> V_187 = V_217 + sizeof( struct V_104 ) ;
V_3 -> V_160 = V_218 - sizeof( struct V_104 ) ;
V_3 -> V_38 = V_219 ;
V_3 -> V_61 &= ~ V_220 ;
V_3 -> V_37 = 0 ;
V_3 -> V_221 = 4 ;
V_3 -> V_222 |= V_223 ;
V_3 -> V_222 |= V_224 ;
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_22 * V_133 = F_19 ( V_3 ) ;
V_133 -> V_3 = V_3 ;
memcpy ( V_3 -> V_188 , & V_133 -> V_32 . V_33 . V_34 , 4 ) ;
memcpy ( V_3 -> V_189 , & V_133 -> V_32 . V_33 . V_35 , 4 ) ;
F_108 ( V_3 ) ;
V_3 -> V_7 = F_122 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_91 ;
return 0 ;
}
static int T_9 F_123 ( struct V_2 * V_3 )
{
struct V_22 * V_133 = F_19 ( V_3 ) ;
struct V_104 * V_33 = & V_133 -> V_32 . V_33 ;
struct V_23 * V_23 = F_23 ( V_3 ) ;
struct V_29 * V_30 = F_8 ( V_23 , V_31 ) ;
V_133 -> V_3 = V_3 ;
strcpy ( V_133 -> V_32 . V_63 , V_3 -> V_63 ) ;
V_33 -> V_183 = 4 ;
V_33 -> V_137 = V_127 ;
V_33 -> V_184 = 5 ;
V_33 -> V_128 = 64 ;
V_3 -> V_7 = F_122 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_91 ;
F_26 ( V_3 ) ;
F_15 ( V_30 -> V_40 [ 0 ] , V_133 ) ;
return 0 ;
}
static void F_124 ( struct V_225 * V_115 [] ,
struct V_41 * V_32 )
{
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
V_32 -> V_33 . V_183 = 4 ;
V_32 -> V_33 . V_137 = V_127 ;
V_32 -> V_33 . V_184 = 5 ;
V_32 -> V_33 . V_128 = 64 ;
if ( ! V_115 )
return;
if ( V_115 [ V_226 ] )
V_32 -> V_36 = F_125 ( V_115 [ V_226 ] ) ;
if ( V_115 [ V_227 ] )
V_32 -> V_33 . V_34 = F_126 ( V_115 [ V_227 ] ) ;
if ( V_115 [ V_228 ] )
V_32 -> V_33 . V_35 = F_126 ( V_115 [ V_228 ] ) ;
if ( V_115 [ V_229 ] ) {
V_32 -> V_33 . V_128 = F_127 ( V_115 [ V_229 ] ) ;
if ( V_32 -> V_33 . V_128 )
V_32 -> V_33 . V_153 = F_70 ( V_203 ) ;
}
if ( V_115 [ V_230 ] )
V_32 -> V_33 . V_142 = F_127 ( V_115 [ V_230 ] ) ;
if ( ! V_115 [ V_231 ] || F_127 ( V_115 [ V_231 ] ) )
V_32 -> V_33 . V_153 = F_70 ( V_203 ) ;
if ( V_115 [ V_232 ] )
V_32 -> V_59 = F_128 ( V_115 [ V_232 ] ) ;
}
static bool F_129 ( struct V_225 * V_115 [] ,
struct V_190 * V_49 )
{
bool V_83 = false ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
if ( ! V_115 )
return V_83 ;
if ( V_115 [ V_233 ] ) {
V_83 = true ;
F_130 ( & V_49 -> V_50 , V_115 [ V_233 ] ,
sizeof( struct V_110 ) ) ;
}
if ( V_115 [ V_234 ] ) {
V_83 = true ;
V_49 -> V_51 =
F_126 ( V_115 [ V_234 ] ) ;
}
if ( V_115 [ V_235 ] ) {
V_83 = true ;
V_49 -> V_52 = F_131 ( V_115 [ V_235 ] ) ;
}
if ( V_115 [ V_236 ] ) {
V_83 = true ;
V_49 -> V_53 =
F_131 ( V_115 [ V_236 ] ) ;
}
return V_83 ;
}
static int F_132 ( struct V_23 * V_237 , struct V_2 * V_3 ,
struct V_225 * V_238 [] , struct V_225 * V_115 [] )
{
struct V_23 * V_23 = F_23 ( V_3 ) ;
struct V_22 * V_67 ;
#ifdef F_18
struct V_190 V_49 ;
#endif
int V_55 ;
V_67 = F_19 ( V_3 ) ;
F_124 ( V_115 , & V_67 -> V_32 ) ;
if ( F_27 ( V_23 , & V_67 -> V_32 , 0 ) )
return - V_95 ;
V_55 = F_22 ( V_3 ) ;
if ( V_55 < 0 )
return V_55 ;
#ifdef F_18
if ( F_129 ( V_115 , & V_49 ) )
V_55 = F_113 ( V_67 , & V_49 ) ;
#endif
return V_55 ;
}
static int F_133 ( struct V_2 * V_3 , struct V_225 * V_238 [] ,
struct V_225 * V_115 [] )
{
struct V_22 * V_28 ;
struct V_41 V_93 ;
struct V_23 * V_23 = F_23 ( V_3 ) ;
struct V_29 * V_30 = F_8 ( V_23 , V_31 ) ;
#ifdef F_18
struct V_190 V_49 ;
#endif
if ( V_3 == V_30 -> V_48 )
return - V_94 ;
F_124 ( V_115 , & V_93 ) ;
if ( ( ( V_3 -> V_38 & V_186 ) && ! V_93 . V_33 . V_35 ) ||
( ! ( V_3 -> V_38 & V_186 ) && V_93 . V_33 . V_35 ) )
return - V_94 ;
V_28 = F_27 ( V_23 , & V_93 , 0 ) ;
if ( V_28 ) {
if ( V_28 -> V_3 != V_3 )
return - V_95 ;
} else
V_28 = F_19 ( V_3 ) ;
F_110 ( V_28 , & V_93 ) ;
#ifdef F_18
if ( F_129 ( V_115 , & V_49 ) )
return F_113 ( V_28 , & V_49 ) ;
#endif
return 0 ;
}
static T_10 F_134 ( const struct V_2 * V_3 )
{
return
F_135 ( 4 ) +
F_135 ( 4 ) +
F_135 ( 4 ) +
F_135 ( 1 ) +
F_135 ( 1 ) +
F_135 ( 1 ) +
F_135 ( 2 ) +
#ifdef F_18
F_135 ( sizeof( struct V_110 ) ) +
F_135 ( 4 ) +
F_135 ( 2 ) +
F_135 ( 2 ) +
#endif
0 ;
}
static int F_136 ( struct V_102 * V_103 , const struct V_2 * V_3 )
{
struct V_22 * V_133 = F_19 ( V_3 ) ;
struct V_41 * V_239 = & V_133 -> V_32 ;
if ( F_137 ( V_103 , V_226 , V_239 -> V_36 ) ||
F_138 ( V_103 , V_227 , V_239 -> V_33 . V_34 ) ||
F_138 ( V_103 , V_228 , V_239 -> V_33 . V_35 ) ||
F_139 ( V_103 , V_229 , V_239 -> V_33 . V_128 ) ||
F_139 ( V_103 , V_230 , V_239 -> V_33 . V_142 ) ||
F_139 ( V_103 , V_231 ,
! ! ( V_239 -> V_33 . V_153 & F_70 ( V_203 ) ) ) ||
F_140 ( V_103 , V_232 , V_239 -> V_59 ) )
goto V_240;
#ifdef F_18
if ( F_141 ( V_103 , V_233 , sizeof( struct V_110 ) ,
& V_133 -> V_49 . V_50 ) ||
F_138 ( V_103 , V_234 ,
V_133 -> V_49 . V_51 ) ||
F_142 ( V_103 , V_235 ,
V_133 -> V_49 . V_52 ) ||
F_142 ( V_103 , V_236 ,
V_133 -> V_49 . V_53 ) )
goto V_240;
#endif
return 0 ;
V_240:
return - V_241 ;
}
static void T_11 F_143 ( struct V_29 * V_30 , struct V_242 * V_99 )
{
int V_43 ;
for ( V_43 = 1 ; V_43 < 4 ; V_43 ++ ) {
int V_42 ;
for ( V_42 = 0 ; V_42 < V_243 ; V_42 ++ ) {
struct V_22 * V_28 ;
V_28 = F_14 ( V_30 -> V_44 [ V_43 ] [ V_42 ] ) ;
while ( V_28 != NULL ) {
F_144 ( V_28 -> V_3 , V_99 ) ;
V_28 = F_14 ( V_28 -> V_47 ) ;
}
}
}
}
static int T_9 F_145 ( struct V_23 * V_23 )
{
struct V_29 * V_30 = F_8 ( V_23 , V_31 ) ;
struct V_22 * V_28 ;
int V_55 ;
V_30 -> V_44 [ 0 ] = V_30 -> V_40 ;
V_30 -> V_44 [ 1 ] = V_30 -> V_244 ;
V_30 -> V_44 [ 2 ] = V_30 -> V_245 ;
V_30 -> V_44 [ 3 ] = V_30 -> V_246 ;
V_30 -> V_48 = F_29 ( sizeof( struct V_22 ) , L_4 ,
V_70 ) ;
if ( ! V_30 -> V_48 ) {
V_55 = - V_91 ;
goto V_247;
}
F_30 ( V_30 -> V_48 , V_23 ) ;
V_55 = F_123 ( V_30 -> V_48 ) ;
if ( V_55 )
goto V_248;
F_17 ( V_30 -> V_48 , V_30 ) ;
if ( ( V_55 = F_146 ( V_30 -> V_48 ) ) )
goto V_249;
V_28 = F_19 ( V_30 -> V_48 ) ;
strcpy ( V_28 -> V_32 . V_63 , V_30 -> V_48 -> V_63 ) ;
return 0 ;
V_249:
F_58 ( V_30 -> V_48 ) ;
V_248:
F_31 ( V_30 -> V_48 ) ;
V_247:
return V_55 ;
}
static void T_11 F_147 ( struct V_23 * V_23 )
{
struct V_29 * V_30 = F_8 ( V_23 , V_31 ) ;
F_148 ( V_250 ) ;
F_149 () ;
F_143 ( V_30 , & V_250 ) ;
F_144 ( V_30 -> V_48 , & V_250 ) ;
F_150 ( & V_250 ) ;
F_151 () ;
}
static void T_12 F_152 ( void )
{
F_153 ( & V_65 ) ;
F_154 ( & V_251 , V_252 ) ;
F_155 ( & V_253 ) ;
F_156 () ;
}
static int T_13 F_157 ( void )
{
int V_55 ;
F_158 ( L_5 ) ;
V_55 = F_159 ( & V_253 ) ;
if ( V_55 < 0 )
return V_55 ;
V_55 = F_160 ( & V_251 , V_252 ) ;
if ( V_55 < 0 ) {
F_158 ( L_6 , V_254 ) ;
goto V_255;
}
V_55 = F_161 ( & V_65 ) ;
if ( V_55 < 0 )
goto V_256;
V_56:
return V_55 ;
V_256:
F_154 ( & V_251 , V_252 ) ;
V_255:
F_155 ( & V_253 ) ;
goto V_56;
}
