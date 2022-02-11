struct V_1 * F_1 ( struct V_2 * V_3 , const char * V_4 )
{
return & V_5 ;
}
static void F_2 ( struct V_1 * V_1 )
{
struct V_1 * V_6 ;
F_3 (clkp, &clock_list, node) {
if ( F_4 ( V_6 -> V_7 != V_1 ) )
continue;
if ( F_4 ( V_6 -> V_8 && V_6 -> V_8 -> V_9 ) )
V_6 -> V_8 -> V_9 ( V_6 ) ;
if ( F_5 ( V_6 -> V_10 & V_11 ) )
F_2 ( V_6 ) ;
}
}
int F_6 ( struct V_1 * V_1 )
{
return 0 ;
}
void F_7 ( struct V_1 * V_1 )
{
}
unsigned long F_8 ( struct V_1 * V_1 )
{
return ( unsigned long ) V_1 -> V_12 ;
}
void F_9 ( struct V_1 * V_1 )
{
}
int F_10 ( struct V_1 * V_1 , unsigned long V_12 )
{
return F_11 ( V_1 , V_12 , 0 ) ;
}
int F_11 ( struct V_1 * V_1 , unsigned long V_12 , int V_13 )
{
int V_14 = 0 ;
int V_15 ;
int V_16 ;
if ( F_4 ( V_1 -> V_8 && V_1 -> V_8 -> V_17 ) ) {
unsigned long V_10 ;
F_12 ( & V_18 , V_10 ) ;
V_14 = V_1 -> V_8 -> V_17 ( V_1 , V_12 , V_13 ) ;
F_13 ( & V_18 , V_10 ) ;
}
if ( F_5 ( V_1 -> V_10 & V_11 ) )
F_2 ( V_1 ) ;
for ( V_16 = 0 ; V_19 [ V_16 ] . V_20 != V_21 ;
V_16 ++ ) {
if ( V_19 [ V_16 ] . V_20 ==
V_22 )
continue;
if ( V_12 == V_19 [ V_16 ] . V_20 )
break;
}
if ( V_12 != V_19 [ V_16 ] . V_20 )
return - V_23 ;
V_1 -> V_12 = V_12 ;
V_15 = V_24 ;
V_15 = ( V_15 & ~ 0x7 ) | ( V_19 [ V_16 ] . V_25 - 1 ) ;
V_24 = V_15 ;
return V_14 ;
}
long F_14 ( struct V_1 * V_1 , unsigned long V_12 )
{
if ( F_4 ( V_1 -> V_8 && V_1 -> V_8 -> V_26 ) ) {
unsigned long V_10 , V_27 ;
F_12 ( & V_18 , V_10 ) ;
V_27 = V_1 -> V_8 -> V_26 ( V_1 , V_12 ) ;
F_13 ( & V_18 , V_10 ) ;
return V_27 ;
}
return V_12 ;
}
void F_15 ( void )
{
T_1 V_28 ;
unsigned long V_10 ;
F_12 ( & V_29 , V_10 ) ;
V_28 = V_24 ;
V_24 &= ~ 0x7 ;
V_24 = V_28 ;
F_13 ( & V_29 , V_10 ) ;
}
