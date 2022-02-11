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
static void F_10 ( struct V_1 * V_2 )
{
F_3 ( & V_9 ) ;
F_11 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
F_6 ( & V_9 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
unsigned int * V_6 = V_2 -> V_7 ;
F_13 ( ! V_2 -> V_14 ) ;
F_2 ( L_3 , V_2 -> V_8 ) ;
F_3 ( & V_9 ) ;
F_4 ( V_10 , V_2 -> V_8 ) = 1 ;
* V_6 = V_2 -> V_14 ;
F_6 ( & V_9 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
unsigned int * V_6 = V_2 -> V_7 ;
F_2 ( L_4 , V_2 -> V_8 ) ;
F_3 ( & V_9 ) ;
F_4 ( V_10 , V_2 -> V_8 ) = 0 ;
* V_6 = 0 ;
F_6 ( & V_9 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
unsigned int * V_6 = V_2 -> V_7 ;
F_3 ( & V_9 ) ;
F_2 ( L_5 ,
V_2 -> V_8 , V_2 -> V_17 , V_2 -> V_18 , V_2 -> V_14 , * V_6 ) ;
if ( V_2 -> V_18 < * V_6 )
F_5 ( V_2 , V_2 -> V_18 , V_19 ) ;
else if ( V_2 -> V_17 > * V_6 )
F_5 ( V_2 , V_2 -> V_17 , V_12 ) ;
else
F_5 ( V_2 , * V_6 , V_12 ) ;
F_6 ( & V_9 ) ;
}
static int T_2 F_16 ( void )
{
return F_17 ( & V_20 ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_20 ) ;
}
struct V_21 * F_20 ( void )
{
return & V_20 ;
}
