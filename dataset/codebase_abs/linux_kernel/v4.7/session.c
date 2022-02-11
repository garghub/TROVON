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
#define F_89 ( T_8 ) bswap_field(f, 32)
#define F_90 ( T_8 ) bswap_field(f, 64)
F_90 ( V_104 ) ;
F_90 ( V_105 ) ;
F_90 ( V_106 ) ;
F_90 ( V_107 ) ;
F_89 ( V_108 ) ;
F_89 ( V_109 ) ;
F_90 ( V_110 ) ;
F_90 ( V_111 ) ;
F_90 ( V_112 ) ;
F_90 ( V_113 ) ;
F_89 ( V_114 ) ;
F_89 ( V_115 ) ;
if ( F_87 ( V_107 , 1 ) )
F_85 ( ( T_7 * ) ( & V_14 -> V_107 + 1 ) ,
sizeof( V_75 ) ) ;
#undef F_90
#undef F_89
#undef F_88
#undef F_87
}
static void F_91 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
T_10 V_42 ;
F_86 ( & V_19 -> V_14 . V_14 ) ;
V_42 = V_19 -> V_5 . V_42 ;
V_42 -= ( void * ) & V_19 -> V_14 . V_91 - ( void * ) V_19 ;
F_70 ( V_19 -> V_14 . V_91 , V_42 ) ;
}
static void F_92 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_59 . type = F_76 ( V_19 -> V_59 . type ) ;
V_19 -> V_59 . V_91 = F_76 ( V_19 -> V_59 . V_91 ) ;
}
static void F_93 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_116 . V_116 . V_117 =
F_76 ( V_19 -> V_116 . V_116 . V_117 ) ;
}
static void F_94 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_60 . V_42 = F_73 ( V_19 -> V_60 . V_42 ) ;
}
static void F_95 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
T_10 V_42 ;
V_19 -> V_65 . type = F_73 ( V_19 -> V_65 . type ) ;
V_42 = V_19 -> V_5 . V_42 ;
V_42 -= ( void * ) & V_19 -> V_65 . V_118 - ( void * ) V_19 ;
F_70 ( V_19 -> V_65 . V_118 , V_42 ) ;
}
static void F_96 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_41 . V_42 = F_76 ( V_19 -> V_41 . V_42 ) ;
V_19 -> V_41 . V_119 = F_76 ( V_19 -> V_41 . V_119 ) ;
V_19 -> V_41 . V_120 = F_76 ( V_19 -> V_41 . V_120 ) ;
V_19 -> V_41 . V_121 = F_73 ( V_19 -> V_41 . V_121 ) ;
V_19 -> V_41 . V_79 = F_73 ( V_19 -> V_41 . V_79 ) ;
V_19 -> V_41 . V_122 = F_73 ( V_19 -> V_41 . V_122 ) ;
}
static void F_97 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_66 . type = F_73 ( V_19 -> V_66 . type ) ;
V_19 -> V_66 . V_123 = F_73 ( V_19 -> V_66 . V_123 ) ;
V_19 -> V_66 . V_122 = F_73 ( V_19 -> V_66 . V_122 ) ;
V_19 -> V_66 . V_78 = F_73 ( V_19 -> V_66 . V_78 ) ;
V_19 -> V_66 . V_79 = F_73 ( V_19 -> V_66 . V_79 ) ;
V_19 -> V_66 . V_124 = F_76 ( V_19 -> V_66 . V_124 ) ;
}
static void F_98 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
unsigned V_102 ;
V_19 -> V_67 . V_125 = F_76 ( V_19 -> V_67 . V_125 ) ;
for ( V_102 = 0 ; V_102 < V_19 -> V_67 . V_125 ; V_102 ++ )
V_19 -> V_67 . V_126 [ V_102 ] . V_78 = F_76 ( V_19 -> V_67 . V_126 [ V_102 ] . V_78 ) ;
}
static void F_99 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
struct V_127 * V_73 = & V_19 -> V_68 . V_73 ;
struct V_128 * V_129 ;
struct V_130 * V_131 ;
unsigned V_102 ;
V_73 -> type = F_76 ( V_73 -> type ) ;
switch ( V_73 -> type ) {
case V_132 :
V_129 = (struct V_128 * ) V_73 -> V_73 ;
V_129 -> V_125 = F_100 ( V_129 -> V_125 ) ;
for ( V_102 = 0 ; V_102 < V_129 -> V_125 ; V_102 ++ )
V_129 -> V_122 [ V_102 ] = F_100 ( V_129 -> V_122 [ V_102 ] ) ;
break;
case V_133 :
V_131 = (struct V_130 * ) V_73 -> V_73 ;
V_131 -> V_125 = F_100 ( V_131 -> V_125 ) ;
V_131 -> V_134 = F_100 ( V_131 -> V_134 ) ;
switch ( V_131 -> V_134 ) {
case 4 : F_101 ( & V_131 -> V_131 , V_131 -> V_125 ) ; break;
case 8 : F_70 ( & V_131 -> V_131 , V_131 -> V_125 ) ; break;
default:
F_3 ( L_9 ) ;
}
default:
break;
}
}
static void F_102 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_75 V_42 ;
V_42 = V_19 -> V_69 . V_125 * sizeof( V_19 -> V_69 . V_73 [ 0 ] ) ;
V_42 += 1 ;
F_70 ( & V_19 -> V_69 . V_125 , V_42 ) ;
}
static void F_103 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_70 . V_91 = F_76 ( V_19 -> V_70 . V_91 ) ;
V_19 -> V_70 . V_135 = F_73 ( V_19 -> V_70 . V_135 ) ;
V_19 -> V_70 . V_122 = F_73 ( V_19 -> V_70 . V_122 ) ;
V_19 -> V_70 . V_136 = F_76 ( V_19 -> V_70 . V_136 ) ;
V_19 -> V_70 . V_137 = F_76 ( V_19 -> V_70 . V_137 ) ;
V_19 -> V_70 . V_138 = F_76 ( V_19 -> V_70 . V_138 ) ;
}
static void F_104 ( union V_34 * V_19 ,
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
return F_105 ( V_17 , V_139 ) ;
}
int F_106 ( struct V_1 * V_140 , union V_34 * V_19 ,
struct V_20 * V_21 , V_75 V_23 )
{
return F_107 ( & V_140 -> V_16 , V_19 , V_21 , V_23 ) ;
}
static void F_108 ( struct V_20 * V_21 )
{
struct V_141 * V_142 = V_21 -> V_142 ;
struct V_143 * V_144 = V_21 -> V_143 ;
V_75 V_145 = V_142 -> V_125 ;
unsigned int V_102 ;
for ( V_102 = 0 ; V_102 < V_145 ; V_102 ++ ) {
if ( V_142 -> V_146 [ V_102 ] == V_147 )
break;
}
if ( ( V_102 != V_145 ) && V_144 -> V_125 ) {
V_75 V_148 ;
V_148 = V_102 + 1 + V_144 -> V_125 + 1 ;
V_145 = V_102 + 1 ;
printf ( L_11 V_149 L_10 , V_148 ) ;
for ( V_102 = 0 ; V_102 < V_145 ; V_102 ++ )
printf ( L_12 V_150 L_10 ,
V_102 , V_142 -> V_146 [ V_102 ] ) ;
printf ( L_12 V_150 L_10 ,
( int ) ( V_145 ) , V_144 -> V_126 [ 0 ] . V_151 ) ;
for ( V_102 = 0 ; V_102 < V_144 -> V_125 ; V_102 ++ )
printf ( L_12 V_150 L_10 ,
( int ) ( V_102 + V_145 + 1 ) , V_144 -> V_126 [ V_102 ] . V_152 ) ;
}
}
static void F_109 ( struct V_12 * V_13 ,
struct V_20 * V_21 )
{
unsigned int V_102 ;
struct V_141 * V_142 = V_21 -> V_142 ;
if ( F_110 ( V_13 ) )
F_108 ( V_21 ) ;
printf ( L_13 V_149 L_10 , V_142 -> V_125 ) ;
for ( V_102 = 0 ; V_102 < V_142 -> V_125 ; V_102 ++ )
printf ( L_12 V_150 L_10 ,
V_102 , V_142 -> V_146 [ V_102 ] ) ;
}
static void F_111 ( struct V_20 * V_21 )
{
T_11 V_102 ;
printf ( L_14 V_149 L_10 , V_21 -> V_143 -> V_125 ) ;
for ( V_102 = 0 ; V_102 < V_21 -> V_143 -> V_125 ; V_102 ++ ) {
struct V_153 * V_154 = & V_21 -> V_143 -> V_126 [ V_102 ] ;
printf ( L_15 V_149 L_16 V_150 L_17 V_150 L_18 ,
V_102 , V_154 -> V_152 , V_154 -> V_151 ,
V_154 -> V_94 . V_155 ,
V_154 -> V_94 . V_156 ? L_19 : L_20 ,
V_154 -> V_94 . V_157 ? L_21 : L_20 ,
V_154 -> V_94 . abort ? L_22 : L_20 ,
V_154 -> V_94 . V_158 ? L_23 : L_20 ,
( unsigned ) V_154 -> V_94 . V_159 ) ;
}
}
static void F_112 ( V_75 V_131 , V_75 * V_160 )
{
unsigned V_161 , V_102 = 0 ;
F_113 (rid, (unsigned long *) &mask, sizeof(mask) * 8 ) {
V_75 V_136 = V_160 [ V_102 ++ ] ;
printf ( L_24 V_150 L_10 ,
F_114 ( V_161 ) , V_136 ) ;
}
}
static inline const char * F_115 ( struct V_162 * V_163 )
{
if ( V_163 -> V_164 > V_165 )
return L_25 ;
return V_166 [ V_163 -> V_164 ] ;
}
static void F_116 ( const char * type , struct V_162 * V_160 )
{
V_75 V_131 = V_160 -> V_131 ;
printf ( L_26 V_150 L_27 ,
type ,
V_131 ,
F_115 ( V_160 ) ) ;
F_112 ( V_131 , V_160 -> V_160 ) ;
}
static void F_117 ( struct V_20 * V_21 )
{
struct V_162 * V_167 = & V_21 -> V_167 ;
if ( V_167 -> V_160 )
F_116 ( L_28 , V_167 ) ;
}
static void F_118 ( struct V_20 * V_21 )
{
struct V_162 * V_168 = & V_21 -> V_168 ;
if ( V_168 -> V_160 )
F_116 ( L_29 , V_168 ) ;
}
static void F_119 ( struct V_169 * V_170 )
{
printf ( L_30 V_149 L_31 ,
V_170 -> V_42 , V_170 -> V_119 ) ;
}
static void F_120 ( struct V_35 * V_7 ,
union V_34 * V_19 ,
struct V_20 * V_21 )
{
V_75 V_106 = F_121 ( V_7 ) ;
if ( V_19 -> V_5 . type != V_171 &&
! F_34 ( V_7 ) ) {
fputs ( L_32 , stdout ) ;
return;
}
if ( ( V_106 & V_172 ) )
printf ( L_33 , V_21 -> V_122 ) ;
if ( V_106 & V_173 )
printf ( L_34 V_149 L_20 , V_21 -> time ) ;
}
static void F_122 ( struct V_20 * V_21 , V_75 V_107 )
{
printf ( L_35 ) ;
if ( V_107 & V_174 )
printf ( L_36 V_150 L_10 ,
V_21 -> F_52 . V_89 ) ;
if ( V_107 & V_175 )
printf ( L_37 V_150 L_10 ,
V_21 -> F_52 . V_90 ) ;
if ( V_107 & V_176 ) {
V_75 V_102 ;
printf ( L_38 V_149 L_10 , V_21 -> F_52 . V_177 . V_125 ) ;
for ( V_102 = 0 ; V_102 < V_21 -> F_52 . V_177 . V_125 ; V_102 ++ ) {
struct V_178 * V_88 ;
V_88 = & V_21 -> F_52 . V_177 . V_179 [ V_102 ] ;
printf ( L_39 V_150
L_40 V_150 L_10 ,
V_88 -> V_91 , V_88 -> V_88 ) ;
}
} else
printf ( L_39 V_150 L_40 V_150 L_10 ,
V_21 -> F_52 . V_180 . V_91 , V_21 -> F_52 . V_180 . V_88 ) ;
}
static void F_123 ( struct V_35 * V_7 , union V_34 * V_19 ,
V_75 V_23 , struct V_20 * V_21 )
{
if ( ! V_36 )
return;
printf ( L_41 V_150 L_42 ,
V_23 , V_19 -> V_5 . V_42 , V_19 -> V_5 . type ) ;
F_124 ( V_19 ) ;
if ( V_21 )
F_120 ( V_7 , V_19 , V_21 ) ;
printf ( L_43 V_150 L_44 , V_23 ,
V_19 -> V_5 . V_42 , F_125 ( V_19 -> V_5 . type ) ) ;
}
static void F_126 ( struct V_12 * V_13 , union V_34 * V_19 ,
struct V_20 * V_21 )
{
V_75 V_106 ;
if ( ! V_36 )
return;
printf ( L_45 V_150 L_46 V_149 L_47 V_150 L_10 ,
V_19 -> V_5 . V_181 , V_21 -> V_78 , V_21 -> V_79 , V_21 -> V_124 ,
V_21 -> V_182 , V_21 -> V_183 ) ;
V_106 = V_13 -> V_14 . V_106 ;
if ( V_106 & V_184 )
F_109 ( V_13 , V_21 ) ;
if ( ( V_106 & V_185 ) && ! F_110 ( V_13 ) )
F_111 ( V_21 ) ;
if ( V_106 & V_186 )
F_117 ( V_21 ) ;
if ( V_106 & V_187 )
F_118 ( V_21 ) ;
if ( V_106 & V_188 )
F_119 ( & V_21 -> V_189 ) ;
if ( V_106 & V_190 )
printf ( L_48 V_149 L_10 , V_21 -> V_191 ) ;
if ( V_106 & V_192 )
printf ( L_49 V_150 L_10 , V_21 -> V_193 ) ;
if ( V_106 & V_194 )
printf ( L_50 V_150 L_10 , V_21 -> V_195 ) ;
if ( V_106 & V_196 )
F_122 ( V_21 , V_13 -> V_14 . V_107 ) ;
}
static struct V_37 * F_127 ( struct V_9 * V_9 ,
union V_34 * V_19 ,
struct V_20 * V_21 )
{
struct V_37 * V_37 ;
if ( V_197 &&
( ( V_21 -> V_198 == V_199 ) ||
( V_21 -> V_198 == V_200 ) ) ) {
T_12 V_78 ;
if ( V_19 -> V_5 . type == V_201
|| V_19 -> V_5 . type == V_202 )
V_78 = V_19 -> V_43 . V_78 ;
else
V_78 = V_21 -> V_78 ;
V_37 = F_128 ( V_9 , V_78 ) ;
if ( ! V_37 )
V_37 = F_129 ( V_9 , V_203 ) ;
return V_37 ;
}
return & V_9 -> V_11 ;
}
static int F_130 ( struct V_35 * V_7 ,
struct V_25 * V_22 ,
union V_34 * V_19 ,
struct V_20 * V_21 ,
struct V_178 * V_204 ,
struct V_37 * V_37 )
{
struct V_205 * V_206 = F_131 ( V_7 , V_204 -> V_91 ) ;
if ( V_206 ) {
V_21 -> V_91 = V_204 -> V_91 ;
V_21 -> V_182 = V_204 -> V_88 - V_206 -> V_182 ;
V_206 -> V_182 = V_204 -> V_88 ;
}
if ( ! V_206 || V_206 -> V_13 == NULL ) {
++ V_7 -> V_207 . V_208 ;
return 0 ;
}
return V_22 -> V_21 ( V_22 , V_19 , V_21 , V_206 -> V_13 , V_37 ) ;
}
static int F_132 ( struct V_35 * V_7 ,
struct V_25 * V_22 ,
union V_34 * V_19 ,
struct V_20 * V_21 ,
struct V_37 * V_37 )
{
int V_10 = - V_209 ;
V_75 V_102 ;
for ( V_102 = 0 ; V_102 < V_21 -> F_52 . V_177 . V_125 ; V_102 ++ ) {
V_10 = F_130 ( V_7 , V_22 , V_19 , V_21 ,
& V_21 -> F_52 . V_177 . V_179 [ V_102 ] ,
V_37 ) ;
if ( V_10 )
break;
}
return V_10 ;
}
static int
F_133 ( struct V_35 * V_7 ,
struct V_25 * V_22 ,
union V_34 * V_19 ,
struct V_20 * V_21 ,
struct V_12 * V_13 ,
struct V_37 * V_37 )
{
V_75 V_106 = V_13 -> V_14 . V_106 ;
V_75 V_107 = V_13 -> V_14 . V_107 ;
if ( ! ( V_106 & V_196 ) )
return V_22 -> V_21 ( V_22 , V_19 , V_21 , V_13 , V_37 ) ;
if ( V_107 & V_176 )
return F_132 ( V_7 , V_22 , V_19 , V_21 ,
V_37 ) ;
else
return F_130 ( V_7 , V_22 , V_19 , V_21 ,
& V_21 -> F_52 . V_180 , V_37 ) ;
}
static int F_134 ( struct V_9 * V_9 ,
struct V_35 * V_7 ,
union V_34 * V_19 ,
struct V_20 * V_21 ,
struct V_25 * V_22 , V_75 V_23 )
{
struct V_12 * V_13 ;
struct V_37 * V_37 ;
F_123 ( V_7 , V_19 , V_23 , V_21 ) ;
V_13 = F_135 ( V_7 , V_21 -> V_91 ) ;
V_37 = F_127 ( V_9 , V_19 , V_21 ) ;
switch ( V_19 -> V_5 . type ) {
case V_171 :
if ( V_13 == NULL ) {
++ V_7 -> V_207 . V_208 ;
return 0 ;
}
F_126 ( V_13 , V_19 , V_21 ) ;
if ( V_37 == NULL ) {
++ V_7 -> V_207 . V_210 ;
return 0 ;
}
return F_133 ( V_7 , V_22 , V_19 , V_21 , V_13 , V_37 ) ;
case V_201 :
return V_22 -> V_43 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_202 :
if ( V_19 -> V_5 . V_181 & V_211 )
++ V_7 -> V_207 . V_212 ;
return V_22 -> V_44 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_213 :
return V_22 -> V_45 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_214 :
return V_22 -> V_46 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_215 :
return V_22 -> exit ( V_22 , V_19 , V_21 , V_37 ) ;
case V_216 :
if ( V_22 -> V_47 == V_48 )
V_7 -> V_207 . V_217 += V_19 -> V_47 . V_47 ;
return V_22 -> V_47 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_218 :
if ( V_22 -> V_49 == V_50 )
V_7 -> V_207 . V_219 += V_19 -> V_49 . V_47 ;
return V_22 -> V_49 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_220 :
return V_22 -> F_52 ( V_22 , V_19 , V_21 , V_13 , V_37 ) ;
case V_221 :
return V_22 -> V_57 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_222 :
return V_22 -> V_58 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_223 :
if ( V_22 -> V_51 == V_52 &&
( V_19 -> V_51 . V_94 & V_224 ) )
V_7 -> V_207 . V_225 += 1 ;
return V_22 -> V_51 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_226 :
return V_22 -> V_53 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_227 :
case V_95 :
return V_22 -> V_55 ( V_22 , V_19 , V_21 , V_37 ) ;
default:
++ V_7 -> V_207 . V_228 ;
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
V_10 = F_136 ( V_2 , V_19 , V_21 , V_22 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_10 > 0 )
return 0 ;
return F_134 ( & V_2 -> V_9 , V_2 -> V_7 ,
V_19 , V_21 , V_22 , V_23 ) ;
}
static T_5 F_137 ( struct V_1 * V_2 ,
union V_34 * V_19 ,
V_75 V_23 )
{
struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_25 * V_22 = V_2 -> V_22 ;
int V_38 = F_55 ( V_2 -> V_4 ) ;
int V_229 ;
F_123 ( V_2 -> V_7 , V_19 , V_23 , NULL ) ;
switch ( V_19 -> V_5 . type ) {
case V_230 :
V_229 = V_22 -> V_14 ( V_22 , V_19 , & V_2 -> V_7 ) ;
if ( V_229 == 0 ) {
F_9 ( V_2 ) ;
F_19 ( V_2 ) ;
}
return V_229 ;
case V_231 :
return V_22 -> V_59 ( V_22 , V_19 , & V_2 -> V_7 ) ;
case V_232 :
return 0 ;
case V_233 :
F_138 ( V_38 , V_23 , V_234 ) ;
return V_22 -> V_60 ( V_22 , V_19 , V_2 ) ;
case V_235 :
return V_22 -> V_61 ( V_22 , V_19 , V_2 ) ;
case V_236 :
return V_22 -> V_62 ( V_22 , V_19 , V_17 ) ;
case V_237 :
return V_22 -> V_64 ( V_22 , V_19 , V_2 ) ;
case V_238 :
return V_22 -> V_65 ( V_22 , V_19 , V_2 ) ;
case V_239 :
F_138 ( V_38 , V_23 + V_19 -> V_5 . V_42 , V_234 ) ;
return V_22 -> V_41 ( V_22 , V_19 , V_2 ) ;
case V_240 :
F_139 ( V_2 , V_19 ) ;
return V_22 -> V_66 ( V_22 , V_19 , V_2 ) ;
case V_241 :
return V_22 -> V_67 ( V_22 , V_19 , V_2 ) ;
case V_242 :
return V_22 -> V_68 ( V_22 , V_19 , V_2 ) ;
case V_243 :
return V_22 -> V_69 ( V_22 , V_19 , V_2 ) ;
case V_244 :
return V_22 -> V_70 ( V_22 , V_19 , V_2 ) ;
case V_245 :
return V_22 -> V_71 ( V_22 , V_19 , V_2 ) ;
case V_246 :
V_2 -> V_72 = V_19 -> V_72 ;
return V_22 -> V_72 ( V_22 , V_19 , V_2 ) ;
default:
return - V_209 ;
}
}
int F_140 ( struct V_1 * V_2 ,
union V_34 * V_19 ,
struct V_20 * V_21 )
{
struct V_35 * V_7 = V_2 -> V_7 ;
struct V_25 * V_22 = V_2 -> V_22 ;
F_141 ( & V_7 -> V_207 , V_19 -> V_5 . type ) ;
if ( V_19 -> V_5 . type >= V_247 )
return F_137 ( V_2 , V_19 , 0 ) ;
return F_134 ( & V_2 -> V_9 , V_7 , V_19 , V_21 , V_22 , 0 ) ;
}
static void F_142 ( union V_34 * V_19 , bool T_6 )
{
T_13 V_248 ;
V_248 = V_249 [ V_19 -> V_5 . type ] ;
if ( V_248 )
V_248 ( V_19 , T_6 ) ;
}
int F_143 ( struct V_1 * V_2 , T_3 V_23 ,
void * V_40 , T_10 V_250 ,
union V_34 * * V_251 ,
struct V_20 * V_21 )
{
union V_34 * V_19 ;
T_10 V_252 , V_253 ;
int V_38 ;
if ( V_2 -> V_254 && ! V_2 -> V_5 . V_255 ) {
V_19 = V_23 - V_2 -> V_256 +
V_2 -> V_257 ;
goto V_258;
}
if ( F_4 ( V_2 -> V_4 ) )
return - 1 ;
V_38 = F_55 ( V_2 -> V_4 ) ;
V_252 = sizeof( struct V_76 ) ;
if ( V_250 < V_252 )
return - 1 ;
if ( F_138 ( V_38 , V_23 , V_234 ) == ( T_3 ) - 1 ||
F_144 ( V_38 , V_40 , V_252 ) != ( T_4 ) V_252 )
return - 1 ;
V_19 = (union V_34 * ) V_40 ;
if ( V_2 -> V_5 . V_255 )
F_145 ( & V_19 -> V_5 ) ;
if ( V_19 -> V_5 . V_42 < V_252 || V_19 -> V_5 . V_42 > V_250 )
return - 1 ;
V_253 = V_19 -> V_5 . V_42 - V_252 ;
if ( F_144 ( V_38 , V_40 , V_253 ) != ( T_4 ) V_253 )
return - 1 ;
if ( V_2 -> V_5 . V_255 )
F_142 ( V_19 , F_34 ( V_2 -> V_7 ) ) ;
V_258:
if ( V_21 && V_19 -> V_5 . type < V_247 &&
F_23 ( V_2 -> V_7 , V_19 , V_21 ) )
return - 1 ;
* V_251 = V_19 ;
return 0 ;
}
static T_5 F_146 ( struct V_1 * V_2 ,
union V_34 * V_19 , V_75 V_23 )
{
struct V_35 * V_7 = V_2 -> V_7 ;
struct V_25 * V_22 = V_2 -> V_22 ;
struct V_20 V_21 ;
int V_10 ;
if ( V_2 -> V_5 . V_255 )
F_142 ( V_19 , F_34 ( V_7 ) ) ;
if ( V_19 -> V_5 . type >= V_259 )
return - V_209 ;
F_141 ( & V_7 -> V_207 , V_19 -> V_5 . type ) ;
if ( V_19 -> V_5 . type >= V_247 )
return F_137 ( V_2 , V_19 , V_23 ) ;
V_10 = F_23 ( V_7 , V_19 , & V_21 ) ;
if ( V_10 )
return V_10 ;
if ( V_22 -> V_16 ) {
V_10 = F_106 ( V_2 , V_19 , & V_21 , V_23 ) ;
if ( V_10 != - V_260 )
return V_10 ;
}
return F_24 ( V_2 , V_19 , & V_21 , V_22 ,
V_23 ) ;
}
void F_145 ( struct V_76 * V_77 )
{
V_77 -> type = F_73 ( V_77 -> type ) ;
V_77 -> V_181 = F_100 ( V_77 -> V_181 ) ;
V_77 -> V_42 = F_100 ( V_77 -> V_42 ) ;
}
struct V_135 * F_147 ( struct V_1 * V_2 , T_14 V_78 )
{
return F_148 ( & V_2 -> V_9 . V_11 , - 1 , V_78 ) ;
}
int F_149 ( struct V_1 * V_2 )
{
struct V_135 * V_135 ;
int V_229 = 0 ;
V_135 = F_148 ( & V_2 -> V_9 . V_11 , 0 , 0 ) ;
if ( V_135 == NULL || F_150 ( V_135 , L_51 , 0 ) ) {
F_3 ( L_52 ) ;
V_229 = - 1 ;
}
F_151 ( V_135 ) ;
return V_229 ;
}
static void F_152 ( const struct V_1 * V_2 )
{
const struct V_261 * V_207 = & V_2 -> V_7 -> V_207 ;
const struct V_16 * V_17 = & V_2 -> V_16 ;
if ( V_2 -> V_22 -> V_47 == V_48 &&
V_207 -> V_262 [ V_216 ] != 0 ) {
F_153 ( L_53
L_54 ,
V_207 -> V_262 [ 0 ] ,
V_207 -> V_262 [ V_216 ] ) ;
}
if ( V_2 -> V_22 -> V_49 == V_50 ) {
double V_263 ;
V_263 = ( double ) V_207 -> V_219 /
( double ) ( V_207 -> V_262 [ V_171 ] + V_207 -> V_219 ) ;
if ( V_263 > 0.05 ) {
F_153 ( L_55 V_149 L_56 ,
V_207 -> V_262 [ V_171 ] + V_207 -> V_219 ,
V_263 * 100.0 ) ;
}
}
if ( V_2 -> V_22 -> V_51 == V_52 &&
V_207 -> V_225 != 0 ) {
F_153 ( L_57 V_149 L_58 ,
V_207 -> V_225 ,
V_207 -> V_262 [ V_223 ] ) ;
}
if ( V_207 -> V_228 != 0 ) {
F_153 ( L_59
L_60
L_61
L_62
L_63 ,
V_207 -> V_228 ) ;
}
if ( V_207 -> V_208 != 0 ) {
F_153 ( L_64 ,
V_207 -> V_208 ) ;
}
if ( V_207 -> V_264 != 0 ) {
F_153 ( L_65
L_66
L_67 ,
V_207 -> V_264 ,
V_207 -> V_262 [ V_171 ] ) ;
}
if ( V_207 -> V_210 != 0 ) {
F_153 ( L_68
L_69 ,
V_207 -> V_210 ) ;
}
if ( V_17 -> V_265 != 0 )
F_153 ( L_70 , V_17 -> V_265 ) ;
F_154 ( V_207 ) ;
if ( V_207 -> V_212 != 0 ) {
F_153 ( L_71
L_72
L_73
L_74
L_75
L_76
L_77 ,
V_207 -> V_212 ) ;
}
}
static int F_155 ( struct V_135 * V_135 ,
void * V_101 V_33 )
{
return F_156 ( V_135 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
return F_158 ( & V_2 -> V_9 ,
F_155 ,
NULL ) ;
}
static int F_159 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_25 * V_22 = V_2 -> V_22 ;
int V_38 = F_55 ( V_2 -> V_4 ) ;
union V_34 * V_19 ;
T_15 V_42 , V_266 = 0 ;
void * V_40 = NULL ;
T_5 V_267 = 0 ;
V_75 V_268 ;
T_4 V_229 ;
void * V_101 ;
F_67 ( V_22 ) ;
V_268 = 0 ;
V_266 = sizeof( union V_34 ) ;
V_40 = malloc ( V_266 ) ;
if ( ! V_40 )
return - V_269 ;
V_270:
V_19 = V_40 ;
V_229 = F_144 ( V_38 , V_19 , sizeof( struct V_76 ) ) ;
if ( V_229 <= 0 ) {
if ( V_229 == 0 )
goto V_271;
F_3 ( L_78 ) ;
goto V_272;
}
if ( V_2 -> V_5 . V_255 )
F_145 ( & V_19 -> V_5 ) ;
V_42 = V_19 -> V_5 . V_42 ;
if ( V_42 < sizeof( struct V_76 ) ) {
F_3 ( L_79 ) ;
goto V_272;
}
if ( V_42 > V_266 ) {
void * V_273 = realloc ( V_40 , V_42 ) ;
if ( ! V_273 ) {
F_3 ( L_80 ) ;
goto V_272;
}
V_40 = V_273 ;
V_266 = V_42 ;
V_19 = V_40 ;
}
V_101 = V_19 ;
V_101 += sizeof( struct V_76 ) ;
if ( V_42 - sizeof( struct V_76 ) ) {
V_229 = F_144 ( V_38 , V_101 , V_42 - sizeof( struct V_76 ) ) ;
if ( V_229 <= 0 ) {
if ( V_229 == 0 ) {
F_3 ( L_81 ) ;
goto V_271;
}
F_3 ( L_82 ) ;
goto V_272;
}
}
if ( ( V_267 = F_146 ( V_2 , V_19 , V_268 ) ) < 0 ) {
F_3 ( L_43 V_150 L_83 ,
V_268 , V_19 -> V_5 . V_42 , V_19 -> V_5 . type ) ;
V_229 = - V_209 ;
goto V_272;
}
V_268 += V_42 ;
if ( V_267 > 0 )
V_268 += V_267 ;
if ( ! F_160 () )
goto V_270;
V_271:
V_229 = F_105 ( V_17 , V_274 ) ;
if ( V_229 )
goto V_272;
V_229 = F_161 ( V_2 , V_22 ) ;
if ( V_229 )
goto V_272;
V_229 = F_157 ( V_2 ) ;
V_272:
free ( V_40 ) ;
F_152 ( V_2 ) ;
F_162 ( & V_2 -> V_16 ) ;
F_163 ( V_2 ) ;
return V_229 ;
}
static union V_34 *
F_164 ( struct V_1 * V_2 ,
V_75 V_268 , T_10 V_275 , char * V_40 )
{
union V_34 * V_19 ;
if ( V_268 + sizeof( V_19 -> V_5 ) > V_275 )
return NULL ;
V_19 = (union V_34 * ) ( V_40 + V_268 ) ;
if ( V_2 -> V_5 . V_255 )
F_145 ( & V_19 -> V_5 ) ;
if ( V_268 + V_19 -> V_5 . V_42 > V_275 ) {
if ( V_2 -> V_5 . V_255 )
F_145 ( & V_19 -> V_5 ) ;
return NULL ;
}
return V_19 ;
}
static int F_165 ( struct V_1 * V_2 ,
V_75 V_276 , V_75 V_277 ,
V_75 V_278 )
{
struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_25 * V_22 = V_2 -> V_22 ;
int V_38 = F_55 ( V_2 -> V_4 ) ;
V_75 V_268 , V_279 , V_23 , V_280 , V_42 ;
int V_229 , V_281 , V_282 , V_283 = 0 ;
T_10 V_275 ;
char * V_40 , * V_284 [ V_285 ] ;
union V_34 * V_19 ;
struct V_286 V_287 ;
T_5 V_267 ;
F_67 ( V_22 ) ;
V_279 = V_288 * ( V_276 / V_288 ) ;
V_23 = V_279 ;
V_268 = V_276 - V_279 ;
if ( V_277 == 0 )
goto V_26;
if ( V_276 + V_277 < V_278 )
V_278 = V_276 + V_277 ;
F_166 ( & V_287 , V_278 , L_84 ) ;
V_275 = V_289 ;
if ( V_275 > V_278 ) {
V_275 = V_278 ;
V_2 -> V_254 = true ;
}
memset ( V_284 , 0 , sizeof( V_284 ) ) ;
V_281 = V_290 ;
V_282 = V_291 ;
if ( V_2 -> V_5 . V_255 ) {
V_281 |= V_292 ;
V_282 = V_293 ;
}
V_294:
V_40 = V_43 ( NULL , V_275 , V_281 , V_282 , V_38 ,
V_23 ) ;
if ( V_40 == V_295 ) {
F_3 ( L_85 ) ;
V_229 = - V_269 ;
goto V_272;
}
V_284 [ V_283 ] = V_40 ;
V_283 = ( V_283 + 1 ) & ( F_167 ( V_284 ) - 1 ) ;
V_280 = V_23 + V_268 ;
if ( V_2 -> V_254 ) {
V_2 -> V_257 = V_40 ;
V_2 -> V_256 = V_23 ;
}
V_270:
V_19 = F_164 ( V_2 , V_268 , V_275 , V_40 ) ;
if ( ! V_19 ) {
if ( V_284 [ V_283 ] ) {
F_168 ( V_284 [ V_283 ] , V_275 ) ;
V_284 [ V_283 ] = NULL ;
}
V_279 = V_288 * ( V_268 / V_288 ) ;
V_23 += V_279 ;
V_268 -= V_279 ;
goto V_294;
}
V_42 = V_19 -> V_5 . V_42 ;
if ( V_42 < sizeof( struct V_76 ) ||
( V_267 = F_146 ( V_2 , V_19 , V_280 ) ) < 0 ) {
F_3 ( L_43 V_150 L_83 ,
V_23 + V_268 , V_19 -> V_5 . V_42 ,
V_19 -> V_5 . type ) ;
V_229 = - V_209 ;
goto V_272;
}
if ( V_267 )
V_42 += V_267 ;
V_268 += V_42 ;
V_280 += V_42 ;
F_169 ( & V_287 , V_42 ) ;
if ( F_160 () )
goto V_26;
if ( V_280 < V_278 )
goto V_270;
V_26:
V_229 = F_105 ( V_17 , V_274 ) ;
if ( V_229 )
goto V_272;
V_229 = F_161 ( V_2 , V_22 ) ;
if ( V_229 )
goto V_272;
V_229 = F_157 ( V_2 ) ;
V_272:
F_170 () ;
F_152 ( V_2 ) ;
F_171 ( & V_2 -> V_16 ) ;
F_163 ( V_2 ) ;
V_2 -> V_254 = false ;
return V_229 ;
}
int F_172 ( struct V_1 * V_2 )
{
V_75 V_42 = F_173 ( V_2 -> V_4 ) ;
int V_229 ;
if ( F_149 ( V_2 ) < 0 )
return - V_296 ;
if ( ! F_4 ( V_2 -> V_4 ) )
V_229 = F_165 ( V_2 ,
V_2 -> V_5 . V_276 ,
V_2 -> V_5 . V_277 , V_42 ) ;
else
V_229 = F_159 ( V_2 ) ;
return V_229 ;
}
bool F_174 ( struct V_1 * V_2 , const char * V_297 )
{
struct V_12 * V_13 ;
F_18 (session->evlist, evsel) {
if ( V_13 -> V_14 . type == V_298 )
return true ;
}
F_3 ( L_86 , V_297 ) ;
return false ;
}
int F_175 ( struct V_299 * * V_300 ,
const char * V_301 , V_75 V_183 )
{
char * V_302 ;
enum V_303 V_102 ;
struct V_304 * V_305 ;
V_305 = F_26 ( sizeof( struct V_304 ) ) ;
if ( V_305 == NULL )
return - V_296 ;
V_305 -> V_306 = F_176 ( V_301 ) ;
if ( V_305 -> V_306 == NULL ) {
free ( V_305 ) ;
return - V_296 ;
}
V_302 = strchr ( V_305 -> V_306 , ']' ) ;
if ( V_302 )
* V_302 = '\0' ;
V_305 -> V_183 = V_183 ;
for ( V_102 = 0 ; V_102 < V_307 ; ++ V_102 ) {
struct V_308 * V_308 = F_177 ( V_300 [ V_102 ] ) ;
if ( ! V_308 )
continue;
V_308 -> V_304 = V_305 ;
}
return 0 ;
}
T_10 F_178 ( struct V_1 * V_2 , T_16 * V_309 )
{
return F_179 ( & V_2 -> V_9 , V_309 ) ;
}
T_10 F_180 ( struct V_1 * V_2 , T_16 * V_309 ,
bool (V_267)( struct V_310 * V_310 , int V_311 ) , int V_311 )
{
return F_181 ( & V_2 -> V_9 , V_309 , V_267 , V_311 ) ;
}
T_10 F_182 ( struct V_1 * V_2 , T_16 * V_309 )
{
T_10 V_10 ;
const char * V_297 = L_87 ;
if ( F_5 ( & V_2 -> V_5 , V_312 ) )
V_297 = L_88 ;
V_10 = fprintf ( V_309 , L_89 , V_297 ) ;
V_10 += F_183 ( & V_2 -> V_7 -> V_207 , V_309 ) ;
return V_10 ;
}
T_10 F_184 ( struct V_1 * V_2 , T_16 * V_309 )
{
return F_185 ( & V_2 -> V_9 . V_11 , V_309 ) ;
}
struct V_12 * F_186 ( struct V_1 * V_2 ,
unsigned int type )
{
struct V_12 * V_313 ;
F_18 (session->evlist, pos) {
if ( V_313 -> V_14 . type == type )
return V_313 ;
}
return NULL ;
}
int F_187 ( struct V_1 * V_2 ,
const char * V_314 , unsigned long * V_315 )
{
int V_102 , V_229 = - 1 ;
struct V_68 * V_299 ;
for ( V_102 = 0 ; V_102 < V_316 ; ++ V_102 ) {
struct V_12 * V_13 ;
V_13 = F_186 ( V_2 , V_102 ) ;
if ( ! V_13 )
continue;
if ( ! ( V_13 -> V_14 . V_106 & V_172 ) ) {
F_3 ( L_90
L_91 ) ;
return - 1 ;
}
}
V_299 = F_188 ( V_314 ) ;
if ( V_299 == NULL ) {
F_3 ( L_92 ) ;
return - 1 ;
}
for ( V_102 = 0 ; V_102 < V_299 -> V_125 ; V_102 ++ ) {
int V_122 = V_299 -> V_299 [ V_102 ] ;
if ( V_122 >= V_317 ) {
F_3 ( L_93
L_94 , V_122 ) ;
goto V_318;
}
F_189 ( V_122 , V_315 ) ;
}
V_229 = 0 ;
V_318:
F_190 ( V_299 ) ;
return V_229 ;
}
void F_191 ( struct V_1 * V_2 , T_16 * V_309 ,
bool V_319 )
{
struct V_70 V_320 ;
int V_38 , V_10 ;
if ( V_2 == NULL || V_309 == NULL )
return;
V_38 = F_55 ( V_2 -> V_4 ) ;
V_10 = F_192 ( V_38 , & V_320 ) ;
if ( V_10 == - 1 )
return;
fprintf ( V_309 , L_95 ) ;
fprintf ( V_309 , L_96 , ctime ( & V_320 . V_321 ) ) ;
F_193 ( V_2 , V_309 , V_319 ) ;
fprintf ( V_309 , L_97 ) ;
}
int F_194 ( struct V_1 * V_2 ,
const struct V_322 * V_323 ,
T_10 V_324 )
{
struct V_12 * V_13 ;
T_10 V_102 ;
int V_229 ;
for ( V_102 = 0 ; V_102 < V_324 ; V_102 ++ ) {
V_13 = F_195 ( V_2 -> V_7 , V_323 [ V_102 ] . V_306 ) ;
if ( V_13 == NULL )
continue;
V_229 = - V_325 ;
if ( V_13 -> V_326 != NULL )
goto V_26;
V_13 -> V_326 = V_323 [ V_102 ] . V_326 ;
}
V_229 = 0 ;
V_26:
return V_229 ;
}
int F_196 ( struct V_25 * V_22 V_33 ,
union V_34 * V_19 ,
struct V_1 * V_2 )
{
struct V_35 * V_7 = V_2 -> V_7 ;
struct V_327 * V_328 = & V_19 -> V_64 ;
T_10 V_102 , V_125 , V_329 ;
V_329 = ( V_328 -> V_5 . V_42 - sizeof( struct V_327 ) ) /
sizeof( struct V_330 ) ;
V_125 = V_328 -> V_125 ;
if ( V_125 > V_329 )
return - V_209 ;
if ( V_36 )
fprintf ( stdout , L_98 , V_125 ) ;
for ( V_102 = 0 ; V_102 < V_125 ; V_102 ++ ) {
struct V_330 * V_154 = & V_328 -> V_126 [ V_102 ] ;
struct V_205 * V_206 ;
if ( V_36 ) {
fprintf ( stdout , L_99 V_149 , V_154 -> V_91 ) ;
fprintf ( stdout , L_100 V_149 , V_154 -> V_121 ) ;
fprintf ( stdout , L_101 V_331 , V_154 -> V_122 ) ;
fprintf ( stdout , L_102 V_331 L_10 , V_154 -> V_79 ) ;
}
V_206 = F_131 ( V_7 , V_154 -> V_91 ) ;
if ( ! V_206 )
return - V_332 ;
V_206 -> V_121 = V_154 -> V_121 ;
V_206 -> V_122 = V_154 -> V_122 ;
V_206 -> V_79 = V_154 -> V_79 ;
}
return 0 ;
}
int F_197 ( struct V_25 * V_22 ,
T_17 V_333 ,
struct V_35 * V_7 ,
struct V_37 * V_37 )
{
union V_34 * V_334 ;
struct V_12 * V_13 ;
T_10 V_125 = 0 , V_102 = 0 , T_9 , V_329 , V_39 ;
int V_229 ;
F_198 ( L_103 ) ;
V_329 = ( V_335 - sizeof( struct V_327 ) ) /
sizeof( struct V_330 ) ;
F_18 (evlist, evsel)
V_125 += V_13 -> V_336 ;
V_39 = V_125 > V_329 ? V_329 : V_125 ;
T_9 = sizeof( struct V_327 ) + V_39 * sizeof( struct V_330 ) ;
V_334 = F_26 ( T_9 ) ;
if ( ! V_334 )
return - V_296 ;
V_334 -> V_64 . V_5 . type = V_237 ;
V_334 -> V_64 . V_5 . V_42 = T_9 ;
V_334 -> V_64 . V_125 = V_39 ;
F_18 (evlist, evsel) {
T_12 V_337 ;
for ( V_337 = 0 ; V_337 < V_13 -> V_336 ; V_337 ++ ) {
struct V_330 * V_154 ;
struct V_205 * V_206 ;
if ( V_102 >= V_39 ) {
V_229 = V_333 ( V_22 , V_334 , NULL , V_37 ) ;
if ( V_229 )
goto V_272;
V_125 -= V_39 ;
V_102 = 0 ;
}
V_154 = & V_334 -> V_64 . V_126 [ V_102 ++ ] ;
V_154 -> V_91 = V_13 -> V_91 [ V_337 ] ;
V_206 = F_131 ( V_7 , V_154 -> V_91 ) ;
if ( ! V_206 ) {
free ( V_334 ) ;
return - V_332 ;
}
V_154 -> V_121 = V_206 -> V_121 ;
V_154 -> V_122 = V_206 -> V_122 ;
V_154 -> V_79 = V_206 -> V_79 ;
}
}
T_9 = sizeof( struct V_327 ) + V_125 * sizeof( struct V_330 ) ;
V_334 -> V_64 . V_5 . V_42 = T_9 ;
V_334 -> V_64 . V_125 = V_125 ;
V_229 = V_333 ( V_22 , V_334 , NULL , V_37 ) ;
V_272:
free ( V_334 ) ;
return V_229 ;
}
