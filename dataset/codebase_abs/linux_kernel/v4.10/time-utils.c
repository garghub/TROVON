int F_1 ( const char * V_1 , T_1 * V_2 )
{
T_1 V_3 , V_4 ;
char * V_5 ;
V_3 = strtoul ( V_1 , & V_5 , 10 ) ;
if ( * V_5 != '.' && * V_5 != '\0' )
return - 1 ;
if ( * V_5 == '.' ) {
int V_6 ;
char V_7 [ 10 ] ;
if ( strlen ( ++ V_5 ) > 9 )
return - 1 ;
strncpy ( V_7 , V_5 , 9 ) ;
V_7 [ 9 ] = '\0' ;
for ( V_6 = strlen ( V_7 ) ; V_6 < 9 ; V_6 ++ )
V_7 [ V_6 ] = '0' ;
V_4 = strtoul ( V_7 , & V_5 , 10 ) ;
if ( * V_5 != '\0' )
return - 1 ;
} else
V_4 = 0 ;
* V_2 = V_3 * V_8 + V_4 ;
return 0 ;
}
static int F_2 ( struct V_9 * V_2 ,
char * V_10 , char * V_11 )
{
if ( V_10 && ( * V_10 != '\0' ) &&
( F_1 ( V_10 , & V_2 -> V_12 ) != 0 ) ) {
return - 1 ;
}
if ( V_11 && ( * V_11 != '\0' ) &&
( F_1 ( V_11 , & V_2 -> V_5 ) != 0 ) ) {
return - 1 ;
}
return 0 ;
}
int F_3 ( struct V_9 * V_2 , const char * V_13 )
{
char * V_10 , * V_11 ;
char * V_14 , * V_1 ;
int V_15 = 0 ;
if ( V_13 == NULL || * V_13 == '\0' )
return 0 ;
V_1 = F_4 ( V_13 ) ;
if ( V_1 == NULL )
return - V_16 ;
V_2 -> V_12 = 0 ;
V_2 -> V_5 = 0 ;
V_10 = V_1 ;
V_14 = strchr ( V_10 , ',' ) ;
if ( V_14 ) {
* V_14 = '\0' ;
++ V_14 ;
}
V_11 = V_14 ;
V_15 = F_2 ( V_2 , V_10 , V_11 ) ;
free ( V_1 ) ;
if ( V_15 == 0 && V_2 -> V_5 && V_2 -> V_5 < V_2 -> V_12 )
return - V_17 ;
F_5 ( L_1 V_18 L_2 , V_2 -> V_12 ) ;
F_5 ( L_3 V_18 L_4 , V_2 -> V_5 ) ;
return V_15 ;
}
bool F_6 ( struct V_9 * V_2 , T_1 V_19 )
{
if ( V_19 == 0 )
return false ;
if ( ( V_2 -> V_12 && V_19 < V_2 -> V_12 ) ||
( V_2 -> V_5 && V_19 > V_2 -> V_5 ) ) {
return true ;
}
return false ;
}
