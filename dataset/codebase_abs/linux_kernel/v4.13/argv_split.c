static int F_1 ( const char * V_1 )
{
int V_2 = 0 ;
bool V_3 ;
for ( V_3 = true ; * V_1 ; V_1 ++ ) {
if ( isspace ( * V_1 ) ) {
V_3 = true ;
} else if ( V_3 ) {
V_3 = false ;
V_2 ++ ;
}
}
return V_2 ;
}
void F_2 ( char * * V_4 )
{
V_4 -- ;
F_3 ( V_4 [ 0 ] ) ;
F_3 ( V_4 ) ;
}
char * * F_4 ( T_1 V_5 , const char * V_1 , int * V_6 )
{
char * V_7 ;
bool V_3 ;
char * * V_4 , * * V_8 ;
int V_9 ;
V_7 = F_5 ( V_1 , V_10 - 1 , V_5 ) ;
if ( ! V_7 )
return NULL ;
V_9 = F_1 ( V_7 ) ;
V_4 = F_6 ( sizeof( * V_4 ) * ( V_9 + 2 ) , V_5 ) ;
if ( ! V_4 ) {
F_3 ( V_7 ) ;
return NULL ;
}
* V_4 = V_7 ;
V_8 = ++ V_4 ;
for ( V_3 = true ; * V_7 ; V_7 ++ ) {
if ( isspace ( * V_7 ) ) {
V_3 = true ;
* V_7 = 0 ;
} else if ( V_3 ) {
V_3 = false ;
* V_4 ++ = V_7 ;
}
}
* V_4 = NULL ;
if ( V_6 )
* V_6 = V_9 ;
return V_8 ;
}
