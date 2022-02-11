static bool F_1 ( struct V_1 * V_2 , char * V_3 ,
T_1 V_4 )
{
return V_2 -> V_5 == V_4 &&
! strncmp ( V_2 -> V_6 -> V_7 -> V_8 , V_3 ,
sizeof( V_2 -> V_6 -> V_7 -> V_8 ) ) ;
}
static struct V_1 * F_2 ( char * V_9 )
{
struct V_1 * V_2 , * V_10 = NULL ;
F_3 ( & V_11 . V_12 ) ;
F_4 (pnetelem, &smc_pnettable.pnetlist, list) {
if ( ! strncmp ( V_2 -> V_9 , V_9 ,
sizeof( V_2 -> V_9 ) ) ) {
V_10 = V_2 ;
break;
}
}
F_5 ( & V_11 . V_12 ) ;
return V_10 ;
}
static int F_6 ( char * V_9 )
{
struct V_1 * V_2 , * V_13 ;
int V_14 = - V_15 ;
F_7 ( & V_11 . V_12 ) ;
F_8 (pnetelem, tmp_pe, &smc_pnettable.pnetlist,
list) {
if ( ! strncmp ( V_2 -> V_9 , V_9 ,
sizeof( V_2 -> V_9 ) ) ) {
F_9 ( & V_2 -> V_16 ) ;
F_10 ( V_2 -> V_17 ) ;
F_11 ( V_2 ) ;
V_14 = 0 ;
break;
}
}
F_12 ( & V_11 . V_12 ) ;
return V_14 ;
}
static int F_13 ( struct V_18 * V_17 )
{
struct V_1 * V_2 , * V_13 ;
int V_14 = - V_15 ;
F_7 ( & V_11 . V_12 ) ;
F_8 (pnetelem, tmp_pe, &smc_pnettable.pnetlist,
list) {
if ( V_2 -> V_17 == V_17 ) {
F_9 ( & V_2 -> V_16 ) ;
F_10 ( V_2 -> V_17 ) ;
F_11 ( V_2 ) ;
V_14 = 0 ;
break;
}
}
F_12 ( & V_11 . V_12 ) ;
return V_14 ;
}
int F_14 ( struct V_19 * V_7 )
{
struct V_1 * V_2 , * V_13 ;
int V_14 = - V_15 ;
F_7 ( & V_11 . V_12 ) ;
F_8 (pnetelem, tmp_pe, &smc_pnettable.pnetlist,
list) {
if ( V_2 -> V_6 == V_7 ) {
F_9 ( & V_2 -> V_16 ) ;
F_10 ( V_2 -> V_17 ) ;
F_11 ( V_2 ) ;
V_14 = 0 ;
break;
}
}
F_12 ( & V_11 . V_12 ) ;
return V_14 ;
}
static int F_15 ( struct V_1 * V_20 )
{
struct V_1 * V_2 ;
int V_14 = - V_21 ;
F_7 ( & V_11 . V_12 ) ;
F_4 (pnetelem, &smc_pnettable.pnetlist, list) {
if ( ! strncmp ( V_2 -> V_9 , V_20 -> V_9 ,
sizeof( V_20 -> V_9 ) ) ||
! strncmp ( V_2 -> V_17 -> V_8 , V_20 -> V_17 -> V_8 ,
sizeof( V_20 -> V_17 -> V_8 ) ) ||
F_1 ( V_2 ,
V_20 -> V_6 -> V_7 -> V_8 ,
V_20 -> V_5 ) ) {
F_10 ( V_2 -> V_17 ) ;
goto V_22;
}
}
F_16 ( & V_20 -> V_16 , & V_11 . V_23 ) ;
V_14 = 0 ;
V_22:
F_12 ( & V_11 . V_12 ) ;
return V_14 ;
}
static bool F_17 ( const char * V_9 , char * V_24 )
{
char * V_25 = F_18 ( V_9 ) ;
T_2 V_26 = strlen ( V_25 ) ;
char * V_27 = V_25 + V_26 ;
if ( ! V_26 )
return false ;
while ( -- V_27 >= V_25 && isspace ( * V_27 ) )
;
if ( V_27 - V_25 >= V_28 )
return false ;
while ( V_25 <= V_27 ) {
if ( ! isalnum ( * V_25 ) )
return false ;
* V_24 ++ = islower ( * V_25 ) ? toupper ( * V_25 ) : * V_25 ;
V_25 ++ ;
}
* V_24 = '\0' ;
return true ;
}
static struct V_19 * F_19 ( char * V_29 )
{
struct V_19 * V_7 ;
F_20 ( & V_30 . V_12 ) ;
F_4 (ibdev, &smc_ib_devices.list, list) {
if ( ! strncmp ( V_7 -> V_7 -> V_8 , V_29 ,
sizeof( V_7 -> V_7 -> V_8 ) ) ) {
goto V_31;
}
}
V_7 = NULL ;
V_31:
F_21 ( & V_30 . V_12 ) ;
return V_7 ;
}
static int F_22 ( struct V_32 * V_32 , struct V_1 * V_2 ,
struct V_33 * V_34 [] )
{
char * string , * V_3 = NULL ;
int V_14 = 0 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_23 ( & V_2 -> V_16 ) ;
if ( V_34 [ V_35 ] ) {
string = ( char * ) F_24 ( V_34 [ V_35 ] ) ;
if ( ! F_17 ( string , V_2 -> V_9 ) ) {
V_14 = - V_36 ;
goto error;
}
}
if ( V_34 [ V_37 ] ) {
string = ( char * ) F_24 ( V_34 [ V_37 ] ) ;
V_2 -> V_17 = F_25 ( V_32 , string ) ;
if ( ! V_2 -> V_17 )
return - V_15 ;
}
if ( V_34 [ V_38 ] ) {
V_3 = ( char * ) F_24 ( V_34 [ V_38 ] ) ;
V_3 = F_26 ( V_3 ) ;
V_2 -> V_6 = F_19 ( V_3 ) ;
if ( ! V_2 -> V_6 ) {
V_14 = - V_15 ;
goto error;
}
}
if ( V_34 [ V_39 ] ) {
V_2 -> V_5 = F_27 ( V_34 [ V_39 ] ) ;
if ( V_2 -> V_5 > V_40 ) {
V_14 = - V_36 ;
goto error;
}
}
return 0 ;
error:
if ( V_2 -> V_17 )
F_10 ( V_2 -> V_17 ) ;
return V_14 ;
}
static int F_28 ( struct V_41 * V_42 , struct V_1 * V_2 )
{
if ( F_29 ( V_42 , V_35 , V_2 -> V_9 ) ||
F_29 ( V_42 , V_37 , V_2 -> V_17 -> V_8 ) ||
F_29 ( V_42 , V_38 ,
V_2 -> V_6 -> V_7 -> V_8 ) ||
F_30 ( V_42 , V_39 , V_2 -> V_5 ) )
return - 1 ;
return 0 ;
}
static int F_31 ( struct V_41 * V_43 , struct V_44 * V_45 )
{
struct V_1 * V_2 ;
struct V_41 * V_42 ;
void * V_46 ;
int V_14 ;
V_2 = F_2 (
( char * ) F_24 ( V_45 -> V_47 [ V_35 ] ) ) ;
if ( ! V_2 )
return - V_15 ;
V_42 = F_32 ( V_48 , V_49 ) ;
if ( ! V_42 )
return - V_50 ;
V_46 = F_33 ( V_42 , V_45 -> V_51 , V_45 -> V_52 ,
& V_53 , 0 , V_54 ) ;
if ( ! V_46 ) {
V_14 = - V_55 ;
goto V_56;
}
if ( F_28 ( V_42 , V_2 ) ) {
V_14 = - V_57 ;
goto V_56;
}
F_34 ( V_42 , V_46 ) ;
return F_35 ( V_42 , V_45 ) ;
V_56:
F_36 ( V_42 ) ;
return V_14 ;
}
static int F_37 ( struct V_41 * V_43 , struct V_44 * V_45 )
{
struct V_32 * V_32 = F_38 ( V_45 ) ;
struct V_1 * V_2 ;
int V_14 ;
V_2 = F_39 ( sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 )
return - V_50 ;
V_14 = F_22 ( V_32 , V_2 , V_45 -> V_47 ) ;
if ( ! V_14 )
V_14 = F_15 ( V_2 ) ;
if ( V_14 ) {
F_11 ( V_2 ) ;
return V_14 ;
}
V_14 = F_40 ( V_2 -> V_6 , V_2 -> V_5 ) ;
if ( V_14 )
F_6 ( V_2 -> V_9 ) ;
return V_14 ;
}
static int F_41 ( struct V_41 * V_43 , struct V_44 * V_45 )
{
return F_6 (
( char * ) F_24 ( V_45 -> V_47 [ V_35 ] ) ) ;
}
static int F_42 ( struct V_58 * V_59 )
{
V_59 -> args [ 0 ] = 0 ;
return 0 ;
}
static int F_43 ( struct V_41 * V_43 ,
T_3 V_60 , T_3 V_61 , T_3 V_62 ,
struct V_1 * V_2 )
{
void * V_46 ;
V_46 = F_33 ( V_43 , V_60 , V_61 , & V_53 ,
V_62 , V_54 ) ;
if ( ! V_46 )
return - V_50 ;
if ( F_28 ( V_43 , V_2 ) < 0 ) {
F_44 ( V_43 , V_46 ) ;
return - V_55 ;
}
F_34 ( V_43 , V_46 ) ;
return 0 ;
}
static int F_45 ( struct V_41 * V_43 , struct V_58 * V_59 )
{
struct V_1 * V_2 ;
int V_63 = 0 ;
F_3 ( & V_11 . V_12 ) ;
F_4 (pnetelem, &smc_pnettable.pnetlist, list) {
if ( V_63 ++ < V_59 -> args [ 0 ] )
continue;
if ( F_43 ( V_43 , F_46 ( V_59 -> V_43 ) . V_60 ,
V_59 -> V_64 -> V_65 , V_66 ,
V_2 ) ) {
-- V_63 ;
break;
}
}
V_59 -> args [ 0 ] = V_63 ;
F_5 ( & V_11 . V_12 ) ;
return V_43 -> V_26 ;
}
static int F_47 ( struct V_41 * V_43 , struct V_44 * V_45 )
{
struct V_1 * V_2 , * V_13 ;
F_7 ( & V_11 . V_12 ) ;
F_8 (pnetelem, tmp_pe, &smc_pnettable.pnetlist,
list) {
F_9 ( & V_2 -> V_16 ) ;
F_10 ( V_2 -> V_17 ) ;
F_11 ( V_2 ) ;
}
F_12 ( & V_11 . V_12 ) ;
return 0 ;
}
static int F_48 ( struct V_67 * V_68 ,
unsigned long V_69 , void * V_70 )
{
struct V_18 * V_71 = F_49 ( V_70 ) ;
switch ( V_69 ) {
case V_72 :
case V_73 :
F_13 ( V_71 ) ;
default:
break;
}
return V_74 ;
}
int T_4 F_50 ( void )
{
int V_14 ;
V_14 = F_51 ( & V_53 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_52 ( & V_75 ) ;
if ( V_14 )
F_53 ( & V_53 ) ;
return V_14 ;
}
void F_54 ( void )
{
F_47 ( NULL , NULL ) ;
F_55 ( & V_75 ) ;
F_53 ( & V_53 ) ;
}
void F_56 ( struct V_76 * V_77 ,
struct V_19 * * V_6 , T_1 * V_4 )
{
struct V_78 * V_79 = F_57 ( V_77 ) ;
struct V_1 * V_2 ;
* V_6 = NULL ;
* V_4 = 0 ;
if ( ! V_79 )
return;
if ( ! V_79 -> V_80 )
goto V_81;
F_3 ( & V_11 . V_12 ) ;
F_4 (pnetelem, &smc_pnettable.pnetlist, list) {
if ( V_79 -> V_80 == V_2 -> V_17 ) {
if ( F_58 ( V_2 -> V_6 ,
V_2 -> V_5 ) ) {
* V_6 = V_2 -> V_6 ;
* V_4 = V_2 -> V_5 ;
}
break;
}
}
F_5 ( & V_11 . V_12 ) ;
V_81:
F_59 ( V_79 ) ;
}
