static int F_1 ( struct V_1 * V_1 , int V_2 ,
int V_3 , T_1 * V_4 )
{
int V_5 ;
if ( F_2 ( V_1 , V_2 , & V_5 ) )
return - V_6 ;
* V_4 = ( V_5 & F_3 ( V_3 ) ) ? 1 : 0 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , int V_2 ,
int V_3 , bool V_7 )
{
int V_5 ;
if ( F_2 ( V_1 , V_2 , & V_5 ) )
return - V_6 ;
if ( V_7 )
V_5 |= F_3 ( V_3 ) ;
else
V_5 &= ~ F_3 ( V_3 ) ;
if ( F_5 ( V_1 , V_2 , V_5 ) )
return - V_6 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , int V_2 )
{
struct V_8 * V_9 ;
int V_10 , V_11 ;
V_9 = F_7 ( NULL , L_1 ) ;
if ( F_8 ( V_9 ) )
return - V_12 ;
V_10 = F_9 ( V_9 , & V_11 ) ;
if ( V_10 < 0 )
V_11 = V_10 ;
F_10 ( V_9 ) ;
return V_11 ;
}
static T_2 F_11 ( T_3 V_13 ,
T_4 V_14 , T_3 V_15 , T_1 * V_4 ,
void * V_16 , void * V_17 )
{
return V_18 ;
}
static int F_12 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 . V_22 ;
struct V_24 * V_25 = F_13 ( V_22 ) ;
T_2 V_26 ;
int V_27 ;
V_26 = F_14 ( F_15 ( V_22 ) ,
V_28 , F_11 ,
NULL , NULL ) ;
if ( F_16 ( V_26 ) )
return - V_29 ;
V_27 = F_17 ( & V_20 -> V_23 ,
F_15 ( V_22 ) , V_25 -> V_1 ,
& V_30 ) ;
if ( V_27 )
F_18 ( F_15 ( V_22 ) ,
V_28 ,
F_11 ) ;
return V_27 ;
}
static int T_5 F_19 ( void )
{
return F_20 ( & V_31 ) ;
}
