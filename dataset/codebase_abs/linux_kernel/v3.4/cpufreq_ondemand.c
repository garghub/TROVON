static inline T_1 F_1 ( unsigned int V_1 , T_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
T_1 V_5 ;
V_4 = F_2 ( F_3 () ) ;
V_5 = F_4 ( V_1 ) . V_6 [ V_7 ] ;
V_5 += F_4 ( V_1 ) . V_6 [ V_8 ] ;
V_5 += F_4 ( V_1 ) . V_6 [ V_9 ] ;
V_5 += F_4 ( V_1 ) . V_6 [ V_10 ] ;
V_5 += F_4 ( V_1 ) . V_6 [ V_11 ] ;
V_5 += F_4 ( V_1 ) . V_6 [ V_12 ] ;
V_3 = V_4 - V_5 ;
if ( V_2 )
* V_2 = F_5 ( V_4 ) ;
return F_5 ( V_3 ) ;
}
static inline T_2 F_6 ( unsigned int V_1 , T_2 * V_2 )
{
T_1 V_3 = F_7 ( V_1 , NULL ) ;
if ( V_3 == - 1ULL )
return F_1 ( V_1 , V_2 ) ;
else
V_3 += F_8 ( V_1 , V_2 ) ;
return V_3 ;
}
static inline T_2 F_9 ( unsigned int V_1 , T_2 * V_2 )
{
T_1 V_13 = F_8 ( V_1 , V_2 ) ;
if ( V_13 == - 1ULL )
return 0 ;
return V_13 ;
}
static unsigned int F_10 ( struct V_14 * V_15 ,
unsigned int V_16 ,
unsigned int V_17 )
{
unsigned int V_18 , V_19 , V_20 ;
unsigned int V_21 , V_22 ;
unsigned int V_23 = 0 ;
unsigned int V_24 , V_25 , V_26 ;
struct V_27 * V_28 = & F_11 ( V_29 ,
V_15 -> V_1 ) ;
if ( ! V_28 -> V_30 ) {
V_28 -> V_22 = 0 ;
V_28 -> V_31 = 0 ;
return V_16 ;
}
F_12 ( V_15 , V_28 -> V_30 , V_16 ,
V_17 , & V_23 ) ;
V_18 = V_28 -> V_30 [ V_23 ] . V_32 ;
V_19 = V_18 * V_33 . V_34 / 1000 ;
V_20 = V_18 - V_19 ;
V_23 = 0 ;
F_12 ( V_15 , V_28 -> V_30 , V_20 ,
V_35 , & V_23 ) ;
V_22 = V_28 -> V_30 [ V_23 ] . V_32 ;
V_23 = 0 ;
F_12 ( V_15 , V_28 -> V_30 , V_20 ,
V_36 , & V_23 ) ;
V_21 = V_28 -> V_30 [ V_23 ] . V_32 ;
if ( V_21 == V_22 ) {
V_28 -> V_22 = 0 ;
V_28 -> V_31 = 0 ;
return V_22 ;
}
V_24 = F_13 ( V_33 . V_37 ) ;
V_25 = ( V_20 - V_22 ) * V_24 ;
V_25 += ( ( V_21 - V_22 ) / 2 ) ;
V_25 /= ( V_21 - V_22 ) ;
V_26 = V_24 - V_25 ;
V_28 -> V_22 = V_22 ;
V_28 -> V_31 = V_26 ;
V_28 -> V_38 = V_25 ;
return V_21 ;
}
static void F_14 ( int V_1 )
{
struct V_27 * V_28 = & F_11 ( V_29 , V_1 ) ;
V_28 -> V_30 = F_15 ( V_1 ) ;
V_28 -> V_22 = 0 ;
}
static void F_16 ( void )
{
int V_39 ;
F_17 (i) {
F_14 ( V_39 ) ;
}
}
static T_3 F_18 ( struct V_40 * V_41 ,
struct V_42 * V_43 , char * V_44 )
{
return sprintf ( V_44 , L_1 , V_45 ) ;
}
static void F_19 ( unsigned int V_46 )
{
int V_1 ;
V_33 . V_37 = V_46
= F_20 ( V_46 , V_45 ) ;
F_17 (cpu) {
struct V_14 * V_15 ;
struct V_27 * V_28 ;
unsigned long V_47 , V_48 ;
V_15 = F_21 ( V_1 ) ;
if ( ! V_15 )
continue;
V_28 = & F_11 ( V_29 , V_15 -> V_1 ) ;
F_22 ( V_15 ) ;
F_23 ( & V_28 -> V_49 ) ;
if ( ! F_24 ( & V_28 -> V_50 ) ) {
F_25 ( & V_28 -> V_49 ) ;
continue;
}
V_47 = V_51 + F_13 ( V_46 ) ;
V_48 = V_28 -> V_50 . V_52 . V_53 ;
if ( F_26 ( V_47 , V_48 ) ) {
F_25 ( & V_28 -> V_49 ) ;
F_27 ( & V_28 -> V_50 ) ;
F_23 ( & V_28 -> V_49 ) ;
F_28 ( V_28 -> V_1 , & V_28 -> V_50 ,
F_13 ( V_46 ) ) ;
}
F_25 ( & V_28 -> V_49 ) ;
}
}
static T_3 F_29 ( struct V_40 * V_54 , struct V_42 * V_55 ,
const char * V_44 , T_4 V_56 )
{
unsigned int V_57 ;
int V_58 ;
V_58 = sscanf ( V_44 , L_2 , & V_57 ) ;
if ( V_58 != 1 )
return - V_59 ;
F_19 ( V_57 ) ;
return V_56 ;
}
static T_3 F_30 ( struct V_40 * V_54 , struct V_42 * V_55 ,
const char * V_44 , T_4 V_56 )
{
unsigned int V_57 ;
int V_58 ;
V_58 = sscanf ( V_44 , L_2 , & V_57 ) ;
if ( V_58 != 1 )
return - V_59 ;
V_33 . V_60 = ! ! V_57 ;
return V_56 ;
}
static T_3 F_31 ( struct V_40 * V_54 , struct V_42 * V_55 ,
const char * V_44 , T_4 V_56 )
{
unsigned int V_57 ;
int V_58 ;
V_58 = sscanf ( V_44 , L_2 , & V_57 ) ;
if ( V_58 != 1 || V_57 > V_61 ||
V_57 < V_62 ) {
return - V_59 ;
}
V_33 . V_63 = V_57 ;
return V_56 ;
}
static T_3 F_32 ( struct V_40 * V_54 ,
struct V_42 * V_55 , const char * V_44 , T_4 V_56 )
{
unsigned int V_57 , V_64 ;
int V_58 ;
V_58 = sscanf ( V_44 , L_2 , & V_57 ) ;
if ( V_58 != 1 || V_57 > V_65 || V_57 < 1 )
return - V_59 ;
V_33 . V_66 = V_57 ;
F_17 (j) {
struct V_27 * V_28 ;
V_28 = & F_11 ( V_29 , V_64 ) ;
V_28 -> V_67 = 1 ;
}
return V_56 ;
}
static T_3 F_33 ( struct V_40 * V_54 , struct V_42 * V_55 ,
const char * V_44 , T_4 V_56 )
{
unsigned int V_57 ;
int V_58 ;
unsigned int V_64 ;
V_58 = sscanf ( V_44 , L_2 , & V_57 ) ;
if ( V_58 != 1 )
return - V_59 ;
if ( V_57 > 1 )
V_57 = 1 ;
if ( V_57 == V_33 . V_68 ) {
return V_56 ;
}
V_33 . V_68 = V_57 ;
F_17 (j) {
struct V_27 * V_28 ;
V_28 = & F_11 ( V_29 , V_64 ) ;
V_28 -> V_69 = F_6 ( V_64 ,
& V_28 -> V_70 ) ;
if ( V_33 . V_68 )
V_28 -> V_71 = F_4 ( V_64 ) . V_6 [ V_12 ] ;
}
return V_56 ;
}
static T_3 F_34 ( struct V_40 * V_54 , struct V_42 * V_55 ,
const char * V_44 , T_4 V_56 )
{
unsigned int V_57 ;
int V_58 ;
V_58 = sscanf ( V_44 , L_2 , & V_57 ) ;
if ( V_58 != 1 )
return - V_59 ;
if ( V_57 > 1000 )
V_57 = 1000 ;
V_33 . V_34 = V_57 ;
F_16 () ;
return V_56 ;
}
static void F_35 ( struct V_14 * V_72 , unsigned int V_73 )
{
if ( V_33 . V_34 )
V_73 = F_10 ( V_72 , V_73 , V_35 ) ;
else if ( V_72 -> V_74 == V_72 -> F_20 )
return;
F_36 ( V_72 , V_73 , V_33 . V_34 ?
V_36 : V_35 ) ;
}
static void F_37 ( struct V_27 * V_75 )
{
unsigned int V_76 ;
struct V_14 * V_15 ;
unsigned int V_64 ;
V_75 -> V_22 = 0 ;
V_15 = V_75 -> V_77 ;
V_76 = 0 ;
F_38 (j, policy->cpus) {
struct V_27 * V_78 ;
T_2 V_4 , V_79 , V_80 ;
unsigned int V_3 , V_81 , V_13 ;
unsigned int V_82 , V_83 ;
int V_20 ;
V_78 = & F_11 ( V_29 , V_64 ) ;
V_79 = F_6 ( V_64 , & V_4 ) ;
V_80 = F_9 ( V_64 , & V_4 ) ;
V_81 = ( unsigned int )
( V_4 - V_78 -> V_70 ) ;
V_78 -> V_70 = V_4 ;
V_3 = ( unsigned int )
( V_79 - V_78 -> V_69 ) ;
V_78 -> V_69 = V_79 ;
V_13 = ( unsigned int )
( V_80 - V_78 -> V_84 ) ;
V_78 -> V_84 = V_80 ;
if ( V_33 . V_68 ) {
T_1 V_85 ;
unsigned long V_86 ;
V_85 = F_4 ( V_64 ) . V_6 [ V_12 ] -
V_78 -> V_71 ;
V_86 = ( unsigned long )
F_39 ( V_85 ) ;
V_78 -> V_71 = F_4 ( V_64 ) . V_6 [ V_12 ] ;
V_3 += F_5 ( V_86 ) ;
}
if ( V_33 . V_60 && V_3 >= V_13 )
V_3 -= V_13 ;
if ( F_40 ( ! V_81 || V_81 < V_3 ) )
continue;
V_82 = 100 * ( V_81 - V_3 ) / V_81 ;
V_20 = F_41 ( V_15 , V_64 ) ;
if ( V_20 <= 0 )
V_20 = V_15 -> V_74 ;
V_83 = V_82 * V_20 ;
if ( V_83 > V_76 )
V_76 = V_83 ;
}
if ( V_76 > V_33 . V_63 * V_15 -> V_74 ) {
if ( V_15 -> V_74 < V_15 -> F_20 )
V_75 -> V_67 =
V_33 . V_66 ;
F_35 ( V_15 , V_15 -> F_20 ) ;
return;
}
if ( V_15 -> V_74 == V_15 -> V_87 )
return;
if ( V_76 <
( V_33 . V_63 - V_33 . V_88 ) *
V_15 -> V_74 ) {
unsigned int V_16 ;
V_16 = V_76 /
( V_33 . V_63 -
V_33 . V_88 ) ;
V_75 -> V_67 = 1 ;
if ( V_16 < V_15 -> V_87 )
V_16 = V_15 -> V_87 ;
if ( ! V_33 . V_34 ) {
F_36 ( V_15 , V_16 ,
V_36 ) ;
} else {
int V_73 = F_10 ( V_15 , V_16 ,
V_36 ) ;
F_36 ( V_15 , V_73 ,
V_36 ) ;
}
}
}
static void F_42 ( struct V_89 * V_50 )
{
struct V_27 * V_28 =
F_43 ( V_50 , struct V_27 , V_50 . V_50 ) ;
unsigned int V_1 = V_28 -> V_1 ;
int V_90 = V_28 -> V_90 ;
int V_91 ;
F_23 ( & V_28 -> V_49 ) ;
V_28 -> V_90 = V_92 ;
if ( ! V_33 . V_34 ||
V_90 == V_92 ) {
F_37 ( V_28 ) ;
if ( V_28 -> V_22 ) {
V_28 -> V_90 = V_93 ;
V_91 = V_28 -> V_38 ;
} else {
V_91 = F_13 ( V_33 . V_37
* V_28 -> V_67 ) ;
if ( F_44 () > 1 )
V_91 -= V_51 % V_91 ;
}
} else {
F_36 ( V_28 -> V_77 ,
V_28 -> V_22 , V_35 ) ;
V_91 = V_28 -> V_31 ;
}
F_28 ( V_1 , & V_28 -> V_50 , V_91 ) ;
F_25 ( & V_28 -> V_49 ) ;
}
static inline void F_45 ( struct V_27 * V_28 )
{
int V_91 = F_13 ( V_33 . V_37 ) ;
if ( F_44 () > 1 )
V_91 -= V_51 % V_91 ;
V_28 -> V_90 = V_92 ;
F_46 ( & V_28 -> V_50 , F_42 ) ;
F_28 ( V_28 -> V_1 , & V_28 -> V_50 , V_91 ) ;
}
static inline void F_47 ( struct V_27 * V_28 )
{
F_27 ( & V_28 -> V_50 ) ;
}
static int F_48 ( void )
{
#if F_49 ( V_94 )
if ( V_95 . V_96 == V_97 &&
V_95 . V_98 == 6 &&
V_95 . V_99 >= 15 )
return 1 ;
#endif
return 0 ;
}
static int F_50 ( struct V_14 * V_15 ,
unsigned int V_100 )
{
unsigned int V_1 = V_15 -> V_1 ;
struct V_27 * V_75 ;
unsigned int V_64 ;
int V_101 ;
V_75 = & F_11 ( V_29 , V_1 ) ;
switch ( V_100 ) {
case V_102 :
if ( ( ! F_51 ( V_1 ) ) || ( ! V_15 -> V_74 ) )
return - V_59 ;
F_23 ( & V_103 ) ;
V_104 ++ ;
F_38 (j, policy->cpus) {
struct V_27 * V_78 ;
V_78 = & F_11 ( V_29 , V_64 ) ;
V_78 -> V_77 = V_15 ;
V_78 -> V_69 = F_6 ( V_64 ,
& V_78 -> V_70 ) ;
if ( V_33 . V_68 )
V_78 -> V_71 =
F_4 ( V_64 ) . V_6 [ V_12 ] ;
}
V_75 -> V_1 = V_1 ;
V_75 -> V_67 = 1 ;
F_14 ( V_1 ) ;
if ( V_104 == 1 ) {
unsigned int V_105 ;
V_101 = F_52 ( V_106 ,
& V_107 ) ;
if ( V_101 ) {
F_25 ( & V_103 ) ;
return V_101 ;
}
V_105 = V_15 -> V_108 . V_109 / 1000 ;
if ( V_105 == 0 )
V_105 = 1 ;
V_45 = F_20 ( V_45 ,
V_110 * V_105 ) ;
V_33 . V_37 =
F_20 ( V_45 ,
V_105 * V_111 ) ;
V_33 . V_60 = F_48 () ;
}
F_25 ( & V_103 ) ;
F_53 ( & V_75 -> V_49 ) ;
F_45 ( V_75 ) ;
break;
case V_112 :
F_47 ( V_75 ) ;
F_23 ( & V_103 ) ;
F_54 ( & V_75 -> V_49 ) ;
V_104 -- ;
F_25 ( & V_103 ) ;
if ( ! V_104 )
F_55 ( V_106 ,
& V_107 ) ;
break;
case V_113 :
F_23 ( & V_75 -> V_49 ) ;
if ( V_15 -> F_20 < V_75 -> V_77 -> V_74 )
F_36 ( V_75 -> V_77 ,
V_15 -> F_20 , V_35 ) ;
else if ( V_15 -> V_87 > V_75 -> V_77 -> V_74 )
F_36 ( V_75 -> V_77 ,
V_15 -> V_87 , V_36 ) ;
F_25 ( & V_75 -> V_49 ) ;
break;
}
return 0 ;
}
static int T_5 F_56 ( void )
{
T_1 V_3 ;
int V_1 = F_57 () ;
V_3 = F_7 ( V_1 , NULL ) ;
F_58 () ;
if ( V_3 != - 1ULL ) {
V_33 . V_63 = V_114 ;
V_33 . V_88 =
V_115 ;
V_45 = V_116 ;
} else {
V_45 =
V_117 * F_5 ( 10 ) ;
}
return F_59 ( & V_118 ) ;
}
static void T_6 F_60 ( void )
{
F_61 ( & V_118 ) ;
}
