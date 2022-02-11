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
if ( ! V_4 -> V_30 ) {
F_9 ( V_2 ) ;
F_19 ( V_2 ) ;
}
}
} else {
V_2 -> V_9 . V_11 . V_31 = & V_32 ;
}
if ( ! V_4 || F_32 ( V_4 ) ) {
if ( F_12 ( V_2 ) < 0 )
F_33 ( L_6 ) ;
}
if ( ( ! V_4 || ! V_4 -> V_30 ) && V_22 && V_22 -> V_33 &&
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
F_42 ( & V_2 -> V_5 . V_31 ) ;
F_43 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_4 )
F_36 ( V_2 -> V_4 ) ;
free ( V_2 ) ;
}
static int F_44 ( struct V_25 * V_22
V_34 ,
union V_35 * V_19
V_34 ,
struct V_1 * V_2
V_34 )
{
F_35 ( L_8 ) ;
return 0 ;
}
static int F_45 ( struct V_25 * V_22 V_34 ,
union V_35 * V_19 V_34 ,
struct V_36 * * T_2
V_34 )
{
F_35 ( L_8 ) ;
return 0 ;
}
static int F_46 ( struct V_25 * V_22 V_34 ,
union V_35 * V_19 V_34 ,
struct V_36 * * T_2
V_34 )
{
if ( V_37 )
F_47 ( V_19 , stdout ) ;
F_35 ( L_8 ) ;
return 0 ;
}
static int F_48 ( struct V_25 * V_22 V_34 ,
union V_35 * V_19 V_34 ,
struct V_20 * V_21 V_34 ,
struct V_12 * V_13 V_34 ,
struct V_38 * V_38 V_34 )
{
F_35 ( L_8 ) ;
return 0 ;
}
static int F_49 ( struct V_25 * V_22 V_34 ,
union V_35 * V_19 V_34 ,
struct V_20 * V_21 V_34 ,
struct V_38 * V_38 V_34 )
{
F_35 ( L_8 ) ;
return 0 ;
}
static int F_50 ( struct V_25 * V_22 V_34 ,
union V_35 * V_19 V_34 ,
struct V_16 * V_17 V_34 )
{
F_35 ( L_8 ) ;
return 0 ;
}
static int F_51 ( int V_39 , T_3 V_40 )
{
char V_41 [ 4096 ] ;
T_4 V_10 ;
while ( V_40 > 0 ) {
V_10 = F_52 ( V_39 , V_41 , F_53 ( V_40 , ( T_3 ) sizeof( V_41 ) ) ) ;
if ( V_10 <= 0 )
return V_10 ;
V_40 -= V_10 ;
}
return 0 ;
}
static T_5 F_54 ( struct V_25 * V_22 V_34 ,
union V_35 * V_19 ,
struct V_1 * V_2
V_34 )
{
F_35 ( L_8 ) ;
if ( F_4 ( V_2 -> V_4 ) )
F_51 ( F_55 ( V_2 -> V_4 ) , V_19 -> V_42 . V_43 ) ;
return V_19 -> V_42 . V_43 ;
}
static int F_56 ( struct V_25 * V_22 V_34 ,
union V_35 * V_19 V_34 ,
struct V_1 * V_2 V_34 )
{
F_35 ( L_8 ) ;
return 0 ;
}
static
int F_57 ( struct V_25 * V_22 V_34 ,
union V_35 * V_19 V_34 ,
struct V_1 * V_2 V_34 )
{
if ( V_37 )
F_58 ( V_19 , stdout ) ;
F_35 ( L_8 ) ;
return 0 ;
}
static
int F_59 ( struct V_25 * V_22 V_34 ,
union V_35 * V_19 V_34 ,
struct V_1 * V_2 V_34 )
{
if ( V_37 )
F_60 ( V_19 , stdout ) ;
F_35 ( L_8 ) ;
return 0 ;
}
static
int F_61 ( struct V_25 * V_22 V_34 ,
union V_35 * V_19 V_34 ,
struct V_1 * V_2 V_34 )
{
if ( V_37 )
F_62 ( V_19 , stdout ) ;
F_35 ( L_8 ) ;
return 0 ;
}
static int F_63 ( struct V_25 * V_22 V_34 ,
union V_35 * V_19 V_34 ,
struct V_1 * V_1
V_34 )
{
if ( V_37 )
F_64 ( V_19 , stdout ) ;
F_35 ( L_8 ) ;
return 0 ;
}
static int F_65 ( struct V_25 * V_22 V_34 ,
union V_35 * V_19 V_34 ,
struct V_1 * V_1
V_34 )
{
if ( V_37 )
F_66 ( V_19 , stdout ) ;
F_35 ( L_8 ) ;
return 0 ;
}
void F_67 ( struct V_25 * V_22 )
{
if ( V_22 -> V_21 == NULL )
V_22 -> V_21 = F_48 ;
if ( V_22 -> V_44 == NULL )
V_22 -> V_44 = F_49 ;
if ( V_22 -> V_45 == NULL )
V_22 -> V_45 = F_49 ;
if ( V_22 -> V_46 == NULL )
V_22 -> V_46 = F_49 ;
if ( V_22 -> V_47 == NULL )
V_22 -> V_47 = F_49 ;
if ( V_22 -> exit == NULL )
V_22 -> exit = F_49 ;
if ( V_22 -> V_48 == NULL )
V_22 -> V_48 = V_49 ;
if ( V_22 -> V_50 == NULL )
V_22 -> V_50 = V_51 ;
if ( V_22 -> V_52 == NULL )
V_22 -> V_52 = V_53 ;
if ( V_22 -> V_54 == NULL )
V_22 -> V_54 = V_55 ;
if ( V_22 -> V_56 == NULL )
V_22 -> V_56 = V_57 ;
if ( V_22 -> F_52 == NULL )
V_22 -> F_52 = F_48 ;
if ( V_22 -> V_58 == NULL )
V_22 -> V_58 = F_49 ;
if ( V_22 -> V_59 == NULL )
V_22 -> V_59 = F_49 ;
if ( V_22 -> V_14 == NULL )
V_22 -> V_14 = F_45 ;
if ( V_22 -> V_60 == NULL )
V_22 -> V_60 = F_46 ;
if ( V_22 -> V_61 == NULL )
V_22 -> V_61 = F_44 ;
if ( V_22 -> V_62 == NULL )
V_22 -> V_62 = F_56 ;
if ( V_22 -> V_63 == NULL ) {
if ( V_22 -> V_16 )
V_22 -> V_63 = V_64 ;
else
V_22 -> V_63 = F_50 ;
}
if ( V_22 -> V_65 == NULL )
V_22 -> V_65 = F_56 ;
if ( V_22 -> V_66 == NULL )
V_22 -> V_66 = F_56 ;
if ( V_22 -> V_42 == NULL )
V_22 -> V_42 = F_54 ;
if ( V_22 -> V_67 == NULL )
V_22 -> V_67 = F_56 ;
if ( V_22 -> V_68 == NULL )
V_22 -> V_68 = F_57 ;
if ( V_22 -> V_69 == NULL )
V_22 -> V_69 = F_59 ;
if ( V_22 -> V_70 == NULL )
V_22 -> V_70 = F_61 ;
if ( V_22 -> V_71 == NULL )
V_22 -> V_71 = F_63 ;
if ( V_22 -> V_72 == NULL )
V_22 -> V_72 = F_65 ;
if ( V_22 -> V_73 == NULL )
V_22 -> V_73 = F_56 ;
}
static void F_68 ( union V_35 * V_19 , void * V_74 )
{
void * V_75 = ( void * ) V_19 + V_19 -> V_5 . V_43 ;
int V_43 = V_75 - V_74 ;
F_69 ( V_43 % sizeof( V_76 ) ) ;
F_70 ( V_74 , V_43 ) ;
}
static void F_71 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
struct V_77 * V_78 = & V_19 -> V_5 ;
F_70 ( V_78 + 1 , V_19 -> V_5 . V_43 - sizeof( * V_78 ) ) ;
}
static void F_72 ( union V_35 * V_19 , bool T_6 )
{
V_19 -> V_46 . V_79 = F_73 ( V_19 -> V_46 . V_79 ) ;
V_19 -> V_46 . V_80 = F_73 ( V_19 -> V_46 . V_80 ) ;
if ( T_6 ) {
void * V_74 = & V_19 -> V_46 . V_46 ;
V_74 += F_74 ( strlen ( V_74 ) + 1 , sizeof( V_76 ) ) ;
F_68 ( V_19 , V_74 ) ;
}
}
static void F_75 ( union V_35 * V_19 ,
bool T_6 )
{
V_19 -> V_44 . V_79 = F_73 ( V_19 -> V_44 . V_79 ) ;
V_19 -> V_44 . V_80 = F_73 ( V_19 -> V_44 . V_80 ) ;
V_19 -> V_44 . V_81 = F_76 ( V_19 -> V_44 . V_81 ) ;
V_19 -> V_44 . V_82 = F_76 ( V_19 -> V_44 . V_82 ) ;
V_19 -> V_44 . V_83 = F_76 ( V_19 -> V_44 . V_83 ) ;
if ( T_6 ) {
void * V_74 = & V_19 -> V_44 . V_84 ;
V_74 += F_74 ( strlen ( V_74 ) + 1 , sizeof( V_76 ) ) ;
F_68 ( V_19 , V_74 ) ;
}
}
static void F_77 ( union V_35 * V_19 ,
bool T_6 )
{
V_19 -> V_45 . V_79 = F_73 ( V_19 -> V_45 . V_79 ) ;
V_19 -> V_45 . V_80 = F_73 ( V_19 -> V_45 . V_80 ) ;
V_19 -> V_45 . V_81 = F_76 ( V_19 -> V_45 . V_81 ) ;
V_19 -> V_45 . V_82 = F_76 ( V_19 -> V_45 . V_82 ) ;
V_19 -> V_45 . V_83 = F_76 ( V_19 -> V_45 . V_83 ) ;
V_19 -> V_45 . V_85 = F_73 ( V_19 -> V_45 . V_85 ) ;
V_19 -> V_45 . F_53 = F_73 ( V_19 -> V_45 . F_53 ) ;
V_19 -> V_45 . V_86 = F_76 ( V_19 -> V_45 . V_86 ) ;
if ( T_6 ) {
void * V_74 = & V_19 -> V_45 . V_84 ;
V_74 += F_74 ( strlen ( V_74 ) + 1 , sizeof( V_76 ) ) ;
F_68 ( V_19 , V_74 ) ;
}
}
static void F_78 ( union V_35 * V_19 , bool T_6 )
{
V_19 -> V_47 . V_79 = F_73 ( V_19 -> V_47 . V_79 ) ;
V_19 -> V_47 . V_80 = F_73 ( V_19 -> V_47 . V_80 ) ;
V_19 -> V_47 . V_87 = F_73 ( V_19 -> V_47 . V_87 ) ;
V_19 -> V_47 . V_88 = F_73 ( V_19 -> V_47 . V_88 ) ;
V_19 -> V_47 . time = F_76 ( V_19 -> V_47 . time ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_47 + 1 ) ;
}
static void F_79 ( union V_35 * V_19 , bool T_6 )
{
V_19 -> F_52 . V_79 = F_73 ( V_19 -> F_52 . V_79 ) ;
V_19 -> F_52 . V_80 = F_73 ( V_19 -> F_52 . V_80 ) ;
V_19 -> F_52 . V_89 = F_76 ( V_19 -> F_52 . V_89 ) ;
V_19 -> F_52 . V_90 = F_76 ( V_19 -> F_52 . V_90 ) ;
V_19 -> F_52 . V_91 = F_76 ( V_19 -> F_52 . V_91 ) ;
V_19 -> F_52 . V_92 = F_76 ( V_19 -> F_52 . V_92 ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> F_52 + 1 ) ;
}
static void F_80 ( union V_35 * V_19 , bool T_6 )
{
V_19 -> V_52 . V_93 = F_76 ( V_19 -> V_52 . V_93 ) ;
V_19 -> V_52 . V_94 = F_76 ( V_19 -> V_52 . V_94 ) ;
V_19 -> V_52 . V_95 = F_76 ( V_19 -> V_52 . V_95 ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_52 + 1 ) ;
}
static void F_81 ( union V_35 * V_19 ,
bool T_6 )
{
V_19 -> V_54 . V_79 = F_73 ( V_19 -> V_54 . V_79 ) ;
V_19 -> V_54 . V_80 = F_73 ( V_19 -> V_54 . V_80 ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_54 + 1 ) ;
}
static void F_82 ( union V_35 * V_19 , bool T_6 )
{
if ( V_19 -> V_5 . type == V_96 ) {
V_19 -> V_56 . V_97 =
F_73 ( V_19 -> V_56 . V_97 ) ;
V_19 -> V_56 . V_98 =
F_73 ( V_19 -> V_56 . V_98 ) ;
}
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_56 + 1 ) ;
}
static void F_83 ( union V_35 * V_19 ,
bool T_6 )
{
V_19 -> V_58 . time = F_76 ( V_19 -> V_58 . time ) ;
V_19 -> V_58 . V_92 = F_76 ( V_19 -> V_58 . V_92 ) ;
V_19 -> V_58 . V_99 = F_76 ( V_19 -> V_58 . V_99 ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_58 + 1 ) ;
}
static T_7 F_84 ( T_7 V_100 )
{
int V_101 = ( V_100 >> 4 ) | ( ( V_100 & 0xf ) << 4 ) ;
V_101 = ( ( V_101 & 0xcc ) >> 2 ) | ( ( V_101 & 0x33 ) << 2 ) ;
V_101 = ( ( V_101 & 0xaa ) >> 1 ) | ( ( V_101 & 0x55 ) << 1 ) ;
return ( T_7 ) V_101 ;
}
static void F_85 ( T_7 * V_102 , unsigned V_82 )
{
unsigned V_103 ;
for ( V_103 = 0 ; V_103 < V_82 ; V_103 ++ ) {
* V_102 = F_84 ( * V_102 ) ;
V_102 ++ ;
}
}
void F_86 ( struct V_104 * V_14 )
{
V_14 -> type = F_73 ( V_14 -> type ) ;
V_14 -> V_43 = F_73 ( V_14 -> V_43 ) ;
#define F_87 ( T_8 , V_40 ) \
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
F_91 ( V_105 ) ;
F_91 ( V_106 ) ;
F_91 ( V_107 ) ;
F_91 ( V_108 ) ;
F_90 ( V_109 ) ;
F_90 ( V_110 ) ;
F_91 ( V_111 ) ;
F_91 ( V_112 ) ;
F_91 ( V_113 ) ;
F_91 ( V_114 ) ;
F_90 ( V_115 ) ;
F_90 ( V_116 ) ;
F_89 ( V_117 ) ;
if ( F_87 ( V_108 , 1 ) )
F_85 ( ( T_7 * ) ( & V_14 -> V_108 + 1 ) ,
sizeof( V_76 ) ) ;
#undef F_91
#undef F_90
#undef F_88
#undef F_87
}
static void F_92 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
T_10 V_43 ;
F_86 ( & V_19 -> V_14 . V_14 ) ;
V_43 = V_19 -> V_5 . V_43 ;
V_43 -= ( void * ) & V_19 -> V_14 . V_92 - ( void * ) V_19 ;
F_70 ( V_19 -> V_14 . V_92 , V_43 ) ;
}
static void F_93 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
V_19 -> V_60 . type = F_76 ( V_19 -> V_60 . type ) ;
V_19 -> V_60 . V_92 = F_76 ( V_19 -> V_60 . V_92 ) ;
}
static void F_94 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
V_19 -> V_118 . V_118 . V_119 =
F_76 ( V_19 -> V_118 . V_118 . V_119 ) ;
}
static void F_95 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
V_19 -> V_61 . V_43 = F_73 ( V_19 -> V_61 . V_43 ) ;
}
static void F_96 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
T_10 V_43 ;
V_19 -> V_66 . type = F_73 ( V_19 -> V_66 . type ) ;
V_43 = V_19 -> V_5 . V_43 ;
V_43 -= ( void * ) & V_19 -> V_66 . V_120 - ( void * ) V_19 ;
F_70 ( V_19 -> V_66 . V_120 , V_43 ) ;
}
static void F_97 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
V_19 -> V_42 . V_43 = F_76 ( V_19 -> V_42 . V_43 ) ;
V_19 -> V_42 . V_121 = F_76 ( V_19 -> V_42 . V_121 ) ;
V_19 -> V_42 . V_122 = F_76 ( V_19 -> V_42 . V_122 ) ;
V_19 -> V_42 . V_123 = F_73 ( V_19 -> V_42 . V_123 ) ;
V_19 -> V_42 . V_80 = F_73 ( V_19 -> V_42 . V_80 ) ;
V_19 -> V_42 . V_124 = F_73 ( V_19 -> V_42 . V_124 ) ;
}
static void F_98 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
V_19 -> V_67 . type = F_73 ( V_19 -> V_67 . type ) ;
V_19 -> V_67 . V_125 = F_73 ( V_19 -> V_67 . V_125 ) ;
V_19 -> V_67 . V_124 = F_73 ( V_19 -> V_67 . V_124 ) ;
V_19 -> V_67 . V_79 = F_73 ( V_19 -> V_67 . V_79 ) ;
V_19 -> V_67 . V_80 = F_73 ( V_19 -> V_67 . V_80 ) ;
V_19 -> V_67 . V_126 = F_76 ( V_19 -> V_67 . V_126 ) ;
}
static void F_99 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
unsigned V_103 ;
V_19 -> V_68 . V_127 = F_76 ( V_19 -> V_68 . V_127 ) ;
for ( V_103 = 0 ; V_103 < V_19 -> V_68 . V_127 ; V_103 ++ )
V_19 -> V_68 . V_128 [ V_103 ] . V_79 = F_76 ( V_19 -> V_68 . V_128 [ V_103 ] . V_79 ) ;
}
static void F_100 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
struct V_129 * V_74 = & V_19 -> V_69 . V_74 ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
unsigned V_103 ;
V_74 -> type = F_76 ( V_74 -> type ) ;
switch ( V_74 -> type ) {
case V_134 :
V_131 = (struct V_130 * ) V_74 -> V_74 ;
V_131 -> V_127 = F_101 ( V_131 -> V_127 ) ;
for ( V_103 = 0 ; V_103 < V_131 -> V_127 ; V_103 ++ )
V_131 -> V_124 [ V_103 ] = F_101 ( V_131 -> V_124 [ V_103 ] ) ;
break;
case V_135 :
V_133 = (struct V_132 * ) V_74 -> V_74 ;
V_133 -> V_127 = F_101 ( V_133 -> V_127 ) ;
V_133 -> V_136 = F_101 ( V_133 -> V_136 ) ;
switch ( V_133 -> V_136 ) {
case 4 : F_102 ( & V_133 -> V_133 , V_133 -> V_127 ) ; break;
case 8 : F_70 ( & V_133 -> V_133 , V_133 -> V_127 ) ; break;
default:
F_3 ( L_9 ) ;
}
default:
break;
}
}
static void F_103 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
V_76 V_43 ;
V_43 = V_19 -> V_70 . V_127 * sizeof( V_19 -> V_70 . V_74 [ 0 ] ) ;
V_43 += 1 ;
F_70 ( & V_19 -> V_70 . V_127 , V_43 ) ;
}
static void F_104 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
V_19 -> V_71 . V_92 = F_76 ( V_19 -> V_71 . V_92 ) ;
V_19 -> V_71 . V_137 = F_73 ( V_19 -> V_71 . V_137 ) ;
V_19 -> V_71 . V_124 = F_73 ( V_19 -> V_71 . V_124 ) ;
V_19 -> V_71 . V_138 = F_76 ( V_19 -> V_71 . V_138 ) ;
V_19 -> V_71 . V_139 = F_76 ( V_19 -> V_71 . V_139 ) ;
V_19 -> V_71 . V_140 = F_76 ( V_19 -> V_71 . V_140 ) ;
}
static void F_105 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
V_19 -> V_72 . type = F_76 ( V_19 -> V_72 . type ) ;
V_19 -> V_72 . time = F_76 ( V_19 -> V_72 . time ) ;
}
static int V_64 ( struct V_25 * V_22 V_34 ,
union V_35 * V_19 V_34 ,
struct V_16 * V_17 )
{
if ( V_37 )
fprintf ( stdout , L_10 ) ;
return F_106 ( V_17 , V_141 ) ;
}
int F_107 ( struct V_1 * V_142 , union V_35 * V_19 ,
struct V_20 * V_21 , V_76 V_23 )
{
return F_108 ( & V_142 -> V_16 , V_19 , V_21 , V_23 ) ;
}
static void F_109 ( struct V_20 * V_21 )
{
struct V_143 * V_144 = V_21 -> V_144 ;
struct V_145 * V_146 = V_21 -> V_145 ;
V_76 V_147 = V_144 -> V_127 ;
unsigned int V_103 ;
for ( V_103 = 0 ; V_103 < V_147 ; V_103 ++ ) {
if ( V_144 -> V_148 [ V_103 ] == V_149 )
break;
}
if ( ( V_103 != V_147 ) && V_146 -> V_127 ) {
V_76 V_150 ;
V_150 = V_103 + 1 + V_146 -> V_127 + 1 ;
V_147 = V_103 + 1 ;
printf ( L_11 V_151 L_10 , V_150 ) ;
for ( V_103 = 0 ; V_103 < V_147 ; V_103 ++ )
printf ( L_12 V_152 L_10 ,
V_103 , V_144 -> V_148 [ V_103 ] ) ;
printf ( L_12 V_152 L_10 ,
( int ) ( V_147 ) , V_146 -> V_128 [ 0 ] . V_153 ) ;
for ( V_103 = 0 ; V_103 < V_146 -> V_127 ; V_103 ++ )
printf ( L_12 V_152 L_10 ,
( int ) ( V_103 + V_147 + 1 ) , V_146 -> V_128 [ V_103 ] . V_154 ) ;
}
}
static void F_110 ( struct V_12 * V_13 ,
struct V_20 * V_21 )
{
unsigned int V_103 ;
struct V_143 * V_144 = V_21 -> V_144 ;
if ( F_111 ( V_13 ) )
F_109 ( V_21 ) ;
printf ( L_13 V_151 L_10 , V_144 -> V_127 ) ;
for ( V_103 = 0 ; V_103 < V_144 -> V_127 ; V_103 ++ )
printf ( L_12 V_152 L_10 ,
V_103 , V_144 -> V_148 [ V_103 ] ) ;
}
static void F_112 ( struct V_20 * V_21 )
{
T_11 V_103 ;
printf ( L_14 V_151 L_10 , V_21 -> V_145 -> V_127 ) ;
for ( V_103 = 0 ; V_103 < V_21 -> V_145 -> V_127 ; V_103 ++ ) {
struct V_155 * V_156 = & V_21 -> V_145 -> V_128 [ V_103 ] ;
printf ( L_15 V_151 L_16 V_152 L_17 V_152 L_18 ,
V_103 , V_156 -> V_154 , V_156 -> V_153 ,
( unsigned short ) V_156 -> V_95 . V_157 ,
V_156 -> V_95 . V_158 ? L_19 : L_20 ,
V_156 -> V_95 . V_159 ? L_21 : L_20 ,
V_156 -> V_95 . abort ? L_22 : L_20 ,
V_156 -> V_95 . V_160 ? L_23 : L_20 ,
( unsigned ) V_156 -> V_95 . V_161 ) ;
}
}
static void F_113 ( V_76 V_133 , V_76 * V_162 )
{
unsigned V_163 , V_103 = 0 ;
F_114 (rid, (unsigned long *) &mask, sizeof(mask) * 8 ) {
V_76 V_138 = V_162 [ V_103 ++ ] ;
printf ( L_24 V_152 L_10 ,
F_115 ( V_163 ) , V_138 ) ;
}
}
static inline const char * F_116 ( struct V_164 * V_165 )
{
if ( V_165 -> V_166 > V_167 )
return L_25 ;
return V_168 [ V_165 -> V_166 ] ;
}
static void F_117 ( const char * type , struct V_164 * V_162 )
{
V_76 V_133 = V_162 -> V_133 ;
printf ( L_26 V_152 L_27 ,
type ,
V_133 ,
F_116 ( V_162 ) ) ;
F_113 ( V_133 , V_162 -> V_162 ) ;
}
static void F_118 ( struct V_20 * V_21 )
{
struct V_164 * V_169 = & V_21 -> V_169 ;
if ( V_169 -> V_162 )
F_117 ( L_28 , V_169 ) ;
}
static void F_119 ( struct V_20 * V_21 )
{
struct V_164 * V_170 = & V_21 -> V_170 ;
if ( V_170 -> V_162 )
F_117 ( L_29 , V_170 ) ;
}
static void F_120 ( struct V_171 * V_172 )
{
printf ( L_30 V_151 L_31 ,
V_172 -> V_43 , V_172 -> V_121 ) ;
}
static void F_121 ( struct V_36 * V_7 ,
union V_35 * V_19 ,
struct V_20 * V_21 )
{
V_76 V_107 = F_122 ( V_7 ) ;
if ( V_19 -> V_5 . type != V_173 &&
! F_34 ( V_7 ) ) {
fputs ( L_32 , stdout ) ;
return;
}
if ( ( V_107 & V_174 ) )
printf ( L_33 , V_21 -> V_124 ) ;
if ( V_107 & V_175 )
printf ( L_34 V_151 L_20 , V_21 -> time ) ;
}
static void F_123 ( struct V_20 * V_21 , V_76 V_108 )
{
printf ( L_35 ) ;
if ( V_108 & V_176 )
printf ( L_36 V_152 L_10 ,
V_21 -> F_52 . V_90 ) ;
if ( V_108 & V_177 )
printf ( L_37 V_152 L_10 ,
V_21 -> F_52 . V_91 ) ;
if ( V_108 & V_178 ) {
V_76 V_103 ;
printf ( L_38 V_151 L_10 , V_21 -> F_52 . V_179 . V_127 ) ;
for ( V_103 = 0 ; V_103 < V_21 -> F_52 . V_179 . V_127 ; V_103 ++ ) {
struct V_180 * V_89 ;
V_89 = & V_21 -> F_52 . V_179 . V_181 [ V_103 ] ;
printf ( L_39 V_152
L_40 V_152 L_10 ,
V_89 -> V_92 , V_89 -> V_89 ) ;
}
} else
printf ( L_39 V_152 L_40 V_152 L_10 ,
V_21 -> F_52 . V_182 . V_92 , V_21 -> F_52 . V_182 . V_89 ) ;
}
static void F_124 ( struct V_36 * V_7 , union V_35 * V_19 ,
V_76 V_23 , struct V_20 * V_21 )
{
if ( ! V_37 )
return;
printf ( L_41 V_152 L_42 ,
V_23 , V_19 -> V_5 . V_43 , V_19 -> V_5 . type ) ;
F_125 ( V_19 ) ;
if ( V_21 )
F_121 ( V_7 , V_19 , V_21 ) ;
printf ( L_43 V_152 L_44 , V_23 ,
V_19 -> V_5 . V_43 , F_126 ( V_19 -> V_5 . type ) ) ;
}
static void F_127 ( struct V_12 * V_13 , union V_35 * V_19 ,
struct V_20 * V_21 )
{
V_76 V_107 ;
if ( ! V_37 )
return;
printf ( L_45 V_152 L_46 V_151 L_47 V_152 L_10 ,
V_19 -> V_5 . V_183 , V_21 -> V_79 , V_21 -> V_80 , V_21 -> V_126 ,
V_21 -> V_184 , V_21 -> V_185 ) ;
V_107 = V_13 -> V_14 . V_107 ;
if ( V_107 & V_186 )
F_110 ( V_13 , V_21 ) ;
if ( ( V_107 & V_187 ) && ! F_111 ( V_13 ) )
F_112 ( V_21 ) ;
if ( V_107 & V_188 )
F_118 ( V_21 ) ;
if ( V_107 & V_189 )
F_119 ( V_21 ) ;
if ( V_107 & V_190 )
F_120 ( & V_21 -> V_191 ) ;
if ( V_107 & V_192 )
printf ( L_48 V_151 L_10 , V_21 -> V_193 ) ;
if ( V_107 & V_194 )
printf ( L_49 V_152 L_10 , V_21 -> V_195 ) ;
if ( V_107 & V_196 )
printf ( L_50 V_152 L_10 , V_21 -> V_197 ) ;
if ( V_107 & V_198 )
F_123 ( V_21 , V_13 -> V_14 . V_108 ) ;
}
static struct V_38 * F_128 ( struct V_9 * V_9 ,
union V_35 * V_19 ,
struct V_20 * V_21 )
{
struct V_38 * V_38 ;
if ( V_199 &&
( ( V_21 -> V_200 == V_201 ) ||
( V_21 -> V_200 == V_202 ) ) ) {
T_12 V_79 ;
if ( V_19 -> V_5 . type == V_203
|| V_19 -> V_5 . type == V_204 )
V_79 = V_19 -> V_44 . V_79 ;
else
V_79 = V_21 -> V_79 ;
V_38 = F_129 ( V_9 , V_79 ) ;
if ( ! V_38 )
V_38 = F_130 ( V_9 , V_205 ) ;
return V_38 ;
}
return & V_9 -> V_11 ;
}
static int F_131 ( struct V_36 * V_7 ,
struct V_25 * V_22 ,
union V_35 * V_19 ,
struct V_20 * V_21 ,
struct V_180 * V_206 ,
struct V_38 * V_38 )
{
struct V_207 * V_208 = F_132 ( V_7 , V_206 -> V_92 ) ;
if ( V_208 ) {
V_21 -> V_92 = V_206 -> V_92 ;
V_21 -> V_184 = V_206 -> V_89 - V_208 -> V_184 ;
V_208 -> V_184 = V_206 -> V_89 ;
}
if ( ! V_208 || V_208 -> V_13 == NULL ) {
++ V_7 -> V_209 . V_210 ;
return 0 ;
}
return V_22 -> V_21 ( V_22 , V_19 , V_21 , V_208 -> V_13 , V_38 ) ;
}
static int F_133 ( struct V_36 * V_7 ,
struct V_25 * V_22 ,
union V_35 * V_19 ,
struct V_20 * V_21 ,
struct V_38 * V_38 )
{
int V_10 = - V_211 ;
V_76 V_103 ;
for ( V_103 = 0 ; V_103 < V_21 -> F_52 . V_179 . V_127 ; V_103 ++ ) {
V_10 = F_131 ( V_7 , V_22 , V_19 , V_21 ,
& V_21 -> F_52 . V_179 . V_181 [ V_103 ] ,
V_38 ) ;
if ( V_10 )
break;
}
return V_10 ;
}
static int
F_134 ( struct V_36 * V_7 ,
struct V_25 * V_22 ,
union V_35 * V_19 ,
struct V_20 * V_21 ,
struct V_12 * V_13 ,
struct V_38 * V_38 )
{
V_76 V_107 = V_13 -> V_14 . V_107 ;
V_76 V_108 = V_13 -> V_14 . V_108 ;
if ( ! ( V_107 & V_198 ) )
return V_22 -> V_21 ( V_22 , V_19 , V_21 , V_13 , V_38 ) ;
if ( V_108 & V_178 )
return F_133 ( V_7 , V_22 , V_19 , V_21 ,
V_38 ) ;
else
return F_131 ( V_7 , V_22 , V_19 , V_21 ,
& V_21 -> F_52 . V_182 , V_38 ) ;
}
static int F_135 ( struct V_9 * V_9 ,
struct V_36 * V_7 ,
union V_35 * V_19 ,
struct V_20 * V_21 ,
struct V_25 * V_22 , V_76 V_23 )
{
struct V_12 * V_13 ;
struct V_38 * V_38 ;
F_124 ( V_7 , V_19 , V_23 , V_21 ) ;
V_13 = F_136 ( V_7 , V_21 -> V_92 ) ;
V_38 = F_128 ( V_9 , V_19 , V_21 ) ;
switch ( V_19 -> V_5 . type ) {
case V_173 :
if ( V_13 == NULL ) {
++ V_7 -> V_209 . V_210 ;
return 0 ;
}
F_127 ( V_13 , V_19 , V_21 ) ;
if ( V_38 == NULL ) {
++ V_7 -> V_209 . V_212 ;
return 0 ;
}
return F_134 ( V_7 , V_22 , V_19 , V_21 , V_13 , V_38 ) ;
case V_203 :
return V_22 -> V_44 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_204 :
if ( V_19 -> V_5 . V_183 & V_213 )
++ V_7 -> V_209 . V_214 ;
return V_22 -> V_45 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_215 :
return V_22 -> V_46 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_216 :
return V_22 -> V_217 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_218 :
return V_22 -> V_47 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_219 :
return V_22 -> exit ( V_22 , V_19 , V_21 , V_38 ) ;
case V_220 :
if ( V_22 -> V_48 == V_49 )
V_7 -> V_209 . V_221 += V_19 -> V_48 . V_48 ;
return V_22 -> V_48 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_222 :
if ( V_22 -> V_50 == V_51 )
V_7 -> V_209 . V_223 += V_19 -> V_50 . V_48 ;
return V_22 -> V_50 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_224 :
return V_22 -> F_52 ( V_22 , V_19 , V_21 , V_13 , V_38 ) ;
case V_225 :
return V_22 -> V_58 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_226 :
return V_22 -> V_59 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_227 :
if ( V_22 -> V_52 == V_53 ) {
if ( V_19 -> V_52 . V_95 & V_228 )
V_7 -> V_209 . V_229 += 1 ;
if ( V_19 -> V_52 . V_95 & V_230 )
V_7 -> V_209 . V_231 += 1 ;
}
return V_22 -> V_52 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_232 :
return V_22 -> V_54 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_233 :
case V_96 :
return V_22 -> V_56 ( V_22 , V_19 , V_21 , V_38 ) ;
default:
++ V_7 -> V_209 . V_234 ;
return - 1 ;
}
}
static int F_24 ( struct V_1 * V_2 ,
union V_35 * V_19 ,
struct V_20 * V_21 ,
struct V_25 * V_22 ,
V_76 V_23 )
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
union V_35 * V_19 ,
V_76 V_23 )
{
struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_25 * V_22 = V_2 -> V_22 ;
int V_39 = F_55 ( V_2 -> V_4 ) ;
int V_235 ;
F_124 ( V_2 -> V_7 , V_19 , V_23 , NULL ) ;
switch ( V_19 -> V_5 . type ) {
case V_236 :
V_235 = V_22 -> V_14 ( V_22 , V_19 , & V_2 -> V_7 ) ;
if ( V_235 == 0 ) {
F_9 ( V_2 ) ;
F_19 ( V_2 ) ;
}
return V_235 ;
case V_237 :
return V_22 -> V_60 ( V_22 , V_19 , & V_2 -> V_7 ) ;
case V_238 :
return 0 ;
case V_239 :
F_139 ( V_39 , V_23 , V_240 ) ;
return V_22 -> V_61 ( V_22 , V_19 , V_2 ) ;
case V_241 :
return V_22 -> V_62 ( V_22 , V_19 , V_2 ) ;
case V_242 :
return V_22 -> V_63 ( V_22 , V_19 , V_17 ) ;
case V_243 :
return V_22 -> V_65 ( V_22 , V_19 , V_2 ) ;
case V_244 :
return V_22 -> V_66 ( V_22 , V_19 , V_2 ) ;
case V_245 :
F_139 ( V_39 , V_23 + V_19 -> V_5 . V_43 , V_240 ) ;
return V_22 -> V_42 ( V_22 , V_19 , V_2 ) ;
case V_246 :
F_140 ( V_2 , V_19 ) ;
return V_22 -> V_67 ( V_22 , V_19 , V_2 ) ;
case V_247 :
return V_22 -> V_68 ( V_22 , V_19 , V_2 ) ;
case V_248 :
return V_22 -> V_69 ( V_22 , V_19 , V_2 ) ;
case V_249 :
return V_22 -> V_70 ( V_22 , V_19 , V_2 ) ;
case V_250 :
return V_22 -> V_71 ( V_22 , V_19 , V_2 ) ;
case V_251 :
return V_22 -> V_72 ( V_22 , V_19 , V_2 ) ;
case V_252 :
V_2 -> V_73 = V_19 -> V_73 ;
return V_22 -> V_73 ( V_22 , V_19 , V_2 ) ;
default:
return - V_211 ;
}
}
int F_141 ( struct V_1 * V_2 ,
union V_35 * V_19 ,
struct V_20 * V_21 )
{
struct V_36 * V_7 = V_2 -> V_7 ;
struct V_25 * V_22 = V_2 -> V_22 ;
F_142 ( & V_7 -> V_209 , V_19 -> V_5 . type ) ;
if ( V_19 -> V_5 . type >= V_253 )
return F_138 ( V_2 , V_19 , 0 ) ;
return F_135 ( & V_2 -> V_9 , V_7 , V_19 , V_21 , V_22 , 0 ) ;
}
static void F_143 ( union V_35 * V_19 , bool T_6 )
{
T_13 V_254 ;
V_254 = V_255 [ V_19 -> V_5 . type ] ;
if ( V_254 )
V_254 ( V_19 , T_6 ) ;
}
int F_144 ( struct V_1 * V_2 , T_3 V_23 ,
void * V_41 , T_10 V_256 ,
union V_35 * * V_257 ,
struct V_20 * V_21 )
{
union V_35 * V_19 ;
T_10 V_258 , V_259 ;
int V_39 ;
if ( V_2 -> V_260 && ! V_2 -> V_5 . V_261 ) {
V_19 = V_23 - V_2 -> V_262 +
V_2 -> V_263 ;
goto V_264;
}
if ( F_4 ( V_2 -> V_4 ) )
return - 1 ;
V_39 = F_55 ( V_2 -> V_4 ) ;
V_258 = sizeof( struct V_77 ) ;
if ( V_256 < V_258 )
return - 1 ;
if ( F_139 ( V_39 , V_23 , V_240 ) == ( T_3 ) - 1 ||
F_145 ( V_39 , V_41 , V_258 ) != ( T_4 ) V_258 )
return - 1 ;
V_19 = (union V_35 * ) V_41 ;
if ( V_2 -> V_5 . V_261 )
F_146 ( & V_19 -> V_5 ) ;
if ( V_19 -> V_5 . V_43 < V_258 || V_19 -> V_5 . V_43 > V_256 )
return - 1 ;
V_259 = V_19 -> V_5 . V_43 - V_258 ;
if ( F_145 ( V_39 , V_41 , V_259 ) != ( T_4 ) V_259 )
return - 1 ;
if ( V_2 -> V_5 . V_261 )
F_143 ( V_19 , F_34 ( V_2 -> V_7 ) ) ;
V_264:
if ( V_21 && V_19 -> V_5 . type < V_253 &&
F_23 ( V_2 -> V_7 , V_19 , V_21 ) )
return - 1 ;
* V_257 = V_19 ;
return 0 ;
}
static T_5 F_147 ( struct V_1 * V_2 ,
union V_35 * V_19 , V_76 V_23 )
{
struct V_36 * V_7 = V_2 -> V_7 ;
struct V_25 * V_22 = V_2 -> V_22 ;
struct V_20 V_21 ;
int V_10 ;
if ( V_2 -> V_5 . V_261 )
F_143 ( V_19 , F_34 ( V_7 ) ) ;
if ( V_19 -> V_5 . type >= V_265 )
return - V_211 ;
F_142 ( & V_7 -> V_209 , V_19 -> V_5 . type ) ;
if ( V_19 -> V_5 . type >= V_253 )
return F_138 ( V_2 , V_19 , V_23 ) ;
V_10 = F_23 ( V_7 , V_19 , & V_21 ) ;
if ( V_10 )
return V_10 ;
if ( V_22 -> V_16 ) {
V_10 = F_107 ( V_2 , V_19 , & V_21 , V_23 ) ;
if ( V_10 != - V_266 )
return V_10 ;
}
return F_24 ( V_2 , V_19 , & V_21 , V_22 ,
V_23 ) ;
}
void F_146 ( struct V_77 * V_78 )
{
V_78 -> type = F_73 ( V_78 -> type ) ;
V_78 -> V_183 = F_101 ( V_78 -> V_183 ) ;
V_78 -> V_43 = F_101 ( V_78 -> V_43 ) ;
}
struct V_137 * F_148 ( struct V_1 * V_2 , T_14 V_79 )
{
return F_149 ( & V_2 -> V_9 . V_11 , - 1 , V_79 ) ;
}
int F_150 ( struct V_1 * V_2 )
{
struct V_137 * V_137 ;
int V_235 = 0 ;
V_137 = F_149 ( & V_2 -> V_9 . V_11 , 0 , 0 ) ;
if ( V_137 == NULL || F_151 ( V_137 , L_51 , 0 ) ) {
F_3 ( L_52 ) ;
V_235 = - 1 ;
}
if ( V_137 == NULL || F_152 ( V_137 , 0 , NULL ) ) {
F_3 ( L_52 ) ;
V_235 = - 1 ;
}
F_153 ( V_137 ) ;
return V_235 ;
}
static void
F_154 ( const struct V_1 * V_2 )
{
const struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_12 * V_13 ;
bool V_267 = true ;
F_18 (session->evlist, evsel) {
if ( V_13 -> V_14 . V_268 )
V_267 = false ;
}
if ( ! V_267 )
return;
if ( V_17 -> V_269 != 0 )
F_155 ( L_53 , V_17 -> V_269 ) ;
}
static void F_156 ( const struct V_1 * V_2 )
{
const struct V_270 * V_209 = & V_2 -> V_7 -> V_209 ;
if ( V_2 -> V_22 -> V_48 == V_49 &&
V_209 -> V_271 [ V_220 ] != 0 ) {
F_155 ( L_54
L_55 ,
V_209 -> V_271 [ 0 ] ,
V_209 -> V_271 [ V_220 ] ) ;
}
if ( V_2 -> V_22 -> V_50 == V_51 ) {
double V_272 ;
V_272 = ( double ) V_209 -> V_223 /
( double ) ( V_209 -> V_271 [ V_173 ] + V_209 -> V_223 ) ;
if ( V_272 > 0.05 ) {
F_155 ( L_56 V_151 L_57 ,
V_209 -> V_271 [ V_173 ] + V_209 -> V_223 ,
V_272 * 100.0 ) ;
}
}
if ( V_2 -> V_22 -> V_52 == V_53 &&
V_209 -> V_229 != 0 ) {
F_155 ( L_58 V_151 L_59 ,
V_209 -> V_229 ,
V_209 -> V_271 [ V_227 ] ) ;
}
if ( V_2 -> V_22 -> V_52 == V_53 &&
V_209 -> V_231 != 0 ) {
bool V_273 = false ;
( void ) F_157 ( L_60 ,
& V_273 ) ;
F_155 ( L_61 V_151 L_59
L_62 ,
V_209 -> V_231 ,
V_209 -> V_271 [ V_227 ] ,
V_273 ?
L_63
L_64 :
L_65 ) ;
}
if ( V_209 -> V_234 != 0 ) {
F_155 ( L_66
L_67
L_68
L_69
L_70 ,
V_209 -> V_234 ) ;
}
if ( V_209 -> V_210 != 0 ) {
F_155 ( L_71 ,
V_209 -> V_210 ) ;
}
if ( V_209 -> V_274 != 0 ) {
F_155 ( L_72
L_73
L_74 ,
V_209 -> V_274 ,
V_209 -> V_271 [ V_173 ] ) ;
}
if ( V_209 -> V_212 != 0 ) {
F_155 ( L_75
L_76 ,
V_209 -> V_212 ) ;
}
F_154 ( V_2 ) ;
F_158 ( V_209 ) ;
if ( V_209 -> V_214 != 0 ) {
F_155 ( L_77
L_78
L_79
L_80
L_81
L_82
L_83 ,
V_209 -> V_214 ) ;
}
}
static int F_159 ( struct V_137 * V_137 ,
void * V_102 V_34 )
{
return F_160 ( V_137 ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
return F_162 ( & V_2 -> V_9 ,
F_159 ,
NULL ) ;
}
static int F_163 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_25 * V_22 = V_2 -> V_22 ;
int V_39 = F_55 ( V_2 -> V_4 ) ;
union V_35 * V_19 ;
T_15 V_43 , V_275 = 0 ;
void * V_41 = NULL ;
T_5 V_276 = 0 ;
V_76 V_277 ;
T_4 V_235 ;
void * V_102 ;
F_67 ( V_22 ) ;
V_277 = 0 ;
V_275 = sizeof( union V_35 ) ;
V_41 = malloc ( V_275 ) ;
if ( ! V_41 )
return - V_278 ;
F_164 ( V_17 , true ) ;
V_279:
V_19 = V_41 ;
V_235 = F_145 ( V_39 , V_19 , sizeof( struct V_77 ) ) ;
if ( V_235 <= 0 ) {
if ( V_235 == 0 )
goto V_280;
F_3 ( L_84 ) ;
goto V_281;
}
if ( V_2 -> V_5 . V_261 )
F_146 ( & V_19 -> V_5 ) ;
V_43 = V_19 -> V_5 . V_43 ;
if ( V_43 < sizeof( struct V_77 ) ) {
F_3 ( L_85 ) ;
goto V_281;
}
if ( V_43 > V_275 ) {
void * V_282 = realloc ( V_41 , V_43 ) ;
if ( ! V_282 ) {
F_3 ( L_86 ) ;
goto V_281;
}
V_41 = V_282 ;
V_275 = V_43 ;
V_19 = V_41 ;
}
V_102 = V_19 ;
V_102 += sizeof( struct V_77 ) ;
if ( V_43 - sizeof( struct V_77 ) ) {
V_235 = F_145 ( V_39 , V_102 , V_43 - sizeof( struct V_77 ) ) ;
if ( V_235 <= 0 ) {
if ( V_235 == 0 ) {
F_3 ( L_87 ) ;
goto V_280;
}
F_3 ( L_88 ) ;
goto V_281;
}
}
if ( ( V_276 = F_147 ( V_2 , V_19 , V_277 ) ) < 0 ) {
F_3 ( L_43 V_152 L_89 ,
V_277 , V_19 -> V_5 . V_43 , V_19 -> V_5 . type ) ;
V_235 = - V_211 ;
goto V_281;
}
V_277 += V_43 ;
if ( V_276 > 0 )
V_277 += V_276 ;
if ( ! F_165 () )
goto V_279;
V_280:
V_235 = F_106 ( V_17 , V_283 ) ;
if ( V_235 )
goto V_281;
V_235 = F_166 ( V_2 , V_22 ) ;
if ( V_235 )
goto V_281;
V_235 = F_161 ( V_2 ) ;
V_281:
free ( V_41 ) ;
F_156 ( V_2 ) ;
F_167 ( & V_2 -> V_16 ) ;
F_168 ( V_2 ) ;
return V_235 ;
}
static union V_35 *
F_169 ( struct V_1 * V_2 ,
V_76 V_277 , T_10 V_284 , char * V_41 )
{
union V_35 * V_19 ;
if ( V_277 + sizeof( V_19 -> V_5 ) > V_284 )
return NULL ;
V_19 = (union V_35 * ) ( V_41 + V_277 ) ;
if ( V_2 -> V_5 . V_261 )
F_146 ( & V_19 -> V_5 ) ;
if ( V_277 + V_19 -> V_5 . V_43 > V_284 ) {
if ( V_2 -> V_5 . V_261 )
F_146 ( & V_19 -> V_5 ) ;
return NULL ;
}
return V_19 ;
}
static int F_170 ( struct V_1 * V_2 ,
V_76 V_285 , V_76 V_286 ,
V_76 V_287 )
{
struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_25 * V_22 = V_2 -> V_22 ;
int V_39 = F_55 ( V_2 -> V_4 ) ;
V_76 V_277 , V_288 , V_23 , V_289 , V_43 ;
int V_235 , V_290 , V_291 , V_292 = 0 ;
T_10 V_284 ;
char * V_41 , * V_293 [ V_294 ] ;
union V_35 * V_19 ;
struct V_295 V_296 ;
T_5 V_276 ;
F_67 ( V_22 ) ;
V_288 = V_297 * ( V_285 / V_297 ) ;
V_23 = V_288 ;
V_277 = V_285 - V_288 ;
if ( V_286 == 0 )
goto V_26;
if ( V_285 + V_286 < V_287 )
V_287 = V_285 + V_286 ;
F_171 ( & V_296 , V_287 , L_90 ) ;
V_284 = V_298 ;
if ( V_284 > V_287 ) {
V_284 = V_287 ;
V_2 -> V_260 = true ;
}
memset ( V_293 , 0 , sizeof( V_293 ) ) ;
V_290 = V_299 ;
V_291 = V_300 ;
if ( V_2 -> V_5 . V_261 ) {
V_290 |= V_301 ;
V_291 = V_302 ;
}
V_303:
V_41 = V_44 ( NULL , V_284 , V_290 , V_291 , V_39 ,
V_23 ) ;
if ( V_41 == V_304 ) {
F_3 ( L_91 ) ;
V_235 = - V_278 ;
goto V_281;
}
V_293 [ V_292 ] = V_41 ;
V_292 = ( V_292 + 1 ) & ( F_172 ( V_293 ) - 1 ) ;
V_289 = V_23 + V_277 ;
if ( V_2 -> V_260 ) {
V_2 -> V_263 = V_41 ;
V_2 -> V_262 = V_23 ;
}
V_279:
V_19 = F_169 ( V_2 , V_277 , V_284 , V_41 ) ;
if ( ! V_19 ) {
if ( V_293 [ V_292 ] ) {
F_173 ( V_293 [ V_292 ] , V_284 ) ;
V_293 [ V_292 ] = NULL ;
}
V_288 = V_297 * ( V_277 / V_297 ) ;
V_23 += V_288 ;
V_277 -= V_288 ;
goto V_303;
}
V_43 = V_19 -> V_5 . V_43 ;
if ( V_43 < sizeof( struct V_77 ) ||
( V_276 = F_147 ( V_2 , V_19 , V_289 ) ) < 0 ) {
F_3 ( L_43 V_152 L_89 ,
V_23 + V_277 , V_19 -> V_5 . V_43 ,
V_19 -> V_5 . type ) ;
V_235 = - V_211 ;
goto V_281;
}
if ( V_276 )
V_43 += V_276 ;
V_277 += V_43 ;
V_289 += V_43 ;
F_174 ( & V_296 , V_43 ) ;
if ( F_165 () )
goto V_26;
if ( V_289 < V_287 )
goto V_279;
V_26:
V_235 = F_106 ( V_17 , V_283 ) ;
if ( V_235 )
goto V_281;
V_235 = F_166 ( V_2 , V_22 ) ;
if ( V_235 )
goto V_281;
V_235 = F_161 ( V_2 ) ;
V_281:
F_175 () ;
F_156 ( V_2 ) ;
F_176 ( & V_2 -> V_16 ) ;
F_168 ( V_2 ) ;
V_2 -> V_260 = false ;
return V_235 ;
}
int F_177 ( struct V_1 * V_2 )
{
V_76 V_43 = F_178 ( V_2 -> V_4 ) ;
int V_235 ;
if ( F_150 ( V_2 ) < 0 )
return - V_305 ;
if ( ! F_4 ( V_2 -> V_4 ) )
V_235 = F_170 ( V_2 ,
V_2 -> V_5 . V_285 ,
V_2 -> V_5 . V_286 , V_43 ) ;
else
V_235 = F_163 ( V_2 ) ;
return V_235 ;
}
bool F_179 ( struct V_1 * V_2 , const char * V_306 )
{
struct V_12 * V_13 ;
F_18 (session->evlist, evsel) {
if ( V_13 -> V_14 . type == V_307 )
return true ;
}
F_3 ( L_92 , V_306 ) ;
return false ;
}
int F_180 ( struct V_308 * * V_309 ,
const char * V_310 , V_76 V_185 )
{
char * V_311 ;
int V_103 ;
struct V_312 * V_313 ;
V_313 = F_26 ( sizeof( struct V_312 ) ) ;
if ( V_313 == NULL )
return - V_305 ;
V_313 -> V_314 = F_181 ( V_310 ) ;
if ( V_313 -> V_314 == NULL ) {
free ( V_313 ) ;
return - V_305 ;
}
V_311 = strchr ( V_313 -> V_314 , ']' ) ;
if ( V_311 )
* V_311 = '\0' ;
V_313 -> V_185 = V_185 ;
for ( V_103 = 0 ; V_103 < V_315 ; ++ V_103 ) {
struct V_316 * V_316 = F_182 ( V_309 [ V_103 ] ) ;
if ( ! V_316 )
continue;
V_316 -> V_312 = V_313 ;
}
return 0 ;
}
T_10 F_183 ( struct V_1 * V_2 , T_16 * V_317 )
{
return F_184 ( & V_2 -> V_9 , V_317 ) ;
}
T_10 F_185 ( struct V_1 * V_2 , T_16 * V_317 ,
bool (V_276)( struct V_318 * V_318 , int V_319 ) , int V_319 )
{
return F_186 ( & V_2 -> V_9 , V_317 , V_276 , V_319 ) ;
}
T_10 F_187 ( struct V_1 * V_2 , T_16 * V_317 )
{
T_10 V_10 ;
const char * V_306 = L_65 ;
if ( F_5 ( & V_2 -> V_5 , V_320 ) )
V_306 = L_93 ;
V_10 = fprintf ( V_317 , L_94 , V_306 ) ;
V_10 += F_188 ( & V_2 -> V_7 -> V_209 , V_317 ) ;
return V_10 ;
}
T_10 F_189 ( struct V_1 * V_2 , T_16 * V_317 )
{
return F_190 ( & V_2 -> V_9 . V_11 , V_317 ) ;
}
struct V_12 * F_191 ( struct V_1 * V_2 ,
unsigned int type )
{
struct V_12 * V_321 ;
F_18 (session->evlist, pos) {
if ( V_321 -> V_14 . type == type )
return V_321 ;
}
return NULL ;
}
int F_192 ( struct V_1 * V_2 ,
const char * V_322 , unsigned long * V_323 )
{
int V_103 , V_235 = - 1 ;
struct V_69 * V_308 ;
for ( V_103 = 0 ; V_103 < V_324 ; ++ V_103 ) {
struct V_12 * V_13 ;
V_13 = F_191 ( V_2 , V_103 ) ;
if ( ! V_13 )
continue;
if ( ! ( V_13 -> V_14 . V_107 & V_174 ) ) {
F_3 ( L_95
L_96 ) ;
return - 1 ;
}
}
V_308 = F_193 ( V_322 ) ;
if ( V_308 == NULL ) {
F_3 ( L_97 ) ;
return - 1 ;
}
for ( V_103 = 0 ; V_103 < V_308 -> V_127 ; V_103 ++ ) {
int V_124 = V_308 -> V_308 [ V_103 ] ;
if ( V_124 >= V_325 ) {
F_3 ( L_98
L_99 , V_124 ) ;
goto V_326;
}
F_194 ( V_124 , V_323 ) ;
}
V_235 = 0 ;
V_326:
F_195 ( V_308 ) ;
return V_235 ;
}
void F_196 ( struct V_1 * V_2 , T_16 * V_317 ,
bool V_327 )
{
if ( V_2 == NULL || V_317 == NULL )
return;
fprintf ( V_317 , L_100 ) ;
F_197 ( V_2 , V_317 , V_327 ) ;
fprintf ( V_317 , L_101 ) ;
}
int F_198 ( struct V_1 * V_2 ,
const struct V_328 * V_329 ,
T_10 V_330 )
{
struct V_12 * V_13 ;
T_10 V_103 ;
int V_235 ;
for ( V_103 = 0 ; V_103 < V_330 ; V_103 ++ ) {
V_13 = F_199 ( V_2 -> V_7 , V_329 [ V_103 ] . V_314 ) ;
if ( V_13 == NULL )
continue;
V_235 = - V_331 ;
if ( V_13 -> V_332 != NULL )
goto V_26;
V_13 -> V_332 = V_329 [ V_103 ] . V_332 ;
}
V_235 = 0 ;
V_26:
return V_235 ;
}
int F_200 ( struct V_25 * V_22 V_34 ,
union V_35 * V_19 ,
struct V_1 * V_2 )
{
struct V_36 * V_7 = V_2 -> V_7 ;
struct V_333 * V_334 = & V_19 -> V_65 ;
T_10 V_103 , V_127 , V_335 ;
V_335 = ( V_334 -> V_5 . V_43 - sizeof( struct V_333 ) ) /
sizeof( struct V_336 ) ;
V_127 = V_334 -> V_127 ;
if ( V_127 > V_335 )
return - V_211 ;
if ( V_37 )
fprintf ( stdout , L_102 , V_127 ) ;
for ( V_103 = 0 ; V_103 < V_127 ; V_103 ++ ) {
struct V_336 * V_156 = & V_334 -> V_128 [ V_103 ] ;
struct V_207 * V_208 ;
if ( V_37 ) {
fprintf ( stdout , L_103 V_151 , V_156 -> V_92 ) ;
fprintf ( stdout , L_104 V_151 , V_156 -> V_123 ) ;
fprintf ( stdout , L_105 V_337 , V_156 -> V_124 ) ;
fprintf ( stdout , L_106 V_337 L_10 , V_156 -> V_80 ) ;
}
V_208 = F_132 ( V_7 , V_156 -> V_92 ) ;
if ( ! V_208 )
return - V_338 ;
V_208 -> V_123 = V_156 -> V_123 ;
V_208 -> V_124 = V_156 -> V_124 ;
V_208 -> V_80 = V_156 -> V_80 ;
}
return 0 ;
}
int F_201 ( struct V_25 * V_22 ,
T_17 V_339 ,
struct V_36 * V_7 ,
struct V_38 * V_38 )
{
union V_35 * V_340 ;
struct V_12 * V_13 ;
T_10 V_127 = 0 , V_103 = 0 , T_9 , V_335 , V_40 ;
int V_235 ;
F_202 ( L_107 ) ;
V_335 = ( V_341 - sizeof( struct V_333 ) ) /
sizeof( struct V_336 ) ;
F_18 (evlist, evsel)
V_127 += V_13 -> V_342 ;
V_40 = V_127 > V_335 ? V_335 : V_127 ;
T_9 = sizeof( struct V_333 ) + V_40 * sizeof( struct V_336 ) ;
V_340 = F_26 ( T_9 ) ;
if ( ! V_340 )
return - V_305 ;
V_340 -> V_65 . V_5 . type = V_243 ;
V_340 -> V_65 . V_5 . V_43 = T_9 ;
V_340 -> V_65 . V_127 = V_40 ;
F_18 (evlist, evsel) {
T_12 V_343 ;
for ( V_343 = 0 ; V_343 < V_13 -> V_342 ; V_343 ++ ) {
struct V_336 * V_156 ;
struct V_207 * V_208 ;
if ( V_103 >= V_40 ) {
V_235 = V_339 ( V_22 , V_340 , NULL , V_38 ) ;
if ( V_235 )
goto V_281;
V_127 -= V_40 ;
V_103 = 0 ;
}
V_156 = & V_340 -> V_65 . V_128 [ V_103 ++ ] ;
V_156 -> V_92 = V_13 -> V_92 [ V_343 ] ;
V_208 = F_132 ( V_7 , V_156 -> V_92 ) ;
if ( ! V_208 ) {
free ( V_340 ) ;
return - V_338 ;
}
V_156 -> V_123 = V_208 -> V_123 ;
V_156 -> V_124 = V_208 -> V_124 ;
V_156 -> V_80 = V_208 -> V_80 ;
}
}
T_9 = sizeof( struct V_333 ) + V_127 * sizeof( struct V_336 ) ;
V_340 -> V_65 . V_5 . V_43 = T_9 ;
V_340 -> V_65 . V_127 = V_127 ;
V_235 = V_339 ( V_22 , V_340 , NULL , V_38 ) ;
V_281:
free ( V_340 ) ;
return V_235 ;
}
