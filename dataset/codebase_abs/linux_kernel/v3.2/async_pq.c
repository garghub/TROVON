void
F_1 ( struct V_1 * * V_2 , unsigned int V_3 , int V_4 ,
T_1 V_5 , struct V_6 * V_7 )
{
void * * V_8 ;
int V_9 ;
if ( V_7 -> V_10 )
V_8 = V_7 -> V_10 ;
else
V_8 = ( void * * ) V_2 ;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ ) {
if ( V_2 [ V_9 ] == NULL ) {
F_2 ( V_9 > V_4 - 3 ) ;
V_8 [ V_9 ] = ( void * ) V_11 ;
} else
V_8 [ V_9 ] = F_3 ( V_2 [ V_9 ] ) + V_3 ;
}
V_12 . V_13 ( V_4 , V_5 , V_8 ) ;
F_4 ( V_7 ) ;
}
struct V_14 *
F_5 ( struct V_1 * * V_2 , unsigned int V_3 , int V_4 ,
T_1 V_5 , struct V_6 * V_7 )
{
int V_15 = V_4 - 2 ;
struct V_16 * V_17 = F_6 ( V_7 , V_18 ,
& F_7 ( V_2 , V_4 ) , 2 ,
V_2 , V_15 , V_5 ) ;
struct V_19 * V_20 = V_17 ? V_17 -> V_20 : NULL ;
T_2 * V_21 = NULL ;
F_2 ( V_4 > 255 || ! ( F_7 ( V_2 , V_4 ) || F_8 ( V_2 , V_4 ) ) ) ;
if ( V_7 -> V_10 )
V_21 = V_7 -> V_10 ;
else if ( sizeof( T_2 ) <= sizeof( struct V_1 * ) )
V_21 = ( T_2 * ) V_2 ;
if ( V_21 && V_20 &&
( V_15 <= F_9 ( V_20 , 0 ) ||
F_9 ( V_20 , V_22 ) > 0 ) &&
F_10 ( V_20 , V_3 , 0 , V_5 ) ) {
F_11 ( L_1 ,
V_23 , V_4 , V_5 ) ;
return F_12 ( V_17 , V_2 , V_24 , V_3 ,
V_4 , V_5 , V_21 , V_7 ) ;
}
F_11 ( L_2 , V_23 , V_4 , V_5 ) ;
F_13 ( & V_7 -> V_25 ) ;
if ( ! F_7 ( V_2 , V_4 ) ) {
F_7 ( V_2 , V_4 ) = V_26 ;
F_2 ( V_5 + V_3 > V_27 ) ;
}
if ( ! F_8 ( V_2 , V_4 ) ) {
F_8 ( V_2 , V_4 ) = V_26 ;
F_2 ( V_5 + V_3 > V_27 ) ;
}
F_1 ( V_2 , V_3 , V_4 , V_5 , V_7 ) ;
return NULL ;
}
static inline struct V_16 *
F_14 ( struct V_6 * V_7 , struct V_1 * * V_2 , int V_4 , T_1 V_5 )
{
#ifdef F_15
return NULL ;
#endif
return F_6 ( V_7 , V_28 , NULL , 0 , V_2 ,
V_4 , V_5 ) ;
}
struct V_14 *
F_16 ( struct V_1 * * V_2 , unsigned int V_3 , int V_4 ,
T_1 V_5 , enum V_29 * V_30 , struct V_1 * V_31 ,
struct V_6 * V_7 )
{
struct V_16 * V_17 = F_14 ( V_7 , V_2 , V_4 , V_5 ) ;
struct V_19 * V_20 = V_17 ? V_17 -> V_20 : NULL ;
struct V_14 * V_32 ;
unsigned char V_33 [ V_4 - 2 ] ;
enum V_34 V_35 = V_7 -> V_36 ? V_37 : 0 ;
T_2 * V_21 = NULL ;
int V_15 = 0 ;
F_2 ( V_4 < 4 ) ;
if ( V_7 -> V_10 )
V_21 = V_7 -> V_10 ;
else if ( sizeof( T_2 ) <= sizeof( struct V_1 * ) )
V_21 = ( T_2 * ) V_2 ;
if ( V_21 && V_20 && V_4 <= F_9 ( V_20 , 0 ) &&
F_10 ( V_20 , V_3 , 0 , V_5 ) ) {
struct V_20 * V_38 = V_20 -> V_38 ;
T_2 * V_39 = & V_21 [ V_4 - 2 ] ;
int V_9 ;
F_11 ( L_1 ,
V_23 , V_4 , V_5 ) ;
if ( ! F_7 ( V_2 , V_4 ) )
V_35 |= V_40 ;
else
V_39 [ 0 ] = F_17 ( V_38 , F_7 ( V_2 , V_4 ) ,
V_3 , V_5 ,
V_41 ) ;
if ( ! F_8 ( V_2 , V_4 ) )
V_35 |= V_42 ;
else
V_39 [ 1 ] = F_17 ( V_38 , F_8 ( V_2 , V_4 ) ,
V_3 , V_5 ,
V_41 ) ;
if ( V_7 -> V_43 & V_44 )
V_35 |= V_45 ;
for ( V_9 = 0 ; V_9 < V_4 - 2 ; V_9 ++ )
if ( F_18 ( V_2 [ V_9 ] ) ) {
V_21 [ V_15 ] = F_17 ( V_38 , V_2 [ V_9 ] ,
V_3 , V_5 ,
V_41 ) ;
V_33 [ V_15 ] = V_24 [ V_9 ] ;
V_15 ++ ;
}
for (; ; ) {
V_32 = V_20 -> V_46 ( V_17 , V_39 , V_21 ,
V_15 ,
V_33 ,
V_5 , V_30 ,
V_35 ) ;
if ( F_18 ( V_32 ) )
break;
F_13 ( & V_7 -> V_25 ) ;
F_19 ( V_17 ) ;
}
F_20 ( V_17 , V_32 , V_7 ) ;
return V_32 ;
} else {
struct V_1 * V_47 = F_7 ( V_2 , V_4 ) ;
struct V_1 * V_48 = F_8 ( V_2 , V_4 ) ;
enum V_49 V_50 = V_7 -> V_43 ;
T_3 V_51 = V_7 -> V_36 ;
void * V_10 = V_7 -> V_10 ;
void * V_52 = V_7 -> V_53 ;
void * V_54 , * V_55 , * V_56 ;
F_11 ( L_2 ,
V_23 , V_4 , V_5 ) ;
F_2 ( ! V_31 || ! V_10 ) ;
F_13 ( & V_7 -> V_25 ) ;
V_32 = NULL ;
* V_30 = 0 ;
if ( V_47 ) {
F_21 ( V_7 , V_57 , NULL ,
NULL , NULL , V_10 ) ;
V_32 = F_22 ( V_31 , V_2 , V_3 , V_4 - 2 , V_5 , V_7 ) ;
F_13 ( & V_32 ) ;
V_54 = F_3 ( V_47 ) + V_3 ;
V_56 = F_3 ( V_31 ) + V_3 ;
* V_30 |= ! ! memcmp ( V_54 , V_56 , V_5 ) << V_58 ;
}
if ( V_48 ) {
F_7 ( V_2 , V_4 ) = NULL ;
F_8 ( V_2 , V_4 ) = V_31 ;
F_21 ( V_7 , 0 , NULL , NULL , NULL , V_10 ) ;
V_32 = F_5 ( V_2 , V_3 , V_4 , V_5 , V_7 ) ;
F_13 ( & V_32 ) ;
V_55 = F_3 ( V_48 ) + V_3 ;
V_56 = F_3 ( V_31 ) + V_3 ;
* V_30 |= ! ! memcmp ( V_55 , V_56 , V_5 ) << V_59 ;
}
F_7 ( V_2 , V_4 ) = V_47 ;
F_8 ( V_2 , V_4 ) = V_48 ;
V_7 -> V_36 = V_51 ;
V_7 -> V_53 = V_52 ;
V_7 -> V_43 = V_50 ;
F_4 ( V_7 ) ;
return NULL ;
}
}
static int T_4 F_23 ( void )
{
V_26 = F_24 ( V_60 ) ;
if ( V_26 )
return 0 ;
F_25 ( L_3 , V_23 ) ;
return - V_61 ;
}
static void T_5 F_26 ( void )
{
F_27 ( V_26 ) ;
}
