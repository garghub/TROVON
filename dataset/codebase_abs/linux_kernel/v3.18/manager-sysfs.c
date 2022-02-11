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
enum V_27 V_28 ;
struct V_21 V_22 ;
int V_12 ;
for ( V_28 = V_31 ;
V_28 < F_17 ( V_30 ) ; V_28 ++ ) {
if ( F_4 ( V_3 , V_30 [ V_28 ] ) )
break;
}
if ( V_28 == F_17 ( V_30 ) )
return - V_15 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
V_22 . V_29 = V_28 ;
V_12 = V_2 -> V_26 ( V_2 , & V_22 ) ;
if ( V_12 )
return V_12 ;
V_12 = V_2 -> V_20 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_21 V_22 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
return snprintf ( V_3 , V_4 , L_10 , V_22 . V_32 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_11 )
{
struct V_21 V_22 ;
T_3 V_33 ;
int V_12 ;
V_12 = F_14 ( V_3 , 0 , & V_33 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
V_22 . V_32 = V_33 ;
V_12 = V_2 -> V_26 ( V_2 , & V_22 ) ;
if ( V_12 )
return V_12 ;
V_12 = V_2 -> V_20 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_21 V_22 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
return snprintf ( V_3 , V_4 , L_11 , V_22 . V_34 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_11 )
{
struct V_21 V_22 ;
bool V_35 ;
int V_12 ;
V_12 = F_23 ( V_3 , & V_35 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
V_22 . V_34 = V_35 ;
V_12 = V_2 -> V_26 ( V_2 , & V_22 ) ;
if ( V_12 )
return V_12 ;
V_12 = V_2 -> V_20 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_24 (
struct V_1 * V_2 , char * V_3 )
{
struct V_21 V_22 ;
if( ! F_25 ( V_36 ) )
return - V_37 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
return snprintf ( V_3 , V_4 , L_11 ,
V_22 . V_38 ) ;
}
static T_1 F_26 (
struct V_1 * V_2 ,
const char * V_3 , T_2 V_11 )
{
struct V_21 V_22 ;
bool V_35 ;
int V_12 ;
if( ! F_25 ( V_36 ) )
return - V_37 ;
V_12 = F_23 ( V_3 , & V_35 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
V_22 . V_38 = V_35 ;
V_12 = V_2 -> V_26 ( V_2 , & V_22 ) ;
if ( V_12 )
return V_12 ;
V_12 = V_2 -> V_20 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_21 V_22 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
return snprintf ( V_3 , V_4 , L_11 , V_22 . V_39 ) ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_11 )
{
struct V_21 V_22 ;
int V_12 ;
bool V_35 ;
if ( ! F_25 ( V_40 ) )
return - V_37 ;
V_12 = F_23 ( V_3 , & V_35 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
if ( V_22 . V_39 == V_35 )
return V_11 ;
V_22 . V_39 = V_35 ;
V_12 = V_2 -> V_26 ( V_2 , & V_22 ) ;
if ( V_12 )
return V_12 ;
V_12 = V_2 -> V_20 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_21 V_22 ;
V_2 -> V_23 ( V_2 , & V_22 ) ;
return snprintf ( V_3 , V_4 ,
L_12 ,
V_22 . V_41 . V_42 ,
V_22 . V_41 . V_43 ,
V_22 . V_41 . V_44 ,
V_22 . V_41 . V_45 ,
V_22 . V_41 . V_46 ,
V_22 . V_41 . V_47 ,
V_22 . V_41 . V_48 ,
V_22 . V_41 . V_49 ,
V_22 . V_41 . V_50 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_11 )
{
struct V_21 V_22 ;
struct V_51 V_52 ;
int V_12 , V_53 ;
T_4 * V_54 ;
if ( ! F_25 ( V_40 ) )
return - V_37 ;
if ( sscanf ( V_3 , L_13 ,
& V_52 . V_42 , & V_52 . V_43 , & V_52 . V_44 ,
& V_52 . V_45 , & V_52 . V_46 , & V_52 . V_47 ,
& V_52 . V_48 , & V_52 . V_49 , & V_52 . V_50 ) != 9 )
return - V_15 ;
V_54 = ( T_4 [] ) { V_52 . V_42 , V_52 . V_43 , V_52 . V_44 ,
V_52 . V_45 , V_52 . V_46 , V_52 . V_47 ,
V_52 . V_48 , V_52 . V_49 , V_52 . V_50 } ;
for ( V_53 = 0 ; V_53 < 9 ; ++ V_53 ) {
if ( V_54 [ V_53 ] < - 512 || V_54 [ V_53 ] > 511 )
return - V_15 ;
}
V_2 -> V_23 ( V_2 , & V_22 ) ;
V_22 . V_41 = V_52 ;
V_12 = V_2 -> V_26 ( V_2 , & V_22 ) ;
if ( V_12 )
return V_12 ;
V_12 = V_2 -> V_20 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return V_11 ;
}
static T_1 F_31 ( struct V_55 * V_56 , struct V_57 * V_58 ,
char * V_3 )
{
struct V_1 * V_59 ;
struct V_60 * V_61 ;
V_59 = F_32 ( V_56 , struct V_1 , V_56 ) ;
V_61 = F_32 ( V_58 , struct V_60 , V_58 ) ;
if ( ! V_61 -> V_62 )
return - V_63 ;
return V_61 -> V_62 ( V_59 , V_3 ) ;
}
static T_1 F_33 ( struct V_55 * V_56 , struct V_57 * V_58 ,
const char * V_3 , T_2 V_11 )
{
struct V_1 * V_59 ;
struct V_60 * V_61 ;
V_59 = F_32 ( V_56 , struct V_1 , V_56 ) ;
V_61 = F_32 ( V_58 , struct V_60 , V_58 ) ;
if ( ! V_61 -> V_64 )
return - V_63 ;
return V_61 -> V_64 ( V_59 , V_3 , V_11 ) ;
}
int F_34 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
return F_35 ( & V_2 -> V_56 , & V_67 ,
& V_66 -> V_68 . V_56 , L_14 , V_2 -> V_69 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_56 ) ;
F_38 ( & V_2 -> V_56 ) ;
memset ( & V_2 -> V_56 , 0 , sizeof( V_2 -> V_56 ) ) ;
}
