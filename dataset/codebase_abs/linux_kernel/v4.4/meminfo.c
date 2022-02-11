static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 V_5 ;
unsigned long V_6 ;
long V_7 ;
long V_8 ;
unsigned long V_9 ;
unsigned long V_10 = 0 ;
unsigned long V_11 [ V_12 ] ;
struct V_13 * V_13 ;
int V_14 ;
#define F_2 ( T_1 ) ((x) << (PAGE_SHIFT - 10))
F_3 ( & V_5 ) ;
F_4 ( & V_5 ) ;
V_6 = F_5 ( & V_15 ) ;
V_7 = F_6 ( V_16 ) -
F_7 () - V_5 . V_17 ;
if ( V_7 < 0 )
V_7 = 0 ;
for ( V_14 = V_18 ; V_14 < V_12 ; V_14 ++ )
V_11 [ V_14 ] = F_6 ( V_19 + V_14 ) ;
F_8 (zone)
V_10 += V_13 -> V_20 [ V_21 ] ;
V_8 = V_5 . V_22 - V_10 ;
V_9 = V_11 [ V_23 ] + V_11 [ V_24 ] ;
V_9 -= F_9 ( V_9 / 2 , V_10 ) ;
V_8 += V_9 ;
V_8 += F_6 ( V_25 ) -
F_9 ( F_6 ( V_25 ) / 2 , V_10 ) ;
if ( V_8 < 0 )
V_8 = 0 ;
F_10 ( V_2 ,
L_1
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11
L_12
L_13
L_14
#ifdef F_11
L_15
L_16
L_17
L_18
#endif
#ifndef F_12
L_19
#endif
L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_30
L_31
#ifdef F_13
L_32
#endif
L_33
L_34
L_35
L_36
L_37
L_38
L_39
L_40
#ifdef F_14
L_41
#endif
#ifdef F_15
L_42
#endif
#ifdef F_16
L_43
L_44
#endif
,
F_2 ( V_5 . V_26 ) ,
F_2 ( V_5 . V_22 ) ,
F_2 ( V_8 ) ,
F_2 ( V_5 . V_17 ) ,
F_2 ( V_7 ) ,
F_2 ( F_7 () ) ,
F_2 ( V_11 [ V_27 ] + V_11 [ V_23 ] ) ,
F_2 ( V_11 [ V_28 ] + V_11 [ V_24 ] ) ,
F_2 ( V_11 [ V_27 ] ) ,
F_2 ( V_11 [ V_28 ] ) ,
F_2 ( V_11 [ V_23 ] ) ,
F_2 ( V_11 [ V_24 ] ) ,
F_2 ( V_11 [ V_29 ] ) ,
F_2 ( F_6 ( V_30 ) ) ,
#ifdef F_11
F_2 ( V_5 . V_31 ) ,
F_2 ( V_5 . V_32 ) ,
F_2 ( V_5 . V_26 - V_5 . V_31 ) ,
F_2 ( V_5 . V_22 - V_5 . V_32 ) ,
#endif
#ifndef F_12
F_2 ( ( unsigned long ) F_17 ( & V_33 ) ) ,
#endif
F_2 ( V_5 . V_34 ) ,
F_2 ( V_5 . V_35 ) ,
F_2 ( F_6 ( V_36 ) ) ,
F_2 ( F_6 ( V_37 ) ) ,
F_2 ( F_6 ( V_38 ) ) ,
F_2 ( F_6 ( V_39 ) ) ,
F_2 ( V_5 . V_40 ) ,
F_2 ( F_6 ( V_25 ) +
F_6 ( V_41 ) ) ,
F_2 ( F_6 ( V_25 ) ) ,
F_2 ( F_6 ( V_41 ) ) ,
F_6 ( V_42 ) * V_43 / 1024 ,
F_2 ( F_6 ( V_44 ) ) ,
#ifdef F_13
F_2 ( F_18 () ) ,
#endif
F_2 ( F_6 ( V_45 ) ) ,
F_2 ( F_6 ( V_46 ) ) ,
F_2 ( F_6 ( V_47 ) ) ,
F_2 ( F_19 () ) ,
F_2 ( V_6 ) ,
( unsigned long ) V_48 >> 10 ,
0ul ,
0ul
#ifdef F_14
, F_17 ( & V_49 ) << ( V_50 - 10 )
#endif
#ifdef F_15
, F_2 ( F_6 ( V_51 ) *
V_52 )
#endif
#ifdef F_16
, F_2 ( V_53 )
, F_2 ( F_6 ( V_54 ) )
#endif
) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
return 0 ;
#undef F_2
}
static int F_22 ( struct V_55 * V_55 , struct V_56 * V_56 )
{
return F_23 ( V_56 , F_1 , NULL ) ;
}
static int T_2 F_24 ( void )
{
F_25 ( L_45 , 0 , NULL , & V_57 ) ;
return 0 ;
}
