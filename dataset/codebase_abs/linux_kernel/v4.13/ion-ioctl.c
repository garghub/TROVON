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
default:
return F_3 ( V_1 ) ;
}
}
long F_4 ( struct V_11 * V_12 , unsigned int V_1 , unsigned long V_3 )
{
int V_4 = 0 ;
unsigned int V_13 ;
union V_2 V_14 ;
V_13 = F_2 ( V_1 ) ;
if ( F_5 ( V_1 ) > sizeof( V_14 ) )
return - V_10 ;
if ( F_6 ( & V_14 , ( void V_15 * ) V_3 , F_5 ( V_1 ) ) )
return - V_16 ;
V_4 = F_1 ( V_1 , & V_14 ) ;
if ( F_7 ( V_4 ) )
return V_4 ;
if ( ! ( V_13 & V_17 ) )
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
switch ( V_1 ) {
case V_18 :
{
int V_19 ;
V_19 = F_8 ( V_14 . V_20 . V_21 ,
V_14 . V_20 . V_22 ,
V_14 . V_20 . V_23 ) ;
if ( V_19 < 0 )
return V_19 ;
V_14 . V_20 . V_19 = V_19 ;
break;
}
case V_5 :
V_4 = F_9 ( & V_14 . V_6 ) ;
break;
default:
return - V_24 ;
}
if ( V_13 & V_25 ) {
if ( F_10 ( ( void V_15 * ) V_3 , & V_14 , F_5 ( V_1 ) ) )
return - V_16 ;
}
return V_4 ;
}
