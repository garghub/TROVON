static unsigned int F_1 ( T_1 V_1 )
{
return V_1 & 0x1f ;
}
static unsigned int F_2 ( T_1 V_1 )
{
return V_1 >> 5 ;
}
static void T_2 * F_3 ( T_1 V_1 )
{
return ( void T_2 * ) ( V_2 +
V_3 * F_2 ( V_1 ) ) ;
}
static void T_2 * F_4 ( T_1 V_1 )
{
return ( void T_2 * ) ( V_4 +
V_3 * F_2 ( V_1 ) ) ;
}
static void T_2 * F_5 ( T_1 V_1 )
{
return ( void T_2 * ) ( V_5 +
V_3 * F_2 ( V_1 ) ) ;
}
static inline void T_2 * F_6 ( T_1 V_1 )
{
return ( void T_2 * ) ( V_6 +
V_7 * F_2 ( V_1 ) +
V_8 * F_1 ( V_1 ) ) ;
}
static unsigned int F_7 ( struct V_9 * V_10 )
{
T_1 V_1 = V_10 -> V_11 ;
void T_2 * V_12 = F_6 ( V_1 ) ;
int V_13 = F_8 () ;
if ( V_10 -> V_14 -> V_15 )
V_10 -> V_14 -> V_15 ( V_10 ) ;
F_9 ( F_10 ( F_11 ( V_13 ) ) , V_12 ) ;
V_10 -> V_14 -> V_16 ( V_10 ) ;
return 0 ;
}
static void F_12 ( struct V_9 * V_10 )
{
T_1 V_1 = V_10 -> V_11 ;
void T_2 * V_12 = F_6 ( V_1 ) ;
V_10 -> V_14 -> V_17 ( V_10 ) ;
F_9 ( 0 , V_12 ) ;
}
static void F_13 ( struct V_9 * V_10 )
{
T_1 V_1 = V_10 -> V_11 ;
unsigned int V_18 = 1 << F_1 ( V_1 ) ;
void T_2 * V_19 = F_3 ( V_1 ) ;
if ( F_14 ( V_19 ) & V_18 )
F_9 ( V_18 , V_19 ) ;
}
static void F_15 ( struct V_9 * V_10 )
{
struct V_20 * V_21 = & V_20 ;
T_1 V_1 = V_10 -> V_11 ;
F_16 ( F_1 ( V_1 ) , & V_21 -> V_22 [ F_2 ( V_1 ) ] ) ;
}
static void F_17 ( struct V_9 * V_10 )
{
struct V_20 * V_21 = & V_20 ;
T_1 V_1 = V_10 -> V_11 ;
F_18 ( F_1 ( V_1 ) , & V_21 -> V_22 [ F_2 ( V_1 ) ] ) ;
}
void F_19 ( struct V_9 * V_10 )
{
F_15 ( V_10 ) ;
}
void F_20 ( struct V_9 * V_10 )
{
F_17 ( V_10 ) ;
}
static void F_21 ( struct V_9 * V_10 )
{
T_1 V_1 = V_10 -> V_11 ;
unsigned int V_18 = 1 << F_1 ( V_1 ) ;
void T_2 * V_23 = F_5 ( V_1 ) ;
unsigned long V_24 ;
F_15 ( V_10 ) ;
F_22 ( V_24 ) ;
F_9 ( F_14 ( V_23 ) & ~ V_18 , V_23 ) ;
F_23 ( V_24 ) ;
}
static void F_24 ( struct V_9 * V_10 )
{
T_1 V_1 = V_10 -> V_11 ;
unsigned int V_18 = 1 << F_1 ( V_1 ) ;
void T_2 * V_23 = F_5 ( V_1 ) ;
unsigned long V_24 ;
F_17 ( V_10 ) ;
F_22 ( V_24 ) ;
F_9 ( F_14 ( V_23 ) | V_18 , V_23 ) ;
F_23 ( V_24 ) ;
}
static void F_25 ( struct V_9 * V_10 )
{
T_1 V_1 = V_10 -> V_11 ;
void T_2 * V_12 = F_6 ( V_1 ) ;
F_15 ( V_10 ) ;
F_9 ( 0 , V_12 ) ;
}
static void F_26 ( struct V_9 * V_10 )
{
T_1 V_1 = V_10 -> V_11 ;
unsigned int V_18 = 1 << F_1 ( V_1 ) ;
void T_2 * V_19 = F_3 ( V_1 ) ;
void T_2 * V_12 = F_6 ( V_1 ) ;
unsigned int V_13 = F_8 () ;
F_17 ( V_10 ) ;
F_9 ( F_10 ( F_11 ( V_13 ) ) , V_12 ) ;
if ( F_14 ( V_19 ) & V_18 ) {
F_9 ( V_18 , V_19 ) ;
while ( ! ( F_14 ( V_19 ) & V_18 ) )
F_9 ( V_18 , V_19 ) ;
}
}
static void F_27 ( struct V_9 * V_10 )
{
T_1 V_1 = V_10 -> V_11 ;
unsigned int V_18 = 1 << F_1 ( V_1 ) ;
void T_2 * V_19 = F_3 ( V_1 ) ;
void T_2 * V_12 = F_6 ( V_1 ) ;
unsigned int V_13 = F_8 () ;
F_17 ( V_10 ) ;
F_9 ( F_10 ( F_11 ( V_13 ) ) , V_12 ) ;
if ( F_14 ( V_19 ) & V_18 )
F_9 ( V_18 , V_19 ) ;
}
static int F_28 ( struct V_9 * V_10 , unsigned int V_25 )
{
#ifdef F_29
struct V_20 * V_21 = & V_20 ;
#endif
unsigned int V_26 = V_10 -> V_26 ;
T_1 V_1 = V_10 -> V_11 ;
unsigned int V_18 = 1 << F_1 ( V_1 ) ;
void T_2 * V_27 = F_4 ( V_1 ) ;
unsigned long V_24 ;
unsigned int V_28 ;
if ( V_25 & V_29 )
F_30 ( V_26 , & V_30 ,
V_31 , NULL ) ;
else
F_30 ( V_26 , & V_32 ,
V_33 , NULL ) ;
F_22 ( V_24 ) ;
V_28 = F_14 ( V_27 ) ;
if ( V_25 & V_29 )
V_28 |= V_18 ;
else
V_28 &= ~ V_18 ;
F_9 ( V_28 , V_27 ) ;
#ifdef F_29
V_21 -> V_34 [ F_2 ( V_1 ) ] |= V_18 ;
#endif
F_23 ( V_24 ) ;
return 0 ;
}
static void F_31 ( unsigned int V_26 , struct V_35 * V_36 )
{
struct V_20 * V_21 = & V_20 ;
T_1 V_1 ;
unsigned int V_37 , V_38 , V_39 ;
void T_2 * V_19 = F_3 ( 0 ) ;
for ( V_37 = 0 ; V_37 < V_21 -> V_40 ; ++ V_37 ) {
V_41:
V_39 = F_14 ( V_19 ) & V_21 -> V_22 [ V_37 ] ;
for ( V_1 = V_37 * 32 ; V_39 ; V_39 >>= 1 , ++ V_1 ) {
if ( V_39 & 0x1 ) {
V_38 = F_32 ( V_21 -> V_42 , V_1 ) ;
F_33 ( V_38 ) ;
goto V_41;
}
}
V_19 += V_3 ;
}
}
static int F_34 ( struct V_9 * V_10 ,
const struct V_43 * V_43 , bool V_44 )
{
T_1 V_1 = V_10 -> V_11 ;
void T_2 * V_12 = F_6 ( V_1 ) ;
unsigned int V_45 , V_13 ;
V_45 = F_35 ( V_43 ) ;
V_13 = V_46 [ V_45 ] ;
F_9 ( F_10 ( F_11 ( V_13 ) ) , V_12 ) ;
return 0 ;
}
static int F_36 ( struct V_47 * V_48 , unsigned int V_26 ,
T_1 V_1 )
{
unsigned int V_18 = 1 << F_1 ( V_1 ) ;
void T_2 * V_27 = F_4 ( V_1 ) ;
if ( F_14 ( V_27 ) & V_18 )
F_37 ( V_26 , & V_30 ,
V_31 ) ;
else
F_37 ( V_26 , & V_32 ,
V_33 ) ;
return 0 ;
}
static int F_38 ( void )
{
struct V_20 * V_21 = & V_20 ;
int V_49 , V_50 ;
T_1 V_1 ;
unsigned int V_37 ;
unsigned long V_24 ;
struct V_51 * V_52 ;
void T_2 * V_27 , * V_23 , * V_12 ;
T_3 V_53 , V_18 ;
V_52 = F_39 ( sizeof( * V_52 ) , V_54 ) ;
if ( ! V_52 )
return - V_55 ;
V_1 = 0 ;
V_27 = F_4 ( 0 ) ;
V_23 = F_5 ( 0 ) ;
for ( V_37 = 0 ; V_37 < V_21 -> V_40 ; ++ V_37 ) {
V_12 = F_6 ( V_1 ) ;
V_53 = 0 ;
for ( V_18 = 1 ; V_18 ; V_18 <<= 1 ) {
V_49 = F_32 ( V_21 -> V_42 , V_1 ) ;
if ( V_49 && ( ! F_40 ( F_41 ( V_49 ) ) ||
F_42 ( V_49 ) ) ) {
V_53 |= V_18 ;
V_52 -> V_56 [ V_1 ] = F_14 ( V_12 ) ;
}
++ V_1 ;
V_12 += V_8 ;
}
if ( V_21 -> V_34 [ V_37 ] )
V_52 -> V_57 [ V_37 ] = F_14 ( V_27 ) ;
if ( V_53 )
V_52 -> V_58 [ V_37 ] = F_14 ( V_23 ) ;
V_27 += V_3 ;
V_23 += V_3 ;
}
F_22 ( V_24 ) ;
for ( V_49 = 0 ; V_49 < 4 ; ++ V_49 )
for ( V_50 = 0 ; V_50 < 4 ; ++ V_50 )
V_52 -> V_59 [ V_49 ] [ V_50 ] = F_14 ( V_60 +
V_61 * V_49 +
8 * V_50 ) ;
F_23 ( V_24 ) ;
V_51 = V_52 ;
return 0 ;
}
static void F_43 ( void )
{
struct V_20 * V_21 = & V_20 ;
int V_49 , V_50 ;
T_1 V_1 ;
unsigned int V_37 ;
unsigned long V_24 ;
struct V_51 * V_52 = V_51 ;
void T_2 * V_27 , * V_23 , * V_12 ;
T_3 V_53 , V_18 , V_62 ;
V_51 = NULL ;
V_1 = 0 ;
V_27 = F_4 ( 0 ) ;
V_23 = F_5 ( 0 ) ;
for ( V_37 = 0 ; V_37 < V_21 -> V_40 ; ++ V_37 ) {
V_12 = F_6 ( V_1 ) ;
V_53 = 0 ;
for ( V_18 = 1 ; V_18 ; V_18 <<= 1 ) {
V_49 = F_32 ( V_21 -> V_42 , V_1 ) ;
if ( V_49 && ( ! F_40 ( F_41 ( V_49 ) ) ||
F_42 ( V_49 ) ) ) {
V_53 |= V_18 ;
F_9 ( V_52 -> V_56 [ V_1 ] , V_12 ) ;
}
++ V_1 ;
V_12 += V_8 ;
}
if ( V_53 ) {
F_22 ( V_24 ) ;
V_62 = F_14 ( V_23 ) ;
V_62 = ( V_62 & ~ V_53 ) | ( V_52 -> V_58 [ V_37 ] & V_53 ) ;
F_9 ( V_62 , V_23 ) ;
F_23 ( V_24 ) ;
}
V_53 = V_21 -> V_34 [ V_37 ] ;
if ( V_53 ) {
F_22 ( V_24 ) ;
V_62 = F_14 ( V_27 ) ;
V_62 = ( V_62 & ~ V_53 ) | ( V_52 -> V_57 [ V_37 ] & V_53 ) ;
F_9 ( V_62 , V_27 ) ;
F_23 ( V_24 ) ;
}
V_27 += V_3 ;
V_23 += V_3 ;
}
F_22 ( V_24 ) ;
for ( V_49 = 0 ; V_49 < 4 ; ++ V_49 ) {
for ( V_50 = 0 ; V_50 < 4 ; ++ V_50 ) {
F_9 ( V_52 -> V_59 [ V_49 ] [ V_50 ] ,
V_60 +
V_61 * V_49 +
8 * V_50 ) ;
}
}
F_23 ( V_24 ) ;
F_44 ( V_52 ) ;
}
static void T_4 F_45 ( struct V_20 * V_21 )
{
F_46 ( & V_63 ) ;
}
static void T_4 F_47 ( struct V_20 * V_21 , int V_45 )
{
unsigned int V_13 = V_46 [ V_45 ] ;
unsigned int V_64 = F_11 ( V_13 ) ;
int V_26 = F_48 ( V_64 ) ;
F_49 ( V_26 , F_31 ) ;
F_50 ( V_26 , V_65 ) ;
}
void T_4 F_51 ( void )
{
V_32 . V_17 = F_25 ;
V_32 . V_16 = F_26 ;
V_30 . V_17 = F_25 ;
V_30 . V_16 = F_27 ;
}
int T_4 F_52 ( void )
{
struct V_20 * V_21 = & V_20 ;
struct V_66 * V_67 ;
int V_68 , V_45 ;
T_3 V_69 ;
bool V_70 = false ;
V_67 = F_53 ( NULL , NULL , L_1 ) ;
if ( ! V_67 )
return - V_71 ;
V_68 = F_54 ( V_67 , L_2 , & V_69 ) ;
if ( V_68 ) {
F_55 ( L_3 ) ;
return V_68 ;
}
if ( V_69 < 1 || V_69 > 4 ) {
F_55 ( L_4 , V_69 ) ;
return - V_72 ;
}
V_21 -> V_40 = V_69 ;
if ( F_56 ( V_67 , L_5 , NULL ) )
V_70 = true ;
if ( V_70 )
F_51 () ;
V_21 -> V_42 = F_57 ( V_67 , V_21 -> V_40 * 32 ,
& V_73 , V_21 ) ;
if ( F_58 ( ! V_21 -> V_42 ) ) {
F_55 ( L_6 ) ;
return - V_55 ;
}
F_59 (cpu)
F_47 ( V_21 , V_45 ) ;
F_45 ( V_21 ) ;
F_60 ( L_7 ,
V_21 -> V_40 * 32 ) ;
return 0 ;
}
