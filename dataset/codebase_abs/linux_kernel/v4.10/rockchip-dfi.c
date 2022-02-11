static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_6 ;
T_2 V_7 ;
T_2 V_8 ;
F_3 ( V_4 -> V_9 , V_10 , & V_7 ) ;
V_8 = ( V_7 >> V_11 ) & V_12 ;
F_4 ( V_13 , V_5 + V_14 ) ;
if ( V_8 == V_15 )
F_4 ( V_16 , V_5 + V_14 ) ;
else if ( V_8 == V_17 )
F_4 ( V_18 , V_5 + V_14 ) ;
F_4 ( V_19 , V_5 + V_14 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_6 ;
F_4 ( V_20 , V_5 + V_14 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_21 , V_22 = 0 ;
T_2 V_23 , V_24 = 0 ;
void T_1 * V_5 = V_4 -> V_6 ;
F_5 ( V_2 ) ;
for ( V_23 = 0 ; V_23 < V_25 ; V_23 ++ ) {
V_4 -> V_26 [ V_23 ] . V_27 = F_7 ( V_5 +
V_28 + V_23 * 20 ) * 4 ;
V_4 -> V_26 [ V_23 ] . V_29 = F_7 ( V_5 +
V_30 + V_23 * 20 ) ;
V_21 = V_4 -> V_26 [ V_23 ] . V_27 ;
if ( V_21 > V_22 ) {
V_24 = V_23 ;
V_22 = V_21 ;
}
}
F_1 ( V_2 ) ;
return V_24 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_2 ) ;
F_9 ( V_4 -> V_31 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_32 ;
V_32 = F_11 ( V_4 -> V_31 ) ;
if ( V_32 ) {
F_12 ( & V_2 -> V_33 , L_1 , V_32 ) ;
return V_32 ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_24 ;
V_24 = F_6 ( V_2 ) ;
V_35 -> V_36 = V_4 -> V_26 [ V_24 ] . V_27 ;
V_35 -> V_37 = V_4 -> V_26 [ V_24 ] . V_29 ;
return 0 ;
}
static int F_15 ( struct V_38 * V_39 )
{
struct V_40 * V_33 = & V_39 -> V_33 ;
struct V_3 * V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 = V_39 -> V_33 . V_48 , * V_49 ;
V_41 = F_16 ( V_33 , sizeof( struct V_3 ) , V_50 ) ;
if ( ! V_41 )
return - V_51 ;
V_43 = F_17 ( V_39 , V_52 , 0 ) ;
V_41 -> V_6 = F_18 ( & V_39 -> V_33 , V_43 ) ;
if ( F_19 ( V_41 -> V_6 ) )
return F_20 ( V_41 -> V_6 ) ;
V_41 -> V_31 = F_21 ( V_33 , L_2 ) ;
if ( F_19 ( V_41 -> V_31 ) ) {
F_12 ( V_33 , L_3 ) ;
return F_20 ( V_41 -> V_31 ) ;
} ;
V_49 = F_22 ( V_47 , L_4 , 0 ) ;
if ( V_49 ) {
V_41 -> V_9 = F_23 ( V_49 ) ;
if ( F_19 ( V_41 -> V_9 ) )
return F_20 ( V_41 -> V_9 ) ;
}
V_41 -> V_33 = V_33 ;
V_45 = F_16 ( V_33 , sizeof( * V_45 ) , V_50 ) ;
if ( ! V_45 )
return - V_51 ;
V_45 -> V_53 = & V_54 ;
V_45 -> V_55 = V_41 ;
V_45 -> V_56 = V_47 -> V_56 ;
V_41 -> V_45 = V_45 ;
V_41 -> V_2 = F_24 ( & V_39 -> V_33 , V_45 ) ;
if ( F_19 ( V_41 -> V_2 ) ) {
F_12 ( & V_39 -> V_33 ,
L_5 ) ;
return F_20 ( V_41 -> V_2 ) ;
}
F_25 ( V_39 , V_41 ) ;
return 0 ;
}
