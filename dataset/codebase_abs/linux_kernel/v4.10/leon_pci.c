void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_5 ) ;
struct V_6 * V_7 ;
F_3 ( & V_5 , & V_4 -> V_8 ,
V_4 -> V_8 . V_9 - 0x1000 ) ;
F_4 ( & V_5 , & V_4 -> V_10 ) ;
V_4 -> V_11 . V_12 = V_13 ;
F_4 ( & V_5 , & V_4 -> V_11 ) ;
V_7 = F_5 ( & V_2 -> V_14 , 0 , V_4 -> V_15 , V_4 ,
& V_5 ) ;
if ( ! V_7 ) {
F_6 ( & V_5 ) ;
return;
}
F_7 ( V_16 , V_4 -> V_17 ) ;
F_8 () ;
F_9 ( V_7 ) ;
}
void F_10 ( struct V_6 * V_18 )
{
struct V_19 * V_14 ;
int V_20 , V_21 , V_22 ;
T_1 V_23 ;
F_11 (dev, &pbus->devices, bus_list) {
V_21 = V_22 = 0 ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
unsigned long V_25 = V_14 -> V_26 [ V_20 ] . V_12 ;
if ( V_25 & V_27 )
V_21 = 1 ;
else if ( V_25 & V_28 )
V_22 = 1 ;
}
if ( V_14 -> V_26 [ V_24 ] . V_29 != 0 ) {
V_14 -> V_26 [ V_24 ] . V_12 |=
V_30 ;
V_22 = 1 ;
}
F_12 ( V_18 , V_14 -> V_31 , V_32 , & V_23 ) ;
if ( V_21 && ! ( V_23 & V_33 ) ) {
#ifdef F_13
F_14 ( V_34 L_1 ,
F_15 ( V_14 ) ) ;
#endif
V_23 |= V_33 ;
F_16 ( V_18 , V_14 -> V_31 , V_32 ,
V_23 ) ;
}
if ( V_22 && ! ( V_23 & V_35 ) ) {
#ifdef F_13
F_14 ( V_34 L_2
L_3 , F_15 ( V_14 ) ) ;
#endif
V_23 |= V_35 ;
F_16 ( V_18 , V_14 -> V_31 , V_32 ,
V_23 ) ;
}
}
}
T_2 F_17 ( void * V_36 , const struct V_26 * V_37 ,
T_2 V_38 , T_2 V_39 )
{
return V_37 -> V_9 ;
}
