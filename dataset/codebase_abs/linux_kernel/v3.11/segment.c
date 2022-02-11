void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 , 0 ) ) {
F_3 ( & V_2 -> V_3 ) ;
F_4 ( V_2 ) ;
}
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_4 ,
enum V_5 V_5 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
if ( F_7 ( V_2 , V_4 ) )
return;
if ( ! F_8 ( V_4 , V_7 -> V_8 [ V_5 ] ) )
V_7 -> V_9 [ V_5 ] ++ ;
if ( V_5 == V_10 ) {
struct V_11 * V_12 = F_9 ( V_2 , V_4 ) ;
enum V_5 V_13 = V_14 ;
V_5 = V_12 -> type ;
if ( ! F_8 ( V_4 , V_7 -> V_8 [ V_5 ] ) )
V_7 -> V_9 [ V_5 ] ++ ;
for (; V_13 <= V_15 ; V_13 ++ ) {
if ( V_13 == V_5 )
continue;
if ( F_10 ( V_4 , V_7 -> V_8 [ V_13 ] ) )
V_7 -> V_9 [ V_13 ] -- ;
}
}
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_4 ,
enum V_5 V_5 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
if ( F_10 ( V_4 , V_7 -> V_8 [ V_5 ] ) )
V_7 -> V_9 [ V_5 ] -- ;
if ( V_5 == V_10 ) {
enum V_5 V_13 = V_14 ;
for (; V_13 <= V_15 ; V_13 ++ )
if ( F_10 ( V_4 , V_7 -> V_8 [ V_13 ] ) )
V_7 -> V_9 [ V_13 ] -- ;
if ( F_12 ( V_2 , V_4 , V_2 -> V_16 ) == 0 )
F_13 ( F_14 ( V_2 , V_4 ) ,
V_7 -> V_17 ) ;
}
}
static void F_15 ( struct V_1 * V_2 , unsigned int V_4 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
unsigned short V_18 ;
if ( V_4 == V_19 || F_7 ( V_2 , V_4 ) )
return;
F_3 ( & V_7 -> V_20 ) ;
V_18 = F_12 ( V_2 , V_4 , 0 ) ;
if ( V_18 == 0 ) {
F_5 ( V_2 , V_4 , V_21 ) ;
F_11 ( V_2 , V_4 , V_10 ) ;
} else if ( V_18 < V_2 -> V_22 ) {
F_5 ( V_2 , V_4 , V_10 ) ;
} else {
F_11 ( V_2 , V_4 , V_10 ) ;
}
F_16 ( & V_7 -> V_20 ) ;
return;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
unsigned int V_4 = - 1 ;
unsigned int V_23 = F_18 ( V_2 ) ;
F_3 ( & V_7 -> V_20 ) ;
while ( 1 ) {
V_4 = F_19 ( V_7 -> V_8 [ V_21 ] , V_23 ,
V_4 + 1 ) ;
if ( V_4 >= V_23 )
break;
F_20 ( V_2 , V_4 ) ;
}
F_16 ( & V_7 -> V_20 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
unsigned int V_4 = - 1 ;
unsigned int V_23 = F_18 ( V_2 ) ;
F_3 ( & V_7 -> V_20 ) ;
while ( 1 ) {
V_4 = F_19 ( V_7 -> V_8 [ V_21 ] , V_23 ,
V_4 + 1 ) ;
if ( V_4 >= V_23 )
break;
if ( F_10 ( V_4 , V_7 -> V_8 [ V_21 ] ) )
V_7 -> V_9 [ V_21 ] -- ;
if ( F_22 ( V_2 , V_24 ) )
F_23 ( V_2 -> V_25 -> V_26 ,
F_24 ( V_2 , V_4 ) <<
V_2 -> V_27 ,
1 << ( V_2 -> V_27 +
V_2 -> V_28 ) ,
V_29 , 0 ) ;
}
F_16 ( & V_7 -> V_20 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_4 )
{
struct V_30 * V_31 = F_26 ( V_2 ) ;
if ( ! F_27 ( V_4 , V_31 -> V_32 ) )
V_31 -> V_33 ++ ;
}
static void F_28 ( struct V_1 * V_2 , int type ,
unsigned int V_4 , int V_34 )
{
struct V_11 * V_35 = F_9 ( V_2 , V_4 ) ;
V_35 -> type = type ;
if ( V_34 )
F_25 ( V_2 , V_4 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_36 , int V_37 )
{
struct V_11 * V_35 ;
unsigned int V_4 , V_38 ;
long int V_39 ;
V_4 = F_30 ( V_2 , V_36 ) ;
V_35 = F_9 ( V_2 , V_4 ) ;
V_39 = V_35 -> V_18 + V_37 ;
V_38 = F_31 ( V_2 , V_36 ) & ( V_2 -> V_22 - 1 ) ;
F_32 ( ( V_39 >> (sizeof( unsigned short ) << 3 ) ||
( V_39 > V_2 -> V_22 ) ) ) ;
V_35 -> V_18 = V_39 ;
V_35 -> V_40 = F_33 ( V_2 ) ;
F_26 ( V_2 ) -> V_41 = V_35 -> V_40 ;
if ( V_37 > 0 ) {
if ( F_34 ( V_38 , V_35 -> V_42 ) )
F_35 () ;
} else {
if ( ! F_36 ( V_38 , V_35 -> V_42 ) )
F_35 () ;
}
if ( ! F_37 ( V_38 , V_35 -> V_43 ) )
V_35 -> V_44 += V_37 ;
F_25 ( V_2 , V_4 ) ;
F_26 ( V_2 ) -> V_45 += V_37 ;
if ( V_2 -> V_16 > 1 )
F_38 ( V_2 , V_4 ) -> V_18 += V_37 ;
}
static void F_39 ( struct V_1 * V_2 ,
T_1 V_46 , T_1 V_47 )
{
F_29 ( V_2 , V_47 , 1 ) ;
if ( F_30 ( V_2 , V_46 ) != V_19 )
F_29 ( V_2 , V_46 , - 1 ) ;
}
void F_40 ( struct V_1 * V_2 , T_1 V_48 )
{
unsigned int V_4 = F_30 ( V_2 , V_48 ) ;
struct V_30 * V_31 = F_26 ( V_2 ) ;
F_32 ( V_48 == V_49 ) ;
if ( V_48 == V_50 )
return;
F_3 ( & V_31 -> V_51 ) ;
F_29 ( V_2 , V_48 , - 1 ) ;
F_15 ( V_2 , V_4 ) ;
F_16 ( & V_31 -> V_51 ) ;
}
static void F_41 ( struct V_1 * V_2 , int type ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = F_42 ( V_2 , type ) ;
void * V_48 = V_55 -> V_56 ;
V_48 += V_55 -> V_57 * sizeof( struct V_52 ) ;
memcpy ( V_48 , V_53 , sizeof( struct V_52 ) ) ;
return;
}
int F_43 ( struct V_1 * V_2 )
{
int V_58 = 0 ;
int V_59 = 0 ;
int V_60 , V_61 ;
for ( V_60 = V_62 ; V_60 <= V_63 ; V_60 ++ ) {
if ( V_2 -> V_64 -> V_65 [ V_60 ] == V_66 )
V_59 += V_2 -> V_22 ;
else
V_59 += F_44 ( V_2 , V_60 ) ;
}
V_58 = V_59 * ( V_67 + 1 )
+ sizeof( struct V_68 ) + 2
+ sizeof( struct V_69 ) + 2 ;
V_61 = V_70 - V_71 ;
if ( V_58 < V_61 )
return 1 ;
else if ( V_58 < 2 * V_61 )
return 2 ;
return 3 ;
}
struct V_72 * F_45 ( struct V_1 * V_2 , unsigned int V_4 )
{
return F_46 ( V_2 , F_47 ( V_2 , V_4 ) ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_73 * V_56 , T_1 V_74 )
{
struct V_72 * V_72 = F_49 ( V_2 , V_74 ) ;
void * V_75 = F_50 ( V_72 ) ;
memcpy ( V_75 , V_56 , V_70 ) ;
F_51 ( V_72 ) ;
F_52 ( V_72 , 1 ) ;
}
static int F_53 ( struct V_1 * V_2 , int type )
{
struct V_54 * V_55 = F_42 ( V_2 , type ) ;
unsigned int V_4 = V_55 -> V_4 + 1 ;
struct V_76 * V_77 = F_54 ( V_2 ) ;
if ( V_4 < F_18 ( V_2 ) && V_4 % V_2 -> V_16 )
return ! F_55 ( V_4 , V_77 -> V_78 ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 ,
unsigned int * V_79 , bool V_80 , int V_81 )
{
struct V_76 * V_77 = F_54 ( V_2 ) ;
unsigned int V_4 , V_82 , V_83 ;
unsigned int V_84 = F_57 ( V_2 ) / V_2 -> V_85 ;
unsigned int V_86 = * V_79 / V_2 -> V_16 ;
unsigned int V_87 = F_58 ( V_2 , * V_79 ) ;
unsigned int V_88 = V_86 ;
bool V_89 = true ;
int V_90 = 0 ;
int V_60 ;
F_59 ( & V_77 -> V_91 ) ;
if ( ! V_80 && ( ( * V_79 + 1 ) % V_2 -> V_16 ) ) {
V_4 = F_60 ( V_77 -> V_78 ,
F_18 ( V_2 ) , * V_79 + 1 ) ;
if ( V_4 - * V_79 < V_2 -> V_16 -
( * V_79 % V_2 -> V_16 ) )
goto V_92;
}
V_93:
V_82 = F_60 ( V_77 -> V_94 , F_57 ( V_2 ) , V_86 ) ;
if ( V_82 >= F_57 ( V_2 ) ) {
if ( V_81 == V_95 ) {
V_82 = F_60 ( V_77 -> V_94 ,
F_57 ( V_2 ) , 0 ) ;
F_32 ( V_82 >= F_57 ( V_2 ) ) ;
} else {
V_90 = 1 ;
V_88 = V_86 - 1 ;
}
}
if ( V_90 == 0 )
goto V_96;
while ( F_55 ( V_88 , V_77 -> V_94 ) ) {
if ( V_88 > 0 ) {
V_88 -- ;
continue;
}
V_88 = F_60 ( V_77 -> V_94 ,
F_57 ( V_2 ) , 0 ) ;
F_32 ( V_88 >= F_57 ( V_2 ) ) ;
break;
}
V_82 = V_88 ;
V_96:
V_86 = V_82 ;
V_4 = V_82 * V_2 -> V_16 ;
V_83 = V_82 / V_2 -> V_85 ;
if ( ! V_89 )
goto V_92;
if ( V_2 -> V_85 == 1 )
goto V_92;
if ( V_83 == V_87 )
goto V_92;
if ( V_81 == V_97 ) {
if ( ! V_90 && V_83 + 1 >= V_84 )
goto V_92;
if ( V_90 && V_83 == 0 )
goto V_92;
}
for ( V_60 = 0 ; V_60 < V_98 ; V_60 ++ )
if ( F_42 ( V_2 , V_60 ) -> V_99 == V_83 )
break;
if ( V_60 < V_98 ) {
if ( V_90 )
V_86 = V_83 * V_2 -> V_85 - 1 ;
else if ( V_83 + 1 >= V_84 )
V_86 = 0 ;
else
V_86 = ( V_83 + 1 ) * V_2 -> V_85 ;
V_89 = false ;
goto V_93;
}
V_92:
F_32 ( F_55 ( V_4 , V_77 -> V_78 ) ) ;
F_61 ( V_2 , V_4 ) ;
* V_79 = V_4 ;
F_62 ( & V_77 -> V_91 ) ;
}
static void F_63 ( struct V_1 * V_2 , int type , int V_34 )
{
struct V_54 * V_55 = F_42 ( V_2 , type ) ;
struct V_100 * V_101 ;
V_55 -> V_4 = V_55 -> V_102 ;
V_55 -> V_99 = F_58 ( V_2 , V_55 -> V_4 ) ;
V_55 -> V_57 = 0 ;
V_55 -> V_102 = V_19 ;
V_101 = & ( V_55 -> V_56 -> V_103 ) ;
memset ( V_101 , 0 , sizeof( struct V_100 ) ) ;
if ( F_64 ( type ) )
F_65 ( V_101 , V_104 ) ;
if ( F_66 ( type ) )
F_65 ( V_101 , V_105 ) ;
F_28 ( V_2 , type , V_55 -> V_4 , V_34 ) ;
}
static void F_67 ( struct V_1 * V_2 , int type , bool V_80 )
{
struct V_54 * V_55 = F_42 ( V_2 , type ) ;
unsigned int V_4 = V_55 -> V_4 ;
int V_81 = V_97 ;
F_48 ( V_2 , V_55 -> V_56 ,
F_47 ( V_2 , V_4 ) ) ;
if ( type == V_106 || type == V_63 )
V_81 = V_95 ;
if ( F_22 ( V_2 , V_107 ) )
V_81 = V_95 ;
F_56 ( V_2 , & V_4 , V_80 , V_81 ) ;
V_55 -> V_102 = V_4 ;
F_63 ( V_2 , type , 1 ) ;
V_55 -> V_65 = V_108 ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_54 * V_109 , T_1 V_110 )
{
struct V_11 * V_35 = F_9 ( V_2 , V_109 -> V_4 ) ;
T_1 V_111 ;
for ( V_111 = V_110 ; V_111 < V_2 -> V_22 ; V_111 ++ ) {
if ( ! F_37 ( V_111 , V_35 -> V_43 )
&& ! F_37 ( V_111 , V_35 -> V_42 ) )
break;
}
V_109 -> V_57 = V_111 ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_54 * V_109 )
{
if ( V_109 -> V_65 == V_66 )
F_68 ( V_2 , V_109 , V_109 -> V_57 + 1 ) ;
else
V_109 -> V_57 ++ ;
}
static void F_70 ( struct V_1 * V_2 , int type , bool V_112 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
struct V_54 * V_55 = F_42 ( V_2 , type ) ;
unsigned int V_113 = V_55 -> V_102 ;
struct V_73 * V_114 ;
struct V_72 * V_115 ;
F_48 ( V_2 , V_55 -> V_56 ,
F_47 ( V_2 , V_55 -> V_4 ) ) ;
F_71 ( V_2 , V_113 ) ;
F_3 ( & V_7 -> V_20 ) ;
F_11 ( V_2 , V_113 , V_21 ) ;
F_11 ( V_2 , V_113 , V_10 ) ;
F_16 ( & V_7 -> V_20 ) ;
F_63 ( V_2 , type , 1 ) ;
V_55 -> V_65 = V_66 ;
F_68 ( V_2 , V_55 , 0 ) ;
if ( V_112 ) {
V_115 = F_45 ( V_2 , V_113 ) ;
V_114 = (struct V_73 * ) F_50 ( V_115 ) ;
memcpy ( V_55 -> V_56 , V_114 , V_116 ) ;
F_52 ( V_115 , 1 ) ;
}
}
static int F_72 ( struct V_1 * V_2 , int type )
{
struct V_54 * V_55 = F_42 ( V_2 , type ) ;
const struct V_117 * V_118 = F_6 ( V_2 ) -> V_118 ;
if ( F_66 ( type ) || ! F_2 ( V_2 , 0 ) )
return V_118 -> V_119 ( V_2 ,
& ( V_55 ) -> V_102 , V_120 , type , V_66 ) ;
for (; type >= V_62 ; type -- )
if ( V_118 -> V_119 ( V_2 , & ( V_55 ) -> V_102 ,
V_120 , type , V_66 ) )
return 1 ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 ,
int type , bool V_121 )
{
struct V_54 * V_55 = F_42 ( V_2 , type ) ;
if ( V_121 ) {
F_67 ( V_2 , type , true ) ;
goto V_122;
}
if ( type == V_123 )
F_67 ( V_2 , type , false ) ;
else if ( V_55 -> V_65 == V_108 && F_53 ( V_2 , type ) )
F_67 ( V_2 , type , false ) ;
else if ( F_74 ( V_2 ) && F_72 ( V_2 , type ) )
F_70 ( V_2 , type , true ) ;
else
F_67 ( V_2 , type , false ) ;
V_122:
#ifdef F_75
V_2 -> V_124 [ V_55 -> V_65 ] ++ ;
#endif
return;
}
void F_76 ( struct V_1 * V_2 )
{
struct V_54 * V_55 ;
unsigned int V_125 ;
int V_60 ;
for ( V_60 = V_62 ; V_60 <= V_63 ; V_60 ++ ) {
V_55 = F_42 ( V_2 , V_60 ) ;
V_125 = V_55 -> V_4 ;
F_26 ( V_2 ) -> V_126 -> V_127 ( V_2 , V_60 , true ) ;
F_15 ( V_2 , V_125 ) ;
}
}
static void F_77 ( struct V_128 * V_128 , int V_129 )
{
const int V_130 = F_55 ( V_131 , & V_128 -> V_132 ) ;
struct V_133 * V_134 = V_128 -> V_135 + V_128 -> V_136 - 1 ;
struct V_137 * V_138 = V_128 -> V_139 ;
do {
struct V_72 * V_72 = V_134 -> V_140 ;
if ( -- V_134 >= V_128 -> V_135 )
F_78 ( & V_134 -> V_140 -> V_141 ) ;
if ( ! V_130 ) {
F_79 ( V_72 ) ;
if ( V_72 -> V_142 )
F_80 ( V_143 , & V_72 -> V_142 -> V_141 ) ;
F_81 ( V_138 -> V_2 -> V_64 , V_144 ) ;
V_138 -> V_2 -> V_25 -> V_145 |= V_146 ;
}
F_82 ( V_72 ) ;
F_83 ( V_138 -> V_2 , V_147 ) ;
} while ( V_134 >= V_128 -> V_135 );
if ( V_138 -> V_148 )
F_84 ( V_138 -> V_149 ) ;
F_85 ( V_138 ) ;
F_86 ( V_128 ) ;
}
struct V_128 * F_87 ( struct V_150 * V_151 , int V_152 )
{
struct V_128 * V_128 ;
struct V_137 * V_153 ;
V_154:
V_153 = F_88 ( sizeof( struct V_137 ) , V_29 ) ;
if ( ! V_153 ) {
F_89 () ;
goto V_154;
}
V_128 = F_90 ( V_155 , V_152 ) ;
V_128 -> V_156 = V_151 ;
V_128 -> V_139 = V_153 ;
return V_128 ;
}
static void F_91 ( struct V_1 * V_2 ,
enum V_157 type , bool V_158 )
{
int V_159 = V_158 ? V_160 : V_161 ;
enum V_157 V_162 = type > V_163 ? V_163 : type ;
if ( type >= V_164 )
V_159 = V_165 ;
if ( V_162 == V_163 )
V_159 |= V_166 ;
if ( V_2 -> V_128 [ V_162 ] ) {
struct V_137 * V_138 = V_2 -> V_128 [ V_162 ] -> V_139 ;
V_138 -> V_2 = V_2 ;
V_2 -> V_128 [ V_162 ] -> V_167 = F_77 ;
F_92 ( V_2 -> V_25 , V_162 , V_158 , V_2 -> V_128 [ V_162 ] ) ;
if ( type == V_164 ) {
F_93 ( V_149 ) ;
V_138 -> V_148 = true ;
V_138 -> V_149 = & V_149 ;
F_94 ( V_159 , V_2 -> V_128 [ V_162 ] ) ;
F_95 ( & V_149 ) ;
} else {
V_138 -> V_148 = false ;
F_94 ( V_159 , V_2 -> V_128 [ V_162 ] ) ;
}
V_2 -> V_128 [ V_162 ] = NULL ;
}
}
void F_96 ( struct V_1 * V_2 , enum V_157 type , bool V_158 )
{
F_97 ( & V_2 -> V_168 ) ;
F_91 ( V_2 , type , V_158 ) ;
F_98 ( & V_2 -> V_168 ) ;
}
static void F_99 ( struct V_1 * V_2 , struct V_72 * V_72 ,
T_1 V_74 , enum V_157 type )
{
struct V_150 * V_151 = V_2 -> V_25 -> V_26 ;
F_100 ( V_2 , V_74 ) ;
F_97 ( & V_2 -> V_168 ) ;
F_101 ( V_2 , V_147 ) ;
if ( V_2 -> V_128 [ type ] && V_2 -> V_169 [ type ] != V_74 - 1 )
F_91 ( V_2 , type , false ) ;
V_170:
if ( V_2 -> V_128 [ type ] == NULL ) {
V_2 -> V_128 [ type ] = F_87 ( V_151 , F_102 ( V_2 ) ) ;
V_2 -> V_128 [ type ] -> V_171 = F_103 ( V_2 , V_74 ) ;
}
if ( F_104 ( V_2 -> V_128 [ type ] , V_72 , V_70 , 0 ) <
V_70 ) {
F_91 ( V_2 , type , false ) ;
goto V_170;
}
V_2 -> V_169 [ type ] = V_74 ;
F_98 ( & V_2 -> V_168 ) ;
F_105 ( V_72 , V_74 , type ) ;
}
static bool F_106 ( struct V_1 * V_2 , int type )
{
struct V_54 * V_55 = F_42 ( V_2 , type ) ;
if ( V_55 -> V_57 < V_2 -> V_22 )
return true ;
return false ;
}
static int F_107 ( struct V_72 * V_72 , enum V_157 V_172 )
{
if ( V_172 == V_173 )
return V_62 ;
else
return V_174 ;
}
static int F_108 ( struct V_72 * V_72 , enum V_157 V_172 )
{
if ( V_172 == V_173 ) {
struct V_175 * V_175 = V_72 -> V_142 -> V_176 ;
if ( F_109 ( V_175 -> V_177 ) )
return V_62 ;
else
return V_63 ;
} else {
if ( F_110 ( V_72 ) && ! F_111 ( V_72 ) )
return V_174 ;
else
return V_178 ;
}
}
static int F_112 ( struct V_72 * V_72 , enum V_157 V_172 )
{
if ( V_172 == V_173 ) {
struct V_175 * V_175 = V_72 -> V_142 -> V_176 ;
if ( F_109 ( V_175 -> V_177 ) )
return V_62 ;
else if ( F_113 ( V_72 ) || F_114 ( V_175 ) )
return V_63 ;
else
return V_106 ;
} else {
if ( F_110 ( V_72 ) )
return F_111 ( V_72 ) ? V_123 :
V_174 ;
else
return V_178 ;
}
}
static int F_115 ( struct V_72 * V_72 , enum V_157 V_172 )
{
struct V_1 * V_2 = F_116 ( V_72 -> V_142 -> V_176 -> V_179 ) ;
switch ( V_2 -> V_180 ) {
case 2 :
return F_107 ( V_72 , V_172 ) ;
case 4 :
return F_108 ( V_72 , V_172 ) ;
}
F_32 ( V_2 -> V_180 != V_98 ) ;
return F_112 ( V_72 , V_172 ) ;
}
static void F_117 ( struct V_1 * V_2 , struct V_72 * V_72 ,
T_1 V_46 , T_1 * V_47 ,
struct V_52 * V_53 , enum V_157 V_172 )
{
struct V_30 * V_31 = F_26 ( V_2 ) ;
struct V_54 * V_55 ;
unsigned int V_181 ;
int type ;
type = F_115 ( V_72 , V_172 ) ;
V_55 = F_42 ( V_2 , type ) ;
F_3 ( & V_55 -> V_182 ) ;
* V_47 = F_118 ( V_2 , V_55 ) ;
V_181 = V_55 -> V_4 ;
F_41 ( V_2 , type , V_53 ) ;
F_3 ( & V_31 -> V_51 ) ;
F_69 ( V_2 , V_55 ) ;
#ifdef F_75
V_2 -> V_183 [ V_55 -> V_65 ] ++ ;
#endif
F_39 ( V_2 , V_46 , * V_47 ) ;
if ( ! F_106 ( V_2 , type ) )
V_31 -> V_126 -> V_127 ( V_2 , type , false ) ;
F_15 ( V_2 , V_181 ) ;
F_15 ( V_2 , F_30 ( V_2 , V_46 ) ) ;
F_16 ( & V_31 -> V_51 ) ;
if ( V_172 == V_184 )
F_119 ( V_72 , F_118 ( V_2 , V_55 ) ) ;
F_99 ( V_2 , V_72 , * V_47 , V_172 ) ;
F_16 ( & V_55 -> V_182 ) ;
}
void F_120 ( struct V_1 * V_2 , struct V_72 * V_72 )
{
F_121 ( V_72 ) ;
F_99 ( V_2 , V_72 , V_72 -> V_185 , V_163 ) ;
}
void F_122 ( struct V_1 * V_2 , struct V_72 * V_72 ,
unsigned int V_186 , T_1 V_46 , T_1 * V_47 )
{
struct V_52 V_53 ;
F_123 ( & V_53 , V_186 , 0 , 0 ) ;
F_117 ( V_2 , V_72 , V_46 , V_47 , & V_53 , V_184 ) ;
}
void F_124 ( struct V_175 * V_175 , struct V_72 * V_72 ,
struct V_187 * V_188 , T_1 V_46 ,
T_1 * V_47 )
{
struct V_1 * V_2 = F_116 ( V_175 -> V_179 ) ;
struct V_52 V_53 ;
struct V_189 V_190 ;
F_32 ( V_46 == V_49 ) ;
F_125 ( V_2 , V_188 -> V_186 , & V_190 ) ;
F_123 ( & V_53 , V_188 -> V_186 , V_188 -> V_191 , V_190 . V_192 ) ;
F_117 ( V_2 , V_72 , V_46 ,
V_47 , & V_53 , V_173 ) ;
}
void F_126 ( struct V_1 * V_2 , struct V_72 * V_72 ,
T_1 V_193 )
{
F_99 ( V_2 , V_72 , V_193 , V_173 ) ;
}
void F_127 ( struct V_1 * V_2 ,
struct V_72 * V_72 , struct V_52 * V_53 ,
T_1 V_46 , T_1 V_47 )
{
struct V_30 * V_31 = F_26 ( V_2 ) ;
struct V_54 * V_55 ;
unsigned int V_4 , V_181 ;
struct V_11 * V_35 ;
int type ;
V_4 = F_30 ( V_2 , V_47 ) ;
V_35 = F_9 ( V_2 , V_4 ) ;
type = V_35 -> type ;
if ( V_35 -> V_18 == 0 && ! F_7 ( V_2 , V_4 ) ) {
if ( V_46 == V_49 )
type = V_63 ;
else
type = V_106 ;
}
V_55 = F_42 ( V_2 , type ) ;
F_3 ( & V_55 -> V_182 ) ;
F_3 ( & V_31 -> V_51 ) ;
V_181 = V_55 -> V_4 ;
if ( V_4 != V_55 -> V_4 ) {
V_55 -> V_102 = V_4 ;
F_70 ( V_2 , type , true ) ;
}
V_55 -> V_57 = F_31 ( V_2 , V_47 ) &
( V_2 -> V_22 - 1 ) ;
F_41 ( V_2 , type , V_53 ) ;
F_39 ( V_2 , V_46 , V_47 ) ;
F_15 ( V_2 , V_181 ) ;
F_15 ( V_2 , F_30 ( V_2 , V_46 ) ) ;
F_16 ( & V_31 -> V_51 ) ;
F_16 ( & V_55 -> V_182 ) ;
}
void F_128 ( struct V_1 * V_2 ,
struct V_72 * V_72 , struct V_52 * V_53 ,
T_1 V_46 , T_1 V_47 )
{
struct V_30 * V_31 = F_26 ( V_2 ) ;
int type = V_123 ;
struct V_54 * V_55 ;
unsigned int V_4 , V_181 ;
T_1 V_194 = F_129 ( V_72 ) ;
unsigned int V_102 = F_30 ( V_2 , V_194 ) ;
V_55 = F_42 ( V_2 , type ) ;
F_3 ( & V_55 -> V_182 ) ;
F_3 ( & V_31 -> V_51 ) ;
V_4 = F_30 ( V_2 , V_47 ) ;
V_181 = V_55 -> V_4 ;
if ( V_4 != V_55 -> V_4 ) {
V_55 -> V_102 = V_4 ;
F_70 ( V_2 , type , true ) ;
}
V_55 -> V_57 = F_31 ( V_2 , V_47 ) &
( V_2 -> V_22 - 1 ) ;
F_41 ( V_2 , type , V_53 ) ;
if ( V_102 != V_4 ) {
V_55 -> V_102 = V_102 ;
F_70 ( V_2 , type , true ) ;
}
V_55 -> V_57 = F_31 ( V_2 , V_194 ) &
( V_2 -> V_22 - 1 ) ;
F_121 ( V_72 ) ;
F_99 ( V_2 , V_72 , V_47 , V_184 ) ;
F_96 ( V_2 , V_184 , true ) ;
F_39 ( V_2 , V_46 , V_47 ) ;
F_15 ( V_2 , V_181 ) ;
F_15 ( V_2 , F_30 ( V_2 , V_46 ) ) ;
F_16 ( & V_31 -> V_51 ) ;
F_16 ( & V_55 -> V_182 ) ;
}
static int F_130 ( struct V_1 * V_2 )
{
struct V_195 * V_64 = F_131 ( V_2 ) ;
struct V_54 * V_196 ;
unsigned char * V_75 ;
struct V_72 * V_72 ;
T_1 V_110 ;
int V_60 , V_197 , V_38 ;
V_110 = F_132 ( V_2 ) ;
V_72 = F_46 ( V_2 , V_110 ++ ) ;
V_75 = ( unsigned char * ) F_50 ( V_72 ) ;
V_196 = F_42 ( V_2 , V_62 ) ;
memcpy ( & V_196 -> V_56 -> V_198 , V_75 , V_199 ) ;
V_196 = F_42 ( V_2 , V_63 ) ;
memcpy ( & V_196 -> V_56 -> V_200 , V_75 + V_199 ,
V_199 ) ;
V_38 = 2 * V_199 ;
for ( V_60 = V_62 ; V_60 <= V_63 ; V_60 ++ ) {
unsigned short V_201 ;
unsigned int V_4 ;
V_196 = F_42 ( V_2 , V_60 ) ;
V_4 = F_133 ( V_64 -> V_202 [ V_60 ] ) ;
V_201 = F_134 ( V_64 -> V_203 [ V_60 ] ) ;
V_196 -> V_102 = V_4 ;
F_63 ( V_2 , V_60 , 0 ) ;
V_196 -> V_65 = V_64 -> V_65 [ V_60 ] ;
V_196 -> V_57 = V_201 ;
if ( V_196 -> V_65 == V_66 )
V_201 = V_2 -> V_22 ;
for ( V_197 = 0 ; V_197 < V_201 ; V_197 ++ ) {
struct V_52 * V_204 ;
V_204 = (struct V_52 * ) ( V_75 + V_38 ) ;
V_196 -> V_56 -> V_205 [ V_197 ] = * V_204 ;
V_38 += V_67 ;
if ( V_38 + V_67 <= V_70 -
V_71 )
continue;
F_52 ( V_72 , 1 ) ;
V_72 = NULL ;
V_72 = F_46 ( V_2 , V_110 ++ ) ;
V_75 = ( unsigned char * ) F_50 ( V_72 ) ;
V_38 = 0 ;
}
}
F_52 ( V_72 , 1 ) ;
return 0 ;
}
static int F_135 ( struct V_1 * V_2 , int type )
{
struct V_195 * V_64 = F_131 ( V_2 ) ;
struct V_73 * V_53 ;
struct V_54 * V_55 ;
struct V_72 * V_206 ;
unsigned short V_201 ;
unsigned int V_4 = 0 ;
T_1 V_74 = 0 ;
if ( F_64 ( type ) ) {
V_4 = F_133 ( V_64 -> V_202 [ type ] ) ;
V_201 = F_134 ( V_64 -> V_203 [ type -
V_62 ] ) ;
if ( F_136 ( V_64 , V_207 ) )
V_74 = F_137 ( V_2 , V_98 , type ) ;
else
V_74 = F_137 ( V_2 , V_208 , type ) ;
} else {
V_4 = F_133 ( V_64 -> V_209 [ type -
V_174 ] ) ;
V_201 = F_134 ( V_64 -> V_210 [ type -
V_174 ] ) ;
if ( F_136 ( V_64 , V_207 ) )
V_74 = F_137 ( V_2 , V_211 ,
type - V_174 ) ;
else
V_74 = F_47 ( V_2 , V_4 ) ;
}
V_206 = F_46 ( V_2 , V_74 ) ;
V_53 = (struct V_73 * ) F_50 ( V_206 ) ;
if ( F_66 ( type ) ) {
if ( F_136 ( V_64 , V_207 ) ) {
struct V_52 * V_212 = & V_53 -> V_205 [ 0 ] ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_22 ; V_60 ++ , V_212 ++ ) {
V_212 -> V_192 = 0 ;
V_212 -> V_191 = 0 ;
}
} else {
if ( F_138 ( V_2 , V_4 , V_53 ) ) {
F_52 ( V_206 , 1 ) ;
return - V_213 ;
}
}
}
V_55 = F_42 ( V_2 , type ) ;
F_3 ( & V_55 -> V_182 ) ;
memcpy ( V_55 -> V_56 , V_53 , V_70 ) ;
V_55 -> V_102 = V_4 ;
F_63 ( V_2 , type , 0 ) ;
V_55 -> V_65 = V_64 -> V_65 [ type ] ;
V_55 -> V_57 = V_201 ;
F_16 ( & V_55 -> V_182 ) ;
F_52 ( V_206 , 1 ) ;
return 0 ;
}
static int F_139 ( struct V_1 * V_2 )
{
int type = V_62 ;
if ( F_136 ( F_131 ( V_2 ) , V_214 ) ) {
if ( F_130 ( V_2 ) )
return - V_213 ;
type = V_174 ;
}
for (; type <= V_178 ; type ++ )
if ( F_135 ( V_2 , type ) )
return - V_213 ;
return 0 ;
}
static void F_140 ( struct V_1 * V_2 , T_1 V_36 )
{
struct V_72 * V_72 ;
unsigned char * V_75 ;
struct V_52 * V_215 ;
struct V_54 * V_196 ;
int V_216 = 0 ;
int V_60 , V_197 ;
V_72 = F_49 ( V_2 , V_36 ++ ) ;
V_75 = ( unsigned char * ) F_50 ( V_72 ) ;
V_196 = F_42 ( V_2 , V_62 ) ;
memcpy ( V_75 , & V_196 -> V_56 -> V_198 , V_199 ) ;
V_216 += V_199 ;
V_196 = F_42 ( V_2 , V_63 ) ;
memcpy ( V_75 + V_216 , & V_196 -> V_56 -> V_200 ,
V_199 ) ;
V_216 += V_199 ;
F_51 ( V_72 ) ;
for ( V_60 = V_62 ; V_60 <= V_63 ; V_60 ++ ) {
unsigned short V_217 ;
V_196 = F_42 ( V_2 , V_60 ) ;
if ( V_2 -> V_64 -> V_65 [ V_60 ] == V_66 )
V_217 = V_2 -> V_22 ;
else
V_217 = F_44 ( V_2 , V_60 ) ;
for ( V_197 = 0 ; V_197 < V_217 ; V_197 ++ ) {
if ( ! V_72 ) {
V_72 = F_49 ( V_2 , V_36 ++ ) ;
V_75 = ( unsigned char * ) F_50 ( V_72 ) ;
V_216 = 0 ;
}
V_215 = (struct V_52 * ) ( V_75 + V_216 ) ;
* V_215 = V_196 -> V_56 -> V_205 [ V_197 ] ;
V_216 += V_67 ;
F_51 ( V_72 ) ;
if ( V_216 + V_67 <= V_70 -
V_71 )
continue;
F_52 ( V_72 , 1 ) ;
V_72 = NULL ;
}
}
if ( V_72 )
F_52 ( V_72 , 1 ) ;
}
static void F_141 ( struct V_1 * V_2 ,
T_1 V_36 , int type )
{
int V_60 , V_218 ;
if ( F_64 ( type ) )
V_218 = type + V_208 ;
else
V_218 = type + V_211 ;
for ( V_60 = type ; V_60 < V_218 ; V_60 ++ ) {
struct V_54 * V_53 = F_42 ( V_2 , V_60 ) ;
F_3 ( & V_53 -> V_182 ) ;
F_48 ( V_2 , V_53 -> V_56 , V_36 + ( V_60 - type ) ) ;
F_16 ( & V_53 -> V_182 ) ;
}
}
void F_142 ( struct V_1 * V_2 , T_1 V_219 )
{
if ( F_136 ( F_131 ( V_2 ) , V_214 ) )
F_140 ( V_2 , V_219 ) ;
else
F_141 ( V_2 , V_219 , V_62 ) ;
}
void F_143 ( struct V_1 * V_2 , T_1 V_219 )
{
if ( F_136 ( F_131 ( V_2 ) , V_207 ) )
F_141 ( V_2 , V_219 , V_174 ) ;
return;
}
int F_144 ( struct V_73 * V_53 , int type ,
unsigned int V_220 , int V_221 )
{
int V_60 ;
if ( type == V_222 ) {
for ( V_60 = 0 ; V_60 < F_145 ( V_53 ) ; V_60 ++ ) {
if ( F_133 ( F_146 ( V_53 , V_60 ) ) == V_220 )
return V_60 ;
}
if ( V_221 && F_145 ( V_53 ) < V_223 )
return F_147 ( V_53 , 1 ) ;
} else if ( type == V_224 ) {
for ( V_60 = 0 ; V_60 < F_148 ( V_53 ) ; V_60 ++ )
if ( F_133 ( F_149 ( V_53 , V_60 ) ) == V_220 )
return V_60 ;
if ( V_221 && F_148 ( V_53 ) < V_225 )
return F_150 ( V_53 , 1 ) ;
}
return - 1 ;
}
static struct V_72 * F_151 ( struct V_1 * V_2 ,
unsigned int V_4 )
{
struct V_30 * V_31 = F_26 ( V_2 ) ;
unsigned int V_38 = F_152 ( V_31 , V_4 ) ;
T_1 V_74 = V_31 -> V_226 + V_38 ;
F_153 ( V_2 , V_4 ) ;
if ( F_37 ( V_38 , V_31 -> V_227 ) )
V_74 += V_31 -> V_228 ;
return F_46 ( V_2 , V_74 ) ;
}
static struct V_72 * F_154 ( struct V_1 * V_2 ,
unsigned int V_110 )
{
struct V_30 * V_31 = F_26 ( V_2 ) ;
struct V_72 * V_229 , * V_230 ;
T_2 V_231 , V_232 ;
void * V_233 , * V_234 ;
V_231 = F_155 ( V_2 , V_110 ) ;
V_232 = F_156 ( V_2 , V_231 ) ;
V_229 = F_46 ( V_2 , V_231 ) ;
V_230 = F_49 ( V_2 , V_232 ) ;
F_32 ( F_157 ( V_229 ) ) ;
V_233 = F_50 ( V_229 ) ;
V_234 = F_50 ( V_230 ) ;
memcpy ( V_234 , V_233 , V_70 ) ;
F_51 ( V_230 ) ;
F_52 ( V_229 , 1 ) ;
F_158 ( V_31 , V_110 ) ;
return V_230 ;
}
static bool F_159 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_42 ( V_2 , V_63 ) ;
struct V_73 * V_53 = V_55 -> V_56 ;
int V_60 ;
if ( F_148 ( V_53 ) >= V_225 ) {
for ( V_60 = F_148 ( V_53 ) - 1 ; V_60 >= 0 ; V_60 -- ) {
unsigned int V_4 ;
V_4 = F_133 ( F_149 ( V_53 , V_60 ) ) ;
F_25 ( V_2 , V_4 ) ;
}
F_150 ( V_53 , - F_148 ( V_53 ) ) ;
return 1 ;
}
return 0 ;
}
void F_160 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_26 ( V_2 ) ;
unsigned long * V_235 = V_31 -> V_32 ;
struct V_54 * V_55 = F_42 ( V_2 , V_63 ) ;
struct V_73 * V_53 = V_55 -> V_56 ;
unsigned long V_236 = F_18 ( V_2 ) ;
struct V_72 * V_72 = NULL ;
struct V_237 * V_238 = NULL ;
unsigned int V_110 = 0 , V_218 = 0 ;
unsigned int V_4 = - 1 ;
bool V_239 ;
F_3 ( & V_55 -> V_182 ) ;
F_3 ( & V_31 -> V_51 ) ;
V_239 = F_159 ( V_2 ) ;
while ( ( V_4 = F_19 ( V_235 , V_236 , V_4 + 1 ) ) < V_236 ) {
struct V_11 * V_35 = F_9 ( V_2 , V_4 ) ;
int V_240 , V_38 ;
V_240 = F_161 ( V_31 , V_4 ) ;
if ( V_239 )
goto V_241;
V_38 = F_144 ( V_53 , V_224 , V_4 , 1 ) ;
if ( V_38 >= 0 ) {
F_149 ( V_53 , V_38 ) = F_162 ( V_4 ) ;
F_163 ( V_35 , & F_164 ( V_53 , V_38 ) ) ;
goto V_242;
}
V_241:
if ( ! V_72 || ( V_110 > V_4 ) || ( V_4 > V_218 ) ) {
if ( V_72 ) {
F_52 ( V_72 , 1 ) ;
V_72 = NULL ;
}
V_110 = F_165 ( V_31 , V_4 ) ;
V_218 = V_110 + V_243 - 1 ;
V_72 = F_154 ( V_2 , V_110 ) ;
V_238 = F_50 ( V_72 ) ;
}
F_163 ( V_35 , & V_238 -> V_205 [ V_240 ] ) ;
V_242:
F_166 ( V_4 , V_235 ) ;
V_31 -> V_33 -- ;
}
F_16 ( & V_31 -> V_51 ) ;
F_16 ( & V_55 -> V_182 ) ;
F_52 ( V_72 , 1 ) ;
F_17 ( V_2 ) ;
}
static int F_167 ( struct V_1 * V_2 )
{
struct V_244 * V_245 = F_168 ( V_2 ) ;
struct V_195 * V_64 = F_131 ( V_2 ) ;
struct V_30 * V_31 ;
unsigned int V_246 , V_110 ;
char * V_247 , * V_248 ;
unsigned int V_249 ;
V_31 = F_169 ( sizeof( struct V_30 ) , V_250 ) ;
if ( ! V_31 )
return - V_251 ;
F_170 ( V_2 ) -> V_30 = V_31 ;
V_31 -> V_252 = F_171 ( F_18 ( V_2 ) * sizeof( struct V_11 ) ) ;
if ( ! V_31 -> V_252 )
return - V_251 ;
V_249 = F_172 ( F_18 ( V_2 ) ) ;
V_31 -> V_32 = F_169 ( V_249 , V_250 ) ;
if ( ! V_31 -> V_32 )
return - V_251 ;
for ( V_110 = 0 ; V_110 < F_18 ( V_2 ) ; V_110 ++ ) {
V_31 -> V_252 [ V_110 ] . V_42
= F_169 ( V_253 , V_250 ) ;
V_31 -> V_252 [ V_110 ] . V_43
= F_169 ( V_253 , V_250 ) ;
if ( ! V_31 -> V_252 [ V_110 ] . V_42
|| ! V_31 -> V_252 [ V_110 ] . V_43 )
return - V_251 ;
}
if ( V_2 -> V_16 > 1 ) {
V_31 -> V_254 = F_171 ( F_57 ( V_2 ) *
sizeof( struct V_255 ) ) ;
if ( ! V_31 -> V_254 )
return - V_251 ;
}
V_246 = F_133 ( V_245 -> V_256 ) >> 1 ;
V_249 = F_173 ( V_2 , V_257 ) ;
V_247 = F_174 ( V_2 , V_257 ) ;
V_248 = F_175 ( V_247 , V_249 , V_250 ) ;
if ( ! V_248 )
return - V_251 ;
V_31 -> V_126 = & V_258 ;
V_31 -> V_226 = F_133 ( V_245 -> V_259 ) ;
V_31 -> V_228 = V_246 << V_2 -> V_28 ;
V_31 -> V_45 = F_176 ( V_64 -> V_260 ) ;
V_31 -> V_227 = V_248 ;
V_31 -> V_249 = V_249 ;
V_31 -> V_33 = 0 ;
V_31 -> V_261 = V_243 ;
V_31 -> V_262 = F_176 ( V_2 -> V_64 -> V_262 ) ;
V_31 -> V_263 = V_264 . V_265 ;
F_177 ( & V_31 -> V_51 ) ;
return 0 ;
}
static int F_178 ( struct V_1 * V_2 )
{
struct V_266 * V_267 = F_170 ( V_2 ) ;
struct V_76 * V_77 ;
unsigned int V_249 , V_268 ;
V_77 = F_169 ( sizeof( struct V_76 ) , V_250 ) ;
if ( ! V_77 )
return - V_251 ;
F_170 ( V_2 ) -> V_269 = V_77 ;
V_249 = F_172 ( F_18 ( V_2 ) ) ;
V_77 -> V_78 = F_88 ( V_249 , V_250 ) ;
if ( ! V_77 -> V_78 )
return - V_251 ;
V_268 = F_172 ( F_57 ( V_2 ) ) ;
V_77 -> V_94 = F_88 ( V_268 , V_250 ) ;
if ( ! V_77 -> V_94 )
return - V_251 ;
memset ( V_77 -> V_78 , 0xff , V_249 ) ;
memset ( V_77 -> V_94 , 0xff , V_268 ) ;
V_77 -> V_270 =
( unsigned int ) F_179 ( V_2 , V_267 -> V_271 ) ;
V_77 -> V_272 = 0 ;
V_77 -> V_273 = 0 ;
F_180 ( & V_77 -> V_91 ) ;
return 0 ;
}
static int F_181 ( struct V_1 * V_2 )
{
struct V_54 * V_274 ;
int V_60 ;
V_274 = F_169 ( sizeof( * V_274 ) * V_98 , V_250 ) ;
if ( ! V_274 )
return - V_251 ;
F_170 ( V_2 ) -> V_275 = V_274 ;
for ( V_60 = 0 ; V_60 < V_98 ; V_60 ++ ) {
F_177 ( & V_274 [ V_60 ] . V_182 ) ;
V_274 [ V_60 ] . V_56 = F_169 ( V_70 , V_250 ) ;
if ( ! V_274 [ V_60 ] . V_56 )
return - V_251 ;
V_274 [ V_60 ] . V_4 = V_19 ;
V_274 [ V_60 ] . V_57 = 0 ;
}
return F_139 ( V_2 ) ;
}
static void F_182 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_26 ( V_2 ) ;
struct V_54 * V_55 = F_42 ( V_2 , V_63 ) ;
struct V_73 * V_53 = V_55 -> V_56 ;
unsigned int V_110 ;
for ( V_110 = 0 ; V_110 < F_18 ( V_2 ) ; V_110 ++ ) {
struct V_11 * V_35 = & V_31 -> V_252 [ V_110 ] ;
struct V_237 * V_276 ;
struct V_277 V_278 ;
struct V_72 * V_72 ;
int V_60 ;
F_3 ( & V_55 -> V_182 ) ;
for ( V_60 = 0 ; V_60 < F_148 ( V_53 ) ; V_60 ++ ) {
if ( F_133 ( F_149 ( V_53 , V_60 ) ) == V_110 ) {
V_278 = F_164 ( V_53 , V_60 ) ;
F_16 ( & V_55 -> V_182 ) ;
goto V_92;
}
}
F_16 ( & V_55 -> V_182 ) ;
V_72 = F_151 ( V_2 , V_110 ) ;
V_276 = (struct V_237 * ) F_50 ( V_72 ) ;
V_278 = V_276 -> V_205 [ F_161 ( V_31 , V_110 ) ] ;
F_52 ( V_72 , 1 ) ;
V_92:
F_183 ( V_2 , V_110 , & V_278 ) ;
F_184 ( V_35 , & V_278 ) ;
if ( V_2 -> V_16 > 1 ) {
struct V_255 * V_279 = F_38 ( V_2 , V_110 ) ;
V_279 -> V_18 += V_35 -> V_18 ;
}
}
}
static void F_185 ( struct V_1 * V_2 )
{
unsigned int V_110 ;
int type ;
for ( V_110 = 0 ; V_110 < F_18 ( V_2 ) ; V_110 ++ ) {
struct V_11 * V_12 = F_9 ( V_2 , V_110 ) ;
if ( ! V_12 -> V_18 )
F_186 ( V_2 , V_110 ) ;
}
for ( type = V_62 ; type <= V_178 ; type ++ ) {
struct V_54 * V_280 = F_42 ( V_2 , type ) ;
F_71 ( V_2 , V_280 -> V_4 ) ;
}
}
static void F_187 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
struct V_76 * V_77 = F_54 ( V_2 ) ;
unsigned int V_4 = 0 , V_38 = 0 , V_23 = F_18 ( V_2 ) ;
unsigned short V_18 ;
while ( 1 ) {
V_4 = F_188 ( V_77 , V_23 , V_38 ) ;
if ( V_4 >= V_23 )
break;
V_38 = V_4 + 1 ;
V_18 = F_12 ( V_2 , V_4 , 0 ) ;
if ( V_18 >= V_2 -> V_22 || ! V_18 )
continue;
F_3 ( & V_7 -> V_20 ) ;
F_5 ( V_2 , V_4 , V_10 ) ;
F_16 ( & V_7 -> V_20 ) ;
}
}
static int F_189 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
unsigned int V_249 = F_172 ( F_57 ( V_2 ) ) ;
V_7 -> V_17 = F_169 ( V_249 , V_250 ) ;
if ( ! V_7 -> V_17 )
return - V_251 ;
return 0 ;
}
static int F_190 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
unsigned int V_249 , V_60 ;
V_7 = F_169 ( sizeof( struct V_6 ) , V_250 ) ;
if ( ! V_7 )
return - V_251 ;
F_170 ( V_2 ) -> V_281 = V_7 ;
F_177 ( & V_7 -> V_20 ) ;
V_249 = F_172 ( F_18 ( V_2 ) ) ;
for ( V_60 = 0 ; V_60 < V_282 ; V_60 ++ ) {
V_7 -> V_8 [ V_60 ] = F_169 ( V_249 , V_250 ) ;
if ( ! V_7 -> V_8 [ V_60 ] )
return - V_251 ;
}
F_187 ( V_2 ) ;
return F_189 ( V_2 ) ;
}
static void F_191 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_26 ( V_2 ) ;
unsigned int V_4 ;
F_3 ( & V_31 -> V_51 ) ;
V_31 -> V_283 = V_284 ;
for ( V_4 = 0 ; V_4 < F_18 ( V_2 ) ; V_4 += V_2 -> V_16 ) {
unsigned int V_60 ;
unsigned long long V_40 = 0 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_16 ; V_60 ++ )
V_40 += F_9 ( V_2 , V_4 + V_60 ) -> V_40 ;
V_40 = F_192 ( V_40 , V_2 -> V_16 ) ;
if ( V_31 -> V_283 > V_40 )
V_31 -> V_283 = V_40 ;
}
V_31 -> V_41 = F_33 ( V_2 ) ;
F_16 ( & V_31 -> V_51 ) ;
}
int F_193 ( struct V_1 * V_2 )
{
struct V_244 * V_245 = F_168 ( V_2 ) ;
struct V_195 * V_64 = F_131 ( V_2 ) ;
struct V_266 * V_267 ;
int V_129 ;
V_267 = F_169 ( sizeof( struct V_266 ) , V_250 ) ;
if ( ! V_267 )
return - V_251 ;
V_2 -> V_267 = V_267 ;
F_194 ( & V_267 -> V_285 ) ;
F_195 ( & V_267 -> V_286 ) ;
V_267 -> V_287 = F_133 ( V_245 -> V_288 ) ;
V_267 -> V_271 = F_133 ( V_245 -> V_271 ) ;
V_267 -> V_124 = F_133 ( V_245 -> V_124 ) ;
V_267 -> V_289 = F_133 ( V_64 -> V_290 ) ;
V_267 -> V_291 = F_133 ( V_64 -> V_292 ) ;
V_267 -> V_293 = F_133 ( V_245 -> V_294 ) ;
V_267 -> V_295 = F_133 ( V_245 -> V_295 ) ;
V_129 = F_167 ( V_2 ) ;
if ( V_129 )
return V_129 ;
V_129 = F_178 ( V_2 ) ;
if ( V_129 )
return V_129 ;
V_129 = F_181 ( V_2 ) ;
if ( V_129 )
return V_129 ;
F_182 ( V_2 ) ;
F_185 ( V_2 ) ;
V_129 = F_190 ( V_2 ) ;
if ( V_129 )
return V_129 ;
F_191 ( V_2 ) ;
return 0 ;
}
static void F_196 ( struct V_1 * V_2 ,
enum V_5 V_5 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
F_3 ( & V_7 -> V_20 ) ;
F_85 ( V_7 -> V_8 [ V_5 ] ) ;
V_7 -> V_9 [ V_5 ] = 0 ;
F_16 ( & V_7 -> V_20 ) ;
}
static void F_197 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
F_85 ( V_7 -> V_17 ) ;
}
static void F_198 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
int V_60 ;
if ( ! V_7 )
return;
for ( V_60 = 0 ; V_60 < V_282 ; V_60 ++ )
F_196 ( V_2 , V_60 ) ;
F_197 ( V_2 ) ;
F_170 ( V_2 ) -> V_281 = NULL ;
F_85 ( V_7 ) ;
}
static void F_199 ( struct V_1 * V_2 )
{
struct V_54 * V_274 = F_170 ( V_2 ) -> V_275 ;
int V_60 ;
if ( ! V_274 )
return;
F_170 ( V_2 ) -> V_275 = NULL ;
for ( V_60 = 0 ; V_60 < V_98 ; V_60 ++ )
F_85 ( V_274 [ V_60 ] . V_56 ) ;
F_85 ( V_274 ) ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = F_170 ( V_2 ) -> V_269 ;
if ( ! V_77 )
return;
F_170 ( V_2 ) -> V_269 = NULL ;
F_85 ( V_77 -> V_78 ) ;
F_85 ( V_77 -> V_94 ) ;
F_85 ( V_77 ) ;
}
static void F_201 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_26 ( V_2 ) ;
unsigned int V_110 ;
if ( ! V_31 )
return;
if ( V_31 -> V_252 ) {
for ( V_110 = 0 ; V_110 < F_18 ( V_2 ) ; V_110 ++ ) {
F_85 ( V_31 -> V_252 [ V_110 ] . V_42 ) ;
F_85 ( V_31 -> V_252 [ V_110 ] . V_43 ) ;
}
}
F_202 ( V_31 -> V_252 ) ;
F_202 ( V_31 -> V_254 ) ;
F_85 ( V_31 -> V_32 ) ;
F_170 ( V_2 ) -> V_30 = NULL ;
F_85 ( V_31 -> V_227 ) ;
F_85 ( V_31 ) ;
}
void F_203 ( struct V_1 * V_2 )
{
struct V_266 * V_267 = F_170 ( V_2 ) ;
F_198 ( V_2 ) ;
F_199 ( V_2 ) ;
F_200 ( V_2 ) ;
F_201 ( V_2 ) ;
V_2 -> V_267 = NULL ;
F_85 ( V_267 ) ;
}
