static void F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
T_1 V_4 )
{
unsigned long V_5 = ( unsigned long ) V_2 -> V_6 + V_3 ;
unsigned long V_7 = V_5 + V_4 ;
V_5 &= ~ ( V_8 - 1 ) ;
while ( V_5 < V_7 ) {
asm volatile ("mcr p15, 0, %0, c7, c6, 1" : : "r" (start));
V_5 += V_8 ;
}
}
static int F_2 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( & V_10 -> V_13 ) ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
V_17 = F_4 ( V_10 , V_18 , 0 ) ;
if ( ! V_17 )
return - V_19 ;
V_15 = F_5 ( sizeof( struct V_14 ) , V_20 ) ;
if ( ! V_15 )
return - V_21 ;
V_15 -> V_2 . V_22 = V_12 -> V_22 ;
V_15 -> V_2 . V_23 = V_12 -> V_24 ;
V_15 -> V_2 . V_25 = V_17 -> V_5 ;
V_15 -> V_2 . V_26 = F_6 ( V_17 ) ;
V_15 -> V_2 . V_27 = F_7 ( V_15 -> V_2 . V_25 , V_15 -> V_2 . V_26 ) ;
if ( ! V_15 -> V_2 . V_27 ) {
F_8 ( V_28 L_1 ,
V_15 -> V_2 . V_22 ) ;
return - V_21 ;
}
V_15 -> V_2 . V_6 = F_9 ( V_15 -> V_2 . V_25 , V_15 -> V_2 . V_26 ,
V_29 ) ;
if ( ! V_15 -> V_2 . V_6 )
F_8 ( V_28 L_2 ,
V_15 -> V_2 . V_22 ) ;
V_15 -> V_2 . V_30 = F_1 ;
F_10 ( & V_15 -> V_2 ) ;
F_8 ( V_31
L_3
L_4 ,
V_15 -> V_2 . V_22 , ( unsigned long ) V_15 -> V_2 . V_25 ,
V_15 -> V_2 . V_23 * 8 ) ;
V_15 -> V_32 = F_11 ( V_12 -> V_33 , & V_15 -> V_2 ) ;
if ( ! V_15 -> V_32 ) {
F_12 ( ( void * ) V_15 -> V_2 . V_27 ) ;
if ( V_15 -> V_2 . V_6 )
F_12 ( V_15 -> V_2 . V_6 ) ;
return - V_34 ;
}
V_15 -> V_32 -> V_13 . V_35 = & V_10 -> V_13 ;
F_13 ( V_15 -> V_32 , V_36 , NULL , V_12 -> V_37 ,
V_12 -> V_38 ) ;
F_14 ( V_10 , V_15 ) ;
return 0 ;
}
static int F_15 ( struct V_9 * V_13 )
{
struct V_14 * V_15 = F_16 ( V_13 ) ;
F_17 ( V_15 -> V_32 ) ;
F_18 ( V_15 -> V_32 ) ;
F_12 ( V_15 -> V_2 . V_27 ) ;
if ( V_15 -> V_2 . V_6 )
F_19 ( V_15 -> V_2 . V_6 ) ;
F_20 ( V_15 ) ;
return 0 ;
}
static void F_21 ( struct V_9 * V_13 )
{
struct V_14 * V_15 = F_16 ( V_13 ) ;
if ( V_15 && F_22 ( V_15 -> V_32 ) == 0 )
F_23 ( V_15 -> V_32 ) ;
}
