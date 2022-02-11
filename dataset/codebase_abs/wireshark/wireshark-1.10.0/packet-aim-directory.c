static int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_4 = 0 ;
while ( F_2 ( V_1 , V_4 ) > 0 ) {
V_4 = F_3 ( V_1 , V_2 , V_4 , V_3 , V_5 ) ;
}
return V_4 ;
}
void
F_4 ( void )
{
static T_4 * V_6 [] = {
& V_7
} ;
V_8 = F_5 ( L_1 , L_2 , L_3 ) ;
F_6 ( V_6 , F_7 ( V_6 ) ) ;
}
void
F_8 ( void )
{
F_9 ( V_8 , V_7 , V_9 , V_10 ) ;
}
