bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
if ( V_4 -> V_7 == V_8 )
V_6 = V_9 ;
else
V_6 = V_10 ;
if ( ! ( V_5 & V_6 ) ) {
F_3 ( V_4 ) ;
return false ;
}
F_4 ( V_2 , V_4 ) ;
return F_5 ( V_2 , V_4 ) ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
T_2 V_13 ,
T_2 V_14 , unsigned V_15 ,
T_3 V_16 , T_3 V_17 )
{
T_3 V_18 = F_7 ( V_2 , V_17 ) ;
T_2 V_19 ;
unsigned V_20 ;
if ( V_17 & V_21 ) {
while ( V_15 ) {
V_20 = V_15 * 2 ;
if ( V_20 > 0xFFFFE )
V_20 = 0xFFFFE ;
V_12 -> V_22 [ V_12 -> V_23 ++ ] = F_8 ( V_24 , 0 , 0 , 0 , V_20 ) ;
V_12 -> V_22 [ V_12 -> V_23 ++ ] = V_13 ;
V_12 -> V_22 [ V_12 -> V_23 ++ ] = F_9 ( V_13 ) & 0xff ;
for (; V_20 > 0 ; V_20 -= 2 , -- V_15 , V_13 += 8 ) {
if ( V_17 & V_21 ) {
V_19 = F_10 ( V_2 , V_14 ) ;
V_19 &= 0xFFFFFFFFFFFFF000ULL ;
} else if ( V_17 & V_25 ) {
V_19 = V_14 ;
} else {
V_19 = 0 ;
}
V_14 += V_16 ;
V_19 |= V_18 ;
V_12 -> V_22 [ V_12 -> V_23 ++ ] = V_19 ;
V_12 -> V_22 [ V_12 -> V_23 ++ ] = F_9 ( V_19 ) ;
}
}
} else {
while ( V_15 ) {
V_20 = V_15 * 2 ;
if ( V_20 > 0xFFFFE )
V_20 = 0xFFFFE ;
if ( V_17 & V_25 )
V_19 = V_14 ;
else
V_19 = 0 ;
V_12 -> V_22 [ V_12 -> V_23 ++ ] = F_11 ( V_20 ) ;
V_12 -> V_22 [ V_12 -> V_23 ++ ] = V_13 ;
V_12 -> V_22 [ V_12 -> V_23 ++ ] = F_9 ( V_13 ) & 0xff ;
V_12 -> V_22 [ V_12 -> V_23 ++ ] = V_18 ;
V_12 -> V_22 [ V_12 -> V_23 ++ ] = 0 ;
V_12 -> V_22 [ V_12 -> V_23 ++ ] = V_19 ;
V_12 -> V_22 [ V_12 -> V_23 ++ ] = F_9 ( V_19 ) ;
V_12 -> V_22 [ V_12 -> V_23 ++ ] = V_16 ;
V_12 -> V_22 [ V_12 -> V_23 ++ ] = 0 ;
V_13 += V_20 * 4 ;
V_14 += ( V_20 / 2 ) * V_16 ;
V_15 -= V_20 / 2 ;
}
}
while ( V_12 -> V_23 & 0x7 )
V_12 -> V_22 [ V_12 -> V_23 ++ ] = F_8 ( V_26 , 0 , 0 , 0 , 0 ) ;
}
void F_12 ( struct V_1 * V_2 , int V_27 , struct V_28 * V_29 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_27 ] ;
if ( V_29 == NULL )
return;
F_13 ( V_4 , F_8 ( V_30 , 0 , 0 , 0 , 0 ) ) ;
if ( V_29 -> V_31 < 8 ) {
F_13 ( V_4 , ( 0xf << 16 ) | ( ( V_32 + ( V_29 -> V_31 << 2 ) ) >> 2 ) ) ;
} else {
F_13 ( V_4 , ( 0xf << 16 ) | ( ( V_33 + ( ( V_29 -> V_31 - 8 ) << 2 ) ) >> 2 ) ) ;
}
F_13 ( V_4 , V_29 -> V_34 >> 12 ) ;
F_13 ( V_4 , F_8 ( V_30 , 0 , 0 , 0 , 0 ) ) ;
F_13 ( V_4 , ( 0xf << 16 ) | ( V_35 >> 2 ) ) ;
F_13 ( V_4 , 1 ) ;
F_13 ( V_4 , F_8 ( V_30 , 0 , 0 , 0 , 0 ) ) ;
F_13 ( V_4 , ( 0xf << 16 ) | ( V_36 >> 2 ) ) ;
F_13 ( V_4 , 1 << V_29 -> V_31 ) ;
}
int F_14 ( struct V_1 * V_2 ,
T_2 V_37 , T_2 V_38 ,
unsigned V_39 ,
struct V_40 * * V_41 )
{
struct V_42 * V_43 = NULL ;
int V_44 = V_2 -> V_45 -> V_46 . V_47 ;
struct V_3 * V_4 = & V_2 -> V_4 [ V_44 ] ;
T_1 V_48 , V_49 ;
int V_50 , V_51 ;
int V_52 = 0 ;
V_52 = F_15 ( V_2 , & V_43 ) ;
if ( V_52 ) {
F_16 ( L_1 , V_52 ) ;
return V_52 ;
}
V_48 = ( V_39 << V_53 ) ;
V_51 = F_17 ( V_48 , 0xfffff ) ;
V_52 = F_18 ( V_2 , V_4 , V_51 * 5 + 11 ) ;
if ( V_52 ) {
F_16 ( L_1 , V_52 ) ;
F_19 ( V_2 , & V_43 , NULL ) ;
return V_52 ;
}
if ( F_20 ( * V_41 , V_4 -> V_7 ) ) {
F_21 ( V_2 , V_43 , ( * V_41 ) -> V_4 ,
V_4 -> V_7 ) ;
F_22 ( * V_41 , V_4 -> V_7 ) ;
} else {
F_19 ( V_2 , & V_43 , NULL ) ;
}
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
V_49 = V_48 ;
if ( V_49 > 0xFFFFF )
V_49 = 0xFFFFF ;
V_48 -= V_49 ;
F_13 ( V_4 , F_8 ( V_54 , 1 , 0 , 0 , V_49 ) ) ;
F_13 ( V_4 , V_38 & 0xffffffff ) ;
F_13 ( V_4 , V_37 & 0xffffffff ) ;
F_13 ( V_4 , F_9 ( V_38 ) & 0xff ) ;
F_13 ( V_4 , F_9 ( V_37 ) & 0xff ) ;
V_37 += V_49 ;
V_38 += V_49 ;
}
V_52 = F_23 ( V_2 , V_41 , V_4 -> V_7 ) ;
if ( V_52 ) {
F_24 ( V_2 , V_4 ) ;
return V_52 ;
}
F_25 ( V_2 , V_4 ) ;
F_19 ( V_2 , & V_43 , * V_41 ) ;
return V_52 ;
}
