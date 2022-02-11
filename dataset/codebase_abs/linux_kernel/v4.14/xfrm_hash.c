struct V_1 * F_1 ( unsigned int V_2 )
{
struct V_1 * V_3 ;
if ( V_2 <= V_4 )
V_3 = F_2 ( V_2 , V_5 ) ;
else if ( V_6 )
V_3 = F_3 ( V_2 ) ;
else
V_3 = (struct V_1 * )
F_4 ( V_5 | V_7 | V_8 ,
F_5 ( V_2 ) ) ;
return V_3 ;
}
void F_6 ( struct V_1 * V_3 , unsigned int V_2 )
{
if ( V_2 <= V_4 )
F_7 ( V_3 ) ;
else if ( V_6 )
F_8 ( V_3 ) ;
else
F_9 ( ( unsigned long ) V_3 , F_5 ( V_2 ) ) ;
}
