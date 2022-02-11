static T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_4 * V_5 = ( void * ) V_2 -> V_6 ;
struct V_7 * V_8 = ( void * ) V_2 ;
unsigned long V_9 ;
T_2 V_10 = ( V_8 -> V_11 -> V_3 + V_3 ) & 0xffffff00000ULL ;
T_2 V_12 = ( V_8 -> V_11 -> V_3 + V_3 ) & 0x000000fffffULL ;
T_1 V_13 ;
F_2 ( & V_5 -> V_14 , V_9 ) ;
if ( F_3 ( V_5 -> V_12 != V_10 ) ) {
F_4 ( V_5 , 0x001700 , V_10 >> 16 ) ;
V_5 -> V_12 = V_10 ;
}
V_13 = F_5 ( V_5 , 0x700000 + V_12 ) ;
F_6 ( & V_5 -> V_14 , V_9 ) ;
return V_13 ;
}
static void
F_7 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_13 )
{
struct V_4 * V_5 = ( void * ) V_2 -> V_6 ;
struct V_7 * V_8 = ( void * ) V_2 ;
unsigned long V_9 ;
T_2 V_10 = ( V_8 -> V_11 -> V_3 + V_3 ) & 0xffffff00000ULL ;
T_2 V_12 = ( V_8 -> V_11 -> V_3 + V_3 ) & 0x000000fffffULL ;
F_2 ( & V_5 -> V_14 , V_9 ) ;
if ( F_3 ( V_5 -> V_12 != V_10 ) ) {
F_4 ( V_5 , 0x001700 , V_10 >> 16 ) ;
V_5 -> V_12 = V_10 ;
}
F_4 ( V_5 , 0x700000 + V_12 , V_13 ) ;
F_6 ( & V_5 -> V_14 , V_9 ) ;
}
static void
F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = ( void * ) V_2 ;
struct V_15 * V_16 = V_15 ( V_2 ) ;
V_16 -> V_17 -> V_18 ( V_16 , & V_8 -> V_11 ) ;
F_9 ( & V_8 -> V_10 ) ;
}
static int
F_10 ( struct V_1 * V_19 , struct V_1 * V_6 ,
struct V_20 * V_21 , void * V_13 , T_1 V_22 ,
struct V_1 * * V_23 )
{
struct V_15 * V_16 = V_15 ( V_19 ) ;
struct V_24 * args = V_13 ;
struct V_7 * V_8 ;
int V_25 ;
args -> V_22 = F_11 ( ( args -> V_22 + 4095 ) & ~ 4095 , ( T_1 ) 4096 ) ;
args -> V_26 = F_11 ( ( args -> V_26 + 4095 ) & ~ 4095 , ( T_1 ) 4096 ) ;
V_25 = F_12 ( V_19 , V_6 , V_21 , & V_8 ) ;
* V_23 = F_13 ( V_8 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_16 -> V_17 -> V_27 ( V_16 , args -> V_22 , args -> V_26 , 0 , 0x800 , & V_8 -> V_11 ) ;
if ( V_25 )
return V_25 ;
V_8 -> V_10 . V_12 = V_8 -> V_11 -> V_3 ;
V_8 -> V_10 . V_22 = V_8 -> V_11 -> V_22 << 12 ;
V_8 -> V_11 -> V_28 = 12 ;
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 , bool V_29 )
{
struct V_4 * V_5 = ( void * ) V_2 ;
V_5 -> V_12 = ~ 0ULL ;
return F_15 ( & V_5 -> V_10 , V_29 ) ;
}
static int
F_16 ( struct V_1 * V_19 , struct V_1 * V_6 ,
struct V_20 * V_21 , void * V_13 , T_1 V_22 ,
struct V_1 * * V_23 )
{
struct V_4 * V_5 ;
int V_25 ;
V_25 = F_17 ( V_19 , V_6 , V_21 , & V_5 ) ;
* V_23 = F_13 ( V_5 ) ;
if ( V_25 )
return V_25 ;
F_18 ( & V_5 -> V_14 ) ;
return 0 ;
}
