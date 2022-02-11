void
F_1 ( struct V_1 * * V_2 , unsigned int V_3 , int V_4 ,
T_1 V_5 , struct V_6 * V_7 )
{
void * * V_8 ;
int V_9 ;
int V_10 = - 1 , V_11 = V_4 - 3 ;
if ( V_7 -> V_12 )
V_8 = V_7 -> V_12 ;
else
V_8 = ( void * * ) V_2 ;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ ) {
if ( V_2 [ V_9 ] == NULL ) {
F_2 ( V_9 > V_4 - 3 ) ;
V_8 [ V_9 ] = ( void * ) V_13 ;
} else {
V_8 [ V_9 ] = F_3 ( V_2 [ V_9 ] ) + V_3 ;
if ( V_9 < V_4 - 2 ) {
V_11 = V_9 ;
if ( V_10 == - 1 )
V_10 = V_9 ;
}
}
}
if ( V_7 -> V_14 & V_15 ) {
F_2 ( ! V_16 . V_17 ) ;
if ( V_10 >= 0 )
V_16 . V_17 ( V_4 , V_10 , V_11 , V_5 , V_8 ) ;
} else
V_16 . V_18 ( V_4 , V_5 , V_8 ) ;
F_4 ( V_7 ) ;
}
struct V_19 *
F_5 ( struct V_1 * * V_2 , unsigned int V_3 , int V_4 ,
T_1 V_5 , struct V_6 * V_7 )
{
int V_20 = V_4 - 2 ;
struct V_21 * V_22 = F_6 ( V_7 , V_23 ,
& F_7 ( V_2 , V_4 ) , 2 ,
V_2 , V_20 , V_5 ) ;
struct V_24 * V_25 = V_22 ? V_22 -> V_25 : NULL ;
struct V_26 * V_27 = NULL ;
F_2 ( V_4 > 255 || ! ( F_7 ( V_2 , V_4 ) || F_8 ( V_2 , V_4 ) ) ) ;
if ( V_25 )
V_27 = F_9 ( V_25 -> V_28 , V_4 , V_29 ) ;
if ( V_27 && ! ( V_7 -> V_14 & V_15 ) &&
( V_20 <= F_10 ( V_25 , 0 ) ||
F_10 ( V_25 , V_30 ) > 0 ) &&
F_11 ( V_25 , V_3 , 0 , V_5 ) ) {
struct V_19 * V_31 ;
enum V_32 V_33 = 0 ;
unsigned char V_34 [ V_20 ] ;
int V_9 , V_35 ;
F_12 ( L_1 ,
V_36 , V_4 , V_5 ) ;
V_27 -> V_5 = V_5 ;
for ( V_9 = 0 , V_35 = 0 ; V_9 < V_20 ; V_9 ++ ) {
if ( V_2 [ V_9 ] == NULL )
continue;
V_27 -> V_37 [ V_35 ] = F_13 ( V_25 -> V_28 , V_2 [ V_9 ] , V_3 ,
V_5 , V_38 ) ;
V_34 [ V_35 ] = V_39 [ V_9 ] ;
V_27 -> V_40 ++ ;
V_35 ++ ;
}
V_27 -> V_41 ++ ;
if ( F_7 ( V_2 , V_4 ) )
V_27 -> V_37 [ V_35 ++ ] = F_13 ( V_25 -> V_28 , F_7 ( V_2 , V_4 ) ,
V_3 , V_5 , V_42 ) ;
else {
V_27 -> V_37 [ V_35 ++ ] = 0 ;
V_33 |= V_43 ;
}
V_27 -> V_41 ++ ;
if ( F_8 ( V_2 , V_4 ) )
V_27 -> V_37 [ V_35 ++ ] = F_13 ( V_25 -> V_28 , F_8 ( V_2 , V_4 ) ,
V_3 , V_5 , V_42 ) ;
else {
V_27 -> V_37 [ V_35 ++ ] = 0 ;
V_33 |= V_44 ;
}
V_31 = F_14 ( V_22 , V_34 , V_35 , V_27 , V_33 , V_7 ) ;
F_15 ( V_27 ) ;
return V_31 ;
}
F_15 ( V_27 ) ;
F_12 ( L_2 , V_36 , V_4 , V_5 ) ;
F_16 ( & V_7 -> V_45 ) ;
if ( ! F_7 ( V_2 , V_4 ) ) {
F_7 ( V_2 , V_4 ) = V_46 ;
F_2 ( V_5 + V_3 > V_47 ) ;
}
if ( ! F_8 ( V_2 , V_4 ) ) {
F_8 ( V_2 , V_4 ) = V_46 ;
F_2 ( V_5 + V_3 > V_47 ) ;
}
F_1 ( V_2 , V_3 , V_4 , V_5 , V_7 ) ;
return NULL ;
}
static inline struct V_21 *
F_17 ( struct V_6 * V_7 , struct V_1 * * V_2 , int V_4 , T_1 V_5 )
{
#ifdef F_18
return NULL ;
#endif
return F_6 ( V_7 , V_48 , NULL , 0 , V_2 ,
V_4 , V_5 ) ;
}
struct V_19 *
F_19 ( struct V_1 * * V_2 , unsigned int V_3 , int V_4 ,
T_1 V_5 , enum V_49 * V_50 , struct V_1 * V_51 ,
struct V_6 * V_7 )
{
struct V_21 * V_22 = F_17 ( V_7 , V_2 , V_4 , V_5 ) ;
struct V_24 * V_25 = V_22 ? V_22 -> V_25 : NULL ;
struct V_19 * V_31 ;
unsigned char V_34 [ V_4 - 2 ] ;
enum V_32 V_33 = V_7 -> V_52 ? V_53 : 0 ;
struct V_26 * V_27 = NULL ;
F_2 ( V_4 < 4 ) ;
if ( V_25 )
V_27 = F_9 ( V_25 -> V_28 , V_4 , V_29 ) ;
if ( V_27 && V_4 <= F_10 ( V_25 , 0 ) &&
F_11 ( V_25 , V_3 , 0 , V_5 ) ) {
struct V_25 * V_28 = V_25 -> V_28 ;
T_2 V_54 [ 2 ] ;
int V_9 , V_35 = 0 , V_20 = 0 ;
F_12 ( L_1 ,
V_36 , V_4 , V_5 ) ;
V_27 -> V_5 = V_5 ;
for ( V_9 = 0 ; V_9 < V_4 - 2 ; V_9 ++ )
if ( F_20 ( V_2 [ V_9 ] ) ) {
V_27 -> V_37 [ V_35 ] = F_13 ( V_28 , V_2 [ V_9 ] ,
V_3 , V_5 ,
V_38 ) ;
V_34 [ V_35 ] = V_39 [ V_9 ] ;
V_27 -> V_40 ++ ;
V_20 ++ ;
V_35 ++ ;
}
if ( ! F_7 ( V_2 , V_4 ) ) {
V_54 [ 0 ] = 0 ;
V_33 |= V_43 ;
} else {
V_54 [ 0 ] = F_13 ( V_28 , F_7 ( V_2 , V_4 ) ,
V_3 , V_5 ,
V_38 ) ;
V_27 -> V_37 [ V_35 ++ ] = V_54 [ 0 ] ;
V_27 -> V_40 ++ ;
}
if ( ! F_8 ( V_2 , V_4 ) ) {
V_54 [ 1 ] = 0 ;
V_33 |= V_44 ;
} else {
V_54 [ 1 ] = F_13 ( V_28 , F_8 ( V_2 , V_4 ) ,
V_3 , V_5 ,
V_38 ) ;
V_27 -> V_37 [ V_35 ++ ] = V_54 [ 1 ] ;
V_27 -> V_40 ++ ;
}
if ( V_7 -> V_14 & V_55 )
V_33 |= V_56 ;
for (; ; ) {
V_31 = V_25 -> V_57 ( V_22 , V_54 ,
V_27 -> V_37 ,
V_20 ,
V_34 ,
V_5 , V_50 ,
V_33 ) ;
if ( F_20 ( V_31 ) )
break;
F_16 ( & V_7 -> V_45 ) ;
F_21 ( V_22 ) ;
}
F_22 ( V_31 , V_27 ) ;
F_23 ( V_22 , V_31 , V_7 ) ;
} else {
struct V_1 * V_58 = F_7 ( V_2 , V_4 ) ;
struct V_1 * V_59 = F_8 ( V_2 , V_4 ) ;
enum V_60 V_61 = V_7 -> V_14 ;
T_3 V_62 = V_7 -> V_52 ;
void * V_12 = V_7 -> V_12 ;
void * V_63 = V_7 -> V_64 ;
void * V_65 , * V_66 , * V_67 ;
F_12 ( L_2 ,
V_36 , V_4 , V_5 ) ;
F_2 ( ! V_51 || ! V_12 ) ;
F_16 ( & V_7 -> V_45 ) ;
V_31 = NULL ;
* V_50 = 0 ;
if ( V_58 ) {
F_24 ( V_7 , V_68 , NULL ,
NULL , NULL , V_12 ) ;
V_31 = F_25 ( V_51 , V_2 , V_3 , V_4 - 2 , V_5 , V_7 ) ;
F_16 ( & V_31 ) ;
V_65 = F_3 ( V_58 ) + V_3 ;
V_67 = F_3 ( V_51 ) + V_3 ;
* V_50 |= ! ! memcmp ( V_65 , V_67 , V_5 ) << V_69 ;
}
if ( V_59 ) {
F_7 ( V_2 , V_4 ) = NULL ;
F_8 ( V_2 , V_4 ) = V_51 ;
F_24 ( V_7 , 0 , NULL , NULL , NULL , V_12 ) ;
V_31 = F_5 ( V_2 , V_3 , V_4 , V_5 , V_7 ) ;
F_16 ( & V_31 ) ;
V_66 = F_3 ( V_59 ) + V_3 ;
V_67 = F_3 ( V_51 ) + V_3 ;
* V_50 |= ! ! memcmp ( V_66 , V_67 , V_5 ) << V_70 ;
}
F_7 ( V_2 , V_4 ) = V_58 ;
F_8 ( V_2 , V_4 ) = V_59 ;
V_7 -> V_52 = V_62 ;
V_7 -> V_64 = V_63 ;
V_7 -> V_14 = V_61 ;
F_4 ( V_7 ) ;
V_31 = NULL ;
}
F_15 ( V_27 ) ;
return V_31 ;
}
static int T_4 F_26 ( void )
{
V_46 = F_27 ( V_71 ) ;
if ( V_46 )
return 0 ;
F_28 ( L_3 , V_36 ) ;
return - V_72 ;
}
static void T_5 F_29 ( void )
{
F_30 ( V_46 ) ;
}
