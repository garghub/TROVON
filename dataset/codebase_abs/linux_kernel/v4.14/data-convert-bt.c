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
static int
F_27 ( struct V_34 * V_35 ,
struct V_2 * V_3 ,
struct V_67 * V_68 )
{
struct V_1 * V_56 , * V_57 ;
struct V_6 * V_58 , * V_59 ;
unsigned int V_61 = V_68 -> V_69 ;
unsigned int V_31 ;
int V_9 ;
V_56 = F_18 (
V_35 , L_23 ) ;
V_58 = F_3 ( V_56 ) ;
if ( ! V_58 ) {
F_4 ( L_24 ) ;
V_9 = - 1 ;
goto V_62;
}
V_9 = F_6 ( V_58 , V_61 ) ;
if ( V_9 ) {
F_4 ( L_25 ) ;
goto V_63;
}
V_9 = F_7 ( V_3 , L_23 , V_58 ) ;
if ( V_9 ) {
F_4 ( L_26 ) ;
goto V_63;
}
V_57 = F_18 (
V_35 , L_27 ) ;
V_59 = F_3 ( V_57 ) ;
if ( ! V_59 ) {
F_4 ( L_28 ) ;
V_9 = - 1 ;
goto V_64;
}
V_9 = F_25 ( V_59 , V_58 ) ;
if ( V_9 ) {
F_4 ( L_29 ) ;
goto V_65;
}
for ( V_31 = 0 ; V_31 < V_61 ; V_31 ++ ) {
struct V_6 * V_66 =
F_26 ( V_59 , V_31 ) ;
V_9 = F_6 ( V_66 ,
( ( T_1 * ) ( V_68 -> V_70 ) ) [ V_31 ] ) ;
F_9 ( V_66 ) ;
if ( V_9 ) {
F_4 ( L_30 , V_31 ) ;
goto V_65;
}
}
V_9 = F_7 ( V_3 , L_27 , V_59 ) ;
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
static int F_28 ( struct V_12 * V_13 ,
struct V_2 * V_3 ,
struct V_51 * V_52 ,
struct V_36 * V_37 )
{
T_1 type = V_52 -> V_71 . V_72 ;
int V_9 ;
if ( type & V_73 ) {
V_9 = F_29 ( V_13 , V_3 , L_31 , V_37 -> V_74 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_75 ) {
V_9 = F_30 ( V_13 , V_3 , L_32 , V_37 -> V_76 ) ;
if ( V_9 )
return - 1 ;
V_9 = F_30 ( V_13 , V_3 , L_33 , V_37 -> V_77 ) ;
if ( V_9 )
return - 1 ;
}
if ( ( type & V_78 ) ||
( type & V_79 ) ) {
V_9 = F_31 ( V_13 , V_3 , L_34 , V_37 -> V_80 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_81 ) {
V_9 = F_31 ( V_13 , V_3 , L_35 , V_37 -> V_82 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_83 ) {
V_9 = F_31 ( V_13 , V_3 , L_36 , V_37 -> V_84 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_85 ) {
V_9 = F_31 ( V_13 , V_3 , L_37 , V_37 -> V_86 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_87 ) {
V_9 = F_31 ( V_13 , V_3 , L_38 ,
V_37 -> V_88 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_89 ) {
V_9 = F_31 ( V_13 , V_3 , L_39 ,
V_37 -> V_90 ) ;
if ( V_9 )
return - 1 ;
}
return 0 ;
}
static int F_32 ( struct V_91 * V_92 )
{
int V_10 = 0 ;
if ( V_92 ) {
V_10 = F_33 ( V_92 -> V_93 ) ;
if ( V_10 )
F_4 ( L_40 , V_92 -> V_94 ) ;
F_34 ( L_41 ,
V_92 -> V_94 , V_92 -> V_95 ) ;
V_92 -> V_95 = 0 ;
}
return V_10 ;
}
static struct V_91 * F_35 ( struct V_12 * V_13 , int V_94 )
{
struct V_91 * V_92 ;
struct V_6 * V_96 = NULL ;
struct V_6 * V_97 = NULL ;
struct V_98 * V_93 = NULL ;
int V_9 ;
V_92 = F_14 ( sizeof( * V_92 ) ) ;
if ( ! V_92 ) {
F_4 ( L_42 ) ;
return NULL ;
}
V_93 = F_36 ( V_13 -> V_99 , V_13 -> V_100 ) ;
if ( ! V_93 ) {
F_4 ( L_43 ) ;
goto V_101;
}
V_96 = F_37 ( V_93 ) ;
if ( ! V_96 ) {
F_4 ( L_44 ) ;
goto V_101;
}
V_97 = F_38 ( V_96 , L_45 ) ;
F_9 ( V_96 ) ;
if ( ! V_97 ) {
F_4 ( L_46 ) ;
goto V_101;
}
V_9 = F_6 ( V_97 , ( V_26 ) V_94 ) ;
if ( V_9 ) {
F_4 ( L_47 ) ;
goto V_101;
}
F_9 ( V_97 ) ;
V_92 -> V_94 = V_94 ;
V_92 -> V_93 = V_93 ;
return V_92 ;
V_101:
if ( V_97 )
F_9 ( V_97 ) ;
if ( V_93 )
F_39 ( V_93 ) ;
free ( V_92 ) ;
return NULL ;
}
static void F_40 ( struct V_91 * V_92 )
{
if ( V_92 ) {
F_39 ( V_92 -> V_93 ) ;
free ( V_92 ) ;
}
}
static struct V_91 * V_91 ( struct V_12 * V_13 , int V_94 )
{
struct V_91 * V_92 = V_13 -> V_93 [ V_94 ] ;
if ( ! V_92 ) {
V_92 = F_35 ( V_13 , V_94 ) ;
V_13 -> V_93 [ V_94 ] = V_92 ;
}
return V_92 ;
}
static int F_41 ( struct V_12 * V_13 , struct V_36 * V_37 ,
struct V_51 * V_52 )
{
int V_94 = 0 ;
if ( V_52 -> V_71 . V_72 & V_102 )
V_94 = V_37 -> V_94 ;
if ( V_94 > V_13 -> V_103 ) {
F_4 ( L_48 ,
V_94 , V_13 -> V_103 ) ;
V_94 = 0 ;
}
return V_94 ;
}
static bool F_42 ( struct V_91 * V_92 )
{
return V_92 -> V_95 >= V_104 ;
}
static int F_43 ( struct V_105 * V_106 ,
union V_107 * V_108 ,
struct V_36 * V_37 ,
struct V_51 * V_52 ,
struct V_109 * V_109 T_2 )
{
struct V_110 * V_111 = F_44 ( V_106 , struct V_110 , V_106 ) ;
struct V_112 * V_113 = V_52 -> V_113 ;
struct V_12 * V_13 = & V_111 -> V_99 ;
struct V_91 * V_92 ;
struct V_34 * V_35 ;
struct V_2 * V_3 ;
int V_9 ;
unsigned long type = V_52 -> V_71 . V_72 ;
if ( F_45 ( ! V_113 , L_49 ) )
return 0 ;
V_35 = V_113 -> V_35 ;
V_111 -> V_114 ++ ;
V_111 -> V_115 += V_108 -> V_116 . V_23 ;
F_46 ( V_37 -> time , L_50 V_11 L_51 , V_111 -> V_114 ) ;
V_3 = F_47 ( V_35 ) ;
if ( ! V_3 ) {
F_4 ( L_52 ) ;
return - 1 ;
}
F_48 ( V_13 -> clock , V_37 -> time ) ;
V_9 = F_28 ( V_13 , V_3 , V_52 , V_37 ) ;
if ( V_9 )
return - 1 ;
if ( V_52 -> V_71 . type == V_117 ) {
V_9 = F_22 ( V_13 , V_35 , V_3 ,
V_52 , V_37 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_118 ) {
V_9 = F_27 ( V_35 ,
V_3 , V_37 -> V_68 ) ;
if ( V_9 )
return - 1 ;
}
if ( F_49 ( V_52 ) ) {
V_9 = F_23 ( V_35 , V_3 , V_37 ) ;
if ( V_9 )
return - 1 ;
}
V_92 = V_91 ( V_13 , F_41 ( V_13 , V_37 , V_52 ) ) ;
if ( V_92 ) {
if ( F_42 ( V_92 ) )
F_32 ( V_92 ) ;
V_92 -> V_95 ++ ;
F_50 ( V_92 -> V_93 , V_3 ) ;
}
F_51 ( V_3 ) ;
return V_92 ? 0 : - 1 ;
}
static char * F_52 ( char * V_4 , char * V_119 , int V_120 )
{
char * V_121 = NULL ;
T_3 V_30 ;
if ( ! V_4 )
V_4 = V_119 ;
if ( V_120 >= 10 )
goto V_101;
if ( V_120 < 0 )
V_30 = strlen ( V_4 ) + sizeof( L_53 ) ;
else
V_30 = strlen ( V_119 ) + sizeof( L_54 ) ;
V_121 = malloc ( V_30 ) ;
if ( ! V_121 )
goto V_101;
if ( V_120 < 0 )
snprintf ( V_121 , V_30 , L_55 , V_4 ) ;
else
snprintf ( V_121 , V_30 , L_56 , V_119 , V_120 ) ;
V_101:
if ( V_4 != V_119 )
free ( V_4 ) ;
return V_121 ;
}
static int F_53 ( struct V_34 * V_35 ,
struct V_1 * type ,
struct V_16 * V_7 )
{
struct V_1 * V_122 = NULL ;
char * V_4 ;
int V_120 = 1 ;
int V_9 ;
if ( V_7 -> V_43 != V_7 -> V_4 )
return F_54 ( V_35 , type ,
( char * ) V_7 -> V_43 ) ;
V_4 = V_7 -> V_4 ;
if ( F_55 ( V_4 ) )
V_4 = F_52 ( V_4 , V_7 -> V_4 , - 1 ) ;
if ( ! V_4 ) {
F_4 ( L_57 ) ;
return - 1 ;
}
while ( ( V_122 = F_18 ( V_35 , V_4 ) ) ) {
F_19 ( V_122 ) ;
V_4 = F_52 ( V_4 , V_7 -> V_4 , V_120 ++ ) ;
if ( ! V_4 ) {
F_4 ( L_58 , V_7 -> V_4 ) ;
return - 1 ;
}
}
V_9 = F_54 ( V_35 , type , V_4 ) ;
if ( ! V_9 )
V_7 -> V_43 = V_4 ;
return V_9 ;
}
static int F_56 ( struct V_12 * V_13 ,
struct V_16 * V_49 ,
struct V_34 * V_35 )
{
struct V_16 * V_7 ;
int V_9 ;
for ( V_7 = V_49 ; V_7 ; V_7 = V_7 -> V_50 ) {
struct V_1 * type ;
unsigned long V_17 = V_7 -> V_17 ;
F_8 ( L_59 , V_7 -> V_4 ) ;
type = F_12 ( V_13 , V_7 ) ;
if ( ! type )
return - 1 ;
if ( V_17 & V_18 )
V_17 &= ~ V_44 ;
if ( V_17 & V_44 )
type = F_57 ( type , V_7 -> V_48 ) ;
V_9 = F_53 ( V_35 , type , V_7 ) ;
if ( V_17 & V_44 )
F_19 ( type ) ;
if ( V_9 ) {
F_4 ( L_60 ,
V_7 -> V_4 , V_9 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_58 ( struct V_12 * V_13 ,
struct V_51 * V_52 ,
struct V_34 * V_123 )
{
struct V_16 * V_53 = V_52 -> V_54 -> V_55 . V_53 ;
struct V_16 * V_49 = V_52 -> V_54 -> V_55 . V_49 ;
int V_9 ;
V_9 = F_56 ( V_13 , V_53 , V_123 ) ;
if ( ! V_9 )
V_9 = F_56 ( V_13 , V_49 , V_123 ) ;
return V_9 ;
}
static int F_59 ( struct V_12 * V_13 ,
struct V_34 * V_123 )
{
struct V_1 * V_56 = V_13 -> V_14 . V_26 ;
struct V_1 * V_124 = V_13 -> V_14 . V_125 ;
struct V_1 * V_57 ;
int V_9 ;
V_9 = F_54 ( V_123 , V_56 , L_14 ) ;
if ( V_9 )
return V_9 ;
V_57 = F_60 ( V_124 , L_14 ) ;
if ( ! V_57 )
return - 1 ;
return F_54 ( V_123 , V_57 , L_18 ) ;
}
static int F_61 ( struct V_12 * V_13 , struct V_51 * V_52 ,
struct V_34 * V_35 )
{
T_1 type = V_52 -> V_71 . V_72 ;
#define F_62 ( T_4 , V_122 , T_5 ) \
do { \
pr2(" field '%s'\n", n); \
if (bt_ctf_event_class_add_field(cl, t, n)) { \
pr_err("Failed to add field '%s';\n", n); \
return -1; \
} \
} while (0)
if ( type & V_73 )
F_62 ( V_35 , V_13 -> V_14 . V_22 , L_31 ) ;
if ( type & V_75 ) {
F_62 ( V_35 , V_13 -> V_14 . V_25 , L_32 ) ;
F_62 ( V_35 , V_13 -> V_14 . V_25 , L_33 ) ;
}
if ( ( type & V_78 ) ||
( type & V_79 ) )
F_62 ( V_35 , V_13 -> V_14 . T_1 , L_34 ) ;
if ( type & V_81 )
F_62 ( V_35 , V_13 -> V_14 . T_1 , L_35 ) ;
if ( type & V_83 )
F_62 ( V_35 , V_13 -> V_14 . T_1 , L_36 ) ;
if ( type & V_85 )
F_62 ( V_35 , V_13 -> V_14 . T_1 , L_37 ) ;
if ( type & V_87 )
F_62 ( V_35 , V_13 -> V_14 . T_1 , L_38 ) ;
if ( type & V_89 )
F_62 ( V_35 , V_13 -> V_14 . T_1 , L_39 ) ;
if ( type & V_118 ) {
F_62 ( V_35 , V_13 -> V_14 . V_26 , L_23 ) ;
F_62 ( V_35 ,
F_60 (
V_13 -> V_14 . V_22 , L_23 ) ,
L_27 ) ;
}
#undef F_62
return 0 ;
}
static int F_63 ( struct V_12 * V_13 , struct V_51 * V_52 )
{
struct V_34 * V_35 ;
struct V_112 * V_113 ;
const char * V_4 = F_64 ( V_52 ) ;
int V_9 ;
F_34 ( L_61 , V_4 , V_52 -> V_71 . type ) ;
V_35 = F_65 ( V_4 ) ;
if ( ! V_35 )
return - 1 ;
V_9 = F_61 ( V_13 , V_52 , V_35 ) ;
if ( V_9 )
goto V_10;
if ( V_52 -> V_71 . type == V_117 ) {
V_9 = F_58 ( V_13 , V_52 , V_35 ) ;
if ( V_9 )
goto V_10;
}
if ( F_49 ( V_52 ) ) {
V_9 = F_59 ( V_13 , V_35 ) ;
if ( V_9 )
goto V_10;
}
V_9 = F_66 ( V_13 -> V_100 , V_35 ) ;
if ( V_9 ) {
F_34 ( L_62 ) ;
goto V_10;
}
V_113 = malloc ( sizeof( * V_113 ) ) ;
if ( ! V_113 )
goto V_10;
V_113 -> V_35 = V_35 ;
V_52 -> V_113 = V_113 ;
return 0 ;
V_10:
F_67 ( V_35 ) ;
F_4 ( L_63 , V_4 ) ;
return - 1 ;
}
static int F_68 ( struct V_12 * V_13 , struct V_126 * V_127 )
{
struct V_128 * V_129 = V_127 -> V_129 ;
struct V_51 * V_52 ;
int V_9 ;
F_69 (evlist, evsel) {
V_9 = F_63 ( V_13 , V_52 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_70 ( struct V_12 * V_13 ,
struct V_126 * V_127 T_2 )
{
int V_9 ;
V_9 = F_71 ( V_13 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_72 ( V_13 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_73 ( V_13 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_74 ( V_13 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_75 ( V_13 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static void F_76 ( struct V_126 * V_127 )
{
struct V_128 * V_129 = V_127 -> V_129 ;
struct V_51 * V_52 ;
F_69 (evlist, evsel) {
struct V_112 * V_113 ;
V_113 = V_52 -> V_113 ;
F_67 ( V_113 -> V_35 ) ;
F_77 ( & V_52 -> V_113 ) ;
}
F_78 ( V_129 ) ;
V_127 -> V_129 = NULL ;
}
static int F_79 ( struct V_12 * V_13 , struct V_126 * V_127 )
{
struct V_91 * * V_93 ;
struct V_130 * V_131 = & V_127 -> V_116 ;
int V_132 ;
V_132 = V_131 -> V_133 . V_134 ? : V_135 ;
V_93 = F_14 ( sizeof( * V_93 ) * V_132 ) ;
if ( ! V_93 ) {
F_4 ( L_64 ) ;
return - V_136 ;
}
V_13 -> V_93 = V_93 ;
V_13 -> V_103 = V_132 ;
return 0 ;
}
static void F_80 ( struct V_12 * V_13 )
{
int V_94 ;
for ( V_94 = 0 ; V_94 < V_13 -> V_103 ; V_94 ++ )
F_40 ( V_13 -> V_93 [ V_94 ] ) ;
free ( V_13 -> V_93 ) ;
}
static int F_81 ( struct V_12 * V_13 ,
struct V_126 * V_127 )
{
struct V_130 * V_116 = & V_127 -> V_116 ;
struct V_137 * V_99 = V_13 -> V_99 ;
#define F_82 ( T_6 , T_7 ) \
do { \
if (bt_ctf_writer_add_environment_field(writer, __n, __v)) \
return -1; \
} while (0)
F_82 ( L_65 , V_116 -> V_133 . V_138 ) ;
F_82 ( L_66 , L_67 ) ;
F_82 ( L_68 , V_116 -> V_133 . V_139 ) ;
F_82 ( L_69 , V_116 -> V_133 . V_140 ) ;
F_82 ( L_70 , V_116 -> V_133 . V_141 ) ;
F_82 ( L_71 , L_72 ) ;
F_82 ( L_73 , L_74 ) ;
#undef F_82
return 0 ;
}
static int F_83 ( struct V_12 * V_13 )
{
struct V_142 * clock = V_13 -> clock ;
F_84 ( clock , L_75 ) ;
#define F_85 ( T_6 , T_7 ) \
do { \
if (bt_ctf_clock_set_##__n(clock, __v)) \
return -1; \
} while (0)
F_85 ( V_143 , 1000000000 ) ;
F_85 ( V_144 , 0 ) ;
F_85 ( V_42 , 0 ) ;
F_85 ( V_145 , 10 ) ;
F_85 ( V_146 , 0 ) ;
#undef F_85
return 0 ;
}
static struct V_1 * F_86 ( int V_23 , bool V_8 , bool V_147 )
{
struct V_1 * type ;
type = F_87 ( V_23 ) ;
if ( ! type )
return NULL ;
if ( V_8 &&
F_88 ( type , 1 ) )
goto V_10;
if ( V_147 &&
F_89 ( type , V_148 ) )
goto V_10;
#if V_149 == V_150
F_90 ( type , V_151 ) ;
#else
F_90 ( type , V_152 ) ;
#endif
F_8 ( L_76 ,
V_23 , V_8 ? L_77 : L_78 , V_147 ? L_79 : L_78 ) ;
return type ;
V_10:
F_19 ( type ) ;
return NULL ;
}
static void F_91 ( struct V_12 * V_13 )
{
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < F_92 ( V_13 -> V_14 . V_153 ) ; V_31 ++ )
F_19 ( V_13 -> V_14 . V_153 [ V_31 ] ) ;
}
static int F_93 ( struct V_12 * V_13 )
{
#define F_94 ( type , V_23 , V_8 , V_147 ) \
do { \
(type) = create_int_type(size, sign, hex); \
if (!(type)) \
goto err; \
} while (0)
F_94 ( V_13 -> V_14 . V_24 , 64 , true , false ) ;
F_94 ( V_13 -> V_14 . T_1 , 64 , false , false ) ;
F_94 ( V_13 -> V_14 . V_25 , 32 , true , false ) ;
F_94 ( V_13 -> V_14 . V_26 , 32 , false , false ) ;
F_94 ( V_13 -> V_14 . V_125 , 32 , false , true ) ;
F_94 ( V_13 -> V_14 . V_22 , 64 , false , true ) ;
V_13 -> V_14 . string = F_95 () ;
if ( V_13 -> V_14 . string )
return 0 ;
V_10:
F_91 ( V_13 ) ;
F_4 ( L_80 ) ;
return - 1 ;
}
static void F_96 ( struct V_12 * V_13 )
{
F_91 ( V_13 ) ;
F_97 ( V_13 -> clock ) ;
F_80 ( V_13 ) ;
F_98 ( V_13 -> V_100 ) ;
F_99 ( V_13 -> V_99 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
}
static int F_100 ( struct V_12 * V_13 , const char * V_154 )
{
struct V_137 * V_99 ;
struct V_155 * V_100 ;
struct V_142 * clock ;
struct V_1 * V_156 ;
int V_9 ;
V_99 = F_101 ( V_154 ) ;
if ( ! V_99 )
goto V_10;
V_13 -> V_99 = V_99 ;
clock = F_102 ( L_81 ) ;
if ( ! clock ) {
F_34 ( L_82 ) ;
goto V_157;
}
V_13 -> clock = clock ;
if ( F_83 ( V_13 ) ) {
F_34 ( L_83 ) ;
goto V_157;
}
V_100 = F_103 ( L_84 ) ;
if ( ! V_100 ) {
F_34 ( L_85 ) ;
goto V_157;
}
V_13 -> V_100 = V_100 ;
if ( F_104 ( V_100 , clock ) ) {
F_34 ( L_86 ) ;
goto V_157;
}
if ( F_93 ( V_13 ) )
goto V_157;
V_156 = F_105 ( V_100 ) ;
if ( ! V_156 )
goto V_157;
V_9 = F_106 ( V_156 , V_13 -> V_14 . V_26 , L_45 ) ;
F_19 ( V_156 ) ;
if ( V_9 )
goto V_157;
if ( F_107 ( V_99 , clock ) ) {
F_34 ( L_87 ) ;
goto V_157;
}
return 0 ;
V_157:
F_96 ( V_13 ) ;
V_10:
F_4 ( L_88 ) ;
return - 1 ;
}
static int F_108 ( struct V_12 * V_13 )
{
int V_94 , V_9 = 0 ;
for ( V_94 = 0 ; V_94 < V_13 -> V_103 && ! V_9 ; V_94 ++ )
V_9 = F_32 ( V_13 -> V_93 [ V_94 ] ) ;
return V_9 ;
}
static int F_109 ( const char * V_158 , const char * V_159 , void * V_160 )
{
struct V_110 * V_111 = V_160 ;
if ( ! strcmp ( V_158 , L_89 ) )
return F_110 ( & V_111 -> V_161 , V_158 , V_159 ) ;
return 0 ;
}
int F_111 ( const char * V_162 , const char * V_154 ,
struct V_163 * V_164 )
{
struct V_126 * V_127 ;
struct V_165 V_166 = {
. V_154 = V_162 ,
. V_167 = V_168 ,
. V_169 = V_164 -> V_169 ,
} ;
struct V_110 V_111 = {
. V_106 = {
. V_37 = F_43 ,
. V_170 = V_171 ,
. V_172 = V_173 ,
. V_174 = V_175 ,
. exit = V_176 ,
. V_177 = V_178 ,
. V_179 = V_180 ,
. V_181 = V_182 ,
. V_183 = V_184 ,
. V_185 = V_186 ,
. V_187 = true ,
. V_188 = true ,
} ,
} ;
struct V_12 * V_13 = & V_111 . V_99 ;
int V_10 ;
if ( V_164 -> V_189 ) {
V_111 . V_106 . V_174 = V_190 ;
V_111 . V_106 . exit = V_191 ;
V_111 . V_106 . V_177 = V_192 ;
V_111 . V_106 . V_170 = V_193 ;
V_111 . V_106 . V_172 = V_194 ;
}
V_10 = F_112 ( F_109 , & V_111 ) ;
if ( V_10 )
return V_10 ;
if ( F_100 ( V_13 , V_154 ) )
return - 1 ;
V_10 = - 1 ;
V_127 = F_113 ( & V_166 , 0 , & V_111 . V_106 ) ;
if ( ! V_127 )
goto V_195;
if ( V_111 . V_161 ) {
F_114 ( & V_127 -> V_187 ,
V_111 . V_161 ) ;
}
if ( F_81 ( V_13 , V_127 ) )
goto V_196;
if ( F_68 ( V_13 , V_127 ) )
goto V_196;
if ( V_164 -> V_189 && F_70 ( V_13 , V_127 ) )
goto V_196;
if ( F_79 ( V_13 , V_127 ) )
goto V_196;
V_10 = F_115 ( V_127 ) ;
if ( ! V_10 )
V_10 = F_108 ( V_13 ) ;
else
F_4 ( L_90 ) ;
fprintf ( V_197 ,
L_91 ,
V_166 . V_154 , V_154 ) ;
fprintf ( V_197 ,
L_92 V_11 L_93 ,
( double ) V_111 . V_115 / 1024.0 / 1024.0 ,
V_111 . V_114 ) ;
if ( ! V_111 . V_198 )
fprintf ( V_197 , L_94 ) ;
else
fprintf ( V_197 , L_95 V_11 L_96 , V_111 . V_198 ) ;
F_76 ( V_127 ) ;
F_116 ( V_127 ) ;
F_96 ( V_13 ) ;
return V_10 ;
V_196:
F_116 ( V_127 ) ;
V_195:
F_96 ( V_13 ) ;
F_4 ( L_97 ) ;
return V_10 ;
}
