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
static bool F_7 ( T_1 V_9 ,
struct V_1 * V_2 )
{
T_1 V_10 ;
T_1 V_11 ;
T_1 V_12 ;
T_1 V_13 = V_2 -> V_3 -> V_14 ;
T_1 V_15 = V_2 -> V_3 -> V_8 ;
T_1 V_16 = V_2 -> V_3 -> V_17 ;
if ( V_16 == 0 )
return false ;
V_12 = V_2 -> V_18 ;
V_11 = V_13 >= V_15 ? V_12 - ( V_13 - V_15 ) :
V_15 - V_13 ;
V_10 = V_13 >= V_9 ? V_12 - ( V_13 - V_9 ) :
V_9 - V_13 ;
if ( ( V_10 < V_16 ) && ( V_11 >= V_16 ) )
return true ;
return false ;
}
static inline T_1
F_8 ( struct V_1 * V_19 )
{
T_1 V_20 = V_19 -> V_3 -> V_14 ;
return V_20 ;
}
static inline void
F_9 ( struct V_1 * V_19 ,
T_1 V_21 )
{
V_19 -> V_3 -> V_14 = V_21 ;
}
static inline T_1
F_10 ( struct V_1 * V_19 )
{
T_1 V_20 = V_19 -> V_3 -> V_8 ;
return V_20 ;
}
static inline T_1
F_11 ( struct V_1 * V_19 ,
T_1 V_22 )
{
T_1 V_20 = V_19 -> V_3 -> V_8 ;
V_20 += V_22 ;
V_20 %= V_19 -> V_18 ;
return V_20 ;
}
static inline void
F_12 ( struct V_1 * V_19 ,
T_1 V_23 )
{
V_19 -> V_3 -> V_8 = V_23 ;
}
static inline void *
F_13 ( struct V_1 * V_19 )
{
return ( void * ) V_19 -> V_3 -> V_24 ;
}
static inline T_1
F_14 ( struct V_1 * V_19 )
{
return V_19 -> V_18 ;
}
static inline T_2
F_15 ( struct V_1 * V_19 )
{
return ( T_2 ) V_19 -> V_3 -> V_14 << 32 ;
}
static T_1 F_16 (
struct V_1 * V_19 ,
void * V_25 ,
T_1 V_26 ,
T_1 V_27 )
{
void * V_3 = F_13 ( V_19 ) ;
T_1 V_28 = F_14 ( V_19 ) ;
T_1 V_29 ;
if ( V_26 > V_28 - V_27 ) {
V_29 = V_28 - V_27 ;
memcpy ( V_25 , V_3 + V_27 , V_29 ) ;
memcpy ( V_25 + V_29 , V_3 , V_26 - V_29 ) ;
} else
memcpy ( V_25 , V_3 + V_27 , V_26 ) ;
V_27 += V_26 ;
V_27 %= V_28 ;
return V_27 ;
}
static T_1 F_17 (
struct V_1 * V_19 ,
T_1 V_30 ,
void * V_31 ,
T_1 V_32 )
{
void * V_3 = F_13 ( V_19 ) ;
T_1 V_28 = F_14 ( V_19 ) ;
T_1 V_29 ;
if ( V_32 > V_28 - V_30 ) {
V_29 = V_28 - V_30 ;
memcpy ( V_3 + V_30 , V_31 , V_29 ) ;
memcpy ( V_3 , V_31 + V_29 , V_32 - V_29 ) ;
} else
memcpy ( V_3 + V_30 , V_31 , V_32 ) ;
V_30 += V_32 ;
V_30 %= V_28 ;
return V_30 ;
}
void F_18 ( struct V_1 * V_19 ,
struct V_33 * V_34 )
{
T_1 V_35 ;
T_1 V_36 ;
if ( V_19 -> V_3 ) {
F_4 ( V_19 ,
& V_36 ,
& V_35 ) ;
V_34 -> V_36 = V_36 ;
V_34 -> V_35 = V_35 ;
V_34 -> V_37 =
V_19 -> V_3 -> V_8 ;
V_34 -> V_38 =
V_19 -> V_3 -> V_14 ;
V_34 -> V_39 =
V_19 -> V_3 -> V_4 ;
}
}
int F_19 ( struct V_1 * V_19 ,
void * V_24 , T_1 V_40 )
{
if ( sizeof( struct V_41 ) != V_42 )
return - V_43 ;
memset ( V_19 , 0 , sizeof( struct V_1 ) ) ;
V_19 -> V_3 = (struct V_41 * ) V_24 ;
V_19 -> V_3 -> V_8 =
V_19 -> V_3 -> V_14 = 0 ;
V_19 -> V_44 = V_40 ;
V_19 -> V_18 = V_40 - sizeof( struct V_41 ) ;
F_20 ( & V_19 -> V_45 ) ;
return 0 ;
}
void F_21 ( struct V_1 * V_19 )
{
}
int F_22 ( struct V_1 * V_46 ,
struct V_47 * V_48 , T_1 V_49 , bool * signal )
{
int V_50 = 0 ;
T_1 V_35 ;
T_1 V_36 ;
T_1 V_51 = 0 ;
T_1 V_21 ;
T_1 V_7 ;
T_2 V_52 = 0 ;
unsigned long V_53 ;
for ( V_50 = 0 ; V_50 < V_49 ; V_50 ++ )
V_51 += V_48 [ V_50 ] . V_54 ;
V_51 += sizeof( T_2 ) ;
F_23 ( & V_46 -> V_45 , V_53 ) ;
F_4 ( V_46 ,
& V_36 ,
& V_35 ) ;
if ( V_35 <= V_51 ) {
F_24 ( & V_46 -> V_45 , V_53 ) ;
return - V_55 ;
}
V_21 = F_8 ( V_46 ) ;
V_7 = V_21 ;
for ( V_50 = 0 ; V_50 < V_49 ; V_50 ++ ) {
V_21 = F_17 ( V_46 ,
V_21 ,
V_48 [ V_50 ] . V_56 ,
V_48 [ V_50 ] . V_54 ) ;
}
V_52 = F_15 ( V_46 ) ;
V_21 = F_17 ( V_46 ,
V_21 ,
& V_52 ,
sizeof( T_2 ) ) ;
F_2 () ;
F_9 ( V_46 , V_21 ) ;
F_24 ( & V_46 -> V_45 , V_53 ) ;
* signal = F_5 ( V_7 , V_46 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_57 ,
void * V_58 , T_1 V_40 )
{
T_1 V_35 ;
T_1 V_36 ;
T_1 V_23 = 0 ;
unsigned long V_53 ;
F_23 ( & V_57 -> V_45 , V_53 ) ;
F_4 ( V_57 ,
& V_36 ,
& V_35 ) ;
if ( V_36 < V_40 ) {
F_24 ( & V_57 -> V_45 , V_53 ) ;
return - V_55 ;
}
V_23 = F_10 ( V_57 ) ;
V_23 = F_16 ( V_57 ,
V_58 ,
V_40 ,
V_23 ) ;
F_24 ( & V_57 -> V_45 , V_53 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_59 , void * V_24 ,
T_1 V_40 , T_1 V_22 , bool * signal )
{
T_1 V_35 ;
T_1 V_36 ;
T_1 V_23 = 0 ;
T_2 V_52 = 0 ;
unsigned long V_53 ;
T_1 V_60 ;
if ( V_40 <= 0 )
return - V_43 ;
F_23 ( & V_59 -> V_45 , V_53 ) ;
F_4 ( V_59 ,
& V_36 ,
& V_35 ) ;
V_60 = V_36 ;
if ( V_36 < V_40 ) {
F_24 ( & V_59 -> V_45 , V_53 ) ;
return - V_55 ;
}
V_23 =
F_11 ( V_59 , V_22 ) ;
V_23 = F_16 ( V_59 ,
V_24 ,
V_40 ,
V_23 ) ;
V_23 = F_16 ( V_59 ,
& V_52 ,
sizeof( T_2 ) ,
V_23 ) ;
F_2 () ;
F_12 ( V_59 , V_23 ) ;
F_24 ( & V_59 -> V_45 , V_53 ) ;
* signal = F_7 ( V_60 , V_59 ) ;
return 0 ;
}
