static void F_1 ( void )
{
unsigned int V_1 ;
#ifdef F_2
printf ( _ ( L_1 ) ) ;
#else
printf ( _ ( L_2 ) ) ;
#endif
printf ( _ ( L_3 ) ) ;
for ( V_1 = 0 ; V_1 < F_3 ( V_2 ) ; V_1 ++ )
printf ( L_4 , V_2 [ V_1 ] . V_3 ) ;
printf ( _ ( L_5 ) ) ;
printf ( _ ( L_6 ) ) ;
}
static int F_4 ( const char * V_4 )
{
int V_5 ;
char * V_6 ;
V_5 = 10 ;
if ( V_4 != NULL )
V_5 += strlen ( V_4 ) ;
V_6 = malloc ( V_5 ) ;
if ( ! V_6 )
return - V_7 ;
sprintf ( V_6 , L_7 ) ;
if ( ( V_4 != NULL ) && strcmp ( V_4 , L_8 ) ) {
strcat ( V_6 , L_9 ) ;
strcat ( V_6 , V_4 ) ;
}
F_5 ( L_10 , L_10 , V_6 , NULL ) ;
return - V_8 ;
}
static int F_6 ( int V_9 , const char * * V_10 )
{
if ( V_9 > 1 ) {
F_4 ( V_10 [ 1 ] ) ;
return V_11 ;
}
F_1 () ;
return V_12 ;
}
static void F_7 ( void )
{
printf ( V_13 L_11 V_14 L_12 ) ;
printf ( _ ( L_13 ) , V_15 ) ;
}
static void F_8 ( int * V_9 , const char * * * V_10 )
{
int V_16 , V_17 , V_18 = 0 ;
if ( * V_9 < 1 )
return;
for ( V_17 = 0 ; V_17 < * V_9 && ( ( * V_10 ) [ V_17 ] ) [ 0 ] == '-' ; V_17 ++ ) {
const char * V_19 = ( * V_10 ) [ V_17 ] ;
if ( ! strcmp ( V_19 , L_14 ) || ! strcmp ( V_19 , L_15 ) ) {
F_1 () ;
exit ( V_12 ) ;
} else if ( ! strcmp ( V_19 , L_16 ) || ! strcmp ( V_19 , L_17 ) ) {
if ( * V_9 < 2 ) {
F_1 () ;
exit ( V_11 ) ;
}
if ( ! strcmp ( ( * V_10 ) [ V_17 + 1 ] , L_18 ) )
F_9 ( V_20 ) ;
else {
V_16 = F_10 (
( * V_10 ) [ V_17 + 1 ] , V_20 ) ;
if ( V_16 < 0 ) {
fprintf ( V_21 , _ ( L_19
L_20 ) ) ;
exit ( V_11 ) ;
}
}
V_17 += 1 ;
V_18 += 2 ;
continue;
} else if ( ! strcmp ( V_19 , L_21 ) ||
! strcmp ( V_19 , L_22 ) ) {
F_7 () ;
exit ( V_12 ) ;
#ifdef F_2
} else if ( ! strcmp ( V_19 , L_23 ) || ! strcmp ( V_19 , L_24 ) ) {
V_22 = 1 ;
V_18 ++ ;
continue;
#endif
} else {
fprintf ( V_21 , L_25 , V_19 ) ;
F_1 () ;
exit ( V_11 ) ;
}
}
* V_9 -= V_18 ;
* V_10 += V_18 ;
}
int main ( int V_9 , const char * V_10 [] )
{
const char * V_3 ;
unsigned int V_1 , V_16 ;
struct V_23 V_24 ;
struct V_25 V_26 ;
char V_27 [ 32 ] ;
V_20 = F_11 ( F_12 ( V_28 ) ) ;
V_9 -- ;
V_10 += 1 ;
F_8 ( & V_9 , & V_10 ) ;
V_3 = V_10 [ 0 ] ;
if ( V_9 < 1 ) {
F_1 () ;
return V_11 ;
}
setlocale ( V_29 , L_26 ) ;
F_13 ( V_13 ) ;
if ( V_9 > 1 && ! strcmp ( V_10 [ 1 ] , L_15 ) ) {
V_10 [ 1 ] = V_10 [ 0 ] ;
V_10 [ 0 ] = V_3 = L_8 ;
}
V_30 = F_14 () ;
if ( V_30 < 0 ) {
fprintf ( V_21 , _ ( L_27 ) ) ;
return V_11 ;
}
F_15 ( & V_31 ) ;
V_32 = ! F_16 () ;
if ( V_32 ) {
V_16 = F_17 ( & V_26 ) ;
sprintf ( V_27 , L_28 , V_30 ) ;
if ( ! V_16 && ! strcmp ( V_26 . V_33 , L_29 ) &&
V_23 ( V_27 , & V_24 ) != 0 ) {
if ( system ( L_30 ) == - 1 )
fprintf ( V_21 , _ ( L_31 ) ) ;
}
}
for ( V_1 = 0 ; V_1 < F_3 ( V_2 ) ; V_1 ++ ) {
struct V_34 * V_35 = V_2 + V_1 ;
if ( strcmp ( V_35 -> V_3 , V_3 ) )
continue;
if ( ! V_32 && V_35 -> V_36 ) {
fprintf ( V_21 , _ ( L_32
L_33 ) , V_3 ) ;
return V_11 ;
}
V_16 = V_35 -> main( V_9 , V_10 ) ;
if ( V_20 )
F_18 ( V_20 ) ;
return V_16 ;
}
F_1 () ;
return V_11 ;
}
