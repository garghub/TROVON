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
V_17 -> V_9 = V_15 -> V_20 . V_21 -> V_22 -> V_23 ;
return V_16 ;
}
static void F_9 ( void * V_24 , unsigned long V_25 , unsigned long * args )
{
struct V_7 * V_26 ;
if ( V_25 > V_27 )
return;
V_26 = & F_10 ( V_7 ) [ V_25 / 4 ] ;
V_26 -> V_28 = F_11 () ;
V_26 -> V_29 = F_12 ( V_30 ) ;
}
static void F_13 ( void * V_24 , unsigned long V_25 , unsigned long V_31 ,
unsigned long * V_32 )
{
struct V_7 * V_26 ;
if ( V_25 > V_27 )
return;
V_26 = & F_14 ( V_7 ) [ V_25 / 4 ] ;
V_26 -> V_10 ++ ;
V_26 -> V_12 += F_11 () - V_26 -> V_28 ;
V_26 -> V_13 += F_12 ( V_30 ) - V_26 -> V_29 ;
F_15 ( V_7 ) ;
}
static int T_2 F_16 ( void )
{
struct V_21 * V_33 ;
struct V_21 * V_34 ;
char V_35 [ V_36 ] ;
int V_37 ;
if ( ! F_17 ( V_38 ) )
return 0 ;
if ( F_18 ( F_9 , NULL ) )
return - V_39 ;
if ( F_19 ( F_13 , NULL ) ) {
F_20 ( F_9 , NULL ) ;
return - V_39 ;
}
V_33 = F_21 ( V_40 , NULL ) ;
if ( ! V_33 )
return - V_41 ;
F_22 (cpu) {
snprintf ( V_35 , V_36 , L_3 , V_37 ) ;
V_34 = F_23 ( V_35 , V_42 ,
V_33 ,
F_24 ( V_7 , V_37 ) ,
& V_43 ) ;
if ( ! V_34 )
return - V_41 ;
}
return 0 ;
}
