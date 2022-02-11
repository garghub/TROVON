static struct V_1 F_1 ( void T_1 * V_2 )
{
T_2 V_3 ;
struct V_1 V_4 ;
V_3 = F_2 ( V_2 ) ;
V_4 . V_5 = V_3 & 0x1ff ;
V_4 . V_6 = ( V_3 >> 9 ) & 0x7f ;
V_4 . V_7 = ( V_3 >> 16 ) & 03 ;
return V_4 ;
}
static void F_3 ( void T_1 * V_8 ,
void T_1 * V_2 ,
struct V_1 V_4 )
{
T_2 V_3 ;
V_3 = F_2 ( V_2 ) & ~ 0x7ffff ;
V_3 |= V_4 . V_5 | ( V_4 . V_6 << 9 ) | ( V_4 . V_7 << 16 ) ;
F_4 ( 0xa05f , V_8 ) ;
F_4 ( V_3 , V_2 ) ;
F_4 ( 0 , V_8 ) ;
}
static unsigned long F_5 ( struct V_9 * V_10 ,
unsigned long V_11 )
{
struct V_12 * V_13 = F_6 ( V_10 ) ;
struct V_1 V_4 ;
V_4 = F_1 ( V_13 -> V_2 ) ;
V_13 -> V_14 = F_7 ( V_13 -> V_15 , V_4 ) ;
return V_13 -> V_14 ;
}
static long F_8 ( struct V_9 * V_10 , unsigned long V_14 ,
unsigned long * V_16 )
{
struct V_12 * V_13 = F_6 ( V_10 ) ;
struct V_1 V_4 ;
V_4 = F_9 ( V_13 -> V_15 , V_14 ) ;
return F_7 ( V_13 -> V_15 , V_4 ) ;
}
static int F_10 ( struct V_9 * V_10 , unsigned long V_14 ,
unsigned long V_11 )
{
struct V_12 * V_13 = F_6 ( V_10 ) ;
struct V_1 V_4 ;
V_4 = F_9 ( V_13 -> V_15 , V_14 ) ;
V_13 -> V_14 = F_7 ( V_13 -> V_15 , V_4 ) ;
F_3 ( V_13 -> V_8 , V_13 -> V_2 , V_4 ) ;
return 0 ;
}
struct V_17 * F_11 ( struct V_18 * V_19 ,
const struct V_20 * V_21 ,
const char * V_22 ,
void T_1 * V_23 )
{
struct V_17 * V_17 ;
struct V_12 * V_13 ;
struct V_24 V_25 ;
V_13 = F_12 ( sizeof( struct V_12 ) , V_26 ) ;
if ( ! V_13 ) {
F_13 ( L_1 ) ;
return F_14 ( - V_27 ) ;
}
V_25 . V_22 = V_22 ;
V_25 . V_28 = & V_29 ;
V_25 . V_30 = V_31 ;
V_25 . V_32 = NULL ;
V_25 . V_33 = 0 ;
V_13 -> V_10 . V_25 = & V_25 ;
V_13 -> V_15 = V_21 -> V_15 ;
V_13 -> V_2 = V_23 + V_21 -> V_34 ;
V_13 -> V_8 = V_23 + V_21 -> V_35 ;
V_17 = F_15 ( V_19 , & V_13 -> V_10 ) ;
if ( F_16 ( V_17 ) )
F_17 ( V_13 ) ;
return V_17 ;
}
