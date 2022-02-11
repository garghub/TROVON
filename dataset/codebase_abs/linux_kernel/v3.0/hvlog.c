void F_1 ( const void * V_1 , T_1 V_2 )
{
struct V_3 V_4 ;
T_1 V_5 ;
T_1 V_6 = F_2 ( V_1 ) ;
while ( V_2 ) {
V_4 . V_7 = V_6 ;
V_5 = ( ( V_6 & V_8 ) + V_9 ) - V_6 ;
if ( V_5 > V_2 )
V_5 = V_2 ;
V_4 . V_2 = V_5 ;
V_2 -= V_5 ;
F_3 ( V_10 ,
F_2 ( & V_4 ) ,
V_5 ) ;
V_6 = ( V_6 & V_8 ) + V_9 ;
}
}
