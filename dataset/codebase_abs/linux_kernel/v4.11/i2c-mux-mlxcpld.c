static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( & V_4 -> V_8 ) ;
int V_9 = - V_10 ;
if ( V_2 -> V_11 -> V_12 ) {
struct V_13 V_14 ;
T_1 V_15 [] = { V_7 -> V_16 , V_5 } ;
V_14 . V_17 = V_4 -> V_17 ;
V_14 . V_18 = 0 ;
V_14 . V_19 = 2 ;
V_14 . V_20 = V_15 ;
V_9 = F_3 ( V_2 , & V_14 , 1 ) ;
if ( V_9 >= 0 && V_9 != 1 )
V_9 = - V_21 ;
} else if ( V_2 -> V_11 -> V_22 ) {
union V_23 V_24 ;
V_24 . V_25 = V_5 ;
V_9 = V_2 -> V_11 -> V_22 ( V_2 , V_4 -> V_17 ,
V_4 -> V_18 , V_26 ,
V_7 -> V_16 ,
V_27 , & V_24 ) ;
}
return V_9 ;
}
static int F_4 ( struct V_28 * V_29 , T_2 V_30 )
{
struct V_31 * V_24 = F_5 ( V_29 ) ;
struct V_3 * V_4 = V_24 -> V_4 ;
T_1 V_32 = V_30 + 1 ;
int V_33 = 0 ;
if ( V_24 -> V_34 != V_32 ) {
V_33 = F_1 ( V_29 -> V_35 , V_4 , V_32 ) ;
V_24 -> V_34 = V_33 < 0 ? 0 : V_32 ;
}
return V_33 ;
}
static int F_6 ( struct V_28 * V_29 , T_2 V_30 )
{
struct V_31 * V_24 = F_5 ( V_29 ) ;
struct V_3 * V_4 = V_24 -> V_4 ;
V_24 -> V_34 = 0 ;
return F_1 ( V_29 -> V_35 , V_4 , V_24 -> V_34 ) ;
}
static int F_7 ( struct V_3 * V_4 ,
const struct V_36 * V_37 )
{
struct V_1 * V_2 = F_8 ( V_4 -> V_8 . V_35 ) ;
struct V_6 * V_7 = F_2 ( & V_4 -> V_8 ) ;
struct V_28 * V_29 ;
int V_38 , V_39 ;
struct V_31 * V_24 ;
int V_33 ;
if ( ! V_7 )
return - V_40 ;
if ( ! F_9 ( V_2 , V_41 ) )
return - V_10 ;
V_29 = F_10 ( V_2 , & V_4 -> V_8 , V_42 ,
sizeof( * V_24 ) , 0 , F_4 ,
F_6 ) ;
if ( ! V_29 )
return - V_43 ;
V_24 = F_5 ( V_29 ) ;
F_11 ( V_4 , V_29 ) ;
V_24 -> V_4 = V_4 ;
V_24 -> V_34 = 0 ;
for ( V_38 = 0 ; V_38 < V_42 ; V_38 ++ ) {
if ( V_38 >= V_7 -> V_44 )
break;
V_39 = V_7 -> V_45 [ V_38 ] ;
V_33 = F_12 ( V_29 , V_39 , V_38 , 0 ) ;
if ( V_33 )
goto V_46;
}
return 0 ;
V_46:
F_13 ( V_29 ) ;
return V_33 ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_28 * V_29 = F_15 ( V_4 ) ;
F_13 ( V_29 ) ;
return 0 ;
}
