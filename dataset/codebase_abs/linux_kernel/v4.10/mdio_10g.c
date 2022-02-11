unsigned F_1 ( T_1 V_1 )
{
unsigned V_2 = 0 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 22 ; ++ V_3 )
if ( V_1 & ( 1 << ( V_3 + 10 ) ) )
V_2 |= 1 << ( V_3 ^ 7 ) ;
return V_2 ;
}
int F_2 ( struct V_4 * V_5 , int V_6 ,
int V_7 , int V_8 )
{
T_1 V_9 ;
F_3 ( V_7 * V_8 >= 5000 ) ;
F_4 ( V_5 , V_6 , V_10 , V_11 ) ;
do {
F_5 ( V_8 ) ;
V_9 = F_6 ( V_5 , V_6 , V_10 ) ;
V_7 -- ;
} while ( V_7 && ( V_9 & V_11 ) );
return V_7 ? V_7 : - V_12 ;
}
static int F_7 ( struct V_4 * V_13 , int V_6 )
{
int V_14 ;
if ( V_6 != V_15 ) {
V_14 = F_6 ( V_13 , V_6 , V_16 ) ;
if ( ( V_14 & V_17 ) != V_18 ) {
F_8 ( V_13 , V_19 , V_13 -> V_20 ,
L_1 , V_6 ) ;
return - V_21 ;
}
}
return 0 ;
}
int F_9 ( struct V_4 * V_13 , unsigned int V_22 )
{
const int V_8 = V_23 / V_24 ;
int V_25 = V_24 ;
int V_26 = 0 ;
int V_27 ;
while ( V_25 ) {
int V_28 = V_22 ;
int V_6 = 0 ;
int V_29 ;
V_27 = 0 ;
while ( V_28 ) {
if ( V_28 & 1 ) {
V_29 = F_6 ( V_13 , V_6 , V_10 ) ;
if ( V_29 < 0 ) {
F_8 ( V_13 , V_19 , V_13 -> V_20 ,
L_2
L_3 , V_6 ) ;
return - V_21 ;
}
if ( V_29 & V_11 )
V_27 |= ( 1 << V_6 ) ;
}
V_28 = V_28 >> 1 ;
V_6 ++ ;
}
if ( ! V_27 )
break;
V_25 -- ;
F_5 ( V_8 ) ;
}
if ( V_27 != 0 ) {
F_8 ( V_13 , V_19 , V_13 -> V_20 ,
L_4
L_5 , V_27 ) ;
V_26 = - V_12 ;
}
return V_26 ;
}
int F_10 ( struct V_4 * V_13 , unsigned int V_22 )
{
int V_6 = 0 , V_30 , V_31 , V_32 ;
T_1 V_33 ;
V_30 = ( V_22 & V_34 ) ? V_35 :
F_11 ( V_22 ) ;
V_31 = F_6 ( V_13 , V_30 , V_36 ) ;
V_32 = F_6 ( V_13 , V_30 , V_37 ) ;
if ( V_31 < 0 || V_32 < 0 ) {
F_8 ( V_13 , V_19 , V_13 -> V_20 ,
L_6 ) ;
return - V_21 ;
}
V_33 = V_31 | ( V_32 << 16 ) ;
if ( ( V_33 & V_22 ) != V_22 ) {
F_8 ( V_13 , V_19 , V_13 -> V_20 ,
L_7 ,
V_33 , V_22 ) ;
return - V_38 ;
}
F_12 ( V_13 , V_19 , V_13 -> V_20 , L_8 , V_33 ) ;
while ( V_22 ) {
if ( ( V_22 & 1 ) && F_7 ( V_13 , V_6 ) )
return - V_21 ;
V_22 = V_22 >> 1 ;
V_6 ++ ;
}
return 0 ;
}
bool F_13 ( struct V_4 * V_13 , unsigned int V_22 )
{
if ( F_14 ( V_13 ) )
return true ;
else if ( F_15 ( V_13 ) & V_39 )
return false ;
else if ( F_16 ( V_13 -> V_40 ) )
return false ;
else if ( V_13 -> V_41 == V_42 )
V_22 &= ~ ( V_34 |
V_43 |
V_44 |
V_45 ) ;
else if ( V_13 -> V_41 == V_46 )
V_22 &= ~ ( V_43 |
V_44 |
V_45 ) ;
else if ( V_13 -> V_41 == V_47 )
V_22 &= ~ ( V_44 |
V_45 ) ;
return F_17 ( & V_13 -> V_48 , V_22 ) ;
}
void F_18 ( struct V_4 * V_13 )
{
F_19 ( V_13 , V_49 ,
V_50 , V_51 ,
V_13 -> V_40 & V_52 ) ;
}
void F_20 ( struct V_4 * V_13 )
{
F_19 ( V_13 , V_49 ,
V_10 , V_53 ,
V_13 -> V_41 == V_47 ) ;
F_19 ( V_13 , V_54 ,
V_10 , V_55 ,
V_13 -> V_41 == V_46 ) ;
F_19 ( V_13 , V_35 ,
V_10 , V_56 ,
V_13 -> V_41 == V_57 ) ;
}
static void F_21 ( struct V_4 * V_13 ,
int V_58 , int V_6 )
{
int V_29 = F_6 ( V_13 , V_6 , V_59 ) ;
F_12 ( V_13 , V_60 , V_13 -> V_20 , L_9 ,
V_6 , V_58 ) ;
if ( V_29 & V_61 ) {
F_19 ( V_13 , V_6 , V_10 ,
V_62 , V_58 ) ;
}
}
void F_22 ( struct V_4 * V_13 ,
int V_63 , unsigned int V_22 )
{
int V_6 = 0 ;
V_22 &= ~ V_45 ;
while ( V_22 ) {
if ( V_22 & 1 )
F_21 ( V_13 , V_63 , V_6 ) ;
V_22 = ( V_22 >> 1 ) ;
V_6 ++ ;
}
}
int F_23 ( struct V_4 * V_13 , struct V_64 * V_65 )
{
struct V_64 V_66 = { . V_67 = V_68 } ;
V_13 -> V_69 -> V_70 ( V_13 , & V_66 ) ;
if ( V_65 -> V_71 == V_66 . V_71 &&
F_24 ( V_65 ) == F_24 ( & V_66 ) &&
V_65 -> V_72 == V_66 . V_72 &&
V_65 -> V_5 == V_66 . V_5 &&
V_65 -> V_73 == V_66 . V_73 )
return 0 ;
if ( V_66 . V_5 != V_74 || V_65 -> V_5 != V_74 )
return - V_75 ;
if ( ! V_65 -> V_73 ||
( V_65 -> V_71 | V_76 ) & ~ V_66 . V_77 )
return - V_75 ;
F_25 ( V_13 , V_65 -> V_71 | V_78 ) ;
F_26 ( V_13 ) ;
return 0 ;
}
void F_26 ( struct V_4 * V_13 )
{
int V_79 ;
F_27 ( ! ( V_13 -> V_48 . V_80 & V_45 ) ) ;
V_79 = V_81 | V_82 ;
if ( V_13 -> V_83 & V_84 )
V_79 |= V_85 ;
if ( V_13 -> V_83 & V_86 )
V_79 |= V_87 ;
F_4 ( V_13 , V_15 , V_88 , V_79 ) ;
V_13 -> V_69 -> V_89 ( V_13 , V_13 -> V_83 ) ;
V_79 = F_6 ( V_13 , V_15 , V_10 ) ;
V_79 |= V_90 | V_91 | V_92 ;
F_4 ( V_13 , V_15 , V_10 , V_79 ) ;
}
T_2 F_28 ( struct V_4 * V_13 )
{
F_29 ( V_93 & ( V_94 | V_95 ) ) ;
if ( ! ( V_13 -> V_96 & V_93 ) )
return V_13 -> V_96 ;
F_27 ( ! ( V_13 -> V_48 . V_80 & V_45 ) ) ;
return F_30 (
F_31 ( V_13 -> V_96 ) ,
F_6 ( V_13 , V_15 , V_97 ) ) ;
}
int F_32 ( struct V_4 * V_13 )
{
int V_26 ;
int V_98 = F_11 ( V_13 -> V_48 . V_80 ) ;
T_3 V_99 , V_100 ;
F_33 ( & V_13 -> V_101 ) ;
V_99 = F_6 ( V_13 , V_98 , V_102 ) ;
V_100 = F_6 ( V_13 , V_98 , V_103 ) ;
if ( ( V_99 == 0x0000 ) || ( V_99 == 0xffff ) ||
( V_100 == 0x0000 ) || ( V_100 == 0xffff ) ) {
F_8 ( V_13 , V_19 , V_13 -> V_20 ,
L_10 , V_13 -> V_48 . V_104 ) ;
V_26 = - V_75 ;
} else {
V_26 = F_10 ( V_13 , V_13 -> V_48 . V_80 ) ;
}
F_34 ( & V_13 -> V_101 ) ;
return V_26 ;
}
