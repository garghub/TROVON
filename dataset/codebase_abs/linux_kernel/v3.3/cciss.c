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
static void T_11 F_1 ( T_1 * V_1 )
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
static int F_43 ( T_12 V_48 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < F_44 ( V_96 ) ; V_20 ++ )
if ( V_96 [ V_20 ] == V_48 )
return 0 ;
return 1 ;
}
static int F_45 ( T_12 V_48 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < F_44 ( V_97 ) ; V_20 ++ )
if ( V_97 [ V_20 ] == V_48 )
return 0 ;
return 1 ;
}
static int F_46 ( T_12 V_48 )
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
T_13 V_106 [ 16 ] ;
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
T_14 V_126 , V_127 ;
do {
V_20 = F_74 ( V_1 -> V_128 , V_1 -> V_19 ) ;
if ( V_20 == V_1 -> V_19 )
return NULL ;
} while ( F_75 ( V_20 & ( V_129 - 1 ) ,
V_1 -> V_128 + ( V_20 / V_129 ) ) != 0 );
V_2 = V_1 -> V_130 + V_20 ;
memset ( V_2 , 0 , sizeof( T_2 ) ) ;
V_126 = V_1 -> V_131 + V_20 * sizeof( T_2 ) ;
V_2 -> V_132 = V_1 -> V_133 + V_20 ;
memset ( V_2 -> V_132 , 0 , sizeof( V_134 ) ) ;
V_127 = V_1 -> V_135
+ V_20 * sizeof( V_134 ) ;
V_1 -> V_136 ++ ;
V_2 -> V_137 = V_20 ;
F_76 ( & V_2 -> V_10 ) ;
V_2 -> V_5 = ( V_138 ) V_126 ;
V_28 . V_36 = ( V_139 ) V_127 ;
V_2 -> V_140 . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_140 . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_140 . V_37 = sizeof( V_134 ) ;
V_2 -> V_62 = V_1 -> V_62 ;
return V_2 ;
}
static T_2 * F_77 ( T_1 * V_1 )
{
T_2 * V_2 ;
T_4 V_28 ;
T_14 V_126 , V_127 ;
V_2 = ( T_2 * ) F_78 ( V_1 -> V_24 ,
sizeof( T_2 ) , & V_126 ) ;
if ( V_2 == NULL )
return NULL ;
memset ( V_2 , 0 , sizeof( T_2 ) ) ;
V_2 -> V_137 = - 1 ;
V_2 -> V_132 = ( V_134 * )
F_78 ( V_1 -> V_24 , sizeof( V_134 ) ,
& V_127 ) ;
if ( V_2 -> V_132 == NULL ) {
F_79 ( V_1 -> V_24 ,
sizeof( T_2 ) , V_2 , V_126 ) ;
return NULL ;
}
memset ( V_2 -> V_132 , 0 , sizeof( V_134 ) ) ;
F_76 ( & V_2 -> V_10 ) ;
V_2 -> V_5 = ( V_138 ) V_126 ;
V_28 . V_36 = ( V_139 ) V_127 ;
V_2 -> V_140 . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_140 . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_140 . V_37 = sizeof( V_134 ) ;
V_2 -> V_62 = V_1 -> V_62 ;
return V_2 ;
}
static void F_80 ( T_1 * V_1 , T_2 * V_2 )
{
int V_20 ;
V_20 = V_2 - V_1 -> V_130 ;
F_81 ( V_20 & ( V_129 - 1 ) ,
V_1 -> V_128 + ( V_20 / V_129 ) ) ;
V_1 -> V_141 ++ ;
}
static void F_82 ( T_1 * V_1 , T_2 * V_2 )
{
T_4 V_28 ;
V_28 . V_32 . V_33 = V_2 -> V_140 . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_2 -> V_140 . V_34 . V_35 ;
F_79 ( V_1 -> V_24 , sizeof( V_134 ) ,
V_2 -> V_132 , ( T_14 ) V_28 . V_36 ) ;
F_79 ( V_1 -> V_24 , sizeof( T_2 ) , V_2 ,
( T_14 ) F_83 ( V_1 , ( T_12 ) V_2 -> V_5 ) ) ;
}
static inline T_1 * F_84 ( struct V_142 * V_143 )
{
return V_143 -> V_144 -> V_145 ;
}
static inline T_7 * F_85 ( struct V_142 * V_143 )
{
return V_143 -> V_75 ;
}
static int F_86 ( struct V_146 * V_147 , T_15 V_148 )
{
T_1 * V_1 = F_84 ( V_147 -> V_149 ) ;
T_7 * V_63 = F_85 ( V_147 -> V_149 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_26 , V_147 -> V_149 -> V_150 ) ;
if ( V_63 -> V_57 )
return - V_58 ;
if ( V_63 -> V_65 == 0 ) {
if ( F_88 ( V_147 -> V_151 ) != 0 ) {
if ( F_88 ( V_147 -> V_151 ) & 0x0f ) {
return - V_152 ;
} else if ( memcmp ( V_63 -> V_116 , V_153 ,
sizeof( V_63 -> V_116 ) ) ) {
return - V_152 ;
}
}
if ( ! F_89 ( V_154 ) )
return - V_155 ;
}
V_63 -> V_118 ++ ;
V_1 -> V_118 ++ ;
return 0 ;
}
static int F_90 ( struct V_146 * V_147 , T_15 V_148 )
{
int V_73 ;
F_91 ( & V_156 ) ;
V_73 = F_86 ( V_147 , V_148 ) ;
F_92 ( & V_156 ) ;
return V_73 ;
}
static int F_93 ( struct V_142 * V_143 , T_15 V_148 )
{
T_1 * V_1 ;
T_7 * V_63 ;
F_91 ( & V_156 ) ;
V_1 = F_84 ( V_143 ) ;
V_63 = F_85 ( V_143 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_27 , V_143 -> V_150 ) ;
V_63 -> V_118 -- ;
V_1 -> V_118 -- ;
F_92 ( & V_156 ) ;
return 0 ;
}
static int F_94 ( struct V_146 * V_147 , T_15 V_148 ,
unsigned V_157 , unsigned long V_158 )
{
int V_73 ;
F_91 ( & V_156 ) ;
V_73 = F_95 ( V_147 , V_148 , V_157 , V_158 ) ;
F_92 ( & V_156 ) ;
return V_73 ;
}
static int F_96 ( struct V_146 * V_147 , T_15 V_148 ,
unsigned V_157 , unsigned long V_158 )
{
switch ( V_157 ) {
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
case V_173 :
return F_94 ( V_147 , V_148 , V_157 , V_158 ) ;
case V_174 :
return F_97 ( V_147 , V_148 , V_157 , V_158 ) ;
case V_175 :
return F_98 ( V_147 , V_148 , V_157 , V_158 ) ;
default:
return - V_176 ;
}
}
static int F_97 ( struct V_146 * V_147 , T_15 V_148 ,
unsigned V_157 , unsigned long V_158 )
{
T_16 T_9 * V_177 =
( T_16 T_9 * ) V_158 ;
T_17 V_178 ;
T_17 T_9 * V_179 = F_99 ( sizeof( V_178 ) ) ;
int V_80 ;
T_12 V_180 ;
V_80 = 0 ;
V_80 |=
F_38 ( & V_178 . V_181 , & V_177 -> V_181 ,
sizeof( V_178 . V_181 ) ) ;
V_80 |=
F_38 ( & V_178 . V_182 , & V_177 -> V_182 ,
sizeof( V_178 . V_182 ) ) ;
V_80 |=
F_38 ( & V_178 . V_183 , & V_177 -> V_183 ,
sizeof( V_178 . V_183 ) ) ;
V_80 |= F_100 ( V_178 . V_184 , & V_177 -> V_184 ) ;
V_80 |= F_100 ( V_180 , & V_177 -> V_77 ) ;
V_178 . V_77 = F_101 ( V_180 ) ;
V_80 |= F_102 ( V_179 , & V_178 , sizeof( V_178 ) ) ;
if ( V_80 )
return - V_85 ;
V_80 = F_94 ( V_147 , V_148 , V_185 , ( unsigned long ) V_179 ) ;
if ( V_80 )
return V_80 ;
V_80 |=
F_103 ( & V_177 -> V_183 , & V_179 -> V_183 ,
sizeof( V_177 -> V_183 ) ) ;
if ( V_80 )
return - V_85 ;
return V_80 ;
}
static int F_98 ( struct V_146 * V_147 , T_15 V_148 ,
unsigned V_157 , unsigned long V_158 )
{
T_18 T_9 * V_177 =
( T_18 T_9 * ) V_158 ;
T_19 V_178 ;
T_19 T_9 * V_179 =
F_99 ( sizeof( V_178 ) ) ;
int V_80 ;
T_12 V_180 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_80 = 0 ;
V_80 |=
F_38 ( & V_178 . V_181 , & V_177 -> V_181 ,
sizeof( V_178 . V_181 ) ) ;
V_80 |=
F_38 ( & V_178 . V_182 , & V_177 -> V_182 ,
sizeof( V_178 . V_182 ) ) ;
V_80 |=
F_38 ( & V_178 . V_183 , & V_177 -> V_183 ,
sizeof( V_178 . V_183 ) ) ;
V_80 |= F_100 ( V_178 . V_184 , & V_177 -> V_184 ) ;
V_80 |= F_100 ( V_178 . V_186 , & V_177 -> V_186 ) ;
V_80 |= F_100 ( V_180 , & V_177 -> V_77 ) ;
V_178 . V_77 = F_101 ( V_180 ) ;
V_80 |= F_102 ( V_179 , & V_178 , sizeof( V_178 ) ) ;
if ( V_80 )
return - V_85 ;
V_80 = F_94 ( V_147 , V_148 , V_187 , ( unsigned long ) V_179 ) ;
if ( V_80 )
return V_80 ;
V_80 |=
F_103 ( & V_177 -> V_183 , & V_179 -> V_183 ,
sizeof( V_177 -> V_183 ) ) ;
if ( V_80 )
return - V_85 ;
return V_80 ;
}
static int F_104 ( struct V_146 * V_147 , struct V_188 * V_189 )
{
T_7 * V_63 = F_85 ( V_147 -> V_149 ) ;
if ( ! V_63 -> V_190 )
return - V_152 ;
V_189 -> V_65 = V_63 -> V_65 ;
V_189 -> V_191 = V_63 -> V_191 ;
V_189 -> V_190 = V_63 -> V_190 ;
return 0 ;
}
static void F_105 ( T_1 * V_1 , T_2 * V_2 )
{
if ( V_2 -> V_132 -> V_192 == V_193 &&
V_2 -> V_132 -> V_194 != V_195 )
( void ) F_106 ( V_1 , V_2 ) ;
}
static int F_107 ( T_1 * V_1 , void T_9 * V_196 )
{
T_20 V_197 ;
if ( ! V_196 )
return - V_82 ;
V_197 . V_198 = F_108 ( V_1 -> V_24 -> V_120 ) ;
V_197 . V_120 = V_1 -> V_24 -> V_120 -> V_199 ;
V_197 . V_200 = V_1 -> V_24 -> V_201 ;
V_197 . V_48 = V_1 -> V_48 ;
if ( F_102 ( V_196 , & V_197 , sizeof( T_20 ) ) )
return - V_85 ;
return 0 ;
}
static int F_109 ( T_1 * V_1 , void T_9 * V_196 )
{
T_21 V_202 ;
if ( ! V_196 )
return - V_82 ;
V_202 . V_203 = F_110 ( & V_1 -> V_204 -> V_205 . V_206 ) ;
V_202 . V_102 = F_110 ( & V_1 -> V_204 -> V_205 . V_207 ) ;
if ( F_102
( V_196 , & V_202 , sizeof( T_21 ) ) )
return - V_85 ;
return 0 ;
}
static int F_111 ( T_1 * V_1 , void T_9 * V_196 )
{
T_21 V_202 ;
unsigned long V_13 ;
int V_20 ;
if ( ! V_196 )
return - V_82 ;
if ( ! F_89 ( V_154 ) )
return - V_155 ;
if ( F_38 ( & V_202 , V_196 , sizeof( V_202 ) ) )
return - V_85 ;
if ( ( V_202 . V_203 == 0 ) && ( V_202 . V_102 == 0 ) )
return - V_82 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
F_112 ( V_202 . V_203 , & ( V_1 -> V_204 -> V_205 . V_206 ) ) ;
F_112 ( V_202 . V_102 , & ( V_1 -> V_204 -> V_205 . V_207 ) ) ;
F_112 ( V_208 , V_1 -> V_209 + V_210 ) ;
for ( V_20 = 0 ; V_20 < V_211 ; V_20 ++ ) {
if ( ! ( F_110 ( V_1 -> V_209 + V_210 ) & V_208 ) )
break;
F_113 ( 1000 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_20 >= V_211 )
return - V_212 ;
return 0 ;
}
static int F_114 ( T_1 * V_1 , void T_9 * V_196 )
{
T_22 V_213 ;
int V_20 ;
if ( ! V_196 )
return - V_82 ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
V_213 [ V_20 ] = F_115 ( & V_1 -> V_204 -> V_214 [ V_20 ] ) ;
if ( F_102 ( V_196 , V_213 , sizeof( T_22 ) ) )
return - V_85 ;
return 0 ;
}
static int F_116 ( T_1 * V_1 , void T_9 * V_196 )
{
T_22 V_213 ;
unsigned long V_13 ;
int V_20 ;
if ( ! V_196 )
return - V_82 ;
if ( ! F_89 ( V_154 ) )
return - V_155 ;
if ( F_38 ( V_213 , V_196 , sizeof( T_22 ) ) )
return - V_85 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
F_117 ( V_213 [ V_20 ] , & V_1 -> V_204 -> V_214 [ V_20 ] ) ;
F_112 ( V_208 , V_1 -> V_209 + V_210 ) ;
for ( V_20 = 0 ; V_20 < V_211 ; V_20 ++ ) {
if ( ! ( F_110 ( V_1 -> V_209 + V_210 ) & V_208 ) )
break;
F_113 ( 1000 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_20 >= V_211 )
return - V_212 ;
return 0 ;
}
static int F_118 ( T_1 * V_1 , void T_9 * V_196 )
{
T_23 V_215 ;
if ( ! V_196 )
return - V_82 ;
V_215 = F_110 ( & V_1 -> V_204 -> V_216 ) ;
if ( F_102 ( V_196 , & V_215 , sizeof( T_23 ) ) )
return - V_85 ;
return 0 ;
}
static int F_119 ( T_1 * V_1 , void T_9 * V_196 )
{
T_24 V_217 ;
if ( ! V_196 )
return - V_82 ;
V_217 = F_110 ( & V_1 -> V_204 -> V_217 ) ;
if ( F_102 ( V_196 , & V_217 , sizeof( T_24 ) ) )
return - V_85 ;
return 0 ;
}
static int F_120 ( T_1 * V_1 , void T_9 * V_196 )
{
T_25 V_218 ;
if ( ! V_196 )
return - V_82 ;
memcpy ( V_218 , V_1 -> V_49 , 4 ) ;
if ( F_102
( V_196 , V_218 , sizeof( T_25 ) ) )
return - V_85 ;
return 0 ;
}
static int F_121 ( T_1 * V_1 , void T_9 * V_196 )
{
T_26 V_219 = V_220 ;
if ( ! V_196 )
return - V_82 ;
if ( F_102 ( V_196 , & V_219 , sizeof( T_26 ) ) )
return - V_85 ;
return 0 ;
}
static int F_122 ( T_1 * V_1 ,
struct V_142 * V_143 , void T_9 * V_196 )
{
T_27 V_221 ;
T_7 * V_63 = F_85 ( V_143 ) ;
if ( ! V_196 )
return - V_82 ;
memcpy ( & V_221 . V_116 , V_63 -> V_116 , sizeof( V_221 . V_116 ) ) ;
V_221 . V_222 = V_63 -> V_118 ;
V_221 . V_223 = 0 ;
if ( F_102 ( V_196 , & V_221 , sizeof( T_27 ) ) )
return - V_85 ;
return 0 ;
}
static int F_123 ( T_1 * V_1 , void T_9 * V_196 )
{
T_17 V_224 ;
T_2 * V_2 ;
char * V_225 = NULL ;
T_4 V_28 ;
F_124 ( V_226 ) ;
if ( ! V_196 )
return - V_82 ;
if ( ! F_89 ( V_227 ) )
return - V_155 ;
if ( F_38
( & V_224 , V_196 , sizeof( T_17 ) ) )
return - V_85 ;
if ( ( V_224 . V_184 < 1 ) &&
( V_224 . V_182 . Type . V_228 != V_229 ) ) {
return - V_82 ;
}
if ( V_224 . V_184 > 0 ) {
V_225 = F_17 ( V_224 . V_184 , V_23 ) ;
if ( V_225 == NULL )
return - V_85 ;
}
if ( V_224 . V_182 . Type . V_228 == V_230 ) {
if ( F_38 ( V_225 , V_224 . V_77 , V_224 . V_184 ) ) {
F_15 ( V_225 ) ;
return - V_85 ;
}
} else {
memset ( V_225 , 0 , V_224 . V_184 ) ;
}
V_2 = F_77 ( V_1 ) ;
if ( ! V_2 ) {
F_15 ( V_225 ) ;
return - V_84 ;
}
V_2 -> V_11 = V_231 ;
V_2 -> V_7 . V_232 = 0 ;
if ( V_224 . V_184 > 0 ) {
V_2 -> V_7 . V_8 = 1 ;
V_2 -> V_7 . V_29 = 1 ;
} else {
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_7 . V_29 = 0 ;
}
V_2 -> V_7 . V_233 = V_224 . V_181 ;
V_2 -> V_7 . V_234 . V_33 = V_2 -> V_5 ;
V_2 -> V_182 = V_224 . V_182 ;
if ( V_224 . V_184 > 0 ) {
V_28 . V_36 = F_22 ( V_1 -> V_24 , V_225 ,
V_224 . V_184 , V_235 ) ;
V_2 -> V_31 [ 0 ] . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_31 [ 0 ] . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_31 [ 0 ] . V_37 = V_224 . V_184 ;
V_2 -> V_31 [ 0 ] . V_41 = 0 ;
}
V_2 -> V_236 = & V_226 ;
F_10 ( V_1 , V_2 ) ;
F_125 ( & V_226 ) ;
V_28 . V_32 . V_33 = V_2 -> V_31 [ 0 ] . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_2 -> V_31 [ 0 ] . V_34 . V_35 ;
F_20 ( V_1 -> V_24 , ( T_14 ) V_28 . V_36 , V_224 . V_184 ,
V_235 ) ;
F_105 ( V_1 , V_2 ) ;
V_224 . V_183 = * ( V_2 -> V_132 ) ;
if ( F_102 ( V_196 , & V_224 , sizeof( T_17 ) ) ) {
F_15 ( V_225 ) ;
F_82 ( V_1 , V_2 ) ;
return - V_85 ;
}
if ( V_224 . V_182 . Type . V_228 == V_237 ) {
if ( F_102 ( V_224 . V_77 , V_225 , V_224 . V_184 ) ) {
F_15 ( V_225 ) ;
F_82 ( V_1 , V_2 ) ;
return - V_85 ;
}
}
F_15 ( V_225 ) ;
F_82 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_126 ( T_1 * V_1 , void T_9 * V_196 )
{
T_19 * V_238 ;
T_2 * V_2 ;
unsigned char * * V_225 = NULL ;
int * V_239 = NULL ;
T_4 V_28 ;
T_28 V_240 = 0 ;
int V_241 = 0 ;
int V_20 ;
F_124 ( V_226 ) ;
V_138 V_242 ;
V_138 V_243 ;
T_28 T_9 * V_244 ;
if ( ! V_196 )
return - V_82 ;
if ( ! F_89 ( V_227 ) )
return - V_155 ;
V_238 = F_17 ( sizeof( * V_238 ) , V_23 ) ;
if ( ! V_238 ) {
V_241 = - V_84 ;
goto V_245;
}
if ( F_38 ( V_238 , V_196 , sizeof( * V_238 ) ) ) {
V_241 = - V_85 ;
goto V_245;
}
if ( ( V_238 -> V_184 < 1 ) &&
( V_238 -> V_182 . Type . V_228 != V_229 ) ) {
V_241 = - V_82 ;
goto V_245;
}
if ( V_238 -> V_186 > V_246 ) {
V_241 = - V_82 ;
goto V_245;
}
if ( V_238 -> V_184 > V_238 -> V_186 * V_247 ) {
V_241 = - V_82 ;
goto V_245;
}
V_225 = F_127 ( V_247 * sizeof( char * ) , V_23 ) ;
if ( ! V_225 ) {
V_241 = - V_84 ;
goto V_245;
}
V_239 = F_17 ( V_247 * sizeof( int ) , V_23 ) ;
if ( ! V_239 ) {
V_241 = - V_84 ;
goto V_245;
}
V_242 = V_238 -> V_184 ;
V_244 = V_238 -> V_77 ;
while ( V_242 ) {
V_243 = ( V_242 > V_238 -> V_186 ) ? V_238 -> V_186 : V_242 ;
V_239 [ V_240 ] = V_243 ;
V_225 [ V_240 ] = F_17 ( V_243 , V_23 ) ;
if ( V_225 [ V_240 ] == NULL ) {
V_241 = - V_84 ;
goto V_245;
}
if ( V_238 -> V_182 . Type . V_228 == V_230 ) {
if ( F_38 ( V_225 [ V_240 ] , V_244 , V_243 ) ) {
V_241 = - V_85 ;
goto V_245;
}
} else {
memset ( V_225 [ V_240 ] , 0 , V_243 ) ;
}
V_242 -= V_243 ;
V_244 += V_243 ;
V_240 ++ ;
}
V_2 = F_77 ( V_1 ) ;
if ( ! V_2 ) {
V_241 = - V_84 ;
goto V_245;
}
V_2 -> V_11 = V_231 ;
V_2 -> V_7 . V_232 = 0 ;
V_2 -> V_7 . V_8 = V_240 ;
V_2 -> V_7 . V_29 = V_240 ;
V_2 -> V_7 . V_233 = V_238 -> V_181 ;
V_2 -> V_7 . V_234 . V_33 = V_2 -> V_5 ;
V_2 -> V_182 = V_238 -> V_182 ;
for ( V_20 = 0 ; V_20 < V_240 ; V_20 ++ ) {
V_28 . V_36 = F_22 ( V_1 -> V_24 , V_225 [ V_20 ] , V_239 [ V_20 ] ,
V_235 ) ;
V_2 -> V_31 [ V_20 ] . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_31 [ V_20 ] . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_31 [ V_20 ] . V_37 = V_239 [ V_20 ] ;
V_2 -> V_31 [ V_20 ] . V_41 = 0 ;
}
V_2 -> V_236 = & V_226 ;
F_10 ( V_1 , V_2 ) ;
F_125 ( & V_226 ) ;
for ( V_20 = 0 ; V_20 < V_240 ; V_20 ++ ) {
V_28 . V_32 . V_33 = V_2 -> V_31 [ V_20 ] . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_2 -> V_31 [ V_20 ] . V_34 . V_35 ;
F_20 ( V_1 -> V_24 ,
( T_14 ) V_28 . V_36 , V_239 [ V_20 ] ,
V_235 ) ;
}
F_105 ( V_1 , V_2 ) ;
V_238 -> V_183 = * ( V_2 -> V_132 ) ;
if ( F_102 ( V_196 , V_238 , sizeof( * V_238 ) ) ) {
F_82 ( V_1 , V_2 ) ;
V_241 = - V_85 ;
goto V_245;
}
if ( V_238 -> V_182 . Type . V_228 == V_237 ) {
T_28 T_9 * V_248 = V_238 -> V_77 ;
for ( V_20 = 0 ; V_20 < V_240 ; V_20 ++ ) {
if ( F_102 ( V_248 , V_225 [ V_20 ] , V_239 [ V_20 ] ) ) {
F_82 ( V_1 , V_2 ) ;
V_241 = - V_85 ;
goto V_245;
}
V_248 += V_239 [ V_20 ] ;
}
}
F_82 ( V_1 , V_2 ) ;
V_241 = 0 ;
V_245:
if ( V_225 ) {
for ( V_20 = 0 ; V_20 < V_240 ; V_20 ++ )
F_15 ( V_225 [ V_20 ] ) ;
F_15 ( V_225 ) ;
}
F_15 ( V_239 ) ;
F_15 ( V_238 ) ;
return V_241 ;
}
static int F_95 ( struct V_146 * V_147 , T_15 V_148 ,
unsigned int V_157 , unsigned long V_158 )
{
struct V_142 * V_143 = V_147 -> V_149 ;
T_1 * V_1 = F_84 ( V_143 ) ;
void T_9 * V_196 = ( void T_9 * ) V_158 ;
F_87 ( & V_1 -> V_24 -> V_25 , L_28 ,
V_157 , V_158 ) ;
switch ( V_157 ) {
case V_159 :
return F_107 ( V_1 , V_196 ) ;
case V_160 :
return F_109 ( V_1 , V_196 ) ;
case V_161 :
return F_111 ( V_1 , V_196 ) ;
case V_162 :
return F_114 ( V_1 , V_196 ) ;
case V_163 :
return F_116 ( V_1 , V_196 ) ;
case V_164 :
return F_118 ( V_1 , V_196 ) ;
case V_165 :
return F_119 ( V_1 , V_196 ) ;
case V_166 :
return F_120 ( V_1 , V_196 ) ;
case V_167 :
return F_121 ( V_1 , V_196 ) ;
case V_169 :
case V_171 :
case V_168 :
return F_128 ( V_1 , 0 , 1 ) ;
case V_173 :
return F_122 ( V_1 , V_143 , V_196 ) ;
case V_185 :
return F_123 ( V_1 , V_196 ) ;
case V_187 :
return F_126 ( V_1 , V_196 ) ;
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
return F_129 ( V_147 , V_148 , V_157 , V_196 ) ;
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
default:
return - V_115 ;
}
}
static void F_130 ( T_1 * V_1 )
{
int V_262 = V_1 -> V_263 ;
int V_20 ;
if ( ( F_74 ( V_1 -> V_128 , V_1 -> V_19 ) ) == V_1 -> V_19 )
return;
for ( V_20 = 0 ; V_20 < V_1 -> V_64 + 1 ; V_20 ++ ) {
int V_264 = ( V_262 + V_20 ) % ( V_1 -> V_64 + 1 ) ;
if ( ! V_1 -> V_63 [ V_264 ] )
continue;
if ( ! ( V_1 -> V_63 [ V_264 ] -> V_144 ) ||
! ( V_1 -> V_63 [ V_264 ] -> V_65 ) )
continue;
F_131 ( V_1 -> V_142 [ V_264 ] -> V_144 ) ;
if ( ( F_74 ( V_1 -> V_128 , V_1 -> V_19 ) ) == V_1 -> V_19 ) {
if ( V_264 == V_262 ) {
V_1 -> V_263 =
( V_262 + 1 ) % ( V_1 -> V_64 + 1 ) ;
break;
} else {
V_1 -> V_263 = V_264 ;
break;
}
}
}
}
static void F_132 ( struct V_265 * V_266 )
{
T_2 * V_2 = V_266 -> V_267 ;
T_1 * V_1 = V_268 [ V_2 -> V_62 ] ;
T_3 * V_269 = V_2 -> V_31 ;
T_4 V_28 ;
unsigned long V_13 ;
int V_20 , V_270 ;
int V_271 = 0 ;
if ( V_2 -> V_182 . Type . V_228 == V_237 )
V_270 = V_272 ;
else
V_270 = V_38 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_7 . V_8 ; V_20 ++ ) {
if ( V_269 [ V_271 ] . V_41 == V_42 ) {
F_19 ( V_1 , V_2 ) ;
V_269 = V_1 -> V_18 [ V_2 -> V_137 ] ;
V_271 = 0 ;
}
V_28 . V_32 . V_33 = V_269 [ V_271 ] . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_269 [ V_271 ] . V_34 . V_35 ;
F_133 ( V_1 -> V_24 , V_28 . V_36 , V_269 [ V_271 ] . V_37 ,
V_270 ) ;
++ V_271 ;
}
F_87 ( & V_1 -> V_24 -> V_25 , L_29 , V_266 ) ;
if ( V_266 -> V_11 == V_273 )
V_266 -> V_274 = V_2 -> V_132 -> V_275 ;
F_134 ( V_266 , ( V_266 -> V_276 == 0 ) ? 0 : - V_277 ) ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
F_80 ( V_1 , V_2 ) ;
F_130 ( V_1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
}
static inline void F_135 ( T_1 * V_1 ,
unsigned char V_278 [] , T_29 V_279 )
{
memcpy ( V_278 , V_1 -> V_63 [ V_279 ] -> V_116 ,
sizeof( V_1 -> V_63 [ V_279 ] -> V_116 ) ) ;
}
static void F_136 ( T_1 * V_1 , int V_280 ,
char * V_108 , char * V_110 , char * V_112 )
{
int V_281 ;
T_30 * V_282 ;
unsigned char V_278 [ 8 ] ;
* V_108 = '\0' ;
* V_110 = '\0' ;
* V_112 = '\0' ;
V_282 = F_127 ( sizeof( T_30 ) , V_23 ) ;
if ( ! V_282 )
return;
F_135 ( V_1 , V_278 , V_280 ) ;
V_281 = F_137 ( V_1 , V_283 , V_282 , sizeof( * V_282 ) , 0 ,
V_278 , V_284 ) ;
if ( V_281 == V_285 ) {
memcpy ( V_108 , & V_282 -> V_286 [ 8 ] , V_109 ) ;
V_108 [ V_109 ] = '\0' ;
memcpy ( V_110 , & V_282 -> V_286 [ 16 ] , V_111 ) ;
V_110 [ V_111 ] = '\0' ;
memcpy ( V_112 , & V_282 -> V_286 [ 32 ] , V_113 ) ;
V_112 [ V_113 ] = '\0' ;
}
F_15 ( V_282 ) ;
return;
}
static void F_138 ( T_1 * V_1 , int V_280 ,
unsigned char * V_107 , int V_287 )
{
#define F_139 64
int V_281 ;
unsigned char * V_77 ;
unsigned char V_278 [ 8 ] ;
if ( V_287 > 16 )
V_287 = 16 ;
memset ( V_107 , 0xff , V_287 ) ;
V_77 = F_127 ( F_139 , V_23 ) ;
if ( ! V_77 )
return;
memset ( V_107 , 0 , V_287 ) ;
F_135 ( V_1 , V_278 , V_280 ) ;
V_281 = F_137 ( V_1 , V_283 , V_77 ,
F_139 , 0x83 , V_278 , V_284 ) ;
if ( V_281 == V_285 )
memcpy ( V_107 , & V_77 [ 8 ] , V_287 ) ;
F_15 ( V_77 ) ;
return;
}
static int F_140 ( T_1 * V_1 , struct V_142 * V_143 ,
int V_122 )
{
V_143 -> V_144 = F_141 ( V_288 , & V_1 -> V_14 ) ;
if ( ! V_143 -> V_144 )
goto V_289;
sprintf ( V_143 -> V_150 , L_30 , V_1 -> V_62 , V_122 ) ;
V_143 -> V_290 = V_1 -> V_290 ;
V_143 -> V_291 = V_122 << V_292 ;
V_143 -> V_293 = & V_294 ;
if ( F_71 ( V_1 , V_122 ) )
goto V_295;
V_143 -> V_75 = V_1 -> V_63 [ V_122 ] ;
V_143 -> V_296 = & V_1 -> V_63 [ V_122 ] -> V_25 ;
F_142 ( V_143 -> V_144 , V_1 -> V_24 -> V_297 ) ;
F_143 ( V_143 -> V_144 , V_1 -> V_298 ) ;
F_144 ( V_143 -> V_144 , V_1 -> V_299 ) ;
F_145 ( V_143 -> V_144 , F_132 ) ;
V_143 -> V_144 -> V_145 = V_1 ;
F_146 ( V_143 -> V_144 ,
V_1 -> V_63 [ V_122 ] -> V_300 ) ;
F_147 () ;
V_1 -> V_63 [ V_122 ] -> V_144 = V_143 -> V_144 ;
F_148 ( V_143 ) ;
return 0 ;
V_295:
F_149 ( V_143 -> V_144 ) ;
V_143 -> V_144 = NULL ;
V_289:
return - 1 ;
}
static void F_150 ( T_1 * V_1 , int V_122 ,
int V_301 , int V_302 )
{
struct V_142 * V_143 ;
T_30 * V_303 = NULL ;
unsigned int V_300 ;
T_6 V_304 ;
unsigned long V_13 = 0 ;
int V_73 = 0 ;
T_7 * V_305 ;
V_303 = F_17 ( sizeof( T_30 ) , V_23 ) ;
V_305 = F_127 ( sizeof( * V_305 ) , V_23 ) ;
if ( V_303 == NULL || V_305 == NULL )
goto V_306;
if ( V_1 -> V_307 == V_308 ) {
F_151 ( V_1 , V_122 ,
& V_304 , & V_300 ) ;
} else {
F_152 ( V_1 , V_122 , & V_304 , & V_300 ) ;
if ( V_304 == 0xFFFFFFFFULL ) {
F_151 ( V_1 , V_122 ,
& V_304 , & V_300 ) ;
V_1 -> V_307 = V_308 ;
V_1 -> V_309 = V_310 ;
} else {
V_1 -> V_307 = V_311 ;
V_1 -> V_309 = V_312 ;
}
}
F_153 ( V_1 , V_122 , V_304 , V_300 ,
V_303 , V_305 ) ;
V_305 -> V_300 = V_300 ;
V_305 -> V_66 = V_304 + 1 ;
F_136 ( V_1 , V_122 , V_305 -> V_108 ,
V_305 -> V_110 , V_305 -> V_112 ) ;
F_138 ( V_1 , V_122 , V_305 -> V_107 ,
sizeof( V_305 -> V_107 ) ) ;
memcpy ( V_305 -> V_116 , V_1 -> V_63 [ V_122 ] -> V_116 ,
sizeof( V_305 -> V_116 ) ) ;
if ( V_1 -> V_63 [ V_122 ] -> V_68 != - 1 &&
( ( memcmp ( V_305 -> V_107 ,
V_1 -> V_63 [ V_122 ] -> V_107 , 16 ) == 0 ) &&
V_305 -> V_300 == V_1 -> V_63 [ V_122 ] -> V_300 &&
V_305 -> V_66 == V_1 -> V_63 [ V_122 ] -> V_66 &&
V_305 -> V_65 == V_1 -> V_63 [ V_122 ] -> V_65 &&
V_305 -> V_191 == V_1 -> V_63 [ V_122 ] -> V_191 &&
V_305 -> V_190 == V_1 -> V_63 [ V_122 ] -> V_190 ) )
goto V_313;
if ( V_1 -> V_63 [ V_122 ] -> V_68 != - 1 && V_122 != 0 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_31 , V_122 ) ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_1 -> V_63 [ V_122 ] -> V_57 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
V_73 = F_155 ( V_1 , V_122 , 0 , V_302 ) ;
}
if ( V_73 )
goto V_313;
if ( V_1 -> V_63 [ V_122 ] == NULL ) {
V_305 -> V_123 = 0 ;
V_1 -> V_63 [ V_122 ] = V_305 ;
V_305 = NULL ;
} else {
V_1 -> V_63 [ V_122 ] -> V_300 = V_305 -> V_300 ;
V_1 -> V_63 [ V_122 ] -> V_66 = V_305 -> V_66 ;
V_1 -> V_63 [ V_122 ] -> V_65 = V_305 -> V_65 ;
V_1 -> V_63 [ V_122 ] -> V_191 = V_305 -> V_191 ;
V_1 -> V_63 [ V_122 ] -> V_190 = V_305 -> V_190 ;
V_1 -> V_63 [ V_122 ] -> V_68 = V_305 -> V_68 ;
memcpy ( V_1 -> V_63 [ V_122 ] -> V_107 , V_305 -> V_107 , 16 ) ;
memcpy ( V_1 -> V_63 [ V_122 ] -> V_108 , V_305 -> V_108 ,
V_109 + 1 ) ;
memcpy ( V_1 -> V_63 [ V_122 ] -> V_110 , V_305 -> V_110 , V_111 + 1 ) ;
memcpy ( V_1 -> V_63 [ V_122 ] -> V_112 , V_305 -> V_112 , V_113 + 1 ) ;
}
++ V_1 -> V_52 ;
V_143 = V_1 -> V_142 [ V_122 ] ;
F_156 ( V_143 , V_1 -> V_63 [ V_122 ] -> V_66 ) ;
if ( V_122 || V_301 ) {
if ( F_140 ( V_1 , V_143 , V_122 ) != 0 ) {
F_157 ( V_1 , V_122 ) ;
F_158 ( V_1 , V_122 ) ;
F_154 ( & V_1 -> V_24 -> V_25 , L_32 ,
V_122 ) ;
-- V_1 -> V_52 ;
}
}
V_313:
F_15 ( V_303 ) ;
F_15 ( V_305 ) ;
return;
V_306:
F_18 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
goto V_313;
}
static int F_159 ( T_1 * V_1 , int V_314 )
{
int V_20 ;
T_7 * V_63 ;
for ( V_20 = 0 ; V_20 < V_315 ; V_20 ++ ) {
if ( V_1 -> V_63 [ V_20 ] && V_20 != 0 )
continue;
if ( V_20 == 0 && V_1 -> V_63 [ V_20 ] && V_1 -> V_63 [ V_20 ] -> V_68 != - 1 )
continue;
if ( V_20 > V_1 -> V_64 && ! V_314 )
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
F_160 ( V_1 -> V_142 [ V_122 ] ) ;
V_1 -> V_142 [ V_122 ] = NULL ;
}
static int F_161 ( T_1 * V_1 , unsigned char V_114 [] ,
int V_314 )
{
int V_122 ;
V_122 = F_159 ( V_1 , V_314 ) ;
if ( V_122 == - 1 )
return - 1 ;
if ( ! V_1 -> V_142 [ V_122 ] ) {
V_1 -> V_142 [ V_122 ] =
F_162 ( 1 << V_292 ) ;
if ( ! V_1 -> V_142 [ V_122 ] ) {
F_18 ( & V_1 -> V_24 -> V_25 ,
L_34 ,
V_122 ) ;
goto V_316;
}
}
memcpy ( V_1 -> V_63 [ V_122 ] -> V_116 , V_114 ,
sizeof( V_1 -> V_63 [ V_122 ] -> V_116 ) ) ;
if ( F_71 ( V_1 , V_122 ) )
goto V_317;
V_1 -> V_63 [ V_122 ] -> V_57 = 0 ;
F_147 () ;
return V_122 ;
V_317:
F_157 ( V_1 , V_122 ) ;
V_316:
F_158 ( V_1 , V_122 ) ;
return - 1 ;
}
static void F_163 ( T_1 * V_1 )
{
struct V_142 * V_143 ;
int V_122 ;
if ( V_1 -> V_142 [ 0 ] != NULL )
return;
V_122 = F_161 ( V_1 , V_153 , 1 ) ;
if ( V_122 == - 1 )
goto error;
V_1 -> V_63 [ V_122 ] -> V_300 = 512 ;
V_1 -> V_63 [ V_122 ] -> V_66 = 0 ;
V_1 -> V_63 [ V_122 ] -> V_65 = 0 ;
V_1 -> V_63 [ V_122 ] -> V_191 = 0 ;
V_1 -> V_63 [ V_122 ] -> V_190 = 0 ;
V_1 -> V_63 [ V_122 ] -> V_68 = - 1 ;
memset ( V_1 -> V_63 [ V_122 ] -> V_107 , 0 , 16 ) ;
V_143 = V_1 -> V_142 [ V_122 ] ;
if ( F_140 ( V_1 , V_143 , V_122 ) == 0 )
return;
F_157 ( V_1 , V_122 ) ;
F_158 ( V_1 , V_122 ) ;
error:
F_154 ( & V_1 -> V_24 -> V_25 , L_35 ) ;
return;
}
static int F_128 ( T_1 * V_1 , int V_301 ,
int V_302 )
{
int V_52 ;
T_31 * V_318 = NULL ;
int V_319 ;
int V_320 = 0 ;
int V_20 ;
int V_321 ;
int V_122 = 0 ;
unsigned char V_114 [ 8 ] = V_153 ;
unsigned long V_13 ;
if ( ! F_89 ( V_227 ) )
return - V_155 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_58 ;
}
V_1 -> V_57 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
V_318 = F_127 ( sizeof( T_31 ) , V_23 ) ;
if ( V_318 == NULL )
goto V_306;
V_319 = F_137 ( V_1 , V_322 , V_318 ,
sizeof( T_31 ) ,
0 , V_153 , V_284 ) ;
if ( V_319 == V_285 )
V_320 = F_164 ( * ( V_323 * ) V_318 -> V_324 ) ;
else {
F_154 ( & V_1 -> V_24 -> V_25 ,
L_36 ) ;
V_320 = 0 ;
goto V_313;
}
V_52 = V_320 / 8 ;
if ( V_52 > V_315 ) {
V_52 = V_315 ;
F_154 ( & V_1 -> V_24 -> V_25 , L_37
L_38
L_39 ) ;
}
if ( V_52 == 0 )
F_163 ( V_1 ) ;
for ( V_20 = 0 ; V_20 <= V_1 -> V_64 ; V_20 ++ ) {
int V_22 ;
V_321 = 0 ;
if ( V_1 -> V_63 [ V_20 ] == NULL )
continue;
for ( V_22 = 0 ; V_22 < V_52 ; V_22 ++ ) {
memcpy ( V_114 , & V_318 -> V_233 [ V_22 ] [ 0 ] , sizeof( V_114 ) ) ;
if ( memcmp ( V_1 -> V_63 [ V_20 ] -> V_116 , V_114 ,
sizeof( V_114 ) ) == 0 ) {
V_321 = 1 ;
break;
}
}
if ( ! V_321 ) {
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_1 -> V_63 [ V_20 ] -> V_57 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
V_319 = F_155 ( V_1 , V_20 , 1 , V_302 ) ;
if ( V_1 -> V_63 [ V_20 ] != NULL )
V_1 -> V_63 [ V_20 ] -> V_57 = 0 ;
}
}
for ( V_20 = 0 ; V_20 < V_52 ; V_20 ++ ) {
int V_22 ;
V_321 = 0 ;
memcpy ( V_114 , & V_318 -> V_233 [ V_20 ] [ 0 ] , sizeof( V_114 ) ) ;
for ( V_22 = 0 ; V_22 <= V_1 -> V_64 ; V_22 ++ ) {
if ( V_1 -> V_63 [ V_22 ] != NULL &&
memcmp ( V_1 -> V_63 [ V_22 ] -> V_116 , V_114 ,
sizeof( V_1 -> V_63 [ V_22 ] -> V_116 ) ) == 0 ) {
V_122 = V_22 ;
V_321 = 1 ;
break;
}
}
if ( ! V_321 ) {
V_122 = F_161 ( V_1 , V_114 , 0 ) ;
if ( V_122 == - 1 )
goto V_313;
}
F_150 ( V_1 , V_122 , V_301 , V_302 ) ;
}
V_313:
F_15 ( V_318 ) ;
V_1 -> V_57 = 0 ;
return - 1 ;
V_306:
F_18 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
V_1 -> V_57 = 0 ;
goto V_313;
}
static void F_165 ( T_7 * V_325 )
{
V_325 -> V_66 = 0 ;
V_325 -> V_300 = 0 ;
V_325 -> V_65 = 0 ;
V_325 -> V_191 = 0 ;
V_325 -> V_190 = 0 ;
V_325 -> V_68 = - 1 ;
memset ( V_325 -> V_107 , 0 , sizeof( V_325 -> V_107 ) ) ;
memset ( V_325 -> V_110 , 0 , sizeof( V_325 -> V_110 ) ) ;
memset ( V_325 -> V_112 , 0 , sizeof( V_325 -> V_112 ) ) ;
memset ( V_325 -> V_108 , 0 , sizeof( V_325 -> V_108 ) ) ;
}
static int F_155 ( T_1 * V_1 , int V_122 ,
int V_326 , int V_302 )
{
int V_20 ;
struct V_142 * V_143 ;
T_7 * V_63 ;
int V_327 ;
if ( ! F_89 ( V_227 ) )
return - V_155 ;
V_63 = V_1 -> V_63 [ V_122 ] ;
V_143 = V_1 -> V_142 [ V_122 ] ;
if ( V_326 || ( V_1 -> V_142 [ 0 ] == V_143 ) ) {
if ( V_63 -> V_118 > V_302 )
return - V_58 ;
} else if ( V_63 -> V_118 > 0 )
return - V_58 ;
V_327 = ( V_63 == V_1 -> V_63 [ V_1 -> V_64 ] ) ;
if ( V_1 -> V_142 [ 0 ] != V_143 ) {
struct V_328 * V_329 = V_143 -> V_144 ;
if ( V_143 -> V_13 & V_330 ) {
F_72 ( V_1 , V_122 , 0 ) ;
F_166 ( V_143 ) ;
}
if ( V_329 )
F_149 ( V_329 ) ;
if ( V_326 ) {
for ( V_20 = 0 ; V_20 < V_315 ; V_20 ++ ) {
if ( V_1 -> V_142 [ V_20 ] == V_143 ) {
V_1 -> V_142 [ V_20 ] = NULL ;
break;
}
}
F_160 ( V_143 ) ;
}
} else {
F_156 ( V_143 , 0 ) ;
F_165 ( V_63 ) ;
}
-- V_1 -> V_52 ;
if ( V_326 && V_327 ) {
int V_331 = - 1 ;
for ( V_20 = 0 ; V_20 <= V_1 -> V_64 ; V_20 ++ ) {
if ( V_1 -> V_63 [ V_20 ] && V_1 -> V_63 [ V_20 ] -> V_65 )
V_331 = V_20 ;
}
V_1 -> V_64 = V_331 ;
}
return 0 ;
}
static int F_167 ( T_1 * V_1 , T_2 * V_2 , T_13 V_157 , void * V_225 ,
T_10 V_332 , T_13 V_333 , unsigned char * V_278 ,
int V_11 )
{
T_4 V_334 ;
int V_241 = V_285 ;
V_2 -> V_11 = V_231 ;
V_2 -> V_7 . V_232 = 0 ;
if ( V_225 != NULL ) {
V_2 -> V_7 . V_8 = 1 ;
V_2 -> V_7 . V_29 = 1 ;
} else {
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_7 . V_29 = 0 ;
}
V_2 -> V_7 . V_234 . V_33 = V_2 -> V_5 ;
memcpy ( V_2 -> V_7 . V_233 . V_335 , V_278 , 8 ) ;
V_2 -> V_182 . Type . Type = V_11 ;
if ( V_11 == V_284 ) {
switch ( V_157 ) {
case V_283 :
if ( V_333 != 0 ) {
V_2 -> V_182 . V_336 [ 1 ] = 0x01 ;
V_2 -> V_182 . V_336 [ 2 ] = V_333 ;
}
V_2 -> V_182 . V_337 = 6 ;
V_2 -> V_182 . Type . V_338 = V_339 ;
V_2 -> V_182 . Type . V_228 = V_237 ;
V_2 -> V_182 . V_340 = 0 ;
V_2 -> V_182 . V_336 [ 0 ] = V_283 ;
V_2 -> V_182 . V_336 [ 4 ] = V_332 & 0xFF ;
break;
case V_322 :
case V_341 :
V_2 -> V_182 . V_337 = 12 ;
V_2 -> V_182 . Type . V_338 = V_339 ;
V_2 -> V_182 . Type . V_228 = V_237 ;
V_2 -> V_182 . V_340 = 0 ;
V_2 -> V_182 . V_336 [ 0 ] = V_157 ;
V_2 -> V_182 . V_336 [ 6 ] = ( V_332 >> 24 ) & 0xFF ;
V_2 -> V_182 . V_336 [ 7 ] = ( V_332 >> 16 ) & 0xFF ;
V_2 -> V_182 . V_336 [ 8 ] = ( V_332 >> 8 ) & 0xFF ;
V_2 -> V_182 . V_336 [ 9 ] = V_332 & 0xFF ;
break;
case V_342 :
V_2 -> V_182 . V_337 = 10 ;
V_2 -> V_182 . Type . V_338 = V_339 ;
V_2 -> V_182 . Type . V_228 = V_237 ;
V_2 -> V_182 . V_340 = 0 ;
V_2 -> V_182 . V_336 [ 0 ] = V_157 ;
break;
case V_343 :
V_2 -> V_182 . V_337 = 16 ;
V_2 -> V_182 . Type . V_338 = V_339 ;
V_2 -> V_182 . Type . V_228 = V_237 ;
V_2 -> V_182 . V_340 = 0 ;
V_2 -> V_182 . V_336 [ 0 ] = V_157 ;
V_2 -> V_182 . V_336 [ 1 ] = 0x10 ;
V_2 -> V_182 . V_336 [ 10 ] = ( V_332 >> 24 ) & 0xFF ;
V_2 -> V_182 . V_336 [ 11 ] = ( V_332 >> 16 ) & 0xFF ;
V_2 -> V_182 . V_336 [ 12 ] = ( V_332 >> 8 ) & 0xFF ;
V_2 -> V_182 . V_336 [ 13 ] = V_332 & 0xFF ;
V_2 -> V_182 . V_340 = 0 ;
V_2 -> V_182 . V_336 [ 0 ] = V_157 ;
break;
case V_344 :
V_2 -> V_182 . V_337 = 12 ;
V_2 -> V_182 . Type . V_338 = V_339 ;
V_2 -> V_182 . Type . V_228 = V_230 ;
V_2 -> V_182 . V_340 = 0 ;
V_2 -> V_182 . V_336 [ 0 ] = V_345 ;
V_2 -> V_182 . V_336 [ 6 ] = V_346 ;
V_2 -> V_182 . V_336 [ 7 ] = ( V_332 >> 8 ) & 0xFF ;
V_2 -> V_182 . V_336 [ 8 ] = V_332 & 0xFF ;
break;
case V_347 :
V_2 -> V_182 . V_337 = 6 ;
V_2 -> V_182 . Type . V_338 = V_339 ;
V_2 -> V_182 . Type . V_228 = V_229 ;
V_2 -> V_182 . V_340 = 0 ;
break;
default:
F_154 ( & V_1 -> V_24 -> V_25 , L_40 , V_157 ) ;
return V_348 ;
}
} else if ( V_11 == V_349 ) {
switch ( V_157 ) {
case V_350 :
V_2 -> V_182 . V_337 = 12 ;
V_2 -> V_182 . Type . V_338 = V_339 ;
V_2 -> V_182 . Type . V_228 = V_230 ;
V_2 -> V_182 . V_340 = 0 ;
V_2 -> V_182 . V_336 [ 0 ] = V_157 ;
V_2 -> V_182 . V_336 [ 1 ] = 0 ;
memcpy ( & V_2 -> V_182 . V_336 [ 4 ] , V_225 , 8 ) ;
break;
case V_351 :
V_2 -> V_182 . V_337 = 16 ;
V_2 -> V_182 . Type . V_338 = V_339 ;
V_2 -> V_182 . Type . V_228 = V_229 ;
V_2 -> V_182 . V_340 = 0 ;
memset ( & V_2 -> V_182 . V_336 [ 0 ] , 0 , sizeof( V_2 -> V_182 . V_336 ) ) ;
V_2 -> V_182 . V_336 [ 0 ] = V_157 ;
V_2 -> V_182 . V_336 [ 1 ] = V_352 ;
break;
case V_353 :
V_2 -> V_182 . V_337 = 1 ;
V_2 -> V_182 . Type . V_338 = V_339 ;
V_2 -> V_182 . Type . V_228 = V_230 ;
V_2 -> V_182 . V_340 = 0 ;
V_2 -> V_182 . V_336 [ 0 ] = V_157 ;
break;
default:
F_154 ( & V_1 -> V_24 -> V_25 ,
L_41 , V_157 ) ;
return V_348 ;
}
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_42 , V_11 ) ;
return V_348 ;
}
if ( V_332 > 0 ) {
V_334 . V_36 = ( V_139 ) F_22 ( V_1 -> V_24 ,
V_225 , V_332 ,
V_235 ) ;
V_2 -> V_31 [ 0 ] . V_34 . V_33 = V_334 . V_32 . V_33 ;
V_2 -> V_31 [ 0 ] . V_34 . V_35 = V_334 . V_32 . V_35 ;
V_2 -> V_31 [ 0 ] . V_37 = V_332 ;
V_2 -> V_31 [ 0 ] . V_41 = 0 ;
}
return V_241 ;
}
static int T_11 F_168 ( T_1 * V_1 , unsigned char * V_278 ,
T_32 V_354 )
{
T_2 * V_2 ;
int V_355 ;
V_2 = F_73 ( V_1 ) ;
if ( ! V_2 )
return - V_84 ;
V_355 = F_167 ( V_1 , V_2 , V_351 , NULL , 0 , 0 ,
V_153 , V_349 ) ;
V_2 -> V_182 . V_336 [ 1 ] = V_354 ;
if ( V_355 != V_285 ) {
F_82 ( V_1 , V_2 ) ;
return V_355 ;
}
V_2 -> V_236 = NULL ;
F_10 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_169 ( T_1 * V_1 , T_2 * V_2 )
{
switch ( V_2 -> V_132 -> V_194 ) {
case V_356 :
return V_285 ;
case V_195 :
switch ( 0xf & V_2 -> V_132 -> V_357 [ 2 ] ) {
case 0 : return V_285 ;
case 1 : return V_285 ;
default:
if ( F_106 ( V_1 , V_2 ) )
return V_358 ;
F_154 ( & V_1 -> V_24 -> V_25 , L_43
L_44 ,
V_2 -> V_182 . V_336 [ 0 ] , V_2 -> V_132 -> V_357 [ 2 ] ) ;
}
break;
default:
F_154 ( & V_1 -> V_24 -> V_25 , L_45
L_46 ,
V_2 -> V_182 . V_336 [ 0 ] , V_2 -> V_132 -> V_194 ) ;
break;
}
return V_348 ;
}
static int F_170 ( T_1 * V_1 , T_2 * V_2 )
{
int V_355 = V_285 ;
if ( V_2 -> V_132 -> V_192 == V_359 )
return V_285 ;
switch ( V_2 -> V_132 -> V_192 ) {
case V_193 :
V_355 = F_169 ( V_1 , V_2 ) ;
break;
case V_360 :
case V_361 :
break;
case V_362 :
F_154 ( & V_1 -> V_24 -> V_25 , L_47
L_48 , V_2 -> V_182 . V_336 [ 0 ] ) ;
V_355 = V_348 ;
break;
case V_363 :
F_154 ( & V_1 -> V_24 -> V_25 , L_49
L_50 , V_2 -> V_182 . V_336 [ 0 ] ) ;
V_355 = V_348 ;
break;
case V_364 :
F_154 ( & V_1 -> V_24 -> V_25 , L_51
L_52 , V_2 -> V_182 . V_336 [ 0 ] ) ;
V_355 = V_348 ;
break;
case V_365 :
F_154 ( & V_1 -> V_24 -> V_25 , L_51
L_53 , V_2 -> V_182 . V_336 [ 0 ] ) ;
V_355 = V_348 ;
break;
case V_366 :
F_154 ( & V_1 -> V_24 -> V_25 , L_54
L_55 , V_2 -> V_182 . V_336 [ 0 ] ) ;
V_355 = V_348 ;
break;
case V_367 :
F_154 ( & V_1 -> V_24 -> V_25 , L_56
L_57 , V_2 -> V_182 . V_336 [ 0 ] ) ;
V_355 = V_348 ;
break;
case V_368 :
F_154 ( & V_1 -> V_24 -> V_25 , L_58 ,
V_2 -> V_182 . V_336 [ 0 ] ) ;
V_355 = V_358 ;
break;
case V_369 :
F_154 ( & V_1 -> V_24 -> V_25 , L_59 ) ;
V_355 = V_348 ;
break;
default:
F_154 ( & V_1 -> V_24 -> V_25 , L_60
L_61 , V_2 -> V_182 . V_336 [ 0 ] ,
V_2 -> V_132 -> V_192 ) ;
V_355 = V_348 ;
}
return V_355 ;
}
static int F_171 ( T_1 * V_1 , T_2 * V_2 ,
int V_370 )
{
F_124 ( V_226 ) ;
T_4 V_334 ;
int V_355 = V_285 ;
V_371:
V_2 -> V_236 = & V_226 ;
F_10 ( V_1 , V_2 ) ;
F_125 ( & V_226 ) ;
if ( V_2 -> V_132 -> V_192 == 0 || ! V_370 )
goto V_372;
V_355 = F_170 ( V_1 , V_2 ) ;
if ( V_355 == V_358 &&
V_2 -> V_373 < V_374 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_62 ,
V_2 -> V_182 . V_336 [ 0 ] ) ;
V_2 -> V_373 ++ ;
memset ( V_2 -> V_132 , 0 , sizeof( V_134 ) ) ;
V_355 = V_285 ;
F_172 ( V_226 ) ;
goto V_371;
}
V_372:
V_334 . V_32 . V_33 = V_2 -> V_31 [ 0 ] . V_34 . V_33 ;
V_334 . V_32 . V_35 = V_2 -> V_31 [ 0 ] . V_34 . V_35 ;
F_20 ( V_1 -> V_24 , ( T_14 ) V_334 . V_36 ,
V_2 -> V_31 [ 0 ] . V_37 , V_235 ) ;
return V_355 ;
}
static int F_137 ( T_1 * V_1 , T_13 V_157 , void * V_225 , T_10 V_332 ,
T_13 V_333 , unsigned char V_278 [] ,
int V_11 )
{
T_2 * V_2 ;
int V_355 ;
V_2 = F_77 ( V_1 ) ;
if ( ! V_2 )
return - V_84 ;
V_355 = F_167 ( V_1 , V_2 , V_157 , V_225 , V_332 , V_333 ,
V_278 , V_11 ) ;
if ( V_355 == V_285 )
V_355 = F_171 ( V_1 , V_2 , 1 ) ;
F_82 ( V_1 , V_2 ) ;
return V_355 ;
}
static void F_153 ( T_1 * V_1 , int V_280 ,
T_6 V_304 ,
unsigned int V_300 ,
T_30 * V_303 ,
T_7 * V_63 )
{
int V_319 ;
unsigned long V_375 ;
unsigned char V_278 [ 8 ] ;
memset ( V_303 , 0 , sizeof( T_30 ) ) ;
F_135 ( V_1 , V_278 , V_280 ) ;
V_319 = F_137 ( V_1 , V_283 , V_303 ,
sizeof( * V_303 ) , 0xC1 , V_278 , V_284 ) ;
if ( V_319 == V_285 ) {
if ( V_303 -> V_286 [ 8 ] == 0xFF ) {
F_154 ( & V_1 -> V_24 -> V_25 ,
L_63
L_64 ) ;
V_63 -> V_65 = 255 ;
V_63 -> V_191 = 32 ;
V_63 -> V_190 = V_304 + 1 ;
V_63 -> V_68 = V_69 ;
} else {
V_63 -> V_65 = V_303 -> V_286 [ 6 ] ;
V_63 -> V_191 = V_303 -> V_286 [ 7 ] ;
V_63 -> V_190 = ( V_303 -> V_286 [ 4 ] & 0xff ) << 8 ;
V_63 -> V_190 += V_303 -> V_286 [ 5 ] ;
V_63 -> V_68 = V_303 -> V_286 [ 8 ] ;
}
V_63 -> V_300 = V_300 ;
V_63 -> V_66 = V_304 + 1 ;
V_375 = V_63 -> V_65 * V_63 -> V_191 ;
if ( V_375 > 1 ) {
T_6 V_376 = V_304 + 1 ;
unsigned long V_377 = F_30 ( V_376 , V_375 ) ;
if ( V_377 )
V_376 ++ ;
V_63 -> V_190 = V_376 ;
}
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_65 ) ;
}
}
static void
F_152 ( T_1 * V_1 , int V_280 , T_6 * V_304 ,
unsigned int * V_300 )
{
T_33 * V_77 ;
int V_319 ;
unsigned char V_278 [ 8 ] ;
V_77 = F_127 ( sizeof( T_33 ) , V_23 ) ;
if ( ! V_77 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
return;
}
F_135 ( V_1 , V_278 , V_280 ) ;
V_319 = F_137 ( V_1 , V_342 , V_77 ,
sizeof( T_33 ) , 0 , V_278 , V_284 ) ;
if ( V_319 == V_285 ) {
* V_304 = F_164 ( * ( V_323 * ) V_77 -> V_304 ) ;
* V_300 = F_164 ( * ( V_323 * ) V_77 -> V_300 ) ;
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_66 ) ;
* V_304 = 0 ;
* V_300 = V_378 ;
}
F_15 ( V_77 ) ;
}
static void F_151 ( T_1 * V_1 , int V_280 ,
T_6 * V_304 , unsigned int * V_300 )
{
T_34 * V_77 ;
int V_319 ;
unsigned char V_278 [ 8 ] ;
V_77 = F_127 ( sizeof( T_34 ) , V_23 ) ;
if ( ! V_77 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
return;
}
F_135 ( V_1 , V_278 , V_280 ) ;
V_319 = F_137 ( V_1 , V_343 ,
V_77 , sizeof( T_34 ) ,
0 , V_278 , V_284 ) ;
if ( V_319 == V_285 ) {
* V_304 = F_173 ( * ( V_379 * ) V_77 -> V_304 ) ;
* V_300 = F_164 ( * ( V_323 * ) V_77 -> V_300 ) ;
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_66 ) ;
* V_304 = 0 ;
* V_300 = V_378 ;
}
F_174 ( & V_1 -> V_24 -> V_25 , L_67 ,
( unsigned long long ) * V_304 + 1 , * V_300 ) ;
F_15 ( V_77 ) ;
}
static int F_175 ( struct V_142 * V_143 )
{
T_1 * V_1 = F_84 ( V_143 ) ;
T_7 * V_63 = F_85 ( V_143 ) ;
int V_280 ;
int V_380 = 0 ;
unsigned int V_300 ;
T_6 V_304 ;
T_30 * V_303 = NULL ;
for ( V_280 = 0 ; V_280 <= V_1 -> V_64 ; V_280 ++ ) {
if ( ! V_1 -> V_63 [ V_280 ] )
continue;
if ( memcmp ( V_1 -> V_63 [ V_280 ] -> V_116 , V_63 -> V_116 ,
sizeof( V_63 -> V_116 ) ) == 0 ) {
V_380 = 1 ;
break;
}
}
if ( ! V_380 )
return 1 ;
V_303 = F_17 ( sizeof( T_30 ) , V_23 ) ;
if ( V_303 == NULL ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
return 1 ;
}
if ( V_1 -> V_307 == V_311 ) {
F_152 ( V_1 , V_280 ,
& V_304 , & V_300 ) ;
} else {
F_151 ( V_1 , V_280 ,
& V_304 , & V_300 ) ;
}
F_153 ( V_1 , V_280 , V_304 , V_300 ,
V_303 , V_63 ) ;
F_146 ( V_63 -> V_144 , V_63 -> V_300 ) ;
F_156 ( V_143 , V_63 -> V_66 ) ;
F_15 ( V_303 ) ;
return 0 ;
}
static void T_35 * F_176 ( T_36 V_381 , T_36 V_332 )
{
T_36 V_382 = ( ( T_36 ) V_381 ) & V_383 ;
T_36 V_384 = ( ( T_36 ) V_381 ) - V_382 ;
void T_35 * V_385 = F_177 ( V_382 , V_384 + V_332 ) ;
return V_385 ? ( V_385 + V_384 ) : NULL ;
}
static void F_12 ( T_1 * V_1 )
{
T_2 * V_2 ;
while ( ! F_8 ( & V_1 -> V_15 ) ) {
V_2 = F_178 ( V_1 -> V_15 . V_386 , T_2 , V_10 ) ;
if ( ( V_1 -> V_387 . V_388 ( V_1 ) ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_68 ) ;
break;
}
F_6 ( V_2 ) ;
V_1 -> V_16 -- ;
V_1 -> V_387 . V_389 ( V_1 , V_2 ) ;
F_4 ( & V_1 -> V_390 , V_2 ) ;
}
}
static inline void F_179 ( T_1 * V_1 , T_2 * V_2 )
{
memset ( V_2 -> V_132 , 0 , sizeof( V_134 ) ) ;
F_4 ( & V_1 -> V_15 , V_2 ) ;
V_1 -> V_16 ++ ;
if ( V_1 -> V_16 > V_1 -> V_17 )
V_1 -> V_17 = V_1 -> V_16 ;
F_12 ( V_1 ) ;
}
static inline unsigned int F_180 ( unsigned int V_391 ,
unsigned int V_392 , unsigned int V_393 ,
unsigned int V_394 )
{
return ( V_391 & 0xff ) |
( ( V_392 & 0xff ) << 8 ) |
( ( V_393 & 0xff ) << 16 ) |
( ( V_394 & 0xff ) << 24 ) ;
}
static inline int F_181 ( T_1 * V_1 ,
T_2 * V_157 , int * V_395 )
{
unsigned char V_396 ;
unsigned char V_397 , V_392 , V_393 , V_394 ;
int V_398 ;
* V_395 = 0 ;
V_397 = V_157 -> V_132 -> V_194 ;
V_394 = V_399 ;
V_392 = V_157 -> V_132 -> V_192 ;
if ( V_157 -> V_266 -> V_11 == V_273 )
V_393 = V_400 ;
else
V_393 = V_401 ;
V_398 = F_180 ( V_397 , V_392 ,
V_393 , V_394 ) ;
if ( V_157 -> V_132 -> V_194 != V_195 ) {
if ( V_157 -> V_266 -> V_11 != V_273 )
F_154 ( & V_1 -> V_24 -> V_25 , L_69
L_70 ,
V_157 , V_157 -> V_132 -> V_194 ) ;
return V_398 ;
}
V_396 = 0xf & V_157 -> V_132 -> V_357 [ 2 ] ;
if ( ( ( V_396 == 0x0 ) || ( V_396 == 0x1 ) ) &&
( V_157 -> V_266 -> V_11 != V_273 ) )
V_398 = 0 ;
if ( F_106 ( V_1 , V_157 ) ) {
* V_395 = ! ( V_157 -> V_266 -> V_11 == V_273 ) ;
return 0 ;
}
if ( V_157 -> V_266 -> V_11 != V_273 ) {
if ( V_398 != 0 )
F_154 ( & V_1 -> V_24 -> V_25 , L_71
L_72 , V_157 , V_396 ) ;
return V_398 ;
}
if ( V_157 -> V_266 -> V_402 ) {
if ( V_157 -> V_266 -> V_403 > V_157 -> V_132 -> V_404 )
V_157 -> V_266 -> V_403 = V_157 -> V_132 -> V_404 ;
memcpy ( V_157 -> V_266 -> V_402 , V_157 -> V_132 -> V_357 ,
V_157 -> V_266 -> V_403 ) ;
} else
V_157 -> V_266 -> V_403 = 0 ;
return V_398 ;
}
static inline void F_182 ( T_1 * V_1 , T_2 * V_157 ,
int V_405 )
{
int V_395 = 0 ;
struct V_265 * V_266 = V_157 -> V_266 ;
V_266 -> V_276 = 0 ;
if ( V_405 )
V_266 -> V_276 = F_180 ( 0 , 0 , 0 , V_406 ) ;
if ( V_157 -> V_132 -> V_192 == 0 )
goto V_407;
switch ( V_157 -> V_132 -> V_192 ) {
case V_193 :
V_266 -> V_276 = F_181 ( V_1 , V_157 , & V_395 ) ;
break;
case V_360 :
if ( V_157 -> V_266 -> V_11 == V_408 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_73
L_74
L_75 , V_157 ) ;
V_157 -> V_266 -> V_274 = V_157 -> V_132 -> V_275 ;
}
break;
case V_361 :
if ( V_157 -> V_266 -> V_11 == V_408 )
F_154 ( & V_1 -> V_24 -> V_25 , L_76
L_77
L_75 , V_157 ) ;
break;
case V_362 :
F_154 ( & V_1 -> V_24 -> V_25 , L_78
L_48 , V_157 ) ;
V_266 -> V_276 = F_180 ( V_356 ,
V_157 -> V_132 -> V_192 , V_399 ,
( V_157 -> V_266 -> V_11 == V_273 ) ?
V_400 : V_409 ) ;
break;
case V_363 :
F_154 ( & V_1 -> V_24 -> V_25 , L_79
L_50 , V_157 ) ;
V_266 -> V_276 = F_180 ( V_356 ,
V_157 -> V_132 -> V_192 , V_399 ,
( V_157 -> V_266 -> V_11 == V_273 ) ?
V_400 : V_409 ) ;
break;
case V_364 :
F_154 ( & V_1 -> V_24 -> V_25 , L_80
L_52 , V_157 ) ;
V_266 -> V_276 = F_180 ( V_356 ,
V_157 -> V_132 -> V_192 , V_399 ,
( V_157 -> V_266 -> V_11 == V_273 ) ?
V_400 : V_409 ) ;
break;
case V_365 :
F_154 ( & V_1 -> V_24 -> V_25 , L_80
L_53 , V_157 ) ;
V_266 -> V_276 = F_180 ( V_356 ,
V_157 -> V_132 -> V_192 , V_399 ,
( V_157 -> V_266 -> V_11 == V_273 ) ?
V_400 : V_409 ) ;
break;
case V_366 :
F_154 ( & V_1 -> V_24 -> V_25 , L_81
L_55 , V_157 ) ;
V_266 -> V_276 = F_180 ( V_356 ,
V_157 -> V_132 -> V_192 , V_399 ,
( V_157 -> V_266 -> V_11 == V_273 ) ?
V_400 : V_410 ) ;
break;
case V_367 :
F_154 ( & V_1 -> V_24 -> V_25 , L_82
L_57 , V_157 ) ;
V_266 -> V_276 = F_180 ( V_356 ,
V_157 -> V_132 -> V_192 , V_399 ,
( V_157 -> V_266 -> V_11 == V_273 ) ?
V_400 : V_409 ) ;
break;
case V_368 :
F_154 ( & V_1 -> V_24 -> V_25 , L_83
L_84 , V_1 -> V_62 , V_157 ) ;
if ( V_157 -> V_373 < V_374 ) {
V_395 = 1 ;
F_154 ( & V_1 -> V_24 -> V_25 , L_85 , V_157 ) ;
V_157 -> V_373 ++ ;
} else
F_154 ( & V_1 -> V_24 -> V_25 ,
L_86 , V_157 ) ;
V_266 -> V_276 = F_180 ( V_356 ,
V_157 -> V_132 -> V_192 , V_399 ,
( V_157 -> V_266 -> V_11 == V_273 ) ?
V_400 : V_410 ) ;
break;
case V_411 :
F_154 ( & V_1 -> V_24 -> V_25 , L_87 , V_157 ) ;
V_266 -> V_276 = F_180 ( V_356 ,
V_157 -> V_132 -> V_192 , V_399 ,
( V_157 -> V_266 -> V_11 == V_273 ) ?
V_400 : V_409 ) ;
break;
case V_369 :
F_154 ( & V_1 -> V_24 -> V_25 , L_88 , V_157 ) ;
V_266 -> V_276 = F_180 ( V_356 ,
V_157 -> V_132 -> V_192 , V_399 ,
V_157 -> V_266 -> V_11 == V_273 ?
V_400 : V_409 ) ;
break;
default:
F_154 ( & V_1 -> V_24 -> V_25 , L_89
L_61 , V_157 ,
V_157 -> V_132 -> V_192 ) ;
V_266 -> V_276 = F_180 ( V_356 ,
V_157 -> V_132 -> V_192 , V_399 ,
( V_157 -> V_266 -> V_11 == V_273 ) ?
V_400 : V_409 ) ;
}
V_407:
if ( V_395 ) {
F_179 ( V_1 , V_157 ) ;
return;
}
V_157 -> V_266 -> V_267 = V_157 ;
F_183 ( V_157 -> V_266 ) ;
}
static inline T_12 F_184 ( T_12 V_412 )
{
#define F_185 0x10
return V_412 & F_185 ;
}
static inline T_12 F_186 ( T_12 V_412 )
{
#define F_187 5
return V_412 >> F_187 ;
}
static inline T_12 F_83 ( T_1 * V_1 , T_12 V_412 )
{
#define F_188 ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define F_189 0x03
if ( F_3 ( V_1 -> V_3 & V_4 ) )
return V_412 & ~ F_188 ;
return V_412 & ~ F_189 ;
}
static inline void F_190 ( T_12 * V_412 )
{
* V_412 |= F_185 ;
}
static inline void F_191 ( T_12 * V_412 , T_12 V_413 )
{
* V_412 |= ( V_413 << F_187 ) ;
}
static void V_288 ( struct V_328 * V_329 )
{
T_1 * V_1 = V_329 -> V_145 ;
T_2 * V_2 ;
T_6 V_414 ;
int V_415 ;
struct V_265 * V_416 ;
T_4 V_28 ;
struct V_417 * V_418 ;
T_3 * V_269 ;
T_7 * V_63 ;
int V_20 , V_419 ;
int V_271 = 0 ;
int V_420 = 0 ;
V_144:
V_416 = F_192 ( V_329 ) ;
if ( ! V_416 )
goto V_421;
F_193 ( V_416 -> V_422 > V_1 -> V_298 ) ;
V_2 = F_73 ( V_1 ) ;
if ( ! V_2 )
goto V_423;
F_194 ( V_416 ) ;
V_418 = V_1 -> V_424 [ V_2 -> V_137 ] ;
F_195 ( V_329 -> V_425 ) ;
V_2 -> V_11 = V_426 ;
V_2 -> V_266 = V_416 ;
V_63 = V_416 -> V_427 -> V_75 ;
V_2 -> V_7 . V_232 = 0 ;
F_191 ( & V_2 -> V_7 . V_234 . V_33 , V_2 -> V_137 ) ;
F_190 ( & V_2 -> V_7 . V_234 . V_33 ) ;
memcpy ( & V_2 -> V_7 . V_233 , V_63 -> V_116 , sizeof( V_63 -> V_116 ) ) ;
V_2 -> V_182 . V_337 = 10 ;
V_2 -> V_182 . Type . Type = V_284 ;
V_2 -> V_182 . Type . V_338 = V_339 ;
V_2 -> V_182 . Type . V_228 =
( F_196 ( V_416 ) == V_428 ) ? V_237 : V_230 ;
V_2 -> V_182 . V_340 = 0 ;
V_2 -> V_182 . V_336 [ 0 ] =
( F_196 ( V_416 ) == V_428 ) ? V_1 -> V_307 : V_1 -> V_309 ;
V_414 = F_197 ( V_416 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_90 ,
( int ) F_197 ( V_416 ) , ( int ) F_198 ( V_416 ) ) ;
F_199 ( V_418 , V_1 -> V_298 ) ;
V_415 = F_200 ( V_329 , V_416 , V_418 ) ;
if ( V_2 -> V_182 . Type . V_228 == V_237 )
V_419 = V_272 ;
else
V_419 = V_38 ;
V_269 = V_2 -> V_31 ;
V_271 = 0 ;
V_420 = 0 ;
for ( V_20 = 0 ; V_20 < V_415 ; V_20 ++ ) {
if ( ( ( V_271 + 1 ) == ( V_1 -> V_30 ) ) &&
! V_420 && ( ( V_415 - V_20 ) > 1 ) ) {
V_269 = V_1 -> V_18 [ V_2 -> V_137 ] ;
V_271 = 0 ;
V_420 = 1 ;
}
V_269 [ V_271 ] . V_37 = V_418 [ V_20 ] . V_78 ;
V_28 . V_36 = ( V_139 ) F_201 ( V_1 -> V_24 , F_202 ( & V_418 [ V_20 ] ) ,
V_418 [ V_20 ] . V_429 ,
V_418 [ V_20 ] . V_78 , V_419 ) ;
V_269 [ V_271 ] . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_269 [ V_271 ] . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_269 [ V_271 ] . V_41 = 0 ;
++ V_271 ;
}
if ( V_420 )
F_21 ( V_1 , V_2 , V_1 -> V_18 [ V_2 -> V_137 ] ,
( V_415 - ( V_1 -> V_30 - 1 ) ) *
sizeof( T_3 ) ) ;
if ( V_415 > V_1 -> V_55 )
V_1 -> V_55 = V_415 ;
F_87 ( & V_1 -> V_24 -> V_25 , L_91
L_92 ,
F_198 ( V_416 ) , V_415 , V_420 ) ;
V_2 -> V_7 . V_29 = V_415 + V_420 ;
if ( V_415 <= V_1 -> V_30 )
V_2 -> V_7 . V_8 = V_2 -> V_7 . V_29 ;
else
V_2 -> V_7 . V_8 = V_1 -> V_30 ;
F_2 ( V_1 , V_2 ) ;
if ( F_3 ( V_416 -> V_11 == V_408 ) ) {
if( V_1 -> V_307 == V_311 ) {
V_2 -> V_182 . V_336 [ 1 ] = 0 ;
V_2 -> V_182 . V_336 [ 2 ] = ( V_414 >> 24 ) & 0xff ;
V_2 -> V_182 . V_336 [ 3 ] = ( V_414 >> 16 ) & 0xff ;
V_2 -> V_182 . V_336 [ 4 ] = ( V_414 >> 8 ) & 0xff ;
V_2 -> V_182 . V_336 [ 5 ] = V_414 & 0xff ;
V_2 -> V_182 . V_336 [ 6 ] = 0 ;
V_2 -> V_182 . V_336 [ 7 ] = ( F_198 ( V_416 ) >> 8 ) & 0xff ;
V_2 -> V_182 . V_336 [ 8 ] = F_198 ( V_416 ) & 0xff ;
V_2 -> V_182 . V_336 [ 9 ] = V_2 -> V_182 . V_336 [ 11 ] = V_2 -> V_182 . V_336 [ 12 ] = 0 ;
} else {
T_12 V_430 = F_203 ( V_414 ) ;
V_2 -> V_182 . V_337 = 16 ;
V_2 -> V_182 . V_336 [ 1 ] = 0 ;
V_2 -> V_182 . V_336 [ 2 ] = ( V_430 >> 24 ) & 0xff ;
V_2 -> V_182 . V_336 [ 3 ] = ( V_430 >> 16 ) & 0xff ;
V_2 -> V_182 . V_336 [ 4 ] = ( V_430 >> 8 ) & 0xff ;
V_2 -> V_182 . V_336 [ 5 ] = V_430 & 0xff ;
V_2 -> V_182 . V_336 [ 6 ] = ( V_414 >> 24 ) & 0xff ;
V_2 -> V_182 . V_336 [ 7 ] = ( V_414 >> 16 ) & 0xff ;
V_2 -> V_182 . V_336 [ 8 ] = ( V_414 >> 8 ) & 0xff ;
V_2 -> V_182 . V_336 [ 9 ] = V_414 & 0xff ;
V_2 -> V_182 . V_336 [ 10 ] = ( F_198 ( V_416 ) >> 24 ) & 0xff ;
V_2 -> V_182 . V_336 [ 11 ] = ( F_198 ( V_416 ) >> 16 ) & 0xff ;
V_2 -> V_182 . V_336 [ 12 ] = ( F_198 ( V_416 ) >> 8 ) & 0xff ;
V_2 -> V_182 . V_336 [ 13 ] = F_198 ( V_416 ) & 0xff ;
V_2 -> V_182 . V_336 [ 14 ] = V_2 -> V_182 . V_336 [ 15 ] = 0 ;
}
} else if ( V_416 -> V_11 == V_273 ) {
V_2 -> V_182 . V_337 = V_416 -> V_431 ;
memcpy ( V_2 -> V_182 . V_336 , V_416 -> V_157 , V_432 ) ;
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_93 ,
V_416 -> V_11 ) ;
F_204 () ;
}
F_205 ( V_329 -> V_425 ) ;
F_4 ( & V_1 -> V_15 , V_2 ) ;
V_1 -> V_16 ++ ;
if ( V_1 -> V_16 > V_1 -> V_17 )
V_1 -> V_17 = V_1 -> V_16 ;
goto V_144;
V_423:
F_206 ( V_329 ) ;
V_421:
F_12 ( V_1 ) ;
}
static inline unsigned long F_207 ( T_1 * V_1 )
{
return V_1 -> V_387 . V_433 ( V_1 ) ;
}
static inline int F_208 ( T_1 * V_1 )
{
return V_1 -> V_387 . V_434 ( V_1 ) ;
}
static inline long F_209 ( T_1 * V_1 )
{
return ( ( V_1 -> V_387 . V_434 ( V_1 ) == 0 ) ||
( V_1 -> V_435 == 0 ) ) ;
}
static inline int F_210 ( T_1 * V_1 , T_12 V_436 ,
T_12 V_437 )
{
if ( F_211 ( V_436 >= V_1 -> V_19 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_94 , V_437 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_212 ( T_1 * V_1 , T_2 * V_2 ,
T_12 V_437 )
{
F_6 ( V_2 ) ;
if ( F_3 ( V_2 -> V_11 == V_426 ) )
F_182 ( V_1 , V_2 , 0 ) ;
else if ( V_2 -> V_11 == V_231 )
F_213 ( V_2 -> V_236 ) ;
#ifdef F_25
else if ( V_2 -> V_11 == V_438 )
F_214 ( V_2 , 0 , V_437 ) ;
#endif
}
static inline T_12 F_215 ( T_1 * V_1 )
{
T_12 V_439 ;
if ( F_211 ( ! ( V_1 -> V_3 & V_4 ) ) )
return V_1 -> V_387 . V_433 ( V_1 ) ;
if ( ( * ( V_1 -> V_440 ) & 1 ) == ( V_1 -> V_441 ) ) {
V_439 = * ( V_1 -> V_440 ) ;
( V_1 -> V_440 ) ++ ;
V_1 -> V_53 -- ;
} else {
V_439 = V_442 ;
}
if ( V_1 -> V_440 == ( V_1 -> V_443 + V_1 -> V_444 ) ) {
V_1 -> V_440 = V_1 -> V_443 ;
V_1 -> V_441 ^= 1 ;
}
return V_439 ;
}
static inline T_12 F_216 ( T_1 * V_1 , T_12 V_437 )
{
T_12 V_436 ;
T_2 * V_2 ;
V_436 = F_186 ( V_437 ) ;
if ( F_210 ( V_1 , V_436 , V_437 ) )
return F_215 ( V_1 ) ;
V_2 = V_1 -> V_130 + V_436 ;
F_212 ( V_1 , V_2 , V_437 ) ;
return F_215 ( V_1 ) ;
}
static inline T_12 F_217 ( T_1 * V_1 , T_12 V_437 )
{
T_2 * V_2 = NULL ;
V_138 V_445 , V_446 ;
V_446 = F_83 ( V_1 , V_437 ) ;
F_218 (c, &h->cmpQ, list) {
V_445 = F_83 ( V_1 , V_2 -> V_5 ) ;
if ( V_445 == V_446 ) {
F_212 ( V_1 , V_2 , V_437 ) ;
return F_215 ( V_1 ) ;
}
}
F_210 ( V_1 , V_1 -> V_19 + 1 , V_437 ) ;
return F_215 ( V_1 ) ;
}
static int F_219 ( T_1 * V_1 )
{
if ( F_3 ( ! V_447 ) )
return 0 ;
if ( F_3 ( V_1 -> V_435 ) )
return 0 ;
F_174 ( & V_1 -> V_24 -> V_25 , L_95
L_96 ) ;
return 1 ;
}
static T_37 F_220 ( int V_448 , void * V_449 )
{
T_1 * V_1 = V_449 ;
unsigned long V_13 ;
T_12 V_437 ;
if ( F_219 ( V_1 ) )
return V_450 ;
if ( F_209 ( V_1 ) )
return V_450 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
while ( F_208 ( V_1 ) ) {
V_437 = F_207 ( V_1 ) ;
while ( V_437 != V_442 )
V_437 = F_215 ( V_1 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_451 ;
}
static T_37 F_221 ( int V_448 , void * V_449 )
{
T_1 * V_1 = V_449 ;
unsigned long V_13 ;
T_12 V_437 ;
if ( F_219 ( V_1 ) )
return V_450 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_437 = F_207 ( V_1 ) ;
while ( V_437 != V_442 )
V_437 = F_215 ( V_1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_451 ;
}
static T_37 F_222 ( int V_448 , void * V_449 )
{
T_1 * V_1 = V_449 ;
unsigned long V_13 ;
T_12 V_437 ;
if ( F_209 ( V_1 ) )
return V_450 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
while ( F_208 ( V_1 ) ) {
V_437 = F_207 ( V_1 ) ;
while ( V_437 != V_442 ) {
if ( F_184 ( V_437 ) )
V_437 = F_216 ( V_1 , V_437 ) ;
else
V_437 = F_217 ( V_1 , V_437 ) ;
}
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_451 ;
}
static T_37 F_223 ( int V_448 , void * V_449 )
{
T_1 * V_1 = V_449 ;
unsigned long V_13 ;
T_12 V_437 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_437 = F_207 ( V_1 ) ;
while ( V_437 != V_442 ) {
if ( F_184 ( V_437 ) )
V_437 = F_216 ( V_1 , V_437 ) ;
else
V_437 = F_217 ( V_1 , V_437 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_451 ;
}
static int F_50 ( struct V_101 * V_1 )
{
struct V_101 * V_452 ;
int V_453 = 0 ;
int V_73 = 0 ;
if ( V_1 -> V_454 )
return 0 ;
if ( ! F_224 ( & V_1 -> V_455 ) )
return 0 ;
F_91 ( & V_456 ) ;
F_218 (test_h, &scan_q, scan_list) {
if ( V_452 == V_1 ) {
V_453 = 1 ;
break;
}
}
if ( ! V_453 && ! V_1 -> V_457 ) {
F_172 ( V_1 -> V_104 ) ;
F_5 ( & V_1 -> V_458 , & V_459 ) ;
V_73 = 1 ;
}
F_92 ( & V_456 ) ;
F_92 ( & V_1 -> V_455 ) ;
return V_73 ;
}
static void F_225 ( struct V_101 * V_1 )
{
struct V_101 * V_452 , * V_460 ;
F_91 ( & V_456 ) ;
F_226 (test_h, tmp_h, &scan_q, scan_list) {
if ( V_452 == V_1 ) {
F_227 ( & V_1 -> V_458 ) ;
F_228 ( & V_1 -> V_104 ) ;
F_92 ( & V_456 ) ;
return;
}
}
if ( V_1 -> V_457 ) {
F_92 ( & V_456 ) ;
F_125 ( & V_1 -> V_104 ) ;
} else {
F_92 ( & V_456 ) ;
}
}
static int F_229 ( void * V_76 )
{
struct V_101 * V_1 ;
while ( 1 ) {
F_230 ( V_461 ) ;
F_231 () ;
if ( F_232 () )
break;
while ( 1 ) {
F_91 ( & V_456 ) ;
if ( F_8 ( & V_459 ) ) {
F_92 ( & V_456 ) ;
break;
}
V_1 = F_178 ( V_459 . V_386 ,
struct V_101 ,
V_458 ) ;
F_227 ( & V_1 -> V_458 ) ;
V_1 -> V_457 = 1 ;
F_92 ( & V_456 ) ;
F_128 ( V_1 , 0 , 0 ) ;
F_228 ( & V_1 -> V_104 ) ;
F_91 ( & V_456 ) ;
V_1 -> V_457 = 0 ;
F_92 ( & V_456 ) ;
}
}
return 0 ;
}
static int F_106 ( T_1 * V_1 , T_2 * V_2 )
{
if ( V_2 -> V_132 -> V_357 [ 2 ] != V_462 )
return 0 ;
switch ( V_2 -> V_132 -> V_357 [ 12 ] ) {
case V_463 :
F_154 ( & V_1 -> V_24 -> V_25 , L_97
L_98 ) ;
return 1 ;
break;
case V_464 :
F_154 ( & V_1 -> V_24 -> V_25 , L_99
L_100 ) ;
return 1 ;
break;
case V_465 :
F_154 ( & V_1 -> V_24 -> V_25 , L_101 ) ;
return 1 ;
break;
case V_466 :
F_154 ( & V_1 -> V_24 -> V_25 ,
L_102 ) ;
return 1 ;
break;
case V_467 :
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
char V_468 [ 17 ] ;
T_38 * V_469 = V_1 -> V_204 ;
F_87 ( & V_1 -> V_24 -> V_25 , L_105 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_106 ) ;
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ )
V_468 [ V_20 ] = F_115 ( & ( V_469 -> V_470 [ V_20 ] ) ) ;
V_468 [ 4 ] = '\0' ;
F_87 ( & V_1 -> V_24 -> V_25 , L_107 , V_468 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_108 ,
F_110 ( & ( V_469 -> V_471 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_109 ,
F_110 ( & ( V_469 -> V_472 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_110 ,
F_110 ( & ( V_469 -> V_473 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_111 ,
F_110 ( & ( V_469 -> V_205 . V_474 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_112 ,
F_110 ( & ( V_469 -> V_205 . V_206 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_113 ,
F_110 ( & ( V_469 -> V_205 . V_207 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_114 ,
F_110 ( & ( V_469 -> V_475 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_115 ,
F_110 ( & ( V_469 -> V_217 ) ) ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
V_468 [ V_20 ] = F_115 ( & ( V_469 -> V_214 [ V_20 ] ) ) ;
V_468 [ 16 ] = '\0' ;
F_87 ( & V_1 -> V_24 -> V_25 , L_116 , V_468 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_117 ,
F_110 ( & ( V_469 -> V_216 ) ) ) ;
}
static int F_234 ( struct V_476 * V_24 , unsigned long V_477 )
{
int V_20 , V_429 , V_478 , V_479 ;
if ( V_477 == V_480 )
return 0 ;
V_429 = 0 ;
for ( V_20 = 0 ; V_20 < V_481 ; V_20 ++ ) {
V_479 = F_235 ( V_24 , V_20 ) & V_482 ;
if ( V_479 == V_483 )
V_429 += 4 ;
else {
V_478 = F_235 ( V_24 , V_20 ) &
V_484 ;
switch ( V_478 ) {
case V_485 :
case V_486 :
V_429 += 4 ;
break;
case V_487 :
V_429 += 8 ;
break;
default:
F_154 ( & V_24 -> V_25 ,
L_118 ) ;
return - 1 ;
break;
}
}
if ( V_429 == V_477 - V_480 )
return V_20 + 1 ;
}
return - 1 ;
}
static void F_236 ( int V_488 [] , int V_489 ,
int V_490 , int * V_491 )
{
int V_20 , V_22 , V_492 , V_332 ;
#define F_237 4
#define F_238 8
for ( V_20 = 0 ; V_20 <= V_490 ; V_20 ++ ) {
V_332 = V_20 + F_237 ;
V_492 = V_489 ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
if ( V_488 [ V_22 ] >= V_332 ) {
V_492 = V_22 ;
break;
}
}
V_491 [ V_20 ] = V_492 ;
}
}
static void T_11 F_239 ( T_1 * V_1 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_493 ; V_20 ++ ) {
if ( ! ( F_110 ( V_1 -> V_209 + V_210 ) & V_208 ) )
break;
F_240 ( 10000 , 20000 ) ;
}
}
static T_11 void F_241 ( T_1 * V_1 ,
T_12 V_494 )
{
V_138 V_495 ;
int V_496 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_247 + 4 } ;
unsigned long V_497 ;
F_242 ( 28 > V_247 + 4 ) ;
V_1 -> V_441 = 1 ;
memset ( V_1 -> V_443 , 0 , V_1 -> V_444 * sizeof( V_139 ) ) ;
V_1 -> V_440 = V_1 -> V_443 ;
V_495 = F_110 ( & ( V_1 -> V_204 -> V_498 ) ) ;
F_236 ( V_496 , F_44 ( V_496 ) , V_1 -> V_298 ,
V_1 -> V_6 ) ;
F_112 ( V_496 [ 0 ] , & V_1 -> V_499 -> V_500 ) ;
F_112 ( V_496 [ 1 ] , & V_1 -> V_499 -> V_501 ) ;
F_112 ( V_496 [ 2 ] , & V_1 -> V_499 -> V_502 ) ;
F_112 ( V_496 [ 3 ] , & V_1 -> V_499 -> V_503 ) ;
F_112 ( V_496 [ 4 ] , & V_1 -> V_499 -> V_504 ) ;
F_112 ( V_496 [ 5 ] , & V_1 -> V_499 -> V_505 ) ;
F_112 ( V_496 [ 6 ] , & V_1 -> V_499 -> V_506 ) ;
F_112 ( V_496 [ 7 ] , & V_1 -> V_499 -> V_507 ) ;
F_112 ( V_1 -> V_444 , & V_1 -> V_499 -> V_508 ) ;
F_112 ( 1 , & V_1 -> V_499 -> V_509 ) ;
F_112 ( 0 , & V_1 -> V_499 -> V_510 ) ;
F_112 ( 0 , & V_1 -> V_499 -> V_511 ) ;
F_112 ( V_1 -> V_512 , & V_1 -> V_499 -> V_513 ) ;
F_112 ( 0 , & V_1 -> V_499 -> V_514 ) ;
F_112 ( V_4 | V_494 ,
& ( V_1 -> V_204 -> V_205 . V_474 ) ) ;
F_112 ( V_208 , V_1 -> V_209 + V_210 ) ;
F_239 ( V_1 ) ;
V_497 = F_110 ( & ( V_1 -> V_204 -> V_473 ) ) ;
if ( ! ( V_497 & V_4 ) )
F_154 ( & V_1 -> V_24 -> V_25 , L_119
L_120 ) ;
}
static void T_11 F_243 ( T_1 * V_1 )
{
V_138 V_515 ;
if ( V_516 )
return;
F_87 ( & V_1 -> V_24 -> V_25 , L_121 ) ;
V_515 = F_110 ( & ( V_1 -> V_204 -> V_472 ) ) ;
if ( ! ( V_515 & V_517 ) )
return;
F_87 ( & V_1 -> V_24 -> V_25 , L_122 ) ;
if ( ( sizeof( T_2 ) % 32 ) != 0 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_123 ,
L_124 ,
( int ) sizeof( T_2 ) ,
L_125 ) ;
return;
}
V_1 -> V_443 = ( V_139 * ) F_78 (
V_1 -> V_24 , V_1 -> V_444 * sizeof( V_139 ) ,
& ( V_1 -> V_512 ) ) ;
V_1 -> V_6 = F_17 ( ( ( V_1 -> V_298 + 1 ) *
sizeof( V_138 ) ) , V_23 ) ;
if ( ( V_1 -> V_443 == NULL ) || ( V_1 -> V_6 == NULL ) )
goto V_518;
F_241 ( V_1 ,
V_515 & V_519 ) ;
V_1 -> V_387 = V_520 ;
V_1 -> V_3 = V_4 ;
return;
V_518:
F_15 ( V_1 -> V_6 ) ;
if ( V_1 -> V_443 )
F_79 ( V_1 -> V_24 ,
V_1 -> V_444 * sizeof( V_139 ) ,
V_1 -> V_443 ,
V_1 -> V_512 ) ;
return;
}
static void T_11 F_244 ( T_1 * V_1 )
{
#ifdef F_245
int V_80 ;
struct V_521 V_522 [ 4 ] = { { 0 , 0 } , { 0 , 1 } ,
{ 0 , 2 } , { 0 , 3 }
} ;
if ( ( V_1 -> V_48 == 0x40700E11 ) || ( V_1 -> V_48 == 0x40800E11 ) ||
( V_1 -> V_48 == 0x40820E11 ) || ( V_1 -> V_48 == 0x40830E11 ) )
goto V_523;
if ( F_246 ( V_1 -> V_24 , V_524 ) ) {
V_80 = F_247 ( V_1 -> V_24 , V_522 , 4 ) ;
if ( ! V_80 ) {
V_1 -> V_50 [ 0 ] = V_522 [ 0 ] . V_525 ;
V_1 -> V_50 [ 1 ] = V_522 [ 1 ] . V_525 ;
V_1 -> V_50 [ 2 ] = V_522 [ 2 ] . V_525 ;
V_1 -> V_50 [ 3 ] = V_522 [ 3 ] . V_525 ;
V_1 -> V_526 = 1 ;
return;
}
if ( V_80 > 0 ) {
F_154 ( & V_1 -> V_24 -> V_25 ,
L_126 , V_80 ) ;
goto V_523;
} else {
F_154 ( & V_1 -> V_24 -> V_25 ,
L_127 , V_80 ) ;
goto V_523;
}
}
if ( F_246 ( V_1 -> V_24 , V_527 ) ) {
if ( ! F_248 ( V_1 -> V_24 ) )
V_1 -> V_528 = 1 ;
else
F_154 ( & V_1 -> V_24 -> V_25 , L_128 ) ;
}
V_523:
#endif
V_1 -> V_50 [ V_1 -> V_51 ] = V_1 -> V_24 -> V_448 ;
return;
}
static int T_11 F_249 ( struct V_476 * V_24 , T_12 * V_48 )
{
int V_20 ;
T_12 V_529 , V_530 ;
V_529 = V_24 -> V_531 ;
V_530 = V_24 -> V_532 ;
* V_48 = ( ( V_530 << 16 ) & 0xffff0000 ) |
V_529 ;
for ( V_20 = 0 ; V_20 < F_44 ( V_533 ) ; V_20 ++ )
if ( * V_48 == V_533 [ V_20 ] . V_48 )
return V_20 ;
F_154 ( & V_24 -> V_25 , L_129 ,
* V_48 ) ;
return - V_534 ;
}
static inline bool F_250 ( T_1 * V_1 )
{
T_39 V_535 ;
( void ) F_251 ( V_1 -> V_24 , V_536 , & V_535 ) ;
return ( ( V_535 & V_537 ) == 0 ) ;
}
static int T_11 F_252 ( struct V_476 * V_24 ,
unsigned long * V_538 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_481 ; V_20 ++ )
if ( F_235 ( V_24 , V_20 ) & V_539 ) {
* V_538 = F_253 ( V_24 , V_20 ) ;
F_87 ( & V_24 -> V_25 , L_130 ,
* V_538 ) ;
return 0 ;
}
F_154 ( & V_24 -> V_25 , L_131 ) ;
return - V_534 ;
}
static int T_11 F_254 ( struct V_476 * V_24 ,
void T_35 * V_209 , int V_540 )
#define F_255 1
#define F_256 0
{
int V_20 , V_541 ;
T_12 V_542 ;
if ( V_540 )
V_541 = V_543 ;
else
V_541 = V_544 ;
for ( V_20 = 0 ; V_20 < V_541 ; V_20 ++ ) {
V_542 = F_110 ( V_209 + V_545 ) ;
if ( V_540 ) {
if ( V_542 == V_546 )
return 0 ;
} else {
if ( V_542 != V_546 )
return 0 ;
}
F_257 ( V_547 ) ;
}
F_154 ( & V_24 -> V_25 , L_132 ) ;
return - V_534 ;
}
static int T_11 F_258 ( struct V_476 * V_24 ,
void T_35 * V_209 , T_12 * V_548 , T_40 * V_549 ,
T_40 * V_550 )
{
* V_548 = F_110 ( V_209 + V_551 ) ;
* V_550 = F_110 ( V_209 + V_552 ) ;
* V_548 &= ( T_12 ) 0x0000ffff ;
* V_549 = F_234 ( V_24 , * V_548 ) ;
if ( * V_549 == - 1 ) {
F_154 ( & V_24 -> V_25 , L_133
L_134 , * V_548 ) ;
return - V_534 ;
}
return 0 ;
}
static int T_11 F_259 ( T_1 * V_1 )
{
T_40 V_550 ;
T_12 V_548 ;
T_40 V_549 ;
T_12 V_495 ;
int V_281 ;
V_281 = F_258 ( V_1 -> V_24 , V_1 -> V_209 , & V_548 ,
& V_549 , & V_550 ) ;
if ( V_281 )
return V_281 ;
V_1 -> V_204 = F_176 ( F_253 ( V_1 -> V_24 ,
V_549 ) + V_550 , sizeof( V_1 -> V_204 ) ) ;
if ( ! V_1 -> V_204 )
return - V_84 ;
V_281 = F_260 ( V_1 -> V_204 ) ;
if ( V_281 )
return V_281 ;
V_495 = F_110 ( & V_1 -> V_204 -> V_498 ) ;
V_1 -> V_499 = F_176 ( F_253 ( V_1 -> V_24 ,
V_549 ) + V_550 + V_495 ,
sizeof( * V_1 -> V_499 ) ) ;
if ( ! V_1 -> V_499 )
return - V_84 ;
return 0 ;
}
static void T_11 F_261 ( struct V_101 * V_1 )
{
V_1 -> V_444 = F_110 ( & ( V_1 -> V_204 -> V_553 ) ) ;
if ( V_447 && V_1 -> V_444 > 32 )
V_1 -> V_444 = 32 ;
if ( V_1 -> V_444 < 16 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_135
L_136
L_137 ,
V_1 -> V_444 ) ;
V_1 -> V_444 = 16 ;
}
}
static void T_11 F_262 ( T_1 * V_1 )
{
F_261 ( V_1 ) ;
V_1 -> V_19 = V_1 -> V_444 - 4 - V_554 ;
V_1 -> V_298 = F_110 ( & ( V_1 -> V_204 -> V_555 ) ) ;
V_1 -> V_30 = 31 ;
if ( V_1 -> V_298 > 512 ) {
V_1 -> V_30 = 32 ;
V_1 -> V_21 = V_1 -> V_298 - V_1 -> V_30 + 1 ;
V_1 -> V_298 -- ;
} else {
V_1 -> V_298 = 31 ;
V_1 -> V_21 = 0 ;
}
}
static inline bool F_263 ( T_1 * V_1 )
{
if ( ( F_115 ( & V_1 -> V_204 -> V_470 [ 0 ] ) != 'C' ) ||
( F_115 ( & V_1 -> V_204 -> V_470 [ 1 ] ) != 'I' ) ||
( F_115 ( & V_1 -> V_204 -> V_470 [ 2 ] ) != 'S' ) ||
( F_115 ( & V_1 -> V_204 -> V_470 [ 3 ] ) != 'S' ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_138 ) ;
return false ;
}
return true ;
}
static inline void F_264 ( T_1 * V_1 )
{
#ifdef F_265
T_12 V_556 ;
V_556 = F_110 ( & ( V_1 -> V_204 -> V_557 ) ) ;
V_556 |= 0x100 ;
F_112 ( V_556 , & ( V_1 -> V_204 -> V_557 ) ) ;
#endif
}
static inline void F_266 ( T_1 * V_1 )
{
T_12 V_558 ;
V_138 V_559 ;
if ( V_1 -> V_48 != 0x3225103C )
return;
V_558 = F_110 ( V_1 -> V_209 + V_560 ) ;
V_558 |= 0x8000 ;
F_112 ( V_558 , V_1 -> V_209 + V_560 ) ;
F_267 ( V_1 -> V_24 , V_561 , & V_559 ) ;
V_559 |= 0x1 ;
F_268 ( V_1 -> V_24 , V_561 , V_559 ) ;
}
static int T_11 F_269 ( T_1 * V_1 )
{
int V_562 , V_80 ;
V_562 = F_249 ( V_1 -> V_24 , & V_1 -> V_48 ) ;
if ( V_562 < 0 )
return - V_534 ;
V_1 -> V_47 = V_533 [ V_562 ] . V_47 ;
V_1 -> V_387 = * ( V_533 [ V_562 ] . V_387 ) ;
if ( F_250 ( V_1 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_139 ) ;
return - V_534 ;
}
F_270 ( V_1 -> V_24 , V_563 |
V_564 | V_565 ) ;
V_80 = F_271 ( V_1 -> V_24 ) ;
if ( V_80 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_140 ) ;
return V_80 ;
}
V_80 = F_272 ( V_1 -> V_24 , L_141 ) ;
if ( V_80 ) {
F_154 ( & V_1 -> V_24 -> V_25 ,
L_142 ) ;
return V_80 ;
}
F_87 ( & V_1 -> V_24 -> V_25 , L_143 , V_1 -> V_24 -> V_448 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_144 , V_1 -> V_48 ) ;
F_244 ( V_1 ) ;
V_80 = F_252 ( V_1 -> V_24 , & V_1 -> V_566 ) ;
if ( V_80 )
goto V_567;
V_1 -> V_209 = F_176 ( V_1 -> V_566 , 0x250 ) ;
if ( ! V_1 -> V_209 ) {
V_80 = - V_84 ;
goto V_567;
}
V_80 = F_254 ( V_1 -> V_24 , V_1 -> V_209 , F_255 ) ;
if ( V_80 )
goto V_567;
V_80 = F_259 ( V_1 ) ;
if ( V_80 )
goto V_567;
F_233 ( V_1 ) ;
F_262 ( V_1 ) ;
if ( ! F_263 ( V_1 ) ) {
V_80 = - V_534 ;
goto V_567;
}
F_264 ( V_1 ) ;
F_266 ( V_1 ) ;
V_80 = F_273 ( V_1 ) ;
if ( V_80 )
goto V_567;
F_243 ( V_1 ) ;
return 0 ;
V_567:
if ( V_1 -> V_499 )
F_274 ( V_1 -> V_499 ) ;
if ( V_1 -> V_204 )
F_274 ( V_1 -> V_204 ) ;
if ( V_1 -> V_209 )
F_274 ( V_1 -> V_209 ) ;
F_275 ( V_1 -> V_24 ) ;
return V_80 ;
}
static int F_276 ( struct V_476 * V_24 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_568 ; V_20 ++ ) {
if ( ! V_268 [ V_20 ] ) {
T_1 * V_1 ;
V_1 = F_127 ( sizeof( T_1 ) , V_23 ) ;
if ( ! V_1 )
goto V_569;
V_268 [ V_20 ] = V_1 ;
return V_20 ;
}
}
F_154 ( & V_24 -> V_25 , L_145
L_146 , V_568 ) ;
return - 1 ;
V_569:
F_154 ( & V_24 -> V_25 , L_147 ) ;
return - 1 ;
}
static void F_277 ( T_1 * V_1 )
{
int V_20 ;
V_268 [ V_1 -> V_62 ] = NULL ;
for ( V_20 = 0 ; V_20 < V_1 -> V_64 + 1 ; V_20 ++ )
if ( V_1 -> V_142 [ V_20 ] != NULL )
F_160 ( V_1 -> V_142 [ V_20 ] ) ;
F_15 ( V_1 ) ;
}
static T_11 int F_278 ( struct V_476 * V_24 , unsigned char V_570 , unsigned char type )
{
typedef struct {
T_41 V_571 ;
T_42 V_182 ;
T_43 V_572 ;
} T_44;
static const T_10 V_573 = sizeof( T_44 ) + sizeof( V_134 ) ;
T_44 * V_157 ;
T_14 V_574 ;
T_29 V_575 , V_412 ;
void T_35 * V_209 ;
int V_20 , V_80 ;
V_209 = F_279 ( F_253 ( V_24 , 0 ) , F_280 ( V_24 , 0 ) ) ;
if ( V_209 == NULL )
return - V_84 ;
V_80 = F_281 ( V_24 , F_282 ( 32 ) ) ;
if ( V_80 ) {
F_274 ( V_209 ) ;
return - V_84 ;
}
V_157 = F_78 ( V_24 , V_573 , & V_574 ) ;
if ( V_157 == NULL ) {
F_274 ( V_209 ) ;
return - V_84 ;
}
V_575 = V_574 ;
V_157 -> V_571 . V_232 = 0 ;
V_157 -> V_571 . V_8 = 0 ;
V_157 -> V_571 . V_29 = 0 ;
V_157 -> V_571 . V_234 . V_33 = V_575 ;
V_157 -> V_571 . V_234 . V_35 = 0 ;
memset ( & V_157 -> V_571 . V_233 . V_335 , 0 , 8 ) ;
V_157 -> V_182 . V_337 = 16 ;
V_157 -> V_182 . Type . Type = V_349 ;
V_157 -> V_182 . Type . V_338 = V_576 ;
V_157 -> V_182 . Type . V_228 = V_229 ;
V_157 -> V_182 . V_340 = 0 ;
V_157 -> V_182 . V_336 [ 0 ] = V_570 ;
V_157 -> V_182 . V_336 [ 1 ] = type ;
memset ( & V_157 -> V_182 . V_336 [ 2 ] , 0 , 14 ) ;
V_157 -> V_572 . V_34 . V_33 = V_575 + sizeof( T_44 ) ;
V_157 -> V_572 . V_34 . V_35 = 0 ;
V_157 -> V_572 . V_37 = sizeof( V_134 ) ;
F_112 ( V_575 , V_209 + V_577 ) ;
for ( V_20 = 0 ; V_20 < 10 ; V_20 ++ ) {
V_412 = F_110 ( V_209 + V_578 ) ;
if ( ( V_412 & ~ 3 ) == V_575 )
break;
F_257 ( V_579 ) ;
}
F_274 ( V_209 ) ;
if ( V_20 == 10 ) {
F_18 ( & V_24 -> V_25 ,
L_148 ,
V_570 , type ) ;
return - V_580 ;
}
F_79 ( V_24 , V_573 , V_157 , V_574 ) ;
if ( V_412 & 2 ) {
F_18 ( & V_24 -> V_25 , L_149 ,
V_570 , type ) ;
return - V_277 ;
}
F_174 ( & V_24 -> V_25 , L_150 ,
V_570 , type ) ;
return 0 ;
}
static int F_283 ( struct V_476 * V_24 ,
void * T_35 V_209 , T_12 V_581 )
{
T_39 V_582 ;
int V_56 ;
if ( V_581 ) {
F_174 ( & V_24 -> V_25 , L_151 ) ;
F_112 ( V_581 , V_209 + V_210 ) ;
} else {
V_56 = F_246 ( V_24 , V_583 ) ;
if ( V_56 == 0 ) {
F_18 ( & V_24 -> V_25 ,
L_152
L_153 ) ;
return - V_534 ;
}
F_174 ( & V_24 -> V_25 , L_154 ) ;
F_251 ( V_24 , V_56 + V_584 , & V_582 ) ;
V_582 &= ~ V_585 ;
V_582 |= V_586 ;
F_284 ( V_24 , V_56 + V_584 , V_582 ) ;
F_257 ( 500 ) ;
V_582 &= ~ V_585 ;
V_582 |= V_587 ;
F_284 ( V_24 , V_56 + V_584 , V_582 ) ;
F_257 ( 500 ) ;
}
return 0 ;
}
static T_11 void F_285 ( char * V_588 , int V_40 )
{
memset ( V_588 , 0 , V_40 ) ;
strncpy ( V_588 , L_155 V_589 , V_40 - 1 ) ;
}
static T_11 int F_260 (
T_38 T_35 * V_204 )
{
char * V_588 ;
int V_20 , V_332 = sizeof( V_204 -> V_588 ) ;
V_588 = F_17 ( V_332 , V_23 ) ;
if ( ! V_588 )
return - V_84 ;
F_285 ( V_588 , V_332 ) ;
for ( V_20 = 0 ; V_20 < V_332 ; V_20 ++ )
F_117 ( V_588 [ V_20 ] , & V_204 -> V_588 [ V_20 ] ) ;
F_15 ( V_588 ) ;
return 0 ;
}
static T_11 void F_286 (
T_38 T_35 * V_204 , unsigned char * V_590 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < sizeof( V_204 -> V_588 ) ; V_20 ++ )
V_590 [ V_20 ] = F_115 ( & V_204 -> V_588 [ V_20 ] ) ;
}
static T_11 int F_287 (
T_38 T_35 * V_204 )
{
char * V_590 , * V_591 ;
int V_281 , V_332 = sizeof( V_204 -> V_588 ) ;
V_591 = F_17 ( 2 * V_332 , V_23 ) ;
if ( ! V_591 )
return - V_84 ;
V_590 = V_591 + V_332 ;
F_285 ( V_591 , V_332 ) ;
F_286 ( V_204 , V_590 ) ;
V_281 = ! memcmp ( V_590 , V_591 , V_332 ) ;
F_15 ( V_591 ) ;
return V_281 ;
}
static T_11 int F_288 ( struct V_476 * V_24 )
{
T_40 V_550 ;
T_12 V_548 ;
T_40 V_549 ;
void T_35 * V_209 ;
unsigned long V_566 ;
T_12 V_592 ;
int V_281 ;
T_38 T_35 * V_204 ;
T_12 V_581 ;
T_12 V_48 ;
T_39 V_593 ;
F_249 ( V_24 , & V_48 ) ;
if ( ! F_46 ( V_48 ) ) {
F_154 ( & V_24 -> V_25 , L_156
L_157 ) ;
return - V_534 ;
}
if ( ! F_43 ( V_48 ) )
return - V_594 ;
F_251 ( V_24 , 4 , & V_593 ) ;
F_289 ( V_24 ) ;
F_290 ( V_24 ) ;
V_281 = F_252 ( V_24 , & V_566 ) ;
if ( V_281 )
return V_281 ;
V_209 = F_176 ( V_566 , 0x250 ) ;
if ( ! V_209 )
return - V_84 ;
V_281 = F_258 ( V_24 , V_209 , & V_548 ,
& V_549 , & V_550 ) ;
if ( V_281 )
goto V_595;
V_204 = F_176 ( F_253 ( V_24 ,
V_549 ) + V_550 , sizeof( * V_204 ) ) ;
if ( ! V_204 ) {
V_281 = - V_84 ;
goto V_595;
}
V_281 = F_260 ( V_204 ) ;
if ( V_281 )
goto V_595;
V_592 = F_110 ( & V_204 -> V_592 ) ;
V_581 = V_592 & V_596 ;
if ( V_581 ) {
V_581 = V_597 ;
} else {
V_581 = V_592 & V_598 ;
if ( V_581 ) {
F_154 ( & V_24 -> V_25 , L_158
L_159
L_160
L_161 ) ;
V_281 = - V_594 ;
goto V_599;
}
}
V_281 = F_283 ( V_24 , V_209 , V_581 ) ;
if ( V_281 )
goto V_599;
F_291 ( V_24 ) ;
V_281 = F_271 ( V_24 ) ;
if ( V_281 ) {
F_154 ( & V_24 -> V_25 , L_162 ) ;
goto V_599;
}
F_284 ( V_24 , 4 , V_593 ) ;
F_257 ( V_600 ) ;
F_174 ( & V_24 -> V_25 , L_163 ) ;
V_281 = F_254 ( V_24 , V_209 , F_256 ) ;
if ( V_281 ) {
F_154 ( & V_24 -> V_25 , L_164
L_165 ) ;
V_281 = - V_594 ;
goto V_599;
}
V_281 = F_254 ( V_24 , V_209 , F_255 ) ;
if ( V_281 ) {
F_154 ( & V_24 -> V_25 ,
L_166
L_167 ) ;
goto V_599;
}
V_281 = F_287 ( V_209 ) ;
if ( V_281 < 0 )
goto V_599;
if ( V_281 ) {
F_154 ( & V_24 -> V_25 , L_168
L_169 ) ;
V_281 = - V_594 ;
} else {
F_174 ( & V_24 -> V_25 , L_170 ) ;
}
V_599:
F_274 ( V_204 ) ;
V_595:
F_274 ( V_209 ) ;
return V_281 ;
}
static T_11 int F_292 ( struct V_476 * V_24 )
{
int V_281 , V_20 ;
if ( ! V_447 )
return 0 ;
V_281 = F_288 ( V_24 ) ;
if ( V_281 == - V_594 )
return V_281 ;
if ( V_281 )
return - V_534 ;
F_154 ( & V_24 -> V_25 , L_171 ) ;
for ( V_20 = 0 ; V_20 < V_601 ; V_20 ++ ) {
if ( F_293 ( V_24 ) == 0 )
break;
else
F_154 ( & V_24 -> V_25 , L_172 ,
( V_20 < V_601 - 1 ?
L_173 : L_174 ) ) ;
F_257 ( V_602 ) ;
}
return 0 ;
}
static T_11 int F_294 ( T_1 * V_1 )
{
V_1 -> V_128 = F_17 (
F_295 ( V_1 -> V_19 , V_129 ) *
sizeof( unsigned long ) , V_23 ) ;
V_1 -> V_130 = F_78 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( T_2 ) ,
& ( V_1 -> V_131 ) ) ;
V_1 -> V_133 = F_78 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( V_134 ) ,
& ( V_1 -> V_135 ) ) ;
if ( ( V_1 -> V_128 == NULL )
|| ( V_1 -> V_130 == NULL )
|| ( V_1 -> V_133 == NULL ) ) {
F_18 ( & V_1 -> V_24 -> V_25 , L_175 ) ;
return - V_84 ;
}
return 0 ;
}
static T_11 int F_296 ( T_1 * V_1 )
{
int V_20 ;
V_1 -> V_424 = F_127 ( V_1 -> V_444 *
sizeof( struct V_417 * ) , V_23 ) ;
if ( ! V_1 -> V_424 )
return - V_84 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_19 ; V_20 ++ ) {
V_1 -> V_424 [ V_20 ] = F_17 ( sizeof( struct V_417 ) *
V_1 -> V_298 , V_23 ) ;
if ( V_1 -> V_424 [ V_20 ] == NULL ) {
F_18 ( & V_1 -> V_24 -> V_25 , L_176
L_177 ) ;
return - V_84 ;
}
}
return 0 ;
}
static void F_297 ( T_1 * V_1 )
{
int V_20 ;
if ( V_1 -> V_424 ) {
for ( V_20 = 0 ; V_20 < V_1 -> V_19 ; V_20 ++ )
F_15 ( V_1 -> V_424 [ V_20 ] ) ;
F_15 ( V_1 -> V_424 ) ;
}
}
static void F_298 ( T_1 * V_1 )
{
F_15 ( V_1 -> V_128 ) ;
if ( V_1 -> V_130 )
F_79 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( T_2 ) ,
V_1 -> V_130 , V_1 -> V_131 ) ;
if ( V_1 -> V_133 )
F_79 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( V_134 ) ,
V_1 -> V_133 , V_1 -> V_135 ) ;
}
static int F_299 ( T_1 * V_1 ,
T_37 (* F_300)( int , void * ) ,
T_37 (* F_301)( int , void * ) )
{
if ( V_1 -> V_526 || V_1 -> V_528 ) {
if ( ! F_302 ( V_1 -> V_50 [ V_1 -> V_51 ] , F_300 ,
0 , V_1 -> V_46 , V_1 ) )
return 0 ;
F_18 ( & V_1 -> V_24 -> V_25 , L_178
L_179 , V_1 -> V_50 [ V_1 -> V_51 ] ,
V_1 -> V_46 ) ;
return - 1 ;
}
if ( ! F_302 ( V_1 -> V_50 [ V_1 -> V_51 ] , F_301 ,
V_603 , V_1 -> V_46 , V_1 ) )
return 0 ;
F_18 ( & V_1 -> V_24 -> V_25 , L_180 ,
V_1 -> V_50 [ V_1 -> V_51 ] , V_1 -> V_46 ) ;
return - 1 ;
}
static int T_11 F_303 ( T_1 * V_1 )
{
if ( F_168 ( V_1 , V_153 , V_604 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_181 ) ;
return - V_277 ;
}
F_174 ( & V_1 -> V_24 -> V_25 , L_182 ) ;
if ( F_254 ( V_1 -> V_24 , V_1 -> V_209 , F_256 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_183 ) ;
return - 1 ;
}
F_174 ( & V_1 -> V_24 -> V_25 , L_184 ) ;
if ( F_254 ( V_1 -> V_24 , V_1 -> V_209 , F_255 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_185
L_186 ) ;
return - 1 ;
}
return 0 ;
}
static void F_304 ( T_1 * V_1 )
{
int V_62 = V_1 -> V_62 ;
F_305 ( V_1 -> V_50 [ V_1 -> V_51 ] , V_1 ) ;
#ifdef F_245
if ( V_1 -> V_526 )
F_306 ( V_1 -> V_24 ) ;
else if ( V_1 -> V_528 )
F_307 ( V_1 -> V_24 ) ;
#endif
F_14 ( V_1 -> V_18 , V_1 -> V_19 ) ;
F_297 ( V_1 ) ;
F_298 ( V_1 ) ;
F_15 ( V_1 -> V_6 ) ;
if ( V_1 -> V_443 )
F_79 ( V_1 -> V_24 , V_1 -> V_444 * sizeof( V_139 ) ,
V_1 -> V_443 , V_1 -> V_512 ) ;
if ( V_1 -> V_499 )
F_274 ( V_1 -> V_499 ) ;
if ( V_1 -> V_204 )
F_274 ( V_1 -> V_204 ) ;
if ( V_1 -> V_209 )
F_274 ( V_1 -> V_209 ) ;
F_308 ( V_1 -> V_290 , V_1 -> V_46 ) ;
F_67 ( V_1 ) ;
F_275 ( V_1 -> V_24 ) ;
F_15 ( V_1 ) ;
V_268 [ V_62 ] = NULL ;
}
static int T_11 F_309 ( struct V_476 * V_24 ,
const struct V_605 * V_606 )
{
int V_20 ;
int V_22 = 0 ;
int V_281 ;
int V_607 = 0 ;
int V_608 , V_319 ;
T_30 * V_303 ;
T_1 * V_1 ;
unsigned long V_13 ;
V_281 = F_292 ( V_24 ) ;
if ( V_281 ) {
if ( V_281 != - V_594 )
return V_281 ;
V_607 = 1 ;
V_281 = 0 ;
}
V_609:
V_20 = F_276 ( V_24 ) ;
if ( V_20 < 0 )
return - 1 ;
V_1 = V_268 [ V_20 ] ;
V_1 -> V_24 = V_24 ;
V_1 -> V_454 = 1 ;
V_1 -> V_51 = V_516 ? V_610 : V_611 ;
F_76 ( & V_1 -> V_390 ) ;
F_76 ( & V_1 -> V_15 ) ;
F_310 ( & V_1 -> V_455 ) ;
if ( F_269 ( V_1 ) != 0 )
goto V_612;
sprintf ( V_1 -> V_46 , L_187 , V_20 ) ;
V_1 -> V_62 = V_20 ;
if ( V_554 < 2 )
V_554 = 2 ;
if ( V_554 > 16 )
V_554 = 16 ;
F_311 ( & V_1 -> V_104 ) ;
if ( F_63 ( V_1 ) )
goto V_613;
if ( ! F_312 ( V_24 , F_282 ( 64 ) ) )
V_608 = 1 ;
else if ( ! F_312 ( V_24 , F_282 ( 32 ) ) )
V_608 = 0 ;
else {
F_18 ( & V_1 -> V_24 -> V_25 , L_188 ) ;
goto V_614;
}
if ( V_20 < V_615 )
V_1 -> V_290 = V_616 + V_20 ;
V_281 = F_313 ( V_1 -> V_290 , V_1 -> V_46 ) ;
if ( V_281 == - V_58 || V_281 == - V_82 ) {
F_18 ( & V_1 -> V_24 -> V_25 ,
L_189
L_190 , V_1 -> V_290 , V_1 -> V_46 , V_20 ) ;
goto V_614;
} else {
if ( V_20 >= V_615 )
V_1 -> V_290 = V_281 ;
}
V_1 -> V_387 . V_617 ( V_1 , V_618 ) ;
V_281 = F_299 ( V_1 , F_223 , F_222 ) ;
if ( V_281 )
goto V_619;
F_174 ( & V_1 -> V_24 -> V_25 , L_191 ,
V_1 -> V_46 , V_24 -> V_98 , F_314 ( V_24 ) ,
V_1 -> V_50 [ V_1 -> V_51 ] , V_608 ? L_174 : L_192 ) ;
if ( F_294 ( V_1 ) )
goto V_620;
if ( F_296 ( V_1 ) )
goto V_620;
V_1 -> V_18 = F_16 ( V_1 ,
V_1 -> V_21 , V_1 -> V_19 ) ;
if ( ! V_1 -> V_18 && V_1 -> V_21 > 0 )
goto V_620;
F_315 ( & V_1 -> V_14 ) ;
F_316 ( V_24 , V_1 ) ;
memset ( V_1 -> V_128 , 0 ,
F_295 ( V_1 -> V_19 , V_129 )
* sizeof( unsigned long ) ) ;
V_1 -> V_52 = 0 ;
V_1 -> V_64 = - 1 ;
for ( V_22 = 0 ; V_22 < V_315 ; V_22 ++ ) {
V_1 -> V_63 [ V_22 ] = NULL ;
V_1 -> V_142 [ V_22 ] = NULL ;
}
if ( V_607 ) {
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_1 -> V_387 . V_617 ( V_1 , V_618 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
F_305 ( V_1 -> V_50 [ V_1 -> V_51 ] , V_1 ) ;
V_281 = F_299 ( V_1 , F_221 ,
F_220 ) ;
if ( V_281 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_193
L_194 ) ;
goto V_620;
}
V_281 = F_303 ( V_1 ) ;
if ( V_281 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_195 ) ;
goto V_620;
}
F_174 ( & V_1 -> V_24 -> V_25 , L_196 ) ;
F_174 ( & V_1 -> V_24 -> V_25 ,
L_197 ) ;
V_1 -> V_387 . V_617 ( V_1 , V_621 ) ;
F_257 ( 10000 ) ;
V_1 -> V_387 . V_617 ( V_1 , V_618 ) ;
V_281 = F_287 ( V_1 -> V_204 ) ;
if ( V_281 )
F_174 ( & V_1 -> V_24 -> V_25 ,
L_198 ) ;
F_304 ( V_1 ) ;
V_607 = 0 ;
if ( V_281 )
return - V_534 ;
goto V_609;
}
F_317 ( V_1 ) ;
V_1 -> V_387 . V_617 ( V_1 , V_621 ) ;
V_303 = F_127 ( sizeof( T_30 ) , V_23 ) ;
if ( V_303 == NULL ) {
F_18 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
goto V_620;
}
V_319 = F_137 ( V_1 , V_283 , V_303 ,
sizeof( T_30 ) , 0 , V_153 , V_284 ) ;
if ( V_319 == V_285 ) {
V_1 -> V_49 [ 0 ] = V_303 -> V_286 [ 32 ] ;
V_1 -> V_49 [ 1 ] = V_303 -> V_286 [ 33 ] ;
V_1 -> V_49 [ 2 ] = V_303 -> V_286 [ 34 ] ;
V_1 -> V_49 [ 3 ] = V_303 -> V_286 [ 35 ] ;
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_199
L_200 ) ;
}
F_15 ( V_303 ) ;
F_1 ( V_1 ) ;
V_1 -> V_299 = 8192 ;
F_128 ( V_1 , 1 , 0 ) ;
F_39 ( V_1 ) ;
V_1 -> V_454 = 0 ;
return 1 ;
V_620:
F_298 ( V_1 ) ;
F_297 ( V_1 ) ;
F_14 ( V_1 -> V_18 , V_1 -> V_19 ) ;
F_305 ( V_1 -> V_50 [ V_1 -> V_51 ] , V_1 ) ;
V_619:
F_308 ( V_1 -> V_290 , V_1 -> V_46 ) ;
V_614:
F_67 ( V_1 ) ;
V_613:
F_275 ( V_24 ) ;
V_612:
V_1 -> V_454 = 0 ;
F_316 ( V_24 , NULL ) ;
F_277 ( V_1 ) ;
return - 1 ;
}
static void F_318 ( struct V_476 * V_24 )
{
T_1 * V_1 ;
char * V_622 ;
int V_319 ;
V_1 = F_319 ( V_24 ) ;
V_622 = F_127 ( 4 , V_23 ) ;
if ( ! V_622 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_201 ) ;
return;
}
memset ( V_622 , 0 , 4 ) ;
V_319 = F_137 ( V_1 , V_344 , V_622 ,
4 , 0 , V_153 , V_284 ) ;
F_15 ( V_622 ) ;
if ( V_319 != V_285 )
F_154 ( & V_1 -> V_24 -> V_25 , L_202 ) ;
V_1 -> V_387 . V_617 ( V_1 , V_618 ) ;
F_305 ( V_1 -> V_50 [ V_1 -> V_51 ] , V_1 ) ;
}
static int T_11 F_273 ( struct V_101 * V_1 )
{
T_12 V_515 ;
V_515 = F_110 ( & ( V_1 -> V_204 -> V_472 ) ) ;
if ( ! ( V_515 & V_623 ) )
return - V_594 ;
V_1 -> V_444 = F_110 ( & ( V_1 -> V_204 -> V_475 ) ) ;
F_112 ( V_624 , & ( V_1 -> V_204 -> V_205 . V_474 ) ) ;
F_112 ( V_208 , V_1 -> V_209 + V_210 ) ;
F_239 ( V_1 ) ;
F_233 ( V_1 ) ;
if ( ! ( F_110 ( & ( V_1 -> V_204 -> V_473 ) ) & V_624 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_203 ) ;
return - V_534 ;
}
V_1 -> V_3 = V_624 ;
return 0 ;
}
static void T_45 F_320 ( struct V_476 * V_24 )
{
T_1 * V_1 ;
int V_20 , V_22 ;
if ( F_319 ( V_24 ) == NULL ) {
F_18 ( & V_24 -> V_25 , L_204 ) ;
return;
}
V_1 = F_319 ( V_24 ) ;
V_20 = V_1 -> V_62 ;
if ( V_268 [ V_20 ] == NULL ) {
F_18 ( & V_24 -> V_25 , L_205 ) ;
return;
}
F_91 ( & V_1 -> V_455 ) ;
F_225 ( V_1 ) ;
F_321 ( V_1 -> V_46 , V_90 ) ;
F_308 ( V_1 -> V_290 , V_1 -> V_46 ) ;
for ( V_22 = 0 ; V_22 < V_315 ; V_22 ++ ) {
struct V_142 * V_143 = V_1 -> V_142 [ V_22 ] ;
if ( V_143 ) {
struct V_328 * V_329 = V_143 -> V_144 ;
if ( V_143 -> V_13 & V_330 ) {
F_72 ( V_1 , V_22 , 1 ) ;
F_166 ( V_143 ) ;
}
if ( V_329 )
F_149 ( V_329 ) ;
}
}
#ifdef F_25
F_322 ( V_1 ) ;
#endif
F_318 ( V_24 ) ;
#ifdef F_245
if ( V_1 -> V_526 )
F_306 ( V_1 -> V_24 ) ;
else if ( V_1 -> V_528 )
F_307 ( V_1 -> V_24 ) ;
#endif
F_274 ( V_1 -> V_499 ) ;
F_274 ( V_1 -> V_204 ) ;
F_274 ( V_1 -> V_209 ) ;
F_298 ( V_1 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_19 ; V_22 ++ )
F_15 ( V_1 -> V_424 [ V_22 ] ) ;
F_15 ( V_1 -> V_424 ) ;
F_14 ( V_1 -> V_18 , V_1 -> V_19 ) ;
F_15 ( V_1 -> V_6 ) ;
if ( V_1 -> V_443 )
F_79 ( V_1 -> V_24 , V_1 -> V_444 * sizeof( V_139 ) ,
V_1 -> V_443 , V_1 -> V_512 ) ;
F_275 ( V_24 ) ;
F_316 ( V_24 , NULL ) ;
F_67 ( V_1 ) ;
F_92 ( & V_1 -> V_455 ) ;
F_277 ( V_1 ) ;
}
static int T_46 F_323 ( void )
{
int V_80 ;
F_242 ( sizeof( T_2 ) % V_625 ) ;
F_324 (KERN_INFO DRIVER_NAME L_206 ) ;
V_80 = F_325 ( & V_121 ) ;
if ( V_80 )
return V_80 ;
V_103 = F_326 ( F_229 , NULL , L_207 ) ;
if ( F_327 ( V_103 ) ) {
V_80 = F_328 ( V_103 ) ;
goto V_626;
}
V_80 = F_329 ( & V_627 ) ;
if ( V_80 )
goto V_628;
return V_80 ;
V_628:
F_330 ( V_103 ) ;
V_626:
F_331 ( & V_121 ) ;
return V_80 ;
}
static void T_47 F_332 ( void )
{
int V_20 ;
F_333 ( & V_627 ) ;
for ( V_20 = 0 ; V_20 < V_568 ; V_20 ++ ) {
if ( V_268 [ V_20 ] != NULL ) {
F_154 ( & V_268 [ V_20 ] -> V_24 -> V_25 ,
L_208 ) ;
F_320 ( V_268 [ V_20 ] -> V_24 ) ;
}
}
F_330 ( V_103 ) ;
if ( V_90 )
F_321 ( L_15 , NULL ) ;
F_331 ( & V_121 ) ;
}
