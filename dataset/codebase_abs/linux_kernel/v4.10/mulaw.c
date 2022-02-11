static inline int F_1 ( int V_1 )
{
int V_2 = 0 ;
V_1 >>= 7 ;
if ( V_1 & 0xf0 ) {
V_1 >>= 4 ;
V_2 += 4 ;
}
if ( V_1 & 0x0c ) {
V_1 >>= 2 ;
V_2 += 2 ;
}
if ( V_1 & 0x02 )
V_2 += 1 ;
return V_2 ;
}
static unsigned char F_2 ( int V_3 )
{
int V_4 ;
int V_5 ;
unsigned char V_6 ;
if ( V_3 < 0 ) {
V_3 = V_7 - V_3 ;
V_4 = 0x7F ;
} else {
V_3 += V_7 ;
V_4 = 0xFF ;
}
if ( V_3 > 0x7FFF )
V_3 = 0x7FFF ;
V_5 = F_1 ( V_3 ) ;
V_6 = ( V_5 << 4 ) | ( ( V_3 >> ( V_5 + 3 ) ) & 0xF ) ;
return V_6 ^ V_4 ;
}
static int F_3 ( unsigned char V_8 )
{
int V_9 ;
V_8 = ~ V_8 ;
V_9 = ( ( V_8 & V_10 ) << 3 ) + V_7 ;
V_9 <<= ( ( unsigned ) V_8 & V_11 ) >> V_12 ;
return ( ( V_8 & V_13 ) ? ( V_7 - V_9 ) : ( V_9 - V_7 ) ) ;
}
static inline void F_4 ( struct V_14 * V_15 ,
unsigned char * V_16 , T_1 V_17 )
{
V_17 ^= V_15 -> V_18 ;
if ( V_15 -> V_19 )
V_17 = F_5 ( V_17 ) ;
if ( V_15 -> V_20 > V_15 -> V_21 )
memset ( V_16 , 0 , V_15 -> V_20 ) ;
memcpy ( V_16 + V_15 -> V_22 , ( char * ) & V_17 + V_15 -> V_23 ,
V_15 -> V_21 ) ;
}
static void F_6 ( struct V_24 * V_25 ,
const struct V_26 * V_27 ,
struct V_26 * V_28 ,
T_2 V_29 )
{
struct V_14 * V_15 = (struct V_14 * ) V_25 -> V_30 ;
int V_31 ;
int V_32 = V_25 -> V_33 . V_34 ;
for ( V_31 = 0 ; V_31 < V_32 ; ++ V_31 ) {
char * V_35 ;
char * V_16 ;
int V_36 , V_37 ;
T_2 V_38 ;
if ( ! V_27 [ V_31 ] . V_39 ) {
if ( V_28 [ V_31 ] . V_40 )
F_7 ( & V_28 [ V_31 ] . V_41 , 0 , V_29 , V_25 -> V_42 . V_43 ) ;
V_28 [ V_31 ] . V_39 = 0 ;
continue;
}
V_28 [ V_31 ] . V_39 = 1 ;
V_35 = V_27 [ V_31 ] . V_41 . V_44 + V_27 [ V_31 ] . V_41 . V_45 / 8 ;
V_16 = V_28 [ V_31 ] . V_41 . V_44 + V_28 [ V_31 ] . V_41 . V_45 / 8 ;
V_36 = V_27 [ V_31 ] . V_41 . V_46 / 8 ;
V_37 = V_28 [ V_31 ] . V_41 . V_46 / 8 ;
V_38 = V_29 ;
while ( V_38 -- > 0 ) {
signed short V_17 = F_3 ( * V_35 ) ;
F_4 ( V_15 , V_16 , V_17 ) ;
V_35 += V_36 ;
V_16 += V_37 ;
}
}
}
static inline signed short F_8 ( struct V_14 * V_15 ,
unsigned char * V_35 )
{
T_1 V_17 = 0 ;
memcpy ( ( char * ) & V_17 + V_15 -> V_23 , V_35 + V_15 -> V_22 ,
V_15 -> V_21 ) ;
if ( V_15 -> V_19 )
V_17 = F_5 ( V_17 ) ;
V_17 ^= V_15 -> V_18 ;
return ( signed short ) V_17 ;
}
static void F_9 ( struct V_24 * V_25 ,
const struct V_26 * V_27 ,
struct V_26 * V_28 ,
T_2 V_29 )
{
struct V_14 * V_15 = (struct V_14 * ) V_25 -> V_30 ;
int V_31 ;
int V_32 = V_25 -> V_33 . V_34 ;
for ( V_31 = 0 ; V_31 < V_32 ; ++ V_31 ) {
char * V_35 ;
char * V_16 ;
int V_36 , V_37 ;
T_2 V_38 ;
if ( ! V_27 [ V_31 ] . V_39 ) {
if ( V_28 [ V_31 ] . V_40 )
F_7 ( & V_28 [ V_31 ] . V_41 , 0 , V_29 , V_25 -> V_42 . V_43 ) ;
V_28 [ V_31 ] . V_39 = 0 ;
continue;
}
V_28 [ V_31 ] . V_39 = 1 ;
V_35 = V_27 [ V_31 ] . V_41 . V_44 + V_27 [ V_31 ] . V_41 . V_45 / 8 ;
V_16 = V_28 [ V_31 ] . V_41 . V_44 + V_28 [ V_31 ] . V_41 . V_45 / 8 ;
V_36 = V_27 [ V_31 ] . V_41 . V_46 / 8 ;
V_37 = V_28 [ V_31 ] . V_41 . V_46 / 8 ;
V_38 = V_29 ;
while ( V_38 -- > 0 ) {
signed short V_17 = F_8 ( V_15 , V_35 ) ;
* V_16 = F_2 ( V_17 ) ;
V_35 += V_36 ;
V_16 += V_37 ;
}
}
}
static T_3 F_10 ( struct V_24 * V_25 ,
const struct V_26 * V_27 ,
struct V_26 * V_28 ,
T_2 V_29 )
{
struct V_14 * V_15 ;
if ( F_11 ( ! V_25 || ! V_27 || ! V_28 ) )
return - V_47 ;
if ( V_29 == 0 )
return 0 ;
#ifdef F_12
{
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_25 -> V_33 . V_34 ; V_31 ++ ) {
if ( F_11 ( V_27 [ V_31 ] . V_41 . V_45 % 8 ||
V_27 [ V_31 ] . V_41 . V_46 % 8 ) )
return - V_47 ;
if ( F_11 ( V_28 [ V_31 ] . V_41 . V_45 % 8 ||
V_28 [ V_31 ] . V_41 . V_46 % 8 ) )
return - V_47 ;
}
}
#endif
V_15 = (struct V_14 * ) V_25 -> V_30 ;
V_15 -> V_48 ( V_25 , V_27 , V_28 , V_29 ) ;
return V_29 ;
}
static void F_13 ( struct V_14 * V_15 , T_4 V_43 )
{
#ifdef F_14
V_15 -> V_19 = F_15 ( V_43 ) > 0 ;
#else
V_15 -> V_19 = F_16 ( V_43 ) > 0 ;
#endif
if ( ! F_17 ( V_43 ) )
V_15 -> V_18 = 0x8000 ;
V_15 -> V_20 = F_18 ( V_43 ) / 8 ;
V_15 -> V_21 = V_15 -> V_20 < 2 ? 1 : 2 ;
if ( F_16 ( V_43 ) ) {
V_15 -> V_22 = V_15 -> V_20 - V_15 -> V_21 ;
V_15 -> V_23 = 2 - V_15 -> V_21 ;
} else {
V_15 -> V_22 = V_15 -> V_20 -
F_19 ( V_43 ) / 8 ;
}
}
int F_20 ( struct V_49 * V_50 ,
struct V_51 * V_33 ,
struct V_51 * V_42 ,
struct V_24 * * V_52 )
{
int V_53 ;
struct V_14 * V_15 ;
struct V_24 * V_25 ;
struct V_51 * V_43 ;
T_5 V_48 ;
if ( F_11 ( ! V_52 ) )
return - V_47 ;
* V_52 = NULL ;
if ( F_11 ( V_33 -> V_54 != V_42 -> V_54 ) )
return - V_47 ;
if ( F_11 ( V_33 -> V_34 != V_42 -> V_34 ) )
return - V_47 ;
if ( V_42 -> V_43 == V_55 ) {
V_43 = V_33 ;
V_48 = F_9 ;
}
else if ( V_33 -> V_43 == V_55 ) {
V_43 = V_42 ;
V_48 = F_6 ;
}
else {
F_21 () ;
return - V_56 ;
}
if ( F_11 ( ! F_22 ( V_43 -> V_43 ) ) )
return - V_47 ;
V_53 = F_23 ( V_50 , L_1 ,
V_33 , V_42 ,
sizeof( struct V_14 ) , & V_25 ) ;
if ( V_53 < 0 )
return V_53 ;
V_15 = (struct V_14 * ) V_25 -> V_30 ;
V_15 -> V_48 = V_48 ;
F_13 ( V_15 , V_43 -> V_43 ) ;
V_25 -> V_57 = F_10 ;
* V_52 = V_25 ;
return 0 ;
}
