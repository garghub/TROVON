static int F_1 ( struct V_1 * V_1 )
{
int V_2 ;
unsigned int V_3 ;
V_2 = F_2 ( V_1 -> V_4 , V_5 , & V_3 ) ;
if ( V_2 )
return V_2 ;
switch ( V_3 >> V_6 ) {
case V_7 :
F_3 ( & V_1 -> V_8 -> V_9 ,
L_1 ) ;
break;
case V_10 :
F_3 ( & V_1 -> V_8 -> V_9 ,
L_2 ) ;
break;
case V_11 :
F_3 ( & V_1 -> V_8 -> V_9 ,
L_3 ) ;
break;
case V_12 :
F_3 ( & V_1 -> V_8 -> V_9 ,
L_4 ) ;
break;
default:
break;
}
return V_2 ;
}
static int F_4 ( struct V_1 * V_1 ,
struct V_13 * V_14 )
{
V_14 -> V_15 = V_1 ;
V_14 -> V_16 = sizeof( * V_1 ) ;
return F_5 ( & V_1 -> V_8 -> V_9 ,
V_17 , V_14 , 1 , NULL , 0 , NULL ) ;
}
static int F_6 ( struct V_18 * V_8 ,
const struct V_19 * V_20 )
{
struct V_1 * V_1 ;
struct V_21 * V_22 ;
int V_2 ;
V_22 = F_7 ( & V_8 -> V_9 ) ;
if ( ! V_22 ) {
F_8 ( & V_8 -> V_9 , L_5 ) ;
return - V_23 ;
}
V_1 = F_9 ( & V_8 -> V_9 , sizeof( * V_1 ) , V_24 ) ;
if ( ! V_1 )
return - V_25 ;
V_1 -> V_4 = F_10 ( V_8 , & V_26 ) ;
if ( F_11 ( V_1 -> V_4 ) )
return F_12 ( V_1 -> V_4 ) ;
F_13 ( V_8 , V_1 ) ;
V_1 -> V_8 = V_8 ;
V_1 -> V_22 = V_22 ;
V_2 = F_1 ( V_1 ) ;
if ( V_2 ) {
F_8 ( & V_8 -> V_9 , L_6 ) ;
return V_2 ;
}
V_2 = F_4 ( V_1 , & V_27 ) ;
if ( V_2 )
return V_2 ;
switch ( V_22 -> V_28 ) {
case V_29 :
F_3 ( & V_8 -> V_9 ,
L_7 ) ;
break;
case V_30 :
V_2 = F_4 ( V_1 , & V_31 ) ;
break;
case V_32 :
V_2 = F_4 ( V_1 , & V_33 ) ;
break;
case V_34 :
V_2 = F_4 ( V_1 , & V_35 ) ;
break;
default:
F_14 ( & V_8 -> V_9 , L_8 , V_22 -> V_28 ) ;
break;
}
if ( V_2 )
F_15 ( & V_8 -> V_9 ) ;
return V_2 ;
}
static int F_16 ( struct V_18 * V_8 )
{
struct V_1 * V_1 = F_17 ( V_8 ) ;
F_15 ( & V_8 -> V_9 ) ;
F_18 ( V_1 -> V_4 , V_5 ,
V_36 ,
V_29 << V_6 ) ;
return 0 ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_37 ) ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_37 ) ;
}
