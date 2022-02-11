static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , T_1 * V_5 , T_1 * V_6 )
{
struct V_7 V_8 ;
struct V_9 * V_10 ;
void * V_11 ;
T_1 * V_12 ;
T_1 * V_13 = V_13 ;
T_2 V_14 ;
int V_15 ;
V_10 = V_11 = F_2 ( sizeof( * V_10 ) * ( V_4 + 2 ) , V_16 ) ;
if ( ! V_11 )
return - V_17 ;
F_3 ( & V_8 ) ;
V_12 = V_11 ;
V_12 [ 0 ] = V_3 ;
if ( V_4 == 1 ) {
V_12 [ 1 ] = * V_5 ;
V_5 = & V_12 [ 1 ] ;
V_13 = V_6 ;
V_6 = & V_12 [ 2 ] ;
}
++ V_10 ;
V_10 [ 0 ] . V_5 = V_12 ;
V_10 [ 0 ] . V_18 = 2 ;
F_4 ( & V_10 [ 0 ] , & V_8 ) ;
++ V_10 ;
for ( V_14 = 0 ; V_14 < V_4 ; ++ V_14 ) {
if ( V_6 )
V_10 [ V_14 ] . V_6 = & V_6 [ V_14 ] ;
if ( V_5 )
V_10 [ V_14 ] . V_5 = & V_5 [ V_14 ] ;
V_10 [ V_14 ] . V_18 = 2 ;
F_4 ( & V_10 [ V_14 ] , & V_8 ) ;
}
V_15 = F_5 ( V_2 , & V_8 ) ;
if ( V_4 == 1 )
V_13 [ 0 ] = V_12 [ 2 ] ;
F_6 ( V_11 ) ;
return V_15 ;
}
static int F_7 ( struct V_19 * V_20 ,
T_2 V_21 , T_2 V_4 , T_1 * V_22 )
{
struct V_1 * V_2 = F_8 ( V_20 ) ;
return F_1 ( V_2 , F_9 ( V_21 ) , V_4 , NULL , V_22 ) ;
}
static int F_10 ( struct V_19 * V_20 , T_2 V_23 )
{
struct V_1 * V_2 = F_8 ( V_20 ) ;
T_1 V_15 , V_24 ;
return F_1 ( V_2 , F_9 ( V_23 ) , 1 , & V_24 , & V_15 ) ? : V_15 ;
}
static int F_11 ( struct V_19 * V_20 , T_2 V_23 , T_1 V_25 )
{
struct V_1 * V_2 = F_8 ( V_20 ) ;
T_1 V_24 ;
return F_1 ( V_2 , F_12 ( V_23 ) , 1 , & V_25 , & V_24 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
int V_28 ;
if ( V_2 -> V_29 > V_30 ) {
F_14 ( & V_2 -> V_20 , L_1 , V_2 -> V_29 ) ;
return - V_31 ;
}
V_2 -> V_32 = 16 ;
V_28 = F_15 ( V_2 ) ;
if ( V_28 ) {
F_16 ( & V_2 -> V_20 , L_2 ) ;
return V_28 ;
}
V_27 = F_17 ( & V_2 -> V_20 , V_33 , V_2 -> V_34 , & V_35 ) ;
if ( F_18 ( V_27 ) )
return F_19 ( V_27 ) ;
F_20 ( V_2 , V_27 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_22 ( V_2 ) ;
F_23 ( V_27 ) ;
F_20 ( V_2 , NULL ) ;
return 0 ;
}
