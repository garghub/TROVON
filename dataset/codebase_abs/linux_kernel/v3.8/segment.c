void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
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
V_5 = V_12 -> type ;
if ( ! F_8 ( V_4 , V_7 -> V_8 [ V_5 ] ) )
V_7 -> V_9 [ V_5 ] ++ ;
}
}
static void F_10 ( struct V_1 * V_2 , unsigned int V_4 ,
enum V_5 V_5 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
if ( F_11 ( V_4 , V_7 -> V_8 [ V_5 ] ) )
V_7 -> V_9 [ V_5 ] -- ;
if ( V_5 == V_10 ) {
struct V_11 * V_12 = F_9 ( V_2 , V_4 ) ;
V_5 = V_12 -> type ;
if ( F_11 ( V_4 ,
V_7 -> V_8 [ V_5 ] ) )
V_7 -> V_9 [ V_5 ] -- ;
F_12 ( V_4 , V_7 -> V_13 [ V_14 ] ) ;
F_12 ( V_4 , V_7 -> V_13 [ V_15 ] ) ;
}
}
void F_13 ( struct V_1 * V_2 , unsigned int V_4 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
unsigned short V_16 ;
if ( V_4 == V_17 || F_7 ( V_2 , V_4 ) )
return;
F_3 ( & V_7 -> V_18 ) ;
V_16 = F_14 ( V_2 , V_4 , 0 ) ;
if ( V_16 == 0 ) {
F_5 ( V_2 , V_4 , V_19 ) ;
F_10 ( V_2 , V_4 , V_10 ) ;
} else if ( V_16 < V_2 -> V_20 ) {
F_5 ( V_2 , V_4 , V_10 ) ;
} else {
F_10 ( V_2 , V_4 , V_10 ) ;
}
F_15 ( & V_7 -> V_18 ) ;
return;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
unsigned int V_4 , V_21 = 0 ;
unsigned int V_22 = F_17 ( V_2 ) ;
F_3 ( & V_7 -> V_18 ) ;
while ( 1 ) {
V_4 = F_18 ( V_7 -> V_8 [ V_19 ] , V_22 ,
V_21 ) ;
if ( V_4 >= V_22 )
break;
F_19 ( V_2 , V_4 ) ;
V_21 = V_4 + 1 ;
}
F_15 ( & V_7 -> V_18 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
unsigned int V_4 , V_21 = 0 ;
unsigned int V_22 = F_17 ( V_2 ) ;
F_3 ( & V_7 -> V_18 ) ;
while ( 1 ) {
V_4 = F_18 ( V_7 -> V_8 [ V_19 ] , V_22 ,
V_21 ) ;
if ( V_4 >= V_22 )
break;
V_21 = V_4 + 1 ;
if ( F_11 ( V_4 , V_7 -> V_8 [ V_19 ] ) )
V_7 -> V_9 [ V_19 ] -- ;
if ( F_21 ( V_2 , V_23 ) )
F_22 ( V_2 -> V_24 -> V_25 ,
F_23 ( V_2 , V_4 ) <<
V_2 -> V_26 ,
1 << ( V_2 -> V_26 +
V_2 -> V_27 ) ,
V_28 , 0 ) ;
}
F_15 ( & V_7 -> V_18 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_4 )
{
struct V_29 * V_30 = F_25 ( V_2 ) ;
if ( ! F_26 ( V_4 , V_30 -> V_31 ) )
V_30 -> V_32 ++ ;
}
static void F_27 ( struct V_1 * V_2 , int type ,
unsigned int V_4 , int V_33 )
{
struct V_11 * V_34 = F_9 ( V_2 , V_4 ) ;
V_34 -> type = type ;
if ( V_33 )
F_24 ( V_2 , V_4 ) ;
}
static void F_28 ( struct V_1 * V_2 , T_1 V_35 , int V_36 )
{
struct V_11 * V_34 ;
unsigned int V_4 , V_21 ;
long int V_37 ;
V_4 = F_29 ( V_2 , V_35 ) ;
V_34 = F_9 ( V_2 , V_4 ) ;
V_37 = V_34 -> V_16 + V_36 ;
V_21 = F_30 ( V_2 , V_35 ) & ( V_2 -> V_20 - 1 ) ;
F_31 ( ( V_37 >> (sizeof( unsigned short ) << 3 ) ||
( V_37 > V_2 -> V_20 ) ) ) ;
V_34 -> V_16 = V_37 ;
V_34 -> V_38 = F_32 ( V_2 ) ;
F_25 ( V_2 ) -> V_39 = V_34 -> V_38 ;
if ( V_36 > 0 ) {
if ( F_33 ( V_21 , V_34 -> V_40 ) )
F_34 () ;
} else {
if ( ! F_35 ( V_21 , V_34 -> V_40 ) )
F_34 () ;
}
if ( ! F_36 ( V_21 , V_34 -> V_41 ) )
V_34 -> V_42 += V_36 ;
F_24 ( V_2 , V_4 ) ;
F_25 ( V_2 ) -> V_43 += V_36 ;
if ( V_2 -> V_44 > 1 )
F_37 ( V_2 , V_4 ) -> V_16 += V_36 ;
}
static void F_38 ( struct V_1 * V_2 ,
T_1 V_45 , T_1 V_46 )
{
F_28 ( V_2 , V_46 , 1 ) ;
if ( F_29 ( V_2 , V_45 ) != V_17 )
F_28 ( V_2 , V_45 , - 1 ) ;
}
void F_39 ( struct V_1 * V_2 , T_1 V_47 )
{
unsigned int V_4 = F_29 ( V_2 , V_47 ) ;
struct V_29 * V_30 = F_25 ( V_2 ) ;
F_31 ( V_47 == V_48 ) ;
if ( V_47 == V_49 )
return;
F_3 ( & V_30 -> V_50 ) ;
F_28 ( V_2 , V_47 , - 1 ) ;
F_13 ( V_2 , V_4 ) ;
F_15 ( & V_30 -> V_50 ) ;
}
static void F_40 ( struct V_1 * V_2 , int type ,
struct V_51 * V_52 , unsigned short V_21 )
{
struct V_53 * V_54 = F_41 ( V_2 , type ) ;
void * V_47 = V_54 -> V_55 ;
V_47 += V_21 * sizeof( struct V_51 ) ;
memcpy ( V_47 , V_52 , sizeof( struct V_51 ) ) ;
return;
}
int F_42 ( struct V_1 * V_2 )
{
int V_56 = 0 ;
int V_57 = 0 ;
int V_58 , V_59 ;
for ( V_58 = V_60 ; V_58 <= V_61 ; V_58 ++ ) {
if ( V_2 -> V_62 -> V_63 [ V_58 ] == V_64 )
V_57 += V_2 -> V_20 ;
else
V_57 += F_43 ( V_2 , V_58 ) ;
}
V_56 = V_57 * ( V_65 + 1 )
+ sizeof( struct V_66 ) + 2
+ sizeof( struct V_67 ) + 2 ;
V_59 = V_68 - V_69 ;
if ( V_56 < V_59 )
return 1 ;
else if ( V_56 < 2 * V_59 )
return 2 ;
return 3 ;
}
struct V_70 * F_44 ( struct V_1 * V_2 , unsigned int V_4 )
{
return F_45 ( V_2 , F_46 ( V_2 , V_4 ) ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_71 * V_55 , T_1 V_72 )
{
struct V_70 * V_70 = F_48 ( V_2 , V_72 ) ;
void * V_73 = F_49 ( V_70 ) ;
memcpy ( V_73 , V_55 , V_68 ) ;
F_50 ( V_70 ) ;
F_51 ( V_70 , 1 ) ;
}
static unsigned int F_52 ( struct V_1 * V_2 ,
int V_74 , int type )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
unsigned long * V_75 = V_7 -> V_8 [ V_19 ] ;
unsigned int V_4 , V_76 , V_58 ;
int V_77 = 0 ;
if ( F_2 ( V_2 ) )
return V_17 ;
if ( F_53 ( type ) )
return V_17 ;
V_78:
V_4 = F_18 ( V_75 , F_17 ( V_2 ) , V_77 ++ ) ;
V_77 = ( ( V_4 / V_74 ) * V_74 ) + V_74 ;
if ( V_4 < F_17 ( V_2 ) ) {
if ( V_4 % V_74 )
goto V_78;
V_76 = F_54 ( V_75 ,
F_17 ( V_2 ) , V_4 + 1 ) ;
if ( V_76 - V_4 < V_74 )
goto V_78;
for ( V_58 = 0 ; V_58 < V_74 ; V_58 ++ )
if ( F_9 ( V_2 , V_4 ) -> V_42 )
goto V_78;
return V_4 ;
}
return V_17 ;
}
static void F_55 ( struct V_1 * V_2 ,
unsigned int * V_79 , bool V_80 , int V_81 )
{
struct V_82 * V_83 = F_56 ( V_2 ) ;
unsigned int V_84 = V_2 -> V_85 ;
unsigned int V_4 , V_86 , V_87 ;
unsigned int V_88 = V_2 -> V_85 / V_2 -> V_89 ;
unsigned int V_90 = * V_79 / V_2 -> V_44 ;
unsigned int V_91 = F_57 ( V_2 , * V_79 ) ;
unsigned int V_92 = V_90 ;
bool V_93 = true ;
int V_94 = 0 ;
int V_58 ;
F_58 ( & V_83 -> V_95 ) ;
if ( ! V_80 && ( ( * V_79 + 1 ) % V_2 -> V_44 ) ) {
V_4 = F_54 ( V_83 -> V_96 ,
F_17 ( V_2 ) , * V_79 + 1 ) ;
if ( V_4 < F_17 ( V_2 ) )
goto V_97;
}
V_98:
V_86 = F_54 ( V_83 -> V_99 , V_84 , V_90 ) ;
if ( V_86 >= V_84 ) {
if ( V_81 == V_100 ) {
V_86 = F_54 ( V_83 -> V_99 ,
V_84 , 0 ) ;
F_31 ( V_86 >= V_84 ) ;
} else {
V_94 = 1 ;
V_92 = V_90 - 1 ;
}
}
if ( V_94 == 0 )
goto V_101;
while ( F_59 ( V_92 , V_83 -> V_99 ) ) {
if ( V_92 > 0 ) {
V_92 -- ;
continue;
}
V_92 = F_54 ( V_83 -> V_99 ,
V_84 , 0 ) ;
F_31 ( V_92 >= V_84 ) ;
break;
}
V_86 = V_92 ;
V_101:
V_90 = V_86 ;
V_4 = V_86 * V_2 -> V_44 ;
V_87 = V_86 / V_2 -> V_89 ;
if ( ! V_93 )
goto V_97;
if ( V_2 -> V_89 == 1 )
goto V_97;
if ( V_87 == V_91 )
goto V_97;
if ( V_81 == V_102 ) {
if ( ! V_94 && V_87 + 1 >= V_88 )
goto V_97;
if ( V_94 && V_87 == 0 )
goto V_97;
}
for ( V_58 = 0 ; V_58 < V_103 ; V_58 ++ )
if ( F_41 ( V_2 , V_58 ) -> V_104 == V_87 )
break;
if ( V_58 < V_103 ) {
if ( V_94 )
V_90 = V_87 * V_2 -> V_89 - 1 ;
else if ( V_87 + 1 >= V_88 )
V_90 = 0 ;
else
V_90 = ( V_87 + 1 ) * V_2 -> V_89 ;
V_93 = false ;
goto V_98;
}
V_97:
F_31 ( F_59 ( V_4 , V_83 -> V_96 ) ) ;
F_60 ( V_2 , V_4 ) ;
* V_79 = V_4 ;
F_61 ( & V_83 -> V_95 ) ;
}
static void F_62 ( struct V_1 * V_2 , int type , int V_33 )
{
struct V_53 * V_54 = F_41 ( V_2 , type ) ;
struct V_105 * V_106 ;
V_54 -> V_4 = V_54 -> V_76 ;
V_54 -> V_104 = F_57 ( V_2 , V_54 -> V_4 ) ;
V_54 -> V_107 = 0 ;
V_54 -> V_76 = V_17 ;
V_106 = & ( V_54 -> V_55 -> V_108 ) ;
memset ( V_106 , 0 , sizeof( struct V_105 ) ) ;
if ( F_63 ( type ) )
F_64 ( V_106 , V_109 ) ;
if ( F_53 ( type ) )
F_64 ( V_106 , V_110 ) ;
F_27 ( V_2 , type , V_54 -> V_4 , V_33 ) ;
}
static void F_65 ( struct V_1 * V_2 , int type , bool V_80 )
{
struct V_53 * V_54 = F_41 ( V_2 , type ) ;
unsigned int V_4 = V_54 -> V_4 ;
int V_81 = V_102 ;
F_47 ( V_2 , V_54 -> V_55 ,
F_46 ( V_2 , V_54 -> V_4 ) ) ;
if ( type == V_111 || type == V_61 )
V_81 = V_100 ;
if ( F_21 ( V_2 , V_112 ) )
V_81 = V_100 ;
F_55 ( V_2 , & V_4 , V_80 , V_81 ) ;
V_54 -> V_76 = V_4 ;
F_62 ( V_2 , type , 1 ) ;
V_54 -> V_63 = V_113 ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_53 * V_114 , T_1 V_115 )
{
struct V_11 * V_34 = F_9 ( V_2 , V_114 -> V_4 ) ;
T_1 V_77 ;
for ( V_77 = V_115 ; V_77 < V_2 -> V_20 ; V_77 ++ ) {
if ( ! F_36 ( V_77 , V_34 -> V_41 )
&& ! F_36 ( V_77 , V_34 -> V_40 ) )
break;
}
V_114 -> V_107 = V_77 ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_53 * V_114 )
{
if ( V_114 -> V_63 == V_64 )
F_66 ( V_2 , V_114 , V_114 -> V_107 + 1 ) ;
else
V_114 -> V_107 ++ ;
}
static void F_68 ( struct V_1 * V_2 , int type , bool V_116 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
struct V_53 * V_54 = F_41 ( V_2 , type ) ;
unsigned int V_117 = V_54 -> V_76 ;
struct V_71 * V_118 ;
struct V_70 * V_119 ;
F_47 ( V_2 , V_54 -> V_55 ,
F_46 ( V_2 , V_54 -> V_4 ) ) ;
F_69 ( V_2 , V_117 ) ;
F_3 ( & V_7 -> V_18 ) ;
F_10 ( V_2 , V_117 , V_19 ) ;
F_10 ( V_2 , V_117 , V_10 ) ;
F_15 ( & V_7 -> V_18 ) ;
F_62 ( V_2 , type , 1 ) ;
V_54 -> V_63 = V_64 ;
F_66 ( V_2 , V_54 , 0 ) ;
if ( V_116 ) {
V_119 = F_44 ( V_2 , V_117 ) ;
V_118 = (struct V_71 * ) F_49 ( V_119 ) ;
memcpy ( V_54 -> V_55 , V_118 , V_120 ) ;
F_51 ( V_119 , 1 ) ;
}
}
static void F_70 ( struct V_1 * V_2 ,
int type , bool V_121 )
{
struct V_53 * V_54 = F_41 ( V_2 , type ) ;
unsigned int V_74 ;
if ( V_121 ) {
F_65 ( V_2 , type , true ) ;
goto V_122;
}
V_74 = F_71 ( V_2 ) ? 1 : V_2 -> V_44 ;
V_54 -> V_76 = F_52 ( V_2 , V_74 , type ) ;
if ( V_54 -> V_76 != V_17 )
F_68 ( V_2 , type , false ) ;
else if ( type == V_123 )
F_65 ( V_2 , type , false ) ;
else if ( F_71 ( V_2 ) && F_72 ( V_2 , type ) )
F_68 ( V_2 , type , true ) ;
else
F_65 ( V_2 , type , false ) ;
V_122:
V_2 -> V_124 [ V_54 -> V_63 ] ++ ;
}
void F_73 ( struct V_1 * V_2 )
{
struct V_53 * V_54 ;
unsigned int V_125 ;
int V_58 ;
for ( V_58 = V_60 ; V_58 <= V_61 ; V_58 ++ ) {
V_54 = F_41 ( V_2 , V_58 ) ;
V_125 = V_54 -> V_4 ;
F_25 ( V_2 ) -> V_126 -> V_127 ( V_2 , V_58 , true ) ;
F_13 ( V_2 , V_125 ) ;
}
}
static void F_74 ( struct V_128 * V_128 , int V_129 )
{
const int V_130 = F_59 ( V_131 , & V_128 -> V_132 ) ;
struct V_133 * V_134 = V_128 -> V_135 + V_128 -> V_136 - 1 ;
struct V_137 * V_138 = V_128 -> V_139 ;
do {
struct V_70 * V_70 = V_134 -> V_140 ;
if ( -- V_134 >= V_128 -> V_135 )
F_75 ( & V_134 -> V_140 -> V_141 ) ;
if ( ! V_130 ) {
F_76 ( V_70 ) ;
if ( V_70 -> V_142 )
F_77 ( V_143 , & V_70 -> V_142 -> V_141 ) ;
F_78 ( V_138 -> V_2 -> V_62 , V_144 ) ;
}
F_79 ( V_70 ) ;
F_80 ( V_138 -> V_2 , V_145 ) ;
} while ( V_134 >= V_128 -> V_135 );
if ( V_138 -> V_146 )
F_81 ( V_138 -> V_147 ) ;
F_82 ( V_138 ) ;
F_83 ( V_128 ) ;
}
struct V_128 * F_84 ( struct V_148 * V_149 , int V_150 )
{
struct V_128 * V_128 ;
struct V_137 * V_151 ;
V_152:
V_151 = F_85 ( sizeof( struct V_137 ) , V_28 ) ;
if ( ! V_151 ) {
F_86 () ;
goto V_152;
}
V_128 = F_87 ( V_153 , V_150 ) ;
V_128 -> V_154 = V_149 ;
V_128 -> V_139 = V_151 ;
return V_128 ;
}
static void F_88 ( struct V_1 * V_2 ,
enum V_155 type , bool V_156 )
{
int V_157 = V_156 ? V_158 : V_159 ;
enum V_155 V_160 = type > V_161 ? V_161 : type ;
if ( type >= V_162 )
V_157 = V_163 ;
if ( V_2 -> V_128 [ V_160 ] ) {
struct V_137 * V_138 = V_2 -> V_128 [ V_160 ] -> V_139 ;
V_138 -> V_2 = V_2 ;
V_2 -> V_128 [ V_160 ] -> V_164 = F_74 ;
if ( type == V_162 ) {
F_89 ( V_147 ) ;
V_138 -> V_146 = true ;
V_138 -> V_147 = & V_147 ;
F_90 ( V_157 , V_2 -> V_128 [ V_160 ] ) ;
F_91 ( & V_147 ) ;
} else {
V_138 -> V_146 = false ;
F_90 ( V_157 , V_2 -> V_128 [ V_160 ] ) ;
}
V_2 -> V_128 [ V_160 ] = NULL ;
}
}
void F_92 ( struct V_1 * V_2 , enum V_155 type , bool V_156 )
{
F_93 ( & V_2 -> V_165 ) ;
F_88 ( V_2 , type , V_156 ) ;
F_94 ( & V_2 -> V_165 ) ;
}
static void F_95 ( struct V_1 * V_2 , struct V_70 * V_70 ,
T_1 V_72 , enum V_155 type )
{
struct V_148 * V_149 = V_2 -> V_24 -> V_25 ;
F_96 ( V_2 , V_72 ) ;
F_93 ( & V_2 -> V_165 ) ;
F_97 ( V_2 , V_145 ) ;
if ( V_2 -> V_128 [ type ] && V_2 -> V_166 [ type ] != V_72 - 1 )
F_88 ( V_2 , type , false ) ;
V_167:
if ( V_2 -> V_128 [ type ] == NULL ) {
V_2 -> V_128 [ type ] = F_84 ( V_149 , F_98 ( V_149 ) ) ;
V_2 -> V_128 [ type ] -> V_168 = F_99 ( V_2 , V_72 ) ;
}
if ( F_100 ( V_2 -> V_128 [ type ] , V_70 , V_68 , 0 ) <
V_68 ) {
F_88 ( V_2 , type , false ) ;
goto V_167;
}
V_2 -> V_166 [ type ] = V_72 ;
F_94 ( & V_2 -> V_165 ) ;
}
static bool F_101 ( struct V_1 * V_2 , int type )
{
struct V_53 * V_54 = F_41 ( V_2 , type ) ;
if ( V_54 -> V_107 < V_2 -> V_20 )
return true ;
return false ;
}
static int F_102 ( struct V_70 * V_70 , enum V_155 V_169 )
{
if ( V_169 == V_170 )
return V_60 ;
else
return V_171 ;
}
static int F_103 ( struct V_70 * V_70 , enum V_155 V_169 )
{
if ( V_169 == V_170 ) {
struct V_172 * V_172 = V_70 -> V_142 -> V_173 ;
if ( F_104 ( V_172 -> V_174 ) )
return V_60 ;
else
return V_61 ;
} else {
if ( F_105 ( V_70 ) && ! F_106 ( V_70 ) )
return V_171 ;
else
return V_175 ;
}
}
static int F_107 ( struct V_70 * V_70 , enum V_155 V_169 )
{
if ( V_169 == V_170 ) {
struct V_172 * V_172 = V_70 -> V_142 -> V_173 ;
if ( F_104 ( V_172 -> V_174 ) )
return V_60 ;
else if ( F_108 ( V_70 ) || F_109 ( V_172 ) )
return V_61 ;
else
return V_111 ;
} else {
if ( F_105 ( V_70 ) )
return F_106 ( V_70 ) ? V_123 :
V_171 ;
else
return V_175 ;
}
}
static int F_110 ( struct V_70 * V_70 , enum V_155 V_169 )
{
struct V_1 * V_2 = F_111 ( V_70 -> V_142 -> V_173 -> V_176 ) ;
switch ( V_2 -> V_177 ) {
case 2 :
return F_102 ( V_70 , V_169 ) ;
case 4 :
return F_103 ( V_70 , V_169 ) ;
}
F_31 ( V_2 -> V_177 != V_103 ) ;
return F_107 ( V_70 , V_169 ) ;
}
static void F_112 ( struct V_1 * V_2 , struct V_70 * V_70 ,
T_1 V_45 , T_1 * V_46 ,
struct V_51 * V_52 , enum V_155 V_169 )
{
struct V_29 * V_30 = F_25 ( V_2 ) ;
struct V_53 * V_54 ;
unsigned int V_178 ;
int type ;
type = F_110 ( V_70 , V_169 ) ;
V_54 = F_41 ( V_2 , type ) ;
F_3 ( & V_54 -> V_179 ) ;
* V_46 = F_113 ( V_2 , V_54 ) ;
V_178 = V_54 -> V_4 ;
F_40 ( V_2 , type , V_52 , V_54 -> V_107 ) ;
F_3 ( & V_30 -> V_50 ) ;
F_67 ( V_2 , V_54 ) ;
V_2 -> V_180 [ V_54 -> V_63 ] ++ ;
F_38 ( V_2 , V_45 , * V_46 ) ;
if ( ! F_101 ( V_2 , type ) )
V_30 -> V_126 -> V_127 ( V_2 , type , false ) ;
F_13 ( V_2 , V_178 ) ;
F_13 ( V_2 , F_29 ( V_2 , V_45 ) ) ;
F_15 ( & V_30 -> V_50 ) ;
if ( V_169 == V_181 )
F_114 ( V_70 , F_113 ( V_2 , V_54 ) ) ;
F_95 ( V_2 , V_70 , * V_46 , V_169 ) ;
F_15 ( & V_54 -> V_179 ) ;
}
int F_115 ( struct V_1 * V_2 , struct V_70 * V_70 ,
struct V_182 * V_183 )
{
if ( V_183 -> V_184 )
return V_185 ;
F_116 ( V_70 ) ;
F_95 ( V_2 , V_70 , V_70 -> V_186 , V_161 ) ;
return 0 ;
}
void F_117 ( struct V_1 * V_2 , struct V_70 * V_70 ,
unsigned int V_187 , T_1 V_45 , T_1 * V_46 )
{
struct V_51 V_52 ;
F_118 ( & V_52 , V_187 , 0 , 0 ) ;
F_112 ( V_2 , V_70 , V_45 , V_46 , & V_52 , V_181 ) ;
}
void F_119 ( struct V_172 * V_172 , struct V_70 * V_70 ,
struct V_188 * V_189 , T_1 V_45 ,
T_1 * V_46 )
{
struct V_1 * V_2 = F_111 ( V_172 -> V_176 ) ;
struct V_51 V_52 ;
struct V_190 V_191 ;
F_31 ( V_45 == V_48 ) ;
F_120 ( V_2 , V_189 -> V_187 , & V_191 ) ;
F_118 ( & V_52 , V_189 -> V_187 , V_189 -> V_192 , V_191 . V_193 ) ;
F_112 ( V_2 , V_70 , V_45 ,
V_46 , & V_52 , V_170 ) ;
}
void F_121 ( struct V_1 * V_2 , struct V_70 * V_70 ,
T_1 V_194 )
{
F_95 ( V_2 , V_70 , V_194 , V_170 ) ;
}
void F_122 ( struct V_1 * V_2 ,
struct V_70 * V_70 , struct V_51 * V_52 ,
T_1 V_45 , T_1 V_46 )
{
struct V_29 * V_30 = F_25 ( V_2 ) ;
struct V_53 * V_54 ;
unsigned int V_4 , V_178 ;
struct V_11 * V_34 ;
int type ;
V_4 = F_29 ( V_2 , V_46 ) ;
V_34 = F_9 ( V_2 , V_4 ) ;
type = V_34 -> type ;
if ( V_34 -> V_16 == 0 && ! F_7 ( V_2 , V_4 ) ) {
if ( V_45 == V_48 )
type = V_61 ;
else
type = V_111 ;
}
V_54 = F_41 ( V_2 , type ) ;
F_3 ( & V_54 -> V_179 ) ;
F_3 ( & V_30 -> V_50 ) ;
V_178 = V_54 -> V_4 ;
if ( V_4 != V_54 -> V_4 ) {
V_54 -> V_76 = V_4 ;
F_68 ( V_2 , type , true ) ;
}
V_54 -> V_107 = F_30 ( V_2 , V_46 ) &
( V_2 -> V_20 - 1 ) ;
F_40 ( V_2 , type , V_52 , V_54 -> V_107 ) ;
F_38 ( V_2 , V_45 , V_46 ) ;
F_13 ( V_2 , V_178 ) ;
F_13 ( V_2 , F_29 ( V_2 , V_45 ) ) ;
F_15 ( & V_30 -> V_50 ) ;
F_15 ( & V_54 -> V_179 ) ;
}
void F_123 ( struct V_1 * V_2 ,
struct V_70 * V_70 , struct V_51 * V_52 ,
T_1 V_45 , T_1 V_46 )
{
struct V_29 * V_30 = F_25 ( V_2 ) ;
int type = V_123 ;
struct V_53 * V_54 ;
unsigned int V_4 , V_178 ;
T_1 V_195 = F_124 ( V_70 ) ;
unsigned int V_76 = F_29 ( V_2 , V_195 ) ;
V_54 = F_41 ( V_2 , type ) ;
F_3 ( & V_54 -> V_179 ) ;
F_3 ( & V_30 -> V_50 ) ;
V_4 = F_29 ( V_2 , V_46 ) ;
V_178 = V_54 -> V_4 ;
if ( V_4 != V_54 -> V_4 ) {
V_54 -> V_76 = V_4 ;
F_68 ( V_2 , type , true ) ;
}
V_54 -> V_107 = F_30 ( V_2 , V_46 ) &
( V_2 -> V_20 - 1 ) ;
F_40 ( V_2 , type , V_52 , V_54 -> V_107 ) ;
if ( V_76 != V_4 ) {
V_54 -> V_76 = V_76 ;
F_68 ( V_2 , type , true ) ;
}
V_54 -> V_107 = F_30 ( V_2 , V_195 ) &
( V_2 -> V_20 - 1 ) ;
F_116 ( V_70 ) ;
F_95 ( V_2 , V_70 , V_46 , V_181 ) ;
F_92 ( V_2 , V_181 , true ) ;
F_38 ( V_2 , V_45 , V_46 ) ;
F_13 ( V_2 , V_178 ) ;
F_13 ( V_2 , F_29 ( V_2 , V_45 ) ) ;
F_15 ( & V_30 -> V_50 ) ;
F_15 ( & V_54 -> V_179 ) ;
}
static int F_125 ( struct V_1 * V_2 )
{
struct V_196 * V_62 = F_126 ( V_2 ) ;
struct V_53 * V_197 ;
unsigned char * V_73 ;
struct V_70 * V_70 ;
T_1 V_115 ;
int V_58 , V_198 , V_21 ;
V_115 = F_127 ( V_2 ) ;
V_70 = F_45 ( V_2 , V_115 ++ ) ;
V_73 = ( unsigned char * ) F_49 ( V_70 ) ;
V_197 = F_41 ( V_2 , V_60 ) ;
memcpy ( & V_197 -> V_55 -> V_199 , V_73 , V_200 ) ;
V_197 = F_41 ( V_2 , V_61 ) ;
memcpy ( & V_197 -> V_55 -> V_201 , V_73 + V_200 ,
V_200 ) ;
V_21 = 2 * V_200 ;
for ( V_58 = V_60 ; V_58 <= V_61 ; V_58 ++ ) {
unsigned short V_202 ;
unsigned int V_4 ;
V_197 = F_41 ( V_2 , V_58 ) ;
V_4 = F_128 ( V_62 -> V_203 [ V_58 ] ) ;
V_202 = F_129 ( V_62 -> V_204 [ V_58 ] ) ;
V_197 -> V_76 = V_4 ;
F_62 ( V_2 , V_58 , 0 ) ;
V_197 -> V_63 = V_62 -> V_63 [ V_58 ] ;
V_197 -> V_107 = V_202 ;
if ( V_197 -> V_63 == V_64 )
V_202 = V_2 -> V_20 ;
for ( V_198 = 0 ; V_198 < V_202 ; V_198 ++ ) {
struct V_51 * V_205 ;
V_205 = (struct V_51 * ) ( V_73 + V_21 ) ;
V_197 -> V_55 -> V_206 [ V_198 ] = * V_205 ;
V_21 += V_65 ;
if ( V_21 + V_65 <= V_68 -
V_69 )
continue;
F_51 ( V_70 , 1 ) ;
V_70 = NULL ;
V_70 = F_45 ( V_2 , V_115 ++ ) ;
V_73 = ( unsigned char * ) F_49 ( V_70 ) ;
V_21 = 0 ;
}
}
F_51 ( V_70 , 1 ) ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 , int type )
{
struct V_196 * V_62 = F_126 ( V_2 ) ;
struct V_71 * V_52 ;
struct V_53 * V_54 ;
struct V_70 * V_207 ;
unsigned short V_202 ;
unsigned int V_4 = 0 ;
T_1 V_72 = 0 ;
if ( F_63 ( type ) ) {
V_4 = F_128 ( V_62 -> V_203 [ type ] ) ;
V_202 = F_129 ( V_62 -> V_204 [ type -
V_60 ] ) ;
if ( F_131 ( V_62 , V_208 ) )
V_72 = F_132 ( V_2 , V_103 , type ) ;
else
V_72 = F_132 ( V_2 , V_209 , type ) ;
} else {
V_4 = F_128 ( V_62 -> V_210 [ type -
V_171 ] ) ;
V_202 = F_129 ( V_62 -> V_211 [ type -
V_171 ] ) ;
if ( F_131 ( V_62 , V_208 ) )
V_72 = F_132 ( V_2 , V_212 ,
type - V_171 ) ;
else
V_72 = F_46 ( V_2 , V_4 ) ;
}
V_207 = F_45 ( V_2 , V_72 ) ;
V_52 = (struct V_71 * ) F_49 ( V_207 ) ;
if ( F_53 ( type ) ) {
if ( F_131 ( V_62 , V_208 ) ) {
struct V_51 * V_213 = & V_52 -> V_206 [ 0 ] ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_20 ; V_58 ++ , V_213 ++ ) {
V_213 -> V_193 = 0 ;
V_213 -> V_192 = 0 ;
}
} else {
if ( F_133 ( V_2 , V_4 , V_52 ) ) {
F_51 ( V_207 , 1 ) ;
return - V_214 ;
}
}
}
V_54 = F_41 ( V_2 , type ) ;
F_3 ( & V_54 -> V_179 ) ;
memcpy ( V_54 -> V_55 , V_52 , V_68 ) ;
V_54 -> V_76 = V_4 ;
F_62 ( V_2 , type , 0 ) ;
V_54 -> V_63 = V_62 -> V_63 [ type ] ;
V_54 -> V_107 = V_202 ;
F_15 ( & V_54 -> V_179 ) ;
F_51 ( V_207 , 1 ) ;
return 0 ;
}
static int F_134 ( struct V_1 * V_2 )
{
int type = V_60 ;
if ( F_131 ( F_126 ( V_2 ) , V_215 ) ) {
if ( F_125 ( V_2 ) )
return - V_214 ;
type = V_171 ;
}
for (; type <= V_175 ; type ++ )
if ( F_130 ( V_2 , type ) )
return - V_214 ;
return 0 ;
}
static void F_135 ( struct V_1 * V_2 , T_1 V_35 )
{
struct V_70 * V_70 ;
unsigned char * V_73 ;
struct V_51 * V_216 ;
struct V_53 * V_197 ;
int V_217 = 0 ;
int V_58 , V_198 ;
V_70 = F_48 ( V_2 , V_35 ++ ) ;
V_73 = ( unsigned char * ) F_49 ( V_70 ) ;
V_197 = F_41 ( V_2 , V_60 ) ;
memcpy ( V_73 , & V_197 -> V_55 -> V_199 , V_200 ) ;
V_217 += V_200 ;
V_197 = F_41 ( V_2 , V_61 ) ;
memcpy ( V_73 + V_217 , & V_197 -> V_55 -> V_201 ,
V_200 ) ;
V_217 += V_200 ;
F_50 ( V_70 ) ;
for ( V_58 = V_60 ; V_58 <= V_61 ; V_58 ++ ) {
unsigned short V_218 ;
V_197 = F_41 ( V_2 , V_58 ) ;
if ( V_2 -> V_62 -> V_63 [ V_58 ] == V_64 )
V_218 = V_2 -> V_20 ;
else
V_218 = F_43 ( V_2 , V_58 ) ;
for ( V_198 = 0 ; V_198 < V_218 ; V_198 ++ ) {
if ( ! V_70 ) {
V_70 = F_48 ( V_2 , V_35 ++ ) ;
V_73 = ( unsigned char * ) F_49 ( V_70 ) ;
V_217 = 0 ;
}
V_216 = (struct V_51 * ) ( V_73 + V_217 ) ;
* V_216 = V_197 -> V_55 -> V_206 [ V_198 ] ;
V_217 += V_65 ;
F_50 ( V_70 ) ;
if ( V_217 + V_65 <= V_68 -
V_69 )
continue;
F_51 ( V_70 , 1 ) ;
V_70 = NULL ;
}
}
if ( V_70 )
F_51 ( V_70 , 1 ) ;
}
static void F_136 ( struct V_1 * V_2 ,
T_1 V_35 , int type )
{
int V_58 , V_219 ;
if ( F_63 ( type ) )
V_219 = type + V_209 ;
else
V_219 = type + V_212 ;
for ( V_58 = type ; V_58 < V_219 ; V_58 ++ ) {
struct V_53 * V_52 = F_41 ( V_2 , V_58 ) ;
F_3 ( & V_52 -> V_179 ) ;
F_47 ( V_2 , V_52 -> V_55 , V_35 + ( V_58 - type ) ) ;
F_15 ( & V_52 -> V_179 ) ;
}
}
void F_137 ( struct V_1 * V_2 , T_1 V_220 )
{
if ( F_131 ( F_126 ( V_2 ) , V_215 ) )
F_135 ( V_2 , V_220 ) ;
else
F_136 ( V_2 , V_220 , V_60 ) ;
}
void F_138 ( struct V_1 * V_2 , T_1 V_220 )
{
if ( F_131 ( F_126 ( V_2 ) , V_208 ) )
F_136 ( V_2 , V_220 , V_171 ) ;
return;
}
int F_139 ( struct V_71 * V_52 , int type ,
unsigned int V_221 , int V_222 )
{
int V_58 ;
if ( type == V_223 ) {
for ( V_58 = 0 ; V_58 < F_140 ( V_52 ) ; V_58 ++ ) {
if ( F_128 ( F_141 ( V_52 , V_58 ) ) == V_221 )
return V_58 ;
}
if ( V_222 && F_140 ( V_52 ) < V_224 )
return F_142 ( V_52 , 1 ) ;
} else if ( type == V_225 ) {
for ( V_58 = 0 ; V_58 < F_143 ( V_52 ) ; V_58 ++ )
if ( F_128 ( F_144 ( V_52 , V_58 ) ) == V_221 )
return V_58 ;
if ( V_222 && F_143 ( V_52 ) < V_226 )
return F_145 ( V_52 , 1 ) ;
}
return - 1 ;
}
static struct V_70 * F_146 ( struct V_1 * V_2 ,
unsigned int V_4 )
{
struct V_29 * V_30 = F_25 ( V_2 ) ;
unsigned int V_21 = F_147 ( V_30 , V_4 ) ;
T_1 V_72 = V_30 -> V_227 + V_21 ;
F_148 ( V_2 , V_4 ) ;
if ( F_36 ( V_21 , V_30 -> V_228 ) )
V_72 += V_30 -> V_229 ;
return F_45 ( V_2 , V_72 ) ;
}
static struct V_70 * F_149 ( struct V_1 * V_2 ,
unsigned int V_115 )
{
struct V_29 * V_30 = F_25 ( V_2 ) ;
struct V_70 * V_230 , * V_231 ;
T_2 V_232 , V_233 ;
void * V_234 , * V_235 ;
V_232 = F_150 ( V_2 , V_115 ) ;
V_233 = F_151 ( V_2 , V_232 ) ;
V_230 = F_45 ( V_2 , V_232 ) ;
V_231 = F_48 ( V_2 , V_233 ) ;
F_31 ( F_152 ( V_230 ) ) ;
V_234 = F_49 ( V_230 ) ;
V_235 = F_49 ( V_231 ) ;
memcpy ( V_235 , V_234 , V_68 ) ;
F_50 ( V_231 ) ;
F_51 ( V_230 , 1 ) ;
F_153 ( V_30 , V_115 ) ;
return V_231 ;
}
static bool F_154 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = F_41 ( V_2 , V_61 ) ;
struct V_71 * V_52 = V_54 -> V_55 ;
int V_58 ;
if ( F_143 ( V_52 ) >= V_226 ) {
for ( V_58 = F_143 ( V_52 ) - 1 ; V_58 >= 0 ; V_58 -- ) {
unsigned int V_4 ;
V_4 = F_128 ( F_144 ( V_52 , V_58 ) ) ;
F_24 ( V_2 , V_4 ) ;
}
F_145 ( V_52 , - F_143 ( V_52 ) ) ;
return 1 ;
}
return 0 ;
}
void F_155 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_25 ( V_2 ) ;
unsigned long * V_236 = V_30 -> V_31 ;
struct V_53 * V_54 = F_41 ( V_2 , V_61 ) ;
struct V_71 * V_52 = V_54 -> V_55 ;
unsigned long V_237 = F_17 ( V_2 ) ;
struct V_70 * V_70 = NULL ;
struct V_238 * V_239 = NULL ;
unsigned int V_115 = 0 , V_219 = 0 ;
unsigned int V_4 = - 1 ;
bool V_240 ;
F_3 ( & V_54 -> V_179 ) ;
F_3 ( & V_30 -> V_50 ) ;
V_240 = F_154 ( V_2 ) ;
while ( ( V_4 = F_18 ( V_236 , V_237 , V_4 + 1 ) ) < V_237 ) {
struct V_11 * V_34 = F_9 ( V_2 , V_4 ) ;
int V_241 , V_21 ;
V_241 = F_156 ( V_30 , V_4 ) ;
if ( V_240 )
goto V_242;
V_21 = F_139 ( V_52 , V_225 , V_4 , 1 ) ;
if ( V_21 >= 0 ) {
F_144 ( V_52 , V_21 ) = F_157 ( V_4 ) ;
F_158 ( V_34 , & F_159 ( V_52 , V_21 ) ) ;
goto V_243;
}
V_242:
if ( ! V_70 || ( V_115 > V_4 ) || ( V_4 > V_219 ) ) {
if ( V_70 ) {
F_51 ( V_70 , 1 ) ;
V_70 = NULL ;
}
V_115 = F_160 ( V_30 , V_4 ) ;
V_219 = V_115 + V_244 - 1 ;
V_70 = F_149 ( V_2 , V_115 ) ;
V_239 = F_49 ( V_70 ) ;
}
F_158 ( V_34 , & V_239 -> V_206 [ V_241 ] ) ;
V_243:
F_161 ( V_4 , V_236 ) ;
V_30 -> V_32 -- ;
}
F_15 ( & V_30 -> V_50 ) ;
F_15 ( & V_54 -> V_179 ) ;
F_51 ( V_70 , 1 ) ;
F_16 ( V_2 ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_245 * V_246 = F_163 ( V_2 ) ;
struct V_196 * V_62 = F_126 ( V_2 ) ;
struct V_29 * V_30 ;
unsigned int V_247 , V_115 ;
char * V_248 , * V_249 ;
unsigned int V_250 ;
V_30 = F_164 ( sizeof( struct V_29 ) , V_251 ) ;
if ( ! V_30 )
return - V_252 ;
F_165 ( V_2 ) -> V_29 = V_30 ;
V_30 -> V_253 = F_166 ( F_17 ( V_2 ) * sizeof( struct V_11 ) ) ;
if ( ! V_30 -> V_253 )
return - V_252 ;
V_250 = F_167 ( F_17 ( V_2 ) ) ;
V_30 -> V_31 = F_164 ( V_250 , V_251 ) ;
if ( ! V_30 -> V_31 )
return - V_252 ;
for ( V_115 = 0 ; V_115 < F_17 ( V_2 ) ; V_115 ++ ) {
V_30 -> V_253 [ V_115 ] . V_40
= F_164 ( V_254 , V_251 ) ;
V_30 -> V_253 [ V_115 ] . V_41
= F_164 ( V_254 , V_251 ) ;
if ( ! V_30 -> V_253 [ V_115 ] . V_40
|| ! V_30 -> V_253 [ V_115 ] . V_41 )
return - V_252 ;
}
if ( V_2 -> V_44 > 1 ) {
V_30 -> V_255 = F_166 ( V_2 -> V_85 *
sizeof( struct V_256 ) ) ;
if ( ! V_30 -> V_255 )
return - V_252 ;
}
V_247 = F_128 ( V_246 -> V_257 ) >> 1 ;
V_250 = F_168 ( V_2 , V_258 ) ;
V_248 = F_169 ( V_2 , V_258 ) ;
V_249 = F_164 ( V_250 , V_251 ) ;
if ( ! V_249 )
return - V_252 ;
memcpy ( V_249 , V_248 , V_250 ) ;
V_30 -> V_126 = & V_259 ;
V_30 -> V_227 = F_128 ( V_246 -> V_260 ) ;
V_30 -> V_229 = V_247 << V_2 -> V_27 ;
V_30 -> V_43 = F_170 ( V_62 -> V_261 ) ;
V_30 -> V_228 = V_249 ;
V_30 -> V_250 = V_250 ;
V_30 -> V_32 = 0 ;
V_30 -> V_262 = V_244 ;
V_30 -> V_263 = F_170 ( V_2 -> V_62 -> V_263 ) ;
V_30 -> V_264 = V_265 . V_266 ;
F_171 ( & V_30 -> V_50 ) ;
return 0 ;
}
static int F_172 ( struct V_1 * V_2 )
{
struct V_267 * V_268 = F_165 ( V_2 ) ;
struct V_82 * V_83 ;
unsigned int V_250 , V_269 ;
V_83 = F_164 ( sizeof( struct V_82 ) , V_251 ) ;
if ( ! V_83 )
return - V_252 ;
F_165 ( V_2 ) -> V_270 = V_83 ;
V_250 = F_167 ( F_17 ( V_2 ) ) ;
V_83 -> V_96 = F_85 ( V_250 , V_251 ) ;
if ( ! V_83 -> V_96 )
return - V_252 ;
V_269 = F_167 ( V_2 -> V_85 ) ;
V_83 -> V_99 = F_85 ( V_269 , V_251 ) ;
if ( ! V_83 -> V_99 )
return - V_252 ;
memset ( V_83 -> V_96 , 0xff , V_250 ) ;
memset ( V_83 -> V_99 , 0xff , V_269 ) ;
V_83 -> V_271 =
( unsigned int ) F_173 ( V_2 , V_268 -> V_272 ) ;
V_83 -> V_273 = 0 ;
V_83 -> V_274 = 0 ;
F_174 ( & V_83 -> V_95 ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 )
{
struct V_53 * V_275 ;
int V_58 ;
V_275 = F_164 ( sizeof( * V_275 ) * V_103 , V_251 ) ;
if ( ! V_275 )
return - V_252 ;
F_165 ( V_2 ) -> V_276 = V_275 ;
for ( V_58 = 0 ; V_58 < V_103 ; V_58 ++ ) {
F_171 ( & V_275 [ V_58 ] . V_179 ) ;
V_275 [ V_58 ] . V_55 = F_164 ( V_68 , V_251 ) ;
if ( ! V_275 [ V_58 ] . V_55 )
return - V_252 ;
V_275 [ V_58 ] . V_4 = V_17 ;
V_275 [ V_58 ] . V_107 = 0 ;
}
return F_134 ( V_2 ) ;
}
static void F_176 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_25 ( V_2 ) ;
struct V_53 * V_54 = F_41 ( V_2 , V_61 ) ;
struct V_71 * V_52 = V_54 -> V_55 ;
unsigned int V_115 ;
for ( V_115 = 0 ; V_115 < F_17 ( V_2 ) ; V_115 ++ ) {
struct V_11 * V_34 = & V_30 -> V_253 [ V_115 ] ;
struct V_238 * V_277 ;
struct V_278 V_279 ;
struct V_70 * V_70 ;
int V_58 ;
F_3 ( & V_54 -> V_179 ) ;
for ( V_58 = 0 ; V_58 < F_143 ( V_52 ) ; V_58 ++ ) {
if ( F_128 ( F_144 ( V_52 , V_58 ) ) == V_115 ) {
V_279 = F_159 ( V_52 , V_58 ) ;
F_15 ( & V_54 -> V_179 ) ;
goto V_97;
}
}
F_15 ( & V_54 -> V_179 ) ;
V_70 = F_146 ( V_2 , V_115 ) ;
V_277 = (struct V_238 * ) F_49 ( V_70 ) ;
V_279 = V_277 -> V_206 [ F_156 ( V_30 , V_115 ) ] ;
F_51 ( V_70 , 1 ) ;
V_97:
F_177 ( V_2 , V_115 , & V_279 ) ;
F_178 ( V_34 , & V_279 ) ;
if ( V_2 -> V_44 > 1 ) {
struct V_256 * V_280 = F_37 ( V_2 , V_115 ) ;
V_280 -> V_16 += V_34 -> V_16 ;
}
}
}
static void F_179 ( struct V_1 * V_2 )
{
unsigned int V_115 ;
int type ;
for ( V_115 = 0 ; V_115 < F_17 ( V_2 ) ; V_115 ++ ) {
struct V_11 * V_12 = F_9 ( V_2 , V_115 ) ;
if ( ! V_12 -> V_16 )
F_180 ( V_2 , V_115 ) ;
}
for ( type = V_60 ; type <= V_175 ; type ++ ) {
struct V_53 * V_281 = F_41 ( V_2 , type ) ;
F_69 ( V_2 , V_281 -> V_4 ) ;
}
}
static void F_181 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
struct V_82 * V_83 = F_56 ( V_2 ) ;
unsigned int V_4 = 0 , V_21 = 0 ;
unsigned short V_16 ;
while ( V_4 < F_17 ( V_2 ) ) {
V_4 = F_182 ( V_83 , F_17 ( V_2 ) , V_21 ) ;
if ( V_4 >= F_17 ( V_2 ) )
break;
V_21 = V_4 + 1 ;
V_16 = F_14 ( V_2 , V_4 , 0 ) ;
if ( V_16 >= V_2 -> V_20 || ! V_16 )
continue;
F_3 ( & V_7 -> V_18 ) ;
F_5 ( V_2 , V_4 , V_10 ) ;
F_15 ( & V_7 -> V_18 ) ;
}
}
static int F_183 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
unsigned int V_250 = F_167 ( F_17 ( V_2 ) ) ;
V_7 -> V_13 [ V_14 ] = F_164 ( V_250 , V_251 ) ;
V_7 -> V_13 [ V_15 ] = F_164 ( V_250 , V_251 ) ;
if ( ! V_7 -> V_13 [ V_14 ] || ! V_7 -> V_13 [ V_15 ] )
return - V_252 ;
return 0 ;
}
static int F_184 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
unsigned int V_250 , V_58 ;
V_7 = F_164 ( sizeof( struct V_6 ) , V_251 ) ;
if ( ! V_7 )
return - V_252 ;
F_165 ( V_2 ) -> V_282 = V_7 ;
F_171 ( & V_7 -> V_18 ) ;
V_250 = F_167 ( F_17 ( V_2 ) ) ;
for ( V_58 = 0 ; V_58 < V_283 ; V_58 ++ ) {
V_7 -> V_8 [ V_58 ] = F_164 ( V_250 , V_251 ) ;
if ( ! V_7 -> V_8 [ V_58 ] )
return - V_252 ;
}
F_181 ( V_2 ) ;
return F_183 ( V_2 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_25 ( V_2 ) ;
unsigned int V_4 ;
F_3 ( & V_30 -> V_50 ) ;
V_30 -> V_284 = V_285 ;
for ( V_4 = 0 ; V_4 < F_17 ( V_2 ) ; V_4 += V_2 -> V_44 ) {
unsigned int V_58 ;
unsigned long long V_38 = 0 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_44 ; V_58 ++ )
V_38 += F_9 ( V_2 , V_4 + V_58 ) -> V_38 ;
V_38 = F_186 ( V_38 , V_2 -> V_44 ) ;
if ( V_30 -> V_284 > V_38 )
V_30 -> V_284 = V_38 ;
}
V_30 -> V_39 = F_32 ( V_2 ) ;
F_15 ( & V_30 -> V_50 ) ;
}
int F_187 ( struct V_1 * V_2 )
{
struct V_245 * V_246 = F_163 ( V_2 ) ;
struct V_196 * V_62 = F_126 ( V_2 ) ;
struct V_267 * V_268 ;
int V_129 ;
V_268 = F_164 ( sizeof( struct V_267 ) , V_251 ) ;
if ( ! V_268 )
return - V_252 ;
V_2 -> V_268 = V_268 ;
F_188 ( & V_268 -> V_286 ) ;
F_189 ( & V_268 -> V_287 ) ;
V_268 -> V_288 = F_128 ( V_246 -> V_289 ) ;
V_268 -> V_272 = F_128 ( V_246 -> V_272 ) ;
V_268 -> V_124 = F_128 ( V_246 -> V_124 ) ;
V_268 -> V_290 = F_128 ( V_62 -> V_291 ) ;
V_268 -> V_292 = F_128 ( V_62 -> V_293 ) ;
V_268 -> V_294 = F_128 ( V_246 -> V_295 ) ;
V_268 -> V_296 = F_128 ( V_246 -> V_296 ) ;
V_129 = F_162 ( V_2 ) ;
if ( V_129 )
return V_129 ;
V_129 = F_172 ( V_2 ) ;
if ( V_129 )
return V_129 ;
V_129 = F_175 ( V_2 ) ;
if ( V_129 )
return V_129 ;
F_176 ( V_2 ) ;
F_179 ( V_2 ) ;
V_129 = F_184 ( V_2 ) ;
if ( V_129 )
return V_129 ;
F_185 ( V_2 ) ;
return 0 ;
}
static void F_190 ( struct V_1 * V_2 ,
enum V_5 V_5 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
F_3 ( & V_7 -> V_18 ) ;
F_82 ( V_7 -> V_8 [ V_5 ] ) ;
V_7 -> V_9 [ V_5 ] = 0 ;
F_15 ( & V_7 -> V_18 ) ;
}
void F_191 ( struct V_1 * V_2 )
{
unsigned int V_250 = F_167 ( F_17 ( V_2 ) ) ;
memset ( F_6 ( V_2 ) -> V_13 [ V_14 ] , 0 , V_250 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
F_82 ( V_7 -> V_13 [ V_14 ] ) ;
F_82 ( V_7 -> V_13 [ V_15 ] ) ;
}
static void F_193 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
int V_58 ;
if ( ! V_7 )
return;
for ( V_58 = 0 ; V_58 < V_283 ; V_58 ++ )
F_190 ( V_2 , V_58 ) ;
F_192 ( V_2 ) ;
F_165 ( V_2 ) -> V_282 = NULL ;
F_82 ( V_7 ) ;
}
static void F_194 ( struct V_1 * V_2 )
{
struct V_53 * V_275 = F_165 ( V_2 ) -> V_276 ;
int V_58 ;
if ( ! V_275 )
return;
F_165 ( V_2 ) -> V_276 = NULL ;
for ( V_58 = 0 ; V_58 < V_103 ; V_58 ++ )
F_82 ( V_275 [ V_58 ] . V_55 ) ;
F_82 ( V_275 ) ;
}
static void F_195 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = F_165 ( V_2 ) -> V_270 ;
if ( ! V_83 )
return;
F_165 ( V_2 ) -> V_270 = NULL ;
F_82 ( V_83 -> V_96 ) ;
F_82 ( V_83 -> V_99 ) ;
F_82 ( V_83 ) ;
}
static void F_196 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_25 ( V_2 ) ;
unsigned int V_115 ;
if ( ! V_30 )
return;
if ( V_30 -> V_253 ) {
for ( V_115 = 0 ; V_115 < F_17 ( V_2 ) ; V_115 ++ ) {
F_82 ( V_30 -> V_253 [ V_115 ] . V_40 ) ;
F_82 ( V_30 -> V_253 [ V_115 ] . V_41 ) ;
}
}
F_197 ( V_30 -> V_253 ) ;
F_197 ( V_30 -> V_255 ) ;
F_82 ( V_30 -> V_31 ) ;
F_165 ( V_2 ) -> V_29 = NULL ;
F_82 ( V_30 -> V_228 ) ;
F_82 ( V_30 ) ;
}
void F_198 ( struct V_1 * V_2 )
{
struct V_267 * V_268 = F_165 ( V_2 ) ;
F_193 ( V_2 ) ;
F_194 ( V_2 ) ;
F_195 ( V_2 ) ;
F_196 ( V_2 ) ;
V_2 -> V_268 = NULL ;
F_82 ( V_268 ) ;
}
