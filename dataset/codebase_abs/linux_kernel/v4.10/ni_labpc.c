static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_5 = V_4 -> V_6 [ 1 ] ;
unsigned int V_7 = V_4 -> V_6 [ 2 ] ;
int V_8 ;
V_8 = F_2 ( V_2 , V_4 -> V_6 [ 0 ] , 0x20 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_5 , 0 ) ;
if ( V_8 )
return V_8 ;
if ( V_2 -> V_5 )
F_4 ( V_2 , V_7 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
