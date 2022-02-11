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
* V_76 = F_26 ( V_4 , V_94 ) ;
if ( * V_76 == NULL )
return - V_95 ;
memcpy ( * V_76 , V_3 + V_96 , V_4 ) ;
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
static int F_30 ( void )
{
int V_7 = 0 ;
if ( F_31 ( V_98 ) ) {
V_79 [ 2 ] = V_85 ;
V_79 [ 3 ] = V_88 ;
} else
V_79 [ 2 ] = V_91 ;
V_99 . V_76 = V_56 ;
V_99 . V_100 = V_57 ;
F_32 ( & V_99 . V_101 ) ;
V_7 = F_33 ( & V_99 ) ;
if ( V_7 != 0 )
F_3 ( L_13
L_14 , V_7 ) ;
return V_7 ;
}
static int F_30 ( void )
{
return - 1 ;
}
void T_2 F_34 ( int V_102 )
{
int V_7 ;
V_7 = F_6 ( & V_74 ) ;
if ( V_7 != 0 ) {
#ifdef F_24
if ( ! V_102 ) {
F_3 ( L_15 ) ;
return;
}
F_35 ( L_16
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
V_7 = F_30 () ;
if ( ! V_7 )
return;
V_103 = ( V_57 * 100 ) / 45 ;
V_55 = F_26 ( V_103 , V_94 ) ;
if ( V_55 ) {
V_35 . V_104 = F_26 ( F_36 (
V_38 , V_39 ) , V_94 ) ;
if ( ! V_35 . V_104 ) {
F_3 ( L_19
L_20 ,
V_74 . V_22 ) ;
F_27 ( V_55 ) ;
V_55 = NULL ;
}
} else {
F_3 ( L_21
L_22 , V_74 . V_22 ) ;
V_35 . V_104 = NULL ;
}
V_7 = F_37 ( & V_105 ) ;
if ( V_7 != 0 ) {
F_3 ( L_23 , V_7 ) ;
F_27 ( V_53 ) ;
F_27 ( V_55 ) ;
F_27 ( V_35 . V_104 ) ;
}
}
static void F_38 ( struct V_106 * V_107 ,
enum V_66 V_67 )
{
struct V_51 * V_52 = (struct V_51 * ) V_53 ;
static unsigned int V_108 = 0 ;
static bool V_109 = false ;
static F_39 ( V_110 ) ;
unsigned long V_111 ;
T_3 V_50 ;
unsigned int V_5 = V_73 ;
int V_7 = - 1 ;
switch ( V_67 ) {
case V_112 :
case V_113 :
case V_114 :
return;
case V_115 :
break;
case V_116 :
V_109 = true ;
break;
case V_117 :
if ( V_109 )
return;
break;
default:
F_3 ( L_24 ,
V_18 , ( int ) V_67 ) ;
return;
}
if ( F_22 () )
return;
if ( ! F_40 ( & V_110 , V_111 ) )
return;
if ( V_55 ) {
F_41 ( V_107 , false ,
V_55 , V_103 , & V_50 ) ;
V_7 = F_16 ( V_50 ) ;
}
if ( V_7 != 0 ) {
F_42 ( V_107 ) ;
F_41 ( V_107 , false ,
V_56 , V_57 , & V_50 ) ;
V_5 = V_71 ;
V_52 -> V_58 = F_17 ( V_59 ) ;
V_52 -> V_60 = F_17 ( V_50 ) ;
V_52 -> V_61 = F_18 ( F_19 () ) ;
}
( void ) F_1 ( & V_74 , V_53 ,
( int ) ( sizeof( * V_52 ) + V_50 ) , V_5 ,
++ V_108 ) ;
F_43 ( & V_110 , V_111 ) ;
}
static T_1 F_44 ( struct V_118 * V_118 , T_1 V_119 , int V_120 )
{
int V_13 ;
if ( V_16 . V_121 == NULL )
return - V_122 ;
V_13 = V_16 . V_121 () ;
switch ( V_120 ) {
case 1 :
V_119 += V_118 -> V_123 ;
break;
case 2 :
V_119 += V_13 ;
break;
}
if ( V_119 < 0 )
return - V_124 ;
V_118 -> V_123 = V_119 ;
return V_118 -> V_123 ;
}
static T_5 F_45 ( struct V_118 * V_118 , char T_6 * V_76 ,
T_3 V_69 , T_1 * V_125 )
{
T_5 V_33 ;
char * V_126 = NULL ;
T_5 V_13 ;
if ( ! V_16 . V_121 ) {
V_33 = - V_122 ;
goto V_29;
}
V_13 = V_16 . V_121 () ;
if ( V_13 < 0 ) {
V_33 = V_13 ;
goto V_29;
}
if ( * V_125 >= V_13 ) {
V_33 = 0 ;
goto V_29;
}
V_69 = F_46 ( T_3 , V_69 , V_13 - * V_125 ) ;
V_69 = F_47 ( V_69 , V_127 ) ;
V_126 = F_26 ( V_69 , V_94 ) ;
if ( ! V_126 ) {
V_33 = - V_95 ;
goto V_29;
}
V_33 = V_16 . V_20 ( V_126 , V_69 , V_125 ) ;
if ( V_33 <= 0 )
goto V_29;
if ( F_48 ( V_76 , V_126 , V_33 ) )
V_33 = - V_128 ;
V_29:
F_27 ( V_126 ) ;
return V_33 ;
}
static T_5 F_49 ( struct V_118 * V_118 , const char T_6 * V_76 ,
T_3 V_69 , T_1 * V_125 )
{
T_5 V_33 ;
char * V_126 = NULL ;
T_5 V_13 ;
V_33 = - V_122 ;
if ( ! V_16 . V_121 )
goto V_29;
V_33 = 0 ;
V_13 = V_16 . V_121 () ;
if ( * V_125 >= V_13 || V_13 < 0 )
goto V_29;
V_69 = F_46 ( T_3 , V_69 , V_13 - * V_125 ) ;
V_69 = F_47 ( V_69 , V_127 ) ;
V_33 = - V_95 ;
V_126 = F_26 ( V_69 , V_94 ) ;
if ( ! V_126 )
goto V_29;
V_33 = - V_128 ;
if ( F_50 ( V_126 , V_76 , V_69 ) )
goto V_29;
V_33 = V_16 . V_17 ( V_126 , V_69 , V_125 ) ;
V_29:
F_27 ( V_126 ) ;
return V_33 ;
}
static long F_51 ( struct V_118 * V_118 , unsigned int V_129 ,
unsigned long V_130 )
{
switch( V_129 ) {
#ifdef F_52
case V_131 :
F_53 ( V_132 L_25 ) ;
case V_133 : {
int V_2 , V_119 ;
if ( ! F_31 ( V_134 ) )
return - V_124 ;
if ( F_50 ( & V_2 , ( void T_6 * ) V_130 , sizeof( V_2 ) ) != 0 )
return - V_128 ;
if ( V_2 < V_135 || V_2 > V_136 )
return - V_124 ;
V_119 = F_54 ( V_2 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( F_48 ( ( void T_6 * ) V_130 , & V_119 , sizeof( V_119 ) ) != 0 )
return - V_128 ;
return 0 ;
}
#endif
default:
return - V_124 ;
}
}
static void T_2 F_55 ( char * V_137 )
{
struct V_138 * V_139 ;
F_53 ( V_132 L_26 , V_137 ) ;
F_53 ( V_132 L_27 ) ;
F_56 (tmp_part, &nvram_partitions, partition) {
F_53 ( V_132 L_28 ,
V_139 -> V_11 , V_139 -> V_140 . V_141 ,
V_139 -> V_140 . V_142 , V_139 -> V_140 . V_4 ,
V_139 -> V_140 . V_22 ) ;
}
}
static int T_2 F_57 ( struct V_138 * V_2 )
{
T_1 V_8 ;
int V_7 ;
struct V_143 V_144 ;
memcpy ( & V_144 , & V_2 -> V_140 , V_145 ) ;
V_144 . V_4 = F_17 ( V_144 . V_4 ) ;
V_8 = V_2 -> V_11 ;
V_7 = V_16 . V_17 ( ( char * ) & V_144 , V_145 , & V_8 ) ;
return V_7 ;
}
static unsigned char T_2 F_58 ( struct V_143 * V_21 )
{
unsigned int V_146 , V_147 ;
unsigned short * V_148 = ( unsigned short * ) V_21 -> V_22 ;
V_146 = V_21 -> V_141 + V_21 -> V_4 + V_148 [ 0 ] + V_148 [ 1 ] + V_148 [ 2 ] + V_148 [ 3 ] + V_148 [ 4 ] + V_148 [ 5 ] ;
V_146 = ( ( V_146 & 0xffff ) + ( V_146 >> 16 ) ) & 0xffff ;
V_147 = ( V_146 >> 8 ) + ( V_146 << 8 ) ;
V_146 = ( ( V_146 + V_147 ) >> 8 ) & 0xff ;
return V_146 ;
}
static int F_59 ( struct V_138 * V_2 ,
const char * V_22 , int V_78 , const char * V_149 [] )
{
if ( V_2 -> V_140 . V_141 != V_78 )
return 0 ;
if ( V_22 ) {
if ( strncmp ( V_22 , V_2 -> V_140 . V_22 , 12 ) )
return 0 ;
} else if ( V_149 ) {
const char * * V_150 ;
for ( V_150 = V_149 ; * V_150 ; V_150 ++ ) {
if ( ! strncmp ( * V_150 , V_2 -> V_140 . V_22 , 12 ) )
return 0 ;
}
}
return 1 ;
}
int T_2 F_9 ( const char * V_22 , int V_78 ,
const char * V_149 [] )
{
struct V_138 * V_2 , * V_151 , * V_126 ;
int V_7 ;
F_56 (part, &nvram_partitions, partition) {
if ( ! F_59 ( V_2 , V_22 , V_78 , V_149 ) )
continue;
V_2 -> V_140 . V_141 = V_152 ;
strncpy ( V_2 -> V_140 . V_22 , L_29 , 12 ) ;
V_2 -> V_140 . V_142 = F_58 ( & V_2 -> V_140 ) ;
V_7 = F_57 ( V_2 ) ;
if ( V_7 <= 0 ) {
F_53 ( V_153 L_30 , V_7 ) ;
return V_7 ;
}
}
V_151 = NULL ;
F_60 (part, tmp, &nvram_partitions, partition) {
if ( V_2 -> V_140 . V_141 != V_152 ) {
V_151 = NULL ;
continue;
}
if ( V_151 ) {
V_151 -> V_140 . V_4 += V_2 -> V_140 . V_4 ;
V_151 -> V_140 . V_142 = F_58 ( & V_2 -> V_140 ) ;
V_7 = F_57 ( V_2 ) ;
if ( V_7 <= 0 ) {
F_53 ( V_153 L_30 , V_7 ) ;
return V_7 ;
}
F_61 ( & V_2 -> V_154 ) ;
F_27 ( V_2 ) ;
} else
V_151 = V_2 ;
}
return 0 ;
}
T_1 T_2 F_10 ( const char * V_22 , int V_78 ,
int V_25 , int V_24 )
{
struct V_138 * V_2 ;
struct V_138 * V_155 ;
struct V_138 * V_156 = NULL ;
static char V_157 [ 16 ] ;
T_1 V_8 ;
long V_13 = 0 ;
int V_7 ;
V_25 = F_62 ( V_25 , V_158 ) / V_158 ;
V_24 = F_62 ( V_24 , V_158 ) / V_158 ;
if ( V_24 == 0 )
V_24 = V_25 ;
if ( V_24 > V_25 )
return - V_124 ;
V_25 += 1 ;
V_24 += 1 ;
F_56 (part, &nvram_partitions, partition) {
if ( V_2 -> V_140 . V_141 != V_152 )
continue;
if ( V_2 -> V_140 . V_4 >= V_25 ) {
V_13 = V_25 ;
V_156 = V_2 ;
break;
}
if ( V_2 -> V_140 . V_4 > V_13 &&
V_2 -> V_140 . V_4 >= V_24 ) {
V_13 = V_2 -> V_140 . V_4 ;
V_156 = V_2 ;
}
}
if ( ! V_13 )
return - V_26 ;
V_155 = F_26 ( sizeof( * V_155 ) , V_94 ) ;
if ( ! V_155 ) {
F_3 ( L_31 ) ;
return - V_95 ;
}
V_155 -> V_11 = V_156 -> V_11 ;
V_155 -> V_140 . V_141 = V_78 ;
V_155 -> V_140 . V_4 = V_13 ;
strncpy ( V_155 -> V_140 . V_22 , V_22 , 12 ) ;
V_155 -> V_140 . V_142 = F_58 ( & V_155 -> V_140 ) ;
V_7 = F_57 ( V_155 ) ;
if ( V_7 <= 0 ) {
F_3 ( L_32
L_33 , V_7 ) ;
return V_7 ;
}
F_63 ( & V_155 -> V_154 , & V_156 -> V_154 ) ;
if ( V_156 -> V_140 . V_4 > V_13 ) {
V_156 -> V_11 += V_13 * V_158 ;
V_156 -> V_140 . V_4 -= V_13 ;
V_156 -> V_140 . V_142 = F_58 ( & V_156 -> V_140 ) ;
V_7 = F_57 ( V_156 ) ;
if ( V_7 <= 0 ) {
F_3 ( L_32
L_33 , V_7 ) ;
return V_7 ;
}
} else {
F_61 ( & V_156 -> V_154 ) ;
F_27 ( V_156 ) ;
}
for ( V_8 = V_155 -> V_11 + V_145 ;
V_8 < ( ( V_13 - 1 ) * V_158 ) ;
V_8 += V_158 ) {
V_7 = V_16 . V_17 ( V_157 , V_158 , & V_8 ) ;
if ( V_7 <= 0 ) {
F_3 ( L_34 , V_7 ) ;
return V_7 ;
}
}
return V_155 -> V_11 + V_145 ;
}
int F_11 ( T_1 V_159 )
{
struct V_138 * V_2 ;
F_56 (part, &nvram_partitions, partition) {
if ( V_2 -> V_11 + V_145 == V_159 )
return ( V_2 -> V_140 . V_4 - 1 ) * V_158 ;
}
return - 1 ;
}
T_1 F_7 ( const char * V_22 , int V_78 , int * V_160 )
{
struct V_138 * V_21 ;
F_56 (p, &nvram_partitions, partition) {
if ( V_21 -> V_140 . V_141 == V_78 &&
( ! V_22 || ! strncmp ( V_21 -> V_140 . V_22 , V_22 , 12 ) ) ) {
if ( V_160 )
* V_160 = ( V_21 -> V_140 . V_4 - 1 ) *
V_158 ;
return V_21 -> V_11 + V_145 ;
}
}
return 0 ;
}
int T_2 F_64 ( void )
{
T_1 V_161 = 0 ;
struct V_143 V_144 ;
struct V_138 * V_139 ;
unsigned char V_146 ;
char * V_140 ;
int V_162 ;
int V_32 ;
if ( V_16 . V_121 == NULL || V_16 . V_121 () <= 0 )
return - V_122 ;
V_162 = V_16 . V_121 () ;
V_140 = F_26 ( V_145 , V_94 ) ;
if ( ! V_140 ) {
F_53 ( V_153 L_35 ) ;
return - V_95 ;
}
while ( V_161 < V_162 ) {
V_32 = V_16 . V_20 ( V_140 , V_145 , & V_161 ) ;
if ( V_32 != V_145 ) {
F_53 ( V_153 L_36
L_37 ) ;
goto V_29;
}
V_161 -= V_145 ;
memcpy ( & V_144 , V_140 , V_145 ) ;
V_144 . V_4 = F_28 ( V_144 . V_4 ) ;
V_32 = 0 ;
V_146 = F_58 ( & V_144 ) ;
if ( V_146 != V_144 . V_142 ) {
F_53 ( V_132 L_38
L_39 ,
V_144 . V_142 , V_146 ) ;
F_53 ( V_132 L_40 ) ;
goto V_29;
}
if ( ! V_144 . V_4 ) {
F_53 ( V_132 L_41
L_42 ) ;
goto V_29;
}
V_139 = F_26 ( sizeof( struct V_138 ) , V_94 ) ;
V_32 = - V_95 ;
if ( ! V_139 ) {
F_53 ( V_153 L_43 ) ;
goto V_29;
}
memcpy ( & V_139 -> V_140 , & V_144 , V_145 ) ;
V_139 -> V_11 = V_161 ;
F_63 ( & V_139 -> V_154 , & V_163 ) ;
V_161 += V_144 . V_4 * V_158 ;
}
V_32 = 0 ;
#ifdef F_65
F_55 ( L_44 ) ;
#endif
V_29:
F_27 ( V_140 ) ;
return V_32 ;
}
static int T_2 F_66 ( void )
{
int V_7 ;
F_67 ( V_158 != 16 ) ;
if ( V_16 . V_121 == NULL || V_16 . V_121 () <= 0 )
return - V_122 ;
V_7 = F_68 ( & V_164 ) ;
if ( V_7 != 0 ) {
F_53 ( V_153 L_45 ) ;
return V_7 ;
}
return V_7 ;
}
static void T_7 F_69 ( void )
{
F_70 ( & V_164 ) ;
}
