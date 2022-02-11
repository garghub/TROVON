static int F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int V_4 )
{
int V_5 ;
int V_6 ;
unsigned int V_7 = 0 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 V_12 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
int V_13 ;
T_1 V_14 = ( ( V_5 + 1 ) % 2 ) ? V_9 -> V_15 : V_9 -> V_16 ;
if ( V_7 + V_3 [ V_5 ] >= V_17 )
return - V_18 ;
V_14 = ( V_5 % 2 ) ? V_9 -> V_16 : V_9 -> V_15 ;
for ( V_13 = 0 ; V_13 < V_3 [ V_5 ] ; V_13 ++ )
V_9 -> V_19 [ V_7 ++ ] = V_14 ;
}
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_20 = V_9 -> V_21 ;
V_12 . V_7 = V_7 * sizeof( * V_9 -> V_19 ) ;
V_12 . V_19 = V_9 -> V_19 ;
V_6 = F_2 ( V_9 -> V_22 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_3 ( V_9 -> V_23 , & V_12 , 1 ) ;
if ( V_6 )
F_4 ( & V_9 -> V_23 -> V_2 , L_1 ) ;
F_5 ( V_9 -> V_22 ) ;
return V_6 ? V_6 : V_4 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( ! V_24 )
return - V_18 ;
V_9 -> V_21 = V_24 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_25 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_25 >= 90 )
V_9 -> V_15 = V_26 ;
else if ( V_25 >= 80 )
V_9 -> V_15 = V_27 ;
else if ( V_25 >= 75 )
V_9 -> V_15 = V_28 ;
else if ( V_25 >= 70 )
V_9 -> V_15 = V_29 ;
else if ( V_25 >= 60 )
V_9 -> V_15 = V_30 ;
else
V_9 -> V_15 = V_31 ;
if ( V_9 -> V_32 ) {
V_9 -> V_15 = ~ V_9 -> V_15 ;
V_9 -> V_16 = 0xffff ;
} else {
V_9 -> V_16 = 0 ;
}
return 0 ;
}
static int F_8 ( struct V_33 * V_23 )
{
int V_6 ;
T_3 V_34 ;
struct V_8 * V_9 ;
V_9 = F_9 ( & V_23 -> V_2 , sizeof( * V_9 ) , V_35 ) ;
if ( ! V_9 )
return - V_36 ;
V_9 -> V_22 = F_10 ( & V_23 -> V_2 , L_2 ) ;
if ( F_11 ( V_9 -> V_22 ) )
return F_12 ( V_9 -> V_22 ) ;
V_9 -> V_37 = F_13 ( & V_23 -> V_2 , V_38 ) ;
if ( ! V_9 -> V_37 )
return - V_36 ;
V_9 -> V_37 -> V_39 = F_1 ;
V_9 -> V_37 -> V_40 = F_6 ;
V_9 -> V_37 -> V_41 = F_7 ;
V_9 -> V_37 -> V_42 = V_43 ;
V_9 -> V_37 -> V_10 = V_9 ;
V_9 -> V_23 = V_23 ;
V_9 -> V_32 = F_14 ( V_23 -> V_2 . V_44 ,
L_3 ) ;
V_6 = F_15 ( V_23 -> V_2 . V_44 , L_4 , & V_34 ) ;
if ( V_6 )
V_34 = 50 ;
F_7 ( V_9 -> V_37 , V_34 ) ;
V_9 -> V_21 = V_45 ;
return F_16 ( & V_23 -> V_2 , V_9 -> V_37 ) ;
}
static int F_17 ( struct V_33 * V_23 )
{
return 0 ;
}
