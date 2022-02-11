static T_1 * F_1 ( void )
{
T_1 * V_1 = NULL ;
if ( ( V_1 = F_2 () ) == NULL ) return ( NULL ) ;
V_1 -> V_2 = F_3 ( V_3 , sizeof( V_3 ) , NULL ) ;
V_1 -> V_4 = F_3 ( V_5 , sizeof( V_5 ) , NULL ) ;
if ( ( V_1 -> V_2 == NULL ) || ( V_1 -> V_4 == NULL ) )
return ( NULL ) ;
return ( V_1 ) ;
}
static int F_4 ( const char * V_6 , int V_7 )
{
if( V_7 )
fprintf ( V_8 , L_1 , V_6 ) ;
else
fprintf ( V_8 , L_2 , V_6 ) ;
fprintf ( V_8 , L_3 , V_9 ) ;
return 1 ;
}
static int F_5 ( const char * V_10 )
{
fprintf ( V_8 , L_3 , V_10 ) ;
return 1 ;
}
static int F_6 ( const char * V_11 , const char * V_12 )
{
fprintf ( V_8 , V_11 , V_12 ) ;
fprintf ( V_8 , L_4 ) ;
return 1 ;
}
static int F_7 ( const char * V_13 , unsigned int * V_14 )
{
unsigned long V_15 ;
if( ! F_8 ( V_13 , & V_15 ) || ( V_15 < 1 ) || ( V_15 > 1024 ) ) {
fprintf ( V_8 , L_5
L_6 , V_13 ) ;
return 0 ;
}
* V_14 = ( unsigned int ) V_15 ;
return 1 ;
}
static int F_9 ( const char * V_13 , int * V_16 )
{
unsigned long V_15 ;
if( ! F_8 ( V_13 , & V_15 ) || ( V_15 > 1 ) ) {
fprintf ( V_8 , L_7
L_8 , V_13 ) ;
return 0 ;
}
* V_16 = ( int ) V_15 ;
return 1 ;
}
static int F_10 ( const char * V_13 , const char * * V_17 )
{
if( ( strcmp ( V_13 , L_9 ) == 0 ) || ( strcmp ( V_13 , L_10 ) == 0 ) ||
( strcmp ( V_13 , L_11 ) == 0 ) ) {
* V_17 = V_13 ;
return 1 ;
}
fprintf ( V_8 , L_12 , V_13 ) ;
return 0 ;
}
static int F_11 ( const char * V_13 , unsigned int * V_18 )
{
unsigned long V_15 ;
if( ! F_8 ( V_13 , & V_15 ) || ( V_15 > 3 ) ) {
fprintf ( V_8 , L_5
L_13 , V_13 ) ;
return 0 ;
}
* V_18 = ( unsigned int ) V_15 ;
return 1 ;
}
static int F_12 ( const char * V_13 , unsigned int * V_19 )
{
unsigned long V_15 ;
if( ! F_8 ( V_13 , & V_15 ) || ( V_15 < 1 ) || ( V_15 > 50 ) ) {
fprintf ( V_8 , L_5
L_14 , V_13 ) ;
return 0 ;
}
* V_19 = ( unsigned int ) V_15 ;
return 1 ;
}
static void F_13 ( T_2 * V_20 , unsigned int V_21 )
{
T_3 * V_22 = V_20 -> V_23 + V_21 ;
if( V_22 -> V_24 != - 1 )
F_14 ( V_22 -> V_24 ) ;
if( V_22 -> V_25 != V_22 -> V_24 )
F_14 ( V_22 -> V_25 ) ;
V_22 -> V_24 = V_22 -> V_25 = - 1 ;
if( V_22 -> V_26 != - 1 )
F_14 ( V_22 -> V_26 ) ;
if( V_22 -> V_27 != V_22 -> V_26 )
F_14 ( V_22 -> V_27 ) ;
V_22 -> V_26 = V_22 -> V_27 = - 1 ;
F_15 ( & V_22 -> V_28 ) ;
if( V_21 + 1 < V_20 -> V_29 )
memmove ( V_20 -> V_23 + V_21 ,
V_20 -> V_23 + ( V_21 + 1 ) ,
( V_20 -> V_29 - ( V_21 + 1 ) ) *
sizeof( T_3 ) ) ;
V_20 -> V_29 -- ;
}
static int F_16 ( T_4 * V_30 , T_3 * V_22 )
{
int V_31 , V_32 , V_33 , V_34 ;
if( ( V_22 -> V_24 != - 1 ) && F_17 ( V_22 -> V_24 ,
& V_30 -> V_35 . V_36 ) )
return 0 ;
if( ( V_22 -> V_25 != - 1 ) && F_17 ( V_22 -> V_25 ,
& V_30 -> V_35 . V_36 ) )
return 0 ;
if( ( V_22 -> V_26 != - 1 ) && F_17 ( V_22 -> V_26 ,
& V_30 -> V_35 . V_36 ) )
return 0 ;
if( ( V_22 -> V_27 != - 1 ) && F_17 ( V_22 -> V_27 ,
& V_30 -> V_35 . V_36 ) )
return 0 ;
V_31 = V_32 = V_33 = V_34 = 0 ;
if( V_22 -> V_24 != - 1 )
V_31 = F_17 ( V_22 -> V_24 , & V_30 -> V_35 . V_37 ) ;
if( V_22 -> V_25 != - 1 )
V_32 = F_17 ( V_22 -> V_25 , & V_30 -> V_35 . V_38 ) ;
if( V_22 -> V_26 != - 1 )
V_33 = F_17 ( V_22 -> V_26 , & V_30 -> V_35 . V_37 ) ;
if( V_22 -> V_27 != - 1 )
V_34 = F_17 ( V_22 -> V_27 , & V_30 -> V_35 . V_38 ) ;
if( ! V_31 && ! V_32 && ! V_33 && ! V_34 )
return 1 ;
if( V_31 )
V_31 = ( F_18 ( F_19 ( & V_22 -> V_28 ,
V_39 ) , V_22 -> V_24 ) <= 0 ) ;
if( V_32 )
V_32 = ( F_20 ( F_19 ( & V_22 -> V_28 ,
V_40 ) , V_22 -> V_25 ) <= 0 ) ;
if( V_33 )
V_33 = ( F_18 ( F_19 ( & V_22 -> V_28 ,
V_41 ) , V_22 -> V_26 ) <= 0 ) ;
if( V_34 )
V_34 = ( F_20 ( F_19 ( & V_22 -> V_28 ,
V_42 ) , V_22 -> V_27 ) <= 0 ) ;
if( V_31 ) {
F_14 ( V_22 -> V_24 ) ;
if( V_22 -> V_25 == V_22 -> V_24 )
V_22 -> V_25 = - 1 ;
V_22 -> V_24 = - 1 ;
}
if( V_32 && ( V_22 -> V_25 != - 1 ) ) {
F_14 ( V_22 -> V_25 ) ;
if( V_22 -> V_25 == V_22 -> V_24 )
V_22 -> V_24 = - 1 ;
V_22 -> V_25 = - 1 ;
}
if( V_33 ) {
F_14 ( V_22 -> V_26 ) ;
if( V_22 -> V_27 == V_22 -> V_26 )
V_22 -> V_27 = - 1 ;
V_22 -> V_26 = - 1 ;
}
if( V_34 && ( V_22 -> V_27 != - 1 ) ) {
F_14 ( V_22 -> V_27 ) ;
if( V_22 -> V_27 == V_22 -> V_26 )
V_22 -> V_26 = - 1 ;
V_22 -> V_27 = - 1 ;
}
if( ! F_21 ( & V_22 -> V_28 ) )
return 0 ;
if( ( ( V_22 -> V_24 == - 1 ) || ( V_22 -> V_25 == - 1 ) ) &&
( ( V_22 -> V_26 == - 1 ) || ( V_22 -> V_27 == - 1 ) ) )
return 0 ;
if( ( V_22 -> V_24 == - 1 ) || ( V_22 -> V_25 == - 1 ) ) {
if( ! F_22 ( & V_22 -> V_28 ) )
return 0 ;
}
if( ( V_22 -> V_26 == - 1 ) || ( V_22 -> V_27 == - 1 ) ) {
if( ! F_23 ( & V_22 -> V_28 ) )
return 0 ;
}
return 1 ;
}
