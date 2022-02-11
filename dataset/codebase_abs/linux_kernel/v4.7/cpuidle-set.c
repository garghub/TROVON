int F_1 ( int V_1 , char * * V_2 )
{
extern char * V_3 ;
extern int V_4 , V_5 , V_6 ;
int V_7 = 0 , V_8 = 1 , V_9 = 0 , V_10 ;
unsigned long long V_11 = 0 , V_12 ;
unsigned int V_13 = 0 , V_14 = 0 , V_15 = 0 ;
char * V_16 ;
do {
V_7 = F_2 ( V_1 , V_2 , L_1 , V_17 , NULL ) ;
if ( V_7 == - 1 )
break;
switch ( V_7 ) {
case '?' :
V_9 = '?' ;
V_8 = 0 ;
break;
case 'd' :
if ( V_9 ) {
V_9 = - 1 ;
V_8 = 0 ;
break;
}
V_9 = V_7 ;
V_14 = atoi ( V_3 ) ;
break;
case 'e' :
if ( V_9 ) {
V_9 = - 1 ;
V_8 = 0 ;
break;
}
V_9 = V_7 ;
V_14 = atoi ( V_3 ) ;
break;
case 'D' :
if ( V_9 ) {
V_9 = - 1 ;
V_8 = 0 ;
break;
}
V_9 = V_7 ;
V_11 = F_3 ( V_3 , & V_16 , 10 ) ;
if ( * V_16 != '\0' ) {
printf ( _ ( L_2 ) , V_3 ) ;
exit ( V_18 ) ;
}
break;
case 'E' :
if ( V_9 ) {
V_9 = - 1 ;
V_8 = 0 ;
break;
}
V_9 = V_7 ;
break;
case - 1 :
V_8 = 0 ;
break;
}
} while ( V_8 );
switch ( V_9 ) {
case - 1 :
printf ( _ ( L_3
L_4 ) ) ;
exit ( V_18 ) ;
case '?' :
printf ( _ ( L_5 ) ) ;
exit ( V_18 ) ;
}
if ( F_4 ( V_19 ) )
F_5 ( V_19 ) ;
for ( V_13 = F_6 ( V_19 ) ;
V_13 <= F_7 ( V_19 ) ; V_13 ++ ) {
if ( ! F_8 ( V_19 , V_13 ) )
continue;
if ( F_9 ( V_13 ) != 1 )
continue;
V_15 = F_10 ( V_13 ) ;
if ( V_15 <= 0 )
continue;
switch ( V_9 ) {
case 'd' :
V_7 = F_11 ( V_13 , V_14 , 1 ) ;
if ( V_7 == 0 )
printf ( _ ( L_6 ) , V_14 , V_13 ) ;
else if ( V_7 == - 1 )
printf ( _ ( L_7 ) ,
V_14 , V_13 ) ;
else if ( V_7 == - 2 )
printf ( _ ( L_8 ) ) ;
else
printf ( _ ( L_9 ) ,
V_14 , V_13 ) ;
break;
case 'e' :
V_7 = F_11 ( V_13 , V_14 , 0 ) ;
if ( V_7 == 0 )
printf ( _ ( L_10 ) , V_14 , V_13 ) ;
else if ( V_7 == - 1 )
printf ( _ ( L_7 ) ,
V_14 , V_13 ) ;
else if ( V_7 == - 2 )
printf ( _ ( L_11 ) ) ;
else
printf ( _ ( L_12 ) ,
V_14 , V_13 ) ;
break;
case 'D' :
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_10 = F_12
( V_13 , V_14 ) ;
V_12 = F_13
( V_13 , V_14 ) ;
if ( V_10 == 1 ) {
if ( V_11 > V_12 ) {
V_7 = F_11
( V_13 , V_14 , 0 ) ;
if ( V_7 == 0 )
printf ( _ ( L_10 ) , V_14 , V_13 ) ;
}
continue;
}
if ( V_11 <= V_12 ) {
V_7 = F_11
( V_13 , V_14 , 1 ) ;
if ( V_7 == 0 )
printf ( _ ( L_6 ) , V_14 , V_13 ) ;
}
}
break;
case 'E' :
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_10 = F_12
( V_13 , V_14 ) ;
if ( V_10 == 1 ) {
V_7 = F_11
( V_13 , V_14 , 0 ) ;
if ( V_7 == 0 )
printf ( _ ( L_10 ) , V_14 , V_13 ) ;
}
}
break;
default:
printf ( _ ( L_13 ) ) ;
exit ( V_18 ) ;
break;
}
}
return V_20 ;
}
