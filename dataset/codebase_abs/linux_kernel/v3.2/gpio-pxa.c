static inline void T_1 * F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , struct V_3 , V_4 ) -> V_5 ;
}
static inline struct V_3 * F_3 ( unsigned V_6 )
{
return & V_7 [ F_4 ( V_6 ) ] ;
}
static int F_5 ( struct V_1 * V_4 , unsigned V_8 )
{
void T_1 * V_9 = F_1 ( V_4 ) ;
T_2 V_10 , V_11 = 1 << V_8 ;
unsigned long V_12 ;
F_6 ( & V_13 , V_12 ) ;
V_10 = F_7 ( V_9 + V_14 ) ;
if ( F_8 ( V_4 -> V_9 + V_8 ) )
V_10 |= V_11 ;
else
V_10 &= ~ V_11 ;
F_9 ( V_10 , V_9 + V_14 ) ;
F_10 ( & V_13 , V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_4 ,
unsigned V_8 , int V_10 )
{
void T_1 * V_9 = F_1 ( V_4 ) ;
T_2 V_15 , V_11 = 1 << V_8 ;
unsigned long V_12 ;
F_9 ( V_11 , V_9 + ( V_10 ? V_16 : V_17 ) ) ;
F_6 ( & V_13 , V_12 ) ;
V_15 = F_7 ( V_9 + V_14 ) ;
if ( F_8 ( V_4 -> V_9 + V_8 ) )
V_15 &= ~ V_11 ;
else
V_15 |= V_11 ;
F_9 ( V_15 , V_9 + V_14 ) ;
F_10 ( & V_13 , V_12 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_4 , unsigned V_8 )
{
return F_7 ( F_1 ( V_4 ) + V_18 ) & ( 1 << V_8 ) ;
}
static void F_13 ( struct V_1 * V_4 , unsigned V_8 , int V_10 )
{
F_9 ( 1 << V_8 , F_1 ( V_4 ) +
( V_10 ? V_16 : V_17 ) ) ;
}
static int T_3 F_14 ( int V_19 )
{
int V_20 , V_6 , V_21 = F_4 ( V_19 ) + 1 ;
struct V_3 * V_22 ;
V_22 = F_15 ( V_21 * sizeof( struct V_3 ) , V_23 ) ;
if ( V_22 == NULL ) {
F_16 ( L_1 , V_24 ) ;
return - V_25 ;
}
for ( V_20 = 0 , V_6 = 0 ; V_20 < V_21 ; V_20 ++ , V_6 += 32 ) {
struct V_1 * V_2 = & V_22 [ V_20 ] . V_4 ;
sprintf ( V_22 [ V_20 ] . V_26 , L_2 , V_20 ) ;
V_22 [ V_20 ] . V_5 = F_17 ( V_20 ) ;
V_2 -> V_9 = V_6 ;
V_2 -> V_26 = V_22 [ V_20 ] . V_26 ;
V_2 -> V_27 = F_5 ;
V_2 -> V_28 = F_11 ;
V_2 -> V_29 = F_12 ;
V_2 -> V_30 = F_13 ;
V_2 -> V_31 = ( V_6 + 31 > V_19 ) ? ( V_19 - V_6 + 1 ) : 32 ;
F_18 ( V_2 ) ;
}
V_7 = V_22 ;
return 0 ;
}
static inline void F_19 ( struct V_3 * V_2 )
{
T_2 V_32 , V_33 ;
V_32 = F_7 ( V_2 -> V_5 + V_34 ) & ~ V_2 -> V_35 ;
V_33 = F_7 ( V_2 -> V_5 + V_36 ) & ~ V_2 -> V_35 ;
V_32 |= V_2 -> V_37 & V_2 -> V_35 ;
V_33 |= V_2 -> V_38 & V_2 -> V_35 ;
F_9 ( V_32 , V_2 -> V_5 + V_34 ) ;
F_9 ( V_33 , V_2 -> V_5 + V_36 ) ;
}
static int F_20 ( struct V_39 * V_40 , unsigned int type )
{
struct V_3 * V_2 ;
int V_6 = F_21 ( V_40 -> V_41 ) ;
unsigned long V_42 , V_11 = F_22 ( V_6 ) ;
V_2 = F_3 ( V_6 ) ;
if ( type == V_43 ) {
if ( ( V_2 -> V_37 | V_2 -> V_38 ) & F_22 ( V_6 ) )
return 0 ;
if ( F_23 ( V_6 ) )
return 0 ;
type = V_44 | V_45 ;
}
V_42 = F_7 ( V_2 -> V_5 + V_14 ) ;
if ( F_8 ( V_6 ) )
F_9 ( V_42 | V_11 , V_2 -> V_5 + V_14 ) ;
else
F_9 ( V_42 & ~ V_11 , V_2 -> V_5 + V_14 ) ;
if ( type & V_44 )
V_2 -> V_37 |= V_11 ;
else
V_2 -> V_37 &= ~ V_11 ;
if ( type & V_45 )
V_2 -> V_38 |= V_11 ;
else
V_2 -> V_38 &= ~ V_11 ;
F_19 ( V_2 ) ;
F_24 ( L_3 , V_24 , V_40 -> V_41 , V_6 ,
( ( type & V_44 ) ? L_4 : L_5 ) ,
( ( type & V_45 ) ? L_6 : L_5 ) ) ;
return 0 ;
}
static void F_25 ( unsigned int V_41 , struct V_46 * V_47 )
{
struct V_3 * V_2 ;
int V_48 , V_6 , V_49 , V_50 ;
unsigned long V_51 ;
do {
V_48 = 0 ;
F_26 (gpio, c) {
V_49 = V_2 -> V_4 . V_9 ;
V_51 = F_7 ( V_2 -> V_5 + V_52 ) ;
V_51 = V_51 & V_2 -> V_35 ;
F_9 ( V_51 , V_2 -> V_5 + V_52 ) ;
V_50 = F_27 ( & V_51 , V_53 ) ;
while ( V_50 < V_53 ) {
V_48 = 1 ;
F_28 ( F_29 ( V_49 + V_50 ) ) ;
V_50 = F_30 ( & V_51 , V_53 , V_50 + 1 ) ;
}
}
} while ( V_48 );
}
static void F_31 ( struct V_39 * V_40 )
{
int V_6 = F_21 ( V_40 -> V_41 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
F_9 ( F_22 ( V_6 ) , V_2 -> V_5 + V_52 ) ;
}
static void F_32 ( struct V_39 * V_40 )
{
int V_6 = F_21 ( V_40 -> V_41 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
T_2 V_32 , V_33 ;
V_2 -> V_35 &= ~ F_22 ( V_6 ) ;
V_32 = F_7 ( V_2 -> V_5 + V_34 ) & ~ F_22 ( V_6 ) ;
V_33 = F_7 ( V_2 -> V_5 + V_36 ) & ~ F_22 ( V_6 ) ;
F_9 ( V_32 , V_2 -> V_5 + V_34 ) ;
F_9 ( V_33 , V_2 -> V_5 + V_36 ) ;
}
static void F_33 ( struct V_39 * V_40 )
{
int V_6 = F_21 ( V_40 -> V_41 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
V_2 -> V_35 |= F_22 ( V_6 ) ;
F_19 ( V_2 ) ;
}
void T_3 F_34 ( int V_54 , int V_55 , int V_56 , T_4 V_57 )
{
struct V_3 * V_2 ;
int V_6 , V_41 ;
V_58 = V_56 ;
F_14 ( V_56 ) ;
F_26 (gpio, c) {
F_9 ( 0 , V_2 -> V_5 + V_36 ) ;
F_9 ( 0 , V_2 -> V_5 + V_34 ) ;
F_9 ( ~ 0 , V_2 -> V_5 + V_52 ) ;
}
for ( V_41 = F_29 ( V_55 ) ; V_41 <= F_29 ( V_56 ) ; V_41 ++ ) {
F_35 ( V_41 , & V_59 ,
V_60 ) ;
F_36 ( V_41 , V_61 | V_62 ) ;
}
F_37 ( V_54 , F_25 ) ;
V_59 . V_63 = V_57 ;
}
static int F_38 ( void )
{
struct V_3 * V_2 ;
int V_6 ;
F_26 (gpio, c) {
V_2 -> V_64 = F_7 ( V_2 -> V_5 + V_18 ) ;
V_2 -> V_65 = F_7 ( V_2 -> V_5 + V_14 ) ;
V_2 -> V_66 = F_7 ( V_2 -> V_5 + V_34 ) ;
V_2 -> V_67 = F_7 ( V_2 -> V_5 + V_36 ) ;
F_9 ( 0xffffffff , V_2 -> V_5 + V_52 ) ;
}
return 0 ;
}
static void F_39 ( void )
{
struct V_3 * V_2 ;
int V_6 ;
F_26 (gpio, c) {
F_9 ( V_2 -> V_64 , V_2 -> V_5 + V_16 ) ;
F_9 ( ~ V_2 -> V_64 , V_2 -> V_5 + V_17 ) ;
F_9 ( V_2 -> V_66 , V_2 -> V_5 + V_34 ) ;
F_9 ( V_2 -> V_67 , V_2 -> V_5 + V_36 ) ;
F_9 ( V_2 -> V_65 , V_2 -> V_5 + V_14 ) ;
}
}
