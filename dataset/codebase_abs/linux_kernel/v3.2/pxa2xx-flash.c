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
static int T_2 F_2 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
V_18 = F_3 ( V_10 , V_19 , 0 ) ;
if ( ! V_18 )
return - V_20 ;
V_16 = F_4 ( sizeof( struct V_15 ) , V_21 ) ;
if ( ! V_16 )
return - V_22 ;
V_16 -> V_2 . V_23 = ( char * ) V_12 -> V_23 ;
V_16 -> V_2 . V_24 = V_12 -> V_25 ;
V_16 -> V_2 . V_26 = V_18 -> V_5 ;
V_16 -> V_2 . V_27 = F_5 ( V_18 ) ;
V_16 -> V_2 . V_28 = F_6 ( V_16 -> V_2 . V_26 , V_16 -> V_2 . V_27 ) ;
if ( ! V_16 -> V_2 . V_28 ) {
F_7 ( V_29 L_1 ,
V_16 -> V_2 . V_23 ) ;
return - V_22 ;
}
V_16 -> V_2 . V_6 =
F_8 ( V_16 -> V_2 . V_26 , V_16 -> V_2 . V_27 ) ;
if ( ! V_16 -> V_2 . V_6 )
F_7 ( V_29 L_2 ,
V_16 -> V_2 . V_23 ) ;
V_16 -> V_2 . V_30 = F_1 ;
F_9 ( & V_16 -> V_2 ) ;
F_7 ( V_31
L_3
L_4 ,
V_16 -> V_2 . V_23 , ( unsigned long ) V_16 -> V_2 . V_26 ,
V_16 -> V_2 . V_24 * 8 ) ;
V_16 -> V_32 = F_10 ( V_12 -> V_33 , & V_16 -> V_2 ) ;
if ( ! V_16 -> V_32 ) {
F_11 ( ( void * ) V_16 -> V_2 . V_28 ) ;
if ( V_16 -> V_2 . V_6 )
F_11 ( V_16 -> V_2 . V_6 ) ;
return - V_34 ;
}
V_16 -> V_32 -> V_35 = V_36 ;
F_12 ( V_16 -> V_32 , V_37 , 0 , V_12 -> V_38 , V_12 -> V_39 ) ;
F_13 ( V_10 , V_16 ) ;
return 0 ;
}
static int T_3 F_14 ( struct V_9 * V_13 )
{
struct V_15 * V_16 = F_15 ( V_13 ) ;
F_13 ( V_13 , NULL ) ;
F_16 ( V_16 -> V_32 ) ;
F_17 ( V_16 -> V_32 ) ;
F_11 ( V_16 -> V_2 . V_28 ) ;
if ( V_16 -> V_2 . V_6 )
F_11 ( V_16 -> V_2 . V_6 ) ;
F_18 ( V_16 ) ;
return 0 ;
}
static void F_19 ( struct V_9 * V_13 )
{
struct V_15 * V_16 = F_15 ( V_13 ) ;
if ( V_16 && V_16 -> V_32 -> V_40 ( V_16 -> V_32 ) == 0 )
V_16 -> V_32 -> V_41 ( V_16 -> V_32 ) ;
}
static int T_4 F_20 ( void )
{
return F_21 ( & V_42 ) ;
}
static void T_5 F_22 ( void )
{
F_23 ( & V_42 ) ;
}
