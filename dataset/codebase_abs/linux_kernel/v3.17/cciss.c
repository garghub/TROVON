static void F_1 ( T_1 * V_1 )
{
}
static void F_2 ( T_1 * V_1 , T_2 * V_2 )
{
if ( F_3 ( V_1 -> V_3 & V_4 ) )
V_2 -> V_5 |= 1 | ( V_1 -> V_6 [ V_2 -> V_7 . V_8 ] << 1 ) ;
}
static inline void F_4 ( struct V_9 * V_10 , T_2 * V_2 )
{
F_5 ( & V_2 -> V_10 , V_10 ) ;
}
static inline void F_6 ( T_2 * V_2 )
{
if ( F_7 ( F_8 ( & V_2 -> V_10 ) ) ) {
V_2 -> V_11 = V_12 ;
return;
}
F_9 ( & V_2 -> V_10 ) ;
}
static void F_10 ( T_1 * V_1 ,
T_2 * V_2 )
{
unsigned long V_13 ;
F_2 ( V_1 , V_2 ) ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
F_4 ( & V_1 -> V_15 , V_2 ) ;
V_1 -> V_16 ++ ;
if ( V_1 -> V_16 > V_1 -> V_17 )
V_1 -> V_17 = V_1 -> V_16 ;
F_12 ( V_1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
}
static void F_14 ( T_3 * * V_18 ,
int V_19 )
{
int V_20 ;
if ( ! V_18 )
return;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
F_15 ( V_18 [ V_20 ] ) ;
V_18 [ V_20 ] = NULL ;
}
F_15 ( V_18 ) ;
}
static T_3 * * F_16 (
T_1 * V_1 , int V_21 , int V_19 )
{
int V_22 ;
T_3 * * V_18 ;
if ( V_21 <= 0 )
return NULL ;
V_18 = F_17 ( sizeof( * V_18 ) * V_19 , V_23 ) ;
if ( ! V_18 )
return NULL ;
for ( V_22 = 0 ; V_22 < V_19 ; V_22 ++ ) {
V_18 [ V_22 ] = F_17 ( ( V_21 *
sizeof( * V_18 [ V_22 ] ) ) , V_23 ) ;
if ( ! V_18 [ V_22 ] ) {
F_18 ( & V_1 -> V_24 -> V_25 , L_1
L_2 ) ;
goto V_26;
}
}
return V_18 ;
V_26:
F_14 ( V_18 , V_19 ) ;
return NULL ;
}
static void F_19 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 * V_27 ;
T_4 V_28 ;
if ( V_2 -> V_7 . V_29 <= V_1 -> V_30 )
return;
V_27 = & V_2 -> V_31 [ V_1 -> V_30 - 1 ] ;
V_28 . V_32 . V_33 = V_27 -> V_34 . V_33 ;
V_28 . V_32 . V_35 = V_27 -> V_34 . V_35 ;
F_20 ( V_1 -> V_24 , V_28 . V_36 , V_27 -> V_37 , V_38 ) ;
}
static void F_21 ( T_1 * V_1 , T_2 * V_2 ,
T_3 * V_39 , int V_40 )
{
T_3 * V_27 ;
T_4 V_28 ;
V_27 = & V_2 -> V_31 [ V_1 -> V_30 - 1 ] ;
V_27 -> V_41 = V_42 ;
V_27 -> V_37 = V_40 ;
V_28 . V_36 = F_22 ( V_1 -> V_24 , V_39 , V_40 ,
V_38 ) ;
V_27 -> V_34 . V_33 = V_28 . V_32 . V_33 ;
V_27 -> V_34 . V_35 = V_28 . V_32 . V_35 ;
}
static void F_23 ( struct V_43 * V_44 )
{
T_1 * V_1 = V_44 -> V_45 ;
F_24 ( V_44 , L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11
L_12 ,
V_1 -> V_46 ,
V_1 -> V_47 ,
( unsigned long ) V_1 -> V_48 ,
V_1 -> V_49 [ 0 ] , V_1 -> V_49 [ 1 ] , V_1 -> V_49 [ 2 ] ,
V_1 -> V_49 [ 3 ] , ( unsigned int ) V_1 -> V_50 [ V_1 -> V_51 ] ,
V_1 -> V_52 ,
V_1 -> V_16 , V_1 -> V_53 ,
V_1 -> V_17 , V_1 -> V_54 , V_1 -> V_55 ) ;
#ifdef F_25
F_26 ( V_44 , V_1 ) ;
#endif
}
static void * F_27 ( struct V_43 * V_44 , T_5 * V_56 )
{
T_1 * V_1 = V_44 -> V_45 ;
unsigned long V_13 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return F_28 ( - V_58 ) ;
}
V_1 -> V_57 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( * V_56 == 0 )
F_23 ( V_44 ) ;
return V_56 ;
}
static int F_29 ( struct V_43 * V_44 , void * V_59 )
{
T_6 V_60 , V_61 ;
T_1 * V_1 = V_44 -> V_45 ;
unsigned V_62 = V_1 -> V_62 ;
T_5 * V_56 = V_59 ;
T_7 * V_63 = V_1 -> V_63 [ * V_56 ] ;
if ( * V_56 > V_1 -> V_64 )
return 0 ;
if ( V_63 == NULL )
return 0 ;
if ( V_63 -> V_65 == 0 )
return 0 ;
V_60 = V_63 -> V_66 ;
V_61 = F_30 ( V_60 , V_67 ) ;
V_61 *= 100 ;
F_30 ( V_61 , V_67 ) ;
if ( V_63 -> V_68 < 0 || V_63 -> V_68 > V_69 )
V_63 -> V_68 = V_69 ;
F_24 ( V_44 , L_13
L_14 ,
V_62 , ( int ) * V_56 , ( int ) V_60 , ( int ) V_61 ,
V_70 [ V_63 -> V_68 ] ) ;
return 0 ;
}
static void * F_31 ( struct V_43 * V_44 , void * V_59 , T_5 * V_56 )
{
T_1 * V_1 = V_44 -> V_45 ;
if ( * V_56 > V_1 -> V_64 )
return NULL ;
* V_56 += 1 ;
return V_56 ;
}
static void F_32 ( struct V_43 * V_44 , void * V_59 )
{
T_1 * V_1 = V_44 -> V_45 ;
if ( V_59 == F_28 ( - V_58 ) )
return;
V_1 -> V_57 = 0 ;
}
static int F_33 ( struct V_71 * V_71 , struct V_72 * V_72 )
{
int V_73 = F_34 ( V_72 , & V_74 ) ;
struct V_43 * V_44 = V_72 -> V_75 ;
if ( ! V_73 )
V_44 -> V_45 = F_35 ( V_71 ) ;
return V_73 ;
}
static T_8
F_36 ( struct V_72 * V_72 , const char T_9 * V_76 ,
T_10 V_77 , T_5 * V_78 )
{
int V_79 ;
char * V_80 ;
#ifndef F_25
return - V_81 ;
#endif
if ( ! V_76 || V_77 > V_82 - 1 )
return - V_81 ;
V_80 = ( char * ) F_37 ( V_23 ) ;
if ( ! V_80 )
return - V_83 ;
V_79 = - V_84 ;
if ( F_38 ( V_80 , V_76 , V_77 ) )
goto V_85;
V_80 [ V_77 ] = '\0' ;
#ifdef F_25
if ( strncmp ( V_86 , V_80 , sizeof V_86 - 1 ) == 0 ) {
struct V_43 * V_44 = V_72 -> V_75 ;
T_1 * V_1 = V_44 -> V_45 ;
V_79 = F_39 ( V_1 ) ;
if ( V_79 == 0 )
V_79 = V_77 ;
} else
#endif
V_79 = - V_81 ;
V_85:
F_40 ( ( unsigned long ) V_80 ) ;
return V_79 ;
}
static void F_1 ( T_1 * V_1 )
{
struct V_87 * V_88 ;
if ( V_89 == NULL )
V_89 = F_41 ( L_15 , NULL ) ;
if ( ! V_89 )
return;
V_88 = F_42 ( V_1 -> V_46 , V_90 | V_91 | V_92 |
V_93 , V_89 ,
& V_94 , V_1 ) ;
}
static int F_43 ( T_11 V_48 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < F_44 ( V_95 ) ; V_20 ++ )
if ( V_95 [ V_20 ] == V_48 )
return 0 ;
return 1 ;
}
static int F_45 ( T_11 V_48 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < F_44 ( V_96 ) ; V_20 ++ )
if ( V_96 [ V_20 ] == V_48 )
return 0 ;
return 1 ;
}
static int F_46 ( T_11 V_48 )
{
return F_43 ( V_48 ) ||
F_45 ( V_48 ) ;
}
static T_8 F_47 ( struct V_97 * V_25 ,
struct V_98 * V_99 ,
char * V_76 )
{
struct V_100 * V_1 = F_48 ( V_25 ) ;
return snprintf ( V_76 , 20 , L_16 , F_46 ( V_1 -> V_48 ) ) ;
}
static T_8 F_49 ( struct V_97 * V_25 ,
struct V_98 * V_99 ,
const char * V_76 , T_10 V_101 )
{
struct V_100 * V_1 = F_48 ( V_25 ) ;
F_50 ( V_1 ) ;
F_51 ( V_102 ) ;
F_52 ( & V_1 -> V_103 ) ;
return V_101 ;
}
static T_8 F_53 ( struct V_97 * V_25 ,
struct V_98 * V_99 ,
char * V_76 )
{
struct V_100 * V_1 = F_48 ( V_25 ) ;
return snprintf ( V_76 , 20 , L_17 ,
V_1 -> V_3 & V_4 ?
L_18 : L_19 ) ;
}
static T_8 F_54 ( struct V_97 * V_25 ,
struct V_98 * V_99 ,
char * V_76 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_100 * V_1 = F_48 ( V_63 -> V_25 . V_104 ) ;
T_12 V_105 [ 16 ] ;
unsigned long V_13 ;
int V_73 = 0 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 )
V_73 = - V_58 ;
else
memcpy ( V_105 , V_63 -> V_106 , sizeof( V_105 ) ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_73 )
return V_73 ;
else
return snprintf ( V_76 , 16 * 2 + 2 ,
L_20
L_21 ,
V_105 [ 0 ] , V_105 [ 1 ] , V_105 [ 2 ] , V_105 [ 3 ] ,
V_105 [ 4 ] , V_105 [ 5 ] , V_105 [ 6 ] , V_105 [ 7 ] ,
V_105 [ 8 ] , V_105 [ 9 ] , V_105 [ 10 ] , V_105 [ 11 ] ,
V_105 [ 12 ] , V_105 [ 13 ] , V_105 [ 14 ] , V_105 [ 15 ] ) ;
}
static T_8 F_56 ( struct V_97 * V_25 ,
struct V_98 * V_99 ,
char * V_76 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_100 * V_1 = F_48 ( V_63 -> V_25 . V_104 ) ;
char V_107 [ V_108 + 1 ] ;
unsigned long V_13 ;
int V_73 = 0 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 )
V_73 = - V_58 ;
else
memcpy ( V_107 , V_63 -> V_107 , V_108 + 1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_73 )
return V_73 ;
else
return snprintf ( V_76 , sizeof( V_107 ) + 1 , L_17 , V_63 -> V_107 ) ;
}
static T_8 F_57 ( struct V_97 * V_25 ,
struct V_98 * V_99 ,
char * V_76 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_100 * V_1 = F_48 ( V_63 -> V_25 . V_104 ) ;
char V_109 [ V_110 + 1 ] ;
unsigned long V_13 ;
int V_73 = 0 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 )
V_73 = - V_58 ;
else
memcpy ( V_109 , V_63 -> V_109 , V_110 + 1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_73 )
return V_73 ;
else
return snprintf ( V_76 , sizeof( V_109 ) + 1 , L_17 , V_63 -> V_109 ) ;
}
static T_8 F_58 ( struct V_97 * V_25 ,
struct V_98 * V_99 ,
char * V_76 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_100 * V_1 = F_48 ( V_63 -> V_25 . V_104 ) ;
char V_111 [ V_112 + 1 ] ;
unsigned long V_13 ;
int V_73 = 0 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 )
V_73 = - V_58 ;
else
memcpy ( V_111 , V_63 -> V_111 , V_112 + 1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_73 )
return V_73 ;
else
return snprintf ( V_76 , sizeof( V_111 ) + 1 , L_17 , V_63 -> V_111 ) ;
}
static T_8 F_59 ( struct V_97 * V_25 ,
struct V_98 * V_99 , char * V_76 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_100 * V_1 = F_48 ( V_63 -> V_25 . V_104 ) ;
unsigned long V_13 ;
unsigned char V_113 [ 8 ] ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_58 ;
}
if ( ! V_63 -> V_65 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_114 ;
}
memcpy ( V_113 , V_63 -> V_115 , sizeof( V_113 ) ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
return snprintf ( V_76 , 20 , L_22 ,
V_113 [ 0 ] , V_113 [ 1 ] , V_113 [ 2 ] , V_113 [ 3 ] ,
V_113 [ 4 ] , V_113 [ 5 ] , V_113 [ 6 ] , V_113 [ 7 ] ) ;
}
static T_8 F_60 ( struct V_97 * V_25 ,
struct V_98 * V_99 , char * V_76 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_100 * V_1 = F_48 ( V_63 -> V_25 . V_104 ) ;
int V_116 ;
unsigned long V_13 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_58 ;
}
V_116 = V_63 -> V_68 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_116 < 0 || V_116 > V_69 )
V_116 = V_69 ;
return snprintf ( V_76 , strlen ( V_70 [ V_116 ] ) + 7 , L_23 ,
V_70 [ V_116 ] ) ;
}
static T_8 F_61 ( struct V_97 * V_25 ,
struct V_98 * V_99 , char * V_76 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_100 * V_1 = F_48 ( V_63 -> V_25 . V_104 ) ;
unsigned long V_13 ;
int V_101 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_58 ;
}
V_101 = V_63 -> V_117 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
return snprintf ( V_76 , 20 , L_16 , V_101 ) ;
}
static void F_62 ( struct V_97 * V_25 )
{
}
static int F_63 ( struct V_100 * V_1 )
{
F_64 ( & V_1 -> V_25 ) ;
V_1 -> V_25 . type = & V_118 ;
V_1 -> V_25 . V_119 = & V_120 ;
F_65 ( & V_1 -> V_25 , L_24 , V_1 -> V_46 ) ;
V_1 -> V_25 . V_104 = & V_1 -> V_24 -> V_25 ;
return F_66 ( & V_1 -> V_25 ) ;
}
static void F_67 ( struct V_100 * V_1 )
{
F_68 ( & V_1 -> V_25 ) ;
F_69 ( & V_1 -> V_25 ) ;
}
static void F_70 ( struct V_97 * V_25 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
F_15 ( V_63 ) ;
}
static long F_71 ( struct V_100 * V_1 ,
int V_121 )
{
struct V_97 * V_25 ;
if ( V_1 -> V_63 [ V_121 ] -> V_122 )
return 0 ;
V_25 = & V_1 -> V_63 [ V_121 ] -> V_25 ;
F_64 ( V_25 ) ;
V_25 -> type = & V_123 ;
V_25 -> V_119 = & V_120 ;
F_65 ( V_25 , L_25 , V_1 -> V_62 , V_121 ) ;
V_25 -> V_104 = & V_1 -> V_25 ;
V_1 -> V_63 [ V_121 ] -> V_122 = 1 ;
return F_66 ( V_25 ) ;
}
static void F_72 ( struct V_100 * V_1 , int V_121 ,
int V_124 )
{
struct V_97 * V_25 = & V_1 -> V_63 [ V_121 ] -> V_25 ;
if ( V_121 == 0 && ! V_124 )
return;
F_68 ( V_25 ) ;
F_69 ( V_25 ) ;
V_1 -> V_63 [ V_121 ] = NULL ;
}
static T_2 * F_73 ( T_1 * V_1 )
{
T_2 * V_2 ;
int V_20 ;
T_4 V_28 ;
T_13 V_125 , V_126 ;
do {
V_20 = F_74 ( V_1 -> V_127 , V_1 -> V_19 ) ;
if ( V_20 == V_1 -> V_19 )
return NULL ;
} while ( F_75 ( V_20 , V_1 -> V_127 ) != 0 );
V_2 = V_1 -> V_128 + V_20 ;
memset ( V_2 , 0 , sizeof( T_2 ) ) ;
V_125 = V_1 -> V_129 + V_20 * sizeof( T_2 ) ;
V_2 -> V_130 = V_1 -> V_131 + V_20 ;
memset ( V_2 -> V_130 , 0 , sizeof( V_132 ) ) ;
V_126 = V_1 -> V_133
+ V_20 * sizeof( V_132 ) ;
V_1 -> V_134 ++ ;
V_2 -> V_135 = V_20 ;
F_76 ( & V_2 -> V_10 ) ;
V_2 -> V_5 = ( V_136 ) V_125 ;
V_28 . V_36 = ( V_137 ) V_126 ;
V_2 -> V_138 . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_138 . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_138 . V_37 = sizeof( V_132 ) ;
V_2 -> V_62 = V_1 -> V_62 ;
return V_2 ;
}
static T_2 * F_77 ( T_1 * V_1 )
{
T_2 * V_2 ;
T_4 V_28 ;
T_13 V_125 , V_126 ;
V_2 = F_78 ( V_1 -> V_24 , sizeof( T_2 ) ,
& V_125 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_135 = - 1 ;
V_2 -> V_130 = F_78 ( V_1 -> V_24 , sizeof( V_132 ) ,
& V_126 ) ;
if ( V_2 -> V_130 == NULL ) {
F_79 ( V_1 -> V_24 ,
sizeof( T_2 ) , V_2 , V_125 ) ;
return NULL ;
}
F_76 ( & V_2 -> V_10 ) ;
V_2 -> V_5 = ( V_136 ) V_125 ;
V_28 . V_36 = ( V_137 ) V_126 ;
V_2 -> V_138 . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_138 . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_138 . V_37 = sizeof( V_132 ) ;
V_2 -> V_62 = V_1 -> V_62 ;
return V_2 ;
}
static void F_80 ( T_1 * V_1 , T_2 * V_2 )
{
int V_20 ;
V_20 = V_2 - V_1 -> V_128 ;
F_81 ( V_20 , V_1 -> V_127 ) ;
V_1 -> V_139 ++ ;
}
static void F_82 ( T_1 * V_1 , T_2 * V_2 )
{
T_4 V_28 ;
V_28 . V_32 . V_33 = V_2 -> V_138 . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_2 -> V_138 . V_34 . V_35 ;
F_79 ( V_1 -> V_24 , sizeof( V_132 ) ,
V_2 -> V_130 , ( T_13 ) V_28 . V_36 ) ;
F_79 ( V_1 -> V_24 , sizeof( T_2 ) , V_2 ,
( T_13 ) F_83 ( V_1 , ( T_11 ) V_2 -> V_5 ) ) ;
}
static inline T_1 * F_84 ( struct V_140 * V_141 )
{
return V_141 -> V_142 -> V_143 ;
}
static inline T_7 * F_85 ( struct V_140 * V_141 )
{
return V_141 -> V_75 ;
}
static int F_86 ( struct V_144 * V_145 , T_14 V_146 )
{
T_1 * V_1 = F_84 ( V_145 -> V_147 ) ;
T_7 * V_63 = F_85 ( V_145 -> V_147 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_26 , V_145 -> V_147 -> V_148 ) ;
if ( V_63 -> V_57 )
return - V_58 ;
if ( V_63 -> V_65 == 0 ) {
if ( F_88 ( V_145 -> V_149 ) != 0 ) {
if ( F_88 ( V_145 -> V_149 ) & 0x0f ) {
return - V_150 ;
} else if ( memcmp ( V_63 -> V_115 , V_151 ,
sizeof( V_63 -> V_115 ) ) ) {
return - V_150 ;
}
}
if ( ! F_89 ( V_152 ) )
return - V_153 ;
}
V_63 -> V_117 ++ ;
V_1 -> V_117 ++ ;
return 0 ;
}
static int F_90 ( struct V_144 * V_145 , T_14 V_146 )
{
int V_73 ;
F_91 ( & V_154 ) ;
V_73 = F_86 ( V_145 , V_146 ) ;
F_92 ( & V_154 ) ;
return V_73 ;
}
static void F_93 ( struct V_140 * V_141 , T_14 V_146 )
{
T_1 * V_1 ;
T_7 * V_63 ;
F_91 ( & V_154 ) ;
V_1 = F_84 ( V_141 ) ;
V_63 = F_85 ( V_141 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_27 , V_141 -> V_148 ) ;
V_63 -> V_117 -- ;
V_1 -> V_117 -- ;
F_92 ( & V_154 ) ;
}
static int F_94 ( struct V_144 * V_145 , T_14 V_146 ,
unsigned V_155 , unsigned long V_156 )
{
switch ( V_155 ) {
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
return F_95 ( V_145 , V_146 , V_155 , V_156 ) ;
case V_172 :
return F_96 ( V_145 , V_146 , V_155 , V_156 ) ;
case V_173 :
return F_97 ( V_145 , V_146 , V_155 , V_156 ) ;
default:
return - V_174 ;
}
}
static int F_96 ( struct V_144 * V_145 , T_14 V_146 ,
unsigned V_155 , unsigned long V_156 )
{
T_15 T_9 * V_175 =
( T_15 T_9 * ) V_156 ;
T_16 V_176 ;
T_16 T_9 * V_177 = F_98 ( sizeof( V_176 ) ) ;
int V_79 ;
T_11 V_178 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_79 = 0 ;
V_79 |=
F_38 ( & V_176 . V_179 , & V_175 -> V_179 ,
sizeof( V_176 . V_179 ) ) ;
V_79 |=
F_38 ( & V_176 . V_180 , & V_175 -> V_180 ,
sizeof( V_176 . V_180 ) ) ;
V_79 |=
F_38 ( & V_176 . V_181 , & V_175 -> V_181 ,
sizeof( V_176 . V_181 ) ) ;
V_79 |= F_99 ( V_176 . V_182 , & V_175 -> V_182 ) ;
V_79 |= F_99 ( V_178 , & V_175 -> V_76 ) ;
V_176 . V_76 = F_100 ( V_178 ) ;
V_79 |= F_101 ( V_177 , & V_176 , sizeof( V_176 ) ) ;
if ( V_79 )
return - V_84 ;
V_79 = F_95 ( V_145 , V_146 , V_183 , ( unsigned long ) V_177 ) ;
if ( V_79 )
return V_79 ;
V_79 |=
F_102 ( & V_175 -> V_181 , & V_177 -> V_181 ,
sizeof( V_175 -> V_181 ) ) ;
if ( V_79 )
return - V_84 ;
return V_79 ;
}
static int F_97 ( struct V_144 * V_145 , T_14 V_146 ,
unsigned V_155 , unsigned long V_156 )
{
T_17 T_9 * V_175 =
( T_17 T_9 * ) V_156 ;
T_18 V_176 ;
T_18 T_9 * V_177 =
F_98 ( sizeof( V_176 ) ) ;
int V_79 ;
T_11 V_178 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_79 = 0 ;
V_79 |=
F_38 ( & V_176 . V_179 , & V_175 -> V_179 ,
sizeof( V_176 . V_179 ) ) ;
V_79 |=
F_38 ( & V_176 . V_180 , & V_175 -> V_180 ,
sizeof( V_176 . V_180 ) ) ;
V_79 |=
F_38 ( & V_176 . V_181 , & V_175 -> V_181 ,
sizeof( V_176 . V_181 ) ) ;
V_79 |= F_99 ( V_176 . V_182 , & V_175 -> V_182 ) ;
V_79 |= F_99 ( V_176 . V_184 , & V_175 -> V_184 ) ;
V_79 |= F_99 ( V_178 , & V_175 -> V_76 ) ;
V_176 . V_76 = F_100 ( V_178 ) ;
V_79 |= F_101 ( V_177 , & V_176 , sizeof( V_176 ) ) ;
if ( V_79 )
return - V_84 ;
V_79 = F_95 ( V_145 , V_146 , V_185 , ( unsigned long ) V_177 ) ;
if ( V_79 )
return V_79 ;
V_79 |=
F_102 ( & V_175 -> V_181 , & V_177 -> V_181 ,
sizeof( V_175 -> V_181 ) ) ;
if ( V_79 )
return - V_84 ;
return V_79 ;
}
static int F_103 ( struct V_144 * V_145 , struct V_186 * V_187 )
{
T_7 * V_63 = F_85 ( V_145 -> V_147 ) ;
if ( ! V_63 -> V_188 )
return - V_150 ;
V_187 -> V_65 = V_63 -> V_65 ;
V_187 -> V_189 = V_63 -> V_189 ;
V_187 -> V_188 = V_63 -> V_188 ;
return 0 ;
}
static void F_104 ( T_1 * V_1 , T_2 * V_2 )
{
if ( V_2 -> V_130 -> V_190 == V_191 &&
V_2 -> V_130 -> V_192 != V_193 )
( void ) F_105 ( V_1 , V_2 ) ;
}
static int F_106 ( T_1 * V_1 , void T_9 * V_194 )
{
T_19 V_195 ;
if ( ! V_194 )
return - V_81 ;
V_195 . V_196 = F_107 ( V_1 -> V_24 -> V_119 ) ;
V_195 . V_119 = V_1 -> V_24 -> V_119 -> V_197 ;
V_195 . V_198 = V_1 -> V_24 -> V_199 ;
V_195 . V_48 = V_1 -> V_48 ;
if ( F_101 ( V_194 , & V_195 , sizeof( T_19 ) ) )
return - V_84 ;
return 0 ;
}
static int F_108 ( T_1 * V_1 , void T_9 * V_194 )
{
T_20 V_200 ;
unsigned long V_13 ;
if ( ! V_194 )
return - V_81 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_200 . V_201 = F_109 ( & V_1 -> V_202 -> V_203 . V_204 ) ;
V_200 . V_101 = F_109 ( & V_1 -> V_202 -> V_203 . V_205 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( F_101
( V_194 , & V_200 , sizeof( T_20 ) ) )
return - V_84 ;
return 0 ;
}
static int F_110 ( T_1 * V_1 , void T_9 * V_194 )
{
T_20 V_200 ;
unsigned long V_13 ;
int V_20 ;
if ( ! V_194 )
return - V_81 ;
if ( ! F_89 ( V_152 ) )
return - V_153 ;
if ( F_38 ( & V_200 , V_194 , sizeof( V_200 ) ) )
return - V_84 ;
if ( ( V_200 . V_201 == 0 ) && ( V_200 . V_101 == 0 ) )
return - V_81 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
F_111 ( V_200 . V_201 , & ( V_1 -> V_202 -> V_203 . V_204 ) ) ;
F_111 ( V_200 . V_101 , & ( V_1 -> V_202 -> V_203 . V_205 ) ) ;
F_111 ( V_206 , V_1 -> V_207 + V_208 ) ;
for ( V_20 = 0 ; V_20 < V_209 ; V_20 ++ ) {
if ( ! ( F_109 ( V_1 -> V_207 + V_208 ) & V_206 ) )
break;
F_112 ( 1000 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_20 >= V_209 )
return - V_210 ;
return 0 ;
}
static int F_113 ( T_1 * V_1 , void T_9 * V_194 )
{
T_21 V_211 ;
unsigned long V_13 ;
int V_20 ;
if ( ! V_194 )
return - V_81 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
V_211 [ V_20 ] = F_114 ( & V_1 -> V_202 -> V_212 [ V_20 ] ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( F_101 ( V_194 , V_211 , sizeof( T_21 ) ) )
return - V_84 ;
return 0 ;
}
static int F_115 ( T_1 * V_1 , void T_9 * V_194 )
{
T_21 V_211 ;
unsigned long V_13 ;
int V_20 ;
if ( ! V_194 )
return - V_81 ;
if ( ! F_89 ( V_152 ) )
return - V_153 ;
if ( F_38 ( V_211 , V_194 , sizeof( T_21 ) ) )
return - V_84 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
F_116 ( V_211 [ V_20 ] , & V_1 -> V_202 -> V_212 [ V_20 ] ) ;
F_111 ( V_206 , V_1 -> V_207 + V_208 ) ;
for ( V_20 = 0 ; V_20 < V_209 ; V_20 ++ ) {
if ( ! ( F_109 ( V_1 -> V_207 + V_208 ) & V_206 ) )
break;
F_112 ( 1000 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_20 >= V_209 )
return - V_210 ;
return 0 ;
}
static int F_117 ( T_1 * V_1 , void T_9 * V_194 )
{
T_22 V_213 ;
unsigned long V_13 ;
if ( ! V_194 )
return - V_81 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_213 = F_109 ( & V_1 -> V_202 -> V_214 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( F_101 ( V_194 , & V_213 , sizeof( T_22 ) ) )
return - V_84 ;
return 0 ;
}
static int F_118 ( T_1 * V_1 , void T_9 * V_194 )
{
T_23 V_215 ;
unsigned long V_13 ;
if ( ! V_194 )
return - V_81 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_215 = F_109 ( & V_1 -> V_202 -> V_215 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( F_101 ( V_194 , & V_215 , sizeof( T_23 ) ) )
return - V_84 ;
return 0 ;
}
static int F_119 ( T_1 * V_1 , void T_9 * V_194 )
{
T_24 V_216 ;
if ( ! V_194 )
return - V_81 ;
memcpy ( V_216 , V_1 -> V_49 , 4 ) ;
if ( F_101
( V_194 , V_216 , sizeof( T_24 ) ) )
return - V_84 ;
return 0 ;
}
static int F_120 ( T_1 * V_1 , void T_9 * V_194 )
{
T_25 V_217 = V_218 ;
if ( ! V_194 )
return - V_81 ;
if ( F_101 ( V_194 , & V_217 , sizeof( T_25 ) ) )
return - V_84 ;
return 0 ;
}
static int F_121 ( T_1 * V_1 ,
struct V_140 * V_141 , void T_9 * V_194 )
{
T_26 V_219 ;
T_7 * V_63 = F_85 ( V_141 ) ;
if ( ! V_194 )
return - V_81 ;
memcpy ( & V_219 . V_115 , V_63 -> V_115 , sizeof( V_219 . V_115 ) ) ;
V_219 . V_220 = V_63 -> V_117 ;
V_219 . V_221 = 0 ;
if ( F_101 ( V_194 , & V_219 , sizeof( T_26 ) ) )
return - V_84 ;
return 0 ;
}
static int F_122 ( T_1 * V_1 , void T_9 * V_194 )
{
T_16 V_222 ;
T_2 * V_2 ;
char * V_223 = NULL ;
T_4 V_28 ;
F_123 ( V_224 ) ;
if ( ! V_194 )
return - V_81 ;
if ( ! F_89 ( V_225 ) )
return - V_153 ;
if ( F_38
( & V_222 , V_194 , sizeof( T_16 ) ) )
return - V_84 ;
if ( ( V_222 . V_182 < 1 ) &&
( V_222 . V_180 . Type . V_226 != V_227 ) ) {
return - V_81 ;
}
if ( V_222 . V_182 > 0 ) {
V_223 = F_17 ( V_222 . V_182 , V_23 ) ;
if ( V_223 == NULL )
return - V_84 ;
}
if ( V_222 . V_180 . Type . V_226 == V_228 ) {
if ( F_38 ( V_223 , V_222 . V_76 , V_222 . V_182 ) ) {
F_15 ( V_223 ) ;
return - V_84 ;
}
} else {
memset ( V_223 , 0 , V_222 . V_182 ) ;
}
V_2 = F_77 ( V_1 ) ;
if ( ! V_2 ) {
F_15 ( V_223 ) ;
return - V_83 ;
}
V_2 -> V_11 = V_229 ;
V_2 -> V_7 . V_230 = 0 ;
if ( V_222 . V_182 > 0 ) {
V_2 -> V_7 . V_8 = 1 ;
V_2 -> V_7 . V_29 = 1 ;
} else {
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_7 . V_29 = 0 ;
}
V_2 -> V_7 . V_231 = V_222 . V_179 ;
V_2 -> V_7 . V_232 . V_33 = V_2 -> V_5 ;
V_2 -> V_180 = V_222 . V_180 ;
if ( V_222 . V_182 > 0 ) {
V_28 . V_36 = F_22 ( V_1 -> V_24 , V_223 ,
V_222 . V_182 , V_233 ) ;
V_2 -> V_31 [ 0 ] . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_31 [ 0 ] . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_31 [ 0 ] . V_37 = V_222 . V_182 ;
V_2 -> V_31 [ 0 ] . V_41 = 0 ;
}
V_2 -> V_234 = & V_224 ;
F_10 ( V_1 , V_2 ) ;
F_124 ( & V_224 ) ;
V_28 . V_32 . V_33 = V_2 -> V_31 [ 0 ] . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_2 -> V_31 [ 0 ] . V_34 . V_35 ;
F_20 ( V_1 -> V_24 , ( T_13 ) V_28 . V_36 , V_222 . V_182 ,
V_233 ) ;
F_104 ( V_1 , V_2 ) ;
V_222 . V_181 = * ( V_2 -> V_130 ) ;
if ( F_101 ( V_194 , & V_222 , sizeof( T_16 ) ) ) {
F_15 ( V_223 ) ;
F_82 ( V_1 , V_2 ) ;
return - V_84 ;
}
if ( V_222 . V_180 . Type . V_226 == V_235 ) {
if ( F_101 ( V_222 . V_76 , V_223 , V_222 . V_182 ) ) {
F_15 ( V_223 ) ;
F_82 ( V_1 , V_2 ) ;
return - V_84 ;
}
}
F_15 ( V_223 ) ;
F_82 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_125 ( T_1 * V_1 , void T_9 * V_194 )
{
T_18 * V_236 ;
T_2 * V_2 ;
unsigned char * * V_223 = NULL ;
int * V_237 = NULL ;
T_4 V_28 ;
T_27 V_238 = 0 ;
int V_239 = 0 ;
int V_20 ;
F_123 ( V_224 ) ;
V_136 V_240 ;
V_136 V_241 ;
T_27 T_9 * V_242 ;
if ( ! V_194 )
return - V_81 ;
if ( ! F_89 ( V_225 ) )
return - V_153 ;
V_236 = F_17 ( sizeof( * V_236 ) , V_23 ) ;
if ( ! V_236 ) {
V_239 = - V_83 ;
goto V_243;
}
if ( F_38 ( V_236 , V_194 , sizeof( * V_236 ) ) ) {
V_239 = - V_84 ;
goto V_243;
}
if ( ( V_236 -> V_182 < 1 ) &&
( V_236 -> V_180 . Type . V_226 != V_227 ) ) {
V_239 = - V_81 ;
goto V_243;
}
if ( V_236 -> V_184 > V_244 ) {
V_239 = - V_81 ;
goto V_243;
}
if ( V_236 -> V_182 > V_236 -> V_184 * V_245 ) {
V_239 = - V_81 ;
goto V_243;
}
V_223 = F_126 ( V_245 * sizeof( char * ) , V_23 ) ;
if ( ! V_223 ) {
V_239 = - V_83 ;
goto V_243;
}
V_237 = F_17 ( V_245 * sizeof( int ) , V_23 ) ;
if ( ! V_237 ) {
V_239 = - V_83 ;
goto V_243;
}
V_240 = V_236 -> V_182 ;
V_242 = V_236 -> V_76 ;
while ( V_240 ) {
V_241 = ( V_240 > V_236 -> V_184 ) ? V_236 -> V_184 : V_240 ;
V_237 [ V_238 ] = V_241 ;
V_223 [ V_238 ] = F_17 ( V_241 , V_23 ) ;
if ( V_223 [ V_238 ] == NULL ) {
V_239 = - V_83 ;
goto V_243;
}
if ( V_236 -> V_180 . Type . V_226 == V_228 ) {
if ( F_38 ( V_223 [ V_238 ] , V_242 , V_241 ) ) {
V_239 = - V_84 ;
goto V_243;
}
} else {
memset ( V_223 [ V_238 ] , 0 , V_241 ) ;
}
V_240 -= V_241 ;
V_242 += V_241 ;
V_238 ++ ;
}
V_2 = F_77 ( V_1 ) ;
if ( ! V_2 ) {
V_239 = - V_83 ;
goto V_243;
}
V_2 -> V_11 = V_229 ;
V_2 -> V_7 . V_230 = 0 ;
V_2 -> V_7 . V_8 = V_238 ;
V_2 -> V_7 . V_29 = V_238 ;
V_2 -> V_7 . V_231 = V_236 -> V_179 ;
V_2 -> V_7 . V_232 . V_33 = V_2 -> V_5 ;
V_2 -> V_180 = V_236 -> V_180 ;
for ( V_20 = 0 ; V_20 < V_238 ; V_20 ++ ) {
V_28 . V_36 = F_22 ( V_1 -> V_24 , V_223 [ V_20 ] , V_237 [ V_20 ] ,
V_233 ) ;
V_2 -> V_31 [ V_20 ] . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_31 [ V_20 ] . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_31 [ V_20 ] . V_37 = V_237 [ V_20 ] ;
V_2 -> V_31 [ V_20 ] . V_41 = 0 ;
}
V_2 -> V_234 = & V_224 ;
F_10 ( V_1 , V_2 ) ;
F_124 ( & V_224 ) ;
for ( V_20 = 0 ; V_20 < V_238 ; V_20 ++ ) {
V_28 . V_32 . V_33 = V_2 -> V_31 [ V_20 ] . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_2 -> V_31 [ V_20 ] . V_34 . V_35 ;
F_20 ( V_1 -> V_24 ,
( T_13 ) V_28 . V_36 , V_237 [ V_20 ] ,
V_233 ) ;
}
F_104 ( V_1 , V_2 ) ;
V_236 -> V_181 = * ( V_2 -> V_130 ) ;
if ( F_101 ( V_194 , V_236 , sizeof( * V_236 ) ) ) {
F_82 ( V_1 , V_2 ) ;
V_239 = - V_84 ;
goto V_243;
}
if ( V_236 -> V_180 . Type . V_226 == V_235 ) {
T_27 T_9 * V_246 = V_236 -> V_76 ;
for ( V_20 = 0 ; V_20 < V_238 ; V_20 ++ ) {
if ( F_101 ( V_246 , V_223 [ V_20 ] , V_237 [ V_20 ] ) ) {
F_82 ( V_1 , V_2 ) ;
V_239 = - V_84 ;
goto V_243;
}
V_246 += V_237 [ V_20 ] ;
}
}
F_82 ( V_1 , V_2 ) ;
V_239 = 0 ;
V_243:
if ( V_223 ) {
for ( V_20 = 0 ; V_20 < V_238 ; V_20 ++ )
F_15 ( V_223 [ V_20 ] ) ;
F_15 ( V_223 ) ;
}
F_15 ( V_237 ) ;
F_15 ( V_236 ) ;
return V_239 ;
}
static int F_95 ( struct V_144 * V_145 , T_14 V_146 ,
unsigned int V_155 , unsigned long V_156 )
{
struct V_140 * V_141 = V_145 -> V_147 ;
T_1 * V_1 = F_84 ( V_141 ) ;
void T_9 * V_194 = ( void T_9 * ) V_156 ;
F_87 ( & V_1 -> V_24 -> V_25 , L_28 ,
V_155 , V_156 ) ;
switch ( V_155 ) {
case V_157 :
return F_106 ( V_1 , V_194 ) ;
case V_158 :
return F_108 ( V_1 , V_194 ) ;
case V_159 :
return F_110 ( V_1 , V_194 ) ;
case V_160 :
return F_113 ( V_1 , V_194 ) ;
case V_161 :
return F_115 ( V_1 , V_194 ) ;
case V_162 :
return F_117 ( V_1 , V_194 ) ;
case V_163 :
return F_118 ( V_1 , V_194 ) ;
case V_164 :
return F_119 ( V_1 , V_194 ) ;
case V_165 :
return F_120 ( V_1 , V_194 ) ;
case V_167 :
case V_169 :
case V_166 :
return F_127 ( V_1 , 0 , 1 ) ;
case V_171 :
return F_121 ( V_1 , V_141 , V_194 ) ;
case V_183 :
return F_122 ( V_1 , V_194 ) ;
case V_185 :
return F_125 ( V_1 , V_194 ) ;
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
return F_128 ( V_145 , V_146 , V_155 , V_194 ) ;
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
default:
return - V_114 ;
}
}
static void F_129 ( T_1 * V_1 )
{
int V_260 = V_1 -> V_261 ;
int V_20 ;
if ( ( F_74 ( V_1 -> V_127 , V_1 -> V_19 ) ) == V_1 -> V_19 )
return;
for ( V_20 = 0 ; V_20 < V_1 -> V_64 + 1 ; V_20 ++ ) {
int V_262 = ( V_260 + V_20 ) % ( V_1 -> V_64 + 1 ) ;
if ( ! V_1 -> V_63 [ V_262 ] )
continue;
if ( ! ( V_1 -> V_63 [ V_262 ] -> V_142 ) ||
! ( V_1 -> V_63 [ V_262 ] -> V_65 ) )
continue;
F_130 ( V_1 -> V_140 [ V_262 ] -> V_142 ) ;
if ( ( F_74 ( V_1 -> V_127 , V_1 -> V_19 ) ) == V_1 -> V_19 ) {
if ( V_262 == V_260 ) {
V_1 -> V_261 =
( V_260 + 1 ) % ( V_1 -> V_64 + 1 ) ;
break;
} else {
V_1 -> V_261 = V_262 ;
break;
}
}
}
}
static void F_131 ( struct V_263 * V_264 )
{
T_2 * V_2 = V_264 -> V_265 ;
T_1 * V_1 = V_266 [ V_2 -> V_62 ] ;
T_3 * V_267 = V_2 -> V_31 ;
T_4 V_28 ;
unsigned long V_13 ;
int V_20 , V_268 ;
int V_269 = 0 ;
if ( V_2 -> V_180 . Type . V_226 == V_235 )
V_268 = V_270 ;
else
V_268 = V_38 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_7 . V_8 ; V_20 ++ ) {
if ( V_267 [ V_269 ] . V_41 == V_42 ) {
F_19 ( V_1 , V_2 ) ;
V_267 = V_1 -> V_18 [ V_2 -> V_135 ] ;
V_269 = 0 ;
}
V_28 . V_32 . V_33 = V_267 [ V_269 ] . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_267 [ V_269 ] . V_34 . V_35 ;
F_132 ( V_1 -> V_24 , V_28 . V_36 , V_267 [ V_269 ] . V_37 ,
V_268 ) ;
++ V_269 ;
}
F_87 ( & V_1 -> V_24 -> V_25 , L_29 , V_264 ) ;
if ( V_264 -> V_11 == V_271 )
V_264 -> V_272 = V_2 -> V_130 -> V_273 ;
F_133 ( V_264 , ( V_264 -> V_274 == 0 ) ? 0 : - V_275 ) ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
F_80 ( V_1 , V_2 ) ;
F_129 ( V_1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
}
static inline void F_134 ( T_1 * V_1 ,
unsigned char V_276 [] , T_28 V_277 )
{
memcpy ( V_276 , V_1 -> V_63 [ V_277 ] -> V_115 ,
sizeof( V_1 -> V_63 [ V_277 ] -> V_115 ) ) ;
}
static void F_135 ( T_1 * V_1 , int V_278 ,
char * V_107 , char * V_109 , char * V_111 )
{
int V_279 ;
T_29 * V_280 ;
unsigned char V_276 [ 8 ] ;
* V_107 = '\0' ;
* V_109 = '\0' ;
* V_111 = '\0' ;
V_280 = F_126 ( sizeof( T_29 ) , V_23 ) ;
if ( ! V_280 )
return;
F_134 ( V_1 , V_276 , V_278 ) ;
V_279 = F_136 ( V_1 , V_281 , V_280 , sizeof( * V_280 ) , 0 ,
V_276 , V_282 ) ;
if ( V_279 == V_283 ) {
memcpy ( V_107 , & V_280 -> V_284 [ 8 ] , V_108 ) ;
V_107 [ V_108 ] = '\0' ;
memcpy ( V_109 , & V_280 -> V_284 [ 16 ] , V_110 ) ;
V_109 [ V_110 ] = '\0' ;
memcpy ( V_111 , & V_280 -> V_284 [ 32 ] , V_112 ) ;
V_111 [ V_112 ] = '\0' ;
}
F_15 ( V_280 ) ;
return;
}
static void F_137 ( T_1 * V_1 , int V_278 ,
unsigned char * V_106 , int V_285 )
{
#define F_138 64
int V_279 ;
unsigned char * V_76 ;
unsigned char V_276 [ 8 ] ;
if ( V_285 > 16 )
V_285 = 16 ;
memset ( V_106 , 0xff , V_285 ) ;
V_76 = F_126 ( F_138 , V_23 ) ;
if ( ! V_76 )
return;
memset ( V_106 , 0 , V_285 ) ;
F_134 ( V_1 , V_276 , V_278 ) ;
V_279 = F_136 ( V_1 , V_281 , V_76 ,
F_138 , 0x83 , V_276 , V_282 ) ;
if ( V_279 == V_283 )
memcpy ( V_106 , & V_76 [ 8 ] , V_285 ) ;
F_15 ( V_76 ) ;
return;
}
static int F_139 ( T_1 * V_1 , struct V_140 * V_141 ,
int V_121 )
{
V_141 -> V_142 = F_140 ( V_286 , & V_1 -> V_14 ) ;
if ( ! V_141 -> V_142 )
goto V_287;
sprintf ( V_141 -> V_148 , L_30 , V_1 -> V_62 , V_121 ) ;
V_141 -> V_288 = V_1 -> V_288 ;
V_141 -> V_289 = V_121 << V_290 ;
V_141 -> V_291 = & V_292 ;
if ( F_71 ( V_1 , V_121 ) )
goto V_293;
V_141 -> V_75 = V_1 -> V_63 [ V_121 ] ;
V_141 -> V_294 = & V_1 -> V_63 [ V_121 ] -> V_25 ;
F_141 ( V_141 -> V_142 , V_1 -> V_24 -> V_295 ) ;
F_142 ( V_141 -> V_142 , V_1 -> V_296 ) ;
F_143 ( V_141 -> V_142 , V_1 -> V_297 ) ;
F_144 ( V_141 -> V_142 , F_131 ) ;
V_141 -> V_142 -> V_143 = V_1 ;
F_145 ( V_141 -> V_142 ,
V_1 -> V_63 [ V_121 ] -> V_298 ) ;
F_146 () ;
V_1 -> V_63 [ V_121 ] -> V_142 = V_141 -> V_142 ;
F_147 ( V_141 ) ;
return 0 ;
V_293:
F_148 ( V_141 -> V_142 ) ;
V_141 -> V_142 = NULL ;
V_287:
return - 1 ;
}
static void F_149 ( T_1 * V_1 , int V_121 ,
int V_299 , int V_300 )
{
struct V_140 * V_141 ;
T_29 * V_301 = NULL ;
unsigned int V_298 ;
T_6 V_302 ;
unsigned long V_13 = 0 ;
int V_73 = 0 ;
T_7 * V_303 ;
V_301 = F_17 ( sizeof( T_29 ) , V_23 ) ;
V_303 = F_126 ( sizeof( * V_303 ) , V_23 ) ;
if ( V_301 == NULL || V_303 == NULL )
goto V_304;
if ( V_1 -> V_305 == V_306 ) {
F_150 ( V_1 , V_121 ,
& V_302 , & V_298 ) ;
} else {
F_151 ( V_1 , V_121 , & V_302 , & V_298 ) ;
if ( V_302 == 0xFFFFFFFFULL ) {
F_150 ( V_1 , V_121 ,
& V_302 , & V_298 ) ;
V_1 -> V_305 = V_306 ;
V_1 -> V_307 = V_308 ;
} else {
V_1 -> V_305 = V_309 ;
V_1 -> V_307 = V_310 ;
}
}
F_152 ( V_1 , V_121 , V_302 , V_298 ,
V_301 , V_303 ) ;
V_303 -> V_298 = V_298 ;
V_303 -> V_66 = V_302 + 1 ;
F_135 ( V_1 , V_121 , V_303 -> V_107 ,
V_303 -> V_109 , V_303 -> V_111 ) ;
F_137 ( V_1 , V_121 , V_303 -> V_106 ,
sizeof( V_303 -> V_106 ) ) ;
memcpy ( V_303 -> V_115 , V_1 -> V_63 [ V_121 ] -> V_115 ,
sizeof( V_303 -> V_115 ) ) ;
if ( V_1 -> V_63 [ V_121 ] -> V_68 != - 1 &&
( ( memcmp ( V_303 -> V_106 ,
V_1 -> V_63 [ V_121 ] -> V_106 , 16 ) == 0 ) &&
V_303 -> V_298 == V_1 -> V_63 [ V_121 ] -> V_298 &&
V_303 -> V_66 == V_1 -> V_63 [ V_121 ] -> V_66 &&
V_303 -> V_65 == V_1 -> V_63 [ V_121 ] -> V_65 &&
V_303 -> V_189 == V_1 -> V_63 [ V_121 ] -> V_189 &&
V_303 -> V_188 == V_1 -> V_63 [ V_121 ] -> V_188 ) )
goto V_311;
if ( V_1 -> V_63 [ V_121 ] -> V_68 != - 1 && V_121 != 0 ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_31 , V_121 ) ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_1 -> V_63 [ V_121 ] -> V_57 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
V_73 = F_154 ( V_1 , V_121 , 0 , V_300 ) ;
}
if ( V_73 )
goto V_311;
if ( V_1 -> V_63 [ V_121 ] == NULL ) {
V_303 -> V_122 = 0 ;
V_1 -> V_63 [ V_121 ] = V_303 ;
V_303 = NULL ;
} else {
V_1 -> V_63 [ V_121 ] -> V_298 = V_303 -> V_298 ;
V_1 -> V_63 [ V_121 ] -> V_66 = V_303 -> V_66 ;
V_1 -> V_63 [ V_121 ] -> V_65 = V_303 -> V_65 ;
V_1 -> V_63 [ V_121 ] -> V_189 = V_303 -> V_189 ;
V_1 -> V_63 [ V_121 ] -> V_188 = V_303 -> V_188 ;
V_1 -> V_63 [ V_121 ] -> V_68 = V_303 -> V_68 ;
memcpy ( V_1 -> V_63 [ V_121 ] -> V_106 , V_303 -> V_106 , 16 ) ;
memcpy ( V_1 -> V_63 [ V_121 ] -> V_107 , V_303 -> V_107 ,
V_108 + 1 ) ;
memcpy ( V_1 -> V_63 [ V_121 ] -> V_109 , V_303 -> V_109 , V_110 + 1 ) ;
memcpy ( V_1 -> V_63 [ V_121 ] -> V_111 , V_303 -> V_111 , V_112 + 1 ) ;
}
++ V_1 -> V_52 ;
V_141 = V_1 -> V_140 [ V_121 ] ;
F_155 ( V_141 , V_1 -> V_63 [ V_121 ] -> V_66 ) ;
if ( V_121 || V_299 ) {
if ( F_139 ( V_1 , V_141 , V_121 ) != 0 ) {
F_156 ( V_1 , V_121 ) ;
F_157 ( V_1 , V_121 ) ;
F_153 ( & V_1 -> V_24 -> V_25 , L_32 ,
V_121 ) ;
-- V_1 -> V_52 ;
}
}
V_311:
F_15 ( V_301 ) ;
F_15 ( V_303 ) ;
return;
V_304:
F_18 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
goto V_311;
}
static int F_158 ( T_1 * V_1 , int V_312 )
{
int V_20 ;
T_7 * V_63 ;
for ( V_20 = 0 ; V_20 < V_313 ; V_20 ++ ) {
if ( V_1 -> V_63 [ V_20 ] && V_20 != 0 )
continue;
if ( V_20 == 0 && V_1 -> V_63 [ V_20 ] && V_1 -> V_63 [ V_20 ] -> V_68 != - 1 )
continue;
if ( V_20 > V_1 -> V_64 && ! V_312 )
V_1 -> V_64 = V_20 ;
if ( V_20 == 0 && V_1 -> V_63 [ V_20 ] != NULL )
return V_20 ;
V_63 = F_126 ( sizeof( * V_63 ) , V_23 ) ;
if ( ! V_63 )
return - 1 ;
V_63 -> V_68 = - 1 ;
V_1 -> V_63 [ V_20 ] = V_63 ;
return V_20 ;
}
return - 1 ;
}
static void F_157 ( T_1 * V_1 , int V_121 )
{
F_15 ( V_1 -> V_63 [ V_121 ] ) ;
V_1 -> V_63 [ V_121 ] = NULL ;
}
static void F_156 ( T_1 * V_1 , int V_121 )
{
F_159 ( V_1 -> V_140 [ V_121 ] ) ;
V_1 -> V_140 [ V_121 ] = NULL ;
}
static int F_160 ( T_1 * V_1 , unsigned char V_113 [] ,
int V_312 )
{
int V_121 ;
V_121 = F_158 ( V_1 , V_312 ) ;
if ( V_121 == - 1 )
return - 1 ;
if ( ! V_1 -> V_140 [ V_121 ] ) {
V_1 -> V_140 [ V_121 ] =
F_161 ( 1 << V_290 ) ;
if ( ! V_1 -> V_140 [ V_121 ] ) {
F_18 ( & V_1 -> V_24 -> V_25 ,
L_34 ,
V_121 ) ;
goto V_314;
}
}
memcpy ( V_1 -> V_63 [ V_121 ] -> V_115 , V_113 ,
sizeof( V_1 -> V_63 [ V_121 ] -> V_115 ) ) ;
if ( F_71 ( V_1 , V_121 ) )
goto V_315;
V_1 -> V_63 [ V_121 ] -> V_57 = 0 ;
F_146 () ;
return V_121 ;
V_315:
F_156 ( V_1 , V_121 ) ;
V_314:
F_157 ( V_1 , V_121 ) ;
return - 1 ;
}
static void F_162 ( T_1 * V_1 )
{
struct V_140 * V_141 ;
int V_121 ;
if ( V_1 -> V_140 [ 0 ] != NULL )
return;
V_121 = F_160 ( V_1 , V_151 , 1 ) ;
if ( V_121 == - 1 )
goto error;
V_1 -> V_63 [ V_121 ] -> V_298 = 512 ;
V_1 -> V_63 [ V_121 ] -> V_66 = 0 ;
V_1 -> V_63 [ V_121 ] -> V_65 = 0 ;
V_1 -> V_63 [ V_121 ] -> V_189 = 0 ;
V_1 -> V_63 [ V_121 ] -> V_188 = 0 ;
V_1 -> V_63 [ V_121 ] -> V_68 = - 1 ;
memset ( V_1 -> V_63 [ V_121 ] -> V_106 , 0 , 16 ) ;
V_141 = V_1 -> V_140 [ V_121 ] ;
if ( F_139 ( V_1 , V_141 , V_121 ) == 0 )
return;
F_156 ( V_1 , V_121 ) ;
F_157 ( V_1 , V_121 ) ;
error:
F_153 ( & V_1 -> V_24 -> V_25 , L_35 ) ;
return;
}
static int F_127 ( T_1 * V_1 , int V_299 ,
int V_300 )
{
int V_52 ;
T_30 * V_316 = NULL ;
int V_317 ;
int V_318 = 0 ;
int V_20 ;
int V_319 ;
int V_121 = 0 ;
unsigned char V_113 [ 8 ] = V_151 ;
unsigned long V_13 ;
if ( ! F_89 ( V_225 ) )
return - V_153 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_58 ;
}
V_1 -> V_57 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
V_316 = F_126 ( sizeof( T_30 ) , V_23 ) ;
if ( V_316 == NULL )
goto V_304;
V_317 = F_136 ( V_1 , V_320 , V_316 ,
sizeof( T_30 ) ,
0 , V_151 , V_282 ) ;
if ( V_317 == V_283 )
V_318 = F_163 ( * ( V_321 * ) V_316 -> V_322 ) ;
else {
F_153 ( & V_1 -> V_24 -> V_25 ,
L_36 ) ;
V_318 = 0 ;
goto V_311;
}
V_52 = V_318 / 8 ;
if ( V_52 > V_313 ) {
V_52 = V_313 ;
F_153 ( & V_1 -> V_24 -> V_25 , L_37
L_38
L_39 ) ;
}
if ( V_52 == 0 )
F_162 ( V_1 ) ;
for ( V_20 = 0 ; V_20 <= V_1 -> V_64 ; V_20 ++ ) {
int V_22 ;
V_319 = 0 ;
if ( V_1 -> V_63 [ V_20 ] == NULL )
continue;
for ( V_22 = 0 ; V_22 < V_52 ; V_22 ++ ) {
memcpy ( V_113 , & V_316 -> V_231 [ V_22 ] [ 0 ] , sizeof( V_113 ) ) ;
if ( memcmp ( V_1 -> V_63 [ V_20 ] -> V_115 , V_113 ,
sizeof( V_113 ) ) == 0 ) {
V_319 = 1 ;
break;
}
}
if ( ! V_319 ) {
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_1 -> V_63 [ V_20 ] -> V_57 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
V_317 = F_154 ( V_1 , V_20 , 1 , V_300 ) ;
if ( V_1 -> V_63 [ V_20 ] != NULL )
V_1 -> V_63 [ V_20 ] -> V_57 = 0 ;
}
}
for ( V_20 = 0 ; V_20 < V_52 ; V_20 ++ ) {
int V_22 ;
V_319 = 0 ;
memcpy ( V_113 , & V_316 -> V_231 [ V_20 ] [ 0 ] , sizeof( V_113 ) ) ;
for ( V_22 = 0 ; V_22 <= V_1 -> V_64 ; V_22 ++ ) {
if ( V_1 -> V_63 [ V_22 ] != NULL &&
memcmp ( V_1 -> V_63 [ V_22 ] -> V_115 , V_113 ,
sizeof( V_1 -> V_63 [ V_22 ] -> V_115 ) ) == 0 ) {
V_121 = V_22 ;
V_319 = 1 ;
break;
}
}
if ( ! V_319 ) {
V_121 = F_160 ( V_1 , V_113 , 0 ) ;
if ( V_121 == - 1 )
goto V_311;
}
F_149 ( V_1 , V_121 , V_299 , V_300 ) ;
}
V_311:
F_15 ( V_316 ) ;
V_1 -> V_57 = 0 ;
return - 1 ;
V_304:
F_18 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
V_1 -> V_57 = 0 ;
goto V_311;
}
static void F_164 ( T_7 * V_323 )
{
V_323 -> V_66 = 0 ;
V_323 -> V_298 = 0 ;
V_323 -> V_65 = 0 ;
V_323 -> V_189 = 0 ;
V_323 -> V_188 = 0 ;
V_323 -> V_68 = - 1 ;
memset ( V_323 -> V_106 , 0 , sizeof( V_323 -> V_106 ) ) ;
memset ( V_323 -> V_109 , 0 , sizeof( V_323 -> V_109 ) ) ;
memset ( V_323 -> V_111 , 0 , sizeof( V_323 -> V_111 ) ) ;
memset ( V_323 -> V_107 , 0 , sizeof( V_323 -> V_107 ) ) ;
}
static int F_154 ( T_1 * V_1 , int V_121 ,
int V_324 , int V_300 )
{
int V_20 ;
struct V_140 * V_141 ;
T_7 * V_63 ;
int V_325 ;
if ( ! F_89 ( V_225 ) )
return - V_153 ;
V_63 = V_1 -> V_63 [ V_121 ] ;
V_141 = V_1 -> V_140 [ V_121 ] ;
if ( V_324 || ( V_1 -> V_140 [ 0 ] == V_141 ) ) {
if ( V_63 -> V_117 > V_300 )
return - V_58 ;
} else if ( V_63 -> V_117 > 0 )
return - V_58 ;
V_325 = ( V_63 == V_1 -> V_63 [ V_1 -> V_64 ] ) ;
if ( V_1 -> V_140 [ 0 ] != V_141 ) {
struct V_326 * V_327 = V_141 -> V_142 ;
if ( V_141 -> V_13 & V_328 ) {
F_72 ( V_1 , V_121 , 0 ) ;
F_165 ( V_141 ) ;
}
if ( V_327 )
F_148 ( V_327 ) ;
if ( V_324 ) {
for ( V_20 = 0 ; V_20 < V_313 ; V_20 ++ ) {
if ( V_1 -> V_140 [ V_20 ] == V_141 ) {
V_1 -> V_140 [ V_20 ] = NULL ;
break;
}
}
F_159 ( V_141 ) ;
}
} else {
F_155 ( V_141 , 0 ) ;
F_164 ( V_63 ) ;
}
-- V_1 -> V_52 ;
if ( V_324 && V_325 ) {
int V_329 = - 1 ;
for ( V_20 = 0 ; V_20 <= V_1 -> V_64 ; V_20 ++ ) {
if ( V_1 -> V_63 [ V_20 ] && V_1 -> V_63 [ V_20 ] -> V_65 )
V_329 = V_20 ;
}
V_1 -> V_64 = V_329 ;
}
return 0 ;
}
static int F_166 ( T_1 * V_1 , T_2 * V_2 , T_12 V_155 , void * V_223 ,
T_10 V_330 , T_12 V_331 , unsigned char * V_276 ,
int V_11 )
{
T_4 V_332 ;
int V_239 = V_283 ;
V_2 -> V_11 = V_229 ;
V_2 -> V_7 . V_230 = 0 ;
if ( V_223 != NULL ) {
V_2 -> V_7 . V_8 = 1 ;
V_2 -> V_7 . V_29 = 1 ;
} else {
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_7 . V_29 = 0 ;
}
V_2 -> V_7 . V_232 . V_33 = V_2 -> V_5 ;
memcpy ( V_2 -> V_7 . V_231 . V_333 , V_276 , 8 ) ;
V_2 -> V_180 . Type . Type = V_11 ;
if ( V_11 == V_282 ) {
switch ( V_155 ) {
case V_281 :
if ( V_331 != 0 ) {
V_2 -> V_180 . V_334 [ 1 ] = 0x01 ;
V_2 -> V_180 . V_334 [ 2 ] = V_331 ;
}
V_2 -> V_180 . V_335 = 6 ;
V_2 -> V_180 . Type . V_336 = V_337 ;
V_2 -> V_180 . Type . V_226 = V_235 ;
V_2 -> V_180 . V_338 = 0 ;
V_2 -> V_180 . V_334 [ 0 ] = V_281 ;
V_2 -> V_180 . V_334 [ 4 ] = V_330 & 0xFF ;
break;
case V_320 :
case V_339 :
V_2 -> V_180 . V_335 = 12 ;
V_2 -> V_180 . Type . V_336 = V_337 ;
V_2 -> V_180 . Type . V_226 = V_235 ;
V_2 -> V_180 . V_338 = 0 ;
V_2 -> V_180 . V_334 [ 0 ] = V_155 ;
V_2 -> V_180 . V_334 [ 6 ] = ( V_330 >> 24 ) & 0xFF ;
V_2 -> V_180 . V_334 [ 7 ] = ( V_330 >> 16 ) & 0xFF ;
V_2 -> V_180 . V_334 [ 8 ] = ( V_330 >> 8 ) & 0xFF ;
V_2 -> V_180 . V_334 [ 9 ] = V_330 & 0xFF ;
break;
case V_340 :
V_2 -> V_180 . V_335 = 10 ;
V_2 -> V_180 . Type . V_336 = V_337 ;
V_2 -> V_180 . Type . V_226 = V_235 ;
V_2 -> V_180 . V_338 = 0 ;
V_2 -> V_180 . V_334 [ 0 ] = V_155 ;
break;
case V_341 :
V_2 -> V_180 . V_335 = 16 ;
V_2 -> V_180 . Type . V_336 = V_337 ;
V_2 -> V_180 . Type . V_226 = V_235 ;
V_2 -> V_180 . V_338 = 0 ;
V_2 -> V_180 . V_334 [ 0 ] = V_155 ;
V_2 -> V_180 . V_334 [ 1 ] = 0x10 ;
V_2 -> V_180 . V_334 [ 10 ] = ( V_330 >> 24 ) & 0xFF ;
V_2 -> V_180 . V_334 [ 11 ] = ( V_330 >> 16 ) & 0xFF ;
V_2 -> V_180 . V_334 [ 12 ] = ( V_330 >> 8 ) & 0xFF ;
V_2 -> V_180 . V_334 [ 13 ] = V_330 & 0xFF ;
V_2 -> V_180 . V_338 = 0 ;
V_2 -> V_180 . V_334 [ 0 ] = V_155 ;
break;
case V_342 :
V_2 -> V_180 . V_335 = 12 ;
V_2 -> V_180 . Type . V_336 = V_337 ;
V_2 -> V_180 . Type . V_226 = V_228 ;
V_2 -> V_180 . V_338 = 0 ;
V_2 -> V_180 . V_334 [ 0 ] = V_343 ;
V_2 -> V_180 . V_334 [ 6 ] = V_344 ;
V_2 -> V_180 . V_334 [ 7 ] = ( V_330 >> 8 ) & 0xFF ;
V_2 -> V_180 . V_334 [ 8 ] = V_330 & 0xFF ;
break;
case V_345 :
V_2 -> V_180 . V_335 = 6 ;
V_2 -> V_180 . Type . V_336 = V_337 ;
V_2 -> V_180 . Type . V_226 = V_227 ;
V_2 -> V_180 . V_338 = 0 ;
break;
default:
F_153 ( & V_1 -> V_24 -> V_25 , L_40 , V_155 ) ;
return V_346 ;
}
} else if ( V_11 == V_347 ) {
switch ( V_155 ) {
case V_348 :
V_2 -> V_180 . V_335 = 12 ;
V_2 -> V_180 . Type . V_336 = V_337 ;
V_2 -> V_180 . Type . V_226 = V_228 ;
V_2 -> V_180 . V_338 = 0 ;
V_2 -> V_180 . V_334 [ 0 ] = V_155 ;
V_2 -> V_180 . V_334 [ 1 ] = 0 ;
memcpy ( & V_2 -> V_180 . V_334 [ 4 ] , V_223 , 8 ) ;
break;
case V_349 :
V_2 -> V_180 . V_335 = 16 ;
V_2 -> V_180 . Type . V_336 = V_337 ;
V_2 -> V_180 . Type . V_226 = V_227 ;
V_2 -> V_180 . V_338 = 0 ;
memset ( & V_2 -> V_180 . V_334 [ 0 ] , 0 , sizeof( V_2 -> V_180 . V_334 ) ) ;
V_2 -> V_180 . V_334 [ 0 ] = V_155 ;
V_2 -> V_180 . V_334 [ 1 ] = V_350 ;
break;
case V_351 :
V_2 -> V_180 . V_335 = 1 ;
V_2 -> V_180 . Type . V_336 = V_337 ;
V_2 -> V_180 . Type . V_226 = V_228 ;
V_2 -> V_180 . V_338 = 0 ;
V_2 -> V_180 . V_334 [ 0 ] = V_155 ;
break;
default:
F_153 ( & V_1 -> V_24 -> V_25 ,
L_41 , V_155 ) ;
return V_346 ;
}
} else {
F_153 ( & V_1 -> V_24 -> V_25 , L_42 , V_11 ) ;
return V_346 ;
}
if ( V_330 > 0 ) {
V_332 . V_36 = ( V_137 ) F_22 ( V_1 -> V_24 ,
V_223 , V_330 ,
V_233 ) ;
V_2 -> V_31 [ 0 ] . V_34 . V_33 = V_332 . V_32 . V_33 ;
V_2 -> V_31 [ 0 ] . V_34 . V_35 = V_332 . V_32 . V_35 ;
V_2 -> V_31 [ 0 ] . V_37 = V_330 ;
V_2 -> V_31 [ 0 ] . V_41 = 0 ;
}
return V_239 ;
}
static int F_167 ( T_1 * V_1 , unsigned char * V_276 ,
T_31 V_352 )
{
T_2 * V_2 ;
int V_353 ;
V_2 = F_73 ( V_1 ) ;
if ( ! V_2 )
return - V_83 ;
V_353 = F_166 ( V_1 , V_2 , V_349 , NULL , 0 , 0 ,
V_151 , V_347 ) ;
V_2 -> V_180 . V_334 [ 1 ] = V_352 ;
if ( V_353 != V_283 ) {
F_82 ( V_1 , V_2 ) ;
return V_353 ;
}
V_2 -> V_234 = NULL ;
F_10 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_168 ( T_1 * V_1 , T_2 * V_2 )
{
switch ( V_2 -> V_130 -> V_192 ) {
case V_354 :
return V_283 ;
case V_193 :
switch ( 0xf & V_2 -> V_130 -> V_355 [ 2 ] ) {
case 0 : return V_283 ;
case 1 : return V_283 ;
default:
if ( F_105 ( V_1 , V_2 ) )
return V_356 ;
F_153 ( & V_1 -> V_24 -> V_25 , L_43
L_44 ,
V_2 -> V_180 . V_334 [ 0 ] , V_2 -> V_130 -> V_355 [ 2 ] ) ;
}
break;
default:
F_153 ( & V_1 -> V_24 -> V_25 , L_45
L_46 ,
V_2 -> V_180 . V_334 [ 0 ] , V_2 -> V_130 -> V_192 ) ;
break;
}
return V_346 ;
}
static int F_169 ( T_1 * V_1 , T_2 * V_2 )
{
int V_353 = V_283 ;
if ( V_2 -> V_130 -> V_190 == V_357 )
return V_283 ;
switch ( V_2 -> V_130 -> V_190 ) {
case V_191 :
V_353 = F_168 ( V_1 , V_2 ) ;
break;
case V_358 :
case V_359 :
break;
case V_360 :
F_153 ( & V_1 -> V_24 -> V_25 , L_47
L_48 , V_2 -> V_180 . V_334 [ 0 ] ) ;
V_353 = V_346 ;
break;
case V_361 :
F_153 ( & V_1 -> V_24 -> V_25 , L_49
L_50 , V_2 -> V_180 . V_334 [ 0 ] ) ;
V_353 = V_346 ;
break;
case V_362 :
F_153 ( & V_1 -> V_24 -> V_25 , L_51
L_52 , V_2 -> V_180 . V_334 [ 0 ] ) ;
V_353 = V_346 ;
break;
case V_363 :
F_153 ( & V_1 -> V_24 -> V_25 , L_51
L_53 , V_2 -> V_180 . V_334 [ 0 ] ) ;
V_353 = V_346 ;
break;
case V_364 :
F_153 ( & V_1 -> V_24 -> V_25 , L_54
L_55 , V_2 -> V_180 . V_334 [ 0 ] ) ;
V_353 = V_346 ;
break;
case V_365 :
F_153 ( & V_1 -> V_24 -> V_25 , L_56
L_57 , V_2 -> V_180 . V_334 [ 0 ] ) ;
V_353 = V_346 ;
break;
case V_366 :
F_153 ( & V_1 -> V_24 -> V_25 , L_58 ,
V_2 -> V_180 . V_334 [ 0 ] ) ;
V_353 = V_356 ;
break;
case V_367 :
F_153 ( & V_1 -> V_24 -> V_25 , L_59 ) ;
V_353 = V_346 ;
break;
default:
F_153 ( & V_1 -> V_24 -> V_25 , L_60
L_61 , V_2 -> V_180 . V_334 [ 0 ] ,
V_2 -> V_130 -> V_190 ) ;
V_353 = V_346 ;
}
return V_353 ;
}
static int F_170 ( T_1 * V_1 , T_2 * V_2 ,
int V_368 )
{
F_123 ( V_224 ) ;
T_4 V_332 ;
int V_353 = V_283 ;
V_369:
V_2 -> V_234 = & V_224 ;
F_10 ( V_1 , V_2 ) ;
F_124 ( & V_224 ) ;
if ( V_2 -> V_130 -> V_190 == 0 || ! V_368 )
goto V_370;
V_353 = F_169 ( V_1 , V_2 ) ;
if ( V_353 == V_356 &&
V_2 -> V_371 < V_372 ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_62 ,
V_2 -> V_180 . V_334 [ 0 ] ) ;
V_2 -> V_371 ++ ;
memset ( V_2 -> V_130 , 0 , sizeof( V_132 ) ) ;
V_353 = V_283 ;
F_171 ( & V_224 ) ;
goto V_369;
}
V_370:
V_332 . V_32 . V_33 = V_2 -> V_31 [ 0 ] . V_34 . V_33 ;
V_332 . V_32 . V_35 = V_2 -> V_31 [ 0 ] . V_34 . V_35 ;
F_20 ( V_1 -> V_24 , ( T_13 ) V_332 . V_36 ,
V_2 -> V_31 [ 0 ] . V_37 , V_233 ) ;
return V_353 ;
}
static int F_136 ( T_1 * V_1 , T_12 V_155 , void * V_223 , T_10 V_330 ,
T_12 V_331 , unsigned char V_276 [] ,
int V_11 )
{
T_2 * V_2 ;
int V_353 ;
V_2 = F_77 ( V_1 ) ;
if ( ! V_2 )
return - V_83 ;
V_353 = F_166 ( V_1 , V_2 , V_155 , V_223 , V_330 , V_331 ,
V_276 , V_11 ) ;
if ( V_353 == V_283 )
V_353 = F_170 ( V_1 , V_2 , 1 ) ;
F_82 ( V_1 , V_2 ) ;
return V_353 ;
}
static void F_152 ( T_1 * V_1 , int V_278 ,
T_6 V_302 ,
unsigned int V_298 ,
T_29 * V_301 ,
T_7 * V_63 )
{
int V_317 ;
unsigned long V_373 ;
unsigned char V_276 [ 8 ] ;
memset ( V_301 , 0 , sizeof( T_29 ) ) ;
F_134 ( V_1 , V_276 , V_278 ) ;
V_317 = F_136 ( V_1 , V_281 , V_301 ,
sizeof( * V_301 ) , 0xC1 , V_276 , V_282 ) ;
if ( V_317 == V_283 ) {
if ( V_301 -> V_284 [ 8 ] == 0xFF ) {
F_153 ( & V_1 -> V_24 -> V_25 ,
L_63
L_64 ) ;
V_63 -> V_65 = 255 ;
V_63 -> V_189 = 32 ;
V_63 -> V_188 = V_302 + 1 ;
V_63 -> V_68 = V_69 ;
} else {
V_63 -> V_65 = V_301 -> V_284 [ 6 ] ;
V_63 -> V_189 = V_301 -> V_284 [ 7 ] ;
V_63 -> V_188 = ( V_301 -> V_284 [ 4 ] & 0xff ) << 8 ;
V_63 -> V_188 += V_301 -> V_284 [ 5 ] ;
V_63 -> V_68 = V_301 -> V_284 [ 8 ] ;
}
V_63 -> V_298 = V_298 ;
V_63 -> V_66 = V_302 + 1 ;
V_373 = V_63 -> V_65 * V_63 -> V_189 ;
if ( V_373 > 1 ) {
T_6 V_374 = V_302 + 1 ;
unsigned long V_375 = F_30 ( V_374 , V_373 ) ;
if ( V_375 )
V_374 ++ ;
V_63 -> V_188 = V_374 ;
}
} else {
F_153 ( & V_1 -> V_24 -> V_25 , L_65 ) ;
}
}
static void
F_151 ( T_1 * V_1 , int V_278 , T_6 * V_302 ,
unsigned int * V_298 )
{
T_32 * V_76 ;
int V_317 ;
unsigned char V_276 [ 8 ] ;
V_76 = F_126 ( sizeof( T_32 ) , V_23 ) ;
if ( ! V_76 ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
return;
}
F_134 ( V_1 , V_276 , V_278 ) ;
V_317 = F_136 ( V_1 , V_340 , V_76 ,
sizeof( T_32 ) , 0 , V_276 , V_282 ) ;
if ( V_317 == V_283 ) {
* V_302 = F_163 ( * ( V_321 * ) V_76 -> V_302 ) ;
* V_298 = F_163 ( * ( V_321 * ) V_76 -> V_298 ) ;
} else {
F_153 ( & V_1 -> V_24 -> V_25 , L_66 ) ;
* V_302 = 0 ;
* V_298 = V_376 ;
}
F_15 ( V_76 ) ;
}
static void F_150 ( T_1 * V_1 , int V_278 ,
T_6 * V_302 , unsigned int * V_298 )
{
T_33 * V_76 ;
int V_317 ;
unsigned char V_276 [ 8 ] ;
V_76 = F_126 ( sizeof( T_33 ) , V_23 ) ;
if ( ! V_76 ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
return;
}
F_134 ( V_1 , V_276 , V_278 ) ;
V_317 = F_136 ( V_1 , V_341 ,
V_76 , sizeof( T_33 ) ,
0 , V_276 , V_282 ) ;
if ( V_317 == V_283 ) {
* V_302 = F_172 ( * ( V_377 * ) V_76 -> V_302 ) ;
* V_298 = F_163 ( * ( V_321 * ) V_76 -> V_298 ) ;
} else {
F_153 ( & V_1 -> V_24 -> V_25 , L_66 ) ;
* V_302 = 0 ;
* V_298 = V_376 ;
}
F_173 ( & V_1 -> V_24 -> V_25 , L_67 ,
( unsigned long long ) * V_302 + 1 , * V_298 ) ;
F_15 ( V_76 ) ;
}
static int F_174 ( struct V_140 * V_141 )
{
T_1 * V_1 = F_84 ( V_141 ) ;
T_7 * V_63 = F_85 ( V_141 ) ;
int V_278 ;
int V_378 = 0 ;
unsigned int V_298 ;
T_6 V_302 ;
T_29 * V_301 = NULL ;
for ( V_278 = 0 ; V_278 <= V_1 -> V_64 ; V_278 ++ ) {
if ( ! V_1 -> V_63 [ V_278 ] )
continue;
if ( memcmp ( V_1 -> V_63 [ V_278 ] -> V_115 , V_63 -> V_115 ,
sizeof( V_63 -> V_115 ) ) == 0 ) {
V_378 = 1 ;
break;
}
}
if ( ! V_378 )
return 1 ;
V_301 = F_17 ( sizeof( T_29 ) , V_23 ) ;
if ( V_301 == NULL ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
return 1 ;
}
if ( V_1 -> V_305 == V_309 ) {
F_151 ( V_1 , V_278 ,
& V_302 , & V_298 ) ;
} else {
F_150 ( V_1 , V_278 ,
& V_302 , & V_298 ) ;
}
F_152 ( V_1 , V_278 , V_302 , V_298 ,
V_301 , V_63 ) ;
F_145 ( V_63 -> V_142 , V_63 -> V_298 ) ;
F_155 ( V_141 , V_63 -> V_66 ) ;
F_15 ( V_301 ) ;
return 0 ;
}
static void T_34 * F_175 ( T_35 V_379 , T_35 V_330 )
{
T_35 V_380 = ( ( T_35 ) V_379 ) & V_381 ;
T_35 V_382 = ( ( T_35 ) V_379 ) - V_380 ;
void T_34 * V_383 = F_176 ( V_380 , V_382 + V_330 ) ;
return V_383 ? ( V_383 + V_382 ) : NULL ;
}
static void F_12 ( T_1 * V_1 )
{
T_2 * V_2 ;
while ( ! F_8 ( & V_1 -> V_15 ) ) {
V_2 = F_177 ( V_1 -> V_15 . V_384 , T_2 , V_10 ) ;
if ( ( V_1 -> V_385 . V_386 ( V_1 ) ) ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_68 ) ;
break;
}
F_6 ( V_2 ) ;
V_1 -> V_16 -- ;
V_1 -> V_385 . V_387 ( V_1 , V_2 ) ;
F_4 ( & V_1 -> V_388 , V_2 ) ;
}
}
static inline void F_178 ( T_1 * V_1 , T_2 * V_2 )
{
memset ( V_2 -> V_130 , 0 , sizeof( V_132 ) ) ;
F_4 ( & V_1 -> V_15 , V_2 ) ;
V_1 -> V_16 ++ ;
if ( V_1 -> V_16 > V_1 -> V_17 )
V_1 -> V_17 = V_1 -> V_16 ;
F_12 ( V_1 ) ;
}
static inline unsigned int F_179 ( unsigned int V_389 ,
unsigned int V_390 , unsigned int V_391 ,
unsigned int V_392 )
{
return ( V_389 & 0xff ) |
( ( V_390 & 0xff ) << 8 ) |
( ( V_391 & 0xff ) << 16 ) |
( ( V_392 & 0xff ) << 24 ) ;
}
static inline int F_180 ( T_1 * V_1 ,
T_2 * V_155 , int * V_393 )
{
unsigned char V_394 ;
unsigned char V_395 , V_390 , V_391 , V_392 ;
int V_396 ;
* V_393 = 0 ;
V_395 = V_155 -> V_130 -> V_192 ;
V_392 = V_397 ;
V_390 = V_155 -> V_130 -> V_190 ;
if ( V_155 -> V_264 -> V_11 == V_271 )
V_391 = V_398 ;
else
V_391 = V_399 ;
V_396 = F_179 ( V_395 , V_390 ,
V_391 , V_392 ) ;
if ( V_155 -> V_130 -> V_192 != V_193 ) {
if ( V_155 -> V_264 -> V_11 != V_271 )
F_153 ( & V_1 -> V_24 -> V_25 , L_69
L_70 ,
V_155 , V_155 -> V_130 -> V_192 ) ;
return V_396 ;
}
V_394 = 0xf & V_155 -> V_130 -> V_355 [ 2 ] ;
if ( ( ( V_394 == 0x0 ) || ( V_394 == 0x1 ) ) &&
( V_155 -> V_264 -> V_11 != V_271 ) )
V_396 = 0 ;
if ( F_105 ( V_1 , V_155 ) ) {
* V_393 = ! ( V_155 -> V_264 -> V_11 == V_271 ) ;
return 0 ;
}
if ( V_155 -> V_264 -> V_11 != V_271 ) {
if ( V_396 != 0 )
F_153 ( & V_1 -> V_24 -> V_25 , L_71
L_72 , V_155 , V_394 ) ;
return V_396 ;
}
if ( V_155 -> V_264 -> V_400 ) {
if ( V_155 -> V_264 -> V_401 > V_155 -> V_130 -> V_402 )
V_155 -> V_264 -> V_401 = V_155 -> V_130 -> V_402 ;
memcpy ( V_155 -> V_264 -> V_400 , V_155 -> V_130 -> V_355 ,
V_155 -> V_264 -> V_401 ) ;
} else
V_155 -> V_264 -> V_401 = 0 ;
return V_396 ;
}
static inline void F_181 ( T_1 * V_1 , T_2 * V_155 ,
int V_403 )
{
int V_393 = 0 ;
struct V_263 * V_264 = V_155 -> V_264 ;
V_264 -> V_274 = 0 ;
if ( V_403 )
V_264 -> V_274 = F_179 ( 0 , 0 , 0 , V_404 ) ;
if ( V_155 -> V_130 -> V_190 == 0 )
goto V_405;
switch ( V_155 -> V_130 -> V_190 ) {
case V_191 :
V_264 -> V_274 = F_180 ( V_1 , V_155 , & V_393 ) ;
break;
case V_358 :
if ( V_155 -> V_264 -> V_11 == V_406 ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_73
L_74
L_75 , V_155 ) ;
V_155 -> V_264 -> V_272 = V_155 -> V_130 -> V_273 ;
}
break;
case V_359 :
if ( V_155 -> V_264 -> V_11 == V_406 )
F_153 ( & V_1 -> V_24 -> V_25 , L_76
L_77
L_75 , V_155 ) ;
break;
case V_360 :
F_153 ( & V_1 -> V_24 -> V_25 , L_78
L_48 , V_155 ) ;
V_264 -> V_274 = F_179 ( V_354 ,
V_155 -> V_130 -> V_190 , V_397 ,
( V_155 -> V_264 -> V_11 == V_271 ) ?
V_398 : V_407 ) ;
break;
case V_361 :
F_153 ( & V_1 -> V_24 -> V_25 , L_79
L_50 , V_155 ) ;
V_264 -> V_274 = F_179 ( V_354 ,
V_155 -> V_130 -> V_190 , V_397 ,
( V_155 -> V_264 -> V_11 == V_271 ) ?
V_398 : V_407 ) ;
break;
case V_362 :
F_153 ( & V_1 -> V_24 -> V_25 , L_80
L_52 , V_155 ) ;
V_264 -> V_274 = F_179 ( V_354 ,
V_155 -> V_130 -> V_190 , V_397 ,
( V_155 -> V_264 -> V_11 == V_271 ) ?
V_398 : V_407 ) ;
break;
case V_363 :
F_153 ( & V_1 -> V_24 -> V_25 , L_80
L_53 , V_155 ) ;
V_264 -> V_274 = F_179 ( V_354 ,
V_155 -> V_130 -> V_190 , V_397 ,
( V_155 -> V_264 -> V_11 == V_271 ) ?
V_398 : V_407 ) ;
break;
case V_364 :
F_153 ( & V_1 -> V_24 -> V_25 , L_81
L_55 , V_155 ) ;
V_264 -> V_274 = F_179 ( V_354 ,
V_155 -> V_130 -> V_190 , V_397 ,
( V_155 -> V_264 -> V_11 == V_271 ) ?
V_398 : V_408 ) ;
break;
case V_365 :
F_153 ( & V_1 -> V_24 -> V_25 , L_82
L_57 , V_155 ) ;
V_264 -> V_274 = F_179 ( V_354 ,
V_155 -> V_130 -> V_190 , V_397 ,
( V_155 -> V_264 -> V_11 == V_271 ) ?
V_398 : V_407 ) ;
break;
case V_366 :
F_153 ( & V_1 -> V_24 -> V_25 , L_83
L_84 , V_1 -> V_62 , V_155 ) ;
if ( V_155 -> V_371 < V_372 ) {
V_393 = 1 ;
F_153 ( & V_1 -> V_24 -> V_25 , L_85 , V_155 ) ;
V_155 -> V_371 ++ ;
} else
F_153 ( & V_1 -> V_24 -> V_25 ,
L_86 , V_155 ) ;
V_264 -> V_274 = F_179 ( V_354 ,
V_155 -> V_130 -> V_190 , V_397 ,
( V_155 -> V_264 -> V_11 == V_271 ) ?
V_398 : V_408 ) ;
break;
case V_409 :
F_153 ( & V_1 -> V_24 -> V_25 , L_87 , V_155 ) ;
V_264 -> V_274 = F_179 ( V_354 ,
V_155 -> V_130 -> V_190 , V_397 ,
( V_155 -> V_264 -> V_11 == V_271 ) ?
V_398 : V_407 ) ;
break;
case V_367 :
F_153 ( & V_1 -> V_24 -> V_25 , L_88 , V_155 ) ;
V_264 -> V_274 = F_179 ( V_354 ,
V_155 -> V_130 -> V_190 , V_397 ,
V_155 -> V_264 -> V_11 == V_271 ?
V_398 : V_407 ) ;
break;
default:
F_153 ( & V_1 -> V_24 -> V_25 , L_89
L_61 , V_155 ,
V_155 -> V_130 -> V_190 ) ;
V_264 -> V_274 = F_179 ( V_354 ,
V_155 -> V_130 -> V_190 , V_397 ,
( V_155 -> V_264 -> V_11 == V_271 ) ?
V_398 : V_407 ) ;
}
V_405:
if ( V_393 ) {
F_178 ( V_1 , V_155 ) ;
return;
}
V_155 -> V_264 -> V_265 = V_155 ;
F_182 ( V_155 -> V_264 ) ;
}
static inline T_11 F_183 ( T_11 V_410 )
{
#define F_184 0x10
return V_410 & F_184 ;
}
static inline T_11 F_185 ( T_11 V_410 )
{
#define F_186 5
return V_410 >> F_186 ;
}
static inline T_11 F_83 ( T_1 * V_1 , T_11 V_410 )
{
#define F_187 ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define F_188 0x03
if ( F_3 ( V_1 -> V_3 & V_4 ) )
return V_410 & ~ F_187 ;
return V_410 & ~ F_188 ;
}
static inline void F_189 ( T_11 * V_410 )
{
* V_410 |= F_184 ;
}
static inline void F_190 ( T_11 * V_410 , T_11 V_411 )
{
* V_410 |= ( V_411 << F_186 ) ;
}
static void V_286 ( struct V_326 * V_327 )
{
T_1 * V_1 = V_327 -> V_143 ;
T_2 * V_2 ;
T_6 V_412 ;
int V_413 ;
struct V_263 * V_414 ;
T_4 V_28 ;
struct V_415 * V_416 ;
T_3 * V_267 ;
T_7 * V_63 ;
int V_20 , V_417 ;
int V_269 = 0 ;
int V_418 = 0 ;
V_142:
V_414 = F_191 ( V_327 ) ;
if ( ! V_414 )
goto V_419;
F_192 ( V_414 -> V_420 > V_1 -> V_296 ) ;
V_2 = F_73 ( V_1 ) ;
if ( ! V_2 )
goto V_421;
F_193 ( V_414 ) ;
V_416 = V_1 -> V_422 [ V_2 -> V_135 ] ;
F_194 ( V_327 -> V_423 ) ;
V_2 -> V_11 = V_424 ;
V_2 -> V_264 = V_414 ;
V_63 = V_414 -> V_425 -> V_75 ;
V_2 -> V_7 . V_230 = 0 ;
F_190 ( & V_2 -> V_7 . V_232 . V_33 , V_2 -> V_135 ) ;
F_189 ( & V_2 -> V_7 . V_232 . V_33 ) ;
memcpy ( & V_2 -> V_7 . V_231 , V_63 -> V_115 , sizeof( V_63 -> V_115 ) ) ;
V_2 -> V_180 . V_335 = 10 ;
V_2 -> V_180 . Type . Type = V_282 ;
V_2 -> V_180 . Type . V_336 = V_337 ;
V_2 -> V_180 . Type . V_226 =
( F_195 ( V_414 ) == V_426 ) ? V_235 : V_228 ;
V_2 -> V_180 . V_338 = 0 ;
V_2 -> V_180 . V_334 [ 0 ] =
( F_195 ( V_414 ) == V_426 ) ? V_1 -> V_305 : V_1 -> V_307 ;
V_412 = F_196 ( V_414 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_90 ,
( int ) F_196 ( V_414 ) , ( int ) F_197 ( V_414 ) ) ;
F_198 ( V_416 , V_1 -> V_296 ) ;
V_413 = F_199 ( V_327 , V_414 , V_416 ) ;
if ( V_2 -> V_180 . Type . V_226 == V_235 )
V_417 = V_270 ;
else
V_417 = V_38 ;
V_267 = V_2 -> V_31 ;
V_269 = 0 ;
V_418 = 0 ;
for ( V_20 = 0 ; V_20 < V_413 ; V_20 ++ ) {
if ( ( ( V_269 + 1 ) == ( V_1 -> V_30 ) ) &&
! V_418 && ( ( V_413 - V_20 ) > 1 ) ) {
V_267 = V_1 -> V_18 [ V_2 -> V_135 ] ;
V_269 = 0 ;
V_418 = 1 ;
}
V_267 [ V_269 ] . V_37 = V_416 [ V_20 ] . V_77 ;
V_28 . V_36 = ( V_137 ) F_200 ( V_1 -> V_24 , F_201 ( & V_416 [ V_20 ] ) ,
V_416 [ V_20 ] . V_427 ,
V_416 [ V_20 ] . V_77 , V_417 ) ;
V_267 [ V_269 ] . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_267 [ V_269 ] . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_267 [ V_269 ] . V_41 = 0 ;
++ V_269 ;
}
if ( V_418 )
F_21 ( V_1 , V_2 , V_1 -> V_18 [ V_2 -> V_135 ] ,
( V_413 - ( V_1 -> V_30 - 1 ) ) *
sizeof( T_3 ) ) ;
if ( V_413 > V_1 -> V_55 )
V_1 -> V_55 = V_413 ;
F_87 ( & V_1 -> V_24 -> V_25 , L_91
L_92 ,
F_197 ( V_414 ) , V_413 , V_418 ) ;
V_2 -> V_7 . V_29 = V_413 + V_418 ;
if ( V_413 <= V_1 -> V_30 )
V_2 -> V_7 . V_8 = V_2 -> V_7 . V_29 ;
else
V_2 -> V_7 . V_8 = V_1 -> V_30 ;
F_2 ( V_1 , V_2 ) ;
if ( F_3 ( V_414 -> V_11 == V_406 ) ) {
if( V_1 -> V_305 == V_309 ) {
V_2 -> V_180 . V_334 [ 1 ] = 0 ;
V_2 -> V_180 . V_334 [ 2 ] = ( V_412 >> 24 ) & 0xff ;
V_2 -> V_180 . V_334 [ 3 ] = ( V_412 >> 16 ) & 0xff ;
V_2 -> V_180 . V_334 [ 4 ] = ( V_412 >> 8 ) & 0xff ;
V_2 -> V_180 . V_334 [ 5 ] = V_412 & 0xff ;
V_2 -> V_180 . V_334 [ 6 ] = 0 ;
V_2 -> V_180 . V_334 [ 7 ] = ( F_197 ( V_414 ) >> 8 ) & 0xff ;
V_2 -> V_180 . V_334 [ 8 ] = F_197 ( V_414 ) & 0xff ;
V_2 -> V_180 . V_334 [ 9 ] = V_2 -> V_180 . V_334 [ 11 ] = V_2 -> V_180 . V_334 [ 12 ] = 0 ;
} else {
T_11 V_428 = F_202 ( V_412 ) ;
V_2 -> V_180 . V_335 = 16 ;
V_2 -> V_180 . V_334 [ 1 ] = 0 ;
V_2 -> V_180 . V_334 [ 2 ] = ( V_428 >> 24 ) & 0xff ;
V_2 -> V_180 . V_334 [ 3 ] = ( V_428 >> 16 ) & 0xff ;
V_2 -> V_180 . V_334 [ 4 ] = ( V_428 >> 8 ) & 0xff ;
V_2 -> V_180 . V_334 [ 5 ] = V_428 & 0xff ;
V_2 -> V_180 . V_334 [ 6 ] = ( V_412 >> 24 ) & 0xff ;
V_2 -> V_180 . V_334 [ 7 ] = ( V_412 >> 16 ) & 0xff ;
V_2 -> V_180 . V_334 [ 8 ] = ( V_412 >> 8 ) & 0xff ;
V_2 -> V_180 . V_334 [ 9 ] = V_412 & 0xff ;
V_2 -> V_180 . V_334 [ 10 ] = ( F_197 ( V_414 ) >> 24 ) & 0xff ;
V_2 -> V_180 . V_334 [ 11 ] = ( F_197 ( V_414 ) >> 16 ) & 0xff ;
V_2 -> V_180 . V_334 [ 12 ] = ( F_197 ( V_414 ) >> 8 ) & 0xff ;
V_2 -> V_180 . V_334 [ 13 ] = F_197 ( V_414 ) & 0xff ;
V_2 -> V_180 . V_334 [ 14 ] = V_2 -> V_180 . V_334 [ 15 ] = 0 ;
}
} else if ( V_414 -> V_11 == V_271 ) {
V_2 -> V_180 . V_335 = V_414 -> V_429 ;
memcpy ( V_2 -> V_180 . V_334 , V_414 -> V_155 , V_430 ) ;
} else {
F_153 ( & V_1 -> V_24 -> V_25 , L_93 ,
V_414 -> V_11 ) ;
F_203 () ;
}
F_204 ( V_327 -> V_423 ) ;
F_4 ( & V_1 -> V_15 , V_2 ) ;
V_1 -> V_16 ++ ;
if ( V_1 -> V_16 > V_1 -> V_17 )
V_1 -> V_17 = V_1 -> V_16 ;
goto V_142;
V_421:
F_205 ( V_327 ) ;
V_419:
F_12 ( V_1 ) ;
}
static inline unsigned long F_206 ( T_1 * V_1 )
{
return V_1 -> V_385 . V_431 ( V_1 ) ;
}
static inline int F_207 ( T_1 * V_1 )
{
return V_1 -> V_385 . V_432 ( V_1 ) ;
}
static inline long F_208 ( T_1 * V_1 )
{
return ( ( V_1 -> V_385 . V_432 ( V_1 ) == 0 ) ||
( V_1 -> V_433 == 0 ) ) ;
}
static inline int F_209 ( T_1 * V_1 , T_11 V_434 ,
T_11 V_435 )
{
if ( F_210 ( V_434 >= V_1 -> V_19 ) ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_94 , V_435 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_211 ( T_1 * V_1 , T_2 * V_2 ,
T_11 V_435 )
{
F_6 ( V_2 ) ;
if ( F_3 ( V_2 -> V_11 == V_424 ) )
F_181 ( V_1 , V_2 , 0 ) ;
else if ( V_2 -> V_11 == V_229 )
F_212 ( V_2 -> V_234 ) ;
#ifdef F_25
else if ( V_2 -> V_11 == V_436 )
F_213 ( V_2 , 0 , V_435 ) ;
#endif
}
static inline T_11 F_214 ( T_1 * V_1 )
{
T_11 V_437 ;
if ( F_210 ( ! ( V_1 -> V_3 & V_4 ) ) )
return V_1 -> V_385 . V_431 ( V_1 ) ;
if ( ( * ( V_1 -> V_438 ) & 1 ) == ( V_1 -> V_439 ) ) {
V_437 = * ( V_1 -> V_438 ) ;
( V_1 -> V_438 ) ++ ;
V_1 -> V_53 -- ;
} else {
V_437 = V_440 ;
}
if ( V_1 -> V_438 == ( V_1 -> V_441 + V_1 -> V_442 ) ) {
V_1 -> V_438 = V_1 -> V_441 ;
V_1 -> V_439 ^= 1 ;
}
return V_437 ;
}
static inline T_11 F_215 ( T_1 * V_1 , T_11 V_435 )
{
T_11 V_434 ;
T_2 * V_2 ;
V_434 = F_185 ( V_435 ) ;
if ( F_209 ( V_1 , V_434 , V_435 ) )
return F_214 ( V_1 ) ;
V_2 = V_1 -> V_128 + V_434 ;
F_211 ( V_1 , V_2 , V_435 ) ;
return F_214 ( V_1 ) ;
}
static inline T_11 F_216 ( T_1 * V_1 , T_11 V_435 )
{
T_2 * V_2 = NULL ;
V_136 V_443 , V_444 ;
V_444 = F_83 ( V_1 , V_435 ) ;
F_217 (c, &h->cmpQ, list) {
V_443 = F_83 ( V_1 , V_2 -> V_5 ) ;
if ( V_443 == V_444 ) {
F_211 ( V_1 , V_2 , V_435 ) ;
return F_214 ( V_1 ) ;
}
}
F_209 ( V_1 , V_1 -> V_19 + 1 , V_435 ) ;
return F_214 ( V_1 ) ;
}
static int F_218 ( T_1 * V_1 )
{
if ( F_3 ( ! V_445 ) )
return 0 ;
if ( F_3 ( V_1 -> V_433 ) )
return 0 ;
F_173 ( & V_1 -> V_24 -> V_25 , L_95
L_96 ) ;
return 1 ;
}
static T_36 F_219 ( int V_446 , void * V_447 )
{
T_1 * V_1 = V_447 ;
unsigned long V_13 ;
T_11 V_435 ;
if ( F_218 ( V_1 ) )
return V_448 ;
if ( F_208 ( V_1 ) )
return V_448 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
while ( F_207 ( V_1 ) ) {
V_435 = F_206 ( V_1 ) ;
while ( V_435 != V_440 )
V_435 = F_214 ( V_1 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_449 ;
}
static T_36 F_220 ( int V_446 , void * V_447 )
{
T_1 * V_1 = V_447 ;
unsigned long V_13 ;
T_11 V_435 ;
if ( F_218 ( V_1 ) )
return V_448 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_435 = F_206 ( V_1 ) ;
while ( V_435 != V_440 )
V_435 = F_214 ( V_1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_449 ;
}
static T_36 F_221 ( int V_446 , void * V_447 )
{
T_1 * V_1 = V_447 ;
unsigned long V_13 ;
T_11 V_435 ;
if ( F_208 ( V_1 ) )
return V_448 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
while ( F_207 ( V_1 ) ) {
V_435 = F_206 ( V_1 ) ;
while ( V_435 != V_440 ) {
if ( F_183 ( V_435 ) )
V_435 = F_215 ( V_1 , V_435 ) ;
else
V_435 = F_216 ( V_1 , V_435 ) ;
}
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_449 ;
}
static T_36 F_222 ( int V_446 , void * V_447 )
{
T_1 * V_1 = V_447 ;
unsigned long V_13 ;
T_11 V_435 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_435 = F_206 ( V_1 ) ;
while ( V_435 != V_440 ) {
if ( F_183 ( V_435 ) )
V_435 = F_215 ( V_1 , V_435 ) ;
else
V_435 = F_216 ( V_1 , V_435 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_449 ;
}
static int F_50 ( struct V_100 * V_1 )
{
struct V_100 * V_450 ;
int V_451 = 0 ;
int V_73 = 0 ;
if ( V_1 -> V_452 )
return 0 ;
if ( ! F_223 ( & V_1 -> V_453 ) )
return 0 ;
F_91 ( & V_454 ) ;
F_217 (test_h, &scan_q, scan_list) {
if ( V_450 == V_1 ) {
V_451 = 1 ;
break;
}
}
if ( ! V_451 && ! V_1 -> V_455 ) {
F_171 ( & V_1 -> V_103 ) ;
F_5 ( & V_1 -> V_456 , & V_457 ) ;
V_73 = 1 ;
}
F_92 ( & V_454 ) ;
F_92 ( & V_1 -> V_453 ) ;
return V_73 ;
}
static void F_224 ( struct V_100 * V_1 )
{
struct V_100 * V_450 , * V_458 ;
F_91 ( & V_454 ) ;
F_225 (test_h, tmp_h, &scan_q, scan_list) {
if ( V_450 == V_1 ) {
F_226 ( & V_1 -> V_456 ) ;
F_227 ( & V_1 -> V_103 ) ;
F_92 ( & V_454 ) ;
return;
}
}
if ( V_1 -> V_455 ) {
F_92 ( & V_454 ) ;
F_124 ( & V_1 -> V_103 ) ;
} else {
F_92 ( & V_454 ) ;
}
}
static int F_228 ( void * V_459 )
{
struct V_100 * V_1 ;
while ( 1 ) {
F_229 ( V_460 ) ;
F_230 () ;
if ( F_231 () )
break;
while ( 1 ) {
F_91 ( & V_454 ) ;
if ( F_8 ( & V_457 ) ) {
F_92 ( & V_454 ) ;
break;
}
V_1 = F_177 ( V_457 . V_384 ,
struct V_100 ,
V_456 ) ;
F_226 ( & V_1 -> V_456 ) ;
V_1 -> V_455 = 1 ;
F_92 ( & V_454 ) ;
F_127 ( V_1 , 0 , 0 ) ;
F_227 ( & V_1 -> V_103 ) ;
F_91 ( & V_454 ) ;
V_1 -> V_455 = 0 ;
F_92 ( & V_454 ) ;
}
}
return 0 ;
}
static int F_105 ( T_1 * V_1 , T_2 * V_2 )
{
if ( V_2 -> V_130 -> V_355 [ 2 ] != V_461 )
return 0 ;
switch ( V_2 -> V_130 -> V_355 [ 12 ] ) {
case V_462 :
F_153 ( & V_1 -> V_24 -> V_25 , L_97
L_98 ) ;
return 1 ;
break;
case V_463 :
F_153 ( & V_1 -> V_24 -> V_25 , L_99
L_100 ) ;
return 1 ;
break;
case V_464 :
F_153 ( & V_1 -> V_24 -> V_25 , L_101 ) ;
return 1 ;
break;
case V_465 :
F_153 ( & V_1 -> V_24 -> V_25 ,
L_102 ) ;
return 1 ;
break;
case V_466 :
F_153 ( & V_1 -> V_24 -> V_25 ,
L_103 ) ;
return 1 ;
break;
default:
F_153 ( & V_1 -> V_24 -> V_25 , L_104 ) ;
return 1 ;
}
}
static void F_232 ( T_1 * V_1 )
{
int V_20 ;
char V_467 [ 17 ] ;
T_37 * V_468 = V_1 -> V_202 ;
F_87 ( & V_1 -> V_24 -> V_25 , L_105 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_106 ) ;
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ )
V_467 [ V_20 ] = F_114 ( & ( V_468 -> V_469 [ V_20 ] ) ) ;
V_467 [ 4 ] = '\0' ;
F_87 ( & V_1 -> V_24 -> V_25 , L_107 , V_467 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_108 ,
F_109 ( & ( V_468 -> V_470 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_109 ,
F_109 ( & ( V_468 -> V_471 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_110 ,
F_109 ( & ( V_468 -> V_472 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_111 ,
F_109 ( & ( V_468 -> V_203 . V_473 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_112 ,
F_109 ( & ( V_468 -> V_203 . V_204 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_113 ,
F_109 ( & ( V_468 -> V_203 . V_205 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_114 ,
F_109 ( & ( V_468 -> V_474 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_115 ,
F_109 ( & ( V_468 -> V_215 ) ) ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
V_467 [ V_20 ] = F_114 ( & ( V_468 -> V_212 [ V_20 ] ) ) ;
V_467 [ 16 ] = '\0' ;
F_87 ( & V_1 -> V_24 -> V_25 , L_116 , V_467 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_117 ,
F_109 ( & ( V_468 -> V_214 ) ) ) ;
}
static int F_233 ( struct V_475 * V_24 , unsigned long V_476 )
{
int V_20 , V_427 , V_477 , V_478 ;
if ( V_476 == V_479 )
return 0 ;
V_427 = 0 ;
for ( V_20 = 0 ; V_20 < V_480 ; V_20 ++ ) {
V_478 = F_234 ( V_24 , V_20 ) & V_481 ;
if ( V_478 == V_482 )
V_427 += 4 ;
else {
V_477 = F_234 ( V_24 , V_20 ) &
V_483 ;
switch ( V_477 ) {
case V_484 :
case V_485 :
V_427 += 4 ;
break;
case V_486 :
V_427 += 8 ;
break;
default:
F_153 ( & V_24 -> V_25 ,
L_118 ) ;
return - 1 ;
break;
}
}
if ( V_427 == V_476 - V_479 )
return V_20 + 1 ;
}
return - 1 ;
}
static void F_235 ( int V_487 [] , int V_488 ,
int V_489 , int * V_490 )
{
int V_20 , V_22 , V_491 , V_330 ;
#define F_236 4
#define F_237 8
for ( V_20 = 0 ; V_20 <= V_489 ; V_20 ++ ) {
V_330 = V_20 + F_236 ;
V_491 = V_488 ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
if ( V_487 [ V_22 ] >= V_330 ) {
V_491 = V_22 ;
break;
}
}
V_490 [ V_20 ] = V_491 ;
}
}
static void F_238 ( T_1 * V_1 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_492 ; V_20 ++ ) {
if ( ! ( F_109 ( V_1 -> V_207 + V_208 ) & V_206 ) )
break;
F_239 ( 10000 , 20000 ) ;
}
}
static void F_240 ( T_1 * V_1 , T_11 V_493 )
{
V_136 V_494 ;
int V_495 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_245 + 4 } ;
unsigned long V_496 ;
F_241 ( 28 > V_245 + 4 ) ;
V_1 -> V_439 = 1 ;
memset ( V_1 -> V_441 , 0 , V_1 -> V_442 * sizeof( V_137 ) ) ;
V_1 -> V_438 = V_1 -> V_441 ;
V_494 = F_109 ( & ( V_1 -> V_202 -> V_497 ) ) ;
F_235 ( V_495 , F_44 ( V_495 ) , V_1 -> V_296 ,
V_1 -> V_6 ) ;
F_111 ( V_495 [ 0 ] , & V_1 -> V_498 -> V_499 ) ;
F_111 ( V_495 [ 1 ] , & V_1 -> V_498 -> V_500 ) ;
F_111 ( V_495 [ 2 ] , & V_1 -> V_498 -> V_501 ) ;
F_111 ( V_495 [ 3 ] , & V_1 -> V_498 -> V_502 ) ;
F_111 ( V_495 [ 4 ] , & V_1 -> V_498 -> V_503 ) ;
F_111 ( V_495 [ 5 ] , & V_1 -> V_498 -> V_504 ) ;
F_111 ( V_495 [ 6 ] , & V_1 -> V_498 -> V_505 ) ;
F_111 ( V_495 [ 7 ] , & V_1 -> V_498 -> V_506 ) ;
F_111 ( V_1 -> V_442 , & V_1 -> V_498 -> V_507 ) ;
F_111 ( 1 , & V_1 -> V_498 -> V_508 ) ;
F_111 ( 0 , & V_1 -> V_498 -> V_509 ) ;
F_111 ( 0 , & V_1 -> V_498 -> V_510 ) ;
F_111 ( V_1 -> V_511 , & V_1 -> V_498 -> V_512 ) ;
F_111 ( 0 , & V_1 -> V_498 -> V_513 ) ;
F_111 ( V_4 | V_493 ,
& ( V_1 -> V_202 -> V_203 . V_473 ) ) ;
F_111 ( V_206 , V_1 -> V_207 + V_208 ) ;
F_238 ( V_1 ) ;
V_496 = F_109 ( & ( V_1 -> V_202 -> V_472 ) ) ;
if ( ! ( V_496 & V_4 ) )
F_153 ( & V_1 -> V_24 -> V_25 , L_119
L_120 ) ;
}
static void F_242 ( T_1 * V_1 )
{
V_136 V_514 ;
if ( V_515 )
return;
F_87 ( & V_1 -> V_24 -> V_25 , L_121 ) ;
V_514 = F_109 ( & ( V_1 -> V_202 -> V_471 ) ) ;
if ( ! ( V_514 & V_516 ) )
return;
F_87 ( & V_1 -> V_24 -> V_25 , L_122 ) ;
if ( ( sizeof( T_2 ) % 32 ) != 0 ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_123 ,
L_124 ,
( int ) sizeof( T_2 ) ,
L_125 ) ;
return;
}
V_1 -> V_441 = ( V_137 * ) F_243 (
V_1 -> V_24 , V_1 -> V_442 * sizeof( V_137 ) ,
& ( V_1 -> V_511 ) ) ;
V_1 -> V_6 = F_17 ( ( ( V_1 -> V_296 + 1 ) *
sizeof( V_136 ) ) , V_23 ) ;
if ( ( V_1 -> V_441 == NULL ) || ( V_1 -> V_6 == NULL ) )
goto V_517;
F_240 ( V_1 ,
V_514 & V_518 ) ;
V_1 -> V_385 = V_519 ;
V_1 -> V_3 = V_4 ;
return;
V_517:
F_15 ( V_1 -> V_6 ) ;
if ( V_1 -> V_441 )
F_79 ( V_1 -> V_24 ,
V_1 -> V_442 * sizeof( V_137 ) ,
V_1 -> V_441 ,
V_1 -> V_511 ) ;
return;
}
static void F_244 ( T_1 * V_1 )
{
#ifdef F_245
int V_79 ;
struct V_520 V_521 [ 4 ] = { { 0 , 0 } , { 0 , 1 } ,
{ 0 , 2 } , { 0 , 3 }
} ;
if ( ( V_1 -> V_48 == 0x40700E11 ) || ( V_1 -> V_48 == 0x40800E11 ) ||
( V_1 -> V_48 == 0x40820E11 ) || ( V_1 -> V_48 == 0x40830E11 ) )
goto V_522;
if ( F_246 ( V_1 -> V_24 , V_523 ) ) {
V_79 = F_247 ( V_1 -> V_24 , V_521 , 4 ) ;
if ( ! V_79 ) {
V_1 -> V_50 [ 0 ] = V_521 [ 0 ] . V_524 ;
V_1 -> V_50 [ 1 ] = V_521 [ 1 ] . V_524 ;
V_1 -> V_50 [ 2 ] = V_521 [ 2 ] . V_524 ;
V_1 -> V_50 [ 3 ] = V_521 [ 3 ] . V_524 ;
V_1 -> V_525 = 1 ;
return;
} else {
F_153 ( & V_1 -> V_24 -> V_25 ,
L_126 , V_79 ) ;
}
}
if ( F_246 ( V_1 -> V_24 , V_526 ) ) {
if ( ! F_248 ( V_1 -> V_24 ) )
V_1 -> V_527 = 1 ;
else
F_153 ( & V_1 -> V_24 -> V_25 , L_127 ) ;
}
V_522:
#endif
V_1 -> V_50 [ V_1 -> V_51 ] = V_1 -> V_24 -> V_446 ;
return;
}
static int F_249 ( struct V_475 * V_24 , T_11 * V_48 )
{
int V_20 ;
T_11 V_528 , V_529 ;
V_528 = V_24 -> V_530 ;
V_529 = V_24 -> V_531 ;
* V_48 = ( ( V_529 << 16 ) & 0xffff0000 ) |
V_528 ;
for ( V_20 = 0 ; V_20 < F_44 ( V_532 ) ; V_20 ++ ) {
if ( V_533 )
return - V_534 ;
if ( * V_48 == V_532 [ V_20 ] . V_48 )
return V_20 ;
}
F_153 ( & V_24 -> V_25 , L_128 ,
* V_48 ) ;
return - V_534 ;
}
static inline bool F_250 ( T_1 * V_1 )
{
T_38 V_535 ;
( void ) F_251 ( V_1 -> V_24 , V_536 , & V_535 ) ;
return ( ( V_535 & V_537 ) == 0 ) ;
}
static int F_252 ( struct V_475 * V_24 ,
unsigned long * V_538 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_480 ; V_20 ++ )
if ( F_234 ( V_24 , V_20 ) & V_539 ) {
* V_538 = F_253 ( V_24 , V_20 ) ;
F_87 ( & V_24 -> V_25 , L_129 ,
* V_538 ) ;
return 0 ;
}
F_153 ( & V_24 -> V_25 , L_130 ) ;
return - V_534 ;
}
static int F_254 ( struct V_475 * V_24 ,
void T_34 * V_207 , int V_540 )
#define F_255 1
#define F_256 0
{
int V_20 , V_541 ;
T_11 V_542 ;
if ( V_540 )
V_541 = V_543 ;
else
V_541 = V_544 ;
for ( V_20 = 0 ; V_20 < V_541 ; V_20 ++ ) {
V_542 = F_109 ( V_207 + V_545 ) ;
if ( V_540 ) {
if ( V_542 == V_546 )
return 0 ;
} else {
if ( V_542 != V_546 )
return 0 ;
}
F_257 ( V_547 ) ;
}
F_153 ( & V_24 -> V_25 , L_131 ) ;
return - V_534 ;
}
static int F_258 ( struct V_475 * V_24 , void T_34 * V_207 ,
T_11 * V_548 , T_39 * V_549 ,
T_39 * V_550 )
{
* V_548 = F_109 ( V_207 + V_551 ) ;
* V_550 = F_109 ( V_207 + V_552 ) ;
* V_548 &= ( T_11 ) 0x0000ffff ;
* V_549 = F_233 ( V_24 , * V_548 ) ;
if ( * V_549 == - 1 ) {
F_153 ( & V_24 -> V_25 , L_132
L_133 , * V_548 ) ;
return - V_534 ;
}
return 0 ;
}
static int F_259 ( T_1 * V_1 )
{
T_39 V_550 ;
T_11 V_548 ;
T_39 V_549 ;
T_11 V_494 ;
int V_279 ;
V_279 = F_258 ( V_1 -> V_24 , V_1 -> V_207 , & V_548 ,
& V_549 , & V_550 ) ;
if ( V_279 )
return V_279 ;
V_1 -> V_202 = F_175 ( F_253 ( V_1 -> V_24 ,
V_549 ) + V_550 , sizeof( * V_1 -> V_202 ) ) ;
if ( ! V_1 -> V_202 )
return - V_83 ;
V_279 = F_260 ( V_1 -> V_202 ) ;
if ( V_279 )
return V_279 ;
V_494 = F_109 ( & V_1 -> V_202 -> V_497 ) ;
V_1 -> V_498 = F_175 ( F_253 ( V_1 -> V_24 ,
V_549 ) + V_550 + V_494 ,
sizeof( * V_1 -> V_498 ) ) ;
if ( ! V_1 -> V_498 )
return - V_83 ;
return 0 ;
}
static void F_261 ( struct V_100 * V_1 )
{
V_1 -> V_442 = F_109 ( & ( V_1 -> V_202 -> V_553 ) ) ;
if ( V_445 && V_1 -> V_442 > 32 )
V_1 -> V_442 = 32 ;
if ( V_1 -> V_442 < 16 ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_134
L_135
L_136 ,
V_1 -> V_442 ) ;
V_1 -> V_442 = 16 ;
}
}
static void F_262 ( T_1 * V_1 )
{
F_261 ( V_1 ) ;
V_1 -> V_19 = V_1 -> V_442 - 4 - V_554 ;
V_1 -> V_296 = F_109 ( & ( V_1 -> V_202 -> V_555 ) ) ;
if ( V_1 -> V_48 == 0x3225103C )
V_1 -> V_296 = V_245 ;
V_1 -> V_30 = 31 ;
if ( V_1 -> V_296 > 512 ) {
V_1 -> V_30 = 32 ;
V_1 -> V_21 = V_1 -> V_296 - V_1 -> V_30 + 1 ;
V_1 -> V_296 -- ;
} else {
V_1 -> V_296 = 31 ;
V_1 -> V_21 = 0 ;
}
}
static inline bool F_263 ( T_1 * V_1 )
{
if ( ! F_264 ( V_1 -> V_202 -> V_469 , L_137 , 4 ) ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_138 ) ;
return false ;
}
return true ;
}
static inline void F_265 ( T_1 * V_1 )
{
#ifdef F_266
T_11 V_556 ;
V_556 = F_109 ( & ( V_1 -> V_202 -> V_557 ) ) ;
V_556 |= 0x100 ;
F_111 ( V_556 , & ( V_1 -> V_202 -> V_557 ) ) ;
#endif
}
static inline void F_267 ( T_1 * V_1 )
{
T_11 V_558 ;
V_136 V_559 ;
if ( V_1 -> V_48 != 0x3225103C )
return;
V_558 = F_109 ( V_1 -> V_207 + V_560 ) ;
V_558 |= 0x8000 ;
F_111 ( V_558 , V_1 -> V_207 + V_560 ) ;
F_268 ( V_1 -> V_24 , V_561 , & V_559 ) ;
V_559 |= 0x1 ;
F_269 ( V_1 -> V_24 , V_561 , V_559 ) ;
}
static int F_270 ( T_1 * V_1 )
{
int V_562 , V_79 ;
V_562 = F_249 ( V_1 -> V_24 , & V_1 -> V_48 ) ;
if ( V_562 < 0 )
return - V_534 ;
V_1 -> V_47 = V_532 [ V_562 ] . V_47 ;
V_1 -> V_385 = * ( V_532 [ V_562 ] . V_385 ) ;
if ( F_250 ( V_1 ) ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_139 ) ;
return - V_534 ;
}
F_271 ( V_1 -> V_24 , V_563 |
V_564 | V_565 ) ;
V_79 = F_272 ( V_1 -> V_24 ) ;
if ( V_79 ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_140 ) ;
return V_79 ;
}
V_79 = F_273 ( V_1 -> V_24 , L_141 ) ;
if ( V_79 ) {
F_153 ( & V_1 -> V_24 -> V_25 ,
L_142 ) ;
return V_79 ;
}
F_87 ( & V_1 -> V_24 -> V_25 , L_143 , V_1 -> V_24 -> V_446 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_144 , V_1 -> V_48 ) ;
F_244 ( V_1 ) ;
V_79 = F_252 ( V_1 -> V_24 , & V_1 -> V_566 ) ;
if ( V_79 )
goto V_567;
V_1 -> V_207 = F_175 ( V_1 -> V_566 , 0x250 ) ;
if ( ! V_1 -> V_207 ) {
V_79 = - V_83 ;
goto V_567;
}
V_79 = F_254 ( V_1 -> V_24 , V_1 -> V_207 , F_255 ) ;
if ( V_79 )
goto V_567;
V_79 = F_259 ( V_1 ) ;
if ( V_79 )
goto V_567;
F_232 ( V_1 ) ;
F_262 ( V_1 ) ;
if ( ! F_263 ( V_1 ) ) {
V_79 = - V_534 ;
goto V_567;
}
F_265 ( V_1 ) ;
F_267 ( V_1 ) ;
V_79 = F_274 ( V_1 ) ;
if ( V_79 )
goto V_567;
F_242 ( V_1 ) ;
return 0 ;
V_567:
if ( V_1 -> V_498 )
F_275 ( V_1 -> V_498 ) ;
if ( V_1 -> V_202 )
F_275 ( V_1 -> V_202 ) ;
if ( V_1 -> V_207 )
F_275 ( V_1 -> V_207 ) ;
F_276 ( V_1 -> V_24 ) ;
return V_79 ;
}
static int F_277 ( struct V_475 * V_24 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_568 ; V_20 ++ ) {
if ( ! V_266 [ V_20 ] ) {
T_1 * V_1 ;
V_1 = F_126 ( sizeof( T_1 ) , V_23 ) ;
if ( ! V_1 )
goto V_569;
V_266 [ V_20 ] = V_1 ;
return V_20 ;
}
}
F_153 ( & V_24 -> V_25 , L_145
L_146 , V_568 ) ;
return - 1 ;
V_569:
F_153 ( & V_24 -> V_25 , L_147 ) ;
return - 1 ;
}
static void F_278 ( T_1 * V_1 )
{
int V_20 ;
V_266 [ V_1 -> V_62 ] = NULL ;
for ( V_20 = 0 ; V_20 < V_1 -> V_64 + 1 ; V_20 ++ )
if ( V_1 -> V_140 [ V_20 ] != NULL )
F_159 ( V_1 -> V_140 [ V_20 ] ) ;
F_15 ( V_1 ) ;
}
static int F_279 ( struct V_475 * V_24 , unsigned char V_570 ,
unsigned char type )
{
typedef struct {
T_40 V_571 ;
T_41 V_180 ;
T_42 V_572 ;
} T_43;
static const T_10 V_573 = sizeof( T_43 ) + sizeof( V_132 ) ;
T_43 * V_155 ;
T_13 V_574 ;
T_28 V_575 , V_410 ;
void T_34 * V_207 ;
int V_20 , V_79 ;
V_207 = F_280 ( F_253 ( V_24 , 0 ) , F_281 ( V_24 , 0 ) ) ;
if ( V_207 == NULL )
return - V_83 ;
V_79 = F_282 ( V_24 , F_283 ( 32 ) ) ;
if ( V_79 ) {
F_275 ( V_207 ) ;
return - V_83 ;
}
V_155 = F_243 ( V_24 , V_573 , & V_574 ) ;
if ( V_155 == NULL ) {
F_275 ( V_207 ) ;
return - V_83 ;
}
V_575 = V_574 ;
V_155 -> V_571 . V_230 = 0 ;
V_155 -> V_571 . V_8 = 0 ;
V_155 -> V_571 . V_29 = 0 ;
V_155 -> V_571 . V_232 . V_33 = V_575 ;
V_155 -> V_571 . V_232 . V_35 = 0 ;
memset ( & V_155 -> V_571 . V_231 . V_333 , 0 , 8 ) ;
V_155 -> V_180 . V_335 = 16 ;
V_155 -> V_180 . Type . Type = V_347 ;
V_155 -> V_180 . Type . V_336 = V_576 ;
V_155 -> V_180 . Type . V_226 = V_227 ;
V_155 -> V_180 . V_338 = 0 ;
V_155 -> V_180 . V_334 [ 0 ] = V_570 ;
V_155 -> V_180 . V_334 [ 1 ] = type ;
memset ( & V_155 -> V_180 . V_334 [ 2 ] , 0 , 14 ) ;
V_155 -> V_572 . V_34 . V_33 = V_575 + sizeof( T_43 ) ;
V_155 -> V_572 . V_34 . V_35 = 0 ;
V_155 -> V_572 . V_37 = sizeof( V_132 ) ;
F_111 ( V_575 , V_207 + V_577 ) ;
for ( V_20 = 0 ; V_20 < 10 ; V_20 ++ ) {
V_410 = F_109 ( V_207 + V_578 ) ;
if ( ( V_410 & ~ 3 ) == V_575 )
break;
F_257 ( V_579 ) ;
}
F_275 ( V_207 ) ;
if ( V_20 == 10 ) {
F_18 ( & V_24 -> V_25 ,
L_148 ,
V_570 , type ) ;
return - V_580 ;
}
F_79 ( V_24 , V_573 , V_155 , V_574 ) ;
if ( V_410 & 2 ) {
F_18 ( & V_24 -> V_25 , L_149 ,
V_570 , type ) ;
return - V_275 ;
}
F_173 ( & V_24 -> V_25 , L_150 ,
V_570 , type ) ;
return 0 ;
}
static int F_284 ( struct V_475 * V_24 ,
void * T_34 V_207 , T_11 V_581 )
{
T_38 V_582 ;
int V_56 ;
if ( V_581 ) {
F_173 ( & V_24 -> V_25 , L_151 ) ;
F_111 ( V_581 , V_207 + V_208 ) ;
} else {
V_56 = F_246 ( V_24 , V_583 ) ;
if ( V_56 == 0 ) {
F_18 ( & V_24 -> V_25 ,
L_152
L_153 ) ;
return - V_534 ;
}
F_173 ( & V_24 -> V_25 , L_154 ) ;
F_251 ( V_24 , V_56 + V_584 , & V_582 ) ;
V_582 &= ~ V_585 ;
V_582 |= V_586 ;
F_285 ( V_24 , V_56 + V_584 , V_582 ) ;
F_257 ( 500 ) ;
V_582 &= ~ V_585 ;
V_582 |= V_587 ;
F_285 ( V_24 , V_56 + V_584 , V_582 ) ;
F_257 ( 500 ) ;
}
return 0 ;
}
static void F_286 ( char * V_588 , int V_40 )
{
memset ( V_588 , 0 , V_40 ) ;
strncpy ( V_588 , L_155 V_589 , V_40 - 1 ) ;
}
static int F_260 ( T_37 T_34 * V_202 )
{
char * V_588 ;
int V_20 , V_330 = sizeof( V_202 -> V_588 ) ;
V_588 = F_17 ( V_330 , V_23 ) ;
if ( ! V_588 )
return - V_83 ;
F_286 ( V_588 , V_330 ) ;
for ( V_20 = 0 ; V_20 < V_330 ; V_20 ++ )
F_116 ( V_588 [ V_20 ] , & V_202 -> V_588 [ V_20 ] ) ;
F_15 ( V_588 ) ;
return 0 ;
}
static void F_287 ( T_37 T_34 * V_202 ,
unsigned char * V_590 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < sizeof( V_202 -> V_588 ) ; V_20 ++ )
V_590 [ V_20 ] = F_114 ( & V_202 -> V_588 [ V_20 ] ) ;
}
static int F_288 ( T_37 T_34 * V_202 )
{
char * V_590 , * V_591 ;
int V_279 , V_330 = sizeof( V_202 -> V_588 ) ;
V_591 = F_17 ( 2 * V_330 , V_23 ) ;
if ( ! V_591 )
return - V_83 ;
V_590 = V_591 + V_330 ;
F_286 ( V_591 , V_330 ) ;
F_287 ( V_202 , V_590 ) ;
V_279 = ! memcmp ( V_590 , V_591 , V_330 ) ;
F_15 ( V_591 ) ;
return V_279 ;
}
static int F_289 ( struct V_475 * V_24 )
{
T_39 V_550 ;
T_11 V_548 ;
T_39 V_549 ;
void T_34 * V_207 ;
unsigned long V_566 ;
T_11 V_592 ;
int V_279 ;
T_37 T_34 * V_202 ;
T_11 V_581 ;
T_11 V_48 ;
T_38 V_593 ;
F_249 ( V_24 , & V_48 ) ;
if ( ! F_46 ( V_48 ) ) {
F_153 ( & V_24 -> V_25 , L_156
L_157 ) ;
return - V_534 ;
}
if ( ! F_43 ( V_48 ) )
return - V_594 ;
F_251 ( V_24 , 4 , & V_593 ) ;
F_290 ( V_24 ) ;
F_291 ( V_24 ) ;
V_279 = F_252 ( V_24 , & V_566 ) ;
if ( V_279 )
return V_279 ;
V_207 = F_175 ( V_566 , 0x250 ) ;
if ( ! V_207 )
return - V_83 ;
V_279 = F_258 ( V_24 , V_207 , & V_548 ,
& V_549 , & V_550 ) ;
if ( V_279 )
goto V_595;
V_202 = F_175 ( F_253 ( V_24 ,
V_549 ) + V_550 , sizeof( * V_202 ) ) ;
if ( ! V_202 ) {
V_279 = - V_83 ;
goto V_595;
}
V_279 = F_260 ( V_202 ) ;
if ( V_279 )
goto V_595;
V_592 = F_109 ( & V_202 -> V_592 ) ;
V_581 = V_592 & V_596 ;
if ( V_581 ) {
V_581 = V_597 ;
} else {
V_581 = V_592 & V_598 ;
if ( V_581 ) {
F_153 ( & V_24 -> V_25 , L_158
L_159
L_160
L_161 ) ;
V_279 = - V_594 ;
goto V_599;
}
}
V_279 = F_284 ( V_24 , V_207 , V_581 ) ;
if ( V_279 )
goto V_599;
F_292 ( V_24 ) ;
V_279 = F_272 ( V_24 ) ;
if ( V_279 ) {
F_153 ( & V_24 -> V_25 , L_162 ) ;
goto V_599;
}
F_285 ( V_24 , 4 , V_593 ) ;
F_257 ( V_600 ) ;
F_173 ( & V_24 -> V_25 , L_163 ) ;
V_279 = F_254 ( V_24 , V_207 , F_256 ) ;
if ( V_279 ) {
F_153 ( & V_24 -> V_25 , L_164
L_165 ) ;
V_279 = - V_594 ;
goto V_599;
}
V_279 = F_254 ( V_24 , V_207 , F_255 ) ;
if ( V_279 ) {
F_153 ( & V_24 -> V_25 ,
L_166
L_167 ) ;
goto V_599;
}
V_279 = F_288 ( V_207 ) ;
if ( V_279 < 0 )
goto V_599;
if ( V_279 ) {
F_153 ( & V_24 -> V_25 , L_168
L_169 ) ;
V_279 = - V_594 ;
} else {
F_173 ( & V_24 -> V_25 , L_170 ) ;
}
V_599:
F_275 ( V_202 ) ;
V_595:
F_275 ( V_207 ) ;
return V_279 ;
}
static int F_293 ( struct V_475 * V_24 )
{
int V_279 , V_20 ;
if ( ! V_445 )
return 0 ;
V_279 = F_289 ( V_24 ) ;
if ( V_279 == - V_594 )
return V_279 ;
if ( V_279 )
return - V_534 ;
F_153 ( & V_24 -> V_25 , L_171 ) ;
for ( V_20 = 0 ; V_20 < V_601 ; V_20 ++ ) {
if ( F_294 ( V_24 ) == 0 )
break;
else
F_153 ( & V_24 -> V_25 , L_172 ,
( V_20 < V_601 - 1 ?
L_173 : L_174 ) ) ;
F_257 ( V_602 ) ;
}
return 0 ;
}
static int F_295 ( T_1 * V_1 )
{
V_1 -> V_127 = F_17 ( F_296 ( V_1 -> V_19 ) *
sizeof( unsigned long ) , V_23 ) ;
V_1 -> V_128 = F_243 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( T_2 ) ,
& ( V_1 -> V_129 ) ) ;
V_1 -> V_131 = F_243 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( V_132 ) ,
& ( V_1 -> V_133 ) ) ;
if ( ( V_1 -> V_127 == NULL )
|| ( V_1 -> V_128 == NULL )
|| ( V_1 -> V_131 == NULL ) ) {
F_18 ( & V_1 -> V_24 -> V_25 , L_175 ) ;
return - V_83 ;
}
return 0 ;
}
static int F_297 ( T_1 * V_1 )
{
int V_20 ;
V_1 -> V_422 = F_126 ( V_1 -> V_442 *
sizeof( struct V_415 * ) , V_23 ) ;
if ( ! V_1 -> V_422 )
return - V_83 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_19 ; V_20 ++ ) {
V_1 -> V_422 [ V_20 ] = F_17 ( sizeof( struct V_415 ) *
V_1 -> V_296 , V_23 ) ;
if ( V_1 -> V_422 [ V_20 ] == NULL ) {
F_18 ( & V_1 -> V_24 -> V_25 , L_176
L_177 ) ;
return - V_83 ;
}
}
return 0 ;
}
static void F_298 ( T_1 * V_1 )
{
int V_20 ;
if ( V_1 -> V_422 ) {
for ( V_20 = 0 ; V_20 < V_1 -> V_19 ; V_20 ++ )
F_15 ( V_1 -> V_422 [ V_20 ] ) ;
F_15 ( V_1 -> V_422 ) ;
}
}
static void F_299 ( T_1 * V_1 )
{
F_15 ( V_1 -> V_127 ) ;
if ( V_1 -> V_128 )
F_79 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( T_2 ) ,
V_1 -> V_128 , V_1 -> V_129 ) ;
if ( V_1 -> V_131 )
F_79 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( V_132 ) ,
V_1 -> V_131 , V_1 -> V_133 ) ;
}
static int F_300 ( T_1 * V_1 ,
T_36 (* F_301)( int , void * ) ,
T_36 (* F_302)( int , void * ) )
{
if ( V_1 -> V_525 || V_1 -> V_527 ) {
if ( ! F_303 ( V_1 -> V_50 [ V_1 -> V_51 ] , F_301 ,
0 , V_1 -> V_46 , V_1 ) )
return 0 ;
F_18 ( & V_1 -> V_24 -> V_25 , L_178
L_179 , V_1 -> V_50 [ V_1 -> V_51 ] ,
V_1 -> V_46 ) ;
return - 1 ;
}
if ( ! F_303 ( V_1 -> V_50 [ V_1 -> V_51 ] , F_302 ,
V_603 , V_1 -> V_46 , V_1 ) )
return 0 ;
F_18 ( & V_1 -> V_24 -> V_25 , L_180 ,
V_1 -> V_50 [ V_1 -> V_51 ] , V_1 -> V_46 ) ;
return - 1 ;
}
static int F_304 ( T_1 * V_1 )
{
if ( F_167 ( V_1 , V_151 , V_604 ) ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_181 ) ;
return - V_275 ;
}
F_173 ( & V_1 -> V_24 -> V_25 , L_182 ) ;
if ( F_254 ( V_1 -> V_24 , V_1 -> V_207 , F_256 ) ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_183 ) ;
return - 1 ;
}
F_173 ( & V_1 -> V_24 -> V_25 , L_184 ) ;
if ( F_254 ( V_1 -> V_24 , V_1 -> V_207 , F_255 ) ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_185
L_186 ) ;
return - 1 ;
}
return 0 ;
}
static void F_305 ( T_1 * V_1 )
{
int V_62 = V_1 -> V_62 ;
F_306 ( V_1 -> V_50 [ V_1 -> V_51 ] , V_1 ) ;
#ifdef F_245
if ( V_1 -> V_525 )
F_307 ( V_1 -> V_24 ) ;
else if ( V_1 -> V_527 )
F_308 ( V_1 -> V_24 ) ;
#endif
F_14 ( V_1 -> V_18 , V_1 -> V_19 ) ;
F_298 ( V_1 ) ;
F_299 ( V_1 ) ;
F_15 ( V_1 -> V_6 ) ;
if ( V_1 -> V_441 )
F_79 ( V_1 -> V_24 , V_1 -> V_442 * sizeof( V_137 ) ,
V_1 -> V_441 , V_1 -> V_511 ) ;
if ( V_1 -> V_498 )
F_275 ( V_1 -> V_498 ) ;
if ( V_1 -> V_202 )
F_275 ( V_1 -> V_202 ) ;
if ( V_1 -> V_207 )
F_275 ( V_1 -> V_207 ) ;
F_309 ( V_1 -> V_288 , V_1 -> V_46 ) ;
F_67 ( V_1 ) ;
F_276 ( V_1 -> V_24 ) ;
F_15 ( V_1 ) ;
V_266 [ V_62 ] = NULL ;
}
static int F_310 ( struct V_475 * V_24 , const struct V_605 * V_606 )
{
int V_20 ;
int V_22 = 0 ;
int V_279 ;
int V_607 = 0 ;
int V_608 , V_317 ;
T_29 * V_301 ;
T_1 * V_1 ;
unsigned long V_13 ;
if ( ( V_445 ) && ( V_533 == 1 ) )
return - V_534 ;
V_279 = F_293 ( V_24 ) ;
if ( V_279 ) {
if ( V_279 != - V_594 )
return V_279 ;
V_607 = 1 ;
V_279 = 0 ;
}
V_609:
V_20 = F_277 ( V_24 ) ;
if ( V_20 < 0 )
return - V_83 ;
V_1 = V_266 [ V_20 ] ;
V_1 -> V_24 = V_24 ;
V_1 -> V_452 = 1 ;
V_1 -> V_51 = V_515 ? V_610 : V_611 ;
F_76 ( & V_1 -> V_388 ) ;
F_76 ( & V_1 -> V_15 ) ;
F_311 ( & V_1 -> V_453 ) ;
if ( F_270 ( V_1 ) != 0 )
goto V_612;
sprintf ( V_1 -> V_46 , L_187 , V_20 ) ;
V_1 -> V_62 = V_20 ;
if ( V_554 < 2 )
V_554 = 2 ;
if ( V_554 > 16 )
V_554 = 16 ;
F_312 ( & V_1 -> V_103 ) ;
if ( F_63 ( V_1 ) )
goto V_613;
if ( ! F_313 ( V_24 , F_283 ( 64 ) ) )
V_608 = 1 ;
else if ( ! F_313 ( V_24 , F_283 ( 32 ) ) )
V_608 = 0 ;
else {
F_18 ( & V_1 -> V_24 -> V_25 , L_188 ) ;
goto V_614;
}
if ( V_20 < V_615 )
V_1 -> V_288 = V_616 + V_20 ;
V_279 = F_314 ( V_1 -> V_288 , V_1 -> V_46 ) ;
if ( V_279 == - V_58 || V_279 == - V_81 ) {
F_18 ( & V_1 -> V_24 -> V_25 ,
L_189
L_190 , V_1 -> V_288 , V_1 -> V_46 , V_20 ) ;
goto V_614;
} else {
if ( V_20 >= V_615 )
V_1 -> V_288 = V_279 ;
}
V_1 -> V_385 . V_617 ( V_1 , V_618 ) ;
V_279 = F_300 ( V_1 , F_222 , F_221 ) ;
if ( V_279 )
goto V_619;
F_173 ( & V_1 -> V_24 -> V_25 , L_191 ,
V_1 -> V_46 , V_24 -> V_97 , F_315 ( V_24 ) ,
V_1 -> V_50 [ V_1 -> V_51 ] , V_608 ? L_174 : L_192 ) ;
if ( F_295 ( V_1 ) )
goto V_620;
if ( F_297 ( V_1 ) )
goto V_620;
V_1 -> V_18 = F_16 ( V_1 ,
V_1 -> V_21 , V_1 -> V_19 ) ;
if ( ! V_1 -> V_18 && V_1 -> V_21 > 0 )
goto V_620;
F_316 ( & V_1 -> V_14 ) ;
F_317 ( V_24 , V_1 ) ;
F_318 ( V_1 -> V_127 , V_1 -> V_19 ) ;
V_1 -> V_52 = 0 ;
V_1 -> V_64 = - 1 ;
for ( V_22 = 0 ; V_22 < V_313 ; V_22 ++ ) {
V_1 -> V_63 [ V_22 ] = NULL ;
V_1 -> V_140 [ V_22 ] = NULL ;
}
if ( V_607 ) {
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_1 -> V_385 . V_617 ( V_1 , V_618 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
F_306 ( V_1 -> V_50 [ V_1 -> V_51 ] , V_1 ) ;
V_279 = F_300 ( V_1 , F_220 ,
F_219 ) ;
if ( V_279 ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_193
L_194 ) ;
goto V_620;
}
V_279 = F_304 ( V_1 ) ;
if ( V_279 ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_195 ) ;
goto V_620;
}
F_173 ( & V_1 -> V_24 -> V_25 , L_196 ) ;
F_173 ( & V_1 -> V_24 -> V_25 ,
L_197 ) ;
V_1 -> V_385 . V_617 ( V_1 , V_621 ) ;
F_257 ( 10000 ) ;
V_1 -> V_385 . V_617 ( V_1 , V_618 ) ;
V_279 = F_288 ( V_1 -> V_202 ) ;
if ( V_279 )
F_173 ( & V_1 -> V_24 -> V_25 ,
L_198 ) ;
F_305 ( V_1 ) ;
V_607 = 0 ;
if ( V_279 )
return - V_534 ;
goto V_609;
}
F_319 ( V_1 ) ;
V_1 -> V_385 . V_617 ( V_1 , V_621 ) ;
V_301 = F_126 ( sizeof( T_29 ) , V_23 ) ;
if ( V_301 == NULL ) {
F_18 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
goto V_620;
}
V_317 = F_136 ( V_1 , V_281 , V_301 ,
sizeof( T_29 ) , 0 , V_151 , V_282 ) ;
if ( V_317 == V_283 ) {
V_1 -> V_49 [ 0 ] = V_301 -> V_284 [ 32 ] ;
V_1 -> V_49 [ 1 ] = V_301 -> V_284 [ 33 ] ;
V_1 -> V_49 [ 2 ] = V_301 -> V_284 [ 34 ] ;
V_1 -> V_49 [ 3 ] = V_301 -> V_284 [ 35 ] ;
} else {
F_153 ( & V_1 -> V_24 -> V_25 , L_199
L_200 ) ;
}
F_15 ( V_301 ) ;
F_1 ( V_1 ) ;
V_1 -> V_297 = 8192 ;
F_127 ( V_1 , 1 , 0 ) ;
F_39 ( V_1 ) ;
V_1 -> V_452 = 0 ;
return 0 ;
V_620:
F_299 ( V_1 ) ;
F_298 ( V_1 ) ;
F_14 ( V_1 -> V_18 , V_1 -> V_19 ) ;
F_306 ( V_1 -> V_50 [ V_1 -> V_51 ] , V_1 ) ;
V_619:
F_309 ( V_1 -> V_288 , V_1 -> V_46 ) ;
V_614:
F_67 ( V_1 ) ;
V_613:
F_276 ( V_24 ) ;
V_612:
V_1 -> V_452 = 0 ;
F_317 ( V_24 , NULL ) ;
F_278 ( V_1 ) ;
return - V_534 ;
}
static void F_320 ( struct V_475 * V_24 )
{
T_1 * V_1 ;
char * V_622 ;
int V_317 ;
V_1 = F_321 ( V_24 ) ;
V_622 = F_126 ( 4 , V_23 ) ;
if ( ! V_622 ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_201 ) ;
return;
}
V_317 = F_136 ( V_1 , V_342 , V_622 ,
4 , 0 , V_151 , V_282 ) ;
F_15 ( V_622 ) ;
if ( V_317 != V_283 )
F_153 ( & V_1 -> V_24 -> V_25 , L_202 ) ;
V_1 -> V_385 . V_617 ( V_1 , V_618 ) ;
F_306 ( V_1 -> V_50 [ V_1 -> V_51 ] , V_1 ) ;
}
static int F_274 ( struct V_100 * V_1 )
{
T_11 V_514 ;
V_514 = F_109 ( & ( V_1 -> V_202 -> V_471 ) ) ;
if ( ! ( V_514 & V_623 ) )
return - V_594 ;
V_1 -> V_442 = F_109 ( & ( V_1 -> V_202 -> V_474 ) ) ;
F_111 ( V_624 , & ( V_1 -> V_202 -> V_203 . V_473 ) ) ;
F_111 ( V_206 , V_1 -> V_207 + V_208 ) ;
F_238 ( V_1 ) ;
F_232 ( V_1 ) ;
if ( ! ( F_109 ( & ( V_1 -> V_202 -> V_472 ) ) & V_624 ) ) {
F_153 ( & V_1 -> V_24 -> V_25 , L_203 ) ;
return - V_534 ;
}
V_1 -> V_3 = V_624 ;
return 0 ;
}
static void F_322 ( struct V_475 * V_24 )
{
T_1 * V_1 ;
int V_20 , V_22 ;
if ( F_321 ( V_24 ) == NULL ) {
F_18 ( & V_24 -> V_25 , L_204 ) ;
return;
}
V_1 = F_321 ( V_24 ) ;
V_20 = V_1 -> V_62 ;
if ( V_266 [ V_20 ] == NULL ) {
F_18 ( & V_24 -> V_25 , L_205 ) ;
return;
}
F_91 ( & V_1 -> V_453 ) ;
F_224 ( V_1 ) ;
F_323 ( V_1 -> V_46 , V_89 ) ;
F_309 ( V_1 -> V_288 , V_1 -> V_46 ) ;
for ( V_22 = 0 ; V_22 < V_313 ; V_22 ++ ) {
struct V_140 * V_141 = V_1 -> V_140 [ V_22 ] ;
if ( V_141 ) {
struct V_326 * V_327 = V_141 -> V_142 ;
if ( V_141 -> V_13 & V_328 ) {
F_72 ( V_1 , V_22 , 1 ) ;
F_165 ( V_141 ) ;
}
if ( V_327 )
F_148 ( V_327 ) ;
}
}
#ifdef F_25
F_324 ( V_1 ) ;
#endif
F_320 ( V_24 ) ;
#ifdef F_245
if ( V_1 -> V_525 )
F_307 ( V_1 -> V_24 ) ;
else if ( V_1 -> V_527 )
F_308 ( V_1 -> V_24 ) ;
#endif
F_275 ( V_1 -> V_498 ) ;
F_275 ( V_1 -> V_202 ) ;
F_275 ( V_1 -> V_207 ) ;
F_299 ( V_1 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_19 ; V_22 ++ )
F_15 ( V_1 -> V_422 [ V_22 ] ) ;
F_15 ( V_1 -> V_422 ) ;
F_14 ( V_1 -> V_18 , V_1 -> V_19 ) ;
F_15 ( V_1 -> V_6 ) ;
if ( V_1 -> V_441 )
F_79 ( V_1 -> V_24 , V_1 -> V_442 * sizeof( V_137 ) ,
V_1 -> V_441 , V_1 -> V_511 ) ;
F_276 ( V_24 ) ;
F_317 ( V_24 , NULL ) ;
F_67 ( V_1 ) ;
F_92 ( & V_1 -> V_453 ) ;
F_278 ( V_1 ) ;
}
static int T_44 F_325 ( void )
{
int V_79 ;
F_241 ( sizeof( T_2 ) % V_625 ) ;
F_326 (KERN_INFO DRIVER_NAME L_206 ) ;
V_79 = F_327 ( & V_120 ) ;
if ( V_79 )
return V_79 ;
V_102 = F_328 ( F_228 , NULL , L_207 ) ;
if ( F_329 ( V_102 ) ) {
V_79 = F_330 ( V_102 ) ;
goto V_626;
}
V_79 = F_331 ( & V_627 ) ;
if ( V_79 )
goto V_628;
return V_79 ;
V_628:
F_332 ( V_102 ) ;
V_626:
F_333 ( & V_120 ) ;
return V_79 ;
}
static void T_45 F_334 ( void )
{
int V_20 ;
F_335 ( & V_627 ) ;
for ( V_20 = 0 ; V_20 < V_568 ; V_20 ++ ) {
if ( V_266 [ V_20 ] != NULL ) {
F_153 ( & V_266 [ V_20 ] -> V_24 -> V_25 ,
L_208 ) ;
F_322 ( V_266 [ V_20 ] -> V_24 ) ;
}
}
F_332 ( V_102 ) ;
if ( V_89 )
F_323 ( L_15 , NULL ) ;
F_333 ( & V_120 ) ;
}
