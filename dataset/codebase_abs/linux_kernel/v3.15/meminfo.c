static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 V_5 ;
unsigned long V_6 ;
struct V_7 V_8 ;
long V_9 ;
long V_10 ;
unsigned long V_11 ;
unsigned long V_12 = 0 ;
unsigned long V_13 [ V_14 ] ;
struct V_15 * V_15 ;
int V_16 ;
#define F_2 ( T_1 ) ((x) << (PAGE_SHIFT - 10))
F_3 ( & V_5 ) ;
F_4 ( & V_5 ) ;
V_6 = F_5 ( & V_17 ) ;
V_9 = F_6 ( V_18 ) -
F_7 () - V_5 . V_19 ;
if ( V_9 < 0 )
V_9 = 0 ;
F_8 ( & V_8 ) ;
for ( V_16 = V_20 ; V_16 < V_14 ; V_16 ++ )
V_13 [ V_16 ] = F_6 ( V_21 + V_16 ) ;
F_9 (zone)
V_12 += V_15 -> V_22 [ V_23 ] ;
V_10 = V_5 . V_24 - V_12 ;
V_11 = V_13 [ V_25 ] + V_13 [ V_26 ] ;
V_11 -= F_10 ( V_11 / 2 , V_12 ) ;
V_10 += V_11 ;
V_10 += F_6 ( V_27 ) -
F_10 ( F_6 ( V_27 ) / 2 , V_12 ) ;
if ( V_10 < 0 )
V_10 = 0 ;
F_11 ( V_2 ,
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
#ifdef F_12
L_15
L_16
L_17
L_18
#endif
#ifndef F_13
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
#ifdef F_14
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
#ifdef F_15
L_41
#endif
#ifdef F_16
L_42
#endif
,
F_2 ( V_5 . V_28 ) ,
F_2 ( V_5 . V_24 ) ,
F_2 ( V_10 ) ,
F_2 ( V_5 . V_19 ) ,
F_2 ( V_9 ) ,
F_2 ( F_7 () ) ,
F_2 ( V_13 [ V_29 ] + V_13 [ V_25 ] ) ,
F_2 ( V_13 [ V_30 ] + V_13 [ V_26 ] ) ,
F_2 ( V_13 [ V_29 ] ) ,
F_2 ( V_13 [ V_30 ] ) ,
F_2 ( V_13 [ V_25 ] ) ,
F_2 ( V_13 [ V_26 ] ) ,
F_2 ( V_13 [ V_31 ] ) ,
F_2 ( F_6 ( V_32 ) ) ,
#ifdef F_12
F_2 ( V_5 . V_33 ) ,
F_2 ( V_5 . V_34 ) ,
F_2 ( V_5 . V_28 - V_5 . V_33 ) ,
F_2 ( V_5 . V_24 - V_5 . V_34 ) ,
#endif
#ifndef F_13
F_2 ( ( unsigned long ) F_17 ( & V_35 ) ) ,
#endif
F_2 ( V_5 . V_36 ) ,
F_2 ( V_5 . V_37 ) ,
F_2 ( F_6 ( V_38 ) ) ,
F_2 ( F_6 ( V_39 ) ) ,
F_2 ( F_6 ( V_40 ) ) ,
F_2 ( F_6 ( V_41 ) ) ,
F_2 ( F_6 ( V_42 ) ) ,
F_2 ( F_6 ( V_27 ) +
F_6 ( V_43 ) ) ,
F_2 ( F_6 ( V_27 ) ) ,
F_2 ( F_6 ( V_43 ) ) ,
F_6 ( V_44 ) * V_45 / 1024 ,
F_2 ( F_6 ( V_46 ) ) ,
#ifdef F_14
F_2 ( F_18 () ) ,
#endif
F_2 ( F_6 ( V_47 ) ) ,
F_2 ( F_6 ( V_48 ) ) ,
F_2 ( F_6 ( V_49 ) ) ,
F_2 ( F_19 () ) ,
F_2 ( V_6 ) ,
( unsigned long ) V_50 >> 10 ,
V_8 . V_51 >> 10 ,
V_8 . V_52 >> 10
#ifdef F_15
, F_17 ( & V_53 ) << ( V_54 - 10 )
#endif
#ifdef F_16
, F_2 ( F_6 ( V_55 ) *
V_56 )
#endif
) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
return 0 ;
#undef F_2
}
static int F_22 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_23 ( V_58 , F_1 , NULL ) ;
}
static int T_2 F_24 ( void )
{
F_25 ( L_43 , 0 , NULL , & V_59 ) ;
return 0 ;
}
