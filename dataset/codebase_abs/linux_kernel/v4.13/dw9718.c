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
int F_5 ( struct V_15 * V_16 , T_3 V_17 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
int V_18 ;
V_17 = F_7 ( V_17 , 0 , V_19 ) ;
V_18 = F_4 ( V_2 , V_20 , V_17 ) ;
if ( V_18 < 0 )
return V_18 ;
F_8 ( & V_21 . V_22 ) ;
V_21 . V_23 = V_17 ;
return 0 ;
}
int F_9 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
int V_18 ;
T_1 V_17 ;
if ( V_21 . V_24 )
return 0 ;
V_18 = V_21 . V_25 -> V_26 ( V_16 , 1 ) ;
if ( V_18 ) {
F_10 ( & V_2 -> V_27 , L_1 , V_18 ) ;
return V_18 ;
}
F_11 ( 100 ) ;
V_18 = F_1 ( V_2 , V_28 , & V_17 ) ;
if ( V_18 < 0 ) {
F_10 ( & V_2 -> V_27 , L_2 , V_18 ) ;
goto V_29;
}
if ( V_17 != V_30 )
F_12 ( & V_2 -> V_27 , L_3 , V_31 ) ;
V_18 = F_3 ( V_2 , V_32 ,
V_33 |
V_34 |
V_35 |
V_36 ) ;
if ( V_18 < 0 ) {
F_10 ( & V_2 -> V_27 , L_4 , V_18 ) ;
goto V_29;
}
V_18 = F_3 ( V_2 , V_28 ,
V_37 |
V_38 ) ;
if ( V_18 < 0 ) {
F_10 ( & V_2 -> V_27 , L_5 , V_18 ) ;
goto V_29;
}
V_18 = F_5 ( V_16 , V_21 . V_23 ) ;
if ( V_18 )
return V_18 ;
V_21 . V_39 = true ;
V_21 . V_24 = 1 ;
return 0 ;
V_29:
F_10 ( & V_2 -> V_27 , L_6 , V_31 ) ;
V_21 . V_25 -> V_26 ( V_16 , 0 ) ;
return V_18 ;
}
int F_13 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
int V_18 ;
if ( ! V_21 . V_24 )
return 0 ;
V_18 = V_21 . V_25 -> V_26 ( V_16 , 0 ) ;
if ( V_18 ) {
F_10 ( & V_2 -> V_27 , L_7 ,
V_31 ) ;
return V_18 ;
}
V_21 . V_24 = 0 ;
return 0 ;
}
int F_14 ( struct V_15 * V_16 , T_3 * V_17 )
{
static const struct V_40 V_41 = {
. V_42 = 0 ,
. V_43 = 60000000
} ;
struct V_40 V_44 , V_45 , V_46 ;
F_8 ( & V_44 ) ;
V_45 = F_15 ( V_21 . V_22 , V_41 ) ;
V_46 = F_16 ( V_44 , V_45 ) ;
if ( V_46 . V_42 >= 0 && V_46 . V_43 >= 0 ) {
* V_17 = V_47 |
V_48 ;
} else {
* V_17 = V_49 |
V_50 ;
}
return 0 ;
}
int F_17 ( struct V_15 * V_16 , T_2 V_4 )
{
return - V_51 ;
}
int F_18 ( struct V_15 * V_16 , T_3 V_17 )
{
return F_5 ( V_16 , V_21 . V_23 + V_17 ) ;
}
int F_19 ( struct V_15 * V_16 , T_3 * V_17 )
{
* V_17 = V_21 . V_23 ;
return 0 ;
}
int F_20 ( struct V_15 * V_16 , T_3 V_17 )
{
return 0 ;
}
int F_21 ( struct V_15 * V_16 , T_3 V_17 )
{
return 0 ;
}
int F_22 ( struct V_15 * V_16 )
{
V_21 . V_25 = F_23 () ;
V_21 . V_23 = V_52 ;
V_21 . V_24 = 0 ;
return ( NULL == V_21 . V_25 ) ? - V_53 : 0 ;
}
