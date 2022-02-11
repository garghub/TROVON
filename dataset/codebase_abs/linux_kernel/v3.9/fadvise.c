T_1 (F_1)( int V_1 , T_2 V_2 , T_2 V_3 , int V_4 )
{
struct V_1 V_5 = F_2 ( V_1 ) ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_2 V_10 ;
T_3 V_11 ;
T_3 V_12 ;
unsigned long V_13 ;
int V_14 = 0 ;
if ( ! V_5 . V_15 )
return - V_16 ;
if ( F_3 ( F_4 ( V_5 . V_15 ) -> V_17 ) ) {
V_14 = - V_18 ;
goto V_19;
}
V_7 = V_5 . V_15 -> V_20 ;
if ( ! V_7 || V_3 < 0 ) {
V_14 = - V_21 ;
goto V_19;
}
if ( V_7 -> V_22 -> V_23 ) {
switch ( V_4 ) {
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
break;
default:
V_14 = - V_21 ;
}
goto V_19;
}
V_10 = V_2 + V_3 ;
if ( ! V_3 || V_10 < V_3 )
V_10 = - 1 ;
else
V_10 -- ;
V_9 = V_7 -> V_8 ;
switch ( V_4 ) {
case V_24 :
V_5 . V_15 -> V_30 . V_31 = V_9 -> V_31 ;
F_5 ( & V_5 . V_15 -> V_32 ) ;
V_5 . V_15 -> V_33 &= ~ V_34 ;
F_6 ( & V_5 . V_15 -> V_32 ) ;
break;
case V_25 :
F_5 ( & V_5 . V_15 -> V_32 ) ;
V_5 . V_15 -> V_33 |= V_34 ;
F_6 ( & V_5 . V_15 -> V_32 ) ;
break;
case V_26 :
V_5 . V_15 -> V_30 . V_31 = V_9 -> V_31 * 2 ;
F_5 ( & V_5 . V_15 -> V_32 ) ;
V_5 . V_15 -> V_33 &= ~ V_34 ;
F_6 ( & V_5 . V_15 -> V_32 ) ;
break;
case V_27 :
V_11 = V_2 >> V_35 ;
V_12 = V_10 >> V_35 ;
V_13 = V_12 - V_11 + 1 ;
if ( ! V_13 )
V_13 = ~ 0UL ;
F_7 ( V_7 , V_5 . V_15 , V_11 ,
V_13 ) ;
break;
case V_28 :
break;
case V_29 :
if ( ! F_8 ( V_7 -> V_8 ) )
F_9 ( V_7 , V_2 , V_10 ,
V_36 ) ;
V_11 = ( V_2 + ( V_37 - 1 ) ) >> V_35 ;
V_12 = ( V_10 >> V_35 ) ;
if ( V_12 >= V_11 ) {
unsigned long V_38 = F_10 ( V_7 ,
V_11 , V_12 ) ;
if ( V_38 < ( V_12 - V_11 + 1 ) ) {
F_11 () ;
F_10 ( V_7 , V_11 ,
V_12 ) ;
}
}
break;
default:
V_14 = - V_21 ;
}
V_19:
F_12 ( V_5 ) ;
return V_14 ;
}
T_4 long F_13 ( long V_1 , T_2 V_2 , T_2 V_3 , long V_4 )
{
return F_14 ( ( int ) V_1 , V_2 , V_3 , ( int ) V_4 ) ;
}
T_1 (F_15)( int V_1 , T_2 V_2 , T_5 V_3 , int V_4 )
{
return F_16 ( V_1 , V_2 , V_3 , V_4 ) ;
}
T_4 long F_17 ( long V_1 , T_2 V_2 , long V_3 , long V_4 )
{
return F_18 ( ( int ) V_1 , V_2 , ( T_5 ) V_3 , ( int ) V_4 ) ;
}
