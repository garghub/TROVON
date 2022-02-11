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
if ( V_2 -> V_26 >= V_27 )
F_5 ( V_28 , V_29 ) ;
else
F_5 ( V_28 , V_30 ) ;
F_2 ( V_28 ) ;
F_9 ( 50 ) ;
F_5 ( V_28 , 0 ) ;
F_5 ( V_31 , 0 ) ;
F_5 ( V_32 , 0 ) ;
V_24 = F_10 ( V_4 -> V_33 / 4 ) ;
V_12 = V_24 << 1 ;
#ifdef F_11
V_12 |= V_34 | V_35 ;
#endif
F_5 ( V_13 , V_12 ) ;
F_5 ( V_9 , 0 ) ;
F_5 ( V_10 , 0 ) ;
F_5 ( V_36 ,
F_12 ( V_2 -> V_6 . V_37 + V_38 ) & 0xFF ) ;
F_5 ( V_39 ,
( ( V_2 -> V_6 . V_37 + V_38 ) & 0xFFFFFFFC ) ) ;
if ( V_2 -> V_6 . V_7 )
V_12 |= V_40 ;
F_5 ( V_41 , V_4 -> V_37 >> 8 ) ;
V_23 = V_42 ;
#ifdef F_11
V_23 |= V_43 ;
#endif
F_5 ( V_44 , V_23 ) ;
V_22 = F_2 ( V_45 ) ;
V_22 &= ~ V_46 ;
F_5 ( V_45 , V_22 ) ;
if ( V_2 -> V_26 >= V_27 )
F_5 ( V_47 , 1 ) ;
V_4 -> V_11 = 0 ;
F_5 ( V_10 , V_4 -> V_11 << 2 ) ;
F_5 ( V_13 , V_12 | V_20 ) ;
V_4 -> V_21 = true ;
V_25 = F_13 ( V_2 , V_17 , V_4 ) ;
if ( V_25 ) {
V_4 -> V_21 = false ;
return V_25 ;
}
if ( V_2 -> V_14 -> V_15 . V_16 == V_17 )
F_7 ( V_2 , V_2 -> V_18 . V_48 ) ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_15 ( V_2 , & V_2 -> V_4 [ V_17 ] ) ;
}
bool F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_49 = F_17 ( V_2 ) ;
if ( ! ( V_49 & V_50 ) ) {
F_18 ( V_2 , V_4 ) ;
return false ;
}
return F_19 ( V_2 , V_4 ) ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned V_51 ;
int V_25 ;
void T_3 * V_52 = ( void * ) V_2 -> V_53 . V_52 ;
T_2 V_54 ;
if ( ! V_52 ) {
F_21 ( L_1 ) ;
return - V_55 ;
}
V_54 = 0xCAFEDEAD ;
F_22 ( V_54 , V_52 ) ;
V_25 = F_23 ( V_2 , V_4 , 4 ) ;
if ( V_25 ) {
F_21 ( L_2 , V_4 -> V_56 , V_25 ) ;
return V_25 ;
}
F_24 ( V_4 , F_25 ( V_57 , 0 , 0 , 1 ) ) ;
F_24 ( V_4 , V_2 -> V_53 . V_37 & 0xfffffffc ) ;
F_24 ( V_4 , F_12 ( V_2 -> V_53 . V_37 ) & 0xff ) ;
F_24 ( V_4 , 0xDEADBEEF ) ;
F_26 ( V_2 , V_4 ) ;
for ( V_51 = 0 ; V_51 < V_2 -> V_58 ; V_51 ++ ) {
V_54 = F_27 ( V_52 ) ;
if ( V_54 == 0xDEADBEEF )
break;
F_28 ( 1 ) ;
}
if ( V_51 < V_2 -> V_58 ) {
F_29 ( L_3 , V_4 -> V_56 , V_51 ) ;
} else {
F_21 ( L_4 ,
V_4 -> V_56 , V_54 ) ;
V_25 = - V_55 ;
}
return V_25 ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_60 -> V_4 ] ;
T_4 V_61 = V_2 -> V_62 [ V_60 -> V_4 ] . V_37 ;
F_24 ( V_4 , F_25 ( V_63 , 0 , 0 , 0 ) ) ;
F_24 ( V_4 , V_61 & 0xfffffffc ) ;
F_24 ( V_4 , ( F_12 ( V_61 ) & 0xff ) ) ;
F_24 ( V_4 , F_31 ( V_60 -> V_64 ) ) ;
F_24 ( V_4 , F_25 ( V_65 , 0 , 0 , 0 ) ) ;
}
bool F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_66 * V_67 ,
bool V_68 )
{
T_4 V_61 = V_67 -> V_37 ;
T_2 V_69 = V_68 ? 0 : 1 ;
F_24 ( V_4 , F_25 ( V_70 , 0 , V_69 , 0 ) ) ;
F_24 ( V_4 , V_61 & 0xfffffffc ) ;
F_24 ( V_4 , F_12 ( V_61 ) & 0xff ) ;
return true ;
}
int F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_71 V_72 ;
unsigned V_51 ;
int V_25 ;
void T_3 * V_52 = ( void * ) V_2 -> V_53 . V_52 ;
T_2 V_54 = 0 ;
if ( ! V_52 ) {
F_21 ( L_1 ) ;
return - V_55 ;
}
V_54 = 0xCAFEDEAD ;
F_22 ( V_54 , V_52 ) ;
V_25 = F_34 ( V_2 , V_4 -> V_56 , & V_72 , NULL , 256 ) ;
if ( V_25 ) {
F_21 ( L_5 , V_25 ) ;
return V_25 ;
}
V_72 . V_52 [ 0 ] = F_25 ( V_57 , 0 , 0 , 1 ) ;
V_72 . V_52 [ 1 ] = V_2 -> V_53 . V_37 & 0xfffffffc ;
V_72 . V_52 [ 2 ] = F_12 ( V_2 -> V_53 . V_37 ) & 0xff ;
V_72 . V_52 [ 3 ] = 0xDEADBEEF ;
V_72 . V_73 = 4 ;
V_25 = F_35 ( V_2 , & V_72 , NULL ) ;
if ( V_25 ) {
F_36 ( V_2 , & V_72 ) ;
F_21 ( L_6 , V_25 ) ;
return V_25 ;
}
V_25 = F_37 ( V_72 . V_60 , false ) ;
if ( V_25 ) {
F_21 ( L_7 , V_25 ) ;
return V_25 ;
}
for ( V_51 = 0 ; V_51 < V_2 -> V_58 ; V_51 ++ ) {
V_54 = F_27 ( V_52 ) ;
if ( V_54 == 0xDEADBEEF )
break;
F_28 ( 1 ) ;
}
if ( V_51 < V_2 -> V_58 ) {
F_29 ( L_8 , V_72 . V_60 -> V_4 , V_51 ) ;
} else {
F_21 ( L_9 , V_54 ) ;
V_25 = - V_55 ;
}
F_36 ( V_2 , & V_72 ) ;
return V_25 ;
}
void F_38 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_72 -> V_4 ] ;
if ( V_2 -> V_6 . V_7 ) {
T_2 V_74 = V_4 -> V_11 + 4 ;
while ( ( V_74 & 7 ) != 5 )
V_74 ++ ;
V_74 += 3 ;
F_24 ( V_4 , F_25 ( V_57 , 0 , 0 , 1 ) ) ;
F_24 ( V_4 , V_4 -> V_75 & 0xfffffffc ) ;
F_24 ( V_4 , F_12 ( V_4 -> V_75 ) & 0xff ) ;
F_24 ( V_4 , V_74 ) ;
}
while ( ( V_4 -> V_11 & 7 ) != 5 )
F_24 ( V_4 , F_25 ( V_76 , 0 , 0 , 0 ) ) ;
F_24 ( V_4 , F_25 ( V_77 , 0 , 0 , 0 ) ) ;
F_24 ( V_4 , ( V_72 -> V_37 & 0xFFFFFFE0 ) ) ;
F_24 ( V_4 , ( V_72 -> V_73 << 16 ) | ( F_12 ( V_72 -> V_37 ) & 0xFF ) ) ;
}
int F_39 ( struct V_1 * V_2 ,
T_5 V_78 , T_5 V_79 ,
unsigned V_80 ,
struct V_59 * * V_60 )
{
struct V_66 * V_81 = NULL ;
int V_82 = V_2 -> V_14 -> V_15 . V_83 ;
struct V_3 * V_4 = & V_2 -> V_4 [ V_82 ] ;
T_2 V_84 , V_85 ;
int V_51 , V_86 ;
int V_25 = 0 ;
V_25 = F_40 ( V_2 , & V_81 ) ;
if ( V_25 ) {
F_21 ( L_10 , V_25 ) ;
return V_25 ;
}
V_84 = ( V_80 << V_87 ) / 4 ;
V_86 = F_41 ( V_84 , 0xFFFE ) ;
V_25 = F_23 ( V_2 , V_4 , V_86 * 4 + 8 ) ;
if ( V_25 ) {
F_21 ( L_10 , V_25 ) ;
F_42 ( V_2 , & V_81 , NULL ) ;
return V_25 ;
}
F_43 ( V_81 , * V_60 ) ;
F_44 ( V_2 , V_81 , V_4 -> V_56 ) ;
for ( V_51 = 0 ; V_51 < V_86 ; V_51 ++ ) {
V_85 = V_84 ;
if ( V_85 > 0xFFFE )
V_85 = 0xFFFE ;
V_84 -= V_85 ;
F_24 ( V_4 , F_25 ( V_88 , 0 , 0 , V_85 ) ) ;
F_24 ( V_4 , V_79 & 0xfffffffc ) ;
F_24 ( V_4 , V_78 & 0xfffffffc ) ;
F_24 ( V_4 , ( ( ( F_12 ( V_79 ) & 0xff ) << 16 ) |
( F_12 ( V_78 ) & 0xff ) ) ) ;
V_78 += V_85 * 4 ;
V_79 += V_85 * 4 ;
}
V_25 = F_45 ( V_2 , V_60 , V_4 -> V_56 ) ;
if ( V_25 ) {
F_46 ( V_2 , V_4 ) ;
F_42 ( V_2 , & V_81 , NULL ) ;
return V_25 ;
}
F_26 ( V_2 , V_4 ) ;
F_42 ( V_2 , & V_81 , * V_60 ) ;
return V_25 ;
}
