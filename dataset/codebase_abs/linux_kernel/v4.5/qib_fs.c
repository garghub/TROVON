static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
T_1 V_4 , const struct V_5 * V_6 ,
void * V_7 )
{
int error ;
struct V_1 * V_1 = F_2 ( V_2 -> V_8 ) ;
if ( ! V_1 ) {
error = - V_9 ;
goto V_10;
}
V_1 -> V_11 = F_3 () ;
V_1 -> V_12 = V_4 ;
V_1 -> V_13 = V_14 ;
V_1 -> V_15 = V_16 ;
V_1 -> V_17 = 0 ;
V_1 -> V_18 = V_19 ;
V_1 -> V_20 = V_1 -> V_18 ;
V_1 -> V_21 = V_1 -> V_18 ;
V_1 -> V_22 = V_7 ;
if ( F_4 ( V_4 ) ) {
V_1 -> V_23 = & V_24 ;
F_5 ( V_1 ) ;
F_5 ( V_2 ) ;
}
V_1 -> V_25 = V_6 ;
F_6 ( V_3 , V_1 ) ;
error = 0 ;
V_10:
return error ;
}
static int F_7 ( const char * V_26 , T_1 V_4 ,
struct V_3 * V_27 , struct V_3 * * V_3 ,
const struct V_5 * V_6 , void * V_7 )
{
int error ;
F_8 ( F_9 ( V_27 ) ) ;
* V_3 = F_10 ( V_26 , V_27 , strlen ( V_26 ) ) ;
if ( ! F_11 ( * V_3 ) )
error = F_1 ( F_9 ( V_27 ) , * V_3 ,
V_4 , V_6 , V_7 ) ;
else
error = F_12 ( * V_3 ) ;
F_13 ( F_9 ( V_27 ) ) ;
return error ;
}
static T_2 F_14 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
V_32 . V_33 = F_15 () ;
return F_16 ( V_29 , V_30 , V_31 , & V_32 ,
sizeof( V_32 ) ) ;
}
static T_2 F_17 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
return F_16 ( V_29 , V_30 , V_31 , V_34 ,
sizeof( V_34 ) - 1 ) ;
}
static T_2 F_18 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
T_6 * V_35 ;
T_4 V_36 ;
struct V_37 * V_38 = F_19 ( V_28 ) ;
V_36 = V_38 -> V_39 ( V_38 , * V_31 , NULL , & V_35 ) ;
return F_16 ( V_29 , V_30 , V_31 , V_35 , V_36 ) ;
}
static T_2 F_20 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
char * V_40 ;
T_4 V_36 ;
struct V_37 * V_38 = F_19 ( V_28 ) ;
V_36 = V_38 -> V_39 ( V_38 , * V_31 , & V_40 , NULL ) ;
return F_16 ( V_29 , V_30 , V_31 , V_40 , V_36 ) ;
}
static T_2 F_21 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
char * V_40 ;
T_4 V_36 ;
struct V_37 * V_38 = F_19 ( V_28 ) ;
V_36 = V_38 -> V_41 ( V_38 , * V_31 , 0 , & V_40 , NULL ) ;
return F_16 ( V_29 , V_30 , V_31 , V_40 , V_36 ) ;
}
static T_2 F_22 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
T_6 * V_35 ;
T_4 V_36 ;
struct V_37 * V_38 = F_19 ( V_28 ) ;
V_36 = V_38 -> V_41 ( V_38 , * V_31 , 0 , NULL , & V_35 ) ;
return F_16 ( V_29 , V_30 , V_31 , V_35 , V_36 ) ;
}
static T_2 F_23 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
T_6 * V_35 ;
T_4 V_36 ;
struct V_37 * V_38 = F_19 ( V_28 ) ;
V_36 = V_38 -> V_41 ( V_38 , * V_31 , 1 , NULL , & V_35 ) ;
return F_16 ( V_29 , V_30 , V_31 , V_35 , V_36 ) ;
}
static T_2 F_24 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
struct V_37 * V_38 = F_19 ( V_28 ) ;
char * V_42 ;
int V_43 ;
V_42 = F_25 ( V_44 , V_45 ) ;
if ( ! V_42 )
return - V_46 ;
V_43 = F_26 ( V_38 -> V_47 , V_42 , V_44 ) ;
if ( V_43 > 0 )
V_43 = F_16 ( V_29 , V_30 , V_31 , V_42 , V_43 ) ;
F_27 ( V_42 ) ;
return V_43 ;
}
static T_2 F_28 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
struct V_37 * V_38 = F_19 ( V_28 ) ;
char * V_42 ;
int V_43 ;
if ( V_38 -> V_48 < 2 )
return - V_49 ;
V_42 = F_25 ( V_44 , V_45 ) ;
if ( ! V_42 )
return - V_46 ;
V_43 = F_26 ( V_38 -> V_47 + 1 , V_42 , V_44 ) ;
if ( V_43 > 0 )
V_43 = F_16 ( V_29 , V_30 , V_31 , V_42 , V_43 ) ;
F_27 ( V_42 ) ;
return V_43 ;
}
static T_2 F_29 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
struct V_37 * V_38 ;
T_2 V_43 ;
T_5 V_50 ;
char * V_42 ;
V_50 = * V_31 ;
if ( V_50 < 0 ) {
V_43 = - V_51 ;
goto V_10;
}
if ( V_50 >= sizeof( struct V_52 ) ) {
V_43 = 0 ;
goto V_10;
}
if ( V_30 > sizeof( struct V_52 ) - V_50 )
V_30 = sizeof( struct V_52 ) - V_50 ;
V_42 = F_25 ( V_30 , V_45 ) ;
if ( ! V_42 ) {
V_43 = - V_46 ;
goto V_10;
}
V_38 = F_19 ( V_28 ) ;
if ( F_30 ( V_38 , V_50 , V_42 , V_30 ) ) {
F_31 ( V_38 , L_1 ) ;
V_43 = - V_53 ;
goto V_54;
}
if ( F_32 ( V_29 , V_42 , V_30 ) ) {
V_43 = - V_55 ;
goto V_54;
}
* V_31 = V_50 + V_30 ;
V_43 = V_30 ;
V_54:
F_27 ( V_42 ) ;
V_10:
return V_43 ;
}
static T_2 F_33 ( struct V_28 * V_28 , const char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
struct V_37 * V_38 ;
T_2 V_43 ;
T_5 V_50 ;
char * V_42 ;
V_50 = * V_31 ;
if ( V_50 != 0 ) {
V_43 = - V_51 ;
goto V_10;
}
if ( V_30 != sizeof( struct V_52 ) ) {
V_43 = - V_51 ;
goto V_10;
}
V_42 = F_25 ( V_30 , V_45 ) ;
if ( ! V_42 ) {
V_43 = - V_46 ;
goto V_10;
}
if ( F_34 ( V_42 , V_29 , V_30 ) ) {
V_43 = - V_55 ;
goto V_54;
}
V_38 = F_19 ( V_28 ) ;
if ( F_35 ( V_38 , V_50 , V_42 , V_30 ) ) {
V_43 = - V_53 ;
F_31 ( V_38 , L_2 ) ;
goto V_54;
}
* V_31 = V_50 + V_30 ;
V_43 = V_30 ;
V_54:
F_27 ( V_42 ) ;
V_10:
return V_43 ;
}
static int F_36 ( struct V_56 * V_57 , struct V_37 * V_38 )
{
struct V_3 * V_2 , * V_42 ;
char V_58 [ 10 ] ;
int V_43 , V_59 ;
snprintf ( V_58 , sizeof( V_58 ) , L_3 , V_38 -> V_58 ) ;
V_43 = F_7 ( V_58 , V_60 | V_61 | V_62 , V_57 -> V_63 , & V_2 ,
& V_64 , V_38 ) ;
if ( V_43 ) {
F_37 ( L_4 , V_58 , V_43 ) ;
goto V_10;
}
V_43 = F_7 ( L_5 , V_65 | V_61 , V_2 , & V_42 ,
& V_66 [ 0 ] , V_38 ) ;
if ( V_43 ) {
F_37 ( L_6 ,
V_58 , V_43 ) ;
goto V_10;
}
V_43 = F_7 ( L_7 , V_65 | V_61 , V_2 , & V_42 ,
& V_66 [ 1 ] , V_38 ) ;
if ( V_43 ) {
F_37 ( L_8 ,
V_58 , V_43 ) ;
goto V_10;
}
V_43 = F_7 ( L_9 , V_65 | V_61 , V_2 , & V_42 ,
& V_67 [ 0 ] , V_38 ) ;
if ( V_43 ) {
F_37 ( L_10 ,
V_58 , L_9 , V_43 ) ;
goto V_10;
}
for ( V_59 = 1 ; V_59 <= V_38 -> V_48 ; V_59 ++ ) {
char V_68 [ 24 ] ;
sprintf ( V_68 , L_11 , V_59 ) ;
V_43 = F_7 ( V_68 , V_65 | V_61 , V_2 , & V_42 ,
& V_67 [ V_59 ] , V_38 ) ;
if ( V_43 ) {
F_37 ( L_10 ,
V_58 , V_68 , V_43 ) ;
goto V_10;
}
if ( ! ( V_38 -> V_69 & V_70 ) )
continue;
sprintf ( V_68 , L_12 , V_59 ) ;
V_43 = F_7 ( V_68 , V_65 | V_61 , V_2 , & V_42 ,
& V_71 [ V_59 - 1 ] , V_38 ) ;
if ( V_43 ) {
F_37 ( L_10 ,
V_58 , V_68 , V_43 ) ;
goto V_10;
}
}
V_43 = F_7 ( L_13 , V_65 | V_72 | V_61 , V_2 , & V_42 ,
& V_73 , V_38 ) ;
if ( V_43 )
F_37 ( L_14 ,
V_58 , V_43 ) ;
V_10:
return V_43 ;
}
static int F_38 ( struct V_3 * V_27 , char * V_26 )
{
struct V_3 * V_42 ;
int V_43 ;
V_42 = F_10 ( V_26 , V_27 , strlen ( V_26 ) ) ;
if ( F_11 ( V_42 ) ) {
V_43 = F_12 ( V_42 ) ;
goto V_10;
}
F_39 ( & V_42 -> V_74 ) ;
if ( F_40 ( V_42 ) ) {
F_41 ( V_42 ) ;
F_42 ( & V_42 -> V_74 ) ;
F_43 ( F_9 ( V_27 ) , V_42 ) ;
} else {
F_42 ( & V_42 -> V_74 ) ;
}
F_44 ( V_42 ) ;
V_43 = 0 ;
V_10:
return V_43 ;
}
static int F_45 ( struct V_56 * V_57 ,
struct V_37 * V_38 )
{
struct V_3 * V_2 , * V_75 ;
char V_58 [ 10 ] ;
int V_43 , V_59 ;
V_75 = F_46 ( V_57 -> V_63 ) ;
F_8 ( F_9 ( V_75 ) ) ;
snprintf ( V_58 , sizeof( V_58 ) , L_3 , V_38 -> V_58 ) ;
V_2 = F_10 ( V_58 , V_75 , strlen ( V_58 ) ) ;
if ( F_11 ( V_2 ) ) {
V_43 = F_12 ( V_2 ) ;
F_37 ( L_15 , V_58 ) ;
goto V_10;
}
F_8 ( F_9 ( V_2 ) ) ;
F_38 ( V_2 , L_5 ) ;
F_38 ( V_2 , L_7 ) ;
F_38 ( V_2 , L_9 ) ;
for ( V_59 = 0 ; V_59 < V_38 -> V_48 ; V_59 ++ ) {
char V_68 [ 24 ] ;
sprintf ( V_68 , L_11 , V_59 + 1 ) ;
F_38 ( V_2 , V_68 ) ;
if ( V_38 -> V_69 & V_70 ) {
sprintf ( V_68 , L_12 , V_59 + 1 ) ;
F_38 ( V_2 , V_68 ) ;
}
}
F_38 ( V_2 , L_13 ) ;
F_13 ( F_9 ( V_2 ) ) ;
V_43 = F_47 ( F_9 ( V_75 ) , V_2 ) ;
F_48 ( V_2 ) ;
F_44 ( V_2 ) ;
V_10:
F_13 ( F_9 ( V_75 ) ) ;
F_44 ( V_75 ) ;
return V_43 ;
}
static int F_49 ( struct V_56 * V_57 , void * V_7 , int V_76 )
{
struct V_37 * V_38 , * V_42 ;
unsigned long V_69 ;
int V_43 ;
static struct V_77 V_78 [] = {
[ 2 ] = { L_16 , & V_79 [ 0 ] , V_61 } ,
[ 3 ] = { L_17 , & V_79 [ 1 ] , V_61 } ,
{ L_18 } ,
} ;
V_43 = F_50 ( V_57 , V_80 , V_78 ) ;
if ( V_43 ) {
F_37 ( L_19 , V_43 ) ;
goto V_10;
}
F_51 ( & V_81 , V_69 ) ;
F_52 (dd, tmp, &qib_dev_list, list) {
F_53 ( & V_81 , V_69 ) ;
V_43 = F_36 ( V_57 , V_38 ) ;
if ( V_43 )
goto V_10;
F_51 ( & V_81 , V_69 ) ;
}
F_53 ( & V_81 , V_69 ) ;
V_10:
return V_43 ;
}
static struct V_3 * F_54 ( struct V_82 * V_83 , int V_69 ,
const char * V_84 , void * V_7 )
{
struct V_3 * V_43 ;
V_43 = F_55 ( V_83 , V_69 , V_7 , F_49 ) ;
if ( ! F_11 ( V_43 ) )
V_85 = V_43 -> V_86 ;
return V_43 ;
}
static void F_56 ( struct V_56 * V_87 )
{
F_57 ( V_87 ) ;
V_85 = NULL ;
}
int F_58 ( struct V_37 * V_38 )
{
int V_43 ;
if ( V_85 == NULL )
V_43 = 0 ;
else
V_43 = F_36 ( V_85 , V_38 ) ;
return V_43 ;
}
int F_59 ( struct V_37 * V_38 )
{
int V_43 = 0 ;
if ( V_85 )
V_43 = F_45 ( V_85 , V_38 ) ;
return V_43 ;
}
int T_7 F_60 ( void )
{
return F_61 ( & V_88 ) ;
}
int T_8 F_62 ( void )
{
return F_63 ( & V_88 ) ;
}
