static inline void
F_1 ( unsigned long V_1 )
{
* ( V_2 ) V_3 = V_1 ;
F_2 () ;
* ( V_2 ) V_3 ;
}
static inline void
F_3 ( struct V_4 * V_5 )
{
F_1 ( V_6 |= 1UL << ( V_5 -> V_7 - 16 ) ) ;
}
static void
F_4 ( struct V_4 * V_5 )
{
F_1 ( V_6 &= ~ ( 1UL << ( V_5 -> V_7 - 16 ) ) ) ;
}
static void
F_5 ( struct V_4 * V_5 )
{
unsigned long V_8 = 1UL << ( V_5 -> V_7 - 16 ) ;
unsigned long V_1 = V_6 &= ~ V_8 ;
* ( V_2 ) V_3 = V_1 ;
F_6 () ;
* ( V_2 ) V_9 = V_8 ;
F_2 () ;
* ( V_2 ) V_3 ;
}
void
F_7 ( unsigned long V_10 )
{
unsigned long V_11 ;
unsigned int V_12 ;
V_11 = * ( V_2 ) V_9 ;
V_11 &= V_6 ;
while ( V_11 ) {
V_12 = F_8 ( ~ V_11 ) ;
V_11 &= V_11 - 1 ;
if ( V_12 == 7 )
F_9 ( V_10 ) ;
else
F_10 ( 16 + V_12 ) ;
}
}
void T_1
F_11 ( unsigned long V_13 )
{
long V_12 ;
* ( V_2 ) V_3 = 0 ;
* ( V_2 ) V_9 = - 1 ;
F_2 () ;
* ( V_14 ) V_15 ;
for ( V_12 = 16 ; V_12 < 48 ; ++ V_12 ) {
if ( ( V_13 >> V_12 ) & 1 )
continue;
F_12 ( V_12 , & V_16 , V_17 ) ;
F_13 ( V_12 , V_18 ) ;
}
F_14 ( 16 + 7 , & V_19 ) ;
}
