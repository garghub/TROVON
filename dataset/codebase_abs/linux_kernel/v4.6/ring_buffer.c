void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_4 = 1 ;
F_2 () ;
}
T_1 F_3 ( struct V_1 * V_2 )
{
T_1 V_5 ;
T_1 V_6 ;
V_2 -> V_3 -> V_4 = 0 ;
F_2 () ;
F_4 ( V_2 , & V_5 , & V_6 ) ;
return V_5 ;
}
static bool F_5 ( T_1 V_7 , struct V_1 * V_2 )
{
F_2 () ;
if ( V_2 -> V_3 -> V_4 )
return false ;
F_6 () ;
if ( V_7 == V_2 -> V_3 -> V_8 )
return true ;
return false ;
}
static bool F_7 ( struct V_1 * V_2 )
{
T_1 V_9 ;
T_1 V_10 ;
T_1 V_11 ;
T_1 V_12 = V_2 -> V_3 -> V_8 ;
T_1 V_13 ;
F_2 () ;
V_13 = V_2 -> V_3 -> V_14 ;
V_11 = V_2 -> V_3 -> V_15 ;
if ( V_13 == 0 )
return false ;
V_10 = V_2 -> V_16 ;
V_9 = V_11 >= V_12 ? V_10 - ( V_11 - V_12 ) :
V_12 - V_11 ;
if ( V_9 >= V_13 )
return true ;
return false ;
}
static inline T_1
F_8 ( struct V_1 * V_17 )
{
T_1 V_18 = V_17 -> V_3 -> V_15 ;
return V_18 ;
}
static inline void
F_9 ( struct V_1 * V_17 ,
T_1 V_19 )
{
V_17 -> V_3 -> V_15 = V_19 ;
}
static inline T_1
F_10 ( struct V_1 * V_17 )
{
T_1 V_18 = V_17 -> V_3 -> V_8 ;
return V_18 ;
}
static inline T_1
F_11 ( struct V_1 * V_17 ,
T_1 V_20 )
{
T_1 V_18 = V_17 -> V_3 -> V_8 ;
V_18 += V_20 ;
V_18 %= V_17 -> V_16 ;
return V_18 ;
}
static inline void
F_12 ( struct V_1 * V_17 ,
T_1 V_21 )
{
V_17 -> V_3 -> V_8 = V_21 ;
}
static inline void *
F_13 ( struct V_1 * V_17 )
{
return ( void * ) V_17 -> V_3 -> V_22 ;
}
static inline T_1
F_14 ( struct V_1 * V_17 )
{
return V_17 -> V_16 ;
}
static inline T_2
F_15 ( struct V_1 * V_17 )
{
return ( T_2 ) V_17 -> V_3 -> V_15 << 32 ;
}
static T_1 F_16 (
struct V_1 * V_17 ,
void * V_23 ,
T_1 V_24 ,
T_1 V_25 )
{
void * V_3 = F_13 ( V_17 ) ;
T_1 V_26 = F_14 ( V_17 ) ;
T_1 V_27 ;
if ( V_24 > V_26 - V_25 ) {
V_27 = V_26 - V_25 ;
memcpy ( V_23 , V_3 + V_25 , V_27 ) ;
memcpy ( V_23 + V_27 , V_3 , V_24 - V_27 ) ;
} else
memcpy ( V_23 , V_3 + V_25 , V_24 ) ;
V_25 += V_24 ;
V_25 %= V_26 ;
return V_25 ;
}
static T_1 F_17 (
struct V_1 * V_17 ,
T_1 V_28 ,
void * V_29 ,
T_1 V_30 )
{
void * V_3 = F_13 ( V_17 ) ;
T_1 V_26 = F_14 ( V_17 ) ;
T_1 V_27 ;
if ( V_30 > V_26 - V_28 ) {
V_27 = V_26 - V_28 ;
memcpy ( V_3 + V_28 , V_29 , V_27 ) ;
memcpy ( V_3 , V_29 + V_27 , V_30 - V_27 ) ;
} else
memcpy ( V_3 + V_28 , V_29 , V_30 ) ;
V_28 += V_30 ;
V_28 %= V_26 ;
return V_28 ;
}
void F_18 ( struct V_1 * V_17 ,
struct V_31 * V_32 )
{
T_1 V_33 ;
T_1 V_34 ;
if ( V_17 -> V_3 ) {
F_4 ( V_17 ,
& V_34 ,
& V_33 ) ;
V_32 -> V_34 = V_34 ;
V_32 -> V_33 = V_33 ;
V_32 -> V_35 =
V_17 -> V_3 -> V_8 ;
V_32 -> V_36 =
V_17 -> V_3 -> V_15 ;
V_32 -> V_37 =
V_17 -> V_3 -> V_4 ;
}
}
int F_19 ( struct V_1 * V_17 ,
void * V_22 , T_1 V_38 )
{
if ( sizeof( struct V_39 ) != V_40 )
return - V_41 ;
memset ( V_17 , 0 , sizeof( struct V_1 ) ) ;
V_17 -> V_3 = (struct V_39 * ) V_22 ;
V_17 -> V_3 -> V_8 =
V_17 -> V_3 -> V_15 = 0 ;
V_17 -> V_3 -> V_42 . V_43 = 1 ;
V_17 -> V_44 = V_38 ;
V_17 -> V_16 = V_38 - sizeof( struct V_39 ) ;
F_20 ( & V_17 -> V_45 ) ;
return 0 ;
}
void F_21 ( struct V_1 * V_17 )
{
}
int F_22 ( struct V_1 * V_46 ,
struct V_47 * V_48 , T_1 V_49 , bool * signal , bool V_50 )
{
int V_51 = 0 ;
T_1 V_33 ;
T_1 V_34 ;
T_1 V_52 = 0 ;
T_1 V_19 ;
T_1 V_7 ;
T_2 V_53 = 0 ;
unsigned long V_54 = 0 ;
for ( V_51 = 0 ; V_51 < V_49 ; V_51 ++ )
V_52 += V_48 [ V_51 ] . V_55 ;
V_52 += sizeof( T_2 ) ;
if ( V_50 )
F_23 ( & V_46 -> V_45 , V_54 ) ;
F_4 ( V_46 ,
& V_34 ,
& V_33 ) ;
if ( V_33 <= V_52 ) {
if ( V_50 )
F_24 ( & V_46 -> V_45 , V_54 ) ;
return - V_56 ;
}
V_19 = F_8 ( V_46 ) ;
V_7 = V_19 ;
for ( V_51 = 0 ; V_51 < V_49 ; V_51 ++ ) {
V_19 = F_17 ( V_46 ,
V_19 ,
V_48 [ V_51 ] . V_57 ,
V_48 [ V_51 ] . V_55 ) ;
}
V_53 = F_15 ( V_46 ) ;
V_19 = F_17 ( V_46 ,
V_19 ,
& V_53 ,
sizeof( T_2 ) ) ;
F_2 () ;
F_9 ( V_46 , V_19 ) ;
if ( V_50 )
F_24 ( & V_46 -> V_45 , V_54 ) ;
* signal = F_5 ( V_7 , V_46 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_58 ,
void * V_22 , T_1 V_38 , T_1 * V_59 ,
T_2 * V_60 , bool * signal , bool V_61 )
{
T_1 V_33 ;
T_1 V_34 ;
T_1 V_21 = 0 ;
T_2 V_53 = 0 ;
struct V_62 V_63 ;
T_1 V_20 ;
T_1 V_64 ;
int V_65 = 0 ;
if ( V_38 <= 0 )
return - V_41 ;
* V_59 = 0 ;
* V_60 = 0 ;
F_4 ( V_58 ,
& V_34 ,
& V_33 ) ;
if ( V_34 < sizeof( V_63 ) ) {
return V_65 ;
}
V_21 = F_10 ( V_58 ) ;
V_21 = F_16 ( V_58 , & V_63 ,
sizeof( V_63 ) ,
V_21 ) ;
V_20 = V_61 ? 0 : ( V_63 . V_66 << 3 ) ;
V_64 = ( V_63 . V_67 << 3 ) - V_20 ;
* V_59 = V_64 ;
* V_60 = V_63 . V_68 ;
if ( V_34 < V_64 + V_20 )
return - V_56 ;
if ( V_64 > V_38 )
return - V_69 ;
V_21 =
F_11 ( V_58 , V_20 ) ;
V_21 = F_16 ( V_58 ,
V_22 ,
V_64 ,
V_21 ) ;
V_21 = F_16 ( V_58 ,
& V_53 ,
sizeof( T_2 ) ,
V_21 ) ;
F_2 () ;
F_12 ( V_58 , V_21 ) ;
* signal = F_7 ( V_58 ) ;
return V_65 ;
}
