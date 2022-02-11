void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0x4c , 0x01800000 , 0x2 ) ;
F_2 ( V_2 , 0xcb4 , 0xff , 0x77 ) ;
F_2 ( V_2 , 0x974 , 0x300 , 0x3 ) ;
F_2 ( V_2 , 0x1990 , 0x300 , 0x0 ) ;
F_2 ( V_2 , 0xcbc , 0x80000 , 0x0 ) ;
F_2 ( V_2 , 0x70 , 0xff000000 , 0x0e ) ;
F_2 ( V_2 , 0x1704 , 0xffffffff , 0x7700 ) ;
F_2 ( V_2 , 0x1700 , 0xffffffff , 0xc00f0038 ) ;
}
void F_3 ( struct V_1 * V_2 ,
T_1 V_3 )
{
F_4 ( V_2 , V_3 ) ;
}
void F_5 ( struct V_1 * V_2 ,
T_1 V_3 )
{
F_4 ( V_2 , V_3 ) ;
}
void F_4 ( struct V_1 * V_2 ,
T_1 V_3 )
{
if ( V_3 )
F_2 ( V_2 , 0xcbc , 0x300 , 0x1 ) ;
else
F_2 ( V_2 , 0xcbc , 0x300 , 0x2 ) ;
}
