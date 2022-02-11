static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_2 , 0x0f ) ;
F_3 ( V_2 , 0x16 , V_4 , 0 ,
V_5 , V_3 ? V_5 : 0 ) ;
F_3 ( V_2 , 0x1a , V_4 , 3 ,
V_5 , V_3 ? 0 : V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
if ( ( V_6 >> 26 ) == V_7 )
F_1 ( V_2 ) ;
}
