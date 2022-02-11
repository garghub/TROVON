static void F_1 ( void * V_1 , void * V_2 )
{
F_2 ( L_1 , F_3 ( ( unsigned long * ) V_1 ) ,
F_3 ( ( unsigned long * ) V_2 ) ) ;
}
void T_1 F_4 ( void )
{
bool V_3 = F_5 ( V_4 ) ;
V_5 = V_3 ? F_1 : NULL ;
}
void T_1 F_6 ( void )
{
unsigned long V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 . V_9 ; V_7 ++ ) {
if ( V_8 . V_10 [ V_7 ] . type != V_11 )
continue;
V_6 = V_8 . V_10 [ V_7 ] . V_6 ;
F_2 ( L_2 ,
V_6 , V_6 + V_8 . V_10 [ V_7 ] . V_12 ) ;
}
}
T_2 F_7 ( void )
{
return 0x1fc10000 ;
}
