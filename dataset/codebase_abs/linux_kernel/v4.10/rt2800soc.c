static bool F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static void F_2 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
F_4 ( V_2 , V_4 , 0 ) ;
F_4 ( V_2 , V_5 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_6 V_7 )
{
int V_8 = 0 ;
switch ( V_7 ) {
case V_9 :
V_8 = F_6 ( V_2 ) ;
break;
case V_10 :
F_2 ( V_2 ) ;
break;
case V_11 :
case V_12 :
F_7 ( V_2 , V_7 ) ;
break;
case V_13 :
case V_14 :
case V_15 :
case V_16 :
V_8 = 0 ;
break;
default:
V_8 = - V_17 ;
break;
}
if ( F_8 ( V_8 ) )
F_9 ( V_2 , L_1 ,
V_7 , V_8 ) ;
return V_8 ;
}
static int F_10 ( struct V_1 * V_2 )
{
void T_1 * V_18 = F_11 ( 0x1F040000 , V_19 ) ;
if ( ! V_18 )
return - V_20 ;
F_12 ( V_2 -> V_21 , V_18 , V_19 ) ;
F_13 ( V_18 ) ;
return 0 ;
}
static char * F_14 ( struct V_1 * V_2 )
{
F_15 ( 1 ) ;
return NULL ;
}
static int F_16 ( struct V_1 * V_2 ,
const T_2 * V_22 , const T_3 V_23 )
{
F_15 ( 1 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
const T_2 * V_22 , const T_3 V_23 )
{
F_15 ( 1 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
const T_2 * V_22 , const T_3 V_23 )
{
F_15 ( 1 ) ;
return 0 ;
}
static int F_19 ( struct V_24 * V_25 )
{
return F_20 ( V_25 , & V_26 ) ;
}
