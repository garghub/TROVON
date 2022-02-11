static inline unsigned int F_1 ( unsigned V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( unsigned long V_3 , unsigned V_1 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
F_3 ( V_5 -> V_6 , V_7 ) ;
}
static void F_6 ( struct V_4 * V_5 )
{
F_3 ( 1 , V_8 ) ;
F_3 ( V_5 -> V_6 , V_9 ) ;
F_3 ( 1 , V_10 ) ;
}
static void F_7 ( struct V_4 * V_5 )
{
F_3 ( V_5 -> V_6 , V_11 ) ;
}
static int F_8 ( struct V_4 * V_5 , unsigned int V_12 )
{
unsigned V_13 = F_9 ( V_5 -> V_6 ) ;
unsigned V_14 = F_10 ( V_5 -> V_6 ) ;
unsigned V_15 = F_1 ( F_11 ( V_13 ) ) ;
unsigned type = F_1 ( F_12 ( V_13 ) ) ;
switch ( V_12 ) {
case V_16 :
V_15 |= V_14 ;
type |= V_14 ;
break;
case V_17 :
V_15 &= ~ V_14 ;
type |= V_14 ;
break;
case V_18 :
V_15 |= V_14 ;
type &= ~ V_14 ;
break;
case V_19 :
V_15 &= ~ V_14 ;
type &= ~ V_14 ;
break;
default:
return - V_20 ;
}
F_3 ( V_15 , F_11 ( V_13 ) ) ;
F_3 ( type , F_12 ( V_13 ) ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 , unsigned int V_21 )
{
return 0 ;
}
void T_1 F_14 ( void )
{
unsigned long V_22 = V_23 . V_24 ;
T_2 * V_25 = V_23 . V_26 ;
T_3 * V_27 = V_23 . V_28 ;
unsigned V_29 = F_15 ( V_22 ) ;
int V_30 ;
V_31 = V_32 ;
V_2 = F_16 ( V_23 . V_33 , V_34 ) ;
if ( F_17 ( ! V_2 ) )
return;
F_3 ( 0 , V_35 ) ;
F_3 ( 0 , F_18 ( 0 ) ) ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ )
F_3 ( ~ 0 , F_19 ( V_30 ) ) ;
F_3 ( 0 , V_36 ) ;
F_3 ( 0 , V_37 ) ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ )
F_3 ( ~ 0 , F_20 ( V_30 ) ) ;
F_3 ( 1 , V_10 ) ;
V_29 = ( V_22 + 3 ) >> 2 ;
if ( V_25 ) {
unsigned V_38 , V_39 ;
T_3 V_40 ;
for ( V_39 = V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
for ( V_40 = V_38 = 0 ; V_38 < 4 ; V_38 ++ , V_39 ++ ) {
V_40 >>= 8 ;
if ( V_39 < V_22 )
V_40 |= V_25 [ V_39 ] << 24 ;
}
F_3 ( V_40 , F_21 ( V_30 ) ) ;
}
} else {
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ )
F_3 ( 0x0f0f0f0f , F_21 ( V_30 ) ) ;
}
if ( V_27 )
for ( V_30 = 0 ; V_27 [ V_30 ] != - 1 ; V_30 ++ )
F_3 ( V_27 [ V_30 ] , F_22 ( V_30 ) ) ;
for ( V_30 = 0 ; V_30 < V_22 ; V_30 ++ ) {
F_23 ( V_30 , & V_41 ) ;
F_24 ( V_30 , V_42 | V_43 ) ;
F_25 ( V_30 , V_44 ) ;
}
F_3 ( 1 , V_35 ) ;
}
