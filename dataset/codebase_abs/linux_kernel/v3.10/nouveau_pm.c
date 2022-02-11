static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 , struct V_3 * V_6 )
{
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
int V_14 ;
if ( V_12 && V_12 -> V_15 &&
V_5 -> V_16 && V_6 -> V_16 && V_6 -> V_16 > V_5 -> V_16 ) {
V_14 = V_12 -> V_15 ( V_12 , V_4 -> V_16 ) ;
if ( V_14 && V_14 != - V_17 ) {
F_2 ( V_8 , L_1 , V_14 ) ;
}
}
if ( V_10 -> V_18 . V_19 && V_10 -> V_20 ) {
if ( V_4 -> V_21 && V_6 -> V_21 > V_5 -> V_21 ) {
V_14 = V_10 -> V_20 ( V_2 , V_4 -> V_21 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_2 , V_14 ) ;
return V_14 ;
}
}
}
return 0 ;
}
static int
F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
void * V_22 ;
int V_14 ;
if ( V_4 == V_10 -> V_23 )
return 0 ;
V_14 = F_1 ( V_2 , V_4 , V_10 -> V_23 , V_4 ) ;
if ( V_14 )
return V_14 ;
V_22 = V_10 -> V_24 ( V_2 , V_4 ) ;
if ( F_4 ( V_22 ) ) {
V_14 = F_5 ( V_22 ) ;
goto error;
}
V_14 = V_10 -> V_25 ( V_2 , V_22 ) ;
if ( V_14 )
goto error;
V_14 = F_1 ( V_2 , V_4 , V_4 , V_10 -> V_23 ) ;
if ( V_14 )
return V_14 ;
V_10 -> V_23 = V_4 ;
return 0 ;
error:
F_1 ( V_2 , V_4 , V_4 , V_10 -> V_23 ) ;
return V_14 ;
}
void
F_6 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_26 * V_27 = V_26 ( V_8 -> V_13 ) ;
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_28 * V_29 = NULL ;
struct V_3 * V_4 = NULL ;
int V_14 ;
if ( F_7 () )
V_29 = V_10 -> V_30 ;
else
V_29 = V_10 -> V_31 ;
if ( V_29 != V_10 -> V_29 ) {
V_10 -> V_29 -> V_32 -> V_33 ( V_10 -> V_29 ) ;
V_10 -> V_29 = V_29 ;
V_10 -> V_29 -> V_32 -> V_34 ( V_10 -> V_29 ) ;
}
V_4 = V_29 -> V_32 -> V_35 ( V_29 ) ;
if ( V_4 != V_10 -> V_23 ) {
T_1 V_36 = V_27 -> V_37 ( V_27 ) ;
F_8 ( V_8 , L_3 , V_4 -> V_38 ) ;
V_14 = F_3 ( V_2 , V_4 ) ;
if ( V_14 )
F_8 ( V_8 , L_4 , V_14 ) ;
F_8 ( V_8 , L_5 ,
V_27 -> V_37 ( V_27 ) - V_36 ) ;
}
}
static struct V_28 *
F_9 ( struct V_1 * V_2 , const char * string )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_28 * V_29 ;
F_10 (profile, &pm->profiles, head) {
if ( ! strncmp ( V_29 -> V_39 , string , sizeof( V_29 -> V_39 ) ) )
return V_29 ;
}
return NULL ;
}
static int
F_11 ( struct V_1 * V_2 , const char * V_29 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_28 * V_40 = NULL , * V_41 = NULL ;
char string [ 16 ] , * V_23 = string , * V_42 ;
if ( V_43 != 7777 )
return - V_44 ;
strncpy ( string , V_29 , sizeof( string ) ) ;
string [ sizeof( string ) - 1 ] = 0 ;
if ( ( V_42 = strchr ( string , '\n' ) ) )
* V_42 = '\0' ;
V_42 = F_12 ( & V_23 , L_6 ) ;
if ( V_42 )
V_40 = F_9 ( V_2 , V_42 ) ;
V_42 = F_12 ( & V_23 , L_6 ) ;
if ( V_42 )
V_41 = F_9 ( V_2 , V_42 ) ;
else
V_41 = V_40 ;
if ( V_40 == NULL || V_41 == NULL )
return - V_45 ;
V_10 -> V_30 = V_40 ;
V_10 -> V_31 = V_41 ;
F_6 ( V_2 ) ;
return 0 ;
}
static void
F_13 ( struct V_28 * V_29 )
{
}
static struct V_3 *
F_14 ( struct V_28 * V_29 )
{
return F_15 ( V_29 , struct V_3 , V_29 ) ;
}
static int
F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
int V_14 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
if ( V_10 -> V_46 ) {
V_14 = V_10 -> V_46 ( V_2 , V_4 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_10 -> V_18 . V_19 && V_10 -> V_47 ) {
V_14 = V_10 -> V_47 ( V_2 ) ;
if ( V_14 > 0 ) {
V_4 -> V_21 = V_14 ;
V_4 -> V_48 = V_14 ;
}
}
if ( V_12 && V_12 -> V_49 ) {
V_14 = V_12 -> V_49 ( V_12 ) ;
if ( V_14 >= 0 )
V_4 -> V_16 = V_14 ;
}
F_17 ( V_2 , & V_4 -> V_50 ) ;
return 0 ;
}
static void
F_18 ( struct V_3 * V_4 , char * V_42 , int V_51 )
{
char V_52 [ 16 ] , V_53 [ 16 ] , V_54 [ 32 ] , V_55 [ 16 ] , V_56 [ 16 ] ;
V_52 [ 0 ] = '\0' ;
if ( V_4 -> V_57 )
snprintf ( V_52 , sizeof( V_52 ) , L_7 , V_4 -> V_57 / 1000 ) ;
V_53 [ 0 ] = '\0' ;
if ( V_4 -> V_58 )
snprintf ( V_53 , sizeof( V_53 ) , L_8 , V_4 -> V_58 / 1000 ) ;
V_56 [ 0 ] = '\0' ;
if ( V_4 -> V_59 )
snprintf ( V_56 , sizeof( V_56 ) , L_9 , V_4 -> V_59 / 1000 ) ;
V_54 [ 0 ] = '\0' ;
if ( V_4 -> V_21 && V_4 -> V_21 != V_4 -> V_48 ) {
snprintf ( V_54 , sizeof( V_54 ) , L_10 ,
V_4 -> V_21 / 1000 , V_4 -> V_48 / 1000 ) ;
} else
if ( V_4 -> V_21 ) {
snprintf ( V_54 , sizeof( V_54 ) , L_11 ,
V_4 -> V_21 / 1000 ) ;
}
V_55 [ 0 ] = '\0' ;
if ( V_4 -> V_16 )
snprintf ( V_55 , sizeof( V_55 ) , L_12 , V_4 -> V_16 ) ;
snprintf ( V_42 , V_51 , L_13 , V_52 , V_53 , V_56 , V_54 , V_55 ) ;
}
static T_2
F_19 ( struct V_13 * V_60 ,
struct V_61 * V_5 , char * V_62 )
{
struct V_3 * V_4 =
F_15 ( V_5 , struct V_3 , V_63 ) ;
char * V_42 = V_62 ;
int V_51 = V_64 ;
snprintf ( V_42 , V_51 , L_14 , V_4 -> V_38 ) ;
V_42 += strlen ( V_62 ) ;
V_51 -= strlen ( V_62 ) ;
F_18 ( V_4 , V_42 , V_51 ) ;
return strlen ( V_62 ) ;
}
static T_2
F_20 ( struct V_13 * V_60 , struct V_61 * V_5 , char * V_62 )
{
struct V_1 * V_2 = F_21 ( F_22 ( V_60 ) ) ;
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_3 V_23 ;
int V_51 = V_64 , V_14 ;
char * V_42 = V_62 ;
snprintf ( V_42 , V_51 , L_15 ,
V_10 -> V_30 -> V_39 , V_10 -> V_31 -> V_39 ) ;
V_42 += strlen ( V_62 ) ;
V_51 -= strlen ( V_62 ) ;
V_14 = F_16 ( V_2 , & V_23 ) ;
if ( V_14 == 0 )
F_18 ( & V_23 , V_42 , V_51 ) ;
return strlen ( V_62 ) ;
}
static T_2
F_23 ( struct V_13 * V_60 , struct V_61 * V_5 ,
const char * V_62 , T_3 V_65 )
{
struct V_1 * V_2 = F_21 ( F_22 ( V_60 ) ) ;
int V_14 ;
V_14 = F_11 ( V_2 , V_62 ) ;
if ( V_14 )
return V_14 ;
return strlen ( V_62 ) ;
}
static int
F_24 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_13 * V_60 = & V_2 -> V_66 -> V_2 ;
int V_14 , V_67 ;
V_14 = F_25 ( V_60 , & V_68 ) ;
if ( V_14 )
return V_14 ;
for ( V_67 = 0 ; V_67 < V_10 -> V_69 ; V_67 ++ ) {
struct V_3 * V_4 = & V_10 -> V_4 [ V_67 ] ;
V_4 -> V_63 . V_70 . V_39 = V_4 -> V_39 ;
V_4 -> V_63 . V_70 . V_71 = V_72 ;
V_4 -> V_63 . V_73 = F_19 ;
V_4 -> V_63 . V_74 = NULL ;
F_26 ( & V_4 -> V_63 . V_70 ) ;
V_14 = F_25 ( V_60 , & V_4 -> V_63 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_16 ,
V_4 -> V_38 , V_67 ) ;
V_4 -> V_63 . V_70 . V_39 = NULL ;
F_27 ( V_2 ) ;
return V_14 ;
}
}
return 0 ;
}
static void
F_28 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_13 * V_60 = & V_2 -> V_66 -> V_2 ;
int V_67 ;
F_29 ( V_60 , & V_68 ) ;
for ( V_67 = 0 ; V_67 < V_10 -> V_69 ; V_67 ++ ) {
struct V_3 * V_75 = & V_10 -> V_4 [ V_67 ] ;
if ( ! V_75 -> V_63 . V_70 . V_39 )
break;
F_29 ( V_60 , & V_75 -> V_63 ) ;
}
}
static T_2
F_30 ( struct V_13 * V_60 , struct V_61 * V_5 , char * V_62 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
int V_76 = V_12 -> V_77 ( V_12 ) ;
if ( V_76 < 0 )
return V_76 ;
return snprintf ( V_62 , V_64 , L_17 , V_76 * 1000 ) ;
}
static T_2
F_32 ( struct V_13 * V_60 ,
struct V_61 * V_5 , char * V_62 )
{
return snprintf ( V_62 , V_64 , L_17 , 100 ) ;
}
static T_2
F_33 ( struct V_13 * V_60 ,
struct V_61 * V_5 , char * V_62 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
return snprintf ( V_62 , V_64 , L_17 ,
V_12 -> V_78 ( V_12 , V_79 ) * 1000 ) ;
}
static T_2
F_34 ( struct V_13 * V_60 ,
struct V_61 * V_5 ,
const char * V_62 , T_3 V_65 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
long V_80 ;
if ( F_35 ( V_62 , 10 , & V_80 ) == - V_45 )
return V_65 ;
V_12 -> V_81 ( V_12 , V_79 ,
V_80 / 1000 ) ;
return V_65 ;
}
static T_2
F_36 ( struct V_13 * V_60 ,
struct V_61 * V_5 , char * V_62 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
return snprintf ( V_62 , V_64 , L_17 ,
V_12 -> V_78 ( V_12 , V_82 ) * 1000 ) ;
}
static T_2
F_37 ( struct V_13 * V_60 ,
struct V_61 * V_5 ,
const char * V_62 , T_3 V_65 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
long V_80 ;
if ( F_35 ( V_62 , 10 , & V_80 ) == - V_45 )
return V_65 ;
V_12 -> V_81 ( V_12 , V_82 ,
V_80 / 1000 ) ;
return V_65 ;
}
static T_2
F_38 ( struct V_13 * V_60 , struct V_61 * V_5 , char * V_62 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
return snprintf ( V_62 , V_64 , L_17 ,
V_12 -> V_78 ( V_12 , V_83 ) * 1000 ) ;
}
static T_2
F_39 ( struct V_13 * V_60 , struct V_61 * V_5 ,
const char * V_62 , T_3 V_65 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
long V_80 ;
if ( F_35 ( V_62 , 10 , & V_80 ) == - V_45 )
return V_65 ;
V_12 -> V_81 ( V_12 , V_83 , V_80 / 1000 ) ;
return V_65 ;
}
static T_2
F_40 ( struct V_13 * V_60 , struct V_61 * V_5 ,
char * V_62 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
return snprintf ( V_62 , V_64 , L_17 ,
V_12 -> V_78 ( V_12 , V_84 ) * 1000 ) ;
}
static T_2
F_41 ( struct V_13 * V_60 , struct V_61 * V_5 ,
const char * V_62 , T_3 V_65 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
long V_80 ;
if ( F_35 ( V_62 , 10 , & V_80 ) == - V_45 )
return V_65 ;
V_12 -> V_81 ( V_12 , V_84 ,
V_80 / 1000 ) ;
return V_65 ;
}
static T_2
F_42 ( struct V_13 * V_60 , struct V_61 * V_5 ,
char * V_62 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
return snprintf ( V_62 , V_64 , L_17 ,
V_12 -> V_78 ( V_12 , V_85 ) * 1000 ) ;
}
static T_2
F_43 ( struct V_13 * V_60 , struct V_61 * V_5 ,
const char * V_62 ,
T_3 V_65 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
long V_80 ;
if ( F_35 ( V_62 , 10 , & V_80 ) == - V_45 )
return V_65 ;
V_12 -> V_81 ( V_12 , V_85 , V_80 / 1000 ) ;
return V_65 ;
}
static T_2
F_44 ( struct V_13 * V_60 , struct V_61 * V_5 ,
char * V_62 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
return snprintf ( V_62 , V_64 , L_17 ,
V_12 -> V_78 ( V_12 , V_86 ) * 1000 ) ;
}
static T_2
F_45 ( struct V_13 * V_60 ,
struct V_61 * V_5 ,
const char * V_62 ,
T_3 V_65 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
long V_80 ;
if ( F_35 ( V_62 , 10 , & V_80 ) == - V_45 )
return V_65 ;
V_12 -> V_81 ( V_12 , V_86 ,
V_80 / 1000 ) ;
return V_65 ;
}
static T_2
F_46 ( struct V_13 * V_60 , struct V_61 * V_5 ,
char * V_62 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
return snprintf ( V_62 , V_64 , L_17 ,
V_12 -> V_78 ( V_12 , V_87 ) * 1000 ) ;
}
static T_2
F_47 ( struct V_13 * V_60 , struct V_61 * V_5 ,
const char * V_62 ,
T_3 V_65 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
long V_80 ;
if ( F_35 ( V_62 , 10 , & V_80 ) == - V_45 )
return V_65 ;
V_12 -> V_81 ( V_12 , V_87 , V_80 / 1000 ) ;
return V_65 ;
}
static T_2
F_48 ( struct V_13 * V_60 , struct V_61 * V_5 ,
char * V_62 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
return snprintf ( V_62 , V_64 , L_17 ,
V_12 -> V_78 ( V_12 , V_88 ) * 1000 ) ;
}
static T_2
F_49 ( struct V_13 * V_60 ,
struct V_61 * V_5 ,
const char * V_62 ,
T_3 V_65 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
long V_80 ;
if ( F_35 ( V_62 , 10 , & V_80 ) == - V_45 )
return V_65 ;
V_12 -> V_81 ( V_12 , V_88 ,
V_80 / 1000 ) ;
return V_65 ;
}
static T_2 F_50 ( struct V_13 * V_2 ,
struct V_61 * V_70 ,
char * V_62 )
{
return sprintf ( V_62 , L_18 ) ;
}
static T_2 F_51 ( struct V_13 * V_2 ,
struct V_61 * V_70 ,
char * V_62 )
{
return sprintf ( V_62 , L_19 ) ;
}
static T_2
F_52 ( struct V_13 * V_60 , struct V_61 * V_70 ,
char * V_62 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
return snprintf ( V_62 , V_64 , L_17 , V_12 -> V_89 ( V_12 ) ) ;
}
static T_2
F_53 ( struct V_13 * V_60 ,
struct V_61 * V_5 , char * V_62 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
int V_14 ;
V_14 = V_12 -> V_78 ( V_12 , V_90 ) ;
if ( V_14 < 0 )
return V_14 ;
return sprintf ( V_62 , L_20 , V_14 ) ;
}
static T_2
F_54 ( struct V_13 * V_60 , struct V_61 * V_5 ,
const char * V_62 , T_3 V_65 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
long V_80 ;
int V_14 ;
if ( F_55 ( V_62 , 10 , & V_80 ) == - V_45 )
return - V_45 ;
V_14 = V_12 -> V_81 ( V_12 , V_90 , V_80 ) ;
if ( V_14 )
return V_14 ;
else
return V_65 ;
}
static T_2
F_56 ( struct V_13 * V_60 , struct V_61 * V_5 , char * V_62 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
int V_14 ;
V_14 = V_12 -> V_49 ( V_12 ) ;
if ( V_14 < 0 )
return V_14 ;
return sprintf ( V_62 , L_20 , V_14 ) ;
}
static T_2
F_57 ( struct V_13 * V_60 , struct V_61 * V_5 ,
const char * V_62 , T_3 V_65 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
int V_14 = - V_17 ;
long V_80 ;
if ( V_43 != 7777 )
return - V_44 ;
if ( F_35 ( V_62 , 10 , & V_80 ) == - V_45 )
return - V_45 ;
V_14 = V_12 -> V_15 ( V_12 , V_80 ) ;
if ( V_14 )
return V_14 ;
return V_65 ;
}
static T_2
F_58 ( struct V_13 * V_60 ,
struct V_61 * V_5 , char * V_62 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
int V_14 ;
V_14 = V_12 -> V_78 ( V_12 , V_91 ) ;
if ( V_14 < 0 )
return V_14 ;
return sprintf ( V_62 , L_20 , V_14 ) ;
}
static T_2
F_59 ( struct V_13 * V_60 , struct V_61 * V_5 ,
const char * V_62 , T_3 V_65 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
long V_80 ;
int V_14 ;
if ( F_35 ( V_62 , 10 , & V_80 ) == - V_45 )
return - V_45 ;
V_14 = V_12 -> V_81 ( V_12 , V_91 , V_80 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_65 ;
}
static T_2
F_60 ( struct V_13 * V_60 ,
struct V_61 * V_5 , char * V_62 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
int V_14 ;
V_14 = V_12 -> V_78 ( V_12 , V_92 ) ;
if ( V_14 < 0 )
return V_14 ;
return sprintf ( V_62 , L_20 , V_14 ) ;
}
static T_2
F_61 ( struct V_13 * V_60 , struct V_61 * V_5 ,
const char * V_62 , T_3 V_65 )
{
struct V_1 * V_2 = F_31 ( V_60 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
long V_80 ;
int V_14 ;
if ( F_35 ( V_62 , 10 , & V_80 ) == - V_45 )
return - V_45 ;
V_14 = V_12 -> V_81 ( V_12 , V_92 , V_80 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_65 ;
}
static int
F_62 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
#if F_63 ( V_93 ) || ( F_63 ( V_94 ) && F_63 ( V_95 ) )
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_11 * V_12 = V_11 ( V_8 -> V_13 ) ;
struct V_13 * V_96 ;
int V_14 = 0 ;
if ( ! V_12 || ! V_12 -> V_77 || ! V_12 -> V_78 || ! V_12 -> V_81 )
return - V_17 ;
V_96 = F_64 ( & V_2 -> V_66 -> V_2 ) ;
if ( F_4 ( V_96 ) ) {
V_14 = F_5 ( V_96 ) ;
F_2 ( V_8 , L_21 , V_14 ) ;
return V_14 ;
}
F_65 ( V_96 , V_2 ) ;
V_14 = F_66 ( & V_96 -> V_97 , & V_98 ) ;
if ( V_14 ) {
if ( V_14 )
goto error;
}
if ( V_12 -> V_77 ( V_12 ) >= 0 ) {
V_14 = F_66 ( & V_96 -> V_97 , & V_99 ) ;
if ( V_14 ) {
if ( V_14 )
goto error;
}
}
if ( V_12 -> V_49 && V_12 -> V_49 ( V_12 ) >= 0 ) {
V_14 = F_66 ( & V_96 -> V_97 ,
& V_100 ) ;
if ( V_14 )
goto error;
}
if ( V_12 -> V_89 ( V_12 ) >= 0 ) {
V_14 = F_66 ( & V_96 -> V_97 ,
& V_101 ) ;
if ( V_14 )
goto error;
}
V_10 -> V_102 = V_96 ;
return 0 ;
error:
F_2 ( V_8 , L_22 , V_14 ) ;
F_67 ( V_96 ) ;
V_10 -> V_102 = NULL ;
return V_14 ;
#else
V_10 -> V_102 = NULL ;
return 0 ;
#endif
}
static void
F_68 ( struct V_1 * V_2 )
{
#if F_63 ( V_93 ) || ( F_63 ( V_94 ) && F_63 ( V_95 ) )
struct V_9 * V_10 = V_9 ( V_2 ) ;
if ( V_10 -> V_102 ) {
F_69 ( & V_10 -> V_102 -> V_97 , & V_98 ) ;
F_69 ( & V_10 -> V_102 -> V_97 , & V_99 ) ;
F_69 ( & V_10 -> V_102 -> V_97 , & V_100 ) ;
F_69 ( & V_10 -> V_102 -> V_97 , & V_101 ) ;
F_67 ( V_10 -> V_102 ) ;
}
#endif
}
static int
F_70 ( struct V_103 * V_104 , unsigned long V_105 , void * V_106 )
{
struct V_9 * V_10 = F_15 ( V_104 , struct V_9 , V_107 ) ;
struct V_7 * V_8 = V_7 ( V_10 -> V_2 ) ;
struct V_108 * V_109 = (struct V_108 * ) V_106 ;
if ( strcmp ( V_109 -> V_110 , L_23 ) == 0 ) {
bool V_40 = F_7 () ;
F_71 ( V_8 , L_24 , V_40 ? L_25 : L_26 ) ;
F_6 ( V_10 -> V_2 ) ;
}
return V_111 ;
}
int
F_72 ( struct V_1 * V_2 )
{
struct V_112 * V_13 = F_73 ( V_2 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_9 * V_10 ;
char V_113 [ 256 ] ;
int V_14 , V_67 ;
V_10 = V_8 -> V_10 = F_74 ( sizeof( * V_10 ) , V_114 ) ;
if ( ! V_10 )
return - V_115 ;
V_10 -> V_2 = V_2 ;
if ( V_13 -> V_116 < V_117 ) {
V_10 -> V_46 = V_118 ;
V_10 -> V_24 = V_119 ;
V_10 -> V_25 = V_120 ;
if ( F_75 ( V_8 -> V_13 ) ) {
V_10 -> V_47 = V_121 ;
V_10 -> V_20 = V_122 ;
}
} else
if ( V_13 -> V_116 < V_123 ) {
V_10 -> V_46 = V_124 ;
V_10 -> V_24 = V_125 ;
V_10 -> V_25 = V_126 ;
V_10 -> V_47 = V_121 ;
V_10 -> V_20 = V_122 ;
} else
if ( V_13 -> V_116 < V_127 ) {
if ( V_13 -> V_128 < 0xa3 ||
V_13 -> V_128 == 0xaa ||
V_13 -> V_128 == 0xac ) {
V_10 -> V_46 = V_129 ;
V_10 -> V_24 = V_130 ;
V_10 -> V_25 = V_131 ;
} else {
V_10 -> V_46 = V_132 ;
V_10 -> V_24 = V_133 ;
V_10 -> V_25 = V_134 ;
}
V_10 -> V_47 = V_121 ;
V_10 -> V_20 = V_122 ;
} else
if ( V_13 -> V_116 < V_135 ) {
V_10 -> V_46 = V_136 ;
V_10 -> V_24 = V_137 ;
V_10 -> V_25 = V_138 ;
V_10 -> V_47 = V_121 ;
V_10 -> V_20 = V_122 ;
}
F_76 ( V_2 ) ;
F_77 ( & V_10 -> V_139 ) ;
V_14 = F_16 ( V_2 , & V_10 -> V_140 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_27 ) ;
return V_14 ;
}
strncpy ( V_10 -> V_140 . V_39 , L_28 , 4 ) ;
strncpy ( V_10 -> V_140 . V_29 . V_39 , L_28 , 4 ) ;
V_10 -> V_140 . V_29 . V_32 = & V_141 ;
F_78 ( & V_10 -> V_140 . V_29 . V_142 , & V_10 -> V_139 ) ;
V_10 -> V_30 = & V_10 -> V_140 . V_29 ;
V_10 -> V_31 = & V_10 -> V_140 . V_29 ;
V_10 -> V_29 = & V_10 -> V_140 . V_29 ;
V_10 -> V_23 = & V_10 -> V_140 ;
F_79 ( V_2 ) ;
F_8 ( V_8 , L_29 , V_10 -> V_69 ) ;
for ( V_67 = 0 ; V_67 < V_10 -> V_69 ; V_67 ++ ) {
F_18 ( & V_10 -> V_4 [ V_67 ] , V_113 , sizeof( V_113 ) ) ;
F_8 ( V_8 , L_30 , V_10 -> V_4 [ V_67 ] . V_38 , V_113 ) ;
}
F_18 ( & V_10 -> V_140 , V_113 , sizeof( V_113 ) ) ;
F_8 ( V_8 , L_31 , V_113 ) ;
if ( V_143 != NULL )
F_11 ( V_2 , V_143 ) ;
F_24 ( V_2 ) ;
F_62 ( V_2 ) ;
#if F_63 ( V_144 ) && F_63 ( V_145 )
V_10 -> V_107 . V_146 = F_70 ;
F_80 ( & V_10 -> V_107 ) ;
#endif
return 0 ;
}
void
F_27 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_28 * V_29 , * V_147 ;
F_81 (profile, tmp, &pm->profiles, head) {
F_82 ( & V_29 -> V_142 ) ;
V_29 -> V_32 -> V_148 ( V_29 ) ;
}
if ( V_10 -> V_23 != & V_10 -> V_140 )
F_3 ( V_2 , & V_10 -> V_140 ) ;
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
#if F_63 ( V_144 ) && F_63 ( V_145 )
F_85 ( & V_10 -> V_107 ) ;
#endif
F_68 ( V_2 ) ;
F_28 ( V_2 ) ;
V_7 ( V_2 ) -> V_10 = NULL ;
F_86 ( V_10 ) ;
}
void
F_87 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! V_10 -> V_23 || V_10 -> V_23 == & V_10 -> V_140 )
return;
V_4 = V_10 -> V_23 ;
V_10 -> V_23 = & V_10 -> V_140 ;
F_3 ( V_2 , V_4 ) ;
}
