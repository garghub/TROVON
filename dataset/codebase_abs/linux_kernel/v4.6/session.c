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
}
static void F_68 ( union V_34 * V_19 , void * V_72 )
{
void * V_73 = ( void * ) V_19 + V_19 -> V_5 . V_42 ;
int V_42 = V_73 - V_72 ;
F_69 ( V_42 % sizeof( V_74 ) ) ;
F_70 ( V_72 , V_42 ) ;
}
static void F_71 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
struct V_75 * V_76 = & V_19 -> V_5 ;
F_70 ( V_76 + 1 , V_19 -> V_5 . V_42 - sizeof( * V_76 ) ) ;
}
static void F_72 ( union V_34 * V_19 , bool T_6 )
{
V_19 -> V_45 . V_77 = F_73 ( V_19 -> V_45 . V_77 ) ;
V_19 -> V_45 . V_78 = F_73 ( V_19 -> V_45 . V_78 ) ;
if ( T_6 ) {
void * V_72 = & V_19 -> V_45 . V_45 ;
V_72 += F_74 ( strlen ( V_72 ) + 1 , sizeof( V_74 ) ) ;
F_68 ( V_19 , V_72 ) ;
}
}
static void F_75 ( union V_34 * V_19 ,
bool T_6 )
{
V_19 -> V_43 . V_77 = F_73 ( V_19 -> V_43 . V_77 ) ;
V_19 -> V_43 . V_78 = F_73 ( V_19 -> V_43 . V_78 ) ;
V_19 -> V_43 . V_79 = F_76 ( V_19 -> V_43 . V_79 ) ;
V_19 -> V_43 . V_80 = F_76 ( V_19 -> V_43 . V_80 ) ;
V_19 -> V_43 . V_81 = F_76 ( V_19 -> V_43 . V_81 ) ;
if ( T_6 ) {
void * V_72 = & V_19 -> V_43 . V_82 ;
V_72 += F_74 ( strlen ( V_72 ) + 1 , sizeof( V_74 ) ) ;
F_68 ( V_19 , V_72 ) ;
}
}
static void F_77 ( union V_34 * V_19 ,
bool T_6 )
{
V_19 -> V_44 . V_77 = F_73 ( V_19 -> V_44 . V_77 ) ;
V_19 -> V_44 . V_78 = F_73 ( V_19 -> V_44 . V_78 ) ;
V_19 -> V_44 . V_79 = F_76 ( V_19 -> V_44 . V_79 ) ;
V_19 -> V_44 . V_80 = F_76 ( V_19 -> V_44 . V_80 ) ;
V_19 -> V_44 . V_81 = F_76 ( V_19 -> V_44 . V_81 ) ;
V_19 -> V_44 . V_83 = F_73 ( V_19 -> V_44 . V_83 ) ;
V_19 -> V_44 . F_53 = F_73 ( V_19 -> V_44 . F_53 ) ;
V_19 -> V_44 . V_84 = F_76 ( V_19 -> V_44 . V_84 ) ;
if ( T_6 ) {
void * V_72 = & V_19 -> V_44 . V_82 ;
V_72 += F_74 ( strlen ( V_72 ) + 1 , sizeof( V_74 ) ) ;
F_68 ( V_19 , V_72 ) ;
}
}
static void F_78 ( union V_34 * V_19 , bool T_6 )
{
V_19 -> V_46 . V_77 = F_73 ( V_19 -> V_46 . V_77 ) ;
V_19 -> V_46 . V_78 = F_73 ( V_19 -> V_46 . V_78 ) ;
V_19 -> V_46 . V_85 = F_73 ( V_19 -> V_46 . V_85 ) ;
V_19 -> V_46 . V_86 = F_73 ( V_19 -> V_46 . V_86 ) ;
V_19 -> V_46 . time = F_76 ( V_19 -> V_46 . time ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_46 + 1 ) ;
}
static void F_79 ( union V_34 * V_19 , bool T_6 )
{
V_19 -> F_52 . V_77 = F_73 ( V_19 -> F_52 . V_77 ) ;
V_19 -> F_52 . V_78 = F_73 ( V_19 -> F_52 . V_78 ) ;
V_19 -> F_52 . V_87 = F_76 ( V_19 -> F_52 . V_87 ) ;
V_19 -> F_52 . V_88 = F_76 ( V_19 -> F_52 . V_88 ) ;
V_19 -> F_52 . V_89 = F_76 ( V_19 -> F_52 . V_89 ) ;
V_19 -> F_52 . V_90 = F_76 ( V_19 -> F_52 . V_90 ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> F_52 + 1 ) ;
}
static void F_80 ( union V_34 * V_19 , bool T_6 )
{
V_19 -> V_51 . V_91 = F_76 ( V_19 -> V_51 . V_91 ) ;
V_19 -> V_51 . V_92 = F_76 ( V_19 -> V_51 . V_92 ) ;
V_19 -> V_51 . V_93 = F_76 ( V_19 -> V_51 . V_93 ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_51 + 1 ) ;
}
static void F_81 ( union V_34 * V_19 ,
bool T_6 )
{
V_19 -> V_53 . V_77 = F_73 ( V_19 -> V_53 . V_77 ) ;
V_19 -> V_53 . V_78 = F_73 ( V_19 -> V_53 . V_78 ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_53 + 1 ) ;
}
static void F_82 ( union V_34 * V_19 , bool T_6 )
{
if ( V_19 -> V_5 . type == V_94 ) {
V_19 -> V_55 . V_95 =
F_73 ( V_19 -> V_55 . V_95 ) ;
V_19 -> V_55 . V_96 =
F_73 ( V_19 -> V_55 . V_96 ) ;
}
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_55 + 1 ) ;
}
static void F_83 ( union V_34 * V_19 ,
bool T_6 )
{
V_19 -> V_57 . time = F_76 ( V_19 -> V_57 . time ) ;
V_19 -> V_57 . V_90 = F_76 ( V_19 -> V_57 . V_90 ) ;
V_19 -> V_57 . V_97 = F_76 ( V_19 -> V_57 . V_97 ) ;
if ( T_6 )
F_68 ( V_19 , & V_19 -> V_57 + 1 ) ;
}
static T_7 F_84 ( T_7 V_98 )
{
int V_99 = ( V_98 >> 4 ) | ( ( V_98 & 0xf ) << 4 ) ;
V_99 = ( ( V_99 & 0xcc ) >> 2 ) | ( ( V_99 & 0x33 ) << 2 ) ;
V_99 = ( ( V_99 & 0xaa ) >> 1 ) | ( ( V_99 & 0x55 ) << 1 ) ;
return ( T_7 ) V_99 ;
}
static void F_85 ( T_7 * V_100 , unsigned V_80 )
{
unsigned V_101 ;
for ( V_101 = 0 ; V_101 < V_80 ; V_101 ++ ) {
* V_100 = F_84 ( * V_100 ) ;
V_100 ++ ;
}
}
void F_86 ( struct V_102 * V_14 )
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
F_90 ( V_103 ) ;
F_90 ( V_104 ) ;
F_90 ( V_105 ) ;
F_90 ( V_106 ) ;
F_89 ( V_107 ) ;
F_89 ( V_108 ) ;
F_90 ( V_109 ) ;
F_90 ( V_110 ) ;
F_90 ( V_111 ) ;
F_90 ( V_112 ) ;
F_89 ( V_113 ) ;
F_89 ( V_114 ) ;
if ( F_87 ( V_106 , 1 ) )
F_85 ( ( T_7 * ) ( & V_14 -> V_106 + 1 ) ,
sizeof( V_74 ) ) ;
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
V_42 -= ( void * ) & V_19 -> V_14 . V_90 - ( void * ) V_19 ;
F_70 ( V_19 -> V_14 . V_90 , V_42 ) ;
}
static void F_92 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_59 . type = F_76 ( V_19 -> V_59 . type ) ;
V_19 -> V_59 . V_90 = F_76 ( V_19 -> V_59 . V_90 ) ;
}
static void F_93 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_115 . V_115 . V_116 =
F_76 ( V_19 -> V_115 . V_115 . V_116 ) ;
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
V_42 -= ( void * ) & V_19 -> V_65 . V_117 - ( void * ) V_19 ;
F_70 ( V_19 -> V_65 . V_117 , V_42 ) ;
}
static void F_96 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_41 . V_42 = F_76 ( V_19 -> V_41 . V_42 ) ;
V_19 -> V_41 . V_118 = F_76 ( V_19 -> V_41 . V_118 ) ;
V_19 -> V_41 . V_119 = F_76 ( V_19 -> V_41 . V_119 ) ;
V_19 -> V_41 . V_120 = F_73 ( V_19 -> V_41 . V_120 ) ;
V_19 -> V_41 . V_78 = F_73 ( V_19 -> V_41 . V_78 ) ;
V_19 -> V_41 . V_121 = F_73 ( V_19 -> V_41 . V_121 ) ;
}
static void F_97 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_66 . type = F_73 ( V_19 -> V_66 . type ) ;
V_19 -> V_66 . V_122 = F_73 ( V_19 -> V_66 . V_122 ) ;
V_19 -> V_66 . V_121 = F_73 ( V_19 -> V_66 . V_121 ) ;
V_19 -> V_66 . V_77 = F_73 ( V_19 -> V_66 . V_77 ) ;
V_19 -> V_66 . V_78 = F_73 ( V_19 -> V_66 . V_78 ) ;
V_19 -> V_66 . V_123 = F_76 ( V_19 -> V_66 . V_123 ) ;
}
static void F_98 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
unsigned V_101 ;
V_19 -> V_67 . V_124 = F_76 ( V_19 -> V_67 . V_124 ) ;
for ( V_101 = 0 ; V_101 < V_19 -> V_67 . V_124 ; V_101 ++ )
V_19 -> V_67 . V_125 [ V_101 ] . V_77 = F_76 ( V_19 -> V_67 . V_125 [ V_101 ] . V_77 ) ;
}
static void F_99 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
struct V_126 * V_72 = & V_19 -> V_68 . V_72 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
unsigned V_101 ;
V_72 -> type = F_76 ( V_72 -> type ) ;
switch ( V_72 -> type ) {
case V_131 :
V_128 = (struct V_127 * ) V_72 -> V_72 ;
V_128 -> V_124 = F_100 ( V_128 -> V_124 ) ;
for ( V_101 = 0 ; V_101 < V_128 -> V_124 ; V_101 ++ )
V_128 -> V_121 [ V_101 ] = F_100 ( V_128 -> V_121 [ V_101 ] ) ;
break;
case V_132 :
V_130 = (struct V_129 * ) V_72 -> V_72 ;
V_130 -> V_124 = F_100 ( V_130 -> V_124 ) ;
V_130 -> V_133 = F_100 ( V_130 -> V_133 ) ;
switch ( V_130 -> V_133 ) {
case 4 : F_101 ( & V_130 -> V_130 , V_130 -> V_124 ) ; break;
case 8 : F_70 ( & V_130 -> V_130 , V_130 -> V_124 ) ; break;
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
V_74 V_42 ;
V_42 = V_19 -> V_69 . V_124 * sizeof( V_19 -> V_69 . V_72 [ 0 ] ) ;
V_42 += 1 ;
F_70 ( & V_19 -> V_69 . V_124 , V_42 ) ;
}
static void F_103 ( union V_34 * V_19 ,
bool T_6 V_33 )
{
V_19 -> V_70 . V_90 = F_76 ( V_19 -> V_70 . V_90 ) ;
V_19 -> V_70 . V_134 = F_73 ( V_19 -> V_70 . V_134 ) ;
V_19 -> V_70 . V_121 = F_73 ( V_19 -> V_70 . V_121 ) ;
V_19 -> V_70 . V_135 = F_76 ( V_19 -> V_70 . V_135 ) ;
V_19 -> V_70 . V_136 = F_76 ( V_19 -> V_70 . V_136 ) ;
V_19 -> V_70 . V_137 = F_76 ( V_19 -> V_70 . V_137 ) ;
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
return F_105 ( V_17 , V_138 ) ;
}
int F_106 ( struct V_1 * V_139 , union V_34 * V_19 ,
struct V_20 * V_21 , V_74 V_23 )
{
return F_107 ( & V_139 -> V_16 , V_19 , V_21 , V_23 ) ;
}
static void F_108 ( struct V_20 * V_21 )
{
struct V_140 * V_141 = V_21 -> V_141 ;
struct V_142 * V_143 = V_21 -> V_142 ;
V_74 V_144 = V_141 -> V_124 ;
unsigned int V_101 ;
for ( V_101 = 0 ; V_101 < V_144 ; V_101 ++ ) {
if ( V_141 -> V_145 [ V_101 ] == V_146 )
break;
}
if ( ( V_101 != V_144 ) && V_143 -> V_124 ) {
V_74 V_147 ;
V_147 = V_101 + 1 + V_143 -> V_124 + 1 ;
V_144 = V_101 + 1 ;
printf ( L_11 V_148 L_10 , V_147 ) ;
for ( V_101 = 0 ; V_101 < V_144 ; V_101 ++ )
printf ( L_12 V_149 L_10 ,
V_101 , V_141 -> V_145 [ V_101 ] ) ;
printf ( L_12 V_149 L_10 ,
( int ) ( V_144 ) , V_143 -> V_125 [ 0 ] . V_150 ) ;
for ( V_101 = 0 ; V_101 < V_143 -> V_124 ; V_101 ++ )
printf ( L_12 V_149 L_10 ,
( int ) ( V_101 + V_144 + 1 ) , V_143 -> V_125 [ V_101 ] . V_151 ) ;
}
}
static void F_109 ( struct V_12 * V_13 ,
struct V_20 * V_21 )
{
unsigned int V_101 ;
struct V_140 * V_141 = V_21 -> V_141 ;
if ( F_110 ( V_13 ) )
F_108 ( V_21 ) ;
printf ( L_13 V_148 L_10 , V_141 -> V_124 ) ;
for ( V_101 = 0 ; V_101 < V_141 -> V_124 ; V_101 ++ )
printf ( L_12 V_149 L_10 ,
V_101 , V_141 -> V_145 [ V_101 ] ) ;
}
static void F_111 ( struct V_20 * V_21 )
{
T_11 V_101 ;
printf ( L_14 V_148 L_10 , V_21 -> V_142 -> V_124 ) ;
for ( V_101 = 0 ; V_101 < V_21 -> V_142 -> V_124 ; V_101 ++ ) {
struct V_152 * V_153 = & V_21 -> V_142 -> V_125 [ V_101 ] ;
printf ( L_15 V_148 L_16 V_149 L_17 V_149 L_18 ,
V_101 , V_153 -> V_151 , V_153 -> V_150 ,
V_153 -> V_93 . V_154 ,
V_153 -> V_93 . V_155 ? L_19 : L_20 ,
V_153 -> V_93 . V_156 ? L_21 : L_20 ,
V_153 -> V_93 . abort ? L_22 : L_20 ,
V_153 -> V_93 . V_157 ? L_23 : L_20 ,
( unsigned ) V_153 -> V_93 . V_158 ) ;
}
}
static void F_112 ( V_74 V_130 , V_74 * V_159 )
{
unsigned V_160 , V_101 = 0 ;
F_113 (rid, (unsigned long *) &mask, sizeof(mask) * 8 ) {
V_74 V_135 = V_159 [ V_101 ++ ] ;
printf ( L_24 V_149 L_10 ,
F_114 ( V_160 ) , V_135 ) ;
}
}
static inline const char * F_115 ( struct V_161 * V_162 )
{
if ( V_162 -> V_163 > V_164 )
return L_25 ;
return V_165 [ V_162 -> V_163 ] ;
}
static void F_116 ( const char * type , struct V_161 * V_159 )
{
V_74 V_130 = V_159 -> V_130 ;
printf ( L_26 V_149 L_27 ,
type ,
V_130 ,
F_115 ( V_159 ) ) ;
F_112 ( V_130 , V_159 -> V_159 ) ;
}
static void F_117 ( struct V_20 * V_21 )
{
struct V_161 * V_166 = & V_21 -> V_166 ;
if ( V_166 -> V_159 )
F_116 ( L_28 , V_166 ) ;
}
static void F_118 ( struct V_20 * V_21 )
{
struct V_161 * V_167 = & V_21 -> V_167 ;
if ( V_167 -> V_159 )
F_116 ( L_29 , V_167 ) ;
}
static void F_119 ( struct V_168 * V_169 )
{
printf ( L_30 V_148 L_31 ,
V_169 -> V_42 , V_169 -> V_118 ) ;
}
static void F_120 ( struct V_35 * V_7 ,
union V_34 * V_19 ,
struct V_20 * V_21 )
{
V_74 V_105 = F_121 ( V_7 ) ;
if ( V_19 -> V_5 . type != V_170 &&
! F_34 ( V_7 ) ) {
fputs ( L_32 , stdout ) ;
return;
}
if ( ( V_105 & V_171 ) )
printf ( L_33 , V_21 -> V_121 ) ;
if ( V_105 & V_172 )
printf ( L_34 V_148 L_20 , V_21 -> time ) ;
}
static void F_122 ( struct V_20 * V_21 , V_74 V_106 )
{
printf ( L_35 ) ;
if ( V_106 & V_173 )
printf ( L_36 V_149 L_10 ,
V_21 -> F_52 . V_88 ) ;
if ( V_106 & V_174 )
printf ( L_37 V_149 L_10 ,
V_21 -> F_52 . V_89 ) ;
if ( V_106 & V_175 ) {
V_74 V_101 ;
printf ( L_38 V_148 L_10 , V_21 -> F_52 . V_176 . V_124 ) ;
for ( V_101 = 0 ; V_101 < V_21 -> F_52 . V_176 . V_124 ; V_101 ++ ) {
struct V_177 * V_87 ;
V_87 = & V_21 -> F_52 . V_176 . V_178 [ V_101 ] ;
printf ( L_39 V_149
L_40 V_149 L_10 ,
V_87 -> V_90 , V_87 -> V_87 ) ;
}
} else
printf ( L_39 V_149 L_40 V_149 L_10 ,
V_21 -> F_52 . V_179 . V_90 , V_21 -> F_52 . V_179 . V_87 ) ;
}
static void F_123 ( struct V_35 * V_7 , union V_34 * V_19 ,
V_74 V_23 , struct V_20 * V_21 )
{
if ( ! V_36 )
return;
printf ( L_41 V_149 L_42 ,
V_23 , V_19 -> V_5 . V_42 , V_19 -> V_5 . type ) ;
F_124 ( V_19 ) ;
if ( V_21 )
F_120 ( V_7 , V_19 , V_21 ) ;
printf ( L_43 V_149 L_44 , V_23 ,
V_19 -> V_5 . V_42 , F_125 ( V_19 -> V_5 . type ) ) ;
}
static void F_126 ( struct V_12 * V_13 , union V_34 * V_19 ,
struct V_20 * V_21 )
{
V_74 V_105 ;
if ( ! V_36 )
return;
printf ( L_45 V_149 L_46 V_148 L_47 V_149 L_10 ,
V_19 -> V_5 . V_180 , V_21 -> V_77 , V_21 -> V_78 , V_21 -> V_123 ,
V_21 -> V_181 , V_21 -> V_182 ) ;
V_105 = V_13 -> V_14 . V_105 ;
if ( V_105 & V_183 )
F_109 ( V_13 , V_21 ) ;
if ( ( V_105 & V_184 ) && ! F_110 ( V_13 ) )
F_111 ( V_21 ) ;
if ( V_105 & V_185 )
F_117 ( V_21 ) ;
if ( V_105 & V_186 )
F_118 ( V_21 ) ;
if ( V_105 & V_187 )
F_119 ( & V_21 -> V_188 ) ;
if ( V_105 & V_189 )
printf ( L_48 V_148 L_10 , V_21 -> V_190 ) ;
if ( V_105 & V_191 )
printf ( L_49 V_149 L_10 , V_21 -> V_192 ) ;
if ( V_105 & V_193 )
printf ( L_50 V_149 L_10 , V_21 -> V_194 ) ;
if ( V_105 & V_195 )
F_122 ( V_21 , V_13 -> V_14 . V_106 ) ;
}
static struct V_37 * F_127 ( struct V_9 * V_9 ,
union V_34 * V_19 ,
struct V_20 * V_21 )
{
struct V_37 * V_37 ;
if ( V_196 &&
( ( V_21 -> V_197 == V_198 ) ||
( V_21 -> V_197 == V_199 ) ) ) {
T_12 V_77 ;
if ( V_19 -> V_5 . type == V_200
|| V_19 -> V_5 . type == V_201 )
V_77 = V_19 -> V_43 . V_77 ;
else
V_77 = V_21 -> V_77 ;
V_37 = F_128 ( V_9 , V_77 ) ;
if ( ! V_37 )
V_37 = F_129 ( V_9 , V_202 ) ;
return V_37 ;
}
return & V_9 -> V_11 ;
}
static int F_130 ( struct V_35 * V_7 ,
struct V_25 * V_22 ,
union V_34 * V_19 ,
struct V_20 * V_21 ,
struct V_177 * V_203 ,
struct V_37 * V_37 )
{
struct V_204 * V_205 = F_131 ( V_7 , V_203 -> V_90 ) ;
if ( V_205 ) {
V_21 -> V_90 = V_203 -> V_90 ;
V_21 -> V_181 = V_203 -> V_87 - V_205 -> V_181 ;
V_205 -> V_181 = V_203 -> V_87 ;
}
if ( ! V_205 || V_205 -> V_13 == NULL ) {
++ V_7 -> V_206 . V_207 ;
return 0 ;
}
return V_22 -> V_21 ( V_22 , V_19 , V_21 , V_205 -> V_13 , V_37 ) ;
}
static int F_132 ( struct V_35 * V_7 ,
struct V_25 * V_22 ,
union V_34 * V_19 ,
struct V_20 * V_21 ,
struct V_37 * V_37 )
{
int V_10 = - V_208 ;
V_74 V_101 ;
for ( V_101 = 0 ; V_101 < V_21 -> F_52 . V_176 . V_124 ; V_101 ++ ) {
V_10 = F_130 ( V_7 , V_22 , V_19 , V_21 ,
& V_21 -> F_52 . V_176 . V_178 [ V_101 ] ,
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
V_74 V_105 = V_13 -> V_14 . V_105 ;
V_74 V_106 = V_13 -> V_14 . V_106 ;
if ( ! ( V_105 & V_195 ) )
return V_22 -> V_21 ( V_22 , V_19 , V_21 , V_13 , V_37 ) ;
if ( V_106 & V_175 )
return F_132 ( V_7 , V_22 , V_19 , V_21 ,
V_37 ) ;
else
return F_130 ( V_7 , V_22 , V_19 , V_21 ,
& V_21 -> F_52 . V_179 , V_37 ) ;
}
static int F_134 ( struct V_9 * V_9 ,
struct V_35 * V_7 ,
union V_34 * V_19 ,
struct V_20 * V_21 ,
struct V_25 * V_22 , V_74 V_23 )
{
struct V_12 * V_13 ;
struct V_37 * V_37 ;
F_123 ( V_7 , V_19 , V_23 , V_21 ) ;
V_13 = F_135 ( V_7 , V_21 -> V_90 ) ;
V_37 = F_127 ( V_9 , V_19 , V_21 ) ;
switch ( V_19 -> V_5 . type ) {
case V_170 :
if ( V_13 == NULL ) {
++ V_7 -> V_206 . V_207 ;
return 0 ;
}
F_126 ( V_13 , V_19 , V_21 ) ;
if ( V_37 == NULL ) {
++ V_7 -> V_206 . V_209 ;
return 0 ;
}
return F_133 ( V_7 , V_22 , V_19 , V_21 , V_13 , V_37 ) ;
case V_200 :
return V_22 -> V_43 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_201 :
if ( V_19 -> V_5 . V_180 & V_210 )
++ V_7 -> V_206 . V_211 ;
return V_22 -> V_44 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_212 :
return V_22 -> V_45 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_213 :
return V_22 -> V_46 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_214 :
return V_22 -> exit ( V_22 , V_19 , V_21 , V_37 ) ;
case V_215 :
if ( V_22 -> V_47 == V_48 )
V_7 -> V_206 . V_216 += V_19 -> V_47 . V_47 ;
return V_22 -> V_47 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_217 :
if ( V_22 -> V_49 == V_50 )
V_7 -> V_206 . V_218 += V_19 -> V_49 . V_47 ;
return V_22 -> V_49 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_219 :
return V_22 -> F_52 ( V_22 , V_19 , V_21 , V_13 , V_37 ) ;
case V_220 :
return V_22 -> V_57 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_221 :
return V_22 -> V_58 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_222 :
if ( V_22 -> V_51 == V_52 &&
( V_19 -> V_51 . V_93 & V_223 ) )
V_7 -> V_206 . V_224 += 1 ;
return V_22 -> V_51 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_225 :
return V_22 -> V_53 ( V_22 , V_19 , V_21 , V_37 ) ;
case V_226 :
case V_94 :
return V_22 -> V_55 ( V_22 , V_19 , V_21 , V_37 ) ;
default:
++ V_7 -> V_206 . V_227 ;
return - 1 ;
}
}
static int F_24 ( struct V_1 * V_2 ,
union V_34 * V_19 ,
struct V_20 * V_21 ,
struct V_25 * V_22 ,
V_74 V_23 )
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
V_74 V_23 )
{
struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_25 * V_22 = V_2 -> V_22 ;
int V_38 = F_55 ( V_2 -> V_4 ) ;
int V_228 ;
F_123 ( V_2 -> V_7 , V_19 , V_23 , NULL ) ;
switch ( V_19 -> V_5 . type ) {
case V_229 :
V_228 = V_22 -> V_14 ( V_22 , V_19 , & V_2 -> V_7 ) ;
if ( V_228 == 0 ) {
F_9 ( V_2 ) ;
F_19 ( V_2 ) ;
}
return V_228 ;
case V_230 :
return V_22 -> V_59 ( V_22 , V_19 , & V_2 -> V_7 ) ;
case V_231 :
return 0 ;
case V_232 :
F_138 ( V_38 , V_23 , V_233 ) ;
return V_22 -> V_60 ( V_22 , V_19 , V_2 ) ;
case V_234 :
return V_22 -> V_61 ( V_22 , V_19 , V_2 ) ;
case V_235 :
return V_22 -> V_62 ( V_22 , V_19 , V_17 ) ;
case V_236 :
return V_22 -> V_64 ( V_22 , V_19 , V_2 ) ;
case V_237 :
return V_22 -> V_65 ( V_22 , V_19 , V_2 ) ;
case V_238 :
F_138 ( V_38 , V_23 + V_19 -> V_5 . V_42 , V_233 ) ;
return V_22 -> V_41 ( V_22 , V_19 , V_2 ) ;
case V_239 :
F_139 ( V_2 , V_19 ) ;
return V_22 -> V_66 ( V_22 , V_19 , V_2 ) ;
case V_240 :
return V_22 -> V_67 ( V_22 , V_19 , V_2 ) ;
case V_241 :
return V_22 -> V_68 ( V_22 , V_19 , V_2 ) ;
case V_242 :
return V_22 -> V_69 ( V_22 , V_19 , V_2 ) ;
case V_243 :
return V_22 -> V_70 ( V_22 , V_19 , V_2 ) ;
case V_244 :
return V_22 -> V_71 ( V_22 , V_19 , V_2 ) ;
default:
return - V_208 ;
}
}
int F_140 ( struct V_1 * V_2 ,
union V_34 * V_19 ,
struct V_20 * V_21 )
{
struct V_35 * V_7 = V_2 -> V_7 ;
struct V_25 * V_22 = V_2 -> V_22 ;
F_141 ( & V_7 -> V_206 , V_19 -> V_5 . type ) ;
if ( V_19 -> V_5 . type >= V_245 )
return F_137 ( V_2 , V_19 , 0 ) ;
return F_134 ( & V_2 -> V_9 , V_7 , V_19 , V_21 , V_22 , 0 ) ;
}
static void F_142 ( union V_34 * V_19 , bool T_6 )
{
T_13 V_246 ;
V_246 = V_247 [ V_19 -> V_5 . type ] ;
if ( V_246 )
V_246 ( V_19 , T_6 ) ;
}
int F_143 ( struct V_1 * V_2 , T_3 V_23 ,
void * V_40 , T_10 V_248 ,
union V_34 * * V_249 ,
struct V_20 * V_21 )
{
union V_34 * V_19 ;
T_10 V_250 , V_251 ;
int V_38 ;
if ( V_2 -> V_252 && ! V_2 -> V_5 . V_253 ) {
V_19 = V_23 - V_2 -> V_254 +
V_2 -> V_255 ;
goto V_256;
}
if ( F_4 ( V_2 -> V_4 ) )
return - 1 ;
V_38 = F_55 ( V_2 -> V_4 ) ;
V_250 = sizeof( struct V_75 ) ;
if ( V_248 < V_250 )
return - 1 ;
if ( F_138 ( V_38 , V_23 , V_233 ) == ( T_3 ) - 1 ||
F_144 ( V_38 , V_40 , V_250 ) != ( T_4 ) V_250 )
return - 1 ;
V_19 = (union V_34 * ) V_40 ;
if ( V_2 -> V_5 . V_253 )
F_145 ( & V_19 -> V_5 ) ;
if ( V_19 -> V_5 . V_42 < V_250 || V_19 -> V_5 . V_42 > V_248 )
return - 1 ;
V_251 = V_19 -> V_5 . V_42 - V_250 ;
if ( F_144 ( V_38 , V_40 , V_251 ) != ( T_4 ) V_251 )
return - 1 ;
if ( V_2 -> V_5 . V_253 )
F_142 ( V_19 , F_34 ( V_2 -> V_7 ) ) ;
V_256:
if ( V_21 && V_19 -> V_5 . type < V_245 &&
F_23 ( V_2 -> V_7 , V_19 , V_21 ) )
return - 1 ;
* V_249 = V_19 ;
return 0 ;
}
static T_5 F_146 ( struct V_1 * V_2 ,
union V_34 * V_19 , V_74 V_23 )
{
struct V_35 * V_7 = V_2 -> V_7 ;
struct V_25 * V_22 = V_2 -> V_22 ;
struct V_20 V_21 ;
int V_10 ;
if ( V_2 -> V_5 . V_253 )
F_142 ( V_19 , F_34 ( V_7 ) ) ;
if ( V_19 -> V_5 . type >= V_257 )
return - V_208 ;
F_141 ( & V_7 -> V_206 , V_19 -> V_5 . type ) ;
if ( V_19 -> V_5 . type >= V_245 )
return F_137 ( V_2 , V_19 , V_23 ) ;
V_10 = F_23 ( V_7 , V_19 , & V_21 ) ;
if ( V_10 )
return V_10 ;
if ( V_22 -> V_16 ) {
V_10 = F_106 ( V_2 , V_19 , & V_21 , V_23 ) ;
if ( V_10 != - V_258 )
return V_10 ;
}
return F_24 ( V_2 , V_19 , & V_21 , V_22 ,
V_23 ) ;
}
void F_145 ( struct V_75 * V_76 )
{
V_76 -> type = F_73 ( V_76 -> type ) ;
V_76 -> V_180 = F_100 ( V_76 -> V_180 ) ;
V_76 -> V_42 = F_100 ( V_76 -> V_42 ) ;
}
struct V_134 * F_147 ( struct V_1 * V_2 , T_14 V_77 )
{
return F_148 ( & V_2 -> V_9 . V_11 , - 1 , V_77 ) ;
}
int F_149 ( struct V_1 * V_2 )
{
struct V_134 * V_134 ;
int V_228 = 0 ;
V_134 = F_148 ( & V_2 -> V_9 . V_11 , 0 , 0 ) ;
if ( V_134 == NULL || F_150 ( V_134 , L_51 , 0 ) ) {
F_3 ( L_52 ) ;
V_228 = - 1 ;
}
F_151 ( V_134 ) ;
return V_228 ;
}
static void F_152 ( const struct V_1 * V_2 )
{
const struct V_259 * V_206 = & V_2 -> V_7 -> V_206 ;
const struct V_16 * V_17 = & V_2 -> V_16 ;
if ( V_2 -> V_22 -> V_47 == V_48 &&
V_206 -> V_260 [ V_215 ] != 0 ) {
F_153 ( L_53
L_54 ,
V_206 -> V_260 [ 0 ] ,
V_206 -> V_260 [ V_215 ] ) ;
}
if ( V_2 -> V_22 -> V_49 == V_50 ) {
double V_261 ;
V_261 = ( double ) V_206 -> V_218 /
( double ) ( V_206 -> V_260 [ V_170 ] + V_206 -> V_218 ) ;
if ( V_261 > 0.05 ) {
F_153 ( L_55 V_148 L_56 ,
V_206 -> V_260 [ V_170 ] + V_206 -> V_218 ,
V_261 * 100.0 ) ;
}
}
if ( V_2 -> V_22 -> V_51 == V_52 &&
V_206 -> V_224 != 0 ) {
F_153 ( L_57 V_148 L_58 ,
V_206 -> V_224 ,
V_206 -> V_260 [ V_222 ] ) ;
}
if ( V_206 -> V_227 != 0 ) {
F_153 ( L_59
L_60
L_61
L_62
L_63 ,
V_206 -> V_227 ) ;
}
if ( V_206 -> V_207 != 0 ) {
F_153 ( L_64 ,
V_206 -> V_207 ) ;
}
if ( V_206 -> V_262 != 0 ) {
F_153 ( L_65
L_66
L_67 ,
V_206 -> V_262 ,
V_206 -> V_260 [ V_170 ] ) ;
}
if ( V_206 -> V_209 != 0 ) {
F_153 ( L_68
L_69 ,
V_206 -> V_209 ) ;
}
if ( V_17 -> V_263 != 0 )
F_153 ( L_70 , V_17 -> V_263 ) ;
F_154 ( V_206 ) ;
if ( V_206 -> V_211 != 0 ) {
F_153 ( L_71
L_72
L_73
L_74
L_75
L_76
L_77 ,
V_206 -> V_211 ) ;
}
}
static int F_155 ( struct V_134 * V_134 ,
void * V_100 V_33 )
{
return F_156 ( V_134 ) ;
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
T_15 V_42 , V_264 = 0 ;
void * V_40 = NULL ;
T_5 V_265 = 0 ;
V_74 V_266 ;
T_4 V_228 ;
void * V_100 ;
F_67 ( V_22 ) ;
V_266 = 0 ;
V_264 = sizeof( union V_34 ) ;
V_40 = malloc ( V_264 ) ;
if ( ! V_40 )
return - V_267 ;
V_268:
V_19 = V_40 ;
V_228 = F_144 ( V_38 , V_19 , sizeof( struct V_75 ) ) ;
if ( V_228 <= 0 ) {
if ( V_228 == 0 )
goto V_269;
F_3 ( L_78 ) ;
goto V_270;
}
if ( V_2 -> V_5 . V_253 )
F_145 ( & V_19 -> V_5 ) ;
V_42 = V_19 -> V_5 . V_42 ;
if ( V_42 < sizeof( struct V_75 ) ) {
F_3 ( L_79 ) ;
goto V_270;
}
if ( V_42 > V_264 ) {
void * V_271 = realloc ( V_40 , V_42 ) ;
if ( ! V_271 ) {
F_3 ( L_80 ) ;
goto V_270;
}
V_40 = V_271 ;
V_264 = V_42 ;
V_19 = V_40 ;
}
V_100 = V_19 ;
V_100 += sizeof( struct V_75 ) ;
if ( V_42 - sizeof( struct V_75 ) ) {
V_228 = F_144 ( V_38 , V_100 , V_42 - sizeof( struct V_75 ) ) ;
if ( V_228 <= 0 ) {
if ( V_228 == 0 ) {
F_3 ( L_81 ) ;
goto V_269;
}
F_3 ( L_82 ) ;
goto V_270;
}
}
if ( ( V_265 = F_146 ( V_2 , V_19 , V_266 ) ) < 0 ) {
F_3 ( L_43 V_149 L_83 ,
V_266 , V_19 -> V_5 . V_42 , V_19 -> V_5 . type ) ;
V_228 = - V_208 ;
goto V_270;
}
V_266 += V_42 ;
if ( V_265 > 0 )
V_266 += V_265 ;
if ( ! F_160 () )
goto V_268;
V_269:
V_228 = F_105 ( V_17 , V_272 ) ;
if ( V_228 )
goto V_270;
V_228 = F_161 ( V_2 , V_22 ) ;
if ( V_228 )
goto V_270;
V_228 = F_157 ( V_2 ) ;
V_270:
free ( V_40 ) ;
F_152 ( V_2 ) ;
F_162 ( & V_2 -> V_16 ) ;
F_163 ( V_2 ) ;
return V_228 ;
}
static union V_34 *
F_164 ( struct V_1 * V_2 ,
V_74 V_266 , T_10 V_273 , char * V_40 )
{
union V_34 * V_19 ;
if ( V_266 + sizeof( V_19 -> V_5 ) > V_273 )
return NULL ;
V_19 = (union V_34 * ) ( V_40 + V_266 ) ;
if ( V_2 -> V_5 . V_253 )
F_145 ( & V_19 -> V_5 ) ;
if ( V_266 + V_19 -> V_5 . V_42 > V_273 ) {
if ( V_2 -> V_5 . V_253 )
F_145 ( & V_19 -> V_5 ) ;
return NULL ;
}
return V_19 ;
}
static int F_165 ( struct V_1 * V_2 ,
V_74 V_274 , V_74 V_275 ,
V_74 V_276 )
{
struct V_16 * V_17 = & V_2 -> V_16 ;
struct V_25 * V_22 = V_2 -> V_22 ;
int V_38 = F_55 ( V_2 -> V_4 ) ;
V_74 V_266 , V_277 , V_23 , V_278 , V_42 ;
int V_228 , V_279 , V_280 , V_281 = 0 ;
T_10 V_273 ;
char * V_40 , * V_282 [ V_283 ] ;
union V_34 * V_19 ;
struct V_284 V_285 ;
T_5 V_265 ;
F_67 ( V_22 ) ;
V_277 = V_286 * ( V_274 / V_286 ) ;
V_23 = V_277 ;
V_266 = V_274 - V_277 ;
if ( V_275 == 0 )
goto V_26;
if ( V_274 + V_275 < V_276 )
V_276 = V_274 + V_275 ;
F_166 ( & V_285 , V_276 , L_84 ) ;
V_273 = V_287 ;
if ( V_273 > V_276 ) {
V_273 = V_276 ;
V_2 -> V_252 = true ;
}
memset ( V_282 , 0 , sizeof( V_282 ) ) ;
V_279 = V_288 ;
V_280 = V_289 ;
if ( V_2 -> V_5 . V_253 ) {
V_279 |= V_290 ;
V_280 = V_291 ;
}
V_292:
V_40 = V_43 ( NULL , V_273 , V_279 , V_280 , V_38 ,
V_23 ) ;
if ( V_40 == V_293 ) {
F_3 ( L_85 ) ;
V_228 = - V_267 ;
goto V_270;
}
V_282 [ V_281 ] = V_40 ;
V_281 = ( V_281 + 1 ) & ( F_167 ( V_282 ) - 1 ) ;
V_278 = V_23 + V_266 ;
if ( V_2 -> V_252 ) {
V_2 -> V_255 = V_40 ;
V_2 -> V_254 = V_23 ;
}
V_268:
V_19 = F_164 ( V_2 , V_266 , V_273 , V_40 ) ;
if ( ! V_19 ) {
if ( V_282 [ V_281 ] ) {
F_168 ( V_282 [ V_281 ] , V_273 ) ;
V_282 [ V_281 ] = NULL ;
}
V_277 = V_286 * ( V_266 / V_286 ) ;
V_23 += V_277 ;
V_266 -= V_277 ;
goto V_292;
}
V_42 = V_19 -> V_5 . V_42 ;
if ( V_42 < sizeof( struct V_75 ) ||
( V_265 = F_146 ( V_2 , V_19 , V_278 ) ) < 0 ) {
F_3 ( L_43 V_149 L_83 ,
V_23 + V_266 , V_19 -> V_5 . V_42 ,
V_19 -> V_5 . type ) ;
V_228 = - V_208 ;
goto V_270;
}
if ( V_265 )
V_42 += V_265 ;
V_266 += V_42 ;
V_278 += V_42 ;
F_169 ( & V_285 , V_42 ) ;
if ( F_160 () )
goto V_26;
if ( V_278 < V_276 )
goto V_268;
V_26:
V_228 = F_105 ( V_17 , V_272 ) ;
if ( V_228 )
goto V_270;
V_228 = F_161 ( V_2 , V_22 ) ;
if ( V_228 )
goto V_270;
V_228 = F_157 ( V_2 ) ;
V_270:
F_170 () ;
F_152 ( V_2 ) ;
F_162 ( & V_2 -> V_16 ) ;
F_163 ( V_2 ) ;
V_2 -> V_252 = false ;
return V_228 ;
}
int F_171 ( struct V_1 * V_2 )
{
V_74 V_42 = F_172 ( V_2 -> V_4 ) ;
int V_228 ;
if ( F_149 ( V_2 ) < 0 )
return - V_294 ;
if ( ! F_4 ( V_2 -> V_4 ) )
V_228 = F_165 ( V_2 ,
V_2 -> V_5 . V_274 ,
V_2 -> V_5 . V_275 , V_42 ) ;
else
V_228 = F_159 ( V_2 ) ;
return V_228 ;
}
bool F_173 ( struct V_1 * V_2 , const char * V_295 )
{
struct V_12 * V_13 ;
F_18 (session->evlist, evsel) {
if ( V_13 -> V_14 . type == V_296 )
return true ;
}
F_3 ( L_86 , V_295 ) ;
return false ;
}
int F_174 ( struct V_297 * * V_298 ,
const char * V_299 , V_74 V_182 )
{
char * V_300 ;
enum V_301 V_101 ;
struct V_302 * V_303 ;
V_303 = F_26 ( sizeof( struct V_302 ) ) ;
if ( V_303 == NULL )
return - V_294 ;
V_303 -> V_304 = F_175 ( V_299 ) ;
if ( V_303 -> V_304 == NULL ) {
free ( V_303 ) ;
return - V_294 ;
}
V_300 = strchr ( V_303 -> V_304 , ']' ) ;
if ( V_300 )
* V_300 = '\0' ;
V_303 -> V_182 = V_182 ;
for ( V_101 = 0 ; V_101 < V_305 ; ++ V_101 ) {
struct V_306 * V_306 = F_176 ( V_298 [ V_101 ] ) ;
if ( ! V_306 )
continue;
V_306 -> V_302 = V_303 ;
}
return 0 ;
}
T_10 F_177 ( struct V_1 * V_2 , T_16 * V_307 )
{
return F_178 ( & V_2 -> V_9 , V_307 ) ;
}
T_10 F_179 ( struct V_1 * V_2 , T_16 * V_307 ,
bool (V_265)( struct V_308 * V_308 , int V_309 ) , int V_309 )
{
return F_180 ( & V_2 -> V_9 , V_307 , V_265 , V_309 ) ;
}
T_10 F_181 ( struct V_1 * V_2 , T_16 * V_307 )
{
T_10 V_10 ;
const char * V_295 = L_87 ;
if ( F_5 ( & V_2 -> V_5 , V_310 ) )
V_295 = L_88 ;
V_10 = fprintf ( V_307 , L_89 , V_295 ) ;
V_10 += F_182 ( & V_2 -> V_7 -> V_206 , V_307 ) ;
return V_10 ;
}
T_10 F_183 ( struct V_1 * V_2 , T_16 * V_307 )
{
return F_184 ( & V_2 -> V_9 . V_11 , V_307 ) ;
}
struct V_12 * F_185 ( struct V_1 * V_2 ,
unsigned int type )
{
struct V_12 * V_311 ;
F_18 (session->evlist, pos) {
if ( V_311 -> V_14 . type == type )
return V_311 ;
}
return NULL ;
}
void F_186 ( struct V_12 * V_13 , struct V_20 * V_21 ,
struct V_312 * V_313 ,
unsigned int V_314 , unsigned int V_315 )
{
struct V_316 * V_317 ;
int V_318 = V_314 & V_319 ;
int V_320 = V_314 & V_321 ;
int V_322 = V_314 & V_323 ;
int V_324 = V_314 & V_325 ;
int V_326 = V_314 & V_327 ;
int V_328 = V_314 & V_329 ;
char V_139 = V_326 ? ' ' : '\t' ;
if ( V_330 . V_331 && V_21 -> V_141 ) {
struct V_312 V_332 ;
if ( F_187 ( V_313 -> V_134 , V_13 ,
V_21 , NULL , NULL ,
V_315 ) != 0 ) {
if ( V_333 )
error ( L_90 ) ;
return;
}
F_188 ( & V_334 ) ;
if ( V_324 )
V_332 = * V_313 ;
while ( V_315 ) {
V_74 V_182 = 0 ;
V_317 = F_189 ( & V_334 ) ;
if ( ! V_317 )
break;
if ( V_317 -> V_335 && V_317 -> V_335 -> V_336 )
goto V_337;
if ( V_318 )
printf ( L_91 V_149 , V_139 , V_317 -> V_123 ) ;
if ( V_317 -> V_297 )
V_182 = V_317 -> V_297 -> V_338 ( V_317 -> V_297 , V_317 -> V_123 ) ;
if ( V_320 ) {
printf ( L_20 ) ;
if ( V_324 ) {
V_332 . V_182 = V_182 ;
V_332 . V_297 = V_317 -> V_297 ;
F_190 ( V_317 -> V_335 , & V_332 , stdout ) ;
} else
F_191 ( V_317 -> V_335 , stdout ) ;
}
if ( V_322 ) {
printf ( L_92 ) ;
F_192 ( V_317 -> V_297 , stdout ) ;
printf ( L_93 ) ;
}
if ( V_328 )
F_193 ( V_317 -> V_297 , V_182 , L_94 ,
stdout ) ;
if ( ! V_326 )
printf ( L_10 ) ;
V_315 -- ;
V_337:
F_194 ( & V_334 ) ;
}
} else {
if ( V_313 -> V_335 && V_313 -> V_335 -> V_336 )
return;
if ( V_318 )
printf ( L_95 V_149 , V_21 -> V_123 ) ;
if ( V_320 ) {
printf ( L_20 ) ;
if ( V_324 )
F_190 ( V_313 -> V_335 , V_313 ,
stdout ) ;
else
F_191 ( V_313 -> V_335 , stdout ) ;
}
if ( V_322 ) {
printf ( L_92 ) ;
F_192 ( V_313 -> V_297 , stdout ) ;
printf ( L_93 ) ;
}
if ( V_328 )
F_193 ( V_313 -> V_297 , V_313 -> V_182 , L_94 , stdout ) ;
}
}
int F_195 ( struct V_1 * V_2 ,
const char * V_339 , unsigned long * V_340 )
{
int V_101 , V_228 = - 1 ;
struct V_68 * V_297 ;
for ( V_101 = 0 ; V_101 < V_341 ; ++ V_101 ) {
struct V_12 * V_13 ;
V_13 = F_185 ( V_2 , V_101 ) ;
if ( ! V_13 )
continue;
if ( ! ( V_13 -> V_14 . V_105 & V_171 ) ) {
F_3 ( L_96
L_97 ) ;
return - 1 ;
}
}
V_297 = F_196 ( V_339 ) ;
if ( V_297 == NULL ) {
F_3 ( L_98 ) ;
return - 1 ;
}
for ( V_101 = 0 ; V_101 < V_297 -> V_124 ; V_101 ++ ) {
int V_121 = V_297 -> V_297 [ V_101 ] ;
if ( V_121 >= V_342 ) {
F_3 ( L_99
L_100 , V_121 ) ;
goto V_343;
}
F_197 ( V_121 , V_340 ) ;
}
V_228 = 0 ;
V_343:
F_198 ( V_297 ) ;
return V_228 ;
}
void F_199 ( struct V_1 * V_2 , T_16 * V_307 ,
bool V_344 )
{
struct V_70 V_345 ;
int V_38 , V_10 ;
if ( V_2 == NULL || V_307 == NULL )
return;
V_38 = F_55 ( V_2 -> V_4 ) ;
V_10 = F_200 ( V_38 , & V_345 ) ;
if ( V_10 == - 1 )
return;
fprintf ( V_307 , L_101 ) ;
fprintf ( V_307 , L_102 , ctime ( & V_345 . V_346 ) ) ;
F_201 ( V_2 , V_307 , V_344 ) ;
fprintf ( V_307 , L_103 ) ;
}
int F_202 ( struct V_1 * V_2 ,
const struct V_347 * V_348 ,
T_10 V_349 )
{
struct V_12 * V_13 ;
T_10 V_101 ;
int V_228 ;
for ( V_101 = 0 ; V_101 < V_349 ; V_101 ++ ) {
V_13 = F_203 ( V_2 -> V_7 , V_348 [ V_101 ] . V_304 ) ;
if ( V_13 == NULL )
continue;
V_228 = - V_350 ;
if ( V_13 -> V_351 != NULL )
goto V_26;
V_13 -> V_351 = V_348 [ V_101 ] . V_351 ;
}
V_228 = 0 ;
V_26:
return V_228 ;
}
int F_204 ( struct V_25 * V_22 V_33 ,
union V_34 * V_19 ,
struct V_1 * V_2 )
{
struct V_35 * V_7 = V_2 -> V_7 ;
struct V_352 * V_353 = & V_19 -> V_64 ;
T_10 V_101 , V_124 , V_354 ;
V_354 = ( V_353 -> V_5 . V_42 - sizeof( struct V_352 ) ) /
sizeof( struct V_355 ) ;
V_124 = V_353 -> V_124 ;
if ( V_124 > V_354 )
return - V_208 ;
if ( V_36 )
fprintf ( stdout , L_104 , V_124 ) ;
for ( V_101 = 0 ; V_101 < V_124 ; V_101 ++ ) {
struct V_355 * V_153 = & V_353 -> V_125 [ V_101 ] ;
struct V_204 * V_205 ;
if ( V_36 ) {
fprintf ( stdout , L_105 V_148 , V_153 -> V_90 ) ;
fprintf ( stdout , L_106 V_148 , V_153 -> V_120 ) ;
fprintf ( stdout , L_107 V_356 , V_153 -> V_121 ) ;
fprintf ( stdout , L_108 V_356 L_10 , V_153 -> V_78 ) ;
}
V_205 = F_131 ( V_7 , V_153 -> V_90 ) ;
if ( ! V_205 )
return - V_357 ;
V_205 -> V_120 = V_153 -> V_120 ;
V_205 -> V_121 = V_153 -> V_121 ;
V_205 -> V_78 = V_153 -> V_78 ;
}
return 0 ;
}
int F_205 ( struct V_25 * V_22 ,
T_17 V_358 ,
struct V_35 * V_7 ,
struct V_37 * V_37 )
{
union V_34 * V_359 ;
struct V_12 * V_13 ;
T_10 V_124 = 0 , V_101 = 0 , T_9 , V_354 , V_39 ;
int V_228 ;
F_206 ( L_109 ) ;
V_354 = ( V_360 - sizeof( struct V_352 ) ) /
sizeof( struct V_355 ) ;
F_18 (evlist, evsel)
V_124 += V_13 -> V_361 ;
V_39 = V_124 > V_354 ? V_354 : V_124 ;
T_9 = sizeof( struct V_352 ) + V_39 * sizeof( struct V_355 ) ;
V_359 = F_26 ( T_9 ) ;
if ( ! V_359 )
return - V_294 ;
V_359 -> V_64 . V_5 . type = V_236 ;
V_359 -> V_64 . V_5 . V_42 = T_9 ;
V_359 -> V_64 . V_124 = V_39 ;
F_18 (evlist, evsel) {
T_12 V_362 ;
for ( V_362 = 0 ; V_362 < V_13 -> V_361 ; V_362 ++ ) {
struct V_355 * V_153 ;
struct V_204 * V_205 ;
if ( V_101 >= V_39 ) {
V_228 = V_358 ( V_22 , V_359 , NULL , V_37 ) ;
if ( V_228 )
goto V_270;
V_124 -= V_39 ;
V_101 = 0 ;
}
V_153 = & V_359 -> V_64 . V_125 [ V_101 ++ ] ;
V_153 -> V_90 = V_13 -> V_90 [ V_362 ] ;
V_205 = F_131 ( V_7 , V_153 -> V_90 ) ;
if ( ! V_205 ) {
free ( V_359 ) ;
return - V_357 ;
}
V_153 -> V_120 = V_205 -> V_120 ;
V_153 -> V_121 = V_205 -> V_121 ;
V_153 -> V_78 = V_205 -> V_78 ;
}
}
T_9 = sizeof( struct V_352 ) + V_124 * sizeof( struct V_355 ) ;
V_359 -> V_64 . V_5 . V_42 = T_9 ;
V_359 -> V_64 . V_124 = V_124 ;
V_228 = V_358 ( V_22 , V_359 , NULL , V_37 ) ;
V_270:
free ( V_359 ) ;
return V_228 ;
}
