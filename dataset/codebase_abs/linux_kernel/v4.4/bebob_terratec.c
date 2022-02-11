static int
F_1 ( struct V_1 * V_2 , unsigned int * V_3 )
{
unsigned int V_4 , V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , 0 , 9 , & V_4 ) ;
if ( V_6 < 0 )
goto V_8;
V_6 = F_2 ( V_2 -> V_7 , 0 , 8 , & V_5 ) ;
if ( V_6 < 0 )
goto V_8;
if ( V_4 == 0 )
* V_3 = 0 ;
else if ( V_5 == 0 )
* V_3 = 1 ;
else
* V_3 = 2 ;
V_8:
return V_6 ;
}
static int
F_3 ( struct V_1 * V_2 , unsigned int * V_3 )
{
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , 0 , 4 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( * V_3 >= F_4 ( V_9 ) )
return - V_10 ;
return 0 ;
}
