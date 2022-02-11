static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_1 , V_2 -> V_5 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 , char * V_3 )
{
struct V_6 * V_7 = V_2 -> V_8 ( V_2 ) ;
return snprintf ( V_3 , V_4 , L_1 , V_7 ?
V_7 -> V_5 : L_2 ) ;
}
static int F_3 ( struct V_6 * V_7 , void * V_9 )
{
const char * V_10 = V_9 ;
return F_4 ( V_7 -> V_5 , V_10 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_11 )
{
int V_12 = 0 ;
T_2 V_13 = V_11 ;
struct V_6 * V_7 = NULL ;
struct V_6 * V_14 ;
if ( V_3 [ V_11 - 1 ] == '\n' )
-- V_13 ;
if ( V_13 > 0 )
V_7 = F_6 ( ( void * ) V_3 ,
F_3 ) ;
if ( V_13 > 0 && V_7 == NULL )
return - V_15 ;
if ( V_7 ) {
F_7 ( L_3 , V_7 -> V_5 ) ;
if ( F_8 ( V_7 ) ) {
F_9 ( L_4 ) ;
V_12 = - V_15 ;
goto V_16;
}
if ( F_10 ( V_7 ) ) {
F_9 ( L_5 ) ;
V_12 = - V_15 ;
goto V_16;
}
}
V_14 = V_2 -> V_8 ( V_2 ) ;
if ( V_14 ) {
if ( F_10 ( V_14 ) ) {
F_9 ( L_6 ) ;
V_12 = - V_15 ;
goto V_16;
}
V_14 -> V_17 -> V_18 ( V_14 ) ;
}
if ( V_7 ) {
V_12 = V_7 -> V_17 -> V_19 ( V_7 ) ;
if ( V_12 ) {
F_9 ( L_7 ) ;
goto V_16;
}
V_14 = V_2 -> V_8 ( V_2 ) ;
if ( V_14 != V_7 ) {
F_9 ( L_8 ) ;
V_7 -> V_17 -> V_18 ( V_7 ) ;
goto V_16;
}
V_12 = V_2 -> V_20 ( V_2 ) ;
if ( V_12 ) {
F_9 ( L_9 ) ;
goto V_16;
}
}
V_16:
if ( V_7 )
F_11 ( V_7 ) ;
return V_12 ? V_12 : V_11 ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_21 V_22 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
return snprintf ( V_3 , V_4 , L_10 , V_22 . V_24 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_11 )
{
struct V_21 V_22 ;
T_3 V_25 ;
int V_12 ;
V_12 = F_14 ( V_3 , 0 , & V_25 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
V_22 . V_24 = V_25 ;
V_12 = V_2 -> V_26 ( V_2 , & V_22 ) ;
if ( V_12 )
return V_12 ;
V_12 = V_2 -> V_20 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
char * V_3 )
{
enum V_27 V_28 ;
struct V_21 V_22 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
V_28 = V_22 . V_29 ;
F_16 ( V_28 >= F_17 ( V_30 ) ) ;
return snprintf ( V_3 , V_4 , L_1 , V_30 [ V_28 ] ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_11 )
{
struct V_21 V_22 ;
int V_12 ;
V_12 = F_19 ( V_30 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
V_22 . V_29 = V_12 ;
V_12 = V_2 -> V_26 ( V_2 , & V_22 ) ;
if ( V_12 )
return V_12 ;
V_12 = V_2 -> V_20 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_21 V_22 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
return snprintf ( V_3 , V_4 , L_10 , V_22 . V_31 ) ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_11 )
{
struct V_21 V_22 ;
T_3 V_32 ;
int V_12 ;
V_12 = F_14 ( V_3 , 0 , & V_32 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
V_22 . V_31 = V_32 ;
V_12 = V_2 -> V_26 ( V_2 , & V_22 ) ;
if ( V_12 )
return V_12 ;
V_12 = V_2 -> V_20 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_21 V_22 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
return snprintf ( V_3 , V_4 , L_11 , V_22 . V_33 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_11 )
{
struct V_21 V_22 ;
bool V_34 ;
int V_12 ;
V_12 = F_24 ( V_3 , & V_34 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
V_22 . V_33 = V_34 ;
V_12 = V_2 -> V_26 ( V_2 , & V_22 ) ;
if ( V_12 )
return V_12 ;
V_12 = V_2 -> V_20 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_25 (
struct V_1 * V_2 , char * V_3 )
{
struct V_21 V_22 ;
if( ! F_26 ( V_35 ) )
return - V_36 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
return snprintf ( V_3 , V_4 , L_11 ,
V_22 . V_37 ) ;
}
static T_1 F_27 (
struct V_1 * V_2 ,
const char * V_3 , T_2 V_11 )
{
struct V_21 V_22 ;
bool V_34 ;
int V_12 ;
if( ! F_26 ( V_35 ) )
return - V_36 ;
V_12 = F_24 ( V_3 , & V_34 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
V_22 . V_37 = V_34 ;
V_12 = V_2 -> V_26 ( V_2 , & V_22 ) ;
if ( V_12 )
return V_12 ;
V_12 = V_2 -> V_20 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_21 V_22 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
return snprintf ( V_3 , V_4 , L_11 , V_22 . V_38 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_11 )
{
struct V_21 V_22 ;
int V_12 ;
bool V_34 ;
if ( ! F_26 ( V_39 ) )
return - V_36 ;
V_12 = F_24 ( V_3 , & V_34 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
if ( V_22 . V_38 == V_34 )
return V_11 ;
V_22 . V_38 = V_34 ;
V_12 = V_2 -> V_26 ( V_2 , & V_22 ) ;
if ( V_12 )
return V_12 ;
V_12 = V_2 -> V_20 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_21 V_22 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
return snprintf ( V_3 , V_4 ,
L_12 ,
V_22 . V_40 . V_41 ,
V_22 . V_40 . V_42 ,
V_22 . V_40 . V_43 ,
V_22 . V_40 . V_44 ,
V_22 . V_40 . V_45 ,
V_22 . V_40 . V_46 ,
V_22 . V_40 . V_47 ,
V_22 . V_40 . V_48 ,
V_22 . V_40 . V_49 ) ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_11 )
{
struct V_21 V_22 ;
struct V_50 V_51 ;
int V_12 , V_52 ;
T_4 * V_53 ;
if ( ! F_26 ( V_39 ) )
return - V_36 ;
if ( sscanf ( V_3 , L_13 ,
& V_51 . V_41 , & V_51 . V_42 , & V_51 . V_43 ,
& V_51 . V_44 , & V_51 . V_45 , & V_51 . V_46 ,
& V_51 . V_47 , & V_51 . V_48 , & V_51 . V_49 ) != 9 )
return - V_15 ;
V_53 = ( T_4 [] ) { V_51 . V_41 , V_51 . V_42 , V_51 . V_43 ,
V_51 . V_44 , V_51 . V_45 , V_51 . V_46 ,
V_51 . V_47 , V_51 . V_48 , V_51 . V_49 } ;
for ( V_52 = 0 ; V_52 < 9 ; ++ V_52 ) {
if ( V_53 [ V_52 ] < - 512 || V_53 [ V_52 ] > 511 )
return - V_15 ;
}
V_2 -> V_23 ( V_2 , & V_22 ) ;
V_22 . V_40 = V_51 ;
V_12 = V_2 -> V_26 ( V_2 , & V_22 ) ;
if ( V_12 )
return V_12 ;
V_12 = V_2 -> V_20 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_32 ( struct V_54 * V_55 , struct V_56 * V_57 ,
char * V_3 )
{
struct V_1 * V_58 ;
struct V_59 * V_60 ;
V_58 = F_33 ( V_55 , struct V_1 , V_55 ) ;
V_60 = F_33 ( V_57 , struct V_59 , V_57 ) ;
if ( ! V_60 -> V_61 )
return - V_62 ;
return V_60 -> V_61 ( V_58 , V_3 ) ;
}
static T_1 F_34 ( struct V_54 * V_55 , struct V_56 * V_57 ,
const char * V_3 , T_2 V_11 )
{
struct V_1 * V_58 ;
struct V_59 * V_60 ;
V_58 = F_33 ( V_55 , struct V_1 , V_55 ) ;
V_60 = F_33 ( V_57 , struct V_59 , V_57 ) ;
if ( ! V_60 -> V_63 )
return - V_62 ;
return V_60 -> V_63 ( V_58 , V_3 , V_11 ) ;
}
int F_35 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
return F_36 ( & V_2 -> V_55 , & V_66 ,
& V_65 -> V_67 . V_55 , L_14 , V_2 -> V_68 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_55 ) ;
F_39 ( & V_2 -> V_55 ) ;
memset ( & V_2 -> V_55 , 0 , sizeof( V_2 -> V_55 ) ) ;
}
