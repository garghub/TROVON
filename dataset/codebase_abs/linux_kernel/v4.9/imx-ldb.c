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
static void
F_27 ( struct V_5 * V_7 ,
struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_1 * V_11 = F_3 ( V_7 ) ;
struct V_33 * V_34 = & V_63 -> V_66 ;
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
if ( V_34 -> V_67 & V_68 )
V_14 -> V_16 |= V_69 ;
else if ( V_34 -> V_67 & V_70 )
V_14 -> V_16 &= ~ V_69 ;
}
if ( V_11 == & V_14 -> V_48 [ 1 ] || V_15 ) {
if ( V_34 -> V_67 & V_68 )
V_14 -> V_16 |= V_71 ;
else if ( V_34 -> V_67 & V_70 )
V_14 -> V_16 &= ~ V_71 ;
}
if ( ! V_12 ) {
struct V_2 * V_4 = V_65 -> V_4 ;
struct V_72 * V_73 = & V_4 -> V_74 ;
if ( V_73 -> V_75 )
V_12 = V_73 -> V_76 [ 0 ] ;
}
F_5 ( V_11 , V_12 ) ;
}
static void F_29 ( struct V_5 * V_7 )
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
F_30 ( V_11 -> V_27 ) ;
if ( V_11 == & V_14 -> V_48 [ 0 ] )
V_14 -> V_16 &= ~ V_49 ;
else if ( V_11 == & V_14 -> V_48 [ 1 ] )
V_14 -> V_16 &= ~ V_53 ;
F_25 ( V_14 -> V_57 , V_61 , V_14 -> V_16 ) ;
if ( V_14 -> V_16 & V_17 ) {
F_31 ( V_14 -> V_45 [ 0 ] ) ;
F_31 ( V_14 -> V_45 [ 1 ] ) ;
}
if ( V_14 -> V_50 ) {
const struct V_56 * V_50 = NULL ;
if ( V_11 == & V_14 -> V_48 [ 0 ] )
V_50 = & V_14 -> V_50 [ 0 ] ;
else if ( V_11 == & V_14 -> V_48 [ 1 ] )
V_50 = & V_14 -> V_50 [ 1 ] ;
F_32 ( V_14 -> V_57 , V_50 -> V_58 , & V_39 ) ;
V_39 &= V_50 -> V_59 ;
V_39 >>= V_50 -> V_60 ;
} else {
V_39 = ( V_11 == & V_14 -> V_48 [ 0 ] ) ? 0 : 1 ;
}
V_42 = F_18 ( V_14 -> V_46 [ V_39 ] , V_14 -> V_77 [ V_39 ] ) ;
if ( V_42 )
F_19 ( V_14 -> V_35 ,
L_6 ,
V_39 ) ;
F_33 ( V_11 -> V_27 ) ;
}
static int F_34 ( struct V_5 * V_7 ,
struct V_62 * V_63 ,
struct V_64 * V_78 )
{
struct V_79 * V_79 = F_35 ( V_63 ) ;
struct V_1 * V_11 = F_3 ( V_7 ) ;
struct V_72 * V_73 = & V_78 -> V_4 -> V_74 ;
T_1 V_12 = V_11 -> V_12 ;
if ( ! V_12 && V_73 -> V_75 ) {
V_12 = V_73 -> V_76 [ 0 ] ;
V_79 -> V_80 = V_73 -> V_80 ;
} else {
V_12 = V_11 -> V_12 ;
V_79 -> V_80 = V_11 -> V_80 ;
}
switch ( V_12 ) {
case V_18 :
V_79 -> V_12 = V_81 ;
break;
case V_19 :
case V_23 :
V_79 -> V_12 = V_82 ;
break;
default:
return - V_36 ;
}
V_79 -> V_83 = 2 ;
V_79 -> V_84 = 3 ;
return 0 ;
}
static int F_36 ( struct V_13 * V_14 , int V_20 )
{
char V_85 [ 16 ] ;
snprintf ( V_85 , sizeof( V_85 ) , L_7 , V_20 ) ;
V_14 -> V_45 [ V_20 ] = F_37 ( V_14 -> V_35 , V_85 ) ;
if ( F_38 ( V_14 -> V_45 [ V_20 ] ) )
return F_39 ( V_14 -> V_45 [ V_20 ] ) ;
snprintf ( V_85 , sizeof( V_85 ) , L_8 , V_20 ) ;
V_14 -> V_44 [ V_20 ] = F_37 ( V_14 -> V_35 , V_85 ) ;
return F_40 ( V_14 -> V_44 [ V_20 ] ) ;
}
static int F_41 ( struct V_86 * V_87 ,
struct V_1 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_5 * V_7 = & V_11 -> V_7 ;
int V_42 ;
V_42 = F_42 ( V_87 , V_7 , V_11 -> V_47 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_36 ( V_14 , V_11 -> V_20 ) ;
if ( V_42 )
return V_42 ;
if ( V_14 -> V_16 & V_17 ) {
V_42 = F_36 ( V_14 , 1 ) ;
if ( V_42 )
return V_42 ;
}
F_43 ( V_7 , & V_88 ) ;
F_44 ( V_87 , V_7 , & V_89 ,
V_90 , NULL ) ;
if ( V_11 -> V_91 ) {
V_11 -> V_91 -> V_7 = V_7 ;
V_11 -> V_7 . V_91 = V_11 -> V_91 ;
V_42 = F_45 ( V_87 , V_11 -> V_91 ) ;
if ( V_42 ) {
F_46 ( L_9 ) ;
return V_42 ;
}
} else {
F_47 ( & V_11 -> V_4 ,
& V_92 ) ;
F_48 ( V_87 , & V_11 -> V_4 ,
& V_93 ,
V_94 ) ;
F_49 ( & V_11 -> V_4 ,
V_7 ) ;
}
if ( V_11 -> V_27 ) {
V_42 = F_50 ( V_11 -> V_27 ,
& V_11 -> V_4 ) ;
if ( V_42 )
return V_42 ;
}
return 0 ;
}
static T_1 F_51 ( struct V_95 * V_35 , struct V_96 * V_97 )
{
const char * V_98 ;
T_1 V_99 = 0 ;
int V_42 , V_100 ;
V_42 = F_52 ( V_97 , L_10 , & V_98 ) ;
if ( V_42 < 0 )
return V_42 ;
F_53 ( V_97 , L_11 , & V_99 ) ;
for ( V_100 = 0 ; V_100 < F_54 ( V_101 ) ; V_100 ++ ) {
if ( ! strcasecmp ( V_98 , V_101 [ V_100 ] . V_102 ) &&
V_99 == V_101 [ V_100 ] . V_99 )
return V_101 [ V_100 ] . V_12 ;
}
F_19 ( V_35 , L_12 , V_99 , V_98 ) ;
return - V_103 ;
}
static int F_55 ( struct V_95 * V_35 ,
struct V_1 * V_48 , struct V_96 * V_47 )
{
struct V_96 * V_104 ;
const T_2 * V_105 ;
int V_42 ;
V_104 = F_56 ( V_47 , L_13 , 0 ) ;
if ( V_104 ) {
V_48 -> V_31 = F_57 ( V_104 ) ;
F_58 ( V_104 ) ;
if ( ! V_48 -> V_31 ) {
F_28 ( V_35 , L_14 ) ;
return - V_106 ;
}
}
if ( ! V_48 -> V_31 ) {
F_15 ( V_35 , L_15 ) ;
V_105 = F_59 ( V_47 , L_16 ,
& V_48 -> V_107 ) ;
if ( V_105 ) {
V_48 -> V_30 = F_60 ( V_105 ,
V_48 -> V_107 ,
V_108 ) ;
} else if ( ! V_48 -> V_27 ) {
V_42 = F_61 ( V_47 ,
& V_48 -> V_34 ,
& V_48 -> V_80 ,
V_109 ) ;
if ( ! V_42 )
V_48 -> V_32 = 1 ;
}
}
return 0 ;
}
static int F_62 ( struct V_95 * V_35 , struct V_95 * V_110 , void * V_111 )
{
struct V_86 * V_87 = V_111 ;
struct V_96 * V_97 = V_35 -> V_112 ;
const struct V_113 * V_114 =
F_63 ( V_115 , V_35 ) ;
struct V_96 * V_47 ;
struct V_13 * V_13 ;
int V_15 ;
int V_42 ;
int V_100 ;
V_13 = F_64 ( V_35 , sizeof( * V_13 ) , V_108 ) ;
if ( ! V_13 )
return - V_116 ;
V_13 -> V_57 = F_65 ( V_97 , L_17 ) ;
if ( F_38 ( V_13 -> V_57 ) ) {
F_19 ( V_35 , L_18 ) ;
return F_39 ( V_13 -> V_57 ) ;
}
V_13 -> V_35 = V_35 ;
if ( V_114 )
V_13 -> V_50 = V_114 -> V_111 ;
V_15 = F_66 ( V_97 , L_19 ) ;
if ( V_15 )
V_13 -> V_16 |= V_17 ;
for ( V_100 = 0 ; V_100 < 4 ; V_100 ++ ) {
char V_85 [ 16 ] ;
sprintf ( V_85 , L_20 , V_100 ) ;
V_13 -> V_46 [ V_100 ] = F_37 ( V_13 -> V_35 , V_85 ) ;
if ( F_38 ( V_13 -> V_46 [ V_100 ] ) ) {
V_42 = F_39 ( V_13 -> V_46 [ V_100 ] ) ;
V_13 -> V_46 [ V_100 ] = NULL ;
break;
}
V_13 -> V_77 [ V_100 ] = F_67 ( V_13 -> V_46 [ V_100 ] ) ;
}
if ( V_100 == 0 )
return V_42 ;
F_68 (np, child) {
struct V_1 * V_48 ;
struct V_96 * V_117 ;
int V_12 ;
V_42 = F_53 ( V_47 , L_21 , & V_100 ) ;
if ( V_42 || V_100 < 0 || V_100 > 1 )
return - V_36 ;
if ( V_15 && V_100 > 0 ) {
F_28 ( V_35 , L_22 ) ;
continue;
}
if ( ! F_69 ( V_47 ) )
continue;
V_48 = & V_13 -> V_48 [ V_100 ] ;
V_48 -> V_14 = V_13 ;
V_48 -> V_20 = V_100 ;
V_48 -> V_47 = V_47 ;
V_117 = F_70 ( V_47 ,
V_13 -> V_50 ? 4 : 2 ,
- 1 ) ;
if ( V_117 ) {
struct V_96 * V_118 ;
V_118 = F_71 ( V_117 ) ;
F_58 ( V_117 ) ;
if ( V_118 ) {
V_48 -> V_27 = F_72 ( V_118 ) ;
V_48 -> V_91 = F_73 ( V_118 ) ;
} else
return - V_106 ;
F_58 ( V_118 ) ;
if ( ! V_48 -> V_27 && ! V_48 -> V_91 ) {
F_19 ( V_35 , L_23 ,
V_118 -> V_119 ) ;
return - V_106 ;
}
}
if ( ! V_48 -> V_91 ) {
V_42 = F_55 ( V_35 , V_48 , V_47 ) ;
if ( V_42 )
return V_42 ;
}
V_12 = F_51 ( V_35 , V_47 ) ;
if ( V_12 == - V_36 ) {
if ( V_48 -> V_27 && V_48 -> V_27 -> V_28 &&
V_48 -> V_27 -> V_28 -> V_29 )
V_12 = 0 ;
}
if ( V_12 < 0 ) {
F_19 ( V_35 , L_24 ,
V_12 ) ;
return V_12 ;
}
V_48 -> V_12 = V_12 ;
V_42 = F_41 ( V_87 , V_48 ) ;
if ( V_42 )
return V_42 ;
}
F_74 ( V_35 , V_13 ) ;
return 0 ;
}
static void F_75 ( struct V_95 * V_35 , struct V_95 * V_110 ,
void * V_111 )
{
struct V_13 * V_13 = F_76 ( V_35 ) ;
int V_100 ;
for ( V_100 = 0 ; V_100 < 2 ; V_100 ++ ) {
struct V_1 * V_48 = & V_13 -> V_48 [ V_100 ] ;
if ( V_48 -> V_91 )
F_77 ( V_48 -> V_91 ) ;
if ( V_48 -> V_27 )
F_78 ( V_48 -> V_27 ) ;
F_79 ( V_48 -> V_30 ) ;
F_80 ( V_48 -> V_31 ) ;
}
}
static int F_81 ( struct V_120 * V_121 )
{
return F_82 ( & V_121 -> V_35 , & V_122 ) ;
}
static int F_83 ( struct V_120 * V_121 )
{
F_84 ( & V_121 -> V_35 , & V_122 ) ;
return 0 ;
}
