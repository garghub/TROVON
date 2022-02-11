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
};
int V_10 ;
} V_10 ;
int V_9 = 0 ;
int V_11 = 0 ;
setlocale ( V_12 , L_2 ) ;
F_3 ( V_13 ) ;
V_10 . V_10 = 0 ;
while ( ( V_11 = F_4 ( V_2 , V_3 , L_3 ,
V_14 , NULL ) ) != - 1 ) {
switch ( V_11 ) {
case 'b' :
if ( V_10 . V_9 )
F_1 () ;
V_9 = atoi ( V_4 ) ;
if ( V_9 < 0 || V_9 > 15 ) {
printf ( _ ( L_4
L_5 ) , 15 ) ;
F_1 () ;
}
V_10 . V_9 = 1 ;
break;
default:
F_1 () ;
}
} ;
if ( ! V_10 . V_10 )
F_1 () ;
if ( F_5 ( V_15 ) )
F_6 ( V_15 ) ;
for ( V_8 = F_7 ( V_15 ) ;
V_8 <= F_8 ( V_15 ) ; V_8 ++ ) {
if ( ! F_9 ( V_15 , V_8 ) ||
F_10 ( V_8 ) )
continue;
if ( V_10 . V_9 ) {
V_11 = F_11 ( V_8 , V_9 ) ;
if ( V_11 ) {
fprintf ( V_16 , _ ( L_6
L_7 ) , V_8 ) ;
break;
}
}
}
return V_11 ;
}
