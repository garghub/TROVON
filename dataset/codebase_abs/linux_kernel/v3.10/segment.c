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
void F_15 ( struct V_1 * V_2 , unsigned int V_4 )
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
unsigned int V_4 , V_23 = 0 ;
unsigned int V_24 = F_18 ( V_2 ) ;
F_3 ( & V_7 -> V_20 ) ;
while ( 1 ) {
V_4 = F_19 ( V_7 -> V_8 [ V_21 ] , V_24 ,
V_23 ) ;
if ( V_4 >= V_24 )
break;
F_20 ( V_2 , V_4 ) ;
V_23 = V_4 + 1 ;
}
F_16 ( & V_7 -> V_20 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
unsigned int V_4 , V_23 = 0 ;
unsigned int V_24 = F_18 ( V_2 ) ;
F_3 ( & V_7 -> V_20 ) ;
while ( 1 ) {
V_4 = F_19 ( V_7 -> V_8 [ V_21 ] , V_24 ,
V_23 ) ;
if ( V_4 >= V_24 )
break;
V_23 = V_4 + 1 ;
if ( F_10 ( V_4 , V_7 -> V_8 [ V_21 ] ) )
V_7 -> V_9 [ V_21 ] -- ;
if ( F_22 ( V_2 , V_25 ) )
F_23 ( V_2 -> V_26 -> V_27 ,
F_24 ( V_2 , V_4 ) <<
V_2 -> V_28 ,
1 << ( V_2 -> V_28 +
V_2 -> V_29 ) ,
V_30 , 0 ) ;
}
F_16 ( & V_7 -> V_20 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_4 )
{
struct V_31 * V_32 = F_26 ( V_2 ) ;
if ( ! F_27 ( V_4 , V_32 -> V_33 ) )
V_32 -> V_34 ++ ;
}
static void F_28 ( struct V_1 * V_2 , int type ,
unsigned int V_4 , int V_35 )
{
struct V_11 * V_36 = F_9 ( V_2 , V_4 ) ;
V_36 -> type = type ;
if ( V_35 )
F_25 ( V_2 , V_4 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_37 , int V_38 )
{
struct V_11 * V_36 ;
unsigned int V_4 , V_23 ;
long int V_39 ;
V_4 = F_30 ( V_2 , V_37 ) ;
V_36 = F_9 ( V_2 , V_4 ) ;
V_39 = V_36 -> V_18 + V_38 ;
V_23 = F_31 ( V_2 , V_37 ) & ( V_2 -> V_22 - 1 ) ;
F_32 ( ( V_39 >> (sizeof( unsigned short ) << 3 ) ||
( V_39 > V_2 -> V_22 ) ) ) ;
V_36 -> V_18 = V_39 ;
V_36 -> V_40 = F_33 ( V_2 ) ;
F_26 ( V_2 ) -> V_41 = V_36 -> V_40 ;
if ( V_38 > 0 ) {
if ( F_34 ( V_23 , V_36 -> V_42 ) )
F_35 () ;
} else {
if ( ! F_36 ( V_23 , V_36 -> V_42 ) )
F_35 () ;
}
if ( ! F_37 ( V_23 , V_36 -> V_43 ) )
V_36 -> V_44 += V_38 ;
F_25 ( V_2 , V_4 ) ;
F_26 ( V_2 ) -> V_45 += V_38 ;
if ( V_2 -> V_16 > 1 )
F_38 ( V_2 , V_4 ) -> V_18 += V_38 ;
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
struct V_31 * V_32 = F_26 ( V_2 ) ;
F_32 ( V_48 == V_49 ) ;
if ( V_48 == V_50 )
return;
F_3 ( & V_32 -> V_51 ) ;
F_29 ( V_2 , V_48 , - 1 ) ;
F_15 ( V_2 , V_4 ) ;
F_16 ( & V_32 -> V_51 ) ;
}
static void F_41 ( struct V_1 * V_2 , int type ,
struct V_52 * V_53 , unsigned short V_23 )
{
struct V_54 * V_55 = F_42 ( V_2 , type ) ;
void * V_48 = V_55 -> V_56 ;
V_48 += V_23 * sizeof( struct V_52 ) ;
memcpy ( V_48 , V_53 , sizeof( struct V_52 ) ) ;
return;
}
int F_43 ( struct V_1 * V_2 )
{
int V_57 = 0 ;
int V_58 = 0 ;
int V_59 , V_60 ;
for ( V_59 = V_61 ; V_59 <= V_62 ; V_59 ++ ) {
if ( V_2 -> V_63 -> V_64 [ V_59 ] == V_65 )
V_58 += V_2 -> V_22 ;
else
V_58 += F_44 ( V_2 , V_59 ) ;
}
V_57 = V_58 * ( V_66 + 1 )
+ sizeof( struct V_67 ) + 2
+ sizeof( struct V_68 ) + 2 ;
V_60 = V_69 - V_70 ;
if ( V_57 < V_60 )
return 1 ;
else if ( V_57 < 2 * V_60 )
return 2 ;
return 3 ;
}
struct V_71 * F_45 ( struct V_1 * V_2 , unsigned int V_4 )
{
return F_46 ( V_2 , F_47 ( V_2 , V_4 ) ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_72 * V_56 , T_1 V_73 )
{
struct V_71 * V_71 = F_49 ( V_2 , V_73 ) ;
void * V_74 = F_50 ( V_71 ) ;
memcpy ( V_74 , V_56 , V_69 ) ;
F_51 ( V_71 ) ;
F_52 ( V_71 , 1 ) ;
}
static unsigned int F_53 ( struct V_1 * V_2 , int type )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
unsigned long * V_75 = V_7 -> V_8 [ V_21 ] ;
unsigned int V_4 ;
unsigned int V_76 = 0 ;
if ( F_2 ( V_2 , 0 ) )
return V_19 ;
if ( F_54 ( type ) )
return V_19 ;
V_77:
V_4 = F_19 ( V_75 , F_18 ( V_2 ) , V_76 ) ;
V_76 += V_2 -> V_16 ;
if ( V_4 < F_18 ( V_2 ) ) {
int V_59 ;
if ( V_4 % V_2 -> V_16 )
goto V_77;
if ( F_55 ( V_2 , F_14 ( V_2 , V_4 ) ) )
goto V_77;
for ( V_59 = 1 ; V_59 < V_2 -> V_16 ; V_59 ++ )
if ( ! F_56 ( V_4 + V_59 , V_75 ) )
goto V_77;
for ( V_59 = 0 ; V_59 < V_2 -> V_16 ; V_59 ++ )
if ( F_9 ( V_2 , V_4 + V_59 ) -> V_44 )
goto V_77;
return V_4 ;
}
return V_19 ;
}
static int F_57 ( struct V_1 * V_2 , int type )
{
struct V_54 * V_55 = F_42 ( V_2 , type ) ;
unsigned int V_4 = V_55 -> V_4 ;
struct V_78 * V_79 = F_58 ( V_2 ) ;
if ( V_4 + 1 < F_18 ( V_2 ) && ( V_4 + 1 ) % V_2 -> V_16 )
return ! F_56 ( V_4 + 1 , V_79 -> V_80 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 ,
unsigned int * V_81 , bool V_82 , int V_83 )
{
struct V_78 * V_79 = F_58 ( V_2 ) ;
unsigned int V_4 , V_84 , V_85 ;
unsigned int V_86 = F_60 ( V_2 ) / V_2 -> V_87 ;
unsigned int V_88 = * V_81 / V_2 -> V_16 ;
unsigned int V_89 = F_61 ( V_2 , * V_81 ) ;
unsigned int V_90 = V_88 ;
bool V_91 = true ;
int V_92 = 0 ;
int V_59 ;
F_62 ( & V_79 -> V_93 ) ;
if ( ! V_82 && ( ( * V_81 + 1 ) % V_2 -> V_16 ) ) {
V_4 = F_63 ( V_79 -> V_80 ,
F_18 ( V_2 ) , * V_81 + 1 ) ;
if ( V_4 - * V_81 < V_2 -> V_16 -
( * V_81 % V_2 -> V_16 ) )
goto V_94;
}
V_95:
V_84 = F_63 ( V_79 -> V_96 , F_60 ( V_2 ) , V_88 ) ;
if ( V_84 >= F_60 ( V_2 ) ) {
if ( V_83 == V_97 ) {
V_84 = F_63 ( V_79 -> V_96 ,
F_60 ( V_2 ) , 0 ) ;
F_32 ( V_84 >= F_60 ( V_2 ) ) ;
} else {
V_92 = 1 ;
V_90 = V_88 - 1 ;
}
}
if ( V_92 == 0 )
goto V_98;
while ( F_56 ( V_90 , V_79 -> V_96 ) ) {
if ( V_90 > 0 ) {
V_90 -- ;
continue;
}
V_90 = F_63 ( V_79 -> V_96 ,
F_60 ( V_2 ) , 0 ) ;
F_32 ( V_90 >= F_60 ( V_2 ) ) ;
break;
}
V_84 = V_90 ;
V_98:
V_88 = V_84 ;
V_4 = V_84 * V_2 -> V_16 ;
V_85 = V_84 / V_2 -> V_87 ;
if ( ! V_91 )
goto V_94;
if ( V_2 -> V_87 == 1 )
goto V_94;
if ( V_85 == V_89 )
goto V_94;
if ( V_83 == V_99 ) {
if ( ! V_92 && V_85 + 1 >= V_86 )
goto V_94;
if ( V_92 && V_85 == 0 )
goto V_94;
}
for ( V_59 = 0 ; V_59 < V_100 ; V_59 ++ )
if ( F_42 ( V_2 , V_59 ) -> V_101 == V_85 )
break;
if ( V_59 < V_100 ) {
if ( V_92 )
V_88 = V_85 * V_2 -> V_87 - 1 ;
else if ( V_85 + 1 >= V_86 )
V_88 = 0 ;
else
V_88 = ( V_85 + 1 ) * V_2 -> V_87 ;
V_91 = false ;
goto V_95;
}
V_94:
F_32 ( F_56 ( V_4 , V_79 -> V_80 ) ) ;
F_64 ( V_2 , V_4 ) ;
* V_81 = V_4 ;
F_65 ( & V_79 -> V_93 ) ;
}
static void F_66 ( struct V_1 * V_2 , int type , int V_35 )
{
struct V_54 * V_55 = F_42 ( V_2 , type ) ;
struct V_102 * V_103 ;
V_55 -> V_4 = V_55 -> V_104 ;
V_55 -> V_101 = F_61 ( V_2 , V_55 -> V_4 ) ;
V_55 -> V_105 = 0 ;
V_55 -> V_104 = V_19 ;
V_103 = & ( V_55 -> V_56 -> V_106 ) ;
memset ( V_103 , 0 , sizeof( struct V_102 ) ) ;
if ( F_67 ( type ) )
F_68 ( V_103 , V_107 ) ;
if ( F_54 ( type ) )
F_68 ( V_103 , V_108 ) ;
F_28 ( V_2 , type , V_55 -> V_4 , V_35 ) ;
}
static void F_69 ( struct V_1 * V_2 , int type , bool V_82 )
{
struct V_54 * V_55 = F_42 ( V_2 , type ) ;
unsigned int V_4 = V_55 -> V_4 ;
int V_83 = V_99 ;
F_48 ( V_2 , V_55 -> V_56 ,
F_47 ( V_2 , V_55 -> V_4 ) ) ;
if ( type == V_109 || type == V_62 )
V_83 = V_97 ;
if ( F_22 ( V_2 , V_110 ) )
V_83 = V_97 ;
F_59 ( V_2 , & V_4 , V_82 , V_83 ) ;
V_55 -> V_104 = V_4 ;
F_66 ( V_2 , type , 1 ) ;
V_55 -> V_64 = V_111 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_54 * V_112 , T_1 V_113 )
{
struct V_11 * V_36 = F_9 ( V_2 , V_112 -> V_4 ) ;
T_1 V_76 ;
for ( V_76 = V_113 ; V_76 < V_2 -> V_22 ; V_76 ++ ) {
if ( ! F_37 ( V_76 , V_36 -> V_43 )
&& ! F_37 ( V_76 , V_36 -> V_42 ) )
break;
}
V_112 -> V_105 = V_76 ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_54 * V_112 )
{
if ( V_112 -> V_64 == V_65 )
F_70 ( V_2 , V_112 , V_112 -> V_105 + 1 ) ;
else
V_112 -> V_105 ++ ;
}
static void F_72 ( struct V_1 * V_2 , int type , bool V_114 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
struct V_54 * V_55 = F_42 ( V_2 , type ) ;
unsigned int V_115 = V_55 -> V_104 ;
struct V_72 * V_116 ;
struct V_71 * V_117 ;
F_48 ( V_2 , V_55 -> V_56 ,
F_47 ( V_2 , V_55 -> V_4 ) ) ;
F_73 ( V_2 , V_115 ) ;
F_3 ( & V_7 -> V_20 ) ;
F_11 ( V_2 , V_115 , V_21 ) ;
F_11 ( V_2 , V_115 , V_10 ) ;
F_16 ( & V_7 -> V_20 ) ;
F_66 ( V_2 , type , 1 ) ;
V_55 -> V_64 = V_65 ;
F_70 ( V_2 , V_55 , 0 ) ;
if ( V_114 ) {
V_117 = F_45 ( V_2 , V_115 ) ;
V_116 = (struct V_72 * ) F_50 ( V_117 ) ;
memcpy ( V_55 -> V_56 , V_116 , V_118 ) ;
F_52 ( V_117 , 1 ) ;
}
}
static int F_74 ( struct V_1 * V_2 , int type )
{
struct V_54 * V_55 = F_42 ( V_2 , type ) ;
const struct V_119 * V_120 = F_6 ( V_2 ) -> V_120 ;
if ( F_54 ( type ) || ! F_2 ( V_2 , 0 ) )
return V_120 -> V_121 ( V_2 ,
& ( V_55 ) -> V_104 , V_122 , type , V_65 ) ;
for (; type >= V_61 ; type -- )
if ( V_120 -> V_121 ( V_2 , & ( V_55 ) -> V_104 ,
V_122 , type , V_65 ) )
return 1 ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 ,
int type , bool V_123 )
{
struct V_54 * V_55 = F_42 ( V_2 , type ) ;
if ( V_123 ) {
F_69 ( V_2 , type , true ) ;
goto V_124;
}
V_55 -> V_104 = F_53 ( V_2 , type ) ;
if ( V_55 -> V_104 != V_19 )
F_72 ( V_2 , type , false ) ;
else if ( type == V_125 )
F_69 ( V_2 , type , false ) ;
else if ( V_55 -> V_64 == V_111 && F_57 ( V_2 , type ) )
F_69 ( V_2 , type , false ) ;
else if ( F_76 ( V_2 ) && F_74 ( V_2 , type ) )
F_72 ( V_2 , type , true ) ;
else
F_69 ( V_2 , type , false ) ;
V_124:
V_2 -> V_126 [ V_55 -> V_64 ] ++ ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_54 * V_55 ;
unsigned int V_127 ;
int V_59 ;
for ( V_59 = V_61 ; V_59 <= V_62 ; V_59 ++ ) {
V_55 = F_42 ( V_2 , V_59 ) ;
V_127 = V_55 -> V_4 ;
F_26 ( V_2 ) -> V_128 -> V_129 ( V_2 , V_59 , true ) ;
F_15 ( V_2 , V_127 ) ;
}
}
static void F_78 ( struct V_130 * V_130 , int V_131 )
{
const int V_132 = F_56 ( V_133 , & V_130 -> V_134 ) ;
struct V_135 * V_136 = V_130 -> V_137 + V_130 -> V_138 - 1 ;
struct V_139 * V_140 = V_130 -> V_141 ;
do {
struct V_71 * V_71 = V_136 -> V_142 ;
if ( -- V_136 >= V_130 -> V_137 )
F_79 ( & V_136 -> V_142 -> V_143 ) ;
if ( ! V_132 ) {
F_80 ( V_71 ) ;
if ( V_71 -> V_144 )
F_81 ( V_145 , & V_71 -> V_144 -> V_143 ) ;
F_82 ( V_140 -> V_2 -> V_63 , V_146 ) ;
V_140 -> V_2 -> V_26 -> V_147 |= V_148 ;
}
F_83 ( V_71 ) ;
F_84 ( V_140 -> V_2 , V_149 ) ;
} while ( V_136 >= V_130 -> V_137 );
if ( V_140 -> V_150 )
F_85 ( V_140 -> V_151 ) ;
F_86 ( V_140 ) ;
F_87 ( V_130 ) ;
}
struct V_130 * F_88 ( struct V_152 * V_153 , int V_154 )
{
struct V_130 * V_130 ;
struct V_139 * V_155 ;
V_156:
V_155 = F_89 ( sizeof( struct V_139 ) , V_30 ) ;
if ( ! V_155 ) {
F_90 () ;
goto V_156;
}
V_130 = F_91 ( V_157 , V_154 ) ;
V_130 -> V_158 = V_153 ;
V_130 -> V_141 = V_155 ;
return V_130 ;
}
static void F_92 ( struct V_1 * V_2 ,
enum V_159 type , bool V_160 )
{
int V_161 = V_160 ? V_162 : V_163 ;
enum V_159 V_164 = type > V_165 ? V_165 : type ;
if ( type >= V_166 )
V_161 = V_167 ;
if ( V_164 == V_165 )
V_161 |= V_168 ;
if ( V_2 -> V_130 [ V_164 ] ) {
struct V_139 * V_140 = V_2 -> V_130 [ V_164 ] -> V_141 ;
V_140 -> V_2 = V_2 ;
V_2 -> V_130 [ V_164 ] -> V_169 = F_78 ;
F_93 ( V_2 -> V_26 , V_164 , V_160 , V_2 -> V_130 [ V_164 ] ) ;
if ( type == V_166 ) {
F_94 ( V_151 ) ;
V_140 -> V_150 = true ;
V_140 -> V_151 = & V_151 ;
F_95 ( V_161 , V_2 -> V_130 [ V_164 ] ) ;
F_96 ( & V_151 ) ;
} else {
V_140 -> V_150 = false ;
F_95 ( V_161 , V_2 -> V_130 [ V_164 ] ) ;
}
V_2 -> V_130 [ V_164 ] = NULL ;
}
}
void F_97 ( struct V_1 * V_2 , enum V_159 type , bool V_160 )
{
F_98 ( & V_2 -> V_170 ) ;
F_92 ( V_2 , type , V_160 ) ;
F_99 ( & V_2 -> V_170 ) ;
}
static void F_100 ( struct V_1 * V_2 , struct V_71 * V_71 ,
T_1 V_73 , enum V_159 type )
{
struct V_152 * V_153 = V_2 -> V_26 -> V_27 ;
F_101 ( V_2 , V_73 ) ;
F_98 ( & V_2 -> V_170 ) ;
F_102 ( V_2 , V_149 ) ;
if ( V_2 -> V_130 [ type ] && V_2 -> V_171 [ type ] != V_73 - 1 )
F_92 ( V_2 , type , false ) ;
V_172:
if ( V_2 -> V_130 [ type ] == NULL ) {
V_2 -> V_130 [ type ] = F_88 ( V_153 , F_103 ( V_2 ) ) ;
V_2 -> V_130 [ type ] -> V_173 = F_104 ( V_2 , V_73 ) ;
}
if ( F_105 ( V_2 -> V_130 [ type ] , V_71 , V_69 , 0 ) <
V_69 ) {
F_92 ( V_2 , type , false ) ;
goto V_172;
}
V_2 -> V_171 [ type ] = V_73 ;
F_99 ( & V_2 -> V_170 ) ;
F_106 ( V_71 , V_73 , type ) ;
}
static bool F_107 ( struct V_1 * V_2 , int type )
{
struct V_54 * V_55 = F_42 ( V_2 , type ) ;
if ( V_55 -> V_105 < V_2 -> V_22 )
return true ;
return false ;
}
static int F_108 ( struct V_71 * V_71 , enum V_159 V_174 )
{
if ( V_174 == V_175 )
return V_61 ;
else
return V_176 ;
}
static int F_109 ( struct V_71 * V_71 , enum V_159 V_174 )
{
if ( V_174 == V_175 ) {
struct V_177 * V_177 = V_71 -> V_144 -> V_178 ;
if ( F_110 ( V_177 -> V_179 ) )
return V_61 ;
else
return V_62 ;
} else {
if ( F_111 ( V_71 ) && ! F_112 ( V_71 ) )
return V_176 ;
else
return V_180 ;
}
}
static int F_113 ( struct V_71 * V_71 , enum V_159 V_174 )
{
if ( V_174 == V_175 ) {
struct V_177 * V_177 = V_71 -> V_144 -> V_178 ;
if ( F_110 ( V_177 -> V_179 ) )
return V_61 ;
else if ( F_114 ( V_71 ) || F_115 ( V_177 ) )
return V_62 ;
else
return V_109 ;
} else {
if ( F_111 ( V_71 ) )
return F_112 ( V_71 ) ? V_125 :
V_176 ;
else
return V_180 ;
}
}
static int F_116 ( struct V_71 * V_71 , enum V_159 V_174 )
{
struct V_1 * V_2 = F_117 ( V_71 -> V_144 -> V_178 -> V_181 ) ;
switch ( V_2 -> V_182 ) {
case 2 :
return F_108 ( V_71 , V_174 ) ;
case 4 :
return F_109 ( V_71 , V_174 ) ;
}
F_32 ( V_2 -> V_182 != V_100 ) ;
return F_113 ( V_71 , V_174 ) ;
}
static void F_118 ( struct V_1 * V_2 , struct V_71 * V_71 ,
T_1 V_46 , T_1 * V_47 ,
struct V_52 * V_53 , enum V_159 V_174 )
{
struct V_31 * V_32 = F_26 ( V_2 ) ;
struct V_54 * V_55 ;
unsigned int V_183 ;
int type ;
type = F_116 ( V_71 , V_174 ) ;
V_55 = F_42 ( V_2 , type ) ;
F_3 ( & V_55 -> V_184 ) ;
* V_47 = F_119 ( V_2 , V_55 ) ;
V_183 = V_55 -> V_4 ;
F_41 ( V_2 , type , V_53 , V_55 -> V_105 ) ;
F_3 ( & V_32 -> V_51 ) ;
F_71 ( V_2 , V_55 ) ;
V_2 -> V_185 [ V_55 -> V_64 ] ++ ;
F_39 ( V_2 , V_46 , * V_47 ) ;
if ( ! F_107 ( V_2 , type ) )
V_32 -> V_128 -> V_129 ( V_2 , type , false ) ;
F_15 ( V_2 , V_183 ) ;
F_15 ( V_2 , F_30 ( V_2 , V_46 ) ) ;
F_16 ( & V_32 -> V_51 ) ;
if ( V_174 == V_186 )
F_120 ( V_71 , F_119 ( V_2 , V_55 ) ) ;
F_100 ( V_2 , V_71 , * V_47 , V_174 ) ;
F_16 ( & V_55 -> V_184 ) ;
}
void F_121 ( struct V_1 * V_2 , struct V_71 * V_71 )
{
F_122 ( V_71 ) ;
F_100 ( V_2 , V_71 , V_71 -> V_187 , V_165 ) ;
}
void F_123 ( struct V_1 * V_2 , struct V_71 * V_71 ,
unsigned int V_188 , T_1 V_46 , T_1 * V_47 )
{
struct V_52 V_53 ;
F_124 ( & V_53 , V_188 , 0 , 0 ) ;
F_118 ( V_2 , V_71 , V_46 , V_47 , & V_53 , V_186 ) ;
}
void F_125 ( struct V_177 * V_177 , struct V_71 * V_71 ,
struct V_189 * V_190 , T_1 V_46 ,
T_1 * V_47 )
{
struct V_1 * V_2 = F_117 ( V_177 -> V_181 ) ;
struct V_52 V_53 ;
struct V_191 V_192 ;
F_32 ( V_46 == V_49 ) ;
F_126 ( V_2 , V_190 -> V_188 , & V_192 ) ;
F_124 ( & V_53 , V_190 -> V_188 , V_190 -> V_193 , V_192 . V_194 ) ;
F_118 ( V_2 , V_71 , V_46 ,
V_47 , & V_53 , V_175 ) ;
}
void F_127 ( struct V_1 * V_2 , struct V_71 * V_71 ,
T_1 V_195 )
{
F_100 ( V_2 , V_71 , V_195 , V_175 ) ;
}
void F_128 ( struct V_1 * V_2 ,
struct V_71 * V_71 , struct V_52 * V_53 ,
T_1 V_46 , T_1 V_47 )
{
struct V_31 * V_32 = F_26 ( V_2 ) ;
struct V_54 * V_55 ;
unsigned int V_4 , V_183 ;
struct V_11 * V_36 ;
int type ;
V_4 = F_30 ( V_2 , V_47 ) ;
V_36 = F_9 ( V_2 , V_4 ) ;
type = V_36 -> type ;
if ( V_36 -> V_18 == 0 && ! F_7 ( V_2 , V_4 ) ) {
if ( V_46 == V_49 )
type = V_62 ;
else
type = V_109 ;
}
V_55 = F_42 ( V_2 , type ) ;
F_3 ( & V_55 -> V_184 ) ;
F_3 ( & V_32 -> V_51 ) ;
V_183 = V_55 -> V_4 ;
if ( V_4 != V_55 -> V_4 ) {
V_55 -> V_104 = V_4 ;
F_72 ( V_2 , type , true ) ;
}
V_55 -> V_105 = F_31 ( V_2 , V_47 ) &
( V_2 -> V_22 - 1 ) ;
F_41 ( V_2 , type , V_53 , V_55 -> V_105 ) ;
F_39 ( V_2 , V_46 , V_47 ) ;
F_15 ( V_2 , V_183 ) ;
F_15 ( V_2 , F_30 ( V_2 , V_46 ) ) ;
F_16 ( & V_32 -> V_51 ) ;
F_16 ( & V_55 -> V_184 ) ;
}
void F_129 ( struct V_1 * V_2 ,
struct V_71 * V_71 , struct V_52 * V_53 ,
T_1 V_46 , T_1 V_47 )
{
struct V_31 * V_32 = F_26 ( V_2 ) ;
int type = V_125 ;
struct V_54 * V_55 ;
unsigned int V_4 , V_183 ;
T_1 V_196 = F_130 ( V_71 ) ;
unsigned int V_104 = F_30 ( V_2 , V_196 ) ;
V_55 = F_42 ( V_2 , type ) ;
F_3 ( & V_55 -> V_184 ) ;
F_3 ( & V_32 -> V_51 ) ;
V_4 = F_30 ( V_2 , V_47 ) ;
V_183 = V_55 -> V_4 ;
if ( V_4 != V_55 -> V_4 ) {
V_55 -> V_104 = V_4 ;
F_72 ( V_2 , type , true ) ;
}
V_55 -> V_105 = F_31 ( V_2 , V_47 ) &
( V_2 -> V_22 - 1 ) ;
F_41 ( V_2 , type , V_53 , V_55 -> V_105 ) ;
if ( V_104 != V_4 ) {
V_55 -> V_104 = V_104 ;
F_72 ( V_2 , type , true ) ;
}
V_55 -> V_105 = F_31 ( V_2 , V_196 ) &
( V_2 -> V_22 - 1 ) ;
F_122 ( V_71 ) ;
F_100 ( V_2 , V_71 , V_47 , V_186 ) ;
F_97 ( V_2 , V_186 , true ) ;
F_39 ( V_2 , V_46 , V_47 ) ;
F_15 ( V_2 , V_183 ) ;
F_15 ( V_2 , F_30 ( V_2 , V_46 ) ) ;
F_16 ( & V_32 -> V_51 ) ;
F_16 ( & V_55 -> V_184 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
struct V_197 * V_63 = F_132 ( V_2 ) ;
struct V_54 * V_198 ;
unsigned char * V_74 ;
struct V_71 * V_71 ;
T_1 V_113 ;
int V_59 , V_199 , V_23 ;
V_113 = F_133 ( V_2 ) ;
V_71 = F_46 ( V_2 , V_113 ++ ) ;
V_74 = ( unsigned char * ) F_50 ( V_71 ) ;
V_198 = F_42 ( V_2 , V_61 ) ;
memcpy ( & V_198 -> V_56 -> V_200 , V_74 , V_201 ) ;
V_198 = F_42 ( V_2 , V_62 ) ;
memcpy ( & V_198 -> V_56 -> V_202 , V_74 + V_201 ,
V_201 ) ;
V_23 = 2 * V_201 ;
for ( V_59 = V_61 ; V_59 <= V_62 ; V_59 ++ ) {
unsigned short V_203 ;
unsigned int V_4 ;
V_198 = F_42 ( V_2 , V_59 ) ;
V_4 = F_134 ( V_63 -> V_204 [ V_59 ] ) ;
V_203 = F_135 ( V_63 -> V_205 [ V_59 ] ) ;
V_198 -> V_104 = V_4 ;
F_66 ( V_2 , V_59 , 0 ) ;
V_198 -> V_64 = V_63 -> V_64 [ V_59 ] ;
V_198 -> V_105 = V_203 ;
if ( V_198 -> V_64 == V_65 )
V_203 = V_2 -> V_22 ;
for ( V_199 = 0 ; V_199 < V_203 ; V_199 ++ ) {
struct V_52 * V_206 ;
V_206 = (struct V_52 * ) ( V_74 + V_23 ) ;
V_198 -> V_56 -> V_207 [ V_199 ] = * V_206 ;
V_23 += V_66 ;
if ( V_23 + V_66 <= V_69 -
V_70 )
continue;
F_52 ( V_71 , 1 ) ;
V_71 = NULL ;
V_71 = F_46 ( V_2 , V_113 ++ ) ;
V_74 = ( unsigned char * ) F_50 ( V_71 ) ;
V_23 = 0 ;
}
}
F_52 ( V_71 , 1 ) ;
return 0 ;
}
static int F_136 ( struct V_1 * V_2 , int type )
{
struct V_197 * V_63 = F_132 ( V_2 ) ;
struct V_72 * V_53 ;
struct V_54 * V_55 ;
struct V_71 * V_208 ;
unsigned short V_203 ;
unsigned int V_4 = 0 ;
T_1 V_73 = 0 ;
if ( F_67 ( type ) ) {
V_4 = F_134 ( V_63 -> V_204 [ type ] ) ;
V_203 = F_135 ( V_63 -> V_205 [ type -
V_61 ] ) ;
if ( F_137 ( V_63 , V_209 ) )
V_73 = F_138 ( V_2 , V_100 , type ) ;
else
V_73 = F_138 ( V_2 , V_210 , type ) ;
} else {
V_4 = F_134 ( V_63 -> V_211 [ type -
V_176 ] ) ;
V_203 = F_135 ( V_63 -> V_212 [ type -
V_176 ] ) ;
if ( F_137 ( V_63 , V_209 ) )
V_73 = F_138 ( V_2 , V_213 ,
type - V_176 ) ;
else
V_73 = F_47 ( V_2 , V_4 ) ;
}
V_208 = F_46 ( V_2 , V_73 ) ;
V_53 = (struct V_72 * ) F_50 ( V_208 ) ;
if ( F_54 ( type ) ) {
if ( F_137 ( V_63 , V_209 ) ) {
struct V_52 * V_214 = & V_53 -> V_207 [ 0 ] ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_22 ; V_59 ++ , V_214 ++ ) {
V_214 -> V_194 = 0 ;
V_214 -> V_193 = 0 ;
}
} else {
if ( F_139 ( V_2 , V_4 , V_53 ) ) {
F_52 ( V_208 , 1 ) ;
return - V_215 ;
}
}
}
V_55 = F_42 ( V_2 , type ) ;
F_3 ( & V_55 -> V_184 ) ;
memcpy ( V_55 -> V_56 , V_53 , V_69 ) ;
V_55 -> V_104 = V_4 ;
F_66 ( V_2 , type , 0 ) ;
V_55 -> V_64 = V_63 -> V_64 [ type ] ;
V_55 -> V_105 = V_203 ;
F_16 ( & V_55 -> V_184 ) ;
F_52 ( V_208 , 1 ) ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 )
{
int type = V_61 ;
if ( F_137 ( F_132 ( V_2 ) , V_216 ) ) {
if ( F_131 ( V_2 ) )
return - V_215 ;
type = V_176 ;
}
for (; type <= V_180 ; type ++ )
if ( F_136 ( V_2 , type ) )
return - V_215 ;
return 0 ;
}
static void F_141 ( struct V_1 * V_2 , T_1 V_37 )
{
struct V_71 * V_71 ;
unsigned char * V_74 ;
struct V_52 * V_217 ;
struct V_54 * V_198 ;
int V_218 = 0 ;
int V_59 , V_199 ;
V_71 = F_49 ( V_2 , V_37 ++ ) ;
V_74 = ( unsigned char * ) F_50 ( V_71 ) ;
V_198 = F_42 ( V_2 , V_61 ) ;
memcpy ( V_74 , & V_198 -> V_56 -> V_200 , V_201 ) ;
V_218 += V_201 ;
V_198 = F_42 ( V_2 , V_62 ) ;
memcpy ( V_74 + V_218 , & V_198 -> V_56 -> V_202 ,
V_201 ) ;
V_218 += V_201 ;
F_51 ( V_71 ) ;
for ( V_59 = V_61 ; V_59 <= V_62 ; V_59 ++ ) {
unsigned short V_219 ;
V_198 = F_42 ( V_2 , V_59 ) ;
if ( V_2 -> V_63 -> V_64 [ V_59 ] == V_65 )
V_219 = V_2 -> V_22 ;
else
V_219 = F_44 ( V_2 , V_59 ) ;
for ( V_199 = 0 ; V_199 < V_219 ; V_199 ++ ) {
if ( ! V_71 ) {
V_71 = F_49 ( V_2 , V_37 ++ ) ;
V_74 = ( unsigned char * ) F_50 ( V_71 ) ;
V_218 = 0 ;
}
V_217 = (struct V_52 * ) ( V_74 + V_218 ) ;
* V_217 = V_198 -> V_56 -> V_207 [ V_199 ] ;
V_218 += V_66 ;
F_51 ( V_71 ) ;
if ( V_218 + V_66 <= V_69 -
V_70 )
continue;
F_52 ( V_71 , 1 ) ;
V_71 = NULL ;
}
}
if ( V_71 )
F_52 ( V_71 , 1 ) ;
}
static void F_142 ( struct V_1 * V_2 ,
T_1 V_37 , int type )
{
int V_59 , V_220 ;
if ( F_67 ( type ) )
V_220 = type + V_210 ;
else
V_220 = type + V_213 ;
for ( V_59 = type ; V_59 < V_220 ; V_59 ++ ) {
struct V_54 * V_53 = F_42 ( V_2 , V_59 ) ;
F_3 ( & V_53 -> V_184 ) ;
F_48 ( V_2 , V_53 -> V_56 , V_37 + ( V_59 - type ) ) ;
F_16 ( & V_53 -> V_184 ) ;
}
}
void F_143 ( struct V_1 * V_2 , T_1 V_221 )
{
if ( F_137 ( F_132 ( V_2 ) , V_216 ) )
F_141 ( V_2 , V_221 ) ;
else
F_142 ( V_2 , V_221 , V_61 ) ;
}
void F_144 ( struct V_1 * V_2 , T_1 V_221 )
{
if ( F_137 ( F_132 ( V_2 ) , V_209 ) )
F_142 ( V_2 , V_221 , V_176 ) ;
return;
}
int F_145 ( struct V_72 * V_53 , int type ,
unsigned int V_222 , int V_223 )
{
int V_59 ;
if ( type == V_224 ) {
for ( V_59 = 0 ; V_59 < F_146 ( V_53 ) ; V_59 ++ ) {
if ( F_134 ( F_147 ( V_53 , V_59 ) ) == V_222 )
return V_59 ;
}
if ( V_223 && F_146 ( V_53 ) < V_225 )
return F_148 ( V_53 , 1 ) ;
} else if ( type == V_226 ) {
for ( V_59 = 0 ; V_59 < F_149 ( V_53 ) ; V_59 ++ )
if ( F_134 ( F_150 ( V_53 , V_59 ) ) == V_222 )
return V_59 ;
if ( V_223 && F_149 ( V_53 ) < V_227 )
return F_151 ( V_53 , 1 ) ;
}
return - 1 ;
}
static struct V_71 * F_152 ( struct V_1 * V_2 ,
unsigned int V_4 )
{
struct V_31 * V_32 = F_26 ( V_2 ) ;
unsigned int V_23 = F_153 ( V_32 , V_4 ) ;
T_1 V_73 = V_32 -> V_228 + V_23 ;
F_154 ( V_2 , V_4 ) ;
if ( F_37 ( V_23 , V_32 -> V_229 ) )
V_73 += V_32 -> V_230 ;
return F_46 ( V_2 , V_73 ) ;
}
static struct V_71 * F_155 ( struct V_1 * V_2 ,
unsigned int V_113 )
{
struct V_31 * V_32 = F_26 ( V_2 ) ;
struct V_71 * V_231 , * V_232 ;
T_2 V_233 , V_234 ;
void * V_235 , * V_236 ;
V_233 = F_156 ( V_2 , V_113 ) ;
V_234 = F_157 ( V_2 , V_233 ) ;
V_231 = F_46 ( V_2 , V_233 ) ;
V_232 = F_49 ( V_2 , V_234 ) ;
F_32 ( F_158 ( V_231 ) ) ;
V_235 = F_50 ( V_231 ) ;
V_236 = F_50 ( V_232 ) ;
memcpy ( V_236 , V_235 , V_69 ) ;
F_51 ( V_232 ) ;
F_52 ( V_231 , 1 ) ;
F_159 ( V_32 , V_113 ) ;
return V_232 ;
}
static bool F_160 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_42 ( V_2 , V_62 ) ;
struct V_72 * V_53 = V_55 -> V_56 ;
int V_59 ;
if ( F_149 ( V_53 ) >= V_227 ) {
for ( V_59 = F_149 ( V_53 ) - 1 ; V_59 >= 0 ; V_59 -- ) {
unsigned int V_4 ;
V_4 = F_134 ( F_150 ( V_53 , V_59 ) ) ;
F_25 ( V_2 , V_4 ) ;
}
F_151 ( V_53 , - F_149 ( V_53 ) ) ;
return 1 ;
}
return 0 ;
}
void F_161 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_26 ( V_2 ) ;
unsigned long * V_237 = V_32 -> V_33 ;
struct V_54 * V_55 = F_42 ( V_2 , V_62 ) ;
struct V_72 * V_53 = V_55 -> V_56 ;
unsigned long V_238 = F_18 ( V_2 ) ;
struct V_71 * V_71 = NULL ;
struct V_239 * V_240 = NULL ;
unsigned int V_113 = 0 , V_220 = 0 ;
unsigned int V_4 = - 1 ;
bool V_241 ;
F_3 ( & V_55 -> V_184 ) ;
F_3 ( & V_32 -> V_51 ) ;
V_241 = F_160 ( V_2 ) ;
while ( ( V_4 = F_19 ( V_237 , V_238 , V_4 + 1 ) ) < V_238 ) {
struct V_11 * V_36 = F_9 ( V_2 , V_4 ) ;
int V_242 , V_23 ;
V_242 = F_162 ( V_32 , V_4 ) ;
if ( V_241 )
goto V_243;
V_23 = F_145 ( V_53 , V_226 , V_4 , 1 ) ;
if ( V_23 >= 0 ) {
F_150 ( V_53 , V_23 ) = F_163 ( V_4 ) ;
F_164 ( V_36 , & F_165 ( V_53 , V_23 ) ) ;
goto V_244;
}
V_243:
if ( ! V_71 || ( V_113 > V_4 ) || ( V_4 > V_220 ) ) {
if ( V_71 ) {
F_52 ( V_71 , 1 ) ;
V_71 = NULL ;
}
V_113 = F_166 ( V_32 , V_4 ) ;
V_220 = V_113 + V_245 - 1 ;
V_71 = F_155 ( V_2 , V_113 ) ;
V_240 = F_50 ( V_71 ) ;
}
F_164 ( V_36 , & V_240 -> V_207 [ V_242 ] ) ;
V_244:
F_167 ( V_4 , V_237 ) ;
V_32 -> V_34 -- ;
}
F_16 ( & V_32 -> V_51 ) ;
F_16 ( & V_55 -> V_184 ) ;
F_52 ( V_71 , 1 ) ;
F_17 ( V_2 ) ;
}
static int F_168 ( struct V_1 * V_2 )
{
struct V_246 * V_247 = F_169 ( V_2 ) ;
struct V_197 * V_63 = F_132 ( V_2 ) ;
struct V_31 * V_32 ;
unsigned int V_248 , V_113 ;
char * V_249 , * V_250 ;
unsigned int V_251 ;
V_32 = F_170 ( sizeof( struct V_31 ) , V_252 ) ;
if ( ! V_32 )
return - V_253 ;
F_171 ( V_2 ) -> V_31 = V_32 ;
V_32 -> V_254 = F_172 ( F_18 ( V_2 ) * sizeof( struct V_11 ) ) ;
if ( ! V_32 -> V_254 )
return - V_253 ;
V_251 = F_173 ( F_18 ( V_2 ) ) ;
V_32 -> V_33 = F_170 ( V_251 , V_252 ) ;
if ( ! V_32 -> V_33 )
return - V_253 ;
for ( V_113 = 0 ; V_113 < F_18 ( V_2 ) ; V_113 ++ ) {
V_32 -> V_254 [ V_113 ] . V_42
= F_170 ( V_255 , V_252 ) ;
V_32 -> V_254 [ V_113 ] . V_43
= F_170 ( V_255 , V_252 ) ;
if ( ! V_32 -> V_254 [ V_113 ] . V_42
|| ! V_32 -> V_254 [ V_113 ] . V_43 )
return - V_253 ;
}
if ( V_2 -> V_16 > 1 ) {
V_32 -> V_256 = F_172 ( F_60 ( V_2 ) *
sizeof( struct V_257 ) ) ;
if ( ! V_32 -> V_256 )
return - V_253 ;
}
V_248 = F_134 ( V_247 -> V_258 ) >> 1 ;
V_251 = F_174 ( V_2 , V_259 ) ;
V_249 = F_175 ( V_2 , V_259 ) ;
V_250 = F_176 ( V_249 , V_251 , V_252 ) ;
if ( ! V_250 )
return - V_253 ;
V_32 -> V_128 = & V_260 ;
V_32 -> V_228 = F_134 ( V_247 -> V_261 ) ;
V_32 -> V_230 = V_248 << V_2 -> V_29 ;
V_32 -> V_45 = F_177 ( V_63 -> V_262 ) ;
V_32 -> V_229 = V_250 ;
V_32 -> V_251 = V_251 ;
V_32 -> V_34 = 0 ;
V_32 -> V_263 = V_245 ;
V_32 -> V_264 = F_177 ( V_2 -> V_63 -> V_264 ) ;
V_32 -> V_265 = V_266 . V_267 ;
F_178 ( & V_32 -> V_51 ) ;
return 0 ;
}
static int F_179 ( struct V_1 * V_2 )
{
struct V_268 * V_269 = F_171 ( V_2 ) ;
struct V_78 * V_79 ;
unsigned int V_251 , V_270 ;
V_79 = F_170 ( sizeof( struct V_78 ) , V_252 ) ;
if ( ! V_79 )
return - V_253 ;
F_171 ( V_2 ) -> V_271 = V_79 ;
V_251 = F_173 ( F_18 ( V_2 ) ) ;
V_79 -> V_80 = F_89 ( V_251 , V_252 ) ;
if ( ! V_79 -> V_80 )
return - V_253 ;
V_270 = F_173 ( F_60 ( V_2 ) ) ;
V_79 -> V_96 = F_89 ( V_270 , V_252 ) ;
if ( ! V_79 -> V_96 )
return - V_253 ;
memset ( V_79 -> V_80 , 0xff , V_251 ) ;
memset ( V_79 -> V_96 , 0xff , V_270 ) ;
V_79 -> V_272 =
( unsigned int ) F_180 ( V_2 , V_269 -> V_273 ) ;
V_79 -> V_274 = 0 ;
V_79 -> V_275 = 0 ;
F_181 ( & V_79 -> V_93 ) ;
return 0 ;
}
static int F_182 ( struct V_1 * V_2 )
{
struct V_54 * V_276 ;
int V_59 ;
V_276 = F_170 ( sizeof( * V_276 ) * V_100 , V_252 ) ;
if ( ! V_276 )
return - V_253 ;
F_171 ( V_2 ) -> V_277 = V_276 ;
for ( V_59 = 0 ; V_59 < V_100 ; V_59 ++ ) {
F_178 ( & V_276 [ V_59 ] . V_184 ) ;
V_276 [ V_59 ] . V_56 = F_170 ( V_69 , V_252 ) ;
if ( ! V_276 [ V_59 ] . V_56 )
return - V_253 ;
V_276 [ V_59 ] . V_4 = V_19 ;
V_276 [ V_59 ] . V_105 = 0 ;
}
return F_140 ( V_2 ) ;
}
static void F_183 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_26 ( V_2 ) ;
struct V_54 * V_55 = F_42 ( V_2 , V_62 ) ;
struct V_72 * V_53 = V_55 -> V_56 ;
unsigned int V_113 ;
for ( V_113 = 0 ; V_113 < F_18 ( V_2 ) ; V_113 ++ ) {
struct V_11 * V_36 = & V_32 -> V_254 [ V_113 ] ;
struct V_239 * V_278 ;
struct V_279 V_280 ;
struct V_71 * V_71 ;
int V_59 ;
F_3 ( & V_55 -> V_184 ) ;
for ( V_59 = 0 ; V_59 < F_149 ( V_53 ) ; V_59 ++ ) {
if ( F_134 ( F_150 ( V_53 , V_59 ) ) == V_113 ) {
V_280 = F_165 ( V_53 , V_59 ) ;
F_16 ( & V_55 -> V_184 ) ;
goto V_94;
}
}
F_16 ( & V_55 -> V_184 ) ;
V_71 = F_152 ( V_2 , V_113 ) ;
V_278 = (struct V_239 * ) F_50 ( V_71 ) ;
V_280 = V_278 -> V_207 [ F_162 ( V_32 , V_113 ) ] ;
F_52 ( V_71 , 1 ) ;
V_94:
F_184 ( V_2 , V_113 , & V_280 ) ;
F_185 ( V_36 , & V_280 ) ;
if ( V_2 -> V_16 > 1 ) {
struct V_257 * V_281 = F_38 ( V_2 , V_113 ) ;
V_281 -> V_18 += V_36 -> V_18 ;
}
}
}
static void F_186 ( struct V_1 * V_2 )
{
unsigned int V_113 ;
int type ;
for ( V_113 = 0 ; V_113 < F_18 ( V_2 ) ; V_113 ++ ) {
struct V_11 * V_12 = F_9 ( V_2 , V_113 ) ;
if ( ! V_12 -> V_18 )
F_187 ( V_2 , V_113 ) ;
}
for ( type = V_61 ; type <= V_180 ; type ++ ) {
struct V_54 * V_282 = F_42 ( V_2 , type ) ;
F_73 ( V_2 , V_282 -> V_4 ) ;
}
}
static void F_188 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
struct V_78 * V_79 = F_58 ( V_2 ) ;
unsigned int V_4 = 0 , V_23 = 0 ;
unsigned short V_18 ;
while ( V_4 < F_18 ( V_2 ) ) {
V_4 = F_189 ( V_79 , F_18 ( V_2 ) , V_23 ) ;
if ( V_4 >= F_18 ( V_2 ) )
break;
V_23 = V_4 + 1 ;
V_18 = F_12 ( V_2 , V_4 , 0 ) ;
if ( V_18 >= V_2 -> V_22 || ! V_18 )
continue;
F_3 ( & V_7 -> V_20 ) ;
F_5 ( V_2 , V_4 , V_10 ) ;
F_16 ( & V_7 -> V_20 ) ;
}
}
static int F_190 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
unsigned int V_251 = F_173 ( F_60 ( V_2 ) ) ;
V_7 -> V_17 = F_170 ( V_251 , V_252 ) ;
if ( ! V_7 -> V_17 )
return - V_253 ;
return 0 ;
}
static int F_191 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
unsigned int V_251 , V_59 ;
V_7 = F_170 ( sizeof( struct V_6 ) , V_252 ) ;
if ( ! V_7 )
return - V_253 ;
F_171 ( V_2 ) -> V_283 = V_7 ;
F_178 ( & V_7 -> V_20 ) ;
V_251 = F_173 ( F_18 ( V_2 ) ) ;
for ( V_59 = 0 ; V_59 < V_284 ; V_59 ++ ) {
V_7 -> V_8 [ V_59 ] = F_170 ( V_251 , V_252 ) ;
if ( ! V_7 -> V_8 [ V_59 ] )
return - V_253 ;
}
F_188 ( V_2 ) ;
return F_190 ( V_2 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_26 ( V_2 ) ;
unsigned int V_4 ;
F_3 ( & V_32 -> V_51 ) ;
V_32 -> V_285 = V_286 ;
for ( V_4 = 0 ; V_4 < F_18 ( V_2 ) ; V_4 += V_2 -> V_16 ) {
unsigned int V_59 ;
unsigned long long V_40 = 0 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_16 ; V_59 ++ )
V_40 += F_9 ( V_2 , V_4 + V_59 ) -> V_40 ;
V_40 = F_193 ( V_40 , V_2 -> V_16 ) ;
if ( V_32 -> V_285 > V_40 )
V_32 -> V_285 = V_40 ;
}
V_32 -> V_41 = F_33 ( V_2 ) ;
F_16 ( & V_32 -> V_51 ) ;
}
int F_194 ( struct V_1 * V_2 )
{
struct V_246 * V_247 = F_169 ( V_2 ) ;
struct V_197 * V_63 = F_132 ( V_2 ) ;
struct V_268 * V_269 ;
int V_131 ;
V_269 = F_170 ( sizeof( struct V_268 ) , V_252 ) ;
if ( ! V_269 )
return - V_253 ;
V_2 -> V_269 = V_269 ;
F_195 ( & V_269 -> V_287 ) ;
F_196 ( & V_269 -> V_288 ) ;
V_269 -> V_289 = F_134 ( V_247 -> V_290 ) ;
V_269 -> V_273 = F_134 ( V_247 -> V_273 ) ;
V_269 -> V_126 = F_134 ( V_247 -> V_126 ) ;
V_269 -> V_291 = F_134 ( V_63 -> V_292 ) ;
V_269 -> V_293 = F_134 ( V_63 -> V_294 ) ;
V_269 -> V_295 = F_134 ( V_247 -> V_296 ) ;
V_269 -> V_297 = F_134 ( V_247 -> V_297 ) ;
V_131 = F_168 ( V_2 ) ;
if ( V_131 )
return V_131 ;
V_131 = F_179 ( V_2 ) ;
if ( V_131 )
return V_131 ;
V_131 = F_182 ( V_2 ) ;
if ( V_131 )
return V_131 ;
F_183 ( V_2 ) ;
F_186 ( V_2 ) ;
V_131 = F_191 ( V_2 ) ;
if ( V_131 )
return V_131 ;
F_192 ( V_2 ) ;
return 0 ;
}
static void F_197 ( struct V_1 * V_2 ,
enum V_5 V_5 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
F_3 ( & V_7 -> V_20 ) ;
F_86 ( V_7 -> V_8 [ V_5 ] ) ;
V_7 -> V_9 [ V_5 ] = 0 ;
F_16 ( & V_7 -> V_20 ) ;
}
static void F_198 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
F_86 ( V_7 -> V_17 ) ;
}
static void F_199 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
int V_59 ;
if ( ! V_7 )
return;
for ( V_59 = 0 ; V_59 < V_284 ; V_59 ++ )
F_197 ( V_2 , V_59 ) ;
F_198 ( V_2 ) ;
F_171 ( V_2 ) -> V_283 = NULL ;
F_86 ( V_7 ) ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_54 * V_276 = F_171 ( V_2 ) -> V_277 ;
int V_59 ;
if ( ! V_276 )
return;
F_171 ( V_2 ) -> V_277 = NULL ;
for ( V_59 = 0 ; V_59 < V_100 ; V_59 ++ )
F_86 ( V_276 [ V_59 ] . V_56 ) ;
F_86 ( V_276 ) ;
}
static void F_201 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = F_171 ( V_2 ) -> V_271 ;
if ( ! V_79 )
return;
F_171 ( V_2 ) -> V_271 = NULL ;
F_86 ( V_79 -> V_80 ) ;
F_86 ( V_79 -> V_96 ) ;
F_86 ( V_79 ) ;
}
static void F_202 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_26 ( V_2 ) ;
unsigned int V_113 ;
if ( ! V_32 )
return;
if ( V_32 -> V_254 ) {
for ( V_113 = 0 ; V_113 < F_18 ( V_2 ) ; V_113 ++ ) {
F_86 ( V_32 -> V_254 [ V_113 ] . V_42 ) ;
F_86 ( V_32 -> V_254 [ V_113 ] . V_43 ) ;
}
}
F_203 ( V_32 -> V_254 ) ;
F_203 ( V_32 -> V_256 ) ;
F_86 ( V_32 -> V_33 ) ;
F_171 ( V_2 ) -> V_31 = NULL ;
F_86 ( V_32 -> V_229 ) ;
F_86 ( V_32 ) ;
}
void F_204 ( struct V_1 * V_2 )
{
struct V_268 * V_269 = F_171 ( V_2 ) ;
F_199 ( V_2 ) ;
F_200 ( V_2 ) ;
F_201 ( V_2 ) ;
F_202 ( V_2 ) ;
V_2 -> V_269 = NULL ;
F_86 ( V_269 ) ;
}
