int F_1 ( struct V_1 * V_2 ,
char * V_3 , int V_4 ,
unsigned int V_5 ,
unsigned int V_6 )
{
int V_7 ;
T_1 V_8 ;
struct V_9 V_10 ;
if ( V_2 -> V_11 == - 1 )
return - V_12 ;
if ( V_4 > V_2 -> V_13 )
V_4 = V_2 -> V_13 ;
V_10 . V_14 = F_2 ( V_5 ) ;
V_10 . V_15 = F_2 ( V_6 ) ;
V_8 = V_2 -> V_11 ;
V_7 = V_16 . V_17 ( ( char * ) & V_10 , sizeof( struct V_9 ) ,
& V_8 ) ;
if ( V_7 <= 0 ) {
F_3 ( L_1 , V_18 , V_7 ) ;
return V_7 ;
}
V_7 = V_16 . V_17 ( V_3 , V_4 , & V_8 ) ;
if ( V_7 <= 0 ) {
F_3 ( L_1 , V_18 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 , char * V_3 ,
int V_4 , unsigned int * V_5 ,
unsigned int * V_6 )
{
int V_7 ;
T_1 V_8 ;
struct V_9 V_10 ;
if ( V_2 -> V_11 == - 1 )
return - 1 ;
if ( V_4 > V_2 -> V_13 )
V_4 = V_2 -> V_13 ;
V_8 = V_2 -> V_11 ;
if ( V_2 -> V_19 ) {
V_7 = V_16 . V_20 ( ( char * ) & V_10 ,
sizeof( struct V_9 ) ,
& V_8 ) ;
if ( V_7 <= 0 ) {
F_3 ( L_2 , V_18 , V_7 ) ;
return V_7 ;
}
}
V_7 = V_16 . V_20 ( V_3 , V_4 , & V_8 ) ;
if ( V_7 <= 0 ) {
F_3 ( L_2 , V_18 , V_7 ) ;
return V_7 ;
}
if ( V_2 -> V_19 ) {
* V_6 = F_5 ( V_10 . V_15 ) ;
* V_5 = F_5 ( V_10 . V_14 ) ;
}
return 0 ;
}
int T_2 F_6 ( struct V_1 * V_2 )
{
T_1 V_21 ;
int V_13 ;
V_21 = F_7 ( V_2 -> V_22 , V_23 , & V_13 ) ;
if ( V_21 && V_13 < V_2 -> V_24 ) {
F_8 ( L_3
L_4 , V_2 -> V_22 ) ;
F_9 ( V_2 -> V_22 , V_23 , NULL ) ;
V_21 = 0 ;
}
if ( ! V_21 ) {
V_21 = F_10 ( V_2 -> V_22 , V_23 ,
V_2 -> V_25 , V_2 -> V_24 ) ;
if ( V_21 == - V_26 ) {
F_8 ( L_5
L_6 ,
V_2 -> V_22 ) ;
F_9 ( NULL , V_23 ,
V_27 ) ;
V_21 = F_10 ( V_2 -> V_22 , V_23 ,
V_2 -> V_25 , V_2 -> V_24 ) ;
}
}
if ( V_21 <= 0 ) {
F_3 ( L_7
L_8 , V_2 -> V_22 , ( int ) V_21 ) ;
return - 1 ;
}
V_2 -> V_11 = V_21 ;
V_2 -> V_13 = F_11 ( V_21 ) - sizeof( struct V_9 ) ;
return 0 ;
}
static int F_12 ( const void * V_28 , void * V_29 , T_3 V_30 ,
T_3 V_31 )
{
int V_32 , V_33 ;
V_33 = - V_34 ;
V_32 = F_13 ( & V_35 , V_36 , V_37 , V_38 ,
V_39 , V_40 ) ;
if ( V_32 != V_41 )
goto error;
V_35 . V_42 = V_28 ;
V_35 . V_43 = V_30 ;
V_35 . V_44 = 0 ;
V_35 . V_45 = V_29 ;
V_35 . V_46 = V_31 ;
V_35 . V_47 = 0 ;
V_32 = F_14 ( & V_35 , V_48 ) ;
if ( V_32 != V_49 )
goto error;
V_32 = F_15 ( & V_35 ) ;
if ( V_32 != V_41 )
goto error;
if ( V_35 . V_47 >= V_35 . V_44 )
goto error;
V_33 = V_35 . V_47 ;
error:
return V_33 ;
}
static int F_16 ( T_3 V_50 )
{
struct V_51 * V_52 = (struct V_51 * ) V_53 ;
int V_54 = F_12 ( V_55 , V_56 , V_50 ,
V_57 ) ;
if ( V_54 < 0 ) {
F_3 ( L_9 , V_54 ) ;
F_3 ( L_10 ) ;
return - 1 ;
}
V_52 -> V_58 = F_17 ( V_59 ) ;
V_52 -> V_60 = F_17 ( V_54 ) ;
V_52 -> V_61 = F_18 ( F_19 () ) ;
return 0 ;
}
static int F_20 ( struct V_62 * V_63 )
{
V_64 = - 1 ;
return 0 ;
}
static int F_21 ( enum V_65 type ,
enum V_66 V_67 ,
T_4 * V_68 , unsigned int V_2 , int V_69 ,
bool V_70 , T_3 V_13 ,
struct V_62 * V_63 )
{
int V_7 ;
unsigned int V_5 = V_71 ;
struct V_51 * V_52 = (struct V_51 * ) V_53 ;
if ( V_2 > 1 || ( type != V_72 ) )
return - 1 ;
if ( F_22 () )
return - 1 ;
V_52 -> V_58 = F_17 ( V_59 ) ;
V_52 -> V_60 = F_17 ( V_13 ) ;
V_52 -> V_61 = F_18 ( F_19 () ) ;
if ( V_70 )
V_5 = V_73 ;
V_7 = F_1 ( & V_74 , V_53 ,
( int ) ( sizeof( * V_52 ) + V_13 ) , V_5 , V_69 ) ;
if ( V_7 != 0 )
return V_7 ;
* V_68 = V_2 ;
return 0 ;
}
static T_5 F_23 ( T_4 * V_68 , enum V_65 * type ,
int * V_69 , struct V_75 * time , char * * V_76 ,
bool * V_70 , struct V_62 * V_63 )
{
struct V_51 * V_52 ;
unsigned int V_5 , V_77 , V_13 = 0 ;
struct V_1 * V_2 = NULL ;
char * V_3 = NULL ;
int V_78 = 0 ;
T_1 V_21 ;
V_64 ++ ;
switch ( V_79 [ V_64 ] ) {
case V_72 :
V_2 = & V_74 ;
* type = V_72 ;
break;
case V_80 :
V_78 = V_81 ;
V_2 = & V_82 ;
* type = V_80 ;
* V_68 = V_80 ;
time -> V_83 = 0 ;
time -> V_84 = 0 ;
break;
#ifdef F_24
case V_85 :
V_2 = & V_86 ;
* type = V_85 ;
time -> V_83 = V_87 ;
time -> V_84 = 0 ;
break;
case V_88 :
V_78 = V_89 ;
V_2 = & V_90 ;
* type = V_88 ;
* V_68 = V_88 ;
time -> V_83 = 0 ;
time -> V_84 = 0 ;
break;
#endif
#ifdef F_25
case V_91 :
V_78 = V_92 ;
V_2 = & V_93 ;
* type = V_91 ;
* V_68 = V_91 ;
time -> V_83 = 0 ;
time -> V_84 = 0 ;
break;
#endif
default:
return 0 ;
}
if ( ! V_2 -> V_19 ) {
V_21 = F_7 ( V_2 -> V_22 , V_78 , & V_13 ) ;
if ( V_21 <= 0 ) {
F_3 ( L_11
L_12 , V_2 -> V_22 , ( int ) V_21 ) ;
return 0 ;
}
V_2 -> V_11 = V_21 ;
V_2 -> V_13 = V_13 ;
}
V_3 = F_26 ( V_2 -> V_13 , V_94 ) ;
if ( ! V_3 )
return - V_95 ;
if ( F_4 ( V_2 , V_3 , V_2 -> V_13 , & V_5 , & V_77 ) ) {
F_27 ( V_3 ) ;
return 0 ;
}
* V_69 = 0 ;
if ( V_2 -> V_19 )
* V_68 = V_77 ;
if ( V_79 [ V_64 ] == V_72 ) {
T_3 V_4 , V_96 ;
V_52 = (struct V_51 * ) V_3 ;
if ( F_28 ( V_52 -> V_58 ) < V_59 ) {
V_96 = sizeof( V_97 ) ;
V_4 = F_28 ( V_52 -> V_58 ) ;
time -> V_83 = 0 ;
time -> V_84 = 0 ;
} else {
V_96 = sizeof( * V_52 ) ;
V_4 = F_28 ( V_52 -> V_60 ) ;
time -> V_83 = F_29 ( V_52 -> V_61 ) ;
time -> V_84 = 0 ;
}
* V_76 = F_30 ( V_3 + V_96 , V_4 , V_94 ) ;
if ( * V_76 == NULL )
return - V_95 ;
F_27 ( V_3 ) ;
if ( V_5 == V_73 )
* V_70 = true ;
else
* V_70 = false ;
return V_4 ;
}
* V_76 = V_3 ;
return V_2 -> V_13 ;
}
static int F_31 ( void )
{
int V_7 = 0 ;
if ( F_32 ( V_98 ) ) {
V_79 [ 2 ] = V_85 ;
V_79 [ 3 ] = V_88 ;
} else
V_79 [ 2 ] = V_91 ;
V_99 . V_76 = V_56 ;
V_99 . V_100 = V_57 ;
F_33 ( & V_99 . V_101 ) ;
V_7 = F_34 ( & V_99 ) ;
if ( V_7 && ( V_7 != - V_102 ) )
F_3 ( L_13
L_14 , V_7 ) ;
return V_7 ;
}
static int F_31 ( void )
{
return - 1 ;
}
void T_2 F_35 ( int V_103 )
{
int V_7 ;
V_7 = F_6 ( & V_74 ) ;
if ( V_7 != 0 ) {
#ifdef F_24
if ( ! V_103 ) {
F_3 ( L_15 ) ;
return;
}
F_36 ( L_16
L_17 ,
V_86 . V_22 ) ;
memcpy ( & V_74 , & V_86 ,
sizeof( V_86 ) ) ;
#else
F_3 ( L_15 ) ;
return;
#endif
}
V_53 = F_26 ( V_74 . V_13 , V_94 ) ;
if ( ! V_53 ) {
F_3 ( L_18 ,
V_74 . V_22 ) ;
return;
}
V_56 = V_53 + sizeof( struct V_51 ) ;
V_57 = V_74 . V_13 - sizeof( struct V_51 ) ;
V_7 = F_31 () ;
if ( ! V_7 )
return;
V_104 = ( V_57 * 100 ) / 45 ;
V_55 = F_26 ( V_104 , V_94 ) ;
if ( V_55 ) {
V_35 . V_105 = F_26 ( F_37 (
V_38 , V_39 ) , V_94 ) ;
if ( ! V_35 . V_105 ) {
F_3 ( L_19
L_20 ,
V_74 . V_22 ) ;
F_27 ( V_55 ) ;
V_55 = NULL ;
}
} else {
F_3 ( L_21
L_22 , V_74 . V_22 ) ;
V_35 . V_105 = NULL ;
}
V_7 = F_38 ( & V_106 ) ;
if ( V_7 != 0 ) {
F_3 ( L_23 , V_7 ) ;
F_27 ( V_53 ) ;
F_27 ( V_55 ) ;
F_27 ( V_35 . V_105 ) ;
}
}
static void F_39 ( struct V_107 * V_108 ,
enum V_66 V_67 )
{
struct V_51 * V_52 = (struct V_51 * ) V_53 ;
static unsigned int V_109 = 0 ;
static bool V_110 = false ;
static F_40 ( V_111 ) ;
unsigned long V_112 ;
T_3 V_50 ;
unsigned int V_5 = V_73 ;
int V_7 = - 1 ;
switch ( V_67 ) {
case V_113 :
case V_114 :
case V_115 :
return;
case V_116 :
break;
case V_117 :
V_110 = true ;
break;
case V_118 :
if ( V_110 )
return;
break;
default:
F_3 ( L_24 ,
V_18 , ( int ) V_67 ) ;
return;
}
if ( F_22 () )
return;
if ( ! F_41 ( & V_111 , V_112 ) )
return;
if ( V_55 ) {
F_42 ( V_108 , false ,
V_55 , V_104 , & V_50 ) ;
V_7 = F_16 ( V_50 ) ;
}
if ( V_7 != 0 ) {
F_43 ( V_108 ) ;
F_42 ( V_108 , false ,
V_56 , V_57 , & V_50 ) ;
V_5 = V_71 ;
V_52 -> V_58 = F_17 ( V_59 ) ;
V_52 -> V_60 = F_17 ( V_50 ) ;
V_52 -> V_61 = F_18 ( F_19 () ) ;
}
( void ) F_1 ( & V_74 , V_53 ,
( int ) ( sizeof( * V_52 ) + V_50 ) , V_5 ,
++ V_109 ) ;
F_44 ( & V_111 , V_112 ) ;
}
static T_1 F_45 ( struct V_119 * V_119 , T_1 V_120 , int V_121 )
{
int V_13 ;
if ( V_16 . V_122 == NULL )
return - V_123 ;
V_13 = V_16 . V_122 () ;
switch ( V_121 ) {
case 1 :
V_120 += V_119 -> V_124 ;
break;
case 2 :
V_120 += V_13 ;
break;
}
if ( V_120 < 0 )
return - V_125 ;
V_119 -> V_124 = V_120 ;
return V_119 -> V_124 ;
}
static T_5 F_46 ( struct V_119 * V_119 , char T_6 * V_76 ,
T_3 V_69 , T_1 * V_126 )
{
T_5 V_33 ;
char * V_127 = NULL ;
T_5 V_13 ;
if ( ! V_16 . V_122 ) {
V_33 = - V_123 ;
goto V_29;
}
V_13 = V_16 . V_122 () ;
if ( V_13 < 0 ) {
V_33 = V_13 ;
goto V_29;
}
if ( * V_126 >= V_13 ) {
V_33 = 0 ;
goto V_29;
}
V_69 = F_47 ( T_3 , V_69 , V_13 - * V_126 ) ;
V_69 = F_48 ( V_69 , V_128 ) ;
V_127 = F_26 ( V_69 , V_94 ) ;
if ( ! V_127 ) {
V_33 = - V_95 ;
goto V_29;
}
V_33 = V_16 . V_20 ( V_127 , V_69 , V_126 ) ;
if ( V_33 <= 0 )
goto V_29;
if ( F_49 ( V_76 , V_127 , V_33 ) )
V_33 = - V_129 ;
V_29:
F_27 ( V_127 ) ;
return V_33 ;
}
static T_5 F_50 ( struct V_119 * V_119 , const char T_6 * V_76 ,
T_3 V_69 , T_1 * V_126 )
{
T_5 V_33 ;
char * V_127 = NULL ;
T_5 V_13 ;
V_33 = - V_123 ;
if ( ! V_16 . V_122 )
goto V_29;
V_33 = 0 ;
V_13 = V_16 . V_122 () ;
if ( * V_126 >= V_13 || V_13 < 0 )
goto V_29;
V_69 = F_47 ( T_3 , V_69 , V_13 - * V_126 ) ;
V_69 = F_48 ( V_69 , V_128 ) ;
V_33 = - V_95 ;
V_127 = F_26 ( V_69 , V_94 ) ;
if ( ! V_127 )
goto V_29;
V_33 = - V_129 ;
if ( F_51 ( V_127 , V_76 , V_69 ) )
goto V_29;
V_33 = V_16 . V_17 ( V_127 , V_69 , V_126 ) ;
V_29:
F_27 ( V_127 ) ;
return V_33 ;
}
static long F_52 ( struct V_119 * V_119 , unsigned int V_130 ,
unsigned long V_131 )
{
switch( V_130 ) {
#ifdef F_53
case V_132 :
F_54 ( V_133 L_25 ) ;
case V_134 : {
int V_2 , V_120 ;
if ( ! F_32 ( V_135 ) )
return - V_125 ;
if ( F_51 ( & V_2 , ( void T_6 * ) V_131 , sizeof( V_2 ) ) != 0 )
return - V_129 ;
if ( V_2 < V_136 || V_2 > V_137 )
return - V_125 ;
V_120 = F_55 ( V_2 ) ;
if ( V_120 < 0 )
return V_120 ;
if ( F_49 ( ( void T_6 * ) V_131 , & V_120 , sizeof( V_120 ) ) != 0 )
return - V_129 ;
return 0 ;
}
#endif
default:
return - V_125 ;
}
}
static void T_2 F_56 ( char * V_138 )
{
struct V_139 * V_140 ;
F_54 ( V_133 L_26 , V_138 ) ;
F_54 ( V_133 L_27 ) ;
F_57 (tmp_part, &nvram_partitions, partition) {
F_54 ( V_133 L_28 ,
V_140 -> V_11 , V_140 -> V_141 . V_142 ,
V_140 -> V_141 . V_143 , V_140 -> V_141 . V_4 ,
V_140 -> V_141 . V_22 ) ;
}
}
static int T_2 F_58 ( struct V_139 * V_2 )
{
T_1 V_8 ;
int V_7 ;
struct V_144 V_145 ;
memcpy ( & V_145 , & V_2 -> V_141 , V_146 ) ;
V_145 . V_4 = F_17 ( V_145 . V_4 ) ;
V_8 = V_2 -> V_11 ;
V_7 = V_16 . V_17 ( ( char * ) & V_145 , V_146 , & V_8 ) ;
return V_7 ;
}
static unsigned char T_2 F_59 ( struct V_144 * V_21 )
{
unsigned int V_147 , V_148 ;
unsigned short * V_149 = ( unsigned short * ) V_21 -> V_22 ;
V_147 = V_21 -> V_142 + V_21 -> V_4 + V_149 [ 0 ] + V_149 [ 1 ] + V_149 [ 2 ] + V_149 [ 3 ] + V_149 [ 4 ] + V_149 [ 5 ] ;
V_147 = ( ( V_147 & 0xffff ) + ( V_147 >> 16 ) ) & 0xffff ;
V_148 = ( V_147 >> 8 ) + ( V_147 << 8 ) ;
V_147 = ( ( V_147 + V_148 ) >> 8 ) & 0xff ;
return V_147 ;
}
static int F_60 ( struct V_139 * V_2 ,
const char * V_22 , int V_78 , const char * V_150 [] )
{
if ( V_2 -> V_141 . V_142 != V_78 )
return 0 ;
if ( V_22 ) {
if ( strncmp ( V_22 , V_2 -> V_141 . V_22 , 12 ) )
return 0 ;
} else if ( V_150 ) {
const char * * V_151 ;
for ( V_151 = V_150 ; * V_151 ; V_151 ++ ) {
if ( ! strncmp ( * V_151 , V_2 -> V_141 . V_22 , 12 ) )
return 0 ;
}
}
return 1 ;
}
int T_2 F_9 ( const char * V_22 , int V_78 ,
const char * V_150 [] )
{
struct V_139 * V_2 , * V_152 , * V_127 ;
int V_7 ;
F_57 (part, &nvram_partitions, partition) {
if ( ! F_60 ( V_2 , V_22 , V_78 , V_150 ) )
continue;
V_2 -> V_141 . V_142 = V_153 ;
strncpy ( V_2 -> V_141 . V_22 , L_29 , 12 ) ;
V_2 -> V_141 . V_143 = F_59 ( & V_2 -> V_141 ) ;
V_7 = F_58 ( V_2 ) ;
if ( V_7 <= 0 ) {
F_54 ( V_154 L_30 , V_7 ) ;
return V_7 ;
}
}
V_152 = NULL ;
F_61 (part, tmp, &nvram_partitions, partition) {
if ( V_2 -> V_141 . V_142 != V_153 ) {
V_152 = NULL ;
continue;
}
if ( V_152 ) {
V_152 -> V_141 . V_4 += V_2 -> V_141 . V_4 ;
V_152 -> V_141 . V_143 = F_59 ( & V_2 -> V_141 ) ;
V_7 = F_58 ( V_2 ) ;
if ( V_7 <= 0 ) {
F_54 ( V_154 L_30 , V_7 ) ;
return V_7 ;
}
F_62 ( & V_2 -> V_155 ) ;
F_27 ( V_2 ) ;
} else
V_152 = V_2 ;
}
return 0 ;
}
T_1 T_2 F_10 ( const char * V_22 , int V_78 ,
int V_25 , int V_24 )
{
struct V_139 * V_2 ;
struct V_139 * V_156 ;
struct V_139 * V_157 = NULL ;
static char V_158 [ 16 ] ;
T_1 V_8 ;
long V_13 = 0 ;
int V_7 ;
V_25 = F_63 ( V_25 , V_159 ) / V_159 ;
V_24 = F_63 ( V_24 , V_159 ) / V_159 ;
if ( V_24 == 0 )
V_24 = V_25 ;
if ( V_24 > V_25 )
return - V_125 ;
V_25 += 1 ;
V_24 += 1 ;
F_57 (part, &nvram_partitions, partition) {
if ( V_2 -> V_141 . V_142 != V_153 )
continue;
if ( V_2 -> V_141 . V_4 >= V_25 ) {
V_13 = V_25 ;
V_157 = V_2 ;
break;
}
if ( V_2 -> V_141 . V_4 > V_13 &&
V_2 -> V_141 . V_4 >= V_24 ) {
V_13 = V_2 -> V_141 . V_4 ;
V_157 = V_2 ;
}
}
if ( ! V_13 )
return - V_26 ;
V_156 = F_26 ( sizeof( * V_156 ) , V_94 ) ;
if ( ! V_156 ) {
F_3 ( L_31 ) ;
return - V_95 ;
}
V_156 -> V_11 = V_157 -> V_11 ;
V_156 -> V_141 . V_142 = V_78 ;
V_156 -> V_141 . V_4 = V_13 ;
strncpy ( V_156 -> V_141 . V_22 , V_22 , 12 ) ;
V_156 -> V_141 . V_143 = F_59 ( & V_156 -> V_141 ) ;
V_7 = F_58 ( V_156 ) ;
if ( V_7 <= 0 ) {
F_3 ( L_32
L_33 , V_7 ) ;
return V_7 ;
}
F_64 ( & V_156 -> V_155 , & V_157 -> V_155 ) ;
if ( V_157 -> V_141 . V_4 > V_13 ) {
V_157 -> V_11 += V_13 * V_159 ;
V_157 -> V_141 . V_4 -= V_13 ;
V_157 -> V_141 . V_143 = F_59 ( & V_157 -> V_141 ) ;
V_7 = F_58 ( V_157 ) ;
if ( V_7 <= 0 ) {
F_3 ( L_32
L_33 , V_7 ) ;
return V_7 ;
}
} else {
F_62 ( & V_157 -> V_155 ) ;
F_27 ( V_157 ) ;
}
for ( V_8 = V_156 -> V_11 + V_146 ;
V_8 < ( ( V_13 - 1 ) * V_159 ) ;
V_8 += V_159 ) {
V_7 = V_16 . V_17 ( V_158 , V_159 , & V_8 ) ;
if ( V_7 <= 0 ) {
F_3 ( L_34 , V_7 ) ;
return V_7 ;
}
}
return V_156 -> V_11 + V_146 ;
}
int F_11 ( T_1 V_160 )
{
struct V_139 * V_2 ;
F_57 (part, &nvram_partitions, partition) {
if ( V_2 -> V_11 + V_146 == V_160 )
return ( V_2 -> V_141 . V_4 - 1 ) * V_159 ;
}
return - 1 ;
}
T_1 F_7 ( const char * V_22 , int V_78 , int * V_161 )
{
struct V_139 * V_21 ;
F_57 (p, &nvram_partitions, partition) {
if ( V_21 -> V_141 . V_142 == V_78 &&
( ! V_22 || ! strncmp ( V_21 -> V_141 . V_22 , V_22 , 12 ) ) ) {
if ( V_161 )
* V_161 = ( V_21 -> V_141 . V_4 - 1 ) *
V_159 ;
return V_21 -> V_11 + V_146 ;
}
}
return 0 ;
}
int T_2 F_65 ( void )
{
T_1 V_162 = 0 ;
struct V_144 V_145 ;
struct V_139 * V_140 ;
unsigned char V_147 ;
char * V_141 ;
int V_163 ;
int V_32 ;
if ( V_16 . V_122 == NULL || V_16 . V_122 () <= 0 )
return - V_123 ;
V_163 = V_16 . V_122 () ;
V_141 = F_26 ( V_146 , V_94 ) ;
if ( ! V_141 ) {
F_54 ( V_154 L_35 ) ;
return - V_95 ;
}
while ( V_162 < V_163 ) {
V_32 = V_16 . V_20 ( V_141 , V_146 , & V_162 ) ;
if ( V_32 != V_146 ) {
F_54 ( V_154 L_36
L_37 ) ;
goto V_29;
}
V_162 -= V_146 ;
memcpy ( & V_145 , V_141 , V_146 ) ;
V_145 . V_4 = F_28 ( V_145 . V_4 ) ;
V_32 = 0 ;
V_147 = F_59 ( & V_145 ) ;
if ( V_147 != V_145 . V_143 ) {
F_54 ( V_133 L_38
L_39 ,
V_145 . V_143 , V_147 ) ;
F_54 ( V_133 L_40 ) ;
goto V_29;
}
if ( ! V_145 . V_4 ) {
F_54 ( V_133 L_41
L_42 ) ;
goto V_29;
}
V_140 = F_26 ( sizeof( struct V_139 ) , V_94 ) ;
V_32 = - V_95 ;
if ( ! V_140 ) {
F_54 ( V_154 L_43 ) ;
goto V_29;
}
memcpy ( & V_140 -> V_141 , & V_145 , V_146 ) ;
V_140 -> V_11 = V_162 ;
F_64 ( & V_140 -> V_155 , & V_164 ) ;
V_162 += V_145 . V_4 * V_159 ;
}
V_32 = 0 ;
#ifdef F_66
F_56 ( L_44 ) ;
#endif
V_29:
F_27 ( V_141 ) ;
return V_32 ;
}
static int T_2 F_67 ( void )
{
int V_7 ;
F_68 ( V_159 != 16 ) ;
if ( V_16 . V_122 == NULL || V_16 . V_122 () <= 0 )
return - V_123 ;
V_7 = F_69 ( & V_165 ) ;
if ( V_7 != 0 ) {
F_54 ( V_154 L_45 ) ;
return V_7 ;
}
return V_7 ;
}
static void T_7 F_70 ( void )
{
F_71 ( & V_165 ) ;
}
