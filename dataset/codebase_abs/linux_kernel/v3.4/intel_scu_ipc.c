static inline void F_1 ( T_1 V_1 )
{
F_2 ( V_1 , V_2 . V_3 ) ;
}
static inline void F_3 ( T_1 V_4 , T_1 V_5 )
{
F_2 ( V_4 , V_2 . V_3 + 0x80 + V_5 ) ;
}
static inline T_2 F_4 ( void )
{
return F_5 ( V_2 . V_3 + 0x04 ) ;
}
static inline T_2 F_6 ( T_1 V_5 )
{
return F_7 ( V_2 . V_3 + V_6 + V_5 ) ;
}
static inline T_1 F_8 ( T_1 V_5 )
{
return F_9 ( V_2 . V_3 + V_6 + V_5 ) ;
}
static inline int F_10 ( void )
{
T_1 V_7 = 0 ;
T_1 V_8 = 0 ;
V_7 = F_4 () ;
while ( V_7 & 1 ) {
F_11 ( 1 ) ;
V_7 = F_4 () ;
V_8 ++ ;
if ( V_8 > 100000 ) {
F_12 ( & V_2 . V_9 -> V_10 , L_1 ) ;
return - V_11 ;
}
}
if ( ( V_7 >> 1 ) & 1 )
return - V_12 ;
return 0 ;
}
static int F_13 ( T_3 * V_13 , T_2 * V_4 , T_1 V_14 , T_1 V_15 , T_1 V_16 )
{
int V_17 ;
T_1 V_5 = 0 ;
int V_18 ;
T_2 V_19 [ V_20 ] = { } ;
T_1 * V_21 = ( T_1 * ) & V_19 ;
F_14 ( & V_22 ) ;
memset ( V_19 , 0 , sizeof( V_19 ) ) ;
if ( V_2 . V_9 == NULL ) {
F_15 ( & V_22 ) ;
return - V_23 ;
}
for ( V_17 = 0 ; V_17 < V_14 ; V_17 ++ , V_5 += 2 ) {
V_19 [ V_5 ] = V_13 [ V_17 ] ;
V_19 [ V_5 + 1 ] = V_13 [ V_17 ] >> 8 ;
}
if ( V_16 == V_24 ) {
for ( V_17 = 0 , V_5 = 0 ; V_17 < V_14 ; V_17 ++ , V_5 += 4 )
F_3 ( V_21 [ V_17 ] , V_5 ) ;
F_1 ( ( V_14 * 2 ) << 16 | V_16 << 12 | 0 << 8 | V_15 ) ;
} else if ( V_16 == V_25 ) {
for ( V_17 = 0 ; V_17 < V_14 ; V_17 ++ , V_5 += 1 )
V_19 [ V_5 ] = V_4 [ V_17 ] ;
for ( V_17 = 0 , V_5 = 0 ; V_17 < V_14 ; V_17 ++ , V_5 += 4 )
F_3 ( V_21 [ V_17 ] , V_5 ) ;
F_1 ( ( V_14 * 3 ) << 16 | V_16 << 12 | 0 << 8 | V_15 ) ;
} else if ( V_16 == V_26 ) {
V_19 [ V_5 ] = V_4 [ 0 ] ;
V_19 [ V_5 + 1 ] = V_4 [ 1 ] ;
F_3 ( V_21 [ 0 ] , 0 ) ;
F_1 ( 4 << 16 | V_16 << 12 | 0 << 8 | V_15 ) ;
}
V_18 = F_10 () ;
if ( V_16 == V_24 ) {
F_16 ( V_19 , V_2 . V_3 + 0x90 , 16 ) ;
for ( V_17 = 0 ; V_17 < V_14 ; V_17 ++ )
V_4 [ V_17 ] = F_6 ( V_17 ) ;
}
F_15 ( & V_22 ) ;
return V_18 ;
}
int F_17 ( T_3 V_13 , T_2 * V_4 )
{
return F_13 ( & V_13 , V_4 , 1 , V_27 , V_24 ) ;
}
int F_18 ( T_3 V_13 , T_3 * V_4 )
{
T_3 V_28 [ 2 ] = { V_13 , V_13 + 1 } ;
return F_13 ( V_28 , ( T_2 * ) V_4 , 2 , V_27 , V_24 ) ;
}
int F_19 ( T_3 V_13 , T_1 * V_4 )
{
T_3 V_28 [ 4 ] = { V_13 , V_13 + 1 , V_13 + 2 , V_13 + 3 } ;
return F_13 ( V_28 , ( T_2 * ) V_4 , 4 , V_27 , V_24 ) ;
}
int F_20 ( T_3 V_13 , T_2 V_4 )
{
return F_13 ( & V_13 , & V_4 , 1 , V_27 , V_25 ) ;
}
int F_21 ( T_3 V_13 , T_3 V_4 )
{
T_3 V_28 [ 2 ] = { V_13 , V_13 + 1 } ;
return F_13 ( V_28 , ( T_2 * ) & V_4 , 2 , V_27 , V_25 ) ;
}
int F_22 ( T_3 V_13 , T_1 V_4 )
{
T_3 V_28 [ 4 ] = { V_13 , V_13 + 1 , V_13 + 2 , V_13 + 3 } ;
return F_13 ( V_28 , ( T_2 * ) & V_4 , 4 , V_27 , V_25 ) ;
}
int F_23 ( T_3 * V_13 , T_2 * V_4 , int V_29 )
{
return F_13 ( V_13 , V_4 , V_29 , V_27 , V_24 ) ;
}
int F_24 ( T_3 * V_13 , T_2 * V_4 , int V_29 )
{
return F_13 ( V_13 , V_4 , V_29 , V_27 , V_25 ) ;
}
int F_25 ( T_3 V_13 , T_2 V_30 , T_2 V_31 )
{
T_2 V_4 [ 2 ] = { V_30 , V_31 } ;
return F_13 ( & V_13 , V_4 , 1 , V_27 , V_26 ) ;
}
int F_26 ( int V_1 , int V_32 )
{
int V_18 ;
F_14 ( & V_22 ) ;
if ( V_2 . V_9 == NULL ) {
F_15 ( & V_22 ) ;
return - V_23 ;
}
F_1 ( V_32 << 12 | V_1 ) ;
V_18 = F_10 () ;
F_15 ( & V_22 ) ;
return V_18 ;
}
int F_27 ( int V_1 , int V_32 , T_1 * V_33 , int V_34 ,
T_1 * V_35 , int V_36 )
{
int V_37 , V_18 ;
F_14 ( & V_22 ) ;
if ( V_2 . V_9 == NULL ) {
F_15 ( & V_22 ) ;
return - V_23 ;
}
for ( V_37 = 0 ; V_37 < V_34 ; V_37 ++ )
F_3 ( * V_33 ++ , 4 * V_37 ) ;
F_1 ( ( V_34 << 16 ) | ( V_32 << 12 ) | V_1 ) ;
V_18 = F_10 () ;
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ )
* V_35 ++ = F_8 ( 4 * V_37 ) ;
F_15 ( & V_22 ) ;
return V_18 ;
}
int F_28 ( T_1 V_13 , T_1 * V_4 )
{
T_1 V_1 = 0 ;
F_14 ( & V_22 ) ;
if ( V_2 . V_9 == NULL ) {
F_15 ( & V_22 ) ;
return - V_23 ;
}
V_1 = ( V_13 >> 24 ) & 0xFF ;
if ( V_1 == V_38 ) {
F_2 ( V_13 , V_2 . V_39 + V_40 ) ;
F_29 ( 1 ) ;
* V_4 = F_9 ( V_2 . V_39 + V_41 ) ;
} else if ( V_1 == V_42 ) {
F_2 ( * V_4 , V_2 . V_39 + V_41 ) ;
F_29 ( 1 ) ;
F_2 ( V_13 , V_2 . V_39 + V_40 ) ;
} else {
F_12 ( & V_2 . V_9 -> V_10 ,
L_2 , V_1 ) ;
F_15 ( & V_22 ) ;
return - V_12 ;
}
F_15 ( & V_22 ) ;
return 0 ;
}
static T_4 F_30 ( int V_43 , void * V_44 )
{
return V_45 ;
}
static int F_31 ( struct V_46 * V_10 , const struct V_47 * V_16 )
{
int V_18 ;
T_5 V_48 ;
if ( V_2 . V_9 )
return - V_49 ;
V_2 . V_9 = F_32 ( V_10 ) ;
V_18 = F_33 ( V_10 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_34 ( V_10 , L_3 ) ;
if ( V_18 )
return V_18 ;
V_48 = F_35 ( V_10 , 0 ) ;
if ( ! V_48 )
return - V_50 ;
if ( F_36 ( V_10 -> V_43 , F_30 , 0 , L_3 , & V_2 ) )
return - V_49 ;
V_2 . V_3 = F_37 ( V_51 , V_52 ) ;
if ( ! V_2 . V_3 )
return - V_50 ;
V_2 . V_39 = F_37 ( V_53 , V_54 ) ;
if ( ! V_2 . V_39 ) {
F_38 ( V_2 . V_3 ) ;
return - V_50 ;
}
F_39 () ;
return 0 ;
}
static void F_40 ( struct V_46 * V_9 )
{
F_41 ( V_9 -> V_43 , & V_2 ) ;
F_42 ( V_9 ) ;
F_43 ( V_2 . V_9 ) ;
F_38 ( V_2 . V_3 ) ;
F_38 ( V_2 . V_39 ) ;
V_2 . V_9 = NULL ;
F_44 () ;
}
static int T_6 F_45 ( void )
{
V_55 = F_46 () ;
if ( V_55 == 0 )
return - V_23 ;
return F_47 ( & V_56 ) ;
}
static void T_7 F_48 ( void )
{
F_49 ( & V_56 ) ;
}
