void F_1 ( T_1 V_1 )
{
V_2 = V_1 ;
}
static T_2 F_2 ( struct V_3 * V_4 )
{
T_2 V_5 = F_3 () - V_4 -> V_6 ;
return F_4 ( V_5 , V_4 -> V_7 ,
V_4 -> V_8 ) ;
}
static unsigned F_5 ( struct V_3 * V_9 ,
struct V_10 * V_11 )
{
do {
V_9 -> V_12 = V_11 -> V_12 ;
F_6 () ;
V_9 -> V_6 = V_11 -> V_6 ;
V_9 -> V_13 = V_11 -> V_14 ;
V_9 -> V_7 = V_11 -> V_15 ;
V_9 -> V_8 = V_11 -> V_8 ;
V_9 -> V_1 = V_11 -> V_1 ;
F_6 () ;
} while ( ( V_11 -> V_12 & 1 ) || ( V_9 -> V_12 != V_11 -> V_12 ) );
return V_9 -> V_12 ;
}
unsigned long F_7 ( struct V_10 * V_11 )
{
T_2 V_16 = 1000000ULL << 32 ;
F_8 ( V_16 , V_11 -> V_15 ) ;
if ( V_11 -> V_8 < 0 )
V_16 <<= - V_11 -> V_8 ;
else
V_16 >>= V_11 -> V_8 ;
return V_16 ;
}
void F_9 ( void )
{
F_10 ( & V_17 , 0 ) ;
}
T_3 F_11 ( struct V_10 * V_11 )
{
struct V_3 V_4 ;
unsigned V_12 ;
T_3 V_18 , V_19 ;
T_2 V_20 ;
do {
V_12 = F_5 ( & V_4 , V_11 ) ;
F_12 () ;
V_19 = F_2 ( & V_4 ) ;
V_18 = V_4 . V_13 + V_19 ;
F_12 () ;
} while ( V_12 != V_11 -> V_12 );
if ( ( V_2 & V_21 ) &&
( V_4 . V_1 & V_21 ) )
return V_18 ;
V_20 = F_13 ( & V_17 ) ;
do {
if ( V_18 < V_20 )
return V_20 ;
V_20 = F_14 ( & V_17 , V_20 , V_18 ) ;
} while ( F_15 ( V_20 != V_18 ) );
return V_18 ;
}
void F_16 ( struct V_22 * V_23 ,
struct V_10 * V_24 ,
struct V_25 * V_26 )
{
T_4 V_12 ;
T_2 V_5 ;
struct V_25 V_27 ;
do {
V_12 = V_23 -> V_12 ;
F_6 () ;
V_27 . V_28 = V_23 -> V_29 ;
V_27 . V_30 = V_23 -> V_31 ;
F_6 () ;
} while ( ( V_23 -> V_12 & 1 ) || ( V_12 != V_23 -> V_12 ) );
V_5 = F_11 ( V_24 ) ;
V_5 += V_27 . V_28 * ( T_2 ) V_32 + V_27 . V_30 ;
V_27 . V_30 = F_8 ( V_5 , V_32 ) ;
V_27 . V_28 = V_5 ;
F_17 ( V_26 , V_27 . V_28 , V_27 . V_30 ) ;
}
