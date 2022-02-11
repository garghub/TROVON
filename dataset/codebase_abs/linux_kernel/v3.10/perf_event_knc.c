static T_1 F_1 ( int V_1 )
{
return V_2 [ V_1 ] ;
}
static void F_2 ( void )
{
T_1 V_3 ;
F_3 ( V_4 , V_3 ) ;
V_3 &= ~ ( V_5 | V_6 ) ;
F_4 ( V_4 , V_3 ) ;
}
static void F_5 ( int V_7 )
{
T_1 V_3 ;
F_3 ( V_4 , V_3 ) ;
V_3 |= ( V_5 | V_6 ) ;
F_4 ( V_4 , V_3 ) ;
}
static inline void
F_6 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
T_1 V_3 ;
V_3 = V_11 -> V_13 ;
V_3 &= ~ V_14 ;
( void ) F_7 ( V_11 -> V_15 + V_11 -> V_16 , V_3 ) ;
}
static void F_8 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
T_1 V_3 ;
V_3 = V_11 -> V_13 ;
V_3 |= V_14 ;
( void ) F_7 ( V_11 -> V_15 + V_11 -> V_16 , V_3 ) ;
}
static inline T_1 F_9 ( void )
{
T_1 V_17 ;
F_3 ( V_18 , V_17 ) ;
return V_17 ;
}
static inline void F_10 ( T_1 V_19 )
{
F_4 ( V_20 , V_19 ) ;
}
static int F_11 ( struct V_21 * V_22 )
{
struct V_23 V_24 ;
struct V_25 * V_26 ;
int V_27 = 0 ;
int V_28 , V_29 ;
T_1 V_17 ;
V_26 = & F_12 ( V_25 ) ;
F_2 () ;
V_17 = F_9 () ;
if ( ! V_17 ) {
F_5 ( 0 ) ;
return V_27 ;
}
V_29 = 0 ;
V_30:
F_10 ( V_17 ) ;
if ( ++ V_29 > 100 ) {
F_13 ( 1 , L_1 ) ;
F_14 () ;
goto V_31;
}
F_15 ( V_32 ) ;
F_16 (bit, (unsigned long *)&status, X86_PMC_IDX_MAX) {
struct V_8 * V_9 = V_26 -> V_33 [ V_28 ] ;
V_27 ++ ;
if ( ! F_17 ( V_28 , V_26 -> V_34 ) )
continue;
if ( ! F_18 ( V_9 ) )
continue;
F_19 ( & V_24 , 0 , V_9 -> V_12 . V_35 ) ;
if ( F_20 ( V_9 , & V_24 , V_22 ) )
F_21 ( V_9 , 0 ) ;
}
V_17 = F_9 () ;
if ( V_17 )
goto V_30;
V_31:
F_5 ( 0 ) ;
return V_27 ;
}
T_2 int F_22 ( void )
{
V_36 = V_37 ;
memcpy ( V_38 , V_39 ,
sizeof( V_38 ) ) ;
return 0 ;
}
