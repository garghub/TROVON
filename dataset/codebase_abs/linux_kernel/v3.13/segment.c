void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 , 0 ) ) {
F_3 ( & V_2 -> V_3 ) ;
F_4 ( V_2 ) ;
}
}
void F_5 ( struct V_1 * V_2 )
{
if ( F_6 ( V_2 , V_4 ) ||
F_7 ( V_2 ) )
F_8 ( V_2 -> V_5 , true ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned int V_6 ,
enum V_7 V_7 )
{
struct V_8 * V_9 = F_10 ( V_2 ) ;
if ( F_11 ( V_2 , V_6 ) )
return;
if ( ! F_12 ( V_6 , V_9 -> V_10 [ V_7 ] ) )
V_9 -> V_11 [ V_7 ] ++ ;
if ( V_7 == V_12 ) {
struct V_13 * V_14 = F_13 ( V_2 , V_6 ) ;
enum V_7 V_15 = V_14 -> type ;
if ( ! F_12 ( V_6 , V_9 -> V_10 [ V_15 ] ) )
V_9 -> V_11 [ V_15 ] ++ ;
}
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_6 ,
enum V_7 V_7 )
{
struct V_8 * V_9 = F_10 ( V_2 ) ;
if ( F_15 ( V_6 , V_9 -> V_10 [ V_7 ] ) )
V_9 -> V_11 [ V_7 ] -- ;
if ( V_7 == V_12 ) {
struct V_13 * V_14 = F_13 ( V_2 , V_6 ) ;
enum V_7 V_15 = V_14 -> type ;
if ( F_15 ( V_6 , V_9 -> V_10 [ V_15 ] ) )
V_9 -> V_11 [ V_15 ] -- ;
if ( F_16 ( V_2 , V_6 , V_2 -> V_16 ) == 0 )
F_17 ( F_18 ( V_2 , V_6 ) ,
V_9 -> V_17 ) ;
}
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_6 )
{
struct V_8 * V_9 = F_10 ( V_2 ) ;
unsigned short V_18 ;
if ( V_6 == V_19 || F_11 ( V_2 , V_6 ) )
return;
F_3 ( & V_9 -> V_20 ) ;
V_18 = F_16 ( V_2 , V_6 , 0 ) ;
if ( V_18 == 0 ) {
F_9 ( V_2 , V_6 , V_21 ) ;
F_14 ( V_2 , V_6 , V_12 ) ;
} else if ( V_18 < V_2 -> V_22 ) {
F_9 ( V_2 , V_6 , V_12 ) ;
} else {
F_14 ( V_2 , V_6 , V_12 ) ;
}
F_20 ( & V_9 -> V_20 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_10 ( V_2 ) ;
unsigned int V_6 = - 1 ;
unsigned int V_23 = F_22 ( V_2 ) ;
F_3 ( & V_9 -> V_20 ) ;
while ( 1 ) {
V_6 = F_23 ( V_9 -> V_10 [ V_21 ] , V_23 ,
V_6 + 1 ) ;
if ( V_6 >= V_23 )
break;
F_24 ( V_2 , V_6 ) ;
}
F_20 ( & V_9 -> V_20 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_10 ( V_2 ) ;
unsigned long * V_24 = V_9 -> V_10 [ V_21 ] ;
unsigned int V_23 = F_22 ( V_2 ) ;
unsigned int V_25 = 0 , V_26 = - 1 ;
F_3 ( & V_9 -> V_20 ) ;
while ( 1 ) {
int V_27 ;
V_25 = F_23 ( V_24 , V_23 , V_26 + 1 ) ;
if ( V_25 >= V_23 )
break;
V_26 = F_26 ( V_24 , V_23 , V_25 + 1 ) ;
for ( V_27 = V_25 ; V_27 < V_26 ; V_27 ++ )
F_17 ( V_27 , V_24 ) ;
V_9 -> V_11 [ V_21 ] -= V_26 - V_25 ;
if ( ! F_27 ( V_2 , V_28 ) )
continue;
F_28 ( V_2 -> V_5 -> V_29 ,
F_29 ( V_2 , V_25 ) <<
V_2 -> V_30 ,
( 1 << ( V_2 -> V_30 +
V_2 -> V_31 ) ) * ( V_26 - V_25 ) ,
V_32 , 0 ) ;
}
F_20 ( & V_9 -> V_20 ) ;
}
static void F_30 ( struct V_1 * V_2 , unsigned int V_6 )
{
struct V_33 * V_34 = F_31 ( V_2 ) ;
if ( ! F_32 ( V_6 , V_34 -> V_35 ) )
V_34 -> V_36 ++ ;
}
static void F_33 ( struct V_1 * V_2 , int type ,
unsigned int V_6 , int V_37 )
{
struct V_13 * V_38 = F_13 ( V_2 , V_6 ) ;
V_38 -> type = type ;
if ( V_37 )
F_30 ( V_2 , V_6 ) ;
}
static void F_34 ( struct V_1 * V_2 , T_1 V_39 , int V_40 )
{
struct V_13 * V_38 ;
unsigned int V_6 , V_41 ;
long int V_42 ;
V_6 = F_35 ( V_2 , V_39 ) ;
V_38 = F_13 ( V_2 , V_6 ) ;
V_42 = V_38 -> V_18 + V_40 ;
V_41 = F_36 ( V_2 , V_39 ) & ( V_2 -> V_22 - 1 ) ;
F_37 ( ( V_42 >> (sizeof( unsigned short ) << 3 ) ||
( V_42 > V_2 -> V_22 ) ) ) ;
V_38 -> V_18 = V_42 ;
V_38 -> V_43 = F_38 ( V_2 ) ;
F_31 ( V_2 ) -> V_44 = V_38 -> V_43 ;
if ( V_40 > 0 ) {
if ( F_39 ( V_41 , V_38 -> V_45 ) )
F_40 () ;
} else {
if ( ! F_41 ( V_41 , V_38 -> V_45 ) )
F_40 () ;
}
if ( ! F_42 ( V_41 , V_38 -> V_46 ) )
V_38 -> V_47 += V_40 ;
F_30 ( V_2 , V_6 ) ;
F_31 ( V_2 ) -> V_48 += V_40 ;
if ( V_2 -> V_16 > 1 )
F_43 ( V_2 , V_6 ) -> V_18 += V_40 ;
}
static void F_44 ( struct V_1 * V_2 ,
T_1 V_49 , T_1 V_50 )
{
F_34 ( V_2 , V_50 , 1 ) ;
if ( F_35 ( V_2 , V_49 ) != V_19 )
F_34 ( V_2 , V_49 , - 1 ) ;
}
void F_45 ( struct V_1 * V_2 , T_1 V_51 )
{
unsigned int V_6 = F_35 ( V_2 , V_51 ) ;
struct V_33 * V_34 = F_31 ( V_2 ) ;
F_37 ( V_51 == V_52 ) ;
if ( V_51 == V_53 )
return;
F_3 ( & V_34 -> V_54 ) ;
F_34 ( V_2 , V_51 , - 1 ) ;
F_19 ( V_2 , V_6 ) ;
F_20 ( & V_34 -> V_54 ) ;
}
static void F_46 ( struct V_1 * V_2 , int type ,
struct V_55 * V_56 )
{
struct V_57 * V_58 = F_47 ( V_2 , type ) ;
void * V_51 = V_58 -> V_59 ;
V_51 += V_58 -> V_60 * sizeof( struct V_55 ) ;
memcpy ( V_51 , V_56 , sizeof( struct V_55 ) ) ;
}
int F_48 ( struct V_1 * V_2 )
{
int V_61 = 0 ;
int V_27 , V_62 ;
for ( V_27 = V_63 ; V_27 <= V_64 ; V_27 ++ ) {
if ( V_2 -> V_65 -> V_66 [ V_27 ] == V_67 )
V_61 += V_2 -> V_22 ;
else
V_61 += F_49 ( V_2 , V_27 ) ;
}
V_62 = ( V_68 - 2 * V_69 -
V_70 ) / V_71 ;
if ( V_61 <= V_62 )
return 1 ;
else if ( ( V_61 - V_62 ) <=
( V_68 - V_70 ) / V_71 )
return 2 ;
return 3 ;
}
struct V_72 * F_50 ( struct V_1 * V_2 , unsigned int V_6 )
{
return F_51 ( V_2 , F_52 ( V_2 , V_6 ) ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_73 * V_59 , T_1 V_74 )
{
struct V_72 * V_72 = F_54 ( V_2 , V_74 ) ;
void * V_75 = F_55 ( V_72 ) ;
memcpy ( V_75 , V_59 , V_68 ) ;
F_56 ( V_72 ) ;
F_57 ( V_72 , 1 ) ;
}
static int F_58 ( struct V_1 * V_2 , int type )
{
struct V_57 * V_58 = F_47 ( V_2 , type ) ;
unsigned int V_6 = V_58 -> V_6 + 1 ;
struct V_76 * V_77 = F_59 ( V_2 ) ;
if ( V_6 < F_22 ( V_2 ) && V_6 % V_2 -> V_16 )
return ! F_60 ( V_6 , V_77 -> V_78 ) ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 ,
unsigned int * V_79 , bool V_80 , int V_81 )
{
struct V_76 * V_77 = F_59 ( V_2 ) ;
unsigned int V_6 , V_82 , V_83 ;
unsigned int V_84 = F_62 ( V_2 ) / V_2 -> V_85 ;
unsigned int V_86 = * V_79 / V_2 -> V_16 ;
unsigned int V_87 = F_63 ( V_2 , * V_79 ) ;
unsigned int V_88 = V_86 ;
bool V_89 = true ;
int V_90 = 0 ;
int V_27 ;
F_64 ( & V_77 -> V_91 ) ;
if ( ! V_80 && ( ( * V_79 + 1 ) % V_2 -> V_16 ) ) {
V_6 = F_26 ( V_77 -> V_78 ,
F_22 ( V_2 ) , * V_79 + 1 ) ;
if ( V_6 - * V_79 < V_2 -> V_16 -
( * V_79 % V_2 -> V_16 ) )
goto V_92;
}
V_93:
V_82 = F_26 ( V_77 -> V_94 , F_62 ( V_2 ) , V_86 ) ;
if ( V_82 >= F_62 ( V_2 ) ) {
if ( V_81 == V_95 ) {
V_82 = F_26 ( V_77 -> V_94 ,
F_62 ( V_2 ) , 0 ) ;
F_37 ( V_82 >= F_62 ( V_2 ) ) ;
} else {
V_90 = 1 ;
V_88 = V_86 - 1 ;
}
}
if ( V_90 == 0 )
goto V_96;
while ( F_60 ( V_88 , V_77 -> V_94 ) ) {
if ( V_88 > 0 ) {
V_88 -- ;
continue;
}
V_88 = F_26 ( V_77 -> V_94 ,
F_62 ( V_2 ) , 0 ) ;
F_37 ( V_88 >= F_62 ( V_2 ) ) ;
break;
}
V_82 = V_88 ;
V_96:
V_86 = V_82 ;
V_6 = V_82 * V_2 -> V_16 ;
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
for ( V_27 = 0 ; V_27 < V_98 ; V_27 ++ )
if ( F_47 ( V_2 , V_27 ) -> V_99 == V_83 )
break;
if ( V_27 < V_98 ) {
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
F_37 ( F_60 ( V_6 , V_77 -> V_78 ) ) ;
F_65 ( V_2 , V_6 ) ;
* V_79 = V_6 ;
F_66 ( & V_77 -> V_91 ) ;
}
static void F_67 ( struct V_1 * V_2 , int type , int V_37 )
{
struct V_57 * V_58 = F_47 ( V_2 , type ) ;
struct V_100 * V_101 ;
V_58 -> V_6 = V_58 -> V_102 ;
V_58 -> V_99 = F_63 ( V_2 , V_58 -> V_6 ) ;
V_58 -> V_60 = 0 ;
V_58 -> V_102 = V_19 ;
V_101 = & ( V_58 -> V_59 -> V_103 ) ;
memset ( V_101 , 0 , sizeof( struct V_100 ) ) ;
if ( F_68 ( type ) )
F_69 ( V_101 , V_104 ) ;
if ( F_70 ( type ) )
F_69 ( V_101 , V_105 ) ;
F_33 ( V_2 , type , V_58 -> V_6 , V_37 ) ;
}
static void F_71 ( struct V_1 * V_2 , int type , bool V_80 )
{
struct V_57 * V_58 = F_47 ( V_2 , type ) ;
unsigned int V_6 = V_58 -> V_6 ;
int V_81 = V_97 ;
F_53 ( V_2 , V_58 -> V_59 ,
F_52 ( V_2 , V_6 ) ) ;
if ( type == V_106 || type == V_64 )
V_81 = V_95 ;
if ( F_27 ( V_2 , V_107 ) )
V_81 = V_95 ;
F_61 ( V_2 , & V_6 , V_80 , V_81 ) ;
V_58 -> V_102 = V_6 ;
F_67 ( V_2 , type , 1 ) ;
V_58 -> V_66 = V_108 ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_57 * V_109 , T_1 V_25 )
{
struct V_13 * V_38 = F_13 ( V_2 , V_109 -> V_6 ) ;
T_1 V_110 ;
for ( V_110 = V_25 ; V_110 < V_2 -> V_22 ; V_110 ++ ) {
if ( ! F_42 ( V_110 , V_38 -> V_46 )
&& ! F_42 ( V_110 , V_38 -> V_45 ) )
break;
}
V_109 -> V_60 = V_110 ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_57 * V_109 )
{
if ( V_109 -> V_66 == V_67 )
F_72 ( V_2 , V_109 , V_109 -> V_60 + 1 ) ;
else
V_109 -> V_60 ++ ;
}
static void F_74 ( struct V_1 * V_2 , int type , bool V_111 )
{
struct V_8 * V_9 = F_10 ( V_2 ) ;
struct V_57 * V_58 = F_47 ( V_2 , type ) ;
unsigned int V_112 = V_58 -> V_102 ;
struct V_73 * V_113 ;
struct V_72 * V_114 ;
F_53 ( V_2 , V_58 -> V_59 ,
F_52 ( V_2 , V_58 -> V_6 ) ) ;
F_75 ( V_2 , V_112 ) ;
F_3 ( & V_9 -> V_20 ) ;
F_14 ( V_2 , V_112 , V_21 ) ;
F_14 ( V_2 , V_112 , V_12 ) ;
F_20 ( & V_9 -> V_20 ) ;
F_67 ( V_2 , type , 1 ) ;
V_58 -> V_66 = V_67 ;
F_72 ( V_2 , V_58 , 0 ) ;
if ( V_111 ) {
V_114 = F_50 ( V_2 , V_112 ) ;
V_113 = (struct V_73 * ) F_55 ( V_114 ) ;
memcpy ( V_58 -> V_59 , V_113 , V_115 ) ;
F_57 ( V_114 , 1 ) ;
}
}
static int F_76 ( struct V_1 * V_2 , int type )
{
struct V_57 * V_58 = F_47 ( V_2 , type ) ;
const struct V_116 * V_117 = F_10 ( V_2 ) -> V_117 ;
if ( F_70 ( type ) || ! F_2 ( V_2 , 0 ) )
return V_117 -> V_118 ( V_2 ,
& ( V_58 ) -> V_102 , V_119 , type , V_67 ) ;
for (; type >= V_63 ; type -- )
if ( V_117 -> V_118 ( V_2 , & ( V_58 ) -> V_102 ,
V_119 , type , V_67 ) )
return 1 ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 ,
int type , bool V_120 )
{
struct V_57 * V_58 = F_47 ( V_2 , type ) ;
if ( V_120 )
F_71 ( V_2 , type , true ) ;
else if ( type == V_121 )
F_71 ( V_2 , type , false ) ;
else if ( V_58 -> V_66 == V_108 && F_58 ( V_2 , type ) )
F_71 ( V_2 , type , false ) ;
else if ( F_78 ( V_2 ) && F_76 ( V_2 , type ) )
F_74 ( V_2 , type , true ) ;
else
F_71 ( V_2 , type , false ) ;
F_79 ( V_2 , V_58 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
unsigned int V_122 ;
int V_27 ;
for ( V_27 = V_63 ; V_27 <= V_64 ; V_27 ++ ) {
V_58 = F_47 ( V_2 , V_27 ) ;
V_122 = V_58 -> V_6 ;
F_31 ( V_2 ) -> V_123 -> V_124 ( V_2 , V_27 , true ) ;
F_19 ( V_2 , V_122 ) ;
}
}
static void F_81 ( struct V_125 * V_125 , int V_126 )
{
const int V_127 = F_60 ( V_128 , & V_125 -> V_129 ) ;
struct V_130 * V_131 = V_125 -> V_132 + V_125 -> V_133 - 1 ;
struct V_134 * V_135 = V_125 -> V_136 ;
do {
struct V_72 * V_72 = V_131 -> V_137 ;
if ( -- V_131 >= V_125 -> V_132 )
F_82 ( & V_131 -> V_137 -> V_138 ) ;
if ( ! V_127 ) {
F_83 ( V_72 ) ;
if ( V_72 -> V_139 )
F_84 ( V_140 , & V_72 -> V_139 -> V_138 ) ;
F_85 ( V_135 -> V_2 -> V_65 , V_141 ) ;
V_135 -> V_2 -> V_5 -> V_142 |= V_143 ;
}
F_86 ( V_72 ) ;
F_87 ( V_135 -> V_2 , V_144 ) ;
} while ( V_131 >= V_125 -> V_132 );
if ( V_135 -> V_145 )
F_88 ( V_135 -> V_146 ) ;
if ( ! F_89 ( V_135 -> V_2 , V_144 ) &&
! F_90 ( & V_135 -> V_2 -> V_147 . V_148 ) )
F_91 ( & V_135 -> V_2 -> V_147 ) ;
F_92 ( V_135 ) ;
F_93 ( V_125 ) ;
}
struct V_125 * F_94 ( struct V_149 * V_150 , int V_151 )
{
struct V_125 * V_125 ;
V_125 = F_95 ( V_152 , V_151 ) ;
V_125 -> V_153 = V_150 ;
V_125 -> V_136 = NULL ;
return V_125 ;
}
static void F_96 ( struct V_1 * V_2 ,
enum V_154 type , bool V_155 )
{
int V_156 = V_155 ? V_157 : V_158 ;
enum V_154 V_159 = type > V_160 ? V_160 : type ;
if ( type >= V_161 )
V_156 = V_162 ;
if ( V_159 == V_160 )
V_156 |= V_163 ;
if ( V_2 -> V_125 [ V_159 ] ) {
struct V_134 * V_135 = V_2 -> V_125 [ V_159 ] -> V_136 ;
V_135 -> V_2 = V_2 ;
V_2 -> V_125 [ V_159 ] -> V_164 = F_81 ;
F_97 ( V_2 -> V_5 , V_159 , V_155 , V_2 -> V_125 [ V_159 ] ) ;
if ( type == V_161 ) {
F_98 ( V_146 ) ;
V_135 -> V_145 = true ;
V_135 -> V_146 = & V_146 ;
F_99 ( V_156 , V_2 -> V_125 [ V_159 ] ) ;
F_100 ( & V_146 ) ;
} else {
V_135 -> V_145 = false ;
F_99 ( V_156 , V_2 -> V_125 [ V_159 ] ) ;
}
V_2 -> V_125 [ V_159 ] = NULL ;
}
}
void F_101 ( struct V_1 * V_2 , enum V_154 type , bool V_155 )
{
F_102 ( & V_2 -> V_165 ) ;
F_96 ( V_2 , type , V_155 ) ;
F_103 ( & V_2 -> V_165 ) ;
}
static void F_104 ( struct V_1 * V_2 , struct V_72 * V_72 ,
T_1 V_74 , enum V_154 type )
{
struct V_149 * V_150 = V_2 -> V_5 -> V_29 ;
int V_166 ;
F_105 ( V_2 , V_74 ) ;
F_102 ( & V_2 -> V_165 ) ;
F_106 ( V_2 , V_144 ) ;
if ( V_2 -> V_125 [ type ] && V_2 -> V_167 [ type ] != V_74 - 1 )
F_96 ( V_2 , type , false ) ;
V_168:
if ( V_2 -> V_125 [ type ] == NULL ) {
struct V_134 * V_169 ;
V_170:
V_169 = F_107 ( sizeof( struct V_134 ) , V_32 ) ;
if ( ! V_169 ) {
F_108 () ;
goto V_170;
}
V_166 = F_109 ( F_110 ( V_2 ) ) ;
V_2 -> V_125 [ type ] = F_94 ( V_150 , V_166 ) ;
V_2 -> V_125 [ type ] -> V_171 = F_111 ( V_2 , V_74 ) ;
V_2 -> V_125 [ type ] -> V_136 = V_169 ;
}
if ( F_112 ( V_2 -> V_125 [ type ] , V_72 , V_68 , 0 ) <
V_68 ) {
F_96 ( V_2 , type , false ) ;
goto V_168;
}
V_2 -> V_167 [ type ] = V_74 ;
F_103 ( & V_2 -> V_165 ) ;
F_113 ( V_72 , V_74 , type ) ;
}
void F_114 ( struct V_72 * V_72 ,
enum V_154 type , bool V_155 )
{
struct V_1 * V_2 = F_115 ( V_72 -> V_139 -> V_172 -> V_173 ) ;
if ( F_116 ( V_72 ) ) {
F_101 ( V_2 , type , V_155 ) ;
F_117 ( V_72 ) ;
}
}
static bool F_118 ( struct V_1 * V_2 , int type )
{
struct V_57 * V_58 = F_47 ( V_2 , type ) ;
if ( V_58 -> V_60 < V_2 -> V_22 )
return true ;
return false ;
}
static int F_119 ( struct V_72 * V_72 , enum V_154 V_174 )
{
if ( V_174 == V_175 )
return V_63 ;
else
return V_176 ;
}
static int F_120 ( struct V_72 * V_72 , enum V_154 V_174 )
{
if ( V_174 == V_175 ) {
struct V_177 * V_177 = V_72 -> V_139 -> V_172 ;
if ( F_121 ( V_177 -> V_178 ) )
return V_63 ;
else
return V_64 ;
} else {
if ( F_122 ( V_72 ) && ! F_123 ( V_72 ) )
return V_176 ;
else
return V_179 ;
}
}
static int F_124 ( struct V_72 * V_72 , enum V_154 V_174 )
{
if ( V_174 == V_175 ) {
struct V_177 * V_177 = V_72 -> V_139 -> V_172 ;
if ( F_121 ( V_177 -> V_178 ) )
return V_63 ;
else if ( F_125 ( V_72 ) || F_126 ( V_177 ) )
return V_64 ;
else
return V_106 ;
} else {
if ( F_122 ( V_72 ) )
return F_123 ( V_72 ) ? V_121 :
V_176 ;
else
return V_179 ;
}
}
static int F_127 ( struct V_72 * V_72 , enum V_154 V_174 )
{
struct V_1 * V_2 = F_115 ( V_72 -> V_139 -> V_172 -> V_173 ) ;
switch ( V_2 -> V_180 ) {
case 2 :
return F_119 ( V_72 , V_174 ) ;
case 4 :
return F_120 ( V_72 , V_174 ) ;
}
F_37 ( V_2 -> V_180 != V_98 ) ;
return F_124 ( V_72 , V_174 ) ;
}
static void F_128 ( struct V_1 * V_2 , struct V_72 * V_72 ,
T_1 V_49 , T_1 * V_50 ,
struct V_55 * V_56 , enum V_154 V_174 )
{
struct V_33 * V_34 = F_31 ( V_2 ) ;
struct V_57 * V_58 ;
unsigned int V_181 ;
int type ;
type = F_127 ( V_72 , V_174 ) ;
V_58 = F_47 ( V_2 , type ) ;
F_3 ( & V_58 -> V_182 ) ;
* V_50 = F_129 ( V_2 , V_58 ) ;
V_181 = V_58 -> V_6 ;
F_46 ( V_2 , type , V_56 ) ;
F_3 ( & V_34 -> V_54 ) ;
F_73 ( V_2 , V_58 ) ;
F_130 ( V_2 , V_58 ) ;
F_44 ( V_2 , V_49 , * V_50 ) ;
if ( ! F_118 ( V_2 , type ) )
V_34 -> V_123 -> V_124 ( V_2 , type , false ) ;
F_19 ( V_2 , V_181 ) ;
F_19 ( V_2 , F_35 ( V_2 , V_49 ) ) ;
F_20 ( & V_34 -> V_54 ) ;
if ( V_174 == V_183 )
F_131 ( V_72 , F_129 ( V_2 , V_58 ) ) ;
F_104 ( V_2 , V_72 , * V_50 , V_174 ) ;
F_20 ( & V_58 -> V_182 ) ;
}
void F_132 ( struct V_1 * V_2 , struct V_72 * V_72 )
{
F_133 ( V_72 ) ;
F_104 ( V_2 , V_72 , V_72 -> V_184 , V_160 ) ;
}
void F_134 ( struct V_1 * V_2 , struct V_72 * V_72 ,
unsigned int V_185 , T_1 V_49 , T_1 * V_50 )
{
struct V_55 V_56 ;
F_135 ( & V_56 , V_185 , 0 , 0 ) ;
F_128 ( V_2 , V_72 , V_49 , V_50 , & V_56 , V_183 ) ;
}
void F_136 ( struct V_177 * V_177 , struct V_72 * V_72 ,
struct V_186 * V_187 , T_1 V_49 ,
T_1 * V_50 )
{
struct V_1 * V_2 = F_115 ( V_177 -> V_173 ) ;
struct V_55 V_56 ;
struct V_188 V_189 ;
F_37 ( V_49 == V_52 ) ;
F_137 ( V_2 , V_187 -> V_185 , & V_189 ) ;
F_135 ( & V_56 , V_187 -> V_185 , V_187 -> V_190 , V_189 . V_191 ) ;
F_128 ( V_2 , V_72 , V_49 ,
V_50 , & V_56 , V_175 ) ;
}
void F_138 ( struct V_1 * V_2 , struct V_72 * V_72 ,
T_1 V_192 )
{
F_104 ( V_2 , V_72 , V_192 , V_175 ) ;
}
void F_139 ( struct V_1 * V_2 ,
struct V_72 * V_72 , struct V_55 * V_56 ,
T_1 V_49 , T_1 V_50 )
{
struct V_33 * V_34 = F_31 ( V_2 ) ;
struct V_57 * V_58 ;
unsigned int V_6 , V_181 ;
struct V_13 * V_38 ;
int type ;
V_6 = F_35 ( V_2 , V_50 ) ;
V_38 = F_13 ( V_2 , V_6 ) ;
type = V_38 -> type ;
if ( V_38 -> V_18 == 0 && ! F_11 ( V_2 , V_6 ) ) {
if ( V_49 == V_52 )
type = V_64 ;
else
type = V_106 ;
}
V_58 = F_47 ( V_2 , type ) ;
F_3 ( & V_58 -> V_182 ) ;
F_3 ( & V_34 -> V_54 ) ;
V_181 = V_58 -> V_6 ;
if ( V_6 != V_58 -> V_6 ) {
V_58 -> V_102 = V_6 ;
F_74 ( V_2 , type , true ) ;
}
V_58 -> V_60 = F_36 ( V_2 , V_50 ) &
( V_2 -> V_22 - 1 ) ;
F_46 ( V_2 , type , V_56 ) ;
F_44 ( V_2 , V_49 , V_50 ) ;
F_19 ( V_2 , V_181 ) ;
F_19 ( V_2 , F_35 ( V_2 , V_49 ) ) ;
F_20 ( & V_34 -> V_54 ) ;
F_20 ( & V_58 -> V_182 ) ;
}
void F_140 ( struct V_1 * V_2 ,
struct V_72 * V_72 , struct V_55 * V_56 ,
T_1 V_49 , T_1 V_50 )
{
struct V_33 * V_34 = F_31 ( V_2 ) ;
int type = V_121 ;
struct V_57 * V_58 ;
unsigned int V_6 , V_181 ;
T_1 V_193 = F_141 ( V_72 ) ;
unsigned int V_102 = F_35 ( V_2 , V_193 ) ;
V_58 = F_47 ( V_2 , type ) ;
F_3 ( & V_58 -> V_182 ) ;
F_3 ( & V_34 -> V_54 ) ;
V_6 = F_35 ( V_2 , V_50 ) ;
V_181 = V_58 -> V_6 ;
if ( V_6 != V_58 -> V_6 ) {
V_58 -> V_102 = V_6 ;
F_74 ( V_2 , type , true ) ;
}
V_58 -> V_60 = F_36 ( V_2 , V_50 ) &
( V_2 -> V_22 - 1 ) ;
F_46 ( V_2 , type , V_56 ) ;
if ( V_102 != V_6 ) {
V_58 -> V_102 = V_102 ;
F_74 ( V_2 , type , true ) ;
}
V_58 -> V_60 = F_36 ( V_2 , V_193 ) &
( V_2 -> V_22 - 1 ) ;
F_133 ( V_72 ) ;
F_104 ( V_2 , V_72 , V_50 , V_183 ) ;
F_101 ( V_2 , V_183 , true ) ;
F_44 ( V_2 , V_49 , V_50 ) ;
F_19 ( V_2 , V_181 ) ;
F_19 ( V_2 , F_35 ( V_2 , V_49 ) ) ;
F_20 ( & V_34 -> V_54 ) ;
F_20 ( & V_58 -> V_182 ) ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_194 * V_65 = F_143 ( V_2 ) ;
struct V_57 * V_195 ;
unsigned char * V_75 ;
struct V_72 * V_72 ;
T_1 V_25 ;
int V_27 , V_196 , V_41 ;
V_25 = F_144 ( V_2 ) ;
V_72 = F_51 ( V_2 , V_25 ++ ) ;
V_75 = ( unsigned char * ) F_55 ( V_72 ) ;
V_195 = F_47 ( V_2 , V_63 ) ;
memcpy ( & V_195 -> V_59 -> V_197 , V_75 , V_69 ) ;
V_195 = F_47 ( V_2 , V_64 ) ;
memcpy ( & V_195 -> V_59 -> V_198 , V_75 + V_69 ,
V_69 ) ;
V_41 = 2 * V_69 ;
for ( V_27 = V_63 ; V_27 <= V_64 ; V_27 ++ ) {
unsigned short V_199 ;
unsigned int V_6 ;
V_195 = F_47 ( V_2 , V_27 ) ;
V_6 = F_145 ( V_65 -> V_200 [ V_27 ] ) ;
V_199 = F_146 ( V_65 -> V_201 [ V_27 ] ) ;
V_195 -> V_102 = V_6 ;
F_67 ( V_2 , V_27 , 0 ) ;
V_195 -> V_66 = V_65 -> V_66 [ V_27 ] ;
V_195 -> V_60 = V_199 ;
if ( V_195 -> V_66 == V_67 )
V_199 = V_2 -> V_22 ;
for ( V_196 = 0 ; V_196 < V_199 ; V_196 ++ ) {
struct V_55 * V_202 ;
V_202 = (struct V_55 * ) ( V_75 + V_41 ) ;
V_195 -> V_59 -> V_203 [ V_196 ] = * V_202 ;
V_41 += V_71 ;
if ( V_41 + V_71 <= V_68 -
V_70 )
continue;
F_57 ( V_72 , 1 ) ;
V_72 = NULL ;
V_72 = F_51 ( V_2 , V_25 ++ ) ;
V_75 = ( unsigned char * ) F_55 ( V_72 ) ;
V_41 = 0 ;
}
}
F_57 ( V_72 , 1 ) ;
return 0 ;
}
static int F_147 ( struct V_1 * V_2 , int type )
{
struct V_194 * V_65 = F_143 ( V_2 ) ;
struct V_73 * V_56 ;
struct V_57 * V_58 ;
struct V_72 * V_204 ;
unsigned short V_199 ;
unsigned int V_6 = 0 ;
T_1 V_74 = 0 ;
if ( F_68 ( type ) ) {
V_6 = F_145 ( V_65 -> V_200 [ type ] ) ;
V_199 = F_146 ( V_65 -> V_201 [ type -
V_63 ] ) ;
if ( F_148 ( V_65 , V_205 ) )
V_74 = F_149 ( V_2 , V_98 , type ) ;
else
V_74 = F_149 ( V_2 , V_206 , type ) ;
} else {
V_6 = F_145 ( V_65 -> V_207 [ type -
V_176 ] ) ;
V_199 = F_146 ( V_65 -> V_208 [ type -
V_176 ] ) ;
if ( F_148 ( V_65 , V_205 ) )
V_74 = F_149 ( V_2 , V_209 ,
type - V_176 ) ;
else
V_74 = F_52 ( V_2 , V_6 ) ;
}
V_204 = F_51 ( V_2 , V_74 ) ;
V_56 = (struct V_73 * ) F_55 ( V_204 ) ;
if ( F_70 ( type ) ) {
if ( F_148 ( V_65 , V_205 ) ) {
struct V_55 * V_210 = & V_56 -> V_203 [ 0 ] ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_22 ; V_27 ++ , V_210 ++ ) {
V_210 -> V_191 = 0 ;
V_210 -> V_190 = 0 ;
}
} else {
if ( F_150 ( V_2 , V_6 , V_56 ) ) {
F_57 ( V_204 , 1 ) ;
return - V_211 ;
}
}
}
V_58 = F_47 ( V_2 , type ) ;
F_3 ( & V_58 -> V_182 ) ;
memcpy ( V_58 -> V_59 , V_56 , V_68 ) ;
V_58 -> V_102 = V_6 ;
F_67 ( V_2 , type , 0 ) ;
V_58 -> V_66 = V_65 -> V_66 [ type ] ;
V_58 -> V_60 = V_199 ;
F_20 ( & V_58 -> V_182 ) ;
F_57 ( V_204 , 1 ) ;
return 0 ;
}
static int F_151 ( struct V_1 * V_2 )
{
int type = V_63 ;
if ( F_148 ( F_143 ( V_2 ) , V_212 ) ) {
if ( F_142 ( V_2 ) )
return - V_211 ;
type = V_176 ;
}
for (; type <= V_179 ; type ++ )
if ( F_147 ( V_2 , type ) )
return - V_211 ;
return 0 ;
}
static void F_152 ( struct V_1 * V_2 , T_1 V_39 )
{
struct V_72 * V_72 ;
unsigned char * V_75 ;
struct V_55 * V_213 ;
struct V_57 * V_195 ;
int V_214 = 0 ;
int V_27 , V_196 ;
V_72 = F_54 ( V_2 , V_39 ++ ) ;
V_75 = ( unsigned char * ) F_55 ( V_72 ) ;
V_195 = F_47 ( V_2 , V_63 ) ;
memcpy ( V_75 , & V_195 -> V_59 -> V_197 , V_69 ) ;
V_214 += V_69 ;
V_195 = F_47 ( V_2 , V_64 ) ;
memcpy ( V_75 + V_214 , & V_195 -> V_59 -> V_198 ,
V_69 ) ;
V_214 += V_69 ;
for ( V_27 = V_63 ; V_27 <= V_64 ; V_27 ++ ) {
unsigned short V_215 ;
V_195 = F_47 ( V_2 , V_27 ) ;
if ( V_2 -> V_65 -> V_66 [ V_27 ] == V_67 )
V_215 = V_2 -> V_22 ;
else
V_215 = F_49 ( V_2 , V_27 ) ;
for ( V_196 = 0 ; V_196 < V_215 ; V_196 ++ ) {
if ( ! V_72 ) {
V_72 = F_54 ( V_2 , V_39 ++ ) ;
V_75 = ( unsigned char * ) F_55 ( V_72 ) ;
V_214 = 0 ;
}
V_213 = (struct V_55 * ) ( V_75 + V_214 ) ;
* V_213 = V_195 -> V_59 -> V_203 [ V_196 ] ;
V_214 += V_71 ;
if ( V_214 + V_71 <= V_68 -
V_70 )
continue;
F_56 ( V_72 ) ;
F_57 ( V_72 , 1 ) ;
V_72 = NULL ;
}
}
if ( V_72 ) {
F_56 ( V_72 ) ;
F_57 ( V_72 , 1 ) ;
}
}
static void F_153 ( struct V_1 * V_2 ,
T_1 V_39 , int type )
{
int V_27 , V_26 ;
if ( F_68 ( type ) )
V_26 = type + V_206 ;
else
V_26 = type + V_209 ;
for ( V_27 = type ; V_27 < V_26 ; V_27 ++ ) {
struct V_57 * V_56 = F_47 ( V_2 , V_27 ) ;
F_3 ( & V_56 -> V_182 ) ;
F_53 ( V_2 , V_56 -> V_59 , V_39 + ( V_27 - type ) ) ;
F_20 ( & V_56 -> V_182 ) ;
}
}
void F_154 ( struct V_1 * V_2 , T_1 V_216 )
{
if ( F_148 ( F_143 ( V_2 ) , V_212 ) )
F_152 ( V_2 , V_216 ) ;
else
F_153 ( V_2 , V_216 , V_63 ) ;
}
void F_155 ( struct V_1 * V_2 , T_1 V_216 )
{
if ( F_148 ( F_143 ( V_2 ) , V_205 ) )
F_153 ( V_2 , V_216 , V_176 ) ;
}
int F_156 ( struct V_73 * V_56 , int type ,
unsigned int V_217 , int V_218 )
{
int V_27 ;
if ( type == V_219 ) {
for ( V_27 = 0 ; V_27 < F_157 ( V_56 ) ; V_27 ++ ) {
if ( F_145 ( F_158 ( V_56 , V_27 ) ) == V_217 )
return V_27 ;
}
if ( V_218 && F_157 ( V_56 ) < V_220 )
return F_159 ( V_56 , 1 ) ;
} else if ( type == V_221 ) {
for ( V_27 = 0 ; V_27 < F_160 ( V_56 ) ; V_27 ++ )
if ( F_145 ( F_161 ( V_56 , V_27 ) ) == V_217 )
return V_27 ;
if ( V_218 && F_160 ( V_56 ) < V_222 )
return F_162 ( V_56 , 1 ) ;
}
return - 1 ;
}
static struct V_72 * F_163 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
struct V_33 * V_34 = F_31 ( V_2 ) ;
unsigned int V_41 = F_164 ( V_34 , V_6 ) ;
T_1 V_74 = V_34 -> V_223 + V_41 ;
F_165 ( V_2 , V_6 ) ;
if ( F_42 ( V_41 , V_34 -> V_224 ) )
V_74 += V_34 -> V_225 ;
return F_51 ( V_2 , V_74 ) ;
}
static struct V_72 * F_166 ( struct V_1 * V_2 ,
unsigned int V_25 )
{
struct V_33 * V_34 = F_31 ( V_2 ) ;
struct V_72 * V_226 , * V_227 ;
T_2 V_228 , V_229 ;
void * V_230 , * V_231 ;
V_228 = F_167 ( V_2 , V_25 ) ;
V_229 = F_168 ( V_2 , V_228 ) ;
V_226 = F_51 ( V_2 , V_228 ) ;
V_227 = F_54 ( V_2 , V_229 ) ;
F_37 ( F_169 ( V_226 ) ) ;
V_230 = F_55 ( V_226 ) ;
V_231 = F_55 ( V_227 ) ;
memcpy ( V_231 , V_230 , V_68 ) ;
F_56 ( V_227 ) ;
F_57 ( V_226 , 1 ) ;
F_170 ( V_34 , V_25 ) ;
return V_227 ;
}
static bool F_171 ( struct V_1 * V_2 )
{
struct V_57 * V_58 = F_47 ( V_2 , V_64 ) ;
struct V_73 * V_56 = V_58 -> V_59 ;
int V_27 ;
if ( F_160 ( V_56 ) >= V_222 ) {
for ( V_27 = F_160 ( V_56 ) - 1 ; V_27 >= 0 ; V_27 -- ) {
unsigned int V_6 ;
V_6 = F_145 ( F_161 ( V_56 , V_27 ) ) ;
F_30 ( V_2 , V_6 ) ;
}
F_162 ( V_56 , - F_160 ( V_56 ) ) ;
return true ;
}
return false ;
}
void F_172 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_31 ( V_2 ) ;
unsigned long * V_232 = V_34 -> V_35 ;
struct V_57 * V_58 = F_47 ( V_2 , V_64 ) ;
struct V_73 * V_56 = V_58 -> V_59 ;
unsigned long V_233 = F_22 ( V_2 ) ;
struct V_72 * V_72 = NULL ;
struct V_234 * V_235 = NULL ;
unsigned int V_25 = 0 , V_26 = 0 ;
unsigned int V_6 = - 1 ;
bool V_236 ;
F_3 ( & V_58 -> V_182 ) ;
F_3 ( & V_34 -> V_54 ) ;
V_236 = F_171 ( V_2 ) ;
while ( ( V_6 = F_23 ( V_232 , V_233 , V_6 + 1 ) ) < V_233 ) {
struct V_13 * V_38 = F_13 ( V_2 , V_6 ) ;
int V_237 , V_41 ;
V_237 = F_173 ( V_34 , V_6 ) ;
if ( V_236 )
goto V_238;
V_41 = F_156 ( V_56 , V_221 , V_6 , 1 ) ;
if ( V_41 >= 0 ) {
F_161 ( V_56 , V_41 ) = F_174 ( V_6 ) ;
F_175 ( V_38 , & F_176 ( V_56 , V_41 ) ) ;
goto V_239;
}
V_238:
if ( ! V_72 || ( V_25 > V_6 ) || ( V_6 > V_26 ) ) {
if ( V_72 ) {
F_57 ( V_72 , 1 ) ;
V_72 = NULL ;
}
V_25 = F_177 ( V_34 , V_6 ) ;
V_26 = V_25 + V_240 - 1 ;
V_72 = F_166 ( V_2 , V_25 ) ;
V_235 = F_55 ( V_72 ) ;
}
F_175 ( V_38 , & V_235 -> V_203 [ V_237 ] ) ;
V_239:
F_178 ( V_6 , V_232 ) ;
V_34 -> V_36 -- ;
}
F_20 ( & V_34 -> V_54 ) ;
F_20 ( & V_58 -> V_182 ) ;
F_57 ( V_72 , 1 ) ;
F_21 ( V_2 ) ;
}
static int F_179 ( struct V_1 * V_2 )
{
struct V_241 * V_242 = F_180 ( V_2 ) ;
struct V_194 * V_65 = F_143 ( V_2 ) ;
struct V_33 * V_34 ;
unsigned int V_243 , V_25 ;
char * V_244 , * V_245 ;
unsigned int V_246 ;
V_34 = F_181 ( sizeof( struct V_33 ) , V_247 ) ;
if ( ! V_34 )
return - V_248 ;
F_182 ( V_2 ) -> V_33 = V_34 ;
V_34 -> V_249 = F_183 ( F_22 ( V_2 ) * sizeof( struct V_13 ) ) ;
if ( ! V_34 -> V_249 )
return - V_248 ;
V_246 = F_184 ( F_22 ( V_2 ) ) ;
V_34 -> V_35 = F_181 ( V_246 , V_247 ) ;
if ( ! V_34 -> V_35 )
return - V_248 ;
for ( V_25 = 0 ; V_25 < F_22 ( V_2 ) ; V_25 ++ ) {
V_34 -> V_249 [ V_25 ] . V_45
= F_181 ( V_250 , V_247 ) ;
V_34 -> V_249 [ V_25 ] . V_46
= F_181 ( V_250 , V_247 ) ;
if ( ! V_34 -> V_249 [ V_25 ] . V_45
|| ! V_34 -> V_249 [ V_25 ] . V_46 )
return - V_248 ;
}
if ( V_2 -> V_16 > 1 ) {
V_34 -> V_251 = F_183 ( F_62 ( V_2 ) *
sizeof( struct V_252 ) ) ;
if ( ! V_34 -> V_251 )
return - V_248 ;
}
V_243 = F_145 ( V_242 -> V_253 ) >> 1 ;
V_246 = F_185 ( V_2 , V_254 ) ;
V_244 = F_186 ( V_2 , V_254 ) ;
V_245 = F_187 ( V_244 , V_246 , V_247 ) ;
if ( ! V_245 )
return - V_248 ;
V_34 -> V_123 = & V_255 ;
V_34 -> V_223 = F_145 ( V_242 -> V_256 ) ;
V_34 -> V_225 = V_243 << V_2 -> V_31 ;
V_34 -> V_48 = F_188 ( V_65 -> V_257 ) ;
V_34 -> V_224 = V_245 ;
V_34 -> V_246 = V_246 ;
V_34 -> V_36 = 0 ;
V_34 -> V_258 = V_240 ;
V_34 -> V_259 = F_188 ( V_2 -> V_65 -> V_259 ) ;
V_34 -> V_260 = V_261 . V_262 ;
F_189 ( & V_34 -> V_54 ) ;
return 0 ;
}
static int F_190 ( struct V_1 * V_2 )
{
struct V_263 * V_264 = F_182 ( V_2 ) ;
struct V_76 * V_77 ;
unsigned int V_246 , V_265 ;
V_77 = F_181 ( sizeof( struct V_76 ) , V_247 ) ;
if ( ! V_77 )
return - V_248 ;
F_182 ( V_2 ) -> V_266 = V_77 ;
V_246 = F_184 ( F_22 ( V_2 ) ) ;
V_77 -> V_78 = F_107 ( V_246 , V_247 ) ;
if ( ! V_77 -> V_78 )
return - V_248 ;
V_265 = F_184 ( F_62 ( V_2 ) ) ;
V_77 -> V_94 = F_107 ( V_265 , V_247 ) ;
if ( ! V_77 -> V_94 )
return - V_248 ;
memset ( V_77 -> V_78 , 0xff , V_246 ) ;
memset ( V_77 -> V_94 , 0xff , V_265 ) ;
V_77 -> V_267 =
( unsigned int ) F_191 ( V_2 , V_264 -> V_268 ) ;
V_77 -> V_269 = 0 ;
V_77 -> V_270 = 0 ;
F_192 ( & V_77 -> V_91 ) ;
return 0 ;
}
static int F_193 ( struct V_1 * V_2 )
{
struct V_57 * V_271 ;
int V_27 ;
V_271 = F_181 ( sizeof( * V_271 ) * V_98 , V_247 ) ;
if ( ! V_271 )
return - V_248 ;
F_182 ( V_2 ) -> V_272 = V_271 ;
for ( V_27 = 0 ; V_27 < V_98 ; V_27 ++ ) {
F_189 ( & V_271 [ V_27 ] . V_182 ) ;
V_271 [ V_27 ] . V_59 = F_181 ( V_68 , V_247 ) ;
if ( ! V_271 [ V_27 ] . V_59 )
return - V_248 ;
V_271 [ V_27 ] . V_6 = V_19 ;
V_271 [ V_27 ] . V_60 = 0 ;
}
return F_151 ( V_2 ) ;
}
static void F_194 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_31 ( V_2 ) ;
struct V_57 * V_58 = F_47 ( V_2 , V_64 ) ;
struct V_73 * V_56 = V_58 -> V_59 ;
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < F_22 ( V_2 ) ; V_25 ++ ) {
struct V_13 * V_38 = & V_34 -> V_249 [ V_25 ] ;
struct V_234 * V_273 ;
struct V_274 V_275 ;
struct V_72 * V_72 ;
int V_27 ;
F_3 ( & V_58 -> V_182 ) ;
for ( V_27 = 0 ; V_27 < F_160 ( V_56 ) ; V_27 ++ ) {
if ( F_145 ( F_161 ( V_56 , V_27 ) ) == V_25 ) {
V_275 = F_176 ( V_56 , V_27 ) ;
F_20 ( & V_58 -> V_182 ) ;
goto V_92;
}
}
F_20 ( & V_58 -> V_182 ) ;
V_72 = F_163 ( V_2 , V_25 ) ;
V_273 = (struct V_234 * ) F_55 ( V_72 ) ;
V_275 = V_273 -> V_203 [ F_173 ( V_34 , V_25 ) ] ;
F_57 ( V_72 , 1 ) ;
V_92:
F_195 ( V_2 , V_25 , & V_275 ) ;
F_196 ( V_38 , & V_275 ) ;
if ( V_2 -> V_16 > 1 ) {
struct V_252 * V_276 = F_43 ( V_2 , V_25 ) ;
V_276 -> V_18 += V_38 -> V_18 ;
}
}
}
static void F_197 ( struct V_1 * V_2 )
{
unsigned int V_25 ;
int type ;
for ( V_25 = 0 ; V_25 < F_22 ( V_2 ) ; V_25 ++ ) {
struct V_13 * V_14 = F_13 ( V_2 , V_25 ) ;
if ( ! V_14 -> V_18 )
F_198 ( V_2 , V_25 ) ;
}
for ( type = V_63 ; type <= V_179 ; type ++ ) {
struct V_57 * V_277 = F_47 ( V_2 , type ) ;
F_75 ( V_2 , V_277 -> V_6 ) ;
}
}
static void F_199 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_10 ( V_2 ) ;
struct V_76 * V_77 = F_59 ( V_2 ) ;
unsigned int V_6 = 0 , V_41 = 0 , V_23 = F_22 ( V_2 ) ;
unsigned short V_18 ;
while ( 1 ) {
V_6 = F_200 ( V_77 , V_23 , V_41 ) ;
if ( V_6 >= V_23 )
break;
V_41 = V_6 + 1 ;
V_18 = F_16 ( V_2 , V_6 , 0 ) ;
if ( V_18 >= V_2 -> V_22 || ! V_18 )
continue;
F_3 ( & V_9 -> V_20 ) ;
F_9 ( V_2 , V_6 , V_12 ) ;
F_20 ( & V_9 -> V_20 ) ;
}
}
static int F_201 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_10 ( V_2 ) ;
unsigned int V_246 = F_184 ( F_62 ( V_2 ) ) ;
V_9 -> V_17 = F_181 ( V_246 , V_247 ) ;
if ( ! V_9 -> V_17 )
return - V_248 ;
return 0 ;
}
static int F_202 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_246 , V_27 ;
V_9 = F_181 ( sizeof( struct V_8 ) , V_247 ) ;
if ( ! V_9 )
return - V_248 ;
F_182 ( V_2 ) -> V_278 = V_9 ;
F_189 ( & V_9 -> V_20 ) ;
V_246 = F_184 ( F_22 ( V_2 ) ) ;
for ( V_27 = 0 ; V_27 < V_279 ; V_27 ++ ) {
V_9 -> V_10 [ V_27 ] = F_181 ( V_246 , V_247 ) ;
if ( ! V_9 -> V_10 [ V_27 ] )
return - V_248 ;
}
F_199 ( V_2 ) ;
return F_201 ( V_2 ) ;
}
static void F_203 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_31 ( V_2 ) ;
unsigned int V_6 ;
F_3 ( & V_34 -> V_54 ) ;
V_34 -> V_280 = V_281 ;
for ( V_6 = 0 ; V_6 < F_22 ( V_2 ) ; V_6 += V_2 -> V_16 ) {
unsigned int V_27 ;
unsigned long long V_43 = 0 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_16 ; V_27 ++ )
V_43 += F_13 ( V_2 , V_6 + V_27 ) -> V_43 ;
V_43 = F_204 ( V_43 , V_2 -> V_16 ) ;
if ( V_34 -> V_280 > V_43 )
V_34 -> V_280 = V_43 ;
}
V_34 -> V_44 = F_38 ( V_2 ) ;
F_20 ( & V_34 -> V_54 ) ;
}
int F_205 ( struct V_1 * V_2 )
{
struct V_241 * V_242 = F_180 ( V_2 ) ;
struct V_194 * V_65 = F_143 ( V_2 ) ;
struct V_263 * V_264 ;
int V_126 ;
V_264 = F_181 ( sizeof( struct V_263 ) , V_247 ) ;
if ( ! V_264 )
return - V_248 ;
V_2 -> V_264 = V_264 ;
F_206 ( & V_264 -> V_282 ) ;
F_207 ( & V_264 -> V_283 ) ;
V_264 -> V_284 = F_145 ( V_242 -> V_285 ) ;
V_264 -> V_268 = F_145 ( V_242 -> V_268 ) ;
V_264 -> V_286 = F_145 ( V_242 -> V_286 ) ;
V_264 -> V_287 = F_145 ( V_65 -> V_288 ) ;
V_264 -> V_289 = F_145 ( V_65 -> V_290 ) ;
V_264 -> V_291 = F_145 ( V_242 -> V_292 ) ;
V_264 -> V_293 = F_145 ( V_242 -> V_293 ) ;
V_264 -> V_294 = V_295 ;
V_126 = F_179 ( V_2 ) ;
if ( V_126 )
return V_126 ;
V_126 = F_190 ( V_2 ) ;
if ( V_126 )
return V_126 ;
V_126 = F_193 ( V_2 ) ;
if ( V_126 )
return V_126 ;
F_194 ( V_2 ) ;
F_197 ( V_2 ) ;
V_126 = F_202 ( V_2 ) ;
if ( V_126 )
return V_126 ;
F_203 ( V_2 ) ;
return 0 ;
}
static void F_208 ( struct V_1 * V_2 ,
enum V_7 V_7 )
{
struct V_8 * V_9 = F_10 ( V_2 ) ;
F_3 ( & V_9 -> V_20 ) ;
F_92 ( V_9 -> V_10 [ V_7 ] ) ;
V_9 -> V_11 [ V_7 ] = 0 ;
F_20 ( & V_9 -> V_20 ) ;
}
static void F_209 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_10 ( V_2 ) ;
F_92 ( V_9 -> V_17 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_10 ( V_2 ) ;
int V_27 ;
if ( ! V_9 )
return;
for ( V_27 = 0 ; V_27 < V_279 ; V_27 ++ )
F_208 ( V_2 , V_27 ) ;
F_209 ( V_2 ) ;
F_182 ( V_2 ) -> V_278 = NULL ;
F_92 ( V_9 ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
struct V_57 * V_271 = F_182 ( V_2 ) -> V_272 ;
int V_27 ;
if ( ! V_271 )
return;
F_182 ( V_2 ) -> V_272 = NULL ;
for ( V_27 = 0 ; V_27 < V_98 ; V_27 ++ )
F_92 ( V_271 [ V_27 ] . V_59 ) ;
F_92 ( V_271 ) ;
}
static void F_212 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = F_182 ( V_2 ) -> V_266 ;
if ( ! V_77 )
return;
F_182 ( V_2 ) -> V_266 = NULL ;
F_92 ( V_77 -> V_78 ) ;
F_92 ( V_77 -> V_94 ) ;
F_92 ( V_77 ) ;
}
static void F_213 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_31 ( V_2 ) ;
unsigned int V_25 ;
if ( ! V_34 )
return;
if ( V_34 -> V_249 ) {
for ( V_25 = 0 ; V_25 < F_22 ( V_2 ) ; V_25 ++ ) {
F_92 ( V_34 -> V_249 [ V_25 ] . V_45 ) ;
F_92 ( V_34 -> V_249 [ V_25 ] . V_46 ) ;
}
}
F_214 ( V_34 -> V_249 ) ;
F_214 ( V_34 -> V_251 ) ;
F_92 ( V_34 -> V_35 ) ;
F_182 ( V_2 ) -> V_33 = NULL ;
F_92 ( V_34 -> V_224 ) ;
F_92 ( V_34 ) ;
}
void F_215 ( struct V_1 * V_2 )
{
struct V_263 * V_264 = F_182 ( V_2 ) ;
if ( ! V_264 )
return;
F_210 ( V_2 ) ;
F_211 ( V_2 ) ;
F_212 ( V_2 ) ;
F_213 ( V_2 ) ;
V_2 -> V_264 = NULL ;
F_92 ( V_264 ) ;
}
