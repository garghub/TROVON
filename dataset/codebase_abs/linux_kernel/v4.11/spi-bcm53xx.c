static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 , V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_2 V_3 ,
T_1 V_5 )
{
F_4 ( V_2 -> V_4 , V_3 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_4 -> V_7 ;
unsigned long V_8 ;
T_1 V_9 ;
if ( ! V_2 -> V_10 )
return;
V_9 = F_1 ( V_2 , V_11 ) ;
if ( V_9 & 0x1 )
return;
V_8 = V_12 + F_6 ( 200 ) ;
do {
V_9 = F_1 ( V_2 , V_13 ) ;
if ( ! ( V_9 & 0x1 ) ) {
F_3 ( V_2 , V_11 ,
0x1 ) ;
F_7 ( 200 ) ;
V_2 -> V_10 = false ;
return;
}
F_8 ( 1 ) ;
} while ( ! F_9 ( V_12 , V_8 ) );
F_10 ( V_7 , L_1 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_9 ;
if ( V_2 -> V_10 )
return;
V_9 = F_1 ( V_2 , V_11 ) ;
if ( ! ( V_9 & 0x1 ) )
return;
F_3 ( V_2 , V_11 , 0x0 ) ;
V_2 -> V_10 = true ;
}
static inline unsigned int F_12 ( T_3 V_14 )
{
return ( V_14 * 9000 / V_15 * 110 / 100 ) + 1 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_16 )
{
unsigned long V_8 ;
T_1 V_9 ;
V_8 = V_12 + F_14 ( V_17 ) ;
do {
V_9 = F_1 ( V_2 , V_18 ) ;
if ( ! ( V_9 & V_19 ) )
break;
F_8 ( 5 ) ;
} while ( ! F_9 ( V_12 , V_8 ) );
if ( V_9 & V_19 )
goto V_20;
V_8 = V_12 + F_14 ( V_16 ) ;
do {
V_9 = F_1 ( V_2 , V_21 ) ;
if ( V_9 & V_22 ) {
F_3 ( V_2 , V_21 , 0 ) ;
return 0 ;
}
F_15 () ;
F_8 ( 100 ) ;
} while ( ! F_9 ( V_12 , V_8 ) );
V_20:
F_3 ( V_2 , V_21 , 0 ) ;
F_16 ( L_2 ) ;
return - V_23 ;
}
static void F_17 ( struct V_1 * V_2 , T_4 * V_24 ,
T_3 V_14 , bool V_25 )
{
T_1 V_9 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_14 ; V_26 ++ ) {
F_3 ( V_2 , V_27 + 4 * ( V_26 * 2 ) ,
( unsigned int ) V_24 [ V_26 ] ) ;
}
for ( V_26 = 0 ; V_26 < V_14 ; V_26 ++ ) {
V_9 = V_28 | V_29 |
V_30 ;
if ( ! V_25 && V_26 == V_14 - 1 )
V_9 &= ~ V_28 ;
V_9 &= ~ 0x1 ;
F_3 ( V_2 , V_31 + 4 * V_26 , V_9 ) ;
}
F_3 ( V_2 , V_32 , 0 ) ;
F_3 ( V_2 , V_33 , V_14 - 1 ) ;
if ( V_25 )
F_3 ( V_2 , V_34 , 1 ) ;
V_9 = F_1 ( V_2 , V_18 ) ;
V_9 |= V_19 ;
if ( V_25 )
V_9 |= V_35 ;
F_3 ( V_2 , V_18 , V_9 ) ;
F_13 ( V_2 , F_12 ( V_14 ) ) ;
if ( ! V_25 )
F_3 ( V_2 , V_34 , 0 ) ;
V_2 -> V_36 = V_14 ;
}
static void F_18 ( struct V_1 * V_2 , T_4 * V_37 ,
T_3 V_14 , bool V_25 )
{
T_1 V_9 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_36 + V_14 ; V_26 ++ ) {
V_9 = V_28 | V_29 |
V_30 ;
if ( ! V_25 && V_26 == V_2 -> V_36 + V_14 - 1 )
V_9 &= ~ V_28 ;
V_9 &= ~ 0x1 ;
F_3 ( V_2 , V_31 + 4 * V_26 , V_9 ) ;
}
F_3 ( V_2 , V_32 , 0 ) ;
F_3 ( V_2 , V_33 ,
V_2 -> V_36 + V_14 - 1 ) ;
if ( V_25 )
F_3 ( V_2 , V_34 , 1 ) ;
V_9 = F_1 ( V_2 , V_18 ) ;
V_9 |= V_19 ;
if ( V_25 )
V_9 |= V_35 ;
F_3 ( V_2 , V_18 , V_9 ) ;
F_13 ( V_2 , F_12 ( V_14 ) ) ;
if ( ! V_25 )
F_3 ( V_2 , V_34 , 0 ) ;
for ( V_26 = 0 ; V_26 < V_14 ; ++ V_26 ) {
int V_3 = V_2 -> V_36 + V_26 ;
V_37 [ V_26 ] = ( T_4 ) F_1 ( V_2 , V_38 + 4 * ( 1 + V_3 * 2 ) ) ;
}
V_2 -> V_36 = 0 ;
}
static int F_19 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_20 ( V_40 ) ;
T_4 * V_45 ;
T_3 V_46 ;
F_5 ( V_2 ) ;
if ( V_44 -> V_47 ) {
V_45 = ( T_4 * ) V_44 -> V_47 ;
V_46 = V_44 -> V_14 ;
while ( V_46 ) {
T_3 V_48 = F_21 ( T_3 , 16 , V_46 ) ;
bool V_25 = V_46 - V_48 > 0 ;
F_17 ( V_2 , V_45 , V_48 , V_25 ) ;
V_46 -= V_48 ;
V_45 += V_48 ;
}
}
if ( V_44 -> V_49 ) {
V_45 = ( T_4 * ) V_44 -> V_49 ;
V_46 = V_44 -> V_14 ;
while ( V_46 ) {
T_3 V_50 = F_21 ( T_3 , 16 - V_2 -> V_36 ,
V_46 ) ;
bool V_25 = V_46 - V_50 > 0 ;
F_18 ( V_2 , V_45 , V_50 , V_25 ) ;
V_46 -= V_50 ;
V_45 += V_50 ;
}
}
return 0 ;
}
static int F_22 ( struct V_41 * V_42 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = F_20 ( V_42 -> V_40 ) ;
int V_53 = 0 ;
if ( V_52 -> V_54 + V_52 -> V_14 > V_55 )
return - V_56 ;
F_11 ( V_2 ) ;
F_23 ( V_52 -> V_45 , V_2 -> V_57 + V_52 -> V_54 , V_52 -> V_14 ) ;
V_52 -> V_58 = V_52 -> V_14 ;
return V_53 ;
}
static int F_24 ( struct V_59 * V_4 )
{
struct V_6 * V_7 = & V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_39 * V_40 ;
int V_60 ;
if ( V_4 -> V_61 -> V_62 . V_4 -> V_63 . V_64 != 42 ) {
F_16 ( L_3 ) ;
return - V_65 ;
}
V_40 = F_25 ( V_7 , sizeof( * V_2 ) ) ;
if ( ! V_40 )
return - V_66 ;
V_2 = F_20 ( V_40 ) ;
V_2 -> V_40 = V_40 ;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_67 [ 0 ] )
V_2 -> V_57 = F_26 ( V_7 , V_4 -> V_67 [ 0 ] ,
V_55 ) ;
V_2 -> V_10 = true ;
F_5 ( V_2 ) ;
V_40 -> V_7 . V_68 = V_7 -> V_68 ;
V_40 -> V_69 = F_19 ;
if ( V_2 -> V_57 )
V_40 -> V_70 = F_22 ;
F_27 ( V_4 , V_2 ) ;
V_60 = F_28 ( V_7 , V_40 ) ;
if ( V_60 ) {
F_29 ( V_40 ) ;
F_27 ( V_4 , NULL ) ;
return V_60 ;
}
return 0 ;
}
static int T_5 F_30 ( void )
{
int V_60 = 0 ;
V_60 = F_31 ( & V_71 ) ;
if ( V_60 )
F_16 ( L_4 , V_60 ) ;
return V_60 ;
}
static void T_6 F_32 ( void )
{
F_33 ( & V_71 ) ;
}
