static struct V_1 F_1 ( void )
{
T_1 V_2 ;
struct V_1 V_3 ;
V_2 = F_2 ( V_4 ) ;
V_3 . V_5 = V_2 & 0x1ff ;
V_3 . V_6 = ( V_2 >> 9 ) & 0x7f ;
V_3 . V_7 = ( V_2 >> 16 ) & 03 ;
return V_3 ;
}
static void F_3 ( struct V_1 V_3 )
{
T_1 V_2 ;
V_2 = F_2 ( V_4 ) & ~ 0x7ffff ;
V_2 |= V_3 . V_5 | ( V_3 . V_6 << 9 ) | ( V_3 . V_7 << 16 ) ;
F_4 ( 0xa05f , V_8 ) ;
F_4 ( V_2 , V_4 ) ;
F_4 ( 0 , V_8 ) ;
}
void T_2 F_5 ( bool V_9 )
{
struct V_10 * V_10 ;
V_10 = F_6 ( NULL , L_1 , NULL , V_11 , 0 ) ;
F_7 ( V_10 , L_1 , NULL ) ;
V_10 = F_6 ( NULL , L_2 , NULL , V_11 ,
14745600 ) ;
F_7 ( V_10 , NULL , L_3 ) ;
F_7 ( V_10 , NULL , L_4 ) ;
if ( V_9 )
F_7 ( V_10 , NULL , L_5 ) ;
V_10 = F_6 ( NULL , L_6 , NULL , V_11 ,
24000000 ) ;
F_7 ( V_10 , NULL , L_7 ) ;
F_7 ( V_10 , NULL , L_8 ) ;
if ( ! V_9 )
F_7 ( V_10 , NULL , L_9 ) ;
if ( ! V_9 )
return;
V_10 = F_6 ( NULL , L_10 , NULL , V_11 ,
1000000 ) ;
F_7 ( V_10 , NULL , L_11 ) ;
V_10 = F_8 ( NULL , & V_12 ) ;
F_7 ( V_10 , NULL , L_12 ) ;
}
