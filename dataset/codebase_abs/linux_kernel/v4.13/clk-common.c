static inline unsigned long F_1 ( unsigned V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( T_1 V_3 , unsigned V_1 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static unsigned long F_5 ( struct V_4 * V_5 ,
unsigned long V_6 )
{
unsigned long V_7 = V_6 ;
struct V_8 * V_9 = F_6 ( V_5 ) ;
T_1 V_10 = V_9 -> V_11 + V_12 -
V_13 ;
if ( F_1 ( V_10 ) & F_7 ( 2 ) ) {
return V_7 ;
} else {
T_1 V_14 = F_1 ( V_9 -> V_11 ) ;
T_1 V_15 = ( V_14 & ( F_7 ( 13 ) - 1 ) ) + 1 ;
T_1 V_16 = ( ( V_14 >> 13 ) & ( F_7 ( 6 ) - 1 ) ) + 1 ;
T_1 V_17 = ( ( V_14 >> 19 ) & ( F_7 ( 4 ) - 1 ) ) + 1 ;
F_8 ( V_7 % V_18 ) ;
return V_7 / V_18 * V_15 / V_16 / V_17 * V_18 ;
}
}
static long F_9 ( struct V_4 * V_5 , unsigned long V_19 ,
unsigned long * V_6 )
{
unsigned long V_7 , V_15 , V_16 , V_17 ;
T_2 V_20 ;
V_19 = V_19 - V_19 % V_18 ;
V_15 = V_19 / V_18 ;
if ( V_15 > F_7 ( 13 ) )
V_15 = F_7 ( 13 ) ;
if ( V_15 < 1 )
V_15 = 1 ;
V_7 = * V_6 ;
V_16 = V_7 / V_18 ;
if ( V_16 > F_7 ( 6 ) )
V_16 = F_7 ( 6 ) ;
V_17 = 1 ;
V_20 = ( T_2 ) V_7 * V_15 ;
F_10 ( V_20 , V_16 * V_17 ) ;
return ( long ) V_20 ;
}
static int F_11 ( struct V_4 * V_5 , unsigned long V_19 ,
unsigned long V_6 )
{
struct V_8 * V_9 = F_6 ( V_5 ) ;
unsigned long V_7 , V_15 , V_16 , V_17 , V_1 ;
V_15 = V_19 / V_18 ;
if ( F_12 ( ( V_19 % V_18 ) || V_15 > F_7 ( 13 ) || V_15 < 1 ) )
return - V_21 ;
V_7 = V_6 ;
F_13 ( V_7 < V_18 ) ;
V_16 = V_7 / V_18 ;
F_13 ( ( V_7 % V_18 ) || V_16 > F_7 ( 6 ) ) ;
V_17 = 1 ;
V_1 = ( V_15 - 1 ) | ( ( V_16 - 1 ) << 13 ) | ( ( V_17 - 1 ) << 19 ) ;
F_3 ( V_1 , V_9 -> V_11 ) ;
V_1 = V_9 -> V_11 + V_22 - V_13 ;
F_3 ( ( V_15 >> 1 ) - 1 , V_1 ) ;
V_1 = V_9 -> V_11 + V_12 - V_13 ;
while ( ! ( F_1 ( V_1 ) & F_7 ( 6 ) ) )
F_14 () ;
return 0 ;
}
static long F_15 ( struct V_4 * V_5 , unsigned long V_19 ,
unsigned long * V_6 )
{
struct V_4 * V_23 = F_16 ( V_5 ) ;
struct V_4 * V_24 = F_16 ( V_23 ) ;
unsigned long V_25 = F_17 ( V_24 ) ;
return F_9 ( V_23 , V_19 , & V_25 ) ;
}
static unsigned long F_18 ( struct V_4 * V_5 ,
unsigned long V_6 )
{
struct V_4 * V_23 = F_16 ( V_5 ) ;
return F_17 ( V_23 ) ;
}
static int F_19 ( struct V_4 * V_5 )
{
T_1 V_1 = F_2 ( V_26 + V_27 ) ;
V_1 &= ~ ( V_28 | V_29 ) ;
F_4 ( V_1 , V_26 + V_27 ) ;
while ( ! ( F_2 ( V_26 + V_27 ) &
V_30 ) )
F_14 () ;
return 0 ;
}
static void F_20 ( struct V_4 * V_9 )
{
T_1 V_1 = F_2 ( V_26 + V_27 ) ;
V_1 |= ( V_28 | V_29 ) ;
F_4 ( V_1 , V_26 + V_27 ) ;
}
static unsigned long F_21 ( struct V_4 * V_5 , unsigned long V_6 )
{
T_1 V_1 = F_2 ( V_26 + V_27 ) ;
return ( V_1 & V_29 ) ? V_6 : 48 * V_18 ;
}
static T_3 F_22 ( struct V_4 * V_5 )
{
struct V_31 * V_9 = F_23 ( V_5 ) ;
T_1 V_32 = F_1 ( V_9 -> V_11 ) ;
if ( strcmp ( V_5 -> V_33 -> V_34 , L_1 ) == 0 )
return 4 ;
F_8 ( ( V_32 & ( F_7 ( 3 ) - 1 ) ) > 4 ) ;
return V_32 & ( F_7 ( 3 ) - 1 ) ;
}
static int F_24 ( struct V_4 * V_5 , T_3 V_35 )
{
struct V_31 * V_9 = F_23 ( V_5 ) ;
T_1 V_32 = F_1 ( V_9 -> V_11 ) ;
if ( strcmp ( V_5 -> V_33 -> V_34 , L_1 ) == 0 )
return - V_21 ;
V_32 &= ~ ( F_7 ( 3 ) - 1 ) ;
F_3 ( V_32 | V_35 , V_9 -> V_11 ) ;
while ( F_1 ( V_9 -> V_11 ) & F_7 ( 3 ) )
F_14 () ;
return 0 ;
}
static unsigned long F_25 ( struct V_4 * V_5 ,
unsigned long V_6 )
{
unsigned long V_7 = V_6 ;
struct V_31 * V_9 = F_23 ( V_5 ) ;
T_1 V_32 = F_1 ( V_9 -> V_11 ) ;
if ( V_32 & F_7 ( 24 ) ) {
return V_7 ;
} else {
T_1 V_36 = ( V_32 >> 16 ) & ( F_7 ( 4 ) - 1 ) ;
T_1 V_37 = ( V_32 >> 20 ) & ( F_7 ( 4 ) - 1 ) ;
return V_7 / ( V_36 + V_37 + 2 ) ;
}
}
static long F_26 ( struct V_4 * V_5 , unsigned long V_19 ,
unsigned long * V_6 )
{
unsigned long V_7 ;
unsigned V_38 , V_36 , V_37 ;
unsigned V_39 = ( strcmp ( V_5 -> V_33 -> V_34 , L_2 ) == 0 ) ? 3 : 4 ;
V_7 = * V_6 ;
V_38 = V_7 / V_19 ;
if ( V_38 < 2 )
V_38 = 2 ;
if ( V_38 > F_7 ( V_39 + 1 ) )
V_38 = F_7 ( V_39 + 1 ) ;
V_36 = ( V_38 >> 1 ) - 1 ;
V_37 = V_38 - V_36 - 2 ;
return V_7 / ( V_36 + V_37 + 2 ) ;
}
static int F_27 ( struct V_4 * V_5 , unsigned long V_19 ,
unsigned long V_6 )
{
struct V_31 * V_9 = F_23 ( V_5 ) ;
unsigned long V_7 ;
unsigned V_38 , V_36 , V_37 , V_1 ;
unsigned V_39 = ( strcmp ( V_5 -> V_33 -> V_34 , L_2 ) == 0 ) ? 3 : 4 ;
V_7 = V_6 ;
V_38 = V_7 / V_19 ;
if ( F_12 ( V_38 < 2 || V_38 > F_7 ( V_39 + 1 ) ) )
return - V_21 ;
F_8 ( V_7 % V_19 ) ;
V_36 = ( V_38 >> 1 ) - 1 ;
V_37 = V_38 - V_36 - 2 ;
V_1 = F_1 ( V_9 -> V_11 ) ;
V_1 &= ~ ( ( ( F_7 ( V_39 ) - 1 ) << 16 ) | ( ( F_7 ( V_39 ) - 1 ) << 20 ) ) ;
V_1 |= ( V_36 << 16 ) | ( V_37 << 20 ) | F_7 ( 25 ) ;
F_3 ( V_1 , V_9 -> V_11 ) ;
while ( F_1 ( V_9 -> V_11 ) & F_7 ( 25 ) )
F_14 () ;
return 0 ;
}
static int F_28 ( struct V_4 * V_5 , unsigned long V_19 ,
unsigned long V_6 )
{
int V_40 , V_41 ;
struct V_9 * V_42 ;
if ( V_19 == F_29 ( V_43 . V_5 . V_9 ) ) {
V_40 = F_30 ( V_5 -> V_9 , V_43 . V_5 . V_9 ) ;
return V_40 ;
}
if ( V_19 == F_29 ( V_44 . V_5 . V_9 ) ) {
V_40 = F_30 ( V_5 -> V_9 , V_44 . V_5 . V_9 ) ;
return V_40 ;
}
if ( V_19 == F_29 ( V_45 . V_5 . V_9 ) ) {
V_40 = F_30 ( V_5 -> V_9 , V_45 . V_5 . V_9 ) ;
return V_40 ;
}
V_42 = F_31 ( V_5 -> V_9 ) ;
if ( V_42 == V_43 . V_5 . V_9 ) {
V_40 = F_30 ( V_5 -> V_9 , V_44 . V_5 . V_9 ) ;
F_13 ( V_40 ) ;
}
V_41 = F_32 ( V_43 . V_5 . V_9 , V_19 ) ;
V_40 = F_30 ( V_5 -> V_9 , V_43 . V_5 . V_9 ) ;
return V_41 ? V_41 : V_40 ;
}
static int F_33 ( struct V_4 * V_5 )
{
T_1 V_1 ;
int V_46 ;
struct V_47 * V_9 = F_34 ( V_5 ) ;
V_46 = V_9 -> V_48 % 32 ;
V_1 = V_9 -> V_48 / 32 ;
V_1 = V_49 + V_1 * sizeof( V_1 ) ;
return ! ! ( F_1 ( V_1 ) & F_7 ( V_46 ) ) ;
}
static int F_35 ( struct V_4 * V_5 )
{
T_1 V_3 , V_1 ;
int V_46 ;
struct V_47 * V_9 = F_34 ( V_5 ) ;
F_13 ( V_9 -> V_48 < 0 || V_9 -> V_48 > 63 ) ;
V_46 = V_9 -> V_48 % 32 ;
V_1 = V_9 -> V_48 / 32 ;
V_1 = V_49 + V_1 * sizeof( V_1 ) ;
V_3 = F_1 ( V_1 ) | F_7 ( V_46 ) ;
F_3 ( V_3 , V_1 ) ;
return 0 ;
}
static void F_36 ( struct V_4 * V_5 )
{
T_1 V_3 , V_1 ;
int V_46 ;
struct V_47 * V_9 = F_34 ( V_5 ) ;
F_13 ( V_9 -> V_48 < 0 || V_9 -> V_48 > 63 ) ;
V_46 = V_9 -> V_48 % 32 ;
V_1 = V_9 -> V_48 / 32 ;
V_1 = V_49 + V_1 * sizeof( V_1 ) ;
V_3 = F_1 ( V_1 ) & ~ F_7 ( V_46 ) ;
F_3 ( V_3 , V_1 ) ;
}
