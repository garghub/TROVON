static int F_1 ( enum V_1 V_2 , int V_3 , int * V_4 )
{
int V_5 ;
V_5 = F_2 ( & V_6 , V_2 , NULL ,
V_3 , V_4 ) ;
return F_3 ( V_5 ) ;
}
int F_4 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
int V_5 ;
F_5 ( & V_10 , V_9 ) ;
V_5 = F_6 ( & V_6 , V_8 ) ;
F_7 ( & V_10 , V_9 ) ;
return V_5 ;
}
int F_8 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
int V_5 ;
F_5 ( & V_10 , V_9 ) ;
V_5 = F_9 ( & V_6 , V_8 ) ;
F_7 ( & V_10 , V_9 ) ;
return V_5 ;
}
int F_10 ( void )
{
int V_4 ;
int V_5 = 0 ;
F_11 ( & V_10 ) ;
V_5 = F_1 ( V_11 , - 1 , & V_4 ) ;
if ( V_5 )
F_1 ( V_12 , V_4 - 1 , NULL ) ;
F_12 ( & V_10 ) ;
return V_5 ;
}
int F_13 ( void )
{
int V_5 ;
F_11 ( & V_10 ) ;
V_5 = F_1 ( V_13 , - 1 , NULL ) ;
F_12 ( & V_10 ) ;
return V_5 ;
}
int F_14 ( void )
{
int V_4 ;
int V_5 = 0 ;
F_11 ( & V_10 ) ;
V_5 = F_1 ( V_14 , - 1 , & V_4 ) ;
if ( V_5 )
F_1 ( V_15 , V_4 - 1 , NULL ) ;
F_12 ( & V_10 ) ;
return V_5 ;
}
int F_15 ( void )
{
int V_5 ;
F_11 ( & V_10 ) ;
V_5 = F_1 ( V_16 , - 1 , NULL ) ;
F_12 ( & V_10 ) ;
return V_5 ;
}
static int F_16 ( void )
{
int V_5 ;
V_5 = F_10 () ;
if ( V_5 )
return V_5 ;
V_5 = F_14 () ;
return V_5 ;
}
static void F_17 ( void )
{
F_15 () ;
F_13 () ;
}
static int F_18 ( void )
{
F_19 ( & V_17 ) ;
return 0 ;
}
