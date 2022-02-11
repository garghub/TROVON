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
static void F_11 ( struct V_28 * V_29 , int V_30 , int V_31 ,
unsigned long V_32 , unsigned long V_33 )
{
int V_34 ;
F_12 ( V_29 -> V_22 , L_1 , V_35 ,
F_13 ( V_29 -> V_36 [ V_31 ] ) , V_32 ) ;
F_14 ( V_29 -> V_36 [ V_31 ] , V_32 ) ;
F_12 ( V_29 -> V_22 , L_2 , V_35 ,
F_13 ( V_29 -> V_36 [ V_31 ] ) ) ;
F_12 ( V_29 -> V_22 , L_1 , V_35 ,
F_13 ( V_29 -> V_37 [ V_31 ] ) ,
( long int ) V_33 ) ;
F_14 ( V_29 -> V_37 [ V_31 ] , V_33 ) ;
F_12 ( V_29 -> V_22 , L_2 , V_35 ,
F_13 ( V_29 -> V_37 [ V_31 ] ) ) ;
V_34 = F_15 ( V_29 -> V_38 [ V_30 ] , V_29 -> V_37 [ V_31 ] ) ;
if ( V_34 )
F_16 ( V_29 -> V_22 ,
L_3 , V_30 ,
V_31 ) ;
}
static void F_17 ( struct V_26 * V_27 )
{
struct V_6 * V_7 = F_18 ( V_27 ) ;
struct V_28 * V_29 = V_7 -> V_29 ;
int V_39 = V_29 -> V_40 & V_41 ;
T_1 V_15 ;
switch ( V_7 -> V_15 ) {
default:
F_19 ( V_29 -> V_22 ,
L_4 ) ;
case V_42 :
V_15 = V_43 ;
break;
case V_44 :
V_15 = V_45 ;
if ( V_7 -> V_31 == 0 || V_39 )
V_29 -> V_40 |= V_46 ;
if ( V_7 -> V_31 == 1 || V_39 )
V_29 -> V_40 |= V_47 ;
break;
case V_48 :
V_15 = V_45 ;
if ( V_7 -> V_31 == 0 || V_39 )
V_29 -> V_40 |= V_46 |
V_49 ;
if ( V_7 -> V_31 == 1 || V_39 )
V_29 -> V_40 |= V_47 |
V_50 ;
break;
}
F_20 ( V_27 , V_15 ) ;
}
static void F_21 ( struct V_26 * V_27 )
{
struct V_6 * V_7 = F_18 ( V_27 ) ;
struct V_28 * V_29 = V_7 -> V_29 ;
int V_39 = V_29 -> V_40 & V_41 ;
int V_30 = F_22 ( V_7 -> V_51 , V_27 ) ;
F_23 ( V_7 -> V_9 ) ;
if ( V_39 ) {
F_24 ( V_29 -> V_37 [ 0 ] ) ;
F_24 ( V_29 -> V_37 [ 1 ] ) ;
}
if ( V_7 == & V_29 -> V_52 [ 0 ] || V_39 ) {
V_29 -> V_40 &= ~ V_53 ;
if ( V_30 == 0 || V_29 -> V_54 )
V_29 -> V_40 |= V_55 ;
else if ( V_30 == 1 )
V_29 -> V_40 |= V_56 ;
}
if ( V_7 == & V_29 -> V_52 [ 1 ] || V_39 ) {
V_29 -> V_40 &= ~ V_57 ;
if ( V_30 == 1 || V_29 -> V_54 )
V_29 -> V_40 |= V_58 ;
else if ( V_30 == 0 )
V_29 -> V_40 |= V_59 ;
}
if ( V_29 -> V_54 ) {
const struct V_60 * V_54 = NULL ;
if ( V_7 == & V_29 -> V_52 [ 0 ] )
V_54 = & V_29 -> V_54 [ 0 ] ;
else if ( V_7 == & V_29 -> V_52 [ 1 ] )
V_54 = & V_29 -> V_54 [ 1 ] ;
F_25 ( V_29 -> V_61 , V_54 -> V_62 , V_54 -> V_63 ,
V_30 << V_54 -> V_64 ) ;
}
F_26 ( V_29 -> V_61 , V_65 , V_29 -> V_40 ) ;
F_27 ( V_7 -> V_9 ) ;
}
static void F_28 ( struct V_26 * V_27 ,
struct V_20 * V_66 ,
struct V_20 * V_21 )
{
struct V_6 * V_7 = F_18 ( V_27 ) ;
struct V_28 * V_29 = V_7 -> V_29 ;
int V_39 = V_29 -> V_40 & V_41 ;
unsigned long V_32 ;
unsigned long V_33 = V_21 -> clock * 1000 ;
int V_30 = F_22 ( V_7 -> V_51 , V_27 ) ;
if ( V_21 -> clock > 170000 ) {
F_19 ( V_29 -> V_22 ,
L_5 , V_35 ) ;
}
if ( V_21 -> clock > 85000 && ! V_39 ) {
F_19 ( V_29 -> V_22 ,
L_6 , V_35 ) ;
}
if ( V_39 ) {
V_32 = 3500UL * V_21 -> clock ;
F_11 ( V_29 , V_30 , 0 , V_32 , V_33 ) ;
F_11 ( V_29 , V_30 , 1 , V_32 , V_33 ) ;
} else {
V_32 = 7000UL * V_21 -> clock ;
F_11 ( V_29 , V_30 , V_7 -> V_31 , V_32 ,
V_33 ) ;
}
if ( V_7 == & V_29 -> V_52 [ 0 ] ) {
if ( V_21 -> V_67 & V_68 )
V_29 -> V_40 |= V_69 ;
else if ( V_21 -> V_67 & V_70 )
V_29 -> V_40 &= ~ V_69 ;
}
if ( V_7 == & V_29 -> V_52 [ 1 ] ) {
if ( V_21 -> V_67 & V_68 )
V_29 -> V_40 |= V_71 ;
else if ( V_21 -> V_67 & V_70 )
V_29 -> V_40 &= ~ V_71 ;
}
}
static void F_29 ( struct V_26 * V_27 )
{
struct V_6 * V_7 = F_18 ( V_27 ) ;
struct V_28 * V_29 = V_7 -> V_29 ;
int V_30 , V_34 ;
if ( V_7 == & V_29 -> V_52 [ 0 ] &&
( V_29 -> V_40 & V_53 ) == 0 )
return;
else if ( V_7 == & V_29 -> V_52 [ 1 ] &&
( V_29 -> V_40 & V_57 ) == 0 )
return;
F_30 ( V_7 -> V_9 ) ;
if ( V_7 == & V_29 -> V_52 [ 0 ] )
V_29 -> V_40 &= ~ V_53 ;
else if ( V_7 == & V_29 -> V_52 [ 1 ] )
V_29 -> V_40 &= ~ V_57 ;
F_26 ( V_29 -> V_61 , V_65 , V_29 -> V_40 ) ;
if ( V_29 -> V_40 & V_41 ) {
F_31 ( V_29 -> V_37 [ 0 ] ) ;
F_31 ( V_29 -> V_37 [ 1 ] ) ;
}
if ( V_29 -> V_54 ) {
const struct V_60 * V_54 = NULL ;
if ( V_7 == & V_29 -> V_52 [ 0 ] )
V_54 = & V_29 -> V_54 [ 0 ] ;
else if ( V_7 == & V_29 -> V_52 [ 1 ] )
V_54 = & V_29 -> V_54 [ 1 ] ;
F_32 ( V_29 -> V_61 , V_54 -> V_62 , & V_30 ) ;
V_30 &= V_54 -> V_63 ;
V_30 >>= V_54 -> V_64 ;
} else {
V_30 = ( V_7 == & V_29 -> V_52 [ 0 ] ) ? 0 : 1 ;
}
V_34 = F_15 ( V_29 -> V_38 [ V_30 ] , V_29 -> V_72 [ V_30 ] ) ;
if ( V_34 )
F_16 ( V_29 -> V_22 ,
L_7 ,
V_30 ) ;
F_33 ( V_7 -> V_9 ) ;
}
static int F_34 ( struct V_28 * V_29 , int V_31 )
{
char V_73 [ 16 ] ;
snprintf ( V_73 , sizeof( V_73 ) , L_8 , V_31 ) ;
V_29 -> V_37 [ V_31 ] = F_35 ( V_29 -> V_22 , V_73 ) ;
if ( F_36 ( V_29 -> V_37 [ V_31 ] ) )
return F_37 ( V_29 -> V_37 [ V_31 ] ) ;
snprintf ( V_73 , sizeof( V_73 ) , L_9 , V_31 ) ;
V_29 -> V_36 [ V_31 ] = F_35 ( V_29 -> V_22 , V_73 ) ;
return F_38 ( V_29 -> V_36 [ V_31 ] ) ;
}
static int F_39 ( struct V_74 * V_75 ,
struct V_6 * V_7 )
{
struct V_28 * V_29 = V_7 -> V_29 ;
int V_34 ;
V_34 = F_40 ( V_75 , & V_7 -> V_27 ,
V_7 -> V_51 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_34 ( V_29 , V_7 -> V_31 ) ;
if ( V_34 )
return V_34 ;
if ( V_29 -> V_40 & V_41 ) {
V_34 = F_34 ( V_29 , 1 ) ;
if ( V_34 )
return V_34 ;
}
F_41 ( & V_7 -> V_27 ,
& V_76 ) ;
F_42 ( V_75 , & V_7 -> V_27 , & V_77 ,
V_78 , NULL ) ;
F_43 ( & V_7 -> V_3 ,
& V_79 ) ;
F_44 ( V_75 , & V_7 -> V_3 ,
& V_80 , V_81 ) ;
if ( V_7 -> V_9 )
F_45 ( V_7 -> V_9 , & V_7 -> V_3 ) ;
F_46 ( & V_7 -> V_3 ,
& V_7 -> V_27 ) ;
return 0 ;
}
static T_1 F_47 ( struct V_82 * V_22 , struct V_83 * V_84 )
{
const char * V_85 ;
T_1 V_86 = 0 ;
int V_34 , V_87 ;
V_34 = F_48 ( V_84 , L_10 , & V_85 ) ;
if ( V_34 < 0 )
return V_34 ;
F_49 ( V_84 , L_11 , & V_86 ) ;
for ( V_87 = 0 ; V_87 < F_50 ( V_88 ) ; V_87 ++ ) {
if ( ! strcasecmp ( V_85 , V_88 [ V_87 ] . V_89 ) &&
V_86 == V_88 [ V_87 ] . V_86 )
return V_88 [ V_87 ] . V_15 ;
}
F_16 ( V_22 , L_12 , V_86 , V_85 ) ;
return - V_90 ;
}
static int F_51 ( struct V_82 * V_22 , struct V_82 * V_91 , void * V_92 )
{
struct V_74 * V_75 = V_92 ;
struct V_83 * V_84 = V_22 -> V_93 ;
const struct V_94 * V_95 =
F_52 ( V_96 , V_22 ) ;
struct V_83 * V_51 ;
const T_2 * V_97 ;
struct V_28 * V_28 ;
int V_39 ;
int V_34 ;
int V_87 ;
V_28 = F_53 ( V_22 , sizeof( * V_28 ) , V_98 ) ;
if ( ! V_28 )
return - V_99 ;
V_28 -> V_61 = F_54 ( V_84 , L_13 ) ;
if ( F_36 ( V_28 -> V_61 ) ) {
F_16 ( V_22 , L_14 ) ;
return F_37 ( V_28 -> V_61 ) ;
}
V_28 -> V_22 = V_22 ;
if ( V_95 )
V_28 -> V_54 = V_95 -> V_92 ;
V_39 = F_55 ( V_84 , L_15 ) ;
if ( V_39 )
V_28 -> V_40 |= V_41 ;
for ( V_87 = 0 ; V_87 < 4 ; V_87 ++ ) {
char V_73 [ 16 ] ;
sprintf ( V_73 , L_16 , V_87 ) ;
V_28 -> V_38 [ V_87 ] = F_35 ( V_28 -> V_22 , V_73 ) ;
if ( F_36 ( V_28 -> V_38 [ V_87 ] ) ) {
V_34 = F_37 ( V_28 -> V_38 [ V_87 ] ) ;
V_28 -> V_38 [ V_87 ] = NULL ;
break;
}
V_28 -> V_72 [ V_87 ] = F_56 ( V_28 -> V_38 [ V_87 ] ) ;
}
if ( V_87 == 0 )
return V_34 ;
F_57 (np, child) {
struct V_6 * V_52 ;
struct V_83 * V_100 ;
V_34 = F_49 ( V_51 , L_17 , & V_87 ) ;
if ( V_34 || V_87 < 0 || V_87 > 1 )
return - V_23 ;
if ( V_39 && V_87 > 0 ) {
F_19 ( V_22 , L_18 ) ;
continue;
}
if ( ! F_58 ( V_51 ) )
continue;
V_52 = & V_28 -> V_52 [ V_87 ] ;
V_52 -> V_29 = V_28 ;
V_52 -> V_31 = V_87 ;
V_52 -> V_51 = V_51 ;
V_100 = F_59 ( V_51 , V_28 -> V_54 ? 4 : 2 ) ;
if ( V_100 ) {
struct V_83 * V_101 , * V_102 ;
V_101 = F_60 ( V_100 , L_19 ) ;
if ( V_101 ) {
V_102 = F_61 ( V_101 ) ;
if ( V_102 )
V_52 -> V_9 = F_62 ( V_102 ) ;
else
return - V_103 ;
if ( ! V_52 -> V_9 ) {
F_16 ( V_22 , L_20 ,
V_102 -> V_104 ) ;
return - V_103 ;
}
}
}
V_97 = F_63 ( V_51 , L_21 , & V_52 -> V_105 ) ;
if ( V_97 ) {
V_52 -> V_18 = F_64 ( V_97 , V_52 -> V_105 ,
V_98 ) ;
} else if ( ! V_52 -> V_9 ) {
V_34 = F_65 ( V_51 , & V_52 -> V_21 , 0 ) ;
if ( ! V_34 )
V_52 -> V_19 = 1 ;
}
V_52 -> V_15 = F_47 ( V_22 , V_51 ) ;
if ( V_52 -> V_15 == - V_23 ) {
if ( V_52 -> V_9 && V_52 -> V_9 -> V_10 &&
V_52 -> V_9 -> V_10 -> V_11 )
V_52 -> V_15 = 0 ;
}
if ( V_52 -> V_15 < 0 ) {
F_16 ( V_22 , L_22 ,
V_52 -> V_15 ) ;
return V_52 -> V_15 ;
}
V_34 = F_39 ( V_75 , V_52 ) ;
if ( V_34 )
return V_34 ;
}
F_66 ( V_22 , V_28 ) ;
return 0 ;
}
static void F_67 ( struct V_82 * V_22 , struct V_82 * V_91 ,
void * V_92 )
{
struct V_28 * V_28 = F_68 ( V_22 ) ;
int V_87 ;
for ( V_87 = 0 ; V_87 < 2 ; V_87 ++ ) {
struct V_6 * V_52 = & V_28 -> V_52 [ V_87 ] ;
if ( ! V_52 -> V_3 . V_10 )
continue;
V_52 -> V_3 . V_10 -> V_106 ( & V_52 -> V_3 ) ;
V_52 -> V_27 . V_10 -> V_106 ( & V_52 -> V_27 ) ;
F_69 ( V_52 -> V_18 ) ;
}
}
static int F_70 ( struct V_107 * V_108 )
{
return F_71 ( & V_108 -> V_22 , & V_109 ) ;
}
static int F_72 ( struct V_107 * V_108 )
{
F_73 ( & V_108 -> V_22 , & V_109 ) ;
return 0 ;
}
