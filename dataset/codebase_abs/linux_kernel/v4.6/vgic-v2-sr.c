static void T_1 F_1 ( struct V_1 * V_2 ,
void T_2 * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_8 ;
int V_9 = V_2 -> V_6 . V_7 . V_9 ;
T_3 V_10 , V_11 ;
int V_12 ;
bool V_13 ;
V_13 = ! ! ( V_5 -> V_14 & V_15 ) ;
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ ) {
if ( ! ( V_2 -> V_6 . V_7 . V_16 & ( 1UL << V_12 ) ) )
continue;
V_13 |= ( ! ( V_5 -> V_17 [ V_12 ] & V_18 ) &&
( V_5 -> V_17 [ V_12 ] & V_19 ) ) ;
}
if ( V_13 ) {
V_5 -> V_20 = F_2 ( V_3 + V_21 ) ;
if ( V_5 -> V_20 & V_22 ) {
V_10 = F_2 ( V_3 + V_23 ) ;
if ( F_3 ( V_9 > 32 ) )
V_11 = F_2 ( V_3 + V_24 ) ;
else
V_11 = 0 ;
} else {
V_10 = V_11 = 0 ;
}
} else {
V_5 -> V_20 = 0 ;
V_10 = V_11 = 0 ;
}
#ifdef F_4
V_5 -> V_25 = ( ( V_26 ) V_10 << 32 ) | V_11 ;
#else
V_5 -> V_25 = ( ( V_26 ) V_11 << 32 ) | V_10 ;
#endif
}
static void T_1 F_5 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_8 ;
int V_9 = V_2 -> V_6 . V_7 . V_9 ;
T_3 V_27 , V_28 ;
V_27 = F_2 ( V_3 + V_29 ) ;
if ( F_3 ( V_9 > 32 ) )
V_28 = F_2 ( V_3 + V_30 ) ;
else
V_28 = 0 ;
#ifdef F_4
V_5 -> V_31 = ( ( V_26 ) V_27 << 32 ) | V_28 ;
#else
V_5 -> V_31 = ( ( V_26 ) V_28 << 32 ) | V_27 ;
#endif
}
static void T_1 F_6 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_8 ;
int V_9 = V_2 -> V_6 . V_7 . V_9 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ ) {
if ( ! ( V_2 -> V_6 . V_7 . V_16 & ( 1UL << V_12 ) ) )
continue;
if ( V_5 -> V_31 & ( 1UL << V_12 ) ) {
V_5 -> V_17 [ V_12 ] &= ~ V_32 ;
continue;
}
V_5 -> V_17 [ V_12 ] = F_2 ( V_3 + V_33 + ( V_12 * 4 ) ) ;
F_7 ( 0 , V_3 + V_33 + ( V_12 * 4 ) ) ;
}
}
void T_1 F_8 ( struct V_1 * V_2 )
{
struct V_34 * V_34 = F_9 ( V_2 -> V_34 ) ;
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_8 ;
struct V_35 * V_36 = & V_34 -> V_6 . V_36 ;
void T_2 * V_3 = F_9 ( V_36 -> V_37 ) ;
if ( ! V_3 )
return;
V_5 -> V_38 = F_2 ( V_3 + V_39 ) ;
if ( V_2 -> V_6 . V_7 . V_16 ) {
V_5 -> V_40 = F_2 ( V_3 + V_41 ) ;
F_1 ( V_2 , V_3 ) ;
F_5 ( V_2 , V_3 ) ;
F_6 ( V_2 , V_3 ) ;
F_7 ( 0 , V_3 + V_42 ) ;
V_2 -> V_6 . V_7 . V_16 = 0 ;
} else {
V_5 -> V_25 = 0 ;
V_5 -> V_31 = ~ 0UL ;
V_5 -> V_20 = 0 ;
V_5 -> V_40 = 0 ;
}
}
void T_1 F_10 ( struct V_1 * V_2 )
{
struct V_34 * V_34 = F_9 ( V_2 -> V_34 ) ;
struct V_4 * V_5 = & V_2 -> V_6 . V_7 . V_8 ;
struct V_35 * V_36 = & V_34 -> V_6 . V_36 ;
void T_2 * V_3 = F_9 ( V_36 -> V_37 ) ;
int V_12 , V_9 ;
V_26 V_16 = 0 ;
if ( ! V_3 )
return;
V_9 = V_2 -> V_6 . V_7 . V_9 ;
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ )
if ( V_5 -> V_17 [ V_12 ] & V_32 )
V_16 |= 1UL << V_12 ;
if ( V_16 ) {
F_7 ( V_5 -> V_14 , V_3 + V_42 ) ;
F_7 ( V_5 -> V_40 , V_3 + V_41 ) ;
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ ) {
if ( ! ( V_16 & ( 1UL << V_12 ) ) )
continue;
F_7 ( V_5 -> V_17 [ V_12 ] ,
V_3 + V_33 + ( V_12 * 4 ) ) ;
}
}
F_7 ( V_5 -> V_38 , V_3 + V_39 ) ;
V_2 -> V_6 . V_7 . V_16 = V_16 ;
}
