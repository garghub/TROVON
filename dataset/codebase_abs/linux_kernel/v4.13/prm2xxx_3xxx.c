int F_1 ( T_1 V_1 , T_1 V_2 , T_2 V_3 , T_3 V_4 )
{
return F_2 ( V_3 , V_5 ,
( 1 << V_1 ) ) ;
}
int F_3 ( T_1 V_1 , T_1 V_2 , T_2 V_3 , T_3 V_4 )
{
T_4 V_6 ;
V_6 = 1 << V_1 ;
F_4 ( V_6 , V_6 , V_3 , V_5 ) ;
return 0 ;
}
int F_5 ( T_1 V_7 , T_1 V_8 , T_1 V_2 ,
T_2 V_3 , T_3 V_9 , T_3 V_10 )
{
T_4 V_11 , V_12 ;
int V_13 ;
V_11 = 1 << V_7 ;
V_12 = 1 << V_8 ;
if ( F_2 ( V_3 , V_5 , V_11 ) == 0 )
return - V_14 ;
F_4 ( 0xffffffff , V_12 , V_3 , V_15 ) ;
F_4 ( V_11 , 0 , V_3 , V_5 ) ;
F_6 ( F_2 ( V_3 , V_15 ,
V_12 ) ,
V_16 , V_13 ) ;
return ( V_13 == V_16 ) ? - V_17 : 0 ;
}
int F_7 ( struct V_18 * V_19 , T_1 V_20 ,
T_1 V_21 )
{
T_4 V_22 ;
V_22 = F_8 ( V_20 ) ;
F_4 ( V_22 , ( V_21 << F_9 ( V_22 ) ) , V_19 -> V_23 ,
V_24 ) ;
return 0 ;
}
int F_10 ( struct V_18 * V_19 , T_1 V_20 ,
T_1 V_21 )
{
T_4 V_22 ;
V_22 = F_11 ( V_20 ) ;
F_4 ( V_22 , ( V_21 << F_9 ( V_22 ) ) , V_19 -> V_23 ,
V_24 ) ;
return 0 ;
}
int F_12 ( struct V_18 * V_19 , T_1 V_20 )
{
T_4 V_22 ;
V_22 = F_13 ( V_20 ) ;
return F_2 ( V_19 -> V_23 , V_25 ,
V_22 ) ;
}
int F_14 ( struct V_18 * V_19 , T_1 V_20 )
{
T_4 V_22 ;
V_22 = F_11 ( V_20 ) ;
return F_2 ( V_19 -> V_23 ,
V_24 , V_22 ) ;
}
int F_15 ( struct V_18 * V_19 , T_1 V_21 )
{
T_4 V_26 ;
V_26 = V_21 << F_9 ( V_27 ) ;
F_4 ( V_27 , V_26 , V_19 -> V_23 ,
V_24 ) ;
return 0 ;
}
int F_16 ( struct V_18 * V_19 )
{
T_4 V_13 = 0 ;
while ( ( F_17 ( V_19 -> V_23 , V_25 ) &
V_28 ) &&
( V_13 ++ < V_29 ) )
F_18 ( 1 ) ;
if ( V_13 > V_29 ) {
F_19 ( L_1 ,
V_19 -> V_30 ) ;
return - V_31 ;
}
F_20 ( L_2 , V_13 ) ;
return 0 ;
}
int F_21 ( struct V_32 * V_33 ,
struct V_32 * V_34 )
{
F_22 ( ( 1 << V_34 -> V_35 ) ,
V_33 -> V_19 . V_36 -> V_23 , V_37 ) ;
return 0 ;
}
int F_23 ( struct V_32 * V_33 ,
struct V_32 * V_34 )
{
F_24 ( ( 1 << V_34 -> V_35 ) ,
V_33 -> V_19 . V_36 -> V_23 , V_37 ) ;
return 0 ;
}
int F_25 ( struct V_32 * V_33 ,
struct V_32 * V_34 )
{
return F_2 ( V_33 -> V_19 . V_36 -> V_23 ,
V_37 , ( 1 << V_34 -> V_35 ) ) ;
}
int F_26 ( struct V_32 * V_38 )
{
struct V_39 * V_40 ;
T_4 V_6 = 0 ;
for ( V_40 = V_38 -> V_41 ; V_40 && V_40 -> V_42 ; V_40 ++ ) {
if ( ! V_40 -> V_38 )
continue;
V_6 |= 1 << V_40 -> V_38 -> V_35 ;
V_40 -> V_43 = 0 ;
}
F_24 ( V_6 , V_38 -> V_19 . V_36 -> V_23 ,
V_37 ) ;
return 0 ;
}
