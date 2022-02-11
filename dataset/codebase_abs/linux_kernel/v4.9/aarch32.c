bool F_1 ( const struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
int V_5 ;
if ( F_2 ( V_2 ) >> 30 )
return true ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 == 0xE )
return true ;
V_3 = * F_4 ( V_2 ) ;
if ( V_5 < 0 ) {
unsigned long V_6 ;
V_6 = ( ( V_3 >> 8 ) & 0xFC ) | ( ( V_3 >> 25 ) & 0x3 ) ;
if ( V_6 == 0 )
return true ;
V_5 = ( V_6 >> 4 ) ;
}
V_4 = V_3 >> 28 ;
if ( ! ( ( V_7 [ V_5 ] >> V_4 ) & 1 ) )
return false ;
return true ;
}
static void T_2 F_5 ( struct V_1 * V_2 )
{
unsigned long V_8 , V_5 ;
unsigned long V_3 = * F_4 ( V_2 ) ;
bool V_9 = ! ( V_3 & V_10 ) ;
if ( V_9 || ! ( V_3 & V_11 ) )
return;
V_5 = ( V_3 & 0xe000 ) >> 13 ;
V_8 = ( V_3 & 0x1c00 ) >> ( 10 - 2 ) ;
V_8 |= ( V_3 & ( 0x3 << 25 ) ) >> 25 ;
if ( ( V_8 & 0x7 ) == 0 )
V_8 = V_5 = 0 ;
else
V_8 = ( V_8 << 1 ) & 0x1f ;
V_3 &= ~ V_11 ;
V_3 |= V_5 << 13 ;
V_3 |= ( V_8 & 0x1c ) << ( 10 - 2 ) ;
V_3 |= ( V_8 & 0x3 ) << 25 ;
* F_4 ( V_2 ) = V_3 ;
}
void T_2 F_6 ( struct V_1 * V_2 , bool V_12 )
{
bool V_13 ;
V_13 = ! ! ( * F_4 ( V_2 ) & V_10 ) ;
if ( V_13 && ! V_12 )
* F_7 ( V_2 ) += 2 ;
else
* F_7 ( V_2 ) += 4 ;
F_5 ( V_2 ) ;
}
