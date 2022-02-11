int F_1 ( const T_1 * V_1 , const T_1 * V_2 )
{
int V_3 ;
const T_2 * V_4 , * V_5 ;
V_4 = & V_1 -> V_6 ;
V_5 = & V_2 -> V_6 ;
V_3 = F_2 ( & V_4 -> V_7 , & V_5 -> V_7 ) ;
if ( V_3 )
return ( V_3 ) ;
return ( F_3 ( V_4 -> V_8 , V_5 -> V_8 ) ) ;
}
unsigned long F_4 ( T_1 * V_1 )
{
unsigned long V_9 = 0 ;
T_3 * V_10 = F_5 () ;
unsigned char V_11 [ 16 ] ;
char * V_12 ;
if ( V_10 == NULL )
goto V_13;
V_12 = F_6 ( V_1 -> V_6 . V_8 , NULL , 0 ) ;
if ( ! F_7 ( V_10 , F_8 () , NULL ) )
goto V_13;
if ( ! F_9 ( V_10 , ( unsigned char * ) V_12 , strlen ( V_12 ) ) )
goto V_13;
F_10 ( V_12 ) ;
if ( ! F_9
( V_10 , ( unsigned char * ) V_1 -> V_6 . V_7 . V_14 ,
( unsigned long ) V_1 -> V_6 . V_7 . V_15 ) )
goto V_13;
if ( ! F_11 ( V_10 , & ( V_11 [ 0 ] ) , NULL ) )
goto V_13;
V_9 = ( ( ( unsigned long ) V_11 [ 0 ] ) | ( ( unsigned long ) V_11 [ 1 ] << 8L ) |
( ( unsigned long ) V_11 [ 2 ] << 16L ) | ( ( unsigned long ) V_11 [ 3 ] << 24L )
) & 0xffffffffL ;
V_13:
F_12 ( V_10 ) ;
return ( V_9 ) ;
}
int F_13 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( F_3 ( V_1 -> V_6 . V_8 , V_2 -> V_6 . V_8 ) ) ;
}
int F_14 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( F_3 ( V_1 -> V_6 . V_16 , V_2 -> V_6 . V_16 ) ) ;
}
int F_15 ( const T_4 * V_1 , const T_4 * V_2 )
{
return ( F_3 ( V_1 -> V_17 . V_8 , V_2 -> V_17 . V_8 ) ) ;
}
int F_16 ( const T_4 * V_1 , const T_4 * V_2 )
{
return memcmp ( V_1 -> V_18 , V_2 -> V_18 , 20 ) ;
}
T_5 * F_17 ( const T_1 * V_1 )
{
return ( V_1 -> V_6 . V_8 ) ;
}
unsigned long F_18 ( T_1 * V_19 )
{
return ( F_19 ( V_19 -> V_6 . V_8 ) ) ;
}
unsigned long F_20 ( T_1 * V_19 )
{
return ( F_21 ( V_19 -> V_6 . V_8 ) ) ;
}
T_5 * F_22 ( const T_1 * V_1 )
{
return ( V_1 -> V_6 . V_16 ) ;
}
T_6 * F_23 ( T_1 * V_1 )
{
return & V_1 -> V_6 . V_7 ;
}
const T_6 * F_24 ( const T_1 * V_1 )
{
return & V_1 -> V_6 . V_7 ;
}
unsigned long F_25 ( T_1 * V_19 )
{
return ( F_19 ( V_19 -> V_6 . V_16 ) ) ;
}
unsigned long F_26 ( T_1 * V_19 )
{
return ( F_21 ( V_19 -> V_6 . V_16 ) ) ;
}
int F_27 ( const T_1 * V_1 , const T_1 * V_2 )
{
int V_20 ;
F_28 ( ( T_1 * ) V_1 , - 1 , 0 ) ;
F_28 ( ( T_1 * ) V_2 , - 1 , 0 ) ;
V_20 = memcmp ( V_1 -> V_18 , V_2 -> V_18 , V_21 ) ;
if ( V_20 )
return V_20 ;
if ( ! V_1 -> V_6 . V_22 . V_23 && ! V_2 -> V_6 . V_22 . V_23 ) {
if ( V_1 -> V_6 . V_22 . V_24 < V_2 -> V_6 . V_22 . V_24 )
return - 1 ;
if ( V_1 -> V_6 . V_22 . V_24 > V_2 -> V_6 . V_22 . V_24 )
return 1 ;
return memcmp ( V_1 -> V_6 . V_22 . V_22 , V_2 -> V_6 . V_22 . V_22 ,
V_1 -> V_6 . V_22 . V_24 ) ;
}
return V_20 ;
}
int F_3 ( const T_5 * V_1 , const T_5 * V_2 )
{
int V_9 ;
if ( ! V_1 -> V_25 || V_1 -> V_23 ) {
V_9 = F_29 ( ( T_5 * ) V_1 , NULL ) ;
if ( V_9 < 0 )
return - 2 ;
}
if ( ! V_2 -> V_25 || V_2 -> V_23 ) {
V_9 = F_29 ( ( T_5 * ) V_2 , NULL ) ;
if ( V_9 < 0 )
return - 2 ;
}
V_9 = V_1 -> V_26 - V_2 -> V_26 ;
if ( V_9 )
return V_9 ;
return memcmp ( V_1 -> V_25 , V_2 -> V_25 , V_1 -> V_26 ) ;
}
unsigned long F_19 ( T_5 * V_19 )
{
unsigned long V_9 = 0 ;
unsigned char V_11 [ V_21 ] ;
F_29 ( V_19 , NULL ) ;
if ( ! F_30 ( V_19 -> V_25 , V_19 -> V_26 , V_11 , NULL , F_31 () ,
NULL ) )
return 0 ;
V_9 = ( ( ( unsigned long ) V_11 [ 0 ] ) | ( ( unsigned long ) V_11 [ 1 ] << 8L ) |
( ( unsigned long ) V_11 [ 2 ] << 16L ) | ( ( unsigned long ) V_11 [ 3 ] << 24L )
) & 0xffffffffL ;
return ( V_9 ) ;
}
unsigned long F_21 ( T_5 * V_19 )
{
T_3 * V_27 = F_5 () ;
unsigned long V_9 = 0 ;
unsigned char V_11 [ 16 ] ;
if ( V_27 == NULL )
return V_9 ;
F_29 ( V_19 , NULL ) ;
F_32 ( V_27 , V_28 ) ;
if ( F_7 ( V_27 , F_8 () , NULL )
&& F_9 ( V_27 , V_19 -> V_29 -> V_14 , V_19 -> V_29 -> V_15 )
&& F_11 ( V_27 , V_11 , NULL ) )
V_9 = ( ( ( unsigned long ) V_11 [ 0 ] ) | ( ( unsigned long ) V_11 [ 1 ] << 8L ) |
( ( unsigned long ) V_11 [ 2 ] << 16L ) | ( ( unsigned long ) V_11 [ 3 ] << 24L )
) & 0xffffffffL ;
F_12 ( V_27 ) ;
return ( V_9 ) ;
}
T_7 * F_33 ( const T_1 * V_19 )
{
if ( V_19 == NULL )
return NULL ;
return F_34 ( V_19 -> V_6 . V_30 ) ;
}
T_7 * F_35 ( T_1 * V_19 )
{
if ( V_19 == NULL )
return NULL ;
return F_36 ( V_19 -> V_6 . V_30 ) ;
}
int F_37 ( const T_1 * V_19 , const T_7 * V_31 )
{
const T_7 * V_32 ;
int V_9 ;
V_32 = F_33 ( V_19 ) ;
if ( V_32 )
V_9 = F_38 ( V_32 , V_31 ) ;
else
V_9 = - 2 ;
switch ( V_9 ) {
case 1 :
break;
case 0 :
F_39 ( V_33 , V_34 ) ;
break;
case - 1 :
F_39 ( V_33 , V_35 ) ;
break;
case - 2 :
F_39 ( V_33 , V_36 ) ;
}
if ( V_9 > 0 )
return 1 ;
return 0 ;
}
static int F_40 ( T_7 * V_37 , int V_38 , unsigned long * V_39 )
{
const T_8 * V_40 = NULL ;
int V_41 ;
if ( V_37 && F_41 ( V_37 ) == V_42 )
V_40 = F_42 ( F_43 ( V_37 ) ) ;
if ( ! V_40 )
return V_43 ;
V_41 = F_44 ( V_40 ) ;
if ( V_41 == V_44 ) {
if ( V_38 != - 1 && V_38 != V_45 )
return V_46 ;
if ( ! ( * V_39 & V_47 ) )
return V_48 ;
* V_39 &= ~ V_49 ;
} else if ( V_41 == V_50 ) {
if ( V_38 != - 1 && V_38 != V_51 )
return V_46 ;
if ( ! ( * V_39 & V_49 ) )
return V_48 ;
} else
return V_52 ;
return V_53 ;
}
int F_45 ( T_4 * V_17 , T_7 * V_54 , unsigned long V_55 )
{
int V_38 ;
if ( ! ( V_55 & V_56 ) )
return V_53 ;
V_38 = F_46 ( V_17 -> V_17 . V_57 . V_58 ) ;
return F_40 ( V_54 , V_38 , & V_55 ) ;
}
int F_45 ( T_4 * V_17 , T_7 * V_54 , unsigned long V_55 )
{
return 0 ;
}
