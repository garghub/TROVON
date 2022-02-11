static int F_1 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( V_4 != 1 )
return - V_9 ;
F_4 ( L_1 , ( ( V_10 * ) V_3 ) [ 0 ] ) ;
switch ( ( ( V_10 * ) V_3 ) [ 0 ] ) {
case V_11 :
F_5 ( V_12 , & V_8 -> V_13 ) ;
break;
case V_14 :
F_6 ( V_12 , & V_8 -> V_13 ) ;
break;
default:
return - V_9 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_8 ( V_6 ) ;
}
static int F_9 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_10 ( V_6 , V_15 ,
V_16 , V_3 ,
V_4 , NULL ) ;
}
static int F_11 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_10 ( V_6 , V_15 ,
V_17 , V_3 , V_4 , NULL ) ;
}
static int F_12 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
int V_18 ;
struct V_19 * V_20 , * V_21 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_18 = F_10 ( V_6 , V_15 , V_22 ,
V_3 , V_4 , & V_21 ) ;
if ( V_18 )
goto exit;
V_20 = F_13 ( V_2 , V_23 ,
V_24 , V_21 -> V_25 ) ;
if ( ! V_20 ) {
V_18 = - V_26 ;
goto V_27;
}
if ( F_14 ( V_20 , V_28 , V_21 -> V_25 , V_21 -> V_3 ) ) {
F_15 ( V_20 ) ;
V_18 = - V_29 ;
goto V_27;
}
V_18 = F_16 ( V_20 ) ;
V_27:
F_15 ( V_21 ) ;
exit:
return V_18 ;
}
static int F_17 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
int V_18 ;
struct V_19 * V_20 , * V_21 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_18 = F_10 ( V_6 , V_15 , V_30 ,
V_3 , V_4 , & V_21 ) ;
if ( V_18 )
goto exit;
V_20 = F_13 ( V_2 , V_23 ,
V_31 , V_21 -> V_25 ) ;
if ( ! V_20 ) {
V_18 = - V_26 ;
goto V_27;
}
if ( F_14 ( V_20 , V_28 , V_21 -> V_25 , V_21 -> V_3 ) ) {
F_15 ( V_20 ) ;
V_18 = - V_29 ;
goto V_27;
}
V_18 = F_16 ( V_20 ) ;
V_27:
F_15 ( V_21 ) ;
exit:
return V_18 ;
}
static int F_18 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
int V_18 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_2 -> V_32 = true ;
V_18 = F_10 ( V_6 , V_15 ,
V_33 , V_3 , V_4 , NULL ) ;
if ( V_18 )
V_2 -> V_32 = false ;
return V_18 ;
}
static int F_19 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_10 ( V_6 , V_15 ,
V_34 , V_3 , V_4 , NULL ) ;
}
static int F_20 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_2 -> V_32 ) {
V_2 -> V_32 = false ;
return F_10 ( V_6 , V_15 ,
V_35 , V_3 , V_4 , NULL ) ;
}
return - V_36 ;
}
static int F_21 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_10 ( V_6 , V_15 ,
V_37 , V_3 , V_4 , NULL ) ;
F_22 ( 200 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
int V_18 ;
struct V_19 * V_20 , * V_21 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_38 * V_39 = (struct V_38 * ) V_3 ;
if ( V_4 < sizeof( struct V_38 ) )
return - V_36 ;
V_18 = F_24 ( V_6 , V_39 -> V_40 , V_39 -> V_3 , & V_21 ) ;
if ( V_18 )
goto exit;
V_20 = F_13 ( V_2 , V_23 ,
V_41 , V_21 -> V_25 ) ;
if ( ! V_20 ) {
V_18 = - V_26 ;
goto V_27;
}
if ( F_14 ( V_20 , V_28 , V_21 -> V_25 , V_21 -> V_3 ) ) {
F_15 ( V_20 ) ;
V_18 = - V_29 ;
goto V_27;
}
V_18 = F_16 ( V_20 ) ;
V_27:
F_15 ( V_21 ) ;
exit:
return V_18 ;
}
static int F_25 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_10 ( V_6 , V_15 ,
V_42 , V_3 , V_4 , NULL ) ;
}
static int F_26 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
int V_18 ;
struct V_19 * V_20 , * V_21 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_4 != 4 )
return - V_36 ;
V_18 = F_10 ( V_6 , V_15 ,
V_43 ,
V_3 , V_4 , & V_21 ) ;
if ( V_18 )
goto exit;
V_20 = F_13 ( V_2 , V_23 ,
V_44 , V_21 -> V_25 ) ;
if ( ! V_20 ) {
V_18 = - V_26 ;
goto V_27;
}
if ( F_14 ( V_20 , V_28 , V_21 -> V_25 , V_21 -> V_3 ) ) {
F_15 ( V_20 ) ;
V_18 = - V_29 ;
goto V_27;
}
V_18 = F_16 ( V_20 ) ;
V_27:
F_15 ( V_21 ) ;
exit:
return V_18 ;
}
static int F_27 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
int V_18 ;
struct V_19 * V_20 , * V_21 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_4 != 2 )
return - V_36 ;
V_18 = F_10 ( V_6 , V_15 ,
V_45 ,
V_3 , V_4 , & V_21 ) ;
if ( V_18 )
goto exit;
V_20 = F_13 ( V_2 , V_23 ,
V_46 , V_21 -> V_25 ) ;
if ( ! V_20 ) {
V_18 = - V_26 ;
goto V_27;
}
if ( F_14 ( V_20 , V_28 , V_21 -> V_25 , V_21 -> V_3 ) ) {
F_15 ( V_20 ) ;
V_18 = - V_29 ;
goto V_27;
}
V_18 = F_16 ( V_20 ) ;
V_27:
F_15 ( V_21 ) ;
exit:
return V_18 ;
}
static int F_28 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
int V_18 ;
struct V_19 * V_20 , * V_21 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_4 <= 0 )
return - V_36 ;
V_18 = F_29 ( V_6 , V_3 , V_4 , & V_21 ) ;
if ( V_18 < 0 )
return V_18 ;
V_20 = F_13 ( V_2 , V_23 ,
V_47 , V_21 -> V_25 ) ;
if ( ! V_20 ) {
V_18 = - V_26 ;
goto V_27;
}
if ( F_14 ( V_20 , V_28 , V_21 -> V_25 , V_21 -> V_3 ) ) {
F_15 ( V_20 ) ;
V_18 = - V_29 ;
goto V_27;
}
V_18 = F_16 ( V_20 ) ;
V_27:
F_15 ( V_21 ) ;
return V_18 ;
}
static int F_30 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
struct V_19 * V_20 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_20 = F_13 ( V_2 , V_23 ,
V_48 ,
sizeof( V_6 -> V_49 ) ) ;
if ( ! V_20 )
return - V_26 ;
if ( F_14 ( V_20 , V_28 , sizeof( V_6 -> V_49 ) ,
& V_6 -> V_49 ) ) {
F_15 ( V_20 ) ;
return - V_29 ;
}
return F_16 ( V_20 ) ;
}
int F_31 ( struct V_5 * V_6 )
{
return F_32 ( V_6 -> V_1 , V_50 ,
sizeof( V_50 ) ) ;
}
