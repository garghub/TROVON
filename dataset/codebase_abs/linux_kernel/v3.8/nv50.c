static int
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_11 * V_12 ;
T_1 V_13 = ( unsigned long ) V_6 ;
int V_14 ;
V_7 = F_2 ( ( V_7 + 4095 ) & ~ 4095 , ( T_1 ) 4096 ) ;
V_13 = F_2 ( ( V_13 + 4095 ) & ~ 4095 , ( T_1 ) 4096 ) ;
V_14 = F_3 ( V_2 , V_3 , V_5 , & V_12 ) ;
* V_8 = F_4 ( V_12 ) ;
if ( V_14 )
return V_14 ;
V_14 = V_10 -> V_15 . V_16 ( V_10 , V_7 , V_13 , 0 , 0x800 , & V_12 -> V_17 ) ;
if ( V_14 )
return V_14 ;
V_12 -> V_18 . V_19 = V_12 -> V_17 -> V_20 ;
V_12 -> V_18 . V_7 = V_12 -> V_17 -> V_7 << 12 ;
V_12 -> V_17 -> V_21 = 12 ;
return 0 ;
}
static void
F_5 ( struct V_1 * V_22 )
{
struct V_11 * V_12 = ( void * ) V_22 ;
struct V_9 * V_10 = V_9 ( V_22 ) ;
V_10 -> V_15 . V_23 ( V_10 , & V_12 -> V_17 ) ;
F_6 ( & V_12 -> V_18 ) ;
}
static T_1
F_7 ( struct V_1 * V_22 , T_2 V_20 )
{
struct V_24 * V_25 = ( void * ) V_22 -> V_3 ;
struct V_11 * V_12 = ( void * ) V_22 ;
unsigned long V_26 ;
T_2 V_18 = ( V_12 -> V_17 -> V_20 + V_20 ) & 0xffffff00000ULL ;
T_2 V_19 = ( V_12 -> V_17 -> V_20 + V_20 ) & 0x000000fffffULL ;
T_1 V_6 ;
F_8 ( & V_25 -> V_27 , V_26 ) ;
if ( F_9 ( V_25 -> V_19 != V_18 ) ) {
F_10 ( V_25 , 0x001700 , V_18 >> 16 ) ;
V_25 -> V_19 = V_18 ;
}
V_6 = F_11 ( V_25 , 0x700000 + V_19 ) ;
F_12 ( & V_25 -> V_27 , V_26 ) ;
return V_6 ;
}
static void
F_13 ( struct V_1 * V_22 , T_2 V_20 , T_1 V_6 )
{
struct V_24 * V_25 = ( void * ) V_22 -> V_3 ;
struct V_11 * V_12 = ( void * ) V_22 ;
unsigned long V_26 ;
T_2 V_18 = ( V_12 -> V_17 -> V_20 + V_20 ) & 0xffffff00000ULL ;
T_2 V_19 = ( V_12 -> V_17 -> V_20 + V_20 ) & 0x000000fffffULL ;
F_8 ( & V_25 -> V_27 , V_26 ) ;
if ( F_9 ( V_25 -> V_19 != V_18 ) ) {
F_10 ( V_25 , 0x001700 , V_18 >> 16 ) ;
V_25 -> V_19 = V_18 ;
}
F_10 ( V_25 , 0x700000 + V_19 , V_6 ) ;
F_12 ( & V_25 -> V_27 , V_26 ) ;
}
static int
F_14 ( struct V_28 * V_29 , struct V_1 * V_2 ,
T_1 V_7 , T_1 V_13 , struct V_1 * * V_8 )
{
struct V_1 * V_3 = F_4 ( V_29 ) ;
return F_15 ( V_2 , V_3 , & V_30 ,
( void * ) ( unsigned long ) V_13 , V_7 , V_8 ) ;
}
static int
F_16 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_24 * V_25 ;
int V_14 ;
V_14 = F_17 ( V_2 , V_3 , V_5 , & V_25 ) ;
* V_8 = F_4 ( V_25 ) ;
if ( V_14 )
return V_14 ;
F_18 ( & V_25 -> V_27 ) ;
V_25 -> V_18 . V_31 = F_14 ;
return 0 ;
}
static int
F_19 ( struct V_1 * V_22 , bool V_32 )
{
struct V_24 * V_25 = ( void * ) V_22 ;
V_25 -> V_19 = ~ 0ULL ;
return F_20 ( & V_25 -> V_18 , V_32 ) ;
}
