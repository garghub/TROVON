static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_7 ;
int V_8 ;
int V_9 = 0 ;
V_4 -> V_7 = F_2 ( V_2 , V_10 ) ;
if ( F_3 ( V_4 -> V_7 ) ) {
V_9 = F_4 ( V_4 -> V_7 ) ;
if ( V_9 != - V_11 && V_9 != - V_12 ) {
F_5 ( V_2 , L_1 ) ;
return V_9 ;
}
F_6 ( V_2 , L_2 ) ;
} else {
V_4 -> V_13 = V_4 -> V_7 -> V_13 ;
}
F_7 (dev->of_node, child) {
V_9 = F_8 ( V_6 , L_3 , & V_8 ) ;
if ( V_9 ) {
F_5 ( V_2 , L_4 ) ;
F_9 ( V_6 ) ;
return V_9 ;
}
if ( V_8 >= V_14 ) {
F_5 ( V_2 , L_5 ) ;
F_9 ( V_6 ) ;
return - V_15 ;
}
V_7 = F_10 ( V_2 , V_6 , NULL ) ;
F_9 ( V_6 ) ;
if ( F_3 ( V_7 ) ) {
V_9 = F_4 ( V_7 ) ;
if ( V_9 != - V_16 && V_9 != - V_12 ) {
F_5 ( V_2 , L_1 ) ;
return V_9 ;
}
F_6 ( V_2 , L_2 ) ;
}
V_4 -> V_17 [ V_8 ] = V_7 ;
}
return V_9 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_12 ( V_2 ) ;
struct V_3 * V_4 = F_13 ( V_19 ) ;
int V_20 ;
int V_9 = 0 ;
if ( ! F_3 ( V_4 -> V_7 ) )
return F_14 ( V_4 -> V_7 ) ;
for ( V_20 = 0 ; V_9 == 0 && V_20 < V_14 ; V_20 ++ )
if ( ! F_3 ( V_4 -> V_17 [ V_20 ] ) )
V_9 = F_15 ( V_4 -> V_17 [ V_20 ] ) ;
if ( V_9 )
for ( V_20 -- ; V_20 >= 0 ; V_20 -- )
if ( ! F_3 ( V_4 -> V_17 [ V_20 ] ) )
F_16 ( V_4 -> V_17 [ V_20 ] ) ;
return V_9 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_12 ( V_2 ) ;
struct V_3 * V_4 = F_13 ( V_19 ) ;
int V_20 ;
if ( ! F_3 ( V_4 -> V_7 ) ) {
F_18 ( V_4 -> V_7 ) ;
return;
}
for ( V_20 = 0 ; V_20 < V_14 ; V_20 ++ )
if ( ! F_3 ( V_4 -> V_17 [ V_20 ] ) )
F_16 ( V_4 -> V_17 [ V_20 ] ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_21 ;
int V_22 ;
if ( ! V_2 -> V_23 )
return;
V_22 = F_20 ( V_2 -> V_23 , L_6 , 0 ) ;
if ( ! F_21 ( V_22 ) )
return;
V_21 = F_22 ( V_2 , V_22 , V_24 ,
L_7 ) ;
if ( V_21 )
F_5 ( V_2 , L_8 , V_22 ) ;
}
static int F_23 ( struct V_25 * V_26 )
{
struct V_3 * V_4 ;
struct V_18 * V_19 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
int V_31 ;
int V_21 ;
V_21 = F_24 ( & V_26 -> V_2 , F_25 ( 32 ) ) ;
if ( V_21 )
return V_21 ;
F_19 ( & V_26 -> V_2 ) ;
V_19 = F_26 ( & V_32 ,
& V_26 -> V_2 , F_27 ( & V_26 -> V_2 ) ) ;
if ( ! V_19 ) {
F_5 ( & V_26 -> V_2 , L_9 ) ;
return - V_33 ;
}
V_4 = F_13 ( V_19 ) ;
if ( F_28 ( V_26 -> V_2 . V_23 ,
L_10 ) )
goto V_34;
V_21 = F_1 ( & V_26 -> V_2 , V_4 ) ;
if ( V_21 )
goto V_35;
V_34:
V_4 -> V_36 = F_29 ( & V_26 -> V_2 , L_11 ) ;
if ( F_3 ( V_4 -> V_36 ) ) {
F_5 ( & V_26 -> V_2 , L_12 ) ;
V_21 = F_4 ( V_4 -> V_36 ) ;
goto V_35;
}
V_21 = F_30 ( V_4 -> V_36 ) ;
if ( V_21 )
goto V_35;
V_30 = F_31 ( V_26 , V_37 , 0 ) ;
if ( ! V_30 ) {
F_5 ( & V_26 -> V_2 , L_13 ) ;
V_21 = - V_11 ;
goto V_38;
}
V_19 -> V_39 = V_30 -> V_40 ;
V_19 -> V_41 = F_32 ( V_30 ) ;
V_19 -> V_42 = F_33 ( & V_26 -> V_2 , V_30 ) ;
if ( F_3 ( V_19 -> V_42 ) ) {
V_21 = F_4 ( V_19 -> V_42 ) ;
goto V_38;
}
V_31 = F_34 ( V_26 , 0 ) ;
if ( ! V_31 ) {
F_5 ( & V_26 -> V_2 , L_14 ) ;
V_21 = - V_12 ;
goto V_38;
}
if ( V_4 -> V_13 )
V_4 -> V_13 -> V_43 ( V_4 -> V_13 , & V_19 -> V_44 ) ;
V_21 = F_11 ( & V_26 -> V_2 ) ;
if ( V_21 ) {
F_5 ( & V_26 -> V_2 , L_15 ) ;
goto V_38;
}
V_28 = F_35 ( V_19 ) ;
V_28 -> V_45 = V_19 -> V_42 ;
F_36 ( V_46 , F_37 ( V_19 -> V_42 ) ) ;
V_21 = F_38 ( V_19 , V_31 , V_47 ) ;
if ( V_21 ) {
F_5 ( & V_26 -> V_2 , L_16 ) ;
goto V_48;
}
F_39 ( V_19 -> V_44 . V_49 ) ;
F_40 ( V_26 , V_19 ) ;
return 0 ;
V_48:
F_17 ( & V_26 -> V_2 ) ;
V_38:
F_41 ( V_4 -> V_36 ) ;
V_35:
F_42 ( V_19 ) ;
return V_21 ;
}
static int F_43 ( struct V_25 * V_26 )
{
struct V_18 * V_19 = F_44 ( V_26 ) ;
struct V_3 * V_4 = F_13 ( V_19 ) ;
F_45 ( V_19 ) ;
if ( V_4 -> V_13 )
V_4 -> V_13 -> V_43 ( V_4 -> V_13 , & V_19 -> V_44 ) ;
F_17 ( & V_26 -> V_2 ) ;
F_41 ( V_4 -> V_36 ) ;
F_42 ( V_19 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_12 ( V_2 ) ;
struct V_3 * V_4 = F_13 ( V_19 ) ;
bool V_50 = F_47 ( V_2 ) ;
int V_51 ;
V_51 = F_48 ( V_19 , V_50 ) ;
if ( V_51 )
return V_51 ;
if ( V_4 -> V_13 )
V_4 -> V_13 -> V_43 ( V_4 -> V_13 , & V_19 -> V_44 ) ;
F_17 ( V_2 ) ;
F_41 ( V_4 -> V_36 ) ;
return V_51 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_12 ( V_2 ) ;
struct V_3 * V_4 = F_13 ( V_19 ) ;
int V_9 ;
F_30 ( V_4 -> V_36 ) ;
if ( V_4 -> V_13 )
V_4 -> V_13 -> V_43 ( V_4 -> V_13 , & V_19 -> V_44 ) ;
V_9 = F_11 ( V_2 ) ;
if ( V_9 ) {
F_5 ( V_2 , L_15 ) ;
F_41 ( V_4 -> V_36 ) ;
return V_9 ;
}
F_36 ( V_46 , F_37 ( V_19 -> V_42 ) ) ;
F_50 ( V_19 , false ) ;
return 0 ;
}
static int T_1 F_51 ( void )
{
if ( F_52 () )
return - V_12 ;
F_53 ( L_17 V_52 L_18 , V_53 ) ;
F_54 ( & V_32 , & V_54 ) ;
return F_55 ( & V_55 ) ;
}
static void T_2 F_56 ( void )
{
F_57 ( & V_55 ) ;
}
