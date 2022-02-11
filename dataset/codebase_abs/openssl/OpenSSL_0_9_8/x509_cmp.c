int F_1 ( const T_1 * V_1 , const T_1 * V_2 )
{
int V_3 ;
T_2 * V_4 , * V_5 ;
V_4 = V_1 -> V_6 ;
V_5 = V_2 -> V_6 ;
V_3 = F_2 ( V_4 -> V_7 , V_5 -> V_7 ) ;
if ( V_3 ) return ( V_3 ) ;
return ( F_3 ( V_4 -> V_8 , V_5 -> V_8 ) ) ;
}
unsigned long F_4 ( T_1 * V_1 )
{
unsigned long V_9 = 0 ;
T_3 V_10 ;
unsigned char V_11 [ 16 ] ;
char * V_12 ;
F_5 ( & V_10 ) ;
V_12 = F_6 ( V_1 -> V_6 -> V_8 , NULL , 0 ) ;
V_9 = strlen ( V_12 ) ;
F_7 ( & V_10 , F_8 () , NULL ) ;
F_9 ( & V_10 , ( unsigned char * ) V_12 , V_9 ) ;
F_10 ( V_12 ) ;
F_9 ( & V_10 , ( unsigned char * ) V_1 -> V_6 -> V_7 -> V_13 ,
( unsigned long ) V_1 -> V_6 -> V_7 -> V_14 ) ;
F_11 ( & V_10 , & ( V_11 [ 0 ] ) , NULL ) ;
V_9 = ( ( ( unsigned long ) V_11 [ 0 ] ) | ( ( unsigned long ) V_11 [ 1 ] << 8L ) |
( ( unsigned long ) V_11 [ 2 ] << 16L ) | ( ( unsigned long ) V_11 [ 3 ] << 24L )
) & 0xffffffffL ;
F_12 ( & V_10 ) ;
return ( V_9 ) ;
}
int F_13 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( F_3 ( V_1 -> V_6 -> V_8 , V_2 -> V_6 -> V_8 ) ) ;
}
int F_14 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( F_3 ( V_1 -> V_6 -> V_15 , V_2 -> V_6 -> V_15 ) ) ;
}
int F_15 ( const T_4 * V_1 , const T_4 * V_2 )
{
return ( F_3 ( V_1 -> V_16 -> V_8 , V_2 -> V_16 -> V_8 ) ) ;
}
T_5 * F_16 ( T_1 * V_1 )
{
return ( V_1 -> V_6 -> V_8 ) ;
}
unsigned long F_17 ( T_1 * V_17 )
{
return ( F_18 ( V_17 -> V_6 -> V_8 ) ) ;
}
T_5 * F_19 ( T_1 * V_1 )
{
return ( V_1 -> V_6 -> V_15 ) ;
}
T_6 * F_20 ( T_1 * V_1 )
{
return ( V_1 -> V_6 -> V_7 ) ;
}
unsigned long F_21 ( T_1 * V_17 )
{
return ( F_18 ( V_17 -> V_6 -> V_15 ) ) ;
}
int F_22 ( const T_1 * V_1 , const T_1 * V_2 )
{
F_23 ( ( T_1 * ) V_1 , - 1 , 0 ) ;
F_23 ( ( T_1 * ) V_2 , - 1 , 0 ) ;
return memcmp ( V_1 -> V_18 , V_2 -> V_18 , V_19 ) ;
}
static int F_24 ( const T_7 * V_1 , const T_7 * V_2 )
{
int V_3 ;
if ( V_1 -> V_14 != V_2 -> V_14 )
return ( V_1 -> V_14 - V_2 -> V_14 ) ;
for ( V_3 = 0 ; V_3 < V_1 -> V_14 ; V_3 ++ )
{
int V_20 , V_21 ;
V_20 = tolower ( V_1 -> V_13 [ V_3 ] ) ;
V_21 = tolower ( V_2 -> V_13 [ V_3 ] ) ;
if ( V_20 != V_21 )
return ( V_20 - V_21 ) ;
}
return 0 ;
}
static int F_25 ( const T_7 * V_1 , const T_7 * V_2 )
{
unsigned char * V_22 = NULL , * V_23 = NULL ;
int V_24 , V_25 ;
V_24 = V_1 -> V_14 ;
V_25 = V_2 -> V_14 ;
V_22 = V_1 -> V_13 ;
V_23 = V_2 -> V_13 ;
while ( V_24 > 0 && isspace ( * V_22 ) )
{
V_24 -- ;
V_22 ++ ;
}
while ( V_25 > 0 && isspace ( * V_23 ) )
{
V_25 -- ;
V_23 ++ ;
}
while ( V_24 > 0 && isspace ( V_22 [ V_24 - 1 ] ) )
V_24 -- ;
while ( V_25 > 0 && isspace ( V_23 [ V_25 - 1 ] ) )
V_25 -- ;
while ( V_24 > 0 && V_25 > 0 )
{
int V_20 , V_21 ;
V_20 = tolower ( * V_22 ) ;
V_21 = tolower ( * V_23 ) ;
if ( V_20 != V_21 )
return ( V_20 - V_21 ) ;
V_22 ++ ; V_23 ++ ;
V_24 -- ; V_25 -- ;
if ( V_24 <= 0 || V_25 <= 0 )
break;
if ( isspace ( * V_22 ) && isspace ( * V_23 ) )
{
while ( V_24 > 0 && isspace ( * V_22 ) )
{
V_24 -- ;
V_22 ++ ;
}
while ( V_25 > 0 && isspace ( * V_23 ) )
{
V_25 -- ;
V_23 ++ ;
}
}
}
if ( V_24 > 0 || V_25 > 0 )
return V_24 - V_25 ;
return 0 ;
}
static int F_26 ( T_7 * V_1 , T_7 * V_2 )
{
int V_26 ;
V_26 = V_1 -> V_14 - V_2 -> V_14 ;
if ( V_26 )
return V_26 ;
return memcmp ( V_1 -> V_13 , V_2 -> V_13 , V_1 -> V_14 ) ;
}
int F_3 ( const T_5 * V_1 , const T_5 * V_2 )
{
int V_3 , V_26 ;
T_8 * V_27 , * V_28 ;
unsigned long V_29 , V_30 ;
V_26 = F_27 ( V_1 -> V_31 )
- F_27 ( V_2 -> V_31 ) ;
if ( V_26 )
return V_26 ;
for ( V_3 = F_27 ( V_1 -> V_31 ) - 1 ; V_3 >= 0 ; V_3 -- )
{
V_27 = F_28 ( V_1 -> V_31 , V_3 ) ;
V_28 = F_28 ( V_2 -> V_31 , V_3 ) ;
V_26 = V_27 -> V_32 -> type - V_28 -> V_32 -> type ;
if ( V_26 )
{
V_29 = F_29 ( V_27 -> V_32 -> type ) ;
V_30 = F_29 ( V_28 -> V_32 -> type ) ;
if ( ! ( V_29 & V_33 ) ||
! ( V_30 & V_33 ) )
return V_26 ;
V_26 = F_26 ( V_27 -> V_32 , V_28 -> V_32 ) ;
}
else if ( V_27 -> V_32 -> type == V_34 )
V_26 = F_25 ( V_27 -> V_32 , V_28 -> V_32 ) ;
else if ( V_27 -> V_32 -> type == V_35
&& F_30 ( V_27 -> V_36 ) == V_37 )
V_26 = F_24 ( V_27 -> V_32 , V_28 -> V_32 ) ;
else
V_26 = F_26 ( V_27 -> V_32 , V_28 -> V_32 ) ;
if ( V_26 ) return ( V_26 ) ;
V_26 = V_27 -> V_38 - V_28 -> V_38 ;
if ( V_26 ) return ( V_26 ) ;
}
for ( V_3 = F_27 ( V_1 -> V_31 ) - 1 ; V_3 >= 0 ; V_3 -- )
{
V_27 = F_28 ( V_1 -> V_31 , V_3 ) ;
V_28 = F_28 ( V_2 -> V_31 , V_3 ) ;
V_26 = F_31 ( V_27 -> V_36 , V_28 -> V_36 ) ;
if ( V_26 ) return ( V_26 ) ;
}
return ( 0 ) ;
}
unsigned long F_18 ( T_5 * V_17 )
{
unsigned long V_9 = 0 ;
unsigned char V_11 [ 16 ] ;
F_32 ( V_17 , NULL ) ;
F_33 ( V_17 -> V_39 -> V_13 , V_17 -> V_39 -> V_14 , V_11 , NULL , F_8 () , NULL ) ;
V_9 = ( ( ( unsigned long ) V_11 [ 0 ] ) | ( ( unsigned long ) V_11 [ 1 ] << 8L ) |
( ( unsigned long ) V_11 [ 2 ] << 16L ) | ( ( unsigned long ) V_11 [ 3 ] << 24L )
) & 0xffffffffL ;
return ( V_9 ) ;
}
T_9 * F_34 ( T_1 * V_17 )
{
if ( ( V_17 == NULL ) || ( V_17 -> V_6 == NULL ) )
return ( NULL ) ;
return ( F_35 ( V_17 -> V_6 -> V_40 ) ) ;
}
T_10 * F_36 ( const T_1 * V_17 )
{
if( ! V_17 ) return NULL ;
return V_17 -> V_6 -> V_40 -> V_41 ;
}
int F_37 ( T_1 * V_17 , T_9 * V_42 )
{
T_9 * V_43 = NULL ;
int V_44 = 0 ;
V_43 = F_34 ( V_17 ) ;
switch ( F_38 ( V_43 , V_42 ) )
{
case 1 :
V_44 = 1 ;
break;
case 0 :
F_39 ( V_45 , V_46 ) ;
break;
case - 1 :
F_39 ( V_45 , V_47 ) ;
break;
case - 2 :
#ifndef F_40
if ( V_42 -> type == V_48 )
{
F_39 ( V_45 , V_49 ) ;
break;
}
#endif
#ifndef F_41
if ( V_42 -> type == V_50 )
{
F_39 ( V_45 , V_51 ) ;
break;
}
#endif
F_39 ( V_45 , V_52 ) ;
}
F_42 ( V_43 ) ;
return ( V_44 ) ;
}
