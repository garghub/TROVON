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
if ( ! V_3 )
return;
if ( ! V_4 ) {
F_3 ( V_2 , V_2 -> V_6 ) ;
return;
}
F_4 ( & V_2 -> V_10 , V_11 + 1 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned long * V_3 ,
unsigned long * V_4 )
{
if ( ! ( V_2 -> V_12 & V_13 ) &&
V_2 -> V_14 &&
! V_2 -> V_14 ( V_2 , V_3 , V_4 ) )
return;
if ( ! * V_3 && ! * V_4 )
* V_3 = * V_4 = 500 ;
F_1 ( V_2 , * V_3 , * V_4 ) ;
}
void F_6 ( struct V_1 * V_2 ,
unsigned long * V_3 ,
unsigned long * V_4 )
{
F_7 ( & V_2 -> V_10 ) ;
V_2 -> V_12 &= ~ V_13 ;
V_2 -> V_12 &= ~ V_15 ;
F_5 ( V_2 , V_3 , V_4 ) ;
}
void F_8 ( struct V_1 * V_2 ,
unsigned long * V_3 ,
unsigned long * V_4 ,
int V_16 )
{
if ( ( V_2 -> V_12 & V_13 ) &&
F_9 ( & V_2 -> V_10 ) )
return;
V_2 -> V_12 |= V_13 ;
V_2 -> V_12 &= ~ V_15 ;
if ( V_16 )
V_2 -> V_12 |= V_17 ;
else
V_2 -> V_12 &= ~ V_17 ;
F_5 ( V_2 , V_3 , V_4 ) ;
}
void F_10 ( struct V_1 * V_2 ,
enum V_18 V_19 )
{
F_7 ( & V_2 -> V_10 ) ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
F_3 ( V_2 , V_19 ) ;
}
