static void F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_6 ;
F_2 () ;
if ( F_3 ( V_5 -> V_7 -> V_8 ) )
return;
F_4 () ;
if ( V_1 == F_3 ( V_5 -> V_7 -> V_9 ) )
F_5 ( V_3 ) ;
return;
}
static inline T_1
F_6 ( struct V_4 * V_10 )
{
T_1 V_11 = V_10 -> V_7 -> V_12 ;
return V_11 ;
}
static inline void
F_7 ( struct V_4 * V_10 ,
T_1 V_13 )
{
V_10 -> V_7 -> V_12 = V_13 ;
}
static inline T_1
F_8 ( const struct V_4 * V_10 )
{
return V_10 -> V_7 -> V_9 ;
}
static inline T_1
F_9 ( const struct V_4 * V_10 ,
T_1 V_14 )
{
T_1 V_11 = V_10 -> V_7 -> V_9 ;
V_11 += V_14 ;
if ( V_11 >= V_10 -> V_15 )
V_11 -= V_10 -> V_15 ;
return V_11 ;
}
static inline void
F_10 ( struct V_4 * V_10 ,
T_1 V_16 )
{
V_10 -> V_7 -> V_9 = V_16 ;
V_10 -> V_17 = V_16 ;
}
static inline T_1
F_11 ( const struct V_4 * V_10 )
{
return V_10 -> V_15 ;
}
static inline T_2
F_12 ( struct V_4 * V_10 )
{
return ( T_2 ) V_10 -> V_7 -> V_12 << 32 ;
}
static T_1 F_13 (
const struct V_4 * V_10 ,
void * V_18 ,
T_1 V_19 ,
T_1 V_20 )
{
void * V_7 = F_14 ( V_10 ) ;
T_1 V_21 = F_11 ( V_10 ) ;
memcpy ( V_18 , V_7 + V_20 , V_19 ) ;
V_20 += V_19 ;
if ( V_20 >= V_21 )
V_20 -= V_21 ;
return V_20 ;
}
static T_1 F_15 (
struct V_4 * V_10 ,
T_1 V_22 ,
const void * V_23 ,
T_1 V_24 )
{
void * V_7 = F_14 ( V_10 ) ;
T_1 V_21 = F_11 ( V_10 ) ;
memcpy ( V_7 + V_22 , V_23 , V_24 ) ;
V_22 += V_24 ;
if ( V_22 >= V_21 )
V_22 -= V_21 ;
return V_22 ;
}
void F_16 ( const struct V_4 * V_10 ,
struct V_25 * V_26 )
{
T_1 V_27 ;
T_1 V_28 ;
if ( V_10 -> V_7 ) {
F_17 ( V_10 ,
& V_28 ,
& V_27 ) ;
V_26 -> V_28 = V_28 ;
V_26 -> V_27 = V_27 ;
V_26 -> V_29 =
V_10 -> V_7 -> V_9 ;
V_26 -> V_30 =
V_10 -> V_7 -> V_12 ;
V_26 -> V_31 =
V_10 -> V_7 -> V_8 ;
}
}
int F_18 ( struct V_4 * V_10 ,
struct V_32 * V_33 , T_1 V_34 )
{
int V_35 ;
struct V_32 * * V_36 ;
F_19 ( ( sizeof( struct V_37 ) != V_38 ) ) ;
memset ( V_10 , 0 , sizeof( struct V_4 ) ) ;
V_36 = F_20 ( sizeof( struct V_32 * ) * ( V_34 * 2 - 1 ) ,
V_39 ) ;
if ( ! V_36 )
return - V_40 ;
V_36 [ 0 ] = V_33 ;
for ( V_35 = 0 ; V_35 < 2 * ( V_34 - 1 ) ; V_35 ++ )
V_36 [ V_35 + 1 ] = & V_33 [ V_35 % ( V_34 - 1 ) + 1 ] ;
V_10 -> V_7 = (struct V_37 * )
F_21 ( V_36 , V_34 * 2 - 1 , V_41 , V_42 ) ;
F_22 ( V_36 ) ;
if ( ! V_10 -> V_7 )
return - V_40 ;
V_10 -> V_7 -> V_9 =
V_10 -> V_7 -> V_12 = 0 ;
V_10 -> V_7 -> V_43 . V_44 = 1 ;
V_10 -> V_45 = V_34 << V_46 ;
V_10 -> V_15 = V_10 -> V_45 -
sizeof( struct V_37 ) ;
F_23 ( & V_10 -> V_47 ) ;
return 0 ;
}
void F_24 ( struct V_4 * V_10 )
{
F_25 ( V_10 -> V_7 ) ;
}
int F_26 ( struct V_2 * V_3 ,
const struct V_48 * V_49 , T_1 V_50 )
{
int V_35 = 0 ;
T_1 V_27 ;
T_1 V_51 = 0 ;
T_1 V_13 ;
T_1 V_1 ;
T_2 V_52 = 0 ;
unsigned long V_53 = 0 ;
struct V_4 * V_54 = & V_3 -> V_6 ;
if ( V_3 -> V_55 )
return - V_56 ;
for ( V_35 = 0 ; V_35 < V_50 ; V_35 ++ )
V_51 += V_49 [ V_35 ] . V_57 ;
V_51 += sizeof( T_2 ) ;
F_27 ( & V_54 -> V_47 , V_53 ) ;
V_27 = F_28 ( V_54 ) ;
if ( V_27 <= V_51 ) {
F_29 ( & V_54 -> V_47 , V_53 ) ;
return - V_58 ;
}
V_13 = F_6 ( V_54 ) ;
V_1 = V_13 ;
for ( V_35 = 0 ; V_35 < V_50 ; V_35 ++ ) {
V_13 = F_15 ( V_54 ,
V_13 ,
V_49 [ V_35 ] . V_59 ,
V_49 [ V_35 ] . V_57 ) ;
}
V_52 = F_12 ( V_54 ) ;
V_13 = F_15 ( V_54 ,
V_13 ,
& V_52 ,
sizeof( T_2 ) ) ;
F_2 () ;
F_7 ( V_54 , V_13 ) ;
F_29 ( & V_54 -> V_47 , V_53 ) ;
F_1 ( V_1 , V_3 ) ;
if ( V_3 -> V_55 )
return - V_56 ;
return 0 ;
}
int F_30 ( struct V_2 * V_3 ,
void * V_60 , T_1 V_61 , T_1 * V_62 ,
T_2 * V_63 , bool V_64 )
{
T_1 V_28 ;
T_1 V_16 = 0 ;
T_2 V_52 = 0 ;
struct V_65 V_66 ;
T_1 V_14 ;
T_1 V_67 ;
int V_68 = 0 ;
struct V_4 * V_69 = & V_3 -> V_70 ;
if ( V_61 <= 0 )
return - V_71 ;
* V_62 = 0 ;
* V_63 = 0 ;
V_28 = F_31 ( V_69 ) ;
if ( V_28 < sizeof( V_66 ) ) {
return V_68 ;
}
F_32 ( V_3 ) ;
V_16 = F_8 ( V_69 ) ;
V_16 = F_13 ( V_69 , & V_66 ,
sizeof( V_66 ) ,
V_16 ) ;
V_14 = V_64 ? 0 : ( V_66 . V_72 << 3 ) ;
V_67 = ( V_66 . V_73 << 3 ) - V_14 ;
* V_62 = V_67 ;
* V_63 = V_66 . V_74 ;
if ( V_28 < V_67 + V_14 )
return - V_58 ;
if ( V_67 > V_61 )
return - V_75 ;
V_16 =
F_9 ( V_69 , V_14 ) ;
V_16 = F_13 ( V_69 ,
V_60 ,
V_67 ,
V_16 ) ;
V_16 = F_13 ( V_69 ,
& V_52 ,
sizeof( T_2 ) ,
V_16 ) ;
F_2 () ;
F_10 ( V_69 , V_16 ) ;
F_33 ( V_3 ) ;
return V_68 ;
}
