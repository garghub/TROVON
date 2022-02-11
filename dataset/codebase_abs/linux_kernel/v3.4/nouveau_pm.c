static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_9 V_10 ;
T_1 V_11 , V_12 ;
int V_13 ;
if ( ! V_7 -> V_14 )
return - V_15 ;
V_13 = F_2 ( V_2 , 0 , V_16 , 0xff , & V_10 ) ;
if ( V_13 == 0 ) {
V_13 = V_7 -> V_14 ( V_2 , V_10 . line , & V_11 , & V_12 ) ;
if ( V_13 == 0 && V_11 ) {
V_11 = F_3 ( V_11 , V_12 ) ;
if ( V_4 -> V_17 <= V_18 || ( V_10 . log [ 0 ] & 1 ) )
V_12 = V_11 - V_12 ;
return ( V_12 * 100 ) / V_11 ;
}
return F_4 ( V_2 , V_10 . V_19 ) * 100 ;
}
return - V_15 ;
}
static int
F_5 ( struct V_1 * V_2 , int V_20 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_9 V_10 ;
T_1 V_11 , V_12 ;
int V_13 ;
if ( ! V_7 -> V_21 )
return - V_15 ;
V_13 = F_2 ( V_2 , 0 , V_16 , 0xff , & V_10 ) ;
if ( V_13 == 0 ) {
V_11 = V_7 -> V_22 . V_23 ;
if ( V_7 -> V_22 . V_24 ) {
V_11 = 135000 / V_7 -> V_22 . V_24 ;
if ( V_4 -> V_25 < 0xa3 )
V_11 /= 4 ;
}
V_12 = ( ( V_11 * V_20 ) + 99 ) / 100 ;
if ( V_4 -> V_17 <= V_18 || ( V_10 . log [ 0 ] & 1 ) )
V_12 = V_11 - V_12 ;
V_13 = V_7 -> V_21 ( V_2 , V_10 . line , V_11 , V_12 ) ;
if ( ! V_13 )
V_7 -> V_22 . V_20 = V_20 ;
return V_13 ;
}
return - V_15 ;
}
static int
F_6 ( struct V_1 * V_2 , struct V_26 * V_27 ,
struct V_26 * V_28 , struct V_26 * V_29 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
int V_13 ;
if ( V_28 -> V_30 && V_29 -> V_30 && V_29 -> V_30 > V_28 -> V_30 ) {
V_13 = F_5 ( V_2 , V_27 -> V_30 ) ;
if ( V_13 && V_13 != - V_15 ) {
F_7 ( V_2 , L_1 , V_13 ) ;
return V_13 ;
}
}
if ( V_7 -> V_31 . V_32 && V_7 -> V_33 ) {
if ( V_27 -> V_34 && V_29 -> V_34 > V_28 -> V_34 ) {
V_13 = V_7 -> V_33 ( V_2 , V_27 -> V_34 ) ;
if ( V_13 ) {
F_7 ( V_2 , L_2 , V_13 ) ;
return V_13 ;
}
}
}
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
void * V_35 ;
int V_13 ;
if ( V_27 == V_7 -> V_36 )
return 0 ;
V_13 = F_6 ( V_2 , V_27 , V_7 -> V_36 , V_27 ) ;
if ( V_13 )
return V_13 ;
V_35 = V_7 -> V_37 ( V_2 , V_27 ) ;
if ( F_9 ( V_35 ) ) {
V_13 = F_10 ( V_35 ) ;
goto error;
}
V_13 = V_7 -> V_38 ( V_2 , V_35 ) ;
if ( V_13 )
goto error;
V_13 = F_6 ( V_2 , V_27 , V_27 , V_7 -> V_36 ) ;
if ( V_13 )
return V_13 ;
V_7 -> V_36 = V_27 ;
return 0 ;
error:
F_6 ( V_2 , V_27 , V_27 , V_7 -> V_36 ) ;
return V_13 ;
}
void
F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_39 * V_40 = NULL ;
struct V_26 * V_27 = NULL ;
int V_13 ;
if ( F_12 () )
V_40 = V_7 -> V_41 ;
else
V_40 = V_7 -> V_42 ;
if ( V_40 != V_7 -> V_40 ) {
V_7 -> V_40 -> V_19 -> V_43 ( V_7 -> V_40 ) ;
V_7 -> V_40 = V_40 ;
V_7 -> V_40 -> V_19 -> V_44 ( V_7 -> V_40 ) ;
}
V_27 = V_40 -> V_19 -> V_45 ( V_40 ) ;
if ( V_27 != V_7 -> V_36 ) {
struct V_46 * V_47 = & V_4 -> V_8 . V_48 ;
T_2 V_49 = V_47 -> V_50 ( V_2 ) ;
F_13 ( V_2 , L_3 , V_27 -> V_51 ) ;
V_13 = F_8 ( V_2 , V_27 ) ;
if ( V_13 )
F_13 ( V_2 , L_4 , V_13 ) ;
F_13 ( V_2 , L_5 ,
V_47 -> V_50 ( V_2 ) - V_49 ) ;
}
}
static struct V_39 *
F_14 ( struct V_1 * V_2 , const char * string )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_39 * V_40 ;
F_15 (profile, &pm->profiles, head) {
if ( ! strncmp ( V_40 -> V_52 , string , sizeof( V_40 -> V_52 ) ) )
return V_40 ;
}
return NULL ;
}
static int
F_16 ( struct V_1 * V_2 , const char * V_40 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_39 * V_53 = NULL , * V_54 = NULL ;
char string [ 16 ] , * V_36 = string , * V_55 ;
if ( V_56 != 7777 )
return - V_57 ;
strncpy ( string , V_40 , sizeof( string ) ) ;
string [ sizeof( string ) - 1 ] = 0 ;
if ( ( V_55 = strchr ( string , '\n' ) ) )
* V_55 = '\0' ;
V_55 = F_17 ( & V_36 , L_6 ) ;
if ( V_55 )
V_53 = F_14 ( V_2 , V_55 ) ;
V_55 = F_17 ( & V_36 , L_6 ) ;
if ( V_55 )
V_54 = F_14 ( V_2 , V_55 ) ;
else
V_54 = V_53 ;
if ( V_53 == NULL || V_54 == NULL )
return - V_58 ;
V_7 -> V_41 = V_53 ;
V_7 -> V_42 = V_54 ;
F_11 ( V_2 ) ;
return 0 ;
}
static void
F_18 ( struct V_39 * V_40 )
{
}
static struct V_26 *
F_19 ( struct V_39 * V_40 )
{
return F_20 ( V_40 , struct V_26 , V_40 ) ;
}
static int
F_21 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
int V_13 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
if ( V_7 -> V_59 ) {
V_13 = V_7 -> V_59 ( V_2 , V_27 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_7 -> V_31 . V_32 && V_7 -> V_60 ) {
V_13 = V_7 -> V_60 ( V_2 ) ;
if ( V_13 > 0 ) {
V_27 -> V_34 = V_13 ;
V_27 -> V_61 = V_13 ;
}
}
V_13 = F_1 ( V_2 ) ;
if ( V_13 > 0 )
V_27 -> V_30 = V_13 ;
F_22 ( V_2 , & V_27 -> V_62 ) ;
return 0 ;
}
static void
F_23 ( struct V_26 * V_27 , char * V_55 , int V_63 )
{
char V_64 [ 16 ] , V_65 [ 16 ] , V_66 [ 32 ] , V_67 [ 16 ] , V_68 [ 16 ] ;
V_64 [ 0 ] = '\0' ;
if ( V_27 -> V_69 )
snprintf ( V_64 , sizeof( V_64 ) , L_7 , V_27 -> V_69 / 1000 ) ;
V_65 [ 0 ] = '\0' ;
if ( V_27 -> V_70 )
snprintf ( V_65 , sizeof( V_65 ) , L_8 , V_27 -> V_70 / 1000 ) ;
V_68 [ 0 ] = '\0' ;
if ( V_27 -> V_71 )
snprintf ( V_68 , sizeof( V_68 ) , L_9 , V_27 -> V_71 / 1000 ) ;
V_66 [ 0 ] = '\0' ;
if ( V_27 -> V_34 && V_27 -> V_34 != V_27 -> V_61 ) {
snprintf ( V_66 , sizeof( V_66 ) , L_10 ,
V_27 -> V_34 / 1000 , V_27 -> V_61 / 1000 ) ;
} else
if ( V_27 -> V_34 ) {
snprintf ( V_66 , sizeof( V_66 ) , L_11 ,
V_27 -> V_34 / 1000 ) ;
}
V_67 [ 0 ] = '\0' ;
if ( V_27 -> V_30 )
snprintf ( V_67 , sizeof( V_67 ) , L_12 , V_27 -> V_30 ) ;
snprintf ( V_55 , V_63 , L_13 , V_64 , V_65 , V_68 , V_66 , V_67 ) ;
}
static T_3
F_24 ( struct V_72 * V_73 ,
struct V_74 * V_28 , char * V_75 )
{
struct V_26 * V_27 =
F_20 ( V_28 , struct V_26 , V_76 ) ;
char * V_55 = V_75 ;
int V_63 = V_77 ;
snprintf ( V_55 , V_63 , L_14 , V_27 -> V_51 ) ;
V_55 += strlen ( V_75 ) ;
V_63 -= strlen ( V_75 ) ;
F_23 ( V_27 , V_55 , V_63 ) ;
return strlen ( V_75 ) ;
}
static T_3
F_25 ( struct V_72 * V_73 , struct V_74 * V_28 , char * V_75 )
{
struct V_1 * V_2 = F_26 ( F_27 ( V_73 ) ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_26 V_36 ;
int V_63 = V_77 , V_13 ;
char * V_55 = V_75 ;
snprintf ( V_55 , V_63 , L_15 ,
V_7 -> V_41 -> V_52 , V_7 -> V_42 -> V_52 ) ;
V_55 += strlen ( V_75 ) ;
V_63 -= strlen ( V_75 ) ;
V_13 = F_21 ( V_2 , & V_36 ) ;
if ( V_13 == 0 )
F_23 ( & V_36 , V_55 , V_63 ) ;
return strlen ( V_75 ) ;
}
static T_3
F_28 ( struct V_72 * V_73 , struct V_74 * V_28 ,
const char * V_75 , T_4 V_78 )
{
struct V_1 * V_2 = F_26 ( F_27 ( V_73 ) ) ;
int V_13 ;
V_13 = F_16 ( V_2 , V_75 ) ;
if ( V_13 )
return V_13 ;
return strlen ( V_75 ) ;
}
static int
F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_72 * V_73 = & V_2 -> V_79 -> V_2 ;
int V_13 , V_80 ;
V_13 = F_30 ( V_73 , & V_81 ) ;
if ( V_13 )
return V_13 ;
for ( V_80 = 0 ; V_80 < V_7 -> V_82 ; V_80 ++ ) {
struct V_26 * V_27 = & V_7 -> V_27 [ V_80 ] ;
V_27 -> V_76 . V_83 . V_52 = V_27 -> V_52 ;
V_27 -> V_76 . V_83 . V_84 = V_85 ;
V_27 -> V_76 . V_86 = F_24 ;
V_27 -> V_76 . V_87 = NULL ;
F_31 ( & V_27 -> V_76 . V_83 ) ;
V_13 = F_30 ( V_73 , & V_27 -> V_76 ) ;
if ( V_13 ) {
F_7 ( V_2 , L_16 ,
V_27 -> V_51 , V_80 ) ;
V_27 -> V_76 . V_83 . V_52 = NULL ;
F_32 ( V_2 ) ;
return V_13 ;
}
}
return 0 ;
}
static void
F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_72 * V_73 = & V_2 -> V_79 -> V_2 ;
int V_80 ;
F_34 ( V_73 , & V_81 ) ;
for ( V_80 = 0 ; V_80 < V_7 -> V_82 ; V_80 ++ ) {
struct V_26 * V_88 = & V_7 -> V_27 [ V_80 ] ;
if ( ! V_88 -> V_76 . V_83 . V_52 )
break;
F_34 ( V_73 , & V_88 -> V_76 ) ;
}
}
static T_3
F_35 ( struct V_72 * V_73 , struct V_74 * V_28 , char * V_75 )
{
struct V_1 * V_2 = F_36 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
return snprintf ( V_75 , V_77 , L_17 , V_7 -> V_89 ( V_2 ) * 1000 ) ;
}
static T_3
F_37 ( struct V_72 * V_73 , struct V_74 * V_28 , char * V_75 )
{
struct V_1 * V_2 = F_36 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_90 * V_91 = & V_7 -> V_92 ;
return snprintf ( V_75 , V_77 , L_17 , V_91 -> V_93 * 1000 ) ;
}
static T_3
F_38 ( struct V_72 * V_73 , struct V_74 * V_28 ,
const char * V_75 , T_4 V_78 )
{
struct V_1 * V_2 = F_36 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_90 * V_91 = & V_7 -> V_92 ;
long V_94 ;
if ( F_39 ( V_75 , 10 , & V_94 ) == - V_58 )
return V_78 ;
V_91 -> V_93 = V_94 / 1000 ;
F_40 ( V_2 ) ;
return V_78 ;
}
static T_3
F_41 ( struct V_72 * V_73 , struct V_74 * V_28 ,
char * V_75 )
{
struct V_1 * V_2 = F_36 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_90 * V_91 = & V_7 -> V_92 ;
return snprintf ( V_75 , V_77 , L_17 , V_91 -> V_95 * 1000 ) ;
}
static T_3
F_42 ( struct V_72 * V_73 , struct V_74 * V_28 ,
const char * V_75 ,
T_4 V_78 )
{
struct V_1 * V_2 = F_36 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_90 * V_91 = & V_7 -> V_92 ;
long V_94 ;
if ( F_39 ( V_75 , 10 , & V_94 ) == - V_58 )
return V_78 ;
V_91 -> V_95 = V_94 / 1000 ;
F_40 ( V_2 ) ;
return V_78 ;
}
static T_3 F_43 ( struct V_72 * V_2 ,
struct V_74 * V_83 ,
char * V_75 )
{
return sprintf ( V_75 , L_18 ) ;
}
static T_3 F_44 ( struct V_72 * V_2 ,
struct V_74 * V_83 ,
char * V_75 )
{
return sprintf ( V_75 , L_19 ) ;
}
static T_3
F_45 ( struct V_72 * V_73 , struct V_74 * V_83 ,
char * V_75 )
{
struct V_1 * V_2 = F_36 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_46 * V_47 = & V_4 -> V_8 . V_48 ;
struct V_9 V_10 ;
T_1 V_96 , V_36 , V_97 ;
T_2 V_98 ;
int V_13 ;
V_13 = F_2 ( V_2 , 0 , V_99 , 0xff , & V_10 ) ;
if ( V_13 )
return V_13 ;
V_98 = V_47 -> V_50 ( V_2 ) ;
V_97 = F_46 ( V_2 , 0 , V_10 . line ) ;
V_96 = 0 ;
do {
V_36 = F_46 ( V_2 , 0 , V_10 . line ) ;
if ( V_97 != V_36 ) {
V_96 ++ ;
V_97 = V_36 ;
}
F_47 ( 500 , 1000 ) ;
} while ( V_47 -> V_50 ( V_2 ) - V_98 < 250000000 );
return sprintf ( V_75 , L_20 , V_96 / 4 * 4 * 60 ) ;
}
static T_3
F_48 ( struct V_72 * V_73 , struct V_74 * V_28 , char * V_75 )
{
struct V_1 * V_2 = F_36 ( V_73 ) ;
int V_13 ;
V_13 = F_1 ( V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_75 , L_20 , V_13 ) ;
}
static T_3
F_49 ( struct V_72 * V_73 , struct V_74 * V_28 ,
const char * V_75 , T_4 V_78 )
{
struct V_1 * V_2 = F_36 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
int V_13 = - V_15 ;
long V_94 ;
if ( V_56 != 7777 )
return - V_57 ;
if ( F_39 ( V_75 , 10 , & V_94 ) == - V_58 )
return - V_58 ;
if ( V_94 < V_7 -> V_22 . V_100 )
V_94 = V_7 -> V_22 . V_100 ;
if ( V_94 > V_7 -> V_22 . V_101 )
V_94 = V_7 -> V_22 . V_101 ;
V_13 = F_5 ( V_2 , V_94 ) ;
if ( V_13 )
return V_13 ;
return V_78 ;
}
static T_3
F_50 ( struct V_72 * V_73 ,
struct V_74 * V_28 , char * V_75 )
{
struct V_1 * V_2 = F_36 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
return sprintf ( V_75 , L_20 , V_7 -> V_22 . V_100 ) ;
}
static T_3
F_51 ( struct V_72 * V_73 , struct V_74 * V_28 ,
const char * V_75 , T_4 V_78 )
{
struct V_1 * V_2 = F_36 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
long V_94 ;
if ( F_39 ( V_75 , 10 , & V_94 ) == - V_58 )
return - V_58 ;
if ( V_94 < 0 )
V_94 = 0 ;
if ( V_7 -> V_22 . V_101 - V_94 < 10 )
V_94 = V_7 -> V_22 . V_101 - 10 ;
if ( V_94 < 10 )
V_7 -> V_22 . V_100 = 10 ;
else
V_7 -> V_22 . V_100 = V_94 ;
return V_78 ;
}
static T_3
F_52 ( struct V_72 * V_73 ,
struct V_74 * V_28 , char * V_75 )
{
struct V_1 * V_2 = F_36 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
return sprintf ( V_75 , L_20 , V_7 -> V_22 . V_101 ) ;
}
static T_3
F_53 ( struct V_72 * V_73 , struct V_74 * V_28 ,
const char * V_75 , T_4 V_78 )
{
struct V_1 * V_2 = F_36 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
long V_94 ;
if ( F_39 ( V_75 , 10 , & V_94 ) == - V_58 )
return - V_58 ;
if ( V_94 < 0 )
V_94 = 0 ;
if ( V_94 - V_7 -> V_22 . V_100 < 10 )
V_94 = V_7 -> V_22 . V_100 + 10 ;
if ( V_94 > 100 )
V_7 -> V_22 . V_101 = 100 ;
else
V_7 -> V_22 . V_101 = V_94 ;
return V_78 ;
}
static int
F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
#if F_55 ( V_102 ) || ( F_55 ( V_103 ) && F_55 ( V_104 ) )
struct V_72 * V_105 ;
int V_13 = 0 ;
if ( ! V_7 -> V_89 )
return - V_15 ;
V_105 = F_56 ( & V_2 -> V_79 -> V_2 ) ;
if ( F_9 ( V_105 ) ) {
V_13 = F_10 ( V_105 ) ;
F_7 ( V_2 ,
L_21 , V_13 ) ;
return V_13 ;
}
F_57 ( V_105 , V_2 ) ;
V_13 = F_58 ( & V_2 -> V_79 -> V_2 . V_106 , & V_107 ) ;
if ( V_13 ) {
if ( V_13 )
goto error;
}
if ( F_1 ( V_2 ) >= 0 ) {
V_13 = F_58 ( & V_2 -> V_79 -> V_2 . V_106 ,
& V_108 ) ;
if ( V_13 )
goto error;
}
if ( F_59 ( V_2 , V_99 ) ) {
V_13 = F_58 ( & V_2 -> V_79 -> V_2 . V_106 ,
& V_109 ) ;
if ( V_13 )
goto error;
}
V_7 -> V_110 = V_105 ;
return 0 ;
error:
F_7 ( V_2 , L_22 , V_13 ) ;
F_60 ( V_105 ) ;
V_7 -> V_110 = NULL ;
return V_13 ;
#else
V_7 -> V_110 = NULL ;
return 0 ;
#endif
}
static void
F_61 ( struct V_1 * V_2 )
{
#if F_55 ( V_102 ) || ( F_55 ( V_103 ) && F_55 ( V_104 ) )
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
if ( V_7 -> V_110 ) {
F_62 ( & V_2 -> V_79 -> V_2 . V_106 , & V_107 ) ;
F_62 ( & V_2 -> V_79 -> V_2 . V_106 ,
& V_108 ) ;
F_62 ( & V_2 -> V_79 -> V_2 . V_106 ,
& V_109 ) ;
F_60 ( V_7 -> V_110 ) ;
}
#endif
}
static int
F_63 ( struct V_111 * V_112 , unsigned long V_113 , void * V_114 )
{
struct V_3 * V_4 =
F_20 ( V_112 , struct V_3 , V_8 . V_7 . V_115 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_116 * V_117 = (struct V_116 * ) V_114 ;
if ( strcmp ( V_117 -> V_118 , L_23 ) == 0 ) {
bool V_53 = F_12 () ;
F_64 ( V_2 , L_24 , V_53 ? L_25 : L_26 ) ;
F_11 ( V_2 ) ;
}
return V_119 ;
}
int
F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
char V_120 [ 256 ] ;
int V_13 , V_80 ;
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
V_13 = F_21 ( V_2 , & V_7 -> V_121 ) ;
if ( V_13 ) {
F_7 ( V_2 , L_27 ) ;
return V_13 ;
}
strncpy ( V_7 -> V_121 . V_52 , L_28 , 4 ) ;
strncpy ( V_7 -> V_121 . V_40 . V_52 , L_28 , 4 ) ;
V_7 -> V_121 . V_40 . V_19 = & V_122 ;
F_68 ( & V_7 -> V_123 ) ;
F_69 ( & V_7 -> V_121 . V_40 . V_124 , & V_7 -> V_123 ) ;
V_7 -> V_41 = & V_7 -> V_121 . V_40 ;
V_7 -> V_42 = & V_7 -> V_121 . V_40 ;
V_7 -> V_40 = & V_7 -> V_121 . V_40 ;
V_7 -> V_36 = & V_7 -> V_121 ;
F_70 ( V_2 ) ;
F_13 ( V_2 , L_29 , V_7 -> V_82 ) ;
for ( V_80 = 0 ; V_80 < V_7 -> V_82 ; V_80 ++ ) {
F_23 ( & V_7 -> V_27 [ V_80 ] , V_120 , sizeof( V_120 ) ) ;
F_13 ( V_2 , L_30 , V_7 -> V_27 [ V_80 ] . V_51 , V_120 ) ;
}
F_23 ( & V_7 -> V_121 , V_120 , sizeof( V_120 ) ) ;
F_13 ( V_2 , L_31 , V_120 ) ;
if ( V_125 != NULL )
F_16 ( V_2 , V_125 ) ;
V_7 -> V_22 . V_20 = F_1 ( V_2 ) ;
F_29 ( V_2 ) ;
F_54 ( V_2 ) ;
#if F_55 ( V_126 ) && F_55 ( V_127 )
V_7 -> V_115 . V_128 = F_63 ;
F_71 ( & V_7 -> V_115 ) ;
#endif
return 0 ;
}
void
F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_39 * V_40 , * V_129 ;
F_72 (profile, tmp, &pm->profiles, head) {
F_73 ( & V_40 -> V_124 ) ;
V_40 -> V_19 -> V_130 ( V_40 ) ;
}
if ( V_7 -> V_36 != & V_7 -> V_121 )
F_8 ( V_2 , & V_7 -> V_121 ) ;
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
F_76 ( V_2 ) ;
#if F_55 ( V_126 ) && F_55 ( V_127 )
F_77 ( & V_7 -> V_115 ) ;
#endif
F_61 ( V_2 ) ;
F_33 ( V_2 ) ;
}
void
F_78 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_26 * V_27 ;
if ( ! V_7 -> V_36 || V_7 -> V_36 == & V_7 -> V_121 )
return;
V_27 = V_7 -> V_36 ;
V_7 -> V_36 = & V_7 -> V_121 ;
F_8 ( V_2 , V_27 ) ;
F_5 ( V_2 , V_7 -> V_22 . V_20 ) ;
}
