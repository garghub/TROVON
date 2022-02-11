static struct V_1 * F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
do {
V_2 = F_2 ( V_5 , V_5 , V_2 ) ;
if ( ! V_2 )
break;
} while ( ! F_3 ( V_4 , V_2 ) );
return V_2 ;
}
int F_4 ( void )
{
T_1 V_6 = 0 ;
struct V_7 * V_8 ;
struct V_1 * V_9 , * V_10 ;
if ( F_5 () )
return 0 ;
V_9 = NULL ;
while ( ( V_9 = F_1 ( V_9 , V_11 ) ) != NULL )
V_6 ++ ;
if ( V_6 == 0 )
return 0 ;
V_8 = F_6 ( V_6 * sizeof( struct V_7 ) , V_12 ) ;
if ( ! V_8 )
return - V_13 ;
V_14 . V_8 = V_8 ;
V_14 . V_15 = V_6 ;
V_10 = V_9 = NULL ;
for ( V_6 = 0 ; V_6 != F_5 () ; V_6 ++ ) {
F_7 ( V_6 ) -> V_9 = V_9 =
F_1 ( V_9 , V_11 ) ;
F_7 ( V_6 ) -> V_10 = V_10 =
F_1 ( V_10 , V_16 ) ;
}
if ( V_17 . V_18 == 0xf || V_17 . V_18 == 0x10 ||
V_17 . V_18 == 0x15 )
V_14 . V_19 |= V_20 ;
if ( V_17 . V_18 == 0x10 &&
V_17 . V_21 >= 0x8 &&
( V_17 . V_21 > 0x9 ||
V_17 . V_22 >= 0x1 ) )
V_14 . V_19 |= V_23 ;
if ( V_17 . V_18 == 0x15 )
V_14 . V_19 |= V_23 ;
if ( V_17 . V_18 == 0x15 )
V_14 . V_19 |= V_24 ;
return 0 ;
}
bool T_2 F_8 ( T_3 V_25 )
{
const struct V_3 * V_26 ;
T_3 V_27 = V_25 & 0xffff ;
V_25 >>= 16 ;
for ( V_26 = V_11 ; V_26 -> V_27 ; V_26 ++ )
if ( V_27 == V_26 -> V_27 && V_25 == V_26 -> V_25 )
return true ;
return false ;
}
int F_9 ( int V_28 )
{
struct V_1 * V_10 = F_7 ( F_10 ( V_28 ) ) -> V_10 ;
unsigned int V_29 ;
int V_30 = 0 ;
if ( ! F_11 ( V_24 ) )
return 0 ;
F_12 ( V_10 , 0x1d4 , & V_29 ) ;
#ifdef F_13
V_30 = F_14 ( V_28 ) . V_31 ;
#endif
return ( V_29 >> ( 4 * V_30 ) ) & 0xf ;
}
int F_15 ( int V_28 , int V_29 )
{
static unsigned int V_32 , V_33 ;
struct V_7 * V_8 = F_7 ( F_10 ( V_28 ) ) ;
unsigned int V_34 ;
int V_30 = 0 ;
if ( ! F_11 ( V_24 ) || V_29 > 0xf )
return - V_35 ;
if ( V_32 == 0 ) {
F_12 ( V_8 -> V_10 , 0x1d4 , & V_32 ) ;
F_12 ( V_8 -> V_9 , 0x1b8 , & V_33 ) ;
V_33 &= 0x180000 ;
}
if ( V_29 != 0xf ) {
F_12 ( V_8 -> V_9 , 0x1b8 , & V_34 ) ;
F_16 ( V_8 -> V_9 , 0x1b8 , V_34 & ~ 0x180000 ) ;
}
#ifdef F_13
V_30 = F_14 ( V_28 ) . V_31 ;
#endif
V_29 <<= 4 * V_30 ;
V_29 |= ( 0xf ^ ( 1 << V_30 ) ) << 26 ;
F_16 ( V_8 -> V_10 , 0x1d4 , V_29 ) ;
F_12 ( V_8 -> V_10 , 0x1d4 , & V_34 ) ;
if ( V_34 == V_32 ) {
F_12 ( V_8 -> V_9 , 0x1b8 , & V_34 ) ;
V_34 &= ~ 0x180000 ;
F_16 ( V_8 -> V_9 , 0x1b8 , V_34 | V_33 ) ;
}
return 0 ;
}
static int F_17 ( void )
{
T_1 V_6 ;
if ( ! F_11 ( V_20 ) )
return 0 ;
V_36 = F_18 ( F_5 () * sizeof( T_3 ) , V_12 ) ;
if ( ! V_36 ) {
V_14 . V_19 &= ~ V_20 ;
return - V_13 ;
}
for ( V_6 = 0 ; V_6 != F_5 () ; V_6 ++ )
F_12 ( F_7 ( V_6 ) -> V_9 , 0x9c ,
& V_36 [ V_6 ] ) ;
return 0 ;
}
void F_19 ( void )
{
int V_37 , V_6 ;
unsigned long V_19 ;
static F_20 ( V_38 ) ;
if ( ! F_11 ( V_20 ) )
return;
F_21 ( & V_38 , V_19 ) ;
V_37 = 0 ;
for ( V_6 = 0 ; V_6 < F_5 () ; V_6 ++ ) {
F_16 ( F_7 ( V_6 ) -> V_9 , 0x9c ,
V_36 [ V_6 ] | 1 ) ;
V_37 ++ ;
}
for ( V_6 = 0 ; V_6 < F_5 () ; V_6 ++ ) {
T_3 V_39 ;
for (; ; ) {
F_12 ( F_7 ( V_6 ) -> V_9 ,
0x9c , & V_39 ) ;
if ( ! ( V_39 & 1 ) )
break;
F_22 () ;
}
}
F_23 ( & V_38 , V_19 ) ;
if ( ! V_37 )
F_24 ( L_1 ) ;
}
static T_2 int F_25 ( void )
{
int V_40 = 0 ;
V_40 = F_4 () ;
if ( V_40 < 0 )
F_24 ( V_41 L_2 ) ;
if ( F_17 () < 0 )
F_24 ( V_41 L_3
L_4 ) ;
return V_40 ;
}
