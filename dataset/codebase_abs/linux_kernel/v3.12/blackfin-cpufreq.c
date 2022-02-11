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
static int F_15 ( struct V_24 * V_25 ,
unsigned int V_26 , unsigned int V_27 )
{
#ifndef V_9
unsigned int V_28 ;
#endif
unsigned int V_5 ;
unsigned long V_29 ;
struct V_30 V_31 ;
static unsigned long V_32 ;
static unsigned int V_33 ;
int V_22 = 0 ;
#if F_2 ( V_34 )
T_2 V_35 ;
#endif
if ( F_16 ( V_25 , V_13 , V_26 ,
V_27 , & V_5 ) )
return - V_36 ;
V_29 = V_13 [ V_5 ] . V_14 ;
V_31 . V_37 = F_8 ( 0 ) ;
V_31 . V_20 = V_29 ;
F_5 ( L_3 ,
V_29 , V_26 , V_31 . V_37 ) ;
F_17 ( V_25 , & V_31 , V_38 ) ;
#ifndef V_9
V_28 = ( F_3 () & V_39 ) | V_15 [ V_5 ] . V_3 ;
F_18 ( V_28 ) ;
#else
V_22 = F_10 ( V_25 -> V_19 , V_31 . V_20 * 1000 ) ;
if ( V_22 != 0 ) {
F_19 ( V_22 , L_4 , V_22 ) ;
return V_22 ;
}
#endif
F_20 ( F_6 , & V_5 , 1 ) ;
#if F_2 ( V_34 )
V_35 = F_21 () ;
F_22 () ;
V_35 += 10 ;
V_40 += ( V_35 << V_41 ) - ( V_35 << V_5 ) ;
V_41 = V_5 ;
#endif
if ( ! V_33 ) {
V_32 = V_42 ;
V_33 = V_31 . V_37 ;
}
if ( V_31 . V_20 != V_31 . V_37 ) {
V_42 = F_23 ( V_32 ,
V_33 , V_31 . V_20 ) ;
}
F_17 ( V_25 , & V_31 , V_43 ) ;
F_5 ( L_5 ) ;
return V_22 ;
}
static int F_24 ( struct V_24 * V_25 )
{
return F_25 ( V_25 , V_13 ) ;
}
static int F_26 ( struct V_24 * V_25 )
{
unsigned long V_1 , V_2 ;
V_1 = F_9 () / 1000 ;
V_2 = F_27 () / 1000 ;
if ( V_25 -> V_19 == V_44 )
F_1 ( V_1 , V_2 ) ;
V_25 -> V_45 . V_46 = 50000 ;
V_25 -> V_47 = V_1 ;
F_28 ( V_13 , V_25 -> V_19 ) ;
return F_29 ( V_25 , V_13 ) ;
}
static int T_1 F_30 ( void )
{
return F_31 ( & V_48 ) ;
}
static void T_3 F_32 ( void )
{
F_33 ( & V_48 ) ;
}
