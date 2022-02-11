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
if ( V_11 )
V_13 -> V_14 -> V_15 = V_11 ;
V_4 = F_1 ( V_13 -> V_2 ) ;
V_13 -> V_16 = F_7 ( V_13 -> V_14 , V_4 ) ;
return V_13 -> V_16 ;
}
static long F_8 ( struct V_9 * V_10 , unsigned long V_16 ,
unsigned long * V_17 )
{
struct V_12 * V_13 = F_6 ( V_10 ) ;
struct V_1 V_4 ;
V_4 = F_9 ( V_13 -> V_14 , V_16 ) ;
return F_7 ( V_13 -> V_14 , V_4 ) ;
}
static int F_10 ( struct V_9 * V_10 , unsigned long V_16 ,
unsigned long V_11 )
{
struct V_12 * V_13 = F_6 ( V_10 ) ;
struct V_1 V_4 ;
if ( V_11 )
V_13 -> V_14 -> V_15 = V_11 ;
V_4 = F_9 ( V_13 -> V_14 , V_16 ) ;
V_13 -> V_16 = F_7 ( V_13 -> V_14 , V_4 ) ;
F_3 ( V_13 -> V_8 , V_13 -> V_2 , V_4 ) ;
return 0 ;
}
struct V_18 * F_11 ( struct V_19 * V_20 ,
const struct V_21 * V_22 ,
const char * V_23 ,
const char * V_24 ,
void T_1 * V_25 )
{
struct V_18 * V_18 ;
struct V_12 * V_13 ;
struct V_26 V_27 ;
struct V_28 * V_29 ;
V_13 = F_12 ( sizeof( struct V_12 ) , V_30 ) ;
if ( ! V_13 ) {
F_13 ( L_1 ) ;
return F_14 ( - V_31 ) ;
}
V_29 = F_15 ( V_22 -> V_14 , sizeof( * V_29 ) , V_30 ) ;
if ( ! V_29 ) {
F_13 ( L_2 ) ;
return F_14 ( - V_31 ) ;
}
V_27 . V_23 = V_23 ;
V_27 . V_32 = & V_33 ;
V_27 . V_34 = V_35 ;
V_27 . V_36 = ( V_24 ? & V_24 : NULL ) ;
V_27 . V_37 = ( V_24 ? 1 : 0 ) ;
V_13 -> V_10 . V_27 = & V_27 ;
V_13 -> V_14 = V_29 ;
V_13 -> V_2 = V_25 + V_22 -> V_38 ;
V_13 -> V_8 = V_25 + V_22 -> V_39 ;
V_18 = F_16 ( V_20 , & V_13 -> V_10 ) ;
if ( F_17 ( V_18 ) )
F_18 ( V_13 ) ;
return V_18 ;
}
