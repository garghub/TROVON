void
F_1 (
struct V_1 * V_2 ,
unsigned short V_3
)
{
T_1 V_4 = V_2 -> V_5 | F_2 ( 14 ) | F_2 ( 15 ) ;
F_3 ( V_2 -> V_6 + V_7 , V_8 ) ;
if ( V_2 -> V_9 != V_10 ) {
F_3 ( V_2 -> V_6 + V_11 , V_4 ) ;
} else {
#if 0
MACvWriteATIMW(priv->PortOffset, pMgmt->wCurrATIMWindow);
#endif
}
F_4 ( V_2 -> V_6 , V_12 , V_13 ) ;
F_4 ( V_2 -> V_6 , V_14 , V_15 ) ;
if ( V_3 >= 2 ) {
F_5 ( V_2 -> V_6 , V_16 , V_17 ) ;
F_4 ( V_2 -> V_6 , V_16 , V_18 ) ;
} else {
F_4 ( V_2 -> V_6 , V_16 , V_17 ) ;
}
F_4 ( V_2 -> V_6 , V_16 , V_19 ) ;
V_2 -> V_20 = true ;
V_2 -> V_21 = true ;
F_6 ( L_1 ) ;
}
void
F_7 (
struct V_1 * V_2
)
{
F_8 ( V_2 ) ;
F_5 ( V_2 -> V_6 , V_12 , V_13 ) ;
F_5 ( V_2 -> V_6 , V_14 , V_15 ) ;
F_4 ( V_2 -> V_6 , V_16 , V_17 ) ;
V_2 -> V_20 = false ;
V_2 -> V_21 = false ;
}
bool
F_9 (
struct V_1 * V_2
)
{
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_24 * V_25 = & V_23 -> V_25 ;
bool V_26 = false ;
if ( V_25 -> V_27 > 1 ) {
if ( ! V_2 -> V_28 )
V_2 -> V_28 = V_25 -> V_27 ;
-- V_2 -> V_28 ;
if ( V_2 -> V_28 == 1 ) {
F_4 ( V_2 -> V_6 ,
V_16 , V_18 ) ;
V_26 = true ;
}
}
return V_26 ;
}
