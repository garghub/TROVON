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
V_1 -> V_13 = 0 ;
V_1 -> V_14 = 0 ;
V_1 -> V_15 = 0 ;
V_1 -> V_16 = V_17 ;
V_1 -> V_18 = V_1 -> V_16 ;
V_1 -> V_19 = V_1 -> V_16 ;
V_1 -> V_20 = V_7 ;
if ( F_4 ( V_4 ) ) {
V_1 -> V_21 = & V_22 ;
F_5 ( V_1 ) ;
F_5 ( V_2 ) ;
}
V_1 -> V_23 = V_6 ;
F_6 ( V_3 , V_1 ) ;
error = 0 ;
V_10:
return error ;
}
static int F_7 ( const char * V_24 , T_1 V_4 ,
struct V_3 * V_25 , struct V_3 * * V_3 ,
const struct V_5 * V_6 , void * V_7 )
{
int error ;
* V_3 = NULL ;
F_8 ( & V_25 -> V_26 -> V_27 ) ;
* V_3 = F_9 ( V_24 , V_25 , strlen ( V_24 ) ) ;
if ( ! F_10 ( * V_3 ) )
error = F_1 ( V_25 -> V_26 , * V_3 ,
V_4 , V_6 , V_7 ) ;
else
error = F_11 ( * V_3 ) ;
F_12 ( & V_25 -> V_26 -> V_27 ) ;
return error ;
}
static T_2 F_13 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
return F_14 ( V_29 , V_30 , V_31 , & V_32 ,
sizeof V_32 ) ;
}
static T_2 F_15 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
return F_14 ( V_29 , V_30 , V_31 , V_33 ,
sizeof V_33 - 1 ) ;
}
static T_2 F_16 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
T_6 * V_34 ;
T_4 V_35 ;
struct V_36 * V_37 = F_17 ( V_28 ) ;
V_35 = V_37 -> V_38 ( V_37 , * V_31 , NULL , & V_34 ) ;
return F_14 ( V_29 , V_30 , V_31 , V_34 , V_35 ) ;
}
static T_2 F_18 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
char * V_39 ;
T_4 V_35 ;
struct V_36 * V_37 = F_17 ( V_28 ) ;
V_35 = V_37 -> V_38 ( V_37 , * V_31 , & V_39 , NULL ) ;
return F_14 ( V_29 , V_30 , V_31 , V_39 , V_35 ) ;
}
static T_2 F_19 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
char * V_39 ;
T_4 V_35 ;
struct V_36 * V_37 = F_17 ( V_28 ) ;
V_35 = V_37 -> V_40 ( V_37 , * V_31 , 0 , & V_39 , NULL ) ;
return F_14 ( V_29 , V_30 , V_31 , V_39 , V_35 ) ;
}
static T_2 F_20 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
T_6 * V_34 ;
T_4 V_35 ;
struct V_36 * V_37 = F_17 ( V_28 ) ;
V_35 = V_37 -> V_40 ( V_37 , * V_31 , 0 , NULL , & V_34 ) ;
return F_14 ( V_29 , V_30 , V_31 , V_34 , V_35 ) ;
}
static T_2 F_21 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
T_6 * V_34 ;
T_4 V_35 ;
struct V_36 * V_37 = F_17 ( V_28 ) ;
V_35 = V_37 -> V_40 ( V_37 , * V_31 , 1 , NULL , & V_34 ) ;
return F_14 ( V_29 , V_30 , V_31 , V_34 , V_35 ) ;
}
static T_2 F_22 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
struct V_36 * V_37 = F_17 ( V_28 ) ;
char * V_41 ;
int V_42 ;
V_41 = F_23 ( V_43 , V_44 ) ;
if ( ! V_41 )
return - V_45 ;
V_42 = F_24 ( V_37 -> V_46 , V_41 , V_43 ) ;
if ( V_42 > 0 )
V_42 = F_14 ( V_29 , V_30 , V_31 , V_41 , V_42 ) ;
F_25 ( V_41 ) ;
return V_42 ;
}
static T_2 F_26 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
struct V_36 * V_37 = F_17 ( V_28 ) ;
char * V_41 ;
int V_42 ;
if ( V_37 -> V_47 < 2 )
return - V_48 ;
V_41 = F_23 ( V_43 , V_44 ) ;
if ( ! V_41 )
return - V_45 ;
V_42 = F_24 ( V_37 -> V_46 + 1 , V_41 , V_43 ) ;
if ( V_42 > 0 )
V_42 = F_14 ( V_29 , V_30 , V_31 , V_41 , V_42 ) ;
F_25 ( V_41 ) ;
return V_42 ;
}
static T_2 F_27 ( struct V_28 * V_28 , char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
struct V_36 * V_37 ;
T_2 V_42 ;
T_5 V_49 ;
char * V_41 ;
V_49 = * V_31 ;
if ( V_49 < 0 ) {
V_42 = - V_50 ;
goto V_10;
}
if ( V_49 >= sizeof( struct V_51 ) ) {
V_42 = 0 ;
goto V_10;
}
if ( V_30 > sizeof( struct V_51 ) - V_49 )
V_30 = sizeof( struct V_51 ) - V_49 ;
V_41 = F_23 ( V_30 , V_44 ) ;
if ( ! V_41 ) {
V_42 = - V_45 ;
goto V_10;
}
V_37 = F_17 ( V_28 ) ;
if ( F_28 ( V_37 , V_49 , V_41 , V_30 ) ) {
F_29 ( V_37 , L_1 ) ;
V_42 = - V_52 ;
goto V_53;
}
if ( F_30 ( V_29 , V_41 , V_30 ) ) {
V_42 = - V_54 ;
goto V_53;
}
* V_31 = V_49 + V_30 ;
V_42 = V_30 ;
V_53:
F_25 ( V_41 ) ;
V_10:
return V_42 ;
}
static T_2 F_31 ( struct V_28 * V_28 , const char T_3 * V_29 ,
T_4 V_30 , T_5 * V_31 )
{
struct V_36 * V_37 ;
T_2 V_42 ;
T_5 V_49 ;
char * V_41 ;
V_49 = * V_31 ;
if ( V_49 != 0 ) {
V_42 = - V_50 ;
goto V_10;
}
if ( V_30 != sizeof( struct V_51 ) ) {
V_42 = - V_50 ;
goto V_10;
}
V_41 = F_23 ( V_30 , V_44 ) ;
if ( ! V_41 ) {
V_42 = - V_45 ;
goto V_10;
}
if ( F_32 ( V_41 , V_29 , V_30 ) ) {
V_42 = - V_54 ;
goto V_53;
}
V_37 = F_17 ( V_28 ) ;
if ( F_33 ( V_37 , V_49 , V_41 , V_30 ) ) {
V_42 = - V_52 ;
F_29 ( V_37 , L_2 ) ;
goto V_53;
}
* V_31 = V_49 + V_30 ;
V_42 = V_30 ;
V_53:
F_25 ( V_41 ) ;
V_10:
return V_42 ;
}
static int F_34 ( struct V_55 * V_56 , struct V_36 * V_37 )
{
struct V_3 * V_2 , * V_41 ;
char V_57 [ 10 ] ;
int V_42 , V_58 ;
snprintf ( V_57 , sizeof V_57 , L_3 , V_37 -> V_57 ) ;
V_42 = F_7 ( V_57 , V_59 | V_60 | V_61 , V_56 -> V_62 , & V_2 ,
& V_63 , V_37 ) ;
if ( V_42 ) {
F_35 ( V_64 L_4 , V_57 , V_42 ) ;
goto V_10;
}
V_42 = F_7 ( L_5 , V_65 | V_60 , V_2 , & V_41 ,
& V_66 [ 0 ] , V_37 ) ;
if ( V_42 ) {
F_35 ( V_64 L_6 ,
V_57 , V_42 ) ;
goto V_10;
}
V_42 = F_7 ( L_7 , V_65 | V_60 , V_2 , & V_41 ,
& V_66 [ 1 ] , V_37 ) ;
if ( V_42 ) {
F_35 ( V_64 L_8 ,
V_57 , V_42 ) ;
goto V_10;
}
V_42 = F_7 ( L_9 , V_65 | V_60 , V_2 , & V_41 ,
& V_67 [ 0 ] , V_37 ) ;
if ( V_42 ) {
F_35 ( V_64 L_10 ,
V_57 , L_9 , V_42 ) ;
goto V_10;
}
for ( V_58 = 1 ; V_58 <= V_37 -> V_47 ; V_58 ++ ) {
char V_68 [ 24 ] ;
sprintf ( V_68 , L_11 , V_58 ) ;
V_42 = F_7 ( V_68 , V_65 | V_60 , V_2 , & V_41 ,
& V_67 [ V_58 ] , V_37 ) ;
if ( V_42 ) {
F_35 ( V_64 L_10 ,
V_57 , V_68 , V_42 ) ;
goto V_10;
}
if ( ! ( V_37 -> V_69 & V_70 ) )
continue;
sprintf ( V_68 , L_12 , V_58 ) ;
V_42 = F_7 ( V_68 , V_65 | V_60 , V_2 , & V_41 ,
& V_71 [ V_58 - 1 ] , V_37 ) ;
if ( V_42 ) {
F_35 ( V_64 L_10 ,
V_57 , V_68 , V_42 ) ;
goto V_10;
}
}
V_42 = F_7 ( L_13 , V_65 | V_72 | V_60 , V_2 , & V_41 ,
& V_73 , V_37 ) ;
if ( V_42 )
F_35 ( V_64 L_14 ,
V_57 , V_42 ) ;
V_10:
return V_42 ;
}
static int F_36 ( struct V_3 * V_25 , char * V_24 )
{
struct V_3 * V_41 ;
int V_42 ;
V_41 = F_9 ( V_24 , V_25 , strlen ( V_24 ) ) ;
if ( F_10 ( V_41 ) ) {
V_42 = F_11 ( V_41 ) ;
goto V_10;
}
F_37 ( & V_41 -> V_74 ) ;
if ( ! ( F_38 ( V_41 ) && V_41 -> V_26 ) ) {
F_39 ( V_41 ) ;
F_40 ( V_41 ) ;
F_41 ( & V_41 -> V_74 ) ;
F_42 ( V_25 -> V_26 , V_41 ) ;
} else {
F_41 ( & V_41 -> V_74 ) ;
}
V_42 = 0 ;
V_10:
return V_42 ;
}
static int F_43 ( struct V_55 * V_56 ,
struct V_36 * V_37 )
{
struct V_3 * V_2 , * V_75 ;
char V_57 [ 10 ] ;
int V_42 , V_58 ;
V_75 = F_44 ( V_56 -> V_62 ) ;
F_8 ( & V_75 -> V_26 -> V_27 ) ;
snprintf ( V_57 , sizeof V_57 , L_3 , V_37 -> V_57 ) ;
V_2 = F_9 ( V_57 , V_75 , strlen ( V_57 ) ) ;
if ( F_10 ( V_2 ) ) {
V_42 = F_11 ( V_2 ) ;
F_35 ( V_64 L_15 , V_57 ) ;
goto V_10;
}
F_36 ( V_2 , L_5 ) ;
F_36 ( V_2 , L_7 ) ;
F_36 ( V_2 , L_9 ) ;
for ( V_58 = 0 ; V_58 < V_37 -> V_47 ; V_58 ++ ) {
char V_68 [ 24 ] ;
sprintf ( V_68 , L_11 , V_58 + 1 ) ;
F_36 ( V_2 , V_68 ) ;
if ( V_37 -> V_69 & V_70 ) {
sprintf ( V_68 , L_12 , V_58 + 1 ) ;
F_36 ( V_2 , V_68 ) ;
}
}
F_36 ( V_2 , L_13 ) ;
F_45 ( V_2 ) ;
V_42 = F_46 ( V_75 -> V_26 , V_2 ) ;
V_10:
F_12 ( & V_75 -> V_26 -> V_27 ) ;
F_47 ( V_75 ) ;
return V_42 ;
}
static int F_48 ( struct V_55 * V_56 , void * V_7 , int V_76 )
{
struct V_36 * V_37 , * V_41 ;
unsigned long V_69 ;
int V_42 ;
static struct V_77 V_78 [] = {
[ 2 ] = { L_16 , & V_79 [ 0 ] , V_60 } ,
[ 3 ] = { L_17 , & V_79 [ 1 ] , V_60 } ,
{ L_18 } ,
} ;
V_42 = F_49 ( V_56 , V_80 , V_78 ) ;
if ( V_42 ) {
F_35 ( V_64 L_19 , V_42 ) ;
goto V_10;
}
F_50 ( & V_81 , V_69 ) ;
F_51 (dd, tmp, &qib_dev_list, list) {
F_52 ( & V_81 , V_69 ) ;
V_42 = F_34 ( V_56 , V_37 ) ;
if ( V_42 )
goto V_10;
F_50 ( & V_81 , V_69 ) ;
}
F_52 ( & V_81 , V_69 ) ;
V_10:
return V_42 ;
}
static struct V_3 * F_53 ( struct V_82 * V_83 , int V_69 ,
const char * V_84 , void * V_7 )
{
struct V_3 * V_42 ;
V_42 = F_54 ( V_83 , V_69 , V_7 , F_48 ) ;
if ( ! F_10 ( V_42 ) )
V_85 = V_42 -> V_86 ;
return V_42 ;
}
static void F_55 ( struct V_55 * V_87 )
{
F_56 ( V_87 ) ;
V_85 = NULL ;
}
int F_57 ( struct V_36 * V_37 )
{
int V_42 ;
if ( V_85 == NULL )
V_42 = 0 ;
else
V_42 = F_34 ( V_85 , V_37 ) ;
return V_42 ;
}
int F_58 ( struct V_36 * V_37 )
{
int V_42 = 0 ;
if ( V_85 )
V_42 = F_43 ( V_85 , V_37 ) ;
return V_42 ;
}
int T_7 F_59 ( void )
{
return F_60 ( & V_88 ) ;
}
int T_8 F_61 ( void )
{
return F_62 ( & V_88 ) ;
}
