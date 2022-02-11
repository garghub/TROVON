static inline int F_1 ( int type )
{
return type >= V_1 &&
type <= V_2 ;
}
static struct V_3 * * F_2 ( struct V_4 * V_5 ,
int type ,
T_1 V_6 )
{
int V_7 ;
struct V_3 * * V_8 , * * free = NULL ;
F_3 ( V_6 == V_9 ) ;
F_3 ( type < V_10 ||
type > V_11 ) ;
F_4 ( & V_5 -> V_12 ) ;
V_8 = V_5 -> V_8 ;
F_5 ( & V_5 -> V_12 ) ;
if ( F_6 ( ! V_8 ) ) {
V_8 = F_7 ( sizeof( struct V_3 * ) *
V_13 *
V_5 -> V_14 ,
V_15 ) ;
if ( ! V_8 ) {
F_8 ( - V_16 ) ;
return NULL ;
}
F_4 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_8 ) {
free = V_8 ;
V_8 = V_5 -> V_8 ;
} else
V_5 -> V_8 = V_8 ;
F_5 ( & V_5 -> V_12 ) ;
F_9 ( free ) ;
}
V_7 = ( V_6 * V_13 ) +
( type - V_10 ) ;
return & V_8 [ V_7 ] ;
}
struct V_3 * F_10 ( struct V_4 * V_5 ,
int type ,
T_1 V_6 )
{
struct V_3 * V_3 = NULL ;
struct V_3 * * V_17 = NULL ;
if ( F_1 ( type ) ) {
V_17 = & ( V_5 -> V_18 [ type ] ) ;
} else
V_17 = F_2 ( V_5 , type , V_6 ) ;
F_11 ( & V_5 -> V_19 ) ;
if ( V_17 && ( ( V_3 = * V_17 ) != NULL ) ) {
V_3 = F_12 ( V_3 ) ;
F_13 ( & V_5 -> V_19 ) ;
F_3 ( ! V_3 ) ;
return V_3 ;
}
V_3 = F_14 ( V_5 , type , V_6 ) ;
if ( V_17 && V_3 ) {
* V_17 = F_12 ( V_3 ) ;
F_3 ( ! * V_17 ) ;
}
F_13 ( & V_5 -> V_19 ) ;
return V_3 ;
}
static struct V_3 * F_14 ( struct V_4 * V_5 ,
int type ,
T_1 V_6 )
{
char V_20 [ 40 ] ;
struct V_3 * V_3 = NULL ;
T_2 V_21 ;
int V_22 = 0 ;
F_15 ( V_20 ,
sizeof( V_20 ) ,
type , V_6 ) ;
V_22 = F_16 ( V_5 -> V_23 , V_20 ,
strlen ( V_20 ) , & V_21 ) ;
if ( V_22 < 0 ) {
goto V_24;
}
V_3 = F_17 ( V_5 , V_21 , V_25 , type ) ;
if ( F_18 ( V_3 ) ) {
F_8 ( F_19 ( V_3 ) ) ;
V_3 = NULL ;
goto V_24;
}
#ifdef F_20
if ( type == V_26 ||
type == V_27 ||
type == V_28 ) {
F_21 ( V_3 ) -> V_29 . V_30 . V_31 = NULL ;
} else {
F_22 ( & F_21 ( V_3 ) -> V_29 .
V_30 ,
V_32 [ type ] . V_33 ,
& V_34 [ type ] , 0 ) ;
}
#endif
V_24:
return V_3 ;
}
