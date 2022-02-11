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
static void F_5 ( T_1 V_5 , struct V_6 * V_7 ,
bool V_8 )
{
struct V_1 * V_2 = & V_7 -> V_9 ;
F_2 () ;
if ( F_6 ( V_2 -> V_3 -> V_4 ) )
return;
F_7 () ;
if ( V_5 == F_6 ( V_2 -> V_3 -> V_10 ) )
F_8 ( V_7 ) ;
return;
}
static inline T_1
F_9 ( struct V_1 * V_11 )
{
T_1 V_12 = V_11 -> V_3 -> V_13 ;
return V_12 ;
}
static inline void
F_10 ( struct V_1 * V_11 ,
T_1 V_14 )
{
V_11 -> V_3 -> V_13 = V_14 ;
}
static inline T_1
F_11 ( struct V_1 * V_11 )
{
T_1 V_12 = V_11 -> V_3 -> V_10 ;
return V_12 ;
}
static inline T_1
F_12 ( struct V_1 * V_11 ,
T_1 V_15 )
{
T_1 V_12 = V_11 -> V_3 -> V_10 ;
V_12 += V_15 ;
V_12 %= V_11 -> V_16 ;
return V_12 ;
}
static inline void
F_13 ( struct V_1 * V_11 ,
T_1 V_17 )
{
V_11 -> V_3 -> V_10 = V_17 ;
V_11 -> V_18 = V_17 ;
}
static inline T_1
F_14 ( struct V_1 * V_11 )
{
return V_11 -> V_16 ;
}
static inline T_2
F_15 ( struct V_1 * V_11 )
{
return ( T_2 ) V_11 -> V_3 -> V_13 << 32 ;
}
static T_1 F_16 (
struct V_1 * V_11 ,
void * V_19 ,
T_1 V_20 ,
T_1 V_21 )
{
void * V_3 = F_17 ( V_11 ) ;
T_1 V_22 = F_14 ( V_11 ) ;
memcpy ( V_19 , V_3 + V_21 , V_20 ) ;
V_21 += V_20 ;
V_21 %= V_22 ;
return V_21 ;
}
static T_1 F_18 (
struct V_1 * V_11 ,
T_1 V_23 ,
void * V_24 ,
T_1 V_25 )
{
void * V_3 = F_17 ( V_11 ) ;
T_1 V_22 = F_14 ( V_11 ) ;
memcpy ( V_3 + V_23 , V_24 , V_25 ) ;
V_23 += V_25 ;
V_23 %= V_22 ;
return V_23 ;
}
void F_19 ( struct V_1 * V_11 ,
struct V_26 * V_27 )
{
T_1 V_28 ;
T_1 V_29 ;
if ( V_11 -> V_3 ) {
F_20 ( V_11 ,
& V_29 ,
& V_28 ) ;
V_27 -> V_29 = V_29 ;
V_27 -> V_28 = V_28 ;
V_27 -> V_30 =
V_11 -> V_3 -> V_10 ;
V_27 -> V_31 =
V_11 -> V_3 -> V_13 ;
V_27 -> V_32 =
V_11 -> V_3 -> V_4 ;
}
}
int F_21 ( struct V_1 * V_11 ,
struct V_33 * V_34 , T_1 V_35 )
{
int V_36 ;
struct V_33 * * V_37 ;
F_22 ( ( sizeof( struct V_38 ) != V_39 ) ) ;
memset ( V_11 , 0 , sizeof( struct V_1 ) ) ;
V_37 = F_23 ( sizeof( struct V_33 * ) * ( V_35 * 2 - 1 ) ,
V_40 ) ;
if ( ! V_37 )
return - V_41 ;
V_37 [ 0 ] = V_34 ;
for ( V_36 = 0 ; V_36 < 2 * ( V_35 - 1 ) ; V_36 ++ )
V_37 [ V_36 + 1 ] = & V_34 [ V_36 % ( V_35 - 1 ) + 1 ] ;
V_11 -> V_3 = (struct V_38 * )
F_24 ( V_37 , V_35 * 2 - 1 , V_42 , V_43 ) ;
F_25 ( V_37 ) ;
if ( ! V_11 -> V_3 )
return - V_41 ;
V_11 -> V_3 -> V_10 =
V_11 -> V_3 -> V_13 = 0 ;
V_11 -> V_3 -> V_44 . V_45 = 1 ;
V_11 -> V_46 = V_35 << V_47 ;
V_11 -> V_16 = V_11 -> V_46 -
sizeof( struct V_38 ) ;
F_26 ( & V_11 -> V_48 ) ;
return 0 ;
}
void F_27 ( struct V_1 * V_11 )
{
F_28 ( V_11 -> V_3 ) ;
}
int F_29 ( struct V_6 * V_7 ,
struct V_49 * V_50 , T_1 V_51 , bool V_52 ,
bool V_8 )
{
int V_36 = 0 ;
T_1 V_28 ;
T_1 V_53 = 0 ;
T_1 V_14 ;
T_1 V_5 ;
T_2 V_54 = 0 ;
unsigned long V_55 = 0 ;
struct V_1 * V_56 = & V_7 -> V_9 ;
for ( V_36 = 0 ; V_36 < V_51 ; V_36 ++ )
V_53 += V_50 [ V_36 ] . V_57 ;
V_53 += sizeof( T_2 ) ;
if ( V_52 )
F_30 ( & V_56 -> V_48 , V_55 ) ;
V_28 = F_31 ( V_56 ) ;
if ( V_28 <= V_53 ) {
if ( V_52 )
F_32 ( & V_56 -> V_48 , V_55 ) ;
return - V_58 ;
}
V_14 = F_9 ( V_56 ) ;
V_5 = V_14 ;
for ( V_36 = 0 ; V_36 < V_51 ; V_36 ++ ) {
V_14 = F_18 ( V_56 ,
V_14 ,
V_50 [ V_36 ] . V_59 ,
V_50 [ V_36 ] . V_57 ) ;
}
V_54 = F_15 ( V_56 ) ;
V_14 = F_18 ( V_56 ,
V_14 ,
& V_54 ,
sizeof( T_2 ) ) ;
F_2 () ;
F_10 ( V_56 , V_14 ) ;
if ( V_52 )
F_32 ( & V_56 -> V_48 , V_55 ) ;
F_5 ( V_5 , V_7 , V_8 ) ;
return 0 ;
}
int F_33 ( struct V_6 * V_7 ,
void * V_60 , T_1 V_61 , T_1 * V_62 ,
T_2 * V_63 , bool V_64 )
{
T_1 V_29 ;
T_1 V_17 = 0 ;
T_2 V_54 = 0 ;
struct V_65 V_66 ;
T_1 V_15 ;
T_1 V_67 ;
int V_68 = 0 ;
struct V_1 * V_69 = & V_7 -> V_70 ;
if ( V_61 <= 0 )
return - V_71 ;
* V_62 = 0 ;
* V_63 = 0 ;
V_29 = F_4 ( V_69 ) ;
if ( V_29 < sizeof( V_66 ) ) {
return V_68 ;
}
F_34 ( V_7 ) ;
V_17 = F_11 ( V_69 ) ;
V_17 = F_16 ( V_69 , & V_66 ,
sizeof( V_66 ) ,
V_17 ) ;
V_15 = V_64 ? 0 : ( V_66 . V_72 << 3 ) ;
V_67 = ( V_66 . V_73 << 3 ) - V_15 ;
* V_62 = V_67 ;
* V_63 = V_66 . V_74 ;
if ( V_29 < V_67 + V_15 )
return - V_58 ;
if ( V_67 > V_61 )
return - V_75 ;
V_17 =
F_12 ( V_69 , V_15 ) ;
V_17 = F_16 ( V_69 ,
V_60 ,
V_67 ,
V_17 ) ;
V_17 = F_16 ( V_69 ,
& V_54 ,
sizeof( T_2 ) ,
V_17 ) ;
F_2 () ;
F_13 ( V_69 , V_17 ) ;
F_35 ( V_7 ) ;
return V_68 ;
}
