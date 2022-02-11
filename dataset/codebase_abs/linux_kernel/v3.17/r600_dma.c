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
void T_3 * V_49 = ( void * ) V_2 -> V_50 . V_49 ;
T_2 V_51 ;
if ( ! V_49 ) {
F_20 ( L_1 ) ;
return - V_52 ;
}
V_51 = 0xCAFEDEAD ;
F_21 ( V_51 , V_49 ) ;
V_25 = F_22 ( V_2 , V_4 , 4 ) ;
if ( V_25 ) {
F_20 ( L_2 , V_4 -> V_53 , V_25 ) ;
return V_25 ;
}
F_23 ( V_4 , F_24 ( V_54 , 0 , 0 , 1 ) ) ;
F_23 ( V_4 , V_2 -> V_50 . V_32 & 0xfffffffc ) ;
F_23 ( V_4 , F_11 ( V_2 -> V_50 . V_32 ) & 0xff ) ;
F_23 ( V_4 , 0xDEADBEEF ) ;
F_25 ( V_2 , V_4 , false ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_55 ; V_48 ++ ) {
V_51 = F_26 ( V_49 ) ;
if ( V_51 == 0xDEADBEEF )
break;
F_27 ( 1 ) ;
}
if ( V_48 < V_2 -> V_55 ) {
F_28 ( L_3 , V_4 -> V_53 , V_48 ) ;
} else {
F_20 ( L_4 ,
V_4 -> V_53 , V_51 ) ;
V_25 = - V_52 ;
}
return V_25 ;
}
void F_29 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_57 -> V_4 ] ;
T_4 V_58 = V_2 -> V_59 [ V_57 -> V_4 ] . V_32 ;
F_23 ( V_4 , F_24 ( V_60 , 0 , 0 , 0 ) ) ;
F_23 ( V_4 , V_58 & 0xfffffffc ) ;
F_23 ( V_4 , ( F_11 ( V_58 ) & 0xff ) ) ;
F_23 ( V_4 , F_30 ( V_57 -> V_61 ) ) ;
F_23 ( V_4 , F_24 ( V_62 , 0 , 0 , 0 ) ) ;
}
bool F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_63 * V_64 ,
bool V_65 )
{
T_4 V_58 = V_64 -> V_32 ;
T_2 V_66 = V_65 ? 0 : 1 ;
F_23 ( V_4 , F_24 ( V_67 , 0 , V_66 , 0 ) ) ;
F_23 ( V_4 , V_58 & 0xfffffffc ) ;
F_23 ( V_4 , F_11 ( V_58 ) & 0xff ) ;
return true ;
}
int F_32 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_68 V_69 ;
unsigned V_48 ;
int V_25 ;
void T_3 * V_49 = ( void * ) V_2 -> V_50 . V_49 ;
T_2 V_51 = 0 ;
if ( ! V_49 ) {
F_20 ( L_1 ) ;
return - V_52 ;
}
V_51 = 0xCAFEDEAD ;
F_21 ( V_51 , V_49 ) ;
V_25 = F_33 ( V_2 , V_4 -> V_53 , & V_69 , NULL , 256 ) ;
if ( V_25 ) {
F_20 ( L_5 , V_25 ) ;
return V_25 ;
}
V_69 . V_49 [ 0 ] = F_24 ( V_54 , 0 , 0 , 1 ) ;
V_69 . V_49 [ 1 ] = V_2 -> V_50 . V_32 & 0xfffffffc ;
V_69 . V_49 [ 2 ] = F_11 ( V_2 -> V_50 . V_32 ) & 0xff ;
V_69 . V_49 [ 3 ] = 0xDEADBEEF ;
V_69 . V_70 = 4 ;
V_25 = F_34 ( V_2 , & V_69 , NULL , false ) ;
if ( V_25 ) {
F_35 ( V_2 , & V_69 ) ;
F_20 ( L_6 , V_25 ) ;
return V_25 ;
}
V_25 = F_36 ( V_69 . V_57 , false ) ;
if ( V_25 ) {
F_20 ( L_7 , V_25 ) ;
return V_25 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_55 ; V_48 ++ ) {
V_51 = F_26 ( V_49 ) ;
if ( V_51 == 0xDEADBEEF )
break;
F_27 ( 1 ) ;
}
if ( V_48 < V_2 -> V_55 ) {
F_28 ( L_8 , V_69 . V_57 -> V_4 , V_48 ) ;
} else {
F_20 ( L_9 , V_51 ) ;
V_25 = - V_52 ;
}
F_35 ( V_2 , & V_69 ) ;
return V_25 ;
}
void F_37 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_69 -> V_4 ] ;
if ( V_2 -> V_6 . V_7 ) {
T_2 V_71 = V_4 -> V_11 + 4 ;
while ( ( V_71 & 7 ) != 5 )
V_71 ++ ;
V_71 += 3 ;
F_23 ( V_4 , F_24 ( V_54 , 0 , 0 , 1 ) ) ;
F_23 ( V_4 , V_4 -> V_72 & 0xfffffffc ) ;
F_23 ( V_4 , F_11 ( V_4 -> V_72 ) & 0xff ) ;
F_23 ( V_4 , V_71 ) ;
}
while ( ( V_4 -> V_11 & 7 ) != 5 )
F_23 ( V_4 , F_24 ( V_73 , 0 , 0 , 0 ) ) ;
F_23 ( V_4 , F_24 ( V_74 , 0 , 0 , 0 ) ) ;
F_23 ( V_4 , ( V_69 -> V_32 & 0xFFFFFFE0 ) ) ;
F_23 ( V_4 , ( V_69 -> V_70 << 16 ) | ( F_11 ( V_69 -> V_32 ) & 0xFF ) ) ;
}
int F_38 ( struct V_1 * V_2 ,
T_5 V_75 , T_5 V_76 ,
unsigned V_77 ,
struct V_56 * * V_57 )
{
struct V_63 * V_78 = NULL ;
int V_79 = V_2 -> V_14 -> V_15 . V_80 ;
struct V_3 * V_4 = & V_2 -> V_4 [ V_79 ] ;
T_2 V_81 , V_82 ;
int V_48 , V_83 ;
int V_25 = 0 ;
V_25 = F_39 ( V_2 , & V_78 ) ;
if ( V_25 ) {
F_20 ( L_10 , V_25 ) ;
return V_25 ;
}
V_81 = ( V_77 << V_84 ) / 4 ;
V_83 = F_40 ( V_81 , 0xFFFE ) ;
V_25 = F_22 ( V_2 , V_4 , V_83 * 4 + 8 ) ;
if ( V_25 ) {
F_20 ( L_10 , V_25 ) ;
F_41 ( V_2 , & V_78 , NULL ) ;
return V_25 ;
}
F_42 ( V_78 , * V_57 ) ;
F_43 ( V_2 , V_78 , V_4 -> V_53 ) ;
for ( V_48 = 0 ; V_48 < V_83 ; V_48 ++ ) {
V_82 = V_81 ;
if ( V_82 > 0xFFFE )
V_82 = 0xFFFE ;
V_81 -= V_82 ;
F_23 ( V_4 , F_24 ( V_85 , 0 , 0 , V_82 ) ) ;
F_23 ( V_4 , V_76 & 0xfffffffc ) ;
F_23 ( V_4 , V_75 & 0xfffffffc ) ;
F_23 ( V_4 , ( ( ( F_11 ( V_76 ) & 0xff ) << 16 ) |
( F_11 ( V_75 ) & 0xff ) ) ) ;
V_75 += V_82 * 4 ;
V_76 += V_82 * 4 ;
}
V_25 = F_44 ( V_2 , V_57 , V_4 -> V_53 ) ;
if ( V_25 ) {
F_45 ( V_2 , V_4 ) ;
F_41 ( V_2 , & V_78 , NULL ) ;
return V_25 ;
}
F_25 ( V_2 , V_4 , false ) ;
F_41 ( V_2 , & V_78 , * V_57 ) ;
return V_25 ;
}
