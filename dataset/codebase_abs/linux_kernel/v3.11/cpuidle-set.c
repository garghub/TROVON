int F_1 ( int V_1 , char * * V_2 )
{
extern char * V_3 ;
extern int V_4 , V_5 , V_6 ;
int V_7 = 0 , V_8 = 1 , V_9 = 0 , V_10 = 0 ;
unsigned int V_11 = 0 ;
do {
V_7 = F_2 ( V_1 , V_2 , L_1 , V_12 , NULL ) ;
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
V_10 = atoi ( V_3 ) ;
break;
case 'e' :
if ( V_9 ) {
V_9 = - 1 ;
V_8 = 0 ;
break;
}
V_9 = V_7 ;
V_10 = atoi ( V_3 ) ;
break;
case - 1 :
V_8 = 0 ;
break;
}
} while ( V_8 );
switch ( V_9 ) {
case - 1 :
printf ( _ ( L_2
L_3 ) ) ;
exit ( V_13 ) ;
case '?' :
printf ( _ ( L_4 ) ) ;
exit ( V_13 ) ;
}
if ( F_3 ( V_14 ) )
F_4 ( V_14 ) ;
for ( V_11 = F_5 ( V_14 ) ;
V_11 <= F_6 ( V_14 ) ; V_11 ++ ) {
if ( ! F_7 ( V_14 , V_11 ) )
continue;
switch ( V_9 ) {
case 'd' :
V_7 = F_8 ( V_11 , V_10 , 1 ) ;
if ( V_7 == 0 )
printf ( _ ( L_5 ) , V_10 , V_11 ) ;
else if ( V_7 == - 1 )
printf ( _ ( L_6 ) ,
V_10 , V_11 ) ;
else if ( V_7 == - 2 )
printf ( _ ( L_7 ) ) ;
else
printf ( _ ( L_8 ) ,
V_10 , V_11 ) ;
break;
case 'e' :
V_7 = F_8 ( V_11 , V_10 , 0 ) ;
if ( V_7 == 0 )
printf ( _ ( L_9 ) , V_10 , V_11 ) ;
else if ( V_7 == - 1 )
printf ( _ ( L_6 ) ,
V_10 , V_11 ) ;
else if ( V_7 == - 2 )
printf ( _ ( L_10 ) ) ;
else
printf ( _ ( L_11 ) ,
V_10 , V_11 ) ;
break;
default:
printf ( _ ( L_12 ) ) ;
exit ( V_13 ) ;
break;
}
}
return V_15 ;
}
