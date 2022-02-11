static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
struct V_6 V_7 ;
struct V_8 V_9 ;
int V_10 ;
V_7 . V_11 = V_12 ;
V_7 . V_13 = V_14 ;
V_10 = F_2 ( V_2 -> V_5 ,
V_15 ,
& V_7 , sizeof( V_7 ) , & V_9 ,
sizeof( V_9 ) ) ;
if ( V_10 ) {
F_3 ( & V_4 -> V_16 ,
L_1 ,
V_10 ) ;
return V_10 ;
}
if ( V_9 . V_11 > V_7 . V_11 ) {
F_3 ( & V_4 -> V_16 ,
L_2 ,
V_9 . V_11 , V_7 . V_11 ) ;
return - V_17 ;
}
V_2 -> V_18 = V_9 . V_11 ;
V_2 -> V_19 = V_9 . V_13 ;
F_4 ( & V_4 -> V_16 , L_3 , V_20 , V_9 . V_11 ,
V_9 . V_13 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
struct V_23 V_7 ;
struct V_24 V_9 ;
int V_10 ;
V_7 . V_25 = V_22 -> V_26 ;
V_10 = F_2 ( V_2 -> V_5 ,
V_27 ,
& V_7 , sizeof( V_7 ) ,
& V_9 , sizeof( V_9 ) ) ;
if ( V_10 ) {
F_3 ( & V_4 -> V_16 ,
L_4 ,
V_22 -> V_26 , V_10 ) ;
return V_10 ;
}
V_22 -> V_28 = V_9 . V_11 ;
V_22 -> V_29 = V_9 . V_13 ;
F_4 ( & V_4 -> V_16 , L_5 , V_20 , V_22 -> V_26 ,
V_9 . V_11 , V_9 . V_13 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
struct V_21 * V_22 ;
int V_10 ;
if ( ! V_2 -> V_30 )
return 0 ;
F_7 (bundle, &intf->bundles, links) {
V_10 = F_5 ( V_2 , V_22 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
int F_8 ( struct V_3 * V_4 )
{
struct V_31 V_9 ;
struct V_32 * V_5 = V_4 -> V_2 -> V_5 ;
int V_10 ;
V_10 = F_2 ( V_5 , V_33 ,
NULL , 0 , & V_9 , sizeof( V_9 ) ) ;
if ( V_10 ) {
F_3 ( & V_5 -> V_4 -> V_16 ,
L_6 , V_10 ) ;
return V_10 ;
}
return F_9 ( V_9 . V_34 ) ;
}
int F_10 ( struct V_3 * V_4 , void * V_35 ,
T_1 V_34 )
{
struct V_32 * V_5 = V_4 -> V_2 -> V_5 ;
return F_2 ( V_5 , V_36 ,
NULL , 0 , V_35 , V_34 ) ;
}
int F_11 ( struct V_1 * V_2 , T_2 V_37 )
{
struct V_38 V_7 ;
V_7 . V_37 = F_12 ( V_37 ) ;
return F_2 ( V_2 -> V_5 , V_39 ,
& V_7 , sizeof( V_7 ) , NULL , 0 ) ;
}
int F_13 ( struct V_1 * V_2 , T_2 V_37 )
{
struct V_40 V_7 ;
V_7 . V_37 = F_12 ( V_37 ) ;
return F_2 ( V_2 -> V_5 ,
V_41 , & V_7 ,
sizeof( V_7 ) , NULL , 0 ) ;
}
int F_14 ( struct V_1 * V_2 ,
T_2 V_37 )
{
struct V_42 * V_7 ;
struct V_43 * V_44 ;
int V_10 ;
V_44 = F_15 ( V_2 -> V_5 ,
V_45 ,
sizeof( * V_7 ) , 0 , 0 ,
V_46 ) ;
if ( ! V_44 )
return - V_47 ;
V_7 = V_44 -> V_7 -> V_48 ;
V_7 -> V_37 = F_12 ( V_37 ) ;
V_10 = F_16 ( V_44 ) ;
if ( V_10 ) {
F_3 ( & V_2 -> V_16 , L_7 ,
V_10 ) ;
}
F_17 ( V_44 ) ;
return V_10 ;
}
int F_18 ( struct V_1 * V_2 )
{
struct V_43 * V_44 ;
int V_10 ;
V_44 = F_15 ( V_2 -> V_5 ,
V_49 ,
0 , 0 , V_50 ,
V_46 ) ;
if ( ! V_44 )
return - V_47 ;
V_10 = F_16 ( V_44 ) ;
if ( V_10 )
F_3 ( & V_2 -> V_16 , L_8 , V_10 ) ;
F_17 ( V_44 ) ;
return V_10 ;
}
static int F_19 ( T_3 V_51 )
{
switch ( V_51 ) {
case V_52 :
return - V_53 ;
case V_54 :
return - V_55 ;
case V_56 :
return - V_57 ;
case V_58 :
default:
return - V_59 ;
}
}
int F_20 ( struct V_1 * V_2 , T_3 V_25 )
{
struct V_60 V_7 ;
struct V_61 V_9 ;
int V_10 ;
V_7 . V_25 = V_25 ;
V_10 = F_2 ( V_2 -> V_5 ,
V_62 , & V_7 ,
sizeof( V_7 ) , & V_9 , sizeof( V_9 ) ) ;
if ( V_10 ) {
F_3 ( & V_2 -> V_16 , L_9 ,
V_25 , V_10 ) ;
return V_10 ;
}
if ( V_9 . V_51 != V_63 ) {
F_3 ( & V_2 -> V_16 , L_10 ,
V_25 , V_9 . V_51 ) ;
return F_19 ( V_9 . V_51 ) ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 , T_3 V_25 )
{
struct V_60 V_7 ;
struct V_61 V_9 ;
int V_10 ;
V_7 . V_25 = V_25 ;
V_10 = F_2 ( V_2 -> V_5 ,
V_64 , & V_7 ,
sizeof( V_7 ) , & V_9 , sizeof( V_9 ) ) ;
if ( V_10 ) {
F_3 ( & V_2 -> V_16 , L_11 ,
V_25 , V_10 ) ;
return V_10 ;
}
if ( V_9 . V_51 != V_63 ) {
F_3 ( & V_2 -> V_16 , L_12 ,
V_25 , V_9 . V_51 ) ;
return F_19 ( V_9 . V_51 ) ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 , T_3 V_25 )
{
struct V_60 V_7 ;
struct V_61 V_9 ;
int V_10 ;
V_7 . V_25 = V_25 ;
V_10 = F_2 ( V_2 -> V_5 ,
V_65 , & V_7 ,
sizeof( V_7 ) , & V_9 , sizeof( V_9 ) ) ;
if ( V_10 ) {
F_3 ( & V_2 -> V_16 ,
L_13 , V_25 ,
V_10 ) ;
return V_10 ;
}
if ( V_9 . V_51 != V_63 ) {
F_3 ( & V_2 -> V_16 , L_14 ,
V_25 , V_9 . V_51 ) ;
return F_19 ( V_9 . V_51 ) ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 , T_3 V_25 )
{
struct V_60 V_7 ;
struct V_61 V_9 ;
int V_10 ;
if ( ! V_2 -> V_66 )
return 0 ;
V_7 . V_25 = V_25 ;
V_10 = F_2 ( V_2 -> V_5 ,
V_67 , & V_7 ,
sizeof( V_7 ) , & V_9 , sizeof( V_9 ) ) ;
if ( V_10 ) {
F_3 ( & V_2 -> V_16 ,
L_15 , V_25 ,
V_10 ) ;
return V_10 ;
}
if ( V_9 . V_51 != V_63 ) {
F_3 ( & V_2 -> V_16 , L_16 ,
V_25 , V_9 . V_51 ) ;
return F_19 ( V_9 . V_51 ) ;
}
return 0 ;
}
static int F_24 ( T_3 V_51 )
{
switch ( V_51 ) {
case V_68 :
return - V_55 ;
case V_69 :
return - V_57 ;
default:
return - V_59 ;
}
}
int F_25 ( struct V_1 * V_2 )
{
struct V_70 V_9 ;
int V_10 ;
V_10 = F_2 ( V_2 -> V_5 ,
V_71 , NULL , 0 ,
& V_9 , sizeof( V_9 ) ) ;
if ( V_10 ) {
F_3 ( & V_2 -> V_16 ,
L_17 , V_10 ) ;
return V_10 ;
}
if ( V_9 . V_51 != V_72 ) {
F_3 ( & V_2 -> V_16 , L_18 ,
V_9 . V_51 ) ;
return F_24 ( V_9 . V_51 ) ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_70 V_9 ;
int V_10 ;
V_10 = F_2 ( V_2 -> V_5 ,
V_73 , NULL ,
0 , & V_9 , sizeof( V_9 ) ) ;
if ( V_10 ) {
F_3 ( & V_2 -> V_16 , L_19 ,
V_10 ) ;
return V_10 ;
}
if ( V_9 . V_51 != V_72 ) {
F_3 ( & V_2 -> V_16 , L_20 ,
V_9 . V_51 ) ;
return F_24 ( V_9 . V_51 ) ;
}
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_70 V_9 ;
int V_10 ;
V_10 = F_2 ( V_2 -> V_5 ,
V_74 , NULL , 0 ,
& V_9 , sizeof( V_9 ) ) ;
if ( V_10 ) {
F_3 ( & V_2 -> V_16 ,
L_21 ,
V_10 ) ;
return V_10 ;
}
if ( V_9 . V_51 != V_72 ) {
F_3 ( & V_2 -> V_16 , L_22 ,
V_9 . V_51 ) ;
return F_24 ( V_9 . V_51 ) ;
}
return 0 ;
}
static T_4 F_28 ( struct V_75 * V_16 ,
struct V_76 * V_77 , char * V_78 )
{
struct V_1 * V_2 = F_29 ( V_16 ) ;
return F_30 ( V_78 , V_79 , L_23 , V_2 -> V_80 ) ;
}
static T_4 F_31 ( struct V_75 * V_16 ,
struct V_76 * V_77 , char * V_78 )
{
struct V_1 * V_2 = F_29 ( V_16 ) ;
return F_30 ( V_78 , V_79 , L_23 , V_2 -> V_81 ) ;
}
static void F_32 ( struct V_75 * V_16 )
{
struct V_1 * V_2 = F_29 ( V_16 ) ;
F_33 ( V_2 -> V_5 ) ;
F_34 ( V_2 -> V_80 ) ;
F_34 ( V_2 -> V_81 ) ;
F_34 ( V_2 ) ;
}
struct V_1 * F_35 ( struct V_3 * V_4 )
{
struct V_32 * V_5 ;
struct V_1 * V_2 ;
V_2 = F_36 ( sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return F_37 ( - V_47 ) ;
V_2 -> V_4 = V_4 ;
V_5 = F_38 ( V_4 ) ;
if ( F_39 ( V_5 ) ) {
F_3 ( & V_4 -> V_16 ,
L_24 ,
F_40 ( V_5 ) ) ;
F_34 ( V_2 ) ;
return F_41 ( V_5 ) ;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_16 . V_82 = & V_4 -> V_16 ;
V_2 -> V_16 . V_83 = & V_84 ;
V_2 -> V_16 . type = & V_85 ;
V_2 -> V_16 . V_86 = V_87 ;
V_2 -> V_16 . V_88 = V_4 -> V_16 . V_88 ;
F_42 ( & V_2 -> V_16 ) ;
F_43 ( & V_2 -> V_16 , L_25 , F_44 ( & V_4 -> V_16 ) ) ;
F_45 ( V_2 -> V_5 , V_2 ) ;
return V_2 ;
}
int F_46 ( struct V_1 * V_2 )
{
int V_10 ;
F_4 ( & V_2 -> V_5 -> V_4 -> V_16 , L_23 , V_20 ) ;
V_10 = F_47 ( V_2 -> V_5 ) ;
if ( V_10 ) {
F_3 ( & V_2 -> V_5 -> V_4 -> V_16 ,
L_26 ,
V_10 ) ;
return V_10 ;
}
V_10 = F_1 ( V_2 ) ;
if ( V_10 )
goto V_89;
if ( V_2 -> V_18 > 0 || V_2 -> V_19 > 1 )
V_2 -> V_30 = true ;
if ( ! ( V_2 -> V_4 -> V_90 & V_91 ) )
V_2 -> V_66 = true ;
return 0 ;
V_89:
F_48 ( V_2 -> V_5 ) ;
return V_10 ;
}
void F_49 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_5 -> V_4 -> V_16 , L_23 , V_20 ) ;
if ( V_2 -> V_4 -> V_92 )
F_50 ( V_2 -> V_5 ) ;
else
F_48 ( V_2 -> V_5 ) ;
}
int F_51 ( struct V_1 * V_2 )
{
F_48 ( V_2 -> V_5 ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_47 ( V_2 -> V_5 ) ;
if ( V_10 ) {
F_3 ( & V_2 -> V_5 -> V_4 -> V_16 ,
L_26 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_54 ( & V_2 -> V_16 ) ;
if ( V_10 ) {
F_3 ( & V_2 -> V_16 ,
L_27 ,
V_10 ) ;
return V_10 ;
}
return 0 ;
}
void F_55 ( struct V_1 * V_2 )
{
if ( F_56 ( & V_2 -> V_16 ) )
F_57 ( & V_2 -> V_16 ) ;
}
struct V_1 * F_58 ( struct V_1 * V_2 )
{
F_59 ( & V_2 -> V_16 ) ;
return V_2 ;
}
void F_60 ( struct V_1 * V_2 )
{
F_61 ( & V_2 -> V_16 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
F_63 ( V_2 -> V_5 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
F_65 ( V_2 -> V_5 ) ;
}
