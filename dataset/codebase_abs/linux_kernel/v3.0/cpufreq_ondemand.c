static inline T_1 F_1 ( unsigned int V_1 ,
T_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
T_1 V_5 ;
V_4 = F_2 ( F_3 () ) ;
V_5 = F_4 ( F_5 ( V_1 ) . V_6 . V_7 ,
F_5 ( V_1 ) . V_6 . system ) ;
V_5 = F_4 ( V_5 , F_5 ( V_1 ) . V_6 . V_8 ) ;
V_5 = F_4 ( V_5 , F_5 ( V_1 ) . V_6 . V_9 ) ;
V_5 = F_4 ( V_5 , F_5 ( V_1 ) . V_6 . V_10 ) ;
V_5 = F_4 ( V_5 , F_5 ( V_1 ) . V_6 . V_11 ) ;
V_3 = F_6 ( V_4 , V_5 ) ;
if ( V_2 )
* V_2 = ( T_1 ) F_7 ( V_4 ) ;
return ( T_1 ) F_7 ( V_3 ) ;
}
static inline T_1 F_8 ( unsigned int V_1 , T_1 * V_2 )
{
T_2 V_3 = F_9 ( V_1 , V_2 ) ;
if ( V_3 == - 1ULL )
return F_1 ( V_1 , V_2 ) ;
return V_3 ;
}
static inline T_1 F_10 ( unsigned int V_1 , T_1 * V_2 )
{
T_2 V_12 = F_11 ( V_1 , V_2 ) ;
if ( V_12 == - 1ULL )
return 0 ;
return V_12 ;
}
static unsigned int F_12 ( struct V_13 * V_14 ,
unsigned int V_15 ,
unsigned int V_16 )
{
unsigned int V_17 , V_18 , V_19 ;
unsigned int V_20 , V_21 ;
unsigned int V_22 = 0 ;
unsigned int V_23 , V_24 , V_25 ;
struct V_26 * V_27 = & F_13 ( V_28 ,
V_14 -> V_1 ) ;
if ( ! V_27 -> V_29 ) {
V_27 -> V_21 = 0 ;
V_27 -> V_30 = 0 ;
return V_15 ;
}
F_14 ( V_14 , V_27 -> V_29 , V_15 ,
V_16 , & V_22 ) ;
V_17 = V_27 -> V_29 [ V_22 ] . V_31 ;
V_18 = V_17 * V_32 . V_33 / 1000 ;
V_19 = V_17 - V_18 ;
V_22 = 0 ;
F_14 ( V_14 , V_27 -> V_29 , V_19 ,
V_34 , & V_22 ) ;
V_21 = V_27 -> V_29 [ V_22 ] . V_31 ;
V_22 = 0 ;
F_14 ( V_14 , V_27 -> V_29 , V_19 ,
V_35 , & V_22 ) ;
V_20 = V_27 -> V_29 [ V_22 ] . V_31 ;
if ( V_20 == V_21 ) {
V_27 -> V_21 = 0 ;
V_27 -> V_30 = 0 ;
return V_21 ;
}
V_23 = F_15 ( V_32 . V_36 ) ;
V_24 = ( V_19 - V_21 ) * V_23 ;
V_24 += ( ( V_20 - V_21 ) / 2 ) ;
V_24 /= ( V_20 - V_21 ) ;
V_25 = V_23 - V_24 ;
V_27 -> V_21 = V_21 ;
V_27 -> V_30 = V_25 ;
V_27 -> V_37 = V_24 ;
return V_20 ;
}
static void F_16 ( int V_1 )
{
struct V_26 * V_27 = & F_13 ( V_28 , V_1 ) ;
V_27 -> V_29 = F_17 ( V_1 ) ;
V_27 -> V_21 = 0 ;
}
static void F_18 ( void )
{
int V_38 ;
F_19 (i) {
F_16 ( V_38 ) ;
}
}
static T_3 F_20 ( struct V_39 * V_40 ,
struct V_41 * V_42 , char * V_43 )
{
return sprintf ( V_43 , L_1 , V_44 ) ;
}
static T_3 F_21 ( struct V_39 * V_45 , struct V_41 * V_46 ,
const char * V_43 , T_4 V_47 )
{
unsigned int V_48 ;
int V_49 ;
V_49 = sscanf ( V_43 , L_2 , & V_48 ) ;
if ( V_49 != 1 )
return - V_50 ;
V_32 . V_36 = F_22 ( V_48 , V_44 ) ;
return V_47 ;
}
static T_3 F_23 ( struct V_39 * V_45 , struct V_41 * V_46 ,
const char * V_43 , T_4 V_47 )
{
unsigned int V_48 ;
int V_49 ;
V_49 = sscanf ( V_43 , L_2 , & V_48 ) ;
if ( V_49 != 1 )
return - V_50 ;
V_32 . V_51 = ! ! V_48 ;
return V_47 ;
}
static T_3 F_24 ( struct V_39 * V_45 , struct V_41 * V_46 ,
const char * V_43 , T_4 V_47 )
{
unsigned int V_48 ;
int V_49 ;
V_49 = sscanf ( V_43 , L_2 , & V_48 ) ;
if ( V_49 != 1 || V_48 > V_52 ||
V_48 < V_53 ) {
return - V_50 ;
}
V_32 . V_54 = V_48 ;
return V_47 ;
}
static T_3 F_25 ( struct V_39 * V_45 ,
struct V_41 * V_46 , const char * V_43 , T_4 V_47 )
{
unsigned int V_48 , V_55 ;
int V_49 ;
V_49 = sscanf ( V_43 , L_2 , & V_48 ) ;
if ( V_49 != 1 || V_48 > V_56 || V_48 < 1 )
return - V_50 ;
V_32 . V_57 = V_48 ;
F_19 (j) {
struct V_26 * V_27 ;
V_27 = & F_13 ( V_28 , V_55 ) ;
V_27 -> V_58 = 1 ;
}
return V_47 ;
}
static T_3 F_26 ( struct V_39 * V_45 , struct V_41 * V_46 ,
const char * V_43 , T_4 V_47 )
{
unsigned int V_48 ;
int V_49 ;
unsigned int V_55 ;
V_49 = sscanf ( V_43 , L_2 , & V_48 ) ;
if ( V_49 != 1 )
return - V_50 ;
if ( V_48 > 1 )
V_48 = 1 ;
if ( V_48 == V_32 . V_59 ) {
return V_47 ;
}
V_32 . V_59 = V_48 ;
F_19 (j) {
struct V_26 * V_27 ;
V_27 = & F_13 ( V_28 , V_55 ) ;
V_27 -> V_60 = F_8 ( V_55 ,
& V_27 -> V_61 ) ;
if ( V_32 . V_59 )
V_27 -> V_62 = F_5 ( V_55 ) . V_6 . V_11 ;
}
return V_47 ;
}
static T_3 F_27 ( struct V_39 * V_45 , struct V_41 * V_46 ,
const char * V_43 , T_4 V_47 )
{
unsigned int V_48 ;
int V_49 ;
V_49 = sscanf ( V_43 , L_2 , & V_48 ) ;
if ( V_49 != 1 )
return - V_50 ;
if ( V_48 > 1000 )
V_48 = 1000 ;
V_32 . V_33 = V_48 ;
F_18 () ;
return V_47 ;
}
static void F_28 ( struct V_13 * V_63 , unsigned int V_64 )
{
if ( V_32 . V_33 )
V_64 = F_12 ( V_63 , V_64 , V_34 ) ;
else if ( V_63 -> V_65 == V_63 -> F_22 )
return;
F_29 ( V_63 , V_64 , V_32 . V_33 ?
V_35 : V_34 ) ;
}
static void F_30 ( struct V_26 * V_66 )
{
unsigned int V_67 ;
struct V_13 * V_14 ;
unsigned int V_55 ;
V_66 -> V_21 = 0 ;
V_14 = V_66 -> V_68 ;
V_67 = 0 ;
F_31 (j, policy->cpus) {
struct V_26 * V_69 ;
T_1 V_4 , V_70 , V_71 ;
unsigned int V_3 , V_72 , V_12 ;
unsigned int V_73 , V_74 ;
int V_19 ;
V_69 = & F_13 ( V_28 , V_55 ) ;
V_70 = F_8 ( V_55 , & V_4 ) ;
V_71 = F_10 ( V_55 , & V_4 ) ;
V_72 = ( unsigned int ) F_6 ( V_4 ,
V_69 -> V_61 ) ;
V_69 -> V_61 = V_4 ;
V_3 = ( unsigned int ) F_6 ( V_70 ,
V_69 -> V_60 ) ;
V_69 -> V_60 = V_70 ;
V_12 = ( unsigned int ) F_6 ( V_71 ,
V_69 -> V_75 ) ;
V_69 -> V_75 = V_71 ;
if ( V_32 . V_59 ) {
T_1 V_76 ;
unsigned long V_77 ;
V_76 = F_6 ( F_5 ( V_55 ) . V_6 . V_11 ,
V_69 -> V_62 ) ;
V_77 = ( unsigned long )
F_32 ( V_76 ) ;
V_69 -> V_62 = F_5 ( V_55 ) . V_6 . V_11 ;
V_3 += F_7 ( V_77 ) ;
}
if ( V_32 . V_51 && V_3 >= V_12 )
V_3 -= V_12 ;
if ( F_33 ( ! V_72 || V_72 < V_3 ) )
continue;
V_73 = 100 * ( V_72 - V_3 ) / V_72 ;
V_19 = F_34 ( V_14 , V_55 ) ;
if ( V_19 <= 0 )
V_19 = V_14 -> V_65 ;
V_74 = V_73 * V_19 ;
if ( V_74 > V_67 )
V_67 = V_74 ;
}
if ( V_67 > V_32 . V_54 * V_14 -> V_65 ) {
if ( V_14 -> V_65 < V_14 -> F_22 )
V_66 -> V_58 =
V_32 . V_57 ;
F_28 ( V_14 , V_14 -> F_22 ) ;
return;
}
if ( V_14 -> V_65 == V_14 -> V_78 )
return;
if ( V_67 <
( V_32 . V_54 - V_32 . V_79 ) *
V_14 -> V_65 ) {
unsigned int V_15 ;
V_15 = V_67 /
( V_32 . V_54 -
V_32 . V_79 ) ;
V_66 -> V_58 = 1 ;
if ( V_15 < V_14 -> V_78 )
V_15 = V_14 -> V_78 ;
if ( ! V_32 . V_33 ) {
F_29 ( V_14 , V_15 ,
V_35 ) ;
} else {
int V_64 = F_12 ( V_14 , V_15 ,
V_35 ) ;
F_29 ( V_14 , V_64 ,
V_35 ) ;
}
}
}
static void F_35 ( struct V_80 * V_81 )
{
struct V_26 * V_27 =
F_36 ( V_81 , struct V_26 , V_81 . V_81 ) ;
unsigned int V_1 = V_27 -> V_1 ;
int V_82 = V_27 -> V_82 ;
int V_83 ;
F_37 ( & V_27 -> V_84 ) ;
V_27 -> V_82 = V_85 ;
if ( ! V_32 . V_33 ||
V_82 == V_85 ) {
F_30 ( V_27 ) ;
if ( V_27 -> V_21 ) {
V_27 -> V_82 = V_86 ;
V_83 = V_27 -> V_37 ;
} else {
V_83 = F_15 ( V_32 . V_36
* V_27 -> V_58 ) ;
if ( F_38 () > 1 )
V_83 -= V_87 % V_83 ;
}
} else {
F_29 ( V_27 -> V_68 ,
V_27 -> V_21 , V_34 ) ;
V_83 = V_27 -> V_30 ;
}
F_39 ( V_1 , & V_27 -> V_81 , V_83 ) ;
F_40 ( & V_27 -> V_84 ) ;
}
static inline void F_41 ( struct V_26 * V_27 )
{
int V_83 = F_15 ( V_32 . V_36 ) ;
if ( F_38 () > 1 )
V_83 -= V_87 % V_83 ;
V_27 -> V_82 = V_85 ;
F_42 ( & V_27 -> V_81 , F_35 ) ;
F_39 ( V_27 -> V_1 , & V_27 -> V_81 , V_83 ) ;
}
static inline void F_43 ( struct V_26 * V_27 )
{
F_44 ( & V_27 -> V_81 ) ;
}
static int F_45 ( void )
{
#if F_46 ( V_88 )
if ( V_89 . V_90 == V_91 &&
V_89 . V_92 == 6 &&
V_89 . V_93 >= 15 )
return 1 ;
#endif
return 0 ;
}
static int F_47 ( struct V_13 * V_14 ,
unsigned int V_94 )
{
unsigned int V_1 = V_14 -> V_1 ;
struct V_26 * V_66 ;
unsigned int V_55 ;
int V_95 ;
V_66 = & F_13 ( V_28 , V_1 ) ;
switch ( V_94 ) {
case V_96 :
if ( ( ! F_48 ( V_1 ) ) || ( ! V_14 -> V_65 ) )
return - V_50 ;
F_37 ( & V_97 ) ;
V_98 ++ ;
F_31 (j, policy->cpus) {
struct V_26 * V_69 ;
V_69 = & F_13 ( V_28 , V_55 ) ;
V_69 -> V_68 = V_14 ;
V_69 -> V_60 = F_8 ( V_55 ,
& V_69 -> V_61 ) ;
if ( V_32 . V_59 ) {
V_69 -> V_62 =
F_5 ( V_55 ) . V_6 . V_11 ;
}
}
V_66 -> V_1 = V_1 ;
V_66 -> V_58 = 1 ;
F_16 ( V_1 ) ;
if ( V_98 == 1 ) {
unsigned int V_99 ;
V_95 = F_49 ( V_100 ,
& V_101 ) ;
if ( V_95 ) {
F_40 ( & V_97 ) ;
return V_95 ;
}
V_99 = V_14 -> V_102 . V_103 / 1000 ;
if ( V_99 == 0 )
V_99 = 1 ;
V_44 = F_22 ( V_44 ,
V_104 * V_99 ) ;
V_32 . V_36 =
F_22 ( V_44 ,
V_99 * V_105 ) ;
V_32 . V_51 = F_45 () ;
}
F_40 ( & V_97 ) ;
F_50 ( & V_66 -> V_84 ) ;
F_41 ( V_66 ) ;
break;
case V_106 :
F_43 ( V_66 ) ;
F_37 ( & V_97 ) ;
F_51 ( & V_66 -> V_84 ) ;
V_98 -- ;
F_40 ( & V_97 ) ;
if ( ! V_98 )
F_52 ( V_100 ,
& V_101 ) ;
break;
case V_107 :
F_37 ( & V_66 -> V_84 ) ;
if ( V_14 -> F_22 < V_66 -> V_68 -> V_65 )
F_29 ( V_66 -> V_68 ,
V_14 -> F_22 , V_34 ) ;
else if ( V_14 -> V_78 > V_66 -> V_68 -> V_65 )
F_29 ( V_66 -> V_68 ,
V_14 -> V_78 , V_35 ) ;
F_40 ( & V_66 -> V_84 ) ;
break;
}
return 0 ;
}
static int T_5 F_53 ( void )
{
T_1 V_2 ;
T_2 V_3 ;
int V_1 = F_54 () ;
V_3 = F_9 ( V_1 , & V_2 ) ;
F_55 () ;
if ( V_3 != - 1ULL ) {
V_32 . V_54 = V_108 ;
V_32 . V_79 =
V_109 ;
V_44 = V_110 ;
} else {
V_44 =
V_111 * F_7 ( 10 ) ;
}
return F_56 ( & V_112 ) ;
}
static void T_6 F_57 ( void )
{
F_58 ( & V_112 ) ;
}
