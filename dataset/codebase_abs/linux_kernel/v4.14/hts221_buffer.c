static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
V_7 = F_4 ( V_6 , V_8 ,
V_9 , V_3 ) ;
return V_7 < 0 ? V_7 : 0 ;
}
static T_1 F_5 ( int V_10 , void * V_11 )
{
struct V_5 * V_6 = V_11 ;
T_2 V_12 ;
int V_7 ;
V_7 = V_6 -> V_13 -> V_14 ( V_6 -> V_15 , V_16 , sizeof( V_12 ) ,
& V_12 ) ;
if ( V_7 < 0 )
return V_17 ;
if ( ! ( V_12 & V_18 ) )
return V_19 ;
F_6 ( V_6 -> V_2 ) ;
return V_17 ;
}
int F_7 ( struct V_5 * V_6 )
{
struct V_4 * V_4 = F_8 ( V_6 ) ;
bool V_20 = false , V_21 = false ;
struct V_22 * V_23 = V_6 -> V_15 -> V_24 ;
struct V_25 * V_26 ;
unsigned long V_27 ;
int V_7 ;
V_27 = F_9 ( F_10 ( V_6 -> V_10 ) ) ;
switch ( V_27 ) {
case V_28 :
case V_29 :
break;
case V_30 :
case V_31 :
V_20 = true ;
break;
default:
F_11 ( V_6 -> V_15 ,
L_1 ,
V_27 ) ;
V_27 = V_29 ;
break;
}
V_7 = F_4 ( V_6 , V_32 ,
V_33 , V_20 ) ;
if ( V_7 < 0 )
return V_7 ;
V_26 = (struct V_25 * ) V_6 -> V_15 -> V_34 ;
if ( ( V_23 && F_12 ( V_23 , L_2 ) ) ||
( V_26 && V_26 -> V_21 ) ) {
V_27 |= V_35 ;
V_21 = true ;
}
V_7 = F_4 ( V_6 , V_36 ,
V_37 ,
V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_6 -> V_15 , V_6 -> V_10 , NULL ,
F_5 ,
V_27 | V_38 ,
V_6 -> V_39 , V_6 ) ;
if ( V_7 ) {
F_14 ( V_6 -> V_15 , L_3 ,
V_6 -> V_10 ) ;
return V_7 ;
}
V_6 -> V_2 = F_15 ( V_6 -> V_15 , L_4 ,
V_4 -> V_39 ) ;
if ( ! V_6 -> V_2 )
return - V_40 ;
F_16 ( V_6 -> V_2 , V_4 ) ;
V_6 -> V_2 -> V_41 = & V_42 ;
V_6 -> V_2 -> V_15 . V_43 = V_6 -> V_15 ;
V_4 -> V_2 = F_17 ( V_6 -> V_2 ) ;
return F_18 ( V_6 -> V_15 , V_6 -> V_2 ) ;
}
static int F_19 ( struct V_4 * V_4 )
{
return F_20 ( F_3 ( V_4 ) , true ) ;
}
static int F_21 ( struct V_4 * V_4 )
{
return F_20 ( F_3 ( V_4 ) , false ) ;
}
static T_1 F_22 ( int V_10 , void * V_44 )
{
T_2 V_45 [ F_23 ( 2 * V_46 , sizeof( V_47 ) ) + sizeof( V_47 ) ] ;
struct V_48 * V_49 = V_44 ;
struct V_4 * V_4 = V_49 -> V_50 ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_51 const * V_52 ;
int V_7 ;
V_52 = & V_4 -> V_53 [ V_54 ] ;
V_7 = V_6 -> V_13 -> V_14 ( V_6 -> V_15 , V_52 -> V_55 , V_46 ,
V_45 ) ;
if ( V_7 < 0 )
goto V_56;
V_52 = & V_4 -> V_53 [ V_57 ] ;
V_7 = V_6 -> V_13 -> V_14 ( V_6 -> V_15 , V_52 -> V_55 , V_46 ,
V_45 + V_46 ) ;
if ( V_7 < 0 )
goto V_56;
F_24 ( V_4 , V_45 ,
F_25 ( V_4 ) ) ;
V_56:
F_26 ( V_6 -> V_2 ) ;
return V_17 ;
}
int F_27 ( struct V_5 * V_6 )
{
return F_28 ( V_6 -> V_15 , F_8 ( V_6 ) ,
NULL , F_22 ,
& V_58 ) ;
}
