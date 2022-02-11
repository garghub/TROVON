static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
if ( V_3 == V_5 )
V_6 . V_7 = V_8 ;
return V_9 ;
}
static int F_2 ( struct V_10 * V_11 ,
unsigned int V_12 )
{
struct V_13 * V_14 = F_3 ( V_11 -> V_15 ) ;
unsigned int V_16 , V_17 ;
V_16 = V_11 -> V_18 ;
V_17 = V_11 -> V_19 [ V_12 ] . V_20 ;
F_4 ( V_11 -> V_21 , V_22 -> V_23 ) ;
F_5 ( F_6 ( V_24 ) | V_25 | V_26 ,
V_24 ) ;
F_5 ( F_6 ( V_24 ) & ~ ( V_25 | V_26 ) ,
V_24 ) ;
F_7 ( V_22 -> V_27 , V_17 * 1000 ) ;
F_4 ( V_11 -> V_21 , V_22 -> V_27 ) ;
F_8 ( V_14 , L_1 , V_16 , V_17 ) ;
return 0 ;
}
static int F_9 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = F_3 ( V_11 -> V_15 ) ;
struct V_28 * V_29 ;
unsigned int V_30 , V_31 ;
int V_32 , V_33 , V_34 ;
V_30 = F_10 ( V_22 -> V_35 ) / 1000 ;
V_32 = 1 << V_36 ;
V_29 = F_11 ( V_32 , sizeof( * V_29 ) , V_37 ) ;
if ( ! V_29 )
return - V_38 ;
for ( V_33 = 0 ; V_33 < ( V_32 - 1 ) ; V_33 ++ ) {
V_31 = V_30 / ( V_33 + 1 ) ;
if ( ( V_31 < V_22 -> V_39 ) || ( V_31 > V_22 -> V_40 ) )
V_29 [ V_33 ] . V_20 = V_41 ;
else
V_29 [ V_33 ] . V_20 = V_31 ;
F_8 ( V_14 ,
L_2 , V_33 ,
V_29 [ V_33 ] . V_20 ) ;
}
V_29 [ V_33 ] . V_20 = V_42 ;
V_11 -> V_21 = V_22 -> V_21 ;
V_34 = F_12 ( V_11 , V_29 , 0 ) ;
if ( V_34 )
F_13 ( V_29 ) ;
return V_34 ;
}
static int F_14 ( struct V_10 * V_11 )
{
F_13 ( V_11 -> V_19 ) ;
return 0 ;
}
static int F_15 ( struct V_43 * V_44 )
{
F_16 ( & V_45 ,
V_46 ) ;
F_17 ( & V_47 ) ;
return 0 ;
}
static int F_18 ( struct V_43 * V_44 )
{
struct V_48 * V_49 = F_19 ( & V_44 -> V_50 ) ;
struct V_21 * V_21 ;
int V_34 ;
if ( ! V_49 || ! V_49 -> V_51 || ! V_49 -> V_52 ) {
F_20 ( & V_44 -> V_50 , L_3 ) ;
return - V_53 ;
}
V_22 =
F_21 ( & V_44 -> V_50 , sizeof( struct V_54 ) , V_37 ) ;
if ( ! V_22 )
return - V_38 ;
V_22 -> V_50 = & V_44 -> V_50 ;
V_21 = F_22 ( & V_44 -> V_50 , V_49 -> V_51 ) ;
if ( F_23 ( V_21 ) ) {
F_20 ( & V_44 -> V_50 , L_4 ,
V_49 -> V_51 ) ;
return F_24 ( V_21 ) ;
}
V_22 -> V_21 = V_21 ;
V_21 = F_25 ( V_21 ) ;
if ( F_23 ( V_21 ) ) {
F_20 ( & V_44 -> V_50 , L_5 ,
F_26 ( V_22 -> V_21 ) ) ;
return F_24 ( V_21 ) ;
}
V_22 -> V_27 = V_21 ;
V_21 = F_25 ( V_21 ) ;
if ( F_23 ( V_21 ) ) {
F_20 ( & V_44 -> V_50 , L_5 ,
F_26 ( V_22 -> V_27 ) ) ;
return F_24 ( V_21 ) ;
}
V_22 -> V_35 = V_21 ;
V_21 = F_22 ( & V_44 -> V_50 , V_49 -> V_52 ) ;
if ( F_23 ( V_21 ) ) {
F_20 ( & V_44 -> V_50 , L_4 ,
V_49 -> V_52 ) ;
return F_24 ( V_21 ) ;
}
V_22 -> V_23 = V_21 ;
V_22 -> V_40 = V_49 -> V_40 ;
V_22 -> V_39 = V_49 -> V_39 ;
V_34 = F_27 ( & V_47 ) ;
if ( V_34 ) {
F_20 ( & V_44 -> V_50 ,
L_6 , V_34 ) ;
return V_34 ;
}
V_34 = F_28 ( & V_45 ,
V_46 ) ;
if ( V_34 ) {
F_20 ( & V_44 -> V_50 ,
L_7 , V_34 ) ;
F_17 ( & V_47 ) ;
}
return V_34 ;
}
