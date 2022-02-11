T_1 (F_1)( int V_1 , T_2 V_2 , T_2 V_3 , int V_4 )
{
struct V_5 * V_5 = F_2 ( V_1 ) ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_2 V_10 ;
T_3 V_11 ;
T_3 V_12 ;
unsigned long V_13 ;
int V_14 = 0 ;
if ( ! V_5 )
return - V_15 ;
if ( F_3 ( V_5 -> V_16 . V_17 -> V_18 -> V_19 ) ) {
V_14 = - V_20 ;
goto V_21;
}
V_7 = V_5 -> V_22 ;
if ( ! V_7 || V_3 < 0 ) {
V_14 = - V_23 ;
goto V_21;
}
if ( V_7 -> V_24 -> V_25 ) {
switch ( V_4 ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
break;
default:
V_14 = - V_23 ;
}
goto V_21;
}
V_10 = V_2 + V_3 ;
if ( ! V_3 || V_10 < V_3 )
V_10 = - 1 ;
else
V_10 -- ;
V_9 = V_7 -> V_8 ;
switch ( V_4 ) {
case V_26 :
V_5 -> V_32 . V_33 = V_9 -> V_33 ;
F_4 ( & V_5 -> V_34 ) ;
V_5 -> V_35 &= ~ V_36 ;
F_5 ( & V_5 -> V_34 ) ;
break;
case V_27 :
F_4 ( & V_5 -> V_34 ) ;
V_5 -> V_35 |= V_36 ;
F_5 ( & V_5 -> V_34 ) ;
break;
case V_28 :
V_5 -> V_32 . V_33 = V_9 -> V_33 * 2 ;
F_4 ( & V_5 -> V_34 ) ;
V_5 -> V_35 &= ~ V_36 ;
F_5 ( & V_5 -> V_34 ) ;
break;
case V_29 :
V_11 = V_2 >> V_37 ;
V_12 = V_10 >> V_37 ;
V_13 = V_12 - V_11 + 1 ;
if ( ! V_13 )
V_13 = ~ 0UL ;
F_6 ( V_7 , V_5 , V_11 ,
V_13 ) ;
break;
case V_30 :
break;
case V_31 :
if ( ! F_7 ( V_7 -> V_8 ) )
F_8 ( V_7 , V_2 , V_10 ,
V_38 ) ;
V_11 = ( V_2 + ( V_39 - 1 ) ) >> V_37 ;
V_12 = ( V_10 >> V_37 ) ;
if ( V_12 >= V_11 )
F_9 ( V_7 , V_11 ,
V_12 ) ;
break;
default:
V_14 = - V_23 ;
}
V_21:
F_10 ( V_5 ) ;
return V_14 ;
}
T_4 long F_11 ( long V_1 , T_2 V_2 , T_2 V_3 , long V_4 )
{
return F_12 ( ( int ) V_1 , V_2 , V_3 , ( int ) V_4 ) ;
}
T_1 (F_13)( int V_1 , T_2 V_2 , T_5 V_3 , int V_4 )
{
return F_14 ( V_1 , V_2 , V_3 , V_4 ) ;
}
T_4 long F_15 ( long V_1 , T_2 V_2 , long V_3 , long V_4 )
{
return F_16 ( ( int ) V_1 , V_2 , ( T_5 ) V_3 , ( int ) V_4 ) ;
}
