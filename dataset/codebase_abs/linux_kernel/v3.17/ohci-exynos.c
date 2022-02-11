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
static int F_19 ( struct V_21 * V_22 )
{
struct V_3 * V_4 ;
struct V_18 * V_19 ;
struct V_23 * V_24 ;
int V_25 ;
int V_26 ;
V_26 = F_20 ( & V_22 -> V_2 , F_21 ( 32 ) ) ;
if ( V_26 )
return V_26 ;
V_19 = F_22 ( & V_27 ,
& V_22 -> V_2 , F_23 ( & V_22 -> V_2 ) ) ;
if ( ! V_19 ) {
F_5 ( & V_22 -> V_2 , L_6 ) ;
return - V_28 ;
}
V_4 = F_13 ( V_19 ) ;
if ( F_24 ( V_22 -> V_2 . V_29 ,
L_7 ) )
goto V_30;
V_26 = F_1 ( & V_22 -> V_2 , V_4 ) ;
if ( V_26 )
goto V_31;
V_30:
V_4 -> V_32 = F_25 ( & V_22 -> V_2 , L_8 ) ;
if ( F_3 ( V_4 -> V_32 ) ) {
F_5 ( & V_22 -> V_2 , L_9 ) ;
V_26 = F_4 ( V_4 -> V_32 ) ;
goto V_31;
}
V_26 = F_26 ( V_4 -> V_32 ) ;
if ( V_26 )
goto V_31;
V_24 = F_27 ( V_22 , V_33 , 0 ) ;
if ( ! V_24 ) {
F_5 ( & V_22 -> V_2 , L_10 ) ;
V_26 = - V_11 ;
goto V_34;
}
V_19 -> V_35 = V_24 -> V_36 ;
V_19 -> V_37 = F_28 ( V_24 ) ;
V_19 -> V_38 = F_29 ( & V_22 -> V_2 , V_24 ) ;
if ( F_3 ( V_19 -> V_38 ) ) {
V_26 = F_4 ( V_19 -> V_38 ) ;
goto V_34;
}
V_25 = F_30 ( V_22 , 0 ) ;
if ( ! V_25 ) {
F_5 ( & V_22 -> V_2 , L_11 ) ;
V_26 = - V_12 ;
goto V_34;
}
if ( V_4 -> V_13 )
V_4 -> V_13 -> V_39 ( V_4 -> V_13 , & V_19 -> V_40 ) ;
F_31 ( V_22 , V_19 ) ;
V_26 = F_11 ( & V_22 -> V_2 ) ;
if ( V_26 ) {
F_5 ( & V_22 -> V_2 , L_12 ) ;
goto V_34;
}
V_26 = F_32 ( V_19 , V_25 , V_41 ) ;
if ( V_26 ) {
F_5 ( & V_22 -> V_2 , L_13 ) ;
goto V_42;
}
F_33 ( V_19 -> V_40 . V_43 ) ;
return 0 ;
V_42:
F_17 ( & V_22 -> V_2 ) ;
V_34:
F_34 ( V_4 -> V_32 ) ;
V_31:
F_35 ( V_19 ) ;
return V_26 ;
}
static int F_36 ( struct V_21 * V_22 )
{
struct V_18 * V_19 = F_37 ( V_22 ) ;
struct V_3 * V_4 = F_13 ( V_19 ) ;
F_38 ( V_19 ) ;
if ( V_4 -> V_13 )
V_4 -> V_13 -> V_39 ( V_4 -> V_13 , & V_19 -> V_40 ) ;
F_17 ( & V_22 -> V_2 ) ;
F_34 ( V_4 -> V_32 ) ;
F_35 ( V_19 ) ;
return 0 ;
}
static void F_39 ( struct V_21 * V_22 )
{
struct V_18 * V_19 = F_37 ( V_22 ) ;
if ( V_19 -> V_44 -> V_45 )
V_19 -> V_44 -> V_45 ( V_19 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_12 ( V_2 ) ;
struct V_3 * V_4 = F_13 ( V_19 ) ;
bool V_46 = F_41 ( V_2 ) ;
int V_47 = F_42 ( V_19 , V_46 ) ;
if ( V_47 )
return V_47 ;
if ( V_4 -> V_13 )
V_4 -> V_13 -> V_39 ( V_4 -> V_13 , & V_19 -> V_40 ) ;
F_17 ( V_2 ) ;
F_34 ( V_4 -> V_32 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_12 ( V_2 ) ;
struct V_3 * V_4 = F_13 ( V_19 ) ;
int V_9 ;
F_26 ( V_4 -> V_32 ) ;
if ( V_4 -> V_13 )
V_4 -> V_13 -> V_39 ( V_4 -> V_13 , & V_19 -> V_40 ) ;
V_9 = F_11 ( V_2 ) ;
if ( V_9 ) {
F_5 ( V_2 , L_12 ) ;
F_34 ( V_4 -> V_32 ) ;
return V_9 ;
}
F_44 ( V_19 , false ) ;
return 0 ;
}
static int T_1 F_45 ( void )
{
if ( F_46 () )
return - V_12 ;
F_47 ( L_14 V_48 L_15 , V_49 ) ;
F_48 ( & V_27 , & V_50 ) ;
return F_49 ( & V_51 ) ;
}
static void T_2 F_50 ( void )
{
F_51 ( & V_51 ) ;
}
