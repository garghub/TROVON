static int F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 -> V_7 ) ;
int V_8 ;
T_1 V_9 ;
V_9 = F_3 ( V_2 -> V_10 , 16 , & V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_4 = F_4 ( V_6 ) ;
return V_8 ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 =
F_6 ( V_12 , struct V_14 , V_12 ) ;
struct V_3 * V_16 ;
int V_8 ;
if ( ! V_15 -> V_17 )
return - V_18 ;
V_8 = F_1 ( V_2 , & V_16 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_15 -> V_17 ( V_16 , V_8 , V_15 , V_13 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , struct V_11 * V_12 ,
const char * V_13 , T_2 V_19 )
{
struct V_14 * V_15 =
F_6 ( V_12 , struct V_14 , V_12 ) ;
struct V_3 * V_16 ;
int V_8 ;
if ( ! V_15 -> V_20 )
return - V_18 ;
V_8 = F_1 ( V_2 , & V_16 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_15 -> V_20 ( V_16 , V_8 , V_15 , V_13 , V_19 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
}
static T_1 F_10 ( struct V_3 * V_16 , T_3 V_8 ,
struct V_14 * V_12 , char * V_13 )
{
return sprintf ( V_13 , L_1 , F_11 ( V_16 , V_8 ) ) ;
}
static T_1 F_12 ( struct V_3 * V_16 , T_3 V_8 ,
struct V_14 * V_12 , char * V_13 )
{
if ( F_13 ( F_11 ( V_16 , V_8 ) ) != V_21 )
return 0 ;
return sprintf ( V_13 , L_1 ,
F_14 ( V_16 , V_8 , V_22 ) ) ;
}
static T_1 F_15 ( struct V_3 * V_16 , T_3 V_8 ,
struct V_14 * V_12 , char * V_13 )
{
unsigned int V_23 ;
if ( F_13 ( F_11 ( V_16 , V_8 ) ) != V_21 )
return 0 ;
if ( F_16 ( V_16 , V_8 , V_24 , 0 , & V_23 ) )
return 0 ;
return sprintf ( V_13 , L_1 , V_23 ) ;
}
static bool F_17 ( struct V_3 * V_16 , T_3 V_8 )
{
if ( V_8 == V_16 -> V_25 || V_8 == V_16 -> V_26 )
return true ;
switch ( F_13 ( F_11 ( V_16 , V_8 ) ) ) {
case V_27 :
case V_28 :
return true ;
default:
return false ;
}
}
static T_1 F_18 ( struct V_3 * V_16 , T_3 V_8 ,
struct V_14 * V_12 , char * V_13 )
{
if ( ! F_17 ( V_16 , V_8 ) )
return 0 ;
return sprintf ( V_13 , L_1 ,
F_14 ( V_16 , V_8 , V_29 ) ) ;
}
static T_1 F_19 ( struct V_3 * V_16 , T_3 V_8 ,
struct V_14 * V_12 , char * V_13 )
{
if ( ! F_17 ( V_16 , V_8 ) )
return 0 ;
return sprintf ( V_13 , L_1 ,
F_14 ( V_16 , V_8 , V_30 ) ) ;
}
static T_1 F_20 ( struct V_3 * V_16 , T_3 V_8 ,
struct V_14 * V_12 , char * V_13 )
{
if ( V_8 != V_16 -> V_25 && ! ( F_11 ( V_16 , V_8 ) & V_31 ) )
return 0 ;
return sprintf ( V_13 , L_1 ,
F_14 ( V_16 , V_8 , V_32 ) ) ;
}
static T_1 F_21 ( struct V_3 * V_16 , T_3 V_8 ,
struct V_14 * V_12 , char * V_13 )
{
if ( V_8 != V_16 -> V_25 && ! ( F_11 ( V_16 , V_8 ) & V_33 ) )
return 0 ;
return sprintf ( V_13 , L_1 ,
F_14 ( V_16 , V_8 , V_34 ) ) ;
}
static T_1 F_22 ( struct V_3 * V_16 , T_3 V_8 ,
struct V_14 * V_12 , char * V_13 )
{
if ( V_8 != V_16 -> V_25 && ! ( F_11 ( V_16 , V_8 ) & V_35 ) )
return 0 ;
return sprintf ( V_13 , L_1 ,
F_14 ( V_16 , V_8 , V_36 ) ) ;
}
static T_1 F_23 ( struct V_3 * V_16 , T_3 V_8 ,
struct V_14 * V_12 , char * V_13 )
{
return sprintf ( V_13 , L_1 ,
F_14 ( V_16 , V_8 , V_37 ) ) ;
}
static T_1 F_24 ( struct V_3 * V_16 , T_3 V_8 ,
struct V_14 * V_12 , char * V_13 )
{
T_3 V_38 [ 32 ] ;
int V_39 , V_40 ;
T_1 V_9 = 0 ;
V_40 = F_25 ( V_16 , V_8 , V_38 , F_26 ( V_38 ) ) ;
if ( V_40 <= 0 )
return V_40 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
V_9 += sprintf ( V_13 + V_9 , L_2 , V_39 ? L_3 : L_4 , V_38 [ V_39 ] ) ;
V_9 += sprintf ( V_13 + V_9 , L_5 ) ;
return V_9 ;
}
static void F_27 ( struct V_1 * V_2 ,
const struct V_41 * V_42 )
{
if ( V_2 ) {
F_28 ( V_2 , V_42 ) ;
F_29 ( V_2 ) ;
}
}
static void F_30 ( struct V_3 * V_16 )
{
struct V_43 * V_44 = V_16 -> V_45 ;
struct V_1 * * V_46 ;
if ( ! V_44 )
return;
F_27 ( V_44 -> V_25 , & V_47 ) ;
if ( V_44 -> V_48 ) {
for ( V_46 = V_44 -> V_48 ; * V_46 ; V_46 ++ )
F_27 ( * V_46 , & V_49 ) ;
F_9 ( V_44 -> V_48 ) ;
}
F_29 ( V_44 -> V_50 ) ;
F_9 ( V_44 ) ;
V_16 -> V_45 = NULL ;
}
static int F_31 ( struct V_1 * V_7 , T_3 V_8 ,
const struct V_41 * V_42 ,
struct V_1 * * V_51 )
{
struct V_1 * V_2 = F_32 ( sizeof( * V_2 ) , V_52 ) ;
int V_53 ;
if ( ! V_2 )
return - V_54 ;
F_33 ( V_2 , & V_55 ) ;
V_53 = F_34 ( V_2 , V_7 , L_6 , V_8 ) ;
if ( V_53 < 0 )
return V_53 ;
V_53 = F_35 ( V_2 , V_42 ) ;
if ( V_53 < 0 ) {
F_29 ( V_2 ) ;
return V_53 ;
}
* V_51 = V_2 ;
return 0 ;
}
static int F_36 ( struct V_3 * V_16 )
{
struct V_43 * V_44 ;
int V_39 , V_53 ;
T_3 V_8 ;
V_44 = V_16 -> V_45 = F_32 ( sizeof( * V_44 ) , V_52 ) ;
if ( ! V_44 )
return - V_54 ;
V_44 -> V_50 = F_37 ( L_7 , & V_16 -> V_6 . V_2 ) ;
if ( ! V_44 -> V_50 )
return - V_54 ;
V_44 -> V_48 = F_38 ( V_16 -> V_56 + 1 , sizeof( * V_44 -> V_48 ) ,
V_52 ) ;
if ( ! V_44 -> V_48 )
return - V_54 ;
for ( V_39 = 0 , V_8 = V_16 -> V_57 ; V_39 < V_16 -> V_56 ; V_39 ++ , V_8 ++ ) {
V_53 = F_31 ( V_44 -> V_50 , V_8 , & V_49 ,
& V_44 -> V_48 [ V_39 ] ) ;
if ( V_53 < 0 )
return V_53 ;
}
if ( V_16 -> V_25 ) {
V_53 = F_31 ( V_44 -> V_50 , V_16 -> V_25 ,
& V_47 , & V_44 -> V_25 ) ;
if ( V_53 < 0 )
return V_53 ;
}
F_39 ( V_44 -> V_50 , V_58 ) ;
return 0 ;
}
int F_40 ( struct V_3 * V_16 )
{
int V_53 ;
if ( V_16 -> V_45 )
return 0 ;
V_53 = F_36 ( V_16 ) ;
if ( V_53 < 0 ) {
F_30 ( V_16 ) ;
return V_53 ;
}
return 0 ;
}
void F_41 ( struct V_3 * V_16 )
{
F_30 ( V_16 ) ;
}
