static unsigned long
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 = V_9 ;
int V_10 = V_11 ;
unsigned long V_12 = V_4 -> V_12 ;
if ( V_6 -> V_4 . V_13 == 0x18 )
V_12 &= ~ V_14 ;
while ( V_10 == - 1 && V_8 -> V_15 ) {
if ( V_4 -> V_16 == V_8 -> V_15 &&
V_4 -> V_17 == V_8 -> V_18 &&
F_2 ( V_6 ) -> V_19 -> V_20 == V_8 -> V_21 &&
F_2 ( V_6 ) -> V_19 -> V_6 == V_8 -> V_22 ) {
V_10 = V_8 -> V_12 ;
F_3 ( V_2 , L_1 ,
V_10 ) ;
break;
}
++ V_8 ;
}
if ( V_10 > 0 ) {
bool V_23 = V_12 & 0x8 ;
int V_24 = V_23 ? V_10 / 4 : V_10 ;
V_12 = ( V_12 & ~ 0x7 ) | ( V_24 & 0x7 ) ;
}
return V_12 ;
}
static bool
F_4 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
if ( ! V_26 -> V_19 || ! F_5 ( V_26 ) || ! V_26 -> V_27 )
return false ;
if ( V_2 -> V_27 . V_28 == V_29 ) {
if ( ! V_11 )
return false ;
#ifdef F_6
if ( V_11 == - 1 )
return false ;
#endif
return true ;
}
return ( V_2 -> V_27 . V_28 == V_30 ) ;
}
void
F_7 ( struct V_1 * V_2 )
{
#if V_31
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_25 * V_26 = V_2 -> V_26 ;
T_1 V_32 [ 2 ] ;
int V_33 ;
if ( ! F_4 ( V_2 ) )
return;
if ( ( F_8 ( V_6 , V_34 ) |
V_26 -> V_27 -> V_12 ) & V_14 ) {
struct V_3 V_4 ;
struct V_35 V_12 ;
V_33 = V_3 ( V_26 , & V_4 ) ;
if ( V_33 )
return;
V_12 . V_12 = F_1 ( V_2 , & V_4 ) ;
V_12 . V_12 &= ~ V_14 ;
V_33 = F_9 ( V_26 , V_12 ) ;
if ( V_33 )
return;
}
V_32 [ 0 ] = F_10 ( V_6 , V_36 , 0x00000004 , 0x00000000 ) ;
F_11 ( V_6 , V_34 , 0 ) ;
V_32 [ 1 ] = F_10 ( V_6 , 0x000200 , 0x00011100 , 0x00000000 ) ;
F_10 ( V_6 , 0x000200 , 0x00011100 , V_32 [ 1 ] ) ;
F_11 ( V_6 , V_36 , V_32 [ 0 ] ) ;
#endif
}
void
F_12 ( struct V_1 * V_2 )
{
#if V_31
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_3 V_4 ;
struct V_35 V_12 ;
int V_33 ;
if ( ! F_4 ( V_2 ) )
return;
V_2 -> V_27 . V_28 = V_37 ;
V_33 = F_13 ( V_26 ) ;
if ( V_33 ) {
F_14 ( V_2 , L_2 , V_33 ) ;
return;
}
V_33 = V_3 ( V_26 , & V_4 ) ;
if ( V_33 ) {
F_14 ( V_2 , L_3 , V_33 ) ;
return;
}
V_12 . V_12 = F_1 ( V_2 , & V_4 ) ;
V_33 = F_9 ( V_26 , V_12 ) ;
if ( V_33 ) {
F_14 ( V_2 , L_4 , V_33 ) ;
return;
}
V_2 -> V_27 . V_28 = V_30 ;
V_2 -> V_27 . V_38 = V_4 . V_39 ;
V_2 -> V_27 . V_40 = V_4 . V_41 ;
#endif
}
void
F_15 ( struct V_1 * V_2 )
{
#if V_31
struct V_25 * V_26 = V_2 -> V_26 ;
if ( V_26 -> V_27 && V_26 -> V_27 -> V_42 )
F_16 ( V_26 ) ;
#endif
}
