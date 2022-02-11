static int F_1 ( const char * V_1 , T_1 V_2 ,
enum V_3 * type ,
const char * * args )
{
enum V_3 V_4 ;
T_1 V_5 ;
const char * V_6 ;
int V_7 = - V_8 ;
if ( V_2 && ( V_1 [ V_2 - 1 ] == '\n' || V_1 [ V_2 - 1 ] == '\0' ) )
V_2 -- ;
if ( ! V_2 )
goto V_9;
V_6 = F_2 ( V_1 , V_2 , ' ' ) ;
if ( V_6 ) {
V_5 = V_6 - V_1 ;
V_6 = V_6 + 1 ;
} else
V_5 = V_2 ;
for ( V_4 = 0 ; V_4 < F_3 ( V_10 ) ; V_4 ++ ) {
if ( strncmp ( V_10 [ V_4 ] , V_1 , V_5 ) != 0 )
continue;
if ( V_10 [ V_4 ] [ V_5 ] != '\0' )
continue;
if ( args )
* args = V_6 ;
* type = V_4 ;
V_7 = 0 ;
break;
}
V_9:
return V_7 ;
}
static const char * F_4 ( const char * V_1 , const char * V_11 ,
char V_12 )
{
const char * V_13 = V_1 ;
while ( V_13 <= V_11 && * V_13 != V_12 )
if ( ! isalnum ( * V_13 ++ ) )
return NULL ;
if ( V_13 == V_1 )
return NULL ;
return V_13 ;
}
static int F_5 ( const char * V_1 , T_1 V_2 ,
struct V_14 * * V_15 )
{
struct V_14 * V_16 = NULL ;
const char * V_13 , * V_11 , * V_17 ;
int V_18 ;
int V_19 = - V_8 ;
if ( V_2 && ( V_1 [ V_2 - 1 ] == '\n' || V_1 [ V_2 - 1 ] == '\0' ) )
V_2 -- ;
if ( ! V_2 )
return - V_8 ;
V_16 = F_6 ( sizeof( * V_16 ) , V_20 ) ;
if ( ! V_16 )
return - V_21 ;
if ( V_2 < V_22 || ! F_7 ( V_1 ) ||
F_8 ( V_16 , L_1 , V_22 , V_1 ) )
goto V_9;
V_13 = V_1 + V_22 ;
V_11 = V_1 + V_2 - 1 ;
while ( V_13 <= V_11 ) {
if ( * V_13 != ' ' )
goto V_9;
V_17 = ++ V_13 ;
if ( V_17 > V_11 )
goto V_9;
V_1 = V_13 ;
V_13 = F_4 ( V_1 , V_11 , '=' ) ;
if ( ! V_13 || V_13 > V_11 || * V_13 != '=' )
goto V_9;
V_18 = V_13 - V_1 ;
if ( ++ V_13 > V_11 )
goto V_9;
V_1 = V_13 ;
V_13 = F_4 ( V_1 , V_11 , ' ' ) ;
if ( ! V_13 )
goto V_9;
if ( F_8 ( V_16 , L_2 ,
V_18 , V_17 , ( int ) ( V_13 - V_1 ) , V_1 ) )
goto V_9;
}
V_19 = 0 ;
V_9:
if ( V_19 )
F_9 ( V_16 ) ;
else
* V_15 = V_16 ;
return V_19 ;
}
int F_10 ( struct V_23 * V_24 , const char * V_1 , T_1 V_2 )
{
char * V_25 [] = { L_3 , NULL } ;
enum V_3 V_4 ;
const char * V_26 ;
struct V_14 * V_16 ;
const char * V_27 = NULL , * V_28 ;
int V_19 ;
V_19 = F_1 ( V_1 , V_2 , & V_4 , & V_26 ) ;
if ( V_19 ) {
V_27 = L_4 ;
goto V_9;
}
if ( ! V_26 ) {
V_19 = F_11 ( V_24 , V_4 , V_25 ) ;
goto V_9;
}
V_19 = F_5 ( V_26 ,
V_2 - ( V_26 - V_1 ) , & V_16 ) ;
if ( V_19 == - V_8 ) {
V_27 = L_5 ;
goto V_9;
}
if ( V_19 )
goto V_9;
V_19 = F_11 ( V_24 , V_4 , V_16 -> V_29 ) ;
F_9 ( V_16 ) ;
V_9:
if ( V_19 ) {
V_28 = F_12 ( V_24 , V_20 ) ;
F_13 ( V_30 L_6 ,
V_28 ? : L_7 ,
V_27 ? : L_8 ) ;
F_9 ( V_28 ) ;
}
return V_19 ;
}
static int F_14 ( struct V_31 * V_32 , struct V_33 * V_34 , void * V_35 )
{
struct V_23 * V_24 = V_35 , * V_36 ;
const struct V_37 * V_38 ;
V_38 = F_15 ( V_24 ) ;
if ( ! V_38 && V_24 -> V_39 ) {
V_36 = & V_24 -> V_39 -> V_24 ;
if ( V_36 -> V_40 != NULL )
V_38 = F_15 ( V_36 -> V_40 ) ;
}
if ( V_38 && V_38 -> V_41 && V_24 -> V_42 -> V_43 ) {
const void * V_44 , * V_45 ;
V_45 = V_24 -> V_42 -> V_43 ( V_24 ) ;
V_44 = V_38 -> V_41 ( V_32 ) ;
return V_44 != V_45 ;
}
return 0 ;
}
static int F_16 ( struct V_23 * V_24 )
{
const struct V_37 * V_38 ;
V_38 = F_15 ( V_24 ) ;
if ( V_38 ) {
const void * V_46 , * V_45 ;
V_45 = V_24 -> V_42 -> V_43 ( V_24 ) ;
V_46 = V_38 -> V_47 () ;
return V_45 != V_46 ;
}
return 0 ;
}
static int F_17 ( struct V_14 * V_16 , const char * V_48 )
{
int V_49 ;
V_49 = F_18 ( & V_16 -> V_1 [ V_16 -> V_50 ] , V_48 ,
sizeof( V_16 -> V_1 ) - V_16 -> V_50 ) ;
if ( V_49 >= ( sizeof( V_16 -> V_1 ) - V_16 -> V_50 ) ) {
F_19 ( 1 , V_51 L_9 ) ;
return - V_21 ;
}
V_16 -> V_52 [ 0 ] = V_53 ;
V_16 -> V_52 [ 1 ] = & V_16 -> V_1 [ V_16 -> V_50 ] ;
V_16 -> V_52 [ 2 ] = NULL ;
V_16 -> V_50 += V_49 + 1 ;
return 0 ;
}
static void F_20 ( struct V_54 * V_55 )
{
F_9 ( V_55 -> V_35 ) ;
}
static void F_21 ( struct V_14 * V_16 )
{
static const char V_56 [] = L_10 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_16 -> V_58 ; ) {
if ( strncmp ( V_16 -> V_29 [ V_57 ] , V_56 ,
sizeof( V_56 ) - 1 ) ) {
V_57 ++ ;
continue;
}
if ( V_57 != V_16 -> V_58 - 1 )
memmove ( & V_16 -> V_29 [ V_57 ] , & V_16 -> V_29 [ V_57 + 1 ] ,
sizeof( V_16 -> V_29 [ V_57 ] ) * V_16 -> V_58 - 1 ) ;
V_16 -> V_58 -- ;
}
}
int F_11 ( struct V_23 * V_24 , enum V_3 V_4 ,
char * V_59 [] )
{
struct V_14 * V_16 ;
const char * V_60 = V_10 [ V_4 ] ;
const char * V_28 = NULL ;
const char * V_48 ;
struct V_23 * V_61 ;
struct V_39 * V_39 ;
const struct V_62 * V_63 ;
int V_57 = 0 ;
int V_64 = 0 ;
#ifdef F_22
struct V_65 * V_66 ;
#endif
F_23 ( L_11 ,
F_24 ( V_24 ) , V_24 , V_67 ) ;
V_61 = V_24 ;
while ( ! V_61 -> V_39 && V_61 -> V_40 )
V_61 = V_61 -> V_40 ;
if ( ! V_61 -> V_39 ) {
F_23 ( L_12
L_13 , F_24 ( V_24 ) , V_24 ,
V_67 ) ;
return - V_8 ;
}
V_39 = V_61 -> V_39 ;
V_63 = V_39 -> V_63 ;
if ( V_24 -> V_68 ) {
F_23 ( L_14
L_15 ,
F_24 ( V_24 ) , V_24 , V_67 ) ;
return 0 ;
}
if ( V_63 && V_63 -> V_69 )
if ( ! V_63 -> V_69 ( V_39 , V_24 ) ) {
F_23 ( L_16
L_15 ,
F_24 ( V_24 ) , V_24 , V_67 ) ;
return 0 ;
}
if ( V_63 && V_63 -> V_70 )
V_48 = V_63 -> V_70 ( V_39 , V_24 ) ;
else
V_48 = F_24 ( & V_39 -> V_24 ) ;
if ( ! V_48 ) {
F_23 ( L_17
L_18 , F_24 ( V_24 ) , V_24 ,
V_67 ) ;
return 0 ;
}
V_16 = F_6 ( sizeof( struct V_14 ) , V_20 ) ;
if ( ! V_16 )
return - V_21 ;
V_28 = F_12 ( V_24 , V_20 ) ;
if ( ! V_28 ) {
V_64 = - V_71 ;
goto exit;
}
V_64 = F_8 ( V_16 , L_19 , V_60 ) ;
if ( V_64 )
goto exit;
V_64 = F_8 ( V_16 , L_20 , V_28 ) ;
if ( V_64 )
goto exit;
V_64 = F_8 ( V_16 , L_21 , V_48 ) ;
if ( V_64 )
goto exit;
if ( V_59 ) {
for ( V_57 = 0 ; V_59 [ V_57 ] ; V_57 ++ ) {
V_64 = F_8 ( V_16 , L_22 , V_59 [ V_57 ] ) ;
if ( V_64 )
goto exit;
}
}
if ( V_63 && V_63 -> V_72 ) {
V_64 = V_63 -> V_72 ( V_39 , V_24 , V_16 ) ;
if ( V_64 ) {
F_23 ( L_23
L_24 , F_24 ( V_24 ) , V_24 ,
V_67 , V_64 ) ;
goto exit;
}
}
switch ( V_4 ) {
case V_73 :
V_24 -> V_74 = 1 ;
break;
case V_75 :
V_24 -> V_76 = 1 ;
break;
case V_77 :
F_21 ( V_16 ) ;
break;
default:
break;
}
F_25 ( & V_78 ) ;
V_64 = F_8 ( V_16 , L_25 , ( unsigned long long ) ++ V_79 ) ;
if ( V_64 ) {
F_26 ( & V_78 ) ;
goto exit;
}
#if F_27 ( F_22 )
F_28 (ue_sk, &uevent_sock_list, list) {
struct V_31 * V_65 = V_66 -> V_80 ;
struct V_33 * V_34 ;
T_1 V_49 ;
if ( ! F_29 ( V_65 , 1 ) )
continue;
V_49 = strlen ( V_60 ) + strlen ( V_28 ) + 2 ;
V_34 = F_30 ( V_49 + V_16 -> V_50 , V_20 ) ;
if ( V_34 ) {
char * V_81 ;
V_81 = F_31 ( V_34 , V_49 ) ;
sprintf ( V_81 , L_26 , V_60 , V_28 ) ;
for ( V_57 = 0 ; V_57 < V_16 -> V_58 ; V_57 ++ ) {
V_49 = strlen ( V_16 -> V_29 [ V_57 ] ) + 1 ;
V_81 = F_31 ( V_34 , V_49 ) ;
strcpy ( V_81 , V_16 -> V_29 [ V_57 ] ) ;
}
F_32 ( V_34 ) . V_82 = 1 ;
V_64 = F_33 ( V_65 , V_34 ,
0 , 1 , V_20 ,
F_14 ,
V_24 ) ;
if ( V_64 == - V_83 || V_64 == - V_84 )
V_64 = 0 ;
} else
V_64 = - V_21 ;
}
#endif
F_26 ( & V_78 ) ;
#ifdef F_34
if ( V_53 [ 0 ] && ! F_16 ( V_24 ) ) {
struct V_54 * V_55 ;
V_64 = F_8 ( V_16 , L_27 ) ;
if ( V_64 )
goto exit;
V_64 = F_8 ( V_16 ,
L_28 ) ;
if ( V_64 )
goto exit;
V_64 = F_17 ( V_16 , V_48 ) ;
if ( V_64 )
goto exit;
V_64 = - V_21 ;
V_55 = F_35 ( V_16 -> V_52 [ 0 ] , V_16 -> V_52 ,
V_16 -> V_29 , V_20 ,
NULL , F_20 , V_16 ) ;
if ( V_55 ) {
V_64 = F_36 ( V_55 , V_85 ) ;
V_16 = NULL ;
}
}
#endif
exit:
F_9 ( V_28 ) ;
F_9 ( V_16 ) ;
return V_64 ;
}
int F_37 ( struct V_23 * V_24 , enum V_3 V_4 )
{
return F_11 ( V_24 , V_4 , NULL ) ;
}
int F_8 ( struct V_14 * V_16 , const char * V_86 , ... )
{
T_2 args ;
int V_49 ;
if ( V_16 -> V_58 >= F_3 ( V_16 -> V_29 ) ) {
F_19 ( 1 , V_51 L_29 ) ;
return - V_21 ;
}
va_start ( args , V_86 ) ;
V_49 = vsnprintf ( & V_16 -> V_1 [ V_16 -> V_50 ] ,
sizeof( V_16 -> V_1 ) - V_16 -> V_50 ,
V_86 , args ) ;
va_end ( args ) ;
if ( V_49 >= ( sizeof( V_16 -> V_1 ) - V_16 -> V_50 ) ) {
F_19 ( 1 , V_51 L_30 ) ;
return - V_21 ;
}
V_16 -> V_29 [ V_16 -> V_58 ++ ] = & V_16 -> V_1 [ V_16 -> V_50 ] ;
V_16 -> V_50 += V_49 + 1 ;
return 0 ;
}
static int F_38 ( struct V_87 * V_87 )
{
struct V_65 * V_66 ;
struct V_88 V_89 = {
. V_90 = 1 ,
. V_91 = V_92 ,
} ;
V_66 = F_6 ( sizeof( * V_66 ) , V_20 ) ;
if ( ! V_66 )
return - V_21 ;
V_66 -> V_80 = F_39 ( V_87 , V_93 , & V_89 ) ;
if ( ! V_66 -> V_80 ) {
F_13 ( V_51
L_31 ) ;
F_9 ( V_66 ) ;
return - V_94 ;
}
F_25 ( & V_78 ) ;
F_40 ( & V_66 -> V_95 , & V_96 ) ;
F_26 ( & V_78 ) ;
return 0 ;
}
static void F_41 ( struct V_87 * V_87 )
{
struct V_65 * V_66 ;
F_25 ( & V_78 ) ;
F_28 (ue_sk, &uevent_sock_list, list) {
if ( F_42 ( V_66 -> V_80 ) == V_87 )
goto V_97;
}
F_26 ( & V_78 ) ;
return;
V_97:
F_43 ( & V_66 -> V_95 ) ;
F_26 ( & V_78 ) ;
F_44 ( V_66 -> V_80 ) ;
F_9 ( V_66 ) ;
}
static int T_3 F_45 ( void )
{
return F_46 ( & V_98 ) ;
}
