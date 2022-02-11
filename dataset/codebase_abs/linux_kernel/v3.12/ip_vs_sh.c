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
unsigned int V_10 ;
unsigned int V_20 ;
struct V_1 * V_2 ;
for ( V_10 = 0 ; V_10 < V_22 ; V_10 ++ ) {
V_20 = F_3 ( V_17 -> V_6 , V_8 , V_9 , V_10 ) ;
V_2 = F_8 ( V_19 -> V_21 [ V_20 ] . V_2 ) ;
if ( ! V_2 )
break;
if ( F_1 ( V_2 ) )
F_10 ( 6 , L_1
L_2 ,
F_11 ( V_17 -> V_6 , & V_2 -> V_8 ) ,
F_5 ( V_2 -> V_9 ) , V_10 ) ;
else
return V_2 ;
}
return NULL ;
}
static int
F_12 ( struct V_18 * V_19 , struct V_16 * V_17 )
{
int V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_1 * V_2 ;
int V_28 ;
bool V_29 ;
V_25 = & V_19 -> V_21 [ 0 ] ;
V_27 = & V_17 -> V_30 ;
V_29 = F_13 ( V_27 ) ;
V_28 = 0 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
V_2 = F_14 ( V_25 -> V_2 , 1 ) ;
if ( V_2 )
F_15 ( V_2 ) ;
if ( V_29 )
F_16 ( V_25 -> V_2 , NULL ) ;
else {
if ( V_27 == & V_17 -> V_30 )
V_27 = V_27 -> V_31 ;
V_2 = F_17 ( V_27 , struct V_1 , V_32 ) ;
F_18 ( V_2 ) ;
F_16 ( V_25 -> V_2 , V_2 ) ;
F_10 ( 6 , L_3 ,
V_23 , F_11 ( V_17 -> V_6 , & V_2 -> V_8 ) ,
F_2 ( & V_2 -> V_3 ) ) ;
if ( ++ V_28 >= F_2 ( & V_2 -> V_3 ) ) {
V_27 = V_27 -> V_31 ;
V_28 = 0 ;
}
}
V_25 ++ ;
}
return 0 ;
}
static void F_19 ( struct V_18 * V_19 )
{
int V_23 ;
struct V_24 * V_25 ;
struct V_1 * V_2 ;
V_25 = & V_19 -> V_21 [ 0 ] ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
V_2 = F_14 ( V_25 -> V_2 , 1 ) ;
if ( V_2 ) {
F_15 ( V_2 ) ;
F_16 ( V_25 -> V_2 , NULL ) ;
}
V_25 ++ ;
}
}
static int F_20 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
V_19 = F_21 ( sizeof( struct V_18 ) , V_33 ) ;
if ( V_19 == NULL )
return - V_34 ;
V_17 -> V_35 = V_19 ;
F_22 ( 6 , L_4
L_5 ,
sizeof( struct V_24 ) * V_22 ) ;
F_12 ( V_19 , V_17 ) ;
return 0 ;
}
static void F_23 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_35 ;
F_19 ( V_19 ) ;
F_24 ( V_19 , V_36 ) ;
F_22 ( 6 , L_6 ,
sizeof( struct V_24 ) * V_22 ) ;
}
static int F_25 ( struct V_16 * V_17 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 = V_17 -> V_35 ;
F_12 ( V_19 , V_17 ) ;
return 0 ;
}
static inline T_1
F_26 ( const struct V_37 * V_38 , struct V_39 * V_40 )
{
T_1 V_9 ;
struct V_41 V_42 , * V_43 ;
struct V_44 V_45 , * V_46 ;
T_3 V_47 , * V_48 ;
switch ( V_40 -> V_49 ) {
case V_50 :
V_43 = F_27 ( V_38 , V_40 -> V_51 , sizeof( V_42 ) , & V_42 ) ;
if ( F_28 ( V_43 == NULL ) )
return 0 ;
V_9 = V_43 -> V_52 ;
break;
case V_53 :
V_46 = F_27 ( V_38 , V_40 -> V_51 , sizeof( V_45 ) , & V_45 ) ;
if ( F_28 ( V_46 == NULL ) )
return 0 ;
V_9 = V_46 -> V_52 ;
break;
case V_54 :
V_48 = F_27 ( V_38 , V_40 -> V_51 , sizeof( V_47 ) , & V_47 ) ;
if ( F_28 ( V_48 == NULL ) )
return 0 ;
V_9 = V_48 -> V_52 ;
break;
default:
V_9 = 0 ;
}
return V_9 ;
}
static struct V_1 *
F_29 ( struct V_16 * V_17 , const struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 ;
T_1 V_9 = 0 ;
F_22 ( 6 , L_7 ) ;
if ( V_17 -> V_4 & V_55 )
V_9 = F_26 ( V_38 , V_40 ) ;
V_19 = (struct V_18 * ) V_17 -> V_35 ;
if ( V_17 -> V_4 & V_56 )
V_2 = F_9 ( V_17 , V_19 , & V_40 -> V_57 , V_9 ) ;
else
V_2 = F_7 ( V_17 , V_19 , & V_40 -> V_57 , V_9 ) ;
if ( ! V_2 ) {
F_30 ( V_17 , L_8 ) ;
return NULL ;
}
F_10 ( 6 , L_9 ,
F_11 ( V_17 -> V_6 , & V_40 -> V_57 ) ,
F_11 ( V_17 -> V_6 , & V_2 -> V_8 ) ,
F_5 ( V_2 -> V_9 ) ) ;
return V_2 ;
}
static int T_4 F_31 ( void )
{
return F_32 ( & V_58 ) ;
}
static void T_5 F_33 ( void )
{
F_34 ( & V_58 ) ;
F_35 () ;
}
