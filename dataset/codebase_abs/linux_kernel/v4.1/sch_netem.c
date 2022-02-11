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
F_30 ( V_68 , V_78 ) ;
V_15 -> V_70 = V_79 ;
}
if ( V_15 -> V_80 && V_15 -> V_80 >= F_7 ( & V_15 -> V_81 ) ) {
if ( ! ( V_6 = F_31 ( V_6 , V_77 ) ) ||
( V_6 -> V_82 == V_83 &&
F_32 ( V_6 ) ) )
return F_33 ( V_6 , V_55 ) ;
V_6 -> V_7 [ F_6 () % F_34 ( V_6 ) ] ^=
1 << ( F_6 () % 8 ) ;
}
if ( F_35 ( F_36 ( & V_55 -> V_15 ) >= V_55 -> V_84 ) )
return F_37 ( V_6 , V_55 ) ;
F_38 ( V_55 , V_6 ) ;
V_67 = V_5 ( V_6 ) ;
if ( V_15 -> V_85 == 0 ||
V_15 -> V_86 < V_15 -> V_85 - 1 ||
V_15 -> V_87 < F_7 ( & V_15 -> V_88 ) ) {
T_4 V_89 ;
T_3 V_90 ;
V_90 = F_11 ( V_15 -> V_75 , V_15 -> V_76 ,
& V_15 -> V_91 , V_15 -> V_92 ) ;
V_89 = F_39 () ;
if ( V_15 -> V_53 ) {
struct V_1 * V_11 ;
if ( ! F_40 ( & V_55 -> V_15 ) )
V_11 = F_41 ( & V_55 -> V_15 ) ;
else
V_11 = F_1 ( F_42 ( & V_15 -> V_57 ) ) ;
if ( V_11 ) {
V_90 -= V_5 ( V_11 ) -> V_62 - V_89 ;
V_90 = F_43 ( T_3 , 0 , V_90 ) ;
V_89 = V_5 ( V_11 ) -> V_62 ;
}
V_90 += F_12 ( F_44 ( V_6 ) , V_15 ) ;
}
V_67 -> V_62 = V_89 + V_90 ;
V_67 -> V_93 = V_6 -> V_94 ;
++ V_15 -> V_86 ;
F_21 ( V_6 , V_55 ) ;
} else {
V_67 -> V_62 = F_39 () ;
V_15 -> V_86 = 0 ;
F_45 ( & V_55 -> V_15 , V_6 ) ;
V_55 -> V_95 . V_96 ++ ;
}
return V_73 ;
}
static unsigned int F_46 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
unsigned int V_45 ;
V_45 = F_47 ( V_55 ) ;
if ( ! V_45 ) {
struct V_2 * V_56 = F_18 ( & V_15 -> V_57 ) ;
if ( V_56 ) {
struct V_1 * V_6 = F_1 ( V_56 ) ;
F_19 ( V_56 , & V_15 -> V_57 ) ;
V_55 -> V_15 . V_66 -- ;
V_6 -> V_58 = NULL ;
V_6 -> V_59 = NULL ;
F_48 ( V_55 , V_6 ) ;
F_20 ( V_6 ) ;
}
}
if ( ! V_45 && V_15 -> V_97 && V_15 -> V_97 -> V_98 -> V_99 )
V_45 = V_15 -> V_97 -> V_98 -> V_99 ( V_15 -> V_97 ) ;
if ( V_45 )
F_26 ( V_55 ) ;
return V_45 ;
}
static struct V_1 * F_49 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_1 * V_6 ;
struct V_2 * V_56 ;
if ( F_50 ( V_55 ) )
return NULL ;
V_100:
V_6 = F_51 ( & V_55 -> V_15 ) ;
if ( V_6 ) {
F_48 ( V_55 , V_6 ) ;
V_101:
F_52 ( V_55 ) ;
F_53 ( V_55 , V_6 ) ;
return V_6 ;
}
V_56 = F_18 ( & V_15 -> V_57 ) ;
if ( V_56 ) {
T_4 V_62 ;
V_6 = F_1 ( V_56 ) ;
V_62 = V_5 ( V_6 ) -> V_62 ;
if ( V_62 <= F_39 () ) {
F_19 ( V_56 , & V_15 -> V_57 ) ;
V_55 -> V_15 . V_66 -- ;
F_48 ( V_55 , V_6 ) ;
V_6 -> V_58 = NULL ;
V_6 -> V_59 = NULL ;
V_6 -> V_94 = V_5 ( V_6 ) -> V_93 ;
#ifdef F_54
if ( F_55 ( V_6 -> V_102 ) & V_103 )
V_6 -> V_94 . V_104 = 0 ;
#endif
if ( V_15 -> V_97 ) {
int V_105 = F_56 ( V_6 , V_15 -> V_97 ) ;
if ( F_35 ( V_105 != V_73 ) ) {
if ( F_57 ( V_105 ) ) {
F_26 ( V_55 ) ;
F_58 ( V_55 , 1 ) ;
}
}
goto V_100;
}
goto V_101;
}
if ( V_15 -> V_97 ) {
V_6 = V_15 -> V_97 -> V_98 -> V_106 ( V_15 -> V_97 ) ;
if ( V_6 )
goto V_101;
}
F_59 ( & V_15 -> V_107 , V_62 ) ;
}
if ( V_15 -> V_97 ) {
V_6 = V_15 -> V_97 -> V_98 -> V_106 ( V_15 -> V_97 ) ;
if ( V_6 )
goto V_101;
}
return NULL ;
}
static void F_60 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
F_61 ( V_55 ) ;
F_16 ( V_55 ) ;
if ( V_15 -> V_97 )
F_62 ( V_15 -> V_97 ) ;
F_63 ( & V_15 -> V_107 ) ;
}
static void F_64 ( struct V_38 * V_108 )
{
F_65 ( V_108 ) ;
}
static int F_66 ( struct V_54 * V_55 , const struct V_109 * V_110 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
T_5 V_111 = F_67 ( V_110 ) / sizeof( V_112 ) ;
const V_112 * V_7 = F_68 ( V_110 ) ;
T_6 * V_113 ;
struct V_38 * V_108 ;
int V_114 ;
T_5 V_115 ;
if ( V_111 > V_116 )
return - V_117 ;
V_115 = sizeof( struct V_38 ) + V_111 * sizeof( V_118 ) ;
V_108 = F_69 ( V_115 , V_119 | V_120 ) ;
if ( ! V_108 )
V_108 = F_70 ( V_115 ) ;
if ( ! V_108 )
return - V_121 ;
V_108 -> V_43 = V_111 ;
for ( V_114 = 0 ; V_114 < V_111 ; V_114 ++ )
V_108 -> V_42 [ V_114 ] = V_7 [ V_114 ] ;
V_113 = F_71 ( V_55 ) ;
F_72 ( V_113 ) ;
F_73 ( V_15 -> V_92 , V_108 ) ;
F_74 ( V_113 ) ;
F_64 ( V_108 ) ;
return 0 ;
}
static void F_75 ( struct V_14 * V_15 , const struct V_109 * V_110 )
{
const struct V_122 * V_123 = F_68 ( V_110 ) ;
F_5 ( & V_15 -> V_91 , V_123 -> V_124 ) ;
F_5 ( & V_15 -> V_33 , V_123 -> V_125 ) ;
F_5 ( & V_15 -> V_71 , V_123 -> V_126 ) ;
}
static void F_76 ( struct V_14 * V_15 , const struct V_109 * V_110 )
{
const struct V_127 * V_128 = F_68 ( V_110 ) ;
V_15 -> V_87 = V_128 -> V_129 ;
F_5 ( & V_15 -> V_88 , V_128 -> V_130 ) ;
}
static void F_77 ( struct V_14 * V_15 , const struct V_109 * V_110 )
{
const struct V_131 * V_128 = F_68 ( V_110 ) ;
V_15 -> V_80 = V_128 -> V_129 ;
F_5 ( & V_15 -> V_81 , V_128 -> V_130 ) ;
}
static void F_78 ( struct V_14 * V_15 , const struct V_109 * V_110 )
{
const struct V_132 * V_128 = F_68 ( V_110 ) ;
V_15 -> V_53 = V_128 -> V_53 ;
V_15 -> V_47 = V_128 -> V_47 ;
V_15 -> V_48 = V_128 -> V_48 ;
V_15 -> V_51 = V_128 -> V_51 ;
if ( V_15 -> V_48 )
V_15 -> V_50 = F_79 ( V_15 -> V_48 ) ;
else
V_15 -> V_50 = (struct F_79 ) { 0 } ;
}
static int F_80 ( struct V_14 * V_15 , const struct V_109 * V_110 )
{
const struct V_109 * V_133 ;
int V_134 ;
F_81 (la, attr, rem) {
T_7 type = F_82 ( V_133 ) ;
switch ( type ) {
case V_135 : {
const struct V_136 * V_137 = F_68 ( V_133 ) ;
if ( F_67 ( V_133 ) < sizeof( struct V_136 ) ) {
F_83 ( L_1 ) ;
return - V_117 ;
}
V_15 -> V_30 = V_34 ;
V_15 -> V_17 . V_9 = V_19 ;
V_15 -> V_17 . V_22 = V_137 -> V_138 ;
V_15 -> V_17 . V_27 = V_137 -> V_139 ;
V_15 -> V_17 . V_26 = V_137 -> V_140 ;
V_15 -> V_17 . V_20 = V_137 -> V_141 ;
V_15 -> V_17 . V_25 = V_137 -> V_142 ;
break;
}
case V_143 : {
const struct V_144 * V_145 = F_68 ( V_133 ) ;
if ( F_67 ( V_133 ) < sizeof( struct V_144 ) ) {
F_83 ( L_2 ) ;
return - V_117 ;
}
V_15 -> V_30 = V_35 ;
V_15 -> V_17 . V_9 = V_28 ;
V_15 -> V_17 . V_22 = V_145 -> V_56 ;
V_15 -> V_17 . V_27 = V_145 -> V_128 ;
V_15 -> V_17 . V_26 = V_145 -> V_146 ;
V_15 -> V_17 . V_20 = V_145 -> V_147 ;
break;
}
default:
F_83 ( L_3 , type ) ;
return - V_117 ;
}
}
return 0 ;
}
static int F_84 ( struct V_109 * V_148 [] , int V_149 , struct V_109 * V_150 ,
const struct V_151 * V_152 , int V_45 )
{
int V_153 = F_67 ( V_150 ) - F_85 ( V_45 ) ;
if ( V_153 < 0 ) {
F_83 ( L_4 , V_153 ) ;
return - V_117 ;
}
if ( V_153 >= F_86 ( 0 ) )
return F_87 ( V_148 , V_149 , F_68 ( V_150 ) + F_85 ( V_45 ) ,
V_153 , V_152 ) ;
memset ( V_148 , 0 , sizeof( struct V_109 * ) * ( V_149 + 1 ) ) ;
return 0 ;
}
static int F_88 ( struct V_54 * V_55 , struct V_109 * V_154 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_109 * V_148 [ V_155 + 1 ] ;
struct V_156 * V_157 ;
struct V_16 V_158 ;
int V_159 = V_31 ;
int V_160 ;
if ( V_154 == NULL )
return - V_117 ;
V_157 = F_68 ( V_154 ) ;
V_160 = F_84 ( V_148 , V_155 , V_154 , V_161 , sizeof( * V_157 ) ) ;
if ( V_160 < 0 )
return V_160 ;
V_158 = V_15 -> V_17 ;
V_159 = V_15 -> V_30 ;
if ( V_148 [ V_162 ] ) {
V_160 = F_80 ( V_15 , V_148 [ V_162 ] ) ;
if ( V_160 ) {
V_15 -> V_30 = V_159 ;
return V_160 ;
}
} else {
V_15 -> V_30 = V_31 ;
}
if ( V_148 [ V_163 ] ) {
V_160 = F_66 ( V_55 , V_148 [ V_163 ] ) ;
if ( V_160 ) {
V_15 -> V_17 = V_158 ;
V_15 -> V_30 = V_159 ;
return V_160 ;
}
}
V_55 -> V_84 = V_157 -> V_84 ;
V_15 -> V_75 = V_157 -> V_75 ;
V_15 -> V_76 = V_157 -> V_76 ;
V_15 -> V_84 = V_157 -> V_84 ;
V_15 -> V_85 = V_157 -> V_85 ;
V_15 -> V_86 = 0 ;
V_15 -> V_32 = V_157 -> V_32 ;
V_15 -> V_70 = V_157 -> V_70 ;
if ( V_15 -> V_85 )
V_15 -> V_87 = ~ 0 ;
if ( V_148 [ V_164 ] )
F_75 ( V_15 , V_148 [ V_164 ] ) ;
if ( V_148 [ V_165 ] )
F_76 ( V_15 , V_148 [ V_165 ] ) ;
if ( V_148 [ V_166 ] )
F_77 ( V_15 , V_148 [ V_166 ] ) ;
if ( V_148 [ V_167 ] )
F_78 ( V_15 , V_148 [ V_167 ] ) ;
if ( V_148 [ V_168 ] )
V_15 -> V_53 = F_43 ( T_2 , V_15 -> V_53 ,
F_89 ( V_148 [ V_168 ] ) ) ;
if ( V_148 [ V_169 ] )
V_15 -> V_72 = F_90 ( V_148 [ V_169 ] ) ;
return V_160 ;
}
static int F_91 ( struct V_54 * V_55 , struct V_109 * V_154 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
int V_160 ;
if ( ! V_154 )
return - V_117 ;
F_92 ( & V_15 -> V_107 , V_55 ) ;
V_15 -> V_30 = V_31 ;
V_160 = F_88 ( V_55 , V_154 ) ;
if ( V_160 )
F_83 ( L_5 ) ;
return V_160 ;
}
static void F_93 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
F_63 ( & V_15 -> V_107 ) ;
if ( V_15 -> V_97 )
F_94 ( V_15 -> V_97 ) ;
F_64 ( V_15 -> V_92 ) ;
}
static int F_95 ( const struct V_14 * V_15 ,
struct V_1 * V_6 )
{
struct V_109 * V_170 ;
V_170 = F_96 ( V_6 , V_162 ) ;
if ( V_170 == NULL )
goto V_171;
switch ( V_15 -> V_30 ) {
case V_31 :
F_97 ( V_6 , V_170 ) ;
return 0 ;
case V_34 : {
struct V_136 V_137 = {
. V_138 = V_15 -> V_17 . V_22 ,
. V_139 = V_15 -> V_17 . V_27 ,
. V_140 = V_15 -> V_17 . V_26 ,
. V_141 = V_15 -> V_17 . V_20 ,
. V_142 = V_15 -> V_17 . V_25 ,
} ;
if ( F_98 ( V_6 , V_135 , sizeof( V_137 ) , & V_137 ) )
goto V_171;
break;
}
case V_35 : {
struct V_144 V_145 = {
. V_56 = V_15 -> V_17 . V_22 ,
. V_128 = V_15 -> V_17 . V_27 ,
. V_146 = V_15 -> V_17 . V_26 ,
. V_147 = V_15 -> V_17 . V_20 ,
} ;
if ( F_98 ( V_6 , V_143 , sizeof( V_145 ) , & V_145 ) )
goto V_171;
break;
}
}
F_99 ( V_6 , V_170 ) ;
return 0 ;
V_171:
F_97 ( V_6 , V_170 ) ;
return - 1 ;
}
static int F_100 ( struct V_54 * V_55 , struct V_1 * V_6 )
{
const struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_109 * V_150 = (struct V_109 * ) F_101 ( V_6 ) ;
struct V_156 V_157 ;
struct V_122 V_172 ;
struct V_127 V_87 ;
struct V_131 V_80 ;
struct V_132 V_53 ;
V_157 . V_75 = V_15 -> V_75 ;
V_157 . V_76 = V_15 -> V_76 ;
V_157 . V_84 = V_15 -> V_84 ;
V_157 . V_32 = V_15 -> V_32 ;
V_157 . V_85 = V_15 -> V_85 ;
V_157 . V_70 = V_15 -> V_70 ;
if ( F_98 ( V_6 , V_173 , sizeof( V_157 ) , & V_157 ) )
goto V_171;
V_172 . V_124 = V_15 -> V_91 . V_10 ;
V_172 . V_125 = V_15 -> V_33 . V_10 ;
V_172 . V_126 = V_15 -> V_71 . V_10 ;
if ( F_98 ( V_6 , V_164 , sizeof( V_172 ) , & V_172 ) )
goto V_171;
V_87 . V_129 = V_15 -> V_87 ;
V_87 . V_130 = V_15 -> V_88 . V_10 ;
if ( F_98 ( V_6 , V_165 , sizeof( V_87 ) , & V_87 ) )
goto V_171;
V_80 . V_129 = V_15 -> V_80 ;
V_80 . V_130 = V_15 -> V_81 . V_10 ;
if ( F_98 ( V_6 , V_166 , sizeof( V_80 ) , & V_80 ) )
goto V_171;
if ( V_15 -> V_53 >= ( 1ULL << 32 ) ) {
if ( F_102 ( V_6 , V_168 , V_15 -> V_53 ) )
goto V_171;
V_53 . V_53 = ~ 0U ;
} else {
V_53 . V_53 = V_15 -> V_53 ;
}
V_53 . V_47 = V_15 -> V_47 ;
V_53 . V_48 = V_15 -> V_48 ;
V_53 . V_51 = V_15 -> V_51 ;
if ( F_98 ( V_6 , V_167 , sizeof( V_53 ) , & V_53 ) )
goto V_171;
if ( V_15 -> V_72 && F_103 ( V_6 , V_169 , V_15 -> V_72 ) )
goto V_171;
if ( F_95 ( V_15 , V_6 ) != 0 )
goto V_171;
return F_99 ( V_6 , V_150 ) ;
V_171:
F_104 ( V_6 , V_150 ) ;
return - 1 ;
}
static int F_105 ( struct V_54 * V_55 , unsigned long V_174 ,
struct V_1 * V_6 , struct V_175 * V_176 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
if ( V_174 != 1 || ! V_15 -> V_97 )
return - V_177 ;
V_176 -> V_178 |= F_106 ( 1 ) ;
V_176 -> V_179 = V_15 -> V_97 -> V_180 ;
return 0 ;
}
static int F_107 ( struct V_54 * V_55 , unsigned long V_181 , struct V_54 * V_182 ,
struct V_54 * * V_183 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
F_108 ( V_55 ) ;
* V_183 = V_15 -> V_97 ;
V_15 -> V_97 = V_182 ;
if ( * V_183 ) {
F_58 ( * V_183 , ( * V_183 ) -> V_15 . V_66 ) ;
F_62 ( * V_183 ) ;
}
F_109 ( V_55 ) ;
return 0 ;
}
static struct V_54 * F_110 ( struct V_54 * V_55 , unsigned long V_181 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
return V_15 -> V_97 ;
}
static unsigned long F_111 ( struct V_54 * V_55 , T_1 V_184 )
{
return 1 ;
}
static void F_112 ( struct V_54 * V_55 , unsigned long V_181 )
{
}
static void F_113 ( struct V_54 * V_55 , struct V_185 * V_186 )
{
if ( ! V_186 -> V_187 ) {
if ( V_186 -> V_69 >= V_186 -> V_188 )
if ( V_186 -> V_189 ( V_55 , 1 , V_186 ) < 0 ) {
V_186 -> V_187 = 1 ;
return;
}
V_186 -> V_69 ++ ;
}
}
static int T_8 F_114 ( void )
{
F_83 ( L_6 V_190 L_7 ) ;
return F_115 ( & V_191 ) ;
}
static void T_9 F_116 ( void )
{
F_117 ( & V_191 ) ;
}
