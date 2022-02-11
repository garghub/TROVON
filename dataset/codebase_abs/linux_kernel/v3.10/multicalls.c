void F_1 ( void )
{
struct V_1 * V_2 = & F_2 ( V_1 ) ;
struct V_3 * V_4 ;
int V_5 = 0 ;
unsigned long V_6 ;
int V_7 ;
F_3 ( F_4 () ) ;
F_5 ( V_6 ) ;
F_6 ( V_2 -> V_8 , V_2 -> V_9 , V_2 -> V_10 ) ;
switch ( V_2 -> V_8 ) {
case 0 :
F_3 ( V_2 -> V_9 != 0 ) ;
break;
case 1 :
V_4 = & V_2 -> V_11 [ 0 ] ;
V_4 -> V_12 = F_7 ( V_4 -> V_13 ,
V_4 -> args [ 0 ] , V_4 -> args [ 1 ] , V_4 -> args [ 2 ] ,
V_4 -> args [ 3 ] , V_4 -> args [ 4 ] ) ;
V_5 = V_4 -> V_12 < 0 ;
break;
default:
#if V_14
memcpy ( V_2 -> V_15 , V_2 -> V_11 ,
V_2 -> V_8 * sizeof( struct V_3 ) ) ;
#endif
if ( F_8 ( V_2 -> V_11 , V_2 -> V_8 ) != 0 )
F_9 () ;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 ; V_7 ++ )
if ( V_2 -> V_11 [ V_7 ] . V_12 < 0 )
V_5 ++ ;
#if V_14
if ( V_5 ) {
F_10 ( V_16 L_1 ,
V_5 , F_11 () ) ;
F_12 () ;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 ; V_7 ++ ) {
F_10 ( V_17 L_2 ,
V_7 + 1 , V_2 -> V_8 ,
V_2 -> V_15 [ V_7 ] . V_13 ,
V_2 -> V_15 [ V_7 ] . args [ 0 ] ,
V_2 -> V_11 [ V_7 ] . V_12 ,
V_2 -> V_18 [ V_7 ] ) ;
}
}
#endif
}
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_10 ; V_7 ++ ) {
struct V_19 * V_20 = & V_2 -> V_21 [ V_7 ] ;
(* V_20 -> V_22 )( V_20 -> V_23 ) ;
}
V_2 -> V_10 = 0 ;
F_13 ( V_6 ) ;
F_14 ( V_5 ) ;
}
struct V_24 F_15 ( T_1 args )
{
struct V_1 * V_2 = & F_2 ( V_1 ) ;
struct V_24 V_5 ;
unsigned V_9 = F_16 ( V_2 -> V_9 , sizeof( V_25 ) ) ;
F_17 ( args ) ;
F_3 ( F_4 () ) ;
F_3 ( V_2 -> V_9 >= V_26 ) ;
if ( F_18 ( V_2 -> V_8 == V_27 ||
( V_9 + args ) >= V_26 ) ) {
F_19 ( ( V_2 -> V_8 == V_27 ) ?
V_28 : V_29 ) ;
F_1 () ;
V_9 = F_16 ( V_2 -> V_9 , sizeof( V_25 ) ) ;
}
V_5 . V_4 = & V_2 -> V_11 [ V_2 -> V_8 ] ;
#if V_14
V_2 -> V_18 [ V_2 -> V_8 ] = F_20 ( 0 ) ;
#endif
V_2 -> V_8 ++ ;
V_5 . args = & V_2 -> args [ V_9 ] ;
V_2 -> V_9 = V_9 + args ;
F_3 ( V_2 -> V_9 >= V_26 ) ;
return V_5 ;
}
struct V_24 F_21 ( unsigned long V_13 , T_1 V_30 )
{
struct V_1 * V_2 = & F_2 ( V_1 ) ;
struct V_24 V_5 = { NULL , NULL } ;
F_3 ( F_4 () ) ;
F_3 ( V_2 -> V_9 >= V_26 ) ;
if ( F_18 ( V_2 -> V_8 == 0 ||
V_2 -> V_11 [ V_2 -> V_8 - 1 ] . V_13 != V_13 ) ) {
F_22 ( V_13 , V_30 , V_31 ) ;
goto V_32;
}
if ( F_18 ( ( V_2 -> V_9 + V_30 ) >= V_26 ) ) {
F_22 ( V_13 , V_30 , V_33 ) ;
goto V_32;
}
V_5 . V_4 = & V_2 -> V_11 [ V_2 -> V_8 - 1 ] ;
V_5 . args = & V_2 -> args [ V_2 -> V_9 ] ;
V_2 -> V_9 += V_30 ;
F_3 ( V_2 -> V_9 >= V_26 ) ;
F_22 ( V_13 , V_30 , V_34 ) ;
V_32:
return V_5 ;
}
void F_23 ( void (* V_22)( void * ) , void * V_23 )
{
struct V_1 * V_2 = & F_2 ( V_1 ) ;
struct V_19 * V_20 ;
if ( V_2 -> V_10 == V_27 ) {
F_19 ( V_35 ) ;
F_1 () ;
}
F_24 ( V_22 , V_23 ) ;
V_20 = & V_2 -> V_21 [ V_2 -> V_10 ++ ] ;
V_20 -> V_22 = V_22 ;
V_20 -> V_23 = V_23 ;
}
