static void F_1 ( const char * V_1 , const char * V_2 )
{
snprintf ( V_3 , sizeof( V_3 ) , L_1 , V_2 ) ;
snprintf ( V_4 , sizeof( V_4 ) , L_2 ,
V_2 , V_1 ) ;
snprintf ( V_5 , sizeof( V_5 ) , L_3 ,
V_2 , V_1 , L_4 ) ;
}
static const char * F_2 ( void )
{
const char * V_6 ;
V_6 = F_3 () ;
if ( ! V_6 )
return NULL ;
F_1 ( L_5 , V_6 ) ;
return V_6 ;
}
static const char * F_4 ( void )
{
const char * V_6 ;
V_6 = F_5 () ;
if ( ! V_6 )
return NULL ;
F_1 ( L_6 , V_6 ) ;
return V_6 ;
}
const char * F_6 ( void )
{
const char * V_6 ;
V_6 = F_2 () ;
if ( V_6 )
return V_6 ;
V_6 = F_4 () ;
return V_6 ;
}
void F_7 ( const char * V_7 )
{
F_1 ( L_6 , V_7 ) ;
}
char * F_8 ( const char * V_8 )
{
char * V_9 ;
if ( F_9 ( & V_9 , L_2 , V_4 , V_8 ) < 0 )
return NULL ;
return V_9 ;
}
void F_10 ( char * V_9 )
{
free ( V_9 ) ;
}
int F_11 ( int V_10 , char * V_11 , T_1 V_12 ,
const char * V_13 , const char * V_8 )
{
char V_14 [ 128 ] ;
char V_15 [ V_16 ] ;
snprintf ( V_15 , V_16 , L_2 , V_13 , V_8 ? : L_7 ) ;
switch ( V_10 ) {
case V_17 :
if ( F_12 () || F_13 () ) {
if ( ! strncmp ( V_15 , L_8 , 4 ) ) {
snprintf ( V_11 , V_12 ,
L_9
L_10
L_11 ,
V_5 , V_15 , V_13 , V_8 ) ;
} else {
snprintf ( V_11 , V_12 ,
L_9
L_12 ,
V_5 , V_15 ) ;
}
break;
}
snprintf ( V_11 , V_12 , L_1 ,
L_13
L_14
L_15
L_16 ) ;
break;
case V_18 : {
snprintf ( V_11 , V_12 ,
L_17
L_18 ,
V_5 , V_15 , V_3 ) ;
}
break;
default:
snprintf ( V_11 , V_12 , L_1 , F_14 ( V_10 , V_14 , sizeof( V_14 ) ) ) ;
break;
}
return 0 ;
}
