int main ( int V_1 , char * V_2 [] )
{
if ( ( V_1 == 1 ) )
{
F_1 () ;
}
else if ( ( V_1 == 2 ) && ! strcmp ( V_2 [ 1 ] , L_1 ) )
{
F_2 () ;
}
else
{
fprintf ( V_3 , L_2 , V_4 ) ;
exit ( 1 ) ;
}
return 0 ;
}
void F_1 ()
{
char V_5 [ V_6 ] ;
char V_7 [ V_6 + 24 ] ;
unsigned int V_8 ;
T_1 V_9 ;
F_3 ( & V_9 ) ;
while( 1 )
{
int V_10 = F_4 ( V_11 , V_5 , sizeof( V_5 ) ) ;
if ( V_10 <= 0 )
{
if ( ! V_10 )
break;
else
{
perror ( L_3 ) ;
exit ( 1 ) ;
}
}
F_5 ( & V_9 , V_7 , & V_8 , V_5 , V_10 ) ;
F_6 ( STDOUT , V_7 , V_8 ) ;
}
F_7 ( & V_9 , V_7 , & V_8 ) ;
F_6 ( STDOUT , V_7 , V_8 ) ;
}
void F_2 ()
{
char V_5 [ V_6 ] ;
char V_7 [ V_6 + 24 ] ;
unsigned int V_8 ;
T_1 V_9 ;
F_8 ( & V_9 ) ;
while( 1 )
{
int V_10 = F_4 ( V_11 , V_5 , sizeof( V_5 ) ) ;
int V_12 ;
if ( V_10 <= 0 )
{
if ( ! V_10 )
break;
else
{
perror ( L_3 ) ;
exit ( 1 ) ;
}
}
V_12 = F_9 ( & V_9 , V_7 , & V_8 , V_5 , V_10 ) ;
if ( V_12 <= 0 )
{
if ( ! V_12 )
{
F_6 ( STDOUT , V_7 , V_8 ) ;
break;
}
fprintf ( V_3 , L_4 ) ;
return;
}
F_6 ( STDOUT , V_7 , V_8 ) ;
}
F_10 ( & V_9 , V_7 , & V_8 ) ;
F_6 ( STDOUT , V_7 , V_8 ) ;
}
