int F_1 ( void * V_1 , char * V_2 )
{
int V_3 [ 4 ] ;
if ( V_2 == NULL )
return 0 ;
if ( sscanf ( V_2 , L_1 , & V_3 [ 0 ] ,
& V_3 [ 1 ] , & V_3 [ 2 ] , & V_3 [ 3 ] ) != 4 ) {
F_2 ( V_4 L_2 ,
V_2 ) ;
return - V_5 ;
}
return 0 ;
}
void F_3 ( char * V_2 , unsigned char * V_6 )
{
int V_3 [ 4 ] ;
if ( ( V_2 != NULL ) &&
( sscanf ( V_2 , L_1 , & V_3 [ 0 ] ,
& V_3 [ 1 ] , & V_3 [ 2 ] , & V_3 [ 3 ] ) == 4 ) &&
( V_6 [ 0 ] == V_3 [ 0 ] ) &&
( V_6 [ 1 ] == V_3 [ 1 ] ) &&
( V_6 [ 2 ] == V_3 [ 2 ] ) &&
( V_6 [ 3 ] == V_3 [ 3 ] ) ) {
F_2 ( V_4 L_3
L_4 ) ;
}
}
void F_4 ( int V_7 , char * V_8 , int V_9 )
{
int V_10 , V_11 , V_12 ;
char V_13 ;
char * V_14 ;
if ( V_8 == NULL ) {
V_8 = & V_13 ;
V_9 = sizeof( V_13 ) ;
}
* V_8 = '\0' ;
V_11 = F_5 ( V_7 , & V_10 , sizeof( V_10 ) ) ;
if ( V_11 != sizeof( V_10 ) ) {
if ( V_11 < 0 )
V_11 = - V_15 ;
V_12 = sizeof( V_10 ) ;
V_14 = L_5 ;
goto V_16;
}
while ( V_10 != 0 ) {
V_12 = ( V_10 < V_9 ) ? V_10 : V_9 ;
V_11 = F_5 ( V_7 , V_8 , V_12 ) ;
if ( V_11 != V_12 ) {
if ( V_11 < 0 )
V_11 = - V_15 ;
V_14 = L_6 ;
goto V_16;
}
V_10 -= V_11 ;
}
return;
V_16:
if ( V_11 < 0 )
F_2 ( V_4 L_7
L_8 , V_14 , - V_11 ) ;
else
F_2 ( V_4 L_9
L_10 , V_14 , V_11 , V_12 ) ;
}
int F_6 ( int V_7 , void * V_17 , int V_9 )
{
int V_18 ;
V_18 = F_5 ( V_7 , V_17 , V_9 ) ;
if ( ( V_18 < 0 ) && ( V_15 == V_19 ) )
return 0 ;
else if ( V_18 == 0 )
return - V_20 ;
return V_18 ;
}
int F_7 ( int V_7 , void * V_17 , int V_9 )
{
int V_18 ;
F_8 ( V_18 = F_9 ( V_7 , V_17 , V_9 , 0 , NULL , NULL ) ) ;
if ( V_18 < 0 ) {
if ( V_15 == V_19 )
return 0 ;
return - V_15 ;
}
else if ( V_18 == 0 )
return - V_20 ;
return V_18 ;
}
int F_10 ( int V_7 , void * V_17 , int V_9 )
{
int V_18 ;
V_18 = F_11 ( V_7 , V_17 , V_9 ) ;
if ( ( V_18 < 0 ) && ( V_15 == V_19 ) )
return 0 ;
else if ( V_18 == 0 )
return - V_20 ;
return V_18 ;
}
int F_12 ( int V_7 , void * V_17 , int V_9 )
{
int V_18 ;
F_8 ( V_18 = F_13 ( V_7 , V_17 , V_9 , 0 ) ) ;
if ( V_18 < 0 ) {
if ( V_15 == V_19 )
return 0 ;
return - V_15 ;
}
else if ( V_18 == 0 )
return - V_20 ;
return V_18 ;
}
int F_14 ( int V_7 , void * V_17 , int V_9 , void * V_21 , int V_22 )
{
int V_18 ;
F_8 ( V_18 = F_15 ( V_7 , V_17 , V_9 , 0 , (struct V_23 * ) V_21 ,
V_22 ) ) ;
if ( V_18 < 0 ) {
if ( V_15 == V_19 )
return 0 ;
return - V_15 ;
}
else if ( V_18 == 0 )
return - V_20 ;
return V_18 ;
}
static void F_16 ( void * V_24 )
{
struct V_25 * V_26 = V_24 ;
F_17 ( V_26 -> V_27 ) ;
F_18 ( V_26 -> stdout , 1 ) ;
}
static int F_19 ( char * * V_28 , char * V_8 , int V_29 )
{
int V_30 , V_31 [ 2 ] , V_16 ;
struct V_25 V_32 ;
V_16 = F_20 ( V_31 , 1 , 0 ) ;
if ( V_16 < 0 ) {
F_2 ( V_4 L_11 ,
- V_16 ) ;
return V_16 ;
}
V_32 . V_27 = V_31 [ 0 ] ;
V_32 . stdout = V_31 [ 1 ] ;
V_30 = F_21 ( F_16 , & V_32 , V_28 ) ;
if ( V_30 > 0 )
F_4 ( V_31 [ 0 ] , V_8 , V_29 ) ;
F_17 ( V_31 [ 0 ] ) ;
F_17 ( V_31 [ 1 ] ) ;
if ( V_30 > 0 )
F_22 ( V_30 ) ;
return V_30 ;
}
static void F_23 ( char * V_1 , char * V_33 , unsigned char * V_34 ,
unsigned char * V_35 )
{
char V_36 [ sizeof( L_12 ) ] ;
char V_37 [ sizeof( L_12 ) ] ;
char V_38 [ sizeof( L_13 ) ] ;
char * V_28 [] = { L_14 , V_38 , V_33 , V_1 , V_36 ,
V_37 , NULL } ;
char * V_8 ;
int V_29 , V_30 ;
sprintf ( V_38 , L_15 , V_39 ) ;
sprintf ( V_36 , L_1 , V_34 [ 0 ] , V_34 [ 1 ] , V_34 [ 2 ] , V_34 [ 3 ] ) ;
sprintf ( V_37 , L_1 , V_35 [ 0 ] , V_35 [ 1 ] ,
V_35 [ 2 ] , V_35 [ 3 ] ) ;
V_29 = V_40 ;
V_8 = F_24 ( V_29 , V_41 ) ;
if ( V_8 == NULL )
F_2 ( V_4 L_16
L_17 ) ;
V_30 = F_19 ( V_28 , V_8 , V_29 ) ;
if ( V_30 < 0 ) {
F_25 ( V_8 ) ;
return;
}
if ( V_8 != NULL ) {
F_2 ( L_18 , V_8 ) ;
F_25 ( V_8 ) ;
}
}
void F_26 ( unsigned char * V_34 , unsigned char * V_35 , void * V_24 )
{
F_23 ( V_24 , L_19 , V_34 , V_35 ) ;
}
void F_27 ( unsigned char * V_34 , unsigned char * V_35 , void * V_24 )
{
F_23 ( V_24 , L_20 , V_34 , V_35 ) ;
}
char * F_28 ( char * V_14 , ... )
{
char * * V_24 , * V_42 ;
T_1 V_43 ;
va_start ( V_43 , V_14 ) ;
while ( ( V_24 = va_arg ( V_43 , char * * ) ) != NULL ) {
if ( * V_14 == '\0' )
return NULL ;
V_42 = strchr ( V_14 , ',' ) ;
if ( V_42 != V_14 )
* V_24 = V_14 ;
if ( V_42 == NULL )
return NULL ;
* V_42 ++ = '\0' ;
V_14 = V_42 ;
}
va_end ( V_43 ) ;
return V_14 ;
}
