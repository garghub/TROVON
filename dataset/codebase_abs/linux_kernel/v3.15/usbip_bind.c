void F_1 ( void )
{
printf ( L_1 , V_1 ) ;
}
static int F_2 ( char * V_2 )
{
char V_3 [] = L_2 ;
char V_4 [ V_5 ] ;
int V_6 = - 1 ;
snprintf ( V_4 , sizeof( V_4 ) , L_3 ,
V_7 , V_8 , V_9 ,
V_10 , V_11 , V_3 ) ;
V_6 = F_3 ( V_4 , V_2 , strlen ( V_2 ) ) ;
if ( V_6 < 0 ) {
F_4 ( L_4 , V_2 ,
strerror ( V_12 ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_5 ( char * V_2 )
{
enum V_13 V_14 = V_15 ;
char V_3 [] = L_5 ;
char V_16 [ V_5 ] ;
int V_6 = - 1 ;
struct V_17 * V_17 ;
struct V_18 * V_19 ;
const char * V_20 ;
const char * V_21 ;
V_17 = F_6 () ;
V_19 = F_7 ( V_17 , L_6 , V_2 ) ;
if ( ! V_19 ) {
F_8 ( L_7 , V_2 ) ;
goto V_22;
}
V_21 = F_9 ( V_19 , L_8 ) ;
if ( ! V_21 ) {
F_8 ( L_9 ) ;
goto V_22;
}
if ( ! strncmp ( V_21 , L_10 , strlen ( V_21 ) ) ) {
F_8 ( L_11 ) ;
goto V_22;
}
V_20 = F_10 ( V_19 ) ;
if ( ! V_20 ) {
goto V_23;
}
if ( ! strncmp ( V_11 , V_20 ,
strlen ( V_11 ) ) ) {
V_14 = V_24 ;
goto V_23;
}
snprintf ( V_16 , sizeof( V_16 ) , L_3 ,
V_7 , V_8 , V_9 ,
V_10 , V_20 , V_3 ) ;
V_6 = F_3 ( V_16 , V_2 , strlen ( V_2 ) ) ;
if ( V_6 < 0 ) {
F_4 ( L_12 , V_2 ) ;
goto V_22;
}
goto V_23;
V_22:
V_14 = V_25 ;
V_23:
F_11 ( V_19 ) ;
F_12 ( V_17 ) ;
return V_14 ;
}
static int F_13 ( char * V_2 )
{
int V_6 ;
struct V_17 * V_17 ;
struct V_18 * V_19 ;
V_17 = F_6 () ;
V_19 = F_7 ( V_17 , L_6 , V_2 ) ;
if ( ! V_19 ) {
F_4 ( L_13 ) ;
return - 1 ;
}
F_12 ( V_17 ) ;
V_6 = F_5 ( V_2 ) ;
if ( V_6 == V_25 ) {
F_4 ( L_14 , V_2 ) ;
return - 1 ;
} else if ( V_6 == V_24 ) {
F_4 ( L_15 , V_2 ,
V_11 ) ;
return - 1 ;
}
V_6 = F_14 ( V_2 , 1 ) ;
if ( V_6 < 0 ) {
F_4 ( L_16 , V_2 ) ;
return - 1 ;
}
V_6 = F_2 ( V_2 ) ;
if ( V_6 < 0 ) {
F_4 ( L_17 , V_11 ) ;
F_14 ( V_2 , 0 ) ;
return - 1 ;
}
F_15 ( L_18 , V_2 ) ;
return 0 ;
}
int F_16 ( int V_26 , char * V_27 [] )
{
static const struct V_28 V_29 [] = {
{ L_19 , V_30 , NULL , 'b' } ,
{ NULL , 0 , NULL , 0 }
} ;
int V_31 ;
int V_32 = - 1 ;
for (; ; ) {
V_31 = F_17 ( V_26 , V_27 , L_20 , V_29 , NULL ) ;
if ( V_31 == - 1 )
break;
switch ( V_31 ) {
case 'b' :
V_32 = F_13 ( V_33 ) ;
goto V_23;
default:
goto V_34;
}
}
V_34:
F_1 () ;
V_23:
return V_32 ;
}
