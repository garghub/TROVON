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
F_9 ( V_13 , ( unsigned int ) V_14 ) ;
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
L_16 ,
V_10 ) ;
return - V_15 ;
}
if ( F_8 ( & V_8 -> V_23 ) == V_26 )
return V_11 ;
F_7 ( V_9 , L_17 ,
F_8 ( & V_8 -> V_23 ) == V_24 ?
L_13 : L_14 , V_26 == V_24 ?
L_13 : L_14 ) ;
F_9 ( & V_8 -> V_23 , ( unsigned int ) V_26 ) ;
return V_11 ;
}
static T_3 F_17 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 )
{
struct V_8 * V_8 = F_4 ( V_7 ) ;
return sprintf ( V_10 , L_12 , V_8 -> V_28 -> V_19 ) ;
}
static void F_18 ( struct V_1 * V_9 )
{
struct V_8 * V_8 = F_5 ( V_9 ) ;
F_19 ( V_8 ) ;
}
static T_3 F_20 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 )
{
struct V_8 * V_8 = F_4 ( V_7 ) ;
int V_29 ;
switch ( F_8 ( & V_8 -> V_30 ) ) {
case V_31 :
V_29 = sprintf ( V_10 , L_12 , V_32 ) ;
break;
case V_33 :
V_29 = sprintf ( V_10 , L_12 , V_34 ) ;
break;
default:
V_29 = sprintf ( V_10 , L_12 , V_35 ) ;
break;
}
return V_29 ;
}
static T_3 F_21 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 , T_1 V_11 )
{
struct V_1 * V_9 = F_1 ( V_7 ) ;
struct V_8 * V_8 = F_5 ( V_9 ) ;
char * V_36 ;
int V_37 = - 1 ;
if ( V_10 [ V_11 - 1 ] == '\n' )
V_10 [ V_11 - 1 ] = '\0' ;
if ( strncmp ( V_10 , V_35 , strlen ( V_35 ) ) == 0 )
V_37 = V_38 ;
if ( strncmp ( V_10 , V_32 ,
strlen ( V_32 ) ) == 0 )
V_37 = V_31 ;
if ( strncmp ( V_10 , V_34 ,
strlen ( V_34 ) ) == 0 )
V_37 = V_33 ;
if ( V_37 < 0 ) {
F_7 ( V_9 ,
L_18 ,
V_10 ) ;
return - V_15 ;
}
if ( F_8 ( & V_8 -> V_30 ) == V_37 )
return V_11 ;
switch ( F_8 ( & V_8 -> V_30 ) ) {
case V_31 :
V_36 = V_32 ;
break;
case V_33 :
V_36 = V_34 ;
break;
default:
V_36 = V_35 ;
break;
}
F_7 ( V_9 , L_19 ,
V_36 , V_10 ) ;
F_19 ( V_8 ) ;
F_9 ( & V_8 -> V_30 , ( unsigned int ) V_37 ) ;
return V_11 ;
}
static T_3 F_22 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 )
{
struct V_8 * V_8 = F_4 ( V_7 ) ;
int V_39 , V_40 ;
int V_41 = F_8 ( & V_8 -> V_41 ) ;
F_23 ( V_41 , & V_39 , & V_40 ) ;
return sprintf ( V_10 , L_20 ,
( V_39 > 2048 ? V_39 / 1024 : V_39 ) ,
( V_39 > 2048 ? L_21 : L_22 ) ,
( V_40 > 2048 ? V_40 / 1024 : V_40 ) ,
( V_40 > 2048 ? L_21 : L_22 ) ) ;
}
static T_3 F_24 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 , T_1 V_11 )
{
struct V_1 * V_9 = F_1 ( V_7 ) ;
if ( V_10 [ V_11 - 1 ] == '\n' )
V_10 [ V_11 - 1 ] = '\0' ;
return F_25 ( V_9 , V_10 , V_11 ) ;
}
int F_26 ( struct V_1 * V_5 )
{
struct V_2 * V_42 = & V_5 -> V_5 . V_7 ;
struct V_8 * V_8 = F_5 ( V_5 ) ;
struct V_43 * * V_44 ;
int V_45 ;
V_8 -> V_46 = F_27 ( V_47 ,
V_42 ) ;
if ( ! V_8 -> V_46 ) {
F_28 ( V_5 , L_23 , V_5 -> V_19 ,
V_47 ) ;
goto V_48;
}
for ( V_44 = V_49 ; * V_44 ; ++ V_44 ) {
V_45 = F_29 ( V_8 -> V_46 ,
& ( ( * V_44 ) -> V_13 ) ) ;
if ( V_45 ) {
F_28 ( V_5 , L_24 ,
V_5 -> V_19 , V_47 ,
( ( * V_44 ) -> V_13 ) . V_19 ) ;
goto V_50;
}
}
return 0 ;
V_50:
for ( V_44 = V_49 ; * V_44 ; ++ V_44 )
F_30 ( V_8 -> V_46 , & ( ( * V_44 ) -> V_13 ) ) ;
F_31 ( V_8 -> V_46 ) ;
V_8 -> V_46 = NULL ;
V_48:
return - V_51 ;
}
void F_32 ( struct V_1 * V_5 )
{
struct V_8 * V_8 = F_5 ( V_5 ) ;
struct V_43 * * V_44 ;
for ( V_44 = V_49 ; * V_44 ; ++ V_44 )
F_30 ( V_8 -> V_46 , & ( ( * V_44 ) -> V_13 ) ) ;
F_31 ( V_8 -> V_46 ) ;
V_8 -> V_46 = NULL ;
}
static T_3 F_33 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 )
{
struct V_1 * V_9 = F_1 ( V_7 ) ;
struct V_52 * V_52 = F_34 ( V_9 ) ;
T_3 V_53 ;
if ( ! V_52 )
return 0 ;
V_53 = sprintf ( V_10 , L_12 , V_52 -> V_54 == V_55 ?
L_25 : V_52 -> V_56 -> V_19 ) ;
F_35 ( V_52 ) ;
return V_53 ;
}
static T_3 F_36 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 , T_1 V_11 )
{
struct V_1 * V_9 = F_1 ( V_7 ) ;
struct V_52 * V_52 = F_34 ( V_9 ) ;
int V_57 = - 1 ;
int V_18 = V_11 ;
if ( ! V_52 )
return V_11 ;
if ( V_10 [ V_11 - 1 ] == '\n' )
V_10 [ V_11 - 1 ] = '\0' ;
if ( strlen ( V_10 ) >= V_58 ) {
F_37 ( L_26 ,
V_10 ) ;
F_35 ( V_52 ) ;
return - V_15 ;
}
if ( strncmp ( V_10 , L_25 , 4 ) == 0 )
V_57 = V_55 ;
else
V_57 = V_59 ;
if ( V_52 -> V_54 == V_57 )
goto V_48;
if ( ( V_52 -> V_56 ) &&
( strncmp ( V_52 -> V_56 -> V_19 , V_10 , V_58 ) == 0 ) )
goto V_48;
if ( ! F_38 () ) {
V_18 = - V_60 ;
goto V_48;
}
if ( V_57 == V_55 ) {
F_39 ( V_52 ) ;
goto V_61;
}
if ( V_52 -> V_54 != V_55 )
F_39 ( V_52 ) ;
V_18 = F_40 ( V_52 , V_10 ) ;
V_61:
F_41 () ;
V_48:
F_35 ( V_52 ) ;
return V_18 ;
}
static T_3 F_42 ( struct V_2 * V_7 , struct V_16 * V_13 ,
char * V_10 )
{
struct V_1 * V_9 = F_1 ( V_7 ) ;
struct V_52 * V_52 = F_34 ( V_9 ) ;
T_3 V_53 ;
if ( ! V_52 )
return 0 ;
switch ( V_52 -> V_54 ) {
case V_62 :
V_53 = sprintf ( V_10 , L_27 ) ;
break;
case V_63 :
V_53 = sprintf ( V_10 , L_28 ) ;
break;
case V_64 :
V_53 = sprintf ( V_10 , L_29 ) ;
break;
case V_65 :
V_53 = sprintf ( V_10 , L_30 ) ;
break;
case V_55 :
default:
V_53 = sprintf ( V_10 , L_31 ) ;
break;
}
F_35 ( V_52 ) ;
return V_53 ;
}
int F_43 ( struct V_2 * * V_66 , struct V_1 * V_5 )
{
struct V_2 * V_67 = & V_5 -> V_5 . V_7 ;
struct V_43 * * V_44 ;
int V_45 ;
* V_66 = F_27 ( V_68 ,
V_67 ) ;
if ( ! * V_66 ) {
F_28 ( V_5 , L_23 , V_5 -> V_19 ,
V_68 ) ;
goto V_48;
}
for ( V_44 = V_69 ; * V_44 ; ++ V_44 ) {
V_45 = F_29 ( * V_66 , & ( ( * V_44 ) -> V_13 ) ) ;
if ( V_45 ) {
F_28 ( V_5 , L_24 ,
V_5 -> V_19 , V_68 ,
( ( * V_44 ) -> V_13 ) . V_19 ) ;
goto V_50;
}
}
return 0 ;
V_50:
for ( V_44 = V_69 ; * V_44 ; ++ V_44 )
F_30 ( * V_66 , & ( ( * V_44 ) -> V_13 ) ) ;
V_48:
return - V_51 ;
}
void F_44 ( struct V_2 * * V_66 )
{
F_31 ( * V_66 ) ;
* V_66 = NULL ;
}
int F_45 ( struct V_8 * V_8 , enum V_70 type ,
enum V_71 V_72 , const char * V_73 )
{
int V_18 = - 1 ;
struct V_52 * V_74 = NULL ;
struct V_2 * V_75 ;
char * V_76 [ 4 ] = { NULL , NULL , NULL , NULL } ;
V_74 = F_46 ( V_8 ) ;
if ( ! V_74 )
goto V_48;
V_75 = & V_74 -> V_56 -> V_5 . V_7 ;
V_76 [ 0 ] = F_47 ( strlen ( V_77 ) +
strlen ( V_78 [ type ] ) + 1 ,
V_79 ) ;
if ( ! V_76 [ 0 ] )
goto V_48;
sprintf ( V_76 [ 0 ] , L_32 , V_77 , V_78 [ type ] ) ;
V_76 [ 1 ] = F_47 ( strlen ( V_80 ) +
strlen ( V_81 [ V_72 ] ) + 1 ,
V_79 ) ;
if ( ! V_76 [ 1 ] )
goto V_48;
sprintf ( V_76 [ 1 ] , L_32 , V_80 , V_81 [ V_72 ] ) ;
if ( V_72 != V_82 ) {
V_76 [ 2 ] = F_47 ( strlen ( V_83 ) +
strlen ( V_73 ) + 1 , V_79 ) ;
if ( ! V_76 [ 2 ] )
goto V_48;
sprintf ( V_76 [ 2 ] , L_32 , V_83 , V_73 ) ;
}
V_18 = F_48 ( V_75 , V_84 , V_76 ) ;
V_48:
F_49 ( V_76 [ 0 ] ) ;
F_49 ( V_76 [ 1 ] ) ;
F_49 ( V_76 [ 2 ] ) ;
if ( V_74 )
F_35 ( V_74 ) ;
if ( V_18 )
F_50 ( V_85 , V_8 ,
L_33 ,
V_78 [ type ] , V_81 [ V_72 ] ,
( V_72 == V_82 ? L_34 : V_73 ) , V_18 ) ;
return V_18 ;
}
