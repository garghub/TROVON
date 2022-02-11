void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
long F_5 ( struct V_3 * V_4 ,
unsigned int V_5 , unsigned long V_6 )
{
struct V_7 * V_8 ;
struct V_9 V_10 ;
unsigned long V_11 ;
long V_12 = - V_13 ;
switch ( V_5 ) {
case V_14 :
if ( V_6 == V_15 )
V_12 = F_6 () ? 1 : 0 ;
else
V_12 = 0 ;
break;
case V_16 :
V_8 = F_7 ( V_4 ) ;
if ( ! V_8 )
return - V_17 ;
V_11 = F_8 ( struct V_9 , V_10 ) ;
if ( F_9 ( & V_10 , ( void V_18 * ) V_6 , V_11 ) )
return - V_19 ;
if ( V_10 . V_20 < V_11 || V_10 . V_21 )
return - V_13 ;
switch ( V_10 . V_10 ) {
case V_22 :
V_12 = F_10 ( V_8 , V_23 ) ;
break;
case V_24 :
V_12 = F_10 ( V_8 , V_25 ) ;
break;
case V_26 :
V_12 = F_10 ( V_8 , V_27 ) ;
break;
case V_28 :
V_12 = F_10 ( V_8 , V_29 ) ;
break;
case V_30 :
V_12 = F_11 ( V_8 ) ;
break;
case V_31 :
V_12 = F_12 ( V_8 , V_32 ) ;
break;
case V_33 :
V_12 = F_12 ( V_8 , V_34 ) ;
break;
case V_35 :
V_12 = F_12 ( V_8 , V_36 ) ;
break;
case V_37 :
V_12 = F_13 ( V_8 ) ;
break;
case V_38 :
V_11 = F_8 ( struct V_9 , V_39 . V_40 ) ;
if ( V_10 . V_20 < V_11 )
return - V_13 ;
if ( F_9 ( & V_10 , ( void V_18 * ) V_6 , V_11 ) )
return - V_19 ;
V_12 = F_14 ( V_8 , V_10 . V_39 . type , V_10 . V_39 . V_41 ,
V_10 . V_39 . V_42 , V_10 . V_39 . V_40 ) ;
break;
default:
V_12 = - V_13 ;
}
}
return V_12 ;
}
