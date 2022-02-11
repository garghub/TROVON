static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_2 -> V_7 ) ; V_6 ++ )
F_3 ( V_4 , V_2 -> V_7 [ V_6 ] ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_2 -> V_7 ) ; V_6 ++ )
F_5 ( V_4 , V_2 -> V_7 [ V_6 ] ) ;
}
static void F_6 ( struct V_8 * V_9 )
{
struct V_1 * V_2 =
F_7 ( V_9 , struct V_1 , V_10 ) ;
struct V_11 * V_12 ;
F_8 ( L_1 ) ;
F_9 (ctx, &mdp->ctx_list, list) {
F_10 ( 0 , L_2 , V_12 -> V_13 ) ;
F_11 ( V_12 , V_14 ) ;
}
}
static void F_12 ( void * V_15 )
{
struct V_1 * V_2 = V_15 ;
F_13 ( V_2 -> V_16 , & V_2 -> V_10 ) ;
}
static int F_14 ( struct V_17 * V_5 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = & V_5 -> V_4 ;
struct V_18 * V_19 ;
int V_6 , V_20 = 0 ;
V_2 = F_15 ( V_4 , sizeof( * V_2 ) , V_21 ) ;
if ( ! V_2 )
return - V_22 ;
V_2 -> V_13 = V_5 -> V_13 ;
V_2 -> V_5 = V_5 ;
F_16 ( & V_2 -> V_23 ) ;
F_17 ( & V_2 -> V_24 ) ;
F_17 ( & V_2 -> V_25 ) ;
F_18 (dev->of_node, node) {
const struct V_26 * V_27 ;
enum V_28 V_29 ;
int V_30 ;
struct V_31 * V_7 ;
V_27 = F_19 ( V_32 , V_19 ) ;
if ( ! V_27 )
continue;
if ( ! F_20 ( V_19 ) ) {
F_21 ( V_4 , L_3 ,
V_19 -> V_33 ) ;
continue;
}
V_29 = (enum V_28 ) V_27 -> V_34 ;
V_30 = F_22 ( V_4 , V_19 , V_29 ) ;
if ( V_30 < 0 ) {
F_23 ( V_4 , L_4 ,
V_19 -> V_33 ) ;
continue;
}
V_7 = F_15 ( V_4 , sizeof( * V_7 ) , V_21 ) ;
if ( ! V_7 ) {
V_20 = - V_22 ;
goto V_35;
}
V_2 -> V_7 [ V_30 ] = V_7 ;
V_20 = F_24 ( V_4 , V_19 , V_7 , V_30 ) ;
if ( V_20 )
goto V_35;
}
V_2 -> V_36 = F_25 ( V_37 ) ;
if ( ! V_2 -> V_36 ) {
F_21 ( & V_5 -> V_4 , L_5 ) ;
V_20 = - V_22 ;
goto V_38;
}
V_2 -> V_16 = F_25 ( L_6 ) ;
if ( ! V_2 -> V_16 ) {
F_21 ( & V_5 -> V_4 , L_7 ) ;
V_20 = - V_22 ;
goto V_39;
}
F_26 ( & V_2 -> V_10 , F_6 ) ;
V_20 = F_27 ( V_4 , & V_2 -> V_40 ) ;
if ( V_20 ) {
F_21 ( & V_5 -> V_4 , L_8 ) ;
V_20 = - V_41 ;
goto V_42;
}
V_20 = F_28 ( V_2 ) ;
if ( V_20 ) {
F_29 ( & V_2 -> V_40 , L_9 ) ;
goto V_43;
}
V_2 -> V_44 = F_30 ( V_5 ) ;
F_31 ( V_2 -> V_44 , F_12 , V_2 ,
V_45 ) ;
F_32 ( V_5 , V_2 ) ;
F_33 ( & V_5 -> V_4 , F_34 ( 32 ) ) ;
F_35 ( V_4 ) ;
F_36 ( V_4 , L_10 , V_2 -> V_13 ) ;
return 0 ;
V_43:
F_37 ( & V_2 -> V_40 ) ;
V_42:
F_38 ( V_2 -> V_16 ) ;
V_39:
F_38 ( V_2 -> V_36 ) ;
V_38:
V_35:
for ( V_6 = 0 ; V_6 < F_2 ( V_2 -> V_7 ) ; V_6 ++ )
F_39 ( V_4 , V_2 -> V_7 [ V_6 ] ) ;
F_36 ( V_4 , L_11 , V_20 ) ;
return V_20 ;
}
static int F_40 ( struct V_17 * V_5 )
{
struct V_1 * V_2 = F_41 ( V_5 ) ;
int V_6 ;
F_42 ( & V_5 -> V_4 ) ;
F_43 ( & V_5 -> V_4 ) ;
F_44 ( V_2 ) ;
F_37 ( & V_2 -> V_40 ) ;
F_45 ( V_2 -> V_36 ) ;
F_38 ( V_2 -> V_36 ) ;
for ( V_6 = 0 ; V_6 < F_2 ( V_2 -> V_7 ) ; V_6 ++ )
F_39 ( & V_5 -> V_4 , V_2 -> V_7 [ V_6 ] ) ;
F_36 ( & V_5 -> V_4 , L_12 , V_5 -> V_46 ) ;
return 0 ;
}
static int T_1 F_46 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_47 ( V_4 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int T_1 F_48 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_47 ( V_4 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int T_1 F_49 ( struct V_3 * V_4 )
{
if ( F_50 ( V_4 ) )
return 0 ;
return F_46 ( V_4 ) ;
}
static int T_1 F_51 ( struct V_3 * V_4 )
{
if ( F_50 ( V_4 ) )
return 0 ;
return F_48 ( V_4 ) ;
}
