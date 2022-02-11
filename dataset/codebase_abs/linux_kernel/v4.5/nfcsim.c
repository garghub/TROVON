static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , L_1 , V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_3 ;
V_2 -> V_8 = NULL ;
F_4 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
F_5 ( & V_2 -> V_4 ) ;
F_6 ( & V_2 -> V_10 ) ;
F_6 ( & V_2 -> V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_12 V_13 ;
F_2 ( V_2 , L_2 ) ;
memset ( & V_13 , 0 , sizeof( struct V_12 ) ) ;
V_13 . V_14 = V_15 ;
F_8 ( V_2 -> V_16 , & V_13 , 1 ) ;
return 0 ;
}
static int F_9 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
F_2 ( V_2 , L_2 ) ;
F_3 ( & V_2 -> V_4 ) ;
V_2 -> V_17 = 1 ;
F_5 ( & V_2 -> V_4 ) ;
return 0 ;
}
static int F_11 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
F_2 ( V_2 , L_2 ) ;
F_3 ( & V_2 -> V_4 ) ;
V_2 -> V_17 = 0 ;
F_5 ( & V_2 -> V_4 ) ;
return 0 ;
}
static int F_12 ( struct V_16 * V_16 ,
struct V_12 * V_18 ,
T_1 V_19 , T_1 * V_20 , T_2 V_21 )
{
int V_22 ;
struct V_1 * V_2 = F_10 ( V_16 ) ;
struct V_1 * V_23 = V_2 -> V_24 ;
T_1 * V_25 ;
T_2 V_26 ;
F_2 ( V_2 , L_3 , V_18 -> V_27 , V_19 ) ;
F_3 ( & V_23 -> V_4 ) ;
F_13 ( V_23 -> V_16 , V_15 ,
V_28 , V_20 , V_21 ) ;
V_25 = F_14 ( V_23 -> V_16 , & V_26 ) ;
if ( ! V_25 ) {
F_15 ( V_23 , L_4 ) ;
F_5 ( & V_23 -> V_4 ) ;
return - V_29 ;
}
F_5 ( & V_23 -> V_4 ) ;
F_3 ( & V_2 -> V_4 ) ;
V_22 = F_16 ( V_16 , V_25 , V_26 ) ;
if ( V_22 ) {
F_15 ( V_2 , L_5 ) ;
F_5 ( & V_2 -> V_4 ) ;
return V_22 ;
}
V_22 = F_17 ( V_16 , V_18 -> V_27 , V_28 ,
V_30 ) ;
F_5 ( & V_2 -> V_4 ) ;
return V_22 ;
}
static int F_18 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
F_2 ( V_2 , L_2 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_16 * V_16 ,
T_3 V_31 , T_3 V_32 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
int V_22 ;
F_3 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_5 != V_6 ) {
F_15 ( V_2 , L_6 ) ;
V_22 = - V_33 ;
goto exit;
}
if ( V_31 & V_15 )
V_2 -> V_5 |= V_34 ;
if ( V_32 & V_15 )
V_2 -> V_5 |= V_35 ;
if ( V_2 -> V_5 == V_6 ) {
F_15 ( V_2 , L_7 ) ;
V_22 = - V_29 ;
goto exit;
}
V_2 -> V_36 = 0 ;
V_2 -> V_37 = V_6 ;
F_20 ( V_38 , & V_2 -> V_10 , 0 ) ;
F_2 ( V_2 , L_8 , V_31 ,
V_32 ) ;
V_22 = 0 ;
exit:
F_5 ( & V_2 -> V_4 ) ;
return V_22 ;
}
static void F_21 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
F_2 ( V_2 , L_9 ) ;
F_3 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = V_6 ;
F_5 ( & V_2 -> V_4 ) ;
F_6 ( & V_2 -> V_10 ) ;
}
static int F_22 ( struct V_16 * V_16 ,
struct V_12 * V_18 , T_3 V_39 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
F_2 ( V_2 , L_2 ) ;
return - V_40 ;
}
static void F_23 ( struct V_16 * V_16 ,
struct V_12 * V_18 , T_1 V_41 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
F_2 ( V_2 , L_2 ) ;
}
static void F_24 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_25 ( V_43 , struct V_1 ,
V_11 . V_43 ) ;
F_3 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_7 || ! V_2 -> V_17 || ! V_2 -> V_9 ) {
F_4 ( V_2 -> V_9 ) ;
goto exit;
}
if ( V_2 -> V_36 ) {
if ( ! V_2 -> V_8 ) {
F_15 ( V_2 , L_10 ) ;
F_4 ( V_2 -> V_9 ) ;
goto exit;
}
V_2 -> V_8 ( V_2 -> V_44 , V_2 -> V_9 , 0 ) ;
V_2 -> V_8 = NULL ;
} else {
F_26 ( V_2 -> V_16 , V_2 -> V_9 ) ;
}
exit:
V_2 -> V_9 = NULL ;
F_5 ( & V_2 -> V_4 ) ;
}
static int F_27 ( struct V_16 * V_16 , struct V_12 * V_18 ,
struct V_45 * V_46 , T_4 V_8 ,
void * V_44 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
struct V_1 * V_23 = V_2 -> V_24 ;
int V_47 ;
F_3 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_7 || ! V_2 -> V_17 ) {
F_5 ( & V_2 -> V_4 ) ;
V_47 = - V_48 ;
goto exit;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_44 = V_44 ;
F_5 ( & V_2 -> V_4 ) ;
F_3 ( & V_23 -> V_4 ) ;
V_23 -> V_9 = F_28 ( V_46 , V_49 ) ;
if ( ! V_23 -> V_9 ) {
F_15 ( V_2 , L_11 ) ;
F_5 ( & V_23 -> V_4 ) ;
V_47 = - V_50 ;
goto exit;
}
F_20 ( V_38 , & V_23 -> V_11 ,
F_29 ( V_2 -> V_51 ) ) ;
F_5 ( & V_23 -> V_4 ) ;
V_47 = 0 ;
exit:
F_4 ( V_46 ) ;
return V_47 ;
}
static int F_30 ( struct V_16 * V_16 ,
struct V_12 * V_18 , struct V_45 * V_46 ,
T_4 V_8 , void * V_44 )
{
return F_27 ( V_16 , V_18 , V_46 , V_8 , V_44 ) ;
}
static int F_31 ( struct V_16 * V_16 , struct V_45 * V_46 )
{
return F_27 ( V_16 , NULL , V_46 , NULL , NULL ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 == V_6 ) {
V_2 -> V_37 = V_6 ;
return;
}
if ( V_2 -> V_37 == V_6 ) {
if ( V_2 -> V_5 & V_34 )
V_2 -> V_37 = V_34 ;
else
V_2 -> V_37 = V_35 ;
return;
}
if ( V_2 -> V_5 == V_52 ) {
if ( V_2 -> V_37 == V_35 )
V_2 -> V_37 = V_34 ;
else
V_2 -> V_37 = V_35 ;
}
}
static void F_33 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_25 ( V_43 , struct V_1 , V_10 . V_43 ) ;
struct V_1 * V_23 = V_2 -> V_24 ;
F_3 ( & V_2 -> V_4 ) ;
F_3 ( & V_23 -> V_4 ) ;
F_32 ( V_2 ) ;
if ( V_2 -> V_37 == V_6 ) {
F_2 ( V_2 , L_12 ) ;
goto V_53;
}
F_2 ( V_2 , L_13 ,
V_2 -> V_37 == V_34 ?
L_14 : L_15 ) ;
if ( V_2 -> V_37 == V_35 )
goto V_54;
if ( V_23 -> V_37 == V_35 ) {
V_23 -> V_5 = V_6 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_36 = 1 ;
F_7 ( V_2 ) ;
goto V_53;
}
V_54:
F_20 ( V_38 , & V_2 -> V_10 , F_29 ( 200 ) ) ;
V_53:
F_5 ( & V_23 -> V_4 ) ;
F_5 ( & V_2 -> V_4 ) ;
}
static struct V_1 * F_34 ( void )
{
struct V_1 * V_2 ;
int V_22 = - V_50 ;
V_2 = F_35 ( sizeof( * V_2 ) , V_49 ) ;
if ( V_2 == NULL )
return F_36 ( - V_50 ) ;
F_37 ( & V_2 -> V_4 ) ;
F_38 ( & V_2 -> V_11 , F_24 ) ;
F_38 ( & V_2 -> V_10 , F_33 ) ;
V_2 -> V_16 = F_39 ( & V_55 ,
V_15 ,
0 , 0 ) ;
if ( ! V_2 -> V_16 )
goto error;
F_40 ( V_2 -> V_16 , V_2 ) ;
V_22 = F_41 ( V_2 -> V_16 ) ;
if ( V_22 )
goto V_56;
V_2 -> V_51 = V_57 ;
return V_2 ;
V_56:
F_42 ( V_2 -> V_16 ) ;
error:
F_43 ( V_2 ) ;
return F_36 ( V_22 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_45 ( V_2 -> V_16 ) ;
F_42 ( V_2 -> V_16 ) ;
F_43 ( V_2 ) ;
}
static int T_5 F_46 ( void )
{
int V_22 ;
V_38 = F_47 ( L_16 , 0 ) ;
if ( ! V_38 ) {
V_22 = - V_50 ;
goto exit;
}
V_58 = F_34 () ;
if ( F_48 ( V_58 ) ) {
V_22 = F_49 ( V_58 ) ;
goto exit;
}
V_59 = F_34 () ;
if ( F_48 ( V_59 ) ) {
F_43 ( V_58 ) ;
V_22 = F_49 ( V_59 ) ;
goto exit;
}
V_58 -> V_24 = V_59 ;
V_59 -> V_24 = V_58 ;
F_50 ( L_17 V_60 L_18 ) ;
V_22 = 0 ;
exit:
if ( V_22 )
F_51 ( L_19 ,
V_22 ) ;
return V_22 ;
}
static void T_6 F_52 ( void )
{
F_1 ( V_58 , 1 ) ;
F_1 ( V_59 , 1 ) ;
F_44 ( V_58 ) ;
F_44 ( V_59 ) ;
F_53 ( V_38 ) ;
}
