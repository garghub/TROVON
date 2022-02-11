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
static int F_21 ( T_1 * V_1 , T_2 * V_2 ,
T_3 * V_39 , int V_40 )
{
T_3 * V_27 ;
T_4 V_28 ;
V_27 = & V_2 -> V_31 [ V_1 -> V_30 - 1 ] ;
V_27 -> V_41 = V_42 ;
V_27 -> V_37 = V_40 ;
V_28 . V_36 = F_22 ( V_1 -> V_24 , V_39 , V_40 ,
V_38 ) ;
if ( F_23 ( & V_1 -> V_24 -> V_25 , V_28 . V_36 ) ) {
F_24 ( & V_1 -> V_24 -> V_25 ,
L_3 ,
V_43 ) ;
return - 1 ;
}
V_27 -> V_34 . V_33 = V_28 . V_32 . V_33 ;
V_27 -> V_34 . V_35 = V_28 . V_32 . V_35 ;
return 0 ;
}
static void F_25 ( struct V_44 * V_45 )
{
T_1 * V_1 = V_45 -> V_46 ;
F_26 ( V_45 , L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11
L_12
L_13 ,
V_1 -> V_47 ,
V_1 -> V_48 ,
( unsigned long ) V_1 -> V_49 ,
V_1 -> V_50 [ 0 ] , V_1 -> V_50 [ 1 ] , V_1 -> V_50 [ 2 ] ,
V_1 -> V_50 [ 3 ] , ( unsigned int ) V_1 -> V_51 [ V_1 -> V_52 ] ,
V_1 -> V_53 ,
V_1 -> V_16 , V_1 -> V_54 ,
V_1 -> V_17 , V_1 -> V_55 , V_1 -> V_56 ) ;
#ifdef F_27
F_28 ( V_45 , V_1 ) ;
#endif
}
static void * F_29 ( struct V_44 * V_45 , T_5 * V_57 )
{
T_1 * V_1 = V_45 -> V_46 ;
unsigned long V_13 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_58 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return F_30 ( - V_59 ) ;
}
V_1 -> V_58 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( * V_57 == 0 )
F_25 ( V_45 ) ;
return V_57 ;
}
static int F_31 ( struct V_44 * V_45 , void * V_60 )
{
T_6 V_61 , V_62 ;
T_1 * V_1 = V_45 -> V_46 ;
unsigned V_63 = V_1 -> V_63 ;
T_5 * V_57 = V_60 ;
T_7 * V_64 = V_1 -> V_64 [ * V_57 ] ;
if ( * V_57 > V_1 -> V_65 )
return 0 ;
if ( V_64 == NULL )
return 0 ;
if ( V_64 -> V_66 == 0 )
return 0 ;
V_61 = V_64 -> V_67 ;
V_62 = F_32 ( V_61 , V_68 ) ;
V_62 *= 100 ;
F_32 ( V_62 , V_68 ) ;
if ( V_64 -> V_69 < 0 || V_64 -> V_69 > V_70 )
V_64 -> V_69 = V_70 ;
F_26 ( V_45 , L_14
L_15 ,
V_63 , ( int ) * V_57 , ( int ) V_61 , ( int ) V_62 ,
V_71 [ V_64 -> V_69 ] ) ;
return 0 ;
}
static void * F_33 ( struct V_44 * V_45 , void * V_60 , T_5 * V_57 )
{
T_1 * V_1 = V_45 -> V_46 ;
if ( * V_57 > V_1 -> V_65 )
return NULL ;
* V_57 += 1 ;
return V_57 ;
}
static void F_34 ( struct V_44 * V_45 , void * V_60 )
{
T_1 * V_1 = V_45 -> V_46 ;
if ( V_60 == F_30 ( - V_59 ) )
return;
V_1 -> V_58 = 0 ;
}
static int F_35 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
int V_74 = F_36 ( V_73 , & V_75 ) ;
struct V_44 * V_45 = V_73 -> V_76 ;
if ( ! V_74 )
V_45 -> V_46 = F_37 ( V_72 ) ;
return V_74 ;
}
static T_8
F_38 ( struct V_73 * V_73 , const char T_9 * V_77 ,
T_10 V_78 , T_5 * V_79 )
{
int V_80 ;
char * V_81 ;
#ifndef F_27
return - V_82 ;
#endif
if ( ! V_77 || V_78 > V_83 - 1 )
return - V_82 ;
V_81 = F_39 ( V_77 , V_78 ) ;
if ( F_40 ( V_81 ) )
return F_41 ( V_81 ) ;
#ifdef F_27
if ( strncmp ( V_84 , V_81 , sizeof V_84 - 1 ) == 0 ) {
struct V_44 * V_45 = V_73 -> V_76 ;
T_1 * V_1 = V_45 -> V_46 ;
V_80 = F_42 ( V_1 ) ;
if ( V_80 == 0 )
V_80 = V_78 ;
} else
#endif
V_80 = - V_82 ;
F_15 ( V_81 ) ;
return V_80 ;
}
static void F_1 ( T_1 * V_1 )
{
struct V_85 * V_86 ;
if ( V_87 == NULL )
V_87 = F_43 ( L_16 , NULL ) ;
if ( ! V_87 )
return;
V_86 = F_44 ( V_1 -> V_47 , V_88 | V_89 | V_90 |
V_91 , V_87 ,
& V_92 , V_1 ) ;
}
static int F_45 ( T_11 V_49 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < F_46 ( V_93 ) ; V_20 ++ )
if ( V_93 [ V_20 ] == V_49 )
return 0 ;
return 1 ;
}
static int F_47 ( T_11 V_49 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < F_46 ( V_94 ) ; V_20 ++ )
if ( V_94 [ V_20 ] == V_49 )
return 0 ;
return 1 ;
}
static int F_48 ( T_11 V_49 )
{
return F_45 ( V_49 ) ||
F_47 ( V_49 ) ;
}
static T_8 F_49 ( struct V_95 * V_25 ,
struct V_96 * V_97 ,
char * V_77 )
{
struct V_98 * V_1 = F_50 ( V_25 ) ;
return snprintf ( V_77 , 20 , L_17 , F_48 ( V_1 -> V_49 ) ) ;
}
static T_8 F_51 ( struct V_95 * V_25 ,
struct V_96 * V_97 ,
const char * V_77 , T_10 V_99 )
{
struct V_98 * V_1 = F_50 ( V_25 ) ;
F_52 ( V_1 ) ;
F_53 ( V_100 ) ;
F_54 ( & V_1 -> V_101 ) ;
return V_99 ;
}
static T_8 F_55 ( struct V_95 * V_25 ,
struct V_96 * V_97 ,
char * V_77 )
{
struct V_98 * V_1 = F_50 ( V_25 ) ;
return snprintf ( V_77 , 20 , L_18 ,
V_1 -> V_3 & V_4 ?
L_19 : L_20 ) ;
}
static T_8 F_56 ( struct V_95 * V_25 ,
struct V_96 * V_97 ,
char * V_77 )
{
T_7 * V_64 = F_57 ( V_25 ) ;
struct V_98 * V_1 = F_50 ( V_64 -> V_25 . V_102 ) ;
T_12 V_103 [ 16 ] ;
unsigned long V_13 ;
int V_74 = 0 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_58 )
V_74 = - V_59 ;
else
memcpy ( V_103 , V_64 -> V_104 , sizeof( V_103 ) ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_74 )
return V_74 ;
else
return snprintf ( V_77 , 16 * 2 + 2 ,
L_21
L_22 ,
V_103 [ 0 ] , V_103 [ 1 ] , V_103 [ 2 ] , V_103 [ 3 ] ,
V_103 [ 4 ] , V_103 [ 5 ] , V_103 [ 6 ] , V_103 [ 7 ] ,
V_103 [ 8 ] , V_103 [ 9 ] , V_103 [ 10 ] , V_103 [ 11 ] ,
V_103 [ 12 ] , V_103 [ 13 ] , V_103 [ 14 ] , V_103 [ 15 ] ) ;
}
static T_8 F_58 ( struct V_95 * V_25 ,
struct V_96 * V_97 ,
char * V_77 )
{
T_7 * V_64 = F_57 ( V_25 ) ;
struct V_98 * V_1 = F_50 ( V_64 -> V_25 . V_102 ) ;
char V_105 [ V_106 + 1 ] ;
unsigned long V_13 ;
int V_74 = 0 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_58 )
V_74 = - V_59 ;
else
memcpy ( V_105 , V_64 -> V_105 , V_106 + 1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_74 )
return V_74 ;
else
return snprintf ( V_77 , sizeof( V_105 ) + 1 , L_18 , V_64 -> V_105 ) ;
}
static T_8 F_59 ( struct V_95 * V_25 ,
struct V_96 * V_97 ,
char * V_77 )
{
T_7 * V_64 = F_57 ( V_25 ) ;
struct V_98 * V_1 = F_50 ( V_64 -> V_25 . V_102 ) ;
char V_107 [ V_108 + 1 ] ;
unsigned long V_13 ;
int V_74 = 0 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_58 )
V_74 = - V_59 ;
else
memcpy ( V_107 , V_64 -> V_107 , V_108 + 1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_74 )
return V_74 ;
else
return snprintf ( V_77 , sizeof( V_107 ) + 1 , L_18 , V_64 -> V_107 ) ;
}
static T_8 F_60 ( struct V_95 * V_25 ,
struct V_96 * V_97 ,
char * V_77 )
{
T_7 * V_64 = F_57 ( V_25 ) ;
struct V_98 * V_1 = F_50 ( V_64 -> V_25 . V_102 ) ;
char V_109 [ V_110 + 1 ] ;
unsigned long V_13 ;
int V_74 = 0 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_58 )
V_74 = - V_59 ;
else
memcpy ( V_109 , V_64 -> V_109 , V_110 + 1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_74 )
return V_74 ;
else
return snprintf ( V_77 , sizeof( V_109 ) + 1 , L_18 , V_64 -> V_109 ) ;
}
static T_8 F_61 ( struct V_95 * V_25 ,
struct V_96 * V_97 , char * V_77 )
{
T_7 * V_64 = F_57 ( V_25 ) ;
struct V_98 * V_1 = F_50 ( V_64 -> V_25 . V_102 ) ;
unsigned long V_13 ;
unsigned char V_111 [ 8 ] ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_58 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_59 ;
}
if ( ! V_64 -> V_66 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_112 ;
}
memcpy ( V_111 , V_64 -> V_113 , sizeof( V_111 ) ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
return snprintf ( V_77 , 20 , L_23 ,
V_111 [ 0 ] , V_111 [ 1 ] , V_111 [ 2 ] , V_111 [ 3 ] ,
V_111 [ 4 ] , V_111 [ 5 ] , V_111 [ 6 ] , V_111 [ 7 ] ) ;
}
static T_8 F_62 ( struct V_95 * V_25 ,
struct V_96 * V_97 , char * V_77 )
{
T_7 * V_64 = F_57 ( V_25 ) ;
struct V_98 * V_1 = F_50 ( V_64 -> V_25 . V_102 ) ;
int V_114 ;
unsigned long V_13 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_58 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_59 ;
}
V_114 = V_64 -> V_69 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_114 < 0 || V_114 > V_70 )
V_114 = V_70 ;
return snprintf ( V_77 , strlen ( V_71 [ V_114 ] ) + 7 , L_24 ,
V_71 [ V_114 ] ) ;
}
static T_8 F_63 ( struct V_95 * V_25 ,
struct V_96 * V_97 , char * V_77 )
{
T_7 * V_64 = F_57 ( V_25 ) ;
struct V_98 * V_1 = F_50 ( V_64 -> V_25 . V_102 ) ;
unsigned long V_13 ;
int V_99 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_58 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_59 ;
}
V_99 = V_64 -> V_115 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
return snprintf ( V_77 , 20 , L_17 , V_99 ) ;
}
static void F_64 ( struct V_95 * V_25 )
{
}
static int F_65 ( struct V_98 * V_1 )
{
F_66 ( & V_1 -> V_25 ) ;
V_1 -> V_25 . type = & V_116 ;
V_1 -> V_25 . V_117 = & V_118 ;
F_67 ( & V_1 -> V_25 , L_25 , V_1 -> V_47 ) ;
V_1 -> V_25 . V_102 = & V_1 -> V_24 -> V_25 ;
return F_68 ( & V_1 -> V_25 ) ;
}
static void F_69 ( struct V_98 * V_1 )
{
F_70 ( & V_1 -> V_25 ) ;
F_71 ( & V_1 -> V_25 ) ;
}
static void F_72 ( struct V_95 * V_25 )
{
T_7 * V_64 = F_57 ( V_25 ) ;
F_15 ( V_64 ) ;
}
static long F_73 ( struct V_98 * V_1 ,
int V_119 )
{
struct V_95 * V_25 ;
if ( V_1 -> V_64 [ V_119 ] -> V_120 )
return 0 ;
V_25 = & V_1 -> V_64 [ V_119 ] -> V_25 ;
F_66 ( V_25 ) ;
V_25 -> type = & V_121 ;
V_25 -> V_117 = & V_118 ;
F_67 ( V_25 , L_26 , V_1 -> V_63 , V_119 ) ;
V_25 -> V_102 = & V_1 -> V_25 ;
V_1 -> V_64 [ V_119 ] -> V_120 = 1 ;
return F_68 ( V_25 ) ;
}
static void F_74 ( struct V_98 * V_1 , int V_119 ,
int V_122 )
{
struct V_95 * V_25 = & V_1 -> V_64 [ V_119 ] -> V_25 ;
if ( V_119 == 0 && ! V_122 )
return;
F_70 ( V_25 ) ;
F_71 ( V_25 ) ;
V_1 -> V_64 [ V_119 ] = NULL ;
}
static T_2 * F_75 ( T_1 * V_1 )
{
T_2 * V_2 ;
int V_20 ;
T_4 V_28 ;
T_13 V_123 , V_124 ;
do {
V_20 = F_76 ( V_1 -> V_125 , V_1 -> V_19 ) ;
if ( V_20 == V_1 -> V_19 )
return NULL ;
} while ( F_77 ( V_20 , V_1 -> V_125 ) != 0 );
V_2 = V_1 -> V_126 + V_20 ;
memset ( V_2 , 0 , sizeof( T_2 ) ) ;
V_123 = V_1 -> V_127 + V_20 * sizeof( T_2 ) ;
V_2 -> V_128 = V_1 -> V_129 + V_20 ;
memset ( V_2 -> V_128 , 0 , sizeof( V_130 ) ) ;
V_124 = V_1 -> V_131
+ V_20 * sizeof( V_130 ) ;
V_1 -> V_132 ++ ;
V_2 -> V_133 = V_20 ;
F_78 ( & V_2 -> V_10 ) ;
V_2 -> V_5 = ( V_134 ) V_123 ;
V_28 . V_36 = ( V_135 ) V_124 ;
V_2 -> V_136 . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_136 . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_136 . V_37 = sizeof( V_130 ) ;
V_2 -> V_63 = V_1 -> V_63 ;
return V_2 ;
}
static T_2 * F_79 ( T_1 * V_1 )
{
T_2 * V_2 ;
T_4 V_28 ;
T_13 V_123 , V_124 ;
V_2 = F_80 ( V_1 -> V_24 , sizeof( T_2 ) ,
& V_123 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_133 = - 1 ;
V_2 -> V_128 = F_80 ( V_1 -> V_24 , sizeof( V_130 ) ,
& V_124 ) ;
if ( V_2 -> V_128 == NULL ) {
F_81 ( V_1 -> V_24 ,
sizeof( T_2 ) , V_2 , V_123 ) ;
return NULL ;
}
F_78 ( & V_2 -> V_10 ) ;
V_2 -> V_5 = ( V_134 ) V_123 ;
V_28 . V_36 = ( V_135 ) V_124 ;
V_2 -> V_136 . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_136 . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_136 . V_37 = sizeof( V_130 ) ;
V_2 -> V_63 = V_1 -> V_63 ;
return V_2 ;
}
static void F_82 ( T_1 * V_1 , T_2 * V_2 )
{
int V_20 ;
V_20 = V_2 - V_1 -> V_126 ;
F_83 ( V_20 , V_1 -> V_125 ) ;
V_1 -> V_137 ++ ;
}
static void F_84 ( T_1 * V_1 , T_2 * V_2 )
{
T_4 V_28 ;
V_28 . V_32 . V_33 = V_2 -> V_136 . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_2 -> V_136 . V_34 . V_35 ;
F_81 ( V_1 -> V_24 , sizeof( V_130 ) ,
V_2 -> V_128 , ( T_13 ) V_28 . V_36 ) ;
F_81 ( V_1 -> V_24 , sizeof( T_2 ) , V_2 ,
( T_13 ) F_85 ( V_1 , ( T_11 ) V_2 -> V_5 ) ) ;
}
static inline T_1 * F_86 ( struct V_138 * V_139 )
{
return V_139 -> V_140 -> V_141 ;
}
static inline T_7 * F_87 ( struct V_138 * V_139 )
{
return V_139 -> V_76 ;
}
static int F_88 ( struct V_142 * V_143 , T_14 V_144 )
{
T_1 * V_1 = F_86 ( V_143 -> V_145 ) ;
T_7 * V_64 = F_87 ( V_143 -> V_145 ) ;
F_89 ( & V_1 -> V_24 -> V_25 , L_27 , V_143 -> V_145 -> V_146 ) ;
if ( V_64 -> V_58 )
return - V_59 ;
if ( V_64 -> V_66 == 0 ) {
if ( F_90 ( V_143 -> V_147 ) != 0 ) {
if ( F_90 ( V_143 -> V_147 ) & 0x0f ) {
return - V_148 ;
} else if ( memcmp ( V_64 -> V_113 , V_149 ,
sizeof( V_64 -> V_113 ) ) ) {
return - V_148 ;
}
}
if ( ! F_91 ( V_150 ) )
return - V_151 ;
}
V_64 -> V_115 ++ ;
V_1 -> V_115 ++ ;
return 0 ;
}
static int F_92 ( struct V_142 * V_143 , T_14 V_144 )
{
int V_74 ;
F_93 ( & V_152 ) ;
V_74 = F_88 ( V_143 , V_144 ) ;
F_94 ( & V_152 ) ;
return V_74 ;
}
static void F_95 ( struct V_138 * V_139 , T_14 V_144 )
{
T_1 * V_1 ;
T_7 * V_64 ;
F_93 ( & V_152 ) ;
V_1 = F_86 ( V_139 ) ;
V_64 = F_87 ( V_139 ) ;
F_89 ( & V_1 -> V_24 -> V_25 , L_28 , V_139 -> V_146 ) ;
V_64 -> V_115 -- ;
V_1 -> V_115 -- ;
F_94 ( & V_152 ) ;
}
static int F_96 ( struct V_142 * V_143 , T_14 V_144 ,
unsigned V_153 , unsigned long V_154 )
{
switch ( V_153 ) {
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
case V_169 :
return F_97 ( V_143 , V_144 , V_153 , V_154 ) ;
case V_170 :
return F_98 ( V_143 , V_144 , V_153 , V_154 ) ;
case V_171 :
return F_99 ( V_143 , V_144 , V_153 , V_154 ) ;
default:
return - V_172 ;
}
}
static int F_98 ( struct V_142 * V_143 , T_14 V_144 ,
unsigned V_153 , unsigned long V_154 )
{
T_15 T_9 * V_173 =
( T_15 T_9 * ) V_154 ;
T_16 V_174 ;
T_16 T_9 * V_175 = F_100 ( sizeof( V_174 ) ) ;
int V_80 ;
T_11 V_176 ;
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
V_80 = 0 ;
V_80 |=
F_101 ( & V_174 . V_177 , & V_173 -> V_177 ,
sizeof( V_174 . V_177 ) ) ;
V_80 |=
F_101 ( & V_174 . V_178 , & V_173 -> V_178 ,
sizeof( V_174 . V_178 ) ) ;
V_80 |=
F_101 ( & V_174 . V_179 , & V_173 -> V_179 ,
sizeof( V_174 . V_179 ) ) ;
V_80 |= F_102 ( V_174 . V_180 , & V_173 -> V_180 ) ;
V_80 |= F_102 ( V_176 , & V_173 -> V_77 ) ;
V_174 . V_77 = F_103 ( V_176 ) ;
V_80 |= F_104 ( V_175 , & V_174 , sizeof( V_174 ) ) ;
if ( V_80 )
return - V_181 ;
V_80 = F_97 ( V_143 , V_144 , V_182 , ( unsigned long ) V_175 ) ;
if ( V_80 )
return V_80 ;
V_80 |=
F_105 ( & V_173 -> V_179 , & V_175 -> V_179 ,
sizeof( V_173 -> V_179 ) ) ;
if ( V_80 )
return - V_181 ;
return V_80 ;
}
static int F_99 ( struct V_142 * V_143 , T_14 V_144 ,
unsigned V_153 , unsigned long V_154 )
{
T_17 T_9 * V_173 =
( T_17 T_9 * ) V_154 ;
T_18 V_174 ;
T_18 T_9 * V_175 =
F_100 ( sizeof( V_174 ) ) ;
int V_80 ;
T_11 V_176 ;
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
V_80 = 0 ;
V_80 |=
F_101 ( & V_174 . V_177 , & V_173 -> V_177 ,
sizeof( V_174 . V_177 ) ) ;
V_80 |=
F_101 ( & V_174 . V_178 , & V_173 -> V_178 ,
sizeof( V_174 . V_178 ) ) ;
V_80 |=
F_101 ( & V_174 . V_179 , & V_173 -> V_179 ,
sizeof( V_174 . V_179 ) ) ;
V_80 |= F_102 ( V_174 . V_180 , & V_173 -> V_180 ) ;
V_80 |= F_102 ( V_174 . V_183 , & V_173 -> V_183 ) ;
V_80 |= F_102 ( V_176 , & V_173 -> V_77 ) ;
V_174 . V_77 = F_103 ( V_176 ) ;
V_80 |= F_104 ( V_175 , & V_174 , sizeof( V_174 ) ) ;
if ( V_80 )
return - V_181 ;
V_80 = F_97 ( V_143 , V_144 , V_184 , ( unsigned long ) V_175 ) ;
if ( V_80 )
return V_80 ;
V_80 |=
F_105 ( & V_173 -> V_179 , & V_175 -> V_179 ,
sizeof( V_173 -> V_179 ) ) ;
if ( V_80 )
return - V_181 ;
return V_80 ;
}
static int F_106 ( struct V_142 * V_143 , struct V_185 * V_186 )
{
T_7 * V_64 = F_87 ( V_143 -> V_145 ) ;
if ( ! V_64 -> V_187 )
return - V_148 ;
V_186 -> V_66 = V_64 -> V_66 ;
V_186 -> V_188 = V_64 -> V_188 ;
V_186 -> V_187 = V_64 -> V_187 ;
return 0 ;
}
static void F_107 ( T_1 * V_1 , T_2 * V_2 )
{
if ( V_2 -> V_128 -> V_189 == V_190 &&
V_2 -> V_128 -> V_191 != V_192 )
( void ) F_108 ( V_1 , V_2 ) ;
}
static int F_109 ( T_1 * V_1 , void T_9 * V_193 )
{
T_19 V_194 ;
if ( ! V_193 )
return - V_82 ;
V_194 . V_195 = F_110 ( V_1 -> V_24 -> V_117 ) ;
V_194 . V_117 = V_1 -> V_24 -> V_117 -> V_196 ;
V_194 . V_197 = V_1 -> V_24 -> V_198 ;
V_194 . V_49 = V_1 -> V_49 ;
if ( F_104 ( V_193 , & V_194 , sizeof( T_19 ) ) )
return - V_181 ;
return 0 ;
}
static int F_111 ( T_1 * V_1 , void T_9 * V_193 )
{
T_20 V_199 ;
unsigned long V_13 ;
if ( ! V_193 )
return - V_82 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_199 . V_200 = F_112 ( & V_1 -> V_201 -> V_202 . V_203 ) ;
V_199 . V_99 = F_112 ( & V_1 -> V_201 -> V_202 . V_204 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( F_104
( V_193 , & V_199 , sizeof( T_20 ) ) )
return - V_181 ;
return 0 ;
}
static int F_113 ( T_1 * V_1 , void T_9 * V_193 )
{
T_20 V_199 ;
unsigned long V_13 ;
int V_20 ;
if ( ! V_193 )
return - V_82 ;
if ( ! F_91 ( V_150 ) )
return - V_151 ;
if ( F_101 ( & V_199 , V_193 , sizeof( V_199 ) ) )
return - V_181 ;
if ( ( V_199 . V_200 == 0 ) && ( V_199 . V_99 == 0 ) )
return - V_82 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
F_114 ( V_199 . V_200 , & ( V_1 -> V_201 -> V_202 . V_203 ) ) ;
F_114 ( V_199 . V_99 , & ( V_1 -> V_201 -> V_202 . V_204 ) ) ;
F_114 ( V_205 , V_1 -> V_206 + V_207 ) ;
for ( V_20 = 0 ; V_20 < V_208 ; V_20 ++ ) {
if ( ! ( F_112 ( V_1 -> V_206 + V_207 ) & V_205 ) )
break;
F_115 ( 1000 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_20 >= V_208 )
return - V_209 ;
return 0 ;
}
static int F_116 ( T_1 * V_1 , void T_9 * V_193 )
{
T_21 V_210 ;
unsigned long V_13 ;
int V_20 ;
if ( ! V_193 )
return - V_82 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
V_210 [ V_20 ] = F_117 ( & V_1 -> V_201 -> V_211 [ V_20 ] ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( F_104 ( V_193 , V_210 , sizeof( T_21 ) ) )
return - V_181 ;
return 0 ;
}
static int F_118 ( T_1 * V_1 , void T_9 * V_193 )
{
T_21 V_210 ;
unsigned long V_13 ;
int V_20 ;
if ( ! V_193 )
return - V_82 ;
if ( ! F_91 ( V_150 ) )
return - V_151 ;
if ( F_101 ( V_210 , V_193 , sizeof( T_21 ) ) )
return - V_181 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
F_119 ( V_210 [ V_20 ] , & V_1 -> V_201 -> V_211 [ V_20 ] ) ;
F_114 ( V_205 , V_1 -> V_206 + V_207 ) ;
for ( V_20 = 0 ; V_20 < V_208 ; V_20 ++ ) {
if ( ! ( F_112 ( V_1 -> V_206 + V_207 ) & V_205 ) )
break;
F_115 ( 1000 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( V_20 >= V_208 )
return - V_209 ;
return 0 ;
}
static int F_120 ( T_1 * V_1 , void T_9 * V_193 )
{
T_22 V_212 ;
unsigned long V_13 ;
if ( ! V_193 )
return - V_82 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_212 = F_112 ( & V_1 -> V_201 -> V_213 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( F_104 ( V_193 , & V_212 , sizeof( T_22 ) ) )
return - V_181 ;
return 0 ;
}
static int F_121 ( T_1 * V_1 , void T_9 * V_193 )
{
T_23 V_214 ;
unsigned long V_13 ;
if ( ! V_193 )
return - V_82 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_214 = F_112 ( & V_1 -> V_201 -> V_214 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
if ( F_104 ( V_193 , & V_214 , sizeof( T_23 ) ) )
return - V_181 ;
return 0 ;
}
static int F_122 ( T_1 * V_1 , void T_9 * V_193 )
{
T_24 V_215 ;
if ( ! V_193 )
return - V_82 ;
memcpy ( V_215 , V_1 -> V_50 , 4 ) ;
if ( F_104
( V_193 , V_215 , sizeof( T_24 ) ) )
return - V_181 ;
return 0 ;
}
static int F_123 ( T_1 * V_1 , void T_9 * V_193 )
{
T_25 V_216 = V_217 ;
if ( ! V_193 )
return - V_82 ;
if ( F_104 ( V_193 , & V_216 , sizeof( T_25 ) ) )
return - V_181 ;
return 0 ;
}
static int F_124 ( T_1 * V_1 ,
struct V_138 * V_139 , void T_9 * V_193 )
{
T_26 V_218 ;
T_7 * V_64 = F_87 ( V_139 ) ;
if ( ! V_193 )
return - V_82 ;
memcpy ( & V_218 . V_113 , V_64 -> V_113 , sizeof( V_218 . V_113 ) ) ;
V_218 . V_219 = V_64 -> V_115 ;
V_218 . V_220 = 0 ;
if ( F_104 ( V_193 , & V_218 , sizeof( T_26 ) ) )
return - V_181 ;
return 0 ;
}
static int F_125 ( T_1 * V_1 , void T_9 * V_193 )
{
T_16 V_221 ;
T_2 * V_2 ;
char * V_222 = NULL ;
T_4 V_28 ;
F_126 ( V_223 ) ;
if ( ! V_193 )
return - V_82 ;
if ( ! F_91 ( V_224 ) )
return - V_151 ;
if ( F_101
( & V_221 , V_193 , sizeof( T_16 ) ) )
return - V_181 ;
if ( ( V_221 . V_180 < 1 ) &&
( V_221 . V_178 . Type . V_225 != V_226 ) ) {
return - V_82 ;
}
if ( V_221 . V_180 > 0 ) {
V_222 = F_17 ( V_221 . V_180 , V_23 ) ;
if ( V_222 == NULL )
return - V_181 ;
}
if ( V_221 . V_178 . Type . V_225 == V_227 ) {
if ( F_101 ( V_222 , V_221 . V_77 , V_221 . V_180 ) ) {
F_15 ( V_222 ) ;
return - V_181 ;
}
} else {
memset ( V_222 , 0 , V_221 . V_180 ) ;
}
V_2 = F_79 ( V_1 ) ;
if ( ! V_2 ) {
F_15 ( V_222 ) ;
return - V_228 ;
}
V_2 -> V_11 = V_229 ;
V_2 -> V_7 . V_230 = 0 ;
if ( V_221 . V_180 > 0 ) {
V_2 -> V_7 . V_8 = 1 ;
V_2 -> V_7 . V_29 = 1 ;
} else {
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_7 . V_29 = 0 ;
}
V_2 -> V_7 . V_231 = V_221 . V_177 ;
V_2 -> V_7 . V_232 . V_33 = V_2 -> V_5 ;
V_2 -> V_178 = V_221 . V_178 ;
if ( V_221 . V_180 > 0 ) {
V_28 . V_36 = F_22 ( V_1 -> V_24 , V_222 ,
V_221 . V_180 , V_233 ) ;
V_2 -> V_31 [ 0 ] . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_31 [ 0 ] . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_31 [ 0 ] . V_37 = V_221 . V_180 ;
V_2 -> V_31 [ 0 ] . V_41 = 0 ;
}
V_2 -> V_234 = & V_223 ;
F_10 ( V_1 , V_2 ) ;
F_127 ( & V_223 ) ;
V_28 . V_32 . V_33 = V_2 -> V_31 [ 0 ] . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_2 -> V_31 [ 0 ] . V_34 . V_35 ;
F_20 ( V_1 -> V_24 , ( T_13 ) V_28 . V_36 , V_221 . V_180 ,
V_233 ) ;
F_107 ( V_1 , V_2 ) ;
V_221 . V_179 = * ( V_2 -> V_128 ) ;
if ( F_104 ( V_193 , & V_221 , sizeof( T_16 ) ) ) {
F_15 ( V_222 ) ;
F_84 ( V_1 , V_2 ) ;
return - V_181 ;
}
if ( V_221 . V_178 . Type . V_225 == V_235 ) {
if ( F_104 ( V_221 . V_77 , V_222 , V_221 . V_180 ) ) {
F_15 ( V_222 ) ;
F_84 ( V_1 , V_2 ) ;
return - V_181 ;
}
}
F_15 ( V_222 ) ;
F_84 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_128 ( T_1 * V_1 , void T_9 * V_193 )
{
T_18 * V_236 ;
T_2 * V_2 ;
unsigned char * * V_222 = NULL ;
int * V_237 = NULL ;
T_4 V_28 ;
T_27 V_238 = 0 ;
int V_239 = 0 ;
int V_20 ;
F_126 ( V_223 ) ;
V_134 V_240 ;
V_134 V_241 ;
T_27 T_9 * V_242 ;
if ( ! V_193 )
return - V_82 ;
if ( ! F_91 ( V_224 ) )
return - V_151 ;
V_236 = F_17 ( sizeof( * V_236 ) , V_23 ) ;
if ( ! V_236 ) {
V_239 = - V_228 ;
goto V_243;
}
if ( F_101 ( V_236 , V_193 , sizeof( * V_236 ) ) ) {
V_239 = - V_181 ;
goto V_243;
}
if ( ( V_236 -> V_180 < 1 ) &&
( V_236 -> V_178 . Type . V_225 != V_226 ) ) {
V_239 = - V_82 ;
goto V_243;
}
if ( V_236 -> V_183 > V_244 ) {
V_239 = - V_82 ;
goto V_243;
}
if ( V_236 -> V_180 > V_236 -> V_183 * V_245 ) {
V_239 = - V_82 ;
goto V_243;
}
V_222 = F_129 ( V_245 * sizeof( char * ) , V_23 ) ;
if ( ! V_222 ) {
V_239 = - V_228 ;
goto V_243;
}
V_237 = F_17 ( V_245 * sizeof( int ) , V_23 ) ;
if ( ! V_237 ) {
V_239 = - V_228 ;
goto V_243;
}
V_240 = V_236 -> V_180 ;
V_242 = V_236 -> V_77 ;
while ( V_240 ) {
V_241 = ( V_240 > V_236 -> V_183 ) ? V_236 -> V_183 : V_240 ;
V_237 [ V_238 ] = V_241 ;
V_222 [ V_238 ] = F_17 ( V_241 , V_23 ) ;
if ( V_222 [ V_238 ] == NULL ) {
V_239 = - V_228 ;
goto V_243;
}
if ( V_236 -> V_178 . Type . V_225 == V_227 ) {
if ( F_101 ( V_222 [ V_238 ] , V_242 , V_241 ) ) {
V_239 = - V_181 ;
goto V_243;
}
} else {
memset ( V_222 [ V_238 ] , 0 , V_241 ) ;
}
V_240 -= V_241 ;
V_242 += V_241 ;
V_238 ++ ;
}
V_2 = F_79 ( V_1 ) ;
if ( ! V_2 ) {
V_239 = - V_228 ;
goto V_243;
}
V_2 -> V_11 = V_229 ;
V_2 -> V_7 . V_230 = 0 ;
V_2 -> V_7 . V_8 = V_238 ;
V_2 -> V_7 . V_29 = V_238 ;
V_2 -> V_7 . V_231 = V_236 -> V_177 ;
V_2 -> V_7 . V_232 . V_33 = V_2 -> V_5 ;
V_2 -> V_178 = V_236 -> V_178 ;
for ( V_20 = 0 ; V_20 < V_238 ; V_20 ++ ) {
V_28 . V_36 = F_22 ( V_1 -> V_24 , V_222 [ V_20 ] , V_237 [ V_20 ] ,
V_233 ) ;
V_2 -> V_31 [ V_20 ] . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_2 -> V_31 [ V_20 ] . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_2 -> V_31 [ V_20 ] . V_37 = V_237 [ V_20 ] ;
V_2 -> V_31 [ V_20 ] . V_41 = 0 ;
}
V_2 -> V_234 = & V_223 ;
F_10 ( V_1 , V_2 ) ;
F_127 ( & V_223 ) ;
for ( V_20 = 0 ; V_20 < V_238 ; V_20 ++ ) {
V_28 . V_32 . V_33 = V_2 -> V_31 [ V_20 ] . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_2 -> V_31 [ V_20 ] . V_34 . V_35 ;
F_20 ( V_1 -> V_24 ,
( T_13 ) V_28 . V_36 , V_237 [ V_20 ] ,
V_233 ) ;
}
F_107 ( V_1 , V_2 ) ;
V_236 -> V_179 = * ( V_2 -> V_128 ) ;
if ( F_104 ( V_193 , V_236 , sizeof( * V_236 ) ) ) {
F_84 ( V_1 , V_2 ) ;
V_239 = - V_181 ;
goto V_243;
}
if ( V_236 -> V_178 . Type . V_225 == V_235 ) {
T_27 T_9 * V_246 = V_236 -> V_77 ;
for ( V_20 = 0 ; V_20 < V_238 ; V_20 ++ ) {
if ( F_104 ( V_246 , V_222 [ V_20 ] , V_237 [ V_20 ] ) ) {
F_84 ( V_1 , V_2 ) ;
V_239 = - V_181 ;
goto V_243;
}
V_246 += V_237 [ V_20 ] ;
}
}
F_84 ( V_1 , V_2 ) ;
V_239 = 0 ;
V_243:
if ( V_222 ) {
for ( V_20 = 0 ; V_20 < V_238 ; V_20 ++ )
F_15 ( V_222 [ V_20 ] ) ;
F_15 ( V_222 ) ;
}
F_15 ( V_237 ) ;
F_15 ( V_236 ) ;
return V_239 ;
}
static int F_97 ( struct V_142 * V_143 , T_14 V_144 ,
unsigned int V_153 , unsigned long V_154 )
{
struct V_138 * V_139 = V_143 -> V_145 ;
T_1 * V_1 = F_86 ( V_139 ) ;
void T_9 * V_193 = ( void T_9 * ) V_154 ;
F_89 ( & V_1 -> V_24 -> V_25 , L_29 ,
V_153 , V_154 ) ;
switch ( V_153 ) {
case V_155 :
return F_109 ( V_1 , V_193 ) ;
case V_156 :
return F_111 ( V_1 , V_193 ) ;
case V_157 :
return F_113 ( V_1 , V_193 ) ;
case V_158 :
return F_116 ( V_1 , V_193 ) ;
case V_159 :
return F_118 ( V_1 , V_193 ) ;
case V_160 :
return F_120 ( V_1 , V_193 ) ;
case V_161 :
return F_121 ( V_1 , V_193 ) ;
case V_162 :
return F_122 ( V_1 , V_193 ) ;
case V_163 :
return F_123 ( V_1 , V_193 ) ;
case V_165 :
case V_167 :
case V_164 :
return F_130 ( V_1 , 0 , 1 ) ;
case V_169 :
return F_124 ( V_1 , V_139 , V_193 ) ;
case V_182 :
return F_125 ( V_1 , V_193 ) ;
case V_184 :
return F_128 ( V_1 , V_193 ) ;
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
return F_131 ( V_143 , V_144 , V_153 , V_193 ) ;
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
default:
return - V_112 ;
}
}
static void F_132 ( T_1 * V_1 )
{
int V_260 = V_1 -> V_261 ;
int V_20 ;
if ( ( F_76 ( V_1 -> V_125 , V_1 -> V_19 ) ) == V_1 -> V_19 )
return;
for ( V_20 = 0 ; V_20 < V_1 -> V_65 + 1 ; V_20 ++ ) {
int V_262 = ( V_260 + V_20 ) % ( V_1 -> V_65 + 1 ) ;
if ( ! V_1 -> V_64 [ V_262 ] )
continue;
if ( ! ( V_1 -> V_64 [ V_262 ] -> V_140 ) ||
! ( V_1 -> V_64 [ V_262 ] -> V_66 ) )
continue;
F_133 ( V_1 -> V_138 [ V_262 ] -> V_140 ) ;
if ( ( F_76 ( V_1 -> V_125 , V_1 -> V_19 ) ) == V_1 -> V_19 ) {
if ( V_262 == V_260 ) {
V_1 -> V_261 =
( V_260 + 1 ) % ( V_1 -> V_65 + 1 ) ;
break;
} else {
V_1 -> V_261 = V_262 ;
break;
}
}
}
}
static void F_134 ( struct V_263 * V_264 )
{
T_2 * V_2 = V_264 -> V_265 ;
T_1 * V_1 = V_266 [ V_2 -> V_63 ] ;
T_3 * V_267 = V_2 -> V_31 ;
T_4 V_28 ;
unsigned long V_13 ;
int V_20 , V_268 ;
int V_269 = 0 ;
if ( V_2 -> V_178 . Type . V_225 == V_235 )
V_268 = V_270 ;
else
V_268 = V_38 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_7 . V_8 ; V_20 ++ ) {
if ( V_267 [ V_269 ] . V_41 == V_42 ) {
F_19 ( V_1 , V_2 ) ;
V_267 = V_1 -> V_18 [ V_2 -> V_133 ] ;
V_269 = 0 ;
}
V_28 . V_32 . V_33 = V_267 [ V_269 ] . V_34 . V_33 ;
V_28 . V_32 . V_35 = V_267 [ V_269 ] . V_34 . V_35 ;
F_135 ( V_1 -> V_24 , V_28 . V_36 , V_267 [ V_269 ] . V_37 ,
V_268 ) ;
++ V_269 ;
}
F_89 ( & V_1 -> V_24 -> V_25 , L_30 , V_264 ) ;
if ( F_136 ( V_264 ) )
F_137 ( V_264 ) -> V_271 = V_2 -> V_128 -> V_272 ;
F_138 ( V_264 , ( V_264 -> V_273 == 0 ) ? 0 : - V_274 ) ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
F_82 ( V_1 , V_2 ) ;
F_132 ( V_1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
}
static inline void F_139 ( T_1 * V_1 ,
unsigned char V_275 [] , T_28 V_276 )
{
memcpy ( V_275 , V_1 -> V_64 [ V_276 ] -> V_113 ,
sizeof( V_1 -> V_64 [ V_276 ] -> V_113 ) ) ;
}
static void F_140 ( T_1 * V_1 , int V_277 ,
char * V_105 , char * V_107 , char * V_109 )
{
int V_278 ;
T_29 * V_279 ;
unsigned char V_275 [ 8 ] ;
* V_105 = '\0' ;
* V_107 = '\0' ;
* V_109 = '\0' ;
V_279 = F_129 ( sizeof( T_29 ) , V_23 ) ;
if ( ! V_279 )
return;
F_139 ( V_1 , V_275 , V_277 ) ;
V_278 = F_141 ( V_1 , V_280 , V_279 , sizeof( * V_279 ) , 0 ,
V_275 , V_281 ) ;
if ( V_278 == V_282 ) {
memcpy ( V_105 , & V_279 -> V_283 [ 8 ] , V_106 ) ;
V_105 [ V_106 ] = '\0' ;
memcpy ( V_107 , & V_279 -> V_283 [ 16 ] , V_108 ) ;
V_107 [ V_108 ] = '\0' ;
memcpy ( V_109 , & V_279 -> V_283 [ 32 ] , V_110 ) ;
V_109 [ V_110 ] = '\0' ;
}
F_15 ( V_279 ) ;
return;
}
static void F_142 ( T_1 * V_1 , int V_277 ,
unsigned char * V_104 , int V_284 )
{
#define F_143 64
int V_278 ;
unsigned char * V_77 ;
unsigned char V_275 [ 8 ] ;
if ( V_284 > 16 )
V_284 = 16 ;
memset ( V_104 , 0xff , V_284 ) ;
V_77 = F_129 ( F_143 , V_23 ) ;
if ( ! V_77 )
return;
memset ( V_104 , 0 , V_284 ) ;
F_139 ( V_1 , V_275 , V_277 ) ;
V_278 = F_141 ( V_1 , V_280 , V_77 ,
F_143 , 0x83 , V_275 , V_281 ) ;
if ( V_278 == V_282 )
memcpy ( V_104 , & V_77 [ 8 ] , V_284 ) ;
F_15 ( V_77 ) ;
return;
}
static int F_144 ( T_1 * V_1 , struct V_138 * V_139 ,
int V_119 )
{
V_139 -> V_140 = F_145 ( V_23 ) ;
if ( ! V_139 -> V_140 )
goto V_285;
V_139 -> V_140 -> V_286 = sizeof( struct V_287 ) ;
V_139 -> V_140 -> V_288 = V_289 ;
V_139 -> V_140 -> V_290 = & V_1 -> V_14 ;
if ( F_146 ( V_139 -> V_140 ) < 0 )
goto V_291;
sprintf ( V_139 -> V_146 , L_31 , V_1 -> V_63 , V_119 ) ;
V_139 -> V_292 = V_1 -> V_292 ;
V_139 -> V_293 = V_119 << V_294 ;
V_139 -> V_295 = & V_296 ;
if ( F_73 ( V_1 , V_119 ) )
goto V_291;
V_139 -> V_76 = V_1 -> V_64 [ V_119 ] ;
F_147 ( V_139 -> V_140 , V_1 -> V_24 -> V_297 ) ;
F_148 ( V_139 -> V_140 , V_1 -> V_298 ) ;
F_149 ( V_139 -> V_140 , V_1 -> V_299 ) ;
F_150 ( V_139 -> V_140 , F_134 ) ;
V_139 -> V_140 -> V_141 = V_1 ;
F_151 ( V_139 -> V_140 ,
V_1 -> V_64 [ V_119 ] -> V_300 ) ;
F_152 () ;
V_1 -> V_64 [ V_119 ] -> V_140 = V_139 -> V_140 ;
F_153 ( & V_1 -> V_64 [ V_119 ] -> V_25 , V_139 ) ;
return 0 ;
V_291:
F_154 ( V_139 -> V_140 ) ;
V_139 -> V_140 = NULL ;
V_285:
return - 1 ;
}
static void F_155 ( T_1 * V_1 , int V_119 ,
int V_301 , int V_302 )
{
struct V_138 * V_139 ;
T_29 * V_303 = NULL ;
unsigned int V_300 ;
T_6 V_304 ;
unsigned long V_13 = 0 ;
int V_74 = 0 ;
T_7 * V_305 ;
V_303 = F_17 ( sizeof( T_29 ) , V_23 ) ;
V_305 = F_129 ( sizeof( * V_305 ) , V_23 ) ;
if ( V_303 == NULL || V_305 == NULL )
goto V_306;
if ( V_1 -> V_307 == V_308 ) {
F_156 ( V_1 , V_119 ,
& V_304 , & V_300 ) ;
} else {
F_157 ( V_1 , V_119 , & V_304 , & V_300 ) ;
if ( V_304 == 0xFFFFFFFFULL ) {
F_156 ( V_1 , V_119 ,
& V_304 , & V_300 ) ;
V_1 -> V_307 = V_308 ;
V_1 -> V_309 = V_310 ;
} else {
V_1 -> V_307 = V_311 ;
V_1 -> V_309 = V_312 ;
}
}
F_158 ( V_1 , V_119 , V_304 , V_300 ,
V_303 , V_305 ) ;
V_305 -> V_300 = V_300 ;
V_305 -> V_67 = V_304 + 1 ;
F_140 ( V_1 , V_119 , V_305 -> V_105 ,
V_305 -> V_107 , V_305 -> V_109 ) ;
F_142 ( V_1 , V_119 , V_305 -> V_104 ,
sizeof( V_305 -> V_104 ) ) ;
memcpy ( V_305 -> V_113 , V_1 -> V_64 [ V_119 ] -> V_113 ,
sizeof( V_305 -> V_113 ) ) ;
if ( V_1 -> V_64 [ V_119 ] -> V_69 != - 1 &&
( ( memcmp ( V_305 -> V_104 ,
V_1 -> V_64 [ V_119 ] -> V_104 , 16 ) == 0 ) &&
V_305 -> V_300 == V_1 -> V_64 [ V_119 ] -> V_300 &&
V_305 -> V_67 == V_1 -> V_64 [ V_119 ] -> V_67 &&
V_305 -> V_66 == V_1 -> V_64 [ V_119 ] -> V_66 &&
V_305 -> V_188 == V_1 -> V_64 [ V_119 ] -> V_188 &&
V_305 -> V_187 == V_1 -> V_64 [ V_119 ] -> V_187 ) )
goto V_313;
if ( V_1 -> V_64 [ V_119 ] -> V_69 != - 1 && V_119 != 0 ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_32 , V_119 ) ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_1 -> V_64 [ V_119 ] -> V_58 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
V_74 = F_159 ( V_1 , V_119 , 0 , V_302 ) ;
}
if ( V_74 )
goto V_313;
if ( V_1 -> V_64 [ V_119 ] == NULL ) {
V_305 -> V_120 = 0 ;
V_1 -> V_64 [ V_119 ] = V_305 ;
V_305 = NULL ;
} else {
V_1 -> V_64 [ V_119 ] -> V_300 = V_305 -> V_300 ;
V_1 -> V_64 [ V_119 ] -> V_67 = V_305 -> V_67 ;
V_1 -> V_64 [ V_119 ] -> V_66 = V_305 -> V_66 ;
V_1 -> V_64 [ V_119 ] -> V_188 = V_305 -> V_188 ;
V_1 -> V_64 [ V_119 ] -> V_187 = V_305 -> V_187 ;
V_1 -> V_64 [ V_119 ] -> V_69 = V_305 -> V_69 ;
memcpy ( V_1 -> V_64 [ V_119 ] -> V_104 , V_305 -> V_104 , 16 ) ;
memcpy ( V_1 -> V_64 [ V_119 ] -> V_105 , V_305 -> V_105 ,
V_106 + 1 ) ;
memcpy ( V_1 -> V_64 [ V_119 ] -> V_107 , V_305 -> V_107 , V_108 + 1 ) ;
memcpy ( V_1 -> V_64 [ V_119 ] -> V_109 , V_305 -> V_109 , V_110 + 1 ) ;
}
++ V_1 -> V_53 ;
V_139 = V_1 -> V_138 [ V_119 ] ;
F_160 ( V_139 , V_1 -> V_64 [ V_119 ] -> V_67 ) ;
if ( V_119 || V_301 ) {
if ( F_144 ( V_1 , V_139 , V_119 ) != 0 ) {
F_161 ( V_1 , V_119 ) ;
F_162 ( V_1 , V_119 ) ;
F_24 ( & V_1 -> V_24 -> V_25 , L_33 ,
V_119 ) ;
-- V_1 -> V_53 ;
}
}
V_313:
F_15 ( V_303 ) ;
F_15 ( V_305 ) ;
return;
V_306:
F_18 ( & V_1 -> V_24 -> V_25 , L_34 ) ;
goto V_313;
}
static int F_163 ( T_1 * V_1 , int V_314 )
{
int V_20 ;
T_7 * V_64 ;
for ( V_20 = 0 ; V_20 < V_315 ; V_20 ++ ) {
if ( V_1 -> V_64 [ V_20 ] && V_20 != 0 )
continue;
if ( V_20 == 0 && V_1 -> V_64 [ V_20 ] && V_1 -> V_64 [ V_20 ] -> V_69 != - 1 )
continue;
if ( V_20 > V_1 -> V_65 && ! V_314 )
V_1 -> V_65 = V_20 ;
if ( V_20 == 0 && V_1 -> V_64 [ V_20 ] != NULL )
return V_20 ;
V_64 = F_129 ( sizeof( * V_64 ) , V_23 ) ;
if ( ! V_64 )
return - 1 ;
V_64 -> V_69 = - 1 ;
V_1 -> V_64 [ V_20 ] = V_64 ;
return V_20 ;
}
return - 1 ;
}
static void F_162 ( T_1 * V_1 , int V_119 )
{
F_15 ( V_1 -> V_64 [ V_119 ] ) ;
V_1 -> V_64 [ V_119 ] = NULL ;
}
static void F_161 ( T_1 * V_1 , int V_119 )
{
F_164 ( V_1 -> V_138 [ V_119 ] ) ;
V_1 -> V_138 [ V_119 ] = NULL ;
}
static int F_165 ( T_1 * V_1 , unsigned char V_111 [] ,
int V_314 )
{
int V_119 ;
V_119 = F_163 ( V_1 , V_314 ) ;
if ( V_119 == - 1 )
return - 1 ;
if ( ! V_1 -> V_138 [ V_119 ] ) {
V_1 -> V_138 [ V_119 ] =
F_166 ( 1 << V_294 ) ;
if ( ! V_1 -> V_138 [ V_119 ] ) {
F_18 ( & V_1 -> V_24 -> V_25 ,
L_35 ,
V_119 ) ;
goto V_316;
}
}
memcpy ( V_1 -> V_64 [ V_119 ] -> V_113 , V_111 ,
sizeof( V_1 -> V_64 [ V_119 ] -> V_113 ) ) ;
if ( F_73 ( V_1 , V_119 ) )
goto V_317;
V_1 -> V_64 [ V_119 ] -> V_58 = 0 ;
F_152 () ;
return V_119 ;
V_317:
F_161 ( V_1 , V_119 ) ;
V_316:
F_162 ( V_1 , V_119 ) ;
return - 1 ;
}
static void F_167 ( T_1 * V_1 )
{
struct V_138 * V_139 ;
int V_119 ;
if ( V_1 -> V_138 [ 0 ] != NULL )
return;
V_119 = F_165 ( V_1 , V_149 , 1 ) ;
if ( V_119 == - 1 )
goto error;
V_1 -> V_64 [ V_119 ] -> V_300 = 512 ;
V_1 -> V_64 [ V_119 ] -> V_67 = 0 ;
V_1 -> V_64 [ V_119 ] -> V_66 = 0 ;
V_1 -> V_64 [ V_119 ] -> V_188 = 0 ;
V_1 -> V_64 [ V_119 ] -> V_187 = 0 ;
V_1 -> V_64 [ V_119 ] -> V_69 = - 1 ;
memset ( V_1 -> V_64 [ V_119 ] -> V_104 , 0 , 16 ) ;
V_139 = V_1 -> V_138 [ V_119 ] ;
if ( F_144 ( V_1 , V_139 , V_119 ) == 0 )
return;
F_161 ( V_1 , V_119 ) ;
F_162 ( V_1 , V_119 ) ;
error:
F_24 ( & V_1 -> V_24 -> V_25 , L_36 ) ;
return;
}
static int F_130 ( T_1 * V_1 , int V_301 ,
int V_302 )
{
int V_53 ;
T_30 * V_318 = NULL ;
int V_319 ;
int V_320 = 0 ;
int V_20 ;
int V_321 ;
int V_119 = 0 ;
unsigned char V_111 [ 8 ] = V_149 ;
unsigned long V_13 ;
if ( ! F_91 ( V_224 ) )
return - V_151 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
if ( V_1 -> V_58 ) {
F_13 ( & V_1 -> V_14 , V_13 ) ;
return - V_59 ;
}
V_1 -> V_58 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
V_318 = F_129 ( sizeof( T_30 ) , V_23 ) ;
if ( V_318 == NULL )
goto V_306;
V_319 = F_141 ( V_1 , V_322 , V_318 ,
sizeof( T_30 ) ,
0 , V_149 , V_281 ) ;
if ( V_319 == V_282 )
V_320 = F_168 ( * ( V_323 * ) V_318 -> V_324 ) ;
else {
F_24 ( & V_1 -> V_24 -> V_25 ,
L_37 ) ;
V_320 = 0 ;
goto V_313;
}
V_53 = V_320 / 8 ;
if ( V_53 > V_315 ) {
V_53 = V_315 ;
F_24 ( & V_1 -> V_24 -> V_25 , L_38
L_39
L_40 ) ;
}
if ( V_53 == 0 )
F_167 ( V_1 ) ;
for ( V_20 = 0 ; V_20 <= V_1 -> V_65 ; V_20 ++ ) {
int V_22 ;
V_321 = 0 ;
if ( V_1 -> V_64 [ V_20 ] == NULL )
continue;
for ( V_22 = 0 ; V_22 < V_53 ; V_22 ++ ) {
memcpy ( V_111 , & V_318 -> V_231 [ V_22 ] [ 0 ] , sizeof( V_111 ) ) ;
if ( memcmp ( V_1 -> V_64 [ V_20 ] -> V_113 , V_111 ,
sizeof( V_111 ) ) == 0 ) {
V_321 = 1 ;
break;
}
}
if ( ! V_321 ) {
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_1 -> V_64 [ V_20 ] -> V_58 = 1 ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
V_319 = F_159 ( V_1 , V_20 , 1 , V_302 ) ;
if ( V_1 -> V_64 [ V_20 ] != NULL )
V_1 -> V_64 [ V_20 ] -> V_58 = 0 ;
}
}
for ( V_20 = 0 ; V_20 < V_53 ; V_20 ++ ) {
int V_22 ;
V_321 = 0 ;
memcpy ( V_111 , & V_318 -> V_231 [ V_20 ] [ 0 ] , sizeof( V_111 ) ) ;
for ( V_22 = 0 ; V_22 <= V_1 -> V_65 ; V_22 ++ ) {
if ( V_1 -> V_64 [ V_22 ] != NULL &&
memcmp ( V_1 -> V_64 [ V_22 ] -> V_113 , V_111 ,
sizeof( V_1 -> V_64 [ V_22 ] -> V_113 ) ) == 0 ) {
V_119 = V_22 ;
V_321 = 1 ;
break;
}
}
if ( ! V_321 ) {
V_119 = F_165 ( V_1 , V_111 , 0 ) ;
if ( V_119 == - 1 )
goto V_313;
}
F_155 ( V_1 , V_119 , V_301 , V_302 ) ;
}
V_313:
F_15 ( V_318 ) ;
V_1 -> V_58 = 0 ;
return - 1 ;
V_306:
F_18 ( & V_1 -> V_24 -> V_25 , L_34 ) ;
V_1 -> V_58 = 0 ;
goto V_313;
}
static void F_169 ( T_7 * V_325 )
{
V_325 -> V_67 = 0 ;
V_325 -> V_300 = 0 ;
V_325 -> V_66 = 0 ;
V_325 -> V_188 = 0 ;
V_325 -> V_187 = 0 ;
V_325 -> V_69 = - 1 ;
memset ( V_325 -> V_104 , 0 , sizeof( V_325 -> V_104 ) ) ;
memset ( V_325 -> V_107 , 0 , sizeof( V_325 -> V_107 ) ) ;
memset ( V_325 -> V_109 , 0 , sizeof( V_325 -> V_109 ) ) ;
memset ( V_325 -> V_105 , 0 , sizeof( V_325 -> V_105 ) ) ;
}
static int F_159 ( T_1 * V_1 , int V_119 ,
int V_326 , int V_302 )
{
int V_20 ;
struct V_138 * V_139 ;
T_7 * V_64 ;
int V_327 ;
if ( ! F_91 ( V_224 ) )
return - V_151 ;
V_64 = V_1 -> V_64 [ V_119 ] ;
V_139 = V_1 -> V_138 [ V_119 ] ;
if ( V_326 || ( V_1 -> V_138 [ 0 ] == V_139 ) ) {
if ( V_64 -> V_115 > V_302 )
return - V_59 ;
} else if ( V_64 -> V_115 > 0 )
return - V_59 ;
V_327 = ( V_64 == V_1 -> V_64 [ V_1 -> V_65 ] ) ;
if ( V_1 -> V_138 [ 0 ] != V_139 ) {
struct V_328 * V_329 = V_139 -> V_140 ;
if ( V_139 -> V_13 & V_330 ) {
F_74 ( V_1 , V_119 , 0 ) ;
F_170 ( V_139 ) ;
}
if ( V_329 )
F_154 ( V_329 ) ;
if ( V_326 ) {
for ( V_20 = 0 ; V_20 < V_315 ; V_20 ++ ) {
if ( V_1 -> V_138 [ V_20 ] == V_139 ) {
V_1 -> V_138 [ V_20 ] = NULL ;
break;
}
}
F_164 ( V_139 ) ;
}
} else {
F_160 ( V_139 , 0 ) ;
F_169 ( V_64 ) ;
}
-- V_1 -> V_53 ;
if ( V_326 && V_327 ) {
int V_331 = - 1 ;
for ( V_20 = 0 ; V_20 <= V_1 -> V_65 ; V_20 ++ ) {
if ( V_1 -> V_64 [ V_20 ] && V_1 -> V_64 [ V_20 ] -> V_66 )
V_331 = V_20 ;
}
V_1 -> V_65 = V_331 ;
}
return 0 ;
}
static int F_171 ( T_1 * V_1 , T_2 * V_2 , T_12 V_153 , void * V_222 ,
T_10 V_332 , T_12 V_333 , unsigned char * V_275 ,
int V_11 )
{
T_4 V_334 ;
int V_239 = V_282 ;
V_2 -> V_11 = V_229 ;
V_2 -> V_7 . V_230 = 0 ;
if ( V_222 != NULL ) {
V_2 -> V_7 . V_8 = 1 ;
V_2 -> V_7 . V_29 = 1 ;
} else {
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_7 . V_29 = 0 ;
}
V_2 -> V_7 . V_232 . V_33 = V_2 -> V_5 ;
memcpy ( V_2 -> V_7 . V_231 . V_335 , V_275 , 8 ) ;
V_2 -> V_178 . Type . Type = V_11 ;
if ( V_11 == V_281 ) {
switch ( V_153 ) {
case V_280 :
if ( V_333 != 0 ) {
V_2 -> V_178 . V_336 [ 1 ] = 0x01 ;
V_2 -> V_178 . V_336 [ 2 ] = V_333 ;
}
V_2 -> V_178 . V_337 = 6 ;
V_2 -> V_178 . Type . V_338 = V_339 ;
V_2 -> V_178 . Type . V_225 = V_235 ;
V_2 -> V_178 . V_340 = 0 ;
V_2 -> V_178 . V_336 [ 0 ] = V_280 ;
V_2 -> V_178 . V_336 [ 4 ] = V_332 & 0xFF ;
break;
case V_322 :
case V_341 :
V_2 -> V_178 . V_337 = 12 ;
V_2 -> V_178 . Type . V_338 = V_339 ;
V_2 -> V_178 . Type . V_225 = V_235 ;
V_2 -> V_178 . V_340 = 0 ;
V_2 -> V_178 . V_336 [ 0 ] = V_153 ;
V_2 -> V_178 . V_336 [ 6 ] = ( V_332 >> 24 ) & 0xFF ;
V_2 -> V_178 . V_336 [ 7 ] = ( V_332 >> 16 ) & 0xFF ;
V_2 -> V_178 . V_336 [ 8 ] = ( V_332 >> 8 ) & 0xFF ;
V_2 -> V_178 . V_336 [ 9 ] = V_332 & 0xFF ;
break;
case V_342 :
V_2 -> V_178 . V_337 = 10 ;
V_2 -> V_178 . Type . V_338 = V_339 ;
V_2 -> V_178 . Type . V_225 = V_235 ;
V_2 -> V_178 . V_340 = 0 ;
V_2 -> V_178 . V_336 [ 0 ] = V_153 ;
break;
case V_343 :
V_2 -> V_178 . V_337 = 16 ;
V_2 -> V_178 . Type . V_338 = V_339 ;
V_2 -> V_178 . Type . V_225 = V_235 ;
V_2 -> V_178 . V_340 = 0 ;
V_2 -> V_178 . V_336 [ 0 ] = V_153 ;
V_2 -> V_178 . V_336 [ 1 ] = 0x10 ;
V_2 -> V_178 . V_336 [ 10 ] = ( V_332 >> 24 ) & 0xFF ;
V_2 -> V_178 . V_336 [ 11 ] = ( V_332 >> 16 ) & 0xFF ;
V_2 -> V_178 . V_336 [ 12 ] = ( V_332 >> 8 ) & 0xFF ;
V_2 -> V_178 . V_336 [ 13 ] = V_332 & 0xFF ;
V_2 -> V_178 . V_340 = 0 ;
V_2 -> V_178 . V_336 [ 0 ] = V_153 ;
break;
case V_344 :
V_2 -> V_178 . V_337 = 12 ;
V_2 -> V_178 . Type . V_338 = V_339 ;
V_2 -> V_178 . Type . V_225 = V_227 ;
V_2 -> V_178 . V_340 = 0 ;
V_2 -> V_178 . V_336 [ 0 ] = V_345 ;
V_2 -> V_178 . V_336 [ 6 ] = V_346 ;
V_2 -> V_178 . V_336 [ 7 ] = ( V_332 >> 8 ) & 0xFF ;
V_2 -> V_178 . V_336 [ 8 ] = V_332 & 0xFF ;
break;
case V_347 :
V_2 -> V_178 . V_337 = 6 ;
V_2 -> V_178 . Type . V_338 = V_339 ;
V_2 -> V_178 . Type . V_225 = V_226 ;
V_2 -> V_178 . V_340 = 0 ;
break;
default:
F_24 ( & V_1 -> V_24 -> V_25 , L_41 , V_153 ) ;
return V_348 ;
}
} else if ( V_11 == V_349 ) {
switch ( V_153 ) {
case V_350 :
V_2 -> V_178 . V_337 = 12 ;
V_2 -> V_178 . Type . V_338 = V_339 ;
V_2 -> V_178 . Type . V_225 = V_227 ;
V_2 -> V_178 . V_340 = 0 ;
V_2 -> V_178 . V_336 [ 0 ] = V_153 ;
V_2 -> V_178 . V_336 [ 1 ] = 0 ;
memcpy ( & V_2 -> V_178 . V_336 [ 4 ] , V_222 , 8 ) ;
break;
case V_351 :
V_2 -> V_178 . V_337 = 16 ;
V_2 -> V_178 . Type . V_338 = V_339 ;
V_2 -> V_178 . Type . V_225 = V_226 ;
V_2 -> V_178 . V_340 = 0 ;
memset ( & V_2 -> V_178 . V_336 [ 0 ] , 0 , sizeof( V_2 -> V_178 . V_336 ) ) ;
V_2 -> V_178 . V_336 [ 0 ] = V_153 ;
V_2 -> V_178 . V_336 [ 1 ] = V_352 ;
break;
case V_353 :
V_2 -> V_178 . V_337 = 1 ;
V_2 -> V_178 . Type . V_338 = V_339 ;
V_2 -> V_178 . Type . V_225 = V_227 ;
V_2 -> V_178 . V_340 = 0 ;
V_2 -> V_178 . V_336 [ 0 ] = V_153 ;
break;
default:
F_24 ( & V_1 -> V_24 -> V_25 ,
L_42 , V_153 ) ;
return V_348 ;
}
} else {
F_24 ( & V_1 -> V_24 -> V_25 , L_43 , V_11 ) ;
return V_348 ;
}
if ( V_332 > 0 ) {
V_334 . V_36 = ( V_135 ) F_22 ( V_1 -> V_24 ,
V_222 , V_332 ,
V_233 ) ;
V_2 -> V_31 [ 0 ] . V_34 . V_33 = V_334 . V_32 . V_33 ;
V_2 -> V_31 [ 0 ] . V_34 . V_35 = V_334 . V_32 . V_35 ;
V_2 -> V_31 [ 0 ] . V_37 = V_332 ;
V_2 -> V_31 [ 0 ] . V_41 = 0 ;
}
return V_239 ;
}
static int F_172 ( T_1 * V_1 , unsigned char * V_275 ,
T_31 V_354 )
{
T_2 * V_2 ;
int V_355 ;
V_2 = F_75 ( V_1 ) ;
if ( ! V_2 )
return - V_228 ;
V_355 = F_171 ( V_1 , V_2 , V_351 , NULL , 0 , 0 ,
V_149 , V_349 ) ;
V_2 -> V_178 . V_336 [ 1 ] = V_354 ;
if ( V_355 != V_282 ) {
F_84 ( V_1 , V_2 ) ;
return V_355 ;
}
V_2 -> V_234 = NULL ;
F_10 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_173 ( T_1 * V_1 , T_2 * V_2 )
{
switch ( V_2 -> V_128 -> V_191 ) {
case V_356 :
return V_282 ;
case V_192 :
switch ( 0xf & V_2 -> V_128 -> V_357 [ 2 ] ) {
case 0 : return V_282 ;
case 1 : return V_282 ;
default:
if ( F_108 ( V_1 , V_2 ) )
return V_358 ;
F_24 ( & V_1 -> V_24 -> V_25 , L_44
L_45 ,
V_2 -> V_178 . V_336 [ 0 ] , V_2 -> V_128 -> V_357 [ 2 ] ) ;
}
break;
default:
F_24 ( & V_1 -> V_24 -> V_25 , L_46
L_47 ,
V_2 -> V_178 . V_336 [ 0 ] , V_2 -> V_128 -> V_191 ) ;
break;
}
return V_348 ;
}
static int F_174 ( T_1 * V_1 , T_2 * V_2 )
{
int V_355 = V_282 ;
if ( V_2 -> V_128 -> V_189 == V_359 )
return V_282 ;
switch ( V_2 -> V_128 -> V_189 ) {
case V_190 :
V_355 = F_173 ( V_1 , V_2 ) ;
break;
case V_360 :
case V_361 :
break;
case V_362 :
F_24 ( & V_1 -> V_24 -> V_25 , L_48
L_49 , V_2 -> V_178 . V_336 [ 0 ] ) ;
V_355 = V_348 ;
break;
case V_363 :
F_24 ( & V_1 -> V_24 -> V_25 , L_50
L_51 , V_2 -> V_178 . V_336 [ 0 ] ) ;
V_355 = V_348 ;
break;
case V_364 :
F_24 ( & V_1 -> V_24 -> V_25 , L_52
L_53 , V_2 -> V_178 . V_336 [ 0 ] ) ;
V_355 = V_348 ;
break;
case V_365 :
F_24 ( & V_1 -> V_24 -> V_25 , L_52
L_54 , V_2 -> V_178 . V_336 [ 0 ] ) ;
V_355 = V_348 ;
break;
case V_366 :
F_24 ( & V_1 -> V_24 -> V_25 , L_55
L_56 , V_2 -> V_178 . V_336 [ 0 ] ) ;
V_355 = V_348 ;
break;
case V_367 :
F_24 ( & V_1 -> V_24 -> V_25 , L_57
L_58 , V_2 -> V_178 . V_336 [ 0 ] ) ;
V_355 = V_348 ;
break;
case V_368 :
F_24 ( & V_1 -> V_24 -> V_25 , L_59 ,
V_2 -> V_178 . V_336 [ 0 ] ) ;
V_355 = V_358 ;
break;
case V_369 :
F_24 ( & V_1 -> V_24 -> V_25 , L_60 ) ;
V_355 = V_348 ;
break;
default:
F_24 ( & V_1 -> V_24 -> V_25 , L_61
L_62 , V_2 -> V_178 . V_336 [ 0 ] ,
V_2 -> V_128 -> V_189 ) ;
V_355 = V_348 ;
}
return V_355 ;
}
static int F_175 ( T_1 * V_1 , T_2 * V_2 ,
int V_370 )
{
F_126 ( V_223 ) ;
T_4 V_334 ;
int V_355 = V_282 ;
V_371:
V_2 -> V_234 = & V_223 ;
F_10 ( V_1 , V_2 ) ;
F_127 ( & V_223 ) ;
if ( V_2 -> V_128 -> V_189 == 0 || ! V_370 )
goto V_372;
V_355 = F_174 ( V_1 , V_2 ) ;
if ( V_355 == V_358 &&
V_2 -> V_373 < V_374 ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_63 ,
V_2 -> V_178 . V_336 [ 0 ] ) ;
V_2 -> V_373 ++ ;
memset ( V_2 -> V_128 , 0 , sizeof( V_130 ) ) ;
V_355 = V_282 ;
F_176 ( & V_223 ) ;
goto V_371;
}
V_372:
V_334 . V_32 . V_33 = V_2 -> V_31 [ 0 ] . V_34 . V_33 ;
V_334 . V_32 . V_35 = V_2 -> V_31 [ 0 ] . V_34 . V_35 ;
F_20 ( V_1 -> V_24 , ( T_13 ) V_334 . V_36 ,
V_2 -> V_31 [ 0 ] . V_37 , V_233 ) ;
return V_355 ;
}
static int F_141 ( T_1 * V_1 , T_12 V_153 , void * V_222 , T_10 V_332 ,
T_12 V_333 , unsigned char V_275 [] ,
int V_11 )
{
T_2 * V_2 ;
int V_355 ;
V_2 = F_79 ( V_1 ) ;
if ( ! V_2 )
return - V_228 ;
V_355 = F_171 ( V_1 , V_2 , V_153 , V_222 , V_332 , V_333 ,
V_275 , V_11 ) ;
if ( V_355 == V_282 )
V_355 = F_175 ( V_1 , V_2 , 1 ) ;
F_84 ( V_1 , V_2 ) ;
return V_355 ;
}
static void F_158 ( T_1 * V_1 , int V_277 ,
T_6 V_304 ,
unsigned int V_300 ,
T_29 * V_303 ,
T_7 * V_64 )
{
int V_319 ;
unsigned long V_375 ;
unsigned char V_275 [ 8 ] ;
memset ( V_303 , 0 , sizeof( T_29 ) ) ;
F_139 ( V_1 , V_275 , V_277 ) ;
V_319 = F_141 ( V_1 , V_280 , V_303 ,
sizeof( * V_303 ) , 0xC1 , V_275 , V_281 ) ;
if ( V_319 == V_282 ) {
if ( V_303 -> V_283 [ 8 ] == 0xFF ) {
F_24 ( & V_1 -> V_24 -> V_25 ,
L_64
L_65 ) ;
V_64 -> V_66 = 255 ;
V_64 -> V_188 = 32 ;
V_64 -> V_187 = V_304 + 1 ;
V_64 -> V_69 = V_70 ;
} else {
V_64 -> V_66 = V_303 -> V_283 [ 6 ] ;
V_64 -> V_188 = V_303 -> V_283 [ 7 ] ;
V_64 -> V_187 = ( V_303 -> V_283 [ 4 ] & 0xff ) << 8 ;
V_64 -> V_187 += V_303 -> V_283 [ 5 ] ;
V_64 -> V_69 = V_303 -> V_283 [ 8 ] ;
}
V_64 -> V_300 = V_300 ;
V_64 -> V_67 = V_304 + 1 ;
V_375 = V_64 -> V_66 * V_64 -> V_188 ;
if ( V_375 > 1 ) {
T_6 V_376 = V_304 + 1 ;
unsigned long V_377 = F_32 ( V_376 , V_375 ) ;
if ( V_377 )
V_376 ++ ;
V_64 -> V_187 = V_376 ;
}
} else {
F_24 ( & V_1 -> V_24 -> V_25 , L_66 ) ;
}
}
static void
F_157 ( T_1 * V_1 , int V_277 , T_6 * V_304 ,
unsigned int * V_300 )
{
T_32 * V_77 ;
int V_319 ;
unsigned char V_275 [ 8 ] ;
V_77 = F_129 ( sizeof( T_32 ) , V_23 ) ;
if ( ! V_77 ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_34 ) ;
return;
}
F_139 ( V_1 , V_275 , V_277 ) ;
V_319 = F_141 ( V_1 , V_342 , V_77 ,
sizeof( T_32 ) , 0 , V_275 , V_281 ) ;
if ( V_319 == V_282 ) {
* V_304 = F_168 ( * ( V_323 * ) V_77 -> V_304 ) ;
* V_300 = F_168 ( * ( V_323 * ) V_77 -> V_300 ) ;
} else {
F_24 ( & V_1 -> V_24 -> V_25 , L_67 ) ;
* V_304 = 0 ;
* V_300 = V_378 ;
}
F_15 ( V_77 ) ;
}
static void F_156 ( T_1 * V_1 , int V_277 ,
T_6 * V_304 , unsigned int * V_300 )
{
T_33 * V_77 ;
int V_319 ;
unsigned char V_275 [ 8 ] ;
V_77 = F_129 ( sizeof( T_33 ) , V_23 ) ;
if ( ! V_77 ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_34 ) ;
return;
}
F_139 ( V_1 , V_275 , V_277 ) ;
V_319 = F_141 ( V_1 , V_343 ,
V_77 , sizeof( T_33 ) ,
0 , V_275 , V_281 ) ;
if ( V_319 == V_282 ) {
* V_304 = F_177 ( * ( V_379 * ) V_77 -> V_304 ) ;
* V_300 = F_168 ( * ( V_323 * ) V_77 -> V_300 ) ;
} else {
F_24 ( & V_1 -> V_24 -> V_25 , L_67 ) ;
* V_304 = 0 ;
* V_300 = V_378 ;
}
F_178 ( & V_1 -> V_24 -> V_25 , L_68 ,
( unsigned long long ) * V_304 + 1 , * V_300 ) ;
F_15 ( V_77 ) ;
}
static int F_179 ( struct V_138 * V_139 )
{
T_1 * V_1 = F_86 ( V_139 ) ;
T_7 * V_64 = F_87 ( V_139 ) ;
int V_277 ;
int V_380 = 0 ;
unsigned int V_300 ;
T_6 V_304 ;
T_29 * V_303 = NULL ;
for ( V_277 = 0 ; V_277 <= V_1 -> V_65 ; V_277 ++ ) {
if ( ! V_1 -> V_64 [ V_277 ] )
continue;
if ( memcmp ( V_1 -> V_64 [ V_277 ] -> V_113 , V_64 -> V_113 ,
sizeof( V_64 -> V_113 ) ) == 0 ) {
V_380 = 1 ;
break;
}
}
if ( ! V_380 )
return 1 ;
V_303 = F_17 ( sizeof( T_29 ) , V_23 ) ;
if ( V_303 == NULL ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_34 ) ;
return 1 ;
}
if ( V_1 -> V_307 == V_311 ) {
F_157 ( V_1 , V_277 ,
& V_304 , & V_300 ) ;
} else {
F_156 ( V_1 , V_277 ,
& V_304 , & V_300 ) ;
}
F_158 ( V_1 , V_277 , V_304 , V_300 ,
V_303 , V_64 ) ;
F_151 ( V_64 -> V_140 , V_64 -> V_300 ) ;
F_160 ( V_139 , V_64 -> V_67 ) ;
F_15 ( V_303 ) ;
return 0 ;
}
static void T_34 * F_180 ( T_35 V_381 , T_35 V_332 )
{
T_35 V_382 = ( ( T_35 ) V_381 ) & V_383 ;
T_35 V_384 = ( ( T_35 ) V_381 ) - V_382 ;
void T_34 * V_385 = F_181 ( V_382 , V_384 + V_332 ) ;
return V_385 ? ( V_385 + V_384 ) : NULL ;
}
static void F_12 ( T_1 * V_1 )
{
T_2 * V_2 ;
while ( ! F_8 ( & V_1 -> V_15 ) ) {
V_2 = F_182 ( V_1 -> V_15 . V_386 , T_2 , V_10 ) ;
if ( ( V_1 -> V_387 . V_388 ( V_1 ) ) ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_69 ) ;
break;
}
F_6 ( V_2 ) ;
V_1 -> V_16 -- ;
V_1 -> V_387 . V_389 ( V_1 , V_2 ) ;
F_4 ( & V_1 -> V_390 , V_2 ) ;
}
}
static inline void F_183 ( T_1 * V_1 , T_2 * V_2 )
{
memset ( V_2 -> V_128 , 0 , sizeof( V_130 ) ) ;
F_4 ( & V_1 -> V_15 , V_2 ) ;
V_1 -> V_16 ++ ;
if ( V_1 -> V_16 > V_1 -> V_17 )
V_1 -> V_17 = V_1 -> V_16 ;
F_12 ( V_1 ) ;
}
static inline unsigned int F_184 ( unsigned int V_391 ,
unsigned int V_392 , unsigned int V_393 ,
unsigned int V_394 )
{
return ( V_391 & 0xff ) |
( ( V_392 & 0xff ) << 8 ) |
( ( V_393 & 0xff ) << 16 ) |
( ( V_394 & 0xff ) << 24 ) ;
}
static inline int F_185 ( T_1 * V_1 ,
T_2 * V_153 , int * V_395 )
{
unsigned char V_396 ;
unsigned char V_397 , V_392 , V_393 , V_394 ;
int V_398 ;
* V_395 = 0 ;
V_397 = V_153 -> V_128 -> V_191 ;
V_394 = V_399 ;
V_392 = V_153 -> V_128 -> V_189 ;
if ( F_136 ( V_153 -> V_264 ) )
V_393 = V_400 ;
else
V_393 = V_401 ;
V_398 = F_184 ( V_397 , V_392 ,
V_393 , V_394 ) ;
if ( V_153 -> V_128 -> V_191 != V_192 ) {
if ( ! F_136 ( V_153 -> V_264 ) )
F_24 ( & V_1 -> V_24 -> V_25 , L_70
L_71 ,
V_153 , V_153 -> V_128 -> V_191 ) ;
return V_398 ;
}
V_396 = 0xf & V_153 -> V_128 -> V_357 [ 2 ] ;
if ( ( ( V_396 == 0x0 ) || ( V_396 == 0x1 ) ) &&
! F_136 ( V_153 -> V_264 ) )
V_398 = 0 ;
if ( F_108 ( V_1 , V_153 ) ) {
* V_395 = ! F_136 ( V_153 -> V_264 ) ;
return 0 ;
}
if ( ! F_136 ( V_153 -> V_264 ) ) {
if ( V_398 != 0 )
F_24 ( & V_1 -> V_24 -> V_25 , L_72
L_73 , V_153 , V_396 ) ;
return V_398 ;
}
F_137 ( V_153 -> V_264 ) -> V_402 = V_153 -> V_128 -> V_403 ;
return V_398 ;
}
static inline void F_186 ( T_1 * V_1 , T_2 * V_153 ,
int V_404 )
{
int V_395 = 0 ;
struct V_263 * V_264 = V_153 -> V_264 ;
V_264 -> V_273 = 0 ;
if ( V_404 )
V_264 -> V_273 = F_184 ( 0 , 0 , 0 , V_405 ) ;
if ( V_153 -> V_128 -> V_189 == 0 )
goto V_406;
switch ( V_153 -> V_128 -> V_189 ) {
case V_190 :
V_264 -> V_273 = F_185 ( V_1 , V_153 , & V_395 ) ;
break;
case V_360 :
if ( ! F_136 ( V_153 -> V_264 ) ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_74
L_75
L_76 , V_153 ) ;
}
break;
case V_361 :
if ( ! F_136 ( V_153 -> V_264 ) )
F_24 ( & V_1 -> V_24 -> V_25 , L_77
L_78
L_76 , V_153 ) ;
break;
case V_362 :
F_24 ( & V_1 -> V_24 -> V_25 , L_79
L_49 , V_153 ) ;
V_264 -> V_273 = F_184 ( V_356 ,
V_153 -> V_128 -> V_189 , V_399 ,
F_136 ( V_153 -> V_264 ) ?
V_400 : V_407 ) ;
break;
case V_363 :
F_24 ( & V_1 -> V_24 -> V_25 , L_80
L_51 , V_153 ) ;
V_264 -> V_273 = F_184 ( V_356 ,
V_153 -> V_128 -> V_189 , V_399 ,
F_136 ( V_153 -> V_264 ) ?
V_400 : V_407 ) ;
break;
case V_364 :
F_24 ( & V_1 -> V_24 -> V_25 , L_81
L_53 , V_153 ) ;
V_264 -> V_273 = F_184 ( V_356 ,
V_153 -> V_128 -> V_189 , V_399 ,
F_136 ( V_153 -> V_264 ) ?
V_400 : V_407 ) ;
break;
case V_365 :
F_24 ( & V_1 -> V_24 -> V_25 , L_81
L_54 , V_153 ) ;
V_264 -> V_273 = F_184 ( V_356 ,
V_153 -> V_128 -> V_189 , V_399 ,
F_136 ( V_153 -> V_264 ) ?
V_400 : V_407 ) ;
break;
case V_366 :
F_24 ( & V_1 -> V_24 -> V_25 , L_82
L_56 , V_153 ) ;
V_264 -> V_273 = F_184 ( V_356 ,
V_153 -> V_128 -> V_189 , V_399 ,
F_136 ( V_153 -> V_264 ) ?
V_400 : V_408 ) ;
break;
case V_367 :
F_24 ( & V_1 -> V_24 -> V_25 , L_83
L_58 , V_153 ) ;
V_264 -> V_273 = F_184 ( V_356 ,
V_153 -> V_128 -> V_189 , V_399 ,
F_136 ( V_153 -> V_264 ) ?
V_400 : V_407 ) ;
break;
case V_368 :
F_24 ( & V_1 -> V_24 -> V_25 , L_84
L_85 , V_1 -> V_63 , V_153 ) ;
if ( V_153 -> V_373 < V_374 ) {
V_395 = 1 ;
F_24 ( & V_1 -> V_24 -> V_25 , L_86 , V_153 ) ;
V_153 -> V_373 ++ ;
} else
F_24 ( & V_1 -> V_24 -> V_25 ,
L_87 , V_153 ) ;
V_264 -> V_273 = F_184 ( V_356 ,
V_153 -> V_128 -> V_189 , V_399 ,
F_136 ( V_153 -> V_264 ) ?
V_400 : V_408 ) ;
break;
case V_409 :
F_24 ( & V_1 -> V_24 -> V_25 , L_88 , V_153 ) ;
V_264 -> V_273 = F_184 ( V_356 ,
V_153 -> V_128 -> V_189 , V_399 ,
F_136 ( V_153 -> V_264 ) ?
V_400 : V_407 ) ;
break;
case V_369 :
F_24 ( & V_1 -> V_24 -> V_25 , L_89 , V_153 ) ;
V_264 -> V_273 = F_184 ( V_356 ,
V_153 -> V_128 -> V_189 , V_399 ,
F_136 ( V_153 -> V_264 ) ?
V_400 : V_407 ) ;
break;
default:
F_24 ( & V_1 -> V_24 -> V_25 , L_90
L_62 , V_153 ,
V_153 -> V_128 -> V_189 ) ;
V_264 -> V_273 = F_184 ( V_356 ,
V_153 -> V_128 -> V_189 , V_399 ,
F_136 ( V_153 -> V_264 ) ?
V_400 : V_407 ) ;
}
V_406:
if ( V_395 ) {
F_183 ( V_1 , V_153 ) ;
return;
}
V_153 -> V_264 -> V_265 = V_153 ;
F_187 ( V_153 -> V_264 ) ;
}
static inline T_11 F_188 ( T_11 V_410 )
{
#define F_189 0x10
return V_410 & F_189 ;
}
static inline T_11 F_190 ( T_11 V_410 )
{
#define F_191 5
return V_410 >> F_191 ;
}
static inline T_11 F_85 ( T_1 * V_1 , T_11 V_410 )
{
#define F_192 ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define F_193 0x03
if ( F_3 ( V_1 -> V_3 & V_4 ) )
return V_410 & ~ F_192 ;
return V_410 & ~ F_193 ;
}
static inline void F_194 ( T_11 * V_410 )
{
* V_410 |= F_189 ;
}
static inline void F_195 ( T_11 * V_410 , T_11 V_411 )
{
* V_410 |= ( V_411 << F_191 ) ;
}
static void V_289 ( struct V_328 * V_329 )
{
T_1 * V_1 = V_329 -> V_141 ;
T_2 * V_2 ;
T_6 V_412 ;
int V_413 ;
struct V_263 * V_414 ;
T_4 V_28 ;
struct V_415 * V_416 ;
T_3 * V_267 ;
T_7 * V_64 ;
int V_20 , V_417 ;
int V_269 = 0 ;
int V_418 = 0 ;
V_140:
V_414 = F_196 ( V_329 ) ;
if ( ! V_414 )
goto V_419;
F_197 ( V_414 -> V_420 > V_1 -> V_298 ) ;
V_2 = F_75 ( V_1 ) ;
if ( ! V_2 )
goto V_421;
F_198 ( V_414 ) ;
V_416 = V_1 -> V_422 [ V_2 -> V_133 ] ;
F_199 ( V_329 -> V_290 ) ;
V_2 -> V_11 = V_423 ;
V_2 -> V_264 = V_414 ;
V_64 = V_414 -> V_424 -> V_76 ;
V_2 -> V_7 . V_230 = 0 ;
F_195 ( & V_2 -> V_7 . V_232 . V_33 , V_2 -> V_133 ) ;
F_194 ( & V_2 -> V_7 . V_232 . V_33 ) ;
memcpy ( & V_2 -> V_7 . V_231 , V_64 -> V_113 , sizeof( V_64 -> V_113 ) ) ;
V_2 -> V_178 . V_337 = 10 ;
V_2 -> V_178 . Type . Type = V_281 ;
V_2 -> V_178 . Type . V_338 = V_339 ;
V_2 -> V_178 . Type . V_225 =
( F_200 ( V_414 ) == V_425 ) ? V_235 : V_227 ;
V_2 -> V_178 . V_340 = 0 ;
V_2 -> V_178 . V_336 [ 0 ] =
( F_200 ( V_414 ) == V_425 ) ? V_1 -> V_307 : V_1 -> V_309 ;
V_412 = F_201 ( V_414 ) ;
F_89 ( & V_1 -> V_24 -> V_25 , L_91 ,
( int ) F_201 ( V_414 ) , ( int ) F_202 ( V_414 ) ) ;
F_203 ( V_416 , V_1 -> V_298 ) ;
V_413 = F_204 ( V_329 , V_414 , V_416 ) ;
if ( V_2 -> V_178 . Type . V_225 == V_235 )
V_417 = V_270 ;
else
V_417 = V_38 ;
V_267 = V_2 -> V_31 ;
V_269 = 0 ;
V_418 = 0 ;
for ( V_20 = 0 ; V_20 < V_413 ; V_20 ++ ) {
if ( ( ( V_269 + 1 ) == ( V_1 -> V_30 ) ) &&
! V_418 && ( ( V_413 - V_20 ) > 1 ) ) {
V_267 = V_1 -> V_18 [ V_2 -> V_133 ] ;
V_269 = 0 ;
V_418 = 1 ;
}
V_267 [ V_269 ] . V_37 = V_416 [ V_20 ] . V_78 ;
V_28 . V_36 = ( V_135 ) F_205 ( V_1 -> V_24 , F_206 ( & V_416 [ V_20 ] ) ,
V_416 [ V_20 ] . V_426 ,
V_416 [ V_20 ] . V_78 , V_417 ) ;
if ( F_23 ( & V_1 -> V_24 -> V_25 , V_28 . V_36 ) ) {
F_24 ( & V_1 -> V_24 -> V_25 ,
L_92 , V_43 ) ;
V_414 -> V_273 = F_184 ( V_356 ,
0 , V_399 ,
V_427 ) ;
F_82 ( V_1 , V_2 ) ;
return;
}
V_267 [ V_269 ] . V_34 . V_33 = V_28 . V_32 . V_33 ;
V_267 [ V_269 ] . V_34 . V_35 = V_28 . V_32 . V_35 ;
V_267 [ V_269 ] . V_41 = 0 ;
++ V_269 ;
}
if ( V_418 ) {
if ( F_21 ( V_1 , V_2 , V_1 -> V_18 [ V_2 -> V_133 ] ,
( V_413 - ( V_1 -> V_30 - 1 ) ) *
sizeof( T_3 ) ) ) {
V_414 -> V_273 = F_184 ( V_356 ,
0 , V_399 ,
V_427 ) ;
F_82 ( V_1 , V_2 ) ;
return;
}
}
if ( V_413 > V_1 -> V_56 )
V_1 -> V_56 = V_413 ;
F_89 ( & V_1 -> V_24 -> V_25 , L_93
L_94 ,
F_202 ( V_414 ) , V_413 , V_418 ) ;
V_2 -> V_7 . V_29 = V_413 + V_418 ;
if ( V_413 <= V_1 -> V_30 )
V_2 -> V_7 . V_8 = V_2 -> V_7 . V_29 ;
else
V_2 -> V_7 . V_8 = V_1 -> V_30 ;
F_2 ( V_1 , V_2 ) ;
switch ( F_207 ( V_414 ) ) {
case V_428 :
case V_429 :
if( V_1 -> V_307 == V_311 ) {
V_2 -> V_178 . V_336 [ 1 ] = 0 ;
V_2 -> V_178 . V_336 [ 2 ] = ( V_412 >> 24 ) & 0xff ;
V_2 -> V_178 . V_336 [ 3 ] = ( V_412 >> 16 ) & 0xff ;
V_2 -> V_178 . V_336 [ 4 ] = ( V_412 >> 8 ) & 0xff ;
V_2 -> V_178 . V_336 [ 5 ] = V_412 & 0xff ;
V_2 -> V_178 . V_336 [ 6 ] = 0 ;
V_2 -> V_178 . V_336 [ 7 ] = ( F_202 ( V_414 ) >> 8 ) & 0xff ;
V_2 -> V_178 . V_336 [ 8 ] = F_202 ( V_414 ) & 0xff ;
V_2 -> V_178 . V_336 [ 9 ] = V_2 -> V_178 . V_336 [ 11 ] = V_2 -> V_178 . V_336 [ 12 ] = 0 ;
} else {
T_11 V_430 = F_208 ( V_412 ) ;
V_2 -> V_178 . V_337 = 16 ;
V_2 -> V_178 . V_336 [ 1 ] = 0 ;
V_2 -> V_178 . V_336 [ 2 ] = ( V_430 >> 24 ) & 0xff ;
V_2 -> V_178 . V_336 [ 3 ] = ( V_430 >> 16 ) & 0xff ;
V_2 -> V_178 . V_336 [ 4 ] = ( V_430 >> 8 ) & 0xff ;
V_2 -> V_178 . V_336 [ 5 ] = V_430 & 0xff ;
V_2 -> V_178 . V_336 [ 6 ] = ( V_412 >> 24 ) & 0xff ;
V_2 -> V_178 . V_336 [ 7 ] = ( V_412 >> 16 ) & 0xff ;
V_2 -> V_178 . V_336 [ 8 ] = ( V_412 >> 8 ) & 0xff ;
V_2 -> V_178 . V_336 [ 9 ] = V_412 & 0xff ;
V_2 -> V_178 . V_336 [ 10 ] = ( F_202 ( V_414 ) >> 24 ) & 0xff ;
V_2 -> V_178 . V_336 [ 11 ] = ( F_202 ( V_414 ) >> 16 ) & 0xff ;
V_2 -> V_178 . V_336 [ 12 ] = ( F_202 ( V_414 ) >> 8 ) & 0xff ;
V_2 -> V_178 . V_336 [ 13 ] = F_202 ( V_414 ) & 0xff ;
V_2 -> V_178 . V_336 [ 14 ] = V_2 -> V_178 . V_336 [ 15 ] = 0 ;
}
break;
case V_431 :
case V_432 :
V_2 -> V_178 . V_337 = F_137 ( V_414 ) -> V_433 ;
memcpy ( V_2 -> V_178 . V_336 , F_137 ( V_414 ) -> V_153 , V_434 ) ;
F_137 ( V_414 ) -> V_435 = V_2 -> V_128 -> V_357 ;
break;
default:
F_24 ( & V_1 -> V_24 -> V_25 , L_95 ,
V_414 -> V_436 ) ;
F_209 () ;
}
F_210 ( V_329 -> V_290 ) ;
F_4 ( & V_1 -> V_15 , V_2 ) ;
V_1 -> V_16 ++ ;
if ( V_1 -> V_16 > V_1 -> V_17 )
V_1 -> V_17 = V_1 -> V_16 ;
goto V_140;
V_421:
F_211 ( V_329 ) ;
V_419:
F_12 ( V_1 ) ;
}
static inline unsigned long F_212 ( T_1 * V_1 )
{
return V_1 -> V_387 . V_437 ( V_1 ) ;
}
static inline int F_213 ( T_1 * V_1 )
{
return V_1 -> V_387 . V_438 ( V_1 ) ;
}
static inline long F_214 ( T_1 * V_1 )
{
return ( ( V_1 -> V_387 . V_438 ( V_1 ) == 0 ) ||
( V_1 -> V_439 == 0 ) ) ;
}
static inline int F_215 ( T_1 * V_1 , T_11 V_440 ,
T_11 V_441 )
{
if ( F_216 ( V_440 >= V_1 -> V_19 ) ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_96 , V_441 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_217 ( T_1 * V_1 , T_2 * V_2 ,
T_11 V_441 )
{
F_6 ( V_2 ) ;
if ( F_3 ( V_2 -> V_11 == V_423 ) )
F_186 ( V_1 , V_2 , 0 ) ;
else if ( V_2 -> V_11 == V_229 )
F_218 ( V_2 -> V_234 ) ;
#ifdef F_27
else if ( V_2 -> V_11 == V_442 )
F_219 ( V_2 , 0 , V_441 ) ;
#endif
}
static inline T_11 F_220 ( T_1 * V_1 )
{
T_11 V_443 ;
if ( F_216 ( ! ( V_1 -> V_3 & V_4 ) ) )
return V_1 -> V_387 . V_437 ( V_1 ) ;
if ( ( * ( V_1 -> V_444 ) & 1 ) == ( V_1 -> V_445 ) ) {
V_443 = * ( V_1 -> V_444 ) ;
( V_1 -> V_444 ) ++ ;
V_1 -> V_54 -- ;
} else {
V_443 = V_446 ;
}
if ( V_1 -> V_444 == ( V_1 -> V_447 + V_1 -> V_448 ) ) {
V_1 -> V_444 = V_1 -> V_447 ;
V_1 -> V_445 ^= 1 ;
}
return V_443 ;
}
static inline T_11 F_221 ( T_1 * V_1 , T_11 V_441 )
{
T_11 V_440 ;
T_2 * V_2 ;
V_440 = F_190 ( V_441 ) ;
if ( F_215 ( V_1 , V_440 , V_441 ) )
return F_220 ( V_1 ) ;
V_2 = V_1 -> V_126 + V_440 ;
F_217 ( V_1 , V_2 , V_441 ) ;
return F_220 ( V_1 ) ;
}
static inline T_11 F_222 ( T_1 * V_1 , T_11 V_441 )
{
T_2 * V_2 = NULL ;
V_134 V_449 , V_450 ;
V_450 = F_85 ( V_1 , V_441 ) ;
F_223 (c, &h->cmpQ, list) {
V_449 = F_85 ( V_1 , V_2 -> V_5 ) ;
if ( V_449 == V_450 ) {
F_217 ( V_1 , V_2 , V_441 ) ;
return F_220 ( V_1 ) ;
}
}
F_215 ( V_1 , V_1 -> V_19 + 1 , V_441 ) ;
return F_220 ( V_1 ) ;
}
static int F_224 ( T_1 * V_1 )
{
if ( F_3 ( ! V_451 ) )
return 0 ;
if ( F_3 ( V_1 -> V_439 ) )
return 0 ;
F_178 ( & V_1 -> V_24 -> V_25 , L_97
L_98 ) ;
return 1 ;
}
static T_36 F_225 ( int V_452 , void * V_453 )
{
T_1 * V_1 = V_453 ;
unsigned long V_13 ;
T_11 V_441 ;
if ( F_224 ( V_1 ) )
return V_454 ;
if ( F_214 ( V_1 ) )
return V_454 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
while ( F_213 ( V_1 ) ) {
V_441 = F_212 ( V_1 ) ;
while ( V_441 != V_446 )
V_441 = F_220 ( V_1 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_455 ;
}
static T_36 F_226 ( int V_452 , void * V_453 )
{
T_1 * V_1 = V_453 ;
unsigned long V_13 ;
T_11 V_441 ;
if ( F_224 ( V_1 ) )
return V_454 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_441 = F_212 ( V_1 ) ;
while ( V_441 != V_446 )
V_441 = F_220 ( V_1 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_455 ;
}
static T_36 F_227 ( int V_452 , void * V_453 )
{
T_1 * V_1 = V_453 ;
unsigned long V_13 ;
T_11 V_441 ;
if ( F_214 ( V_1 ) )
return V_454 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
while ( F_213 ( V_1 ) ) {
V_441 = F_212 ( V_1 ) ;
while ( V_441 != V_446 ) {
if ( F_188 ( V_441 ) )
V_441 = F_221 ( V_1 , V_441 ) ;
else
V_441 = F_222 ( V_1 , V_441 ) ;
}
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_455 ;
}
static T_36 F_228 ( int V_452 , void * V_453 )
{
T_1 * V_1 = V_453 ;
unsigned long V_13 ;
T_11 V_441 ;
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_441 = F_212 ( V_1 ) ;
while ( V_441 != V_446 ) {
if ( F_188 ( V_441 ) )
V_441 = F_221 ( V_1 , V_441 ) ;
else
V_441 = F_222 ( V_1 , V_441 ) ;
}
F_13 ( & V_1 -> V_14 , V_13 ) ;
return V_455 ;
}
static int F_52 ( struct V_98 * V_1 )
{
struct V_98 * V_456 ;
int V_457 = 0 ;
int V_74 = 0 ;
if ( V_1 -> V_458 )
return 0 ;
if ( ! F_229 ( & V_1 -> V_459 ) )
return 0 ;
F_93 ( & V_460 ) ;
F_223 (test_h, &scan_q, scan_list) {
if ( V_456 == V_1 ) {
V_457 = 1 ;
break;
}
}
if ( ! V_457 && ! V_1 -> V_461 ) {
F_176 ( & V_1 -> V_101 ) ;
F_5 ( & V_1 -> V_462 , & V_463 ) ;
V_74 = 1 ;
}
F_94 ( & V_460 ) ;
F_94 ( & V_1 -> V_459 ) ;
return V_74 ;
}
static void F_230 ( struct V_98 * V_1 )
{
struct V_98 * V_456 , * V_464 ;
F_93 ( & V_460 ) ;
F_231 (test_h, tmp_h, &scan_q, scan_list) {
if ( V_456 == V_1 ) {
F_232 ( & V_1 -> V_462 ) ;
F_233 ( & V_1 -> V_101 ) ;
F_94 ( & V_460 ) ;
return;
}
}
if ( V_1 -> V_461 ) {
F_94 ( & V_460 ) ;
F_127 ( & V_1 -> V_101 ) ;
} else {
F_94 ( & V_460 ) ;
}
}
static int F_234 ( void * V_465 )
{
struct V_98 * V_1 ;
while ( 1 ) {
F_235 ( V_466 ) ;
F_236 () ;
if ( F_237 () )
break;
while ( 1 ) {
F_93 ( & V_460 ) ;
if ( F_8 ( & V_463 ) ) {
F_94 ( & V_460 ) ;
break;
}
V_1 = F_182 ( V_463 . V_386 ,
struct V_98 ,
V_462 ) ;
F_232 ( & V_1 -> V_462 ) ;
V_1 -> V_461 = 1 ;
F_94 ( & V_460 ) ;
F_130 ( V_1 , 0 , 0 ) ;
F_233 ( & V_1 -> V_101 ) ;
F_93 ( & V_460 ) ;
V_1 -> V_461 = 0 ;
F_94 ( & V_460 ) ;
}
}
return 0 ;
}
static int F_108 ( T_1 * V_1 , T_2 * V_2 )
{
if ( V_2 -> V_128 -> V_357 [ 2 ] != V_467 )
return 0 ;
switch ( V_2 -> V_128 -> V_357 [ 12 ] ) {
case V_468 :
F_24 ( & V_1 -> V_24 -> V_25 , L_99
L_100 ) ;
return 1 ;
break;
case V_469 :
F_24 ( & V_1 -> V_24 -> V_25 , L_101
L_102 ) ;
return 1 ;
break;
case V_470 :
F_24 ( & V_1 -> V_24 -> V_25 , L_103 ) ;
return 1 ;
break;
case V_471 :
F_24 ( & V_1 -> V_24 -> V_25 ,
L_104 ) ;
return 1 ;
break;
case V_472 :
F_24 ( & V_1 -> V_24 -> V_25 ,
L_105 ) ;
return 1 ;
break;
default:
F_24 ( & V_1 -> V_24 -> V_25 , L_106 ) ;
return 1 ;
}
}
static void F_238 ( T_1 * V_1 )
{
int V_20 ;
char V_473 [ 17 ] ;
T_37 * V_474 = V_1 -> V_201 ;
F_89 ( & V_1 -> V_24 -> V_25 , L_107 ) ;
F_89 ( & V_1 -> V_24 -> V_25 , L_108 ) ;
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ )
V_473 [ V_20 ] = F_117 ( & ( V_474 -> V_475 [ V_20 ] ) ) ;
V_473 [ 4 ] = '\0' ;
F_89 ( & V_1 -> V_24 -> V_25 , L_109 , V_473 ) ;
F_89 ( & V_1 -> V_24 -> V_25 , L_110 ,
F_112 ( & ( V_474 -> V_476 ) ) ) ;
F_89 ( & V_1 -> V_24 -> V_25 , L_111 ,
F_112 ( & ( V_474 -> V_477 ) ) ) ;
F_89 ( & V_1 -> V_24 -> V_25 , L_112 ,
F_112 ( & ( V_474 -> V_478 ) ) ) ;
F_89 ( & V_1 -> V_24 -> V_25 , L_113 ,
F_112 ( & ( V_474 -> V_202 . V_479 ) ) ) ;
F_89 ( & V_1 -> V_24 -> V_25 , L_114 ,
F_112 ( & ( V_474 -> V_202 . V_203 ) ) ) ;
F_89 ( & V_1 -> V_24 -> V_25 , L_115 ,
F_112 ( & ( V_474 -> V_202 . V_204 ) ) ) ;
F_89 ( & V_1 -> V_24 -> V_25 , L_116 ,
F_112 ( & ( V_474 -> V_480 ) ) ) ;
F_89 ( & V_1 -> V_24 -> V_25 , L_117 ,
F_112 ( & ( V_474 -> V_214 ) ) ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
V_473 [ V_20 ] = F_117 ( & ( V_474 -> V_211 [ V_20 ] ) ) ;
V_473 [ 16 ] = '\0' ;
F_89 ( & V_1 -> V_24 -> V_25 , L_118 , V_473 ) ;
F_89 ( & V_1 -> V_24 -> V_25 , L_119 ,
F_112 ( & ( V_474 -> V_213 ) ) ) ;
}
static int F_239 ( struct V_481 * V_24 , unsigned long V_482 )
{
int V_20 , V_426 , V_483 , V_484 ;
if ( V_482 == V_485 )
return 0 ;
V_426 = 0 ;
for ( V_20 = 0 ; V_20 < V_486 ; V_20 ++ ) {
V_484 = F_240 ( V_24 , V_20 ) & V_487 ;
if ( V_484 == V_488 )
V_426 += 4 ;
else {
V_483 = F_240 ( V_24 , V_20 ) &
V_489 ;
switch ( V_483 ) {
case V_490 :
case V_491 :
V_426 += 4 ;
break;
case V_492 :
V_426 += 8 ;
break;
default:
F_24 ( & V_24 -> V_25 ,
L_120 ) ;
return - 1 ;
break;
}
}
if ( V_426 == V_482 - V_485 )
return V_20 + 1 ;
}
return - 1 ;
}
static void F_241 ( int V_493 [] , int V_494 ,
int V_495 , int * V_496 )
{
int V_20 , V_22 , V_497 , V_332 ;
#define F_242 4
#define F_243 8
for ( V_20 = 0 ; V_20 <= V_495 ; V_20 ++ ) {
V_332 = V_20 + F_242 ;
V_497 = V_494 ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
if ( V_493 [ V_22 ] >= V_332 ) {
V_497 = V_22 ;
break;
}
}
V_496 [ V_20 ] = V_497 ;
}
}
static void F_244 ( T_1 * V_1 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_498 ; V_20 ++ ) {
if ( ! ( F_112 ( V_1 -> V_206 + V_207 ) & V_205 ) )
break;
F_245 ( 10000 , 20000 ) ;
}
}
static void F_246 ( T_1 * V_1 , T_11 V_499 )
{
V_134 V_500 ;
int V_501 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_245 + 4 } ;
unsigned long V_502 ;
F_247 ( 28 > V_245 + 4 ) ;
V_1 -> V_445 = 1 ;
memset ( V_1 -> V_447 , 0 , V_1 -> V_448 * sizeof( V_135 ) ) ;
V_1 -> V_444 = V_1 -> V_447 ;
V_500 = F_112 ( & ( V_1 -> V_201 -> V_503 ) ) ;
F_241 ( V_501 , F_46 ( V_501 ) , V_1 -> V_298 ,
V_1 -> V_6 ) ;
F_114 ( V_501 [ 0 ] , & V_1 -> V_504 -> V_505 ) ;
F_114 ( V_501 [ 1 ] , & V_1 -> V_504 -> V_506 ) ;
F_114 ( V_501 [ 2 ] , & V_1 -> V_504 -> V_507 ) ;
F_114 ( V_501 [ 3 ] , & V_1 -> V_504 -> V_508 ) ;
F_114 ( V_501 [ 4 ] , & V_1 -> V_504 -> V_509 ) ;
F_114 ( V_501 [ 5 ] , & V_1 -> V_504 -> V_510 ) ;
F_114 ( V_501 [ 6 ] , & V_1 -> V_504 -> V_511 ) ;
F_114 ( V_501 [ 7 ] , & V_1 -> V_504 -> V_512 ) ;
F_114 ( V_1 -> V_448 , & V_1 -> V_504 -> V_513 ) ;
F_114 ( 1 , & V_1 -> V_504 -> V_514 ) ;
F_114 ( 0 , & V_1 -> V_504 -> V_515 ) ;
F_114 ( 0 , & V_1 -> V_504 -> V_516 ) ;
F_114 ( V_1 -> V_517 , & V_1 -> V_504 -> V_518 ) ;
F_114 ( 0 , & V_1 -> V_504 -> V_519 ) ;
F_114 ( V_4 | V_499 ,
& ( V_1 -> V_201 -> V_202 . V_479 ) ) ;
F_114 ( V_205 , V_1 -> V_206 + V_207 ) ;
F_244 ( V_1 ) ;
V_502 = F_112 ( & ( V_1 -> V_201 -> V_478 ) ) ;
if ( ! ( V_502 & V_4 ) )
F_24 ( & V_1 -> V_24 -> V_25 , L_121
L_122 ) ;
}
static void F_248 ( T_1 * V_1 )
{
V_134 V_520 ;
if ( V_521 )
return;
F_89 ( & V_1 -> V_24 -> V_25 , L_123 ) ;
V_520 = F_112 ( & ( V_1 -> V_201 -> V_477 ) ) ;
if ( ! ( V_520 & V_522 ) )
return;
F_89 ( & V_1 -> V_24 -> V_25 , L_124 ) ;
if ( ( sizeof( T_2 ) % 32 ) != 0 ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_125 ,
L_126 ,
( int ) sizeof( T_2 ) ,
L_127 ) ;
return;
}
V_1 -> V_447 = ( V_135 * ) F_249 (
V_1 -> V_24 , V_1 -> V_448 * sizeof( V_135 ) ,
& ( V_1 -> V_517 ) ) ;
V_1 -> V_6 = F_17 ( ( ( V_1 -> V_298 + 1 ) *
sizeof( V_134 ) ) , V_23 ) ;
if ( ( V_1 -> V_447 == NULL ) || ( V_1 -> V_6 == NULL ) )
goto V_523;
F_246 ( V_1 ,
V_520 & V_524 ) ;
V_1 -> V_387 = V_525 ;
V_1 -> V_3 = V_4 ;
return;
V_523:
F_15 ( V_1 -> V_6 ) ;
if ( V_1 -> V_447 )
F_81 ( V_1 -> V_24 ,
V_1 -> V_448 * sizeof( V_135 ) ,
V_1 -> V_447 ,
V_1 -> V_517 ) ;
return;
}
static void F_250 ( T_1 * V_1 )
{
int V_74 ;
if ( ( V_1 -> V_49 == 0x40700E11 ) || ( V_1 -> V_49 == 0x40800E11 ) ||
( V_1 -> V_49 == 0x40820E11 ) || ( V_1 -> V_49 == 0x40830E11 ) )
goto V_526;
V_74 = F_251 ( V_1 -> V_24 , 4 , 4 , V_527 ) ;
if ( V_74 >= 0 ) {
V_1 -> V_51 [ 0 ] = F_252 ( V_1 -> V_24 , 0 ) ;
V_1 -> V_51 [ 1 ] = F_252 ( V_1 -> V_24 , 1 ) ;
V_1 -> V_51 [ 2 ] = F_252 ( V_1 -> V_24 , 2 ) ;
V_1 -> V_51 [ 3 ] = F_252 ( V_1 -> V_24 , 3 ) ;
return;
}
V_74 = F_251 ( V_1 -> V_24 , 1 , 1 , V_528 ) ;
V_526:
V_1 -> V_51 [ V_1 -> V_52 ] = F_252 ( V_1 -> V_24 , 0 ) ;
return;
}
static int F_253 ( struct V_481 * V_24 , T_11 * V_49 )
{
int V_20 ;
T_11 V_529 , V_530 ;
V_529 = V_24 -> V_531 ;
V_530 = V_24 -> V_532 ;
* V_49 = ( ( V_530 << 16 ) & 0xffff0000 ) |
V_529 ;
for ( V_20 = 0 ; V_20 < F_46 ( V_533 ) ; V_20 ++ ) {
if ( V_534 )
return - V_535 ;
if ( * V_49 == V_533 [ V_20 ] . V_49 )
return V_20 ;
}
F_24 ( & V_24 -> V_25 , L_128 ,
* V_49 ) ;
return - V_535 ;
}
static inline bool F_254 ( T_1 * V_1 )
{
T_38 V_536 ;
( void ) F_255 ( V_1 -> V_24 , V_537 , & V_536 ) ;
return ( ( V_536 & V_538 ) == 0 ) ;
}
static int F_256 ( struct V_481 * V_24 ,
unsigned long * V_539 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_486 ; V_20 ++ )
if ( F_240 ( V_24 , V_20 ) & V_540 ) {
* V_539 = F_257 ( V_24 , V_20 ) ;
F_89 ( & V_24 -> V_25 , L_129 ,
* V_539 ) ;
return 0 ;
}
F_24 ( & V_24 -> V_25 , L_130 ) ;
return - V_535 ;
}
static int F_258 ( struct V_481 * V_24 ,
void T_34 * V_206 , int V_541 )
#define F_259 1
#define F_260 0
{
int V_20 , V_542 ;
T_11 V_543 ;
if ( V_541 )
V_542 = V_544 ;
else
V_542 = V_545 ;
for ( V_20 = 0 ; V_20 < V_542 ; V_20 ++ ) {
V_543 = F_112 ( V_206 + V_546 ) ;
if ( V_541 ) {
if ( V_543 == V_547 )
return 0 ;
} else {
if ( V_543 != V_547 )
return 0 ;
}
F_261 ( V_548 ) ;
}
F_24 ( & V_24 -> V_25 , L_131 ) ;
return - V_535 ;
}
static int F_262 ( struct V_481 * V_24 , void T_34 * V_206 ,
T_11 * V_549 , T_39 * V_550 ,
T_39 * V_551 )
{
* V_549 = F_112 ( V_206 + V_552 ) ;
* V_551 = F_112 ( V_206 + V_553 ) ;
* V_549 &= ( T_11 ) 0x0000ffff ;
* V_550 = F_239 ( V_24 , * V_549 ) ;
if ( * V_550 == - 1 ) {
F_24 ( & V_24 -> V_25 , L_132
L_133 , * V_549 ) ;
return - V_535 ;
}
return 0 ;
}
static int F_263 ( T_1 * V_1 )
{
T_39 V_551 ;
T_11 V_549 ;
T_39 V_550 ;
T_11 V_500 ;
int V_278 ;
V_278 = F_262 ( V_1 -> V_24 , V_1 -> V_206 , & V_549 ,
& V_550 , & V_551 ) ;
if ( V_278 )
return V_278 ;
V_1 -> V_201 = F_180 ( F_257 ( V_1 -> V_24 ,
V_550 ) + V_551 , sizeof( * V_1 -> V_201 ) ) ;
if ( ! V_1 -> V_201 )
return - V_228 ;
V_278 = F_264 ( V_1 -> V_201 ) ;
if ( V_278 )
return V_278 ;
V_500 = F_112 ( & V_1 -> V_201 -> V_503 ) ;
V_1 -> V_504 = F_180 ( F_257 ( V_1 -> V_24 ,
V_550 ) + V_551 + V_500 ,
sizeof( * V_1 -> V_504 ) ) ;
if ( ! V_1 -> V_504 )
return - V_228 ;
return 0 ;
}
static void F_265 ( struct V_98 * V_1 )
{
V_1 -> V_448 = F_112 ( & ( V_1 -> V_201 -> V_554 ) ) ;
if ( V_451 && V_1 -> V_448 > 32 )
V_1 -> V_448 = 32 ;
if ( V_1 -> V_448 < 16 ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_134
L_135
L_136 ,
V_1 -> V_448 ) ;
V_1 -> V_448 = 16 ;
}
}
static void F_266 ( T_1 * V_1 )
{
F_265 ( V_1 ) ;
V_1 -> V_19 = V_1 -> V_448 - 4 - V_555 ;
V_1 -> V_298 = F_112 ( & ( V_1 -> V_201 -> V_556 ) ) ;
if ( V_1 -> V_49 == 0x3225103C )
V_1 -> V_298 = V_245 ;
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
static inline bool F_267 ( T_1 * V_1 )
{
if ( ! F_268 ( V_1 -> V_201 -> V_475 , L_137 , 4 ) ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_138 ) ;
return false ;
}
return true ;
}
static inline void F_269 ( T_1 * V_1 )
{
#ifdef F_270
T_11 V_557 ;
V_557 = F_112 ( & ( V_1 -> V_201 -> V_558 ) ) ;
V_557 |= 0x100 ;
F_114 ( V_557 , & ( V_1 -> V_201 -> V_558 ) ) ;
#endif
}
static inline void F_271 ( T_1 * V_1 )
{
T_11 V_559 ;
V_134 V_560 ;
if ( V_1 -> V_49 != 0x3225103C )
return;
V_559 = F_112 ( V_1 -> V_206 + V_561 ) ;
V_559 |= 0x8000 ;
F_114 ( V_559 , V_1 -> V_206 + V_561 ) ;
F_272 ( V_1 -> V_24 , V_562 , & V_560 ) ;
V_560 |= 0x1 ;
F_273 ( V_1 -> V_24 , V_562 , V_560 ) ;
}
static int F_274 ( T_1 * V_1 )
{
int V_563 , V_80 ;
V_563 = F_253 ( V_1 -> V_24 , & V_1 -> V_49 ) ;
if ( V_563 < 0 )
return - V_535 ;
V_1 -> V_48 = V_533 [ V_563 ] . V_48 ;
V_1 -> V_387 = * ( V_533 [ V_563 ] . V_387 ) ;
if ( F_254 ( V_1 ) ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_139 ) ;
return - V_535 ;
}
F_275 ( V_1 -> V_24 , V_564 |
V_565 | V_566 ) ;
V_80 = F_276 ( V_1 -> V_24 ) ;
if ( V_80 ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_140 ) ;
return V_80 ;
}
V_80 = F_277 ( V_1 -> V_24 , L_141 ) ;
if ( V_80 ) {
F_24 ( & V_1 -> V_24 -> V_25 ,
L_142 ) ;
return V_80 ;
}
F_89 ( & V_1 -> V_24 -> V_25 , L_143 , V_1 -> V_24 -> V_452 ) ;
F_89 ( & V_1 -> V_24 -> V_25 , L_144 , V_1 -> V_49 ) ;
F_250 ( V_1 ) ;
V_80 = F_256 ( V_1 -> V_24 , & V_1 -> V_567 ) ;
if ( V_80 )
goto V_568;
V_1 -> V_206 = F_180 ( V_1 -> V_567 , 0x250 ) ;
if ( ! V_1 -> V_206 ) {
V_80 = - V_228 ;
goto V_568;
}
V_80 = F_258 ( V_1 -> V_24 , V_1 -> V_206 , F_259 ) ;
if ( V_80 )
goto V_568;
V_80 = F_263 ( V_1 ) ;
if ( V_80 )
goto V_568;
F_238 ( V_1 ) ;
F_266 ( V_1 ) ;
if ( ! F_267 ( V_1 ) ) {
V_80 = - V_535 ;
goto V_568;
}
F_269 ( V_1 ) ;
F_271 ( V_1 ) ;
V_80 = F_278 ( V_1 ) ;
if ( V_80 )
goto V_568;
F_248 ( V_1 ) ;
return 0 ;
V_568:
if ( V_1 -> V_504 )
F_279 ( V_1 -> V_504 ) ;
if ( V_1 -> V_201 )
F_279 ( V_1 -> V_201 ) ;
if ( V_1 -> V_206 )
F_279 ( V_1 -> V_206 ) ;
F_280 ( V_1 -> V_24 ) ;
return V_80 ;
}
static int F_281 ( struct V_481 * V_24 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_569 ; V_20 ++ ) {
if ( ! V_266 [ V_20 ] ) {
T_1 * V_1 ;
V_1 = F_129 ( sizeof( T_1 ) , V_23 ) ;
if ( ! V_1 )
goto V_570;
V_266 [ V_20 ] = V_1 ;
return V_20 ;
}
}
F_24 ( & V_24 -> V_25 , L_145
L_146 , V_569 ) ;
return - 1 ;
V_570:
F_24 ( & V_24 -> V_25 , L_147 ) ;
return - 1 ;
}
static void F_282 ( T_1 * V_1 )
{
int V_20 ;
V_266 [ V_1 -> V_63 ] = NULL ;
for ( V_20 = 0 ; V_20 < V_1 -> V_65 + 1 ; V_20 ++ )
if ( V_1 -> V_138 [ V_20 ] != NULL )
F_164 ( V_1 -> V_138 [ V_20 ] ) ;
F_15 ( V_1 ) ;
}
static int F_283 ( struct V_481 * V_24 , unsigned char V_571 ,
unsigned char type )
{
typedef struct {
T_40 V_572 ;
T_41 V_178 ;
T_42 V_573 ;
} T_43;
static const T_10 V_574 = sizeof( T_43 ) + sizeof( V_130 ) ;
T_43 * V_153 ;
T_13 V_575 ;
T_28 V_576 , V_410 ;
void T_34 * V_206 ;
int V_20 , V_80 ;
V_206 = F_284 ( F_257 ( V_24 , 0 ) , F_285 ( V_24 , 0 ) ) ;
if ( V_206 == NULL )
return - V_228 ;
V_80 = F_286 ( V_24 , F_287 ( 32 ) ) ;
if ( V_80 ) {
F_279 ( V_206 ) ;
return - V_228 ;
}
V_153 = F_249 ( V_24 , V_574 , & V_575 ) ;
if ( V_153 == NULL ) {
F_279 ( V_206 ) ;
return - V_228 ;
}
V_576 = V_575 ;
V_153 -> V_572 . V_230 = 0 ;
V_153 -> V_572 . V_8 = 0 ;
V_153 -> V_572 . V_29 = 0 ;
V_153 -> V_572 . V_232 . V_33 = V_576 ;
V_153 -> V_572 . V_232 . V_35 = 0 ;
memset ( & V_153 -> V_572 . V_231 . V_335 , 0 , 8 ) ;
V_153 -> V_178 . V_337 = 16 ;
V_153 -> V_178 . Type . Type = V_349 ;
V_153 -> V_178 . Type . V_338 = V_577 ;
V_153 -> V_178 . Type . V_225 = V_226 ;
V_153 -> V_178 . V_340 = 0 ;
V_153 -> V_178 . V_336 [ 0 ] = V_571 ;
V_153 -> V_178 . V_336 [ 1 ] = type ;
memset ( & V_153 -> V_178 . V_336 [ 2 ] , 0 , 14 ) ;
V_153 -> V_573 . V_34 . V_33 = V_576 + sizeof( T_43 ) ;
V_153 -> V_573 . V_34 . V_35 = 0 ;
V_153 -> V_573 . V_37 = sizeof( V_130 ) ;
F_114 ( V_576 , V_206 + V_578 ) ;
for ( V_20 = 0 ; V_20 < 10 ; V_20 ++ ) {
V_410 = F_112 ( V_206 + V_579 ) ;
if ( ( V_410 & ~ 3 ) == V_576 )
break;
F_261 ( V_580 ) ;
}
F_279 ( V_206 ) ;
if ( V_20 == 10 ) {
F_18 ( & V_24 -> V_25 ,
L_148 ,
V_571 , type ) ;
return - V_581 ;
}
F_81 ( V_24 , V_574 , V_153 , V_575 ) ;
if ( V_410 & 2 ) {
F_18 ( & V_24 -> V_25 , L_149 ,
V_571 , type ) ;
return - V_274 ;
}
F_178 ( & V_24 -> V_25 , L_150 ,
V_571 , type ) ;
return 0 ;
}
static int F_288 ( struct V_481 * V_24 ,
void * T_34 V_206 , T_11 V_582 )
{
T_38 V_583 ;
int V_57 ;
if ( V_582 ) {
F_178 ( & V_24 -> V_25 , L_151 ) ;
F_114 ( V_582 , V_206 + V_207 ) ;
} else {
V_57 = F_289 ( V_24 , V_584 ) ;
if ( V_57 == 0 ) {
F_18 ( & V_24 -> V_25 ,
L_152
L_153 ) ;
return - V_535 ;
}
F_178 ( & V_24 -> V_25 , L_154 ) ;
F_255 ( V_24 , V_57 + V_585 , & V_583 ) ;
V_583 &= ~ V_586 ;
V_583 |= V_587 ;
F_290 ( V_24 , V_57 + V_585 , V_583 ) ;
F_261 ( 500 ) ;
V_583 &= ~ V_586 ;
V_583 |= V_588 ;
F_290 ( V_24 , V_57 + V_585 , V_583 ) ;
F_261 ( 500 ) ;
}
return 0 ;
}
static void F_291 ( char * V_589 , int V_40 )
{
memset ( V_589 , 0 , V_40 ) ;
strncpy ( V_589 , L_155 V_590 , V_40 - 1 ) ;
}
static int F_264 ( T_37 T_34 * V_201 )
{
char * V_589 ;
int V_20 , V_332 = sizeof( V_201 -> V_589 ) ;
V_589 = F_17 ( V_332 , V_23 ) ;
if ( ! V_589 )
return - V_228 ;
F_291 ( V_589 , V_332 ) ;
for ( V_20 = 0 ; V_20 < V_332 ; V_20 ++ )
F_119 ( V_589 [ V_20 ] , & V_201 -> V_589 [ V_20 ] ) ;
F_15 ( V_589 ) ;
return 0 ;
}
static void F_292 ( T_37 T_34 * V_201 ,
unsigned char * V_591 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < sizeof( V_201 -> V_589 ) ; V_20 ++ )
V_591 [ V_20 ] = F_117 ( & V_201 -> V_589 [ V_20 ] ) ;
}
static int F_293 ( T_37 T_34 * V_201 )
{
char * V_591 , * V_592 ;
int V_278 , V_332 = sizeof( V_201 -> V_589 ) ;
V_592 = F_17 ( 2 * V_332 , V_23 ) ;
if ( ! V_592 )
return - V_228 ;
V_591 = V_592 + V_332 ;
F_291 ( V_592 , V_332 ) ;
F_292 ( V_201 , V_591 ) ;
V_278 = ! memcmp ( V_591 , V_592 , V_332 ) ;
F_15 ( V_592 ) ;
return V_278 ;
}
static int F_294 ( struct V_481 * V_24 )
{
T_39 V_551 ;
T_11 V_549 ;
T_39 V_550 ;
void T_34 * V_206 ;
unsigned long V_567 ;
T_11 V_593 ;
int V_278 ;
T_37 T_34 * V_201 ;
T_11 V_582 ;
T_11 V_49 ;
T_38 V_594 ;
F_253 ( V_24 , & V_49 ) ;
if ( ! F_48 ( V_49 ) ) {
F_24 ( & V_24 -> V_25 , L_156 ) ;
return - V_535 ;
}
if ( ! F_45 ( V_49 ) )
return - V_595 ;
F_255 ( V_24 , 4 , & V_594 ) ;
F_295 ( V_24 ) ;
F_296 ( V_24 ) ;
V_278 = F_256 ( V_24 , & V_567 ) ;
if ( V_278 )
return V_278 ;
V_206 = F_180 ( V_567 , 0x250 ) ;
if ( ! V_206 )
return - V_228 ;
V_278 = F_262 ( V_24 , V_206 , & V_549 ,
& V_550 , & V_551 ) ;
if ( V_278 )
goto V_596;
V_201 = F_180 ( F_257 ( V_24 ,
V_550 ) + V_551 , sizeof( * V_201 ) ) ;
if ( ! V_201 ) {
V_278 = - V_228 ;
goto V_596;
}
V_278 = F_264 ( V_201 ) ;
if ( V_278 )
goto V_596;
V_593 = F_112 ( & V_201 -> V_593 ) ;
V_582 = V_593 & V_597 ;
if ( V_582 ) {
V_582 = V_598 ;
} else {
V_582 = V_593 & V_599 ;
if ( V_582 ) {
F_24 ( & V_24 -> V_25 , L_157
L_158
L_159
L_160 ) ;
V_278 = - V_595 ;
goto V_600;
}
}
V_278 = F_288 ( V_24 , V_206 , V_582 ) ;
if ( V_278 )
goto V_600;
F_297 ( V_24 ) ;
V_278 = F_276 ( V_24 ) ;
if ( V_278 ) {
F_24 ( & V_24 -> V_25 , L_161 ) ;
goto V_600;
}
F_290 ( V_24 , 4 , V_594 ) ;
F_261 ( V_601 ) ;
F_178 ( & V_24 -> V_25 , L_162 ) ;
V_278 = F_258 ( V_24 , V_206 , F_260 ) ;
if ( V_278 ) {
F_24 ( & V_24 -> V_25 , L_163
L_164 ) ;
V_278 = - V_595 ;
goto V_600;
}
V_278 = F_258 ( V_24 , V_206 , F_259 ) ;
if ( V_278 ) {
F_24 ( & V_24 -> V_25 ,
L_165
L_166 ) ;
goto V_600;
}
V_278 = F_293 ( V_206 ) ;
if ( V_278 < 0 )
goto V_600;
if ( V_278 ) {
F_24 ( & V_24 -> V_25 , L_167
L_168 ) ;
V_278 = - V_595 ;
} else {
F_178 ( & V_24 -> V_25 , L_169 ) ;
}
V_600:
F_279 ( V_201 ) ;
V_596:
F_279 ( V_206 ) ;
return V_278 ;
}
static int F_298 ( struct V_481 * V_24 )
{
int V_278 , V_20 ;
if ( ! V_451 )
return 0 ;
V_278 = F_294 ( V_24 ) ;
if ( V_278 == - V_595 )
return V_278 ;
if ( V_278 )
return - V_535 ;
F_24 ( & V_24 -> V_25 , L_170 ) ;
for ( V_20 = 0 ; V_20 < V_602 ; V_20 ++ ) {
if ( F_299 ( V_24 ) == 0 )
break;
else
F_24 ( & V_24 -> V_25 , L_171 ,
( V_20 < V_602 - 1 ?
L_172 : L_173 ) ) ;
F_261 ( V_603 ) ;
}
return 0 ;
}
static int F_300 ( T_1 * V_1 )
{
V_1 -> V_125 = F_17 ( F_301 ( V_1 -> V_19 ) *
sizeof( unsigned long ) , V_23 ) ;
V_1 -> V_126 = F_249 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( T_2 ) ,
& ( V_1 -> V_127 ) ) ;
V_1 -> V_129 = F_249 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( V_130 ) ,
& ( V_1 -> V_131 ) ) ;
if ( ( V_1 -> V_125 == NULL )
|| ( V_1 -> V_126 == NULL )
|| ( V_1 -> V_129 == NULL ) ) {
F_18 ( & V_1 -> V_24 -> V_25 , L_174 ) ;
return - V_228 ;
}
return 0 ;
}
static int F_302 ( T_1 * V_1 )
{
int V_20 ;
V_1 -> V_422 = F_129 ( V_1 -> V_448 *
sizeof( struct V_415 * ) , V_23 ) ;
if ( ! V_1 -> V_422 )
return - V_228 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_19 ; V_20 ++ ) {
V_1 -> V_422 [ V_20 ] = F_17 ( sizeof( struct V_415 ) *
V_1 -> V_298 , V_23 ) ;
if ( V_1 -> V_422 [ V_20 ] == NULL ) {
F_18 ( & V_1 -> V_24 -> V_25 , L_175
L_176 ) ;
return - V_228 ;
}
}
return 0 ;
}
static void F_303 ( T_1 * V_1 )
{
int V_20 ;
if ( V_1 -> V_422 ) {
for ( V_20 = 0 ; V_20 < V_1 -> V_19 ; V_20 ++ )
F_15 ( V_1 -> V_422 [ V_20 ] ) ;
F_15 ( V_1 -> V_422 ) ;
}
}
static void F_304 ( T_1 * V_1 )
{
F_15 ( V_1 -> V_125 ) ;
if ( V_1 -> V_126 )
F_81 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( T_2 ) ,
V_1 -> V_126 , V_1 -> V_127 ) ;
if ( V_1 -> V_129 )
F_81 ( V_1 -> V_24 ,
V_1 -> V_19 * sizeof( V_130 ) ,
V_1 -> V_129 , V_1 -> V_131 ) ;
}
static int F_305 ( T_1 * V_1 ,
T_36 (* F_306)( int , void * ) ,
T_36 (* F_307)( int , void * ) )
{
if ( V_1 -> V_24 -> V_604 || V_1 -> V_24 -> V_605 ) {
if ( ! F_308 ( V_1 -> V_51 [ V_1 -> V_52 ] , F_306 ,
0 , V_1 -> V_47 , V_1 ) )
return 0 ;
F_18 ( & V_1 -> V_24 -> V_25 , L_177
L_178 , V_1 -> V_51 [ V_1 -> V_52 ] ,
V_1 -> V_47 ) ;
return - 1 ;
}
if ( ! F_308 ( V_1 -> V_51 [ V_1 -> V_52 ] , F_307 ,
V_606 , V_1 -> V_47 , V_1 ) )
return 0 ;
F_18 ( & V_1 -> V_24 -> V_25 , L_179 ,
V_1 -> V_51 [ V_1 -> V_52 ] , V_1 -> V_47 ) ;
return - 1 ;
}
static int F_309 ( T_1 * V_1 )
{
if ( F_172 ( V_1 , V_149 , V_607 ) ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_180 ) ;
return - V_274 ;
}
F_178 ( & V_1 -> V_24 -> V_25 , L_181 ) ;
if ( F_258 ( V_1 -> V_24 , V_1 -> V_206 , F_260 ) ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_182 ) ;
return - 1 ;
}
F_178 ( & V_1 -> V_24 -> V_25 , L_183 ) ;
if ( F_258 ( V_1 -> V_24 , V_1 -> V_206 , F_259 ) ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_184
L_185 ) ;
return - 1 ;
}
return 0 ;
}
static void F_310 ( T_1 * V_1 )
{
int V_63 = V_1 -> V_63 ;
F_311 ( V_1 -> V_51 [ V_1 -> V_52 ] , V_1 ) ;
F_312 ( V_1 -> V_24 ) ;
F_14 ( V_1 -> V_18 , V_1 -> V_19 ) ;
F_303 ( V_1 ) ;
F_304 ( V_1 ) ;
F_15 ( V_1 -> V_6 ) ;
if ( V_1 -> V_447 )
F_81 ( V_1 -> V_24 , V_1 -> V_448 * sizeof( V_135 ) ,
V_1 -> V_447 , V_1 -> V_517 ) ;
if ( V_1 -> V_504 )
F_279 ( V_1 -> V_504 ) ;
if ( V_1 -> V_201 )
F_279 ( V_1 -> V_201 ) ;
if ( V_1 -> V_206 )
F_279 ( V_1 -> V_206 ) ;
F_313 ( V_1 -> V_292 , V_1 -> V_47 ) ;
F_69 ( V_1 ) ;
F_280 ( V_1 -> V_24 ) ;
F_15 ( V_1 ) ;
V_266 [ V_63 ] = NULL ;
}
static int F_314 ( struct V_481 * V_24 , const struct V_608 * V_609 )
{
int V_20 ;
int V_22 = 0 ;
int V_278 ;
int V_610 = 0 ;
int V_611 , V_319 ;
T_29 * V_303 ;
T_1 * V_1 ;
unsigned long V_13 ;
if ( ( V_451 ) && ( V_534 == 1 ) )
return - V_535 ;
V_278 = F_298 ( V_24 ) ;
if ( V_278 ) {
if ( V_278 != - V_595 )
return V_278 ;
V_610 = 1 ;
V_278 = 0 ;
}
V_612:
V_20 = F_281 ( V_24 ) ;
if ( V_20 < 0 )
return - V_228 ;
V_1 = V_266 [ V_20 ] ;
V_1 -> V_24 = V_24 ;
V_1 -> V_458 = 1 ;
V_1 -> V_52 = V_521 ? V_613 : V_614 ;
F_78 ( & V_1 -> V_390 ) ;
F_78 ( & V_1 -> V_15 ) ;
F_315 ( & V_1 -> V_459 ) ;
if ( F_274 ( V_1 ) != 0 )
goto V_615;
sprintf ( V_1 -> V_47 , L_186 , V_20 ) ;
V_1 -> V_63 = V_20 ;
if ( V_555 < 2 )
V_555 = 2 ;
if ( V_555 > 16 )
V_555 = 16 ;
F_316 ( & V_1 -> V_101 ) ;
if ( F_65 ( V_1 ) )
goto V_616;
if ( ! F_317 ( V_24 , F_287 ( 64 ) ) )
V_611 = 1 ;
else if ( ! F_317 ( V_24 , F_287 ( 32 ) ) )
V_611 = 0 ;
else {
F_18 ( & V_1 -> V_24 -> V_25 , L_187 ) ;
goto V_617;
}
if ( V_20 < V_618 )
V_1 -> V_292 = V_619 + V_20 ;
V_278 = F_318 ( V_1 -> V_292 , V_1 -> V_47 ) ;
if ( V_278 == - V_59 || V_278 == - V_82 ) {
F_18 ( & V_1 -> V_24 -> V_25 ,
L_188
L_189 , V_1 -> V_292 , V_1 -> V_47 , V_20 ) ;
goto V_617;
} else {
if ( V_20 >= V_618 )
V_1 -> V_292 = V_278 ;
}
V_1 -> V_387 . V_620 ( V_1 , V_621 ) ;
V_278 = F_305 ( V_1 , F_228 , F_227 ) ;
if ( V_278 )
goto V_622;
F_178 ( & V_1 -> V_24 -> V_25 , L_190 ,
V_1 -> V_47 , V_24 -> V_95 , F_319 ( V_24 ) ,
V_1 -> V_51 [ V_1 -> V_52 ] , V_611 ? L_173 : L_191 ) ;
if ( F_300 ( V_1 ) )
goto V_623;
if ( F_302 ( V_1 ) )
goto V_623;
V_1 -> V_18 = F_16 ( V_1 ,
V_1 -> V_21 , V_1 -> V_19 ) ;
if ( ! V_1 -> V_18 && V_1 -> V_21 > 0 )
goto V_623;
F_320 ( & V_1 -> V_14 ) ;
F_321 ( V_24 , V_1 ) ;
F_322 ( V_1 -> V_125 , V_1 -> V_19 ) ;
V_1 -> V_53 = 0 ;
V_1 -> V_65 = - 1 ;
for ( V_22 = 0 ; V_22 < V_315 ; V_22 ++ ) {
V_1 -> V_64 [ V_22 ] = NULL ;
V_1 -> V_138 [ V_22 ] = NULL ;
}
if ( V_610 ) {
F_11 ( & V_1 -> V_14 , V_13 ) ;
V_1 -> V_387 . V_620 ( V_1 , V_621 ) ;
F_13 ( & V_1 -> V_14 , V_13 ) ;
F_311 ( V_1 -> V_51 [ V_1 -> V_52 ] , V_1 ) ;
V_278 = F_305 ( V_1 , F_226 ,
F_225 ) ;
if ( V_278 ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_192
L_193 ) ;
goto V_623;
}
V_278 = F_309 ( V_1 ) ;
if ( V_278 ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_194 ) ;
goto V_623;
}
F_178 ( & V_1 -> V_24 -> V_25 , L_195 ) ;
F_178 ( & V_1 -> V_24 -> V_25 ,
L_196 ) ;
V_1 -> V_387 . V_620 ( V_1 , V_624 ) ;
F_261 ( 10000 ) ;
V_1 -> V_387 . V_620 ( V_1 , V_621 ) ;
V_278 = F_293 ( V_1 -> V_201 ) ;
if ( V_278 )
F_178 ( & V_1 -> V_24 -> V_25 ,
L_197 ) ;
F_310 ( V_1 ) ;
V_610 = 0 ;
if ( V_278 )
return - V_535 ;
goto V_612;
}
F_323 ( V_1 ) ;
V_1 -> V_387 . V_620 ( V_1 , V_624 ) ;
V_303 = F_129 ( sizeof( T_29 ) , V_23 ) ;
if ( V_303 == NULL ) {
F_18 ( & V_1 -> V_24 -> V_25 , L_34 ) ;
goto V_623;
}
V_319 = F_141 ( V_1 , V_280 , V_303 ,
sizeof( T_29 ) , 0 , V_149 , V_281 ) ;
if ( V_319 == V_282 ) {
V_1 -> V_50 [ 0 ] = V_303 -> V_283 [ 32 ] ;
V_1 -> V_50 [ 1 ] = V_303 -> V_283 [ 33 ] ;
V_1 -> V_50 [ 2 ] = V_303 -> V_283 [ 34 ] ;
V_1 -> V_50 [ 3 ] = V_303 -> V_283 [ 35 ] ;
} else {
F_24 ( & V_1 -> V_24 -> V_25 , L_198
L_199 ) ;
}
F_15 ( V_303 ) ;
F_1 ( V_1 ) ;
V_1 -> V_299 = 8192 ;
F_130 ( V_1 , 1 , 0 ) ;
F_42 ( V_1 ) ;
V_1 -> V_458 = 0 ;
return 0 ;
V_623:
F_304 ( V_1 ) ;
F_303 ( V_1 ) ;
F_14 ( V_1 -> V_18 , V_1 -> V_19 ) ;
F_311 ( V_1 -> V_51 [ V_1 -> V_52 ] , V_1 ) ;
V_622:
F_313 ( V_1 -> V_292 , V_1 -> V_47 ) ;
V_617:
F_69 ( V_1 ) ;
V_616:
F_280 ( V_24 ) ;
V_615:
V_1 -> V_458 = 0 ;
F_321 ( V_24 , NULL ) ;
F_282 ( V_1 ) ;
return - V_535 ;
}
static void F_324 ( struct V_481 * V_24 )
{
T_1 * V_1 ;
char * V_625 ;
int V_319 ;
V_1 = F_325 ( V_24 ) ;
V_625 = F_129 ( 4 , V_23 ) ;
if ( ! V_625 ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_200 ) ;
return;
}
V_319 = F_141 ( V_1 , V_344 , V_625 ,
4 , 0 , V_149 , V_281 ) ;
F_15 ( V_625 ) ;
if ( V_319 != V_282 )
F_24 ( & V_1 -> V_24 -> V_25 , L_201 ) ;
V_1 -> V_387 . V_620 ( V_1 , V_621 ) ;
F_311 ( V_1 -> V_51 [ V_1 -> V_52 ] , V_1 ) ;
}
static int F_278 ( struct V_98 * V_1 )
{
T_11 V_520 ;
V_520 = F_112 ( & ( V_1 -> V_201 -> V_477 ) ) ;
if ( ! ( V_520 & V_626 ) )
return - V_595 ;
V_1 -> V_448 = F_112 ( & ( V_1 -> V_201 -> V_480 ) ) ;
F_114 ( V_627 , & ( V_1 -> V_201 -> V_202 . V_479 ) ) ;
F_114 ( V_205 , V_1 -> V_206 + V_207 ) ;
F_244 ( V_1 ) ;
F_238 ( V_1 ) ;
if ( ! ( F_112 ( & ( V_1 -> V_201 -> V_478 ) ) & V_627 ) ) {
F_24 ( & V_1 -> V_24 -> V_25 , L_202 ) ;
return - V_535 ;
}
V_1 -> V_3 = V_627 ;
return 0 ;
}
static void F_326 ( struct V_481 * V_24 )
{
T_1 * V_1 ;
int V_20 , V_22 ;
if ( F_325 ( V_24 ) == NULL ) {
F_18 ( & V_24 -> V_25 , L_203 ) ;
return;
}
V_1 = F_325 ( V_24 ) ;
V_20 = V_1 -> V_63 ;
if ( V_266 [ V_20 ] == NULL ) {
F_18 ( & V_24 -> V_25 , L_204 ) ;
return;
}
F_93 ( & V_1 -> V_459 ) ;
F_230 ( V_1 ) ;
F_327 ( V_1 -> V_47 , V_87 ) ;
F_313 ( V_1 -> V_292 , V_1 -> V_47 ) ;
for ( V_22 = 0 ; V_22 < V_315 ; V_22 ++ ) {
struct V_138 * V_139 = V_1 -> V_138 [ V_22 ] ;
if ( V_139 ) {
struct V_328 * V_329 = V_139 -> V_140 ;
if ( V_139 -> V_13 & V_330 ) {
F_74 ( V_1 , V_22 , 1 ) ;
F_170 ( V_139 ) ;
}
if ( V_329 )
F_154 ( V_329 ) ;
}
}
#ifdef F_27
F_328 ( V_1 ) ;
#endif
F_324 ( V_24 ) ;
F_312 ( V_1 -> V_24 ) ;
F_279 ( V_1 -> V_504 ) ;
F_279 ( V_1 -> V_201 ) ;
F_279 ( V_1 -> V_206 ) ;
F_304 ( V_1 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_19 ; V_22 ++ )
F_15 ( V_1 -> V_422 [ V_22 ] ) ;
F_15 ( V_1 -> V_422 ) ;
F_14 ( V_1 -> V_18 , V_1 -> V_19 ) ;
F_15 ( V_1 -> V_6 ) ;
if ( V_1 -> V_447 )
F_81 ( V_1 -> V_24 , V_1 -> V_448 * sizeof( V_135 ) ,
V_1 -> V_447 , V_1 -> V_517 ) ;
F_280 ( V_24 ) ;
F_321 ( V_24 , NULL ) ;
F_69 ( V_1 ) ;
F_94 ( & V_1 -> V_459 ) ;
F_282 ( V_1 ) ;
}
static int T_44 F_329 ( void )
{
int V_80 ;
F_247 ( sizeof( T_2 ) % V_628 ) ;
F_330 (KERN_INFO DRIVER_NAME L_205 ) ;
V_80 = F_331 ( & V_118 ) ;
if ( V_80 )
return V_80 ;
V_100 = F_332 ( F_234 , NULL , L_206 ) ;
if ( F_40 ( V_100 ) ) {
V_80 = F_41 ( V_100 ) ;
goto V_629;
}
V_80 = F_333 ( & V_630 ) ;
if ( V_80 )
goto V_631;
return V_80 ;
V_631:
F_334 ( V_100 ) ;
V_629:
F_335 ( & V_118 ) ;
return V_80 ;
}
static void T_45 F_336 ( void )
{
int V_20 ;
F_337 ( & V_630 ) ;
for ( V_20 = 0 ; V_20 < V_569 ; V_20 ++ ) {
if ( V_266 [ V_20 ] != NULL ) {
F_24 ( & V_266 [ V_20 ] -> V_24 -> V_25 ,
L_207 ) ;
F_326 ( V_266 [ V_20 ] -> V_24 ) ;
}
}
F_334 ( V_100 ) ;
if ( V_87 )
F_327 ( L_16 , NULL ) ;
F_335 ( & V_118 ) ;
}
