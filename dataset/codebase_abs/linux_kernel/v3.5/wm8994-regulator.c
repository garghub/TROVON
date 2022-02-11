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
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_8 > V_10 )
return - V_7 ;
switch ( V_4 -> V_11 -> type ) {
case V_12 :
return ( V_8 * 100000 ) + 900000 ;
case V_13 :
return ( V_8 * 100000 ) + 1000000 ;
case V_14 :
switch ( V_8 ) {
case 0 :
return - V_7 ;
default:
return ( V_8 * 100000 ) + 950000 ;
}
break;
default:
return - V_7 ;
}
}
static T_1 int F_9 ( struct V_15 * V_16 )
{
struct V_11 * V_11 = F_10 ( V_16 -> V_17 . V_18 ) ;
struct V_19 * V_20 = V_11 -> V_17 -> V_21 ;
int V_22 = V_16 -> V_22 % F_11 ( V_20 -> V_4 ) ;
struct V_23 V_24 = { } ;
struct V_3 * V_4 ;
int V_25 ;
F_12 ( & V_16 -> V_17 , L_1 , V_22 + 1 ) ;
V_4 = F_13 ( & V_16 -> V_17 , sizeof( struct V_3 ) , V_26 ) ;
if ( V_4 == NULL ) {
F_14 ( & V_16 -> V_17 , L_2 ) ;
return - V_27 ;
}
V_4 -> V_11 = V_11 ;
if ( V_20 -> V_4 [ V_22 ] . V_5 && F_15 ( V_20 -> V_4 [ V_22 ] . V_5 ) ) {
V_4 -> V_5 = V_20 -> V_4 [ V_22 ] . V_5 ;
V_25 = F_16 ( V_4 -> V_5 , 0 , L_3 ) ;
if ( V_25 < 0 ) {
F_14 ( & V_16 -> V_17 , L_4 ,
V_25 ) ;
goto V_28;
}
} else
V_4 -> V_6 = true ;
V_24 . V_17 = V_11 -> V_17 ;
V_24 . V_29 = V_4 ;
V_24 . V_30 = V_11 -> V_30 ;
if ( V_20 )
V_24 . V_31 = V_20 -> V_4 [ V_22 ] . V_31 ;
V_4 -> V_32 = F_17 ( & V_33 [ V_22 ] , & V_24 ) ;
if ( F_18 ( V_4 -> V_32 ) ) {
V_25 = F_19 ( V_4 -> V_32 ) ;
F_14 ( V_11 -> V_17 , L_5 ,
V_22 + 1 , V_25 ) ;
goto V_34;
}
F_20 ( V_16 , V_4 ) ;
return 0 ;
V_34:
if ( F_15 ( V_4 -> V_5 ) )
F_21 ( V_4 -> V_5 ) ;
V_28:
return V_25 ;
}
static T_2 int F_22 ( struct V_15 * V_16 )
{
struct V_3 * V_4 = F_23 ( V_16 ) ;
F_20 ( V_16 , NULL ) ;
F_24 ( V_4 -> V_32 ) ;
if ( F_15 ( V_4 -> V_5 ) )
F_21 ( V_4 -> V_5 ) ;
return 0 ;
}
static int T_3 F_25 ( void )
{
int V_25 ;
V_25 = F_26 ( & V_35 ) ;
if ( V_25 != 0 )
F_27 ( L_6 , V_25 ) ;
return V_25 ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_35 ) ;
}
