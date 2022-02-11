static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 , V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_2 V_3 ,
T_1 V_5 )
{
F_4 ( V_2 -> V_4 , V_3 , V_5 ) ;
}
static inline unsigned int F_5 ( T_3 V_6 )
{
return ( V_6 * 9000 / V_7 * 110 / 100 ) + 1 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_8 )
{
unsigned long V_9 ;
T_1 V_10 ;
V_9 = V_11 + V_12 * V_13 / 1000 ;
do {
V_10 = F_1 ( V_2 , V_14 ) ;
if ( ! ( V_10 & V_15 ) )
break;
F_7 ( 5 ) ;
} while ( ! F_8 ( V_11 , V_9 ) );
if ( V_10 & V_15 )
goto V_16;
V_9 = V_11 + V_8 * V_13 / 1000 ;
do {
V_10 = F_1 ( V_2 , V_17 ) ;
if ( V_10 & V_18 ) {
F_3 ( V_2 , V_17 , 0 ) ;
return 0 ;
}
F_9 () ;
F_7 ( 100 ) ;
} while ( ! F_8 ( V_11 , V_9 ) );
V_16:
F_3 ( V_2 , V_17 , 0 ) ;
F_10 ( L_1 ) ;
return - V_19 ;
}
static void F_11 ( struct V_1 * V_2 , T_4 * V_20 ,
T_3 V_6 , bool V_21 )
{
T_1 V_10 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_6 ; V_22 ++ ) {
F_3 ( V_2 , V_23 + 4 * ( V_22 * 2 ) ,
( unsigned int ) V_20 [ V_22 ] ) ;
}
for ( V_22 = 0 ; V_22 < V_6 ; V_22 ++ ) {
V_10 = V_24 | V_25 |
V_26 ;
if ( ! V_21 && V_22 == V_6 - 1 )
V_10 &= ~ V_24 ;
V_10 &= ~ 0x1 ;
F_3 ( V_2 , V_27 + 4 * V_22 , V_10 ) ;
}
F_3 ( V_2 , V_28 , 0 ) ;
F_3 ( V_2 , V_29 , V_6 - 1 ) ;
if ( V_21 )
F_3 ( V_2 , V_30 , 1 ) ;
V_10 = F_1 ( V_2 , V_14 ) ;
V_10 |= V_15 ;
if ( V_21 )
V_10 |= V_31 ;
F_3 ( V_2 , V_14 , V_10 ) ;
F_6 ( V_2 , F_5 ( V_6 ) ) ;
if ( ! V_21 )
F_3 ( V_2 , V_30 , 0 ) ;
V_2 -> V_32 = V_6 ;
}
static void F_12 ( struct V_1 * V_2 , T_4 * V_33 ,
T_3 V_6 , bool V_21 )
{
T_1 V_10 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_32 + V_6 ; V_22 ++ ) {
V_10 = V_24 | V_25 |
V_26 ;
if ( ! V_21 && V_22 == V_2 -> V_32 + V_6 - 1 )
V_10 &= ~ V_24 ;
V_10 &= ~ 0x1 ;
F_3 ( V_2 , V_27 + 4 * V_22 , V_10 ) ;
}
F_3 ( V_2 , V_28 , 0 ) ;
F_3 ( V_2 , V_29 ,
V_2 -> V_32 + V_6 - 1 ) ;
if ( V_21 )
F_3 ( V_2 , V_30 , 1 ) ;
V_10 = F_1 ( V_2 , V_14 ) ;
V_10 |= V_15 ;
if ( V_21 )
V_10 |= V_31 ;
F_3 ( V_2 , V_14 , V_10 ) ;
F_6 ( V_2 , F_5 ( V_6 ) ) ;
if ( ! V_21 )
F_3 ( V_2 , V_30 , 0 ) ;
for ( V_22 = 0 ; V_22 < V_6 ; ++ V_22 ) {
int V_3 = V_2 -> V_32 + V_22 ;
V_33 [ V_22 ] = ( T_4 ) F_1 ( V_2 , V_34 + 4 * ( 1 + V_3 * 2 ) ) ;
}
V_2 -> V_32 = 0 ;
}
static int F_13 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = F_14 ( V_36 ) ;
T_4 * V_41 ;
T_3 V_42 ;
if ( V_40 -> V_43 ) {
V_41 = ( T_4 * ) V_40 -> V_43 ;
V_42 = V_40 -> V_6 ;
while ( V_42 ) {
T_3 V_44 = F_15 ( T_3 , 16 , V_42 ) ;
bool V_21 = V_42 - V_44 > 0 ;
F_11 ( V_2 , V_41 , V_44 , V_21 ) ;
V_42 -= V_44 ;
V_41 += V_44 ;
}
}
if ( V_40 -> V_45 ) {
V_41 = ( T_4 * ) V_40 -> V_45 ;
V_42 = V_40 -> V_6 ;
while ( V_42 ) {
T_3 V_46 = F_15 ( T_3 , 16 - V_2 -> V_32 ,
V_42 ) ;
bool V_21 = V_42 - V_46 > 0 ;
F_12 ( V_2 , V_41 , V_46 , V_21 ) ;
V_42 -= V_46 ;
V_41 += V_46 ;
}
}
return 0 ;
}
static int F_16 ( struct V_47 * V_4 )
{
struct V_1 * V_2 ;
struct V_35 * V_36 ;
int V_48 ;
if ( V_4 -> V_49 -> V_50 . V_4 -> V_51 . V_52 != 42 ) {
F_10 ( L_2 ) ;
return - V_53 ;
}
V_36 = F_17 ( & V_4 -> V_54 , sizeof( * V_2 ) ) ;
if ( ! V_36 )
return - V_55 ;
V_2 = F_14 ( V_36 ) ;
V_2 -> V_36 = V_36 ;
V_2 -> V_4 = V_4 ;
V_36 -> V_56 = F_13 ;
F_18 ( V_4 , V_2 ) ;
V_48 = F_19 ( & V_4 -> V_54 , V_36 ) ;
if ( V_48 ) {
F_20 ( V_36 ) ;
F_18 ( V_4 , NULL ) ;
goto V_57;
}
F_21 ( V_36 , & V_58 ) ;
V_57:
return V_48 ;
}
static void F_22 ( struct V_47 * V_4 )
{
struct V_1 * V_2 = F_23 ( V_4 ) ;
F_24 ( V_2 -> V_36 ) ;
}
static int T_5 F_25 ( void )
{
int V_48 = 0 ;
V_48 = F_26 ( & V_59 ) ;
if ( V_48 )
F_10 ( L_3 , V_48 ) ;
return V_48 ;
}
static void T_6 F_27 ( void )
{
F_28 ( & V_59 ) ;
}
