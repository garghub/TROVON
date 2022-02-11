static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * V_5 ( struct V_1 * V_6 )
{
F_3 ( V_6 , sizeof( struct V_5 ) ) ;
return (struct V_5 * ) F_4 ( V_6 ) -> V_7 ;
}
static void F_5 ( struct V_8 * V_9 , unsigned long V_10 )
{
V_9 -> V_10 = V_10 ;
V_9 -> V_11 = F_6 () ;
}
static T_1 F_7 ( struct V_8 * V_9 )
{
T_2 V_12 , V_10 ;
unsigned long V_13 ;
if ( V_9 -> V_10 == 0 )
return F_6 () ;
V_12 = F_6 () ;
V_10 = ( T_2 ) V_9 -> V_10 + 1 ;
V_13 = ( V_12 * ( ( 1ull << 32 ) - V_10 ) + V_9 -> V_11 * V_10 ) >> 32 ;
V_9 -> V_11 = V_13 ;
return V_13 ;
}
static bool F_8 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_17 ;
T_1 V_18 = F_6 () ;
switch ( V_17 -> V_9 ) {
case V_19 :
if ( V_18 < V_17 -> V_20 ) {
V_17 -> V_9 = V_21 ;
return true ;
} else if ( V_17 -> V_20 < V_18 && V_18 < V_17 -> V_22 + V_17 -> V_20 ) {
V_17 -> V_9 = V_23 ;
return true ;
} else if ( V_17 -> V_22 + V_17 -> V_20 < V_18 ) {
V_17 -> V_9 = V_19 ;
}
break;
case V_24 :
if ( V_18 < V_17 -> V_25 ) {
V_17 -> V_9 = V_23 ;
return true ;
} else {
V_17 -> V_9 = V_24 ;
}
break;
case V_23 :
if ( V_18 < V_17 -> V_26 )
V_17 -> V_9 = V_24 ;
else if ( V_17 -> V_26 < V_18 && V_18 < V_17 -> V_27 + V_17 -> V_26 ) {
V_17 -> V_9 = V_19 ;
} else if ( V_17 -> V_27 + V_17 -> V_26 < V_18 ) {
V_17 -> V_9 = V_23 ;
return true ;
}
break;
case V_21 :
V_17 -> V_9 = V_19 ;
break;
}
return false ;
}
static bool F_9 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_17 ;
switch ( V_17 -> V_9 ) {
case V_28 :
if ( F_6 () < V_17 -> V_22 )
V_17 -> V_9 = V_29 ;
if ( F_6 () < V_17 -> V_20 )
return true ;
break;
case V_29 :
if ( F_6 () < V_17 -> V_27 )
V_17 -> V_9 = V_28 ;
if ( F_6 () > V_17 -> V_26 )
return true ;
}
return false ;
}
static bool F_10 ( struct V_14 * V_15 )
{
switch ( V_15 -> V_30 ) {
case V_31 :
return V_15 -> V_32 && V_15 -> V_32 >= F_7 ( & V_15 -> V_33 ) ;
case V_34 :
return F_8 ( V_15 ) ;
case V_35 :
return F_9 ( V_15 ) ;
}
return false ;
}
static T_3 F_11 ( T_3 V_36 , T_3 V_37 ,
struct V_8 * V_9 ,
const struct V_38 * V_39 )
{
T_3 V_40 ;
long V_41 ;
T_1 V_18 ;
if ( V_37 == 0 )
return V_36 ;
V_18 = F_7 ( V_9 ) ;
if ( V_39 == NULL )
return ( V_18 % ( 2 * V_37 ) ) - V_37 + V_36 ;
V_41 = V_39 -> V_42 [ V_18 % V_39 -> V_43 ] ;
V_40 = ( V_37 % V_44 ) * V_41 ;
if ( V_40 >= 0 )
V_40 += V_44 / 2 ;
else
V_40 -= V_44 / 2 ;
return V_40 / V_44 + ( V_37 / V_44 ) * V_41 + V_36 ;
}
static T_4 F_12 ( unsigned int V_45 , struct V_14 * V_15 )
{
T_2 V_46 ;
V_45 += V_15 -> V_47 ;
if ( V_15 -> V_48 ) {
T_1 V_49 = F_13 ( V_45 , V_15 -> V_50 ) ;
if ( V_45 > V_49 * V_15 -> V_48 )
V_49 ++ ;
V_45 = V_49 * ( V_15 -> V_48 + V_15 -> V_51 ) ;
}
V_46 = ( T_2 ) V_45 * V_52 ;
F_14 ( V_46 , V_15 -> V_53 ) ;
return F_15 ( V_46 ) ;
}
static void F_16 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_2 * V_56 ;
while ( ( V_56 = F_18 ( & V_15 -> V_57 ) ) ) {
struct V_1 * V_6 = F_1 ( V_56 ) ;
F_19 ( V_56 , & V_15 -> V_57 ) ;
V_6 -> V_58 = NULL ;
V_6 -> V_59 = NULL ;
F_20 ( V_6 ) ;
}
}
static void F_21 ( struct V_1 * V_60 , struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
T_4 V_61 = V_5 ( V_60 ) -> V_62 ;
struct V_2 * * V_56 = & V_15 -> V_57 . V_2 , * V_63 = NULL ;
while ( * V_56 ) {
struct V_1 * V_6 ;
V_63 = * V_56 ;
V_6 = F_1 ( V_63 ) ;
if ( V_61 >= V_5 ( V_6 ) -> V_62 )
V_56 = & V_63 -> V_64 ;
else
V_56 = & V_63 -> V_65 ;
}
F_22 ( & V_60 -> V_4 , V_63 , V_56 ) ;
F_23 ( & V_60 -> V_4 , & V_15 -> V_57 ) ;
V_55 -> V_15 . V_66 ++ ;
}
static int F_24 ( struct V_1 * V_6 , struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_5 * V_67 ;
struct V_1 * V_68 ;
int V_69 = 1 ;
if ( V_15 -> V_70 && V_15 -> V_70 >= F_7 ( & V_15 -> V_71 ) )
++ V_69 ;
if ( F_10 ( V_15 ) ) {
if ( V_15 -> V_72 && F_25 ( V_6 ) )
F_26 ( V_55 ) ;
else
-- V_69 ;
}
if ( V_69 == 0 ) {
F_26 ( V_55 ) ;
F_20 ( V_6 ) ;
return V_73 | V_74 ;
}
if ( V_15 -> V_75 || V_15 -> V_76 )
F_27 ( V_6 ) ;
if ( V_69 > 1 && ( V_68 = F_28 ( V_6 , V_77 ) ) != NULL ) {
struct V_54 * V_78 = F_29 ( V_55 ) ;
T_1 V_79 = V_15 -> V_70 ;
V_15 -> V_70 = 0 ;
V_78 -> V_80 ( V_68 , V_78 ) ;
V_15 -> V_70 = V_79 ;
}
if ( V_15 -> V_81 && V_15 -> V_81 >= F_7 ( & V_15 -> V_82 ) ) {
if ( ! ( V_6 = F_30 ( V_6 , V_77 ) ) ||
( V_6 -> V_83 == V_84 &&
F_31 ( V_6 ) ) )
return F_32 ( V_6 , V_55 ) ;
V_6 -> V_7 [ F_6 () % F_33 ( V_6 ) ] ^=
1 << ( F_6 () % 8 ) ;
}
if ( F_34 ( F_35 ( & V_55 -> V_15 ) >= V_55 -> V_85 ) )
return F_36 ( V_6 , V_55 ) ;
F_37 ( V_55 , V_6 ) ;
V_67 = V_5 ( V_6 ) ;
if ( V_15 -> V_86 == 0 ||
V_15 -> V_87 < V_15 -> V_86 - 1 ||
V_15 -> V_88 < F_7 ( & V_15 -> V_89 ) ) {
T_4 V_90 ;
T_3 V_91 ;
V_91 = F_11 ( V_15 -> V_75 , V_15 -> V_76 ,
& V_15 -> V_92 , V_15 -> V_93 ) ;
V_90 = F_38 () ;
if ( V_15 -> V_53 ) {
struct V_1 * V_11 ;
if ( ! F_39 ( & V_55 -> V_15 ) )
V_11 = F_40 ( & V_55 -> V_15 ) ;
else
V_11 = F_1 ( F_41 ( & V_15 -> V_57 ) ) ;
if ( V_11 ) {
V_91 -= V_5 ( V_11 ) -> V_62 - V_90 ;
V_91 = F_42 ( T_3 , 0 , V_91 ) ;
V_90 = V_5 ( V_11 ) -> V_62 ;
}
V_91 += F_12 ( F_43 ( V_6 ) , V_15 ) ;
}
V_67 -> V_62 = V_90 + V_91 ;
V_67 -> V_94 = V_6 -> V_95 ;
++ V_15 -> V_87 ;
F_21 ( V_6 , V_55 ) ;
} else {
V_67 -> V_62 = F_38 () ;
V_15 -> V_87 = 0 ;
F_44 ( & V_55 -> V_15 , V_6 ) ;
V_55 -> V_96 . V_97 ++ ;
}
return V_73 ;
}
static unsigned int F_45 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
unsigned int V_45 ;
V_45 = F_46 ( V_55 ) ;
if ( ! V_45 ) {
struct V_2 * V_56 = F_18 ( & V_15 -> V_57 ) ;
if ( V_56 ) {
struct V_1 * V_6 = F_1 ( V_56 ) ;
F_19 ( V_56 , & V_15 -> V_57 ) ;
V_55 -> V_15 . V_66 -- ;
V_6 -> V_58 = NULL ;
V_6 -> V_59 = NULL ;
F_47 ( V_55 , V_6 ) ;
F_20 ( V_6 ) ;
}
}
if ( ! V_45 && V_15 -> V_98 && V_15 -> V_98 -> V_99 -> V_100 )
V_45 = V_15 -> V_98 -> V_99 -> V_100 ( V_15 -> V_98 ) ;
if ( V_45 )
F_26 ( V_55 ) ;
return V_45 ;
}
static struct V_1 * F_48 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_1 * V_6 ;
struct V_2 * V_56 ;
if ( F_49 ( V_55 ) )
return NULL ;
V_101:
V_6 = F_50 ( & V_55 -> V_15 ) ;
if ( V_6 ) {
F_47 ( V_55 , V_6 ) ;
V_102:
F_51 ( V_55 ) ;
F_52 ( V_55 , V_6 ) ;
return V_6 ;
}
V_56 = F_18 ( & V_15 -> V_57 ) ;
if ( V_56 ) {
T_4 V_62 ;
V_6 = F_1 ( V_56 ) ;
V_62 = V_5 ( V_6 ) -> V_62 ;
if ( V_62 <= F_38 () ) {
F_19 ( V_56 , & V_15 -> V_57 ) ;
V_55 -> V_15 . V_66 -- ;
F_47 ( V_55 , V_6 ) ;
V_6 -> V_58 = NULL ;
V_6 -> V_59 = NULL ;
V_6 -> V_95 = V_5 ( V_6 ) -> V_94 ;
#ifdef F_53
if ( F_54 ( V_6 -> V_103 ) & V_104 )
V_6 -> V_95 . V_105 = 0 ;
#endif
if ( V_15 -> V_98 ) {
int V_106 = F_55 ( V_6 , V_15 -> V_98 ) ;
if ( F_34 ( V_106 != V_73 ) ) {
if ( F_56 ( V_106 ) ) {
F_26 ( V_55 ) ;
F_57 ( V_55 , 1 ) ;
}
}
goto V_101;
}
goto V_102;
}
if ( V_15 -> V_98 ) {
V_6 = V_15 -> V_98 -> V_99 -> V_107 ( V_15 -> V_98 ) ;
if ( V_6 )
goto V_102;
}
F_58 ( & V_15 -> V_108 , V_62 ) ;
}
if ( V_15 -> V_98 ) {
V_6 = V_15 -> V_98 -> V_99 -> V_107 ( V_15 -> V_98 ) ;
if ( V_6 )
goto V_102;
}
return NULL ;
}
static void F_59 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
F_60 ( V_55 ) ;
F_16 ( V_55 ) ;
if ( V_15 -> V_98 )
F_61 ( V_15 -> V_98 ) ;
F_62 ( & V_15 -> V_108 ) ;
}
static void F_63 ( struct V_38 * V_109 )
{
F_64 ( V_109 ) ;
}
static int F_65 ( struct V_54 * V_55 , const struct V_110 * V_111 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
T_5 V_112 = F_66 ( V_111 ) / sizeof( V_113 ) ;
const V_113 * V_7 = F_67 ( V_111 ) ;
T_6 * V_114 ;
struct V_38 * V_109 ;
int V_115 ;
T_5 V_116 ;
if ( V_112 > V_117 )
return - V_118 ;
V_116 = sizeof( struct V_38 ) + V_112 * sizeof( V_119 ) ;
V_109 = F_68 ( V_116 , V_120 | V_121 ) ;
if ( ! V_109 )
V_109 = F_69 ( V_116 ) ;
if ( ! V_109 )
return - V_122 ;
V_109 -> V_43 = V_112 ;
for ( V_115 = 0 ; V_115 < V_112 ; V_115 ++ )
V_109 -> V_42 [ V_115 ] = V_7 [ V_115 ] ;
V_114 = F_70 ( V_55 ) ;
F_71 ( V_114 ) ;
F_72 ( V_15 -> V_93 , V_109 ) ;
F_73 ( V_114 ) ;
F_63 ( V_109 ) ;
return 0 ;
}
static void F_74 ( struct V_14 * V_15 , const struct V_110 * V_111 )
{
const struct V_123 * V_124 = F_67 ( V_111 ) ;
F_5 ( & V_15 -> V_92 , V_124 -> V_125 ) ;
F_5 ( & V_15 -> V_33 , V_124 -> V_126 ) ;
F_5 ( & V_15 -> V_71 , V_124 -> V_127 ) ;
}
static void F_75 ( struct V_14 * V_15 , const struct V_110 * V_111 )
{
const struct V_128 * V_129 = F_67 ( V_111 ) ;
V_15 -> V_88 = V_129 -> V_130 ;
F_5 ( & V_15 -> V_89 , V_129 -> V_131 ) ;
}
static void F_76 ( struct V_14 * V_15 , const struct V_110 * V_111 )
{
const struct V_132 * V_129 = F_67 ( V_111 ) ;
V_15 -> V_81 = V_129 -> V_130 ;
F_5 ( & V_15 -> V_82 , V_129 -> V_131 ) ;
}
static void F_77 ( struct V_14 * V_15 , const struct V_110 * V_111 )
{
const struct V_133 * V_129 = F_67 ( V_111 ) ;
V_15 -> V_53 = V_129 -> V_53 ;
V_15 -> V_47 = V_129 -> V_47 ;
V_15 -> V_48 = V_129 -> V_48 ;
V_15 -> V_51 = V_129 -> V_51 ;
if ( V_15 -> V_48 )
V_15 -> V_50 = F_78 ( V_15 -> V_48 ) ;
else
V_15 -> V_50 = (struct F_78 ) { 0 } ;
}
static int F_79 ( struct V_14 * V_15 , const struct V_110 * V_111 )
{
const struct V_110 * V_134 ;
int V_135 ;
F_80 (la, attr, rem) {
T_7 type = F_81 ( V_134 ) ;
switch ( type ) {
case V_136 : {
const struct V_137 * V_138 = F_67 ( V_134 ) ;
if ( F_66 ( V_134 ) < sizeof( struct V_137 ) ) {
F_82 ( L_1 ) ;
return - V_118 ;
}
V_15 -> V_30 = V_34 ;
V_15 -> V_17 . V_9 = V_19 ;
V_15 -> V_17 . V_22 = V_138 -> V_139 ;
V_15 -> V_17 . V_27 = V_138 -> V_140 ;
V_15 -> V_17 . V_26 = V_138 -> V_141 ;
V_15 -> V_17 . V_20 = V_138 -> V_142 ;
V_15 -> V_17 . V_25 = V_138 -> V_143 ;
break;
}
case V_144 : {
const struct V_145 * V_146 = F_67 ( V_134 ) ;
if ( F_66 ( V_134 ) < sizeof( struct V_145 ) ) {
F_82 ( L_2 ) ;
return - V_118 ;
}
V_15 -> V_30 = V_35 ;
V_15 -> V_17 . V_9 = V_28 ;
V_15 -> V_17 . V_22 = V_146 -> V_56 ;
V_15 -> V_17 . V_27 = V_146 -> V_129 ;
V_15 -> V_17 . V_26 = V_146 -> V_147 ;
V_15 -> V_17 . V_20 = V_146 -> V_148 ;
break;
}
default:
F_82 ( L_3 , type ) ;
return - V_118 ;
}
}
return 0 ;
}
static int F_83 ( struct V_110 * V_149 [] , int V_150 , struct V_110 * V_151 ,
const struct V_152 * V_153 , int V_45 )
{
int V_154 = F_66 ( V_151 ) - F_84 ( V_45 ) ;
if ( V_154 < 0 ) {
F_82 ( L_4 , V_154 ) ;
return - V_118 ;
}
if ( V_154 >= F_85 ( 0 ) )
return F_86 ( V_149 , V_150 , F_67 ( V_151 ) + F_84 ( V_45 ) ,
V_154 , V_153 ) ;
memset ( V_149 , 0 , sizeof( struct V_110 * ) * ( V_150 + 1 ) ) ;
return 0 ;
}
static int F_87 ( struct V_54 * V_55 , struct V_110 * V_155 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_110 * V_149 [ V_156 + 1 ] ;
struct V_157 * V_158 ;
struct V_16 V_159 ;
int V_160 = V_31 ;
int V_161 ;
if ( V_155 == NULL )
return - V_118 ;
V_158 = F_67 ( V_155 ) ;
V_161 = F_83 ( V_149 , V_156 , V_155 , V_162 , sizeof( * V_158 ) ) ;
if ( V_161 < 0 )
return V_161 ;
V_159 = V_15 -> V_17 ;
V_160 = V_15 -> V_30 ;
if ( V_149 [ V_163 ] ) {
V_161 = F_79 ( V_15 , V_149 [ V_163 ] ) ;
if ( V_161 ) {
V_15 -> V_30 = V_160 ;
return V_161 ;
}
} else {
V_15 -> V_30 = V_31 ;
}
if ( V_149 [ V_164 ] ) {
V_161 = F_65 ( V_55 , V_149 [ V_164 ] ) ;
if ( V_161 ) {
V_15 -> V_17 = V_159 ;
V_15 -> V_30 = V_160 ;
return V_161 ;
}
}
V_55 -> V_85 = V_158 -> V_85 ;
V_15 -> V_75 = V_158 -> V_75 ;
V_15 -> V_76 = V_158 -> V_76 ;
V_15 -> V_85 = V_158 -> V_85 ;
V_15 -> V_86 = V_158 -> V_86 ;
V_15 -> V_87 = 0 ;
V_15 -> V_32 = V_158 -> V_32 ;
V_15 -> V_70 = V_158 -> V_70 ;
if ( V_15 -> V_86 )
V_15 -> V_88 = ~ 0 ;
if ( V_149 [ V_165 ] )
F_74 ( V_15 , V_149 [ V_165 ] ) ;
if ( V_149 [ V_166 ] )
F_75 ( V_15 , V_149 [ V_166 ] ) ;
if ( V_149 [ V_167 ] )
F_76 ( V_15 , V_149 [ V_167 ] ) ;
if ( V_149 [ V_168 ] )
F_77 ( V_15 , V_149 [ V_168 ] ) ;
if ( V_149 [ V_169 ] )
V_15 -> V_53 = F_42 ( T_2 , V_15 -> V_53 ,
F_88 ( V_149 [ V_169 ] ) ) ;
if ( V_149 [ V_170 ] )
V_15 -> V_72 = F_89 ( V_149 [ V_170 ] ) ;
return V_161 ;
}
static int F_90 ( struct V_54 * V_55 , struct V_110 * V_155 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
int V_161 ;
if ( ! V_155 )
return - V_118 ;
F_91 ( & V_15 -> V_108 , V_55 ) ;
V_15 -> V_30 = V_31 ;
V_161 = F_87 ( V_55 , V_155 ) ;
if ( V_161 )
F_82 ( L_5 ) ;
return V_161 ;
}
static void F_92 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
F_62 ( & V_15 -> V_108 ) ;
if ( V_15 -> V_98 )
F_93 ( V_15 -> V_98 ) ;
F_63 ( V_15 -> V_93 ) ;
}
static int F_94 ( const struct V_14 * V_15 ,
struct V_1 * V_6 )
{
struct V_110 * V_171 ;
V_171 = F_95 ( V_6 , V_163 ) ;
if ( V_171 == NULL )
goto V_172;
switch ( V_15 -> V_30 ) {
case V_31 :
F_96 ( V_6 , V_171 ) ;
return 0 ;
case V_34 : {
struct V_137 V_138 = {
. V_139 = V_15 -> V_17 . V_22 ,
. V_140 = V_15 -> V_17 . V_27 ,
. V_141 = V_15 -> V_17 . V_26 ,
. V_142 = V_15 -> V_17 . V_20 ,
. V_143 = V_15 -> V_17 . V_25 ,
} ;
if ( F_97 ( V_6 , V_136 , sizeof( V_138 ) , & V_138 ) )
goto V_172;
break;
}
case V_35 : {
struct V_145 V_146 = {
. V_56 = V_15 -> V_17 . V_22 ,
. V_129 = V_15 -> V_17 . V_27 ,
. V_147 = V_15 -> V_17 . V_26 ,
. V_148 = V_15 -> V_17 . V_20 ,
} ;
if ( F_97 ( V_6 , V_144 , sizeof( V_146 ) , & V_146 ) )
goto V_172;
break;
}
}
F_98 ( V_6 , V_171 ) ;
return 0 ;
V_172:
F_96 ( V_6 , V_171 ) ;
return - 1 ;
}
static int F_99 ( struct V_54 * V_55 , struct V_1 * V_6 )
{
const struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_110 * V_151 = (struct V_110 * ) F_100 ( V_6 ) ;
struct V_157 V_158 ;
struct V_123 V_173 ;
struct V_128 V_88 ;
struct V_132 V_81 ;
struct V_133 V_53 ;
V_158 . V_75 = V_15 -> V_75 ;
V_158 . V_76 = V_15 -> V_76 ;
V_158 . V_85 = V_15 -> V_85 ;
V_158 . V_32 = V_15 -> V_32 ;
V_158 . V_86 = V_15 -> V_86 ;
V_158 . V_70 = V_15 -> V_70 ;
if ( F_97 ( V_6 , V_174 , sizeof( V_158 ) , & V_158 ) )
goto V_172;
V_173 . V_125 = V_15 -> V_92 . V_10 ;
V_173 . V_126 = V_15 -> V_33 . V_10 ;
V_173 . V_127 = V_15 -> V_71 . V_10 ;
if ( F_97 ( V_6 , V_165 , sizeof( V_173 ) , & V_173 ) )
goto V_172;
V_88 . V_130 = V_15 -> V_88 ;
V_88 . V_131 = V_15 -> V_89 . V_10 ;
if ( F_97 ( V_6 , V_166 , sizeof( V_88 ) , & V_88 ) )
goto V_172;
V_81 . V_130 = V_15 -> V_81 ;
V_81 . V_131 = V_15 -> V_82 . V_10 ;
if ( F_97 ( V_6 , V_167 , sizeof( V_81 ) , & V_81 ) )
goto V_172;
if ( V_15 -> V_53 >= ( 1ULL << 32 ) ) {
if ( F_101 ( V_6 , V_169 , V_15 -> V_53 ) )
goto V_172;
V_53 . V_53 = ~ 0U ;
} else {
V_53 . V_53 = V_15 -> V_53 ;
}
V_53 . V_47 = V_15 -> V_47 ;
V_53 . V_48 = V_15 -> V_48 ;
V_53 . V_51 = V_15 -> V_51 ;
if ( F_97 ( V_6 , V_168 , sizeof( V_53 ) , & V_53 ) )
goto V_172;
if ( V_15 -> V_72 && F_102 ( V_6 , V_170 , V_15 -> V_72 ) )
goto V_172;
if ( F_94 ( V_15 , V_6 ) != 0 )
goto V_172;
return F_98 ( V_6 , V_151 ) ;
V_172:
F_103 ( V_6 , V_151 ) ;
return - 1 ;
}
static int F_104 ( struct V_54 * V_55 , unsigned long V_175 ,
struct V_1 * V_6 , struct V_176 * V_177 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
if ( V_175 != 1 || ! V_15 -> V_98 )
return - V_178 ;
V_177 -> V_179 |= F_105 ( 1 ) ;
V_177 -> V_180 = V_15 -> V_98 -> V_181 ;
return 0 ;
}
static int F_106 ( struct V_54 * V_55 , unsigned long V_182 , struct V_54 * V_183 ,
struct V_54 * * V_184 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
F_107 ( V_55 ) ;
* V_184 = V_15 -> V_98 ;
V_15 -> V_98 = V_183 ;
if ( * V_184 ) {
F_57 ( * V_184 , ( * V_184 ) -> V_15 . V_66 ) ;
F_61 ( * V_184 ) ;
}
F_108 ( V_55 ) ;
return 0 ;
}
static struct V_54 * F_109 ( struct V_54 * V_55 , unsigned long V_182 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
return V_15 -> V_98 ;
}
static unsigned long F_110 ( struct V_54 * V_55 , T_1 V_185 )
{
return 1 ;
}
static void F_111 ( struct V_54 * V_55 , unsigned long V_182 )
{
}
static void F_112 ( struct V_54 * V_55 , struct V_186 * V_187 )
{
if ( ! V_187 -> V_188 ) {
if ( V_187 -> V_69 >= V_187 -> V_189 )
if ( V_187 -> V_190 ( V_55 , 1 , V_187 ) < 0 ) {
V_187 -> V_188 = 1 ;
return;
}
V_187 -> V_69 ++ ;
}
}
static int T_8 F_113 ( void )
{
F_82 ( L_6 V_191 L_7 ) ;
return F_114 ( & V_192 ) ;
}
static void T_9 F_115 ( void )
{
F_116 ( & V_192 ) ;
}
