static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_4 ,
( V_3 << V_5 ) ,
V_2 -> V_6 , V_7 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_6 ,
V_7 ,
V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_6 ,
V_8 ,
V_9 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_10 ,
T_1 V_3 )
{
T_2 V_11 ;
V_11 = F_7 ( V_10 ) ;
F_2 ( V_11 , ( V_3 << F_8 ( V_11 ) ) , V_2 -> V_6 ,
V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_10 ,
T_1 V_3 )
{
T_2 V_11 ;
V_11 = F_10 ( V_10 ) ;
F_2 ( V_11 , ( V_3 << F_8 ( V_11 ) ) , V_2 -> V_6 ,
V_7 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_10 )
{
T_2 V_11 ;
V_11 = F_12 ( V_10 ) ;
return F_4 ( V_2 -> V_6 , V_8 ,
V_11 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_10 )
{
T_2 V_11 ;
V_11 = F_10 ( V_10 ) ;
return F_4 ( V_2 -> V_6 ,
V_7 , V_11 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_12 ;
V_12 = V_3 << F_8 ( V_13 ) ;
F_2 ( V_13 , V_12 ,
V_2 -> V_6 , V_7 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_2 V_14 = 0 ;
while ( ( F_16 ( V_2 -> V_6 , V_8 ) &
V_15 ) &&
( V_14 ++ < V_16 ) )
F_17 ( 1 ) ;
if ( V_14 > V_16 ) {
F_18 ( V_17 L_1
L_2 , V_2 -> V_18 ) ;
return - V_19 ;
}
F_19 ( L_3 , V_14 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_6 ,
V_20 ,
V_21 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_6 ,
V_8 ,
V_22 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_6 ,
V_7 ,
V_22 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_6 ,
V_20 ,
V_23 ) ;
}
static int F_24 ( T_1 V_10 )
{
switch ( V_10 ) {
case 0 :
return V_24 ;
case 1 :
return V_25 ;
case 2 :
return V_26 ;
case 3 :
return V_27 ;
default:
F_25 ( 1 ) ;
return - V_28 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_10 )
{
T_2 V_11 ;
V_11 = F_24 ( V_10 ) ;
return F_4 ( V_2 -> V_6 ,
V_20 , V_11 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
F_28 ( 0 , V_2 -> V_6 , V_20 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
return F_2 ( 0 ,
1 << V_29 ,
V_2 -> V_6 , V_7 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
return F_2 ( 1 << V_29 ,
0 , V_2 -> V_6 ,
V_7 ) ;
}
