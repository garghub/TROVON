static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_2 ( & V_5 -> V_6 -> V_7 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_4 ( & V_5 -> V_6 -> V_7 ) ;
return 0 ;
}
static T_1 F_5 ( int V_8 , struct V_1 * V_9 )
{
struct V_4 * V_5 = V_9 -> V_5 ;
if ( ! F_6 ( 0 , & V_5 -> V_10 ) )
F_7 ( V_8 ) ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_9 , T_2 V_12 )
{
struct V_4 * V_5 = V_9 -> V_5 ;
unsigned long V_10 ;
F_9 ( & V_5 -> V_13 , V_10 ) ;
if ( V_12 ) {
if ( F_10 ( 0 , & V_5 -> V_10 ) )
F_11 ( V_9 -> V_8 ) ;
} else {
if ( ! F_6 ( 0 , & V_5 -> V_10 ) )
F_12 ( V_9 -> V_8 ) ;
}
F_13 ( & V_5 -> V_13 , V_10 ) ;
return 0 ;
}
static int F_14 ( struct V_14 * V_6 )
{
struct V_1 * V_15 = V_6 -> V_7 . V_16 ;
struct V_4 * V_5 ;
struct V_17 * V_18 ;
int V_19 = - V_20 ;
int V_21 ;
if ( ! V_15 || ! V_15 -> V_22 || ! V_15 -> V_23 ) {
F_15 ( & V_6 -> V_7 , L_1 ) ;
goto V_24;
}
if ( V_15 -> V_25 || V_15 -> V_26 ||
V_15 -> V_27 & V_28 ) {
F_15 ( & V_6 -> V_7 , L_2 ) ;
goto V_24;
}
V_5 = F_16 ( sizeof( * V_5 ) , V_29 ) ;
if ( ! V_5 ) {
V_19 = - V_30 ;
F_15 ( & V_6 -> V_7 , L_3 ) ;
goto V_24;
}
V_5 -> V_15 = V_15 ;
F_17 ( & V_5 -> V_13 ) ;
V_5 -> V_10 = 0 ;
V_5 -> V_6 = V_6 ;
V_18 = & V_15 -> V_31 [ 0 ] ;
for ( V_21 = 0 ; V_21 < V_6 -> V_32 ; ++ V_21 ) {
struct V_33 * V_34 = & V_6 -> V_33 [ V_21 ] ;
if ( V_34 -> V_10 != V_35 )
continue;
if ( V_18 >= & V_15 -> V_31 [ V_36 ] ) {
F_18 ( & V_6 -> V_7 , L_4
F_19 ( V_36 )
L_5 ) ;
break;
}
V_18 -> V_37 = V_38 ;
V_18 -> V_39 = V_34 -> V_40 ;
V_18 -> V_41 = V_34 -> V_42 - V_34 -> V_40 + 1 ;
++ V_18 ;
}
while ( V_18 < & V_15 -> V_31 [ V_36 ] ) {
V_18 -> V_41 = 0 ;
++ V_18 ;
}
V_15 -> V_25 = F_5 ;
V_15 -> V_26 = F_8 ;
V_15 -> V_43 = F_1 ;
V_15 -> V_44 = F_3 ;
V_15 -> V_5 = V_5 ;
F_20 ( & V_6 -> V_7 ) ;
V_19 = F_21 ( & V_6 -> V_7 , V_5 -> V_15 ) ;
if ( V_19 ) {
F_15 ( & V_6 -> V_7 , L_6 ) ;
goto V_45;
}
F_22 ( V_6 , V_5 ) ;
return 0 ;
V_45:
F_23 ( V_5 ) ;
F_24 ( & V_6 -> V_7 ) ;
V_24:
return V_19 ;
}
static int F_25 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = F_26 ( V_6 ) ;
F_27 ( V_5 -> V_15 ) ;
F_24 ( & V_6 -> V_7 ) ;
V_5 -> V_15 -> V_25 = NULL ;
V_5 -> V_15 -> V_26 = NULL ;
F_23 ( V_5 ) ;
return 0 ;
}
static int F_28 ( struct V_46 * V_7 )
{
return 0 ;
}
static int T_3 F_29 ( void )
{
return F_30 ( & V_47 ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_47 ) ;
}
