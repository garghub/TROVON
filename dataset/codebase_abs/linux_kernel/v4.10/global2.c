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
return F_1 ( V_2 , V_42 , V_33 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
T_2 V_35 , T_1 V_33 )
{
T_1 V_40 = V_43 | V_35 ;
int V_8 ;
V_8 = F_23 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_42 , V_33 ) ;
if ( V_8 )
return V_8 ;
return F_24 ( V_2 , V_40 ) ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_44 * V_45 , T_2 * V_33 )
{
unsigned int V_46 = V_45 -> V_46 ;
unsigned int V_47 = V_45 -> V_47 ;
T_1 V_4 ;
int V_8 ;
V_45 -> V_47 = 0 ;
if ( V_46 & 1 ) {
V_8 = F_25 ( V_2 , V_46 >> 1 , & V_4 ) ;
if ( V_8 )
return V_8 ;
* V_33 ++ = ( V_4 >> 8 ) & 0xff ;
V_46 ++ ;
V_47 -- ;
V_45 -> V_47 ++ ;
}
while ( V_47 >= 2 ) {
V_8 = F_25 ( V_2 , V_46 >> 1 , & V_4 ) ;
if ( V_8 )
return V_8 ;
* V_33 ++ = V_4 & 0xff ;
* V_33 ++ = ( V_4 >> 8 ) & 0xff ;
V_46 += 2 ;
V_47 -= 2 ;
V_45 -> V_47 += 2 ;
}
if ( V_47 ) {
V_8 = F_25 ( V_2 , V_46 >> 1 , & V_4 ) ;
if ( V_8 )
return V_8 ;
* V_33 ++ = V_4 & 0xff ;
V_46 ++ ;
V_47 -- ;
V_45 -> V_47 ++ ;
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_44 * V_45 , T_2 * V_33 )
{
unsigned int V_46 = V_45 -> V_46 ;
unsigned int V_47 = V_45 -> V_47 ;
T_1 V_4 ;
int V_8 ;
V_8 = F_1 ( V_2 , V_37 , & V_4 ) ;
if ( V_8 )
return V_8 ;
if ( ! ( V_4 & V_48 ) )
return - V_49 ;
V_45 -> V_47 = 0 ;
if ( V_46 & 1 ) {
V_8 = F_25 ( V_2 , V_46 >> 1 , & V_4 ) ;
if ( V_8 )
return V_8 ;
V_4 = ( * V_33 ++ << 8 ) | ( V_4 & 0xff ) ;
V_8 = F_26 ( V_2 , V_46 >> 1 , V_4 ) ;
if ( V_8 )
return V_8 ;
V_46 ++ ;
V_47 -- ;
V_45 -> V_47 ++ ;
}
while ( V_47 >= 2 ) {
V_4 = * V_33 ++ ;
V_4 |= * V_33 ++ << 8 ;
V_8 = F_26 ( V_2 , V_46 >> 1 , V_4 ) ;
if ( V_8 )
return V_8 ;
V_46 += 2 ;
V_47 -= 2 ;
V_45 -> V_47 += 2 ;
}
if ( V_47 ) {
V_8 = F_25 ( V_2 , V_46 >> 1 , & V_4 ) ;
if ( V_8 )
return V_8 ;
V_4 = ( V_4 & 0xff00 ) | * V_33 ++ ;
V_8 = F_26 ( V_2 , V_46 >> 1 , V_4 ) ;
if ( V_8 )
return V_8 ;
V_46 ++ ;
V_47 -- ;
V_45 -> V_47 ++ ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_50 ,
V_51 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_40 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_50 , V_40 ) ;
if ( V_8 )
return V_8 ;
return F_29 ( V_2 ) ;
}
int F_31 ( struct V_1 * V_2 , int V_35 , int V_3 ,
T_1 * V_4 )
{
T_1 V_40 = V_52 | ( V_35 << 5 ) | V_3 ;
int V_8 ;
V_8 = F_29 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_30 ( V_2 , V_40 ) ;
if ( V_8 )
return V_8 ;
return F_1 ( V_2 , V_53 , V_4 ) ;
}
int F_32 ( struct V_1 * V_2 , int V_35 , int V_3 ,
T_1 V_4 )
{
T_1 V_40 = V_54 | ( V_35 << 5 ) | V_3 ;
int V_8 ;
V_8 = F_29 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_53 , V_4 ) ;
if ( V_8 )
return V_8 ;
return F_30 ( V_2 , V_40 ) ;
}
static void F_33 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_34 ( V_56 ) ;
unsigned int V_57 = V_56 -> V_58 ;
V_2 -> V_59 . V_60 |= ( 1 << V_57 ) ;
}
static void F_35 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_34 ( V_56 ) ;
unsigned int V_57 = V_56 -> V_58 ;
V_2 -> V_59 . V_60 &= ~ ( 1 << V_57 ) ;
}
static T_3 F_36 ( int V_61 , void * V_62 )
{
struct V_1 * V_2 = V_62 ;
unsigned int V_63 = 0 ;
unsigned int V_64 ;
unsigned int V_57 ;
int V_8 ;
T_1 V_3 ;
F_37 ( & V_2 -> V_65 ) ;
V_8 = F_1 ( V_2 , V_66 , & V_3 ) ;
F_38 ( & V_2 -> V_65 ) ;
if ( V_8 )
goto V_67;
for ( V_57 = 0 ; V_57 < 16 ; ++ V_57 ) {
if ( V_3 & ( 1 << V_57 ) ) {
V_64 = F_39 ( V_2 -> V_59 . V_68 , V_57 ) ;
F_40 ( V_64 ) ;
++ V_63 ;
}
}
V_67:
return ( V_63 > 0 ? V_69 : V_70 ) ;
}
static void F_41 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_34 ( V_56 ) ;
F_37 ( & V_2 -> V_65 ) ;
}
static void F_42 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_34 ( V_56 ) ;
F_3 ( V_2 , V_71 , ~ V_2 -> V_59 . V_60 ) ;
F_38 ( & V_2 -> V_65 ) ;
}
static int F_43 ( struct V_72 * V_56 ,
unsigned int V_61 ,
T_4 V_58 )
{
struct V_1 * V_2 = V_56 -> V_73 ;
F_44 ( V_61 , V_56 -> V_73 ) ;
F_45 ( V_61 , & V_2 -> V_59 . V_2 , V_74 ) ;
F_46 ( V_61 ) ;
return 0 ;
}
void F_47 ( struct V_1 * V_2 )
{
int V_61 , V_75 ;
F_48 ( V_2 -> V_76 , V_2 ) ;
F_49 ( V_2 -> V_76 ) ;
for ( V_61 = 0 ; V_61 < 16 ; V_61 ++ ) {
V_75 = F_39 ( V_2 -> V_59 . V_68 , V_61 ) ;
F_49 ( V_75 ) ;
}
F_50 ( V_2 -> V_59 . V_68 ) ;
}
int F_51 ( struct V_1 * V_2 )
{
int V_8 , V_61 , V_75 ;
if ( ! V_2 -> V_77 -> V_78 )
return - V_79 ;
V_2 -> V_59 . V_68 = F_52 (
V_2 -> V_77 -> V_78 , 16 , 0 , & V_80 , V_2 ) ;
if ( ! V_2 -> V_59 . V_68 )
return - V_81 ;
for ( V_61 = 0 ; V_61 < 16 ; V_61 ++ )
F_53 ( V_2 -> V_59 . V_68 , V_61 ) ;
V_2 -> V_59 . V_2 = V_82 ;
V_2 -> V_59 . V_60 = ~ 0 ;
V_2 -> V_76 = F_39 ( V_2 -> V_83 . V_68 ,
V_84 ) ;
if ( V_2 -> V_76 < 0 ) {
V_8 = V_2 -> V_76 ;
goto V_67;
}
V_8 = F_54 ( V_2 -> V_76 , NULL ,
F_36 ,
V_85 , L_1 , V_2 ) ;
if ( V_8 )
goto V_67;
return 0 ;
V_67:
for ( V_61 = 0 ; V_61 < 16 ; V_61 ++ ) {
V_75 = F_39 ( V_2 -> V_59 . V_68 , V_61 ) ;
F_49 ( V_75 ) ;
}
F_50 ( V_2 -> V_59 . V_68 ) ;
return V_8 ;
}
int F_55 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_8 ;
V_3 = V_86 | ( 0x7 << 4 ) ;
if ( F_10 ( V_2 , V_11 ) ||
F_10 ( V_2 , V_9 ) )
V_3 |= V_87 | 0x7 ;
V_8 = F_3 ( V_2 , V_88 , V_3 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_12 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_17 ( V_2 ) ;
if ( V_8 )
return V_8 ;
if ( F_10 ( V_2 , V_89 ) ) {
V_8 = F_18 ( V_2 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_10 ( V_2 , V_90 ) ) {
V_8 = F_3 ( V_2 , V_91 ,
V_92 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_10 ( V_2 , V_93 ) ) {
V_8 = F_22 ( V_2 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
