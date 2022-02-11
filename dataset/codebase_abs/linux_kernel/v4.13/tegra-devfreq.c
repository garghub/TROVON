static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_1 F_5 ( struct V_6 * V_7 , T_1 V_3 )
{
return F_2 ( V_7 -> V_4 + V_3 ) ;
}
static void F_6 ( struct V_6 * V_7 , T_1 V_5 ,
T_1 V_3 )
{
F_4 ( V_5 , V_7 -> V_4 + V_3 ) ;
}
static unsigned long F_7 ( unsigned long V_5 , unsigned int V_8 )
{
return V_5 * V_8 / 100 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
T_1 V_9 = V_7 -> V_10 ;
T_1 V_11 = V_2 -> V_12 * V_13 / V_14 ;
T_1 V_15 = V_11 * V_16 ;
F_6 ( V_7 , V_9 + V_15 , V_17 ) ;
V_9 = F_9 ( V_7 -> V_10 , V_15 ) ;
F_6 ( V_7 , V_9 - V_15 , V_18 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
T_1 V_5 = V_2 -> V_19 * V_16 ;
F_6 ( V_7 , F_7 ( V_5 , V_7 -> V_20 -> V_21 ) ,
V_22 ) ;
F_6 ( V_7 , F_7 ( V_5 , V_7 -> V_20 -> V_23 ) ,
V_24 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 () ;
F_1 ( V_2 , V_25 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
unsigned long V_26 ;
T_1 V_27 , V_28 ;
F_14 ( & V_7 -> V_29 , V_26 ) ;
V_7 -> V_10 = F_5 ( V_7 , V_30 ) ;
F_8 ( V_2 , V_7 ) ;
V_27 = F_5 ( V_7 , V_31 ) ;
V_28 = F_5 ( V_7 , V_32 ) ;
if ( V_27 & V_33 ) {
V_7 -> V_34 = F_7 ( V_7 -> V_34 ,
V_7 -> V_20 -> V_35 ) ;
V_7 -> V_34 += V_36 ;
V_28 |= V_37 ;
if ( V_7 -> V_34 >= V_2 -> V_12 )
V_7 -> V_34 = V_2 -> V_12 ;
else
V_28 |= V_38 ;
} else if ( V_27 & V_39 ) {
V_7 -> V_34 = F_7 ( V_7 -> V_34 ,
V_7 -> V_20 -> V_40 ) ;
V_28 |= V_38 ;
if ( V_7 -> V_34 < ( V_36 >> 1 ) )
V_7 -> V_34 = 0 ;
else
V_28 |= V_37 ;
}
if ( V_7 -> V_20 -> V_41 ) {
if ( V_7 -> V_10 >= V_7 -> V_20 -> V_41 )
V_28 |= V_37 ;
else if ( V_7 -> V_34 == 0 )
V_28 &= ~ V_37 ;
}
F_6 ( V_7 , V_28 , V_32 ) ;
F_6 ( V_7 , V_42 , V_31 ) ;
F_11 ( V_2 ) ;
F_15 ( & V_7 -> V_29 , V_26 ) ;
}
static T_2 F_16 ( int V_43 , void * V_44 )
{
struct V_1 * V_2 = V_44 ;
bool V_45 = false ;
unsigned int V_46 ;
T_1 V_5 ;
V_5 = F_1 ( V_2 , V_25 ) ;
for ( V_46 = 0 ; V_46 < F_17 ( V_2 -> V_47 ) ; V_46 ++ ) {
if ( V_5 & V_2 -> V_47 [ V_46 ] . V_20 -> V_48 ) {
F_13 ( V_2 , V_2 -> V_47 + V_46 ) ;
V_45 = true ;
}
}
return V_45 ? V_49 : V_50 ;
}
static unsigned long F_18 ( struct V_1 * V_2 ,
unsigned long V_51 )
{
unsigned int V_46 ;
struct V_52 * V_53 = V_54 ;
for ( V_46 = 0 ; V_46 < F_17 ( V_54 ) ; V_46 ++ , V_53 ++ ) {
if ( V_51 >= V_53 -> V_51 ) {
if ( V_53 -> V_55 >= V_2 -> V_12 )
return V_2 -> V_12 ;
else
return V_53 -> V_55 ;
}
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
unsigned long V_51 = 0 ;
unsigned long V_56 = 0 ;
unsigned int V_57 ;
unsigned long V_26 ;
if ( V_7 -> V_20 -> V_41 ) {
V_51 = F_20 ( 0 ) ;
V_56 = F_18 ( V_2 , V_51 ) ;
}
F_14 ( & V_7 -> V_29 , V_26 ) ;
V_7 -> V_58 = V_7 -> V_10 / V_16 ;
V_57 = 100 * 100 / V_7 -> V_20 -> V_21 ;
V_7 -> V_58 = F_7 ( V_7 -> V_58 , V_57 ) ;
V_7 -> V_58 += V_7 -> V_34 ;
if ( V_7 -> V_10 >= V_7 -> V_20 -> V_41 )
V_7 -> V_58 = F_9 ( V_7 -> V_58 , V_56 ) ;
F_15 ( & V_7 -> V_29 , V_26 ) ;
}
static T_2 F_21 ( int V_43 , void * V_44 )
{
struct V_1 * V_2 = V_44 ;
F_22 ( & V_2 -> V_59 -> V_29 ) ;
F_23 ( V_2 -> V_59 ) ;
F_24 ( & V_2 -> V_59 -> V_29 ) ;
return V_60 ;
}
static int F_25 ( struct V_61 * V_62 ,
unsigned long V_63 , void * V_64 )
{
struct V_65 * V_44 = V_64 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
unsigned int V_46 ;
unsigned long V_26 ;
if ( V_63 != V_66 )
return V_67 ;
V_2 = F_26 ( V_62 , struct V_1 , V_68 ) ;
V_2 -> V_19 = V_44 -> V_69 / V_14 ;
for ( V_46 = 0 ; V_46 < F_17 ( V_2 -> V_47 ) ; V_46 ++ ) {
V_7 = & V_2 -> V_47 [ V_46 ] ;
F_14 ( & V_7 -> V_29 , V_26 ) ;
F_10 ( V_2 , V_7 ) ;
F_15 ( & V_7 -> V_29 , V_26 ) ;
}
F_11 ( V_2 ) ;
return V_67 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
T_1 V_5 ;
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < F_17 ( V_2 -> V_47 ) ; V_46 ++ ) {
V_7 = & V_2 -> V_47 [ V_46 ] ;
V_5 = F_5 ( V_7 , V_32 ) ;
V_5 |= V_70 ;
V_5 |= V_71 ;
V_5 |= V_37 ;
V_5 |= V_38 ;
F_6 ( V_7 , V_5 , V_32 ) ;
}
F_11 ( V_2 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
T_1 V_5 ;
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < F_17 ( V_2 -> V_47 ) ; V_46 ++ ) {
V_7 = & V_2 -> V_47 [ V_46 ] ;
V_5 = F_5 ( V_7 , V_32 ) ;
V_5 &= ~ V_70 ;
V_5 &= ~ V_71 ;
V_5 &= ~ V_37 ;
V_5 &= ~ V_38 ;
F_6 ( V_7 , V_5 , V_32 ) ;
}
F_11 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
T_1 V_5 = 0 ;
V_7 -> V_58 = V_2 -> V_19 ;
V_7 -> V_10 = V_2 -> V_19 * V_16 ;
F_6 ( V_7 , V_7 -> V_10 , V_72 ) ;
F_8 ( V_2 , V_7 ) ;
F_10 ( V_2 , V_7 ) ;
F_6 ( V_7 , V_73 , V_74 ) ;
F_6 ( V_7 , V_42 , V_31 ) ;
V_5 |= V_75 ;
V_5 |= ( V_76 - 1 )
<< V_77 ;
V_5 |= ( V_78 - 1 )
<< V_79 ;
V_5 |= ( V_80 - 1 )
<< V_81 ;
V_5 |= V_82 ;
F_6 ( V_7 , V_5 , V_32 ) ;
F_11 ( V_2 ) ;
}
static int F_30 ( struct V_83 * V_7 , unsigned long * V_84 ,
T_1 V_26 )
{
struct V_1 * V_2 = F_31 ( V_7 ) ;
struct V_85 * V_86 ;
unsigned long V_87 = * V_84 * V_14 ;
V_86 = F_32 ( V_7 , & V_87 , V_26 ) ;
if ( F_33 ( V_86 ) ) {
F_34 ( V_7 , L_1 , * V_84 ) ;
return F_35 ( V_86 ) ;
}
V_87 = F_36 ( V_86 ) ;
F_37 ( V_86 ) ;
F_38 ( V_2 -> V_88 , V_87 ) ;
F_39 ( V_2 -> V_88 , 0 ) ;
* V_84 = V_87 ;
return 0 ;
}
static int F_40 ( struct V_83 * V_7 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = F_31 ( V_7 ) ;
struct V_6 * V_91 ;
V_90 -> V_92 = V_2 -> V_19 ;
V_90 -> V_93 = V_2 ;
V_91 = & V_2 -> V_47 [ V_94 ] ;
V_90 -> V_95 = F_5 ( V_91 , V_30 ) ;
V_90 -> V_95 *= 100 / V_96 ;
V_90 -> V_97 = V_16 * V_2 -> V_19 ;
V_90 -> V_95 = F_41 ( V_90 -> V_95 , V_90 -> V_97 ) ;
return 0 ;
}
static int F_42 ( struct V_59 * V_59 ,
unsigned long * V_84 )
{
struct V_89 * V_90 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
unsigned long V_58 = 0 ;
unsigned int V_46 ;
int V_98 ;
V_98 = F_43 ( V_59 ) ;
if ( V_98 )
return V_98 ;
V_90 = & V_59 -> V_99 ;
V_2 = V_90 -> V_93 ;
for ( V_46 = 0 ; V_46 < F_17 ( V_2 -> V_47 ) ; V_46 ++ ) {
V_7 = & V_2 -> V_47 [ V_46 ] ;
F_19 ( V_2 , V_7 ) ;
V_58 = F_9 ( V_58 , V_7 -> V_58 ) ;
}
* V_84 = V_58 ;
return 0 ;
}
static int F_44 ( struct V_59 * V_59 ,
unsigned int V_100 , void * V_44 )
{
struct V_1 * V_2 ;
int V_101 = 0 ;
V_2 = F_31 ( V_59 -> V_7 . V_102 ) ;
switch ( V_100 ) {
case V_103 :
F_45 ( V_59 ) ;
F_27 ( V_2 ) ;
break;
case V_104 :
F_28 ( V_2 ) ;
F_46 ( V_59 ) ;
break;
case V_105 :
F_28 ( V_2 ) ;
F_47 ( V_59 ) ;
break;
case V_106 :
F_48 ( V_59 ) ;
F_27 ( V_2 ) ;
break;
}
return V_101 ;
}
static int F_49 ( struct V_107 * V_108 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_109 * V_110 ;
unsigned int V_46 ;
unsigned long V_87 ;
int V_43 ;
int V_98 ;
V_2 = F_50 ( & V_108 -> V_7 , sizeof( * V_2 ) , V_111 ) ;
if ( ! V_2 )
return - V_112 ;
V_110 = F_51 ( V_108 , V_113 , 0 ) ;
V_2 -> V_4 = F_52 ( & V_108 -> V_7 , V_110 ) ;
if ( F_33 ( V_2 -> V_4 ) )
return F_35 ( V_2 -> V_4 ) ;
V_2 -> V_114 = F_53 ( & V_108 -> V_7 , L_2 ) ;
if ( F_33 ( V_2 -> V_114 ) ) {
F_34 ( & V_108 -> V_7 , L_3 ) ;
return F_35 ( V_2 -> V_114 ) ;
}
V_2 -> clock = F_54 ( & V_108 -> V_7 , L_2 ) ;
if ( F_33 ( V_2 -> clock ) ) {
F_34 ( & V_108 -> V_7 , L_4 ) ;
return F_35 ( V_2 -> clock ) ;
}
V_2 -> V_88 = F_54 ( & V_108 -> V_7 , L_5 ) ;
if ( F_33 ( V_2 -> V_88 ) ) {
F_34 ( & V_108 -> V_7 , L_6 ) ;
return F_35 ( V_2 -> V_88 ) ;
}
F_39 ( V_2 -> V_88 , V_115 ) ;
V_2 -> V_68 . V_116 = F_25 ;
V_98 = F_55 ( V_2 -> V_88 , & V_2 -> V_68 ) ;
if ( V_98 ) {
F_34 ( & V_108 -> V_7 ,
L_7 ) ;
return V_98 ;
}
F_56 ( V_2 -> V_114 ) ;
V_98 = F_57 ( V_2 -> clock ) ;
if ( V_98 ) {
F_34 ( & V_108 -> V_7 ,
L_8 ) ;
return V_98 ;
}
F_58 ( V_2 -> V_114 ) ;
V_2 -> V_12 = F_59 ( V_2 -> V_88 , V_115 ) / V_14 ;
V_2 -> V_19 = F_60 ( V_2 -> V_88 ) / V_14 ;
F_3 ( V_2 , V_16 - 1 ,
V_117 ) ;
for ( V_46 = 0 ; V_46 < F_17 ( V_118 ) ; V_46 ++ ) {
V_7 = V_2 -> V_47 + V_46 ;
V_7 -> V_20 = V_118 + V_46 ;
V_7 -> V_4 = V_2 -> V_4 + V_7 -> V_20 -> V_3 ;
F_61 ( & V_7 -> V_29 ) ;
F_29 ( V_2 , V_7 ) ;
}
for ( V_87 = 0 ; V_87 <= V_2 -> V_12 * V_14 ; V_87 ++ ) {
V_87 = F_59 ( V_2 -> V_88 , V_87 ) ;
F_62 ( & V_108 -> V_7 , V_87 , 0 ) ;
}
V_43 = F_63 ( V_108 , 0 ) ;
if ( V_43 < 0 ) {
F_34 ( & V_108 -> V_7 , L_9 , V_43 ) ;
return V_43 ;
}
F_64 ( V_108 , V_2 ) ;
V_98 = F_65 ( & V_108 -> V_7 , V_43 , F_16 ,
F_21 , V_119 ,
L_10 , V_2 ) ;
if ( V_98 ) {
F_34 ( & V_108 -> V_7 , L_11 ) ;
return V_98 ;
}
V_120 . V_121 = F_60 ( V_2 -> V_88 ) ;
V_2 -> V_59 = F_66 ( & V_108 -> V_7 ,
& V_120 ,
L_12 ,
NULL ) ;
return 0 ;
}
static int F_67 ( struct V_107 * V_108 )
{
struct V_1 * V_2 = F_68 ( V_108 ) ;
int V_43 = F_63 ( V_108 , 0 ) ;
T_1 V_5 ;
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < F_17 ( V_118 ) ; V_46 ++ ) {
V_5 = F_5 ( & V_2 -> V_47 [ V_46 ] , V_32 ) ;
V_5 &= ~ V_82 ;
F_6 ( & V_2 -> V_47 [ V_46 ] , V_5 , V_32 ) ;
}
F_11 ( V_2 ) ;
F_69 ( & V_108 -> V_7 , V_43 , V_2 ) ;
F_70 ( V_2 -> V_88 , & V_2 -> V_68 ) ;
F_71 ( V_2 -> clock ) ;
return 0 ;
}
static int T_3 F_72 ( void )
{
int V_101 = 0 ;
V_101 = F_73 ( & V_122 ) ;
if ( V_101 ) {
F_74 ( L_13 , V_123 , V_101 ) ;
return V_101 ;
}
V_101 = F_75 ( & V_124 ) ;
if ( V_101 )
F_76 ( & V_122 ) ;
return V_101 ;
}
static void T_4 F_77 ( void )
{
int V_101 = 0 ;
F_78 ( & V_124 ) ;
V_101 = F_76 ( & V_122 ) ;
if ( V_101 )
F_74 ( L_14 , V_123 , V_101 ) ;
}
