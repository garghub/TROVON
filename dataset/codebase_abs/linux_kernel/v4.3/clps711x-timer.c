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
static int T_3 F_10 ( struct V_2 * clock , void T_4 * V_3 ,
unsigned int V_7 )
{
struct V_9 * V_13 ;
unsigned long V_4 ;
if ( ! V_7 )
return - V_14 ;
if ( ! V_3 )
return - V_5 ;
if ( F_4 ( clock ) )
return F_5 ( clock ) ;
V_13 = F_11 ( sizeof( * V_13 ) , V_15 ) ;
if ( ! V_13 )
return - V_5 ;
V_4 = F_6 ( clock ) ;
F_12 ( F_13 ( V_4 , V_16 ) , V_3 ) ;
V_13 -> V_17 = L_2 ;
V_13 -> V_18 = 300 ;
V_13 -> V_19 = V_20 | V_21 ;
V_13 -> V_22 = F_14 ( 0 ) ;
F_15 ( V_13 , V_16 , 0 , 0 ) ;
return F_16 ( V_7 , F_9 , V_23 ,
L_3 , V_13 ) ;
}
void T_3 F_17 ( void T_4 * V_24 , void T_4 * V_25 ,
unsigned int V_7 )
{
struct V_2 * V_26 = F_18 ( L_4 , NULL ) ;
struct V_2 * V_27 = F_18 ( L_5 , NULL ) ;
F_19 ( F_3 ( V_26 , V_24 ) ) ;
F_19 ( F_10 ( V_27 , V_25 , V_7 ) ) ;
}
static void T_3 F_20 ( struct V_28 * V_29 )
{
unsigned int V_7 = F_21 ( V_29 , 0 ) ;
struct V_2 * clock = F_22 ( V_29 , 0 ) ;
void T_4 * V_3 = F_23 ( V_29 , 0 ) ;
switch ( F_24 ( V_29 , L_6 ) ) {
case V_30 :
F_19 ( F_3 ( clock , V_3 ) ) ;
break;
case V_31 :
F_19 ( F_10 ( clock , V_3 , V_7 ) ) ;
break;
default:
break;
}
}
