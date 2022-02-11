static void F_1 ( void )
{
printf ( L_1 , V_1 ) ;
}
static int F_2 ( int V_2 , char * V_3 [] )
{
const struct V_4 * V_5 ;
int V_6 ;
int V_7 = 0 ;
if ( V_2 > 1 && V_3 ++ ) {
for ( V_6 = 0 ; V_8 [ V_6 ] . V_9 != NULL ; V_6 ++ )
if ( ! strcmp ( V_8 [ V_6 ] . V_9 , V_3 [ 0 ] ) && V_8 [ V_6 ] . V_10 ) {
V_8 [ V_6 ] . V_10 () ;
goto V_11;
}
V_7 = - 1 ;
}
F_1 () ;
printf ( L_2 ) ;
for ( V_5 = V_8 ; V_5 -> V_9 != NULL ; V_5 ++ )
if ( V_5 -> V_12 != NULL )
printf ( L_3 , V_5 -> V_9 , V_5 -> V_12 ) ;
printf ( L_2 ) ;
V_11:
return V_7 ;
}
static int F_3 ( int V_2 , char * V_3 [] )
{
( void ) V_2 ;
( void ) V_3 ;
printf ( V_13 L_4 , V_14 ) ;
return 0 ;
}
static int F_4 ( const struct V_4 * V_5 , int V_2 , char * V_3 [] )
{
F_5 ( L_5 , V_5 -> V_9 ) ;
return V_5 -> V_15 ( V_2 , V_3 ) ;
}
int main ( int V_2 , char * V_3 [] )
{
static const struct V_16 V_17 [] = {
{ L_6 , V_18 , NULL , 'd' } ,
{ L_7 , V_18 , NULL , 'l' } ,
{ L_8 , V_19 , NULL , 't' } ,
{ NULL , 0 , NULL , 0 }
} ;
char * V_5 ;
int V_20 ;
int V_6 , V_21 = - 1 ;
V_22 = 1 ;
V_23 = 0 ;
for (; ; ) {
V_20 = F_6 ( V_2 , V_3 , L_9 , V_17 , NULL ) ;
if ( V_20 == - 1 )
break;
switch ( V_20 ) {
case 'd' :
V_24 = 1 ;
break;
case 'l' :
V_25 = 1 ;
F_7 ( L_10 , V_26 , V_27 ) ;
break;
case 't' :
F_8 ( V_28 ) ;
break;
case '?' :
printf ( L_11 ) ;
default:
F_1 () ;
goto V_29;
}
}
V_5 = V_3 [ V_30 ] ;
if ( V_5 ) {
for ( V_6 = 0 ; V_8 [ V_6 ] . V_9 != NULL ; V_6 ++ )
if ( ! strcmp ( V_8 [ V_6 ] . V_9 , V_5 ) ) {
V_2 -= V_30 ;
V_3 += V_30 ;
V_30 = 0 ;
V_21 = F_4 ( & V_8 [ V_6 ] , V_2 , V_3 ) ;
goto V_29;
}
}
F_2 ( 0 , NULL ) ;
V_29:
return ( V_21 > - 1 ? V_31 : V_32 ) ;
}
