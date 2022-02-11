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
int F_5 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
int V_17 ;
T_1 V_18 ;
V_17 = V_19 . V_20 -> V_21 ( V_16 , 1 ) ;
if ( V_17 )
return V_17 ;
F_7 ( 1 ) ;
F_3 ( V_2 , V_22 , V_23 ) ;
F_8 ( V_24 , V_24 * 10 ) ;
V_17 = F_3 ( V_2 , V_22 , V_23 ) ;
if ( V_17 < 0 )
goto V_25;
V_17 = F_1 ( V_2 , V_22 , & V_18 ) ;
if ( V_17 < 0 )
goto V_25;
if ( V_18 != V_26 ) {
V_17 = - V_27 ;
goto V_25;
}
V_19 . V_28 = V_29 ;
V_19 . V_30 = true ;
return 0 ;
V_25:
V_19 . V_20 -> V_21 ( V_16 , 0 ) ;
return V_17 ;
}
int F_9 ( struct V_15 * V_16 )
{
return V_19 . V_20 -> V_21 ( V_16 , 0 ) ;
}
int F_10 ( struct V_15 * V_16 , T_2 V_4 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
T_2 V_31 = V_4 & V_32 ;
if ( ! V_19 . V_30 )
return - V_33 ;
return F_4 ( V_2 , V_34 , V_31 ) ;
}
int F_11 ( struct V_15 * V_16 , T_3 V_18 )
{
int V_17 ;
V_18 = F_12 ( V_18 , 0 , V_29 ) ;
V_17 = F_10 ( V_16 , V_18 ) ;
if ( V_17 == 0 ) {
V_19 . V_35 = V_18 - V_19 . V_28 ;
V_19 . V_28 = V_18 ;
F_13 ( & ( V_19 . V_36 ) ) ;
}
return V_17 ;
}
int F_14 ( struct V_15 * V_16 , T_3 V_18 )
{
return F_11 ( V_16 , V_19 . V_28 + V_18 ) ;
}
int F_15 ( struct V_15 * V_16 , T_3 * V_18 )
{
T_4 V_37 = 0 ;
struct V_38 V_39 ;
const struct V_38 V_40 = {
0 ,
F_16 ( T_4 , abs ( V_19 . V_35 ) * V_41 ,
V_42 ) ,
} ;
F_17 ( & V_39 ) ;
V_39 = F_18 ( V_39 , ( V_19 . V_36 ) ) ;
if ( F_19 ( & V_39 , & V_40 ) <= 0 ) {
V_37 |= V_43 ;
V_37 |= V_44 ;
} else {
V_37 |= V_45 ;
V_37 |= V_46 ;
}
* V_18 = V_37 ;
return 0 ;
}
int F_20 ( struct V_15 * V_16 , T_3 * V_18 )
{
T_3 V_4 ;
F_15 ( V_16 , & V_4 ) ;
if ( V_4 & V_43 )
* V_18 = V_19 . V_28 - V_19 . V_35 ;
else
* V_18 = V_19 . V_28 ;
return 0 ;
}
int F_21 ( struct V_15 * V_16 , T_3 V_18 )
{
return 0 ;
}
int F_22 ( struct V_15 * V_16 , T_3 V_18 )
{
return 0 ;
}
int F_23 ( struct V_15 * V_16 )
{
V_19 . V_20 = F_24 () ;
return ( NULL == V_19 . V_20 ) ? - V_33 : 0 ;
}
