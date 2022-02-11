const T_1 * F_1 ( void )
{
void T_2 * V_1 = F_2 ( V_2 ) ;
int V_3 = 0x400 ;
T_3 V_4 ;
static int V_5 = 0 ;
if ( V_5 )
return V_6 ;
F_3 ( & V_7 ) ;
F_4 ( V_8 , V_1 ) ;
while ( ( F_5 ( V_1 ) &
( V_9 | V_8 ) ) && -- V_3 )
F_6 () ;
if ( F_7 ( ! V_3 ) )
goto V_10;
F_8 ( V_11 , V_1 ) ;
F_9 ( 1 ) ;
V_3 = 0x400 ;
while ( ( F_5 ( V_1 ) & V_9 ) && -- V_3 )
F_6 () ;
if ( F_7 ( ! V_3 ) )
goto V_10;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ )
V_6 [ V_4 ] = F_5 ( V_1 + V_13 +
V_4 * 0x10 ) ;
F_4 ( V_11 , V_1 ) ;
V_5 = 1 ;
F_10 ( & V_7 ) ;
return V_6 ;
V_10:
F_10 ( & V_7 ) ;
F_11 ( L_1 , V_14 ) ;
return NULL ;
}
