static inline T_1
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 -> V_5 ;
return V_3 ;
}
static inline void
F_2 ( struct V_1 * V_2 ,
T_1 V_6 )
{
V_2 -> V_4 -> V_5 = V_6 ;
}
static inline T_1
F_3 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 -> V_7 ;
return V_3 ;
}
static inline T_1
F_4 ( struct V_1 * V_2 ,
T_1 V_8 )
{
T_1 V_3 = V_2 -> V_4 -> V_7 ;
V_3 += V_8 ;
V_3 %= V_2 -> V_9 ;
return V_3 ;
}
static inline void
F_5 ( struct V_1 * V_2 ,
T_1 V_10 )
{
V_2 -> V_4 -> V_7 = V_10 ;
}
static inline void *
F_6 ( struct V_1 * V_2 )
{
return ( void * ) V_2 -> V_4 -> V_11 ;
}
static inline T_1
F_7 ( struct V_1 * V_2 )
{
return V_2 -> V_9 ;
}
static inline T_2
F_8 ( struct V_1 * V_2 )
{
return ( T_2 ) V_2 -> V_4 -> V_5 << 32 ;
}
static T_1 F_9 (
struct V_1 * V_2 ,
void * V_12 ,
T_1 V_13 ,
T_1 V_14 )
{
void * V_4 = F_6 ( V_2 ) ;
T_1 V_15 = F_7 ( V_2 ) ;
T_1 V_16 ;
if ( V_13 > V_15 - V_14 ) {
V_16 = V_15 - V_14 ;
memcpy ( V_12 , V_4 + V_14 , V_16 ) ;
memcpy ( V_12 + V_16 , V_4 , V_13 - V_16 ) ;
} else
memcpy ( V_12 , V_4 + V_14 , V_13 ) ;
V_14 += V_13 ;
V_14 %= V_15 ;
return V_14 ;
}
static T_1 F_10 (
struct V_1 * V_2 ,
T_1 V_17 ,
void * V_18 ,
T_1 V_19 )
{
void * V_4 = F_6 ( V_2 ) ;
T_1 V_15 = F_7 ( V_2 ) ;
T_1 V_16 ;
if ( V_19 > V_15 - V_17 ) {
V_16 = V_15 - V_17 ;
memcpy ( V_4 + V_17 , V_18 , V_16 ) ;
memcpy ( V_4 , V_18 + V_16 , V_19 - V_16 ) ;
} else
memcpy ( V_4 + V_17 , V_18 , V_19 ) ;
V_17 += V_19 ;
V_17 %= V_15 ;
return V_17 ;
}
void F_11 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
T_1 V_22 ;
T_1 V_23 ;
if ( V_2 -> V_4 ) {
F_12 ( V_2 ,
& V_23 ,
& V_22 ) ;
V_21 -> V_23 = V_23 ;
V_21 -> V_22 = V_22 ;
V_21 -> V_24 =
V_2 -> V_4 -> V_7 ;
V_21 -> V_25 =
V_2 -> V_4 -> V_5 ;
V_21 -> V_26 =
V_2 -> V_4 -> V_27 ;
}
}
T_1 F_13 ( struct V_1 * V_28 )
{
return V_28 -> V_4 -> V_27 ;
}
int F_14 ( struct V_1 * V_2 ,
void * V_11 , T_1 V_29 )
{
if ( sizeof( struct V_30 ) != V_31 )
return - V_32 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_4 = (struct V_30 * ) V_11 ;
V_2 -> V_4 -> V_7 =
V_2 -> V_4 -> V_5 = 0 ;
V_2 -> V_33 = V_29 ;
V_2 -> V_9 = V_29 - sizeof( struct V_30 ) ;
F_15 ( & V_2 -> V_34 ) ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
}
int F_17 ( struct V_1 * V_35 ,
struct V_36 * V_37 , T_1 V_38 )
{
int V_39 = 0 ;
T_1 V_22 ;
T_1 V_23 ;
T_1 V_40 = 0 ;
struct V_36 * V_41 ;
T_1 V_6 ;
T_2 V_42 = 0 ;
unsigned long V_43 ;
F_18 (sglist, sg, sgcount, i)
{
V_40 += V_41 -> V_44 ;
}
V_40 += sizeof( T_2 ) ;
F_19 ( & V_35 -> V_34 , V_43 ) ;
F_12 ( V_35 ,
& V_23 ,
& V_22 ) ;
if ( V_22 <= V_40 ) {
F_20 ( & V_35 -> V_34 , V_43 ) ;
return - V_45 ;
}
V_6 = F_1 ( V_35 ) ;
F_18 (sglist, sg, sgcount, i)
{
V_6 = F_10 ( V_35 ,
V_6 ,
F_21 ( V_41 ) ,
V_41 -> V_44 ) ;
}
V_42 = F_8 ( V_35 ) ;
V_6 = F_10 ( V_35 ,
V_6 ,
& V_42 ,
sizeof( T_2 ) ) ;
F_22 () ;
F_2 ( V_35 , V_6 ) ;
F_20 ( & V_35 -> V_34 , V_43 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_46 ,
void * V_47 , T_1 V_29 )
{
T_1 V_22 ;
T_1 V_23 ;
T_1 V_10 = 0 ;
unsigned long V_43 ;
F_19 ( & V_46 -> V_34 , V_43 ) ;
F_12 ( V_46 ,
& V_23 ,
& V_22 ) ;
if ( V_23 < V_29 ) {
F_20 ( & V_46 -> V_34 , V_43 ) ;
return - V_45 ;
}
V_10 = F_3 ( V_46 ) ;
V_10 = F_9 ( V_46 ,
V_47 ,
V_29 ,
V_10 ) ;
F_20 ( & V_46 -> V_34 , V_43 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_48 , void * V_11 ,
T_1 V_29 , T_1 V_8 )
{
T_1 V_22 ;
T_1 V_23 ;
T_1 V_10 = 0 ;
T_2 V_42 = 0 ;
unsigned long V_43 ;
if ( V_29 <= 0 )
return - V_32 ;
F_19 ( & V_48 -> V_34 , V_43 ) ;
F_12 ( V_48 ,
& V_23 ,
& V_22 ) ;
if ( V_23 < V_29 ) {
F_20 ( & V_48 -> V_34 , V_43 ) ;
return - V_45 ;
}
V_10 =
F_4 ( V_48 , V_8 ) ;
V_10 = F_9 ( V_48 ,
V_11 ,
V_29 ,
V_10 ) ;
V_10 = F_9 ( V_48 ,
& V_42 ,
sizeof( T_2 ) ,
V_10 ) ;
F_25 () ;
F_5 ( V_48 , V_10 ) ;
F_20 ( & V_48 -> V_34 , V_43 ) ;
return 0 ;
}
