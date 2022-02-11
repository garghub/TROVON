static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 V_6 [ 2 ] ;
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_3 ;
V_7 [ 1 ] = 0 ;
V_6 [ 0 ] . V_8 = V_9 ;
V_6 [ 0 ] . V_10 = 0 ;
V_6 [ 0 ] . V_11 = 1 ;
V_6 [ 0 ] . V_7 = & V_7 [ 0 ] ;
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
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_3 ;
V_7 [ 1 ] = V_4 ;
V_6 . V_8 = V_9 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = 2 ;
V_6 . V_7 = & V_7 [ 0 ] ;
if ( F_2 ( V_2 -> V_13 , & V_6 , 1 ) != 1 )
return - V_14 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 V_6 ;
T_1 V_7 [ 3 ] ;
V_7 [ 0 ] = V_3 ;
V_7 [ 1 ] = ( T_1 ) ( V_4 >> 8 ) ;
V_7 [ 2 ] = ( T_1 ) ( V_4 & 0xff ) ;
V_6 . V_8 = V_9 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = 3 ;
V_6 . V_7 = & V_7 [ 0 ] ;
if ( F_2 ( V_2 -> V_13 , & V_6 , 1 ) != 1 )
return - V_14 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_15 ;
V_15 = F_3 ( V_2 , V_16 , V_17 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_3 ( V_2 , V_18 ,
V_19 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_3 ( V_2 , V_20 , V_21 ) ;
return V_15 ;
}
int F_6 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_7 ( V_23 ) ;
int V_15 ;
T_1 V_24 ;
V_15 = V_25 . V_26 -> V_27 ( V_23 , 1 ) ;
if ( V_15 )
return V_15 ;
F_8 ( 1100 , 2200 ) ;
V_15 = F_1 ( V_2 , V_28 , & V_24 ) ;
if ( V_15 < 0 )
goto V_29;
if ( V_24 != V_30 ) {
V_15 = - V_31 ;
goto V_29;
}
V_15 = F_5 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_3 ( V_2 , V_32 ,
V_33 ) ;
return V_15 ;
V_29:
V_25 . V_26 -> V_27 ( V_23 , 0 ) ;
return V_15 ;
}
int F_9 ( struct V_22 * V_23 )
{
return V_25 . V_26 -> V_27 ( V_23 , 0 ) ;
}
int F_10 ( struct V_22 * V_23 , T_2 V_4 )
{
struct V_1 * V_2 = F_7 ( V_23 ) ;
T_2 V_34 = V_4 & V_35 ;
return F_4 ( V_2 , V_36 , V_34 ) ;
}
int F_11 ( struct V_22 * V_23 , T_3 V_37 )
{
int V_15 ;
V_37 = F_12 ( V_37 , 0 , V_38 ) ;
V_15 = F_10 ( V_23 , V_37 ) ;
if ( V_15 == 0 ) {
V_25 . V_39 = V_37 - V_25 . V_40 ;
V_25 . V_40 = V_37 ;
F_13 ( & ( V_25 . V_41 ) ) ;
}
return V_15 ;
}
int F_14 ( struct V_22 * V_23 , T_3 V_37 )
{
return F_11 ( V_23 , V_25 . V_40 + V_37 ) ;
}
int F_15 ( struct V_22 * V_23 , T_3 * V_37 )
{
T_4 V_42 = 0 ;
struct V_43 V_44 ;
const struct V_43 V_45 = {
0 ,
F_16 ( T_4 , abs ( V_25 . V_39 ) * V_46 ,
V_47 ) ,
} ;
F_17 ( & V_44 ) ;
V_44 = F_18 ( V_44 , ( V_25 . V_41 ) ) ;
if ( F_19 ( & V_44 , & V_45 ) <= 0 ) {
V_42 |= V_48 ;
V_42 |= V_49 ;
} else {
V_42 |= V_50 ;
V_42 |= V_51 ;
}
* V_37 = V_42 ;
return 0 ;
}
int F_20 ( struct V_22 * V_23 , T_3 * V_37 )
{
T_3 V_4 ;
F_15 ( V_23 , & V_4 ) ;
if ( V_4 & V_48 )
* V_37 = V_25 . V_40 - V_25 . V_39 ;
else
* V_37 = V_25 . V_40 ;
return 0 ;
}
int F_21 ( struct V_22 * V_23 , T_3 V_37 )
{
return 0 ;
}
int F_22 ( struct V_22 * V_23 , T_3 V_37 )
{
return 0 ;
}
int F_23 ( struct V_22 * V_23 )
{
V_25 . V_26 = F_24 () ;
return ( NULL == V_25 . V_26 ) ? - V_52 : 0 ;
}
