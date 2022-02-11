static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 ) {
F_2 ( & V_2 -> V_5 ) ;
F_3 ( V_3 | V_6 , V_2 -> V_7 ) ;
}
F_3 ( V_3 , V_2 -> V_7 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_9 )
{
F_3 ( V_8 , V_2 -> V_7 + 0x80 + V_9 ) ;
}
static inline T_2 F_5 ( struct V_1 * V_2 )
{
return F_6 ( V_2 -> V_7 + 0x04 ) ;
}
static inline T_2 F_7 ( struct V_1 * V_2 , T_1 V_9 )
{
return F_8 ( V_2 -> V_7 + V_10 + V_9 ) ;
}
static inline T_1 F_9 ( struct V_1 * V_2 , T_1 V_9 )
{
return F_10 ( V_2 -> V_7 + V_10 + V_9 ) ;
}
static inline int F_11 ( struct V_1 * V_2 )
{
T_1 V_11 = F_5 ( V_2 ) ;
T_1 V_12 = 100000 ;
while ( ( V_11 & F_12 ( 0 ) ) && -- V_12 ) {
F_13 ( 1 ) ;
V_11 = F_5 ( V_2 ) ;
}
if ( V_11 & F_12 ( 0 ) ) {
F_14 ( V_2 -> V_13 , L_1 ) ;
return - V_14 ;
}
if ( V_11 & F_12 ( 1 ) )
return - V_15 ;
return 0 ;
}
static inline int F_15 ( struct V_1 * V_2 )
{
int V_11 ;
if ( ! F_16 ( & V_2 -> V_5 , 3 * V_16 ) ) {
F_14 ( V_2 -> V_13 , L_2 ) ;
return - V_14 ;
}
V_11 = F_5 ( V_2 ) ;
if ( V_11 & F_12 ( 1 ) )
return - V_15 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return V_2 -> V_4 ? F_15 ( V_2 ) : F_11 ( V_2 ) ;
}
static int F_18 ( T_3 * V_17 , T_2 * V_8 , T_1 V_18 , T_1 V_19 , T_1 V_20 )
{
struct V_1 * V_2 = & V_21 ;
int V_22 ;
T_1 V_9 = 0 ;
int V_23 ;
T_2 V_24 [ V_25 ] ;
T_1 * V_26 = ( T_1 * ) & V_24 ;
memset ( V_24 , 0 , sizeof( V_24 ) ) ;
F_19 ( & V_27 ) ;
if ( V_2 -> V_13 == NULL ) {
F_20 ( & V_27 ) ;
return - V_28 ;
}
for ( V_22 = 0 ; V_22 < V_18 ; V_22 ++ , V_9 += 2 ) {
V_24 [ V_9 ] = V_17 [ V_22 ] ;
V_24 [ V_9 + 1 ] = V_17 [ V_22 ] >> 8 ;
}
if ( V_20 == V_29 ) {
for ( V_22 = 0 , V_9 = 0 ; V_22 < V_18 ; V_22 ++ , V_9 += 4 )
F_4 ( V_2 , V_26 [ V_22 ] , V_9 ) ;
F_1 ( V_2 , ( V_18 * 2 ) << 16 | V_20 << 12 | 0 << 8 | V_19 ) ;
} else if ( V_20 == V_30 ) {
for ( V_22 = 0 ; V_22 < V_18 ; V_22 ++ , V_9 += 1 )
V_24 [ V_9 ] = V_8 [ V_22 ] ;
for ( V_22 = 0 , V_9 = 0 ; V_22 < V_18 ; V_22 ++ , V_9 += 4 )
F_4 ( V_2 , V_26 [ V_22 ] , V_9 ) ;
F_1 ( V_2 , ( V_18 * 3 ) << 16 | V_20 << 12 | 0 << 8 | V_19 ) ;
} else if ( V_20 == V_31 ) {
V_24 [ V_9 ] = V_8 [ 0 ] ;
V_24 [ V_9 + 1 ] = V_8 [ 1 ] ;
F_4 ( V_2 , V_26 [ 0 ] , 0 ) ;
F_1 ( V_2 , 4 << 16 | V_20 << 12 | 0 << 8 | V_19 ) ;
}
V_23 = F_17 ( V_2 ) ;
if ( ! V_23 && V_20 == V_29 ) {
F_21 ( V_24 , V_2 -> V_7 + 0x90 , 16 ) ;
for ( V_22 = 0 ; V_22 < V_18 ; V_22 ++ )
V_8 [ V_22 ] = F_7 ( V_2 , V_22 ) ;
}
F_20 ( & V_27 ) ;
return V_23 ;
}
int F_22 ( T_3 V_17 , T_2 * V_8 )
{
return F_18 ( & V_17 , V_8 , 1 , V_32 , V_29 ) ;
}
int F_23 ( T_3 V_17 , T_3 * V_8 )
{
T_3 V_33 [ 2 ] = { V_17 , V_17 + 1 } ;
return F_18 ( V_33 , ( T_2 * ) V_8 , 2 , V_32 , V_29 ) ;
}
int F_24 ( T_3 V_17 , T_1 * V_8 )
{
T_3 V_33 [ 4 ] = { V_17 , V_17 + 1 , V_17 + 2 , V_17 + 3 } ;
return F_18 ( V_33 , ( T_2 * ) V_8 , 4 , V_32 , V_29 ) ;
}
int F_25 ( T_3 V_17 , T_2 V_8 )
{
return F_18 ( & V_17 , & V_8 , 1 , V_32 , V_30 ) ;
}
int F_26 ( T_3 V_17 , T_3 V_8 )
{
T_3 V_33 [ 2 ] = { V_17 , V_17 + 1 } ;
return F_18 ( V_33 , ( T_2 * ) & V_8 , 2 , V_32 , V_30 ) ;
}
int F_27 ( T_3 V_17 , T_1 V_8 )
{
T_3 V_33 [ 4 ] = { V_17 , V_17 + 1 , V_17 + 2 , V_17 + 3 } ;
return F_18 ( V_33 , ( T_2 * ) & V_8 , 4 , V_32 , V_30 ) ;
}
int F_28 ( T_3 * V_17 , T_2 * V_8 , int V_34 )
{
return F_18 ( V_17 , V_8 , V_34 , V_32 , V_29 ) ;
}
int F_29 ( T_3 * V_17 , T_2 * V_8 , int V_34 )
{
return F_18 ( V_17 , V_8 , V_34 , V_32 , V_30 ) ;
}
int F_30 ( T_3 V_17 , T_2 V_35 , T_2 V_36 )
{
T_2 V_8 [ 2 ] = { V_35 , V_36 } ;
return F_18 ( & V_17 , V_8 , 1 , V_32 , V_31 ) ;
}
int F_31 ( int V_3 , int V_37 )
{
struct V_1 * V_2 = & V_21 ;
int V_23 ;
F_19 ( & V_27 ) ;
if ( V_2 -> V_13 == NULL ) {
F_20 ( & V_27 ) ;
return - V_28 ;
}
F_1 ( V_2 , V_37 << 12 | V_3 ) ;
V_23 = F_17 ( V_2 ) ;
F_20 ( & V_27 ) ;
return V_23 ;
}
int F_32 ( int V_3 , int V_37 , T_1 * V_38 , int V_39 ,
T_1 * V_40 , int V_41 )
{
struct V_1 * V_2 = & V_21 ;
int V_42 , V_23 ;
F_19 ( & V_27 ) ;
if ( V_2 -> V_13 == NULL ) {
F_20 ( & V_27 ) ;
return - V_28 ;
}
for ( V_42 = 0 ; V_42 < V_39 ; V_42 ++ )
F_4 ( V_2 , * V_38 ++ , 4 * V_42 ) ;
F_1 ( V_2 , ( V_39 << 16 ) | ( V_37 << 12 ) | V_3 ) ;
V_23 = F_17 ( V_2 ) ;
if ( ! V_23 ) {
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ )
* V_40 ++ = F_9 ( V_2 , 4 * V_42 ) ;
}
F_20 ( & V_27 ) ;
return V_23 ;
}
int F_33 ( int V_3 , int V_37 , T_2 * V_38 , int V_39 ,
T_1 * V_40 , int V_41 , T_1 V_43 , T_1 V_44 )
{
struct V_1 * V_2 = & V_21 ;
int V_45 = F_34 ( V_39 , 4 ) ;
T_1 V_46 [ 4 ] ;
int V_42 , V_23 ;
if ( V_45 > 4 )
return - V_47 ;
F_19 ( & V_27 ) ;
if ( V_2 -> V_13 == NULL ) {
F_20 ( & V_27 ) ;
return - V_28 ;
}
F_3 ( V_43 , V_2 -> V_7 + V_48 ) ;
F_3 ( V_44 , V_2 -> V_7 + V_49 ) ;
memcpy ( V_46 , V_38 , V_39 ) ;
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ )
F_4 ( V_2 , V_46 [ V_42 ] , 4 * V_42 ) ;
F_1 ( V_2 , ( V_39 << 16 ) | ( V_37 << 12 ) | V_3 ) ;
V_23 = F_17 ( V_2 ) ;
if ( ! V_23 ) {
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ )
* V_40 ++ = F_9 ( V_2 , 4 * V_42 ) ;
}
F_20 ( & V_27 ) ;
return V_23 ;
}
int F_35 ( T_1 V_17 , T_1 * V_8 )
{
struct V_1 * V_2 = & V_21 ;
T_1 V_3 = 0 ;
F_19 ( & V_27 ) ;
if ( V_2 -> V_13 == NULL ) {
F_20 ( & V_27 ) ;
return - V_28 ;
}
V_3 = ( V_17 >> 24 ) & 0xFF ;
if ( V_3 == V_50 ) {
F_3 ( V_17 , V_2 -> V_51 + V_52 ) ;
F_36 ( 1 ) ;
* V_8 = F_10 ( V_2 -> V_51 + V_53 ) ;
} else if ( V_3 == V_54 ) {
F_3 ( * V_8 , V_2 -> V_51 + V_53 ) ;
F_36 ( 1 ) ;
F_3 ( V_17 , V_2 -> V_51 + V_52 ) ;
} else {
F_14 ( V_2 -> V_13 ,
L_3 , V_3 ) ;
F_20 ( & V_27 ) ;
return - V_15 ;
}
F_20 ( & V_27 ) ;
return 0 ;
}
static T_4 F_37 ( int V_55 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
if ( V_2 -> V_4 )
F_38 ( & V_2 -> V_5 ) ;
return V_57 ;
}
static int F_39 ( struct V_58 * V_59 , const struct V_60 * V_20 )
{
int V_23 ;
struct V_1 * V_2 = & V_21 ;
struct V_61 * V_62 ;
if ( V_2 -> V_13 )
return - V_63 ;
V_62 = (struct V_61 * ) V_20 -> V_64 ;
if ( ! V_62 )
return - V_28 ;
V_2 -> V_4 = V_62 -> V_4 ;
V_23 = F_40 ( V_59 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_41 ( V_59 , 1 << 0 , F_42 ( V_59 ) ) ;
if ( V_23 )
return V_23 ;
F_43 ( & V_2 -> V_5 ) ;
V_2 -> V_7 = F_44 ( V_59 ) [ 0 ] ;
V_2 -> V_51 = F_45 ( V_62 -> V_51 , V_62 -> V_65 ) ;
if ( ! V_2 -> V_51 )
return - V_66 ;
V_23 = F_46 ( & V_59 -> V_13 , V_59 -> V_55 , F_37 , 0 , L_4 ,
V_2 ) ;
if ( V_23 )
return V_23 ;
V_2 -> V_13 = & V_59 -> V_13 ;
F_47 () ;
F_48 ( V_59 , V_2 ) ;
return 0 ;
}
