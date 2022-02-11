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
struct V_18 * V_19 , * V_20 ;
int V_6 , V_21 = 0 ;
V_2 = F_15 ( V_4 , sizeof( * V_2 ) , V_22 ) ;
if ( ! V_2 )
return - V_23 ;
V_2 -> V_13 = V_5 -> V_13 ;
V_2 -> V_5 = V_5 ;
F_16 ( & V_2 -> V_24 ) ;
F_17 ( & V_2 -> V_25 ) ;
F_17 ( & V_2 -> V_26 ) ;
if ( F_18 ( V_4 -> V_27 , NULL ) ) {
V_20 = V_4 -> V_27 ;
F_19 ( V_4 , L_3 ) ;
} else {
V_20 = V_4 -> V_27 -> V_20 ;
}
F_20 (parent, node) {
const struct V_28 * V_29 ;
enum V_30 V_31 ;
int V_32 ;
struct V_33 * V_7 ;
V_29 = F_21 ( V_34 , V_19 ) ;
if ( ! V_29 )
continue;
if ( ! F_22 ( V_19 ) ) {
F_23 ( V_4 , L_4 ,
V_19 -> V_35 ) ;
continue;
}
V_31 = (enum V_30 ) V_29 -> V_36 ;
V_32 = F_24 ( V_4 , V_19 , V_31 ) ;
if ( V_32 < 0 ) {
F_19 ( V_4 , L_5 ,
V_19 -> V_35 ) ;
continue;
}
V_7 = F_15 ( V_4 , sizeof( * V_7 ) , V_22 ) ;
if ( ! V_7 ) {
V_21 = - V_23 ;
goto V_37;
}
V_2 -> V_7 [ V_32 ] = V_7 ;
V_21 = F_25 ( V_4 , V_19 , V_7 , V_32 ) ;
if ( V_21 )
goto V_37;
}
V_2 -> V_38 = F_26 ( V_39 ) ;
if ( ! V_2 -> V_38 ) {
F_23 ( & V_5 -> V_4 , L_6 ) ;
V_21 = - V_23 ;
goto V_40;
}
V_2 -> V_16 = F_26 ( L_7 ) ;
if ( ! V_2 -> V_16 ) {
F_23 ( & V_5 -> V_4 , L_8 ) ;
V_21 = - V_23 ;
goto V_41;
}
F_27 ( & V_2 -> V_10 , F_6 ) ;
V_21 = F_28 ( V_4 , & V_2 -> V_42 ) ;
if ( V_21 ) {
F_23 ( & V_5 -> V_4 , L_9 ) ;
V_21 = - V_43 ;
goto V_44;
}
V_21 = F_29 ( V_2 ) ;
if ( V_21 ) {
F_30 ( & V_2 -> V_42 , L_10 ) ;
goto V_45;
}
V_2 -> V_46 = F_31 ( V_5 ) ;
F_32 ( V_2 -> V_46 , F_12 , V_2 ,
V_47 ) ;
F_33 ( V_5 , V_2 ) ;
F_34 ( & V_5 -> V_4 , F_35 ( 32 ) ) ;
F_36 ( V_4 ) ;
F_37 ( V_4 , L_11 , V_2 -> V_13 ) ;
return 0 ;
V_45:
F_38 ( & V_2 -> V_42 ) ;
V_44:
F_39 ( V_2 -> V_16 ) ;
V_41:
F_39 ( V_2 -> V_38 ) ;
V_40:
V_37:
for ( V_6 = 0 ; V_6 < F_2 ( V_2 -> V_7 ) ; V_6 ++ )
F_40 ( V_4 , V_2 -> V_7 [ V_6 ] ) ;
F_37 ( V_4 , L_12 , V_21 ) ;
return V_21 ;
}
static int F_41 ( struct V_17 * V_5 )
{
struct V_1 * V_2 = F_42 ( V_5 ) ;
int V_6 ;
F_43 ( & V_5 -> V_4 ) ;
F_44 ( & V_5 -> V_4 ) ;
F_45 ( V_2 ) ;
F_38 ( & V_2 -> V_42 ) ;
F_46 ( V_2 -> V_38 ) ;
F_39 ( V_2 -> V_38 ) ;
for ( V_6 = 0 ; V_6 < F_2 ( V_2 -> V_7 ) ; V_6 ++ )
F_40 ( & V_5 -> V_4 , V_2 -> V_7 [ V_6 ] ) ;
F_37 ( & V_5 -> V_4 , L_13 , V_5 -> V_48 ) ;
return 0 ;
}
static int T_1 F_47 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_48 ( V_4 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int T_1 F_49 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_48 ( V_4 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int T_1 F_50 ( struct V_3 * V_4 )
{
if ( F_51 ( V_4 ) )
return 0 ;
return F_47 ( V_4 ) ;
}
static int T_1 F_52 ( struct V_3 * V_4 )
{
if ( F_51 ( V_4 ) )
return 0 ;
return F_49 ( V_4 ) ;
}
