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
V_80 = F_37 ( V_76 , V_77 ) ;
if ( F_38 ( V_80 ) )
return F_39 ( V_80 ) ;
#ifdef F_25
if ( strncmp ( V_83 , V_80 , sizeof V_83 - 1 ) == 0 ) {
struct V_43 * V_44 = V_72 -> V_75 ;
T_1 * V_1 = V_44 -> V_45 ;
V_79 = F_40 ( V_1 ) ;
if ( V_79 == 0 )
V_79 = V_77 ;
} else
#endif
V_79 = - V_81 ;
F_15 ( V_80 ) ;
return V_79 ;
}
static void F_1 ( T_1 * V_1 )
{
struct V_84 * V_85 ;
if ( V_86 == NULL )
V_86 = F_41 ( L_15 , NULL ) ;
if ( ! V_86 )
return;
V_85 = F_42 ( V_1 -> V_46 , V_87 | V_88 | V_89 |
V_90 , V_86 ,
& V_91 , V_1 ) ;
}
static int F_43 ( T_11 V_48 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < F_44 ( V_92 ) ; V_20 ++ )
if ( V_92 [ V_20 ] == V_48 )
return 0 ;
return 1 ;
}
static int F_45 ( T_11 V_48 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < F_44 ( V_93 ) ; V_20 ++ )
if ( V_93 [ V_20 ] == V_48 )
return 0 ;
return 1 ;
}
static int F_46 ( T_11 V_48 )
{
return F_43 ( V_48 ) ||
F_45 ( V_48 ) ;
}
static T_8 F_47 ( struct V_94 * V_25 ,
struct V_95 * V_96 ,
char * V_76 )
{
struct V_97 * V_1 = F_48 ( V_25 ) ;
return snprintf ( V_76 , 20 , L_16 , F_46 ( V_1 -> V_48 ) ) ;
}
static T_8 F_49 ( struct V_94 * V_25 ,
struct V_95 * V_96 ,
const char * V_76 , T_10 V_98 )
{
struct V_97 * V_1 = F_48 ( V_25 ) ;
F_50 ( V_1 ) ;
F_51 ( V_99 ) ;
F_52 ( & V_1 -> V_100 ) ;
return V_98 ;
}
static T_8 F_53 ( struct V_94 * V_25 ,
struct V_95 * V_96 ,
char * V_76 )
{
struct V_97 * V_1 = F_48 ( V_25 ) ;
return snprintf ( V_76 , 20 , L_17 ,
V_1 -> V_3 & V_4 ?
L_18 : L_19 ) ;
}
static T_8 F_54 ( struct V_94 * V_25 ,
struct V_95 * V_96 ,
char * V_76 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_97 * V_1 = F_48 ( V_63 -> V_25 . V_101 ) ;
T_12 V_102 [ 16 ] ;
unsigned long V_13 ;
int V_73 = 0 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 )
V_73 = - V_58 ;
else
memcpy ( V_102 , V_63 -> V_103 , sizeof( V_102 ) ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_73 )
return V_73 ;
else
return snprintf ( V_76 , 16 * 2 + 2 ,
L_20
L_21 ,
V_102 [ 0 ] , V_102 [ 1 ] , V_102 [ 2 ] , V_102 [ 3 ] ,
V_102 [ 4 ] , V_102 [ 5 ] , V_102 [ 6 ] , V_102 [ 7 ] ,
V_102 [ 8 ] , V_102 [ 9 ] , V_102 [ 10 ] , V_102 [ 11 ] ,
V_102 [ 12 ] , V_102 [ 13 ] , V_102 [ 14 ] , V_102 [ 15 ] ) ;
}
static T_8 F_56 ( struct V_94 * V_25 ,
struct V_95 * V_96 ,
char * V_76 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_97 * V_1 = F_48 ( V_63 -> V_25 . V_101 ) ;
char V_104 [ V_105 + 1 ] ;
unsigned long V_13 ;
int V_73 = 0 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 )
V_73 = - V_58 ;
else
memcpy ( V_104 , V_63 -> V_104 , V_105 + 1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_73 )
return V_73 ;
else
return snprintf ( V_76 , sizeof( V_104 ) + 1 , L_17 , V_63 -> V_104 ) ;
}
static T_8 F_57 ( struct V_94 * V_25 ,
struct V_95 * V_96 ,
char * V_76 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_97 * V_1 = F_48 ( V_63 -> V_25 . V_101 ) ;
char V_106 [ V_107 + 1 ] ;
unsigned long V_13 ;
int V_73 = 0 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 )
V_73 = - V_58 ;
else
memcpy ( V_106 , V_63 -> V_106 , V_107 + 1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_73 )
return V_73 ;
else
return snprintf ( V_76 , sizeof( V_106 ) + 1 , L_17 , V_63 -> V_106 ) ;
}
static T_8 F_58 ( struct V_94 * V_25 ,
struct V_95 * V_96 ,
char * V_76 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_97 * V_1 = F_48 ( V_63 -> V_25 . V_101 ) ;
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
return snprintf ( V_76 , sizeof( V_108 ) + 1 , L_17 , V_63 -> V_108 ) ;
}
static T_8 F_59 ( struct V_94 * V_25 ,
struct V_95 * V_96 , char * V_76 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_97 * V_1 = F_48 ( V_63 -> V_25 . V_101 ) ;
unsigned long V_13 ;
unsigned char V_110 [ 8 ] ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_58 ;
}
if ( ! V_63 -> V_65 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_111 ;
}
memcpy ( V_110 , V_63 -> V_112 , sizeof( V_110 ) ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
return snprintf ( V_76 , 20 , L_22 ,
V_110 [ 0 ] , V_110 [ 1 ] , V_110 [ 2 ] , V_110 [ 3 ] ,
V_110 [ 4 ] , V_110 [ 5 ] , V_110 [ 6 ] , V_110 [ 7 ] ) ;
}
static T_8 F_60 ( struct V_94 * V_25 ,
struct V_95 * V_96 , char * V_76 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_97 * V_1 = F_48 ( V_63 -> V_25 . V_101 ) ;
int V_113 ;
unsigned long V_13 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_58 ;
}
V_113 = V_63 -> V_68 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_113 < 0 || V_113 > V_69 )
V_113 = V_69 ;
return snprintf ( V_76 , strlen ( V_70 [ V_113 ] ) + 7 , L_23 ,
V_70 [ V_113 ] ) ;
}
static T_8 F_61 ( struct V_94 * V_25 ,
struct V_95 * V_96 , char * V_76 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
struct V_97 * V_1 = F_48 ( V_63 -> V_25 . V_101 ) ;
unsigned long V_13 ;
int V_98 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_58 ;
}
V_98 = V_63 -> V_114 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
return snprintf ( V_76 , 20 , L_16 , V_98 ) ;
}
static void F_62 ( struct V_94 * V_25 )
{
}
static int F_63 ( struct V_97 * V_1 )
{
F_64 ( & V_1 -> V_25 ) ;
V_1 -> V_25 . type = & V_115 ;
V_1 -> V_25 . V_116 = & V_117 ;
F_65 ( & V_1 -> V_25 , L_24 , V_1 -> V_46 ) ;
V_1 -> V_25 . V_101 = & V_1 -> V_24 -> V_25 ;
return F_66 ( & V_1 -> V_25 ) ;
}
static void F_67 ( struct V_97 * V_1 )
{
F_68 ( & V_1 -> V_25 ) ;
F_69 ( & V_1 -> V_25 ) ;
}
static void F_70 ( struct V_94 * V_25 )
{
T_7 * V_63 = F_55 ( V_25 ) ;
F_15 ( V_63 ) ;
}
static long F_71 ( struct V_97 * V_1 ,
int V_118 )
{
struct V_94 * V_25 ;
if ( V_1 -> V_63 [ V_118 ] -> V_119 )
return 0 ;
V_25 = & V_1 -> V_63 [ V_118 ] -> V_25 ;
F_64 ( V_25 ) ;
V_25 -> type = & V_120 ;
V_25 -> V_116 = & V_117 ;
F_65 ( V_25 , L_25 , V_1 -> V_62 , V_118 ) ;
V_25 -> V_101 = & V_1 -> V_25 ;
V_1 -> V_63 [ V_118 ] -> V_119 = 1 ;
return F_66 ( V_25 ) ;
}
static void F_72 ( struct V_97 * V_1 , int V_118 ,
int V_121 )
{
struct V_94 * V_25 = & V_1 -> V_63 [ V_118 ] -> V_25 ;
if ( V_118 == 0 && ! V_121 )
return;
F_68 ( V_25 ) ;
F_69 ( V_25 ) ;
V_1 -> V_63 [ V_118 ] = NULL ;
}
static T_2 * F_73 ( T_1 * V_1 )
{
T_2 * V_2 ;
int V_20 ;
T_4 V_28 ;
T_13 V_122 , V_123 ;
do {
V_20 = F_74 ( V_1 -> V_124 , V_1 -> V_19 ) ;
if ( V_20 == V_1 -> V_19 )
return NULL ;
} while ( F_75 ( V_20 , V_1 -> V_124 ) != 0 );
V_2 = V_1 -> V_125 + V_20 ;
memset ( V_2 , 0 , sizeof( T_2 ) ) ;
V_122 = V_1 -> V_126 + V_20 * sizeof( T_2 ) ;
V_2 -> V_127 = V_1 -> V_128 + V_20 ;
memset ( V_2 -> V_127 , 0 , sizeof( V_129 ) ) ;
V_123 = V_1 -> V_130
+ V_20 * sizeof( V_129 ) ;
V_1 -> V_131 ++ ;
V_2 -> V_132 = V_20 ;
F_76 ( & V_2 -> V_10 ) ;
V_2 -> V_5 = ( V_133 ) V_122 ;
V_28 . V_36 = ( V_134 ) V_123 ;
V_2 -> V_135 . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_135 . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_135 . V_37 = sizeof( V_129 ) ;
V_2 -> V_62 = V_1 -> V_62 ;
return V_2 ;
}
static T_2 * F_77 ( T_1 * V_1 )
{
T_2 * V_2 ;
T_4 V_28 ;
T_13 V_122 , V_123 ;
V_2 = F_78 ( V_1 -> V_24 , sizeof( T_2 ) ,
& V_122 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_132 = - 1 ;
V_2 -> V_127 = F_78 ( V_1 -> V_24 , sizeof( V_129 ) ,
& V_123 ) ;
if ( V_2 -> V_127 == NULL ) {
F_79 ( V_1 -> V_24 ,
sizeof( T_2 ) , V_2 , V_122 ) ;
return NULL ;
}
F_76 ( & V_2 -> V_10 ) ;
V_2 -> V_5 = ( V_133 ) V_122 ;
V_28 . V_36 = ( V_134 ) V_123 ;
V_2 -> V_135 . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_135 . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_135 . V_37 = sizeof( V_129 ) ;
V_2 -> V_62 = V_1 -> V_62 ;
return V_2 ;
}
static void F_80 ( T_1 * V_1 , T_2 * V_2 )
{
int V_20 ;
V_20 = V_2 - V_1 -> V_125 ;
F_81 ( V_20 , V_1 -> V_124 ) ;
V_1 -> V_136 ++ ;
}
static void F_82 ( T_1 * V_1 , T_2 * V_2 )
{
T_4 V_28 ;
V_28 . V_32 . V_33 = V_2 -> V_135 . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_2 -> V_135 . V_34 . V_35 ;
F_79 ( V_1 -> V_24 , sizeof( V_129 ) ,
V_2 -> V_127 , ( T_13 ) V_28 . V_36 ) ;
F_79 ( V_1 -> V_24 , sizeof( T_2 ) , V_2 ,
( T_13 ) F_83 ( V_1 , ( T_11 ) V_2 -> V_5 ) ) ;
}
static inline T_1 * F_84 ( struct V_137 * V_138 )
{
return V_138 -> V_139 -> V_140 ;
}
static inline T_7 * F_85 ( struct V_137 * V_138 )
{
return V_138 -> V_75 ;
}
static int F_86 ( struct V_141 * V_142 , T_14 V_143 )
{
T_1 * V_1 = F_84 ( V_142 -> V_144 ) ;
T_7 * V_63 = F_85 ( V_142 -> V_144 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_26 , V_142 -> V_144 -> V_145 ) ;
if ( V_63 -> V_57 )
return - V_58 ;
if ( V_63 -> V_65 == 0 ) {
if ( F_88 ( V_142 -> V_146 ) != 0 ) {
if ( F_88 ( V_142 -> V_146 ) & 0x0f ) {
return - V_147 ;
} else if ( memcmp ( V_63 -> V_112 , V_148 ,
sizeof( V_63 -> V_112 ) ) ) {
return - V_147 ;
}
}
if ( ! F_89 ( V_149 ) )
return - V_150 ;
}
V_63 -> V_114 ++ ;
V_1 -> V_114 ++ ;
return 0 ;
}
static int F_90 ( struct V_141 * V_142 , T_14 V_143 )
{
int V_73 ;
F_91 ( & V_151 ) ;
V_73 = F_86 ( V_142 , V_143 ) ;
F_92 ( & V_151 ) ;
return V_73 ;
}
static void F_93 ( struct V_137 * V_138 , T_14 V_143 )
{
T_1 * V_1 ;
T_7 * V_63 ;
F_91 ( & V_151 ) ;
V_1 = F_84 ( V_138 ) ;
V_63 = F_85 ( V_138 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_27 , V_138 -> V_145 ) ;
V_63 -> V_114 -- ;
V_1 -> V_114 -- ;
F_92 ( & V_151 ) ;
}
static int F_94 ( struct V_141 * V_142 , T_14 V_143 ,
unsigned V_152 , unsigned long V_153 )
{
switch ( V_152 ) {
case V_154 :
case V_155 :
case V_156 :
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
return F_95 ( V_142 , V_143 , V_152 , V_153 ) ;
case V_169 :
return F_96 ( V_142 , V_143 , V_152 , V_153 ) ;
case V_170 :
return F_97 ( V_142 , V_143 , V_152 , V_153 ) ;
default:
return - V_171 ;
}
}
static int F_96 ( struct V_141 * V_142 , T_14 V_143 ,
unsigned V_152 , unsigned long V_153 )
{
T_15 T_9 * V_172 =
( T_15 T_9 * ) V_153 ;
T_16 V_173 ;
T_16 T_9 * V_174 = F_98 ( sizeof( V_173 ) ) ;
int V_79 ;
T_11 V_175 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_79 = 0 ;
V_79 |=
F_99 ( & V_173 . V_176 , & V_172 -> V_176 ,
sizeof( V_173 . V_176 ) ) ;
V_79 |=
F_99 ( & V_173 . V_177 , & V_172 -> V_177 ,
sizeof( V_173 . V_177 ) ) ;
V_79 |=
F_99 ( & V_173 . V_178 , & V_172 -> V_178 ,
sizeof( V_173 . V_178 ) ) ;
V_79 |= F_100 ( V_173 . V_179 , & V_172 -> V_179 ) ;
V_79 |= F_100 ( V_175 , & V_172 -> V_76 ) ;
V_173 . V_76 = F_101 ( V_175 ) ;
V_79 |= F_102 ( V_174 , & V_173 , sizeof( V_173 ) ) ;
if ( V_79 )
return - V_180 ;
V_79 = F_95 ( V_142 , V_143 , V_181 , ( unsigned long ) V_174 ) ;
if ( V_79 )
return V_79 ;
V_79 |=
F_103 ( & V_172 -> V_178 , & V_174 -> V_178 ,
sizeof( V_172 -> V_178 ) ) ;
if ( V_79 )
return - V_180 ;
return V_79 ;
}
static int F_97 ( struct V_141 * V_142 , T_14 V_143 ,
unsigned V_152 , unsigned long V_153 )
{
T_17 T_9 * V_172 =
( T_17 T_9 * ) V_153 ;
T_18 V_173 ;
T_18 T_9 * V_174 =
F_98 ( sizeof( V_173 ) ) ;
int V_79 ;
T_11 V_175 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_79 = 0 ;
V_79 |=
F_99 ( & V_173 . V_176 , & V_172 -> V_176 ,
sizeof( V_173 . V_176 ) ) ;
V_79 |=
F_99 ( & V_173 . V_177 , & V_172 -> V_177 ,
sizeof( V_173 . V_177 ) ) ;
V_79 |=
F_99 ( & V_173 . V_178 , & V_172 -> V_178 ,
sizeof( V_173 . V_178 ) ) ;
V_79 |= F_100 ( V_173 . V_179 , & V_172 -> V_179 ) ;
V_79 |= F_100 ( V_173 . V_182 , & V_172 -> V_182 ) ;
V_79 |= F_100 ( V_175 , & V_172 -> V_76 ) ;
V_173 . V_76 = F_101 ( V_175 ) ;
V_79 |= F_102 ( V_174 , & V_173 , sizeof( V_173 ) ) ;
if ( V_79 )
return - V_180 ;
V_79 = F_95 ( V_142 , V_143 , V_183 , ( unsigned long ) V_174 ) ;
if ( V_79 )
return V_79 ;
V_79 |=
F_103 ( & V_172 -> V_178 , & V_174 -> V_178 ,
sizeof( V_172 -> V_178 ) ) ;
if ( V_79 )
return - V_180 ;
return V_79 ;
}
static int F_104 ( struct V_141 * V_142 , struct V_184 * V_185 )
{
T_7 * V_63 = F_85 ( V_142 -> V_144 ) ;
if ( ! V_63 -> V_186 )
return - V_147 ;
V_185 -> V_65 = V_63 -> V_65 ;
V_185 -> V_187 = V_63 -> V_187 ;
V_185 -> V_186 = V_63 -> V_186 ;
return 0 ;
}
static void F_105 ( T_1 * V_1 , T_2 * V_2 )
{
if ( V_2 -> V_127 -> V_188 == V_189 &&
V_2 -> V_127 -> V_190 != V_191 )
( void ) F_106 ( V_1 , V_2 ) ;
}
static int F_107 ( T_1 * V_1 , void T_9 * V_192 )
{
T_19 V_193 ;
if ( ! V_192 )
return - V_81 ;
V_193 . V_194 = F_108 ( V_1 -> V_24 -> V_116 ) ;
V_193 . V_116 = V_1 -> V_24 -> V_116 -> V_195 ;
V_193 . V_196 = V_1 -> V_24 -> V_197 ;
V_193 . V_48 = V_1 -> V_48 ;
if ( F_102 ( V_192 , & V_193 , sizeof( T_19 ) ) )
return - V_180 ;
return 0 ;
}
static int F_109 ( T_1 * V_1 , void T_9 * V_192 )
{
T_20 V_198 ;
unsigned long V_13 ;
if ( ! V_192 )
return - V_81 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_198 . V_199 = F_110 ( & V_1 -> V_200 -> V_201 . V_202 ) ;
V_198 . V_98 = F_110 ( & V_1 -> V_200 -> V_201 . V_203 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( F_102
( V_192 , & V_198 , sizeof( T_20 ) ) )
return - V_180 ;
return 0 ;
}
static int F_111 ( T_1 * V_1 , void T_9 * V_192 )
{
T_20 V_198 ;
unsigned long V_13 ;
int V_20 ;
if ( ! V_192 )
return - V_81 ;
if ( ! F_89 ( V_149 ) )
return - V_150 ;
if ( F_99 ( & V_198 , V_192 , sizeof( V_198 ) ) )
return - V_180 ;
if ( ( V_198 . V_199 == 0 ) && ( V_198 . V_98 == 0 ) )
return - V_81 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
F_112 ( V_198 . V_199 , & ( V_1 -> V_200 -> V_201 . V_202 ) ) ;
F_112 ( V_198 . V_98 , & ( V_1 -> V_200 -> V_201 . V_203 ) ) ;
F_112 ( V_204 , V_1 -> V_205 + V_206 ) ;
for ( V_20 = 0 ; V_20 < V_207 ; V_20 ++ ) {
if ( ! ( F_110 ( V_1 -> V_205 + V_206 ) & V_204 ) )
break;
F_113 ( 1000 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_20 >= V_207 )
return - V_208 ;
return 0 ;
}
static int F_114 ( T_1 * V_1 , void T_9 * V_192 )
{
T_21 V_209 ;
unsigned long V_13 ;
int V_20 ;
if ( ! V_192 )
return - V_81 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
V_209 [ V_20 ] = F_115 ( & V_1 -> V_200 -> V_210 [ V_20 ] ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( F_102 ( V_192 , V_209 , sizeof( T_21 ) ) )
return - V_180 ;
return 0 ;
}
static int F_116 ( T_1 * V_1 , void T_9 * V_192 )
{
T_21 V_209 ;
unsigned long V_13 ;
int V_20 ;
if ( ! V_192 )
return - V_81 ;
if ( ! F_89 ( V_149 ) )
return - V_150 ;
if ( F_99 ( V_209 , V_192 , sizeof( T_21 ) ) )
return - V_180 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
F_117 ( V_209 [ V_20 ] , & V_1 -> V_200 -> V_210 [ V_20 ] ) ;
F_112 ( V_204 , V_1 -> V_205 + V_206 ) ;
for ( V_20 = 0 ; V_20 < V_207 ; V_20 ++ ) {
if ( ! ( F_110 ( V_1 -> V_205 + V_206 ) & V_204 ) )
break;
F_113 ( 1000 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_20 >= V_207 )
return - V_208 ;
return 0 ;
}
static int F_118 ( T_1 * V_1 , void T_9 * V_192 )
{
T_22 V_211 ;
unsigned long V_13 ;
if ( ! V_192 )
return - V_81 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_211 = F_110 ( & V_1 -> V_200 -> V_212 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( F_102 ( V_192 , & V_211 , sizeof( T_22 ) ) )
return - V_180 ;
return 0 ;
}
static int F_119 ( T_1 * V_1 , void T_9 * V_192 )
{
T_23 V_213 ;
unsigned long V_13 ;
if ( ! V_192 )
return - V_81 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_213 = F_110 ( & V_1 -> V_200 -> V_213 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( F_102 ( V_192 , & V_213 , sizeof( T_23 ) ) )
return - V_180 ;
return 0 ;
}
static int F_120 ( T_1 * V_1 , void T_9 * V_192 )
{
T_24 V_214 ;
if ( ! V_192 )
return - V_81 ;
memcpy ( V_214 , V_1 -> V_49 , 4 ) ;
if ( F_102
( V_192 , V_214 , sizeof( T_24 ) ) )
return - V_180 ;
return 0 ;
}
static int F_121 ( T_1 * V_1 , void T_9 * V_192 )
{
T_25 V_215 = V_216 ;
if ( ! V_192 )
return - V_81 ;
if ( F_102 ( V_192 , & V_215 , sizeof( T_25 ) ) )
return - V_180 ;
return 0 ;
}
static int F_122 ( T_1 * V_1 ,
struct V_137 * V_138 , void T_9 * V_192 )
{
T_26 V_217 ;
T_7 * V_63 = F_85 ( V_138 ) ;
if ( ! V_192 )
return - V_81 ;
memcpy ( & V_217 . V_112 , V_63 -> V_112 , sizeof( V_217 . V_112 ) ) ;
V_217 . V_218 = V_63 -> V_114 ;
V_217 . V_219 = 0 ;
if ( F_102 ( V_192 , & V_217 , sizeof( T_26 ) ) )
return - V_180 ;
return 0 ;
}
static int F_123 ( T_1 * V_1 , void T_9 * V_192 )
{
T_16 V_220 ;
T_2 * V_2 ;
char * V_221 = NULL ;
T_4 V_28 ;
F_124 ( V_222 ) ;
if ( ! V_192 )
return - V_81 ;
if ( ! F_89 ( V_223 ) )
return - V_150 ;
if ( F_99
( & V_220 , V_192 , sizeof( T_16 ) ) )
return - V_180 ;
if ( ( V_220 . V_179 < 1 ) &&
( V_220 . V_177 . Type . V_224 != V_225 ) ) {
return - V_81 ;
}
if ( V_220 . V_179 > 0 ) {
V_221 = F_17 ( V_220 . V_179 , V_23 ) ;
if ( V_221 == NULL )
return - V_180 ;
}
if ( V_220 . V_177 . Type . V_224 == V_226 ) {
if ( F_99 ( V_221 , V_220 . V_76 , V_220 . V_179 ) ) {
F_15 ( V_221 ) ;
return - V_180 ;
}
} else {
memset ( V_221 , 0 , V_220 . V_179 ) ;
}
V_2 = F_77 ( V_1 ) ;
if ( ! V_2 ) {
F_15 ( V_221 ) ;
return - V_227 ;
}
V_2 -> V_11 = V_228 ;
V_2 -> V_7 . V_229 = 0 ;
if ( V_220 . V_179 > 0 ) {
V_2 -> V_7 . V_8 = 1 ;
V_2 -> V_7 . V_29 = 1 ;
} else {
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_7 . V_29 = 0 ;
}
V_2 -> V_7 . V_230 = V_220 . V_176 ;
V_2 -> V_7 . V_231 . V_33 = V_2 -> V_5 ;
V_2 -> V_177 = V_220 . V_177 ;
if ( V_220 . V_179 > 0 ) {
V_28 . V_36 = F_22 ( V_1 -> V_24 , V_221 ,
V_220 . V_179 , V_232 ) ;
V_2 -> V_31 [ 0 ] . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_31 [ 0 ] . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_31 [ 0 ] . V_37 = V_220 . V_179 ;
V_2 -> V_31 [ 0 ] . V_41 = 0 ;
}
V_2 -> V_233 = & V_222 ;
F_10 ( V_1 , V_2 ) ;
F_125 ( & V_222 ) ;
V_28 . V_32 . V_33 = V_2 -> V_31 [ 0 ] . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_2 -> V_31 [ 0 ] . V_34 . V_35 ;
F_20 ( V_1 -> V_24 , ( T_13 ) V_28 . V_36 , V_220 . V_179 ,
V_232 ) ;
F_105 ( V_1 , V_2 ) ;
V_220 . V_178 = * ( V_2 -> V_127 ) ;
if ( F_102 ( V_192 , & V_220 , sizeof( T_16 ) ) ) {
F_15 ( V_221 ) ;
F_82 ( V_1 , V_2 ) ;
return - V_180 ;
}
if ( V_220 . V_177 . Type . V_224 == V_234 ) {
if ( F_102 ( V_220 . V_76 , V_221 , V_220 . V_179 ) ) {
F_15 ( V_221 ) ;
F_82 ( V_1 , V_2 ) ;
return - V_180 ;
}
}
F_15 ( V_221 ) ;
F_82 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_126 ( T_1 * V_1 , void T_9 * V_192 )
{
T_18 * V_235 ;
T_2 * V_2 ;
unsigned char * * V_221 = NULL ;
int * V_236 = NULL ;
T_4 V_28 ;
T_27 V_237 = 0 ;
int V_238 = 0 ;
int V_20 ;
F_124 ( V_222 ) ;
V_133 V_239 ;
V_133 V_240 ;
T_27 T_9 * V_241 ;
if ( ! V_192 )
return - V_81 ;
if ( ! F_89 ( V_223 ) )
return - V_150 ;
V_235 = F_17 ( sizeof( * V_235 ) , V_23 ) ;
if ( ! V_235 ) {
V_238 = - V_227 ;
goto V_242;
}
if ( F_99 ( V_235 , V_192 , sizeof( * V_235 ) ) ) {
V_238 = - V_180 ;
goto V_242;
}
if ( ( V_235 -> V_179 < 1 ) &&
( V_235 -> V_177 . Type . V_224 != V_225 ) ) {
V_238 = - V_81 ;
goto V_242;
}
if ( V_235 -> V_182 > V_243 ) {
V_238 = - V_81 ;
goto V_242;
}
if ( V_235 -> V_179 > V_235 -> V_182 * V_244 ) {
V_238 = - V_81 ;
goto V_242;
}
V_221 = F_127 ( V_244 * sizeof( char * ) , V_23 ) ;
if ( ! V_221 ) {
V_238 = - V_227 ;
goto V_242;
}
V_236 = F_17 ( V_244 * sizeof( int ) , V_23 ) ;
if ( ! V_236 ) {
V_238 = - V_227 ;
goto V_242;
}
V_239 = V_235 -> V_179 ;
V_241 = V_235 -> V_76 ;
while ( V_239 ) {
V_240 = ( V_239 > V_235 -> V_182 ) ? V_235 -> V_182 : V_239 ;
V_236 [ V_237 ] = V_240 ;
V_221 [ V_237 ] = F_17 ( V_240 , V_23 ) ;
if ( V_221 [ V_237 ] == NULL ) {
V_238 = - V_227 ;
goto V_242;
}
if ( V_235 -> V_177 . Type . V_224 == V_226 ) {
if ( F_99 ( V_221 [ V_237 ] , V_241 , V_240 ) ) {
V_238 = - V_180 ;
goto V_242;
}
} else {
memset ( V_221 [ V_237 ] , 0 , V_240 ) ;
}
V_239 -= V_240 ;
V_241 += V_240 ;
V_237 ++ ;
}
V_2 = F_77 ( V_1 ) ;
if ( ! V_2 ) {
V_238 = - V_227 ;
goto V_242;
}
V_2 -> V_11 = V_228 ;
V_2 -> V_7 . V_229 = 0 ;
V_2 -> V_7 . V_8 = V_237 ;
V_2 -> V_7 . V_29 = V_237 ;
V_2 -> V_7 . V_230 = V_235 -> V_176 ;
V_2 -> V_7 . V_231 . V_33 = V_2 -> V_5 ;
V_2 -> V_177 = V_235 -> V_177 ;
for ( V_20 = 0 ; V_20 < V_237 ; V_20 ++ ) {
V_28 . V_36 = F_22 ( V_1 -> V_24 , V_221 [ V_20 ] , V_236 [ V_20 ] ,
V_232 ) ;
V_2 -> V_31 [ V_20 ] . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_31 [ V_20 ] . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_31 [ V_20 ] . V_37 = V_236 [ V_20 ] ;
V_2 -> V_31 [ V_20 ] . V_41 = 0 ;
}
V_2 -> V_233 = & V_222 ;
F_10 ( V_1 , V_2 ) ;
F_125 ( & V_222 ) ;
for ( V_20 = 0 ; V_20 < V_237 ; V_20 ++ ) {
V_28 . V_32 . V_33 = V_2 -> V_31 [ V_20 ] . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_2 -> V_31 [ V_20 ] . V_34 . V_35 ;
F_20 ( V_1 -> V_24 ,
( T_13 ) V_28 . V_36 , V_236 [ V_20 ] ,
V_232 ) ;
}
F_105 ( V_1 , V_2 ) ;
V_235 -> V_178 = * ( V_2 -> V_127 ) ;
if ( F_102 ( V_192 , V_235 , sizeof( * V_235 ) ) ) {
F_82 ( V_1 , V_2 ) ;
V_238 = - V_180 ;
goto V_242;
}
if ( V_235 -> V_177 . Type . V_224 == V_234 ) {
T_27 T_9 * V_245 = V_235 -> V_76 ;
for ( V_20 = 0 ; V_20 < V_237 ; V_20 ++ ) {
if ( F_102 ( V_245 , V_221 [ V_20 ] , V_236 [ V_20 ] ) ) {
F_82 ( V_1 , V_2 ) ;
V_238 = - V_180 ;
goto V_242;
}
V_245 += V_236 [ V_20 ] ;
}
}
F_82 ( V_1 , V_2 ) ;
V_238 = 0 ;
V_242:
if ( V_221 ) {
for ( V_20 = 0 ; V_20 < V_237 ; V_20 ++ )
F_15 ( V_221 [ V_20 ] ) ;
F_15 ( V_221 ) ;
}
F_15 ( V_236 ) ;
F_15 ( V_235 ) ;
return V_238 ;
}
static int F_95 ( struct V_141 * V_142 , T_14 V_143 ,
unsigned int V_152 , unsigned long V_153 )
{
struct V_137 * V_138 = V_142 -> V_144 ;
T_1 * V_1 = F_84 ( V_138 ) ;
void T_9 * V_192 = ( void T_9 * ) V_153 ;
F_87 ( & V_1 -> V_24 -> V_25 , L_28 ,
V_152 , V_153 ) ;
switch ( V_152 ) {
case V_154 :
return F_107 ( V_1 , V_192 ) ;
case V_155 :
return F_109 ( V_1 , V_192 ) ;
case V_156 :
return F_111 ( V_1 , V_192 ) ;
case V_157 :
return F_114 ( V_1 , V_192 ) ;
case V_158 :
return F_116 ( V_1 , V_192 ) ;
case V_159 :
return F_118 ( V_1 , V_192 ) ;
case V_160 :
return F_119 ( V_1 , V_192 ) ;
case V_161 :
return F_120 ( V_1 , V_192 ) ;
case V_162 :
return F_121 ( V_1 , V_192 ) ;
case V_164 :
case V_166 :
case V_163 :
return F_128 ( V_1 , 0 , 1 ) ;
case V_168 :
return F_122 ( V_1 , V_138 , V_192 ) ;
case V_181 :
return F_123 ( V_1 , V_192 ) ;
case V_183 :
return F_126 ( V_1 , V_192 ) ;
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
return F_129 ( V_142 , V_143 , V_152 , V_192 ) ;
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
default:
return - V_111 ;
}
}
static void F_130 ( T_1 * V_1 )
{
int V_259 = V_1 -> V_260 ;
int V_20 ;
if ( ( F_74 ( V_1 -> V_124 , V_1 -> V_19 ) ) == V_1 -> V_19 )
return;
for ( V_20 = 0 ; V_20 < V_1 -> V_64 + 1 ; V_20 ++ ) {
int V_261 = ( V_259 + V_20 ) % ( V_1 -> V_64 + 1 ) ;
if ( ! V_1 -> V_63 [ V_261 ] )
continue;
if ( ! ( V_1 -> V_63 [ V_261 ] -> V_139 ) ||
! ( V_1 -> V_63 [ V_261 ] -> V_65 ) )
continue;
F_131 ( V_1 -> V_137 [ V_261 ] -> V_139 ) ;
if ( ( F_74 ( V_1 -> V_124 , V_1 -> V_19 ) ) == V_1 -> V_19 ) {
if ( V_261 == V_259 ) {
V_1 -> V_260 =
( V_259 + 1 ) % ( V_1 -> V_64 + 1 ) ;
break;
} else {
V_1 -> V_260 = V_261 ;
break;
}
}
}
}
static void F_132 ( struct V_262 * V_263 )
{
T_2 * V_2 = V_263 -> V_264 ;
T_1 * V_1 = V_265 [ V_2 -> V_62 ] ;
T_3 * V_266 = V_2 -> V_31 ;
T_4 V_28 ;
unsigned long V_13 ;
int V_20 , V_267 ;
int V_268 = 0 ;
if ( V_2 -> V_177 . Type . V_224 == V_234 )
V_267 = V_269 ;
else
V_267 = V_38 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_7 . V_8 ; V_20 ++ ) {
if ( V_266 [ V_268 ] . V_41 == V_42 ) {
F_19 ( V_1 , V_2 ) ;
V_266 = V_1 -> V_18 [ V_2 -> V_132 ] ;
V_268 = 0 ;
}
V_28 . V_32 . V_33 = V_266 [ V_268 ] . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_266 [ V_268 ] . V_34 . V_35 ;
F_133 ( V_1 -> V_24 , V_28 . V_36 , V_266 [ V_268 ] . V_37 ,
V_267 ) ;
++ V_268 ;
}
F_87 ( & V_1 -> V_24 -> V_25 , L_29 , V_263 ) ;
if ( V_263 -> V_11 == V_270 )
V_263 -> V_271 = V_2 -> V_127 -> V_272 ;
F_134 ( V_263 , ( V_263 -> V_273 == 0 ) ? 0 : - V_274 ) ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
F_80 ( V_1 , V_2 ) ;
F_130 ( V_1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
}
static inline void F_135 ( T_1 * V_1 ,
unsigned char V_275 [] , T_28 V_276 )
{
memcpy ( V_275 , V_1 -> V_63 [ V_276 ] -> V_112 ,
sizeof( V_1 -> V_63 [ V_276 ] -> V_112 ) ) ;
}
static void F_136 ( T_1 * V_1 , int V_277 ,
char * V_104 , char * V_106 , char * V_108 )
{
int V_278 ;
T_29 * V_279 ;
unsigned char V_275 [ 8 ] ;
* V_104 = '\0' ;
* V_106 = '\0' ;
* V_108 = '\0' ;
V_279 = F_127 ( sizeof( T_29 ) , V_23 ) ;
if ( ! V_279 )
return;
F_135 ( V_1 , V_275 , V_277 ) ;
V_278 = F_137 ( V_1 , V_280 , V_279 , sizeof( * V_279 ) , 0 ,
V_275 , V_281 ) ;
if ( V_278 == V_282 ) {
memcpy ( V_104 , & V_279 -> V_283 [ 8 ] , V_105 ) ;
V_104 [ V_105 ] = '\0' ;
memcpy ( V_106 , & V_279 -> V_283 [ 16 ] , V_107 ) ;
V_106 [ V_107 ] = '\0' ;
memcpy ( V_108 , & V_279 -> V_283 [ 32 ] , V_109 ) ;
V_108 [ V_109 ] = '\0' ;
}
F_15 ( V_279 ) ;
return;
}
static void F_138 ( T_1 * V_1 , int V_277 ,
unsigned char * V_103 , int V_284 )
{
#define F_139 64
int V_278 ;
unsigned char * V_76 ;
unsigned char V_275 [ 8 ] ;
if ( V_284 > 16 )
V_284 = 16 ;
memset ( V_103 , 0xff , V_284 ) ;
V_76 = F_127 ( F_139 , V_23 ) ;
if ( ! V_76 )
return;
memset ( V_103 , 0 , V_284 ) ;
F_135 ( V_1 , V_275 , V_277 ) ;
V_278 = F_137 ( V_1 , V_280 , V_76 ,
F_139 , 0x83 , V_275 , V_281 ) ;
if ( V_278 == V_282 )
memcpy ( V_103 , & V_76 [ 8 ] , V_284 ) ;
F_15 ( V_76 ) ;
return;
}
static int F_140 ( T_1 * V_1 , struct V_137 * V_138 ,
int V_118 )
{
V_138 -> V_139 = F_141 ( V_285 , & V_1 -> V_14 ) ;
if ( ! V_138 -> V_139 )
goto V_286;
sprintf ( V_138 -> V_145 , L_30 , V_1 -> V_62 , V_118 ) ;
V_138 -> V_287 = V_1 -> V_287 ;
V_138 -> V_288 = V_118 << V_289 ;
V_138 -> V_290 = & V_291 ;
if ( F_71 ( V_1 , V_118 ) )
goto V_292;
V_138 -> V_75 = V_1 -> V_63 [ V_118 ] ;
V_138 -> V_293 = & V_1 -> V_63 [ V_118 ] -> V_25 ;
F_142 ( V_138 -> V_139 , V_1 -> V_24 -> V_294 ) ;
F_143 ( V_138 -> V_139 , V_1 -> V_295 ) ;
F_144 ( V_138 -> V_139 , V_1 -> V_296 ) ;
F_145 ( V_138 -> V_139 , F_132 ) ;
V_138 -> V_139 -> V_140 = V_1 ;
F_146 ( V_138 -> V_139 ,
V_1 -> V_63 [ V_118 ] -> V_297 ) ;
F_147 () ;
V_1 -> V_63 [ V_118 ] -> V_139 = V_138 -> V_139 ;
F_148 ( V_138 ) ;
return 0 ;
V_292:
F_149 ( V_138 -> V_139 ) ;
V_138 -> V_139 = NULL ;
V_286:
return - 1 ;
}
static void F_150 ( T_1 * V_1 , int V_118 ,
int V_298 , int V_299 )
{
struct V_137 * V_138 ;
T_29 * V_300 = NULL ;
unsigned int V_297 ;
T_6 V_301 ;
unsigned long V_13 = 0 ;
int V_73 = 0 ;
T_7 * V_302 ;
V_300 = F_17 ( sizeof( T_29 ) , V_23 ) ;
V_302 = F_127 ( sizeof( * V_302 ) , V_23 ) ;
if ( V_300 == NULL || V_302 == NULL )
goto V_303;
if ( V_1 -> V_304 == V_305 ) {
F_151 ( V_1 , V_118 ,
& V_301 , & V_297 ) ;
} else {
F_152 ( V_1 , V_118 , & V_301 , & V_297 ) ;
if ( V_301 == 0xFFFFFFFFULL ) {
F_151 ( V_1 , V_118 ,
& V_301 , & V_297 ) ;
V_1 -> V_304 = V_305 ;
V_1 -> V_306 = V_307 ;
} else {
V_1 -> V_304 = V_308 ;
V_1 -> V_306 = V_309 ;
}
}
F_153 ( V_1 , V_118 , V_301 , V_297 ,
V_300 , V_302 ) ;
V_302 -> V_297 = V_297 ;
V_302 -> V_66 = V_301 + 1 ;
F_136 ( V_1 , V_118 , V_302 -> V_104 ,
V_302 -> V_106 , V_302 -> V_108 ) ;
F_138 ( V_1 , V_118 , V_302 -> V_103 ,
sizeof( V_302 -> V_103 ) ) ;
memcpy ( V_302 -> V_112 , V_1 -> V_63 [ V_118 ] -> V_112 ,
sizeof( V_302 -> V_112 ) ) ;
if ( V_1 -> V_63 [ V_118 ] -> V_68 != - 1 &&
( ( memcmp ( V_302 -> V_103 ,
V_1 -> V_63 [ V_118 ] -> V_103 , 16 ) == 0 ) &&
V_302 -> V_297 == V_1 -> V_63 [ V_118 ] -> V_297 &&
V_302 -> V_66 == V_1 -> V_63 [ V_118 ] -> V_66 &&
V_302 -> V_65 == V_1 -> V_63 [ V_118 ] -> V_65 &&
V_302 -> V_187 == V_1 -> V_63 [ V_118 ] -> V_187 &&
V_302 -> V_186 == V_1 -> V_63 [ V_118 ] -> V_186 ) )
goto V_310;
if ( V_1 -> V_63 [ V_118 ] -> V_68 != - 1 && V_118 != 0 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_31 , V_118 ) ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_1 -> V_63 [ V_118 ] -> V_57 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
V_73 = F_155 ( V_1 , V_118 , 0 , V_299 ) ;
}
if ( V_73 )
goto V_310;
if ( V_1 -> V_63 [ V_118 ] == NULL ) {
V_302 -> V_119 = 0 ;
V_1 -> V_63 [ V_118 ] = V_302 ;
V_302 = NULL ;
} else {
V_1 -> V_63 [ V_118 ] -> V_297 = V_302 -> V_297 ;
V_1 -> V_63 [ V_118 ] -> V_66 = V_302 -> V_66 ;
V_1 -> V_63 [ V_118 ] -> V_65 = V_302 -> V_65 ;
V_1 -> V_63 [ V_118 ] -> V_187 = V_302 -> V_187 ;
V_1 -> V_63 [ V_118 ] -> V_186 = V_302 -> V_186 ;
V_1 -> V_63 [ V_118 ] -> V_68 = V_302 -> V_68 ;
memcpy ( V_1 -> V_63 [ V_118 ] -> V_103 , V_302 -> V_103 , 16 ) ;
memcpy ( V_1 -> V_63 [ V_118 ] -> V_104 , V_302 -> V_104 ,
V_105 + 1 ) ;
memcpy ( V_1 -> V_63 [ V_118 ] -> V_106 , V_302 -> V_106 , V_107 + 1 ) ;
memcpy ( V_1 -> V_63 [ V_118 ] -> V_108 , V_302 -> V_108 , V_109 + 1 ) ;
}
++ V_1 -> V_52 ;
V_138 = V_1 -> V_137 [ V_118 ] ;
F_156 ( V_138 , V_1 -> V_63 [ V_118 ] -> V_66 ) ;
if ( V_118 || V_298 ) {
if ( F_140 ( V_1 , V_138 , V_118 ) != 0 ) {
F_157 ( V_1 , V_118 ) ;
F_158 ( V_1 , V_118 ) ;
F_154 ( & V_1 -> V_24 -> V_25 , L_32 ,
V_118 ) ;
-- V_1 -> V_52 ;
}
}
V_310:
F_15 ( V_300 ) ;
F_15 ( V_302 ) ;
return;
V_303:
F_18 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
goto V_310;
}
static int F_159 ( T_1 * V_1 , int V_311 )
{
int V_20 ;
T_7 * V_63 ;
for ( V_20 = 0 ; V_20 < V_312 ; V_20 ++ ) {
if ( V_1 -> V_63 [ V_20 ] && V_20 != 0 )
continue;
if ( V_20 == 0 && V_1 -> V_63 [ V_20 ] && V_1 -> V_63 [ V_20 ] -> V_68 != - 1 )
continue;
if ( V_20 > V_1 -> V_64 && ! V_311 )
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
static void F_158 ( T_1 * V_1 , int V_118 )
{
F_15 ( V_1 -> V_63 [ V_118 ] ) ;
V_1 -> V_63 [ V_118 ] = NULL ;
}
static void F_157 ( T_1 * V_1 , int V_118 )
{
F_160 ( V_1 -> V_137 [ V_118 ] ) ;
V_1 -> V_137 [ V_118 ] = NULL ;
}
static int F_161 ( T_1 * V_1 , unsigned char V_110 [] ,
int V_311 )
{
int V_118 ;
V_118 = F_159 ( V_1 , V_311 ) ;
if ( V_118 == - 1 )
return - 1 ;
if ( ! V_1 -> V_137 [ V_118 ] ) {
V_1 -> V_137 [ V_118 ] =
F_162 ( 1 << V_289 ) ;
if ( ! V_1 -> V_137 [ V_118 ] ) {
F_18 ( & V_1 -> V_24 -> V_25 ,
L_34 ,
V_118 ) ;
goto V_313;
}
}
memcpy ( V_1 -> V_63 [ V_118 ] -> V_112 , V_110 ,
sizeof( V_1 -> V_63 [ V_118 ] -> V_112 ) ) ;
if ( F_71 ( V_1 , V_118 ) )
goto V_314;
V_1 -> V_63 [ V_118 ] -> V_57 = 0 ;
F_147 () ;
return V_118 ;
V_314:
F_157 ( V_1 , V_118 ) ;
V_313:
F_158 ( V_1 , V_118 ) ;
return - 1 ;
}
static void F_163 ( T_1 * V_1 )
{
struct V_137 * V_138 ;
int V_118 ;
if ( V_1 -> V_137 [ 0 ] != NULL )
return;
V_118 = F_161 ( V_1 , V_148 , 1 ) ;
if ( V_118 == - 1 )
goto error;
V_1 -> V_63 [ V_118 ] -> V_297 = 512 ;
V_1 -> V_63 [ V_118 ] -> V_66 = 0 ;
V_1 -> V_63 [ V_118 ] -> V_65 = 0 ;
V_1 -> V_63 [ V_118 ] -> V_187 = 0 ;
V_1 -> V_63 [ V_118 ] -> V_186 = 0 ;
V_1 -> V_63 [ V_118 ] -> V_68 = - 1 ;
memset ( V_1 -> V_63 [ V_118 ] -> V_103 , 0 , 16 ) ;
V_138 = V_1 -> V_137 [ V_118 ] ;
if ( F_140 ( V_1 , V_138 , V_118 ) == 0 )
return;
F_157 ( V_1 , V_118 ) ;
F_158 ( V_1 , V_118 ) ;
error:
F_154 ( & V_1 -> V_24 -> V_25 , L_35 ) ;
return;
}
static int F_128 ( T_1 * V_1 , int V_298 ,
int V_299 )
{
int V_52 ;
T_30 * V_315 = NULL ;
int V_316 ;
int V_317 = 0 ;
int V_20 ;
int V_318 ;
int V_118 = 0 ;
unsigned char V_110 [ 8 ] = V_148 ;
unsigned long V_13 ;
if ( ! F_89 ( V_223 ) )
return - V_150 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_57 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_58 ;
}
V_1 -> V_57 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
V_315 = F_127 ( sizeof( T_30 ) , V_23 ) ;
if ( V_315 == NULL )
goto V_303;
V_316 = F_137 ( V_1 , V_319 , V_315 ,
sizeof( T_30 ) ,
0 , V_148 , V_281 ) ;
if ( V_316 == V_282 )
V_317 = F_164 ( * ( V_320 * ) V_315 -> V_321 ) ;
else {
F_154 ( & V_1 -> V_24 -> V_25 ,
L_36 ) ;
V_317 = 0 ;
goto V_310;
}
V_52 = V_317 / 8 ;
if ( V_52 > V_312 ) {
V_52 = V_312 ;
F_154 ( & V_1 -> V_24 -> V_25 , L_37
L_38
L_39 ) ;
}
if ( V_52 == 0 )
F_163 ( V_1 ) ;
for ( V_20 = 0 ; V_20 <= V_1 -> V_64 ; V_20 ++ ) {
int V_22 ;
V_318 = 0 ;
if ( V_1 -> V_63 [ V_20 ] == NULL )
continue;
for ( V_22 = 0 ; V_22 < V_52 ; V_22 ++ ) {
memcpy ( V_110 , & V_315 -> V_230 [ V_22 ] [ 0 ] , sizeof( V_110 ) ) ;
if ( memcmp ( V_1 -> V_63 [ V_20 ] -> V_112 , V_110 ,
sizeof( V_110 ) ) == 0 ) {
V_318 = 1 ;
break;
}
}
if ( ! V_318 ) {
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_1 -> V_63 [ V_20 ] -> V_57 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
V_316 = F_155 ( V_1 , V_20 , 1 , V_299 ) ;
if ( V_1 -> V_63 [ V_20 ] != NULL )
V_1 -> V_63 [ V_20 ] -> V_57 = 0 ;
}
}
for ( V_20 = 0 ; V_20 < V_52 ; V_20 ++ ) {
int V_22 ;
V_318 = 0 ;
memcpy ( V_110 , & V_315 -> V_230 [ V_20 ] [ 0 ] , sizeof( V_110 ) ) ;
for ( V_22 = 0 ; V_22 <= V_1 -> V_64 ; V_22 ++ ) {
if ( V_1 -> V_63 [ V_22 ] != NULL &&
memcmp ( V_1 -> V_63 [ V_22 ] -> V_112 , V_110 ,
sizeof( V_1 -> V_63 [ V_22 ] -> V_112 ) ) == 0 ) {
V_118 = V_22 ;
V_318 = 1 ;
break;
}
}
if ( ! V_318 ) {
V_118 = F_161 ( V_1 , V_110 , 0 ) ;
if ( V_118 == - 1 )
goto V_310;
}
F_150 ( V_1 , V_118 , V_298 , V_299 ) ;
}
V_310:
F_15 ( V_315 ) ;
V_1 -> V_57 = 0 ;
return - 1 ;
V_303:
F_18 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
V_1 -> V_57 = 0 ;
goto V_310;
}
static void F_165 ( T_7 * V_322 )
{
V_322 -> V_66 = 0 ;
V_322 -> V_297 = 0 ;
V_322 -> V_65 = 0 ;
V_322 -> V_187 = 0 ;
V_322 -> V_186 = 0 ;
V_322 -> V_68 = - 1 ;
memset ( V_322 -> V_103 , 0 , sizeof( V_322 -> V_103 ) ) ;
memset ( V_322 -> V_106 , 0 , sizeof( V_322 -> V_106 ) ) ;
memset ( V_322 -> V_108 , 0 , sizeof( V_322 -> V_108 ) ) ;
memset ( V_322 -> V_104 , 0 , sizeof( V_322 -> V_104 ) ) ;
}
static int F_155 ( T_1 * V_1 , int V_118 ,
int V_323 , int V_299 )
{
int V_20 ;
struct V_137 * V_138 ;
T_7 * V_63 ;
int V_324 ;
if ( ! F_89 ( V_223 ) )
return - V_150 ;
V_63 = V_1 -> V_63 [ V_118 ] ;
V_138 = V_1 -> V_137 [ V_118 ] ;
if ( V_323 || ( V_1 -> V_137 [ 0 ] == V_138 ) ) {
if ( V_63 -> V_114 > V_299 )
return - V_58 ;
} else if ( V_63 -> V_114 > 0 )
return - V_58 ;
V_324 = ( V_63 == V_1 -> V_63 [ V_1 -> V_64 ] ) ;
if ( V_1 -> V_137 [ 0 ] != V_138 ) {
struct V_325 * V_326 = V_138 -> V_139 ;
if ( V_138 -> V_13 & V_327 ) {
F_72 ( V_1 , V_118 , 0 ) ;
F_166 ( V_138 ) ;
}
if ( V_326 )
F_149 ( V_326 ) ;
if ( V_323 ) {
for ( V_20 = 0 ; V_20 < V_312 ; V_20 ++ ) {
if ( V_1 -> V_137 [ V_20 ] == V_138 ) {
V_1 -> V_137 [ V_20 ] = NULL ;
break;
}
}
F_160 ( V_138 ) ;
}
} else {
F_156 ( V_138 , 0 ) ;
F_165 ( V_63 ) ;
}
-- V_1 -> V_52 ;
if ( V_323 && V_324 ) {
int V_328 = - 1 ;
for ( V_20 = 0 ; V_20 <= V_1 -> V_64 ; V_20 ++ ) {
if ( V_1 -> V_63 [ V_20 ] && V_1 -> V_63 [ V_20 ] -> V_65 )
V_328 = V_20 ;
}
V_1 -> V_64 = V_328 ;
}
return 0 ;
}
static int F_167 ( T_1 * V_1 , T_2 * V_2 , T_12 V_152 , void * V_221 ,
T_10 V_329 , T_12 V_330 , unsigned char * V_275 ,
int V_11 )
{
T_4 V_331 ;
int V_238 = V_282 ;
V_2 -> V_11 = V_228 ;
V_2 -> V_7 . V_229 = 0 ;
if ( V_221 != NULL ) {
V_2 -> V_7 . V_8 = 1 ;
V_2 -> V_7 . V_29 = 1 ;
} else {
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_7 . V_29 = 0 ;
}
V_2 -> V_7 . V_231 . V_33 = V_2 -> V_5 ;
memcpy ( V_2 -> V_7 . V_230 . V_332 , V_275 , 8 ) ;
V_2 -> V_177 . Type . Type = V_11 ;
if ( V_11 == V_281 ) {
switch ( V_152 ) {
case V_280 :
if ( V_330 != 0 ) {
V_2 -> V_177 . V_333 [ 1 ] = 0x01 ;
V_2 -> V_177 . V_333 [ 2 ] = V_330 ;
}
V_2 -> V_177 . V_334 = 6 ;
V_2 -> V_177 . Type . V_335 = V_336 ;
V_2 -> V_177 . Type . V_224 = V_234 ;
V_2 -> V_177 . V_337 = 0 ;
V_2 -> V_177 . V_333 [ 0 ] = V_280 ;
V_2 -> V_177 . V_333 [ 4 ] = V_329 & 0xFF ;
break;
case V_319 :
case V_338 :
V_2 -> V_177 . V_334 = 12 ;
V_2 -> V_177 . Type . V_335 = V_336 ;
V_2 -> V_177 . Type . V_224 = V_234 ;
V_2 -> V_177 . V_337 = 0 ;
V_2 -> V_177 . V_333 [ 0 ] = V_152 ;
V_2 -> V_177 . V_333 [ 6 ] = ( V_329 >> 24 ) & 0xFF ;
V_2 -> V_177 . V_333 [ 7 ] = ( V_329 >> 16 ) & 0xFF ;
V_2 -> V_177 . V_333 [ 8 ] = ( V_329 >> 8 ) & 0xFF ;
V_2 -> V_177 . V_333 [ 9 ] = V_329 & 0xFF ;
break;
case V_339 :
V_2 -> V_177 . V_334 = 10 ;
V_2 -> V_177 . Type . V_335 = V_336 ;
V_2 -> V_177 . Type . V_224 = V_234 ;
V_2 -> V_177 . V_337 = 0 ;
V_2 -> V_177 . V_333 [ 0 ] = V_152 ;
break;
case V_340 :
V_2 -> V_177 . V_334 = 16 ;
V_2 -> V_177 . Type . V_335 = V_336 ;
V_2 -> V_177 . Type . V_224 = V_234 ;
V_2 -> V_177 . V_337 = 0 ;
V_2 -> V_177 . V_333 [ 0 ] = V_152 ;
V_2 -> V_177 . V_333 [ 1 ] = 0x10 ;
V_2 -> V_177 . V_333 [ 10 ] = ( V_329 >> 24 ) & 0xFF ;
V_2 -> V_177 . V_333 [ 11 ] = ( V_329 >> 16 ) & 0xFF ;
V_2 -> V_177 . V_333 [ 12 ] = ( V_329 >> 8 ) & 0xFF ;
V_2 -> V_177 . V_333 [ 13 ] = V_329 & 0xFF ;
V_2 -> V_177 . V_337 = 0 ;
V_2 -> V_177 . V_333 [ 0 ] = V_152 ;
break;
case V_341 :
V_2 -> V_177 . V_334 = 12 ;
V_2 -> V_177 . Type . V_335 = V_336 ;
V_2 -> V_177 . Type . V_224 = V_226 ;
V_2 -> V_177 . V_337 = 0 ;
V_2 -> V_177 . V_333 [ 0 ] = V_342 ;
V_2 -> V_177 . V_333 [ 6 ] = V_343 ;
V_2 -> V_177 . V_333 [ 7 ] = ( V_329 >> 8 ) & 0xFF ;
V_2 -> V_177 . V_333 [ 8 ] = V_329 & 0xFF ;
break;
case V_344 :
V_2 -> V_177 . V_334 = 6 ;
V_2 -> V_177 . Type . V_335 = V_336 ;
V_2 -> V_177 . Type . V_224 = V_225 ;
V_2 -> V_177 . V_337 = 0 ;
break;
default:
F_154 ( & V_1 -> V_24 -> V_25 , L_40 , V_152 ) ;
return V_345 ;
}
} else if ( V_11 == V_346 ) {
switch ( V_152 ) {
case V_347 :
V_2 -> V_177 . V_334 = 12 ;
V_2 -> V_177 . Type . V_335 = V_336 ;
V_2 -> V_177 . Type . V_224 = V_226 ;
V_2 -> V_177 . V_337 = 0 ;
V_2 -> V_177 . V_333 [ 0 ] = V_152 ;
V_2 -> V_177 . V_333 [ 1 ] = 0 ;
memcpy ( & V_2 -> V_177 . V_333 [ 4 ] , V_221 , 8 ) ;
break;
case V_348 :
V_2 -> V_177 . V_334 = 16 ;
V_2 -> V_177 . Type . V_335 = V_336 ;
V_2 -> V_177 . Type . V_224 = V_225 ;
V_2 -> V_177 . V_337 = 0 ;
memset ( & V_2 -> V_177 . V_333 [ 0 ] , 0 , sizeof( V_2 -> V_177 . V_333 ) ) ;
V_2 -> V_177 . V_333 [ 0 ] = V_152 ;
V_2 -> V_177 . V_333 [ 1 ] = V_349 ;
break;
case V_350 :
V_2 -> V_177 . V_334 = 1 ;
V_2 -> V_177 . Type . V_335 = V_336 ;
V_2 -> V_177 . Type . V_224 = V_226 ;
V_2 -> V_177 . V_337 = 0 ;
V_2 -> V_177 . V_333 [ 0 ] = V_152 ;
break;
default:
F_154 ( & V_1 -> V_24 -> V_25 ,
L_41 , V_152 ) ;
return V_345 ;
}
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_42 , V_11 ) ;
return V_345 ;
}
if ( V_329 > 0 ) {
V_331 . V_36 = ( V_134 ) F_22 ( V_1 -> V_24 ,
V_221 , V_329 ,
V_232 ) ;
V_2 -> V_31 [ 0 ] . V_34 . V_33 = V_331 . V_32 . V_33 ;
V_2 -> V_31 [ 0 ] . V_34 . V_35 = V_331 . V_32 . V_35 ;
V_2 -> V_31 [ 0 ] . V_37 = V_329 ;
V_2 -> V_31 [ 0 ] . V_41 = 0 ;
}
return V_238 ;
}
static int F_168 ( T_1 * V_1 , unsigned char * V_275 ,
T_31 V_351 )
{
T_2 * V_2 ;
int V_352 ;
V_2 = F_73 ( V_1 ) ;
if ( ! V_2 )
return - V_227 ;
V_352 = F_167 ( V_1 , V_2 , V_348 , NULL , 0 , 0 ,
V_148 , V_346 ) ;
V_2 -> V_177 . V_333 [ 1 ] = V_351 ;
if ( V_352 != V_282 ) {
F_82 ( V_1 , V_2 ) ;
return V_352 ;
}
V_2 -> V_233 = NULL ;
F_10 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_169 ( T_1 * V_1 , T_2 * V_2 )
{
switch ( V_2 -> V_127 -> V_190 ) {
case V_353 :
return V_282 ;
case V_191 :
switch ( 0xf & V_2 -> V_127 -> V_354 [ 2 ] ) {
case 0 : return V_282 ;
case 1 : return V_282 ;
default:
if ( F_106 ( V_1 , V_2 ) )
return V_355 ;
F_154 ( & V_1 -> V_24 -> V_25 , L_43
L_44 ,
V_2 -> V_177 . V_333 [ 0 ] , V_2 -> V_127 -> V_354 [ 2 ] ) ;
}
break;
default:
F_154 ( & V_1 -> V_24 -> V_25 , L_45
L_46 ,
V_2 -> V_177 . V_333 [ 0 ] , V_2 -> V_127 -> V_190 ) ;
break;
}
return V_345 ;
}
static int F_170 ( T_1 * V_1 , T_2 * V_2 )
{
int V_352 = V_282 ;
if ( V_2 -> V_127 -> V_188 == V_356 )
return V_282 ;
switch ( V_2 -> V_127 -> V_188 ) {
case V_189 :
V_352 = F_169 ( V_1 , V_2 ) ;
break;
case V_357 :
case V_358 :
break;
case V_359 :
F_154 ( & V_1 -> V_24 -> V_25 , L_47
L_48 , V_2 -> V_177 . V_333 [ 0 ] ) ;
V_352 = V_345 ;
break;
case V_360 :
F_154 ( & V_1 -> V_24 -> V_25 , L_49
L_50 , V_2 -> V_177 . V_333 [ 0 ] ) ;
V_352 = V_345 ;
break;
case V_361 :
F_154 ( & V_1 -> V_24 -> V_25 , L_51
L_52 , V_2 -> V_177 . V_333 [ 0 ] ) ;
V_352 = V_345 ;
break;
case V_362 :
F_154 ( & V_1 -> V_24 -> V_25 , L_51
L_53 , V_2 -> V_177 . V_333 [ 0 ] ) ;
V_352 = V_345 ;
break;
case V_363 :
F_154 ( & V_1 -> V_24 -> V_25 , L_54
L_55 , V_2 -> V_177 . V_333 [ 0 ] ) ;
V_352 = V_345 ;
break;
case V_364 :
F_154 ( & V_1 -> V_24 -> V_25 , L_56
L_57 , V_2 -> V_177 . V_333 [ 0 ] ) ;
V_352 = V_345 ;
break;
case V_365 :
F_154 ( & V_1 -> V_24 -> V_25 , L_58 ,
V_2 -> V_177 . V_333 [ 0 ] ) ;
V_352 = V_355 ;
break;
case V_366 :
F_154 ( & V_1 -> V_24 -> V_25 , L_59 ) ;
V_352 = V_345 ;
break;
default:
F_154 ( & V_1 -> V_24 -> V_25 , L_60
L_61 , V_2 -> V_177 . V_333 [ 0 ] ,
V_2 -> V_127 -> V_188 ) ;
V_352 = V_345 ;
}
return V_352 ;
}
static int F_171 ( T_1 * V_1 , T_2 * V_2 ,
int V_367 )
{
F_124 ( V_222 ) ;
T_4 V_331 ;
int V_352 = V_282 ;
V_368:
V_2 -> V_233 = & V_222 ;
F_10 ( V_1 , V_2 ) ;
F_125 ( & V_222 ) ;
if ( V_2 -> V_127 -> V_188 == 0 || ! V_367 )
goto V_369;
V_352 = F_170 ( V_1 , V_2 ) ;
if ( V_352 == V_355 &&
V_2 -> V_370 < V_371 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_62 ,
V_2 -> V_177 . V_333 [ 0 ] ) ;
V_2 -> V_370 ++ ;
memset ( V_2 -> V_127 , 0 , sizeof( V_129 ) ) ;
V_352 = V_282 ;
F_172 ( & V_222 ) ;
goto V_368;
}
V_369:
V_331 . V_32 . V_33 = V_2 -> V_31 [ 0 ] . V_34 . V_33 ;
V_331 . V_32 . V_35 = V_2 -> V_31 [ 0 ] . V_34 . V_35 ;
F_20 ( V_1 -> V_24 , ( T_13 ) V_331 . V_36 ,
V_2 -> V_31 [ 0 ] . V_37 , V_232 ) ;
return V_352 ;
}
static int F_137 ( T_1 * V_1 , T_12 V_152 , void * V_221 , T_10 V_329 ,
T_12 V_330 , unsigned char V_275 [] ,
int V_11 )
{
T_2 * V_2 ;
int V_352 ;
V_2 = F_77 ( V_1 ) ;
if ( ! V_2 )
return - V_227 ;
V_352 = F_167 ( V_1 , V_2 , V_152 , V_221 , V_329 , V_330 ,
V_275 , V_11 ) ;
if ( V_352 == V_282 )
V_352 = F_171 ( V_1 , V_2 , 1 ) ;
F_82 ( V_1 , V_2 ) ;
return V_352 ;
}
static void F_153 ( T_1 * V_1 , int V_277 ,
T_6 V_301 ,
unsigned int V_297 ,
T_29 * V_300 ,
T_7 * V_63 )
{
int V_316 ;
unsigned long V_372 ;
unsigned char V_275 [ 8 ] ;
memset ( V_300 , 0 , sizeof( T_29 ) ) ;
F_135 ( V_1 , V_275 , V_277 ) ;
V_316 = F_137 ( V_1 , V_280 , V_300 ,
sizeof( * V_300 ) , 0xC1 , V_275 , V_281 ) ;
if ( V_316 == V_282 ) {
if ( V_300 -> V_283 [ 8 ] == 0xFF ) {
F_154 ( & V_1 -> V_24 -> V_25 ,
L_63
L_64 ) ;
V_63 -> V_65 = 255 ;
V_63 -> V_187 = 32 ;
V_63 -> V_186 = V_301 + 1 ;
V_63 -> V_68 = V_69 ;
} else {
V_63 -> V_65 = V_300 -> V_283 [ 6 ] ;
V_63 -> V_187 = V_300 -> V_283 [ 7 ] ;
V_63 -> V_186 = ( V_300 -> V_283 [ 4 ] & 0xff ) << 8 ;
V_63 -> V_186 += V_300 -> V_283 [ 5 ] ;
V_63 -> V_68 = V_300 -> V_283 [ 8 ] ;
}
V_63 -> V_297 = V_297 ;
V_63 -> V_66 = V_301 + 1 ;
V_372 = V_63 -> V_65 * V_63 -> V_187 ;
if ( V_372 > 1 ) {
T_6 V_373 = V_301 + 1 ;
unsigned long V_374 = F_30 ( V_373 , V_372 ) ;
if ( V_374 )
V_373 ++ ;
V_63 -> V_186 = V_373 ;
}
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_65 ) ;
}
}
static void
F_152 ( T_1 * V_1 , int V_277 , T_6 * V_301 ,
unsigned int * V_297 )
{
T_32 * V_76 ;
int V_316 ;
unsigned char V_275 [ 8 ] ;
V_76 = F_127 ( sizeof( T_32 ) , V_23 ) ;
if ( ! V_76 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
return;
}
F_135 ( V_1 , V_275 , V_277 ) ;
V_316 = F_137 ( V_1 , V_339 , V_76 ,
sizeof( T_32 ) , 0 , V_275 , V_281 ) ;
if ( V_316 == V_282 ) {
* V_301 = F_164 ( * ( V_320 * ) V_76 -> V_301 ) ;
* V_297 = F_164 ( * ( V_320 * ) V_76 -> V_297 ) ;
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_66 ) ;
* V_301 = 0 ;
* V_297 = V_375 ;
}
F_15 ( V_76 ) ;
}
static void F_151 ( T_1 * V_1 , int V_277 ,
T_6 * V_301 , unsigned int * V_297 )
{
T_33 * V_76 ;
int V_316 ;
unsigned char V_275 [ 8 ] ;
V_76 = F_127 ( sizeof( T_33 ) , V_23 ) ;
if ( ! V_76 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
return;
}
F_135 ( V_1 , V_275 , V_277 ) ;
V_316 = F_137 ( V_1 , V_340 ,
V_76 , sizeof( T_33 ) ,
0 , V_275 , V_281 ) ;
if ( V_316 == V_282 ) {
* V_301 = F_173 ( * ( V_376 * ) V_76 -> V_301 ) ;
* V_297 = F_164 ( * ( V_320 * ) V_76 -> V_297 ) ;
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_66 ) ;
* V_301 = 0 ;
* V_297 = V_375 ;
}
F_174 ( & V_1 -> V_24 -> V_25 , L_67 ,
( unsigned long long ) * V_301 + 1 , * V_297 ) ;
F_15 ( V_76 ) ;
}
static int F_175 ( struct V_137 * V_138 )
{
T_1 * V_1 = F_84 ( V_138 ) ;
T_7 * V_63 = F_85 ( V_138 ) ;
int V_277 ;
int V_377 = 0 ;
unsigned int V_297 ;
T_6 V_301 ;
T_29 * V_300 = NULL ;
for ( V_277 = 0 ; V_277 <= V_1 -> V_64 ; V_277 ++ ) {
if ( ! V_1 -> V_63 [ V_277 ] )
continue;
if ( memcmp ( V_1 -> V_63 [ V_277 ] -> V_112 , V_63 -> V_112 ,
sizeof( V_63 -> V_112 ) ) == 0 ) {
V_377 = 1 ;
break;
}
}
if ( ! V_377 )
return 1 ;
V_300 = F_17 ( sizeof( T_29 ) , V_23 ) ;
if ( V_300 == NULL ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
return 1 ;
}
if ( V_1 -> V_304 == V_308 ) {
F_152 ( V_1 , V_277 ,
& V_301 , & V_297 ) ;
} else {
F_151 ( V_1 , V_277 ,
& V_301 , & V_297 ) ;
}
F_153 ( V_1 , V_277 , V_301 , V_297 ,
V_300 , V_63 ) ;
F_146 ( V_63 -> V_139 , V_63 -> V_297 ) ;
F_156 ( V_138 , V_63 -> V_66 ) ;
F_15 ( V_300 ) ;
return 0 ;
}
static void T_34 * F_176 ( T_35 V_378 , T_35 V_329 )
{
T_35 V_379 = ( ( T_35 ) V_378 ) & V_380 ;
T_35 V_381 = ( ( T_35 ) V_378 ) - V_379 ;
void T_34 * V_382 = F_177 ( V_379 , V_381 + V_329 ) ;
return V_382 ? ( V_382 + V_381 ) : NULL ;
}
static void F_12 ( T_1 * V_1 )
{
T_2 * V_2 ;
while ( ! F_8 ( & V_1 -> V_15 ) ) {
V_2 = F_178 ( V_1 -> V_15 . V_383 , T_2 , V_10 ) ;
if ( ( V_1 -> V_384 . V_385 ( V_1 ) ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_68 ) ;
break;
}
F_6 ( V_2 ) ;
V_1 -> V_16 -- ;
V_1 -> V_384 . V_386 ( V_1 , V_2 ) ;
F_4 ( & V_1 -> V_387 , V_2 ) ;
}
}
static inline void F_179 ( T_1 * V_1 , T_2 * V_2 )
{
memset ( V_2 -> V_127 , 0 , sizeof( V_129 ) ) ;
F_4 ( & V_1 -> V_15 , V_2 ) ;
V_1 -> V_16 ++ ;
if ( V_1 -> V_16 > V_1 -> V_17 )
V_1 -> V_17 = V_1 -> V_16 ;
F_12 ( V_1 ) ;
}
static inline unsigned int F_180 ( unsigned int V_388 ,
unsigned int V_389 , unsigned int V_390 ,
unsigned int V_391 )
{
return ( V_388 & 0xff ) |
( ( V_389 & 0xff ) << 8 ) |
( ( V_390 & 0xff ) << 16 ) |
( ( V_391 & 0xff ) << 24 ) ;
}
static inline int F_181 ( T_1 * V_1 ,
T_2 * V_152 , int * V_392 )
{
unsigned char V_393 ;
unsigned char V_394 , V_389 , V_390 , V_391 ;
int V_395 ;
* V_392 = 0 ;
V_394 = V_152 -> V_127 -> V_190 ;
V_391 = V_396 ;
V_389 = V_152 -> V_127 -> V_188 ;
if ( V_152 -> V_263 -> V_11 == V_270 )
V_390 = V_397 ;
else
V_390 = V_398 ;
V_395 = F_180 ( V_394 , V_389 ,
V_390 , V_391 ) ;
if ( V_152 -> V_127 -> V_190 != V_191 ) {
if ( V_152 -> V_263 -> V_11 != V_270 )
F_154 ( & V_1 -> V_24 -> V_25 , L_69
L_70 ,
V_152 , V_152 -> V_127 -> V_190 ) ;
return V_395 ;
}
V_393 = 0xf & V_152 -> V_127 -> V_354 [ 2 ] ;
if ( ( ( V_393 == 0x0 ) || ( V_393 == 0x1 ) ) &&
( V_152 -> V_263 -> V_11 != V_270 ) )
V_395 = 0 ;
if ( F_106 ( V_1 , V_152 ) ) {
* V_392 = ! ( V_152 -> V_263 -> V_11 == V_270 ) ;
return 0 ;
}
if ( V_152 -> V_263 -> V_11 != V_270 ) {
if ( V_395 != 0 )
F_154 ( & V_1 -> V_24 -> V_25 , L_71
L_72 , V_152 , V_393 ) ;
return V_395 ;
}
if ( V_152 -> V_263 -> V_399 ) {
if ( V_152 -> V_263 -> V_400 > V_152 -> V_127 -> V_401 )
V_152 -> V_263 -> V_400 = V_152 -> V_127 -> V_401 ;
memcpy ( V_152 -> V_263 -> V_399 , V_152 -> V_127 -> V_354 ,
V_152 -> V_263 -> V_400 ) ;
} else
V_152 -> V_263 -> V_400 = 0 ;
return V_395 ;
}
static inline void F_182 ( T_1 * V_1 , T_2 * V_152 ,
int V_402 )
{
int V_392 = 0 ;
struct V_262 * V_263 = V_152 -> V_263 ;
V_263 -> V_273 = 0 ;
if ( V_402 )
V_263 -> V_273 = F_180 ( 0 , 0 , 0 , V_403 ) ;
if ( V_152 -> V_127 -> V_188 == 0 )
goto V_404;
switch ( V_152 -> V_127 -> V_188 ) {
case V_189 :
V_263 -> V_273 = F_181 ( V_1 , V_152 , & V_392 ) ;
break;
case V_357 :
if ( V_152 -> V_263 -> V_11 == V_405 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_73
L_74
L_75 , V_152 ) ;
V_152 -> V_263 -> V_271 = V_152 -> V_127 -> V_272 ;
}
break;
case V_358 :
if ( V_152 -> V_263 -> V_11 == V_405 )
F_154 ( & V_1 -> V_24 -> V_25 , L_76
L_77
L_75 , V_152 ) ;
break;
case V_359 :
F_154 ( & V_1 -> V_24 -> V_25 , L_78
L_48 , V_152 ) ;
V_263 -> V_273 = F_180 ( V_353 ,
V_152 -> V_127 -> V_188 , V_396 ,
( V_152 -> V_263 -> V_11 == V_270 ) ?
V_397 : V_406 ) ;
break;
case V_360 :
F_154 ( & V_1 -> V_24 -> V_25 , L_79
L_50 , V_152 ) ;
V_263 -> V_273 = F_180 ( V_353 ,
V_152 -> V_127 -> V_188 , V_396 ,
( V_152 -> V_263 -> V_11 == V_270 ) ?
V_397 : V_406 ) ;
break;
case V_361 :
F_154 ( & V_1 -> V_24 -> V_25 , L_80
L_52 , V_152 ) ;
V_263 -> V_273 = F_180 ( V_353 ,
V_152 -> V_127 -> V_188 , V_396 ,
( V_152 -> V_263 -> V_11 == V_270 ) ?
V_397 : V_406 ) ;
break;
case V_362 :
F_154 ( & V_1 -> V_24 -> V_25 , L_80
L_53 , V_152 ) ;
V_263 -> V_273 = F_180 ( V_353 ,
V_152 -> V_127 -> V_188 , V_396 ,
( V_152 -> V_263 -> V_11 == V_270 ) ?
V_397 : V_406 ) ;
break;
case V_363 :
F_154 ( & V_1 -> V_24 -> V_25 , L_81
L_55 , V_152 ) ;
V_263 -> V_273 = F_180 ( V_353 ,
V_152 -> V_127 -> V_188 , V_396 ,
( V_152 -> V_263 -> V_11 == V_270 ) ?
V_397 : V_407 ) ;
break;
case V_364 :
F_154 ( & V_1 -> V_24 -> V_25 , L_82
L_57 , V_152 ) ;
V_263 -> V_273 = F_180 ( V_353 ,
V_152 -> V_127 -> V_188 , V_396 ,
( V_152 -> V_263 -> V_11 == V_270 ) ?
V_397 : V_406 ) ;
break;
case V_365 :
F_154 ( & V_1 -> V_24 -> V_25 , L_83
L_84 , V_1 -> V_62 , V_152 ) ;
if ( V_152 -> V_370 < V_371 ) {
V_392 = 1 ;
F_154 ( & V_1 -> V_24 -> V_25 , L_85 , V_152 ) ;
V_152 -> V_370 ++ ;
} else
F_154 ( & V_1 -> V_24 -> V_25 ,
L_86 , V_152 ) ;
V_263 -> V_273 = F_180 ( V_353 ,
V_152 -> V_127 -> V_188 , V_396 ,
( V_152 -> V_263 -> V_11 == V_270 ) ?
V_397 : V_407 ) ;
break;
case V_408 :
F_154 ( & V_1 -> V_24 -> V_25 , L_87 , V_152 ) ;
V_263 -> V_273 = F_180 ( V_353 ,
V_152 -> V_127 -> V_188 , V_396 ,
( V_152 -> V_263 -> V_11 == V_270 ) ?
V_397 : V_406 ) ;
break;
case V_366 :
F_154 ( & V_1 -> V_24 -> V_25 , L_88 , V_152 ) ;
V_263 -> V_273 = F_180 ( V_353 ,
V_152 -> V_127 -> V_188 , V_396 ,
V_152 -> V_263 -> V_11 == V_270 ?
V_397 : V_406 ) ;
break;
default:
F_154 ( & V_1 -> V_24 -> V_25 , L_89
L_61 , V_152 ,
V_152 -> V_127 -> V_188 ) ;
V_263 -> V_273 = F_180 ( V_353 ,
V_152 -> V_127 -> V_188 , V_396 ,
( V_152 -> V_263 -> V_11 == V_270 ) ?
V_397 : V_406 ) ;
}
V_404:
if ( V_392 ) {
F_179 ( V_1 , V_152 ) ;
return;
}
V_152 -> V_263 -> V_264 = V_152 ;
F_183 ( V_152 -> V_263 ) ;
}
static inline T_11 F_184 ( T_11 V_409 )
{
#define F_185 0x10
return V_409 & F_185 ;
}
static inline T_11 F_186 ( T_11 V_409 )
{
#define F_187 5
return V_409 >> F_187 ;
}
static inline T_11 F_83 ( T_1 * V_1 , T_11 V_409 )
{
#define F_188 ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define F_189 0x03
if ( F_3 ( V_1 -> V_3 & V_4 ) )
return V_409 & ~ F_188 ;
return V_409 & ~ F_189 ;
}
static inline void F_190 ( T_11 * V_409 )
{
* V_409 |= F_185 ;
}
static inline void F_191 ( T_11 * V_409 , T_11 V_410 )
{
* V_409 |= ( V_410 << F_187 ) ;
}
static void V_285 ( struct V_325 * V_326 )
{
T_1 * V_1 = V_326 -> V_140 ;
T_2 * V_2 ;
T_6 V_411 ;
int V_412 ;
struct V_262 * V_413 ;
T_4 V_28 ;
struct V_414 * V_415 ;
T_3 * V_266 ;
T_7 * V_63 ;
int V_20 , V_416 ;
int V_268 = 0 ;
int V_417 = 0 ;
V_139:
V_413 = F_192 ( V_326 ) ;
if ( ! V_413 )
goto V_418;
F_193 ( V_413 -> V_419 > V_1 -> V_295 ) ;
V_2 = F_73 ( V_1 ) ;
if ( ! V_2 )
goto V_420;
F_194 ( V_413 ) ;
V_415 = V_1 -> V_421 [ V_2 -> V_132 ] ;
F_195 ( V_326 -> V_422 ) ;
V_2 -> V_11 = V_423 ;
V_2 -> V_263 = V_413 ;
V_63 = V_413 -> V_424 -> V_75 ;
V_2 -> V_7 . V_229 = 0 ;
F_191 ( & V_2 -> V_7 . V_231 . V_33 , V_2 -> V_132 ) ;
F_190 ( & V_2 -> V_7 . V_231 . V_33 ) ;
memcpy ( & V_2 -> V_7 . V_230 , V_63 -> V_112 , sizeof( V_63 -> V_112 ) ) ;
V_2 -> V_177 . V_334 = 10 ;
V_2 -> V_177 . Type . Type = V_281 ;
V_2 -> V_177 . Type . V_335 = V_336 ;
V_2 -> V_177 . Type . V_224 =
( F_196 ( V_413 ) == V_425 ) ? V_234 : V_226 ;
V_2 -> V_177 . V_337 = 0 ;
V_2 -> V_177 . V_333 [ 0 ] =
( F_196 ( V_413 ) == V_425 ) ? V_1 -> V_304 : V_1 -> V_306 ;
V_411 = F_197 ( V_413 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_90 ,
( int ) F_197 ( V_413 ) , ( int ) F_198 ( V_413 ) ) ;
F_199 ( V_415 , V_1 -> V_295 ) ;
V_412 = F_200 ( V_326 , V_413 , V_415 ) ;
if ( V_2 -> V_177 . Type . V_224 == V_234 )
V_416 = V_269 ;
else
V_416 = V_38 ;
V_266 = V_2 -> V_31 ;
V_268 = 0 ;
V_417 = 0 ;
for ( V_20 = 0 ; V_20 < V_412 ; V_20 ++ ) {
if ( ( ( V_268 + 1 ) == ( V_1 -> V_30 ) ) &&
! V_417 && ( ( V_412 - V_20 ) > 1 ) ) {
V_266 = V_1 -> V_18 [ V_2 -> V_132 ] ;
V_268 = 0 ;
V_417 = 1 ;
}
V_266 [ V_268 ] . V_37 = V_415 [ V_20 ] . V_77 ;
V_28 . V_36 = ( V_134 ) F_201 ( V_1 -> V_24 , F_202 ( & V_415 [ V_20 ] ) ,
V_415 [ V_20 ] . V_426 ,
V_415 [ V_20 ] . V_77 , V_416 ) ;
V_266 [ V_268 ] . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_266 [ V_268 ] . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_266 [ V_268 ] . V_41 = 0 ;
++ V_268 ;
}
if ( V_417 )
F_21 ( V_1 , V_2 , V_1 -> V_18 [ V_2 -> V_132 ] ,
( V_412 - ( V_1 -> V_30 - 1 ) ) *
sizeof( T_3 ) ) ;
if ( V_412 > V_1 -> V_55 )
V_1 -> V_55 = V_412 ;
F_87 ( & V_1 -> V_24 -> V_25 , L_91
L_92 ,
F_198 ( V_413 ) , V_412 , V_417 ) ;
V_2 -> V_7 . V_29 = V_412 + V_417 ;
if ( V_412 <= V_1 -> V_30 )
V_2 -> V_7 . V_8 = V_2 -> V_7 . V_29 ;
else
V_2 -> V_7 . V_8 = V_1 -> V_30 ;
F_2 ( V_1 , V_2 ) ;
if ( F_3 ( V_413 -> V_11 == V_405 ) ) {
if( V_1 -> V_304 == V_308 ) {
V_2 -> V_177 . V_333 [ 1 ] = 0 ;
V_2 -> V_177 . V_333 [ 2 ] = ( V_411 >> 24 ) & 0xff ;
V_2 -> V_177 . V_333 [ 3 ] = ( V_411 >> 16 ) & 0xff ;
V_2 -> V_177 . V_333 [ 4 ] = ( V_411 >> 8 ) & 0xff ;
V_2 -> V_177 . V_333 [ 5 ] = V_411 & 0xff ;
V_2 -> V_177 . V_333 [ 6 ] = 0 ;
V_2 -> V_177 . V_333 [ 7 ] = ( F_198 ( V_413 ) >> 8 ) & 0xff ;
V_2 -> V_177 . V_333 [ 8 ] = F_198 ( V_413 ) & 0xff ;
V_2 -> V_177 . V_333 [ 9 ] = V_2 -> V_177 . V_333 [ 11 ] = V_2 -> V_177 . V_333 [ 12 ] = 0 ;
} else {
T_11 V_427 = F_203 ( V_411 ) ;
V_2 -> V_177 . V_334 = 16 ;
V_2 -> V_177 . V_333 [ 1 ] = 0 ;
V_2 -> V_177 . V_333 [ 2 ] = ( V_427 >> 24 ) & 0xff ;
V_2 -> V_177 . V_333 [ 3 ] = ( V_427 >> 16 ) & 0xff ;
V_2 -> V_177 . V_333 [ 4 ] = ( V_427 >> 8 ) & 0xff ;
V_2 -> V_177 . V_333 [ 5 ] = V_427 & 0xff ;
V_2 -> V_177 . V_333 [ 6 ] = ( V_411 >> 24 ) & 0xff ;
V_2 -> V_177 . V_333 [ 7 ] = ( V_411 >> 16 ) & 0xff ;
V_2 -> V_177 . V_333 [ 8 ] = ( V_411 >> 8 ) & 0xff ;
V_2 -> V_177 . V_333 [ 9 ] = V_411 & 0xff ;
V_2 -> V_177 . V_333 [ 10 ] = ( F_198 ( V_413 ) >> 24 ) & 0xff ;
V_2 -> V_177 . V_333 [ 11 ] = ( F_198 ( V_413 ) >> 16 ) & 0xff ;
V_2 -> V_177 . V_333 [ 12 ] = ( F_198 ( V_413 ) >> 8 ) & 0xff ;
V_2 -> V_177 . V_333 [ 13 ] = F_198 ( V_413 ) & 0xff ;
V_2 -> V_177 . V_333 [ 14 ] = V_2 -> V_177 . V_333 [ 15 ] = 0 ;
}
} else if ( V_413 -> V_11 == V_270 ) {
V_2 -> V_177 . V_334 = V_413 -> V_428 ;
memcpy ( V_2 -> V_177 . V_333 , V_413 -> V_152 , V_429 ) ;
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_93 ,
V_413 -> V_11 ) ;
F_204 () ;
}
F_205 ( V_326 -> V_422 ) ;
F_4 ( & V_1 -> V_15 , V_2 ) ;
V_1 -> V_16 ++ ;
if ( V_1 -> V_16 > V_1 -> V_17 )
V_1 -> V_17 = V_1 -> V_16 ;
goto V_139;
V_420:
F_206 ( V_326 ) ;
V_418:
F_12 ( V_1 ) ;
}
static inline unsigned long F_207 ( T_1 * V_1 )
{
return V_1 -> V_384 . V_430 ( V_1 ) ;
}
static inline int F_208 ( T_1 * V_1 )
{
return V_1 -> V_384 . V_431 ( V_1 ) ;
}
static inline long F_209 ( T_1 * V_1 )
{
return ( ( V_1 -> V_384 . V_431 ( V_1 ) == 0 ) ||
( V_1 -> V_432 == 0 ) ) ;
}
static inline int F_210 ( T_1 * V_1 , T_11 V_433 ,
T_11 V_434 )
{
if ( F_211 ( V_433 >= V_1 -> V_19 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_94 , V_434 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_212 ( T_1 * V_1 , T_2 * V_2 ,
T_11 V_434 )
{
F_6 ( V_2 ) ;
if ( F_3 ( V_2 -> V_11 == V_423 ) )
F_182 ( V_1 , V_2 , 0 ) ;
else if ( V_2 -> V_11 == V_228 )
F_213 ( V_2 -> V_233 ) ;
#ifdef F_25
else if ( V_2 -> V_11 == V_435 )
F_214 ( V_2 , 0 , V_434 ) ;
#endif
}
static inline T_11 F_215 ( T_1 * V_1 )
{
T_11 V_436 ;
if ( F_211 ( ! ( V_1 -> V_3 & V_4 ) ) )
return V_1 -> V_384 . V_430 ( V_1 ) ;
if ( ( * ( V_1 -> V_437 ) & 1 ) == ( V_1 -> V_438 ) ) {
V_436 = * ( V_1 -> V_437 ) ;
( V_1 -> V_437 ) ++ ;
V_1 -> V_53 -- ;
} else {
V_436 = V_439 ;
}
if ( V_1 -> V_437 == ( V_1 -> V_440 + V_1 -> V_441 ) ) {
V_1 -> V_437 = V_1 -> V_440 ;
V_1 -> V_438 ^= 1 ;
}
return V_436 ;
}
static inline T_11 F_216 ( T_1 * V_1 , T_11 V_434 )
{
T_11 V_433 ;
T_2 * V_2 ;
V_433 = F_186 ( V_434 ) ;
if ( F_210 ( V_1 , V_433 , V_434 ) )
return F_215 ( V_1 ) ;
V_2 = V_1 -> V_125 + V_433 ;
F_212 ( V_1 , V_2 , V_434 ) ;
return F_215 ( V_1 ) ;
}
static inline T_11 F_217 ( T_1 * V_1 , T_11 V_434 )
{
T_2 * V_2 = NULL ;
V_133 V_442 , V_443 ;
V_443 = F_83 ( V_1 , V_434 ) ;
F_218 (c, &h->cmpQ, list) {
V_442 = F_83 ( V_1 , V_2 -> V_5 ) ;
if ( V_442 == V_443 ) {
F_212 ( V_1 , V_2 , V_434 ) ;
return F_215 ( V_1 ) ;
}
}
F_210 ( V_1 , V_1 -> V_19 + 1 , V_434 ) ;
return F_215 ( V_1 ) ;
}
static int F_219 ( T_1 * V_1 )
{
if ( F_3 ( ! V_444 ) )
return 0 ;
if ( F_3 ( V_1 -> V_432 ) )
return 0 ;
F_174 ( & V_1 -> V_24 -> V_25 , L_95
L_96 ) ;
return 1 ;
}
static T_36 F_220 ( int V_445 , void * V_446 )
{
T_1 * V_1 = V_446 ;
unsigned long V_13 ;
T_11 V_434 ;
if ( F_219 ( V_1 ) )
return V_447 ;
if ( F_209 ( V_1 ) )
return V_447 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
while ( F_208 ( V_1 ) ) {
V_434 = F_207 ( V_1 ) ;
while ( V_434 != V_439 )
V_434 = F_215 ( V_1 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_448 ;
}
static T_36 F_221 ( int V_445 , void * V_446 )
{
T_1 * V_1 = V_446 ;
unsigned long V_13 ;
T_11 V_434 ;
if ( F_219 ( V_1 ) )
return V_447 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_434 = F_207 ( V_1 ) ;
while ( V_434 != V_439 )
V_434 = F_215 ( V_1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_448 ;
}
static T_36 F_222 ( int V_445 , void * V_446 )
{
T_1 * V_1 = V_446 ;
unsigned long V_13 ;
T_11 V_434 ;
if ( F_209 ( V_1 ) )
return V_447 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
while ( F_208 ( V_1 ) ) {
V_434 = F_207 ( V_1 ) ;
while ( V_434 != V_439 ) {
if ( F_184 ( V_434 ) )
V_434 = F_216 ( V_1 , V_434 ) ;
else
V_434 = F_217 ( V_1 , V_434 ) ;
}
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_448 ;
}
static T_36 F_223 ( int V_445 , void * V_446 )
{
T_1 * V_1 = V_446 ;
unsigned long V_13 ;
T_11 V_434 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_434 = F_207 ( V_1 ) ;
while ( V_434 != V_439 ) {
if ( F_184 ( V_434 ) )
V_434 = F_216 ( V_1 , V_434 ) ;
else
V_434 = F_217 ( V_1 , V_434 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_448 ;
}
static int F_50 ( struct V_97 * V_1 )
{
struct V_97 * V_449 ;
int V_450 = 0 ;
int V_73 = 0 ;
if ( V_1 -> V_451 )
return 0 ;
if ( ! F_224 ( & V_1 -> V_452 ) )
return 0 ;
F_91 ( & V_453 ) ;
F_218 (test_h, &scan_q, scan_list) {
if ( V_449 == V_1 ) {
V_450 = 1 ;
break;
}
}
if ( ! V_450 && ! V_1 -> V_454 ) {
F_172 ( & V_1 -> V_100 ) ;
F_5 ( & V_1 -> V_455 , & V_456 ) ;
V_73 = 1 ;
}
F_92 ( & V_453 ) ;
F_92 ( & V_1 -> V_452 ) ;
return V_73 ;
}
static void F_225 ( struct V_97 * V_1 )
{
struct V_97 * V_449 , * V_457 ;
F_91 ( & V_453 ) ;
F_226 (test_h, tmp_h, &scan_q, scan_list) {
if ( V_449 == V_1 ) {
F_227 ( & V_1 -> V_455 ) ;
F_228 ( & V_1 -> V_100 ) ;
F_92 ( & V_453 ) ;
return;
}
}
if ( V_1 -> V_454 ) {
F_92 ( & V_453 ) ;
F_125 ( & V_1 -> V_100 ) ;
} else {
F_92 ( & V_453 ) ;
}
}
static int F_229 ( void * V_458 )
{
struct V_97 * V_1 ;
while ( 1 ) {
F_230 ( V_459 ) ;
F_231 () ;
if ( F_232 () )
break;
while ( 1 ) {
F_91 ( & V_453 ) ;
if ( F_8 ( & V_456 ) ) {
F_92 ( & V_453 ) ;
break;
}
V_1 = F_178 ( V_456 . V_383 ,
struct V_97 ,
V_455 ) ;
F_227 ( & V_1 -> V_455 ) ;
V_1 -> V_454 = 1 ;
F_92 ( & V_453 ) ;
F_128 ( V_1 , 0 , 0 ) ;
F_228 ( & V_1 -> V_100 ) ;
F_91 ( & V_453 ) ;
V_1 -> V_454 = 0 ;
F_92 ( & V_453 ) ;
}
}
return 0 ;
}
static int F_106 ( T_1 * V_1 , T_2 * V_2 )
{
if ( V_2 -> V_127 -> V_354 [ 2 ] != V_460 )
return 0 ;
switch ( V_2 -> V_127 -> V_354 [ 12 ] ) {
case V_461 :
F_154 ( & V_1 -> V_24 -> V_25 , L_97
L_98 ) ;
return 1 ;
break;
case V_462 :
F_154 ( & V_1 -> V_24 -> V_25 , L_99
L_100 ) ;
return 1 ;
break;
case V_463 :
F_154 ( & V_1 -> V_24 -> V_25 , L_101 ) ;
return 1 ;
break;
case V_464 :
F_154 ( & V_1 -> V_24 -> V_25 ,
L_102 ) ;
return 1 ;
break;
case V_465 :
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
char V_466 [ 17 ] ;
T_37 * V_467 = V_1 -> V_200 ;
F_87 ( & V_1 -> V_24 -> V_25 , L_105 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_106 ) ;
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ )
V_466 [ V_20 ] = F_115 ( & ( V_467 -> V_468 [ V_20 ] ) ) ;
V_466 [ 4 ] = '\0' ;
F_87 ( & V_1 -> V_24 -> V_25 , L_107 , V_466 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_108 ,
F_110 ( & ( V_467 -> V_469 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_109 ,
F_110 ( & ( V_467 -> V_470 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_110 ,
F_110 ( & ( V_467 -> V_471 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_111 ,
F_110 ( & ( V_467 -> V_201 . V_472 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_112 ,
F_110 ( & ( V_467 -> V_201 . V_202 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_113 ,
F_110 ( & ( V_467 -> V_201 . V_203 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_114 ,
F_110 ( & ( V_467 -> V_473 ) ) ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_115 ,
F_110 ( & ( V_467 -> V_213 ) ) ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
V_466 [ V_20 ] = F_115 ( & ( V_467 -> V_210 [ V_20 ] ) ) ;
V_466 [ 16 ] = '\0' ;
F_87 ( & V_1 -> V_24 -> V_25 , L_116 , V_466 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_117 ,
F_110 ( & ( V_467 -> V_212 ) ) ) ;
}
static int F_234 ( struct V_474 * V_24 , unsigned long V_475 )
{
int V_20 , V_426 , V_476 , V_477 ;
if ( V_475 == V_478 )
return 0 ;
V_426 = 0 ;
for ( V_20 = 0 ; V_20 < V_479 ; V_20 ++ ) {
V_477 = F_235 ( V_24 , V_20 ) & V_480 ;
if ( V_477 == V_481 )
V_426 += 4 ;
else {
V_476 = F_235 ( V_24 , V_20 ) &
V_482 ;
switch ( V_476 ) {
case V_483 :
case V_484 :
V_426 += 4 ;
break;
case V_485 :
V_426 += 8 ;
break;
default:
F_154 ( & V_24 -> V_25 ,
L_118 ) ;
return - 1 ;
break;
}
}
if ( V_426 == V_475 - V_478 )
return V_20 + 1 ;
}
return - 1 ;
}
static void F_236 ( int V_486 [] , int V_487 ,
int V_488 , int * V_489 )
{
int V_20 , V_22 , V_490 , V_329 ;
#define F_237 4
#define F_238 8
for ( V_20 = 0 ; V_20 <= V_488 ; V_20 ++ ) {
V_329 = V_20 + F_237 ;
V_490 = V_487 ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
if ( V_486 [ V_22 ] >= V_329 ) {
V_490 = V_22 ;
break;
}
}
V_489 [ V_20 ] = V_490 ;
}
}
static void F_239 ( T_1 * V_1 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_491 ; V_20 ++ ) {
if ( ! ( F_110 ( V_1 -> V_205 + V_206 ) & V_204 ) )
break;
F_240 ( 10000 , 20000 ) ;
}
}
static void F_241 ( T_1 * V_1 , T_11 V_492 )
{
V_133 V_493 ;
int V_494 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_244 + 4 } ;
unsigned long V_495 ;
F_242 ( 28 > V_244 + 4 ) ;
V_1 -> V_438 = 1 ;
memset ( V_1 -> V_440 , 0 , V_1 -> V_441 * sizeof( V_134 ) ) ;
V_1 -> V_437 = V_1 -> V_440 ;
V_493 = F_110 ( & ( V_1 -> V_200 -> V_496 ) ) ;
F_236 ( V_494 , F_44 ( V_494 ) , V_1 -> V_295 ,
V_1 -> V_6 ) ;
F_112 ( V_494 [ 0 ] , & V_1 -> V_497 -> V_498 ) ;
F_112 ( V_494 [ 1 ] , & V_1 -> V_497 -> V_499 ) ;
F_112 ( V_494 [ 2 ] , & V_1 -> V_497 -> V_500 ) ;
F_112 ( V_494 [ 3 ] , & V_1 -> V_497 -> V_501 ) ;
F_112 ( V_494 [ 4 ] , & V_1 -> V_497 -> V_502 ) ;
F_112 ( V_494 [ 5 ] , & V_1 -> V_497 -> V_503 ) ;
F_112 ( V_494 [ 6 ] , & V_1 -> V_497 -> V_504 ) ;
F_112 ( V_494 [ 7 ] , & V_1 -> V_497 -> V_505 ) ;
F_112 ( V_1 -> V_441 , & V_1 -> V_497 -> V_506 ) ;
F_112 ( 1 , & V_1 -> V_497 -> V_507 ) ;
F_112 ( 0 , & V_1 -> V_497 -> V_508 ) ;
F_112 ( 0 , & V_1 -> V_497 -> V_509 ) ;
F_112 ( V_1 -> V_510 , & V_1 -> V_497 -> V_511 ) ;
F_112 ( 0 , & V_1 -> V_497 -> V_512 ) ;
F_112 ( V_4 | V_492 ,
& ( V_1 -> V_200 -> V_201 . V_472 ) ) ;
F_112 ( V_204 , V_1 -> V_205 + V_206 ) ;
F_239 ( V_1 ) ;
V_495 = F_110 ( & ( V_1 -> V_200 -> V_471 ) ) ;
if ( ! ( V_495 & V_4 ) )
F_154 ( & V_1 -> V_24 -> V_25 , L_119
L_120 ) ;
}
static void F_243 ( T_1 * V_1 )
{
V_133 V_513 ;
if ( V_514 )
return;
F_87 ( & V_1 -> V_24 -> V_25 , L_121 ) ;
V_513 = F_110 ( & ( V_1 -> V_200 -> V_470 ) ) ;
if ( ! ( V_513 & V_515 ) )
return;
F_87 ( & V_1 -> V_24 -> V_25 , L_122 ) ;
if ( ( sizeof( T_2 ) % 32 ) != 0 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_123 ,
L_124 ,
( int ) sizeof( T_2 ) ,
L_125 ) ;
return;
}
V_1 -> V_440 = ( V_134 * ) F_244 (
V_1 -> V_24 , V_1 -> V_441 * sizeof( V_134 ) ,
& ( V_1 -> V_510 ) ) ;
V_1 -> V_6 = F_17 ( ( ( V_1 -> V_295 + 1 ) *
sizeof( V_133 ) ) , V_23 ) ;
if ( ( V_1 -> V_440 == NULL ) || ( V_1 -> V_6 == NULL ) )
goto V_516;
F_241 ( V_1 ,
V_513 & V_517 ) ;
V_1 -> V_384 = V_518 ;
V_1 -> V_3 = V_4 ;
return;
V_516:
F_15 ( V_1 -> V_6 ) ;
if ( V_1 -> V_440 )
F_79 ( V_1 -> V_24 ,
V_1 -> V_441 * sizeof( V_134 ) ,
V_1 -> V_440 ,
V_1 -> V_510 ) ;
return;
}
static void F_245 ( T_1 * V_1 )
{
#ifdef F_246
int V_79 ;
struct V_519 V_520 [ 4 ] = { { 0 , 0 } , { 0 , 1 } ,
{ 0 , 2 } , { 0 , 3 }
} ;
if ( ( V_1 -> V_48 == 0x40700E11 ) || ( V_1 -> V_48 == 0x40800E11 ) ||
( V_1 -> V_48 == 0x40820E11 ) || ( V_1 -> V_48 == 0x40830E11 ) )
goto V_521;
if ( F_247 ( V_1 -> V_24 , V_522 ) ) {
V_79 = F_248 ( V_1 -> V_24 , V_520 , 4 ) ;
if ( ! V_79 ) {
V_1 -> V_50 [ 0 ] = V_520 [ 0 ] . V_523 ;
V_1 -> V_50 [ 1 ] = V_520 [ 1 ] . V_523 ;
V_1 -> V_50 [ 2 ] = V_520 [ 2 ] . V_523 ;
V_1 -> V_50 [ 3 ] = V_520 [ 3 ] . V_523 ;
V_1 -> V_524 = 1 ;
return;
} else {
F_154 ( & V_1 -> V_24 -> V_25 ,
L_126 , V_79 ) ;
}
}
if ( F_247 ( V_1 -> V_24 , V_525 ) ) {
if ( ! F_249 ( V_1 -> V_24 ) )
V_1 -> V_526 = 1 ;
else
F_154 ( & V_1 -> V_24 -> V_25 , L_127 ) ;
}
V_521:
#endif
V_1 -> V_50 [ V_1 -> V_51 ] = V_1 -> V_24 -> V_445 ;
return;
}
static int F_250 ( struct V_474 * V_24 , T_11 * V_48 )
{
int V_20 ;
T_11 V_527 , V_528 ;
V_527 = V_24 -> V_529 ;
V_528 = V_24 -> V_530 ;
* V_48 = ( ( V_528 << 16 ) & 0xffff0000 ) |
V_527 ;
for ( V_20 = 0 ; V_20 < F_44 ( V_531 ) ; V_20 ++ ) {
if ( V_532 )
return - V_533 ;
if ( * V_48 == V_531 [ V_20 ] . V_48 )
return V_20 ;
}
F_154 ( & V_24 -> V_25 , L_128 ,
* V_48 ) ;
return - V_533 ;
}
static inline bool F_251 ( T_1 * V_1 )
{
T_38 V_534 ;
( void ) F_252 ( V_1 -> V_24 , V_535 , & V_534 ) ;
return ( ( V_534 & V_536 ) == 0 ) ;
}
static int F_253 ( struct V_474 * V_24 ,
unsigned long * V_537 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_479 ; V_20 ++ )
if ( F_235 ( V_24 , V_20 ) & V_538 ) {
* V_537 = F_254 ( V_24 , V_20 ) ;
F_87 ( & V_24 -> V_25 , L_129 ,
* V_537 ) ;
return 0 ;
}
F_154 ( & V_24 -> V_25 , L_130 ) ;
return - V_533 ;
}
static int F_255 ( struct V_474 * V_24 ,
void T_34 * V_205 , int V_539 )
#define F_256 1
#define F_257 0
{
int V_20 , V_540 ;
T_11 V_541 ;
if ( V_539 )
V_540 = V_542 ;
else
V_540 = V_543 ;
for ( V_20 = 0 ; V_20 < V_540 ; V_20 ++ ) {
V_541 = F_110 ( V_205 + V_544 ) ;
if ( V_539 ) {
if ( V_541 == V_545 )
return 0 ;
} else {
if ( V_541 != V_545 )
return 0 ;
}
F_258 ( V_546 ) ;
}
F_154 ( & V_24 -> V_25 , L_131 ) ;
return - V_533 ;
}
static int F_259 ( struct V_474 * V_24 , void T_34 * V_205 ,
T_11 * V_547 , T_39 * V_548 ,
T_39 * V_549 )
{
* V_547 = F_110 ( V_205 + V_550 ) ;
* V_549 = F_110 ( V_205 + V_551 ) ;
* V_547 &= ( T_11 ) 0x0000ffff ;
* V_548 = F_234 ( V_24 , * V_547 ) ;
if ( * V_548 == - 1 ) {
F_154 ( & V_24 -> V_25 , L_132
L_133 , * V_547 ) ;
return - V_533 ;
}
return 0 ;
}
static int F_260 ( T_1 * V_1 )
{
T_39 V_549 ;
T_11 V_547 ;
T_39 V_548 ;
T_11 V_493 ;
int V_278 ;
V_278 = F_259 ( V_1 -> V_24 , V_1 -> V_205 , & V_547 ,
& V_548 , & V_549 ) ;
if ( V_278 )
return V_278 ;
V_1 -> V_200 = F_176 ( F_254 ( V_1 -> V_24 ,
V_548 ) + V_549 , sizeof( * V_1 -> V_200 ) ) ;
if ( ! V_1 -> V_200 )
return - V_227 ;
V_278 = F_261 ( V_1 -> V_200 ) ;
if ( V_278 )
return V_278 ;
V_493 = F_110 ( & V_1 -> V_200 -> V_496 ) ;
V_1 -> V_497 = F_176 ( F_254 ( V_1 -> V_24 ,
V_548 ) + V_549 + V_493 ,
sizeof( * V_1 -> V_497 ) ) ;
if ( ! V_1 -> V_497 )
return - V_227 ;
return 0 ;
}
static void F_262 ( struct V_97 * V_1 )
{
V_1 -> V_441 = F_110 ( & ( V_1 -> V_200 -> V_552 ) ) ;
if ( V_444 && V_1 -> V_441 > 32 )
V_1 -> V_441 = 32 ;
if ( V_1 -> V_441 < 16 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_134
L_135
L_136 ,
V_1 -> V_441 ) ;
V_1 -> V_441 = 16 ;
}
}
static void F_263 ( T_1 * V_1 )
{
F_262 ( V_1 ) ;
V_1 -> V_19 = V_1 -> V_441 - 4 - V_553 ;
V_1 -> V_295 = F_110 ( & ( V_1 -> V_200 -> V_554 ) ) ;
if ( V_1 -> V_48 == 0x3225103C )
V_1 -> V_295 = V_244 ;
V_1 -> V_30 = 31 ;
if ( V_1 -> V_295 > 512 ) {
V_1 -> V_30 = 32 ;
V_1 -> V_21 = V_1 -> V_295 - V_1 -> V_30 + 1 ;
V_1 -> V_295 -- ;
} else {
V_1 -> V_295 = 31 ;
V_1 -> V_21 = 0 ;
}
}
static inline bool F_264 ( T_1 * V_1 )
{
if ( ! F_265 ( V_1 -> V_200 -> V_468 , L_137 , 4 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_138 ) ;
return false ;
}
return true ;
}
static inline void F_266 ( T_1 * V_1 )
{
#ifdef F_267
T_11 V_555 ;
V_555 = F_110 ( & ( V_1 -> V_200 -> V_556 ) ) ;
V_555 |= 0x100 ;
F_112 ( V_555 , & ( V_1 -> V_200 -> V_556 ) ) ;
#endif
}
static inline void F_268 ( T_1 * V_1 )
{
T_11 V_557 ;
V_133 V_558 ;
if ( V_1 -> V_48 != 0x3225103C )
return;
V_557 = F_110 ( V_1 -> V_205 + V_559 ) ;
V_557 |= 0x8000 ;
F_112 ( V_557 , V_1 -> V_205 + V_559 ) ;
F_269 ( V_1 -> V_24 , V_560 , & V_558 ) ;
V_558 |= 0x1 ;
F_270 ( V_1 -> V_24 , V_560 , V_558 ) ;
}
static int F_271 ( T_1 * V_1 )
{
int V_561 , V_79 ;
V_561 = F_250 ( V_1 -> V_24 , & V_1 -> V_48 ) ;
if ( V_561 < 0 )
return - V_533 ;
V_1 -> V_47 = V_531 [ V_561 ] . V_47 ;
V_1 -> V_384 = * ( V_531 [ V_561 ] . V_384 ) ;
if ( F_251 ( V_1 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_139 ) ;
return - V_533 ;
}
F_272 ( V_1 -> V_24 , V_562 |
V_563 | V_564 ) ;
V_79 = F_273 ( V_1 -> V_24 ) ;
if ( V_79 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_140 ) ;
return V_79 ;
}
V_79 = F_274 ( V_1 -> V_24 , L_141 ) ;
if ( V_79 ) {
F_154 ( & V_1 -> V_24 -> V_25 ,
L_142 ) ;
return V_79 ;
}
F_87 ( & V_1 -> V_24 -> V_25 , L_143 , V_1 -> V_24 -> V_445 ) ;
F_87 ( & V_1 -> V_24 -> V_25 , L_144 , V_1 -> V_48 ) ;
F_245 ( V_1 ) ;
V_79 = F_253 ( V_1 -> V_24 , & V_1 -> V_565 ) ;
if ( V_79 )
goto V_566;
V_1 -> V_205 = F_176 ( V_1 -> V_565 , 0x250 ) ;
if ( ! V_1 -> V_205 ) {
V_79 = - V_227 ;
goto V_566;
}
V_79 = F_255 ( V_1 -> V_24 , V_1 -> V_205 , F_256 ) ;
if ( V_79 )
goto V_566;
V_79 = F_260 ( V_1 ) ;
if ( V_79 )
goto V_566;
F_233 ( V_1 ) ;
F_263 ( V_1 ) ;
if ( ! F_264 ( V_1 ) ) {
V_79 = - V_533 ;
goto V_566;
}
F_266 ( V_1 ) ;
F_268 ( V_1 ) ;
V_79 = F_275 ( V_1 ) ;
if ( V_79 )
goto V_566;
F_243 ( V_1 ) ;
return 0 ;
V_566:
if ( V_1 -> V_497 )
F_276 ( V_1 -> V_497 ) ;
if ( V_1 -> V_200 )
F_276 ( V_1 -> V_200 ) ;
if ( V_1 -> V_205 )
F_276 ( V_1 -> V_205 ) ;
F_277 ( V_1 -> V_24 ) ;
return V_79 ;
}
static int F_278 ( struct V_474 * V_24 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_567 ; V_20 ++ ) {
if ( ! V_265 [ V_20 ] ) {
T_1 * V_1 ;
V_1 = F_127 ( sizeof( T_1 ) , V_23 ) ;
if ( ! V_1 )
goto V_568;
V_265 [ V_20 ] = V_1 ;
return V_20 ;
}
}
F_154 ( & V_24 -> V_25 , L_145
L_146 , V_567 ) ;
return - 1 ;
V_568:
F_154 ( & V_24 -> V_25 , L_147 ) ;
return - 1 ;
}
static void F_279 ( T_1 * V_1 )
{
int V_20 ;
V_265 [ V_1 -> V_62 ] = NULL ;
for ( V_20 = 0 ; V_20 < V_1 -> V_64 + 1 ; V_20 ++ )
if ( V_1 -> V_137 [ V_20 ] != NULL )
F_160 ( V_1 -> V_137 [ V_20 ] ) ;
F_15 ( V_1 ) ;
}
static int F_280 ( struct V_474 * V_24 , unsigned char V_569 ,
unsigned char type )
{
typedef struct {
T_40 V_570 ;
T_41 V_177 ;
T_42 V_571 ;
} T_43;
static const T_10 V_572 = sizeof( T_43 ) + sizeof( V_129 ) ;
T_43 * V_152 ;
T_13 V_573 ;
T_28 V_574 , V_409 ;
void T_34 * V_205 ;
int V_20 , V_79 ;
V_205 = F_281 ( F_254 ( V_24 , 0 ) , F_282 ( V_24 , 0 ) ) ;
if ( V_205 == NULL )
return - V_227 ;
V_79 = F_283 ( V_24 , F_284 ( 32 ) ) ;
if ( V_79 ) {
F_276 ( V_205 ) ;
return - V_227 ;
}
V_152 = F_244 ( V_24 , V_572 , & V_573 ) ;
if ( V_152 == NULL ) {
F_276 ( V_205 ) ;
return - V_227 ;
}
V_574 = V_573 ;
V_152 -> V_570 . V_229 = 0 ;
V_152 -> V_570 . V_8 = 0 ;
V_152 -> V_570 . V_29 = 0 ;
V_152 -> V_570 . V_231 . V_33 = V_574 ;
V_152 -> V_570 . V_231 . V_35 = 0 ;
memset ( & V_152 -> V_570 . V_230 . V_332 , 0 , 8 ) ;
V_152 -> V_177 . V_334 = 16 ;
V_152 -> V_177 . Type . Type = V_346 ;
V_152 -> V_177 . Type . V_335 = V_575 ;
V_152 -> V_177 . Type . V_224 = V_225 ;
V_152 -> V_177 . V_337 = 0 ;
V_152 -> V_177 . V_333 [ 0 ] = V_569 ;
V_152 -> V_177 . V_333 [ 1 ] = type ;
memset ( & V_152 -> V_177 . V_333 [ 2 ] , 0 , 14 ) ;
V_152 -> V_571 . V_34 . V_33 = V_574 + sizeof( T_43 ) ;
V_152 -> V_571 . V_34 . V_35 = 0 ;
V_152 -> V_571 . V_37 = sizeof( V_129 ) ;
F_112 ( V_574 , V_205 + V_576 ) ;
for ( V_20 = 0 ; V_20 < 10 ; V_20 ++ ) {
V_409 = F_110 ( V_205 + V_577 ) ;
if ( ( V_409 & ~ 3 ) == V_574 )
break;
F_258 ( V_578 ) ;
}
F_276 ( V_205 ) ;
if ( V_20 == 10 ) {
F_18 ( & V_24 -> V_25 ,
L_148 ,
V_569 , type ) ;
return - V_579 ;
}
F_79 ( V_24 , V_572 , V_152 , V_573 ) ;
if ( V_409 & 2 ) {
F_18 ( & V_24 -> V_25 , L_149 ,
V_569 , type ) ;
return - V_274 ;
}
F_174 ( & V_24 -> V_25 , L_150 ,
V_569 , type ) ;
return 0 ;
}
static int F_285 ( struct V_474 * V_24 ,
void * T_34 V_205 , T_11 V_580 )
{
T_38 V_581 ;
int V_56 ;
if ( V_580 ) {
F_174 ( & V_24 -> V_25 , L_151 ) ;
F_112 ( V_580 , V_205 + V_206 ) ;
} else {
V_56 = F_247 ( V_24 , V_582 ) ;
if ( V_56 == 0 ) {
F_18 ( & V_24 -> V_25 ,
L_152
L_153 ) ;
return - V_533 ;
}
F_174 ( & V_24 -> V_25 , L_154 ) ;
F_252 ( V_24 , V_56 + V_583 , & V_581 ) ;
V_581 &= ~ V_584 ;
V_581 |= V_585 ;
F_286 ( V_24 , V_56 + V_583 , V_581 ) ;
F_258 ( 500 ) ;
V_581 &= ~ V_584 ;
V_581 |= V_586 ;
F_286 ( V_24 , V_56 + V_583 , V_581 ) ;
F_258 ( 500 ) ;
}
return 0 ;
}
static void F_287 ( char * V_587 , int V_40 )
{
memset ( V_587 , 0 , V_40 ) ;
strncpy ( V_587 , L_155 V_588 , V_40 - 1 ) ;
}
static int F_261 ( T_37 T_34 * V_200 )
{
char * V_587 ;
int V_20 , V_329 = sizeof( V_200 -> V_587 ) ;
V_587 = F_17 ( V_329 , V_23 ) ;
if ( ! V_587 )
return - V_227 ;
F_287 ( V_587 , V_329 ) ;
for ( V_20 = 0 ; V_20 < V_329 ; V_20 ++ )
F_117 ( V_587 [ V_20 ] , & V_200 -> V_587 [ V_20 ] ) ;
F_15 ( V_587 ) ;
return 0 ;
}
static void F_288 ( T_37 T_34 * V_200 ,
unsigned char * V_589 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < sizeof( V_200 -> V_587 ) ; V_20 ++ )
V_589 [ V_20 ] = F_115 ( & V_200 -> V_587 [ V_20 ] ) ;
}
static int F_289 ( T_37 T_34 * V_200 )
{
char * V_589 , * V_590 ;
int V_278 , V_329 = sizeof( V_200 -> V_587 ) ;
V_590 = F_17 ( 2 * V_329 , V_23 ) ;
if ( ! V_590 )
return - V_227 ;
V_589 = V_590 + V_329 ;
F_287 ( V_590 , V_329 ) ;
F_288 ( V_200 , V_589 ) ;
V_278 = ! memcmp ( V_589 , V_590 , V_329 ) ;
F_15 ( V_590 ) ;
return V_278 ;
}
static int F_290 ( struct V_474 * V_24 )
{
T_39 V_549 ;
T_11 V_547 ;
T_39 V_548 ;
void T_34 * V_205 ;
unsigned long V_565 ;
T_11 V_591 ;
int V_278 ;
T_37 T_34 * V_200 ;
T_11 V_580 ;
T_11 V_48 ;
T_38 V_592 ;
F_250 ( V_24 , & V_48 ) ;
if ( ! F_46 ( V_48 ) ) {
F_154 ( & V_24 -> V_25 , L_156 ) ;
return - V_533 ;
}
if ( ! F_43 ( V_48 ) )
return - V_593 ;
F_252 ( V_24 , 4 , & V_592 ) ;
F_291 ( V_24 ) ;
F_292 ( V_24 ) ;
V_278 = F_253 ( V_24 , & V_565 ) ;
if ( V_278 )
return V_278 ;
V_205 = F_176 ( V_565 , 0x250 ) ;
if ( ! V_205 )
return - V_227 ;
V_278 = F_259 ( V_24 , V_205 , & V_547 ,
& V_548 , & V_549 ) ;
if ( V_278 )
goto V_594;
V_200 = F_176 ( F_254 ( V_24 ,
V_548 ) + V_549 , sizeof( * V_200 ) ) ;
if ( ! V_200 ) {
V_278 = - V_227 ;
goto V_594;
}
V_278 = F_261 ( V_200 ) ;
if ( V_278 )
goto V_594;
V_591 = F_110 ( & V_200 -> V_591 ) ;
V_580 = V_591 & V_595 ;
if ( V_580 ) {
V_580 = V_596 ;
} else {
V_580 = V_591 & V_597 ;
if ( V_580 ) {
F_154 ( & V_24 -> V_25 , L_157
L_158
L_159
L_160 ) ;
V_278 = - V_593 ;
goto V_598;
}
}
V_278 = F_285 ( V_24 , V_205 , V_580 ) ;
if ( V_278 )
goto V_598;
F_293 ( V_24 ) ;
V_278 = F_273 ( V_24 ) ;
if ( V_278 ) {
F_154 ( & V_24 -> V_25 , L_161 ) ;
goto V_598;
}
F_286 ( V_24 , 4 , V_592 ) ;
F_258 ( V_599 ) ;
F_174 ( & V_24 -> V_25 , L_162 ) ;
V_278 = F_255 ( V_24 , V_205 , F_257 ) ;
if ( V_278 ) {
F_154 ( & V_24 -> V_25 , L_163
L_164 ) ;
V_278 = - V_593 ;
goto V_598;
}
V_278 = F_255 ( V_24 , V_205 , F_256 ) ;
if ( V_278 ) {
F_154 ( & V_24 -> V_25 ,
L_165
L_166 ) ;
goto V_598;
}
V_278 = F_289 ( V_205 ) ;
if ( V_278 < 0 )
goto V_598;
if ( V_278 ) {
F_154 ( & V_24 -> V_25 , L_167
L_168 ) ;
V_278 = - V_593 ;
} else {
F_174 ( & V_24 -> V_25 , L_169 ) ;
}
V_598:
F_276 ( V_200 ) ;
V_594:
F_276 ( V_205 ) ;
return V_278 ;
}
static int F_294 ( struct V_474 * V_24 )
{
int V_278 , V_20 ;
if ( ! V_444 )
return 0 ;
V_278 = F_290 ( V_24 ) ;
if ( V_278 == - V_593 )
return V_278 ;
if ( V_278 )
return - V_533 ;
F_154 ( & V_24 -> V_25 , L_170 ) ;
for ( V_20 = 0 ; V_20 < V_600 ; V_20 ++ ) {
if ( F_295 ( V_24 ) == 0 )
break;
else
F_154 ( & V_24 -> V_25 , L_171 ,
( V_20 < V_600 - 1 ?
L_172 : L_173 ) ) ;
F_258 ( V_601 ) ;
}
return 0 ;
}
static int F_296 ( T_1 * V_1 )
{
V_1 -> V_124 = F_17 ( F_297 ( V_1 -> V_19 ) *
sizeof( unsigned long ) , V_23 ) ;
V_1 -> V_125 = F_244 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( T_2 ) ,
& ( V_1 -> V_126 ) ) ;
V_1 -> V_128 = F_244 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( V_129 ) ,
& ( V_1 -> V_130 ) ) ;
if ( ( V_1 -> V_124 == NULL )
|| ( V_1 -> V_125 == NULL )
|| ( V_1 -> V_128 == NULL ) ) {
F_18 ( & V_1 -> V_24 -> V_25 , L_174 ) ;
return - V_227 ;
}
return 0 ;
}
static int F_298 ( T_1 * V_1 )
{
int V_20 ;
V_1 -> V_421 = F_127 ( V_1 -> V_441 *
sizeof( struct V_414 * ) , V_23 ) ;
if ( ! V_1 -> V_421 )
return - V_227 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_19 ; V_20 ++ ) {
V_1 -> V_421 [ V_20 ] = F_17 ( sizeof( struct V_414 ) *
V_1 -> V_295 , V_23 ) ;
if ( V_1 -> V_421 [ V_20 ] == NULL ) {
F_18 ( & V_1 -> V_24 -> V_25 , L_175
L_176 ) ;
return - V_227 ;
}
}
return 0 ;
}
static void F_299 ( T_1 * V_1 )
{
int V_20 ;
if ( V_1 -> V_421 ) {
for ( V_20 = 0 ; V_20 < V_1 -> V_19 ; V_20 ++ )
F_15 ( V_1 -> V_421 [ V_20 ] ) ;
F_15 ( V_1 -> V_421 ) ;
}
}
static void F_300 ( T_1 * V_1 )
{
F_15 ( V_1 -> V_124 ) ;
if ( V_1 -> V_125 )
F_79 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( T_2 ) ,
V_1 -> V_125 , V_1 -> V_126 ) ;
if ( V_1 -> V_128 )
F_79 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( V_129 ) ,
V_1 -> V_128 , V_1 -> V_130 ) ;
}
static int F_301 ( T_1 * V_1 ,
T_36 (* F_302)( int , void * ) ,
T_36 (* F_303)( int , void * ) )
{
if ( V_1 -> V_524 || V_1 -> V_526 ) {
if ( ! F_304 ( V_1 -> V_50 [ V_1 -> V_51 ] , F_302 ,
0 , V_1 -> V_46 , V_1 ) )
return 0 ;
F_18 ( & V_1 -> V_24 -> V_25 , L_177
L_178 , V_1 -> V_50 [ V_1 -> V_51 ] ,
V_1 -> V_46 ) ;
return - 1 ;
}
if ( ! F_304 ( V_1 -> V_50 [ V_1 -> V_51 ] , F_303 ,
V_602 , V_1 -> V_46 , V_1 ) )
return 0 ;
F_18 ( & V_1 -> V_24 -> V_25 , L_179 ,
V_1 -> V_50 [ V_1 -> V_51 ] , V_1 -> V_46 ) ;
return - 1 ;
}
static int F_305 ( T_1 * V_1 )
{
if ( F_168 ( V_1 , V_148 , V_603 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_180 ) ;
return - V_274 ;
}
F_174 ( & V_1 -> V_24 -> V_25 , L_181 ) ;
if ( F_255 ( V_1 -> V_24 , V_1 -> V_205 , F_257 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_182 ) ;
return - 1 ;
}
F_174 ( & V_1 -> V_24 -> V_25 , L_183 ) ;
if ( F_255 ( V_1 -> V_24 , V_1 -> V_205 , F_256 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_184
L_185 ) ;
return - 1 ;
}
return 0 ;
}
static void F_306 ( T_1 * V_1 )
{
int V_62 = V_1 -> V_62 ;
F_307 ( V_1 -> V_50 [ V_1 -> V_51 ] , V_1 ) ;
#ifdef F_246
if ( V_1 -> V_524 )
F_308 ( V_1 -> V_24 ) ;
else if ( V_1 -> V_526 )
F_309 ( V_1 -> V_24 ) ;
#endif
F_14 ( V_1 -> V_18 , V_1 -> V_19 ) ;
F_299 ( V_1 ) ;
F_300 ( V_1 ) ;
F_15 ( V_1 -> V_6 ) ;
if ( V_1 -> V_440 )
F_79 ( V_1 -> V_24 , V_1 -> V_441 * sizeof( V_134 ) ,
V_1 -> V_440 , V_1 -> V_510 ) ;
if ( V_1 -> V_497 )
F_276 ( V_1 -> V_497 ) ;
if ( V_1 -> V_200 )
F_276 ( V_1 -> V_200 ) ;
if ( V_1 -> V_205 )
F_276 ( V_1 -> V_205 ) ;
F_310 ( V_1 -> V_287 , V_1 -> V_46 ) ;
F_67 ( V_1 ) ;
F_277 ( V_1 -> V_24 ) ;
F_15 ( V_1 ) ;
V_265 [ V_62 ] = NULL ;
}
static int F_311 ( struct V_474 * V_24 , const struct V_604 * V_605 )
{
int V_20 ;
int V_22 = 0 ;
int V_278 ;
int V_606 = 0 ;
int V_607 , V_316 ;
T_29 * V_300 ;
T_1 * V_1 ;
unsigned long V_13 ;
if ( ( V_444 ) && ( V_532 == 1 ) )
return - V_533 ;
V_278 = F_294 ( V_24 ) ;
if ( V_278 ) {
if ( V_278 != - V_593 )
return V_278 ;
V_606 = 1 ;
V_278 = 0 ;
}
V_608:
V_20 = F_278 ( V_24 ) ;
if ( V_20 < 0 )
return - V_227 ;
V_1 = V_265 [ V_20 ] ;
V_1 -> V_24 = V_24 ;
V_1 -> V_451 = 1 ;
V_1 -> V_51 = V_514 ? V_609 : V_610 ;
F_76 ( & V_1 -> V_387 ) ;
F_76 ( & V_1 -> V_15 ) ;
F_312 ( & V_1 -> V_452 ) ;
if ( F_271 ( V_1 ) != 0 )
goto V_611;
sprintf ( V_1 -> V_46 , L_186 , V_20 ) ;
V_1 -> V_62 = V_20 ;
if ( V_553 < 2 )
V_553 = 2 ;
if ( V_553 > 16 )
V_553 = 16 ;
F_313 ( & V_1 -> V_100 ) ;
if ( F_63 ( V_1 ) )
goto V_612;
if ( ! F_314 ( V_24 , F_284 ( 64 ) ) )
V_607 = 1 ;
else if ( ! F_314 ( V_24 , F_284 ( 32 ) ) )
V_607 = 0 ;
else {
F_18 ( & V_1 -> V_24 -> V_25 , L_187 ) ;
goto V_613;
}
if ( V_20 < V_614 )
V_1 -> V_287 = V_615 + V_20 ;
V_278 = F_315 ( V_1 -> V_287 , V_1 -> V_46 ) ;
if ( V_278 == - V_58 || V_278 == - V_81 ) {
F_18 ( & V_1 -> V_24 -> V_25 ,
L_188
L_189 , V_1 -> V_287 , V_1 -> V_46 , V_20 ) ;
goto V_613;
} else {
if ( V_20 >= V_614 )
V_1 -> V_287 = V_278 ;
}
V_1 -> V_384 . V_616 ( V_1 , V_617 ) ;
V_278 = F_301 ( V_1 , F_223 , F_222 ) ;
if ( V_278 )
goto V_618;
F_174 ( & V_1 -> V_24 -> V_25 , L_190 ,
V_1 -> V_46 , V_24 -> V_94 , F_316 ( V_24 ) ,
V_1 -> V_50 [ V_1 -> V_51 ] , V_607 ? L_173 : L_191 ) ;
if ( F_296 ( V_1 ) )
goto V_619;
if ( F_298 ( V_1 ) )
goto V_619;
V_1 -> V_18 = F_16 ( V_1 ,
V_1 -> V_21 , V_1 -> V_19 ) ;
if ( ! V_1 -> V_18 && V_1 -> V_21 > 0 )
goto V_619;
F_317 ( & V_1 -> V_14 ) ;
F_318 ( V_24 , V_1 ) ;
F_319 ( V_1 -> V_124 , V_1 -> V_19 ) ;
V_1 -> V_52 = 0 ;
V_1 -> V_64 = - 1 ;
for ( V_22 = 0 ; V_22 < V_312 ; V_22 ++ ) {
V_1 -> V_63 [ V_22 ] = NULL ;
V_1 -> V_137 [ V_22 ] = NULL ;
}
if ( V_606 ) {
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_1 -> V_384 . V_616 ( V_1 , V_617 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
F_307 ( V_1 -> V_50 [ V_1 -> V_51 ] , V_1 ) ;
V_278 = F_301 ( V_1 , F_221 ,
F_220 ) ;
if ( V_278 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_192
L_193 ) ;
goto V_619;
}
V_278 = F_305 ( V_1 ) ;
if ( V_278 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_194 ) ;
goto V_619;
}
F_174 ( & V_1 -> V_24 -> V_25 , L_195 ) ;
F_174 ( & V_1 -> V_24 -> V_25 ,
L_196 ) ;
V_1 -> V_384 . V_616 ( V_1 , V_620 ) ;
F_258 ( 10000 ) ;
V_1 -> V_384 . V_616 ( V_1 , V_617 ) ;
V_278 = F_289 ( V_1 -> V_200 ) ;
if ( V_278 )
F_174 ( & V_1 -> V_24 -> V_25 ,
L_197 ) ;
F_306 ( V_1 ) ;
V_606 = 0 ;
if ( V_278 )
return - V_533 ;
goto V_608;
}
F_320 ( V_1 ) ;
V_1 -> V_384 . V_616 ( V_1 , V_620 ) ;
V_300 = F_127 ( sizeof( T_29 ) , V_23 ) ;
if ( V_300 == NULL ) {
F_18 ( & V_1 -> V_24 -> V_25 , L_33 ) ;
goto V_619;
}
V_316 = F_137 ( V_1 , V_280 , V_300 ,
sizeof( T_29 ) , 0 , V_148 , V_281 ) ;
if ( V_316 == V_282 ) {
V_1 -> V_49 [ 0 ] = V_300 -> V_283 [ 32 ] ;
V_1 -> V_49 [ 1 ] = V_300 -> V_283 [ 33 ] ;
V_1 -> V_49 [ 2 ] = V_300 -> V_283 [ 34 ] ;
V_1 -> V_49 [ 3 ] = V_300 -> V_283 [ 35 ] ;
} else {
F_154 ( & V_1 -> V_24 -> V_25 , L_198
L_199 ) ;
}
F_15 ( V_300 ) ;
F_1 ( V_1 ) ;
V_1 -> V_296 = 8192 ;
F_128 ( V_1 , 1 , 0 ) ;
F_40 ( V_1 ) ;
V_1 -> V_451 = 0 ;
return 0 ;
V_619:
F_300 ( V_1 ) ;
F_299 ( V_1 ) ;
F_14 ( V_1 -> V_18 , V_1 -> V_19 ) ;
F_307 ( V_1 -> V_50 [ V_1 -> V_51 ] , V_1 ) ;
V_618:
F_310 ( V_1 -> V_287 , V_1 -> V_46 ) ;
V_613:
F_67 ( V_1 ) ;
V_612:
F_277 ( V_24 ) ;
V_611:
V_1 -> V_451 = 0 ;
F_318 ( V_24 , NULL ) ;
F_279 ( V_1 ) ;
return - V_533 ;
}
static void F_321 ( struct V_474 * V_24 )
{
T_1 * V_1 ;
char * V_621 ;
int V_316 ;
V_1 = F_322 ( V_24 ) ;
V_621 = F_127 ( 4 , V_23 ) ;
if ( ! V_621 ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_200 ) ;
return;
}
V_316 = F_137 ( V_1 , V_341 , V_621 ,
4 , 0 , V_148 , V_281 ) ;
F_15 ( V_621 ) ;
if ( V_316 != V_282 )
F_154 ( & V_1 -> V_24 -> V_25 , L_201 ) ;
V_1 -> V_384 . V_616 ( V_1 , V_617 ) ;
F_307 ( V_1 -> V_50 [ V_1 -> V_51 ] , V_1 ) ;
}
static int F_275 ( struct V_97 * V_1 )
{
T_11 V_513 ;
V_513 = F_110 ( & ( V_1 -> V_200 -> V_470 ) ) ;
if ( ! ( V_513 & V_622 ) )
return - V_593 ;
V_1 -> V_441 = F_110 ( & ( V_1 -> V_200 -> V_473 ) ) ;
F_112 ( V_623 , & ( V_1 -> V_200 -> V_201 . V_472 ) ) ;
F_112 ( V_204 , V_1 -> V_205 + V_206 ) ;
F_239 ( V_1 ) ;
F_233 ( V_1 ) ;
if ( ! ( F_110 ( & ( V_1 -> V_200 -> V_471 ) ) & V_623 ) ) {
F_154 ( & V_1 -> V_24 -> V_25 , L_202 ) ;
return - V_533 ;
}
V_1 -> V_3 = V_623 ;
return 0 ;
}
static void F_323 ( struct V_474 * V_24 )
{
T_1 * V_1 ;
int V_20 , V_22 ;
if ( F_322 ( V_24 ) == NULL ) {
F_18 ( & V_24 -> V_25 , L_203 ) ;
return;
}
V_1 = F_322 ( V_24 ) ;
V_20 = V_1 -> V_62 ;
if ( V_265 [ V_20 ] == NULL ) {
F_18 ( & V_24 -> V_25 , L_204 ) ;
return;
}
F_91 ( & V_1 -> V_452 ) ;
F_225 ( V_1 ) ;
F_324 ( V_1 -> V_46 , V_86 ) ;
F_310 ( V_1 -> V_287 , V_1 -> V_46 ) ;
for ( V_22 = 0 ; V_22 < V_312 ; V_22 ++ ) {
struct V_137 * V_138 = V_1 -> V_137 [ V_22 ] ;
if ( V_138 ) {
struct V_325 * V_326 = V_138 -> V_139 ;
if ( V_138 -> V_13 & V_327 ) {
F_72 ( V_1 , V_22 , 1 ) ;
F_166 ( V_138 ) ;
}
if ( V_326 )
F_149 ( V_326 ) ;
}
}
#ifdef F_25
F_325 ( V_1 ) ;
#endif
F_321 ( V_24 ) ;
#ifdef F_246
if ( V_1 -> V_524 )
F_308 ( V_1 -> V_24 ) ;
else if ( V_1 -> V_526 )
F_309 ( V_1 -> V_24 ) ;
#endif
F_276 ( V_1 -> V_497 ) ;
F_276 ( V_1 -> V_200 ) ;
F_276 ( V_1 -> V_205 ) ;
F_300 ( V_1 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_19 ; V_22 ++ )
F_15 ( V_1 -> V_421 [ V_22 ] ) ;
F_15 ( V_1 -> V_421 ) ;
F_14 ( V_1 -> V_18 , V_1 -> V_19 ) ;
F_15 ( V_1 -> V_6 ) ;
if ( V_1 -> V_440 )
F_79 ( V_1 -> V_24 , V_1 -> V_441 * sizeof( V_134 ) ,
V_1 -> V_440 , V_1 -> V_510 ) ;
F_277 ( V_24 ) ;
F_318 ( V_24 , NULL ) ;
F_67 ( V_1 ) ;
F_92 ( & V_1 -> V_452 ) ;
F_279 ( V_1 ) ;
}
static int T_44 F_326 ( void )
{
int V_79 ;
F_242 ( sizeof( T_2 ) % V_624 ) ;
F_327 (KERN_INFO DRIVER_NAME L_205 ) ;
V_79 = F_328 ( & V_117 ) ;
if ( V_79 )
return V_79 ;
V_99 = F_329 ( F_229 , NULL , L_206 ) ;
if ( F_38 ( V_99 ) ) {
V_79 = F_39 ( V_99 ) ;
goto V_625;
}
V_79 = F_330 ( & V_626 ) ;
if ( V_79 )
goto V_627;
return V_79 ;
V_627:
F_331 ( V_99 ) ;
V_625:
F_332 ( & V_117 ) ;
return V_79 ;
}
static void T_45 F_333 ( void )
{
int V_20 ;
F_334 ( & V_626 ) ;
for ( V_20 = 0 ; V_20 < V_567 ; V_20 ++ ) {
if ( V_265 [ V_20 ] != NULL ) {
F_154 ( & V_265 [ V_20 ] -> V_24 -> V_25 ,
L_207 ) ;
F_323 ( V_265 [ V_20 ] -> V_24 ) ;
}
}
F_331 ( V_99 ) ;
if ( V_86 )
F_324 ( L_15 , NULL ) ;
F_332 ( & V_117 ) ;
}
