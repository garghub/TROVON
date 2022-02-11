int F_1 ( const char * V_1 , T_1 * V_2 , int V_3 )
{
int V_4 = ( V_1 == NULL ) ;
char V_5 [ 200 ] ;
#ifdef F_2
F_3 ( V_2 , L_1 ) ;
F_4 ( V_2 ) ;
F_5 () ;
F_3 ( V_2 , L_2 ) ;
#endif
if ( V_1 == NULL )
V_1 = F_6 ( V_5 , sizeof V_5 ) ;
else if ( F_7 ( V_1 ) > 0 )
{
V_6 = 1 ;
return 1 ;
}
if ( V_1 == NULL || ! F_8 ( V_1 , - 1 ) )
{
if ( F_9 () == 0 && ! V_3 )
{
F_3 ( V_2 , L_3 ) ;
F_3 ( V_2 , L_4 ) ;
F_3 ( V_2 , L_5 ) ;
if ( V_4 )
{
F_3 ( V_2 , L_6 ) ;
F_3 ( V_2 , L_7 ) ;
}
}
return 0 ;
}
V_7 = 1 ;
return 1 ;
}
long F_10 ( char * V_8 )
{
char * V_9 , * V_10 ;
int V_11 ;
long V_12 = 0 ;
int V_13 ;
for (; ; )
{
V_11 = 0 ;
for ( V_9 = V_8 ; ( ( * V_9 != '\0' ) && ( * V_9 != V_14 ) ) ; V_9 ++ ) ;
if ( * V_9 == '\0' ) V_11 = 1 ;
* V_9 = '\0' ;
V_10 = V_8 ;
V_8 = V_9 + 1 ;
if ( * V_10 == '\0' ) break;
V_13 = F_7 ( V_10 ) ;
if ( V_13 > 0 ) V_12 += V_13 ;
V_12 += F_8 ( V_10 , - 1 ) ;
if ( V_11 ) break;
}
if ( V_12 > 512 )
F_11 () ;
return ( V_12 ) ;
}
int F_12 ( const char * V_1 , T_1 * V_2 )
{
char V_5 [ 200 ] ;
if ( V_6 || ! V_7 )
return 0 ;
if ( V_1 == NULL )
V_1 = F_6 ( V_5 , sizeof V_5 ) ;
if ( V_1 == NULL || ! F_13 ( V_1 ) )
{
F_3 ( V_2 , L_8 ) ;
return 0 ;
}
return 1 ;
}
void F_11 ( void )
{
V_7 = 1 ;
}
