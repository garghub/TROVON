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
int F_10 ( enum V_1 V_2 )
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
static bool F_12 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
if ( V_20 && V_20 -> V_23 )
return true ;
if ( F_13 ( V_22 , L_3 ) )
return true ;
return false ;
}
static bool F_14 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
int V_24 ;
if ( V_20 && V_20 -> V_24 )
return true ;
if ( ! F_15 ( V_22 , L_4 , & V_24 ) && V_24 )
return true ;
return false ;
}
static int F_16 ( struct V_25 * V_26 )
{
struct V_4 * V_5 ;
struct V_19 * V_20 = V_26 -> V_13 . V_27 ;
struct V_21 * V_22 = V_26 -> V_13 . V_28 ;
struct V_29 * V_30 = NULL ;
int V_31 , V_32 = 0 ;
T_1 V_7 ;
if ( ! V_20 && ! V_22 ) {
F_7 ( & V_26 -> V_13 , L_5 ) ;
return - V_14 ;
}
V_5 = F_17 ( & V_26 -> V_13 , sizeof( struct V_4 ) ,
V_33 ) ;
if ( ! V_5 )
return - V_34 ;
F_18 ( & V_5 -> V_15 ) ;
V_5 -> V_18 = F_19 () ;
switch ( V_5 -> V_18 ) {
case 19200000 :
V_7 = V_35 ;
break;
case 26000000 :
V_7 = V_36 ;
break;
case 38400000 :
V_7 = V_37 ;
break;
default:
F_7 ( & V_26 -> V_13 , L_6 ) ;
return - V_14 ;
}
F_4 ( V_8 , V_7 , V_38 ) ;
V_5 -> V_9 [ V_39 ] . V_10 = V_40 ;
V_5 -> V_9 [ V_39 ] . V_11 = V_41 ;
V_5 -> V_9 [ V_42 ] . V_10 = V_38 ;
V_5 -> V_9 [ V_42 ] . V_11 = V_43 ;
if ( F_12 ( V_20 , V_22 ) ) {
V_30 = & V_5 -> V_44 [ V_32 ] ;
V_30 -> V_45 = L_7 ;
if ( V_20 ) {
V_30 -> V_27 = V_20 -> V_23 ;
V_30 -> V_46 = sizeof( * V_20 -> V_23 ) ;
}
V_32 ++ ;
}
if ( F_14 ( V_20 , V_22 ) ) {
V_30 = & V_5 -> V_44 [ V_32 ] ;
V_30 -> V_45 = L_8 ;
if ( V_20 ) {
V_30 -> V_27 = V_20 -> V_24 ;
V_30 -> V_46 = sizeof( * V_20 -> V_24 ) ;
}
V_32 ++ ;
}
F_20 ( V_26 , V_5 ) ;
V_6 = V_26 ;
if ( V_32 )
V_31 = F_21 ( & V_26 -> V_13 , V_26 -> V_2 , V_5 -> V_44 ,
V_32 , NULL , 0 , NULL ) ;
else {
F_7 ( & V_26 -> V_13 , L_9 ) ;
V_31 = - V_47 ;
}
if ( V_31 )
V_6 = NULL ;
return V_31 ;
}
static int F_22 ( struct V_25 * V_26 )
{
F_23 ( & V_26 -> V_13 ) ;
V_6 = NULL ;
return 0 ;
}
