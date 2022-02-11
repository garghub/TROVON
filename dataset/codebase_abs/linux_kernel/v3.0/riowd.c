static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_4 , V_2 -> V_7 + 0 ) ;
F_3 ( V_3 , V_2 -> V_7 + 1 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
static int F_5 ( struct V_8 * V_8 , struct V_9 * V_10 )
{
F_6 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_7 ( struct V_8 * V_8 , struct V_9 * V_10 )
{
return 0 ;
}
static long F_8 ( struct V_9 * V_10 , unsigned int V_11 , unsigned long V_12 )
{
static const struct V_13 V_14 = {
. V_15 = V_16 ,
. V_17 = 1 ,
. V_18 = V_19 ,
} ;
void T_2 * V_20 = ( void T_2 * ) V_12 ;
struct V_1 * V_2 = V_21 ;
unsigned int V_15 ;
int V_22 ;
switch ( V_11 ) {
case V_23 :
if ( F_9 ( V_20 , & V_14 , sizeof( V_14 ) ) )
return - V_24 ;
break;
case V_25 :
case V_26 :
if ( F_10 ( 0 , ( int T_2 * ) V_20 ) )
return - V_24 ;
break;
case V_27 :
F_1 ( V_2 , V_28 , V_29 ) ;
break;
case V_30 :
if ( F_11 ( & V_15 , V_20 , sizeof( V_15 ) ) )
return - V_24 ;
if ( V_15 & V_31 )
F_1 ( V_2 , 0 , V_29 ) ;
else if ( V_15 & V_32 )
F_1 ( V_2 , V_28 , V_29 ) ;
else
return - V_33 ;
break;
case V_34 :
if ( F_12 ( V_22 , ( int T_2 * ) V_20 ) )
return - V_24 ;
if ( ( V_22 < 60 ) || ( V_22 > ( 255 * 60 ) ) )
return - V_33 ;
V_28 = ( V_22 + 59 ) / 60 ;
F_1 ( V_2 , V_28 , V_29 ) ;
case V_35 :
return F_10 ( V_28 * 60 , ( int T_2 * ) V_20 ) ;
default:
return - V_33 ;
} ;
return 0 ;
}
static T_3 F_13 ( struct V_9 * V_9 , const char T_2 * V_36 ,
T_4 V_37 , T_5 * V_38 )
{
struct V_1 * V_2 = V_21 ;
if ( V_37 ) {
F_1 ( V_2 , V_28 , V_29 ) ;
return 1 ;
}
return 0 ;
}
static int T_6 F_14 ( struct V_39 * V_40 )
{
struct V_1 * V_2 ;
int V_41 = - V_33 ;
if ( V_21 )
goto V_42;
V_41 = - V_43 ;
V_2 = F_15 ( sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 )
goto V_42;
F_16 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = F_17 ( & V_40 -> V_45 [ 0 ] , 0 , 2 , V_19 ) ;
if ( ! V_2 -> V_7 ) {
F_18 (KERN_ERR PFX L_1 ) ;
goto V_46;
}
V_21 = V_2 ;
V_41 = F_19 ( & V_47 ) ;
if ( V_41 ) {
F_18 (KERN_ERR PFX L_2 ) ;
goto V_48;
}
F_18 (KERN_INFO PFX L_3
L_4 , riowd_timeout, p->regs) ;
F_20 ( & V_40 -> V_49 , V_2 ) ;
return 0 ;
V_48:
V_21 = NULL ;
F_21 ( & V_40 -> V_45 [ 0 ] , V_2 -> V_7 , 2 ) ;
V_46:
F_22 ( V_2 ) ;
V_42:
return V_41 ;
}
static int T_7 F_23 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_24 ( & V_40 -> V_49 ) ;
F_25 ( & V_47 ) ;
F_21 ( & V_40 -> V_45 [ 0 ] , V_2 -> V_7 , 2 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int T_8 F_26 ( void )
{
return F_27 ( & V_50 ) ;
}
static void T_9 F_28 ( void )
{
F_29 ( & V_50 ) ;
}
