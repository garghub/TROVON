static void
F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
T_1 V_5 = 0x141000 + ( V_3 * 0x2000 ) + ( V_4 * 0x400 ) ;
T_1 V_6 = F_2 ( V_2 , V_5 + 0x020 ) ;
if ( V_6 ) {
F_3 ( V_2 , L_1 , V_3 , V_4 , V_6 ) ;
F_4 ( V_2 , V_5 + 0x020 , V_6 ) ;
}
}
static void
F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = ( void * ) V_8 ;
T_1 V_9 ;
V_9 = F_2 ( V_2 , 0x00017c ) ;
while ( V_9 ) {
T_1 V_4 , V_3 = F_6 ( V_9 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_10 ; V_4 ++ )
F_1 ( V_2 , V_3 , V_4 ) ;
V_9 &= ~ ( 1 << V_3 ) ;
}
F_7 ( V_2 , 0x000640 , 0x02000000 , 0x00000000 ) ;
}
int
F_8 ( struct V_11 * V_12 , T_1 V_13 ,
struct V_14 * * V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
int V_16 ;
V_16 = F_9 ( & V_2 -> V_17 , 1 , V_13 , V_13 , 1 , V_15 ) ;
if ( V_16 )
* V_15 = NULL ;
return V_16 ;
}
void
F_10 ( struct V_11 * V_12 , struct V_14 * * V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
F_11 ( & V_2 -> V_17 , V_15 ) ;
}
static void
F_12 ( struct V_11 * V_12 , T_1 V_18 , T_1 V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
T_1 V_20 = V_18 + V_19 - 1 ;
int V_21 , V_22 ;
F_13 ( ( V_18 > V_20 ) || ( V_20 >= V_2 -> V_23 ) ) ;
F_4 ( V_2 , 0x17e8cc , V_18 ) ;
F_4 ( V_2 , 0x17e8d0 , V_20 ) ;
F_4 ( V_2 , 0x17e8c8 , 0x4 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_24 ; ++ V_21 ) {
for ( V_22 = 0 ; V_22 < V_2 -> V_10 ; ++ V_22 )
F_14 ( V_2 , 0x1410c8 + V_21 * 0x2000 + V_22 * 0x400 , ~ 0 , 0 ) ;
}
}
int
F_15 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
T_1 V_27 , V_28 , V_29 ;
int V_16 ;
V_2 -> V_23 = ( V_26 -> V_30 -> V_31 >> 17 ) / 4 ;
if ( V_2 -> V_23 > ( 1 << 17 ) )
V_2 -> V_23 = 1 << 17 ;
V_2 -> V_23 = ( V_2 -> V_23 + 63 ) & ~ 63 ;
V_29 = V_2 -> V_24 * 0x800 ;
V_28 = ( V_29 < 0x6000 ) ? 0x6000 : V_29 ;
V_27 = ( V_2 -> V_23 / 64 ) * 0x6000 + V_28 ;
V_27 += V_29 ;
V_27 = ( V_27 + 0xfff ) >> 12 ;
V_16 = F_16 ( & V_26 -> V_32 , 1 , V_27 , V_27 , 1 ,
& V_2 -> V_33 ) ;
if ( V_16 ) {
V_2 -> V_23 = 0 ;
} else {
T_2 V_34 = ( V_2 -> V_33 -> V_35 << 12 ) + V_28 ;
V_34 += V_29 - 1 ;
V_16 = F_17 ( V_34 , V_29 ) ;
V_2 -> V_34 = V_34 ;
}
V_16 = F_18 ( & V_2 -> V_17 , 0 , V_2 -> V_23 , 1 ) ;
return V_16 ;
}
static int
F_19 ( struct V_36 * V_37 , struct V_36 * V_38 ,
struct V_39 * V_40 , void * V_41 , T_1 V_31 ,
struct V_36 * * V_42 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 = V_25 ( V_37 ) ;
T_1 V_43 , V_9 ;
int V_16 , V_22 ;
V_16 = F_20 ( V_37 , V_38 , V_40 , & V_2 ) ;
* V_42 = F_21 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_43 = F_2 ( V_2 , 0x022438 ) ;
V_9 = F_2 ( V_2 , 0x022554 ) ;
for ( V_22 = 0 ; V_22 < V_43 ; V_22 ++ ) {
if ( ! ( V_9 & ( 1 << V_22 ) ) )
V_2 -> V_24 ++ ;
}
V_2 -> V_10 = F_2 ( V_2 , 0x17e8dc ) >> 28 ;
V_16 = F_15 ( V_26 , V_2 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_5 . V_44 = F_8 ;
V_2 -> V_5 . V_45 = F_10 ;
V_2 -> V_5 . V_46 = F_12 ;
F_22 ( V_2 ) -> V_47 = F_5 ;
return 0 ;
}
void
F_23 ( struct V_36 * V_48 )
{
struct V_11 * V_12 = (struct V_11 * ) V_48 ;
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
struct V_25 * V_26 = V_25 ( V_12 -> V_5 . V_5 . V_37 ) ;
F_24 ( & V_2 -> V_17 ) ;
F_11 ( & V_26 -> V_32 , & V_2 -> V_33 ) ;
F_25 ( V_12 ) ;
}
static int
F_26 ( struct V_36 * V_48 )
{
struct V_11 * V_12 = (struct V_11 * ) V_48 ;
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
int V_16 ;
V_16 = F_27 ( V_12 ) ;
if ( V_16 )
return V_16 ;
F_7 ( V_2 , 0x17e820 , 0x00100000 , 0x00000000 ) ;
F_4 ( V_2 , 0x17e8d8 , V_2 -> V_24 ) ;
if ( F_28 ( V_12 ) -> V_49 >= V_50 )
F_4 ( V_2 , 0x17e000 , V_2 -> V_24 ) ;
F_4 ( V_2 , 0x17e8d4 , V_2 -> V_34 ) ;
return 0 ;
}
