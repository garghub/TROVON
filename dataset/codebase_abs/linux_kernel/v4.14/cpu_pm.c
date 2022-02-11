static int F_1 ( enum V_1 V_2 , int V_3 , int * V_4 )
{
int V_5 ;
F_2 () ;
V_5 = F_3 ( & V_6 , V_2 , NULL ,
V_3 , V_4 ) ;
F_4 () ;
return F_5 ( V_5 ) ;
}
int F_6 ( struct V_7 * V_8 )
{
return F_7 ( & V_6 , V_8 ) ;
}
int F_8 ( struct V_7 * V_8 )
{
return F_9 ( & V_6 , V_8 ) ;
}
int F_10 ( void )
{
int V_4 ;
int V_5 = 0 ;
V_5 = F_1 ( V_9 , - 1 , & V_4 ) ;
if ( V_5 )
F_1 ( V_10 , V_4 - 1 , NULL ) ;
return V_5 ;
}
int F_11 ( void )
{
return F_1 ( V_11 , - 1 , NULL ) ;
}
int F_12 ( void )
{
int V_4 ;
int V_5 = 0 ;
V_5 = F_1 ( V_12 , - 1 , & V_4 ) ;
if ( V_5 )
F_1 ( V_13 , V_4 - 1 , NULL ) ;
return V_5 ;
}
int F_13 ( void )
{
return F_1 ( V_14 , - 1 , NULL ) ;
}
static int F_14 ( void )
{
int V_5 ;
V_5 = F_10 () ;
if ( V_5 )
return V_5 ;
V_5 = F_12 () ;
return V_5 ;
}
static void F_15 ( void )
{
F_13 () ;
F_11 () ;
}
static int F_16 ( void )
{
F_17 ( & V_15 ) ;
return 0 ;
}
