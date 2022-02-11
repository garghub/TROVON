unsigned long F_1 ( void )
{
struct V_1 * V_2 ;
unsigned long V_3 = 0 ;
int V_4 ;
F_2 () ;
F_3 ( & V_5 ) ;
F_4 (i, desc) {
F_5 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_7 && F_6 ( V_2 ) ) {
if ( V_2 -> V_8 . V_9 -> V_10 )
V_2 -> V_8 . V_9 -> V_10 ( & V_2 -> V_8 ,
V_11 ) ;
F_7 ( V_2 , false ) ;
}
F_8 ( & V_2 -> V_6 ) ;
}
F_9 ( 20 ) ;
F_4 (i, desc) {
F_5 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_7 && F_6 ( V_2 ) ) {
V_2 -> V_12 |= V_13 | V_14 ;
if ( F_7 ( V_2 , false ) )
V_2 -> V_12 |= V_15 ;
}
F_8 ( & V_2 -> V_6 ) ;
}
F_9 ( 100 ) ;
F_10 (i, desc) {
F_5 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_12 & V_13 ) {
if ( ! ( V_2 -> V_12 & V_14 ) ) {
V_2 -> V_12 &= ~ V_13 ;
F_11 ( V_2 ) ;
} else
if ( V_4 < 32 )
V_3 |= 1 << V_4 ;
}
F_8 ( & V_2 -> V_6 ) ;
}
return V_3 ;
}
unsigned int F_12 ( unsigned long V_16 )
{
unsigned int V_3 = 0 ;
struct V_1 * V_2 ;
int V_4 ;
F_10 (i, desc) {
F_5 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_12 & V_13 ) {
if ( V_4 < 16 && ! ( V_2 -> V_12 & V_14 ) )
V_3 |= 1 << V_4 ;
V_2 -> V_12 &= ~ V_13 ;
F_11 ( V_2 ) ;
}
F_8 ( & V_2 -> V_6 ) ;
}
F_13 ( & V_5 ) ;
return V_3 & V_16 ;
}
int F_14 ( unsigned long V_16 )
{
int V_4 , V_17 = 0 , V_18 = 0 ;
struct V_1 * V_2 ;
F_10 (i, desc) {
F_5 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_12 & V_13 ) {
if ( ! ( V_2 -> V_12 & V_14 ) ) {
if ( ! V_18 )
V_17 = V_4 ;
V_18 ++ ;
}
V_2 -> V_12 &= ~ V_13 ;
F_11 ( V_2 ) ;
}
F_8 ( & V_2 -> V_6 ) ;
}
F_13 ( & V_5 ) ;
if ( V_18 > 1 )
V_17 = - V_17 ;
return V_17 ;
}
