static T_1 F_1 ( char * V_1 , T_2 V_2 , T_3 V_3 )
{
T_4 V_4 = V_5 -> V_4 & V_6 ;
T_4 V_7 = V_5 -> V_4 & ~ V_6 ;
T_4 V_8 = V_9 ;
struct V_10 {
T_4 V_11 ;
T_4 V_12 ;
} V_10 [ 2 ] = { { 0 } , { 0 } } ;
T_3 V_13 = 0 ;
int V_14 ;
if ( V_7 & V_15 ) {
if ( V_4 > V_8 )
V_4 = 0 ;
V_10 [ 0 ] = (struct V_10 ) { . V_11 = V_4 , . V_12 = V_8 - V_4 } ;
V_10 [ 1 ] = (struct V_10 ) { . V_11 = 0 , . V_12 = V_4 } ;
} else {
V_10 [ 0 ] = (struct V_10 ) { . V_11 = 0 , . V_12 = F_2 (cursor, size) } ;
}
for ( V_14 = 0 ; V_14 < V_16 ( V_10 ) && V_3 > V_13 ; V_14 ++ ) {
V_13 += F_3 ( V_1 + V_13 , V_3 - V_13 , & V_2 ,
V_5 -> V_17 + V_10 [ V_14 ] . V_11 , V_10 [ V_14 ] . V_12 ) ;
V_2 -= V_10 [ V_14 ] . V_12 ;
}
return V_13 ;
}
static int F_4 ( T_5 V_18 )
{
struct V_19 T_6 * V_20 ;
V_20 = F_5 ( V_18 , sizeof( * V_20 ) , V_21 ) ;
if ( ! V_20 )
return - V_22 ;
V_9 = V_20 -> V_23 ;
V_5 = F_5 ( V_18 ,
V_9 + sizeof( * V_5 ) ,
V_21 ) ;
F_6 ( V_20 ) ;
if ( ! V_5 )
return - V_22 ;
F_7 ( F_1 ) ;
return 0 ;
}
static int F_8 ( struct V_24 * V_25 )
{
int V_26 ;
struct V_27 V_28 ;
V_26 = F_9 ( V_29 , & V_28 , sizeof( V_28 ) ) ;
if ( V_26 )
return V_26 ;
V_26 = F_4 ( V_28 . V_30 ) ;
if ( V_26 )
return V_26 ;
return F_10 () ;
}
static int F_11 ( struct V_24 * V_25 )
{
F_12 () ;
if ( V_5 )
F_6 ( V_5 ) ;
return 0 ;
}
static int T_7 F_13 ( void )
{
struct V_24 * V_25 ;
V_25 = F_14 ( L_1 , - 1 , NULL , 0 ) ;
if ( F_15 ( V_25 ) )
return F_16 ( V_25 ) ;
F_17 ( & V_31 ) ;
return 0 ;
}
