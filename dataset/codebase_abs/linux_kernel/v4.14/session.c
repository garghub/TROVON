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
if ( V_22 -> V_48 == NULL )
V_22 -> V_48 = F_49 ;
if ( V_22 -> exit == NULL )
V_22 -> exit = F_49 ;
if ( V_22 -> V_49 == NULL )
V_22 -> V_49 = V_50 ;
if ( V_22 -> V_51 == NULL )
V_22 -> V_51 = V_52 ;
if ( V_22 -> V_53 == NULL )
V_22 -> V_53 = V_54 ;
if ( V_22 -> V_55 == NULL )
V_22 -> V_55 = V_56 ;
if ( V_22 -> V_57 == NULL )
V_22 -> V_57 = V_58 ;
if ( V_22 -> F_52 == NULL )
V_22 -> F_52 = F_48 ;
if ( V_22 -> V_59 == NULL )
V_22 -> V_59 = F_49 ;
if ( V_22 -> V_60 == NULL )
V_22 -> V_60 = F_49 ;
if ( V_22 -> V_14 == NULL )
V_22 -> V_14 = F_45 ;
if ( V_22 -> V_61 == NULL )
V_22 -> V_61 = F_46 ;
if ( V_22 -> V_62 == NULL )
V_22 -> V_62 = F_44 ;
if ( V_22 -> V_63 == NULL )
V_22 -> V_63 = F_56 ;
if ( V_22 -> V_64 == NULL ) {
if ( V_22 -> V_16 )
V_22 -> V_64 = V_65 ;
else
V_22 -> V_64 = F_50 ;
}
if ( V_22 -> V_66 == NULL )
V_22 -> V_66 = F_56 ;
if ( V_22 -> V_67 == NULL )
V_22 -> V_67 = F_56 ;
if ( V_22 -> V_42 == NULL )
V_22 -> V_42 = F_54 ;
if ( V_22 -> V_68 == NULL )
V_22 -> V_68 = F_56 ;
if ( V_22 -> V_69 == NULL )
V_22 -> V_69 = F_57 ;
if ( V_22 -> V_70 == NULL )
V_22 -> V_70 = F_59 ;
if ( V_22 -> V_71 == NULL )
V_22 -> V_71 = F_61 ;
if ( V_22 -> V_72 == NULL )
V_22 -> V_72 = F_63 ;
if ( V_22 -> V_73 == NULL )
V_22 -> V_73 = F_65 ;
if ( V_22 -> V_74 == NULL )
V_22 -> V_74 = F_56 ;
if ( V_22 -> V_75 == NULL )
V_22 -> V_75 = F_56 ;
}
static void F_68 ( union V_35 * V_19 , void * V_76 )
{
void * V_77 = ( void * ) V_19 + V_19 -> V_5 . V_43 ;
int V_43 = V_77 - V_76 ;
F_69 ( V_43 % sizeof( V_78 ) ) ;
F_70 ( V_76 , V_43 ) ;
}
static void F_71 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
struct V_79 * V_80 = & V_19 -> V_5 ;
F_70 ( V_80 + 1 , V_19 -> V_5 . V_43 - sizeof( * V_80 ) ) ;
}
static void F_72 ( union V_35 * V_19 , bool T_6 )
{
V_19 -> V_46 . V_81 = F_73 ( V_19 -> V_46 . V_81 ) ;
V_19 -> V_46 . V_82 = F_73 ( V_19 -> V_46 . V_82 ) ;
if ( T_6 ) {
void * V_76 = & V_19 -> V_46 . V_46 ;
V_76 += F_74 ( strlen ( V_76 ) + 1 , sizeof( V_78 ) ) ;
F_68 ( V_19 , V_76 ) ;
}
}
static void F_75 ( union V_35 * V_19 ,
bool T_6 )
{
V_19 -> V_44 . V_81 = F_73 ( V_19 -> V_44 . V_81 ) ;
V_19 -> V_44 . V_82 = F_73 ( V_19 -> V_44 . V_82 ) ;
V_19 -> V_44 . V_83 = F_76 ( V_19 -> V_44 . V_83 ) ;
V_19 -> V_44 . V_84 = F_76 ( V_19 -> V_44 . V_84 ) ;
V_19 -> V_44 . V_85 = F_76 ( V_19 -> V_44 . V_85 ) ;
if ( T_6 ) {
void * V_76 = & V_19 -> V_44 . V_86 ;
V_76 += F_74 ( strlen ( V_76 ) + 1 , sizeof( V_78 ) ) ;
F_68 ( V_19 , V_76 ) ;
}
}
static void F_77 ( union V_35 * V_19 ,
bool T_6 )
{
V_19 -> V_45 . V_81 = F_73 ( V_19 -> V_45 . V_81 ) ;
V_19 -> V_45 . V_82 = F_73 ( V_19 -> V_45 . V_82 ) ;
V_19 -> V_45 . V_83 = F_76 ( V_19 -> V_45 . V_83 ) ;
V_19 -> V_45 . V_84 = F_76 ( V_19 -> V_45 . V_84 ) ;
V_19 -> V_45 . V_85 = F_76 ( V_19 -> V_45 . V_85 ) ;
V_19 -> V_45 . V_87 = F_73 ( V_19 -> V_45 . V_87 ) ;
V_19 -> V_45 . F_53 = F_73 ( V_19 -> V_45 . F_53 ) ;
V_19 -> V_45 . V_88 = F_76 ( V_19 -> V_45 . V_88 ) ;
if ( T_6 ) {
void * V_76 = & V_19 -> V_45 . V_86 ;
V_76 += F_74 ( strlen ( V_76 ) + 1 , sizeof( V_78 ) ) ;
F_68 ( V_19 , V_76 ) ;
}
}
static void F_78 ( union V_35 * V_19 , bool T_6 )
{
V_19 -> V_48 . V_81 = F_73 ( V_19 -> V_48 . V_81 ) ;
V_19 -> V_48 . V_82 = F_73 ( V_19 -> V_48 . V_82 ) ;
V_19 -> V_48 . V_89 = F_73 ( V_19 -> V_48 . V_89 ) ;
V_19 -> V_48 . V_90 = F_73 ( V_19 -> V_48 . V_90 ) ;
V_19 -> V_48 . time = F_76 ( V_19 -> V_48 . time ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_48 + 1 ) ;
}
static void F_79 ( union V_35 * V_19 , bool T_6 )
{
V_19 -> F_52 . V_81 = F_73 ( V_19 -> F_52 . V_81 ) ;
V_19 -> F_52 . V_82 = F_73 ( V_19 -> F_52 . V_82 ) ;
V_19 -> F_52 . V_91 = F_76 ( V_19 -> F_52 . V_91 ) ;
V_19 -> F_52 . V_92 = F_76 ( V_19 -> F_52 . V_92 ) ;
V_19 -> F_52 . V_93 = F_76 ( V_19 -> F_52 . V_93 ) ;
V_19 -> F_52 . V_94 = F_76 ( V_19 -> F_52 . V_94 ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> F_52 + 1 ) ;
}
static void F_80 ( union V_35 * V_19 , bool T_6 )
{
V_19 -> V_53 . V_95 = F_76 ( V_19 -> V_53 . V_95 ) ;
V_19 -> V_53 . V_96 = F_76 ( V_19 -> V_53 . V_96 ) ;
V_19 -> V_53 . V_97 = F_76 ( V_19 -> V_53 . V_97 ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_53 + 1 ) ;
}
static void F_81 ( union V_35 * V_19 ,
bool T_6 )
{
V_19 -> V_55 . V_81 = F_73 ( V_19 -> V_55 . V_81 ) ;
V_19 -> V_55 . V_82 = F_73 ( V_19 -> V_55 . V_82 ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_55 + 1 ) ;
}
static void F_82 ( union V_35 * V_19 , bool T_6 )
{
if ( V_19 -> V_5 . type == V_98 ) {
V_19 -> V_57 . V_99 =
F_73 ( V_19 -> V_57 . V_99 ) ;
V_19 -> V_57 . V_100 =
F_73 ( V_19 -> V_57 . V_100 ) ;
}
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_57 + 1 ) ;
}
static void F_83 ( union V_35 * V_19 ,
bool T_6 )
{
V_19 -> V_59 . time = F_76 ( V_19 -> V_59 . time ) ;
V_19 -> V_59 . V_94 = F_76 ( V_19 -> V_59 . V_94 ) ;
V_19 -> V_59 . V_101 = F_76 ( V_19 -> V_59 . V_101 ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_59 + 1 ) ;
}
static T_7 F_84 ( T_7 V_102 )
{
int V_103 = ( V_102 >> 4 ) | ( ( V_102 & 0xf ) << 4 ) ;
V_103 = ( ( V_103 & 0xcc ) >> 2 ) | ( ( V_103 & 0x33 ) << 2 ) ;
V_103 = ( ( V_103 & 0xaa ) >> 1 ) | ( ( V_103 & 0x55 ) << 1 ) ;
return ( T_7 ) V_103 ;
}
static void F_85 ( T_7 * V_104 , unsigned V_84 )
{
unsigned V_105 ;
for ( V_105 = 0 ; V_105 < V_84 ; V_105 ++ ) {
* V_104 = F_84 ( * V_104 ) ;
V_104 ++ ;
}
}
void F_86 ( struct V_106 * V_14 )
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
F_91 ( V_107 ) ;
F_91 ( V_108 ) ;
F_91 ( V_109 ) ;
F_91 ( V_110 ) ;
F_90 ( V_111 ) ;
F_90 ( V_112 ) ;
F_91 ( V_113 ) ;
F_91 ( V_114 ) ;
F_91 ( V_115 ) ;
F_91 ( V_116 ) ;
F_90 ( V_117 ) ;
F_90 ( V_118 ) ;
F_89 ( V_119 ) ;
if ( F_87 ( V_110 , 1 ) )
F_85 ( ( T_7 * ) ( & V_14 -> V_110 + 1 ) ,
sizeof( V_78 ) ) ;
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
V_43 -= ( void * ) & V_19 -> V_14 . V_94 - ( void * ) V_19 ;
F_70 ( V_19 -> V_14 . V_94 , V_43 ) ;
}
static void F_93 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
V_19 -> V_61 . type = F_76 ( V_19 -> V_61 . type ) ;
V_19 -> V_61 . V_94 = F_76 ( V_19 -> V_61 . V_94 ) ;
}
static void F_94 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
V_19 -> V_120 . V_120 . V_121 =
F_76 ( V_19 -> V_120 . V_120 . V_121 ) ;
}
static void F_95 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
V_19 -> V_62 . V_43 = F_73 ( V_19 -> V_62 . V_43 ) ;
}
static void F_96 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
T_10 V_43 ;
V_19 -> V_67 . type = F_73 ( V_19 -> V_67 . type ) ;
V_43 = V_19 -> V_5 . V_43 ;
V_43 -= ( void * ) & V_19 -> V_67 . V_122 - ( void * ) V_19 ;
F_70 ( V_19 -> V_67 . V_122 , V_43 ) ;
}
static void F_97 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
V_19 -> V_42 . V_43 = F_76 ( V_19 -> V_42 . V_43 ) ;
V_19 -> V_42 . V_123 = F_76 ( V_19 -> V_42 . V_123 ) ;
V_19 -> V_42 . V_124 = F_76 ( V_19 -> V_42 . V_124 ) ;
V_19 -> V_42 . V_125 = F_73 ( V_19 -> V_42 . V_125 ) ;
V_19 -> V_42 . V_82 = F_73 ( V_19 -> V_42 . V_82 ) ;
V_19 -> V_42 . V_126 = F_73 ( V_19 -> V_42 . V_126 ) ;
}
static void F_98 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
V_19 -> V_68 . type = F_73 ( V_19 -> V_68 . type ) ;
V_19 -> V_68 . V_127 = F_73 ( V_19 -> V_68 . V_127 ) ;
V_19 -> V_68 . V_126 = F_73 ( V_19 -> V_68 . V_126 ) ;
V_19 -> V_68 . V_81 = F_73 ( V_19 -> V_68 . V_81 ) ;
V_19 -> V_68 . V_82 = F_73 ( V_19 -> V_68 . V_82 ) ;
V_19 -> V_68 . V_128 = F_76 ( V_19 -> V_68 . V_128 ) ;
}
static void F_99 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
unsigned V_105 ;
V_19 -> V_69 . V_129 = F_76 ( V_19 -> V_69 . V_129 ) ;
for ( V_105 = 0 ; V_105 < V_19 -> V_69 . V_129 ; V_105 ++ )
V_19 -> V_69 . V_130 [ V_105 ] . V_81 = F_76 ( V_19 -> V_69 . V_130 [ V_105 ] . V_81 ) ;
}
static void F_100 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
struct V_131 * V_76 = & V_19 -> V_70 . V_76 ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
unsigned V_105 ;
V_76 -> type = F_76 ( V_76 -> type ) ;
switch ( V_76 -> type ) {
case V_136 :
V_133 = (struct V_132 * ) V_76 -> V_76 ;
V_133 -> V_129 = F_101 ( V_133 -> V_129 ) ;
for ( V_105 = 0 ; V_105 < V_133 -> V_129 ; V_105 ++ )
V_133 -> V_126 [ V_105 ] = F_101 ( V_133 -> V_126 [ V_105 ] ) ;
break;
case V_137 :
V_135 = (struct V_134 * ) V_76 -> V_76 ;
V_135 -> V_129 = F_101 ( V_135 -> V_129 ) ;
V_135 -> V_138 = F_101 ( V_135 -> V_138 ) ;
switch ( V_135 -> V_138 ) {
case 4 : F_102 ( & V_135 -> V_135 , V_135 -> V_129 ) ; break;
case 8 : F_70 ( & V_135 -> V_135 , V_135 -> V_129 ) ; break;
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
V_78 V_43 ;
V_43 = V_19 -> V_71 . V_129 * sizeof( V_19 -> V_71 . V_76 [ 0 ] ) ;
V_43 += 1 ;
F_70 ( & V_19 -> V_71 . V_129 , V_43 ) ;
}
static void F_104 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
V_19 -> V_72 . V_94 = F_76 ( V_19 -> V_72 . V_94 ) ;
V_19 -> V_72 . V_139 = F_73 ( V_19 -> V_72 . V_139 ) ;
V_19 -> V_72 . V_126 = F_73 ( V_19 -> V_72 . V_126 ) ;
V_19 -> V_72 . V_140 = F_76 ( V_19 -> V_72 . V_140 ) ;
V_19 -> V_72 . V_141 = F_76 ( V_19 -> V_72 . V_141 ) ;
V_19 -> V_72 . V_142 = F_76 ( V_19 -> V_72 . V_142 ) ;
}
static void F_105 ( union V_35 * V_19 ,
bool T_6 V_34 )
{
V_19 -> V_73 . type = F_76 ( V_19 -> V_73 . type ) ;
V_19 -> V_73 . time = F_76 ( V_19 -> V_73 . time ) ;
}
static int V_65 ( struct V_25 * V_22 V_34 ,
union V_35 * V_19 V_34 ,
struct V_16 * V_17 )
{
if ( V_37 )
fprintf ( stdout , L_10 ) ;
return F_106 ( V_17 , V_143 ) ;
}
int F_107 ( struct V_1 * V_144 , union V_35 * V_19 ,
struct V_20 * V_21 , V_78 V_23 )
{
return F_108 ( & V_144 -> V_16 , V_19 , V_21 , V_23 ) ;
}
static void F_109 ( struct V_20 * V_21 )
{
struct V_145 * V_146 = V_21 -> V_146 ;
struct V_147 * V_148 = V_21 -> V_147 ;
V_78 V_149 = V_146 -> V_129 ;
unsigned int V_105 ;
for ( V_105 = 0 ; V_105 < V_149 ; V_105 ++ ) {
if ( V_146 -> V_150 [ V_105 ] == V_151 )
break;
}
if ( ( V_105 != V_149 ) && V_148 -> V_129 ) {
V_78 V_152 ;
V_152 = V_105 + 1 + V_148 -> V_129 + 1 ;
V_149 = V_105 + 1 ;
printf ( L_11 V_153 L_10 , V_152 ) ;
for ( V_105 = 0 ; V_105 < V_149 ; V_105 ++ )
printf ( L_12 V_154 L_10 ,
V_105 , V_146 -> V_150 [ V_105 ] ) ;
printf ( L_12 V_154 L_10 ,
( int ) ( V_149 ) , V_148 -> V_130 [ 0 ] . V_155 ) ;
for ( V_105 = 0 ; V_105 < V_148 -> V_129 ; V_105 ++ )
printf ( L_12 V_154 L_10 ,
( int ) ( V_105 + V_149 + 1 ) , V_148 -> V_130 [ V_105 ] . V_156 ) ;
}
}
static void F_110 ( struct V_12 * V_13 ,
struct V_20 * V_21 )
{
unsigned int V_105 ;
struct V_145 * V_146 = V_21 -> V_146 ;
if ( F_111 ( V_13 ) )
F_109 ( V_21 ) ;
printf ( L_13 V_153 L_10 , V_146 -> V_129 ) ;
for ( V_105 = 0 ; V_105 < V_146 -> V_129 ; V_105 ++ )
printf ( L_12 V_154 L_10 ,
V_105 , V_146 -> V_150 [ V_105 ] ) ;
}
static void F_112 ( struct V_20 * V_21 )
{
T_11 V_105 ;
printf ( L_14 V_153 L_10 , V_21 -> V_147 -> V_129 ) ;
for ( V_105 = 0 ; V_105 < V_21 -> V_147 -> V_129 ; V_105 ++ ) {
struct V_157 * V_158 = & V_21 -> V_147 -> V_130 [ V_105 ] ;
printf ( L_15 V_153 L_16 V_154 L_17 V_154 L_18 ,
V_105 , V_158 -> V_156 , V_158 -> V_155 ,
( unsigned short ) V_158 -> V_97 . V_159 ,
V_158 -> V_97 . V_160 ? L_19 : L_20 ,
V_158 -> V_97 . V_161 ? L_21 : L_20 ,
V_158 -> V_97 . abort ? L_22 : L_20 ,
V_158 -> V_97 . V_162 ? L_23 : L_20 ,
( unsigned ) V_158 -> V_97 . V_163 ) ;
}
}
static void F_113 ( V_78 V_135 , V_78 * V_164 )
{
unsigned V_165 , V_105 = 0 ;
F_114 (rid, (unsigned long *) &mask, sizeof(mask) * 8 ) {
V_78 V_140 = V_164 [ V_105 ++ ] ;
printf ( L_24 V_154 L_10 ,
F_115 ( V_165 ) , V_140 ) ;
}
}
static inline const char * F_116 ( struct V_166 * V_167 )
{
if ( V_167 -> V_168 > V_169 )
return L_25 ;
return V_170 [ V_167 -> V_168 ] ;
}
static void F_117 ( const char * type , struct V_166 * V_164 )
{
V_78 V_135 = V_164 -> V_135 ;
printf ( L_26 V_154 L_27 ,
type ,
V_135 ,
F_116 ( V_164 ) ) ;
F_113 ( V_135 , V_164 -> V_164 ) ;
}
static void F_118 ( struct V_20 * V_21 )
{
struct V_166 * V_171 = & V_21 -> V_171 ;
if ( V_171 -> V_164 )
F_117 ( L_28 , V_171 ) ;
}
static void F_119 ( struct V_20 * V_21 )
{
struct V_166 * V_172 = & V_21 -> V_172 ;
if ( V_172 -> V_164 )
F_117 ( L_29 , V_172 ) ;
}
static void F_120 ( struct V_173 * V_174 )
{
printf ( L_30 V_153 L_31 ,
V_174 -> V_43 , V_174 -> V_123 ) ;
}
static void F_121 ( struct V_36 * V_7 ,
union V_35 * V_19 ,
struct V_20 * V_21 )
{
V_78 V_109 = F_122 ( V_7 ) ;
if ( V_19 -> V_5 . type != V_175 &&
! F_34 ( V_7 ) ) {
fputs ( L_32 , stdout ) ;
return;
}
if ( ( V_109 & V_176 ) )
printf ( L_33 , V_21 -> V_126 ) ;
if ( V_109 & V_177 )
printf ( L_34 V_153 L_20 , V_21 -> time ) ;
}
static void F_123 ( struct V_20 * V_21 , V_78 V_110 )
{
printf ( L_35 ) ;
if ( V_110 & V_178 )
printf ( L_36 V_154 L_10 ,
V_21 -> F_52 . V_92 ) ;
if ( V_110 & V_179 )
printf ( L_37 V_154 L_10 ,
V_21 -> F_52 . V_93 ) ;
if ( V_110 & V_180 ) {
V_78 V_105 ;
printf ( L_38 V_153 L_10 , V_21 -> F_52 . V_181 . V_129 ) ;
for ( V_105 = 0 ; V_105 < V_21 -> F_52 . V_181 . V_129 ; V_105 ++ ) {
struct V_182 * V_91 ;
V_91 = & V_21 -> F_52 . V_181 . V_183 [ V_105 ] ;
printf ( L_39 V_154
L_40 V_154 L_10 ,
V_91 -> V_94 , V_91 -> V_91 ) ;
}
} else
printf ( L_39 V_154 L_40 V_154 L_10 ,
V_21 -> F_52 . V_184 . V_94 , V_21 -> F_52 . V_184 . V_91 ) ;
}
static void F_124 ( struct V_36 * V_7 , union V_35 * V_19 ,
V_78 V_23 , struct V_20 * V_21 )
{
if ( ! V_37 )
return;
printf ( L_41 V_154 L_42 ,
V_23 , V_19 -> V_5 . V_43 , V_19 -> V_5 . type ) ;
F_125 ( V_19 ) ;
if ( V_21 )
F_121 ( V_7 , V_19 , V_21 ) ;
printf ( L_43 V_154 L_44 , V_23 ,
V_19 -> V_5 . V_43 , F_126 ( V_19 -> V_5 . type ) ) ;
}
static void F_127 ( struct V_12 * V_13 , union V_35 * V_19 ,
struct V_20 * V_21 )
{
V_78 V_109 ;
if ( ! V_37 )
return;
printf ( L_45 V_154 L_46 V_153 L_47 V_154 L_10 ,
V_19 -> V_5 . V_185 , V_21 -> V_81 , V_21 -> V_82 , V_21 -> V_128 ,
V_21 -> V_186 , V_21 -> V_187 ) ;
V_109 = V_13 -> V_14 . V_109 ;
if ( V_109 & V_188 )
F_110 ( V_13 , V_21 ) ;
if ( ( V_109 & V_189 ) && ! F_111 ( V_13 ) )
F_112 ( V_21 ) ;
if ( V_109 & V_190 )
F_118 ( V_21 ) ;
if ( V_109 & V_191 )
F_119 ( V_21 ) ;
if ( V_109 & V_192 )
F_120 ( & V_21 -> V_193 ) ;
if ( V_109 & V_194 )
printf ( L_48 V_153 L_10 , V_21 -> V_195 ) ;
if ( V_109 & V_196 )
printf ( L_49 V_154 L_10 , V_21 -> V_197 ) ;
if ( V_109 & V_198 )
printf ( L_50 V_154 L_10 , V_21 -> V_199 ) ;
if ( V_109 & V_200 )
printf ( L_51 V_154 L_10 , V_21 -> V_201 ) ;
if ( V_109 & V_202 )
F_123 ( V_21 , V_13 -> V_14 . V_110 ) ;
}
static void F_128 ( struct V_12 * V_13 , union V_35 * V_19 )
{
struct V_203 * V_203 = & V_19 -> F_52 ;
V_78 V_110 ;
if ( ! V_37 )
return;
printf ( L_52 V_153 L_10 , V_19 -> F_52 . V_81 , V_19 -> F_52 . V_82 ,
V_13 ? F_129 ( V_13 ) : L_53 ,
V_19 -> F_52 . V_91 ) ;
V_110 = V_13 -> V_14 . V_110 ;
if ( V_110 & V_178 )
printf ( L_54 V_153 L_10 , V_203 -> V_92 ) ;
if ( V_110 & V_179 )
printf ( L_55 V_153 L_10 , V_203 -> V_93 ) ;
if ( V_110 & V_204 )
printf ( L_56 V_153 L_10 , V_203 -> V_94 ) ;
}
static struct V_38 * F_130 ( struct V_9 * V_9 ,
union V_35 * V_19 ,
struct V_20 * V_21 )
{
struct V_38 * V_38 ;
if ( V_205 &&
( ( V_21 -> V_206 == V_207 ) ||
( V_21 -> V_206 == V_208 ) ) ) {
T_12 V_81 ;
if ( V_19 -> V_5 . type == V_209
|| V_19 -> V_5 . type == V_210 )
V_81 = V_19 -> V_44 . V_81 ;
else
V_81 = V_21 -> V_81 ;
V_38 = F_131 ( V_9 , V_81 ) ;
if ( ! V_38 )
V_38 = F_132 ( V_9 , V_211 ) ;
return V_38 ;
}
return & V_9 -> V_11 ;
}
static int F_133 ( struct V_36 * V_7 ,
struct V_25 * V_22 ,
union V_35 * V_19 ,
struct V_20 * V_21 ,
struct V_182 * V_212 ,
struct V_38 * V_38 )
{
struct V_213 * V_214 = F_134 ( V_7 , V_212 -> V_94 ) ;
if ( V_214 ) {
V_21 -> V_94 = V_212 -> V_94 ;
V_21 -> V_186 = V_212 -> V_91 - V_214 -> V_186 ;
V_214 -> V_186 = V_212 -> V_91 ;
}
if ( ! V_214 || V_214 -> V_13 == NULL ) {
++ V_7 -> V_215 . V_216 ;
return 0 ;
}
return V_22 -> V_21 ( V_22 , V_19 , V_21 , V_214 -> V_13 , V_38 ) ;
}
static int F_135 ( struct V_36 * V_7 ,
struct V_25 * V_22 ,
union V_35 * V_19 ,
struct V_20 * V_21 ,
struct V_38 * V_38 )
{
int V_10 = - V_217 ;
V_78 V_105 ;
for ( V_105 = 0 ; V_105 < V_21 -> F_52 . V_181 . V_129 ; V_105 ++ ) {
V_10 = F_133 ( V_7 , V_22 , V_19 , V_21 ,
& V_21 -> F_52 . V_181 . V_183 [ V_105 ] ,
V_38 ) ;
if ( V_10 )
break;
}
return V_10 ;
}
static int
F_136 ( struct V_36 * V_7 ,
struct V_25 * V_22 ,
union V_35 * V_19 ,
struct V_20 * V_21 ,
struct V_12 * V_13 ,
struct V_38 * V_38 )
{
V_78 V_109 = V_13 -> V_14 . V_109 ;
V_78 V_110 = V_13 -> V_14 . V_110 ;
if ( ! ( V_109 & V_202 ) )
return V_22 -> V_21 ( V_22 , V_19 , V_21 , V_13 , V_38 ) ;
if ( V_110 & V_180 )
return F_135 ( V_7 , V_22 , V_19 , V_21 ,
V_38 ) ;
else
return F_133 ( V_7 , V_22 , V_19 , V_21 ,
& V_21 -> F_52 . V_184 , V_38 ) ;
}
static int F_137 ( struct V_9 * V_9 ,
struct V_36 * V_7 ,
union V_35 * V_19 ,
struct V_20 * V_21 ,
struct V_25 * V_22 , V_78 V_23 )
{
struct V_12 * V_13 ;
struct V_38 * V_38 ;
F_124 ( V_7 , V_19 , V_23 , V_21 ) ;
V_13 = F_138 ( V_7 , V_21 -> V_94 ) ;
V_38 = F_130 ( V_9 , V_19 , V_21 ) ;
switch ( V_19 -> V_5 . type ) {
case V_175 :
if ( V_13 == NULL ) {
++ V_7 -> V_215 . V_216 ;
return 0 ;
}
F_127 ( V_13 , V_19 , V_21 ) ;
if ( V_38 == NULL ) {
++ V_7 -> V_215 . V_218 ;
return 0 ;
}
return F_136 ( V_7 , V_22 , V_19 , V_21 , V_13 , V_38 ) ;
case V_209 :
return V_22 -> V_44 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_210 :
if ( V_19 -> V_5 . V_185 & V_219 )
++ V_7 -> V_215 . V_220 ;
return V_22 -> V_45 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_221 :
return V_22 -> V_46 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_222 :
return V_22 -> V_47 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_223 :
return V_22 -> V_48 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_224 :
return V_22 -> exit ( V_22 , V_19 , V_21 , V_38 ) ;
case V_225 :
if ( V_22 -> V_49 == V_50 )
V_7 -> V_215 . V_226 += V_19 -> V_49 . V_49 ;
return V_22 -> V_49 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_227 :
if ( V_22 -> V_51 == V_52 )
V_7 -> V_215 . V_228 += V_19 -> V_51 . V_49 ;
return V_22 -> V_51 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_229 :
F_128 ( V_13 , V_19 ) ;
return V_22 -> F_52 ( V_22 , V_19 , V_21 , V_13 , V_38 ) ;
case V_230 :
return V_22 -> V_59 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_231 :
return V_22 -> V_60 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_232 :
if ( V_22 -> V_53 == V_54 ) {
if ( V_19 -> V_53 . V_97 & V_233 )
V_7 -> V_215 . V_234 += 1 ;
if ( V_19 -> V_53 . V_97 & V_235 )
V_7 -> V_215 . V_236 += 1 ;
}
return V_22 -> V_53 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_237 :
return V_22 -> V_55 ( V_22 , V_19 , V_21 , V_38 ) ;
case V_238 :
case V_98 :
return V_22 -> V_57 ( V_22 , V_19 , V_21 , V_38 ) ;
default:
++ V_7 -> V_215 . V_239 ;
return - 1 ;
}
}
static int F_24 ( struct V_1 * V_2 ,
union V_35 * V_19 ,
struct V_20 * V_21 ,
struct V_25 * V_22 ,
V_78 V_23 )
{
int V_10 ;
V_10 = F_139 ( V_2 , V_19 , V_21 , V_22 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_10 > 0 )
return 0 ;
return F_137 ( & V_2 -> V_9 , V_2 -> V_7 ,
V_19 , V_21 , V_22 , V_23 ) ;
}
static T_5 F_140 ( struct V_1 * V_2 ,
union V_35 * V_19 ,
V_78 V_23 )
{
struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_25 * V_22 = V_2 -> V_22 ;
int V_39 = F_55 ( V_2 -> V_4 ) ;
int V_240 ;
F_124 ( V_2 -> V_7 , V_19 , V_23 , NULL ) ;
switch ( V_19 -> V_5 . type ) {
case V_241 :
V_240 = V_22 -> V_14 ( V_22 , V_19 , & V_2 -> V_7 ) ;
if ( V_240 == 0 ) {
F_9 ( V_2 ) ;
F_19 ( V_2 ) ;
}
return V_240 ;
case V_242 :
return V_22 -> V_61 ( V_22 , V_19 , & V_2 -> V_7 ) ;
case V_243 :
return 0 ;
case V_244 :
F_141 ( V_39 , V_23 , V_245 ) ;
return V_22 -> V_62 ( V_22 , V_19 , V_2 ) ;
case V_246 :
return V_22 -> V_63 ( V_22 , V_19 , V_2 ) ;
case V_247 :
return V_22 -> V_64 ( V_22 , V_19 , V_17 ) ;
case V_248 :
return V_22 -> V_66 ( V_22 , V_19 , V_2 ) ;
case V_249 :
return V_22 -> V_67 ( V_22 , V_19 , V_2 ) ;
case V_250 :
F_141 ( V_39 , V_23 + V_19 -> V_5 . V_43 , V_245 ) ;
return V_22 -> V_42 ( V_22 , V_19 , V_2 ) ;
case V_251 :
F_142 ( V_2 , V_19 ) ;
return V_22 -> V_68 ( V_22 , V_19 , V_2 ) ;
case V_252 :
return V_22 -> V_69 ( V_22 , V_19 , V_2 ) ;
case V_253 :
return V_22 -> V_70 ( V_22 , V_19 , V_2 ) ;
case V_254 :
return V_22 -> V_71 ( V_22 , V_19 , V_2 ) ;
case V_255 :
return V_22 -> V_72 ( V_22 , V_19 , V_2 ) ;
case V_256 :
return V_22 -> V_73 ( V_22 , V_19 , V_2 ) ;
case V_257 :
V_2 -> V_74 = V_19 -> V_74 ;
return V_22 -> V_74 ( V_22 , V_19 , V_2 ) ;
case V_258 :
return V_22 -> V_75 ( V_22 , V_19 , V_2 ) ;
default:
return - V_217 ;
}
}
int F_143 ( struct V_1 * V_2 ,
union V_35 * V_19 ,
struct V_20 * V_21 )
{
struct V_36 * V_7 = V_2 -> V_7 ;
struct V_25 * V_22 = V_2 -> V_22 ;
F_144 ( & V_7 -> V_215 , V_19 -> V_5 . type ) ;
if ( V_19 -> V_5 . type >= V_259 )
return F_140 ( V_2 , V_19 , 0 ) ;
return F_137 ( & V_2 -> V_9 , V_7 , V_19 , V_21 , V_22 , 0 ) ;
}
static void F_145 ( union V_35 * V_19 , bool T_6 )
{
T_13 V_260 ;
V_260 = V_261 [ V_19 -> V_5 . type ] ;
if ( V_260 )
V_260 ( V_19 , T_6 ) ;
}
int F_146 ( struct V_1 * V_2 , T_3 V_23 ,
void * V_41 , T_10 V_262 ,
union V_35 * * V_263 ,
struct V_20 * V_21 )
{
union V_35 * V_19 ;
T_10 V_264 , V_265 ;
int V_39 ;
if ( V_2 -> V_266 && ! V_2 -> V_5 . V_267 ) {
V_19 = V_23 - V_2 -> V_268 +
V_2 -> V_269 ;
goto V_270;
}
if ( F_4 ( V_2 -> V_4 ) )
return - 1 ;
V_39 = F_55 ( V_2 -> V_4 ) ;
V_264 = sizeof( struct V_79 ) ;
if ( V_262 < V_264 )
return - 1 ;
if ( F_141 ( V_39 , V_23 , V_245 ) == ( T_3 ) - 1 ||
F_147 ( V_39 , V_41 , V_264 ) != ( T_4 ) V_264 )
return - 1 ;
V_19 = (union V_35 * ) V_41 ;
if ( V_2 -> V_5 . V_267 )
F_148 ( & V_19 -> V_5 ) ;
if ( V_19 -> V_5 . V_43 < V_264 || V_19 -> V_5 . V_43 > V_262 )
return - 1 ;
V_265 = V_19 -> V_5 . V_43 - V_264 ;
if ( F_147 ( V_39 , V_41 , V_265 ) != ( T_4 ) V_265 )
return - 1 ;
if ( V_2 -> V_5 . V_267 )
F_145 ( V_19 , F_34 ( V_2 -> V_7 ) ) ;
V_270:
if ( V_21 && V_19 -> V_5 . type < V_259 &&
F_23 ( V_2 -> V_7 , V_19 , V_21 ) )
return - 1 ;
* V_263 = V_19 ;
return 0 ;
}
static T_5 F_149 ( struct V_1 * V_2 ,
union V_35 * V_19 , V_78 V_23 )
{
struct V_36 * V_7 = V_2 -> V_7 ;
struct V_25 * V_22 = V_2 -> V_22 ;
struct V_20 V_21 ;
int V_10 ;
if ( V_2 -> V_5 . V_267 )
F_145 ( V_19 , F_34 ( V_7 ) ) ;
if ( V_19 -> V_5 . type >= V_271 )
return - V_217 ;
F_144 ( & V_7 -> V_215 , V_19 -> V_5 . type ) ;
if ( V_19 -> V_5 . type >= V_259 )
return F_140 ( V_2 , V_19 , V_23 ) ;
V_10 = F_23 ( V_7 , V_19 , & V_21 ) ;
if ( V_10 )
return V_10 ;
if ( V_22 -> V_16 ) {
V_10 = F_107 ( V_2 , V_19 , & V_21 , V_23 ) ;
if ( V_10 != - V_272 )
return V_10 ;
}
return F_24 ( V_2 , V_19 , & V_21 , V_22 ,
V_23 ) ;
}
void F_148 ( struct V_79 * V_80 )
{
V_80 -> type = F_73 ( V_80 -> type ) ;
V_80 -> V_185 = F_101 ( V_80 -> V_185 ) ;
V_80 -> V_43 = F_101 ( V_80 -> V_43 ) ;
}
struct V_139 * F_150 ( struct V_1 * V_2 , T_14 V_81 )
{
return F_151 ( & V_2 -> V_9 . V_11 , - 1 , V_81 ) ;
}
int F_152 ( struct V_1 * V_2 )
{
struct V_139 * V_139 ;
int V_240 = 0 ;
V_139 = F_151 ( & V_2 -> V_9 . V_11 , 0 , 0 ) ;
if ( V_139 == NULL || F_153 ( V_139 , L_57 , 0 ) ) {
F_3 ( L_58 ) ;
V_240 = - 1 ;
}
if ( V_139 == NULL || F_154 ( V_139 , 0 , NULL ) ) {
F_3 ( L_58 ) ;
V_240 = - 1 ;
}
F_155 ( V_139 ) ;
return V_240 ;
}
static void
F_156 ( const struct V_1 * V_2 )
{
const struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_12 * V_13 ;
bool V_273 = true ;
F_18 (session->evlist, evsel) {
if ( V_13 -> V_14 . V_274 )
V_273 = false ;
}
if ( ! V_273 )
return;
if ( V_17 -> V_275 != 0 )
F_157 ( L_59 , V_17 -> V_275 ) ;
}
static void F_158 ( const struct V_1 * V_2 )
{
const struct V_276 * V_215 = & V_2 -> V_7 -> V_215 ;
if ( V_2 -> V_22 -> V_49 == V_50 &&
V_215 -> V_277 [ V_225 ] != 0 ) {
F_157 ( L_60
L_61 ,
V_215 -> V_277 [ 0 ] ,
V_215 -> V_277 [ V_225 ] ) ;
}
if ( V_2 -> V_22 -> V_51 == V_52 ) {
double V_278 ;
V_278 = ( double ) V_215 -> V_228 /
( double ) ( V_215 -> V_277 [ V_175 ] + V_215 -> V_228 ) ;
if ( V_278 > 0.05 ) {
F_157 ( L_62 V_153 L_63 ,
V_215 -> V_277 [ V_175 ] + V_215 -> V_228 ,
V_278 * 100.0 ) ;
}
}
if ( V_2 -> V_22 -> V_53 == V_54 &&
V_215 -> V_234 != 0 ) {
F_157 ( L_64 V_153 L_65 ,
V_215 -> V_234 ,
V_215 -> V_277 [ V_232 ] ) ;
}
if ( V_2 -> V_22 -> V_53 == V_54 &&
V_215 -> V_236 != 0 ) {
bool V_279 = false ;
( void ) F_159 ( L_66 ,
& V_279 ) ;
F_157 ( L_67 V_153 L_65
L_68 ,
V_215 -> V_236 ,
V_215 -> V_277 [ V_232 ] ,
V_279 ?
L_69
L_70 :
L_71 ) ;
}
if ( V_215 -> V_239 != 0 ) {
F_157 ( L_72
L_73
L_74
L_75
L_76 ,
V_215 -> V_239 ) ;
}
if ( V_215 -> V_216 != 0 ) {
F_157 ( L_77 ,
V_215 -> V_216 ) ;
}
if ( V_215 -> V_280 != 0 ) {
F_157 ( L_78
L_79
L_80 ,
V_215 -> V_280 ,
V_215 -> V_277 [ V_175 ] ) ;
}
if ( V_215 -> V_218 != 0 ) {
F_157 ( L_81
L_82 ,
V_215 -> V_218 ) ;
}
F_156 ( V_2 ) ;
F_160 ( V_215 ) ;
if ( V_215 -> V_220 != 0 ) {
F_157 ( L_83
L_84
L_85
L_86
L_87
L_88
L_89 ,
V_215 -> V_220 ) ;
}
}
static int F_161 ( struct V_139 * V_139 ,
void * V_104 V_34 )
{
return F_162 ( V_139 ) ;
}
static int F_163 ( struct V_1 * V_2 )
{
return F_164 ( & V_2 -> V_9 ,
F_161 ,
NULL ) ;
}
static int F_165 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_25 * V_22 = V_2 -> V_22 ;
int V_39 = F_55 ( V_2 -> V_4 ) ;
union V_35 * V_19 ;
T_15 V_43 , V_281 = 0 ;
void * V_41 = NULL ;
T_5 V_282 = 0 ;
V_78 V_283 ;
T_4 V_240 ;
void * V_104 ;
F_67 ( V_22 ) ;
V_283 = 0 ;
V_281 = sizeof( union V_35 ) ;
V_41 = malloc ( V_281 ) ;
if ( ! V_41 )
return - V_284 ;
F_166 ( V_17 , true ) ;
V_285:
V_19 = V_41 ;
V_240 = F_147 ( V_39 , V_19 , sizeof( struct V_79 ) ) ;
if ( V_240 <= 0 ) {
if ( V_240 == 0 )
goto V_286;
F_3 ( L_90 ) ;
goto V_287;
}
if ( V_2 -> V_5 . V_267 )
F_148 ( & V_19 -> V_5 ) ;
V_43 = V_19 -> V_5 . V_43 ;
if ( V_43 < sizeof( struct V_79 ) ) {
F_3 ( L_91 ) ;
goto V_287;
}
if ( V_43 > V_281 ) {
void * V_288 = realloc ( V_41 , V_43 ) ;
if ( ! V_288 ) {
F_3 ( L_92 ) ;
goto V_287;
}
V_41 = V_288 ;
V_281 = V_43 ;
V_19 = V_41 ;
}
V_104 = V_19 ;
V_104 += sizeof( struct V_79 ) ;
if ( V_43 - sizeof( struct V_79 ) ) {
V_240 = F_147 ( V_39 , V_104 , V_43 - sizeof( struct V_79 ) ) ;
if ( V_240 <= 0 ) {
if ( V_240 == 0 ) {
F_3 ( L_93 ) ;
goto V_286;
}
F_3 ( L_94 ) ;
goto V_287;
}
}
if ( ( V_282 = F_149 ( V_2 , V_19 , V_283 ) ) < 0 ) {
F_3 ( L_43 V_154 L_95 ,
V_283 , V_19 -> V_5 . V_43 , V_19 -> V_5 . type ) ;
V_240 = - V_217 ;
goto V_287;
}
V_283 += V_43 ;
if ( V_282 > 0 )
V_283 += V_282 ;
if ( ! F_167 () )
goto V_285;
V_286:
V_240 = F_106 ( V_17 , V_289 ) ;
if ( V_240 )
goto V_287;
V_240 = F_168 ( V_2 , V_22 ) ;
if ( V_240 )
goto V_287;
V_240 = F_163 ( V_2 ) ;
V_287:
free ( V_41 ) ;
F_158 ( V_2 ) ;
F_169 ( & V_2 -> V_16 ) ;
F_170 ( V_2 ) ;
return V_240 ;
}
static union V_35 *
F_171 ( struct V_1 * V_2 ,
V_78 V_283 , T_10 V_290 , char * V_41 )
{
union V_35 * V_19 ;
if ( V_283 + sizeof( V_19 -> V_5 ) > V_290 )
return NULL ;
V_19 = (union V_35 * ) ( V_41 + V_283 ) ;
if ( V_2 -> V_5 . V_267 )
F_148 ( & V_19 -> V_5 ) ;
if ( V_283 + V_19 -> V_5 . V_43 > V_290 ) {
if ( V_2 -> V_5 . V_267 )
F_148 ( & V_19 -> V_5 ) ;
return NULL ;
}
return V_19 ;
}
static int F_172 ( struct V_1 * V_2 ,
V_78 V_291 , V_78 V_292 ,
V_78 V_293 )
{
struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_25 * V_22 = V_2 -> V_22 ;
int V_39 = F_55 ( V_2 -> V_4 ) ;
V_78 V_283 , V_294 , V_23 , V_295 , V_43 ;
int V_240 , V_296 , V_297 , V_298 = 0 ;
T_10 V_290 ;
char * V_41 , * V_299 [ V_300 ] ;
union V_35 * V_19 ;
struct V_301 V_302 ;
T_5 V_282 ;
F_67 ( V_22 ) ;
V_294 = V_303 * ( V_291 / V_303 ) ;
V_23 = V_294 ;
V_283 = V_291 - V_294 ;
if ( V_292 == 0 )
goto V_26;
if ( V_291 + V_292 < V_293 )
V_293 = V_291 + V_292 ;
F_173 ( & V_302 , V_293 , L_96 ) ;
V_290 = V_304 ;
if ( V_290 > V_293 ) {
V_290 = V_293 ;
V_2 -> V_266 = true ;
}
memset ( V_299 , 0 , sizeof( V_299 ) ) ;
V_296 = V_305 ;
V_297 = V_306 ;
if ( V_2 -> V_5 . V_267 ) {
V_296 |= V_307 ;
V_297 = V_308 ;
}
V_309:
V_41 = V_44 ( NULL , V_290 , V_296 , V_297 , V_39 ,
V_23 ) ;
if ( V_41 == V_310 ) {
F_3 ( L_97 ) ;
V_240 = - V_284 ;
goto V_287;
}
V_299 [ V_298 ] = V_41 ;
V_298 = ( V_298 + 1 ) & ( F_174 ( V_299 ) - 1 ) ;
V_295 = V_23 + V_283 ;
if ( V_2 -> V_266 ) {
V_2 -> V_269 = V_41 ;
V_2 -> V_268 = V_23 ;
}
V_285:
V_19 = F_171 ( V_2 , V_283 , V_290 , V_41 ) ;
if ( ! V_19 ) {
if ( V_299 [ V_298 ] ) {
F_175 ( V_299 [ V_298 ] , V_290 ) ;
V_299 [ V_298 ] = NULL ;
}
V_294 = V_303 * ( V_283 / V_303 ) ;
V_23 += V_294 ;
V_283 -= V_294 ;
goto V_309;
}
V_43 = V_19 -> V_5 . V_43 ;
if ( V_43 < sizeof( struct V_79 ) ||
( V_282 = F_149 ( V_2 , V_19 , V_295 ) ) < 0 ) {
F_3 ( L_43 V_154 L_95 ,
V_23 + V_283 , V_19 -> V_5 . V_43 ,
V_19 -> V_5 . type ) ;
V_240 = - V_217 ;
goto V_287;
}
if ( V_282 )
V_43 += V_282 ;
V_283 += V_43 ;
V_295 += V_43 ;
F_176 ( & V_302 , V_43 ) ;
if ( F_167 () )
goto V_26;
if ( V_295 < V_293 )
goto V_285;
V_26:
V_240 = F_106 ( V_17 , V_289 ) ;
if ( V_240 )
goto V_287;
V_240 = F_168 ( V_2 , V_22 ) ;
if ( V_240 )
goto V_287;
V_240 = F_163 ( V_2 ) ;
V_287:
F_177 () ;
F_158 ( V_2 ) ;
F_178 ( & V_2 -> V_16 ) ;
F_170 ( V_2 ) ;
V_2 -> V_266 = false ;
return V_240 ;
}
int F_179 ( struct V_1 * V_2 )
{
V_78 V_43 = F_180 ( V_2 -> V_4 ) ;
int V_240 ;
if ( F_152 ( V_2 ) < 0 )
return - V_311 ;
if ( ! F_4 ( V_2 -> V_4 ) )
V_240 = F_172 ( V_2 ,
V_2 -> V_5 . V_291 ,
V_2 -> V_5 . V_292 , V_43 ) ;
else
V_240 = F_165 ( V_2 ) ;
return V_240 ;
}
bool F_181 ( struct V_1 * V_2 , const char * V_312 )
{
struct V_12 * V_13 ;
F_18 (session->evlist, evsel) {
if ( V_13 -> V_14 . type == V_313 )
return true ;
}
F_3 ( L_98 , V_312 ) ;
return false ;
}
int F_182 ( struct V_314 * * V_315 ,
const char * V_316 , V_78 V_187 )
{
char * V_317 ;
int V_105 ;
struct V_318 * V_319 ;
V_319 = F_26 ( sizeof( struct V_318 ) ) ;
if ( V_319 == NULL )
return - V_311 ;
V_319 -> V_320 = F_183 ( V_316 ) ;
if ( V_319 -> V_320 == NULL ) {
free ( V_319 ) ;
return - V_311 ;
}
V_317 = strchr ( V_319 -> V_320 , ']' ) ;
if ( V_317 )
* V_317 = '\0' ;
V_319 -> V_187 = V_187 ;
for ( V_105 = 0 ; V_105 < V_321 ; ++ V_105 ) {
struct V_322 * V_322 = F_184 ( V_315 [ V_105 ] ) ;
if ( ! V_322 )
continue;
V_322 -> V_318 = V_319 ;
}
return 0 ;
}
T_10 F_185 ( struct V_1 * V_2 , T_16 * V_323 )
{
return F_186 ( & V_2 -> V_9 , V_323 ) ;
}
T_10 F_187 ( struct V_1 * V_2 , T_16 * V_323 ,
bool (V_282)( struct V_324 * V_324 , int V_325 ) , int V_325 )
{
return F_188 ( & V_2 -> V_9 , V_323 , V_282 , V_325 ) ;
}
T_10 F_189 ( struct V_1 * V_2 , T_16 * V_323 )
{
T_10 V_10 ;
const char * V_312 = L_71 ;
if ( F_5 ( & V_2 -> V_5 , V_326 ) )
V_312 = L_99 ;
V_10 = fprintf ( V_323 , L_100 , V_312 ) ;
V_10 += F_190 ( & V_2 -> V_7 -> V_215 , V_323 ) ;
return V_10 ;
}
T_10 F_191 ( struct V_1 * V_2 , T_16 * V_323 )
{
return F_192 ( & V_2 -> V_9 . V_11 , V_323 ) ;
}
struct V_12 * F_193 ( struct V_1 * V_2 ,
unsigned int type )
{
struct V_12 * V_327 ;
F_18 (session->evlist, pos) {
if ( V_327 -> V_14 . type == type )
return V_327 ;
}
return NULL ;
}
int F_194 ( struct V_1 * V_2 ,
const char * V_328 , unsigned long * V_329 )
{
int V_105 , V_240 = - 1 ;
struct V_70 * V_314 ;
for ( V_105 = 0 ; V_105 < V_330 ; ++ V_105 ) {
struct V_12 * V_13 ;
V_13 = F_193 ( V_2 , V_105 ) ;
if ( ! V_13 )
continue;
if ( ! ( V_13 -> V_14 . V_109 & V_176 ) ) {
F_3 ( L_101
L_102 ) ;
return - 1 ;
}
}
V_314 = F_195 ( V_328 ) ;
if ( V_314 == NULL ) {
F_3 ( L_103 ) ;
return - 1 ;
}
for ( V_105 = 0 ; V_105 < V_314 -> V_129 ; V_105 ++ ) {
int V_126 = V_314 -> V_314 [ V_105 ] ;
if ( V_126 >= V_331 ) {
F_3 ( L_104
L_105 , V_126 ) ;
goto V_332;
}
F_196 ( V_126 , V_329 ) ;
}
V_240 = 0 ;
V_332:
F_197 ( V_314 ) ;
return V_240 ;
}
void F_198 ( struct V_1 * V_2 , T_16 * V_323 ,
bool V_333 )
{
if ( V_2 == NULL || V_323 == NULL )
return;
fprintf ( V_323 , L_106 ) ;
F_199 ( V_2 , V_323 , V_333 ) ;
fprintf ( V_323 , L_107 ) ;
}
int F_200 ( struct V_1 * V_2 ,
const struct V_334 * V_335 ,
T_10 V_336 )
{
struct V_12 * V_13 ;
T_10 V_105 ;
int V_240 ;
for ( V_105 = 0 ; V_105 < V_336 ; V_105 ++ ) {
V_13 = F_201 ( V_2 -> V_7 , V_335 [ V_105 ] . V_320 ) ;
if ( V_13 == NULL )
continue;
V_240 = - V_337 ;
if ( V_13 -> V_338 != NULL )
goto V_26;
V_13 -> V_338 = V_335 [ V_105 ] . V_338 ;
}
V_240 = 0 ;
V_26:
return V_240 ;
}
int F_202 ( struct V_25 * V_22 V_34 ,
union V_35 * V_19 ,
struct V_1 * V_2 )
{
struct V_36 * V_7 = V_2 -> V_7 ;
struct V_339 * V_340 = & V_19 -> V_66 ;
T_10 V_105 , V_129 , V_341 ;
V_341 = ( V_340 -> V_5 . V_43 - sizeof( struct V_339 ) ) /
sizeof( struct V_342 ) ;
V_129 = V_340 -> V_129 ;
if ( V_129 > V_341 )
return - V_217 ;
if ( V_37 )
fprintf ( stdout , L_108 , V_129 ) ;
for ( V_105 = 0 ; V_105 < V_129 ; V_105 ++ ) {
struct V_342 * V_158 = & V_340 -> V_130 [ V_105 ] ;
struct V_213 * V_214 ;
if ( V_37 ) {
fprintf ( stdout , L_109 V_153 , V_158 -> V_94 ) ;
fprintf ( stdout , L_110 V_153 , V_158 -> V_125 ) ;
fprintf ( stdout , L_111 V_343 , V_158 -> V_126 ) ;
fprintf ( stdout , L_112 V_343 L_10 , V_158 -> V_82 ) ;
}
V_214 = F_134 ( V_7 , V_158 -> V_94 ) ;
if ( ! V_214 )
return - V_344 ;
V_214 -> V_125 = V_158 -> V_125 ;
V_214 -> V_126 = V_158 -> V_126 ;
V_214 -> V_82 = V_158 -> V_82 ;
}
return 0 ;
}
int F_203 ( struct V_25 * V_22 ,
T_17 V_345 ,
struct V_36 * V_7 ,
struct V_38 * V_38 )
{
union V_35 * V_346 ;
struct V_12 * V_13 ;
T_10 V_129 = 0 , V_105 = 0 , T_9 , V_341 , V_40 ;
int V_240 ;
F_204 ( L_113 ) ;
V_341 = ( V_347 - sizeof( struct V_339 ) ) /
sizeof( struct V_342 ) ;
F_18 (evlist, evsel)
V_129 += V_13 -> V_348 ;
V_40 = V_129 > V_341 ? V_341 : V_129 ;
T_9 = sizeof( struct V_339 ) + V_40 * sizeof( struct V_342 ) ;
V_346 = F_26 ( T_9 ) ;
if ( ! V_346 )
return - V_311 ;
V_346 -> V_66 . V_5 . type = V_248 ;
V_346 -> V_66 . V_5 . V_43 = T_9 ;
V_346 -> V_66 . V_129 = V_40 ;
F_18 (evlist, evsel) {
T_12 V_349 ;
for ( V_349 = 0 ; V_349 < V_13 -> V_348 ; V_349 ++ ) {
struct V_342 * V_158 ;
struct V_213 * V_214 ;
if ( V_105 >= V_40 ) {
V_240 = V_345 ( V_22 , V_346 , NULL , V_38 ) ;
if ( V_240 )
goto V_287;
V_129 -= V_40 ;
V_105 = 0 ;
}
V_158 = & V_346 -> V_66 . V_130 [ V_105 ++ ] ;
V_158 -> V_94 = V_13 -> V_94 [ V_349 ] ;
V_214 = F_134 ( V_7 , V_158 -> V_94 ) ;
if ( ! V_214 ) {
free ( V_346 ) ;
return - V_344 ;
}
V_158 -> V_125 = V_214 -> V_125 ;
V_158 -> V_126 = V_214 -> V_126 ;
V_158 -> V_82 = V_214 -> V_82 ;
}
}
T_9 = sizeof( struct V_339 ) + V_129 * sizeof( struct V_342 ) ;
V_346 -> V_66 . V_5 . V_43 = T_9 ;
V_346 -> V_66 . V_129 = V_129 ;
V_240 = V_345 ( V_22 , V_346 , NULL , V_38 ) ;
V_287:
free ( V_346 ) ;
return V_240 ;
}
