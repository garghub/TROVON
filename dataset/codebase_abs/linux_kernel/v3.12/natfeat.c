long F_1 ( const char * V_1 )
{
char V_2 [ 32 ] ;
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_1 , sizeof( V_2 ) ) ;
if ( V_3 >= sizeof( V_2 ) )
return 0 ;
return F_3 ( F_4 ( V_2 ) ) ;
}
void F_5 ( const char * V_4 , ... )
{
static char V_5 [ 256 ] ;
T_2 V_6 ;
int V_3 ;
va_start ( V_6 , V_4 ) ;
V_3 = vsnprintf ( V_5 , 256 , V_4 , V_6 ) ;
F_6 ( F_1 ( L_1 ) , F_4 ( V_5 ) ) ;
va_end ( V_6 ) ;
}
static void F_7 ( void )
{
long V_7 = F_1 ( L_2 ) ;
if ( V_7 )
F_6 ( V_7 ) ;
}
void F_8 ( void )
{
unsigned long V_7 , V_8 ;
char V_5 [ 256 ] ;
V_7 = F_1 ( L_3 ) ;
if ( ! V_7 )
return;
V_8 = F_6 ( V_7 ) ;
V_7 = F_1 ( L_4 ) ;
if ( ! V_7 )
return;
F_6 ( V_7 , F_4 ( V_5 ) , 256 ) ;
V_5 [ 255 ] = 0 ;
F_9 ( L_5 , V_5 , V_8 >> 16 ,
V_8 & 0xffff ) ;
V_9 = F_7 ;
}
