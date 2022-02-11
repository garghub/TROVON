inline void F_1 ( unsigned long V_1 ,
unsigned long long V_2 , T_1 * V_3 )
{
unsigned long long V_4 ;
unsigned long long V_5 = 0 ;
struct V_6 * V_7 ;
unsigned long long V_8 ;
V_4 = F_2 ( * V_3 ) ;
V_5 = F_3 ( V_1 & V_9 ) ;
V_5 |= F_4 () << V_10 ;
V_5 |= V_11 ;
V_4 &= V_12 ;
V_7 = V_2 ? & ( V_13 -> V_14 ) : & ( V_13 -> V_15 ) ;
V_8 = V_7 -> V_8 ;
F_5 ( V_8 ) ;
asm volatile ("putcfg %0,1,%2\n\n\t"
"putcfg %0,0,%1\n"
: : "r" (next), "r" (pteh), "r" (ptel) );
V_8 += V_16 ;
if ( V_8 > V_7 -> V_17 ) V_8 = V_7 -> V_18 ;
V_7 -> V_8 = V_8 ;
}
static int F_6 ( struct V_19 * V_20 ,
unsigned long V_21 ,
unsigned long long V_22 ,
unsigned long V_1 )
{
T_2 * V_23 ;
T_3 * V_24 ;
T_4 * V_25 ;
static T_1 * V_3 ;
T_1 V_26 ;
V_23 = F_7 ( V_1 ) ;
V_24 = F_8 ( V_23 , V_1 ) ;
if ( F_9 ( V_24 ) )
return 0 ;
V_25 = F_10 ( V_24 , V_1 ) ;
if ( F_11 ( V_25 ) )
return 0 ;
V_3 = F_12 ( V_25 , V_1 ) ;
V_26 = * V_3 ;
if ( F_13 ( V_26 ) || ! F_14 ( V_26 ) )
return 0 ;
if ( ( F_2 ( V_26 ) & V_21 ) != V_21 )
return 0 ;
F_1 ( V_1 , V_22 , V_3 ) ;
return 1 ;
}
static int F_15 ( struct V_19 * V_20 ,
unsigned long long V_21 ,
unsigned long long V_22 ,
unsigned long V_1 )
{
T_2 * V_23 ;
T_3 * V_24 ;
T_4 * V_25 ;
T_1 * V_3 ;
T_1 V_26 ;
if ( V_1 >= ( unsigned long ) V_27 )
return 0 ;
V_23 = F_16 ( V_20 , V_1 ) ;
if ( F_17 ( * V_23 ) || ! F_18 ( * V_23 ) )
return 0 ;
if ( ! F_18 ( * V_23 ) )
return 0 ;
V_24 = F_8 ( V_23 , V_1 ) ;
if ( F_19 ( * V_24 ) || ! F_20 ( * V_24 ) )
return 0 ;
V_25 = F_10 ( V_24 , V_1 ) ;
if ( F_21 ( * V_25 ) || ! F_22 ( * V_25 ) )
return 0 ;
V_3 = F_12 ( V_25 , V_1 ) ;
V_26 = * V_3 ;
if ( F_13 ( V_26 ) || ! F_14 ( V_26 ) )
return 0 ;
if ( ( F_2 ( V_26 ) & V_21 ) != V_21 )
return 0 ;
F_1 ( V_1 , V_22 , V_3 ) ;
return 1 ;
}
T_5 int F_23 ( unsigned long long V_28 ,
unsigned long long V_29 ,
unsigned long V_1 )
{
struct V_30 * V_31 ;
struct V_19 * V_20 ;
unsigned long long V_22 ;
unsigned long long V_21 ;
unsigned long long V_32 ;
unsigned long long V_33 ;
V_33 = ( V_29 >> 4 ) ;
V_32 = V_33 ^ ( V_33 >> 5 ) ;
V_32 &= 7 ;
V_21 = V_34 . V_21 [ V_32 ] ;
V_22 = V_34 . V_35 [ V_32 ] ;
V_31 = V_36 ;
V_20 = V_31 -> V_20 ;
if ( ( V_1 >= V_37 && V_1 < V_38 ) ||
( V_1 >= V_39 && V_1 < V_40 ) ) {
if ( V_28 )
if ( F_6 ( V_20 , V_21 ,
V_22 , V_1 ) )
return 1 ;
} else if ( ! F_24 () && V_20 ) {
if ( F_15 ( V_20 , V_21 , V_22 , V_1 ) )
return 1 ;
}
return 0 ;
}
