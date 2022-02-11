void F_1 ( void )
{
printf ( L_1 , V_1 ) ;
}
static int F_2 ( char * V_2 )
{
char V_3 [] = L_2 ;
int V_4 , V_5 = - 1 ;
char V_6 [] = L_3 ;
char V_7 [ V_8 ] ;
char V_9 [] = L_4 ;
char V_10 [ V_8 ] ;
struct V_11 * V_11 ;
struct V_12 * V_13 ;
const char * V_14 ;
V_11 = F_3 () ;
V_13 = F_4 ( V_11 , L_2 , V_2 ) ;
if ( ! V_13 ) {
F_5 ( L_5 ) ;
goto V_15;
}
V_14 = F_6 ( V_13 ) ;
if ( ! V_14 || strcmp ( V_14 , L_6 ) ) {
F_5 ( L_7 ) ;
goto V_15;
}
snprintf ( V_7 , sizeof( V_7 ) , L_8 ,
V_16 , V_17 , V_3 , V_18 ,
V_19 , V_6 ) ;
V_4 = F_7 ( V_7 , V_2 , strlen ( V_2 ) ) ;
if ( V_4 < 0 ) {
F_5 ( L_9 , V_2 ) ;
goto V_15;
}
V_4 = F_8 ( V_2 , 0 ) ;
if ( V_4 < 0 ) {
F_5 ( L_10 , V_2 ) ;
goto V_15;
}
snprintf ( V_10 , sizeof( V_7 ) , L_8 ,
V_16 , V_17 , V_3 , V_18 ,
V_19 , V_9 ) ;
V_4 = F_7 ( V_10 , V_2 , strlen ( V_2 ) ) ;
if ( V_4 < 0 ) {
F_5 ( L_11 ) ;
goto V_15;
}
V_5 = 0 ;
F_9 ( L_12 , V_2 ) ;
V_15:
F_10 ( V_13 ) ;
F_11 ( V_11 ) ;
return V_5 ;
}
int F_12 ( int V_20 , char * V_21 [] )
{
static const struct V_22 V_23 [] = {
{ L_13 , V_24 , NULL , 'b' } ,
{ NULL , 0 , NULL , 0 }
} ;
int V_25 ;
int V_5 = - 1 ;
for (; ; ) {
V_25 = F_13 ( V_20 , V_21 , L_14 , V_23 , NULL ) ;
if ( V_25 == - 1 )
break;
switch ( V_25 ) {
case 'b' :
V_5 = F_2 ( V_26 ) ;
goto V_27;
default:
goto V_28;
}
}
V_28:
F_1 () ;
V_27:
return V_5 ;
}
