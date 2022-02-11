static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 V_6 [ 2 ] ;
T_1 V_7 [ 2 ] = { V_3 } ;
V_6 [ 0 ] . V_8 = V_9 ;
V_6 [ 0 ] . V_10 = 0 ;
V_6 [ 0 ] . V_11 = 1 ;
V_6 [ 0 ] . V_7 = V_7 ;
V_6 [ 1 ] . V_8 = V_9 ;
V_6 [ 1 ] . V_10 = V_12 ;
V_6 [ 1 ] . V_11 = 1 ;
V_6 [ 1 ] . V_7 = & V_7 [ 1 ] ;
* V_4 = 0 ;
if ( F_2 ( V_2 -> V_13 , V_6 , 2 ) != 2 )
return - V_14 ;
* V_4 = V_7 [ 1 ] ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 V_6 ;
T_1 V_7 [ 2 ] = { V_3 , V_4 } ;
V_6 . V_8 = V_9 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = sizeof( V_7 ) ;
V_6 . V_7 = V_7 ;
if ( F_2 ( V_2 -> V_13 , & V_6 , 1 ) != 1 )
return - V_14 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 V_6 ;
T_1 V_7 [ 3 ] = { V_3 , ( T_1 ) ( V_4 >> 8 ) , ( T_1 ) ( V_4 & 0xff ) } ;
V_6 . V_8 = V_9 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = sizeof( V_7 ) ;
V_6 . V_7 = V_7 ;
if ( F_2 ( V_2 -> V_13 , & V_6 , 1 ) != 1 )
return - V_14 ;
return 0 ;
}
int F_5 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
int V_17 ;
T_1 V_18 ;
V_17 = V_19 . V_20 -> V_21 ( V_16 , 1 ) ;
if ( V_17 )
return V_17 ;
F_7 ( 1 ) ;
V_17 = F_3 ( V_2 , V_22 , 1 ) ;
F_8 ( 100 , 1000 ) ;
V_17 = F_3 ( V_2 , V_22 , V_23 ) ;
if ( V_17 < 0 )
goto V_24;
V_17 = F_3 ( V_2 , V_25 , V_26 ) ;
if ( V_17 < 0 )
goto V_24;
V_17 = F_3 ( V_2 , V_27 , V_28 ) ;
if ( V_17 < 0 )
goto V_24;
V_17 = F_1 ( V_2 , V_29 , & V_18 ) ;
if ( V_17 < 0 )
goto V_24;
if ( V_18 != V_30 ) {
V_17 = - V_31 ;
goto V_24;
}
V_19 . V_32 = 0 ;
V_19 . V_33 = true ;
return 0 ;
V_24:
V_19 . V_20 -> V_21 ( V_16 , 0 ) ;
return V_17 ;
}
int F_9 ( struct V_15 * V_16 )
{
return V_19 . V_20 -> V_21 ( V_16 , 0 ) ;
}
int F_10 ( struct V_15 * V_16 , T_3 * V_18 )
{
static const struct V_34 V_35 = {
. V_36 = 0 ,
. V_37 = 60000000
} ;
struct V_34 V_38 , V_39 , V_40 ;
F_11 ( & V_38 ) ;
V_39 = F_12 ( V_19 . V_41 , V_35 ) ;
V_40 = F_13 ( V_38 , V_39 ) ;
if ( V_40 . V_36 >= 0 && V_40 . V_37 >= 0 ) {
* V_18 = V_42 |
V_43 ;
} else {
* V_18 = V_44 |
V_45 ;
}
return 0 ;
}
int F_14 ( struct V_15 * V_16 , T_3 V_18 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
int V_17 ;
V_18 = F_15 ( V_18 , 0 , V_46 ) ;
V_17 = F_4 ( V_2 , V_47 , V_18 ) ;
if ( V_17 < 0 )
return V_17 ;
F_11 ( & V_19 . V_41 ) ;
V_19 . V_32 = V_18 ;
return 0 ;
}
int F_16 ( struct V_15 * V_16 , T_3 V_18 )
{
return F_14 ( V_16 , V_19 . V_32 + V_18 ) ;
}
int F_17 ( struct V_15 * V_16 , T_3 * V_18 )
{
* V_18 = V_19 . V_32 ;
return 0 ;
}
int F_18 ( struct V_15 * V_16 , T_3 V_18 )
{
return 0 ;
}
int F_19 ( struct V_15 * V_16 , T_3 V_18 )
{
return 0 ;
}
