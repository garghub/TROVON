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
static void F_5 ( T_3 * V_5 , T_1 V_4 , unsigned long V_6 ,
int V_7 )
{
int V_8 , V_9 , V_10 = 0 ;
char V_1 [ 256 ] ;
struct V_11 V_12 ;
T_4 V_13 ;
T_5 * V_14 ;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
F_1 ( V_1 , sizeof( V_1 ) ) ;
V_14 = F_6 ( V_1 , NULL ) ;
assert ( V_14 ) ;
assert ( F_7 ( V_14 , V_15 ) ) ;
F_8 ( & V_12 , stdout , ( V_16 ) fprintf ) ;
V_12 . V_17 = F_9 ( V_14 ) ;
V_12 . V_18 = F_10 ( V_14 ) ;
V_12 . V_19 = V_5 ;
V_12 . V_20 = V_4 ;
F_11 ( & V_12 ) ;
V_13 = F_12 ( V_14 ) ;
assert ( V_13 ) ;
do {
printf ( L_2 , V_10 ) ;
V_8 = V_13 ( V_10 , & V_12 ) ;
if ( V_7 ) {
printf ( L_3 ) ;
for ( V_9 = 0 ; V_9 < V_8 ; ++ V_9 )
printf ( L_4 , ( T_3 ) V_5 [ V_10 + V_9 ] ) ;
}
printf ( L_5 ) ;
V_10 += V_8 ;
} while( V_8 > 0 && V_10 < V_4 );
F_13 ( V_14 ) ;
}
static char * F_14 ( int * V_21 )
{
int V_22 , V_4 = F_15 ( 10 , NULL , 0 ) ;
char * V_23 = malloc ( V_4 ) ;
assert ( V_23 && V_21 ) ;
V_22 = F_15 ( 3 , V_23 , V_4 ) ;
assert ( V_22 >= 0 ) ;
* V_21 = V_22 ;
return V_23 ;
}
static void F_16 ( char * V_23 )
{
free ( V_23 ) ;
}
static int F_17 ( char * V_24 , T_1 V_25 ,
T_3 * V_5 , T_1 V_26 ,
unsigned long * V_6 )
{
char * V_27 , * V_28 , * V_29 ;
T_6 V_30 = 0 ;
int V_22 , V_31 , V_32 , V_33 , V_34 = 0 ;
T_7 V_35 [ 1 ] ;
T_8 V_36 ;
if ( V_25 == 0 )
return 0 ;
V_22 = regcomp ( & V_36 , L_6
L_7 , V_37 ) ;
assert ( V_22 == 0 ) ;
V_27 = V_24 ;
while ( 1 ) {
V_22 = regexec ( & V_36 , V_27 , 1 , V_35 , 0 ) ;
if ( V_22 == 0 ) {
V_27 += V_35 [ 0 ] . V_38 ;
V_30 += V_35 [ 0 ] . V_38 ;
assert ( V_30 < V_25 ) ;
} else
break;
}
V_27 = V_24 + V_30 - ( V_35 [ 0 ] . V_38 - V_35 [ 0 ] . V_39 ) ;
V_22 = sscanf ( V_27 , L_8 ,
& V_31 , & V_32 , & V_33 , V_6 ) ;
if ( V_22 != 4 )
return 0 ;
V_29 = V_27 = V_24 + V_30 ;
while ( ( V_27 = strtok ( V_29 , L_5 ) ) != NULL && V_34 < V_26 ) {
V_29 = NULL ;
if ( ! strstr ( V_27 , L_9 ) )
continue;
V_28 = V_27 ;
while ( ( V_27 = strstr ( V_28 , L_10 ) ) )
V_28 = V_27 + 1 ;
V_27 = V_28 ;
do {
V_5 [ V_34 ++ ] = ( T_3 ) strtoul ( V_28 , & V_28 , 16 ) ;
if ( V_27 == V_28 || V_34 >= V_26 ) {
V_34 -- ;
break;
}
V_27 = V_28 ;
} while ( 1 );
}
assert ( V_34 == V_32 ) ;
printf ( L_11 ,
V_32 , V_33 , V_31 ) ;
printf ( L_12 , * V_6 ) ;
regfree ( & V_36 ) ;
return V_34 ;
}
int main ( int V_40 , char * * V_41 )
{
int V_4 , V_21 , V_7 = 0 ;
char * V_42 ;
unsigned long V_6 ;
T_3 V_5 [ 4096 ] ;
if ( V_40 > 1 ) {
if ( ! strncmp ( L_13 , V_41 [ V_40 - 1 ] , 2 ) ) {
V_7 = 1 ;
} else {
printf ( L_14 ) ;
exit ( 0 ) ;
}
}
F_18 () ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
V_42 = F_14 ( & V_21 ) ;
V_4 = F_17 ( V_42 , V_21 , V_5 , sizeof( V_5 ) , & V_6 ) ;
if ( V_4 > 0 && V_6 > 0 )
F_5 ( V_5 , V_4 , V_6 , V_7 ) ;
F_16 ( V_42 ) ;
return 0 ;
}
