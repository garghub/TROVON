int F_1 ( const T_1 * V_1 , const T_1 * V_2 )
{
int V_3 ;
T_2 * V_4 , * V_5 ;
V_4 = V_1 -> V_6 ;
V_5 = V_2 -> V_6 ;
V_3 = F_2 ( V_4 -> V_7 , V_5 -> V_7 ) ;
if ( V_3 )
return ( V_3 ) ;
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
if ( ! F_7 ( & V_10 , F_8 () , NULL ) )
goto V_13;
if ( ! F_9 ( & V_10 , ( unsigned char * ) V_12 , strlen ( V_12 ) ) )
goto V_13;
F_10 ( V_12 ) ;
if ( ! F_9
( & V_10 , ( unsigned char * ) V_1 -> V_6 -> V_7 -> V_14 ,
( unsigned long ) V_1 -> V_6 -> V_7 -> V_15 ) )
goto V_13;
if ( ! F_11 ( & V_10 , & ( V_11 [ 0 ] ) , NULL ) )
goto V_13;
V_9 = ( ( ( unsigned long ) V_11 [ 0 ] ) | ( ( unsigned long ) V_11 [ 1 ] << 8L ) |
( ( unsigned long ) V_11 [ 2 ] << 16L ) | ( ( unsigned long ) V_11 [ 3 ] << 24L )
) & 0xffffffffL ;
V_13:
F_12 ( & V_10 ) ;
return ( V_9 ) ;
}
int F_13 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( F_3 ( V_1 -> V_6 -> V_8 , V_2 -> V_6 -> V_8 ) ) ;
}
int F_14 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( F_3 ( V_1 -> V_6 -> V_16 , V_2 -> V_6 -> V_16 ) ) ;
}
int F_15 ( const T_4 * V_1 , const T_4 * V_2 )
{
return ( F_3 ( V_1 -> V_17 -> V_8 , V_2 -> V_17 -> V_8 ) ) ;
}
int F_16 ( const T_4 * V_1 , const T_4 * V_2 )
{
return memcmp ( V_1 -> V_18 , V_2 -> V_18 , 20 ) ;
}
T_5 * F_17 ( T_1 * V_1 )
{
return ( V_1 -> V_6 -> V_8 ) ;
}
unsigned long F_18 ( T_1 * V_19 )
{
return ( F_19 ( V_19 -> V_6 -> V_8 ) ) ;
}
unsigned long F_20 ( T_1 * V_19 )
{
return ( F_21 ( V_19 -> V_6 -> V_8 ) ) ;
}
T_5 * F_22 ( T_1 * V_1 )
{
return ( V_1 -> V_6 -> V_16 ) ;
}
T_6 * F_23 ( T_1 * V_1 )
{
return ( V_1 -> V_6 -> V_7 ) ;
}
unsigned long F_24 ( T_1 * V_19 )
{
return ( F_19 ( V_19 -> V_6 -> V_16 ) ) ;
}
unsigned long F_25 ( T_1 * V_19 )
{
return ( F_21 ( V_19 -> V_6 -> V_16 ) ) ;
}
int F_26 ( const T_1 * V_1 , const T_1 * V_2 )
{
int V_20 ;
F_27 ( ( T_1 * ) V_1 , - 1 , 0 ) ;
F_27 ( ( T_1 * ) V_2 , - 1 , 0 ) ;
V_20 = memcmp ( V_1 -> V_18 , V_2 -> V_18 , V_21 ) ;
if ( V_20 )
return V_20 ;
if ( ! V_1 -> V_6 -> V_22 . V_23 && ! V_2 -> V_6 -> V_22 . V_23 ) {
V_20 = ( int ) ( V_1 -> V_6 -> V_22 . V_24 - V_2 -> V_6 -> V_22 . V_24 ) ;
if ( V_20 )
return V_20 ;
return memcmp ( V_1 -> V_6 -> V_22 . V_22 , V_2 -> V_6 -> V_22 . V_22 ,
V_1 -> V_6 -> V_22 . V_24 ) ;
}
return V_20 ;
}
int F_3 ( const T_5 * V_1 , const T_5 * V_2 )
{
int V_9 ;
if ( ! V_1 -> V_25 || V_1 -> V_23 ) {
V_9 = F_28 ( ( T_5 * ) V_1 , NULL ) ;
if ( V_9 < 0 )
return - 2 ;
}
if ( ! V_2 -> V_25 || V_2 -> V_23 ) {
V_9 = F_28 ( ( T_5 * ) V_2 , NULL ) ;
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
F_28 ( V_19 , NULL ) ;
if ( ! F_29 ( V_19 -> V_25 , V_19 -> V_26 , V_11 , NULL , F_30 () ,
NULL ) )
return 0 ;
V_9 = ( ( ( unsigned long ) V_11 [ 0 ] ) | ( ( unsigned long ) V_11 [ 1 ] << 8L ) |
( ( unsigned long ) V_11 [ 2 ] << 16L ) | ( ( unsigned long ) V_11 [ 3 ] << 24L )
) & 0xffffffffL ;
return ( V_9 ) ;
}
unsigned long F_21 ( T_5 * V_19 )
{
T_3 V_27 ;
unsigned long V_9 = 0 ;
unsigned char V_11 [ 16 ] ;
F_28 ( V_19 , NULL ) ;
F_5 ( & V_27 ) ;
F_31 ( & V_27 , V_28 ) ;
if ( F_7 ( & V_27 , F_8 () , NULL )
&& F_9 ( & V_27 , V_19 -> V_29 -> V_14 , V_19 -> V_29 -> V_15 )
&& F_11 ( & V_27 , V_11 , NULL ) )
V_9 = ( ( ( unsigned long ) V_11 [ 0 ] ) | ( ( unsigned long ) V_11 [ 1 ] << 8L ) |
( ( unsigned long ) V_11 [ 2 ] << 16L ) | ( ( unsigned long ) V_11 [ 3 ] << 24L )
) & 0xffffffffL ;
F_12 ( & V_27 ) ;
return ( V_9 ) ;
}
T_7 * F_32 ( T_1 * V_19 )
{
if ( ( V_19 == NULL ) || ( V_19 -> V_6 == NULL ) )
return ( NULL ) ;
return ( F_33 ( V_19 -> V_6 -> V_30 ) ) ;
}
T_8 * F_34 ( const T_1 * V_19 )
{
if ( ! V_19 )
return NULL ;
return V_19 -> V_6 -> V_30 -> V_31 ;
}
int F_35 ( T_1 * V_19 , T_7 * V_32 )
{
T_7 * V_33 ;
int V_9 ;
V_33 = F_32 ( V_19 ) ;
if ( V_33 )
V_9 = F_36 ( V_33 , V_32 ) ;
else
V_9 = - 2 ;
switch ( V_9 ) {
case 1 :
break;
case 0 :
F_37 ( V_34 , V_35 ) ;
break;
case - 1 :
F_37 ( V_34 , V_36 ) ;
break;
case - 2 :
F_37 ( V_34 , V_37 ) ;
}
if ( V_33 )
F_38 ( V_33 ) ;
if ( V_9 > 0 )
return 1 ;
return 0 ;
}
static int F_39 ( T_7 * V_38 , int V_39 , unsigned long * V_40 )
{
const T_9 * V_41 = NULL ;
int V_42 ;
if ( V_38 && V_38 -> type == V_43 )
V_41 = F_40 ( V_38 -> V_38 . V_44 ) ;
if ( ! V_41 )
return V_45 ;
V_42 = F_41 ( V_41 ) ;
if ( V_42 == V_46 ) {
if ( V_39 != - 1 && V_39 != V_47 )
return V_48 ;
if ( ! ( * V_40 & V_49 ) )
return V_50 ;
* V_40 &= ~ V_51 ;
} else if ( V_42 == V_52 ) {
if ( V_39 != - 1 && V_39 != V_53 )
return V_48 ;
if ( ! ( * V_40 & V_51 ) )
return V_50 ;
} else
return V_54 ;
return V_55 ;
}
int F_42 ( T_4 * V_17 , T_7 * V_56 , unsigned long V_57 )
{
int V_39 ;
if ( ! ( V_57 & V_58 ) )
return V_55 ;
V_39 = F_43 ( V_17 -> V_17 -> V_59 -> V_60 ) ;
return F_39 ( V_56 , V_39 , & V_57 ) ;
}
int F_42 ( T_4 * V_17 , T_7 * V_56 , unsigned long V_57 )
{
return 0 ;
}
