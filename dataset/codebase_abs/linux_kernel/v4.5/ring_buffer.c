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
T_1 V_12 = V_2 -> V_3 -> V_13 ;
T_1 V_14 = V_2 -> V_3 -> V_8 ;
T_1 V_15 = V_2 -> V_3 -> V_16 ;
if ( V_15 == 0 )
return false ;
V_11 = V_2 -> V_17 ;
V_10 = V_12 >= V_14 ? V_11 - ( V_12 - V_14 ) :
V_14 - V_12 ;
if ( ( V_9 < V_15 ) && ( V_10 >= V_15 ) )
return true ;
return false ;
}
static inline T_1
F_8 ( struct V_1 * V_18 )
{
T_1 V_19 = V_18 -> V_3 -> V_13 ;
return V_19 ;
}
static inline void
F_9 ( struct V_1 * V_18 ,
T_1 V_20 )
{
V_18 -> V_3 -> V_13 = V_20 ;
}
static inline T_1
F_10 ( struct V_1 * V_18 )
{
T_1 V_19 = V_18 -> V_3 -> V_8 ;
return V_19 ;
}
static inline T_1
F_11 ( struct V_1 * V_18 ,
T_1 V_21 )
{
T_1 V_19 = V_18 -> V_3 -> V_8 ;
V_19 += V_21 ;
V_19 %= V_18 -> V_17 ;
return V_19 ;
}
static inline void
F_12 ( struct V_1 * V_18 ,
T_1 V_22 )
{
V_18 -> V_3 -> V_8 = V_22 ;
}
static inline void *
F_13 ( struct V_1 * V_18 )
{
return ( void * ) V_18 -> V_3 -> V_23 ;
}
static inline T_1
F_14 ( struct V_1 * V_18 )
{
return V_18 -> V_17 ;
}
static inline T_2
F_15 ( struct V_1 * V_18 )
{
return ( T_2 ) V_18 -> V_3 -> V_13 << 32 ;
}
static T_1 F_16 (
struct V_1 * V_18 ,
void * V_24 ,
T_1 V_25 ,
T_1 V_26 )
{
void * V_3 = F_13 ( V_18 ) ;
T_1 V_27 = F_14 ( V_18 ) ;
T_1 V_28 ;
if ( V_25 > V_27 - V_26 ) {
V_28 = V_27 - V_26 ;
memcpy ( V_24 , V_3 + V_26 , V_28 ) ;
memcpy ( V_24 + V_28 , V_3 , V_25 - V_28 ) ;
} else
memcpy ( V_24 , V_3 + V_26 , V_25 ) ;
V_26 += V_25 ;
V_26 %= V_27 ;
return V_26 ;
}
static T_1 F_17 (
struct V_1 * V_18 ,
T_1 V_29 ,
void * V_30 ,
T_1 V_31 )
{
void * V_3 = F_13 ( V_18 ) ;
T_1 V_27 = F_14 ( V_18 ) ;
T_1 V_28 ;
if ( V_31 > V_27 - V_29 ) {
V_28 = V_27 - V_29 ;
memcpy ( V_3 + V_29 , V_30 , V_28 ) ;
memcpy ( V_3 , V_30 + V_28 , V_31 - V_28 ) ;
} else
memcpy ( V_3 + V_29 , V_30 , V_31 ) ;
V_29 += V_31 ;
V_29 %= V_27 ;
return V_29 ;
}
void F_18 ( struct V_1 * V_18 ,
struct V_32 * V_33 )
{
T_1 V_34 ;
T_1 V_35 ;
if ( V_18 -> V_3 ) {
F_4 ( V_18 ,
& V_35 ,
& V_34 ) ;
V_33 -> V_35 = V_35 ;
V_33 -> V_34 = V_34 ;
V_33 -> V_36 =
V_18 -> V_3 -> V_8 ;
V_33 -> V_37 =
V_18 -> V_3 -> V_13 ;
V_33 -> V_38 =
V_18 -> V_3 -> V_4 ;
}
}
int F_19 ( struct V_1 * V_18 ,
void * V_23 , T_1 V_39 )
{
if ( sizeof( struct V_40 ) != V_41 )
return - V_42 ;
memset ( V_18 , 0 , sizeof( struct V_1 ) ) ;
V_18 -> V_3 = (struct V_40 * ) V_23 ;
V_18 -> V_3 -> V_8 =
V_18 -> V_3 -> V_13 = 0 ;
V_18 -> V_3 -> V_43 . V_44 = 1 ;
V_18 -> V_45 = V_39 ;
V_18 -> V_17 = V_39 - sizeof( struct V_40 ) ;
F_20 ( & V_18 -> V_46 ) ;
return 0 ;
}
void F_21 ( struct V_1 * V_18 )
{
}
int F_22 ( struct V_1 * V_47 ,
struct V_48 * V_49 , T_1 V_50 , bool * signal )
{
int V_51 = 0 ;
T_1 V_34 ;
T_1 V_35 ;
T_1 V_52 = 0 ;
T_1 V_20 ;
T_1 V_7 ;
T_2 V_53 = 0 ;
unsigned long V_54 ;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ )
V_52 += V_49 [ V_51 ] . V_55 ;
V_52 += sizeof( T_2 ) ;
F_23 ( & V_47 -> V_46 , V_54 ) ;
F_4 ( V_47 ,
& V_35 ,
& V_34 ) ;
if ( V_34 <= V_52 ) {
F_24 ( & V_47 -> V_46 , V_54 ) ;
return - V_56 ;
}
V_20 = F_8 ( V_47 ) ;
V_7 = V_20 ;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ ) {
V_20 = F_17 ( V_47 ,
V_20 ,
V_49 [ V_51 ] . V_57 ,
V_49 [ V_51 ] . V_55 ) ;
}
V_53 = F_15 ( V_47 ) ;
V_20 = F_17 ( V_47 ,
V_20 ,
& V_53 ,
sizeof( T_2 ) ) ;
F_2 () ;
F_9 ( V_47 , V_20 ) ;
F_24 ( & V_47 -> V_46 , V_54 ) ;
* signal = F_5 ( V_7 , V_47 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_58 ,
void * V_23 , T_1 V_39 , T_1 * V_59 ,
T_2 * V_60 , bool * signal , bool V_61 )
{
T_1 V_34 ;
T_1 V_35 ;
T_1 V_22 = 0 ;
T_2 V_53 = 0 ;
unsigned long V_54 ;
struct V_62 V_63 ;
T_1 V_21 ;
T_1 V_64 ;
int V_65 = 0 ;
if ( V_39 <= 0 )
return - V_42 ;
F_23 ( & V_58 -> V_46 , V_54 ) ;
* V_59 = 0 ;
* V_60 = 0 ;
F_4 ( V_58 ,
& V_35 ,
& V_34 ) ;
if ( V_35 < sizeof( V_63 ) ) {
goto V_66;
}
V_22 = F_10 ( V_58 ) ;
V_22 = F_16 ( V_58 , & V_63 ,
sizeof( V_63 ) ,
V_22 ) ;
V_21 = V_61 ? 0 : ( V_63 . V_67 << 3 ) ;
V_64 = ( V_63 . V_68 << 3 ) - V_21 ;
* V_59 = V_64 ;
* V_60 = V_63 . V_69 ;
if ( V_35 < V_64 + V_21 ) {
V_65 = - V_56 ;
goto V_66;
}
if ( V_64 > V_39 ) {
V_65 = - V_70 ;
goto V_66;
}
V_22 =
F_11 ( V_58 , V_21 ) ;
V_22 = F_16 ( V_58 ,
V_23 ,
V_64 ,
V_22 ) ;
V_22 = F_16 ( V_58 ,
& V_53 ,
sizeof( T_2 ) ,
V_22 ) ;
F_2 () ;
F_12 ( V_58 , V_22 ) ;
* signal = F_7 ( V_34 , V_58 ) ;
V_66:
F_24 ( & V_58 -> V_46 , V_54 ) ;
return V_65 ;
}
