static int F_1 ( unsigned int V_1 , union V_2 * V_3 )
{
int V_4 = 0 ;
switch ( V_1 ) {
case V_5 :
V_4 = V_3 -> V_6 . V_7 != 0 ;
V_4 |= V_3 -> V_6 . V_8 != 0 ;
V_4 |= V_3 -> V_6 . V_9 != 0 ;
break;
default:
break;
}
return V_4 ? - V_10 : 0 ;
}
static unsigned int F_2 ( unsigned int V_1 )
{
switch ( V_1 ) {
case V_11 :
case V_12 :
case V_13 :
return V_14 ;
default:
return F_3 ( V_1 ) ;
}
}
long F_4 ( struct V_15 * V_16 , unsigned int V_1 , unsigned long V_3 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_21 ;
struct V_22 * V_23 = NULL ;
int V_4 = 0 ;
unsigned int V_24 ;
union V_2 V_25 ;
V_24 = F_2 ( V_1 ) ;
if ( F_5 ( V_1 ) > sizeof( V_25 ) )
return - V_10 ;
if ( F_6 ( & V_25 , ( void V_26 * ) V_3 , F_5 ( V_1 ) ) )
return - V_27 ;
V_4 = F_1 ( V_1 , & V_25 ) ;
if ( F_7 ( V_4 ) )
return V_4 ;
if ( ! ( V_24 & V_14 ) )
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
switch ( V_1 ) {
case V_28 :
{
struct V_22 * V_29 ;
V_29 = F_8 ( V_18 , V_25 . V_30 . V_31 ,
V_25 . V_30 . V_32 ,
V_25 . V_30 . V_33 ,
V_25 . V_30 . V_34 ) ;
if ( F_9 ( V_29 ) )
return F_10 ( V_29 ) ;
V_25 . V_30 . V_29 = V_29 -> V_35 ;
V_23 = V_29 ;
break;
}
case V_12 :
{
struct V_22 * V_29 ;
F_11 ( & V_18 -> V_36 ) ;
V_29 = F_12 ( V_18 , V_25 . V_29 . V_29 ) ;
if ( F_9 ( V_29 ) ) {
F_13 ( & V_18 -> V_36 ) ;
return F_10 ( V_29 ) ;
}
F_14 ( V_18 , V_29 ) ;
F_15 ( V_29 ) ;
F_13 ( & V_18 -> V_36 ) ;
break;
}
case V_37 :
case V_38 :
{
struct V_22 * V_29 ;
V_29 = F_16 ( V_18 , V_25 . V_29 . V_29 ) ;
if ( F_9 ( V_29 ) )
return F_10 ( V_29 ) ;
V_25 . V_39 . V_39 = F_17 ( V_18 , V_29 ) ;
F_18 ( V_29 ) ;
if ( V_25 . V_39 . V_39 < 0 )
V_4 = V_25 . V_39 . V_39 ;
break;
}
case V_40 :
{
struct V_22 * V_29 ;
V_29 = F_19 ( V_18 , V_25 . V_39 . V_39 ) ;
if ( F_9 ( V_29 ) )
V_4 = F_10 ( V_29 ) ;
else
V_25 . V_29 . V_29 = V_29 -> V_35 ;
break;
}
case V_11 :
{
V_4 = F_20 ( V_18 , V_25 . V_39 . V_39 ) ;
break;
}
case V_13 :
{
if ( ! V_21 -> V_41 )
return - V_42 ;
V_4 = V_21 -> V_41 ( V_18 , V_25 . V_43 . V_1 ,
V_25 . V_43 . V_3 ) ;
break;
}
case V_5 :
V_4 = F_21 ( V_18 , & V_25 . V_6 ) ;
break;
default:
return - V_42 ;
}
if ( V_24 & V_44 ) {
if ( F_22 ( ( void V_26 * ) V_3 , & V_25 , F_5 ( V_1 ) ) ) {
if ( V_23 )
F_23 ( V_18 , V_23 ) ;
return - V_27 ;
}
}
return V_4 ;
}
