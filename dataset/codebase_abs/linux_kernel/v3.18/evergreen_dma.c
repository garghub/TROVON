void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 [ V_4 -> V_6 ] ;
T_1 V_7 = V_2 -> V_8 [ V_4 -> V_6 ] . V_9 ;
F_2 ( V_6 , F_3 ( V_10 , 0 , 0 ) ) ;
F_2 ( V_6 , V_7 & 0xfffffffc ) ;
F_2 ( V_6 , ( F_4 ( V_7 ) & 0xff ) ) ;
F_2 ( V_6 , V_4 -> V_11 ) ;
F_2 ( V_6 , F_3 ( V_12 , 0 , 0 ) ) ;
F_2 ( V_6 , F_3 ( V_13 , 0 , 0 ) ) ;
F_2 ( V_6 , ( 0xf << 16 ) | ( V_14 >> 2 ) ) ;
F_2 ( V_6 , 1 ) ;
}
void F_5 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = & V_2 -> V_6 [ V_16 -> V_6 ] ;
if ( V_2 -> V_17 . V_18 ) {
T_2 V_19 = V_6 -> V_20 + 4 ;
while ( ( V_19 & 7 ) != 5 )
V_19 ++ ;
V_19 += 3 ;
F_2 ( V_6 , F_3 ( V_21 , 0 , 1 ) ) ;
F_2 ( V_6 , V_6 -> V_22 & 0xfffffffc ) ;
F_2 ( V_6 , F_4 ( V_6 -> V_22 ) & 0xff ) ;
F_2 ( V_6 , V_19 ) ;
}
while ( ( V_6 -> V_20 & 7 ) != 5 )
F_2 ( V_6 , F_3 ( V_23 , 0 , 0 ) ) ;
F_2 ( V_6 , F_3 ( V_24 , 0 , 0 ) ) ;
F_2 ( V_6 , ( V_16 -> V_9 & 0xFFFFFFE0 ) ) ;
F_2 ( V_6 , ( V_16 -> V_25 << 12 ) | ( F_4 ( V_16 -> V_9 ) & 0xFF ) ) ;
}
struct V_3 * F_6 ( struct V_1 * V_2 ,
T_3 V_26 ,
T_3 V_27 ,
unsigned V_28 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 = NULL ;
struct V_3 * V_4 ;
int V_33 = V_2 -> V_34 -> V_35 . V_36 ;
struct V_5 * V_6 = & V_2 -> V_6 [ V_33 ] ;
T_2 V_37 , V_38 ;
int V_39 , V_40 ;
int V_41 = 0 ;
V_41 = F_7 ( V_2 , & V_32 ) ;
if ( V_41 ) {
F_8 ( L_1 , V_41 ) ;
return F_9 ( V_41 ) ;
}
V_37 = ( V_28 << V_42 ) / 4 ;
V_40 = F_10 ( V_37 , 0xfffff ) ;
V_41 = F_11 ( V_2 , V_6 , V_40 * 5 + 11 ) ;
if ( V_41 ) {
F_8 ( L_1 , V_41 ) ;
F_12 ( V_2 , & V_32 , NULL ) ;
return F_9 ( V_41 ) ;
}
F_13 ( V_2 , V_32 , V_30 , false ) ;
F_14 ( V_2 , V_32 , V_6 -> V_43 ) ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
V_38 = V_37 ;
if ( V_38 > 0xFFFFF )
V_38 = 0xFFFFF ;
V_37 -= V_38 ;
F_2 ( V_6 , F_3 ( V_44 , 0 , V_38 ) ) ;
F_2 ( V_6 , V_27 & 0xfffffffc ) ;
F_2 ( V_6 , V_26 & 0xfffffffc ) ;
F_2 ( V_6 , F_4 ( V_27 ) & 0xff ) ;
F_2 ( V_6 , F_4 ( V_26 ) & 0xff ) ;
V_26 += V_38 * 4 ;
V_27 += V_38 * 4 ;
}
V_41 = F_15 ( V_2 , & V_4 , V_6 -> V_43 ) ;
if ( V_41 ) {
F_16 ( V_2 , V_6 ) ;
F_12 ( V_2 , & V_32 , NULL ) ;
return F_9 ( V_41 ) ;
}
F_17 ( V_2 , V_6 , false ) ;
F_12 ( V_2 , & V_32 , V_4 ) ;
return V_4 ;
}
bool F_18 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_2 V_45 = F_19 ( V_2 ) ;
if ( ! ( V_45 & V_46 ) ) {
F_20 ( V_2 , V_6 ) ;
return false ;
}
return F_21 ( V_2 , V_6 ) ;
}
