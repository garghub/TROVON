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
static T_3 F_19 ( struct V_40 * V_46 , struct V_42 * V_47 ,
const char * V_44 , T_4 V_48 )
{
unsigned int V_49 ;
int V_50 ;
V_50 = sscanf ( V_44 , L_2 , & V_49 ) ;
if ( V_50 != 1 )
return - V_51 ;
V_33 . V_37 = F_20 ( V_49 , V_45 ) ;
return V_48 ;
}
static T_3 F_21 ( struct V_40 * V_46 , struct V_42 * V_47 ,
const char * V_44 , T_4 V_48 )
{
unsigned int V_49 ;
int V_50 ;
V_50 = sscanf ( V_44 , L_2 , & V_49 ) ;
if ( V_50 != 1 )
return - V_51 ;
V_33 . V_52 = ! ! V_49 ;
return V_48 ;
}
static T_3 F_22 ( struct V_40 * V_46 , struct V_42 * V_47 ,
const char * V_44 , T_4 V_48 )
{
unsigned int V_49 ;
int V_50 ;
V_50 = sscanf ( V_44 , L_2 , & V_49 ) ;
if ( V_50 != 1 || V_49 > V_53 ||
V_49 < V_54 ) {
return - V_51 ;
}
V_33 . V_55 = V_49 ;
return V_48 ;
}
static T_3 F_23 ( struct V_40 * V_46 ,
struct V_42 * V_47 , const char * V_44 , T_4 V_48 )
{
unsigned int V_49 , V_56 ;
int V_50 ;
V_50 = sscanf ( V_44 , L_2 , & V_49 ) ;
if ( V_50 != 1 || V_49 > V_57 || V_49 < 1 )
return - V_51 ;
V_33 . V_58 = V_49 ;
F_17 (j) {
struct V_27 * V_28 ;
V_28 = & F_11 ( V_29 , V_56 ) ;
V_28 -> V_59 = 1 ;
}
return V_48 ;
}
static T_3 F_24 ( struct V_40 * V_46 , struct V_42 * V_47 ,
const char * V_44 , T_4 V_48 )
{
unsigned int V_49 ;
int V_50 ;
unsigned int V_56 ;
V_50 = sscanf ( V_44 , L_2 , & V_49 ) ;
if ( V_50 != 1 )
return - V_51 ;
if ( V_49 > 1 )
V_49 = 1 ;
if ( V_49 == V_33 . V_60 ) {
return V_48 ;
}
V_33 . V_60 = V_49 ;
F_17 (j) {
struct V_27 * V_28 ;
V_28 = & F_11 ( V_29 , V_56 ) ;
V_28 -> V_61 = F_6 ( V_56 ,
& V_28 -> V_62 ) ;
if ( V_33 . V_60 )
V_28 -> V_63 = F_4 ( V_56 ) . V_6 [ V_12 ] ;
}
return V_48 ;
}
static T_3 F_25 ( struct V_40 * V_46 , struct V_42 * V_47 ,
const char * V_44 , T_4 V_48 )
{
unsigned int V_49 ;
int V_50 ;
V_50 = sscanf ( V_44 , L_2 , & V_49 ) ;
if ( V_50 != 1 )
return - V_51 ;
if ( V_49 > 1000 )
V_49 = 1000 ;
V_33 . V_34 = V_49 ;
F_16 () ;
return V_48 ;
}
static void F_26 ( struct V_14 * V_64 , unsigned int V_65 )
{
if ( V_33 . V_34 )
V_65 = F_10 ( V_64 , V_65 , V_35 ) ;
else if ( V_64 -> V_66 == V_64 -> F_20 )
return;
F_27 ( V_64 , V_65 , V_33 . V_34 ?
V_36 : V_35 ) ;
}
static void F_28 ( struct V_27 * V_67 )
{
unsigned int V_68 ;
struct V_14 * V_15 ;
unsigned int V_56 ;
V_67 -> V_22 = 0 ;
V_15 = V_67 -> V_69 ;
V_68 = 0 ;
F_29 (j, policy->cpus) {
struct V_27 * V_70 ;
T_2 V_4 , V_71 , V_72 ;
unsigned int V_3 , V_73 , V_13 ;
unsigned int V_74 , V_75 ;
int V_20 ;
V_70 = & F_11 ( V_29 , V_56 ) ;
V_71 = F_6 ( V_56 , & V_4 ) ;
V_72 = F_9 ( V_56 , & V_4 ) ;
V_73 = ( unsigned int )
( V_4 - V_70 -> V_62 ) ;
V_70 -> V_62 = V_4 ;
V_3 = ( unsigned int )
( V_71 - V_70 -> V_61 ) ;
V_70 -> V_61 = V_71 ;
V_13 = ( unsigned int )
( V_72 - V_70 -> V_76 ) ;
V_70 -> V_76 = V_72 ;
if ( V_33 . V_60 ) {
T_1 V_77 ;
unsigned long V_78 ;
V_77 = F_4 ( V_56 ) . V_6 [ V_12 ] -
V_70 -> V_63 ;
V_78 = ( unsigned long )
F_30 ( V_77 ) ;
V_70 -> V_63 = F_4 ( V_56 ) . V_6 [ V_12 ] ;
V_3 += F_5 ( V_78 ) ;
}
if ( V_33 . V_52 && V_3 >= V_13 )
V_3 -= V_13 ;
if ( F_31 ( ! V_73 || V_73 < V_3 ) )
continue;
V_74 = 100 * ( V_73 - V_3 ) / V_73 ;
V_20 = F_32 ( V_15 , V_56 ) ;
if ( V_20 <= 0 )
V_20 = V_15 -> V_66 ;
V_75 = V_74 * V_20 ;
if ( V_75 > V_68 )
V_68 = V_75 ;
}
if ( V_68 > V_33 . V_55 * V_15 -> V_66 ) {
if ( V_15 -> V_66 < V_15 -> F_20 )
V_67 -> V_59 =
V_33 . V_58 ;
F_26 ( V_15 , V_15 -> F_20 ) ;
return;
}
if ( V_15 -> V_66 == V_15 -> V_79 )
return;
if ( V_68 <
( V_33 . V_55 - V_33 . V_80 ) *
V_15 -> V_66 ) {
unsigned int V_16 ;
V_16 = V_68 /
( V_33 . V_55 -
V_33 . V_80 ) ;
V_67 -> V_59 = 1 ;
if ( V_16 < V_15 -> V_79 )
V_16 = V_15 -> V_79 ;
if ( ! V_33 . V_34 ) {
F_27 ( V_15 , V_16 ,
V_36 ) ;
} else {
int V_65 = F_10 ( V_15 , V_16 ,
V_36 ) ;
F_27 ( V_15 , V_65 ,
V_36 ) ;
}
}
}
static void F_33 ( struct V_81 * V_82 )
{
struct V_27 * V_28 =
F_34 ( V_82 , struct V_27 , V_82 . V_82 ) ;
unsigned int V_1 = V_28 -> V_1 ;
int V_83 = V_28 -> V_83 ;
int V_84 ;
F_35 ( & V_28 -> V_85 ) ;
V_28 -> V_83 = V_86 ;
if ( ! V_33 . V_34 ||
V_83 == V_86 ) {
F_28 ( V_28 ) ;
if ( V_28 -> V_22 ) {
V_28 -> V_83 = V_87 ;
V_84 = V_28 -> V_38 ;
} else {
V_84 = F_13 ( V_33 . V_37
* V_28 -> V_59 ) ;
if ( F_36 () > 1 )
V_84 -= V_88 % V_84 ;
}
} else {
F_27 ( V_28 -> V_69 ,
V_28 -> V_22 , V_35 ) ;
V_84 = V_28 -> V_31 ;
}
F_37 ( V_1 , & V_28 -> V_82 , V_84 ) ;
F_38 ( & V_28 -> V_85 ) ;
}
static inline void F_39 ( struct V_27 * V_28 )
{
int V_84 = F_13 ( V_33 . V_37 ) ;
if ( F_36 () > 1 )
V_84 -= V_88 % V_84 ;
V_28 -> V_83 = V_86 ;
F_40 ( & V_28 -> V_82 , F_33 ) ;
F_37 ( V_28 -> V_1 , & V_28 -> V_82 , V_84 ) ;
}
static inline void F_41 ( struct V_27 * V_28 )
{
F_42 ( & V_28 -> V_82 ) ;
}
static int F_43 ( void )
{
#if F_44 ( V_89 )
if ( V_90 . V_91 == V_92 &&
V_90 . V_93 == 6 &&
V_90 . V_94 >= 15 )
return 1 ;
#endif
return 0 ;
}
static int F_45 ( struct V_14 * V_15 ,
unsigned int V_95 )
{
unsigned int V_1 = V_15 -> V_1 ;
struct V_27 * V_67 ;
unsigned int V_56 ;
int V_96 ;
V_67 = & F_11 ( V_29 , V_1 ) ;
switch ( V_95 ) {
case V_97 :
if ( ( ! F_46 ( V_1 ) ) || ( ! V_15 -> V_66 ) )
return - V_51 ;
F_35 ( & V_98 ) ;
V_99 ++ ;
F_29 (j, policy->cpus) {
struct V_27 * V_70 ;
V_70 = & F_11 ( V_29 , V_56 ) ;
V_70 -> V_69 = V_15 ;
V_70 -> V_61 = F_6 ( V_56 ,
& V_70 -> V_62 ) ;
if ( V_33 . V_60 )
V_70 -> V_63 =
F_4 ( V_56 ) . V_6 [ V_12 ] ;
}
V_67 -> V_1 = V_1 ;
V_67 -> V_59 = 1 ;
F_14 ( V_1 ) ;
if ( V_99 == 1 ) {
unsigned int V_100 ;
V_96 = F_47 ( V_101 ,
& V_102 ) ;
if ( V_96 ) {
F_38 ( & V_98 ) ;
return V_96 ;
}
V_100 = V_15 -> V_103 . V_104 / 1000 ;
if ( V_100 == 0 )
V_100 = 1 ;
V_45 = F_20 ( V_45 ,
V_105 * V_100 ) ;
V_33 . V_37 =
F_20 ( V_45 ,
V_100 * V_106 ) ;
V_33 . V_52 = F_43 () ;
}
F_38 ( & V_98 ) ;
F_48 ( & V_67 -> V_85 ) ;
F_39 ( V_67 ) ;
break;
case V_107 :
F_41 ( V_67 ) ;
F_35 ( & V_98 ) ;
F_49 ( & V_67 -> V_85 ) ;
V_99 -- ;
F_38 ( & V_98 ) ;
if ( ! V_99 )
F_50 ( V_101 ,
& V_102 ) ;
break;
case V_108 :
F_35 ( & V_67 -> V_85 ) ;
if ( V_15 -> F_20 < V_67 -> V_69 -> V_66 )
F_27 ( V_67 -> V_69 ,
V_15 -> F_20 , V_35 ) ;
else if ( V_15 -> V_79 > V_67 -> V_69 -> V_66 )
F_27 ( V_67 -> V_69 ,
V_15 -> V_79 , V_36 ) ;
F_38 ( & V_67 -> V_85 ) ;
break;
}
return 0 ;
}
static int T_5 F_51 ( void )
{
T_1 V_3 ;
int V_1 = F_52 () ;
V_3 = F_7 ( V_1 , NULL ) ;
F_53 () ;
if ( V_3 != - 1ULL ) {
V_33 . V_55 = V_109 ;
V_33 . V_80 =
V_110 ;
V_45 = V_111 ;
} else {
V_45 =
V_112 * F_5 ( 10 ) ;
}
return F_54 ( & V_113 ) ;
}
static void T_6 F_55 ( void )
{
F_56 ( & V_113 ) ;
}
