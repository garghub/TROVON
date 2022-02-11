static int F_1 ( unsigned int V_1 )
{
const struct V_2 * V_3 = NULL ;
int V_4 = - V_5 ;
V_1 = F_2 ( V_1 ) ;
if ( V_1 < F_3 ( V_6 ) )
V_3 = V_6 [ V_1 ] ;
if ( V_3 )
V_4 = F_4 ( V_3 ) ;
return V_4 ? V_4 : 1 ;
}
static int F_5 ( unsigned int V_1 , struct V_7 * V_8 )
{
const struct V_2 * V_3 = NULL ;
unsigned int V_9 = F_2 ( V_1 ) ;
int V_4 ;
if ( V_9 < F_3 ( V_6 ) )
V_3 = V_6 [ V_9 ] ;
if ( V_3 )
V_4 = F_6 ( V_3 ) ;
else
V_4 = - V_5 ;
return V_4 ;
}
static void T_1 F_7 ( unsigned int V_10 )
{
F_8 ( F_9 ( V_11 ) , V_12 ) ;
V_13 = F_10 ( V_14 ) ;
F_11 ( V_10 ) ;
F_12 () ;
F_1 ( 1 ) ;
F_1 ( 2 ) ;
F_1 ( 3 ) ;
}
static int F_13 ( unsigned int V_1 )
{
if ( F_14 ( V_1 ) )
return F_1 ( V_1 ) ;
return 0 ;
}
