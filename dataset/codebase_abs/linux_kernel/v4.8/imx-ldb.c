static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_1 , V_7 ) ;
}
static enum V_8 F_4 (
struct V_2 * V_4 , bool V_9 )
{
return V_10 ;
}
static void F_5 ( struct V_1 * V_11 ,
T_1 V_12 )
{
struct V_13 * V_14 = V_11 -> V_14 ;
int V_15 = V_14 -> V_16 & V_17 ;
switch ( V_12 ) {
case V_18 :
break;
case V_19 :
if ( V_11 -> V_20 == 0 || V_15 )
V_14 -> V_16 |= V_21 ;
if ( V_11 -> V_20 == 1 || V_15 )
V_14 -> V_16 |= V_22 ;
break;
case V_23 :
if ( V_11 -> V_20 == 0 || V_15 )
V_14 -> V_16 |= V_21 |
V_24 ;
if ( V_11 -> V_20 == 1 || V_15 )
V_14 -> V_16 |= V_22 |
V_25 ;
break;
}
}
static int F_6 ( struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_26 = 0 ;
if ( V_11 -> V_27 && V_11 -> V_27 -> V_28 &&
V_11 -> V_27 -> V_28 -> V_29 ) {
V_26 = V_11 -> V_27 -> V_28 -> V_29 ( V_11 -> V_27 ) ;
if ( V_26 > 0 )
return V_26 ;
}
if ( ! V_11 -> V_30 && V_11 -> V_31 )
V_11 -> V_30 = F_7 ( V_4 , V_11 -> V_31 ) ;
if ( V_11 -> V_30 ) {
F_8 ( V_4 ,
V_11 -> V_30 ) ;
V_26 = F_9 ( V_4 , V_11 -> V_30 ) ;
}
if ( V_11 -> V_32 ) {
struct V_33 * V_34 ;
V_34 = F_10 ( V_4 -> V_35 ) ;
if ( ! V_34 )
return - V_36 ;
F_11 ( V_34 , & V_11 -> V_34 ) ;
V_34 -> type |= V_37 | V_38 ;
F_12 ( V_4 , V_34 ) ;
V_26 ++ ;
}
return V_26 ;
}
static struct V_5 * F_13 (
struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
return & V_11 -> V_7 ;
}
static void F_14 ( struct V_13 * V_14 , int V_39 , int V_20 ,
unsigned long V_40 , unsigned long V_41 )
{
int V_42 ;
F_15 ( V_14 -> V_35 , L_1 , V_43 ,
F_16 ( V_14 -> V_44 [ V_20 ] ) , V_40 ) ;
F_17 ( V_14 -> V_44 [ V_20 ] , V_40 ) ;
F_15 ( V_14 -> V_35 , L_2 , V_43 ,
F_16 ( V_14 -> V_44 [ V_20 ] ) ) ;
F_15 ( V_14 -> V_35 , L_1 , V_43 ,
F_16 ( V_14 -> V_45 [ V_20 ] ) ,
( long int ) V_41 ) ;
F_17 ( V_14 -> V_45 [ V_20 ] , V_41 ) ;
F_15 ( V_14 -> V_35 , L_2 , V_43 ,
F_16 ( V_14 -> V_45 [ V_20 ] ) ) ;
V_42 = F_18 ( V_14 -> V_46 [ V_39 ] , V_14 -> V_45 [ V_20 ] ) ;
if ( V_42 )
F_19 ( V_14 -> V_35 ,
L_3 , V_39 ,
V_20 ) ;
}
static void F_20 ( struct V_5 * V_7 )
{
struct V_1 * V_11 = F_3 ( V_7 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
int V_15 = V_14 -> V_16 & V_17 ;
int V_39 = F_21 ( V_11 -> V_47 , V_7 ) ;
F_22 ( V_11 -> V_27 ) ;
if ( V_15 ) {
F_18 ( V_14 -> V_46 [ V_39 ] , V_14 -> V_45 [ 0 ] ) ;
F_18 ( V_14 -> V_46 [ V_39 ] , V_14 -> V_45 [ 1 ] ) ;
F_23 ( V_14 -> V_45 [ 0 ] ) ;
F_23 ( V_14 -> V_45 [ 1 ] ) ;
} else {
F_18 ( V_14 -> V_46 [ V_39 ] , V_14 -> V_45 [ V_11 -> V_20 ] ) ;
}
if ( V_11 == & V_14 -> V_48 [ 0 ] || V_15 ) {
V_14 -> V_16 &= ~ V_49 ;
if ( V_39 == 0 || V_14 -> V_50 )
V_14 -> V_16 |= V_51 ;
else if ( V_39 == 1 )
V_14 -> V_16 |= V_52 ;
}
if ( V_11 == & V_14 -> V_48 [ 1 ] || V_15 ) {
V_14 -> V_16 &= ~ V_53 ;
if ( V_39 == 1 || V_14 -> V_50 )
V_14 -> V_16 |= V_54 ;
else if ( V_39 == 0 )
V_14 -> V_16 |= V_55 ;
}
if ( V_14 -> V_50 ) {
const struct V_56 * V_50 = NULL ;
if ( V_11 == & V_14 -> V_48 [ 0 ] )
V_50 = & V_14 -> V_50 [ 0 ] ;
else if ( V_11 == & V_14 -> V_48 [ 1 ] )
V_50 = & V_14 -> V_50 [ 1 ] ;
F_24 ( V_14 -> V_57 , V_50 -> V_58 , V_50 -> V_59 ,
V_39 << V_50 -> V_60 ) ;
}
F_25 ( V_14 -> V_57 , V_61 , V_14 -> V_16 ) ;
F_26 ( V_11 -> V_27 ) ;
}
static void F_27 ( struct V_5 * V_7 ,
struct V_33 * V_62 ,
struct V_33 * V_34 )
{
struct V_1 * V_11 = F_3 ( V_7 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
int V_15 = V_14 -> V_16 & V_17 ;
unsigned long V_40 ;
unsigned long V_41 = V_34 -> clock * 1000 ;
int V_39 = F_21 ( V_11 -> V_47 , V_7 ) ;
T_1 V_12 = V_11 -> V_12 ;
if ( V_34 -> clock > 170000 ) {
F_28 ( V_14 -> V_35 ,
L_4 , V_43 ) ;
}
if ( V_34 -> clock > 85000 && ! V_15 ) {
F_28 ( V_14 -> V_35 ,
L_5 , V_43 ) ;
}
if ( V_15 ) {
V_40 = 3500UL * V_34 -> clock ;
F_14 ( V_14 , V_39 , 0 , V_40 , V_41 ) ;
F_14 ( V_14 , V_39 , 1 , V_40 , V_41 ) ;
} else {
V_40 = 7000UL * V_34 -> clock ;
F_14 ( V_14 , V_39 , V_11 -> V_20 , V_40 ,
V_41 ) ;
}
if ( V_11 == & V_14 -> V_48 [ 0 ] || V_15 ) {
if ( V_34 -> V_63 & V_64 )
V_14 -> V_16 |= V_65 ;
else if ( V_34 -> V_63 & V_66 )
V_14 -> V_16 &= ~ V_65 ;
}
if ( V_11 == & V_14 -> V_48 [ 1 ] || V_15 ) {
if ( V_34 -> V_63 & V_64 )
V_14 -> V_16 |= V_67 ;
else if ( V_34 -> V_63 & V_66 )
V_14 -> V_16 &= ~ V_67 ;
}
if ( ! V_12 ) {
struct V_2 * V_4 ;
F_29 (connector, encoder->dev) {
struct V_68 * V_69 = & V_4 -> V_70 ;
if ( V_4 -> V_7 == V_7 &&
V_69 -> V_71 ) {
V_12 = V_69 -> V_72 [ 0 ] ;
break;
}
}
}
F_5 ( V_11 , V_12 ) ;
}
static void F_30 ( struct V_5 * V_7 )
{
struct V_1 * V_11 = F_3 ( V_7 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
int V_39 , V_42 ;
if ( V_11 == & V_14 -> V_48 [ 0 ] &&
( V_14 -> V_16 & V_49 ) == 0 )
return;
else if ( V_11 == & V_14 -> V_48 [ 1 ] &&
( V_14 -> V_16 & V_53 ) == 0 )
return;
F_31 ( V_11 -> V_27 ) ;
if ( V_11 == & V_14 -> V_48 [ 0 ] )
V_14 -> V_16 &= ~ V_49 ;
else if ( V_11 == & V_14 -> V_48 [ 1 ] )
V_14 -> V_16 &= ~ V_53 ;
F_25 ( V_14 -> V_57 , V_61 , V_14 -> V_16 ) ;
if ( V_14 -> V_16 & V_17 ) {
F_32 ( V_14 -> V_45 [ 0 ] ) ;
F_32 ( V_14 -> V_45 [ 1 ] ) ;
}
if ( V_14 -> V_50 ) {
const struct V_56 * V_50 = NULL ;
if ( V_11 == & V_14 -> V_48 [ 0 ] )
V_50 = & V_14 -> V_50 [ 0 ] ;
else if ( V_11 == & V_14 -> V_48 [ 1 ] )
V_50 = & V_14 -> V_50 [ 1 ] ;
F_33 ( V_14 -> V_57 , V_50 -> V_58 , & V_39 ) ;
V_39 &= V_50 -> V_59 ;
V_39 >>= V_50 -> V_60 ;
} else {
V_39 = ( V_11 == & V_14 -> V_48 [ 0 ] ) ? 0 : 1 ;
}
V_42 = F_18 ( V_14 -> V_46 [ V_39 ] , V_14 -> V_73 [ V_39 ] ) ;
if ( V_42 )
F_19 ( V_14 -> V_35 ,
L_6 ,
V_39 ) ;
F_34 ( V_11 -> V_27 ) ;
}
static int F_35 ( struct V_5 * V_7 ,
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_78 * V_78 = F_36 ( V_75 ) ;
struct V_1 * V_11 = F_3 ( V_7 ) ;
struct V_68 * V_69 = & V_77 -> V_4 -> V_70 ;
T_1 V_12 = V_11 -> V_12 ;
if ( ! V_12 && V_69 -> V_71 )
V_12 = V_69 -> V_72 [ 0 ] ;
switch ( V_12 ) {
case V_18 :
V_78 -> V_12 = V_79 ;
break;
case V_19 :
case V_23 :
V_78 -> V_12 = V_80 ;
break;
default:
return - V_36 ;
}
V_78 -> V_81 = 2 ;
V_78 -> V_82 = 3 ;
return 0 ;
}
static int F_37 ( struct V_13 * V_14 , int V_20 )
{
char V_83 [ 16 ] ;
snprintf ( V_83 , sizeof( V_83 ) , L_7 , V_20 ) ;
V_14 -> V_45 [ V_20 ] = F_38 ( V_14 -> V_35 , V_83 ) ;
if ( F_39 ( V_14 -> V_45 [ V_20 ] ) )
return F_40 ( V_14 -> V_45 [ V_20 ] ) ;
snprintf ( V_83 , sizeof( V_83 ) , L_8 , V_20 ) ;
V_14 -> V_44 [ V_20 ] = F_38 ( V_14 -> V_35 , V_83 ) ;
return F_41 ( V_14 -> V_44 [ V_20 ] ) ;
}
static int F_42 ( struct V_84 * V_85 ,
struct V_1 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_5 * V_7 = & V_11 -> V_7 ;
int V_42 ;
V_42 = F_43 ( V_85 , V_7 , V_11 -> V_47 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_37 ( V_14 , V_11 -> V_20 ) ;
if ( V_42 )
return V_42 ;
if ( V_14 -> V_16 & V_17 ) {
V_42 = F_37 ( V_14 , 1 ) ;
if ( V_42 )
return V_42 ;
}
F_44 ( V_7 , & V_86 ) ;
F_45 ( V_85 , V_7 , & V_87 ,
V_88 , NULL ) ;
F_46 ( & V_11 -> V_4 ,
& V_89 ) ;
F_47 ( V_85 , & V_11 -> V_4 ,
& V_90 , V_91 ) ;
if ( V_11 -> V_27 ) {
V_42 = F_48 ( V_11 -> V_27 ,
& V_11 -> V_4 ) ;
if ( V_42 )
return V_42 ;
}
F_49 ( & V_11 -> V_4 , V_7 ) ;
return 0 ;
}
static T_1 F_50 ( struct V_92 * V_35 , struct V_93 * V_94 )
{
const char * V_95 ;
T_1 V_96 = 0 ;
int V_42 , V_97 ;
V_42 = F_51 ( V_94 , L_9 , & V_95 ) ;
if ( V_42 < 0 )
return V_42 ;
F_52 ( V_94 , L_10 , & V_96 ) ;
for ( V_97 = 0 ; V_97 < F_53 ( V_98 ) ; V_97 ++ ) {
if ( ! strcasecmp ( V_95 , V_98 [ V_97 ] . V_99 ) &&
V_96 == V_98 [ V_97 ] . V_96 )
return V_98 [ V_97 ] . V_12 ;
}
F_19 ( V_35 , L_11 , V_96 , V_95 ) ;
return - V_100 ;
}
static int F_54 ( struct V_92 * V_35 , struct V_92 * V_101 , void * V_102 )
{
struct V_84 * V_85 = V_102 ;
struct V_93 * V_94 = V_35 -> V_103 ;
const struct V_104 * V_105 =
F_55 ( V_106 , V_35 ) ;
struct V_93 * V_47 ;
const T_2 * V_107 ;
struct V_13 * V_13 ;
int V_15 ;
int V_42 ;
int V_97 ;
V_13 = F_56 ( V_35 , sizeof( * V_13 ) , V_108 ) ;
if ( ! V_13 )
return - V_109 ;
V_13 -> V_57 = F_57 ( V_94 , L_12 ) ;
if ( F_39 ( V_13 -> V_57 ) ) {
F_19 ( V_35 , L_13 ) ;
return F_40 ( V_13 -> V_57 ) ;
}
V_13 -> V_35 = V_35 ;
if ( V_105 )
V_13 -> V_50 = V_105 -> V_102 ;
V_15 = F_58 ( V_94 , L_14 ) ;
if ( V_15 )
V_13 -> V_16 |= V_17 ;
for ( V_97 = 0 ; V_97 < 4 ; V_97 ++ ) {
char V_83 [ 16 ] ;
sprintf ( V_83 , L_15 , V_97 ) ;
V_13 -> V_46 [ V_97 ] = F_38 ( V_13 -> V_35 , V_83 ) ;
if ( F_39 ( V_13 -> V_46 [ V_97 ] ) ) {
V_42 = F_40 ( V_13 -> V_46 [ V_97 ] ) ;
V_13 -> V_46 [ V_97 ] = NULL ;
break;
}
V_13 -> V_73 [ V_97 ] = F_59 ( V_13 -> V_46 [ V_97 ] ) ;
}
if ( V_97 == 0 )
return V_42 ;
F_60 (np, child) {
struct V_1 * V_48 ;
struct V_93 * V_110 ;
struct V_93 * V_111 ;
int V_12 ;
V_42 = F_52 ( V_47 , L_16 , & V_97 ) ;
if ( V_42 || V_97 < 0 || V_97 > 1 )
return - V_36 ;
if ( V_15 && V_97 > 0 ) {
F_28 ( V_35 , L_17 ) ;
continue;
}
if ( ! F_61 ( V_47 ) )
continue;
V_48 = & V_13 -> V_48 [ V_97 ] ;
V_48 -> V_14 = V_13 ;
V_48 -> V_20 = V_97 ;
V_48 -> V_47 = V_47 ;
V_111 = F_62 ( V_47 ,
V_13 -> V_50 ? 4 : 2 ,
- 1 ) ;
if ( V_111 ) {
struct V_93 * V_112 ;
V_112 = F_63 ( V_111 ) ;
F_64 ( V_111 ) ;
if ( V_112 )
V_48 -> V_27 = F_65 ( V_112 ) ;
else
return - V_113 ;
F_64 ( V_112 ) ;
if ( ! V_48 -> V_27 ) {
F_19 ( V_35 , L_18 ,
V_112 -> V_114 ) ;
return - V_113 ;
}
}
V_110 = F_66 ( V_47 , L_19 , 0 ) ;
if ( V_110 ) {
V_48 -> V_31 = F_67 ( V_110 ) ;
F_64 ( V_110 ) ;
if ( ! V_48 -> V_31 ) {
F_28 ( V_35 , L_20 ) ;
return - V_113 ;
}
}
if ( ! V_48 -> V_31 ) {
F_15 ( V_35 , L_21 ) ;
V_107 = F_68 ( V_47 , L_22 ,
& V_48 -> V_115 ) ;
if ( V_107 ) {
V_48 -> V_30 = F_69 ( V_107 ,
V_48 -> V_115 ,
V_108 ) ;
} else if ( ! V_48 -> V_27 ) {
V_42 = F_70 ( V_47 ,
& V_48 -> V_34 ,
V_116 ) ;
if ( ! V_42 )
V_48 -> V_32 = 1 ;
}
}
V_12 = F_50 ( V_35 , V_47 ) ;
if ( V_12 == - V_36 ) {
if ( V_48 -> V_27 && V_48 -> V_27 -> V_28 &&
V_48 -> V_27 -> V_28 -> V_29 )
V_12 = 0 ;
}
if ( V_12 < 0 ) {
F_19 ( V_35 , L_23 ,
V_12 ) ;
return V_12 ;
}
V_48 -> V_12 = V_12 ;
V_42 = F_42 ( V_85 , V_48 ) ;
if ( V_42 )
return V_42 ;
}
F_71 ( V_35 , V_13 ) ;
return 0 ;
}
static void F_72 ( struct V_92 * V_35 , struct V_92 * V_101 ,
void * V_102 )
{
struct V_13 * V_13 = F_73 ( V_35 ) ;
int V_97 ;
for ( V_97 = 0 ; V_97 < 2 ; V_97 ++ ) {
struct V_1 * V_48 = & V_13 -> V_48 [ V_97 ] ;
if ( ! V_48 -> V_4 . V_28 )
continue;
V_48 -> V_4 . V_28 -> V_117 ( & V_48 -> V_4 ) ;
V_48 -> V_7 . V_28 -> V_117 ( & V_48 -> V_7 ) ;
F_74 ( V_48 -> V_30 ) ;
F_75 ( V_48 -> V_31 ) ;
}
}
static int F_76 ( struct V_118 * V_119 )
{
return F_77 ( & V_119 -> V_35 , & V_120 ) ;
}
static int F_78 ( struct V_118 * V_119 )
{
F_79 ( & V_119 -> V_35 , & V_120 ) ;
return 0 ;
}
