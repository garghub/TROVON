static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_4 )
{
unsigned V_5 = F_2 ( V_3 ) ;
unsigned V_6 ;
V_6 = F_3 ( V_2 -> V_7 . V_8 ) ;
if ( V_4 )
F_4 ( V_6 | V_5 , V_2 -> V_7 . V_8 ) ;
else
F_4 ( V_6 & ~ V_5 , V_2 -> V_7 . V_8 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_9 = 100 ;
unsigned V_10 , V_6 , V_11 , V_12 ;
do {
V_6 = F_3 ( V_2 -> V_7 . V_13 ) ;
V_10 = F_3 ( V_2 -> V_7 . V_14 ) ;
V_10 = ( V_10 & ~ V_2 -> V_15 ) |
( ~ V_6 & V_2 -> V_15 ) ;
F_4 ( V_10 , V_2 -> V_7 . V_14 ) ;
V_12 = F_3 ( V_2 -> V_7 . V_16 ) ;
V_11 = F_3 ( V_2 -> V_7 . V_13 ) ;
if ( ( ( V_6 ^ V_11 ) & V_2 -> V_15 & ~ V_12 ) == 0 )
return;
} while ( V_9 -- > 0 );
F_6 ( V_17 L_1
L_2 , V_6 , V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_3 )
{
unsigned V_18 = F_2 ( V_3 ) ;
#if V_19
V_2 -> V_20 |= F_3 ( V_2 -> V_7 . V_16 ) ;
V_2 -> V_20 &= ~ V_18 ;
#endif
F_4 ( V_18 , V_2 -> V_7 . V_21 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_22 * V_23 , unsigned V_3 )
{
struct V_1 * V_2 ;
unsigned long V_24 ;
V_2 = F_9 ( V_23 , struct V_1 , V_23 ) ;
F_10 ( & V_2 -> V_25 , V_24 ) ;
F_4 ( F_3 ( V_2 -> V_7 . V_26 ) & ~ F_2 ( V_3 ) , V_2 -> V_7 . V_26 ) ;
F_11 ( & V_2 -> V_25 , V_24 ) ;
return 0 ;
}
static int
F_12 ( struct V_22 * V_23 , unsigned V_3 , int V_27 )
{
struct V_1 * V_2 ;
unsigned long V_24 ;
V_2 = F_9 ( V_23 , struct V_1 , V_23 ) ;
F_10 ( & V_2 -> V_25 , V_24 ) ;
F_1 ( V_2 , V_3 , V_27 ) ;
F_4 ( F_3 ( V_2 -> V_7 . V_26 ) | F_2 ( V_3 ) , V_2 -> V_7 . V_26 ) ;
F_11 ( & V_2 -> V_25 , V_24 ) ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 , unsigned V_3 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( V_23 , struct V_1 , V_23 ) ;
return ( F_3 ( V_2 -> V_7 . V_13 ) & ( 1U << V_3 ) ) ? 1 : 0 ;
}
static void F_14 ( struct V_22 * V_23 , unsigned V_3 , int V_27 )
{
struct V_1 * V_2 ;
unsigned long V_24 ;
V_2 = F_9 ( V_23 , struct V_1 , V_23 ) ;
F_10 ( & V_2 -> V_25 , V_24 ) ;
F_1 ( V_2 , V_3 , V_27 ) ;
F_11 ( & V_2 -> V_25 , V_24 ) ;
}
static int F_15 ( struct V_22 * V_23 , unsigned V_3 )
{
return F_16 ( V_23 -> V_28 + V_3 ) ;
}
static int F_17 ( struct V_22 * V_23 , unsigned V_3 )
{
return F_18 ( V_23 -> V_28 + V_3 ) ;
}
static void F_19 ( struct V_22 * V_23 , unsigned V_3 )
{
F_20 ( V_23 -> V_28 + V_3 ) ;
}
static void F_21 ( struct V_29 * V_30 )
{
unsigned long V_24 ;
struct V_1 * V_2 = F_22 ( V_30 ) ;
F_10 ( & V_2 -> V_25 , V_24 ) ;
F_7 ( V_2 ,
V_30 -> V_31 - F_23 ( V_2 -> V_23 . V_28 ) ) ;
F_11 ( & V_2 -> V_25 , V_24 ) ;
}
static void F_24 ( struct V_29 * V_30 )
{
unsigned long V_24 ;
struct V_1 * V_2 = F_22 ( V_30 ) ;
unsigned V_3 = V_30 -> V_31 - F_23 ( V_2 -> V_23 . V_28 ) ;
F_10 ( & V_2 -> V_25 , V_24 ) ;
if ( ! ( F_3 ( V_2 -> V_7 . V_32 ) & F_2 ( V_3 ) ) )
F_7 ( V_2 , V_3 ) ;
V_2 -> V_33 [ 0 ] &= ~ F_2 ( V_3 ) ;
F_4 ( V_2 -> V_33 [ 0 ] , V_2 -> V_7 . V_34 ) ;
F_11 ( & V_2 -> V_25 , V_24 ) ;
}
static void F_25 ( struct V_29 * V_30 )
{
unsigned long V_24 ;
struct V_1 * V_2 = F_22 ( V_30 ) ;
unsigned V_3 = V_30 -> V_31 - F_23 ( V_2 -> V_23 . V_28 ) ;
F_10 ( & V_2 -> V_25 , V_24 ) ;
if ( ! ( F_3 ( V_2 -> V_7 . V_32 ) & F_2 ( V_3 ) ) )
F_7 ( V_2 , V_3 ) ;
V_2 -> V_33 [ 0 ] |= F_2 ( V_3 ) ;
F_4 ( V_2 -> V_33 [ 0 ] , V_2 -> V_7 . V_34 ) ;
F_11 ( & V_2 -> V_25 , V_24 ) ;
}
static int F_26 ( struct V_29 * V_30 , unsigned int V_4 )
{
unsigned long V_24 ;
struct V_1 * V_2 = F_22 ( V_30 ) ;
unsigned V_3 = V_30 -> V_31 - F_23 ( V_2 -> V_23 . V_28 ) ;
F_10 ( & V_2 -> V_25 , V_24 ) ;
if ( V_4 )
V_2 -> V_33 [ 1 ] |= F_2 ( V_3 ) ;
else
V_2 -> V_33 [ 1 ] &= ~ F_2 ( V_3 ) ;
F_11 ( & V_2 -> V_25 , V_24 ) ;
return 0 ;
}
static int F_27 ( struct V_29 * V_30 , unsigned int V_35 )
{
unsigned long V_24 ;
struct V_1 * V_2 = F_22 ( V_30 ) ;
unsigned V_3 = V_30 -> V_31 - F_23 ( V_2 -> V_23 . V_28 ) ;
unsigned V_6 , V_5 = F_2 ( V_3 ) ;
F_10 ( & V_2 -> V_25 , V_24 ) ;
V_6 = F_3 ( V_2 -> V_7 . V_32 ) ;
if ( V_35 & V_36 ) {
F_4 ( V_6 | V_5 , V_2 -> V_7 . V_32 ) ;
F_28 ( V_30 -> V_31 , V_37 ) ;
} else {
F_4 ( V_6 & ~ V_5 , V_2 -> V_7 . V_32 ) ;
F_28 ( V_30 -> V_31 , V_38 ) ;
}
if ( ( V_35 & V_36 ) == V_36 ) {
V_2 -> V_15 |= V_5 ;
F_5 ( V_2 ) ;
} else {
V_2 -> V_15 &= ~ V_5 ;
V_6 = F_3 ( V_2 -> V_7 . V_14 ) ;
if ( V_35 & ( V_39 | V_40 ) )
F_4 ( V_6 | V_5 , V_2 -> V_7 . V_14 ) ;
else
F_4 ( V_6 & ~ V_5 , V_2 -> V_7 . V_14 ) ;
}
F_11 ( & V_2 -> V_25 , V_24 ) ;
return 0 ;
}
static void F_29 ( unsigned int V_31 , struct V_41 * V_42 )
{
int V_43 , V_44 , V_5 ;
unsigned V_6 ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
struct V_1 * V_2 = & V_46 [ V_43 ] ;
V_6 = F_3 ( V_2 -> V_7 . V_16 ) ;
V_6 &= V_2 -> V_33 [ 0 ] ;
while ( V_6 ) {
V_5 = V_6 & - V_6 ;
V_44 = F_30 ( V_5 ) - 1 ;
V_6 &= ~ V_5 ;
F_31 ( V_47 +
V_2 -> V_23 . V_28 + V_44 ) ;
}
}
V_42 -> V_29 . V_23 -> V_48 ( & V_42 -> V_29 ) ;
}
static int T_1 F_32 ( void )
{
int V_43 , V_44 = 0 ;
if ( F_33 () ) {
V_46 = V_49 ;
V_45 = F_34 ( V_49 ) ;
} else if ( F_35 () ) {
V_46 = V_50 ;
V_45 = F_34 ( V_50 ) ;
} else if ( F_36 () ) {
V_46 = V_51 ;
V_45 = F_34 ( V_51 ) ;
} else {
return 0 ;
}
for ( V_43 = V_47 ; V_43 < V_47 + V_52 ; V_43 ++ ) {
if ( V_43 - V_47 >=
V_46 [ V_44 ] . V_23 . V_28 +
V_46 [ V_44 ] . V_23 . V_53 )
V_44 ++ ;
F_37 ( V_43 , & V_46 [ V_44 ] ) ;
F_38 ( V_43 , & V_54 ,
V_37 ) ;
F_39 ( V_43 , V_55 ) ;
}
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
F_40 ( & V_46 [ V_43 ] . V_25 ) ;
F_4 ( 0 , V_46 [ V_43 ] . V_7 . V_34 ) ;
F_41 ( & V_46 [ V_43 ] . V_23 ) ;
}
F_42 ( V_56 , F_29 ) ;
F_42 ( V_57 , F_29 ) ;
F_43 ( V_56 , 1 ) ;
F_43 ( V_57 , 2 ) ;
return 0 ;
}
