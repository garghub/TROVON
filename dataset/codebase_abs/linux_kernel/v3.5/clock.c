static void F_1 ( struct V_1 * V_1 )
{
if ( V_1 == NULL || F_2 ( V_1 ) )
return;
F_3 ( ! V_1 -> V_2 ) ;
if ( ! ( -- V_1 -> V_2 ) ) {
if ( V_1 -> V_3 )
V_1 -> V_3 ( V_1 ) ;
F_1 ( V_1 -> V_4 ) ;
F_1 ( V_1 -> V_5 ) ;
}
}
static int F_4 ( struct V_1 * V_1 )
{
if ( V_1 == NULL || F_2 ( V_1 ) )
return - V_6 ;
if ( V_1 -> V_2 ++ == 0 ) {
F_4 ( V_1 -> V_4 ) ;
F_4 ( V_1 -> V_5 ) ;
if ( V_1 -> V_7 )
V_1 -> V_7 ( V_1 ) ;
}
return 0 ;
}
int F_5 ( struct V_1 * V_1 )
{
int V_8 = 0 ;
if ( V_1 == NULL || F_2 ( V_1 ) )
return - V_6 ;
F_6 ( & V_9 ) ;
V_8 = F_4 ( V_1 ) ;
F_7 ( & V_9 ) ;
return V_8 ;
}
void F_8 ( struct V_1 * V_1 )
{
if ( V_1 == NULL || F_2 ( V_1 ) )
return;
F_6 ( & V_9 ) ;
F_1 ( V_1 ) ;
F_7 ( & V_9 ) ;
}
unsigned long F_9 ( struct V_1 * V_1 )
{
if ( V_1 == NULL || F_2 ( V_1 ) )
return 0UL ;
if ( V_1 -> V_10 )
return V_1 -> V_10 ( V_1 ) ;
return F_9 ( V_1 -> V_4 ) ;
}
long F_10 ( struct V_1 * V_1 , unsigned long V_11 )
{
if ( V_1 == NULL || F_2 ( V_1 ) || ! V_1 -> V_12 )
return 0 ;
return V_1 -> V_12 ( V_1 , V_11 ) ;
}
int F_11 ( struct V_1 * V_1 , unsigned long V_11 )
{
int V_8 = - V_6 ;
if ( V_1 == NULL || F_2 ( V_1 ) || V_1 -> V_13 == NULL || V_11 == 0 )
return V_8 ;
F_6 ( & V_9 ) ;
V_8 = V_1 -> V_13 ( V_1 , V_11 ) ;
F_7 ( & V_9 ) ;
return V_8 ;
}
int F_12 ( struct V_1 * V_1 , struct V_1 * V_4 )
{
int V_8 = - V_6 ;
struct V_1 * V_14 ;
if ( V_1 == NULL || F_2 ( V_1 ) || V_4 == NULL ||
F_2 ( V_4 ) || V_1 -> V_15 == NULL )
return V_8 ;
if ( V_1 -> V_2 )
F_5 ( V_4 ) ;
F_6 ( & V_9 ) ;
V_8 = V_1 -> V_15 ( V_1 , V_4 ) ;
if ( V_8 == 0 ) {
V_14 = V_1 -> V_4 ;
V_1 -> V_4 = V_4 ;
} else {
V_14 = V_4 ;
}
F_7 ( & V_9 ) ;
if ( V_1 -> V_2 )
F_8 ( V_14 ) ;
return V_8 ;
}
struct V_1 * F_13 ( struct V_1 * V_1 )
{
struct V_1 * V_8 = NULL ;
if ( V_1 == NULL || F_2 ( V_1 ) )
return V_8 ;
return V_1 -> V_4 ;
}
unsigned long F_14 ( unsigned int V_16 , T_1 V_17 )
{
long long V_18 ;
int V_19 ;
unsigned int V_20 , V_21 , V_22 , V_23 ;
V_20 = ( V_16 >> 10 ) & 0xf ;
V_21 = V_16 & 0x3ff ;
V_22 = ( V_16 >> 16 ) & 0x3ff ;
V_23 = ( V_16 >> 26 ) & 0xf ;
V_20 = V_20 <= 5 ? 5 : V_20 ;
V_19 = V_21 ;
if ( ! F_15 () && ! F_16 () && V_21 >= 0x200 )
V_19 = 0x400 - V_21 ;
V_17 *= 2 ;
V_17 /= V_23 + 1 ;
V_18 = ( unsigned long long ) V_17 * V_19 ;
F_17 ( V_18 , V_22 + 1 ) ;
if ( ! F_15 () && ! F_16 () && V_21 >= 0x200 )
V_18 = - V_18 ;
V_18 = ( V_17 * V_20 ) + V_18 ;
return V_18 ;
}
