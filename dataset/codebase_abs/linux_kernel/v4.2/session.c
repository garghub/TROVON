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
}
void F_36 ( struct V_1 * V_2 )
{
F_41 ( V_2 ) ;
F_42 ( & V_2 -> V_25 ) ;
F_14 ( V_2 ) ;
F_37 ( V_2 ) ;
F_39 ( & V_2 -> V_42 . V_30 ) ;
F_43 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_4 )
F_35 ( V_2 -> V_4 ) ;
free ( V_2 ) ;
}
static int F_44 ( struct V_23 * V_20
V_43 ,
union V_44 * V_17
V_43 ,
struct V_1 * V_2
V_43 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_45 ( struct V_23 * V_20 V_43 ,
union V_44 * V_17 V_43 ,
struct V_45 * * T_2
V_43 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_46 ( struct V_23 * V_20 V_43 ,
union V_44 * V_17 V_43 ,
struct V_18 * V_19 V_43 ,
struct V_10 * V_11 V_43 ,
struct V_46 * V_46 V_43 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_47 ( struct V_23 * V_20 V_43 ,
union V_44 * V_17 V_43 ,
struct V_18 * V_19 V_43 ,
struct V_46 * V_46 V_43 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_48 ( struct V_23 * V_20 V_43 ,
union V_44 * V_17 V_43 ,
struct V_1 * V_2 V_43 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_49 ( struct V_23 * V_20 V_43 ,
union V_44 * V_17 V_43 ,
struct V_14 * V_15 V_43 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_50 ( struct V_23 * V_20 V_43 ,
union V_44 * V_17 V_43 ,
struct V_1 * V_1
V_43 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_51 ( struct V_23 * V_20 V_43 ,
union V_44 * V_17 V_43 ,
struct V_1 * V_2 V_43 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_52 ( int V_47 , T_3 V_48 )
{
char V_49 [ 4096 ] ;
T_4 V_8 ;
while ( V_48 > 0 ) {
V_8 = F_53 ( V_47 , V_49 , F_54 ( V_48 , ( T_3 ) sizeof( V_49 ) ) ) ;
if ( V_8 <= 0 )
return V_8 ;
V_48 -= V_8 ;
}
return 0 ;
}
static T_5 F_55 ( struct V_23 * V_20 V_43 ,
union V_44 * V_17 ,
struct V_1 * V_2
V_43 )
{
F_34 ( L_8 ) ;
if ( F_4 ( V_2 -> V_4 ) )
F_52 ( F_56 ( V_2 -> V_4 ) , V_17 -> V_50 . V_51 ) ;
return V_17 -> V_50 . V_51 ;
}
static
int F_57 ( struct V_23 * V_20 V_43 ,
union V_44 * V_17 V_43 ,
struct V_1 * V_2 V_43 )
{
F_34 ( L_8 ) ;
return 0 ;
}
void F_58 ( struct V_23 * V_20 )
{
if ( V_20 -> V_19 == NULL )
V_20 -> V_19 = F_46 ;
if ( V_20 -> V_52 == NULL )
V_20 -> V_52 = F_47 ;
if ( V_20 -> V_53 == NULL )
V_20 -> V_53 = F_47 ;
if ( V_20 -> V_54 == NULL )
V_20 -> V_54 = F_47 ;
if ( V_20 -> V_55 == NULL )
V_20 -> V_55 = F_47 ;
if ( V_20 -> exit == NULL )
V_20 -> exit = F_47 ;
if ( V_20 -> V_56 == NULL )
V_20 -> V_56 = V_57 ;
if ( V_20 -> V_58 == NULL )
V_20 -> V_58 = V_59 ;
if ( V_20 -> V_60 == NULL )
V_20 -> V_60 = V_61 ;
if ( V_20 -> V_62 == NULL )
V_20 -> V_62 = V_63 ;
if ( V_20 -> F_53 == NULL )
V_20 -> F_53 = F_46 ;
if ( V_20 -> V_64 == NULL )
V_20 -> V_64 = F_47 ;
if ( V_20 -> V_65 == NULL )
V_20 -> V_65 = F_47 ;
if ( V_20 -> V_12 == NULL )
V_20 -> V_12 = F_45 ;
if ( V_20 -> V_66 == NULL )
V_20 -> V_66 = F_44 ;
if ( V_20 -> V_67 == NULL )
V_20 -> V_67 = F_48 ;
if ( V_20 -> V_68 == NULL ) {
if ( V_20 -> V_14 )
V_20 -> V_68 = V_69 ;
else
V_20 -> V_68 = F_49 ;
}
if ( V_20 -> V_70 == NULL )
V_20 -> V_70 = F_50 ;
if ( V_20 -> V_71 == NULL )
V_20 -> V_71 = F_51 ;
if ( V_20 -> V_50 == NULL )
V_20 -> V_50 = F_55 ;
if ( V_20 -> V_72 == NULL )
V_20 -> V_72 = F_57 ;
}
static void F_59 ( union V_44 * V_17 , void * V_73 )
{
void * V_74 = ( void * ) V_17 + V_17 -> V_42 . V_51 ;
int V_51 = V_74 - V_73 ;
F_60 ( V_51 % sizeof( V_75 ) ) ;
F_61 ( V_73 , V_51 ) ;
}
static void F_62 ( union V_44 * V_17 ,
bool T_6 V_43 )
{
struct V_76 * V_77 = & V_17 -> V_42 ;
F_61 ( V_77 + 1 , V_17 -> V_42 . V_51 - sizeof( * V_77 ) ) ;
}
static void F_63 ( union V_44 * V_17 , bool T_6 )
{
V_17 -> V_54 . V_78 = F_64 ( V_17 -> V_54 . V_78 ) ;
V_17 -> V_54 . V_79 = F_64 ( V_17 -> V_54 . V_79 ) ;
if ( T_6 ) {
void * V_73 = & V_17 -> V_54 . V_54 ;
V_73 += F_65 ( strlen ( V_73 ) + 1 , sizeof( V_75 ) ) ;
F_59 ( V_17 , V_73 ) ;
}
}
static void F_66 ( union V_44 * V_17 ,
bool T_6 )
{
V_17 -> V_52 . V_78 = F_64 ( V_17 -> V_52 . V_78 ) ;
V_17 -> V_52 . V_79 = F_64 ( V_17 -> V_52 . V_79 ) ;
V_17 -> V_52 . V_80 = F_67 ( V_17 -> V_52 . V_80 ) ;
V_17 -> V_52 . V_81 = F_67 ( V_17 -> V_52 . V_81 ) ;
V_17 -> V_52 . V_82 = F_67 ( V_17 -> V_52 . V_82 ) ;
if ( T_6 ) {
void * V_73 = & V_17 -> V_52 . V_83 ;
V_73 += F_65 ( strlen ( V_73 ) + 1 , sizeof( V_75 ) ) ;
F_59 ( V_17 , V_73 ) ;
}
}
static void F_68 ( union V_44 * V_17 ,
bool T_6 )
{
V_17 -> V_53 . V_78 = F_64 ( V_17 -> V_53 . V_78 ) ;
V_17 -> V_53 . V_79 = F_64 ( V_17 -> V_53 . V_79 ) ;
V_17 -> V_53 . V_80 = F_67 ( V_17 -> V_53 . V_80 ) ;
V_17 -> V_53 . V_81 = F_67 ( V_17 -> V_53 . V_81 ) ;
V_17 -> V_53 . V_82 = F_67 ( V_17 -> V_53 . V_82 ) ;
V_17 -> V_53 . V_84 = F_64 ( V_17 -> V_53 . V_84 ) ;
V_17 -> V_53 . F_54 = F_64 ( V_17 -> V_53 . F_54 ) ;
V_17 -> V_53 . V_85 = F_67 ( V_17 -> V_53 . V_85 ) ;
if ( T_6 ) {
void * V_73 = & V_17 -> V_53 . V_83 ;
V_73 += F_65 ( strlen ( V_73 ) + 1 , sizeof( V_75 ) ) ;
F_59 ( V_17 , V_73 ) ;
}
}
static void F_69 ( union V_44 * V_17 , bool T_6 )
{
V_17 -> V_55 . V_78 = F_64 ( V_17 -> V_55 . V_78 ) ;
V_17 -> V_55 . V_79 = F_64 ( V_17 -> V_55 . V_79 ) ;
V_17 -> V_55 . V_86 = F_64 ( V_17 -> V_55 . V_86 ) ;
V_17 -> V_55 . V_87 = F_64 ( V_17 -> V_55 . V_87 ) ;
V_17 -> V_55 . time = F_67 ( V_17 -> V_55 . time ) ;
if ( T_6 )
F_59 ( V_17 , & V_17 -> V_55 + 1 ) ;
}
static void F_70 ( union V_44 * V_17 , bool T_6 )
{
V_17 -> F_53 . V_78 = F_64 ( V_17 -> F_53 . V_78 ) ;
V_17 -> F_53 . V_79 = F_64 ( V_17 -> F_53 . V_79 ) ;
V_17 -> F_53 . V_88 = F_67 ( V_17 -> F_53 . V_88 ) ;
V_17 -> F_53 . V_89 = F_67 ( V_17 -> F_53 . V_89 ) ;
V_17 -> F_53 . V_90 = F_67 ( V_17 -> F_53 . V_90 ) ;
V_17 -> F_53 . V_91 = F_67 ( V_17 -> F_53 . V_91 ) ;
if ( T_6 )
F_59 ( V_17 , & V_17 -> F_53 + 1 ) ;
}
static void F_71 ( union V_44 * V_17 , bool T_6 )
{
V_17 -> V_60 . V_92 = F_67 ( V_17 -> V_60 . V_92 ) ;
V_17 -> V_60 . V_93 = F_67 ( V_17 -> V_60 . V_93 ) ;
V_17 -> V_60 . V_94 = F_67 ( V_17 -> V_60 . V_94 ) ;
if ( T_6 )
F_59 ( V_17 , & V_17 -> V_60 + 1 ) ;
}
static void F_72 ( union V_44 * V_17 ,
bool T_6 )
{
V_17 -> V_62 . V_78 = F_64 ( V_17 -> V_62 . V_78 ) ;
V_17 -> V_62 . V_79 = F_64 ( V_17 -> V_62 . V_79 ) ;
if ( T_6 )
F_59 ( V_17 , & V_17 -> V_62 + 1 ) ;
}
static void F_73 ( union V_44 * V_17 ,
bool T_6 )
{
V_17 -> V_64 . time = F_67 ( V_17 -> V_64 . time ) ;
V_17 -> V_64 . V_91 = F_67 ( V_17 -> V_64 . V_91 ) ;
V_17 -> V_64 . V_95 = F_67 ( V_17 -> V_64 . V_95 ) ;
if ( T_6 )
F_59 ( V_17 , & V_17 -> V_64 + 1 ) ;
}
static T_7 F_74 ( T_7 V_96 )
{
int V_97 = ( V_96 >> 4 ) | ( ( V_96 & 0xf ) << 4 ) ;
V_97 = ( ( V_97 & 0xcc ) >> 2 ) | ( ( V_97 & 0x33 ) << 2 ) ;
V_97 = ( ( V_97 & 0xaa ) >> 1 ) | ( ( V_97 & 0x55 ) << 1 ) ;
return ( T_7 ) V_97 ;
}
static void F_75 ( T_7 * V_98 , unsigned V_81 )
{
unsigned V_99 ;
for ( V_99 = 0 ; V_99 < V_81 ; V_99 ++ ) {
* V_98 = F_74 ( * V_98 ) ;
V_98 ++ ;
}
}
void F_76 ( struct V_100 * V_12 )
{
V_12 -> type = F_64 ( V_12 -> type ) ;
V_12 -> V_51 = F_64 ( V_12 -> V_51 ) ;
#define F_77 ( T_8 , V_48 ) \
(attr->size > (offsetof(struct perf_event_attr, f) + \
sizeof(attr->f) * (n)))
#define F_78 ( T_8 , T_9 ) \
do { \
if (bswap_safe(f, 0)) \
attr->f = bswap_##sz(attr->f); \
} while(0)
#define F_79 ( T_8 ) bswap_field(f, 32)
#define F_80 ( T_8 ) bswap_field(f, 64)
F_80 ( V_101 ) ;
F_80 ( V_102 ) ;
F_80 ( V_103 ) ;
F_80 ( V_104 ) ;
F_79 ( V_105 ) ;
F_79 ( V_106 ) ;
F_80 ( V_107 ) ;
F_80 ( V_108 ) ;
F_80 ( V_109 ) ;
F_80 ( V_110 ) ;
F_79 ( V_111 ) ;
F_79 ( V_112 ) ;
if ( F_77 ( V_104 , 1 ) )
F_75 ( ( T_7 * ) ( & V_12 -> V_104 + 1 ) ,
sizeof( V_75 ) ) ;
#undef F_80
#undef F_79
#undef F_78
#undef F_77
}
static void F_81 ( union V_44 * V_17 ,
bool T_6 V_43 )
{
T_10 V_51 ;
F_76 ( & V_17 -> V_12 . V_12 ) ;
V_51 = V_17 -> V_42 . V_51 ;
V_51 -= ( void * ) & V_17 -> V_12 . V_91 - ( void * ) V_17 ;
F_61 ( V_17 -> V_12 . V_91 , V_51 ) ;
}
static void F_82 ( union V_44 * V_17 ,
bool T_6 V_43 )
{
V_17 -> V_113 . V_113 . V_114 =
F_67 ( V_17 -> V_113 . V_113 . V_114 ) ;
}
static void F_83 ( union V_44 * V_17 ,
bool T_6 V_43 )
{
V_17 -> V_66 . V_51 = F_64 ( V_17 -> V_66 . V_51 ) ;
}
static void F_84 ( union V_44 * V_17 ,
bool T_6 V_43 )
{
T_10 V_51 ;
V_17 -> V_71 . type = F_64 ( V_17 -> V_71 . type ) ;
V_51 = V_17 -> V_42 . V_51 ;
V_51 -= ( void * ) & V_17 -> V_71 . V_115 - ( void * ) V_17 ;
F_61 ( V_17 -> V_71 . V_115 , V_51 ) ;
}
static void F_85 ( union V_44 * V_17 ,
bool T_6 V_43 )
{
V_17 -> V_50 . V_51 = F_67 ( V_17 -> V_50 . V_51 ) ;
V_17 -> V_50 . V_116 = F_67 ( V_17 -> V_50 . V_116 ) ;
V_17 -> V_50 . V_117 = F_67 ( V_17 -> V_50 . V_117 ) ;
V_17 -> V_50 . V_118 = F_64 ( V_17 -> V_50 . V_118 ) ;
V_17 -> V_50 . V_79 = F_64 ( V_17 -> V_50 . V_79 ) ;
V_17 -> V_50 . V_119 = F_64 ( V_17 -> V_50 . V_119 ) ;
}
static void F_86 ( union V_44 * V_17 ,
bool T_6 V_43 )
{
V_17 -> V_72 . type = F_64 ( V_17 -> V_72 . type ) ;
V_17 -> V_72 . V_120 = F_64 ( V_17 -> V_72 . V_120 ) ;
V_17 -> V_72 . V_119 = F_64 ( V_17 -> V_72 . V_119 ) ;
V_17 -> V_72 . V_78 = F_64 ( V_17 -> V_72 . V_78 ) ;
V_17 -> V_72 . V_79 = F_64 ( V_17 -> V_72 . V_79 ) ;
V_17 -> V_72 . V_121 = F_67 ( V_17 -> V_72 . V_121 ) ;
}
static int V_69 ( struct V_23 * V_20 V_43 ,
union V_44 * V_17 V_43 ,
struct V_14 * V_15 )
{
if ( V_122 )
fprintf ( stdout , L_9 ) ;
return F_87 ( V_15 , V_123 ) ;
}
int F_88 ( struct V_1 * V_124 , union V_44 * V_17 ,
struct V_18 * V_19 , V_75 V_21 )
{
return F_89 ( & V_124 -> V_14 , V_17 , V_19 , V_21 ) ;
}
static void F_90 ( struct V_18 * V_19 )
{
struct V_125 * V_126 = V_19 -> V_126 ;
struct V_127 * V_128 = V_19 -> V_127 ;
V_75 V_129 = V_126 -> V_130 ;
unsigned int V_99 ;
for ( V_99 = 0 ; V_99 < V_129 ; V_99 ++ ) {
if ( V_126 -> V_131 [ V_99 ] == V_132 )
break;
}
if ( ( V_99 != V_129 ) && V_128 -> V_130 ) {
V_75 V_133 ;
V_133 = V_99 + 1 + V_128 -> V_130 + 1 ;
V_129 = V_99 + 1 ;
printf ( L_10 V_134 L_9 , V_133 ) ;
for ( V_99 = 0 ; V_99 < V_129 ; V_99 ++ )
printf ( L_11 V_135 L_9 ,
V_99 , V_126 -> V_131 [ V_99 ] ) ;
printf ( L_11 V_135 L_9 ,
( int ) ( V_129 ) , V_128 -> V_136 [ 0 ] . V_137 ) ;
for ( V_99 = 0 ; V_99 < V_128 -> V_130 ; V_99 ++ )
printf ( L_11 V_135 L_9 ,
( int ) ( V_99 + V_129 + 1 ) , V_128 -> V_136 [ V_99 ] . V_138 ) ;
}
}
static void F_91 ( struct V_10 * V_11 ,
struct V_18 * V_19 )
{
unsigned int V_99 ;
struct V_125 * V_126 = V_19 -> V_126 ;
if ( F_92 ( V_11 ) )
F_90 ( V_19 ) ;
printf ( L_12 V_134 L_9 , V_126 -> V_130 ) ;
for ( V_99 = 0 ; V_99 < V_126 -> V_130 ; V_99 ++ )
printf ( L_11 V_135 L_9 ,
V_99 , V_126 -> V_131 [ V_99 ] ) ;
}
static void F_93 ( struct V_18 * V_19 )
{
T_11 V_99 ;
printf ( L_13 V_134 L_9 , V_19 -> V_127 -> V_130 ) ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 -> V_130 ; V_99 ++ )
printf ( L_14 V_134 L_15 V_135 L_16 V_135 L_9 ,
V_99 , V_19 -> V_127 -> V_136 [ V_99 ] . V_138 ,
V_19 -> V_127 -> V_136 [ V_99 ] . V_137 ) ;
}
static void F_94 ( V_75 V_139 , V_75 * V_140 )
{
unsigned V_141 , V_99 = 0 ;
F_95 (rid, (unsigned long *) &mask, sizeof(mask) * 8 ) {
V_75 V_142 = V_140 [ V_99 ++ ] ;
printf ( L_17 V_135 L_9 ,
F_96 ( V_141 ) , V_142 ) ;
}
}
static inline const char * F_97 ( struct V_143 * V_144 )
{
if ( V_144 -> V_145 > V_146 )
return L_18 ;
return V_147 [ V_144 -> V_145 ] ;
}
static void F_98 ( const char * type , struct V_143 * V_140 )
{
V_75 V_139 = V_140 -> V_139 ;
printf ( L_19 V_135 L_20 ,
type ,
V_139 ,
F_97 ( V_140 ) ) ;
F_94 ( V_139 , V_140 -> V_140 ) ;
}
static void F_99 ( struct V_18 * V_19 )
{
struct V_143 * V_148 = & V_19 -> V_148 ;
if ( V_148 -> V_140 )
F_98 ( L_21 , V_148 ) ;
}
static void F_100 ( struct V_18 * V_19 )
{
struct V_143 * V_149 = & V_19 -> V_149 ;
if ( V_149 -> V_140 )
F_98 ( L_22 , V_149 ) ;
}
static void F_101 ( struct V_150 * V_151 )
{
printf ( L_23 V_134 L_24 ,
V_151 -> V_51 , V_151 -> V_116 ) ;
}
static void F_102 ( struct V_45 * V_5 ,
union V_44 * V_17 ,
struct V_18 * V_19 )
{
V_75 V_103 = F_103 ( V_5 ) ;
if ( V_17 -> V_42 . type != V_152 &&
! F_33 ( V_5 ) ) {
fputs ( L_25 , stdout ) ;
return;
}
if ( ( V_103 & V_153 ) )
printf ( L_26 , V_19 -> V_119 ) ;
if ( V_103 & V_154 )
printf ( L_27 V_134 L_28 , V_19 -> time ) ;
}
static void F_104 ( struct V_18 * V_19 , V_75 V_104 )
{
printf ( L_29 ) ;
if ( V_104 & V_155 )
printf ( L_30 V_135 L_9 ,
V_19 -> F_53 . V_89 ) ;
if ( V_104 & V_156 )
printf ( L_31 V_135 L_9 ,
V_19 -> F_53 . V_90 ) ;
if ( V_104 & V_157 ) {
V_75 V_99 ;
printf ( L_32 V_134 L_9 , V_19 -> F_53 . V_158 . V_130 ) ;
for ( V_99 = 0 ; V_99 < V_19 -> F_53 . V_158 . V_130 ; V_99 ++ ) {
struct V_159 * V_88 ;
V_88 = & V_19 -> F_53 . V_158 . V_160 [ V_99 ] ;
printf ( L_33 V_135
L_34 V_135 L_9 ,
V_88 -> V_91 , V_88 -> V_88 ) ;
}
} else
printf ( L_33 V_135 L_34 V_135 L_9 ,
V_19 -> F_53 . V_161 . V_91 , V_19 -> F_53 . V_161 . V_88 ) ;
}
static void F_105 ( struct V_45 * V_5 , union V_44 * V_17 ,
V_75 V_21 , struct V_18 * V_19 )
{
if ( ! V_122 )
return;
printf ( L_35 V_135 L_36 ,
V_21 , V_17 -> V_42 . V_51 , V_17 -> V_42 . type ) ;
F_106 ( V_17 ) ;
if ( V_19 )
F_102 ( V_5 , V_17 , V_19 ) ;
printf ( L_37 V_135 L_38 , V_21 ,
V_17 -> V_42 . V_51 , F_107 ( V_17 -> V_42 . type ) ) ;
}
static void F_108 ( struct V_10 * V_11 , union V_44 * V_17 ,
struct V_18 * V_19 )
{
V_75 V_103 ;
if ( ! V_122 )
return;
printf ( L_39 V_135 L_40 V_134 L_41 V_135 L_9 ,
V_17 -> V_42 . V_162 , V_19 -> V_78 , V_19 -> V_79 , V_19 -> V_121 ,
V_19 -> V_163 , V_19 -> V_164 ) ;
V_103 = V_11 -> V_12 . V_103 ;
if ( V_103 & V_165 )
F_91 ( V_11 , V_19 ) ;
if ( ( V_103 & V_166 ) && ! F_92 ( V_11 ) )
F_93 ( V_19 ) ;
if ( V_103 & V_167 )
F_99 ( V_19 ) ;
if ( V_103 & V_168 )
F_100 ( V_19 ) ;
if ( V_103 & V_169 )
F_101 ( & V_19 -> V_170 ) ;
if ( V_103 & V_171 )
printf ( L_42 V_134 L_9 , V_19 -> V_172 ) ;
if ( V_103 & V_173 )
printf ( L_43 V_135 L_9 , V_19 -> V_174 ) ;
if ( V_103 & V_175 )
printf ( L_44 V_135 L_9 , V_19 -> V_176 ) ;
if ( V_103 & V_177 )
F_104 ( V_19 , V_11 -> V_12 . V_104 ) ;
}
static struct V_46 * F_109 ( struct V_7 * V_7 ,
union V_44 * V_17 ,
struct V_18 * V_19 )
{
const T_7 V_178 = V_17 -> V_42 . V_162 & V_179 ;
struct V_46 * V_46 ;
if ( V_180 &&
( ( V_178 == V_181 ) ||
( V_178 == V_182 ) ) ) {
T_12 V_78 ;
if ( V_17 -> V_42 . type == V_183
|| V_17 -> V_42 . type == V_184 )
V_78 = V_17 -> V_52 . V_78 ;
else
V_78 = V_19 -> V_78 ;
V_46 = F_110 ( V_7 , V_78 ) ;
if ( ! V_46 )
V_46 = F_110 ( V_7 , V_185 ) ;
return V_46 ;
}
return & V_7 -> V_9 ;
}
static int F_111 ( struct V_45 * V_5 ,
struct V_23 * V_20 ,
union V_44 * V_17 ,
struct V_18 * V_19 ,
struct V_159 * V_186 ,
struct V_46 * V_46 )
{
struct V_187 * V_188 = F_112 ( V_5 , V_186 -> V_91 ) ;
if ( V_188 ) {
V_19 -> V_91 = V_186 -> V_91 ;
V_19 -> V_163 = V_186 -> V_88 - V_188 -> V_163 ;
V_188 -> V_163 = V_186 -> V_88 ;
}
if ( ! V_188 || V_188 -> V_11 == NULL ) {
++ V_5 -> V_189 . V_190 ;
return 0 ;
}
return V_20 -> V_19 ( V_20 , V_17 , V_19 , V_188 -> V_11 , V_46 ) ;
}
static int F_113 ( struct V_45 * V_5 ,
struct V_23 * V_20 ,
union V_44 * V_17 ,
struct V_18 * V_19 ,
struct V_46 * V_46 )
{
int V_8 = - V_191 ;
V_75 V_99 ;
for ( V_99 = 0 ; V_99 < V_19 -> F_53 . V_158 . V_130 ; V_99 ++ ) {
V_8 = F_111 ( V_5 , V_20 , V_17 , V_19 ,
& V_19 -> F_53 . V_158 . V_160 [ V_99 ] ,
V_46 ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static int
F_114 ( struct V_45 * V_5 ,
struct V_23 * V_20 ,
union V_44 * V_17 ,
struct V_18 * V_19 ,
struct V_10 * V_11 ,
struct V_46 * V_46 )
{
V_75 V_103 = V_11 -> V_12 . V_103 ;
V_75 V_104 = V_11 -> V_12 . V_104 ;
if ( ! ( V_103 & V_177 ) )
return V_20 -> V_19 ( V_20 , V_17 , V_19 , V_11 , V_46 ) ;
if ( V_104 & V_157 )
return F_113 ( V_5 , V_20 , V_17 , V_19 ,
V_46 ) ;
else
return F_111 ( V_5 , V_20 , V_17 , V_19 ,
& V_19 -> F_53 . V_161 , V_46 ) ;
}
static int F_115 ( struct V_7 * V_7 ,
struct V_45 * V_5 ,
union V_44 * V_17 ,
struct V_18 * V_19 ,
struct V_23 * V_20 , V_75 V_21 )
{
struct V_10 * V_11 ;
struct V_46 * V_46 ;
F_105 ( V_5 , V_17 , V_21 , V_19 ) ;
V_11 = F_116 ( V_5 , V_19 -> V_91 ) ;
V_46 = F_109 ( V_7 , V_17 , V_19 ) ;
switch ( V_17 -> V_42 . type ) {
case V_152 :
F_108 ( V_11 , V_17 , V_19 ) ;
if ( V_11 == NULL ) {
++ V_5 -> V_189 . V_190 ;
return 0 ;
}
if ( V_46 == NULL ) {
++ V_5 -> V_189 . V_192 ;
return 0 ;
}
return F_114 ( V_5 , V_20 , V_17 , V_19 , V_11 , V_46 ) ;
case V_183 :
return V_20 -> V_52 ( V_20 , V_17 , V_19 , V_46 ) ;
case V_184 :
if ( V_17 -> V_42 . V_162 & V_193 )
++ V_5 -> V_189 . V_194 ;
return V_20 -> V_53 ( V_20 , V_17 , V_19 , V_46 ) ;
case V_195 :
return V_20 -> V_54 ( V_20 , V_17 , V_19 , V_46 ) ;
case V_196 :
return V_20 -> V_55 ( V_20 , V_17 , V_19 , V_46 ) ;
case V_197 :
return V_20 -> exit ( V_20 , V_17 , V_19 , V_46 ) ;
case V_198 :
if ( V_20 -> V_56 == V_57 )
V_5 -> V_189 . V_199 += V_17 -> V_56 . V_56 ;
return V_20 -> V_56 ( V_20 , V_17 , V_19 , V_46 ) ;
case V_200 :
if ( V_20 -> V_58 == V_59 )
V_5 -> V_189 . V_201 += V_17 -> V_58 . V_56 ;
return V_20 -> V_58 ( V_20 , V_17 , V_19 , V_46 ) ;
case V_202 :
return V_20 -> F_53 ( V_20 , V_17 , V_19 , V_11 , V_46 ) ;
case V_203 :
return V_20 -> V_64 ( V_20 , V_17 , V_19 , V_46 ) ;
case V_204 :
return V_20 -> V_65 ( V_20 , V_17 , V_19 , V_46 ) ;
case V_205 :
return V_20 -> V_60 ( V_20 , V_17 , V_19 , V_46 ) ;
case V_206 :
return V_20 -> V_62 ( V_20 , V_17 , V_19 , V_46 ) ;
default:
++ V_5 -> V_189 . V_207 ;
return - 1 ;
}
}
static int F_23 ( struct V_1 * V_2 ,
union V_44 * V_17 ,
struct V_18 * V_19 ,
struct V_23 * V_20 ,
V_75 V_21 )
{
int V_8 ;
V_8 = F_117 ( V_2 , V_17 , V_19 , V_20 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 > 0 )
return 0 ;
return F_115 ( & V_2 -> V_7 , V_2 -> V_5 ,
V_17 , V_19 , V_20 , V_21 ) ;
}
static T_5 F_118 ( struct V_1 * V_2 ,
union V_44 * V_17 ,
V_75 V_21 )
{
struct V_14 * V_15 = & V_2 -> V_14 ;
struct V_23 * V_20 = V_2 -> V_20 ;
int V_47 = F_56 ( V_2 -> V_4 ) ;
int V_208 ;
F_105 ( V_2 -> V_5 , V_17 , V_21 , NULL ) ;
switch ( V_17 -> V_42 . type ) {
case V_209 :
V_208 = V_20 -> V_12 ( V_20 , V_17 , & V_2 -> V_5 ) ;
if ( V_208 == 0 ) {
F_8 ( V_2 ) ;
F_18 ( V_2 ) ;
}
return V_208 ;
case V_210 :
return 0 ;
case V_211 :
F_119 ( V_47 , V_21 , V_212 ) ;
return V_20 -> V_66 ( V_20 , V_17 , V_2 ) ;
case V_213 :
return V_20 -> V_67 ( V_20 , V_17 , V_2 ) ;
case V_214 :
return V_20 -> V_68 ( V_20 , V_17 , V_15 ) ;
case V_215 :
return V_20 -> V_70 ( V_20 , V_17 , V_2 ) ;
case V_216 :
return V_20 -> V_71 ( V_20 , V_17 , V_2 ) ;
case V_217 :
F_119 ( V_47 , V_21 + V_17 -> V_42 . V_51 , V_212 ) ;
return V_20 -> V_50 ( V_20 , V_17 , V_2 ) ;
case V_218 :
F_120 ( V_2 , V_17 ) ;
return V_20 -> V_72 ( V_20 , V_17 , V_2 ) ;
default:
return - V_191 ;
}
}
int F_121 ( struct V_1 * V_2 ,
union V_44 * V_17 ,
struct V_18 * V_19 )
{
struct V_45 * V_5 = V_2 -> V_5 ;
struct V_23 * V_20 = V_2 -> V_20 ;
F_122 ( & V_5 -> V_189 , V_17 -> V_42 . type ) ;
if ( V_17 -> V_42 . type >= V_219 )
return F_118 ( V_2 , V_17 , 0 ) ;
return F_115 ( & V_2 -> V_7 , V_5 , V_17 , V_19 , V_20 , 0 ) ;
}
static void F_123 ( union V_44 * V_17 , bool T_6 )
{
T_13 V_220 ;
V_220 = V_221 [ V_17 -> V_42 . type ] ;
if ( V_220 )
V_220 ( V_17 , T_6 ) ;
}
int F_124 ( struct V_1 * V_2 , T_3 V_21 ,
void * V_49 , T_10 V_222 ,
union V_44 * * V_223 ,
struct V_18 * V_19 )
{
union V_44 * V_17 ;
T_10 V_224 , V_225 ;
int V_47 ;
if ( V_2 -> V_226 && ! V_2 -> V_42 . V_227 ) {
V_17 = V_21 - V_2 -> V_228 +
V_2 -> V_229 ;
goto V_230;
}
if ( F_4 ( V_2 -> V_4 ) )
return - 1 ;
V_47 = F_56 ( V_2 -> V_4 ) ;
V_224 = sizeof( struct V_76 ) ;
if ( V_222 < V_224 )
return - 1 ;
if ( F_119 ( V_47 , V_21 , V_212 ) == ( T_3 ) - 1 ||
F_125 ( V_47 , V_49 , V_224 ) != ( T_4 ) V_224 )
return - 1 ;
V_17 = (union V_44 * ) V_49 ;
if ( V_2 -> V_42 . V_227 )
F_126 ( & V_17 -> V_42 ) ;
if ( V_17 -> V_42 . V_51 < V_224 || V_17 -> V_42 . V_51 > V_222 )
return - 1 ;
V_225 = V_17 -> V_42 . V_51 - V_224 ;
if ( F_125 ( V_47 , V_49 , V_225 ) != ( T_4 ) V_225 )
return - 1 ;
if ( V_2 -> V_42 . V_227 )
F_123 ( V_17 , F_33 ( V_2 -> V_5 ) ) ;
V_230:
if ( V_19 && V_17 -> V_42 . type < V_219 &&
F_22 ( V_2 -> V_5 , V_17 , V_19 ) )
return - 1 ;
* V_223 = V_17 ;
return 0 ;
}
static T_5 F_127 ( struct V_1 * V_2 ,
union V_44 * V_17 , V_75 V_21 )
{
struct V_45 * V_5 = V_2 -> V_5 ;
struct V_23 * V_20 = V_2 -> V_20 ;
struct V_18 V_19 ;
int V_8 ;
if ( V_2 -> V_42 . V_227 )
F_123 ( V_17 , F_33 ( V_5 ) ) ;
if ( V_17 -> V_42 . type >= V_231 )
return - V_191 ;
F_122 ( & V_5 -> V_189 , V_17 -> V_42 . type ) ;
if ( V_17 -> V_42 . type >= V_219 )
return F_118 ( V_2 , V_17 , V_21 ) ;
V_8 = F_22 ( V_5 , V_17 , & V_19 ) ;
if ( V_8 )
return V_8 ;
if ( V_20 -> V_14 ) {
V_8 = F_88 ( V_2 , V_17 , & V_19 , V_21 ) ;
if ( V_8 != - V_232 )
return V_8 ;
}
return F_23 ( V_2 , V_17 , & V_19 , V_20 ,
V_21 ) ;
}
void F_126 ( struct V_76 * V_77 )
{
V_77 -> type = F_64 ( V_77 -> type ) ;
V_77 -> V_162 = F_128 ( V_77 -> V_162 ) ;
V_77 -> V_51 = F_128 ( V_77 -> V_51 ) ;
}
struct V_233 * F_129 ( struct V_1 * V_2 , T_14 V_78 )
{
return F_130 ( & V_2 -> V_7 . V_9 , - 1 , V_78 ) ;
}
static struct V_233 * F_131 ( struct V_1 * V_2 )
{
struct V_233 * V_233 ;
V_233 = F_130 ( & V_2 -> V_7 . V_9 , 0 , 0 ) ;
if ( V_233 == NULL || F_132 ( V_233 , L_45 , 0 ) ) {
F_3 ( L_46 ) ;
V_233 = NULL ;
}
return V_233 ;
}
static void F_133 ( const struct V_1 * V_2 )
{
const struct V_234 * V_189 = & V_2 -> V_5 -> V_189 ;
const struct V_14 * V_15 = & V_2 -> V_14 ;
if ( V_2 -> V_20 -> V_56 == V_57 &&
V_189 -> V_235 [ V_198 ] != 0 ) {
F_134 ( L_47
L_48 ,
V_189 -> V_235 [ 0 ] ,
V_189 -> V_235 [ V_198 ] ) ;
}
if ( V_2 -> V_20 -> V_58 == V_59 ) {
double V_236 ;
V_236 = ( double ) V_189 -> V_201 /
( double ) ( V_189 -> V_235 [ V_152 ] + V_189 -> V_201 ) ;
if ( V_236 > 0.05 ) {
F_134 ( L_49 V_134 L_50 ,
V_189 -> V_235 [ V_152 ] + V_189 -> V_201 ,
V_236 * 100.0 ) ;
}
}
if ( V_189 -> V_207 != 0 ) {
F_134 ( L_51
L_52
L_53
L_54
L_55 ,
V_189 -> V_207 ) ;
}
if ( V_189 -> V_190 != 0 ) {
F_134 ( L_56 ,
V_189 -> V_190 ) ;
}
if ( V_189 -> V_237 != 0 ) {
F_134 ( L_57
L_58
L_59 ,
V_189 -> V_237 ,
V_189 -> V_235 [ V_152 ] ) ;
}
if ( V_189 -> V_192 != 0 ) {
F_134 ( L_60
L_61 ,
V_189 -> V_192 ) ;
}
if ( V_15 -> V_238 != 0 )
F_134 ( L_62 , V_15 -> V_238 ) ;
F_135 ( V_189 ) ;
if ( V_189 -> V_194 != 0 ) {
F_134 ( L_63
L_64
L_65
L_66
L_67
L_68
L_69 ,
V_189 -> V_194 ) ;
}
}
static int F_136 ( struct V_233 * V_233 ,
void * V_98 V_43 )
{
return F_137 ( V_233 ) ;
}
static int F_138 ( struct V_1 * V_2 )
{
return F_139 ( & V_2 -> V_7 ,
F_136 ,
NULL ) ;
}
static int F_140 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_14 ;
struct V_23 * V_20 = V_2 -> V_20 ;
int V_47 = F_56 ( V_2 -> V_4 ) ;
union V_44 * V_17 ;
T_15 V_51 , V_239 = 0 ;
void * V_49 = NULL ;
T_5 V_240 = 0 ;
V_75 V_241 ;
T_4 V_208 ;
void * V_98 ;
F_58 ( V_20 ) ;
V_241 = 0 ;
V_239 = sizeof( union V_44 ) ;
V_49 = malloc ( V_239 ) ;
if ( ! V_49 )
return - V_242 ;
V_243:
V_17 = V_49 ;
V_208 = F_125 ( V_47 , V_17 , sizeof( struct V_76 ) ) ;
if ( V_208 <= 0 ) {
if ( V_208 == 0 )
goto V_244;
F_3 ( L_70 ) ;
goto V_245;
}
if ( V_2 -> V_42 . V_227 )
F_126 ( & V_17 -> V_42 ) ;
V_51 = V_17 -> V_42 . V_51 ;
if ( V_51 < sizeof( struct V_76 ) ) {
F_3 ( L_71 ) ;
goto V_245;
}
if ( V_51 > V_239 ) {
void * V_246 = realloc ( V_49 , V_51 ) ;
if ( ! V_246 ) {
F_3 ( L_72 ) ;
goto V_245;
}
V_49 = V_246 ;
V_239 = V_51 ;
V_17 = V_49 ;
}
V_98 = V_17 ;
V_98 += sizeof( struct V_76 ) ;
if ( V_51 - sizeof( struct V_76 ) ) {
V_208 = F_125 ( V_47 , V_98 , V_51 - sizeof( struct V_76 ) ) ;
if ( V_208 <= 0 ) {
if ( V_208 == 0 ) {
F_3 ( L_73 ) ;
goto V_244;
}
F_3 ( L_74 ) ;
goto V_245;
}
}
if ( ( V_240 = F_127 ( V_2 , V_17 , V_241 ) ) < 0 ) {
F_3 ( L_37 V_135 L_75 ,
V_241 , V_17 -> V_42 . V_51 , V_17 -> V_42 . type ) ;
V_208 = - V_191 ;
goto V_245;
}
V_241 += V_51 ;
if ( V_240 > 0 )
V_241 += V_240 ;
if ( ! F_141 () )
goto V_243;
V_244:
V_208 = F_87 ( V_15 , V_247 ) ;
if ( V_208 )
goto V_245;
V_208 = F_142 ( V_2 , V_20 ) ;
if ( V_208 )
goto V_245;
V_208 = F_138 ( V_2 ) ;
V_245:
free ( V_49 ) ;
F_133 ( V_2 ) ;
F_143 ( & V_2 -> V_14 ) ;
F_144 ( V_2 ) ;
return V_208 ;
}
static union V_44 *
F_145 ( struct V_1 * V_2 ,
V_75 V_241 , T_10 V_248 , char * V_49 )
{
union V_44 * V_17 ;
if ( V_241 + sizeof( V_17 -> V_42 ) > V_248 )
return NULL ;
V_17 = (union V_44 * ) ( V_49 + V_241 ) ;
if ( V_2 -> V_42 . V_227 )
F_126 ( & V_17 -> V_42 ) ;
if ( V_241 + V_17 -> V_42 . V_51 > V_248 ) {
if ( V_2 -> V_42 . V_227 )
F_126 ( & V_17 -> V_42 ) ;
return NULL ;
}
return V_17 ;
}
static int F_146 ( struct V_1 * V_2 ,
V_75 V_249 , V_75 V_250 ,
V_75 V_251 )
{
struct V_14 * V_15 = & V_2 -> V_14 ;
struct V_23 * V_20 = V_2 -> V_20 ;
int V_47 = F_56 ( V_2 -> V_4 ) ;
V_75 V_241 , V_252 , V_21 , V_253 , V_51 ;
int V_208 , V_254 , V_255 , V_256 = 0 ;
T_10 V_248 ;
char * V_49 , * V_257 [ V_258 ] ;
union V_44 * V_17 ;
struct V_259 V_260 ;
T_5 V_240 ;
F_58 ( V_20 ) ;
V_252 = V_261 * ( V_249 / V_261 ) ;
V_21 = V_252 ;
V_241 = V_249 - V_252 ;
if ( V_250 && ( V_249 + V_250 < V_251 ) )
V_251 = V_249 + V_250 ;
F_147 ( & V_260 , V_251 , L_76 ) ;
V_248 = V_262 ;
if ( V_248 > V_251 ) {
V_248 = V_251 ;
V_2 -> V_226 = true ;
}
memset ( V_257 , 0 , sizeof( V_257 ) ) ;
V_254 = V_263 ;
V_255 = V_264 ;
if ( V_2 -> V_42 . V_227 ) {
V_254 |= V_265 ;
V_255 = V_266 ;
}
V_267:
V_49 = V_52 ( NULL , V_248 , V_254 , V_255 , V_47 ,
V_21 ) ;
if ( V_49 == V_268 ) {
F_3 ( L_77 ) ;
V_208 = - V_242 ;
goto V_245;
}
V_257 [ V_256 ] = V_49 ;
V_256 = ( V_256 + 1 ) & ( F_148 ( V_257 ) - 1 ) ;
V_253 = V_21 + V_241 ;
if ( V_2 -> V_226 ) {
V_2 -> V_229 = V_49 ;
V_2 -> V_228 = V_21 ;
}
V_243:
V_17 = F_145 ( V_2 , V_241 , V_248 , V_49 ) ;
if ( ! V_17 ) {
if ( V_257 [ V_256 ] ) {
F_149 ( V_257 [ V_256 ] , V_248 ) ;
V_257 [ V_256 ] = NULL ;
}
V_252 = V_261 * ( V_241 / V_261 ) ;
V_21 += V_252 ;
V_241 -= V_252 ;
goto V_267;
}
V_51 = V_17 -> V_42 . V_51 ;
if ( V_51 < sizeof( struct V_76 ) ||
( V_240 = F_127 ( V_2 , V_17 , V_253 ) ) < 0 ) {
F_3 ( L_37 V_135 L_75 ,
V_21 + V_241 , V_17 -> V_42 . V_51 ,
V_17 -> V_42 . type ) ;
V_208 = - V_191 ;
goto V_245;
}
if ( V_240 )
V_51 += V_240 ;
V_241 += V_51 ;
V_253 += V_51 ;
F_150 ( & V_260 , V_51 ) ;
if ( F_141 () )
goto V_24;
if ( V_253 < V_251 )
goto V_243;
V_24:
V_208 = F_87 ( V_15 , V_247 ) ;
if ( V_208 )
goto V_245;
V_208 = F_142 ( V_2 , V_20 ) ;
if ( V_208 )
goto V_245;
V_208 = F_138 ( V_2 ) ;
V_245:
F_151 () ;
F_133 ( V_2 ) ;
F_143 ( & V_2 -> V_14 ) ;
F_144 ( V_2 ) ;
V_2 -> V_226 = false ;
return V_208 ;
}
int F_152 ( struct V_1 * V_2 )
{
V_75 V_51 = F_153 ( V_2 -> V_4 ) ;
int V_208 ;
if ( F_131 ( V_2 ) == NULL )
return - V_269 ;
if ( ! F_4 ( V_2 -> V_4 ) )
V_208 = F_146 ( V_2 ,
V_2 -> V_42 . V_249 ,
V_2 -> V_42 . V_250 , V_51 ) ;
else
V_208 = F_140 ( V_2 ) ;
return V_208 ;
}
bool F_154 ( struct V_1 * V_2 , const char * V_270 )
{
struct V_10 * V_11 ;
F_17 (session->evlist, evsel) {
if ( V_11 -> V_12 . type == V_271 )
return true ;
}
F_3 ( L_78 , V_270 ) ;
return false ;
}
int F_155 ( struct V_272 * * V_273 ,
const char * V_274 , V_75 V_164 )
{
char * V_275 ;
enum V_276 V_99 ;
struct V_277 * V_278 ;
V_278 = F_25 ( sizeof( struct V_277 ) ) ;
if ( V_278 == NULL )
return - V_269 ;
V_278 -> V_279 = F_156 ( V_274 ) ;
if ( V_278 -> V_279 == NULL ) {
free ( V_278 ) ;
return - V_269 ;
}
V_275 = strchr ( V_278 -> V_279 , ']' ) ;
if ( V_275 )
* V_275 = '\0' ;
V_278 -> V_164 = V_164 ;
for ( V_99 = 0 ; V_99 < V_280 ; ++ V_99 ) {
struct V_281 * V_281 = F_157 ( V_273 [ V_99 ] ) ;
if ( ! V_281 )
continue;
V_281 -> V_277 = V_278 ;
}
return 0 ;
}
T_10 F_158 ( struct V_1 * V_2 , T_16 * V_282 )
{
return F_159 ( & V_2 -> V_7 , V_282 ) ;
}
T_10 F_160 ( struct V_1 * V_2 , T_16 * V_282 ,
bool (V_240)( struct V_283 * V_283 , int V_284 ) , int V_284 )
{
return F_161 ( & V_2 -> V_7 , V_282 , V_240 , V_284 ) ;
}
T_10 F_162 ( struct V_1 * V_2 , T_16 * V_282 )
{
T_10 V_8 ;
const char * V_270 = L_79 ;
if ( F_163 ( & V_2 -> V_42 , V_285 ) )
V_270 = L_80 ;
V_8 = fprintf ( V_282 , L_81 , V_270 ) ;
V_8 += F_164 ( & V_2 -> V_5 -> V_189 , V_282 ) ;
return V_8 ;
}
T_10 F_165 ( struct V_1 * V_2 , T_16 * V_282 )
{
return F_166 ( & V_2 -> V_7 . V_9 , V_282 ) ;
}
struct V_10 * F_167 ( struct V_1 * V_2 ,
unsigned int type )
{
struct V_10 * V_286 ;
F_17 (session->evlist, pos) {
if ( V_286 -> V_12 . type == type )
return V_286 ;
}
return NULL ;
}
void F_168 ( struct V_10 * V_11 , struct V_18 * V_19 ,
struct V_287 * V_288 ,
unsigned int V_289 , unsigned int V_290 )
{
struct V_291 * V_292 ;
int V_293 = V_289 & V_294 ;
int V_295 = V_289 & V_296 ;
int V_297 = V_289 & V_298 ;
int V_299 = V_289 & V_300 ;
int V_301 = V_289 & V_302 ;
int V_303 = V_289 & V_304 ;
char V_124 = V_301 ? ' ' : '\t' ;
if ( V_305 . V_306 && V_19 -> V_126 ) {
struct V_287 V_307 ;
if ( F_169 ( V_288 -> V_233 , V_11 ,
V_19 , NULL , NULL ,
V_308 ) != 0 ) {
if ( V_309 )
error ( L_82 ) ;
return;
}
F_170 ( & V_310 ) ;
if ( V_299 )
V_307 = * V_288 ;
while ( V_290 ) {
V_75 V_164 = 0 ;
V_292 = F_171 ( & V_310 ) ;
if ( ! V_292 )
break;
if ( V_292 -> V_311 && V_292 -> V_311 -> V_312 )
goto V_313;
if ( V_293 )
printf ( L_83 V_135 , V_124 , V_292 -> V_121 ) ;
if ( V_292 -> V_272 )
V_164 = V_292 -> V_272 -> V_314 ( V_292 -> V_272 , V_292 -> V_121 ) ;
if ( V_295 ) {
printf ( L_28 ) ;
if ( V_299 ) {
V_307 . V_164 = V_164 ;
V_307 . V_272 = V_292 -> V_272 ;
F_172 ( V_292 -> V_311 , & V_307 , stdout ) ;
} else
F_173 ( V_292 -> V_311 , stdout ) ;
}
if ( V_297 ) {
printf ( L_84 ) ;
F_174 ( V_292 -> V_272 , stdout ) ;
printf ( L_85 ) ;
}
if ( V_303 )
F_175 ( V_292 -> V_272 , V_164 , L_86 ,
stdout ) ;
if ( ! V_301 )
printf ( L_9 ) ;
V_290 -- ;
V_313:
F_176 ( & V_310 ) ;
}
} else {
if ( V_288 -> V_311 && V_288 -> V_311 -> V_312 )
return;
if ( V_293 )
printf ( L_87 V_135 , V_19 -> V_121 ) ;
if ( V_295 ) {
printf ( L_28 ) ;
if ( V_299 )
F_172 ( V_288 -> V_311 , V_288 ,
stdout ) ;
else
F_173 ( V_288 -> V_311 , stdout ) ;
}
if ( V_297 ) {
printf ( L_84 ) ;
F_174 ( V_288 -> V_272 , stdout ) ;
printf ( L_85 ) ;
}
if ( V_303 )
F_175 ( V_288 -> V_272 , V_288 -> V_164 , L_86 , stdout ) ;
}
}
int F_177 ( struct V_1 * V_2 ,
const char * V_315 , unsigned long * V_316 )
{
int V_99 , V_208 = - 1 ;
struct V_317 * V_272 ;
for ( V_99 = 0 ; V_99 < V_318 ; ++ V_99 ) {
struct V_10 * V_11 ;
V_11 = F_167 ( V_2 , V_99 ) ;
if ( ! V_11 )
continue;
if ( ! ( V_11 -> V_12 . V_103 & V_153 ) ) {
F_3 ( L_88
L_89 ) ;
return - 1 ;
}
}
V_272 = F_178 ( V_315 ) ;
if ( V_272 == NULL ) {
F_3 ( L_90 ) ;
return - 1 ;
}
for ( V_99 = 0 ; V_99 < V_272 -> V_130 ; V_99 ++ ) {
int V_119 = V_272 -> V_272 [ V_99 ] ;
if ( V_119 >= V_319 ) {
F_3 ( L_91
L_92 , V_119 ) ;
goto V_320;
}
F_179 ( V_119 , V_316 ) ;
}
V_208 = 0 ;
V_320:
F_180 ( V_272 ) ;
return V_208 ;
}
void F_181 ( struct V_1 * V_2 , T_16 * V_282 ,
bool V_321 )
{
struct V_322 V_323 ;
int V_47 , V_8 ;
if ( V_2 == NULL || V_282 == NULL )
return;
V_47 = F_56 ( V_2 -> V_4 ) ;
V_8 = F_182 ( V_47 , & V_323 ) ;
if ( V_8 == - 1 )
return;
fprintf ( V_282 , L_93 ) ;
fprintf ( V_282 , L_94 , ctime ( & V_323 . V_324 ) ) ;
F_183 ( V_2 , V_282 , V_321 ) ;
fprintf ( V_282 , L_95 ) ;
}
int F_184 ( struct V_1 * V_2 ,
const struct V_325 * V_326 ,
T_10 V_327 )
{
struct V_10 * V_11 ;
T_10 V_99 ;
int V_208 ;
for ( V_99 = 0 ; V_99 < V_327 ; V_99 ++ ) {
V_11 = F_185 ( V_2 -> V_5 , V_326 [ V_99 ] . V_279 ) ;
if ( V_11 == NULL )
continue;
V_208 = - V_328 ;
if ( V_11 -> V_329 != NULL )
goto V_24;
V_11 -> V_329 = V_326 [ V_99 ] . V_329 ;
}
V_208 = 0 ;
V_24:
return V_208 ;
}
int F_186 ( struct V_23 * V_20 V_43 ,
union V_44 * V_17 ,
struct V_1 * V_2 )
{
struct V_45 * V_5 = V_2 -> V_5 ;
struct V_330 * V_331 = & V_17 -> V_70 ;
T_10 V_99 , V_130 , V_332 ;
V_332 = ( V_331 -> V_42 . V_51 - sizeof( struct V_330 ) ) /
sizeof( struct V_333 ) ;
V_130 = V_331 -> V_130 ;
if ( V_130 > V_332 )
return - V_191 ;
if ( V_122 )
fprintf ( stdout , L_96 , V_130 ) ;
for ( V_99 = 0 ; V_99 < V_130 ; V_99 ++ ) {
struct V_333 * V_334 = & V_331 -> V_136 [ V_99 ] ;
struct V_187 * V_188 ;
if ( V_122 ) {
fprintf ( stdout , L_97 V_134 , V_334 -> V_91 ) ;
fprintf ( stdout , L_98 V_134 , V_334 -> V_118 ) ;
fprintf ( stdout , L_99 V_335 , V_334 -> V_119 ) ;
fprintf ( stdout , L_100 V_335 L_9 , V_334 -> V_79 ) ;
}
V_188 = F_112 ( V_5 , V_334 -> V_91 ) ;
if ( ! V_188 )
return - V_336 ;
V_188 -> V_118 = V_334 -> V_118 ;
V_188 -> V_119 = V_334 -> V_119 ;
V_188 -> V_79 = V_334 -> V_79 ;
}
return 0 ;
}
int F_187 ( struct V_23 * V_20 ,
T_17 V_337 ,
struct V_45 * V_5 ,
struct V_46 * V_46 )
{
union V_44 * V_338 ;
struct V_10 * V_11 ;
T_10 V_130 = 0 , V_99 = 0 , T_9 , V_332 , V_48 ;
int V_208 ;
F_188 ( L_101 ) ;
V_332 = ( V_339 - sizeof( struct V_330 ) ) /
sizeof( struct V_333 ) ;
F_17 (evlist, evsel)
V_130 += V_11 -> V_340 ;
V_48 = V_130 > V_332 ? V_332 : V_130 ;
T_9 = sizeof( struct V_330 ) + V_48 * sizeof( struct V_333 ) ;
V_338 = F_25 ( T_9 ) ;
if ( ! V_338 )
return - V_269 ;
V_338 -> V_70 . V_42 . type = V_215 ;
V_338 -> V_70 . V_42 . V_51 = T_9 ;
V_338 -> V_70 . V_130 = V_48 ;
F_17 (evlist, evsel) {
T_12 V_341 ;
for ( V_341 = 0 ; V_341 < V_11 -> V_340 ; V_341 ++ ) {
struct V_333 * V_334 ;
struct V_187 * V_188 ;
if ( V_99 >= V_48 ) {
V_208 = V_337 ( V_20 , V_338 , NULL , V_46 ) ;
if ( V_208 )
goto V_245;
V_130 -= V_48 ;
V_99 = 0 ;
}
V_334 = & V_338 -> V_70 . V_136 [ V_99 ++ ] ;
V_334 -> V_91 = V_11 -> V_91 [ V_341 ] ;
V_188 = F_112 ( V_5 , V_334 -> V_91 ) ;
if ( ! V_188 ) {
free ( V_338 ) ;
return - V_336 ;
}
V_334 -> V_118 = V_188 -> V_118 ;
V_334 -> V_119 = V_188 -> V_119 ;
V_334 -> V_79 = V_188 -> V_79 ;
}
}
T_9 = sizeof( struct V_330 ) + V_130 * sizeof( struct V_333 ) ;
V_338 -> V_70 . V_42 . V_51 = T_9 ;
V_338 -> V_70 . V_130 = V_130 ;
V_208 = V_337 ( V_20 , V_338 , NULL , V_46 ) ;
V_245:
free ( V_338 ) ;
return V_208 ;
}
