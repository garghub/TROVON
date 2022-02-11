T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_5 ;
if ( V_2 -> V_6 . V_7 )
V_5 = V_2 -> V_6 . V_6 [ V_4 -> V_8 / 4 ] ;
else
V_5 = F_2 ( V_9 ) ;
return ( V_5 & 0x3fffc ) >> 2 ;
}
T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ( F_2 ( V_10 ) & 0x3fffc ) >> 2 ;
}
void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_5 ( V_10 , ( V_4 -> V_11 << 2 ) & 0x3fffc ) ;
}
void F_6 ( struct V_1 * V_2 )
{
T_2 V_12 = F_2 ( V_13 ) ;
if ( V_2 -> V_14 -> V_15 . V_16 == V_17 )
F_7 ( V_2 , V_2 -> V_18 . V_19 ) ;
V_12 &= ~ V_20 ;
F_5 ( V_13 , V_12 ) ;
V_2 -> V_4 [ V_17 ] . V_21 = false ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_17 ] ;
T_2 V_12 , V_22 , V_23 ;
T_2 V_24 ;
int V_25 ;
F_5 ( V_26 , 0 ) ;
F_5 ( V_27 , 0 ) ;
V_24 = F_9 ( V_4 -> V_28 / 4 ) ;
V_12 = V_24 << 1 ;
#ifdef F_10
V_12 |= V_29 | V_30 ;
#endif
F_5 ( V_13 , V_12 ) ;
F_5 ( V_9 , 0 ) ;
F_5 ( V_10 , 0 ) ;
F_5 ( V_31 ,
F_11 ( V_2 -> V_6 . V_32 + V_33 ) & 0xFF ) ;
F_5 ( V_34 ,
( ( V_2 -> V_6 . V_32 + V_33 ) & 0xFFFFFFFC ) ) ;
if ( V_2 -> V_6 . V_7 )
V_12 |= V_35 ;
F_5 ( V_36 , V_4 -> V_32 >> 8 ) ;
V_23 = V_37 ;
#ifdef F_10
V_23 |= V_38 ;
#endif
F_5 ( V_39 , V_23 ) ;
V_22 = F_2 ( V_40 ) ;
V_22 &= ~ V_41 ;
F_5 ( V_40 , V_22 ) ;
if ( V_2 -> V_42 >= V_43 )
F_5 ( V_44 , 1 ) ;
V_4 -> V_11 = 0 ;
F_5 ( V_10 , V_4 -> V_11 << 2 ) ;
F_5 ( V_13 , V_12 | V_20 ) ;
V_4 -> V_21 = true ;
V_25 = F_12 ( V_2 , V_17 , V_4 ) ;
if ( V_25 ) {
V_4 -> V_21 = false ;
return V_25 ;
}
if ( V_2 -> V_14 -> V_15 . V_16 == V_17 )
F_7 ( V_2 , V_2 -> V_18 . V_45 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_14 ( V_2 , & V_2 -> V_4 [ V_17 ] ) ;
}
bool F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_46 = F_16 ( V_2 ) ;
if ( ! ( V_46 & V_47 ) ) {
F_17 ( V_2 , V_4 ) ;
return false ;
}
return F_18 ( V_2 , V_4 ) ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned V_48 ;
int V_25 ;
unsigned V_49 ;
T_2 V_50 ;
T_3 V_32 ;
if ( V_4 -> V_51 == V_17 )
V_49 = V_52 ;
else
V_49 = V_53 ;
V_32 = V_2 -> V_6 . V_32 + V_49 ;
V_50 = 0xCAFEDEAD ;
V_2 -> V_6 . V_6 [ V_49 / 4 ] = F_20 ( V_50 ) ;
V_25 = F_21 ( V_2 , V_4 , 4 ) ;
if ( V_25 ) {
F_22 ( L_1 , V_4 -> V_51 , V_25 ) ;
return V_25 ;
}
F_23 ( V_4 , F_24 ( V_54 , 0 , 0 , 1 ) ) ;
F_23 ( V_4 , F_25 ( V_32 ) ) ;
F_23 ( V_4 , F_11 ( V_32 ) & 0xff ) ;
F_23 ( V_4 , 0xDEADBEEF ) ;
F_26 ( V_2 , V_4 , false ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_55 ; V_48 ++ ) {
V_50 = F_27 ( V_2 -> V_6 . V_6 [ V_49 / 4 ] ) ;
if ( V_50 == 0xDEADBEEF )
break;
F_28 ( 1 ) ;
}
if ( V_48 < V_2 -> V_55 ) {
F_29 ( L_2 , V_4 -> V_51 , V_48 ) ;
} else {
F_22 ( L_3 ,
V_4 -> V_51 , V_50 ) ;
V_25 = - V_56 ;
}
return V_25 ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_58 -> V_4 ] ;
T_3 V_59 = V_2 -> V_60 [ V_58 -> V_4 ] . V_32 ;
F_23 ( V_4 , F_24 ( V_61 , 0 , 0 , 0 ) ) ;
F_23 ( V_4 , V_59 & 0xfffffffc ) ;
F_23 ( V_4 , ( F_11 ( V_59 ) & 0xff ) ) ;
F_23 ( V_4 , F_25 ( V_58 -> V_62 ) ) ;
F_23 ( V_4 , F_24 ( V_63 , 0 , 0 , 0 ) ) ;
}
bool F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_64 * V_65 ,
bool V_66 )
{
T_3 V_59 = V_65 -> V_32 ;
T_2 V_67 = V_66 ? 0 : 1 ;
F_23 ( V_4 , F_24 ( V_68 , 0 , V_67 , 0 ) ) ;
F_23 ( V_4 , V_59 & 0xfffffffc ) ;
F_23 ( V_4 , F_11 ( V_59 ) & 0xff ) ;
return true ;
}
int F_32 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_69 V_70 ;
unsigned V_48 ;
unsigned V_49 ;
int V_25 ;
T_2 V_50 = 0 ;
T_3 V_32 ;
if ( V_4 -> V_51 == V_17 )
V_49 = V_52 ;
else
V_49 = V_53 ;
V_32 = V_2 -> V_6 . V_32 + V_49 ;
V_25 = F_33 ( V_2 , V_4 -> V_51 , & V_70 , NULL , 256 ) ;
if ( V_25 ) {
F_22 ( L_4 , V_25 ) ;
return V_25 ;
}
V_70 . V_71 [ 0 ] = F_24 ( V_54 , 0 , 0 , 1 ) ;
V_70 . V_71 [ 1 ] = F_25 ( V_32 ) ;
V_70 . V_71 [ 2 ] = F_11 ( V_32 ) & 0xff ;
V_70 . V_71 [ 3 ] = 0xDEADBEEF ;
V_70 . V_72 = 4 ;
V_25 = F_34 ( V_2 , & V_70 , NULL , false ) ;
if ( V_25 ) {
F_35 ( V_2 , & V_70 ) ;
F_22 ( L_5 , V_25 ) ;
return V_25 ;
}
V_25 = F_36 ( V_70 . V_58 , false , F_37 (
V_73 ) ) ;
if ( V_25 < 0 ) {
F_22 ( L_6 , V_25 ) ;
return V_25 ;
} else if ( V_25 == 0 ) {
F_22 ( L_7 ) ;
return - V_74 ;
}
V_25 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_55 ; V_48 ++ ) {
V_50 = F_27 ( V_2 -> V_6 . V_6 [ V_49 / 4 ] ) ;
if ( V_50 == 0xDEADBEEF )
break;
F_28 ( 1 ) ;
}
if ( V_48 < V_2 -> V_55 ) {
F_29 ( L_8 , V_70 . V_58 -> V_4 , V_48 ) ;
} else {
F_22 ( L_9 , V_50 ) ;
V_25 = - V_56 ;
}
F_35 ( V_2 , & V_70 ) ;
return V_25 ;
}
void F_38 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_70 -> V_4 ] ;
if ( V_2 -> V_6 . V_7 ) {
T_2 V_75 = V_4 -> V_11 + 4 ;
while ( ( V_75 & 7 ) != 5 )
V_75 ++ ;
V_75 += 3 ;
F_23 ( V_4 , F_24 ( V_54 , 0 , 0 , 1 ) ) ;
F_23 ( V_4 , V_4 -> V_76 & 0xfffffffc ) ;
F_23 ( V_4 , F_11 ( V_4 -> V_76 ) & 0xff ) ;
F_23 ( V_4 , V_75 ) ;
}
while ( ( V_4 -> V_11 & 7 ) != 5 )
F_23 ( V_4 , F_24 ( V_77 , 0 , 0 , 0 ) ) ;
F_23 ( V_4 , F_24 ( V_78 , 0 , 0 , 0 ) ) ;
F_23 ( V_4 , ( V_70 -> V_32 & 0xFFFFFFE0 ) ) ;
F_23 ( V_4 , ( V_70 -> V_72 << 16 ) | ( F_11 ( V_70 -> V_32 ) & 0xFF ) ) ;
}
struct V_57 * F_39 ( struct V_1 * V_2 ,
T_4 V_79 , T_4 V_80 ,
unsigned V_81 ,
struct V_82 * V_83 )
{
struct V_57 * V_58 ;
struct V_84 V_85 ;
int V_86 = V_2 -> V_14 -> V_15 . V_87 ;
struct V_3 * V_4 = & V_2 -> V_4 [ V_86 ] ;
T_2 V_88 , V_89 ;
int V_48 , V_90 ;
int V_25 = 0 ;
F_40 ( & V_85 ) ;
V_88 = ( V_81 << V_91 ) / 4 ;
V_90 = F_41 ( V_88 , 0xFFFE ) ;
V_25 = F_21 ( V_2 , V_4 , V_90 * 4 + 8 ) ;
if ( V_25 ) {
F_22 ( L_10 , V_25 ) ;
F_42 ( V_2 , & V_85 , NULL ) ;
return F_43 ( V_25 ) ;
}
F_44 ( V_2 , & V_85 , V_83 , false ) ;
F_45 ( V_2 , & V_85 , V_4 -> V_51 ) ;
for ( V_48 = 0 ; V_48 < V_90 ; V_48 ++ ) {
V_89 = V_88 ;
if ( V_89 > 0xFFFE )
V_89 = 0xFFFE ;
V_88 -= V_89 ;
F_23 ( V_4 , F_24 ( V_92 , 0 , 0 , V_89 ) ) ;
F_23 ( V_4 , V_80 & 0xfffffffc ) ;
F_23 ( V_4 , V_79 & 0xfffffffc ) ;
F_23 ( V_4 , ( ( ( F_11 ( V_80 ) & 0xff ) << 16 ) |
( F_11 ( V_79 ) & 0xff ) ) ) ;
V_79 += V_89 * 4 ;
V_80 += V_89 * 4 ;
}
V_25 = F_46 ( V_2 , & V_58 , V_4 -> V_51 ) ;
if ( V_25 ) {
F_47 ( V_2 , V_4 ) ;
F_42 ( V_2 , & V_85 , NULL ) ;
return F_43 ( V_25 ) ;
}
F_26 ( V_2 , V_4 , false ) ;
F_42 ( V_2 , & V_85 , V_58 ) ;
return V_58 ;
}
