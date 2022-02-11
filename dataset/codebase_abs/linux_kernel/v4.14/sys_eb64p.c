static inline void
F_1 ( unsigned int V_1 , unsigned long V_2 )
{
F_2 ( V_2 >> ( V_1 >= 24 ? 24 : 16 ) , ( V_1 >= 24 ? 0x27 : 0x26 ) ) ;
}
static inline void
F_3 ( struct V_3 * V_4 )
{
F_1 ( V_4 -> V_1 , V_5 &= ~ ( 1 << V_4 -> V_1 ) ) ;
}
static void
F_4 ( struct V_3 * V_4 )
{
F_1 ( V_4 -> V_1 , V_5 |= 1 << V_4 -> V_1 ) ;
}
static void
F_5 ( unsigned long V_6 )
{
unsigned long V_7 ;
unsigned int V_8 ;
V_7 = F_6 ( 0x26 ) | ( F_6 ( 0x27 ) << 8 ) ;
while ( V_7 ) {
V_8 = F_7 ( ~ V_7 ) ;
V_7 &= V_7 - 1 ;
if ( V_8 == 5 ) {
F_8 ( V_6 ) ;
} else {
F_9 ( 16 + V_8 ) ;
}
}
}
static void T_1
F_10 ( void )
{
long V_8 ;
#if F_11 ( V_9 ) || F_11 ( V_10 )
if ( F_12 ( 0x806 ) != 0xffff ) {
extern struct V_11 V_12 ;
F_13 ( L_1 ) ;
V_13 -> V_14 |= 2L << 10 ;
F_14 ( V_13 ) ;
V_15 = V_12 ;
V_15 . V_16 () ;
return;
}
#endif
F_2 ( 0xff , 0x26 ) ;
F_2 ( 0xff , 0x27 ) ;
F_15 () ;
for ( V_8 = 16 ; V_8 < 32 ; ++ V_8 ) {
F_16 ( V_8 , & V_17 , V_18 ) ;
F_17 ( V_8 , V_19 ) ;
}
F_18 () ;
F_19 ( 16 + 5 , & V_20 ) ;
}
static int
F_20 ( const struct V_21 * V_22 , T_2 V_23 , T_2 V_24 )
{
static char V_25 [ 5 ] [ 5 ] = {
{ 16 + 7 , 16 + 7 , 16 + 7 , 16 + 7 , 16 + 7 } ,
{ 16 + 0 , 16 + 0 , 16 + 2 , 16 + 4 , 16 + 9 } ,
{ 16 + 1 , 16 + 1 , 16 + 3 , 16 + 8 , 16 + 10 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 16 + 6 , 16 + 6 , 16 + 6 , 16 + 6 , 16 + 6 } ,
} ;
const long V_26 = 5 , V_27 = 9 , V_28 = 5 ;
return V_29 ;
}
