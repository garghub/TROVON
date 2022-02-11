static void T_1 F_1 ( struct V_1 * V_2 ,
void T_2 * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_8 ;
int V_9 = ( F_2 ( & V_10 ) ) -> V_9 ;
T_3 V_11 , V_12 ;
int V_13 ;
bool V_14 ;
V_14 = ! ! ( V_5 -> V_15 & V_16 ) ;
for ( V_13 = 0 ; V_13 < V_9 ; V_13 ++ ) {
if ( ! ( V_2 -> V_6 . V_7 . V_17 & ( 1UL << V_13 ) ) )
continue;
V_14 |= ( ! ( V_5 -> V_18 [ V_13 ] & V_19 ) &&
( V_5 -> V_18 [ V_13 ] & V_20 ) ) ;
}
if ( V_14 ) {
V_5 -> V_21 = F_3 ( V_3 + V_22 ) ;
if ( V_5 -> V_21 & V_23 ) {
V_11 = F_3 ( V_3 + V_24 ) ;
if ( F_4 ( V_9 > 32 ) )
V_12 = F_3 ( V_3 + V_25 ) ;
else
V_12 = 0 ;
} else {
V_11 = V_12 = 0 ;
}
} else {
V_5 -> V_21 = 0 ;
V_11 = V_12 = 0 ;
}
#ifdef F_5
V_5 -> V_26 = ( ( V_27 ) V_11 << 32 ) | V_12 ;
#else
V_5 -> V_26 = ( ( V_27 ) V_12 << 32 ) | V_11 ;
#endif
}
static void T_1 F_6 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_8 ;
int V_9 = ( F_2 ( & V_10 ) ) -> V_9 ;
T_3 V_28 , V_29 ;
V_28 = F_3 ( V_3 + V_30 ) ;
if ( F_4 ( V_9 > 32 ) )
V_29 = F_3 ( V_3 + V_31 ) ;
else
V_29 = 0 ;
#ifdef F_5
V_5 -> V_32 = ( ( V_27 ) V_28 << 32 ) | V_29 ;
#else
V_5 -> V_32 = ( ( V_27 ) V_29 << 32 ) | V_28 ;
#endif
}
static void T_1 F_7 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_8 ;
int V_9 = ( F_2 ( & V_10 ) ) -> V_9 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_9 ; V_13 ++ ) {
if ( ! ( V_2 -> V_6 . V_7 . V_17 & ( 1UL << V_13 ) ) )
continue;
if ( V_5 -> V_32 & ( 1UL << V_13 ) )
V_5 -> V_18 [ V_13 ] &= ~ V_33 ;
else
V_5 -> V_18 [ V_13 ] = F_3 ( V_3 + V_34 + ( V_13 * 4 ) ) ;
F_8 ( 0 , V_3 + V_34 + ( V_13 * 4 ) ) ;
}
}
void T_1 F_9 ( struct V_1 * V_2 )
{
struct V_35 * V_35 = F_2 ( V_2 -> V_35 ) ;
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_8 ;
struct V_36 * V_37 = & V_35 -> V_6 . V_37 ;
void T_2 * V_3 = F_2 ( V_37 -> V_38 ) ;
if ( ! V_3 )
return;
V_5 -> V_39 = F_3 ( V_3 + V_40 ) ;
if ( V_2 -> V_6 . V_7 . V_17 ) {
V_5 -> V_41 = F_3 ( V_3 + V_42 ) ;
F_1 ( V_2 , V_3 ) ;
F_6 ( V_2 , V_3 ) ;
F_7 ( V_2 , V_3 ) ;
F_8 ( 0 , V_3 + V_43 ) ;
V_2 -> V_6 . V_7 . V_17 = 0 ;
} else {
V_5 -> V_26 = 0 ;
V_5 -> V_32 = ~ 0UL ;
V_5 -> V_21 = 0 ;
V_5 -> V_41 = 0 ;
}
}
void T_1 F_10 ( struct V_1 * V_2 )
{
struct V_35 * V_35 = F_2 ( V_2 -> V_35 ) ;
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_8 ;
struct V_36 * V_37 = & V_35 -> V_6 . V_37 ;
void T_2 * V_3 = F_2 ( V_37 -> V_38 ) ;
int V_9 = ( F_2 ( & V_10 ) ) -> V_9 ;
int V_13 ;
V_27 V_17 = 0 ;
if ( ! V_3 )
return;
for ( V_13 = 0 ; V_13 < V_9 ; V_13 ++ )
if ( V_5 -> V_18 [ V_13 ] & V_33 )
V_17 |= 1UL << V_13 ;
if ( V_17 ) {
F_8 ( V_5 -> V_15 , V_3 + V_43 ) ;
F_8 ( V_5 -> V_41 , V_3 + V_42 ) ;
for ( V_13 = 0 ; V_13 < V_9 ; V_13 ++ ) {
if ( ! ( V_17 & ( 1UL << V_13 ) ) )
continue;
F_8 ( V_5 -> V_18 [ V_13 ] ,
V_3 + V_34 + ( V_13 * 4 ) ) ;
}
}
F_8 ( V_5 -> V_39 , V_3 + V_40 ) ;
V_2 -> V_6 . V_7 . V_17 = V_17 ;
}
