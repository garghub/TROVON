static void F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned long V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_2 -> V_6 = V_5 ;
if ( ! V_2 -> V_6 )
V_2 -> V_6 = V_2 -> V_7 ;
V_2 -> V_8 = V_3 ;
V_2 -> V_9 = V_4 ;
if ( ! V_3 ) {
F_3 ( V_2 , V_10 ) ;
return;
}
if ( ! V_4 ) {
F_3 ( V_2 , V_2 -> V_6 ) ;
return;
}
F_4 ( & V_2 -> V_11 , V_12 + 1 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned long * V_3 ,
unsigned long * V_4 )
{
if ( ! ( V_2 -> V_13 & V_14 ) &&
V_2 -> V_15 &&
! V_2 -> V_15 ( V_2 , V_3 , V_4 ) )
return;
if ( ! * V_3 && ! * V_4 )
* V_3 = * V_4 = 500 ;
F_1 ( V_2 , * V_3 , * V_4 ) ;
}
void F_6 ( struct V_1 * V_2 ,
unsigned long * V_3 ,
unsigned long * V_4 )
{
F_7 ( & V_2 -> V_11 ) ;
V_2 -> V_13 &= ~ V_14 ;
V_2 -> V_13 &= ~ V_16 ;
F_5 ( V_2 , V_3 , V_4 ) ;
}
void F_8 ( struct V_1 * V_2 ,
unsigned long * V_3 ,
unsigned long * V_4 ,
int V_17 )
{
if ( ( V_2 -> V_13 & V_14 ) &&
F_9 ( & V_2 -> V_11 ) )
return;
V_2 -> V_13 |= V_14 ;
V_2 -> V_13 &= ~ V_16 ;
if ( V_17 )
V_2 -> V_13 |= V_18 ;
else
V_2 -> V_13 &= ~ V_18 ;
F_5 ( V_2 , V_3 , V_4 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_11 ) ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
}
void F_11 ( struct V_1 * V_2 ,
enum V_19 V_20 )
{
if ( V_2 -> V_8 || V_2 -> V_9 ) {
V_2 -> V_21 = V_20 ;
F_12 ( & V_2 -> V_22 ) ;
return;
}
F_3 ( V_2 , V_20 ) ;
}
