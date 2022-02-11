static inline void
F_1 ( unsigned int V_1 , unsigned long V_2 )
{
int V_3 = 0x21 ;
if ( V_1 & 8 ) V_2 >>= 8 ;
if ( V_1 & 8 ) V_3 = 0xA1 ;
F_2 ( V_2 , V_3 ) ;
}
inline void
F_3 ( struct V_4 * V_5 )
{
F_4 ( & V_6 ) ;
F_1 ( V_5 -> V_1 , V_7 &= ~ ( 1 << V_5 -> V_1 ) ) ;
F_5 ( & V_6 ) ;
}
static inline void
F_6 ( unsigned int V_1 )
{
F_1 ( V_1 , V_7 |= 1 << V_1 ) ;
}
void
F_7 ( struct V_4 * V_5 )
{
F_4 ( & V_6 ) ;
F_6 ( V_5 -> V_1 ) ;
F_5 ( & V_6 ) ;
}
void
F_8 ( struct V_4 * V_5 )
{
unsigned int V_1 = V_5 -> V_1 ;
F_4 ( & V_6 ) ;
F_6 ( V_1 ) ;
if ( V_1 >= 8 ) {
F_2 ( 0xE0 | ( V_1 - 8 ) , 0xa0 ) ;
V_1 = 2 ;
}
F_2 ( 0xE0 | V_1 , 0x20 ) ;
F_5 ( & V_6 ) ;
}
void T_1
F_9 ( void )
{
static struct V_8 V_9 = {
. V_10 = V_11 ,
. V_12 = L_1 ,
} ;
long V_13 ;
F_2 ( 0xff , 0x21 ) ;
F_2 ( 0xff , 0xA1 ) ;
for ( V_13 = 0 ; V_13 < 16 ; V_13 ++ ) {
F_10 ( V_13 , & V_14 , V_15 ) ;
}
F_11 ( 2 , & V_9 ) ;
}
void
F_12 ( unsigned long V_16 )
{
int V_17 = * ( V_18 ) V_19 ;
V_17 &= 0xff ;
F_13 ( V_17 ) ;
}
void
F_14 ( unsigned long V_16 )
{
unsigned long V_20 ;
V_20 = F_15 ( 0x20 ) | ( F_15 ( 0xA0 ) << 8 ) ;
V_20 &= 0xFFFB ;
while ( V_20 ) {
int V_17 = F_16 ( ~ V_20 ) ;
V_20 &= V_20 - 1 ;
F_13 ( V_17 ) ;
}
}
