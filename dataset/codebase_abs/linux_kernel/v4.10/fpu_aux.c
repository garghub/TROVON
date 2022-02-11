static void F_1 ( void )
{
}
static void F_2 ( void )
{
V_1 &=
~ ( V_2 | V_3 | V_4 | V_5 |
V_6 | V_7 | V_8 | V_9 |
V_10 ) ;
V_11 = 1 ;
}
void F_3 ( struct V_12 * V_13 )
{
struct V_14 * V_15 , * V_16 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_17 = 0x037f ;
V_13 -> V_18 = 0 ;
V_13 -> V_19 = 0 ;
V_13 -> V_20 = 0xffff ;
V_15 = (struct V_14 * ) & V_13 -> V_21 ;
V_15 -> V_22 = 0 ;
V_15 -> V_23 = 0 ;
V_16 = (struct V_14 * ) & V_13 -> V_24 ;
V_16 -> V_22 = 0 ;
V_16 -> V_23 = 0 ;
V_16 -> V_25 = 0 ;
V_13 -> V_26 = 1 ;
}
void F_4 ( void )
{
F_3 ( & V_27 -> V_28 . V_29 . V_30 . V_13 ) ;
}
void F_5 ( void )
{
( V_31 [ V_32 ] ) ( ) ;
}
static void F_6 ( void )
{
* ( short * ) & V_33 = F_7 () ;
V_11 = 1 ;
}
void F_8 ( void )
{
( V_34 [ V_32 ] ) ( ) ;
}
void F_9 ( void )
{
( V_35 [ V_32 ] ) ( ) ;
}
void F_10 ( void )
{
T_1 * V_36 ;
int V_37 ;
T_2 V_38 ;
if ( V_39 ) {
F_11 () ;
return;
}
V_37 = V_32 ;
if ( F_12 ( V_37 ) ) {
F_13 ( & F_14 ( V_37 ) , V_36 ) ;
V_38 = F_15 ( V_37 ) ;
F_16 () ;
F_17 ( V_38 ) ;
} else {
if ( V_40 & V_41 ) {
F_18 () ;
} else
F_19 ( V_42 ) ;
}
}
void F_20 ( void )
{
T_1 V_43 ;
int V_37 = V_32 ;
T_1 * V_44 = & F_14 ( 0 ) , * V_45 = & F_14 ( V_37 ) ;
long V_46 = V_47 ;
int V_48 = V_49 & 7 , V_50 = ( ( V_48 + V_37 ) & 7 ) ;
T_2 V_51 = ( V_46 >> ( V_48 * 2 ) ) & 3 ;
T_2 V_52 = ( V_46 >> ( V_50 * 2 ) ) & 3 ;
if ( V_51 == V_53 ) {
if ( V_52 == V_53 ) {
F_18 () ;
F_21 ( V_37 ) ;
return;
}
if ( V_40 & V_41 ) {
F_22 ( V_45 , V_52 ) ;
}
F_21 ( V_37 ) ;
return;
}
if ( V_52 == V_53 ) {
if ( V_40 & V_41 ) {
F_23 ( V_44 , V_51 , V_37 ) ;
}
F_18 () ;
return;
}
F_24 () ;
F_13 ( V_44 , & V_43 ) ;
F_13 ( V_45 , V_44 ) ;
F_13 ( & V_43 , V_45 ) ;
V_46 &= ~ ( 3 << ( V_48 * 2 ) ) & ~ ( 3 << ( V_50 * 2 ) ) ;
V_46 |= ( V_52 << ( V_48 * 2 ) ) | ( V_51 << ( V_50 * 2 ) ) ;
V_47 = V_46 ;
}
static void F_25 ( void )
{
int V_37 = V_32 ;
T_1 * V_44 = & F_14 ( 0 ) ;
T_1 * V_45 = & F_14 ( V_37 ) ;
long V_46 = V_47 ;
int V_48 = V_49 & 7 ;
int V_50 = ( V_49 + V_37 ) & 7 ;
T_2 V_52 = ( V_46 >> ( V_50 * 2 ) ) & 3 ;
if ( V_52 == V_53 ) {
F_18 () ;
F_24 () ;
return;
}
F_13 ( V_45 , V_44 ) ;
V_46 &= ~ ( 3 << ( V_48 * 2 ) ) ;
V_46 |= ( V_52 << ( V_48 * 2 ) ) ;
V_47 = V_46 ;
}
void F_26 ( void )
{
if ( V_54 & V_55 )
F_25 () ;
}
void F_27 ( void )
{
if ( V_54 & V_56 )
F_25 () ;
}
void F_28 ( void )
{
if ( V_54 & ( V_55 | V_56 ) )
F_25 () ;
}
void F_29 ( void )
{
if ( V_54 & V_57 )
F_25 () ;
}
void F_30 ( void )
{
if ( ! ( V_54 & V_55 ) )
F_25 () ;
}
void F_31 ( void )
{
if ( ! ( V_54 & V_56 ) )
F_25 () ;
}
void F_32 ( void )
{
if ( ! ( V_54 & ( V_55 | V_56 ) ) )
F_25 () ;
}
void F_33 ( void )
{
if ( ! ( V_54 & V_57 ) )
F_25 () ;
}
void F_34 ( void )
{
F_35 ( V_32 , V_53 ) ;
}
void F_36 ( void )
{
F_35 ( V_32 , V_53 ) ;
F_37 () ;
}
void F_38 ( void )
{
F_23 ( & F_14 ( 0 ) , F_39 () , V_32 ) ;
}
void F_40 ( void )
{
F_23 ( & F_14 ( 0 ) , F_39 () , V_32 ) ;
F_37 () ;
}
