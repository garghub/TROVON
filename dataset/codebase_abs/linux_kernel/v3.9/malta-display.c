void F_1 ( const char * V_1 )
{
static unsigned int T_1 * V_2 = NULL ;
int V_3 ;
if ( F_2 ( V_2 == NULL ) )
V_2 = F_3 ( V_4 , 16 * sizeof( int ) ) ;
for ( V_3 = 0 ; V_3 <= 14 ; V_3 = V_3 + 2 ) {
if ( * V_1 )
F_4 ( * V_1 ++ , V_2 + V_3 ) ;
else
F_4 ( ' ' , V_2 + V_3 ) ;
}
}
static void F_5 ( unsigned long V_5 )
{
F_1 ( & V_6 [ V_7 ++ ] ) ;
if ( V_7 == V_8 )
V_7 = 0 ;
F_6 ( & V_9 , V_10 + V_11 ) ;
}
void F_7 ( void )
{
F_8 ( & V_9 ) ;
V_8 = strlen ( V_6 ) + 1 - 8 ;
F_6 ( & V_9 , V_10 + 1 ) ;
}
