static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 , struct V_4 , V_7 ) ;
return F_3 ( V_5 ) ;
}
static struct V_8 * F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return F_5 ( V_9 ) ;
}
static int F_6 ( char * V_10 , T_1 V_11 ,
struct V_1 * V_9 ,
const char * V_12 , T_2 * V_13 )
{
int V_14 = - 1 ;
if ( V_10 [ V_11 - 1 ] == '\n' )
V_10 [ V_11 - 1 ] = '\0' ;
if ( ( strncmp ( V_10 , L_1 , 2 ) == 0 ) ||
( strncmp ( V_10 , L_2 , 7 ) == 0 ) ||
( strncmp ( V_10 , L_3 , 8 ) == 0 ) )
V_14 = 1 ;
if ( ( strncmp ( V_10 , L_4 , 2 ) == 0 ) ||
( strncmp ( V_10 , L_5 , 8 ) == 0 ) ||
( strncmp ( V_10 , L_6 , 9 ) == 0 ) )
V_14 = 0 ;
if ( V_14 < 0 ) {
F_7 ( V_9 ,
L_7 ,
V_12 , V_10 ) ;
return - V_15 ;
}
if ( F_8 ( V_13 ) == V_14 )
return V_11 ;
F_7 ( V_9 , L_8 , V_12 ,
F_8 ( V_13 ) == 1 ? L_3 : L_6 ,
V_14 == 1 ? L_3 : L_6 ) ;
F_9 ( V_13 , ( unsigned ) V_14 ) ;
return V_11 ;
}
static inline T_3 F_10 ( char * V_10 , T_1 V_11 ,
void (* F_11)( struct V_1 * ) ,
struct V_16 * V_13 ,
T_2 * V_17 , struct V_1 * V_9 )
{
int V_18 ;
V_18 = F_6 ( V_10 , V_11 , V_9 , V_13 -> V_19 , V_17 ) ;
if ( F_11 && V_18 )
F_11 ( V_9 ) ;
return V_18 ;
}
static int F_12 ( const char * V_10 , T_1 V_11 ,
struct V_1 * V_9 , const char * V_12 ,
unsigned int V_20 , unsigned int V_21 , T_2 * V_13 )
{
unsigned long V_22 ;
int V_18 ;
V_18 = F_13 ( V_10 , 10 , & V_22 ) ;
if ( V_18 ) {
F_7 ( V_9 ,
L_7 ,
V_12 , V_10 ) ;
return - V_15 ;
}
if ( V_22 < V_20 ) {
F_7 ( V_9 , L_9 ,
V_12 , V_22 , V_20 ) ;
return - V_15 ;
}
if ( V_22 > V_21 ) {
F_7 ( V_9 , L_10 ,
V_12 , V_22 , V_21 ) ;
return - V_15 ;
}
if ( F_8 ( V_13 ) == V_22 )
return V_11 ;
F_7 ( V_9 , L_11 ,
V_12 , F_8 ( V_13 ) , V_22 ) ;
F_9 ( V_13 , V_22 ) ;
return V_11 ;
}
static inline T_3 F_14 ( const char * V_10 , T_1 V_11 ,
int V_20 , int V_21 ,
void (* F_11)( struct V_1 * ) ,
const struct V_16 * V_13 ,
T_2 * V_17 , struct V_1 * V_9 )
{
int V_18 ;
V_18 = F_12 ( V_10 , V_11 , V_9 , V_13 -> V_19 ,
V_20 , V_21 , V_17 ) ;
if ( F_11 && V_18 )
F_11 ( V_9 ) ;
return V_18 ;
}
static T_3 F_15 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 )
{
struct V_8 * V_8 = F_4 ( V_7 ) ;
int V_23 = F_8 ( & V_8 -> V_23 ) ;
return sprintf ( V_10 , L_12 ,
V_23 == V_24 ?
L_13 : L_14 ) ;
}
static T_3 F_16 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 , T_1 V_11 )
{
struct V_1 * V_9 = F_1 ( V_7 ) ;
struct V_8 * V_8 = F_5 ( V_9 ) ;
unsigned long V_25 ;
int V_18 , V_26 = - 1 ;
V_18 = F_13 ( V_10 , 10 , & V_25 ) ;
if ( ( ( V_11 == 2 ) && ( ! V_18 ) && ( V_25 == V_24 ) ) ||
( strncmp ( V_10 , L_13 , 6 ) == 0 ) ||
( strncmp ( V_10 , L_15 , 3 ) == 0 ) )
V_26 = V_24 ;
if ( ( ( V_11 == 2 ) && ( ! V_18 ) && ( V_25 == V_27 ) ) ||
( strncmp ( V_10 , L_14 , 6 ) == 0 ) )
V_26 = V_27 ;
if ( V_26 < 0 ) {
if ( V_10 [ V_11 - 1 ] == '\n' )
V_10 [ V_11 - 1 ] = '\0' ;
F_7 ( V_9 ,
L_16
L_12 , V_10 ) ;
return - V_15 ;
}
if ( F_8 ( & V_8 -> V_23 ) == V_26 )
return V_11 ;
F_7 ( V_9 , L_17 ,
F_8 ( & V_8 -> V_23 ) == V_24 ?
L_13 : L_14 , V_26 == V_24 ?
L_13 : L_14 ) ;
F_9 ( & V_8 -> V_23 , ( unsigned ) V_26 ) ;
return V_11 ;
}
static void F_17 ( struct V_1 * V_9 )
{
struct V_8 * V_8 = F_5 ( V_9 ) ;
F_18 ( V_8 ) ;
}
static T_3 F_19 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 )
{
struct V_8 * V_8 = F_4 ( V_7 ) ;
int V_28 ;
switch ( F_8 ( & V_8 -> V_29 ) ) {
case V_30 :
V_28 = sprintf ( V_10 , L_12 , V_31 ) ;
break;
case V_32 :
V_28 = sprintf ( V_10 , L_12 , V_33 ) ;
break;
default:
V_28 = sprintf ( V_10 , L_12 , V_34 ) ;
break;
}
return V_28 ;
}
static T_3 F_20 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 , T_1 V_11 )
{
struct V_1 * V_9 = F_1 ( V_7 ) ;
struct V_8 * V_8 = F_5 ( V_9 ) ;
char * V_35 ;
int V_36 = - 1 ;
if ( V_10 [ V_11 - 1 ] == '\n' )
V_10 [ V_11 - 1 ] = '\0' ;
if ( strncmp ( V_10 , V_34 , strlen ( V_34 ) ) == 0 )
V_36 = V_37 ;
if ( strncmp ( V_10 , V_31 ,
strlen ( V_31 ) ) == 0 )
V_36 = V_30 ;
if ( strncmp ( V_10 , V_33 ,
strlen ( V_33 ) ) == 0 )
V_36 = V_32 ;
if ( V_36 < 0 ) {
F_7 ( V_9 ,
L_18
L_12 , V_10 ) ;
return - V_15 ;
}
if ( F_8 ( & V_8 -> V_29 ) == V_36 )
return V_11 ;
switch ( F_8 ( & V_8 -> V_29 ) ) {
case V_30 :
V_35 = V_31 ;
break;
case V_32 :
V_35 = V_33 ;
break;
default:
V_35 = V_34 ;
break;
}
F_7 ( V_9 , L_19 ,
V_35 , V_10 ) ;
F_18 ( V_8 ) ;
F_9 ( & V_8 -> V_29 , ( unsigned ) V_36 ) ;
return V_11 ;
}
static T_3 F_21 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 )
{
struct V_8 * V_8 = F_4 ( V_7 ) ;
int V_38 , V_39 ;
int V_40 = F_8 ( & V_8 -> V_40 ) ;
F_22 ( V_40 , & V_38 , & V_39 ) ;
return sprintf ( V_10 , L_20 ,
( V_38 > 2048 ? V_38 / 1024 : V_38 ) ,
( V_38 > 2048 ? L_21 : L_22 ) ,
( V_39 > 2048 ? V_39 / 1024 : V_39 ) ,
( V_39 > 2048 ? L_21 : L_22 ) ) ;
}
static T_3 F_23 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 , T_1 V_11 )
{
struct V_1 * V_9 = F_1 ( V_7 ) ;
if ( V_10 [ V_11 - 1 ] == '\n' )
V_10 [ V_11 - 1 ] = '\0' ;
return F_24 ( V_9 , V_10 , V_11 ) ;
}
int F_25 ( struct V_1 * V_5 )
{
struct V_2 * V_41 = & V_5 -> V_5 . V_7 ;
struct V_8 * V_8 = F_5 ( V_5 ) ;
struct V_42 * * V_43 ;
int V_44 ;
V_8 -> V_45 = F_26 ( V_46 ,
V_41 ) ;
if ( ! V_8 -> V_45 ) {
F_27 ( V_5 , L_23 , V_5 -> V_19 ,
V_46 ) ;
goto V_47;
}
for ( V_43 = V_48 ; * V_43 ; ++ V_43 ) {
V_44 = F_28 ( V_8 -> V_45 ,
& ( ( * V_43 ) -> V_13 ) ) ;
if ( V_44 ) {
F_27 ( V_5 , L_24 ,
V_5 -> V_19 , V_46 ,
( ( * V_43 ) -> V_13 ) . V_19 ) ;
goto V_49;
}
}
return 0 ;
V_49:
for ( V_43 = V_48 ; * V_43 ; ++ V_43 )
F_29 ( V_8 -> V_45 , & ( ( * V_43 ) -> V_13 ) ) ;
F_30 ( V_8 -> V_45 ) ;
V_8 -> V_45 = NULL ;
V_47:
return - V_50 ;
}
void F_31 ( struct V_1 * V_5 )
{
struct V_8 * V_8 = F_5 ( V_5 ) ;
struct V_42 * * V_43 ;
for ( V_43 = V_48 ; * V_43 ; ++ V_43 )
F_29 ( V_8 -> V_45 , & ( ( * V_43 ) -> V_13 ) ) ;
F_30 ( V_8 -> V_45 ) ;
V_8 -> V_45 = NULL ;
}
static T_3 F_32 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 )
{
struct V_1 * V_9 = F_1 ( V_7 ) ;
struct V_51 * V_51 = F_33 ( V_9 ) ;
T_3 V_52 ;
if ( ! V_51 )
return 0 ;
V_52 = sprintf ( V_10 , L_12 , V_51 -> V_53 == V_54 ?
L_25 : V_51 -> V_55 -> V_19 ) ;
F_34 ( V_51 ) ;
return V_52 ;
}
static T_3 F_35 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 , T_1 V_11 )
{
struct V_1 * V_9 = F_1 ( V_7 ) ;
struct V_51 * V_51 = F_33 ( V_9 ) ;
int V_56 = - 1 ;
int V_18 = V_11 ;
if ( ! V_51 )
return V_11 ;
if ( V_10 [ V_11 - 1 ] == '\n' )
V_10 [ V_11 - 1 ] = '\0' ;
if ( strlen ( V_10 ) >= V_57 ) {
F_36 ( L_26
L_27 , V_10 ) ;
F_34 ( V_51 ) ;
return - V_15 ;
}
if ( strncmp ( V_10 , L_25 , 4 ) == 0 )
V_56 = V_54 ;
else
V_56 = V_58 ;
if ( V_51 -> V_53 == V_56 )
goto V_47;
if ( ( V_51 -> V_55 ) &&
( strncmp ( V_51 -> V_55 -> V_19 , V_10 , V_57 ) == 0 ) )
goto V_47;
if ( ! F_37 () ) {
V_18 = - V_59 ;
goto V_47;
}
if ( V_56 == V_54 ) {
F_38 ( V_51 ) ;
goto V_60;
}
if ( V_51 -> V_53 != V_54 )
F_38 ( V_51 ) ;
V_18 = F_39 ( V_51 , V_10 ) ;
V_60:
F_40 () ;
V_47:
F_34 ( V_51 ) ;
return V_18 ;
}
static T_3 F_41 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 )
{
struct V_1 * V_9 = F_1 ( V_7 ) ;
struct V_51 * V_51 = F_33 ( V_9 ) ;
T_3 V_52 ;
if ( ! V_51 )
return 0 ;
switch ( V_51 -> V_53 ) {
case V_61 :
V_52 = sprintf ( V_10 , L_28 ) ;
break;
case V_62 :
V_52 = sprintf ( V_10 , L_29 ) ;
break;
case V_63 :
V_52 = sprintf ( V_10 , L_30 ) ;
break;
case V_64 :
V_52 = sprintf ( V_10 , L_31 ) ;
break;
case V_54 :
default:
V_52 = sprintf ( V_10 , L_32 ) ;
break;
}
F_34 ( V_51 ) ;
return V_52 ;
}
int F_42 ( struct V_2 * * V_65 , struct V_1 * V_5 )
{
struct V_2 * V_66 = & V_5 -> V_5 . V_7 ;
struct V_42 * * V_43 ;
int V_44 ;
* V_65 = F_26 ( V_67 ,
V_66 ) ;
if ( ! * V_65 ) {
F_27 ( V_5 , L_23 , V_5 -> V_19 ,
V_67 ) ;
goto V_47;
}
for ( V_43 = V_68 ; * V_43 ; ++ V_43 ) {
V_44 = F_28 ( * V_65 , & ( ( * V_43 ) -> V_13 ) ) ;
if ( V_44 ) {
F_27 ( V_5 , L_24 ,
V_5 -> V_19 , V_67 ,
( ( * V_43 ) -> V_13 ) . V_19 ) ;
goto V_49;
}
}
return 0 ;
V_49:
for ( V_43 = V_68 ; * V_43 ; ++ V_43 )
F_29 ( * V_65 , & ( ( * V_43 ) -> V_13 ) ) ;
V_47:
return - V_50 ;
}
void F_43 ( struct V_2 * * V_65 )
{
F_30 ( * V_65 ) ;
* V_65 = NULL ;
}
int F_44 ( struct V_8 * V_8 , enum V_69 type ,
enum V_70 V_71 , const char * V_72 )
{
int V_18 = - 1 ;
struct V_51 * V_73 = NULL ;
struct V_2 * V_74 ;
char * V_75 [ 4 ] = { NULL , NULL , NULL , NULL } ;
V_73 = F_45 ( V_8 ) ;
if ( ! V_73 )
goto V_47;
V_74 = & V_73 -> V_55 -> V_5 . V_7 ;
V_75 [ 0 ] = F_46 ( strlen ( V_76 ) +
strlen ( V_77 [ type ] ) + 1 ,
V_78 ) ;
if ( ! V_75 [ 0 ] )
goto V_47;
sprintf ( V_75 [ 0 ] , L_33 , V_76 , V_77 [ type ] ) ;
V_75 [ 1 ] = F_46 ( strlen ( V_79 ) +
strlen ( V_80 [ V_71 ] ) + 1 ,
V_78 ) ;
if ( ! V_75 [ 1 ] )
goto V_47;
sprintf ( V_75 [ 1 ] , L_33 , V_79 , V_80 [ V_71 ] ) ;
if ( V_71 != V_81 ) {
V_75 [ 2 ] = F_46 ( strlen ( V_82 ) +
strlen ( V_72 ) + 1 , V_78 ) ;
if ( ! V_75 [ 2 ] )
goto V_47;
sprintf ( V_75 [ 2 ] , L_33 , V_82 , V_72 ) ;
}
V_18 = F_47 ( V_74 , V_83 , V_75 ) ;
V_47:
F_48 ( V_75 [ 0 ] ) ;
F_48 ( V_75 [ 1 ] ) ;
F_48 ( V_75 [ 2 ] ) ;
if ( V_73 )
F_34 ( V_73 ) ;
if ( V_18 )
F_49 ( V_84 , V_8 , L_34
L_35 ,
V_77 [ type ] , V_80 [ V_71 ] ,
( V_71 == V_81 ? L_36 : V_72 ) , V_18 ) ;
return V_18 ;
}
