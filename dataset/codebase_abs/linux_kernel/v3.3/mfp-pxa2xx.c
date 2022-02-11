static int F_1 ( unsigned V_1 , unsigned long V_2 )
{
unsigned long V_3 , V_4 = F_2 ( V_1 ) ;
int V_5 = F_3 ( V_1 ) ;
int V_6 = ! ! ( V_1 & 0x10 ) ;
int V_7 = ( V_1 & 0xf ) << 1 ;
int V_8 = F_4 ( V_2 ) ;
int V_9 = ( V_2 & V_10 ) ? 1 : 0 ;
if ( V_8 > 3 )
return - V_11 ;
V_3 = ( V_6 == 0 ) ? F_5 ( V_5 ) : F_6 ( V_5 ) ;
V_3 = ( V_3 & ~ ( 0x3 << V_7 ) ) | ( V_8 << V_7 ) ;
if ( V_6 == 0 )
F_5 ( V_5 ) = V_3 ;
else
F_6 ( V_5 ) = V_3 ;
if ( V_9 ^ V_12 [ V_1 ] . V_13 )
F_7 ( V_1 ) |= V_4 ;
else
F_7 ( V_1 ) &= ~ V_4 ;
switch ( V_2 & V_14 ) {
case V_15 :
F_8 ( V_5 ) |= V_4 ;
V_9 = 1 ;
break;
case V_16 :
F_8 ( V_5 ) &= ~ V_4 ;
V_9 = 1 ;
break;
case V_17 :
case V_18 :
break;
default:
F_9 ( L_1 ,
V_19 , V_1 ) ;
break;
}
if ( V_9 ^ V_12 [ V_1 ] . V_13 )
V_20 [ V_5 ] |= V_4 ;
else
V_20 [ V_5 ] &= ~ V_4 ;
if ( ( V_2 & V_21 ) && ! V_12 [ V_1 ] . V_22 ) {
F_9 ( L_2 ,
V_19 , V_1 ) ;
return - V_11 ;
}
if ( ( V_2 & V_21 ) && V_9 ) {
F_9 ( L_3 ,
V_19 , V_1 ) ;
return - V_11 ;
}
return 0 ;
}
static inline int F_10 ( int V_23 )
{
int V_1 = F_11 ( V_23 ) ;
if ( ( V_23 > V_24 ) || ! V_12 [ V_1 ] . V_25 ) {
F_9 ( L_4 , V_19 , V_1 ) ;
return - 1 ;
}
return V_1 ;
}
void F_12 ( unsigned long * V_26 , int V_27 )
{
unsigned long V_28 ;
unsigned long * V_2 ;
int V_29 , V_1 ;
for ( V_29 = 0 , V_2 = V_26 ; V_29 < V_27 ; V_29 ++ , V_2 ++ ) {
V_1 = F_10 ( F_13 ( * V_2 ) ) ;
if ( V_1 < 0 )
continue;
F_14 ( V_28 ) ;
V_12 [ V_1 ] . V_30 = * V_2 ;
F_1 ( V_1 , * V_2 ) ;
F_15 ( V_28 ) ;
}
}
void F_16 ( int V_23 , unsigned long V_31 )
{
unsigned long V_28 , V_2 ;
int V_1 ;
V_1 = F_10 ( V_23 ) ;
if ( V_1 < 0 )
return;
F_14 ( V_28 ) ;
V_2 = V_12 [ V_1 ] . V_30 ;
V_2 = ( V_2 & ~ V_14 ) | V_31 ;
F_1 ( V_1 , V_2 ) ;
F_15 ( V_28 ) ;
}
int F_17 ( unsigned int V_1 , unsigned int V_32 )
{
struct V_12 * V_33 ;
unsigned long V_2 , V_34 ;
if ( V_1 > F_11 ( V_24 ) )
return - V_11 ;
V_33 = & V_12 [ V_1 ] ;
V_2 = V_33 -> V_30 ;
if ( ! V_33 -> V_25 )
return - V_11 ;
if ( V_33 -> V_35 && ( F_4 ( V_33 -> V_30 ) == 0 ) &&
( V_33 -> V_30 & V_21 ) ) {
if ( V_32 )
V_36 |= V_33 -> V_4 ;
else
V_36 &= ~ V_33 -> V_4 ;
return 0 ;
}
V_34 = ( V_37 & V_33 -> V_38 ) & ( ~ V_33 -> V_4 ) ;
if ( V_32 && V_34 )
return - V_39 ;
if ( V_33 -> V_22 && ( V_2 & V_21 ) ) {
if ( V_32 ) {
V_37 = ( V_37 & ~ V_33 -> V_38 ) | V_33 -> V_4 ;
if ( V_2 & V_40 )
V_41 |= V_33 -> V_4 ;
else
V_41 &= ~ V_33 -> V_4 ;
if ( V_2 & V_42 )
V_43 |= V_33 -> V_4 ;
else
V_43 &= ~ V_33 -> V_4 ;
} else {
V_37 &= ~ V_33 -> V_4 ;
V_41 &= ~ V_33 -> V_4 ;
V_43 &= ~ V_33 -> V_4 ;
}
}
return 0 ;
}
static void T_1 F_18 ( void )
{
int V_29 ;
#ifdef F_19
V_44 = 89 ;
#else
V_44 = 84 ;
#endif
for ( V_29 = 0 ; V_29 <= V_44 ; V_29 ++ )
V_12 [ V_29 ] . V_25 = 1 ;
for ( V_29 = 0 ; V_29 <= 15 ; V_29 ++ ) {
V_12 [ V_29 ] . V_22 = 1 ;
V_12 [ V_29 ] . V_4 = F_2 ( V_29 ) ;
}
for ( V_29 = 86 ; V_29 <= V_44 ; V_29 ++ )
V_12 [ V_29 ] . V_13 = 1 ;
}
static inline void F_18 ( void ) {}
int F_20 ( unsigned int V_32 )
{
unsigned int V_29 , V_1 , V_4 = 0 ;
struct V_12 * V_33 ;
for ( V_29 = 0 ; V_29 < F_21 ( V_45 ) ; V_29 ++ ) {
V_1 = V_45 [ V_29 ] ;
V_33 = & V_12 [ V_1 ] ;
if ( F_4 ( V_33 -> V_30 ) == 0 )
continue;
if ( V_33 -> V_30 & V_21 )
V_4 |= V_12 [ V_1 ] . V_4 ;
}
if ( V_32 )
V_36 |= V_4 ;
else
V_36 &= ~ V_4 ;
return 0 ;
}
static void T_1 F_22 ( void )
{
int V_29 , V_1 ;
V_44 = 120 ;
for ( V_29 = 0 ; V_29 <= V_44 ; V_29 ++ ) {
if ( V_29 == 2 || V_29 == 5 || V_29 == 6 || V_29 == 7 || V_29 == 8 )
continue;
V_12 [ V_29 ] . V_25 = 1 ;
}
for ( V_29 = 0 ; V_29 < F_21 ( V_45 ) ; V_29 ++ ) {
V_1 = V_45 [ V_29 ] ;
V_12 [ V_1 ] . V_22 = 1 ;
V_12 [ V_1 ] . V_35 = 1 ;
V_12 [ V_1 ] . V_4 = 1 << V_29 ;
}
for ( V_29 = 0 ; V_29 <= 15 ; V_29 ++ ) {
if ( F_2 ( V_29 ) & 0x1e4 )
continue;
V_12 [ V_29 ] . V_22 = 1 ;
V_12 [ V_29 ] . V_4 = F_2 ( V_29 ) ;
}
V_12 [ 35 ] . V_22 = 1 ;
V_12 [ 35 ] . V_4 = V_46 ;
F_23 ( V_47 , 31 ) ;
F_23 ( V_47 , 113 ) ;
F_23 ( V_48 , 38 ) ;
F_23 ( V_48 , 53 ) ;
F_23 ( V_48 , 40 ) ;
F_23 ( V_48 , 36 ) ;
}
static inline void F_22 ( void ) {}
static int F_24 ( void )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_44 ; V_29 ++ ) {
if ( ( V_12 [ V_29 ] . V_30 & V_49 ) &&
( F_7 ( V_29 ) & F_2 ( V_29 ) ) ) {
if ( F_25 ( V_29 ) & F_2 ( V_29 ) )
F_8 ( F_3 ( V_29 ) ) |= F_2 ( V_29 ) ;
else
F_8 ( F_3 ( V_29 ) ) &= ~ F_2 ( V_29 ) ;
}
}
for ( V_29 = 0 ; V_29 <= F_3 ( V_44 ) ; V_29 ++ ) {
V_50 [ 0 ] [ V_29 ] = F_5 ( V_29 ) ;
V_50 [ 1 ] [ V_29 ] = F_6 ( V_29 ) ;
V_51 [ V_29 ] = F_7 ( V_29 * 32 ) ;
V_52 [ V_29 ] = F_8 ( V_29 ) ;
F_7 ( V_29 * 32 ) = V_20 [ V_29 ] ;
}
return 0 ;
}
static void F_26 ( void )
{
int V_29 ;
for ( V_29 = 0 ; V_29 <= F_3 ( V_44 ) ; V_29 ++ ) {
F_5 ( V_29 ) = V_50 [ 0 ] [ V_29 ] ;
F_6 ( V_29 ) = V_50 [ 1 ] [ V_29 ] ;
F_7 ( V_29 * 32 ) = V_51 [ V_29 ] ;
F_8 ( V_29 ) = V_52 [ V_29 ] ;
}
V_53 = V_54 | V_55 ;
}
static int T_1 F_27 ( void )
{
int V_29 ;
if ( ! F_28 () )
return 0 ;
if ( F_29 () )
F_18 () ;
if ( F_30 () )
F_22 () ;
V_53 = V_54 ;
for ( V_29 = 0 ; V_29 <= F_3 ( V_44 ) ; V_29 ++ )
V_20 [ V_29 ] = F_7 ( V_29 * 32 ) ;
return 0 ;
}
