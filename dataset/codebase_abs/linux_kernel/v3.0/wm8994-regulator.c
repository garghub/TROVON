static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_5 )
return 0 ;
F_3 ( V_4 -> V_5 , 1 ) ;
V_4 -> V_6 = true ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_5 )
return - V_7 ;
F_3 ( V_4 -> V_5 , 0 ) ;
V_4 -> V_6 = false ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_6 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return 3000 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
if ( V_8 > V_9 )
return - V_7 ;
return ( V_8 * 100000 ) + 2400000 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
V_10 = F_9 ( V_4 -> V_11 , V_12 ) ;
if ( V_10 < 0 )
return V_10 ;
return ( V_10 & V_13 ) >> V_14 ;
}
static int F_10 ( struct V_1 * V_2 ,
int V_15 , int V_16 , unsigned * V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_8 , V_18 ;
V_8 = ( V_15 - 2400000 ) / 100000 ;
V_18 = F_7 ( V_2 , V_8 ) ;
if ( V_18 < 0 || V_18 > V_16 )
return - V_7 ;
* V_17 = V_8 ;
V_8 <<= V_14 ;
return F_11 ( V_4 -> V_11 , V_12 ,
V_13 , V_8 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_8 > V_19 )
return - V_7 ;
switch ( V_4 -> V_11 -> type ) {
case V_20 :
return ( V_8 * 100000 ) + 900000 ;
case V_21 :
return ( V_8 * 100000 ) + 1000000 ;
default:
return - V_7 ;
}
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
V_10 = F_9 ( V_4 -> V_11 , V_22 ) ;
if ( V_10 < 0 )
return V_10 ;
return ( V_10 & V_23 ) >> V_24 ;
}
static int F_14 ( struct V_1 * V_2 ,
int V_15 , int V_16 , unsigned * V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_8 , V_18 ;
switch ( V_4 -> V_11 -> type ) {
case V_20 :
V_8 = ( V_15 - 900000 ) / 100000 ;
break;
case V_21 :
V_8 = ( V_15 - 1000000 ) / 100000 ;
break;
default:
return - V_7 ;
}
V_18 = F_12 ( V_2 , V_8 ) ;
if ( V_18 < 0 || V_18 > V_16 )
return - V_7 ;
* V_17 = V_8 ;
V_8 <<= V_24 ;
return F_11 ( V_4 -> V_11 , V_22 ,
V_23 , V_8 ) ;
}
static T_1 int F_15 ( struct V_25 * V_26 )
{
struct V_11 * V_11 = F_16 ( V_26 -> V_27 . V_28 ) ;
struct V_29 * V_30 = V_11 -> V_27 -> V_31 ;
int V_32 = V_26 -> V_32 % F_17 ( V_30 -> V_4 ) ;
struct V_3 * V_4 ;
int V_33 ;
F_18 ( & V_26 -> V_27 , L_1 , V_32 + 1 ) ;
if ( ! V_30 )
return - V_34 ;
V_4 = F_19 ( sizeof( struct V_3 ) , V_35 ) ;
if ( V_4 == NULL ) {
F_20 ( & V_26 -> V_27 , L_2 ) ;
return - V_36 ;
}
V_4 -> V_11 = V_11 ;
if ( V_30 -> V_4 [ V_32 ] . V_5 && F_21 ( V_30 -> V_4 [ V_32 ] . V_5 ) ) {
V_4 -> V_5 = V_30 -> V_4 [ V_32 ] . V_5 ;
V_33 = F_22 ( V_4 -> V_5 , L_3 ) ;
if ( V_33 < 0 ) {
F_20 ( & V_26 -> V_27 , L_4 ,
V_33 ) ;
goto V_37;
}
V_33 = F_23 ( V_4 -> V_5 , V_4 -> V_6 ) ;
if ( V_33 < 0 ) {
F_20 ( & V_26 -> V_27 , L_5 ,
V_33 ) ;
goto V_38;
}
} else
V_4 -> V_6 = true ;
V_4 -> V_39 = F_24 ( & V_40 [ V_32 ] , & V_26 -> V_27 ,
V_30 -> V_4 [ V_32 ] . V_41 , V_4 ) ;
if ( F_25 ( V_4 -> V_39 ) ) {
V_33 = F_26 ( V_4 -> V_39 ) ;
F_20 ( V_11 -> V_27 , L_6 ,
V_32 + 1 , V_33 ) ;
goto V_38;
}
F_27 ( V_26 , V_4 ) ;
return 0 ;
V_38:
if ( F_21 ( V_4 -> V_5 ) )
F_28 ( V_4 -> V_5 ) ;
V_37:
F_29 ( V_4 ) ;
return V_33 ;
}
static T_2 int F_30 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_31 ( V_26 ) ;
F_27 ( V_26 , NULL ) ;
F_32 ( V_4 -> V_39 ) ;
if ( F_21 ( V_4 -> V_5 ) )
F_28 ( V_4 -> V_5 ) ;
F_29 ( V_4 ) ;
return 0 ;
}
static int T_3 F_33 ( void )
{
int V_33 ;
V_33 = F_34 ( & V_42 ) ;
if ( V_33 != 0 )
F_35 ( L_7 , V_33 ) ;
return V_33 ;
}
static void T_4 F_36 ( void )
{
F_37 ( & V_42 ) ;
}
