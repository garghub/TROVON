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
case 1 :
if ( F_8 () < V_19 -> V_24 )
V_19 -> V_11 = 2 ;
if ( F_8 () < V_19 -> V_22 )
return true ;
break;
case 2 :
if ( F_8 () < V_19 -> V_29 )
V_19 -> V_11 = 1 ;
if ( F_8 () > V_19 -> V_28 )
return true ;
}
return false ;
}
static bool F_12 ( struct V_16 * V_17 )
{
switch ( V_17 -> V_30 ) {
case V_31 :
return V_17 -> V_32 && V_17 -> V_32 >= F_9 ( & V_17 -> V_33 ) ;
case V_34 :
return F_10 ( V_17 ) ;
case V_35 :
return F_11 ( V_17 ) ;
}
return false ;
}
static T_3 F_13 ( T_3 V_36 , T_3 V_37 ,
struct V_10 * V_11 ,
const struct V_38 * V_39 )
{
T_3 V_40 ;
long V_41 ;
T_1 V_20 ;
if ( V_37 == 0 )
return V_36 ;
V_20 = F_9 ( V_11 ) ;
if ( V_39 == NULL )
return ( V_20 % ( 2 * V_37 ) ) - V_37 + V_36 ;
V_41 = V_39 -> V_42 [ V_20 % V_39 -> V_43 ] ;
V_40 = ( V_37 % V_44 ) * V_41 ;
if ( V_40 >= 0 )
V_40 += V_44 / 2 ;
else
V_40 -= V_44 / 2 ;
return V_40 / V_44 + ( V_37 / V_44 ) * V_41 + V_36 ;
}
static T_4 F_14 ( unsigned int V_45 , struct V_16 * V_17 )
{
T_2 V_46 ;
V_45 += V_17 -> V_47 ;
if ( V_17 -> V_48 ) {
T_1 V_49 = F_15 ( V_45 , V_17 -> V_50 ) ;
if ( V_45 > V_49 * V_17 -> V_48 )
V_49 ++ ;
V_45 = V_49 * ( V_17 -> V_48 + V_17 -> V_51 ) ;
}
V_46 = ( T_2 ) V_45 * V_52 ;
F_16 ( V_46 , V_17 -> V_53 ) ;
return F_17 ( V_46 ) ;
}
static void F_18 ( struct V_54 * V_55 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
struct V_1 * V_56 ;
while ( ( V_56 = F_20 ( & V_17 -> V_57 ) ) ) {
struct V_2 * V_3 = F_4 ( V_56 ) ;
F_21 ( V_56 , & V_17 -> V_57 ) ;
V_3 -> V_4 = NULL ;
V_3 -> V_5 = NULL ;
F_22 ( V_3 ) ;
}
}
static void F_23 ( struct V_2 * V_58 , struct V_54 * V_55 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
T_4 V_59 = V_8 ( V_58 ) -> V_60 ;
struct V_1 * * V_56 = & V_17 -> V_57 . V_1 , * V_61 = NULL ;
while ( * V_56 ) {
struct V_2 * V_3 ;
V_61 = * V_56 ;
V_3 = F_4 ( V_61 ) ;
if ( V_59 >= V_8 ( V_3 ) -> V_60 )
V_56 = & V_61 -> V_62 ;
else
V_56 = & V_61 -> V_63 ;
}
F_24 ( F_1 ( V_58 ) , V_61 , V_56 ) ;
F_25 ( F_1 ( V_58 ) , & V_17 -> V_57 ) ;
V_55 -> V_17 . V_64 ++ ;
}
static int F_26 ( struct V_2 * V_3 , struct V_54 * V_55 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
struct V_8 * V_65 ;
struct V_2 * V_66 ;
int V_67 = 1 ;
if ( V_17 -> V_68 && V_17 -> V_68 >= F_9 ( & V_17 -> V_69 ) )
++ V_67 ;
if ( F_12 ( V_17 ) ) {
if ( V_17 -> V_70 && F_27 ( V_3 ) )
V_55 -> V_71 . V_72 ++ ;
else
-- V_67 ;
}
if ( V_67 == 0 ) {
V_55 -> V_71 . V_72 ++ ;
F_22 ( V_3 ) ;
return V_73 | V_74 ;
}
if ( V_17 -> V_75 || V_17 -> V_76 )
F_28 ( V_3 ) ;
if ( V_67 > 1 && ( V_66 = F_29 ( V_3 , V_77 ) ) != NULL ) {
struct V_54 * V_78 = F_30 ( V_55 ) ;
T_1 V_79 = V_17 -> V_68 ;
V_17 -> V_68 = 0 ;
F_31 ( V_66 , V_78 ) ;
V_17 -> V_68 = V_79 ;
}
if ( V_17 -> V_80 && V_17 -> V_80 >= F_9 ( & V_17 -> V_81 ) ) {
if ( ! ( V_3 = F_32 ( V_3 , V_77 ) ) ||
( V_3 -> V_82 == V_83 &&
F_33 ( V_3 ) ) )
return F_34 ( V_3 , V_55 ) ;
V_3 -> V_9 [ F_8 () % F_35 ( V_3 ) ] ^=
1 << ( F_8 () % 8 ) ;
}
if ( F_36 ( F_37 ( & V_55 -> V_17 ) >= V_55 -> V_84 ) )
return F_38 ( V_3 , V_55 ) ;
V_55 -> V_71 . V_85 += F_39 ( V_3 ) ;
V_65 = V_8 ( V_3 ) ;
if ( V_17 -> V_86 == 0 ||
V_17 -> V_87 < V_17 -> V_86 - 1 ||
V_17 -> V_88 < F_9 ( & V_17 -> V_89 ) ) {
T_4 V_90 ;
T_3 V_91 ;
V_91 = F_13 ( V_17 -> V_75 , V_17 -> V_76 ,
& V_17 -> V_92 , V_17 -> V_93 ) ;
V_90 = F_40 () ;
if ( V_17 -> V_53 ) {
struct V_2 * V_13 ;
if ( ! F_41 ( & V_55 -> V_17 ) )
V_13 = F_42 ( & V_55 -> V_17 ) ;
else
V_13 = F_4 ( F_43 ( & V_17 -> V_57 ) ) ;
if ( V_13 ) {
V_91 -= V_8 ( V_13 ) -> V_60 - V_90 ;
V_91 = F_44 ( T_3 , 0 , V_91 ) ;
V_90 = V_8 ( V_13 ) -> V_60 ;
}
V_91 += F_14 ( F_39 ( V_3 ) , V_17 ) ;
}
V_65 -> V_60 = V_90 + V_91 ;
V_65 -> V_94 = V_3 -> V_6 ;
++ V_17 -> V_87 ;
F_23 ( V_3 , V_55 ) ;
} else {
V_65 -> V_60 = F_40 () ;
V_17 -> V_87 = 0 ;
F_45 ( & V_55 -> V_17 , V_3 ) ;
V_55 -> V_71 . V_95 ++ ;
}
return V_73 ;
}
static unsigned int F_46 ( struct V_54 * V_55 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
unsigned int V_45 ;
V_45 = F_47 ( V_55 ) ;
if ( ! V_45 ) {
struct V_1 * V_56 = F_20 ( & V_17 -> V_57 ) ;
if ( V_56 ) {
struct V_2 * V_3 = F_4 ( V_56 ) ;
F_21 ( V_56 , & V_17 -> V_57 ) ;
V_55 -> V_17 . V_64 -- ;
V_3 -> V_4 = NULL ;
V_3 -> V_5 = NULL ;
V_45 = F_39 ( V_3 ) ;
V_55 -> V_71 . V_85 -= V_45 ;
F_22 ( V_3 ) ;
}
}
if ( ! V_45 && V_17 -> V_96 && V_17 -> V_96 -> V_97 -> V_98 )
V_45 = V_17 -> V_96 -> V_97 -> V_98 ( V_17 -> V_96 ) ;
if ( V_45 )
V_55 -> V_71 . V_72 ++ ;
return V_45 ;
}
static struct V_2 * F_48 ( struct V_54 * V_55 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
struct V_2 * V_3 ;
struct V_1 * V_56 ;
if ( F_49 ( V_55 ) )
return NULL ;
V_99:
V_3 = F_50 ( & V_55 -> V_17 ) ;
if ( V_3 ) {
V_100:
V_55 -> V_71 . V_85 -= F_39 ( V_3 ) ;
F_51 ( V_55 ) ;
F_52 ( V_55 , V_3 ) ;
return V_3 ;
}
V_56 = F_20 ( & V_17 -> V_57 ) ;
if ( V_56 ) {
T_4 V_60 ;
V_3 = F_4 ( V_56 ) ;
V_60 = V_8 ( V_3 ) -> V_60 ;
if ( V_60 <= F_40 () ) {
F_21 ( V_56 , & V_17 -> V_57 ) ;
V_55 -> V_17 . V_64 -- ;
V_3 -> V_4 = NULL ;
V_3 -> V_5 = NULL ;
V_3 -> V_6 = V_8 ( V_3 ) -> V_94 ;
#ifdef F_53
if ( F_54 ( V_3 -> V_101 ) & V_102 )
V_3 -> V_6 . V_103 = 0 ;
#endif
if ( V_17 -> V_96 ) {
int V_104 = F_55 ( V_3 , V_17 -> V_96 ) ;
if ( F_36 ( V_104 != V_73 ) ) {
if ( F_56 ( V_104 ) ) {
V_55 -> V_71 . V_72 ++ ;
F_57 ( V_55 , 1 ) ;
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
F_58 ( & V_17 -> V_106 , V_60 ) ;
}
if ( V_17 -> V_96 ) {
V_3 = V_17 -> V_96 -> V_97 -> V_105 ( V_17 -> V_96 ) ;
if ( V_3 )
goto V_100;
}
return NULL ;
}
static void F_59 ( struct V_54 * V_55 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
F_60 ( V_55 ) ;
F_18 ( V_55 ) ;
if ( V_17 -> V_96 )
F_61 ( V_17 -> V_96 ) ;
F_62 ( & V_17 -> V_106 ) ;
}
static void F_63 ( struct V_38 * V_107 )
{
if ( V_107 ) {
if ( F_64 ( V_107 ) )
F_65 ( V_107 ) ;
else
F_66 ( V_107 ) ;
}
}
static int F_67 ( struct V_54 * V_55 , const struct V_108 * V_109 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
T_5 V_110 = F_68 ( V_109 ) / sizeof( V_111 ) ;
const V_111 * V_9 = F_69 ( V_109 ) ;
T_6 * V_112 ;
struct V_38 * V_107 ;
int V_113 ;
T_5 V_114 ;
if ( V_110 > V_115 )
return - V_116 ;
V_114 = sizeof( struct V_38 ) + V_110 * sizeof( V_117 ) ;
V_107 = F_70 ( V_114 , V_118 | V_119 ) ;
if ( ! V_107 )
V_107 = F_71 ( V_114 ) ;
if ( ! V_107 )
return - V_120 ;
V_107 -> V_43 = V_110 ;
for ( V_113 = 0 ; V_113 < V_110 ; V_113 ++ )
V_107 -> V_42 [ V_113 ] = V_9 [ V_113 ] ;
V_112 = F_72 ( V_55 ) ;
F_73 ( V_112 ) ;
F_74 ( V_17 -> V_93 , V_107 ) ;
F_75 ( V_112 ) ;
F_63 ( V_107 ) ;
return 0 ;
}
static void F_76 ( struct V_54 * V_55 , const struct V_108 * V_109 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
const struct V_121 * V_122 = F_69 ( V_109 ) ;
F_7 ( & V_17 -> V_92 , V_122 -> V_123 ) ;
F_7 ( & V_17 -> V_33 , V_122 -> V_124 ) ;
F_7 ( & V_17 -> V_69 , V_122 -> V_125 ) ;
}
static void F_77 ( struct V_54 * V_55 , const struct V_108 * V_109 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
const struct V_126 * V_127 = F_69 ( V_109 ) ;
V_17 -> V_88 = V_127 -> V_128 ;
F_7 ( & V_17 -> V_89 , V_127 -> V_129 ) ;
}
static void F_78 ( struct V_54 * V_55 , const struct V_108 * V_109 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
const struct V_130 * V_127 = F_69 ( V_109 ) ;
V_17 -> V_80 = V_127 -> V_128 ;
F_7 ( & V_17 -> V_81 , V_127 -> V_129 ) ;
}
static void F_79 ( struct V_54 * V_55 , const struct V_108 * V_109 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
const struct V_131 * V_127 = F_69 ( V_109 ) ;
V_17 -> V_53 = V_127 -> V_53 ;
V_17 -> V_47 = V_127 -> V_47 ;
V_17 -> V_48 = V_127 -> V_48 ;
V_17 -> V_51 = V_127 -> V_51 ;
if ( V_17 -> V_48 )
V_17 -> V_50 = F_80 ( V_17 -> V_48 ) ;
else
V_17 -> V_50 = (struct F_80 ) { 0 } ;
}
static int F_81 ( struct V_54 * V_55 , const struct V_108 * V_109 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
const struct V_108 * V_132 ;
int V_133 ;
F_82 (la, attr, rem) {
T_7 type = F_83 ( V_132 ) ;
switch ( type ) {
case V_134 : {
const struct V_135 * V_136 = F_69 ( V_132 ) ;
if ( F_68 ( V_132 ) < sizeof( struct V_135 ) ) {
F_84 ( L_1 ) ;
return - V_116 ;
}
V_17 -> V_30 = V_34 ;
V_17 -> V_19 . V_11 = 1 ;
V_17 -> V_19 . V_24 = V_136 -> V_137 ;
V_17 -> V_19 . V_29 = V_136 -> V_138 ;
V_17 -> V_19 . V_28 = V_136 -> V_139 ;
V_17 -> V_19 . V_22 = V_136 -> V_140 ;
V_17 -> V_19 . V_27 = V_136 -> V_141 ;
break;
}
case V_142 : {
const struct V_143 * V_144 = F_69 ( V_132 ) ;
if ( F_68 ( V_132 ) < sizeof( struct V_143 ) ) {
F_84 ( L_2 ) ;
return - V_116 ;
}
V_17 -> V_30 = V_35 ;
V_17 -> V_19 . V_11 = 1 ;
V_17 -> V_19 . V_24 = V_144 -> V_56 ;
V_17 -> V_19 . V_29 = V_144 -> V_127 ;
V_17 -> V_19 . V_28 = V_144 -> V_145 ;
V_17 -> V_19 . V_22 = V_144 -> V_146 ;
break;
}
default:
F_84 ( L_3 , type ) ;
return - V_116 ;
}
}
return 0 ;
}
static int F_85 ( struct V_108 * V_147 [] , int V_148 , struct V_108 * V_149 ,
const struct V_150 * V_151 , int V_45 )
{
int V_152 = F_68 ( V_149 ) - F_86 ( V_45 ) ;
if ( V_152 < 0 ) {
F_84 ( L_4 , V_152 ) ;
return - V_116 ;
}
if ( V_152 >= F_87 ( 0 ) )
return F_88 ( V_147 , V_148 , F_69 ( V_149 ) + F_86 ( V_45 ) ,
V_152 , V_151 ) ;
memset ( V_147 , 0 , sizeof( struct V_108 * ) * ( V_148 + 1 ) ) ;
return 0 ;
}
static int F_89 ( struct V_54 * V_55 , struct V_108 * V_153 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
struct V_108 * V_147 [ V_154 + 1 ] ;
struct V_155 * V_156 ;
int V_157 ;
if ( V_153 == NULL )
return - V_116 ;
V_156 = F_69 ( V_153 ) ;
V_157 = F_85 ( V_147 , V_154 , V_153 , V_158 , sizeof( * V_156 ) ) ;
if ( V_157 < 0 )
return V_157 ;
V_55 -> V_84 = V_156 -> V_84 ;
V_17 -> V_75 = V_156 -> V_75 ;
V_17 -> V_76 = V_156 -> V_76 ;
V_17 -> V_84 = V_156 -> V_84 ;
V_17 -> V_86 = V_156 -> V_86 ;
V_17 -> V_87 = 0 ;
V_17 -> V_32 = V_156 -> V_32 ;
V_17 -> V_68 = V_156 -> V_68 ;
if ( V_17 -> V_86 )
V_17 -> V_88 = ~ 0 ;
if ( V_147 [ V_159 ] )
F_76 ( V_55 , V_147 [ V_159 ] ) ;
if ( V_147 [ V_160 ] ) {
V_157 = F_67 ( V_55 , V_147 [ V_160 ] ) ;
if ( V_157 )
return V_157 ;
}
if ( V_147 [ V_161 ] )
F_77 ( V_55 , V_147 [ V_161 ] ) ;
if ( V_147 [ V_162 ] )
F_78 ( V_55 , V_147 [ V_162 ] ) ;
if ( V_147 [ V_163 ] )
F_79 ( V_55 , V_147 [ V_163 ] ) ;
if ( V_147 [ V_164 ] )
V_17 -> V_53 = F_44 ( T_2 , V_17 -> V_53 ,
F_90 ( V_147 [ V_164 ] ) ) ;
if ( V_147 [ V_165 ] )
V_17 -> V_70 = F_91 ( V_147 [ V_165 ] ) ;
V_17 -> V_30 = V_31 ;
if ( V_147 [ V_166 ] )
V_157 = F_81 ( V_55 , V_147 [ V_166 ] ) ;
return V_157 ;
}
static int F_92 ( struct V_54 * V_55 , struct V_108 * V_153 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
int V_157 ;
if ( ! V_153 )
return - V_116 ;
F_93 ( & V_17 -> V_106 , V_55 ) ;
V_17 -> V_30 = V_31 ;
V_157 = F_89 ( V_55 , V_153 ) ;
if ( V_157 )
F_84 ( L_5 ) ;
return V_157 ;
}
static void F_94 ( struct V_54 * V_55 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
F_62 ( & V_17 -> V_106 ) ;
if ( V_17 -> V_96 )
F_95 ( V_17 -> V_96 ) ;
F_63 ( V_17 -> V_93 ) ;
}
static int F_96 ( const struct V_16 * V_17 ,
struct V_2 * V_3 )
{
struct V_108 * V_167 ;
V_167 = F_97 ( V_3 , V_166 ) ;
if ( V_167 == NULL )
goto V_168;
switch ( V_17 -> V_30 ) {
case V_31 :
F_98 ( V_3 , V_167 ) ;
return 0 ;
case V_34 : {
struct V_135 V_136 = {
. V_137 = V_17 -> V_19 . V_24 ,
. V_138 = V_17 -> V_19 . V_29 ,
. V_139 = V_17 -> V_19 . V_28 ,
. V_140 = V_17 -> V_19 . V_22 ,
. V_141 = V_17 -> V_19 . V_27 ,
} ;
if ( F_99 ( V_3 , V_134 , sizeof( V_136 ) , & V_136 ) )
goto V_168;
break;
}
case V_35 : {
struct V_143 V_144 = {
. V_56 = V_17 -> V_19 . V_24 ,
. V_127 = V_17 -> V_19 . V_29 ,
. V_145 = V_17 -> V_19 . V_28 ,
. V_146 = V_17 -> V_19 . V_22 ,
} ;
if ( F_99 ( V_3 , V_142 , sizeof( V_144 ) , & V_144 ) )
goto V_168;
break;
}
}
F_100 ( V_3 , V_167 ) ;
return 0 ;
V_168:
F_98 ( V_3 , V_167 ) ;
return - 1 ;
}
static int F_101 ( struct V_54 * V_55 , struct V_2 * V_3 )
{
const struct V_16 * V_17 = F_19 ( V_55 ) ;
struct V_108 * V_149 = (struct V_108 * ) F_102 ( V_3 ) ;
struct V_155 V_156 ;
struct V_121 V_169 ;
struct V_126 V_88 ;
struct V_130 V_80 ;
struct V_131 V_53 ;
V_156 . V_75 = V_17 -> V_75 ;
V_156 . V_76 = V_17 -> V_76 ;
V_156 . V_84 = V_17 -> V_84 ;
V_156 . V_32 = V_17 -> V_32 ;
V_156 . V_86 = V_17 -> V_86 ;
V_156 . V_68 = V_17 -> V_68 ;
if ( F_99 ( V_3 , V_170 , sizeof( V_156 ) , & V_156 ) )
goto V_168;
V_169 . V_123 = V_17 -> V_92 . V_12 ;
V_169 . V_124 = V_17 -> V_33 . V_12 ;
V_169 . V_125 = V_17 -> V_69 . V_12 ;
if ( F_99 ( V_3 , V_159 , sizeof( V_169 ) , & V_169 ) )
goto V_168;
V_88 . V_128 = V_17 -> V_88 ;
V_88 . V_129 = V_17 -> V_89 . V_12 ;
if ( F_99 ( V_3 , V_161 , sizeof( V_88 ) , & V_88 ) )
goto V_168;
V_80 . V_128 = V_17 -> V_80 ;
V_80 . V_129 = V_17 -> V_81 . V_12 ;
if ( F_99 ( V_3 , V_162 , sizeof( V_80 ) , & V_80 ) )
goto V_168;
if ( V_17 -> V_53 >= ( 1ULL << 32 ) ) {
if ( F_103 ( V_3 , V_164 , V_17 -> V_53 ) )
goto V_168;
V_53 . V_53 = ~ 0U ;
} else {
V_53 . V_53 = V_17 -> V_53 ;
}
V_53 . V_47 = V_17 -> V_47 ;
V_53 . V_48 = V_17 -> V_48 ;
V_53 . V_51 = V_17 -> V_51 ;
if ( F_99 ( V_3 , V_163 , sizeof( V_53 ) , & V_53 ) )
goto V_168;
if ( V_17 -> V_70 && F_104 ( V_3 , V_165 , V_17 -> V_70 ) )
goto V_168;
if ( F_96 ( V_17 , V_3 ) != 0 )
goto V_168;
return F_100 ( V_3 , V_149 ) ;
V_168:
F_105 ( V_3 , V_149 ) ;
return - 1 ;
}
static int F_106 ( struct V_54 * V_55 , unsigned long V_171 ,
struct V_2 * V_3 , struct V_172 * V_173 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
if ( V_171 != 1 || ! V_17 -> V_96 )
return - V_174 ;
V_173 -> V_175 |= F_107 ( 1 ) ;
V_173 -> V_176 = V_17 -> V_96 -> V_177 ;
return 0 ;
}
static int F_108 ( struct V_54 * V_55 , unsigned long V_178 , struct V_54 * V_179 ,
struct V_54 * * V_180 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
F_109 ( V_55 ) ;
* V_180 = V_17 -> V_96 ;
V_17 -> V_96 = V_179 ;
if ( * V_180 ) {
F_57 ( * V_180 , ( * V_180 ) -> V_17 . V_64 ) ;
F_61 ( * V_180 ) ;
}
F_110 ( V_55 ) ;
return 0 ;
}
static struct V_54 * F_111 ( struct V_54 * V_55 , unsigned long V_178 )
{
struct V_16 * V_17 = F_19 ( V_55 ) ;
return V_17 -> V_96 ;
}
static unsigned long F_112 ( struct V_54 * V_55 , T_1 V_181 )
{
return 1 ;
}
static void F_113 ( struct V_54 * V_55 , unsigned long V_178 )
{
}
static void F_114 ( struct V_54 * V_55 , struct V_182 * V_183 )
{
if ( ! V_183 -> V_184 ) {
if ( V_183 -> V_67 >= V_183 -> V_185 )
if ( V_183 -> V_186 ( V_55 , 1 , V_183 ) < 0 ) {
V_183 -> V_184 = 1 ;
return;
}
V_183 -> V_67 ++ ;
}
}
static int T_8 F_115 ( void )
{
F_84 ( L_6 V_187 L_7 ) ;
return F_116 ( & V_188 ) ;
}
static void T_9 F_117 ( void )
{
F_118 ( & V_188 ) ;
}
