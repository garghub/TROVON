static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 = - V_5 ;
unsigned int * V_6 = V_2 -> V_7 ;
F_2 ( L_1 , V_2 -> V_8 , V_3 ) ;
F_3 ( & V_9 ) ;
if ( ! F_4 ( V_10 , V_2 -> V_8 ) )
goto V_11;
* V_6 = V_3 ;
V_4 = F_5 ( V_2 , V_3 , V_12 ) ;
V_11:
F_6 ( & V_9 ) ;
return V_4 ;
}
static T_1 F_7 ( struct V_1 * V_2 , char * V_13 )
{
return sprintf ( V_13 , L_2 , V_2 -> V_14 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned int * V_6 ;
V_6 = F_9 ( sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
return - V_16 ;
V_2 -> V_7 = V_6 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_17 )
{
unsigned int * V_6 = V_2 -> V_7 ;
unsigned int V_8 = V_2 -> V_8 ;
int V_18 = 0 ;
if ( V_17 == V_19 )
return F_8 ( V_2 ) ;
if ( ! V_6 )
return - V_5 ;
switch ( V_17 ) {
case V_20 :
F_3 ( & V_9 ) ;
V_2 -> V_7 = NULL ;
F_11 ( V_6 ) ;
F_6 ( & V_9 ) ;
break;
case V_21 :
F_12 ( ! V_2 -> V_14 ) ;
F_2 ( L_3 , V_8 ) ;
F_3 ( & V_9 ) ;
F_4 ( V_10 , V_8 ) = 1 ;
* V_6 = V_2 -> V_14 ;
F_6 ( & V_9 ) ;
break;
case V_22 :
F_2 ( L_4 , V_8 ) ;
F_3 ( & V_9 ) ;
F_4 ( V_10 , V_8 ) = 0 ;
* V_6 = 0 ;
F_6 ( & V_9 ) ;
break;
case V_23 :
F_3 ( & V_9 ) ;
F_2 ( L_5 ,
V_8 , V_2 -> V_24 , V_2 -> V_25 , V_2 -> V_14 , * V_6 ) ;
if ( V_2 -> V_25 < * V_6 )
F_5 ( V_2 , V_2 -> V_25 ,
V_26 ) ;
else if ( V_2 -> V_24 > * V_6 )
F_5 ( V_2 , V_2 -> V_24 ,
V_12 ) ;
else
F_5 ( V_2 , * V_6 ,
V_12 ) ;
F_6 ( & V_9 ) ;
break;
}
return V_18 ;
}
static int T_2 F_13 ( void )
{
return F_14 ( & V_27 ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_27 ) ;
}
struct V_28 * F_17 ( void )
{
return & V_27 ;
}
