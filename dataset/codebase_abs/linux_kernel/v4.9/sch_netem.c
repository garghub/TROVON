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
if ( V_15 -> V_86 || V_15 -> V_87 )
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
struct V_1 * V_11 ;
if ( V_55 -> V_15 . V_64 )
V_11 = V_55 -> V_15 . V_73 ;
else
V_11 = F_1 ( F_46 ( & V_15 -> V_57 ) ) ;
if ( V_11 ) {
V_104 -= V_5 ( V_11 ) -> V_60 - V_103 ;
V_104 = F_47 ( T_3 , 0 , V_104 ) ;
V_103 = V_5 ( V_11 ) -> V_60 ;
}
V_104 += F_12 ( F_32 ( V_6 ) , V_15 ) ;
}
V_74 -> V_60 = V_103 + V_104 ;
V_74 -> V_107 = V_6 -> V_108 ;
++ V_15 -> V_100 ;
F_21 ( V_6 , V_55 ) ;
} else {
V_74 -> V_60 = F_45 () ;
V_15 -> V_100 = 0 ;
F_30 ( & V_55 -> V_15 , V_6 ) ;
V_55 -> V_109 . V_110 ++ ;
}
V_95:
if ( V_66 ) {
while ( V_66 ) {
V_75 = V_66 -> V_71 ;
V_66 -> V_71 = NULL ;
F_4 ( V_66 ) -> V_111 = V_66 -> V_45 ;
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
V_112:
V_6 = F_52 ( & V_55 -> V_15 ) ;
if ( V_6 ) {
F_53 ( V_55 , V_6 ) ;
V_113:
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
V_6 -> V_114 = NULL ;
V_6 -> V_108 = V_5 ( V_6 ) -> V_107 ;
#ifdef F_55
if ( F_56 ( V_6 -> V_115 ) & V_116 )
V_6 -> V_108 . V_117 = 0 ;
#endif
if ( V_15 -> V_118 ) {
unsigned int V_111 = F_32 ( V_6 ) ;
struct V_1 * V_65 = NULL ;
int V_119 ;
V_119 = F_48 ( V_6 , V_15 -> V_118 , & V_65 ) ;
F_57 ( V_65 ) ;
if ( V_119 != V_81 &&
F_49 ( V_119 ) ) {
F_34 ( V_55 ) ;
F_50 ( V_55 , 1 ,
V_111 ) ;
}
goto V_112;
}
goto V_113;
}
if ( V_15 -> V_118 ) {
V_6 = V_15 -> V_118 -> V_120 -> V_121 ( V_15 -> V_118 ) ;
if ( V_6 )
goto V_113;
}
F_58 ( & V_15 -> V_122 , V_60 ) ;
}
if ( V_15 -> V_118 ) {
V_6 = V_15 -> V_118 -> V_120 -> V_121 ( V_15 -> V_118 ) ;
if ( V_6 )
goto V_113;
}
return NULL ;
}
static void F_59 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
F_60 ( V_55 ) ;
F_16 ( V_55 ) ;
if ( V_15 -> V_118 )
F_61 ( V_15 -> V_118 ) ;
F_62 ( & V_15 -> V_122 ) ;
}
static void F_63 ( struct V_38 * V_123 )
{
F_64 ( V_123 ) ;
}
static int F_65 ( struct V_54 * V_55 , const struct V_124 * V_125 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
T_6 V_126 = F_66 ( V_125 ) / sizeof( V_127 ) ;
const V_127 * V_7 = F_67 ( V_125 ) ;
T_7 * V_128 ;
struct V_38 * V_123 ;
int V_129 ;
T_6 V_130 ;
if ( V_126 > V_131 )
return - V_132 ;
V_130 = sizeof( struct V_38 ) + V_126 * sizeof( V_133 ) ;
V_123 = F_68 ( V_130 , V_134 | V_135 ) ;
if ( ! V_123 )
V_123 = F_69 ( V_130 ) ;
if ( ! V_123 )
return - V_136 ;
V_123 -> V_43 = V_126 ;
for ( V_129 = 0 ; V_129 < V_126 ; V_129 ++ )
V_123 -> V_42 [ V_129 ] = V_7 [ V_129 ] ;
V_128 = F_70 ( V_55 ) ;
F_71 ( V_128 ) ;
F_72 ( V_15 -> V_106 , V_123 ) ;
F_73 ( V_128 ) ;
F_63 ( V_123 ) ;
return 0 ;
}
static void F_74 ( struct V_14 * V_15 , const struct V_124 * V_125 )
{
const struct V_137 * V_138 = F_67 ( V_125 ) ;
F_5 ( & V_15 -> V_105 , V_138 -> V_139 ) ;
F_5 ( & V_15 -> V_33 , V_138 -> V_140 ) ;
F_5 ( & V_15 -> V_83 , V_138 -> V_141 ) ;
}
static void F_75 ( struct V_14 * V_15 , const struct V_124 * V_125 )
{
const struct V_142 * V_143 = F_67 ( V_125 ) ;
V_15 -> V_101 = V_143 -> V_144 ;
F_5 ( & V_15 -> V_102 , V_143 -> V_145 ) ;
}
static void F_76 ( struct V_14 * V_15 , const struct V_124 * V_125 )
{
const struct V_146 * V_143 = F_67 ( V_125 ) ;
V_15 -> V_92 = V_143 -> V_144 ;
F_5 ( & V_15 -> V_93 , V_143 -> V_145 ) ;
}
static void F_77 ( struct V_14 * V_15 , const struct V_124 * V_125 )
{
const struct V_147 * V_143 = F_67 ( V_125 ) ;
V_15 -> V_53 = V_143 -> V_53 ;
V_15 -> V_47 = V_143 -> V_47 ;
V_15 -> V_48 = V_143 -> V_48 ;
V_15 -> V_51 = V_143 -> V_51 ;
if ( V_15 -> V_48 )
V_15 -> V_50 = F_78 ( V_15 -> V_48 ) ;
else
V_15 -> V_50 = (struct F_78 ) { 0 } ;
}
static int F_79 ( struct V_14 * V_15 , const struct V_124 * V_125 )
{
const struct V_124 * V_148 ;
int V_149 ;
F_80 (la, attr, rem) {
T_8 type = F_81 ( V_148 ) ;
switch ( type ) {
case V_150 : {
const struct V_151 * V_152 = F_67 ( V_148 ) ;
if ( F_66 ( V_148 ) < sizeof( struct V_151 ) ) {
F_82 ( L_1 ) ;
return - V_132 ;
}
V_15 -> V_30 = V_34 ;
V_15 -> V_17 . V_9 = V_19 ;
V_15 -> V_17 . V_22 = V_152 -> V_153 ;
V_15 -> V_17 . V_27 = V_152 -> V_154 ;
V_15 -> V_17 . V_26 = V_152 -> V_155 ;
V_15 -> V_17 . V_20 = V_152 -> V_156 ;
V_15 -> V_17 . V_25 = V_152 -> V_157 ;
break;
}
case V_158 : {
const struct V_159 * V_160 = F_67 ( V_148 ) ;
if ( F_66 ( V_148 ) < sizeof( struct V_159 ) ) {
F_82 ( L_2 ) ;
return - V_132 ;
}
V_15 -> V_30 = V_35 ;
V_15 -> V_17 . V_9 = V_28 ;
V_15 -> V_17 . V_22 = V_160 -> V_56 ;
V_15 -> V_17 . V_27 = V_160 -> V_143 ;
V_15 -> V_17 . V_26 = V_160 -> V_161 ;
V_15 -> V_17 . V_20 = V_160 -> V_162 ;
break;
}
default:
F_82 ( L_3 , type ) ;
return - V_132 ;
}
}
return 0 ;
}
static int F_83 ( struct V_124 * V_163 [] , int V_164 , struct V_124 * V_165 ,
const struct V_166 * V_167 , int V_45 )
{
int V_168 = F_66 ( V_165 ) - F_84 ( V_45 ) ;
if ( V_168 < 0 ) {
F_82 ( L_4 , V_168 ) ;
return - V_132 ;
}
if ( V_168 >= F_85 ( 0 ) )
return F_86 ( V_163 , V_164 , F_67 ( V_165 ) + F_84 ( V_45 ) ,
V_168 , V_167 ) ;
memset ( V_163 , 0 , sizeof( struct V_124 * ) * ( V_164 + 1 ) ) ;
return 0 ;
}
static int F_87 ( struct V_54 * V_55 , struct V_124 * V_169 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_124 * V_163 [ V_170 + 1 ] ;
struct V_171 * V_172 ;
struct V_16 V_173 ;
int V_174 = V_31 ;
int V_175 ;
if ( V_169 == NULL )
return - V_132 ;
V_172 = F_67 ( V_169 ) ;
V_175 = F_83 ( V_163 , V_170 , V_169 , V_176 , sizeof( * V_172 ) ) ;
if ( V_175 < 0 )
return V_175 ;
V_173 = V_15 -> V_17 ;
V_174 = V_15 -> V_30 ;
if ( V_163 [ V_177 ] ) {
V_175 = F_79 ( V_15 , V_163 [ V_177 ] ) ;
if ( V_175 ) {
V_15 -> V_30 = V_174 ;
return V_175 ;
}
} else {
V_15 -> V_30 = V_31 ;
}
if ( V_163 [ V_178 ] ) {
V_175 = F_65 ( V_55 , V_163 [ V_178 ] ) ;
if ( V_175 ) {
V_15 -> V_17 = V_173 ;
V_15 -> V_30 = V_174 ;
return V_175 ;
}
}
V_55 -> V_98 = V_172 -> V_98 ;
V_15 -> V_86 = V_172 -> V_86 ;
V_15 -> V_87 = V_172 -> V_87 ;
V_15 -> V_98 = V_172 -> V_98 ;
V_15 -> V_99 = V_172 -> V_99 ;
V_15 -> V_100 = 0 ;
V_15 -> V_32 = V_172 -> V_32 ;
V_15 -> V_82 = V_172 -> V_82 ;
if ( V_15 -> V_99 )
V_15 -> V_101 = ~ 0 ;
if ( V_163 [ V_179 ] )
F_74 ( V_15 , V_163 [ V_179 ] ) ;
if ( V_163 [ V_180 ] )
F_75 ( V_15 , V_163 [ V_180 ] ) ;
if ( V_163 [ V_181 ] )
F_76 ( V_15 , V_163 [ V_181 ] ) ;
if ( V_163 [ V_182 ] )
F_77 ( V_15 , V_163 [ V_182 ] ) ;
if ( V_163 [ V_183 ] )
V_15 -> V_53 = F_47 ( T_2 , V_15 -> V_53 ,
F_88 ( V_163 [ V_183 ] ) ) ;
if ( V_163 [ V_184 ] )
V_15 -> V_84 = F_89 ( V_163 [ V_184 ] ) ;
return V_175 ;
}
static int F_90 ( struct V_54 * V_55 , struct V_124 * V_169 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
int V_175 ;
if ( ! V_169 )
return - V_132 ;
F_91 ( & V_15 -> V_122 , V_55 ) ;
V_15 -> V_30 = V_31 ;
V_175 = F_87 ( V_55 , V_169 ) ;
if ( V_175 )
F_82 ( L_5 ) ;
return V_175 ;
}
static void F_92 ( struct V_54 * V_55 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
F_62 ( & V_15 -> V_122 ) ;
if ( V_15 -> V_118 )
F_93 ( V_15 -> V_118 ) ;
F_63 ( V_15 -> V_106 ) ;
}
static int F_94 ( const struct V_14 * V_15 ,
struct V_1 * V_6 )
{
struct V_124 * V_185 ;
V_185 = F_95 ( V_6 , V_177 ) ;
if ( V_185 == NULL )
goto V_186;
switch ( V_15 -> V_30 ) {
case V_31 :
F_96 ( V_6 , V_185 ) ;
return 0 ;
case V_34 : {
struct V_151 V_152 = {
. V_153 = V_15 -> V_17 . V_22 ,
. V_154 = V_15 -> V_17 . V_27 ,
. V_155 = V_15 -> V_17 . V_26 ,
. V_156 = V_15 -> V_17 . V_20 ,
. V_157 = V_15 -> V_17 . V_25 ,
} ;
if ( F_97 ( V_6 , V_150 , sizeof( V_152 ) , & V_152 ) )
goto V_186;
break;
}
case V_35 : {
struct V_159 V_160 = {
. V_56 = V_15 -> V_17 . V_22 ,
. V_143 = V_15 -> V_17 . V_27 ,
. V_161 = V_15 -> V_17 . V_26 ,
. V_162 = V_15 -> V_17 . V_20 ,
} ;
if ( F_97 ( V_6 , V_158 , sizeof( V_160 ) , & V_160 ) )
goto V_186;
break;
}
}
F_98 ( V_6 , V_185 ) ;
return 0 ;
V_186:
F_96 ( V_6 , V_185 ) ;
return - 1 ;
}
static int F_99 ( struct V_54 * V_55 , struct V_1 * V_6 )
{
const struct V_14 * V_15 = F_17 ( V_55 ) ;
struct V_124 * V_165 = (struct V_124 * ) F_100 ( V_6 ) ;
struct V_171 V_172 ;
struct V_137 V_187 ;
struct V_142 V_101 ;
struct V_146 V_92 ;
struct V_147 V_53 ;
V_172 . V_86 = V_15 -> V_86 ;
V_172 . V_87 = V_15 -> V_87 ;
V_172 . V_98 = V_15 -> V_98 ;
V_172 . V_32 = V_15 -> V_32 ;
V_172 . V_99 = V_15 -> V_99 ;
V_172 . V_82 = V_15 -> V_82 ;
if ( F_97 ( V_6 , V_188 , sizeof( V_172 ) , & V_172 ) )
goto V_186;
V_187 . V_139 = V_15 -> V_105 . V_10 ;
V_187 . V_140 = V_15 -> V_33 . V_10 ;
V_187 . V_141 = V_15 -> V_83 . V_10 ;
if ( F_97 ( V_6 , V_179 , sizeof( V_187 ) , & V_187 ) )
goto V_186;
V_101 . V_144 = V_15 -> V_101 ;
V_101 . V_145 = V_15 -> V_102 . V_10 ;
if ( F_97 ( V_6 , V_180 , sizeof( V_101 ) , & V_101 ) )
goto V_186;
V_92 . V_144 = V_15 -> V_92 ;
V_92 . V_145 = V_15 -> V_93 . V_10 ;
if ( F_97 ( V_6 , V_181 , sizeof( V_92 ) , & V_92 ) )
goto V_186;
if ( V_15 -> V_53 >= ( 1ULL << 32 ) ) {
if ( F_101 ( V_6 , V_183 , V_15 -> V_53 ,
V_189 ) )
goto V_186;
V_53 . V_53 = ~ 0U ;
} else {
V_53 . V_53 = V_15 -> V_53 ;
}
V_53 . V_47 = V_15 -> V_47 ;
V_53 . V_48 = V_15 -> V_48 ;
V_53 . V_51 = V_15 -> V_51 ;
if ( F_97 ( V_6 , V_182 , sizeof( V_53 ) , & V_53 ) )
goto V_186;
if ( V_15 -> V_84 && F_102 ( V_6 , V_184 , V_15 -> V_84 ) )
goto V_186;
if ( F_94 ( V_15 , V_6 ) != 0 )
goto V_186;
return F_98 ( V_6 , V_165 ) ;
V_186:
F_103 ( V_6 , V_165 ) ;
return - 1 ;
}
static int F_104 ( struct V_54 * V_55 , unsigned long V_190 ,
struct V_1 * V_6 , struct V_191 * V_192 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
if ( V_190 != 1 || ! V_15 -> V_118 )
return - V_193 ;
V_192 -> V_194 |= F_105 ( 1 ) ;
V_192 -> V_195 = V_15 -> V_118 -> V_196 ;
return 0 ;
}
static int F_106 ( struct V_54 * V_55 , unsigned long V_197 , struct V_54 * V_198 ,
struct V_54 * * V_199 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
* V_199 = F_107 ( V_55 , V_198 , & V_15 -> V_118 ) ;
return 0 ;
}
static struct V_54 * F_108 ( struct V_54 * V_55 , unsigned long V_197 )
{
struct V_14 * V_15 = F_17 ( V_55 ) ;
return V_15 -> V_118 ;
}
static unsigned long F_109 ( struct V_54 * V_55 , T_1 V_200 )
{
return 1 ;
}
static void F_110 ( struct V_54 * V_55 , unsigned long V_197 )
{
}
static void F_111 ( struct V_54 * V_55 , struct V_201 * V_202 )
{
if ( ! V_202 -> V_203 ) {
if ( V_202 -> V_79 >= V_202 -> V_204 )
if ( V_202 -> V_205 ( V_55 , 1 , V_202 ) < 0 ) {
V_202 -> V_203 = 1 ;
return;
}
V_202 -> V_79 ++ ;
}
}
static int T_9 F_112 ( void )
{
F_82 ( L_6 V_206 L_7 ) ;
return F_113 ( & V_207 ) ;
}
static void T_10 F_114 ( void )
{
F_115 ( & V_207 ) ;
}
