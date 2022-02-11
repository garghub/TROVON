static void F_1 ( char * V_1 , T_1 V_2 )
{
char * V_3 ;
T_2 V_4 ;
snprintf ( V_1 , V_2 , L_1 , ( int ) F_2 () ) ;
V_1 [ V_2 - 1 ] = 0 ;
V_3 = F_3 ( V_1 ) ;
assert ( V_3 ) ;
V_4 = F_4 ( V_3 , V_1 , V_2 ) ;
V_1 [ V_4 ] = 0 ;
free ( V_3 ) ;
}
static void F_5 ( T_3 * V_5 , T_1 V_4 , int V_6 )
{
int V_7 , V_8 , V_9 = 0 ;
char V_1 [ 256 ] ;
struct V_10 V_11 ;
T_4 V_12 ;
T_5 * V_13 ;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
F_1 ( V_1 , sizeof( V_1 ) ) ;
V_13 = F_6 ( V_1 , NULL ) ;
assert ( V_13 ) ;
assert ( F_7 ( V_13 , V_14 ) ) ;
F_8 ( & V_11 , stdout , ( V_15 ) fprintf ) ;
V_11 . V_16 = F_9 ( V_13 ) ;
V_11 . V_17 = F_10 ( V_13 ) ;
V_11 . V_18 = V_5 ;
V_11 . V_19 = V_4 ;
F_11 ( & V_11 ) ;
V_12 = F_12 ( V_13 ) ;
assert ( V_12 ) ;
do {
printf ( L_2 , V_9 ) ;
V_7 = V_12 ( V_9 , & V_11 ) ;
if ( V_6 ) {
printf ( L_3 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; ++ V_8 )
printf ( L_4 , ( T_3 ) V_5 [ V_9 + V_8 ] ) ;
}
printf ( L_5 ) ;
V_9 += V_7 ;
} while( V_7 > 0 && V_9 < V_4 );
F_13 ( V_13 ) ;
}
static char * F_14 ( int * V_20 )
{
int V_21 , V_4 = F_15 ( 10 , NULL , 0 ) ;
char * V_22 = malloc ( V_4 ) ;
assert ( V_22 && V_20 ) ;
V_21 = F_15 ( 3 , V_22 , V_4 ) ;
assert ( V_21 >= 0 ) ;
* V_20 = V_21 ;
return V_22 ;
}
static void F_16 ( char * V_22 )
{
free ( V_22 ) ;
}
static int F_17 ( char * V_23 , T_1 V_24 ,
T_3 * V_5 , T_1 V_25 )
{
char * V_26 , * V_27 , * V_28 ;
T_6 V_29 = 0 ;
int V_21 , V_30 , V_31 , V_32 , V_33 = 0 ;
T_7 V_34 [ 1 ] ;
unsigned long V_35 ;
T_8 V_36 ;
if ( V_24 == 0 )
return 0 ;
V_21 = regcomp ( & V_36 , L_6
L_7 , V_37 ) ;
assert ( V_21 == 0 ) ;
V_26 = V_23 ;
while ( 1 ) {
V_21 = regexec ( & V_36 , V_26 , 1 , V_34 , 0 ) ;
if ( V_21 == 0 ) {
V_26 += V_34 [ 0 ] . V_38 ;
V_29 += V_34 [ 0 ] . V_38 ;
assert ( V_29 < V_24 ) ;
} else
break;
}
V_26 = V_23 + V_29 - ( V_34 [ 0 ] . V_38 - V_34 [ 0 ] . V_39 ) ;
V_21 = sscanf ( V_26 , L_8 ,
& V_30 , & V_31 , & V_32 , & V_35 ) ;
if ( V_21 != 4 )
return 0 ;
V_28 = V_26 = V_23 + V_29 ;
while ( ( V_26 = strtok ( V_28 , L_5 ) ) != NULL && V_33 < V_25 ) {
V_28 = NULL ;
if ( ! strstr ( V_26 , L_9 ) )
continue;
V_27 = V_26 ;
while ( ( V_26 = strstr ( V_27 , L_10 ) ) )
V_27 = V_26 + 1 ;
V_26 = V_27 ;
do {
V_5 [ V_33 ++ ] = ( T_3 ) strtoul ( V_27 , & V_27 , 16 ) ;
if ( V_26 == V_27 || V_33 >= V_25 ) {
V_33 -- ;
break;
}
V_26 = V_27 ;
} while ( 1 );
}
assert ( V_33 == V_31 ) ;
printf ( L_11 ,
V_31 , V_32 , V_30 ) ;
printf ( L_12 , V_35 ) ;
regfree ( & V_36 ) ;
return V_33 ;
}
int main ( int V_40 , char * * V_41 )
{
int V_4 , V_20 , V_6 = 0 ;
char * V_42 ;
static T_3 V_5 [ 32768 ] ;
if ( V_40 > 1 ) {
if ( ! strncmp ( L_13 , V_41 [ V_40 - 1 ] , 2 ) ) {
V_6 = 1 ;
} else {
printf ( L_14 ) ;
exit ( 0 ) ;
}
}
F_18 () ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
V_42 = F_14 ( & V_20 ) ;
V_4 = F_17 ( V_42 , V_20 , V_5 , sizeof( V_5 ) ) ;
if ( V_4 > 0 )
F_5 ( V_5 , V_4 , V_6 ) ;
F_16 ( V_42 ) ;
return 0 ;
}
