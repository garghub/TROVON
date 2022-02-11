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
struct V_28 * F_9 ( struct V_28 * V_29 )
{
T_3 V_30 ;
T_4 V_31 , V_32 ;
unsigned V_33 ;
if ( V_17 . V_34 != V_35 )
return NULL ;
if ( V_17 . V_18 < 0x10 )
return NULL ;
V_30 = V_36 ;
F_10 ( V_30 , V_32 ) ;
if ( ! ( V_32 & V_37 ) )
return NULL ;
V_31 = V_32 & ( V_38 << V_39 ) ;
V_33 = ( V_32 >> V_40 ) &
V_41 ;
V_29 -> V_19 = V_42 ;
V_29 -> V_43 = V_31 ;
V_29 -> V_44 = V_31 + ( 1ULL << ( V_33 + 20 ) ) - 1 ;
return V_29 ;
}
int F_11 ( int V_45 )
{
struct V_1 * V_10 = F_7 ( F_12 ( V_45 ) ) -> V_10 ;
unsigned int V_46 ;
int V_47 ;
if ( ! F_13 ( V_24 ) )
return 0 ;
F_14 ( V_10 , 0x1d4 , & V_46 ) ;
V_47 = F_15 ( V_45 ) . V_48 ;
return ( V_46 >> ( 4 * V_47 ) ) & 0xf ;
}
int F_16 ( int V_45 , int V_46 )
{
static unsigned int V_49 , V_50 ;
struct V_7 * V_8 = F_7 ( F_12 ( V_45 ) ) ;
unsigned int V_51 ;
int V_47 ;
if ( ! F_13 ( V_24 ) || V_46 > 0xf )
return - V_52 ;
if ( V_49 == 0 ) {
F_14 ( V_8 -> V_10 , 0x1d4 , & V_49 ) ;
F_14 ( V_8 -> V_9 , 0x1b8 , & V_50 ) ;
V_50 &= 0x180000 ;
}
if ( V_46 != 0xf ) {
F_14 ( V_8 -> V_9 , 0x1b8 , & V_51 ) ;
F_17 ( V_8 -> V_9 , 0x1b8 , V_51 & ~ 0x180000 ) ;
}
V_47 = F_15 ( V_45 ) . V_48 ;
V_46 <<= 4 * V_47 ;
V_46 |= ( 0xf ^ ( 1 << V_47 ) ) << 26 ;
F_17 ( V_8 -> V_10 , 0x1d4 , V_46 ) ;
F_14 ( V_8 -> V_10 , 0x1d4 , & V_51 ) ;
if ( V_51 == V_49 ) {
F_14 ( V_8 -> V_9 , 0x1b8 , & V_51 ) ;
V_51 &= ~ 0x180000 ;
F_17 ( V_8 -> V_9 , 0x1b8 , V_51 | V_50 ) ;
}
return 0 ;
}
static int F_18 ( void )
{
T_1 V_6 ;
if ( ! F_13 ( V_20 ) )
return 0 ;
V_53 = F_19 ( F_5 () * sizeof( T_3 ) , V_12 ) ;
if ( ! V_53 ) {
V_14 . V_19 &= ~ V_20 ;
return - V_13 ;
}
for ( V_6 = 0 ; V_6 != F_5 () ; V_6 ++ )
F_14 ( F_7 ( V_6 ) -> V_9 , 0x9c ,
& V_53 [ V_6 ] ) ;
return 0 ;
}
void F_20 ( void )
{
int V_54 , V_6 ;
unsigned long V_19 ;
static F_21 ( V_55 ) ;
if ( ! F_13 ( V_20 ) )
return;
F_22 ( & V_55 , V_19 ) ;
V_54 = 0 ;
for ( V_6 = 0 ; V_6 < F_5 () ; V_6 ++ ) {
F_17 ( F_7 ( V_6 ) -> V_9 , 0x9c ,
V_53 [ V_6 ] | 1 ) ;
V_54 ++ ;
}
for ( V_6 = 0 ; V_6 < F_5 () ; V_6 ++ ) {
T_3 V_56 ;
for (; ; ) {
F_14 ( F_7 ( V_6 ) -> V_9 ,
0x9c , & V_56 ) ;
if ( ! ( V_56 & 1 ) )
break;
F_23 () ;
}
}
F_24 ( & V_55 , V_19 ) ;
if ( ! V_54 )
F_25 ( L_1 ) ;
}
static T_2 int F_26 ( void )
{
int V_57 = 0 ;
V_57 = F_4 () ;
if ( V_57 < 0 )
F_25 ( V_58 L_2 ) ;
if ( F_18 () < 0 )
F_25 ( V_58 L_3
L_4 ) ;
return V_57 ;
}
