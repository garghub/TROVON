static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static const struct V_4 * F_2 ( T_1 V_5 )
{
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_7 ) ; V_6 ++ ) {
if ( V_7 [ V_6 ] . V_8 == V_5 )
return & V_7 [ V_6 ] ;
}
return NULL ;
}
static bool F_4 ( struct V_2 * V_3 )
{
return V_3 -> V_9 && V_3 -> V_10 ;
}
static struct V_2 * F_5 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
if ( F_6 ( ! V_12 -> V_3 ) )
return NULL ;
V_13 = F_7 ( V_12 -> V_3 , sizeof( * V_13 ) , V_14 ) ;
if ( ! V_13 )
return NULL ;
F_8 ( V_12 , & V_13 -> V_15 ) ;
if ( V_13 -> V_16 ) {
V_13 -> V_16 = F_7 ( V_13 -> V_16 ,
V_13 -> V_17 * 4 ,
V_14 ) ;
if ( ! V_13 -> V_16 ) {
F_9 ( V_13 ) ;
return NULL ;
}
V_13 -> V_18 = V_13 -> V_17 ;
}
return & V_13 -> V_15 ;
}
static void F_10 ( struct V_11 * V_12 ,
struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
F_9 ( V_13 -> V_16 ) ;
F_11 ( V_12 , & V_13 -> V_15 ) ;
F_9 ( V_3 ) ;
}
static void F_12 ( struct V_11 * V_12 )
{
struct V_1 * V_13 ;
F_6 ( V_12 -> V_3 ) ;
V_13 = F_13 ( sizeof( * V_13 ) , V_14 ) ;
if ( ! V_13 )
return;
V_12 -> V_3 = & V_13 -> V_15 ;
V_13 -> V_15 . V_12 = V_12 ;
}
static void F_14 ( struct V_1 * V_13 , T_1 V_19 )
{
if ( V_13 -> V_17 == V_13 -> V_18 ) {
T_1 V_20 = F_15 ( 4u , V_13 -> V_17 * 2 ) ;
T_1 * V_21 = F_16 ( V_20 * 4 , V_14 ) ;
if ( ! V_21 )
return;
memcpy ( V_21 , V_13 -> V_16 , V_13 -> V_17 * 4 ) ;
F_9 ( V_13 -> V_16 ) ;
V_13 -> V_16 = V_21 ;
V_13 -> V_18 = V_20 ;
}
V_13 -> V_16 [ V_13 -> V_17 ++ ] = V_19 ;
}
static int F_17 ( struct V_11 * V_12 ,
struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_22 * V_9 = V_3 -> V_9 ;
struct V_23 * V_24 = F_18 ( V_9 , 0 ) ;
T_1 V_25 = V_13 -> V_17 ;
const struct V_4 * V_26 = F_2 ( V_9 -> V_27 ) ;
T_2 V_28 = V_9 -> V_29 [ 0 ] ;
int V_30 = V_3 -> V_30 ;
int V_31 = V_3 -> V_31 ;
int V_32 = V_3 -> V_32 ;
int V_33 = V_3 -> V_33 ;
if ( V_3 -> V_32 << 16 != V_3 -> V_34 ||
V_3 -> V_33 << 16 != V_3 -> V_35 ) {
return - V_36 ;
}
if ( V_30 < 0 ) {
V_28 += F_19 ( V_9 -> V_27 , 0 ) * - V_30 ;
V_32 += V_30 ;
V_30 = 0 ;
}
if ( V_31 < 0 ) {
V_28 += V_9 -> V_37 [ 0 ] * - V_31 ;
V_33 += V_31 ;
V_31 = 0 ;
}
F_14 ( V_13 ,
V_38 |
( V_26 -> V_39 << V_40 ) |
( V_26 -> V_41 << V_42 ) |
V_43 ) ;
F_14 ( V_13 ,
F_20 ( 0xff , V_44 ) |
F_20 ( V_30 , V_45 ) |
F_20 ( V_31 , V_46 ) ) ;
F_14 ( V_13 ,
F_20 ( V_26 -> V_47 ?
V_48 :
V_49 ,
V_50 ) |
F_20 ( V_32 , V_51 ) |
F_20 ( V_33 , V_52 ) ) ;
F_14 ( V_13 , 0xc0c0c0c0 ) ;
V_13 -> V_53 = V_13 -> V_17 ;
F_14 ( V_13 , V_24 -> V_54 + V_28 ) ;
F_14 ( V_13 , 0xc0c0c0c0 ) ;
F_14 ( V_13 ,
F_20 ( V_9 -> V_37 [ 0 ] , V_55 ) ) ;
V_13 -> V_16 [ V_25 ] |=
F_20 ( V_13 -> V_17 , V_56 ) ;
return 0 ;
}
static int F_21 ( struct V_11 * V_12 ,
struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
V_13 -> V_17 = 0 ;
if ( F_4 ( V_3 ) )
return F_17 ( V_12 , V_3 ) ;
else
return 0 ;
}
static void F_22 ( struct V_11 * V_12 ,
struct V_2 * V_57 )
{
}
T_1 F_23 ( struct V_11 * V_12 , T_1 T_3 * V_16 )
{
struct V_1 * V_13 = F_1 ( V_12 -> V_3 ) ;
int V_6 ;
V_13 -> V_58 = V_16 ;
for ( V_6 = 0 ; V_6 < V_13 -> V_17 ; V_6 ++ )
F_24 ( V_13 -> V_16 [ V_6 ] , & V_16 [ V_6 ] ) ;
return V_13 -> V_17 ;
}
T_1 F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
return V_13 -> V_17 ;
}
void F_26 ( struct V_11 * V_12 , struct V_22 * V_9 )
{
struct V_1 * V_13 = F_1 ( V_12 -> V_3 ) ;
struct V_23 * V_24 = F_18 ( V_9 , 0 ) ;
T_2 V_59 ;
F_27 ( V_12 -> V_3 -> V_30 < 0 || V_12 -> V_3 -> V_31 < 0 ) ;
V_59 = V_24 -> V_54 + V_9 -> V_29 [ 0 ] ;
F_24 ( V_59 , & V_13 -> V_58 [ V_13 -> V_53 ] ) ;
V_13 -> V_16 [ V_13 -> V_53 ] = V_59 ;
}
static void F_28 ( struct V_11 * V_12 )
{
F_29 ( V_12 ) ;
F_30 ( V_12 ) ;
}
struct V_11 * F_31 ( struct V_60 * V_61 ,
enum V_62 type )
{
struct V_11 * V_12 = NULL ;
struct V_63 * V_63 ;
T_1 V_64 [ F_3 ( V_7 ) ] ;
int V_65 = 0 ;
unsigned V_6 ;
V_63 = F_32 ( V_61 -> V_61 , sizeof( * V_63 ) ,
V_14 ) ;
if ( ! V_63 ) {
V_65 = - V_66 ;
goto V_67;
}
for ( V_6 = 0 ; V_6 < F_3 ( V_7 ) ; V_6 ++ )
V_64 [ V_6 ] = V_7 [ V_6 ] . V_8 ;
V_12 = & V_63 -> V_15 ;
V_65 = F_33 ( V_61 , V_12 , 0xff ,
& V_68 ,
V_64 , F_3 ( V_64 ) ,
type , NULL ) ;
F_34 ( V_12 , & V_69 ) ;
return V_12 ;
V_67:
if ( V_12 )
F_28 ( V_12 ) ;
return F_35 ( V_65 ) ;
}
