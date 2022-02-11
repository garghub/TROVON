static struct V_1 * F_1 ( struct V_2 * V_3 )
{
F_2 ( F_3 ( struct V_2 , V_4 ) != 0 ) ;
F_2 ( F_3 ( struct V_2 , V_5 ) !=
F_3 ( struct V_2 , V_4 ) + sizeof( V_3 -> V_4 ) ) ;
F_2 ( F_3 ( struct V_2 , V_6 ) !=
F_3 ( struct V_2 , V_5 ) + sizeof( V_3 -> V_5 ) ) ;
F_2 ( sizeof( struct V_1 ) > sizeof( V_3 -> V_4 ) +
sizeof( V_3 -> V_5 ) +
sizeof( V_3 -> V_6 ) ) ;
return (struct V_1 * ) & V_3 -> V_4 ;
}
static struct V_2 * F_4 ( struct V_1 * V_7 )
{
return (struct V_2 * ) V_7 ;
}
static inline struct V_8 * V_8 ( struct V_2 * V_3 )
{
F_5 ( V_3 , sizeof( struct V_8 ) ) ;
return (struct V_8 * ) F_6 ( V_3 ) -> V_9 ;
}
static void F_7 ( struct V_10 * V_11 , unsigned long V_12 )
{
V_11 -> V_12 = V_12 ;
V_11 -> V_13 = F_8 () ;
}
static T_1 F_9 ( struct V_10 * V_11 )
{
T_2 V_14 , V_12 ;
unsigned long V_15 ;
if ( V_11 -> V_12 == 0 )
return F_8 () ;
V_14 = F_8 () ;
V_12 = ( T_2 ) V_11 -> V_12 + 1 ;
V_15 = ( V_14 * ( ( 1ull << 32 ) - V_12 ) + V_11 -> V_13 * V_12 ) >> 32 ;
V_11 -> V_13 = V_15 ;
return V_15 ;
}
static bool F_10 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_19 ;
T_1 V_20 = F_8 () ;
switch ( V_19 -> V_11 ) {
case V_21 :
if ( V_20 < V_19 -> V_22 ) {
V_19 -> V_11 = V_23 ;
return true ;
} else if ( V_19 -> V_22 < V_20 && V_20 < V_19 -> V_24 + V_19 -> V_22 ) {
V_19 -> V_11 = V_25 ;
return true ;
} else if ( V_19 -> V_24 + V_19 -> V_22 < V_20 ) {
V_19 -> V_11 = V_21 ;
}
break;
case V_26 :
if ( V_20 < V_19 -> V_27 ) {
V_19 -> V_11 = V_25 ;
return true ;
} else {
V_19 -> V_11 = V_26 ;
}
break;
case V_25 :
if ( V_20 < V_19 -> V_28 )
V_19 -> V_11 = V_26 ;
else if ( V_19 -> V_28 < V_20 && V_20 < V_19 -> V_29 + V_19 -> V_28 ) {
V_19 -> V_11 = V_21 ;
} else if ( V_19 -> V_29 + V_19 -> V_28 < V_20 ) {
V_19 -> V_11 = V_25 ;
return true ;
}
break;
case V_23 :
V_19 -> V_11 = V_21 ;
break;
}
return false ;
}
static bool F_11 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_19 ;
switch ( V_19 -> V_11 ) {
case V_30 :
if ( F_8 () < V_19 -> V_24 )
V_19 -> V_11 = V_31 ;
if ( F_8 () < V_19 -> V_22 )
return true ;
break;
case V_31 :
if ( F_8 () < V_19 -> V_29 )
V_19 -> V_11 = V_30 ;
if ( F_8 () > V_19 -> V_28 )
return true ;
}
return false ;
}
static bool F_12 ( struct V_16 * V_17 )
{
switch ( V_17 -> V_32 ) {
case V_33 :
return V_17 -> V_34 && V_17 -> V_34 >= F_9 ( & V_17 -> V_35 ) ;
case V_36 :
return F_10 ( V_17 ) ;
case V_37 :
return F_11 ( V_17 ) ;
}
return false ;
}
static T_3 F_13 ( T_3 V_38 , T_3 V_39 ,
struct V_10 * V_11 ,
const struct V_40 * V_41 )
{
T_3 V_42 ;
long V_43 ;
T_1 V_20 ;
if ( V_39 == 0 )
return V_38 ;
V_20 = F_9 ( V_11 ) ;
if ( V_41 == NULL )
return ( V_20 % ( 2 * V_39 ) ) - V_39 + V_38 ;
V_43 = V_41 -> V_44 [ V_20 % V_41 -> V_45 ] ;
V_42 = ( V_39 % V_46 ) * V_43 ;
if ( V_42 >= 0 )
V_42 += V_46 / 2 ;
else
V_42 -= V_46 / 2 ;
return V_42 / V_46 + ( V_39 / V_46 ) * V_43 + V_38 ;
}
static T_4 F_14 ( unsigned int V_47 , struct V_16 * V_17 )
{
T_2 V_48 ;
V_47 += V_17 -> V_49 ;
if ( V_17 -> V_50 ) {
T_1 V_51 = F_15 ( V_47 , V_17 -> V_52 ) ;
if ( V_47 > V_51 * V_17 -> V_50 )
V_51 ++ ;
V_47 = V_51 * ( V_17 -> V_50 + V_17 -> V_53 ) ;
}
V_48 = ( T_2 ) V_47 * V_54 ;
F_16 ( V_48 , V_17 -> V_55 ) ;
return F_17 ( V_48 ) ;
}
static void F_18 ( struct V_56 * V_57 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
struct V_1 * V_58 ;
while ( ( V_58 = F_20 ( & V_17 -> V_59 ) ) ) {
struct V_2 * V_3 = F_4 ( V_58 ) ;
F_21 ( V_58 , & V_17 -> V_59 ) ;
V_3 -> V_4 = NULL ;
V_3 -> V_5 = NULL ;
F_22 ( V_3 ) ;
}
}
static void F_23 ( struct V_2 * V_60 , struct V_56 * V_57 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
T_4 V_61 = V_8 ( V_60 ) -> V_62 ;
struct V_1 * * V_58 = & V_17 -> V_59 . V_1 , * V_63 = NULL ;
while ( * V_58 ) {
struct V_2 * V_3 ;
V_63 = * V_58 ;
V_3 = F_4 ( V_63 ) ;
if ( V_61 >= V_8 ( V_3 ) -> V_62 )
V_58 = & V_63 -> V_64 ;
else
V_58 = & V_63 -> V_65 ;
}
F_24 ( F_1 ( V_60 ) , V_63 , V_58 ) ;
F_25 ( F_1 ( V_60 ) , & V_17 -> V_59 ) ;
V_57 -> V_17 . V_66 ++ ;
}
static int F_26 ( struct V_2 * V_3 , struct V_56 * V_57 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
struct V_8 * V_67 ;
struct V_2 * V_68 ;
int V_69 = 1 ;
if ( V_17 -> V_70 && V_17 -> V_70 >= F_9 ( & V_17 -> V_71 ) )
++ V_69 ;
if ( F_12 ( V_17 ) ) {
if ( V_17 -> V_72 && F_27 ( V_3 ) )
V_57 -> V_73 . V_74 ++ ;
else
-- V_69 ;
}
if ( V_69 == 0 ) {
V_57 -> V_73 . V_74 ++ ;
F_22 ( V_3 ) ;
return V_75 | V_76 ;
}
if ( V_17 -> V_77 || V_17 -> V_78 )
F_28 ( V_3 ) ;
if ( V_69 > 1 && ( V_68 = F_29 ( V_3 , V_79 ) ) != NULL ) {
struct V_56 * V_80 = F_30 ( V_57 ) ;
T_1 V_81 = V_17 -> V_70 ;
V_17 -> V_70 = 0 ;
F_31 ( V_68 , V_80 ) ;
V_17 -> V_70 = V_81 ;
}
if ( V_17 -> V_82 && V_17 -> V_82 >= F_9 ( & V_17 -> V_83 ) ) {
if ( ! ( V_3 = F_32 ( V_3 , V_79 ) ) ||
( V_3 -> V_84 == V_85 &&
F_33 ( V_3 ) ) )
return F_34 ( V_3 , V_57 ) ;
V_3 -> V_9 [ F_8 () % F_35 ( V_3 ) ] ^=
1 << ( F_8 () % 8 ) ;
}
if ( F_36 ( F_37 ( & V_57 -> V_17 ) >= V_57 -> V_86 ) )
return F_38 ( V_3 , V_57 ) ;
V_57 -> V_73 . V_87 += F_39 ( V_3 ) ;
V_67 = V_8 ( V_3 ) ;
if ( V_17 -> V_88 == 0 ||
V_17 -> V_89 < V_17 -> V_88 - 1 ||
V_17 -> V_90 < F_9 ( & V_17 -> V_91 ) ) {
T_4 V_92 ;
T_3 V_93 ;
V_93 = F_13 ( V_17 -> V_77 , V_17 -> V_78 ,
& V_17 -> V_94 , V_17 -> V_95 ) ;
V_92 = F_40 () ;
if ( V_17 -> V_55 ) {
struct V_2 * V_13 ;
if ( ! F_41 ( & V_57 -> V_17 ) )
V_13 = F_42 ( & V_57 -> V_17 ) ;
else
V_13 = F_4 ( F_43 ( & V_17 -> V_59 ) ) ;
if ( V_13 ) {
V_93 -= V_8 ( V_13 ) -> V_62 - V_92 ;
V_93 = F_44 ( T_3 , 0 , V_93 ) ;
V_92 = V_8 ( V_13 ) -> V_62 ;
}
V_93 += F_14 ( F_39 ( V_3 ) , V_17 ) ;
}
V_67 -> V_62 = V_92 + V_93 ;
V_67 -> V_96 = V_3 -> V_6 ;
++ V_17 -> V_89 ;
F_23 ( V_3 , V_57 ) ;
} else {
V_67 -> V_62 = F_40 () ;
V_17 -> V_89 = 0 ;
F_45 ( & V_57 -> V_17 , V_3 ) ;
V_57 -> V_73 . V_97 ++ ;
}
return V_75 ;
}
static unsigned int F_46 ( struct V_56 * V_57 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
unsigned int V_47 ;
V_47 = F_47 ( V_57 ) ;
if ( ! V_47 ) {
struct V_1 * V_58 = F_20 ( & V_17 -> V_59 ) ;
if ( V_58 ) {
struct V_2 * V_3 = F_4 ( V_58 ) ;
F_21 ( V_58 , & V_17 -> V_59 ) ;
V_57 -> V_17 . V_66 -- ;
V_3 -> V_4 = NULL ;
V_3 -> V_5 = NULL ;
V_47 = F_39 ( V_3 ) ;
V_57 -> V_73 . V_87 -= V_47 ;
F_22 ( V_3 ) ;
}
}
if ( ! V_47 && V_17 -> V_98 && V_17 -> V_98 -> V_99 -> V_100 )
V_47 = V_17 -> V_98 -> V_99 -> V_100 ( V_17 -> V_98 ) ;
if ( V_47 )
V_57 -> V_73 . V_74 ++ ;
return V_47 ;
}
static struct V_2 * F_48 ( struct V_56 * V_57 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
struct V_2 * V_3 ;
struct V_1 * V_58 ;
if ( F_49 ( V_57 ) )
return NULL ;
V_101:
V_3 = F_50 ( & V_57 -> V_17 ) ;
if ( V_3 ) {
V_102:
V_57 -> V_73 . V_87 -= F_39 ( V_3 ) ;
F_51 ( V_57 ) ;
F_52 ( V_57 , V_3 ) ;
return V_3 ;
}
V_58 = F_20 ( & V_17 -> V_59 ) ;
if ( V_58 ) {
T_4 V_62 ;
V_3 = F_4 ( V_58 ) ;
V_62 = V_8 ( V_3 ) -> V_62 ;
if ( V_62 <= F_40 () ) {
F_21 ( V_58 , & V_17 -> V_59 ) ;
V_57 -> V_17 . V_66 -- ;
V_3 -> V_4 = NULL ;
V_3 -> V_5 = NULL ;
V_3 -> V_6 = V_8 ( V_3 ) -> V_96 ;
#ifdef F_53
if ( F_54 ( V_3 -> V_103 ) & V_104 )
V_3 -> V_6 . V_105 = 0 ;
#endif
if ( V_17 -> V_98 ) {
int V_106 = F_55 ( V_3 , V_17 -> V_98 ) ;
if ( F_36 ( V_106 != V_75 ) ) {
if ( F_56 ( V_106 ) ) {
V_57 -> V_73 . V_74 ++ ;
F_57 ( V_57 , 1 ) ;
}
}
goto V_101;
}
goto V_102;
}
if ( V_17 -> V_98 ) {
V_3 = V_17 -> V_98 -> V_99 -> V_107 ( V_17 -> V_98 ) ;
if ( V_3 )
goto V_102;
}
F_58 ( & V_17 -> V_108 , V_62 ) ;
}
if ( V_17 -> V_98 ) {
V_3 = V_17 -> V_98 -> V_99 -> V_107 ( V_17 -> V_98 ) ;
if ( V_3 )
goto V_102;
}
return NULL ;
}
static void F_59 ( struct V_56 * V_57 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
F_60 ( V_57 ) ;
F_18 ( V_57 ) ;
if ( V_17 -> V_98 )
F_61 ( V_17 -> V_98 ) ;
F_62 ( & V_17 -> V_108 ) ;
}
static void F_63 ( struct V_40 * V_109 )
{
if ( V_109 ) {
if ( F_64 ( V_109 ) )
F_65 ( V_109 ) ;
else
F_66 ( V_109 ) ;
}
}
static int F_67 ( struct V_56 * V_57 , const struct V_110 * V_111 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
T_5 V_112 = F_68 ( V_111 ) / sizeof( V_113 ) ;
const V_113 * V_9 = F_69 ( V_111 ) ;
T_6 * V_114 ;
struct V_40 * V_109 ;
int V_115 ;
T_5 V_116 ;
if ( V_112 > V_117 )
return - V_118 ;
V_116 = sizeof( struct V_40 ) + V_112 * sizeof( V_119 ) ;
V_109 = F_70 ( V_116 , V_120 | V_121 ) ;
if ( ! V_109 )
V_109 = F_71 ( V_116 ) ;
if ( ! V_109 )
return - V_122 ;
V_109 -> V_45 = V_112 ;
for ( V_115 = 0 ; V_115 < V_112 ; V_115 ++ )
V_109 -> V_44 [ V_115 ] = V_9 [ V_115 ] ;
V_114 = F_72 ( V_57 ) ;
F_73 ( V_114 ) ;
F_74 ( V_17 -> V_95 , V_109 ) ;
F_75 ( V_114 ) ;
F_63 ( V_109 ) ;
return 0 ;
}
static void F_76 ( struct V_16 * V_17 , const struct V_110 * V_111 )
{
const struct V_123 * V_124 = F_69 ( V_111 ) ;
F_7 ( & V_17 -> V_94 , V_124 -> V_125 ) ;
F_7 ( & V_17 -> V_35 , V_124 -> V_126 ) ;
F_7 ( & V_17 -> V_71 , V_124 -> V_127 ) ;
}
static void F_77 ( struct V_16 * V_17 , const struct V_110 * V_111 )
{
const struct V_128 * V_129 = F_69 ( V_111 ) ;
V_17 -> V_90 = V_129 -> V_130 ;
F_7 ( & V_17 -> V_91 , V_129 -> V_131 ) ;
}
static void F_78 ( struct V_16 * V_17 , const struct V_110 * V_111 )
{
const struct V_132 * V_129 = F_69 ( V_111 ) ;
V_17 -> V_82 = V_129 -> V_130 ;
F_7 ( & V_17 -> V_83 , V_129 -> V_131 ) ;
}
static void F_79 ( struct V_16 * V_17 , const struct V_110 * V_111 )
{
const struct V_133 * V_129 = F_69 ( V_111 ) ;
V_17 -> V_55 = V_129 -> V_55 ;
V_17 -> V_49 = V_129 -> V_49 ;
V_17 -> V_50 = V_129 -> V_50 ;
V_17 -> V_53 = V_129 -> V_53 ;
if ( V_17 -> V_50 )
V_17 -> V_52 = F_80 ( V_17 -> V_50 ) ;
else
V_17 -> V_52 = (struct F_80 ) { 0 } ;
}
static int F_81 ( struct V_16 * V_17 , const struct V_110 * V_111 )
{
const struct V_110 * V_134 ;
int V_135 ;
F_82 (la, attr, rem) {
T_7 type = F_83 ( V_134 ) ;
switch ( type ) {
case V_136 : {
const struct V_137 * V_138 = F_69 ( V_134 ) ;
if ( F_68 ( V_134 ) < sizeof( struct V_137 ) ) {
F_84 ( L_1 ) ;
return - V_118 ;
}
V_17 -> V_32 = V_36 ;
V_17 -> V_19 . V_11 = V_21 ;
V_17 -> V_19 . V_24 = V_138 -> V_139 ;
V_17 -> V_19 . V_29 = V_138 -> V_140 ;
V_17 -> V_19 . V_28 = V_138 -> V_141 ;
V_17 -> V_19 . V_22 = V_138 -> V_142 ;
V_17 -> V_19 . V_27 = V_138 -> V_143 ;
break;
}
case V_144 : {
const struct V_145 * V_146 = F_69 ( V_134 ) ;
if ( F_68 ( V_134 ) < sizeof( struct V_145 ) ) {
F_84 ( L_2 ) ;
return - V_118 ;
}
V_17 -> V_32 = V_37 ;
V_17 -> V_19 . V_11 = V_30 ;
V_17 -> V_19 . V_24 = V_146 -> V_58 ;
V_17 -> V_19 . V_29 = V_146 -> V_129 ;
V_17 -> V_19 . V_28 = V_146 -> V_147 ;
V_17 -> V_19 . V_22 = V_146 -> V_148 ;
break;
}
default:
F_84 ( L_3 , type ) ;
return - V_118 ;
}
}
return 0 ;
}
static int F_85 ( struct V_110 * V_149 [] , int V_150 , struct V_110 * V_151 ,
const struct V_152 * V_153 , int V_47 )
{
int V_154 = F_68 ( V_151 ) - F_86 ( V_47 ) ;
if ( V_154 < 0 ) {
F_84 ( L_4 , V_154 ) ;
return - V_118 ;
}
if ( V_154 >= F_87 ( 0 ) )
return F_88 ( V_149 , V_150 , F_69 ( V_151 ) + F_86 ( V_47 ) ,
V_154 , V_153 ) ;
memset ( V_149 , 0 , sizeof( struct V_110 * ) * ( V_150 + 1 ) ) ;
return 0 ;
}
static int F_89 ( struct V_56 * V_57 , struct V_110 * V_155 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
struct V_110 * V_149 [ V_156 + 1 ] ;
struct V_157 * V_158 ;
struct V_18 V_159 ;
int V_160 = V_33 ;
int V_161 ;
if ( V_155 == NULL )
return - V_118 ;
V_158 = F_69 ( V_155 ) ;
V_161 = F_85 ( V_149 , V_156 , V_155 , V_162 , sizeof( * V_158 ) ) ;
if ( V_161 < 0 )
return V_161 ;
V_159 = V_17 -> V_19 ;
V_160 = V_17 -> V_32 ;
if ( V_149 [ V_163 ] ) {
V_161 = F_81 ( V_17 , V_149 [ V_163 ] ) ;
if ( V_161 ) {
V_17 -> V_32 = V_160 ;
return V_161 ;
}
} else {
V_17 -> V_32 = V_33 ;
}
if ( V_149 [ V_164 ] ) {
V_161 = F_67 ( V_57 , V_149 [ V_164 ] ) ;
if ( V_161 ) {
V_17 -> V_19 = V_159 ;
V_17 -> V_32 = V_160 ;
return V_161 ;
}
}
V_57 -> V_86 = V_158 -> V_86 ;
V_17 -> V_77 = V_158 -> V_77 ;
V_17 -> V_78 = V_158 -> V_78 ;
V_17 -> V_86 = V_158 -> V_86 ;
V_17 -> V_88 = V_158 -> V_88 ;
V_17 -> V_89 = 0 ;
V_17 -> V_34 = V_158 -> V_34 ;
V_17 -> V_70 = V_158 -> V_70 ;
if ( V_17 -> V_88 )
V_17 -> V_90 = ~ 0 ;
if ( V_149 [ V_165 ] )
F_76 ( V_17 , V_149 [ V_165 ] ) ;
if ( V_149 [ V_166 ] )
F_77 ( V_17 , V_149 [ V_166 ] ) ;
if ( V_149 [ V_167 ] )
F_78 ( V_17 , V_149 [ V_167 ] ) ;
if ( V_149 [ V_168 ] )
F_79 ( V_17 , V_149 [ V_168 ] ) ;
if ( V_149 [ V_169 ] )
V_17 -> V_55 = F_44 ( T_2 , V_17 -> V_55 ,
F_90 ( V_149 [ V_169 ] ) ) ;
if ( V_149 [ V_170 ] )
V_17 -> V_72 = F_91 ( V_149 [ V_170 ] ) ;
return V_161 ;
}
static int F_92 ( struct V_56 * V_57 , struct V_110 * V_155 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
int V_161 ;
if ( ! V_155 )
return - V_118 ;
F_93 ( & V_17 -> V_108 , V_57 ) ;
V_17 -> V_32 = V_33 ;
V_161 = F_89 ( V_57 , V_155 ) ;
if ( V_161 )
F_84 ( L_5 ) ;
return V_161 ;
}
static void F_94 ( struct V_56 * V_57 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
F_62 ( & V_17 -> V_108 ) ;
if ( V_17 -> V_98 )
F_95 ( V_17 -> V_98 ) ;
F_63 ( V_17 -> V_95 ) ;
}
static int F_96 ( const struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_110 * V_171 ;
V_171 = F_97 ( V_3 , V_163 ) ;
if ( V_171 == NULL )
goto V_172;
switch ( V_17 -> V_32 ) {
case V_33 :
F_98 ( V_3 , V_171 ) ;
return 0 ;
case V_36 : {
struct V_137 V_138 = {
. V_139 = V_17 -> V_19 . V_24 ,
. V_140 = V_17 -> V_19 . V_29 ,
. V_141 = V_17 -> V_19 . V_28 ,
. V_142 = V_17 -> V_19 . V_22 ,
. V_143 = V_17 -> V_19 . V_27 ,
} ;
if ( F_99 ( V_3 , V_136 , sizeof( V_138 ) , & V_138 ) )
goto V_172;
break;
}
case V_37 : {
struct V_145 V_146 = {
. V_58 = V_17 -> V_19 . V_24 ,
. V_129 = V_17 -> V_19 . V_29 ,
. V_147 = V_17 -> V_19 . V_28 ,
. V_148 = V_17 -> V_19 . V_22 ,
} ;
if ( F_99 ( V_3 , V_144 , sizeof( V_146 ) , & V_146 ) )
goto V_172;
break;
}
}
F_100 ( V_3 , V_171 ) ;
return 0 ;
V_172:
F_98 ( V_3 , V_171 ) ;
return - 1 ;
}
static int F_101 ( struct V_56 * V_57 , struct V_2 * V_3 )
{
const struct V_16 * V_17 = F_19 ( V_57 ) ;
struct V_110 * V_151 = (struct V_110 * ) F_102 ( V_3 ) ;
struct V_157 V_158 ;
struct V_123 V_173 ;
struct V_128 V_90 ;
struct V_132 V_82 ;
struct V_133 V_55 ;
V_158 . V_77 = V_17 -> V_77 ;
V_158 . V_78 = V_17 -> V_78 ;
V_158 . V_86 = V_17 -> V_86 ;
V_158 . V_34 = V_17 -> V_34 ;
V_158 . V_88 = V_17 -> V_88 ;
V_158 . V_70 = V_17 -> V_70 ;
if ( F_99 ( V_3 , V_174 , sizeof( V_158 ) , & V_158 ) )
goto V_172;
V_173 . V_125 = V_17 -> V_94 . V_12 ;
V_173 . V_126 = V_17 -> V_35 . V_12 ;
V_173 . V_127 = V_17 -> V_71 . V_12 ;
if ( F_99 ( V_3 , V_165 , sizeof( V_173 ) , & V_173 ) )
goto V_172;
V_90 . V_130 = V_17 -> V_90 ;
V_90 . V_131 = V_17 -> V_91 . V_12 ;
if ( F_99 ( V_3 , V_166 , sizeof( V_90 ) , & V_90 ) )
goto V_172;
V_82 . V_130 = V_17 -> V_82 ;
V_82 . V_131 = V_17 -> V_83 . V_12 ;
if ( F_99 ( V_3 , V_167 , sizeof( V_82 ) , & V_82 ) )
goto V_172;
if ( V_17 -> V_55 >= ( 1ULL << 32 ) ) {
if ( F_103 ( V_3 , V_169 , V_17 -> V_55 ) )
goto V_172;
V_55 . V_55 = ~ 0U ;
} else {
V_55 . V_55 = V_17 -> V_55 ;
}
V_55 . V_49 = V_17 -> V_49 ;
V_55 . V_50 = V_17 -> V_50 ;
V_55 . V_53 = V_17 -> V_53 ;
if ( F_99 ( V_3 , V_168 , sizeof( V_55 ) , & V_55 ) )
goto V_172;
if ( V_17 -> V_72 && F_104 ( V_3 , V_170 , V_17 -> V_72 ) )
goto V_172;
if ( F_96 ( V_17 , V_3 ) != 0 )
goto V_172;
return F_100 ( V_3 , V_151 ) ;
V_172:
F_105 ( V_3 , V_151 ) ;
return - 1 ;
}
static int F_106 ( struct V_56 * V_57 , unsigned long V_175 ,
struct V_2 * V_3 , struct V_176 * V_177 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
if ( V_175 != 1 || ! V_17 -> V_98 )
return - V_178 ;
V_177 -> V_179 |= F_107 ( 1 ) ;
V_177 -> V_180 = V_17 -> V_98 -> V_181 ;
return 0 ;
}
static int F_108 ( struct V_56 * V_57 , unsigned long V_182 , struct V_56 * V_183 ,
struct V_56 * * V_184 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
F_109 ( V_57 ) ;
* V_184 = V_17 -> V_98 ;
V_17 -> V_98 = V_183 ;
if ( * V_184 ) {
F_57 ( * V_184 , ( * V_184 ) -> V_17 . V_66 ) ;
F_61 ( * V_184 ) ;
}
F_110 ( V_57 ) ;
return 0 ;
}
static struct V_56 * F_111 ( struct V_56 * V_57 , unsigned long V_182 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
return V_17 -> V_98 ;
}
static unsigned long F_112 ( struct V_56 * V_57 , T_1 V_185 )
{
return 1 ;
}
static void F_113 ( struct V_56 * V_57 , unsigned long V_182 )
{
}
static void F_114 ( struct V_56 * V_57 , struct V_186 * V_187 )
{
if ( ! V_187 -> V_188 ) {
if ( V_187 -> V_69 >= V_187 -> V_189 )
if ( V_187 -> V_190 ( V_57 , 1 , V_187 ) < 0 ) {
V_187 -> V_188 = 1 ;
return;
}
V_187 -> V_69 ++ ;
}
}
static int T_8 F_115 ( void )
{
F_84 ( L_6 V_191 L_7 ) ;
return F_116 ( & V_192 ) ;
}
static void T_9 F_117 ( void )
{
F_118 ( & V_192 ) ;
}
