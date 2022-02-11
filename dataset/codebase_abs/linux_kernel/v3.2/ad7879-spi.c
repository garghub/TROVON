static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_4 ( V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_6 ( V_6 ) ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 ,
T_1 V_7 , T_2 V_8 , T_1 * V_9 , T_1 * V_10 )
{
struct V_11 V_12 ;
struct V_13 * V_14 ;
void * V_15 ;
T_1 * V_16 ;
T_1 * V_17 = V_17 ;
T_2 V_18 ;
int V_19 ;
V_14 = V_15 = F_8 ( sizeof( * V_14 ) * ( V_8 + 2 ) , V_20 ) ;
if ( ! V_15 )
return - V_21 ;
F_9 ( & V_12 ) ;
V_16 = V_15 ;
V_16 [ 0 ] = V_7 ;
if ( V_8 == 1 ) {
V_16 [ 1 ] = * V_9 ;
V_9 = & V_16 [ 1 ] ;
V_17 = V_10 ;
V_10 = & V_16 [ 2 ] ;
}
++ V_14 ;
V_14 [ 0 ] . V_9 = V_16 ;
V_14 [ 0 ] . V_22 = 2 ;
F_10 ( & V_14 [ 0 ] , & V_12 ) ;
++ V_14 ;
for ( V_18 = 0 ; V_18 < V_8 ; ++ V_18 ) {
if ( V_10 )
V_14 [ V_18 ] . V_10 = & V_10 [ V_18 ] ;
if ( V_9 )
V_14 [ V_18 ] . V_9 = & V_9 [ V_18 ] ;
V_14 [ V_18 ] . V_22 = 2 ;
F_10 ( & V_14 [ V_18 ] , & V_12 ) ;
}
V_19 = F_11 ( V_4 , & V_12 ) ;
if ( V_8 == 1 )
V_17 [ 0 ] = V_16 [ 2 ] ;
F_12 ( V_15 ) ;
return V_19 ;
}
static int F_13 ( struct V_1 * V_2 ,
T_2 V_23 , T_2 V_8 , T_1 * V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_7 ( V_4 , F_14 ( V_23 ) , V_8 , NULL , V_24 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_19 , V_26 ;
return F_7 ( V_4 , F_14 ( V_25 ) , 1 , & V_26 , & V_19 ) ? : V_19 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_25 , T_1 V_27 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_26 ;
return F_7 ( V_4 , F_17 ( V_25 ) , 1 , & V_27 , & V_26 ) ;
}
static int T_3 F_18 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_28 ;
if ( V_4 -> V_29 > V_30 ) {
F_19 ( & V_4 -> V_2 , L_1 , V_4 -> V_29 ) ;
return - V_31 ;
}
V_4 -> V_32 = 16 ;
V_28 = F_20 ( V_4 ) ;
if ( V_28 ) {
F_21 ( & V_4 -> V_2 , L_2 ) ;
return V_28 ;
}
V_6 = F_22 ( & V_4 -> V_2 , V_33 , V_4 -> V_34 , & V_35 ) ;
if ( F_23 ( V_6 ) )
return F_24 ( V_6 ) ;
F_25 ( V_4 , V_6 ) ;
return 0 ;
}
static int T_4 F_26 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_27 ( V_6 ) ;
F_25 ( V_4 , NULL ) ;
return 0 ;
}
static int T_5 F_28 ( void )
{
return F_29 ( & V_36 ) ;
}
static void T_6 F_30 ( void )
{
F_31 ( & V_36 ) ;
}
