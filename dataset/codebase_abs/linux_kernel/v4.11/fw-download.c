static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , struct V_2 , V_1 ) ;
F_3 ( V_3 -> V_4 -> V_5 , L_1 ,
V_3 -> V_6 ) ;
F_4 ( V_3 -> V_7 ) ;
if ( ! V_3 -> V_8 )
F_5 ( & V_3 -> V_4 -> V_9 ,
V_3 -> V_10 ) ;
F_6 ( V_3 ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
F_8 ( & V_3 -> V_1 , F_1 ) ;
}
static struct V_2 * F_9 ( struct V_4 * V_4 ,
T_1 V_10 )
{
struct V_2 * V_3 ;
F_10 ( & V_4 -> V_11 ) ;
F_11 (fw_req, &fw_download->fw_requests, node) {
if ( V_3 -> V_10 == V_10 ) {
F_12 ( & V_3 -> V_1 ) ;
goto V_12;
}
}
V_3 = NULL ;
V_12:
F_13 ( & V_4 -> V_11 ) ;
return V_3 ;
}
static void F_14 ( struct V_4 * V_4 ,
struct V_2 * V_3 )
{
if ( V_3 -> V_13 )
return;
F_10 ( & V_4 -> V_11 ) ;
F_15 ( & V_3 -> V_14 ) ;
F_13 ( & V_4 -> V_11 ) ;
V_3 -> V_13 = true ;
F_7 ( V_3 ) ;
}
static void F_16 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_17 ( V_16 ) ;
struct V_2 * V_3 = F_2 ( V_18 ,
struct V_2 , V_18 ) ;
struct V_4 * V_4 = V_3 -> V_4 ;
F_18 ( V_4 -> V_5 ,
L_2 ,
V_3 -> V_10 ) ;
V_3 -> V_8 = true ;
F_14 ( V_4 , V_3 ) ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = V_3 -> V_4 ;
if ( F_20 ( V_19 , V_3 -> V_20 ) )
return 0 ;
F_18 ( V_4 -> V_5 ,
L_3 ,
V_3 -> V_10 ) ;
V_3 -> V_8 = true ;
F_14 ( V_4 , V_3 ) ;
return - V_21 ;
}
static struct V_2 * F_21 ( struct V_4 * V_4 ,
const char * V_22 )
{
struct V_23 * V_24 = V_4 -> V_25 -> V_26 -> V_24 ;
struct V_2 * V_3 ;
int V_27 , V_28 ;
V_3 = F_22 ( sizeof( * V_3 ) , V_29 ) ;
if ( ! V_3 )
return F_23 ( - V_30 ) ;
V_27 = F_24 ( & V_4 -> V_9 , 1 , 256 , V_29 ) ;
if ( V_27 < 0 ) {
F_18 ( V_4 -> V_5 ,
L_4 , V_27 ) ;
goto V_31;
}
V_3 -> V_10 = V_27 ;
snprintf ( V_3 -> V_6 , sizeof( V_3 -> V_6 ) ,
V_32 L_5 ,
V_24 -> V_33 , V_24 -> V_34 ,
V_24 -> V_35 , V_24 -> V_36 , V_22 ) ;
F_25 ( V_4 -> V_5 , L_6 ,
V_3 -> V_6 ) ;
V_27 = F_26 ( & V_3 -> V_7 , V_3 -> V_6 , V_4 -> V_5 ) ;
if ( V_27 ) {
F_18 ( V_4 -> V_5 ,
L_7 , V_3 -> V_6 ,
V_27 ) ;
goto V_37;
}
V_3 -> V_4 = V_4 ;
F_27 ( & V_3 -> V_1 ) ;
F_10 ( & V_4 -> V_11 ) ;
F_28 ( & V_3 -> V_14 , & V_4 -> V_38 ) ;
F_13 ( & V_4 -> V_11 ) ;
V_28 = F_29 ( V_3 -> V_7 -> V_39 , V_40 ) ;
V_3 -> V_20 = V_19 + V_28 * V_41 ;
F_30 ( & V_3 -> V_18 , F_16 ) ;
F_31 ( & V_3 -> V_18 , V_41 ) ;
return V_3 ;
V_37:
F_5 ( & V_4 -> V_9 , V_3 -> V_10 ) ;
V_31:
F_6 ( V_3 ) ;
return F_23 ( V_27 ) ;
}
static int F_32 ( struct V_42 * V_43 )
{
struct V_44 * V_25 = V_43 -> V_25 ;
struct V_4 * V_4 = F_33 ( V_25 ) ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_2 * V_3 ;
const char * V_22 ;
if ( V_43 -> V_46 -> V_49 != sizeof( * V_46 ) ) {
F_18 ( V_4 -> V_5 ,
L_8 ,
V_43 -> V_46 -> V_49 , sizeof( * V_46 ) ) ;
return - V_50 ;
}
V_46 = V_43 -> V_46 -> V_51 ;
V_22 = ( const char * ) V_46 -> V_52 ;
if ( F_34 ( V_22 , V_53 ) ==
V_53 ) {
F_18 ( V_4 -> V_5 ,
L_9 ) ;
return - V_50 ;
}
V_3 = F_21 ( V_4 , V_22 ) ;
if ( F_35 ( V_3 ) )
return F_36 ( V_3 ) ;
if ( ! F_37 ( V_43 , sizeof( * V_48 ) , V_29 ) ) {
F_18 ( V_4 -> V_5 , L_10 ) ;
F_14 ( V_4 , V_3 ) ;
return - V_30 ;
}
V_48 = V_43 -> V_48 -> V_51 ;
V_48 -> V_10 = V_3 -> V_10 ;
V_48 -> V_39 = F_38 ( V_3 -> V_7 -> V_39 ) ;
F_3 ( V_4 -> V_5 ,
L_11 , V_3 -> V_7 -> V_39 ) ;
return 0 ;
}
static int F_39 ( struct V_42 * V_43 )
{
struct V_44 * V_25 = V_43 -> V_25 ;
struct V_4 * V_4 = F_33 ( V_25 ) ;
struct V_54 * V_46 ;
struct V_55 * V_48 ;
struct V_2 * V_3 ;
const struct V_56 * V_7 ;
unsigned int V_57 , V_39 ;
T_1 V_10 ;
int V_27 = 0 ;
if ( V_43 -> V_46 -> V_49 != sizeof( * V_46 ) ) {
F_18 ( V_4 -> V_5 ,
L_12 ,
V_43 -> V_46 -> V_49 , sizeof( * V_46 ) ) ;
return - V_50 ;
}
V_46 = V_43 -> V_46 -> V_51 ;
V_57 = F_40 ( V_46 -> V_57 ) ;
V_39 = F_40 ( V_46 -> V_39 ) ;
V_10 = V_46 -> V_10 ;
V_3 = F_9 ( V_4 , V_10 ) ;
if ( ! V_3 ) {
F_18 ( V_4 -> V_5 ,
L_13 , V_10 ) ;
return - V_50 ;
}
F_41 ( & V_3 -> V_18 ) ;
if ( V_3 -> V_13 ) {
V_27 = - V_21 ;
goto V_58;
}
V_27 = F_19 ( V_3 ) ;
if ( V_27 )
goto V_58;
V_7 = V_3 -> V_7 ;
if ( V_57 >= V_7 -> V_39 || V_39 > V_7 -> V_39 - V_57 ) {
F_18 ( V_4 -> V_5 ,
L_14 ,
V_57 , V_39 ) ;
V_27 = - V_50 ;
goto V_58;
}
if ( ! F_37 ( V_43 , sizeof( * V_48 ) + V_39 ,
V_29 ) ) {
F_18 ( V_4 -> V_5 ,
L_15 ) ;
V_27 = - V_30 ;
goto V_58;
}
V_48 = V_43 -> V_48 -> V_51 ;
memcpy ( V_48 -> V_59 , V_7 -> V_59 + V_57 , V_39 ) ;
F_3 ( V_4 -> V_5 ,
L_16 , V_57 ,
V_39 ) ;
F_31 ( & V_3 -> V_18 , V_41 ) ;
V_58:
F_7 ( V_3 ) ;
return V_27 ;
}
static int F_42 ( struct V_42 * V_43 )
{
struct V_44 * V_25 = V_43 -> V_25 ;
struct V_4 * V_4 = F_33 ( V_25 ) ;
struct V_60 * V_46 ;
struct V_2 * V_3 ;
T_1 V_10 ;
if ( V_43 -> V_46 -> V_49 != sizeof( * V_46 ) ) {
F_18 ( V_4 -> V_5 ,
L_17 ,
V_43 -> V_46 -> V_49 , sizeof( * V_46 ) ) ;
return - V_50 ;
}
V_46 = V_43 -> V_46 -> V_51 ;
V_10 = V_46 -> V_10 ;
V_3 = F_9 ( V_4 , V_10 ) ;
if ( ! V_3 ) {
F_18 ( V_4 -> V_5 ,
L_13 , V_10 ) ;
return - V_50 ;
}
F_41 ( & V_3 -> V_18 ) ;
F_14 ( V_4 , V_3 ) ;
F_7 ( V_3 ) ;
F_3 ( V_4 -> V_5 , L_18 ) ;
return 0 ;
}
int F_43 ( struct V_42 * V_43 )
{
T_1 type = V_43 -> type ;
switch ( type ) {
case V_61 :
return F_32 ( V_43 ) ;
case V_62 :
return F_39 ( V_43 ) ;
case V_63 :
return F_42 ( V_43 ) ;
default:
F_18 ( & V_43 -> V_25 -> V_26 -> V_64 ,
L_19 , type ) ;
return - V_50 ;
}
}
int F_44 ( struct V_44 * V_25 )
{
struct V_4 * V_4 ;
int V_27 ;
if ( ! V_25 )
return 0 ;
V_4 = F_22 ( sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 )
return - V_30 ;
V_4 -> V_5 = & V_25 -> V_26 -> V_64 ;
F_45 ( & V_4 -> V_38 ) ;
F_46 ( & V_4 -> V_9 ) ;
F_47 ( V_25 , V_4 ) ;
V_4 -> V_25 = V_25 ;
F_48 ( & V_4 -> V_11 ) ;
V_27 = F_49 ( V_25 ) ;
if ( V_27 )
goto V_65;
return 0 ;
V_65:
F_50 ( & V_4 -> V_9 ) ;
F_6 ( V_4 ) ;
return V_27 ;
}
void F_51 ( struct V_44 * V_25 )
{
struct V_4 * V_4 ;
struct V_2 * V_3 , * V_66 ;
if ( ! V_25 )
return;
V_4 = F_33 ( V_25 ) ;
F_52 ( V_4 -> V_25 ) ;
F_10 ( & V_4 -> V_11 ) ;
F_11 (fw_req, &fw_download->fw_requests, node)
F_12 ( & V_3 -> V_1 ) ;
F_13 ( & V_4 -> V_11 ) ;
F_53 (fw_req, tmp, &fw_download->fw_requests, node) {
F_41 ( & V_3 -> V_18 ) ;
F_14 ( V_4 , V_3 ) ;
F_7 ( V_3 ) ;
}
F_50 ( & V_4 -> V_9 ) ;
F_6 ( V_4 ) ;
}
