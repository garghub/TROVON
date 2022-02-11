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
F_20 ( V_6 , V_6 ) ;
}
}
static void F_21 ( struct V_1 * V_58 , struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
T_4 V_59 = V_5 ( V_58 ) -> V_60 ;
struct V_2 * * V_56 = & V_15 -> V_57 . V_2 , * V_61 = NULL ;
while ( * V_56 ) {
struct V_1 * V_6 ;
V_61 = * V_56 ;
V_6 = F_1 ( V_61 ) ;
if ( V_59 >= V_5 ( V_6 ) -> V_60 )
V_56 = & V_61 -> V_62 ;
else
V_56 = & V_61 -> V_63 ;
}
F_22 ( & V_58 -> V_4 , V_61 , V_56 ) ;
F_23 ( & V_58 -> V_4 , & V_15 -> V_57 ) ;
V_55 -> V_15 . V_64 ++ ;
}
static struct V_1 * F_24 ( struct V_1 * V_6 , struct V_54 * V_55 ,
struct V_1 * * V_65 )
{
struct V_1 * V_66 ;
T_5 V_67 = F_25 ( V_6 ) ;
V_66 = F_26 ( V_6 , V_67 & ~ V_68 ) ;
if ( F_27 ( V_66 ) ) {
F_28 ( V_6 , V_55 , V_65 ) ;
return NULL ;
}
F_29 ( V_6 ) ;
return V_66 ;
}
static int F_30 ( struct V_1 * V_6 , struct V_54 * V_55 ,
struct V_1 * * V_65 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_5 * V_69 ;
struct V_1 * V_70 ;
struct V_1 * V_66 = NULL ;
unsigned int V_45 = 0 , V_71 , V_72 = F_31 ( V_6 ) ;
int V_73 = 0 ;
int V_74 = 1 ;
int V_75 = V_76 ;
if ( V_15 -> V_77 && V_15 -> V_77 >= F_7 ( & V_15 -> V_78 ) )
++ V_74 ;
if ( F_10 ( V_15 ) ) {
if ( V_15 -> V_79 && F_32 ( V_6 ) )
F_33 ( V_55 ) ;
else
-- V_74 ;
}
if ( V_74 == 0 ) {
F_33 ( V_55 ) ;
F_34 ( V_6 , V_65 ) ;
return V_76 | V_80 ;
}
if ( V_15 -> V_81 || V_15 -> V_82 )
F_35 ( V_6 ) ;
if ( V_74 > 1 && ( V_70 = F_36 ( V_6 , V_83 ) ) != NULL ) {
struct V_54 * V_84 = F_37 ( V_55 ) ;
T_1 V_85 = V_15 -> V_77 ;
V_15 -> V_77 = 0 ;
V_84 -> V_86 ( V_70 , V_84 , V_65 ) ;
V_15 -> V_77 = V_85 ;
}
if ( V_15 -> V_87 && V_15 -> V_87 >= F_7 ( & V_15 -> V_88 ) ) {
if ( F_38 ( V_6 ) ) {
V_66 = F_24 ( V_6 , V_55 , V_65 ) ;
if ( ! V_66 )
return V_89 ;
} else {
V_66 = V_6 ;
}
V_6 = V_66 ;
V_66 = V_66 -> V_90 ;
V_6 = F_39 ( V_6 , V_83 ) ;
if ( F_40 ( ! V_6 ) ) {
F_33 ( V_55 ) ;
goto V_91;
}
if ( V_6 -> V_92 == V_93 &&
F_41 ( V_6 ) ) {
F_28 ( V_6 , V_55 , V_65 ) ;
goto V_91;
}
V_6 -> V_7 [ F_6 () % F_42 ( V_6 ) ] ^=
1 << ( F_6 () % 8 ) ;
}
if ( F_40 ( F_43 ( & V_55 -> V_15 ) >= V_55 -> V_94 ) )
return F_28 ( V_6 , V_55 , V_65 ) ;
F_44 ( V_55 , V_6 ) ;
V_69 = V_5 ( V_6 ) ;
if ( V_15 -> V_95 == 0 ||
V_15 -> V_96 < V_15 -> V_95 - 1 ||
V_15 -> V_97 < F_7 ( & V_15 -> V_98 ) ) {
T_4 V_99 ;
T_3 V_100 ;
V_100 = F_11 ( V_15 -> V_81 , V_15 -> V_82 ,
& V_15 -> V_101 , V_15 -> V_102 ) ;
V_99 = F_45 () ;
if ( V_15 -> V_53 ) {
struct V_1 * V_11 ;
if ( ! F_46 ( & V_55 -> V_15 ) )
V_11 = F_47 ( & V_55 -> V_15 ) ;
else
V_11 = F_1 ( F_48 ( & V_15 -> V_57 ) ) ;
if ( V_11 ) {
V_100 -= V_5 ( V_11 ) -> V_60 - V_99 ;
V_100 = F_49 ( T_3 , 0 , V_100 ) ;
V_99 = V_5 ( V_11 ) -> V_60 ;
}
V_100 += F_12 ( F_31 ( V_6 ) , V_15 ) ;
}
V_69 -> V_60 = V_99 + V_100 ;
V_69 -> V_103 = V_6 -> V_104 ;
++ V_15 -> V_96 ;
F_21 ( V_6 , V_55 ) ;
} else {
V_69 -> V_60 = F_45 () ;
V_15 -> V_96 = 0 ;
F_50 ( & V_55 -> V_15 , V_6 ) ;
V_55 -> V_105 . V_106 ++ ;
}
V_91:
if ( V_66 ) {
while ( V_66 ) {
V_70 = V_66 -> V_90 ;
V_66 -> V_90 = NULL ;
F_4 ( V_66 ) -> V_107 = V_66 -> V_45 ;
V_71 = V_66 -> V_45 ;
V_75 = F_51 ( V_66 , V_55 , V_65 ) ;
if ( V_75 != V_76 ) {
if ( F_52 ( V_75 ) )
F_33 ( V_55 ) ;
} else {
V_73 ++ ;
V_45 += V_71 ;
}
V_66 = V_70 ;
}
V_55 -> V_15 . V_64 += V_73 ;
if ( V_73 > 1 )
F_53 ( V_55 , 1 - V_73 , V_72 - V_45 ) ;
}
return V_76 ;
}
static struct V_1 * F_54 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_1 * V_6 ;
struct V_2 * V_56 ;
V_108:
V_6 = F_55 ( & V_55 -> V_15 ) ;
if ( V_6 ) {
F_56 ( V_55 , V_6 ) ;
V_109:
F_57 ( V_55 , V_6 ) ;
return V_6 ;
}
V_56 = F_18 ( & V_15 -> V_57 ) ;
if ( V_56 ) {
T_4 V_60 ;
V_6 = F_1 ( V_56 ) ;
V_60 = V_5 ( V_6 ) -> V_60 ;
if ( V_60 <= F_45 () ) {
F_19 ( V_56 , & V_15 -> V_57 ) ;
V_55 -> V_15 . V_64 -- ;
F_56 ( V_55 , V_6 ) ;
V_6 -> V_90 = NULL ;
V_6 -> V_110 = NULL ;
V_6 -> V_104 = V_5 ( V_6 ) -> V_103 ;
#ifdef F_58
if ( F_59 ( V_6 -> V_111 ) & V_112 )
V_6 -> V_104 . V_113 = 0 ;
#endif
if ( V_15 -> V_114 ) {
unsigned int V_107 = F_31 ( V_6 ) ;
struct V_1 * V_65 = NULL ;
int V_115 ;
V_115 = F_51 ( V_6 , V_15 -> V_114 , & V_65 ) ;
F_60 ( V_65 ) ;
if ( V_115 != V_76 &&
F_52 ( V_115 ) ) {
F_33 ( V_55 ) ;
F_53 ( V_55 , 1 ,
V_107 ) ;
}
goto V_108;
}
goto V_109;
}
if ( V_15 -> V_114 ) {
V_6 = V_15 -> V_114 -> V_116 -> V_117 ( V_15 -> V_114 ) ;
if ( V_6 )
goto V_109;
}
F_61 ( & V_15 -> V_118 , V_60 ) ;
}
if ( V_15 -> V_114 ) {
V_6 = V_15 -> V_114 -> V_116 -> V_117 ( V_15 -> V_114 ) ;
if ( V_6 )
goto V_109;
}
return NULL ;
}
static void F_62 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
F_63 ( V_55 ) ;
F_16 ( V_55 ) ;
if ( V_15 -> V_114 )
F_64 ( V_15 -> V_114 ) ;
F_65 ( & V_15 -> V_118 ) ;
}
static void F_66 ( struct V_38 * V_119 )
{
F_67 ( V_119 ) ;
}
static int F_68 ( struct V_54 * V_55 , const struct V_120 * V_121 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
T_6 V_122 = F_69 ( V_121 ) / sizeof( V_123 ) ;
const V_123 * V_7 = F_70 ( V_121 ) ;
T_7 * V_124 ;
struct V_38 * V_119 ;
int V_125 ;
T_6 V_126 ;
if ( V_122 > V_127 )
return - V_128 ;
V_126 = sizeof( struct V_38 ) + V_122 * sizeof( V_129 ) ;
V_119 = F_71 ( V_126 , V_130 | V_131 ) ;
if ( ! V_119 )
V_119 = F_72 ( V_126 ) ;
if ( ! V_119 )
return - V_132 ;
V_119 -> V_43 = V_122 ;
for ( V_125 = 0 ; V_125 < V_122 ; V_125 ++ )
V_119 -> V_42 [ V_125 ] = V_7 [ V_125 ] ;
V_124 = F_73 ( V_55 ) ;
F_74 ( V_124 ) ;
F_75 ( V_15 -> V_102 , V_119 ) ;
F_76 ( V_124 ) ;
F_66 ( V_119 ) ;
return 0 ;
}
static void F_77 ( struct V_14 * V_15 , const struct V_120 * V_121 )
{
const struct V_133 * V_134 = F_70 ( V_121 ) ;
F_5 ( & V_15 -> V_101 , V_134 -> V_135 ) ;
F_5 ( & V_15 -> V_33 , V_134 -> V_136 ) ;
F_5 ( & V_15 -> V_78 , V_134 -> V_137 ) ;
}
static void F_78 ( struct V_14 * V_15 , const struct V_120 * V_121 )
{
const struct V_138 * V_139 = F_70 ( V_121 ) ;
V_15 -> V_97 = V_139 -> V_140 ;
F_5 ( & V_15 -> V_98 , V_139 -> V_141 ) ;
}
static void F_79 ( struct V_14 * V_15 , const struct V_120 * V_121 )
{
const struct V_142 * V_139 = F_70 ( V_121 ) ;
V_15 -> V_87 = V_139 -> V_140 ;
F_5 ( & V_15 -> V_88 , V_139 -> V_141 ) ;
}
static void F_80 ( struct V_14 * V_15 , const struct V_120 * V_121 )
{
const struct V_143 * V_139 = F_70 ( V_121 ) ;
V_15 -> V_53 = V_139 -> V_53 ;
V_15 -> V_47 = V_139 -> V_47 ;
V_15 -> V_48 = V_139 -> V_48 ;
V_15 -> V_51 = V_139 -> V_51 ;
if ( V_15 -> V_48 )
V_15 -> V_50 = F_81 ( V_15 -> V_48 ) ;
else
V_15 -> V_50 = (struct F_81 ) { 0 } ;
}
static int F_82 ( struct V_14 * V_15 , const struct V_120 * V_121 )
{
const struct V_120 * V_144 ;
int V_145 ;
F_83 (la, attr, rem) {
T_8 type = F_84 ( V_144 ) ;
switch ( type ) {
case V_146 : {
const struct V_147 * V_148 = F_70 ( V_144 ) ;
if ( F_69 ( V_144 ) < sizeof( struct V_147 ) ) {
F_85 ( L_1 ) ;
return - V_128 ;
}
V_15 -> V_30 = V_34 ;
V_15 -> V_17 . V_9 = V_19 ;
V_15 -> V_17 . V_22 = V_148 -> V_149 ;
V_15 -> V_17 . V_27 = V_148 -> V_150 ;
V_15 -> V_17 . V_26 = V_148 -> V_151 ;
V_15 -> V_17 . V_20 = V_148 -> V_152 ;
V_15 -> V_17 . V_25 = V_148 -> V_153 ;
break;
}
case V_154 : {
const struct V_155 * V_156 = F_70 ( V_144 ) ;
if ( F_69 ( V_144 ) < sizeof( struct V_155 ) ) {
F_85 ( L_2 ) ;
return - V_128 ;
}
V_15 -> V_30 = V_35 ;
V_15 -> V_17 . V_9 = V_28 ;
V_15 -> V_17 . V_22 = V_156 -> V_56 ;
V_15 -> V_17 . V_27 = V_156 -> V_139 ;
V_15 -> V_17 . V_26 = V_156 -> V_157 ;
V_15 -> V_17 . V_20 = V_156 -> V_158 ;
break;
}
default:
F_85 ( L_3 , type ) ;
return - V_128 ;
}
}
return 0 ;
}
static int F_86 ( struct V_120 * V_159 [] , int V_160 , struct V_120 * V_161 ,
const struct V_162 * V_163 , int V_45 )
{
int V_164 = F_69 ( V_161 ) - F_87 ( V_45 ) ;
if ( V_164 < 0 ) {
F_85 ( L_4 , V_164 ) ;
return - V_128 ;
}
if ( V_164 >= F_88 ( 0 ) )
return F_89 ( V_159 , V_160 , F_70 ( V_161 ) + F_87 ( V_45 ) ,
V_164 , V_163 ) ;
memset ( V_159 , 0 , sizeof( struct V_120 * ) * ( V_160 + 1 ) ) ;
return 0 ;
}
static int F_90 ( struct V_54 * V_55 , struct V_120 * V_165 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_120 * V_159 [ V_166 + 1 ] ;
struct V_167 * V_168 ;
struct V_16 V_169 ;
int V_170 = V_31 ;
int V_171 ;
if ( V_165 == NULL )
return - V_128 ;
V_168 = F_70 ( V_165 ) ;
V_171 = F_86 ( V_159 , V_166 , V_165 , V_172 , sizeof( * V_168 ) ) ;
if ( V_171 < 0 )
return V_171 ;
V_169 = V_15 -> V_17 ;
V_170 = V_15 -> V_30 ;
if ( V_159 [ V_173 ] ) {
V_171 = F_82 ( V_15 , V_159 [ V_173 ] ) ;
if ( V_171 ) {
V_15 -> V_30 = V_170 ;
return V_171 ;
}
} else {
V_15 -> V_30 = V_31 ;
}
if ( V_159 [ V_174 ] ) {
V_171 = F_68 ( V_55 , V_159 [ V_174 ] ) ;
if ( V_171 ) {
V_15 -> V_17 = V_169 ;
V_15 -> V_30 = V_170 ;
return V_171 ;
}
}
V_55 -> V_94 = V_168 -> V_94 ;
V_15 -> V_81 = V_168 -> V_81 ;
V_15 -> V_82 = V_168 -> V_82 ;
V_15 -> V_94 = V_168 -> V_94 ;
V_15 -> V_95 = V_168 -> V_95 ;
V_15 -> V_96 = 0 ;
V_15 -> V_32 = V_168 -> V_32 ;
V_15 -> V_77 = V_168 -> V_77 ;
if ( V_15 -> V_95 )
V_15 -> V_97 = ~ 0 ;
if ( V_159 [ V_175 ] )
F_77 ( V_15 , V_159 [ V_175 ] ) ;
if ( V_159 [ V_176 ] )
F_78 ( V_15 , V_159 [ V_176 ] ) ;
if ( V_159 [ V_177 ] )
F_79 ( V_15 , V_159 [ V_177 ] ) ;
if ( V_159 [ V_178 ] )
F_80 ( V_15 , V_159 [ V_178 ] ) ;
if ( V_159 [ V_179 ] )
V_15 -> V_53 = F_49 ( T_2 , V_15 -> V_53 ,
F_91 ( V_159 [ V_179 ] ) ) ;
if ( V_159 [ V_180 ] )
V_15 -> V_79 = F_92 ( V_159 [ V_180 ] ) ;
return V_171 ;
}
static int F_93 ( struct V_54 * V_55 , struct V_120 * V_165 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
int V_171 ;
if ( ! V_165 )
return - V_128 ;
F_94 ( & V_15 -> V_118 , V_55 ) ;
V_15 -> V_30 = V_31 ;
V_171 = F_90 ( V_55 , V_165 ) ;
if ( V_171 )
F_85 ( L_5 ) ;
return V_171 ;
}
static void F_95 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
F_65 ( & V_15 -> V_118 ) ;
if ( V_15 -> V_114 )
F_96 ( V_15 -> V_114 ) ;
F_66 ( V_15 -> V_102 ) ;
}
static int F_97 ( const struct V_14 * V_15 ,
struct V_1 * V_6 )
{
struct V_120 * V_181 ;
V_181 = F_98 ( V_6 , V_173 ) ;
if ( V_181 == NULL )
goto V_182;
switch ( V_15 -> V_30 ) {
case V_31 :
F_99 ( V_6 , V_181 ) ;
return 0 ;
case V_34 : {
struct V_147 V_148 = {
. V_149 = V_15 -> V_17 . V_22 ,
. V_150 = V_15 -> V_17 . V_27 ,
. V_151 = V_15 -> V_17 . V_26 ,
. V_152 = V_15 -> V_17 . V_20 ,
. V_153 = V_15 -> V_17 . V_25 ,
} ;
if ( F_100 ( V_6 , V_146 , sizeof( V_148 ) , & V_148 ) )
goto V_182;
break;
}
case V_35 : {
struct V_155 V_156 = {
. V_56 = V_15 -> V_17 . V_22 ,
. V_139 = V_15 -> V_17 . V_27 ,
. V_157 = V_15 -> V_17 . V_26 ,
. V_158 = V_15 -> V_17 . V_20 ,
} ;
if ( F_100 ( V_6 , V_154 , sizeof( V_156 ) , & V_156 ) )
goto V_182;
break;
}
}
F_101 ( V_6 , V_181 ) ;
return 0 ;
V_182:
F_99 ( V_6 , V_181 ) ;
return - 1 ;
}
static int F_102 ( struct V_54 * V_55 , struct V_1 * V_6 )
{
const struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_120 * V_161 = (struct V_120 * ) F_103 ( V_6 ) ;
struct V_167 V_168 ;
struct V_133 V_183 ;
struct V_138 V_97 ;
struct V_142 V_87 ;
struct V_143 V_53 ;
V_168 . V_81 = V_15 -> V_81 ;
V_168 . V_82 = V_15 -> V_82 ;
V_168 . V_94 = V_15 -> V_94 ;
V_168 . V_32 = V_15 -> V_32 ;
V_168 . V_95 = V_15 -> V_95 ;
V_168 . V_77 = V_15 -> V_77 ;
if ( F_100 ( V_6 , V_184 , sizeof( V_168 ) , & V_168 ) )
goto V_182;
V_183 . V_135 = V_15 -> V_101 . V_10 ;
V_183 . V_136 = V_15 -> V_33 . V_10 ;
V_183 . V_137 = V_15 -> V_78 . V_10 ;
if ( F_100 ( V_6 , V_175 , sizeof( V_183 ) , & V_183 ) )
goto V_182;
V_97 . V_140 = V_15 -> V_97 ;
V_97 . V_141 = V_15 -> V_98 . V_10 ;
if ( F_100 ( V_6 , V_176 , sizeof( V_97 ) , & V_97 ) )
goto V_182;
V_87 . V_140 = V_15 -> V_87 ;
V_87 . V_141 = V_15 -> V_88 . V_10 ;
if ( F_100 ( V_6 , V_177 , sizeof( V_87 ) , & V_87 ) )
goto V_182;
if ( V_15 -> V_53 >= ( 1ULL << 32 ) ) {
if ( F_104 ( V_6 , V_179 , V_15 -> V_53 ,
V_185 ) )
goto V_182;
V_53 . V_53 = ~ 0U ;
} else {
V_53 . V_53 = V_15 -> V_53 ;
}
V_53 . V_47 = V_15 -> V_47 ;
V_53 . V_48 = V_15 -> V_48 ;
V_53 . V_51 = V_15 -> V_51 ;
if ( F_100 ( V_6 , V_178 , sizeof( V_53 ) , & V_53 ) )
goto V_182;
if ( V_15 -> V_79 && F_105 ( V_6 , V_180 , V_15 -> V_79 ) )
goto V_182;
if ( F_97 ( V_15 , V_6 ) != 0 )
goto V_182;
return F_101 ( V_6 , V_161 ) ;
V_182:
F_106 ( V_6 , V_161 ) ;
return - 1 ;
}
static int F_107 ( struct V_54 * V_55 , unsigned long V_186 ,
struct V_1 * V_6 , struct V_187 * V_188 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
if ( V_186 != 1 || ! V_15 -> V_114 )
return - V_189 ;
V_188 -> V_190 |= F_108 ( 1 ) ;
V_188 -> V_191 = V_15 -> V_114 -> V_192 ;
return 0 ;
}
static int F_109 ( struct V_54 * V_55 , unsigned long V_193 , struct V_54 * V_194 ,
struct V_54 * * V_195 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
* V_195 = F_110 ( V_55 , V_194 , & V_15 -> V_114 ) ;
return 0 ;
}
static struct V_54 * F_111 ( struct V_54 * V_55 , unsigned long V_193 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
return V_15 -> V_114 ;
}
static unsigned long F_112 ( struct V_54 * V_55 , T_1 V_196 )
{
return 1 ;
}
static void F_113 ( struct V_54 * V_55 , unsigned long V_193 )
{
}
static void F_114 ( struct V_54 * V_55 , struct V_197 * V_198 )
{
if ( ! V_198 -> V_199 ) {
if ( V_198 -> V_74 >= V_198 -> V_200 )
if ( V_198 -> V_201 ( V_55 , 1 , V_198 ) < 0 ) {
V_198 -> V_199 = 1 ;
return;
}
V_198 -> V_74 ++ ;
}
}
static int T_9 F_115 ( void )
{
F_85 ( L_6 V_202 L_7 ) ;
return F_116 ( & V_203 ) ;
}
static void T_10 F_117 ( void )
{
F_118 ( & V_203 ) ;
}
