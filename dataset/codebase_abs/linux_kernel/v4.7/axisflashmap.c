static T_1 F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 V_4 ;
V_4 . V_5 [ 0 ] = * ( V_6 * ) ( V_2 -> V_7 + V_3 ) ;
return V_4 ;
}
static void F_2 ( struct V_1 * V_2 , void * V_8 ,
unsigned long V_9 , T_2 V_10 )
{
memcpy ( V_8 , ( void * ) ( V_2 -> V_7 + V_9 ) , V_10 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_11 , unsigned long V_12 )
{
* ( V_6 * ) ( V_2 -> V_7 + V_12 ) = ( V_6 ) V_11 . V_5 [ 0 ] ;
}
static struct V_13 * F_4 ( struct V_1 * V_14 )
{
struct V_13 * V_15 = NULL ;
F_5 ( V_16
L_1 ,
V_14 -> V_17 , V_14 -> V_18 , V_14 -> V_7 ) ;
#ifdef F_6
V_15 = F_7 ( L_2 , V_14 ) ;
#endif
#ifdef F_8
if ( ! V_15 )
V_15 = F_7 ( L_3 , V_14 ) ;
#endif
return V_15 ;
}
static struct V_13 * F_9 ( void )
{
struct V_13 * V_19 ;
struct V_13 * V_20 ;
struct V_13 * V_21 ;
V_19 = F_4 ( & V_22 ) ;
V_20 = F_4 ( & V_23 ) ;
if ( ! V_19 && ! V_20 ) {
return NULL ;
}
if ( V_19 && V_20 ) {
struct V_13 * V_24 [] = { V_19 , V_20 } ;
V_21 = F_10 ( V_24 , F_11 ( V_24 ) ,
L_4 ) ;
if ( ! V_21 ) {
F_5 ( V_25 L_5 ,
V_22 . V_17 , V_23 . V_17 ) ;
V_21 = V_19 ;
F_12 ( V_20 ) ;
}
} else {
V_21 = V_19 ? V_19 : V_20 ;
}
return V_21 ;
}
static int T_3 F_13 ( void )
{
struct V_13 * V_26 ;
int V_27 = 0 ;
int V_28 = 0 ;
struct V_29 * V_30 = NULL ;
struct V_31 * V_32 ;
int V_33 = 1 ;
const char V_34 [] = L_6 ;
if ( ! ( V_26 = F_9 () ) ) {
F_5 ( V_16 L_7 ) ;
} else {
F_5 ( V_16 L_8 ,
V_26 -> V_17 , V_26 -> V_18 ) ;
V_35 = V_26 ;
}
if ( V_26 ) {
V_26 -> V_36 = V_37 ;
V_30 = (struct V_29 * ) ( V_38 +
V_39 +
V_40 ) ;
}
V_28 ++ ;
if ( V_30 && ( V_30 -> V_41 == V_42 )
&& ( V_30 -> V_18 <
( V_43 * sizeof( struct V_31 ) +
V_44 ) )
&& ( * ( unsigned long * ) ( ( void * ) V_30 + sizeof( * V_30 ) +
V_30 -> V_18 -
V_44 )
== V_45 ) ) {
int V_46 = 0 ;
struct V_31 * V_47 =
(struct V_31 * )
( ( unsigned long ) V_30 + sizeof( * V_30 ) +
V_30 -> V_18 ) ;
unsigned long V_48 = V_39 ;
unsigned char * V_49 ;
unsigned long V_50 = 0 ;
V_32 = (struct V_31 * )
( ( unsigned long ) V_30 + sizeof( * V_30 ) ) ;
V_49 = ( unsigned char * ) V_32 ;
while ( V_49 <= ( unsigned char * ) V_47 ) {
V_50 += * V_49 ++ ;
V_50 += * V_49 ++ ;
V_50 += * V_49 ++ ;
V_50 += * V_49 ++ ;
}
V_46 = ( V_50 == V_30 -> V_51 ) ;
F_5 ( V_16 L_9 ,
( V_46 ? L_10 : L_11 ) , V_30 ,
V_47 ) ;
while ( V_46
&& V_32 -> V_48 != 0xffffffff
&& V_32 < V_47
&& V_28 < V_43 ) {
V_52 [ V_28 ] . V_48 = V_48 + V_32 -> V_48 ;
V_52 [ V_28 ] . V_18 = V_32 -> V_18 ;
F_5 ( V_34 , V_28 , V_52 [ V_28 ] . V_48 ,
V_52 [ V_28 ] . V_18 ) ;
V_28 ++ ;
V_32 ++ ;
}
V_33 = ! V_46 ;
}
if ( V_53 ) {
V_52 [ V_28 ] . V_17 = L_12 ;
V_52 [ V_28 ] . V_18 = V_54 ;
V_52 [ V_28 ] . V_48 = V_55 - V_38 ;
V_52 [ V_28 ] . V_56 |= V_57 ;
F_5 ( V_16
L_13 ) ;
F_5 ( V_34 , V_28 , V_52 [ V_28 ] . V_48 ,
V_52 [ V_28 ] . V_18 ) ;
V_28 ++ ;
}
#ifdef F_14
if ( V_26 ) {
V_58 . V_18 = V_26 -> V_18 ;
V_27 = F_15 ( V_26 , & V_58 , 1 ) ;
if ( V_27 )
F_16 ( L_14
L_15 ) ;
}
#endif
if ( V_26 ) {
if ( V_33 ) {
F_5 ( V_16 L_16 ) ;
V_27 = F_15 ( V_26 ,
V_59 ,
V_60 ) ;
} else {
V_27 = F_15 ( V_26 , V_52 ,
V_28 ) ;
}
if ( V_27 )
F_16 ( L_17 ) ;
}
if ( ! V_53 ) {
#if ! F_17 ( V_61 ) || ( V_62 != 0 ) || ( V_63 != 0 )
F_5 ( V_64 L_18
L_19 ) ;
F_16 ( L_20 ) ;
#else
struct V_13 * V_65 ;
V_65 = F_18 ( sizeof( struct V_13 ) , V_66 ) ;
if ( ! V_65 )
F_16 ( L_21
L_22 ) ;
F_5 ( V_16 L_23 ) ;
F_5 ( V_34 , V_28 , ( unsigned ) V_55 ,
( unsigned ) V_54 ) ;
V_27 = F_19 ( V_65 ,
( void * ) V_55 ,
V_54 ,
L_12 ) ;
if ( V_27 )
F_16 ( L_24
L_25 ) ;
#endif
}
return V_27 ;
}
