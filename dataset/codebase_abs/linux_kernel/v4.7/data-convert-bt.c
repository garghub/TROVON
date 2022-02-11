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
static int F_12 ( struct V_6 * V_7 , const char * string )
{
char * V_28 = NULL ;
T_2 V_29 = strlen ( string ) , V_30 , V_31 ;
int V_10 ;
for ( V_30 = V_31 = 0 ; V_30 < V_29 ; V_30 ++ , V_31 ++ ) {
if ( isprint ( string [ V_30 ] ) ) {
if ( ! V_28 )
continue;
V_28 [ V_31 ] = string [ V_30 ] ;
} else {
char V_32 [ 5 ] ;
snprintf ( V_32 , sizeof( V_32 ) , L_6 ,
( unsigned int ) ( string [ V_30 ] ) & 0xff ) ;
if ( ! V_28 ) {
V_28 = F_13 ( V_30 + ( V_29 - V_30 ) * 4 + 2 ) ;
if ( ! V_28 ) {
F_4 ( L_7 , string ) ;
return F_14 ( V_7 , L_8 ) ;
}
if ( V_30 > 0 )
strncpy ( V_28 , string , V_30 ) ;
}
strncat ( V_28 + V_31 , V_32 , 4 ) ;
V_31 += 3 ;
}
}
if ( ! V_28 )
return F_14 ( V_7 , string ) ;
V_10 = F_14 ( V_7 , V_28 ) ;
free ( V_28 ) ;
return V_10 ;
}
static int F_15 ( struct V_12 * V_13 ,
struct V_33 * V_34 ,
struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_14 * V_37 )
{
struct V_1 * type ;
struct V_6 * V_38 ;
struct V_6 * V_7 ;
const char * V_4 = V_37 -> V_4 ;
void * V_17 = V_36 -> V_39 ;
unsigned long V_15 = V_37 -> V_15 ;
unsigned int V_40 ;
unsigned int V_30 ;
unsigned int V_41 ;
unsigned int V_29 ;
int V_9 ;
V_4 = V_37 -> V_42 ;
V_41 = V_37 -> V_41 ;
V_29 = V_37 -> V_22 ;
if ( V_15 & V_16 )
V_15 &= ~ V_43 ;
if ( V_15 & V_44 ) {
unsigned long long V_45 ;
V_45 = F_16 ( V_37 -> V_3 -> V_46 ,
V_17 + V_41 , V_29 ) ;
V_41 = V_45 ;
V_29 = V_41 >> 16 ;
V_41 &= 0xffff ;
}
if ( V_15 & V_43 ) {
type = F_17 (
V_34 , V_4 ) ;
V_38 = F_3 ( type ) ;
F_18 ( type ) ;
if ( ! V_38 ) {
F_4 ( L_9 , V_4 ) ;
return - 1 ;
}
V_29 = V_37 -> V_22 / V_37 -> V_47 ;
V_40 = V_37 -> V_47 ;
} else {
V_40 = 1 ;
V_38 = NULL ;
}
type = F_10 ( V_13 , V_37 ) ;
for ( V_30 = 0 ; V_30 < V_40 ; V_30 ++ ) {
if ( V_15 & V_43 )
V_7 = F_19 ( V_38 , V_30 ) ;
else
V_7 = F_3 ( type ) ;
if ( ! V_7 ) {
F_4 ( L_1 , V_4 ) ;
return - 1 ;
}
if ( V_15 & V_16 )
V_9 = F_12 ( V_7 , V_17 + V_41 + V_30 * V_29 ) ;
else {
unsigned long long V_26 ;
V_26 = F_16 (
V_37 -> V_3 -> V_46 ,
V_17 + V_41 + V_30 * V_29 , V_29 ) ;
if ( ! ( V_15 & V_18 ) )
V_9 = F_6 (
V_7 , V_26 ) ;
else
V_9 = F_5 (
V_7 , F_11 ( V_26 , V_29 ) ) ;
}
if ( V_9 ) {
F_4 ( L_10 , V_4 ) ;
goto V_48;
}
if ( ! ( V_15 & V_43 ) ) {
V_9 = F_7 ( V_3 , V_4 , V_7 ) ;
if ( V_9 ) {
F_4 ( L_3 , V_4 ) ;
goto V_48;
}
}
F_9 ( V_7 ) ;
}
if ( V_15 & V_43 ) {
V_9 = F_7 ( V_3 , V_4 , V_38 ) ;
if ( V_9 ) {
F_4 ( L_11 , V_4 ) ;
return - 1 ;
}
F_9 ( V_38 ) ;
}
return 0 ;
V_48:
F_9 ( V_7 ) ;
return - 1 ;
}
static int F_20 ( struct V_12 * V_13 ,
struct V_33 * V_34 ,
struct V_2 * V_3 ,
struct V_14 * V_49 ,
struct V_35 * V_36 )
{
struct V_14 * V_7 ;
int V_9 ;
for ( V_7 = V_49 ; V_7 ; V_7 = V_7 -> V_50 ) {
V_9 = F_15 ( V_13 , V_34 , V_3 , V_36 ,
V_7 ) ;
if ( V_9 )
return - 1 ;
}
return 0 ;
}
static int F_21 ( struct V_12 * V_13 ,
struct V_33 * V_34 ,
struct V_2 * V_3 ,
struct V_51 * V_52 ,
struct V_35 * V_36 )
{
struct V_14 * V_53 = V_52 -> V_54 -> V_55 . V_53 ;
struct V_14 * V_49 = V_52 -> V_54 -> V_55 . V_49 ;
int V_9 ;
V_9 = F_20 ( V_13 , V_34 , V_3 ,
V_53 , V_36 ) ;
if ( ! V_9 )
V_9 = F_20 ( V_13 , V_34 , V_3 ,
V_49 , V_36 ) ;
return V_9 ;
}
static int
F_22 ( struct V_33 * V_34 ,
struct V_2 * V_3 ,
struct V_35 * V_36 )
{
struct V_1 * V_56 , * V_57 ;
struct V_6 * V_58 , * V_59 ;
unsigned int V_60 = V_36 -> V_60 ;
unsigned int V_61 = V_60 / sizeof( V_25 ) ;
unsigned int V_30 ;
int V_9 ;
if ( V_61 * sizeof( V_25 ) != V_60 )
F_23 ( L_12 ,
V_60 , V_61 * sizeof( V_25 ) - V_60 ) ;
V_56 = F_17 ( V_34 , L_13 ) ;
V_58 = F_3 ( V_56 ) ;
if ( ! V_58 ) {
F_4 ( L_14 ) ;
V_9 = - 1 ;
goto V_62;
}
V_9 = F_6 ( V_58 , V_61 ) ;
if ( V_9 ) {
F_4 ( L_15 ) ;
goto V_63;
}
V_9 = F_7 ( V_3 , L_13 , V_58 ) ;
if ( V_9 ) {
F_4 ( L_16 ) ;
goto V_63;
}
V_57 = F_17 ( V_34 , L_17 ) ;
V_59 = F_3 ( V_57 ) ;
if ( ! V_59 ) {
F_4 ( L_18 ) ;
V_9 = - 1 ;
goto V_64;
}
V_9 = F_24 ( V_59 , V_58 ) ;
if ( V_9 ) {
F_4 ( L_19 ) ;
goto V_65;
}
for ( V_30 = 0 ; V_30 < V_61 ; V_30 ++ ) {
struct V_6 * V_66 =
F_25 ( V_59 , V_30 ) ;
V_9 = F_6 ( V_66 ,
( ( V_25 * ) ( V_36 -> V_39 ) ) [ V_30 ] ) ;
F_9 ( V_66 ) ;
if ( V_9 ) {
F_4 ( L_20 , V_30 ) ;
goto V_65;
}
}
V_9 = F_7 ( V_3 , L_17 , V_59 ) ;
if ( V_9 )
F_4 ( L_21 ) ;
V_65:
F_9 ( V_59 ) ;
V_64:
F_18 ( V_57 ) ;
V_63:
F_9 ( V_58 ) ;
V_62:
F_18 ( V_56 ) ;
return V_9 ;
}
static int F_26 ( struct V_12 * V_13 ,
struct V_2 * V_3 ,
struct V_51 * V_52 ,
struct V_35 * V_36 )
{
T_1 type = V_52 -> V_67 . V_68 ;
int V_9 ;
if ( type & V_69 ) {
V_9 = F_27 ( V_13 , V_3 , L_22 , V_36 -> V_70 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_71 ) {
V_9 = F_28 ( V_13 , V_3 , L_23 , V_36 -> V_72 ) ;
if ( V_9 )
return - 1 ;
V_9 = F_28 ( V_13 , V_3 , L_24 , V_36 -> V_73 ) ;
if ( V_9 )
return - 1 ;
}
if ( ( type & V_74 ) ||
( type & V_75 ) ) {
V_9 = F_29 ( V_13 , V_3 , L_25 , V_36 -> V_76 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_77 ) {
V_9 = F_29 ( V_13 , V_3 , L_26 , V_36 -> V_78 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_79 ) {
V_9 = F_29 ( V_13 , V_3 , L_27 , V_36 -> V_80 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_81 ) {
V_9 = F_29 ( V_13 , V_3 , L_28 , V_36 -> V_82 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_83 ) {
V_9 = F_29 ( V_13 , V_3 , L_29 ,
V_36 -> V_84 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_85 ) {
V_9 = F_29 ( V_13 , V_3 , L_30 ,
V_36 -> V_86 ) ;
if ( V_9 )
return - 1 ;
}
return 0 ;
}
static int F_30 ( struct V_87 * V_88 )
{
int V_10 = 0 ;
if ( V_88 ) {
V_10 = F_31 ( V_88 -> V_89 ) ;
if ( V_10 )
F_4 ( L_31 , V_88 -> V_90 ) ;
F_32 ( L_32 ,
V_88 -> V_90 , V_88 -> V_91 ) ;
V_88 -> V_91 = 0 ;
}
return V_10 ;
}
static struct V_87 * F_33 ( struct V_12 * V_13 , int V_90 )
{
struct V_87 * V_88 ;
struct V_6 * V_92 = NULL ;
struct V_6 * V_93 = NULL ;
struct V_94 * V_89 = NULL ;
int V_9 ;
V_88 = F_13 ( sizeof( * V_88 ) ) ;
if ( ! V_88 ) {
F_4 ( L_33 ) ;
return NULL ;
}
V_89 = F_34 ( V_13 -> V_95 , V_13 -> V_96 ) ;
if ( ! V_89 ) {
F_4 ( L_34 ) ;
goto V_97;
}
V_92 = F_35 ( V_89 ) ;
if ( ! V_92 ) {
F_4 ( L_35 ) ;
goto V_97;
}
V_93 = F_36 ( V_92 , L_36 ) ;
F_9 ( V_92 ) ;
if ( ! V_93 ) {
F_4 ( L_37 ) ;
goto V_97;
}
V_9 = F_6 ( V_93 , ( V_25 ) V_90 ) ;
if ( V_9 ) {
F_4 ( L_38 ) ;
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
F_37 ( V_89 ) ;
free ( V_88 ) ;
return NULL ;
}
static void F_38 ( struct V_87 * V_88 )
{
if ( V_88 ) {
F_37 ( V_88 -> V_89 ) ;
free ( V_88 ) ;
}
}
static struct V_87 * V_87 ( struct V_12 * V_13 , int V_90 )
{
struct V_87 * V_88 = V_13 -> V_89 [ V_90 ] ;
if ( ! V_88 ) {
V_88 = F_33 ( V_13 , V_90 ) ;
V_13 -> V_89 [ V_90 ] = V_88 ;
}
return V_88 ;
}
static int F_39 ( struct V_12 * V_13 , struct V_35 * V_36 ,
struct V_51 * V_52 )
{
int V_90 = 0 ;
if ( V_52 -> V_67 . V_68 & V_98 )
V_90 = V_36 -> V_90 ;
if ( V_90 > V_13 -> V_99 ) {
F_4 ( L_39 ,
V_90 , V_13 -> V_99 ) ;
V_90 = 0 ;
}
return V_90 ;
}
static bool F_40 ( struct V_87 * V_88 )
{
return V_88 -> V_91 >= V_100 ;
}
static int F_41 ( struct V_101 * V_102 ,
union V_103 * V_104 ,
struct V_35 * V_36 ,
struct V_51 * V_52 ,
struct V_105 * V_105 V_106 )
{
struct V_107 * V_108 = F_42 ( V_102 , struct V_107 , V_102 ) ;
struct V_109 * V_110 = V_52 -> V_110 ;
struct V_12 * V_13 = & V_108 -> V_95 ;
struct V_87 * V_88 ;
struct V_33 * V_34 ;
struct V_2 * V_3 ;
int V_9 ;
if ( F_43 ( ! V_110 , L_40 ) )
return 0 ;
V_34 = V_110 -> V_34 ;
V_108 -> V_111 ++ ;
V_108 -> V_112 += V_104 -> V_113 . V_22 ;
F_44 ( V_36 -> time , L_41 V_11 L_42 , V_108 -> V_111 ) ;
V_3 = F_45 ( V_34 ) ;
if ( ! V_3 ) {
F_4 ( L_43 ) ;
return - 1 ;
}
F_46 ( V_13 -> clock , V_36 -> time ) ;
V_9 = F_26 ( V_13 , V_3 , V_52 , V_36 ) ;
if ( V_9 )
return - 1 ;
if ( V_52 -> V_67 . type == V_114 ) {
V_9 = F_21 ( V_13 , V_34 , V_3 ,
V_52 , V_36 ) ;
if ( V_9 )
return - 1 ;
}
if ( F_47 ( V_52 ) ) {
V_9 = F_22 ( V_34 , V_3 , V_36 ) ;
if ( V_9 )
return - 1 ;
}
V_88 = V_87 ( V_13 , F_39 ( V_13 , V_36 , V_52 ) ) ;
if ( V_88 ) {
if ( F_40 ( V_88 ) )
F_30 ( V_88 ) ;
V_88 -> V_91 ++ ;
F_48 ( V_88 -> V_89 , V_3 ) ;
}
F_49 ( V_3 ) ;
return V_88 ? 0 : - 1 ;
}
static char * F_50 ( char * V_4 , char * V_115 , int V_116 )
{
char * V_117 = NULL ;
T_2 V_29 ;
if ( ! V_4 )
V_4 = V_115 ;
if ( V_116 >= 10 )
goto V_97;
if ( V_116 < 0 )
V_29 = strlen ( V_4 ) + sizeof( L_44 ) ;
else
V_29 = strlen ( V_115 ) + sizeof( L_45 ) ;
V_117 = malloc ( V_29 ) ;
if ( ! V_117 )
goto V_97;
if ( V_116 < 0 )
snprintf ( V_117 , V_29 , L_46 , V_4 ) ;
else
snprintf ( V_117 , V_29 , L_47 , V_115 , V_116 ) ;
V_97:
if ( V_4 != V_115 )
free ( V_4 ) ;
return V_117 ;
}
static int F_51 ( struct V_33 * V_34 ,
struct V_1 * type ,
struct V_14 * V_7 )
{
struct V_1 * V_118 = NULL ;
char * V_4 ;
int V_116 = 1 ;
int V_9 ;
if ( V_7 -> V_42 != V_7 -> V_4 )
return F_52 ( V_34 , type ,
( char * ) V_7 -> V_42 ) ;
V_4 = V_7 -> V_4 ;
if ( F_53 ( V_4 ) )
V_4 = F_50 ( V_4 , V_7 -> V_4 , - 1 ) ;
if ( ! V_4 ) {
F_4 ( L_48 ) ;
return - 1 ;
}
while ( ( V_118 = F_17 ( V_34 , V_4 ) ) ) {
F_18 ( V_118 ) ;
V_4 = F_50 ( V_4 , V_7 -> V_4 , V_116 ++ ) ;
if ( ! V_4 ) {
F_4 ( L_49 , V_7 -> V_4 ) ;
return - 1 ;
}
}
V_9 = F_52 ( V_34 , type , V_4 ) ;
if ( ! V_9 )
V_7 -> V_42 = V_4 ;
return V_9 ;
}
static int F_54 ( struct V_12 * V_13 ,
struct V_14 * V_49 ,
struct V_33 * V_34 )
{
struct V_14 * V_7 ;
int V_9 ;
for ( V_7 = V_49 ; V_7 ; V_7 = V_7 -> V_50 ) {
struct V_1 * type ;
unsigned long V_15 = V_7 -> V_15 ;
F_8 ( L_50 , V_7 -> V_4 ) ;
type = F_10 ( V_13 , V_7 ) ;
if ( ! type )
return - 1 ;
if ( V_15 & V_16 )
V_15 &= ~ V_43 ;
if ( V_15 & V_43 )
type = F_55 ( type , V_7 -> V_47 ) ;
V_9 = F_51 ( V_34 , type , V_7 ) ;
if ( V_15 & V_43 )
F_18 ( type ) ;
if ( V_9 ) {
F_4 ( L_51 ,
V_7 -> V_4 , V_9 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_56 ( struct V_12 * V_13 ,
struct V_51 * V_52 ,
struct V_33 * V_119 )
{
struct V_14 * V_53 = V_52 -> V_54 -> V_55 . V_53 ;
struct V_14 * V_49 = V_52 -> V_54 -> V_55 . V_49 ;
int V_9 ;
V_9 = F_54 ( V_13 , V_53 , V_119 ) ;
if ( ! V_9 )
V_9 = F_54 ( V_13 , V_49 , V_119 ) ;
return V_9 ;
}
static int F_57 ( struct V_12 * V_13 ,
struct V_33 * V_119 )
{
struct V_1 * V_56 = V_13 -> V_17 . V_25 ;
struct V_1 * V_120 = V_13 -> V_17 . V_121 ;
struct V_1 * V_57 ;
int V_9 ;
V_9 = F_52 ( V_119 , V_56 , L_13 ) ;
if ( V_9 )
return V_9 ;
V_57 = F_58 ( V_120 , L_13 ) ;
if ( ! V_57 )
return - 1 ;
return F_52 ( V_119 , V_57 , L_17 ) ;
}
static int F_59 ( struct V_12 * V_13 , struct V_51 * V_52 ,
struct V_33 * V_34 )
{
T_1 type = V_52 -> V_67 . V_68 ;
#define F_60 ( T_3 , V_118 , T_4 ) \
do { \
pr2(" field '%s'\n", n); \
if (bt_ctf_event_class_add_field(cl, t, n)) { \
pr_err("Failed to add field '%s';\n", n); \
return -1; \
} \
} while (0)
if ( type & V_69 )
F_60 ( V_34 , V_13 -> V_17 . V_21 , L_22 ) ;
if ( type & V_71 ) {
F_60 ( V_34 , V_13 -> V_17 . V_24 , L_23 ) ;
F_60 ( V_34 , V_13 -> V_17 . V_24 , L_24 ) ;
}
if ( ( type & V_74 ) ||
( type & V_75 ) )
F_60 ( V_34 , V_13 -> V_17 . T_1 , L_25 ) ;
if ( type & V_77 )
F_60 ( V_34 , V_13 -> V_17 . T_1 , L_26 ) ;
if ( type & V_79 )
F_60 ( V_34 , V_13 -> V_17 . T_1 , L_27 ) ;
if ( type & V_81 )
F_60 ( V_34 , V_13 -> V_17 . T_1 , L_28 ) ;
if ( type & V_83 )
F_60 ( V_34 , V_13 -> V_17 . T_1 , L_29 ) ;
if ( type & V_85 )
F_60 ( V_34 , V_13 -> V_17 . T_1 , L_30 ) ;
#undef F_60
return 0 ;
}
static int F_61 ( struct V_12 * V_13 , struct V_51 * V_52 )
{
struct V_33 * V_34 ;
struct V_109 * V_110 ;
const char * V_4 = F_62 ( V_52 ) ;
int V_9 ;
F_32 ( L_52 , V_4 , V_52 -> V_67 . type ) ;
V_34 = F_63 ( V_4 ) ;
if ( ! V_34 )
return - 1 ;
V_9 = F_59 ( V_13 , V_52 , V_34 ) ;
if ( V_9 )
goto V_10;
if ( V_52 -> V_67 . type == V_114 ) {
V_9 = F_56 ( V_13 , V_52 , V_34 ) ;
if ( V_9 )
goto V_10;
}
if ( F_47 ( V_52 ) ) {
V_9 = F_57 ( V_13 , V_34 ) ;
if ( V_9 )
goto V_10;
}
V_9 = F_64 ( V_13 -> V_96 , V_34 ) ;
if ( V_9 ) {
F_32 ( L_53 ) ;
goto V_10;
}
V_110 = malloc ( sizeof( * V_110 ) ) ;
if ( ! V_110 )
goto V_10;
V_110 -> V_34 = V_34 ;
V_52 -> V_110 = V_110 ;
return 0 ;
V_10:
F_65 ( V_34 ) ;
F_4 ( L_54 , V_4 ) ;
return - 1 ;
}
static int F_66 ( struct V_12 * V_13 , struct V_122 * V_123 )
{
struct V_124 * V_125 = V_123 -> V_125 ;
struct V_51 * V_52 ;
int V_9 ;
F_67 (evlist, evsel) {
V_9 = F_61 ( V_13 , V_52 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static void F_68 ( struct V_122 * V_123 )
{
struct V_124 * V_125 = V_123 -> V_125 ;
struct V_51 * V_52 ;
F_67 (evlist, evsel) {
struct V_109 * V_110 ;
V_110 = V_52 -> V_110 ;
F_65 ( V_110 -> V_34 ) ;
F_69 ( & V_52 -> V_110 ) ;
}
F_70 ( V_125 ) ;
V_123 -> V_125 = NULL ;
}
static int F_71 ( struct V_12 * V_13 , struct V_122 * V_123 )
{
struct V_87 * * V_89 ;
struct V_126 * V_127 = & V_123 -> V_113 ;
int V_128 ;
V_128 = V_127 -> V_129 . V_130 ? : V_131 ;
V_89 = F_13 ( sizeof( * V_89 ) * V_128 ) ;
if ( ! V_89 ) {
F_4 ( L_55 ) ;
return - V_132 ;
}
V_13 -> V_89 = V_89 ;
V_13 -> V_99 = V_128 ;
return 0 ;
}
static void F_72 ( struct V_12 * V_13 )
{
int V_90 ;
for ( V_90 = 0 ; V_90 < V_13 -> V_99 ; V_90 ++ )
F_38 ( V_13 -> V_89 [ V_90 ] ) ;
free ( V_13 -> V_89 ) ;
}
static int F_73 ( struct V_12 * V_13 ,
struct V_122 * V_123 )
{
struct V_126 * V_113 = & V_123 -> V_113 ;
struct V_133 * V_95 = V_13 -> V_95 ;
#define F_74 ( T_5 , T_6 ) \
do { \
if (bt_ctf_writer_add_environment_field(writer, __n, __v)) \
return -1; \
} while (0)
F_74 ( L_56 , V_113 -> V_129 . V_134 ) ;
F_74 ( L_57 , L_58 ) ;
F_74 ( L_59 , V_113 -> V_129 . V_135 ) ;
F_74 ( L_60 , V_113 -> V_129 . V_136 ) ;
F_74 ( L_61 , V_113 -> V_129 . V_137 ) ;
F_74 ( L_62 , L_63 ) ;
F_74 ( L_64 , L_65 ) ;
#undef F_74
return 0 ;
}
static int F_75 ( struct V_12 * V_13 )
{
struct V_138 * clock = V_13 -> clock ;
F_76 ( clock , L_66 ) ;
#define F_77 ( T_5 , T_6 ) \
do { \
if (bt_ctf_clock_set_##__n(clock, __v)) \
return -1; \
} while (0)
F_77 ( V_139 , 1000000000 ) ;
F_77 ( V_140 , 0 ) ;
F_77 ( V_41 , 0 ) ;
F_77 ( V_141 , 10 ) ;
F_77 ( V_142 , 0 ) ;
#undef F_77
return 0 ;
}
static struct V_1 * F_78 ( int V_22 , bool V_8 , bool V_143 )
{
struct V_1 * type ;
type = F_79 ( V_22 ) ;
if ( ! type )
return NULL ;
if ( V_8 &&
F_80 ( type , 1 ) )
goto V_10;
if ( V_143 &&
F_81 ( type , V_144 ) )
goto V_10;
#if V_145 == V_146
F_82 ( type , V_147 ) ;
#else
F_82 ( type , V_148 ) ;
#endif
F_8 ( L_67 ,
V_22 , V_8 ? L_68 : L_69 , V_143 ? L_70 : L_69 ) ;
return type ;
V_10:
F_18 ( type ) ;
return NULL ;
}
static void F_83 ( struct V_12 * V_13 )
{
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < F_84 ( V_13 -> V_17 . V_149 ) ; V_30 ++ )
F_18 ( V_13 -> V_17 . V_149 [ V_30 ] ) ;
}
static int F_85 ( struct V_12 * V_13 )
{
#define F_86 ( type , V_22 , V_8 , V_143 ) \
do { \
(type) = create_int_type(size, sign, hex); \
if (!(type)) \
goto err; \
} while (0)
F_86 ( V_13 -> V_17 . V_23 , 64 , true , false ) ;
F_86 ( V_13 -> V_17 . T_1 , 64 , false , false ) ;
F_86 ( V_13 -> V_17 . V_24 , 32 , true , false ) ;
F_86 ( V_13 -> V_17 . V_25 , 32 , false , false ) ;
F_86 ( V_13 -> V_17 . V_121 , 32 , false , true ) ;
F_86 ( V_13 -> V_17 . V_21 , 64 , false , true ) ;
V_13 -> V_17 . string = F_87 () ;
if ( V_13 -> V_17 . string )
return 0 ;
V_10:
F_83 ( V_13 ) ;
F_4 ( L_71 ) ;
return - 1 ;
}
static void F_88 ( struct V_12 * V_13 )
{
F_83 ( V_13 ) ;
F_89 ( V_13 -> clock ) ;
F_72 ( V_13 ) ;
F_90 ( V_13 -> V_96 ) ;
F_91 ( V_13 -> V_95 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
}
static int F_92 ( struct V_12 * V_13 , const char * V_150 )
{
struct V_133 * V_95 ;
struct V_151 * V_96 ;
struct V_138 * clock ;
struct V_1 * V_152 ;
int V_9 ;
V_95 = F_93 ( V_150 ) ;
if ( ! V_95 )
goto V_10;
V_13 -> V_95 = V_95 ;
clock = F_94 ( L_72 ) ;
if ( ! clock ) {
F_32 ( L_73 ) ;
goto V_153;
}
V_13 -> clock = clock ;
if ( F_75 ( V_13 ) ) {
F_32 ( L_74 ) ;
goto V_153;
}
V_96 = F_95 ( L_75 ) ;
if ( ! V_96 ) {
F_32 ( L_76 ) ;
goto V_153;
}
V_13 -> V_96 = V_96 ;
if ( F_96 ( V_96 , clock ) ) {
F_32 ( L_77 ) ;
goto V_153;
}
if ( F_85 ( V_13 ) )
goto V_153;
V_152 = F_97 ( V_96 ) ;
if ( ! V_152 )
goto V_153;
V_9 = F_98 ( V_152 , V_13 -> V_17 . V_25 , L_36 ) ;
F_18 ( V_152 ) ;
if ( V_9 )
goto V_153;
if ( F_99 ( V_95 , clock ) ) {
F_32 ( L_78 ) ;
goto V_153;
}
return 0 ;
V_153:
F_88 ( V_13 ) ;
V_10:
F_4 ( L_79 ) ;
return - 1 ;
}
static int F_100 ( struct V_12 * V_13 )
{
int V_90 , V_9 = 0 ;
for ( V_90 = 0 ; V_90 < V_13 -> V_99 && ! V_9 ; V_90 ++ )
V_9 = F_30 ( V_13 -> V_89 [ V_90 ] ) ;
return V_9 ;
}
static int F_101 ( const char * V_154 , const char * V_155 , void * V_156 )
{
struct V_107 * V_108 = V_156 ;
if ( ! strcmp ( V_154 , L_80 ) ) {
V_108 -> V_157 = F_102 ( V_154 , V_155 ) ;
return 0 ;
}
return 0 ;
}
int F_103 ( const char * V_158 , const char * V_150 , bool V_159 )
{
struct V_122 * V_123 ;
struct V_160 V_161 = {
. V_150 = V_158 ,
. V_162 = V_163 ,
. V_159 = V_159 ,
} ;
struct V_107 V_108 = {
. V_102 = {
. V_36 = F_41 ,
. V_164 = V_165 ,
. V_166 = V_167 ,
. V_168 = V_169 ,
. exit = V_170 ,
. V_171 = V_172 ,
. V_173 = V_174 ,
. V_175 = V_176 ,
. V_177 = V_178 ,
. V_179 = true ,
. V_180 = true ,
} ,
} ;
struct V_12 * V_13 = & V_108 . V_95 ;
int V_10 = - 1 ;
F_104 ( F_101 , & V_108 ) ;
if ( F_92 ( V_13 , V_150 ) )
return - 1 ;
V_123 = F_105 ( & V_161 , 0 , & V_108 . V_102 ) ;
if ( ! V_123 )
goto V_181;
if ( V_108 . V_157 ) {
F_106 ( & V_123 -> V_179 ,
V_108 . V_157 ) ;
}
if ( F_73 ( V_13 , V_123 ) )
goto V_182;
if ( F_66 ( V_13 , V_123 ) )
goto V_182;
if ( F_71 ( V_13 , V_123 ) )
goto V_182;
V_10 = F_107 ( V_123 ) ;
if ( ! V_10 )
V_10 = F_100 ( V_13 ) ;
else
F_4 ( L_81 ) ;
fprintf ( V_183 ,
L_82 ,
V_161 . V_150 , V_150 ) ;
fprintf ( V_183 ,
L_83 V_11 L_84 ,
( double ) V_108 . V_112 / 1024.0 / 1024.0 ,
V_108 . V_111 ) ;
F_68 ( V_123 ) ;
F_108 ( V_123 ) ;
F_88 ( V_13 ) ;
return V_10 ;
V_182:
F_108 ( V_123 ) ;
V_181:
F_88 ( V_13 ) ;
F_4 ( L_85 ) ;
return V_10 ;
}
