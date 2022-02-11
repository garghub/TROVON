static int F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int V_4 )
{
int V_5 ;
int V_6 ;
unsigned int V_7 = 0 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 V_12 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
unsigned int V_13 ;
int V_14 ;
T_1 V_15 ;
V_13 = F_2 ( V_3 [ V_5 ] * V_9 -> V_16 , 1000000 ) ;
if ( V_7 + V_13 >= V_17 )
return - V_18 ;
V_15 = ( V_5 % 2 ) ? V_9 -> V_19 : V_9 -> V_20 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
V_9 -> V_21 [ V_7 ++ ] = V_15 ;
}
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_22 = V_9 -> V_16 * 16 ;
V_12 . V_7 = V_7 * sizeof( * V_9 -> V_21 ) ;
V_12 . V_21 = V_9 -> V_21 ;
V_6 = F_3 ( V_9 -> V_23 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_4 ( V_9 -> V_24 , & V_12 , 1 ) ;
if ( V_6 )
F_5 ( & V_9 -> V_24 -> V_2 , L_1 ) ;
F_6 ( V_9 -> V_23 ) ;
return V_6 ? V_6 : V_4 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_25 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( ! V_25 )
return - V_18 ;
V_9 -> V_16 = V_25 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_26 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_26 >= 90 )
V_9 -> V_20 = V_27 ;
else if ( V_26 >= 80 )
V_9 -> V_20 = V_28 ;
else if ( V_26 >= 75 )
V_9 -> V_20 = V_29 ;
else if ( V_26 >= 70 )
V_9 -> V_20 = V_30 ;
else if ( V_26 >= 60 )
V_9 -> V_20 = V_31 ;
else
V_9 -> V_20 = V_32 ;
if ( V_9 -> V_33 ) {
V_9 -> V_20 = ~ V_9 -> V_20 ;
V_9 -> V_19 = 0xffff ;
} else {
V_9 -> V_19 = 0 ;
}
return 0 ;
}
static int F_9 ( struct V_34 * V_24 )
{
int V_6 ;
T_3 V_35 ;
struct V_8 * V_9 ;
V_9 = F_10 ( & V_24 -> V_2 , sizeof( * V_9 ) , V_36 ) ;
if ( ! V_9 )
return - V_37 ;
V_9 -> V_23 = F_11 ( & V_24 -> V_2 , L_2 ) ;
if ( F_12 ( V_9 -> V_23 ) )
return F_13 ( V_9 -> V_23 ) ;
V_9 -> V_38 = F_14 ( & V_24 -> V_2 , V_39 ) ;
if ( ! V_9 -> V_38 )
return - V_37 ;
V_9 -> V_38 -> V_40 = F_1 ;
V_9 -> V_38 -> V_41 = F_7 ;
V_9 -> V_38 -> V_42 = F_8 ;
V_9 -> V_38 -> V_43 = V_44 ;
V_9 -> V_38 -> V_10 = V_9 ;
V_9 -> V_24 = V_24 ;
V_9 -> V_33 = F_15 ( V_24 -> V_2 . V_45 ,
L_3 ) ;
V_6 = F_16 ( V_24 -> V_2 . V_45 , L_4 , & V_35 ) ;
if ( V_6 )
V_35 = 50 ;
F_8 ( V_9 -> V_38 , V_35 ) ;
V_9 -> V_16 = V_46 ;
return F_17 ( & V_24 -> V_2 , V_9 -> V_38 ) ;
}
static int F_18 ( struct V_34 * V_24 )
{
return 0 ;
}
