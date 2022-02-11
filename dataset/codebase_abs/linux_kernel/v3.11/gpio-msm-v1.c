static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
enum V_4 V_5 )
{
F_2 ( V_3 , V_2 -> V_6 + V_2 -> V_7 [ V_5 ] ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , enum V_4 V_5 )
{
return F_4 ( V_2 -> V_6 + V_2 -> V_7 [ V_5 ] ) ;
}
static int F_5 ( struct V_1 * V_8 ,
unsigned V_9 , unsigned V_10 )
{
unsigned V_11 = F_6 ( V_9 ) ;
unsigned V_3 ;
V_3 = F_3 ( V_8 , V_12 ) ;
if ( V_10 )
F_1 ( V_8 , V_3 | V_11 , V_12 ) ;
else
F_1 ( V_8 , V_3 & ~ V_11 , V_12 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_8 )
{
int V_13 = 100 ;
unsigned V_14 , V_3 , V_15 , V_16 ;
do {
V_3 = F_3 ( V_8 , V_17 ) ;
V_14 = F_3 ( V_8 , V_18 ) ;
V_14 = ( V_14 & ~ V_8 -> V_19 ) |
( ~ V_3 & V_8 -> V_19 ) ;
F_1 ( V_8 , V_14 , V_18 ) ;
V_16 = F_3 ( V_8 , V_20 ) ;
V_15 = F_3 ( V_8 , V_17 ) ;
if ( ( ( V_3 ^ V_15 ) & V_8 -> V_19 & ~ V_16 ) == 0 )
return;
} while ( V_13 -- > 0 );
F_8 ( V_21 L_1
L_2 , V_3 , V_15 ) ;
}
static int F_9 ( struct V_1 * V_8 ,
unsigned V_9 )
{
unsigned V_22 = F_6 ( V_9 ) ;
#if V_23
V_8 -> V_24 |=
F_3 ( V_8 , V_20 ) ;
V_8 -> V_24 &= ~ V_22 ;
#endif
F_1 ( V_8 , V_22 , V_25 ) ;
F_7 ( V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_26 * V_2 , unsigned V_9 )
{
struct V_1 * V_8 ;
unsigned long V_27 ;
T_1 V_3 ;
V_8 = F_11 ( V_2 , struct V_1 , V_2 ) ;
F_12 ( & V_8 -> V_28 , V_27 ) ;
V_3 = F_3 ( V_8 , V_29 ) & ~ F_6 ( V_9 ) ;
F_1 ( V_8 , V_3 , V_29 ) ;
F_13 ( & V_8 -> V_28 , V_27 ) ;
return 0 ;
}
static int
F_14 ( struct V_26 * V_2 , unsigned V_9 , int V_30 )
{
struct V_1 * V_8 ;
unsigned long V_27 ;
T_1 V_3 ;
V_8 = F_11 ( V_2 , struct V_1 , V_2 ) ;
F_12 ( & V_8 -> V_28 , V_27 ) ;
F_5 ( V_8 , V_9 , V_30 ) ;
V_3 = F_3 ( V_8 , V_29 ) | F_6 ( V_9 ) ;
F_1 ( V_8 , V_3 , V_29 ) ;
F_13 ( & V_8 -> V_28 , V_27 ) ;
return 0 ;
}
static int F_15 ( struct V_26 * V_2 , unsigned V_9 )
{
struct V_1 * V_8 ;
V_8 = F_11 ( V_2 , struct V_1 , V_2 ) ;
return ( F_3 ( V_8 , V_17 ) & ( 1U << V_9 ) ) ? 1 : 0 ;
}
static void F_16 ( struct V_26 * V_2 , unsigned V_9 , int V_30 )
{
struct V_1 * V_8 ;
unsigned long V_27 ;
V_8 = F_11 ( V_2 , struct V_1 , V_2 ) ;
F_12 ( & V_8 -> V_28 , V_27 ) ;
F_5 ( V_8 , V_9 , V_30 ) ;
F_13 ( & V_8 -> V_28 , V_27 ) ;
}
static int F_17 ( struct V_26 * V_2 , unsigned V_9 )
{
return F_18 ( V_2 -> V_6 + V_9 ) ;
}
static int F_19 ( struct V_26 * V_2 , unsigned V_9 )
{
return F_20 ( V_2 -> V_6 + V_9 ) ;
}
static void F_21 ( struct V_26 * V_2 , unsigned V_9 )
{
F_22 ( V_2 -> V_6 + V_9 ) ;
}
static void F_23 ( struct V_31 * V_32 )
{
unsigned long V_27 ;
struct V_1 * V_8 = F_24 ( V_32 ) ;
F_12 ( & V_8 -> V_28 , V_27 ) ;
F_9 ( V_8 ,
V_32 -> V_33 - F_25 ( V_8 -> V_2 . V_6 ) ) ;
F_13 ( & V_8 -> V_28 , V_27 ) ;
}
static void F_26 ( struct V_31 * V_32 )
{
unsigned long V_27 ;
struct V_1 * V_8 = F_24 ( V_32 ) ;
unsigned V_9 = V_32 -> V_33 - F_25 ( V_8 -> V_2 . V_6 ) ;
F_12 ( & V_8 -> V_28 , V_27 ) ;
if ( ! ( F_3 ( V_8 , V_34 ) & F_6 ( V_9 ) ) )
F_9 ( V_8 , V_9 ) ;
V_8 -> V_35 [ 0 ] &= ~ F_6 ( V_9 ) ;
F_1 ( V_8 , V_8 -> V_35 [ 0 ] , V_36 ) ;
F_13 ( & V_8 -> V_28 , V_27 ) ;
}
static void F_27 ( struct V_31 * V_32 )
{
unsigned long V_27 ;
struct V_1 * V_8 = F_24 ( V_32 ) ;
unsigned V_9 = V_32 -> V_33 - F_25 ( V_8 -> V_2 . V_6 ) ;
F_12 ( & V_8 -> V_28 , V_27 ) ;
if ( ! ( F_3 ( V_8 , V_34 ) & F_6 ( V_9 ) ) )
F_9 ( V_8 , V_9 ) ;
V_8 -> V_35 [ 0 ] |= F_6 ( V_9 ) ;
F_1 ( V_8 , V_8 -> V_35 [ 0 ] , V_36 ) ;
F_13 ( & V_8 -> V_28 , V_27 ) ;
}
static int F_28 ( struct V_31 * V_32 , unsigned int V_10 )
{
unsigned long V_27 ;
struct V_1 * V_8 = F_24 ( V_32 ) ;
unsigned V_9 = V_32 -> V_33 - F_25 ( V_8 -> V_2 . V_6 ) ;
F_12 ( & V_8 -> V_28 , V_27 ) ;
if ( V_10 )
V_8 -> V_35 [ 1 ] |= F_6 ( V_9 ) ;
else
V_8 -> V_35 [ 1 ] &= ~ F_6 ( V_9 ) ;
F_13 ( & V_8 -> V_28 , V_27 ) ;
return 0 ;
}
static int F_29 ( struct V_31 * V_32 , unsigned int V_37 )
{
unsigned long V_27 ;
struct V_1 * V_8 = F_24 ( V_32 ) ;
unsigned V_9 = V_32 -> V_33 - F_25 ( V_8 -> V_2 . V_6 ) ;
unsigned V_3 , V_11 = F_6 ( V_9 ) ;
F_12 ( & V_8 -> V_28 , V_27 ) ;
V_3 = F_3 ( V_8 , V_34 ) ;
if ( V_37 & V_38 ) {
F_1 ( V_8 , V_3 | V_11 , V_34 ) ;
F_30 ( V_32 -> V_33 , V_39 ) ;
} else {
F_1 ( V_8 , V_3 & ~ V_11 , V_34 ) ;
F_30 ( V_32 -> V_33 , V_40 ) ;
}
if ( ( V_37 & V_38 ) == V_38 ) {
V_8 -> V_19 |= V_11 ;
F_7 ( V_8 ) ;
} else {
V_8 -> V_19 &= ~ V_11 ;
V_3 = F_3 ( V_8 , V_18 ) ;
if ( V_37 & ( V_41 | V_42 ) )
V_3 |= V_11 ;
else
V_3 &= ~ V_11 ;
F_1 ( V_8 , V_3 , V_18 ) ;
}
F_13 ( & V_8 -> V_28 , V_27 ) ;
return 0 ;
}
static void F_31 ( unsigned int V_33 , struct V_43 * V_44 )
{
int V_45 , V_46 , V_11 ;
unsigned V_3 ;
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ ) {
struct V_1 * V_8 = & V_48 [ V_45 ] ;
V_3 = F_3 ( V_8 , V_20 ) ;
V_3 &= V_8 -> V_35 [ 0 ] ;
while ( V_3 ) {
V_11 = V_3 & - V_3 ;
V_46 = F_32 ( V_11 ) - 1 ;
V_3 &= ~ V_11 ;
F_33 ( V_49 +
V_8 -> V_2 . V_6 + V_46 ) ;
}
}
V_44 -> V_31 . V_2 -> V_50 ( & V_44 -> V_31 ) ;
}
static int F_34 ( struct V_51 * V_52 )
{
int V_45 , V_46 = 0 ;
const struct V_53 * V_54 = F_35 ( V_52 ) ;
struct V_55 * V_56 ;
int V_57 , V_58 ;
struct V_59 * V_60 ;
void T_2 * V_61 , T_2 * V_62 ;
V_56 = (struct V_55 * ) V_54 -> V_63 ;
V_48 = V_56 -> V_64 ;
V_47 = V_56 -> V_65 ;
V_57 = F_36 ( V_52 , 0 ) ;
if ( V_57 < 0 )
return V_57 ;
V_58 = F_36 ( V_52 , 1 ) ;
if ( V_58 < 0 )
return V_58 ;
V_60 = F_37 ( V_52 , V_66 , 0 ) ;
V_61 = F_38 ( & V_52 -> V_67 , V_60 ) ;
if ( F_39 ( V_61 ) )
return F_40 ( V_61 ) ;
V_60 = F_37 ( V_52 , V_66 , 1 ) ;
V_62 = F_38 ( & V_52 -> V_67 , V_60 ) ;
if ( F_39 ( V_62 ) )
return F_40 ( V_62 ) ;
for ( V_45 = V_49 ; V_45 < V_49 + V_68 ; V_45 ++ ) {
if ( V_45 - V_49 >=
V_48 [ V_46 ] . V_2 . V_6 +
V_48 [ V_46 ] . V_2 . V_69 )
V_46 ++ ;
F_41 ( V_45 , & V_48 [ V_46 ] ) ;
F_42 ( V_45 , & V_70 ,
V_39 ) ;
F_43 ( V_45 , V_71 ) ;
}
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ ) {
if ( V_45 == 1 )
V_48 [ V_45 ] . V_6 = V_62 ;
else
V_48 [ V_45 ] . V_6 = V_61 ;
F_44 ( & V_48 [ V_45 ] . V_28 ) ;
F_1 ( & V_48 [ V_45 ] , 0 , V_36 ) ;
F_45 ( & V_48 [ V_45 ] . V_2 ) ;
}
F_46 ( V_57 , F_31 ) ;
F_46 ( V_58 , F_31 ) ;
F_47 ( V_57 , 1 ) ;
F_47 ( V_58 , 2 ) ;
return 0 ;
}
static int T_3 F_48 ( void )
{
return F_49 ( & V_72 ) ;
}
