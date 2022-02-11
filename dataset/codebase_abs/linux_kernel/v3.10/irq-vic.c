static inline void F_1 ( void T_1 * V_1 , unsigned int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
F_2 ( V_2 , V_1 + ( V_3 * 4 ) ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
void T_1 * V_7 = F_4 ( V_8 , V_6 -> V_9 ) ;
F_2 ( 1 << ( V_6 -> V_9 & 31 ) , V_7 ) ;
}
static void F_5 ( struct V_5 * V_6 )
{
void T_1 * V_7 = F_4 ( V_10 , V_6 -> V_9 ) ;
unsigned V_11 = F_6 ( V_6 -> V_9 ) ;
T_2 V_12 = 1UL << ( V_6 -> V_9 & 31 ) ;
int V_13 = V_14 [ V_6 -> V_9 ] ;
V_15 [ V_11 ] . V_16 [ 0 ] &= ~ V_12 ;
F_2 ( V_12 , V_7 ) ;
if ( V_13 == 0 )
V_17 [ V_11 ] &= ~ V_12 ;
else {
V_12 = 1UL << ( V_13 - 1 ) ;
V_18 [ 0 ] &= ~ V_12 ;
}
}
static void F_7 ( struct V_5 * V_6 )
{
void T_1 * V_7 = F_4 ( V_19 , V_6 -> V_9 ) ;
unsigned V_11 = F_6 ( V_6 -> V_9 ) ;
T_2 V_12 = 1UL << ( V_6 -> V_9 & 31 ) ;
int V_13 = V_14 [ V_6 -> V_9 ] ;
V_15 [ V_11 ] . V_16 [ 0 ] |= V_12 ;
F_2 ( V_12 , V_7 ) ;
if ( V_13 == 0 )
V_17 [ V_11 ] |= V_12 ;
else {
V_12 = 1UL << ( V_13 - 1 ) ;
V_18 [ 0 ] |= V_12 ;
}
}
static int F_8 ( struct V_5 * V_6 , unsigned int V_20 )
{
unsigned V_11 = F_6 ( V_6 -> V_9 ) ;
T_2 V_12 = 1UL << ( V_6 -> V_9 & 31 ) ;
int V_13 = V_14 [ V_6 -> V_9 ] ;
if ( V_13 == 0 ) {
F_9 ( V_21 L_1 , V_6 -> V_9 ) ;
return - V_22 ;
}
if ( V_20 )
V_15 [ V_11 ] . V_16 [ 1 ] |= V_12 ;
else
V_15 [ V_11 ] . V_16 [ 1 ] &= ~ V_12 ;
if ( V_13 == V_23 )
return 0 ;
V_12 = 1UL << ( V_13 - 1 ) ;
if ( V_20 )
V_18 [ 1 ] |= V_12 ;
else
V_18 [ 1 ] &= ~ V_12 ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 , unsigned int V_24 )
{
void T_1 * V_25 = F_4 ( V_26 , V_6 -> V_9 ) ;
void T_1 * V_27 = F_4 ( V_28 , V_6 -> V_9 ) ;
unsigned V_11 = F_6 ( V_6 -> V_9 ) ;
int V_29 = 1 << ( V_6 -> V_9 & 31 ) ;
T_2 V_30 ;
T_2 type ;
V_30 = V_15 [ V_11 ] . V_31 ;
if ( V_24 & ( V_32 | V_33 ) )
V_30 |= V_29 ;
if ( V_24 & ( V_34 | V_35 ) )
V_30 &= ~ V_29 ;
F_2 ( V_30 , V_27 ) ;
V_15 [ V_11 ] . V_31 = V_30 ;
type = V_15 [ V_11 ] . V_36 ;
if ( V_24 & ( V_34 | V_32 ) ) {
type |= V_29 ;
F_11 ( V_6 -> V_9 , V_37 ) ;
}
if ( V_24 & ( V_35 | V_33 ) ) {
type &= ~ V_29 ;
F_11 ( V_6 -> V_9 , V_38 ) ;
}
F_2 ( type , V_25 ) ;
V_15 [ V_11 ] . V_36 = type ;
return 0 ;
}
void T_3 F_12 ( void )
{
unsigned V_39 ;
F_1 ( V_26 , 0 ) ;
F_1 ( V_28 , 0 ) ;
F_1 ( V_40 , 0 ) ;
F_1 ( V_41 , 0 ) ;
F_2 ( 0 , V_42 ) ;
F_2 ( 3 , V_43 ) ;
for ( V_39 = 0 ; V_39 < V_44 ; V_39 ++ ) {
F_13 ( V_39 , & V_45 , V_38 ) ;
F_14 ( V_39 , V_46 ) ;
}
}
