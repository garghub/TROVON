static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 ( & V_4 ) ;
F_3 (p, &ocfs2_stack_list, sp_list) {
if ( ! strcmp ( V_3 -> V_5 , V_2 ) )
return V_3 ;
}
return NULL ;
}
static int F_4 ( const char * V_6 ,
const char * V_7 )
{
int V_8 ;
struct V_1 * V_3 ;
F_5 ( & V_4 ) ;
if ( strcmp ( V_6 , V_9 ) ) {
V_8 = - V_10 ;
goto V_11;
}
if ( V_12 ) {
if ( ! strcmp ( V_12 -> V_5 , V_7 ) )
V_8 = 0 ;
else
V_8 = - V_10 ;
goto V_11;
}
V_3 = F_1 ( V_7 ) ;
if ( ! V_3 || ! F_6 ( V_3 -> V_13 ) ) {
V_8 = - V_14 ;
goto V_11;
}
V_12 = V_3 ;
V_8 = 0 ;
V_11:
if ( ! V_8 )
V_12 -> V_15 ++ ;
F_7 ( & V_4 ) ;
return V_8 ;
}
static int F_8 ( const char * V_6 )
{
int V_8 ;
char * V_7 = V_16 ;
if ( ! V_6 || ! * V_6 )
V_6 = V_16 ;
if ( strlen ( V_6 ) != V_17 ) {
F_9 ( V_18
L_1 ,
V_6 ) ;
return - V_19 ;
}
if ( strcmp ( V_6 , V_16 ) )
V_7 = V_20 ;
V_8 = F_4 ( V_6 , V_7 ) ;
if ( V_8 == - V_14 ) {
F_10 ( L_2 , V_7 ) ;
V_8 = F_4 ( V_6 , V_7 ) ;
}
if ( V_8 == - V_14 ) {
F_9 ( V_18
L_3 ,
V_7 ) ;
} else if ( V_8 == - V_10 ) {
F_9 ( V_18
L_4 ) ;
}
return V_8 ;
}
static void F_11 ( void )
{
F_5 ( & V_4 ) ;
F_12 ( V_12 == NULL ) ;
F_12 ( V_12 -> V_15 == 0 ) ;
V_12 -> V_15 -- ;
if ( ! V_12 -> V_15 ) {
F_13 ( V_12 -> V_13 ) ;
V_12 = NULL ;
}
F_7 ( & V_4 ) ;
}
int F_14 ( struct V_1 * V_21 )
{
int V_8 ;
F_5 ( & V_4 ) ;
if ( ! F_1 ( V_21 -> V_5 ) ) {
V_21 -> V_15 = 0 ;
V_21 -> V_22 = V_23 ;
F_15 ( & V_21 -> V_24 , & V_25 ) ;
F_9 ( V_26 L_5 ,
V_21 -> V_5 ) ;
V_8 = 0 ;
} else {
F_9 ( V_18 L_6 ,
V_21 -> V_5 ) ;
V_8 = - V_27 ;
}
F_7 ( & V_4 ) ;
return V_8 ;
}
void F_16 ( struct V_1 * V_21 )
{
struct V_1 * V_3 ;
F_5 ( & V_4 ) ;
V_3 = F_1 ( V_21 -> V_5 ) ;
if ( V_3 ) {
F_12 ( V_3 != V_21 ) ;
F_12 ( V_21 == V_12 ) ;
F_12 ( V_21 -> V_15 != 0 ) ;
F_17 ( & V_21 -> V_24 ) ;
F_9 ( V_26 L_7 ,
V_21 -> V_5 ) ;
} else {
F_9 ( V_18 L_8 ,
V_21 -> V_5 ) ;
}
F_7 ( & V_4 ) ;
}
void F_18 ( struct V_28 * V_29 )
{
struct V_1 * V_3 ;
F_5 ( & V_4 ) ;
if ( memcmp ( V_29 , & V_23 ,
sizeof( struct V_28 ) ) ) {
F_12 ( V_23 . V_30 != 0 ) ;
V_23 = * V_29 ;
F_3 (p, &ocfs2_stack_list, sp_list) {
V_3 -> V_22 = V_23 ;
}
}
F_7 ( & V_4 ) ;
}
int F_19 ( struct V_31 * V_32 ,
int V_33 ,
struct V_34 * V_35 ,
T_1 V_36 ,
void * V_2 ,
unsigned int V_37 )
{
if ( ! V_35 -> V_38 )
V_35 -> V_38 = V_32 ;
else
F_12 ( V_35 -> V_38 != V_32 ) ;
return V_12 -> V_39 -> V_40 ( V_32 , V_33 , V_35 , V_36 ,
V_2 , V_37 ) ;
}
int F_20 ( struct V_31 * V_32 ,
struct V_34 * V_35 ,
T_1 V_36 )
{
F_12 ( V_35 -> V_38 == NULL ) ;
return V_12 -> V_39 -> V_41 ( V_32 , V_35 , V_36 ) ;
}
int F_21 ( struct V_34 * V_35 )
{
return V_12 -> V_39 -> V_42 ( V_35 ) ;
}
int F_22 ( struct V_34 * V_35 )
{
return V_12 -> V_39 -> V_43 ( V_35 ) ;
}
void * F_23 ( struct V_34 * V_35 )
{
return V_12 -> V_39 -> V_44 ( V_35 ) ;
}
void F_24 ( struct V_34 * V_35 )
{
V_12 -> V_39 -> V_45 ( V_35 ) ;
}
int F_25 ( void )
{
return V_12 && V_12 -> V_39 -> V_46 ;
}
int F_26 ( struct V_31 * V_32 , T_2 V_47 ,
struct V_48 * V_48 , int V_49 , struct V_50 * V_51 )
{
F_27 ( V_12 -> V_39 -> V_46 == NULL ) ;
if ( V_12 -> V_39 -> V_46 )
return V_12 -> V_39 -> V_46 ( V_32 , V_47 , V_48 , V_49 , V_51 ) ;
return - V_52 ;
}
int F_28 ( const char * V_6 ,
const char * V_53 ,
int V_54 ,
struct V_55 * V_56 ,
void (* F_29)( int V_57 ,
void * V_58 ) ,
void * V_58 ,
struct V_31 * * V_32 )
{
int V_8 = 0 ;
struct V_31 * V_59 ;
F_12 ( V_53 == NULL ) ;
F_12 ( V_32 == NULL ) ;
F_12 ( F_29 == NULL ) ;
if ( V_54 > V_60 ) {
V_8 = - V_19 ;
goto V_11;
}
if ( memcmp ( & V_56 -> V_61 , & V_23 ,
sizeof( struct V_28 ) ) ) {
V_8 = - V_19 ;
goto V_11;
}
V_59 = F_30 ( sizeof( struct V_31 ) ,
V_62 ) ;
if ( ! V_59 ) {
V_8 = - V_63 ;
goto V_11;
}
memcpy ( V_59 -> V_64 , V_53 , V_54 ) ;
V_59 -> V_65 = V_54 ;
V_59 -> V_66 = F_29 ;
V_59 -> V_67 = V_58 ;
V_59 -> V_68 = V_56 ;
V_59 -> V_69 = V_56 -> V_61 ;
V_8 = F_8 ( V_6 ) ;
if ( V_8 )
goto V_70;
V_8 = V_12 -> V_39 -> V_71 ( V_59 ) ;
if ( V_8 ) {
F_11 () ;
goto V_70;
}
* V_32 = V_59 ;
V_70:
if ( V_8 )
F_31 ( V_59 ) ;
V_11:
return V_8 ;
}
int F_32 ( const char * V_53 ,
int V_54 ,
struct V_55 * V_56 ,
void (* F_29)( int V_57 ,
void * V_58 ) ,
void * V_58 ,
struct V_31 * * V_32 )
{
char * V_6 = NULL ;
if ( V_9 [ 0 ] )
V_6 = V_9 ;
return F_28 ( V_6 , V_53 , V_54 , V_56 ,
F_29 , V_58 , V_32 ) ;
}
int F_33 ( struct V_31 * V_32 ,
int V_72 )
{
int V_73 ;
F_12 ( V_32 == NULL ) ;
V_73 = V_12 -> V_39 -> V_74 ( V_32 ) ;
if ( ! V_73 ) {
F_31 ( V_32 ) ;
if ( ! V_72 )
F_11 () ;
}
return V_73 ;
}
static void F_34 ( const char * V_53 )
{
int V_73 ;
char * V_75 [ 5 ] , * V_76 [ 3 ] ;
V_75 [ 0 ] = V_77 ;
V_75 [ 1 ] = L_9 ;
V_75 [ 2 ] = L_10 ;
V_75 [ 3 ] = ( char * ) V_53 ;
V_75 [ 4 ] = NULL ;
V_76 [ 0 ] = L_11 ;
V_76 [ 1 ] = L_12 ;
V_76 [ 2 ] = NULL ;
V_73 = F_35 ( V_75 [ 0 ] , V_75 , V_76 , V_78 ) ;
if ( V_73 < 0 ) {
F_9 ( V_18
L_13
L_14 ,
V_73 , V_75 [ 0 ] , V_75 [ 1 ] , V_75 [ 2 ] , V_75 [ 3 ] ) ;
}
}
void F_36 ( const char * V_53 , int V_54 )
{
F_12 ( V_53 == NULL ) ;
F_12 ( V_53 [ V_54 ] != '\0' ) ;
F_34 ( V_53 ) ;
F_11 () ;
}
int F_37 ( unsigned int * V_79 )
{
return V_12 -> V_39 -> V_80 ( V_79 ) ;
}
static T_3 F_38 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
char * V_85 )
{
T_3 V_73 = 0 ;
F_5 ( & V_4 ) ;
if ( V_23 . V_30 )
V_73 = snprintf ( V_85 , V_86 , L_15 ,
V_23 . V_30 ,
V_23 . V_87 ) ;
F_7 ( & V_4 ) ;
return V_73 ;
}
static T_3 F_39 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
char * V_85 )
{
T_3 V_73 = 0 , V_88 = 0 , V_89 = V_86 ;
struct V_1 * V_3 ;
F_5 ( & V_4 ) ;
F_3 (p, &ocfs2_stack_list, sp_list) {
V_73 = snprintf ( V_85 , V_89 , L_16 ,
V_3 -> V_5 ) ;
if ( V_73 < 0 ) {
V_88 = V_73 ;
break;
}
if ( V_73 == V_89 ) {
V_88 = - V_90 ;
break;
}
V_88 += V_73 ;
V_89 -= V_73 ;
}
F_7 ( & V_4 ) ;
return V_88 ;
}
static T_3 F_40 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
char * V_85 )
{
T_3 V_73 = 0 ;
F_5 ( & V_4 ) ;
if ( V_12 ) {
V_73 = snprintf ( V_85 , V_86 , L_16 ,
V_12 -> V_5 ) ;
if ( V_73 == V_86 )
V_73 = - V_90 ;
}
F_7 ( & V_4 ) ;
return V_73 ;
}
static T_3 F_41 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
char * V_85 )
{
T_3 V_73 ;
F_5 ( & V_4 ) ;
V_73 = snprintf ( V_85 , V_86 , L_16 , V_9 ) ;
F_7 ( & V_4 ) ;
return V_73 ;
}
static T_3 F_42 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
const char * V_85 , T_4 V_91 )
{
T_4 V_92 = V_91 ;
T_3 V_73 ;
if ( V_92 == 0 )
return V_92 ;
if ( V_85 [ V_92 - 1 ] == '\n' )
V_92 -- ;
if ( ( V_92 != V_17 ) ||
( F_43 ( V_85 , V_92 ) != V_92 ) )
return - V_19 ;
F_5 ( & V_4 ) ;
if ( V_12 ) {
if ( ! strncmp ( V_85 , V_9 , V_92 ) )
V_73 = V_91 ;
else
V_73 = - V_10 ;
} else {
memcpy ( V_9 , V_85 , V_92 ) ;
V_73 = V_91 ;
}
F_7 ( & V_4 ) ;
return V_73 ;
}
static void F_44 ( void )
{
F_45 ( V_93 ) ;
}
static int F_46 ( void )
{
int V_73 ;
V_93 = F_47 ( L_17 , NULL , V_94 ) ;
if ( ! V_93 )
return - V_63 ;
V_73 = F_48 ( & V_93 -> V_82 , & V_95 ) ;
if ( V_73 )
goto error;
return 0 ;
error:
F_45 ( V_93 ) ;
return V_73 ;
}
static int T_5 F_49 ( void )
{
strcpy ( V_9 , V_16 ) ;
V_96 = F_50 ( V_97 ) ;
if ( ! V_96 ) {
F_9 ( V_18
L_18 ) ;
return - V_63 ;
}
return F_46 () ;
}
static void T_6 F_51 ( void )
{
memset ( & V_23 , 0 ,
sizeof( struct V_28 ) ) ;
V_23 . V_30 = 0 ;
V_23 . V_87 = 0 ;
F_44 () ;
if ( V_96 )
F_52 ( V_96 ) ;
}
