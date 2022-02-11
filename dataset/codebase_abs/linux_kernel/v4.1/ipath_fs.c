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
F_8 ( & F_9 ( V_22 ) -> V_23 ) ;
* V_3 = F_10 ( V_21 , V_22 , strlen ( V_21 ) ) ;
if ( ! F_11 ( * V_3 ) )
error = F_1 ( F_9 ( V_22 ) , * V_3 ,
V_4 , V_6 , V_7 ) ;
else
error = F_12 ( * V_3 ) ;
F_13 ( & F_9 ( V_22 ) -> V_23 ) ;
return error ;
}
static T_2 F_14 ( struct V_24 * V_24 , char T_3 * V_25 ,
T_4 V_26 , T_5 * V_27 )
{
return F_15 ( V_25 , V_26 , V_27 , & V_28 ,
sizeof V_28 ) ;
}
static T_2 F_16 ( struct V_24 * V_24 , char T_3 * V_25 ,
T_4 V_26 , T_5 * V_27 )
{
struct V_29 V_30 ;
struct V_31 * V_32 ;
V_32 = F_17 ( V_24 ) -> V_17 ;
V_32 -> V_33 ( V_32 , & V_30 ) ;
return F_15 ( V_25 , V_26 , V_27 , & V_30 ,
sizeof V_30 ) ;
}
static T_2 F_18 ( struct V_24 * V_24 , char T_3 * V_25 ,
T_4 V_26 , T_5 * V_27 )
{
struct V_31 * V_32 ;
T_2 V_34 ;
T_5 V_35 ;
char * V_36 ;
V_35 = * V_27 ;
if ( V_35 < 0 ) {
V_34 = - V_37 ;
goto V_10;
}
if ( V_35 >= sizeof( struct V_38 ) ) {
V_34 = 0 ;
goto V_10;
}
if ( V_26 > sizeof( struct V_38 ) - V_35 )
V_26 = sizeof( struct V_38 ) - V_35 ;
V_36 = F_19 ( V_26 , V_39 ) ;
if ( ! V_36 ) {
V_34 = - V_40 ;
goto V_10;
}
V_32 = F_17 ( V_24 ) -> V_17 ;
if ( F_20 ( V_32 , V_35 , V_36 , V_26 ) ) {
F_21 ( V_32 , L_1 ) ;
V_34 = - V_41 ;
goto V_42;
}
if ( F_22 ( V_25 , V_36 , V_26 ) ) {
V_34 = - V_43 ;
goto V_42;
}
* V_27 = V_35 + V_26 ;
V_34 = V_26 ;
V_42:
F_23 ( V_36 ) ;
V_10:
return V_34 ;
}
static T_2 F_24 ( struct V_24 * V_24 , const char T_3 * V_25 ,
T_4 V_26 , T_5 * V_27 )
{
struct V_31 * V_32 ;
T_2 V_34 ;
T_5 V_35 ;
char * V_36 ;
V_35 = * V_27 ;
if ( V_35 != 0 ) {
V_34 = - V_37 ;
goto V_10;
}
if ( V_26 != sizeof( struct V_38 ) ) {
V_34 = - V_37 ;
goto V_10;
}
V_36 = F_19 ( V_26 , V_39 ) ;
if ( ! V_36 ) {
V_34 = - V_40 ;
goto V_10;
}
if ( F_25 ( V_36 , V_25 , V_26 ) ) {
V_34 = - V_43 ;
goto V_42;
}
V_32 = F_17 ( V_24 ) -> V_17 ;
if ( F_26 ( V_32 , V_35 , V_36 , V_26 ) ) {
V_34 = - V_41 ;
F_21 ( V_32 , L_2 ) ;
goto V_42;
}
* V_27 = V_35 + V_26 ;
V_34 = V_26 ;
V_42:
F_23 ( V_36 ) ;
V_10:
return V_34 ;
}
static int F_27 ( struct V_44 * V_45 ,
struct V_31 * V_32 )
{
struct V_3 * V_2 , * V_36 ;
char V_46 [ 10 ] ;
int V_34 ;
snprintf ( V_46 , sizeof V_46 , L_3 , V_32 -> V_47 ) ;
V_34 = F_7 ( V_46 , V_48 | V_49 | V_50 , V_45 -> V_51 , & V_2 ,
& V_52 , V_32 ) ;
if ( V_34 ) {
F_28 ( V_53 L_4 , V_46 , V_34 ) ;
goto V_10;
}
V_34 = F_7 ( L_5 , V_54 | V_49 , V_2 , & V_36 ,
& V_55 , V_32 ) ;
if ( V_34 ) {
F_28 ( V_53 L_6
L_7 , V_46 , V_34 ) ;
goto V_10;
}
V_34 = F_7 ( L_8 , V_54 | V_56 | V_49 , V_2 , & V_36 ,
& V_57 , V_32 ) ;
if ( V_34 ) {
F_28 ( V_53 L_9
L_7 , V_46 , V_34 ) ;
goto V_10;
}
V_10:
return V_34 ;
}
static int F_29 ( struct V_3 * V_22 , char * V_21 )
{
struct V_3 * V_36 ;
int V_34 ;
V_36 = F_10 ( V_21 , V_22 , strlen ( V_21 ) ) ;
if ( F_11 ( V_36 ) ) {
V_34 = F_12 ( V_36 ) ;
goto V_10;
}
F_30 ( & V_36 -> V_58 ) ;
if ( ! F_31 ( V_36 ) && F_32 ( V_36 ) ) {
F_33 ( V_36 ) ;
F_34 ( V_36 ) ;
F_35 ( & V_36 -> V_58 ) ;
F_36 ( F_9 ( V_22 ) , V_36 ) ;
} else
F_35 ( & V_36 -> V_58 ) ;
V_34 = 0 ;
V_10:
return V_34 ;
}
static int F_37 ( struct V_44 * V_45 ,
struct V_31 * V_32 )
{
struct V_3 * V_2 , * V_59 ;
char V_46 [ 10 ] ;
int V_34 ;
V_59 = F_38 ( V_45 -> V_51 ) ;
F_8 ( & F_9 ( V_59 ) -> V_23 ) ;
snprintf ( V_46 , sizeof V_46 , L_3 , V_32 -> V_47 ) ;
V_2 = F_10 ( V_46 , V_59 , strlen ( V_46 ) ) ;
if ( F_11 ( V_2 ) ) {
V_34 = F_12 ( V_2 ) ;
F_28 ( V_53 L_10 , V_46 ) ;
goto V_10;
}
F_29 ( V_2 , L_8 ) ;
F_29 ( V_2 , L_5 ) ;
F_39 ( V_2 ) ;
V_34 = F_40 ( F_9 ( V_59 ) , V_2 ) ;
V_10:
F_13 ( & F_9 ( V_59 ) -> V_23 ) ;
F_41 ( V_59 ) ;
return V_34 ;
}
static int F_42 ( struct V_44 * V_45 , void * V_7 ,
int V_60 )
{
struct V_31 * V_32 , * V_36 ;
unsigned long V_61 ;
int V_34 ;
static struct V_62 V_63 [] = {
[ 2 ] = { L_11 , & V_64 , V_49 } ,
{ L_12 } ,
} ;
V_34 = F_43 ( V_45 , V_65 , V_63 ) ;
if ( V_34 ) {
F_28 ( V_53 L_13 , V_34 ) ;
goto V_10;
}
F_44 ( & V_66 , V_61 ) ;
F_45 (dd, tmp, &ipath_dev_list, ipath_list) {
F_46 ( & V_66 , V_61 ) ;
V_34 = F_27 ( V_45 , V_32 ) ;
if ( V_34 )
goto V_10;
F_44 ( & V_66 , V_61 ) ;
}
F_46 ( & V_66 , V_61 ) ;
V_10:
return V_34 ;
}
static struct V_3 * F_47 ( struct V_67 * V_68 ,
int V_61 , const char * V_69 , void * V_7 )
{
struct V_3 * V_34 ;
V_34 = F_48 ( V_68 , V_61 , V_7 , F_42 ) ;
if ( ! F_11 ( V_34 ) )
V_70 = V_34 -> V_71 ;
return V_34 ;
}
static void F_49 ( struct V_44 * V_72 )
{
F_50 ( V_72 ) ;
V_70 = NULL ;
}
int F_51 ( struct V_31 * V_32 )
{
int V_34 ;
if ( V_70 == NULL ) {
V_34 = 0 ;
goto V_10;
}
V_34 = F_27 ( V_70 , V_32 ) ;
V_10:
return V_34 ;
}
int F_52 ( struct V_31 * V_32 )
{
int V_34 ;
if ( V_70 == NULL ) {
V_34 = 0 ;
goto V_10;
}
V_34 = F_37 ( V_70 , V_32 ) ;
V_10:
return V_34 ;
}
int T_6 F_53 ( void )
{
return F_54 ( & V_73 ) ;
}
void T_7 F_55 ( void )
{
F_56 ( & V_73 ) ;
}
