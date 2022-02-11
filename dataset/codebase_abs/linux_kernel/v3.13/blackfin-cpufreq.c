static void T_1 F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 , V_4 ;
int V_5 ;
#if V_6 || V_7 || \
( ! ( F_2 ( V_8 ) || F_2 ( V_9 ) ) \
&& F_2 ( V_10 ) )
V_4 = V_2 * 2 ;
#else
V_4 = V_2 ;
#endif
#ifndef V_9
V_3 = ( ( F_3 () & V_11 ) >> 4 ) ;
#else
V_3 = F_4 ( V_12 ) & 0x1F ;
#endif
for ( V_5 = 0 ; ( V_1 >> V_5 ) >= V_4 && V_3 <= 3 && V_5 < 3 ; V_5 ++ , V_3 ++ ) {
V_13 [ V_5 ] . V_14 = V_1 >> V_5 ;
#ifndef V_9
V_15 [ V_5 ] . V_3 = V_3 << 4 ;
#else
V_15 [ V_5 ] . V_3 = V_3 ;
#endif
V_15 [ V_5 ] . V_16 = ( V_17 >> V_5 ) - 1 ;
F_5 ( L_1 ,
V_13 [ V_5 ] . V_14 ,
V_15 [ V_5 ] . V_3 ,
V_15 [ V_5 ] . V_16 ) ;
}
return;
}
static void F_6 ( void * V_18 )
{
unsigned int V_16 ;
unsigned int V_5 = * ( unsigned int * ) V_18 ;
V_16 = V_15 [ V_5 ] . V_16 ;
F_7 ( V_16 ) ;
return;
}
static unsigned int F_8 ( unsigned int V_19 )
{
return F_9 () / 1000 ;
}
unsigned long F_10 ( int V_19 , unsigned long V_20 )
{
struct V_21 * V_21 ;
int V_22 ;
V_21 = F_11 ( NULL , L_2 ) ;
if ( F_12 ( V_21 ) )
return - V_23 ;
V_22 = F_13 ( V_21 , V_20 ) ;
F_14 ( V_21 ) ;
return V_22 ;
}
static int F_15 ( struct V_24 * V_25 , unsigned int V_5 )
{
#ifndef V_9
unsigned int V_26 ;
#endif
static unsigned long V_27 ;
static unsigned int V_28 ;
unsigned int V_29 , V_30 ;
int V_22 = 0 ;
#if F_2 ( V_31 )
T_2 V_32 ;
#endif
V_29 = F_8 ( 0 ) ;
V_30 = V_13 [ V_5 ] . V_14 ;
#ifndef V_9
V_26 = ( F_3 () & V_33 ) | V_15 [ V_5 ] . V_3 ;
F_16 ( V_26 ) ;
#else
V_22 = F_10 ( V_25 -> V_19 , V_30 * 1000 ) ;
if ( V_22 != 0 ) {
F_17 ( V_22 , L_3 , V_22 ) ;
return V_22 ;
}
#endif
F_18 ( F_6 , & V_5 , 1 ) ;
#if F_2 ( V_31 )
V_32 = F_19 () ;
F_20 () ;
V_32 += 10 ;
V_34 += ( V_32 << V_35 ) - ( V_32 << V_5 ) ;
V_35 = V_5 ;
#endif
if ( ! V_28 ) {
V_27 = V_36 ;
V_28 = V_29 ;
}
if ( V_30 != V_29 ) {
V_36 = F_21 ( V_27 ,
V_28 , V_30 ) ;
}
return V_22 ;
}
static int F_22 ( struct V_24 * V_25 )
{
unsigned long V_1 , V_2 ;
V_1 = F_9 () / 1000 ;
V_2 = F_23 () / 1000 ;
if ( V_25 -> V_19 == V_37 )
F_1 ( V_1 , V_2 ) ;
V_25 -> V_38 . V_39 = 50000 ;
return F_24 ( V_25 , V_13 ) ;
}
static int T_1 F_25 ( void )
{
return F_26 ( & V_40 ) ;
}
static void T_3 F_27 ( void )
{
F_28 ( & V_40 ) ;
}
