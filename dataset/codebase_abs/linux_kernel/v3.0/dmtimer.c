static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 )
while ( F_2 ( V_2 -> V_5 + ( V_6 & 0xff ) )
& ( V_3 >> V_7 ) )
F_3 () ;
return F_2 ( V_2 -> V_5 + ( V_3 & 0xff ) ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_8 )
{
if ( V_2 -> V_4 )
while ( F_2 ( V_2 -> V_5 + ( V_6 & 0xff ) )
& ( V_3 >> V_7 ) )
F_3 () ;
F_5 ( V_8 , V_2 -> V_5 + ( V_3 & 0xff ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = 0 ;
while ( ! ( F_1 ( V_2 , V_10 ) & 1 ) ) {
V_9 ++ ;
if ( V_9 > 100000 ) {
F_7 ( V_11 L_1 ) ;
return;
}
}
}
static void F_8 ( struct V_1 * V_2 )
{
T_1 V_12 ;
if ( ! F_9 () || V_2 != & V_13 [ 0 ] ) {
F_4 ( V_2 , V_14 , 0x06 ) ;
F_6 ( V_2 ) ;
}
F_10 ( V_2 , V_15 ) ;
V_12 = F_1 ( V_2 , V_16 ) ;
V_12 |= 0x02 << 3 ;
V_12 |= 0x2 << 8 ;
if ( F_11 () || F_12 () )
V_12 |= 0x1 << 0 ;
if ( F_9 () )
V_12 |= 1 << 2 ;
F_4 ( V_2 , V_16 , V_12 ) ;
F_4 ( V_2 , V_14 ,
V_17 ) ;
V_2 -> V_4 = 1 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_8 ( V_2 ) ;
}
struct V_1 * F_15 ( void )
{
struct V_1 * V_2 = NULL ;
unsigned long V_18 ;
int V_19 ;
F_16 ( & V_20 , V_18 ) ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
if ( V_13 [ V_19 ] . V_22 )
continue;
V_2 = & V_13 [ V_19 ] ;
V_2 -> V_22 = 1 ;
break;
}
F_17 ( & V_20 , V_18 ) ;
if ( V_2 != NULL )
F_13 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_18 ( int V_23 )
{
struct V_1 * V_2 ;
unsigned long V_18 ;
F_16 ( & V_20 , V_18 ) ;
if ( V_23 <= 0 || V_23 > V_21 || V_13 [ V_23 - 1 ] . V_22 ) {
F_17 ( & V_20 , V_18 ) ;
F_7 ( L_2 ,
__FILE__ , __LINE__ , V_24 , V_23 ) ;
F_19 () ;
return NULL ;
}
V_2 = & V_13 [ V_23 - 1 ] ;
V_2 -> V_22 = 1 ;
F_17 ( & V_20 , V_18 ) ;
F_13 ( V_2 ) ;
return V_2 ;
}
void F_20 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_8 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( ! V_2 -> V_22 ) ;
V_2 -> V_22 = 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 )
return;
#ifdef F_23
if ( F_9 () ) {
F_24 ( V_2 -> V_26 ) ;
F_24 ( V_2 -> V_27 ) ;
}
#endif
V_2 -> V_25 = 1 ;
}
void F_21 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_25 )
return;
#ifdef F_23
if ( F_9 () ) {
F_25 ( V_2 -> V_27 ) ;
F_25 ( V_2 -> V_26 ) ;
}
#endif
V_2 -> V_25 = 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
return V_2 -> V_28 ;
}
T_2 F_27 ( T_2 V_29 )
{
int V_19 ;
if ( ! ( V_29 & ( 1 << 1 ) ) )
return V_29 ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
T_1 V_12 ;
V_12 = F_1 ( & V_13 [ V_19 ] , V_30 ) ;
if ( V_12 & V_31 ) {
if ( ( ( F_28 ( V_32 ) >> ( V_19 * 2 ) ) & 0x03 ) == 0 )
V_29 &= ~ ( 1 << 1 ) ;
else
V_29 &= ~ ( 1 << 2 ) ;
}
}
return V_29 ;
}
struct V_33 * F_29 ( struct V_1 * V_2 )
{
return V_2 -> V_26 ;
}
T_2 F_27 ( T_2 V_29 )
{
F_30 () ;
return 0 ;
}
void F_31 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_34 , 0 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
T_1 V_12 ;
V_12 = F_1 ( V_2 , V_30 ) ;
if ( ! ( V_12 & V_31 ) ) {
V_12 |= V_31 ;
F_4 ( V_2 , V_30 , V_12 ) ;
}
}
void F_33 ( struct V_1 * V_2 )
{
T_1 V_12 ;
V_12 = F_1 ( V_2 , V_30 ) ;
if ( V_12 & V_31 ) {
V_12 &= ~ 0x1 ;
F_4 ( V_2 , V_30 , V_12 ) ;
#ifdef F_23
F_1 ( V_2 , V_30 ) ;
F_34 ( 3500000 / F_35 ( V_2 -> V_26 ) + 1 ) ;
#endif
}
F_4 ( V_2 , V_35 ,
V_36 ) ;
}
int F_10 ( struct V_1 * V_2 , int V_37 )
{
int V_38 = ( V_2 - V_13 ) << 1 ;
T_1 V_12 ;
V_12 = F_28 ( V_32 ) & ~ ( 0x03 << V_38 ) ;
V_12 |= V_37 << V_38 ;
F_36 ( V_12 , V_32 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , int V_37 )
{
int V_39 = - V_40 ;
if ( V_37 < 0 || V_37 >= 3 )
return - V_40 ;
F_25 ( V_2 -> V_26 ) ;
V_39 = F_37 ( V_2 -> V_26 , V_41 [ V_37 ] ) ;
F_24 ( V_2 -> V_26 ) ;
F_38 ( 300000 ) ;
return V_39 ;
}
void F_39 ( struct V_1 * V_2 , int V_42 ,
unsigned int V_43 )
{
T_1 V_12 ;
V_12 = F_1 ( V_2 , V_30 ) ;
if ( V_42 )
V_12 |= V_44 ;
else
V_12 &= ~ V_44 ;
F_4 ( V_2 , V_30 , V_12 ) ;
F_4 ( V_2 , V_45 , V_43 ) ;
F_4 ( V_2 , V_34 , 0 ) ;
}
void F_40 ( struct V_1 * V_2 , int V_42 ,
unsigned int V_43 )
{
T_1 V_12 ;
V_12 = F_1 ( V_2 , V_30 ) ;
if ( V_42 ) {
V_12 |= V_44 ;
F_4 ( V_2 , V_45 , V_43 ) ;
} else {
V_12 &= ~ V_44 ;
}
V_12 |= V_31 ;
F_4 ( V_2 , V_46 , V_43 ) ;
F_4 ( V_2 , V_30 , V_12 ) ;
}
void F_41 ( struct V_1 * V_2 , int V_47 ,
unsigned int V_48 )
{
T_1 V_12 ;
V_12 = F_1 ( V_2 , V_30 ) ;
if ( V_47 )
V_12 |= V_49 ;
else
V_12 &= ~ V_49 ;
F_4 ( V_2 , V_30 , V_12 ) ;
F_4 ( V_2 , V_50 , V_48 ) ;
}
void F_42 ( struct V_1 * V_2 , int V_51 ,
int V_52 , int V_53 )
{
T_1 V_12 ;
V_12 = F_1 ( V_2 , V_30 ) ;
V_12 &= ~ ( V_54 | V_55 |
V_56 | ( 0x03 << 10 ) ) ;
if ( V_51 )
V_12 |= V_55 ;
if ( V_52 )
V_12 |= V_56 ;
V_12 |= V_53 << 10 ;
F_4 ( V_2 , V_30 , V_12 ) ;
}
void F_43 ( struct V_1 * V_2 , int V_57 )
{
T_1 V_12 ;
V_12 = F_1 ( V_2 , V_30 ) ;
V_12 &= ~ ( V_58 | ( 0x07 << 2 ) ) ;
if ( V_57 >= 0x00 && V_57 <= 0x07 ) {
V_12 |= V_58 ;
V_12 |= V_57 << 2 ;
}
F_4 ( V_2 , V_30 , V_12 ) ;
}
void F_44 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
F_4 ( V_2 , V_59 , V_8 ) ;
F_4 ( V_2 , V_60 , V_8 ) ;
}
unsigned int F_45 ( struct V_1 * V_2 )
{
unsigned int V_12 ;
V_12 = F_1 ( V_2 , V_35 ) ;
return V_12 ;
}
void F_46 ( struct V_1 * V_2 , unsigned int V_8 )
{
F_4 ( V_2 , V_35 , V_8 ) ;
}
unsigned int F_47 ( struct V_1 * V_2 )
{
unsigned int V_12 ;
V_12 = F_1 ( V_2 , V_46 ) ;
return V_12 ;
}
void F_48 ( struct V_1 * V_2 , unsigned int V_8 )
{
F_4 ( V_2 , V_46 , V_8 ) ;
}
int F_49 ( void )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
struct V_1 * V_2 ;
V_2 = & V_13 [ V_19 ] ;
if ( ! V_2 -> V_25 )
continue;
if ( F_1 ( V_2 , V_30 ) &
V_31 ) {
return 1 ;
}
}
return 0 ;
}
int T_3 F_50 ( void )
{
struct V_1 * V_2 ;
int V_19 , V_61 = V_62 ;
if ( ! ( F_51 () || F_9 () ) )
return - V_63 ;
F_52 ( & V_20 ) ;
if ( F_53 () ) {
V_13 = V_64 ;
V_21 = V_65 ;
V_61 = V_66 ;
} else if ( F_11 () ) {
V_13 = V_67 ;
V_21 = V_68 ;
V_69 = V_70 ;
V_41 = V_71 ;
} else if ( F_12 () ) {
V_13 = V_72 ;
V_21 = V_73 ;
V_69 = V_74 ;
V_41 = V_75 ;
} else if ( F_54 () ) {
V_13 = V_76 ;
V_21 = V_77 ;
V_69 = V_78 ;
V_41 = V_79 ;
}
if ( F_9 () )
for ( V_19 = 0 ; V_69 [ V_19 ] != NULL ; V_19 ++ )
V_41 [ V_19 ] = F_55 ( NULL , V_69 [ V_19 ] ) ;
if ( F_56 () )
V_13 [ 0 ] . V_80 = 0x49018000 ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
V_2 = & V_13 [ V_19 ] ;
V_2 -> V_5 = F_57 ( V_2 -> V_80 , V_61 ) ;
F_58 ( ! V_2 -> V_5 ) ;
#ifdef F_23
if ( F_9 () ) {
char V_81 [ 16 ] ;
sprintf ( V_81 , L_3 , V_19 + 1 ) ;
V_2 -> V_27 = F_55 ( NULL , V_81 ) ;
sprintf ( V_81 , L_4 , V_19 + 1 ) ;
V_2 -> V_26 = F_55 ( NULL , V_81 ) ;
}
#endif
}
return 0 ;
}
