static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_1 , V_7 ) ;
}
static void F_4 ( struct V_1 * V_8 ,
T_1 V_9 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
int V_12 = V_11 -> V_13 & V_14 ;
switch ( V_9 ) {
case V_15 :
break;
case V_16 :
if ( V_8 -> V_17 == 0 || V_12 )
V_11 -> V_13 |= V_18 ;
if ( V_8 -> V_17 == 1 || V_12 )
V_11 -> V_13 |= V_19 ;
break;
case V_20 :
if ( V_8 -> V_17 == 0 || V_12 )
V_11 -> V_13 |= V_18 |
V_21 ;
if ( V_8 -> V_17 == 1 || V_12 )
V_11 -> V_13 |= V_19 |
V_22 ;
break;
}
}
static int F_5 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
int V_23 = 0 ;
if ( V_8 -> V_24 && V_8 -> V_24 -> V_25 &&
V_8 -> V_24 -> V_25 -> V_26 ) {
V_23 = V_8 -> V_24 -> V_25 -> V_26 ( V_8 -> V_24 ) ;
if ( V_23 > 0 )
return V_23 ;
}
if ( ! V_8 -> V_27 && V_8 -> V_28 )
V_8 -> V_27 = F_6 ( V_4 , V_8 -> V_28 ) ;
if ( V_8 -> V_27 ) {
F_7 ( V_4 ,
V_8 -> V_27 ) ;
V_23 = F_8 ( V_4 , V_8 -> V_27 ) ;
}
if ( V_8 -> V_29 ) {
struct V_30 * V_31 ;
V_31 = F_9 ( V_4 -> V_32 ) ;
if ( ! V_31 )
return - V_33 ;
F_10 ( V_31 , & V_8 -> V_31 ) ;
V_31 -> type |= V_34 | V_35 ;
F_11 ( V_4 , V_31 ) ;
V_23 ++ ;
}
return V_23 ;
}
static struct V_5 * F_12 (
struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
return & V_8 -> V_7 ;
}
static void F_13 ( struct V_10 * V_11 , int V_36 , int V_17 ,
unsigned long V_37 , unsigned long V_38 )
{
int V_39 ;
F_14 ( V_11 -> V_32 , L_1 , V_40 ,
F_15 ( V_11 -> V_41 [ V_17 ] ) , V_37 ) ;
F_16 ( V_11 -> V_41 [ V_17 ] , V_37 ) ;
F_14 ( V_11 -> V_32 , L_2 , V_40 ,
F_15 ( V_11 -> V_41 [ V_17 ] ) ) ;
F_14 ( V_11 -> V_32 , L_1 , V_40 ,
F_15 ( V_11 -> V_42 [ V_17 ] ) ,
( long int ) V_38 ) ;
F_16 ( V_11 -> V_42 [ V_17 ] , V_38 ) ;
F_14 ( V_11 -> V_32 , L_2 , V_40 ,
F_15 ( V_11 -> V_42 [ V_17 ] ) ) ;
V_39 = F_17 ( V_11 -> V_43 [ V_36 ] , V_11 -> V_42 [ V_17 ] ) ;
if ( V_39 )
F_18 ( V_11 -> V_32 ,
L_3 , V_36 ,
V_17 ) ;
}
static void F_19 ( struct V_5 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
int V_12 = V_11 -> V_13 & V_14 ;
int V_36 = F_20 ( V_8 -> V_44 , V_7 ) ;
F_21 ( V_8 -> V_24 ) ;
if ( V_12 ) {
F_17 ( V_11 -> V_43 [ V_36 ] , V_11 -> V_42 [ 0 ] ) ;
F_17 ( V_11 -> V_43 [ V_36 ] , V_11 -> V_42 [ 1 ] ) ;
F_22 ( V_11 -> V_42 [ 0 ] ) ;
F_22 ( V_11 -> V_42 [ 1 ] ) ;
} else {
F_17 ( V_11 -> V_43 [ V_36 ] , V_11 -> V_42 [ V_8 -> V_17 ] ) ;
}
if ( V_8 == & V_11 -> V_45 [ 0 ] || V_12 ) {
V_11 -> V_13 &= ~ V_46 ;
if ( V_36 == 0 || V_11 -> V_47 )
V_11 -> V_13 |= V_48 ;
else if ( V_36 == 1 )
V_11 -> V_13 |= V_49 ;
}
if ( V_8 == & V_11 -> V_45 [ 1 ] || V_12 ) {
V_11 -> V_13 &= ~ V_50 ;
if ( V_36 == 1 || V_11 -> V_47 )
V_11 -> V_13 |= V_51 ;
else if ( V_36 == 0 )
V_11 -> V_13 |= V_52 ;
}
if ( V_11 -> V_47 ) {
const struct V_53 * V_47 = NULL ;
if ( V_8 == & V_11 -> V_45 [ 0 ] )
V_47 = & V_11 -> V_47 [ 0 ] ;
else if ( V_8 == & V_11 -> V_45 [ 1 ] )
V_47 = & V_11 -> V_47 [ 1 ] ;
F_23 ( V_11 -> V_54 , V_47 -> V_55 , V_47 -> V_56 ,
V_36 << V_47 -> V_57 ) ;
}
F_24 ( V_11 -> V_54 , V_58 , V_11 -> V_13 ) ;
F_25 ( V_8 -> V_24 ) ;
}
static void
F_26 ( struct V_5 * V_7 ,
struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
struct V_30 * V_31 = & V_60 -> V_63 ;
struct V_10 * V_11 = V_8 -> V_11 ;
int V_12 = V_11 -> V_13 & V_14 ;
unsigned long V_37 ;
unsigned long V_38 = V_31 -> clock * 1000 ;
int V_36 = F_20 ( V_8 -> V_44 , V_7 ) ;
T_1 V_9 = V_8 -> V_9 ;
if ( V_31 -> clock > 170000 ) {
F_27 ( V_11 -> V_32 ,
L_4 , V_40 ) ;
}
if ( V_31 -> clock > 85000 && ! V_12 ) {
F_27 ( V_11 -> V_32 ,
L_5 , V_40 ) ;
}
if ( V_12 ) {
V_37 = 3500UL * V_31 -> clock ;
F_13 ( V_11 , V_36 , 0 , V_37 , V_38 ) ;
F_13 ( V_11 , V_36 , 1 , V_37 , V_38 ) ;
} else {
V_37 = 7000UL * V_31 -> clock ;
F_13 ( V_11 , V_36 , V_8 -> V_17 , V_37 ,
V_38 ) ;
}
if ( V_8 == & V_11 -> V_45 [ 0 ] || V_12 ) {
if ( V_31 -> V_64 & V_65 )
V_11 -> V_13 |= V_66 ;
else if ( V_31 -> V_64 & V_67 )
V_11 -> V_13 &= ~ V_66 ;
}
if ( V_8 == & V_11 -> V_45 [ 1 ] || V_12 ) {
if ( V_31 -> V_64 & V_65 )
V_11 -> V_13 |= V_68 ;
else if ( V_31 -> V_64 & V_67 )
V_11 -> V_13 &= ~ V_68 ;
}
if ( ! V_9 ) {
struct V_2 * V_4 = V_62 -> V_4 ;
struct V_69 * V_70 = & V_4 -> V_71 ;
if ( V_70 -> V_72 )
V_9 = V_70 -> V_73 [ 0 ] ;
}
F_4 ( V_8 , V_9 ) ;
}
static void F_28 ( struct V_5 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
int V_36 , V_39 ;
F_29 ( V_8 -> V_24 ) ;
if ( V_8 == & V_11 -> V_45 [ 0 ] )
V_11 -> V_13 &= ~ V_46 ;
else if ( V_8 == & V_11 -> V_45 [ 1 ] )
V_11 -> V_13 &= ~ V_50 ;
F_24 ( V_11 -> V_54 , V_58 , V_11 -> V_13 ) ;
if ( V_11 -> V_13 & V_14 ) {
F_30 ( V_11 -> V_42 [ 0 ] ) ;
F_30 ( V_11 -> V_42 [ 1 ] ) ;
}
if ( V_11 -> V_47 ) {
const struct V_53 * V_47 = NULL ;
if ( V_8 == & V_11 -> V_45 [ 0 ] )
V_47 = & V_11 -> V_47 [ 0 ] ;
else if ( V_8 == & V_11 -> V_45 [ 1 ] )
V_47 = & V_11 -> V_47 [ 1 ] ;
F_31 ( V_11 -> V_54 , V_47 -> V_55 , & V_36 ) ;
V_36 &= V_47 -> V_56 ;
V_36 >>= V_47 -> V_57 ;
} else {
V_36 = ( V_8 == & V_11 -> V_45 [ 0 ] ) ? 0 : 1 ;
}
V_39 = F_17 ( V_11 -> V_43 [ V_36 ] , V_11 -> V_74 [ V_36 ] ) ;
if ( V_39 )
F_18 ( V_11 -> V_32 ,
L_6 ,
V_36 ) ;
F_32 ( V_8 -> V_24 ) ;
}
static int F_33 ( struct V_5 * V_7 ,
struct V_59 * V_60 ,
struct V_61 * V_75 )
{
struct V_76 * V_76 = F_34 ( V_60 ) ;
struct V_1 * V_8 = F_3 ( V_7 ) ;
struct V_69 * V_70 = & V_75 -> V_4 -> V_71 ;
T_1 V_9 = V_8 -> V_9 ;
if ( ! V_9 && V_70 -> V_72 ) {
V_9 = V_70 -> V_73 [ 0 ] ;
V_76 -> V_77 = V_70 -> V_77 ;
} else {
V_9 = V_8 -> V_9 ;
V_76 -> V_77 = V_8 -> V_77 ;
}
switch ( V_9 ) {
case V_15 :
V_76 -> V_9 = V_78 ;
break;
case V_16 :
case V_20 :
V_76 -> V_9 = V_79 ;
break;
default:
return - V_33 ;
}
V_76 -> V_80 = 2 ;
V_76 -> V_81 = 3 ;
return 0 ;
}
static int F_35 ( struct V_10 * V_11 , int V_17 )
{
char V_82 [ 16 ] ;
snprintf ( V_82 , sizeof( V_82 ) , L_7 , V_17 ) ;
V_11 -> V_42 [ V_17 ] = F_36 ( V_11 -> V_32 , V_82 ) ;
if ( F_37 ( V_11 -> V_42 [ V_17 ] ) )
return F_38 ( V_11 -> V_42 [ V_17 ] ) ;
snprintf ( V_82 , sizeof( V_82 ) , L_8 , V_17 ) ;
V_11 -> V_41 [ V_17 ] = F_36 ( V_11 -> V_32 , V_82 ) ;
return F_39 ( V_11 -> V_41 [ V_17 ] ) ;
}
static int F_40 ( struct V_83 * V_84 ,
struct V_1 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
struct V_5 * V_7 = & V_8 -> V_7 ;
int V_39 ;
V_39 = F_41 ( V_84 , V_7 , V_8 -> V_44 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_35 ( V_11 , V_8 -> V_17 ) ;
if ( V_39 )
return V_39 ;
if ( V_11 -> V_13 & V_14 ) {
V_39 = F_35 ( V_11 , 1 ) ;
if ( V_39 )
return V_39 ;
}
F_42 ( V_7 , & V_85 ) ;
F_43 ( V_84 , V_7 , & V_86 ,
V_87 , NULL ) ;
if ( V_8 -> V_88 ) {
V_39 = F_44 ( & V_8 -> V_7 ,
V_8 -> V_88 , NULL ) ;
if ( V_39 ) {
F_45 ( L_9 ) ;
return V_39 ;
}
} else {
F_46 ( & V_8 -> V_4 ,
& V_89 ) ;
F_47 ( V_84 , & V_8 -> V_4 ,
& V_90 ,
V_91 ) ;
F_48 ( & V_8 -> V_4 ,
V_7 ) ;
}
if ( V_8 -> V_24 ) {
V_39 = F_49 ( V_8 -> V_24 ,
& V_8 -> V_4 ) ;
if ( V_39 )
return V_39 ;
}
return 0 ;
}
static T_1 F_50 ( struct V_92 * V_32 , struct V_93 * V_94 )
{
const char * V_95 ;
T_1 V_96 = 0 ;
int V_39 , V_97 ;
V_39 = F_51 ( V_94 , L_10 , & V_95 ) ;
if ( V_39 < 0 )
return V_39 ;
F_52 ( V_94 , L_11 , & V_96 ) ;
for ( V_97 = 0 ; V_97 < F_53 ( V_98 ) ; V_97 ++ ) {
if ( ! strcasecmp ( V_95 , V_98 [ V_97 ] . V_99 ) &&
V_96 == V_98 [ V_97 ] . V_96 )
return V_98 [ V_97 ] . V_9 ;
}
F_18 ( V_32 , L_12 , V_96 , V_95 ) ;
return - V_100 ;
}
static int F_54 ( struct V_92 * V_32 ,
struct V_1 * V_45 , struct V_93 * V_44 )
{
struct V_93 * V_101 ;
const T_2 * V_102 ;
int V_39 ;
V_101 = F_55 ( V_44 , L_13 , 0 ) ;
if ( V_101 ) {
V_45 -> V_28 = F_56 ( V_101 ) ;
F_57 ( V_101 ) ;
if ( ! V_45 -> V_28 ) {
F_27 ( V_32 , L_14 ) ;
return - V_103 ;
}
}
if ( ! V_45 -> V_28 ) {
F_14 ( V_32 , L_15 ) ;
V_102 = F_58 ( V_44 , L_16 ,
& V_45 -> V_104 ) ;
if ( V_102 ) {
V_45 -> V_27 = F_59 ( V_102 ,
V_45 -> V_104 ,
V_105 ) ;
} else if ( ! V_45 -> V_24 ) {
V_39 = F_60 ( V_44 ,
& V_45 -> V_31 ,
& V_45 -> V_77 ,
V_106 ) ;
if ( ! V_39 )
V_45 -> V_29 = 1 ;
}
}
return 0 ;
}
static int F_61 ( struct V_92 * V_32 , struct V_92 * V_107 , void * V_108 )
{
struct V_83 * V_84 = V_108 ;
struct V_93 * V_94 = V_32 -> V_109 ;
const struct V_110 * V_111 =
F_62 ( V_112 , V_32 ) ;
struct V_93 * V_44 ;
struct V_10 * V_10 ;
int V_12 ;
int V_39 ;
int V_97 ;
V_10 = F_63 ( V_32 , sizeof( * V_10 ) , V_105 ) ;
if ( ! V_10 )
return - V_113 ;
V_10 -> V_54 = F_64 ( V_94 , L_17 ) ;
if ( F_37 ( V_10 -> V_54 ) ) {
F_18 ( V_32 , L_18 ) ;
return F_38 ( V_10 -> V_54 ) ;
}
V_10 -> V_32 = V_32 ;
if ( V_111 )
V_10 -> V_47 = V_111 -> V_108 ;
V_12 = F_65 ( V_94 , L_19 ) ;
if ( V_12 )
V_10 -> V_13 |= V_14 ;
for ( V_97 = 0 ; V_97 < 4 ; V_97 ++ ) {
char V_82 [ 16 ] ;
sprintf ( V_82 , L_20 , V_97 ) ;
V_10 -> V_43 [ V_97 ] = F_36 ( V_10 -> V_32 , V_82 ) ;
if ( F_37 ( V_10 -> V_43 [ V_97 ] ) ) {
V_39 = F_38 ( V_10 -> V_43 [ V_97 ] ) ;
V_10 -> V_43 [ V_97 ] = NULL ;
break;
}
V_10 -> V_74 [ V_97 ] = F_66 ( V_10 -> V_43 [ V_97 ] ) ;
}
if ( V_97 == 0 )
return V_39 ;
F_67 (np, child) {
struct V_1 * V_45 ;
int V_9 ;
V_39 = F_52 ( V_44 , L_21 , & V_97 ) ;
if ( V_39 || V_97 < 0 || V_97 > 1 )
return - V_33 ;
if ( V_12 && V_97 > 0 ) {
F_27 ( V_32 , L_22 ) ;
continue;
}
if ( ! F_68 ( V_44 ) )
continue;
V_45 = & V_10 -> V_45 [ V_97 ] ;
V_45 -> V_11 = V_10 ;
V_45 -> V_17 = V_97 ;
V_45 -> V_44 = V_44 ;
V_39 = F_69 ( V_44 ,
V_10 -> V_47 ? 4 : 2 , 0 ,
& V_45 -> V_24 , & V_45 -> V_88 ) ;
if ( V_39 && V_39 != - V_114 )
return V_39 ;
if ( ! V_45 -> V_88 ) {
V_39 = F_54 ( V_32 , V_45 , V_44 ) ;
if ( V_39 )
return V_39 ;
}
V_9 = F_50 ( V_32 , V_44 ) ;
if ( V_9 == - V_33 ) {
if ( V_45 -> V_24 && V_45 -> V_24 -> V_25 &&
V_45 -> V_24 -> V_25 -> V_26 )
V_9 = 0 ;
}
if ( V_9 < 0 ) {
F_18 ( V_32 , L_23 ,
V_9 ) ;
return V_9 ;
}
V_45 -> V_9 = V_9 ;
V_39 = F_40 ( V_84 , V_45 ) ;
if ( V_39 )
return V_39 ;
}
F_70 ( V_32 , V_10 ) ;
return 0 ;
}
static void F_71 ( struct V_92 * V_32 , struct V_92 * V_107 ,
void * V_108 )
{
struct V_10 * V_10 = F_72 ( V_32 ) ;
int V_97 ;
for ( V_97 = 0 ; V_97 < 2 ; V_97 ++ ) {
struct V_1 * V_45 = & V_10 -> V_45 [ V_97 ] ;
if ( V_45 -> V_24 )
F_73 ( V_45 -> V_24 ) ;
F_74 ( V_45 -> V_27 ) ;
F_75 ( V_45 -> V_28 ) ;
}
}
static int F_76 ( struct V_115 * V_116 )
{
return F_77 ( & V_116 -> V_32 , & V_117 ) ;
}
static int F_78 ( struct V_115 * V_116 )
{
F_79 ( & V_116 -> V_32 , & V_117 ) ;
return 0 ;
}
