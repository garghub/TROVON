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
struct V_14 * V_15 = V_13 ;
const struct V_16 * V_17 ;
V_17 = F_4 ( V_15 ) ;
if ( V_17 ) {
const void * V_18 , * V_19 ;
V_19 = V_15 -> V_20 -> V_21 ( V_15 ) ;
V_18 = V_17 -> V_22 ( V_10 ) ;
return V_18 != V_19 ;
}
return 0 ;
}
static int F_5 ( struct V_14 * V_15 )
{
const struct V_16 * V_17 ;
V_17 = F_4 ( V_15 ) ;
if ( V_17 ) {
const void * V_23 , * V_19 ;
V_19 = V_15 -> V_20 -> V_21 ( V_15 ) ;
V_23 = V_17 -> V_24 () ;
return V_19 != V_23 ;
}
return 0 ;
}
int F_6 ( struct V_14 * V_15 , enum V_3 V_4 ,
char * V_25 [] )
{
struct V_26 * V_27 ;
const char * V_28 = V_8 [ V_4 ] ;
const char * V_29 = NULL ;
const char * V_30 ;
struct V_14 * V_31 ;
struct V_32 * V_32 ;
const struct V_33 * V_34 ;
int V_35 = 0 ;
int V_36 = 0 ;
#ifdef F_7
struct V_37 * V_38 ;
#endif
F_8 ( L_1 ,
F_9 ( V_15 ) , V_15 , V_39 ) ;
V_31 = V_15 ;
while ( ! V_31 -> V_32 && V_31 -> V_40 )
V_31 = V_31 -> V_40 ;
if ( ! V_31 -> V_32 ) {
F_8 ( L_2
L_3 , F_9 ( V_15 ) , V_15 ,
V_39 ) ;
return - V_6 ;
}
V_32 = V_31 -> V_32 ;
V_34 = V_32 -> V_34 ;
if ( V_15 -> V_41 ) {
F_8 ( L_4
L_5 ,
F_9 ( V_15 ) , V_15 , V_39 ) ;
return 0 ;
}
if ( V_34 && V_34 -> V_42 )
if ( ! V_34 -> V_42 ( V_32 , V_15 ) ) {
F_8 ( L_6
L_5 ,
F_9 ( V_15 ) , V_15 , V_39 ) ;
return 0 ;
}
if ( V_34 && V_34 -> V_43 )
V_30 = V_34 -> V_43 ( V_32 , V_15 ) ;
else
V_30 = F_9 ( & V_32 -> V_15 ) ;
if ( ! V_30 ) {
F_8 ( L_7
L_8 , F_9 ( V_15 ) , V_15 ,
V_39 ) ;
return 0 ;
}
V_27 = F_10 ( sizeof( struct V_26 ) , V_44 ) ;
if ( ! V_27 )
return - V_45 ;
V_29 = F_11 ( V_15 , V_44 ) ;
if ( ! V_29 ) {
V_36 = - V_46 ;
goto exit;
}
V_36 = F_12 ( V_27 , L_9 , V_28 ) ;
if ( V_36 )
goto exit;
V_36 = F_12 ( V_27 , L_10 , V_29 ) ;
if ( V_36 )
goto exit;
V_36 = F_12 ( V_27 , L_11 , V_30 ) ;
if ( V_36 )
goto exit;
if ( V_25 ) {
for ( V_35 = 0 ; V_25 [ V_35 ] ; V_35 ++ ) {
V_36 = F_12 ( V_27 , L_12 , V_25 [ V_35 ] ) ;
if ( V_36 )
goto exit;
}
}
if ( V_34 && V_34 -> V_47 ) {
V_36 = V_34 -> V_47 ( V_32 , V_15 , V_27 ) ;
if ( V_36 ) {
F_8 ( L_13
L_14 , F_9 ( V_15 ) , V_15 ,
V_39 , V_36 ) ;
goto exit;
}
}
if ( V_4 == V_48 )
V_15 -> V_49 = 1 ;
else if ( V_4 == V_50 )
V_15 -> V_51 = 1 ;
F_13 ( & V_52 ) ;
V_36 = F_12 ( V_27 , L_15 , ( unsigned long long ) ++ V_53 ) ;
if ( V_36 ) {
F_14 ( & V_52 ) ;
goto exit;
}
#if F_15 ( F_7 )
F_16 (ue_sk, &uevent_sock_list, list) {
struct V_9 * V_37 = V_38 -> V_54 ;
struct V_11 * V_12 ;
T_1 V_55 ;
if ( ! F_17 ( V_37 , 1 ) )
continue;
V_55 = strlen ( V_28 ) + strlen ( V_29 ) + 2 ;
V_12 = F_18 ( V_55 + V_27 -> V_56 , V_44 ) ;
if ( V_12 ) {
char * V_57 ;
V_57 = F_19 ( V_12 , V_55 ) ;
sprintf ( V_57 , L_16 , V_28 , V_29 ) ;
for ( V_35 = 0 ; V_35 < V_27 -> V_58 ; V_35 ++ ) {
V_55 = strlen ( V_27 -> V_59 [ V_35 ] ) + 1 ;
V_57 = F_19 ( V_12 , V_55 ) ;
strcpy ( V_57 , V_27 -> V_59 [ V_35 ] ) ;
}
F_20 ( V_12 ) . V_60 = 1 ;
V_36 = F_21 ( V_37 , V_12 ,
0 , 1 , V_44 ,
F_3 ,
V_15 ) ;
if ( V_36 == - V_61 || V_36 == - V_62 )
V_36 = 0 ;
} else
V_36 = - V_45 ;
}
#endif
F_14 ( & V_52 ) ;
if ( V_63 [ 0 ] && ! F_5 ( V_15 ) ) {
char * V_64 [ 3 ] ;
V_64 [ 0 ] = V_63 ;
V_64 [ 1 ] = ( char * ) V_30 ;
V_64 [ 2 ] = NULL ;
V_36 = F_12 ( V_27 , L_17 ) ;
if ( V_36 )
goto exit;
V_36 = F_12 ( V_27 ,
L_18 ) ;
if ( V_36 )
goto exit;
V_36 = F_22 ( V_64 [ 0 ] , V_64 ,
V_27 -> V_59 , V_65 ) ;
}
exit:
F_23 ( V_29 ) ;
F_23 ( V_27 ) ;
return V_36 ;
}
int F_24 ( struct V_14 * V_15 , enum V_3 V_4 )
{
return F_6 ( V_15 , V_4 , NULL ) ;
}
int F_12 ( struct V_26 * V_27 , const char * V_66 , ... )
{
T_2 args ;
int V_55 ;
if ( V_27 -> V_58 >= F_2 ( V_27 -> V_59 ) ) {
F_25 ( 1 , V_67 L_19 ) ;
return - V_45 ;
}
va_start ( args , V_66 ) ;
V_55 = vsnprintf ( & V_27 -> V_1 [ V_27 -> V_56 ] ,
sizeof( V_27 -> V_1 ) - V_27 -> V_56 ,
V_66 , args ) ;
va_end ( args ) ;
if ( V_55 >= ( sizeof( V_27 -> V_1 ) - V_27 -> V_56 ) ) {
F_25 ( 1 , V_67 L_20 ) ;
return - V_45 ;
}
V_27 -> V_59 [ V_27 -> V_58 ++ ] = & V_27 -> V_1 [ V_27 -> V_56 ] ;
V_27 -> V_56 += V_55 + 1 ;
return 0 ;
}
static int F_26 ( struct V_68 * V_68 )
{
struct V_37 * V_38 ;
struct V_69 V_70 = {
. V_71 = 1 ,
. V_72 = V_73 ,
} ;
V_38 = F_10 ( sizeof( * V_38 ) , V_44 ) ;
if ( ! V_38 )
return - V_45 ;
V_38 -> V_54 = F_27 ( V_68 , V_74 , & V_70 ) ;
if ( ! V_38 -> V_54 ) {
F_28 ( V_67
L_21 ) ;
F_23 ( V_38 ) ;
return - V_75 ;
}
F_13 ( & V_52 ) ;
F_29 ( & V_38 -> V_76 , & V_77 ) ;
F_14 ( & V_52 ) ;
return 0 ;
}
static void F_30 ( struct V_68 * V_68 )
{
struct V_37 * V_38 ;
F_13 ( & V_52 ) ;
F_16 (ue_sk, &uevent_sock_list, list) {
if ( F_31 ( V_38 -> V_54 ) == V_68 )
goto V_78;
}
F_14 ( & V_52 ) ;
return;
V_78:
F_32 ( & V_38 -> V_76 ) ;
F_14 ( & V_52 ) ;
F_33 ( V_38 -> V_54 ) ;
F_23 ( V_38 ) ;
}
static int T_3 F_34 ( void )
{
return F_35 ( & V_79 ) ;
}
