static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_1 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
unsigned long V_8 ;
T_1 V_9 ;
if ( F_3 ( & V_5 -> V_10 , - 1 , V_1 -> V_11 ) != - 1 )
return - V_12 ;
F_4 ( V_7 -> V_13 ) ;
F_5 ( & V_7 -> V_14 , V_8 ) ;
V_9 = F_6 ( V_7 -> V_15 + V_16 ) ;
V_9 &= ~ V_5 -> V_17 ;
V_9 |= V_1 -> V_18 ;
F_7 ( V_9 , V_7 -> V_15 + V_16 ) ;
F_8 ( & V_7 -> V_14 , V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_1 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_1 -> V_5 ;
F_10 ( V_5 -> V_7 -> V_13 ) ;
V_5 -> V_10 = - 1 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_1 -> V_5 -> V_7 ;
void T_2 * V_15 = V_7 -> V_15 ;
unsigned long V_8 ;
T_1 V_19 ;
int V_20 = 0 , V_21 ;
if ( V_1 -> V_18 != V_22 )
return 0 ;
F_5 ( & V_7 -> V_14 , V_8 ) ;
V_19 = F_6 ( V_15 + V_23 ) ;
V_19 &= ~ V_24 ;
F_7 ( V_19 , V_15 + V_23 ) ;
V_19 = F_12 ( V_15 + V_25 ) ;
V_19 |= V_26 ;
F_13 ( V_19 , V_15 + V_25 ) ;
for ( V_21 = 0 ; V_21 < 20 ; V_21 ++ ) {
V_19 = F_6 ( V_15 + V_27 ) ;
if ( ( V_19 & V_28 ) == V_28 ) {
V_19 = F_6 ( V_15 + V_23 ) ;
V_19 |= V_29 ;
F_7 ( V_19 , V_15 + V_23 ) ;
goto V_30;
}
F_14 ( 1 ) ;
}
V_20 = - V_31 ;
V_30:
F_8 ( & V_7 -> V_14 , V_8 ) ;
return V_20 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_1 -> V_5 -> V_7 ;
void T_2 * V_15 = V_7 -> V_15 ;
unsigned long V_8 ;
T_1 V_19 ;
if ( V_1 -> V_18 != V_22 )
return 0 ;
F_5 ( & V_7 -> V_14 , V_8 ) ;
V_19 = F_6 ( V_15 + V_23 ) ;
V_19 &= ~ V_29 ;
F_7 ( V_19 , V_15 + V_23 ) ;
V_19 = F_12 ( V_15 + V_25 ) ;
V_19 &= ~ V_26 ;
F_13 ( V_19 , V_15 + V_25 ) ;
V_19 = F_6 ( V_15 + V_23 ) ;
V_19 |= V_24 ;
F_7 ( V_19 , V_15 + V_23 ) ;
F_8 ( & V_7 -> V_14 , V_8 ) ;
return 0 ;
}
static struct V_1 * F_16 ( struct V_32 * V_33 ,
struct V_34 * args )
{
struct V_6 * V_7 ;
struct V_35 * V_36 = args -> V_36 ;
int V_21 ;
if ( ! F_17 ( V_36 ) ) {
F_18 ( V_33 , L_1 ) ;
return F_19 ( - V_37 ) ;
}
V_7 = F_20 ( V_33 ) ;
if ( ! V_7 )
return F_19 ( - V_38 ) ;
for ( V_21 = 0 ; V_21 < V_7 -> V_39 ; V_21 ++ ) {
if ( V_36 == V_7 -> V_40 [ V_21 ] . V_41 )
break;
}
if ( V_21 >= V_7 -> V_39 || args -> args [ 0 ] >= 2 )
return F_19 ( - V_37 ) ;
return V_7 -> V_40 [ V_21 ] . V_42 [ args -> args [ 0 ] ] . V_1 ;
}
static int F_21 ( struct V_43 * V_44 )
{
struct V_32 * V_33 = & V_44 -> V_33 ;
struct V_6 * V_7 ;
struct V_45 * V_46 ;
struct V_35 * V_36 ;
struct V_47 * V_48 ;
void T_2 * V_15 ;
struct V_13 * V_13 ;
int V_21 = 0 ;
if ( ! V_33 -> V_41 ) {
F_22 ( V_33 ,
L_2 ) ;
return - V_38 ;
}
V_13 = F_23 ( V_33 , L_3 ) ;
if ( F_24 ( V_13 ) ) {
F_22 ( V_33 , L_4 ) ;
return F_25 ( V_13 ) ;
}
V_48 = F_26 ( V_44 , V_49 , 0 ) ;
V_15 = F_27 ( V_33 , V_48 ) ;
if ( F_24 ( V_15 ) )
return F_25 ( V_15 ) ;
V_7 = F_28 ( V_33 , sizeof( * V_7 ) , V_50 ) ;
if ( ! V_7 )
return - V_51 ;
F_29 ( & V_7 -> V_14 ) ;
V_7 -> V_13 = V_13 ;
V_7 -> V_15 = V_15 ;
V_7 -> V_39 = F_30 ( V_33 -> V_41 ) ;
V_7 -> V_40 = F_31 ( V_33 , V_7 -> V_39 ,
sizeof( struct V_4 ) ,
V_50 ) ;
if ( ! V_7 -> V_40 )
return - V_51 ;
F_32 (dev->of_node, np) {
struct V_4 * V_5 = V_7 -> V_40 + V_21 ;
T_1 V_52 ;
int error , V_53 ;
V_5 -> V_41 = V_36 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_10 = - 1 ;
error = F_33 ( V_36 , L_5 , & V_52 ) ;
if ( error || V_52 > 2 ) {
F_22 ( V_33 , L_6 ) ;
return error ;
}
V_5 -> V_17 = V_17 [ V_52 ] ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
struct V_3 * V_1 = & V_5 -> V_42 [ V_53 ] ;
V_1 -> V_5 = V_5 ;
V_1 -> V_11 = V_53 ;
V_1 -> V_18 = V_18 [ V_52 ] [ V_53 ] ;
V_1 -> V_1 = F_34 ( V_33 , NULL ,
& V_55 ) ;
if ( F_24 ( V_1 -> V_1 ) ) {
F_22 ( V_33 , L_7 ) ;
return F_25 ( V_1 -> V_1 ) ;
}
F_35 ( V_1 -> V_1 , V_1 ) ;
}
V_21 ++ ;
}
V_46 = F_36 ( V_33 , F_16 ) ;
if ( F_24 ( V_46 ) ) {
F_22 ( V_33 , L_8 ) ;
return F_25 ( V_46 ) ;
}
F_37 ( V_33 , V_7 ) ;
return 0 ;
}
