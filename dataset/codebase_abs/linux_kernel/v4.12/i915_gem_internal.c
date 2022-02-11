static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
for ( V_4 = V_2 -> V_5 ; V_4 ; V_4 = F_2 ( V_4 ) ) {
if ( F_3 ( V_4 ) )
F_4 ( F_3 ( V_4 ) , F_5 ( V_4 -> V_6 ) ) ;
}
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static struct V_1 *
F_8 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_9 ( V_8 -> V_11 . V_12 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
unsigned int V_13 ;
int V_14 ;
T_1 V_15 ;
V_14 = V_16 ;
#ifdef F_10
if ( F_11 () ) {
unsigned int V_17 ;
V_17 = F_12 () ;
if ( V_17 ) {
V_17 = F_13 (unsigned int, max_segment,
PAGE_SIZE) >> V_18 ;
V_14 = F_14 ( V_14 , F_15 ( V_17 ) ) ;
}
}
#endif
V_15 = V_19 | V_20 | V_21 ;
if ( F_16 ( V_10 ) || F_17 ( V_10 ) ) {
V_15 &= ~ V_20 ;
V_15 |= V_22 ;
}
V_23:
V_2 = F_18 ( sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 )
return F_19 ( - V_24 ) ;
V_13 = V_8 -> V_11 . V_25 / V_26 ;
if ( F_20 ( V_2 , V_13 , V_19 ) ) {
F_7 ( V_2 ) ;
return F_19 ( - V_24 ) ;
}
V_4 = V_2 -> V_5 ;
V_2 -> V_27 = 0 ;
do {
int V_28 = F_14 ( F_21 ( V_13 ) - 1 , V_14 ) ;
struct V_29 * V_29 ;
do {
V_29 = F_22 ( V_15 | ( V_28 ? V_30 : 0 ) , V_28 ) ;
if ( V_29 )
break;
if ( ! V_28 -- )
goto V_31;
V_14 = V_28 ;
} while ( 1 );
F_23 ( V_4 , V_29 , V_26 << V_28 , 0 ) ;
V_2 -> V_27 ++ ;
V_13 -= 1 << V_28 ;
if ( ! V_13 ) {
F_24 ( V_4 ) ;
break;
}
V_4 = F_2 ( V_4 ) ;
} while ( 1 );
if ( F_25 ( V_8 , V_2 ) ) {
if ( F_5 ( V_2 -> V_5 -> V_6 ) ) {
F_1 ( V_2 ) ;
V_14 = 0 ;
goto V_23;
}
goto V_31;
}
V_8 -> V_32 . V_33 = V_34 ;
return V_2 ;
V_31:
F_23 ( V_4 , NULL , 0 , 0 ) ;
F_24 ( V_4 ) ;
F_1 ( V_2 ) ;
return F_19 ( - V_24 ) ;
}
static void F_26 ( struct V_7 * V_8 ,
struct V_1 * V_35 )
{
F_27 ( V_8 , V_35 ) ;
F_1 ( V_35 ) ;
V_8 -> V_32 . V_36 = false ;
V_8 -> V_32 . V_33 = V_37 ;
}
struct V_7 *
F_28 ( struct V_9 * V_10 ,
T_2 V_25 )
{
struct V_7 * V_8 ;
F_29 ( ! V_25 ) ;
F_29 ( ! F_30 ( V_25 , V_26 ) ) ;
if ( F_31 ( V_25 , V_8 -> V_11 . V_25 ) )
return F_19 ( - V_38 ) ;
V_8 = F_32 ( V_10 ) ;
if ( ! V_8 )
return F_19 ( - V_24 ) ;
F_33 ( & V_10 -> V_39 , & V_8 -> V_11 , V_25 ) ;
F_34 ( V_8 , & V_40 ) ;
V_8 -> V_11 . V_41 = V_42 ;
V_8 -> V_11 . V_43 = V_42 ;
V_8 -> V_44 = F_35 ( V_10 ) ? V_45 : V_46 ;
return V_8 ;
}
