static inline void F_1 ( void )
{
F_2 ( 0x87 , 0x370 ) ;
F_2 ( 0x87 , 0x370 ) ;
}
static inline void F_3 ( void )
{
F_2 ( 0xaa , 0x370 ) ;
}
static inline void F_4 ( int V_1 , int V_2 )
{
F_2 ( V_1 , 0x370 ) ;
F_2 ( V_2 , 0x371 ) ;
}
static inline void F_5 ( int V_1 , int V_2 )
{
F_2 ( V_1 , 0x370 ) ;
F_2 ( V_2 >> 8 , 0x371 ) ;
F_2 ( V_1 + 1 , 0x370 ) ;
F_2 ( V_2 & 255 , 0x371 ) ;
}
void F_6 ( unsigned int V_3 , unsigned int V_4 )
{
unsigned int V_5 , V_6 ;
V_5 = ( V_7 & ~ V_3 ) | V_4 ;
V_6 = V_5 ^ V_7 ;
V_7 = V_5 ;
if ( V_6 & 0xff )
F_2 ( V_5 , V_8 ) ;
if ( V_6 & 0xff00 )
F_2 ( V_5 >> 8 , V_9 ) ;
}
static inline void F_7 ( int V_3 , int V_10 )
{
unsigned int V_5 , V_6 ;
int V_11 ;
V_5 = ( V_12 & ~ V_3 ) | V_10 ;
V_6 = V_5 ^ V_12 ;
V_12 = V_5 ;
V_6 >>= 1 ;
V_5 >>= 1 ;
F_8 ( 7 ) ;
for ( V_11 = 0xe1 ; V_6 && V_11 < 0xe8 ; V_6 >>= 1 ) {
F_4 ( V_11 , V_5 & 1 ) ;
V_11 += 1 ;
V_5 >>= 1 ;
}
F_8 ( 8 ) ;
for ( V_11 = 0xe8 ; V_6 && V_11 < 0xec ; V_6 >>= 1 ) {
F_4 ( V_11 , V_5 & 1 ) ;
V_11 += 1 ;
V_5 >>= 1 ;
}
}
void F_9 ( unsigned int V_3 , unsigned int V_10 )
{
F_1 () ;
F_7 ( V_3 , V_10 ) ;
F_3 () ;
}
unsigned int F_10 ( void )
{
return F_11 ( V_8 ) | F_11 ( V_9 ) << 8 ;
}
static inline void F_12 ( void )
{
F_4 ( 0x26 , 0x40 ) ;
F_4 ( 0x22 , 0xfe ) ;
F_4 ( 0x2a , 0xc1 ) ;
F_4 ( 0x2b , 0x6b ) ;
F_4 ( 0x2c , 0x55 ) ;
}
static inline void F_13 ( void )
{
F_8 ( 1 ) ;
F_4 ( 0xf0 , 0x01 ) ;
}
static inline void F_14 ( void )
{
F_8 ( 5 ) ;
F_5 ( 0x60 , 0x0060 ) ;
F_5 ( 0x62 , 0x0064 ) ;
F_4 ( 0x70 , 1 ) ;
F_4 ( 0x71 , 0x02 ) ;
F_4 ( 0x72 , 5 ) ;
F_4 ( 0x73 , 0x02 ) ;
F_4 ( 0xf0 , 0x40 ) ;
F_15 () ;
}
static inline void F_16 ( void )
{
F_8 ( 6 ) ;
F_5 ( 0x60 , V_13 ) ;
F_4 ( 0x70 , 6 ) ;
F_4 ( 0x71 , 0x02 ) ;
F_4 ( 0x74 , 0x00 ) ;
F_4 ( 0x75 , 0x04 ) ;
F_4 ( 0xf0 , 0x03 ) ;
F_15 () ;
}
static inline void F_17 ( void )
{
unsigned long V_14 ;
V_12 = - 1 ;
F_7 ( - 1 , V_15 | V_16 ) ;
F_8 ( 7 ) ;
F_5 ( 0x60 , V_8 ) ;
F_5 ( 0x62 , 0 ) ;
F_5 ( 0x64 , 0 ) ;
F_4 ( 0x70 , 10 ) ;
F_4 ( 0x71 , 0x02 ) ;
F_4 ( 0xe0 , 0x19 ) ;
F_15 () ;
F_8 ( 8 ) ;
F_5 ( 0x60 , V_9 ) ;
F_4 ( 0xf2 , 0x00 ) ;
F_4 ( 0xf3 , 0x00 ) ;
F_4 ( 0xf4 , 0x00 ) ;
F_15 () ;
F_18 ( & V_17 , V_14 ) ;
F_6 ( - 1 , V_18 | V_19 ) ;
F_19 ( & V_17 , V_14 ) ;
}
static void T_1 F_20 ( void )
{
F_21 ( 0x370 , 2 , L_1 ) ;
F_1 () ;
F_12 () ;
F_13 () ;
F_14 () ;
F_16 () ;
F_17 () ;
F_3 () ;
}
void F_22 ( unsigned int V_3 , unsigned int V_4 )
{
int V_20 ;
V_21 = ( V_21 & ~ V_3 ) | V_4 ;
F_9 ( V_22 | V_23 | V_24 , 0 ) ;
F_6 ( V_24 , 0 ) ;
for ( V_20 = 8 ; V_20 ; V_20 >>= 1 ) {
int V_25 = V_21 & V_20 ;
F_6 ( V_22 | V_23 , V_25 ? V_22 : 0 ) ;
F_6 ( V_23 , V_23 ) ;
}
F_6 ( V_23 | V_22 , 0 ) ;
F_6 ( V_24 | V_26 , V_24 | V_26 ) ;
F_6 ( V_24 , 0 ) ;
}
static void T_1 F_23 ( void )
{
unsigned long V_14 ;
F_18 ( & V_17 , V_14 ) ;
F_22 ( - 1 , V_27 | V_28 ) ;
F_19 ( & V_17 , V_14 ) ;
}
static inline void F_24 ( void )
{
int V_29 ;
F_25 ( 2 , 2 ) ;
F_26 ( 10 ) ;
for ( V_29 = 0 ; V_29 < sizeof( V_30 ) ; V_29 ++ ) {
F_2 ( V_30 [ V_29 ] , 0x279 ) ;
F_27 ( 10 ) ;
}
}
static inline void F_28 ( void )
{
unsigned char V_31 [ 9 ] ;
int V_29 , V_32 ;
F_25 ( 3 , 0 ) ;
F_25 ( 0 , 128 ) ;
F_2 ( 1 , 0x279 ) ;
F_26 ( 1 ) ;
F_29 ( L_2 ) ;
for ( V_29 = 0 ; V_29 < 9 ; V_29 ++ ) {
V_31 [ V_29 ] = 0 ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ ) {
int V_25 ;
F_27 ( 250 ) ;
F_11 ( 0x203 ) ;
F_27 ( 250 ) ;
V_25 = F_11 ( 0x203 ) ;
F_29 ( L_3 , V_25 ) ;
V_25 = ( V_25 == 0xaa ) ? 1 : 0 ;
V_31 [ V_29 ] |= V_25 << V_32 ;
}
F_29 ( L_4 , V_31 [ V_29 ] ) ;
}
F_29 ( L_5 ) ;
}
static inline void F_30 ( void )
{
F_25 ( 6 , 2 ) ;
F_29 ( L_6 , F_11 ( 0x203 ) ) ;
F_25 ( 7 , 3 ) ;
F_25 ( 0x30 , 0 ) ;
F_25 ( 7 , 4 ) ;
F_25 ( 0x30 , 0 ) ;
F_25 ( 7 , 2 ) ;
F_25 ( 0x30 , 0 ) ;
}
static inline void F_31 ( void )
{
int V_29 ;
F_25 ( 7 , 5 ) ;
F_29 ( L_7 ) ;
F_25 ( 0x61 , 1 ) ;
V_29 = F_11 ( 0x203 ) ;
F_25 ( 0x60 , 2 ) ;
F_29 ( L_8 , F_11 ( 0x203 ) , V_29 ) ;
F_25 ( 0x30 , 1 ) ;
}
static inline void F_32 ( int V_33 , int V_34 , int V_35 )
{
int V_29 ;
F_25 ( 7 , 0 ) ;
F_29 ( L_9 ) ;
F_25 ( 0x61 , V_33 & 255 ) ;
V_29 = F_11 ( 0x203 ) ;
F_25 ( 0x60 , V_33 >> 8 ) ;
F_29 ( L_10 , F_11 ( 0x203 ) , V_29 , V_33 ) ;
F_25 ( 0x70 , V_34 ) ;
F_29 ( L_11 , F_11 ( 0x203 ) , V_34 ) ;
F_25 ( 0x74 , V_35 ) ;
F_29 ( L_12 , F_11 ( 0x203 ) , V_35 ) ;
F_25 ( 0x30 , 1 ) ;
}
static inline void F_33 ( int V_36 , int V_37 , int V_34 , int V_35 )
{
int V_29 ;
F_25 ( 7 , 1 ) ;
F_29 ( L_13 ) ;
F_25 ( 0x61 , V_36 & 255 ) ;
V_29 = F_11 ( 0x203 ) ;
F_25 ( 0x60 , V_36 >> 8 ) ;
F_29 ( L_10 , F_11 ( 0x203 ) , V_29 , V_36 ) ;
F_29 ( L_14 ) ;
F_25 ( 0x70 , V_34 ) ;
F_29 ( L_15 , F_11 ( 0x203 ) , V_34 ) ;
F_29 ( L_16 ) ;
F_25 ( 0x74 , V_35 ) ;
F_29 ( L_17 , F_11 ( 0x203 ) , V_35 ) ;
F_29 ( L_18 ) ;
F_25 ( 0x63 , V_37 & 255 ) ;
V_29 = F_11 ( 0x203 ) ;
F_25 ( 0x62 , V_37 >> 8 ) ;
F_29 ( L_19 , F_11 ( 0x203 ) , V_29 , V_37 ) ;
F_25 ( 0x30 , 1 ) ;
}
static void F_34 ( void )
{
int V_29 ;
F_2 ( 1 , 0x226 ) ;
F_27 ( 3 ) ;
F_2 ( 0 , 0x226 ) ;
for ( V_29 = 0 ; V_29 < 5 ; V_29 ++ ) {
if ( F_11 ( 0x22e ) & 0x80 )
break;
F_26 ( 1 ) ;
}
if ( V_29 == 5 )
F_35 ( L_20 ) ;
F_29 ( L_21 , F_11 ( 0x22a ) ) ;
for ( V_29 = 0 ; V_29 < 5 ; V_29 ++ ) {
if ( ( F_11 ( 0x22c ) & 0x80 ) == 0 )
break;
F_26 ( 1 ) ;
}
if ( V_29 == 5 )
F_35 ( L_22 ) ;
else {
F_2 ( 0xe1 , 0x22c ) ;
F_29 ( L_23 ) ;
V_29 = F_11 ( 0x22a ) ;
F_27 ( 1 ) ;
V_29 |= F_11 ( 0x22a ) << 8 ;
F_29 ( L_24 , V_29 ) ;
for ( V_29 = 0 ; V_29 < 5 ; V_29 ++ ) {
if ( ( F_11 ( 0x22c ) & 0x80 ) == 0 )
break;
F_26 ( 1 ) ;
}
if ( V_29 == 5 )
F_35 ( L_25 ) ;
F_2 ( 0xd3 , 0x22c ) ;
}
F_2 ( 5 , 0x38a ) ;
F_2 ( 1 , 0x38b ) ;
}
static void T_1 F_36 ( void )
{
F_24 () ;
F_28 () ;
F_30 () ;
F_31 () ;
F_32 ( 0x250 , 3 , 7 ) ;
F_33 ( 0x220 , 0x388 , 3 , 1 ) ;
F_34 () ;
}
static int T_1 F_37 ( void )
{
if ( F_38 () ) {
F_20 () ;
F_23 () ;
F_36 () ;
}
return 0 ;
}
static void T_1
F_39 ( struct V_38 * V_39 , char * * V_40 , struct V_41 * V_42 )
{
#ifdef F_40
extern int V_43 ;
V_43 = 1 ;
#endif
}
static void F_41 ( enum V_44 V_45 , const char * V_46 )
{
if ( V_45 == V_47 ) {
F_42 ( 0x41000000 ) ;
} else {
F_43 () ;
F_44 () ;
F_2 ( 0x87 , 0x370 ) ;
F_2 ( 0x87 , 0x370 ) ;
F_2 ( 0x07 , 0x370 ) ;
F_2 ( 0x07 , 0x371 ) ;
F_2 ( 0xe6 , 0x370 ) ;
F_2 ( 0x00 , 0x371 ) ;
F_2 ( 0xc4 , 0x338 ) ;
}
}
static void F_45 ( struct V_48 * V_49 ,
enum V_50 V_51 )
{
struct V_52 * V_53 = F_46 ( V_49 ,
struct V_52 , V_49 ) ;
unsigned long V_14 ;
T_2 V_1 ;
F_18 ( & V_17 , V_14 ) ;
V_1 = F_10 () ;
if ( V_51 != V_54 )
V_1 &= ~ V_53 -> V_3 ;
else
V_1 |= V_53 -> V_3 ;
F_6 ( V_53 -> V_3 , V_1 ) ;
F_19 ( & V_17 , V_14 ) ;
}
static enum V_50 F_47 ( struct V_48 * V_49 )
{
struct V_52 * V_53 = F_46 ( V_49 ,
struct V_52 , V_49 ) ;
unsigned long V_14 ;
T_2 V_1 ;
F_18 ( & V_17 , V_14 ) ;
V_1 = F_10 () ;
F_19 ( & V_17 , V_14 ) ;
return ( V_1 & V_53 -> V_3 ) ? V_54 : V_55 ;
}
static int T_1 F_48 ( void )
{
int V_29 ;
if ( ! F_38 () )
return - V_56 ;
for ( V_29 = 0 ; V_29 < F_49 ( V_57 ) ; V_29 ++ ) {
struct V_52 * V_53 ;
V_53 = F_50 ( sizeof( * V_53 ) , V_58 ) ;
if ( ! V_53 )
break;
V_53 -> V_49 . V_59 = V_57 [ V_29 ] . V_59 ;
V_53 -> V_49 . V_60 = F_45 ;
V_53 -> V_49 . V_61 = F_47 ;
V_53 -> V_49 . V_62 = V_57 [ V_29 ] . V_63 ;
if ( V_29 == 0 )
V_53 -> V_3 = V_64 ;
else
V_53 -> V_3 = V_18 ;
if ( F_51 ( NULL , & V_53 -> V_49 ) < 0 ) {
F_52 ( V_53 ) ;
break;
}
}
return 0 ;
}
