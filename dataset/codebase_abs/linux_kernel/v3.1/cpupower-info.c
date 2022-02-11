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
} V_12 = {} ;
int V_13 = 0 ;
setlocale ( V_14 , L_2 ) ;
F_3 ( V_15 ) ;
while ( ( V_13 = F_4 ( V_2 , V_3 , L_3 , V_16 , NULL ) ) != - 1 ) {
switch ( V_13 ) {
case 'b' :
if ( V_12 . V_11 )
F_1 () ;
V_12 . V_11 = 1 ;
break;
case 'm' :
if ( V_12 . V_9 )
F_1 () ;
V_12 . V_9 = 1 ;
break;
case 's' :
if ( V_12 . V_10 )
F_1 () ;
V_12 . V_10 = 1 ;
break;
default:
F_1 () ;
}
} ;
if ( ! V_12 . V_12 )
V_12 . V_12 = 0x7 ;
if ( F_5 ( V_17 ) )
F_6 ( V_17 , 0 ) ;
if ( V_12 . V_9 ) {
V_13 = F_7 ( L_4 ) ;
printf ( _ ( L_5 ) ) ;
if ( V_13 < 0 )
printf ( _ ( L_6 ) ) ;
else
printf ( L_7 , V_13 ) ;
}
if ( V_12 . V_10 ) {
V_13 = F_7 ( L_8 ) ;
printf ( _ ( L_9 ) ) ;
if ( V_13 < 0 )
printf ( _ ( L_6 ) ) ;
else
printf ( L_7 , V_13 ) ;
}
if ( ! V_12 . V_11 )
return V_13 ;
if ( V_12 . V_11 ) {
if ( ! V_18 ) {
V_12 . V_11 = 0 ;
printf ( _ ( L_10 ) ) ;
} else if ( ! ( V_19 . V_20 & V_21 ) ) {
printf ( _ ( L_11
L_12 ) ) ;
V_12 . V_11 = 0 ;
}
}
for ( V_8 = F_8 ( V_17 ) ;
V_8 <= F_9 ( V_17 ) ; V_8 ++ ) {
if ( ! F_10 ( V_17 , V_8 ) ||
F_11 ( V_8 ) )
continue;
printf ( _ ( L_13 ) , V_8 ) ;
if ( V_12 . V_11 ) {
V_13 = F_12 ( V_8 ) ;
if ( V_13 < 0 ) {
printf ( _ ( L_14 ) ) ;
break;
} else
printf ( _ ( L_15 ) , V_13 ) ;
}
}
return V_13 ;
}
