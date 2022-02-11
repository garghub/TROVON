T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 V_8 ;
if ( V_7 ( V_2 , 'x' , & V_8 ) ) {
F_2 ( V_6 , L_1 ) ;
return 0x0000 ;
}
* V_3 = V_8 . V_9 ;
* V_4 = V_8 . V_10 ;
if ( * V_3 != 1 || * V_4 < 3 ) {
F_3 ( V_6 , L_2 , * V_3 , * V_4 ) ;
return 0x0000 ;
}
return V_8 . V_11 ;
}
T_2
F_4 ( struct V_1 * V_2 , T_2 V_12 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_2 V_3 , V_4 ;
T_1 V_13 = F_1 ( V_2 , & V_3 , & V_4 ) ;
if ( V_13 && V_4 >= 6 ) {
T_1 V_14 = F_5 ( V_2 , V_13 + 4 ) ;
if ( V_14 ) {
V_3 = F_6 ( V_2 , V_14 ) ;
if ( V_3 == 0x10 || V_3 == 0x11 ) {
if ( V_12 < F_6 ( V_2 , V_14 + 3 ) ) {
V_14 += F_6 ( V_2 , V_14 + 1 ) ;
V_14 += V_12 ;
return F_6 ( V_2 , V_14 ) ;
}
return 0x00 ;
}
F_3 ( V_6 , L_3 , V_3 ) ;
}
}
if ( V_2 -> V_9 . V_15 == 0x84 || V_2 -> V_9 . V_15 == 0x86 )
return V_16 [ V_12 ] ;
if ( V_2 -> V_9 . V_15 == 0x92 )
return V_17 [ V_12 ] ;
if ( V_2 -> V_9 . V_15 == 0x94 || V_2 -> V_9 . V_15 == 0x96 )
return V_18 [ V_12 ] ;
if ( V_2 -> V_9 . V_15 == 0x98 )
return V_19 [ V_12 ] ;
F_3 ( V_6 , L_4 ) ;
return 0x00 ;
}
T_2
F_7 ( struct V_1 * V_2 , T_2 V_20 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_2 V_3 , V_4 ;
T_1 V_13 = F_1 ( V_2 , & V_3 , & V_4 ) ;
if ( V_13 && V_4 >= 8 ) {
T_1 V_14 = F_5 ( V_2 , V_13 + 6 ) ;
if ( V_14 ) {
V_3 = F_6 ( V_2 , V_14 ) ;
if ( V_3 == 0x10 ) {
if ( V_20 < F_6 ( V_2 , V_14 + 3 ) ) {
V_14 += F_6 ( V_2 , V_14 + 1 ) ;
V_14 += V_20 ;
return F_6 ( V_2 , V_14 ) ;
}
return 0x00 ;
}
F_3 ( V_6 , L_5 , V_3 ) ;
}
}
return ( V_20 << 4 ) | V_20 ;
}
