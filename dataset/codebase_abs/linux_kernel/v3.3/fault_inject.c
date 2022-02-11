static int F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_2 == 0 )
F_2 ( V_5 L_1 , V_4 -> V_6 ) ;
else
F_2 ( V_5 L_2 , V_4 -> V_6 , V_2 ) ;
V_4 -> V_7 ( V_2 ) ;
return 0 ;
}
static int F_3 ( void * V_8 , T_1 * V_2 )
{
return 0 ;
}
void F_4 ( void )
{
F_5 ( V_9 ) ;
}
int F_6 ( void )
{
unsigned int V_10 ;
struct V_3 * V_4 ;
T_2 V_11 = V_12 | V_13 | V_14 ;
V_9 = F_7 ( L_3 , NULL ) ;
if ( ! V_9 )
goto V_15;
for ( V_10 = 0 ; V_10 < V_16 ; V_10 ++ ) {
V_4 = & V_17 [ V_10 ] ;
if ( ! F_8 ( V_4 -> V_6 , V_11 , V_9 , V_4 , & V_18 ) )
goto V_15;
}
return 0 ;
V_15:
F_4 () ;
return - V_19 ;
}
