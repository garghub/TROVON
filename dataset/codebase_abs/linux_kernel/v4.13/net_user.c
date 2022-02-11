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
F_18 ( V_26 -> V_28 , 1 ) ;
}
static int F_19 ( char * * V_29 , char * V_8 , int V_30 )
{
int V_31 , V_32 [ 2 ] , V_16 ;
struct V_25 V_33 ;
V_16 = F_20 ( V_32 , 1 , 0 ) ;
if ( V_16 < 0 ) {
F_2 ( V_4 L_11 ,
- V_16 ) ;
return V_16 ;
}
V_33 . V_27 = V_32 [ 0 ] ;
V_33 . V_28 = V_32 [ 1 ] ;
V_31 = F_21 ( F_16 , & V_33 , V_29 ) ;
if ( V_31 > 0 )
F_4 ( V_32 [ 0 ] , V_8 , V_30 ) ;
F_17 ( V_32 [ 0 ] ) ;
F_17 ( V_32 [ 1 ] ) ;
if ( V_31 > 0 )
F_22 ( V_31 ) ;
return V_31 ;
}
static void F_23 ( char * V_1 , char * V_34 , unsigned char * V_35 ,
unsigned char * V_36 )
{
char V_37 [ sizeof( L_12 ) ] ;
char V_38 [ sizeof( L_12 ) ] ;
char V_39 [ sizeof( L_13 ) ] ;
char * V_29 [] = { L_14 , V_39 , V_34 , V_1 , V_37 ,
V_38 , NULL } ;
char * V_8 ;
int V_30 , V_31 ;
sprintf ( V_39 , L_15 , V_40 ) ;
sprintf ( V_37 , L_1 , V_35 [ 0 ] , V_35 [ 1 ] , V_35 [ 2 ] , V_35 [ 3 ] ) ;
sprintf ( V_38 , L_1 , V_36 [ 0 ] , V_36 [ 1 ] ,
V_36 [ 2 ] , V_36 [ 3 ] ) ;
V_30 = V_41 ;
V_8 = F_24 ( V_30 , V_42 ) ;
if ( V_8 == NULL )
F_2 ( V_4 L_16
L_17 ) ;
V_31 = F_19 ( V_29 , V_8 , V_30 ) ;
if ( V_31 < 0 ) {
F_25 ( V_8 ) ;
return;
}
if ( V_8 != NULL ) {
F_2 ( L_18 , V_8 ) ;
F_25 ( V_8 ) ;
}
}
void F_26 ( unsigned char * V_35 , unsigned char * V_36 , void * V_24 )
{
F_23 ( V_24 , L_19 , V_35 , V_36 ) ;
}
void F_27 ( unsigned char * V_35 , unsigned char * V_36 , void * V_24 )
{
F_23 ( V_24 , L_20 , V_35 , V_36 ) ;
}
char * F_28 ( char * V_14 , ... )
{
char * * V_24 , * V_43 , * V_11 = NULL ;
T_1 V_44 ;
va_start ( V_44 , V_14 ) ;
while ( ( V_24 = va_arg ( V_44 , char * * ) ) != NULL ) {
if ( * V_14 == '\0' )
goto V_45;
V_43 = strchr ( V_14 , ',' ) ;
if ( V_43 != V_14 )
* V_24 = V_14 ;
if ( V_43 == NULL )
goto V_45;
* V_43 ++ = '\0' ;
V_14 = V_43 ;
}
V_11 = V_14 ;
V_45:
va_end ( V_44 ) ;
return V_11 ;
}
