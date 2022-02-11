int F_1 ( const char * V_1 , int V_2 )
{
int V_3 = ( V_1 == NULL ) ;
char V_4 [ 200 ] ;
if ( V_1 == NULL )
V_1 = F_2 ( V_4 , sizeof V_4 ) ;
#ifndef F_3
else if ( F_4 ( V_1 ) > 0 ) {
V_5 = 1 ;
return 1 ;
}
#endif
if ( V_1 == NULL || ! F_5 ( V_1 , - 1 ) ) {
if ( F_6 () == 0 ) {
if ( ! V_2 ) {
F_7 ( V_6 , L_1 ) ;
F_7 ( V_6 ,
L_2 ) ;
F_7 ( V_6 , L_3 ) ;
if ( V_3 ) {
F_7 ( V_6 ,
L_4 ) ;
F_7 ( V_6 ,
L_5 ) ;
}
}
return 0 ;
}
}
V_7 = 1 ;
return 1 ;
}
long F_8 ( char * V_8 )
{
char * V_9 , * V_10 ;
int V_11 ;
long V_12 = 0 ;
#ifndef F_3
int V_13 ;
#endif
for (; ; ) {
V_11 = 0 ;
for ( V_9 = V_8 ; ( ( * V_9 != '\0' ) && ( * V_9 != V_14 ) ) ; V_9 ++ ) ;
if ( * V_9 == '\0' )
V_11 = 1 ;
* V_9 = '\0' ;
V_10 = V_8 ;
V_8 = V_9 + 1 ;
if ( * V_10 == '\0' )
break;
#ifndef F_3
V_13 = F_4 ( V_10 ) ;
if ( V_13 > 0 )
V_12 += V_13 ;
else
#endif
V_12 += F_5 ( V_10 , - 1 ) ;
if ( V_11 )
break;
}
if ( V_12 > 512 )
F_9 () ;
return ( V_12 ) ;
}
int F_10 ( const char * V_1 )
{
char V_4 [ 200 ] ;
if ( V_5 || ! V_7 )
return 0 ;
if ( V_1 == NULL )
V_1 = F_2 ( V_4 , sizeof V_4 ) ;
if ( V_1 == NULL || ! F_11 ( V_1 ) ) {
F_7 ( V_6 , L_6 ) ;
return 0 ;
}
return 1 ;
}
void F_9 ( void )
{
V_7 = 1 ;
}
