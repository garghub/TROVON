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
static void F_30 ( struct V_69 * V_70 , struct V_1 * V_6 )
{
V_6 -> V_71 = V_70 -> V_72 ;
if ( ! V_70 -> V_72 )
V_70 -> V_73 = V_6 ;
V_70 -> V_72 = V_6 ;
V_70 -> V_64 ++ ;
}
static int F_31 ( struct V_1 * V_6 , struct V_54 * V_55 ,
struct V_1 * * V_65 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_5 * V_74 ;
struct V_1 * V_75 ;
struct V_1 * V_66 = NULL ;
unsigned int V_45 = 0 , V_76 , V_77 = F_32 ( V_6 ) ;
int V_78 = 0 ;
int V_79 = 1 ;
int V_80 = V_81 ;
if ( V_15 -> V_82 && V_15 -> V_82 >= F_7 ( & V_15 -> V_83 ) )
++ V_79 ;
if ( F_10 ( V_15 ) ) {
if ( V_15 -> V_84 && F_33 ( V_6 ) )
F_34 ( V_55 ) ;
else
-- V_79 ;
}
if ( V_79 == 0 ) {
F_34 ( V_55 ) ;
F_35 ( V_6 , V_65 ) ;
return V_81 | V_85 ;
}
if ( V_15 -> V_86 || V_15 -> V_87 || V_15 -> V_53 )
F_36 ( V_6 ) ;
if ( V_79 > 1 && ( V_75 = F_37 ( V_6 , V_88 ) ) != NULL ) {
struct V_54 * V_89 = F_38 ( V_55 ) ;
T_1 V_90 = V_15 -> V_82 ;
V_15 -> V_82 = 0 ;
V_89 -> V_91 ( V_75 , V_89 , V_65 ) ;
V_15 -> V_82 = V_90 ;
}
if ( V_15 -> V_92 && V_15 -> V_92 >= F_7 ( & V_15 -> V_93 ) ) {
if ( F_39 ( V_6 ) ) {
V_66 = F_24 ( V_6 , V_55 , V_65 ) ;
if ( ! V_66 )
return V_94 ;
} else {
V_66 = V_6 ;
}
V_6 = V_66 ;
V_66 = V_66 -> V_71 ;
V_6 = F_40 ( V_6 , V_88 ) ;
if ( F_41 ( ! V_6 ) ) {
F_34 ( V_55 ) ;
goto V_95;
}
if ( V_6 -> V_96 == V_97 &&
F_42 ( V_6 ) ) {
F_28 ( V_6 , V_55 , V_65 ) ;
goto V_95;
}
V_6 -> V_7 [ F_6 () % F_43 ( V_6 ) ] ^=
1 << ( F_6 () % 8 ) ;
}
if ( F_41 ( V_55 -> V_15 . V_64 >= V_55 -> V_98 ) )
return F_28 ( V_6 , V_55 , V_65 ) ;
F_44 ( V_55 , V_6 ) ;
V_74 = V_5 ( V_6 ) ;
if ( V_15 -> V_99 == 0 ||
V_15 -> V_100 < V_15 -> V_99 - 1 ||
V_15 -> V_101 < F_7 ( & V_15 -> V_102 ) ) {
T_4 V_103 ;
T_3 V_104 ;
V_104 = F_11 ( V_15 -> V_86 , V_15 -> V_87 ,
& V_15 -> V_105 , V_15 -> V_106 ) ;
V_103 = F_45 () ;
if ( V_15 -> V_53 ) {
struct V_5 * V_11 = NULL ;
if ( V_55 -> V_15 . V_73 )
V_11 = V_5 ( V_55 -> V_15 . V_73 ) ;
if ( V_15 -> V_57 . V_2 ) {
struct V_1 * V_107 ;
struct V_5 * V_108 ;
V_107 = F_1 ( F_46 ( & V_15 -> V_57 ) ) ;
V_108 = V_5 ( V_107 ) ;
if ( ! V_11 ||
V_108 -> V_60 > V_11 -> V_60 ) {
V_11 = V_108 ;
}
}
if ( V_11 ) {
V_104 -= V_11 -> V_60 - V_103 ;
V_104 = F_47 ( T_3 , 0 , V_104 ) ;
V_103 = V_11 -> V_60 ;
}
V_104 += F_12 ( F_32 ( V_6 ) , V_15 ) ;
}
V_74 -> V_60 = V_103 + V_104 ;
V_74 -> V_109 = V_6 -> V_110 ;
++ V_15 -> V_100 ;
F_21 ( V_6 , V_55 ) ;
} else {
V_74 -> V_60 = F_45 () ;
V_15 -> V_100 = 0 ;
F_30 ( & V_55 -> V_15 , V_6 ) ;
V_55 -> V_111 . V_112 ++ ;
}
V_95:
if ( V_66 ) {
while ( V_66 ) {
V_75 = V_66 -> V_71 ;
V_66 -> V_71 = NULL ;
F_4 ( V_66 ) -> V_113 = V_66 -> V_45 ;
V_76 = V_66 -> V_45 ;
V_80 = F_48 ( V_66 , V_55 , V_65 ) ;
if ( V_80 != V_81 ) {
if ( F_49 ( V_80 ) )
F_34 ( V_55 ) ;
} else {
V_78 ++ ;
V_45 += V_76 ;
}
V_66 = V_75 ;
}
V_55 -> V_15 . V_64 += V_78 ;
if ( V_78 > 1 )
F_50 ( V_55 , 1 - V_78 , V_77 - V_45 ) ;
}
return V_81 ;
}
static struct V_1 * F_51 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_1 * V_6 ;
struct V_2 * V_56 ;
V_114:
V_6 = F_52 ( & V_55 -> V_15 ) ;
if ( V_6 ) {
F_53 ( V_55 , V_6 ) ;
V_115:
F_54 ( V_55 , V_6 ) ;
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
F_53 ( V_55 , V_6 ) ;
V_6 -> V_71 = NULL ;
V_6 -> V_116 = NULL ;
V_6 -> V_110 = V_5 ( V_6 ) -> V_109 ;
#ifdef F_55
if ( V_6 -> V_117 && V_6 -> V_118 )
V_6 -> V_110 = 0 ;
#endif
if ( V_15 -> V_119 ) {
unsigned int V_113 = F_32 ( V_6 ) ;
struct V_1 * V_65 = NULL ;
int V_120 ;
V_120 = F_48 ( V_6 , V_15 -> V_119 , & V_65 ) ;
F_56 ( V_65 ) ;
if ( V_120 != V_81 &&
F_49 ( V_120 ) ) {
F_34 ( V_55 ) ;
F_50 ( V_55 , 1 ,
V_113 ) ;
}
goto V_114;
}
goto V_115;
}
if ( V_15 -> V_119 ) {
V_6 = V_15 -> V_119 -> V_121 -> V_122 ( V_15 -> V_119 ) ;
if ( V_6 )
goto V_115;
}
F_57 ( & V_15 -> V_123 , V_60 ) ;
}
if ( V_15 -> V_119 ) {
V_6 = V_15 -> V_119 -> V_121 -> V_122 ( V_15 -> V_119 ) ;
if ( V_6 )
goto V_115;
}
return NULL ;
}
static void F_58 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
F_59 ( V_55 ) ;
F_16 ( V_55 ) ;
if ( V_15 -> V_119 )
F_60 ( V_15 -> V_119 ) ;
F_61 ( & V_15 -> V_123 ) ;
}
static void F_62 ( struct V_38 * V_124 )
{
F_63 ( V_124 ) ;
}
static int F_64 ( struct V_54 * V_55 , const struct V_125 * V_126 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
T_6 V_127 = F_65 ( V_126 ) / sizeof( V_128 ) ;
const V_128 * V_7 = F_66 ( V_126 ) ;
T_7 * V_129 ;
struct V_38 * V_124 ;
int V_130 ;
if ( V_127 > V_131 )
return - V_132 ;
V_124 = F_67 ( sizeof( struct V_38 ) + V_127 * sizeof( V_133 ) , V_134 ) ;
if ( ! V_124 )
return - V_135 ;
V_124 -> V_43 = V_127 ;
for ( V_130 = 0 ; V_130 < V_127 ; V_130 ++ )
V_124 -> V_42 [ V_130 ] = V_7 [ V_130 ] ;
V_129 = F_68 ( V_55 ) ;
F_69 ( V_129 ) ;
F_70 ( V_15 -> V_106 , V_124 ) ;
F_71 ( V_129 ) ;
F_62 ( V_124 ) ;
return 0 ;
}
static void F_72 ( struct V_14 * V_15 , const struct V_125 * V_126 )
{
const struct V_136 * V_137 = F_66 ( V_126 ) ;
F_5 ( & V_15 -> V_105 , V_137 -> V_138 ) ;
F_5 ( & V_15 -> V_33 , V_137 -> V_139 ) ;
F_5 ( & V_15 -> V_83 , V_137 -> V_140 ) ;
}
static void F_73 ( struct V_14 * V_15 , const struct V_125 * V_126 )
{
const struct V_141 * V_142 = F_66 ( V_126 ) ;
V_15 -> V_101 = V_142 -> V_143 ;
F_5 ( & V_15 -> V_102 , V_142 -> V_144 ) ;
}
static void F_74 ( struct V_14 * V_15 , const struct V_125 * V_126 )
{
const struct V_145 * V_142 = F_66 ( V_126 ) ;
V_15 -> V_92 = V_142 -> V_143 ;
F_5 ( & V_15 -> V_93 , V_142 -> V_144 ) ;
}
static void F_75 ( struct V_14 * V_15 , const struct V_125 * V_126 )
{
const struct V_146 * V_142 = F_66 ( V_126 ) ;
V_15 -> V_53 = V_142 -> V_53 ;
V_15 -> V_47 = V_142 -> V_47 ;
V_15 -> V_48 = V_142 -> V_48 ;
V_15 -> V_51 = V_142 -> V_51 ;
if ( V_15 -> V_48 )
V_15 -> V_50 = F_76 ( V_15 -> V_48 ) ;
else
V_15 -> V_50 = (struct F_76 ) { 0 } ;
}
static int F_77 ( struct V_14 * V_15 , const struct V_125 * V_126 )
{
const struct V_125 * V_147 ;
int V_148 ;
F_78 (la, attr, rem) {
T_8 type = F_79 ( V_147 ) ;
switch ( type ) {
case V_149 : {
const struct V_150 * V_151 = F_66 ( V_147 ) ;
if ( F_65 ( V_147 ) < sizeof( struct V_150 ) ) {
F_80 ( L_1 ) ;
return - V_132 ;
}
V_15 -> V_30 = V_34 ;
V_15 -> V_17 . V_9 = V_19 ;
V_15 -> V_17 . V_22 = V_151 -> V_152 ;
V_15 -> V_17 . V_27 = V_151 -> V_153 ;
V_15 -> V_17 . V_26 = V_151 -> V_154 ;
V_15 -> V_17 . V_20 = V_151 -> V_155 ;
V_15 -> V_17 . V_25 = V_151 -> V_156 ;
break;
}
case V_157 : {
const struct V_158 * V_159 = F_66 ( V_147 ) ;
if ( F_65 ( V_147 ) < sizeof( struct V_158 ) ) {
F_80 ( L_2 ) ;
return - V_132 ;
}
V_15 -> V_30 = V_35 ;
V_15 -> V_17 . V_9 = V_28 ;
V_15 -> V_17 . V_22 = V_159 -> V_56 ;
V_15 -> V_17 . V_27 = V_159 -> V_142 ;
V_15 -> V_17 . V_26 = V_159 -> V_160 ;
V_15 -> V_17 . V_20 = V_159 -> V_161 ;
break;
}
default:
F_80 ( L_3 , type ) ;
return - V_132 ;
}
}
return 0 ;
}
static int F_81 ( struct V_125 * V_162 [] , int V_163 , struct V_125 * V_164 ,
const struct V_165 * V_166 , int V_45 )
{
int V_167 = F_65 ( V_164 ) - F_82 ( V_45 ) ;
if ( V_167 < 0 ) {
F_80 ( L_4 , V_167 ) ;
return - V_132 ;
}
if ( V_167 >= F_83 ( 0 ) )
return F_84 ( V_162 , V_163 , F_66 ( V_164 ) + F_82 ( V_45 ) ,
V_167 , V_166 , NULL ) ;
memset ( V_162 , 0 , sizeof( struct V_125 * ) * ( V_163 + 1 ) ) ;
return 0 ;
}
static int F_85 ( struct V_54 * V_55 , struct V_125 * V_168 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_125 * V_162 [ V_169 + 1 ] ;
struct V_170 * V_171 ;
struct V_16 V_172 ;
int V_173 = V_31 ;
int V_174 ;
if ( V_168 == NULL )
return - V_132 ;
V_171 = F_66 ( V_168 ) ;
V_174 = F_81 ( V_162 , V_169 , V_168 , V_175 , sizeof( * V_171 ) ) ;
if ( V_174 < 0 )
return V_174 ;
V_172 = V_15 -> V_17 ;
V_173 = V_15 -> V_30 ;
if ( V_162 [ V_176 ] ) {
V_174 = F_77 ( V_15 , V_162 [ V_176 ] ) ;
if ( V_174 ) {
V_15 -> V_30 = V_173 ;
return V_174 ;
}
} else {
V_15 -> V_30 = V_31 ;
}
if ( V_162 [ V_177 ] ) {
V_174 = F_64 ( V_55 , V_162 [ V_177 ] ) ;
if ( V_174 ) {
V_15 -> V_17 = V_172 ;
V_15 -> V_30 = V_173 ;
return V_174 ;
}
}
V_55 -> V_98 = V_171 -> V_98 ;
V_15 -> V_86 = V_171 -> V_86 ;
V_15 -> V_87 = V_171 -> V_87 ;
V_15 -> V_98 = V_171 -> V_98 ;
V_15 -> V_99 = V_171 -> V_99 ;
V_15 -> V_100 = 0 ;
V_15 -> V_32 = V_171 -> V_32 ;
V_15 -> V_82 = V_171 -> V_82 ;
if ( V_15 -> V_99 )
V_15 -> V_101 = ~ 0 ;
if ( V_162 [ V_178 ] )
F_72 ( V_15 , V_162 [ V_178 ] ) ;
if ( V_162 [ V_179 ] )
F_73 ( V_15 , V_162 [ V_179 ] ) ;
if ( V_162 [ V_180 ] )
F_74 ( V_15 , V_162 [ V_180 ] ) ;
if ( V_162 [ V_181 ] )
F_75 ( V_15 , V_162 [ V_181 ] ) ;
if ( V_162 [ V_182 ] )
V_15 -> V_53 = F_47 ( T_2 , V_15 -> V_53 ,
F_86 ( V_162 [ V_182 ] ) ) ;
if ( V_162 [ V_183 ] )
V_15 -> V_84 = F_87 ( V_162 [ V_183 ] ) ;
return V_174 ;
}
static int F_88 ( struct V_54 * V_55 , struct V_125 * V_168 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
int V_174 ;
if ( ! V_168 )
return - V_132 ;
F_89 ( & V_15 -> V_123 , V_55 ) ;
V_15 -> V_30 = V_31 ;
V_174 = F_85 ( V_55 , V_168 ) ;
if ( V_174 )
F_80 ( L_5 ) ;
return V_174 ;
}
static void F_90 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
F_61 ( & V_15 -> V_123 ) ;
if ( V_15 -> V_119 )
F_91 ( V_15 -> V_119 ) ;
F_62 ( V_15 -> V_106 ) ;
}
static int F_92 ( const struct V_14 * V_15 ,
struct V_1 * V_6 )
{
struct V_125 * V_184 ;
V_184 = F_93 ( V_6 , V_176 ) ;
if ( V_184 == NULL )
goto V_185;
switch ( V_15 -> V_30 ) {
case V_31 :
F_94 ( V_6 , V_184 ) ;
return 0 ;
case V_34 : {
struct V_150 V_151 = {
. V_152 = V_15 -> V_17 . V_22 ,
. V_153 = V_15 -> V_17 . V_27 ,
. V_154 = V_15 -> V_17 . V_26 ,
. V_155 = V_15 -> V_17 . V_20 ,
. V_156 = V_15 -> V_17 . V_25 ,
} ;
if ( F_95 ( V_6 , V_149 , sizeof( V_151 ) , & V_151 ) )
goto V_185;
break;
}
case V_35 : {
struct V_158 V_159 = {
. V_56 = V_15 -> V_17 . V_22 ,
. V_142 = V_15 -> V_17 . V_27 ,
. V_160 = V_15 -> V_17 . V_26 ,
. V_161 = V_15 -> V_17 . V_20 ,
} ;
if ( F_95 ( V_6 , V_157 , sizeof( V_159 ) , & V_159 ) )
goto V_185;
break;
}
}
F_96 ( V_6 , V_184 ) ;
return 0 ;
V_185:
F_94 ( V_6 , V_184 ) ;
return - 1 ;
}
static int F_97 ( struct V_54 * V_55 , struct V_1 * V_6 )
{
const struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_125 * V_164 = (struct V_125 * ) F_98 ( V_6 ) ;
struct V_170 V_171 ;
struct V_136 V_186 ;
struct V_141 V_101 ;
struct V_145 V_92 ;
struct V_146 V_53 ;
V_171 . V_86 = V_15 -> V_86 ;
V_171 . V_87 = V_15 -> V_87 ;
V_171 . V_98 = V_15 -> V_98 ;
V_171 . V_32 = V_15 -> V_32 ;
V_171 . V_99 = V_15 -> V_99 ;
V_171 . V_82 = V_15 -> V_82 ;
if ( F_95 ( V_6 , V_187 , sizeof( V_171 ) , & V_171 ) )
goto V_185;
V_186 . V_138 = V_15 -> V_105 . V_10 ;
V_186 . V_139 = V_15 -> V_33 . V_10 ;
V_186 . V_140 = V_15 -> V_83 . V_10 ;
if ( F_95 ( V_6 , V_178 , sizeof( V_186 ) , & V_186 ) )
goto V_185;
V_101 . V_143 = V_15 -> V_101 ;
V_101 . V_144 = V_15 -> V_102 . V_10 ;
if ( F_95 ( V_6 , V_179 , sizeof( V_101 ) , & V_101 ) )
goto V_185;
V_92 . V_143 = V_15 -> V_92 ;
V_92 . V_144 = V_15 -> V_93 . V_10 ;
if ( F_95 ( V_6 , V_180 , sizeof( V_92 ) , & V_92 ) )
goto V_185;
if ( V_15 -> V_53 >= ( 1ULL << 32 ) ) {
if ( F_99 ( V_6 , V_182 , V_15 -> V_53 ,
V_188 ) )
goto V_185;
V_53 . V_53 = ~ 0U ;
} else {
V_53 . V_53 = V_15 -> V_53 ;
}
V_53 . V_47 = V_15 -> V_47 ;
V_53 . V_48 = V_15 -> V_48 ;
V_53 . V_51 = V_15 -> V_51 ;
if ( F_95 ( V_6 , V_181 , sizeof( V_53 ) , & V_53 ) )
goto V_185;
if ( V_15 -> V_84 && F_100 ( V_6 , V_183 , V_15 -> V_84 ) )
goto V_185;
if ( F_92 ( V_15 , V_6 ) != 0 )
goto V_185;
return F_96 ( V_6 , V_164 ) ;
V_185:
F_101 ( V_6 , V_164 ) ;
return - 1 ;
}
static int F_102 ( struct V_54 * V_55 , unsigned long V_189 ,
struct V_1 * V_6 , struct V_190 * V_191 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
if ( V_189 != 1 || ! V_15 -> V_119 )
return - V_192 ;
V_191 -> V_193 |= F_103 ( 1 ) ;
V_191 -> V_194 = V_15 -> V_119 -> V_195 ;
return 0 ;
}
static int F_104 ( struct V_54 * V_55 , unsigned long V_196 , struct V_54 * V_197 ,
struct V_54 * * V_198 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
* V_198 = F_105 ( V_55 , V_197 , & V_15 -> V_119 ) ;
return 0 ;
}
static struct V_54 * F_106 ( struct V_54 * V_55 , unsigned long V_196 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
return V_15 -> V_119 ;
}
static unsigned long F_107 ( struct V_54 * V_55 , T_1 V_199 )
{
return 1 ;
}
static void F_108 ( struct V_54 * V_55 , unsigned long V_196 )
{
}
static void F_109 ( struct V_54 * V_55 , struct V_200 * V_201 )
{
if ( ! V_201 -> V_202 ) {
if ( V_201 -> V_79 >= V_201 -> V_203 )
if ( V_201 -> V_204 ( V_55 , 1 , V_201 ) < 0 ) {
V_201 -> V_202 = 1 ;
return;
}
V_201 -> V_79 ++ ;
}
}
static int T_9 F_110 ( void )
{
F_80 ( L_6 V_205 L_7 ) ;
return F_111 ( & V_206 ) ;
}
static void T_10 F_112 ( void )
{
F_113 ( & V_206 ) ;
}
