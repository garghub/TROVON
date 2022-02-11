static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 , V_3 , V_2 -> V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_6 )
{
F_4 ( V_2 -> V_4 , V_3 , V_6 , V_2 -> V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = 0 ;
while ( ! ( F_1 ( V_2 , V_8 ) & 1 ) ) {
V_7 ++ ;
if ( V_7 > 100000 ) {
F_6 ( V_9 L_1 ) ;
return;
}
}
}
static void F_7 ( struct V_1 * V_2 )
{
int V_10 = 0 , V_11 = 0 ;
if ( ! F_8 () || V_2 != & V_12 [ 0 ] ) {
F_3 ( V_2 , V_13 , 0x06 ) ;
F_5 ( V_2 ) ;
}
F_9 ( V_2 , V_14 ) ;
if ( F_8 () )
V_10 = 1 ;
if ( F_8 () )
V_11 = 1 ;
F_10 ( V_2 -> V_4 , V_10 , V_11 ) ;
V_2 -> V_5 = 1 ;
}
void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
F_7 ( V_2 ) ;
}
struct V_1 * F_13 ( void )
{
struct V_1 * V_2 = NULL ;
unsigned long V_15 ;
int V_16 ;
F_14 ( & V_17 , V_15 ) ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
if ( V_12 [ V_16 ] . V_19 )
continue;
V_2 = & V_12 [ V_16 ] ;
V_2 -> V_19 = 1 ;
break;
}
F_15 ( & V_17 , V_15 ) ;
if ( V_2 != NULL )
F_11 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_16 ( int V_20 )
{
struct V_1 * V_2 ;
unsigned long V_15 ;
F_14 ( & V_17 , V_15 ) ;
if ( V_20 <= 0 || V_20 > V_18 || V_12 [ V_20 - 1 ] . V_19 ) {
F_15 ( & V_17 , V_15 ) ;
F_6 ( L_2 ,
__FILE__ , __LINE__ , V_21 , V_20 ) ;
F_17 () ;
return NULL ;
}
V_2 = & V_12 [ V_20 - 1 ] ;
V_2 -> V_19 = 1 ;
F_15 ( & V_17 , V_15 ) ;
F_11 ( V_2 ) ;
return V_2 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
F_7 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( ! V_2 -> V_19 ) ;
V_2 -> V_19 = 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 )
return;
#ifdef F_21
if ( F_8 () ) {
F_22 ( V_2 -> V_23 ) ;
F_22 ( V_2 -> V_24 ) ;
}
#endif
V_2 -> V_22 = 1 ;
}
void F_19 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_22 )
return;
#ifdef F_21
if ( F_8 () ) {
F_23 ( V_2 -> V_24 ) ;
F_23 ( V_2 -> V_23 ) ;
}
#endif
V_2 -> V_22 = 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
return V_2 -> V_25 ;
}
T_2 F_25 ( T_2 V_26 )
{
int V_16 ;
if ( ! ( V_26 & ( 1 << 1 ) ) )
return V_26 ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
T_1 V_27 ;
V_27 = F_1 ( & V_12 [ V_16 ] , V_28 ) ;
if ( V_27 & V_29 ) {
if ( ( ( F_26 ( V_30 ) >> ( V_16 * 2 ) ) & 0x03 ) == 0 )
V_26 &= ~ ( 1 << 1 ) ;
else
V_26 &= ~ ( 1 << 2 ) ;
}
}
return V_26 ;
}
struct V_31 * F_27 ( struct V_1 * V_2 )
{
return V_2 -> V_23 ;
}
T_2 F_25 ( T_2 V_26 )
{
F_28 () ;
return 0 ;
}
void F_29 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_32 , 0 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
T_1 V_27 ;
V_27 = F_1 ( V_2 , V_28 ) ;
if ( ! ( V_27 & V_29 ) ) {
V_27 |= V_29 ;
F_3 ( V_2 , V_28 , V_27 ) ;
}
}
void F_31 ( struct V_1 * V_2 )
{
unsigned long V_33 = 0 ;
#ifdef F_21
V_33 = F_32 ( V_2 -> V_23 ) ;
#endif
F_33 ( V_2 -> V_4 , V_2 -> V_5 , V_33 ) ;
}
int F_9 ( struct V_1 * V_2 , int V_34 )
{
int V_35 = ( V_2 - V_12 ) << 1 ;
T_1 V_27 ;
V_27 = F_26 ( V_30 ) & ~ ( 0x03 << V_35 ) ;
V_27 |= V_34 << V_35 ;
F_34 ( V_27 , V_30 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , int V_34 )
{
if ( V_34 < 0 || V_34 >= 3 )
return - V_36 ;
return F_35 ( V_2 -> V_23 ,
V_37 [ V_34 ] ) ;
}
void F_36 ( struct V_1 * V_2 , int V_38 ,
unsigned int V_39 )
{
T_1 V_27 ;
V_27 = F_1 ( V_2 , V_28 ) ;
if ( V_38 )
V_27 |= V_40 ;
else
V_27 &= ~ V_40 ;
F_3 ( V_2 , V_28 , V_27 ) ;
F_3 ( V_2 , V_41 , V_39 ) ;
F_3 ( V_2 , V_32 , 0 ) ;
}
void F_37 ( struct V_1 * V_2 , int V_38 ,
unsigned int V_39 )
{
T_1 V_27 ;
V_27 = F_1 ( V_2 , V_28 ) ;
if ( V_38 ) {
V_27 |= V_40 ;
F_3 ( V_2 , V_41 , V_39 ) ;
} else {
V_27 &= ~ V_40 ;
}
V_27 |= V_29 ;
F_38 ( V_2 -> V_4 , V_27 , V_39 , V_2 -> V_5 ) ;
}
void F_39 ( struct V_1 * V_2 , int V_42 ,
unsigned int V_43 )
{
T_1 V_27 ;
V_27 = F_1 ( V_2 , V_28 ) ;
if ( V_42 )
V_27 |= V_44 ;
else
V_27 &= ~ V_44 ;
F_3 ( V_2 , V_28 , V_27 ) ;
F_3 ( V_2 , V_45 , V_43 ) ;
}
void F_40 ( struct V_1 * V_2 , int V_46 ,
int V_47 , int V_48 )
{
T_1 V_27 ;
V_27 = F_1 ( V_2 , V_28 ) ;
V_27 &= ~ ( V_49 | V_50 |
V_51 | ( 0x03 << 10 ) ) ;
if ( V_46 )
V_27 |= V_50 ;
if ( V_47 )
V_27 |= V_51 ;
V_27 |= V_48 << 10 ;
F_3 ( V_2 , V_28 , V_27 ) ;
}
void F_41 ( struct V_1 * V_2 , int V_52 )
{
T_1 V_27 ;
V_27 = F_1 ( V_2 , V_28 ) ;
V_27 &= ~ ( V_53 | ( 0x07 << 2 ) ) ;
if ( V_52 >= 0x00 && V_52 <= 0x07 ) {
V_27 |= V_53 ;
V_27 |= V_52 << 2 ;
}
F_3 ( V_2 , V_28 , V_27 ) ;
}
void F_42 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
F_43 ( V_2 -> V_4 , V_6 ) ;
}
unsigned int F_44 ( struct V_1 * V_2 )
{
unsigned int V_27 ;
V_27 = F_1 ( V_2 , V_54 ) ;
return V_27 ;
}
void F_45 ( struct V_1 * V_2 , unsigned int V_6 )
{
F_46 ( V_2 -> V_4 , V_6 ) ;
}
unsigned int F_47 ( struct V_1 * V_2 )
{
return F_48 ( V_2 -> V_4 , V_2 -> V_5 ) ;
}
void F_49 ( struct V_1 * V_2 , unsigned int V_6 )
{
F_3 ( V_2 , V_55 , V_6 ) ;
}
int F_50 ( void )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
struct V_1 * V_2 ;
V_2 = & V_12 [ V_16 ] ;
if ( ! V_2 -> V_22 )
continue;
if ( F_1 ( V_2 , V_28 ) &
V_29 ) {
return 1 ;
}
}
return 0 ;
}
static int T_3 F_51 ( void )
{
struct V_1 * V_2 ;
int V_16 , V_56 = V_57 ;
if ( ! ( F_52 () || F_8 () ) )
return - V_58 ;
F_53 ( & V_17 ) ;
if ( F_54 () ) {
V_12 = V_59 ;
V_18 = V_60 ;
V_56 = V_61 ;
} else if ( F_55 () ) {
V_12 = V_62 ;
V_18 = V_63 ;
V_64 = V_65 ;
V_37 = V_66 ;
} else if ( F_56 () ) {
V_12 = V_67 ;
V_18 = V_68 ;
V_64 = V_69 ;
V_37 = V_70 ;
} else if ( F_57 () ) {
V_12 = V_71 ;
V_18 = V_72 ;
V_64 = V_73 ;
V_37 = V_74 ;
}
if ( F_8 () )
for ( V_16 = 0 ; V_64 [ V_16 ] != NULL ; V_16 ++ )
V_37 [ V_16 ] = F_58 ( NULL , V_64 [ V_16 ] ) ;
if ( F_59 () )
V_12 [ 0 ] . V_75 = 0x49018000 ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
V_2 = & V_12 [ V_16 ] ;
V_2 -> V_4 = F_60 ( V_2 -> V_75 , V_56 ) ;
F_61 ( ! V_2 -> V_4 ) ;
#ifdef F_21
if ( F_8 () ) {
char V_76 [ 16 ] ;
sprintf ( V_76 , L_3 , V_16 + 1 ) ;
V_2 -> V_24 = F_58 ( NULL , V_76 ) ;
sprintf ( V_76 , L_4 , V_16 + 1 ) ;
V_2 -> V_23 = F_58 ( NULL , V_76 ) ;
}
if ( V_77 & ( 1 << V_16 ) ) {
V_2 -> V_19 = 1 ;
V_2 -> V_5 = 1 ;
}
#endif
}
return 0 ;
}
