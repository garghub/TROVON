static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
F_2 ( V_2 -> V_4 , L_1 ,
V_5 , F_3 ( V_2 ) ) ;
F_4 ( V_2 -> V_1 -> V_6 ) ;
F_4 ( V_2 -> V_1 ) ;
F_4 ( V_2 ) ;
}
static int F_5 ( struct V_7 * V_4 )
{
struct V_2 * V_2 ;
struct V_1 * V_1 ;
struct V_8 * V_6 ;
char V_9 [ V_10 ] ;
int V_11 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_13 ; V_12 ++ ) {
V_2 = F_6 ( sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 ) {
V_11 = - V_15 ;
goto error;
}
V_1 = F_6 ( sizeof( * V_1 ) , V_14 ) ;
if ( ! V_1 ) {
V_11 = - V_15 ;
goto V_16;
}
V_2 -> V_1 = V_1 ;
V_6 = F_6 ( sizeof( * V_6 ) , V_14 ) ;
if ( ! V_6 ) {
V_11 = - V_15 ;
goto V_17;
}
V_1 -> V_6 = V_6 ;
V_2 -> V_18 = V_12 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_19 = V_4 -> V_20 -> V_21 -> V_22 ;
V_2 -> V_23 = V_4 -> V_24 + V_12 ;
V_2 -> V_25 = V_4 -> V_25 ;
V_2 -> V_22 = V_4 -> V_26 + ( V_4 -> V_27 * V_12 ) ;
V_2 -> V_28 = F_7 ( L_2 , 0 , 0 , V_2 -> V_22 ) ;
if ( ! V_2 -> V_28 ) {
V_11 = - V_15 ;
goto V_29;
}
F_8 ( & V_2 -> V_30 ) ;
F_9 ( & V_2 -> V_31 , V_32 ) ;
V_1 -> V_3 = V_2 ;
V_1 -> V_33 = & F_1 ;
snprintf ( V_9 , V_10 , L_3 , V_2 -> V_22 ) ;
V_1 -> V_34 = & V_35 ;
F_2 ( V_4 , L_4
L_5 ,
F_10 ( V_4 -> V_20 -> V_21 ) ,
V_2 -> V_19 , V_2 -> V_23 , V_2 -> V_18 , V_2 -> V_22 ,
V_4 -> V_24 ) ;
V_11 = F_11 ( V_2 -> V_1 ,
V_4 -> V_20 -> V_21 , V_2 -> V_23 , V_9 ) ;
if ( V_11 ) {
F_12 ( V_4 , L_6 ,
V_11 ) ;
goto V_36;
}
F_13 ( V_1 , & V_6 -> V_37 ) ;
F_14 ( V_1 , & V_6 -> V_38 ) ;
F_15 ( V_1 , & V_6 -> V_39 ) ;
F_16 ( V_1 , & V_6 -> V_40 ) ;
F_17 ( & V_2 -> V_41 , & V_4 -> V_41 ) ;
}
return 0 ;
V_36:
F_18 ( V_2 -> V_28 ) ;
V_29:
F_4 ( V_6 ) ;
V_17:
F_4 ( V_1 ) ;
V_16:
F_4 ( V_2 ) ;
error:
return V_11 ;
}
void F_19 ( struct V_7 * V_4 )
{
struct V_42 * V_43 ;
struct V_42 * V_44 ;
struct V_2 * V_2 ;
F_20 (tmp, next, &ctrl->slot_list) {
V_2 = F_21 ( V_43 , struct V_2 , V_41 ) ;
F_22 ( & V_2 -> V_41 ) ;
F_23 ( & V_2 -> V_31 ) ;
F_18 ( V_2 -> V_28 ) ;
F_24 ( V_2 -> V_1 ) ;
}
}
static int F_25 ( struct V_1 * V_1 , T_1 V_45 )
{
struct V_2 * V_2 = F_26 ( V_1 ) ;
F_2 ( V_2 -> V_4 , L_1 ,
V_5 , F_3 ( V_2 ) ) ;
V_1 -> V_6 -> V_38 = V_45 ;
V_2 -> V_25 -> F_25 ( V_2 , V_45 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = F_26 ( V_1 ) ;
F_2 ( V_2 -> V_4 , L_1 ,
V_5 , F_3 ( V_2 ) ) ;
return F_28 ( V_2 ) ;
}
static int F_29 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = F_26 ( V_1 ) ;
F_2 ( V_2 -> V_4 , L_1 ,
V_5 , F_3 ( V_2 ) ) ;
return F_30 ( V_2 ) ;
}
static int F_13 ( struct V_1 * V_1 , T_1 * V_46 )
{
struct V_2 * V_2 = F_26 ( V_1 ) ;
int V_11 ;
F_2 ( V_2 -> V_4 , L_1 ,
V_5 , F_3 ( V_2 ) ) ;
V_11 = V_2 -> V_25 -> F_13 ( V_2 , V_46 ) ;
if ( V_11 < 0 )
* V_46 = V_1 -> V_6 -> V_37 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 , T_1 * V_46 )
{
struct V_2 * V_2 = F_26 ( V_1 ) ;
int V_11 ;
F_2 ( V_2 -> V_4 , L_1 ,
V_5 , F_3 ( V_2 ) ) ;
V_11 = V_2 -> V_25 -> F_14 ( V_2 , V_46 ) ;
if ( V_11 < 0 )
* V_46 = V_1 -> V_6 -> V_38 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_1 , T_1 * V_46 )
{
struct V_2 * V_2 = F_26 ( V_1 ) ;
int V_11 ;
F_2 ( V_2 -> V_4 , L_1 ,
V_5 , F_3 ( V_2 ) ) ;
V_11 = V_2 -> V_25 -> F_15 ( V_2 , V_46 ) ;
if ( V_11 < 0 )
* V_46 = V_1 -> V_6 -> V_39 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_1 , T_1 * V_46 )
{
struct V_2 * V_2 = F_26 ( V_1 ) ;
int V_11 ;
F_2 ( V_2 -> V_4 , L_1 ,
V_5 , F_3 ( V_2 ) ) ;
V_11 = V_2 -> V_25 -> F_16 ( V_2 , V_46 ) ;
if ( V_11 < 0 )
* V_46 = V_1 -> V_6 -> V_40 ;
return 0 ;
}
static int F_31 ( struct V_20 * V_47 )
{
if ( V_47 -> V_48 == V_49 &&
V_47 -> V_23 == V_50 )
return 1 ;
if ( ! F_32 ( V_47 , V_51 ) )
return 0 ;
if ( F_33 ( V_47 ) )
return 0 ;
return 1 ;
}
static int F_34 ( struct V_20 * V_52 , const struct V_53 * V_54 )
{
int V_55 ;
struct V_7 * V_4 ;
if ( ! F_31 ( V_52 ) )
return - V_56 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 ) {
F_35 ( & V_52 -> V_47 , L_7 , V_5 ) ;
goto V_57;
}
F_36 ( & V_4 -> V_41 ) ;
V_55 = F_37 ( V_4 , V_52 ) ;
if ( V_55 ) {
F_2 ( V_4 , L_8 ) ;
goto V_58;
}
F_38 ( V_52 , V_4 ) ;
V_55 = F_5 ( V_4 ) ;
if ( V_55 ) {
F_12 ( V_4 , L_9 ) ;
goto V_59;
}
V_55 = F_39 ( V_4 ) ;
if ( V_55 )
goto V_60;
return 0 ;
V_60:
F_19 ( V_4 ) ;
V_59:
V_4 -> V_25 -> V_61 ( V_4 ) ;
V_58:
F_4 ( V_4 ) ;
V_57:
return - V_56 ;
}
static void F_40 ( struct V_20 * V_47 )
{
struct V_7 * V_4 = F_41 ( V_47 ) ;
F_42 ( V_4 ) ;
V_4 -> V_25 -> V_61 ( V_4 ) ;
F_4 ( V_4 ) ;
}
static int T_2 F_43 ( void )
{
int V_11 ;
V_11 = F_44 ( & V_62 ) ;
F_45 ( L_10 , V_5 , V_11 ) ;
V_6 ( V_63 L_11 V_64 L_12 ) ;
return V_11 ;
}
static void T_3 F_46 ( void )
{
F_45 ( L_13 ) ;
F_47 ( & V_62 ) ;
V_6 ( V_63 L_11 V_64 L_14 ) ;
}
