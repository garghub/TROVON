void F_1 ( const char * V_1 , ... )
{
static char V_2 [ 256 ] ;
T_1 V_3 ;
int V_4 ;
va_start ( V_3 , V_1 ) ;
V_4 = vsnprintf ( V_2 , 256 , V_1 , V_3 ) ;
F_2 ( F_3 ( L_1 ) , V_2 ) ;
va_end ( V_3 ) ;
}
static void F_4 ( void )
{
long V_5 = F_3 ( L_2 ) ;
if ( V_5 )
F_2 ( V_5 ) ;
}
void F_5 ( void )
{
unsigned long V_5 , V_6 ;
char V_2 [ 256 ] ;
V_5 = F_3 ( L_3 ) ;
if ( ! V_5 )
return;
V_6 = F_2 ( V_5 ) ;
V_5 = F_3 ( L_4 ) ;
if ( ! V_5 )
return;
F_2 ( V_5 , V_2 , 256 ) ;
V_2 [ 255 ] = 0 ;
F_6 ( L_5 , V_2 , V_6 >> 16 ,
V_6 & 0xffff ) ;
V_7 = F_4 ;
}
