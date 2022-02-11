static int F_1 ( struct V_1 * type ,
struct V_2 * V_3 ,
const char * V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
bool V_8 = F_2 ( type ) ;
int V_9 ;
V_7 = F_3 ( type ) ;
if ( ! V_7 ) {
F_4 ( L_1 , V_4 ) ;
return - 1 ;
}
if ( V_8 ) {
V_9 = F_5 ( V_7 , V_5 ) ;
if ( V_9 ) {
F_4 ( L_2 , V_4 ) ;
goto V_10;
}
} else {
V_9 = F_6 ( V_7 , V_5 ) ;
if ( V_9 ) {
F_4 ( L_2 , V_4 ) ;
goto V_10;
}
}
V_9 = F_7 ( V_3 , V_4 , V_7 ) ;
if ( V_9 ) {
F_4 ( L_3 , V_4 ) ;
goto V_10;
}
F_8 ( L_4 V_11 L_5 , V_4 , V_5 ) ;
V_10:
F_9 ( V_7 ) ;
return V_9 ;
}
static struct V_1 *
F_10 ( struct V_12 * V_13 , struct V_14 * V_7 )
{
unsigned long V_15 = V_7 -> V_15 ;
if ( V_15 & V_16 )
return V_13 -> V_17 . string ;
if ( ! ( V_15 & V_18 ) ) {
if ( V_15 & V_19 || V_15 & V_20 )
return V_13 -> V_17 . V_21 ;
}
if ( V_15 & V_18 ) {
if ( V_7 -> V_22 == 8 )
return V_13 -> V_17 . V_23 ;
else
return V_13 -> V_17 . V_24 ;
}
if ( V_7 -> V_22 == 8 )
return V_13 -> V_17 . T_1 ;
else
return V_13 -> V_17 . V_25 ;
}
static unsigned long long F_11 ( unsigned long long V_26 , int V_22 )
{
unsigned long long V_27 ;
switch ( V_22 ) {
case 1 :
V_27 = 0x7fULL ;
break;
case 2 :
V_27 = 0x7fffULL ;
break;
case 4 :
V_27 = 0x7fffffffULL ;
break;
case 8 :
default:
return V_26 ;
}
if ( ( V_26 & ( ~ 0ULL - V_27 ) ) == 0 )
return V_26 ;
return ( V_26 & V_27 ) | ~ V_27 ;
}
static int F_12 ( struct V_12 * V_13 ,
struct V_28 * V_29 ,
struct V_2 * V_3 ,
struct V_30 * V_31 ,
struct V_14 * V_32 )
{
struct V_1 * type ;
struct V_6 * V_33 ;
struct V_6 * V_7 ;
const char * V_4 = V_32 -> V_4 ;
void * V_17 = V_31 -> V_34 ;
unsigned long V_15 = V_32 -> V_15 ;
unsigned int V_35 ;
unsigned int V_36 ;
unsigned int V_37 ;
unsigned int V_38 ;
int V_9 ;
V_4 = V_32 -> V_39 ;
V_37 = V_32 -> V_37 ;
V_38 = V_32 -> V_22 ;
if ( V_15 & V_16 )
V_15 &= ~ V_40 ;
if ( V_15 & V_41 ) {
unsigned long long V_42 ;
V_42 = F_13 ( V_32 -> V_3 -> V_43 ,
V_17 + V_37 , V_38 ) ;
V_37 = V_42 ;
V_38 = V_37 >> 16 ;
V_37 &= 0xffff ;
}
if ( V_15 & V_40 ) {
type = F_14 (
V_29 , V_4 ) ;
V_33 = F_3 ( type ) ;
F_15 ( type ) ;
if ( ! V_33 ) {
F_4 ( L_6 , V_4 ) ;
return - 1 ;
}
V_38 = V_32 -> V_22 / V_32 -> V_44 ;
V_35 = V_32 -> V_44 ;
} else {
V_35 = 1 ;
V_33 = NULL ;
}
type = F_10 ( V_13 , V_32 ) ;
for ( V_36 = 0 ; V_36 < V_35 ; V_36 ++ ) {
if ( V_15 & V_40 )
V_7 = F_16 ( V_33 , V_36 ) ;
else
V_7 = F_3 ( type ) ;
if ( ! V_7 ) {
F_4 ( L_1 , V_4 ) ;
return - 1 ;
}
if ( V_15 & V_16 )
V_9 = F_17 ( V_7 ,
V_17 + V_37 + V_36 * V_38 ) ;
else {
unsigned long long V_26 ;
V_26 = F_13 (
V_32 -> V_3 -> V_43 ,
V_17 + V_37 + V_36 * V_38 , V_38 ) ;
if ( ! ( V_15 & V_18 ) )
V_9 = F_6 (
V_7 , V_26 ) ;
else
V_9 = F_5 (
V_7 , F_11 ( V_26 , V_38 ) ) ;
}
if ( V_9 ) {
F_4 ( L_7 , V_4 ) ;
goto V_45;
}
if ( ! ( V_15 & V_40 ) ) {
V_9 = F_7 ( V_3 , V_4 , V_7 ) ;
if ( V_9 ) {
F_4 ( L_3 , V_4 ) ;
goto V_45;
}
}
F_9 ( V_7 ) ;
}
if ( V_15 & V_40 ) {
V_9 = F_7 ( V_3 , V_4 , V_33 ) ;
if ( V_9 ) {
F_4 ( L_8 , V_4 ) ;
return - 1 ;
}
F_9 ( V_33 ) ;
}
return 0 ;
V_45:
F_9 ( V_7 ) ;
return - 1 ;
}
static int F_18 ( struct V_12 * V_13 ,
struct V_28 * V_29 ,
struct V_2 * V_3 ,
struct V_14 * V_46 ,
struct V_30 * V_31 )
{
struct V_14 * V_7 ;
int V_9 ;
for ( V_7 = V_46 ; V_7 ; V_7 = V_7 -> V_47 ) {
V_9 = F_12 ( V_13 , V_29 , V_3 , V_31 ,
V_7 ) ;
if ( V_9 )
return - 1 ;
}
return 0 ;
}
static int F_19 ( struct V_12 * V_13 ,
struct V_28 * V_29 ,
struct V_2 * V_3 ,
struct V_48 * V_49 ,
struct V_30 * V_31 )
{
struct V_14 * V_50 = V_49 -> V_51 -> V_52 . V_50 ;
struct V_14 * V_46 = V_49 -> V_51 -> V_52 . V_46 ;
int V_9 ;
V_9 = F_18 ( V_13 , V_29 , V_3 ,
V_50 , V_31 ) ;
if ( ! V_9 )
V_9 = F_18 ( V_13 , V_29 , V_3 ,
V_46 , V_31 ) ;
return V_9 ;
}
static int F_20 ( struct V_12 * V_13 ,
struct V_2 * V_3 ,
struct V_48 * V_49 ,
struct V_30 * V_31 )
{
T_1 type = V_49 -> V_53 . V_54 ;
int V_9 ;
if ( type & V_55 ) {
V_9 = F_21 ( V_13 , V_3 , L_9 , V_31 -> V_56 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_57 ) {
V_9 = F_22 ( V_13 , V_3 , L_10 , V_31 -> V_58 ) ;
if ( V_9 )
return - 1 ;
V_9 = F_22 ( V_13 , V_3 , L_11 , V_31 -> V_59 ) ;
if ( V_9 )
return - 1 ;
}
if ( ( type & V_60 ) ||
( type & V_61 ) ) {
V_9 = F_23 ( V_13 , V_3 , L_12 , V_31 -> V_62 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_63 ) {
V_9 = F_23 ( V_13 , V_3 , L_13 , V_31 -> V_64 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_65 ) {
V_9 = F_23 ( V_13 , V_3 , L_14 , V_31 -> V_66 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_67 ) {
V_9 = F_23 ( V_13 , V_3 , L_15 , V_31 -> V_68 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_69 ) {
V_9 = F_23 ( V_13 , V_3 , L_16 ,
V_31 -> V_70 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_71 ) {
V_9 = F_23 ( V_13 , V_3 , L_17 ,
V_31 -> V_72 ) ;
if ( V_9 )
return - 1 ;
}
return 0 ;
}
static int F_24 ( struct V_73 * V_74 )
{
int V_10 = 0 ;
if ( V_74 ) {
V_10 = F_25 ( V_74 -> V_75 ) ;
if ( V_10 )
F_4 ( L_18 , V_74 -> V_76 ) ;
F_26 ( L_19 ,
V_74 -> V_76 , V_74 -> V_77 ) ;
V_74 -> V_77 = 0 ;
}
return V_10 ;
}
static struct V_73 * F_27 ( struct V_12 * V_13 , int V_76 )
{
struct V_73 * V_74 ;
struct V_6 * V_78 = NULL ;
struct V_6 * V_79 = NULL ;
struct V_80 * V_75 = NULL ;
int V_9 ;
V_74 = F_28 ( sizeof( * V_74 ) ) ;
if ( ! V_74 ) {
F_4 ( L_20 ) ;
return NULL ;
}
V_75 = F_29 ( V_13 -> V_81 , V_13 -> V_82 ) ;
if ( ! V_75 ) {
F_4 ( L_21 ) ;
goto V_83;
}
V_78 = F_30 ( V_75 ) ;
if ( ! V_78 ) {
F_4 ( L_22 ) ;
goto V_83;
}
V_79 = F_31 ( V_78 , L_23 ) ;
F_9 ( V_78 ) ;
if ( ! V_79 ) {
F_4 ( L_24 ) ;
goto V_83;
}
V_9 = F_6 ( V_79 , ( V_25 ) V_76 ) ;
if ( V_9 ) {
F_4 ( L_25 ) ;
goto V_83;
}
F_9 ( V_79 ) ;
V_74 -> V_76 = V_76 ;
V_74 -> V_75 = V_75 ;
return V_74 ;
V_83:
if ( V_79 )
F_9 ( V_79 ) ;
if ( V_75 )
F_32 ( V_75 ) ;
free ( V_74 ) ;
return NULL ;
}
static void F_33 ( struct V_73 * V_74 )
{
if ( V_74 ) {
F_32 ( V_74 -> V_75 ) ;
free ( V_74 ) ;
}
}
static struct V_73 * V_73 ( struct V_12 * V_13 , int V_76 )
{
struct V_73 * V_74 = V_13 -> V_75 [ V_76 ] ;
if ( ! V_74 ) {
V_74 = F_27 ( V_13 , V_76 ) ;
V_13 -> V_75 [ V_76 ] = V_74 ;
}
return V_74 ;
}
static int F_34 ( struct V_12 * V_13 , struct V_30 * V_31 ,
struct V_48 * V_49 )
{
int V_76 = 0 ;
if ( V_49 -> V_53 . V_54 & V_84 )
V_76 = V_31 -> V_76 ;
if ( V_76 > V_13 -> V_85 ) {
F_4 ( L_26 ,
V_76 , V_13 -> V_85 ) ;
V_76 = 0 ;
}
return V_76 ;
}
static bool F_35 ( struct V_73 * V_74 )
{
return V_74 -> V_77 >= V_86 ;
}
static int F_36 ( struct V_87 * V_88 ,
union V_89 * T_2 V_90 ,
struct V_30 * V_31 ,
struct V_48 * V_49 ,
struct V_91 * V_91 V_90 )
{
struct V_92 * V_93 = F_37 ( V_88 , struct V_92 , V_88 ) ;
struct V_94 * V_95 = V_49 -> V_95 ;
struct V_12 * V_13 = & V_93 -> V_81 ;
struct V_73 * V_74 ;
struct V_28 * V_29 ;
struct V_2 * V_3 ;
int V_9 ;
if ( F_38 ( ! V_95 , L_27 ) )
return 0 ;
V_29 = V_95 -> V_29 ;
V_93 -> V_96 ++ ;
V_93 -> V_97 += T_2 -> V_98 . V_22 ;
F_39 ( V_31 -> time , L_28 V_11 L_29 , V_93 -> V_96 ) ;
V_3 = F_40 ( V_29 ) ;
if ( ! V_3 ) {
F_4 ( L_30 ) ;
return - 1 ;
}
F_41 ( V_13 -> clock , V_31 -> time ) ;
V_9 = F_20 ( V_13 , V_3 , V_49 , V_31 ) ;
if ( V_9 )
return - 1 ;
if ( V_49 -> V_53 . type == V_99 ) {
V_9 = F_19 ( V_13 , V_29 , V_3 ,
V_49 , V_31 ) ;
if ( V_9 )
return - 1 ;
}
V_74 = V_73 ( V_13 , F_34 ( V_13 , V_31 , V_49 ) ) ;
if ( V_74 ) {
if ( F_35 ( V_74 ) )
F_24 ( V_74 ) ;
V_74 -> V_77 ++ ;
F_42 ( V_74 -> V_75 , V_3 ) ;
}
F_43 ( V_3 ) ;
return V_74 ? 0 : - 1 ;
}
static char * F_44 ( char * V_4 , char * V_100 , int V_101 )
{
char * V_102 = NULL ;
T_3 V_38 ;
if ( ! V_4 )
V_4 = V_100 ;
if ( V_101 >= 10 )
goto V_83;
if ( V_101 < 0 )
V_38 = strlen ( V_4 ) + sizeof( L_31 ) ;
else
V_38 = strlen ( V_100 ) + sizeof( L_32 ) ;
V_102 = malloc ( V_38 ) ;
if ( ! V_102 )
goto V_83;
if ( V_101 < 0 )
snprintf ( V_102 , V_38 , L_33 , V_4 ) ;
else
snprintf ( V_102 , V_38 , L_34 , V_100 , V_101 ) ;
V_83:
if ( V_4 != V_100 )
free ( V_4 ) ;
return V_102 ;
}
static int F_45 ( struct V_28 * V_29 ,
struct V_1 * type ,
struct V_14 * V_7 )
{
struct V_1 * V_103 = NULL ;
char * V_4 ;
int V_101 = 1 ;
int V_9 ;
if ( V_7 -> V_39 != V_7 -> V_4 )
return F_46 ( V_29 , type ,
( char * ) V_7 -> V_39 ) ;
V_4 = V_7 -> V_4 ;
if ( F_47 ( V_4 ) )
V_4 = F_44 ( V_4 , V_7 -> V_4 , - 1 ) ;
if ( ! V_4 ) {
F_4 ( L_35 ) ;
return - 1 ;
}
while ( ( V_103 = F_14 ( V_29 , V_4 ) ) ) {
F_15 ( V_103 ) ;
V_4 = F_44 ( V_4 , V_7 -> V_4 , V_101 ++ ) ;
if ( ! V_4 ) {
F_4 ( L_36 , V_7 -> V_4 ) ;
return - 1 ;
}
}
V_9 = F_46 ( V_29 , type , V_4 ) ;
if ( ! V_9 )
V_7 -> V_39 = V_4 ;
return V_9 ;
}
static int F_48 ( struct V_12 * V_13 ,
struct V_14 * V_46 ,
struct V_28 * V_29 )
{
struct V_14 * V_7 ;
int V_9 ;
for ( V_7 = V_46 ; V_7 ; V_7 = V_7 -> V_47 ) {
struct V_1 * type ;
unsigned long V_15 = V_7 -> V_15 ;
F_8 ( L_37 , V_7 -> V_4 ) ;
type = F_10 ( V_13 , V_7 ) ;
if ( ! type )
return - 1 ;
if ( V_15 & V_16 )
V_15 &= ~ V_40 ;
if ( V_15 & V_40 )
type = F_49 ( type , V_7 -> V_44 ) ;
V_9 = F_45 ( V_29 , type , V_7 ) ;
if ( V_15 & V_40 )
F_15 ( type ) ;
if ( V_9 ) {
F_4 ( L_38 ,
V_7 -> V_4 , V_9 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_50 ( struct V_12 * V_13 ,
struct V_48 * V_49 ,
struct V_28 * V_104 )
{
struct V_14 * V_50 = V_49 -> V_51 -> V_52 . V_50 ;
struct V_14 * V_46 = V_49 -> V_51 -> V_52 . V_46 ;
int V_9 ;
V_9 = F_48 ( V_13 , V_50 , V_104 ) ;
if ( ! V_9 )
V_9 = F_48 ( V_13 , V_46 , V_104 ) ;
return V_9 ;
}
static int F_51 ( struct V_12 * V_13 , struct V_48 * V_49 ,
struct V_28 * V_29 )
{
T_1 type = V_49 -> V_53 . V_54 ;
#define F_52 ( T_4 , V_103 , T_5 ) \
do { \
pr2(" field '%s'\n", n); \
if (bt_ctf_event_class_add_field(cl, t, n)) { \
pr_err("Failed to add field '%s';\n", n); \
return -1; \
} \
} while (0)
if ( type & V_55 )
F_52 ( V_29 , V_13 -> V_17 . V_21 , L_9 ) ;
if ( type & V_57 ) {
F_52 ( V_29 , V_13 -> V_17 . V_24 , L_10 ) ;
F_52 ( V_29 , V_13 -> V_17 . V_24 , L_11 ) ;
}
if ( ( type & V_60 ) ||
( type & V_61 ) )
F_52 ( V_29 , V_13 -> V_17 . T_1 , L_12 ) ;
if ( type & V_63 )
F_52 ( V_29 , V_13 -> V_17 . T_1 , L_13 ) ;
if ( type & V_65 )
F_52 ( V_29 , V_13 -> V_17 . T_1 , L_14 ) ;
if ( type & V_67 )
F_52 ( V_29 , V_13 -> V_17 . T_1 , L_15 ) ;
if ( type & V_69 )
F_52 ( V_29 , V_13 -> V_17 . T_1 , L_16 ) ;
if ( type & V_71 )
F_52 ( V_29 , V_13 -> V_17 . T_1 , L_17 ) ;
#undef F_52
return 0 ;
}
static int F_53 ( struct V_12 * V_13 , struct V_48 * V_49 )
{
struct V_28 * V_29 ;
struct V_94 * V_95 ;
const char * V_4 = F_54 ( V_49 ) ;
int V_9 ;
F_26 ( L_39 , V_4 , V_49 -> V_53 . type ) ;
V_29 = F_55 ( V_4 ) ;
if ( ! V_29 )
return - 1 ;
V_9 = F_51 ( V_13 , V_49 , V_29 ) ;
if ( V_9 )
goto V_10;
if ( V_49 -> V_53 . type == V_99 ) {
V_9 = F_50 ( V_13 , V_49 , V_29 ) ;
if ( V_9 )
goto V_10;
}
V_9 = F_56 ( V_13 -> V_82 , V_29 ) ;
if ( V_9 ) {
F_26 ( L_40 ) ;
goto V_10;
}
V_95 = malloc ( sizeof( * V_95 ) ) ;
if ( ! V_95 )
goto V_10;
V_95 -> V_29 = V_29 ;
V_49 -> V_95 = V_95 ;
return 0 ;
V_10:
F_57 ( V_29 ) ;
F_4 ( L_41 , V_4 ) ;
return - 1 ;
}
static int F_58 ( struct V_12 * V_13 , struct V_105 * V_106 )
{
struct V_107 * V_108 = V_106 -> V_108 ;
struct V_48 * V_49 ;
int V_9 ;
F_59 (evlist, evsel) {
V_9 = F_53 ( V_13 , V_49 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_60 ( struct V_12 * V_13 , struct V_105 * V_106 )
{
struct V_73 * * V_75 ;
struct V_109 * V_110 = & V_106 -> V_98 ;
int V_111 ;
V_111 = V_110 -> V_112 . V_113 ? : V_114 ;
V_75 = F_28 ( sizeof( * V_75 ) * V_111 ) ;
if ( ! V_75 ) {
F_4 ( L_42 ) ;
return - V_115 ;
}
V_13 -> V_75 = V_75 ;
V_13 -> V_85 = V_111 ;
return 0 ;
}
static void F_61 ( struct V_12 * V_13 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_13 -> V_85 ; V_76 ++ )
F_33 ( V_13 -> V_75 [ V_76 ] ) ;
free ( V_13 -> V_75 ) ;
}
static int F_62 ( struct V_12 * V_13 ,
struct V_105 * V_106 )
{
struct V_109 * V_98 = & V_106 -> V_98 ;
struct V_116 * V_81 = V_13 -> V_81 ;
#define F_63 ( T_6 , T_7 ) \
do { \
if (bt_ctf_writer_add_environment_field(writer, __n, __v)) \
return -1; \
} while (0)
F_63 ( L_43 , V_98 -> V_112 . V_117 ) ;
F_63 ( L_44 , L_45 ) ;
F_63 ( L_46 , V_98 -> V_112 . V_118 ) ;
F_63 ( L_47 , V_98 -> V_112 . V_119 ) ;
F_63 ( L_48 , V_98 -> V_112 . V_120 ) ;
F_63 ( L_49 , L_50 ) ;
F_63 ( L_51 , L_52 ) ;
#undef F_63
return 0 ;
}
static int F_64 ( struct V_12 * V_13 )
{
struct V_121 * clock = V_13 -> clock ;
F_65 ( clock , L_53 ) ;
#define F_66 ( T_6 , T_7 ) \
do { \
if (bt_ctf_clock_set_##__n(clock, __v)) \
return -1; \
} while (0)
F_66 ( V_122 , 1000000000 ) ;
F_66 ( V_123 , 0 ) ;
F_66 ( V_37 , 0 ) ;
F_66 ( V_124 , 10 ) ;
F_66 ( V_125 , 0 ) ;
#undef F_66
return 0 ;
}
static struct V_1 * F_67 ( int V_22 , bool V_8 , bool V_126 )
{
struct V_1 * type ;
type = F_68 ( V_22 ) ;
if ( ! type )
return NULL ;
if ( V_8 &&
F_69 ( type , 1 ) )
goto V_10;
if ( V_126 &&
F_70 ( type , V_127 ) )
goto V_10;
F_8 ( L_54 ,
V_22 , V_8 ? L_55 : L_56 , V_126 ? L_57 : L_56 ) ;
return type ;
V_10:
F_15 ( type ) ;
return NULL ;
}
static void F_71 ( struct V_12 * V_13 )
{
unsigned int V_36 ;
for ( V_36 = 0 ; V_36 < F_72 ( V_13 -> V_17 . V_128 ) ; V_36 ++ )
F_15 ( V_13 -> V_17 . V_128 [ V_36 ] ) ;
}
static int F_73 ( struct V_12 * V_13 )
{
#define F_74 ( type , V_22 , V_8 , V_126 ) \
do { \
(type) = create_int_type(size, sign, hex); \
if (!(type)) \
goto err; \
} while (0)
F_74 ( V_13 -> V_17 . V_23 , 64 , true , false ) ;
F_74 ( V_13 -> V_17 . T_1 , 64 , false , false ) ;
F_74 ( V_13 -> V_17 . V_24 , 32 , true , false ) ;
F_74 ( V_13 -> V_17 . V_25 , 32 , false , false ) ;
F_74 ( V_13 -> V_17 . V_129 , 32 , false , true ) ;
F_74 ( V_13 -> V_17 . V_21 , 64 , false , true ) ;
V_13 -> V_17 . string = F_75 () ;
if ( V_13 -> V_17 . string )
return 0 ;
V_10:
F_71 ( V_13 ) ;
F_4 ( L_58 ) ;
return - 1 ;
}
static void F_76 ( struct V_12 * V_13 )
{
F_71 ( V_13 ) ;
F_77 ( V_13 -> clock ) ;
F_61 ( V_13 ) ;
F_78 ( V_13 -> V_82 ) ;
F_79 ( V_13 -> V_81 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
}
static int F_80 ( struct V_12 * V_13 , const char * V_130 )
{
struct V_116 * V_81 ;
struct V_131 * V_82 ;
struct V_121 * clock ;
struct V_1 * V_132 ;
int V_9 ;
V_81 = F_81 ( V_130 ) ;
if ( ! V_81 )
goto V_10;
V_13 -> V_81 = V_81 ;
clock = F_82 ( L_59 ) ;
if ( ! clock ) {
F_26 ( L_60 ) ;
goto V_133;
}
V_13 -> clock = clock ;
if ( F_64 ( V_13 ) ) {
F_26 ( L_61 ) ;
goto V_133;
}
V_82 = F_83 ( L_62 ) ;
if ( ! V_82 ) {
F_26 ( L_63 ) ;
goto V_133;
}
V_13 -> V_82 = V_82 ;
if ( F_84 ( V_82 , clock ) ) {
F_26 ( L_64 ) ;
goto V_133;
}
if ( F_73 ( V_13 ) )
goto V_133;
V_132 = F_85 ( V_82 ) ;
if ( ! V_132 )
goto V_133;
V_9 = F_86 ( V_132 , V_13 -> V_17 . V_25 , L_23 ) ;
F_15 ( V_132 ) ;
if ( V_9 )
goto V_133;
if ( F_87 ( V_81 , clock ) ) {
F_26 ( L_65 ) ;
goto V_133;
}
return 0 ;
V_133:
F_76 ( V_13 ) ;
V_10:
F_4 ( L_66 ) ;
return - 1 ;
}
static int F_88 ( struct V_12 * V_13 )
{
int V_76 , V_9 = 0 ;
for ( V_76 = 0 ; V_76 < V_13 -> V_85 && ! V_9 ; V_76 ++ )
V_9 = F_24 ( V_13 -> V_75 [ V_76 ] ) ;
return V_9 ;
}
static int F_89 ( const char * V_134 , const char * V_135 , void * V_136 )
{
struct V_92 * V_93 = V_136 ;
if ( ! strcmp ( V_134 , L_67 ) ) {
V_93 -> V_137 = F_90 ( V_134 , V_135 ) ;
return 0 ;
}
return F_91 ( V_134 , V_135 , V_136 ) ;
}
int F_92 ( const char * V_138 , const char * V_130 , bool V_139 )
{
struct V_105 * V_106 ;
struct V_140 V_141 = {
. V_130 = V_138 ,
. V_142 = V_143 ,
. V_139 = V_139 ,
} ;
struct V_92 V_93 = {
. V_88 = {
. V_31 = F_36 ,
. V_144 = V_145 ,
. V_146 = V_147 ,
. V_148 = V_149 ,
. exit = V_150 ,
. V_151 = V_152 ,
. V_153 = V_154 ,
. V_155 = V_156 ,
. V_157 = V_158 ,
. V_159 = true ,
. V_160 = true ,
} ,
} ;
struct V_12 * V_13 = & V_93 . V_81 ;
int V_10 = - 1 ;
F_93 ( F_89 , & V_93 ) ;
if ( F_80 ( V_13 , V_130 ) )
return - 1 ;
V_106 = F_94 ( & V_141 , 0 , & V_93 . V_88 ) ;
if ( ! V_106 )
goto V_161;
if ( V_93 . V_137 ) {
F_95 ( & V_106 -> V_159 ,
V_93 . V_137 ) ;
}
if ( F_62 ( V_13 , V_106 ) )
goto V_162;
if ( F_58 ( V_13 , V_106 ) )
goto V_162;
if ( F_60 ( V_13 , V_106 ) )
goto V_162;
V_10 = F_96 ( V_106 ) ;
if ( ! V_10 )
V_10 = F_88 ( V_13 ) ;
else
F_4 ( L_68 ) ;
fprintf ( V_163 ,
L_69 ,
V_141 . V_130 , V_130 ) ;
fprintf ( V_163 ,
L_70 V_11 L_71 ,
( double ) V_93 . V_97 / 1024.0 / 1024.0 ,
V_93 . V_96 ) ;
F_97 ( V_106 ) ;
F_76 ( V_13 ) ;
return V_10 ;
V_162:
F_97 ( V_106 ) ;
V_161:
F_76 ( V_13 ) ;
F_4 ( L_72 ) ;
return V_10 ;
}
