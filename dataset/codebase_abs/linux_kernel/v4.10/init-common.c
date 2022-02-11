static void F_1 ( void * V_1 )
{
memset ( V_1 , 0 , V_2 ) ;
}
static void F_2 ( void * V_1 )
{
memset ( V_1 , 0 , V_3 ) ;
}
static void F_3 ( void * V_1 )
{
memset ( V_1 , 0 , V_4 ) ;
}
void F_4 ( unsigned V_5 , void (* F_5)( void * ) )
{
char * V_6 ;
unsigned long V_7 = sizeof( void * ) << V_5 ;
unsigned long V_8 = V_7 ;
unsigned long V_9 = F_6 ( V_10 + 1 ,
V_11 + 1 ) ;
struct V_12 * V_13 ;
F_7 ( ! F_8 ( V_9 ) ) ;
F_7 ( ( V_5 < 1 ) || ( V_5 > V_10 ) ) ;
if ( F_9 ( V_5 ) )
return;
V_8 = F_10 (unsigned long, align, minalign) ;
V_6 = F_11 ( V_14 , L_1 , V_5 ) ;
V_13 = F_12 ( V_6 , V_7 , V_8 , 0 , F_5 ) ;
if ( ! V_13 )
F_13 ( L_2 , V_5 ) ;
F_14 ( V_6 ) ;
V_15 [ V_5 - 1 ] = V_13 ;
F_15 ( L_3 , V_5 ) ;
}
void F_16 ( void )
{
F_4 ( V_16 , F_1 ) ;
if ( V_17 && ! F_9 ( V_17 ) )
F_4 ( V_17 , F_3 ) ;
if ( V_18 && ! F_9 ( V_18 ) )
F_4 ( V_18 , F_2 ) ;
}
