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
if ( F_7 ( V_7 ) ) {
V_9 = F_8 ( V_7 ) ;
if ( V_9 == - V_12 ) {
F_5 ( V_6 ) ;
return V_9 ;
} else if ( V_9 != - V_13 && V_9 != - V_14 ) {
F_4 ( V_2 ,
L_4 , V_9 ) ;
F_5 ( V_6 ) ;
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
static int F_15 ( struct V_18 * V_19 )
{
struct V_3 * V_4 ;
struct V_15 * V_16 ;
struct V_20 * V_21 ;
int V_22 ;
int V_23 ;
V_23 = F_16 ( & V_19 -> V_2 , F_17 ( 32 ) ) ;
if ( V_23 )
return V_23 ;
V_16 = F_18 ( & V_24 ,
& V_19 -> V_2 , F_19 ( & V_19 -> V_2 ) ) ;
if ( ! V_16 ) {
F_4 ( & V_19 -> V_2 , L_5 ) ;
return - V_25 ;
}
V_4 = F_11 ( V_16 ) ;
if ( F_20 ( V_19 -> V_2 . V_26 ,
L_6 ) )
goto V_27;
V_23 = F_1 ( & V_19 -> V_2 , V_4 ) ;
if ( V_23 )
goto V_28;
V_27:
V_4 -> V_29 = F_21 ( & V_19 -> V_2 , L_7 ) ;
if ( F_7 ( V_4 -> V_29 ) ) {
F_4 ( & V_19 -> V_2 , L_8 ) ;
V_23 = F_8 ( V_4 -> V_29 ) ;
goto V_28;
}
V_23 = F_22 ( V_4 -> V_29 ) ;
if ( V_23 )
goto V_28;
V_21 = F_23 ( V_19 , V_30 , 0 ) ;
V_16 -> V_31 = F_24 ( & V_19 -> V_2 , V_21 ) ;
if ( F_7 ( V_16 -> V_31 ) ) {
V_23 = F_8 ( V_16 -> V_31 ) ;
goto V_32;
}
V_16 -> V_33 = V_21 -> V_34 ;
V_16 -> V_35 = F_25 ( V_21 ) ;
V_22 = F_26 ( V_19 , 0 ) ;
if ( ! V_22 ) {
F_4 ( & V_19 -> V_2 , L_9 ) ;
V_23 = - V_14 ;
goto V_32;
}
F_27 ( V_19 , V_16 ) ;
V_23 = F_9 ( & V_19 -> V_2 ) ;
if ( V_23 ) {
F_4 ( & V_19 -> V_2 , L_10 ) ;
goto V_32;
}
V_23 = F_28 ( V_16 , V_22 , V_36 ) ;
if ( V_23 ) {
F_4 ( & V_19 -> V_2 , L_11 ) ;
goto V_37;
}
F_29 ( V_16 -> V_38 . V_39 ) ;
return 0 ;
V_37:
F_14 ( & V_19 -> V_2 ) ;
V_32:
F_30 ( V_4 -> V_29 ) ;
V_28:
F_31 ( V_16 ) ;
return V_23 ;
}
static int F_32 ( struct V_18 * V_19 )
{
struct V_15 * V_16 = F_33 ( V_19 ) ;
struct V_3 * V_4 = F_11 ( V_16 ) ;
F_34 ( V_16 ) ;
F_14 ( & V_19 -> V_2 ) ;
F_30 ( V_4 -> V_29 ) ;
F_31 ( V_16 ) ;
return 0 ;
}
static void F_35 ( struct V_18 * V_19 )
{
struct V_15 * V_16 = F_33 ( V_19 ) ;
if ( V_16 -> V_40 -> V_41 )
V_16 -> V_40 -> V_41 ( V_16 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_3 * V_4 = F_11 ( V_16 ) ;
bool V_42 = F_37 ( V_2 ) ;
int V_43 = F_38 ( V_16 , V_42 ) ;
if ( V_43 )
return V_43 ;
F_14 ( V_2 ) ;
F_30 ( V_4 -> V_29 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_10 ( V_2 ) ;
struct V_3 * V_4 = F_11 ( V_16 ) ;
int V_9 ;
F_22 ( V_4 -> V_29 ) ;
V_9 = F_9 ( V_2 ) ;
if ( V_9 ) {
F_4 ( V_2 , L_10 ) ;
F_30 ( V_4 -> V_29 ) ;
return V_9 ;
}
F_40 ( V_16 , false ) ;
return 0 ;
}
static int T_1 F_41 ( void )
{
if ( F_42 () )
return - V_14 ;
F_43 ( L_12 V_44 L_13 , V_45 ) ;
F_44 ( & V_24 , & V_46 ) ;
return F_45 ( & V_47 ) ;
}
static void T_2 F_46 ( void )
{
F_47 ( & V_47 ) ;
}
