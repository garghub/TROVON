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
T_1 V_1 = V_10 -> V_11 ;
unsigned int V_18 = 1 << F_1 ( V_1 ) ;
void T_2 * V_26 = F_4 ( V_1 ) ;
unsigned long V_24 ;
unsigned int V_27 ;
if ( V_25 & V_28 )
F_30 ( V_10 , & V_29 ,
V_30 , NULL ) ;
else
F_30 ( V_10 , & V_31 ,
V_32 , NULL ) ;
F_22 ( V_24 ) ;
V_27 = F_14 ( V_26 ) ;
if ( V_25 & V_28 )
V_27 |= V_18 ;
else
V_27 &= ~ V_18 ;
F_9 ( V_27 , V_26 ) ;
#ifdef F_29
V_21 -> V_33 [ F_2 ( V_1 ) ] |= V_18 ;
#endif
F_23 ( V_24 ) ;
return 0 ;
}
static void F_31 ( struct V_34 * V_35 )
{
struct V_20 * V_21 = & V_20 ;
T_1 V_1 ;
unsigned int V_36 , V_37 , V_38 ;
void T_2 * V_19 = F_3 ( 0 ) ;
for ( V_36 = 0 ; V_36 < V_21 -> V_39 ; ++ V_36 ) {
V_40:
V_38 = F_14 ( V_19 ) & V_21 -> V_22 [ V_36 ] ;
for ( V_1 = V_36 * 32 ; V_38 ; V_38 >>= 1 , ++ V_1 ) {
if ( V_38 & 0x1 ) {
V_37 = F_32 ( V_21 -> V_41 , V_1 ) ;
F_33 ( V_37 ) ;
goto V_40;
}
}
V_19 += V_3 ;
}
}
static int F_34 ( struct V_9 * V_10 ,
const struct V_42 * V_42 , bool V_43 )
{
T_1 V_1 = V_10 -> V_11 ;
void T_2 * V_12 = F_6 ( V_1 ) ;
unsigned int V_44 , V_13 ;
V_44 = F_35 ( V_42 , V_45 ) ;
V_13 = V_46 [ V_44 ] ;
F_9 ( F_10 ( F_11 ( V_13 ) ) , V_12 ) ;
F_36 ( V_10 , F_37 ( V_44 ) ) ;
return 0 ;
}
static int F_38 ( struct V_47 * V_48 , unsigned int V_49 ,
T_1 V_1 )
{
unsigned int V_18 = 1 << F_1 ( V_1 ) ;
void T_2 * V_26 = F_4 ( V_1 ) ;
if ( F_14 ( V_26 ) & V_18 )
F_39 ( V_49 , & V_29 ,
V_30 ) ;
else
F_39 ( V_49 , & V_31 ,
V_32 ) ;
F_40 ( F_41 ( F_42 ( V_49 ) ) ) ;
return 0 ;
}
static int F_43 ( void )
{
struct V_20 * V_21 = & V_20 ;
int V_50 , V_51 ;
T_1 V_1 ;
unsigned int V_36 ;
unsigned long V_24 ;
struct V_52 * V_53 ;
void T_2 * V_26 , * V_23 , * V_12 ;
T_3 V_54 , V_18 ;
V_53 = F_44 ( sizeof( * V_53 ) , V_55 ) ;
if ( ! V_53 )
return - V_56 ;
V_1 = 0 ;
V_26 = F_4 ( 0 ) ;
V_23 = F_5 ( 0 ) ;
for ( V_36 = 0 ; V_36 < V_21 -> V_39 ; ++ V_36 ) {
V_12 = F_6 ( V_1 ) ;
V_54 = 0 ;
for ( V_18 = 1 ; V_18 ; V_18 <<= 1 ) {
V_50 = F_32 ( V_21 -> V_41 , V_1 ) ;
if ( V_50 && ( ! F_45 ( F_46 ( V_50 ) ) ||
F_47 ( V_50 ) ) ) {
V_54 |= V_18 ;
V_53 -> V_57 [ V_1 ] = F_14 ( V_12 ) ;
}
++ V_1 ;
V_12 += V_8 ;
}
if ( V_21 -> V_33 [ V_36 ] )
V_53 -> V_58 [ V_36 ] = F_14 ( V_26 ) ;
if ( V_54 )
V_53 -> V_59 [ V_36 ] = F_14 ( V_23 ) ;
V_26 += V_3 ;
V_23 += V_3 ;
}
F_22 ( V_24 ) ;
for ( V_50 = 0 ; V_50 < 4 ; ++ V_50 )
for ( V_51 = 0 ; V_51 < 4 ; ++ V_51 )
V_53 -> V_60 [ V_50 ] [ V_51 ] = F_14 ( V_61 +
V_62 * V_50 +
8 * V_51 ) ;
F_23 ( V_24 ) ;
V_52 = V_53 ;
return 0 ;
}
static void F_48 ( void )
{
struct V_20 * V_21 = & V_20 ;
int V_50 , V_51 ;
T_1 V_1 ;
unsigned int V_36 ;
unsigned long V_24 ;
struct V_52 * V_53 = V_52 ;
void T_2 * V_26 , * V_23 , * V_12 ;
T_3 V_54 , V_18 , V_63 ;
V_52 = NULL ;
V_1 = 0 ;
V_26 = F_4 ( 0 ) ;
V_23 = F_5 ( 0 ) ;
for ( V_36 = 0 ; V_36 < V_21 -> V_39 ; ++ V_36 ) {
V_12 = F_6 ( V_1 ) ;
V_54 = 0 ;
for ( V_18 = 1 ; V_18 ; V_18 <<= 1 ) {
V_50 = F_32 ( V_21 -> V_41 , V_1 ) ;
if ( V_50 && ( ! F_45 ( F_46 ( V_50 ) ) ||
F_47 ( V_50 ) ) ) {
V_54 |= V_18 ;
F_9 ( V_53 -> V_57 [ V_1 ] , V_12 ) ;
}
++ V_1 ;
V_12 += V_8 ;
}
if ( V_54 ) {
F_22 ( V_24 ) ;
V_63 = F_14 ( V_23 ) ;
V_63 = ( V_63 & ~ V_54 ) | ( V_53 -> V_59 [ V_36 ] & V_54 ) ;
F_9 ( V_63 , V_23 ) ;
F_23 ( V_24 ) ;
}
V_54 = V_21 -> V_33 [ V_36 ] ;
if ( V_54 ) {
F_22 ( V_24 ) ;
V_63 = F_14 ( V_26 ) ;
V_63 = ( V_63 & ~ V_54 ) | ( V_53 -> V_58 [ V_36 ] & V_54 ) ;
F_9 ( V_63 , V_26 ) ;
F_23 ( V_24 ) ;
}
V_26 += V_3 ;
V_23 += V_3 ;
}
F_22 ( V_24 ) ;
for ( V_50 = 0 ; V_50 < 4 ; ++ V_50 ) {
for ( V_51 = 0 ; V_51 < 4 ; ++ V_51 ) {
F_9 ( V_53 -> V_60 [ V_50 ] [ V_51 ] ,
V_61 +
V_62 * V_50 +
8 * V_51 ) ;
}
}
F_23 ( V_24 ) ;
F_49 ( V_53 ) ;
}
static void T_4 F_50 ( struct V_20 * V_21 )
{
F_51 ( & V_64 ) ;
}
static void T_4 F_52 ( struct V_20 * V_21 , int V_44 )
{
unsigned int V_13 = V_46 [ V_44 ] ;
unsigned int V_65 = F_11 ( V_13 ) ;
int V_49 = F_53 ( V_65 ) ;
F_54 ( V_49 , F_31 ) ;
F_55 ( V_49 , V_66 ) ;
}
void T_4 F_56 ( void )
{
V_31 . V_17 = F_25 ;
V_31 . V_16 = F_26 ;
V_29 . V_17 = F_25 ;
V_29 . V_16 = F_27 ;
}
int T_4 F_57 ( void )
{
struct V_20 * V_21 = & V_20 ;
struct V_67 * V_68 ;
int V_69 , V_44 ;
T_3 V_70 ;
bool V_71 = false ;
V_68 = F_58 ( NULL , NULL , L_1 ) ;
if ( ! V_68 )
return - V_72 ;
V_69 = F_59 ( V_68 , L_2 , & V_70 ) ;
if ( V_69 ) {
F_60 ( L_3 ) ;
return V_69 ;
}
if ( V_70 < 1 || V_70 > 4 ) {
F_60 ( L_4 , V_70 ) ;
return - V_73 ;
}
V_21 -> V_39 = V_70 ;
if ( F_61 ( V_68 , L_5 , NULL ) )
V_71 = true ;
if ( V_71 )
F_56 () ;
V_21 -> V_41 = F_62 ( V_68 , V_21 -> V_39 * 32 ,
& V_74 , V_21 ) ;
if ( F_63 ( ! V_21 -> V_41 ) ) {
F_60 ( L_6 ) ;
return - V_56 ;
}
F_64 (cpu)
F_52 ( V_21 , V_44 ) ;
F_50 ( V_21 ) ;
F_65 ( L_7 ,
V_21 -> V_39 * 32 ) ;
return 0 ;
}
