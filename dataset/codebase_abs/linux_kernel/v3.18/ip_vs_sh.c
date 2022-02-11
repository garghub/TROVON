static inline bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) <= 0 ||
V_2 -> V_4 & V_5 ;
}
static inline unsigned int
F_3 ( int V_6 , const union V_7 * V_8 ,
T_1 V_9 , unsigned int V_10 )
{
T_2 V_11 = V_8 -> V_12 ;
#ifdef F_4
if ( V_6 == V_13 )
V_11 = V_8 -> V_14 [ 0 ] ^ V_8 -> V_14 [ 1 ] ^
V_8 -> V_14 [ 2 ] ^ V_8 -> V_14 [ 3 ] ;
#endif
return ( V_10 + ( F_5 ( V_9 ) + F_6 ( V_11 ) ) * 2654435761UL ) &
V_15 ;
}
static inline struct V_1 *
F_7 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const union V_7 * V_8 , T_1 V_9 )
{
unsigned int V_20 = F_3 ( V_17 -> V_6 , V_8 , V_9 , 0 ) ;
struct V_1 * V_2 = F_8 ( V_19 -> V_21 [ V_20 ] . V_2 ) ;
return ( ! V_2 || F_1 ( V_2 ) ) ? NULL : V_2 ;
}
static inline struct V_1 *
F_9 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const union V_7 * V_8 , T_1 V_9 )
{
unsigned int V_10 , V_22 ;
unsigned int V_20 , V_23 ;
struct V_1 * V_2 ;
V_23 = F_3 ( V_17 -> V_6 , V_8 , V_9 , 0 ) ;
V_2 = F_8 ( V_19 -> V_21 [ V_23 ] . V_2 ) ;
if ( ! V_2 )
return NULL ;
if ( ! F_1 ( V_2 ) )
return V_2 ;
F_10 ( 6 , L_1 ,
F_11 ( V_2 -> V_6 , & V_2 -> V_8 ) , F_5 ( V_2 -> V_9 ) ) ;
for ( V_10 = 0 ; V_10 < V_24 ; V_10 ++ ) {
V_22 = ( V_10 + V_23 ) % V_24 ;
V_20 = F_3 ( V_17 -> V_6 , V_8 , V_9 , V_22 ) ;
V_2 = F_8 ( V_19 -> V_21 [ V_20 ] . V_2 ) ;
if ( ! V_2 )
break;
if ( ! F_1 ( V_2 ) )
return V_2 ;
F_10 ( 6 , L_2
L_3 ,
F_11 ( V_2 -> V_6 , & V_2 -> V_8 ) ,
F_5 ( V_2 -> V_9 ) , V_22 ) ;
}
return NULL ;
}
static int
F_12 ( struct V_18 * V_19 , struct V_16 * V_17 )
{
int V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_1 * V_2 ;
int V_30 ;
bool V_31 ;
V_27 = & V_19 -> V_21 [ 0 ] ;
V_29 = & V_17 -> V_32 ;
V_31 = F_13 ( V_29 ) ;
V_30 = 0 ;
for ( V_25 = 0 ; V_25 < V_24 ; V_25 ++ ) {
V_2 = F_14 ( V_27 -> V_2 , 1 ) ;
if ( V_2 )
F_15 ( V_2 ) ;
if ( V_31 )
F_16 ( V_27 -> V_2 , NULL ) ;
else {
if ( V_29 == & V_17 -> V_32 )
V_29 = V_29 -> V_33 ;
V_2 = F_17 ( V_29 , struct V_1 , V_34 ) ;
F_18 ( V_2 ) ;
F_16 ( V_27 -> V_2 , V_2 ) ;
F_10 ( 6 , L_4 ,
V_25 , F_11 ( V_2 -> V_6 , & V_2 -> V_8 ) ,
F_2 ( & V_2 -> V_3 ) ) ;
if ( ++ V_30 >= F_2 ( & V_2 -> V_3 ) ) {
V_29 = V_29 -> V_33 ;
V_30 = 0 ;
}
}
V_27 ++ ;
}
return 0 ;
}
static void F_19 ( struct V_18 * V_19 )
{
int V_25 ;
struct V_26 * V_27 ;
struct V_1 * V_2 ;
V_27 = & V_19 -> V_21 [ 0 ] ;
for ( V_25 = 0 ; V_25 < V_24 ; V_25 ++ ) {
V_2 = F_14 ( V_27 -> V_2 , 1 ) ;
if ( V_2 ) {
F_15 ( V_2 ) ;
F_16 ( V_27 -> V_2 , NULL ) ;
}
V_27 ++ ;
}
}
static int F_20 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
V_19 = F_21 ( sizeof( struct V_18 ) , V_35 ) ;
if ( V_19 == NULL )
return - V_36 ;
V_17 -> V_37 = V_19 ;
F_22 ( 6 , L_5
L_6 ,
sizeof( struct V_26 ) * V_24 ) ;
F_12 ( V_19 , V_17 ) ;
return 0 ;
}
static void F_23 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_37 ;
F_19 ( V_19 ) ;
F_24 ( V_19 , V_38 ) ;
F_22 ( 6 , L_7 ,
sizeof( struct V_26 ) * V_24 ) ;
}
static int F_25 ( struct V_16 * V_17 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 = V_17 -> V_37 ;
F_12 ( V_19 , V_17 ) ;
return 0 ;
}
static inline T_1
F_26 ( const struct V_39 * V_40 , struct V_41 * V_42 )
{
T_1 V_9 ;
struct V_43 V_44 , * V_45 ;
struct V_46 V_47 , * V_48 ;
T_3 V_49 , * V_50 ;
switch ( V_42 -> V_51 ) {
case V_52 :
V_45 = F_27 ( V_40 , V_42 -> V_53 , sizeof( V_44 ) , & V_44 ) ;
if ( F_28 ( V_45 == NULL ) )
return 0 ;
V_9 = V_45 -> V_54 ;
break;
case V_55 :
V_48 = F_27 ( V_40 , V_42 -> V_53 , sizeof( V_47 ) , & V_47 ) ;
if ( F_28 ( V_48 == NULL ) )
return 0 ;
V_9 = V_48 -> V_54 ;
break;
case V_56 :
V_50 = F_27 ( V_40 , V_42 -> V_53 , sizeof( V_49 ) , & V_49 ) ;
if ( F_28 ( V_50 == NULL ) )
return 0 ;
V_9 = V_50 -> V_54 ;
break;
default:
V_9 = 0 ;
}
return V_9 ;
}
static struct V_1 *
F_29 ( struct V_16 * V_17 , const struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 ;
T_1 V_9 = 0 ;
F_22 ( 6 , L_8 ) ;
if ( V_17 -> V_4 & V_57 )
V_9 = F_26 ( V_40 , V_42 ) ;
V_19 = (struct V_18 * ) V_17 -> V_37 ;
if ( V_17 -> V_4 & V_58 )
V_2 = F_9 ( V_17 , V_19 , & V_42 -> V_59 , V_9 ) ;
else
V_2 = F_7 ( V_17 , V_19 , & V_42 -> V_59 , V_9 ) ;
if ( ! V_2 ) {
F_30 ( V_17 , L_9 ) ;
return NULL ;
}
F_10 ( 6 , L_10 ,
F_11 ( V_17 -> V_6 , & V_42 -> V_59 ) ,
F_11 ( V_2 -> V_6 , & V_2 -> V_8 ) ,
F_5 ( V_2 -> V_9 ) ) ;
return V_2 ;
}
static int T_4 F_31 ( void )
{
return F_32 ( & V_60 ) ;
}
static void T_5 F_33 ( void )
{
F_34 ( & V_60 ) ;
F_35 () ;
}
