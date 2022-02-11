static int F_1 ( struct V_1 * V_1 , int V_2 )
{
int V_3 = V_2 / V_4 ;
int V_5 = F_2 ( V_2 % V_4 ) ;
int V_6 = V_7 + ( V_3 * V_8 ) ;
int V_9 , V_10 ;
if ( V_6 < V_7 || V_6 > V_11 )
return - V_12 ;
V_9 = F_3 ( V_1 , V_6 , & V_10 ) ;
if ( V_9 )
return V_9 ;
return ! ! ( V_10 & V_5 ) ;
}
int F_4 ( struct V_1 * V_1 , int V_13 )
{
struct V_14 * V_15 = F_5 ( V_13 ) ;
int V_16 = F_6 ( V_15 ) ;
return F_1 ( V_1 , V_13 - V_16 ) ;
}
static int F_7 ( struct V_17 * V_18 )
{
T_1 V_19 , V_20 ;
int V_21 ;
V_21 = F_8 ( & V_18 -> V_22 -> V_23 , V_18 -> V_1 , & V_19 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_9 ( & V_18 -> V_22 -> V_23 , V_18 -> V_1 , & V_20 ) ;
if ( V_21 )
return V_21 ;
F_10 ( & V_18 -> V_22 -> V_23 , L_1 ,
V_19 == V_24 ? L_2 : L_3 ,
F_11 ( V_20 ) , F_12 ( V_20 ) ,
V_20 ) ;
if ( V_20 < V_25 ) {
F_10 ( & V_18 -> V_22 -> V_23 ,
L_4 ) ;
return - V_26 ;
}
return 0 ;
}
static void F_13 ( struct V_17 * V_18 ,
struct V_27 * V_28 ,
int V_16 , int V_2 )
{
unsigned int V_29 ;
unsigned int V_30 , V_5 ;
V_29 = V_2 - V_16 ;
V_29 /= V_18 -> V_31 -> V_32 ;
V_29 *= V_18 -> V_31 -> V_33 ;
V_30 = V_2 % V_18 -> V_31 -> V_32 ;
V_5 = ( 1 << V_30 ) ;
V_28 -> V_29 = V_29 ;
V_28 -> V_5 = V_5 ;
}
static int F_14 ( struct V_17 * V_18 , int V_34 ,
int V_35 , int V_36 )
{
struct V_37 * V_38 = & V_39 [ V_34 ] ;
int V_40 , V_21 ;
for ( V_40 = V_35 ; V_40 < V_35 + V_36 ; V_40 ++ ) {
struct V_27 * V_28 = & V_18 -> V_41 [ V_40 ] ;
F_13 ( V_18 , V_28 , V_35 , V_40 ) ;
}
V_38 -> V_41 = & V_18 -> V_41 [ V_35 ] ;
V_38 -> V_42 = V_36 ;
V_38 -> V_43 = V_18 ;
V_21 = F_15 ( & V_18 -> V_22 -> V_23 , V_18 -> V_1 ,
V_18 -> V_22 -> V_2 ,
F_16 ( V_18 -> V_22 -> V_2 ) |
V_44 , - 1 ,
V_38 , & V_18 -> V_45 [ V_34 ] ) ;
if ( V_21 ) {
F_17 ( & V_18 -> V_22 -> V_23 , L_5 ,
V_34 , V_21 ) ;
return V_21 ;
}
return 0 ;
}
static int F_18 ( struct V_17 * V_18 )
{
int V_21 ;
V_18 -> V_41 = F_19 ( & V_18 -> V_22 -> V_23 ,
sizeof( * V_18 -> V_41 ) *
V_46 *
V_18 -> V_31 -> V_32 ,
V_47 ) ;
if ( ! V_18 -> V_41 )
return - V_48 ;
V_21 = F_14 ( V_18 , 0 , 0 , 16 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_14 ( V_18 , 1 , 16 , 16 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_14 ( V_18 , 2 , 32 , 64 ) ;
if ( V_21 )
return V_21 ;
F_20 ( V_18 -> V_22 -> V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_49 * V_22 )
{
const struct V_50 * V_51 ;
struct V_17 * V_18 ;
int V_21 ;
V_51 = F_22 ( F_23 ( V_52 ) , & V_22 -> V_23 ) ;
if ( ! V_51 )
return - V_26 ;
V_18 = F_19 ( & V_22 -> V_23 , sizeof( * V_18 ) , V_47 ) ;
if ( ! V_18 )
return - V_48 ;
V_18 -> V_22 = V_22 ;
F_24 ( V_22 , V_18 ) ;
V_22 -> V_53 = 16 ;
V_22 -> V_54 = V_55 | V_56 ;
V_21 = F_25 ( V_22 ) ;
if ( V_21 )
return V_21 ;
V_18 -> V_31 = & V_57 ;
V_18 -> V_1 = F_26 ( V_22 , & V_57 ) ;
if ( F_27 ( V_18 -> V_1 ) ) {
V_21 = F_28 ( V_18 -> V_1 ) ;
F_17 ( & V_18 -> V_22 -> V_23 , L_6 ,
V_21 ) ;
return V_21 ;
}
V_21 = F_7 ( V_18 ) ;
if ( V_21 ) {
F_17 ( & V_18 -> V_22 -> V_23 , L_7 , V_21 ) ;
return V_21 ;
}
V_21 = F_18 ( V_18 ) ;
if ( V_21 )
return V_21 ;
return F_29 ( & V_18 -> V_22 -> V_23 ) ;
}
