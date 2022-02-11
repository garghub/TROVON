void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_4 = 1 ;
F_2 () ;
}
T_1 F_3 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_4 = 0 ;
F_2 () ;
return F_4 ( V_2 ) ;
}
static bool F_5 ( T_1 V_5 , struct V_1 * V_2 ,
enum V_6 V_7 )
{
F_2 () ;
if ( F_6 ( V_2 -> V_3 -> V_4 ) )
return false ;
if ( V_7 == V_8 )
return true ;
F_7 () ;
if ( V_5 == F_6 ( V_2 -> V_3 -> V_9 ) )
return true ;
return false ;
}
static inline T_1
F_8 ( struct V_1 * V_10 )
{
T_1 V_11 = V_10 -> V_3 -> V_12 ;
return V_11 ;
}
static inline void
F_9 ( struct V_1 * V_10 ,
T_1 V_13 )
{
V_10 -> V_3 -> V_12 = V_13 ;
}
static inline T_1
F_10 ( struct V_1 * V_10 )
{
T_1 V_11 = V_10 -> V_3 -> V_9 ;
return V_11 ;
}
static inline T_1
F_11 ( struct V_1 * V_10 ,
T_1 V_14 )
{
T_1 V_11 = V_10 -> V_3 -> V_9 ;
V_11 += V_14 ;
V_11 %= V_10 -> V_15 ;
return V_11 ;
}
static inline void
F_12 ( struct V_1 * V_10 ,
T_1 V_16 )
{
V_10 -> V_3 -> V_9 = V_16 ;
V_10 -> V_17 = V_16 ;
}
static inline T_1
F_13 ( struct V_1 * V_10 )
{
return V_10 -> V_15 ;
}
static inline T_2
F_14 ( struct V_1 * V_10 )
{
return ( T_2 ) V_10 -> V_3 -> V_12 << 32 ;
}
static T_1 F_15 (
struct V_1 * V_10 ,
void * V_18 ,
T_1 V_19 ,
T_1 V_20 )
{
void * V_3 = F_16 ( V_10 ) ;
T_1 V_21 = F_13 ( V_10 ) ;
memcpy ( V_18 , V_3 + V_20 , V_19 ) ;
V_20 += V_19 ;
V_20 %= V_21 ;
return V_20 ;
}
static T_1 F_17 (
struct V_1 * V_10 ,
T_1 V_22 ,
void * V_23 ,
T_1 V_24 )
{
void * V_3 = F_16 ( V_10 ) ;
T_1 V_21 = F_13 ( V_10 ) ;
memcpy ( V_3 + V_22 , V_23 , V_24 ) ;
V_22 += V_24 ;
V_22 %= V_21 ;
return V_22 ;
}
void F_18 ( struct V_1 * V_10 ,
struct V_25 * V_26 )
{
T_1 V_27 ;
T_1 V_28 ;
if ( V_10 -> V_3 ) {
F_19 ( V_10 ,
& V_28 ,
& V_27 ) ;
V_26 -> V_28 = V_28 ;
V_26 -> V_27 = V_27 ;
V_26 -> V_29 =
V_10 -> V_3 -> V_9 ;
V_26 -> V_30 =
V_10 -> V_3 -> V_12 ;
V_26 -> V_31 =
V_10 -> V_3 -> V_4 ;
}
}
int F_20 ( struct V_1 * V_10 ,
struct V_32 * V_33 , T_1 V_34 )
{
int V_35 ;
struct V_32 * * V_36 ;
F_21 ( ( sizeof( struct V_37 ) != V_38 ) ) ;
memset ( V_10 , 0 , sizeof( struct V_1 ) ) ;
V_36 = F_22 ( sizeof( struct V_32 * ) * ( V_34 * 2 - 1 ) ,
V_39 ) ;
if ( ! V_36 )
return - V_40 ;
V_36 [ 0 ] = V_33 ;
for ( V_35 = 0 ; V_35 < 2 * ( V_34 - 1 ) ; V_35 ++ )
V_36 [ V_35 + 1 ] = & V_33 [ V_35 % ( V_34 - 1 ) + 1 ] ;
V_10 -> V_3 = (struct V_37 * )
F_23 ( V_36 , V_34 * 2 - 1 , V_41 , V_42 ) ;
F_24 ( V_36 ) ;
if ( ! V_10 -> V_3 )
return - V_40 ;
V_10 -> V_3 -> V_9 =
V_10 -> V_3 -> V_12 = 0 ;
V_10 -> V_3 -> V_43 . V_44 = 1 ;
V_10 -> V_45 = V_34 << V_46 ;
V_10 -> V_15 = V_10 -> V_45 -
sizeof( struct V_37 ) ;
F_25 ( & V_10 -> V_47 ) ;
return 0 ;
}
void F_26 ( struct V_1 * V_10 )
{
F_27 ( V_10 -> V_3 ) ;
}
int F_28 ( struct V_1 * V_48 ,
struct V_49 * V_50 , T_1 V_51 , bool * signal , bool V_52 ,
enum V_6 V_7 )
{
int V_35 = 0 ;
T_1 V_27 ;
T_1 V_53 = 0 ;
T_1 V_13 ;
T_1 V_5 ;
T_2 V_54 = 0 ;
unsigned long V_55 = 0 ;
for ( V_35 = 0 ; V_35 < V_51 ; V_35 ++ )
V_53 += V_50 [ V_35 ] . V_56 ;
V_53 += sizeof( T_2 ) ;
if ( V_52 )
F_29 ( & V_48 -> V_47 , V_55 ) ;
V_27 = F_30 ( V_48 ) ;
if ( V_27 <= V_53 ) {
if ( V_52 )
F_31 ( & V_48 -> V_47 , V_55 ) ;
return - V_57 ;
}
V_13 = F_8 ( V_48 ) ;
V_5 = V_13 ;
for ( V_35 = 0 ; V_35 < V_51 ; V_35 ++ ) {
V_13 = F_17 ( V_48 ,
V_13 ,
V_50 [ V_35 ] . V_58 ,
V_50 [ V_35 ] . V_56 ) ;
}
V_54 = F_14 ( V_48 ) ;
V_13 = F_17 ( V_48 ,
V_13 ,
& V_54 ,
sizeof( T_2 ) ) ;
F_2 () ;
F_9 ( V_48 , V_13 ) ;
if ( V_52 )
F_31 ( & V_48 -> V_47 , V_55 ) ;
* signal = F_5 ( V_5 , V_48 , V_7 ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_59 ,
void * V_60 , T_1 V_61 , T_1 * V_62 ,
T_2 * V_63 , bool * signal , bool V_64 )
{
T_1 V_28 ;
T_1 V_16 = 0 ;
T_2 V_54 = 0 ;
struct V_65 V_66 ;
T_1 V_14 ;
T_1 V_67 ;
int V_68 = 0 ;
if ( V_61 <= 0 )
return - V_69 ;
* V_62 = 0 ;
* V_63 = 0 ;
V_28 = F_4 ( V_59 ) ;
if ( V_28 < sizeof( V_66 ) ) {
return V_68 ;
}
V_16 = F_10 ( V_59 ) ;
V_16 = F_15 ( V_59 , & V_66 ,
sizeof( V_66 ) ,
V_16 ) ;
V_14 = V_64 ? 0 : ( V_66 . V_70 << 3 ) ;
V_67 = ( V_66 . V_71 << 3 ) - V_14 ;
* V_62 = V_67 ;
* V_63 = V_66 . V_72 ;
if ( V_28 < V_67 + V_14 )
return - V_57 ;
if ( V_67 > V_61 )
return - V_73 ;
V_16 =
F_11 ( V_59 , V_14 ) ;
V_16 = F_15 ( V_59 ,
V_60 ,
V_67 ,
V_16 ) ;
V_16 = F_15 ( V_59 ,
& V_54 ,
sizeof( T_2 ) ,
V_16 ) ;
F_2 () ;
F_12 ( V_59 , V_16 ) ;
* signal = F_33 ( V_59 ) ;
return V_68 ;
}
