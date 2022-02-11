static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
int V_5 ;
V_5 = F_2 ( & V_2 -> V_6 -> V_7 , V_2 -> V_8 , & V_3 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_3 ( & V_2 -> V_6 -> V_7 , V_2 -> V_8 , & V_4 ) ;
if ( V_5 )
return V_5 ;
F_4 ( & V_2 -> V_6 -> V_7 , L_1 ,
V_3 == V_9 ? L_2 : L_3 ,
F_5 ( V_4 ) , F_6 ( V_4 ) ,
V_4 ) ;
if ( V_4 < V_10 ) {
F_4 ( & V_2 -> V_6 -> V_7 ,
L_4 ) ;
return - V_11 ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
int V_14 , int V_15 )
{
unsigned int V_16 ;
unsigned int V_17 , V_18 ;
V_16 = V_15 - V_14 ;
V_16 /= V_2 -> V_19 -> V_20 ;
V_16 *= V_2 -> V_19 -> V_21 ;
V_17 = V_15 % V_2 -> V_19 -> V_20 ;
V_18 = ( 1 << V_17 ) ;
V_13 -> V_16 = V_16 ;
V_13 -> V_18 = V_18 ;
}
static int F_8 ( struct V_1 * V_2 , int V_22 ,
int V_23 , int V_24 )
{
struct V_25 * V_26 = & V_27 [ V_22 ] ;
int V_28 , V_5 ;
for ( V_28 = V_23 ; V_28 < V_23 + V_24 ; V_28 ++ ) {
struct V_12 * V_13 = & V_2 -> V_29 [ V_28 ] ;
F_7 ( V_2 , V_13 , V_23 , V_28 ) ;
}
V_26 -> V_29 = & V_2 -> V_29 [ V_23 ] ;
V_26 -> V_30 = V_24 ;
V_26 -> V_31 = V_2 ;
V_5 = F_9 ( & V_2 -> V_6 -> V_7 , V_2 -> V_8 ,
V_2 -> V_6 -> V_15 ,
V_32 |
V_33 , - 1 ,
V_26 , & V_2 -> V_34 [ V_22 ] ) ;
if ( V_5 ) {
F_10 ( & V_2 -> V_6 -> V_7 , L_5 ,
V_22 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_5 ;
V_2 -> V_29 = F_12 ( & V_2 -> V_6 -> V_7 ,
sizeof( * V_2 -> V_29 ) *
V_35 *
V_2 -> V_19 -> V_20 ,
V_36 ) ;
if ( ! V_2 -> V_29 )
return - V_37 ;
V_5 = F_8 ( V_2 , 0 , 0 , 16 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_8 ( V_2 , 1 , 16 , 16 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_8 ( V_2 , 2 , 32 , 64 ) ;
if ( V_5 )
return V_5 ;
F_13 ( V_2 -> V_6 -> V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_38 * V_6 )
{
const struct V_39 * V_40 ;
struct V_1 * V_2 ;
int V_5 ;
V_40 = F_15 ( F_16 ( V_41 ) , & V_6 -> V_7 ) ;
if ( ! V_40 )
return - V_11 ;
V_2 = F_12 ( & V_6 -> V_7 , sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_37 ;
V_2 -> V_6 = V_6 ;
F_17 ( V_6 , V_2 ) ;
V_6 -> V_42 = 16 ;
V_6 -> V_43 = V_44 | V_45 ;
V_5 = F_18 ( V_6 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_19 = & V_46 ;
V_2 -> V_8 = F_19 ( V_6 , & V_46 ) ;
if ( F_20 ( V_2 -> V_8 ) ) {
V_5 = F_21 ( V_2 -> V_8 ) ;
F_10 ( & V_2 -> V_6 -> V_7 , L_6 ,
V_5 ) ;
return V_5 ;
}
V_5 = F_1 ( V_2 ) ;
if ( V_5 ) {
F_10 ( & V_2 -> V_6 -> V_7 , L_7 , V_5 ) ;
return V_5 ;
}
V_5 = F_11 ( V_2 ) ;
if ( V_5 )
return V_5 ;
return F_22 ( V_6 -> V_7 . V_47 , NULL , NULL ,
& V_2 -> V_6 -> V_7 ) ;
}
static int F_23 ( struct V_38 * V_48 )
{
struct V_1 * V_2 = F_24 ( V_48 ) ;
F_25 ( & V_2 -> V_6 -> V_7 ) ;
return 0 ;
}
