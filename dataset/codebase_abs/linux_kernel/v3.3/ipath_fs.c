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
V_1 -> V_13 = V_1 -> V_14 = V_1 -> V_15 = V_16 ;
V_1 -> V_17 = V_7 ;
if ( F_4 ( V_4 ) ) {
V_1 -> V_18 = & V_19 ;
F_5 ( V_1 ) ;
F_5 ( V_2 ) ;
}
V_1 -> V_20 = V_6 ;
F_6 ( V_3 , V_1 ) ;
error = 0 ;
V_10:
return error ;
}
static int F_7 ( const char * V_21 , T_1 V_4 ,
struct V_3 * V_22 , struct V_3 * * V_3 ,
const struct V_5 * V_6 , void * V_7 )
{
int error ;
* V_3 = NULL ;
F_8 ( & V_22 -> V_23 -> V_24 ) ;
* V_3 = F_9 ( V_21 , V_22 , strlen ( V_21 ) ) ;
if ( ! F_10 ( * V_3 ) )
error = F_1 ( V_22 -> V_23 , * V_3 ,
V_4 , V_6 , V_7 ) ;
else
error = F_11 ( * V_3 ) ;
F_12 ( & V_22 -> V_23 -> V_24 ) ;
return error ;
}
static T_2 F_13 ( struct V_25 * V_25 , char T_3 * V_26 ,
T_4 V_27 , T_5 * V_28 )
{
return F_14 ( V_26 , V_27 , V_28 , & V_29 ,
sizeof V_29 ) ;
}
static T_2 F_15 ( struct V_25 * V_25 , char T_3 * V_26 ,
T_4 V_27 , T_5 * V_28 )
{
struct V_30 V_31 ;
struct V_32 * V_33 ;
V_33 = V_25 -> V_34 . V_3 -> V_23 -> V_17 ;
V_33 -> V_35 ( V_33 , & V_31 ) ;
return F_14 ( V_26 , V_27 , V_28 , & V_31 ,
sizeof V_31 ) ;
}
static T_2 F_16 ( struct V_25 * V_25 , char T_3 * V_26 ,
T_4 V_27 , T_5 * V_28 )
{
struct V_32 * V_33 ;
T_2 V_36 ;
T_5 V_37 ;
char * V_38 ;
V_37 = * V_28 ;
if ( V_37 < 0 ) {
V_36 = - V_39 ;
goto V_10;
}
if ( V_37 >= sizeof( struct V_40 ) ) {
V_36 = 0 ;
goto V_10;
}
if ( V_27 > sizeof( struct V_40 ) - V_37 )
V_27 = sizeof( struct V_40 ) - V_37 ;
V_38 = F_17 ( V_27 , V_41 ) ;
if ( ! V_38 ) {
V_36 = - V_42 ;
goto V_10;
}
V_33 = V_25 -> V_34 . V_3 -> V_23 -> V_17 ;
if ( F_18 ( V_33 , V_37 , V_38 , V_27 ) ) {
F_19 ( V_33 , L_1 ) ;
V_36 = - V_43 ;
goto V_44;
}
if ( F_20 ( V_26 , V_38 , V_27 ) ) {
V_36 = - V_45 ;
goto V_44;
}
* V_28 = V_37 + V_27 ;
V_36 = V_27 ;
V_44:
F_21 ( V_38 ) ;
V_10:
return V_36 ;
}
static T_2 F_22 ( struct V_25 * V_25 , const char T_3 * V_26 ,
T_4 V_27 , T_5 * V_28 )
{
struct V_32 * V_33 ;
T_2 V_36 ;
T_5 V_37 ;
char * V_38 ;
V_37 = * V_28 ;
if ( V_37 != 0 ) {
V_36 = - V_39 ;
goto V_10;
}
if ( V_27 != sizeof( struct V_40 ) ) {
V_36 = - V_39 ;
goto V_10;
}
V_38 = F_17 ( V_27 , V_41 ) ;
if ( ! V_38 ) {
V_36 = - V_42 ;
goto V_10;
}
if ( F_23 ( V_38 , V_26 , V_27 ) ) {
V_36 = - V_45 ;
goto V_44;
}
V_33 = V_25 -> V_34 . V_3 -> V_23 -> V_17 ;
if ( F_24 ( V_33 , V_37 , V_38 , V_27 ) ) {
V_36 = - V_43 ;
F_19 ( V_33 , L_2 ) ;
goto V_44;
}
* V_28 = V_37 + V_27 ;
V_36 = V_27 ;
V_44:
F_21 ( V_38 ) ;
V_10:
return V_36 ;
}
static int F_25 ( struct V_46 * V_47 ,
struct V_32 * V_33 )
{
struct V_3 * V_2 , * V_38 ;
char V_48 [ 10 ] ;
int V_36 ;
snprintf ( V_48 , sizeof V_48 , L_3 , V_33 -> V_49 ) ;
V_36 = F_7 ( V_48 , V_50 | V_51 | V_52 , V_47 -> V_53 , & V_2 ,
& V_54 , V_33 ) ;
if ( V_36 ) {
F_26 ( V_55 L_4 , V_48 , V_36 ) ;
goto V_10;
}
V_36 = F_7 ( L_5 , V_56 | V_51 , V_2 , & V_38 ,
& V_57 , V_33 ) ;
if ( V_36 ) {
F_26 ( V_55 L_6
L_7 , V_48 , V_36 ) ;
goto V_10;
}
V_36 = F_7 ( L_8 , V_56 | V_58 | V_51 , V_2 , & V_38 ,
& V_59 , V_33 ) ;
if ( V_36 ) {
F_26 ( V_55 L_9
L_7 , V_48 , V_36 ) ;
goto V_10;
}
V_10:
return V_36 ;
}
static int F_27 ( struct V_3 * V_22 , char * V_21 )
{
struct V_3 * V_38 ;
int V_36 ;
V_38 = F_9 ( V_21 , V_22 , strlen ( V_21 ) ) ;
if ( F_10 ( V_38 ) ) {
V_36 = F_11 ( V_38 ) ;
goto V_10;
}
F_28 ( & V_38 -> V_60 ) ;
if ( ! ( F_29 ( V_38 ) && V_38 -> V_23 ) ) {
F_30 ( V_38 ) ;
F_31 ( V_38 ) ;
F_32 ( & V_38 -> V_60 ) ;
F_33 ( V_22 -> V_23 , V_38 ) ;
} else
F_32 ( & V_38 -> V_60 ) ;
V_36 = 0 ;
V_10:
return V_36 ;
}
static int F_34 ( struct V_46 * V_47 ,
struct V_32 * V_33 )
{
struct V_3 * V_2 , * V_61 ;
char V_48 [ 10 ] ;
int V_36 ;
V_61 = F_35 ( V_47 -> V_53 ) ;
F_8 ( & V_61 -> V_23 -> V_24 ) ;
snprintf ( V_48 , sizeof V_48 , L_3 , V_33 -> V_49 ) ;
V_2 = F_9 ( V_48 , V_61 , strlen ( V_48 ) ) ;
if ( F_10 ( V_2 ) ) {
V_36 = F_11 ( V_2 ) ;
F_26 ( V_55 L_10 , V_48 ) ;
goto V_10;
}
F_27 ( V_2 , L_8 ) ;
F_27 ( V_2 , L_5 ) ;
F_36 ( V_2 ) ;
V_36 = F_37 ( V_61 -> V_23 , V_2 ) ;
V_10:
F_12 ( & V_61 -> V_23 -> V_24 ) ;
F_38 ( V_61 ) ;
return V_36 ;
}
static int F_39 ( struct V_46 * V_47 , void * V_7 ,
int V_62 )
{
struct V_32 * V_33 , * V_38 ;
unsigned long V_63 ;
int V_36 ;
static struct V_64 V_65 [] = {
[ 2 ] = { L_11 , & V_66 , V_51 } ,
{ L_12 } ,
} ;
V_36 = F_40 ( V_47 , V_67 , V_65 ) ;
if ( V_36 ) {
F_26 ( V_55 L_13 , V_36 ) ;
goto V_10;
}
F_41 ( & V_68 , V_63 ) ;
F_42 (dd, tmp, &ipath_dev_list, ipath_list) {
F_43 ( & V_68 , V_63 ) ;
V_36 = F_25 ( V_47 , V_33 ) ;
if ( V_36 )
goto V_10;
F_41 ( & V_68 , V_63 ) ;
}
F_43 ( & V_68 , V_63 ) ;
V_10:
return V_36 ;
}
static struct V_3 * F_44 ( struct V_69 * V_70 ,
int V_63 , const char * V_71 , void * V_7 )
{
struct V_3 * V_36 ;
V_36 = F_45 ( V_70 , V_63 , V_7 , F_39 ) ;
if ( ! F_10 ( V_36 ) )
V_72 = V_36 -> V_73 ;
return V_36 ;
}
static void F_46 ( struct V_46 * V_74 )
{
F_47 ( V_74 ) ;
V_72 = NULL ;
}
int F_48 ( struct V_32 * V_33 )
{
int V_36 ;
if ( V_72 == NULL ) {
V_36 = 0 ;
goto V_10;
}
V_36 = F_25 ( V_72 , V_33 ) ;
V_10:
return V_36 ;
}
int F_49 ( struct V_32 * V_33 )
{
int V_36 ;
if ( V_72 == NULL ) {
V_36 = 0 ;
goto V_10;
}
V_36 = F_34 ( V_72 , V_33 ) ;
V_10:
return V_36 ;
}
int T_6 F_50 ( void )
{
return F_51 ( & V_75 ) ;
}
void T_7 F_52 ( void )
{
F_53 ( & V_75 ) ;
}
