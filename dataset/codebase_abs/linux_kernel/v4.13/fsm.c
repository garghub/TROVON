T_1 *
F_1 ( char * V_1 , const char * * V_2 , const char * * V_3 , int V_4 ,
int V_5 , const T_2 * V_6 , int V_7 , T_3 V_8 )
{
int V_9 ;
T_1 * V_10 ;
T_4 * V_11 ;
T_5 * V_12 ;
V_10 = F_2 ( sizeof( T_1 ) , V_8 ) ;
if ( V_10 == NULL ) {
F_3 ( V_13
L_1 , V_1 ) ;
return NULL ;
}
F_4 ( V_10 -> V_1 , V_1 , sizeof( V_10 -> V_1 ) ) ;
F_5 ( & V_10 -> V_14 ) ;
V_12 = F_2 ( sizeof( T_5 ) , V_8 ) ;
if ( V_12 == NULL ) {
F_3 ( V_13
L_2 , V_1 ) ;
F_6 ( V_10 ) ;
return NULL ;
}
V_12 -> V_5 = V_5 ;
V_12 -> V_4 = V_4 ;
V_12 -> V_3 = V_3 ;
V_12 -> V_2 = V_2 ;
V_10 -> V_12 = V_12 ;
V_11 = F_7 ( V_4 * V_5 , sizeof( T_4 ) , V_8 ) ;
if ( V_11 == NULL ) {
F_3 ( V_13
L_3 , V_1 ) ;
F_6 ( V_10 ) ;
return NULL ;
}
V_12 -> V_15 = V_11 ;
for ( V_9 = 0 ; V_9 < V_7 ; V_9 ++ ) {
if ( ( V_6 [ V_9 ] . V_16 >= V_4 ) ||
( V_6 [ V_9 ] . V_17 >= V_5 ) ) {
F_3 ( V_18
L_4 ,
V_1 , V_9 , ( long ) V_6 [ V_9 ] . V_16 , ( long ) V_12 -> V_4 ,
( long ) V_6 [ V_9 ] . V_17 , ( long ) V_12 -> V_5 ) ;
F_6 ( V_10 ) ;
return NULL ;
} else
V_11 [ V_4 * V_6 [ V_9 ] . V_17 + V_6 [ V_9 ] . V_16 ] =
V_6 [ V_9 ] . V_19 ;
}
return V_10 ;
}
void
F_6 ( T_1 * V_10 )
{
if ( V_10 ) {
if ( V_10 -> V_12 ) {
F_8 ( V_10 -> V_12 -> V_15 ) ;
F_8 ( V_10 -> V_12 ) ;
}
F_8 ( V_10 ) ;
} else
F_3 ( V_13
L_5 ) ;
}
void
F_9 ( T_1 * V_20 )
{
int V_21 = 0 ;
int V_9 ;
if ( V_20 -> V_22 >= V_23 )
V_21 = V_20 -> V_24 ;
F_3 ( V_25 L_6 , V_20 -> V_1 ) ;
for ( V_9 = 0 ; V_9 < V_20 -> V_22 ; V_9 ++ ) {
int V_26 = V_20 -> V_27 [ V_21 ] . V_28 ;
int V_29 = V_20 -> V_27 [ V_21 ++ ] . V_30 ;
V_21 %= V_23 ;
if ( V_26 == - 1 )
F_3 ( V_25 L_7 ,
V_20 -> V_12 -> V_2 [ V_29 ] ) ;
else
F_3 ( V_25 L_8 ,
V_20 -> V_12 -> V_2 [ V_29 ] ,
V_20 -> V_12 -> V_3 [ V_26 ] ) ;
}
V_20 -> V_22 = V_20 -> V_24 = 0 ;
}
void
F_10 ( T_1 * V_20 , int V_30 , int V_28 )
{
V_20 -> V_27 [ V_20 -> V_24 ] . V_30 = V_30 ;
V_20 -> V_27 [ V_20 -> V_24 ++ ] . V_28 = V_28 ;
V_20 -> V_24 %= V_23 ;
if ( V_20 -> V_22 < V_23 )
V_20 -> V_22 ++ ;
}
const char *
F_11 ( T_1 * V_20 )
{
int V_31 = F_12 ( & V_20 -> V_30 ) ;
if ( V_31 >= V_20 -> V_12 -> V_4 )
return L_9 ;
return V_20 -> V_12 -> V_2 [ V_31 ] ;
}
static void
F_13 ( T_6 * V_10 )
{
#if V_32
F_3 ( V_25 L_10 ,
V_10 -> V_20 -> V_1 , V_10 ) ;
#endif
F_14 ( V_10 -> V_20 , V_10 -> V_33 , V_10 -> V_34 ) ;
}
void
F_15 ( T_1 * V_20 , T_6 * V_10 )
{
V_10 -> V_20 = V_20 ;
V_10 -> V_35 . V_19 = ( void * ) F_13 ;
V_10 -> V_35 . V_36 = ( long ) V_10 ;
#if V_32
F_3 ( V_25 L_11 , V_20 -> V_1 ,
V_10 ) ;
#endif
F_16 ( & V_10 -> V_35 ) ;
}
void
F_17 ( T_6 * V_10 )
{
#if V_32
F_3 ( V_25 L_12 , V_10 -> V_20 -> V_1 ,
V_10 ) ;
#endif
F_18 ( & V_10 -> V_35 ) ;
}
int
F_19 ( T_6 * V_10 , int V_37 , int V_28 , void * V_38 )
{
#if V_32
F_3 ( V_25 L_13 ,
V_10 -> V_20 -> V_1 , V_10 , V_37 ) ;
#endif
F_16 ( & V_10 -> V_35 ) ;
V_10 -> V_35 . V_19 = ( void * ) F_13 ;
V_10 -> V_35 . V_36 = ( long ) V_10 ;
V_10 -> V_33 = V_28 ;
V_10 -> V_34 = V_38 ;
V_10 -> V_35 . V_39 = V_40 + ( V_37 * V_41 ) / 1000 ;
F_20 ( & V_10 -> V_35 ) ;
return 0 ;
}
void
F_21 ( T_6 * V_10 , int V_37 , int V_28 , void * V_38 )
{
#if V_32
F_3 ( V_25 L_14 ,
V_10 -> V_20 -> V_1 , V_10 , V_37 ) ;
#endif
F_18 ( & V_10 -> V_35 ) ;
F_16 ( & V_10 -> V_35 ) ;
V_10 -> V_35 . V_19 = ( void * ) F_13 ;
V_10 -> V_35 . V_36 = ( long ) V_10 ;
V_10 -> V_33 = V_28 ;
V_10 -> V_34 = V_38 ;
V_10 -> V_35 . V_39 = V_40 + ( V_37 * V_41 ) / 1000 ;
F_20 ( & V_10 -> V_35 ) ;
}
