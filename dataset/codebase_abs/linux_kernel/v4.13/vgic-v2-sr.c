static void T_1 F_1 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_8 ;
int V_9 = ( F_2 ( & V_10 ) ) -> V_9 ;
T_3 V_11 , V_12 ;
V_11 = F_3 ( V_3 + V_13 ) ;
if ( F_4 ( V_9 > 32 ) )
V_12 = F_3 ( V_3 + V_14 ) ;
else
V_12 = 0 ;
#ifdef F_5
V_5 -> V_15 = ( ( V_16 ) V_11 << 32 ) | V_12 ;
#else
V_5 -> V_15 = ( ( V_16 ) V_12 << 32 ) | V_11 ;
#endif
}
static void T_1 F_6 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_8 ;
int V_17 ;
V_16 V_18 = V_2 -> V_6 . V_7 . V_18 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
if ( V_5 -> V_15 & ( 1UL << V_17 ) )
V_5 -> V_19 [ V_17 ] &= ~ V_20 ;
else
V_5 -> V_19 [ V_17 ] = F_3 ( V_3 + V_21 + ( V_17 * 4 ) ) ;
F_7 ( 0 , V_3 + V_21 + ( V_17 * 4 ) ) ;
}
}
void T_1 F_8 ( struct V_1 * V_2 )
{
struct V_22 * V_22 = F_2 ( V_2 -> V_22 ) ;
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_8 ;
struct V_23 * V_24 = & V_22 -> V_6 . V_24 ;
void T_2 * V_3 = F_2 ( V_24 -> V_25 ) ;
V_16 V_18 = V_2 -> V_6 . V_7 . V_18 ;
if ( ! V_3 )
return;
if ( V_18 ) {
V_5 -> V_26 = F_3 ( V_3 + V_27 ) ;
F_1 ( V_2 , V_3 ) ;
F_6 ( V_2 , V_3 ) ;
F_7 ( 0 , V_3 + V_28 ) ;
} else {
V_5 -> V_15 = ~ 0UL ;
V_5 -> V_26 = 0 ;
}
}
void T_1 F_9 ( struct V_1 * V_2 )
{
struct V_22 * V_22 = F_2 ( V_2 -> V_22 ) ;
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_8 ;
struct V_23 * V_24 = & V_22 -> V_6 . V_24 ;
void T_2 * V_3 = F_2 ( V_24 -> V_25 ) ;
int V_17 ;
V_16 V_18 = V_2 -> V_6 . V_7 . V_18 ;
if ( ! V_3 )
return;
if ( V_18 ) {
F_7 ( V_5 -> V_29 , V_3 + V_28 ) ;
F_7 ( V_5 -> V_26 , V_3 + V_27 ) ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
F_7 ( V_5 -> V_19 [ V_17 ] ,
V_3 + V_21 + ( V_17 * 4 ) ) ;
}
}
}
int T_1 F_10 ( struct V_1 * V_2 )
{
struct V_22 * V_22 = F_2 ( V_2 -> V_22 ) ;
struct V_23 * V_24 = & V_22 -> V_6 . V_24 ;
T_4 V_30 ;
void T_2 * V_31 ;
int V_32 ;
V_30 = F_11 ( V_2 ) ;
V_30 |= F_12 ( V_2 ) & F_13 ( 11 , 0 ) ;
if ( V_30 < V_24 -> V_33 ||
V_30 >= ( V_24 -> V_33 + V_34 ) )
return 0 ;
if ( F_14 ( V_2 ) != sizeof( T_3 ) )
return - 1 ;
if ( V_30 & 3 )
return - 1 ;
V_32 = F_15 ( V_2 ) ;
V_31 = F_2 ( ( F_2 ( & V_10 ) ) -> V_35 ) ;
V_31 += V_30 - V_24 -> V_33 ;
if ( F_16 ( V_2 ) ) {
T_3 V_36 = F_17 ( V_2 ,
F_18 ( V_2 , V_32 ) ,
sizeof( T_3 ) ) ;
F_7 ( V_36 , V_31 ) ;
} else {
T_3 V_36 = F_3 ( V_31 ) ;
F_19 ( V_2 , V_32 , F_20 ( V_2 , V_36 ,
sizeof( T_3 ) ) ) ;
}
return 1 ;
}
