static void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
if ( ( int ) * V_3 < ( V_4 - 1 ) )
return ( void * ) ( unsigned long ) ( * V_3 + 1 ) ;
return NULL ;
}
static void * F_2 ( struct V_1 * V_2 , void * V_5 , T_1 * V_3 )
{
++ * V_3 ;
return F_1 ( V_2 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , void * V_5 )
{
}
static int F_4 ( struct V_1 * V_2 , void * V_5 )
{
unsigned long V_6 = ( unsigned long ) V_5 ;
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_8 [ V_6 ] . V_10 ) {
if ( F_5 ( V_11 ) )
F_6 ( V_2 , L_1 , V_6 << 2 ,
V_8 [ V_6 ] . V_10 ,
V_8 [ V_6 ] . V_12 ,
V_8 [ V_6 ] . V_13 ) ;
else
F_6 ( V_2 , L_2 , V_6 << 2 ,
V_8 [ V_6 ] . V_10 ,
V_8 [ V_6 ] . V_12 ) ;
}
return 0 ;
}
static int F_7 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
int V_16 ;
struct V_1 * V_17 ;
V_16 = F_8 ( V_15 , & V_18 ) ;
V_17 = V_15 -> V_19 ;
V_17 -> V_9 = F_9 ( V_15 ) -> V_20 ;
return V_16 ;
}
static void F_10 ( void * V_21 , unsigned long V_22 , unsigned long * args )
{
struct V_7 * V_23 ;
if ( V_22 > V_24 )
return;
V_23 = F_11 ( & V_7 [ V_22 / 4 ] ) ;
V_23 -> V_25 = F_12 () ;
V_23 -> V_26 = F_13 ( V_27 ) ;
}
static void F_14 ( void * V_21 , unsigned long V_22 , unsigned long V_28 ,
unsigned long * V_29 )
{
struct V_7 * V_23 ;
if ( V_22 > V_24 )
return;
V_23 = F_11 ( & V_7 [ V_22 / 4 ] ) ;
V_23 -> V_10 ++ ;
V_23 -> V_12 += F_12 () - V_23 -> V_25 ;
V_23 -> V_13 += F_13 ( V_27 ) - V_23 -> V_26 ;
}
static int T_2 F_15 ( void )
{
struct V_30 * V_31 ;
struct V_30 * V_32 ;
char V_33 [ V_34 ] ;
int V_35 ;
if ( ! F_16 ( V_36 ) )
return 0 ;
if ( F_17 ( F_10 , NULL ) )
return - V_37 ;
if ( F_18 ( F_14 , NULL ) ) {
F_19 ( F_10 , NULL ) ;
return - V_37 ;
}
V_31 = F_20 ( V_38 , NULL ) ;
if ( ! V_31 )
return - V_39 ;
F_21 (cpu) {
snprintf ( V_33 , V_34 , L_3 , V_35 ) ;
V_32 = F_22 ( V_33 , V_40 ,
V_31 ,
F_23 ( V_7 , V_35 ) ,
& V_41 ) ;
if ( ! V_32 )
return - V_39 ;
}
return 0 ;
}
