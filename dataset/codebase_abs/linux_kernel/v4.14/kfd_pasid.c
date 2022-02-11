int F_1 ( void )
{
V_1 = V_2 ;
V_3 = F_2 ( F_3 ( V_1 ) , sizeof( long ) ,
V_4 ) ;
if ( ! V_3 )
return - V_5 ;
F_4 ( 0 , V_3 ) ;
return 0 ;
}
void F_5 ( void )
{
F_6 ( V_3 ) ;
}
bool F_7 ( unsigned int V_6 )
{
if ( V_6 < V_1 ) {
bool V_7 ;
F_8 ( & V_8 ) ;
V_7 = ( F_9 ( V_3 , V_1 , V_6 ) ==
V_1 ) ;
if ( V_7 )
V_1 = V_6 ;
F_10 ( & V_8 ) ;
return V_7 ;
}
return true ;
}
inline unsigned int F_11 ( void )
{
return V_1 ;
}
unsigned int F_12 ( void )
{
unsigned int V_9 ;
F_8 ( & V_8 ) ;
V_9 = F_13 ( V_3 , V_1 ) ;
if ( V_9 == V_1 )
V_9 = 0 ;
else
F_4 ( V_9 , V_3 ) ;
F_10 ( & V_8 ) ;
return V_9 ;
}
void F_14 ( unsigned int V_10 )
{
if ( ! F_15 ( V_10 == 0 || V_10 >= V_1 ) )
F_16 ( V_10 , V_3 ) ;
}
