static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 = - V_12 ;
int V_13 ;
if ( ! V_4 || ! V_4 -> V_14 || ! V_4 -> V_15 ) {
F_2 ( & V_2 -> V_5 , L_1 , V_16 ) ;
goto V_17;
}
V_8 = F_3 ( sizeof( * V_8 ) , V_18 ) ;
if ( ! V_8 ) {
V_11 = - V_19 ;
F_2 ( & V_2 -> V_5 , L_2 , V_16 ) ;
goto V_20;
}
V_8 -> V_4 = V_4 ;
V_10 = & V_4 -> V_21 [ 0 ] ;
for ( V_13 = 0 ; V_13 < V_2 -> V_22 ; ++ V_13 ) {
struct V_23 * V_24 = & V_2 -> V_23 [ V_13 ] ;
if ( V_24 -> V_25 != V_26 )
continue;
if ( V_10 >= & V_4 -> V_21 [ V_27 ] ) {
F_4 ( & V_2 -> V_5 , L_3
F_5 ( V_27 )
L_4 ) ;
break;
}
V_10 -> V_28 = V_29 ;
V_10 -> V_30 = V_24 -> V_31 ;
V_10 -> V_32 = F_6 ( V_24 ) ;
++ V_10 ;
}
while ( V_10 < & V_4 -> V_21 [ V_27 ] ) {
V_10 -> V_32 = 0 ;
++ V_10 ;
}
V_8 -> V_4 -> V_33 = V_8 ;
V_11 = F_7 ( & V_2 -> V_5 , V_8 -> V_4 ) ;
if ( V_11 ) {
F_8 ( V_8 ) ;
V_20:
V_17:
return V_11 ;
}
F_9 ( V_2 , V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_11 ( V_2 ) ;
F_12 ( V_8 -> V_4 ) ;
F_8 ( V_8 ) ;
return 0 ;
}
static int T_1 F_13 ( void )
{
return F_14 ( & V_34 ) ;
}
static void T_2 F_15 ( void )
{
F_16 ( & V_34 ) ;
}
