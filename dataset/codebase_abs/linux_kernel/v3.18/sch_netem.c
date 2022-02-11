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
F_28 ( V_57 ) ;
else
-- V_69 ;
}
if ( V_69 == 0 ) {
F_28 ( V_57 ) ;
F_22 ( V_3 ) ;
return V_73 | V_74 ;
}
if ( V_17 -> V_75 || V_17 -> V_76 )
F_29 ( V_3 ) ;
if ( V_69 > 1 && ( V_68 = F_30 ( V_3 , V_77 ) ) != NULL ) {
struct V_56 * V_78 = F_31 ( V_57 ) ;
T_1 V_79 = V_17 -> V_70 ;
V_17 -> V_70 = 0 ;
F_32 ( V_68 , V_78 ) ;
V_17 -> V_70 = V_79 ;
}
if ( V_17 -> V_80 && V_17 -> V_80 >= F_9 ( & V_17 -> V_81 ) ) {
if ( ! ( V_3 = F_33 ( V_3 , V_77 ) ) ||
( V_3 -> V_82 == V_83 &&
F_34 ( V_3 ) ) )
return F_35 ( V_3 , V_57 ) ;
V_3 -> V_9 [ F_8 () % F_36 ( V_3 ) ] ^=
1 << ( F_8 () % 8 ) ;
}
if ( F_37 ( F_38 ( & V_57 -> V_17 ) >= V_57 -> V_84 ) )
return F_39 ( V_3 , V_57 ) ;
F_40 ( V_57 , V_3 ) ;
V_67 = V_8 ( V_3 ) ;
if ( V_17 -> V_85 == 0 ||
V_17 -> V_86 < V_17 -> V_85 - 1 ||
V_17 -> V_87 < F_9 ( & V_17 -> V_88 ) ) {
T_4 V_89 ;
T_3 V_90 ;
V_90 = F_13 ( V_17 -> V_75 , V_17 -> V_76 ,
& V_17 -> V_91 , V_17 -> V_92 ) ;
V_89 = F_41 () ;
if ( V_17 -> V_55 ) {
struct V_2 * V_13 ;
if ( ! F_42 ( & V_57 -> V_17 ) )
V_13 = F_43 ( & V_57 -> V_17 ) ;
else
V_13 = F_4 ( F_44 ( & V_17 -> V_59 ) ) ;
if ( V_13 ) {
V_90 -= V_8 ( V_13 ) -> V_62 - V_89 ;
V_90 = F_45 ( T_3 , 0 , V_90 ) ;
V_89 = V_8 ( V_13 ) -> V_62 ;
}
V_90 += F_14 ( F_46 ( V_3 ) , V_17 ) ;
}
V_67 -> V_62 = V_89 + V_90 ;
V_67 -> V_93 = V_3 -> V_6 ;
++ V_17 -> V_86 ;
F_23 ( V_3 , V_57 ) ;
} else {
V_67 -> V_62 = F_41 () ;
V_17 -> V_86 = 0 ;
F_47 ( & V_57 -> V_17 , V_3 ) ;
V_57 -> V_94 . V_95 ++ ;
}
return V_73 ;
}
static unsigned int F_48 ( struct V_56 * V_57 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
unsigned int V_47 ;
V_47 = F_49 ( V_57 ) ;
if ( ! V_47 ) {
struct V_1 * V_58 = F_20 ( & V_17 -> V_59 ) ;
if ( V_58 ) {
struct V_2 * V_3 = F_4 ( V_58 ) ;
F_21 ( V_58 , & V_17 -> V_59 ) ;
V_57 -> V_17 . V_66 -- ;
V_3 -> V_4 = NULL ;
V_3 -> V_5 = NULL ;
F_50 ( V_57 , V_3 ) ;
F_22 ( V_3 ) ;
}
}
if ( ! V_47 && V_17 -> V_96 && V_17 -> V_96 -> V_97 -> V_98 )
V_47 = V_17 -> V_96 -> V_97 -> V_98 ( V_17 -> V_96 ) ;
if ( V_47 )
F_28 ( V_57 ) ;
return V_47 ;
}
static struct V_2 * F_51 ( struct V_56 * V_57 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
struct V_2 * V_3 ;
struct V_1 * V_58 ;
if ( F_52 ( V_57 ) )
return NULL ;
V_99:
V_3 = F_53 ( & V_57 -> V_17 ) ;
if ( V_3 ) {
V_100:
F_50 ( V_57 , V_3 ) ;
F_54 ( V_57 ) ;
F_55 ( V_57 , V_3 ) ;
return V_3 ;
}
V_58 = F_20 ( & V_17 -> V_59 ) ;
if ( V_58 ) {
T_4 V_62 ;
V_3 = F_4 ( V_58 ) ;
V_62 = V_8 ( V_3 ) -> V_62 ;
if ( V_62 <= F_41 () ) {
F_21 ( V_58 , & V_17 -> V_59 ) ;
V_57 -> V_17 . V_66 -- ;
V_3 -> V_4 = NULL ;
V_3 -> V_5 = NULL ;
V_3 -> V_6 = V_8 ( V_3 ) -> V_93 ;
#ifdef F_56
if ( F_57 ( V_3 -> V_101 ) & V_102 )
V_3 -> V_6 . V_103 = 0 ;
#endif
if ( V_17 -> V_96 ) {
int V_104 = F_58 ( V_3 , V_17 -> V_96 ) ;
if ( F_37 ( V_104 != V_73 ) ) {
if ( F_59 ( V_104 ) ) {
F_28 ( V_57 ) ;
F_60 ( V_57 , 1 ) ;
}
}
goto V_99;
}
goto V_100;
}
if ( V_17 -> V_96 ) {
V_3 = V_17 -> V_96 -> V_97 -> V_105 ( V_17 -> V_96 ) ;
if ( V_3 )
goto V_100;
}
F_61 ( & V_17 -> V_106 , V_62 ) ;
}
if ( V_17 -> V_96 ) {
V_3 = V_17 -> V_96 -> V_97 -> V_105 ( V_17 -> V_96 ) ;
if ( V_3 )
goto V_100;
}
return NULL ;
}
static void F_62 ( struct V_56 * V_57 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
F_63 ( V_57 ) ;
F_18 ( V_57 ) ;
if ( V_17 -> V_96 )
F_64 ( V_17 -> V_96 ) ;
F_65 ( & V_17 -> V_106 ) ;
}
static void F_66 ( struct V_40 * V_107 )
{
F_67 ( V_107 ) ;
}
static int F_68 ( struct V_56 * V_57 , const struct V_108 * V_109 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
T_5 V_110 = F_69 ( V_109 ) / sizeof( V_111 ) ;
const V_111 * V_9 = F_70 ( V_109 ) ;
T_6 * V_112 ;
struct V_40 * V_107 ;
int V_113 ;
T_5 V_114 ;
if ( V_110 > V_115 )
return - V_116 ;
V_114 = sizeof( struct V_40 ) + V_110 * sizeof( V_117 ) ;
V_107 = F_71 ( V_114 , V_118 | V_119 ) ;
if ( ! V_107 )
V_107 = F_72 ( V_114 ) ;
if ( ! V_107 )
return - V_120 ;
V_107 -> V_45 = V_110 ;
for ( V_113 = 0 ; V_113 < V_110 ; V_113 ++ )
V_107 -> V_44 [ V_113 ] = V_9 [ V_113 ] ;
V_112 = F_73 ( V_57 ) ;
F_74 ( V_112 ) ;
F_75 ( V_17 -> V_92 , V_107 ) ;
F_76 ( V_112 ) ;
F_66 ( V_107 ) ;
return 0 ;
}
static void F_77 ( struct V_16 * V_17 , const struct V_108 * V_109 )
{
const struct V_121 * V_122 = F_70 ( V_109 ) ;
F_7 ( & V_17 -> V_91 , V_122 -> V_123 ) ;
F_7 ( & V_17 -> V_35 , V_122 -> V_124 ) ;
F_7 ( & V_17 -> V_71 , V_122 -> V_125 ) ;
}
static void F_78 ( struct V_16 * V_17 , const struct V_108 * V_109 )
{
const struct V_126 * V_127 = F_70 ( V_109 ) ;
V_17 -> V_87 = V_127 -> V_128 ;
F_7 ( & V_17 -> V_88 , V_127 -> V_129 ) ;
}
static void F_79 ( struct V_16 * V_17 , const struct V_108 * V_109 )
{
const struct V_130 * V_127 = F_70 ( V_109 ) ;
V_17 -> V_80 = V_127 -> V_128 ;
F_7 ( & V_17 -> V_81 , V_127 -> V_129 ) ;
}
static void F_80 ( struct V_16 * V_17 , const struct V_108 * V_109 )
{
const struct V_131 * V_127 = F_70 ( V_109 ) ;
V_17 -> V_55 = V_127 -> V_55 ;
V_17 -> V_49 = V_127 -> V_49 ;
V_17 -> V_50 = V_127 -> V_50 ;
V_17 -> V_53 = V_127 -> V_53 ;
if ( V_17 -> V_50 )
V_17 -> V_52 = F_81 ( V_17 -> V_50 ) ;
else
V_17 -> V_52 = (struct F_81 ) { 0 } ;
}
static int F_82 ( struct V_16 * V_17 , const struct V_108 * V_109 )
{
const struct V_108 * V_132 ;
int V_133 ;
F_83 (la, attr, rem) {
T_7 type = F_84 ( V_132 ) ;
switch ( type ) {
case V_134 : {
const struct V_135 * V_136 = F_70 ( V_132 ) ;
if ( F_69 ( V_132 ) < sizeof( struct V_135 ) ) {
F_85 ( L_1 ) ;
return - V_116 ;
}
V_17 -> V_32 = V_36 ;
V_17 -> V_19 . V_11 = V_21 ;
V_17 -> V_19 . V_24 = V_136 -> V_137 ;
V_17 -> V_19 . V_29 = V_136 -> V_138 ;
V_17 -> V_19 . V_28 = V_136 -> V_139 ;
V_17 -> V_19 . V_22 = V_136 -> V_140 ;
V_17 -> V_19 . V_27 = V_136 -> V_141 ;
break;
}
case V_142 : {
const struct V_143 * V_144 = F_70 ( V_132 ) ;
if ( F_69 ( V_132 ) < sizeof( struct V_143 ) ) {
F_85 ( L_2 ) ;
return - V_116 ;
}
V_17 -> V_32 = V_37 ;
V_17 -> V_19 . V_11 = V_30 ;
V_17 -> V_19 . V_24 = V_144 -> V_58 ;
V_17 -> V_19 . V_29 = V_144 -> V_127 ;
V_17 -> V_19 . V_28 = V_144 -> V_145 ;
V_17 -> V_19 . V_22 = V_144 -> V_146 ;
break;
}
default:
F_85 ( L_3 , type ) ;
return - V_116 ;
}
}
return 0 ;
}
static int F_86 ( struct V_108 * V_147 [] , int V_148 , struct V_108 * V_149 ,
const struct V_150 * V_151 , int V_47 )
{
int V_152 = F_69 ( V_149 ) - F_87 ( V_47 ) ;
if ( V_152 < 0 ) {
F_85 ( L_4 , V_152 ) ;
return - V_116 ;
}
if ( V_152 >= F_88 ( 0 ) )
return F_89 ( V_147 , V_148 , F_70 ( V_149 ) + F_87 ( V_47 ) ,
V_152 , V_151 ) ;
memset ( V_147 , 0 , sizeof( struct V_108 * ) * ( V_148 + 1 ) ) ;
return 0 ;
}
static int F_90 ( struct V_56 * V_57 , struct V_108 * V_153 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
struct V_108 * V_147 [ V_154 + 1 ] ;
struct V_155 * V_156 ;
struct V_18 V_157 ;
int V_158 = V_33 ;
int V_159 ;
if ( V_153 == NULL )
return - V_116 ;
V_156 = F_70 ( V_153 ) ;
V_159 = F_86 ( V_147 , V_154 , V_153 , V_160 , sizeof( * V_156 ) ) ;
if ( V_159 < 0 )
return V_159 ;
V_157 = V_17 -> V_19 ;
V_158 = V_17 -> V_32 ;
if ( V_147 [ V_161 ] ) {
V_159 = F_82 ( V_17 , V_147 [ V_161 ] ) ;
if ( V_159 ) {
V_17 -> V_32 = V_158 ;
return V_159 ;
}
} else {
V_17 -> V_32 = V_33 ;
}
if ( V_147 [ V_162 ] ) {
V_159 = F_68 ( V_57 , V_147 [ V_162 ] ) ;
if ( V_159 ) {
V_17 -> V_19 = V_157 ;
V_17 -> V_32 = V_158 ;
return V_159 ;
}
}
V_57 -> V_84 = V_156 -> V_84 ;
V_17 -> V_75 = V_156 -> V_75 ;
V_17 -> V_76 = V_156 -> V_76 ;
V_17 -> V_84 = V_156 -> V_84 ;
V_17 -> V_85 = V_156 -> V_85 ;
V_17 -> V_86 = 0 ;
V_17 -> V_34 = V_156 -> V_34 ;
V_17 -> V_70 = V_156 -> V_70 ;
if ( V_17 -> V_85 )
V_17 -> V_87 = ~ 0 ;
if ( V_147 [ V_163 ] )
F_77 ( V_17 , V_147 [ V_163 ] ) ;
if ( V_147 [ V_164 ] )
F_78 ( V_17 , V_147 [ V_164 ] ) ;
if ( V_147 [ V_165 ] )
F_79 ( V_17 , V_147 [ V_165 ] ) ;
if ( V_147 [ V_166 ] )
F_80 ( V_17 , V_147 [ V_166 ] ) ;
if ( V_147 [ V_167 ] )
V_17 -> V_55 = F_45 ( T_2 , V_17 -> V_55 ,
F_91 ( V_147 [ V_167 ] ) ) ;
if ( V_147 [ V_168 ] )
V_17 -> V_72 = F_92 ( V_147 [ V_168 ] ) ;
return V_159 ;
}
static int F_93 ( struct V_56 * V_57 , struct V_108 * V_153 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
int V_159 ;
if ( ! V_153 )
return - V_116 ;
F_94 ( & V_17 -> V_106 , V_57 ) ;
V_17 -> V_32 = V_33 ;
V_159 = F_90 ( V_57 , V_153 ) ;
if ( V_159 )
F_85 ( L_5 ) ;
return V_159 ;
}
static void F_95 ( struct V_56 * V_57 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
F_65 ( & V_17 -> V_106 ) ;
if ( V_17 -> V_96 )
F_96 ( V_17 -> V_96 ) ;
F_66 ( V_17 -> V_92 ) ;
}
static int F_97 ( const struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_108 * V_169 ;
V_169 = F_98 ( V_3 , V_161 ) ;
if ( V_169 == NULL )
goto V_170;
switch ( V_17 -> V_32 ) {
case V_33 :
F_99 ( V_3 , V_169 ) ;
return 0 ;
case V_36 : {
struct V_135 V_136 = {
. V_137 = V_17 -> V_19 . V_24 ,
. V_138 = V_17 -> V_19 . V_29 ,
. V_139 = V_17 -> V_19 . V_28 ,
. V_140 = V_17 -> V_19 . V_22 ,
. V_141 = V_17 -> V_19 . V_27 ,
} ;
if ( F_100 ( V_3 , V_134 , sizeof( V_136 ) , & V_136 ) )
goto V_170;
break;
}
case V_37 : {
struct V_143 V_144 = {
. V_58 = V_17 -> V_19 . V_24 ,
. V_127 = V_17 -> V_19 . V_29 ,
. V_145 = V_17 -> V_19 . V_28 ,
. V_146 = V_17 -> V_19 . V_22 ,
} ;
if ( F_100 ( V_3 , V_142 , sizeof( V_144 ) , & V_144 ) )
goto V_170;
break;
}
}
F_101 ( V_3 , V_169 ) ;
return 0 ;
V_170:
F_99 ( V_3 , V_169 ) ;
return - 1 ;
}
static int F_102 ( struct V_56 * V_57 , struct V_2 * V_3 )
{
const struct V_16 * V_17 = F_19 ( V_57 ) ;
struct V_108 * V_149 = (struct V_108 * ) F_103 ( V_3 ) ;
struct V_155 V_156 ;
struct V_121 V_171 ;
struct V_126 V_87 ;
struct V_130 V_80 ;
struct V_131 V_55 ;
V_156 . V_75 = V_17 -> V_75 ;
V_156 . V_76 = V_17 -> V_76 ;
V_156 . V_84 = V_17 -> V_84 ;
V_156 . V_34 = V_17 -> V_34 ;
V_156 . V_85 = V_17 -> V_85 ;
V_156 . V_70 = V_17 -> V_70 ;
if ( F_100 ( V_3 , V_172 , sizeof( V_156 ) , & V_156 ) )
goto V_170;
V_171 . V_123 = V_17 -> V_91 . V_12 ;
V_171 . V_124 = V_17 -> V_35 . V_12 ;
V_171 . V_125 = V_17 -> V_71 . V_12 ;
if ( F_100 ( V_3 , V_163 , sizeof( V_171 ) , & V_171 ) )
goto V_170;
V_87 . V_128 = V_17 -> V_87 ;
V_87 . V_129 = V_17 -> V_88 . V_12 ;
if ( F_100 ( V_3 , V_164 , sizeof( V_87 ) , & V_87 ) )
goto V_170;
V_80 . V_128 = V_17 -> V_80 ;
V_80 . V_129 = V_17 -> V_81 . V_12 ;
if ( F_100 ( V_3 , V_165 , sizeof( V_80 ) , & V_80 ) )
goto V_170;
if ( V_17 -> V_55 >= ( 1ULL << 32 ) ) {
if ( F_104 ( V_3 , V_167 , V_17 -> V_55 ) )
goto V_170;
V_55 . V_55 = ~ 0U ;
} else {
V_55 . V_55 = V_17 -> V_55 ;
}
V_55 . V_49 = V_17 -> V_49 ;
V_55 . V_50 = V_17 -> V_50 ;
V_55 . V_53 = V_17 -> V_53 ;
if ( F_100 ( V_3 , V_166 , sizeof( V_55 ) , & V_55 ) )
goto V_170;
if ( V_17 -> V_72 && F_105 ( V_3 , V_168 , V_17 -> V_72 ) )
goto V_170;
if ( F_97 ( V_17 , V_3 ) != 0 )
goto V_170;
return F_101 ( V_3 , V_149 ) ;
V_170:
F_106 ( V_3 , V_149 ) ;
return - 1 ;
}
static int F_107 ( struct V_56 * V_57 , unsigned long V_173 ,
struct V_2 * V_3 , struct V_174 * V_175 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
if ( V_173 != 1 || ! V_17 -> V_96 )
return - V_176 ;
V_175 -> V_177 |= F_108 ( 1 ) ;
V_175 -> V_178 = V_17 -> V_96 -> V_179 ;
return 0 ;
}
static int F_109 ( struct V_56 * V_57 , unsigned long V_180 , struct V_56 * V_181 ,
struct V_56 * * V_182 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
F_110 ( V_57 ) ;
* V_182 = V_17 -> V_96 ;
V_17 -> V_96 = V_181 ;
if ( * V_182 ) {
F_60 ( * V_182 , ( * V_182 ) -> V_17 . V_66 ) ;
F_64 ( * V_182 ) ;
}
F_111 ( V_57 ) ;
return 0 ;
}
static struct V_56 * F_112 ( struct V_56 * V_57 , unsigned long V_180 )
{
struct V_16 * V_17 = F_19 ( V_57 ) ;
return V_17 -> V_96 ;
}
static unsigned long F_113 ( struct V_56 * V_57 , T_1 V_183 )
{
return 1 ;
}
static void F_114 ( struct V_56 * V_57 , unsigned long V_180 )
{
}
static void F_115 ( struct V_56 * V_57 , struct V_184 * V_185 )
{
if ( ! V_185 -> V_186 ) {
if ( V_185 -> V_69 >= V_185 -> V_187 )
if ( V_185 -> V_188 ( V_57 , 1 , V_185 ) < 0 ) {
V_185 -> V_186 = 1 ;
return;
}
V_185 -> V_69 ++ ;
}
}
static int T_8 F_116 ( void )
{
F_85 ( L_6 V_189 L_7 ) ;
return F_117 ( & V_190 ) ;
}
static void T_9 F_118 ( void )
{
F_119 ( & V_190 ) ;
}
