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
static int
F_20 ( struct V_28 * V_29 ,
struct V_2 * V_3 ,
struct V_30 * V_31 )
{
struct V_1 * V_53 , * V_54 ;
struct V_6 * V_55 , * V_56 ;
unsigned int V_57 = V_31 -> V_57 ;
unsigned int V_58 = V_57 / sizeof( V_25 ) ;
unsigned int V_36 ;
int V_9 ;
if ( V_58 * sizeof( V_25 ) != V_57 )
F_21 ( L_9 ,
V_57 , V_58 * sizeof( V_25 ) - V_57 ) ;
V_53 = F_14 ( V_29 , L_10 ) ;
V_55 = F_3 ( V_53 ) ;
if ( ! V_55 ) {
F_4 ( L_11 ) ;
V_9 = - 1 ;
goto V_59;
}
V_9 = F_6 ( V_55 , V_58 ) ;
if ( V_9 ) {
F_4 ( L_12 ) ;
goto V_60;
}
V_9 = F_7 ( V_3 , L_10 , V_55 ) ;
if ( V_9 ) {
F_4 ( L_13 ) ;
goto V_60;
}
V_54 = F_14 ( V_29 , L_14 ) ;
V_56 = F_3 ( V_54 ) ;
if ( ! V_56 ) {
F_4 ( L_15 ) ;
V_9 = - 1 ;
goto V_61;
}
V_9 = F_22 ( V_56 , V_55 ) ;
if ( V_9 ) {
F_4 ( L_16 ) ;
goto V_62;
}
for ( V_36 = 0 ; V_36 < V_58 ; V_36 ++ ) {
struct V_6 * V_63 =
F_23 ( V_56 , V_36 ) ;
V_9 = F_6 ( V_63 ,
( ( V_25 * ) ( V_31 -> V_34 ) ) [ V_36 ] ) ;
F_9 ( V_63 ) ;
if ( V_9 ) {
F_4 ( L_17 , V_36 ) ;
goto V_62;
}
}
V_9 = F_7 ( V_3 , L_14 , V_56 ) ;
if ( V_9 )
F_4 ( L_18 ) ;
V_62:
F_9 ( V_56 ) ;
V_61:
F_15 ( V_54 ) ;
V_60:
F_9 ( V_55 ) ;
V_59:
F_15 ( V_53 ) ;
return V_9 ;
}
static int F_24 ( struct V_12 * V_13 ,
struct V_2 * V_3 ,
struct V_48 * V_49 ,
struct V_30 * V_31 )
{
T_1 type = V_49 -> V_64 . V_65 ;
int V_9 ;
if ( type & V_66 ) {
V_9 = F_25 ( V_13 , V_3 , L_19 , V_31 -> V_67 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_68 ) {
V_9 = F_26 ( V_13 , V_3 , L_20 , V_31 -> V_69 ) ;
if ( V_9 )
return - 1 ;
V_9 = F_26 ( V_13 , V_3 , L_21 , V_31 -> V_70 ) ;
if ( V_9 )
return - 1 ;
}
if ( ( type & V_71 ) ||
( type & V_72 ) ) {
V_9 = F_27 ( V_13 , V_3 , L_22 , V_31 -> V_73 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_74 ) {
V_9 = F_27 ( V_13 , V_3 , L_23 , V_31 -> V_75 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_76 ) {
V_9 = F_27 ( V_13 , V_3 , L_24 , V_31 -> V_77 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_78 ) {
V_9 = F_27 ( V_13 , V_3 , L_25 , V_31 -> V_79 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_80 ) {
V_9 = F_27 ( V_13 , V_3 , L_26 ,
V_31 -> V_81 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_82 ) {
V_9 = F_27 ( V_13 , V_3 , L_27 ,
V_31 -> V_83 ) ;
if ( V_9 )
return - 1 ;
}
return 0 ;
}
static int F_28 ( struct V_84 * V_85 )
{
int V_10 = 0 ;
if ( V_85 ) {
V_10 = F_29 ( V_85 -> V_86 ) ;
if ( V_10 )
F_4 ( L_28 , V_85 -> V_87 ) ;
F_30 ( L_29 ,
V_85 -> V_87 , V_85 -> V_88 ) ;
V_85 -> V_88 = 0 ;
}
return V_10 ;
}
static struct V_84 * F_31 ( struct V_12 * V_13 , int V_87 )
{
struct V_84 * V_85 ;
struct V_6 * V_89 = NULL ;
struct V_6 * V_90 = NULL ;
struct V_91 * V_86 = NULL ;
int V_9 ;
V_85 = F_32 ( sizeof( * V_85 ) ) ;
if ( ! V_85 ) {
F_4 ( L_30 ) ;
return NULL ;
}
V_86 = F_33 ( V_13 -> V_92 , V_13 -> V_93 ) ;
if ( ! V_86 ) {
F_4 ( L_31 ) ;
goto V_94;
}
V_89 = F_34 ( V_86 ) ;
if ( ! V_89 ) {
F_4 ( L_32 ) ;
goto V_94;
}
V_90 = F_35 ( V_89 , L_33 ) ;
F_9 ( V_89 ) ;
if ( ! V_90 ) {
F_4 ( L_34 ) ;
goto V_94;
}
V_9 = F_6 ( V_90 , ( V_25 ) V_87 ) ;
if ( V_9 ) {
F_4 ( L_35 ) ;
goto V_94;
}
F_9 ( V_90 ) ;
V_85 -> V_87 = V_87 ;
V_85 -> V_86 = V_86 ;
return V_85 ;
V_94:
if ( V_90 )
F_9 ( V_90 ) ;
if ( V_86 )
F_36 ( V_86 ) ;
free ( V_85 ) ;
return NULL ;
}
static void F_37 ( struct V_84 * V_85 )
{
if ( V_85 ) {
F_36 ( V_85 -> V_86 ) ;
free ( V_85 ) ;
}
}
static struct V_84 * V_84 ( struct V_12 * V_13 , int V_87 )
{
struct V_84 * V_85 = V_13 -> V_86 [ V_87 ] ;
if ( ! V_85 ) {
V_85 = F_31 ( V_13 , V_87 ) ;
V_13 -> V_86 [ V_87 ] = V_85 ;
}
return V_85 ;
}
static int F_38 ( struct V_12 * V_13 , struct V_30 * V_31 ,
struct V_48 * V_49 )
{
int V_87 = 0 ;
if ( V_49 -> V_64 . V_65 & V_95 )
V_87 = V_31 -> V_87 ;
if ( V_87 > V_13 -> V_96 ) {
F_4 ( L_36 ,
V_87 , V_13 -> V_96 ) ;
V_87 = 0 ;
}
return V_87 ;
}
static bool F_39 ( struct V_84 * V_85 )
{
return V_85 -> V_88 >= V_97 ;
}
static int F_40 ( struct V_98 * V_99 ,
union V_100 * V_101 ,
struct V_30 * V_31 ,
struct V_48 * V_49 ,
struct V_102 * V_102 V_103 )
{
struct V_104 * V_105 = F_41 ( V_99 , struct V_104 , V_99 ) ;
struct V_106 * V_107 = V_49 -> V_107 ;
struct V_12 * V_13 = & V_105 -> V_92 ;
struct V_84 * V_85 ;
struct V_28 * V_29 ;
struct V_2 * V_3 ;
int V_9 ;
if ( F_42 ( ! V_107 , L_37 ) )
return 0 ;
V_29 = V_107 -> V_29 ;
V_105 -> V_108 ++ ;
V_105 -> V_109 += V_101 -> V_110 . V_22 ;
F_43 ( V_31 -> time , L_38 V_11 L_39 , V_105 -> V_108 ) ;
V_3 = F_44 ( V_29 ) ;
if ( ! V_3 ) {
F_4 ( L_40 ) ;
return - 1 ;
}
F_45 ( V_13 -> clock , V_31 -> time ) ;
V_9 = F_24 ( V_13 , V_3 , V_49 , V_31 ) ;
if ( V_9 )
return - 1 ;
if ( V_49 -> V_64 . type == V_111 ) {
V_9 = F_19 ( V_13 , V_29 , V_3 ,
V_49 , V_31 ) ;
if ( V_9 )
return - 1 ;
}
if ( F_46 ( V_49 ) ) {
V_9 = F_20 ( V_29 , V_3 , V_31 ) ;
if ( V_9 )
return - 1 ;
}
V_85 = V_84 ( V_13 , F_38 ( V_13 , V_31 , V_49 ) ) ;
if ( V_85 ) {
if ( F_39 ( V_85 ) )
F_28 ( V_85 ) ;
V_85 -> V_88 ++ ;
F_47 ( V_85 -> V_86 , V_3 ) ;
}
F_48 ( V_3 ) ;
return V_85 ? 0 : - 1 ;
}
static char * F_49 ( char * V_4 , char * V_112 , int V_113 )
{
char * V_114 = NULL ;
T_2 V_38 ;
if ( ! V_4 )
V_4 = V_112 ;
if ( V_113 >= 10 )
goto V_94;
if ( V_113 < 0 )
V_38 = strlen ( V_4 ) + sizeof( L_41 ) ;
else
V_38 = strlen ( V_112 ) + sizeof( L_42 ) ;
V_114 = malloc ( V_38 ) ;
if ( ! V_114 )
goto V_94;
if ( V_113 < 0 )
snprintf ( V_114 , V_38 , L_43 , V_4 ) ;
else
snprintf ( V_114 , V_38 , L_44 , V_112 , V_113 ) ;
V_94:
if ( V_4 != V_112 )
free ( V_4 ) ;
return V_114 ;
}
static int F_50 ( struct V_28 * V_29 ,
struct V_1 * type ,
struct V_14 * V_7 )
{
struct V_1 * V_115 = NULL ;
char * V_4 ;
int V_113 = 1 ;
int V_9 ;
if ( V_7 -> V_39 != V_7 -> V_4 )
return F_51 ( V_29 , type ,
( char * ) V_7 -> V_39 ) ;
V_4 = V_7 -> V_4 ;
if ( F_52 ( V_4 ) )
V_4 = F_49 ( V_4 , V_7 -> V_4 , - 1 ) ;
if ( ! V_4 ) {
F_4 ( L_45 ) ;
return - 1 ;
}
while ( ( V_115 = F_14 ( V_29 , V_4 ) ) ) {
F_15 ( V_115 ) ;
V_4 = F_49 ( V_4 , V_7 -> V_4 , V_113 ++ ) ;
if ( ! V_4 ) {
F_4 ( L_46 , V_7 -> V_4 ) ;
return - 1 ;
}
}
V_9 = F_51 ( V_29 , type , V_4 ) ;
if ( ! V_9 )
V_7 -> V_39 = V_4 ;
return V_9 ;
}
static int F_53 ( struct V_12 * V_13 ,
struct V_14 * V_46 ,
struct V_28 * V_29 )
{
struct V_14 * V_7 ;
int V_9 ;
for ( V_7 = V_46 ; V_7 ; V_7 = V_7 -> V_47 ) {
struct V_1 * type ;
unsigned long V_15 = V_7 -> V_15 ;
F_8 ( L_47 , V_7 -> V_4 ) ;
type = F_10 ( V_13 , V_7 ) ;
if ( ! type )
return - 1 ;
if ( V_15 & V_16 )
V_15 &= ~ V_40 ;
if ( V_15 & V_40 )
type = F_54 ( type , V_7 -> V_44 ) ;
V_9 = F_50 ( V_29 , type , V_7 ) ;
if ( V_15 & V_40 )
F_15 ( type ) ;
if ( V_9 ) {
F_4 ( L_48 ,
V_7 -> V_4 , V_9 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_55 ( struct V_12 * V_13 ,
struct V_48 * V_49 ,
struct V_28 * V_116 )
{
struct V_14 * V_50 = V_49 -> V_51 -> V_52 . V_50 ;
struct V_14 * V_46 = V_49 -> V_51 -> V_52 . V_46 ;
int V_9 ;
V_9 = F_53 ( V_13 , V_50 , V_116 ) ;
if ( ! V_9 )
V_9 = F_53 ( V_13 , V_46 , V_116 ) ;
return V_9 ;
}
static int F_56 ( struct V_12 * V_13 ,
struct V_28 * V_116 )
{
struct V_1 * V_53 = V_13 -> V_17 . V_25 ;
struct V_1 * V_117 = V_13 -> V_17 . V_118 ;
struct V_1 * V_54 ;
int V_9 ;
V_9 = F_51 ( V_116 , V_53 , L_10 ) ;
if ( V_9 )
return V_9 ;
V_54 = F_57 ( V_117 , L_10 ) ;
if ( ! V_54 )
return - 1 ;
return F_51 ( V_116 , V_54 , L_14 ) ;
}
static int F_58 ( struct V_12 * V_13 , struct V_48 * V_49 ,
struct V_28 * V_29 )
{
T_1 type = V_49 -> V_64 . V_65 ;
#define F_59 ( T_3 , V_115 , T_4 ) \
do { \
pr2(" field '%s'\n", n); \
if (bt_ctf_event_class_add_field(cl, t, n)) { \
pr_err("Failed to add field '%s';\n", n); \
return -1; \
} \
} while (0)
if ( type & V_66 )
F_59 ( V_29 , V_13 -> V_17 . V_21 , L_19 ) ;
if ( type & V_68 ) {
F_59 ( V_29 , V_13 -> V_17 . V_24 , L_20 ) ;
F_59 ( V_29 , V_13 -> V_17 . V_24 , L_21 ) ;
}
if ( ( type & V_71 ) ||
( type & V_72 ) )
F_59 ( V_29 , V_13 -> V_17 . T_1 , L_22 ) ;
if ( type & V_74 )
F_59 ( V_29 , V_13 -> V_17 . T_1 , L_23 ) ;
if ( type & V_76 )
F_59 ( V_29 , V_13 -> V_17 . T_1 , L_24 ) ;
if ( type & V_78 )
F_59 ( V_29 , V_13 -> V_17 . T_1 , L_25 ) ;
if ( type & V_80 )
F_59 ( V_29 , V_13 -> V_17 . T_1 , L_26 ) ;
if ( type & V_82 )
F_59 ( V_29 , V_13 -> V_17 . T_1 , L_27 ) ;
#undef F_59
return 0 ;
}
static int F_60 ( struct V_12 * V_13 , struct V_48 * V_49 )
{
struct V_28 * V_29 ;
struct V_106 * V_107 ;
const char * V_4 = F_61 ( V_49 ) ;
int V_9 ;
F_30 ( L_49 , V_4 , V_49 -> V_64 . type ) ;
V_29 = F_62 ( V_4 ) ;
if ( ! V_29 )
return - 1 ;
V_9 = F_58 ( V_13 , V_49 , V_29 ) ;
if ( V_9 )
goto V_10;
if ( V_49 -> V_64 . type == V_111 ) {
V_9 = F_55 ( V_13 , V_49 , V_29 ) ;
if ( V_9 )
goto V_10;
}
if ( F_46 ( V_49 ) ) {
V_9 = F_56 ( V_13 , V_29 ) ;
if ( V_9 )
goto V_10;
}
V_9 = F_63 ( V_13 -> V_93 , V_29 ) ;
if ( V_9 ) {
F_30 ( L_50 ) ;
goto V_10;
}
V_107 = malloc ( sizeof( * V_107 ) ) ;
if ( ! V_107 )
goto V_10;
V_107 -> V_29 = V_29 ;
V_49 -> V_107 = V_107 ;
return 0 ;
V_10:
F_64 ( V_29 ) ;
F_4 ( L_51 , V_4 ) ;
return - 1 ;
}
static int F_65 ( struct V_12 * V_13 , struct V_119 * V_120 )
{
struct V_121 * V_122 = V_120 -> V_122 ;
struct V_48 * V_49 ;
int V_9 ;
F_66 (evlist, evsel) {
V_9 = F_60 ( V_13 , V_49 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static void F_67 ( struct V_119 * V_120 )
{
struct V_121 * V_122 = V_120 -> V_122 ;
struct V_48 * V_49 ;
F_66 (evlist, evsel) {
struct V_106 * V_107 ;
V_107 = V_49 -> V_107 ;
F_64 ( V_107 -> V_29 ) ;
F_68 ( & V_49 -> V_107 ) ;
}
F_69 ( V_122 ) ;
V_120 -> V_122 = NULL ;
}
static int F_70 ( struct V_12 * V_13 , struct V_119 * V_120 )
{
struct V_84 * * V_86 ;
struct V_123 * V_124 = & V_120 -> V_110 ;
int V_125 ;
V_125 = V_124 -> V_126 . V_127 ? : V_128 ;
V_86 = F_32 ( sizeof( * V_86 ) * V_125 ) ;
if ( ! V_86 ) {
F_4 ( L_52 ) ;
return - V_129 ;
}
V_13 -> V_86 = V_86 ;
V_13 -> V_96 = V_125 ;
return 0 ;
}
static void F_71 ( struct V_12 * V_13 )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < V_13 -> V_96 ; V_87 ++ )
F_37 ( V_13 -> V_86 [ V_87 ] ) ;
free ( V_13 -> V_86 ) ;
}
static int F_72 ( struct V_12 * V_13 ,
struct V_119 * V_120 )
{
struct V_123 * V_110 = & V_120 -> V_110 ;
struct V_130 * V_92 = V_13 -> V_92 ;
#define F_73 ( T_5 , T_6 ) \
do { \
if (bt_ctf_writer_add_environment_field(writer, __n, __v)) \
return -1; \
} while (0)
F_73 ( L_53 , V_110 -> V_126 . V_131 ) ;
F_73 ( L_54 , L_55 ) ;
F_73 ( L_56 , V_110 -> V_126 . V_132 ) ;
F_73 ( L_57 , V_110 -> V_126 . V_133 ) ;
F_73 ( L_58 , V_110 -> V_126 . V_134 ) ;
F_73 ( L_59 , L_60 ) ;
F_73 ( L_61 , L_62 ) ;
#undef F_73
return 0 ;
}
static int F_74 ( struct V_12 * V_13 )
{
struct V_135 * clock = V_13 -> clock ;
F_75 ( clock , L_63 ) ;
#define F_76 ( T_5 , T_6 ) \
do { \
if (bt_ctf_clock_set_##__n(clock, __v)) \
return -1; \
} while (0)
F_76 ( V_136 , 1000000000 ) ;
F_76 ( V_137 , 0 ) ;
F_76 ( V_37 , 0 ) ;
F_76 ( V_138 , 10 ) ;
F_76 ( V_139 , 0 ) ;
#undef F_76
return 0 ;
}
static struct V_1 * F_77 ( int V_22 , bool V_8 , bool V_140 )
{
struct V_1 * type ;
type = F_78 ( V_22 ) ;
if ( ! type )
return NULL ;
if ( V_8 &&
F_79 ( type , 1 ) )
goto V_10;
if ( V_140 &&
F_80 ( type , V_141 ) )
goto V_10;
#if V_142 == V_143
F_81 ( type , V_144 ) ;
#else
F_81 ( type , V_145 ) ;
#endif
F_8 ( L_64 ,
V_22 , V_8 ? L_65 : L_66 , V_140 ? L_67 : L_66 ) ;
return type ;
V_10:
F_15 ( type ) ;
return NULL ;
}
static void F_82 ( struct V_12 * V_13 )
{
unsigned int V_36 ;
for ( V_36 = 0 ; V_36 < F_83 ( V_13 -> V_17 . V_146 ) ; V_36 ++ )
F_15 ( V_13 -> V_17 . V_146 [ V_36 ] ) ;
}
static int F_84 ( struct V_12 * V_13 )
{
#define F_85 ( type , V_22 , V_8 , V_140 ) \
do { \
(type) = create_int_type(size, sign, hex); \
if (!(type)) \
goto err; \
} while (0)
F_85 ( V_13 -> V_17 . V_23 , 64 , true , false ) ;
F_85 ( V_13 -> V_17 . T_1 , 64 , false , false ) ;
F_85 ( V_13 -> V_17 . V_24 , 32 , true , false ) ;
F_85 ( V_13 -> V_17 . V_25 , 32 , false , false ) ;
F_85 ( V_13 -> V_17 . V_118 , 32 , false , true ) ;
F_85 ( V_13 -> V_17 . V_21 , 64 , false , true ) ;
V_13 -> V_17 . string = F_86 () ;
if ( V_13 -> V_17 . string )
return 0 ;
V_10:
F_82 ( V_13 ) ;
F_4 ( L_68 ) ;
return - 1 ;
}
static void F_87 ( struct V_12 * V_13 )
{
F_82 ( V_13 ) ;
F_88 ( V_13 -> clock ) ;
F_71 ( V_13 ) ;
F_89 ( V_13 -> V_93 ) ;
F_90 ( V_13 -> V_92 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
}
static int F_91 ( struct V_12 * V_13 , const char * V_147 )
{
struct V_130 * V_92 ;
struct V_148 * V_93 ;
struct V_135 * clock ;
struct V_1 * V_149 ;
int V_9 ;
V_92 = F_92 ( V_147 ) ;
if ( ! V_92 )
goto V_10;
V_13 -> V_92 = V_92 ;
clock = F_93 ( L_69 ) ;
if ( ! clock ) {
F_30 ( L_70 ) ;
goto V_150;
}
V_13 -> clock = clock ;
if ( F_74 ( V_13 ) ) {
F_30 ( L_71 ) ;
goto V_150;
}
V_93 = F_94 ( L_72 ) ;
if ( ! V_93 ) {
F_30 ( L_73 ) ;
goto V_150;
}
V_13 -> V_93 = V_93 ;
if ( F_95 ( V_93 , clock ) ) {
F_30 ( L_74 ) ;
goto V_150;
}
if ( F_84 ( V_13 ) )
goto V_150;
V_149 = F_96 ( V_93 ) ;
if ( ! V_149 )
goto V_150;
V_9 = F_97 ( V_149 , V_13 -> V_17 . V_25 , L_33 ) ;
F_15 ( V_149 ) ;
if ( V_9 )
goto V_150;
if ( F_98 ( V_92 , clock ) ) {
F_30 ( L_75 ) ;
goto V_150;
}
return 0 ;
V_150:
F_87 ( V_13 ) ;
V_10:
F_4 ( L_76 ) ;
return - 1 ;
}
static int F_99 ( struct V_12 * V_13 )
{
int V_87 , V_9 = 0 ;
for ( V_87 = 0 ; V_87 < V_13 -> V_96 && ! V_9 ; V_87 ++ )
V_9 = F_28 ( V_13 -> V_86 [ V_87 ] ) ;
return V_9 ;
}
static int F_100 ( const char * V_151 , const char * V_152 , void * V_153 )
{
struct V_104 * V_105 = V_153 ;
if ( ! strcmp ( V_151 , L_77 ) ) {
V_105 -> V_154 = F_101 ( V_151 , V_152 ) ;
return 0 ;
}
return 0 ;
}
int F_102 ( const char * V_155 , const char * V_147 , bool V_156 )
{
struct V_119 * V_120 ;
struct V_157 V_158 = {
. V_147 = V_155 ,
. V_159 = V_160 ,
. V_156 = V_156 ,
} ;
struct V_104 V_105 = {
. V_99 = {
. V_31 = F_40 ,
. V_161 = V_162 ,
. V_163 = V_164 ,
. V_165 = V_166 ,
. exit = V_167 ,
. V_168 = V_169 ,
. V_170 = V_171 ,
. V_172 = V_173 ,
. V_174 = V_175 ,
. V_176 = true ,
. V_177 = true ,
} ,
} ;
struct V_12 * V_13 = & V_105 . V_92 ;
int V_10 = - 1 ;
F_103 ( F_100 , & V_105 ) ;
if ( F_91 ( V_13 , V_147 ) )
return - 1 ;
V_120 = F_104 ( & V_158 , 0 , & V_105 . V_99 ) ;
if ( ! V_120 )
goto V_178;
if ( V_105 . V_154 ) {
F_105 ( & V_120 -> V_176 ,
V_105 . V_154 ) ;
}
if ( F_72 ( V_13 , V_120 ) )
goto V_179;
if ( F_65 ( V_13 , V_120 ) )
goto V_179;
if ( F_70 ( V_13 , V_120 ) )
goto V_179;
V_10 = F_106 ( V_120 ) ;
if ( ! V_10 )
V_10 = F_99 ( V_13 ) ;
else
F_4 ( L_78 ) ;
fprintf ( V_180 ,
L_79 ,
V_158 . V_147 , V_147 ) ;
fprintf ( V_180 ,
L_80 V_11 L_81 ,
( double ) V_105 . V_109 / 1024.0 / 1024.0 ,
V_105 . V_108 ) ;
F_67 ( V_120 ) ;
F_107 ( V_120 ) ;
F_87 ( V_13 ) ;
return V_10 ;
V_179:
F_107 ( V_120 ) ;
V_178:
F_87 ( V_13 ) ;
F_4 ( L_82 ) ;
return V_10 ;
}
