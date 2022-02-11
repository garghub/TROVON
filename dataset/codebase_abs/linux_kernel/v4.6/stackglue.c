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
const char * V_55 ,
int V_56 ,
struct V_57 * V_58 ,
void (* F_29)( int V_59 ,
void * V_60 ) ,
void * V_60 ,
struct V_31 * * V_32 )
{
int V_8 = 0 ;
struct V_31 * V_61 ;
F_12 ( V_55 == NULL ) ;
F_12 ( V_32 == NULL ) ;
F_12 ( F_29 == NULL ) ;
if ( V_56 > V_62 ) {
V_8 = - V_19 ;
goto V_11;
}
if ( memcmp ( & V_58 -> V_63 , & V_23 ,
sizeof( struct V_28 ) ) ) {
V_8 = - V_19 ;
goto V_11;
}
V_61 = F_30 ( sizeof( struct V_31 ) ,
V_64 ) ;
if ( ! V_61 ) {
V_8 = - V_65 ;
goto V_11;
}
F_31 ( V_61 -> V_66 , V_55 , V_62 + 1 ) ;
V_61 -> V_67 = V_56 ;
if ( V_54 )
F_31 ( V_61 -> V_68 , V_53 ,
V_69 + 1 ) ;
V_61 -> V_70 = V_54 ;
V_61 -> V_71 = F_29 ;
V_61 -> V_72 = V_60 ;
V_61 -> V_73 = V_58 ;
V_61 -> V_74 = V_58 -> V_63 ;
V_8 = F_8 ( V_6 ) ;
if ( V_8 )
goto V_75;
V_8 = V_12 -> V_39 -> V_76 ( V_61 ) ;
if ( V_8 ) {
F_11 () ;
goto V_75;
}
* V_32 = V_61 ;
V_75:
if ( V_8 )
F_32 ( V_61 ) ;
V_11:
return V_8 ;
}
int F_33 ( const char * V_55 ,
int V_56 ,
struct V_57 * V_58 ,
void (* F_29)( int V_59 ,
void * V_60 ) ,
void * V_60 ,
struct V_31 * * V_32 )
{
char * V_6 = NULL ;
if ( V_9 [ 0 ] )
V_6 = V_9 ;
return F_28 ( V_6 , NULL , 0 , V_55 , V_56 ,
V_58 , F_29 , V_60 ,
V_32 ) ;
}
int F_34 ( struct V_31 * V_32 ,
int V_77 )
{
int V_78 ;
F_12 ( V_32 == NULL ) ;
V_78 = V_12 -> V_39 -> V_79 ( V_32 ) ;
if ( ! V_78 ) {
F_32 ( V_32 ) ;
if ( ! V_77 )
F_11 () ;
}
return V_78 ;
}
static void F_35 ( const char * V_55 )
{
int V_78 ;
char * V_80 [ 5 ] , * V_81 [ 3 ] ;
V_80 [ 0 ] = V_82 ;
V_80 [ 1 ] = L_9 ;
V_80 [ 2 ] = L_10 ;
V_80 [ 3 ] = ( char * ) V_55 ;
V_80 [ 4 ] = NULL ;
V_81 [ 0 ] = L_11 ;
V_81 [ 1 ] = L_12 ;
V_81 [ 2 ] = NULL ;
V_78 = F_36 ( V_80 [ 0 ] , V_80 , V_81 , V_83 ) ;
if ( V_78 < 0 ) {
F_9 ( V_18
L_13
L_14 ,
V_78 , V_80 [ 0 ] , V_80 [ 1 ] , V_80 [ 2 ] , V_80 [ 3 ] ) ;
}
}
void F_37 ( const char * V_55 , int V_56 )
{
F_12 ( V_55 == NULL ) ;
F_12 ( V_55 [ V_56 ] != '\0' ) ;
F_35 ( V_55 ) ;
F_11 () ;
}
int F_38 ( struct V_31 * V_32 ,
unsigned int * V_84 )
{
return V_12 -> V_39 -> V_85 ( V_32 , V_84 ) ;
}
static T_3 F_39 ( struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_90 )
{
T_3 V_78 = 0 ;
F_5 ( & V_4 ) ;
if ( V_23 . V_30 )
V_78 = snprintf ( V_90 , V_91 , L_15 ,
V_23 . V_30 ,
V_23 . V_92 ) ;
F_7 ( & V_4 ) ;
return V_78 ;
}
static T_3 F_40 ( struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_90 )
{
T_3 V_78 = 0 , V_93 = 0 , V_94 = V_91 ;
struct V_1 * V_3 ;
F_5 ( & V_4 ) ;
F_3 (p, &ocfs2_stack_list, sp_list) {
V_78 = snprintf ( V_90 , V_94 , L_16 ,
V_3 -> V_5 ) ;
if ( V_78 < 0 ) {
V_93 = V_78 ;
break;
}
if ( V_78 == V_94 ) {
V_93 = - V_95 ;
break;
}
V_93 += V_78 ;
V_94 -= V_78 ;
}
F_7 ( & V_4 ) ;
return V_93 ;
}
static T_3 F_41 ( struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_90 )
{
T_3 V_78 = 0 ;
F_5 ( & V_4 ) ;
if ( V_12 ) {
V_78 = snprintf ( V_90 , V_91 , L_16 ,
V_12 -> V_5 ) ;
if ( V_78 == V_91 )
V_78 = - V_95 ;
}
F_7 ( & V_4 ) ;
return V_78 ;
}
static T_3 F_42 ( struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_90 )
{
T_3 V_78 ;
F_5 ( & V_4 ) ;
V_78 = snprintf ( V_90 , V_91 , L_16 , V_9 ) ;
F_7 ( & V_4 ) ;
return V_78 ;
}
static T_3 F_43 ( struct V_86 * V_87 ,
struct V_88 * V_89 ,
const char * V_90 , T_4 V_96 )
{
T_4 V_97 = V_96 ;
T_3 V_78 ;
if ( V_97 == 0 )
return V_97 ;
if ( V_90 [ V_97 - 1 ] == '\n' )
V_97 -- ;
if ( ( V_97 != V_17 ) ||
( F_44 ( V_90 , V_97 ) != V_97 ) )
return - V_19 ;
F_5 ( & V_4 ) ;
if ( V_12 ) {
if ( ! strncmp ( V_90 , V_9 , V_97 ) )
V_78 = V_96 ;
else
V_78 = - V_10 ;
} else {
memcpy ( V_9 , V_90 , V_97 ) ;
V_78 = V_96 ;
}
F_7 ( & V_4 ) ;
return V_78 ;
}
static T_3 F_45 ( struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_90 )
{
return snprintf ( V_90 , V_91 , L_17 ) ;
}
static void F_46 ( void )
{
F_47 ( V_98 ) ;
}
static int F_48 ( void )
{
int V_78 ;
V_98 = F_49 ( L_18 , NULL , V_99 ) ;
if ( ! V_98 )
return - V_65 ;
V_78 = F_50 ( & V_98 -> V_87 , & V_100 ) ;
if ( V_78 )
goto error;
return 0 ;
error:
F_47 ( V_98 ) ;
return V_78 ;
}
static int T_5 F_51 ( void )
{
strcpy ( V_9 , V_16 ) ;
V_101 = F_52 ( V_102 ) ;
if ( ! V_101 ) {
F_9 ( V_18
L_19 ) ;
return - V_65 ;
}
return F_48 () ;
}
static void T_6 F_53 ( void )
{
memset ( & V_23 , 0 ,
sizeof( struct V_28 ) ) ;
V_23 . V_30 = 0 ;
V_23 . V_92 = 0 ;
F_46 () ;
if ( V_101 )
F_54 ( V_101 ) ;
}
