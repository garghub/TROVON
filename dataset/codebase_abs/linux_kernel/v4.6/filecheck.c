static const char *
F_1 ( int V_1 )
{
if ( ! V_1 )
return V_2 [ V_1 ] ;
F_2 ( V_1 < V_3 ||
V_1 > V_4 ) ;
return V_2 [ V_1 - V_3 + 1 ] ;
}
static int F_3 ( T_1 * V_5 )
{
F_4 () ;
return 0 ;
}
static void
F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_5 ;
if ( ! F_6 ( & V_7 -> V_9 ) )
F_7 ( & V_7 -> V_9 , F_3 ,
V_10 ) ;
F_8 ( & V_7 -> V_11 -> V_12 ) ;
while ( ! F_9 ( & V_7 -> V_11 -> V_13 ) ) {
V_5 = F_10 ( & V_7 -> V_11 -> V_13 ,
struct V_8 , V_14 ) ;
F_11 ( & V_5 -> V_14 ) ;
F_2 ( ! V_5 -> V_15 ) ;
F_12 ( V_5 ) ;
}
F_13 ( & V_7 -> V_11 -> V_12 ) ;
F_14 ( V_7 -> V_16 ) ;
F_14 ( V_7 -> V_17 ) ;
F_12 ( V_7 -> V_11 ) ;
F_12 ( V_7 ) ;
}
static void
F_15 ( struct V_6 * V_7 )
{
F_8 ( & V_18 ) ;
F_16 ( & V_7 -> V_19 , & V_20 ) ;
F_13 ( & V_18 ) ;
}
static int F_17 ( const char * V_21 )
{
struct V_6 * V_5 ;
F_8 ( & V_18 ) ;
F_18 (p, &ocfs2_filecheck_sysfs_list, fs_list) {
if ( ! strcmp ( V_5 -> V_22 -> V_23 , V_21 ) ) {
F_11 ( & V_5 -> V_19 ) ;
F_13 ( & V_18 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
}
F_13 ( & V_18 ) ;
return 1 ;
}
static void
F_19 ( struct V_6 * V_7 )
{
if ( F_6 ( & V_7 -> V_9 ) )
F_20 ( & V_7 -> V_9 ) ;
}
static struct V_6 *
F_21 ( const char * V_21 )
{
struct V_6 * V_5 = NULL ;
F_8 ( & V_18 ) ;
F_18 (p, &ocfs2_filecheck_sysfs_list, fs_list) {
if ( ! strcmp ( V_5 -> V_22 -> V_23 , V_21 ) ) {
F_22 ( & V_5 -> V_9 ) ;
F_13 ( & V_18 ) ;
return V_5 ;
}
}
F_13 ( & V_18 ) ;
return NULL ;
}
int F_23 ( struct V_24 * V_25 )
{
int V_26 = 0 ;
struct V_27 * V_28 = NULL ;
struct V_27 * V_29 = NULL ;
struct V_30 * V_31 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_32 * * V_33 = NULL ;
struct V_34 V_35 ;
if ( ! V_36 )
return - V_37 ;
V_33 = F_24 ( sizeof( struct V_32 * ) * 4 , V_38 ) ;
if ( ! V_33 ) {
V_26 = - V_37 ;
goto error;
} else {
V_33 [ 0 ] = & V_39 . V_40 ;
V_33 [ 1 ] = & V_41 . V_40 ;
V_33 [ 2 ] = & V_42 . V_40 ;
V_33 [ 3 ] = NULL ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_33 = V_33 ;
}
V_31 = F_24 ( sizeof( struct V_30 ) , V_38 ) ;
if ( ! V_31 ) {
V_26 = - V_37 ;
goto error;
} else {
F_25 ( & V_31 -> V_13 ) ;
F_26 ( & V_31 -> V_12 ) ;
V_31 -> V_43 = V_44 ;
V_31 -> V_45 = 0 ;
V_31 -> V_46 = 0 ;
}
if ( strlen ( V_25 -> V_23 ) <= 0 ) {
F_27 ( V_47 ,
L_1 ) ;
V_26 = - V_48 ;
goto error;
}
V_28 = F_28 ( V_25 -> V_23 , NULL , & V_36 -> V_49 ) ;
if ( ! V_28 ) {
V_26 = - V_37 ;
goto error;
}
V_29 = F_28 ( L_2 , NULL ,
& V_28 -> V_49 ) ;
if ( ! V_29 ) {
V_26 = - V_37 ;
goto error;
}
V_26 = F_29 ( & V_29 -> V_49 , & V_35 ) ;
if ( V_26 )
goto error;
V_7 = F_24 ( sizeof( struct V_6 ) , V_38 ) ;
if ( ! V_7 ) {
V_26 = - V_37 ;
goto error;
} else {
F_30 ( & V_7 -> V_9 , 1 ) ;
V_7 -> V_22 = V_25 ;
V_7 -> V_17 = V_28 ;
V_7 -> V_16 = V_29 ;
V_7 -> V_11 = V_31 ;
F_15 ( V_7 ) ;
}
F_12 ( V_33 ) ;
return 0 ;
error:
F_12 ( V_33 ) ;
F_12 ( V_7 ) ;
F_12 ( V_31 ) ;
F_14 ( V_29 ) ;
F_14 ( V_28 ) ;
return V_26 ;
}
int F_31 ( struct V_24 * V_25 )
{
return F_17 ( V_25 -> V_23 ) ;
}
static int
F_32 ( struct V_6 * V_50 ,
unsigned int V_51 )
{
int V_26 ;
if ( ( V_51 < V_44 ) || ( V_51 > V_52 ) )
return - V_53 ;
F_8 ( & V_50 -> V_11 -> V_12 ) ;
if ( V_51 < ( V_50 -> V_11 -> V_45 - V_50 -> V_11 -> V_46 ) ) {
F_27 ( V_47 ,
L_3
L_4 ,
V_51 , V_50 -> V_11 -> V_45 - V_50 -> V_11 -> V_46 ) ;
V_26 = - V_54 ;
} else {
if ( V_51 < V_50 -> V_11 -> V_45 )
F_2 ( ! F_33 ( V_50 ,
V_50 -> V_11 -> V_45 - V_51 ) ) ;
V_50 -> V_11 -> V_43 = V_51 ;
V_26 = 0 ;
}
F_13 ( & V_50 -> V_11 -> V_12 ) ;
return V_26 ;
}
static int
F_34 ( const char * V_55 , T_2 V_56 ,
unsigned long * V_57 )
{
char V_58 [ V_59 ] ;
memcpy ( V_58 , V_55 , V_56 ) ;
V_58 [ V_56 ] = '\0' ;
if ( F_35 ( V_58 , 0 , V_57 ) )
return 1 ;
return 0 ;
}
static int
F_36 ( const char * V_60 , unsigned int * type )
{
if ( ! strncmp ( V_60 , L_5 , 4 ) )
* type = V_61 ;
else if ( ! strncmp ( V_60 , L_6 , 6 ) )
* type = V_62 ;
else if ( ! strncmp ( V_60 , L_7 , 4 ) )
* type = V_63 ;
else
return 1 ;
return 0 ;
}
static int
F_37 ( const char * V_60 , const char * V_55 , T_2 V_56 ,
struct V_64 * args )
{
unsigned long V_57 = 0 ;
unsigned int type ;
if ( ( V_56 < 1 ) || ( V_56 >= V_59 ) )
return 1 ;
if ( F_36 ( V_60 , & type ) )
return 1 ;
if ( F_34 ( V_55 , V_56 , & V_57 ) )
return 1 ;
if ( V_57 <= 0 )
return 1 ;
args -> V_65 = type ;
if ( type == V_63 )
args -> V_66 = ( unsigned int ) V_57 ;
else
args -> V_67 = V_57 ;
return 0 ;
}
static T_3 F_38 ( struct V_68 * V_49 ,
struct V_69 * V_40 ,
char * V_55 )
{
T_3 V_26 = 0 , V_70 = 0 , V_71 = V_72 ;
unsigned int type ;
struct V_8 * V_5 ;
struct V_6 * V_50 ;
if ( F_36 ( V_40 -> V_40 . V_60 , & type ) )
return - V_53 ;
V_50 = F_21 ( V_49 -> V_73 -> V_60 ) ;
if ( ! V_50 ) {
F_27 ( V_47 ,
L_8 ,
V_49 -> V_60 ) ;
return - V_48 ;
}
if ( type == V_63 ) {
F_8 ( & V_50 -> V_11 -> V_12 ) ;
V_70 = snprintf ( V_55 , V_71 , L_9 , V_50 -> V_11 -> V_43 ) ;
F_13 ( & V_50 -> V_11 -> V_12 ) ;
goto exit;
}
V_26 = snprintf ( V_55 , V_71 , L_10 ) ;
V_70 += V_26 ;
V_71 -= V_26 ;
F_8 ( & V_50 -> V_11 -> V_12 ) ;
F_18 (p, &ent->fs_fcheck->fc_head, fe_list) {
if ( V_5 -> V_74 != type )
continue;
V_26 = snprintf ( V_55 + V_70 , V_71 , L_11 ,
V_5 -> V_75 , V_5 -> V_15 ,
F_1 ( V_5 -> V_76 ) ) ;
if ( V_26 < 0 ) {
V_70 = V_26 ;
break;
}
if ( V_26 == V_71 ) {
V_70 = - V_77 ;
break;
}
V_70 += V_26 ;
V_71 -= V_26 ;
}
F_13 ( & V_50 -> V_11 -> V_12 ) ;
exit:
F_19 ( V_50 ) ;
return V_70 ;
}
static int
F_39 ( struct V_6 * V_50 )
{
struct V_8 * V_5 ;
F_18 (p, &ent->fs_fcheck->fc_head, fe_list) {
if ( V_5 -> V_15 ) {
F_11 ( & V_5 -> V_14 ) ;
F_12 ( V_5 ) ;
V_50 -> V_11 -> V_45 -- ;
V_50 -> V_11 -> V_46 -- ;
return 1 ;
}
}
return 0 ;
}
static int
F_33 ( struct V_6 * V_50 ,
unsigned int V_56 )
{
unsigned int V_78 = 0 ;
unsigned int V_26 = 0 ;
while ( V_78 ++ < V_56 ) {
if ( F_39 ( V_50 ) )
V_26 ++ ;
else
break;
}
return ( V_26 == V_56 ? 1 : 0 ) ;
}
static void
F_40 ( struct V_6 * V_50 ,
struct V_8 * V_7 )
{
V_7 -> V_15 = 1 ;
F_8 ( & V_50 -> V_11 -> V_12 ) ;
V_50 -> V_11 -> V_46 ++ ;
F_13 ( & V_50 -> V_11 -> V_12 ) ;
}
static unsigned int
F_41 ( struct V_24 * V_25 ,
unsigned long V_79 , unsigned int V_80 )
{
unsigned int V_26 = V_81 ;
struct V_82 * V_82 = NULL ;
int V_83 ;
V_82 = F_42 ( F_43 ( V_25 ) , V_79 , V_80 , 0 ) ;
if ( F_44 ( V_82 ) ) {
V_83 = ( int ) ( - ( long ) V_82 ) ;
if ( V_83 >= V_3 &&
V_83 < V_4 )
V_26 = V_83 ;
else
V_26 = V_84 ;
} else
F_45 ( V_82 ) ;
return V_26 ;
}
static void
F_46 ( struct V_6 * V_50 ,
struct V_8 * V_7 )
{
if ( V_7 -> V_74 == V_62 )
V_7 -> V_76 = F_41 ( V_50 -> V_22 ,
V_7 -> V_75 , V_85 ) ;
else if ( V_7 -> V_74 == V_61 )
V_7 -> V_76 = F_41 ( V_50 -> V_22 ,
V_7 -> V_75 , V_86 ) ;
else
V_7 -> V_76 = V_87 ;
F_40 ( V_50 , V_7 ) ;
}
static T_3 F_47 ( struct V_68 * V_49 ,
struct V_69 * V_40 ,
const char * V_55 , T_2 V_56 )
{
struct V_64 args ;
struct V_8 * V_7 ;
struct V_6 * V_50 ;
T_3 V_26 = 0 ;
if ( V_56 == 0 )
return V_56 ;
if ( F_37 ( V_40 -> V_40 . V_60 , V_55 , V_56 , & args ) ) {
F_27 ( V_47 , L_12 ) ;
return - V_53 ;
}
V_50 = F_21 ( V_49 -> V_73 -> V_60 ) ;
if ( ! V_50 ) {
F_27 ( V_47 ,
L_8 ,
V_49 -> V_73 -> V_60 ) ;
return - V_48 ;
}
if ( args . V_65 == V_63 ) {
V_26 = F_32 ( V_50 , args . V_66 ) ;
goto exit;
}
V_7 = F_24 ( sizeof( struct V_8 ) , V_38 ) ;
if ( ! V_7 ) {
V_26 = - V_37 ;
goto exit;
}
F_8 ( & V_50 -> V_11 -> V_12 ) ;
if ( ( V_50 -> V_11 -> V_45 >= V_50 -> V_11 -> V_43 ) &&
( V_50 -> V_11 -> V_46 == 0 ) ) {
F_27 ( V_47 ,
L_13
L_14 ,
V_50 -> V_11 -> V_43 ) ;
V_26 = - V_54 ;
F_12 ( V_7 ) ;
} else {
if ( ( V_50 -> V_11 -> V_45 >= V_50 -> V_11 -> V_43 ) &&
( V_50 -> V_11 -> V_46 > 0 ) ) {
F_2 ( ! F_39 ( V_50 ) ) ;
}
V_7 -> V_75 = args . V_67 ;
V_7 -> V_74 = args . V_65 ;
V_7 -> V_15 = 0 ;
V_7 -> V_76 = V_88 ;
F_16 ( & V_7 -> V_14 , & V_50 -> V_11 -> V_13 ) ;
V_50 -> V_11 -> V_45 ++ ;
}
F_13 ( & V_50 -> V_11 -> V_12 ) ;
if ( ! V_26 )
F_46 ( V_50 , V_7 ) ;
exit:
F_19 ( V_50 ) ;
return ( ! V_26 ? V_56 : V_26 ) ;
}
