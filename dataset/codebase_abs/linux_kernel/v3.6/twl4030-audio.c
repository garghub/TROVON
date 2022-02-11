static int F_1 ( enum V_1 V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
T_1 V_7 ;
F_3 ( V_8 , & V_7 ,
V_5 -> V_9 [ V_2 ] . V_10 ) ;
if ( V_3 )
V_7 |= V_5 -> V_9 [ V_2 ] . V_11 ;
else
V_7 &= ~ V_5 -> V_9 [ V_2 ] . V_11 ;
F_4 ( V_8 ,
V_7 , V_5 -> V_9 [ V_2 ] . V_10 ) ;
return V_7 ;
}
static inline int F_5 ( enum V_1 V_2 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
T_1 V_7 ;
F_3 ( V_8 , & V_7 ,
V_5 -> V_9 [ V_2 ] . V_10 ) ;
return V_7 ;
}
int F_6 ( enum V_1 V_2 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
int V_7 ;
if ( V_2 >= V_12 ) {
F_7 ( & V_6 -> V_13 ,
L_1 , V_2 ) ;
return - V_14 ;
}
F_8 ( & V_5 -> V_15 ) ;
if ( ! V_5 -> V_9 [ V_2 ] . V_16 )
V_7 = F_1 ( V_2 , 1 ) ;
else
V_7 = F_5 ( V_2 ) ;
V_5 -> V_9 [ V_2 ] . V_16 ++ ;
F_9 ( & V_5 -> V_15 ) ;
return V_7 ;
}
int F_10 ( unsigned V_2 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
int V_7 ;
if ( V_2 >= V_12 ) {
F_7 ( & V_6 -> V_13 ,
L_1 , V_2 ) ;
return - V_14 ;
}
F_8 ( & V_5 -> V_15 ) ;
if ( ! V_5 -> V_9 [ V_2 ] . V_16 ) {
F_7 ( & V_6 -> V_13 ,
L_2 , V_2 ) ;
F_9 ( & V_5 -> V_15 ) ;
return - V_17 ;
}
V_5 -> V_9 [ V_2 ] . V_16 -- ;
if ( ! V_5 -> V_9 [ V_2 ] . V_16 )
V_7 = F_1 ( V_2 , 0 ) ;
else
V_7 = F_5 ( V_2 ) ;
F_9 ( & V_5 -> V_15 ) ;
return V_7 ;
}
unsigned int F_11 ( void )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
return V_5 -> V_18 ;
}
static int T_2 F_12 ( struct V_19 * V_20 )
{
struct V_4 * V_5 ;
struct V_21 * V_22 = V_20 -> V_13 . V_23 ;
struct V_24 * V_25 = NULL ;
int V_26 , V_27 = 0 ;
T_1 V_7 ;
if ( ! V_22 ) {
F_7 ( & V_20 -> V_13 , L_3 ) ;
return - V_14 ;
}
V_7 = 0 ;
switch ( V_22 -> V_18 ) {
case 19200000 :
V_7 |= V_28 ;
break;
case 26000000 :
V_7 |= V_29 ;
break;
case 38400000 :
V_7 |= V_30 ;
break;
default:
F_7 ( & V_20 -> V_13 , L_4 ) ;
return - V_14 ;
}
F_4 ( V_8 ,
V_7 , V_31 ) ;
V_5 = F_13 ( sizeof( struct V_4 ) , V_32 ) ;
if ( ! V_5 )
return - V_33 ;
F_14 ( V_20 , V_5 ) ;
V_6 = V_20 ;
F_15 ( & V_5 -> V_15 ) ;
V_5 -> V_18 = V_22 -> V_18 ;
V_5 -> V_9 [ V_34 ] . V_10 = V_35 ;
V_5 -> V_9 [ V_34 ] . V_11 = V_36 ;
V_5 -> V_9 [ V_37 ] . V_10 = V_31 ;
V_5 -> V_9 [ V_37 ] . V_11 = V_38 ;
if ( V_22 -> V_39 ) {
V_25 = & V_5 -> V_40 [ V_27 ] ;
V_25 -> V_41 = L_5 ;
V_25 -> V_23 = V_22 -> V_39 ;
V_25 -> V_42 = sizeof( * V_22 -> V_39 ) ;
V_27 ++ ;
}
if ( V_22 -> V_43 ) {
V_25 = & V_5 -> V_40 [ V_27 ] ;
V_25 -> V_41 = L_6 ;
V_25 -> V_23 = V_22 -> V_43 ;
V_25 -> V_42 = sizeof( * V_22 -> V_43 ) ;
V_27 ++ ;
}
if ( V_27 )
V_26 = F_16 ( & V_20 -> V_13 , V_20 -> V_2 , V_5 -> V_40 ,
V_27 , NULL , 0 , NULL ) ;
else {
F_7 ( & V_20 -> V_13 , L_7 ) ;
V_26 = - V_44 ;
}
if ( ! V_26 )
return 0 ;
F_14 ( V_20 , NULL ) ;
F_17 ( V_5 ) ;
V_6 = NULL ;
return V_26 ;
}
static int T_3 F_18 ( struct V_19 * V_20 )
{
struct V_4 * V_5 = F_2 ( V_20 ) ;
F_19 ( & V_20 -> V_13 ) ;
F_14 ( V_20 , NULL ) ;
F_17 ( V_5 ) ;
V_6 = NULL ;
return 0 ;
}
