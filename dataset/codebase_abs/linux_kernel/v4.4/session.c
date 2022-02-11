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
} else {
V_2 -> V_7 . V_9 . V_28 = & V_29 ;
}
if ( ! V_4 || F_31 ( V_4 ) ) {
if ( F_11 ( V_2 ) < 0 )
F_32 ( L_6 ) ;
}
if ( V_20 && V_20 -> V_30 &&
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
void F_36 ( struct V_1 * V_2 )
{
F_39 ( V_2 ) ;
F_40 ( & V_2 -> V_25 ) ;
F_14 ( V_2 ) ;
F_37 ( V_2 ) ;
F_41 ( & V_2 -> V_31 . V_28 ) ;
F_42 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_4 )
F_35 ( V_2 -> V_4 ) ;
free ( V_2 ) ;
}
static int F_43 ( struct V_23 * V_20
V_32 ,
union V_33 * V_17
V_32 ,
struct V_1 * V_2
V_32 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_44 ( struct V_23 * V_20 V_32 ,
union V_33 * V_17 V_32 ,
struct V_34 * * T_2
V_32 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_45 ( struct V_23 * V_20 V_32 ,
union V_33 * V_17 V_32 ,
struct V_18 * V_19 V_32 ,
struct V_10 * V_11 V_32 ,
struct V_35 * V_35 V_32 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_46 ( struct V_23 * V_20 V_32 ,
union V_33 * V_17 V_32 ,
struct V_18 * V_19 V_32 ,
struct V_35 * V_35 V_32 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_47 ( struct V_23 * V_20 V_32 ,
union V_33 * V_17 V_32 ,
struct V_1 * V_2 V_32 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_48 ( struct V_23 * V_20 V_32 ,
union V_33 * V_17 V_32 ,
struct V_14 * V_15 V_32 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_49 ( struct V_23 * V_20 V_32 ,
union V_33 * V_17 V_32 ,
struct V_1 * V_1
V_32 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_50 ( struct V_23 * V_20 V_32 ,
union V_33 * V_17 V_32 ,
struct V_1 * V_2 V_32 )
{
F_34 ( L_8 ) ;
return 0 ;
}
static int F_51 ( int V_36 , T_3 V_37 )
{
char V_38 [ 4096 ] ;
T_4 V_8 ;
while ( V_37 > 0 ) {
V_8 = F_52 ( V_36 , V_38 , F_53 ( V_37 , ( T_3 ) sizeof( V_38 ) ) ) ;
if ( V_8 <= 0 )
return V_8 ;
V_37 -= V_8 ;
}
return 0 ;
}
static T_5 F_54 ( struct V_23 * V_20 V_32 ,
union V_33 * V_17 ,
struct V_1 * V_2
V_32 )
{
F_34 ( L_8 ) ;
if ( F_4 ( V_2 -> V_4 ) )
F_51 ( F_55 ( V_2 -> V_4 ) , V_17 -> V_39 . V_40 ) ;
return V_17 -> V_39 . V_40 ;
}
static
int F_56 ( struct V_23 * V_20 V_32 ,
union V_33 * V_17 V_32 ,
struct V_1 * V_2 V_32 )
{
F_34 ( L_8 ) ;
return 0 ;
}
void F_57 ( struct V_23 * V_20 )
{
if ( V_20 -> V_19 == NULL )
V_20 -> V_19 = F_45 ;
if ( V_20 -> V_41 == NULL )
V_20 -> V_41 = F_46 ;
if ( V_20 -> V_42 == NULL )
V_20 -> V_42 = F_46 ;
if ( V_20 -> V_43 == NULL )
V_20 -> V_43 = F_46 ;
if ( V_20 -> V_44 == NULL )
V_20 -> V_44 = F_46 ;
if ( V_20 -> exit == NULL )
V_20 -> exit = F_46 ;
if ( V_20 -> V_45 == NULL )
V_20 -> V_45 = V_46 ;
if ( V_20 -> V_47 == NULL )
V_20 -> V_47 = V_48 ;
if ( V_20 -> V_49 == NULL )
V_20 -> V_49 = V_50 ;
if ( V_20 -> V_51 == NULL )
V_20 -> V_51 = V_52 ;
if ( V_20 -> V_53 == NULL )
V_20 -> V_53 = V_54 ;
if ( V_20 -> F_52 == NULL )
V_20 -> F_52 = F_45 ;
if ( V_20 -> V_55 == NULL )
V_20 -> V_55 = F_46 ;
if ( V_20 -> V_56 == NULL )
V_20 -> V_56 = F_46 ;
if ( V_20 -> V_12 == NULL )
V_20 -> V_12 = F_44 ;
if ( V_20 -> V_57 == NULL )
V_20 -> V_57 = F_43 ;
if ( V_20 -> V_58 == NULL )
V_20 -> V_58 = F_47 ;
if ( V_20 -> V_59 == NULL ) {
if ( V_20 -> V_14 )
V_20 -> V_59 = V_60 ;
else
V_20 -> V_59 = F_48 ;
}
if ( V_20 -> V_61 == NULL )
V_20 -> V_61 = F_49 ;
if ( V_20 -> V_62 == NULL )
V_20 -> V_62 = F_50 ;
if ( V_20 -> V_39 == NULL )
V_20 -> V_39 = F_54 ;
if ( V_20 -> V_63 == NULL )
V_20 -> V_63 = F_56 ;
}
static void F_58 ( union V_33 * V_17 , void * V_64 )
{
void * V_65 = ( void * ) V_17 + V_17 -> V_31 . V_40 ;
int V_40 = V_65 - V_64 ;
F_59 ( V_40 % sizeof( V_66 ) ) ;
F_60 ( V_64 , V_40 ) ;
}
static void F_61 ( union V_33 * V_17 ,
bool T_6 V_32 )
{
struct V_67 * V_68 = & V_17 -> V_31 ;
F_60 ( V_68 + 1 , V_17 -> V_31 . V_40 - sizeof( * V_68 ) ) ;
}
static void F_62 ( union V_33 * V_17 , bool T_6 )
{
V_17 -> V_43 . V_69 = F_63 ( V_17 -> V_43 . V_69 ) ;
V_17 -> V_43 . V_70 = F_63 ( V_17 -> V_43 . V_70 ) ;
if ( T_6 ) {
void * V_64 = & V_17 -> V_43 . V_43 ;
V_64 += F_64 ( strlen ( V_64 ) + 1 , sizeof( V_66 ) ) ;
F_58 ( V_17 , V_64 ) ;
}
}
static void F_65 ( union V_33 * V_17 ,
bool T_6 )
{
V_17 -> V_41 . V_69 = F_63 ( V_17 -> V_41 . V_69 ) ;
V_17 -> V_41 . V_70 = F_63 ( V_17 -> V_41 . V_70 ) ;
V_17 -> V_41 . V_71 = F_66 ( V_17 -> V_41 . V_71 ) ;
V_17 -> V_41 . V_72 = F_66 ( V_17 -> V_41 . V_72 ) ;
V_17 -> V_41 . V_73 = F_66 ( V_17 -> V_41 . V_73 ) ;
if ( T_6 ) {
void * V_64 = & V_17 -> V_41 . V_74 ;
V_64 += F_64 ( strlen ( V_64 ) + 1 , sizeof( V_66 ) ) ;
F_58 ( V_17 , V_64 ) ;
}
}
static void F_67 ( union V_33 * V_17 ,
bool T_6 )
{
V_17 -> V_42 . V_69 = F_63 ( V_17 -> V_42 . V_69 ) ;
V_17 -> V_42 . V_70 = F_63 ( V_17 -> V_42 . V_70 ) ;
V_17 -> V_42 . V_71 = F_66 ( V_17 -> V_42 . V_71 ) ;
V_17 -> V_42 . V_72 = F_66 ( V_17 -> V_42 . V_72 ) ;
V_17 -> V_42 . V_73 = F_66 ( V_17 -> V_42 . V_73 ) ;
V_17 -> V_42 . V_75 = F_63 ( V_17 -> V_42 . V_75 ) ;
V_17 -> V_42 . F_53 = F_63 ( V_17 -> V_42 . F_53 ) ;
V_17 -> V_42 . V_76 = F_66 ( V_17 -> V_42 . V_76 ) ;
if ( T_6 ) {
void * V_64 = & V_17 -> V_42 . V_74 ;
V_64 += F_64 ( strlen ( V_64 ) + 1 , sizeof( V_66 ) ) ;
F_58 ( V_17 , V_64 ) ;
}
}
static void F_68 ( union V_33 * V_17 , bool T_6 )
{
V_17 -> V_44 . V_69 = F_63 ( V_17 -> V_44 . V_69 ) ;
V_17 -> V_44 . V_70 = F_63 ( V_17 -> V_44 . V_70 ) ;
V_17 -> V_44 . V_77 = F_63 ( V_17 -> V_44 . V_77 ) ;
V_17 -> V_44 . V_78 = F_63 ( V_17 -> V_44 . V_78 ) ;
V_17 -> V_44 . time = F_66 ( V_17 -> V_44 . time ) ;
if ( T_6 )
F_58 ( V_17 , & V_17 -> V_44 + 1 ) ;
}
static void F_69 ( union V_33 * V_17 , bool T_6 )
{
V_17 -> F_52 . V_69 = F_63 ( V_17 -> F_52 . V_69 ) ;
V_17 -> F_52 . V_70 = F_63 ( V_17 -> F_52 . V_70 ) ;
V_17 -> F_52 . V_79 = F_66 ( V_17 -> F_52 . V_79 ) ;
V_17 -> F_52 . V_80 = F_66 ( V_17 -> F_52 . V_80 ) ;
V_17 -> F_52 . V_81 = F_66 ( V_17 -> F_52 . V_81 ) ;
V_17 -> F_52 . V_82 = F_66 ( V_17 -> F_52 . V_82 ) ;
if ( T_6 )
F_58 ( V_17 , & V_17 -> F_52 + 1 ) ;
}
static void F_70 ( union V_33 * V_17 , bool T_6 )
{
V_17 -> V_49 . V_83 = F_66 ( V_17 -> V_49 . V_83 ) ;
V_17 -> V_49 . V_84 = F_66 ( V_17 -> V_49 . V_84 ) ;
V_17 -> V_49 . V_85 = F_66 ( V_17 -> V_49 . V_85 ) ;
if ( T_6 )
F_58 ( V_17 , & V_17 -> V_49 + 1 ) ;
}
static void F_71 ( union V_33 * V_17 ,
bool T_6 )
{
V_17 -> V_51 . V_69 = F_63 ( V_17 -> V_51 . V_69 ) ;
V_17 -> V_51 . V_70 = F_63 ( V_17 -> V_51 . V_70 ) ;
if ( T_6 )
F_58 ( V_17 , & V_17 -> V_51 + 1 ) ;
}
static void F_72 ( union V_33 * V_17 , bool T_6 )
{
if ( V_17 -> V_31 . type == V_86 ) {
V_17 -> V_53 . V_87 =
F_63 ( V_17 -> V_53 . V_87 ) ;
V_17 -> V_53 . V_88 =
F_63 ( V_17 -> V_53 . V_88 ) ;
}
if ( T_6 )
F_58 ( V_17 , & V_17 -> V_53 + 1 ) ;
}
static void F_73 ( union V_33 * V_17 ,
bool T_6 )
{
V_17 -> V_55 . time = F_66 ( V_17 -> V_55 . time ) ;
V_17 -> V_55 . V_82 = F_66 ( V_17 -> V_55 . V_82 ) ;
V_17 -> V_55 . V_89 = F_66 ( V_17 -> V_55 . V_89 ) ;
if ( T_6 )
F_58 ( V_17 , & V_17 -> V_55 + 1 ) ;
}
static T_7 F_74 ( T_7 V_90 )
{
int V_91 = ( V_90 >> 4 ) | ( ( V_90 & 0xf ) << 4 ) ;
V_91 = ( ( V_91 & 0xcc ) >> 2 ) | ( ( V_91 & 0x33 ) << 2 ) ;
V_91 = ( ( V_91 & 0xaa ) >> 1 ) | ( ( V_91 & 0x55 ) << 1 ) ;
return ( T_7 ) V_91 ;
}
static void F_75 ( T_7 * V_92 , unsigned V_72 )
{
unsigned V_93 ;
for ( V_93 = 0 ; V_93 < V_72 ; V_93 ++ ) {
* V_92 = F_74 ( * V_92 ) ;
V_92 ++ ;
}
}
void F_76 ( struct V_94 * V_12 )
{
V_12 -> type = F_63 ( V_12 -> type ) ;
V_12 -> V_40 = F_63 ( V_12 -> V_40 ) ;
#define F_77 ( T_8 , V_37 ) \
(attr->size > (offsetof(struct perf_event_attr, f) + \
sizeof(attr->f) * (n)))
#define F_78 ( T_8 , T_9 ) \
do { \
if (bswap_safe(f, 0)) \
attr->f = bswap_##sz(attr->f); \
} while(0)
#define F_79 ( T_8 ) bswap_field(f, 32)
#define F_80 ( T_8 ) bswap_field(f, 64)
F_80 ( V_95 ) ;
F_80 ( V_96 ) ;
F_80 ( V_97 ) ;
F_80 ( V_98 ) ;
F_79 ( V_99 ) ;
F_79 ( V_100 ) ;
F_80 ( V_101 ) ;
F_80 ( V_102 ) ;
F_80 ( V_103 ) ;
F_80 ( V_104 ) ;
F_79 ( V_105 ) ;
F_79 ( V_106 ) ;
if ( F_77 ( V_98 , 1 ) )
F_75 ( ( T_7 * ) ( & V_12 -> V_98 + 1 ) ,
sizeof( V_66 ) ) ;
#undef F_80
#undef F_79
#undef F_78
#undef F_77
}
static void F_81 ( union V_33 * V_17 ,
bool T_6 V_32 )
{
T_10 V_40 ;
F_76 ( & V_17 -> V_12 . V_12 ) ;
V_40 = V_17 -> V_31 . V_40 ;
V_40 -= ( void * ) & V_17 -> V_12 . V_82 - ( void * ) V_17 ;
F_60 ( V_17 -> V_12 . V_82 , V_40 ) ;
}
static void F_82 ( union V_33 * V_17 ,
bool T_6 V_32 )
{
V_17 -> V_107 . V_107 . V_108 =
F_66 ( V_17 -> V_107 . V_107 . V_108 ) ;
}
static void F_83 ( union V_33 * V_17 ,
bool T_6 V_32 )
{
V_17 -> V_57 . V_40 = F_63 ( V_17 -> V_57 . V_40 ) ;
}
static void F_84 ( union V_33 * V_17 ,
bool T_6 V_32 )
{
T_10 V_40 ;
V_17 -> V_62 . type = F_63 ( V_17 -> V_62 . type ) ;
V_40 = V_17 -> V_31 . V_40 ;
V_40 -= ( void * ) & V_17 -> V_62 . V_109 - ( void * ) V_17 ;
F_60 ( V_17 -> V_62 . V_109 , V_40 ) ;
}
static void F_85 ( union V_33 * V_17 ,
bool T_6 V_32 )
{
V_17 -> V_39 . V_40 = F_66 ( V_17 -> V_39 . V_40 ) ;
V_17 -> V_39 . V_110 = F_66 ( V_17 -> V_39 . V_110 ) ;
V_17 -> V_39 . V_111 = F_66 ( V_17 -> V_39 . V_111 ) ;
V_17 -> V_39 . V_112 = F_63 ( V_17 -> V_39 . V_112 ) ;
V_17 -> V_39 . V_70 = F_63 ( V_17 -> V_39 . V_70 ) ;
V_17 -> V_39 . V_113 = F_63 ( V_17 -> V_39 . V_113 ) ;
}
static void F_86 ( union V_33 * V_17 ,
bool T_6 V_32 )
{
V_17 -> V_63 . type = F_63 ( V_17 -> V_63 . type ) ;
V_17 -> V_63 . V_114 = F_63 ( V_17 -> V_63 . V_114 ) ;
V_17 -> V_63 . V_113 = F_63 ( V_17 -> V_63 . V_113 ) ;
V_17 -> V_63 . V_69 = F_63 ( V_17 -> V_63 . V_69 ) ;
V_17 -> V_63 . V_70 = F_63 ( V_17 -> V_63 . V_70 ) ;
V_17 -> V_63 . V_115 = F_66 ( V_17 -> V_63 . V_115 ) ;
}
static int V_60 ( struct V_23 * V_20 V_32 ,
union V_33 * V_17 V_32 ,
struct V_14 * V_15 )
{
if ( V_116 )
fprintf ( stdout , L_9 ) ;
return F_87 ( V_15 , V_117 ) ;
}
int F_88 ( struct V_1 * V_118 , union V_33 * V_17 ,
struct V_18 * V_19 , V_66 V_21 )
{
return F_89 ( & V_118 -> V_14 , V_17 , V_19 , V_21 ) ;
}
static void F_90 ( struct V_18 * V_19 )
{
struct V_119 * V_120 = V_19 -> V_120 ;
struct V_121 * V_122 = V_19 -> V_121 ;
V_66 V_123 = V_120 -> V_124 ;
unsigned int V_93 ;
for ( V_93 = 0 ; V_93 < V_123 ; V_93 ++ ) {
if ( V_120 -> V_125 [ V_93 ] == V_126 )
break;
}
if ( ( V_93 != V_123 ) && V_122 -> V_124 ) {
V_66 V_127 ;
V_127 = V_93 + 1 + V_122 -> V_124 + 1 ;
V_123 = V_93 + 1 ;
printf ( L_10 V_128 L_9 , V_127 ) ;
for ( V_93 = 0 ; V_93 < V_123 ; V_93 ++ )
printf ( L_11 V_129 L_9 ,
V_93 , V_120 -> V_125 [ V_93 ] ) ;
printf ( L_11 V_129 L_9 ,
( int ) ( V_123 ) , V_122 -> V_130 [ 0 ] . V_131 ) ;
for ( V_93 = 0 ; V_93 < V_122 -> V_124 ; V_93 ++ )
printf ( L_11 V_129 L_9 ,
( int ) ( V_93 + V_123 + 1 ) , V_122 -> V_130 [ V_93 ] . V_132 ) ;
}
}
static void F_91 ( struct V_10 * V_11 ,
struct V_18 * V_19 )
{
unsigned int V_93 ;
struct V_119 * V_120 = V_19 -> V_120 ;
if ( F_92 ( V_11 ) )
F_90 ( V_19 ) ;
printf ( L_12 V_128 L_9 , V_120 -> V_124 ) ;
for ( V_93 = 0 ; V_93 < V_120 -> V_124 ; V_93 ++ )
printf ( L_11 V_129 L_9 ,
V_93 , V_120 -> V_125 [ V_93 ] ) ;
}
static void F_93 ( struct V_18 * V_19 )
{
T_11 V_93 ;
printf ( L_13 V_128 L_9 , V_19 -> V_121 -> V_124 ) ;
for ( V_93 = 0 ; V_93 < V_19 -> V_121 -> V_124 ; V_93 ++ ) {
struct V_133 * V_134 = & V_19 -> V_121 -> V_130 [ V_93 ] ;
printf ( L_14 V_128 L_15 V_129 L_16 V_129 L_17 ,
V_93 , V_134 -> V_132 , V_134 -> V_131 ,
V_134 -> V_85 . V_135 ,
V_134 -> V_85 . V_136 ? L_18 : L_19 ,
V_134 -> V_85 . V_137 ? L_20 : L_19 ,
V_134 -> V_85 . abort ? L_21 : L_19 ,
V_134 -> V_85 . V_138 ? L_22 : L_19 ,
( unsigned ) V_134 -> V_85 . V_139 ) ;
}
}
static void F_94 ( V_66 V_140 , V_66 * V_141 )
{
unsigned V_142 , V_93 = 0 ;
F_95 (rid, (unsigned long *) &mask, sizeof(mask) * 8 ) {
V_66 V_143 = V_141 [ V_93 ++ ] ;
printf ( L_23 V_129 L_9 ,
F_96 ( V_142 ) , V_143 ) ;
}
}
static inline const char * F_97 ( struct V_144 * V_145 )
{
if ( V_145 -> V_146 > V_147 )
return L_24 ;
return V_148 [ V_145 -> V_146 ] ;
}
static void F_98 ( const char * type , struct V_144 * V_141 )
{
V_66 V_140 = V_141 -> V_140 ;
printf ( L_25 V_129 L_26 ,
type ,
V_140 ,
F_97 ( V_141 ) ) ;
F_94 ( V_140 , V_141 -> V_141 ) ;
}
static void F_99 ( struct V_18 * V_19 )
{
struct V_144 * V_149 = & V_19 -> V_149 ;
if ( V_149 -> V_141 )
F_98 ( L_27 , V_149 ) ;
}
static void F_100 ( struct V_18 * V_19 )
{
struct V_144 * V_150 = & V_19 -> V_150 ;
if ( V_150 -> V_141 )
F_98 ( L_28 , V_150 ) ;
}
static void F_101 ( struct V_151 * V_152 )
{
printf ( L_29 V_128 L_30 ,
V_152 -> V_40 , V_152 -> V_110 ) ;
}
static void F_102 ( struct V_34 * V_5 ,
union V_33 * V_17 ,
struct V_18 * V_19 )
{
V_66 V_97 = F_103 ( V_5 ) ;
if ( V_17 -> V_31 . type != V_153 &&
! F_33 ( V_5 ) ) {
fputs ( L_31 , stdout ) ;
return;
}
if ( ( V_97 & V_154 ) )
printf ( L_32 , V_19 -> V_113 ) ;
if ( V_97 & V_155 )
printf ( L_33 V_128 L_19 , V_19 -> time ) ;
}
static void F_104 ( struct V_18 * V_19 , V_66 V_98 )
{
printf ( L_34 ) ;
if ( V_98 & V_156 )
printf ( L_35 V_129 L_9 ,
V_19 -> F_52 . V_80 ) ;
if ( V_98 & V_157 )
printf ( L_36 V_129 L_9 ,
V_19 -> F_52 . V_81 ) ;
if ( V_98 & V_158 ) {
V_66 V_93 ;
printf ( L_37 V_128 L_9 , V_19 -> F_52 . V_159 . V_124 ) ;
for ( V_93 = 0 ; V_93 < V_19 -> F_52 . V_159 . V_124 ; V_93 ++ ) {
struct V_160 * V_79 ;
V_79 = & V_19 -> F_52 . V_159 . V_161 [ V_93 ] ;
printf ( L_38 V_129
L_39 V_129 L_9 ,
V_79 -> V_82 , V_79 -> V_79 ) ;
}
} else
printf ( L_38 V_129 L_39 V_129 L_9 ,
V_19 -> F_52 . V_162 . V_82 , V_19 -> F_52 . V_162 . V_79 ) ;
}
static void F_105 ( struct V_34 * V_5 , union V_33 * V_17 ,
V_66 V_21 , struct V_18 * V_19 )
{
if ( ! V_116 )
return;
printf ( L_40 V_129 L_41 ,
V_21 , V_17 -> V_31 . V_40 , V_17 -> V_31 . type ) ;
F_106 ( V_17 ) ;
if ( V_19 )
F_102 ( V_5 , V_17 , V_19 ) ;
printf ( L_42 V_129 L_43 , V_21 ,
V_17 -> V_31 . V_40 , F_107 ( V_17 -> V_31 . type ) ) ;
}
static void F_108 ( struct V_10 * V_11 , union V_33 * V_17 ,
struct V_18 * V_19 )
{
V_66 V_97 ;
if ( ! V_116 )
return;
printf ( L_44 V_129 L_45 V_128 L_46 V_129 L_9 ,
V_17 -> V_31 . V_163 , V_19 -> V_69 , V_19 -> V_70 , V_19 -> V_115 ,
V_19 -> V_164 , V_19 -> V_165 ) ;
V_97 = V_11 -> V_12 . V_97 ;
if ( V_97 & V_166 )
F_91 ( V_11 , V_19 ) ;
if ( ( V_97 & V_167 ) && ! F_92 ( V_11 ) )
F_93 ( V_19 ) ;
if ( V_97 & V_168 )
F_99 ( V_19 ) ;
if ( V_97 & V_169 )
F_100 ( V_19 ) ;
if ( V_97 & V_170 )
F_101 ( & V_19 -> V_171 ) ;
if ( V_97 & V_172 )
printf ( L_47 V_128 L_9 , V_19 -> V_173 ) ;
if ( V_97 & V_174 )
printf ( L_48 V_129 L_9 , V_19 -> V_175 ) ;
if ( V_97 & V_176 )
printf ( L_49 V_129 L_9 , V_19 -> V_177 ) ;
if ( V_97 & V_178 )
F_104 ( V_19 , V_11 -> V_12 . V_98 ) ;
}
static struct V_35 * F_109 ( struct V_7 * V_7 ,
union V_33 * V_17 ,
struct V_18 * V_19 )
{
const T_7 V_179 = V_17 -> V_31 . V_163 & V_180 ;
struct V_35 * V_35 ;
if ( V_181 &&
( ( V_179 == V_182 ) ||
( V_179 == V_183 ) ) ) {
T_12 V_69 ;
if ( V_17 -> V_31 . type == V_184
|| V_17 -> V_31 . type == V_185 )
V_69 = V_17 -> V_41 . V_69 ;
else
V_69 = V_19 -> V_69 ;
V_35 = F_110 ( V_7 , V_69 ) ;
if ( ! V_35 )
V_35 = F_110 ( V_7 , V_186 ) ;
return V_35 ;
}
return & V_7 -> V_9 ;
}
static int F_111 ( struct V_34 * V_5 ,
struct V_23 * V_20 ,
union V_33 * V_17 ,
struct V_18 * V_19 ,
struct V_160 * V_187 ,
struct V_35 * V_35 )
{
struct V_188 * V_189 = F_112 ( V_5 , V_187 -> V_82 ) ;
if ( V_189 ) {
V_19 -> V_82 = V_187 -> V_82 ;
V_19 -> V_164 = V_187 -> V_79 - V_189 -> V_164 ;
V_189 -> V_164 = V_187 -> V_79 ;
}
if ( ! V_189 || V_189 -> V_11 == NULL ) {
++ V_5 -> V_190 . V_191 ;
return 0 ;
}
return V_20 -> V_19 ( V_20 , V_17 , V_19 , V_189 -> V_11 , V_35 ) ;
}
static int F_113 ( struct V_34 * V_5 ,
struct V_23 * V_20 ,
union V_33 * V_17 ,
struct V_18 * V_19 ,
struct V_35 * V_35 )
{
int V_8 = - V_192 ;
V_66 V_93 ;
for ( V_93 = 0 ; V_93 < V_19 -> F_52 . V_159 . V_124 ; V_93 ++ ) {
V_8 = F_111 ( V_5 , V_20 , V_17 , V_19 ,
& V_19 -> F_52 . V_159 . V_161 [ V_93 ] ,
V_35 ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static int
F_114 ( struct V_34 * V_5 ,
struct V_23 * V_20 ,
union V_33 * V_17 ,
struct V_18 * V_19 ,
struct V_10 * V_11 ,
struct V_35 * V_35 )
{
V_66 V_97 = V_11 -> V_12 . V_97 ;
V_66 V_98 = V_11 -> V_12 . V_98 ;
if ( ! ( V_97 & V_178 ) )
return V_20 -> V_19 ( V_20 , V_17 , V_19 , V_11 , V_35 ) ;
if ( V_98 & V_158 )
return F_113 ( V_5 , V_20 , V_17 , V_19 ,
V_35 ) ;
else
return F_111 ( V_5 , V_20 , V_17 , V_19 ,
& V_19 -> F_52 . V_162 , V_35 ) ;
}
static int F_115 ( struct V_7 * V_7 ,
struct V_34 * V_5 ,
union V_33 * V_17 ,
struct V_18 * V_19 ,
struct V_23 * V_20 , V_66 V_21 )
{
struct V_10 * V_11 ;
struct V_35 * V_35 ;
F_105 ( V_5 , V_17 , V_21 , V_19 ) ;
V_11 = F_116 ( V_5 , V_19 -> V_82 ) ;
V_35 = F_109 ( V_7 , V_17 , V_19 ) ;
switch ( V_17 -> V_31 . type ) {
case V_153 :
if ( V_11 == NULL ) {
++ V_5 -> V_190 . V_191 ;
return 0 ;
}
F_108 ( V_11 , V_17 , V_19 ) ;
if ( V_35 == NULL ) {
++ V_5 -> V_190 . V_193 ;
return 0 ;
}
return F_114 ( V_5 , V_20 , V_17 , V_19 , V_11 , V_35 ) ;
case V_184 :
return V_20 -> V_41 ( V_20 , V_17 , V_19 , V_35 ) ;
case V_185 :
if ( V_17 -> V_31 . V_163 & V_194 )
++ V_5 -> V_190 . V_195 ;
return V_20 -> V_42 ( V_20 , V_17 , V_19 , V_35 ) ;
case V_196 :
return V_20 -> V_43 ( V_20 , V_17 , V_19 , V_35 ) ;
case V_197 :
return V_20 -> V_44 ( V_20 , V_17 , V_19 , V_35 ) ;
case V_198 :
return V_20 -> exit ( V_20 , V_17 , V_19 , V_35 ) ;
case V_199 :
if ( V_20 -> V_45 == V_46 )
V_5 -> V_190 . V_200 += V_17 -> V_45 . V_45 ;
return V_20 -> V_45 ( V_20 , V_17 , V_19 , V_35 ) ;
case V_201 :
if ( V_20 -> V_47 == V_48 )
V_5 -> V_190 . V_202 += V_17 -> V_47 . V_45 ;
return V_20 -> V_47 ( V_20 , V_17 , V_19 , V_35 ) ;
case V_203 :
return V_20 -> F_52 ( V_20 , V_17 , V_19 , V_11 , V_35 ) ;
case V_204 :
return V_20 -> V_55 ( V_20 , V_17 , V_19 , V_35 ) ;
case V_205 :
return V_20 -> V_56 ( V_20 , V_17 , V_19 , V_35 ) ;
case V_206 :
if ( V_20 -> V_49 == V_50 &&
( V_17 -> V_49 . V_85 & V_207 ) )
V_5 -> V_190 . V_208 += 1 ;
return V_20 -> V_49 ( V_20 , V_17 , V_19 , V_35 ) ;
case V_209 :
return V_20 -> V_51 ( V_20 , V_17 , V_19 , V_35 ) ;
case V_210 :
case V_86 :
return V_20 -> V_53 ( V_20 , V_17 , V_19 , V_35 ) ;
default:
++ V_5 -> V_190 . V_211 ;
return - 1 ;
}
}
static int F_23 ( struct V_1 * V_2 ,
union V_33 * V_17 ,
struct V_18 * V_19 ,
struct V_23 * V_20 ,
V_66 V_21 )
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
union V_33 * V_17 ,
V_66 V_21 )
{
struct V_14 * V_15 = & V_2 -> V_14 ;
struct V_23 * V_20 = V_2 -> V_20 ;
int V_36 = F_55 ( V_2 -> V_4 ) ;
int V_212 ;
F_105 ( V_2 -> V_5 , V_17 , V_21 , NULL ) ;
switch ( V_17 -> V_31 . type ) {
case V_213 :
V_212 = V_20 -> V_12 ( V_20 , V_17 , & V_2 -> V_5 ) ;
if ( V_212 == 0 ) {
F_8 ( V_2 ) ;
F_18 ( V_2 ) ;
}
return V_212 ;
case V_214 :
return 0 ;
case V_215 :
F_119 ( V_36 , V_21 , V_216 ) ;
return V_20 -> V_57 ( V_20 , V_17 , V_2 ) ;
case V_217 :
return V_20 -> V_58 ( V_20 , V_17 , V_2 ) ;
case V_218 :
return V_20 -> V_59 ( V_20 , V_17 , V_15 ) ;
case V_219 :
return V_20 -> V_61 ( V_20 , V_17 , V_2 ) ;
case V_220 :
return V_20 -> V_62 ( V_20 , V_17 , V_2 ) ;
case V_221 :
F_119 ( V_36 , V_21 + V_17 -> V_31 . V_40 , V_216 ) ;
return V_20 -> V_39 ( V_20 , V_17 , V_2 ) ;
case V_222 :
F_120 ( V_2 , V_17 ) ;
return V_20 -> V_63 ( V_20 , V_17 , V_2 ) ;
default:
return - V_192 ;
}
}
int F_121 ( struct V_1 * V_2 ,
union V_33 * V_17 ,
struct V_18 * V_19 )
{
struct V_34 * V_5 = V_2 -> V_5 ;
struct V_23 * V_20 = V_2 -> V_20 ;
F_122 ( & V_5 -> V_190 , V_17 -> V_31 . type ) ;
if ( V_17 -> V_31 . type >= V_223 )
return F_118 ( V_2 , V_17 , 0 ) ;
return F_115 ( & V_2 -> V_7 , V_5 , V_17 , V_19 , V_20 , 0 ) ;
}
static void F_123 ( union V_33 * V_17 , bool T_6 )
{
T_13 V_224 ;
V_224 = V_225 [ V_17 -> V_31 . type ] ;
if ( V_224 )
V_224 ( V_17 , T_6 ) ;
}
int F_124 ( struct V_1 * V_2 , T_3 V_21 ,
void * V_38 , T_10 V_226 ,
union V_33 * * V_227 ,
struct V_18 * V_19 )
{
union V_33 * V_17 ;
T_10 V_228 , V_229 ;
int V_36 ;
if ( V_2 -> V_230 && ! V_2 -> V_31 . V_231 ) {
V_17 = V_21 - V_2 -> V_232 +
V_2 -> V_233 ;
goto V_234;
}
if ( F_4 ( V_2 -> V_4 ) )
return - 1 ;
V_36 = F_55 ( V_2 -> V_4 ) ;
V_228 = sizeof( struct V_67 ) ;
if ( V_226 < V_228 )
return - 1 ;
if ( F_119 ( V_36 , V_21 , V_216 ) == ( T_3 ) - 1 ||
F_125 ( V_36 , V_38 , V_228 ) != ( T_4 ) V_228 )
return - 1 ;
V_17 = (union V_33 * ) V_38 ;
if ( V_2 -> V_31 . V_231 )
F_126 ( & V_17 -> V_31 ) ;
if ( V_17 -> V_31 . V_40 < V_228 || V_17 -> V_31 . V_40 > V_226 )
return - 1 ;
V_229 = V_17 -> V_31 . V_40 - V_228 ;
if ( F_125 ( V_36 , V_38 , V_229 ) != ( T_4 ) V_229 )
return - 1 ;
if ( V_2 -> V_31 . V_231 )
F_123 ( V_17 , F_33 ( V_2 -> V_5 ) ) ;
V_234:
if ( V_19 && V_17 -> V_31 . type < V_223 &&
F_22 ( V_2 -> V_5 , V_17 , V_19 ) )
return - 1 ;
* V_227 = V_17 ;
return 0 ;
}
static T_5 F_127 ( struct V_1 * V_2 ,
union V_33 * V_17 , V_66 V_21 )
{
struct V_34 * V_5 = V_2 -> V_5 ;
struct V_23 * V_20 = V_2 -> V_20 ;
struct V_18 V_19 ;
int V_8 ;
if ( V_2 -> V_31 . V_231 )
F_123 ( V_17 , F_33 ( V_5 ) ) ;
if ( V_17 -> V_31 . type >= V_235 )
return - V_192 ;
F_122 ( & V_5 -> V_190 , V_17 -> V_31 . type ) ;
if ( V_17 -> V_31 . type >= V_223 )
return F_118 ( V_2 , V_17 , V_21 ) ;
V_8 = F_22 ( V_5 , V_17 , & V_19 ) ;
if ( V_8 )
return V_8 ;
if ( V_20 -> V_14 ) {
V_8 = F_88 ( V_2 , V_17 , & V_19 , V_21 ) ;
if ( V_8 != - V_236 )
return V_8 ;
}
return F_23 ( V_2 , V_17 , & V_19 , V_20 ,
V_21 ) ;
}
void F_126 ( struct V_67 * V_68 )
{
V_68 -> type = F_63 ( V_68 -> type ) ;
V_68 -> V_163 = F_128 ( V_68 -> V_163 ) ;
V_68 -> V_40 = F_128 ( V_68 -> V_40 ) ;
}
struct V_237 * F_129 ( struct V_1 * V_2 , T_14 V_69 )
{
return F_130 ( & V_2 -> V_7 . V_9 , - 1 , V_69 ) ;
}
struct V_237 * F_131 ( struct V_1 * V_2 )
{
struct V_237 * V_237 ;
V_237 = F_130 ( & V_2 -> V_7 . V_9 , 0 , 0 ) ;
if ( V_237 == NULL || F_132 ( V_237 , L_50 , 0 ) ) {
F_3 ( L_51 ) ;
V_237 = NULL ;
}
return V_237 ;
}
static void F_133 ( const struct V_1 * V_2 )
{
const struct V_238 * V_190 = & V_2 -> V_5 -> V_190 ;
const struct V_14 * V_15 = & V_2 -> V_14 ;
if ( V_2 -> V_20 -> V_45 == V_46 &&
V_190 -> V_239 [ V_199 ] != 0 ) {
F_134 ( L_52
L_53 ,
V_190 -> V_239 [ 0 ] ,
V_190 -> V_239 [ V_199 ] ) ;
}
if ( V_2 -> V_20 -> V_47 == V_48 ) {
double V_240 ;
V_240 = ( double ) V_190 -> V_202 /
( double ) ( V_190 -> V_239 [ V_153 ] + V_190 -> V_202 ) ;
if ( V_240 > 0.05 ) {
F_134 ( L_54 V_128 L_55 ,
V_190 -> V_239 [ V_153 ] + V_190 -> V_202 ,
V_240 * 100.0 ) ;
}
}
if ( V_2 -> V_20 -> V_49 == V_50 &&
V_190 -> V_208 != 0 ) {
F_134 ( L_56 V_128 L_57 ,
V_190 -> V_208 ,
V_190 -> V_239 [ V_206 ] ) ;
}
if ( V_190 -> V_211 != 0 ) {
F_134 ( L_58
L_59
L_60
L_61
L_62 ,
V_190 -> V_211 ) ;
}
if ( V_190 -> V_191 != 0 ) {
F_134 ( L_63 ,
V_190 -> V_191 ) ;
}
if ( V_190 -> V_241 != 0 ) {
F_134 ( L_64
L_65
L_66 ,
V_190 -> V_241 ,
V_190 -> V_239 [ V_153 ] ) ;
}
if ( V_190 -> V_193 != 0 ) {
F_134 ( L_67
L_68 ,
V_190 -> V_193 ) ;
}
if ( V_15 -> V_242 != 0 )
F_134 ( L_69 , V_15 -> V_242 ) ;
F_135 ( V_190 ) ;
if ( V_190 -> V_195 != 0 ) {
F_134 ( L_70
L_71
L_72
L_73
L_74
L_75
L_76 ,
V_190 -> V_195 ) ;
}
}
static int F_136 ( struct V_237 * V_237 ,
void * V_92 V_32 )
{
return F_137 ( V_237 ) ;
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
int V_36 = F_55 ( V_2 -> V_4 ) ;
union V_33 * V_17 ;
T_15 V_40 , V_243 = 0 ;
void * V_38 = NULL ;
T_5 V_244 = 0 ;
V_66 V_245 ;
T_4 V_212 ;
void * V_92 ;
F_57 ( V_20 ) ;
V_245 = 0 ;
V_243 = sizeof( union V_33 ) ;
V_38 = malloc ( V_243 ) ;
if ( ! V_38 )
return - V_246 ;
V_247:
V_17 = V_38 ;
V_212 = F_125 ( V_36 , V_17 , sizeof( struct V_67 ) ) ;
if ( V_212 <= 0 ) {
if ( V_212 == 0 )
goto V_248;
F_3 ( L_77 ) ;
goto V_249;
}
if ( V_2 -> V_31 . V_231 )
F_126 ( & V_17 -> V_31 ) ;
V_40 = V_17 -> V_31 . V_40 ;
if ( V_40 < sizeof( struct V_67 ) ) {
F_3 ( L_78 ) ;
goto V_249;
}
if ( V_40 > V_243 ) {
void * V_250 = realloc ( V_38 , V_40 ) ;
if ( ! V_250 ) {
F_3 ( L_79 ) ;
goto V_249;
}
V_38 = V_250 ;
V_243 = V_40 ;
V_17 = V_38 ;
}
V_92 = V_17 ;
V_92 += sizeof( struct V_67 ) ;
if ( V_40 - sizeof( struct V_67 ) ) {
V_212 = F_125 ( V_36 , V_92 , V_40 - sizeof( struct V_67 ) ) ;
if ( V_212 <= 0 ) {
if ( V_212 == 0 ) {
F_3 ( L_80 ) ;
goto V_248;
}
F_3 ( L_81 ) ;
goto V_249;
}
}
if ( ( V_244 = F_127 ( V_2 , V_17 , V_245 ) ) < 0 ) {
F_3 ( L_42 V_129 L_82 ,
V_245 , V_17 -> V_31 . V_40 , V_17 -> V_31 . type ) ;
V_212 = - V_192 ;
goto V_249;
}
V_245 += V_40 ;
if ( V_244 > 0 )
V_245 += V_244 ;
if ( ! F_141 () )
goto V_247;
V_248:
V_212 = F_87 ( V_15 , V_251 ) ;
if ( V_212 )
goto V_249;
V_212 = F_142 ( V_2 , V_20 ) ;
if ( V_212 )
goto V_249;
V_212 = F_138 ( V_2 ) ;
V_249:
free ( V_38 ) ;
F_133 ( V_2 ) ;
F_143 ( & V_2 -> V_14 ) ;
F_144 ( V_2 ) ;
return V_212 ;
}
static union V_33 *
F_145 ( struct V_1 * V_2 ,
V_66 V_245 , T_10 V_252 , char * V_38 )
{
union V_33 * V_17 ;
if ( V_245 + sizeof( V_17 -> V_31 ) > V_252 )
return NULL ;
V_17 = (union V_33 * ) ( V_38 + V_245 ) ;
if ( V_2 -> V_31 . V_231 )
F_126 ( & V_17 -> V_31 ) ;
if ( V_245 + V_17 -> V_31 . V_40 > V_252 ) {
if ( V_2 -> V_31 . V_231 )
F_126 ( & V_17 -> V_31 ) ;
return NULL ;
}
return V_17 ;
}
static int F_146 ( struct V_1 * V_2 ,
V_66 V_253 , V_66 V_254 ,
V_66 V_255 )
{
struct V_14 * V_15 = & V_2 -> V_14 ;
struct V_23 * V_20 = V_2 -> V_20 ;
int V_36 = F_55 ( V_2 -> V_4 ) ;
V_66 V_245 , V_256 , V_21 , V_257 , V_40 ;
int V_212 , V_258 , V_259 , V_260 = 0 ;
T_10 V_252 ;
char * V_38 , * V_261 [ V_262 ] ;
union V_33 * V_17 ;
struct V_263 V_264 ;
T_5 V_244 ;
F_57 ( V_20 ) ;
V_256 = V_265 * ( V_253 / V_265 ) ;
V_21 = V_256 ;
V_245 = V_253 - V_256 ;
if ( V_254 == 0 )
goto V_24;
if ( V_253 + V_254 < V_255 )
V_255 = V_253 + V_254 ;
F_147 ( & V_264 , V_255 , L_83 ) ;
V_252 = V_266 ;
if ( V_252 > V_255 ) {
V_252 = V_255 ;
V_2 -> V_230 = true ;
}
memset ( V_261 , 0 , sizeof( V_261 ) ) ;
V_258 = V_267 ;
V_259 = V_268 ;
if ( V_2 -> V_31 . V_231 ) {
V_258 |= V_269 ;
V_259 = V_270 ;
}
V_271:
V_38 = V_41 ( NULL , V_252 , V_258 , V_259 , V_36 ,
V_21 ) ;
if ( V_38 == V_272 ) {
F_3 ( L_84 ) ;
V_212 = - V_246 ;
goto V_249;
}
V_261 [ V_260 ] = V_38 ;
V_260 = ( V_260 + 1 ) & ( F_148 ( V_261 ) - 1 ) ;
V_257 = V_21 + V_245 ;
if ( V_2 -> V_230 ) {
V_2 -> V_233 = V_38 ;
V_2 -> V_232 = V_21 ;
}
V_247:
V_17 = F_145 ( V_2 , V_245 , V_252 , V_38 ) ;
if ( ! V_17 ) {
if ( V_261 [ V_260 ] ) {
F_149 ( V_261 [ V_260 ] , V_252 ) ;
V_261 [ V_260 ] = NULL ;
}
V_256 = V_265 * ( V_245 / V_265 ) ;
V_21 += V_256 ;
V_245 -= V_256 ;
goto V_271;
}
V_40 = V_17 -> V_31 . V_40 ;
if ( V_40 < sizeof( struct V_67 ) ||
( V_244 = F_127 ( V_2 , V_17 , V_257 ) ) < 0 ) {
F_3 ( L_42 V_129 L_82 ,
V_21 + V_245 , V_17 -> V_31 . V_40 ,
V_17 -> V_31 . type ) ;
V_212 = - V_192 ;
goto V_249;
}
if ( V_244 )
V_40 += V_244 ;
V_245 += V_40 ;
V_257 += V_40 ;
F_150 ( & V_264 , V_40 ) ;
if ( F_141 () )
goto V_24;
if ( V_257 < V_255 )
goto V_247;
V_24:
V_212 = F_87 ( V_15 , V_251 ) ;
if ( V_212 )
goto V_249;
V_212 = F_142 ( V_2 , V_20 ) ;
if ( V_212 )
goto V_249;
V_212 = F_138 ( V_2 ) ;
V_249:
F_151 () ;
F_133 ( V_2 ) ;
F_143 ( & V_2 -> V_14 ) ;
F_144 ( V_2 ) ;
V_2 -> V_230 = false ;
return V_212 ;
}
int F_152 ( struct V_1 * V_2 )
{
V_66 V_40 = F_153 ( V_2 -> V_4 ) ;
int V_212 ;
if ( F_131 ( V_2 ) == NULL )
return - V_273 ;
if ( ! F_4 ( V_2 -> V_4 ) )
V_212 = F_146 ( V_2 ,
V_2 -> V_31 . V_253 ,
V_2 -> V_31 . V_254 , V_40 ) ;
else
V_212 = F_140 ( V_2 ) ;
return V_212 ;
}
bool F_154 ( struct V_1 * V_2 , const char * V_274 )
{
struct V_10 * V_11 ;
F_17 (session->evlist, evsel) {
if ( V_11 -> V_12 . type == V_275 )
return true ;
}
F_3 ( L_85 , V_274 ) ;
return false ;
}
int F_155 ( struct V_276 * * V_277 ,
const char * V_278 , V_66 V_165 )
{
char * V_279 ;
enum V_280 V_93 ;
struct V_281 * V_282 ;
V_282 = F_25 ( sizeof( struct V_281 ) ) ;
if ( V_282 == NULL )
return - V_273 ;
V_282 -> V_283 = F_156 ( V_278 ) ;
if ( V_282 -> V_283 == NULL ) {
free ( V_282 ) ;
return - V_273 ;
}
V_279 = strchr ( V_282 -> V_283 , ']' ) ;
if ( V_279 )
* V_279 = '\0' ;
V_282 -> V_165 = V_165 ;
for ( V_93 = 0 ; V_93 < V_284 ; ++ V_93 ) {
struct V_285 * V_285 = F_157 ( V_277 [ V_93 ] ) ;
if ( ! V_285 )
continue;
V_285 -> V_281 = V_282 ;
}
return 0 ;
}
T_10 F_158 ( struct V_1 * V_2 , T_16 * V_286 )
{
return F_159 ( & V_2 -> V_7 , V_286 ) ;
}
T_10 F_160 ( struct V_1 * V_2 , T_16 * V_286 ,
bool (V_244)( struct V_287 * V_287 , int V_288 ) , int V_288 )
{
return F_161 ( & V_2 -> V_7 , V_286 , V_244 , V_288 ) ;
}
T_10 F_162 ( struct V_1 * V_2 , T_16 * V_286 )
{
T_10 V_8 ;
const char * V_274 = L_86 ;
if ( F_163 ( & V_2 -> V_31 , V_289 ) )
V_274 = L_87 ;
V_8 = fprintf ( V_286 , L_88 , V_274 ) ;
V_8 += F_164 ( & V_2 -> V_5 -> V_190 , V_286 ) ;
return V_8 ;
}
T_10 F_165 ( struct V_1 * V_2 , T_16 * V_286 )
{
return F_166 ( & V_2 -> V_7 . V_9 , V_286 ) ;
}
struct V_10 * F_167 ( struct V_1 * V_2 ,
unsigned int type )
{
struct V_10 * V_290 ;
F_17 (session->evlist, pos) {
if ( V_290 -> V_12 . type == type )
return V_290 ;
}
return NULL ;
}
void F_168 ( struct V_10 * V_11 , struct V_18 * V_19 ,
struct V_291 * V_292 ,
unsigned int V_293 , unsigned int V_294 )
{
struct V_295 * V_296 ;
int V_297 = V_293 & V_298 ;
int V_299 = V_293 & V_300 ;
int V_301 = V_293 & V_302 ;
int V_303 = V_293 & V_304 ;
int V_305 = V_293 & V_306 ;
int V_307 = V_293 & V_308 ;
char V_118 = V_305 ? ' ' : '\t' ;
if ( V_309 . V_310 && V_19 -> V_120 ) {
struct V_291 V_311 ;
if ( F_169 ( V_292 -> V_237 , V_11 ,
V_19 , NULL , NULL ,
V_294 ) != 0 ) {
if ( V_312 )
error ( L_89 ) ;
return;
}
F_170 ( & V_313 ) ;
if ( V_303 )
V_311 = * V_292 ;
while ( V_294 ) {
V_66 V_165 = 0 ;
V_296 = F_171 ( & V_313 ) ;
if ( ! V_296 )
break;
if ( V_296 -> V_314 && V_296 -> V_314 -> V_315 )
goto V_316;
if ( V_297 )
printf ( L_90 V_129 , V_118 , V_296 -> V_115 ) ;
if ( V_296 -> V_276 )
V_165 = V_296 -> V_276 -> V_317 ( V_296 -> V_276 , V_296 -> V_115 ) ;
if ( V_299 ) {
printf ( L_19 ) ;
if ( V_303 ) {
V_311 . V_165 = V_165 ;
V_311 . V_276 = V_296 -> V_276 ;
F_172 ( V_296 -> V_314 , & V_311 , stdout ) ;
} else
F_173 ( V_296 -> V_314 , stdout ) ;
}
if ( V_301 ) {
printf ( L_91 ) ;
F_174 ( V_296 -> V_276 , stdout ) ;
printf ( L_92 ) ;
}
if ( V_307 )
F_175 ( V_296 -> V_276 , V_165 , L_93 ,
stdout ) ;
if ( ! V_305 )
printf ( L_9 ) ;
V_294 -- ;
V_316:
F_176 ( & V_313 ) ;
}
} else {
if ( V_292 -> V_314 && V_292 -> V_314 -> V_315 )
return;
if ( V_297 )
printf ( L_94 V_129 , V_19 -> V_115 ) ;
if ( V_299 ) {
printf ( L_19 ) ;
if ( V_303 )
F_172 ( V_292 -> V_314 , V_292 ,
stdout ) ;
else
F_173 ( V_292 -> V_314 , stdout ) ;
}
if ( V_301 ) {
printf ( L_91 ) ;
F_174 ( V_292 -> V_276 , stdout ) ;
printf ( L_92 ) ;
}
if ( V_307 )
F_175 ( V_292 -> V_276 , V_292 -> V_165 , L_93 , stdout ) ;
}
}
int F_177 ( struct V_1 * V_2 ,
const char * V_318 , unsigned long * V_319 )
{
int V_93 , V_212 = - 1 ;
struct V_320 * V_276 ;
for ( V_93 = 0 ; V_93 < V_321 ; ++ V_93 ) {
struct V_10 * V_11 ;
V_11 = F_167 ( V_2 , V_93 ) ;
if ( ! V_11 )
continue;
if ( ! ( V_11 -> V_12 . V_97 & V_154 ) ) {
F_3 ( L_95
L_96 ) ;
return - 1 ;
}
}
V_276 = F_178 ( V_318 ) ;
if ( V_276 == NULL ) {
F_3 ( L_97 ) ;
return - 1 ;
}
for ( V_93 = 0 ; V_93 < V_276 -> V_124 ; V_93 ++ ) {
int V_113 = V_276 -> V_276 [ V_93 ] ;
if ( V_113 >= V_322 ) {
F_3 ( L_98
L_99 , V_113 ) ;
goto V_323;
}
F_179 ( V_113 , V_319 ) ;
}
V_212 = 0 ;
V_323:
F_180 ( V_276 ) ;
return V_212 ;
}
void F_181 ( struct V_1 * V_2 , T_16 * V_286 ,
bool V_324 )
{
struct V_325 V_326 ;
int V_36 , V_8 ;
if ( V_2 == NULL || V_286 == NULL )
return;
V_36 = F_55 ( V_2 -> V_4 ) ;
V_8 = F_182 ( V_36 , & V_326 ) ;
if ( V_8 == - 1 )
return;
fprintf ( V_286 , L_100 ) ;
fprintf ( V_286 , L_101 , ctime ( & V_326 . V_327 ) ) ;
F_183 ( V_2 , V_286 , V_324 ) ;
fprintf ( V_286 , L_102 ) ;
}
int F_184 ( struct V_1 * V_2 ,
const struct V_328 * V_329 ,
T_10 V_330 )
{
struct V_10 * V_11 ;
T_10 V_93 ;
int V_212 ;
for ( V_93 = 0 ; V_93 < V_330 ; V_93 ++ ) {
V_11 = F_185 ( V_2 -> V_5 , V_329 [ V_93 ] . V_283 ) ;
if ( V_11 == NULL )
continue;
V_212 = - V_331 ;
if ( V_11 -> V_332 != NULL )
goto V_24;
V_11 -> V_332 = V_329 [ V_93 ] . V_332 ;
}
V_212 = 0 ;
V_24:
return V_212 ;
}
int F_186 ( struct V_23 * V_20 V_32 ,
union V_33 * V_17 ,
struct V_1 * V_2 )
{
struct V_34 * V_5 = V_2 -> V_5 ;
struct V_333 * V_334 = & V_17 -> V_61 ;
T_10 V_93 , V_124 , V_335 ;
V_335 = ( V_334 -> V_31 . V_40 - sizeof( struct V_333 ) ) /
sizeof( struct V_336 ) ;
V_124 = V_334 -> V_124 ;
if ( V_124 > V_335 )
return - V_192 ;
if ( V_116 )
fprintf ( stdout , L_103 , V_124 ) ;
for ( V_93 = 0 ; V_93 < V_124 ; V_93 ++ ) {
struct V_336 * V_134 = & V_334 -> V_130 [ V_93 ] ;
struct V_188 * V_189 ;
if ( V_116 ) {
fprintf ( stdout , L_104 V_128 , V_134 -> V_82 ) ;
fprintf ( stdout , L_105 V_128 , V_134 -> V_112 ) ;
fprintf ( stdout , L_106 V_337 , V_134 -> V_113 ) ;
fprintf ( stdout , L_107 V_337 L_9 , V_134 -> V_70 ) ;
}
V_189 = F_112 ( V_5 , V_134 -> V_82 ) ;
if ( ! V_189 )
return - V_338 ;
V_189 -> V_112 = V_134 -> V_112 ;
V_189 -> V_113 = V_134 -> V_113 ;
V_189 -> V_70 = V_134 -> V_70 ;
}
return 0 ;
}
int F_187 ( struct V_23 * V_20 ,
T_17 V_339 ,
struct V_34 * V_5 ,
struct V_35 * V_35 )
{
union V_33 * V_340 ;
struct V_10 * V_11 ;
T_10 V_124 = 0 , V_93 = 0 , T_9 , V_335 , V_37 ;
int V_212 ;
F_188 ( L_108 ) ;
V_335 = ( V_341 - sizeof( struct V_333 ) ) /
sizeof( struct V_336 ) ;
F_17 (evlist, evsel)
V_124 += V_11 -> V_342 ;
V_37 = V_124 > V_335 ? V_335 : V_124 ;
T_9 = sizeof( struct V_333 ) + V_37 * sizeof( struct V_336 ) ;
V_340 = F_25 ( T_9 ) ;
if ( ! V_340 )
return - V_273 ;
V_340 -> V_61 . V_31 . type = V_219 ;
V_340 -> V_61 . V_31 . V_40 = T_9 ;
V_340 -> V_61 . V_124 = V_37 ;
F_17 (evlist, evsel) {
T_12 V_343 ;
for ( V_343 = 0 ; V_343 < V_11 -> V_342 ; V_343 ++ ) {
struct V_336 * V_134 ;
struct V_188 * V_189 ;
if ( V_93 >= V_37 ) {
V_212 = V_339 ( V_20 , V_340 , NULL , V_35 ) ;
if ( V_212 )
goto V_249;
V_124 -= V_37 ;
V_93 = 0 ;
}
V_134 = & V_340 -> V_61 . V_130 [ V_93 ++ ] ;
V_134 -> V_82 = V_11 -> V_82 [ V_343 ] ;
V_189 = F_112 ( V_5 , V_134 -> V_82 ) ;
if ( ! V_189 ) {
free ( V_340 ) ;
return - V_338 ;
}
V_134 -> V_112 = V_189 -> V_112 ;
V_134 -> V_113 = V_189 -> V_113 ;
V_134 -> V_70 = V_189 -> V_70 ;
}
}
T_9 = sizeof( struct V_333 ) + V_124 * sizeof( struct V_336 ) ;
V_340 -> V_61 . V_31 . V_40 = T_9 ;
V_340 -> V_61 . V_124 = V_124 ;
V_212 = V_339 ( V_20 , V_340 , NULL , V_35 ) ;
V_249:
free ( V_340 ) ;
return V_212 ;
}
