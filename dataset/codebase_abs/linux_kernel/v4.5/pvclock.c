void F_1 ( T_1 V_1 )
{
V_2 = V_1 ;
}
unsigned long F_2 ( struct V_3 * V_4 )
{
T_2 V_5 = 1000000ULL << 32 ;
F_3 ( V_5 , V_4 -> V_6 ) ;
if ( V_4 -> V_7 < 0 )
V_5 <<= - V_4 -> V_7 ;
else
V_5 >>= V_4 -> V_7 ;
return V_5 ;
}
void F_4 ( void )
{
F_5 () ;
F_6 () ;
F_7 () ;
F_8 () ;
}
void F_9 ( void )
{
F_10 ( & V_8 , 0 ) ;
}
T_1 F_11 ( struct V_3 * V_4 )
{
unsigned V_9 ;
T_3 V_10 ;
T_1 V_1 ;
do {
V_9 = F_12 ( V_4 , & V_10 , & V_1 ) ;
} while ( ( V_4 -> V_9 & 1 ) || V_9 != V_4 -> V_9 );
return V_1 & V_2 ;
}
T_3 F_13 ( struct V_3 * V_4 )
{
unsigned V_9 ;
T_3 V_10 ;
T_2 V_11 ;
T_1 V_1 ;
do {
V_9 = F_12 ( V_4 , & V_10 , & V_1 ) ;
} while ( ( V_4 -> V_9 & 1 ) || V_9 != V_4 -> V_9 );
if ( F_14 ( ( V_1 & V_12 ) != 0 ) ) {
V_4 -> V_1 &= ~ V_12 ;
F_4 () ;
}
if ( ( V_2 & V_13 ) &&
( V_1 & V_13 ) )
return V_10 ;
V_11 = F_15 ( & V_8 ) ;
do {
if ( V_10 < V_11 )
return V_11 ;
V_11 = F_16 ( & V_8 , V_11 , V_10 ) ;
} while ( F_14 ( V_11 != V_10 ) );
return V_10 ;
}
void F_17 ( struct V_14 * V_15 ,
struct V_3 * V_16 ,
struct V_17 * V_18 )
{
T_4 V_9 ;
T_2 V_19 ;
struct V_17 V_20 ;
do {
V_9 = V_15 -> V_9 ;
F_18 () ;
V_20 . V_21 = V_15 -> V_22 ;
V_20 . V_23 = V_15 -> V_24 ;
F_18 () ;
} while ( ( V_15 -> V_9 & 1 ) || ( V_9 != V_15 -> V_9 ) );
V_19 = F_13 ( V_16 ) ;
V_19 += V_20 . V_21 * ( T_2 ) V_25 + V_20 . V_23 ;
V_20 . V_23 = F_3 ( V_19 , V_25 ) ;
V_20 . V_21 = V_19 ;
F_19 ( V_18 , V_20 . V_21 , V_20 . V_23 ) ;
}
