static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_7 ;
int V_8 ;
int V_9 ;
F_2 (dev->of_node, child) {
V_9 = F_3 ( V_6 , L_1 , & V_8 ) ;
if ( V_9 ) {
F_4 ( V_2 , L_2 ) ;
F_5 ( V_6 ) ;
return V_9 ;
}
if ( V_8 >= V_10 ) {
F_4 ( V_2 , L_3 ) ;
F_5 ( V_6 ) ;
return - V_11 ;
}
V_7 = F_6 ( V_2 , V_6 , NULL ) ;
V_4 -> V_7 [ V_8 ] = V_7 ;
F_5 ( V_6 ) ;
if ( F_7 ( V_7 ) ) {
V_9 = F_8 ( V_7 ) ;
if ( V_9 == - V_12 ) {
return V_9 ;
} else if ( V_9 != - V_13 && V_9 != - V_14 ) {
F_4 ( V_2 ,
L_4 , V_9 ) ;
return V_9 ;
}
}
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_3 * V_4 = F_11 ( V_16 ) ;
int V_17 ;
int V_9 = 0 ;
for ( V_17 = 0 ; V_9 == 0 && V_17 < V_10 ; V_17 ++ )
if ( ! F_7 ( V_4 -> V_7 [ V_17 ] ) )
V_9 = F_12 ( V_4 -> V_7 [ V_17 ] ) ;
if ( V_9 )
for ( V_17 -- ; V_17 >= 0 ; V_17 -- )
if ( ! F_7 ( V_4 -> V_7 [ V_17 ] ) )
F_13 ( V_4 -> V_7 [ V_17 ] ) ;
return V_9 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_3 * V_4 = F_11 ( V_16 ) ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_10 ; V_17 ++ )
if ( ! F_7 ( V_4 -> V_7 [ V_17 ] ) )
F_13 ( V_4 -> V_7 [ V_17 ] ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
int V_18 ;
int V_19 ;
if ( ! V_2 -> V_20 )
return;
V_19 = F_16 ( V_2 -> V_20 , L_5 , 0 ) ;
if ( ! F_17 ( V_19 ) )
return;
V_18 = F_18 ( V_2 , V_19 , V_21 ,
L_6 ) ;
if ( V_18 )
F_4 ( V_2 , L_7 , V_19 ) ;
}
static int F_19 ( struct V_22 * V_23 )
{
struct V_3 * V_4 ;
struct V_15 * V_16 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_28 ;
int V_18 ;
V_18 = F_20 ( & V_23 -> V_2 , F_21 ( 32 ) ) ;
if ( V_18 )
return V_18 ;
F_15 ( & V_23 -> V_2 ) ;
V_16 = F_22 ( & V_29 ,
& V_23 -> V_2 , F_23 ( & V_23 -> V_2 ) ) ;
if ( ! V_16 ) {
F_4 ( & V_23 -> V_2 , L_8 ) ;
return - V_30 ;
}
V_4 = F_11 ( V_16 ) ;
if ( F_24 ( V_23 -> V_2 . V_20 ,
L_9 ) )
goto V_31;
V_18 = F_1 ( & V_23 -> V_2 , V_4 ) ;
if ( V_18 )
goto V_32;
V_31:
V_4 -> V_33 = F_25 ( & V_23 -> V_2 , L_10 ) ;
if ( F_7 ( V_4 -> V_33 ) ) {
F_4 ( & V_23 -> V_2 , L_11 ) ;
V_18 = F_8 ( V_4 -> V_33 ) ;
goto V_32;
}
V_18 = F_26 ( V_4 -> V_33 ) ;
if ( V_18 )
goto V_32;
V_27 = F_27 ( V_23 , V_34 , 0 ) ;
if ( ! V_27 ) {
F_4 ( & V_23 -> V_2 , L_12 ) ;
V_18 = - V_35 ;
goto V_36;
}
V_16 -> V_37 = V_27 -> V_38 ;
V_16 -> V_39 = F_28 ( V_27 ) ;
V_16 -> V_40 = F_29 ( & V_23 -> V_2 , V_27 ) ;
if ( F_7 ( V_16 -> V_40 ) ) {
V_18 = F_8 ( V_16 -> V_40 ) ;
goto V_36;
}
V_28 = F_30 ( V_23 , 0 ) ;
if ( ! V_28 ) {
F_4 ( & V_23 -> V_2 , L_13 ) ;
V_18 = - V_14 ;
goto V_36;
}
V_18 = F_9 ( & V_23 -> V_2 ) ;
if ( V_18 ) {
F_4 ( & V_23 -> V_2 , L_14 ) ;
goto V_36;
}
V_25 = F_31 ( V_16 ) ;
V_25 -> V_41 = V_16 -> V_40 ;
F_32 ( V_42 , F_33 ( V_16 -> V_40 ) ) ;
V_18 = F_34 ( V_16 , V_28 , V_43 ) ;
if ( V_18 ) {
F_4 ( & V_23 -> V_2 , L_15 ) ;
goto V_44;
}
F_35 ( V_16 -> V_45 . V_46 ) ;
F_36 ( V_23 , V_16 ) ;
return 0 ;
V_44:
F_14 ( & V_23 -> V_2 ) ;
V_36:
F_37 ( V_4 -> V_33 ) ;
V_32:
F_38 ( V_16 ) ;
return V_18 ;
}
static int F_39 ( struct V_22 * V_23 )
{
struct V_15 * V_16 = F_40 ( V_23 ) ;
struct V_3 * V_4 = F_11 ( V_16 ) ;
F_41 ( V_16 ) ;
F_14 ( & V_23 -> V_2 ) ;
F_37 ( V_4 -> V_33 ) ;
F_38 ( V_16 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_3 * V_4 = F_11 ( V_16 ) ;
bool V_47 = F_43 ( V_2 ) ;
int V_48 ;
V_48 = F_44 ( V_16 , V_47 ) ;
if ( V_48 )
return V_48 ;
F_14 ( V_2 ) ;
F_37 ( V_4 -> V_33 ) ;
return V_48 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_3 * V_4 = F_11 ( V_16 ) ;
int V_9 ;
F_26 ( V_4 -> V_33 ) ;
V_9 = F_9 ( V_2 ) ;
if ( V_9 ) {
F_4 ( V_2 , L_14 ) ;
F_37 ( V_4 -> V_33 ) ;
return V_9 ;
}
F_32 ( V_42 , F_33 ( V_16 -> V_40 ) ) ;
F_46 ( V_16 , false ) ;
return 0 ;
}
static int T_1 F_47 ( void )
{
if ( F_48 () )
return - V_14 ;
F_49 ( L_16 V_49 L_17 , V_50 ) ;
F_50 ( & V_29 , & V_51 ) ;
return F_51 ( & V_52 ) ;
}
static void T_2 F_52 ( void )
{
F_53 ( & V_52 ) ;
}
