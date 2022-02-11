static int
F_1 ( struct V_1 * V_2 , unsigned int * V_3 )
{
unsigned int V_4 , V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , 0 , 0 , & V_4 ) ;
if ( V_6 < 0 )
goto V_8;
V_6 = F_2 ( V_2 -> V_7 , 0 , 0 , & V_5 ) ;
if ( V_6 < 0 )
goto V_8;
* V_3 = ( V_4 & 0x01 ) | ( ( V_5 & 0x01 ) << 1 ) ;
V_8:
return V_6 ;
}
static int
F_3 ( struct V_1 * V_2 , unsigned int * V_3 )
{
return F_2 ( V_2 -> V_7 , 0 , 4 , V_3 ) ;
}
