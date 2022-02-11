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
F_2 ( V_4 , L_4 ,
F_10 ( V_4 -> V_20 -> V_21 ) ,
V_2 -> V_19 , V_2 -> V_23 , V_2 -> V_18 , V_2 -> V_22 ,
V_4 -> V_24 ) ;
V_11 = F_11 ( V_2 -> V_1 ,
V_4 -> V_20 -> V_21 , V_2 -> V_23 , V_9 ) ;
if ( V_11 ) {
F_12 ( V_4 , L_5 ,
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
struct V_2 * V_2 , * V_42 ;
F_20 (slot, next, &ctrl->slot_list, slot_list) {
F_21 ( & V_2 -> V_41 ) ;
F_22 ( & V_2 -> V_31 ) ;
F_18 ( V_2 -> V_28 ) ;
F_23 ( V_2 -> V_1 ) ;
}
}
static int F_24 ( struct V_1 * V_1 , T_1 V_43 )
{
struct V_2 * V_2 = F_25 ( V_1 ) ;
F_2 ( V_2 -> V_4 , L_1 ,
V_5 , F_3 ( V_2 ) ) ;
V_1 -> V_6 -> V_38 = V_43 ;
V_2 -> V_25 -> F_24 ( V_2 , V_43 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = F_25 ( V_1 ) ;
F_2 ( V_2 -> V_4 , L_1 ,
V_5 , F_3 ( V_2 ) ) ;
return F_27 ( V_2 ) ;
}
static int F_28 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = F_25 ( V_1 ) ;
F_2 ( V_2 -> V_4 , L_1 ,
V_5 , F_3 ( V_2 ) ) ;
return F_29 ( V_2 ) ;
}
static int F_13 ( struct V_1 * V_1 , T_1 * V_44 )
{
struct V_2 * V_2 = F_25 ( V_1 ) ;
int V_11 ;
F_2 ( V_2 -> V_4 , L_1 ,
V_5 , F_3 ( V_2 ) ) ;
V_11 = V_2 -> V_25 -> F_13 ( V_2 , V_44 ) ;
if ( V_11 < 0 )
* V_44 = V_1 -> V_6 -> V_37 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 , T_1 * V_44 )
{
struct V_2 * V_2 = F_25 ( V_1 ) ;
int V_11 ;
F_2 ( V_2 -> V_4 , L_1 ,
V_5 , F_3 ( V_2 ) ) ;
V_11 = V_2 -> V_25 -> F_14 ( V_2 , V_44 ) ;
if ( V_11 < 0 )
* V_44 = V_1 -> V_6 -> V_38 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_1 , T_1 * V_44 )
{
struct V_2 * V_2 = F_25 ( V_1 ) ;
int V_11 ;
F_2 ( V_2 -> V_4 , L_1 ,
V_5 , F_3 ( V_2 ) ) ;
V_11 = V_2 -> V_25 -> F_15 ( V_2 , V_44 ) ;
if ( V_11 < 0 )
* V_44 = V_1 -> V_6 -> V_39 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_1 , T_1 * V_44 )
{
struct V_2 * V_2 = F_25 ( V_1 ) ;
int V_11 ;
F_2 ( V_2 -> V_4 , L_1 ,
V_5 , F_3 ( V_2 ) ) ;
V_11 = V_2 -> V_25 -> F_16 ( V_2 , V_44 ) ;
if ( V_11 < 0 )
* V_44 = V_1 -> V_6 -> V_40 ;
return 0 ;
}
static int F_30 ( struct V_20 * V_45 )
{
if ( V_45 -> V_46 == V_47 &&
V_45 -> V_23 == V_48 )
return 1 ;
if ( ! F_31 ( V_45 , V_49 ) )
return 0 ;
if ( F_32 ( V_45 ) )
return 0 ;
return 1 ;
}
static int F_33 ( struct V_20 * V_50 , const struct V_51 * V_52 )
{
int V_53 ;
struct V_7 * V_4 ;
if ( ! F_30 ( V_50 ) )
return - V_54 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 ) {
F_34 ( & V_50 -> V_45 , L_6 , V_5 ) ;
goto V_55;
}
F_35 ( & V_4 -> V_41 ) ;
V_53 = F_36 ( V_4 , V_50 ) ;
if ( V_53 ) {
F_2 ( V_4 , L_7 ) ;
goto V_56;
}
F_37 ( V_50 , V_4 ) ;
V_53 = F_5 ( V_4 ) ;
if ( V_53 ) {
F_12 ( V_4 , L_8 ) ;
goto V_57;
}
V_53 = F_38 ( V_4 ) ;
if ( V_53 )
goto V_58;
return 0 ;
V_58:
F_19 ( V_4 ) ;
V_57:
V_4 -> V_25 -> V_59 ( V_4 ) ;
V_56:
F_4 ( V_4 ) ;
V_55:
return - V_54 ;
}
static void F_39 ( struct V_20 * V_45 )
{
struct V_7 * V_4 = F_40 ( V_45 ) ;
F_41 ( V_4 ) ;
V_4 -> V_25 -> V_59 ( V_4 ) ;
F_4 ( V_4 ) ;
}
static int T_2 F_42 ( void )
{
int V_11 ;
V_11 = F_43 ( & V_60 ) ;
F_44 ( L_9 , V_5 , V_11 ) ;
V_6 ( V_61 L_10 V_62 L_11 ) ;
return V_11 ;
}
static void T_3 F_45 ( void )
{
F_44 ( L_12 ) ;
F_46 ( & V_60 ) ;
V_6 ( V_61 L_10 V_62 L_13 ) ;
}
