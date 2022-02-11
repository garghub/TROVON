static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 ;
int V_4 ;
while ( ! F_2 ( V_5 , V_6 ) ) {
V_4 = F_3 ( V_5 , V_6 ) ;
F_4 ( V_4 , V_5 ) ;
V_3 = F_5 ( V_4 ) ;
F_6 () ;
V_3 -> V_7 ( V_3 ) ;
F_7 () ;
}
}
void F_8 ( struct V_2 * V_3 )
{
if ( F_9 ( V_3 ) ) {
V_3 -> V_8 &= ~ V_9 ;
return;
}
if ( V_3 -> V_8 & V_10 )
return;
if ( V_3 -> V_8 & V_9 ) {
V_3 -> V_8 &= ~ V_9 ;
V_3 -> V_8 |= V_10 ;
if ( ! V_3 -> V_11 . V_12 -> V_13 ||
! V_3 -> V_11 . V_12 -> V_13 ( & V_3 -> V_11 ) ) {
#ifdef F_10
unsigned int V_4 = F_11 ( V_3 ) ;
if ( F_12 ( V_3 ) ) {
if ( ! V_3 -> V_14 )
return;
V_4 = V_3 -> V_14 ;
}
F_13 ( V_4 , V_5 ) ;
F_14 ( & V_15 ) ;
#endif
}
}
}
