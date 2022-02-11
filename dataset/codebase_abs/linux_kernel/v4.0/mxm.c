T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 )
{
struct V_5 V_6 ;
if ( V_5 ( V_2 , 'x' , & V_6 ) ) {
F_2 ( V_2 , L_1 ) ;
return 0x0000 ;
}
* V_3 = V_6 . V_7 ;
* V_4 = V_6 . V_8 ;
if ( * V_3 != 1 || * V_4 < 3 ) {
F_3 ( V_2 , L_2 , * V_3 , * V_4 ) ;
return 0x0000 ;
}
return V_6 . V_9 ;
}
T_2
F_4 ( struct V_1 * V_2 , T_2 V_10 )
{
T_2 V_3 , V_4 ;
T_1 V_11 = F_1 ( V_2 , & V_3 , & V_4 ) ;
if ( V_11 && V_4 >= 6 ) {
T_1 V_12 = F_5 ( V_2 , V_11 + 4 ) ;
if ( V_12 ) {
V_3 = F_6 ( V_2 , V_12 ) ;
if ( V_3 == 0x10 ) {
if ( V_10 < F_6 ( V_2 , V_12 + 3 ) ) {
V_12 += F_6 ( V_2 , V_12 + 1 ) ;
V_12 += V_10 ;
return F_6 ( V_2 , V_12 ) ;
}
return 0x00 ;
}
F_3 ( V_2 , L_3 , V_3 ) ;
}
}
if ( V_2 -> V_7 . V_13 == 0x84 || V_2 -> V_7 . V_13 == 0x86 )
return V_14 [ V_10 ] ;
if ( V_2 -> V_7 . V_13 == 0x92 )
return V_15 [ V_10 ] ;
if ( V_2 -> V_7 . V_13 == 0x94 || V_2 -> V_7 . V_13 == 0x96 )
return V_16 [ V_10 ] ;
if ( V_2 -> V_7 . V_13 == 0x98 )
return V_17 [ V_10 ] ;
F_3 ( V_2 , L_4 ) ;
return 0x00 ;
}
T_2
F_7 ( struct V_1 * V_2 , T_2 V_18 )
{
T_2 V_3 , V_4 ;
T_1 V_11 = F_1 ( V_2 , & V_3 , & V_4 ) ;
if ( V_11 && V_4 >= 8 ) {
T_1 V_12 = F_5 ( V_2 , V_11 + 6 ) ;
if ( V_12 ) {
V_3 = F_6 ( V_2 , V_12 ) ;
if ( V_3 == 0x10 ) {
if ( V_18 < F_6 ( V_2 , V_12 + 3 ) ) {
V_12 += F_6 ( V_2 , V_12 + 1 ) ;
V_12 += V_18 ;
return F_6 ( V_2 , V_12 ) ;
}
return 0x00 ;
}
F_3 ( V_2 , L_5 , V_3 ) ;
}
}
return ( V_18 << 4 ) | V_18 ;
}
