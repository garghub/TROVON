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
int F_6 ( struct V_14 * V_15 , enum V_3 V_4 ,
char * V_28 [] )
{
struct V_29 * V_30 ;
const char * V_31 = V_8 [ V_4 ] ;
const char * V_32 = NULL ;
const char * V_33 ;
struct V_14 * V_34 ;
struct V_19 * V_19 ;
const struct V_35 * V_36 ;
int V_37 = 0 ;
int V_38 = 0 ;
#ifdef F_7
struct V_39 * V_40 ;
#endif
F_8 ( L_1 ,
F_9 ( V_15 ) , V_15 , V_41 ) ;
V_34 = V_15 ;
while ( ! V_34 -> V_19 && V_34 -> V_20 )
V_34 = V_34 -> V_20 ;
if ( ! V_34 -> V_19 ) {
F_8 ( L_2
L_3 , F_9 ( V_15 ) , V_15 ,
V_41 ) ;
return - V_6 ;
}
V_19 = V_34 -> V_19 ;
V_36 = V_19 -> V_36 ;
if ( V_15 -> V_42 ) {
F_8 ( L_4
L_5 ,
F_9 ( V_15 ) , V_15 , V_41 ) ;
return 0 ;
}
if ( V_36 && V_36 -> V_43 )
if ( ! V_36 -> V_43 ( V_19 , V_15 ) ) {
F_8 ( L_6
L_5 ,
F_9 ( V_15 ) , V_15 , V_41 ) ;
return 0 ;
}
if ( V_36 && V_36 -> V_44 )
V_33 = V_36 -> V_44 ( V_19 , V_15 ) ;
else
V_33 = F_9 ( & V_19 -> V_15 ) ;
if ( ! V_33 ) {
F_8 ( L_7
L_8 , F_9 ( V_15 ) , V_15 ,
V_41 ) ;
return 0 ;
}
V_30 = F_10 ( sizeof( struct V_29 ) , V_45 ) ;
if ( ! V_30 )
return - V_46 ;
V_32 = F_11 ( V_15 , V_45 ) ;
if ( ! V_32 ) {
V_38 = - V_47 ;
goto exit;
}
V_38 = F_12 ( V_30 , L_9 , V_31 ) ;
if ( V_38 )
goto exit;
V_38 = F_12 ( V_30 , L_10 , V_32 ) ;
if ( V_38 )
goto exit;
V_38 = F_12 ( V_30 , L_11 , V_33 ) ;
if ( V_38 )
goto exit;
if ( V_28 ) {
for ( V_37 = 0 ; V_28 [ V_37 ] ; V_37 ++ ) {
V_38 = F_12 ( V_30 , L_12 , V_28 [ V_37 ] ) ;
if ( V_38 )
goto exit;
}
}
if ( V_36 && V_36 -> V_48 ) {
V_38 = V_36 -> V_48 ( V_19 , V_15 , V_30 ) ;
if ( V_38 ) {
F_8 ( L_13
L_14 , F_9 ( V_15 ) , V_15 ,
V_41 , V_38 ) ;
goto exit;
}
}
if ( V_4 == V_49 )
V_15 -> V_50 = 1 ;
else if ( V_4 == V_51 )
V_15 -> V_52 = 1 ;
F_13 ( & V_53 ) ;
V_38 = F_12 ( V_30 , L_15 , ( unsigned long long ) ++ V_54 ) ;
if ( V_38 ) {
F_14 ( & V_53 ) ;
goto exit;
}
#if F_15 ( F_7 )
F_16 (ue_sk, &uevent_sock_list, list) {
struct V_9 * V_39 = V_40 -> V_55 ;
struct V_11 * V_12 ;
T_1 V_56 ;
if ( ! F_17 ( V_39 , 1 ) )
continue;
V_56 = strlen ( V_31 ) + strlen ( V_32 ) + 2 ;
V_12 = F_18 ( V_56 + V_30 -> V_57 , V_45 ) ;
if ( V_12 ) {
char * V_58 ;
V_58 = F_19 ( V_12 , V_56 ) ;
sprintf ( V_58 , L_16 , V_31 , V_32 ) ;
for ( V_37 = 0 ; V_37 < V_30 -> V_59 ; V_37 ++ ) {
V_56 = strlen ( V_30 -> V_60 [ V_37 ] ) + 1 ;
V_58 = F_19 ( V_12 , V_56 ) ;
strcpy ( V_58 , V_30 -> V_60 [ V_37 ] ) ;
}
F_20 ( V_12 ) . V_61 = 1 ;
V_38 = F_21 ( V_39 , V_12 ,
0 , 1 , V_45 ,
F_3 ,
V_15 ) ;
if ( V_38 == - V_62 || V_38 == - V_63 )
V_38 = 0 ;
} else
V_38 = - V_46 ;
}
#endif
F_14 ( & V_53 ) ;
if ( V_64 [ 0 ] && ! F_5 ( V_15 ) ) {
char * V_65 [ 3 ] ;
V_65 [ 0 ] = V_64 ;
V_65 [ 1 ] = ( char * ) V_33 ;
V_65 [ 2 ] = NULL ;
V_38 = F_12 ( V_30 , L_17 ) ;
if ( V_38 )
goto exit;
V_38 = F_12 ( V_30 ,
L_18 ) ;
if ( V_38 )
goto exit;
V_38 = F_22 ( V_65 [ 0 ] , V_65 ,
V_30 -> V_60 , V_66 ) ;
}
exit:
F_23 ( V_32 ) ;
F_23 ( V_30 ) ;
return V_38 ;
}
int F_24 ( struct V_14 * V_15 , enum V_3 V_4 )
{
return F_6 ( V_15 , V_4 , NULL ) ;
}
int F_12 ( struct V_29 * V_30 , const char * V_67 , ... )
{
T_2 args ;
int V_56 ;
if ( V_30 -> V_59 >= F_2 ( V_30 -> V_60 ) ) {
F_25 ( 1 , V_68 L_19 ) ;
return - V_46 ;
}
va_start ( args , V_67 ) ;
V_56 = vsnprintf ( & V_30 -> V_1 [ V_30 -> V_57 ] ,
sizeof( V_30 -> V_1 ) - V_30 -> V_57 ,
V_67 , args ) ;
va_end ( args ) ;
if ( V_56 >= ( sizeof( V_30 -> V_1 ) - V_30 -> V_57 ) ) {
F_25 ( 1 , V_68 L_20 ) ;
return - V_46 ;
}
V_30 -> V_60 [ V_30 -> V_59 ++ ] = & V_30 -> V_1 [ V_30 -> V_57 ] ;
V_30 -> V_57 += V_56 + 1 ;
return 0 ;
}
static int F_26 ( struct V_69 * V_69 )
{
struct V_39 * V_40 ;
struct V_70 V_71 = {
. V_72 = 1 ,
. V_73 = V_74 ,
} ;
V_40 = F_10 ( sizeof( * V_40 ) , V_45 ) ;
if ( ! V_40 )
return - V_46 ;
V_40 -> V_55 = F_27 ( V_69 , V_75 , & V_71 ) ;
if ( ! V_40 -> V_55 ) {
F_28 ( V_68
L_21 ) ;
F_23 ( V_40 ) ;
return - V_76 ;
}
F_13 ( & V_53 ) ;
F_29 ( & V_40 -> V_77 , & V_78 ) ;
F_14 ( & V_53 ) ;
return 0 ;
}
static void F_30 ( struct V_69 * V_69 )
{
struct V_39 * V_40 ;
F_13 ( & V_53 ) ;
F_16 (ue_sk, &uevent_sock_list, list) {
if ( F_31 ( V_40 -> V_55 ) == V_69 )
goto V_79;
}
F_14 ( & V_53 ) ;
return;
V_79:
F_32 ( & V_40 -> V_77 ) ;
F_14 ( & V_53 ) ;
F_33 ( V_40 -> V_55 ) ;
F_23 ( V_40 ) ;
}
static int T_3 F_34 ( void )
{
return F_35 ( & V_80 ) ;
}
