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
static char * F_14 ( unsigned int * V_20 )
{
int V_21 , V_4 ;
char * V_22 ;
V_4 = F_15 ( V_23 , NULL , 0 ) ;
V_22 = malloc ( V_4 ) ;
if ( ! V_22 )
return NULL ;
V_21 = F_15 ( V_24 , V_22 , V_4 ) ;
if ( V_21 < 0 ) {
free ( V_22 ) ;
return NULL ;
}
* V_20 = V_21 ;
return V_22 ;
}
static char * F_16 ( const char * V_25 , unsigned int * V_20 )
{
int V_26 , V_21 , V_4 ;
struct V_27 V_28 ;
char * V_22 ;
V_26 = F_17 ( V_25 , V_29 ) ;
if ( V_26 < 0 )
return NULL ;
V_21 = F_18 ( V_26 , & V_28 ) ;
if ( V_21 < 0 || ! F_19 ( V_28 . V_30 ) )
goto V_31;
V_4 = V_28 . V_32 + 1 ;
V_22 = malloc ( V_4 ) ;
if ( ! V_22 )
goto V_31;
memset ( V_22 , 0 , V_4 ) ;
V_21 = F_20 ( V_26 , V_22 , V_4 - 1 ) ;
if ( V_21 <= 0 )
goto V_33;
F_21 ( V_26 ) ;
* V_20 = V_21 ;
return V_22 ;
V_33:
free ( V_22 ) ;
V_31:
F_21 ( V_26 ) ;
return NULL ;
}
static char * F_22 ( const char * V_25 , unsigned int * V_20 )
{
return V_25 ? F_16 ( V_25 , V_20 ) : F_14 ( V_20 ) ;
}
static void F_23 ( char * V_22 )
{
free ( V_22 ) ;
}
static int F_24 ( char * V_34 , T_1 V_35 ,
T_3 * V_5 , T_1 V_36 )
{
char * V_37 , * V_38 , * V_39 ;
T_6 V_40 = 0 ;
int V_21 , V_41 , V_42 , V_43 , V_44 = 0 ;
T_7 V_45 [ 1 ] ;
unsigned long V_46 ;
T_8 V_47 ;
if ( V_35 == 0 )
return 0 ;
V_21 = regcomp ( & V_47 , L_6
L_7 , V_48 ) ;
assert ( V_21 == 0 ) ;
V_37 = V_34 ;
memset ( V_45 , 0 , sizeof( V_45 ) ) ;
while ( 1 ) {
V_21 = regexec ( & V_47 , V_37 , 1 , V_45 , 0 ) ;
if ( V_21 == 0 ) {
V_37 += V_45 [ 0 ] . V_49 ;
V_40 += V_45 [ 0 ] . V_49 ;
assert ( V_40 < V_35 ) ;
} else
break;
}
V_37 = V_34 + V_40 - ( V_45 [ 0 ] . V_49 - V_45 [ 0 ] . V_50 ) ;
V_21 = sscanf ( V_37 , L_8 ,
& V_41 , & V_42 , & V_43 , & V_46 ) ;
if ( V_21 != 4 ) {
regfree ( & V_47 ) ;
return 0 ;
}
V_39 = V_37 = V_34 + V_40 ;
while ( ( V_37 = strtok ( V_39 , L_5 ) ) != NULL && V_44 < V_36 ) {
V_39 = NULL ;
if ( ! strstr ( V_37 , L_9 ) )
continue;
V_38 = V_37 ;
while ( ( V_37 = strstr ( V_38 , L_10 ) ) )
V_38 = V_37 + 1 ;
V_37 = V_38 ;
do {
V_5 [ V_44 ++ ] = ( T_3 ) strtoul ( V_38 , & V_38 , 16 ) ;
if ( V_37 == V_38 || V_44 >= V_36 ) {
V_44 -- ;
break;
}
V_37 = V_38 ;
} while ( 1 );
}
assert ( V_44 == V_42 ) ;
printf ( L_11 ,
V_42 , V_43 , V_41 ) ;
printf ( L_12 , V_46 ) ;
regfree ( & V_47 ) ;
return V_44 ;
}
static void F_25 ( void )
{
printf ( L_13 ) ;
printf ( L_14 ) ;
printf ( L_15 ) ;
printf ( L_16 ) ;
}
int main ( int V_51 , char * * V_52 )
{
unsigned int V_4 , V_20 , V_53 , V_6 = 0 ;
static T_3 V_5 [ 32768 ] ;
char * V_54 , * V_25 = NULL ;
while ( ( V_53 = F_26 ( V_51 , V_52 , L_17 ) ) != - 1 ) {
switch ( V_53 ) {
case 'o' :
V_6 = 1 ;
break;
case 'f' :
V_25 = V_55 ;
break;
default:
F_25 () ;
return - 1 ;
}
}
F_27 () ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
V_54 = F_22 ( V_25 , & V_20 ) ;
if ( ! V_54 ) {
fprintf ( V_56 , L_18 ) ;
return - 1 ;
}
V_4 = F_24 ( V_54 , V_20 , V_5 , sizeof( V_5 ) ) ;
if ( V_4 > 0 )
F_5 ( V_5 , V_4 , V_6 ) ;
else
fprintf ( V_56 , L_19 ) ;
F_23 ( V_54 ) ;
return 0 ;
}
