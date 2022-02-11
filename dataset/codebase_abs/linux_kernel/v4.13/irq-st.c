static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , bool V_5 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
switch ( V_3 ) {
case V_9 :
V_7 -> V_10 |= V_11 ;
break;
case V_12 :
V_7 -> V_10 |= V_13 ;
break;
case V_14 :
V_7 -> V_10 |= V_15 ;
break;
case V_16 :
V_7 -> V_10 |= V_17 ;
break;
case V_18 :
V_7 -> V_10 |= V_19 ;
break;
case V_20 :
V_7 -> V_10 |= V_21 ;
break;
case V_22 :
V_7 -> V_10 |= V_23 ;
break;
case V_24 :
V_7 -> V_10 |= V_25 ;
break;
case V_26 :
return 0 ;
default:
F_3 ( & V_2 -> V_8 , L_1 , V_3 ) ;
return - V_27 ;
}
V_7 -> V_10 |= V_5 ?
F_4 ( V_3 , V_4 ) :
F_5 ( V_3 , V_4 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_8 . V_30 ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
int V_31 , V_32 , V_33 ;
T_1 V_3 , V_34 ;
V_31 = F_7 ( V_29 , L_2 ) ;
if ( V_31 != V_35 ) {
F_3 ( & V_2 -> V_8 , L_3 ) ;
return - V_27 ;
}
V_31 = F_7 ( V_29 , L_4 ) ;
if ( V_31 != V_35 ) {
F_3 ( & V_2 -> V_8 , L_5 ) ;
return - V_27 ;
}
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
F_8 ( V_29 , L_2 , V_33 , & V_3 ) ;
V_32 = F_1 ( V_2 , V_3 , V_33 , true ) ;
if ( V_32 )
return V_32 ;
F_8 ( V_29 , L_4 , V_33 , & V_3 ) ;
V_32 = F_1 ( V_2 , V_3 , V_33 , false ) ;
if ( V_32 )
return V_32 ;
}
F_9 ( V_29 , L_6 , & V_34 ) ;
V_7 -> V_10 |= F_10 ( V_34 ) ;
return F_11 ( V_7 -> V_36 , V_7 -> V_37 ,
V_38 , V_7 -> V_10 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_8 . V_30 ;
const struct V_39 * V_40 ;
struct V_6 * V_7 ;
V_7 = F_13 ( & V_2 -> V_8 , sizeof( * V_7 ) , V_41 ) ;
if ( ! V_7 )
return - V_42 ;
V_40 = F_14 ( V_43 , & V_2 -> V_8 ) ;
if ( ! V_40 )
return - V_44 ;
V_7 -> V_37 = ( unsigned int ) V_40 -> V_45 ;
V_7 -> V_36 = F_15 ( V_29 , L_7 ) ;
if ( F_16 ( V_7 -> V_36 ) ) {
F_3 ( & V_2 -> V_8 , L_8 ) ;
return F_17 ( V_7 -> V_36 ) ;
}
F_18 ( & V_2 -> V_8 , V_7 ) ;
return F_6 ( V_2 ) ;
}
static int T_2 F_19 ( struct V_3 * V_8 )
{
struct V_6 * V_7 = F_2 ( V_8 ) ;
return F_11 ( V_7 -> V_36 , V_7 -> V_37 ,
V_38 , V_7 -> V_10 ) ;
}
static int T_3 F_20 ( void )
{
return F_21 ( & V_46 ) ;
}
