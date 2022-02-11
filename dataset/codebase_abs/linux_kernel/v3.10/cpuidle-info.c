static void F_1 ( unsigned int V_1 , int V_2 )
{
int V_3 , V_4 ;
char * V_5 ;
printf ( _ ( L_1 ) , V_1 ) ;
V_3 = F_2 ( V_1 ) ;
if ( V_3 == 0 ) {
printf ( _ ( L_2 ) , V_1 ) ;
return;
} else if ( V_3 <= 0 ) {
printf ( _ ( L_3 ) , V_1 ) ;
return;
}
printf ( _ ( L_4 ) , V_3 ) ;
printf ( _ ( L_5 ) ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_5 = F_3 ( V_1 , V_4 ) ;
if ( ! V_5 )
continue;
printf ( L_6 , V_5 ) ;
free ( V_5 ) ;
}
printf ( L_7 ) ;
if ( ! V_2 )
return;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_5 = F_3 ( V_1 , V_4 ) ;
if ( ! V_5 )
continue;
printf ( L_8 , V_5 ) ;
free ( V_5 ) ;
V_5 = F_4 ( V_1 , V_4 ) ;
if ( ! V_5 )
continue;
printf ( _ ( L_9 ) , V_5 ) ;
free ( V_5 ) ;
printf ( _ ( L_10 ) ,
F_5 ( V_1 , V_4 ) ) ;
printf ( _ ( L_11 ) ,
F_6 ( V_1 , V_4 ) ) ;
printf ( _ ( L_12 ) ,
F_7 ( V_1 , V_4 ) ) ;
}
printf ( L_7 ) ;
}
static void F_8 ( void )
{
char * V_5 ;
V_5 = F_9 () ;
if ( ! V_5 ) {
printf ( _ ( L_13 ) ) ;
return;
}
printf ( _ ( L_14 ) , V_5 ) ;
free ( V_5 ) ;
V_5 = F_10 () ;
if ( ! V_5 ) {
printf ( _ ( L_15 ) ) ;
return;
}
printf ( _ ( L_16 ) , V_5 ) ;
free ( V_5 ) ;
}
static void F_11 ( unsigned int V_1 )
{
long V_6 = 2000000000 ;
int V_7 , V_8 ;
V_7 = F_2 ( V_1 ) ;
if ( V_7 == 0 ) {
} else if ( V_7 <= 0 ) {
printf ( _ ( L_17 ) , V_1 ) ;
return;
}
printf ( _ ( L_18 ) ) ;
printf ( _ ( L_19 ) , V_7 - 1 ) ;
printf ( _ ( L_20 ) , V_6 ) ;
printf ( _ ( L_21 ) ) ;
for ( V_8 = 1 ; V_8 < V_7 ; V_8 ++ ) {
printf ( _ ( L_22
L_23 ) , V_8 , V_8 ) ;
printf ( _ ( L_24 ) ) ;
printf ( _ ( L_25 ) ,
F_5 ( V_1 , V_8 ) ) ;
printf ( _ ( L_26 ) ,
F_6 ( V_1 , V_8 ) ) ;
printf ( _ ( L_27 ) ,
F_7 ( V_1 , V_8 ) ) ;
}
}
static inline void F_12 ( int V_9 )
{
exit ( V_10 ) ;
}
int F_13 ( int V_11 , char * * V_12 )
{
extern char * V_13 ;
extern int V_14 , V_15 , V_16 ;
int V_17 = 0 , V_18 = 1 , V_19 = 0 , V_2 = 1 ;
unsigned int V_1 = 0 ;
do {
V_17 = F_14 ( V_11 , V_12 , L_28 , V_20 , NULL ) ;
if ( V_17 == - 1 )
break;
switch ( V_17 ) {
case '?' :
V_19 = '?' ;
V_18 = 0 ;
break;
case 's' :
V_2 = 0 ;
break;
case - 1 :
V_18 = 0 ;
break;
case 'o' :
if ( V_19 ) {
V_19 = - 1 ;
V_18 = 0 ;
break;
}
V_19 = V_17 ;
break;
}
} while ( V_18 );
switch ( V_19 ) {
case - 1 :
printf ( _ ( L_29
L_30 ) ) ;
F_12 ( V_10 ) ;
case '?' :
printf ( _ ( L_31 ) ) ;
F_12 ( V_10 ) ;
}
if ( F_15 ( V_21 ) )
F_16 ( V_21 , 0 ) ;
if ( V_19 == 0 )
F_8 () ;
for ( V_1 = F_17 ( V_21 ) ;
V_1 <= F_18 ( V_21 ) ; V_1 ++ ) {
if ( ! F_19 ( V_21 , V_1 ) ||
F_20 ( V_1 ) )
continue;
switch ( V_19 ) {
case 'o' :
F_11 ( V_1 ) ;
break;
case 0 :
printf ( L_7 ) ;
F_1 ( V_1 , V_2 ) ;
break;
}
}
return V_22 ;
}
