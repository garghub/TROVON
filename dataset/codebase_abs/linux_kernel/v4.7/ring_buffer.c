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
static bool F_5 ( T_1 V_5 , struct V_1 * V_2 )
{
F_2 () ;
if ( F_6 ( V_2 -> V_3 -> V_4 ) )
return false ;
F_7 () ;
if ( V_5 == F_6 ( V_2 -> V_3 -> V_6 ) )
return true ;
return false ;
}
static inline T_1
F_8 ( struct V_1 * V_7 )
{
T_1 V_8 = V_7 -> V_3 -> V_9 ;
return V_8 ;
}
static inline void
F_9 ( struct V_1 * V_7 ,
T_1 V_10 )
{
V_7 -> V_3 -> V_9 = V_10 ;
}
static inline T_1
F_10 ( struct V_1 * V_7 )
{
T_1 V_8 = V_7 -> V_3 -> V_6 ;
return V_8 ;
}
static inline T_1
F_11 ( struct V_1 * V_7 ,
T_1 V_11 )
{
T_1 V_8 = V_7 -> V_3 -> V_6 ;
V_8 += V_11 ;
V_8 %= V_7 -> V_12 ;
return V_8 ;
}
static inline void
F_12 ( struct V_1 * V_7 ,
T_1 V_13 )
{
V_7 -> V_3 -> V_6 = V_13 ;
V_7 -> V_14 = V_13 ;
}
static inline T_1
F_13 ( struct V_1 * V_7 )
{
return V_7 -> V_12 ;
}
static inline T_2
F_14 ( struct V_1 * V_7 )
{
return ( T_2 ) V_7 -> V_3 -> V_9 << 32 ;
}
static T_1 F_15 (
struct V_1 * V_7 ,
void * V_15 ,
T_1 V_16 ,
T_1 V_17 )
{
void * V_3 = F_16 ( V_7 ) ;
T_1 V_18 = F_13 ( V_7 ) ;
T_1 V_19 ;
if ( V_16 > V_18 - V_17 ) {
V_19 = V_18 - V_17 ;
memcpy ( V_15 , V_3 + V_17 , V_19 ) ;
memcpy ( V_15 + V_19 , V_3 , V_16 - V_19 ) ;
} else
memcpy ( V_15 , V_3 + V_17 , V_16 ) ;
V_17 += V_16 ;
V_17 %= V_18 ;
return V_17 ;
}
static T_1 F_17 (
struct V_1 * V_7 ,
T_1 V_20 ,
void * V_21 ,
T_1 V_22 )
{
void * V_3 = F_16 ( V_7 ) ;
T_1 V_18 = F_13 ( V_7 ) ;
T_1 V_19 ;
if ( V_22 > V_18 - V_20 ) {
V_19 = V_18 - V_20 ;
memcpy ( V_3 + V_20 , V_21 , V_19 ) ;
memcpy ( V_3 , V_21 + V_19 , V_22 - V_19 ) ;
} else
memcpy ( V_3 + V_20 , V_21 , V_22 ) ;
V_20 += V_22 ;
V_20 %= V_18 ;
return V_20 ;
}
void F_18 ( struct V_1 * V_7 ,
struct V_23 * V_24 )
{
T_1 V_25 ;
T_1 V_26 ;
if ( V_7 -> V_3 ) {
F_19 ( V_7 ,
& V_26 ,
& V_25 ) ;
V_24 -> V_26 = V_26 ;
V_24 -> V_25 = V_25 ;
V_24 -> V_27 =
V_7 -> V_3 -> V_6 ;
V_24 -> V_28 =
V_7 -> V_3 -> V_9 ;
V_24 -> V_29 =
V_7 -> V_3 -> V_4 ;
}
}
int F_20 ( struct V_1 * V_7 ,
void * V_30 , T_1 V_31 )
{
if ( sizeof( struct V_32 ) != V_33 )
return - V_34 ;
memset ( V_7 , 0 , sizeof( struct V_1 ) ) ;
V_7 -> V_3 = (struct V_32 * ) V_30 ;
V_7 -> V_3 -> V_6 =
V_7 -> V_3 -> V_9 = 0 ;
V_7 -> V_3 -> V_35 . V_36 = 1 ;
V_7 -> V_37 = V_31 ;
V_7 -> V_12 = V_31 - sizeof( struct V_32 ) ;
F_21 ( & V_7 -> V_38 ) ;
return 0 ;
}
void F_22 ( struct V_1 * V_7 )
{
}
int F_23 ( struct V_1 * V_39 ,
struct V_40 * V_41 , T_1 V_42 , bool * signal , bool V_43 )
{
int V_44 = 0 ;
T_1 V_25 ;
T_1 V_45 = 0 ;
T_1 V_10 ;
T_1 V_5 ;
T_2 V_46 = 0 ;
unsigned long V_47 = 0 ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ )
V_45 += V_41 [ V_44 ] . V_48 ;
V_45 += sizeof( T_2 ) ;
if ( V_43 )
F_24 ( & V_39 -> V_38 , V_47 ) ;
V_25 = F_25 ( V_39 ) ;
if ( V_25 <= V_45 ) {
if ( V_43 )
F_26 ( & V_39 -> V_38 , V_47 ) ;
return - V_49 ;
}
V_10 = F_8 ( V_39 ) ;
V_5 = V_10 ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ ) {
V_10 = F_17 ( V_39 ,
V_10 ,
V_41 [ V_44 ] . V_50 ,
V_41 [ V_44 ] . V_48 ) ;
}
V_46 = F_14 ( V_39 ) ;
V_10 = F_17 ( V_39 ,
V_10 ,
& V_46 ,
sizeof( T_2 ) ) ;
F_2 () ;
F_9 ( V_39 , V_10 ) ;
if ( V_43 )
F_26 ( & V_39 -> V_38 , V_47 ) ;
* signal = F_5 ( V_5 , V_39 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_51 ,
void * V_30 , T_1 V_31 , T_1 * V_52 ,
T_2 * V_53 , bool * signal , bool V_54 )
{
T_1 V_26 ;
T_1 V_13 = 0 ;
T_2 V_46 = 0 ;
struct V_55 V_56 ;
T_1 V_11 ;
T_1 V_57 ;
int V_58 = 0 ;
if ( V_31 <= 0 )
return - V_34 ;
* V_52 = 0 ;
* V_53 = 0 ;
V_26 = F_4 ( V_51 ) ;
if ( V_26 < sizeof( V_56 ) ) {
return V_58 ;
}
V_13 = F_10 ( V_51 ) ;
V_13 = F_15 ( V_51 , & V_56 ,
sizeof( V_56 ) ,
V_13 ) ;
V_11 = V_54 ? 0 : ( V_56 . V_59 << 3 ) ;
V_57 = ( V_56 . V_60 << 3 ) - V_11 ;
* V_52 = V_57 ;
* V_53 = V_56 . V_61 ;
if ( V_26 < V_57 + V_11 )
return - V_49 ;
if ( V_57 > V_31 )
return - V_62 ;
V_13 =
F_11 ( V_51 , V_11 ) ;
V_13 = F_15 ( V_51 ,
V_30 ,
V_57 ,
V_13 ) ;
V_13 = F_15 ( V_51 ,
& V_46 ,
sizeof( T_2 ) ,
V_13 ) ;
F_2 () ;
F_12 ( V_51 , V_13 ) ;
* signal = F_28 ( V_51 ) ;
return V_58 ;
}
