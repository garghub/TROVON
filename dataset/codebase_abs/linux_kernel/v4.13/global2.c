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
return F_3 ( V_2 , V_12 ,
0xffff ) ;
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
T_1 V_4 = ( V_20 << 12 ) | ( V_7 & F_14 ( V_2 ) ) ;
if ( V_21 )
V_4 |= V_22 ;
return F_5 ( V_2 , V_23 , V_4 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_24 ,
T_1 V_25 )
{
const T_1 V_26 = F_16 ( F_17 ( V_2 ) ) - 1 ;
T_1 V_4 = ( V_24 << 11 ) | ( V_25 & V_26 ) ;
return F_5 ( V_2 , V_27 , V_4 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
const T_1 V_26 = F_16 ( F_17 ( V_2 ) ) - 1 ;
int V_28 , V_8 ;
for ( V_28 = 0 ; V_28 < 8 ; ++ V_28 ) {
V_8 = F_13 ( V_2 , V_28 , false , V_26 ) ;
if ( V_8 )
return V_8 ;
}
for ( V_28 = 0 ; V_28 < 16 ; ++ V_28 ) {
V_8 = F_15 ( V_2 , V_28 , 0 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_29 ,
V_30 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_31 , int V_14 ,
int V_32 , int V_3 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_29 ,
V_30 | V_31 | ( V_14 << 8 ) |
( V_32 << 5 ) | V_3 ) ;
if ( V_8 )
return V_8 ;
return F_19 ( V_2 ) ;
}
int F_21 ( struct V_1 * V_2 , int V_14 )
{
return F_20 ( V_2 , V_33 , V_14 ,
0 , 0 ) ;
}
int F_22 ( struct V_1 * V_2 , int V_14 )
{
return F_20 ( V_2 , V_34 , V_14 ,
0 , 0 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_35 ,
V_36 ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_37 ,
int V_38 , T_1 V_31 )
{
int V_8 ;
V_31 |= V_36 ;
V_31 |= ( V_37 & 0x1f ) << 4 ;
V_31 |= ( V_38 & 0xf ) ;
V_8 = F_3 ( V_2 , V_35 , V_31 ) ;
if ( V_8 )
return V_8 ;
return F_23 ( V_2 ) ;
}
int F_25 ( struct V_1 * V_2 , int V_37 ,
int V_38 , T_1 V_39 )
{
int V_8 ;
V_8 = F_23 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_40 , V_39 ) ;
if ( V_8 )
return V_8 ;
return F_24 ( V_2 , V_37 , V_38 ,
V_41 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
unsigned int V_42 , T_2 V_39 )
{
T_1 V_4 = ( V_42 << 8 ) | V_39 ;
return F_5 ( V_2 , V_43 , V_4 ) ;
}
int F_27 ( struct V_1 * V_2 , T_2 * V_44 )
{
int V_28 , V_8 ;
for ( V_28 = 0 ; V_28 < 6 ; V_28 ++ ) {
V_8 = F_26 ( V_2 , V_28 , V_44 [ V_28 ] ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static int F_28 ( struct V_1 * V_2 , int V_42 ,
T_2 V_39 )
{
T_1 V_4 = ( V_42 << 8 ) | ( V_39 & 0x7 ) ;
return F_5 ( V_2 , V_45 , V_4 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_28 , V_8 ;
for ( V_28 = 0 ; V_28 < 16 ; V_28 ++ ) {
V_8 = F_28 ( V_2 , V_28 , 0 ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static int F_30 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_46 ,
V_47 |
V_48 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_49 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_46 ,
V_47 | V_49 ) ;
if ( V_8 )
return V_8 ;
return F_30 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
T_1 V_44 , T_2 * V_39 )
{
T_1 V_49 = V_50 ;
int V_8 ;
V_8 = F_30 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_51 , V_44 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_31 ( V_2 , V_49 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_2 , V_46 , & V_49 ) ;
if ( V_8 )
return V_8 ;
* V_39 = V_49 & 0xff ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
T_1 V_44 , T_2 V_39 )
{
T_1 V_49 = V_52 |
V_53 ;
int V_8 ;
V_8 = F_30 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_51 , V_44 ) ;
if ( V_8 )
return V_8 ;
return F_31 ( V_2 , V_49 | V_39 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
T_2 V_44 , T_1 * V_39 )
{
T_1 V_49 = V_50 | V_44 ;
int V_8 ;
V_8 = F_30 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_31 ( V_2 , V_49 ) ;
if ( V_8 )
return V_8 ;
return F_1 ( V_2 , V_54 , V_39 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
T_2 V_44 , T_1 V_39 )
{
T_1 V_49 = V_52 | V_44 ;
int V_8 ;
V_8 = F_30 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_54 , V_39 ) ;
if ( V_8 )
return V_8 ;
return F_31 ( V_2 , V_49 ) ;
}
int F_36 ( struct V_1 * V_2 ,
struct V_55 * V_56 , T_2 * V_39 )
{
unsigned int V_57 = V_56 -> V_57 ;
unsigned int V_58 = V_56 -> V_58 ;
int V_8 ;
V_56 -> V_58 = 0 ;
while ( V_58 ) {
V_8 = F_32 ( V_2 , V_57 , V_39 ) ;
if ( V_8 )
return V_8 ;
V_56 -> V_58 ++ ;
V_57 ++ ;
V_39 ++ ;
V_58 -- ;
}
return 0 ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_55 * V_56 , T_2 * V_39 )
{
unsigned int V_57 = V_56 -> V_57 ;
unsigned int V_58 = V_56 -> V_58 ;
int V_8 ;
V_56 -> V_58 = 0 ;
while ( V_58 ) {
V_8 = F_33 ( V_2 , V_57 , * V_39 ) ;
if ( V_8 )
return V_8 ;
V_56 -> V_58 ++ ;
V_57 ++ ;
V_39 ++ ;
V_58 -- ;
}
return 0 ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_55 * V_56 , T_2 * V_39 )
{
unsigned int V_57 = V_56 -> V_57 ;
unsigned int V_58 = V_56 -> V_58 ;
T_1 V_4 ;
int V_8 ;
V_56 -> V_58 = 0 ;
if ( V_57 & 1 ) {
V_8 = F_34 ( V_2 , V_57 >> 1 , & V_4 ) ;
if ( V_8 )
return V_8 ;
* V_39 ++ = ( V_4 >> 8 ) & 0xff ;
V_57 ++ ;
V_58 -- ;
V_56 -> V_58 ++ ;
}
while ( V_58 >= 2 ) {
V_8 = F_34 ( V_2 , V_57 >> 1 , & V_4 ) ;
if ( V_8 )
return V_8 ;
* V_39 ++ = V_4 & 0xff ;
* V_39 ++ = ( V_4 >> 8 ) & 0xff ;
V_57 += 2 ;
V_58 -= 2 ;
V_56 -> V_58 += 2 ;
}
if ( V_58 ) {
V_8 = F_34 ( V_2 , V_57 >> 1 , & V_4 ) ;
if ( V_8 )
return V_8 ;
* V_39 ++ = V_4 & 0xff ;
V_57 ++ ;
V_58 -- ;
V_56 -> V_58 ++ ;
}
return 0 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_55 * V_56 , T_2 * V_39 )
{
unsigned int V_57 = V_56 -> V_57 ;
unsigned int V_58 = V_56 -> V_58 ;
T_1 V_4 ;
int V_8 ;
V_8 = F_1 ( V_2 , V_46 , & V_4 ) ;
if ( V_8 )
return V_8 ;
if ( ! ( V_4 & V_53 ) )
return - V_59 ;
V_56 -> V_58 = 0 ;
if ( V_57 & 1 ) {
V_8 = F_34 ( V_2 , V_57 >> 1 , & V_4 ) ;
if ( V_8 )
return V_8 ;
V_4 = ( * V_39 ++ << 8 ) | ( V_4 & 0xff ) ;
V_8 = F_35 ( V_2 , V_57 >> 1 , V_4 ) ;
if ( V_8 )
return V_8 ;
V_57 ++ ;
V_58 -- ;
V_56 -> V_58 ++ ;
}
while ( V_58 >= 2 ) {
V_4 = * V_39 ++ ;
V_4 |= * V_39 ++ << 8 ;
V_8 = F_35 ( V_2 , V_57 >> 1 , V_4 ) ;
if ( V_8 )
return V_8 ;
V_57 += 2 ;
V_58 -= 2 ;
V_56 -> V_58 += 2 ;
}
if ( V_58 ) {
V_8 = F_34 ( V_2 , V_57 >> 1 , & V_4 ) ;
if ( V_8 )
return V_8 ;
V_4 = ( V_4 & 0xff00 ) | * V_39 ++ ;
V_8 = F_35 ( V_2 , V_57 >> 1 , V_4 ) ;
if ( V_8 )
return V_8 ;
V_57 ++ ;
V_58 -- ;
V_56 -> V_58 ++ ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_60 ,
V_61 ) ;
}
static int F_41 ( struct V_1 * V_2 , T_1 V_49 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_60 ,
V_61 | V_49 ) ;
if ( V_8 )
return V_8 ;
return F_40 ( V_2 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
bool V_62 , bool V_63 , T_1 V_31 , int V_64 ,
int V_3 )
{
T_1 V_49 = V_31 ;
if ( V_62 )
V_49 |= V_65 ;
else
V_49 |= V_66 ;
if ( V_63 )
V_49 |= V_67 ;
else
V_49 |= V_68 ;
V_64 <<= F_43 ( V_69 ) ;
V_49 |= V_64 & V_69 ;
V_49 |= V_3 & V_70 ;
return F_41 ( V_2 , V_49 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
bool V_62 , T_1 V_31 , int V_64 ,
int V_3 )
{
return F_42 ( V_2 , V_62 , false , V_31 , V_64 , V_3 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
bool V_62 , int V_64 , int V_3 ,
T_1 * V_39 )
{
T_1 V_31 = V_71 ;
int V_8 ;
V_8 = F_40 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_44 ( V_2 , V_62 , V_31 , V_64 , V_3 ) ;
if ( V_8 )
return V_8 ;
return F_1 ( V_2 , V_72 , V_39 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
bool V_62 , int V_64 , int V_3 ,
T_1 V_39 )
{
T_1 V_31 = V_73 ;
int V_8 ;
V_8 = F_40 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_72 , V_39 ) ;
if ( V_8 )
return V_8 ;
return F_44 ( V_2 , V_62 , V_31 , V_64 , V_3 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
bool V_62 , T_1 V_31 , int V_14 ,
int V_64 )
{
return F_42 ( V_2 , V_62 , true , V_31 , V_14 , V_64 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
bool V_62 , int V_14 , int V_64 ,
int V_44 )
{
T_1 V_31 = V_74 ;
int V_8 ;
V_8 = F_40 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_72 , V_44 ) ;
if ( V_8 )
return V_8 ;
return F_47 ( V_2 , V_62 , V_31 , V_14 , V_64 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
bool V_62 , int V_14 , int V_64 ,
T_1 * V_39 )
{
T_1 V_31 = V_75 ;
int V_8 ;
V_8 = F_47 ( V_2 , V_62 , V_31 , V_14 , V_64 ) ;
if ( V_8 )
return V_8 ;
return F_1 ( V_2 , V_72 , V_39 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
bool V_62 , int V_14 , int V_3 ,
T_1 * V_39 )
{
int V_64 = ( V_3 >> 16 ) & 0x1f ;
int V_44 = V_3 & 0xffff ;
int V_8 ;
V_8 = F_48 ( V_2 , V_62 , V_14 , V_64 ,
V_44 ) ;
if ( V_8 )
return V_8 ;
return F_49 ( V_2 , V_62 , V_14 , V_64 ,
V_39 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
bool V_62 , int V_14 , int V_64 ,
T_1 V_39 )
{
T_1 V_31 = V_76 ;
int V_8 ;
V_8 = F_3 ( V_2 , V_72 , V_39 ) ;
if ( V_8 )
return V_8 ;
return F_47 ( V_2 , V_62 , V_31 , V_14 , V_64 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
bool V_62 , int V_14 , int V_3 ,
T_1 V_39 )
{
int V_64 = ( V_3 >> 16 ) & 0x1f ;
int V_44 = V_3 & 0xffff ;
int V_8 ;
V_8 = F_48 ( V_2 , V_62 , V_14 , V_64 ,
V_44 ) ;
if ( V_8 )
return V_8 ;
return F_51 ( V_2 , V_62 , V_14 , V_64 ,
V_39 ) ;
}
int F_53 ( struct V_1 * V_2 , struct V_77 * V_78 ,
int V_44 , int V_3 , T_1 * V_4 )
{
struct V_79 * V_80 = V_78 -> V_81 ;
bool V_62 = V_80 -> V_62 ;
if ( V_3 & V_82 )
return F_50 ( V_2 , V_62 , V_44 , V_3 ,
V_4 ) ;
return F_45 ( V_2 , V_62 , V_44 , V_3 ,
V_4 ) ;
}
int F_54 ( struct V_1 * V_2 , struct V_77 * V_78 ,
int V_44 , int V_3 , T_1 V_4 )
{
struct V_79 * V_80 = V_78 -> V_81 ;
bool V_62 = V_80 -> V_62 ;
if ( V_3 & V_82 )
return F_52 ( V_2 , V_62 , V_44 , V_3 ,
V_4 ) ;
return F_46 ( V_2 , V_62 , V_44 , V_3 ,
V_4 ) ;
}
static int F_55 ( struct V_1 * V_2 , int V_83 )
{
T_1 V_3 ;
F_1 ( V_2 , V_84 , & V_3 ) ;
F_56 ( V_2 -> V_64 , L_1 , V_3 ) ;
return V_85 ;
}
static void F_57 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_1 ( V_2 , V_84 , & V_3 ) ;
V_3 &= ~ ( V_86 |
V_87 ) ;
F_3 ( V_2 , V_84 , V_3 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_84 ,
V_86 |
V_87 |
V_88 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_89 ,
V_90 |
V_91 |
V_92 |
V_93 |
V_94 ) ;
}
static int F_60 ( struct V_1 * V_2 , int V_83 )
{
int V_8 ;
T_1 V_3 ;
F_3 ( V_2 , V_89 ,
V_95 ) ;
V_8 = F_1 ( V_2 , V_89 , & V_3 ) ;
F_56 ( V_2 -> V_64 , L_1 ,
V_3 & V_96 ) ;
F_3 ( V_2 , V_89 ,
V_97 ) ;
V_8 = F_1 ( V_2 , V_89 , & V_3 ) ;
F_56 ( V_2 -> V_64 , L_2 ,
V_3 & V_96 ) ;
if ( V_2 -> V_98 -> V_99 -> V_100 )
V_2 -> V_98 -> V_99 -> V_100 ( V_2 ) ;
F_59 ( V_2 ) ;
return V_85 ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_89 ,
V_90 ) ;
}
static T_3 F_62 ( int V_83 , void * V_101 )
{
struct V_1 * V_2 = V_101 ;
T_3 V_102 = V_103 ;
F_63 ( & V_2 -> V_104 ) ;
if ( V_2 -> V_98 -> V_99 -> V_105 -> V_106 )
V_102 = V_2 -> V_98 -> V_99 -> V_105 -> V_106 ( V_2 , V_83 ) ;
F_64 ( & V_2 -> V_104 ) ;
return V_102 ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_63 ( & V_2 -> V_104 ) ;
if ( V_2 -> V_98 -> V_99 -> V_105 -> V_107 )
V_2 -> V_98 -> V_99 -> V_105 -> V_107 ( V_2 ) ;
F_64 ( & V_2 -> V_104 ) ;
F_66 ( V_2 -> V_108 , V_2 ) ;
F_67 ( V_2 -> V_108 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_8 ;
V_2 -> V_108 = F_69 ( V_2 -> V_109 . V_110 ,
V_111 ) ;
if ( V_2 -> V_108 < 0 )
return V_2 -> V_108 ;
V_8 = F_70 ( V_2 -> V_108 , NULL ,
F_62 ,
V_112 | V_113 ,
L_3 , V_2 ) ;
if ( V_8 )
return V_8 ;
F_63 ( & V_2 -> V_104 ) ;
if ( V_2 -> V_98 -> V_99 -> V_105 -> V_114 )
V_8 = V_2 -> V_98 -> V_99 -> V_105 -> V_114 ( V_2 ) ;
F_64 ( & V_2 -> V_104 ) ;
return V_8 ;
}
static int F_71 ( struct V_1 * V_2 ,
bool V_115 )
{
T_1 V_4 ;
int V_8 ;
V_8 = F_1 ( V_2 , V_116 , & V_4 ) ;
if ( V_8 )
return V_8 ;
if ( V_115 )
V_4 |= V_117 ;
else
V_4 &= ~ V_117 ;
return F_3 ( V_2 , V_116 , V_4 ) ;
}
int F_72 ( struct V_1 * V_2 )
{
return F_71 ( V_2 , false ) ;
}
static void F_73 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_74 ( V_119 ) ;
unsigned int V_120 = V_119 -> V_121 ;
V_2 -> V_109 . V_122 |= ( 1 << V_120 ) ;
}
static void F_75 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_74 ( V_119 ) ;
unsigned int V_120 = V_119 -> V_121 ;
V_2 -> V_109 . V_122 &= ~ ( 1 << V_120 ) ;
}
static T_3 F_76 ( int V_83 , void * V_101 )
{
struct V_1 * V_2 = V_101 ;
unsigned int V_123 = 0 ;
unsigned int V_124 ;
unsigned int V_120 ;
int V_8 ;
T_1 V_3 ;
F_63 ( & V_2 -> V_104 ) ;
V_8 = F_1 ( V_2 , V_125 , & V_3 ) ;
F_64 ( & V_2 -> V_104 ) ;
if ( V_8 )
goto V_126;
for ( V_120 = 0 ; V_120 < 16 ; ++ V_120 ) {
if ( V_3 & ( 1 << V_120 ) ) {
V_124 = F_69 ( V_2 -> V_109 . V_110 , V_120 ) ;
F_77 ( V_124 ) ;
++ V_123 ;
}
}
V_126:
return ( V_123 > 0 ? V_85 : V_103 ) ;
}
static void F_78 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_74 ( V_119 ) ;
F_63 ( & V_2 -> V_104 ) ;
}
static void F_79 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_74 ( V_119 ) ;
F_3 ( V_2 , V_127 , ~ V_2 -> V_109 . V_122 ) ;
F_64 ( & V_2 -> V_104 ) ;
}
static int F_80 ( struct V_128 * V_119 ,
unsigned int V_83 ,
T_4 V_121 )
{
struct V_1 * V_2 = V_119 -> V_129 ;
F_81 ( V_83 , V_119 -> V_129 ) ;
F_82 ( V_83 , & V_2 -> V_109 . V_2 , V_130 ) ;
F_83 ( V_83 ) ;
return 0 ;
}
void F_84 ( struct V_1 * V_2 )
{
int V_83 , V_131 ;
F_65 ( V_2 ) ;
F_66 ( V_2 -> V_132 , V_2 ) ;
F_67 ( V_2 -> V_132 ) ;
for ( V_83 = 0 ; V_83 < 16 ; V_83 ++ ) {
V_131 = F_69 ( V_2 -> V_109 . V_110 , V_83 ) ;
F_67 ( V_131 ) ;
}
F_85 ( V_2 -> V_109 . V_110 ) ;
}
int F_86 ( struct V_1 * V_2 )
{
int V_8 , V_83 , V_131 ;
if ( ! V_2 -> V_64 -> V_133 )
return - V_134 ;
V_2 -> V_109 . V_110 = F_87 (
V_2 -> V_64 -> V_133 , 16 , 0 , & V_135 , V_2 ) ;
if ( ! V_2 -> V_109 . V_110 )
return - V_136 ;
for ( V_83 = 0 ; V_83 < 16 ; V_83 ++ )
F_88 ( V_2 -> V_109 . V_110 , V_83 ) ;
V_2 -> V_109 . V_2 = V_137 ;
V_2 -> V_109 . V_122 = ~ 0 ;
V_2 -> V_132 = F_69 ( V_2 -> V_138 . V_110 ,
V_139 ) ;
if ( V_2 -> V_132 < 0 ) {
V_8 = V_2 -> V_132 ;
goto V_126;
}
V_8 = F_70 ( V_2 -> V_132 , NULL ,
F_76 ,
V_112 , L_4 , V_2 ) ;
if ( V_8 )
goto V_126;
return F_68 ( V_2 ) ;
V_126:
for ( V_83 = 0 ; V_83 < 16 ; V_83 ++ ) {
V_131 = F_69 ( V_2 -> V_109 . V_110 , V_83 ) ;
F_67 ( V_131 ) ;
}
F_85 ( V_2 -> V_109 . V_110 ) ;
return V_8 ;
}
int F_89 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_8 ;
V_3 = V_140 | ( 0x7 << 4 ) ;
if ( F_10 ( V_2 , V_11 ) ||
F_10 ( V_2 , V_9 ) )
V_3 |= V_141 | 0x7 ;
V_8 = F_3 ( V_2 , V_142 , V_3 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_12 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_18 ( V_2 ) ;
if ( V_8 )
return V_8 ;
if ( F_10 ( V_2 , V_143 ) ) {
V_8 = F_29 ( V_2 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
