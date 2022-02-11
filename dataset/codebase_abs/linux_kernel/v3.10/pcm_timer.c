void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 , V_4 , V_5 , V_6 , V_7 ;
struct V_8 * V_9 = V_2 -> V_9 ;
V_4 = 1000000000 ;
V_3 = V_9 -> V_3 ;
if ( F_2 ( ! V_3 ) )
return;
V_6 = F_3 ( V_4 , V_3 ) ;
V_4 /= V_6 ;
V_3 /= V_6 ;
V_5 = V_9 -> V_10 ;
if ( F_2 ( ! V_5 ) )
return;
V_6 = F_3 ( V_3 , V_5 ) ;
V_3 /= V_6 ;
V_5 /= V_6 ;
V_7 = 1 ;
while ( ( V_4 * V_5 ) / V_5 != V_4 ) {
V_4 /= 2 ;
V_7 *= 2 ;
}
if ( V_3 == 0 ) {
F_4 ( V_11 L_1 , V_9 -> V_3 , V_9 -> V_10 ) ;
V_9 -> V_12 = - 1 ;
return;
}
V_9 -> V_12 = ( V_4 * V_5 / V_3 ) * V_7 ;
}
static unsigned long F_5 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
V_2 = V_14 -> V_15 ;
return V_2 -> V_9 ? V_2 -> V_9 -> V_12 : 0 ;
}
static int F_6 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( V_14 ) ;
V_2 -> V_16 = 1 ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( V_14 ) ;
V_2 -> V_16 = 0 ;
return 0 ;
}
static void F_9 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
V_2 -> V_14 = NULL ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_17 V_18 ;
struct V_13 * V_14 ;
V_18 . V_19 = V_20 ;
V_18 . V_21 = V_22 ;
V_18 . V_23 = V_2 -> V_24 -> V_23 -> V_25 ;
V_18 . V_26 = V_2 -> V_24 -> V_26 ;
V_18 . V_27 = ( V_2 -> V_25 << 1 ) | ( V_2 -> V_28 & 1 ) ;
if ( F_11 ( V_2 -> V_24 -> V_23 , L_2 , & V_18 , & V_14 ) < 0 )
return;
sprintf ( V_14 -> V_29 , L_3 ,
V_2 -> V_28 == V_30 ?
L_4 : L_5 ,
V_18 . V_23 , V_18 . V_26 , V_18 . V_27 ) ;
V_14 -> V_31 = V_32 ;
if ( F_12 ( V_14 -> V_23 , V_14 ) < 0 ) {
F_13 ( V_14 -> V_23 , V_14 ) ;
return;
}
V_14 -> V_15 = V_2 ;
V_14 -> V_33 = F_9 ;
V_2 -> V_14 = V_14 ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 ) {
F_13 ( V_2 -> V_24 -> V_23 , V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
}
