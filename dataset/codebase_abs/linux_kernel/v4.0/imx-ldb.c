static enum V_1 F_1 (
struct V_2 * V_3 , bool V_4 )
{
return V_5 ;
}
static int F_2 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
int V_8 = 0 ;
if ( V_7 -> V_9 ) {
F_4 ( V_3 ,
V_7 -> V_9 ) ;
V_8 = F_5 ( V_3 , V_7 -> V_9 ) ;
}
if ( V_7 -> V_10 ) {
struct V_11 * V_12 ;
V_12 = F_6 ( V_3 -> V_13 ) ;
if ( ! V_12 )
return - V_14 ;
F_7 ( V_12 , & V_7 -> V_12 ) ;
V_12 -> type |= V_15 | V_16 ;
F_8 ( V_3 , V_12 ) ;
V_8 ++ ;
}
return V_8 ;
}
static struct V_17 * F_9 (
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
return & V_7 -> V_18 ;
}
static void F_10 ( struct V_17 * V_18 , int V_12 )
{
}
static bool F_11 ( struct V_17 * V_18 ,
const struct V_11 * V_12 ,
struct V_11 * V_19 )
{
return true ;
}
static void F_12 ( struct V_20 * V_21 , int V_22 , int V_23 ,
unsigned long V_24 , unsigned long V_25 )
{
int V_26 ;
F_13 ( V_21 -> V_13 , L_1 , V_27 ,
F_14 ( V_21 -> V_28 [ V_23 ] ) , V_24 ) ;
F_15 ( V_21 -> V_28 [ V_23 ] , V_24 ) ;
F_13 ( V_21 -> V_13 , L_2 , V_27 ,
F_14 ( V_21 -> V_28 [ V_23 ] ) ) ;
F_13 ( V_21 -> V_13 , L_1 , V_27 ,
F_14 ( V_21 -> V_29 [ V_23 ] ) ,
( long int ) V_25 ) ;
F_15 ( V_21 -> V_29 [ V_23 ] , V_25 ) ;
F_13 ( V_21 -> V_13 , L_2 , V_27 ,
F_14 ( V_21 -> V_29 [ V_23 ] ) ) ;
V_26 = F_16 ( V_21 -> V_30 [ V_22 ] , V_21 -> V_29 [ V_23 ] ) ;
if ( V_26 )
F_17 ( V_21 -> V_13 ,
L_3 , V_22 ,
V_23 ) ;
}
static void F_18 ( struct V_17 * V_18 )
{
struct V_6 * V_7 = F_19 ( V_18 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
T_1 V_31 ;
switch ( V_7 -> V_23 ) {
case 0 :
V_31 = ( V_21 -> V_32 & V_33 ) ?
V_34 : V_35 ;
break;
case 1 :
V_31 = ( V_21 -> V_32 & V_36 ) ?
V_34 : V_35 ;
break;
default:
F_17 ( V_21 -> V_13 , L_4 ,
V_7 -> V_23 ) ;
V_31 = V_34 ;
}
F_20 ( V_18 , V_31 ) ;
}
static void F_21 ( struct V_17 * V_18 )
{
struct V_6 * V_7 = F_19 ( V_18 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
int V_37 = V_21 -> V_32 & V_38 ;
int V_22 = F_22 ( V_7 -> V_39 , V_18 ) ;
if ( V_37 ) {
F_23 ( V_21 -> V_29 [ 0 ] ) ;
F_23 ( V_21 -> V_29 [ 1 ] ) ;
}
if ( V_7 == & V_21 -> V_40 [ 0 ] || V_37 ) {
V_21 -> V_32 &= ~ V_41 ;
if ( V_22 == 0 || V_21 -> V_42 )
V_21 -> V_32 |= V_43 ;
else if ( V_22 == 1 )
V_21 -> V_32 |= V_44 ;
}
if ( V_7 == & V_21 -> V_40 [ 1 ] || V_37 ) {
V_21 -> V_32 &= ~ V_45 ;
if ( V_22 == 1 || V_21 -> V_42 )
V_21 -> V_32 |= V_46 ;
else if ( V_22 == 0 )
V_21 -> V_32 |= V_47 ;
}
if ( V_21 -> V_42 ) {
const struct V_48 * V_42 = NULL ;
if ( V_7 == & V_21 -> V_40 [ 0 ] )
V_42 = & V_21 -> V_42 [ 0 ] ;
else if ( V_7 == & V_21 -> V_40 [ 1 ] )
V_42 = & V_21 -> V_42 [ 1 ] ;
F_24 ( V_21 -> V_49 , V_42 -> V_50 , V_42 -> V_51 ,
V_22 << V_42 -> V_52 ) ;
}
F_25 ( V_21 -> V_49 , V_53 , V_21 -> V_32 ) ;
}
static void F_26 ( struct V_17 * V_18 ,
struct V_11 * V_54 ,
struct V_11 * V_12 )
{
struct V_6 * V_7 = F_19 ( V_18 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
int V_37 = V_21 -> V_32 & V_38 ;
unsigned long V_24 ;
unsigned long V_25 = V_12 -> clock * 1000 ;
int V_22 = F_22 ( V_7 -> V_39 , V_18 ) ;
if ( V_12 -> clock > 170000 ) {
F_27 ( V_21 -> V_13 ,
L_5 , V_27 ) ;
}
if ( V_12 -> clock > 85000 && ! V_37 ) {
F_27 ( V_21 -> V_13 ,
L_6 , V_27 ) ;
}
if ( V_37 ) {
V_24 = 3500UL * V_12 -> clock ;
F_12 ( V_21 , V_22 , 0 , V_24 , V_25 ) ;
F_12 ( V_21 , V_22 , 1 , V_24 , V_25 ) ;
} else {
V_24 = 7000UL * V_12 -> clock ;
F_12 ( V_21 , V_22 , V_7 -> V_23 , V_24 ,
V_25 ) ;
}
if ( V_7 == & V_21 -> V_40 [ 0 ] ) {
if ( V_12 -> V_55 & V_56 )
V_21 -> V_32 |= V_57 ;
else if ( V_12 -> V_55 & V_58 )
V_21 -> V_32 &= ~ V_57 ;
}
if ( V_7 == & V_21 -> V_40 [ 1 ] ) {
if ( V_12 -> V_55 & V_56 )
V_21 -> V_32 |= V_59 ;
else if ( V_12 -> V_55 & V_58 )
V_21 -> V_32 &= ~ V_59 ;
}
}
static void F_28 ( struct V_17 * V_18 )
{
struct V_6 * V_7 = F_19 ( V_18 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
if ( V_7 == & V_21 -> V_40 [ 0 ] &&
( V_21 -> V_32 & V_41 ) == 0 )
return;
else if ( V_7 == & V_21 -> V_40 [ 1 ] &&
( V_21 -> V_32 & V_45 ) == 0 )
return;
if ( V_7 == & V_21 -> V_40 [ 0 ] )
V_21 -> V_32 &= ~ V_41 ;
else if ( V_7 == & V_21 -> V_40 [ 1 ] )
V_21 -> V_32 &= ~ V_45 ;
F_25 ( V_21 -> V_49 , V_53 , V_21 -> V_32 ) ;
if ( V_21 -> V_32 & V_38 ) {
F_29 ( V_21 -> V_29 [ 0 ] ) ;
F_29 ( V_21 -> V_29 [ 1 ] ) ;
}
}
static int F_30 ( struct V_20 * V_21 , int V_23 )
{
char V_60 [ 16 ] ;
snprintf ( V_60 , sizeof( V_60 ) , L_7 , V_23 ) ;
V_21 -> V_29 [ V_23 ] = F_31 ( V_21 -> V_13 , V_60 ) ;
if ( F_32 ( V_21 -> V_29 [ V_23 ] ) )
return F_33 ( V_21 -> V_29 [ V_23 ] ) ;
snprintf ( V_60 , sizeof( V_60 ) , L_8 , V_23 ) ;
V_21 -> V_28 [ V_23 ] = F_31 ( V_21 -> V_13 , V_60 ) ;
return F_34 ( V_21 -> V_28 [ V_23 ] ) ;
}
static int F_35 ( struct V_61 * V_62 ,
struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
int V_26 ;
V_26 = F_36 ( V_62 , & V_7 -> V_18 ,
V_7 -> V_39 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_30 ( V_21 , V_7 -> V_23 ) ;
if ( V_26 )
return V_26 ;
if ( V_21 -> V_32 & V_38 ) {
V_26 = F_30 ( V_21 , 1 ) ;
if ( V_26 )
return V_26 ;
}
F_37 ( & V_7 -> V_18 ,
& V_63 ) ;
F_38 ( V_62 , & V_7 -> V_18 , & V_64 ,
V_65 ) ;
F_39 ( & V_7 -> V_3 ,
& V_66 ) ;
F_40 ( V_62 , & V_7 -> V_3 ,
& V_67 , V_68 ) ;
F_41 ( & V_7 -> V_3 ,
& V_7 -> V_18 ) ;
return 0 ;
}
static const int F_42 ( struct V_69 * V_70 )
{
const char * V_71 ;
int V_26 , V_72 ;
V_26 = F_43 ( V_70 , L_9 , & V_71 ) ;
if ( V_26 < 0 )
return V_26 ;
for ( V_72 = 0 ; V_72 < F_44 ( V_73 ) ; V_72 ++ )
if ( ! strcasecmp ( V_71 , V_73 [ V_72 ] ) )
return V_72 ;
return - V_14 ;
}
static int F_45 ( struct V_74 * V_13 , struct V_74 * V_75 , void * V_76 )
{
struct V_61 * V_62 = V_76 ;
struct V_69 * V_70 = V_13 -> V_77 ;
const struct V_78 * V_79 =
F_46 ( V_80 , V_13 ) ;
struct V_69 * V_39 ;
const T_2 * V_81 ;
struct V_20 * V_20 ;
int V_82 ;
int V_83 ;
int V_37 ;
int V_26 ;
int V_72 ;
V_20 = F_47 ( V_13 , sizeof( * V_20 ) , V_84 ) ;
if ( ! V_20 )
return - V_85 ;
V_20 -> V_49 = F_48 ( V_70 , L_10 ) ;
if ( F_32 ( V_20 -> V_49 ) ) {
F_17 ( V_13 , L_11 ) ;
return F_33 ( V_20 -> V_49 ) ;
}
V_20 -> V_13 = V_13 ;
if ( V_79 )
V_20 -> V_42 = V_79 -> V_76 ;
V_37 = F_49 ( V_70 , L_12 ) ;
if ( V_37 )
V_20 -> V_32 |= V_38 ;
for ( V_72 = 0 ; V_72 < 4 ; V_72 ++ ) {
char V_60 [ 16 ] ;
sprintf ( V_60 , L_13 , V_72 ) ;
V_20 -> V_30 [ V_72 ] = F_31 ( V_20 -> V_13 , V_60 ) ;
if ( F_32 ( V_20 -> V_30 [ V_72 ] ) ) {
V_26 = F_33 ( V_20 -> V_30 [ V_72 ] ) ;
V_20 -> V_30 [ V_72 ] = NULL ;
break;
}
}
if ( V_72 == 0 )
return V_26 ;
F_50 (np, child) {
struct V_6 * V_40 ;
V_26 = F_51 ( V_39 , L_14 , & V_72 ) ;
if ( V_26 || V_72 < 0 || V_72 > 1 )
return - V_14 ;
if ( V_37 && V_72 > 0 ) {
F_27 ( V_13 , L_15 ) ;
continue;
}
if ( ! F_52 ( V_39 ) )
continue;
V_40 = & V_20 -> V_40 [ V_72 ] ;
V_40 -> V_21 = V_20 ;
V_40 -> V_23 = V_72 ;
V_40 -> V_39 = V_39 ;
V_81 = F_53 ( V_39 , L_16 , & V_40 -> V_86 ) ;
if ( V_81 ) {
V_40 -> V_9 = F_54 ( V_81 , V_40 -> V_86 ,
V_84 ) ;
} else {
V_26 = F_55 ( V_39 , & V_40 -> V_12 , 0 ) ;
if ( ! V_26 )
V_40 -> V_10 = 1 ;
}
V_26 = F_51 ( V_39 , L_17 , & V_82 ) ;
if ( V_26 )
V_82 = 0 ;
else if ( V_82 != 18 && V_82 != 24 )
return - V_14 ;
V_83 = F_42 ( V_39 ) ;
switch ( V_83 ) {
case V_87 :
if ( V_82 == 24 ) {
if ( V_72 == 0 || V_37 )
V_20 -> V_32 |=
V_33 ;
if ( V_72 == 1 || V_37 )
V_20 -> V_32 |=
V_36 ;
}
break;
case V_88 :
if ( V_82 == 18 ) {
F_17 ( V_13 , L_18 ) ;
return - V_14 ;
}
if ( V_72 == 0 || V_37 )
V_20 -> V_32 |= V_33 |
V_89 ;
if ( V_72 == 1 || V_37 )
V_20 -> V_32 |= V_36 |
V_90 ;
break;
default:
F_17 ( V_13 , L_19 ) ;
return - V_14 ;
}
V_26 = F_35 ( V_62 , V_40 ) ;
if ( V_26 )
return V_26 ;
}
F_56 ( V_13 , V_20 ) ;
return 0 ;
}
static void F_57 ( struct V_74 * V_13 , struct V_74 * V_75 ,
void * V_76 )
{
struct V_20 * V_20 = F_58 ( V_13 ) ;
int V_72 ;
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
struct V_6 * V_40 = & V_20 -> V_40 [ V_72 ] ;
if ( ! V_40 -> V_3 . V_91 )
continue;
V_40 -> V_3 . V_91 -> V_92 ( & V_40 -> V_3 ) ;
V_40 -> V_18 . V_91 -> V_92 ( & V_40 -> V_18 ) ;
F_59 ( V_40 -> V_9 ) ;
}
}
static int F_60 ( struct V_93 * V_94 )
{
return F_61 ( & V_94 -> V_13 , & V_95 ) ;
}
static int F_62 ( struct V_93 * V_94 )
{
F_63 ( & V_94 -> V_13 , & V_95 ) ;
return 0 ;
}
