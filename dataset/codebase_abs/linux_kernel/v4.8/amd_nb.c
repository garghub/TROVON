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
if ( ! V_6 )
return - V_12 ;
V_8 = F_6 ( V_6 * sizeof( struct V_7 ) , V_13 ) ;
if ( ! V_8 )
return - V_14 ;
V_15 . V_8 = V_8 ;
V_15 . V_16 = V_6 ;
V_10 = V_9 = NULL ;
for ( V_6 = 0 ; V_6 != F_5 () ; V_6 ++ ) {
F_7 ( V_6 ) -> V_9 = V_9 =
F_1 ( V_9 , V_11 ) ;
F_7 ( V_6 ) -> V_10 = V_10 =
F_1 ( V_10 , V_17 ) ;
}
if ( F_8 () )
V_15 . V_18 |= V_19 ;
if ( ! F_9 ( 0x80000006 ) )
return 0 ;
if ( V_20 . V_21 == 0x10 &&
V_20 . V_22 >= 0x8 &&
( V_20 . V_22 > 0x9 ||
V_20 . V_23 >= 0x1 ) )
V_15 . V_18 |= V_24 ;
if ( V_20 . V_21 == 0x15 )
V_15 . V_18 |= V_24 ;
if ( V_20 . V_21 == 0x15 )
V_15 . V_18 |= V_25 ;
return 0 ;
}
bool T_2 F_10 ( T_3 V_26 )
{
const struct V_3 * V_27 ;
T_3 V_28 = V_26 & 0xffff ;
V_26 >>= 16 ;
for ( V_27 = V_11 ; V_27 -> V_28 ; V_27 ++ )
if ( V_28 == V_27 -> V_28 && V_26 == V_27 -> V_26 )
return true ;
return false ;
}
struct V_29 * F_11 ( struct V_29 * V_30 )
{
T_3 V_31 ;
T_4 V_32 , V_33 ;
unsigned V_34 ;
if ( V_20 . V_35 != V_36 )
return NULL ;
if ( V_20 . V_21 < 0x10 )
return NULL ;
V_31 = V_37 ;
F_12 ( V_31 , V_33 ) ;
if ( ! ( V_33 & V_38 ) )
return NULL ;
V_32 = V_33 & ( V_39 << V_40 ) ;
V_34 = ( V_33 >> V_41 ) &
V_42 ;
V_30 -> V_18 = V_43 ;
V_30 -> V_44 = V_32 ;
V_30 -> V_45 = V_32 + ( 1ULL << ( V_34 + 20 ) ) - 1 ;
return V_30 ;
}
int F_13 ( int V_46 )
{
struct V_1 * V_10 = F_7 ( F_14 ( V_46 ) ) -> V_10 ;
unsigned int V_47 ;
if ( ! F_15 ( V_25 ) )
return 0 ;
F_16 ( V_10 , 0x1d4 , & V_47 ) ;
return ( V_47 >> ( 4 * F_17 ( V_46 ) . V_48 ) ) & 0xf ;
}
int F_18 ( int V_46 , unsigned long V_47 )
{
static unsigned int V_49 , V_50 ;
struct V_7 * V_8 = F_7 ( F_14 ( V_46 ) ) ;
unsigned int V_51 ;
int V_52 ;
if ( ! F_15 ( V_25 ) || V_47 > 0xf )
return - V_53 ;
if ( V_49 == 0 ) {
F_16 ( V_8 -> V_10 , 0x1d4 , & V_49 ) ;
F_16 ( V_8 -> V_9 , 0x1b8 , & V_50 ) ;
V_50 &= 0x180000 ;
}
if ( V_47 != 0xf ) {
F_16 ( V_8 -> V_9 , 0x1b8 , & V_51 ) ;
F_19 ( V_8 -> V_9 , 0x1b8 , V_51 & ~ 0x180000 ) ;
}
V_52 = F_17 ( V_46 ) . V_48 ;
V_47 <<= 4 * V_52 ;
V_47 |= ( 0xf ^ ( 1 << V_52 ) ) << 26 ;
F_19 ( V_8 -> V_10 , 0x1d4 , V_47 ) ;
F_16 ( V_8 -> V_10 , 0x1d4 , & V_51 ) ;
if ( V_51 == V_49 ) {
F_16 ( V_8 -> V_9 , 0x1b8 , & V_51 ) ;
V_51 &= ~ 0x180000 ;
F_19 ( V_8 -> V_9 , 0x1b8 , V_51 | V_50 ) ;
}
return 0 ;
}
static void F_20 ( void )
{
T_1 V_6 ;
if ( ! F_15 ( V_19 ) )
return;
V_54 = F_21 ( F_5 () * sizeof( T_3 ) , V_13 ) ;
if ( ! V_54 ) {
V_15 . V_18 &= ~ V_19 ;
F_22 ( L_1 ) ;
return;
}
for ( V_6 = 0 ; V_6 != F_5 () ; V_6 ++ )
F_16 ( F_7 ( V_6 ) -> V_9 , 0x9c , & V_54 [ V_6 ] ) ;
}
void F_23 ( void )
{
int V_55 , V_6 ;
unsigned long V_18 ;
static F_24 ( V_56 ) ;
if ( ! F_15 ( V_19 ) )
return;
F_25 ( & V_56 , V_18 ) ;
V_55 = 0 ;
for ( V_6 = 0 ; V_6 < F_5 () ; V_6 ++ ) {
F_19 ( F_7 ( V_6 ) -> V_9 , 0x9c ,
V_54 [ V_6 ] | 1 ) ;
V_55 ++ ;
}
for ( V_6 = 0 ; V_6 < F_5 () ; V_6 ++ ) {
T_3 V_57 ;
for (; ; ) {
F_16 ( F_7 ( V_6 ) -> V_9 ,
0x9c , & V_57 ) ;
if ( ! ( V_57 & 1 ) )
break;
F_26 () ;
}
}
F_27 ( & V_56 , V_18 ) ;
if ( ! V_55 )
F_22 ( L_2 ) ;
}
static T_2 int F_28 ( void )
{
F_4 () ;
F_20 () ;
return 0 ;
}
