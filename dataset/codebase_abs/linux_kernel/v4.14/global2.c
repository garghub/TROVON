static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
return F_2 ( V_2 , V_2 -> V_5 -> V_6 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
return F_4 ( V_2 , V_2 -> V_5 -> V_6 , V_3 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_7 )
{
return F_6 ( V_2 , V_2 -> V_5 -> V_6 , V_3 , V_7 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 , T_1 V_8 )
{
return F_8 ( V_2 , V_2 -> V_5 -> V_6 , V_3 , V_8 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_9 )
{
return F_1 ( V_2 , V_10 , V_9 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_8 )
{
return F_3 ( V_2 , V_11 , V_8 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_12 )
{
return F_3 ( V_2 , V_13 , V_12 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_14 )
{
return F_3 ( V_2 , V_15 , V_14 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
bool V_16 )
{
T_1 V_4 ;
int V_17 ;
V_17 = F_1 ( V_2 , V_18 , & V_4 ) ;
if ( V_17 )
return V_17 ;
if ( V_16 )
V_4 |= V_19 ;
else
V_4 &= ~ V_19 ;
return F_3 ( V_2 , V_18 , V_4 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_17 ;
V_17 = F_12 ( V_2 , 0xffff ) ;
if ( V_17 )
return V_17 ;
return F_13 ( V_2 , true ) ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_17 ;
V_17 = F_11 ( V_2 , 0xffff ) ;
if ( V_17 )
return V_17 ;
return F_14 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
int V_20 , int V_21 )
{
T_1 V_4 = ( V_20 << 8 ) | ( V_21 & 0xf ) ;
return F_5 ( V_2 , V_22 , V_4 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_20 , V_21 ;
int V_17 ;
for ( V_20 = 0 ; V_20 < 32 ; ++ V_20 ) {
V_21 = 0xf ;
if ( V_20 < V_23 ) {
V_21 = V_2 -> V_24 -> V_25 [ V_20 ] ;
if ( V_21 == V_26 )
V_21 = 0xf ;
}
V_17 = F_16 ( V_2 , V_20 , V_21 ) ;
if ( V_17 )
break;
}
return V_17 ;
}
static int F_18 ( struct V_1 * V_2 , int V_27 ,
bool V_28 , T_1 V_8 )
{
T_1 V_4 = ( V_27 << 12 ) | ( V_8 & F_19 ( V_2 ) ) ;
if ( V_28 )
V_4 |= V_29 ;
return F_5 ( V_2 , V_30 , V_4 ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_31 ,
T_1 V_32 )
{
const T_1 V_33 = F_21 ( F_22 ( V_2 ) ) - 1 ;
T_1 V_4 = ( V_31 << 11 ) | ( V_32 & V_33 ) ;
return F_5 ( V_2 , V_34 , V_4 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
const T_1 V_33 = F_21 ( F_22 ( V_2 ) ) - 1 ;
int V_35 , V_17 ;
for ( V_35 = 0 ; V_35 < 8 ; ++ V_35 ) {
V_17 = F_18 ( V_2 , V_35 , false , V_33 ) ;
if ( V_17 )
return V_17 ;
}
for ( V_35 = 0 ; V_35 < 16 ; ++ V_35 ) {
V_17 = F_20 ( V_2 , V_35 , 0 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_36 ,
V_37 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_38 , int V_21 ,
int V_39 , int V_3 )
{
int V_17 ;
V_17 = F_3 ( V_2 , V_36 ,
V_37 | V_38 | ( V_21 << 8 ) |
( V_39 << 5 ) | V_3 ) ;
if ( V_17 )
return V_17 ;
return F_24 ( V_2 ) ;
}
int F_26 ( struct V_1 * V_2 , int V_21 )
{
return F_25 ( V_2 , V_40 , V_21 ,
0 , 0 ) ;
}
int F_27 ( struct V_1 * V_2 , int V_21 )
{
return F_25 ( V_2 , V_41 , V_21 ,
0 , 0 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_42 ,
V_43 ) ;
}
static int F_29 ( struct V_1 * V_2 , int V_44 ,
int V_45 , T_1 V_38 )
{
int V_17 ;
V_38 |= V_43 ;
V_38 |= ( V_44 & 0x1f ) << 4 ;
V_38 |= ( V_45 & 0xf ) ;
V_17 = F_3 ( V_2 , V_42 , V_38 ) ;
if ( V_17 )
return V_17 ;
return F_28 ( V_2 ) ;
}
int F_30 ( struct V_1 * V_2 , int V_44 ,
int V_45 , T_1 V_46 )
{
int V_17 ;
V_17 = F_28 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_3 ( V_2 , V_47 , V_46 ) ;
if ( V_17 )
return V_17 ;
return F_29 ( V_2 , V_44 , V_45 ,
V_48 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
unsigned int V_49 , T_2 V_46 )
{
T_1 V_4 = ( V_49 << 8 ) | V_46 ;
return F_5 ( V_2 , V_50 , V_4 ) ;
}
int F_32 ( struct V_1 * V_2 , T_2 * V_51 )
{
int V_35 , V_17 ;
for ( V_35 = 0 ; V_35 < 6 ; V_35 ++ ) {
V_17 = F_31 ( V_2 , V_35 , V_51 [ V_35 ] ) ;
if ( V_17 )
break;
}
return V_17 ;
}
static int F_33 ( struct V_1 * V_2 , int V_49 ,
T_2 V_46 )
{
T_1 V_4 = ( V_49 << 8 ) | ( V_46 & 0x7 ) ;
return F_5 ( V_2 , V_52 , V_4 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_35 , V_17 ;
for ( V_35 = 0 ; V_35 < 16 ; V_35 ++ ) {
V_17 = F_33 ( V_2 , V_35 , 0 ) ;
if ( V_17 )
break;
}
return V_17 ;
}
static int F_35 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_53 ,
V_54 |
V_55 ) ;
}
static int F_36 ( struct V_1 * V_2 , T_1 V_56 )
{
int V_17 ;
V_17 = F_3 ( V_2 , V_53 ,
V_54 | V_56 ) ;
if ( V_17 )
return V_17 ;
return F_35 ( V_2 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
T_1 V_51 , T_2 * V_46 )
{
T_1 V_56 = V_57 ;
int V_17 ;
V_17 = F_35 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_3 ( V_2 , V_58 , V_51 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_36 ( V_2 , V_56 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_1 ( V_2 , V_53 , & V_56 ) ;
if ( V_17 )
return V_17 ;
* V_46 = V_56 & 0xff ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
T_1 V_51 , T_2 V_46 )
{
T_1 V_56 = V_59 |
V_60 ;
int V_17 ;
V_17 = F_35 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_3 ( V_2 , V_58 , V_51 ) ;
if ( V_17 )
return V_17 ;
return F_36 ( V_2 , V_56 | V_46 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
T_2 V_51 , T_1 * V_46 )
{
T_1 V_56 = V_57 | V_51 ;
int V_17 ;
V_17 = F_35 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_36 ( V_2 , V_56 ) ;
if ( V_17 )
return V_17 ;
return F_1 ( V_2 , V_61 , V_46 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
T_2 V_51 , T_1 V_46 )
{
T_1 V_56 = V_59 | V_51 ;
int V_17 ;
V_17 = F_35 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_3 ( V_2 , V_61 , V_46 ) ;
if ( V_17 )
return V_17 ;
return F_36 ( V_2 , V_56 ) ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_62 * V_63 , T_2 * V_46 )
{
unsigned int V_64 = V_63 -> V_64 ;
unsigned int V_65 = V_63 -> V_65 ;
int V_17 ;
V_63 -> V_65 = 0 ;
while ( V_65 ) {
V_17 = F_37 ( V_2 , V_64 , V_46 ) ;
if ( V_17 )
return V_17 ;
V_63 -> V_65 ++ ;
V_64 ++ ;
V_46 ++ ;
V_65 -- ;
}
return 0 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_62 * V_63 , T_2 * V_46 )
{
unsigned int V_64 = V_63 -> V_64 ;
unsigned int V_65 = V_63 -> V_65 ;
int V_17 ;
V_63 -> V_65 = 0 ;
while ( V_65 ) {
V_17 = F_38 ( V_2 , V_64 , * V_46 ) ;
if ( V_17 )
return V_17 ;
V_63 -> V_65 ++ ;
V_64 ++ ;
V_46 ++ ;
V_65 -- ;
}
return 0 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_62 * V_63 , T_2 * V_46 )
{
unsigned int V_64 = V_63 -> V_64 ;
unsigned int V_65 = V_63 -> V_65 ;
T_1 V_4 ;
int V_17 ;
V_63 -> V_65 = 0 ;
if ( V_64 & 1 ) {
V_17 = F_39 ( V_2 , V_64 >> 1 , & V_4 ) ;
if ( V_17 )
return V_17 ;
* V_46 ++ = ( V_4 >> 8 ) & 0xff ;
V_64 ++ ;
V_65 -- ;
V_63 -> V_65 ++ ;
}
while ( V_65 >= 2 ) {
V_17 = F_39 ( V_2 , V_64 >> 1 , & V_4 ) ;
if ( V_17 )
return V_17 ;
* V_46 ++ = V_4 & 0xff ;
* V_46 ++ = ( V_4 >> 8 ) & 0xff ;
V_64 += 2 ;
V_65 -= 2 ;
V_63 -> V_65 += 2 ;
}
if ( V_65 ) {
V_17 = F_39 ( V_2 , V_64 >> 1 , & V_4 ) ;
if ( V_17 )
return V_17 ;
* V_46 ++ = V_4 & 0xff ;
V_64 ++ ;
V_65 -- ;
V_63 -> V_65 ++ ;
}
return 0 ;
}
int F_44 ( struct V_1 * V_2 ,
struct V_62 * V_63 , T_2 * V_46 )
{
unsigned int V_64 = V_63 -> V_64 ;
unsigned int V_65 = V_63 -> V_65 ;
T_1 V_4 ;
int V_17 ;
V_17 = F_1 ( V_2 , V_53 , & V_4 ) ;
if ( V_17 )
return V_17 ;
if ( ! ( V_4 & V_60 ) )
return - V_66 ;
V_63 -> V_65 = 0 ;
if ( V_64 & 1 ) {
V_17 = F_39 ( V_2 , V_64 >> 1 , & V_4 ) ;
if ( V_17 )
return V_17 ;
V_4 = ( * V_46 ++ << 8 ) | ( V_4 & 0xff ) ;
V_17 = F_40 ( V_2 , V_64 >> 1 , V_4 ) ;
if ( V_17 )
return V_17 ;
V_64 ++ ;
V_65 -- ;
V_63 -> V_65 ++ ;
}
while ( V_65 >= 2 ) {
V_4 = * V_46 ++ ;
V_4 |= * V_46 ++ << 8 ;
V_17 = F_40 ( V_2 , V_64 >> 1 , V_4 ) ;
if ( V_17 )
return V_17 ;
V_64 += 2 ;
V_65 -= 2 ;
V_63 -> V_65 += 2 ;
}
if ( V_65 ) {
V_17 = F_39 ( V_2 , V_64 >> 1 , & V_4 ) ;
if ( V_17 )
return V_17 ;
V_4 = ( V_4 & 0xff00 ) | * V_46 ++ ;
V_17 = F_40 ( V_2 , V_64 >> 1 , V_4 ) ;
if ( V_17 )
return V_17 ;
V_64 ++ ;
V_65 -- ;
V_63 -> V_65 ++ ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_67 ,
V_68 ) ;
}
static int F_46 ( struct V_1 * V_2 , T_1 V_56 )
{
int V_17 ;
V_17 = F_3 ( V_2 , V_67 ,
V_68 | V_56 ) ;
if ( V_17 )
return V_17 ;
return F_45 ( V_2 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
bool V_69 , bool V_70 , T_1 V_38 , int V_71 ,
int V_3 )
{
T_1 V_56 = V_38 ;
if ( V_69 )
V_56 |= V_72 ;
else
V_56 |= V_73 ;
if ( V_70 )
V_56 |= V_74 ;
else
V_56 |= V_75 ;
V_71 <<= F_48 ( V_76 ) ;
V_56 |= V_71 & V_76 ;
V_56 |= V_3 & V_77 ;
return F_46 ( V_2 , V_56 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
bool V_69 , T_1 V_38 , int V_71 ,
int V_3 )
{
return F_47 ( V_2 , V_69 , false , V_38 , V_71 , V_3 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
bool V_69 , int V_71 , int V_3 ,
T_1 * V_46 )
{
T_1 V_38 = V_78 ;
int V_17 ;
V_17 = F_45 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_49 ( V_2 , V_69 , V_38 , V_71 , V_3 ) ;
if ( V_17 )
return V_17 ;
return F_1 ( V_2 , V_79 , V_46 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
bool V_69 , int V_71 , int V_3 ,
T_1 V_46 )
{
T_1 V_38 = V_80 ;
int V_17 ;
V_17 = F_45 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_3 ( V_2 , V_79 , V_46 ) ;
if ( V_17 )
return V_17 ;
return F_49 ( V_2 , V_69 , V_38 , V_71 , V_3 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
bool V_69 , T_1 V_38 , int V_21 ,
int V_71 )
{
return F_47 ( V_2 , V_69 , true , V_38 , V_21 , V_71 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
bool V_69 , int V_21 , int V_71 ,
int V_51 )
{
T_1 V_38 = V_81 ;
int V_17 ;
V_17 = F_45 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_3 ( V_2 , V_79 , V_51 ) ;
if ( V_17 )
return V_17 ;
return F_52 ( V_2 , V_69 , V_38 , V_21 , V_71 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
bool V_69 , int V_21 , int V_71 ,
T_1 * V_46 )
{
T_1 V_38 = V_82 ;
int V_17 ;
V_17 = F_52 ( V_2 , V_69 , V_38 , V_21 , V_71 ) ;
if ( V_17 )
return V_17 ;
return F_1 ( V_2 , V_79 , V_46 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
bool V_69 , int V_21 , int V_3 ,
T_1 * V_46 )
{
int V_71 = ( V_3 >> 16 ) & 0x1f ;
int V_51 = V_3 & 0xffff ;
int V_17 ;
V_17 = F_53 ( V_2 , V_69 , V_21 , V_71 ,
V_51 ) ;
if ( V_17 )
return V_17 ;
return F_54 ( V_2 , V_69 , V_21 , V_71 ,
V_46 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
bool V_69 , int V_21 , int V_71 ,
T_1 V_46 )
{
T_1 V_38 = V_83 ;
int V_17 ;
V_17 = F_3 ( V_2 , V_79 , V_46 ) ;
if ( V_17 )
return V_17 ;
return F_52 ( V_2 , V_69 , V_38 , V_21 , V_71 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
bool V_69 , int V_21 , int V_3 ,
T_1 V_46 )
{
int V_71 = ( V_3 >> 16 ) & 0x1f ;
int V_51 = V_3 & 0xffff ;
int V_17 ;
V_17 = F_53 ( V_2 , V_69 , V_21 , V_71 ,
V_51 ) ;
if ( V_17 )
return V_17 ;
return F_56 ( V_2 , V_69 , V_21 , V_71 ,
V_46 ) ;
}
int F_58 ( struct V_1 * V_2 , struct V_84 * V_85 ,
int V_51 , int V_3 , T_1 * V_4 )
{
struct V_86 * V_87 = V_85 -> V_88 ;
bool V_69 = V_87 -> V_69 ;
if ( V_3 & V_89 )
return F_55 ( V_2 , V_69 , V_51 , V_3 ,
V_4 ) ;
return F_50 ( V_2 , V_69 , V_51 , V_3 ,
V_4 ) ;
}
int F_59 ( struct V_1 * V_2 , struct V_84 * V_85 ,
int V_51 , int V_3 , T_1 V_4 )
{
struct V_86 * V_87 = V_85 -> V_88 ;
bool V_69 = V_87 -> V_69 ;
if ( V_3 & V_89 )
return F_57 ( V_2 , V_69 , V_51 , V_3 ,
V_4 ) ;
return F_51 ( V_2 , V_69 , V_51 , V_3 ,
V_4 ) ;
}
static int F_60 ( struct V_1 * V_2 , int V_90 )
{
T_1 V_3 ;
F_1 ( V_2 , V_91 , & V_3 ) ;
F_61 ( V_2 -> V_71 , L_1 , V_3 ) ;
return V_92 ;
}
static void F_62 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_1 ( V_2 , V_91 , & V_3 ) ;
V_3 &= ~ ( V_93 |
V_94 ) ;
F_3 ( V_2 , V_91 , V_3 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_91 ,
V_93 |
V_94 |
V_95 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_96 ,
V_97 |
V_98 |
V_99 |
V_100 |
V_101 ) ;
}
static int F_65 ( struct V_1 * V_2 , int V_90 )
{
int V_17 ;
T_1 V_3 ;
F_3 ( V_2 , V_96 ,
V_102 ) ;
V_17 = F_1 ( V_2 , V_96 , & V_3 ) ;
F_61 ( V_2 -> V_71 , L_1 ,
V_3 & V_103 ) ;
F_3 ( V_2 , V_96 ,
V_104 ) ;
V_17 = F_1 ( V_2 , V_96 , & V_3 ) ;
F_61 ( V_2 -> V_71 , L_2 ,
V_3 & V_103 ) ;
if ( V_2 -> V_5 -> V_105 -> V_106 )
V_2 -> V_5 -> V_105 -> V_106 ( V_2 ) ;
F_64 ( V_2 ) ;
return V_92 ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_96 ,
V_97 ) ;
}
static T_3 F_67 ( int V_90 , void * V_107 )
{
struct V_1 * V_2 = V_107 ;
T_3 V_108 = V_109 ;
F_68 ( & V_2 -> V_110 ) ;
if ( V_2 -> V_5 -> V_105 -> V_111 -> V_112 )
V_108 = V_2 -> V_5 -> V_105 -> V_111 -> V_112 ( V_2 , V_90 ) ;
F_69 ( & V_2 -> V_110 ) ;
return V_108 ;
}
static void F_70 ( struct V_1 * V_2 )
{
F_68 ( & V_2 -> V_110 ) ;
if ( V_2 -> V_5 -> V_105 -> V_111 -> V_113 )
V_2 -> V_5 -> V_105 -> V_111 -> V_113 ( V_2 ) ;
F_69 ( & V_2 -> V_110 ) ;
F_71 ( V_2 -> V_114 , V_2 ) ;
F_72 ( V_2 -> V_114 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
int V_17 ;
V_2 -> V_114 = F_74 ( V_2 -> V_115 . V_116 ,
V_117 ) ;
if ( V_2 -> V_114 < 0 )
return V_2 -> V_114 ;
V_17 = F_75 ( V_2 -> V_114 , NULL ,
F_67 ,
V_118 | V_119 ,
L_3 , V_2 ) ;
if ( V_17 )
return V_17 ;
F_68 ( & V_2 -> V_110 ) ;
if ( V_2 -> V_5 -> V_105 -> V_111 -> V_120 )
V_17 = V_2 -> V_5 -> V_105 -> V_111 -> V_120 ( V_2 ) ;
F_69 ( & V_2 -> V_110 ) ;
return V_17 ;
}
static int F_76 ( struct V_1 * V_2 ,
bool V_121 )
{
T_1 V_4 ;
int V_17 ;
V_17 = F_1 ( V_2 , V_122 , & V_4 ) ;
if ( V_17 )
return V_17 ;
if ( V_121 )
V_4 |= V_123 ;
else
V_4 &= ~ V_123 ;
return F_3 ( V_2 , V_122 , V_4 ) ;
}
int F_77 ( struct V_1 * V_2 )
{
return F_76 ( V_2 , false ) ;
}
static void F_78 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = F_79 ( V_125 ) ;
unsigned int V_126 = V_125 -> V_127 ;
V_2 -> V_115 . V_128 |= ( 1 << V_126 ) ;
}
static void F_80 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = F_79 ( V_125 ) ;
unsigned int V_126 = V_125 -> V_127 ;
V_2 -> V_115 . V_128 &= ~ ( 1 << V_126 ) ;
}
static T_3 F_81 ( int V_90 , void * V_107 )
{
struct V_1 * V_2 = V_107 ;
unsigned int V_129 = 0 ;
unsigned int V_130 ;
unsigned int V_126 ;
int V_17 ;
T_1 V_3 ;
F_68 ( & V_2 -> V_110 ) ;
V_17 = F_9 ( V_2 , & V_3 ) ;
F_69 ( & V_2 -> V_110 ) ;
if ( V_17 )
goto V_131;
for ( V_126 = 0 ; V_126 < 16 ; ++ V_126 ) {
if ( V_3 & ( 1 << V_126 ) ) {
V_130 = F_74 ( V_2 -> V_115 . V_116 , V_126 ) ;
F_82 ( V_130 ) ;
++ V_129 ;
}
}
V_131:
return ( V_129 > 0 ? V_92 : V_109 ) ;
}
static void F_83 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = F_79 ( V_125 ) ;
F_68 ( & V_2 -> V_110 ) ;
}
static void F_84 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = F_79 ( V_125 ) ;
int V_17 ;
V_17 = F_10 ( V_2 , ~ V_2 -> V_115 . V_128 ) ;
if ( V_17 )
F_85 ( V_2 -> V_71 , L_4 ) ;
F_69 ( & V_2 -> V_110 ) ;
}
static int F_86 ( struct V_132 * V_125 ,
unsigned int V_90 ,
T_4 V_127 )
{
struct V_1 * V_2 = V_125 -> V_133 ;
F_87 ( V_90 , V_125 -> V_133 ) ;
F_88 ( V_90 , & V_2 -> V_115 . V_2 , V_134 ) ;
F_89 ( V_90 ) ;
return 0 ;
}
void F_90 ( struct V_1 * V_2 )
{
int V_90 , V_135 ;
F_70 ( V_2 ) ;
F_71 ( V_2 -> V_136 , V_2 ) ;
F_72 ( V_2 -> V_136 ) ;
for ( V_90 = 0 ; V_90 < 16 ; V_90 ++ ) {
V_135 = F_74 ( V_2 -> V_115 . V_116 , V_90 ) ;
F_72 ( V_135 ) ;
}
F_91 ( V_2 -> V_115 . V_116 ) ;
}
int F_92 ( struct V_1 * V_2 )
{
int V_17 , V_90 , V_135 ;
if ( ! V_2 -> V_71 -> V_137 )
return - V_138 ;
V_2 -> V_115 . V_116 = F_93 (
V_2 -> V_71 -> V_137 , 16 , 0 , & V_139 , V_2 ) ;
if ( ! V_2 -> V_115 . V_116 )
return - V_140 ;
for ( V_90 = 0 ; V_90 < 16 ; V_90 ++ )
F_94 ( V_2 -> V_115 . V_116 , V_90 ) ;
V_2 -> V_115 . V_2 = V_141 ;
V_2 -> V_115 . V_128 = ~ 0 ;
V_2 -> V_136 = F_74 ( V_2 -> V_142 . V_116 ,
V_143 ) ;
if ( V_2 -> V_136 < 0 ) {
V_17 = V_2 -> V_136 ;
goto V_131;
}
V_17 = F_75 ( V_2 -> V_136 , NULL ,
F_81 ,
V_118 , L_5 , V_2 ) ;
if ( V_17 )
goto V_131;
return F_73 ( V_2 ) ;
V_131:
for ( V_90 = 0 ; V_90 < 16 ; V_90 ++ ) {
V_135 = F_74 ( V_2 -> V_115 . V_116 , V_90 ) ;
F_72 ( V_135 ) ;
}
F_91 ( V_2 -> V_115 . V_116 ) ;
return V_17 ;
}
int F_95 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_17 ;
V_3 = V_144 | ( 0x7 << 4 ) ;
V_17 = F_3 ( V_2 , V_18 , V_3 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_17 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_23 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return 0 ;
}
