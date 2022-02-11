static int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
struct V_3 * V_5 ;
struct V_6 * V_7 ;
T_1 V_8 ;
struct V_9 V_10 = { V_11 , NULL } ;
union V_12 * V_13 , * V_14 ;
union V_12 * V_15 ;
int V_16 ;
int V_17 ;
V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_18 ;
V_8 = F_3 ( V_7 -> V_19 , L_1 , NULL , & V_10 ) ;
if ( F_4 ( V_8 ) )
return - V_18 ;
V_15 = V_10 . V_20 ;
if ( ! V_15 || ( V_15 -> type != V_21 ) ) {
F_5 ( V_2 , L_2 ) ;
V_17 = - V_22 ;
goto V_23;
}
if ( ! V_15 -> V_24 . V_25 ) {
F_5 ( V_2 , L_3 ) ;
V_17 = - V_22 ;
goto V_23;
}
V_5 = F_6 ( V_2 , sizeof( * V_5 ) , V_26 ) ;
if ( ! V_5 ) {
V_17 = - V_27 ;
goto V_23;
}
V_5 -> V_2 = V_2 ;
V_5 -> V_7 = V_7 ;
for ( V_16 = 0 ; V_16 < F_7 ( ( int ) V_15 -> V_24 . V_25 - 1 , 2 ) ; ++ V_16 ) {
V_13 = & ( V_15 -> V_24 . V_13 [ V_16 + 1 ] ) ;
if ( V_13 -> type != V_21 ||
V_13 -> V_24 . V_25 != 6 ) {
V_17 = - V_22 ;
goto V_23;
}
V_14 = V_13 -> V_24 . V_13 ;
V_5 -> V_28 [ V_16 ] . V_29 = V_14 [ 0 ] . integer . V_30 ;
V_5 -> V_28 [ V_16 ] . V_31 = V_14 [ 1 ] . integer . V_30 ;
V_5 -> V_28 [ V_16 ] . V_32 = V_14 [ 2 ] . integer . V_30 ;
V_5 -> V_28 [ V_16 ] . V_33 = V_14 [ 3 ] . integer . V_30 ;
V_5 -> V_28 [ V_16 ] . V_34 = V_14 [ 4 ] . integer . V_30 ;
V_5 -> V_28 [ V_16 ] . V_35 = V_14 [ 5 ] . integer . V_30 ;
}
* V_4 = V_5 ;
V_17 = F_8 ( & V_2 -> V_36 ,
& V_37 ) ;
V_23:
F_9 ( V_10 . V_20 ) ;
return V_17 ;
}
void F_10 ( struct V_3 * V_5 )
{
F_11 ( & V_5 -> V_2 -> V_36 ,
& V_37 ) ;
}
static int F_12 ( struct V_38 * V_39 )
{
struct V_3 * V_5 ;
int V_17 ;
if ( V_40 == V_41 ) {
F_5 ( & V_39 -> V_2 , L_4 ) ;
return - V_18 ;
}
V_17 = F_1 ( & V_39 -> V_2 , & V_5 ) ;
if ( V_17 )
return V_17 ;
F_13 ( V_39 , V_5 ) ;
V_40 = V_42 ;
return 0 ;
}
static int F_14 ( struct V_38 * V_39 )
{
F_10 ( F_15 ( V_39 ) ) ;
return 0 ;
}
static int F_16 ( struct V_43 * V_39 ,
const struct V_44 * V_45 )
{
struct V_3 * V_5 ;
int V_17 ;
if ( V_40 == V_42 ) {
F_5 ( & V_39 -> V_2 , L_5 ) ;
return - V_18 ;
}
V_17 = F_17 ( V_39 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_39 -> V_2 , L_6 ) ;
return V_17 ;
}
V_17 = F_1 ( & V_39 -> V_2 , & V_5 ) ;
if ( V_17 ) {
F_18 ( V_39 ) ;
return V_17 ;
}
F_19 ( V_39 , V_5 ) ;
V_40 = V_41 ;
return 0 ;
}
static void F_20 ( struct V_43 * V_39 )
{
F_10 ( F_21 ( V_39 ) ) ;
F_18 ( V_39 ) ;
}
static int T_2 F_22 ( void )
{
int V_17 ;
V_17 = F_23 ( & V_46 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_24 ( & V_47 ) ;
return V_17 ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_46 ) ;
F_27 ( & V_47 ) ;
}
