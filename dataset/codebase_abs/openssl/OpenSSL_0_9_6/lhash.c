void F_1 ( T_1 * V_1 )
{
unsigned int V_2 ;
T_2 * V_3 , * V_4 ;
if ( V_1 == NULL )
return;
for ( V_2 = 0 ; V_2 < V_1 -> V_5 ; V_2 ++ )
{
V_3 = V_1 -> V_6 [ V_2 ] ;
while ( V_3 != NULL )
{
V_4 = V_3 -> V_7 ;
F_2 ( V_3 ) ;
V_3 = V_4 ;
}
}
F_2 ( V_1 -> V_6 ) ;
F_2 ( V_1 ) ;
}
void * F_3 ( T_1 * V_1 , void * V_8 )
{
unsigned long V_9 ;
T_2 * V_4 , * * V_10 ;
void * V_11 ;
V_1 -> error = 0 ;
if ( V_1 -> V_12 <= ( V_1 -> V_13 * V_14 / V_1 -> V_5 ) )
F_4 ( V_1 ) ;
V_10 = F_5 ( V_1 , V_8 , & V_9 ) ;
if ( * V_10 == NULL )
{
if ( ( V_4 = ( T_2 * ) F_6 ( sizeof( T_2 ) ) ) == NULL )
{
V_1 -> error ++ ;
return ( NULL ) ;
}
V_4 -> V_8 = V_8 ;
V_4 -> V_7 = NULL ;
#ifndef F_7
V_4 -> V_9 = V_9 ;
#endif
* V_10 = V_4 ;
V_11 = NULL ;
V_1 -> V_15 ++ ;
V_1 -> V_13 ++ ;
}
else
{
V_11 = ( * V_10 ) -> V_8 ;
( * V_10 ) -> V_8 = V_8 ;
V_1 -> V_16 ++ ;
}
return ( V_11 ) ;
}
void * F_8 ( T_1 * V_1 , void * V_8 )
{
unsigned long V_9 ;
T_2 * V_4 , * * V_10 ;
void * V_11 ;
V_1 -> error = 0 ;
V_10 = F_5 ( V_1 , V_8 , & V_9 ) ;
if ( * V_10 == NULL )
{
V_1 -> V_17 ++ ;
return ( NULL ) ;
}
else
{
V_4 = * V_10 ;
* V_10 = V_4 -> V_7 ;
V_11 = V_4 -> V_8 ;
F_2 ( V_4 ) ;
V_1 -> V_18 ++ ;
}
V_1 -> V_13 -- ;
if ( ( V_1 -> V_5 > V_19 ) &&
( V_1 -> V_20 >= ( V_1 -> V_13 * V_14 / V_1 -> V_5 ) ) )
F_9 ( V_1 ) ;
return ( V_11 ) ;
}
void * F_10 ( T_1 * V_1 , void * V_8 )
{
unsigned long V_9 ;
T_2 * * V_10 ;
void * V_11 ;
V_1 -> error = 0 ;
V_10 = F_5 ( V_1 , V_8 , & V_9 ) ;
if ( * V_10 == NULL )
{
V_1 -> V_21 ++ ;
return ( NULL ) ;
}
else
{
V_11 = ( * V_10 ) -> V_8 ;
V_1 -> V_22 ++ ;
}
return ( V_11 ) ;
}
void F_11 ( T_1 * V_1 , void (* F_12)() )
{
F_13 ( V_1 , F_12 , NULL ) ;
}
void F_13 ( T_1 * V_1 , void (* F_12)() , void * V_23 )
{
int V_2 ;
T_2 * V_24 , * V_3 ;
for ( V_2 = V_1 -> V_5 - 1 ; V_2 >= 0 ; V_2 -- )
{
V_24 = V_1 -> V_6 [ V_2 ] ;
while ( V_24 != NULL )
{
V_3 = V_24 -> V_7 ;
F_12 ( V_24 -> V_8 , V_23 ) ;
V_24 = V_3 ;
}
}
}
static void F_4 ( T_1 * V_1 )
{
T_2 * * V_3 , * * V_25 , * * V_26 , * V_27 ;
unsigned int V_28 , V_2 , V_29 ;
unsigned long V_9 , V_30 ;
V_1 -> V_5 ++ ;
V_1 -> V_31 ++ ;
V_28 = ( int ) V_1 -> V_28 ++ ;
V_25 = & ( V_1 -> V_6 [ V_28 ] ) ;
V_26 = & ( V_1 -> V_6 [ V_28 + ( int ) V_1 -> V_32 ] ) ;
* V_26 = NULL ;
V_30 = V_1 -> V_33 ;
for ( V_27 = * V_25 ; V_27 != NULL ; )
{
#ifndef F_7
V_9 = V_27 -> V_9 ;
#else
V_9 = ( * ( V_1 -> V_9 ) ) ( V_27 -> V_8 ) ;
V_1 -> V_34 ++ ;
#endif
if ( ( V_9 % V_30 ) != V_28 )
{
* V_25 = ( * V_25 ) -> V_7 ;
V_27 -> V_7 = * V_26 ;
* V_26 = V_27 ;
}
else
V_25 = & ( ( * V_25 ) -> V_7 ) ;
V_27 = * V_25 ;
}
if ( ( V_1 -> V_28 ) >= V_1 -> V_32 )
{
V_29 = ( int ) V_1 -> V_33 * 2 ;
V_3 = ( T_2 * * ) F_14 ( V_1 -> V_6 ,
( unsigned int ) sizeof( T_2 * ) * V_29 ) ;
if ( V_3 == NULL )
{
V_1 -> error ++ ;
V_1 -> V_28 = 0 ;
return;
}
for ( V_2 = ( int ) V_1 -> V_33 ; V_2 < V_29 ; V_2 ++ )
V_3 [ V_2 ] = NULL ;
V_1 -> V_32 = V_1 -> V_33 ;
V_1 -> V_33 = V_29 ;
V_1 -> V_35 ++ ;
V_1 -> V_28 = 0 ;
V_1 -> V_6 = V_3 ;
}
}
static void F_9 ( T_1 * V_1 )
{
T_2 * * V_3 , * V_25 , * V_27 ;
V_27 = V_1 -> V_6 [ V_1 -> V_28 + V_1 -> V_32 - 1 ] ;
V_1 -> V_6 [ V_1 -> V_28 + V_1 -> V_32 - 1 ] = NULL ;
if ( V_1 -> V_28 == 0 )
{
V_3 = ( T_2 * * ) F_14 ( V_1 -> V_6 ,
( unsigned int ) ( sizeof( T_2 * ) * V_1 -> V_32 ) ) ;
if ( V_3 == NULL )
{
V_1 -> error ++ ;
return;
}
V_1 -> V_36 ++ ;
V_1 -> V_33 /= 2 ;
V_1 -> V_32 /= 2 ;
V_1 -> V_28 = V_1 -> V_32 - 1 ;
V_1 -> V_6 = V_3 ;
}
else
V_1 -> V_28 -- ;
V_1 -> V_5 -- ;
V_1 -> V_37 ++ ;
V_25 = V_1 -> V_6 [ ( int ) V_1 -> V_28 ] ;
if ( V_25 == NULL )
V_1 -> V_6 [ ( int ) V_1 -> V_28 ] = V_27 ;
else
{
while ( V_25 -> V_7 != NULL )
V_25 = V_25 -> V_7 ;
V_25 -> V_7 = V_27 ;
}
}
static T_2 * * F_5 ( T_1 * V_1 , void * V_8 , unsigned long * V_38 )
{
T_2 * * V_11 , * V_25 ;
unsigned long V_9 , V_4 ;
int (* F_15)();
V_9 = ( * ( V_1 -> V_9 ) ) ( V_8 ) ;
V_1 -> V_34 ++ ;
* V_38 = V_9 ;
V_4 = V_9 % V_1 -> V_32 ;
if ( V_4 < V_1 -> V_28 )
V_4 = V_9 % V_1 -> V_33 ;
F_15 = V_1 -> V_39 ;
V_11 = & ( V_1 -> V_6 [ ( int ) V_4 ] ) ;
for ( V_25 = * V_11 ; V_25 != NULL ; V_25 = V_25 -> V_7 )
{
#ifndef F_7
V_1 -> V_40 ++ ;
if ( V_25 -> V_9 != V_9 )
{
V_11 = & ( V_25 -> V_7 ) ;
continue;
}
#endif
V_1 -> V_41 ++ ;
if ( (* F_15)( V_25 -> V_8 , V_8 ) == 0 )
break;
V_11 = & ( V_25 -> V_7 ) ;
}
return ( V_11 ) ;
}
unsigned long F_16 ( const char * V_42 )
{
unsigned long V_11 = 0 ;
long V_3 ;
unsigned long V_43 ;
int V_44 ;
if ( ( V_42 == NULL ) || ( * V_42 == '\0' ) )
return ( V_11 ) ;
V_3 = 0x100 ;
while ( * V_42 )
{
V_43 = V_3 | ( * V_42 ) ;
V_3 += 0x100 ;
V_44 = ( int ) ( ( V_43 >> 2 ) ^ V_43 ) & 0x0f ;
V_11 = ( V_11 << V_44 ) | ( V_11 >> ( 32 - V_44 ) ) ;
V_11 &= 0xFFFFFFFFL ;
V_11 ^= V_43 * V_43 ;
V_42 ++ ;
}
return ( ( V_11 >> 16 ) ^ V_11 ) ;
}
unsigned long F_17 ( T_1 * V_1 )
{
return V_1 ? V_1 -> V_13 : 0 ;
}
