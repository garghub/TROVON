static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_2 ( V_2 ) < 0 ) {
F_3 ( L_1 ) ;
return - 1 ;
}
if ( F_4 ( V_4 ) )
return 0 ;
if ( F_5 ( & V_2 -> V_5 , V_6 ) )
return 0 ;
if ( ! F_6 ( V_2 -> V_7 ) ) {
F_3 ( L_2 ) ;
return - 1 ;
}
if ( ! F_7 ( V_2 -> V_7 ) ) {
F_3 ( L_3 ) ;
return - 1 ;
}
if ( ! F_8 ( V_2 -> V_7 ) ) {
F_3 ( L_4 ) ;
return - 1 ;
}
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
T_1 V_8 = F_10 ( V_2 -> V_7 ) ;
F_11 ( & V_2 -> V_9 , V_8 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_10 = F_13 ( & V_2 -> V_9 . V_11 ) ;
if ( V_10 >= 0 )
V_10 = F_14 ( & V_2 -> V_9 ) ;
return V_10 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_9 ) ;
}
static bool F_17 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
F_18 (session->evlist, evsel) {
if ( V_13 -> V_14 . V_15 )
return true ;
}
return false ;
}
static void F_19 ( struct V_1 * V_2 )
{
bool V_15 = F_17 ( V_2 ) ;
F_20 ( & V_2 -> V_9 , V_15 ) ;
}
static int F_21 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_20 V_21 ;
struct V_1 * V_2 = F_22 ( V_17 , struct V_1 ,
V_16 ) ;
int V_10 = F_23 ( V_2 -> V_7 , V_19 -> V_19 , & V_21 ) ;
if ( V_10 ) {
F_3 ( L_5 , V_10 ) ;
return V_10 ;
}
return F_24 ( V_2 , V_19 -> V_19 , & V_21 ,
V_2 -> V_22 , V_19 -> V_23 ) ;
}
struct V_1 * F_25 ( struct V_3 * V_4 ,
bool V_24 , struct V_25 * V_22 )
{
struct V_1 * V_2 = F_26 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
goto V_26;
V_2 -> V_24 = V_24 ;
V_2 -> V_22 = V_22 ;
F_27 ( & V_2 -> V_27 ) ;
F_28 ( & V_2 -> V_9 ) ;
F_29 ( & V_2 -> V_16 , F_21 ) ;
if ( V_4 ) {
if ( F_30 ( V_4 ) )
goto V_28;
V_2 -> V_4 = V_4 ;
if ( F_31 ( V_4 ) ) {
if ( F_1 ( V_2 ) < 0 )
goto V_29;
F_9 ( V_2 ) ;
F_19 ( V_2 ) ;
}
} else {
V_2 -> V_9 . V_11 . V_30 = & V_31 ;
}
if ( ! V_4 || F_32 ( V_4 ) ) {
if ( F_12 ( V_2 ) < 0 )
F_33 ( L_6 ) ;
}
if ( V_22 && V_22 -> V_32 &&
V_22 -> V_16 && ! F_34 ( V_2 -> V_7 ) ) {
F_35 ( L_7 ) ;
V_22 -> V_16 = false ;
}
return V_2 ;
V_29:
F_36 ( V_4 ) ;
V_28:
F_37 ( V_2 ) ;
V_26:
return NULL ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_9 . V_11 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_40 ( V_2 ) ;
F_41 ( & V_2 -> V_27 ) ;
F_15 ( V_2 ) ;
F_38 ( V_2 ) ;
F_42 ( & V_2 -> V_5 . V_30 ) ;
F_43 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_4 )
F_36 ( V_2 -> V_4 ) ;
free ( V_2 ) ;
}
static int F_44 ( struct V_25 * V_22
V_33 ,
union V_34 * V_19
V_33 ,
struct V_1 * V_2
V_33 )
{
F_35 ( L_8 ) ;
return 0 ;
}
static int F_45 ( struct V_25 * V_22 V_33 ,
union V_34 * V_19 V_33 ,
struct V_35 * * T_2
V_33 )
{
F_35 ( L_8 ) ;
return 0 ;
}
static int F_46 ( struct V_25 * V_22 V_33 ,
union V_34 * V_19 V_33 ,
struct V_35 * * T_2
V_33 )
{
if ( V_36 )
F_47 ( V_19 , stdout ) ;
F_35 ( L_8 ) ;
return 0 ;
}
static int F_48 ( struct V_25 * V_22 V_33 ,
union V_34 * V_19 V_33 ,
struct V_20 * V_21 V_33 ,
struct V_12 * V_13 V_33 ,
struct V_37 * V_37 V_33 )
{
F_35 ( L_8 ) ;
return 0 ;
}
static int F_49 ( struct V_25 * V_22 V_33 ,
union V_34 * V_19 V_33 ,
struct V_20 * V_21 V_33 ,
struct V_37 * V_37 V_33 )
{
F_35 ( L_8 ) ;
return 0 ;
}
static int F_50 ( struct V_25 * V_22 V_33 ,
union V_34 * V_19 V_33 ,
struct V_16 * V_17 V_33 )
{
F_35 ( L_8 ) ;
return 0 ;
}
static int F_51 ( int V_38 , T_3 V_39 )
{
char V_40 [ 4096 ] ;
T_4 V_10 ;
while ( V_39 > 0 ) {
V_10 = F_52 ( V_38 , V_40 , F_53 ( V_39 , ( T_3 ) sizeof( V_40 ) ) ) ;
if ( V_10 <= 0 )
return V_10 ;
V_39 -= V_10 ;
}
return 0 ;
}
static T_5 F_54 ( struct V_25 * V_22 V_33 ,
union V_34 * V_19 ,
struct V_1 * V_2
V_33 )
{
F_35 ( L_8 ) ;
if ( F_4 ( V_2 -> V_4 ) )
F_51 ( F_55 ( V_2 -> V_4 ) , V_19 -> V_41 . V_42 ) ;
return V_19 -> V_41 . V_42 ;
}
static int F_56 ( struct V_25 * V_22 V_33 ,
union V_34 * V_19 V_33 ,
struct V_1 * V_2 V_33 )
{
F_35 ( L_8 ) ;
return 0 ;
}
static
int F_57 ( struct V_25 * V_22 V_33 ,
union V_34 * V_19 V_33 ,
struct V_1 * V_2 V_33 )
{
if ( V_36 )
F_58 ( V_19 , stdout ) ;
F_35 ( L_8 ) ;
return 0 ;
}
static
int F_59 ( struct V_25 * V_22 V_33 ,
union V_34 * V_19 V_33 ,
struct V_1 * V_2 V_33 )
{
if ( V_36 )
F_60 ( V_19 , stdout ) ;
F_35 ( L_8 ) ;
return 0 ;
}
static
int F_61 ( struct V_25 * V_22 V_33 ,
union V_34 * V_19 V_33 ,
struct V_1 * V_2 V_33 )
{
if ( V_36 )
F_62 ( V_19 , stdout ) ;
F_35 ( L_8 ) ;
return 0 ;
}
static int F_63 ( struct V_25 * V_22 V_33 ,
union V_34 * V_19 V_33 ,
struct V_1 * V_1
V_33 )
{
if ( V_36 )
F_64 ( V_19 , stdout ) ;
F_35 ( L_8 ) ;
return 0 ;
}
static int F_65 ( struct V_25 * V_22 V_33 ,
union V_34 * V_19 V_33 ,
struct V_1 * V_1
V_33 )
{
if ( V_36 )
F_66 ( V_19 , stdout ) ;
F_35 ( L_8 ) ;
return 0 ;
}
void F_67 ( struct V_25 * V_22 )
{
if ( V_22 -> V_21 == NULL )
V_22 -> V_21 = F_48 ;
if ( V_22 -> V_43 == NULL )
V_22 -> V_43 = F_49 ;
if ( V_22 -> V_44 == NULL )
V_22 -> V_44 = F_49 ;
if ( V_22 -> V_45 == NULL )
V_22 -> V_45 = F_49 ;
if ( V_22 -> V_46 == NULL )
V_22 -> V_46 = F_49 ;
if ( V_22 -> exit == NULL )
V_22 -> exit = F_49 ;
if ( V_22 -> V_47 == NULL )
V_22 -> V_47 = V_48 ;
if ( V_22 -> V_49 == NULL )
V_22 -> V_49 = V_50 ;
if ( V_22 -> V_51 == NULL )
V_22 -> V_51 = V_52 ;
if ( V_22 -> V_53 == NULL )
V_22 -> V_53 = V_54 ;
if ( V_22 -> V_55 == NULL )
V_22 -> V_55 = V_56 ;
if ( V_22 -> F_52 == NULL )
V_22 -> F_52 = F_48 ;
if ( V_22 -> V_57 == NULL )
V_22 -> V_57 = F_49 ;
if ( V_22 -> V_58 == NULL )
V_22 -> V_58 = F_49 ;
if ( V_22 -> V_14 == NULL )
V_22 -> V_14 = F_45 ;
if ( V_22 -> V_59 == NULL )
V_22 -> V_59 = F_46 ;
if ( V_22 -> V_60 == NULL )
V_22 -> V_60 = F_44 ;
if ( V_22 -> V_61 == NULL )
V_22 -> V_61 = F_56 ;
if ( V_22 -> V_62 == NULL ) {
if ( V_22 -> V_16 )
V_22 -> V_62 = V_63 ;
else
V_22 -> V_62 = F_50 ;
}
if ( V_22 -> V_64 == NULL )
V_22 -> V_64 = F_56 ;
if ( V_22 -> V_65 == NULL )
V_22 -> V_65 = F_56 ;
if ( V_22 -> V_41 == NULL )
V_22 -> V_41 = F_54 ;
if ( V_22 -> V_66 == NULL )
V_22 -> V_66 = F_56 ;
if ( V_22 -> V_67 == NULL )
V_22 -> V_67 = F_57 ;
if ( V_22 -> V_68 == NULL )
V_22 -> V_68 = F_59 ;
if ( V_22 -> V_69 == NULL )
V_22 -> V_69 = F_61 ;
if ( V_22 -> V_70 == NULL )
V_22 -> V_70 = F_63 ;
if ( V_22 -> V_71 == NULL )
V_22 -> V_71 = F_65 ;
if ( V_22 -> V_72 == NULL )
V_22 -> V_72 = F_56 ;
}
static void F_68 ( union V_34 * V_19 , void * V_73 )
{
void * V_74 = ( void * ) V_19 + V_19 -> V_5 . V_42 ;
int V_42 = V_74 - V_73 ;
F_69 ( V_42 % sizeof( V_75 ) ) ;
F_70 ( V_73 , V_42 ) ;
}
static void F_71 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
struct V_76 * V_77 = & V_19 -> V_5 ;
F_70 ( V_77 + 1 , V_19 -> V_5 . V_42 - sizeof( * V_77 ) ) ;
}
static void F_72 ( union V_34 * V_19 , bool T_6 )
{
V_19 -> V_45 . V_78 = F_73 ( V_19 -> V_45 . V_78 ) ;
V_19 -> V_45 . V_79 = F_73 ( V_19 -> V_45 . V_79 ) ;
if ( T_6 ) {
void * V_73 = & V_19 -> V_45 . V_45 ;
V_73 += F_74 ( strlen ( V_73 ) + 1 , sizeof( V_75 ) ) ;
F_68 ( V_19 , V_73 ) ;
}
}
static void F_75 ( union V_34 * V_19 ,
bool T_6 )
{
V_19 -> V_43 . V_78 = F_73 ( V_19 -> V_43 . V_78 ) ;
V_19 -> V_43 . V_79 = F_73 ( V_19 -> V_43 . V_79 ) ;
V_19 -> V_43 . V_80 = F_76 ( V_19 -> V_43 . V_80 ) ;
V_19 -> V_43 . V_81 = F_76 ( V_19 -> V_43 . V_81 ) ;
V_19 -> V_43 . V_82 = F_76 ( V_19 -> V_43 . V_82 ) ;
if ( T_6 ) {
void * V_73 = & V_19 -> V_43 . V_83 ;
V_73 += F_74 ( strlen ( V_73 ) + 1 , sizeof( V_75 ) ) ;
F_68 ( V_19 , V_73 ) ;
}
}
static void F_77 ( union V_34 * V_19 ,
bool T_6 )
{
V_19 -> V_44 . V_78 = F_73 ( V_19 -> V_44 . V_78 ) ;
V_19 -> V_44 . V_79 = F_73 ( V_19 -> V_44 . V_79 ) ;
V_19 -> V_44 . V_80 = F_76 ( V_19 -> V_44 . V_80 ) ;
V_19 -> V_44 . V_81 = F_76 ( V_19 -> V_44 . V_81 ) ;
V_19 -> V_44 . V_82 = F_76 ( V_19 -> V_44 . V_82 ) ;
V_19 -> V_44 . V_84 = F_73 ( V_19 -> V_44 . V_84 ) ;
V_19 -> V_44 . F_53 = F_73 ( V_19 -> V_44 . F_53 ) ;
V_19 -> V_44 . V_85 = F_76 ( V_19 -> V_44 . V_85 ) ;
if ( T_6 ) {
void * V_73 = & V_19 -> V_44 . V_83 ;
V_73 += F_74 ( strlen ( V_73 ) + 1 , sizeof( V_75 ) ) ;
F_68 ( V_19 , V_73 ) ;
}
}
static void F_78 ( union V_34 * V_19 , bool T_6 )
{
V_19 -> V_46 . V_78 = F_73 ( V_19 -> V_46 . V_78 ) ;
V_19 -> V_46 . V_79 = F_73 ( V_19 -> V_46 . V_79 ) ;
V_19 -> V_46 . V_86 = F_73 ( V_19 -> V_46 . V_86 ) ;
V_19 -> V_46 . V_87 = F_73 ( V_19 -> V_46 . V_87 ) ;
V_19 -> V_46 . time = F_76 ( V_19 -> V_46 . time ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_46 + 1 ) ;
}
static void F_79 ( union V_34 * V_19 , bool T_6 )
{
V_19 -> F_52 . V_78 = F_73 ( V_19 -> F_52 . V_78 ) ;
V_19 -> F_52 . V_79 = F_73 ( V_19 -> F_52 . V_79 ) ;
V_19 -> F_52 . V_88 = F_76 ( V_19 -> F_52 . V_88 ) ;
V_19 -> F_52 . V_89 = F_76 ( V_19 -> F_52 . V_89 ) ;
V_19 -> F_52 . V_90 = F_76 ( V_19 -> F_52 . V_90 ) ;
V_19 -> F_52 . V_91 = F_76 ( V_19 -> F_52 . V_91 ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> F_52 + 1 ) ;
}
static void F_80 ( union V_34 * V_19 , bool T_6 )
{
V_19 -> V_51 . V_92 = F_76 ( V_19 -> V_51 . V_92 ) ;
V_19 -> V_51 . V_93 = F_76 ( V_19 -> V_51 . V_93 ) ;
V_19 -> V_51 . V_94 = F_76 ( V_19 -> V_51 . V_94 ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_51 + 1 ) ;
}
static void F_81 ( union V_34 * V_19 ,
bool T_6 )
{
V_19 -> V_53 . V_78 = F_73 ( V_19 -> V_53 . V_78 ) ;
V_19 -> V_53 . V_79 = F_73 ( V_19 -> V_53 . V_79 ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_53 + 1 ) ;
}
static void F_82 ( union V_34 * V_19 , bool T_6 )
{
if ( V_19 -> V_5 . type == V_95 ) {
V_19 -> V_55 . V_96 =
F_73 ( V_19 -> V_55 . V_96 ) ;
V_19 -> V_55 . V_97 =
F_73 ( V_19 -> V_55 . V_97 ) ;
}
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_55 + 1 ) ;
}
static void F_83 ( union V_34 * V_19 ,
bool T_6 )
{
V_19 -> V_57 . time = F_76 ( V_19 -> V_57 . time ) ;
V_19 -> V_57 . V_91 = F_76 ( V_19 -> V_57 . V_91 ) ;
V_19 -> V_57 . V_98 = F_76 ( V_19 -> V_57 . V_98 ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_57 + 1 ) ;
}
static T_7 F_84 ( T_7 V_99 )
{
int V_100 = ( V_99 >> 4 ) | ( ( V_99 & 0xf ) << 4 ) ;
V_100 = ( ( V_100 & 0xcc ) >> 2 ) | ( ( V_100 & 0x33 ) << 2 ) ;
V_100 = ( ( V_100 & 0xaa ) >> 1 ) | ( ( V_100 & 0x55 ) << 1 ) ;
return ( T_7 ) V_100 ;
}
static void F_85 ( T_7 * V_101 , unsigned V_81 )
{
unsigned V_102 ;
for ( V_102 = 0 ; V_102 < V_81 ; V_102 ++ ) {
* V_101 = F_84 ( * V_101 ) ;
V_101 ++ ;
}
}
void F_86 ( struct V_103 * V_14 )
{
V_14 -> type = F_73 ( V_14 -> type ) ;
V_14 -> V_42 = F_73 ( V_14 -> V_42 ) ;
#define F_87 ( T_8 , V_39 ) \
(attr->size > (offsetof(struct perf_event_attr, f) + \
sizeof(attr->f) * (n)))
#define F_88 ( T_8 , T_9 ) \
do { \
if (bswap_safe(f, 0)) \
attr->f = bswap_##sz(attr->f); \
} while(0)
#define F_89 ( T_8 ) bswap_field(f, 16)
#define F_90 ( T_8 ) bswap_field(f, 32)
#define F_91 ( T_8 ) bswap_field(f, 64)
F_91 ( V_104 ) ;
F_91 ( V_105 ) ;
F_91 ( V_106 ) ;
F_91 ( V_107 ) ;
F_90 ( V_108 ) ;
F_90 ( V_109 ) ;
F_91 ( V_110 ) ;
F_91 ( V_111 ) ;
F_91 ( V_112 ) ;
F_91 ( V_113 ) ;
F_90 ( V_114 ) ;
F_90 ( V_115 ) ;
F_89 ( V_116 ) ;
if ( F_87 ( V_107 , 1 ) )
F_85 ( ( T_7 * ) ( & V_14 -> V_107 + 1 ) ,
sizeof( V_75 ) ) ;
#undef F_91
#undef F_90
#undef F_88
#undef F_87
}
static void F_92 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
T_10 V_42 ;
F_86 ( & V_19 -> V_14 . V_14 ) ;
V_42 = V_19 -> V_5 . V_42 ;
V_42 -= ( void * ) & V_19 -> V_14 . V_91 - ( void * ) V_19 ;
F_70 ( V_19 -> V_14 . V_91 , V_42 ) ;
}
static void F_93 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_59 . type = F_76 ( V_19 -> V_59 . type ) ;
V_19 -> V_59 . V_91 = F_76 ( V_19 -> V_59 . V_91 ) ;
}
static void F_94 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_117 . V_117 . V_118 =
F_76 ( V_19 -> V_117 . V_117 . V_118 ) ;
}
static void F_95 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_60 . V_42 = F_73 ( V_19 -> V_60 . V_42 ) ;
}
static void F_96 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
T_10 V_42 ;
V_19 -> V_65 . type = F_73 ( V_19 -> V_65 . type ) ;
V_42 = V_19 -> V_5 . V_42 ;
V_42 -= ( void * ) & V_19 -> V_65 . V_119 - ( void * ) V_19 ;
F_70 ( V_19 -> V_65 . V_119 , V_42 ) ;
}
static void F_97 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_41 . V_42 = F_76 ( V_19 -> V_41 . V_42 ) ;
V_19 -> V_41 . V_120 = F_76 ( V_19 -> V_41 . V_120 ) ;
V_19 -> V_41 . V_121 = F_76 ( V_19 -> V_41 . V_121 ) ;
V_19 -> V_41 . V_122 = F_73 ( V_19 -> V_41 . V_122 ) ;
V_19 -> V_41 . V_79 = F_73 ( V_19 -> V_41 . V_79 ) ;
V_19 -> V_41 . V_123 = F_73 ( V_19 -> V_41 . V_123 ) ;
}
static void F_98 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_66 . type = F_73 ( V_19 -> V_66 . type ) ;
V_19 -> V_66 . V_124 = F_73 ( V_19 -> V_66 . V_124 ) ;
V_19 -> V_66 . V_123 = F_73 ( V_19 -> V_66 . V_123 ) ;
V_19 -> V_66 . V_78 = F_73 ( V_19 -> V_66 . V_78 ) ;
V_19 -> V_66 . V_79 = F_73 ( V_19 -> V_66 . V_79 ) ;
V_19 -> V_66 . V_125 = F_76 ( V_19 -> V_66 . V_125 ) ;
}
static void F_99 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
unsigned V_102 ;
V_19 -> V_67 . V_126 = F_76 ( V_19 -> V_67 . V_126 ) ;
for ( V_102 = 0 ; V_102 < V_19 -> V_67 . V_126 ; V_102 ++ )
V_19 -> V_67 . V_127 [ V_102 ] . V_78 = F_76 ( V_19 -> V_67 . V_127 [ V_102 ] . V_78 ) ;
}
static void F_100 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
struct V_128 * V_73 = & V_19 -> V_68 . V_73 ;
struct V_129 * V_130 ;
struct V_131 * V_132 ;
unsigned V_102 ;
V_73 -> type = F_76 ( V_73 -> type ) ;
switch ( V_73 -> type ) {
case V_133 :
V_130 = (struct V_129 * ) V_73 -> V_73 ;
V_130 -> V_126 = F_101 ( V_130 -> V_126 ) ;
for ( V_102 = 0 ; V_102 < V_130 -> V_126 ; V_102 ++ )
V_130 -> V_123 [ V_102 ] = F_101 ( V_130 -> V_123 [ V_102 ] ) ;
break;
case V_134 :
V_132 = (struct V_131 * ) V_73 -> V_73 ;
V_132 -> V_126 = F_101 ( V_132 -> V_126 ) ;
V_132 -> V_135 = F_101 ( V_132 -> V_135 ) ;
switch ( V_132 -> V_135 ) {
case 4 : F_102 ( & V_132 -> V_132 , V_132 -> V_126 ) ; break;
case 8 : F_70 ( & V_132 -> V_132 , V_132 -> V_126 ) ; break;
default:
F_3 ( L_9 ) ;
}
default:
break;
}
}
static void F_103 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_75 V_42 ;
V_42 = V_19 -> V_69 . V_126 * sizeof( V_19 -> V_69 . V_73 [ 0 ] ) ;
V_42 += 1 ;
F_70 ( & V_19 -> V_69 . V_126 , V_42 ) ;
}
static void F_104 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_70 . V_91 = F_76 ( V_19 -> V_70 . V_91 ) ;
V_19 -> V_70 . V_136 = F_73 ( V_19 -> V_70 . V_136 ) ;
V_19 -> V_70 . V_123 = F_73 ( V_19 -> V_70 . V_123 ) ;
V_19 -> V_70 . V_137 = F_76 ( V_19 -> V_70 . V_137 ) ;
V_19 -> V_70 . V_138 = F_76 ( V_19 -> V_70 . V_138 ) ;
V_19 -> V_70 . V_139 = F_76 ( V_19 -> V_70 . V_139 ) ;
}
static void F_105 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_71 . type = F_76 ( V_19 -> V_71 . type ) ;
V_19 -> V_71 . time = F_76 ( V_19 -> V_71 . time ) ;
}
static int V_63 ( struct V_25 * V_22 V_33 ,
union V_34 * V_19 V_33 ,
struct V_16 * V_17 )
{
if ( V_36 )
fprintf ( stdout , L_10 ) ;
return F_106 ( V_17 , V_140 ) ;
}
int F_107 ( struct V_1 * V_141 , union V_34 * V_19 ,
struct V_20 * V_21 , V_75 V_23 )
{
return F_108 ( & V_141 -> V_16 , V_19 , V_21 , V_23 ) ;
}
static void F_109 ( struct V_20 * V_21 )
{
struct V_142 * V_143 = V_21 -> V_143 ;
struct V_144 * V_145 = V_21 -> V_144 ;
V_75 V_146 = V_143 -> V_126 ;
unsigned int V_102 ;
for ( V_102 = 0 ; V_102 < V_146 ; V_102 ++ ) {
if ( V_143 -> V_147 [ V_102 ] == V_148 )
break;
}
if ( ( V_102 != V_146 ) && V_145 -> V_126 ) {
V_75 V_149 ;
V_149 = V_102 + 1 + V_145 -> V_126 + 1 ;
V_146 = V_102 + 1 ;
printf ( L_11 V_150 L_10 , V_149 ) ;
for ( V_102 = 0 ; V_102 < V_146 ; V_102 ++ )
printf ( L_12 V_151 L_10 ,
V_102 , V_143 -> V_147 [ V_102 ] ) ;
printf ( L_12 V_151 L_10 ,
( int ) ( V_146 ) , V_145 -> V_127 [ 0 ] . V_152 ) ;
for ( V_102 = 0 ; V_102 < V_145 -> V_126 ; V_102 ++ )
printf ( L_12 V_151 L_10 ,
( int ) ( V_102 + V_146 + 1 ) , V_145 -> V_127 [ V_102 ] . V_153 ) ;
}
}
static void F_110 ( struct V_12 * V_13 ,
struct V_20 * V_21 )
{
unsigned int V_102 ;
struct V_142 * V_143 = V_21 -> V_143 ;
if ( F_111 ( V_13 ) )
F_109 ( V_21 ) ;
printf ( L_13 V_150 L_10 , V_143 -> V_126 ) ;
for ( V_102 = 0 ; V_102 < V_143 -> V_126 ; V_102 ++ )
printf ( L_12 V_151 L_10 ,
V_102 , V_143 -> V_147 [ V_102 ] ) ;
}
static void F_112 ( struct V_20 * V_21 )
{
T_11 V_102 ;
printf ( L_14 V_150 L_10 , V_21 -> V_144 -> V_126 ) ;
for ( V_102 = 0 ; V_102 < V_21 -> V_144 -> V_126 ; V_102 ++ ) {
struct V_154 * V_155 = & V_21 -> V_144 -> V_127 [ V_102 ] ;
printf ( L_15 V_150 L_16 V_151 L_17 V_151 L_18 ,
V_102 , V_155 -> V_153 , V_155 -> V_152 ,
V_155 -> V_94 . V_156 ,
V_155 -> V_94 . V_157 ? L_19 : L_20 ,
V_155 -> V_94 . V_158 ? L_21 : L_20 ,
V_155 -> V_94 . abort ? L_22 : L_20 ,
V_155 -> V_94 . V_159 ? L_23 : L_20 ,
( unsigned ) V_155 -> V_94 . V_160 ) ;
}
}
static void F_113 ( V_75 V_132 , V_75 * V_161 )
{
unsigned V_162 , V_102 = 0 ;
F_114 (rid, (unsigned long *) &mask, sizeof(mask) * 8 ) {
V_75 V_137 = V_161 [ V_102 ++ ] ;
printf ( L_24 V_151 L_10 ,
F_115 ( V_162 ) , V_137 ) ;
}
}
static inline const char * F_116 ( struct V_163 * V_164 )
{
if ( V_164 -> V_165 > V_166 )
return L_25 ;
return V_167 [ V_164 -> V_165 ] ;
}
static void F_117 ( const char * type , struct V_163 * V_161 )
{
V_75 V_132 = V_161 -> V_132 ;
printf ( L_26 V_151 L_27 ,
type ,
V_132 ,
F_116 ( V_161 ) ) ;
F_113 ( V_132 , V_161 -> V_161 ) ;
}
static void F_118 ( struct V_20 * V_21 )
{
struct V_163 * V_168 = & V_21 -> V_168 ;
if ( V_168 -> V_161 )
F_117 ( L_28 , V_168 ) ;
}
static void F_119 ( struct V_20 * V_21 )
{
struct V_163 * V_169 = & V_21 -> V_169 ;
if ( V_169 -> V_161 )
F_117 ( L_29 , V_169 ) ;
}
static void F_120 ( struct V_170 * V_171 )
{
printf ( L_30 V_150 L_31 ,
V_171 -> V_42 , V_171 -> V_120 ) ;
}
static void F_121 ( struct V_35 * V_7 ,
union V_34 * V_19 ,
struct V_20 * V_21 )
{
V_75 V_106 = F_122 ( V_7 ) ;
if ( V_19 -> V_5 . type != V_172 &&
! F_34 ( V_7 ) ) {
fputs ( L_32 , stdout ) ;
return;
}
if ( ( V_106 & V_173 ) )
printf ( L_33 , V_21 -> V_123 ) ;
if ( V_106 & V_174 )
printf ( L_34 V_150 L_20 , V_21 -> time ) ;
}
static void F_123 ( struct V_20 * V_21 , V_75 V_107 )
{
printf ( L_35 ) ;
if ( V_107 & V_175 )
printf ( L_36 V_151 L_10 ,
V_21 -> F_52 . V_89 ) ;
if ( V_107 & V_176 )
printf ( L_37 V_151 L_10 ,
V_21 -> F_52 . V_90 ) ;
if ( V_107 & V_177 ) {
V_75 V_102 ;
printf ( L_38 V_150 L_10 , V_21 -> F_52 . V_178 . V_126 ) ;
for ( V_102 = 0 ; V_102 < V_21 -> F_52 . V_178 . V_126 ; V_102 ++ ) {
struct V_179 * V_88 ;
V_88 = & V_21 -> F_52 . V_178 . V_180 [ V_102 ] ;
printf ( L_39 V_151
L_40 V_151 L_10 ,
V_88 -> V_91 , V_88 -> V_88 ) ;
}
} else
printf ( L_39 V_151 L_40 V_151 L_10 ,
V_21 -> F_52 . V_181 . V_91 , V_21 -> F_52 . V_181 . V_88 ) ;
}
static void F_124 ( struct V_35 * V_7 , union V_34 * V_19 ,
V_75 V_23 , struct V_20 * V_21 )
{
if ( ! V_36 )
return;
printf ( L_41 V_151 L_42 ,
V_23 , V_19 -> V_5 . V_42 , V_19 -> V_5 . type ) ;
F_125 ( V_19 ) ;
if ( V_21 )
F_121 ( V_7 , V_19 , V_21 ) ;
printf ( L_43 V_151 L_44 , V_23 ,
V_19 -> V_5 . V_42 , F_126 ( V_19 -> V_5 . type ) ) ;
}
static void F_127 ( struct V_12 * V_13 , union V_34 * V_19 ,
struct V_20 * V_21 )
{
V_75 V_106 ;
if ( ! V_36 )
return;
printf ( L_45 V_151 L_46 V_150 L_47 V_151 L_10 ,
V_19 -> V_5 . V_182 , V_21 -> V_78 , V_21 -> V_79 , V_21 -> V_125 ,
V_21 -> V_183 , V_21 -> V_184 ) ;
V_106 = V_13 -> V_14 . V_106 ;
if ( V_106 & V_185 )
F_110 ( V_13 , V_21 ) ;
if ( ( V_106 & V_186 ) && ! F_111 ( V_13 ) )
F_112 ( V_21 ) ;
if ( V_106 & V_187 )
F_118 ( V_21 ) ;
if ( V_106 & V_188 )
F_119 ( V_21 ) ;
if ( V_106 & V_189 )
F_120 ( & V_21 -> V_190 ) ;
if ( V_106 & V_191 )
printf ( L_48 V_150 L_10 , V_21 -> V_192 ) ;
if ( V_106 & V_193 )
printf ( L_49 V_151 L_10 , V_21 -> V_194 ) ;
if ( V_106 & V_195 )
printf ( L_50 V_151 L_10 , V_21 -> V_196 ) ;
if ( V_106 & V_197 )
F_123 ( V_21 , V_13 -> V_14 . V_107 ) ;
}
static struct V_37 * F_128 ( struct V_9 * V_9 ,
union V_34 * V_19 ,
struct V_20 * V_21 )
{
struct V_37 * V_37 ;
if ( V_198 &&
( ( V_21 -> V_199 == V_200 ) ||
( V_21 -> V_199 == V_201 ) ) ) {
T_12 V_78 ;
if ( V_19 -> V_5 . type == V_202
|| V_19 -> V_5 . type == V_203 )
V_78 = V_19 -> V_43 . V_78 ;
else
V_78 = V_21 -> V_78 ;
V_37 = F_129 ( V_9 , V_78 ) ;
if ( ! V_37 )
V_37 = F_130 ( V_9 , V_204 ) ;
return V_37 ;
}
return & V_9 -> V_11 ;
}
static int F_131 ( struct V_35 * V_7 ,
struct V_25 * V_22 ,
union V_34 * V_19 ,
struct V_20 * V_21 ,
struct V_179 * V_205 ,
struct V_37 * V_37 )
{
struct V_206 * V_207 = F_132 ( V_7 , V_205 -> V_91 ) ;
if ( V_207 ) {
V_21 -> V_91 = V_205 -> V_91 ;
V_21 -> V_183 = V_205 -> V_88 - V_207 -> V_183 ;
V_207 -> V_183 = V_205 -> V_88 ;
}
if ( ! V_207 || V_207 -> V_13 == NULL ) {
++ V_7 -> V_208 . V_209 ;
return 0 ;
}
return V_22 -> V_21 ( V_22 , V_19 , V_21 , V_207 -> V_13 , V_37 ) ;
}
static int F_133 ( struct V_35 * V_7 ,
struct V_25 * V_22 ,
union V_34 * V_19 ,
struct V_20 * V_21 ,
struct V_37 * V_37 )
{
int V_10 = - V_210 ;
V_75 V_102 ;
for ( V_102 = 0 ; V_102 < V_21 -> F_52 . V_178 . V_126 ; V_102 ++ ) {
V_10 = F_131 ( V_7 , V_22 , V_19 , V_21 ,
& V_21 -> F_52 . V_178 . V_180 [ V_102 ] ,
V_37 ) ;
if ( V_10 )
break;
}
return V_10 ;
}
static int
F_134 ( struct V_35 * V_7 ,
struct V_25 * V_22 ,
union V_34 * V_19 ,
struct V_20 * V_21 ,
struct V_12 * V_13 ,
struct V_37 * V_37 )
{
V_75 V_106 = V_13 -> V_14 . V_106 ;
V_75 V_107 = V_13 -> V_14 . V_107 ;
if ( ! ( V_106 & V_197 ) )
return V_22 -> V_21 ( V_22 , V_19 , V_21 , V_13 , V_37 ) ;
if ( V_107 & V_177 )
return F_133 ( V_7 , V_22 , V_19 , V_21 ,
V_37 ) ;
else
return F_131 ( V_7 , V_22 , V_19 , V_21 ,
& V_21 -> F_52 . V_181 , V_37 ) ;
}
static int F_135 ( struct V_9 * V_9 ,
struct V_35 * V_7 ,
union V_34 * V_19 ,
struct V_20 * V_21 ,
struct V_25 * V_22 , V_75 V_23 )
{
struct V_12 * V_13 ;
struct V_37 * V_37 ;
F_124 ( V_7 , V_19 , V_23 , V_21 ) ;
V_13 = F_136 ( V_7 , V_21 -> V_91 ) ;
V_37 = F_128 ( V_9 , V_19 , V_21 ) ;
switch ( V_19 -> V_5 . type ) {
case V_172 :
if ( V_13 == NULL ) {
++ V_7 -> V_208 . V_209 ;
return 0 ;
}
F_127 ( V_13 , V_19 , V_21 ) ;
if ( V_37 == NULL ) {
++ V_7 -> V_208 . V_211 ;
return 0 ;
}
return F_134 ( V_7 , V_22 , V_19 , V_21 , V_13 , V_37 ) ;
case V_202 :
return V_22 -> V_43 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_203 :
if ( V_19 -> V_5 . V_182 & V_212 )
++ V_7 -> V_208 . V_213 ;
return V_22 -> V_44 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_214 :
return V_22 -> V_45 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_215 :
return V_22 -> V_46 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_216 :
return V_22 -> exit ( V_22 , V_19 , V_21 , V_37 ) ;
case V_217 :
if ( V_22 -> V_47 == V_48 )
V_7 -> V_208 . V_218 += V_19 -> V_47 . V_47 ;
return V_22 -> V_47 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_219 :
if ( V_22 -> V_49 == V_50 )
V_7 -> V_208 . V_220 += V_19 -> V_49 . V_47 ;
return V_22 -> V_49 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_221 :
return V_22 -> F_52 ( V_22 , V_19 , V_21 , V_13 , V_37 ) ;
case V_222 :
return V_22 -> V_57 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_223 :
return V_22 -> V_58 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_224 :
if ( V_22 -> V_51 == V_52 &&
( V_19 -> V_51 . V_94 & V_225 ) )
V_7 -> V_208 . V_226 += 1 ;
return V_22 -> V_51 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_227 :
return V_22 -> V_53 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_228 :
case V_95 :
return V_22 -> V_55 ( V_22 , V_19 , V_21 , V_37 ) ;
default:
++ V_7 -> V_208 . V_229 ;
return - 1 ;
}
}
static int F_24 ( struct V_1 * V_2 ,
union V_34 * V_19 ,
struct V_20 * V_21 ,
struct V_25 * V_22 ,
V_75 V_23 )
{
int V_10 ;
V_10 = F_137 ( V_2 , V_19 , V_21 , V_22 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_10 > 0 )
return 0 ;
return F_135 ( & V_2 -> V_9 , V_2 -> V_7 ,
V_19 , V_21 , V_22 , V_23 ) ;
}
static T_5 F_138 ( struct V_1 * V_2 ,
union V_34 * V_19 ,
V_75 V_23 )
{
struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_25 * V_22 = V_2 -> V_22 ;
int V_38 = F_55 ( V_2 -> V_4 ) ;
int V_230 ;
F_124 ( V_2 -> V_7 , V_19 , V_23 , NULL ) ;
switch ( V_19 -> V_5 . type ) {
case V_231 :
V_230 = V_22 -> V_14 ( V_22 , V_19 , & V_2 -> V_7 ) ;
if ( V_230 == 0 ) {
F_9 ( V_2 ) ;
F_19 ( V_2 ) ;
}
return V_230 ;
case V_232 :
return V_22 -> V_59 ( V_22 , V_19 , & V_2 -> V_7 ) ;
case V_233 :
return 0 ;
case V_234 :
F_139 ( V_38 , V_23 , V_235 ) ;
return V_22 -> V_60 ( V_22 , V_19 , V_2 ) ;
case V_236 :
return V_22 -> V_61 ( V_22 , V_19 , V_2 ) ;
case V_237 :
return V_22 -> V_62 ( V_22 , V_19 , V_17 ) ;
case V_238 :
return V_22 -> V_64 ( V_22 , V_19 , V_2 ) ;
case V_239 :
return V_22 -> V_65 ( V_22 , V_19 , V_2 ) ;
case V_240 :
F_139 ( V_38 , V_23 + V_19 -> V_5 . V_42 , V_235 ) ;
return V_22 -> V_41 ( V_22 , V_19 , V_2 ) ;
case V_241 :
F_140 ( V_2 , V_19 ) ;
return V_22 -> V_66 ( V_22 , V_19 , V_2 ) ;
case V_242 :
return V_22 -> V_67 ( V_22 , V_19 , V_2 ) ;
case V_243 :
return V_22 -> V_68 ( V_22 , V_19 , V_2 ) ;
case V_244 :
return V_22 -> V_69 ( V_22 , V_19 , V_2 ) ;
case V_245 :
return V_22 -> V_70 ( V_22 , V_19 , V_2 ) ;
case V_246 :
return V_22 -> V_71 ( V_22 , V_19 , V_2 ) ;
case V_247 :
V_2 -> V_72 = V_19 -> V_72 ;
return V_22 -> V_72 ( V_22 , V_19 , V_2 ) ;
default:
return - V_210 ;
}
}
int F_141 ( struct V_1 * V_2 ,
union V_34 * V_19 ,
struct V_20 * V_21 )
{
struct V_35 * V_7 = V_2 -> V_7 ;
struct V_25 * V_22 = V_2 -> V_22 ;
F_142 ( & V_7 -> V_208 , V_19 -> V_5 . type ) ;
if ( V_19 -> V_5 . type >= V_248 )
return F_138 ( V_2 , V_19 , 0 ) ;
return F_135 ( & V_2 -> V_9 , V_7 , V_19 , V_21 , V_22 , 0 ) ;
}
static void F_143 ( union V_34 * V_19 , bool T_6 )
{
T_13 V_249 ;
V_249 = V_250 [ V_19 -> V_5 . type ] ;
if ( V_249 )
V_249 ( V_19 , T_6 ) ;
}
int F_144 ( struct V_1 * V_2 , T_3 V_23 ,
void * V_40 , T_10 V_251 ,
union V_34 * * V_252 ,
struct V_20 * V_21 )
{
union V_34 * V_19 ;
T_10 V_253 , V_254 ;
int V_38 ;
if ( V_2 -> V_255 && ! V_2 -> V_5 . V_256 ) {
V_19 = V_23 - V_2 -> V_257 +
V_2 -> V_258 ;
goto V_259;
}
if ( F_4 ( V_2 -> V_4 ) )
return - 1 ;
V_38 = F_55 ( V_2 -> V_4 ) ;
V_253 = sizeof( struct V_76 ) ;
if ( V_251 < V_253 )
return - 1 ;
if ( F_139 ( V_38 , V_23 , V_235 ) == ( T_3 ) - 1 ||
F_145 ( V_38 , V_40 , V_253 ) != ( T_4 ) V_253 )
return - 1 ;
V_19 = (union V_34 * ) V_40 ;
if ( V_2 -> V_5 . V_256 )
F_146 ( & V_19 -> V_5 ) ;
if ( V_19 -> V_5 . V_42 < V_253 || V_19 -> V_5 . V_42 > V_251 )
return - 1 ;
V_254 = V_19 -> V_5 . V_42 - V_253 ;
if ( F_145 ( V_38 , V_40 , V_254 ) != ( T_4 ) V_254 )
return - 1 ;
if ( V_2 -> V_5 . V_256 )
F_143 ( V_19 , F_34 ( V_2 -> V_7 ) ) ;
V_259:
if ( V_21 && V_19 -> V_5 . type < V_248 &&
F_23 ( V_2 -> V_7 , V_19 , V_21 ) )
return - 1 ;
* V_252 = V_19 ;
return 0 ;
}
static T_5 F_147 ( struct V_1 * V_2 ,
union V_34 * V_19 , V_75 V_23 )
{
struct V_35 * V_7 = V_2 -> V_7 ;
struct V_25 * V_22 = V_2 -> V_22 ;
struct V_20 V_21 ;
int V_10 ;
if ( V_2 -> V_5 . V_256 )
F_143 ( V_19 , F_34 ( V_7 ) ) ;
if ( V_19 -> V_5 . type >= V_260 )
return - V_210 ;
F_142 ( & V_7 -> V_208 , V_19 -> V_5 . type ) ;
if ( V_19 -> V_5 . type >= V_248 )
return F_138 ( V_2 , V_19 , V_23 ) ;
V_10 = F_23 ( V_7 , V_19 , & V_21 ) ;
if ( V_10 )
return V_10 ;
if ( V_22 -> V_16 ) {
V_10 = F_107 ( V_2 , V_19 , & V_21 , V_23 ) ;
if ( V_10 != - V_261 )
return V_10 ;
}
return F_24 ( V_2 , V_19 , & V_21 , V_22 ,
V_23 ) ;
}
void F_146 ( struct V_76 * V_77 )
{
V_77 -> type = F_73 ( V_77 -> type ) ;
V_77 -> V_182 = F_101 ( V_77 -> V_182 ) ;
V_77 -> V_42 = F_101 ( V_77 -> V_42 ) ;
}
struct V_136 * F_148 ( struct V_1 * V_2 , T_14 V_78 )
{
return F_149 ( & V_2 -> V_9 . V_11 , - 1 , V_78 ) ;
}
int F_150 ( struct V_1 * V_2 )
{
struct V_136 * V_136 ;
int V_230 = 0 ;
V_136 = F_149 ( & V_2 -> V_9 . V_11 , 0 , 0 ) ;
if ( V_136 == NULL || F_151 ( V_136 , L_51 , 0 ) ) {
F_3 ( L_52 ) ;
V_230 = - 1 ;
}
F_152 ( V_136 ) ;
return V_230 ;
}
static void
F_153 ( const struct V_1 * V_2 )
{
const struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_12 * V_13 ;
bool V_262 = true ;
F_18 (session->evlist, evsel) {
if ( V_13 -> V_14 . V_263 )
V_262 = false ;
}
if ( ! V_262 )
return;
if ( V_17 -> V_264 != 0 )
F_154 ( L_53 , V_17 -> V_264 ) ;
}
static void F_155 ( const struct V_1 * V_2 )
{
const struct V_265 * V_208 = & V_2 -> V_7 -> V_208 ;
if ( V_2 -> V_22 -> V_47 == V_48 &&
V_208 -> V_266 [ V_217 ] != 0 ) {
F_154 ( L_54
L_55 ,
V_208 -> V_266 [ 0 ] ,
V_208 -> V_266 [ V_217 ] ) ;
}
if ( V_2 -> V_22 -> V_49 == V_50 ) {
double V_267 ;
V_267 = ( double ) V_208 -> V_220 /
( double ) ( V_208 -> V_266 [ V_172 ] + V_208 -> V_220 ) ;
if ( V_267 > 0.05 ) {
F_154 ( L_56 V_150 L_57 ,
V_208 -> V_266 [ V_172 ] + V_208 -> V_220 ,
V_267 * 100.0 ) ;
}
}
if ( V_2 -> V_22 -> V_51 == V_52 &&
V_208 -> V_226 != 0 ) {
F_154 ( L_58 V_150 L_59 ,
V_208 -> V_226 ,
V_208 -> V_266 [ V_224 ] ) ;
}
if ( V_208 -> V_229 != 0 ) {
F_154 ( L_60
L_61
L_62
L_63
L_64 ,
V_208 -> V_229 ) ;
}
if ( V_208 -> V_209 != 0 ) {
F_154 ( L_65 ,
V_208 -> V_209 ) ;
}
if ( V_208 -> V_268 != 0 ) {
F_154 ( L_66
L_67
L_68 ,
V_208 -> V_268 ,
V_208 -> V_266 [ V_172 ] ) ;
}
if ( V_208 -> V_211 != 0 ) {
F_154 ( L_69
L_70 ,
V_208 -> V_211 ) ;
}
F_153 ( V_2 ) ;
F_156 ( V_208 ) ;
if ( V_208 -> V_213 != 0 ) {
F_154 ( L_71
L_72
L_73
L_74
L_75
L_76
L_77 ,
V_208 -> V_213 ) ;
}
}
static int F_157 ( struct V_136 * V_136 ,
void * V_101 V_33 )
{
return F_158 ( V_136 ) ;
}
static int F_159 ( struct V_1 * V_2 )
{
return F_160 ( & V_2 -> V_9 ,
F_157 ,
NULL ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_25 * V_22 = V_2 -> V_22 ;
int V_38 = F_55 ( V_2 -> V_4 ) ;
union V_34 * V_19 ;
T_15 V_42 , V_269 = 0 ;
void * V_40 = NULL ;
T_5 V_270 = 0 ;
V_75 V_271 ;
T_4 V_230 ;
void * V_101 ;
F_67 ( V_22 ) ;
V_271 = 0 ;
V_269 = sizeof( union V_34 ) ;
V_40 = malloc ( V_269 ) ;
if ( ! V_40 )
return - V_272 ;
V_273:
V_19 = V_40 ;
V_230 = F_145 ( V_38 , V_19 , sizeof( struct V_76 ) ) ;
if ( V_230 <= 0 ) {
if ( V_230 == 0 )
goto V_274;
F_3 ( L_78 ) ;
goto V_275;
}
if ( V_2 -> V_5 . V_256 )
F_146 ( & V_19 -> V_5 ) ;
V_42 = V_19 -> V_5 . V_42 ;
if ( V_42 < sizeof( struct V_76 ) ) {
F_3 ( L_79 ) ;
goto V_275;
}
if ( V_42 > V_269 ) {
void * V_276 = realloc ( V_40 , V_42 ) ;
if ( ! V_276 ) {
F_3 ( L_80 ) ;
goto V_275;
}
V_40 = V_276 ;
V_269 = V_42 ;
V_19 = V_40 ;
}
V_101 = V_19 ;
V_101 += sizeof( struct V_76 ) ;
if ( V_42 - sizeof( struct V_76 ) ) {
V_230 = F_145 ( V_38 , V_101 , V_42 - sizeof( struct V_76 ) ) ;
if ( V_230 <= 0 ) {
if ( V_230 == 0 ) {
F_3 ( L_81 ) ;
goto V_274;
}
F_3 ( L_82 ) ;
goto V_275;
}
}
if ( ( V_270 = F_147 ( V_2 , V_19 , V_271 ) ) < 0 ) {
F_3 ( L_43 V_151 L_83 ,
V_271 , V_19 -> V_5 . V_42 , V_19 -> V_5 . type ) ;
V_230 = - V_210 ;
goto V_275;
}
V_271 += V_42 ;
if ( V_270 > 0 )
V_271 += V_270 ;
if ( ! F_162 () )
goto V_273;
V_274:
V_230 = F_106 ( V_17 , V_277 ) ;
if ( V_230 )
goto V_275;
V_230 = F_163 ( V_2 , V_22 ) ;
if ( V_230 )
goto V_275;
V_230 = F_159 ( V_2 ) ;
V_275:
free ( V_40 ) ;
F_155 ( V_2 ) ;
F_164 ( & V_2 -> V_16 ) ;
F_165 ( V_2 ) ;
return V_230 ;
}
static union V_34 *
F_166 ( struct V_1 * V_2 ,
V_75 V_271 , T_10 V_278 , char * V_40 )
{
union V_34 * V_19 ;
if ( V_271 + sizeof( V_19 -> V_5 ) > V_278 )
return NULL ;
V_19 = (union V_34 * ) ( V_40 + V_271 ) ;
if ( V_2 -> V_5 . V_256 )
F_146 ( & V_19 -> V_5 ) ;
if ( V_271 + V_19 -> V_5 . V_42 > V_278 ) {
if ( V_2 -> V_5 . V_256 )
F_146 ( & V_19 -> V_5 ) ;
return NULL ;
}
return V_19 ;
}
static int F_167 ( struct V_1 * V_2 ,
V_75 V_279 , V_75 V_280 ,
V_75 V_281 )
{
struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_25 * V_22 = V_2 -> V_22 ;
int V_38 = F_55 ( V_2 -> V_4 ) ;
V_75 V_271 , V_282 , V_23 , V_283 , V_42 ;
int V_230 , V_284 , V_285 , V_286 = 0 ;
T_10 V_278 ;
char * V_40 , * V_287 [ V_288 ] ;
union V_34 * V_19 ;
struct V_289 V_290 ;
T_5 V_270 ;
F_67 ( V_22 ) ;
V_282 = V_291 * ( V_279 / V_291 ) ;
V_23 = V_282 ;
V_271 = V_279 - V_282 ;
if ( V_280 == 0 )
goto V_26;
if ( V_279 + V_280 < V_281 )
V_281 = V_279 + V_280 ;
F_168 ( & V_290 , V_281 , L_84 ) ;
V_278 = V_292 ;
if ( V_278 > V_281 ) {
V_278 = V_281 ;
V_2 -> V_255 = true ;
}
memset ( V_287 , 0 , sizeof( V_287 ) ) ;
V_284 = V_293 ;
V_285 = V_294 ;
if ( V_2 -> V_5 . V_256 ) {
V_284 |= V_295 ;
V_285 = V_296 ;
}
V_297:
V_40 = V_43 ( NULL , V_278 , V_284 , V_285 , V_38 ,
V_23 ) ;
if ( V_40 == V_298 ) {
F_3 ( L_85 ) ;
V_230 = - V_272 ;
goto V_275;
}
V_287 [ V_286 ] = V_40 ;
V_286 = ( V_286 + 1 ) & ( F_169 ( V_287 ) - 1 ) ;
V_283 = V_23 + V_271 ;
if ( V_2 -> V_255 ) {
V_2 -> V_258 = V_40 ;
V_2 -> V_257 = V_23 ;
}
V_273:
V_19 = F_166 ( V_2 , V_271 , V_278 , V_40 ) ;
if ( ! V_19 ) {
if ( V_287 [ V_286 ] ) {
F_170 ( V_287 [ V_286 ] , V_278 ) ;
V_287 [ V_286 ] = NULL ;
}
V_282 = V_291 * ( V_271 / V_291 ) ;
V_23 += V_282 ;
V_271 -= V_282 ;
goto V_297;
}
V_42 = V_19 -> V_5 . V_42 ;
if ( V_42 < sizeof( struct V_76 ) ||
( V_270 = F_147 ( V_2 , V_19 , V_283 ) ) < 0 ) {
F_3 ( L_43 V_151 L_83 ,
V_23 + V_271 , V_19 -> V_5 . V_42 ,
V_19 -> V_5 . type ) ;
V_230 = - V_210 ;
goto V_275;
}
if ( V_270 )
V_42 += V_270 ;
V_271 += V_42 ;
V_283 += V_42 ;
F_171 ( & V_290 , V_42 ) ;
if ( F_162 () )
goto V_26;
if ( V_283 < V_281 )
goto V_273;
V_26:
V_230 = F_106 ( V_17 , V_277 ) ;
if ( V_230 )
goto V_275;
V_230 = F_163 ( V_2 , V_22 ) ;
if ( V_230 )
goto V_275;
V_230 = F_159 ( V_2 ) ;
V_275:
F_172 () ;
F_155 ( V_2 ) ;
F_173 ( & V_2 -> V_16 ) ;
F_165 ( V_2 ) ;
V_2 -> V_255 = false ;
return V_230 ;
}
int F_174 ( struct V_1 * V_2 )
{
V_75 V_42 = F_175 ( V_2 -> V_4 ) ;
int V_230 ;
if ( F_150 ( V_2 ) < 0 )
return - V_299 ;
if ( ! F_4 ( V_2 -> V_4 ) )
V_230 = F_167 ( V_2 ,
V_2 -> V_5 . V_279 ,
V_2 -> V_5 . V_280 , V_42 ) ;
else
V_230 = F_161 ( V_2 ) ;
return V_230 ;
}
bool F_176 ( struct V_1 * V_2 , const char * V_300 )
{
struct V_12 * V_13 ;
F_18 (session->evlist, evsel) {
if ( V_13 -> V_14 . type == V_301 )
return true ;
}
F_3 ( L_86 , V_300 ) ;
return false ;
}
int F_177 ( struct V_302 * * V_303 ,
const char * V_304 , V_75 V_184 )
{
char * V_305 ;
enum V_306 V_102 ;
struct V_307 * V_308 ;
V_308 = F_26 ( sizeof( struct V_307 ) ) ;
if ( V_308 == NULL )
return - V_299 ;
V_308 -> V_309 = F_178 ( V_304 ) ;
if ( V_308 -> V_309 == NULL ) {
free ( V_308 ) ;
return - V_299 ;
}
V_305 = strchr ( V_308 -> V_309 , ']' ) ;
if ( V_305 )
* V_305 = '\0' ;
V_308 -> V_184 = V_184 ;
for ( V_102 = 0 ; V_102 < V_310 ; ++ V_102 ) {
struct V_311 * V_311 = F_179 ( V_303 [ V_102 ] ) ;
if ( ! V_311 )
continue;
V_311 -> V_307 = V_308 ;
}
return 0 ;
}
T_10 F_180 ( struct V_1 * V_2 , T_16 * V_312 )
{
return F_181 ( & V_2 -> V_9 , V_312 ) ;
}
T_10 F_182 ( struct V_1 * V_2 , T_16 * V_312 ,
bool (V_270)( struct V_313 * V_313 , int V_314 ) , int V_314 )
{
return F_183 ( & V_2 -> V_9 , V_312 , V_270 , V_314 ) ;
}
T_10 F_184 ( struct V_1 * V_2 , T_16 * V_312 )
{
T_10 V_10 ;
const char * V_300 = L_87 ;
if ( F_5 ( & V_2 -> V_5 , V_315 ) )
V_300 = L_88 ;
V_10 = fprintf ( V_312 , L_89 , V_300 ) ;
V_10 += F_185 ( & V_2 -> V_7 -> V_208 , V_312 ) ;
return V_10 ;
}
T_10 F_186 ( struct V_1 * V_2 , T_16 * V_312 )
{
return F_187 ( & V_2 -> V_9 . V_11 , V_312 ) ;
}
struct V_12 * F_188 ( struct V_1 * V_2 ,
unsigned int type )
{
struct V_12 * V_316 ;
F_18 (session->evlist, pos) {
if ( V_316 -> V_14 . type == type )
return V_316 ;
}
return NULL ;
}
int F_189 ( struct V_1 * V_2 ,
const char * V_317 , unsigned long * V_318 )
{
int V_102 , V_230 = - 1 ;
struct V_68 * V_302 ;
for ( V_102 = 0 ; V_102 < V_319 ; ++ V_102 ) {
struct V_12 * V_13 ;
V_13 = F_188 ( V_2 , V_102 ) ;
if ( ! V_13 )
continue;
if ( ! ( V_13 -> V_14 . V_106 & V_173 ) ) {
F_3 ( L_90
L_91 ) ;
return - 1 ;
}
}
V_302 = F_190 ( V_317 ) ;
if ( V_302 == NULL ) {
F_3 ( L_92 ) ;
return - 1 ;
}
for ( V_102 = 0 ; V_102 < V_302 -> V_126 ; V_102 ++ ) {
int V_123 = V_302 -> V_302 [ V_102 ] ;
if ( V_123 >= V_320 ) {
F_3 ( L_93
L_94 , V_123 ) ;
goto V_321;
}
F_191 ( V_123 , V_318 ) ;
}
V_230 = 0 ;
V_321:
F_192 ( V_302 ) ;
return V_230 ;
}
void F_193 ( struct V_1 * V_2 , T_16 * V_312 ,
bool V_322 )
{
if ( V_2 == NULL || V_312 == NULL )
return;
fprintf ( V_312 , L_95 ) ;
F_194 ( V_2 , V_312 , V_322 ) ;
fprintf ( V_312 , L_96 ) ;
}
int F_195 ( struct V_1 * V_2 ,
const struct V_323 * V_324 ,
T_10 V_325 )
{
struct V_12 * V_13 ;
T_10 V_102 ;
int V_230 ;
for ( V_102 = 0 ; V_102 < V_325 ; V_102 ++ ) {
V_13 = F_196 ( V_2 -> V_7 , V_324 [ V_102 ] . V_309 ) ;
if ( V_13 == NULL )
continue;
V_230 = - V_326 ;
if ( V_13 -> V_327 != NULL )
goto V_26;
V_13 -> V_327 = V_324 [ V_102 ] . V_327 ;
}
V_230 = 0 ;
V_26:
return V_230 ;
}
int F_197 ( struct V_25 * V_22 V_33 ,
union V_34 * V_19 ,
struct V_1 * V_2 )
{
struct V_35 * V_7 = V_2 -> V_7 ;
struct V_328 * V_329 = & V_19 -> V_64 ;
T_10 V_102 , V_126 , V_330 ;
V_330 = ( V_329 -> V_5 . V_42 - sizeof( struct V_328 ) ) /
sizeof( struct V_331 ) ;
V_126 = V_329 -> V_126 ;
if ( V_126 > V_330 )
return - V_210 ;
if ( V_36 )
fprintf ( stdout , L_97 , V_126 ) ;
for ( V_102 = 0 ; V_102 < V_126 ; V_102 ++ ) {
struct V_331 * V_155 = & V_329 -> V_127 [ V_102 ] ;
struct V_206 * V_207 ;
if ( V_36 ) {
fprintf ( stdout , L_98 V_150 , V_155 -> V_91 ) ;
fprintf ( stdout , L_99 V_150 , V_155 -> V_122 ) ;
fprintf ( stdout , L_100 V_332 , V_155 -> V_123 ) ;
fprintf ( stdout , L_101 V_332 L_10 , V_155 -> V_79 ) ;
}
V_207 = F_132 ( V_7 , V_155 -> V_91 ) ;
if ( ! V_207 )
return - V_333 ;
V_207 -> V_122 = V_155 -> V_122 ;
V_207 -> V_123 = V_155 -> V_123 ;
V_207 -> V_79 = V_155 -> V_79 ;
}
return 0 ;
}
int F_198 ( struct V_25 * V_22 ,
T_17 V_334 ,
struct V_35 * V_7 ,
struct V_37 * V_37 )
{
union V_34 * V_335 ;
struct V_12 * V_13 ;
T_10 V_126 = 0 , V_102 = 0 , T_9 , V_330 , V_39 ;
int V_230 ;
F_199 ( L_102 ) ;
V_330 = ( V_336 - sizeof( struct V_328 ) ) /
sizeof( struct V_331 ) ;
F_18 (evlist, evsel)
V_126 += V_13 -> V_337 ;
V_39 = V_126 > V_330 ? V_330 : V_126 ;
T_9 = sizeof( struct V_328 ) + V_39 * sizeof( struct V_331 ) ;
V_335 = F_26 ( T_9 ) ;
if ( ! V_335 )
return - V_299 ;
V_335 -> V_64 . V_5 . type = V_238 ;
V_335 -> V_64 . V_5 . V_42 = T_9 ;
V_335 -> V_64 . V_126 = V_39 ;
F_18 (evlist, evsel) {
T_12 V_338 ;
for ( V_338 = 0 ; V_338 < V_13 -> V_337 ; V_338 ++ ) {
struct V_331 * V_155 ;
struct V_206 * V_207 ;
if ( V_102 >= V_39 ) {
V_230 = V_334 ( V_22 , V_335 , NULL , V_37 ) ;
if ( V_230 )
goto V_275;
V_126 -= V_39 ;
V_102 = 0 ;
}
V_155 = & V_335 -> V_64 . V_127 [ V_102 ++ ] ;
V_155 -> V_91 = V_13 -> V_91 [ V_338 ] ;
V_207 = F_132 ( V_7 , V_155 -> V_91 ) ;
if ( ! V_207 ) {
free ( V_335 ) ;
return - V_333 ;
}
V_155 -> V_122 = V_207 -> V_122 ;
V_155 -> V_123 = V_207 -> V_123 ;
V_155 -> V_79 = V_207 -> V_79 ;
}
}
T_9 = sizeof( struct V_328 ) + V_126 * sizeof( struct V_331 ) ;
V_335 -> V_64 . V_5 . V_42 = T_9 ;
V_335 -> V_64 . V_126 = V_126 ;
V_230 = V_334 ( V_22 , V_335 , NULL , V_37 ) ;
V_275:
free ( V_335 ) ;
return V_230 ;
}
