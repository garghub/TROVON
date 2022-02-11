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
} V_10 = {} ;
int V_11 = 0 ;
setlocale ( V_12 , L_2 ) ;
F_3 ( V_13 ) ;
while ( ( V_11 = F_4 ( V_2 , V_3 , L_3 , V_14 , NULL ) ) != - 1 ) {
switch ( V_11 ) {
case 'b' :
if ( V_10 . V_9 )
F_1 () ;
V_10 . V_9 = 1 ;
break;
default:
F_1 () ;
}
} ;
if ( ! V_10 . V_10 )
V_10 . V_10 = 0x7 ;
if ( F_5 ( V_15 ) )
F_6 ( V_15 , 0 ) ;
if ( ! V_10 . V_9 )
return V_11 ;
if ( V_10 . V_9 ) {
if ( ! V_16 ) {
V_10 . V_9 = 0 ;
printf ( _ ( L_4 ) ) ;
} else if ( ! ( V_17 . V_18 & V_19 ) ) {
printf ( _ ( L_5
L_6 ) ) ;
V_10 . V_9 = 0 ;
}
}
for ( V_8 = F_7 ( V_15 ) ;
V_8 <= F_8 ( V_15 ) ; V_8 ++ ) {
if ( ! F_9 ( V_15 , V_8 ) )
continue;
printf ( _ ( L_7 ) , V_8 ) ;
if ( F_10 ( V_8 ) != 1 ) {
printf ( _ ( L_8 ) ) ;
continue;
}
if ( V_10 . V_9 ) {
V_11 = F_11 ( V_8 ) ;
if ( V_11 < 0 ) {
fprintf ( V_20 ,
_ ( L_9 ) , V_11 ) ;
exit ( V_1 ) ;
} else
printf ( _ ( L_10 ) , V_11 ) ;
}
}
return 0 ;
}
