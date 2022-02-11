static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_2 ( V_2 ) < 0 ) {
F_3 ( L_1 ) ;
return - 1 ;
}
if ( F_4 ( V_4 ) )
return 0 ;
if ( ! F_5 ( V_2 -> V_5 ) ) {
F_3 ( L_2 ) ;
return - 1 ;
}
if ( ! F_6 ( V_2 -> V_5 ) ) {
F_3 ( L_3 ) ;
return - 1 ;
}
if ( ! F_7 ( V_2 -> V_5 ) ) {
F_3 ( L_4 ) ;
return - 1 ;
}
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
T_1 V_6 = F_9 ( V_2 -> V_5 ) ;
F_10 ( & V_2 -> V_7 , V_6 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_8 = F_12 ( & V_2 -> V_7 . V_9 ) ;
if ( V_8 >= 0 )
V_8 = F_13 ( & V_2 -> V_7 ) ;
return V_8 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_7 ) ;
}
static bool F_16 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_17 (session->evlist, evsel) {
if ( V_11 -> V_12 . V_13 )
return true ;
}
return false ;
}
static void F_18 ( struct V_1 * V_2 )
{
bool V_13 = F_16 ( V_2 ) ;
F_19 ( & V_2 -> V_7 , V_13 ) ;
}
static int F_20 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_18 V_19 ;
struct V_1 * V_2 = F_21 ( V_15 , struct V_1 ,
V_14 ) ;
int V_8 = F_22 ( V_2 -> V_5 , V_17 -> V_17 , & V_19 ) ;
if ( V_8 ) {
F_3 ( L_5 , V_8 ) ;
return V_8 ;
}
return F_23 ( V_2 , V_17 -> V_17 , & V_19 ,
V_2 -> V_20 , V_17 -> V_21 ) ;
}
struct V_1 * F_24 ( struct V_3 * V_4 ,
bool V_22 , struct V_23 * V_20 )
{
struct V_1 * V_2 = F_25 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
goto V_24;
V_2 -> V_22 = V_22 ;
V_2 -> V_20 = V_20 ;
F_26 ( & V_2 -> V_25 ) ;
F_27 ( & V_2 -> V_7 ) ;
F_28 ( & V_2 -> V_14 , F_20 ) ;
if ( V_4 ) {
if ( F_29 ( V_4 ) )
goto V_26;
V_2 -> V_4 = V_4 ;
if ( F_30 ( V_4 ) ) {
if ( F_1 ( V_2 ) < 0 )
goto V_27;
F_8 ( V_2 ) ;
F_18 ( V_2 ) ;
}
}
if ( ! V_4 || F_31 ( V_4 ) ) {
if ( F_11 ( V_2 ) < 0 )
F_32 ( L_6 ) ;
}
if ( V_20 && V_20 -> V_28 &&
V_20 -> V_14 && ! F_33 ( V_2 -> V_5 ) ) {
F_34 ( L_7 ) ;
V_20 -> V_14 = false ;
}
return V_2 ;
V_27:
F_35 ( V_4 ) ;
V_26:
F_36 ( V_2 ) ;
V_24:
return NULL ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_7 . V_9 ) ;
}
static void F_39 ( struct V_29 * V_30 )
{
F_40 ( & V_30 -> V_31 ) ;
F_40 ( & V_30 -> V_32 ) ;
F_40 ( & V_30 -> V_33 ) ;
F_40 ( & V_30 -> V_34 ) ;
F_40 ( & V_30 -> V_35 ) ;
F_40 ( & V_30 -> V_36 ) ;
F_40 ( & V_30 -> V_37 ) ;
F_40 ( & V_30 -> V_38 ) ;
F_40 ( & V_30 -> V_39 ) ;
F_40 ( & V_30 -> V_40 ) ;
F_40 ( & V_30 -> V_41 ) ;
F_40 ( & V_30 -> V_42 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_41 ( V_2 ) ;
F_42 ( & V_2 -> V_25 ) ;
F_14 ( V_2 ) ;
F_37 ( V_2 ) ;
F_39 ( & V_2 -> V_43 . V_30 ) ;
F_43 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_4 )
F_35 ( V_2 -> V_4 ) ;
free ( V_2 ) ;
}
static int F_44 ( struct V_23 * V_20
V_44 ,
union V_45 * V_17
V_44 ,
struct V_1 * V_2
V_44 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_45 ( struct V_23 * V_20 V_44 ,
union V_45 * V_17 V_44 ,
struct V_46 * * T_2
V_44 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_46 ( struct V_23 * V_20 V_44 ,
union V_45 * V_17 V_44 ,
struct V_18 * V_19 V_44 ,
struct V_10 * V_11 V_44 ,
struct V_47 * V_47 V_44 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_47 ( struct V_23 * V_20 V_44 ,
union V_45 * V_17 V_44 ,
struct V_18 * V_19 V_44 ,
struct V_47 * V_47 V_44 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_48 ( struct V_23 * V_20 V_44 ,
union V_45 * V_17 V_44 ,
struct V_1 * V_2 V_44 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_49 ( struct V_23 * V_20 V_44 ,
union V_45 * V_17 V_44 ,
struct V_14 * V_15 V_44 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_50 ( struct V_23 * V_20 V_44 ,
union V_45 * V_17 V_44 ,
struct V_1 * V_1
V_44 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_51 ( struct V_23 * V_20 V_44 ,
union V_45 * V_17 V_44 ,
struct V_1 * V_2 V_44 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_52 ( int V_48 , T_3 V_49 )
{
char V_50 [ 4096 ] ;
T_4 V_8 ;
while ( V_49 > 0 ) {
V_8 = F_53 ( V_48 , V_50 , F_54 ( V_49 , ( T_3 ) sizeof( V_50 ) ) ) ;
if ( V_8 <= 0 )
return V_8 ;
V_49 -= V_8 ;
}
return 0 ;
}
static T_5 F_55 ( struct V_23 * V_20 V_44 ,
union V_45 * V_17 ,
struct V_1 * V_2
V_44 )
{
F_34 ( L_8 ) ;
if ( F_4 ( V_2 -> V_4 ) )
F_52 ( F_56 ( V_2 -> V_4 ) , V_17 -> V_51 . V_52 ) ;
return V_17 -> V_51 . V_52 ;
}
static
int F_57 ( struct V_23 * V_20 V_44 ,
union V_45 * V_17 V_44 ,
struct V_1 * V_2 V_44 )
{
F_34 ( L_8 ) ;
return 0 ;
}
void F_58 ( struct V_23 * V_20 )
{
if ( V_20 -> V_19 == NULL )
V_20 -> V_19 = F_46 ;
if ( V_20 -> V_53 == NULL )
V_20 -> V_53 = F_47 ;
if ( V_20 -> V_54 == NULL )
V_20 -> V_54 = F_47 ;
if ( V_20 -> V_55 == NULL )
V_20 -> V_55 = F_47 ;
if ( V_20 -> V_56 == NULL )
V_20 -> V_56 = F_47 ;
if ( V_20 -> exit == NULL )
V_20 -> exit = F_47 ;
if ( V_20 -> V_57 == NULL )
V_20 -> V_57 = V_58 ;
if ( V_20 -> V_59 == NULL )
V_20 -> V_59 = V_60 ;
if ( V_20 -> V_61 == NULL )
V_20 -> V_61 = V_62 ;
if ( V_20 -> V_63 == NULL )
V_20 -> V_63 = V_64 ;
if ( V_20 -> V_65 == NULL )
V_20 -> V_65 = V_66 ;
if ( V_20 -> F_53 == NULL )
V_20 -> F_53 = F_46 ;
if ( V_20 -> V_67 == NULL )
V_20 -> V_67 = F_47 ;
if ( V_20 -> V_68 == NULL )
V_20 -> V_68 = F_47 ;
if ( V_20 -> V_12 == NULL )
V_20 -> V_12 = F_45 ;
if ( V_20 -> V_69 == NULL )
V_20 -> V_69 = F_44 ;
if ( V_20 -> V_70 == NULL )
V_20 -> V_70 = F_48 ;
if ( V_20 -> V_71 == NULL ) {
if ( V_20 -> V_14 )
V_20 -> V_71 = V_72 ;
else
V_20 -> V_71 = F_49 ;
}
if ( V_20 -> V_73 == NULL )
V_20 -> V_73 = F_50 ;
if ( V_20 -> V_74 == NULL )
V_20 -> V_74 = F_51 ;
if ( V_20 -> V_51 == NULL )
V_20 -> V_51 = F_55 ;
if ( V_20 -> V_75 == NULL )
V_20 -> V_75 = F_57 ;
}
static void F_59 ( union V_45 * V_17 , void * V_76 )
{
void * V_77 = ( void * ) V_17 + V_17 -> V_43 . V_52 ;
int V_52 = V_77 - V_76 ;
F_60 ( V_52 % sizeof( V_78 ) ) ;
F_61 ( V_76 , V_52 ) ;
}
static void F_62 ( union V_45 * V_17 ,
bool T_6 V_44 )
{
struct V_79 * V_80 = & V_17 -> V_43 ;
F_61 ( V_80 + 1 , V_17 -> V_43 . V_52 - sizeof( * V_80 ) ) ;
}
static void F_63 ( union V_45 * V_17 , bool T_6 )
{
V_17 -> V_55 . V_81 = F_64 ( V_17 -> V_55 . V_81 ) ;
V_17 -> V_55 . V_82 = F_64 ( V_17 -> V_55 . V_82 ) ;
if ( T_6 ) {
void * V_76 = & V_17 -> V_55 . V_55 ;
V_76 += F_65 ( strlen ( V_76 ) + 1 , sizeof( V_78 ) ) ;
F_59 ( V_17 , V_76 ) ;
}
}
static void F_66 ( union V_45 * V_17 ,
bool T_6 )
{
V_17 -> V_53 . V_81 = F_64 ( V_17 -> V_53 . V_81 ) ;
V_17 -> V_53 . V_82 = F_64 ( V_17 -> V_53 . V_82 ) ;
V_17 -> V_53 . V_83 = F_67 ( V_17 -> V_53 . V_83 ) ;
V_17 -> V_53 . V_84 = F_67 ( V_17 -> V_53 . V_84 ) ;
V_17 -> V_53 . V_85 = F_67 ( V_17 -> V_53 . V_85 ) ;
if ( T_6 ) {
void * V_76 = & V_17 -> V_53 . V_86 ;
V_76 += F_65 ( strlen ( V_76 ) + 1 , sizeof( V_78 ) ) ;
F_59 ( V_17 , V_76 ) ;
}
}
static void F_68 ( union V_45 * V_17 ,
bool T_6 )
{
V_17 -> V_54 . V_81 = F_64 ( V_17 -> V_54 . V_81 ) ;
V_17 -> V_54 . V_82 = F_64 ( V_17 -> V_54 . V_82 ) ;
V_17 -> V_54 . V_83 = F_67 ( V_17 -> V_54 . V_83 ) ;
V_17 -> V_54 . V_84 = F_67 ( V_17 -> V_54 . V_84 ) ;
V_17 -> V_54 . V_85 = F_67 ( V_17 -> V_54 . V_85 ) ;
V_17 -> V_54 . V_87 = F_64 ( V_17 -> V_54 . V_87 ) ;
V_17 -> V_54 . F_54 = F_64 ( V_17 -> V_54 . F_54 ) ;
V_17 -> V_54 . V_88 = F_67 ( V_17 -> V_54 . V_88 ) ;
if ( T_6 ) {
void * V_76 = & V_17 -> V_54 . V_86 ;
V_76 += F_65 ( strlen ( V_76 ) + 1 , sizeof( V_78 ) ) ;
F_59 ( V_17 , V_76 ) ;
}
}
static void F_69 ( union V_45 * V_17 , bool T_6 )
{
V_17 -> V_56 . V_81 = F_64 ( V_17 -> V_56 . V_81 ) ;
V_17 -> V_56 . V_82 = F_64 ( V_17 -> V_56 . V_82 ) ;
V_17 -> V_56 . V_89 = F_64 ( V_17 -> V_56 . V_89 ) ;
V_17 -> V_56 . V_90 = F_64 ( V_17 -> V_56 . V_90 ) ;
V_17 -> V_56 . time = F_67 ( V_17 -> V_56 . time ) ;
if ( T_6 )
F_59 ( V_17 , & V_17 -> V_56 + 1 ) ;
}
static void F_70 ( union V_45 * V_17 , bool T_6 )
{
V_17 -> F_53 . V_81 = F_64 ( V_17 -> F_53 . V_81 ) ;
V_17 -> F_53 . V_82 = F_64 ( V_17 -> F_53 . V_82 ) ;
V_17 -> F_53 . V_91 = F_67 ( V_17 -> F_53 . V_91 ) ;
V_17 -> F_53 . V_92 = F_67 ( V_17 -> F_53 . V_92 ) ;
V_17 -> F_53 . V_93 = F_67 ( V_17 -> F_53 . V_93 ) ;
V_17 -> F_53 . V_94 = F_67 ( V_17 -> F_53 . V_94 ) ;
if ( T_6 )
F_59 ( V_17 , & V_17 -> F_53 + 1 ) ;
}
static void F_71 ( union V_45 * V_17 , bool T_6 )
{
V_17 -> V_61 . V_95 = F_67 ( V_17 -> V_61 . V_95 ) ;
V_17 -> V_61 . V_96 = F_67 ( V_17 -> V_61 . V_96 ) ;
V_17 -> V_61 . V_97 = F_67 ( V_17 -> V_61 . V_97 ) ;
if ( T_6 )
F_59 ( V_17 , & V_17 -> V_61 + 1 ) ;
}
static void F_72 ( union V_45 * V_17 ,
bool T_6 )
{
V_17 -> V_63 . V_81 = F_64 ( V_17 -> V_63 . V_81 ) ;
V_17 -> V_63 . V_82 = F_64 ( V_17 -> V_63 . V_82 ) ;
if ( T_6 )
F_59 ( V_17 , & V_17 -> V_63 + 1 ) ;
}
static void F_73 ( union V_45 * V_17 , bool T_6 )
{
if ( V_17 -> V_43 . type == V_98 ) {
V_17 -> V_65 . V_99 =
F_64 ( V_17 -> V_65 . V_99 ) ;
V_17 -> V_65 . V_100 =
F_64 ( V_17 -> V_65 . V_100 ) ;
}
if ( T_6 )
F_59 ( V_17 , & V_17 -> V_65 + 1 ) ;
}
static void F_74 ( union V_45 * V_17 ,
bool T_6 )
{
V_17 -> V_67 . time = F_67 ( V_17 -> V_67 . time ) ;
V_17 -> V_67 . V_94 = F_67 ( V_17 -> V_67 . V_94 ) ;
V_17 -> V_67 . V_101 = F_67 ( V_17 -> V_67 . V_101 ) ;
if ( T_6 )
F_59 ( V_17 , & V_17 -> V_67 + 1 ) ;
}
static T_7 F_75 ( T_7 V_102 )
{
int V_103 = ( V_102 >> 4 ) | ( ( V_102 & 0xf ) << 4 ) ;
V_103 = ( ( V_103 & 0xcc ) >> 2 ) | ( ( V_103 & 0x33 ) << 2 ) ;
V_103 = ( ( V_103 & 0xaa ) >> 1 ) | ( ( V_103 & 0x55 ) << 1 ) ;
return ( T_7 ) V_103 ;
}
static void F_76 ( T_7 * V_104 , unsigned V_84 )
{
unsigned V_105 ;
for ( V_105 = 0 ; V_105 < V_84 ; V_105 ++ ) {
* V_104 = F_75 ( * V_104 ) ;
V_104 ++ ;
}
}
void F_77 ( struct V_106 * V_12 )
{
V_12 -> type = F_64 ( V_12 -> type ) ;
V_12 -> V_52 = F_64 ( V_12 -> V_52 ) ;
#define F_78 ( T_8 , V_49 ) \
(attr->size > (offsetof(struct perf_event_attr, f) + \
sizeof(attr->f) * (n)))
#define F_79 ( T_8 , T_9 ) \
do { \
if (bswap_safe(f, 0)) \
attr->f = bswap_##sz(attr->f); \
} while(0)
#define F_80 ( T_8 ) bswap_field(f, 32)
#define F_81 ( T_8 ) bswap_field(f, 64)
F_81 ( V_107 ) ;
F_81 ( V_108 ) ;
F_81 ( V_109 ) ;
F_81 ( V_110 ) ;
F_80 ( V_111 ) ;
F_80 ( V_112 ) ;
F_81 ( V_113 ) ;
F_81 ( V_114 ) ;
F_81 ( V_115 ) ;
F_81 ( V_116 ) ;
F_80 ( V_117 ) ;
F_80 ( V_118 ) ;
if ( F_78 ( V_110 , 1 ) )
F_76 ( ( T_7 * ) ( & V_12 -> V_110 + 1 ) ,
sizeof( V_78 ) ) ;
#undef F_81
#undef F_80
#undef F_79
#undef F_78
}
static void F_82 ( union V_45 * V_17 ,
bool T_6 V_44 )
{
T_10 V_52 ;
F_77 ( & V_17 -> V_12 . V_12 ) ;
V_52 = V_17 -> V_43 . V_52 ;
V_52 -= ( void * ) & V_17 -> V_12 . V_94 - ( void * ) V_17 ;
F_61 ( V_17 -> V_12 . V_94 , V_52 ) ;
}
static void F_83 ( union V_45 * V_17 ,
bool T_6 V_44 )
{
V_17 -> V_119 . V_119 . V_120 =
F_67 ( V_17 -> V_119 . V_119 . V_120 ) ;
}
static void F_84 ( union V_45 * V_17 ,
bool T_6 V_44 )
{
V_17 -> V_69 . V_52 = F_64 ( V_17 -> V_69 . V_52 ) ;
}
static void F_85 ( union V_45 * V_17 ,
bool T_6 V_44 )
{
T_10 V_52 ;
V_17 -> V_74 . type = F_64 ( V_17 -> V_74 . type ) ;
V_52 = V_17 -> V_43 . V_52 ;
V_52 -= ( void * ) & V_17 -> V_74 . V_121 - ( void * ) V_17 ;
F_61 ( V_17 -> V_74 . V_121 , V_52 ) ;
}
static void F_86 ( union V_45 * V_17 ,
bool T_6 V_44 )
{
V_17 -> V_51 . V_52 = F_67 ( V_17 -> V_51 . V_52 ) ;
V_17 -> V_51 . V_122 = F_67 ( V_17 -> V_51 . V_122 ) ;
V_17 -> V_51 . V_123 = F_67 ( V_17 -> V_51 . V_123 ) ;
V_17 -> V_51 . V_124 = F_64 ( V_17 -> V_51 . V_124 ) ;
V_17 -> V_51 . V_82 = F_64 ( V_17 -> V_51 . V_82 ) ;
V_17 -> V_51 . V_125 = F_64 ( V_17 -> V_51 . V_125 ) ;
}
static void F_87 ( union V_45 * V_17 ,
bool T_6 V_44 )
{
V_17 -> V_75 . type = F_64 ( V_17 -> V_75 . type ) ;
V_17 -> V_75 . V_126 = F_64 ( V_17 -> V_75 . V_126 ) ;
V_17 -> V_75 . V_125 = F_64 ( V_17 -> V_75 . V_125 ) ;
V_17 -> V_75 . V_81 = F_64 ( V_17 -> V_75 . V_81 ) ;
V_17 -> V_75 . V_82 = F_64 ( V_17 -> V_75 . V_82 ) ;
V_17 -> V_75 . V_127 = F_67 ( V_17 -> V_75 . V_127 ) ;
}
static int V_72 ( struct V_23 * V_20 V_44 ,
union V_45 * V_17 V_44 ,
struct V_14 * V_15 )
{
if ( V_128 )
fprintf ( stdout , L_9 ) ;
return F_88 ( V_15 , V_129 ) ;
}
int F_89 ( struct V_1 * V_130 , union V_45 * V_17 ,
struct V_18 * V_19 , V_78 V_21 )
{
return F_90 ( & V_130 -> V_14 , V_17 , V_19 , V_21 ) ;
}
static void F_91 ( struct V_18 * V_19 )
{
struct V_131 * V_132 = V_19 -> V_132 ;
struct V_133 * V_134 = V_19 -> V_133 ;
V_78 V_135 = V_132 -> V_136 ;
unsigned int V_105 ;
for ( V_105 = 0 ; V_105 < V_135 ; V_105 ++ ) {
if ( V_132 -> V_137 [ V_105 ] == V_138 )
break;
}
if ( ( V_105 != V_135 ) && V_134 -> V_136 ) {
V_78 V_139 ;
V_139 = V_105 + 1 + V_134 -> V_136 + 1 ;
V_135 = V_105 + 1 ;
printf ( L_10 V_140 L_9 , V_139 ) ;
for ( V_105 = 0 ; V_105 < V_135 ; V_105 ++ )
printf ( L_11 V_141 L_9 ,
V_105 , V_132 -> V_137 [ V_105 ] ) ;
printf ( L_11 V_141 L_9 ,
( int ) ( V_135 ) , V_134 -> V_142 [ 0 ] . V_143 ) ;
for ( V_105 = 0 ; V_105 < V_134 -> V_136 ; V_105 ++ )
printf ( L_11 V_141 L_9 ,
( int ) ( V_105 + V_135 + 1 ) , V_134 -> V_142 [ V_105 ] . V_144 ) ;
}
}
static void F_92 ( struct V_10 * V_11 ,
struct V_18 * V_19 )
{
unsigned int V_105 ;
struct V_131 * V_132 = V_19 -> V_132 ;
if ( F_93 ( V_11 ) )
F_91 ( V_19 ) ;
printf ( L_12 V_140 L_9 , V_132 -> V_136 ) ;
for ( V_105 = 0 ; V_105 < V_132 -> V_136 ; V_105 ++ )
printf ( L_11 V_141 L_9 ,
V_105 , V_132 -> V_137 [ V_105 ] ) ;
}
static void F_94 ( struct V_18 * V_19 )
{
T_11 V_105 ;
printf ( L_13 V_140 L_9 , V_19 -> V_133 -> V_136 ) ;
for ( V_105 = 0 ; V_105 < V_19 -> V_133 -> V_136 ; V_105 ++ ) {
struct V_145 * V_146 = & V_19 -> V_133 -> V_142 [ V_105 ] ;
printf ( L_14 V_140 L_15 V_141 L_16 V_141 L_17 ,
V_105 , V_146 -> V_144 , V_146 -> V_143 ,
V_146 -> V_97 . V_147 ,
V_146 -> V_97 . V_148 ? L_18 : L_19 ,
V_146 -> V_97 . V_149 ? L_20 : L_19 ,
V_146 -> V_97 . abort ? L_21 : L_19 ,
V_146 -> V_97 . V_150 ? L_22 : L_19 ,
( unsigned ) V_146 -> V_97 . V_151 ) ;
}
}
static void F_95 ( V_78 V_152 , V_78 * V_153 )
{
unsigned V_154 , V_105 = 0 ;
F_96 (rid, (unsigned long *) &mask, sizeof(mask) * 8 ) {
V_78 V_155 = V_153 [ V_105 ++ ] ;
printf ( L_23 V_141 L_9 ,
F_97 ( V_154 ) , V_155 ) ;
}
}
static inline const char * F_98 ( struct V_156 * V_157 )
{
if ( V_157 -> V_158 > V_159 )
return L_24 ;
return V_160 [ V_157 -> V_158 ] ;
}
static void F_99 ( const char * type , struct V_156 * V_153 )
{
V_78 V_152 = V_153 -> V_152 ;
printf ( L_25 V_141 L_26 ,
type ,
V_152 ,
F_98 ( V_153 ) ) ;
F_95 ( V_152 , V_153 -> V_153 ) ;
}
static void F_100 ( struct V_18 * V_19 )
{
struct V_156 * V_161 = & V_19 -> V_161 ;
if ( V_161 -> V_153 )
F_99 ( L_27 , V_161 ) ;
}
static void F_101 ( struct V_18 * V_19 )
{
struct V_156 * V_162 = & V_19 -> V_162 ;
if ( V_162 -> V_153 )
F_99 ( L_28 , V_162 ) ;
}
static void F_102 ( struct V_163 * V_164 )
{
printf ( L_29 V_140 L_30 ,
V_164 -> V_52 , V_164 -> V_122 ) ;
}
static void F_103 ( struct V_46 * V_5 ,
union V_45 * V_17 ,
struct V_18 * V_19 )
{
V_78 V_109 = F_104 ( V_5 ) ;
if ( V_17 -> V_43 . type != V_165 &&
! F_33 ( V_5 ) ) {
fputs ( L_31 , stdout ) ;
return;
}
if ( ( V_109 & V_166 ) )
printf ( L_32 , V_19 -> V_125 ) ;
if ( V_109 & V_167 )
printf ( L_33 V_140 L_19 , V_19 -> time ) ;
}
static void F_105 ( struct V_18 * V_19 , V_78 V_110 )
{
printf ( L_34 ) ;
if ( V_110 & V_168 )
printf ( L_35 V_141 L_9 ,
V_19 -> F_53 . V_92 ) ;
if ( V_110 & V_169 )
printf ( L_36 V_141 L_9 ,
V_19 -> F_53 . V_93 ) ;
if ( V_110 & V_170 ) {
V_78 V_105 ;
printf ( L_37 V_140 L_9 , V_19 -> F_53 . V_171 . V_136 ) ;
for ( V_105 = 0 ; V_105 < V_19 -> F_53 . V_171 . V_136 ; V_105 ++ ) {
struct V_172 * V_91 ;
V_91 = & V_19 -> F_53 . V_171 . V_173 [ V_105 ] ;
printf ( L_38 V_141
L_39 V_141 L_9 ,
V_91 -> V_94 , V_91 -> V_91 ) ;
}
} else
printf ( L_38 V_141 L_39 V_141 L_9 ,
V_19 -> F_53 . V_174 . V_94 , V_19 -> F_53 . V_174 . V_91 ) ;
}
static void F_106 ( struct V_46 * V_5 , union V_45 * V_17 ,
V_78 V_21 , struct V_18 * V_19 )
{
if ( ! V_128 )
return;
printf ( L_40 V_141 L_41 ,
V_21 , V_17 -> V_43 . V_52 , V_17 -> V_43 . type ) ;
F_107 ( V_17 ) ;
if ( V_19 )
F_103 ( V_5 , V_17 , V_19 ) ;
printf ( L_42 V_141 L_43 , V_21 ,
V_17 -> V_43 . V_52 , F_108 ( V_17 -> V_43 . type ) ) ;
}
static void F_109 ( struct V_10 * V_11 , union V_45 * V_17 ,
struct V_18 * V_19 )
{
V_78 V_109 ;
if ( ! V_128 )
return;
printf ( L_44 V_141 L_45 V_140 L_46 V_141 L_9 ,
V_17 -> V_43 . V_175 , V_19 -> V_81 , V_19 -> V_82 , V_19 -> V_127 ,
V_19 -> V_176 , V_19 -> V_177 ) ;
V_109 = V_11 -> V_12 . V_109 ;
if ( V_109 & V_178 )
F_92 ( V_11 , V_19 ) ;
if ( ( V_109 & V_179 ) && ! F_93 ( V_11 ) )
F_94 ( V_19 ) ;
if ( V_109 & V_180 )
F_100 ( V_19 ) ;
if ( V_109 & V_181 )
F_101 ( V_19 ) ;
if ( V_109 & V_182 )
F_102 ( & V_19 -> V_183 ) ;
if ( V_109 & V_184 )
printf ( L_47 V_140 L_9 , V_19 -> V_185 ) ;
if ( V_109 & V_186 )
printf ( L_48 V_141 L_9 , V_19 -> V_187 ) ;
if ( V_109 & V_188 )
printf ( L_49 V_141 L_9 , V_19 -> V_189 ) ;
if ( V_109 & V_190 )
F_105 ( V_19 , V_11 -> V_12 . V_110 ) ;
}
static struct V_47 * F_110 ( struct V_7 * V_7 ,
union V_45 * V_17 ,
struct V_18 * V_19 )
{
const T_7 V_191 = V_17 -> V_43 . V_175 & V_192 ;
struct V_47 * V_47 ;
if ( V_193 &&
( ( V_191 == V_194 ) ||
( V_191 == V_195 ) ) ) {
T_12 V_81 ;
if ( V_17 -> V_43 . type == V_196
|| V_17 -> V_43 . type == V_197 )
V_81 = V_17 -> V_53 . V_81 ;
else
V_81 = V_19 -> V_81 ;
V_47 = F_111 ( V_7 , V_81 ) ;
if ( ! V_47 )
V_47 = F_111 ( V_7 , V_198 ) ;
return V_47 ;
}
return & V_7 -> V_9 ;
}
static int F_112 ( struct V_46 * V_5 ,
struct V_23 * V_20 ,
union V_45 * V_17 ,
struct V_18 * V_19 ,
struct V_172 * V_199 ,
struct V_47 * V_47 )
{
struct V_200 * V_201 = F_113 ( V_5 , V_199 -> V_94 ) ;
if ( V_201 ) {
V_19 -> V_94 = V_199 -> V_94 ;
V_19 -> V_176 = V_199 -> V_91 - V_201 -> V_176 ;
V_201 -> V_176 = V_199 -> V_91 ;
}
if ( ! V_201 || V_201 -> V_11 == NULL ) {
++ V_5 -> V_202 . V_203 ;
return 0 ;
}
return V_20 -> V_19 ( V_20 , V_17 , V_19 , V_201 -> V_11 , V_47 ) ;
}
static int F_114 ( struct V_46 * V_5 ,
struct V_23 * V_20 ,
union V_45 * V_17 ,
struct V_18 * V_19 ,
struct V_47 * V_47 )
{
int V_8 = - V_204 ;
V_78 V_105 ;
for ( V_105 = 0 ; V_105 < V_19 -> F_53 . V_171 . V_136 ; V_105 ++ ) {
V_8 = F_112 ( V_5 , V_20 , V_17 , V_19 ,
& V_19 -> F_53 . V_171 . V_173 [ V_105 ] ,
V_47 ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static int
F_115 ( struct V_46 * V_5 ,
struct V_23 * V_20 ,
union V_45 * V_17 ,
struct V_18 * V_19 ,
struct V_10 * V_11 ,
struct V_47 * V_47 )
{
V_78 V_109 = V_11 -> V_12 . V_109 ;
V_78 V_110 = V_11 -> V_12 . V_110 ;
if ( ! ( V_109 & V_190 ) )
return V_20 -> V_19 ( V_20 , V_17 , V_19 , V_11 , V_47 ) ;
if ( V_110 & V_170 )
return F_114 ( V_5 , V_20 , V_17 , V_19 ,
V_47 ) ;
else
return F_112 ( V_5 , V_20 , V_17 , V_19 ,
& V_19 -> F_53 . V_174 , V_47 ) ;
}
static int F_116 ( struct V_7 * V_7 ,
struct V_46 * V_5 ,
union V_45 * V_17 ,
struct V_18 * V_19 ,
struct V_23 * V_20 , V_78 V_21 )
{
struct V_10 * V_11 ;
struct V_47 * V_47 ;
F_106 ( V_5 , V_17 , V_21 , V_19 ) ;
V_11 = F_117 ( V_5 , V_19 -> V_94 ) ;
V_47 = F_110 ( V_7 , V_17 , V_19 ) ;
switch ( V_17 -> V_43 . type ) {
case V_165 :
F_109 ( V_11 , V_17 , V_19 ) ;
if ( V_11 == NULL ) {
++ V_5 -> V_202 . V_203 ;
return 0 ;
}
if ( V_47 == NULL ) {
++ V_5 -> V_202 . V_205 ;
return 0 ;
}
return F_115 ( V_5 , V_20 , V_17 , V_19 , V_11 , V_47 ) ;
case V_196 :
return V_20 -> V_53 ( V_20 , V_17 , V_19 , V_47 ) ;
case V_197 :
if ( V_17 -> V_43 . V_175 & V_206 )
++ V_5 -> V_202 . V_207 ;
return V_20 -> V_54 ( V_20 , V_17 , V_19 , V_47 ) ;
case V_208 :
return V_20 -> V_55 ( V_20 , V_17 , V_19 , V_47 ) ;
case V_209 :
return V_20 -> V_56 ( V_20 , V_17 , V_19 , V_47 ) ;
case V_210 :
return V_20 -> exit ( V_20 , V_17 , V_19 , V_47 ) ;
case V_211 :
if ( V_20 -> V_57 == V_58 )
V_5 -> V_202 . V_212 += V_17 -> V_57 . V_57 ;
return V_20 -> V_57 ( V_20 , V_17 , V_19 , V_47 ) ;
case V_213 :
if ( V_20 -> V_59 == V_60 )
V_5 -> V_202 . V_214 += V_17 -> V_59 . V_57 ;
return V_20 -> V_59 ( V_20 , V_17 , V_19 , V_47 ) ;
case V_215 :
return V_20 -> F_53 ( V_20 , V_17 , V_19 , V_11 , V_47 ) ;
case V_216 :
return V_20 -> V_67 ( V_20 , V_17 , V_19 , V_47 ) ;
case V_217 :
return V_20 -> V_68 ( V_20 , V_17 , V_19 , V_47 ) ;
case V_218 :
return V_20 -> V_61 ( V_20 , V_17 , V_19 , V_47 ) ;
case V_219 :
return V_20 -> V_63 ( V_20 , V_17 , V_19 , V_47 ) ;
case V_220 :
case V_98 :
return V_20 -> V_65 ( V_20 , V_17 , V_19 , V_47 ) ;
default:
++ V_5 -> V_202 . V_221 ;
return - 1 ;
}
}
static int F_23 ( struct V_1 * V_2 ,
union V_45 * V_17 ,
struct V_18 * V_19 ,
struct V_23 * V_20 ,
V_78 V_21 )
{
int V_8 ;
V_8 = F_118 ( V_2 , V_17 , V_19 , V_20 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 > 0 )
return 0 ;
return F_116 ( & V_2 -> V_7 , V_2 -> V_5 ,
V_17 , V_19 , V_20 , V_21 ) ;
}
static T_5 F_119 ( struct V_1 * V_2 ,
union V_45 * V_17 ,
V_78 V_21 )
{
struct V_14 * V_15 = & V_2 -> V_14 ;
struct V_23 * V_20 = V_2 -> V_20 ;
int V_48 = F_56 ( V_2 -> V_4 ) ;
int V_222 ;
F_106 ( V_2 -> V_5 , V_17 , V_21 , NULL ) ;
switch ( V_17 -> V_43 . type ) {
case V_223 :
V_222 = V_20 -> V_12 ( V_20 , V_17 , & V_2 -> V_5 ) ;
if ( V_222 == 0 ) {
F_8 ( V_2 ) ;
F_18 ( V_2 ) ;
}
return V_222 ;
case V_224 :
return 0 ;
case V_225 :
F_120 ( V_48 , V_21 , V_226 ) ;
return V_20 -> V_69 ( V_20 , V_17 , V_2 ) ;
case V_227 :
return V_20 -> V_70 ( V_20 , V_17 , V_2 ) ;
case V_228 :
return V_20 -> V_71 ( V_20 , V_17 , V_15 ) ;
case V_229 :
return V_20 -> V_73 ( V_20 , V_17 , V_2 ) ;
case V_230 :
return V_20 -> V_74 ( V_20 , V_17 , V_2 ) ;
case V_231 :
F_120 ( V_48 , V_21 + V_17 -> V_43 . V_52 , V_226 ) ;
return V_20 -> V_51 ( V_20 , V_17 , V_2 ) ;
case V_232 :
F_121 ( V_2 , V_17 ) ;
return V_20 -> V_75 ( V_20 , V_17 , V_2 ) ;
default:
return - V_204 ;
}
}
int F_122 ( struct V_1 * V_2 ,
union V_45 * V_17 ,
struct V_18 * V_19 )
{
struct V_46 * V_5 = V_2 -> V_5 ;
struct V_23 * V_20 = V_2 -> V_20 ;
F_123 ( & V_5 -> V_202 , V_17 -> V_43 . type ) ;
if ( V_17 -> V_43 . type >= V_233 )
return F_119 ( V_2 , V_17 , 0 ) ;
return F_116 ( & V_2 -> V_7 , V_5 , V_17 , V_19 , V_20 , 0 ) ;
}
static void F_124 ( union V_45 * V_17 , bool T_6 )
{
T_13 V_234 ;
V_234 = V_235 [ V_17 -> V_43 . type ] ;
if ( V_234 )
V_234 ( V_17 , T_6 ) ;
}
int F_125 ( struct V_1 * V_2 , T_3 V_21 ,
void * V_50 , T_10 V_236 ,
union V_45 * * V_237 ,
struct V_18 * V_19 )
{
union V_45 * V_17 ;
T_10 V_238 , V_239 ;
int V_48 ;
if ( V_2 -> V_240 && ! V_2 -> V_43 . V_241 ) {
V_17 = V_21 - V_2 -> V_242 +
V_2 -> V_243 ;
goto V_244;
}
if ( F_4 ( V_2 -> V_4 ) )
return - 1 ;
V_48 = F_56 ( V_2 -> V_4 ) ;
V_238 = sizeof( struct V_79 ) ;
if ( V_236 < V_238 )
return - 1 ;
if ( F_120 ( V_48 , V_21 , V_226 ) == ( T_3 ) - 1 ||
F_126 ( V_48 , V_50 , V_238 ) != ( T_4 ) V_238 )
return - 1 ;
V_17 = (union V_45 * ) V_50 ;
if ( V_2 -> V_43 . V_241 )
F_127 ( & V_17 -> V_43 ) ;
if ( V_17 -> V_43 . V_52 < V_238 || V_17 -> V_43 . V_52 > V_236 )
return - 1 ;
V_239 = V_17 -> V_43 . V_52 - V_238 ;
if ( F_126 ( V_48 , V_50 , V_239 ) != ( T_4 ) V_239 )
return - 1 ;
if ( V_2 -> V_43 . V_241 )
F_124 ( V_17 , F_33 ( V_2 -> V_5 ) ) ;
V_244:
if ( V_19 && V_17 -> V_43 . type < V_233 &&
F_22 ( V_2 -> V_5 , V_17 , V_19 ) )
return - 1 ;
* V_237 = V_17 ;
return 0 ;
}
static T_5 F_128 ( struct V_1 * V_2 ,
union V_45 * V_17 , V_78 V_21 )
{
struct V_46 * V_5 = V_2 -> V_5 ;
struct V_23 * V_20 = V_2 -> V_20 ;
struct V_18 V_19 ;
int V_8 ;
if ( V_2 -> V_43 . V_241 )
F_124 ( V_17 , F_33 ( V_5 ) ) ;
if ( V_17 -> V_43 . type >= V_245 )
return - V_204 ;
F_123 ( & V_5 -> V_202 , V_17 -> V_43 . type ) ;
if ( V_17 -> V_43 . type >= V_233 )
return F_119 ( V_2 , V_17 , V_21 ) ;
V_8 = F_22 ( V_5 , V_17 , & V_19 ) ;
if ( V_8 )
return V_8 ;
if ( V_20 -> V_14 ) {
V_8 = F_89 ( V_2 , V_17 , & V_19 , V_21 ) ;
if ( V_8 != - V_246 )
return V_8 ;
}
return F_23 ( V_2 , V_17 , & V_19 , V_20 ,
V_21 ) ;
}
void F_127 ( struct V_79 * V_80 )
{
V_80 -> type = F_64 ( V_80 -> type ) ;
V_80 -> V_175 = F_129 ( V_80 -> V_175 ) ;
V_80 -> V_52 = F_129 ( V_80 -> V_52 ) ;
}
struct V_247 * F_130 ( struct V_1 * V_2 , T_14 V_81 )
{
return F_131 ( & V_2 -> V_7 . V_9 , - 1 , V_81 ) ;
}
static struct V_247 * F_132 ( struct V_1 * V_2 )
{
struct V_247 * V_247 ;
V_247 = F_131 ( & V_2 -> V_7 . V_9 , 0 , 0 ) ;
if ( V_247 == NULL || F_133 ( V_247 , L_50 , 0 ) ) {
F_3 ( L_51 ) ;
V_247 = NULL ;
}
return V_247 ;
}
static void F_134 ( const struct V_1 * V_2 )
{
const struct V_248 * V_202 = & V_2 -> V_5 -> V_202 ;
const struct V_14 * V_15 = & V_2 -> V_14 ;
if ( V_2 -> V_20 -> V_57 == V_58 &&
V_202 -> V_249 [ V_211 ] != 0 ) {
F_135 ( L_52
L_53 ,
V_202 -> V_249 [ 0 ] ,
V_202 -> V_249 [ V_211 ] ) ;
}
if ( V_2 -> V_20 -> V_59 == V_60 ) {
double V_250 ;
V_250 = ( double ) V_202 -> V_214 /
( double ) ( V_202 -> V_249 [ V_165 ] + V_202 -> V_214 ) ;
if ( V_250 > 0.05 ) {
F_135 ( L_54 V_140 L_55 ,
V_202 -> V_249 [ V_165 ] + V_202 -> V_214 ,
V_250 * 100.0 ) ;
}
}
if ( V_202 -> V_221 != 0 ) {
F_135 ( L_56
L_57
L_58
L_59
L_60 ,
V_202 -> V_221 ) ;
}
if ( V_202 -> V_203 != 0 ) {
F_135 ( L_61 ,
V_202 -> V_203 ) ;
}
if ( V_202 -> V_251 != 0 ) {
F_135 ( L_62
L_63
L_64 ,
V_202 -> V_251 ,
V_202 -> V_249 [ V_165 ] ) ;
}
if ( V_202 -> V_205 != 0 ) {
F_135 ( L_65
L_66 ,
V_202 -> V_205 ) ;
}
if ( V_15 -> V_252 != 0 )
F_135 ( L_67 , V_15 -> V_252 ) ;
F_136 ( V_202 ) ;
if ( V_202 -> V_207 != 0 ) {
F_135 ( L_68
L_69
L_70
L_71
L_72
L_73
L_74 ,
V_202 -> V_207 ) ;
}
}
static int F_137 ( struct V_247 * V_247 ,
void * V_104 V_44 )
{
return F_138 ( V_247 ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
return F_140 ( & V_2 -> V_7 ,
F_137 ,
NULL ) ;
}
static int F_141 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_14 ;
struct V_23 * V_20 = V_2 -> V_20 ;
int V_48 = F_56 ( V_2 -> V_4 ) ;
union V_45 * V_17 ;
T_15 V_52 , V_253 = 0 ;
void * V_50 = NULL ;
T_5 V_254 = 0 ;
V_78 V_255 ;
T_4 V_222 ;
void * V_104 ;
F_58 ( V_20 ) ;
V_255 = 0 ;
V_253 = sizeof( union V_45 ) ;
V_50 = malloc ( V_253 ) ;
if ( ! V_50 )
return - V_256 ;
V_257:
V_17 = V_50 ;
V_222 = F_126 ( V_48 , V_17 , sizeof( struct V_79 ) ) ;
if ( V_222 <= 0 ) {
if ( V_222 == 0 )
goto V_258;
F_3 ( L_75 ) ;
goto V_259;
}
if ( V_2 -> V_43 . V_241 )
F_127 ( & V_17 -> V_43 ) ;
V_52 = V_17 -> V_43 . V_52 ;
if ( V_52 < sizeof( struct V_79 ) ) {
F_3 ( L_76 ) ;
goto V_259;
}
if ( V_52 > V_253 ) {
void * V_260 = realloc ( V_50 , V_52 ) ;
if ( ! V_260 ) {
F_3 ( L_77 ) ;
goto V_259;
}
V_50 = V_260 ;
V_253 = V_52 ;
V_17 = V_50 ;
}
V_104 = V_17 ;
V_104 += sizeof( struct V_79 ) ;
if ( V_52 - sizeof( struct V_79 ) ) {
V_222 = F_126 ( V_48 , V_104 , V_52 - sizeof( struct V_79 ) ) ;
if ( V_222 <= 0 ) {
if ( V_222 == 0 ) {
F_3 ( L_78 ) ;
goto V_258;
}
F_3 ( L_79 ) ;
goto V_259;
}
}
if ( ( V_254 = F_128 ( V_2 , V_17 , V_255 ) ) < 0 ) {
F_3 ( L_42 V_141 L_80 ,
V_255 , V_17 -> V_43 . V_52 , V_17 -> V_43 . type ) ;
V_222 = - V_204 ;
goto V_259;
}
V_255 += V_52 ;
if ( V_254 > 0 )
V_255 += V_254 ;
if ( ! F_142 () )
goto V_257;
V_258:
V_222 = F_88 ( V_15 , V_261 ) ;
if ( V_222 )
goto V_259;
V_222 = F_143 ( V_2 , V_20 ) ;
if ( V_222 )
goto V_259;
V_222 = F_139 ( V_2 ) ;
V_259:
free ( V_50 ) ;
F_134 ( V_2 ) ;
F_144 ( & V_2 -> V_14 ) ;
F_145 ( V_2 ) ;
return V_222 ;
}
static union V_45 *
F_146 ( struct V_1 * V_2 ,
V_78 V_255 , T_10 V_262 , char * V_50 )
{
union V_45 * V_17 ;
if ( V_255 + sizeof( V_17 -> V_43 ) > V_262 )
return NULL ;
V_17 = (union V_45 * ) ( V_50 + V_255 ) ;
if ( V_2 -> V_43 . V_241 )
F_127 ( & V_17 -> V_43 ) ;
if ( V_255 + V_17 -> V_43 . V_52 > V_262 ) {
if ( V_2 -> V_43 . V_241 )
F_127 ( & V_17 -> V_43 ) ;
return NULL ;
}
return V_17 ;
}
static int F_147 ( struct V_1 * V_2 ,
V_78 V_263 , V_78 V_264 ,
V_78 V_265 )
{
struct V_14 * V_15 = & V_2 -> V_14 ;
struct V_23 * V_20 = V_2 -> V_20 ;
int V_48 = F_56 ( V_2 -> V_4 ) ;
V_78 V_255 , V_266 , V_21 , V_267 , V_52 ;
int V_222 , V_268 , V_269 , V_270 = 0 ;
T_10 V_262 ;
char * V_50 , * V_271 [ V_272 ] ;
union V_45 * V_17 ;
struct V_273 V_274 ;
T_5 V_254 ;
F_58 ( V_20 ) ;
V_266 = V_275 * ( V_263 / V_275 ) ;
V_21 = V_266 ;
V_255 = V_263 - V_266 ;
if ( V_264 == 0 )
goto V_24;
if ( V_263 + V_264 < V_265 )
V_265 = V_263 + V_264 ;
F_148 ( & V_274 , V_265 , L_81 ) ;
V_262 = V_276 ;
if ( V_262 > V_265 ) {
V_262 = V_265 ;
V_2 -> V_240 = true ;
}
memset ( V_271 , 0 , sizeof( V_271 ) ) ;
V_268 = V_277 ;
V_269 = V_278 ;
if ( V_2 -> V_43 . V_241 ) {
V_268 |= V_279 ;
V_269 = V_280 ;
}
V_281:
V_50 = V_53 ( NULL , V_262 , V_268 , V_269 , V_48 ,
V_21 ) ;
if ( V_50 == V_282 ) {
F_3 ( L_82 ) ;
V_222 = - V_256 ;
goto V_259;
}
V_271 [ V_270 ] = V_50 ;
V_270 = ( V_270 + 1 ) & ( F_149 ( V_271 ) - 1 ) ;
V_267 = V_21 + V_255 ;
if ( V_2 -> V_240 ) {
V_2 -> V_243 = V_50 ;
V_2 -> V_242 = V_21 ;
}
V_257:
V_17 = F_146 ( V_2 , V_255 , V_262 , V_50 ) ;
if ( ! V_17 ) {
if ( V_271 [ V_270 ] ) {
F_150 ( V_271 [ V_270 ] , V_262 ) ;
V_271 [ V_270 ] = NULL ;
}
V_266 = V_275 * ( V_255 / V_275 ) ;
V_21 += V_266 ;
V_255 -= V_266 ;
goto V_281;
}
V_52 = V_17 -> V_43 . V_52 ;
if ( V_52 < sizeof( struct V_79 ) ||
( V_254 = F_128 ( V_2 , V_17 , V_267 ) ) < 0 ) {
F_3 ( L_42 V_141 L_80 ,
V_21 + V_255 , V_17 -> V_43 . V_52 ,
V_17 -> V_43 . type ) ;
V_222 = - V_204 ;
goto V_259;
}
if ( V_254 )
V_52 += V_254 ;
V_255 += V_52 ;
V_267 += V_52 ;
F_151 ( & V_274 , V_52 ) ;
if ( F_142 () )
goto V_24;
if ( V_267 < V_265 )
goto V_257;
V_24:
V_222 = F_88 ( V_15 , V_261 ) ;
if ( V_222 )
goto V_259;
V_222 = F_143 ( V_2 , V_20 ) ;
if ( V_222 )
goto V_259;
V_222 = F_139 ( V_2 ) ;
V_259:
F_152 () ;
F_134 ( V_2 ) ;
F_144 ( & V_2 -> V_14 ) ;
F_145 ( V_2 ) ;
V_2 -> V_240 = false ;
return V_222 ;
}
int F_153 ( struct V_1 * V_2 )
{
V_78 V_52 = F_154 ( V_2 -> V_4 ) ;
int V_222 ;
if ( F_132 ( V_2 ) == NULL )
return - V_283 ;
if ( ! F_4 ( V_2 -> V_4 ) )
V_222 = F_147 ( V_2 ,
V_2 -> V_43 . V_263 ,
V_2 -> V_43 . V_264 , V_52 ) ;
else
V_222 = F_141 ( V_2 ) ;
return V_222 ;
}
bool F_155 ( struct V_1 * V_2 , const char * V_284 )
{
struct V_10 * V_11 ;
F_17 (session->evlist, evsel) {
if ( V_11 -> V_12 . type == V_285 )
return true ;
}
F_3 ( L_83 , V_284 ) ;
return false ;
}
int F_156 ( struct V_286 * * V_287 ,
const char * V_288 , V_78 V_177 )
{
char * V_289 ;
enum V_290 V_105 ;
struct V_291 * V_292 ;
V_292 = F_25 ( sizeof( struct V_291 ) ) ;
if ( V_292 == NULL )
return - V_283 ;
V_292 -> V_293 = F_157 ( V_288 ) ;
if ( V_292 -> V_293 == NULL ) {
free ( V_292 ) ;
return - V_283 ;
}
V_289 = strchr ( V_292 -> V_293 , ']' ) ;
if ( V_289 )
* V_289 = '\0' ;
V_292 -> V_177 = V_177 ;
for ( V_105 = 0 ; V_105 < V_294 ; ++ V_105 ) {
struct V_295 * V_295 = F_158 ( V_287 [ V_105 ] ) ;
if ( ! V_295 )
continue;
V_295 -> V_291 = V_292 ;
}
return 0 ;
}
T_10 F_159 ( struct V_1 * V_2 , T_16 * V_296 )
{
return F_160 ( & V_2 -> V_7 , V_296 ) ;
}
T_10 F_161 ( struct V_1 * V_2 , T_16 * V_296 ,
bool (V_254)( struct V_297 * V_297 , int V_298 ) , int V_298 )
{
return F_162 ( & V_2 -> V_7 , V_296 , V_254 , V_298 ) ;
}
T_10 F_163 ( struct V_1 * V_2 , T_16 * V_296 )
{
T_10 V_8 ;
const char * V_284 = L_84 ;
if ( F_164 ( & V_2 -> V_43 , V_299 ) )
V_284 = L_85 ;
V_8 = fprintf ( V_296 , L_86 , V_284 ) ;
V_8 += F_165 ( & V_2 -> V_5 -> V_202 , V_296 ) ;
return V_8 ;
}
T_10 F_166 ( struct V_1 * V_2 , T_16 * V_296 )
{
return F_167 ( & V_2 -> V_7 . V_9 , V_296 ) ;
}
struct V_10 * F_168 ( struct V_1 * V_2 ,
unsigned int type )
{
struct V_10 * V_300 ;
F_17 (session->evlist, pos) {
if ( V_300 -> V_12 . type == type )
return V_300 ;
}
return NULL ;
}
void F_169 ( struct V_10 * V_11 , struct V_18 * V_19 ,
struct V_301 * V_302 ,
unsigned int V_303 , unsigned int V_304 )
{
struct V_305 * V_306 ;
int V_307 = V_303 & V_308 ;
int V_309 = V_303 & V_310 ;
int V_311 = V_303 & V_312 ;
int V_313 = V_303 & V_314 ;
int V_315 = V_303 & V_316 ;
int V_317 = V_303 & V_318 ;
char V_130 = V_315 ? ' ' : '\t' ;
if ( V_319 . V_320 && V_19 -> V_132 ) {
struct V_301 V_321 ;
if ( F_170 ( V_302 -> V_247 , V_11 ,
V_19 , NULL , NULL ,
V_322 ) != 0 ) {
if ( V_323 )
error ( L_87 ) ;
return;
}
F_171 ( & V_324 ) ;
if ( V_313 )
V_321 = * V_302 ;
while ( V_304 ) {
V_78 V_177 = 0 ;
V_306 = F_172 ( & V_324 ) ;
if ( ! V_306 )
break;
if ( V_306 -> V_325 && V_306 -> V_325 -> V_326 )
goto V_327;
if ( V_307 )
printf ( L_88 V_141 , V_130 , V_306 -> V_127 ) ;
if ( V_306 -> V_286 )
V_177 = V_306 -> V_286 -> V_328 ( V_306 -> V_286 , V_306 -> V_127 ) ;
if ( V_309 ) {
printf ( L_19 ) ;
if ( V_313 ) {
V_321 . V_177 = V_177 ;
V_321 . V_286 = V_306 -> V_286 ;
F_173 ( V_306 -> V_325 , & V_321 , stdout ) ;
} else
F_174 ( V_306 -> V_325 , stdout ) ;
}
if ( V_311 ) {
printf ( L_89 ) ;
F_175 ( V_306 -> V_286 , stdout ) ;
printf ( L_90 ) ;
}
if ( V_317 )
F_176 ( V_306 -> V_286 , V_177 , L_91 ,
stdout ) ;
if ( ! V_315 )
printf ( L_9 ) ;
V_304 -- ;
V_327:
F_177 ( & V_324 ) ;
}
} else {
if ( V_302 -> V_325 && V_302 -> V_325 -> V_326 )
return;
if ( V_307 )
printf ( L_92 V_141 , V_19 -> V_127 ) ;
if ( V_309 ) {
printf ( L_19 ) ;
if ( V_313 )
F_173 ( V_302 -> V_325 , V_302 ,
stdout ) ;
else
F_174 ( V_302 -> V_325 , stdout ) ;
}
if ( V_311 ) {
printf ( L_89 ) ;
F_175 ( V_302 -> V_286 , stdout ) ;
printf ( L_90 ) ;
}
if ( V_317 )
F_176 ( V_302 -> V_286 , V_302 -> V_177 , L_91 , stdout ) ;
}
}
int F_178 ( struct V_1 * V_2 ,
const char * V_329 , unsigned long * V_330 )
{
int V_105 , V_222 = - 1 ;
struct V_331 * V_286 ;
for ( V_105 = 0 ; V_105 < V_332 ; ++ V_105 ) {
struct V_10 * V_11 ;
V_11 = F_168 ( V_2 , V_105 ) ;
if ( ! V_11 )
continue;
if ( ! ( V_11 -> V_12 . V_109 & V_166 ) ) {
F_3 ( L_93
L_94 ) ;
return - 1 ;
}
}
V_286 = F_179 ( V_329 ) ;
if ( V_286 == NULL ) {
F_3 ( L_95 ) ;
return - 1 ;
}
for ( V_105 = 0 ; V_105 < V_286 -> V_136 ; V_105 ++ ) {
int V_125 = V_286 -> V_286 [ V_105 ] ;
if ( V_125 >= V_333 ) {
F_3 ( L_96
L_97 , V_125 ) ;
goto V_334;
}
F_180 ( V_125 , V_330 ) ;
}
V_222 = 0 ;
V_334:
F_181 ( V_286 ) ;
return V_222 ;
}
void F_182 ( struct V_1 * V_2 , T_16 * V_296 ,
bool V_335 )
{
struct V_336 V_337 ;
int V_48 , V_8 ;
if ( V_2 == NULL || V_296 == NULL )
return;
V_48 = F_56 ( V_2 -> V_4 ) ;
V_8 = F_183 ( V_48 , & V_337 ) ;
if ( V_8 == - 1 )
return;
fprintf ( V_296 , L_98 ) ;
fprintf ( V_296 , L_99 , ctime ( & V_337 . V_338 ) ) ;
F_184 ( V_2 , V_296 , V_335 ) ;
fprintf ( V_296 , L_100 ) ;
}
int F_185 ( struct V_1 * V_2 ,
const struct V_339 * V_340 ,
T_10 V_341 )
{
struct V_10 * V_11 ;
T_10 V_105 ;
int V_222 ;
for ( V_105 = 0 ; V_105 < V_341 ; V_105 ++ ) {
V_11 = F_186 ( V_2 -> V_5 , V_340 [ V_105 ] . V_293 ) ;
if ( V_11 == NULL )
continue;
V_222 = - V_342 ;
if ( V_11 -> V_343 != NULL )
goto V_24;
V_11 -> V_343 = V_340 [ V_105 ] . V_343 ;
}
V_222 = 0 ;
V_24:
return V_222 ;
}
int F_187 ( struct V_23 * V_20 V_44 ,
union V_45 * V_17 ,
struct V_1 * V_2 )
{
struct V_46 * V_5 = V_2 -> V_5 ;
struct V_344 * V_345 = & V_17 -> V_73 ;
T_10 V_105 , V_136 , V_346 ;
V_346 = ( V_345 -> V_43 . V_52 - sizeof( struct V_344 ) ) /
sizeof( struct V_347 ) ;
V_136 = V_345 -> V_136 ;
if ( V_136 > V_346 )
return - V_204 ;
if ( V_128 )
fprintf ( stdout , L_101 , V_136 ) ;
for ( V_105 = 0 ; V_105 < V_136 ; V_105 ++ ) {
struct V_347 * V_146 = & V_345 -> V_142 [ V_105 ] ;
struct V_200 * V_201 ;
if ( V_128 ) {
fprintf ( stdout , L_102 V_140 , V_146 -> V_94 ) ;
fprintf ( stdout , L_103 V_140 , V_146 -> V_124 ) ;
fprintf ( stdout , L_104 V_348 , V_146 -> V_125 ) ;
fprintf ( stdout , L_105 V_348 L_9 , V_146 -> V_82 ) ;
}
V_201 = F_113 ( V_5 , V_146 -> V_94 ) ;
if ( ! V_201 )
return - V_349 ;
V_201 -> V_124 = V_146 -> V_124 ;
V_201 -> V_125 = V_146 -> V_125 ;
V_201 -> V_82 = V_146 -> V_82 ;
}
return 0 ;
}
int F_188 ( struct V_23 * V_20 ,
T_17 V_350 ,
struct V_46 * V_5 ,
struct V_47 * V_47 )
{
union V_45 * V_351 ;
struct V_10 * V_11 ;
T_10 V_136 = 0 , V_105 = 0 , T_9 , V_346 , V_49 ;
int V_222 ;
F_189 ( L_106 ) ;
V_346 = ( V_352 - sizeof( struct V_344 ) ) /
sizeof( struct V_347 ) ;
F_17 (evlist, evsel)
V_136 += V_11 -> V_353 ;
V_49 = V_136 > V_346 ? V_346 : V_136 ;
T_9 = sizeof( struct V_344 ) + V_49 * sizeof( struct V_347 ) ;
V_351 = F_25 ( T_9 ) ;
if ( ! V_351 )
return - V_283 ;
V_351 -> V_73 . V_43 . type = V_229 ;
V_351 -> V_73 . V_43 . V_52 = T_9 ;
V_351 -> V_73 . V_136 = V_49 ;
F_17 (evlist, evsel) {
T_12 V_354 ;
for ( V_354 = 0 ; V_354 < V_11 -> V_353 ; V_354 ++ ) {
struct V_347 * V_146 ;
struct V_200 * V_201 ;
if ( V_105 >= V_49 ) {
V_222 = V_350 ( V_20 , V_351 , NULL , V_47 ) ;
if ( V_222 )
goto V_259;
V_136 -= V_49 ;
V_105 = 0 ;
}
V_146 = & V_351 -> V_73 . V_142 [ V_105 ++ ] ;
V_146 -> V_94 = V_11 -> V_94 [ V_354 ] ;
V_201 = F_113 ( V_5 , V_146 -> V_94 ) ;
if ( ! V_201 ) {
free ( V_351 ) ;
return - V_349 ;
}
V_146 -> V_124 = V_201 -> V_124 ;
V_146 -> V_125 = V_201 -> V_125 ;
V_146 -> V_82 = V_201 -> V_82 ;
}
}
T_9 = sizeof( struct V_344 ) + V_136 * sizeof( struct V_347 ) ;
V_351 -> V_73 . V_43 . V_52 = T_9 ;
V_351 -> V_73 . V_136 = V_136 ;
V_222 = V_350 ( V_20 , V_351 , NULL , V_47 ) ;
V_259:
free ( V_351 ) ;
return V_222 ;
}
