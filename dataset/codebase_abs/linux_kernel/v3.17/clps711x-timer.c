static T_1 T_2 F_1 ( void )
{
return ~ F_2 ( V_1 ) ;
}
static int T_3 F_3 ( struct V_2 * clock , void T_4 * V_3 )
{
unsigned long V_4 ;
if ( ! V_3 )
return - V_5 ;
if ( F_4 ( clock ) )
return F_5 ( clock ) ;
V_4 = F_6 ( clock ) ;
V_1 = V_3 ;
F_7 ( V_1 , L_1 , V_4 , 300 , 16 ,
V_6 ) ;
F_8 ( F_1 , 16 , V_4 ) ;
return 0 ;
}
static T_5 F_9 ( int V_7 , void * V_8 )
{
struct V_9 * V_10 = V_8 ;
V_10 -> V_11 ( V_10 ) ;
return V_12 ;
}
static void F_10 ( enum V_13 V_14 ,
struct V_9 * V_10 )
{
}
static int T_3 F_11 ( struct V_2 * clock , void T_4 * V_3 ,
unsigned int V_7 )
{
struct V_9 * V_15 ;
unsigned long V_4 ;
if ( ! V_7 )
return - V_16 ;
if ( ! V_3 )
return - V_5 ;
if ( F_4 ( clock ) )
return F_5 ( clock ) ;
V_15 = F_12 ( sizeof( * V_15 ) , V_17 ) ;
if ( ! V_15 )
return - V_5 ;
V_4 = F_6 ( clock ) ;
F_13 ( F_14 ( V_4 , V_18 ) , V_3 ) ;
V_15 -> V_19 = L_2 ;
V_15 -> V_20 = 300 ;
V_15 -> V_21 = V_22 | V_23 ;
V_15 -> V_24 = F_10 ;
V_15 -> V_25 = F_15 ( 0 ) ;
F_16 ( V_15 , V_18 , 0 , 0 ) ;
return F_17 ( V_7 , F_9 , V_26 ,
L_3 , V_15 ) ;
}
void T_3 F_18 ( void T_4 * V_27 , void T_4 * V_28 ,
unsigned int V_7 )
{
struct V_2 * V_29 = F_19 ( L_4 , NULL ) ;
struct V_2 * V_30 = F_19 ( L_5 , NULL ) ;
F_20 ( F_3 ( V_29 , V_27 ) ) ;
F_20 ( F_11 ( V_30 , V_28 , V_7 ) ) ;
}
static void T_3 F_21 ( struct V_31 * V_32 )
{
unsigned int V_7 = F_22 ( V_32 , 0 ) ;
struct V_2 * clock = F_23 ( V_32 , 0 ) ;
void T_4 * V_3 = F_24 ( V_32 , 0 ) ;
switch ( F_25 ( V_32 , L_6 ) ) {
case V_33 :
F_20 ( F_3 ( clock , V_3 ) ) ;
break;
case V_34 :
F_20 ( F_11 ( clock , V_3 , V_7 ) ) ;
break;
default:
break;
}
}
