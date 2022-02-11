static inline void
F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_1 * V_4 )
{
T_1 V_5 , V_6 ;
V_5 = V_2 -> V_7 -> V_8 ;
V_6 = V_2 -> V_7 -> V_9 ;
* V_4 = F_2 ( V_5 , V_6 , V_2 -> V_10 ) ;
* V_3 = V_2 -> V_10 - * V_4 ;
}
static inline T_1
F_3 ( struct V_1 * V_11 )
{
T_1 V_12 = V_11 -> V_7 -> V_9 ;
return V_12 ;
}
static inline void
F_4 ( struct V_1 * V_11 ,
T_1 V_13 )
{
V_11 -> V_7 -> V_9 = V_13 ;
}
static inline T_1
F_5 ( struct V_1 * V_11 )
{
T_1 V_12 = V_11 -> V_7 -> V_8 ;
return V_12 ;
}
static inline T_1
F_6 ( struct V_1 * V_11 ,
T_1 V_14 )
{
T_1 V_12 = V_11 -> V_7 -> V_8 ;
V_12 += V_14 ;
V_12 %= V_11 -> V_10 ;
return V_12 ;
}
static inline void
F_7 ( struct V_1 * V_11 ,
T_1 V_15 )
{
V_11 -> V_7 -> V_8 = V_15 ;
}
static inline void *
F_8 ( struct V_1 * V_11 )
{
return ( void * ) V_11 -> V_7 -> V_16 ;
}
static inline T_1
F_9 ( struct V_1 * V_11 )
{
return V_11 -> V_10 ;
}
static inline T_2
F_10 ( struct V_1 * V_11 )
{
return ( T_2 ) V_11 -> V_7 -> V_9 << 32 ;
}
void F_11 ( struct V_1 * V_11 , char * V_17 )
{
T_1 V_18 ;
T_1 V_19 ;
F_1 ( V_11 ,
& V_19 ,
& V_18 ) ;
F_12 ( V_20 ,
V_21 ,
L_1
L_2 ,
V_17 ,
V_11 ,
V_11 -> V_7 -> V_16 ,
V_18 ,
V_19 ,
V_11 -> V_7 -> V_8 ,
V_11 -> V_7 -> V_9 ) ;
}
static T_1 F_13 (
struct V_1 * V_11 ,
void * V_22 ,
T_1 V_23 ,
T_1 V_24 )
{
void * V_7 = F_8 ( V_11 ) ;
T_1 V_25 = F_9 ( V_11 ) ;
T_1 V_26 ;
if ( V_23 > V_25 - V_24 ) {
V_26 = V_25 - V_24 ;
memcpy ( V_22 , V_7 + V_24 , V_26 ) ;
memcpy ( V_22 + V_26 , V_7 , V_23 - V_26 ) ;
} else
memcpy ( V_22 , V_7 + V_24 , V_23 ) ;
V_24 += V_23 ;
V_24 %= V_25 ;
return V_24 ;
}
static T_1 F_14 (
struct V_1 * V_11 ,
T_1 V_27 ,
void * V_28 ,
T_1 V_29 )
{
void * V_7 = F_8 ( V_11 ) ;
T_1 V_25 = F_9 ( V_11 ) ;
T_1 V_26 ;
if ( V_29 > V_25 - V_27 ) {
V_26 = V_25 - V_27 ;
memcpy ( V_7 + V_27 , V_28 , V_26 ) ;
memcpy ( V_7 , V_28 + V_26 , V_29 - V_26 ) ;
} else
memcpy ( V_7 + V_27 , V_28 , V_29 ) ;
V_27 += V_29 ;
V_27 %= V_25 ;
return V_27 ;
}
void F_15 ( struct V_1 * V_11 ,
struct V_30 * V_31 )
{
T_1 V_18 ;
T_1 V_19 ;
if ( V_11 -> V_7 ) {
F_1 ( V_11 ,
& V_19 ,
& V_18 ) ;
V_31 -> V_19 = V_19 ;
V_31 -> V_18 = V_18 ;
V_31 -> V_32 =
V_11 -> V_7 -> V_8 ;
V_31 -> V_33 =
V_11 -> V_7 -> V_9 ;
V_31 -> V_34 =
V_11 -> V_7 -> V_35 ;
}
}
T_1 F_16 ( struct V_1 * V_2 )
{
return V_2 -> V_7 -> V_35 ;
}
int F_17 ( struct V_1 * V_11 ,
void * V_16 , T_1 V_36 )
{
if ( sizeof( struct V_37 ) != V_38 )
return - V_39 ;
memset ( V_11 , 0 , sizeof( struct V_1 ) ) ;
V_11 -> V_7 = (struct V_37 * ) V_16 ;
V_11 -> V_7 -> V_8 =
V_11 -> V_7 -> V_9 = 0 ;
V_11 -> V_40 = V_36 ;
V_11 -> V_10 = V_36 - sizeof( struct V_37 ) ;
F_18 ( & V_11 -> V_41 ) ;
return 0 ;
}
void F_19 ( struct V_1 * V_11 )
{
}
int F_20 ( struct V_1 * V_42 ,
struct V_43 * V_44 , T_1 V_45 )
{
int V_46 = 0 ;
T_1 V_18 ;
T_1 V_19 ;
T_1 V_47 = 0 ;
struct V_43 * V_48 ;
T_1 V_13 ;
T_2 V_49 = 0 ;
unsigned long V_50 ;
F_21 (sglist, sg, sgcount, i)
{
V_47 += V_48 -> V_51 ;
}
V_47 += sizeof( T_2 ) ;
F_22 ( & V_42 -> V_41 , V_50 ) ;
F_1 ( V_42 ,
& V_19 ,
& V_18 ) ;
if ( V_18 <= V_47 ) {
F_23 ( & V_42 -> V_41 , V_50 ) ;
return - 1 ;
}
V_13 = F_3 ( V_42 ) ;
F_21 (sglist, sg, sgcount, i)
{
V_13 = F_14 ( V_42 ,
V_13 ,
F_24 ( V_48 ) ,
V_48 -> V_51 ) ;
}
V_49 = F_10 ( V_42 ) ;
V_13 = F_14 ( V_42 ,
V_13 ,
& V_49 ,
sizeof( T_2 ) ) ;
F_25 () ;
F_4 ( V_42 , V_13 ) ;
F_23 ( & V_42 -> V_41 , V_50 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_52 ,
void * V_53 , T_1 V_36 )
{
T_1 V_18 ;
T_1 V_19 ;
T_1 V_15 = 0 ;
unsigned long V_50 ;
F_22 ( & V_52 -> V_41 , V_50 ) ;
F_1 ( V_52 ,
& V_19 ,
& V_18 ) ;
if ( V_19 < V_36 ) {
F_23 ( & V_52 -> V_41 , V_50 ) ;
return - 1 ;
}
V_15 = F_5 ( V_52 ) ;
V_15 = F_13 ( V_52 ,
V_53 ,
V_36 ,
V_15 ) ;
F_23 ( & V_52 -> V_41 , V_50 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_54 , void * V_16 ,
T_1 V_36 , T_1 V_14 )
{
T_1 V_18 ;
T_1 V_19 ;
T_1 V_15 = 0 ;
T_2 V_49 = 0 ;
unsigned long V_50 ;
if ( V_36 <= 0 )
return - V_39 ;
F_22 ( & V_54 -> V_41 , V_50 ) ;
F_1 ( V_54 ,
& V_19 ,
& V_18 ) ;
if ( V_19 < V_36 ) {
F_23 ( & V_54 -> V_41 , V_50 ) ;
return - 1 ;
}
V_15 =
F_6 ( V_54 , V_14 ) ;
V_15 = F_13 ( V_54 ,
V_16 ,
V_36 ,
V_15 ) ;
V_15 = F_13 ( V_54 ,
& V_49 ,
sizeof( T_2 ) ,
V_15 ) ;
F_25 () ;
F_7 ( V_54 , V_15 ) ;
F_23 ( & V_54 -> V_41 , V_50 ) ;
return 0 ;
}
