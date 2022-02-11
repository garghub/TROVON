static unsigned long F_1 ( unsigned long V_1 , unsigned int V_2 )
{
return V_1 * V_2 / 100 ;
}
static void F_2 ( struct V_3 * V_4 )
{
T_1 V_5 = V_4 -> V_6 ;
T_1 V_7 = V_4 -> V_8 * V_9 ;
F_3 ( V_5 + V_7 , V_4 -> V_10 + V_11 ) ;
V_5 = F_4 ( V_5 , V_7 ) ;
F_3 ( V_5 - V_7 , V_4 -> V_10 + V_12 ) ;
}
static void F_5 ( struct V_13 * V_14 ,
struct V_3 * V_4 )
{
T_1 V_1 = V_14 -> V_15 * V_9 ;
F_3 ( F_1 ( V_1 , V_4 -> V_16 -> V_17 ) ,
V_4 -> V_10 + V_18 ) ;
F_3 ( F_1 ( V_1 , V_4 -> V_16 -> V_19 ) ,
V_4 -> V_10 + V_20 ) ;
}
static void F_6 ( struct V_13 * V_14 )
{
F_7 () ;
F_8 ( V_14 -> V_10 + V_21 ) ;
}
static T_2 F_9 ( int V_22 , void * V_23 )
{
struct V_13 * V_14 = V_23 ;
struct V_3 * V_4 = NULL ;
unsigned long V_24 ;
T_1 V_1 ;
unsigned int V_25 ;
V_1 = F_8 ( V_14 -> V_10 + V_21 ) ;
for ( V_25 = 0 ; V_25 < F_10 ( V_14 -> V_26 ) ; V_25 ++ ) {
if ( V_1 & V_14 -> V_26 [ V_25 ] . V_16 -> V_27 ) {
V_4 = V_14 -> V_26 + V_25 ;
break;
}
}
if ( ! V_4 )
return V_28 ;
F_11 ( & V_14 -> V_29 , V_24 ) ;
V_4 -> V_6 = F_8 ( V_4 -> V_10 + V_30 ) ;
F_2 ( V_4 ) ;
V_1 = F_8 ( V_4 -> V_10 + V_31 ) ;
if ( V_1 & V_32 ) {
V_1 = F_8 ( V_4 -> V_10 + V_33 ) |
V_34 |
V_35 ;
V_4 -> V_36 = F_1 ( V_4 -> V_36 ,
V_4 -> V_16 -> V_37 ) ;
V_4 -> V_36 += V_38 ;
if ( V_4 -> V_36 >= V_14 -> V_39 ) {
V_4 -> V_36 = V_14 -> V_39 ;
V_1 &= ~ V_34 ;
}
F_3 ( V_1 , V_4 -> V_10 + V_33 ) ;
} else if ( V_1 & V_40 ) {
V_1 = F_8 ( V_4 -> V_10 + V_33 ) |
V_34 |
V_35 ;
V_4 -> V_36 = F_1 ( V_4 -> V_36 ,
V_4 -> V_16 -> V_41 ) ;
if ( V_4 -> V_36 < ( V_38 >> 1 ) ) {
V_4 -> V_36 = 0 ;
V_1 &= ~ V_35 ;
}
F_3 ( V_1 , V_4 -> V_10 + V_33 ) ;
}
if ( V_4 -> V_16 -> V_42 ) {
V_1 = F_8 ( V_4 -> V_10 + V_33 ) ;
if ( V_4 -> V_6 >= V_4 -> V_16 -> V_42 )
V_1 |= V_35 ;
else if ( V_4 -> V_36 == 0 )
V_1 &= ~ V_35 ;
F_3 ( V_1 , V_4 -> V_10 + V_33 ) ;
}
F_3 ( V_43 , V_4 -> V_10 + V_31 ) ;
F_6 ( V_14 ) ;
F_12 ( & V_14 -> V_29 , V_24 ) ;
return V_44 ;
}
static unsigned long F_13 ( struct V_13 * V_14 ,
unsigned long V_45 )
{
unsigned int V_25 ;
struct V_46 * V_47 = V_48 ;
for ( V_25 = 0 ; V_25 < F_10 ( V_48 ) ; V_25 ++ , V_47 ++ ) {
if ( V_45 >= V_47 -> V_45 ) {
if ( V_47 -> V_49 >= V_14 -> V_39 )
return V_14 -> V_39 ;
else
return V_47 -> V_49 ;
}
}
return 0 ;
}
static void F_14 ( struct V_13 * V_14 ,
struct V_3 * V_4 )
{
unsigned long V_45 = 0 ;
unsigned long V_50 = 0 ;
unsigned int V_51 ;
unsigned long V_24 ;
if ( V_4 -> V_16 -> V_42 ) {
V_45 = F_15 ( 0 ) ;
V_50 = F_13 ( V_14 , V_45 ) ;
}
F_11 ( & V_14 -> V_29 , V_24 ) ;
V_4 -> V_52 = V_4 -> V_6 / V_9 ;
V_51 = 100 * 100 / V_4 -> V_16 -> V_17 ;
V_4 -> V_52 = F_1 ( V_4 -> V_52 , V_51 ) ;
V_4 -> V_52 += V_4 -> V_36 ;
if ( V_4 -> V_6 >= V_4 -> V_16 -> V_42 )
V_4 -> V_52 = F_4 ( V_4 -> V_52 , V_50 ) ;
F_12 ( & V_14 -> V_29 , V_24 ) ;
}
static T_2 F_16 ( int V_22 , void * V_23 )
{
struct V_13 * V_14 = V_23 ;
F_17 ( & V_14 -> V_53 -> V_29 ) ;
F_18 ( V_14 -> V_53 ) ;
F_19 ( & V_14 -> V_53 -> V_29 ) ;
return V_54 ;
}
static int F_20 ( struct V_55 * V_56 ,
unsigned long V_57 , void * V_58 )
{
struct V_59 * V_23 = V_58 ;
struct V_13 * V_14 = F_21 ( V_56 , struct V_13 ,
V_60 ) ;
unsigned int V_25 ;
unsigned long V_24 ;
F_11 ( & V_14 -> V_29 , V_24 ) ;
switch ( V_57 ) {
case V_61 :
V_14 -> V_15 = V_23 -> V_62 / V_63 ;
for ( V_25 = 0 ; V_25 < F_10 ( V_14 -> V_26 ) ; V_25 ++ )
F_5 ( V_14 , V_14 -> V_26 + V_25 ) ;
F_6 ( V_14 ) ;
break;
case V_64 :
case V_65 :
break;
} ;
F_12 ( & V_14 -> V_29 , V_24 ) ;
return V_66 ;
}
static void F_22 ( struct V_13 * V_14 ,
struct V_3 * V_4 )
{
T_1 V_1 ;
V_4 -> V_8 = V_14 -> V_39 * V_67 / V_63 ;
V_4 -> V_52 = V_14 -> V_15 ;
V_4 -> V_6 = V_14 -> V_15 * V_9 ;
F_3 ( V_4 -> V_6 , V_4 -> V_10 + V_68 ) ;
F_2 ( V_4 ) ;
F_5 ( V_14 , V_4 ) ;
F_3 ( V_69 , V_4 -> V_10 + V_70 ) ;
F_3 ( V_43 , V_4 -> V_10 + V_31 ) ;
V_1 = 0 ;
V_1 |= V_71 |
V_72 |
V_73 ;
V_1 |= ( V_74 - 1 )
<< V_75 ;
V_1 |= ( V_76 - 1 )
<< V_77 ;
V_1 |= ( V_78 - 1 )
<< V_79 ;
V_1 |= V_35 |
V_34 ;
F_3 ( V_1 , V_4 -> V_10 + V_33 ) ;
F_6 ( V_14 ) ;
V_1 = F_8 ( V_4 -> V_10 + V_33 ) ;
V_1 |= V_80 ;
F_3 ( V_1 , V_4 -> V_10 + V_33 ) ;
F_6 ( V_14 ) ;
}
static int F_23 ( struct V_81 * V_4 )
{
struct V_82 * V_83 ;
struct V_13 * V_14 ;
struct V_3 * V_84 ;
unsigned int V_25 ;
T_1 V_1 ;
V_83 = F_21 ( V_4 , struct V_82 , V_4 ) ;
V_14 = F_24 ( V_83 ) ;
for ( V_25 = 0 ; V_25 < F_10 ( V_14 -> V_26 ) ; V_25 ++ ) {
V_84 = & V_14 -> V_26 [ V_25 ] ;
V_1 = F_8 ( V_84 -> V_10 + V_33 ) ;
V_1 &= ~ V_80 ;
F_3 ( V_1 , V_84 -> V_10 + V_33 ) ;
F_3 ( V_43 ,
V_84 -> V_10 + V_31 ) ;
F_6 ( V_14 ) ;
}
return 0 ;
}
static int F_25 ( struct V_81 * V_4 )
{
struct V_82 * V_83 ;
struct V_13 * V_14 ;
struct V_3 * V_84 ;
unsigned int V_25 ;
V_83 = F_21 ( V_4 , struct V_82 , V_4 ) ;
V_14 = F_24 ( V_83 ) ;
for ( V_25 = 0 ; V_25 < F_10 ( V_14 -> V_26 ) ; V_25 ++ ) {
V_84 = & V_14 -> V_26 [ V_25 ] ;
F_22 ( V_14 , V_84 ) ;
}
return 0 ;
}
static int F_26 ( struct V_81 * V_4 , unsigned long * V_85 ,
T_1 V_24 )
{
struct V_82 * V_83 ;
struct V_13 * V_14 ;
struct V_86 * V_87 ;
unsigned long V_88 = * V_85 * V_63 ;
V_83 = F_21 ( V_4 , struct V_82 , V_4 ) ;
V_14 = F_24 ( V_83 ) ;
F_27 () ;
V_87 = F_28 ( V_4 , & V_88 , V_24 ) ;
if ( F_29 ( V_87 ) ) {
F_30 () ;
F_31 ( V_4 , L_1 , * V_85 ) ;
return F_32 ( V_87 ) ;
}
V_88 = F_33 ( V_87 ) ;
F_30 () ;
F_34 ( V_14 -> V_89 , V_88 ) ;
return 0 ;
}
static int F_35 ( struct V_81 * V_4 ,
struct V_90 * V_91 )
{
struct V_82 * V_83 ;
struct V_13 * V_14 ;
struct V_3 * V_84 ;
V_83 = F_21 ( V_4 , struct V_82 , V_4 ) ;
V_14 = F_24 ( V_83 ) ;
V_91 -> V_92 = V_14 -> V_15 ;
V_91 -> V_93 = V_14 ;
V_84 = & V_14 -> V_26 [ V_94 ] ;
V_91 -> V_95 = V_84 -> V_6 ;
V_91 -> V_95 *= 100 / V_96 ;
V_91 -> V_97 = V_9 * V_14 -> V_15 ;
return 0 ;
}
static int F_36 ( struct V_53 * V_53 ,
unsigned long * V_85 )
{
struct V_90 V_91 ;
struct V_13 * V_14 ;
struct V_3 * V_4 ;
unsigned long V_52 = 0 ;
unsigned int V_25 ;
int V_98 ;
V_98 = V_53 -> V_99 -> V_100 ( V_53 -> V_4 . V_101 , & V_91 ) ;
if ( V_98 )
return V_98 ;
V_14 = V_91 . V_93 ;
for ( V_25 = 0 ; V_25 < F_10 ( V_14 -> V_26 ) ; V_25 ++ ) {
V_4 = & V_14 -> V_26 [ V_25 ] ;
F_14 ( V_14 , V_4 ) ;
V_52 = F_4 ( V_52 , V_4 -> V_52 ) ;
}
* V_85 = V_52 ;
return 0 ;
}
static int F_37 ( struct V_53 * V_53 ,
unsigned int V_102 , void * V_23 )
{
return 0 ;
}
static int F_38 ( struct V_82 * V_83 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
struct V_103 * V_104 ;
unsigned long V_39 ;
unsigned int V_25 ;
int V_22 ;
int V_98 ;
V_14 = F_39 ( & V_83 -> V_4 , sizeof( * V_14 ) , V_105 ) ;
if ( ! V_14 )
return - V_106 ;
F_40 ( & V_14 -> V_29 ) ;
V_104 = F_41 ( V_83 , V_107 , 0 ) ;
if ( ! V_104 ) {
F_31 ( & V_83 -> V_4 , L_2 ) ;
return - V_108 ;
}
V_14 -> V_10 = F_42 ( & V_83 -> V_4 , V_104 ) ;
if ( F_29 ( V_14 -> V_10 ) ) {
F_31 ( & V_83 -> V_4 , L_3 ) ;
return F_32 ( V_14 -> V_10 ) ;
}
V_14 -> V_109 = F_43 ( & V_83 -> V_4 , L_4 ) ;
if ( F_29 ( V_14 -> V_109 ) ) {
F_31 ( & V_83 -> V_4 , L_5 ) ;
return F_32 ( V_14 -> V_109 ) ;
}
V_14 -> clock = F_44 ( & V_83 -> V_4 , L_4 ) ;
if ( F_29 ( V_14 -> clock ) ) {
F_31 ( & V_83 -> V_4 , L_6 ) ;
return F_32 ( V_14 -> clock ) ;
}
V_14 -> V_89 = F_44 ( & V_83 -> V_4 , L_7 ) ;
if ( F_29 ( V_14 -> V_89 ) ) {
F_31 ( & V_83 -> V_4 , L_8 ) ;
return F_32 ( V_14 -> V_89 ) ;
}
V_98 = F_45 ( & V_83 -> V_4 ) ;
if ( V_98 ) {
F_31 ( & V_83 -> V_4 , L_9 ) ;
return V_98 ;
}
V_14 -> V_60 . V_110 = F_20 ;
V_98 = F_46 ( V_14 -> V_89 , & V_14 -> V_60 ) ;
if ( V_98 ) {
F_31 ( & V_83 -> V_4 ,
L_10 ) ;
return V_98 ;
}
F_47 ( V_14 -> V_109 ) ;
V_98 = F_48 ( V_14 -> clock ) ;
if ( V_98 ) {
F_49 ( V_14 -> V_109 ) ;
return V_98 ;
}
F_49 ( V_14 -> V_109 ) ;
V_39 = F_50 ( V_14 -> V_89 , V_111 ) ;
V_14 -> V_39 = V_39 / V_63 ;
F_34 ( V_14 -> V_89 , V_39 ) ;
V_14 -> V_15 = F_51 ( V_14 -> V_89 ) / V_63 ;
F_3 ( V_9 - 1 ,
V_14 -> V_10 + V_112 ) ;
for ( V_25 = 0 ; V_25 < F_10 ( V_113 ) ; V_25 ++ ) {
V_4 = V_14 -> V_26 + V_25 ;
V_4 -> V_16 = V_113 + V_25 ;
V_4 -> V_10 = V_14 -> V_10 + V_4 -> V_16 -> V_114 ;
F_22 ( V_14 , V_14 -> V_26 + V_25 ) ;
}
V_98 = F_52 ( & V_115 ) ;
if ( V_98 ) {
F_31 ( & V_83 -> V_4 , L_11 ) ;
return V_98 ;
}
V_116 . V_117 = F_51 ( V_14 -> V_89 ) ;
V_14 -> V_53 = F_53 ( & V_83 -> V_4 ,
& V_116 ,
L_12 ,
NULL ) ;
V_22 = F_54 ( V_83 , 0 ) ;
V_98 = F_55 ( & V_83 -> V_4 , V_22 , F_9 ,
F_16 , V_118 ,
L_13 , V_14 ) ;
if ( V_98 ) {
F_31 ( & V_83 -> V_4 , L_14 ) ;
return V_98 ;
}
F_56 ( V_83 , V_14 ) ;
return 0 ;
}
static int F_57 ( struct V_82 * V_83 )
{
struct V_13 * V_14 = F_24 ( V_83 ) ;
F_58 ( V_14 -> V_89 , & V_14 -> V_60 ) ;
F_59 ( V_14 -> clock ) ;
return 0 ;
}
