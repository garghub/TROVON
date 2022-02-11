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
V_1 -> V_13 = V_1 -> V_14 = V_1 -> V_15 = V_16 ;
V_1 -> V_17 = V_7 ;
if ( ( V_4 & V_18 ) == V_19 ) {
V_1 -> V_20 = & V_21 ;
F_4 ( V_1 ) ;
F_4 ( V_2 ) ;
}
V_1 -> V_22 = V_6 ;
F_5 ( V_3 , V_1 ) ;
error = 0 ;
V_10:
return error ;
}
static int F_6 ( const char * V_23 , T_1 V_4 ,
struct V_3 * V_24 , struct V_3 * * V_3 ,
const struct V_5 * V_6 , void * V_7 )
{
int error ;
* V_3 = NULL ;
F_7 ( & V_24 -> V_25 -> V_26 ) ;
* V_3 = F_8 ( V_23 , V_24 , strlen ( V_23 ) ) ;
if ( ! F_9 ( * V_3 ) )
error = F_1 ( V_24 -> V_25 , * V_3 ,
V_4 , V_6 , V_7 ) ;
else
error = F_10 ( V_3 ) ;
F_11 ( & V_24 -> V_25 -> V_26 ) ;
return error ;
}
static T_2 F_12 ( struct V_27 * V_27 , char T_3 * V_28 ,
T_4 V_29 , T_5 * V_30 )
{
return F_13 ( V_28 , V_29 , V_30 , & V_31 ,
sizeof V_31 ) ;
}
static T_2 F_14 ( struct V_27 * V_27 , char T_3 * V_28 ,
T_4 V_29 , T_5 * V_30 )
{
struct V_32 V_33 ;
struct V_34 * V_35 ;
V_35 = V_27 -> V_36 . V_3 -> V_25 -> V_17 ;
V_35 -> V_37 ( V_35 , & V_33 ) ;
return F_13 ( V_28 , V_29 , V_30 , & V_33 ,
sizeof V_33 ) ;
}
static T_2 F_15 ( struct V_27 * V_27 , char T_3 * V_28 ,
T_4 V_29 , T_5 * V_30 )
{
struct V_34 * V_35 ;
T_2 V_38 ;
T_5 V_39 ;
char * V_40 ;
V_39 = * V_30 ;
if ( V_39 < 0 ) {
V_38 = - V_41 ;
goto V_10;
}
if ( V_39 >= sizeof( struct V_42 ) ) {
V_38 = 0 ;
goto V_10;
}
if ( V_29 > sizeof( struct V_42 ) - V_39 )
V_29 = sizeof( struct V_42 ) - V_39 ;
V_40 = F_16 ( V_29 , V_43 ) ;
if ( ! V_40 ) {
V_38 = - V_44 ;
goto V_10;
}
V_35 = V_27 -> V_36 . V_3 -> V_25 -> V_17 ;
if ( F_17 ( V_35 , V_39 , V_40 , V_29 ) ) {
F_18 ( V_35 , L_1 ) ;
V_38 = - V_45 ;
goto V_46;
}
if ( F_19 ( V_28 , V_40 , V_29 ) ) {
V_38 = - V_47 ;
goto V_46;
}
* V_30 = V_39 + V_29 ;
V_38 = V_29 ;
V_46:
F_20 ( V_40 ) ;
V_10:
return V_38 ;
}
static T_2 F_21 ( struct V_27 * V_27 , const char T_3 * V_28 ,
T_4 V_29 , T_5 * V_30 )
{
struct V_34 * V_35 ;
T_2 V_38 ;
T_5 V_39 ;
char * V_40 ;
V_39 = * V_30 ;
if ( V_39 != 0 ) {
V_38 = - V_41 ;
goto V_10;
}
if ( V_29 != sizeof( struct V_42 ) ) {
V_38 = - V_41 ;
goto V_10;
}
V_40 = F_16 ( V_29 , V_43 ) ;
if ( ! V_40 ) {
V_38 = - V_44 ;
goto V_10;
}
if ( F_22 ( V_40 , V_28 , V_29 ) ) {
V_38 = - V_47 ;
goto V_46;
}
V_35 = V_27 -> V_36 . V_3 -> V_25 -> V_17 ;
if ( F_23 ( V_35 , V_39 , V_40 , V_29 ) ) {
V_38 = - V_45 ;
F_18 ( V_35 , L_2 ) ;
goto V_46;
}
* V_30 = V_39 + V_29 ;
V_38 = V_29 ;
V_46:
F_20 ( V_40 ) ;
V_10:
return V_38 ;
}
static int F_24 ( struct V_48 * V_49 ,
struct V_34 * V_35 )
{
struct V_3 * V_2 , * V_40 ;
char V_50 [ 10 ] ;
int V_38 ;
snprintf ( V_50 , sizeof V_50 , L_3 , V_35 -> V_51 ) ;
V_38 = F_6 ( V_50 , V_19 | V_52 | V_53 , V_49 -> V_54 , & V_2 ,
& V_55 , V_35 ) ;
if ( V_38 ) {
F_25 ( V_56 L_4 , V_50 , V_38 ) ;
goto V_10;
}
V_38 = F_6 ( L_5 , V_57 | V_52 , V_2 , & V_40 ,
& V_58 , V_35 ) ;
if ( V_38 ) {
F_25 ( V_56 L_6
L_7 , V_50 , V_38 ) ;
goto V_10;
}
V_38 = F_6 ( L_8 , V_57 | V_59 | V_52 , V_2 , & V_40 ,
& V_60 , V_35 ) ;
if ( V_38 ) {
F_25 ( V_56 L_9
L_7 , V_50 , V_38 ) ;
goto V_10;
}
V_10:
return V_38 ;
}
static int F_26 ( struct V_3 * V_24 , char * V_23 )
{
struct V_3 * V_40 ;
int V_38 ;
V_40 = F_8 ( V_23 , V_24 , strlen ( V_23 ) ) ;
if ( F_9 ( V_40 ) ) {
V_38 = F_10 ( V_40 ) ;
goto V_10;
}
F_27 ( & V_40 -> V_61 ) ;
if ( ! ( F_28 ( V_40 ) && V_40 -> V_25 ) ) {
F_29 ( V_40 ) ;
F_30 ( V_40 ) ;
F_31 ( & V_40 -> V_61 ) ;
F_32 ( V_24 -> V_25 , V_40 ) ;
} else
F_31 ( & V_40 -> V_61 ) ;
V_38 = 0 ;
V_10:
return V_38 ;
}
static int F_33 ( struct V_48 * V_49 ,
struct V_34 * V_35 )
{
struct V_3 * V_2 , * V_62 ;
char V_50 [ 10 ] ;
int V_38 ;
V_62 = F_34 ( V_49 -> V_54 ) ;
F_7 ( & V_62 -> V_25 -> V_26 ) ;
snprintf ( V_50 , sizeof V_50 , L_3 , V_35 -> V_51 ) ;
V_2 = F_8 ( V_50 , V_62 , strlen ( V_50 ) ) ;
if ( F_9 ( V_2 ) ) {
V_38 = F_10 ( V_2 ) ;
F_25 ( V_56 L_10 , V_50 ) ;
goto V_10;
}
F_26 ( V_2 , L_8 ) ;
F_26 ( V_2 , L_5 ) ;
F_35 ( V_2 ) ;
V_38 = F_36 ( V_62 -> V_25 , V_2 ) ;
V_10:
F_11 ( & V_62 -> V_25 -> V_26 ) ;
F_37 ( V_62 ) ;
return V_38 ;
}
static int F_38 ( struct V_48 * V_49 , void * V_7 ,
int V_63 )
{
struct V_34 * V_35 , * V_40 ;
unsigned long V_64 ;
int V_38 ;
static struct V_65 V_66 [] = {
[ 2 ] = { L_11 , & V_67 , V_52 } ,
{ L_12 } ,
} ;
V_38 = F_39 ( V_49 , V_68 , V_66 ) ;
if ( V_38 ) {
F_25 ( V_56 L_13 , V_38 ) ;
goto V_10;
}
F_40 ( & V_69 , V_64 ) ;
F_41 (dd, tmp, &ipath_dev_list, ipath_list) {
F_42 ( & V_69 , V_64 ) ;
V_38 = F_24 ( V_49 , V_35 ) ;
if ( V_38 )
goto V_10;
F_40 ( & V_69 , V_64 ) ;
}
F_42 ( & V_69 , V_64 ) ;
V_10:
return V_38 ;
}
static struct V_3 * F_43 ( struct V_70 * V_71 ,
int V_64 , const char * V_72 , void * V_7 )
{
struct V_3 * V_38 ;
V_38 = F_44 ( V_71 , V_64 , V_7 , F_38 ) ;
if ( ! F_9 ( V_38 ) )
V_73 = V_38 -> V_74 ;
return V_38 ;
}
static void F_45 ( struct V_48 * V_75 )
{
F_46 ( V_75 ) ;
V_73 = NULL ;
}
int F_47 ( struct V_34 * V_35 )
{
int V_38 ;
if ( V_73 == NULL ) {
V_38 = 0 ;
goto V_10;
}
V_38 = F_24 ( V_73 , V_35 ) ;
V_10:
return V_38 ;
}
int F_48 ( struct V_34 * V_35 )
{
int V_38 ;
if ( V_73 == NULL ) {
V_38 = 0 ;
goto V_10;
}
V_38 = F_33 ( V_73 , V_35 ) ;
V_10:
return V_38 ;
}
int T_6 F_49 ( void )
{
return F_50 ( & V_76 ) ;
}
void T_7 F_51 ( void )
{
F_52 ( & V_76 ) ;
}
