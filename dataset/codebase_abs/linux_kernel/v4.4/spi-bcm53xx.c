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
V_9 = V_11 + F_7 ( V_12 ) ;
do {
V_10 = F_1 ( V_2 , V_13 ) ;
if ( ! ( V_10 & V_14 ) )
break;
F_8 ( 5 ) ;
} while ( ! F_9 ( V_11 , V_9 ) );
if ( V_10 & V_14 )
goto V_15;
V_9 = V_11 + F_7 ( V_8 ) ;
do {
V_10 = F_1 ( V_2 , V_16 ) ;
if ( V_10 & V_17 ) {
F_3 ( V_2 , V_16 , 0 ) ;
return 0 ;
}
F_10 () ;
F_8 ( 100 ) ;
} while ( ! F_9 ( V_11 , V_9 ) );
V_15:
F_3 ( V_2 , V_16 , 0 ) ;
F_11 ( L_1 ) ;
return - V_18 ;
}
static void F_12 ( struct V_1 * V_2 , T_4 * V_19 ,
T_3 V_6 , bool V_20 )
{
T_1 V_10 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_6 ; V_21 ++ ) {
F_3 ( V_2 , V_22 + 4 * ( V_21 * 2 ) ,
( unsigned int ) V_19 [ V_21 ] ) ;
}
for ( V_21 = 0 ; V_21 < V_6 ; V_21 ++ ) {
V_10 = V_23 | V_24 |
V_25 ;
if ( ! V_20 && V_21 == V_6 - 1 )
V_10 &= ~ V_23 ;
V_10 &= ~ 0x1 ;
F_3 ( V_2 , V_26 + 4 * V_21 , V_10 ) ;
}
F_3 ( V_2 , V_27 , 0 ) ;
F_3 ( V_2 , V_28 , V_6 - 1 ) ;
if ( V_20 )
F_3 ( V_2 , V_29 , 1 ) ;
V_10 = F_1 ( V_2 , V_13 ) ;
V_10 |= V_14 ;
if ( V_20 )
V_10 |= V_30 ;
F_3 ( V_2 , V_13 , V_10 ) ;
F_6 ( V_2 , F_5 ( V_6 ) ) ;
if ( ! V_20 )
F_3 ( V_2 , V_29 , 0 ) ;
V_2 -> V_31 = V_6 ;
}
static void F_13 ( struct V_1 * V_2 , T_4 * V_32 ,
T_3 V_6 , bool V_20 )
{
T_1 V_10 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_31 + V_6 ; V_21 ++ ) {
V_10 = V_23 | V_24 |
V_25 ;
if ( ! V_20 && V_21 == V_2 -> V_31 + V_6 - 1 )
V_10 &= ~ V_23 ;
V_10 &= ~ 0x1 ;
F_3 ( V_2 , V_26 + 4 * V_21 , V_10 ) ;
}
F_3 ( V_2 , V_27 , 0 ) ;
F_3 ( V_2 , V_28 ,
V_2 -> V_31 + V_6 - 1 ) ;
if ( V_20 )
F_3 ( V_2 , V_29 , 1 ) ;
V_10 = F_1 ( V_2 , V_13 ) ;
V_10 |= V_14 ;
if ( V_20 )
V_10 |= V_30 ;
F_3 ( V_2 , V_13 , V_10 ) ;
F_6 ( V_2 , F_5 ( V_6 ) ) ;
if ( ! V_20 )
F_3 ( V_2 , V_29 , 0 ) ;
for ( V_21 = 0 ; V_21 < V_6 ; ++ V_21 ) {
int V_3 = V_2 -> V_31 + V_21 ;
V_32 [ V_21 ] = ( T_4 ) F_1 ( V_2 , V_33 + 4 * ( 1 + V_3 * 2 ) ) ;
}
V_2 -> V_31 = 0 ;
}
static int F_14 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = F_15 ( V_35 ) ;
T_4 * V_40 ;
T_3 V_41 ;
if ( V_39 -> V_42 ) {
V_40 = ( T_4 * ) V_39 -> V_42 ;
V_41 = V_39 -> V_6 ;
while ( V_41 ) {
T_3 V_43 = F_16 ( T_3 , 16 , V_41 ) ;
bool V_20 = V_41 - V_43 > 0 ;
F_12 ( V_2 , V_40 , V_43 , V_20 ) ;
V_41 -= V_43 ;
V_40 += V_43 ;
}
}
if ( V_39 -> V_44 ) {
V_40 = ( T_4 * ) V_39 -> V_44 ;
V_41 = V_39 -> V_6 ;
while ( V_41 ) {
T_3 V_45 = F_16 ( T_3 , 16 - V_2 -> V_31 ,
V_41 ) ;
bool V_20 = V_41 - V_45 > 0 ;
F_13 ( V_2 , V_40 , V_45 , V_20 ) ;
V_41 -= V_45 ;
V_40 += V_45 ;
}
}
return 0 ;
}
static int F_17 ( struct V_46 * V_4 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_47 ;
if ( V_4 -> V_48 -> V_49 . V_4 -> V_50 . V_51 != 42 ) {
F_11 ( L_2 ) ;
return - V_52 ;
}
V_35 = F_18 ( & V_4 -> V_53 , sizeof( * V_2 ) ) ;
if ( ! V_35 )
return - V_54 ;
V_2 = F_15 ( V_35 ) ;
V_2 -> V_35 = V_35 ;
V_2 -> V_4 = V_4 ;
V_35 -> V_55 = F_14 ;
F_19 ( V_4 , V_2 ) ;
V_47 = F_20 ( & V_4 -> V_53 , V_35 ) ;
if ( V_47 ) {
F_21 ( V_35 ) ;
F_19 ( V_4 , NULL ) ;
return V_47 ;
}
F_22 ( V_35 , & V_56 ) ;
return 0 ;
}
static int T_5 F_23 ( void )
{
int V_47 = 0 ;
V_47 = F_24 ( & V_57 ) ;
if ( V_47 )
F_11 ( L_3 , V_47 ) ;
return V_47 ;
}
static void T_6 F_25 ( void )
{
F_26 ( & V_57 ) ;
}
