static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
return F_2 ( V_2 , V_5 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
return F_4 ( V_2 , V_5 , V_3 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_6 )
{
return F_6 ( V_2 , V_5 , V_3 , V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 , T_1 V_7 )
{
return F_8 ( V_2 , V_5 , V_3 , V_7 ) ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_8 ;
if ( F_10 ( V_2 , V_9 ) ) {
V_8 = F_3 ( V_2 , V_10 , 0xffff ) ;
if ( V_8 )
return V_8 ;
}
if ( F_10 ( V_2 , V_11 ) )
return F_3 ( V_2 , V_12 , 0xffff ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_13 , int V_14 )
{
T_1 V_4 = ( V_13 << 8 ) | ( V_14 & 0xf ) ;
return F_5 ( V_2 , V_15 , V_4 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_13 , V_14 ;
int V_8 ;
for ( V_13 = 0 ; V_13 < 32 ; ++ V_13 ) {
V_14 = 0xf ;
if ( V_13 < V_16 ) {
V_14 = V_2 -> V_17 -> V_18 [ V_13 ] ;
if ( V_14 == V_19 )
V_14 = 0xf ;
}
V_8 = F_11 ( V_2 , V_13 , V_14 ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static int F_13 ( struct V_1 * V_2 , int V_20 ,
bool V_21 , T_1 V_7 )
{
const T_1 V_22 = F_14 ( F_15 ( V_2 ) ) - 1 ;
T_1 V_4 = ( V_20 << 12 ) | ( V_7 & V_22 ) ;
if ( V_21 )
V_4 |= V_23 ;
return F_5 ( V_2 , V_24 , V_4 ) ;
}
static int F_16 ( struct V_1 * V_2 , int V_25 ,
T_1 V_26 )
{
const T_1 V_22 = F_14 ( F_15 ( V_2 ) ) - 1 ;
T_1 V_4 = ( V_25 << 11 ) | ( V_26 & V_22 ) ;
return F_5 ( V_2 , V_27 , V_4 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
const T_1 V_22 = F_14 ( F_15 ( V_2 ) ) - 1 ;
int V_28 , V_8 ;
for ( V_28 = 0 ; V_28 < 8 ; ++ V_28 ) {
V_8 = F_13 ( V_2 , V_28 , false , V_22 ) ;
if ( V_8 )
return V_8 ;
}
for ( V_28 = 0 ; V_28 < 16 ; ++ V_28 ) {
V_8 = F_16 ( V_2 , V_28 , 0 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_14 , V_8 ;
for ( V_14 = 0 ; V_14 < F_15 ( V_2 ) ; ++ V_14 ) {
V_8 = F_3 ( V_2 , V_29 ,
V_30 |
( V_14 << 8 ) ) ;
if ( V_8 )
break;
V_8 = F_7 ( V_2 , V_29 ,
V_31 ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned int V_32 , T_2 V_33 )
{
T_1 V_4 = ( V_32 << 8 ) | V_33 ;
return F_5 ( V_2 , V_34 , V_4 ) ;
}
int F_20 ( struct V_1 * V_2 , T_2 * V_35 )
{
int V_28 , V_8 ;
for ( V_28 = 0 ; V_28 < 6 ; V_28 ++ ) {
V_8 = F_19 ( V_2 , V_28 , V_35 [ V_28 ] ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static int F_21 ( struct V_1 * V_2 , int V_32 ,
T_2 V_33 )
{
T_1 V_4 = ( V_32 << 8 ) | ( V_33 & 0x7 ) ;
return F_5 ( V_2 , V_36 , V_4 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_28 , V_8 ;
for ( V_28 = 0 ; V_28 < 16 ; V_28 ++ ) {
V_8 = F_21 ( V_2 , V_28 , 0 ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static int F_23 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_37 ,
V_38 |
V_39 ) ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_40 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_37 , V_40 ) ;
if ( V_8 )
return V_8 ;
return F_23 ( V_2 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
T_1 V_35 , T_2 * V_33 )
{
T_1 V_40 = V_41 ;
int V_8 ;
V_8 = F_23 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_42 , V_35 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_24 ( V_2 , V_40 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_2 , V_37 , & V_40 ) ;
if ( V_8 )
return V_8 ;
* V_33 = V_40 & 0xff ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
T_1 V_35 , T_2 V_33 )
{
T_1 V_40 = V_43 | V_44 ;
int V_8 ;
V_8 = F_23 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_42 , V_35 ) ;
if ( V_8 )
return V_8 ;
return F_24 ( V_2 , V_40 | V_33 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
T_2 V_35 , T_1 * V_33 )
{
T_1 V_40 = V_41 | V_35 ;
int V_8 ;
V_8 = F_23 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_24 ( V_2 , V_40 ) ;
if ( V_8 )
return V_8 ;
return F_1 ( V_2 , V_45 , V_33 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
T_2 V_35 , T_1 V_33 )
{
T_1 V_40 = V_43 | V_35 ;
int V_8 ;
V_8 = F_23 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_45 , V_33 ) ;
if ( V_8 )
return V_8 ;
return F_24 ( V_2 , V_40 ) ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_46 * V_47 , T_2 * V_33 )
{
unsigned int V_48 = V_47 -> V_48 ;
unsigned int V_49 = V_47 -> V_49 ;
int V_8 ;
V_47 -> V_49 = 0 ;
while ( V_49 ) {
V_8 = F_25 ( V_2 , V_48 , V_33 ) ;
if ( V_8 )
return V_8 ;
V_47 -> V_49 ++ ;
V_48 ++ ;
V_33 ++ ;
V_49 -- ;
}
return 0 ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_46 * V_47 , T_2 * V_33 )
{
unsigned int V_48 = V_47 -> V_48 ;
unsigned int V_49 = V_47 -> V_49 ;
int V_8 ;
V_47 -> V_49 = 0 ;
while ( V_49 ) {
V_8 = F_26 ( V_2 , V_48 , * V_33 ) ;
if ( V_8 )
return V_8 ;
V_47 -> V_49 ++ ;
V_48 ++ ;
V_33 ++ ;
V_49 -- ;
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_46 * V_47 , T_2 * V_33 )
{
unsigned int V_48 = V_47 -> V_48 ;
unsigned int V_49 = V_47 -> V_49 ;
T_1 V_4 ;
int V_8 ;
V_47 -> V_49 = 0 ;
if ( V_48 & 1 ) {
V_8 = F_27 ( V_2 , V_48 >> 1 , & V_4 ) ;
if ( V_8 )
return V_8 ;
* V_33 ++ = ( V_4 >> 8 ) & 0xff ;
V_48 ++ ;
V_49 -- ;
V_47 -> V_49 ++ ;
}
while ( V_49 >= 2 ) {
V_8 = F_27 ( V_2 , V_48 >> 1 , & V_4 ) ;
if ( V_8 )
return V_8 ;
* V_33 ++ = V_4 & 0xff ;
* V_33 ++ = ( V_4 >> 8 ) & 0xff ;
V_48 += 2 ;
V_49 -= 2 ;
V_47 -> V_49 += 2 ;
}
if ( V_49 ) {
V_8 = F_27 ( V_2 , V_48 >> 1 , & V_4 ) ;
if ( V_8 )
return V_8 ;
* V_33 ++ = V_4 & 0xff ;
V_48 ++ ;
V_49 -- ;
V_47 -> V_49 ++ ;
}
return 0 ;
}
int F_32 ( struct V_1 * V_2 ,
struct V_46 * V_47 , T_2 * V_33 )
{
unsigned int V_48 = V_47 -> V_48 ;
unsigned int V_49 = V_47 -> V_49 ;
T_1 V_4 ;
int V_8 ;
V_8 = F_1 ( V_2 , V_37 , & V_4 ) ;
if ( V_8 )
return V_8 ;
if ( ! ( V_4 & V_44 ) )
return - V_50 ;
V_47 -> V_49 = 0 ;
if ( V_48 & 1 ) {
V_8 = F_27 ( V_2 , V_48 >> 1 , & V_4 ) ;
if ( V_8 )
return V_8 ;
V_4 = ( * V_33 ++ << 8 ) | ( V_4 & 0xff ) ;
V_8 = F_28 ( V_2 , V_48 >> 1 , V_4 ) ;
if ( V_8 )
return V_8 ;
V_48 ++ ;
V_49 -- ;
V_47 -> V_49 ++ ;
}
while ( V_49 >= 2 ) {
V_4 = * V_33 ++ ;
V_4 |= * V_33 ++ << 8 ;
V_8 = F_28 ( V_2 , V_48 >> 1 , V_4 ) ;
if ( V_8 )
return V_8 ;
V_48 += 2 ;
V_49 -= 2 ;
V_47 -> V_49 += 2 ;
}
if ( V_49 ) {
V_8 = F_27 ( V_2 , V_48 >> 1 , & V_4 ) ;
if ( V_8 )
return V_8 ;
V_4 = ( V_4 & 0xff00 ) | * V_33 ++ ;
V_8 = F_28 ( V_2 , V_48 >> 1 , V_4 ) ;
if ( V_8 )
return V_8 ;
V_48 ++ ;
V_49 -- ;
V_47 -> V_49 ++ ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_51 ,
V_52 ) ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_40 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_51 , V_40 ) ;
if ( V_8 )
return V_8 ;
return F_33 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
int V_35 , int V_53 , int V_3 ,
bool V_54 )
{
int V_40 = V_55 | ( V_35 << 5 ) | V_53 ;
int V_8 ;
if ( V_54 )
V_40 |= V_56 ;
V_8 = F_33 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_57 , V_3 ) ;
if ( V_8 )
return V_8 ;
return F_34 ( V_2 , V_40 ) ;
}
int F_36 ( struct V_1 * V_2 , int V_35 ,
int V_58 , T_1 * V_4 , bool V_54 )
{
int V_53 = ( V_58 >> 16 ) & 0x1f ;
int V_3 = V_58 & 0xffff ;
int V_8 ;
T_1 V_40 ;
V_8 = F_35 ( V_2 , V_35 , V_53 , V_3 ,
V_54 ) ;
if ( V_8 )
return V_8 ;
V_40 = V_59 | ( V_35 << 5 ) | V_53 ;
if ( V_54 )
V_40 |= V_56 ;
V_8 = F_34 ( V_2 , V_40 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_2 , V_57 , V_4 ) ;
if ( V_8 )
return V_8 ;
V_8 = * V_4 ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 , int V_35 ,
int V_3 , T_1 * V_4 , bool V_54 )
{
T_1 V_40 = V_60 | ( V_35 << 5 ) | V_3 ;
int V_8 ;
if ( V_54 )
V_40 |= V_56 ;
V_8 = F_33 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_34 ( V_2 , V_40 ) ;
if ( V_8 )
return V_8 ;
return F_1 ( V_2 , V_57 , V_4 ) ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
int V_35 , int V_3 , T_1 * V_4 )
{
struct V_63 * V_64 = V_62 -> V_65 ;
bool V_54 = V_64 -> V_54 ;
if ( V_3 & V_66 )
return F_36 ( V_2 , V_35 , V_3 , V_4 ,
V_54 ) ;
return F_37 ( V_2 , V_35 , V_3 , V_4 , V_54 ) ;
}
int F_39 ( struct V_1 * V_2 , int V_35 ,
int V_58 , T_1 V_4 , bool V_54 )
{
int V_53 = ( V_58 >> 16 ) & 0x1f ;
int V_3 = V_58 & 0xffff ;
int V_8 ;
T_1 V_40 ;
V_8 = F_35 ( V_2 , V_35 , V_53 , V_3 ,
V_54 ) ;
if ( V_8 )
return V_8 ;
V_40 = V_67 | ( V_35 << 5 ) | V_53 ;
if ( V_54 )
V_40 |= V_56 ;
V_8 = F_3 ( V_2 , V_57 , V_4 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_34 ( V_2 , V_40 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 , int V_35 ,
int V_3 , T_1 V_4 , bool V_54 )
{
T_1 V_40 = V_68 | ( V_35 << 5 ) | V_3 ;
int V_8 ;
if ( V_54 )
V_40 |= V_56 ;
V_8 = F_33 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_57 , V_4 ) ;
if ( V_8 )
return V_8 ;
return F_34 ( V_2 , V_40 ) ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
int V_35 , int V_3 , T_1 V_4 )
{
struct V_63 * V_64 = V_62 -> V_65 ;
bool V_54 = V_64 -> V_54 ;
if ( V_3 & V_66 )
return F_39 ( V_2 , V_35 , V_3 , V_4 ,
V_54 ) ;
return F_40 ( V_2 , V_35 , V_3 , V_4 , V_54 ) ;
}
static int F_42 ( struct V_1 * V_2 , int V_69 )
{
T_1 V_3 ;
F_1 ( V_2 , V_70 , & V_3 ) ;
F_43 ( V_2 -> V_71 , L_1 , V_3 ) ;
return V_72 ;
}
static void F_44 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_1 ( V_2 , V_70 , & V_3 ) ;
V_3 &= ~ ( V_73 |
V_74 ) ;
F_3 ( V_2 , V_70 , V_3 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_70 ,
V_73 |
V_74 |
V_75 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_70 ,
V_76 |
V_77 |
V_78 |
V_79 |
V_80 ) ;
}
static int F_47 ( struct V_1 * V_2 , int V_69 )
{
int V_8 ;
T_1 V_3 ;
F_3 ( V_2 , V_70 , V_81 ) ;
V_8 = F_1 ( V_2 , V_70 , & V_3 ) ;
F_43 ( V_2 -> V_71 , L_1 ,
V_3 & V_82 ) ;
F_3 ( V_2 , V_70 , V_83 ) ;
V_8 = F_1 ( V_2 , V_70 , & V_3 ) ;
F_43 ( V_2 -> V_71 , L_2 ,
V_3 & V_82 ) ;
if ( V_2 -> V_84 -> V_85 -> V_86 )
V_2 -> V_84 -> V_85 -> V_86 ( V_2 ) ;
F_46 ( V_2 ) ;
return V_72 ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_70 ,
V_76 ) ;
}
static T_3 F_49 ( int V_69 , void * V_87 )
{
struct V_1 * V_2 = V_87 ;
T_3 V_88 = V_89 ;
F_50 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_84 -> V_85 -> V_91 -> V_92 )
V_88 = V_2 -> V_84 -> V_85 -> V_91 -> V_92 ( V_2 , V_69 ) ;
F_51 ( & V_2 -> V_90 ) ;
return V_88 ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_50 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_84 -> V_85 -> V_91 -> V_93 )
V_2 -> V_84 -> V_85 -> V_91 -> V_93 ( V_2 ) ;
F_51 ( & V_2 -> V_90 ) ;
F_53 ( V_2 -> V_94 , V_2 ) ;
F_54 ( V_2 -> V_94 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_8 ;
V_2 -> V_94 = F_56 ( V_2 -> V_95 . V_96 ,
V_97 ) ;
if ( V_2 -> V_94 < 0 )
return V_2 -> V_94 ;
V_8 = F_57 ( V_2 -> V_94 , NULL ,
F_49 ,
V_98 | V_99 ,
L_3 , V_2 ) ;
if ( V_8 )
return V_8 ;
F_50 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_84 -> V_85 -> V_91 -> V_100 )
V_8 = V_2 -> V_84 -> V_85 -> V_91 -> V_100 ( V_2 ) ;
F_51 ( & V_2 -> V_90 ) ;
return V_8 ;
}
static void F_58 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_59 ( V_102 ) ;
unsigned int V_103 = V_102 -> V_104 ;
V_2 -> V_95 . V_105 |= ( 1 << V_103 ) ;
}
static void F_60 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_59 ( V_102 ) ;
unsigned int V_103 = V_102 -> V_104 ;
V_2 -> V_95 . V_105 &= ~ ( 1 << V_103 ) ;
}
static T_3 F_61 ( int V_69 , void * V_87 )
{
struct V_1 * V_2 = V_87 ;
unsigned int V_106 = 0 ;
unsigned int V_107 ;
unsigned int V_103 ;
int V_8 ;
T_1 V_3 ;
F_50 ( & V_2 -> V_90 ) ;
V_8 = F_1 ( V_2 , V_108 , & V_3 ) ;
F_51 ( & V_2 -> V_90 ) ;
if ( V_8 )
goto V_109;
for ( V_103 = 0 ; V_103 < 16 ; ++ V_103 ) {
if ( V_3 & ( 1 << V_103 ) ) {
V_107 = F_56 ( V_2 -> V_95 . V_96 , V_103 ) ;
F_62 ( V_107 ) ;
++ V_106 ;
}
}
V_109:
return ( V_106 > 0 ? V_72 : V_89 ) ;
}
static void F_63 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_59 ( V_102 ) ;
F_50 ( & V_2 -> V_90 ) ;
}
static void F_64 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_59 ( V_102 ) ;
F_3 ( V_2 , V_110 , ~ V_2 -> V_95 . V_105 ) ;
F_51 ( & V_2 -> V_90 ) ;
}
static int F_65 ( struct V_111 * V_102 ,
unsigned int V_69 ,
T_4 V_104 )
{
struct V_1 * V_2 = V_102 -> V_112 ;
F_66 ( V_69 , V_102 -> V_112 ) ;
F_67 ( V_69 , & V_2 -> V_95 . V_2 , V_113 ) ;
F_68 ( V_69 ) ;
return 0 ;
}
void F_69 ( struct V_1 * V_2 )
{
int V_69 , V_114 ;
F_52 ( V_2 ) ;
F_53 ( V_2 -> V_115 , V_2 ) ;
F_54 ( V_2 -> V_115 ) ;
for ( V_69 = 0 ; V_69 < 16 ; V_69 ++ ) {
V_114 = F_56 ( V_2 -> V_95 . V_96 , V_69 ) ;
F_54 ( V_114 ) ;
}
F_70 ( V_2 -> V_95 . V_96 ) ;
}
int F_71 ( struct V_1 * V_2 )
{
int V_8 , V_69 , V_114 ;
if ( ! V_2 -> V_71 -> V_116 )
return - V_117 ;
V_2 -> V_95 . V_96 = F_72 (
V_2 -> V_71 -> V_116 , 16 , 0 , & V_118 , V_2 ) ;
if ( ! V_2 -> V_95 . V_96 )
return - V_119 ;
for ( V_69 = 0 ; V_69 < 16 ; V_69 ++ )
F_73 ( V_2 -> V_95 . V_96 , V_69 ) ;
V_2 -> V_95 . V_2 = V_120 ;
V_2 -> V_95 . V_105 = ~ 0 ;
V_2 -> V_115 = F_56 ( V_2 -> V_121 . V_96 ,
V_122 ) ;
if ( V_2 -> V_115 < 0 ) {
V_8 = V_2 -> V_115 ;
goto V_109;
}
V_8 = F_57 ( V_2 -> V_115 , NULL ,
F_61 ,
V_98 , L_4 , V_2 ) ;
if ( V_8 )
goto V_109;
return F_55 ( V_2 ) ;
V_109:
for ( V_69 = 0 ; V_69 < 16 ; V_69 ++ ) {
V_114 = F_56 ( V_2 -> V_95 . V_96 , V_69 ) ;
F_54 ( V_114 ) ;
}
F_70 ( V_2 -> V_95 . V_96 ) ;
return V_8 ;
}
int F_74 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_8 ;
V_3 = V_123 | ( 0x7 << 4 ) ;
if ( F_10 ( V_2 , V_11 ) ||
F_10 ( V_2 , V_9 ) )
V_3 |= V_124 | 0x7 ;
V_8 = F_3 ( V_2 , V_125 , V_3 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_12 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_17 ( V_2 ) ;
if ( V_8 )
return V_8 ;
if ( F_10 ( V_2 , V_126 ) ) {
V_8 = F_18 ( V_2 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_10 ( V_2 , V_127 ) ) {
V_8 = F_3 ( V_2 , V_128 ,
V_129 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_10 ( V_2 , V_130 ) ) {
V_8 = F_22 ( V_2 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
