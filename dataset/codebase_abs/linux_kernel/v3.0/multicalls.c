static inline void F_1 ( void )
{
if ( F_2 ( V_1 ) ) {
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_1 = 0 ;
}
}
static void F_3 ( const struct V_3 * V_4 )
{
int V_5 ;
F_1 () ;
V_2 . V_6 ++ ;
V_2 . V_7 += V_4 -> V_8 ;
V_2 . V_9 += V_4 -> V_10 ;
V_2 . V_11 [ V_4 -> V_8 ] ++ ;
for( V_5 = 0 ; V_5 < V_4 -> V_8 ; V_5 ++ ) {
unsigned V_12 = V_4 -> V_13 [ V_5 ] . V_12 ;
if ( V_12 < V_14 )
V_2 . V_15 [ V_12 ] ++ ;
}
}
static void F_4 ( enum V_16 V_17 )
{
F_1 () ;
V_2 . V_18 [ V_17 ] ++ ;
}
static inline void F_3 ( const struct V_3 * V_4 )
{
}
static inline void F_4 ( enum V_16 V_17 )
{
}
void F_5 ( void )
{
struct V_3 * V_19 = & F_6 ( V_3 ) ;
int V_20 = 0 ;
unsigned long V_21 ;
int V_5 ;
F_7 ( F_8 () ) ;
F_9 ( V_21 ) ;
F_3 ( V_19 ) ;
if ( V_19 -> V_8 ) {
#if V_22
memcpy ( V_19 -> V_23 , V_19 -> V_13 ,
V_19 -> V_8 * sizeof( struct V_24 ) ) ;
#endif
if ( F_10 ( V_19 -> V_13 , V_19 -> V_8 ) != 0 )
F_11 () ;
for ( V_5 = 0 ; V_5 < V_19 -> V_8 ; V_5 ++ )
if ( V_19 -> V_13 [ V_5 ] . V_25 < 0 )
V_20 ++ ;
#if V_22
if ( V_20 ) {
F_12 ( V_26 L_1 ,
V_20 , F_13 () ) ;
F_14 () ;
for ( V_5 = 0 ; V_5 < V_19 -> V_8 ; V_5 ++ ) {
F_12 ( V_27 L_2 ,
V_5 + 1 , V_19 -> V_8 ,
V_19 -> V_23 [ V_5 ] . V_12 ,
V_19 -> V_23 [ V_5 ] . args [ 0 ] ,
V_19 -> V_13 [ V_5 ] . V_25 ,
V_19 -> V_28 [ V_5 ] ) ;
}
}
#endif
V_19 -> V_8 = 0 ;
V_19 -> V_10 = 0 ;
} else
F_7 ( V_19 -> V_10 != 0 ) ;
for ( V_5 = 0 ; V_5 < V_19 -> V_29 ; V_5 ++ ) {
struct V_30 * V_31 = & V_19 -> V_32 [ V_5 ] ;
(* V_31 -> V_33 )( V_31 -> V_34 ) ;
}
V_19 -> V_29 = 0 ;
F_15 ( V_21 ) ;
F_16 ( V_20 ) ;
}
struct V_35 F_17 ( T_1 args )
{
struct V_3 * V_19 = & F_6 ( V_3 ) ;
struct V_35 V_20 ;
unsigned V_10 = F_18 ( V_19 -> V_10 , sizeof( V_36 ) ) ;
F_7 ( F_8 () ) ;
F_7 ( V_19 -> V_10 >= V_37 ) ;
if ( V_19 -> V_8 == V_38 ||
( V_10 + args ) >= V_37 ) {
F_4 ( V_19 -> V_8 == V_38 ? V_39 : V_40 ) ;
F_5 () ;
V_10 = F_18 ( V_19 -> V_10 , sizeof( V_36 ) ) ;
}
V_20 . V_4 = & V_19 -> V_13 [ V_19 -> V_8 ] ;
#ifdef V_22
V_19 -> V_28 [ V_19 -> V_8 ] = F_19 ( 0 ) ;
#endif
V_19 -> V_8 ++ ;
V_20 . args = & V_19 -> args [ V_10 ] ;
V_19 -> V_10 = V_10 + args ;
F_7 ( V_19 -> V_10 >= V_37 ) ;
return V_20 ;
}
struct V_35 F_20 ( unsigned long V_12 , T_1 V_41 )
{
struct V_3 * V_19 = & F_6 ( V_3 ) ;
struct V_35 V_20 = { NULL , NULL } ;
F_7 ( F_8 () ) ;
F_7 ( V_19 -> V_10 >= V_37 ) ;
if ( V_19 -> V_8 == 0 )
return V_20 ;
if ( V_19 -> V_13 [ V_19 -> V_8 - 1 ] . V_12 != V_12 )
return V_20 ;
if ( ( V_19 -> V_10 + V_41 ) >= V_37 )
return V_20 ;
V_20 . V_4 = & V_19 -> V_13 [ V_19 -> V_8 - 1 ] ;
V_20 . args = & V_19 -> args [ V_19 -> V_10 ] ;
V_19 -> V_10 += V_41 ;
F_7 ( V_19 -> V_10 >= V_37 ) ;
return V_20 ;
}
void F_21 ( void (* V_33)( void * ) , void * V_34 )
{
struct V_3 * V_19 = & F_6 ( V_3 ) ;
struct V_30 * V_31 ;
if ( V_19 -> V_29 == V_38 ) {
F_4 ( V_42 ) ;
F_5 () ;
}
V_31 = & V_19 -> V_32 [ V_19 -> V_29 ++ ] ;
V_31 -> V_33 = V_33 ;
V_31 -> V_34 = V_34 ;
}
static int T_2 F_22 ( void )
{
struct V_43 * V_44 = F_23 () ;
if ( V_44 == NULL )
return - V_45 ;
V_46 = F_24 ( L_3 , V_44 ) ;
F_25 ( L_4 , 0644 , V_46 , & V_1 ) ;
F_26 ( L_5 , 0444 , V_46 , & V_2 . V_6 ) ;
F_26 ( L_6 , 0444 , V_46 , & V_2 . V_7 ) ;
F_26 ( L_7 , 0444 , V_46 , & V_2 . V_9 ) ;
F_27 ( L_8 , 0444 , V_46 ,
V_2 . V_11 , V_38 ) ;
F_27 ( L_9 , 0444 , V_46 ,
V_2 . V_15 , V_14 ) ;
F_27 ( L_10 , 0444 , V_46 ,
V_2 . V_18 , V_47 ) ;
return 0 ;
}
