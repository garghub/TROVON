static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = NULL ;
struct V_8 * V_9 = V_2 -> V_10 -> V_11 -> V_9 ;
for ( V_5 = 0 ; V_5 < F_2 () ; V_5 ++ ) {
V_7 = F_3 ( V_5 ) ;
if ( V_7 && V_7 -> V_8
&& V_7 -> V_8 -> type == V_12 )
break;
}
if ( V_5 == F_2 () ) {
F_4 ( V_9 , L_1 ) ;
return - V_13 ;
}
if ( V_7 -> V_8 -> V_14 != V_15 ) {
F_4 ( V_9 , L_2 ) ;
return - V_16 ;
}
return 0 ;
}
static T_1 int F_5 ( struct V_17 * V_18 )
{
struct V_19 * V_11 = & V_20 ;
int V_21 ;
V_11 -> V_9 = & V_18 -> V_9 ;
V_21 = F_6 ( V_11 ) ;
if ( V_21 ) {
F_4 ( & V_18 -> V_9 , L_3 , V_21 ) ;
V_11 -> V_9 = NULL ;
return V_21 ;
}
return 0 ;
}
static int T_2 F_7 ( struct V_17 * V_18 )
{
struct V_19 * V_11 = F_8 ( V_18 ) ;
F_9 ( V_11 ) ;
V_11 -> V_9 = NULL ;
return 0 ;
}
