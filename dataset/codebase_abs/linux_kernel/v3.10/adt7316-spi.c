static int F_1 ( void * V_1 , T_1 V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_1 ;
T_1 V_7 [ 2 ] ;
int V_8 = 0 ;
if ( V_3 > V_9 )
V_3 = V_9 ;
V_7 [ 0 ] = V_10 ;
V_7 [ 1 ] = V_2 ;
V_8 = F_2 ( V_6 , V_7 , 2 ) ;
if ( V_8 < 0 ) {
F_3 ( & V_6 -> V_11 , L_1 ) ;
return V_8 ;
}
V_7 [ 0 ] = V_12 ;
V_8 = F_4 ( V_6 , V_7 , 1 , V_4 , V_3 ) ;
if ( V_8 < 0 ) {
F_3 ( & V_6 -> V_11 , L_2 ) ;
return V_8 ;
}
return 0 ;
}
static int F_5 ( void * V_1 , T_1 V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_1 ;
T_1 V_13 [ V_9 + 2 ] ;
int V_14 , V_8 = 0 ;
if ( V_3 > V_9 )
V_3 = V_9 ;
V_13 [ 0 ] = V_10 ;
V_13 [ 1 ] = V_2 ;
for ( V_14 = 0 ; V_14 < V_3 ; V_14 ++ )
V_13 [ V_14 + 2 ] = V_4 [ V_14 ] ;
V_8 = F_2 ( V_6 , V_13 , V_3 + 2 ) ;
if ( V_8 < 0 ) {
F_3 ( & V_6 -> V_11 , L_3 ) ;
return V_8 ;
}
return V_8 ;
}
static int F_6 ( void * V_1 , T_1 V_2 , T_1 * V_4 )
{
return F_1 ( V_1 , V_2 , 1 , V_4 ) ;
}
static int F_7 ( void * V_1 , T_1 V_2 , T_1 V_15 )
{
return F_5 ( V_1 , V_2 , 1 , & V_15 ) ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_16 V_17 = {
. V_1 = V_6 ,
. V_18 = V_6 -> V_18 ,
. V_19 = V_20 ,
. V_21 = F_6 ,
. V_22 = F_7 ,
. V_23 = F_1 ,
. V_24 = F_5 ,
} ;
if ( V_6 -> V_25 > V_26 ) {
F_3 ( & V_6 -> V_11 , L_4 ,
V_6 -> V_25 ) ;
return - V_27 ;
}
F_7 ( V_6 , 0 , 0 ) ;
F_7 ( V_6 , 0 , 0 ) ;
F_7 ( V_6 , 0 , 0 ) ;
return F_9 ( & V_6 -> V_11 , & V_17 , V_6 -> V_28 ) ;
}
static int F_10 ( struct V_5 * V_6 )
{
return F_11 ( & V_6 -> V_11 ) ;
}
