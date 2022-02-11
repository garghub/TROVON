static void
F_1 ( unsigned int V_1 )
{
F_2 ( V_1 , V_2 ) ;
}
static int
F_3 ( struct V_3 * V_4 , unsigned long V_5 ,
void * V_6 )
{
F_1 ( V_7 ) ;
return V_8 ;
}
static T_1
F_4 ( struct V_9 * V_10 , void * V_11 )
{
switch ( V_10 -> type ) {
case V_12 :
return V_13 ;
case V_14 :
V_2 = V_10 -> V_15 . V_16 . V_17 ;
return V_13 ;
default:
return V_18 ;
}
}
static int F_5 ( struct V_19 * V_20 )
{
T_1 V_21 ;
T_2 V_22 ;
V_21 = F_6 ( V_20 -> V_23 , L_1 , NULL ,
& V_22 ) ;
if ( F_7 ( V_21 ) || ( V_22 & 0x0B ) != 0x0B )
return - V_24 ;
F_8 ( V_20 -> V_23 , V_25 ,
F_4 , NULL ) ;
if ( ! V_2 )
return - V_24 ;
F_9 ( & V_26 ,
& V_27 ) ;
return 0 ;
}
static int F_10 ( struct V_19 * V_20 )
{
F_11 ( & V_26 ,
& V_27 ) ;
return 0 ;
}
