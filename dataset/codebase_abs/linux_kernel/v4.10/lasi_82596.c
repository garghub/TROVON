static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_3 + V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_4 ( V_2 ) ;
T_2 V_9 = ( T_2 ) ( V_5 ) | ( T_2 ) ( V_6 ) ;
T_3 V_10 , V_11 ;
if ( V_8 -> V_12 & V_13 ) {
V_10 = V_9 >> 16 ;
V_11 = V_9 & 0xffff ;
} else {
V_10 = V_9 & 0xffff ;
V_11 = V_9 >> 16 ;
}
F_2 ( V_10 , V_2 -> V_3 + V_14 ) ;
F_5 ( 1 ) ;
F_2 ( V_11 , V_2 -> V_3 + V_14 ) ;
}
static int
F_6 ( struct V_15 * V_2 )
{
struct V_1 * V_16 ;
struct V_7 * V_8 ;
int V_17 ;
int V_18 ;
if ( ! V_2 -> V_19 ) {
F_7 ( V_20 L_1 ,
__FILE__ , ( unsigned long ) V_2 -> V_21 . V_22 ) ;
return - V_23 ;
}
F_7 ( V_24 L_2 ,
( unsigned long ) V_2 -> V_21 . V_22 , V_2 -> V_19 ) ;
V_16 = F_8 ( sizeof( struct V_7 ) ) ;
if ( ! V_16 )
return - V_25 ;
F_9 ( V_16 , & V_2 -> V_2 ) ;
F_10 ( V_2 , V_16 ) ;
V_16 -> V_3 = V_2 -> V_21 . V_22 ;
V_16 -> V_19 = V_2 -> V_19 ;
if ( F_11 ( V_16 -> V_26 , V_16 -> V_3 ) ) {
for ( V_18 = 0 ; V_18 < 6 ; V_18 ++ ) {
V_16 -> V_26 [ V_18 ] = F_12 ( V_27 + V_18 ) ;
}
F_7 ( V_24
L_3 , __FILE__ ) ;
}
V_8 = F_4 ( V_16 ) ;
V_8 -> V_12 = V_2 -> V_28 . V_29 == 0x72 ? V_13 : 0 ;
V_17 = F_13 ( V_16 ) ;
if ( V_17 ) {
F_14 ( V_16 ) ;
return - V_23 ;
}
return V_17 ;
}
static int F_15 ( struct V_15 * V_30 )
{
struct V_1 * V_2 = F_16 ( V_30 ) ;
struct V_7 * V_8 = F_4 ( V_2 ) ;
F_17 ( V_2 ) ;
F_18 ( & V_30 -> V_2 , sizeof( struct V_7 ) ,
( void * ) V_8 -> V_31 , V_8 -> V_32 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_19 ( void )
{
F_7 (KERN_INFO LASI_82596_DRIVER_VERSION L_4 ) ;
return F_20 ( & V_33 ) ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_33 ) ;
}
