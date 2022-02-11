void F_1 ( unsigned V_1 , T_1 V_2 )
{
unsigned V_3 = ( V_2 & ~ V_4 ) |
( ( V_1 & 0x3ff ) << 4 ) ;
unsigned V_5 = 0 ;
int V_6 ;
V_6 = F_2 ( V_7 ,
& V_3 , & V_5 ) ;
if ( V_6 )
F_3 ( L_1 ,
V_8 , V_6 , V_3 , V_5 ) ;
}
