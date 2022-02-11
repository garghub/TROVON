static inline void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( V_3 < V_4 )
* V_5 |= ( 1 << ( V_3 - V_6 ) ) ;
else
* V_7 |= ( 1 << ( V_3 - V_4 ) ) ;
}
static inline void F_2 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( V_3 < V_4 )
* V_5 &= ~ ( 1 << ( V_3 - V_6 ) ) ;
else
* V_7 &= ~ ( 1 << ( V_3 - V_4 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( V_3 < V_4 )
* V_8 = ( 1 << ( V_3 - V_6 ) ) ;
else
* V_9 = ( 1 << ( V_3 - V_4 ) ) ;
}
void T_1 F_4 ( void )
{
int V_10 ;
* V_5 = 0x00000000 ;
* V_7 = 0x00000000 ;
* V_8 = 0xFFFFFFFF ;
* V_9 = 0xFFFFFFFF ;
for ( V_10 = V_6 ; V_10 < V_4 + 32 ; V_10 ++ )
F_5 ( V_10 , & V_11 ,
V_12 ) ;
}
void F_6 ( void )
{
T_2 V_13 ;
int V_14 ;
V_14 = V_6 ;
V_13 = * V_8 & * V_5 ;
if ( V_13 == ( 1 << ( V_15 - V_6 ) ) ) {
V_14 = V_4 ;
V_13 = * V_9 & * V_7 ;
}
if ( V_13 == 0x00000000 ) {
F_7 ( V_16 L_1 ,
( V_14 == V_6 ) ? L_2 : L_3 ) ;
return;
}
F_8 ( F_9 ( V_13 ) + V_14 - 1 ) ;
}
