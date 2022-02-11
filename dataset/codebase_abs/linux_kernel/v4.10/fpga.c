static void T_1 * F_1 ( void )
{
unsigned long V_1 ;
void T_1 * V_2 ;
for ( V_1 = V_3 ; V_1 < V_4 ; V_1 += V_5 ) {
V_2 = F_2 ( V_1 + V_6 , V_7 ) ;
if ( ! V_2 ) {
continue;
}
if ( F_3 ( V_2 + V_8 ) == V_9 )
return V_2 ;
F_4 ( V_2 ) ;
}
return NULL ;
}
void T_2 F_5 ( void )
{
T_3 V_10 , V_11 ;
V_12 = F_1 () ;
if ( F_6 ( ! V_12 ) ) {
F_7 ( L_1 ) ;
return;
}
V_10 = F_8 ( V_13 ) ;
V_11 = F_8 ( V_14 ) ;
F_9 ( L_2 ,
F_10 ( V_10 >> 8 ) & 0xf , F_10 ( V_10 & 0xf ) ,
( ( V_11 >> 12 ) & 0xf ) + 2000 ,
( V_11 >> 8 ) & 0xf , F_10 ( V_11 & 0xff ) ) ;
}
