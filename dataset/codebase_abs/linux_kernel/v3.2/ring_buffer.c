static inline void
F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_1 * V_4 )
{
T_1 V_5 , V_6 ;
F_2 () ;
V_5 = V_2 -> V_7 -> V_8 ;
V_6 = V_2 -> V_7 -> V_9 ;
* V_4 = F_3 ( V_5 , V_6 , V_2 -> V_10 ) ;
* V_3 = V_2 -> V_10 - * V_4 ;
}
static inline T_1
F_4 ( struct V_1 * V_11 )
{
T_1 V_12 = V_11 -> V_7 -> V_9 ;
return V_12 ;
}
static inline void
F_5 ( struct V_1 * V_11 ,
T_1 V_13 )
{
V_11 -> V_7 -> V_9 = V_13 ;
}
static inline T_1
F_6 ( struct V_1 * V_11 )
{
T_1 V_12 = V_11 -> V_7 -> V_8 ;
return V_12 ;
}
static inline T_1
F_7 ( struct V_1 * V_11 ,
T_1 V_14 )
{
T_1 V_12 = V_11 -> V_7 -> V_8 ;
V_12 += V_14 ;
V_12 %= V_11 -> V_10 ;
return V_12 ;
}
static inline void
F_8 ( struct V_1 * V_11 ,
T_1 V_15 )
{
V_11 -> V_7 -> V_8 = V_15 ;
}
static inline void *
F_9 ( struct V_1 * V_11 )
{
return ( void * ) V_11 -> V_7 -> V_16 ;
}
static inline T_1
F_10 ( struct V_1 * V_11 )
{
return V_11 -> V_10 ;
}
static inline T_2
F_11 ( struct V_1 * V_11 )
{
return ( T_2 ) V_11 -> V_7 -> V_9 << 32 ;
}
static T_1 F_12 (
struct V_1 * V_11 ,
void * V_17 ,
T_1 V_18 ,
T_1 V_19 )
{
void * V_7 = F_9 ( V_11 ) ;
T_1 V_20 = F_10 ( V_11 ) ;
T_1 V_21 ;
if ( V_18 > V_20 - V_19 ) {
V_21 = V_20 - V_19 ;
memcpy ( V_17 , V_7 + V_19 , V_21 ) ;
memcpy ( V_17 + V_21 , V_7 , V_18 - V_21 ) ;
} else
memcpy ( V_17 , V_7 + V_19 , V_18 ) ;
V_19 += V_18 ;
V_19 %= V_20 ;
return V_19 ;
}
static T_1 F_13 (
struct V_1 * V_11 ,
T_1 V_22 ,
void * V_23 ,
T_1 V_24 )
{
void * V_7 = F_9 ( V_11 ) ;
T_1 V_20 = F_10 ( V_11 ) ;
T_1 V_21 ;
if ( V_24 > V_20 - V_22 ) {
V_21 = V_20 - V_22 ;
memcpy ( V_7 + V_22 , V_23 , V_21 ) ;
memcpy ( V_7 , V_23 + V_21 , V_24 - V_21 ) ;
} else
memcpy ( V_7 + V_22 , V_23 , V_24 ) ;
V_22 += V_24 ;
V_22 %= V_20 ;
return V_22 ;
}
void F_14 ( struct V_1 * V_11 ,
struct V_25 * V_26 )
{
T_1 V_27 ;
T_1 V_28 ;
if ( V_11 -> V_7 ) {
F_1 ( V_11 ,
& V_28 ,
& V_27 ) ;
V_26 -> V_28 = V_28 ;
V_26 -> V_27 = V_27 ;
V_26 -> V_29 =
V_11 -> V_7 -> V_8 ;
V_26 -> V_30 =
V_11 -> V_7 -> V_9 ;
V_26 -> V_31 =
V_11 -> V_7 -> V_32 ;
}
}
T_1 F_15 ( struct V_1 * V_2 )
{
return V_2 -> V_7 -> V_32 ;
}
int F_16 ( struct V_1 * V_11 ,
void * V_16 , T_1 V_33 )
{
if ( sizeof( struct V_34 ) != V_35 )
return - V_36 ;
memset ( V_11 , 0 , sizeof( struct V_1 ) ) ;
V_11 -> V_7 = (struct V_34 * ) V_16 ;
V_11 -> V_7 -> V_8 =
V_11 -> V_7 -> V_9 = 0 ;
V_11 -> V_37 = V_33 ;
V_11 -> V_10 = V_33 - sizeof( struct V_34 ) ;
F_17 ( & V_11 -> V_38 ) ;
return 0 ;
}
void F_18 ( struct V_1 * V_11 )
{
}
int F_19 ( struct V_1 * V_39 ,
struct V_40 * V_41 , T_1 V_42 )
{
int V_43 = 0 ;
T_1 V_27 ;
T_1 V_28 ;
T_1 V_44 = 0 ;
struct V_40 * V_45 ;
T_1 V_13 ;
T_2 V_46 = 0 ;
unsigned long V_47 ;
F_20 (sglist, sg, sgcount, i)
{
V_44 += V_45 -> V_48 ;
}
V_44 += sizeof( T_2 ) ;
F_21 ( & V_39 -> V_38 , V_47 ) ;
F_1 ( V_39 ,
& V_28 ,
& V_27 ) ;
if ( V_27 <= V_44 ) {
F_22 ( & V_39 -> V_38 , V_47 ) ;
return - V_49 ;
}
V_13 = F_4 ( V_39 ) ;
F_20 (sglist, sg, sgcount, i)
{
V_13 = F_13 ( V_39 ,
V_13 ,
F_23 ( V_45 ) ,
V_45 -> V_48 ) ;
}
V_46 = F_11 ( V_39 ) ;
V_13 = F_13 ( V_39 ,
V_13 ,
& V_46 ,
sizeof( T_2 ) ) ;
F_24 () ;
F_5 ( V_39 , V_13 ) ;
F_22 ( & V_39 -> V_38 , V_47 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_50 ,
void * V_51 , T_1 V_33 )
{
T_1 V_27 ;
T_1 V_28 ;
T_1 V_15 = 0 ;
unsigned long V_47 ;
F_21 ( & V_50 -> V_38 , V_47 ) ;
F_1 ( V_50 ,
& V_28 ,
& V_27 ) ;
if ( V_28 < V_33 ) {
F_22 ( & V_50 -> V_38 , V_47 ) ;
return - V_49 ;
}
V_15 = F_6 ( V_50 ) ;
V_15 = F_12 ( V_50 ,
V_51 ,
V_33 ,
V_15 ) ;
F_22 ( & V_50 -> V_38 , V_47 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_52 , void * V_16 ,
T_1 V_33 , T_1 V_14 )
{
T_1 V_27 ;
T_1 V_28 ;
T_1 V_15 = 0 ;
T_2 V_46 = 0 ;
unsigned long V_47 ;
if ( V_33 <= 0 )
return - V_36 ;
F_21 ( & V_52 -> V_38 , V_47 ) ;
F_1 ( V_52 ,
& V_28 ,
& V_27 ) ;
if ( V_28 < V_33 ) {
F_22 ( & V_52 -> V_38 , V_47 ) ;
return - V_49 ;
}
V_15 =
F_7 ( V_52 , V_14 ) ;
V_15 = F_12 ( V_52 ,
V_16 ,
V_33 ,
V_15 ) ;
V_15 = F_12 ( V_52 ,
& V_46 ,
sizeof( T_2 ) ,
V_15 ) ;
F_27 () ;
F_8 ( V_52 , V_15 ) ;
F_22 ( & V_52 -> V_38 , V_47 ) ;
return 0 ;
}
