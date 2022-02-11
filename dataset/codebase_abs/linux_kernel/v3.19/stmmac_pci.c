static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 1 ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = 2 ;
V_2 -> V_8 = 1 ;
V_2 -> V_9 = 1 ;
V_2 -> V_10 -> V_11 = NULL ;
V_2 -> V_10 -> V_12 = 0 ;
V_2 -> V_13 -> V_14 = 32 ;
V_2 -> V_13 -> V_15 = V_16 ;
V_2 -> V_17 = V_18 ;
V_2 -> V_19 = 1 ;
}
static int F_2 ( struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
struct V_1 * V_2 ;
struct V_24 * V_25 ;
int V_26 ;
int V_27 ;
V_2 = F_3 ( & V_21 -> V_28 , sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 )
return - V_30 ;
V_2 -> V_10 = F_3 ( & V_21 -> V_28 ,
sizeof( * V_2 -> V_10 ) ,
V_29 ) ;
if ( ! V_2 -> V_10 )
return - V_30 ;
V_2 -> V_13 = F_3 ( & V_21 -> V_28 , sizeof( * V_2 -> V_13 ) ,
V_29 ) ;
if ( ! V_2 -> V_13 )
return - V_30 ;
V_27 = F_4 ( V_21 ) ;
if ( V_27 ) {
F_5 ( & V_21 -> V_28 , L_1 ,
V_31 ) ;
return V_27 ;
}
for ( V_26 = 0 ; V_26 <= V_32 ; V_26 ++ ) {
if ( F_6 ( V_21 , V_26 ) == 0 )
continue;
V_27 = F_7 ( V_21 , F_8 ( V_26 ) , F_9 ( V_21 ) ) ;
if ( V_27 )
return V_27 ;
break;
}
F_10 ( V_21 ) ;
F_1 ( V_2 ) ;
V_25 = F_11 ( & V_21 -> V_28 , V_2 , F_12 ( V_21 ) [ V_26 ] ) ;
if ( F_13 ( V_25 ) ) {
F_5 ( & V_21 -> V_28 , L_2 , V_31 ) ;
return F_14 ( V_25 ) ;
}
V_25 -> V_28 -> V_33 = V_21 -> V_33 ;
V_25 -> V_34 = V_21 -> V_33 ;
F_15 ( V_21 , V_25 -> V_28 ) ;
F_16 ( & V_21 -> V_28 , L_3 ) ;
return 0 ;
}
static void F_17 ( struct V_20 * V_21 )
{
struct V_35 * V_36 = F_18 ( V_21 ) ;
F_19 ( V_36 ) ;
}
static int F_20 ( struct V_37 * V_28 )
{
struct V_20 * V_21 = F_21 ( V_28 ) ;
struct V_35 * V_36 = F_18 ( V_21 ) ;
return F_22 ( V_36 ) ;
}
static int F_23 ( struct V_37 * V_28 )
{
struct V_20 * V_21 = F_21 ( V_28 ) ;
struct V_35 * V_36 = F_18 ( V_21 ) ;
return F_24 ( V_36 ) ;
}
