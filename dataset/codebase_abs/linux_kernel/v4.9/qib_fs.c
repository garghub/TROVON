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
V_1 -> V_18 = F_4 ( V_1 ) ;
V_1 -> V_19 = V_1 -> V_18 ;
V_1 -> V_20 = V_1 -> V_18 ;
V_1 -> V_21 = V_7 ;
if ( F_5 ( V_4 ) ) {
V_1 -> V_22 = & V_23 ;
F_6 ( V_1 ) ;
F_6 ( V_2 ) ;
}
V_1 -> V_24 = V_6 ;
F_7 ( V_3 , V_1 ) ;
error = 0 ;
V_10:
return error ;
}
static int F_8 ( const char * V_25 , T_1 V_4 ,
struct V_3 * V_26 , struct V_3 * * V_3 ,
const struct V_5 * V_6 , void * V_7 )
{
int error ;
F_9 ( F_10 ( V_26 ) ) ;
* V_3 = F_11 ( V_25 , V_26 , strlen ( V_25 ) ) ;
if ( ! F_12 ( * V_3 ) )
error = F_1 ( F_10 ( V_26 ) , * V_3 ,
V_4 , V_6 , V_7 ) ;
else
error = F_13 ( * V_3 ) ;
F_14 ( F_10 ( V_26 ) ) ;
return error ;
}
static T_2 F_15 ( struct V_27 * V_27 , char T_3 * V_28 ,
T_4 V_29 , T_5 * V_30 )
{
V_31 . V_32 = F_16 () ;
return F_17 ( V_28 , V_29 , V_30 , & V_31 ,
sizeof( V_31 ) ) ;
}
static T_2 F_18 ( struct V_27 * V_27 , char T_3 * V_28 ,
T_4 V_29 , T_5 * V_30 )
{
return F_17 ( V_28 , V_29 , V_30 , V_33 ,
sizeof( V_33 ) - 1 ) ;
}
static T_2 F_19 ( struct V_27 * V_27 , char T_3 * V_28 ,
T_4 V_29 , T_5 * V_30 )
{
T_6 * V_34 ;
T_4 V_35 ;
struct V_36 * V_37 = F_20 ( V_27 ) ;
V_35 = V_37 -> V_38 ( V_37 , * V_30 , NULL , & V_34 ) ;
return F_17 ( V_28 , V_29 , V_30 , V_34 , V_35 ) ;
}
static T_2 F_21 ( struct V_27 * V_27 , char T_3 * V_28 ,
T_4 V_29 , T_5 * V_30 )
{
char * V_39 ;
T_4 V_35 ;
struct V_36 * V_37 = F_20 ( V_27 ) ;
V_35 = V_37 -> V_38 ( V_37 , * V_30 , & V_39 , NULL ) ;
return F_17 ( V_28 , V_29 , V_30 , V_39 , V_35 ) ;
}
static T_2 F_22 ( struct V_27 * V_27 , char T_3 * V_28 ,
T_4 V_29 , T_5 * V_30 )
{
char * V_39 ;
T_4 V_35 ;
struct V_36 * V_37 = F_20 ( V_27 ) ;
V_35 = V_37 -> V_40 ( V_37 , * V_30 , 0 , & V_39 , NULL ) ;
return F_17 ( V_28 , V_29 , V_30 , V_39 , V_35 ) ;
}
static T_2 F_23 ( struct V_27 * V_27 , char T_3 * V_28 ,
T_4 V_29 , T_5 * V_30 )
{
T_6 * V_34 ;
T_4 V_35 ;
struct V_36 * V_37 = F_20 ( V_27 ) ;
V_35 = V_37 -> V_40 ( V_37 , * V_30 , 0 , NULL , & V_34 ) ;
return F_17 ( V_28 , V_29 , V_30 , V_34 , V_35 ) ;
}
static T_2 F_24 ( struct V_27 * V_27 , char T_3 * V_28 ,
T_4 V_29 , T_5 * V_30 )
{
T_6 * V_34 ;
T_4 V_35 ;
struct V_36 * V_37 = F_20 ( V_27 ) ;
V_35 = V_37 -> V_40 ( V_37 , * V_30 , 1 , NULL , & V_34 ) ;
return F_17 ( V_28 , V_29 , V_30 , V_34 , V_35 ) ;
}
static T_2 F_25 ( struct V_27 * V_27 , char T_3 * V_28 ,
T_4 V_29 , T_5 * V_30 )
{
struct V_36 * V_37 = F_20 ( V_27 ) ;
char * V_41 ;
int V_42 ;
V_41 = F_26 ( V_43 , V_44 ) ;
if ( ! V_41 )
return - V_45 ;
V_42 = F_27 ( V_37 -> V_46 , V_41 , V_43 ) ;
if ( V_42 > 0 )
V_42 = F_17 ( V_28 , V_29 , V_30 , V_41 , V_42 ) ;
F_28 ( V_41 ) ;
return V_42 ;
}
static T_2 F_29 ( struct V_27 * V_27 , char T_3 * V_28 ,
T_4 V_29 , T_5 * V_30 )
{
struct V_36 * V_37 = F_20 ( V_27 ) ;
char * V_41 ;
int V_42 ;
if ( V_37 -> V_47 < 2 )
return - V_48 ;
V_41 = F_26 ( V_43 , V_44 ) ;
if ( ! V_41 )
return - V_45 ;
V_42 = F_27 ( V_37 -> V_46 + 1 , V_41 , V_43 ) ;
if ( V_42 > 0 )
V_42 = F_17 ( V_28 , V_29 , V_30 , V_41 , V_42 ) ;
F_28 ( V_41 ) ;
return V_42 ;
}
static T_2 F_30 ( struct V_27 * V_27 , char T_3 * V_28 ,
T_4 V_29 , T_5 * V_30 )
{
struct V_36 * V_37 ;
T_2 V_42 ;
T_5 V_49 ;
char * V_41 ;
V_49 = * V_30 ;
if ( V_49 < 0 ) {
V_42 = - V_50 ;
goto V_10;
}
if ( V_49 >= sizeof( struct V_51 ) ) {
V_42 = 0 ;
goto V_10;
}
if ( V_29 > sizeof( struct V_51 ) - V_49 )
V_29 = sizeof( struct V_51 ) - V_49 ;
V_41 = F_26 ( V_29 , V_44 ) ;
if ( ! V_41 ) {
V_42 = - V_45 ;
goto V_10;
}
V_37 = F_20 ( V_27 ) ;
if ( F_31 ( V_37 , V_49 , V_41 , V_29 ) ) {
F_32 ( V_37 , L_1 ) ;
V_42 = - V_52 ;
goto V_53;
}
if ( F_33 ( V_28 , V_41 , V_29 ) ) {
V_42 = - V_54 ;
goto V_53;
}
* V_30 = V_49 + V_29 ;
V_42 = V_29 ;
V_53:
F_28 ( V_41 ) ;
V_10:
return V_42 ;
}
static T_2 F_34 ( struct V_27 * V_27 , const char T_3 * V_28 ,
T_4 V_29 , T_5 * V_30 )
{
struct V_36 * V_37 ;
T_2 V_42 ;
T_5 V_49 ;
char * V_41 ;
V_49 = * V_30 ;
if ( V_49 != 0 || V_29 != sizeof( struct V_51 ) )
return - V_50 ;
V_41 = F_35 ( V_28 , V_29 ) ;
if ( F_12 ( V_41 ) )
return F_13 ( V_41 ) ;
V_37 = F_20 ( V_27 ) ;
if ( F_36 ( V_37 , V_49 , V_41 , V_29 ) ) {
V_42 = - V_52 ;
F_32 ( V_37 , L_2 ) ;
goto V_53;
}
* V_30 = V_49 + V_29 ;
V_42 = V_29 ;
V_53:
F_28 ( V_41 ) ;
return V_42 ;
}
static int F_37 ( struct V_55 * V_56 , struct V_36 * V_37 )
{
struct V_3 * V_2 , * V_41 ;
char V_57 [ 10 ] ;
int V_42 , V_58 ;
snprintf ( V_57 , sizeof( V_57 ) , L_3 , V_37 -> V_57 ) ;
V_42 = F_8 ( V_57 , V_59 | V_60 | V_61 , V_56 -> V_62 , & V_2 ,
& V_63 , V_37 ) ;
if ( V_42 ) {
F_38 ( L_4 , V_57 , V_42 ) ;
goto V_10;
}
V_42 = F_8 ( L_5 , V_64 | V_60 , V_2 , & V_41 ,
& V_65 [ 0 ] , V_37 ) ;
if ( V_42 ) {
F_38 ( L_6 ,
V_57 , V_42 ) ;
goto V_10;
}
V_42 = F_8 ( L_7 , V_64 | V_60 , V_2 , & V_41 ,
& V_65 [ 1 ] , V_37 ) ;
if ( V_42 ) {
F_38 ( L_8 ,
V_57 , V_42 ) ;
goto V_10;
}
V_42 = F_8 ( L_9 , V_64 | V_60 , V_2 , & V_41 ,
& V_66 [ 0 ] , V_37 ) ;
if ( V_42 ) {
F_38 ( L_10 ,
V_57 , L_9 , V_42 ) ;
goto V_10;
}
for ( V_58 = 1 ; V_58 <= V_37 -> V_47 ; V_58 ++ ) {
char V_67 [ 24 ] ;
sprintf ( V_67 , L_11 , V_58 ) ;
V_42 = F_8 ( V_67 , V_64 | V_60 , V_2 , & V_41 ,
& V_66 [ V_58 ] , V_37 ) ;
if ( V_42 ) {
F_38 ( L_10 ,
V_57 , V_67 , V_42 ) ;
goto V_10;
}
if ( ! ( V_37 -> V_68 & V_69 ) )
continue;
sprintf ( V_67 , L_12 , V_58 ) ;
V_42 = F_8 ( V_67 , V_64 | V_60 , V_2 , & V_41 ,
& V_70 [ V_58 - 1 ] , V_37 ) ;
if ( V_42 ) {
F_38 ( L_10 ,
V_57 , V_67 , V_42 ) ;
goto V_10;
}
}
V_42 = F_8 ( L_13 , V_64 | V_71 | V_60 , V_2 , & V_41 ,
& V_72 , V_37 ) ;
if ( V_42 )
F_38 ( L_14 ,
V_57 , V_42 ) ;
V_10:
return V_42 ;
}
static int F_39 ( struct V_3 * V_26 , char * V_25 )
{
struct V_3 * V_41 ;
int V_42 ;
V_41 = F_11 ( V_25 , V_26 , strlen ( V_25 ) ) ;
if ( F_12 ( V_41 ) ) {
V_42 = F_13 ( V_41 ) ;
goto V_10;
}
F_40 ( & V_41 -> V_73 ) ;
if ( F_41 ( V_41 ) ) {
F_42 ( V_41 ) ;
F_43 ( & V_41 -> V_73 ) ;
F_44 ( F_10 ( V_26 ) , V_41 ) ;
} else {
F_43 ( & V_41 -> V_73 ) ;
}
F_45 ( V_41 ) ;
V_42 = 0 ;
V_10:
return V_42 ;
}
static int F_46 ( struct V_55 * V_56 ,
struct V_36 * V_37 )
{
struct V_3 * V_2 , * V_74 ;
char V_57 [ 10 ] ;
int V_42 , V_58 ;
V_74 = F_47 ( V_56 -> V_62 ) ;
F_9 ( F_10 ( V_74 ) ) ;
snprintf ( V_57 , sizeof( V_57 ) , L_3 , V_37 -> V_57 ) ;
V_2 = F_11 ( V_57 , V_74 , strlen ( V_57 ) ) ;
if ( F_12 ( V_2 ) ) {
V_42 = F_13 ( V_2 ) ;
F_38 ( L_15 , V_57 ) ;
goto V_10;
}
F_9 ( F_10 ( V_2 ) ) ;
F_39 ( V_2 , L_5 ) ;
F_39 ( V_2 , L_7 ) ;
F_39 ( V_2 , L_9 ) ;
for ( V_58 = 0 ; V_58 < V_37 -> V_47 ; V_58 ++ ) {
char V_67 [ 24 ] ;
sprintf ( V_67 , L_11 , V_58 + 1 ) ;
F_39 ( V_2 , V_67 ) ;
if ( V_37 -> V_68 & V_69 ) {
sprintf ( V_67 , L_12 , V_58 + 1 ) ;
F_39 ( V_2 , V_67 ) ;
}
}
F_39 ( V_2 , L_13 ) ;
F_14 ( F_10 ( V_2 ) ) ;
V_42 = F_48 ( F_10 ( V_74 ) , V_2 ) ;
F_49 ( V_2 ) ;
F_45 ( V_2 ) ;
V_10:
F_14 ( F_10 ( V_74 ) ) ;
F_45 ( V_74 ) ;
return V_42 ;
}
static int F_50 ( struct V_55 * V_56 , void * V_7 , int V_75 )
{
struct V_36 * V_37 , * V_41 ;
unsigned long V_68 ;
int V_42 ;
static struct V_76 V_77 [] = {
[ 2 ] = { L_16 , & V_78 [ 0 ] , V_60 } ,
[ 3 ] = { L_17 , & V_78 [ 1 ] , V_60 } ,
{ L_18 } ,
} ;
V_42 = F_51 ( V_56 , V_79 , V_77 ) ;
if ( V_42 ) {
F_38 ( L_19 , V_42 ) ;
goto V_10;
}
F_52 ( & V_80 , V_68 ) ;
F_53 (dd, tmp, &qib_dev_list, list) {
F_54 ( & V_80 , V_68 ) ;
V_42 = F_37 ( V_56 , V_37 ) ;
if ( V_42 )
goto V_10;
F_52 ( & V_80 , V_68 ) ;
}
F_54 ( & V_80 , V_68 ) ;
V_10:
return V_42 ;
}
static struct V_3 * F_55 ( struct V_81 * V_82 , int V_68 ,
const char * V_83 , void * V_7 )
{
struct V_3 * V_42 ;
V_42 = F_56 ( V_82 , V_68 , V_7 , F_50 ) ;
if ( ! F_12 ( V_42 ) )
V_84 = V_42 -> V_85 ;
return V_42 ;
}
static void F_57 ( struct V_55 * V_86 )
{
F_58 ( V_86 ) ;
V_84 = NULL ;
}
int F_59 ( struct V_36 * V_37 )
{
int V_42 ;
if ( V_84 == NULL )
V_42 = 0 ;
else
V_42 = F_37 ( V_84 , V_37 ) ;
return V_42 ;
}
int F_60 ( struct V_36 * V_37 )
{
int V_42 = 0 ;
if ( V_84 )
V_42 = F_46 ( V_84 , V_37 ) ;
return V_42 ;
}
int T_7 F_61 ( void )
{
return F_62 ( & V_87 ) ;
}
int T_8 F_63 ( void )
{
return F_64 ( & V_87 ) ;
}
