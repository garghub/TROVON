static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
for ( V_4 = V_2 -> V_5 ; V_4 ; V_4 = F_2 ( V_4 ) )
F_3 ( F_4 ( V_4 ) , F_5 ( V_4 -> V_6 ) ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static struct V_1 *
F_8 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_9 ( V_8 -> V_11 . V_12 ) ;
unsigned int V_13 = V_8 -> V_11 . V_14 / V_15 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_16 ;
T_1 V_17 ;
V_2 = F_10 ( sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 )
return F_11 ( - V_19 ) ;
if ( F_12 ( V_2 , V_13 , V_18 ) ) {
F_7 ( V_2 ) ;
return F_11 ( - V_19 ) ;
}
V_4 = V_2 -> V_5 ;
V_2 -> V_20 = 0 ;
V_16 = V_21 ;
#ifdef F_13
if ( F_14 () ) {
unsigned int V_22 ;
V_22 = F_15 () ;
if ( V_22 ) {
V_22 = F_16 (unsigned int, max_segment,
PAGE_SIZE) >> V_23 ;
V_16 = F_17 ( V_16 , F_18 ( V_22 ) ) ;
}
}
#endif
V_17 = V_18 | V_24 | V_25 ;
if ( F_19 ( V_10 ) || F_20 ( V_10 ) ) {
V_17 &= ~ V_24 ;
V_17 |= V_26 ;
}
do {
int V_27 = F_17 ( F_21 ( V_13 ) - 1 , V_16 ) ;
struct V_28 * V_28 ;
do {
V_28 = F_22 ( V_17 | ( V_27 ? V_29 : 0 ) , V_27 ) ;
if ( V_28 )
break;
if ( ! V_27 -- )
goto V_30;
V_16 = V_27 ;
} while ( 1 );
F_23 ( V_4 , V_28 , V_15 << V_27 , 0 ) ;
V_2 -> V_20 ++ ;
V_13 -= 1 << V_27 ;
if ( ! V_13 ) {
F_24 ( V_4 ) ;
break;
}
V_4 = F_2 ( V_4 ) ;
} while ( 1 );
if ( F_25 ( V_8 , V_2 ) )
goto V_30;
V_8 -> V_31 . V_32 = V_33 ;
return V_2 ;
V_30:
F_24 ( V_4 ) ;
F_1 ( V_2 ) ;
return F_11 ( - V_19 ) ;
}
static void F_26 ( struct V_7 * V_8 ,
struct V_1 * V_34 )
{
F_27 ( V_8 , V_34 ) ;
F_1 ( V_34 ) ;
V_8 -> V_31 . V_35 = false ;
V_8 -> V_31 . V_32 = V_36 ;
}
struct V_7 *
F_28 ( struct V_9 * V_10 ,
unsigned int V_14 )
{
struct V_7 * V_8 ;
V_8 = F_29 ( & V_10 -> V_37 ) ;
if ( ! V_8 )
return F_11 ( - V_19 ) ;
F_30 ( & V_10 -> V_37 , & V_8 -> V_11 , V_14 ) ;
F_31 ( V_8 , & V_38 ) ;
V_8 -> V_11 . V_39 = V_40 ;
V_8 -> V_11 . V_41 = V_40 ;
V_8 -> V_42 = F_32 ( V_10 ) ? V_43 : V_44 ;
return V_8 ;
}
