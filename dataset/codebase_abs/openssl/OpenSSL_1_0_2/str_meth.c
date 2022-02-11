T_1 * F_1 ( char * V_1 )
{
T_1 * V_2 =
( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( V_2 ) {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_1 = F_3 ( V_1 ) ;
}
return V_2 ;
}
void F_4 ( T_1 * V_2 )
{
if ( ! V_2 )
return;
F_5 ( V_2 -> V_1 ) ;
V_2 -> V_1 = NULL ;
F_5 ( V_2 ) ;
}
int F_6 ( T_1 * V_3 ,
T_2 V_4 )
{
V_3 -> V_5 = V_4 ;
return 1 ;
}
int F_7 ( T_1 * V_3 ,
T_3 V_6 )
{
V_3 -> V_7 = V_6 ;
return 1 ;
}
int F_8 ( T_1 * V_3 ,
T_4
V_8 )
{
V_3 -> V_9 = V_8 ;
return 1 ;
}
int F_9 ( T_1 * V_3 ,
T_5 V_10 )
{
V_3 -> V_11 = V_10 ;
return 1 ;
}
int F_10 ( T_1 * V_3 ,
T_6 V_12 )
{
V_3 -> V_13 = V_12 ;
return 1 ;
}
int F_11 ( T_1 * V_3 ,
T_7 V_14 )
{
V_3 -> V_15 = V_14 ;
return 1 ;
}
int F_12 ( T_1 * V_3 ,
T_8 V_16 )
{
V_3 -> V_17 = V_16 ;
return 1 ;
}
int F_13 ( T_1 * V_3 ,
T_8 V_18 )
{
V_3 -> V_19 = V_18 ;
return 1 ;
}
int F_14 ( T_1 * V_3 ,
T_9
V_20 )
{
V_3 -> V_21 = V_20 ;
return 1 ;
}
int F_15 ( T_1 * V_3 ,
T_10
V_22 )
{
V_3 -> V_23 = V_22 ;
return 1 ;
}
int F_16 ( T_1 * V_3 ,
T_11 V_24 )
{
V_3 -> V_25 = V_24 ;
return 1 ;
}
int F_17 ( T_1 * V_3 ,
T_12 V_26 )
{
V_3 -> V_27 = V_26 ;
return 1 ;
}
int F_18 ( T_1 * V_3 ,
T_12 V_28 )
{
V_3 -> V_29 = V_28 ;
return 1 ;
}
int F_19 ( T_1 * V_3 ,
T_12 V_30 )
{
V_3 -> V_31 = V_30 ;
return 1 ;
}
int F_20 ( T_1 * V_3 ,
T_13 V_32 )
{
V_3 -> V_33 = V_32 ;
return 1 ;
}
T_2 F_21 ( T_1
* V_3 )
{
return V_3 -> V_5 ;
}
T_3 F_22 ( T_1 * V_3 )
{
return V_3 -> V_7 ;
}
T_4 F_23 ( T_1
* V_3 )
{
return V_3 -> V_9 ;
}
T_5 F_24 ( T_1 * V_3 )
{
return V_3 -> V_11 ;
}
T_6 F_25 ( T_1 * V_3 )
{
return V_3 -> V_13 ;
}
T_7 F_26 ( T_1
* V_3 )
{
return V_3 -> V_15 ;
}
T_8 F_27 ( T_1
* V_3 )
{
return V_3 -> V_17 ;
}
T_8 F_28 ( T_1
* V_3 )
{
return V_3 -> V_19 ;
}
T_9 F_29 ( T_1
* V_3 )
{
return V_3 -> V_21 ;
}
T_10 F_30 ( T_1
* V_3 )
{
return V_3 -> V_23 ;
}
T_11 F_31 ( T_1 * V_3 )
{
return V_3 -> V_25 ;
}
T_12 F_32 ( T_1
* V_3 )
{
return V_3 -> V_27 ;
}
T_12 F_33 ( T_1 * V_3 )
{
return V_3 -> V_29 ;
}
T_12 F_34 ( T_1
* V_3 )
{
return V_3 -> V_31 ;
}
T_13 F_35 ( T_1 * V_3 )
{
return V_3 -> V_33 ;
}
