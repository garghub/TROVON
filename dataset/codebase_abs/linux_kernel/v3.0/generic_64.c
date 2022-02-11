static inline void F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned long V_4 ,
unsigned long V_5 ,
unsigned long V_6 , T_2 V_7 ,
int V_8 )
{
unsigned long V_9 ;
V_6 &= ~ 0x1UL ;
V_4 &= ~ V_10 ;
V_9 = V_4 + V_5 ;
if ( V_9 > V_11 )
V_9 = V_11 ;
do {
T_1 V_12 ;
unsigned long V_13 = V_4 + V_14 ;
V_12 = F_2 ( V_6 , V_7 , V_8 , V_14 ) ;
if ( ! ( V_4 & 0xffff ) ) {
if ( V_14 < ( 4 * 1024 * 1024 ) &&
! ( V_4 & 0x3fffff ) &&
! ( V_6 & 0x3ffffe ) &&
V_9 >= V_4 + 0x400000 ) {
V_12 = F_2 ( V_6 , V_7 , V_8 ,
4 * 1024 * 1024 ) ;
V_13 = V_4 + 0x400000 ;
V_6 += 0x400000 ;
} else if ( V_14 < ( 512 * 1024 ) &&
! ( V_4 & 0x7ffff ) &&
! ( V_6 & 0x7fffe ) &&
V_9 >= V_4 + 0x80000 ) {
V_12 = F_2 ( V_6 , V_7 , V_8 ,
512 * 1024 * 1024 ) ;
V_13 = V_4 + 0x80000 ;
V_6 += 0x80000 ;
} else if ( V_14 < ( 64 * 1024 ) &&
! ( V_6 & 0xfffe ) &&
V_9 >= V_4 + 0x10000 ) {
V_12 = F_2 ( V_6 , V_7 , V_8 ,
64 * 1024 ) ;
V_13 = V_4 + 0x10000 ;
V_6 += 0x10000 ;
} else
V_6 += V_14 ;
} else
V_6 += V_14 ;
if ( F_3 ( V_12 ) )
V_12 = F_4 ( V_12 ) ;
do {
F_5 ( ! F_6 ( * V_3 ) ) ;
F_7 ( V_2 , V_4 , V_3 , V_12 ) ;
V_4 += V_14 ;
F_8 ( V_12 ) += V_14 ;
V_3 ++ ;
} while ( V_4 < V_13 );
} while ( V_4 < V_9 );
}
static inline int F_9 ( struct V_1 * V_2 , T_3 * V_15 , unsigned long V_4 , unsigned long V_5 ,
unsigned long V_6 , T_2 V_7 , int V_8 )
{
unsigned long V_9 ;
V_4 &= ~ V_16 ;
V_9 = V_4 + V_5 ;
if ( V_9 > V_17 )
V_9 = V_17 ;
V_6 -= V_4 ;
do {
T_1 * V_3 = F_10 ( V_2 , NULL , V_15 , V_4 ) ;
if ( ! V_3 )
return - V_18 ;
F_1 ( V_2 , V_3 , V_4 , V_9 - V_4 , V_4 + V_6 , V_7 , V_8 ) ;
F_11 ( V_3 ) ;
V_4 = ( V_4 + V_11 ) & V_10 ;
V_15 ++ ;
} while ( V_4 < V_9 );
return 0 ;
}
static inline int F_12 ( struct V_1 * V_2 , T_4 * V_19 , unsigned long V_4 , unsigned long V_5 ,
unsigned long V_6 , T_2 V_7 , int V_8 )
{
unsigned long V_9 ;
V_4 &= ~ V_20 ;
V_9 = V_4 + V_5 ;
if ( V_9 > V_21 )
V_9 = V_21 ;
V_6 -= V_4 ;
do {
T_3 * V_15 = F_13 ( V_2 , V_19 , V_4 ) ;
if ( ! V_19 )
return - V_18 ;
F_9 ( V_2 , V_15 , V_4 , V_9 - V_4 , V_4 + V_6 , V_7 , V_8 ) ;
V_4 = ( V_4 + V_21 ) & V_20 ;
V_19 ++ ;
} while ( V_4 < V_9 );
return 0 ;
}
int F_14 ( struct V_22 * V_23 , unsigned long V_24 ,
unsigned long V_25 , unsigned long V_5 , T_2 V_7 )
{
int error = 0 ;
T_5 * V_26 ;
unsigned long V_27 = V_24 ;
unsigned long V_9 = V_24 + V_5 ;
struct V_1 * V_2 = V_23 -> V_28 ;
int V_8 = F_15 ( V_25 ) ;
unsigned long V_6 = F_16 ( V_25 ) << V_29 ;
unsigned long V_30 ;
V_30 = V_6 | ( ( ( unsigned long ) V_8 ) << 32UL ) ;
V_23 -> V_31 |= V_32 | V_33 | V_34 ;
V_23 -> V_35 = V_30 >> V_29 ;
V_6 -= V_24 ;
V_26 = F_17 ( V_2 , V_24 ) ;
F_18 ( V_23 , V_27 , V_9 ) ;
while ( V_24 < V_9 ) {
T_4 * V_19 = F_19 ( V_2 , V_26 , V_24 ) ;
error = - V_18 ;
if ( ! V_19 )
break;
error = F_12 ( V_2 , V_19 , V_24 , V_9 - V_24 , V_6 + V_24 , V_7 , V_8 ) ;
if ( error )
break;
V_24 = ( V_24 + V_17 ) & V_16 ;
V_26 ++ ;
}
F_20 ( V_23 , V_27 , V_9 ) ;
return error ;
}
