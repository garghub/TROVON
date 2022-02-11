static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
unsigned long V_4 ;
unsigned long V_5 ;
if ( ( V_3 <= V_6 ) && ( V_7 == V_8 ) )
F_2 ( L_1 ) ;
if ( V_3 < 32 ) {
V_4 = V_9 ;
V_5 = 1 << V_3 ;
} else {
V_4 = V_10 ;
V_5 = 1 << ( V_3 - 32 ) ;
}
F_3 ( V_5 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
unsigned long V_4 ;
unsigned long V_5 ;
if ( V_3 < 32 ) {
V_4 = V_11 ;
V_5 = 1 << V_3 ;
} else {
V_4 = V_12 ;
V_5 = 1 << ( V_3 - 32 ) ;
}
F_3 ( V_5 , V_4 ) ;
}
void T_1 F_5 ( void )
{
unsigned long long V_13 , V_14 = ~ 0x00000000100000f0 ;
unsigned long V_4 ;
int V_15 ;
V_16 = ( unsigned long ) F_6 ( V_17 , 1024 ) ;
if ( ! V_16 ) {
F_7 ( L_2 ) ;
}
for ( V_15 = 0 ; V_15 < V_18 ; V_15 ++ )
F_8 ( V_15 , & V_19 , V_20 ) ;
F_3 ( - 1 , V_11 ) ;
F_3 ( - 1 , V_12 ) ;
for ( V_4 = V_21 , V_15 = 0 ; V_15 < V_22 ; V_15 ++ , V_4 += 8 )
F_3 ( V_8 , V_4 ) ;
#ifdef F_9
{
unsigned long V_2 ;
V_7 = V_23 [ V_24 ] +
V_23 [ V_25 ] +
V_23 [ V_26 ] +
V_23 [ V_6 ] ;
if ( V_7 == V_8 ) {
V_4 = V_27 ;
V_15 = V_28 ;
F_2 ( L_3 ) ;
} else {
V_4 = V_29 ;
V_15 = V_24 ;
}
F_3 ( V_30 , V_4 ) ;
for ( V_2 = 0 , V_4 = V_21 ; V_15 < V_18 ; V_15 ++ ) {
V_2 |= V_23 [ V_15 ] <<
( ( V_15 % V_31 ) * 4 ) ;
if ( ( V_15 % V_31 ) == ( V_31 - 1 ) ) {
F_3 ( V_2 , V_4 ) ;
V_2 = 0 ;
V_4 += 8 ;
}
}
}
#endif
__asm__ __volatile__("getcon " __SR ", %0\n\t"
"and %0, %1, %0\n\t"
"putcon %0, " __SR "\n\t"
: "=&r" (__dummy0)
: "r" (__dummy1));
}
