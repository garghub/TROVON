static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
return F_2 ( F_3 ( V_2 ) , V_5 , 256 ) ;
}
static int F_4 ( struct V_6 * V_7 , struct V_8 * * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 -> V_10 -> V_10 ) ;
int V_11 ;
T_1 V_12 ;
V_12 = F_6 ( V_7 -> V_13 , 16 , & V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_9 = F_3 ( V_2 ) ;
return V_11 ;
}
static T_1 F_7 ( struct V_6 * V_7 , struct V_14 * V_4 ,
char * V_5 )
{
struct V_15 * V_16 =
F_8 ( V_4 , struct V_15 , V_4 ) ;
struct V_8 * V_17 ;
int V_11 ;
if ( ! V_16 -> V_18 )
return - V_19 ;
V_11 = F_4 ( V_7 , & V_17 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_16 -> V_18 ( V_17 , V_11 , V_16 , V_5 ) ;
}
static T_1 F_9 ( struct V_6 * V_7 , struct V_14 * V_4 ,
const char * V_5 , T_2 V_20 )
{
struct V_15 * V_16 =
F_8 ( V_4 , struct V_15 , V_4 ) ;
struct V_8 * V_17 ;
int V_11 ;
if ( ! V_16 -> V_21 )
return - V_19 ;
V_11 = F_4 ( V_7 , & V_17 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_16 -> V_21 ( V_17 , V_11 , V_16 , V_5 , V_20 ) ;
}
static void F_10 ( struct V_6 * V_7 )
{
F_11 ( V_7 ) ;
}
static T_1 F_12 ( struct V_8 * V_17 , T_3 V_11 ,
struct V_15 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 , F_13 ( V_17 , V_11 ) ) ;
}
static T_1 F_14 ( struct V_8 * V_17 , T_3 V_11 ,
struct V_15 * V_4 , char * V_5 )
{
if ( F_15 ( F_13 ( V_17 , V_11 ) ) != V_22 )
return 0 ;
return sprintf ( V_5 , L_1 ,
F_16 ( V_17 , V_11 , V_23 ) ) ;
}
static T_1 F_17 ( struct V_8 * V_17 , T_3 V_11 ,
struct V_15 * V_4 , char * V_5 )
{
unsigned int V_24 ;
if ( F_15 ( F_13 ( V_17 , V_11 ) ) != V_22 )
return 0 ;
if ( F_18 ( V_17 , V_11 , V_25 , 0 , & V_24 ) )
return 0 ;
return sprintf ( V_5 , L_1 , V_24 ) ;
}
static bool F_19 ( struct V_8 * V_17 , T_3 V_11 )
{
if ( V_11 == V_17 -> V_26 || V_11 == V_17 -> V_27 )
return true ;
switch ( F_15 ( F_13 ( V_17 , V_11 ) ) ) {
case V_28 :
case V_29 :
return true ;
default:
return false ;
}
}
static T_1 F_20 ( struct V_8 * V_17 , T_3 V_11 ,
struct V_15 * V_4 , char * V_5 )
{
if ( ! F_19 ( V_17 , V_11 ) )
return 0 ;
return sprintf ( V_5 , L_1 ,
F_16 ( V_17 , V_11 , V_30 ) ) ;
}
static T_1 F_21 ( struct V_8 * V_17 , T_3 V_11 ,
struct V_15 * V_4 , char * V_5 )
{
if ( ! F_19 ( V_17 , V_11 ) )
return 0 ;
return sprintf ( V_5 , L_1 ,
F_16 ( V_17 , V_11 , V_31 ) ) ;
}
static T_1 F_22 ( struct V_8 * V_17 , T_3 V_11 ,
struct V_15 * V_4 , char * V_5 )
{
if ( V_11 != V_17 -> V_26 && ! ( F_13 ( V_17 , V_11 ) & V_32 ) )
return 0 ;
return sprintf ( V_5 , L_1 ,
F_16 ( V_17 , V_11 , V_33 ) ) ;
}
static T_1 F_23 ( struct V_8 * V_17 , T_3 V_11 ,
struct V_15 * V_4 , char * V_5 )
{
if ( V_11 != V_17 -> V_26 && ! ( F_13 ( V_17 , V_11 ) & V_34 ) )
return 0 ;
return sprintf ( V_5 , L_1 ,
F_16 ( V_17 , V_11 , V_35 ) ) ;
}
static T_1 F_24 ( struct V_8 * V_17 , T_3 V_11 ,
struct V_15 * V_4 , char * V_5 )
{
if ( V_11 != V_17 -> V_26 && ! ( F_13 ( V_17 , V_11 ) & V_36 ) )
return 0 ;
return sprintf ( V_5 , L_1 ,
F_16 ( V_17 , V_11 , V_37 ) ) ;
}
static T_1 F_25 ( struct V_8 * V_17 , T_3 V_11 ,
struct V_15 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 ,
F_16 ( V_17 , V_11 , V_38 ) ) ;
}
static T_1 F_26 ( struct V_8 * V_17 , T_3 V_11 ,
struct V_15 * V_4 , char * V_5 )
{
T_3 V_39 [ 32 ] ;
int V_40 , V_41 ;
T_1 V_12 = 0 ;
V_41 = F_27 ( V_17 , V_11 , V_39 , F_28 ( V_39 ) ) ;
if ( V_41 <= 0 )
return V_41 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ )
V_12 += sprintf ( V_5 + V_12 , L_2 , V_40 ? L_3 : L_4 , V_39 [ V_40 ] ) ;
V_12 += sprintf ( V_5 + V_12 , L_5 ) ;
return V_12 ;
}
static void F_29 ( struct V_6 * V_7 ,
const struct V_42 * V_43 )
{
if ( V_7 ) {
F_30 ( V_7 , V_43 ) ;
F_31 ( V_7 ) ;
}
}
static void F_32 ( struct V_8 * V_17 )
{
struct V_44 * V_45 = V_17 -> V_46 ;
struct V_6 * * V_47 ;
if ( ! V_45 )
return;
F_29 ( V_45 -> V_26 , & V_48 ) ;
if ( V_45 -> V_49 ) {
for ( V_47 = V_45 -> V_49 ; * V_47 ; V_47 ++ )
F_29 ( * V_47 , & V_50 ) ;
F_11 ( V_45 -> V_49 ) ;
}
F_31 ( V_45 -> V_51 ) ;
F_11 ( V_45 ) ;
V_17 -> V_46 = NULL ;
}
static int F_33 ( struct V_6 * V_10 , T_3 V_11 ,
const struct V_42 * V_43 ,
struct V_6 * * V_52 )
{
struct V_6 * V_7 = F_34 ( sizeof( * V_7 ) , V_53 ) ;
int V_54 ;
if ( ! V_7 )
return - V_55 ;
F_35 ( V_7 , & V_56 ) ;
V_54 = F_36 ( V_7 , V_10 , L_6 , V_11 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_37 ( V_7 , V_43 ) ;
if ( V_54 < 0 ) {
F_31 ( V_7 ) ;
return V_54 ;
}
* V_52 = V_7 ;
return 0 ;
}
static int F_38 ( struct V_8 * V_17 )
{
struct V_44 * V_45 ;
int V_40 , V_54 ;
T_3 V_11 ;
V_45 = V_17 -> V_46 = F_34 ( sizeof( * V_45 ) , V_53 ) ;
if ( ! V_45 )
return - V_55 ;
V_45 -> V_51 = F_39 ( L_7 , & V_17 -> V_2 . V_7 ) ;
if ( ! V_45 -> V_51 )
return - V_55 ;
V_45 -> V_49 = F_40 ( V_17 -> V_57 + 1 , sizeof( * V_45 -> V_49 ) ,
V_53 ) ;
if ( ! V_45 -> V_49 )
return - V_55 ;
for ( V_40 = 0 , V_11 = V_17 -> V_58 ; V_40 < V_17 -> V_57 ; V_40 ++ , V_11 ++ ) {
V_54 = F_33 ( V_45 -> V_51 , V_11 , & V_50 ,
& V_45 -> V_49 [ V_40 ] ) ;
if ( V_54 < 0 )
return V_54 ;
}
if ( V_17 -> V_26 ) {
V_54 = F_33 ( V_45 -> V_51 , V_17 -> V_26 ,
& V_48 , & V_45 -> V_26 ) ;
if ( V_54 < 0 )
return V_54 ;
}
F_41 ( V_45 -> V_51 , V_59 ) ;
return 0 ;
}
int F_42 ( struct V_8 * V_17 )
{
int V_54 ;
if ( V_17 -> V_46 )
return 0 ;
V_54 = F_38 ( V_17 ) ;
if ( V_54 < 0 ) {
F_32 ( V_17 ) ;
return V_54 ;
}
return 0 ;
}
void F_43 ( struct V_8 * V_17 )
{
F_32 ( V_17 ) ;
}
