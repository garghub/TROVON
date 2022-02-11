int F_1 ( T_1 V_1 , T_2 V_2 )
{
return F_2 ( V_1 , V_3 ,
( 1 << V_2 ) ) ;
}
int F_3 ( T_1 V_1 , T_2 V_2 )
{
T_3 V_4 ;
V_4 = 1 << V_2 ;
F_4 ( V_4 , V_4 , V_1 , V_3 ) ;
return 0 ;
}
int F_5 ( T_1 V_1 , T_2 V_5 , T_2 V_6 )
{
T_3 V_7 , V_8 ;
int V_9 ;
V_7 = 1 << V_5 ;
V_8 = 1 << V_6 ;
if ( F_2 ( V_1 , V_3 , V_7 ) == 0 )
return - V_10 ;
F_4 ( 0xffffffff , V_8 , V_1 , V_11 ) ;
F_4 ( V_7 , 0 , V_1 , V_3 ) ;
F_6 ( F_2 ( V_1 , V_11 ,
V_8 ) ,
V_12 , V_9 ) ;
return ( V_9 == V_12 ) ? - V_13 : 0 ;
}
int F_7 ( struct V_14 * V_15 , T_2 V_16 ,
T_2 V_17 )
{
T_3 V_18 ;
V_18 = F_8 ( V_16 ) ;
F_4 ( V_18 , ( V_17 << F_9 ( V_18 ) ) , V_15 -> V_19 ,
V_20 ) ;
return 0 ;
}
int F_10 ( struct V_14 * V_15 , T_2 V_16 ,
T_2 V_17 )
{
T_3 V_18 ;
V_18 = F_11 ( V_16 ) ;
F_4 ( V_18 , ( V_17 << F_9 ( V_18 ) ) , V_15 -> V_19 ,
V_20 ) ;
return 0 ;
}
int F_12 ( struct V_14 * V_15 , T_2 V_16 )
{
T_3 V_18 ;
V_18 = F_13 ( V_16 ) ;
return F_2 ( V_15 -> V_19 , V_21 ,
V_18 ) ;
}
int F_14 ( struct V_14 * V_15 , T_2 V_16 )
{
T_3 V_18 ;
V_18 = F_11 ( V_16 ) ;
return F_2 ( V_15 -> V_19 ,
V_20 , V_18 ) ;
}
int F_15 ( struct V_14 * V_15 , T_2 V_17 )
{
T_3 V_22 ;
V_22 = V_17 << F_9 ( V_23 ) ;
F_4 ( V_23 , V_22 , V_15 -> V_19 ,
V_20 ) ;
return 0 ;
}
int F_16 ( struct V_14 * V_15 )
{
T_3 V_9 = 0 ;
while ( ( F_17 ( V_15 -> V_19 , V_21 ) &
V_24 ) &&
( V_9 ++ < V_25 ) )
F_18 ( 1 ) ;
if ( V_9 > V_25 ) {
F_19 ( L_1 ,
V_15 -> V_26 ) ;
return - V_27 ;
}
F_20 ( L_2 , V_9 ) ;
return 0 ;
}
int F_21 ( struct V_28 * V_29 ,
struct V_28 * V_30 )
{
F_22 ( ( 1 << V_30 -> V_31 ) ,
V_29 -> V_15 . V_32 -> V_19 , V_33 ) ;
return 0 ;
}
int F_23 ( struct V_28 * V_29 ,
struct V_28 * V_30 )
{
F_24 ( ( 1 << V_30 -> V_31 ) ,
V_29 -> V_15 . V_32 -> V_19 , V_33 ) ;
return 0 ;
}
int F_25 ( struct V_28 * V_29 ,
struct V_28 * V_30 )
{
return F_2 ( V_29 -> V_15 . V_32 -> V_19 ,
V_33 , ( 1 << V_30 -> V_31 ) ) ;
}
int F_26 ( struct V_28 * V_34 )
{
struct V_35 * V_36 ;
T_3 V_4 = 0 ;
for ( V_36 = V_34 -> V_37 ; V_36 && V_36 -> V_38 ; V_36 ++ ) {
if ( ! V_36 -> V_34 )
continue;
V_4 |= 1 << V_36 -> V_34 -> V_31 ;
V_36 -> V_39 = 0 ;
}
F_24 ( V_4 , V_34 -> V_15 . V_32 -> V_19 ,
V_33 ) ;
return 0 ;
}
