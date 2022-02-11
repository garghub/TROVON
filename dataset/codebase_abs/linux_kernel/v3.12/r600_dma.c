T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ( F_2 ( V_2 , V_4 ) & 0x3fffc ) >> 2 ;
}
T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ( F_4 ( V_4 -> V_5 ) & 0x3fffc ) >> 2 ;
}
void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_6 ( V_4 -> V_5 , ( V_4 -> V_6 << 2 ) & 0x3fffc ) ;
}
void F_7 ( struct V_1 * V_2 )
{
T_2 V_7 = F_4 ( V_8 ) ;
F_8 ( V_2 , V_2 -> V_9 . V_10 ) ;
V_7 &= ~ V_11 ;
F_6 ( V_8 , V_7 ) ;
V_2 -> V_4 [ V_12 ] . V_13 = false ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_12 ] ;
T_2 V_7 , V_14 , V_15 ;
T_2 V_16 ;
int V_17 ;
if ( V_2 -> V_18 >= V_19 )
F_6 ( V_20 , V_21 ) ;
else
F_6 ( V_20 , V_22 ) ;
F_4 ( V_20 ) ;
F_10 ( 50 ) ;
F_6 ( V_20 , 0 ) ;
F_6 ( V_23 , 0 ) ;
F_6 ( V_24 , 0 ) ;
V_16 = F_11 ( V_4 -> V_25 / 4 ) ;
V_7 = V_16 << 1 ;
#ifdef F_12
V_7 |= V_26 | V_27 ;
#endif
F_6 ( V_8 , V_7 ) ;
F_6 ( V_28 , 0 ) ;
F_6 ( V_29 , 0 ) ;
F_6 ( V_30 ,
F_13 ( V_2 -> V_31 . V_32 + V_33 ) & 0xFF ) ;
F_6 ( V_34 ,
( ( V_2 -> V_31 . V_32 + V_33 ) & 0xFFFFFFFC ) ) ;
if ( V_2 -> V_31 . V_35 )
V_7 |= V_36 ;
F_6 ( V_37 , V_4 -> V_32 >> 8 ) ;
V_15 = V_38 ;
#ifdef F_12
V_15 |= V_39 ;
#endif
F_6 ( V_40 , V_15 ) ;
V_14 = F_4 ( V_41 ) ;
V_14 &= ~ V_42 ;
F_6 ( V_41 , V_14 ) ;
if ( V_2 -> V_18 >= V_19 )
F_6 ( V_43 , 1 ) ;
V_4 -> V_6 = 0 ;
F_6 ( V_29 , V_4 -> V_6 << 2 ) ;
V_4 -> V_44 = F_4 ( V_28 ) >> 2 ;
F_6 ( V_8 , V_7 | V_11 ) ;
V_4 -> V_13 = true ;
V_17 = F_14 ( V_2 , V_12 , V_4 ) ;
if ( V_17 ) {
V_4 -> V_13 = false ;
return V_17 ;
}
F_8 ( V_2 , V_2 -> V_9 . V_45 ) ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_16 ( V_2 , & V_2 -> V_4 [ V_12 ] ) ;
}
bool F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_46 = F_18 ( V_2 ) ;
if ( ! ( V_46 & V_47 ) ) {
F_19 ( V_4 ) ;
return false ;
}
F_20 ( V_2 , V_4 ) ;
return F_21 ( V_2 , V_4 ) ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned V_48 ;
int V_17 ;
void T_3 * V_49 = ( void * ) V_2 -> V_50 . V_49 ;
T_2 V_51 ;
if ( ! V_49 ) {
F_23 ( L_1 ) ;
return - V_52 ;
}
V_51 = 0xCAFEDEAD ;
F_24 ( V_51 , V_49 ) ;
V_17 = F_25 ( V_2 , V_4 , 4 ) ;
if ( V_17 ) {
F_23 ( L_2 , V_4 -> V_53 , V_17 ) ;
return V_17 ;
}
F_26 ( V_4 , F_27 ( V_54 , 0 , 0 , 1 ) ) ;
F_26 ( V_4 , V_2 -> V_50 . V_32 & 0xfffffffc ) ;
F_26 ( V_4 , F_13 ( V_2 -> V_50 . V_32 ) & 0xff ) ;
F_26 ( V_4 , 0xDEADBEEF ) ;
F_28 ( V_2 , V_4 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_55 ; V_48 ++ ) {
V_51 = F_29 ( V_49 ) ;
if ( V_51 == 0xDEADBEEF )
break;
F_30 ( 1 ) ;
}
if ( V_48 < V_2 -> V_55 ) {
F_31 ( L_3 , V_4 -> V_53 , V_48 ) ;
} else {
F_23 ( L_4 ,
V_4 -> V_53 , V_51 ) ;
V_17 = - V_52 ;
}
return V_17 ;
}
void F_32 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_57 -> V_4 ] ;
T_4 V_58 = V_2 -> V_59 [ V_57 -> V_4 ] . V_32 ;
F_26 ( V_4 , F_27 ( V_60 , 0 , 0 , 0 ) ) ;
F_26 ( V_4 , V_58 & 0xfffffffc ) ;
F_26 ( V_4 , ( F_13 ( V_58 ) & 0xff ) ) ;
F_26 ( V_4 , F_33 ( V_57 -> V_61 ) ) ;
F_26 ( V_4 , F_27 ( V_62 , 0 , 0 , 0 ) ) ;
}
void F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_63 * V_64 ,
bool V_65 )
{
T_4 V_58 = V_64 -> V_32 ;
T_2 V_66 = V_65 ? 0 : 1 ;
F_26 ( V_4 , F_27 ( V_67 , 0 , V_66 , 0 ) ) ;
F_26 ( V_4 , V_58 & 0xfffffffc ) ;
F_26 ( V_4 , F_13 ( V_58 ) & 0xff ) ;
}
int F_35 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_68 V_69 ;
unsigned V_48 ;
int V_17 ;
void T_3 * V_49 = ( void * ) V_2 -> V_50 . V_49 ;
T_2 V_51 = 0 ;
if ( ! V_49 ) {
F_23 ( L_1 ) ;
return - V_52 ;
}
V_51 = 0xCAFEDEAD ;
F_24 ( V_51 , V_49 ) ;
V_17 = F_36 ( V_2 , V_4 -> V_53 , & V_69 , NULL , 256 ) ;
if ( V_17 ) {
F_23 ( L_5 , V_17 ) ;
return V_17 ;
}
V_69 . V_49 [ 0 ] = F_27 ( V_54 , 0 , 0 , 1 ) ;
V_69 . V_49 [ 1 ] = V_2 -> V_50 . V_32 & 0xfffffffc ;
V_69 . V_49 [ 2 ] = F_13 ( V_2 -> V_50 . V_32 ) & 0xff ;
V_69 . V_49 [ 3 ] = 0xDEADBEEF ;
V_69 . V_70 = 4 ;
V_17 = F_37 ( V_2 , & V_69 , NULL ) ;
if ( V_17 ) {
F_38 ( V_2 , & V_69 ) ;
F_23 ( L_6 , V_17 ) ;
return V_17 ;
}
V_17 = F_39 ( V_69 . V_57 , false ) ;
if ( V_17 ) {
F_23 ( L_7 , V_17 ) ;
return V_17 ;
}
for ( V_48 = 0 ; V_48 < V_2 -> V_55 ; V_48 ++ ) {
V_51 = F_29 ( V_49 ) ;
if ( V_51 == 0xDEADBEEF )
break;
F_30 ( 1 ) ;
}
if ( V_48 < V_2 -> V_55 ) {
F_31 ( L_8 , V_69 . V_57 -> V_4 , V_48 ) ;
} else {
F_23 ( L_9 , V_51 ) ;
V_17 = - V_52 ;
}
F_38 ( V_2 , & V_69 ) ;
return V_17 ;
}
void F_40 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_69 -> V_4 ] ;
if ( V_2 -> V_31 . V_35 ) {
T_2 V_71 = V_4 -> V_6 + 4 ;
while ( ( V_71 & 7 ) != 5 )
V_71 ++ ;
V_71 += 3 ;
F_26 ( V_4 , F_27 ( V_54 , 0 , 0 , 1 ) ) ;
F_26 ( V_4 , V_4 -> V_72 & 0xfffffffc ) ;
F_26 ( V_4 , F_13 ( V_4 -> V_72 ) & 0xff ) ;
F_26 ( V_4 , V_71 ) ;
}
while ( ( V_4 -> V_6 & 7 ) != 5 )
F_26 ( V_4 , F_27 ( V_73 , 0 , 0 , 0 ) ) ;
F_26 ( V_4 , F_27 ( V_74 , 0 , 0 , 0 ) ) ;
F_26 ( V_4 , ( V_69 -> V_32 & 0xFFFFFFE0 ) ) ;
F_26 ( V_4 , ( V_69 -> V_70 << 16 ) | ( F_13 ( V_69 -> V_32 ) & 0xFF ) ) ;
}
int F_41 ( struct V_1 * V_2 ,
T_5 V_75 , T_5 V_76 ,
unsigned V_77 ,
struct V_56 * * V_57 )
{
struct V_63 * V_78 = NULL ;
int V_79 = V_2 -> V_80 -> V_81 . V_82 ;
struct V_3 * V_4 = & V_2 -> V_4 [ V_79 ] ;
T_2 V_83 , V_84 ;
int V_48 , V_85 ;
int V_17 = 0 ;
V_17 = F_42 ( V_2 , & V_78 ) ;
if ( V_17 ) {
F_23 ( L_10 , V_17 ) ;
return V_17 ;
}
V_83 = ( V_77 << V_86 ) / 4 ;
V_85 = F_43 ( V_83 , 0xFFFE ) ;
V_17 = F_25 ( V_2 , V_4 , V_85 * 4 + 8 ) ;
if ( V_17 ) {
F_23 ( L_10 , V_17 ) ;
F_44 ( V_2 , & V_78 , NULL ) ;
return V_17 ;
}
if ( F_45 ( * V_57 , V_4 -> V_53 ) ) {
F_46 ( V_2 , V_78 , ( * V_57 ) -> V_4 ,
V_4 -> V_53 ) ;
F_47 ( * V_57 , V_4 -> V_53 ) ;
} else {
F_44 ( V_2 , & V_78 , NULL ) ;
}
for ( V_48 = 0 ; V_48 < V_85 ; V_48 ++ ) {
V_84 = V_83 ;
if ( V_84 > 0xFFFE )
V_84 = 0xFFFE ;
V_83 -= V_84 ;
F_26 ( V_4 , F_27 ( V_87 , 0 , 0 , V_84 ) ) ;
F_26 ( V_4 , V_76 & 0xfffffffc ) ;
F_26 ( V_4 , V_75 & 0xfffffffc ) ;
F_26 ( V_4 , ( ( ( F_13 ( V_76 ) & 0xff ) << 16 ) |
( F_13 ( V_75 ) & 0xff ) ) ) ;
V_75 += V_84 * 4 ;
V_76 += V_84 * 4 ;
}
V_17 = F_48 ( V_2 , V_57 , V_4 -> V_53 ) ;
if ( V_17 ) {
F_49 ( V_2 , V_4 ) ;
return V_17 ;
}
F_28 ( V_2 , V_4 ) ;
F_44 ( V_2 , & V_78 , * V_57 ) ;
return V_17 ;
}
