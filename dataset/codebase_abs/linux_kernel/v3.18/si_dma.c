bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
if ( V_4 -> V_7 == V_8 )
V_6 = V_9 ;
else
V_6 = V_10 ;
if ( ! ( V_5 & V_6 ) ) {
F_3 ( V_2 , V_4 ) ;
return false ;
}
return F_4 ( V_2 , V_4 ) ;
}
void F_5 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
T_2 V_13 , T_2 V_14 ,
unsigned V_15 )
{
while ( V_15 ) {
unsigned V_16 = V_15 * 8 ;
if ( V_16 > 0xFFFF8 )
V_16 = 0xFFFF8 ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = F_6 ( V_19 ,
1 , 0 , 0 , V_16 ) ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = F_7 ( V_13 ) ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = F_7 ( V_14 ) ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = F_8 ( V_13 ) & 0xff ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = F_8 ( V_14 ) & 0xff ;
V_13 += V_16 ;
V_14 += V_16 ;
V_15 -= V_16 / 8 ;
}
}
void F_9 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
T_2 V_13 ,
T_2 V_20 , unsigned V_15 ,
T_3 V_21 , T_3 V_22 )
{
T_2 V_23 ;
unsigned V_24 ;
while ( V_15 ) {
V_24 = V_15 * 2 ;
if ( V_24 > 0xFFFFE )
V_24 = 0xFFFFE ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = F_6 ( V_25 , 0 , 0 , 0 , V_24 ) ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = V_13 ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = F_8 ( V_13 ) & 0xff ;
for (; V_24 > 0 ; V_24 -= 2 , -- V_15 , V_13 += 8 ) {
if ( V_22 & V_26 ) {
V_23 = F_10 ( V_2 , V_20 ) ;
V_23 &= 0xFFFFFFFFFFFFF000ULL ;
} else if ( V_22 & V_27 ) {
V_23 = V_20 ;
} else {
V_23 = 0 ;
}
V_20 += V_21 ;
V_23 |= V_22 ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = V_23 ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = F_8 ( V_23 ) ;
}
}
}
void F_11 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
T_2 V_13 ,
T_2 V_20 , unsigned V_15 ,
T_3 V_21 , T_3 V_22 )
{
T_2 V_23 ;
unsigned V_24 ;
while ( V_15 ) {
V_24 = V_15 * 2 ;
if ( V_24 > 0xFFFFE )
V_24 = 0xFFFFE ;
if ( V_22 & V_27 )
V_23 = V_20 ;
else
V_23 = 0 ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = F_12 ( V_24 ) ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = V_13 ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = F_8 ( V_13 ) & 0xff ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = V_22 ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = 0 ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = V_23 ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = F_8 ( V_23 ) ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = V_21 ;
V_12 -> V_17 [ V_12 -> V_18 ++ ] = 0 ;
V_13 += V_24 * 4 ;
V_20 += ( V_24 / 2 ) * V_21 ;
V_15 -= V_24 / 2 ;
}
}
void F_13 ( struct V_1 * V_2 , int V_28 , struct V_29 * V_30 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_28 ] ;
if ( V_30 == NULL )
return;
F_14 ( V_4 , F_6 ( V_31 , 0 , 0 , 0 , 0 ) ) ;
if ( V_30 -> V_32 < 8 ) {
F_14 ( V_4 , ( 0xf << 16 ) | ( ( V_33 + ( V_30 -> V_32 << 2 ) ) >> 2 ) ) ;
} else {
F_14 ( V_4 , ( 0xf << 16 ) | ( ( V_34 + ( ( V_30 -> V_32 - 8 ) << 2 ) ) >> 2 ) ) ;
}
F_14 ( V_4 , V_30 -> V_35 >> 12 ) ;
F_14 ( V_4 , F_6 ( V_31 , 0 , 0 , 0 , 0 ) ) ;
F_14 ( V_4 , ( 0xf << 16 ) | ( V_36 >> 2 ) ) ;
F_14 ( V_4 , 1 ) ;
F_14 ( V_4 , F_6 ( V_31 , 0 , 0 , 0 , 0 ) ) ;
F_14 ( V_4 , ( 0xf << 16 ) | ( V_37 >> 2 ) ) ;
F_14 ( V_4 , 1 << V_30 -> V_32 ) ;
}
struct V_38 * F_15 ( struct V_1 * V_2 ,
T_2 V_39 , T_2 V_40 ,
unsigned V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = NULL ;
struct V_38 * V_46 ;
int V_47 = V_2 -> V_48 -> V_49 . V_50 ;
struct V_3 * V_4 = & V_2 -> V_4 [ V_47 ] ;
T_1 V_51 , V_52 ;
int V_53 , V_54 ;
int V_55 = 0 ;
V_55 = F_16 ( V_2 , & V_45 ) ;
if ( V_55 ) {
F_17 ( L_1 , V_55 ) ;
return F_18 ( V_55 ) ;
}
V_51 = ( V_41 << V_56 ) ;
V_54 = F_19 ( V_51 , 0xfffff ) ;
V_55 = F_20 ( V_2 , V_4 , V_54 * 5 + 11 ) ;
if ( V_55 ) {
F_17 ( L_1 , V_55 ) ;
F_21 ( V_2 , & V_45 , NULL ) ;
return F_18 ( V_55 ) ;
}
F_22 ( V_2 , V_45 , V_43 , false ) ;
F_23 ( V_2 , V_45 , V_4 -> V_7 ) ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
V_52 = V_51 ;
if ( V_52 > 0xFFFFF )
V_52 = 0xFFFFF ;
V_51 -= V_52 ;
F_14 ( V_4 , F_6 ( V_19 , 1 , 0 , 0 , V_52 ) ) ;
F_14 ( V_4 , F_7 ( V_40 ) ) ;
F_14 ( V_4 , F_7 ( V_39 ) ) ;
F_14 ( V_4 , F_8 ( V_40 ) & 0xff ) ;
F_14 ( V_4 , F_8 ( V_39 ) & 0xff ) ;
V_39 += V_52 ;
V_40 += V_52 ;
}
V_55 = F_24 ( V_2 , & V_46 , V_4 -> V_7 ) ;
if ( V_55 ) {
F_25 ( V_2 , V_4 ) ;
F_21 ( V_2 , & V_45 , NULL ) ;
return F_18 ( V_55 ) ;
}
F_26 ( V_2 , V_4 , false ) ;
F_21 ( V_2 , & V_45 , V_46 ) ;
return V_46 ;
}
