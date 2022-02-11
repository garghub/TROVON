static inline void F_1 ( T_1 V_1 )
{
if ( V_2 . V_3 ) {
F_2 ( & V_2 . V_4 ) ;
F_3 ( V_1 | V_5 , V_2 . V_6 ) ;
}
F_3 ( V_1 , V_2 . V_6 ) ;
}
static inline void F_4 ( T_1 V_7 , T_1 V_8 )
{
F_3 ( V_7 , V_2 . V_6 + 0x80 + V_8 ) ;
}
static inline T_2 F_5 ( void )
{
return F_6 ( V_2 . V_6 + 0x04 ) ;
}
static inline T_2 F_7 ( T_1 V_8 )
{
return F_8 ( V_2 . V_6 + V_9 + V_8 ) ;
}
static inline T_1 F_9 ( T_1 V_8 )
{
return F_10 ( V_2 . V_6 + V_9 + V_8 ) ;
}
static inline int F_11 ( void )
{
T_1 V_10 = F_5 () ;
T_1 V_11 = 100000 ;
while ( ( V_10 & F_12 ( 0 ) ) && -- V_11 ) {
F_13 ( 1 ) ;
V_10 = F_5 () ;
}
if ( V_10 & F_12 ( 0 ) ) {
F_14 ( & V_2 . V_12 -> V_13 , L_1 ) ;
return - V_14 ;
}
if ( V_10 & F_12 ( 1 ) )
return - V_15 ;
return 0 ;
}
static inline int F_15 ( void )
{
int V_10 ;
if ( ! F_16 ( & V_2 . V_4 , 3 * V_16 ) ) {
struct V_17 * V_13 = & V_2 . V_12 -> V_13 ;
F_14 ( V_13 , L_2 ) ;
return - V_14 ;
}
V_10 = F_5 () ;
if ( V_10 & F_12 ( 1 ) )
return - V_15 ;
return 0 ;
}
static int F_17 ( void )
{
return V_2 . V_3 ? F_15 () : F_11 () ;
}
static int F_18 ( T_3 * V_18 , T_2 * V_7 , T_1 V_19 , T_1 V_20 , T_1 V_21 )
{
int V_22 ;
T_1 V_8 = 0 ;
int V_23 ;
T_2 V_24 [ V_25 ] ;
T_1 * V_26 = ( T_1 * ) & V_24 ;
memset ( V_24 , 0 , sizeof( V_24 ) ) ;
F_19 ( & V_27 ) ;
if ( V_2 . V_12 == NULL ) {
F_20 ( & V_27 ) ;
return - V_28 ;
}
for ( V_22 = 0 ; V_22 < V_19 ; V_22 ++ , V_8 += 2 ) {
V_24 [ V_8 ] = V_18 [ V_22 ] ;
V_24 [ V_8 + 1 ] = V_18 [ V_22 ] >> 8 ;
}
if ( V_21 == V_29 ) {
for ( V_22 = 0 , V_8 = 0 ; V_22 < V_19 ; V_22 ++ , V_8 += 4 )
F_4 ( V_26 [ V_22 ] , V_8 ) ;
F_1 ( ( V_19 * 2 ) << 16 | V_21 << 12 | 0 << 8 | V_20 ) ;
} else if ( V_21 == V_30 ) {
for ( V_22 = 0 ; V_22 < V_19 ; V_22 ++ , V_8 += 1 )
V_24 [ V_8 ] = V_7 [ V_22 ] ;
for ( V_22 = 0 , V_8 = 0 ; V_22 < V_19 ; V_22 ++ , V_8 += 4 )
F_4 ( V_26 [ V_22 ] , V_8 ) ;
F_1 ( ( V_19 * 3 ) << 16 | V_21 << 12 | 0 << 8 | V_20 ) ;
} else if ( V_21 == V_31 ) {
V_24 [ V_8 ] = V_7 [ 0 ] ;
V_24 [ V_8 + 1 ] = V_7 [ 1 ] ;
F_4 ( V_26 [ 0 ] , 0 ) ;
F_1 ( 4 << 16 | V_21 << 12 | 0 << 8 | V_20 ) ;
}
V_23 = F_17 () ;
if ( ! V_23 && V_21 == V_29 ) {
F_21 ( V_24 , V_2 . V_6 + 0x90 , 16 ) ;
for ( V_22 = 0 ; V_22 < V_19 ; V_22 ++ )
V_7 [ V_22 ] = F_7 ( V_22 ) ;
}
F_20 ( & V_27 ) ;
return V_23 ;
}
int F_22 ( T_3 V_18 , T_2 * V_7 )
{
return F_18 ( & V_18 , V_7 , 1 , V_32 , V_29 ) ;
}
int F_23 ( T_3 V_18 , T_3 * V_7 )
{
T_3 V_33 [ 2 ] = { V_18 , V_18 + 1 } ;
return F_18 ( V_33 , ( T_2 * ) V_7 , 2 , V_32 , V_29 ) ;
}
int F_24 ( T_3 V_18 , T_1 * V_7 )
{
T_3 V_33 [ 4 ] = { V_18 , V_18 + 1 , V_18 + 2 , V_18 + 3 } ;
return F_18 ( V_33 , ( T_2 * ) V_7 , 4 , V_32 , V_29 ) ;
}
int F_25 ( T_3 V_18 , T_2 V_7 )
{
return F_18 ( & V_18 , & V_7 , 1 , V_32 , V_30 ) ;
}
int F_26 ( T_3 V_18 , T_3 V_7 )
{
T_3 V_33 [ 2 ] = { V_18 , V_18 + 1 } ;
return F_18 ( V_33 , ( T_2 * ) & V_7 , 2 , V_32 , V_30 ) ;
}
int F_27 ( T_3 V_18 , T_1 V_7 )
{
T_3 V_33 [ 4 ] = { V_18 , V_18 + 1 , V_18 + 2 , V_18 + 3 } ;
return F_18 ( V_33 , ( T_2 * ) & V_7 , 4 , V_32 , V_30 ) ;
}
int F_28 ( T_3 * V_18 , T_2 * V_7 , int V_34 )
{
return F_18 ( V_18 , V_7 , V_34 , V_32 , V_29 ) ;
}
int F_29 ( T_3 * V_18 , T_2 * V_7 , int V_34 )
{
return F_18 ( V_18 , V_7 , V_34 , V_32 , V_30 ) ;
}
int F_30 ( T_3 V_18 , T_2 V_35 , T_2 V_36 )
{
T_2 V_7 [ 2 ] = { V_35 , V_36 } ;
return F_18 ( & V_18 , V_7 , 1 , V_32 , V_31 ) ;
}
int F_31 ( int V_1 , int V_37 )
{
int V_23 ;
F_19 ( & V_27 ) ;
if ( V_2 . V_12 == NULL ) {
F_20 ( & V_27 ) ;
return - V_28 ;
}
F_1 ( V_37 << 12 | V_1 ) ;
V_23 = F_17 () ;
F_20 ( & V_27 ) ;
return V_23 ;
}
int F_32 ( int V_1 , int V_37 , T_1 * V_38 , int V_39 ,
T_1 * V_40 , int V_41 )
{
int V_42 , V_23 ;
F_19 ( & V_27 ) ;
if ( V_2 . V_12 == NULL ) {
F_20 ( & V_27 ) ;
return - V_28 ;
}
for ( V_42 = 0 ; V_42 < V_39 ; V_42 ++ )
F_4 ( * V_38 ++ , 4 * V_42 ) ;
F_1 ( ( V_39 << 16 ) | ( V_37 << 12 ) | V_1 ) ;
V_23 = F_17 () ;
if ( ! V_23 ) {
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ )
* V_40 ++ = F_9 ( 4 * V_42 ) ;
}
F_20 ( & V_27 ) ;
return V_23 ;
}
int F_33 ( T_1 V_18 , T_1 * V_7 )
{
T_1 V_1 = 0 ;
F_19 ( & V_27 ) ;
if ( V_2 . V_12 == NULL ) {
F_20 ( & V_27 ) ;
return - V_28 ;
}
V_1 = ( V_18 >> 24 ) & 0xFF ;
if ( V_1 == V_43 ) {
F_3 ( V_18 , V_2 . V_44 + V_45 ) ;
F_34 ( 1 ) ;
* V_7 = F_10 ( V_2 . V_44 + V_46 ) ;
} else if ( V_1 == V_47 ) {
F_3 ( * V_7 , V_2 . V_44 + V_46 ) ;
F_34 ( 1 ) ;
F_3 ( V_18 , V_2 . V_44 + V_45 ) ;
} else {
F_14 ( & V_2 . V_12 -> V_13 ,
L_3 , V_1 ) ;
F_20 ( & V_27 ) ;
return - V_15 ;
}
F_20 ( & V_27 ) ;
return 0 ;
}
static T_4 F_35 ( int V_48 , void * V_49 )
{
if ( V_2 . V_3 )
F_36 ( & V_2 . V_4 ) ;
return V_50 ;
}
static int F_37 ( struct V_51 * V_13 , const struct V_52 * V_21 )
{
int V_23 ;
struct V_53 * V_54 ;
T_5 V_55 ;
if ( V_2 . V_12 )
return - V_56 ;
V_54 = (struct V_53 * ) V_21 -> V_57 ;
V_2 . V_12 = F_38 ( V_13 ) ;
V_2 . V_3 = V_54 -> V_3 ;
V_23 = F_39 ( V_13 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_40 ( V_13 , L_4 ) ;
if ( V_23 )
return V_23 ;
V_55 = F_41 ( V_13 , 0 ) ;
if ( ! V_55 )
return - V_58 ;
F_42 ( & V_2 . V_4 ) ;
if ( F_43 ( V_13 -> V_48 , F_35 , 0 , L_4 , & V_2 ) )
return - V_56 ;
V_2 . V_6 = F_44 ( V_55 , F_45 ( V_13 , 0 ) ) ;
if ( ! V_2 . V_6 )
return - V_58 ;
V_2 . V_44 = F_44 ( V_54 -> V_44 , V_54 -> V_59 ) ;
if ( ! V_2 . V_44 ) {
F_46 ( V_2 . V_6 ) ;
return - V_58 ;
}
F_47 () ;
return 0 ;
}
static void F_48 ( struct V_51 * V_12 )
{
F_49 ( V_12 -> V_48 , & V_2 ) ;
F_50 ( V_12 ) ;
F_51 ( V_2 . V_12 ) ;
F_46 ( V_2 . V_6 ) ;
F_46 ( V_2 . V_44 ) ;
V_2 . V_12 = NULL ;
F_52 () ;
}
static int T_6 F_53 ( void )
{
int V_60 ;
V_60 = F_54 () ;
if ( V_60 == 0 )
return - V_28 ;
return F_55 ( & V_61 ) ;
}
static void T_7 F_56 ( void )
{
F_57 ( & V_61 ) ;
}
