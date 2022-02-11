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
* V_3 = NULL ;
F_8 ( & V_27 -> V_28 -> V_29 ) ;
* V_3 = F_9 ( V_26 , V_27 , strlen ( V_26 ) ) ;
if ( ! F_10 ( * V_3 ) )
error = F_1 ( V_27 -> V_28 , * V_3 ,
V_4 , V_6 , V_7 ) ;
else
error = F_11 ( * V_3 ) ;
F_12 ( & V_27 -> V_28 -> V_29 ) ;
return error ;
}
static T_2 F_13 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
V_34 . V_35 = F_14 () ;
return F_15 ( V_31 , V_32 , V_33 , & V_34 ,
sizeof V_34 ) ;
}
static T_2 F_16 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
return F_15 ( V_31 , V_32 , V_33 , V_36 ,
sizeof V_36 - 1 ) ;
}
static T_2 F_17 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
T_6 * V_37 ;
T_4 V_38 ;
struct V_39 * V_40 = F_18 ( V_30 ) ;
V_38 = V_40 -> V_41 ( V_40 , * V_33 , NULL , & V_37 ) ;
return F_15 ( V_31 , V_32 , V_33 , V_37 , V_38 ) ;
}
static T_2 F_19 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
char * V_42 ;
T_4 V_38 ;
struct V_39 * V_40 = F_18 ( V_30 ) ;
V_38 = V_40 -> V_41 ( V_40 , * V_33 , & V_42 , NULL ) ;
return F_15 ( V_31 , V_32 , V_33 , V_42 , V_38 ) ;
}
static T_2 F_20 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
char * V_42 ;
T_4 V_38 ;
struct V_39 * V_40 = F_18 ( V_30 ) ;
V_38 = V_40 -> V_43 ( V_40 , * V_33 , 0 , & V_42 , NULL ) ;
return F_15 ( V_31 , V_32 , V_33 , V_42 , V_38 ) ;
}
static T_2 F_21 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
T_6 * V_37 ;
T_4 V_38 ;
struct V_39 * V_40 = F_18 ( V_30 ) ;
V_38 = V_40 -> V_43 ( V_40 , * V_33 , 0 , NULL , & V_37 ) ;
return F_15 ( V_31 , V_32 , V_33 , V_37 , V_38 ) ;
}
static T_2 F_22 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
T_6 * V_37 ;
T_4 V_38 ;
struct V_39 * V_40 = F_18 ( V_30 ) ;
V_38 = V_40 -> V_43 ( V_40 , * V_33 , 1 , NULL , & V_37 ) ;
return F_15 ( V_31 , V_32 , V_33 , V_37 , V_38 ) ;
}
static T_2 F_23 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
struct V_39 * V_40 = F_18 ( V_30 ) ;
char * V_44 ;
int V_45 ;
V_44 = F_24 ( V_46 , V_47 ) ;
if ( ! V_44 )
return - V_48 ;
V_45 = F_25 ( V_40 -> V_49 , V_44 , V_46 ) ;
if ( V_45 > 0 )
V_45 = F_15 ( V_31 , V_32 , V_33 , V_44 , V_45 ) ;
F_26 ( V_44 ) ;
return V_45 ;
}
static T_2 F_27 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
struct V_39 * V_40 = F_18 ( V_30 ) ;
char * V_44 ;
int V_45 ;
if ( V_40 -> V_50 < 2 )
return - V_51 ;
V_44 = F_24 ( V_46 , V_47 ) ;
if ( ! V_44 )
return - V_48 ;
V_45 = F_25 ( V_40 -> V_49 + 1 , V_44 , V_46 ) ;
if ( V_45 > 0 )
V_45 = F_15 ( V_31 , V_32 , V_33 , V_44 , V_45 ) ;
F_26 ( V_44 ) ;
return V_45 ;
}
static T_2 F_28 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
struct V_39 * V_40 ;
T_2 V_45 ;
T_5 V_52 ;
char * V_44 ;
V_52 = * V_33 ;
if ( V_52 < 0 ) {
V_45 = - V_53 ;
goto V_10;
}
if ( V_52 >= sizeof( struct V_54 ) ) {
V_45 = 0 ;
goto V_10;
}
if ( V_32 > sizeof( struct V_54 ) - V_52 )
V_32 = sizeof( struct V_54 ) - V_52 ;
V_44 = F_24 ( V_32 , V_47 ) ;
if ( ! V_44 ) {
V_45 = - V_48 ;
goto V_10;
}
V_40 = F_18 ( V_30 ) ;
if ( F_29 ( V_40 , V_52 , V_44 , V_32 ) ) {
F_30 ( V_40 , L_1 ) ;
V_45 = - V_55 ;
goto V_56;
}
if ( F_31 ( V_31 , V_44 , V_32 ) ) {
V_45 = - V_57 ;
goto V_56;
}
* V_33 = V_52 + V_32 ;
V_45 = V_32 ;
V_56:
F_26 ( V_44 ) ;
V_10:
return V_45 ;
}
static T_2 F_32 ( struct V_30 * V_30 , const char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
struct V_39 * V_40 ;
T_2 V_45 ;
T_5 V_52 ;
char * V_44 ;
V_52 = * V_33 ;
if ( V_52 != 0 ) {
V_45 = - V_53 ;
goto V_10;
}
if ( V_32 != sizeof( struct V_54 ) ) {
V_45 = - V_53 ;
goto V_10;
}
V_44 = F_24 ( V_32 , V_47 ) ;
if ( ! V_44 ) {
V_45 = - V_48 ;
goto V_10;
}
if ( F_33 ( V_44 , V_31 , V_32 ) ) {
V_45 = - V_57 ;
goto V_56;
}
V_40 = F_18 ( V_30 ) ;
if ( F_34 ( V_40 , V_52 , V_44 , V_32 ) ) {
V_45 = - V_55 ;
F_30 ( V_40 , L_2 ) ;
goto V_56;
}
* V_33 = V_52 + V_32 ;
V_45 = V_32 ;
V_56:
F_26 ( V_44 ) ;
V_10:
return V_45 ;
}
static int F_35 ( struct V_58 * V_59 , struct V_39 * V_40 )
{
struct V_3 * V_2 , * V_44 ;
char V_60 [ 10 ] ;
int V_45 , V_61 ;
snprintf ( V_60 , sizeof V_60 , L_3 , V_40 -> V_60 ) ;
V_45 = F_7 ( V_60 , V_62 | V_63 | V_64 , V_59 -> V_65 , & V_2 ,
& V_66 , V_40 ) ;
if ( V_45 ) {
F_36 ( L_4 , V_60 , V_45 ) ;
goto V_10;
}
V_45 = F_7 ( L_5 , V_67 | V_63 , V_2 , & V_44 ,
& V_68 [ 0 ] , V_40 ) ;
if ( V_45 ) {
F_36 ( L_6 ,
V_60 , V_45 ) ;
goto V_10;
}
V_45 = F_7 ( L_7 , V_67 | V_63 , V_2 , & V_44 ,
& V_68 [ 1 ] , V_40 ) ;
if ( V_45 ) {
F_36 ( L_8 ,
V_60 , V_45 ) ;
goto V_10;
}
V_45 = F_7 ( L_9 , V_67 | V_63 , V_2 , & V_44 ,
& V_69 [ 0 ] , V_40 ) ;
if ( V_45 ) {
F_36 ( L_10 ,
V_60 , L_9 , V_45 ) ;
goto V_10;
}
for ( V_61 = 1 ; V_61 <= V_40 -> V_50 ; V_61 ++ ) {
char V_70 [ 24 ] ;
sprintf ( V_70 , L_11 , V_61 ) ;
V_45 = F_7 ( V_70 , V_67 | V_63 , V_2 , & V_44 ,
& V_69 [ V_61 ] , V_40 ) ;
if ( V_45 ) {
F_36 ( L_10 ,
V_60 , V_70 , V_45 ) ;
goto V_10;
}
if ( ! ( V_40 -> V_71 & V_72 ) )
continue;
sprintf ( V_70 , L_12 , V_61 ) ;
V_45 = F_7 ( V_70 , V_67 | V_63 , V_2 , & V_44 ,
& V_73 [ V_61 - 1 ] , V_40 ) ;
if ( V_45 ) {
F_36 ( L_10 ,
V_60 , V_70 , V_45 ) ;
goto V_10;
}
}
V_45 = F_7 ( L_13 , V_67 | V_74 | V_63 , V_2 , & V_44 ,
& V_75 , V_40 ) ;
if ( V_45 )
F_36 ( L_14 ,
V_60 , V_45 ) ;
V_10:
return V_45 ;
}
static int F_37 ( struct V_3 * V_27 , char * V_26 )
{
struct V_3 * V_44 ;
int V_45 ;
V_44 = F_9 ( V_26 , V_27 , strlen ( V_26 ) ) ;
if ( F_10 ( V_44 ) ) {
V_45 = F_11 ( V_44 ) ;
goto V_10;
}
F_38 ( & V_44 -> V_76 ) ;
if ( ! ( F_39 ( V_44 ) && V_44 -> V_28 ) ) {
F_40 ( V_44 ) ;
F_41 ( & V_44 -> V_76 ) ;
F_42 ( V_27 -> V_28 , V_44 ) ;
} else {
F_41 ( & V_44 -> V_76 ) ;
}
F_43 ( V_44 ) ;
V_45 = 0 ;
V_10:
return V_45 ;
}
static int F_44 ( struct V_58 * V_59 ,
struct V_39 * V_40 )
{
struct V_3 * V_2 , * V_77 ;
char V_60 [ 10 ] ;
int V_45 , V_61 ;
V_77 = F_45 ( V_59 -> V_65 ) ;
F_8 ( & V_77 -> V_28 -> V_29 ) ;
snprintf ( V_60 , sizeof V_60 , L_3 , V_40 -> V_60 ) ;
V_2 = F_9 ( V_60 , V_77 , strlen ( V_60 ) ) ;
if ( F_10 ( V_2 ) ) {
V_45 = F_11 ( V_2 ) ;
F_36 ( L_15 , V_60 ) ;
goto V_10;
}
F_8 ( & V_2 -> V_28 -> V_29 ) ;
F_37 ( V_2 , L_5 ) ;
F_37 ( V_2 , L_7 ) ;
F_37 ( V_2 , L_9 ) ;
for ( V_61 = 0 ; V_61 < V_40 -> V_50 ; V_61 ++ ) {
char V_70 [ 24 ] ;
sprintf ( V_70 , L_11 , V_61 + 1 ) ;
F_37 ( V_2 , V_70 ) ;
if ( V_40 -> V_71 & V_72 ) {
sprintf ( V_70 , L_12 , V_61 + 1 ) ;
F_37 ( V_2 , V_70 ) ;
}
}
F_37 ( V_2 , L_13 ) ;
F_12 ( & V_2 -> V_28 -> V_29 ) ;
V_45 = F_46 ( V_77 -> V_28 , V_2 ) ;
F_47 ( V_2 ) ;
F_43 ( V_2 ) ;
V_10:
F_12 ( & V_77 -> V_28 -> V_29 ) ;
F_43 ( V_77 ) ;
return V_45 ;
}
static int F_48 ( struct V_58 * V_59 , void * V_7 , int V_78 )
{
struct V_39 * V_40 , * V_44 ;
unsigned long V_71 ;
int V_45 ;
static struct V_79 V_80 [] = {
[ 2 ] = { L_16 , & V_81 [ 0 ] , V_63 } ,
[ 3 ] = { L_17 , & V_81 [ 1 ] , V_63 } ,
{ L_18 } ,
} ;
V_45 = F_49 ( V_59 , V_82 , V_80 ) ;
if ( V_45 ) {
F_36 ( L_19 , V_45 ) ;
goto V_10;
}
F_50 ( & V_83 , V_71 ) ;
F_51 (dd, tmp, &qib_dev_list, list) {
F_52 ( & V_83 , V_71 ) ;
V_45 = F_35 ( V_59 , V_40 ) ;
if ( V_45 )
goto V_10;
F_50 ( & V_83 , V_71 ) ;
}
F_52 ( & V_83 , V_71 ) ;
V_10:
return V_45 ;
}
static struct V_3 * F_53 ( struct V_84 * V_85 , int V_71 ,
const char * V_86 , void * V_7 )
{
struct V_3 * V_45 ;
V_45 = F_54 ( V_85 , V_71 , V_7 , F_48 ) ;
if ( ! F_10 ( V_45 ) )
V_87 = V_45 -> V_88 ;
return V_45 ;
}
static void F_55 ( struct V_58 * V_89 )
{
F_56 ( V_89 ) ;
V_87 = NULL ;
}
int F_57 ( struct V_39 * V_40 )
{
int V_45 ;
if ( V_87 == NULL )
V_45 = 0 ;
else
V_45 = F_35 ( V_87 , V_40 ) ;
return V_45 ;
}
int F_58 ( struct V_39 * V_40 )
{
int V_45 = 0 ;
if ( V_87 )
V_45 = F_44 ( V_87 , V_40 ) ;
return V_45 ;
}
int T_7 F_59 ( void )
{
return F_60 ( & V_90 ) ;
}
int T_8 F_61 ( void )
{
return F_62 ( & V_90 ) ;
}
