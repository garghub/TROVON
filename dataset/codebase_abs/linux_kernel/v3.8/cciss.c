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
V_44 -> V_45 = F_35 ( V_71 ) -> V_76 ;
return V_73 ;
}
static T_8
F_36 ( struct V_72 * V_72 , const char T_9 * V_77 ,
T_10 V_78 , T_5 * V_79 )
{
int V_80 ;
char * V_81 ;
#ifndef F_25
return - V_82 ;
#endif
if ( ! V_77 || V_78 > V_83 - 1 )
return - V_82 ;
V_81 = ( char * ) F_37 ( V_23 ) ;
if ( ! V_81 )
return - V_84 ;
V_80 = - V_85 ;
if ( F_38 ( V_81 , V_77 , V_78 ) )
goto V_86;
V_81 [ V_78 ] = '\0' ;
#ifdef F_25
if ( strncmp ( V_87 , V_81 , sizeof V_87 - 1 ) == 0 ) {
struct V_43 * V_44 = V_72 -> V_75 ;
T_1 * V_1 = V_44 -> V_45 ;
V_80 = F_39 ( V_1 ) ;
if ( V_80 == 0 )
V_80 = V_78 ;
} else
#endif
V_80 = - V_82 ;
V_86:
F_40 ( ( unsigned long ) V_81 ) ;
return V_80 ;
}
static void F_1 ( T_1 * V_1 )
{
struct V_88 * V_89 ;
if ( V_90 == NULL )
V_90 = F_41 ( L_15 , NULL ) ;
if ( ! V_90 )
return;
V_89 = F_42 ( V_1 -> V_46 , V_91 | V_92 | V_93 |
V_94 , V_90 ,
& V_95 , V_1 ) ;
}
static int F_43 ( T_11 V_48 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < F_44 ( V_96 ) ; V_20 ++ )
if ( V_96 [ V_20 ] == V_48 )
return 0 ;
return 1 ;
}
static int F_45 ( T_11 V_48 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < F_44 ( V_97 ) ; V_20 ++ )
if ( V_97 [ V_20 ] == V_48 )
return 0 ;
return 1 ;
}
static int F_46 ( T_11 V_48 )
{
return F_43 ( V_48 ) ||
F_45 ( V_48 ) ;
}
static T_8 F_47 ( struct V_98 * V_25 ,
struct V_99 * V_100 ,
char * V_77 )
{
struct V_101 * V_1 = F_48 ( V_25 ) ;
return snprintf ( V_77 , 20 , L_16 , F_46 ( V_1 -> V_48 ) ) ;
}
static T_8 F_49 ( struct V_98 * V_25 ,
struct V_99 * V_100 ,
const char * V_77 , T_10 V_102 )
{
struct V_101 * V_1 = F_48 ( V_25 ) ;
F_50 ( V_1 ) ;
F_51 ( V_103 ) ;
F_52 ( & V_1 -> V_104 ) ;
return V_102 ;
}
static T_8 F_53 ( struct V_98 * V_25 ,
struct V_99 * V_100 ,
char * V_77 )
{
struct V_101 * V_1 = F_48 ( V_25 ) ;
return snprintf ( V_77 , 20 , L_17 ,
V_1 -> V_3 & V_4 ?
L_18 : L_19 ) ;
}
static T_8 F_54 ( struct V_98 * V_25 ,
struct V_99 * V_100 ,
char * V_77 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_101 * V_1 = F_48 ( V_63 -> V_25 . V_105 ) ;
T_12 V_106 [ 16 ] ;
unsigned long V_13 ;
int V_73 = 0 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 )
V_73 = - V_58 ;
else
memcpy ( V_106 , V_63 -> V_107 , sizeof( V_106 ) ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_73 )
return V_73 ;
else
return snprintf ( V_77 , 16 * 2 + 2 ,
L_20
L_21 ,
V_106 [ 0 ] , V_106 [ 1 ] , V_106 [ 2 ] , V_106 [ 3 ] ,
V_106 [ 4 ] , V_106 [ 5 ] , V_106 [ 6 ] , V_106 [ 7 ] ,
V_106 [ 8 ] , V_106 [ 9 ] , V_106 [ 10 ] , V_106 [ 11 ] ,
V_106 [ 12 ] , V_106 [ 13 ] , V_106 [ 14 ] , V_106 [ 15 ] ) ;
}
static T_8 F_56 ( struct V_98 * V_25 ,
struct V_99 * V_100 ,
char * V_77 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_101 * V_1 = F_48 ( V_63 -> V_25 . V_105 ) ;
char V_108 [ V_109 + 1 ] ;
unsigned long V_13 ;
int V_73 = 0 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 )
V_73 = - V_58 ;
else
memcpy ( V_108 , V_63 -> V_108 , V_109 + 1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_73 )
return V_73 ;
else
return snprintf ( V_77 , sizeof( V_108 ) + 1 , L_17 , V_63 -> V_108 ) ;
}
static T_8 F_57 ( struct V_98 * V_25 ,
struct V_99 * V_100 ,
char * V_77 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_101 * V_1 = F_48 ( V_63 -> V_25 . V_105 ) ;
char V_110 [ V_111 + 1 ] ;
unsigned long V_13 ;
int V_73 = 0 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 )
V_73 = - V_58 ;
else
memcpy ( V_110 , V_63 -> V_110 , V_111 + 1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_73 )
return V_73 ;
else
return snprintf ( V_77 , sizeof( V_110 ) + 1 , L_17 , V_63 -> V_110 ) ;
}
static T_8 F_58 ( struct V_98 * V_25 ,
struct V_99 * V_100 ,
char * V_77 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_101 * V_1 = F_48 ( V_63 -> V_25 . V_105 ) ;
char V_112 [ V_113 + 1 ] ;
unsigned long V_13 ;
int V_73 = 0 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 )
V_73 = - V_58 ;
else
memcpy ( V_112 , V_63 -> V_112 , V_113 + 1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_73 )
return V_73 ;
else
return snprintf ( V_77 , sizeof( V_112 ) + 1 , L_17 , V_63 -> V_112 ) ;
}
static T_8 F_59 ( struct V_98 * V_25 ,
struct V_99 * V_100 , char * V_77 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_101 * V_1 = F_48 ( V_63 -> V_25 . V_105 ) ;
unsigned long V_13 ;
unsigned char V_114 [ 8 ] ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_58 ;
}
if ( ! V_63 -> V_65 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_115 ;
}
memcpy ( V_114 , V_63 -> V_116 , sizeof( V_114 ) ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
return snprintf ( V_77 , 20 , L_22 ,
V_114 [ 0 ] , V_114 [ 1 ] , V_114 [ 2 ] , V_114 [ 3 ] ,
V_114 [ 4 ] , V_114 [ 5 ] , V_114 [ 6 ] , V_114 [ 7 ] ) ;
}
static T_8 F_60 ( struct V_98 * V_25 ,
struct V_99 * V_100 , char * V_77 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_101 * V_1 = F_48 ( V_63 -> V_25 . V_105 ) ;
int V_117 ;
unsigned long V_13 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_58 ;
}
V_117 = V_63 -> V_68 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_117 < 0 || V_117 > V_69 )
V_117 = V_69 ;
return snprintf ( V_77 , strlen ( V_70 [ V_117 ] ) + 7 , L_23 ,
V_70 [ V_117 ] ) ;
}
static T_8 F_61 ( struct V_98 * V_25 ,
struct V_99 * V_100 , char * V_77 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_101 * V_1 = F_48 ( V_63 -> V_25 . V_105 ) ;
unsigned long V_13 ;
int V_102 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_58 ;
}
V_102 = V_63 -> V_118 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
return snprintf ( V_77 , 20 , L_16 , V_102 ) ;
}
static void F_62 ( struct V_98 * V_25 )
{
}
static int F_63 ( struct V_101 * V_1 )
{
F_64 ( & V_1 -> V_25 ) ;
V_1 -> V_25 . type = & V_119 ;
V_1 -> V_25 . V_120 = & V_121 ;
F_65 ( & V_1 -> V_25 , L_24 , V_1 -> V_46 ) ;
V_1 -> V_25 . V_105 = & V_1 -> V_24 -> V_25 ;
return F_66 ( & V_1 -> V_25 ) ;
}
static void F_67 ( struct V_101 * V_1 )
{
F_68 ( & V_1 -> V_25 ) ;
F_69 ( & V_1 -> V_25 ) ;
}
static void F_70 ( struct V_98 * V_25 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
F_15 ( V_63 ) ;
}
static long F_71 ( struct V_101 * V_1 ,
int V_122 )
{
struct V_98 * V_25 ;
if ( V_1 -> V_63 [ V_122 ] -> V_123 )
return 0 ;
V_25 = & V_1 -> V_63 [ V_122 ] -> V_25 ;
F_64 ( V_25 ) ;
V_25 -> type = & V_124 ;
V_25 -> V_120 = & V_121 ;
F_65 ( V_25 , L_25 , V_1 -> V_62 , V_122 ) ;
V_25 -> V_105 = & V_1 -> V_25 ;
V_1 -> V_63 [ V_122 ] -> V_123 = 1 ;
return F_66 ( V_25 ) ;
}
static void F_72 ( struct V_101 * V_1 , int V_122 ,
int V_125 )
{
struct V_98 * V_25 = & V_1 -> V_63 [ V_122 ] -> V_25 ;
if ( V_122 == 0 && ! V_125 )
return;
F_68 ( V_25 ) ;
F_69 ( V_25 ) ;
V_1 -> V_63 [ V_122 ] = NULL ;
}
static T_2 * F_73 ( T_1 * V_1 )
{
T_2 * V_2 ;
int V_20 ;
T_4 V_28 ;
T_13 V_126 , V_127 ;
do {
V_20 = F_74 ( V_1 -> V_128 , V_1 -> V_19 ) ;
if ( V_20 == V_1 -> V_19 )
return NULL ;
} while ( F_75 ( V_20 , V_1 -> V_128 ) != 0 );
V_2 = V_1 -> V_129 + V_20 ;
memset ( V_2 , 0 , sizeof( T_2 ) ) ;
V_126 = V_1 -> V_130 + V_20 * sizeof( T_2 ) ;
V_2 -> V_131 = V_1 -> V_132 + V_20 ;
memset ( V_2 -> V_131 , 0 , sizeof( V_133 ) ) ;
V_127 = V_1 -> V_134
+ V_20 * sizeof( V_133 ) ;
V_1 -> V_135 ++ ;
V_2 -> V_136 = V_20 ;
F_76 ( & V_2 -> V_10 ) ;
V_2 -> V_5 = ( V_137 ) V_126 ;
V_28 . V_36 = ( V_138 ) V_127 ;
V_2 -> V_139 . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_139 . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_139 . V_37 = sizeof( V_133 ) ;
V_2 -> V_62 = V_1 -> V_62 ;
return V_2 ;
}
static T_2 * F_77 ( T_1 * V_1 )
{
T_2 * V_2 ;
T_4 V_28 ;
T_13 V_126 , V_127 ;
V_2 = ( T_2 * ) F_78 ( V_1 -> V_24 ,
sizeof( T_2 ) , & V_126 ) ;
if ( V_2 == NULL )
return NULL ;
memset ( V_2 , 0 , sizeof( T_2 ) ) ;
V_2 -> V_136 = - 1 ;
V_2 -> V_131 = ( V_133 * )
F_78 ( V_1 -> V_24 , sizeof( V_133 ) ,
& V_127 ) ;
if ( V_2 -> V_131 == NULL ) {
F_79 ( V_1 -> V_24 ,
sizeof( T_2 ) , V_2 , V_126 ) ;
return NULL ;
}
memset ( V_2 -> V_131 , 0 , sizeof( V_133 ) ) ;
F_76 ( & V_2 -> V_10 ) ;
V_2 -> V_5 = ( V_137 ) V_126 ;
V_28 . V_36 = ( V_138 ) V_127 ;
V_2 -> V_139 . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_139 . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_139 . V_37 = sizeof( V_133 ) ;
V_2 -> V_62 = V_1 -> V_62 ;
return V_2 ;
}
static void F_80 ( T_1 * V_1 , T_2 * V_2 )
{
int V_20 ;
V_20 = V_2 - V_1 -> V_129 ;
F_81 ( V_20 , V_1 -> V_128 ) ;
V_1 -> V_140 ++ ;
}
static void F_82 ( T_1 * V_1 , T_2 * V_2 )
{
T_4 V_28 ;
V_28 . V_32 . V_33 = V_2 -> V_139 . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_2 -> V_139 . V_34 . V_35 ;
F_79 ( V_1 -> V_24 , sizeof( V_133 ) ,
V_2 -> V_131 , ( T_13 ) V_28 . V_36 ) ;
F_79 ( V_1 -> V_24 , sizeof( T_2 ) , V_2 ,
( T_13 ) F_83 ( V_1 , ( T_11 ) V_2 -> V_5 ) ) ;
}
static inline T_1 * F_84 ( struct V_141 * V_142 )
{
return V_142 -> V_143 -> V_144 ;
}
static inline T_7 * F_85 ( struct V_141 * V_142 )
{
return V_142 -> V_75 ;
}
static int F_86 ( struct V_145 * V_146 , T_14 V_147 )
{
T_1 * V_1 = F_84 ( V_146 -> V_148 ) ;
T_7 * V_63 = F_85 ( V_146 -> V_148 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_26 , V_146 -> V_148 -> V_149 ) ;
if ( V_63 -> V_57 )
return - V_58 ;
if ( V_63 -> V_65 == 0 ) {
if ( F_88 ( V_146 -> V_150 ) != 0 ) {
if ( F_88 ( V_146 -> V_150 ) & 0x0f ) {
return - V_151 ;
} else if ( memcmp ( V_63 -> V_116 , V_152 ,
sizeof( V_63 -> V_116 ) ) ) {
return - V_151 ;
}
}
if ( ! F_89 ( V_153 ) )
return - V_154 ;
}
V_63 -> V_118 ++ ;
V_1 -> V_118 ++ ;
return 0 ;
}
static int F_90 ( struct V_145 * V_146 , T_14 V_147 )
{
int V_73 ;
F_91 ( & V_155 ) ;
V_73 = F_86 ( V_146 , V_147 ) ;
F_92 ( & V_155 ) ;
return V_73 ;
}
static int F_93 ( struct V_141 * V_142 , T_14 V_147 )
{
T_1 * V_1 ;
T_7 * V_63 ;
F_91 ( & V_155 ) ;
V_1 = F_84 ( V_142 ) ;
V_63 = F_85 ( V_142 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_27 , V_142 -> V_149 ) ;
V_63 -> V_118 -- ;
V_1 -> V_118 -- ;
F_92 ( & V_155 ) ;
return 0 ;
}
static int F_94 ( struct V_145 * V_146 , T_14 V_147 ,
unsigned V_156 , unsigned long V_157 )
{
int V_73 ;
F_91 ( & V_155 ) ;
V_73 = F_95 ( V_146 , V_147 , V_156 , V_157 ) ;
F_92 ( & V_155 ) ;
return V_73 ;
}
static int F_96 ( struct V_145 * V_146 , T_14 V_147 ,
unsigned V_156 , unsigned long V_157 )
{
switch ( V_156 ) {
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
case V_172 :
return F_94 ( V_146 , V_147 , V_156 , V_157 ) ;
case V_173 :
return F_97 ( V_146 , V_147 , V_156 , V_157 ) ;
case V_174 :
return F_98 ( V_146 , V_147 , V_156 , V_157 ) ;
default:
return - V_175 ;
}
}
static int F_97 ( struct V_145 * V_146 , T_14 V_147 ,
unsigned V_156 , unsigned long V_157 )
{
T_15 T_9 * V_176 =
( T_15 T_9 * ) V_157 ;
T_16 V_177 ;
T_16 T_9 * V_178 = F_99 ( sizeof( V_177 ) ) ;
int V_80 ;
T_11 V_179 ;
V_80 = 0 ;
V_80 |=
F_38 ( & V_177 . V_180 , & V_176 -> V_180 ,
sizeof( V_177 . V_180 ) ) ;
V_80 |=
F_38 ( & V_177 . V_181 , & V_176 -> V_181 ,
sizeof( V_177 . V_181 ) ) ;
V_80 |=
F_38 ( & V_177 . V_182 , & V_176 -> V_182 ,
sizeof( V_177 . V_182 ) ) ;
V_80 |= F_100 ( V_177 . V_183 , & V_176 -> V_183 ) ;
V_80 |= F_100 ( V_179 , & V_176 -> V_77 ) ;
V_177 . V_77 = F_101 ( V_179 ) ;
V_80 |= F_102 ( V_178 , & V_177 , sizeof( V_177 ) ) ;
if ( V_80 )
return - V_85 ;
V_80 = F_94 ( V_146 , V_147 , V_184 , ( unsigned long ) V_178 ) ;
if ( V_80 )
return V_80 ;
V_80 |=
F_103 ( & V_176 -> V_182 , & V_178 -> V_182 ,
sizeof( V_176 -> V_182 ) ) ;
if ( V_80 )
return - V_85 ;
return V_80 ;
}
static int F_98 ( struct V_145 * V_146 , T_14 V_147 ,
unsigned V_156 , unsigned long V_157 )
{
T_17 T_9 * V_176 =
( T_17 T_9 * ) V_157 ;
T_18 V_177 ;
T_18 T_9 * V_178 =
F_99 ( sizeof( V_177 ) ) ;
int V_80 ;
T_11 V_179 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_80 = 0 ;
V_80 |=
F_38 ( & V_177 . V_180 , & V_176 -> V_180 ,
sizeof( V_177 . V_180 ) ) ;
V_80 |=
F_38 ( & V_177 . V_181 , & V_176 -> V_181 ,
sizeof( V_177 . V_181 ) ) ;
V_80 |=
F_38 ( & V_177 . V_182 , & V_176 -> V_182 ,
sizeof( V_177 . V_182 ) ) ;
V_80 |= F_100 ( V_177 . V_183 , & V_176 -> V_183 ) ;
V_80 |= F_100 ( V_177 . V_185 , & V_176 -> V_185 ) ;
V_80 |= F_100 ( V_179 , & V_176 -> V_77 ) ;
V_177 . V_77 = F_101 ( V_179 ) ;
V_80 |= F_102 ( V_178 , & V_177 , sizeof( V_177 ) ) ;
if ( V_80 )
return - V_85 ;
V_80 = F_94 ( V_146 , V_147 , V_186 , ( unsigned long ) V_178 ) ;
if ( V_80 )
return V_80 ;
V_80 |=
F_103 ( & V_176 -> V_182 , & V_178 -> V_182 ,
sizeof( V_176 -> V_182 ) ) ;
if ( V_80 )
return - V_85 ;
return V_80 ;
}
static int F_104 ( struct V_145 * V_146 , struct V_187 * V_188 )
{
T_7 * V_63 = F_85 ( V_146 -> V_148 ) ;
if ( ! V_63 -> V_189 )
return - V_151 ;
V_188 -> V_65 = V_63 -> V_65 ;
V_188 -> V_190 = V_63 -> V_190 ;
V_188 -> V_189 = V_63 -> V_189 ;
return 0 ;
}
static void F_105 ( T_1 * V_1 , T_2 * V_2 )
{
if ( V_2 -> V_131 -> V_191 == V_192 &&
V_2 -> V_131 -> V_193 != V_194 )
( void ) F_106 ( V_1 , V_2 ) ;
}
static int F_107 ( T_1 * V_1 , void T_9 * V_195 )
{
T_19 V_196 ;
if ( ! V_195 )
return - V_82 ;
V_196 . V_197 = F_108 ( V_1 -> V_24 -> V_120 ) ;
V_196 . V_120 = V_1 -> V_24 -> V_120 -> V_198 ;
V_196 . V_199 = V_1 -> V_24 -> V_200 ;
V_196 . V_48 = V_1 -> V_48 ;
if ( F_102 ( V_195 , & V_196 , sizeof( T_19 ) ) )
return - V_85 ;
return 0 ;
}
static int F_109 ( T_1 * V_1 , void T_9 * V_195 )
{
T_20 V_201 ;
if ( ! V_195 )
return - V_82 ;
V_201 . V_202 = F_110 ( & V_1 -> V_203 -> V_204 . V_205 ) ;
V_201 . V_102 = F_110 ( & V_1 -> V_203 -> V_204 . V_206 ) ;
if ( F_102
( V_195 , & V_201 , sizeof( T_20 ) ) )
return - V_85 ;
return 0 ;
}
static int F_111 ( T_1 * V_1 , void T_9 * V_195 )
{
T_20 V_201 ;
unsigned long V_13 ;
int V_20 ;
if ( ! V_195 )
return - V_82 ;
if ( ! F_89 ( V_153 ) )
return - V_154 ;
if ( F_38 ( & V_201 , V_195 , sizeof( V_201 ) ) )
return - V_85 ;
if ( ( V_201 . V_202 == 0 ) && ( V_201 . V_102 == 0 ) )
return - V_82 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
F_112 ( V_201 . V_202 , & ( V_1 -> V_203 -> V_204 . V_205 ) ) ;
F_112 ( V_201 . V_102 , & ( V_1 -> V_203 -> V_204 . V_206 ) ) ;
F_112 ( V_207 , V_1 -> V_208 + V_209 ) ;
for ( V_20 = 0 ; V_20 < V_210 ; V_20 ++ ) {
if ( ! ( F_110 ( V_1 -> V_208 + V_209 ) & V_207 ) )
break;
F_113 ( 1000 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_20 >= V_210 )
return - V_211 ;
return 0 ;
}
static int F_114 ( T_1 * V_1 , void T_9 * V_195 )
{
T_21 V_212 ;
int V_20 ;
if ( ! V_195 )
return - V_82 ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
V_212 [ V_20 ] = F_115 ( & V_1 -> V_203 -> V_213 [ V_20 ] ) ;
if ( F_102 ( V_195 , V_212 , sizeof( T_21 ) ) )
return - V_85 ;
return 0 ;
}
static int F_116 ( T_1 * V_1 , void T_9 * V_195 )
{
T_21 V_212 ;
unsigned long V_13 ;
int V_20 ;
if ( ! V_195 )
return - V_82 ;
if ( ! F_89 ( V_153 ) )
return - V_154 ;
if ( F_38 ( V_212 , V_195 , sizeof( T_21 ) ) )
return - V_85 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
F_117 ( V_212 [ V_20 ] , & V_1 -> V_203 -> V_213 [ V_20 ] ) ;
F_112 ( V_207 , V_1 -> V_208 + V_209 ) ;
for ( V_20 = 0 ; V_20 < V_210 ; V_20 ++ ) {
if ( ! ( F_110 ( V_1 -> V_208 + V_209 ) & V_207 ) )
break;
F_113 ( 1000 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_20 >= V_210 )
return - V_211 ;
return 0 ;
}
static int F_118 ( T_1 * V_1 , void T_9 * V_195 )
{
T_22 V_214 ;
if ( ! V_195 )
return - V_82 ;
V_214 = F_110 ( & V_1 -> V_203 -> V_215 ) ;
if ( F_102 ( V_195 , & V_214 , sizeof( T_22 ) ) )
return - V_85 ;
return 0 ;
}
static int F_119 ( T_1 * V_1 , void T_9 * V_195 )
{
T_23 V_216 ;
if ( ! V_195 )
return - V_82 ;
V_216 = F_110 ( & V_1 -> V_203 -> V_216 ) ;
if ( F_102 ( V_195 , & V_216 , sizeof( T_23 ) ) )
return - V_85 ;
return 0 ;
}
static int F_120 ( T_1 * V_1 , void T_9 * V_195 )
{
T_24 V_217 ;
if ( ! V_195 )
return - V_82 ;
memcpy ( V_217 , V_1 -> V_49 , 4 ) ;
if ( F_102
( V_195 , V_217 , sizeof( T_24 ) ) )
return - V_85 ;
return 0 ;
}
static int F_121 ( T_1 * V_1 , void T_9 * V_195 )
{
T_25 V_218 = V_219 ;
if ( ! V_195 )
return - V_82 ;
if ( F_102 ( V_195 , & V_218 , sizeof( T_25 ) ) )
return - V_85 ;
return 0 ;
}
static int F_122 ( T_1 * V_1 ,
struct V_141 * V_142 , void T_9 * V_195 )
{
T_26 V_220 ;
T_7 * V_63 = F_85 ( V_142 ) ;
if ( ! V_195 )
return - V_82 ;
memcpy ( & V_220 . V_116 , V_63 -> V_116 , sizeof( V_220 . V_116 ) ) ;
V_220 . V_221 = V_63 -> V_118 ;
V_220 . V_222 = 0 ;
if ( F_102 ( V_195 , & V_220 , sizeof( T_26 ) ) )
return - V_85 ;
return 0 ;
}
static int F_123 ( T_1 * V_1 , void T_9 * V_195 )
{
T_16 V_223 ;
T_2 * V_2 ;
char * V_224 = NULL ;
T_4 V_28 ;
F_124 ( V_225 ) ;
if ( ! V_195 )
return - V_82 ;
if ( ! F_89 ( V_226 ) )
return - V_154 ;
if ( F_38
( & V_223 , V_195 , sizeof( T_16 ) ) )
return - V_85 ;
if ( ( V_223 . V_183 < 1 ) &&
( V_223 . V_181 . Type . V_227 != V_228 ) ) {
return - V_82 ;
}
if ( V_223 . V_183 > 0 ) {
V_224 = F_17 ( V_223 . V_183 , V_23 ) ;
if ( V_224 == NULL )
return - V_85 ;
}
if ( V_223 . V_181 . Type . V_227 == V_229 ) {
if ( F_38 ( V_224 , V_223 . V_77 , V_223 . V_183 ) ) {
F_15 ( V_224 ) ;
return - V_85 ;
}
} else {
memset ( V_224 , 0 , V_223 . V_183 ) ;
}
V_2 = F_77 ( V_1 ) ;
if ( ! V_2 ) {
F_15 ( V_224 ) ;
return - V_84 ;
}
V_2 -> V_11 = V_230 ;
V_2 -> V_7 . V_231 = 0 ;
if ( V_223 . V_183 > 0 ) {
V_2 -> V_7 . V_8 = 1 ;
V_2 -> V_7 . V_29 = 1 ;
} else {
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_7 . V_29 = 0 ;
}
V_2 -> V_7 . V_232 = V_223 . V_180 ;
V_2 -> V_7 . V_233 . V_33 = V_2 -> V_5 ;
V_2 -> V_181 = V_223 . V_181 ;
if ( V_223 . V_183 > 0 ) {
V_28 . V_36 = F_22 ( V_1 -> V_24 , V_224 ,
V_223 . V_183 , V_234 ) ;
V_2 -> V_31 [ 0 ] . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_31 [ 0 ] . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_31 [ 0 ] . V_37 = V_223 . V_183 ;
V_2 -> V_31 [ 0 ] . V_41 = 0 ;
}
V_2 -> V_235 = & V_225 ;
F_10 ( V_1 , V_2 ) ;
F_125 ( & V_225 ) ;
V_28 . V_32 . V_33 = V_2 -> V_31 [ 0 ] . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_2 -> V_31 [ 0 ] . V_34 . V_35 ;
F_20 ( V_1 -> V_24 , ( T_13 ) V_28 . V_36 , V_223 . V_183 ,
V_234 ) ;
F_105 ( V_1 , V_2 ) ;
V_223 . V_182 = * ( V_2 -> V_131 ) ;
if ( F_102 ( V_195 , & V_223 , sizeof( T_16 ) ) ) {
F_15 ( V_224 ) ;
F_82 ( V_1 , V_2 ) ;
return - V_85 ;
}
if ( V_223 . V_181 . Type . V_227 == V_236 ) {
if ( F_102 ( V_223 . V_77 , V_224 , V_223 . V_183 ) ) {
F_15 ( V_224 ) ;
F_82 ( V_1 , V_2 ) ;
return - V_85 ;
}
}
F_15 ( V_224 ) ;
F_82 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_126 ( T_1 * V_1 , void T_9 * V_195 )
{
T_18 * V_237 ;
T_2 * V_2 ;
unsigned char * * V_224 = NULL ;
int * V_238 = NULL ;
T_4 V_28 ;
T_27 V_239 = 0 ;
int V_240 = 0 ;
int V_20 ;
F_124 ( V_225 ) ;
V_137 V_241 ;
V_137 V_242 ;
T_27 T_9 * V_243 ;
if ( ! V_195 )
return - V_82 ;
if ( ! F_89 ( V_226 ) )
return - V_154 ;
V_237 = F_17 ( sizeof( * V_237 ) , V_23 ) ;
if ( ! V_237 ) {
V_240 = - V_84 ;
goto V_244;
}
if ( F_38 ( V_237 , V_195 , sizeof( * V_237 ) ) ) {
V_240 = - V_85 ;
goto V_244;
}
if ( ( V_237 -> V_183 < 1 ) &&
( V_237 -> V_181 . Type . V_227 != V_228 ) ) {
V_240 = - V_82 ;
goto V_244;
}
if ( V_237 -> V_185 > V_245 ) {
V_240 = - V_82 ;
goto V_244;
}
if ( V_237 -> V_183 > V_237 -> V_185 * V_246 ) {
V_240 = - V_82 ;
goto V_244;
}
V_224 = F_127 ( V_246 * sizeof( char * ) , V_23 ) ;
if ( ! V_224 ) {
V_240 = - V_84 ;
goto V_244;
}
V_238 = F_17 ( V_246 * sizeof( int ) , V_23 ) ;
if ( ! V_238 ) {
V_240 = - V_84 ;
goto V_244;
}
V_241 = V_237 -> V_183 ;
V_243 = V_237 -> V_77 ;
while ( V_241 ) {
V_242 = ( V_241 > V_237 -> V_185 ) ? V_237 -> V_185 : V_241 ;
V_238 [ V_239 ] = V_242 ;
V_224 [ V_239 ] = F_17 ( V_242 , V_23 ) ;
if ( V_224 [ V_239 ] == NULL ) {
V_240 = - V_84 ;
goto V_244;
}
if ( V_237 -> V_181 . Type . V_227 == V_229 ) {
if ( F_38 ( V_224 [ V_239 ] , V_243 , V_242 ) ) {
V_240 = - V_85 ;
goto V_244;
}
} else {
memset ( V_224 [ V_239 ] , 0 , V_242 ) ;
}
V_241 -= V_242 ;
V_243 += V_242 ;
V_239 ++ ;
}
V_2 = F_77 ( V_1 ) ;
if ( ! V_2 ) {
V_240 = - V_84 ;
goto V_244;
}
V_2 -> V_11 = V_230 ;
V_2 -> V_7 . V_231 = 0 ;
V_2 -> V_7 . V_8 = V_239 ;
V_2 -> V_7 . V_29 = V_239 ;
V_2 -> V_7 . V_232 = V_237 -> V_180 ;
V_2 -> V_7 . V_233 . V_33 = V_2 -> V_5 ;
V_2 -> V_181 = V_237 -> V_181 ;
for ( V_20 = 0 ; V_20 < V_239 ; V_20 ++ ) {
V_28 . V_36 = F_22 ( V_1 -> V_24 , V_224 [ V_20 ] , V_238 [ V_20 ] ,
V_234 ) ;
V_2 -> V_31 [ V_20 ] . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_31 [ V_20 ] . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_31 [ V_20 ] . V_37 = V_238 [ V_20 ] ;
V_2 -> V_31 [ V_20 ] . V_41 = 0 ;
}
V_2 -> V_235 = & V_225 ;
F_10 ( V_1 , V_2 ) ;
F_125 ( & V_225 ) ;
for ( V_20 = 0 ; V_20 < V_239 ; V_20 ++ ) {
V_28 . V_32 . V_33 = V_2 -> V_31 [ V_20 ] . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_2 -> V_31 [ V_20 ] . V_34 . V_35 ;
F_20 ( V_1 -> V_24 ,
( T_13 ) V_28 . V_36 , V_238 [ V_20 ] ,
V_234 ) ;
}
F_105 ( V_1 , V_2 ) ;
V_237 -> V_182 = * ( V_2 -> V_131 ) ;
if ( F_102 ( V_195 , V_237 , sizeof( * V_237 ) ) ) {
F_82 ( V_1 , V_2 ) ;
V_240 = - V_85 ;
goto V_244;
}
if ( V_237 -> V_181 . Type . V_227 == V_236 ) {
T_27 T_9 * V_247 = V_237 -> V_77 ;
for ( V_20 = 0 ; V_20 < V_239 ; V_20 ++ ) {
if ( F_102 ( V_247 , V_224 [ V_20 ] , V_238 [ V_20 ] ) ) {
F_82 ( V_1 , V_2 ) ;
V_240 = - V_85 ;
goto V_244;
}
V_247 += V_238 [ V_20 ] ;
}
}
F_82 ( V_1 , V_2 ) ;
V_240 = 0 ;
V_244:
if ( V_224 ) {
for ( V_20 = 0 ; V_20 < V_239 ; V_20 ++ )
F_15 ( V_224 [ V_20 ] ) ;
F_15 ( V_224 ) ;
}
F_15 ( V_238 ) ;
F_15 ( V_237 ) ;
return V_240 ;
}
static int F_95 ( struct V_145 * V_146 , T_14 V_147 ,
unsigned int V_156 , unsigned long V_157 )
{
struct V_141 * V_142 = V_146 -> V_148 ;
T_1 * V_1 = F_84 ( V_142 ) ;
void T_9 * V_195 = ( void T_9 * ) V_157 ;
F_87 ( & V_1 -> V_24 -> V_25 , L_28 ,
V_156 , V_157 ) ;
switch ( V_156 ) {
case V_158 :
return F_107 ( V_1 , V_195 ) ;
case V_159 :
return F_109 ( V_1 , V_195 ) ;
case V_160 :
return F_111 ( V_1 , V_195 ) ;
case V_161 :
return F_114 ( V_1 , V_195 ) ;
case V_162 :
return F_116 ( V_1 , V_195 ) ;
case V_163 :
return F_118 ( V_1 , V_195 ) ;
case V_164 :
return F_119 ( V_1 , V_195 ) ;
case V_165 :
return F_120 ( V_1 , V_195 ) ;
case V_166 :
return F_121 ( V_1 , V_195 ) ;
case V_168 :
case V_170 :
case V_167 :
return F_128 ( V_1 , 0 , 1 ) ;
case V_172 :
return F_122 ( V_1 , V_142 , V_195 ) ;
case V_184 :
return F_123 ( V_1 , V_195 ) ;
case V_186 :
return F_126 ( V_1 , V_195 ) ;
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
return F_129 ( V_146 , V_147 , V_156 , V_195 ) ;
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
default:
return - V_115 ;
}
}
static void F_130 ( T_1 * V_1 )
{
int V_261 = V_1 -> V_262 ;
int V_20 ;
if ( ( F_74 ( V_1 -> V_128 , V_1 -> V_19 ) ) == V_1 -> V_19 )
return;
for ( V_20 = 0 ; V_20 < V_1 -> V_64 + 1 ; V_20 ++ ) {
int V_263 = ( V_261 + V_20 ) % ( V_1 -> V_64 + 1 ) ;
if ( ! V_1 -> V_63 [ V_263 ] )
continue;
if ( ! ( V_1 -> V_63 [ V_263 ] -> V_143 ) ||
! ( V_1 -> V_63 [ V_263 ] -> V_65 ) )
continue;
F_131 ( V_1 -> V_141 [ V_263 ] -> V_143 ) ;
if ( ( F_74 ( V_1 -> V_128 , V_1 -> V_19 ) ) == V_1 -> V_19 ) {
if ( V_263 == V_261 ) {
V_1 -> V_262 =
( V_261 + 1 ) % ( V_1 -> V_64 + 1 ) ;
break;
} else {
V_1 -> V_262 = V_263 ;
break;
}
}
}
}
static void F_132 ( struct V_264 * V_265 )
{
T_2 * V_2 = V_265 -> V_266 ;
T_1 * V_1 = V_267 [ V_2 -> V_62 ] ;
T_3 * V_268 = V_2 -> V_31 ;
T_4 V_28 ;
unsigned long V_13 ;
int V_20 , V_269 ;
int V_270 = 0 ;
if ( V_2 -> V_181 . Type . V_227 == V_236 )
V_269 = V_271 ;
else
V_269 = V_38 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_7 . V_8 ; V_20 ++ ) {
if ( V_268 [ V_270 ] . V_41 == V_42 ) {
F_19 ( V_1 , V_2 ) ;
V_268 = V_1 -> V_18 [ V_2 -> V_136 ] ;
V_270 = 0 ;
}
V_28 . V_32 . V_33 = V_268 [ V_270 ] . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_268 [ V_270 ] . V_34 . V_35 ;
F_133 ( V_1 -> V_24 , V_28 . V_36 , V_268 [ V_270 ] . V_37 ,
V_269 ) ;
++ V_270 ;
}
F_87 ( & V_1 -> V_24 -> V_25 , L_29 , V_265 ) ;
if ( V_265 -> V_11 == V_272 )
V_265 -> V_273 = V_2 -> V_131 -> V_274 ;
F_134 ( V_265 , ( V_265 -> V_275 == 0 ) ? 0 : - V_276 ) ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
F_80 ( V_1 , V_2 ) ;
F_130 ( V_1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
}
static inline void F_135 ( T_1 * V_1 ,
unsigned char V_277 [] , T_28 V_278 )
{
memcpy ( V_277 , V_1 -> V_63 [ V_278 ] -> V_116 ,
sizeof( V_1 -> V_63 [ V_278 ] -> V_116 ) ) ;
}
static void F_136 ( T_1 * V_1 , int V_279 ,
char * V_108 , char * V_110 , char * V_112 )
{
int V_280 ;
T_29 * V_281 ;
unsigned char V_277 [ 8 ] ;
* V_108 = '\0' ;
* V_110 = '\0' ;
* V_112 = '\0' ;
V_281 = F_127 ( sizeof( T_29 ) , V_23 ) ;
if ( ! V_281 )
return;
F_135 ( V_1 , V_277 , V_279 ) ;
V_280 = F_137 ( V_1 , V_282 , V_281 , sizeof( * V_281 ) , 0 ,
V_277 , V_283 ) ;
if ( V_280 == V_284 ) {
memcpy ( V_108 , & V_281 -> V_285 [ 8 ] , V_109 ) ;
V_108 [ V_109 ] = '\0' ;
memcpy ( V_110 , & V_281 -> V_285 [ 16 ] , V_111 ) ;
V_110 [ V_111 ] = '\0' ;
memcpy ( V_112 , & V_281 -> V_285 [ 32 ] , V_113 ) ;
V_112 [ V_113 ] = '\0' ;
}
F_15 ( V_281 ) ;
return;
}
static void F_138 ( T_1 * V_1 , int V_279 ,
unsigned char * V_107 , int V_286 )
{
#define F_139 64
int V_280 ;
unsigned char * V_77 ;
unsigned char V_277 [ 8 ] ;
if ( V_286 > 16 )
V_286 = 16 ;
memset ( V_107 , 0xff , V_286 ) ;
V_77 = F_127 ( F_139 , V_23 ) ;
if ( ! V_77 )
return;
memset ( V_107 , 0 , V_286 ) ;
F_135 ( V_1 , V_277 , V_279 ) ;
V_280 = F_137 ( V_1 , V_282 , V_77 ,
F_139 , 0x83 , V_277 , V_283 ) ;
if ( V_280 == V_284 )
memcpy ( V_107 , & V_77 [ 8 ] , V_286 ) ;
F_15 ( V_77 ) ;
return;
}
static int F_140 ( T_1 * V_1 , struct V_141 * V_142 ,
int V_122 )
{
V_142 -> V_143 = F_141 ( V_287 , & V_1 -> V_14 ) ;
if ( ! V_142 -> V_143 )
goto V_288;
sprintf ( V_142 -> V_149 , L_30 , V_1 -> V_62 , V_122 ) ;
V_142 -> V_289 = V_1 -> V_289 ;
V_142 -> V_290 = V_122 << V_291 ;
V_142 -> V_292 = & V_293 ;
if ( F_71 ( V_1 , V_122 ) )
goto V_294;
V_142 -> V_75 = V_1 -> V_63 [ V_122 ] ;
V_142 -> V_295 = & V_1 -> V_63 [ V_122 ] -> V_25 ;
F_142 ( V_142 -> V_143 , V_1 -> V_24 -> V_296 ) ;
F_143 ( V_142 -> V_143 , V_1 -> V_297 ) ;
F_144 ( V_142 -> V_143 , V_1 -> V_298 ) ;
F_145 ( V_142 -> V_143 , F_132 ) ;
V_142 -> V_143 -> V_144 = V_1 ;
F_146 ( V_142 -> V_143 ,
V_1 -> V_63 [ V_122 ] -> V_299 ) ;
F_147 () ;
V_1 -> V_63 [ V_122 ] -> V_143 = V_142 -> V_143 ;
F_148 ( V_142 ) ;
return 0 ;
V_294:
F_149 ( V_142 -> V_143 ) ;
V_142 -> V_143 = NULL ;
V_288:
return - 1 ;
}
static void F_150 ( T_1 * V_1 , int V_122 ,
int V_300 , int V_301 )
{
struct V_141 * V_142 ;
T_29 * V_302 = NULL ;
unsigned int V_299 ;
T_6 V_303 ;
unsigned long V_13 = 0 ;
int V_73 = 0 ;
T_7 * V_304 ;
V_302 = F_17 ( sizeof( T_29 ) , V_23 ) ;
V_304 = F_127 ( sizeof( * V_304 ) , V_23 ) ;
if ( V_302 == NULL || V_304 == NULL )
goto V_305;
if ( V_1 -> V_306 == V_307 ) {
F_151 ( V_1 , V_122 ,
& V_303 , & V_299 ) ;
} else {
F_152 ( V_1 , V_122 , & V_303 , & V_299 ) ;
if ( V_303 == 0xFFFFFFFFULL ) {
F_151 ( V_1 , V_122 ,
& V_303 , & V_299 ) ;
V_1 -> V_306 = V_307 ;
V_1 -> V_308 = V_309 ;
} else {
V_1 -> V_306 = V_310 ;
V_1 -> V_308 = V_311 ;
}
}
F_153 ( V_1 , V_122 , V_303 , V_299 ,
V_302 , V_304 ) ;
V_304 -> V_299 = V_299 ;
V_304 -> V_66 = V_303 + 1 ;
F_136 ( V_1 , V_122 , V_304 -> V_108 ,
V_304 -> V_110 , V_304 -> V_112 ) ;
F_138 ( V_1 , V_122 , V_304 -> V_107 ,
sizeof( V_304 -> V_107 ) ) ;
memcpy ( V_304 -> V_116 , V_1 -> V_63 [ V_122 ] -> V_116 ,
sizeof( V_304 -> V_116 ) ) ;
if ( V_1 -> V_63 [ V_122 ] -> V_68 != - 1 &&
( ( memcmp ( V_304 -> V_107 ,
V_1 -> V_63 [ V_122 ] -> V_107 , 16 ) == 0 ) &&
V_304 -> V_299 == V_1 -> V_63 [ V_122 ] -> V_299 &&
V_304 -> V_66 == V_1 -> V_63 [ V_122 ] -> V_66 &&
V_304 -> V_65 == V_1 -> V_63 [ V_122 ] -> V_65 &&
V_304 -> V_190 == V_1 -> V_63 [ V_122 ] -> V_190 &&
V_304 -> V_189 == V_1 -> V_63 [ V_122 ] -> V_189 ) )
goto V_312;
if ( V_1 -> V_63 [ V_122 ] -> V_68 != - 1 && V_122 != 0 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_31 , V_122 ) ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_1 -> V_63 [ V_122 ] -> V_57 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
V_73 = F_155 ( V_1 , V_122 , 0 , V_301 ) ;
}
if ( V_73 )
goto V_312;
if ( V_1 -> V_63 [ V_122 ] == NULL ) {
V_304 -> V_123 = 0 ;
V_1 -> V_63 [ V_122 ] = V_304 ;
V_304 = NULL ;
} else {
V_1 -> V_63 [ V_122 ] -> V_299 = V_304 -> V_299 ;
V_1 -> V_63 [ V_122 ] -> V_66 = V_304 -> V_66 ;
V_1 -> V_63 [ V_122 ] -> V_65 = V_304 -> V_65 ;
V_1 -> V_63 [ V_122 ] -> V_190 = V_304 -> V_190 ;
V_1 -> V_63 [ V_122 ] -> V_189 = V_304 -> V_189 ;
V_1 -> V_63 [ V_122 ] -> V_68 = V_304 -> V_68 ;
memcpy ( V_1 -> V_63 [ V_122 ] -> V_107 , V_304 -> V_107 , 16 ) ;
memcpy ( V_1 -> V_63 [ V_122 ] -> V_108 , V_304 -> V_108 ,
V_109 + 1 ) ;
memcpy ( V_1 -> V_63 [ V_122 ] -> V_110 , V_304 -> V_110 , V_111 + 1 ) ;
memcpy ( V_1 -> V_63 [ V_122 ] -> V_112 , V_304 -> V_112 , V_113 + 1 ) ;
}
++ V_1 -> V_52 ;
V_142 = V_1 -> V_141 [ V_122 ] ;
F_156 ( V_142 , V_1 -> V_63 [ V_122 ] -> V_66 ) ;
if ( V_122 || V_300 ) {
if ( F_140 ( V_1 , V_142 , V_122 ) != 0 ) {
F_157 ( V_1 , V_122 ) ;
F_158 ( V_1 , V_122 ) ;
F_154 ( & V_1 -> V_24 -> V_25 , L_32 ,
V_122 ) ;
-- V_1 -> V_52 ;
}
}
V_312:
F_15 ( V_302 ) ;
F_15 ( V_304 ) ;
return;
V_305:
F_18 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
goto V_312;
}
static int F_159 ( T_1 * V_1 , int V_313 )
{
int V_20 ;
T_7 * V_63 ;
for ( V_20 = 0 ; V_20 < V_314 ; V_20 ++ ) {
if ( V_1 -> V_63 [ V_20 ] && V_20 != 0 )
continue;
if ( V_20 == 0 && V_1 -> V_63 [ V_20 ] && V_1 -> V_63 [ V_20 ] -> V_68 != - 1 )
continue;
if ( V_20 > V_1 -> V_64 && ! V_313 )
V_1 -> V_64 = V_20 ;
if ( V_20 == 0 && V_1 -> V_63 [ V_20 ] != NULL )
return V_20 ;
V_63 = F_127 ( sizeof( * V_63 ) , V_23 ) ;
if ( ! V_63 )
return - 1 ;
V_63 -> V_68 = - 1 ;
V_1 -> V_63 [ V_20 ] = V_63 ;
return V_20 ;
}
return - 1 ;
}
static void F_158 ( T_1 * V_1 , int V_122 )
{
F_15 ( V_1 -> V_63 [ V_122 ] ) ;
V_1 -> V_63 [ V_122 ] = NULL ;
}
static void F_157 ( T_1 * V_1 , int V_122 )
{
F_160 ( V_1 -> V_141 [ V_122 ] ) ;
V_1 -> V_141 [ V_122 ] = NULL ;
}
static int F_161 ( T_1 * V_1 , unsigned char V_114 [] ,
int V_313 )
{
int V_122 ;
V_122 = F_159 ( V_1 , V_313 ) ;
if ( V_122 == - 1 )
return - 1 ;
if ( ! V_1 -> V_141 [ V_122 ] ) {
V_1 -> V_141 [ V_122 ] =
F_162 ( 1 << V_291 ) ;
if ( ! V_1 -> V_141 [ V_122 ] ) {
F_18 ( & V_1 -> V_24 -> V_25 ,
L_34 ,
V_122 ) ;
goto V_315;
}
}
memcpy ( V_1 -> V_63 [ V_122 ] -> V_116 , V_114 ,
sizeof( V_1 -> V_63 [ V_122 ] -> V_116 ) ) ;
if ( F_71 ( V_1 , V_122 ) )
goto V_316;
V_1 -> V_63 [ V_122 ] -> V_57 = 0 ;
F_147 () ;
return V_122 ;
V_316:
F_157 ( V_1 , V_122 ) ;
V_315:
F_158 ( V_1 , V_122 ) ;
return - 1 ;
}
static void F_163 ( T_1 * V_1 )
{
struct V_141 * V_142 ;
int V_122 ;
if ( V_1 -> V_141 [ 0 ] != NULL )
return;
V_122 = F_161 ( V_1 , V_152 , 1 ) ;
if ( V_122 == - 1 )
goto error;
V_1 -> V_63 [ V_122 ] -> V_299 = 512 ;
V_1 -> V_63 [ V_122 ] -> V_66 = 0 ;
V_1 -> V_63 [ V_122 ] -> V_65 = 0 ;
V_1 -> V_63 [ V_122 ] -> V_190 = 0 ;
V_1 -> V_63 [ V_122 ] -> V_189 = 0 ;
V_1 -> V_63 [ V_122 ] -> V_68 = - 1 ;
memset ( V_1 -> V_63 [ V_122 ] -> V_107 , 0 , 16 ) ;
V_142 = V_1 -> V_141 [ V_122 ] ;
if ( F_140 ( V_1 , V_142 , V_122 ) == 0 )
return;
F_157 ( V_1 , V_122 ) ;
F_158 ( V_1 , V_122 ) ;
error:
F_154 ( & V_1 -> V_24 -> V_25 , L_35 ) ;
return;
}
static int F_128 ( T_1 * V_1 , int V_300 ,
int V_301 )
{
int V_52 ;
T_30 * V_317 = NULL ;
int V_318 ;
int V_319 = 0 ;
int V_20 ;
int V_320 ;
int V_122 = 0 ;
unsigned char V_114 [ 8 ] = V_152 ;
unsigned long V_13 ;
if ( ! F_89 ( V_226 ) )
return - V_154 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_58 ;
}
V_1 -> V_57 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
V_317 = F_127 ( sizeof( T_30 ) , V_23 ) ;
if ( V_317 == NULL )
goto V_305;
V_318 = F_137 ( V_1 , V_321 , V_317 ,
sizeof( T_30 ) ,
0 , V_152 , V_283 ) ;
if ( V_318 == V_284 )
V_319 = F_164 ( * ( V_322 * ) V_317 -> V_323 ) ;
else {
F_154 ( & V_1 -> V_24 -> V_25 ,
L_36 ) ;
V_319 = 0 ;
goto V_312;
}
V_52 = V_319 / 8 ;
if ( V_52 > V_314 ) {
V_52 = V_314 ;
F_154 ( & V_1 -> V_24 -> V_25 , L_37
L_38
L_39 ) ;
}
if ( V_52 == 0 )
F_163 ( V_1 ) ;
for ( V_20 = 0 ; V_20 <= V_1 -> V_64 ; V_20 ++ ) {
int V_22 ;
V_320 = 0 ;
if ( V_1 -> V_63 [ V_20 ] == NULL )
continue;
for ( V_22 = 0 ; V_22 < V_52 ; V_22 ++ ) {
memcpy ( V_114 , & V_317 -> V_232 [ V_22 ] [ 0 ] , sizeof( V_114 ) ) ;
if ( memcmp ( V_1 -> V_63 [ V_20 ] -> V_116 , V_114 ,
sizeof( V_114 ) ) == 0 ) {
V_320 = 1 ;
break;
}
}
if ( ! V_320 ) {
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_1 -> V_63 [ V_20 ] -> V_57 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
V_318 = F_155 ( V_1 , V_20 , 1 , V_301 ) ;
if ( V_1 -> V_63 [ V_20 ] != NULL )
V_1 -> V_63 [ V_20 ] -> V_57 = 0 ;
}
}
for ( V_20 = 0 ; V_20 < V_52 ; V_20 ++ ) {
int V_22 ;
V_320 = 0 ;
memcpy ( V_114 , & V_317 -> V_232 [ V_20 ] [ 0 ] , sizeof( V_114 ) ) ;
for ( V_22 = 0 ; V_22 <= V_1 -> V_64 ; V_22 ++ ) {
if ( V_1 -> V_63 [ V_22 ] != NULL &&
memcmp ( V_1 -> V_63 [ V_22 ] -> V_116 , V_114 ,
sizeof( V_1 -> V_63 [ V_22 ] -> V_116 ) ) == 0 ) {
V_122 = V_22 ;
V_320 = 1 ;
break;
}
}
if ( ! V_320 ) {
V_122 = F_161 ( V_1 , V_114 , 0 ) ;
if ( V_122 == - 1 )
goto V_312;
}
F_150 ( V_1 , V_122 , V_300 , V_301 ) ;
}
V_312:
F_15 ( V_317 ) ;
V_1 -> V_57 = 0 ;
return - 1 ;
V_305:
F_18 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
V_1 -> V_57 = 0 ;
goto V_312;
}
static void F_165 ( T_7 * V_324 )
{
V_324 -> V_66 = 0 ;
V_324 -> V_299 = 0 ;
V_324 -> V_65 = 0 ;
V_324 -> V_190 = 0 ;
V_324 -> V_189 = 0 ;
V_324 -> V_68 = - 1 ;
memset ( V_324 -> V_107 , 0 , sizeof( V_324 -> V_107 ) ) ;
memset ( V_324 -> V_110 , 0 , sizeof( V_324 -> V_110 ) ) ;
memset ( V_324 -> V_112 , 0 , sizeof( V_324 -> V_112 ) ) ;
memset ( V_324 -> V_108 , 0 , sizeof( V_324 -> V_108 ) ) ;
}
static int F_155 ( T_1 * V_1 , int V_122 ,
int V_325 , int V_301 )
{
int V_20 ;
struct V_141 * V_142 ;
T_7 * V_63 ;
int V_326 ;
if ( ! F_89 ( V_226 ) )
return - V_154 ;
V_63 = V_1 -> V_63 [ V_122 ] ;
V_142 = V_1 -> V_141 [ V_122 ] ;
if ( V_325 || ( V_1 -> V_141 [ 0 ] == V_142 ) ) {
if ( V_63 -> V_118 > V_301 )
return - V_58 ;
} else if ( V_63 -> V_118 > 0 )
return - V_58 ;
V_326 = ( V_63 == V_1 -> V_63 [ V_1 -> V_64 ] ) ;
if ( V_1 -> V_141 [ 0 ] != V_142 ) {
struct V_327 * V_328 = V_142 -> V_143 ;
if ( V_142 -> V_13 & V_329 ) {
F_72 ( V_1 , V_122 , 0 ) ;
F_166 ( V_142 ) ;
}
if ( V_328 )
F_149 ( V_328 ) ;
if ( V_325 ) {
for ( V_20 = 0 ; V_20 < V_314 ; V_20 ++ ) {
if ( V_1 -> V_141 [ V_20 ] == V_142 ) {
V_1 -> V_141 [ V_20 ] = NULL ;
break;
}
}
F_160 ( V_142 ) ;
}
} else {
F_156 ( V_142 , 0 ) ;
F_165 ( V_63 ) ;
}
-- V_1 -> V_52 ;
if ( V_325 && V_326 ) {
int V_330 = - 1 ;
for ( V_20 = 0 ; V_20 <= V_1 -> V_64 ; V_20 ++ ) {
if ( V_1 -> V_63 [ V_20 ] && V_1 -> V_63 [ V_20 ] -> V_65 )
V_330 = V_20 ;
}
V_1 -> V_64 = V_330 ;
}
return 0 ;
}
static int F_167 ( T_1 * V_1 , T_2 * V_2 , T_12 V_156 , void * V_224 ,
T_10 V_331 , T_12 V_332 , unsigned char * V_277 ,
int V_11 )
{
T_4 V_333 ;
int V_240 = V_284 ;
V_2 -> V_11 = V_230 ;
V_2 -> V_7 . V_231 = 0 ;
if ( V_224 != NULL ) {
V_2 -> V_7 . V_8 = 1 ;
V_2 -> V_7 . V_29 = 1 ;
} else {
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_7 . V_29 = 0 ;
}
V_2 -> V_7 . V_233 . V_33 = V_2 -> V_5 ;
memcpy ( V_2 -> V_7 . V_232 . V_334 , V_277 , 8 ) ;
V_2 -> V_181 . Type . Type = V_11 ;
if ( V_11 == V_283 ) {
switch ( V_156 ) {
case V_282 :
if ( V_332 != 0 ) {
V_2 -> V_181 . V_335 [ 1 ] = 0x01 ;
V_2 -> V_181 . V_335 [ 2 ] = V_332 ;
}
V_2 -> V_181 . V_336 = 6 ;
V_2 -> V_181 . Type . V_337 = V_338 ;
V_2 -> V_181 . Type . V_227 = V_236 ;
V_2 -> V_181 . V_339 = 0 ;
V_2 -> V_181 . V_335 [ 0 ] = V_282 ;
V_2 -> V_181 . V_335 [ 4 ] = V_331 & 0xFF ;
break;
case V_321 :
case V_340 :
V_2 -> V_181 . V_336 = 12 ;
V_2 -> V_181 . Type . V_337 = V_338 ;
V_2 -> V_181 . Type . V_227 = V_236 ;
V_2 -> V_181 . V_339 = 0 ;
V_2 -> V_181 . V_335 [ 0 ] = V_156 ;
V_2 -> V_181 . V_335 [ 6 ] = ( V_331 >> 24 ) & 0xFF ;
V_2 -> V_181 . V_335 [ 7 ] = ( V_331 >> 16 ) & 0xFF ;
V_2 -> V_181 . V_335 [ 8 ] = ( V_331 >> 8 ) & 0xFF ;
V_2 -> V_181 . V_335 [ 9 ] = V_331 & 0xFF ;
break;
case V_341 :
V_2 -> V_181 . V_336 = 10 ;
V_2 -> V_181 . Type . V_337 = V_338 ;
V_2 -> V_181 . Type . V_227 = V_236 ;
V_2 -> V_181 . V_339 = 0 ;
V_2 -> V_181 . V_335 [ 0 ] = V_156 ;
break;
case V_342 :
V_2 -> V_181 . V_336 = 16 ;
V_2 -> V_181 . Type . V_337 = V_338 ;
V_2 -> V_181 . Type . V_227 = V_236 ;
V_2 -> V_181 . V_339 = 0 ;
V_2 -> V_181 . V_335 [ 0 ] = V_156 ;
V_2 -> V_181 . V_335 [ 1 ] = 0x10 ;
V_2 -> V_181 . V_335 [ 10 ] = ( V_331 >> 24 ) & 0xFF ;
V_2 -> V_181 . V_335 [ 11 ] = ( V_331 >> 16 ) & 0xFF ;
V_2 -> V_181 . V_335 [ 12 ] = ( V_331 >> 8 ) & 0xFF ;
V_2 -> V_181 . V_335 [ 13 ] = V_331 & 0xFF ;
V_2 -> V_181 . V_339 = 0 ;
V_2 -> V_181 . V_335 [ 0 ] = V_156 ;
break;
case V_343 :
V_2 -> V_181 . V_336 = 12 ;
V_2 -> V_181 . Type . V_337 = V_338 ;
V_2 -> V_181 . Type . V_227 = V_229 ;
V_2 -> V_181 . V_339 = 0 ;
V_2 -> V_181 . V_335 [ 0 ] = V_344 ;
V_2 -> V_181 . V_335 [ 6 ] = V_345 ;
V_2 -> V_181 . V_335 [ 7 ] = ( V_331 >> 8 ) & 0xFF ;
V_2 -> V_181 . V_335 [ 8 ] = V_331 & 0xFF ;
break;
case V_346 :
V_2 -> V_181 . V_336 = 6 ;
V_2 -> V_181 . Type . V_337 = V_338 ;
V_2 -> V_181 . Type . V_227 = V_228 ;
V_2 -> V_181 . V_339 = 0 ;
break;
default:
F_154 ( & V_1 -> V_24 -> V_25 , L_40 , V_156 ) ;
return V_347 ;
}
} else if ( V_11 == V_348 ) {
switch ( V_156 ) {
case V_349 :
V_2 -> V_181 . V_336 = 12 ;
V_2 -> V_181 . Type . V_337 = V_338 ;
V_2 -> V_181 . Type . V_227 = V_229 ;
V_2 -> V_181 . V_339 = 0 ;
V_2 -> V_181 . V_335 [ 0 ] = V_156 ;
V_2 -> V_181 . V_335 [ 1 ] = 0 ;
memcpy ( & V_2 -> V_181 . V_335 [ 4 ] , V_224 , 8 ) ;
break;
case V_350 :
V_2 -> V_181 . V_336 = 16 ;
V_2 -> V_181 . Type . V_337 = V_338 ;
V_2 -> V_181 . Type . V_227 = V_228 ;
V_2 -> V_181 . V_339 = 0 ;
memset ( & V_2 -> V_181 . V_335 [ 0 ] , 0 , sizeof( V_2 -> V_181 . V_335 ) ) ;
V_2 -> V_181 . V_335 [ 0 ] = V_156 ;
V_2 -> V_181 . V_335 [ 1 ] = V_351 ;
break;
case V_352 :
V_2 -> V_181 . V_336 = 1 ;
V_2 -> V_181 . Type . V_337 = V_338 ;
V_2 -> V_181 . Type . V_227 = V_229 ;
V_2 -> V_181 . V_339 = 0 ;
V_2 -> V_181 . V_335 [ 0 ] = V_156 ;
break;
default:
F_154 ( & V_1 -> V_24 -> V_25 ,
L_41 , V_156 ) ;
return V_347 ;
}
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_42 , V_11 ) ;
return V_347 ;
}
if ( V_331 > 0 ) {
V_333 . V_36 = ( V_138 ) F_22 ( V_1 -> V_24 ,
V_224 , V_331 ,
V_234 ) ;
V_2 -> V_31 [ 0 ] . V_34 . V_33 = V_333 . V_32 . V_33 ;
V_2 -> V_31 [ 0 ] . V_34 . V_35 = V_333 . V_32 . V_35 ;
V_2 -> V_31 [ 0 ] . V_37 = V_331 ;
V_2 -> V_31 [ 0 ] . V_41 = 0 ;
}
return V_240 ;
}
static int F_168 ( T_1 * V_1 , unsigned char * V_277 ,
T_31 V_353 )
{
T_2 * V_2 ;
int V_354 ;
V_2 = F_73 ( V_1 ) ;
if ( ! V_2 )
return - V_84 ;
V_354 = F_167 ( V_1 , V_2 , V_350 , NULL , 0 , 0 ,
V_152 , V_348 ) ;
V_2 -> V_181 . V_335 [ 1 ] = V_353 ;
if ( V_354 != V_284 ) {
F_82 ( V_1 , V_2 ) ;
return V_354 ;
}
V_2 -> V_235 = NULL ;
F_10 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_169 ( T_1 * V_1 , T_2 * V_2 )
{
switch ( V_2 -> V_131 -> V_193 ) {
case V_355 :
return V_284 ;
case V_194 :
switch ( 0xf & V_2 -> V_131 -> V_356 [ 2 ] ) {
case 0 : return V_284 ;
case 1 : return V_284 ;
default:
if ( F_106 ( V_1 , V_2 ) )
return V_357 ;
F_154 ( & V_1 -> V_24 -> V_25 , L_43
L_44 ,
V_2 -> V_181 . V_335 [ 0 ] , V_2 -> V_131 -> V_356 [ 2 ] ) ;
}
break;
default:
F_154 ( & V_1 -> V_24 -> V_25 , L_45
L_46 ,
V_2 -> V_181 . V_335 [ 0 ] , V_2 -> V_131 -> V_193 ) ;
break;
}
return V_347 ;
}
static int F_170 ( T_1 * V_1 , T_2 * V_2 )
{
int V_354 = V_284 ;
if ( V_2 -> V_131 -> V_191 == V_358 )
return V_284 ;
switch ( V_2 -> V_131 -> V_191 ) {
case V_192 :
V_354 = F_169 ( V_1 , V_2 ) ;
break;
case V_359 :
case V_360 :
break;
case V_361 :
F_154 ( & V_1 -> V_24 -> V_25 , L_47
L_48 , V_2 -> V_181 . V_335 [ 0 ] ) ;
V_354 = V_347 ;
break;
case V_362 :
F_154 ( & V_1 -> V_24 -> V_25 , L_49
L_50 , V_2 -> V_181 . V_335 [ 0 ] ) ;
V_354 = V_347 ;
break;
case V_363 :
F_154 ( & V_1 -> V_24 -> V_25 , L_51
L_52 , V_2 -> V_181 . V_335 [ 0 ] ) ;
V_354 = V_347 ;
break;
case V_364 :
F_154 ( & V_1 -> V_24 -> V_25 , L_51
L_53 , V_2 -> V_181 . V_335 [ 0 ] ) ;
V_354 = V_347 ;
break;
case V_365 :
F_154 ( & V_1 -> V_24 -> V_25 , L_54
L_55 , V_2 -> V_181 . V_335 [ 0 ] ) ;
V_354 = V_347 ;
break;
case V_366 :
F_154 ( & V_1 -> V_24 -> V_25 , L_56
L_57 , V_2 -> V_181 . V_335 [ 0 ] ) ;
V_354 = V_347 ;
break;
case V_367 :
F_154 ( & V_1 -> V_24 -> V_25 , L_58 ,
V_2 -> V_181 . V_335 [ 0 ] ) ;
V_354 = V_357 ;
break;
case V_368 :
F_154 ( & V_1 -> V_24 -> V_25 , L_59 ) ;
V_354 = V_347 ;
break;
default:
F_154 ( & V_1 -> V_24 -> V_25 , L_60
L_61 , V_2 -> V_181 . V_335 [ 0 ] ,
V_2 -> V_131 -> V_191 ) ;
V_354 = V_347 ;
}
return V_354 ;
}
static int F_171 ( T_1 * V_1 , T_2 * V_2 ,
int V_369 )
{
F_124 ( V_225 ) ;
T_4 V_333 ;
int V_354 = V_284 ;
V_370:
V_2 -> V_235 = & V_225 ;
F_10 ( V_1 , V_2 ) ;
F_125 ( & V_225 ) ;
if ( V_2 -> V_131 -> V_191 == 0 || ! V_369 )
goto V_371;
V_354 = F_170 ( V_1 , V_2 ) ;
if ( V_354 == V_357 &&
V_2 -> V_372 < V_373 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_62 ,
V_2 -> V_181 . V_335 [ 0 ] ) ;
V_2 -> V_372 ++ ;
memset ( V_2 -> V_131 , 0 , sizeof( V_133 ) ) ;
V_354 = V_284 ;
F_172 ( V_225 ) ;
goto V_370;
}
V_371:
V_333 . V_32 . V_33 = V_2 -> V_31 [ 0 ] . V_34 . V_33 ;
V_333 . V_32 . V_35 = V_2 -> V_31 [ 0 ] . V_34 . V_35 ;
F_20 ( V_1 -> V_24 , ( T_13 ) V_333 . V_36 ,
V_2 -> V_31 [ 0 ] . V_37 , V_234 ) ;
return V_354 ;
}
static int F_137 ( T_1 * V_1 , T_12 V_156 , void * V_224 , T_10 V_331 ,
T_12 V_332 , unsigned char V_277 [] ,
int V_11 )
{
T_2 * V_2 ;
int V_354 ;
V_2 = F_77 ( V_1 ) ;
if ( ! V_2 )
return - V_84 ;
V_354 = F_167 ( V_1 , V_2 , V_156 , V_224 , V_331 , V_332 ,
V_277 , V_11 ) ;
if ( V_354 == V_284 )
V_354 = F_171 ( V_1 , V_2 , 1 ) ;
F_82 ( V_1 , V_2 ) ;
return V_354 ;
}
static void F_153 ( T_1 * V_1 , int V_279 ,
T_6 V_303 ,
unsigned int V_299 ,
T_29 * V_302 ,
T_7 * V_63 )
{
int V_318 ;
unsigned long V_374 ;
unsigned char V_277 [ 8 ] ;
memset ( V_302 , 0 , sizeof( T_29 ) ) ;
F_135 ( V_1 , V_277 , V_279 ) ;
V_318 = F_137 ( V_1 , V_282 , V_302 ,
sizeof( * V_302 ) , 0xC1 , V_277 , V_283 ) ;
if ( V_318 == V_284 ) {
if ( V_302 -> V_285 [ 8 ] == 0xFF ) {
F_154 ( & V_1 -> V_24 -> V_25 ,
L_63
L_64 ) ;
V_63 -> V_65 = 255 ;
V_63 -> V_190 = 32 ;
V_63 -> V_189 = V_303 + 1 ;
V_63 -> V_68 = V_69 ;
} else {
V_63 -> V_65 = V_302 -> V_285 [ 6 ] ;
V_63 -> V_190 = V_302 -> V_285 [ 7 ] ;
V_63 -> V_189 = ( V_302 -> V_285 [ 4 ] & 0xff ) << 8 ;
V_63 -> V_189 += V_302 -> V_285 [ 5 ] ;
V_63 -> V_68 = V_302 -> V_285 [ 8 ] ;
}
V_63 -> V_299 = V_299 ;
V_63 -> V_66 = V_303 + 1 ;
V_374 = V_63 -> V_65 * V_63 -> V_190 ;
if ( V_374 > 1 ) {
T_6 V_375 = V_303 + 1 ;
unsigned long V_376 = F_30 ( V_375 , V_374 ) ;
if ( V_376 )
V_375 ++ ;
V_63 -> V_189 = V_375 ;
}
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_65 ) ;
}
}
static void
F_152 ( T_1 * V_1 , int V_279 , T_6 * V_303 ,
unsigned int * V_299 )
{
T_32 * V_77 ;
int V_318 ;
unsigned char V_277 [ 8 ] ;
V_77 = F_127 ( sizeof( T_32 ) , V_23 ) ;
if ( ! V_77 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
return;
}
F_135 ( V_1 , V_277 , V_279 ) ;
V_318 = F_137 ( V_1 , V_341 , V_77 ,
sizeof( T_32 ) , 0 , V_277 , V_283 ) ;
if ( V_318 == V_284 ) {
* V_303 = F_164 ( * ( V_322 * ) V_77 -> V_303 ) ;
* V_299 = F_164 ( * ( V_322 * ) V_77 -> V_299 ) ;
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_66 ) ;
* V_303 = 0 ;
* V_299 = V_377 ;
}
F_15 ( V_77 ) ;
}
static void F_151 ( T_1 * V_1 , int V_279 ,
T_6 * V_303 , unsigned int * V_299 )
{
T_33 * V_77 ;
int V_318 ;
unsigned char V_277 [ 8 ] ;
V_77 = F_127 ( sizeof( T_33 ) , V_23 ) ;
if ( ! V_77 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
return;
}
F_135 ( V_1 , V_277 , V_279 ) ;
V_318 = F_137 ( V_1 , V_342 ,
V_77 , sizeof( T_33 ) ,
0 , V_277 , V_283 ) ;
if ( V_318 == V_284 ) {
* V_303 = F_173 ( * ( V_378 * ) V_77 -> V_303 ) ;
* V_299 = F_164 ( * ( V_322 * ) V_77 -> V_299 ) ;
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_66 ) ;
* V_303 = 0 ;
* V_299 = V_377 ;
}
F_174 ( & V_1 -> V_24 -> V_25 , L_67 ,
( unsigned long long ) * V_303 + 1 , * V_299 ) ;
F_15 ( V_77 ) ;
}
static int F_175 ( struct V_141 * V_142 )
{
T_1 * V_1 = F_84 ( V_142 ) ;
T_7 * V_63 = F_85 ( V_142 ) ;
int V_279 ;
int V_379 = 0 ;
unsigned int V_299 ;
T_6 V_303 ;
T_29 * V_302 = NULL ;
for ( V_279 = 0 ; V_279 <= V_1 -> V_64 ; V_279 ++ ) {
if ( ! V_1 -> V_63 [ V_279 ] )
continue;
if ( memcmp ( V_1 -> V_63 [ V_279 ] -> V_116 , V_63 -> V_116 ,
sizeof( V_63 -> V_116 ) ) == 0 ) {
V_379 = 1 ;
break;
}
}
if ( ! V_379 )
return 1 ;
V_302 = F_17 ( sizeof( T_29 ) , V_23 ) ;
if ( V_302 == NULL ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
return 1 ;
}
if ( V_1 -> V_306 == V_310 ) {
F_152 ( V_1 , V_279 ,
& V_303 , & V_299 ) ;
} else {
F_151 ( V_1 , V_279 ,
& V_303 , & V_299 ) ;
}
F_153 ( V_1 , V_279 , V_303 , V_299 ,
V_302 , V_63 ) ;
F_146 ( V_63 -> V_143 , V_63 -> V_299 ) ;
F_156 ( V_142 , V_63 -> V_66 ) ;
F_15 ( V_302 ) ;
return 0 ;
}
static void T_34 * F_176 ( T_35 V_380 , T_35 V_331 )
{
T_35 V_381 = ( ( T_35 ) V_380 ) & V_382 ;
T_35 V_383 = ( ( T_35 ) V_380 ) - V_381 ;
void T_34 * V_384 = F_177 ( V_381 , V_383 + V_331 ) ;
return V_384 ? ( V_384 + V_383 ) : NULL ;
}
static void F_12 ( T_1 * V_1 )
{
T_2 * V_2 ;
while ( ! F_8 ( & V_1 -> V_15 ) ) {
V_2 = F_178 ( V_1 -> V_15 . V_385 , T_2 , V_10 ) ;
if ( ( V_1 -> V_386 . V_387 ( V_1 ) ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_68 ) ;
break;
}
F_6 ( V_2 ) ;
V_1 -> V_16 -- ;
V_1 -> V_386 . V_388 ( V_1 , V_2 ) ;
F_4 ( & V_1 -> V_389 , V_2 ) ;
}
}
static inline void F_179 ( T_1 * V_1 , T_2 * V_2 )
{
memset ( V_2 -> V_131 , 0 , sizeof( V_133 ) ) ;
F_4 ( & V_1 -> V_15 , V_2 ) ;
V_1 -> V_16 ++ ;
if ( V_1 -> V_16 > V_1 -> V_17 )
V_1 -> V_17 = V_1 -> V_16 ;
F_12 ( V_1 ) ;
}
static inline unsigned int F_180 ( unsigned int V_390 ,
unsigned int V_391 , unsigned int V_392 ,
unsigned int V_393 )
{
return ( V_390 & 0xff ) |
( ( V_391 & 0xff ) << 8 ) |
( ( V_392 & 0xff ) << 16 ) |
( ( V_393 & 0xff ) << 24 ) ;
}
static inline int F_181 ( T_1 * V_1 ,
T_2 * V_156 , int * V_394 )
{
unsigned char V_395 ;
unsigned char V_396 , V_391 , V_392 , V_393 ;
int V_397 ;
* V_394 = 0 ;
V_396 = V_156 -> V_131 -> V_193 ;
V_393 = V_398 ;
V_391 = V_156 -> V_131 -> V_191 ;
if ( V_156 -> V_265 -> V_11 == V_272 )
V_392 = V_399 ;
else
V_392 = V_400 ;
V_397 = F_180 ( V_396 , V_391 ,
V_392 , V_393 ) ;
if ( V_156 -> V_131 -> V_193 != V_194 ) {
if ( V_156 -> V_265 -> V_11 != V_272 )
F_154 ( & V_1 -> V_24 -> V_25 , L_69
L_70 ,
V_156 , V_156 -> V_131 -> V_193 ) ;
return V_397 ;
}
V_395 = 0xf & V_156 -> V_131 -> V_356 [ 2 ] ;
if ( ( ( V_395 == 0x0 ) || ( V_395 == 0x1 ) ) &&
( V_156 -> V_265 -> V_11 != V_272 ) )
V_397 = 0 ;
if ( F_106 ( V_1 , V_156 ) ) {
* V_394 = ! ( V_156 -> V_265 -> V_11 == V_272 ) ;
return 0 ;
}
if ( V_156 -> V_265 -> V_11 != V_272 ) {
if ( V_397 != 0 )
F_154 ( & V_1 -> V_24 -> V_25 , L_71
L_72 , V_156 , V_395 ) ;
return V_397 ;
}
if ( V_156 -> V_265 -> V_401 ) {
if ( V_156 -> V_265 -> V_402 > V_156 -> V_131 -> V_403 )
V_156 -> V_265 -> V_402 = V_156 -> V_131 -> V_403 ;
memcpy ( V_156 -> V_265 -> V_401 , V_156 -> V_131 -> V_356 ,
V_156 -> V_265 -> V_402 ) ;
} else
V_156 -> V_265 -> V_402 = 0 ;
return V_397 ;
}
static inline void F_182 ( T_1 * V_1 , T_2 * V_156 ,
int V_404 )
{
int V_394 = 0 ;
struct V_264 * V_265 = V_156 -> V_265 ;
V_265 -> V_275 = 0 ;
if ( V_404 )
V_265 -> V_275 = F_180 ( 0 , 0 , 0 , V_405 ) ;
if ( V_156 -> V_131 -> V_191 == 0 )
goto V_406;
switch ( V_156 -> V_131 -> V_191 ) {
case V_192 :
V_265 -> V_275 = F_181 ( V_1 , V_156 , & V_394 ) ;
break;
case V_359 :
if ( V_156 -> V_265 -> V_11 == V_407 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_73
L_74
L_75 , V_156 ) ;
V_156 -> V_265 -> V_273 = V_156 -> V_131 -> V_274 ;
}
break;
case V_360 :
if ( V_156 -> V_265 -> V_11 == V_407 )
F_154 ( & V_1 -> V_24 -> V_25 , L_76
L_77
L_75 , V_156 ) ;
break;
case V_361 :
F_154 ( & V_1 -> V_24 -> V_25 , L_78
L_48 , V_156 ) ;
V_265 -> V_275 = F_180 ( V_355 ,
V_156 -> V_131 -> V_191 , V_398 ,
( V_156 -> V_265 -> V_11 == V_272 ) ?
V_399 : V_408 ) ;
break;
case V_362 :
F_154 ( & V_1 -> V_24 -> V_25 , L_79
L_50 , V_156 ) ;
V_265 -> V_275 = F_180 ( V_355 ,
V_156 -> V_131 -> V_191 , V_398 ,
( V_156 -> V_265 -> V_11 == V_272 ) ?
V_399 : V_408 ) ;
break;
case V_363 :
F_154 ( & V_1 -> V_24 -> V_25 , L_80
L_52 , V_156 ) ;
V_265 -> V_275 = F_180 ( V_355 ,
V_156 -> V_131 -> V_191 , V_398 ,
( V_156 -> V_265 -> V_11 == V_272 ) ?
V_399 : V_408 ) ;
break;
case V_364 :
F_154 ( & V_1 -> V_24 -> V_25 , L_80
L_53 , V_156 ) ;
V_265 -> V_275 = F_180 ( V_355 ,
V_156 -> V_131 -> V_191 , V_398 ,
( V_156 -> V_265 -> V_11 == V_272 ) ?
V_399 : V_408 ) ;
break;
case V_365 :
F_154 ( & V_1 -> V_24 -> V_25 , L_81
L_55 , V_156 ) ;
V_265 -> V_275 = F_180 ( V_355 ,
V_156 -> V_131 -> V_191 , V_398 ,
( V_156 -> V_265 -> V_11 == V_272 ) ?
V_399 : V_409 ) ;
break;
case V_366 :
F_154 ( & V_1 -> V_24 -> V_25 , L_82
L_57 , V_156 ) ;
V_265 -> V_275 = F_180 ( V_355 ,
V_156 -> V_131 -> V_191 , V_398 ,
( V_156 -> V_265 -> V_11 == V_272 ) ?
V_399 : V_408 ) ;
break;
case V_367 :
F_154 ( & V_1 -> V_24 -> V_25 , L_83
L_84 , V_1 -> V_62 , V_156 ) ;
if ( V_156 -> V_372 < V_373 ) {
V_394 = 1 ;
F_154 ( & V_1 -> V_24 -> V_25 , L_85 , V_156 ) ;
V_156 -> V_372 ++ ;
} else
F_154 ( & V_1 -> V_24 -> V_25 ,
L_86 , V_156 ) ;
V_265 -> V_275 = F_180 ( V_355 ,
V_156 -> V_131 -> V_191 , V_398 ,
( V_156 -> V_265 -> V_11 == V_272 ) ?
V_399 : V_409 ) ;
break;
case V_410 :
F_154 ( & V_1 -> V_24 -> V_25 , L_87 , V_156 ) ;
V_265 -> V_275 = F_180 ( V_355 ,
V_156 -> V_131 -> V_191 , V_398 ,
( V_156 -> V_265 -> V_11 == V_272 ) ?
V_399 : V_408 ) ;
break;
case V_368 :
F_154 ( & V_1 -> V_24 -> V_25 , L_88 , V_156 ) ;
V_265 -> V_275 = F_180 ( V_355 ,
V_156 -> V_131 -> V_191 , V_398 ,
V_156 -> V_265 -> V_11 == V_272 ?
V_399 : V_408 ) ;
break;
default:
F_154 ( & V_1 -> V_24 -> V_25 , L_89
L_61 , V_156 ,
V_156 -> V_131 -> V_191 ) ;
V_265 -> V_275 = F_180 ( V_355 ,
V_156 -> V_131 -> V_191 , V_398 ,
( V_156 -> V_265 -> V_11 == V_272 ) ?
V_399 : V_408 ) ;
}
V_406:
if ( V_394 ) {
F_179 ( V_1 , V_156 ) ;
return;
}
V_156 -> V_265 -> V_266 = V_156 ;
F_183 ( V_156 -> V_265 ) ;
}
static inline T_11 F_184 ( T_11 V_411 )
{
#define F_185 0x10
return V_411 & F_185 ;
}
static inline T_11 F_186 ( T_11 V_411 )
{
#define F_187 5
return V_411 >> F_187 ;
}
static inline T_11 F_83 ( T_1 * V_1 , T_11 V_411 )
{
#define F_188 ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define F_189 0x03
if ( F_3 ( V_1 -> V_3 & V_4 ) )
return V_411 & ~ F_188 ;
return V_411 & ~ F_189 ;
}
static inline void F_190 ( T_11 * V_411 )
{
* V_411 |= F_185 ;
}
static inline void F_191 ( T_11 * V_411 , T_11 V_412 )
{
* V_411 |= ( V_412 << F_187 ) ;
}
static void V_287 ( struct V_327 * V_328 )
{
T_1 * V_1 = V_328 -> V_144 ;
T_2 * V_2 ;
T_6 V_413 ;
int V_414 ;
struct V_264 * V_415 ;
T_4 V_28 ;
struct V_416 * V_417 ;
T_3 * V_268 ;
T_7 * V_63 ;
int V_20 , V_418 ;
int V_270 = 0 ;
int V_419 = 0 ;
V_143:
V_415 = F_192 ( V_328 ) ;
if ( ! V_415 )
goto V_420;
F_193 ( V_415 -> V_421 > V_1 -> V_297 ) ;
V_2 = F_73 ( V_1 ) ;
if ( ! V_2 )
goto V_422;
F_194 ( V_415 ) ;
V_417 = V_1 -> V_423 [ V_2 -> V_136 ] ;
F_195 ( V_328 -> V_424 ) ;
V_2 -> V_11 = V_425 ;
V_2 -> V_265 = V_415 ;
V_63 = V_415 -> V_426 -> V_75 ;
V_2 -> V_7 . V_231 = 0 ;
F_191 ( & V_2 -> V_7 . V_233 . V_33 , V_2 -> V_136 ) ;
F_190 ( & V_2 -> V_7 . V_233 . V_33 ) ;
memcpy ( & V_2 -> V_7 . V_232 , V_63 -> V_116 , sizeof( V_63 -> V_116 ) ) ;
V_2 -> V_181 . V_336 = 10 ;
V_2 -> V_181 . Type . Type = V_283 ;
V_2 -> V_181 . Type . V_337 = V_338 ;
V_2 -> V_181 . Type . V_227 =
( F_196 ( V_415 ) == V_427 ) ? V_236 : V_229 ;
V_2 -> V_181 . V_339 = 0 ;
V_2 -> V_181 . V_335 [ 0 ] =
( F_196 ( V_415 ) == V_427 ) ? V_1 -> V_306 : V_1 -> V_308 ;
V_413 = F_197 ( V_415 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_90 ,
( int ) F_197 ( V_415 ) , ( int ) F_198 ( V_415 ) ) ;
F_199 ( V_417 , V_1 -> V_297 ) ;
V_414 = F_200 ( V_328 , V_415 , V_417 ) ;
if ( V_2 -> V_181 . Type . V_227 == V_236 )
V_418 = V_271 ;
else
V_418 = V_38 ;
V_268 = V_2 -> V_31 ;
V_270 = 0 ;
V_419 = 0 ;
for ( V_20 = 0 ; V_20 < V_414 ; V_20 ++ ) {
if ( ( ( V_270 + 1 ) == ( V_1 -> V_30 ) ) &&
! V_419 && ( ( V_414 - V_20 ) > 1 ) ) {
V_268 = V_1 -> V_18 [ V_2 -> V_136 ] ;
V_270 = 0 ;
V_419 = 1 ;
}
V_268 [ V_270 ] . V_37 = V_417 [ V_20 ] . V_78 ;
V_28 . V_36 = ( V_138 ) F_201 ( V_1 -> V_24 , F_202 ( & V_417 [ V_20 ] ) ,
V_417 [ V_20 ] . V_428 ,
V_417 [ V_20 ] . V_78 , V_418 ) ;
V_268 [ V_270 ] . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_268 [ V_270 ] . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_268 [ V_270 ] . V_41 = 0 ;
++ V_270 ;
}
if ( V_419 )
F_21 ( V_1 , V_2 , V_1 -> V_18 [ V_2 -> V_136 ] ,
( V_414 - ( V_1 -> V_30 - 1 ) ) *
sizeof( T_3 ) ) ;
if ( V_414 > V_1 -> V_55 )
V_1 -> V_55 = V_414 ;
F_87 ( & V_1 -> V_24 -> V_25 , L_91
L_92 ,
F_198 ( V_415 ) , V_414 , V_419 ) ;
V_2 -> V_7 . V_29 = V_414 + V_419 ;
if ( V_414 <= V_1 -> V_30 )
V_2 -> V_7 . V_8 = V_2 -> V_7 . V_29 ;
else
V_2 -> V_7 . V_8 = V_1 -> V_30 ;
F_2 ( V_1 , V_2 ) ;
if ( F_3 ( V_415 -> V_11 == V_407 ) ) {
if( V_1 -> V_306 == V_310 ) {
V_2 -> V_181 . V_335 [ 1 ] = 0 ;
V_2 -> V_181 . V_335 [ 2 ] = ( V_413 >> 24 ) & 0xff ;
V_2 -> V_181 . V_335 [ 3 ] = ( V_413 >> 16 ) & 0xff ;
V_2 -> V_181 . V_335 [ 4 ] = ( V_413 >> 8 ) & 0xff ;
V_2 -> V_181 . V_335 [ 5 ] = V_413 & 0xff ;
V_2 -> V_181 . V_335 [ 6 ] = 0 ;
V_2 -> V_181 . V_335 [ 7 ] = ( F_198 ( V_415 ) >> 8 ) & 0xff ;
V_2 -> V_181 . V_335 [ 8 ] = F_198 ( V_415 ) & 0xff ;
V_2 -> V_181 . V_335 [ 9 ] = V_2 -> V_181 . V_335 [ 11 ] = V_2 -> V_181 . V_335 [ 12 ] = 0 ;
} else {
T_11 V_429 = F_203 ( V_413 ) ;
V_2 -> V_181 . V_336 = 16 ;
V_2 -> V_181 . V_335 [ 1 ] = 0 ;
V_2 -> V_181 . V_335 [ 2 ] = ( V_429 >> 24 ) & 0xff ;
V_2 -> V_181 . V_335 [ 3 ] = ( V_429 >> 16 ) & 0xff ;
V_2 -> V_181 . V_335 [ 4 ] = ( V_429 >> 8 ) & 0xff ;
V_2 -> V_181 . V_335 [ 5 ] = V_429 & 0xff ;
V_2 -> V_181 . V_335 [ 6 ] = ( V_413 >> 24 ) & 0xff ;
V_2 -> V_181 . V_335 [ 7 ] = ( V_413 >> 16 ) & 0xff ;
V_2 -> V_181 . V_335 [ 8 ] = ( V_413 >> 8 ) & 0xff ;
V_2 -> V_181 . V_335 [ 9 ] = V_413 & 0xff ;
V_2 -> V_181 . V_335 [ 10 ] = ( F_198 ( V_415 ) >> 24 ) & 0xff ;
V_2 -> V_181 . V_335 [ 11 ] = ( F_198 ( V_415 ) >> 16 ) & 0xff ;
V_2 -> V_181 . V_335 [ 12 ] = ( F_198 ( V_415 ) >> 8 ) & 0xff ;
V_2 -> V_181 . V_335 [ 13 ] = F_198 ( V_415 ) & 0xff ;
V_2 -> V_181 . V_335 [ 14 ] = V_2 -> V_181 . V_335 [ 15 ] = 0 ;
}
} else if ( V_415 -> V_11 == V_272 ) {
V_2 -> V_181 . V_336 = V_415 -> V_430 ;
memcpy ( V_2 -> V_181 . V_335 , V_415 -> V_156 , V_431 ) ;
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_93 ,
V_415 -> V_11 ) ;
F_204 () ;
}
F_205 ( V_328 -> V_424 ) ;
F_4 ( & V_1 -> V_15 , V_2 ) ;
V_1 -> V_16 ++ ;
if ( V_1 -> V_16 > V_1 -> V_17 )
V_1 -> V_17 = V_1 -> V_16 ;
goto V_143;
V_422:
F_206 ( V_328 ) ;
V_420:
F_12 ( V_1 ) ;
}
static inline unsigned long F_207 ( T_1 * V_1 )
{
return V_1 -> V_386 . V_432 ( V_1 ) ;
}
static inline int F_208 ( T_1 * V_1 )
{
return V_1 -> V_386 . V_433 ( V_1 ) ;
}
static inline long F_209 ( T_1 * V_1 )
{
return ( ( V_1 -> V_386 . V_433 ( V_1 ) == 0 ) ||
( V_1 -> V_434 == 0 ) ) ;
}
static inline int F_210 ( T_1 * V_1 , T_11 V_435 ,
T_11 V_436 )
{
if ( F_211 ( V_435 >= V_1 -> V_19 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_94 , V_436 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_212 ( T_1 * V_1 , T_2 * V_2 ,
T_11 V_436 )
{
F_6 ( V_2 ) ;
if ( F_3 ( V_2 -> V_11 == V_425 ) )
F_182 ( V_1 , V_2 , 0 ) ;
else if ( V_2 -> V_11 == V_230 )
F_213 ( V_2 -> V_235 ) ;
#ifdef F_25
else if ( V_2 -> V_11 == V_437 )
F_214 ( V_2 , 0 , V_436 ) ;
#endif
}
static inline T_11 F_215 ( T_1 * V_1 )
{
T_11 V_438 ;
if ( F_211 ( ! ( V_1 -> V_3 & V_4 ) ) )
return V_1 -> V_386 . V_432 ( V_1 ) ;
if ( ( * ( V_1 -> V_439 ) & 1 ) == ( V_1 -> V_440 ) ) {
V_438 = * ( V_1 -> V_439 ) ;
( V_1 -> V_439 ) ++ ;
V_1 -> V_53 -- ;
} else {
V_438 = V_441 ;
}
if ( V_1 -> V_439 == ( V_1 -> V_442 + V_1 -> V_443 ) ) {
V_1 -> V_439 = V_1 -> V_442 ;
V_1 -> V_440 ^= 1 ;
}
return V_438 ;
}
static inline T_11 F_216 ( T_1 * V_1 , T_11 V_436 )
{
T_11 V_435 ;
T_2 * V_2 ;
V_435 = F_186 ( V_436 ) ;
if ( F_210 ( V_1 , V_435 , V_436 ) )
return F_215 ( V_1 ) ;
V_2 = V_1 -> V_129 + V_435 ;
F_212 ( V_1 , V_2 , V_436 ) ;
return F_215 ( V_1 ) ;
}
static inline T_11 F_217 ( T_1 * V_1 , T_11 V_436 )
{
T_2 * V_2 = NULL ;
V_137 V_444 , V_445 ;
V_445 = F_83 ( V_1 , V_436 ) ;
F_218 (c, &h->cmpQ, list) {
V_444 = F_83 ( V_1 , V_2 -> V_5 ) ;
if ( V_444 == V_445 ) {
F_212 ( V_1 , V_2 , V_436 ) ;
return F_215 ( V_1 ) ;
}
}
F_210 ( V_1 , V_1 -> V_19 + 1 , V_436 ) ;
return F_215 ( V_1 ) ;
}
static int F_219 ( T_1 * V_1 )
{
if ( F_3 ( ! V_446 ) )
return 0 ;
if ( F_3 ( V_1 -> V_434 ) )
return 0 ;
F_174 ( & V_1 -> V_24 -> V_25 , L_95
L_96 ) ;
return 1 ;
}
static T_36 F_220 ( int V_447 , void * V_448 )
{
T_1 * V_1 = V_448 ;
unsigned long V_13 ;
T_11 V_436 ;
if ( F_219 ( V_1 ) )
return V_449 ;
if ( F_209 ( V_1 ) )
return V_449 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
while ( F_208 ( V_1 ) ) {
V_436 = F_207 ( V_1 ) ;
while ( V_436 != V_441 )
V_436 = F_215 ( V_1 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_450 ;
}
static T_36 F_221 ( int V_447 , void * V_448 )
{
T_1 * V_1 = V_448 ;
unsigned long V_13 ;
T_11 V_436 ;
if ( F_219 ( V_1 ) )
return V_449 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_436 = F_207 ( V_1 ) ;
while ( V_436 != V_441 )
V_436 = F_215 ( V_1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_450 ;
}
static T_36 F_222 ( int V_447 , void * V_448 )
{
T_1 * V_1 = V_448 ;
unsigned long V_13 ;
T_11 V_436 ;
if ( F_209 ( V_1 ) )
return V_449 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
while ( F_208 ( V_1 ) ) {
V_436 = F_207 ( V_1 ) ;
while ( V_436 != V_441 ) {
if ( F_184 ( V_436 ) )
V_436 = F_216 ( V_1 , V_436 ) ;
else
V_436 = F_217 ( V_1 , V_436 ) ;
}
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_450 ;
}
static T_36 F_223 ( int V_447 , void * V_448 )
{
T_1 * V_1 = V_448 ;
unsigned long V_13 ;
T_11 V_436 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_436 = F_207 ( V_1 ) ;
while ( V_436 != V_441 ) {
if ( F_184 ( V_436 ) )
V_436 = F_216 ( V_1 , V_436 ) ;
else
V_436 = F_217 ( V_1 , V_436 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_450 ;
}
static int F_50 ( struct V_101 * V_1 )
{
struct V_101 * V_451 ;
int V_452 = 0 ;
int V_73 = 0 ;
if ( V_1 -> V_453 )
return 0 ;
if ( ! F_224 ( & V_1 -> V_454 ) )
return 0 ;
F_91 ( & V_455 ) ;
F_218 (test_h, &scan_q, scan_list) {
if ( V_451 == V_1 ) {
V_452 = 1 ;
break;
}
}
if ( ! V_452 && ! V_1 -> V_456 ) {
F_172 ( V_1 -> V_104 ) ;
F_5 ( & V_1 -> V_457 , & V_458 ) ;
V_73 = 1 ;
}
F_92 ( & V_455 ) ;
F_92 ( & V_1 -> V_454 ) ;
return V_73 ;
}
static void F_225 ( struct V_101 * V_1 )
{
struct V_101 * V_451 , * V_459 ;
F_91 ( & V_455 ) ;
F_226 (test_h, tmp_h, &scan_q, scan_list) {
if ( V_451 == V_1 ) {
F_227 ( & V_1 -> V_457 ) ;
F_228 ( & V_1 -> V_104 ) ;
F_92 ( & V_455 ) ;
return;
}
}
if ( V_1 -> V_456 ) {
F_92 ( & V_455 ) ;
F_125 ( & V_1 -> V_104 ) ;
} else {
F_92 ( & V_455 ) ;
}
}
static int F_229 ( void * V_76 )
{
struct V_101 * V_1 ;
while ( 1 ) {
F_230 ( V_460 ) ;
F_231 () ;
if ( F_232 () )
break;
while ( 1 ) {
F_91 ( & V_455 ) ;
if ( F_8 ( & V_458 ) ) {
F_92 ( & V_455 ) ;
break;
}
V_1 = F_178 ( V_458 . V_385 ,
struct V_101 ,
V_457 ) ;
F_227 ( & V_1 -> V_457 ) ;
V_1 -> V_456 = 1 ;
F_92 ( & V_455 ) ;
F_128 ( V_1 , 0 , 0 ) ;
F_228 ( & V_1 -> V_104 ) ;
F_91 ( & V_455 ) ;
V_1 -> V_456 = 0 ;
F_92 ( & V_455 ) ;
}
}
return 0 ;
}
static int F_106 ( T_1 * V_1 , T_2 * V_2 )
{
if ( V_2 -> V_131 -> V_356 [ 2 ] != V_461 )
return 0 ;
switch ( V_2 -> V_131 -> V_356 [ 12 ] ) {
case V_462 :
F_154 ( & V_1 -> V_24 -> V_25 , L_97
L_98 ) ;
return 1 ;
break;
case V_463 :
F_154 ( & V_1 -> V_24 -> V_25 , L_99
L_100 ) ;
return 1 ;
break;
case V_464 :
F_154 ( & V_1 -> V_24 -> V_25 , L_101 ) ;
return 1 ;
break;
case V_465 :
F_154 ( & V_1 -> V_24 -> V_25 ,
L_102 ) ;
return 1 ;
break;
case V_466 :
F_154 ( & V_1 -> V_24 -> V_25 ,
L_103 ) ;
return 1 ;
break;
default:
F_154 ( & V_1 -> V_24 -> V_25 , L_104 ) ;
return 1 ;
}
}
static void F_233 ( T_1 * V_1 )
{
int V_20 ;
char V_467 [ 17 ] ;
T_37 * V_468 = V_1 -> V_203 ;
F_87 ( & V_1 -> V_24 -> V_25 , L_105 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_106 ) ;
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ )
V_467 [ V_20 ] = F_115 ( & ( V_468 -> V_469 [ V_20 ] ) ) ;
V_467 [ 4 ] = '\0' ;
F_87 ( & V_1 -> V_24 -> V_25 , L_107 , V_467 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_108 ,
F_110 ( & ( V_468 -> V_470 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_109 ,
F_110 ( & ( V_468 -> V_471 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_110 ,
F_110 ( & ( V_468 -> V_472 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_111 ,
F_110 ( & ( V_468 -> V_204 . V_473 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_112 ,
F_110 ( & ( V_468 -> V_204 . V_205 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_113 ,
F_110 ( & ( V_468 -> V_204 . V_206 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_114 ,
F_110 ( & ( V_468 -> V_474 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_115 ,
F_110 ( & ( V_468 -> V_216 ) ) ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
V_467 [ V_20 ] = F_115 ( & ( V_468 -> V_213 [ V_20 ] ) ) ;
V_467 [ 16 ] = '\0' ;
F_87 ( & V_1 -> V_24 -> V_25 , L_116 , V_467 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_117 ,
F_110 ( & ( V_468 -> V_215 ) ) ) ;
}
static int F_234 ( struct V_475 * V_24 , unsigned long V_476 )
{
int V_20 , V_428 , V_477 , V_478 ;
if ( V_476 == V_479 )
return 0 ;
V_428 = 0 ;
for ( V_20 = 0 ; V_20 < V_480 ; V_20 ++ ) {
V_478 = F_235 ( V_24 , V_20 ) & V_481 ;
if ( V_478 == V_482 )
V_428 += 4 ;
else {
V_477 = F_235 ( V_24 , V_20 ) &
V_483 ;
switch ( V_477 ) {
case V_484 :
case V_485 :
V_428 += 4 ;
break;
case V_486 :
V_428 += 8 ;
break;
default:
F_154 ( & V_24 -> V_25 ,
L_118 ) ;
return - 1 ;
break;
}
}
if ( V_428 == V_476 - V_479 )
return V_20 + 1 ;
}
return - 1 ;
}
static void F_236 ( int V_487 [] , int V_488 ,
int V_489 , int * V_490 )
{
int V_20 , V_22 , V_491 , V_331 ;
#define F_237 4
#define F_238 8
for ( V_20 = 0 ; V_20 <= V_489 ; V_20 ++ ) {
V_331 = V_20 + F_237 ;
V_491 = V_488 ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
if ( V_487 [ V_22 ] >= V_331 ) {
V_491 = V_22 ;
break;
}
}
V_490 [ V_20 ] = V_491 ;
}
}
static void F_239 ( T_1 * V_1 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_492 ; V_20 ++ ) {
if ( ! ( F_110 ( V_1 -> V_208 + V_209 ) & V_207 ) )
break;
F_240 ( 10000 , 20000 ) ;
}
}
static void F_241 ( T_1 * V_1 , T_11 V_493 )
{
V_137 V_494 ;
int V_495 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_246 + 4 } ;
unsigned long V_496 ;
F_242 ( 28 > V_246 + 4 ) ;
V_1 -> V_440 = 1 ;
memset ( V_1 -> V_442 , 0 , V_1 -> V_443 * sizeof( V_138 ) ) ;
V_1 -> V_439 = V_1 -> V_442 ;
V_494 = F_110 ( & ( V_1 -> V_203 -> V_497 ) ) ;
F_236 ( V_495 , F_44 ( V_495 ) , V_1 -> V_297 ,
V_1 -> V_6 ) ;
F_112 ( V_495 [ 0 ] , & V_1 -> V_498 -> V_499 ) ;
F_112 ( V_495 [ 1 ] , & V_1 -> V_498 -> V_500 ) ;
F_112 ( V_495 [ 2 ] , & V_1 -> V_498 -> V_501 ) ;
F_112 ( V_495 [ 3 ] , & V_1 -> V_498 -> V_502 ) ;
F_112 ( V_495 [ 4 ] , & V_1 -> V_498 -> V_503 ) ;
F_112 ( V_495 [ 5 ] , & V_1 -> V_498 -> V_504 ) ;
F_112 ( V_495 [ 6 ] , & V_1 -> V_498 -> V_505 ) ;
F_112 ( V_495 [ 7 ] , & V_1 -> V_498 -> V_506 ) ;
F_112 ( V_1 -> V_443 , & V_1 -> V_498 -> V_507 ) ;
F_112 ( 1 , & V_1 -> V_498 -> V_508 ) ;
F_112 ( 0 , & V_1 -> V_498 -> V_509 ) ;
F_112 ( 0 , & V_1 -> V_498 -> V_510 ) ;
F_112 ( V_1 -> V_511 , & V_1 -> V_498 -> V_512 ) ;
F_112 ( 0 , & V_1 -> V_498 -> V_513 ) ;
F_112 ( V_4 | V_493 ,
& ( V_1 -> V_203 -> V_204 . V_473 ) ) ;
F_112 ( V_207 , V_1 -> V_208 + V_209 ) ;
F_239 ( V_1 ) ;
V_496 = F_110 ( & ( V_1 -> V_203 -> V_472 ) ) ;
if ( ! ( V_496 & V_4 ) )
F_154 ( & V_1 -> V_24 -> V_25 , L_119
L_120 ) ;
}
static void F_243 ( T_1 * V_1 )
{
V_137 V_514 ;
if ( V_515 )
return;
F_87 ( & V_1 -> V_24 -> V_25 , L_121 ) ;
V_514 = F_110 ( & ( V_1 -> V_203 -> V_471 ) ) ;
if ( ! ( V_514 & V_516 ) )
return;
F_87 ( & V_1 -> V_24 -> V_25 , L_122 ) ;
if ( ( sizeof( T_2 ) % 32 ) != 0 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_123 ,
L_124 ,
( int ) sizeof( T_2 ) ,
L_125 ) ;
return;
}
V_1 -> V_442 = ( V_138 * ) F_78 (
V_1 -> V_24 , V_1 -> V_443 * sizeof( V_138 ) ,
& ( V_1 -> V_511 ) ) ;
V_1 -> V_6 = F_17 ( ( ( V_1 -> V_297 + 1 ) *
sizeof( V_137 ) ) , V_23 ) ;
if ( ( V_1 -> V_442 == NULL ) || ( V_1 -> V_6 == NULL ) )
goto V_517;
F_241 ( V_1 ,
V_514 & V_518 ) ;
V_1 -> V_386 = V_519 ;
V_1 -> V_3 = V_4 ;
return;
V_517:
F_15 ( V_1 -> V_6 ) ;
if ( V_1 -> V_442 )
F_79 ( V_1 -> V_24 ,
V_1 -> V_443 * sizeof( V_138 ) ,
V_1 -> V_442 ,
V_1 -> V_511 ) ;
return;
}
static void F_244 ( T_1 * V_1 )
{
#ifdef F_245
int V_80 ;
struct V_520 V_521 [ 4 ] = { { 0 , 0 } , { 0 , 1 } ,
{ 0 , 2 } , { 0 , 3 }
} ;
if ( ( V_1 -> V_48 == 0x40700E11 ) || ( V_1 -> V_48 == 0x40800E11 ) ||
( V_1 -> V_48 == 0x40820E11 ) || ( V_1 -> V_48 == 0x40830E11 ) )
goto V_522;
if ( F_246 ( V_1 -> V_24 , V_523 ) ) {
V_80 = F_247 ( V_1 -> V_24 , V_521 , 4 ) ;
if ( ! V_80 ) {
V_1 -> V_50 [ 0 ] = V_521 [ 0 ] . V_524 ;
V_1 -> V_50 [ 1 ] = V_521 [ 1 ] . V_524 ;
V_1 -> V_50 [ 2 ] = V_521 [ 2 ] . V_524 ;
V_1 -> V_50 [ 3 ] = V_521 [ 3 ] . V_524 ;
V_1 -> V_525 = 1 ;
return;
}
if ( V_80 > 0 ) {
F_154 ( & V_1 -> V_24 -> V_25 ,
L_126 , V_80 ) ;
goto V_522;
} else {
F_154 ( & V_1 -> V_24 -> V_25 ,
L_127 , V_80 ) ;
goto V_522;
}
}
if ( F_246 ( V_1 -> V_24 , V_526 ) ) {
if ( ! F_248 ( V_1 -> V_24 ) )
V_1 -> V_527 = 1 ;
else
F_154 ( & V_1 -> V_24 -> V_25 , L_128 ) ;
}
V_522:
#endif
V_1 -> V_50 [ V_1 -> V_51 ] = V_1 -> V_24 -> V_447 ;
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
for ( V_20 = 0 ; V_20 < F_44 ( V_532 ) ; V_20 ++ )
if ( * V_48 == V_532 [ V_20 ] . V_48 )
return V_20 ;
F_154 ( & V_24 -> V_25 , L_129 ,
* V_48 ) ;
return - V_533 ;
}
static inline bool F_250 ( T_1 * V_1 )
{
T_38 V_534 ;
( void ) F_251 ( V_1 -> V_24 , V_535 , & V_534 ) ;
return ( ( V_534 & V_536 ) == 0 ) ;
}
static int F_252 ( struct V_475 * V_24 ,
unsigned long * V_537 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_480 ; V_20 ++ )
if ( F_235 ( V_24 , V_20 ) & V_538 ) {
* V_537 = F_253 ( V_24 , V_20 ) ;
F_87 ( & V_24 -> V_25 , L_130 ,
* V_537 ) ;
return 0 ;
}
F_154 ( & V_24 -> V_25 , L_131 ) ;
return - V_533 ;
}
static int F_254 ( struct V_475 * V_24 ,
void T_34 * V_208 , int V_539 )
#define F_255 1
#define F_256 0
{
int V_20 , V_540 ;
T_11 V_541 ;
if ( V_539 )
V_540 = V_542 ;
else
V_540 = V_543 ;
for ( V_20 = 0 ; V_20 < V_540 ; V_20 ++ ) {
V_541 = F_110 ( V_208 + V_544 ) ;
if ( V_539 ) {
if ( V_541 == V_545 )
return 0 ;
} else {
if ( V_541 != V_545 )
return 0 ;
}
F_257 ( V_546 ) ;
}
F_154 ( & V_24 -> V_25 , L_132 ) ;
return - V_533 ;
}
static int F_258 ( struct V_475 * V_24 , void T_34 * V_208 ,
T_11 * V_547 , T_39 * V_548 ,
T_39 * V_549 )
{
* V_547 = F_110 ( V_208 + V_550 ) ;
* V_549 = F_110 ( V_208 + V_551 ) ;
* V_547 &= ( T_11 ) 0x0000ffff ;
* V_548 = F_234 ( V_24 , * V_547 ) ;
if ( * V_548 == - 1 ) {
F_154 ( & V_24 -> V_25 , L_133
L_134 , * V_547 ) ;
return - V_533 ;
}
return 0 ;
}
static int F_259 ( T_1 * V_1 )
{
T_39 V_549 ;
T_11 V_547 ;
T_39 V_548 ;
T_11 V_494 ;
int V_280 ;
V_280 = F_258 ( V_1 -> V_24 , V_1 -> V_208 , & V_547 ,
& V_548 , & V_549 ) ;
if ( V_280 )
return V_280 ;
V_1 -> V_203 = F_176 ( F_253 ( V_1 -> V_24 ,
V_548 ) + V_549 , sizeof( V_1 -> V_203 ) ) ;
if ( ! V_1 -> V_203 )
return - V_84 ;
V_280 = F_260 ( V_1 -> V_203 ) ;
if ( V_280 )
return V_280 ;
V_494 = F_110 ( & V_1 -> V_203 -> V_497 ) ;
V_1 -> V_498 = F_176 ( F_253 ( V_1 -> V_24 ,
V_548 ) + V_549 + V_494 ,
sizeof( * V_1 -> V_498 ) ) ;
if ( ! V_1 -> V_498 )
return - V_84 ;
return 0 ;
}
static void F_261 ( struct V_101 * V_1 )
{
V_1 -> V_443 = F_110 ( & ( V_1 -> V_203 -> V_552 ) ) ;
if ( V_446 && V_1 -> V_443 > 32 )
V_1 -> V_443 = 32 ;
if ( V_1 -> V_443 < 16 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_135
L_136
L_137 ,
V_1 -> V_443 ) ;
V_1 -> V_443 = 16 ;
}
}
static void F_262 ( T_1 * V_1 )
{
F_261 ( V_1 ) ;
V_1 -> V_19 = V_1 -> V_443 - 4 - V_553 ;
V_1 -> V_297 = F_110 ( & ( V_1 -> V_203 -> V_554 ) ) ;
V_1 -> V_30 = 31 ;
if ( V_1 -> V_297 > 512 ) {
V_1 -> V_30 = 32 ;
V_1 -> V_21 = V_1 -> V_297 - V_1 -> V_30 + 1 ;
V_1 -> V_297 -- ;
} else {
V_1 -> V_297 = 31 ;
V_1 -> V_21 = 0 ;
}
}
static inline bool F_263 ( T_1 * V_1 )
{
if ( ! F_264 ( V_1 -> V_203 -> V_469 , L_138 , 4 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_139 ) ;
return false ;
}
return true ;
}
static inline void F_265 ( T_1 * V_1 )
{
#ifdef F_266
T_11 V_555 ;
V_555 = F_110 ( & ( V_1 -> V_203 -> V_556 ) ) ;
V_555 |= 0x100 ;
F_112 ( V_555 , & ( V_1 -> V_203 -> V_556 ) ) ;
#endif
}
static inline void F_267 ( T_1 * V_1 )
{
T_11 V_557 ;
V_137 V_558 ;
if ( V_1 -> V_48 != 0x3225103C )
return;
V_557 = F_110 ( V_1 -> V_208 + V_559 ) ;
V_557 |= 0x8000 ;
F_112 ( V_557 , V_1 -> V_208 + V_559 ) ;
F_268 ( V_1 -> V_24 , V_560 , & V_558 ) ;
V_558 |= 0x1 ;
F_269 ( V_1 -> V_24 , V_560 , V_558 ) ;
}
static int F_270 ( T_1 * V_1 )
{
int V_561 , V_80 ;
V_561 = F_249 ( V_1 -> V_24 , & V_1 -> V_48 ) ;
if ( V_561 < 0 )
return - V_533 ;
V_1 -> V_47 = V_532 [ V_561 ] . V_47 ;
V_1 -> V_386 = * ( V_532 [ V_561 ] . V_386 ) ;
if ( F_250 ( V_1 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_140 ) ;
return - V_533 ;
}
F_271 ( V_1 -> V_24 , V_562 |
V_563 | V_564 ) ;
V_80 = F_272 ( V_1 -> V_24 ) ;
if ( V_80 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_141 ) ;
return V_80 ;
}
V_80 = F_273 ( V_1 -> V_24 , L_142 ) ;
if ( V_80 ) {
F_154 ( & V_1 -> V_24 -> V_25 ,
L_143 ) ;
return V_80 ;
}
F_87 ( & V_1 -> V_24 -> V_25 , L_144 , V_1 -> V_24 -> V_447 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_145 , V_1 -> V_48 ) ;
F_244 ( V_1 ) ;
V_80 = F_252 ( V_1 -> V_24 , & V_1 -> V_565 ) ;
if ( V_80 )
goto V_566;
V_1 -> V_208 = F_176 ( V_1 -> V_565 , 0x250 ) ;
if ( ! V_1 -> V_208 ) {
V_80 = - V_84 ;
goto V_566;
}
V_80 = F_254 ( V_1 -> V_24 , V_1 -> V_208 , F_255 ) ;
if ( V_80 )
goto V_566;
V_80 = F_259 ( V_1 ) ;
if ( V_80 )
goto V_566;
F_233 ( V_1 ) ;
F_262 ( V_1 ) ;
if ( ! F_263 ( V_1 ) ) {
V_80 = - V_533 ;
goto V_566;
}
F_265 ( V_1 ) ;
F_267 ( V_1 ) ;
V_80 = F_274 ( V_1 ) ;
if ( V_80 )
goto V_566;
F_243 ( V_1 ) ;
return 0 ;
V_566:
if ( V_1 -> V_498 )
F_275 ( V_1 -> V_498 ) ;
if ( V_1 -> V_203 )
F_275 ( V_1 -> V_203 ) ;
if ( V_1 -> V_208 )
F_275 ( V_1 -> V_208 ) ;
F_276 ( V_1 -> V_24 ) ;
return V_80 ;
}
static int F_277 ( struct V_475 * V_24 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_567 ; V_20 ++ ) {
if ( ! V_267 [ V_20 ] ) {
T_1 * V_1 ;
V_1 = F_127 ( sizeof( T_1 ) , V_23 ) ;
if ( ! V_1 )
goto V_568;
V_267 [ V_20 ] = V_1 ;
return V_20 ;
}
}
F_154 ( & V_24 -> V_25 , L_146
L_147 , V_567 ) ;
return - 1 ;
V_568:
F_154 ( & V_24 -> V_25 , L_148 ) ;
return - 1 ;
}
static void F_278 ( T_1 * V_1 )
{
int V_20 ;
V_267 [ V_1 -> V_62 ] = NULL ;
for ( V_20 = 0 ; V_20 < V_1 -> V_64 + 1 ; V_20 ++ )
if ( V_1 -> V_141 [ V_20 ] != NULL )
F_160 ( V_1 -> V_141 [ V_20 ] ) ;
F_15 ( V_1 ) ;
}
static int F_279 ( struct V_475 * V_24 , unsigned char V_569 ,
unsigned char type )
{
typedef struct {
T_40 V_570 ;
T_41 V_181 ;
T_42 V_571 ;
} T_43;
static const T_10 V_572 = sizeof( T_43 ) + sizeof( V_133 ) ;
T_43 * V_156 ;
T_13 V_573 ;
T_28 V_574 , V_411 ;
void T_34 * V_208 ;
int V_20 , V_80 ;
V_208 = F_280 ( F_253 ( V_24 , 0 ) , F_281 ( V_24 , 0 ) ) ;
if ( V_208 == NULL )
return - V_84 ;
V_80 = F_282 ( V_24 , F_283 ( 32 ) ) ;
if ( V_80 ) {
F_275 ( V_208 ) ;
return - V_84 ;
}
V_156 = F_78 ( V_24 , V_572 , & V_573 ) ;
if ( V_156 == NULL ) {
F_275 ( V_208 ) ;
return - V_84 ;
}
V_574 = V_573 ;
V_156 -> V_570 . V_231 = 0 ;
V_156 -> V_570 . V_8 = 0 ;
V_156 -> V_570 . V_29 = 0 ;
V_156 -> V_570 . V_233 . V_33 = V_574 ;
V_156 -> V_570 . V_233 . V_35 = 0 ;
memset ( & V_156 -> V_570 . V_232 . V_334 , 0 , 8 ) ;
V_156 -> V_181 . V_336 = 16 ;
V_156 -> V_181 . Type . Type = V_348 ;
V_156 -> V_181 . Type . V_337 = V_575 ;
V_156 -> V_181 . Type . V_227 = V_228 ;
V_156 -> V_181 . V_339 = 0 ;
V_156 -> V_181 . V_335 [ 0 ] = V_569 ;
V_156 -> V_181 . V_335 [ 1 ] = type ;
memset ( & V_156 -> V_181 . V_335 [ 2 ] , 0 , 14 ) ;
V_156 -> V_571 . V_34 . V_33 = V_574 + sizeof( T_43 ) ;
V_156 -> V_571 . V_34 . V_35 = 0 ;
V_156 -> V_571 . V_37 = sizeof( V_133 ) ;
F_112 ( V_574 , V_208 + V_576 ) ;
for ( V_20 = 0 ; V_20 < 10 ; V_20 ++ ) {
V_411 = F_110 ( V_208 + V_577 ) ;
if ( ( V_411 & ~ 3 ) == V_574 )
break;
F_257 ( V_578 ) ;
}
F_275 ( V_208 ) ;
if ( V_20 == 10 ) {
F_18 ( & V_24 -> V_25 ,
L_149 ,
V_569 , type ) ;
return - V_579 ;
}
F_79 ( V_24 , V_572 , V_156 , V_573 ) ;
if ( V_411 & 2 ) {
F_18 ( & V_24 -> V_25 , L_150 ,
V_569 , type ) ;
return - V_276 ;
}
F_174 ( & V_24 -> V_25 , L_151 ,
V_569 , type ) ;
return 0 ;
}
static int F_284 ( struct V_475 * V_24 ,
void * T_34 V_208 , T_11 V_580 )
{
T_38 V_581 ;
int V_56 ;
if ( V_580 ) {
F_174 ( & V_24 -> V_25 , L_152 ) ;
F_112 ( V_580 , V_208 + V_209 ) ;
} else {
V_56 = F_246 ( V_24 , V_582 ) ;
if ( V_56 == 0 ) {
F_18 ( & V_24 -> V_25 ,
L_153
L_154 ) ;
return - V_533 ;
}
F_174 ( & V_24 -> V_25 , L_155 ) ;
F_251 ( V_24 , V_56 + V_583 , & V_581 ) ;
V_581 &= ~ V_584 ;
V_581 |= V_585 ;
F_285 ( V_24 , V_56 + V_583 , V_581 ) ;
F_257 ( 500 ) ;
V_581 &= ~ V_584 ;
V_581 |= V_586 ;
F_285 ( V_24 , V_56 + V_583 , V_581 ) ;
F_257 ( 500 ) ;
}
return 0 ;
}
static void F_286 ( char * V_587 , int V_40 )
{
memset ( V_587 , 0 , V_40 ) ;
strncpy ( V_587 , L_156 V_588 , V_40 - 1 ) ;
}
static int F_260 ( T_37 T_34 * V_203 )
{
char * V_587 ;
int V_20 , V_331 = sizeof( V_203 -> V_587 ) ;
V_587 = F_17 ( V_331 , V_23 ) ;
if ( ! V_587 )
return - V_84 ;
F_286 ( V_587 , V_331 ) ;
for ( V_20 = 0 ; V_20 < V_331 ; V_20 ++ )
F_117 ( V_587 [ V_20 ] , & V_203 -> V_587 [ V_20 ] ) ;
F_15 ( V_587 ) ;
return 0 ;
}
static void F_287 ( T_37 T_34 * V_203 ,
unsigned char * V_589 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < sizeof( V_203 -> V_587 ) ; V_20 ++ )
V_589 [ V_20 ] = F_115 ( & V_203 -> V_587 [ V_20 ] ) ;
}
static int F_288 ( T_37 T_34 * V_203 )
{
char * V_589 , * V_590 ;
int V_280 , V_331 = sizeof( V_203 -> V_587 ) ;
V_590 = F_17 ( 2 * V_331 , V_23 ) ;
if ( ! V_590 )
return - V_84 ;
V_589 = V_590 + V_331 ;
F_286 ( V_590 , V_331 ) ;
F_287 ( V_203 , V_589 ) ;
V_280 = ! memcmp ( V_589 , V_590 , V_331 ) ;
F_15 ( V_590 ) ;
return V_280 ;
}
static int F_289 ( struct V_475 * V_24 )
{
T_39 V_549 ;
T_11 V_547 ;
T_39 V_548 ;
void T_34 * V_208 ;
unsigned long V_565 ;
T_11 V_591 ;
int V_280 ;
T_37 T_34 * V_203 ;
T_11 V_580 ;
T_11 V_48 ;
T_38 V_592 ;
F_249 ( V_24 , & V_48 ) ;
if ( ! F_46 ( V_48 ) ) {
F_154 ( & V_24 -> V_25 , L_157
L_158 ) ;
return - V_533 ;
}
if ( ! F_43 ( V_48 ) )
return - V_593 ;
F_251 ( V_24 , 4 , & V_592 ) ;
F_290 ( V_24 ) ;
F_291 ( V_24 ) ;
V_280 = F_252 ( V_24 , & V_565 ) ;
if ( V_280 )
return V_280 ;
V_208 = F_176 ( V_565 , 0x250 ) ;
if ( ! V_208 )
return - V_84 ;
V_280 = F_258 ( V_24 , V_208 , & V_547 ,
& V_548 , & V_549 ) ;
if ( V_280 )
goto V_594;
V_203 = F_176 ( F_253 ( V_24 ,
V_548 ) + V_549 , sizeof( * V_203 ) ) ;
if ( ! V_203 ) {
V_280 = - V_84 ;
goto V_594;
}
V_280 = F_260 ( V_203 ) ;
if ( V_280 )
goto V_594;
V_591 = F_110 ( & V_203 -> V_591 ) ;
V_580 = V_591 & V_595 ;
if ( V_580 ) {
V_580 = V_596 ;
} else {
V_580 = V_591 & V_597 ;
if ( V_580 ) {
F_154 ( & V_24 -> V_25 , L_159
L_160
L_161
L_162 ) ;
V_280 = - V_593 ;
goto V_598;
}
}
V_280 = F_284 ( V_24 , V_208 , V_580 ) ;
if ( V_280 )
goto V_598;
F_292 ( V_24 ) ;
V_280 = F_272 ( V_24 ) ;
if ( V_280 ) {
F_154 ( & V_24 -> V_25 , L_163 ) ;
goto V_598;
}
F_285 ( V_24 , 4 , V_592 ) ;
F_257 ( V_599 ) ;
F_174 ( & V_24 -> V_25 , L_164 ) ;
V_280 = F_254 ( V_24 , V_208 , F_256 ) ;
if ( V_280 ) {
F_154 ( & V_24 -> V_25 , L_165
L_166 ) ;
V_280 = - V_593 ;
goto V_598;
}
V_280 = F_254 ( V_24 , V_208 , F_255 ) ;
if ( V_280 ) {
F_154 ( & V_24 -> V_25 ,
L_167
L_168 ) ;
goto V_598;
}
V_280 = F_288 ( V_208 ) ;
if ( V_280 < 0 )
goto V_598;
if ( V_280 ) {
F_154 ( & V_24 -> V_25 , L_169
L_170 ) ;
V_280 = - V_593 ;
} else {
F_174 ( & V_24 -> V_25 , L_171 ) ;
}
V_598:
F_275 ( V_203 ) ;
V_594:
F_275 ( V_208 ) ;
return V_280 ;
}
static int F_293 ( struct V_475 * V_24 )
{
int V_280 , V_20 ;
if ( ! V_446 )
return 0 ;
V_280 = F_289 ( V_24 ) ;
if ( V_280 == - V_593 )
return V_280 ;
if ( V_280 )
return - V_533 ;
F_154 ( & V_24 -> V_25 , L_172 ) ;
for ( V_20 = 0 ; V_20 < V_600 ; V_20 ++ ) {
if ( F_294 ( V_24 ) == 0 )
break;
else
F_154 ( & V_24 -> V_25 , L_173 ,
( V_20 < V_600 - 1 ?
L_174 : L_175 ) ) ;
F_257 ( V_601 ) ;
}
return 0 ;
}
static int F_295 ( T_1 * V_1 )
{
V_1 -> V_128 = F_17 ( F_296 ( V_1 -> V_19 ) *
sizeof( unsigned long ) , V_23 ) ;
V_1 -> V_129 = F_78 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( T_2 ) ,
& ( V_1 -> V_130 ) ) ;
V_1 -> V_132 = F_78 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( V_133 ) ,
& ( V_1 -> V_134 ) ) ;
if ( ( V_1 -> V_128 == NULL )
|| ( V_1 -> V_129 == NULL )
|| ( V_1 -> V_132 == NULL ) ) {
F_18 ( & V_1 -> V_24 -> V_25 , L_176 ) ;
return - V_84 ;
}
return 0 ;
}
static int F_297 ( T_1 * V_1 )
{
int V_20 ;
V_1 -> V_423 = F_127 ( V_1 -> V_443 *
sizeof( struct V_416 * ) , V_23 ) ;
if ( ! V_1 -> V_423 )
return - V_84 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_19 ; V_20 ++ ) {
V_1 -> V_423 [ V_20 ] = F_17 ( sizeof( struct V_416 ) *
V_1 -> V_297 , V_23 ) ;
if ( V_1 -> V_423 [ V_20 ] == NULL ) {
F_18 ( & V_1 -> V_24 -> V_25 , L_177
L_178 ) ;
return - V_84 ;
}
}
return 0 ;
}
static void F_298 ( T_1 * V_1 )
{
int V_20 ;
if ( V_1 -> V_423 ) {
for ( V_20 = 0 ; V_20 < V_1 -> V_19 ; V_20 ++ )
F_15 ( V_1 -> V_423 [ V_20 ] ) ;
F_15 ( V_1 -> V_423 ) ;
}
}
static void F_299 ( T_1 * V_1 )
{
F_15 ( V_1 -> V_128 ) ;
if ( V_1 -> V_129 )
F_79 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( T_2 ) ,
V_1 -> V_129 , V_1 -> V_130 ) ;
if ( V_1 -> V_132 )
F_79 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( V_133 ) ,
V_1 -> V_132 , V_1 -> V_134 ) ;
}
static int F_300 ( T_1 * V_1 ,
T_36 (* F_301)( int , void * ) ,
T_36 (* F_302)( int , void * ) )
{
if ( V_1 -> V_525 || V_1 -> V_527 ) {
if ( ! F_303 ( V_1 -> V_50 [ V_1 -> V_51 ] , F_301 ,
0 , V_1 -> V_46 , V_1 ) )
return 0 ;
F_18 ( & V_1 -> V_24 -> V_25 , L_179
L_180 , V_1 -> V_50 [ V_1 -> V_51 ] ,
V_1 -> V_46 ) ;
return - 1 ;
}
if ( ! F_303 ( V_1 -> V_50 [ V_1 -> V_51 ] , F_302 ,
V_602 , V_1 -> V_46 , V_1 ) )
return 0 ;
F_18 ( & V_1 -> V_24 -> V_25 , L_181 ,
V_1 -> V_50 [ V_1 -> V_51 ] , V_1 -> V_46 ) ;
return - 1 ;
}
static int F_304 ( T_1 * V_1 )
{
if ( F_168 ( V_1 , V_152 , V_603 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_182 ) ;
return - V_276 ;
}
F_174 ( & V_1 -> V_24 -> V_25 , L_183 ) ;
if ( F_254 ( V_1 -> V_24 , V_1 -> V_208 , F_256 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_184 ) ;
return - 1 ;
}
F_174 ( & V_1 -> V_24 -> V_25 , L_185 ) ;
if ( F_254 ( V_1 -> V_24 , V_1 -> V_208 , F_255 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_186
L_187 ) ;
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
if ( V_1 -> V_442 )
F_79 ( V_1 -> V_24 , V_1 -> V_443 * sizeof( V_138 ) ,
V_1 -> V_442 , V_1 -> V_511 ) ;
if ( V_1 -> V_498 )
F_275 ( V_1 -> V_498 ) ;
if ( V_1 -> V_203 )
F_275 ( V_1 -> V_203 ) ;
if ( V_1 -> V_208 )
F_275 ( V_1 -> V_208 ) ;
F_309 ( V_1 -> V_289 , V_1 -> V_46 ) ;
F_67 ( V_1 ) ;
F_276 ( V_1 -> V_24 ) ;
F_15 ( V_1 ) ;
V_267 [ V_62 ] = NULL ;
}
static int F_310 ( struct V_475 * V_24 , const struct V_604 * V_605 )
{
int V_20 ;
int V_22 = 0 ;
int V_280 ;
int V_606 = 0 ;
int V_607 , V_318 ;
T_29 * V_302 ;
T_1 * V_1 ;
unsigned long V_13 ;
V_280 = F_293 ( V_24 ) ;
if ( V_280 ) {
if ( V_280 != - V_593 )
return V_280 ;
V_606 = 1 ;
V_280 = 0 ;
}
V_608:
V_20 = F_277 ( V_24 ) ;
if ( V_20 < 0 )
return - 1 ;
V_1 = V_267 [ V_20 ] ;
V_1 -> V_24 = V_24 ;
V_1 -> V_453 = 1 ;
V_1 -> V_51 = V_515 ? V_609 : V_610 ;
F_76 ( & V_1 -> V_389 ) ;
F_76 ( & V_1 -> V_15 ) ;
F_311 ( & V_1 -> V_454 ) ;
if ( F_270 ( V_1 ) != 0 )
goto V_611;
sprintf ( V_1 -> V_46 , L_188 , V_20 ) ;
V_1 -> V_62 = V_20 ;
if ( V_553 < 2 )
V_553 = 2 ;
if ( V_553 > 16 )
V_553 = 16 ;
F_312 ( & V_1 -> V_104 ) ;
if ( F_63 ( V_1 ) )
goto V_612;
if ( ! F_313 ( V_24 , F_283 ( 64 ) ) )
V_607 = 1 ;
else if ( ! F_313 ( V_24 , F_283 ( 32 ) ) )
V_607 = 0 ;
else {
F_18 ( & V_1 -> V_24 -> V_25 , L_189 ) ;
goto V_613;
}
if ( V_20 < V_614 )
V_1 -> V_289 = V_615 + V_20 ;
V_280 = F_314 ( V_1 -> V_289 , V_1 -> V_46 ) ;
if ( V_280 == - V_58 || V_280 == - V_82 ) {
F_18 ( & V_1 -> V_24 -> V_25 ,
L_190
L_191 , V_1 -> V_289 , V_1 -> V_46 , V_20 ) ;
goto V_613;
} else {
if ( V_20 >= V_614 )
V_1 -> V_289 = V_280 ;
}
V_1 -> V_386 . V_616 ( V_1 , V_617 ) ;
V_280 = F_300 ( V_1 , F_223 , F_222 ) ;
if ( V_280 )
goto V_618;
F_174 ( & V_1 -> V_24 -> V_25 , L_192 ,
V_1 -> V_46 , V_24 -> V_98 , F_315 ( V_24 ) ,
V_1 -> V_50 [ V_1 -> V_51 ] , V_607 ? L_175 : L_193 ) ;
if ( F_295 ( V_1 ) )
goto V_619;
if ( F_297 ( V_1 ) )
goto V_619;
V_1 -> V_18 = F_16 ( V_1 ,
V_1 -> V_21 , V_1 -> V_19 ) ;
if ( ! V_1 -> V_18 && V_1 -> V_21 > 0 )
goto V_619;
F_316 ( & V_1 -> V_14 ) ;
F_317 ( V_24 , V_1 ) ;
F_318 ( V_1 -> V_128 , V_1 -> V_19 ) ;
V_1 -> V_52 = 0 ;
V_1 -> V_64 = - 1 ;
for ( V_22 = 0 ; V_22 < V_314 ; V_22 ++ ) {
V_1 -> V_63 [ V_22 ] = NULL ;
V_1 -> V_141 [ V_22 ] = NULL ;
}
if ( V_606 ) {
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_1 -> V_386 . V_616 ( V_1 , V_617 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
F_306 ( V_1 -> V_50 [ V_1 -> V_51 ] , V_1 ) ;
V_280 = F_300 ( V_1 , F_221 ,
F_220 ) ;
if ( V_280 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_194
L_195 ) ;
goto V_619;
}
V_280 = F_304 ( V_1 ) ;
if ( V_280 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_196 ) ;
goto V_619;
}
F_174 ( & V_1 -> V_24 -> V_25 , L_197 ) ;
F_174 ( & V_1 -> V_24 -> V_25 ,
L_198 ) ;
V_1 -> V_386 . V_616 ( V_1 , V_620 ) ;
F_257 ( 10000 ) ;
V_1 -> V_386 . V_616 ( V_1 , V_617 ) ;
V_280 = F_288 ( V_1 -> V_203 ) ;
if ( V_280 )
F_174 ( & V_1 -> V_24 -> V_25 ,
L_199 ) ;
F_305 ( V_1 ) ;
V_606 = 0 ;
if ( V_280 )
return - V_533 ;
goto V_608;
}
F_319 ( V_1 ) ;
V_1 -> V_386 . V_616 ( V_1 , V_620 ) ;
V_302 = F_127 ( sizeof( T_29 ) , V_23 ) ;
if ( V_302 == NULL ) {
F_18 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
goto V_619;
}
V_318 = F_137 ( V_1 , V_282 , V_302 ,
sizeof( T_29 ) , 0 , V_152 , V_283 ) ;
if ( V_318 == V_284 ) {
V_1 -> V_49 [ 0 ] = V_302 -> V_285 [ 32 ] ;
V_1 -> V_49 [ 1 ] = V_302 -> V_285 [ 33 ] ;
V_1 -> V_49 [ 2 ] = V_302 -> V_285 [ 34 ] ;
V_1 -> V_49 [ 3 ] = V_302 -> V_285 [ 35 ] ;
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_200
L_201 ) ;
}
F_15 ( V_302 ) ;
F_1 ( V_1 ) ;
V_1 -> V_298 = 8192 ;
F_128 ( V_1 , 1 , 0 ) ;
F_39 ( V_1 ) ;
V_1 -> V_453 = 0 ;
return 1 ;
V_619:
F_299 ( V_1 ) ;
F_298 ( V_1 ) ;
F_14 ( V_1 -> V_18 , V_1 -> V_19 ) ;
F_306 ( V_1 -> V_50 [ V_1 -> V_51 ] , V_1 ) ;
V_618:
F_309 ( V_1 -> V_289 , V_1 -> V_46 ) ;
V_613:
F_67 ( V_1 ) ;
V_612:
F_276 ( V_24 ) ;
V_611:
V_1 -> V_453 = 0 ;
F_317 ( V_24 , NULL ) ;
F_278 ( V_1 ) ;
return - 1 ;
}
static void F_320 ( struct V_475 * V_24 )
{
T_1 * V_1 ;
char * V_621 ;
int V_318 ;
V_1 = F_321 ( V_24 ) ;
V_621 = F_127 ( 4 , V_23 ) ;
if ( ! V_621 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_202 ) ;
return;
}
V_318 = F_137 ( V_1 , V_343 , V_621 ,
4 , 0 , V_152 , V_283 ) ;
F_15 ( V_621 ) ;
if ( V_318 != V_284 )
F_154 ( & V_1 -> V_24 -> V_25 , L_203 ) ;
V_1 -> V_386 . V_616 ( V_1 , V_617 ) ;
F_306 ( V_1 -> V_50 [ V_1 -> V_51 ] , V_1 ) ;
}
static int F_274 ( struct V_101 * V_1 )
{
T_11 V_514 ;
V_514 = F_110 ( & ( V_1 -> V_203 -> V_471 ) ) ;
if ( ! ( V_514 & V_622 ) )
return - V_593 ;
V_1 -> V_443 = F_110 ( & ( V_1 -> V_203 -> V_474 ) ) ;
F_112 ( V_623 , & ( V_1 -> V_203 -> V_204 . V_473 ) ) ;
F_112 ( V_207 , V_1 -> V_208 + V_209 ) ;
F_239 ( V_1 ) ;
F_233 ( V_1 ) ;
if ( ! ( F_110 ( & ( V_1 -> V_203 -> V_472 ) ) & V_623 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_204 ) ;
return - V_533 ;
}
V_1 -> V_3 = V_623 ;
return 0 ;
}
static void F_322 ( struct V_475 * V_24 )
{
T_1 * V_1 ;
int V_20 , V_22 ;
if ( F_321 ( V_24 ) == NULL ) {
F_18 ( & V_24 -> V_25 , L_205 ) ;
return;
}
V_1 = F_321 ( V_24 ) ;
V_20 = V_1 -> V_62 ;
if ( V_267 [ V_20 ] == NULL ) {
F_18 ( & V_24 -> V_25 , L_206 ) ;
return;
}
F_91 ( & V_1 -> V_454 ) ;
F_225 ( V_1 ) ;
F_323 ( V_1 -> V_46 , V_90 ) ;
F_309 ( V_1 -> V_289 , V_1 -> V_46 ) ;
for ( V_22 = 0 ; V_22 < V_314 ; V_22 ++ ) {
struct V_141 * V_142 = V_1 -> V_141 [ V_22 ] ;
if ( V_142 ) {
struct V_327 * V_328 = V_142 -> V_143 ;
if ( V_142 -> V_13 & V_329 ) {
F_72 ( V_1 , V_22 , 1 ) ;
F_166 ( V_142 ) ;
}
if ( V_328 )
F_149 ( V_328 ) ;
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
F_275 ( V_1 -> V_203 ) ;
F_275 ( V_1 -> V_208 ) ;
F_299 ( V_1 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_19 ; V_22 ++ )
F_15 ( V_1 -> V_423 [ V_22 ] ) ;
F_15 ( V_1 -> V_423 ) ;
F_14 ( V_1 -> V_18 , V_1 -> V_19 ) ;
F_15 ( V_1 -> V_6 ) ;
if ( V_1 -> V_442 )
F_79 ( V_1 -> V_24 , V_1 -> V_443 * sizeof( V_138 ) ,
V_1 -> V_442 , V_1 -> V_511 ) ;
F_276 ( V_24 ) ;
F_317 ( V_24 , NULL ) ;
F_67 ( V_1 ) ;
F_92 ( & V_1 -> V_454 ) ;
F_278 ( V_1 ) ;
}
static int T_44 F_325 ( void )
{
int V_80 ;
F_242 ( sizeof( T_2 ) % V_624 ) ;
F_326 (KERN_INFO DRIVER_NAME L_207 ) ;
V_80 = F_327 ( & V_121 ) ;
if ( V_80 )
return V_80 ;
V_103 = F_328 ( F_229 , NULL , L_208 ) ;
if ( F_329 ( V_103 ) ) {
V_80 = F_330 ( V_103 ) ;
goto V_625;
}
V_80 = F_331 ( & V_626 ) ;
if ( V_80 )
goto V_627;
return V_80 ;
V_627:
F_332 ( V_103 ) ;
V_625:
F_333 ( & V_121 ) ;
return V_80 ;
}
static void T_45 F_334 ( void )
{
int V_20 ;
F_335 ( & V_626 ) ;
for ( V_20 = 0 ; V_20 < V_567 ; V_20 ++ ) {
if ( V_267 [ V_20 ] != NULL ) {
F_154 ( & V_267 [ V_20 ] -> V_24 -> V_25 ,
L_209 ) ;
F_322 ( V_267 [ V_20 ] -> V_24 ) ;
}
}
F_332 ( V_103 ) ;
if ( V_90 )
F_323 ( L_15 , NULL ) ;
F_333 ( & V_121 ) ;
}
