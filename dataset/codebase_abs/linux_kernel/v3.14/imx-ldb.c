static enum V_1 F_1 (
struct V_2 * V_3 , bool V_4 )
{
return V_5 ;
}
static void F_2 ( struct V_2 * V_3 )
{
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
int V_8 = 0 ;
if ( V_7 -> V_9 ) {
F_5 ( V_3 ,
V_7 -> V_9 ) ;
V_8 = F_6 ( V_3 , V_7 -> V_9 ) ;
}
if ( V_7 -> V_10 ) {
struct V_11 * V_12 ;
V_12 = F_7 ( V_3 -> V_13 ) ;
F_8 ( V_12 , & V_7 -> V_12 ) ;
V_12 -> type |= V_14 | V_15 ;
F_9 ( V_3 , V_12 ) ;
V_8 ++ ;
}
return V_8 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
return 0 ;
}
static struct V_16 * F_11 (
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
return & V_7 -> V_17 ;
}
static void F_12 ( struct V_16 * V_17 , int V_12 )
{
}
static bool F_13 ( struct V_16 * V_17 ,
const struct V_11 * V_12 ,
struct V_11 * V_18 )
{
return true ;
}
static void F_14 ( struct V_19 * V_20 , int V_21 , int V_22 ,
unsigned long V_23 , unsigned long V_24 )
{
int V_25 ;
F_15 ( V_20 -> V_13 , L_1 , V_26 ,
F_16 ( V_20 -> V_27 [ V_22 ] ) , V_23 ) ;
F_17 ( V_20 -> V_27 [ V_22 ] , V_23 ) ;
F_15 ( V_20 -> V_13 , L_2 , V_26 ,
F_16 ( V_20 -> V_27 [ V_22 ] ) ) ;
F_15 ( V_20 -> V_13 , L_1 , V_26 ,
F_16 ( V_20 -> V_28 [ V_22 ] ) ,
( long int ) V_24 ) ;
F_17 ( V_20 -> V_28 [ V_22 ] , V_24 ) ;
F_15 ( V_20 -> V_13 , L_2 , V_26 ,
F_16 ( V_20 -> V_28 [ V_22 ] ) ) ;
V_25 = F_18 ( V_20 -> V_29 [ V_21 ] , V_20 -> V_28 [ V_22 ] ) ;
if ( V_25 )
F_19 ( V_20 -> V_13 , L_3 , V_21 , V_22 ) ;
}
static void F_20 ( struct V_16 * V_17 )
{
struct V_6 * V_7 = F_21 ( V_17 ) ;
struct V_19 * V_20 = V_7 -> V_20 ;
struct V_11 * V_12 = & V_17 -> V_30 -> V_12 ;
T_1 V_31 ;
unsigned long V_23 ;
unsigned long V_24 = V_12 -> clock * 1000 ;
int V_21 = F_22 ( V_7 -> V_32 ,
V_17 -> V_30 ) ;
if ( V_20 -> V_33 & V_34 ) {
V_23 = 3500UL * V_12 -> clock ;
F_14 ( V_20 , V_21 , 0 , V_23 , V_24 ) ;
F_14 ( V_20 , V_21 , 1 , V_23 , V_24 ) ;
} else {
V_23 = 7000UL * V_12 -> clock ;
F_14 ( V_20 , V_21 , V_7 -> V_22 , V_23 , V_24 ) ;
}
switch ( V_7 -> V_22 ) {
case 0 :
V_31 = ( V_20 -> V_33 & V_35 ) ?
V_36 : V_37 ;
break;
case 1 :
V_31 = ( V_20 -> V_33 & V_38 ) ?
V_36 : V_37 ;
break;
default:
F_19 ( V_20 -> V_13 , L_4 ,
V_7 -> V_22 ) ;
V_31 = V_36 ;
}
F_23 ( V_17 -> V_30 , V_39 ,
V_31 ) ;
}
static void F_24 ( struct V_16 * V_17 )
{
struct V_6 * V_7 = F_21 ( V_17 ) ;
struct V_19 * V_20 = V_7 -> V_20 ;
int V_40 = V_20 -> V_33 & V_34 ;
int V_21 = F_22 ( V_7 -> V_32 ,
V_17 -> V_30 ) ;
if ( V_40 ) {
F_25 ( V_20 -> V_28 [ 0 ] ) ;
F_25 ( V_20 -> V_28 [ 1 ] ) ;
}
if ( V_7 == & V_20 -> V_41 [ 0 ] || V_40 ) {
V_20 -> V_33 &= ~ V_42 ;
if ( V_21 == 0 || V_20 -> V_43 )
V_20 -> V_33 |= V_44 ;
else if ( V_21 == 1 )
V_20 -> V_33 |= V_45 ;
}
if ( V_7 == & V_20 -> V_41 [ 1 ] || V_40 ) {
V_20 -> V_33 &= ~ V_46 ;
if ( V_21 == 1 || V_20 -> V_43 )
V_20 -> V_33 |= V_47 ;
else if ( V_21 == 0 )
V_20 -> V_33 |= V_48 ;
}
if ( V_20 -> V_43 ) {
const struct V_49 * V_43 = NULL ;
if ( V_7 == & V_20 -> V_41 [ 0 ] )
V_43 = & V_20 -> V_43 [ 0 ] ;
else if ( V_7 == & V_20 -> V_41 [ 1 ] )
V_43 = & V_20 -> V_43 [ 1 ] ;
F_26 ( V_20 -> V_50 , V_43 -> V_51 , V_43 -> V_52 ,
V_21 << V_43 -> V_53 ) ;
}
F_27 ( V_20 -> V_50 , V_54 , V_20 -> V_33 ) ;
}
static void F_28 ( struct V_16 * V_17 ,
struct V_11 * V_12 ,
struct V_11 * V_18 )
{
struct V_6 * V_7 = F_21 ( V_17 ) ;
struct V_19 * V_20 = V_7 -> V_20 ;
int V_40 = V_20 -> V_33 & V_34 ;
if ( V_12 -> clock > 170000 ) {
F_29 ( V_20 -> V_13 ,
L_5 , V_26 ) ;
}
if ( V_12 -> clock > 85000 && ! V_40 ) {
F_29 ( V_20 -> V_13 ,
L_6 , V_26 ) ;
}
if ( V_7 == & V_20 -> V_41 [ 0 ] ) {
if ( V_12 -> V_55 & V_56 )
V_20 -> V_33 |= V_57 ;
else if ( V_12 -> V_55 & V_58 )
V_20 -> V_33 &= ~ V_57 ;
}
if ( V_7 == & V_20 -> V_41 [ 1 ] ) {
if ( V_12 -> V_55 & V_56 )
V_20 -> V_33 |= V_59 ;
else if ( V_12 -> V_55 & V_58 )
V_20 -> V_33 &= ~ V_59 ;
}
}
static void F_30 ( struct V_16 * V_17 )
{
struct V_6 * V_7 = F_21 ( V_17 ) ;
struct V_19 * V_20 = V_7 -> V_20 ;
if ( V_7 == & V_20 -> V_41 [ 0 ] &&
( V_20 -> V_33 & V_42 ) == 0 )
return;
else if ( V_7 == & V_20 -> V_41 [ 1 ] &&
( V_20 -> V_33 & V_46 ) == 0 )
return;
if ( V_7 == & V_20 -> V_41 [ 0 ] )
V_20 -> V_33 &= ~ V_42 ;
else if ( V_7 == & V_20 -> V_41 [ 1 ] )
V_20 -> V_33 &= ~ V_46 ;
F_27 ( V_20 -> V_50 , V_54 , V_20 -> V_33 ) ;
if ( V_20 -> V_33 & V_34 ) {
F_31 ( V_20 -> V_28 [ 0 ] ) ;
F_31 ( V_20 -> V_28 [ 1 ] ) ;
}
}
static void F_32 ( struct V_16 * V_17 )
{
}
static int F_33 ( struct V_19 * V_20 , int V_22 )
{
char V_60 [ 16 ] ;
sprintf ( V_60 , L_7 , V_22 ) ;
V_20 -> V_28 [ V_22 ] = F_34 ( V_20 -> V_13 , V_60 ) ;
if ( F_35 ( V_20 -> V_28 [ V_22 ] ) )
return F_36 ( V_20 -> V_28 [ V_22 ] ) ;
sprintf ( V_60 , L_8 , V_22 ) ;
V_20 -> V_27 [ V_22 ] = F_34 ( V_20 -> V_13 , V_60 ) ;
return F_37 ( V_20 -> V_27 [ V_22 ] ) ;
}
static int F_38 ( struct V_6 * V_7 )
{
int V_25 ;
struct V_19 * V_20 = V_7 -> V_20 ;
V_25 = F_33 ( V_20 , V_7 -> V_22 ) ;
if ( V_25 )
return V_25 ;
if ( V_20 -> V_33 & V_34 ) {
V_25 |= F_33 ( V_20 , 1 ) ;
if ( V_25 )
return V_25 ;
}
V_7 -> V_3 . V_61 = & V_62 ;
V_7 -> V_17 . V_61 = & V_63 ;
V_7 -> V_17 . V_64 = V_39 ;
V_7 -> V_3 . V_65 = V_66 ;
F_39 ( & V_7 -> V_17 ,
& V_67 ) ;
V_25 = F_40 ( & V_7 -> V_17 ,
& V_7 -> V_32 , V_68 ) ;
if ( V_25 ) {
F_19 ( V_20 -> V_13 , L_9 , V_25 ) ;
return V_25 ;
}
F_41 ( & V_7 -> V_3 ,
& V_69 ) ;
V_25 = F_42 ( & V_7 -> V_3 ,
& V_7 -> V_70 , V_68 ) ;
if ( V_25 ) {
F_43 ( V_7 -> V_32 ) ;
F_19 ( V_20 -> V_13 , L_10 , V_25 ) ;
return V_25 ;
}
F_44 ( & V_7 -> V_3 ,
& V_7 -> V_17 ) ;
return 0 ;
}
static const int F_45 ( struct V_71 * V_72 )
{
const char * V_73 ;
int V_25 , V_74 ;
V_25 = F_46 ( V_72 , L_11 , & V_73 ) ;
if ( V_25 < 0 )
return V_25 ;
for ( V_74 = 0 ; V_74 < F_47 ( V_75 ) ; V_74 ++ )
if ( ! strcasecmp ( V_73 , V_75 [ V_74 ] ) )
return V_74 ;
return - V_76 ;
}
static int F_48 ( struct V_77 * V_78 )
{
struct V_71 * V_72 = V_78 -> V_13 . V_79 ;
const struct V_80 * V_81 =
F_49 ( V_82 , & V_78 -> V_13 ) ;
struct V_71 * V_83 ;
const T_2 * V_84 ;
struct V_19 * V_19 ;
int V_85 ;
int V_86 ;
int V_40 ;
int V_25 ;
int V_74 ;
V_19 = F_50 ( & V_78 -> V_13 , sizeof( * V_19 ) , V_87 ) ;
if ( ! V_19 )
return - V_88 ;
V_19 -> V_50 = F_51 ( V_72 , L_12 ) ;
if ( F_35 ( V_19 -> V_50 ) ) {
F_19 ( & V_78 -> V_13 , L_13 ) ;
return F_36 ( V_19 -> V_50 ) ;
}
V_19 -> V_13 = & V_78 -> V_13 ;
if ( V_81 )
V_19 -> V_43 = V_81 -> V_89 ;
V_40 = F_52 ( V_72 , L_14 ) ;
if ( V_40 )
V_19 -> V_33 |= V_34 ;
for ( V_74 = 0 ; V_74 < 4 ; V_74 ++ ) {
char V_60 [ 16 ] ;
sprintf ( V_60 , L_15 , V_74 ) ;
V_19 -> V_29 [ V_74 ] = F_34 ( V_19 -> V_13 , V_60 ) ;
if ( F_35 ( V_19 -> V_29 [ V_74 ] ) ) {
V_25 = F_36 ( V_19 -> V_29 [ V_74 ] ) ;
V_19 -> V_29 [ V_74 ] = NULL ;
break;
}
}
if ( V_74 == 0 )
return V_25 ;
F_53 (np, child) {
struct V_6 * V_41 ;
V_25 = F_54 ( V_83 , L_16 , & V_74 ) ;
if ( V_25 || V_74 < 0 || V_74 > 1 )
return - V_76 ;
if ( V_40 && V_74 > 0 ) {
F_29 ( & V_78 -> V_13 , L_17 ) ;
continue;
}
if ( ! F_55 ( V_83 ) )
continue;
V_41 = & V_19 -> V_41 [ V_74 ] ;
V_41 -> V_20 = V_19 ;
V_41 -> V_22 = V_74 ;
V_84 = F_56 ( V_83 , L_18 , & V_41 -> V_90 ) ;
if ( V_84 ) {
V_41 -> V_9 = F_57 ( V_84 , V_41 -> V_90 ,
V_87 ) ;
} else {
V_25 = F_58 ( V_83 , & V_41 -> V_12 , 0 ) ;
if ( ! V_25 )
V_41 -> V_10 = 1 ;
}
V_25 = F_54 ( V_83 , L_19 , & V_85 ) ;
if ( V_25 )
V_85 = 0 ;
else if ( V_85 != 18 && V_85 != 24 )
return - V_76 ;
V_86 = F_45 ( V_83 ) ;
switch ( V_86 ) {
case V_91 :
if ( V_85 == 24 ) {
if ( V_74 == 0 || V_40 )
V_19 -> V_33 |= V_35 ;
if ( V_74 == 1 || V_40 )
V_19 -> V_33 |= V_38 ;
}
break;
case V_92 :
if ( V_85 == 18 ) {
F_19 ( & V_78 -> V_13 , L_20 ) ;
return - V_76 ;
}
if ( V_74 == 0 || V_40 )
V_19 -> V_33 |= V_35 | V_93 ;
if ( V_74 == 1 || V_40 )
V_19 -> V_33 |= V_38 | V_94 ;
break;
default:
F_19 ( & V_78 -> V_13 , L_21 ) ;
return - V_76 ;
}
V_25 = F_38 ( V_41 ) ;
if ( V_25 )
return V_25 ;
F_59 ( V_41 -> V_32 , V_83 ) ;
}
F_60 ( V_78 , V_19 ) ;
return 0 ;
}
static int F_61 ( struct V_77 * V_78 )
{
struct V_19 * V_19 = F_62 ( V_78 ) ;
int V_74 ;
for ( V_74 = 0 ; V_74 < 2 ; V_74 ++ ) {
struct V_6 * V_41 = & V_19 -> V_41 [ V_74 ] ;
struct V_2 * V_3 = & V_41 -> V_3 ;
struct V_16 * V_17 = & V_41 -> V_17 ;
F_63 ( V_3 , V_17 ) ;
F_64 ( V_41 -> V_70 ) ;
F_43 ( V_41 -> V_32 ) ;
}
return 0 ;
}
