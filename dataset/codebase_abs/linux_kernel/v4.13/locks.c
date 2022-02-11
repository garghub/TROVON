void F_1 ( T_1 * V_1 )
{
unsigned int V_2 , V_3 , V_4 ;
V_2 = V_1 -> V_5 ;
if ( V_2 == 0 )
return;
V_3 = V_2 & 0xffff ;
F_2 ( V_3 >= V_6 ) ;
V_4 = F_3 ( F_4 ( V_3 ) . V_4 ) ;
if ( ( V_4 & 1 ) == 0 )
return;
F_5 () ;
if ( V_1 -> V_5 != V_2 )
return;
F_6 ( V_7 ,
F_7 ( V_3 ) , V_4 ) ;
}
void F_8 ( T_2 * V_8 )
{
int V_2 ;
unsigned int V_3 , V_4 ;
V_2 = V_8 -> V_1 ;
if ( V_2 >= 0 )
return;
V_3 = V_2 & 0xffff ;
F_2 ( V_3 >= V_6 ) ;
V_4 = F_3 ( F_4 ( V_3 ) . V_4 ) ;
if ( ( V_4 & 1 ) == 0 )
return;
F_5 () ;
if ( V_8 -> V_1 != V_2 )
return;
F_6 ( V_7 ,
F_7 ( V_3 ) , V_4 ) ;
}
