static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = V_2 -> V_4 ;
int V_5 = V_2 -> V_5 ;
V_3 = F_2 ( V_4 + 0xd ) ;
V_6 ;
F_3 ( 3 , V_4 + 3 ) ;
F_3 ( 2 , V_4 + 3 ) ;
if ( V_3 & 0x80 )
V_7 ;
}
static int F_4 ( struct V_1 * V_2 , int V_8 , char * V_9 , int V_10 )
{
int V_11 ;
int V_4 = V_2 -> V_4 ;
V_11 = 0 ;
if ( V_8 & 1 ) {
#if V_12
F_5 ( 4 )
if ( V_10 >= 128 && ( F_2 ( V_4 + 8 ) & 2 ) ) {
F_6 ( V_4 + 4 , V_9 , 32 ) ;
V_10 -= 128 ;
V_9 += 128 ;
}
while ( V_10 >= 84 && ! ( V_11 & 0xc0 ) )
if ( ( V_11 = F_2 ( V_4 + 8 ) ) & 4 )
{
F_6 ( V_4 + 4 , V_9 , 21 ) ;
V_10 -= 84 ;
V_9 += 84 ;
}
if ( V_10 >= 44 && ( F_2 ( V_4 + 8 ) & 8 ) ) {
F_6 ( V_4 + 4 , V_9 , 11 ) ;
V_10 -= 44 ;
V_9 += 44 ;
}
#endif
F_5 ( 7 )
V_11 = 0 ;
while ( V_10 && ! ( ( V_11 & 0x10 ) && ( V_11 & 0xc0 ) ) )
{
V_11 &= 0xc0 ;
while ( V_10 && ! ( ( V_11 = F_2 ( V_4 + 8 ) ) & 0x10 ) )
{
* V_9 ++ = F_2 ( V_4 + 4 ) ;
V_10 -- ;
}
if ( V_11 & 0x10 )
V_11 = F_2 ( V_4 + 8 ) ;
}
} else {
#if V_12
F_5 ( 4 )
if ( V_10 >= 128 && F_2 ( V_4 + 8 ) & 0x10 ) {
F_7 ( V_4 + 4 , V_9 , 32 ) ;
V_10 -= 128 ;
V_9 += 128 ;
}
while ( V_10 >= 84 && ! ( V_11 & 0xc0 ) )
if ( ! ( ( V_11 = F_2 ( V_4 + 8 ) ) & 8 ) ) {
F_7 ( V_4 + 4 , V_9 , 21 ) ;
V_10 -= 84 ;
V_9 += 84 ;
}
if ( V_10 >= 40 && ! ( F_2 ( V_4 + 8 ) & 4 ) ) {
F_7 ( V_4 + 4 , V_9 , 10 ) ;
V_10 -= 40 ;
V_9 += 40 ;
}
#endif
F_5 ( 7 )
V_11 = 0 ;
while ( V_10 && ! ( ( V_11 & 2 ) && ( V_11 & 0xc0 ) ) ) {
while ( V_10 && ! ( ( V_11 = F_2 ( V_4 + 8 ) ) & 2 ) )
{
F_3 ( * V_9 ++ , V_4 + 4 ) ;
V_10 -- ;
}
if ( V_11 & 2 )
V_11 = F_2 ( V_4 + 8 ) ;
}
}
return F_2 ( V_4 + 8 ) & 0xc0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_13 ;
int V_4 = V_2 -> V_4 ;
unsigned long V_14 ;
V_13 = 0 ;
V_14 = V_15 + V_16 ;
while ( F_9 ( V_15 , V_14 ) && ! V_2 -> V_17 &&
! ( ( V_13 = F_2 ( V_4 + 4 ) ) & 0xe0 ) ) {
F_10 () ;
F_11 () ;
}
if ( F_12 ( V_15 , V_14 ) )
return ( V_18 ) ;
if ( V_2 -> V_17 )
return ( V_2 -> V_17 == 1 ? V_19 : V_20 ) ;
if ( V_13 & 0x60 )
F_1 ( V_2 ) ;
if ( V_13 & 0x20 )
return ( V_21 ) ;
if ( V_13 & 0x40 )
return ( V_22 ) ;
return 0 ;
}
static void F_13 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_14 ( V_24 ) ;
int V_4 = V_2 -> V_4 ;
int V_5 = V_2 -> V_5 ;
unsigned int V_14 ;
V_2 -> V_17 = 0 ;
V_6 ;
F_2 ( V_4 + 5 ) ;
if ( F_2 ( V_4 + 5 ) )
F_3 ( 2 , V_4 + 3 ) ;
else if ( F_2 ( V_4 + 7 ) & 0x1f )
F_3 ( 1 , V_4 + 3 ) ;
while ( F_2 ( V_4 + 5 ) ) ;
V_7 ;
F_3 ( 1 , V_4 + 8 ) ;
F_3 ( 0 , V_4 + 0xb ) ;
F_2 ( V_4 + 8 ) ;
V_6 ;
F_3 ( 0x40 , V_4 + 0xb ) ;
F_3 ( V_25 , V_4 + 0xc ) ;
F_3 ( 0x40 | V_26 | V_2 -> V_27 , V_4 + 8 ) ;
F_3 ( V_28 , V_4 + 7 ) ;
F_3 ( V_29 , V_4 + 6 ) ;
F_3 ( V_30 , V_4 + 5 ) ;
F_3 ( V_31 & 7 , V_4 + 9 ) ;
F_3 ( F_15 ( V_24 ) , V_4 + 4 ) ;
for ( V_14 = 0 ; V_14 < V_24 -> V_32 ; V_14 ++ )
F_3 ( V_24 -> V_33 [ V_14 ] , V_4 + 2 ) ;
V_2 -> V_34 = V_24 ;
F_3 ( 0x41 , V_4 + 3 ) ;
}
static unsigned int F_16 ( struct V_23 * V_24 )
{
unsigned int V_14 , V_11 ;
unsigned long V_13 ;
unsigned int V_35 ;
unsigned int V_36 ;
unsigned int V_37 ;
unsigned int V_8 ;
unsigned int V_10 ;
char * V_38 ;
struct V_1 * V_2 = F_14 ( V_24 ) ;
int V_4 = V_2 -> V_4 ;
int V_5 = V_2 -> V_5 ;
F_5 ( 1 )
V_11 = F_2 ( V_4 + 6 ) ;
V_14 = F_2 ( V_4 + 5 ) ;
if ( V_14 == 0x20 ) {
return ( V_39 << 16 ) ;
}
V_14 |= F_2 ( V_4 + 5 ) ;
if ( V_14 != 0x18 ) {
F_17 ( V_40 L_1 , V_14 ) ;
F_1 ( V_2 ) ;
return ( V_41 << 16 ) ;
}
V_11 &= 7 ;
if ( V_11 != 3 && V_11 != 4 ) {
F_17 ( V_40 L_2 ,
V_11 , V_14 , F_2 ( V_4 + 7 ) & 0x1f ) ;
F_1 ( V_2 ) ;
return ( V_22 << 16 ) ;
}
V_35 = V_42 ;
if ( F_2 ( V_4 + 7 ) & 0x1f )
F_3 ( 1 , V_4 + 3 ) ;
V_10 = F_18 ( V_24 ) ;
if ( V_10 && ! ( ( V_8 = F_2 ( V_4 + 4 ) ) & 6 ) ) {
struct V_43 * V_44 ;
F_5 ( 2 )
F_3 ( V_10 , V_4 ) ;
F_3 ( V_10 >> 8 , V_4 + 1 ) ;
F_3 ( V_10 >> 16 , V_4 + 0xe ) ;
F_3 ( 0x90 , V_4 + 3 ) ;
V_7 ;
F_19 (cmd, sg, scsi_sg_count(cmd), i) {
if ( V_2 -> V_17 ) {
V_6 ;
return ( ( V_2 -> V_17 == 1 ?
V_19 : V_20 ) << 16 ) ;
}
V_38 = F_20 ( V_44 ) ;
if ( F_4 ( V_2 , V_8 , V_38 , V_44 -> V_45 ) )
break;
}
V_6 ;
F_5 ( 2 )
if ( ( V_13 = F_8 ( V_2 ) ) )
return ( V_13 << 16 ) ;
V_13 = F_2 ( V_4 + 5 ) ;
}
V_13 = V_15 + V_16 ;
while ( F_9 ( V_15 , V_13 ) && ! V_2 -> V_17 &&
! ( F_2 ( V_4 + 4 ) & 6 ) )
F_11 () ;
if ( F_12 ( V_15 , V_13 ) ) {
F_1 ( V_2 ) ;
return ( V_18 << 16 ) ;
}
while ( F_2 ( V_4 + 5 ) )
F_11 () ;
if ( V_2 -> V_17 )
return ( ( V_2 -> V_17 == 1 ? V_19 : V_20 ) << 16 ) ;
F_3 ( 0x11 , V_4 + 3 ) ;
if ( ( V_13 = F_8 ( V_2 ) ) )
return ( V_13 << 16 ) ;
V_14 = F_2 ( V_4 + 5 ) ;
V_11 = F_2 ( V_4 + 7 ) & 0x1f ;
V_36 = F_2 ( V_4 + 2 ) ;
V_37 = F_2 ( V_4 + 2 ) ;
if ( ! ( ( V_14 == 8 && V_11 == 2 ) || ( V_14 == 0x10 && V_11 == 1 ) ) ) {
F_17 ( V_40 L_3 , V_14 , V_11 ) ;
V_35 = V_22 ;
}
F_3 ( 0x12 , V_4 + 3 ) ;
F_5 ( 1 )
if ( ( V_13 = F_8 ( V_2 ) ) )
return ( V_13 << 16 ) ;
V_14 = F_2 ( V_4 + 5 ) ;
while ( ! V_2 -> V_17 && ( ( V_14 & 0x20 ) != 0x20 ) ) {
F_10 () ;
F_11 () ;
V_14 |= F_2 ( V_4 + 5 ) ;
}
F_5 ( 0 )
if ( V_2 -> V_17 )
return ( ( V_2 -> V_17 == 1 ? V_19 : V_20 ) << 16 ) ;
return ( V_35 << 16 ) | ( V_37 << 8 ) | ( V_36 & V_46 ) ;
}
static void F_21 ( void * V_47 )
{
struct V_23 * V_48 ;
struct V_49 * V_50 = V_47 ;
struct V_1 * V_2 = F_22 ( V_50 ) ;
int V_4 = V_2 -> V_4 ;
V_6 ;
if ( ! ( F_2 ( V_4 + 4 ) & 0x80 ) )
return;
if ( V_2 -> V_34 == NULL ) {
int V_14 ;
V_14 = 16 ;
while ( V_14 -- && F_2 ( V_4 + 5 ) ) ;
return;
}
V_48 = V_2 -> V_34 ;
V_48 -> V_35 = F_16 ( V_48 ) ;
V_2 -> V_34 = NULL ;
( V_48 -> V_51 ) ( V_48 ) ;
}
T_1 F_23 ( int V_52 , void * V_47 )
{
unsigned long V_53 ;
struct V_49 * V_50 = V_47 ;
F_24 ( V_50 -> V_54 , V_53 ) ;
F_21 ( V_47 ) ;
F_25 ( V_50 -> V_54 , V_53 ) ;
return V_55 ;
}
static int F_26 ( struct V_23 * V_24 ,
void (* F_27) ( struct V_23 * ) )
{
struct V_1 * V_2 = F_14 ( V_24 ) ;
if ( F_15 ( V_24 ) == V_2 -> V_27 ) {
V_24 -> V_35 = V_56 << 16 ;
F_27 ( V_24 ) ;
return 0 ;
}
V_24 -> V_51 = F_27 ;
while ( V_2 -> V_34 != NULL ) {
F_10 () ;
F_11 () ;
}
F_13 ( V_24 ) ;
return 0 ;
}
int F_28 ( struct V_57 * V_58 , struct V_59 * V_60 ,
T_2 V_61 , int V_62 [] )
{
V_62 [ 0 ] = 0x40 ;
V_62 [ 1 ] = 0x20 ;
V_62 [ 2 ] = ( unsigned long ) V_61 / ( V_62 [ 0 ] * V_62 [ 1 ] ) ;
if ( V_62 [ 2 ] > 1024 ) {
V_62 [ 0 ] = 0xff ;
V_62 [ 1 ] = 0x3f ;
V_62 [ 2 ] = ( unsigned long ) V_61 / ( V_62 [ 0 ] * V_62 [ 1 ] ) ;
#if 0
if (ip[2] > 1023)
ip[2] = 1023;
#endif
}
return 0 ;
}
int F_29 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_14 ( V_24 ) ;
V_2 -> V_17 = 1 ;
F_1 ( V_2 ) ;
return V_63 ;
}
int F_30 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_14 ( V_24 ) ;
unsigned long V_53 ;
V_2 -> V_17 = 2 ;
F_24 ( V_24 -> V_64 -> V_50 -> V_54 , V_53 ) ;
F_1 ( V_2 ) ;
F_25 ( V_24 -> V_64 -> V_50 -> V_54 , V_53 ) ;
return V_63 ;
}
const char * F_31 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_22 ( V_50 ) ;
return V_2 -> V_65 ;
}
int F_32 ( int V_4 , int V_5 )
{
V_7 ;
return F_2 ( V_4 + 0xe ) & 0xf8 ;
}
void F_33 ( int V_4 , int V_66 , int V_5 )
{
F_3 ( 1 , V_4 + 8 ) ;
V_6 ;
F_3 ( 0x40 | V_26 | V_66 , V_4 + 8 ) ;
F_3 ( V_30 , V_4 + 5 ) ;
F_3 ( V_31 , V_4 + 9 ) ;
#if V_67
F_3 ( 3 , V_4 + 3 ) ;
V_7 ;
while ( F_2 ( V_4 + 0xf ) & 4 )
F_11 () ;
V_6 ;
#endif
}
int F_34 ( int V_4 , int V_5 )
{
V_7 ;
return ( ( ( F_2 ( V_4 + 0xe ) ^ F_2 ( V_4 + 0xe ) ) == 7 ) &&
( ( F_2 ( V_4 + 0xe ) ^ F_2 ( V_4 + 0xe ) ) == 7 ) ) ;
}
void F_35 ( struct V_1 * V_2 )
{
int V_4 = V_2 -> V_4 ;
int V_5 = V_2 -> V_5 ;
V_7 ;
F_3 ( 0 , V_4 + 0xb ) ;
}
static int T_3 F_36 ( void )
{
return 0 ;
}
static void T_4 F_37 ( void )
{
}
