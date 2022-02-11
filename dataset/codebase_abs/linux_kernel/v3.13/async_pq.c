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
struct V_21 * V_22 = NULL ;
F_2 ( V_4 > 255 || ! ( F_7 ( V_2 , V_4 ) || F_8 ( V_2 , V_4 ) ) ) ;
if ( V_20 )
V_22 = F_9 ( V_20 -> V_23 , V_4 , V_24 ) ;
if ( V_22 &&
( V_15 <= F_10 ( V_20 , 0 ) ||
F_10 ( V_20 , V_25 ) > 0 ) &&
F_11 ( V_20 , V_3 , 0 , V_5 ) ) {
struct V_14 * V_26 ;
enum V_27 V_28 = 0 ;
unsigned char V_29 [ V_15 ] ;
int V_9 , V_30 ;
F_12 ( L_1 ,
V_31 , V_4 , V_5 ) ;
V_22 -> V_5 = V_5 ;
for ( V_9 = 0 , V_30 = 0 ; V_9 < V_15 ; V_9 ++ ) {
if ( V_2 [ V_9 ] == NULL )
continue;
V_22 -> V_32 [ V_30 ] = F_13 ( V_20 -> V_23 , V_2 [ V_9 ] , V_3 ,
V_5 , V_33 ) ;
V_29 [ V_30 ] = V_34 [ V_9 ] ;
V_22 -> V_35 ++ ;
V_30 ++ ;
}
V_22 -> V_36 ++ ;
if ( F_7 ( V_2 , V_4 ) )
V_22 -> V_32 [ V_30 ++ ] = F_13 ( V_20 -> V_23 , F_7 ( V_2 , V_4 ) ,
V_3 , V_5 , V_37 ) ;
else {
V_22 -> V_32 [ V_30 ++ ] = 0 ;
V_28 |= V_38 ;
}
V_22 -> V_36 ++ ;
if ( F_8 ( V_2 , V_4 ) )
V_22 -> V_32 [ V_30 ++ ] = F_13 ( V_20 -> V_23 , F_8 ( V_2 , V_4 ) ,
V_3 , V_5 , V_37 ) ;
else {
V_22 -> V_32 [ V_30 ++ ] = 0 ;
V_28 |= V_39 ;
}
V_26 = F_14 ( V_17 , V_29 , V_30 , V_22 , V_28 , V_7 ) ;
F_15 ( V_22 ) ;
return V_26 ;
}
F_15 ( V_22 ) ;
F_12 ( L_2 , V_31 , V_4 , V_5 ) ;
F_16 ( & V_7 -> V_40 ) ;
if ( ! F_7 ( V_2 , V_4 ) ) {
F_7 ( V_2 , V_4 ) = V_41 ;
F_2 ( V_5 + V_3 > V_42 ) ;
}
if ( ! F_8 ( V_2 , V_4 ) ) {
F_8 ( V_2 , V_4 ) = V_41 ;
F_2 ( V_5 + V_3 > V_42 ) ;
}
F_1 ( V_2 , V_3 , V_4 , V_5 , V_7 ) ;
return NULL ;
}
static inline struct V_16 *
F_17 ( struct V_6 * V_7 , struct V_1 * * V_2 , int V_4 , T_1 V_5 )
{
#ifdef F_18
return NULL ;
#endif
return F_6 ( V_7 , V_43 , NULL , 0 , V_2 ,
V_4 , V_5 ) ;
}
struct V_14 *
F_19 ( struct V_1 * * V_2 , unsigned int V_3 , int V_4 ,
T_1 V_5 , enum V_44 * V_45 , struct V_1 * V_46 ,
struct V_6 * V_7 )
{
struct V_16 * V_17 = F_17 ( V_7 , V_2 , V_4 , V_5 ) ;
struct V_19 * V_20 = V_17 ? V_17 -> V_20 : NULL ;
struct V_14 * V_26 ;
unsigned char V_29 [ V_4 - 2 ] ;
enum V_27 V_28 = V_7 -> V_47 ? V_48 : 0 ;
struct V_21 * V_22 = NULL ;
F_2 ( V_4 < 4 ) ;
if ( V_20 )
V_22 = F_9 ( V_20 -> V_23 , V_4 , V_24 ) ;
if ( V_22 && V_4 <= F_10 ( V_20 , 0 ) &&
F_11 ( V_20 , V_3 , 0 , V_5 ) ) {
struct V_20 * V_23 = V_20 -> V_23 ;
T_2 V_49 [ 2 ] ;
int V_9 , V_30 = 0 , V_15 = 0 ;
F_12 ( L_1 ,
V_31 , V_4 , V_5 ) ;
V_22 -> V_5 = V_5 ;
for ( V_9 = 0 ; V_9 < V_4 - 2 ; V_9 ++ )
if ( F_20 ( V_2 [ V_9 ] ) ) {
V_22 -> V_32 [ V_30 ] = F_13 ( V_23 , V_2 [ V_9 ] ,
V_3 , V_5 ,
V_33 ) ;
V_29 [ V_30 ] = V_34 [ V_9 ] ;
V_22 -> V_35 ++ ;
V_15 ++ ;
V_30 ++ ;
}
if ( ! F_7 ( V_2 , V_4 ) ) {
V_49 [ 0 ] = 0 ;
V_28 |= V_38 ;
} else {
V_49 [ 0 ] = F_13 ( V_23 , F_7 ( V_2 , V_4 ) ,
V_3 , V_5 ,
V_33 ) ;
V_22 -> V_32 [ V_30 ++ ] = V_49 [ 0 ] ;
V_22 -> V_35 ++ ;
}
if ( ! F_8 ( V_2 , V_4 ) ) {
V_49 [ 1 ] = 0 ;
V_28 |= V_39 ;
} else {
V_49 [ 1 ] = F_13 ( V_23 , F_8 ( V_2 , V_4 ) ,
V_3 , V_5 ,
V_33 ) ;
V_22 -> V_32 [ V_30 ++ ] = V_49 [ 1 ] ;
V_22 -> V_35 ++ ;
}
if ( V_7 -> V_50 & V_51 )
V_28 |= V_52 ;
for (; ; ) {
V_26 = V_20 -> V_53 ( V_17 , V_49 ,
V_22 -> V_32 ,
V_15 ,
V_29 ,
V_5 , V_45 ,
V_28 ) ;
if ( F_20 ( V_26 ) )
break;
F_16 ( & V_7 -> V_40 ) ;
F_21 ( V_17 ) ;
}
F_22 ( V_26 , V_22 ) ;
F_23 ( V_17 , V_26 , V_7 ) ;
return V_26 ;
} else {
struct V_1 * V_54 = F_7 ( V_2 , V_4 ) ;
struct V_1 * V_55 = F_8 ( V_2 , V_4 ) ;
enum V_56 V_57 = V_7 -> V_50 ;
T_3 V_58 = V_7 -> V_47 ;
void * V_10 = V_7 -> V_10 ;
void * V_59 = V_7 -> V_60 ;
void * V_61 , * V_62 , * V_63 ;
F_12 ( L_2 ,
V_31 , V_4 , V_5 ) ;
F_2 ( ! V_46 || ! V_10 ) ;
F_16 ( & V_7 -> V_40 ) ;
V_26 = NULL ;
* V_45 = 0 ;
if ( V_54 ) {
F_24 ( V_7 , V_64 , NULL ,
NULL , NULL , V_10 ) ;
V_26 = F_25 ( V_46 , V_2 , V_3 , V_4 - 2 , V_5 , V_7 ) ;
F_16 ( & V_26 ) ;
V_61 = F_3 ( V_54 ) + V_3 ;
V_63 = F_3 ( V_46 ) + V_3 ;
* V_45 |= ! ! memcmp ( V_61 , V_63 , V_5 ) << V_65 ;
}
if ( V_55 ) {
F_7 ( V_2 , V_4 ) = NULL ;
F_8 ( V_2 , V_4 ) = V_46 ;
F_24 ( V_7 , 0 , NULL , NULL , NULL , V_10 ) ;
V_26 = F_5 ( V_2 , V_3 , V_4 , V_5 , V_7 ) ;
F_16 ( & V_26 ) ;
V_62 = F_3 ( V_55 ) + V_3 ;
V_63 = F_3 ( V_46 ) + V_3 ;
* V_45 |= ! ! memcmp ( V_62 , V_63 , V_5 ) << V_66 ;
}
F_7 ( V_2 , V_4 ) = V_54 ;
F_8 ( V_2 , V_4 ) = V_55 ;
V_7 -> V_47 = V_58 ;
V_7 -> V_60 = V_59 ;
V_7 -> V_50 = V_57 ;
F_4 ( V_7 ) ;
return NULL ;
}
}
static int T_4 F_26 ( void )
{
V_41 = F_27 ( V_67 ) ;
if ( V_41 )
return 0 ;
F_28 ( L_3 , V_31 ) ;
return - V_68 ;
}
static void T_5 F_29 ( void )
{
F_30 ( V_41 ) ;
}
