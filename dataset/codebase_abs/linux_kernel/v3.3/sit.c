static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 V_5 = { 0 } ;
int V_6 ;
F_2 (i) {
const struct V_4 * V_7 = F_3 ( V_3 -> V_7 , V_6 ) ;
V_5 . V_8 += V_7 -> V_8 ;
V_5 . V_9 += V_7 -> V_9 ;
V_5 . V_10 += V_7 -> V_10 ;
V_5 . V_11 += V_7 -> V_11 ;
}
V_3 -> V_12 . V_8 = V_5 . V_8 ;
V_3 -> V_12 . V_9 = V_5 . V_9 ;
V_3 -> V_12 . V_10 = V_5 . V_10 ;
V_3 -> V_12 . V_11 = V_5 . V_11 ;
return & V_3 -> V_12 ;
}
static struct V_13 * F_4 ( struct V_14 * V_14 ,
struct V_2 * V_3 , T_1 V_15 , T_1 V_16 )
{
unsigned int V_17 = F_5 ( V_15 ) ;
unsigned int V_18 = F_5 ( V_16 ) ;
struct V_13 * V_19 ;
struct V_20 * V_21 = F_6 ( V_14 , V_22 ) ;
F_7 (sitn->tunnels_r_l[h0 ^ h1]) {
if ( V_16 == V_19 -> V_23 . V_24 . V_25 &&
V_15 == V_19 -> V_23 . V_24 . V_26 &&
( ! V_3 || ! V_19 -> V_23 . V_27 || V_3 -> V_28 == V_19 -> V_23 . V_27 ) &&
( V_19 -> V_3 -> V_29 & V_30 ) )
return V_19 ;
}
F_7 (sitn->tunnels_r[h0]) {
if ( V_15 == V_19 -> V_23 . V_24 . V_26 &&
( ! V_3 || ! V_19 -> V_23 . V_27 || V_3 -> V_28 == V_19 -> V_23 . V_27 ) &&
( V_19 -> V_3 -> V_29 & V_30 ) )
return V_19 ;
}
F_7 (sitn->tunnels_l[h1]) {
if ( V_16 == V_19 -> V_23 . V_24 . V_25 &&
( ! V_3 || ! V_19 -> V_23 . V_27 || V_3 -> V_28 == V_19 -> V_23 . V_27 ) &&
( V_19 -> V_3 -> V_29 & V_30 ) )
return V_19 ;
}
V_19 = F_8 ( V_21 -> V_31 [ 0 ] ) ;
if ( ( V_19 != NULL ) && ( V_19 -> V_3 -> V_29 & V_30 ) )
return V_19 ;
return NULL ;
}
static struct V_13 T_2 * * F_9 ( struct V_20 * V_21 ,
struct V_32 * V_23 )
{
T_1 V_15 = V_23 -> V_24 . V_26 ;
T_1 V_16 = V_23 -> V_24 . V_25 ;
unsigned int V_33 = 0 ;
int V_34 = 0 ;
if ( V_15 ) {
V_34 |= 2 ;
V_33 ^= F_5 ( V_15 ) ;
}
if ( V_16 ) {
V_34 |= 1 ;
V_33 ^= F_5 ( V_16 ) ;
}
return & V_21 -> V_35 [ V_34 ] [ V_33 ] ;
}
static inline struct V_13 T_2 * * F_10 ( struct V_20 * V_21 ,
struct V_13 * V_19 )
{
return F_9 ( V_21 , & V_19 -> V_23 ) ;
}
static void F_11 ( struct V_20 * V_21 , struct V_13 * V_19 )
{
struct V_13 T_2 * * V_36 ;
struct V_13 * V_37 ;
for ( V_36 = F_10 ( V_21 , V_19 ) ;
( V_37 = F_12 ( * V_36 ) ) != NULL ;
V_36 = & V_37 -> V_38 ) {
if ( V_19 == V_37 ) {
F_13 ( * V_36 , V_19 -> V_38 ) ;
break;
}
}
}
static void F_14 ( struct V_20 * V_21 , struct V_13 * V_19 )
{
struct V_13 T_2 * * V_36 = F_10 ( V_21 , V_19 ) ;
F_13 ( V_19 -> V_38 , F_12 ( * V_36 ) ) ;
F_13 ( * V_36 , V_19 ) ;
}
static void F_15 ( struct V_2 * V_3 , struct V_20 * V_21 )
{
#ifdef F_16
struct V_13 * V_19 = F_17 ( V_3 ) ;
if ( V_19 -> V_3 == V_21 -> V_39 ) {
F_18 ( & V_19 -> V_40 . V_41 , F_19 ( 0x20020000 ) , 0 , 0 , 0 ) ;
V_19 -> V_40 . V_42 = 0 ;
V_19 -> V_40 . V_43 = 16 ;
V_19 -> V_40 . V_44 = 0 ;
} else {
struct V_13 * V_45 = F_17 ( V_21 -> V_39 ) ;
memcpy ( & V_19 -> V_40 , & V_45 -> V_40 , sizeof( V_19 -> V_40 ) ) ;
}
#endif
}
static struct V_13 * F_20 ( struct V_14 * V_14 ,
struct V_32 * V_23 , int V_46 )
{
T_1 V_15 = V_23 -> V_24 . V_26 ;
T_1 V_16 = V_23 -> V_24 . V_25 ;
struct V_13 * V_19 , * V_47 ;
struct V_13 T_2 * * V_36 ;
struct V_2 * V_3 ;
char V_48 [ V_49 ] ;
struct V_20 * V_21 = F_6 ( V_14 , V_22 ) ;
for ( V_36 = F_9 ( V_21 , V_23 ) ;
( V_19 = F_12 ( * V_36 ) ) != NULL ;
V_36 = & V_19 -> V_38 ) {
if ( V_16 == V_19 -> V_23 . V_24 . V_25 &&
V_15 == V_19 -> V_23 . V_24 . V_26 &&
V_23 -> V_27 == V_19 -> V_23 . V_27 ) {
if ( V_46 )
return NULL ;
else
return V_19 ;
}
}
if ( ! V_46 )
goto V_50;
if ( V_23 -> V_48 [ 0 ] )
F_21 ( V_48 , V_23 -> V_48 , V_49 ) ;
else
strcpy ( V_48 , L_1 ) ;
V_3 = F_22 ( sizeof( * V_19 ) , V_48 , V_51 ) ;
if ( V_3 == NULL )
return NULL ;
F_23 ( V_3 , V_14 ) ;
V_47 = F_17 ( V_3 ) ;
V_47 -> V_23 = * V_23 ;
if ( F_24 ( V_3 ) < 0 )
goto V_52;
F_15 ( V_3 , V_21 ) ;
if ( V_23 -> V_53 & V_54 )
V_3 -> V_55 |= V_56 ;
if ( F_25 ( V_3 ) < 0 )
goto V_52;
strcpy ( V_47 -> V_23 . V_48 , V_3 -> V_48 ) ;
F_26 ( V_3 ) ;
F_14 ( V_21 , V_47 ) ;
return V_47 ;
V_52:
F_27 ( V_3 ) ;
V_50:
return NULL ;
}
static struct V_57 *
F_28 ( struct V_13 * V_19 , T_1 V_58 )
{
struct V_57 * V_59 ;
F_29 (t->prl)
if ( V_59 -> V_58 == V_58 )
break;
return V_59 ;
}
static int F_30 ( struct V_13 * V_19 ,
struct V_60 T_3 * V_61 )
{
struct V_60 V_62 , * V_63 ;
struct V_57 * V_59 ;
unsigned int V_64 , V_65 = 0 , V_66 , V_67 ;
int V_68 = 0 ;
if ( F_31 ( & V_62 , V_61 , sizeof( V_62 ) ) )
return - V_69 ;
V_64 = V_62 . V_70 / sizeof( V_62 ) ;
if ( V_64 > 1 && V_62 . V_58 != F_19 ( V_71 ) )
V_64 = 1 ;
V_63 = ( V_64 <= 1 || F_32 ( V_72 ) ) ?
F_33 ( V_64 , sizeof( * V_63 ) , V_73 ) :
NULL ;
F_34 () ;
V_66 = V_19 -> V_74 < V_64 ? V_19 -> V_74 : V_64 ;
if ( ! V_63 ) {
V_63 = F_33 ( V_66 , sizeof( * V_63 ) , V_75 ) ;
if ( ! V_63 ) {
V_68 = - V_76 ;
goto V_77;
}
}
V_65 = 0 ;
F_29 (t->prl) {
if ( V_65 >= V_64 )
break;
if ( V_62 . V_58 != F_19 ( V_71 ) && V_59 -> V_58 != V_62 . V_58 )
continue;
V_63 [ V_65 ] . V_58 = V_59 -> V_58 ;
V_63 [ V_65 ] . V_29 = V_59 -> V_29 ;
V_65 ++ ;
if ( V_62 . V_58 != F_19 ( V_71 ) )
break;
}
V_77:
F_35 () ;
V_67 = sizeof( * V_63 ) * V_65 ;
V_68 = 0 ;
if ( ( V_67 && F_36 ( V_61 + 1 , V_63 , V_67 ) ) || F_37 ( V_67 , & V_61 -> V_70 ) )
V_68 = - V_69 ;
F_38 ( V_63 ) ;
return V_68 ;
}
static int
F_39 ( struct V_13 * V_19 , struct V_60 * V_61 , int V_78 )
{
struct V_57 * V_79 ;
int V_80 = 0 ;
if ( V_61 -> V_58 == F_19 ( V_71 ) )
return - V_81 ;
F_40 () ;
for ( V_79 = F_12 ( V_19 -> V_59 ) ; V_79 ; V_79 = F_12 ( V_79 -> V_38 ) ) {
if ( V_79 -> V_58 == V_61 -> V_58 ) {
if ( V_78 ) {
V_79 -> V_29 = V_61 -> V_29 ;
goto V_77;
}
V_80 = - V_82 ;
goto V_77;
}
}
if ( V_78 ) {
V_80 = - V_83 ;
goto V_77;
}
V_79 = F_41 ( sizeof( struct V_57 ) , V_73 ) ;
if ( ! V_79 ) {
V_80 = - V_84 ;
goto V_77;
}
V_79 -> V_38 = V_19 -> V_59 ;
V_79 -> V_58 = V_61 -> V_58 ;
V_79 -> V_29 = V_61 -> V_29 ;
V_19 -> V_74 ++ ;
F_13 ( V_19 -> V_59 , V_79 ) ;
V_77:
return V_80 ;
}
static void F_42 ( struct V_85 * V_86 )
{
struct V_57 * V_79 , * V_87 ;
V_79 = F_43 ( V_86 , struct V_57 , V_85 ) ;
do {
V_87 = F_44 ( V_79 -> V_38 , 1 ) ;
F_38 ( V_79 ) ;
V_79 = V_87 ;
} while ( V_79 );
}
static int
F_45 ( struct V_13 * V_19 , struct V_60 * V_61 )
{
struct V_57 * V_88 ;
struct V_57 T_2 * * V_79 ;
int V_80 = 0 ;
F_40 () ;
if ( V_61 && V_61 -> V_58 != F_19 ( V_71 ) ) {
for ( V_79 = & V_19 -> V_59 ;
( V_88 = F_12 ( * V_79 ) ) != NULL ;
V_79 = & V_88 -> V_38 ) {
if ( V_88 -> V_58 == V_61 -> V_58 ) {
* V_79 = V_88 -> V_38 ;
F_46 ( V_88 , V_85 ) ;
V_19 -> V_74 -- ;
goto V_77;
}
}
V_80 = - V_83 ;
} else {
V_88 = F_12 ( V_19 -> V_59 ) ;
if ( V_88 ) {
V_19 -> V_74 = 0 ;
F_47 ( & V_88 -> V_85 , F_42 ) ;
V_19 -> V_59 = NULL ;
}
}
V_77:
return V_80 ;
}
static int
F_48 ( struct V_89 * V_90 , const struct V_91 * V_24 , struct V_13 * V_19 )
{
struct V_57 * V_79 ;
int V_92 = 1 ;
F_34 () ;
V_79 = F_28 ( V_19 , V_24 -> V_25 ) ;
if ( V_79 ) {
if ( V_79 -> V_29 & V_93 )
V_90 -> V_94 = V_95 ;
else
V_90 -> V_94 = V_96 ;
} else {
const struct V_97 * V_98 = & F_49 ( V_90 ) -> V_25 ;
if ( F_50 ( V_98 ) &&
( V_98 -> V_99 [ 3 ] == V_24 -> V_25 ) &&
F_51 ( V_98 , V_19 -> V_3 ) )
V_90 -> V_94 = V_100 ;
else
V_92 = 0 ;
}
F_35 () ;
return V_92 ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_53 ( V_3 ) ;
struct V_20 * V_21 = F_6 ( V_14 , V_22 ) ;
if ( V_3 == V_21 -> V_39 ) {
F_54 ( V_21 -> V_31 [ 0 ] , NULL ) ;
} else {
F_11 ( V_21 , F_17 ( V_3 ) ) ;
F_45 ( F_17 ( V_3 ) , NULL ) ;
}
F_55 ( V_3 ) ;
}
static int F_56 ( struct V_89 * V_90 , T_4 V_101 )
{
const struct V_91 * V_24 = ( const struct V_91 * ) V_90 -> V_102 ;
const int type = F_57 ( V_90 ) -> type ;
const int V_103 = F_57 ( V_90 ) -> V_103 ;
struct V_13 * V_19 ;
int V_80 ;
switch ( type ) {
default:
case V_104 :
return 0 ;
case V_105 :
switch ( V_103 ) {
case V_106 :
case V_107 :
return 0 ;
case V_108 :
return 0 ;
default:
break;
}
break;
case V_109 :
if ( V_103 != V_110 )
return 0 ;
break;
}
V_80 = - V_111 ;
F_34 () ;
V_19 = F_4 ( F_53 ( V_90 -> V_3 ) ,
V_90 -> V_3 ,
V_24 -> V_26 ,
V_24 -> V_25 ) ;
if ( V_19 == NULL || V_19 -> V_23 . V_24 . V_26 == 0 )
goto V_77;
V_80 = 0 ;
if ( V_19 -> V_23 . V_24 . V_112 == 0 && type == V_109 )
goto V_77;
if ( F_58 ( V_113 , V_19 -> V_114 + V_115 ) )
V_19 -> V_116 ++ ;
else
V_19 -> V_116 = 1 ;
V_19 -> V_114 = V_113 ;
V_77:
F_35 () ;
return V_80 ;
}
static inline void F_59 ( const struct V_91 * V_24 , struct V_89 * V_90 )
{
if ( F_60 ( V_24 -> V_117 ) )
F_61 ( F_49 ( V_90 ) ) ;
}
static int F_62 ( struct V_89 * V_90 )
{
const struct V_91 * V_24 ;
struct V_13 * V_118 ;
if ( ! F_63 ( V_90 , sizeof( struct V_119 ) ) )
goto V_77;
V_24 = F_64 ( V_90 ) ;
F_34 () ;
V_118 = F_4 ( F_53 ( V_90 -> V_3 ) , V_90 -> V_3 ,
V_24 -> V_25 , V_24 -> V_26 ) ;
if ( V_118 != NULL ) {
struct V_4 * V_7 ;
F_65 ( V_90 ) ;
V_90 -> V_120 = V_90 -> V_121 ;
F_66 ( V_90 ) ;
F_67 ( V_90 ) -> V_29 = 0 ;
V_90 -> V_122 = F_68 ( V_123 ) ;
V_90 -> V_124 = V_125 ;
if ( ( V_118 -> V_3 -> V_55 & V_56 ) &&
! F_48 ( V_90 , V_24 , V_118 ) ) {
V_118 -> V_3 -> V_12 . V_126 ++ ;
F_35 () ;
F_69 ( V_90 ) ;
return 0 ;
}
V_7 = F_70 ( V_118 -> V_3 -> V_7 ) ;
V_7 -> V_8 ++ ;
V_7 -> V_9 += V_90 -> V_67 ;
F_71 ( V_90 , V_118 -> V_3 ) ;
F_59 ( V_24 , V_90 ) ;
F_72 ( V_90 ) ;
F_35 () ;
return 0 ;
}
F_35 () ;
return 1 ;
V_77:
F_69 ( V_90 ) ;
return 0 ;
}
static inline
T_1 F_73 ( const struct V_97 * V_127 , struct V_13 * V_118 )
{
T_1 V_128 = 0 ;
#ifdef F_16
if ( F_74 ( V_127 , & V_118 -> V_40 . V_41 ,
V_118 -> V_40 . V_43 ) ) {
unsigned int V_129 , V_130 ;
int V_131 ;
T_4 V_132 ;
V_129 = V_118 -> V_40 . V_43 >> 5 ;
V_130 = V_118 -> V_40 . V_43 & 0x1f ;
V_132 = ( F_75 ( V_127 -> V_99 [ V_129 ] ) << V_130 ) >>
V_118 -> V_40 . V_44 ;
V_131 = V_130 - V_118 -> V_40 . V_44 ;
if ( V_131 > 0 )
V_132 |= F_75 ( V_127 -> V_99 [ V_129 + 1 ] ) >>
( 32 - V_131 ) ;
V_128 = V_118 -> V_40 . V_42 | F_19 ( V_132 ) ;
}
#else
if ( V_127 -> V_133 [ 0 ] == F_68 ( 0x2002 ) ) {
memcpy ( & V_128 , & V_127 -> V_133 [ 1 ] , 4 ) ;
}
#endif
return V_128 ;
}
static T_5 F_76 ( struct V_89 * V_90 ,
struct V_2 * V_3 )
{
struct V_13 * V_118 = F_17 ( V_3 ) ;
struct V_4 * V_7 ;
const struct V_91 * V_134 = & V_118 -> V_23 . V_24 ;
const struct V_119 * V_135 = F_49 ( V_90 ) ;
T_6 V_117 = V_118 -> V_23 . V_24 . V_117 ;
T_7 V_136 = V_134 -> V_137 ;
struct V_138 * V_139 ;
struct V_2 * V_140 ;
struct V_91 * V_24 ;
unsigned int V_141 ;
T_1 V_128 = V_134 -> V_26 ;
struct V_142 V_143 ;
int V_144 ;
const struct V_97 * V_98 ;
int V_145 ;
if ( V_90 -> V_122 != F_68 ( V_123 ) )
goto V_146;
if ( V_117 == 1 )
V_117 = F_77 ( V_135 ) ;
if ( V_3 -> V_55 & V_56 ) {
struct V_147 * V_148 = NULL ;
if ( F_78 ( V_90 ) )
V_148 = F_79 ( F_78 ( V_90 ) ) ;
if ( V_148 == NULL ) {
if ( F_80 () )
F_81 ( V_149 L_2 ) ;
goto V_146;
}
V_98 = ( const struct V_97 * ) & V_148 -> V_150 ;
V_145 = F_82 ( V_98 ) ;
if ( ( V_145 & V_151 ) &&
F_50 ( V_98 ) )
V_128 = V_98 -> V_99 [ 3 ] ;
else
goto V_146;
}
if ( ! V_128 )
V_128 = F_73 ( & V_135 -> V_26 , V_118 ) ;
if ( ! V_128 ) {
struct V_147 * V_148 = NULL ;
if ( F_78 ( V_90 ) )
V_148 = F_79 ( F_78 ( V_90 ) ) ;
if ( V_148 == NULL ) {
if ( F_80 () )
F_81 ( V_149 L_2 ) ;
goto V_146;
}
V_98 = ( const struct V_97 * ) & V_148 -> V_150 ;
V_145 = F_82 ( V_98 ) ;
if ( V_145 == V_152 ) {
V_98 = & F_49 ( V_90 ) -> V_26 ;
V_145 = F_82 ( V_98 ) ;
}
if ( ( V_145 & V_153 ) == 0 )
goto V_154;
V_128 = V_98 -> V_99 [ 3 ] ;
}
V_139 = F_83 ( F_53 ( V_3 ) , & V_143 , NULL ,
V_128 , V_134 -> V_25 ,
0 , 0 ,
V_155 , F_84 ( V_117 ) ,
V_118 -> V_23 . V_27 ) ;
if ( F_85 ( V_139 ) ) {
V_3 -> V_12 . V_156 ++ ;
goto V_154;
}
if ( V_139 -> V_157 != V_158 ) {
F_86 ( V_139 ) ;
V_3 -> V_12 . V_156 ++ ;
goto V_154;
}
V_140 = V_139 -> V_128 . V_3 ;
if ( V_140 == V_3 ) {
F_86 ( V_139 ) ;
V_3 -> V_12 . V_159 ++ ;
goto V_146;
}
if ( V_136 ) {
V_144 = F_87 ( & V_139 -> V_128 ) - sizeof( struct V_91 ) ;
if ( V_144 < 68 ) {
V_3 -> V_12 . V_159 ++ ;
F_86 ( V_139 ) ;
goto V_146;
}
if ( V_144 < V_160 ) {
V_144 = V_160 ;
V_136 = 0 ;
}
if ( V_118 -> V_23 . V_24 . V_26 && F_78 ( V_90 ) )
F_78 ( V_90 ) -> V_161 -> V_162 ( F_78 ( V_90 ) , V_144 ) ;
if ( V_90 -> V_67 > V_144 ) {
F_88 ( V_90 , V_163 , 0 , V_144 ) ;
F_86 ( V_139 ) ;
goto V_146;
}
}
if ( V_118 -> V_116 > 0 ) {
if ( F_58 ( V_113 ,
V_118 -> V_114 + V_115 ) ) {
V_118 -> V_116 -- ;
F_89 ( V_90 ) ;
} else
V_118 -> V_116 = 0 ;
}
V_141 = F_90 ( V_140 ) + sizeof( struct V_91 ) ;
if ( F_91 ( V_90 ) < V_141 || F_92 ( V_90 ) ||
( F_93 ( V_90 ) && ! F_94 ( V_90 , 0 ) ) ) {
struct V_89 * V_164 = F_95 ( V_90 , V_141 ) ;
if ( ! V_164 ) {
F_86 ( V_139 ) ;
V_3 -> V_12 . V_165 ++ ;
F_96 ( V_90 ) ;
return V_166 ;
}
if ( V_90 -> V_167 )
F_97 ( V_164 , V_90 -> V_167 ) ;
F_96 ( V_90 ) ;
V_90 = V_164 ;
V_135 = F_49 ( V_90 ) ;
}
V_90 -> V_168 = V_90 -> V_121 ;
F_98 ( V_90 , sizeof( struct V_91 ) ) ;
F_66 ( V_90 ) ;
memset ( & ( F_67 ( V_90 ) -> V_169 ) , 0 , sizeof( F_67 ( V_90 ) -> V_169 ) ) ;
F_67 ( V_90 ) -> V_29 = 0 ;
F_99 ( V_90 ) ;
F_100 ( V_90 , & V_139 -> V_128 ) ;
V_24 = F_64 ( V_90 ) ;
V_24 -> V_170 = 4 ;
V_24 -> V_171 = sizeof( struct V_91 ) >> 2 ;
V_24 -> V_137 = V_136 ;
V_24 -> V_122 = V_155 ;
V_24 -> V_117 = F_101 ( V_117 , F_77 ( V_135 ) ) ;
V_24 -> V_26 = V_143 . V_26 ;
V_24 -> V_25 = V_143 . V_25 ;
if ( ( V_24 -> V_112 = V_134 -> V_112 ) == 0 )
V_24 -> V_112 = V_135 -> V_172 ;
F_102 ( V_90 ) ;
V_7 = F_70 ( V_3 -> V_7 ) ;
F_103 ( V_7 , & V_3 -> V_12 ) ;
return V_166 ;
V_154:
F_89 ( V_90 ) ;
V_146:
V_3 -> V_12 . V_173 ++ ;
F_96 ( V_90 ) ;
return V_166 ;
}
static void F_104 ( struct V_2 * V_3 )
{
struct V_2 * V_140 = NULL ;
struct V_13 * V_118 ;
const struct V_91 * V_24 ;
struct V_142 V_143 ;
V_118 = F_17 ( V_3 ) ;
V_24 = & V_118 -> V_23 . V_24 ;
if ( V_24 -> V_26 ) {
struct V_138 * V_139 = F_83 ( F_53 ( V_3 ) , & V_143 , NULL ,
V_24 -> V_26 , V_24 -> V_25 ,
0 , 0 ,
V_155 ,
F_84 ( V_24 -> V_117 ) ,
V_118 -> V_23 . V_27 ) ;
if ( ! F_85 ( V_139 ) ) {
V_140 = V_139 -> V_128 . V_3 ;
F_86 ( V_139 ) ;
}
V_3 -> V_29 |= V_174 ;
}
if ( ! V_140 && V_118 -> V_23 . V_27 )
V_140 = F_105 ( F_53 ( V_3 ) , V_118 -> V_23 . V_27 ) ;
if ( V_140 ) {
V_3 -> V_175 = V_140 -> V_175 + sizeof( struct V_91 ) ;
V_3 -> V_144 = V_140 -> V_144 - sizeof( struct V_91 ) ;
if ( V_3 -> V_144 < V_160 )
V_3 -> V_144 = V_160 ;
}
V_3 -> V_28 = V_118 -> V_23 . V_27 ;
}
static int
F_106 ( struct V_2 * V_3 , struct V_176 * V_177 , int V_178 )
{
int V_80 = 0 ;
struct V_32 V_79 ;
struct V_60 V_59 ;
struct V_13 * V_19 ;
struct V_14 * V_14 = F_53 ( V_3 ) ;
struct V_20 * V_21 = F_6 ( V_14 , V_22 ) ;
#ifdef F_16
struct V_179 V_40 ;
#endif
switch ( V_178 ) {
case V_180 :
#ifdef F_16
case V_181 :
#endif
V_19 = NULL ;
if ( V_3 == V_21 -> V_39 ) {
if ( F_31 ( & V_79 , V_177 -> V_182 . V_183 , sizeof( V_79 ) ) ) {
V_80 = - V_69 ;
break;
}
V_19 = F_20 ( V_14 , & V_79 , 0 ) ;
}
if ( V_19 == NULL )
V_19 = F_17 ( V_3 ) ;
V_80 = - V_69 ;
if ( V_178 == V_180 ) {
memcpy ( & V_79 , & V_19 -> V_23 , sizeof( V_79 ) ) ;
if ( F_36 ( V_177 -> V_182 . V_183 , & V_79 ,
sizeof( V_79 ) ) )
goto V_184;
#ifdef F_16
} else {
V_40 . V_41 = V_19 -> V_40 . V_41 ;
V_40 . V_42 = V_19 -> V_40 . V_42 ;
V_40 . V_43 = V_19 -> V_40 . V_43 ;
V_40 . V_44 = V_19 -> V_40 . V_44 ;
if ( F_36 ( V_177 -> V_182 . V_183 , & V_40 ,
sizeof( V_40 ) ) )
goto V_184;
#endif
}
V_80 = 0 ;
break;
case V_185 :
case V_186 :
V_80 = - V_187 ;
if ( ! F_32 ( V_72 ) )
goto V_184;
V_80 = - V_69 ;
if ( F_31 ( & V_79 , V_177 -> V_182 . V_183 , sizeof( V_79 ) ) )
goto V_184;
V_80 = - V_81 ;
if ( V_79 . V_24 . V_170 != 4 || V_79 . V_24 . V_122 != V_155 ||
V_79 . V_24 . V_171 != 5 || ( V_79 . V_24 . V_137 & F_68 ( ~ V_188 ) ) )
goto V_184;
if ( V_79 . V_24 . V_112 )
V_79 . V_24 . V_137 |= F_68 ( V_188 ) ;
V_19 = F_20 ( V_14 , & V_79 , V_178 == V_185 ) ;
if ( V_3 != V_21 -> V_39 && V_178 == V_186 ) {
if ( V_19 != NULL ) {
if ( V_19 -> V_3 != V_3 ) {
V_80 = - V_82 ;
break;
}
} else {
if ( ( ( V_3 -> V_29 & V_174 ) && ! V_79 . V_24 . V_26 ) ||
( ! ( V_3 -> V_29 & V_174 ) && V_79 . V_24 . V_26 ) ) {
V_80 = - V_81 ;
break;
}
V_19 = F_17 ( V_3 ) ;
F_11 ( V_21 , V_19 ) ;
F_107 () ;
V_19 -> V_23 . V_24 . V_25 = V_79 . V_24 . V_25 ;
V_19 -> V_23 . V_24 . V_26 = V_79 . V_24 . V_26 ;
memcpy ( V_3 -> V_189 , & V_79 . V_24 . V_25 , 4 ) ;
memcpy ( V_3 -> V_190 , & V_79 . V_24 . V_26 , 4 ) ;
F_14 ( V_21 , V_19 ) ;
F_108 ( V_3 ) ;
}
}
if ( V_19 ) {
V_80 = 0 ;
if ( V_178 == V_186 ) {
V_19 -> V_23 . V_24 . V_112 = V_79 . V_24 . V_112 ;
V_19 -> V_23 . V_24 . V_117 = V_79 . V_24 . V_117 ;
if ( V_19 -> V_23 . V_27 != V_79 . V_27 ) {
V_19 -> V_23 . V_27 = V_79 . V_27 ;
F_104 ( V_3 ) ;
F_108 ( V_3 ) ;
}
}
if ( F_36 ( V_177 -> V_182 . V_183 , & V_19 -> V_23 , sizeof( V_79 ) ) )
V_80 = - V_69 ;
} else
V_80 = ( V_178 == V_185 ? - V_84 : - V_111 ) ;
break;
case V_191 :
V_80 = - V_187 ;
if ( ! F_32 ( V_72 ) )
goto V_184;
if ( V_3 == V_21 -> V_39 ) {
V_80 = - V_69 ;
if ( F_31 ( & V_79 , V_177 -> V_182 . V_183 , sizeof( V_79 ) ) )
goto V_184;
V_80 = - V_111 ;
if ( ( V_19 = F_20 ( V_14 , & V_79 , 0 ) ) == NULL )
goto V_184;
V_80 = - V_187 ;
if ( V_19 == F_17 ( V_21 -> V_39 ) )
goto V_184;
V_3 = V_19 -> V_3 ;
}
F_109 ( V_3 ) ;
V_80 = 0 ;
break;
case V_192 :
V_80 = - V_81 ;
if ( V_3 == V_21 -> V_39 )
goto V_184;
V_80 = - V_111 ;
if ( ! ( V_19 = F_17 ( V_3 ) ) )
goto V_184;
V_80 = F_30 ( V_19 , V_177 -> V_182 . V_183 ) ;
break;
case V_193 :
case V_194 :
case V_195 :
V_80 = - V_187 ;
if ( ! F_32 ( V_72 ) )
goto V_184;
V_80 = - V_81 ;
if ( V_3 == V_21 -> V_39 )
goto V_184;
V_80 = - V_69 ;
if ( F_31 ( & V_59 , V_177 -> V_182 . V_183 , sizeof( V_59 ) ) )
goto V_184;
V_80 = - V_111 ;
if ( ! ( V_19 = F_17 ( V_3 ) ) )
goto V_184;
switch ( V_178 ) {
case V_194 :
V_80 = F_45 ( V_19 , & V_59 ) ;
break;
case V_193 :
case V_195 :
V_80 = F_39 ( V_19 , & V_59 , V_178 == V_195 ) ;
break;
}
F_108 ( V_3 ) ;
break;
#ifdef F_16
case V_196 :
case V_197 :
case V_198 :
V_80 = - V_187 ;
if ( ! F_32 ( V_72 ) )
goto V_184;
V_80 = - V_69 ;
if ( F_31 ( & V_40 , V_177 -> V_182 . V_183 ,
sizeof( V_40 ) ) )
goto V_184;
V_19 = F_17 ( V_3 ) ;
if ( V_178 != V_198 ) {
struct V_97 V_41 ;
T_1 V_42 ;
V_80 = - V_81 ;
if ( V_40 . V_44 > 32 ||
V_40 . V_43 + ( 32 - V_40 . V_44 ) > 64 )
goto V_184;
F_110 ( & V_41 , & V_40 . V_41 ,
V_40 . V_43 ) ;
if ( ! F_111 ( & V_41 , & V_40 . V_41 ) )
goto V_184;
if ( V_40 . V_44 )
V_42 = V_40 . V_42 &
F_19 ( 0xffffffffUL <<
( 32 - V_40 . V_44 ) ) ;
else
V_42 = 0 ;
if ( V_42 != V_40 . V_42 )
goto V_184;
V_19 -> V_40 . V_41 = V_41 ;
V_19 -> V_40 . V_42 = V_42 ;
V_19 -> V_40 . V_43 = V_40 . V_43 ;
V_19 -> V_40 . V_44 = V_40 . V_44 ;
} else
F_15 ( V_3 , V_21 ) ;
V_80 = 0 ;
break;
#endif
default:
V_80 = - V_81 ;
}
V_184:
return V_80 ;
}
static int F_112 ( struct V_2 * V_3 , int V_199 )
{
if ( V_199 < V_160 || V_199 > 0xFFF8 - sizeof( struct V_91 ) )
return - V_81 ;
V_3 -> V_144 = V_199 ;
return 0 ;
}
static void F_27 ( struct V_2 * V_3 )
{
F_113 ( V_3 -> V_7 ) ;
F_114 ( V_3 ) ;
}
static void V_51 ( struct V_2 * V_3 )
{
V_3 -> V_200 = & V_201 ;
V_3 -> V_202 = F_27 ;
V_3 -> type = V_203 ;
V_3 -> V_175 = V_204 + sizeof( struct V_91 ) ;
V_3 -> V_144 = V_205 - sizeof( struct V_91 ) ;
V_3 -> V_29 = V_206 ;
V_3 -> V_55 &= ~ V_207 ;
V_3 -> V_28 = 0 ;
V_3 -> V_208 = 4 ;
V_3 -> V_209 |= V_210 ;
V_3 -> V_209 |= V_211 ;
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_13 * V_118 = F_17 ( V_3 ) ;
V_118 -> V_3 = V_3 ;
memcpy ( V_3 -> V_189 , & V_118 -> V_23 . V_24 . V_25 , 4 ) ;
memcpy ( V_3 -> V_190 , & V_118 -> V_23 . V_24 . V_26 , 4 ) ;
F_104 ( V_3 ) ;
V_3 -> V_7 = F_115 ( struct V_4 ) ;
if ( ! V_3 -> V_7 )
return - V_76 ;
return 0 ;
}
static int T_8 F_116 ( struct V_2 * V_3 )
{
struct V_13 * V_118 = F_17 ( V_3 ) ;
struct V_91 * V_24 = & V_118 -> V_23 . V_24 ;
struct V_14 * V_14 = F_53 ( V_3 ) ;
struct V_20 * V_21 = F_6 ( V_14 , V_22 ) ;
V_118 -> V_3 = V_3 ;
strcpy ( V_118 -> V_23 . V_48 , V_3 -> V_48 ) ;
V_24 -> V_170 = 4 ;
V_24 -> V_122 = V_155 ;
V_24 -> V_171 = 5 ;
V_24 -> V_112 = 64 ;
V_3 -> V_7 = F_115 ( struct V_4 ) ;
if ( ! V_3 -> V_7 )
return - V_76 ;
F_26 ( V_3 ) ;
F_13 ( V_21 -> V_31 [ 0 ] , V_118 ) ;
return 0 ;
}
static void T_9 F_117 ( struct V_20 * V_21 , struct V_212 * V_86 )
{
int V_34 ;
for ( V_34 = 1 ; V_34 < 4 ; V_34 ++ ) {
int V_33 ;
for ( V_33 = 0 ; V_33 < V_213 ; V_33 ++ ) {
struct V_13 * V_19 ;
V_19 = F_12 ( V_21 -> V_35 [ V_34 ] [ V_33 ] ) ;
while ( V_19 != NULL ) {
F_118 ( V_19 -> V_3 , V_86 ) ;
V_19 = F_12 ( V_19 -> V_38 ) ;
}
}
}
}
static int T_8 F_119 ( struct V_14 * V_14 )
{
struct V_20 * V_21 = F_6 ( V_14 , V_22 ) ;
struct V_13 * V_19 ;
int V_80 ;
V_21 -> V_35 [ 0 ] = V_21 -> V_31 ;
V_21 -> V_35 [ 1 ] = V_21 -> V_214 ;
V_21 -> V_35 [ 2 ] = V_21 -> V_215 ;
V_21 -> V_35 [ 3 ] = V_21 -> V_216 ;
V_21 -> V_39 = F_22 ( sizeof( struct V_13 ) , L_3 ,
V_51 ) ;
if ( ! V_21 -> V_39 ) {
V_80 = - V_76 ;
goto V_217;
}
F_23 ( V_21 -> V_39 , V_14 ) ;
V_80 = F_116 ( V_21 -> V_39 ) ;
if ( V_80 )
goto V_218;
F_15 ( V_21 -> V_39 , V_21 ) ;
if ( ( V_80 = F_120 ( V_21 -> V_39 ) ) )
goto V_219;
V_19 = F_17 ( V_21 -> V_39 ) ;
strcpy ( V_19 -> V_23 . V_48 , V_21 -> V_39 -> V_48 ) ;
return 0 ;
V_219:
F_55 ( V_21 -> V_39 ) ;
V_218:
F_27 ( V_21 -> V_39 ) ;
V_217:
return V_80 ;
}
static void T_9 F_121 ( struct V_14 * V_14 )
{
struct V_20 * V_21 = F_6 ( V_14 , V_22 ) ;
F_122 ( V_220 ) ;
F_123 () ;
F_117 ( V_21 , & V_220 ) ;
F_118 ( V_21 -> V_39 , & V_220 ) ;
F_124 ( & V_220 ) ;
F_125 () ;
}
static void T_10 F_126 ( void )
{
F_127 ( & V_221 , V_222 ) ;
F_128 ( & V_223 ) ;
F_129 () ;
}
static int T_11 F_130 ( void )
{
int V_80 ;
F_81 ( V_224 L_4 ) ;
V_80 = F_131 ( & V_223 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 = F_132 ( & V_221 , V_222 ) ;
if ( V_80 < 0 ) {
F_128 ( & V_223 ) ;
F_81 ( V_224 L_5 ) ;
}
return V_80 ;
}
