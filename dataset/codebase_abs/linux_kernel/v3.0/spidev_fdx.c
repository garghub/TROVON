static void F_1 ( int V_1 , int V_2 )
{
unsigned char V_3 [ 32 ] , * V_4 ;
int V_5 ;
if ( V_2 < 2 )
V_2 = 2 ;
else if ( V_2 > sizeof( V_3 ) )
V_2 = sizeof( V_3 ) ;
memset ( V_3 , 0 , sizeof V_3 ) ;
V_5 = F_2 ( V_1 , V_3 , V_2 ) ;
if ( V_5 < 0 ) {
perror ( L_1 ) ;
return;
}
if ( V_5 != V_2 ) {
fprintf ( V_6 , L_2 ) ;
return;
}
printf ( L_3 , V_2 , V_5 ,
V_3 [ 0 ] , V_3 [ 1 ] ) ;
V_5 -= 2 ;
V_4 = V_3 + 2 ;
while ( V_5 -- > 0 )
printf ( L_4 , * V_4 ++ ) ;
printf ( L_5 ) ;
}
static void F_3 ( int V_1 , int V_2 )
{
struct V_7 V_8 [ 2 ] ;
unsigned char V_3 [ 32 ] , * V_4 ;
int V_5 ;
memset ( V_8 , 0 , sizeof V_8 ) ;
memset ( V_3 , 0 , sizeof V_3 ) ;
if ( V_2 > sizeof V_3 )
V_2 = sizeof V_3 ;
V_3 [ 0 ] = 0xaa ;
V_8 [ 0 ] . V_9 = ( unsigned long ) V_3 ;
V_8 [ 0 ] . V_2 = 1 ;
V_8 [ 1 ] . V_10 = ( unsigned long ) V_3 ;
V_8 [ 1 ] . V_2 = V_2 ;
V_5 = F_4 ( V_1 , F_5 ( 2 ) , V_8 ) ;
if ( V_5 < 0 ) {
perror ( L_6 ) ;
return;
}
printf ( L_7 , V_2 , V_5 ) ;
for ( V_4 = V_3 ; V_2 ; V_2 -- )
printf ( L_4 , * V_4 ++ ) ;
printf ( L_5 ) ;
}
static void F_6 ( const char * V_11 , int V_1 )
{
T_1 V_12 , V_13 , V_14 ;
T_2 V_15 ;
if ( F_4 ( V_1 , V_16 , & V_12 ) < 0 ) {
perror ( L_8 ) ;
return;
}
if ( F_4 ( V_1 , V_17 , & V_13 ) < 0 ) {
perror ( L_9 ) ;
return;
}
if ( F_4 ( V_1 , V_18 , & V_14 ) < 0 ) {
perror ( L_10 ) ;
return;
}
if ( F_4 ( V_1 , V_19 , & V_15 ) < 0 ) {
perror ( L_11 ) ;
return;
}
printf ( L_12 ,
V_11 , V_12 , V_14 , V_13 ? L_13 : L_14 , V_15 ) ;
}
int main ( int V_20 , char * * V_21 )
{
int V_22 ;
int V_23 = 0 ;
int V_24 = 0 ;
int V_1 ;
const char * V_11 ;
while ( ( V_22 = F_7 ( V_20 , V_21 , L_15 ) ) != V_25 ) {
switch ( V_22 ) {
case 'm' :
V_24 = atoi ( V_26 ) ;
if ( V_24 < 0 )
goto V_27;
continue;
case 'r' :
V_23 = atoi ( V_26 ) ;
if ( V_23 < 0 )
goto V_27;
continue;
case 'v' :
V_28 ++ ;
continue;
case 'h' :
case '?' :
V_27:
fprintf ( V_6 ,
L_16 ,
V_21 [ 0 ] ) ;
return 1 ;
}
}
if ( ( V_29 + 1 ) != V_20 )
goto V_27;
V_11 = V_21 [ V_29 ] ;
V_1 = F_8 ( V_11 , V_30 ) ;
if ( V_1 < 0 ) {
perror ( L_17 ) ;
return 1 ;
}
F_6 ( V_11 , V_1 ) ;
if ( V_24 )
F_3 ( V_1 , V_24 ) ;
if ( V_23 )
F_1 ( V_1 , V_23 ) ;
F_9 ( V_1 ) ;
return 0 ;
}
