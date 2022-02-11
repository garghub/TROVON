void F_1 ( char * V_1 )
{
do {
if ( * V_1 == '\n' )
* V_1 = 0 ;
V_1 ++ ;
} while ( * ( V_1 - 1 ) || * V_1 != '\n' );
* V_1 = 0 ;
}
const char * F_2 ( const char * V_1 , const char * V_2 )
{
int V_3 = strlen ( V_2 ) ;
do {
if ( ! strncmp ( V_1 , V_2 , V_3 ) && V_1 [ V_3 ] == '=' )
return V_1 + V_3 + 1 ;
V_1 += strlen ( V_1 ) + 1 ;
} while ( strlen ( V_1 ) != 0 );
return NULL ;
}
int F_3 ( const char * V_1 , const char * V_2 , T_1 * V_4 )
{
const char * V_5 = F_2 ( V_1 , V_2 ) ;
if ( ! V_5 )
return 0 ;
* V_4 = F_4 ( V_5 , NULL , 10 ) ;
return 1 ;
}
int F_5 ( const char * V_1 , const char * V_2 , T_1 * V_4 )
{
const char * V_5 = F_2 ( V_1 , V_2 ) ;
if ( ! V_5 )
return 0 ;
* V_4 = F_4 ( V_5 , NULL , 16 ) ;
return 1 ;
}
void F_6 ( const char * V_1 )
{
T_2 V_6 [ 4 ] [ 6 ] ;
T_1 V_7 ;
T_3 V_8 ;
int V_9 ;
if ( ! F_5 ( V_1 , V_10 , & V_7 ) )
return;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
T_1 V_11 = ( V_7 & ~ 0x000000c00000 ) |
V_12 [ V_8 ] ;
for ( V_9 = 5 ; V_9 >= 0 ; V_9 -- ) {
V_6 [ V_8 ] [ V_9 ] = V_11 & 0xff ;
V_11 >>= 8 ;
}
F_7 ( V_8 , V_6 [ V_8 ] ) ;
}
}
void F_8 ( const char * V_1 )
{
char * V_13 ;
const char * V_14 ;
void * V_15 , * V_16 ;
V_14 = F_2 ( V_1 , V_17 ) ;
if ( ! V_14 )
return;
V_15 = F_9 ( NULL , L_1 ,
V_14 ) ;
if ( ! V_15 )
return;
V_13 = F_10 ( V_15 , V_18 , V_19 ) ;
if ( ! V_13 )
return;
V_16 = F_11 ( L_2 ) ;
if ( ! V_16 )
V_16 = F_12 ( NULL , L_3 ) ;
if ( ! V_16 )
return;
F_13 ( V_16 , L_4 , V_13 ) ;
}
void F_14 ( const char * V_1 )
{
void * V_16 , * stdout ;
T_1 V_20 ;
T_3 V_21 ;
int V_22 ;
V_16 = F_11 ( L_2 ) ;
if ( ! V_16 )
return;
V_22 = F_15 ( V_16 , L_4 , V_18 , V_19 ) ;
if ( V_22 <= 0 )
return;
stdout = F_11 ( V_18 ) ;
if ( ! stdout ) {
printf ( L_5
L_6 ) ;
return;
}
if ( ! F_3 ( V_1 , V_23 ,
& V_20 ) ) {
printf ( L_7 ) ;
return;
}
V_21 = V_20 ;
F_16 ( stdout , L_8 , & V_21 , 4 ) ;
}
