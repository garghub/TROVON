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
V_33 = F_16 ( V_25 ) -> V_17 ;
V_33 -> V_34 ( V_33 , & V_31 ) ;
return F_14 ( V_26 , V_27 , V_28 , & V_31 ,
sizeof V_31 ) ;
}
static T_2 F_17 ( struct V_25 * V_25 , char T_3 * V_26 ,
T_4 V_27 , T_5 * V_28 )
{
struct V_32 * V_33 ;
T_2 V_35 ;
T_5 V_36 ;
char * V_37 ;
V_36 = * V_28 ;
if ( V_36 < 0 ) {
V_35 = - V_38 ;
goto V_10;
}
if ( V_36 >= sizeof( struct V_39 ) ) {
V_35 = 0 ;
goto V_10;
}
if ( V_27 > sizeof( struct V_39 ) - V_36 )
V_27 = sizeof( struct V_39 ) - V_36 ;
V_37 = F_18 ( V_27 , V_40 ) ;
if ( ! V_37 ) {
V_35 = - V_41 ;
goto V_10;
}
V_33 = F_16 ( V_25 ) -> V_17 ;
if ( F_19 ( V_33 , V_36 , V_37 , V_27 ) ) {
F_20 ( V_33 , L_1 ) ;
V_35 = - V_42 ;
goto V_43;
}
if ( F_21 ( V_26 , V_37 , V_27 ) ) {
V_35 = - V_44 ;
goto V_43;
}
* V_28 = V_36 + V_27 ;
V_35 = V_27 ;
V_43:
F_22 ( V_37 ) ;
V_10:
return V_35 ;
}
static T_2 F_23 ( struct V_25 * V_25 , const char T_3 * V_26 ,
T_4 V_27 , T_5 * V_28 )
{
struct V_32 * V_33 ;
T_2 V_35 ;
T_5 V_36 ;
char * V_37 ;
V_36 = * V_28 ;
if ( V_36 != 0 ) {
V_35 = - V_38 ;
goto V_10;
}
if ( V_27 != sizeof( struct V_39 ) ) {
V_35 = - V_38 ;
goto V_10;
}
V_37 = F_18 ( V_27 , V_40 ) ;
if ( ! V_37 ) {
V_35 = - V_41 ;
goto V_10;
}
if ( F_24 ( V_37 , V_26 , V_27 ) ) {
V_35 = - V_44 ;
goto V_43;
}
V_33 = F_16 ( V_25 ) -> V_17 ;
if ( F_25 ( V_33 , V_36 , V_37 , V_27 ) ) {
V_35 = - V_42 ;
F_20 ( V_33 , L_2 ) ;
goto V_43;
}
* V_28 = V_36 + V_27 ;
V_35 = V_27 ;
V_43:
F_22 ( V_37 ) ;
V_10:
return V_35 ;
}
static int F_26 ( struct V_45 * V_46 ,
struct V_32 * V_33 )
{
struct V_3 * V_2 , * V_37 ;
char V_47 [ 10 ] ;
int V_35 ;
snprintf ( V_47 , sizeof V_47 , L_3 , V_33 -> V_48 ) ;
V_35 = F_7 ( V_47 , V_49 | V_50 | V_51 , V_46 -> V_52 , & V_2 ,
& V_53 , V_33 ) ;
if ( V_35 ) {
F_27 ( V_54 L_4 , V_47 , V_35 ) ;
goto V_10;
}
V_35 = F_7 ( L_5 , V_55 | V_50 , V_2 , & V_37 ,
& V_56 , V_33 ) ;
if ( V_35 ) {
F_27 ( V_54 L_6
L_7 , V_47 , V_35 ) ;
goto V_10;
}
V_35 = F_7 ( L_8 , V_55 | V_57 | V_50 , V_2 , & V_37 ,
& V_58 , V_33 ) ;
if ( V_35 ) {
F_27 ( V_54 L_9
L_7 , V_47 , V_35 ) ;
goto V_10;
}
V_10:
return V_35 ;
}
static int F_28 ( struct V_3 * V_22 , char * V_21 )
{
struct V_3 * V_37 ;
int V_35 ;
V_37 = F_9 ( V_21 , V_22 , strlen ( V_21 ) ) ;
if ( F_10 ( V_37 ) ) {
V_35 = F_11 ( V_37 ) ;
goto V_10;
}
F_29 ( & V_37 -> V_59 ) ;
if ( ! ( F_30 ( V_37 ) && V_37 -> V_23 ) ) {
F_31 ( V_37 ) ;
F_32 ( V_37 ) ;
F_33 ( & V_37 -> V_59 ) ;
F_34 ( V_22 -> V_23 , V_37 ) ;
} else
F_33 ( & V_37 -> V_59 ) ;
V_35 = 0 ;
V_10:
return V_35 ;
}
static int F_35 ( struct V_45 * V_46 ,
struct V_32 * V_33 )
{
struct V_3 * V_2 , * V_60 ;
char V_47 [ 10 ] ;
int V_35 ;
V_60 = F_36 ( V_46 -> V_52 ) ;
F_8 ( & V_60 -> V_23 -> V_24 ) ;
snprintf ( V_47 , sizeof V_47 , L_3 , V_33 -> V_48 ) ;
V_2 = F_9 ( V_47 , V_60 , strlen ( V_47 ) ) ;
if ( F_10 ( V_2 ) ) {
V_35 = F_11 ( V_2 ) ;
F_27 ( V_54 L_10 , V_47 ) ;
goto V_10;
}
F_28 ( V_2 , L_8 ) ;
F_28 ( V_2 , L_5 ) ;
F_37 ( V_2 ) ;
V_35 = F_38 ( V_60 -> V_23 , V_2 ) ;
V_10:
F_12 ( & V_60 -> V_23 -> V_24 ) ;
F_39 ( V_60 ) ;
return V_35 ;
}
static int F_40 ( struct V_45 * V_46 , void * V_7 ,
int V_61 )
{
struct V_32 * V_33 , * V_37 ;
unsigned long V_62 ;
int V_35 ;
static struct V_63 V_64 [] = {
[ 2 ] = { L_11 , & V_65 , V_50 } ,
{ L_12 } ,
} ;
V_35 = F_41 ( V_46 , V_66 , V_64 ) ;
if ( V_35 ) {
F_27 ( V_54 L_13 , V_35 ) ;
goto V_10;
}
F_42 ( & V_67 , V_62 ) ;
F_43 (dd, tmp, &ipath_dev_list, ipath_list) {
F_44 ( & V_67 , V_62 ) ;
V_35 = F_26 ( V_46 , V_33 ) ;
if ( V_35 )
goto V_10;
F_42 ( & V_67 , V_62 ) ;
}
F_44 ( & V_67 , V_62 ) ;
V_10:
return V_35 ;
}
static struct V_3 * F_45 ( struct V_68 * V_69 ,
int V_62 , const char * V_70 , void * V_7 )
{
struct V_3 * V_35 ;
V_35 = F_46 ( V_69 , V_62 , V_7 , F_40 ) ;
if ( ! F_10 ( V_35 ) )
V_71 = V_35 -> V_72 ;
return V_35 ;
}
static void F_47 ( struct V_45 * V_73 )
{
F_48 ( V_73 ) ;
V_71 = NULL ;
}
int F_49 ( struct V_32 * V_33 )
{
int V_35 ;
if ( V_71 == NULL ) {
V_35 = 0 ;
goto V_10;
}
V_35 = F_26 ( V_71 , V_33 ) ;
V_10:
return V_35 ;
}
int F_50 ( struct V_32 * V_33 )
{
int V_35 ;
if ( V_71 == NULL ) {
V_35 = 0 ;
goto V_10;
}
V_35 = F_35 ( V_71 , V_33 ) ;
V_10:
return V_35 ;
}
int T_6 F_51 ( void )
{
return F_52 ( & V_74 ) ;
}
void T_7 F_53 ( void )
{
F_54 ( & V_74 ) ;
}
