static unsigned long
F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_5 ) ;
if ( V_5 -> V_6 == 0x18 )
V_3 &= ~ V_7 ;
if ( V_8 > 0 ) {
bool V_9 = V_3 & 0x8 ;
int V_10 = V_9 ? V_8 / 4 : V_8 ;
V_3 = ( V_3 & ~ 0x7 ) | ( V_10 & 0x7 ) ;
}
return V_3 ;
}
static bool
F_3 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
if ( ! F_4 ( V_12 ) || ! V_12 -> V_13 )
return false ;
if ( V_2 -> V_13 . V_14 == V_15 ) {
if ( ! V_8 )
return false ;
#ifdef F_5
if ( V_8 == - 1 )
return false ;
#endif
return true ;
}
return ( V_2 -> V_13 . V_14 == V_16 ) ;
}
void
F_6 ( struct V_1 * V_2 )
{
#if V_17
struct V_4 * V_5 = F_2 ( V_2 -> V_5 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
T_1 V_18 [ 2 ] ;
int V_19 ;
if ( ! F_3 ( V_2 ) )
return;
if ( ( F_7 ( V_5 , V_20 ) |
V_12 -> V_13 -> V_3 ) & V_7 ) {
struct V_21 V_22 ;
struct V_23 V_3 ;
V_19 = V_21 ( V_12 , & V_22 ) ;
if ( V_19 )
return;
V_3 . V_3 = F_1 ( V_2 , V_22 . V_3 ) ;
V_3 . V_3 &= ~ V_7 ;
V_19 = F_8 ( V_12 , V_3 ) ;
if ( V_19 )
return;
}
V_18 [ 0 ] = F_9 ( V_5 , V_24 , 0x00000004 , 0x00000000 ) ;
F_10 ( V_5 , V_20 , 0 ) ;
V_18 [ 1 ] = F_9 ( V_5 , 0x000200 , 0x00011100 , 0x00000000 ) ;
F_9 ( V_5 , 0x000200 , 0x00011100 , V_18 [ 1 ] ) ;
F_10 ( V_5 , V_24 , V_18 [ 0 ] ) ;
#endif
}
void
F_11 ( struct V_1 * V_2 )
{
#if V_17
struct V_4 * V_5 = F_2 ( V_2 -> V_5 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_21 V_22 ;
struct V_23 V_3 ;
int V_19 ;
if ( ! F_3 ( V_2 ) )
return;
V_2 -> V_13 . V_14 = V_25 ;
V_19 = F_12 ( V_12 ) ;
if ( V_19 ) {
F_13 ( V_5 , L_1 , V_19 ) ;
return;
}
V_19 = V_21 ( V_12 , & V_22 ) ;
if ( V_19 ) {
F_13 ( V_5 , L_2 , V_19 ) ;
return;
}
V_3 . V_3 = F_1 ( V_2 , V_22 . V_3 ) ;
V_19 = F_8 ( V_12 , V_3 ) ;
if ( V_19 ) {
F_13 ( V_5 , L_3 , V_19 ) ;
return;
}
V_2 -> V_13 . V_14 = V_16 ;
V_2 -> V_13 . V_26 = V_22 . V_27 ;
V_2 -> V_13 . V_28 = V_22 . V_29 ;
#endif
}
void
F_14 ( struct V_1 * V_2 )
{
#if V_17
struct V_11 * V_12 = V_2 -> V_12 ;
if ( V_12 -> V_13 && V_12 -> V_13 -> V_30 )
F_15 ( V_12 ) ;
#endif
}
