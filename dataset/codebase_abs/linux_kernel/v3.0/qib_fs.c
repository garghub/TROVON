static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
int V_4 , const struct V_5 * V_6 ,
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
if ( ( V_4 & V_21 ) == V_22 ) {
V_1 -> V_23 = & V_24 ;
F_4 ( V_1 ) ;
F_4 ( V_2 ) ;
}
V_1 -> V_25 = V_6 ;
F_5 ( V_3 , V_1 ) ;
error = 0 ;
V_10:
return error ;
}
static int F_6 ( const char * V_26 , T_1 V_4 ,
struct V_3 * V_27 , struct V_3 * * V_3 ,
const struct V_5 * V_6 , void * V_7 )
{
int error ;
* V_3 = NULL ;
F_7 ( & V_27 -> V_28 -> V_29 ) ;
* V_3 = F_8 ( V_26 , V_27 , strlen ( V_26 ) ) ;
if ( ! F_9 ( * V_3 ) )
error = F_1 ( V_27 -> V_28 , * V_3 ,
V_4 , V_6 , V_7 ) ;
else
error = F_10 ( * V_3 ) ;
F_11 ( & V_27 -> V_28 -> V_29 ) ;
return error ;
}
static T_2 F_12 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
return F_13 ( V_31 , V_32 , V_33 , & V_34 ,
sizeof V_34 ) ;
}
static T_2 F_14 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
return F_13 ( V_31 , V_32 , V_33 , V_35 ,
sizeof V_35 - 1 ) ;
}
static T_2 F_15 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
T_6 * V_36 ;
T_4 V_37 ;
struct V_38 * V_39 = F_16 ( V_30 ) ;
V_37 = V_39 -> V_40 ( V_39 , * V_33 , NULL , & V_36 ) ;
return F_13 ( V_31 , V_32 , V_33 , V_36 , V_37 ) ;
}
static T_2 F_17 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
char * V_41 ;
T_4 V_37 ;
struct V_38 * V_39 = F_16 ( V_30 ) ;
V_37 = V_39 -> V_40 ( V_39 , * V_33 , & V_41 , NULL ) ;
return F_13 ( V_31 , V_32 , V_33 , V_41 , V_37 ) ;
}
static T_2 F_18 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
char * V_41 ;
T_4 V_37 ;
struct V_38 * V_39 = F_16 ( V_30 ) ;
V_37 = V_39 -> V_42 ( V_39 , * V_33 , 0 , & V_41 , NULL ) ;
return F_13 ( V_31 , V_32 , V_33 , V_41 , V_37 ) ;
}
static T_2 F_19 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
T_6 * V_36 ;
T_4 V_37 ;
struct V_38 * V_39 = F_16 ( V_30 ) ;
V_37 = V_39 -> V_42 ( V_39 , * V_33 , 0 , NULL , & V_36 ) ;
return F_13 ( V_31 , V_32 , V_33 , V_36 , V_37 ) ;
}
static T_2 F_20 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
T_6 * V_36 ;
T_4 V_37 ;
struct V_38 * V_39 = F_16 ( V_30 ) ;
V_37 = V_39 -> V_42 ( V_39 , * V_33 , 1 , NULL , & V_36 ) ;
return F_13 ( V_31 , V_32 , V_33 , V_36 , V_37 ) ;
}
static T_2 F_21 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
struct V_38 * V_39 = F_16 ( V_30 ) ;
char * V_43 ;
int V_44 ;
V_43 = F_22 ( V_45 , V_46 ) ;
if ( ! V_43 )
return - V_47 ;
V_44 = F_23 ( V_39 -> V_48 , V_43 , V_45 ) ;
if ( V_44 > 0 )
V_44 = F_13 ( V_31 , V_32 , V_33 , V_43 , V_44 ) ;
F_24 ( V_43 ) ;
return V_44 ;
}
static T_2 F_25 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
struct V_38 * V_39 = F_16 ( V_30 ) ;
char * V_43 ;
int V_44 ;
if ( V_39 -> V_49 < 2 )
return - V_50 ;
V_43 = F_22 ( V_45 , V_46 ) ;
if ( ! V_43 )
return - V_47 ;
V_44 = F_23 ( V_39 -> V_48 + 1 , V_43 , V_45 ) ;
if ( V_44 > 0 )
V_44 = F_13 ( V_31 , V_32 , V_33 , V_43 , V_44 ) ;
F_24 ( V_43 ) ;
return V_44 ;
}
static T_2 F_26 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
struct V_38 * V_39 ;
T_2 V_44 ;
T_5 V_51 ;
char * V_43 ;
V_51 = * V_33 ;
if ( V_51 < 0 ) {
V_44 = - V_52 ;
goto V_10;
}
if ( V_51 >= sizeof( struct V_53 ) ) {
V_44 = 0 ;
goto V_10;
}
if ( V_32 > sizeof( struct V_53 ) - V_51 )
V_32 = sizeof( struct V_53 ) - V_51 ;
V_43 = F_22 ( V_32 , V_46 ) ;
if ( ! V_43 ) {
V_44 = - V_47 ;
goto V_10;
}
V_39 = F_16 ( V_30 ) ;
if ( F_27 ( V_39 , V_51 , V_43 , V_32 ) ) {
F_28 ( V_39 , L_1 ) ;
V_44 = - V_54 ;
goto V_55;
}
if ( F_29 ( V_31 , V_43 , V_32 ) ) {
V_44 = - V_56 ;
goto V_55;
}
* V_33 = V_51 + V_32 ;
V_44 = V_32 ;
V_55:
F_24 ( V_43 ) ;
V_10:
return V_44 ;
}
static T_2 F_30 ( struct V_30 * V_30 , const char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
struct V_38 * V_39 ;
T_2 V_44 ;
T_5 V_51 ;
char * V_43 ;
V_51 = * V_33 ;
if ( V_51 != 0 ) {
V_44 = - V_52 ;
goto V_10;
}
if ( V_32 != sizeof( struct V_53 ) ) {
V_44 = - V_52 ;
goto V_10;
}
V_43 = F_22 ( V_32 , V_46 ) ;
if ( ! V_43 ) {
V_44 = - V_47 ;
goto V_10;
}
if ( F_31 ( V_43 , V_31 , V_32 ) ) {
V_44 = - V_56 ;
goto V_55;
}
V_39 = F_16 ( V_30 ) ;
if ( F_32 ( V_39 , V_51 , V_43 , V_32 ) ) {
V_44 = - V_54 ;
F_28 ( V_39 , L_2 ) ;
goto V_55;
}
* V_33 = V_51 + V_32 ;
V_44 = V_32 ;
V_55:
F_24 ( V_43 ) ;
V_10:
return V_44 ;
}
static int F_33 ( struct V_57 * V_58 , struct V_38 * V_39 )
{
struct V_3 * V_2 , * V_43 ;
char V_59 [ 10 ] ;
int V_44 , V_60 ;
snprintf ( V_59 , sizeof V_59 , L_3 , V_39 -> V_59 ) ;
V_44 = F_6 ( V_59 , V_22 | V_61 | V_62 , V_58 -> V_63 , & V_2 ,
& V_64 , V_39 ) ;
if ( V_44 ) {
F_34 ( V_65 L_4 , V_59 , V_44 ) ;
goto V_10;
}
V_44 = F_6 ( L_5 , V_66 | V_61 , V_2 , & V_43 ,
& V_67 [ 0 ] , V_39 ) ;
if ( V_44 ) {
F_34 ( V_65 L_6 ,
V_59 , V_44 ) ;
goto V_10;
}
V_44 = F_6 ( L_7 , V_66 | V_61 , V_2 , & V_43 ,
& V_67 [ 1 ] , V_39 ) ;
if ( V_44 ) {
F_34 ( V_65 L_8 ,
V_59 , V_44 ) ;
goto V_10;
}
V_44 = F_6 ( L_9 , V_66 | V_61 , V_2 , & V_43 ,
& V_68 [ 0 ] , V_39 ) ;
if ( V_44 ) {
F_34 ( V_65 L_10 ,
V_59 , L_9 , V_44 ) ;
goto V_10;
}
for ( V_60 = 1 ; V_60 <= V_39 -> V_49 ; V_60 ++ ) {
char V_69 [ 24 ] ;
sprintf ( V_69 , L_11 , V_60 ) ;
V_44 = F_6 ( V_69 , V_66 | V_61 , V_2 , & V_43 ,
& V_68 [ V_60 ] , V_39 ) ;
if ( V_44 ) {
F_34 ( V_65 L_10 ,
V_59 , V_69 , V_44 ) ;
goto V_10;
}
if ( ! ( V_39 -> V_70 & V_71 ) )
continue;
sprintf ( V_69 , L_12 , V_60 ) ;
V_44 = F_6 ( V_69 , V_66 | V_61 , V_2 , & V_43 ,
& V_72 [ V_60 - 1 ] , V_39 ) ;
if ( V_44 ) {
F_34 ( V_65 L_10 ,
V_59 , V_69 , V_44 ) ;
goto V_10;
}
}
V_44 = F_6 ( L_13 , V_66 | V_73 | V_61 , V_2 , & V_43 ,
& V_74 , V_39 ) ;
if ( V_44 )
F_34 ( V_65 L_14 ,
V_59 , V_44 ) ;
V_10:
return V_44 ;
}
static int F_35 ( struct V_3 * V_27 , char * V_26 )
{
struct V_3 * V_43 ;
int V_44 ;
V_43 = F_8 ( V_26 , V_27 , strlen ( V_26 ) ) ;
if ( F_9 ( V_43 ) ) {
V_44 = F_10 ( V_43 ) ;
goto V_10;
}
F_36 ( & V_43 -> V_75 ) ;
if ( ! ( F_37 ( V_43 ) && V_43 -> V_28 ) ) {
F_38 ( V_43 ) ;
F_39 ( V_43 ) ;
F_40 ( & V_43 -> V_75 ) ;
F_41 ( V_27 -> V_28 , V_43 ) ;
} else {
F_40 ( & V_43 -> V_75 ) ;
}
V_44 = 0 ;
V_10:
return V_44 ;
}
static int F_42 ( struct V_57 * V_58 ,
struct V_38 * V_39 )
{
struct V_3 * V_2 , * V_76 ;
char V_59 [ 10 ] ;
int V_44 , V_60 ;
V_76 = F_43 ( V_58 -> V_63 ) ;
F_7 ( & V_76 -> V_28 -> V_29 ) ;
snprintf ( V_59 , sizeof V_59 , L_3 , V_39 -> V_59 ) ;
V_2 = F_8 ( V_59 , V_76 , strlen ( V_59 ) ) ;
if ( F_9 ( V_2 ) ) {
V_44 = F_10 ( V_2 ) ;
F_34 ( V_65 L_15 , V_59 ) ;
goto V_10;
}
F_35 ( V_2 , L_5 ) ;
F_35 ( V_2 , L_7 ) ;
F_35 ( V_2 , L_9 ) ;
for ( V_60 = 0 ; V_60 < V_39 -> V_49 ; V_60 ++ ) {
char V_69 [ 24 ] ;
sprintf ( V_69 , L_11 , V_60 + 1 ) ;
F_35 ( V_2 , V_69 ) ;
if ( V_39 -> V_70 & V_71 ) {
sprintf ( V_69 , L_12 , V_60 + 1 ) ;
F_35 ( V_2 , V_69 ) ;
}
}
F_35 ( V_2 , L_13 ) ;
F_44 ( V_2 ) ;
V_44 = F_45 ( V_76 -> V_28 , V_2 ) ;
V_10:
F_11 ( & V_76 -> V_28 -> V_29 ) ;
F_46 ( V_76 ) ;
return V_44 ;
}
static int F_47 ( struct V_57 * V_58 , void * V_7 , int V_77 )
{
struct V_38 * V_39 , * V_43 ;
unsigned long V_70 ;
int V_44 ;
static struct V_78 V_79 [] = {
[ 2 ] = { L_16 , & V_80 [ 0 ] , V_61 } ,
[ 3 ] = { L_17 , & V_80 [ 1 ] , V_61 } ,
{ L_18 } ,
} ;
V_44 = F_48 ( V_58 , V_81 , V_79 ) ;
if ( V_44 ) {
F_34 ( V_65 L_19 , V_44 ) ;
goto V_10;
}
F_49 ( & V_82 , V_70 ) ;
F_50 (dd, tmp, &qib_dev_list, list) {
F_51 ( & V_82 , V_70 ) ;
V_44 = F_33 ( V_58 , V_39 ) ;
if ( V_44 )
goto V_10;
F_49 ( & V_82 , V_70 ) ;
}
F_51 ( & V_82 , V_70 ) ;
V_10:
return V_44 ;
}
static struct V_3 * F_52 ( struct V_83 * V_84 , int V_70 ,
const char * V_85 , void * V_7 )
{
struct V_3 * V_44 ;
V_44 = F_53 ( V_84 , V_70 , V_7 , F_47 ) ;
if ( ! F_9 ( V_44 ) )
V_86 = V_44 -> V_87 ;
return V_44 ;
}
static void F_54 ( struct V_57 * V_88 )
{
F_55 ( V_88 ) ;
V_86 = NULL ;
}
int F_56 ( struct V_38 * V_39 )
{
int V_44 ;
if ( V_86 == NULL )
V_44 = 0 ;
else
V_44 = F_33 ( V_86 , V_39 ) ;
return V_44 ;
}
int F_57 ( struct V_38 * V_39 )
{
int V_44 = 0 ;
if ( V_86 )
V_44 = F_42 ( V_86 , V_39 ) ;
return V_44 ;
}
int T_7 F_58 ( void )
{
return F_59 ( & V_89 ) ;
}
int T_8 F_60 ( void )
{
return F_61 ( & V_89 ) ;
}
