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
struct V_19 * V_20 ;
int V_21 = 0 ;
V_20 = F_3 ( V_10 , V_22 , 0 ) ;
if ( ! V_20 )
return - V_23 ;
V_16 = F_4 ( sizeof( struct V_15 ) , V_24 ) ;
if ( ! V_16 )
return - V_25 ;
V_16 -> V_2 . V_26 = ( char * ) V_12 -> V_26 ;
V_16 -> V_2 . V_27 = V_12 -> V_28 ;
V_16 -> V_2 . V_29 = V_20 -> V_5 ;
V_16 -> V_2 . V_30 = F_5 ( V_20 ) ;
V_16 -> V_18 = V_12 -> V_18 ;
V_16 -> V_31 = V_12 -> V_31 ;
V_16 -> V_2 . V_32 = F_6 ( V_16 -> V_2 . V_29 , V_16 -> V_2 . V_30 ) ;
if ( ! V_16 -> V_2 . V_32 ) {
F_7 ( V_33 L_1 ,
V_16 -> V_2 . V_26 ) ;
return - V_25 ;
}
V_16 -> V_2 . V_6 =
F_8 ( V_16 -> V_2 . V_29 , V_16 -> V_2 . V_30 ) ;
if ( ! V_16 -> V_2 . V_6 )
F_7 ( V_33 L_2 ,
V_16 -> V_2 . V_26 ) ;
V_16 -> V_2 . V_34 = F_1 ;
F_9 ( & V_16 -> V_2 ) ;
F_7 ( V_35
L_3
L_4 ,
V_16 -> V_2 . V_26 , ( unsigned long ) V_16 -> V_2 . V_29 ,
V_16 -> V_2 . V_27 * 8 ) ;
V_16 -> V_36 = F_10 ( V_12 -> V_37 , & V_16 -> V_2 ) ;
if ( ! V_16 -> V_36 ) {
F_11 ( ( void * ) V_16 -> V_2 . V_32 ) ;
if ( V_16 -> V_2 . V_6 )
F_11 ( V_16 -> V_2 . V_6 ) ;
return - V_38 ;
}
V_16 -> V_36 -> V_39 = V_40 ;
V_21 = F_12 ( V_16 -> V_36 , V_41 , & V_18 , 0 ) ;
if ( V_21 > 0 ) {
V_16 -> V_31 = V_21 ;
V_16 -> V_18 = V_18 ;
}
if ( ! V_16 -> V_31 )
F_7 ( L_5 ,
V_16 -> V_2 . V_26 ) ;
F_13 ( V_16 -> V_36 , V_16 -> V_18 , V_16 -> V_31 ) ;
F_14 ( V_10 , V_16 ) ;
return 0 ;
}
static int T_3 F_15 ( struct V_9 * V_13 )
{
struct V_15 * V_16 = F_16 ( V_13 ) ;
F_14 ( V_13 , NULL ) ;
F_17 ( V_16 -> V_36 ) ;
F_18 ( V_16 -> V_36 ) ;
F_11 ( V_16 -> V_2 . V_32 ) ;
if ( V_16 -> V_2 . V_6 )
F_11 ( V_16 -> V_2 . V_6 ) ;
F_19 ( V_16 -> V_18 ) ;
F_19 ( V_16 ) ;
return 0 ;
}
static void F_20 ( struct V_9 * V_13 )
{
struct V_15 * V_16 = F_16 ( V_13 ) ;
if ( V_16 && V_16 -> V_36 -> V_42 ( V_16 -> V_36 ) == 0 )
V_16 -> V_36 -> V_43 ( V_16 -> V_36 ) ;
}
static int T_4 F_21 ( void )
{
return F_22 ( & V_44 ) ;
}
static void T_5 F_23 ( void )
{
F_24 ( & V_44 ) ;
}
