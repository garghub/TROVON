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
static T_2 int
F_10 ( struct V_12 * V_13 , struct V_2 * V_3 ,
const char * V_4 , const char * string )
{
struct V_1 * type = V_13 -> V_14 . string ;
struct V_6 * V_7 ;
int V_9 = 0 ;
V_7 = F_3 ( type ) ;
if ( ! V_7 ) {
F_4 ( L_1 , V_4 ) ;
return - 1 ;
}
V_9 = F_11 ( V_7 , string ) ;
if ( V_9 ) {
F_4 ( L_6 , V_4 ) ;
goto V_15;
}
V_9 = F_7 ( V_3 , V_4 , V_7 ) ;
if ( V_9 )
F_4 ( L_3 , V_4 ) ;
V_15:
F_9 ( V_7 ) ;
return V_9 ;
}
static struct V_1 *
F_12 ( struct V_12 * V_13 , struct V_16 * V_7 )
{
unsigned long V_17 = V_7 -> V_17 ;
if ( V_17 & V_18 )
return V_13 -> V_14 . string ;
if ( ! ( V_17 & V_19 ) ) {
if ( V_17 & V_20 || V_17 & V_21 )
return V_13 -> V_14 . V_22 ;
}
if ( V_17 & V_19 ) {
if ( V_7 -> V_23 == 8 )
return V_13 -> V_14 . V_24 ;
else
return V_13 -> V_14 . V_25 ;
}
if ( V_7 -> V_23 == 8 )
return V_13 -> V_14 . T_1 ;
else
return V_13 -> V_14 . V_26 ;
}
static unsigned long long F_13 ( unsigned long long V_27 , int V_23 )
{
unsigned long long V_28 ;
switch ( V_23 ) {
case 1 :
V_28 = 0x7fULL ;
break;
case 2 :
V_28 = 0x7fffULL ;
break;
case 4 :
V_28 = 0x7fffffffULL ;
break;
case 8 :
default:
return V_27 ;
}
if ( ( V_27 & ( ~ 0ULL - V_28 ) ) == 0 )
return V_27 ;
return ( V_27 & V_28 ) | ~ V_28 ;
}
static int F_11 ( struct V_6 * V_7 , const char * string )
{
char * V_29 = NULL ;
T_3 V_30 = strlen ( string ) , V_31 , V_32 ;
int V_10 ;
for ( V_31 = V_32 = 0 ; V_31 < V_30 ; V_31 ++ , V_32 ++ ) {
if ( isprint ( string [ V_31 ] ) ) {
if ( ! V_29 )
continue;
V_29 [ V_32 ] = string [ V_31 ] ;
} else {
char V_33 [ 5 ] ;
snprintf ( V_33 , sizeof( V_33 ) , L_7 ,
( unsigned int ) ( string [ V_31 ] ) & 0xff ) ;
if ( ! V_29 ) {
V_29 = F_14 ( V_31 + ( V_30 - V_31 ) * 4 + 2 ) ;
if ( ! V_29 ) {
F_4 ( L_8 , string ) ;
return F_15 ( V_7 , L_9 ) ;
}
if ( V_31 > 0 )
strncpy ( V_29 , string , V_31 ) ;
}
strncat ( V_29 + V_32 , V_33 , 4 ) ;
V_32 += 3 ;
}
}
if ( ! V_29 )
return F_15 ( V_7 , string ) ;
V_10 = F_15 ( V_7 , V_29 ) ;
free ( V_29 ) ;
return V_10 ;
}
static int F_16 ( struct V_12 * V_13 ,
struct V_34 * V_35 ,
struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_16 * V_38 )
{
struct V_1 * type ;
struct V_6 * V_39 ;
struct V_6 * V_7 ;
const char * V_4 = V_38 -> V_4 ;
void * V_14 = V_37 -> V_40 ;
unsigned long V_17 = V_38 -> V_17 ;
unsigned int V_41 ;
unsigned int V_31 ;
unsigned int V_42 ;
unsigned int V_30 ;
int V_9 ;
V_4 = V_38 -> V_43 ;
V_42 = V_38 -> V_42 ;
V_30 = V_38 -> V_23 ;
if ( V_17 & V_18 )
V_17 &= ~ V_44 ;
if ( V_17 & V_45 ) {
unsigned long long V_46 ;
V_46 = F_17 ( V_38 -> V_3 -> V_47 ,
V_14 + V_42 , V_30 ) ;
V_42 = V_46 ;
V_30 = V_42 >> 16 ;
V_42 &= 0xffff ;
}
if ( V_17 & V_44 ) {
type = F_18 (
V_35 , V_4 ) ;
V_39 = F_3 ( type ) ;
F_19 ( type ) ;
if ( ! V_39 ) {
F_4 ( L_10 , V_4 ) ;
return - 1 ;
}
V_30 = V_38 -> V_23 / V_38 -> V_48 ;
V_41 = V_38 -> V_48 ;
} else {
V_41 = 1 ;
V_39 = NULL ;
}
type = F_12 ( V_13 , V_38 ) ;
for ( V_31 = 0 ; V_31 < V_41 ; V_31 ++ ) {
if ( V_17 & V_44 )
V_7 = F_20 ( V_39 , V_31 ) ;
else
V_7 = F_3 ( type ) ;
if ( ! V_7 ) {
F_4 ( L_1 , V_4 ) ;
return - 1 ;
}
if ( V_17 & V_18 )
V_9 = F_11 ( V_7 , V_14 + V_42 + V_31 * V_30 ) ;
else {
unsigned long long V_27 ;
V_27 = F_17 (
V_38 -> V_3 -> V_47 ,
V_14 + V_42 + V_31 * V_30 , V_30 ) ;
if ( ! ( V_17 & V_19 ) )
V_9 = F_6 (
V_7 , V_27 ) ;
else
V_9 = F_5 (
V_7 , F_13 ( V_27 , V_30 ) ) ;
}
if ( V_9 ) {
F_4 ( L_11 , V_4 ) ;
goto V_15;
}
if ( ! ( V_17 & V_44 ) ) {
V_9 = F_7 ( V_3 , V_4 , V_7 ) ;
if ( V_9 ) {
F_4 ( L_3 , V_4 ) ;
goto V_15;
}
}
F_9 ( V_7 ) ;
}
if ( V_17 & V_44 ) {
V_9 = F_7 ( V_3 , V_4 , V_39 ) ;
if ( V_9 ) {
F_4 ( L_12 , V_4 ) ;
return - 1 ;
}
F_9 ( V_39 ) ;
}
return 0 ;
V_15:
F_9 ( V_7 ) ;
return - 1 ;
}
static int F_21 ( struct V_12 * V_13 ,
struct V_34 * V_35 ,
struct V_2 * V_3 ,
struct V_16 * V_49 ,
struct V_36 * V_37 )
{
struct V_16 * V_7 ;
int V_9 ;
for ( V_7 = V_49 ; V_7 ; V_7 = V_7 -> V_50 ) {
V_9 = F_16 ( V_13 , V_35 , V_3 , V_37 ,
V_7 ) ;
if ( V_9 )
return - 1 ;
}
return 0 ;
}
static int F_22 ( struct V_12 * V_13 ,
struct V_34 * V_35 ,
struct V_2 * V_3 ,
struct V_51 * V_52 ,
struct V_36 * V_37 )
{
struct V_16 * V_53 = V_52 -> V_54 -> V_55 . V_53 ;
struct V_16 * V_49 = V_52 -> V_54 -> V_55 . V_49 ;
int V_9 ;
V_9 = F_21 ( V_13 , V_35 , V_3 ,
V_53 , V_37 ) ;
if ( ! V_9 )
V_9 = F_21 ( V_13 , V_35 , V_3 ,
V_49 , V_37 ) ;
return V_9 ;
}
static int
F_23 ( struct V_34 * V_35 ,
struct V_2 * V_3 ,
struct V_36 * V_37 )
{
struct V_1 * V_56 , * V_57 ;
struct V_6 * V_58 , * V_59 ;
unsigned int V_60 = V_37 -> V_60 ;
unsigned int V_61 = V_60 / sizeof( V_26 ) ;
unsigned int V_31 ;
int V_9 ;
if ( V_61 * sizeof( V_26 ) != V_60 )
F_24 ( L_13 ,
V_60 , V_61 * sizeof( V_26 ) - V_60 ) ;
V_56 = F_18 ( V_35 , L_14 ) ;
V_58 = F_3 ( V_56 ) ;
if ( ! V_58 ) {
F_4 ( L_15 ) ;
V_9 = - 1 ;
goto V_62;
}
V_9 = F_6 ( V_58 , V_61 ) ;
if ( V_9 ) {
F_4 ( L_16 ) ;
goto V_63;
}
V_9 = F_7 ( V_3 , L_14 , V_58 ) ;
if ( V_9 ) {
F_4 ( L_17 ) ;
goto V_63;
}
V_57 = F_18 ( V_35 , L_18 ) ;
V_59 = F_3 ( V_57 ) ;
if ( ! V_59 ) {
F_4 ( L_19 ) ;
V_9 = - 1 ;
goto V_64;
}
V_9 = F_25 ( V_59 , V_58 ) ;
if ( V_9 ) {
F_4 ( L_20 ) ;
goto V_65;
}
for ( V_31 = 0 ; V_31 < V_61 ; V_31 ++ ) {
struct V_6 * V_66 =
F_26 ( V_59 , V_31 ) ;
V_9 = F_6 ( V_66 ,
( ( V_26 * ) ( V_37 -> V_40 ) ) [ V_31 ] ) ;
F_9 ( V_66 ) ;
if ( V_9 ) {
F_4 ( L_21 , V_31 ) ;
goto V_65;
}
}
V_9 = F_7 ( V_3 , L_18 , V_59 ) ;
if ( V_9 )
F_4 ( L_22 ) ;
V_65:
F_9 ( V_59 ) ;
V_64:
F_19 ( V_57 ) ;
V_63:
F_9 ( V_58 ) ;
V_62:
F_19 ( V_56 ) ;
return V_9 ;
}
static int F_27 ( struct V_12 * V_13 ,
struct V_2 * V_3 ,
struct V_51 * V_52 ,
struct V_36 * V_37 )
{
T_1 type = V_52 -> V_67 . V_68 ;
int V_9 ;
if ( type & V_69 ) {
V_9 = F_28 ( V_13 , V_3 , L_23 , V_37 -> V_70 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_71 ) {
V_9 = F_29 ( V_13 , V_3 , L_24 , V_37 -> V_72 ) ;
if ( V_9 )
return - 1 ;
V_9 = F_29 ( V_13 , V_3 , L_25 , V_37 -> V_73 ) ;
if ( V_9 )
return - 1 ;
}
if ( ( type & V_74 ) ||
( type & V_75 ) ) {
V_9 = F_30 ( V_13 , V_3 , L_26 , V_37 -> V_76 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_77 ) {
V_9 = F_30 ( V_13 , V_3 , L_27 , V_37 -> V_78 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_79 ) {
V_9 = F_30 ( V_13 , V_3 , L_28 , V_37 -> V_80 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_81 ) {
V_9 = F_30 ( V_13 , V_3 , L_29 , V_37 -> V_82 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_83 ) {
V_9 = F_30 ( V_13 , V_3 , L_30 ,
V_37 -> V_84 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_85 ) {
V_9 = F_30 ( V_13 , V_3 , L_31 ,
V_37 -> V_86 ) ;
if ( V_9 )
return - 1 ;
}
return 0 ;
}
static int F_31 ( struct V_87 * V_88 )
{
int V_10 = 0 ;
if ( V_88 ) {
V_10 = F_32 ( V_88 -> V_89 ) ;
if ( V_10 )
F_4 ( L_32 , V_88 -> V_90 ) ;
F_33 ( L_33 ,
V_88 -> V_90 , V_88 -> V_91 ) ;
V_88 -> V_91 = 0 ;
}
return V_10 ;
}
static struct V_87 * F_34 ( struct V_12 * V_13 , int V_90 )
{
struct V_87 * V_88 ;
struct V_6 * V_92 = NULL ;
struct V_6 * V_93 = NULL ;
struct V_94 * V_89 = NULL ;
int V_9 ;
V_88 = F_14 ( sizeof( * V_88 ) ) ;
if ( ! V_88 ) {
F_4 ( L_34 ) ;
return NULL ;
}
V_89 = F_35 ( V_13 -> V_95 , V_13 -> V_96 ) ;
if ( ! V_89 ) {
F_4 ( L_35 ) ;
goto V_97;
}
V_92 = F_36 ( V_89 ) ;
if ( ! V_92 ) {
F_4 ( L_36 ) ;
goto V_97;
}
V_93 = F_37 ( V_92 , L_37 ) ;
F_9 ( V_92 ) ;
if ( ! V_93 ) {
F_4 ( L_38 ) ;
goto V_97;
}
V_9 = F_6 ( V_93 , ( V_26 ) V_90 ) ;
if ( V_9 ) {
F_4 ( L_39 ) ;
goto V_97;
}
F_9 ( V_93 ) ;
V_88 -> V_90 = V_90 ;
V_88 -> V_89 = V_89 ;
return V_88 ;
V_97:
if ( V_93 )
F_9 ( V_93 ) ;
if ( V_89 )
F_38 ( V_89 ) ;
free ( V_88 ) ;
return NULL ;
}
static void F_39 ( struct V_87 * V_88 )
{
if ( V_88 ) {
F_38 ( V_88 -> V_89 ) ;
free ( V_88 ) ;
}
}
static struct V_87 * V_87 ( struct V_12 * V_13 , int V_90 )
{
struct V_87 * V_88 = V_13 -> V_89 [ V_90 ] ;
if ( ! V_88 ) {
V_88 = F_34 ( V_13 , V_90 ) ;
V_13 -> V_89 [ V_90 ] = V_88 ;
}
return V_88 ;
}
static int F_40 ( struct V_12 * V_13 , struct V_36 * V_37 ,
struct V_51 * V_52 )
{
int V_90 = 0 ;
if ( V_52 -> V_67 . V_68 & V_98 )
V_90 = V_37 -> V_90 ;
if ( V_90 > V_13 -> V_99 ) {
F_4 ( L_40 ,
V_90 , V_13 -> V_99 ) ;
V_90 = 0 ;
}
return V_90 ;
}
static bool F_41 ( struct V_87 * V_88 )
{
return V_88 -> V_91 >= V_100 ;
}
static int F_42 ( struct V_101 * V_102 ,
union V_103 * V_104 ,
struct V_36 * V_37 ,
struct V_51 * V_52 ,
struct V_105 * V_105 T_2 )
{
struct V_106 * V_107 = F_43 ( V_102 , struct V_106 , V_102 ) ;
struct V_108 * V_109 = V_52 -> V_109 ;
struct V_12 * V_13 = & V_107 -> V_95 ;
struct V_87 * V_88 ;
struct V_34 * V_35 ;
struct V_2 * V_3 ;
int V_9 ;
if ( F_44 ( ! V_109 , L_41 ) )
return 0 ;
V_35 = V_109 -> V_35 ;
V_107 -> V_110 ++ ;
V_107 -> V_111 += V_104 -> V_112 . V_23 ;
F_45 ( V_37 -> time , L_42 V_11 L_43 , V_107 -> V_110 ) ;
V_3 = F_46 ( V_35 ) ;
if ( ! V_3 ) {
F_4 ( L_44 ) ;
return - 1 ;
}
F_47 ( V_13 -> clock , V_37 -> time ) ;
V_9 = F_27 ( V_13 , V_3 , V_52 , V_37 ) ;
if ( V_9 )
return - 1 ;
if ( V_52 -> V_67 . type == V_113 ) {
V_9 = F_22 ( V_13 , V_35 , V_3 ,
V_52 , V_37 ) ;
if ( V_9 )
return - 1 ;
}
if ( F_48 ( V_52 ) ) {
V_9 = F_23 ( V_35 , V_3 , V_37 ) ;
if ( V_9 )
return - 1 ;
}
V_88 = V_87 ( V_13 , F_40 ( V_13 , V_37 , V_52 ) ) ;
if ( V_88 ) {
if ( F_41 ( V_88 ) )
F_31 ( V_88 ) ;
V_88 -> V_91 ++ ;
F_49 ( V_88 -> V_89 , V_3 ) ;
}
F_50 ( V_3 ) ;
return V_88 ? 0 : - 1 ;
}
static char * F_51 ( char * V_4 , char * V_114 , int V_115 )
{
char * V_116 = NULL ;
T_3 V_30 ;
if ( ! V_4 )
V_4 = V_114 ;
if ( V_115 >= 10 )
goto V_97;
if ( V_115 < 0 )
V_30 = strlen ( V_4 ) + sizeof( L_45 ) ;
else
V_30 = strlen ( V_114 ) + sizeof( L_46 ) ;
V_116 = malloc ( V_30 ) ;
if ( ! V_116 )
goto V_97;
if ( V_115 < 0 )
snprintf ( V_116 , V_30 , L_47 , V_4 ) ;
else
snprintf ( V_116 , V_30 , L_48 , V_114 , V_115 ) ;
V_97:
if ( V_4 != V_114 )
free ( V_4 ) ;
return V_116 ;
}
static int F_52 ( struct V_34 * V_35 ,
struct V_1 * type ,
struct V_16 * V_7 )
{
struct V_1 * V_117 = NULL ;
char * V_4 ;
int V_115 = 1 ;
int V_9 ;
if ( V_7 -> V_43 != V_7 -> V_4 )
return F_53 ( V_35 , type ,
( char * ) V_7 -> V_43 ) ;
V_4 = V_7 -> V_4 ;
if ( F_54 ( V_4 ) )
V_4 = F_51 ( V_4 , V_7 -> V_4 , - 1 ) ;
if ( ! V_4 ) {
F_4 ( L_49 ) ;
return - 1 ;
}
while ( ( V_117 = F_18 ( V_35 , V_4 ) ) ) {
F_19 ( V_117 ) ;
V_4 = F_51 ( V_4 , V_7 -> V_4 , V_115 ++ ) ;
if ( ! V_4 ) {
F_4 ( L_50 , V_7 -> V_4 ) ;
return - 1 ;
}
}
V_9 = F_53 ( V_35 , type , V_4 ) ;
if ( ! V_9 )
V_7 -> V_43 = V_4 ;
return V_9 ;
}
static int F_55 ( struct V_12 * V_13 ,
struct V_16 * V_49 ,
struct V_34 * V_35 )
{
struct V_16 * V_7 ;
int V_9 ;
for ( V_7 = V_49 ; V_7 ; V_7 = V_7 -> V_50 ) {
struct V_1 * type ;
unsigned long V_17 = V_7 -> V_17 ;
F_8 ( L_51 , V_7 -> V_4 ) ;
type = F_12 ( V_13 , V_7 ) ;
if ( ! type )
return - 1 ;
if ( V_17 & V_18 )
V_17 &= ~ V_44 ;
if ( V_17 & V_44 )
type = F_56 ( type , V_7 -> V_48 ) ;
V_9 = F_52 ( V_35 , type , V_7 ) ;
if ( V_17 & V_44 )
F_19 ( type ) ;
if ( V_9 ) {
F_4 ( L_52 ,
V_7 -> V_4 , V_9 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_57 ( struct V_12 * V_13 ,
struct V_51 * V_52 ,
struct V_34 * V_118 )
{
struct V_16 * V_53 = V_52 -> V_54 -> V_55 . V_53 ;
struct V_16 * V_49 = V_52 -> V_54 -> V_55 . V_49 ;
int V_9 ;
V_9 = F_55 ( V_13 , V_53 , V_118 ) ;
if ( ! V_9 )
V_9 = F_55 ( V_13 , V_49 , V_118 ) ;
return V_9 ;
}
static int F_58 ( struct V_12 * V_13 ,
struct V_34 * V_118 )
{
struct V_1 * V_56 = V_13 -> V_14 . V_26 ;
struct V_1 * V_119 = V_13 -> V_14 . V_120 ;
struct V_1 * V_57 ;
int V_9 ;
V_9 = F_53 ( V_118 , V_56 , L_14 ) ;
if ( V_9 )
return V_9 ;
V_57 = F_59 ( V_119 , L_14 ) ;
if ( ! V_57 )
return - 1 ;
return F_53 ( V_118 , V_57 , L_18 ) ;
}
static int F_60 ( struct V_12 * V_13 , struct V_51 * V_52 ,
struct V_34 * V_35 )
{
T_1 type = V_52 -> V_67 . V_68 ;
#define F_61 ( T_4 , V_117 , T_5 ) \
do { \
pr2(" field '%s'\n", n); \
if (bt_ctf_event_class_add_field(cl, t, n)) { \
pr_err("Failed to add field '%s';\n", n); \
return -1; \
} \
} while (0)
if ( type & V_69 )
F_61 ( V_35 , V_13 -> V_14 . V_22 , L_23 ) ;
if ( type & V_71 ) {
F_61 ( V_35 , V_13 -> V_14 . V_25 , L_24 ) ;
F_61 ( V_35 , V_13 -> V_14 . V_25 , L_25 ) ;
}
if ( ( type & V_74 ) ||
( type & V_75 ) )
F_61 ( V_35 , V_13 -> V_14 . T_1 , L_26 ) ;
if ( type & V_77 )
F_61 ( V_35 , V_13 -> V_14 . T_1 , L_27 ) ;
if ( type & V_79 )
F_61 ( V_35 , V_13 -> V_14 . T_1 , L_28 ) ;
if ( type & V_81 )
F_61 ( V_35 , V_13 -> V_14 . T_1 , L_29 ) ;
if ( type & V_83 )
F_61 ( V_35 , V_13 -> V_14 . T_1 , L_30 ) ;
if ( type & V_85 )
F_61 ( V_35 , V_13 -> V_14 . T_1 , L_31 ) ;
#undef F_61
return 0 ;
}
static int F_62 ( struct V_12 * V_13 , struct V_51 * V_52 )
{
struct V_34 * V_35 ;
struct V_108 * V_109 ;
const char * V_4 = F_63 ( V_52 ) ;
int V_9 ;
F_33 ( L_53 , V_4 , V_52 -> V_67 . type ) ;
V_35 = F_64 ( V_4 ) ;
if ( ! V_35 )
return - 1 ;
V_9 = F_60 ( V_13 , V_52 , V_35 ) ;
if ( V_9 )
goto V_10;
if ( V_52 -> V_67 . type == V_113 ) {
V_9 = F_57 ( V_13 , V_52 , V_35 ) ;
if ( V_9 )
goto V_10;
}
if ( F_48 ( V_52 ) ) {
V_9 = F_58 ( V_13 , V_35 ) ;
if ( V_9 )
goto V_10;
}
V_9 = F_65 ( V_13 -> V_96 , V_35 ) ;
if ( V_9 ) {
F_33 ( L_54 ) ;
goto V_10;
}
V_109 = malloc ( sizeof( * V_109 ) ) ;
if ( ! V_109 )
goto V_10;
V_109 -> V_35 = V_35 ;
V_52 -> V_109 = V_109 ;
return 0 ;
V_10:
F_66 ( V_35 ) ;
F_4 ( L_55 , V_4 ) ;
return - 1 ;
}
static int F_67 ( struct V_12 * V_13 , struct V_121 * V_122 )
{
struct V_123 * V_124 = V_122 -> V_124 ;
struct V_51 * V_52 ;
int V_9 ;
F_68 (evlist, evsel) {
V_9 = F_62 ( V_13 , V_52 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_69 ( struct V_12 * V_13 ,
struct V_121 * V_122 T_2 )
{
int V_9 ;
V_9 = F_70 ( V_13 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_71 ( V_13 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_72 ( V_13 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static void F_73 ( struct V_121 * V_122 )
{
struct V_123 * V_124 = V_122 -> V_124 ;
struct V_51 * V_52 ;
F_68 (evlist, evsel) {
struct V_108 * V_109 ;
V_109 = V_52 -> V_109 ;
F_66 ( V_109 -> V_35 ) ;
F_74 ( & V_52 -> V_109 ) ;
}
F_75 ( V_124 ) ;
V_122 -> V_124 = NULL ;
}
static int F_76 ( struct V_12 * V_13 , struct V_121 * V_122 )
{
struct V_87 * * V_89 ;
struct V_125 * V_126 = & V_122 -> V_112 ;
int V_127 ;
V_127 = V_126 -> V_128 . V_129 ? : V_130 ;
V_89 = F_14 ( sizeof( * V_89 ) * V_127 ) ;
if ( ! V_89 ) {
F_4 ( L_56 ) ;
return - V_131 ;
}
V_13 -> V_89 = V_89 ;
V_13 -> V_99 = V_127 ;
return 0 ;
}
static void F_77 ( struct V_12 * V_13 )
{
int V_90 ;
for ( V_90 = 0 ; V_90 < V_13 -> V_99 ; V_90 ++ )
F_39 ( V_13 -> V_89 [ V_90 ] ) ;
free ( V_13 -> V_89 ) ;
}
static int F_78 ( struct V_12 * V_13 ,
struct V_121 * V_122 )
{
struct V_125 * V_112 = & V_122 -> V_112 ;
struct V_132 * V_95 = V_13 -> V_95 ;
#define F_79 ( T_6 , T_7 ) \
do { \
if (bt_ctf_writer_add_environment_field(writer, __n, __v)) \
return -1; \
} while (0)
F_79 ( L_57 , V_112 -> V_128 . V_133 ) ;
F_79 ( L_58 , L_59 ) ;
F_79 ( L_60 , V_112 -> V_128 . V_134 ) ;
F_79 ( L_61 , V_112 -> V_128 . V_135 ) ;
F_79 ( L_62 , V_112 -> V_128 . V_136 ) ;
F_79 ( L_63 , L_64 ) ;
F_79 ( L_65 , L_66 ) ;
#undef F_79
return 0 ;
}
static int F_80 ( struct V_12 * V_13 )
{
struct V_137 * clock = V_13 -> clock ;
F_81 ( clock , L_67 ) ;
#define F_82 ( T_6 , T_7 ) \
do { \
if (bt_ctf_clock_set_##__n(clock, __v)) \
return -1; \
} while (0)
F_82 ( V_138 , 1000000000 ) ;
F_82 ( V_139 , 0 ) ;
F_82 ( V_42 , 0 ) ;
F_82 ( V_140 , 10 ) ;
F_82 ( V_141 , 0 ) ;
#undef F_82
return 0 ;
}
static struct V_1 * F_83 ( int V_23 , bool V_8 , bool V_142 )
{
struct V_1 * type ;
type = F_84 ( V_23 ) ;
if ( ! type )
return NULL ;
if ( V_8 &&
F_85 ( type , 1 ) )
goto V_10;
if ( V_142 &&
F_86 ( type , V_143 ) )
goto V_10;
#if V_144 == V_145
F_87 ( type , V_146 ) ;
#else
F_87 ( type , V_147 ) ;
#endif
F_8 ( L_68 ,
V_23 , V_8 ? L_69 : L_70 , V_142 ? L_71 : L_70 ) ;
return type ;
V_10:
F_19 ( type ) ;
return NULL ;
}
static void F_88 ( struct V_12 * V_13 )
{
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < F_89 ( V_13 -> V_14 . V_148 ) ; V_31 ++ )
F_19 ( V_13 -> V_14 . V_148 [ V_31 ] ) ;
}
static int F_90 ( struct V_12 * V_13 )
{
#define F_91 ( type , V_23 , V_8 , V_142 ) \
do { \
(type) = create_int_type(size, sign, hex); \
if (!(type)) \
goto err; \
} while (0)
F_91 ( V_13 -> V_14 . V_24 , 64 , true , false ) ;
F_91 ( V_13 -> V_14 . T_1 , 64 , false , false ) ;
F_91 ( V_13 -> V_14 . V_25 , 32 , true , false ) ;
F_91 ( V_13 -> V_14 . V_26 , 32 , false , false ) ;
F_91 ( V_13 -> V_14 . V_120 , 32 , false , true ) ;
F_91 ( V_13 -> V_14 . V_22 , 64 , false , true ) ;
V_13 -> V_14 . string = F_92 () ;
if ( V_13 -> V_14 . string )
return 0 ;
V_10:
F_88 ( V_13 ) ;
F_4 ( L_72 ) ;
return - 1 ;
}
static void F_93 ( struct V_12 * V_13 )
{
F_88 ( V_13 ) ;
F_94 ( V_13 -> clock ) ;
F_77 ( V_13 ) ;
F_95 ( V_13 -> V_96 ) ;
F_96 ( V_13 -> V_95 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
}
static int F_97 ( struct V_12 * V_13 , const char * V_149 )
{
struct V_132 * V_95 ;
struct V_150 * V_96 ;
struct V_137 * clock ;
struct V_1 * V_151 ;
int V_9 ;
V_95 = F_98 ( V_149 ) ;
if ( ! V_95 )
goto V_10;
V_13 -> V_95 = V_95 ;
clock = F_99 ( L_73 ) ;
if ( ! clock ) {
F_33 ( L_74 ) ;
goto V_152;
}
V_13 -> clock = clock ;
if ( F_80 ( V_13 ) ) {
F_33 ( L_75 ) ;
goto V_152;
}
V_96 = F_100 ( L_76 ) ;
if ( ! V_96 ) {
F_33 ( L_77 ) ;
goto V_152;
}
V_13 -> V_96 = V_96 ;
if ( F_101 ( V_96 , clock ) ) {
F_33 ( L_78 ) ;
goto V_152;
}
if ( F_90 ( V_13 ) )
goto V_152;
V_151 = F_102 ( V_96 ) ;
if ( ! V_151 )
goto V_152;
V_9 = F_103 ( V_151 , V_13 -> V_14 . V_26 , L_37 ) ;
F_19 ( V_151 ) ;
if ( V_9 )
goto V_152;
if ( F_104 ( V_95 , clock ) ) {
F_33 ( L_79 ) ;
goto V_152;
}
return 0 ;
V_152:
F_93 ( V_13 ) ;
V_10:
F_4 ( L_80 ) ;
return - 1 ;
}
static int F_105 ( struct V_12 * V_13 )
{
int V_90 , V_9 = 0 ;
for ( V_90 = 0 ; V_90 < V_13 -> V_99 && ! V_9 ; V_90 ++ )
V_9 = F_31 ( V_13 -> V_89 [ V_90 ] ) ;
return V_9 ;
}
static int F_106 ( const char * V_153 , const char * V_154 , void * V_155 )
{
struct V_106 * V_107 = V_155 ;
if ( ! strcmp ( V_153 , L_81 ) ) {
V_107 -> V_156 = F_107 ( V_153 , V_154 ) ;
return 0 ;
}
return 0 ;
}
int F_108 ( const char * V_157 , const char * V_149 ,
struct V_158 * V_159 )
{
struct V_121 * V_122 ;
struct V_160 V_161 = {
. V_149 = V_157 ,
. V_162 = V_163 ,
. V_164 = V_159 -> V_164 ,
} ;
struct V_106 V_107 = {
. V_102 = {
. V_37 = F_42 ,
. V_165 = V_166 ,
. V_167 = V_168 ,
. V_169 = V_170 ,
. exit = V_171 ,
. V_172 = V_173 ,
. V_174 = V_175 ,
. V_176 = V_177 ,
. V_178 = V_179 ,
. V_180 = true ,
. V_181 = true ,
} ,
} ;
struct V_12 * V_13 = & V_107 . V_95 ;
int V_10 ;
if ( V_159 -> V_182 ) {
V_107 . V_102 . V_169 = V_183 ;
V_107 . V_102 . exit = V_184 ;
V_107 . V_102 . V_172 = V_185 ;
}
V_10 = F_109 ( F_106 , & V_107 ) ;
if ( V_10 )
return V_10 ;
if ( F_97 ( V_13 , V_149 ) )
return - 1 ;
V_10 = - 1 ;
V_122 = F_110 ( & V_161 , 0 , & V_107 . V_102 ) ;
if ( ! V_122 )
goto V_186;
if ( V_107 . V_156 ) {
F_111 ( & V_122 -> V_180 ,
V_107 . V_156 ) ;
}
if ( F_78 ( V_13 , V_122 ) )
goto V_187;
if ( F_67 ( V_13 , V_122 ) )
goto V_187;
if ( V_159 -> V_182 && F_69 ( V_13 , V_122 ) )
goto V_187;
if ( F_76 ( V_13 , V_122 ) )
goto V_187;
V_10 = F_112 ( V_122 ) ;
if ( ! V_10 )
V_10 = F_105 ( V_13 ) ;
else
F_4 ( L_82 ) ;
fprintf ( V_188 ,
L_83 ,
V_161 . V_149 , V_149 ) ;
fprintf ( V_188 ,
L_84 V_11 L_85 ,
( double ) V_107 . V_111 / 1024.0 / 1024.0 ,
V_107 . V_110 ) ;
if ( ! V_107 . V_189 )
fprintf ( V_188 , L_86 ) ;
else
fprintf ( V_188 , L_87 V_11 L_88 , V_107 . V_189 ) ;
F_73 ( V_122 ) ;
F_113 ( V_122 ) ;
F_93 ( V_13 ) ;
return V_10 ;
V_187:
F_113 ( V_122 ) ;
V_186:
F_93 ( V_13 ) ;
F_4 ( L_89 ) ;
return V_10 ;
}
