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
T_2 V_35 ;
int V_36 = 0 ;
int V_37 = 0 ;
#ifdef F_7
struct V_38 * V_39 ;
#endif
F_8 ( L_1 ,
F_9 ( V_15 ) , V_15 , V_40 ) ;
V_31 = V_15 ;
while ( ! V_31 -> V_32 && V_31 -> V_41 )
V_31 = V_31 -> V_41 ;
if ( ! V_31 -> V_32 ) {
F_8 ( L_2
L_3 , F_9 ( V_15 ) , V_15 ,
V_40 ) ;
return - V_6 ;
}
V_32 = V_31 -> V_32 ;
V_34 = V_32 -> V_34 ;
if ( V_15 -> V_42 ) {
F_8 ( L_4
L_5 ,
F_9 ( V_15 ) , V_15 , V_40 ) ;
return 0 ;
}
if ( V_34 && V_34 -> V_43 )
if ( ! V_34 -> V_43 ( V_32 , V_15 ) ) {
F_8 ( L_6
L_5 ,
F_9 ( V_15 ) , V_15 , V_40 ) ;
return 0 ;
}
if ( V_34 && V_34 -> V_44 )
V_30 = V_34 -> V_44 ( V_32 , V_15 ) ;
else
V_30 = F_9 ( & V_32 -> V_15 ) ;
if ( ! V_30 ) {
F_8 ( L_7
L_8 , F_9 ( V_15 ) , V_15 ,
V_40 ) ;
return 0 ;
}
V_27 = F_10 ( sizeof( struct V_26 ) , V_45 ) ;
if ( ! V_27 )
return - V_46 ;
V_29 = F_11 ( V_15 , V_45 ) ;
if ( ! V_29 ) {
V_37 = - V_47 ;
goto exit;
}
V_37 = F_12 ( V_27 , L_9 , V_28 ) ;
if ( V_37 )
goto exit;
V_37 = F_12 ( V_27 , L_10 , V_29 ) ;
if ( V_37 )
goto exit;
V_37 = F_12 ( V_27 , L_11 , V_30 ) ;
if ( V_37 )
goto exit;
if ( V_25 ) {
for ( V_36 = 0 ; V_25 [ V_36 ] ; V_36 ++ ) {
V_37 = F_12 ( V_27 , L_12 , V_25 [ V_36 ] ) ;
if ( V_37 )
goto exit;
}
}
if ( V_34 && V_34 -> V_48 ) {
V_37 = V_34 -> V_48 ( V_32 , V_15 , V_27 ) ;
if ( V_37 ) {
F_8 ( L_13
L_14 , F_9 ( V_15 ) , V_15 ,
V_40 , V_37 ) ;
goto exit;
}
}
if ( V_4 == V_49 )
V_15 -> V_50 = 1 ;
else if ( V_4 == V_51 )
V_15 -> V_52 = 1 ;
F_13 ( & V_53 ) ;
V_35 = ++ V_54 ;
F_14 ( & V_53 ) ;
V_37 = F_12 ( V_27 , L_15 , ( unsigned long long ) V_35 ) ;
if ( V_37 )
goto exit;
#if F_15 ( F_7 )
F_16 ( & V_55 ) ;
F_17 (ue_sk, &uevent_sock_list, list) {
struct V_9 * V_38 = V_39 -> V_56 ;
struct V_11 * V_12 ;
T_1 V_57 ;
V_57 = strlen ( V_28 ) + strlen ( V_29 ) + 2 ;
V_12 = F_18 ( V_57 + V_27 -> V_58 , V_45 ) ;
if ( V_12 ) {
char * V_59 ;
V_59 = F_19 ( V_12 , V_57 ) ;
sprintf ( V_59 , L_16 , V_28 , V_29 ) ;
for ( V_36 = 0 ; V_36 < V_27 -> V_60 ; V_36 ++ ) {
V_57 = strlen ( V_27 -> V_61 [ V_36 ] ) + 1 ;
V_59 = F_19 ( V_12 , V_57 ) ;
strcpy ( V_59 , V_27 -> V_61 [ V_36 ] ) ;
}
F_20 ( V_12 ) . V_62 = 1 ;
V_37 = F_21 ( V_38 , V_12 ,
0 , 1 , V_45 ,
F_3 ,
V_15 ) ;
if ( V_37 == - V_63 || V_37 == - V_64 )
V_37 = 0 ;
} else
V_37 = - V_46 ;
}
F_22 ( & V_55 ) ;
#endif
if ( V_65 [ 0 ] && ! F_5 ( V_15 ) ) {
char * V_66 [ 3 ] ;
V_66 [ 0 ] = V_65 ;
V_66 [ 1 ] = ( char * ) V_30 ;
V_66 [ 2 ] = NULL ;
V_37 = F_12 ( V_27 , L_17 ) ;
if ( V_37 )
goto exit;
V_37 = F_12 ( V_27 ,
L_18 ) ;
if ( V_37 )
goto exit;
V_37 = F_23 ( V_66 [ 0 ] , V_66 ,
V_27 -> V_61 , V_67 ) ;
}
exit:
F_24 ( V_29 ) ;
F_24 ( V_27 ) ;
return V_37 ;
}
int F_25 ( struct V_14 * V_15 , enum V_3 V_4 )
{
return F_6 ( V_15 , V_4 , NULL ) ;
}
int F_12 ( struct V_26 * V_27 , const char * V_68 , ... )
{
T_3 args ;
int V_57 ;
if ( V_27 -> V_60 >= F_2 ( V_27 -> V_61 ) ) {
F_26 ( 1 , V_69 L_19 ) ;
return - V_46 ;
}
va_start ( args , V_68 ) ;
V_57 = vsnprintf ( & V_27 -> V_1 [ V_27 -> V_58 ] ,
sizeof( V_27 -> V_1 ) - V_27 -> V_58 ,
V_68 , args ) ;
va_end ( args ) ;
if ( V_57 >= ( sizeof( V_27 -> V_1 ) - V_27 -> V_58 ) ) {
F_26 ( 1 , V_69 L_20 ) ;
return - V_46 ;
}
V_27 -> V_61 [ V_27 -> V_60 ++ ] = & V_27 -> V_1 [ V_27 -> V_58 ] ;
V_27 -> V_58 += V_57 + 1 ;
return 0 ;
}
static int F_27 ( struct V_70 * V_70 )
{
struct V_38 * V_39 ;
V_39 = F_10 ( sizeof( * V_39 ) , V_45 ) ;
if ( ! V_39 )
return - V_46 ;
V_39 -> V_56 = F_28 ( V_70 , V_71 ,
1 , NULL , NULL , V_72 ) ;
if ( ! V_39 -> V_56 ) {
F_29 ( V_69
L_21 ) ;
F_24 ( V_39 ) ;
return - V_73 ;
}
F_16 ( & V_55 ) ;
F_30 ( & V_39 -> V_74 , & V_75 ) ;
F_22 ( & V_55 ) ;
return 0 ;
}
static void F_31 ( struct V_70 * V_70 )
{
struct V_38 * V_39 ;
F_16 ( & V_55 ) ;
F_17 (ue_sk, &uevent_sock_list, list) {
if ( F_32 ( V_39 -> V_56 ) == V_70 )
goto V_76;
}
F_22 ( & V_55 ) ;
return;
V_76:
F_33 ( & V_39 -> V_74 ) ;
F_22 ( & V_55 ) ;
F_34 ( V_39 -> V_56 ) ;
F_24 ( V_39 ) ;
}
static int T_4 F_35 ( void )
{
F_36 ( V_71 , V_77 ) ;
return F_37 ( & V_78 ) ;
}
