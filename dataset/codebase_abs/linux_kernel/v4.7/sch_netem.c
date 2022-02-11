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
static struct V_1 * F_24 ( struct V_1 * V_6 , struct V_54 * V_55 )
{
struct V_1 * V_67 ;
T_5 V_68 = F_25 ( V_6 ) ;
V_67 = F_26 ( V_6 , V_68 & ~ V_69 ) ;
if ( F_27 ( V_67 ) ) {
F_28 ( V_6 , V_55 ) ;
return NULL ;
}
F_29 ( V_6 ) ;
return V_67 ;
}
static int F_30 ( struct V_1 * V_6 , struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_5 * V_70 ;
struct V_1 * V_71 ;
struct V_1 * V_67 = NULL ;
unsigned int V_45 = 0 , V_72 , V_73 = F_31 ( V_6 ) ;
int V_74 = 0 ;
int V_75 = 1 ;
int V_76 = V_77 ;
if ( V_15 -> V_78 && V_15 -> V_78 >= F_7 ( & V_15 -> V_79 ) )
++ V_75 ;
if ( F_10 ( V_15 ) ) {
if ( V_15 -> V_80 && F_32 ( V_6 ) )
F_33 ( V_55 ) ;
else
-- V_75 ;
}
if ( V_75 == 0 ) {
F_33 ( V_55 ) ;
F_20 ( V_6 ) ;
return V_77 | V_81 ;
}
if ( V_15 -> V_82 || V_15 -> V_83 )
F_34 ( V_6 ) ;
if ( V_75 > 1 && ( V_71 = F_35 ( V_6 , V_84 ) ) != NULL ) {
struct V_54 * V_85 = F_36 ( V_55 ) ;
T_1 V_86 = V_15 -> V_78 ;
V_15 -> V_78 = 0 ;
V_85 -> V_87 ( V_71 , V_85 ) ;
V_15 -> V_78 = V_86 ;
}
if ( V_15 -> V_88 && V_15 -> V_88 >= F_7 ( & V_15 -> V_89 ) ) {
if ( F_37 ( V_6 ) ) {
V_67 = F_24 ( V_6 , V_55 ) ;
if ( ! V_67 )
return V_90 ;
} else {
V_67 = V_6 ;
}
V_6 = V_67 ;
V_67 = V_67 -> V_58 ;
if ( ! ( V_6 = F_38 ( V_6 , V_84 ) ) ||
( V_6 -> V_91 == V_92 &&
F_39 ( V_6 ) ) ) {
V_76 = F_40 ( V_6 , V_55 ) ;
goto V_93;
}
V_6 -> V_7 [ F_6 () % F_41 ( V_6 ) ] ^=
1 << ( F_6 () % 8 ) ;
}
if ( F_42 ( F_43 ( & V_55 -> V_15 ) >= V_55 -> V_94 ) )
return F_28 ( V_6 , V_55 ) ;
F_44 ( V_55 , V_6 ) ;
V_70 = V_5 ( V_6 ) ;
if ( V_15 -> V_95 == 0 ||
V_15 -> V_96 < V_15 -> V_95 - 1 ||
V_15 -> V_97 < F_7 ( & V_15 -> V_98 ) ) {
T_4 V_99 ;
T_3 V_100 ;
V_100 = F_11 ( V_15 -> V_82 , V_15 -> V_83 ,
& V_15 -> V_101 , V_15 -> V_102 ) ;
V_99 = F_45 () ;
if ( V_15 -> V_53 ) {
struct V_1 * V_11 ;
if ( ! F_46 ( & V_55 -> V_15 ) )
V_11 = F_47 ( & V_55 -> V_15 ) ;
else
V_11 = F_1 ( F_48 ( & V_15 -> V_57 ) ) ;
if ( V_11 ) {
V_100 -= V_5 ( V_11 ) -> V_62 - V_99 ;
V_100 = F_49 ( T_3 , 0 , V_100 ) ;
V_99 = V_5 ( V_11 ) -> V_62 ;
}
V_100 += F_12 ( F_31 ( V_6 ) , V_15 ) ;
}
V_70 -> V_62 = V_99 + V_100 ;
V_70 -> V_103 = V_6 -> V_104 ;
++ V_15 -> V_96 ;
F_21 ( V_6 , V_55 ) ;
} else {
V_70 -> V_62 = F_45 () ;
V_15 -> V_96 = 0 ;
F_50 ( & V_55 -> V_15 , V_6 ) ;
V_55 -> V_105 . V_106 ++ ;
}
V_93:
if ( V_67 ) {
while ( V_67 ) {
V_71 = V_67 -> V_58 ;
V_67 -> V_58 = NULL ;
F_4 ( V_67 ) -> V_107 = V_67 -> V_45 ;
V_72 = V_67 -> V_45 ;
V_76 = F_51 ( V_67 , V_55 ) ;
if ( V_76 != V_77 ) {
if ( F_52 ( V_76 ) )
F_33 ( V_55 ) ;
} else {
V_74 ++ ;
V_45 += V_72 ;
}
V_67 = V_71 ;
}
V_55 -> V_15 . V_66 += V_74 ;
if ( V_74 > 1 )
F_53 ( V_55 , 1 - V_74 , V_73 - V_45 ) ;
}
return V_77 ;
}
static unsigned int F_54 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
unsigned int V_45 ;
V_45 = F_55 ( V_55 ) ;
if ( ! V_45 ) {
struct V_2 * V_56 = F_18 ( & V_15 -> V_57 ) ;
if ( V_56 ) {
struct V_1 * V_6 = F_1 ( V_56 ) ;
F_19 ( V_56 , & V_15 -> V_57 ) ;
V_55 -> V_15 . V_66 -- ;
V_6 -> V_58 = NULL ;
V_6 -> V_59 = NULL ;
F_56 ( V_55 , V_6 ) ;
F_20 ( V_6 ) ;
}
}
if ( ! V_45 && V_15 -> V_108 && V_15 -> V_108 -> V_109 -> V_110 )
V_45 = V_15 -> V_108 -> V_109 -> V_110 ( V_15 -> V_108 ) ;
if ( V_45 )
F_33 ( V_55 ) ;
return V_45 ;
}
static struct V_1 * F_57 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_1 * V_6 ;
struct V_2 * V_56 ;
if ( F_58 ( V_55 ) )
return NULL ;
V_111:
V_6 = F_59 ( & V_55 -> V_15 ) ;
if ( V_6 ) {
F_56 ( V_55 , V_6 ) ;
V_112:
F_60 ( V_55 ) ;
F_61 ( V_55 , V_6 ) ;
return V_6 ;
}
V_56 = F_18 ( & V_15 -> V_57 ) ;
if ( V_56 ) {
T_4 V_62 ;
V_6 = F_1 ( V_56 ) ;
V_62 = V_5 ( V_6 ) -> V_62 ;
if ( V_62 <= F_45 () ) {
F_19 ( V_56 , & V_15 -> V_57 ) ;
V_55 -> V_15 . V_66 -- ;
F_56 ( V_55 , V_6 ) ;
V_6 -> V_58 = NULL ;
V_6 -> V_59 = NULL ;
V_6 -> V_104 = V_5 ( V_6 ) -> V_103 ;
#ifdef F_62
if ( F_63 ( V_6 -> V_113 ) & V_114 )
V_6 -> V_104 . V_115 = 0 ;
#endif
if ( V_15 -> V_108 ) {
unsigned int V_107 = F_31 ( V_6 ) ;
int V_116 = F_51 ( V_6 , V_15 -> V_108 ) ;
if ( V_116 != V_77 &&
F_52 ( V_116 ) ) {
F_33 ( V_55 ) ;
F_53 ( V_55 , 1 ,
V_107 ) ;
}
goto V_111;
}
goto V_112;
}
if ( V_15 -> V_108 ) {
V_6 = V_15 -> V_108 -> V_109 -> V_117 ( V_15 -> V_108 ) ;
if ( V_6 )
goto V_112;
}
F_64 ( & V_15 -> V_118 , V_62 ) ;
}
if ( V_15 -> V_108 ) {
V_6 = V_15 -> V_108 -> V_109 -> V_117 ( V_15 -> V_108 ) ;
if ( V_6 )
goto V_112;
}
return NULL ;
}
static void F_65 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
F_66 ( V_55 ) ;
F_16 ( V_55 ) ;
if ( V_15 -> V_108 )
F_67 ( V_15 -> V_108 ) ;
F_68 ( & V_15 -> V_118 ) ;
}
static void F_69 ( struct V_38 * V_119 )
{
F_70 ( V_119 ) ;
}
static int F_71 ( struct V_54 * V_55 , const struct V_120 * V_121 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
T_6 V_122 = F_72 ( V_121 ) / sizeof( V_123 ) ;
const V_123 * V_7 = F_73 ( V_121 ) ;
T_7 * V_124 ;
struct V_38 * V_119 ;
int V_125 ;
T_6 V_126 ;
if ( V_122 > V_127 )
return - V_128 ;
V_126 = sizeof( struct V_38 ) + V_122 * sizeof( V_129 ) ;
V_119 = F_74 ( V_126 , V_130 | V_131 ) ;
if ( ! V_119 )
V_119 = F_75 ( V_126 ) ;
if ( ! V_119 )
return - V_132 ;
V_119 -> V_43 = V_122 ;
for ( V_125 = 0 ; V_125 < V_122 ; V_125 ++ )
V_119 -> V_42 [ V_125 ] = V_7 [ V_125 ] ;
V_124 = F_76 ( V_55 ) ;
F_77 ( V_124 ) ;
F_78 ( V_15 -> V_102 , V_119 ) ;
F_79 ( V_124 ) ;
F_69 ( V_119 ) ;
return 0 ;
}
static void F_80 ( struct V_14 * V_15 , const struct V_120 * V_121 )
{
const struct V_133 * V_134 = F_73 ( V_121 ) ;
F_5 ( & V_15 -> V_101 , V_134 -> V_135 ) ;
F_5 ( & V_15 -> V_33 , V_134 -> V_136 ) ;
F_5 ( & V_15 -> V_79 , V_134 -> V_137 ) ;
}
static void F_81 ( struct V_14 * V_15 , const struct V_120 * V_121 )
{
const struct V_138 * V_139 = F_73 ( V_121 ) ;
V_15 -> V_97 = V_139 -> V_140 ;
F_5 ( & V_15 -> V_98 , V_139 -> V_141 ) ;
}
static void F_82 ( struct V_14 * V_15 , const struct V_120 * V_121 )
{
const struct V_142 * V_139 = F_73 ( V_121 ) ;
V_15 -> V_88 = V_139 -> V_140 ;
F_5 ( & V_15 -> V_89 , V_139 -> V_141 ) ;
}
static void F_83 ( struct V_14 * V_15 , const struct V_120 * V_121 )
{
const struct V_143 * V_139 = F_73 ( V_121 ) ;
V_15 -> V_53 = V_139 -> V_53 ;
V_15 -> V_47 = V_139 -> V_47 ;
V_15 -> V_48 = V_139 -> V_48 ;
V_15 -> V_51 = V_139 -> V_51 ;
if ( V_15 -> V_48 )
V_15 -> V_50 = F_84 ( V_15 -> V_48 ) ;
else
V_15 -> V_50 = (struct F_84 ) { 0 } ;
}
static int F_85 ( struct V_14 * V_15 , const struct V_120 * V_121 )
{
const struct V_120 * V_144 ;
int V_145 ;
F_86 (la, attr, rem) {
T_8 type = F_87 ( V_144 ) ;
switch ( type ) {
case V_146 : {
const struct V_147 * V_148 = F_73 ( V_144 ) ;
if ( F_72 ( V_144 ) < sizeof( struct V_147 ) ) {
F_88 ( L_1 ) ;
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
const struct V_155 * V_156 = F_73 ( V_144 ) ;
if ( F_72 ( V_144 ) < sizeof( struct V_155 ) ) {
F_88 ( L_2 ) ;
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
F_88 ( L_3 , type ) ;
return - V_128 ;
}
}
return 0 ;
}
static int F_89 ( struct V_120 * V_159 [] , int V_160 , struct V_120 * V_161 ,
const struct V_162 * V_163 , int V_45 )
{
int V_164 = F_72 ( V_161 ) - F_90 ( V_45 ) ;
if ( V_164 < 0 ) {
F_88 ( L_4 , V_164 ) ;
return - V_128 ;
}
if ( V_164 >= F_91 ( 0 ) )
return F_92 ( V_159 , V_160 , F_73 ( V_161 ) + F_90 ( V_45 ) ,
V_164 , V_163 ) ;
memset ( V_159 , 0 , sizeof( struct V_120 * ) * ( V_160 + 1 ) ) ;
return 0 ;
}
static int F_93 ( struct V_54 * V_55 , struct V_120 * V_165 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_120 * V_159 [ V_166 + 1 ] ;
struct V_167 * V_168 ;
struct V_16 V_169 ;
int V_170 = V_31 ;
int V_171 ;
if ( V_165 == NULL )
return - V_128 ;
V_168 = F_73 ( V_165 ) ;
V_171 = F_89 ( V_159 , V_166 , V_165 , V_172 , sizeof( * V_168 ) ) ;
if ( V_171 < 0 )
return V_171 ;
V_169 = V_15 -> V_17 ;
V_170 = V_15 -> V_30 ;
if ( V_159 [ V_173 ] ) {
V_171 = F_85 ( V_15 , V_159 [ V_173 ] ) ;
if ( V_171 ) {
V_15 -> V_30 = V_170 ;
return V_171 ;
}
} else {
V_15 -> V_30 = V_31 ;
}
if ( V_159 [ V_174 ] ) {
V_171 = F_71 ( V_55 , V_159 [ V_174 ] ) ;
if ( V_171 ) {
V_15 -> V_17 = V_169 ;
V_15 -> V_30 = V_170 ;
return V_171 ;
}
}
V_55 -> V_94 = V_168 -> V_94 ;
V_15 -> V_82 = V_168 -> V_82 ;
V_15 -> V_83 = V_168 -> V_83 ;
V_15 -> V_94 = V_168 -> V_94 ;
V_15 -> V_95 = V_168 -> V_95 ;
V_15 -> V_96 = 0 ;
V_15 -> V_32 = V_168 -> V_32 ;
V_15 -> V_78 = V_168 -> V_78 ;
if ( V_15 -> V_95 )
V_15 -> V_97 = ~ 0 ;
if ( V_159 [ V_175 ] )
F_80 ( V_15 , V_159 [ V_175 ] ) ;
if ( V_159 [ V_176 ] )
F_81 ( V_15 , V_159 [ V_176 ] ) ;
if ( V_159 [ V_177 ] )
F_82 ( V_15 , V_159 [ V_177 ] ) ;
if ( V_159 [ V_178 ] )
F_83 ( V_15 , V_159 [ V_178 ] ) ;
if ( V_159 [ V_179 ] )
V_15 -> V_53 = F_49 ( T_2 , V_15 -> V_53 ,
F_94 ( V_159 [ V_179 ] ) ) ;
if ( V_159 [ V_180 ] )
V_15 -> V_80 = F_95 ( V_159 [ V_180 ] ) ;
return V_171 ;
}
static int F_96 ( struct V_54 * V_55 , struct V_120 * V_165 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
int V_171 ;
if ( ! V_165 )
return - V_128 ;
F_97 ( & V_15 -> V_118 , V_55 ) ;
V_15 -> V_30 = V_31 ;
V_171 = F_93 ( V_55 , V_165 ) ;
if ( V_171 )
F_88 ( L_5 ) ;
return V_171 ;
}
static void F_98 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
F_68 ( & V_15 -> V_118 ) ;
if ( V_15 -> V_108 )
F_99 ( V_15 -> V_108 ) ;
F_69 ( V_15 -> V_102 ) ;
}
static int F_100 ( const struct V_14 * V_15 ,
struct V_1 * V_6 )
{
struct V_120 * V_181 ;
V_181 = F_101 ( V_6 , V_173 ) ;
if ( V_181 == NULL )
goto V_182;
switch ( V_15 -> V_30 ) {
case V_31 :
F_102 ( V_6 , V_181 ) ;
return 0 ;
case V_34 : {
struct V_147 V_148 = {
. V_149 = V_15 -> V_17 . V_22 ,
. V_150 = V_15 -> V_17 . V_27 ,
. V_151 = V_15 -> V_17 . V_26 ,
. V_152 = V_15 -> V_17 . V_20 ,
. V_153 = V_15 -> V_17 . V_25 ,
} ;
if ( F_103 ( V_6 , V_146 , sizeof( V_148 ) , & V_148 ) )
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
if ( F_103 ( V_6 , V_154 , sizeof( V_156 ) , & V_156 ) )
goto V_182;
break;
}
}
F_104 ( V_6 , V_181 ) ;
return 0 ;
V_182:
F_102 ( V_6 , V_181 ) ;
return - 1 ;
}
static int F_105 ( struct V_54 * V_55 , struct V_1 * V_6 )
{
const struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_120 * V_161 = (struct V_120 * ) F_106 ( V_6 ) ;
struct V_167 V_168 ;
struct V_133 V_183 ;
struct V_138 V_97 ;
struct V_142 V_88 ;
struct V_143 V_53 ;
V_168 . V_82 = V_15 -> V_82 ;
V_168 . V_83 = V_15 -> V_83 ;
V_168 . V_94 = V_15 -> V_94 ;
V_168 . V_32 = V_15 -> V_32 ;
V_168 . V_95 = V_15 -> V_95 ;
V_168 . V_78 = V_15 -> V_78 ;
if ( F_103 ( V_6 , V_184 , sizeof( V_168 ) , & V_168 ) )
goto V_182;
V_183 . V_135 = V_15 -> V_101 . V_10 ;
V_183 . V_136 = V_15 -> V_33 . V_10 ;
V_183 . V_137 = V_15 -> V_79 . V_10 ;
if ( F_103 ( V_6 , V_175 , sizeof( V_183 ) , & V_183 ) )
goto V_182;
V_97 . V_140 = V_15 -> V_97 ;
V_97 . V_141 = V_15 -> V_98 . V_10 ;
if ( F_103 ( V_6 , V_176 , sizeof( V_97 ) , & V_97 ) )
goto V_182;
V_88 . V_140 = V_15 -> V_88 ;
V_88 . V_141 = V_15 -> V_89 . V_10 ;
if ( F_103 ( V_6 , V_177 , sizeof( V_88 ) , & V_88 ) )
goto V_182;
if ( V_15 -> V_53 >= ( 1ULL << 32 ) ) {
if ( F_107 ( V_6 , V_179 , V_15 -> V_53 ,
V_185 ) )
goto V_182;
V_53 . V_53 = ~ 0U ;
} else {
V_53 . V_53 = V_15 -> V_53 ;
}
V_53 . V_47 = V_15 -> V_47 ;
V_53 . V_48 = V_15 -> V_48 ;
V_53 . V_51 = V_15 -> V_51 ;
if ( F_103 ( V_6 , V_178 , sizeof( V_53 ) , & V_53 ) )
goto V_182;
if ( V_15 -> V_80 && F_108 ( V_6 , V_180 , V_15 -> V_80 ) )
goto V_182;
if ( F_100 ( V_15 , V_6 ) != 0 )
goto V_182;
return F_104 ( V_6 , V_161 ) ;
V_182:
F_109 ( V_6 , V_161 ) ;
return - 1 ;
}
static int F_110 ( struct V_54 * V_55 , unsigned long V_186 ,
struct V_1 * V_6 , struct V_187 * V_188 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
if ( V_186 != 1 || ! V_15 -> V_108 )
return - V_189 ;
V_188 -> V_190 |= F_111 ( 1 ) ;
V_188 -> V_191 = V_15 -> V_108 -> V_192 ;
return 0 ;
}
static int F_112 ( struct V_54 * V_55 , unsigned long V_193 , struct V_54 * V_194 ,
struct V_54 * * V_195 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
* V_195 = F_113 ( V_55 , V_194 , & V_15 -> V_108 ) ;
return 0 ;
}
static struct V_54 * F_114 ( struct V_54 * V_55 , unsigned long V_193 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
return V_15 -> V_108 ;
}
static unsigned long F_115 ( struct V_54 * V_55 , T_1 V_196 )
{
return 1 ;
}
static void F_116 ( struct V_54 * V_55 , unsigned long V_193 )
{
}
static void F_117 ( struct V_54 * V_55 , struct V_197 * V_198 )
{
if ( ! V_198 -> V_199 ) {
if ( V_198 -> V_75 >= V_198 -> V_200 )
if ( V_198 -> V_201 ( V_55 , 1 , V_198 ) < 0 ) {
V_198 -> V_199 = 1 ;
return;
}
V_198 -> V_75 ++ ;
}
}
static int T_9 F_118 ( void )
{
F_88 ( L_6 V_202 L_7 ) ;
return F_119 ( & V_203 ) ;
}
static void T_10 F_120 ( void )
{
F_121 ( & V_203 ) ;
}
