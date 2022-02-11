void F_1 ( void )
{
T_1 V_1 = F_2 ( L_1 ) ;
if ( V_1 != 0 && ( V_2 ) V_1 != - 1 )
V_3 = 1 ;
}
int F_3 ( void )
{
return F_4 ( 0x1fff40000d0UL ) ;
}
void F_5 ( int V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 , V_8 , V_9 ;
V_6 = F_6 ( sizeof( * V_6 ) , V_10 ) ;
if ( ! V_6 ) {
F_7 ( L_2 ) ;
F_8 () ;
}
V_7 = 0x100fc000000UL ;
V_8 = ( ( V_4 & 0x3c ) << 1 ) |
( ( V_4 & 0x40 ) >> 4 ) |
( V_4 & 0x3 ) ;
V_6 -> V_8 = V_8 ;
V_7 += ( V_8 << 33UL ) ;
V_7 += 0x200UL ;
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
V_6 -> V_11 [ V_9 ] = 0UL ;
V_6 -> V_12 [ V_9 ] = V_7 + ( V_9 * 0x10UL ) ;
if ( F_4 ( V_6 -> V_12 [ V_9 ] ) != 0 )
V_6 -> V_11 [ V_9 ] = 0xdeadbeaf ;
}
V_6 -> V_4 = V_4 ;
V_6 -> V_13 = V_14 ;
V_14 = V_6 ;
}
unsigned int F_9 ( unsigned long V_15 ,
unsigned int V_4 )
{
struct V_5 * V_6 ;
unsigned int V_16 ;
unsigned int V_9 ;
V_16 = ( ( ( unsigned long ) V_15 ) >> 33 ) & 0x7f ;
for ( V_6 = V_14 ; V_6 != NULL ; V_6 = V_6 -> V_13 )
if ( V_6 -> V_8 == V_16 )
break;
if ( V_6 == NULL ) {
F_7 ( L_3 ,
( ( unsigned long ) V_15 ) ) ;
F_8 () ;
}
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_6 -> V_11 [ V_9 ] == V_15 ||
V_6 -> V_11 [ V_9 ] == 0UL )
break;
}
if ( V_9 == 32 ) {
F_10 ( L_4 ) ;
F_11 ( L_5 ) ;
}
V_6 -> V_11 [ V_9 ] = V_15 ;
V_4 = ( ( ( V_4 & 0x3c ) << 1 ) |
( ( V_4 & 0x40 ) >> 4 ) |
( V_4 & 0x3 ) ) ;
F_12 ( V_4 , V_6 -> V_12 [ V_9 ] ) ;
return V_9 ;
}
