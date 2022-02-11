static int F_1 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
struct V_5 V_6 ;
unsigned int V_7 ;
if ( V_2 -> V_8 == NULL )
return - V_9 ;
if ( F_2 ( V_6 . V_10 , & V_4 -> V_10 ) ||
F_2 ( V_6 . V_11 , & V_4 -> V_11 ) ||
F_2 ( V_6 . V_12 , & V_4 -> V_12 ) ||
F_2 ( V_7 , & V_4 -> V_13 ) )
return - V_14 ;
V_6 . V_13 = V_7 ;
switch ( V_6 . V_10 ) {
case V_15 :
return F_3 ( V_2 -> V_8 , & V_6 ) ;
case V_16 :
return F_4 ( V_2 -> V_17 , & V_6 ) ;
}
return - V_9 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_18 T_1 * V_4 )
{
int V_19 ;
struct V_20 V_21 ;
if ( V_2 -> V_8 == NULL )
return - V_9 ;
if ( F_2 ( V_21 . V_10 , & V_4 -> V_10 ) )
return - V_14 ;
switch ( V_21 . V_10 ) {
case V_15 :
V_19 = F_6 ( V_2 -> V_8 , & V_21 ) ;
break;
case V_16 :
V_19 = F_7 ( V_2 -> V_17 , & V_21 ) ;
break;
default:
return - V_9 ;
}
if ( V_19 < 0 )
return V_19 ;
if ( F_8 ( V_21 . V_22 . V_23 , & V_4 -> V_22 . V_23 ) ||
F_8 ( V_21 . V_22 . V_24 , & V_4 -> V_22 . V_24 ) ||
F_8 ( V_21 . V_25 , & V_4 -> V_25 ) ||
F_8 ( V_21 . V_26 , & V_4 -> V_26 ) )
return - V_14 ;
return 0 ;
}
static long F_9 ( struct V_27 * V_27 , unsigned int V_28 , unsigned long V_29 )
{
struct V_1 * V_2 ;
void T_1 * V_30 = F_10 ( V_29 ) ;
V_2 = V_27 -> V_31 ;
switch ( V_28 ) {
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return F_11 ( V_27 , V_28 , ( unsigned long ) V_30 ) ;
case V_36 :
return F_1 ( V_2 , V_30 ) ;
case V_37 :
return F_5 ( V_2 , V_30 ) ;
}
return - V_38 ;
}
