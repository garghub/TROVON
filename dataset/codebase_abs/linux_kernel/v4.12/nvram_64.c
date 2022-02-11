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
static int F_21 ( struct V_65 * V_66 )
{
int V_7 ;
unsigned int V_5 = V_67 ;
struct V_51 * V_52 = (struct V_51 * ) V_53 ;
if ( V_66 -> V_2 > 1 || ( V_66 -> type != V_68 ) )
return - 1 ;
if ( F_22 () )
return - 1 ;
V_52 -> V_58 = F_17 ( V_59 ) ;
V_52 -> V_60 = F_17 ( V_66 -> V_13 ) ;
V_52 -> V_61 = F_18 ( F_19 () ) ;
if ( V_66 -> V_69 )
V_5 = V_70 ;
V_7 = F_1 ( & V_71 , V_53 ,
( int ) ( sizeof( * V_52 ) + V_66 -> V_13 ) , V_5 ,
V_66 -> V_72 ) ;
if ( V_7 != 0 )
return V_7 ;
V_66 -> V_73 = V_66 -> V_2 ;
return 0 ;
}
static T_4 F_23 ( struct V_65 * V_66 )
{
struct V_51 * V_52 ;
unsigned int V_5 , V_74 , V_13 = 0 ;
struct V_1 * V_2 = NULL ;
char * V_3 = NULL ;
int V_75 = 0 ;
T_1 V_21 ;
V_64 ++ ;
switch ( V_76 [ V_64 ] ) {
case V_68 :
V_2 = & V_71 ;
V_66 -> type = V_68 ;
break;
case V_77 :
V_75 = V_78 ;
V_2 = & V_79 ;
V_66 -> type = V_77 ;
V_66 -> V_73 = V_77 ;
V_66 -> time . V_80 = 0 ;
V_66 -> time . V_81 = 0 ;
break;
#ifdef F_24
case V_82 :
V_2 = & V_83 ;
V_66 -> type = V_82 ;
V_66 -> time . V_80 = V_84 ;
V_66 -> time . V_81 = 0 ;
break;
case V_85 :
V_75 = V_86 ;
V_2 = & V_87 ;
V_66 -> type = V_85 ;
V_66 -> V_73 = V_85 ;
V_66 -> time . V_80 = 0 ;
V_66 -> time . V_81 = 0 ;
break;
#endif
#ifdef F_25
case V_88 :
V_75 = V_89 ;
V_2 = & V_90 ;
V_66 -> type = V_88 ;
V_66 -> V_73 = V_88 ;
V_66 -> time . V_80 = 0 ;
V_66 -> time . V_81 = 0 ;
break;
#endif
default:
return 0 ;
}
if ( ! V_2 -> V_19 ) {
V_21 = F_7 ( V_2 -> V_22 , V_75 , & V_13 ) ;
if ( V_21 <= 0 ) {
F_3 ( L_11
L_12 , V_2 -> V_22 , ( int ) V_21 ) ;
return 0 ;
}
V_2 -> V_11 = V_21 ;
V_2 -> V_13 = V_13 ;
}
V_3 = F_26 ( V_2 -> V_13 , V_91 ) ;
if ( ! V_3 )
return - V_92 ;
if ( F_4 ( V_2 , V_3 , V_2 -> V_13 , & V_5 , & V_74 ) ) {
F_27 ( V_3 ) ;
return 0 ;
}
V_66 -> V_72 = 0 ;
if ( V_2 -> V_19 )
V_66 -> V_73 = V_74 ;
if ( V_76 [ V_64 ] == V_68 ) {
T_3 V_4 , V_93 ;
V_52 = (struct V_51 * ) V_3 ;
if ( F_28 ( V_52 -> V_58 ) < V_59 ) {
V_93 = sizeof( V_94 ) ;
V_4 = F_28 ( V_52 -> V_58 ) ;
V_66 -> time . V_80 = 0 ;
V_66 -> time . V_81 = 0 ;
} else {
V_93 = sizeof( * V_52 ) ;
V_4 = F_28 ( V_52 -> V_60 ) ;
V_66 -> time . V_80 = F_29 ( V_52 -> V_61 ) ;
V_66 -> time . V_81 = 0 ;
}
V_66 -> V_95 = F_30 ( V_3 + V_93 , V_4 , V_91 ) ;
F_27 ( V_3 ) ;
if ( V_66 -> V_95 == NULL )
return - V_92 ;
V_66 -> V_96 = 0 ;
if ( V_5 == V_70 )
V_66 -> V_69 = true ;
else
V_66 -> V_69 = false ;
return V_4 ;
}
V_66 -> V_95 = V_3 ;
return V_2 -> V_13 ;
}
static int F_31 ( void )
{
int V_7 = 0 ;
if ( F_32 ( V_97 ) ) {
V_76 [ 2 ] = V_82 ;
V_76 [ 3 ] = V_85 ;
} else
V_76 [ 2 ] = V_88 ;
V_98 . V_95 = V_56 ;
V_98 . V_99 = V_57 ;
F_33 ( & V_98 . V_100 ) ;
V_7 = F_34 ( & V_98 ) ;
if ( V_7 && ( V_7 != - V_101 ) )
F_3 ( L_13
L_14 , V_7 ) ;
return V_7 ;
}
static int F_31 ( void )
{
return - 1 ;
}
void T_2 F_35 ( int V_102 )
{
int V_7 ;
V_7 = F_6 ( & V_71 ) ;
if ( V_7 != 0 ) {
#ifdef F_24
if ( ! V_102 ) {
F_3 ( L_15 ) ;
return;
}
F_36 ( L_16
L_17 ,
V_83 . V_22 ) ;
memcpy ( & V_71 , & V_83 ,
sizeof( V_83 ) ) ;
#else
F_3 ( L_15 ) ;
return;
#endif
}
V_53 = F_26 ( V_71 . V_13 , V_91 ) ;
if ( ! V_53 ) {
F_3 ( L_18 ,
V_71 . V_22 ) ;
return;
}
V_56 = V_53 + sizeof( struct V_51 ) ;
V_57 = V_71 . V_13 - sizeof( struct V_51 ) ;
V_7 = F_31 () ;
if ( ! V_7 )
return;
V_103 = ( V_57 * 100 ) / 45 ;
V_55 = F_26 ( V_103 , V_91 ) ;
if ( V_55 ) {
V_35 . V_104 = F_26 ( F_37 (
V_38 , V_39 ) , V_91 ) ;
if ( ! V_35 . V_104 ) {
F_3 ( L_19
L_20 ,
V_71 . V_22 ) ;
F_27 ( V_55 ) ;
V_55 = NULL ;
}
} else {
F_3 ( L_21
L_22 , V_71 . V_22 ) ;
V_35 . V_104 = NULL ;
}
V_7 = F_38 ( & V_105 ) ;
if ( V_7 != 0 ) {
F_3 ( L_23 , V_7 ) ;
F_27 ( V_53 ) ;
F_27 ( V_55 ) ;
F_27 ( V_35 . V_104 ) ;
}
}
static void F_39 ( struct V_106 * V_107 ,
enum V_108 V_109 )
{
struct V_51 * V_52 = (struct V_51 * ) V_53 ;
static unsigned int V_110 = 0 ;
static bool V_111 = false ;
static F_40 ( V_112 ) ;
unsigned long V_113 ;
T_3 V_50 ;
unsigned int V_5 = V_70 ;
int V_7 = - 1 ;
switch ( V_109 ) {
case V_114 :
case V_115 :
case V_116 :
return;
case V_117 :
break;
case V_118 :
V_111 = true ;
break;
case V_119 :
if ( V_111 )
return;
break;
default:
F_3 ( L_24 ,
V_18 , ( int ) V_109 ) ;
return;
}
if ( F_22 () )
return;
if ( ! F_41 ( & V_112 , V_113 ) )
return;
if ( V_55 ) {
F_42 ( V_107 , false ,
V_55 , V_103 , & V_50 ) ;
V_7 = F_16 ( V_50 ) ;
}
if ( V_7 != 0 ) {
F_43 ( V_107 ) ;
F_42 ( V_107 , false ,
V_56 , V_57 , & V_50 ) ;
V_5 = V_67 ;
V_52 -> V_58 = F_17 ( V_59 ) ;
V_52 -> V_60 = F_17 ( V_50 ) ;
V_52 -> V_61 = F_18 ( F_19 () ) ;
}
( void ) F_1 ( & V_71 , V_53 ,
( int ) ( sizeof( * V_52 ) + V_50 ) , V_5 ,
++ V_110 ) ;
F_44 ( & V_112 , V_113 ) ;
}
static T_1 F_45 ( struct V_120 * V_120 , T_1 V_121 , int V_122 )
{
if ( V_16 . V_123 == NULL )
return - V_124 ;
return F_46 ( V_120 , V_121 , V_122 , V_125 ,
V_16 . V_123 () ) ;
}
static T_4 F_47 ( struct V_120 * V_120 , char T_5 * V_95 ,
T_3 V_72 , T_1 * V_126 )
{
T_4 V_33 ;
char * V_127 = NULL ;
T_4 V_13 ;
if ( ! V_16 . V_123 ) {
V_33 = - V_124 ;
goto V_29;
}
V_13 = V_16 . V_123 () ;
if ( V_13 < 0 ) {
V_33 = V_13 ;
goto V_29;
}
if ( * V_126 >= V_13 ) {
V_33 = 0 ;
goto V_29;
}
V_72 = F_48 ( T_3 , V_72 , V_13 - * V_126 ) ;
V_72 = F_49 ( V_72 , V_128 ) ;
V_127 = F_26 ( V_72 , V_91 ) ;
if ( ! V_127 ) {
V_33 = - V_92 ;
goto V_29;
}
V_33 = V_16 . V_20 ( V_127 , V_72 , V_126 ) ;
if ( V_33 <= 0 )
goto V_29;
if ( F_50 ( V_95 , V_127 , V_33 ) )
V_33 = - V_129 ;
V_29:
F_27 ( V_127 ) ;
return V_33 ;
}
static T_4 F_51 ( struct V_120 * V_120 , const char T_5 * V_95 ,
T_3 V_72 , T_1 * V_126 )
{
T_4 V_33 ;
char * V_127 = NULL ;
T_4 V_13 ;
V_33 = - V_124 ;
if ( ! V_16 . V_123 )
goto V_29;
V_33 = 0 ;
V_13 = V_16 . V_123 () ;
if ( * V_126 >= V_13 || V_13 < 0 )
goto V_29;
V_72 = F_48 ( T_3 , V_72 , V_13 - * V_126 ) ;
V_72 = F_49 ( V_72 , V_128 ) ;
V_33 = - V_92 ;
V_127 = F_26 ( V_72 , V_91 ) ;
if ( ! V_127 )
goto V_29;
V_33 = - V_129 ;
if ( F_52 ( V_127 , V_95 , V_72 ) )
goto V_29;
V_33 = V_16 . V_17 ( V_127 , V_72 , V_126 ) ;
V_29:
F_27 ( V_127 ) ;
return V_33 ;
}
static long F_53 ( struct V_120 * V_120 , unsigned int V_130 ,
unsigned long V_131 )
{
switch( V_130 ) {
#ifdef F_54
case V_132 :
F_55 ( V_133 L_25 ) ;
case V_134 : {
int V_2 , V_121 ;
if ( ! F_32 ( V_135 ) )
return - V_136 ;
if ( F_52 ( & V_2 , ( void T_5 * ) V_131 , sizeof( V_2 ) ) != 0 )
return - V_129 ;
if ( V_2 < V_137 || V_2 > V_138 )
return - V_136 ;
V_121 = F_56 ( V_2 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( F_50 ( ( void T_5 * ) V_131 , & V_121 , sizeof( V_121 ) ) != 0 )
return - V_129 ;
return 0 ;
}
#endif
default:
return - V_136 ;
}
}
static void T_2 F_57 ( char * V_139 )
{
struct V_140 * V_141 ;
F_55 ( V_133 L_26 , V_139 ) ;
F_55 ( V_133 L_27 ) ;
F_58 (tmp_part, &nvram_partitions, partition) {
F_55 ( V_133 L_28 ,
V_141 -> V_11 , V_141 -> V_142 . V_143 ,
V_141 -> V_142 . V_144 , V_141 -> V_142 . V_4 ,
V_141 -> V_142 . V_22 ) ;
}
}
static int T_2 F_59 ( struct V_140 * V_2 )
{
T_1 V_8 ;
int V_7 ;
struct V_145 V_146 ;
memcpy ( & V_146 , & V_2 -> V_142 , V_147 ) ;
V_146 . V_4 = F_17 ( V_146 . V_4 ) ;
V_8 = V_2 -> V_11 ;
V_7 = V_16 . V_17 ( ( char * ) & V_146 , V_147 , & V_8 ) ;
return V_7 ;
}
static unsigned char T_2 F_60 ( struct V_145 * V_21 )
{
unsigned int V_148 , V_149 ;
unsigned short * V_150 = ( unsigned short * ) V_21 -> V_22 ;
V_148 = V_21 -> V_143 + V_21 -> V_4 + V_150 [ 0 ] + V_150 [ 1 ] + V_150 [ 2 ] + V_150 [ 3 ] + V_150 [ 4 ] + V_150 [ 5 ] ;
V_148 = ( ( V_148 & 0xffff ) + ( V_148 >> 16 ) ) & 0xffff ;
V_149 = ( V_148 >> 8 ) + ( V_148 << 8 ) ;
V_148 = ( ( V_148 + V_149 ) >> 8 ) & 0xff ;
return V_148 ;
}
static int F_61 ( struct V_140 * V_2 ,
const char * V_22 , int V_75 , const char * V_151 [] )
{
if ( V_2 -> V_142 . V_143 != V_75 )
return 0 ;
if ( V_22 ) {
if ( strncmp ( V_22 , V_2 -> V_142 . V_22 , 12 ) )
return 0 ;
} else if ( V_151 ) {
const char * * V_152 ;
for ( V_152 = V_151 ; * V_152 ; V_152 ++ ) {
if ( ! strncmp ( * V_152 , V_2 -> V_142 . V_22 , 12 ) )
return 0 ;
}
}
return 1 ;
}
int T_2 F_9 ( const char * V_22 , int V_75 ,
const char * V_151 [] )
{
struct V_140 * V_2 , * V_153 , * V_127 ;
int V_7 ;
F_58 (part, &nvram_partitions, partition) {
if ( ! F_61 ( V_2 , V_22 , V_75 , V_151 ) )
continue;
V_2 -> V_142 . V_143 = V_154 ;
memset ( V_2 -> V_142 . V_22 , 'w' , 12 ) ;
V_2 -> V_142 . V_144 = F_60 ( & V_2 -> V_142 ) ;
V_7 = F_59 ( V_2 ) ;
if ( V_7 <= 0 ) {
F_55 ( V_155 L_29 , V_7 ) ;
return V_7 ;
}
}
V_153 = NULL ;
F_62 (part, tmp, &nvram_partitions, partition) {
if ( V_2 -> V_142 . V_143 != V_154 ) {
V_153 = NULL ;
continue;
}
if ( V_153 ) {
V_153 -> V_142 . V_4 += V_2 -> V_142 . V_4 ;
V_153 -> V_142 . V_144 = F_60 ( & V_153 -> V_142 ) ;
V_7 = F_59 ( V_153 ) ;
if ( V_7 <= 0 ) {
F_55 ( V_155 L_29 , V_7 ) ;
return V_7 ;
}
F_63 ( & V_2 -> V_156 ) ;
F_27 ( V_2 ) ;
} else
V_153 = V_2 ;
}
return 0 ;
}
T_1 T_2 F_10 ( const char * V_22 , int V_75 ,
int V_25 , int V_24 )
{
struct V_140 * V_2 ;
struct V_140 * V_157 ;
struct V_140 * V_158 = NULL ;
static char V_159 [ 16 ] ;
T_1 V_8 ;
long V_13 = 0 ;
int V_7 ;
V_25 = F_64 ( V_25 , V_160 ) / V_160 ;
V_24 = F_64 ( V_24 , V_160 ) / V_160 ;
if ( V_24 == 0 )
V_24 = V_25 ;
if ( V_24 > V_25 )
return - V_136 ;
V_25 += 1 ;
V_24 += 1 ;
F_58 (part, &nvram_partitions, partition) {
if ( V_2 -> V_142 . V_143 != V_154 )
continue;
if ( V_2 -> V_142 . V_4 >= V_25 ) {
V_13 = V_25 ;
V_158 = V_2 ;
break;
}
if ( V_2 -> V_142 . V_4 > V_13 &&
V_2 -> V_142 . V_4 >= V_24 ) {
V_13 = V_2 -> V_142 . V_4 ;
V_158 = V_2 ;
}
}
if ( ! V_13 )
return - V_26 ;
V_157 = F_26 ( sizeof( * V_157 ) , V_91 ) ;
if ( ! V_157 ) {
F_3 ( L_30 , V_18 ) ;
return - V_92 ;
}
V_157 -> V_11 = V_158 -> V_11 ;
V_157 -> V_142 . V_143 = V_75 ;
V_157 -> V_142 . V_4 = V_13 ;
strncpy ( V_157 -> V_142 . V_22 , V_22 , 12 ) ;
V_157 -> V_142 . V_144 = F_60 ( & V_157 -> V_142 ) ;
V_7 = F_59 ( V_157 ) ;
if ( V_7 <= 0 ) {
F_3 ( L_31 , V_18 , V_7 ) ;
F_27 ( V_157 ) ;
return V_7 ;
}
F_65 ( & V_157 -> V_156 , & V_158 -> V_156 ) ;
if ( V_158 -> V_142 . V_4 > V_13 ) {
V_158 -> V_11 += V_13 * V_160 ;
V_158 -> V_142 . V_4 -= V_13 ;
V_158 -> V_142 . V_144 = F_60 ( & V_158 -> V_142 ) ;
V_7 = F_59 ( V_158 ) ;
if ( V_7 <= 0 ) {
F_3 ( L_31 ,
V_18 , V_7 ) ;
return V_7 ;
}
} else {
F_63 ( & V_158 -> V_156 ) ;
F_27 ( V_158 ) ;
}
for ( V_8 = V_157 -> V_11 + V_147 ;
V_8 < ( ( V_13 - 1 ) * V_160 ) ;
V_8 += V_160 ) {
V_7 = V_16 . V_17 ( V_159 , V_160 , & V_8 ) ;
if ( V_7 <= 0 ) {
F_3 ( L_32 ,
V_18 , V_7 ) ;
return V_7 ;
}
}
return V_157 -> V_11 + V_147 ;
}
int F_11 ( T_1 V_161 )
{
struct V_140 * V_2 ;
F_58 (part, &nvram_partitions, partition) {
if ( V_2 -> V_11 + V_147 == V_161 )
return ( V_2 -> V_142 . V_4 - 1 ) * V_160 ;
}
return - 1 ;
}
T_1 F_7 ( const char * V_22 , int V_75 , int * V_162 )
{
struct V_140 * V_21 ;
F_58 (p, &nvram_partitions, partition) {
if ( V_21 -> V_142 . V_143 == V_75 &&
( ! V_22 || ! strncmp ( V_21 -> V_142 . V_22 , V_22 , 12 ) ) ) {
if ( V_162 )
* V_162 = ( V_21 -> V_142 . V_4 - 1 ) *
V_160 ;
return V_21 -> V_11 + V_147 ;
}
}
return 0 ;
}
int T_2 F_66 ( void )
{
T_1 V_163 = 0 ;
struct V_145 V_146 ;
struct V_140 * V_141 ;
unsigned char V_148 ;
char * V_142 ;
int V_164 ;
int V_32 ;
if ( V_16 . V_123 == NULL || V_16 . V_123 () <= 0 )
return - V_124 ;
V_164 = V_16 . V_123 () ;
V_142 = F_26 ( V_147 , V_91 ) ;
if ( ! V_142 ) {
F_55 ( V_155 L_33 ) ;
return - V_92 ;
}
while ( V_163 < V_164 ) {
V_32 = V_16 . V_20 ( V_142 , V_147 , & V_163 ) ;
if ( V_32 != V_147 ) {
F_55 ( V_155 L_34
L_35 ) ;
goto V_29;
}
V_163 -= V_147 ;
memcpy ( & V_146 , V_142 , V_147 ) ;
V_146 . V_4 = F_28 ( V_146 . V_4 ) ;
V_32 = 0 ;
V_148 = F_60 ( & V_146 ) ;
if ( V_148 != V_146 . V_144 ) {
F_55 ( V_133 L_36
L_37 ,
V_146 . V_144 , V_148 ) ;
F_55 ( V_133 L_38 ) ;
goto V_29;
}
if ( ! V_146 . V_4 ) {
F_55 ( V_133 L_39
L_40 ) ;
goto V_29;
}
V_141 = F_26 ( sizeof( struct V_140 ) , V_91 ) ;
V_32 = - V_92 ;
if ( ! V_141 ) {
F_55 ( V_155 L_41 ) ;
goto V_29;
}
memcpy ( & V_141 -> V_142 , & V_146 , V_147 ) ;
V_141 -> V_11 = V_163 ;
F_65 ( & V_141 -> V_156 , & V_165 ) ;
V_163 += V_146 . V_4 * V_160 ;
}
V_32 = 0 ;
#ifdef F_67
F_57 ( L_42 ) ;
#endif
V_29:
F_27 ( V_142 ) ;
return V_32 ;
}
static int T_2 F_68 ( void )
{
int V_7 ;
F_69 ( V_160 != 16 ) ;
if ( V_16 . V_123 == NULL || V_16 . V_123 () <= 0 )
return - V_124 ;
V_7 = F_70 ( & V_166 ) ;
if ( V_7 != 0 ) {
F_55 ( V_155 L_43 ) ;
return V_7 ;
}
return V_7 ;
}
