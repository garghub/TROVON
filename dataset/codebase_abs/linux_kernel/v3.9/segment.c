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
if ( F_2 ( V_2 , 0 ) )
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
static int F_70 ( struct V_1 * V_2 , int type )
{
struct V_53 * V_54 = F_41 ( V_2 , type ) ;
const struct V_121 * V_122 = F_6 ( V_2 ) -> V_122 ;
if ( F_53 ( type ) || ! F_2 ( V_2 , 0 ) )
return V_122 -> V_123 ( V_2 ,
& ( V_54 ) -> V_76 , V_15 , type , V_64 ) ;
for (; type >= V_60 ; type -- )
if ( V_122 -> V_123 ( V_2 , & ( V_54 ) -> V_76 ,
V_15 , type , V_64 ) )
return 1 ;
return 0 ;
}
static void F_71 ( struct V_1 * V_2 ,
int type , bool V_124 )
{
struct V_53 * V_54 = F_41 ( V_2 , type ) ;
unsigned int V_74 ;
if ( V_124 ) {
F_65 ( V_2 , type , true ) ;
goto V_125;
}
V_74 = F_72 ( V_2 ) ? 1 : V_2 -> V_44 ;
V_54 -> V_76 = F_52 ( V_2 , V_74 , type ) ;
if ( V_54 -> V_76 != V_17 )
F_68 ( V_2 , type , false ) ;
else if ( type == V_126 )
F_65 ( V_2 , type , false ) ;
else if ( F_72 ( V_2 ) && F_70 ( V_2 , type ) )
F_68 ( V_2 , type , true ) ;
else
F_65 ( V_2 , type , false ) ;
V_125:
V_2 -> V_127 [ V_54 -> V_63 ] ++ ;
}
void F_73 ( struct V_1 * V_2 )
{
struct V_53 * V_54 ;
unsigned int V_128 ;
int V_58 ;
for ( V_58 = V_60 ; V_58 <= V_61 ; V_58 ++ ) {
V_54 = F_41 ( V_2 , V_58 ) ;
V_128 = V_54 -> V_4 ;
F_25 ( V_2 ) -> V_129 -> V_130 ( V_2 , V_58 , true ) ;
F_13 ( V_2 , V_128 ) ;
}
}
static void F_74 ( struct V_131 * V_131 , int V_132 )
{
const int V_133 = F_59 ( V_134 , & V_131 -> V_135 ) ;
struct V_136 * V_137 = V_131 -> V_138 + V_131 -> V_139 - 1 ;
struct V_140 * V_141 = V_131 -> V_142 ;
do {
struct V_70 * V_70 = V_137 -> V_143 ;
if ( -- V_137 >= V_131 -> V_138 )
F_75 ( & V_137 -> V_143 -> V_144 ) ;
if ( ! V_133 ) {
F_76 ( V_70 ) ;
if ( V_70 -> V_145 )
F_77 ( V_146 , & V_70 -> V_145 -> V_144 ) ;
F_78 ( V_141 -> V_2 -> V_62 , V_147 ) ;
V_141 -> V_2 -> V_24 -> V_148 |= V_149 ;
}
F_79 ( V_70 ) ;
F_80 ( V_141 -> V_2 , V_150 ) ;
} while ( V_137 >= V_131 -> V_138 );
if ( V_141 -> V_151 )
F_81 ( V_141 -> V_152 ) ;
F_82 ( V_141 ) ;
F_83 ( V_131 ) ;
}
struct V_131 * F_84 ( struct V_153 * V_154 , int V_155 )
{
struct V_131 * V_131 ;
struct V_140 * V_156 ;
V_157:
V_156 = F_85 ( sizeof( struct V_140 ) , V_28 ) ;
if ( ! V_156 ) {
F_86 () ;
goto V_157;
}
V_131 = F_87 ( V_158 , V_155 ) ;
V_131 -> V_159 = V_154 ;
V_131 -> V_142 = V_156 ;
return V_131 ;
}
static void F_88 ( struct V_1 * V_2 ,
enum V_160 type , bool V_161 )
{
int V_162 = V_161 ? V_163 : V_164 ;
enum V_160 V_165 = type > V_166 ? V_166 : type ;
if ( type >= V_167 )
V_162 = V_168 ;
if ( V_2 -> V_131 [ V_165 ] ) {
struct V_140 * V_141 = V_2 -> V_131 [ V_165 ] -> V_142 ;
V_141 -> V_2 = V_2 ;
V_2 -> V_131 [ V_165 ] -> V_169 = F_74 ;
if ( type == V_167 ) {
F_89 ( V_152 ) ;
V_141 -> V_151 = true ;
V_141 -> V_152 = & V_152 ;
F_90 ( V_162 , V_2 -> V_131 [ V_165 ] ) ;
F_91 ( & V_152 ) ;
} else {
V_141 -> V_151 = false ;
F_90 ( V_162 , V_2 -> V_131 [ V_165 ] ) ;
}
V_2 -> V_131 [ V_165 ] = NULL ;
}
}
void F_92 ( struct V_1 * V_2 , enum V_160 type , bool V_161 )
{
F_93 ( & V_2 -> V_170 ) ;
F_88 ( V_2 , type , V_161 ) ;
F_94 ( & V_2 -> V_170 ) ;
}
static void F_95 ( struct V_1 * V_2 , struct V_70 * V_70 ,
T_1 V_72 , enum V_160 type )
{
struct V_153 * V_154 = V_2 -> V_24 -> V_25 ;
F_96 ( V_2 , V_72 ) ;
F_93 ( & V_2 -> V_170 ) ;
F_97 ( V_2 , V_150 ) ;
if ( V_2 -> V_131 [ type ] && V_2 -> V_171 [ type ] != V_72 - 1 )
F_88 ( V_2 , type , false ) ;
V_172:
if ( V_2 -> V_131 [ type ] == NULL ) {
V_2 -> V_131 [ type ] = F_84 ( V_154 , F_98 ( V_154 ) ) ;
V_2 -> V_131 [ type ] -> V_173 = F_99 ( V_2 , V_72 ) ;
}
if ( F_100 ( V_2 -> V_131 [ type ] , V_70 , V_68 , 0 ) <
V_68 ) {
F_88 ( V_2 , type , false ) ;
goto V_172;
}
V_2 -> V_171 [ type ] = V_72 ;
F_94 ( & V_2 -> V_170 ) ;
}
static bool F_101 ( struct V_1 * V_2 , int type )
{
struct V_53 * V_54 = F_41 ( V_2 , type ) ;
if ( V_54 -> V_107 < V_2 -> V_20 )
return true ;
return false ;
}
static int F_102 ( struct V_70 * V_70 , enum V_160 V_174 )
{
if ( V_174 == V_175 )
return V_60 ;
else
return V_176 ;
}
static int F_103 ( struct V_70 * V_70 , enum V_160 V_174 )
{
if ( V_174 == V_175 ) {
struct V_177 * V_177 = V_70 -> V_145 -> V_178 ;
if ( F_104 ( V_177 -> V_179 ) )
return V_60 ;
else
return V_61 ;
} else {
if ( F_105 ( V_70 ) && ! F_106 ( V_70 ) )
return V_176 ;
else
return V_180 ;
}
}
static int F_107 ( struct V_70 * V_70 , enum V_160 V_174 )
{
if ( V_174 == V_175 ) {
struct V_177 * V_177 = V_70 -> V_145 -> V_178 ;
if ( F_104 ( V_177 -> V_179 ) )
return V_60 ;
else if ( F_108 ( V_70 ) || F_109 ( V_177 ) )
return V_61 ;
else
return V_111 ;
} else {
if ( F_105 ( V_70 ) )
return F_106 ( V_70 ) ? V_126 :
V_176 ;
else
return V_180 ;
}
}
static int F_110 ( struct V_70 * V_70 , enum V_160 V_174 )
{
struct V_1 * V_2 = F_111 ( V_70 -> V_145 -> V_178 -> V_181 ) ;
switch ( V_2 -> V_182 ) {
case 2 :
return F_102 ( V_70 , V_174 ) ;
case 4 :
return F_103 ( V_70 , V_174 ) ;
}
F_31 ( V_2 -> V_182 != V_103 ) ;
return F_107 ( V_70 , V_174 ) ;
}
static void F_112 ( struct V_1 * V_2 , struct V_70 * V_70 ,
T_1 V_45 , T_1 * V_46 ,
struct V_51 * V_52 , enum V_160 V_174 )
{
struct V_29 * V_30 = F_25 ( V_2 ) ;
struct V_53 * V_54 ;
unsigned int V_183 ;
int type ;
type = F_110 ( V_70 , V_174 ) ;
V_54 = F_41 ( V_2 , type ) ;
F_3 ( & V_54 -> V_184 ) ;
* V_46 = F_113 ( V_2 , V_54 ) ;
V_183 = V_54 -> V_4 ;
F_40 ( V_2 , type , V_52 , V_54 -> V_107 ) ;
F_3 ( & V_30 -> V_50 ) ;
F_67 ( V_2 , V_54 ) ;
V_2 -> V_185 [ V_54 -> V_63 ] ++ ;
F_38 ( V_2 , V_45 , * V_46 ) ;
if ( ! F_101 ( V_2 , type ) )
V_30 -> V_129 -> V_130 ( V_2 , type , false ) ;
F_13 ( V_2 , V_183 ) ;
F_13 ( V_2 , F_29 ( V_2 , V_45 ) ) ;
F_15 ( & V_30 -> V_50 ) ;
if ( V_174 == V_186 )
F_114 ( V_70 , F_113 ( V_2 , V_54 ) ) ;
F_95 ( V_2 , V_70 , * V_46 , V_174 ) ;
F_15 ( & V_54 -> V_184 ) ;
}
void F_115 ( struct V_1 * V_2 , struct V_70 * V_70 )
{
F_116 ( V_70 ) ;
F_95 ( V_2 , V_70 , V_70 -> V_187 , V_166 ) ;
}
void F_117 ( struct V_1 * V_2 , struct V_70 * V_70 ,
unsigned int V_188 , T_1 V_45 , T_1 * V_46 )
{
struct V_51 V_52 ;
F_118 ( & V_52 , V_188 , 0 , 0 ) ;
F_112 ( V_2 , V_70 , V_45 , V_46 , & V_52 , V_186 ) ;
}
void F_119 ( struct V_177 * V_177 , struct V_70 * V_70 ,
struct V_189 * V_190 , T_1 V_45 ,
T_1 * V_46 )
{
struct V_1 * V_2 = F_111 ( V_177 -> V_181 ) ;
struct V_51 V_52 ;
struct V_191 V_192 ;
F_31 ( V_45 == V_48 ) ;
F_120 ( V_2 , V_190 -> V_188 , & V_192 ) ;
F_118 ( & V_52 , V_190 -> V_188 , V_190 -> V_193 , V_192 . V_194 ) ;
F_112 ( V_2 , V_70 , V_45 ,
V_46 , & V_52 , V_175 ) ;
}
void F_121 ( struct V_1 * V_2 , struct V_70 * V_70 ,
T_1 V_195 )
{
F_95 ( V_2 , V_70 , V_195 , V_175 ) ;
}
void F_122 ( struct V_1 * V_2 ,
struct V_70 * V_70 , struct V_51 * V_52 ,
T_1 V_45 , T_1 V_46 )
{
struct V_29 * V_30 = F_25 ( V_2 ) ;
struct V_53 * V_54 ;
unsigned int V_4 , V_183 ;
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
F_3 ( & V_54 -> V_184 ) ;
F_3 ( & V_30 -> V_50 ) ;
V_183 = V_54 -> V_4 ;
if ( V_4 != V_54 -> V_4 ) {
V_54 -> V_76 = V_4 ;
F_68 ( V_2 , type , true ) ;
}
V_54 -> V_107 = F_30 ( V_2 , V_46 ) &
( V_2 -> V_20 - 1 ) ;
F_40 ( V_2 , type , V_52 , V_54 -> V_107 ) ;
F_38 ( V_2 , V_45 , V_46 ) ;
F_13 ( V_2 , V_183 ) ;
F_13 ( V_2 , F_29 ( V_2 , V_45 ) ) ;
F_15 ( & V_30 -> V_50 ) ;
F_15 ( & V_54 -> V_184 ) ;
}
void F_123 ( struct V_1 * V_2 ,
struct V_70 * V_70 , struct V_51 * V_52 ,
T_1 V_45 , T_1 V_46 )
{
struct V_29 * V_30 = F_25 ( V_2 ) ;
int type = V_126 ;
struct V_53 * V_54 ;
unsigned int V_4 , V_183 ;
T_1 V_196 = F_124 ( V_70 ) ;
unsigned int V_76 = F_29 ( V_2 , V_196 ) ;
V_54 = F_41 ( V_2 , type ) ;
F_3 ( & V_54 -> V_184 ) ;
F_3 ( & V_30 -> V_50 ) ;
V_4 = F_29 ( V_2 , V_46 ) ;
V_183 = V_54 -> V_4 ;
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
V_54 -> V_107 = F_30 ( V_2 , V_196 ) &
( V_2 -> V_20 - 1 ) ;
F_116 ( V_70 ) ;
F_95 ( V_2 , V_70 , V_46 , V_186 ) ;
F_92 ( V_2 , V_186 , true ) ;
F_38 ( V_2 , V_45 , V_46 ) ;
F_13 ( V_2 , V_183 ) ;
F_13 ( V_2 , F_29 ( V_2 , V_45 ) ) ;
F_15 ( & V_30 -> V_50 ) ;
F_15 ( & V_54 -> V_184 ) ;
}
static int F_125 ( struct V_1 * V_2 )
{
struct V_197 * V_62 = F_126 ( V_2 ) ;
struct V_53 * V_198 ;
unsigned char * V_73 ;
struct V_70 * V_70 ;
T_1 V_115 ;
int V_58 , V_199 , V_21 ;
V_115 = F_127 ( V_2 ) ;
V_70 = F_45 ( V_2 , V_115 ++ ) ;
V_73 = ( unsigned char * ) F_49 ( V_70 ) ;
V_198 = F_41 ( V_2 , V_60 ) ;
memcpy ( & V_198 -> V_55 -> V_200 , V_73 , V_201 ) ;
V_198 = F_41 ( V_2 , V_61 ) ;
memcpy ( & V_198 -> V_55 -> V_202 , V_73 + V_201 ,
V_201 ) ;
V_21 = 2 * V_201 ;
for ( V_58 = V_60 ; V_58 <= V_61 ; V_58 ++ ) {
unsigned short V_203 ;
unsigned int V_4 ;
V_198 = F_41 ( V_2 , V_58 ) ;
V_4 = F_128 ( V_62 -> V_204 [ V_58 ] ) ;
V_203 = F_129 ( V_62 -> V_205 [ V_58 ] ) ;
V_198 -> V_76 = V_4 ;
F_62 ( V_2 , V_58 , 0 ) ;
V_198 -> V_63 = V_62 -> V_63 [ V_58 ] ;
V_198 -> V_107 = V_203 ;
if ( V_198 -> V_63 == V_64 )
V_203 = V_2 -> V_20 ;
for ( V_199 = 0 ; V_199 < V_203 ; V_199 ++ ) {
struct V_51 * V_206 ;
V_206 = (struct V_51 * ) ( V_73 + V_21 ) ;
V_198 -> V_55 -> V_207 [ V_199 ] = * V_206 ;
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
struct V_197 * V_62 = F_126 ( V_2 ) ;
struct V_71 * V_52 ;
struct V_53 * V_54 ;
struct V_70 * V_208 ;
unsigned short V_203 ;
unsigned int V_4 = 0 ;
T_1 V_72 = 0 ;
if ( F_63 ( type ) ) {
V_4 = F_128 ( V_62 -> V_204 [ type ] ) ;
V_203 = F_129 ( V_62 -> V_205 [ type -
V_60 ] ) ;
if ( F_131 ( V_62 , V_209 ) )
V_72 = F_132 ( V_2 , V_103 , type ) ;
else
V_72 = F_132 ( V_2 , V_210 , type ) ;
} else {
V_4 = F_128 ( V_62 -> V_211 [ type -
V_176 ] ) ;
V_203 = F_129 ( V_62 -> V_212 [ type -
V_176 ] ) ;
if ( F_131 ( V_62 , V_209 ) )
V_72 = F_132 ( V_2 , V_213 ,
type - V_176 ) ;
else
V_72 = F_46 ( V_2 , V_4 ) ;
}
V_208 = F_45 ( V_2 , V_72 ) ;
V_52 = (struct V_71 * ) F_49 ( V_208 ) ;
if ( F_53 ( type ) ) {
if ( F_131 ( V_62 , V_209 ) ) {
struct V_51 * V_214 = & V_52 -> V_207 [ 0 ] ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_20 ; V_58 ++ , V_214 ++ ) {
V_214 -> V_194 = 0 ;
V_214 -> V_193 = 0 ;
}
} else {
if ( F_133 ( V_2 , V_4 , V_52 ) ) {
F_51 ( V_208 , 1 ) ;
return - V_215 ;
}
}
}
V_54 = F_41 ( V_2 , type ) ;
F_3 ( & V_54 -> V_184 ) ;
memcpy ( V_54 -> V_55 , V_52 , V_68 ) ;
V_54 -> V_76 = V_4 ;
F_62 ( V_2 , type , 0 ) ;
V_54 -> V_63 = V_62 -> V_63 [ type ] ;
V_54 -> V_107 = V_203 ;
F_15 ( & V_54 -> V_184 ) ;
F_51 ( V_208 , 1 ) ;
return 0 ;
}
static int F_134 ( struct V_1 * V_2 )
{
int type = V_60 ;
if ( F_131 ( F_126 ( V_2 ) , V_216 ) ) {
if ( F_125 ( V_2 ) )
return - V_215 ;
type = V_176 ;
}
for (; type <= V_180 ; type ++ )
if ( F_130 ( V_2 , type ) )
return - V_215 ;
return 0 ;
}
static void F_135 ( struct V_1 * V_2 , T_1 V_35 )
{
struct V_70 * V_70 ;
unsigned char * V_73 ;
struct V_51 * V_217 ;
struct V_53 * V_198 ;
int V_218 = 0 ;
int V_58 , V_199 ;
V_70 = F_48 ( V_2 , V_35 ++ ) ;
V_73 = ( unsigned char * ) F_49 ( V_70 ) ;
V_198 = F_41 ( V_2 , V_60 ) ;
memcpy ( V_73 , & V_198 -> V_55 -> V_200 , V_201 ) ;
V_218 += V_201 ;
V_198 = F_41 ( V_2 , V_61 ) ;
memcpy ( V_73 + V_218 , & V_198 -> V_55 -> V_202 ,
V_201 ) ;
V_218 += V_201 ;
F_50 ( V_70 ) ;
for ( V_58 = V_60 ; V_58 <= V_61 ; V_58 ++ ) {
unsigned short V_219 ;
V_198 = F_41 ( V_2 , V_58 ) ;
if ( V_2 -> V_62 -> V_63 [ V_58 ] == V_64 )
V_219 = V_2 -> V_20 ;
else
V_219 = F_43 ( V_2 , V_58 ) ;
for ( V_199 = 0 ; V_199 < V_219 ; V_199 ++ ) {
if ( ! V_70 ) {
V_70 = F_48 ( V_2 , V_35 ++ ) ;
V_73 = ( unsigned char * ) F_49 ( V_70 ) ;
V_218 = 0 ;
}
V_217 = (struct V_51 * ) ( V_73 + V_218 ) ;
* V_217 = V_198 -> V_55 -> V_207 [ V_199 ] ;
V_218 += V_65 ;
F_50 ( V_70 ) ;
if ( V_218 + V_65 <= V_68 -
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
int V_58 , V_220 ;
if ( F_63 ( type ) )
V_220 = type + V_210 ;
else
V_220 = type + V_213 ;
for ( V_58 = type ; V_58 < V_220 ; V_58 ++ ) {
struct V_53 * V_52 = F_41 ( V_2 , V_58 ) ;
F_3 ( & V_52 -> V_184 ) ;
F_47 ( V_2 , V_52 -> V_55 , V_35 + ( V_58 - type ) ) ;
F_15 ( & V_52 -> V_184 ) ;
}
}
void F_137 ( struct V_1 * V_2 , T_1 V_221 )
{
if ( F_131 ( F_126 ( V_2 ) , V_216 ) )
F_135 ( V_2 , V_221 ) ;
else
F_136 ( V_2 , V_221 , V_60 ) ;
}
void F_138 ( struct V_1 * V_2 , T_1 V_221 )
{
if ( F_131 ( F_126 ( V_2 ) , V_209 ) )
F_136 ( V_2 , V_221 , V_176 ) ;
return;
}
int F_139 ( struct V_71 * V_52 , int type ,
unsigned int V_222 , int V_223 )
{
int V_58 ;
if ( type == V_224 ) {
for ( V_58 = 0 ; V_58 < F_140 ( V_52 ) ; V_58 ++ ) {
if ( F_128 ( F_141 ( V_52 , V_58 ) ) == V_222 )
return V_58 ;
}
if ( V_223 && F_140 ( V_52 ) < V_225 )
return F_142 ( V_52 , 1 ) ;
} else if ( type == V_226 ) {
for ( V_58 = 0 ; V_58 < F_143 ( V_52 ) ; V_58 ++ )
if ( F_128 ( F_144 ( V_52 , V_58 ) ) == V_222 )
return V_58 ;
if ( V_223 && F_143 ( V_52 ) < V_227 )
return F_145 ( V_52 , 1 ) ;
}
return - 1 ;
}
static struct V_70 * F_146 ( struct V_1 * V_2 ,
unsigned int V_4 )
{
struct V_29 * V_30 = F_25 ( V_2 ) ;
unsigned int V_21 = F_147 ( V_30 , V_4 ) ;
T_1 V_72 = V_30 -> V_228 + V_21 ;
F_148 ( V_2 , V_4 ) ;
if ( F_36 ( V_21 , V_30 -> V_229 ) )
V_72 += V_30 -> V_230 ;
return F_45 ( V_2 , V_72 ) ;
}
static struct V_70 * F_149 ( struct V_1 * V_2 ,
unsigned int V_115 )
{
struct V_29 * V_30 = F_25 ( V_2 ) ;
struct V_70 * V_231 , * V_232 ;
T_2 V_233 , V_234 ;
void * V_235 , * V_236 ;
V_233 = F_150 ( V_2 , V_115 ) ;
V_234 = F_151 ( V_2 , V_233 ) ;
V_231 = F_45 ( V_2 , V_233 ) ;
V_232 = F_48 ( V_2 , V_234 ) ;
F_31 ( F_152 ( V_231 ) ) ;
V_235 = F_49 ( V_231 ) ;
V_236 = F_49 ( V_232 ) ;
memcpy ( V_236 , V_235 , V_68 ) ;
F_50 ( V_232 ) ;
F_51 ( V_231 , 1 ) ;
F_153 ( V_30 , V_115 ) ;
return V_232 ;
}
static bool F_154 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = F_41 ( V_2 , V_61 ) ;
struct V_71 * V_52 = V_54 -> V_55 ;
int V_58 ;
if ( F_143 ( V_52 ) >= V_227 ) {
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
unsigned long * V_237 = V_30 -> V_31 ;
struct V_53 * V_54 = F_41 ( V_2 , V_61 ) ;
struct V_71 * V_52 = V_54 -> V_55 ;
unsigned long V_238 = F_17 ( V_2 ) ;
struct V_70 * V_70 = NULL ;
struct V_239 * V_240 = NULL ;
unsigned int V_115 = 0 , V_220 = 0 ;
unsigned int V_4 = - 1 ;
bool V_241 ;
F_3 ( & V_54 -> V_184 ) ;
F_3 ( & V_30 -> V_50 ) ;
V_241 = F_154 ( V_2 ) ;
while ( ( V_4 = F_18 ( V_237 , V_238 , V_4 + 1 ) ) < V_238 ) {
struct V_11 * V_34 = F_9 ( V_2 , V_4 ) ;
int V_242 , V_21 ;
V_242 = F_156 ( V_30 , V_4 ) ;
if ( V_241 )
goto V_243;
V_21 = F_139 ( V_52 , V_226 , V_4 , 1 ) ;
if ( V_21 >= 0 ) {
F_144 ( V_52 , V_21 ) = F_157 ( V_4 ) ;
F_158 ( V_34 , & F_159 ( V_52 , V_21 ) ) ;
goto V_244;
}
V_243:
if ( ! V_70 || ( V_115 > V_4 ) || ( V_4 > V_220 ) ) {
if ( V_70 ) {
F_51 ( V_70 , 1 ) ;
V_70 = NULL ;
}
V_115 = F_160 ( V_30 , V_4 ) ;
V_220 = V_115 + V_245 - 1 ;
V_70 = F_149 ( V_2 , V_115 ) ;
V_240 = F_49 ( V_70 ) ;
}
F_158 ( V_34 , & V_240 -> V_207 [ V_242 ] ) ;
V_244:
F_161 ( V_4 , V_237 ) ;
V_30 -> V_32 -- ;
}
F_15 ( & V_30 -> V_50 ) ;
F_15 ( & V_54 -> V_184 ) ;
F_51 ( V_70 , 1 ) ;
F_16 ( V_2 ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_246 * V_247 = F_163 ( V_2 ) ;
struct V_197 * V_62 = F_126 ( V_2 ) ;
struct V_29 * V_30 ;
unsigned int V_248 , V_115 ;
char * V_249 , * V_250 ;
unsigned int V_251 ;
V_30 = F_164 ( sizeof( struct V_29 ) , V_252 ) ;
if ( ! V_30 )
return - V_253 ;
F_165 ( V_2 ) -> V_29 = V_30 ;
V_30 -> V_254 = F_166 ( F_17 ( V_2 ) * sizeof( struct V_11 ) ) ;
if ( ! V_30 -> V_254 )
return - V_253 ;
V_251 = F_167 ( F_17 ( V_2 ) ) ;
V_30 -> V_31 = F_164 ( V_251 , V_252 ) ;
if ( ! V_30 -> V_31 )
return - V_253 ;
for ( V_115 = 0 ; V_115 < F_17 ( V_2 ) ; V_115 ++ ) {
V_30 -> V_254 [ V_115 ] . V_40
= F_164 ( V_255 , V_252 ) ;
V_30 -> V_254 [ V_115 ] . V_41
= F_164 ( V_255 , V_252 ) ;
if ( ! V_30 -> V_254 [ V_115 ] . V_40
|| ! V_30 -> V_254 [ V_115 ] . V_41 )
return - V_253 ;
}
if ( V_2 -> V_44 > 1 ) {
V_30 -> V_256 = F_166 ( V_2 -> V_85 *
sizeof( struct V_257 ) ) ;
if ( ! V_30 -> V_256 )
return - V_253 ;
}
V_248 = F_128 ( V_247 -> V_258 ) >> 1 ;
V_251 = F_168 ( V_2 , V_259 ) ;
V_249 = F_169 ( V_2 , V_259 ) ;
V_250 = F_164 ( V_251 , V_252 ) ;
if ( ! V_250 )
return - V_253 ;
memcpy ( V_250 , V_249 , V_251 ) ;
V_30 -> V_129 = & V_260 ;
V_30 -> V_228 = F_128 ( V_247 -> V_261 ) ;
V_30 -> V_230 = V_248 << V_2 -> V_27 ;
V_30 -> V_43 = F_170 ( V_62 -> V_262 ) ;
V_30 -> V_229 = V_250 ;
V_30 -> V_251 = V_251 ;
V_30 -> V_32 = 0 ;
V_30 -> V_263 = V_245 ;
V_30 -> V_264 = F_170 ( V_2 -> V_62 -> V_264 ) ;
V_30 -> V_265 = V_266 . V_267 ;
F_171 ( & V_30 -> V_50 ) ;
return 0 ;
}
static int F_172 ( struct V_1 * V_2 )
{
struct V_268 * V_269 = F_165 ( V_2 ) ;
struct V_82 * V_83 ;
unsigned int V_251 , V_270 ;
V_83 = F_164 ( sizeof( struct V_82 ) , V_252 ) ;
if ( ! V_83 )
return - V_253 ;
F_165 ( V_2 ) -> V_271 = V_83 ;
V_251 = F_167 ( F_17 ( V_2 ) ) ;
V_83 -> V_96 = F_85 ( V_251 , V_252 ) ;
if ( ! V_83 -> V_96 )
return - V_253 ;
V_270 = F_167 ( V_2 -> V_85 ) ;
V_83 -> V_99 = F_85 ( V_270 , V_252 ) ;
if ( ! V_83 -> V_99 )
return - V_253 ;
memset ( V_83 -> V_96 , 0xff , V_251 ) ;
memset ( V_83 -> V_99 , 0xff , V_270 ) ;
V_83 -> V_272 =
( unsigned int ) F_173 ( V_2 , V_269 -> V_273 ) ;
V_83 -> V_274 = 0 ;
V_83 -> V_275 = 0 ;
F_174 ( & V_83 -> V_95 ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 )
{
struct V_53 * V_276 ;
int V_58 ;
V_276 = F_164 ( sizeof( * V_276 ) * V_103 , V_252 ) ;
if ( ! V_276 )
return - V_253 ;
F_165 ( V_2 ) -> V_277 = V_276 ;
for ( V_58 = 0 ; V_58 < V_103 ; V_58 ++ ) {
F_171 ( & V_276 [ V_58 ] . V_184 ) ;
V_276 [ V_58 ] . V_55 = F_164 ( V_68 , V_252 ) ;
if ( ! V_276 [ V_58 ] . V_55 )
return - V_253 ;
V_276 [ V_58 ] . V_4 = V_17 ;
V_276 [ V_58 ] . V_107 = 0 ;
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
struct V_11 * V_34 = & V_30 -> V_254 [ V_115 ] ;
struct V_239 * V_278 ;
struct V_279 V_280 ;
struct V_70 * V_70 ;
int V_58 ;
F_3 ( & V_54 -> V_184 ) ;
for ( V_58 = 0 ; V_58 < F_143 ( V_52 ) ; V_58 ++ ) {
if ( F_128 ( F_144 ( V_52 , V_58 ) ) == V_115 ) {
V_280 = F_159 ( V_52 , V_58 ) ;
F_15 ( & V_54 -> V_184 ) ;
goto V_97;
}
}
F_15 ( & V_54 -> V_184 ) ;
V_70 = F_146 ( V_2 , V_115 ) ;
V_278 = (struct V_239 * ) F_49 ( V_70 ) ;
V_280 = V_278 -> V_207 [ F_156 ( V_30 , V_115 ) ] ;
F_51 ( V_70 , 1 ) ;
V_97:
F_177 ( V_2 , V_115 , & V_280 ) ;
F_178 ( V_34 , & V_280 ) ;
if ( V_2 -> V_44 > 1 ) {
struct V_257 * V_281 = F_37 ( V_2 , V_115 ) ;
V_281 -> V_16 += V_34 -> V_16 ;
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
for ( type = V_60 ; type <= V_180 ; type ++ ) {
struct V_53 * V_282 = F_41 ( V_2 , type ) ;
F_69 ( V_2 , V_282 -> V_4 ) ;
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
unsigned int V_251 = F_167 ( F_17 ( V_2 ) ) ;
V_7 -> V_13 [ V_14 ] = F_164 ( V_251 , V_252 ) ;
V_7 -> V_13 [ V_15 ] = F_164 ( V_251 , V_252 ) ;
if ( ! V_7 -> V_13 [ V_14 ] || ! V_7 -> V_13 [ V_15 ] )
return - V_253 ;
return 0 ;
}
static int F_184 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
unsigned int V_251 , V_58 ;
V_7 = F_164 ( sizeof( struct V_6 ) , V_252 ) ;
if ( ! V_7 )
return - V_253 ;
F_165 ( V_2 ) -> V_283 = V_7 ;
F_171 ( & V_7 -> V_18 ) ;
V_251 = F_167 ( F_17 ( V_2 ) ) ;
for ( V_58 = 0 ; V_58 < V_284 ; V_58 ++ ) {
V_7 -> V_8 [ V_58 ] = F_164 ( V_251 , V_252 ) ;
if ( ! V_7 -> V_8 [ V_58 ] )
return - V_253 ;
}
F_181 ( V_2 ) ;
return F_183 ( V_2 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_25 ( V_2 ) ;
unsigned int V_4 ;
F_3 ( & V_30 -> V_50 ) ;
V_30 -> V_285 = V_286 ;
for ( V_4 = 0 ; V_4 < F_17 ( V_2 ) ; V_4 += V_2 -> V_44 ) {
unsigned int V_58 ;
unsigned long long V_38 = 0 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_44 ; V_58 ++ )
V_38 += F_9 ( V_2 , V_4 + V_58 ) -> V_38 ;
V_38 = F_186 ( V_38 , V_2 -> V_44 ) ;
if ( V_30 -> V_285 > V_38 )
V_30 -> V_285 = V_38 ;
}
V_30 -> V_39 = F_32 ( V_2 ) ;
F_15 ( & V_30 -> V_50 ) ;
}
int F_187 ( struct V_1 * V_2 )
{
struct V_246 * V_247 = F_163 ( V_2 ) ;
struct V_197 * V_62 = F_126 ( V_2 ) ;
struct V_268 * V_269 ;
int V_132 ;
V_269 = F_164 ( sizeof( struct V_268 ) , V_252 ) ;
if ( ! V_269 )
return - V_253 ;
V_2 -> V_269 = V_269 ;
F_188 ( & V_269 -> V_287 ) ;
F_189 ( & V_269 -> V_288 ) ;
V_269 -> V_289 = F_128 ( V_247 -> V_290 ) ;
V_269 -> V_273 = F_128 ( V_247 -> V_273 ) ;
V_269 -> V_127 = F_128 ( V_247 -> V_127 ) ;
V_269 -> V_291 = F_128 ( V_62 -> V_292 ) ;
V_269 -> V_293 = F_128 ( V_62 -> V_294 ) ;
V_269 -> V_295 = F_128 ( V_247 -> V_296 ) ;
V_269 -> V_297 = F_128 ( V_247 -> V_297 ) ;
V_132 = F_162 ( V_2 ) ;
if ( V_132 )
return V_132 ;
V_132 = F_172 ( V_2 ) ;
if ( V_132 )
return V_132 ;
V_132 = F_175 ( V_2 ) ;
if ( V_132 )
return V_132 ;
F_176 ( V_2 ) ;
F_179 ( V_2 ) ;
V_132 = F_184 ( V_2 ) ;
if ( V_132 )
return V_132 ;
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
unsigned int V_251 = F_167 ( F_17 ( V_2 ) ) ;
memset ( F_6 ( V_2 ) -> V_13 [ V_14 ] , 0 , V_251 ) ;
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
for ( V_58 = 0 ; V_58 < V_284 ; V_58 ++ )
F_190 ( V_2 , V_58 ) ;
F_192 ( V_2 ) ;
F_165 ( V_2 ) -> V_283 = NULL ;
F_82 ( V_7 ) ;
}
static void F_194 ( struct V_1 * V_2 )
{
struct V_53 * V_276 = F_165 ( V_2 ) -> V_277 ;
int V_58 ;
if ( ! V_276 )
return;
F_165 ( V_2 ) -> V_277 = NULL ;
for ( V_58 = 0 ; V_58 < V_103 ; V_58 ++ )
F_82 ( V_276 [ V_58 ] . V_55 ) ;
F_82 ( V_276 ) ;
}
static void F_195 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = F_165 ( V_2 ) -> V_271 ;
if ( ! V_83 )
return;
F_165 ( V_2 ) -> V_271 = NULL ;
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
if ( V_30 -> V_254 ) {
for ( V_115 = 0 ; V_115 < F_17 ( V_2 ) ; V_115 ++ ) {
F_82 ( V_30 -> V_254 [ V_115 ] . V_40 ) ;
F_82 ( V_30 -> V_254 [ V_115 ] . V_41 ) ;
}
}
F_197 ( V_30 -> V_254 ) ;
F_197 ( V_30 -> V_256 ) ;
F_82 ( V_30 -> V_31 ) ;
F_165 ( V_2 ) -> V_29 = NULL ;
F_82 ( V_30 -> V_229 ) ;
F_82 ( V_30 ) ;
}
void F_198 ( struct V_1 * V_2 )
{
struct V_268 * V_269 = F_165 ( V_2 ) ;
F_193 ( V_2 ) ;
F_194 ( V_2 ) ;
F_195 ( V_2 ) ;
F_196 ( V_2 ) ;
V_2 -> V_269 = NULL ;
F_82 ( V_269 ) ;
}
