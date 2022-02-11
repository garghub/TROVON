static void F_1 ( void )
{
printf ( _ ( L_1 ) ) ;
exit ( V_1 ) ;
}
int F_2 ( int V_2 , char * * V_3 )
{
extern char * V_4 ;
extern int V_5 , V_6 , V_7 ;
unsigned int V_8 ;
union {
struct {
int V_9 : 1 ;
int V_10 : 1 ;
int V_11 : 1 ;
};
int V_12 ;
} V_12 ;
int V_9 = 0 , V_10 = 0 , V_11 = 0 ;
int V_13 = 0 ;
setlocale ( V_14 , L_2 ) ;
F_3 ( V_15 ) ;
V_12 . V_12 = 0 ;
while ( ( V_13 = F_4 ( V_2 , V_3 , L_3 ,
V_16 , NULL ) ) != - 1 ) {
switch ( V_13 ) {
case 'b' :
if ( V_12 . V_11 )
F_1 () ;
V_11 = atoi ( V_4 ) ;
if ( V_11 < 0 || V_11 > 15 ) {
printf ( _ ( L_4
L_5 ) , 15 ) ;
F_1 () ;
}
V_12 . V_11 = 1 ;
break;
case 'm' :
if ( V_12 . V_9 )
F_1 () ;
V_9 = atoi ( V_4 ) ;
if ( V_9 < 0 || V_9 > 2 ) {
printf ( _ ( L_6
L_5 ) , 2 ) ;
F_1 () ;
}
V_12 . V_9 = 1 ;
break;
case 's' :
if ( V_12 . V_10 )
F_1 () ;
V_10 = atoi ( V_4 ) ;
if ( V_10 < 0 || V_10 > 2 ) {
printf ( _ ( L_7
L_5 ) , 2 ) ;
F_1 () ;
}
V_12 . V_10 = 1 ;
break;
default:
F_1 () ;
}
} ;
if ( ! V_12 . V_12 )
F_1 () ;
if ( V_12 . V_9 ) {
V_13 = F_5 ( L_8 , V_9 ) ;
if ( V_13 )
fprintf ( V_17 , _ ( L_9 ) ,
( V_13 == - V_18 ) ? L_10 : L_2 ) ;
}
if ( V_12 . V_10 ) {
V_13 = F_5 ( L_11 , V_10 ) ;
if ( V_13 )
fprintf ( V_17 , _ ( L_12 ) ,
( V_13 == - V_18 ) ? L_10 : L_2 ) ;
}
if ( F_6 ( V_19 ) )
F_7 ( V_19 ) ;
for ( V_8 = F_8 ( V_19 ) ;
V_8 <= F_9 ( V_19 ) ; V_8 ++ ) {
if ( ! F_10 ( V_19 , V_8 ) ||
F_11 ( V_8 ) )
continue;
if ( V_12 . V_11 ) {
V_13 = F_12 ( V_8 , V_11 ) ;
if ( V_13 ) {
fprintf ( V_17 , _ ( L_13
L_14 ) , V_8 ) ;
break;
}
}
}
return V_13 ;
}
