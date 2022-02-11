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
int F_3 ( const T_5 * V_1 , const T_5 * V_2 )
{
int V_3 , V_26 ;
T_8 * V_27 , * V_28 ;
if ( F_26 ( V_1 -> V_29 )
!= F_26 ( V_2 -> V_29 ) )
return F_26 ( V_1 -> V_29 )
- F_26 ( V_2 -> V_29 ) ;
for ( V_3 = F_26 ( V_1 -> V_29 ) - 1 ; V_3 >= 0 ; V_3 -- )
{
V_27 = F_27 ( V_1 -> V_29 , V_3 ) ;
V_28 = F_27 ( V_2 -> V_29 , V_3 ) ;
V_26 = V_27 -> V_30 -> type - V_28 -> V_30 -> type ;
if ( V_26 ) return ( V_26 ) ;
if ( V_27 -> V_30 -> type == V_31 )
V_26 = F_25 ( V_27 -> V_30 , V_28 -> V_30 ) ;
else if ( V_27 -> V_30 -> type == V_32
&& F_28 ( V_27 -> V_33 ) == V_34 )
V_26 = F_24 ( V_27 -> V_30 , V_28 -> V_30 ) ;
else
{
V_26 = V_27 -> V_30 -> V_14 - V_28 -> V_30 -> V_14 ;
if ( V_26 ) return ( V_26 ) ;
V_26 = memcmp ( V_27 -> V_30 -> V_13 , V_28 -> V_30 -> V_13 ,
V_27 -> V_30 -> V_14 ) ;
}
if ( V_26 ) return ( V_26 ) ;
V_26 = V_27 -> V_35 - V_28 -> V_35 ;
if ( V_26 ) return ( V_26 ) ;
}
for ( V_3 = F_26 ( V_1 -> V_29 ) - 1 ; V_3 >= 0 ; V_3 -- )
{
V_27 = F_27 ( V_1 -> V_29 , V_3 ) ;
V_28 = F_27 ( V_2 -> V_29 , V_3 ) ;
V_26 = F_29 ( V_27 -> V_33 , V_28 -> V_33 ) ;
if ( V_26 ) return ( V_26 ) ;
}
return ( 0 ) ;
}
unsigned long F_18 ( T_5 * V_17 )
{
unsigned long V_9 = 0 ;
unsigned char V_11 [ 16 ] ;
F_30 ( V_17 , NULL ) ;
F_31 ( V_17 -> V_36 -> V_13 , V_17 -> V_36 -> V_14 , V_11 , NULL , F_8 () , NULL ) ;
V_9 = ( ( ( unsigned long ) V_11 [ 0 ] ) | ( ( unsigned long ) V_11 [ 1 ] << 8L ) |
( ( unsigned long ) V_11 [ 2 ] << 16L ) | ( ( unsigned long ) V_11 [ 3 ] << 24L )
) & 0xffffffffL ;
return ( V_9 ) ;
}
T_9 * F_32 ( T_1 * V_17 )
{
if ( ( V_17 == NULL ) || ( V_17 -> V_6 == NULL ) )
return ( NULL ) ;
return ( F_33 ( V_17 -> V_6 -> V_37 ) ) ;
}
T_10 * F_34 ( const T_1 * V_17 )
{
if( ! V_17 ) return NULL ;
return V_17 -> V_6 -> V_37 -> V_38 ;
}
int F_35 ( T_1 * V_17 , T_9 * V_39 )
{
T_9 * V_40 = NULL ;
int V_41 = 0 ;
V_40 = F_32 ( V_17 ) ;
if ( V_40 -> type != V_39 -> type )
{
F_36 ( V_42 , V_43 ) ;
goto V_44;
}
switch ( V_39 -> type )
{
#ifndef F_37
case V_45 :
if ( F_38 ( V_40 -> V_46 . V_47 -> V_48 , V_39 -> V_46 . V_47 -> V_48 ) != 0
|| F_38 ( V_40 -> V_46 . V_47 -> V_49 , V_39 -> V_46 . V_47 -> V_49 ) != 0 )
{
F_36 ( V_42 , V_50 ) ;
goto V_44;
}
break;
#endif
#ifndef F_39
case V_51 :
if ( F_38 ( V_40 -> V_46 . V_52 -> V_53 , V_39 -> V_46 . V_52 -> V_53 ) != 0 )
{
F_36 ( V_42 , V_50 ) ;
goto V_44;
}
break;
#endif
#ifndef F_40
case V_54 :
F_36 ( V_42 , V_55 ) ;
goto V_44;
#endif
default:
F_36 ( V_42 , V_56 ) ;
goto V_44;
}
V_41 = 1 ;
V_44:
F_41 ( V_40 ) ;
return ( V_41 ) ;
}
