int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( & V_1 -> V_5 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_3 ( V_1 -> V_6 , V_2 , V_3 ) ;
F_4 ( & V_1 -> V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
int F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 * V_7 )
{
int V_4 ;
V_4 = F_2 ( & V_1 -> V_5 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_6 ( V_1 -> V_6 , V_2 ) ;
F_4 ( & V_1 -> V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_7 = V_4 ;
return 0 ;
}
int F_7 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_8 , T_1 V_9 )
{
int V_4 ;
T_1 V_10 ;
V_4 = F_2 ( & V_1 -> V_5 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_6 ( V_1 -> V_6 , V_2 ) ;
if ( V_4 < 0 )
goto V_11;
V_10 = V_4 ;
V_10 = ( ~ V_8 & V_10 ) | ( V_8 & V_9 ) ;
V_4 = F_3 ( V_1 -> V_6 , V_2 , V_10 ) ;
V_11:
F_4 ( & V_1 -> V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static int T_2 F_8 ( struct V_1 * V_1 )
{
int V_4 ;
T_1 V_10 ;
V_4 = F_5 ( V_1 , V_12 , & V_10 ) ;
if ( V_4 )
return V_4 ;
switch ( V_10 >> V_13 ) {
case V_14 :
F_9 ( & V_1 -> V_6 -> V_15 ,
L_1 ) ;
break;
case V_16 :
F_9 ( & V_1 -> V_6 -> V_15 ,
L_2 ) ;
break;
case V_17 :
F_9 ( & V_1 -> V_6 -> V_15 ,
L_3 ) ;
break;
case V_18 :
F_9 ( & V_1 -> V_6 -> V_15 ,
L_4 ) ;
break;
default:
break;
}
return V_4 ;
}
static int T_2 F_10 ( struct V_19 * V_6 ,
const struct V_20 * V_21 )
{
struct V_1 * V_1 ;
struct V_22 * V_23 ;
int V_4 ;
int V_24 ;
V_1 = F_11 ( sizeof( * V_1 ) , V_25 ) ;
if ( ! V_1 )
return - V_26 ;
F_12 ( V_6 , V_1 ) ;
V_1 -> V_6 = V_6 ;
V_23 = V_6 -> V_15 . V_27 ;
V_1 -> V_23 = V_23 ;
F_13 ( & V_1 -> V_5 ) ;
V_4 = F_8 ( V_1 ) ;
if ( V_4 ) {
F_14 ( & V_6 -> V_15 , L_5 ) ;
goto V_11;
}
switch ( V_23 -> V_28 ) {
case V_29 :
F_9 ( & V_6 -> V_15 ,
L_6 ) ;
break;
case V_30 :
V_31 [ 0 ] . V_32 = L_7 ;
F_15 ( & V_6 -> V_15 ,
L_8 ) ;
break;
case V_33 :
V_31 [ 0 ] . V_32 = L_9 ;
F_15 ( & V_6 -> V_15 ,
L_10 ) ;
break;
case V_34 :
V_31 [ 0 ] . V_32 = L_11 ;
break;
default:
break;
}
for ( V_24 = 0 ; V_24 < F_16 ( V_31 ) ; V_24 ++ ) {
V_31 [ V_24 ] . V_27 = V_1 ;
V_31 [ V_24 ] . V_35 = sizeof( * V_1 ) ;
}
V_4 = F_17 ( & V_6 -> V_15 , 0 , V_31 ,
F_16 ( V_31 ) , NULL , 0 ) ;
if ( V_4 )
goto V_11;
return 0 ;
V_11:
F_18 ( V_1 ) ;
return V_4 ;
}
static int T_3 F_19 ( struct V_19 * V_6 )
{
struct V_1 * V_1 = F_20 ( V_6 ) ;
F_21 ( & V_6 -> V_15 ) ;
F_7 ( V_1 , V_12 ,
V_36 ,
V_29 << V_13 ) ;
F_18 ( V_1 ) ;
return 0 ;
}
static int T_4 F_22 ( void )
{
return F_23 ( & V_37 ) ;
}
static void T_5 F_24 ( void )
{
F_25 ( & V_37 ) ;
}
