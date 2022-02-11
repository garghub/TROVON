T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_5 ;
T_2 V_6 ;
T_2 V_7 ;
V_5 = F_2 ( V_2 , V_8 , & V_6 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_2 ( V_2 , V_9 , & V_7 ) ;
if ( V_5 )
return V_5 ;
V_4 -> V_10 = ( V_11 ) V_6 ;
V_4 -> V_10 = ( ( V_4 -> V_10 << 6 ) | ( ( V_7 & 0xFC00 ) >> 10 ) ) ;
V_4 -> V_12 = ( V_11 ) ( V_7 & 0x000F ) ;
F_3 ( L_1 ,
V_4 -> V_10 , V_4 -> V_12 ) ;
return 0 ;
}
T_1 F_2 ( struct V_1 * V_2 , V_11 V_13 , T_2 * V_14 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( V_13 > V_15 ) {
F_4 ( L_2 , V_13 ) ;
return - V_16 ;
}
* V_14 = F_5 ( V_2 , V_4 -> V_17 , V_18 ,
V_13 , ( T_2 ) 0 ) ;
return 0 ;
}
T_1 F_6 ( struct V_1 * V_2 , V_11 V_13 , T_2 V_14 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( V_13 > V_15 ) {
F_4 ( L_2 , V_13 ) ;
return - V_16 ;
}
F_5 ( V_2 , V_4 -> V_17 , V_19 ,
V_13 , V_14 ) ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
T_2 V_20 ;
F_2 ( V_2 , V_21 , & V_20 ) ;
V_20 |= V_22 ;
F_6 ( V_2 , V_21 , V_20 ) ;
F_8 ( 1 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_21 , V_23 ) ;
F_6 ( V_2 , V_24 ,
V_25 ) ;
F_6 ( V_2 , V_26 ,
V_27 ) ;
F_6 ( V_2 , V_28 , V_29 ) ;
F_6 ( V_2 , V_30 ,
V_31 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
T_2 V_32 ;
V_32 = 0 ;
F_2 ( V_2 , V_21 , & V_32 ) ;
V_32 &= ~ V_33 ;
F_6 ( V_2 , V_21 , V_32 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
T_2 V_32 ;
V_32 = 0 ;
F_2 ( V_2 , V_21 , & V_32 ) ;
V_32 |= V_33 ;
F_6 ( V_2 , V_21 , V_32 ) ;
F_12 ( 1 ) ;
}
inline void F_13 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
struct V_36 V_37 = { . V_37 = V_38 } ;
int V_5 ;
T_2 V_32 ;
V_35 = F_15 ( V_2 , struct V_34 , V_2 ) ;
V_5 = F_16 ( & V_35 -> V_39 , & V_37 ) ;
if ( V_5 )
F_4 ( L_3 ) ;
F_17 ( & V_37 , V_2 -> V_40 . V_41 ) ;
V_37 . V_42 = V_2 -> V_40 . V_43 ;
V_37 . V_44 = V_2 -> V_4 . V_45 ;
V_37 . V_46 = V_2 -> V_40 . V_46 ;
F_6 ( V_2 , V_47 , V_48 ) ;
V_5 = F_18 ( & V_35 -> V_39 , & V_37 ) ;
if ( V_5 )
F_4 ( L_4 ) ;
F_7 ( V_2 ) ;
F_2 ( V_2 , V_30 , & V_32 ) ;
V_32 |= V_49 ;
F_6 ( V_2 , V_30 , V_32 ) ;
}
