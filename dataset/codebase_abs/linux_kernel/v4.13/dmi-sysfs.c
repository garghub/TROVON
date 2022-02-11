static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static struct V_3 * F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , struct V_3 , V_2 ) ;
}
static struct V_4 * F_5 ( struct V_5 * V_6 )
{
return F_4 ( V_6 , struct V_4 , V_6 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_5 * V_7 , char * V_8 )
{
struct V_3 * V_9 = F_3 ( V_2 ) ;
struct V_4 * V_6 = F_5 ( V_7 ) ;
if ( ! F_7 ( V_10 ) )
return - V_11 ;
return V_6 -> V_12 ( V_9 , V_8 ) ;
}
static void F_8 ( const struct V_13 * V_14 ,
void * V_15 )
{
struct V_16 * V_17 = V_15 ;
struct V_3 * V_9 = V_17 -> V_9 ;
if ( V_14 -> type != V_9 -> V_14 . type )
return;
if ( V_17 -> V_18 != 0 ) {
V_17 -> V_18 -- ;
return;
}
V_17 -> V_18 -- ;
V_17 -> V_19 = V_17 -> V_20 ( V_9 , V_14 , V_17 -> V_21 ) ;
}
static T_1 F_9 ( struct V_3 * V_9 ,
T_2 V_20 , void * V_21 )
{
struct V_16 V_17 = {
. V_9 = V_9 ,
. V_20 = V_20 ,
. V_21 = V_21 ,
. V_18 = V_9 -> V_22 ,
. V_19 = - V_23 ,
} ;
int V_19 ;
V_19 = F_10 ( F_8 , & V_17 ) ;
if ( V_19 )
return - V_24 ;
return V_17 . V_19 ;
}
static T_3 F_11 ( const struct V_13 * V_14 )
{
const char * V_25 = ( const char * ) V_14 ;
V_25 += V_14 -> V_26 ;
while ( V_25 [ 0 ] || V_25 [ 1 ] )
V_25 ++ ;
return 2 + V_25 - ( const char * ) V_14 ;
}
static T_1 F_12 ( struct V_3 * V_9 ,
const struct V_13 * V_14 ,
void * V_15 )
{
struct V_27 * V_17 = V_15 ;
struct V_28 * V_6 ;
V_6 = F_4 ( V_17 -> V_6 ,
struct V_28 , V_6 ) ;
return V_6 -> V_12 ( V_9 , V_14 , V_17 -> V_8 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
char * V_8 )
{
struct V_27 V_17 = {
. V_6 = V_6 ,
. V_8 = V_8 ,
} ;
return F_9 ( F_3 ( V_2 -> V_29 ) ,
F_12 , & V_17 ) ;
}
static T_4 F_14 ( const struct V_30 * V_31 ,
T_5 V_32 )
{
T_4 V_19 ;
F_15 ( & V_33 ) ;
F_16 ( ( T_4 ) V_32 , V_31 -> V_34 . V_35 ) ;
V_19 = F_17 ( V_31 -> V_34 . V_36 ) ;
F_18 ( & V_33 ) ;
return V_19 ;
}
static T_4 F_19 ( const struct V_30 * V_31 ,
T_5 V_32 )
{
T_4 V_19 ;
F_15 ( & V_33 ) ;
F_16 ( ( T_4 ) V_32 , V_31 -> V_34 . V_35 ) ;
F_16 ( ( T_4 ) ( V_32 >> 8 ) , V_31 -> V_34 . V_35 + 1 ) ;
V_19 = F_17 ( V_31 -> V_34 . V_36 ) ;
F_18 ( & V_33 ) ;
return V_19 ;
}
static T_4 F_20 ( const struct V_30 * V_31 ,
T_5 V_32 )
{
T_4 V_19 ;
F_15 ( & V_33 ) ;
F_21 ( ( V_37 ) V_32 , V_31 -> V_34 . V_35 ) ;
V_19 = F_17 ( V_31 -> V_34 . V_36 ) ;
F_18 ( & V_33 ) ;
return V_19 ;
}
static T_1 F_22 ( struct V_3 * V_9 ,
const struct V_30 * V_31 ,
char * V_8 , T_5 V_38 , T_3 V_39 )
{
T_1 V_40 = 0 ;
T_6 V_41 = V_42 [ V_31 -> V_43 ] ;
while ( V_39 && V_38 < V_31 -> V_44 ) {
V_39 -- ;
* ( V_8 ++ ) = V_41 ( V_31 , V_38 ++ ) ;
V_40 ++ ;
}
return V_40 ;
}
static T_1 F_23 ( struct V_3 * V_9 ,
const struct V_30 * V_31 ,
char * V_8 , T_5 V_38 , T_3 V_39 )
{
T_4 T_7 * V_45 ;
T_1 V_40 = 0 ;
V_45 = F_24 ( V_31 -> V_46 , V_31 -> V_44 ) ;
if ( ! V_45 )
return - V_23 ;
while ( V_39 && V_38 < V_31 -> V_44 ) {
V_39 -- ;
* ( V_8 ++ ) = F_25 ( V_45 + V_38 ++ ) ;
V_40 ++ ;
}
F_26 ( V_45 ) ;
return V_40 ;
}
static T_1 F_27 ( struct V_3 * V_9 ,
const struct V_13 * V_14 ,
void * V_47 )
{
struct V_48 * V_49 = V_47 ;
struct V_30 V_31 ;
if ( sizeof( V_31 ) > F_11 ( V_14 ) )
return - V_23 ;
memcpy ( & V_31 , V_14 , sizeof( V_31 ) ) ;
switch ( V_31 . V_43 ) {
case V_50 :
case V_51 :
case V_52 :
return F_22 ( V_9 , & V_31 , V_49 -> V_8 ,
V_49 -> V_38 , V_49 -> V_39 ) ;
case V_53 :
return F_23 ( V_9 , & V_31 , V_49 -> V_8 ,
V_49 -> V_38 , V_49 -> V_39 ) ;
case V_54 :
F_28 ( L_1 ) ;
return - V_23 ;
default:
F_28 ( L_2 ,
V_31 . V_43 ) ;
return - V_23 ;
}
}
static T_1 F_29 ( struct V_55 * V_56 , struct V_1 * V_2 ,
struct V_57 * V_58 ,
char * V_8 , T_5 V_38 , T_3 V_39 )
{
struct V_3 * V_9 = F_3 ( V_2 -> V_29 ) ;
struct V_48 V_49 = {
. V_8 = V_8 ,
. V_38 = V_38 ,
. V_39 = V_39 ,
} ;
return F_9 ( V_9 , F_27 , & V_49 ) ;
}
static int V_30 ( struct V_3 * V_9 )
{
int V_19 ;
V_9 -> V_59 = F_30 ( sizeof( * V_9 -> V_59 ) , V_60 ) ;
if ( ! V_9 -> V_59 )
return - V_61 ;
V_19 = F_31 ( V_9 -> V_59 ,
& V_62 ,
& V_9 -> V_2 ,
L_3 ) ;
if ( V_19 )
goto V_63;
V_19 = F_32 ( V_9 -> V_59 , & V_64 ) ;
if ( V_19 )
goto V_65;
return 0 ;
V_65:
F_33 ( V_9 -> V_59 ) ;
V_63:
F_2 ( V_9 -> V_59 ) ;
return V_19 ;
}
static T_1 F_34 ( struct V_3 * V_9 , char * V_8 )
{
return sprintf ( V_8 , L_4 , V_9 -> V_14 . V_26 ) ;
}
static T_1 F_35 ( struct V_3 * V_9 , char * V_8 )
{
return sprintf ( V_8 , L_4 , V_9 -> V_14 . V_66 ) ;
}
static T_1 F_36 ( struct V_3 * V_9 , char * V_8 )
{
return sprintf ( V_8 , L_4 , V_9 -> V_14 . type ) ;
}
static T_1 F_37 ( struct V_3 * V_9 ,
char * V_8 )
{
return sprintf ( V_8 , L_4 , V_9 -> V_22 ) ;
}
static T_1 F_38 ( struct V_3 * V_9 ,
char * V_8 )
{
return sprintf ( V_8 , L_4 , V_9 -> V_67 ) ;
}
static T_1 F_39 ( struct V_3 * V_9 ,
const struct V_13 * V_14 ,
void * V_47 )
{
struct V_48 * V_49 = V_47 ;
T_3 V_68 ;
V_68 = F_11 ( V_14 ) ;
return F_40 ( V_49 -> V_8 , V_49 -> V_39 ,
& V_49 -> V_38 , V_14 , V_68 ) ;
}
static T_1 F_41 ( struct V_55 * V_56 ,
struct V_1 * V_2 ,
struct V_57 * V_58 ,
char * V_8 , T_5 V_38 , T_3 V_39 )
{
struct V_3 * V_9 = F_3 ( V_2 ) ;
struct V_48 V_49 = {
. V_8 = V_8 ,
. V_38 = V_38 ,
. V_39 = V_39 ,
} ;
return F_9 ( V_9 , F_39 , & V_49 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_9 = F_3 ( V_2 ) ;
F_43 ( & V_69 ) ;
F_44 ( & V_9 -> V_70 ) ;
F_45 ( & V_69 ) ;
F_2 ( V_9 ) ;
}
static void T_8 F_46 ( const struct V_13 * V_14 ,
void * V_71 )
{
struct V_3 * V_9 ;
int * V_19 = V_71 ;
if ( * V_19 )
return;
V_9 = F_30 ( sizeof( * V_9 ) , V_60 ) ;
if ( ! V_9 ) {
* V_19 = - V_61 ;
return;
}
memcpy ( & V_9 -> V_14 , V_14 , sizeof( * V_14 ) ) ;
V_9 -> V_22 = V_72 [ V_14 -> type ] ++ ;
V_9 -> V_67 = V_73 ++ ;
V_9 -> V_2 . V_74 = V_75 ;
* V_19 = F_31 ( & V_9 -> V_2 , & V_76 , NULL ,
L_5 , V_14 -> type , V_9 -> V_22 ) ;
if ( * V_19 ) {
F_2 ( V_9 ) ;
return;
}
F_43 ( & V_69 ) ;
F_47 ( & V_9 -> V_70 , & V_77 ) ;
F_45 ( & V_69 ) ;
switch ( V_14 -> type ) {
case V_78 :
* V_19 = V_30 ( V_9 ) ;
break;
default:
break;
}
if ( * V_19 )
goto V_79;
* V_19 = F_32 ( & V_9 -> V_2 , & V_80 ) ;
if ( * V_19 )
goto V_79;
return;
V_79:
F_48 ( V_9 -> V_59 ) ;
F_48 ( & V_9 -> V_2 ) ;
return;
}
static void F_49 ( void )
{
struct V_3 * V_9 , * V_81 ;
F_50 (entry, next, &entry_list, list) {
F_48 ( V_9 -> V_59 ) ;
F_48 ( & V_9 -> V_2 ) ;
}
}
static int T_8 F_51 ( void )
{
int error ;
int V_82 ;
if ( ! V_83 ) {
F_52 ( L_6 ) ;
error = - V_84 ;
goto V_85;
}
V_75 = F_53 ( L_7 , NULL , V_83 ) ;
if ( ! V_75 ) {
error = - V_61 ;
goto V_85;
}
V_82 = 0 ;
error = F_10 ( F_46 , & V_82 ) ;
if ( error )
goto V_85;
if ( V_82 ) {
error = V_82 ;
goto V_85;
}
F_54 ( L_8 ) ;
return 0 ;
V_85:
F_49 () ;
F_55 ( V_75 ) ;
return error ;
}
static void T_9 F_56 ( void )
{
F_54 ( L_9 ) ;
F_49 () ;
F_55 ( V_75 ) ;
}
