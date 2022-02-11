static int F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
while ( ! ( F_2 ( V_4 ) & ( 1 << 7 ) ) )
F_3 () ;
F_4 ( V_3 , V_5 ) ;
return 0 ;
}
static T_1 F_5 ( int V_6 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
unsigned int V_8 ;
int V_9 = V_10 ;
while ( F_2 ( V_4 ) & ( 1 << 5 ) ) {
V_8 = F_2 ( V_11 ) ;
F_6 ( V_2 , V_8 , 0 ) ;
V_9 = V_12 ;
}
return V_9 ;
}
static T_1 F_7 ( int V_6 , void * V_7 )
{
return V_12 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
F_4 ( 0 , V_4 ) ;
F_4 ( 8 , V_4 ) ;
F_2 ( V_11 ) ;
if ( F_9 ( V_14 -> V_16 , F_5 , 0 , L_1 , V_2 ) != 0 ) {
F_10 ( V_17 L_2 ) ;
return - V_18 ;
}
if ( F_9 ( V_14 -> V_19 , F_7 , 0 , L_1 , V_2 ) != 0 ) {
F_10 ( V_17 L_3 ) ;
F_11 ( V_14 -> V_16 , V_2 ) ;
return - V_18 ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
F_11 ( V_14 -> V_16 , V_2 ) ;
F_11 ( V_14 -> V_19 , V_2 ) ;
}
static int T_2 F_13 ( struct V_20 * V_21 )
{
struct V_13 * V_14 ;
struct V_1 * V_1 ;
int V_19 , V_16 ;
V_16 = F_14 ( V_21 , 0 ) ;
if ( V_16 <= 0 )
return V_16 < 0 ? V_16 : - V_22 ;
V_19 = F_14 ( V_21 , 1 ) ;
if ( V_19 <= 0 )
return V_19 < 0 ? V_19 : - V_22 ;
V_1 = F_15 ( sizeof( struct V_1 ) , V_23 ) ;
V_14 = F_15 ( sizeof( * V_14 ) , V_23 ) ;
if ( ! V_1 || ! V_14 ) {
F_16 ( V_14 ) ;
F_16 ( V_1 ) ;
return - V_24 ;
}
V_14 -> V_16 = V_16 ;
V_14 -> V_19 = V_19 ;
V_1 -> V_25 . type = V_26 ;
V_1 -> V_27 = F_1 ;
V_1 -> V_28 = F_8 ;
V_1 -> V_29 = F_12 ;
V_1 -> V_21 . V_30 = & V_21 -> V_21 ;
V_1 -> V_15 = V_14 ;
F_17 ( V_1 -> V_31 , L_4 , sizeof( V_1 -> V_31 ) ) ;
F_17 ( V_1 -> V_32 , L_5 , sizeof( V_1 -> V_32 ) ) ;
F_18 ( V_21 , V_1 ) ;
F_19 ( V_1 ) ;
return 0 ;
}
static int T_3 F_20 ( struct V_20 * V_21 )
{
struct V_1 * V_1 = F_21 ( V_21 ) ;
struct V_13 * V_14 = V_1 -> V_15 ;
F_22 ( V_1 ) ;
F_16 ( V_14 ) ;
return 0 ;
}
