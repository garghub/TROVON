int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
struct V_5 V_6 ;
struct V_3 * V_7 ;
T_1 V_8 ;
int V_9 ;
V_9 = F_2 ( V_2 , V_10 ,
NULL , 0 , & V_6 , sizeof( V_6 ) ) ;
if ( V_9 )
return V_9 ;
V_8 = F_3 ( V_6 . V_8 ) ;
if ( V_8 < sizeof( * V_7 ) )
return - V_11 ;
V_7 = F_4 ( V_8 , V_12 ) ;
if ( ! V_7 )
return - V_13 ;
V_9 = F_2 ( V_2 , V_14 , NULL , 0 ,
V_7 , V_8 ) ;
if ( V_9 ) {
F_5 ( V_7 ) ;
return V_9 ;
}
* V_4 = V_7 ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 ,
T_2 V_15 , T_2 V_16 ,
struct V_17 * V_18 )
{
struct V_19 V_20 ;
struct V_21 V_22 ;
int V_9 ;
V_20 . V_15 = V_15 ;
V_20 . V_16 = V_16 ;
V_9 = F_2 ( V_2 , V_23 ,
& V_20 , sizeof( V_20 ) , & V_22 , sizeof( V_22 ) ) ;
if ( V_9 )
return V_9 ;
memcpy ( V_18 , & V_22 . V_18 , sizeof( * V_18 ) ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 ,
T_2 V_15 , T_2 V_16 ,
struct V_17 * V_18 )
{
struct V_24 V_20 ;
V_20 . V_15 = V_15 ;
V_20 . V_16 = V_16 ;
memcpy ( & V_20 . V_18 , V_18 , sizeof( V_20 . V_18 ) ) ;
return F_2 ( V_2 , V_25 ,
& V_20 , sizeof( V_20 ) , NULL , 0 ) ;
}
int F_8 ( struct V_1 * V_2 ,
T_2 V_26 )
{
struct V_27 V_20 ;
V_20 . V_26 = V_26 ;
return F_2 ( V_2 , V_28 ,
& V_20 , sizeof( V_20 ) , NULL , 0 ) ;
}
int F_9 ( struct V_1 * V_2 ,
T_2 V_26 )
{
struct V_29 V_20 ;
V_20 . V_26 = V_26 ;
return F_2 ( V_2 , V_30 ,
& V_20 , sizeof( V_20 ) , NULL , 0 ) ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_31 ,
T_3 * V_32 , T_3 * V_33 , T_2 * V_34 ,
T_2 * V_35 )
{
struct V_36 V_20 ;
struct V_37 V_22 ;
int V_9 ;
V_20 . V_31 = F_11 ( V_31 ) ;
V_9 = F_2 ( V_2 , V_38 ,
& V_20 , sizeof( V_20 ) , & V_22 , sizeof( V_22 ) ) ;
if ( V_9 )
return V_9 ;
* V_32 = F_12 ( V_22 . V_32 ) ;
* V_33 = F_12 ( V_22 . V_33 ) ;
* V_34 = V_22 . V_34 ;
* V_35 = V_22 . V_35 ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_31 ,
T_3 V_32 , T_3 V_33 , T_2 V_34 ,
T_2 V_35 )
{
struct V_39 V_20 ;
V_20 . V_31 = F_11 ( V_31 ) ;
V_20 . V_32 = F_14 ( V_32 ) ;
V_20 . V_33 = F_14 ( V_33 ) ;
V_20 . V_34 = V_34 ;
V_20 . V_35 = V_35 ;
return F_2 ( V_2 , V_40 ,
& V_20 , sizeof( V_20 ) , NULL , 0 ) ;
}
int F_15 ( struct V_1 * V_2 ,
T_1 V_31 , T_1 V_8 )
{
struct V_41 V_20 ;
V_20 . V_31 = F_11 ( V_31 ) ;
V_20 . V_8 = F_11 ( V_8 ) ;
return F_2 ( V_2 , V_42 ,
& V_20 , sizeof( V_20 ) , NULL , 0 ) ;
}
int F_16 ( struct V_1 * V_2 ,
T_1 V_31 )
{
struct V_43 V_20 ;
V_20 . V_31 = F_11 ( V_31 ) ;
return F_2 ( V_2 , V_44 ,
& V_20 , sizeof( V_20 ) , NULL , 0 ) ;
}
int F_17 ( struct V_1 * V_2 ,
T_1 V_31 )
{
struct V_45 V_20 ;
V_20 . V_31 = F_11 ( V_31 ) ;
return F_2 ( V_2 , V_46 ,
& V_20 , sizeof( V_20 ) , NULL , 0 ) ;
}
int F_18 ( struct V_1 * V_2 ,
T_1 V_31 , T_1 V_8 )
{
struct V_47 V_20 ;
V_20 . V_31 = F_11 ( V_31 ) ;
V_20 . V_8 = F_11 ( V_8 ) ;
return F_2 ( V_2 , V_48 ,
& V_20 , sizeof( V_20 ) , NULL , 0 ) ;
}
int F_19 ( struct V_1 * V_2 ,
T_1 V_31 )
{
struct V_49 V_20 ;
V_20 . V_31 = F_11 ( V_31 ) ;
return F_2 ( V_2 , V_50 ,
& V_20 , sizeof( V_20 ) , NULL , 0 ) ;
}
int F_20 ( struct V_1 * V_2 ,
T_1 V_31 )
{
struct V_51 V_20 ;
V_20 . V_31 = F_11 ( V_31 ) ;
return F_2 ( V_2 , V_52 ,
& V_20 , sizeof( V_20 ) , NULL , 0 ) ;
}
