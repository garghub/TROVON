T_1 * F_1 ( T_2 V_1 , T_3 V_2 )
{
T_1 * V_3 ;
if ( ( V_3 = F_2 ( sizeof( * V_3 ) ) ) == NULL )
goto V_4;
if ( ( V_3 -> V_5 = F_2 ( sizeof( * V_3 -> V_5 ) * V_6 ) ) == NULL )
goto V_7;
V_3 -> V_8 = ( ( V_2 == NULL ) ? ( T_3 ) strcmp : V_2 ) ;
V_3 -> V_9 = ( ( V_1 == NULL ) ? ( T_2 ) V_10 : V_1 ) ;
V_3 -> V_11 = V_6 / 2 ;
V_3 -> V_12 = V_6 ;
V_3 -> V_13 = V_6 / 2 ;
V_3 -> V_14 = V_15 ;
V_3 -> V_16 = V_17 ;
return ( V_3 ) ;
V_7:
F_3 ( V_3 ) ;
V_4:
return ( NULL ) ;
}
void F_4 ( T_1 * V_18 )
{
unsigned int V_19 ;
T_4 * V_20 , * V_21 ;
if ( V_18 == NULL )
return;
for ( V_19 = 0 ; V_19 < V_18 -> V_11 ; V_19 ++ ) {
V_20 = V_18 -> V_5 [ V_19 ] ;
while ( V_20 != NULL ) {
V_21 = V_20 -> V_22 ;
F_3 ( V_20 ) ;
V_20 = V_21 ;
}
}
F_3 ( V_18 -> V_5 ) ;
F_3 ( V_18 ) ;
}
void * F_5 ( T_1 * V_18 , void * V_23 )
{
unsigned long V_9 ;
T_4 * V_21 , * * V_24 ;
void * V_3 ;
V_18 -> error = 0 ;
if ( ( V_18 -> V_14 <= ( V_18 -> V_25 * V_26 / V_18 -> V_11 ) ) && ! F_6 ( V_18 ) )
return NULL ;
V_24 = F_7 ( V_18 , V_23 , & V_9 ) ;
if ( * V_24 == NULL ) {
if ( ( V_21 = F_8 ( sizeof( * V_21 ) ) ) == NULL ) {
V_18 -> error ++ ;
return ( NULL ) ;
}
V_21 -> V_23 = V_23 ;
V_21 -> V_22 = NULL ;
V_21 -> V_9 = V_9 ;
* V_24 = V_21 ;
V_3 = NULL ;
V_18 -> V_27 ++ ;
V_18 -> V_25 ++ ;
} else {
V_3 = ( * V_24 ) -> V_23 ;
( * V_24 ) -> V_23 = V_23 ;
V_18 -> V_28 ++ ;
}
return ( V_3 ) ;
}
void * F_9 ( T_1 * V_18 , const void * V_23 )
{
unsigned long V_9 ;
T_4 * V_21 , * * V_24 ;
void * V_3 ;
V_18 -> error = 0 ;
V_24 = F_7 ( V_18 , V_23 , & V_9 ) ;
if ( * V_24 == NULL ) {
V_18 -> V_29 ++ ;
return ( NULL ) ;
} else {
V_21 = * V_24 ;
* V_24 = V_21 -> V_22 ;
V_3 = V_21 -> V_23 ;
F_3 ( V_21 ) ;
V_18 -> V_30 ++ ;
}
V_18 -> V_25 -- ;
if ( ( V_18 -> V_11 > V_6 ) &&
( V_18 -> V_16 >= ( V_18 -> V_25 * V_26 / V_18 -> V_11 ) ) )
F_10 ( V_18 ) ;
return ( V_3 ) ;
}
void * F_11 ( T_1 * V_18 , const void * V_23 )
{
unsigned long V_9 ;
T_4 * * V_24 ;
void * V_3 ;
V_18 -> error = 0 ;
V_24 = F_7 ( V_18 , V_23 , & V_9 ) ;
if ( * V_24 == NULL ) {
V_18 -> V_31 ++ ;
return ( NULL ) ;
} else {
V_3 = ( * V_24 ) -> V_23 ;
V_18 -> V_32 ++ ;
}
return ( V_3 ) ;
}
static void F_12 ( T_1 * V_18 , int V_33 ,
T_5 V_34 ,
T_6 V_35 , void * V_36 )
{
int V_19 ;
T_4 * V_37 , * V_20 ;
if ( V_18 == NULL )
return;
for ( V_19 = V_18 -> V_11 - 1 ; V_19 >= 0 ; V_19 -- ) {
V_37 = V_18 -> V_5 [ V_19 ] ;
while ( V_37 != NULL ) {
V_20 = V_37 -> V_22 ;
if ( V_33 )
V_35 ( V_37 -> V_23 , V_36 ) ;
else
V_34 ( V_37 -> V_23 ) ;
V_37 = V_20 ;
}
}
}
void F_13 ( T_1 * V_18 , T_5 V_34 )
{
F_12 ( V_18 , 0 , V_34 , ( T_6 ) 0 , NULL ) ;
}
void F_14 ( T_1 * V_18 , T_6 V_34 , void * V_36 )
{
F_12 ( V_18 , 1 , ( T_5 ) 0 , V_34 , V_36 ) ;
}
static int F_6 ( T_1 * V_18 )
{
T_4 * * V_20 , * * V_38 , * * V_39 , * V_40 ;
unsigned int V_41 , V_19 , V_42 ;
unsigned long V_9 , V_43 ;
V_18 -> V_11 ++ ;
V_18 -> V_44 ++ ;
V_41 = ( int ) V_18 -> V_41 ++ ;
V_38 = & ( V_18 -> V_5 [ V_41 ] ) ;
V_39 = & ( V_18 -> V_5 [ V_41 + ( int ) V_18 -> V_13 ] ) ;
* V_39 = NULL ;
V_43 = V_18 -> V_12 ;
for ( V_40 = * V_38 ; V_40 != NULL ; ) {
V_9 = V_40 -> V_9 ;
if ( ( V_9 % V_43 ) != V_41 ) {
* V_38 = ( * V_38 ) -> V_22 ;
V_40 -> V_22 = * V_39 ;
* V_39 = V_40 ;
} else
V_38 = & ( ( * V_38 ) -> V_22 ) ;
V_40 = * V_38 ;
}
if ( ( V_18 -> V_41 ) >= V_18 -> V_13 ) {
V_42 = ( int ) V_18 -> V_12 * 2 ;
V_20 = F_15 ( V_18 -> V_5 , ( int ) ( sizeof( T_4 * ) * V_42 ) ) ;
if ( V_20 == NULL ) {
V_18 -> error ++ ;
V_18 -> V_41 = 0 ;
return 0 ;
}
for ( V_19 = ( int ) V_18 -> V_12 ; V_19 < V_42 ; V_19 ++ )
V_20 [ V_19 ] = NULL ;
V_18 -> V_13 = V_18 -> V_12 ;
V_18 -> V_12 = V_42 ;
V_18 -> V_45 ++ ;
V_18 -> V_41 = 0 ;
V_18 -> V_5 = V_20 ;
}
return 1 ;
}
static void F_10 ( T_1 * V_18 )
{
T_4 * * V_20 , * V_38 , * V_40 ;
V_40 = V_18 -> V_5 [ V_18 -> V_41 + V_18 -> V_13 - 1 ] ;
V_18 -> V_5 [ V_18 -> V_41 + V_18 -> V_13 - 1 ] = NULL ;
if ( V_18 -> V_41 == 0 ) {
V_20 = F_15 ( V_18 -> V_5 ,
( unsigned int ) ( sizeof( T_4 * ) * V_18 -> V_13 ) ) ;
if ( V_20 == NULL ) {
V_18 -> error ++ ;
return;
}
V_18 -> V_46 ++ ;
V_18 -> V_12 /= 2 ;
V_18 -> V_13 /= 2 ;
V_18 -> V_41 = V_18 -> V_13 - 1 ;
V_18 -> V_5 = V_20 ;
} else
V_18 -> V_41 -- ;
V_18 -> V_11 -- ;
V_18 -> V_47 ++ ;
V_38 = V_18 -> V_5 [ ( int ) V_18 -> V_41 ] ;
if ( V_38 == NULL )
V_18 -> V_5 [ ( int ) V_18 -> V_41 ] = V_40 ;
else {
while ( V_38 -> V_22 != NULL )
V_38 = V_38 -> V_22 ;
V_38 -> V_22 = V_40 ;
}
}
static T_4 * * F_7 ( T_1 * V_18 ,
const void * V_23 , unsigned long * V_48 )
{
T_4 * * V_3 , * V_38 ;
unsigned long V_9 , V_21 ;
T_3 V_49 ;
V_9 = ( * ( V_18 -> V_9 ) ) ( V_23 ) ;
V_18 -> V_50 ++ ;
* V_48 = V_9 ;
V_21 = V_9 % V_18 -> V_13 ;
if ( V_21 < V_18 -> V_41 )
V_21 = V_9 % V_18 -> V_12 ;
V_49 = V_18 -> V_8 ;
V_3 = & ( V_18 -> V_5 [ ( int ) V_21 ] ) ;
for ( V_38 = * V_3 ; V_38 != NULL ; V_38 = V_38 -> V_22 ) {
V_18 -> V_51 ++ ;
if ( V_38 -> V_9 != V_9 ) {
V_3 = & ( V_38 -> V_22 ) ;
continue;
}
V_18 -> V_52 ++ ;
if ( V_49 ( V_38 -> V_23 , V_23 ) == 0 )
break;
V_3 = & ( V_38 -> V_22 ) ;
}
return ( V_3 ) ;
}
unsigned long V_10 ( const char * V_2 )
{
unsigned long V_3 = 0 ;
long V_20 ;
unsigned long V_53 ;
int V_54 ;
if ( ( V_2 == NULL ) || ( * V_2 == '\0' ) )
return ( V_3 ) ;
V_20 = 0x100 ;
while ( * V_2 ) {
V_53 = V_20 | ( * V_2 ) ;
V_20 += 0x100 ;
V_54 = ( int ) ( ( V_53 >> 2 ) ^ V_53 ) & 0x0f ;
V_3 = ( V_3 << V_54 ) | ( V_3 >> ( 32 - V_54 ) ) ;
V_3 &= 0xFFFFFFFFL ;
V_3 ^= V_53 * V_53 ;
V_2 ++ ;
}
return ( ( V_3 >> 16 ) ^ V_3 ) ;
}
unsigned long F_16 ( const T_1 * V_18 )
{
return V_18 ? V_18 -> V_25 : 0 ;
}
unsigned long F_17 ( const T_1 * V_18 )
{
return V_18 -> V_16 ;
}
void F_18 ( T_1 * V_18 , unsigned long V_16 )
{
V_18 -> V_16 = V_16 ;
}
int F_19 ( T_1 * V_18 )
{
return V_18 -> error ;
}
