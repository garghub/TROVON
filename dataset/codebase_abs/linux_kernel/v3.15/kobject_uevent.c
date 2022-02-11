int F_1 ( const char * V_1 , T_1 V_2 ,
enum V_3 * type )
{
enum V_3 V_4 ;
int V_5 = - V_6 ;
if ( V_2 && ( V_1 [ V_2 - 1 ] == '\n' || V_1 [ V_2 - 1 ] == '\0' ) )
V_2 -- ;
if ( ! V_2 )
goto V_7;
for ( V_4 = 0 ; V_4 < F_2 ( V_8 ) ; V_4 ++ ) {
if ( strncmp ( V_8 [ V_4 ] , V_1 , V_2 ) != 0 )
continue;
if ( V_8 [ V_4 ] [ V_2 ] != '\0' )
continue;
* type = V_4 ;
V_5 = 0 ;
break;
}
V_7:
return V_5 ;
}
static int F_3 ( struct V_9 * V_10 , struct V_11 * V_12 , void * V_13 )
{
struct V_14 * V_15 = V_13 , * V_16 ;
const struct V_17 * V_18 ;
V_18 = F_4 ( V_15 ) ;
if ( ! V_18 && V_15 -> V_19 ) {
V_16 = & V_15 -> V_19 -> V_15 ;
if ( V_16 -> V_20 != NULL )
V_18 = F_4 ( V_16 -> V_20 ) ;
}
if ( V_18 && V_18 -> V_21 && V_15 -> V_22 -> V_23 ) {
const void * V_24 , * V_25 ;
V_25 = V_15 -> V_22 -> V_23 ( V_15 ) ;
V_24 = V_18 -> V_21 ( V_10 ) ;
return V_24 != V_25 ;
}
return 0 ;
}
static int F_5 ( struct V_14 * V_15 )
{
const struct V_17 * V_18 ;
V_18 = F_4 ( V_15 ) ;
if ( V_18 ) {
const void * V_26 , * V_25 ;
V_25 = V_15 -> V_22 -> V_23 ( V_15 ) ;
V_26 = V_18 -> V_27 () ;
return V_25 != V_26 ;
}
return 0 ;
}
static int F_6 ( struct V_28 * V_29 , const char * V_30 )
{
int V_31 ;
V_31 = F_7 ( & V_29 -> V_1 [ V_29 -> V_32 ] , V_30 ,
sizeof( V_29 -> V_1 ) - V_29 -> V_32 ) ;
if ( V_31 >= ( sizeof( V_29 -> V_1 ) - V_29 -> V_32 ) ) {
F_8 ( 1 , V_33 L_1 ) ;
return - V_34 ;
}
V_29 -> V_35 [ 0 ] = V_36 ;
V_29 -> V_35 [ 1 ] = & V_29 -> V_1 [ V_29 -> V_32 ] ;
V_29 -> V_35 [ 2 ] = NULL ;
V_29 -> V_32 += V_31 + 1 ;
return 0 ;
}
static void F_9 ( struct V_37 * V_38 )
{
F_10 ( V_38 -> V_13 ) ;
}
int F_11 ( struct V_14 * V_15 , enum V_3 V_4 ,
char * V_39 [] )
{
struct V_28 * V_29 ;
const char * V_40 = V_8 [ V_4 ] ;
const char * V_41 = NULL ;
const char * V_30 ;
struct V_14 * V_42 ;
struct V_19 * V_19 ;
const struct V_43 * V_44 ;
int V_45 = 0 ;
int V_46 = 0 ;
#ifdef F_12
struct V_47 * V_48 ;
#endif
F_13 ( L_2 ,
F_14 ( V_15 ) , V_15 , V_49 ) ;
V_42 = V_15 ;
while ( ! V_42 -> V_19 && V_42 -> V_20 )
V_42 = V_42 -> V_20 ;
if ( ! V_42 -> V_19 ) {
F_13 ( L_3
L_4 , F_14 ( V_15 ) , V_15 ,
V_49 ) ;
return - V_6 ;
}
V_19 = V_42 -> V_19 ;
V_44 = V_19 -> V_44 ;
if ( V_15 -> V_50 ) {
F_13 ( L_5
L_6 ,
F_14 ( V_15 ) , V_15 , V_49 ) ;
return 0 ;
}
if ( V_44 && V_44 -> V_51 )
if ( ! V_44 -> V_51 ( V_19 , V_15 ) ) {
F_13 ( L_7
L_6 ,
F_14 ( V_15 ) , V_15 , V_49 ) ;
return 0 ;
}
if ( V_44 && V_44 -> V_52 )
V_30 = V_44 -> V_52 ( V_19 , V_15 ) ;
else
V_30 = F_14 ( & V_19 -> V_15 ) ;
if ( ! V_30 ) {
F_13 ( L_8
L_9 , F_14 ( V_15 ) , V_15 ,
V_49 ) ;
return 0 ;
}
V_29 = F_15 ( sizeof( struct V_28 ) , V_53 ) ;
if ( ! V_29 )
return - V_34 ;
V_41 = F_16 ( V_15 , V_53 ) ;
if ( ! V_41 ) {
V_46 = - V_54 ;
goto exit;
}
V_46 = F_17 ( V_29 , L_10 , V_40 ) ;
if ( V_46 )
goto exit;
V_46 = F_17 ( V_29 , L_11 , V_41 ) ;
if ( V_46 )
goto exit;
V_46 = F_17 ( V_29 , L_12 , V_30 ) ;
if ( V_46 )
goto exit;
if ( V_39 ) {
for ( V_45 = 0 ; V_39 [ V_45 ] ; V_45 ++ ) {
V_46 = F_17 ( V_29 , L_13 , V_39 [ V_45 ] ) ;
if ( V_46 )
goto exit;
}
}
if ( V_44 && V_44 -> V_55 ) {
V_46 = V_44 -> V_55 ( V_19 , V_15 , V_29 ) ;
if ( V_46 ) {
F_13 ( L_14
L_15 , F_14 ( V_15 ) , V_15 ,
V_49 , V_46 ) ;
goto exit;
}
}
if ( V_4 == V_56 )
V_15 -> V_57 = 1 ;
else if ( V_4 == V_58 )
V_15 -> V_59 = 1 ;
F_18 ( & V_60 ) ;
V_46 = F_17 ( V_29 , L_16 , ( unsigned long long ) ++ V_61 ) ;
if ( V_46 ) {
F_19 ( & V_60 ) ;
goto exit;
}
#if F_20 ( F_12 )
F_21 (ue_sk, &uevent_sock_list, list) {
struct V_9 * V_47 = V_48 -> V_62 ;
struct V_11 * V_12 ;
T_1 V_31 ;
if ( ! F_22 ( V_47 , 1 ) )
continue;
V_31 = strlen ( V_40 ) + strlen ( V_41 ) + 2 ;
V_12 = F_23 ( V_31 + V_29 -> V_32 , V_53 ) ;
if ( V_12 ) {
char * V_63 ;
V_63 = F_24 ( V_12 , V_31 ) ;
sprintf ( V_63 , L_17 , V_40 , V_41 ) ;
for ( V_45 = 0 ; V_45 < V_29 -> V_64 ; V_45 ++ ) {
V_31 = strlen ( V_29 -> V_65 [ V_45 ] ) + 1 ;
V_63 = F_24 ( V_12 , V_31 ) ;
strcpy ( V_63 , V_29 -> V_65 [ V_45 ] ) ;
}
F_25 ( V_12 ) . V_66 = 1 ;
V_46 = F_26 ( V_47 , V_12 ,
0 , 1 , V_53 ,
F_3 ,
V_15 ) ;
if ( V_46 == - V_67 || V_46 == - V_68 )
V_46 = 0 ;
} else
V_46 = - V_34 ;
}
#endif
F_19 ( & V_60 ) ;
if ( V_36 [ 0 ] && ! F_5 ( V_15 ) ) {
struct V_37 * V_38 ;
V_46 = F_17 ( V_29 , L_18 ) ;
if ( V_46 )
goto exit;
V_46 = F_17 ( V_29 ,
L_19 ) ;
if ( V_46 )
goto exit;
V_46 = F_6 ( V_29 , V_30 ) ;
if ( V_46 )
goto exit;
V_46 = - V_34 ;
V_38 = F_27 ( V_29 -> V_35 [ 0 ] , V_29 -> V_35 ,
V_29 -> V_65 , V_53 ,
NULL , F_9 , V_29 ) ;
if ( V_38 ) {
V_46 = F_28 ( V_38 , V_69 ) ;
V_29 = NULL ;
}
}
exit:
F_10 ( V_41 ) ;
F_10 ( V_29 ) ;
return V_46 ;
}
int F_29 ( struct V_14 * V_15 , enum V_3 V_4 )
{
return F_11 ( V_15 , V_4 , NULL ) ;
}
int F_17 ( struct V_28 * V_29 , const char * V_70 , ... )
{
T_2 args ;
int V_31 ;
if ( V_29 -> V_64 >= F_2 ( V_29 -> V_65 ) ) {
F_8 ( 1 , V_33 L_20 ) ;
return - V_34 ;
}
va_start ( args , V_70 ) ;
V_31 = vsnprintf ( & V_29 -> V_1 [ V_29 -> V_32 ] ,
sizeof( V_29 -> V_1 ) - V_29 -> V_32 ,
V_70 , args ) ;
va_end ( args ) ;
if ( V_31 >= ( sizeof( V_29 -> V_1 ) - V_29 -> V_32 ) ) {
F_8 ( 1 , V_33 L_21 ) ;
return - V_34 ;
}
V_29 -> V_65 [ V_29 -> V_64 ++ ] = & V_29 -> V_1 [ V_29 -> V_32 ] ;
V_29 -> V_32 += V_31 + 1 ;
return 0 ;
}
static int F_30 ( struct V_71 * V_71 )
{
struct V_47 * V_48 ;
struct V_72 V_73 = {
. V_74 = 1 ,
. V_75 = V_76 ,
} ;
V_48 = F_15 ( sizeof( * V_48 ) , V_53 ) ;
if ( ! V_48 )
return - V_34 ;
V_48 -> V_62 = F_31 ( V_71 , V_77 , & V_73 ) ;
if ( ! V_48 -> V_62 ) {
F_32 ( V_33
L_22 ) ;
F_10 ( V_48 ) ;
return - V_78 ;
}
F_18 ( & V_60 ) ;
F_33 ( & V_48 -> V_79 , & V_80 ) ;
F_19 ( & V_60 ) ;
return 0 ;
}
static void F_34 ( struct V_71 * V_71 )
{
struct V_47 * V_48 ;
F_18 ( & V_60 ) ;
F_21 (ue_sk, &uevent_sock_list, list) {
if ( F_35 ( V_48 -> V_62 ) == V_71 )
goto V_81;
}
F_19 ( & V_60 ) ;
return;
V_81:
F_36 ( & V_48 -> V_79 ) ;
F_19 ( & V_60 ) ;
F_37 ( V_48 -> V_62 ) ;
F_10 ( V_48 ) ;
}
static int T_3 F_38 ( void )
{
return F_39 ( & V_82 ) ;
}
