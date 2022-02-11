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
int F_11 ( struct V_23 * V_24 , enum V_3 V_4 ,
char * V_56 [] )
{
struct V_14 * V_16 ;
const char * V_57 = V_10 [ V_4 ] ;
const char * V_28 = NULL ;
const char * V_48 ;
struct V_23 * V_58 ;
struct V_39 * V_39 ;
const struct V_59 * V_60 ;
int V_61 = 0 ;
int V_62 = 0 ;
#ifdef F_21
struct V_63 * V_64 ;
#endif
F_22 ( L_10 ,
F_23 ( V_24 ) , V_24 , V_65 ) ;
V_58 = V_24 ;
while ( ! V_58 -> V_39 && V_58 -> V_40 )
V_58 = V_58 -> V_40 ;
if ( ! V_58 -> V_39 ) {
F_22 ( L_11
L_12 , F_23 ( V_24 ) , V_24 ,
V_65 ) ;
return - V_8 ;
}
V_39 = V_58 -> V_39 ;
V_60 = V_39 -> V_60 ;
if ( V_24 -> V_66 ) {
F_22 ( L_13
L_14 ,
F_23 ( V_24 ) , V_24 , V_65 ) ;
return 0 ;
}
if ( V_60 && V_60 -> V_67 )
if ( ! V_60 -> V_67 ( V_39 , V_24 ) ) {
F_22 ( L_15
L_14 ,
F_23 ( V_24 ) , V_24 , V_65 ) ;
return 0 ;
}
if ( V_60 && V_60 -> V_68 )
V_48 = V_60 -> V_68 ( V_39 , V_24 ) ;
else
V_48 = F_23 ( & V_39 -> V_24 ) ;
if ( ! V_48 ) {
F_22 ( L_16
L_17 , F_23 ( V_24 ) , V_24 ,
V_65 ) ;
return 0 ;
}
V_16 = F_6 ( sizeof( struct V_14 ) , V_20 ) ;
if ( ! V_16 )
return - V_21 ;
V_28 = F_12 ( V_24 , V_20 ) ;
if ( ! V_28 ) {
V_62 = - V_69 ;
goto exit;
}
V_62 = F_8 ( V_16 , L_18 , V_57 ) ;
if ( V_62 )
goto exit;
V_62 = F_8 ( V_16 , L_19 , V_28 ) ;
if ( V_62 )
goto exit;
V_62 = F_8 ( V_16 , L_20 , V_48 ) ;
if ( V_62 )
goto exit;
if ( V_56 ) {
for ( V_61 = 0 ; V_56 [ V_61 ] ; V_61 ++ ) {
V_62 = F_8 ( V_16 , L_21 , V_56 [ V_61 ] ) ;
if ( V_62 )
goto exit;
}
}
if ( V_60 && V_60 -> V_70 ) {
V_62 = V_60 -> V_70 ( V_39 , V_24 , V_16 ) ;
if ( V_62 ) {
F_22 ( L_22
L_23 , F_23 ( V_24 ) , V_24 ,
V_65 , V_62 ) ;
goto exit;
}
}
if ( V_4 == V_71 )
V_24 -> V_72 = 1 ;
else if ( V_4 == V_73 )
V_24 -> V_74 = 1 ;
F_24 ( & V_75 ) ;
V_62 = F_8 ( V_16 , L_24 , ( unsigned long long ) ++ V_76 ) ;
if ( V_62 ) {
F_25 ( & V_75 ) ;
goto exit;
}
#if F_26 ( F_21 )
F_27 (ue_sk, &uevent_sock_list, list) {
struct V_31 * V_63 = V_64 -> V_77 ;
struct V_33 * V_34 ;
T_1 V_49 ;
if ( ! F_28 ( V_63 , 1 ) )
continue;
V_49 = strlen ( V_57 ) + strlen ( V_28 ) + 2 ;
V_34 = F_29 ( V_49 + V_16 -> V_50 , V_20 ) ;
if ( V_34 ) {
char * V_78 ;
V_78 = F_30 ( V_34 , V_49 ) ;
sprintf ( V_78 , L_25 , V_57 , V_28 ) ;
for ( V_61 = 0 ; V_61 < V_16 -> V_79 ; V_61 ++ ) {
V_49 = strlen ( V_16 -> V_29 [ V_61 ] ) + 1 ;
V_78 = F_30 ( V_34 , V_49 ) ;
strcpy ( V_78 , V_16 -> V_29 [ V_61 ] ) ;
}
F_31 ( V_34 ) . V_80 = 1 ;
V_62 = F_32 ( V_63 , V_34 ,
0 , 1 , V_20 ,
F_14 ,
V_24 ) ;
if ( V_62 == - V_81 || V_62 == - V_82 )
V_62 = 0 ;
} else
V_62 = - V_21 ;
}
#endif
F_25 ( & V_75 ) ;
#ifdef F_33
if ( V_53 [ 0 ] && ! F_16 ( V_24 ) ) {
struct V_54 * V_55 ;
V_62 = F_8 ( V_16 , L_26 ) ;
if ( V_62 )
goto exit;
V_62 = F_8 ( V_16 ,
L_27 ) ;
if ( V_62 )
goto exit;
V_62 = F_17 ( V_16 , V_48 ) ;
if ( V_62 )
goto exit;
V_62 = - V_21 ;
V_55 = F_34 ( V_16 -> V_52 [ 0 ] , V_16 -> V_52 ,
V_16 -> V_29 , V_20 ,
NULL , F_20 , V_16 ) ;
if ( V_55 ) {
V_62 = F_35 ( V_55 , V_83 ) ;
V_16 = NULL ;
}
}
#endif
exit:
F_9 ( V_28 ) ;
F_9 ( V_16 ) ;
return V_62 ;
}
int F_36 ( struct V_23 * V_24 , enum V_3 V_4 )
{
return F_11 ( V_24 , V_4 , NULL ) ;
}
int F_8 ( struct V_14 * V_16 , const char * V_84 , ... )
{
T_2 args ;
int V_49 ;
if ( V_16 -> V_79 >= F_3 ( V_16 -> V_29 ) ) {
F_19 ( 1 , V_51 L_28 ) ;
return - V_21 ;
}
va_start ( args , V_84 ) ;
V_49 = vsnprintf ( & V_16 -> V_1 [ V_16 -> V_50 ] ,
sizeof( V_16 -> V_1 ) - V_16 -> V_50 ,
V_84 , args ) ;
va_end ( args ) ;
if ( V_49 >= ( sizeof( V_16 -> V_1 ) - V_16 -> V_50 ) ) {
F_19 ( 1 , V_51 L_29 ) ;
return - V_21 ;
}
V_16 -> V_29 [ V_16 -> V_79 ++ ] = & V_16 -> V_1 [ V_16 -> V_50 ] ;
V_16 -> V_50 += V_49 + 1 ;
return 0 ;
}
static int F_37 ( struct V_85 * V_85 )
{
struct V_63 * V_64 ;
struct V_86 V_87 = {
. V_88 = 1 ,
. V_89 = V_90 ,
} ;
V_64 = F_6 ( sizeof( * V_64 ) , V_20 ) ;
if ( ! V_64 )
return - V_21 ;
V_64 -> V_77 = F_38 ( V_85 , V_91 , & V_87 ) ;
if ( ! V_64 -> V_77 ) {
F_13 ( V_51
L_30 ) ;
F_9 ( V_64 ) ;
return - V_92 ;
}
F_24 ( & V_75 ) ;
F_39 ( & V_64 -> V_93 , & V_94 ) ;
F_25 ( & V_75 ) ;
return 0 ;
}
static void F_40 ( struct V_85 * V_85 )
{
struct V_63 * V_64 ;
F_24 ( & V_75 ) ;
F_27 (ue_sk, &uevent_sock_list, list) {
if ( F_41 ( V_64 -> V_77 ) == V_85 )
goto V_95;
}
F_25 ( & V_75 ) ;
return;
V_95:
F_42 ( & V_64 -> V_93 ) ;
F_25 ( & V_75 ) ;
F_43 ( V_64 -> V_77 ) ;
F_9 ( V_64 ) ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_96 ) ;
}
