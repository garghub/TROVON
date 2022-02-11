static inline T_1 F_1 ( T_2 * V_1 )
{
T_1 V_2 ;
V_2 = V_1 [ 0 ] ;
V_2 |= ( V_1 [ 1 ] << 8 ) ;
return V_2 ;
}
static inline T_3 F_2 ( T_2 * V_1 )
{
T_3 V_3 = 0 ;
T_3 V_4 = V_5 ;
V_3 |= V_1 [ V_4 ++ ] ;
V_3 |= ( V_1 [ V_4 ++ ] << 8 ) ;
V_3 |= ( V_1 [ V_4 ++ ] << 16 ) ;
V_3 |= ( V_1 [ V_4 ] << 24 ) ;
return V_3 ;
}
static inline T_3 F_3 ( T_2 * V_1 )
{
T_3 V_3 = 0 ;
T_3 V_4 = ( V_5 + 4 ) ;
V_3 |= V_1 [ V_4 ++ ] ;
V_3 |= ( V_1 [ V_4 ++ ] << 8 ) ;
V_3 |= ( V_1 [ V_4 ++ ] << 16 ) ;
V_3 |= ( V_1 [ V_4 ] << 24 ) ;
return V_3 ;
}
static inline enum V_6 F_4 ( T_2 * V_7 )
{
return ( (enum V_6 ) ( V_7 [ 0 ] & 0xFC ) ) ;
}
static inline T_2 F_5 ( T_2 * V_7 )
{
return ( V_7 [ 1 ] & 0x01 ) ;
}
static inline T_2 F_6 ( T_2 * V_7 )
{
return ( ( V_7 [ 1 ] & 0x02 ) >> 1 ) ;
}
static inline void F_7 ( T_2 * V_8 , T_2 * V_9 )
{
memcpy ( V_9 , V_8 + 4 , 6 ) ;
}
static inline void F_8 ( T_2 * V_8 , T_2 * V_9 )
{
memcpy ( V_9 , V_8 + 10 , 6 ) ;
}
static inline void F_9 ( T_2 * V_8 , T_2 * V_9 )
{
memcpy ( V_9 , V_8 + 16 , 6 ) ;
}
static inline void F_10 ( T_2 * V_1 , T_2 * V_10 )
{
if ( F_6 ( V_1 ) == 1 )
F_8 ( V_1 , V_10 ) ;
else if ( F_5 ( V_1 ) == 1 )
F_7 ( V_1 , V_10 ) ;
else
F_9 ( V_1 , V_10 ) ;
}
static inline void F_11 ( T_2 * V_1 , T_2 * V_11 , T_2 * V_12 )
{
T_2 V_13 = 0 ;
T_2 V_14 = 0 ;
T_2 V_15 = 0 ;
V_13 = V_1 [ V_16 + 1 ] ;
V_15 = V_16 + 2 ;
if ( V_13 >= V_17 )
V_13 = 0 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ , V_15 ++ )
V_11 [ V_14 ] = V_1 [ V_15 ] ;
V_11 [ V_13 ] = '\0' ;
* V_12 = V_13 ;
}
static inline T_1 F_12 ( T_2 * V_1 )
{
T_1 V_18 = 0 ;
T_1 V_4 = V_5 ;
enum V_6 V_19 ;
V_19 = F_4 ( V_1 ) ;
if ( ( V_19 == V_20 ) || ( V_19 == V_21 ) )
V_4 += V_22 + V_23 ;
V_18 = V_1 [ V_4 ] ;
V_18 |= ( V_1 [ V_4 + 1 ] << 8 ) ;
return V_18 ;
}
static inline T_1 F_13 ( T_2 * V_1 )
{
T_1 V_18 ;
V_18 = V_1 [ 0 ] ;
V_18 |= ( V_1 [ 1 ] << 8 ) ;
return V_18 ;
}
static inline T_1 F_14 ( T_2 * V_1 )
{
T_1 V_24 ;
V_24 = V_1 [ 3 ] ;
V_24 = ( V_24 << 8 ) | V_1 [ 2 ] ;
return V_24 ;
}
static inline T_1 F_15 ( T_2 * V_1 )
{
T_1 V_25 ;
V_25 = V_1 [ 4 ] ;
V_25 |= ( V_1 [ 5 ] << 8 ) ;
return V_25 ;
}
static T_2 * F_16 ( T_2 * V_8 , T_1 V_26 , T_1 V_27 )
{
T_1 V_4 ;
V_4 = V_27 ;
while ( V_4 < ( V_26 - V_28 ) ) {
if ( V_8 [ V_4 ] == V_29 )
return & V_8 [ V_4 ] ;
V_4 += ( V_30 + V_8 [ V_4 + 1 ] ) ;
}
return NULL ;
}
static T_2 F_17 ( T_2 * V_8 , T_1 V_26 )
{
T_1 V_4 ;
V_4 = V_16 ;
while ( V_4 < ( V_26 - V_28 ) ) {
if ( V_8 [ V_4 ] == V_31 )
return V_8 [ V_4 + 2 ] ;
V_4 += V_8 [ V_4 + 1 ] + V_30 ;
}
return 0 ;
}
T_4 F_18 ( T_2 * V_32 ,
struct V_33 * * V_34 )
{
struct V_33 * V_33 = NULL ;
T_2 V_35 = 0 ;
T_2 V_36 = 0 ;
T_1 V_37 = 0 ;
T_1 V_38 = ( T_1 ) V_39 ;
T_1 V_40 = 0 ;
T_2 * V_41 = NULL ;
V_35 = V_32 [ 0 ] ;
if ( 'N' != V_35 )
return - V_42 ;
V_36 = V_32 [ 1 ] ;
V_37 = F_19 ( V_32 [ 2 ] , V_32 [ 3 ] ) ;
V_38 = F_19 ( V_32 [ 4 ] , V_32 [ 5 ] ) ;
V_40 = F_19 ( V_32 [ 6 ] , V_32 [ 7 ] ) ;
V_41 = & V_32 [ 8 ] ;
{
T_2 * V_43 = NULL ;
T_1 V_26 = 0 ;
T_2 * V_44 = NULL ;
T_2 * V_45 = NULL ;
T_1 V_46 = 0 ;
T_2 V_4 = 0 ;
T_3 V_47 ;
T_3 V_48 ;
V_33 = F_20 ( sizeof( * V_33 ) , V_49 ) ;
if ( ! V_33 )
return - V_50 ;
V_33 -> V_51 = V_41 [ 0 ] ;
V_43 = & V_41 [ 1 ] ;
V_26 = V_40 - 1 ;
V_33 -> V_18 = F_12 ( V_43 ) ;
V_33 -> V_47 = F_2 ( V_43 ) ;
V_47 = F_2 ( V_43 ) ;
V_48 = F_3 ( V_43 ) ;
V_33 -> V_48 = V_47 | ( ( V_52 ) V_48 << 32 ) ;
F_11 ( V_43 , V_33 -> V_11 , & V_33 -> V_53 ) ;
F_10 ( V_43 , V_33 -> V_10 ) ;
V_33 -> V_54 = F_17 ( V_43 ,
V_26 + V_28 ) ;
V_4 = V_5 + V_22 ;
V_33 -> V_55 = F_1 ( V_43 + V_4 ) ;
V_4 += V_23 + V_56 ;
V_44 = F_16 ( V_43 , V_26 + V_28 , V_4 ) ;
if ( V_44 )
V_33 -> V_57 = V_44 [ 3 ] ;
V_45 = & V_43 [ V_16 ] ;
V_46 = V_26 - V_16 ;
if ( V_46 > 0 ) {
V_33 -> V_45 = F_21 ( V_45 , V_46 , V_49 ) ;
if ( ! V_33 -> V_45 ) {
F_22 ( V_33 ) ;
return - V_50 ;
}
}
V_33 -> V_46 = V_46 ;
}
* V_34 = V_33 ;
return 0 ;
}
T_4 F_23 ( T_2 * V_58 , T_3 V_59 ,
struct V_60 * * V_61 )
{
struct V_60 * V_60 = NULL ;
T_1 V_62 = 0 ;
T_2 * V_45 = NULL ;
T_1 V_46 = 0 ;
V_60 = F_20 ( sizeof( * V_60 ) , V_49 ) ;
if ( ! V_60 )
return - V_50 ;
V_62 = ( T_1 ) V_59 ;
V_60 -> V_63 = F_14 ( V_58 ) ;
if ( V_60 -> V_63 == V_64 ) {
V_60 -> V_65 = F_13 ( V_58 ) ;
V_60 -> V_66 = F_15 ( V_58 ) ;
V_45 = & V_58 [ V_56 + V_67 + V_68 ] ;
V_46 = V_62 - ( V_56 + V_67 +
V_68 ) ;
V_60 -> V_45 = F_21 ( V_45 , V_46 , V_49 ) ;
if ( ! V_60 -> V_45 ) {
F_22 ( V_60 ) ;
return - V_50 ;
}
V_60 -> V_46 = V_46 ;
}
* V_61 = V_60 ;
return 0 ;
}
