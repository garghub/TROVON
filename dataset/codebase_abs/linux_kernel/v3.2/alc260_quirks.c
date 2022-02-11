static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_2 , 0x0f ) ;
if ( V_3 ) {
F_3 ( V_2 , 0x01 , 0 ,
V_4 , 1 ) ;
F_3 ( V_2 , 0x0f , 0 ,
V_5 ,
V_6 ) ;
} else {
F_3 ( V_2 , 0x01 , 0 ,
V_4 , 0 ) ;
F_3 ( V_2 , 0x0f , 0 ,
V_5 ,
V_7 ) ;
}
}
static void F_4 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
if ( ( V_8 >> 26 ) == V_9 )
F_1 ( V_2 ) ;
}
