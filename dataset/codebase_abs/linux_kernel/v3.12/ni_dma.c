void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 [ V_4 -> V_6 ] ;
if ( V_2 -> V_7 . V_8 ) {
T_1 V_9 = V_6 -> V_10 + 4 ;
while ( ( V_9 & 7 ) != 5 )
V_9 ++ ;
V_9 += 3 ;
F_2 ( V_6 , F_3 ( V_11 , 0 , 0 , 1 ) ) ;
F_2 ( V_6 , V_6 -> V_12 & 0xfffffffc ) ;
F_2 ( V_6 , F_4 ( V_6 -> V_12 ) & 0xff ) ;
F_2 ( V_6 , V_9 ) ;
}
while ( ( V_6 -> V_10 & 7 ) != 5 )
F_2 ( V_6 , F_3 ( V_13 , 0 , 0 , 0 ) ) ;
F_2 ( V_6 , F_5 ( V_14 , V_4 -> V_15 ? V_4 -> V_15 -> V_16 : 0 , 0 ) ) ;
F_2 ( V_6 , ( V_4 -> V_17 & 0xFFFFFFE0 ) ) ;
F_2 ( V_6 , ( V_4 -> V_18 << 12 ) | ( F_4 ( V_4 -> V_17 ) & 0xFF ) ) ;
}
void F_6 ( struct V_1 * V_2 )
{
T_1 V_19 ;
F_7 ( V_2 , V_2 -> V_20 . V_21 ) ;
V_19 = F_8 ( V_22 + V_23 ) ;
V_19 &= ~ V_24 ;
F_9 ( V_22 + V_23 , V_19 ) ;
V_19 = F_8 ( V_22 + V_25 ) ;
V_19 &= ~ V_24 ;
F_9 ( V_22 + V_25 , V_19 ) ;
V_2 -> V_6 [ V_26 ] . V_27 = false ;
V_2 -> V_6 [ V_28 ] . V_27 = false ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
T_1 V_19 , V_29 , V_30 ;
T_1 V_31 ;
T_1 V_32 , V_33 ;
int V_34 , V_35 ;
F_9 ( V_36 , V_37 | V_38 ) ;
F_8 ( V_36 ) ;
F_11 ( 50 ) ;
F_9 ( V_36 , 0 ) ;
for ( V_34 = 0 ; V_34 < 2 ; V_34 ++ ) {
if ( V_34 == 0 ) {
V_6 = & V_2 -> V_6 [ V_26 ] ;
V_32 = V_23 ;
V_33 = V_39 ;
} else {
V_6 = & V_2 -> V_6 [ V_28 ] ;
V_32 = V_25 ;
V_33 = V_40 ;
}
F_9 ( V_41 + V_32 , 0 ) ;
F_9 ( V_42 + V_32 , 0 ) ;
V_31 = F_12 ( V_6 -> V_43 / 4 ) ;
V_19 = V_31 << 1 ;
#ifdef F_13
V_19 |= V_44 | V_45 ;
#endif
F_9 ( V_22 + V_32 , V_19 ) ;
F_9 ( V_46 + V_32 , 0 ) ;
F_9 ( V_47 + V_32 , 0 ) ;
F_9 ( V_48 + V_32 ,
F_4 ( V_2 -> V_7 . V_17 + V_33 ) & 0xFF ) ;
F_9 ( V_49 + V_32 ,
( ( V_2 -> V_7 . V_17 + V_33 ) & 0xFFFFFFFC ) ) ;
if ( V_2 -> V_7 . V_8 )
V_19 |= V_50 ;
F_9 ( V_51 + V_32 , V_6 -> V_17 >> 8 ) ;
V_30 = V_52 | V_53 ;
#ifdef F_13
V_30 |= V_54 ;
#endif
F_9 ( V_55 + V_32 , V_30 ) ;
V_29 = F_8 ( V_56 + V_32 ) ;
V_29 &= ~ V_57 ;
F_9 ( V_56 + V_32 , V_29 ) ;
V_6 -> V_10 = 0 ;
F_9 ( V_47 + V_32 , V_6 -> V_10 << 2 ) ;
V_6 -> V_58 = F_8 ( V_46 + V_32 ) >> 2 ;
F_9 ( V_22 + V_32 , V_19 | V_24 ) ;
V_6 -> V_27 = true ;
V_35 = F_14 ( V_2 , V_6 -> V_59 , V_6 ) ;
if ( V_35 ) {
V_6 -> V_27 = false ;
return V_35 ;
}
}
F_7 ( V_2 , V_2 -> V_20 . V_60 ) ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_16 ( V_2 , & V_2 -> V_6 [ V_26 ] ) ;
F_16 ( V_2 , & V_2 -> V_6 [ V_28 ] ) ;
}
bool F_17 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_61 = F_18 ( V_2 ) ;
T_1 V_62 ;
if ( V_6 -> V_59 == V_26 )
V_62 = V_63 ;
else
V_62 = V_64 ;
if ( ! ( V_61 & V_62 ) ) {
F_19 ( V_6 ) ;
return false ;
}
F_20 ( V_2 , V_6 ) ;
return F_21 ( V_2 , V_6 ) ;
}
void F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_65 ,
T_2 V_66 , unsigned V_67 ,
T_3 V_68 , T_3 V_69 )
{
T_3 V_70 = F_23 ( V_2 , V_69 ) ;
T_2 V_71 ;
unsigned V_72 ;
if ( ( V_69 & V_73 ) || ( V_67 == 1 ) ) {
while ( V_67 ) {
V_72 = V_67 * 2 ;
if ( V_72 > 0xFFFFE )
V_72 = 0xFFFFE ;
V_4 -> V_74 [ V_4 -> V_18 ++ ] = F_3 ( V_11 , 0 , 0 , V_72 ) ;
V_4 -> V_74 [ V_4 -> V_18 ++ ] = V_65 ;
V_4 -> V_74 [ V_4 -> V_18 ++ ] = F_4 ( V_65 ) & 0xff ;
for (; V_72 > 0 ; V_72 -= 2 , -- V_67 , V_65 += 8 ) {
if ( V_69 & V_73 ) {
V_71 = F_24 ( V_2 , V_66 ) ;
V_71 &= 0xFFFFFFFFFFFFF000ULL ;
} else if ( V_69 & V_75 ) {
V_71 = V_66 ;
} else {
V_71 = 0 ;
}
V_66 += V_68 ;
V_71 |= V_70 ;
V_4 -> V_74 [ V_4 -> V_18 ++ ] = V_71 ;
V_4 -> V_74 [ V_4 -> V_18 ++ ] = F_4 ( V_71 ) ;
}
}
} else {
while ( V_67 ) {
V_72 = V_67 * 2 ;
if ( V_72 > 0xFFFFE )
V_72 = 0xFFFFE ;
if ( V_69 & V_75 )
V_71 = V_66 ;
else
V_71 = 0 ;
V_4 -> V_74 [ V_4 -> V_18 ++ ] = F_25 ( V_72 ) ;
V_4 -> V_74 [ V_4 -> V_18 ++ ] = V_65 ;
V_4 -> V_74 [ V_4 -> V_18 ++ ] = F_4 ( V_65 ) & 0xff ;
V_4 -> V_74 [ V_4 -> V_18 ++ ] = V_70 ;
V_4 -> V_74 [ V_4 -> V_18 ++ ] = 0 ;
V_4 -> V_74 [ V_4 -> V_18 ++ ] = V_71 ;
V_4 -> V_74 [ V_4 -> V_18 ++ ] = F_4 ( V_71 ) ;
V_4 -> V_74 [ V_4 -> V_18 ++ ] = V_68 ;
V_4 -> V_74 [ V_4 -> V_18 ++ ] = 0 ;
V_65 += V_72 * 4 ;
V_66 += ( V_72 / 2 ) * V_68 ;
V_67 -= V_72 / 2 ;
}
}
while ( V_4 -> V_18 & 0x7 )
V_4 -> V_74 [ V_4 -> V_18 ++ ] = F_3 ( V_13 , 0 , 0 , 0 ) ;
}
void F_26 ( struct V_1 * V_2 , int V_76 , struct V_77 * V_15 )
{
struct V_5 * V_6 = & V_2 -> V_6 [ V_76 ] ;
if ( V_15 == NULL )
return;
F_2 ( V_6 , F_3 ( V_78 , 0 , 0 , 0 ) ) ;
F_2 ( V_6 , ( 0xf << 16 ) | ( ( V_79 + ( V_15 -> V_16 << 2 ) ) >> 2 ) ) ;
F_2 ( V_6 , V_15 -> V_80 >> 12 ) ;
F_2 ( V_6 , F_3 ( V_78 , 0 , 0 , 0 ) ) ;
F_2 ( V_6 , ( 0xf << 16 ) | ( V_81 >> 2 ) ) ;
F_2 ( V_6 , 1 ) ;
F_2 ( V_6 , F_3 ( V_78 , 0 , 0 , 0 ) ) ;
F_2 ( V_6 , ( 0xf << 16 ) | ( V_82 >> 2 ) ) ;
F_2 ( V_6 , 1 << V_15 -> V_16 ) ;
}
