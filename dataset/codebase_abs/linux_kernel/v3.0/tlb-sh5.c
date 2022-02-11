int T_1 F_1 ( void )
{
V_1 -> V_2 . V_3 = 64 ;
V_1 -> V_2 . V_4 = 0x10 ;
V_1 -> V_2 . V_5 = V_6 | V_1 -> V_2 . V_4 ;
V_1 -> V_2 . V_7 = V_1 -> V_2 . V_5 ;
V_1 -> V_2 . V_8 = V_6 |
( ( V_1 -> V_2 . V_3 - 1 ) *
V_1 -> V_2 . V_4 ) ;
V_1 -> V_9 . V_3 = 64 ;
V_1 -> V_9 . V_4 = 0x10 ;
V_1 -> V_9 . V_5 = V_10 | V_1 -> V_9 . V_4 ;
V_1 -> V_9 . V_7 = V_1 -> V_9 . V_5 ;
V_1 -> V_9 . V_8 = V_10 |
( ( V_1 -> V_9 . V_3 - 1 ) *
V_1 -> V_9 . V_4 ) ;
return 0 ;
}
unsigned long long F_2 ( void )
{
return V_1 -> V_2 . V_7 ;
}
unsigned long long F_3 ( void )
{
unsigned long long V_11 = F_2 () ;
V_1 -> V_2 . V_5 += V_1 -> V_2 . V_4 ;
V_1 -> V_2 . V_7 += V_1 -> V_2 . V_4 ;
return V_11 ;
}
int F_4 ( unsigned long long V_11 )
{
F_5 ( V_11 ) ;
if ( V_11 <= V_6 )
return - V_12 ;
if ( V_11 < ( V_1 -> V_2 . V_5 - V_1 -> V_2 . V_4 ) )
return - V_12 ;
V_1 -> V_2 . V_5 -= V_1 -> V_2 . V_4 ;
V_1 -> V_2 . V_7 = V_11 ;
return 0 ;
}
void F_6 ( unsigned long long V_13 , unsigned long V_14 ,
unsigned long V_15 , unsigned long V_16 )
{
unsigned long long V_17 , V_18 ;
V_17 = F_7 ( V_14 ) ;
V_17 &= V_19 ;
V_17 |= ( V_15 << V_20 ) | V_21 ;
V_18 = F_7 ( V_16 ) ;
V_18 &= V_19 ;
V_18 |= ( V_22 | V_23 | V_24 ) ;
asm volatile("putcfg %0, 1, %1\n\t"
"putcfg %0, 0, %2\n"
: : "r" (config_addr), "r" (ptel), "r" (pteh));
}
void F_8 ( struct V_25 * V_26 , unsigned long V_27 , T_2 V_28 )
{
unsigned long long V_11 ;
unsigned long V_16 , V_29 ;
F_9 ( V_30 == F_10 ( V_31 ) ) ;
F_11 ( V_29 ) ;
V_11 = F_3 () ;
V_31 [ V_30 ++ ] = V_11 ;
V_16 = F_12 ( V_28 ) & V_32 ;
V_16 &= ~ V_19 ;
F_6 ( V_11 , V_27 , F_13 () , V_16 ) ;
F_14 ( V_29 ) ;
}
void F_15 ( void )
{
unsigned long long V_11 ;
unsigned long V_29 ;
F_9 ( ! V_30 ) ;
F_11 ( V_29 ) ;
V_11 = V_31 [ V_30 -- ] ;
F_16 ( V_11 ) ;
F_4 ( V_11 ) ;
F_14 ( V_29 ) ;
}
