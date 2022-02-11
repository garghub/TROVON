static void F_1 ( unsigned int V_1 , int V_2 )
{
unsigned int V_3 , V_4 ;
char * V_5 ;
printf ( _ ( L_1 ) , V_1 ) ;
V_3 = F_2 ( V_1 ) ;
if ( V_3 == 0 ) {
printf ( _ ( L_2 ) , V_1 ) ;
return;
}
printf ( _ ( L_3 ) , V_3 ) ;
printf ( _ ( L_4 ) ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_5 = F_3 ( V_1 , V_4 ) ;
if ( ! V_5 )
continue;
printf ( L_5 , V_5 ) ;
free ( V_5 ) ;
}
printf ( L_6 ) ;
if ( ! V_2 )
return;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
int V_6 = F_4 ( V_1 , V_4 ) ;
if ( V_6 < 0 )
V_6 = 0 ;
V_5 = F_3 ( V_1 , V_4 ) ;
if ( ! V_5 )
continue;
printf ( L_7 , V_5 , ( V_6 ) ? L_8 : L_9 ) ;
free ( V_5 ) ;
V_5 = F_5 ( V_1 , V_4 ) ;
if ( ! V_5 )
continue;
printf ( _ ( L_10 ) , V_5 ) ;
free ( V_5 ) ;
printf ( _ ( L_11 ) ,
F_6 ( V_1 , V_4 ) ) ;
printf ( _ ( L_12 ) ,
F_7 ( V_1 , V_4 ) ) ;
printf ( _ ( L_13 ) ,
F_8 ( V_1 , V_4 ) ) ;
}
printf ( L_6 ) ;
}
static void F_9 ( void )
{
char * V_5 ;
V_5 = F_10 () ;
if ( ! V_5 ) {
printf ( _ ( L_14 ) ) ;
return;
}
printf ( _ ( L_15 ) , V_5 ) ;
free ( V_5 ) ;
V_5 = F_11 () ;
if ( ! V_5 ) {
printf ( _ ( L_16 ) ) ;
return;
}
printf ( _ ( L_17 ) , V_5 ) ;
free ( V_5 ) ;
}
static void F_12 ( unsigned int V_1 )
{
long V_7 = 2000000000 ;
unsigned int V_8 , V_9 ;
V_9 = F_2 ( V_1 ) ;
if ( V_9 == 0 ) {
printf ( _ ( L_18 ) , V_1 ) ;
return;
}
printf ( _ ( L_19 ) ) ;
printf ( _ ( L_20 ) , V_9 - 1 ) ;
printf ( _ ( L_21 ) , V_7 ) ;
printf ( _ ( L_22 ) ) ;
for ( V_8 = 1 ; V_8 < V_9 ; V_8 ++ ) {
printf ( _ ( L_23
L_24 ) , V_8 , V_8 ) ;
printf ( _ ( L_25 ) ) ;
printf ( _ ( L_26 ) ,
F_6 ( V_1 , V_8 ) ) ;
printf ( _ ( L_27 ) ,
F_7 ( V_1 , V_8 ) ) ;
printf ( _ ( L_28 ) ,
F_8 ( V_1 , V_8 ) ) ;
}
}
static inline void F_13 ( int V_10 )
{
exit ( V_11 ) ;
}
int F_14 ( int V_12 , char * * V_13 )
{
extern char * V_14 ;
extern int V_15 , V_16 , V_17 ;
int V_18 = 0 , V_19 = 1 , V_20 = 0 , V_2 = 1 ;
unsigned int V_1 = 0 ;
do {
V_18 = F_15 ( V_12 , V_13 , L_29 , V_21 , NULL ) ;
if ( V_18 == - 1 )
break;
switch ( V_18 ) {
case '?' :
V_20 = '?' ;
V_19 = 0 ;
break;
case 's' :
V_2 = 0 ;
break;
case - 1 :
V_19 = 0 ;
break;
case 'o' :
if ( V_20 ) {
V_20 = - 1 ;
V_19 = 0 ;
break;
}
V_20 = V_18 ;
break;
}
} while ( V_19 );
switch ( V_20 ) {
case - 1 :
printf ( _ ( L_30
L_31 ) ) ;
F_13 ( V_11 ) ;
case '?' :
printf ( _ ( L_32 ) ) ;
F_13 ( V_11 ) ;
}
if ( F_16 ( V_22 ) )
F_17 ( V_22 , 0 ) ;
if ( V_20 == 0 )
F_9 () ;
for ( V_1 = F_18 ( V_22 ) ;
V_1 <= F_19 ( V_22 ) ; V_1 ++ ) {
if ( ! F_20 ( V_22 , V_1 ) ||
F_21 ( V_1 ) )
continue;
switch ( V_20 ) {
case 'o' :
F_12 ( V_1 ) ;
break;
case 0 :
printf ( L_6 ) ;
F_1 ( V_1 , V_2 ) ;
break;
}
}
return V_23 ;
}
