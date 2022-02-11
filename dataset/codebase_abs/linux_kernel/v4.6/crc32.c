T_1 T_2 F_1 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , NULL , V_4 ) ;
}
T_1 T_2 F_3 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , NULL , V_5 ) ;
}
T_1 T_2 F_1 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_2 ( V_1 , V_2 , V_3 ,
( const T_1 ( * ) [ 256 ] ) V_6 , V_4 ) ;
}
T_1 T_2 F_3 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_2 ( V_1 , V_2 , V_3 ,
( const T_1 ( * ) [ 256 ] ) V_7 , V_5 ) ;
}
static T_1 T_4 F_4 ( T_1 V_8 , T_1 V_9 , T_1 V_10 )
{
T_1 V_11 = V_8 & 1 ? V_9 : 0 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 31 ; V_12 ++ ) {
V_11 = ( V_11 >> 1 ) ^ ( V_11 & 1 ? V_10 : 0 ) ;
V_8 >>= 1 ;
V_11 ^= V_8 & 1 ? V_9 : 0 ;
}
return V_11 ;
}
static T_1 T_4 F_5 ( T_1 V_1 , T_3 V_3 ,
T_1 V_13 )
{
T_1 V_14 = V_13 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 8 * ( int ) ( V_3 & 3 ) ; V_12 ++ )
V_1 = ( V_1 >> 1 ) ^ ( V_1 & 1 ? V_13 : 0 ) ;
V_3 >>= 2 ;
if ( ! V_3 )
return V_1 ;
for (; ; ) {
if ( V_3 & 1 )
V_1 = F_4 ( V_1 , V_14 , V_13 ) ;
V_3 >>= 1 ;
if ( ! V_3 )
break;
V_14 = F_4 ( V_14 , V_14 , V_13 ) ;
}
return V_1 ;
}
T_1 T_4 F_6 ( T_1 V_1 , T_3 V_3 )
{
return F_5 ( V_1 , V_3 , V_4 ) ;
}
T_1 T_4 F_7 ( T_1 V_1 , T_3 V_3 )
{
return F_5 ( V_1 , V_3 , V_5 ) ;
}
T_1 T_2 F_8 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_9 ( V_1 , V_2 , V_3 , NULL , V_15 ) ;
}
T_1 T_2 F_8 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_9 ( V_1 , V_2 , V_3 ,
( const T_1 ( * ) [ 256 ] ) V_16 , V_15 ) ;
}
static int T_5 F_10 ( void )
{
int V_12 ;
int V_17 = 0 ;
int V_18 = 0 ;
struct V_19 V_20 , V_21 ;
T_6 V_22 ;
unsigned long V_23 ;
static T_1 V_1 ;
for ( V_12 = 0 ; V_12 < 100 ; V_12 ++ ) {
V_18 += 2 * V_24 [ V_12 ] . V_25 ;
V_1 ^= F_3 ( V_24 [ V_12 ] . V_1 , V_26 +
V_24 [ V_12 ] . V_20 , V_24 [ V_12 ] . V_25 ) ;
}
F_11 ( V_23 ) ;
F_12 () ;
F_13 ( & V_20 ) ;
for ( V_12 = 0 ; V_12 < 100 ; V_12 ++ ) {
if ( V_24 [ V_12 ] . V_27 != F_3 ( V_24 [ V_12 ] . V_1 , V_26 +
V_24 [ V_12 ] . V_20 , V_24 [ V_12 ] . V_25 ) )
V_17 ++ ;
}
F_13 ( & V_21 ) ;
F_14 ( V_23 ) ;
F_15 () ;
V_22 = V_21 . V_28 - V_20 . V_28 +
1000000000 * ( V_21 . V_29 - V_20 . V_29 ) ;
F_16 ( L_1 , V_30 ) ;
if ( V_17 )
F_17 ( L_2 , V_17 ) ;
else {
F_16 ( L_3 ,
V_18 , V_22 ) ;
}
return 0 ;
}
static int T_5 F_18 ( void )
{
int V_12 , V_31 ;
int V_17 = 0 , V_32 = 0 ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
T_1 V_33 ;
V_33 = F_3 ( V_24 [ V_12 ] . V_1 , V_26 + V_24 [ V_12 ] . V_20 ,
V_24 [ V_12 ] . V_25 ) ;
for ( V_31 = 0 ; V_31 <= V_24 [ V_12 ] . V_25 ; ++ V_31 ) {
T_1 V_34 , V_35 ;
T_1 V_36 = V_31 , V_37 = V_24 [ V_12 ] . V_25 - V_31 ;
V_34 = F_3 ( V_24 [ V_12 ] . V_1 , V_26 +
V_24 [ V_12 ] . V_20 , V_36 ) ;
V_35 = F_3 ( 0 , V_26 + V_24 [ V_12 ] . V_20 +
V_36 , V_37 ) ;
if ( ! ( V_33 == F_19 ( V_34 , V_35 , V_37 ) &&
V_33 == V_24 [ V_12 ] . V_27 ) )
V_17 ++ ;
V_32 ++ ;
F_20 () ;
}
}
if ( V_17 )
F_17 ( L_4 , V_17 , V_32 ) ;
else
F_16 ( L_5 , V_32 ) ;
return 0 ;
}
static int T_5 F_21 ( void )
{
int V_12 ;
int V_17 = 0 ;
int V_18 = 0 ;
struct V_19 V_20 , V_21 ;
T_6 V_22 ;
unsigned long V_23 ;
static T_1 V_1 ;
for ( V_12 = 0 ; V_12 < 100 ; V_12 ++ ) {
V_18 += 2 * V_24 [ V_12 ] . V_25 ;
V_1 ^= F_1 ( V_24 [ V_12 ] . V_1 , V_26 +
V_24 [ V_12 ] . V_20 , V_24 [ V_12 ] . V_25 ) ;
V_1 ^= F_8 ( V_24 [ V_12 ] . V_1 , V_26 +
V_24 [ V_12 ] . V_20 , V_24 [ V_12 ] . V_25 ) ;
}
F_11 ( V_23 ) ;
F_12 () ;
F_13 ( & V_20 ) ;
for ( V_12 = 0 ; V_12 < 100 ; V_12 ++ ) {
if ( V_24 [ V_12 ] . V_38 != F_1 ( V_24 [ V_12 ] . V_1 , V_26 +
V_24 [ V_12 ] . V_20 , V_24 [ V_12 ] . V_25 ) )
V_17 ++ ;
if ( V_24 [ V_12 ] . V_39 != F_8 ( V_24 [ V_12 ] . V_1 , V_26 +
V_24 [ V_12 ] . V_20 , V_24 [ V_12 ] . V_25 ) )
V_17 ++ ;
}
F_13 ( & V_21 ) ;
F_14 ( V_23 ) ;
F_15 () ;
V_22 = V_21 . V_28 - V_20 . V_28 +
1000000000 * ( V_21 . V_29 - V_20 . V_29 ) ;
F_16 ( L_6 ,
V_30 , V_40 ) ;
if ( V_17 )
F_17 ( L_7 , V_17 ) ;
else {
F_16 ( L_8 ,
V_18 , V_22 ) ;
}
return 0 ;
}
static int T_5 F_22 ( void )
{
int V_12 , V_31 ;
int V_17 = 0 , V_32 = 0 ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
T_1 V_33 ;
V_33 = F_1 ( V_24 [ V_12 ] . V_1 , V_26 + V_24 [ V_12 ] . V_20 ,
V_24 [ V_12 ] . V_25 ) ;
for ( V_31 = 0 ; V_31 <= V_24 [ V_12 ] . V_25 ; ++ V_31 ) {
T_1 V_34 , V_35 ;
T_1 V_36 = V_31 , V_37 = V_24 [ V_12 ] . V_25 - V_31 ;
V_34 = F_1 ( V_24 [ V_12 ] . V_1 , V_26 +
V_24 [ V_12 ] . V_20 , V_36 ) ;
V_35 = F_1 ( 0 , V_26 + V_24 [ V_12 ] . V_20 +
V_36 , V_37 ) ;
if ( ! ( V_33 == F_23 ( V_34 , V_35 , V_37 ) &&
V_33 == V_24 [ V_12 ] . V_38 ) )
V_17 ++ ;
V_32 ++ ;
F_20 () ;
}
}
if ( V_17 )
F_17 ( L_9 , V_17 , V_32 ) ;
else
F_16 ( L_10 , V_32 ) ;
return 0 ;
}
static int T_5 F_24 ( void )
{
F_21 () ;
F_10 () ;
F_22 () ;
F_18 () ;
return 0 ;
}
static void T_7 F_25 ( void )
{
}
