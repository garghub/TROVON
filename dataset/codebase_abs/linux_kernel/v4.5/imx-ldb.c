static enum V_1 F_1 (
struct V_2 * V_3 , bool V_4 )
{
return V_5 ;
}
static int F_2 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
int V_8 = 0 ;
if ( V_7 -> V_9 && V_7 -> V_9 -> V_10 &&
V_7 -> V_9 -> V_10 -> V_11 ) {
struct V_12 * V_13 = & V_3 -> V_14 ;
V_8 = V_7 -> V_9 -> V_10 -> V_11 ( V_7 -> V_9 ) ;
if ( ! V_7 -> V_15 && V_13 -> V_16 )
V_7 -> V_15 = V_13 -> V_17 [ 0 ] ;
if ( V_8 > 0 )
return V_8 ;
}
if ( V_7 -> V_18 ) {
F_4 ( V_3 ,
V_7 -> V_18 ) ;
V_8 = F_5 ( V_3 , V_7 -> V_18 ) ;
}
if ( V_7 -> V_19 ) {
struct V_20 * V_21 ;
V_21 = F_6 ( V_3 -> V_22 ) ;
if ( ! V_21 )
return - V_23 ;
F_7 ( V_21 , & V_7 -> V_21 ) ;
V_21 -> type |= V_24 | V_25 ;
F_8 ( V_3 , V_21 ) ;
V_8 ++ ;
}
return V_8 ;
}
static struct V_26 * F_9 (
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
return & V_7 -> V_27 ;
}
static void F_10 ( struct V_26 * V_27 , int V_21 )
{
}
static bool F_11 ( struct V_26 * V_27 ,
const struct V_20 * V_21 ,
struct V_20 * V_28 )
{
return true ;
}
static void F_12 ( struct V_29 * V_30 , int V_31 , int V_32 ,
unsigned long V_33 , unsigned long V_34 )
{
int V_35 ;
F_13 ( V_30 -> V_22 , L_1 , V_36 ,
F_14 ( V_30 -> V_37 [ V_32 ] ) , V_33 ) ;
F_15 ( V_30 -> V_37 [ V_32 ] , V_33 ) ;
F_13 ( V_30 -> V_22 , L_2 , V_36 ,
F_14 ( V_30 -> V_37 [ V_32 ] ) ) ;
F_13 ( V_30 -> V_22 , L_1 , V_36 ,
F_14 ( V_30 -> V_38 [ V_32 ] ) ,
( long int ) V_34 ) ;
F_15 ( V_30 -> V_38 [ V_32 ] , V_34 ) ;
F_13 ( V_30 -> V_22 , L_2 , V_36 ,
F_14 ( V_30 -> V_38 [ V_32 ] ) ) ;
V_35 = F_16 ( V_30 -> V_39 [ V_31 ] , V_30 -> V_38 [ V_32 ] ) ;
if ( V_35 )
F_17 ( V_30 -> V_22 ,
L_3 , V_31 ,
V_32 ) ;
}
static void F_18 ( struct V_26 * V_27 )
{
struct V_6 * V_7 = F_19 ( V_27 ) ;
struct V_29 * V_30 = V_7 -> V_30 ;
int V_40 = V_30 -> V_41 & V_42 ;
T_1 V_15 ;
switch ( V_7 -> V_15 ) {
default:
F_20 ( V_30 -> V_22 ,
L_4 ) ;
case V_43 :
V_15 = V_44 ;
break;
case V_45 :
V_15 = V_46 ;
if ( V_7 -> V_32 == 0 || V_40 )
V_30 -> V_41 |= V_47 ;
if ( V_7 -> V_32 == 1 || V_40 )
V_30 -> V_41 |= V_48 ;
break;
case V_49 :
V_15 = V_46 ;
if ( V_7 -> V_32 == 0 || V_40 )
V_30 -> V_41 |= V_47 |
V_50 ;
if ( V_7 -> V_32 == 1 || V_40 )
V_30 -> V_41 |= V_48 |
V_51 ;
break;
}
F_21 ( V_27 , V_15 ) ;
}
static void F_22 ( struct V_26 * V_27 )
{
struct V_6 * V_7 = F_19 ( V_27 ) ;
struct V_29 * V_30 = V_7 -> V_30 ;
int V_40 = V_30 -> V_41 & V_42 ;
int V_31 = F_23 ( V_7 -> V_52 , V_27 ) ;
F_24 ( V_7 -> V_9 ) ;
if ( V_40 ) {
F_25 ( V_30 -> V_38 [ 0 ] ) ;
F_25 ( V_30 -> V_38 [ 1 ] ) ;
}
if ( V_7 == & V_30 -> V_53 [ 0 ] || V_40 ) {
V_30 -> V_41 &= ~ V_54 ;
if ( V_31 == 0 || V_30 -> V_55 )
V_30 -> V_41 |= V_56 ;
else if ( V_31 == 1 )
V_30 -> V_41 |= V_57 ;
}
if ( V_7 == & V_30 -> V_53 [ 1 ] || V_40 ) {
V_30 -> V_41 &= ~ V_58 ;
if ( V_31 == 1 || V_30 -> V_55 )
V_30 -> V_41 |= V_59 ;
else if ( V_31 == 0 )
V_30 -> V_41 |= V_60 ;
}
if ( V_30 -> V_55 ) {
const struct V_61 * V_55 = NULL ;
if ( V_7 == & V_30 -> V_53 [ 0 ] )
V_55 = & V_30 -> V_55 [ 0 ] ;
else if ( V_7 == & V_30 -> V_53 [ 1 ] )
V_55 = & V_30 -> V_55 [ 1 ] ;
F_26 ( V_30 -> V_62 , V_55 -> V_63 , V_55 -> V_64 ,
V_31 << V_55 -> V_65 ) ;
}
F_27 ( V_30 -> V_62 , V_66 , V_30 -> V_41 ) ;
F_28 ( V_7 -> V_9 ) ;
}
static void F_29 ( struct V_26 * V_27 ,
struct V_20 * V_67 ,
struct V_20 * V_21 )
{
struct V_6 * V_7 = F_19 ( V_27 ) ;
struct V_29 * V_30 = V_7 -> V_30 ;
int V_40 = V_30 -> V_41 & V_42 ;
unsigned long V_33 ;
unsigned long V_34 = V_21 -> clock * 1000 ;
int V_31 = F_23 ( V_7 -> V_52 , V_27 ) ;
if ( V_21 -> clock > 170000 ) {
F_20 ( V_30 -> V_22 ,
L_5 , V_36 ) ;
}
if ( V_21 -> clock > 85000 && ! V_40 ) {
F_20 ( V_30 -> V_22 ,
L_6 , V_36 ) ;
}
if ( V_40 ) {
V_33 = 3500UL * V_21 -> clock ;
F_12 ( V_30 , V_31 , 0 , V_33 , V_34 ) ;
F_12 ( V_30 , V_31 , 1 , V_33 , V_34 ) ;
} else {
V_33 = 7000UL * V_21 -> clock ;
F_12 ( V_30 , V_31 , V_7 -> V_32 , V_33 ,
V_34 ) ;
}
if ( V_7 == & V_30 -> V_53 [ 0 ] ) {
if ( V_21 -> V_68 & V_69 )
V_30 -> V_41 |= V_70 ;
else if ( V_21 -> V_68 & V_71 )
V_30 -> V_41 &= ~ V_70 ;
}
if ( V_7 == & V_30 -> V_53 [ 1 ] ) {
if ( V_21 -> V_68 & V_69 )
V_30 -> V_41 |= V_72 ;
else if ( V_21 -> V_68 & V_71 )
V_30 -> V_41 &= ~ V_72 ;
}
}
static void F_30 ( struct V_26 * V_27 )
{
struct V_6 * V_7 = F_19 ( V_27 ) ;
struct V_29 * V_30 = V_7 -> V_30 ;
int V_31 , V_35 ;
if ( V_7 == & V_30 -> V_53 [ 0 ] &&
( V_30 -> V_41 & V_54 ) == 0 )
return;
else if ( V_7 == & V_30 -> V_53 [ 1 ] &&
( V_30 -> V_41 & V_58 ) == 0 )
return;
F_31 ( V_7 -> V_9 ) ;
if ( V_7 == & V_30 -> V_53 [ 0 ] )
V_30 -> V_41 &= ~ V_54 ;
else if ( V_7 == & V_30 -> V_53 [ 1 ] )
V_30 -> V_41 &= ~ V_58 ;
F_27 ( V_30 -> V_62 , V_66 , V_30 -> V_41 ) ;
if ( V_30 -> V_41 & V_42 ) {
F_32 ( V_30 -> V_38 [ 0 ] ) ;
F_32 ( V_30 -> V_38 [ 1 ] ) ;
}
if ( V_30 -> V_55 ) {
const struct V_61 * V_55 = NULL ;
if ( V_7 == & V_30 -> V_53 [ 0 ] )
V_55 = & V_30 -> V_55 [ 0 ] ;
else if ( V_7 == & V_30 -> V_53 [ 1 ] )
V_55 = & V_30 -> V_55 [ 1 ] ;
F_33 ( V_30 -> V_62 , V_55 -> V_63 , & V_31 ) ;
V_31 &= V_55 -> V_64 ;
V_31 >>= V_55 -> V_65 ;
} else {
V_31 = ( V_7 == & V_30 -> V_53 [ 0 ] ) ? 0 : 1 ;
}
V_35 = F_16 ( V_30 -> V_39 [ V_31 ] , V_30 -> V_73 [ V_31 ] ) ;
if ( V_35 )
F_17 ( V_30 -> V_22 ,
L_7 ,
V_31 ) ;
F_34 ( V_7 -> V_9 ) ;
}
static int F_35 ( struct V_29 * V_30 , int V_32 )
{
char V_74 [ 16 ] ;
snprintf ( V_74 , sizeof( V_74 ) , L_8 , V_32 ) ;
V_30 -> V_38 [ V_32 ] = F_36 ( V_30 -> V_22 , V_74 ) ;
if ( F_37 ( V_30 -> V_38 [ V_32 ] ) )
return F_38 ( V_30 -> V_38 [ V_32 ] ) ;
snprintf ( V_74 , sizeof( V_74 ) , L_9 , V_32 ) ;
V_30 -> V_37 [ V_32 ] = F_36 ( V_30 -> V_22 , V_74 ) ;
return F_39 ( V_30 -> V_37 [ V_32 ] ) ;
}
static int F_40 ( struct V_75 * V_76 ,
struct V_6 * V_7 )
{
struct V_29 * V_30 = V_7 -> V_30 ;
int V_35 ;
V_35 = F_41 ( V_76 , & V_7 -> V_27 ,
V_7 -> V_52 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_35 ( V_30 , V_7 -> V_32 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_41 & V_42 ) {
V_35 = F_35 ( V_30 , 1 ) ;
if ( V_35 )
return V_35 ;
}
F_42 ( & V_7 -> V_27 ,
& V_77 ) ;
F_43 ( V_76 , & V_7 -> V_27 , & V_78 ,
V_79 , NULL ) ;
F_44 ( & V_7 -> V_3 ,
& V_80 ) ;
F_45 ( V_76 , & V_7 -> V_3 ,
& V_81 , V_82 ) ;
if ( V_7 -> V_9 )
F_46 ( V_7 -> V_9 , & V_7 -> V_3 ) ;
F_47 ( & V_7 -> V_3 ,
& V_7 -> V_27 ) ;
return 0 ;
}
static T_1 F_48 ( struct V_83 * V_22 , struct V_84 * V_85 )
{
const char * V_86 ;
T_1 V_87 = 0 ;
int V_35 , V_88 ;
V_35 = F_49 ( V_85 , L_10 , & V_86 ) ;
if ( V_35 < 0 )
return V_35 ;
F_50 ( V_85 , L_11 , & V_87 ) ;
for ( V_88 = 0 ; V_88 < F_51 ( V_89 ) ; V_88 ++ ) {
if ( ! strcasecmp ( V_86 , V_89 [ V_88 ] . V_90 ) &&
V_87 == V_89 [ V_88 ] . V_87 )
return V_89 [ V_88 ] . V_15 ;
}
F_17 ( V_22 , L_12 , V_87 , V_86 ) ;
return - V_91 ;
}
static int F_52 ( struct V_83 * V_22 , struct V_83 * V_92 , void * V_93 )
{
struct V_75 * V_76 = V_93 ;
struct V_84 * V_85 = V_22 -> V_94 ;
const struct V_95 * V_96 =
F_53 ( V_97 , V_22 ) ;
struct V_84 * V_52 ;
const T_2 * V_98 ;
struct V_29 * V_29 ;
int V_40 ;
int V_35 ;
int V_88 ;
V_29 = F_54 ( V_22 , sizeof( * V_29 ) , V_99 ) ;
if ( ! V_29 )
return - V_100 ;
V_29 -> V_62 = F_55 ( V_85 , L_13 ) ;
if ( F_37 ( V_29 -> V_62 ) ) {
F_17 ( V_22 , L_14 ) ;
return F_38 ( V_29 -> V_62 ) ;
}
V_29 -> V_22 = V_22 ;
if ( V_96 )
V_29 -> V_55 = V_96 -> V_93 ;
V_40 = F_56 ( V_85 , L_15 ) ;
if ( V_40 )
V_29 -> V_41 |= V_42 ;
for ( V_88 = 0 ; V_88 < 4 ; V_88 ++ ) {
char V_74 [ 16 ] ;
sprintf ( V_74 , L_16 , V_88 ) ;
V_29 -> V_39 [ V_88 ] = F_36 ( V_29 -> V_22 , V_74 ) ;
if ( F_37 ( V_29 -> V_39 [ V_88 ] ) ) {
V_35 = F_38 ( V_29 -> V_39 [ V_88 ] ) ;
V_29 -> V_39 [ V_88 ] = NULL ;
break;
}
V_29 -> V_73 [ V_88 ] = F_57 ( V_29 -> V_39 [ V_88 ] ) ;
}
if ( V_88 == 0 )
return V_35 ;
F_58 (np, child) {
struct V_6 * V_53 ;
struct V_84 * V_101 ;
V_35 = F_50 ( V_52 , L_17 , & V_88 ) ;
if ( V_35 || V_88 < 0 || V_88 > 1 )
return - V_23 ;
if ( V_40 && V_88 > 0 ) {
F_20 ( V_22 , L_18 ) ;
continue;
}
if ( ! F_59 ( V_52 ) )
continue;
V_53 = & V_29 -> V_53 [ V_88 ] ;
V_53 -> V_30 = V_29 ;
V_53 -> V_32 = V_88 ;
V_53 -> V_52 = V_52 ;
V_101 = F_60 ( V_52 , V_29 -> V_55 ? 4 : 2 ) ;
if ( V_101 ) {
struct V_84 * V_102 , * V_103 ;
V_102 = F_61 ( V_101 , L_19 ) ;
if ( V_102 ) {
V_103 = F_62 ( V_102 ) ;
if ( V_103 )
V_53 -> V_9 = F_63 ( V_103 ) ;
else
return - V_104 ;
if ( ! V_53 -> V_9 ) {
F_17 ( V_22 , L_20 ,
V_103 -> V_105 ) ;
return - V_104 ;
}
}
}
V_98 = F_64 ( V_52 , L_21 , & V_53 -> V_106 ) ;
if ( V_98 ) {
V_53 -> V_18 = F_65 ( V_98 , V_53 -> V_106 ,
V_99 ) ;
} else if ( ! V_53 -> V_9 ) {
V_35 = F_66 ( V_52 , & V_53 -> V_21 , 0 ) ;
if ( ! V_35 )
V_53 -> V_19 = 1 ;
}
V_53 -> V_15 = F_48 ( V_22 , V_52 ) ;
if ( V_53 -> V_15 == - V_23 ) {
if ( V_53 -> V_9 && V_53 -> V_9 -> V_10 &&
V_53 -> V_9 -> V_10 -> V_11 )
V_53 -> V_15 = 0 ;
}
if ( V_53 -> V_15 < 0 ) {
F_17 ( V_22 , L_22 ,
V_53 -> V_15 ) ;
return V_53 -> V_15 ;
}
V_35 = F_40 ( V_76 , V_53 ) ;
if ( V_35 )
return V_35 ;
}
F_67 ( V_22 , V_29 ) ;
return 0 ;
}
static void F_68 ( struct V_83 * V_22 , struct V_83 * V_92 ,
void * V_93 )
{
struct V_29 * V_29 = F_69 ( V_22 ) ;
int V_88 ;
for ( V_88 = 0 ; V_88 < 2 ; V_88 ++ ) {
struct V_6 * V_53 = & V_29 -> V_53 [ V_88 ] ;
if ( ! V_53 -> V_3 . V_10 )
continue;
V_53 -> V_3 . V_10 -> V_107 ( & V_53 -> V_3 ) ;
V_53 -> V_27 . V_10 -> V_107 ( & V_53 -> V_27 ) ;
F_70 ( V_53 -> V_18 ) ;
}
}
static int F_71 ( struct V_108 * V_109 )
{
return F_72 ( & V_109 -> V_22 , & V_110 ) ;
}
static int F_73 ( struct V_108 * V_109 )
{
F_74 ( & V_109 -> V_22 , & V_110 ) ;
return 0 ;
}
