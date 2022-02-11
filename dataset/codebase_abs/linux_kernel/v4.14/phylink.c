static inline void F_1 ( unsigned long * V_1 )
{
F_2 ( V_1 , V_2 ) ;
}
static inline void F_3 ( unsigned long * V_1 , const unsigned long * V_3 )
{
F_4 ( V_1 , V_3 , V_2 ) ;
}
static inline void F_5 ( unsigned long * V_1 , const unsigned long * V_4 ,
const unsigned long * V_5 )
{
F_6 ( V_1 , V_4 , V_5 , V_2 ) ;
}
static inline void F_7 ( unsigned long * V_1 , const unsigned long * V_4 ,
const unsigned long * V_5 )
{
F_8 ( V_1 , V_4 , V_5 , V_2 ) ;
}
static inline bool F_9 ( const unsigned long * V_3 )
{
return F_10 ( V_3 , V_2 ) ;
}
void F_11 ( unsigned long * V_6 )
{
F_12 ( V_6 , V_7 ) ;
F_12 ( V_6 , V_8 ) ;
F_12 ( V_6 , V_9 ) ;
F_12 ( V_6 , V_10 ) ;
F_12 ( V_6 , V_11 ) ;
F_12 ( V_6 , V_12 ) ;
}
static int F_13 ( const unsigned long * V_13 )
{
F_14 ( V_14 ) = { 0 , } ;
F_11 ( V_14 ) ;
F_12 ( V_14 , V_15 ) ;
F_12 ( V_14 , V_16 ) ;
F_12 ( V_14 , V_17 ) ;
F_15 ( V_14 , V_13 , V_14 , V_2 ) ;
return F_9 ( V_14 ) ;
}
static const char * F_16 ( unsigned int V_18 )
{
static const char * V_19 [] = {
[ V_20 ] = L_1 ,
[ V_21 ] = L_2 ,
[ V_22 ] = L_3 ,
[ V_23 ] = L_4 ,
} ;
return V_18 < F_17 ( V_19 ) ? V_19 [ V_18 ] : L_5 ;
}
static int F_18 ( struct V_24 * V_25 , unsigned long * V_26 ,
struct V_27 * V_28 )
{
V_25 -> V_29 -> V_30 ( V_25 -> V_31 , V_26 , V_28 ) ;
return F_13 ( V_26 ) ? - V_32 : 0 ;
}
static int F_19 ( struct V_24 * V_25 , struct V_33 * V_34 )
{
struct V_33 * V_35 ;
const struct V_36 * V_37 ;
struct V_38 * V_39 ;
const T_1 * V_40 ;
T_2 V_41 ;
int V_42 , V_43 ;
V_35 = F_20 ( V_34 , L_6 ) ;
if ( V_35 ) {
V_42 = F_21 ( V_35 , L_7 , & V_41 ) ;
V_25 -> V_44 . V_41 = V_41 ;
V_25 -> V_44 . V_45 = V_46 ;
if ( F_22 ( V_35 , L_8 ) )
V_25 -> V_44 . V_45 = V_47 ;
if ( F_22 ( V_35 , L_9 ) )
V_25 -> V_44 . V_48 |= V_49 ;
if ( F_22 ( V_35 , L_10 ) )
V_25 -> V_44 . V_48 |= V_50 ;
if ( V_42 == 0 ) {
V_39 = F_23 ( & V_35 -> V_51 ,
L_11 , 0 ,
V_52 , L_12 ) ;
if ( ! F_24 ( V_39 ) )
V_25 -> V_53 = V_39 ;
else if ( V_39 == F_25 ( - V_54 ) )
V_42 = - V_54 ;
}
F_26 ( V_35 ) ;
if ( V_42 )
return V_42 ;
} else {
V_40 = F_27 ( V_34 , L_6 , & V_43 ) ;
if ( ! V_40 ) {
F_28 ( V_25 -> V_31 , L_13 ) ;
return - V_32 ;
}
if ( V_43 == 5 * sizeof( * V_40 ) ) {
V_25 -> V_44 . V_45 = F_29 ( V_40 [ 1 ] ) ?
V_47 : V_46 ;
V_25 -> V_44 . V_41 = F_29 ( V_40 [ 2 ] ) ;
if ( F_29 ( V_40 [ 3 ] ) )
V_25 -> V_44 . V_48 |= V_49 ;
if ( F_29 ( V_40 [ 4 ] ) )
V_25 -> V_44 . V_48 |= V_50 ;
}
}
if ( V_25 -> V_44 . V_41 > V_55 &&
V_25 -> V_44 . V_45 != V_47 )
F_30 ( V_25 -> V_31 , L_14 ,
V_25 -> V_44 . V_41 ) ;
F_31 ( V_25 -> V_26 , V_2 ) ;
F_3 ( V_25 -> V_44 . V_56 , V_25 -> V_26 ) ;
F_18 ( V_25 , V_25 -> V_26 , & V_25 -> V_44 ) ;
V_37 = F_32 ( V_25 -> V_44 . V_41 , V_25 -> V_44 . V_45 ,
V_25 -> V_26 ,
V_2 , true ) ;
F_1 ( V_25 -> V_26 ) ;
F_12 ( V_25 -> V_26 , V_9 ) ;
if ( V_37 ) {
F_33 ( V_37 -> V_57 , V_25 -> V_26 ) ;
} else {
F_30 ( V_25 -> V_31 , L_15 ,
V_25 -> V_44 . V_45 == V_47 ? L_16 : L_17 ,
V_25 -> V_44 . V_41 ) ;
}
F_5 ( V_25 -> V_44 . V_56 , V_25 -> V_44 . V_56 ,
V_25 -> V_26 ) ;
V_25 -> V_44 . V_58 = 1 ;
V_25 -> V_44 . V_59 = 1 ;
return 0 ;
}
static int F_34 ( struct V_24 * V_25 , struct V_33 * V_34 )
{
struct V_33 * V_60 ;
const char * V_61 ;
V_60 = F_20 ( V_34 , L_6 ) ;
if ( V_60 || F_35 ( V_34 , L_6 , NULL ) )
V_25 -> V_62 = V_21 ;
F_26 ( V_60 ) ;
if ( F_36 ( V_34 , L_18 , & V_61 ) == 0 &&
strcmp ( V_61 , L_19 ) == 0 ) {
if ( V_25 -> V_62 == V_21 ) {
F_28 ( V_25 -> V_31 ,
L_20 ) ;
return - V_32 ;
}
F_1 ( V_25 -> V_26 ) ;
F_12 ( V_25 -> V_26 , V_9 ) ;
F_12 ( V_25 -> V_26 , V_15 ) ;
F_12 ( V_25 -> V_26 , V_17 ) ;
F_12 ( V_25 -> V_26 , V_16 ) ;
V_25 -> V_44 . V_63 = true ;
switch ( V_25 -> V_44 . V_64 ) {
case V_65 :
F_12 ( V_25 -> V_26 , 10baseT_Half ) ;
F_12 ( V_25 -> V_26 , 10baseT_Full ) ;
F_12 ( V_25 -> V_26 , 100baseT_Half ) ;
F_12 ( V_25 -> V_26 , 100baseT_Full ) ;
F_12 ( V_25 -> V_26 , 1000baseT_Half ) ;
F_12 ( V_25 -> V_26 , 1000baseT_Full ) ;
V_25 -> V_62 = V_22 ;
break;
case V_66 :
F_12 ( V_25 -> V_26 , 1000baseX_Full ) ;
V_25 -> V_62 = V_23 ;
break;
case V_67 :
F_12 ( V_25 -> V_26 , 2500baseX_Full ) ;
V_25 -> V_62 = V_23 ;
break;
case V_68 :
F_12 ( V_25 -> V_26 , 10baseT_Half ) ;
F_12 ( V_25 -> V_26 , 10baseT_Full ) ;
F_12 ( V_25 -> V_26 , 100baseT_Half ) ;
F_12 ( V_25 -> V_26 , 100baseT_Full ) ;
F_12 ( V_25 -> V_26 , 1000baseT_Half ) ;
F_12 ( V_25 -> V_26 , 1000baseT_Full ) ;
F_12 ( V_25 -> V_26 , 1000baseX_Full ) ;
F_12 ( V_25 -> V_26 , 10000baseKR_Full ) ;
F_12 ( V_25 -> V_26 , 10000baseCR_Full ) ;
F_12 ( V_25 -> V_26 , 10000baseSR_Full ) ;
F_12 ( V_25 -> V_26 , 10000baseLR_Full ) ;
F_12 ( V_25 -> V_26 , 10000baseLRM_Full ) ;
F_12 ( V_25 -> V_26 , 10000baseER_Full ) ;
V_25 -> V_62 = V_22 ;
break;
default:
F_28 ( V_25 -> V_31 ,
L_21 ,
F_37 ( V_25 -> V_44 . V_64 ) ) ;
return - V_32 ;
}
F_3 ( V_25 -> V_44 . V_56 , V_25 -> V_26 ) ;
if ( F_18 ( V_25 , V_25 -> V_26 , & V_25 -> V_44 ) ) {
F_28 ( V_25 -> V_31 ,
L_22 ) ;
return - V_32 ;
}
}
return 0 ;
}
static void F_38 ( struct V_24 * V_25 ,
const struct V_27 * V_28 )
{
F_39 ( V_25 -> V_31 ,
L_23 ,
V_69 , F_16 ( V_25 -> V_62 ) ,
F_37 ( V_28 -> V_64 ) ,
F_40 ( V_28 -> V_41 ) ,
F_41 ( V_28 -> V_45 ) ,
V_2 , V_28 -> V_56 ,
V_28 -> V_48 , V_28 -> V_58 , V_28 -> V_63 ) ;
V_25 -> V_29 -> V_70 ( V_25 -> V_31 , V_25 -> V_62 , V_28 ) ;
}
static void F_42 ( struct V_24 * V_25 )
{
if ( V_25 -> V_44 . V_63 &&
( V_25 -> V_44 . V_64 == V_66 ||
V_25 -> V_44 . V_64 == V_67 ) )
V_25 -> V_29 -> V_71 ( V_25 -> V_31 ) ;
}
static int F_43 ( struct V_24 * V_25 , struct V_27 * V_28 )
{
struct V_72 * V_73 = V_25 -> V_31 ;
F_3 ( V_28 -> V_56 , V_25 -> V_44 . V_56 ) ;
F_1 ( V_28 -> V_74 ) ;
V_28 -> V_64 = V_25 -> V_44 . V_64 ;
V_28 -> V_63 = V_25 -> V_44 . V_63 ;
V_28 -> V_58 = 1 ;
return V_25 -> V_29 -> V_75 ( V_73 , V_28 ) ;
}
static void F_44 ( struct V_24 * V_25 , struct V_27 * V_28 )
{
* V_28 = V_25 -> V_44 ;
if ( V_25 -> V_53 )
V_28 -> V_58 = ! ! F_45 ( V_25 -> V_53 ) ;
}
static void F_46 ( struct V_24 * V_25 ,
struct V_27 * V_28 )
{
int V_76 = 0 ;
if ( V_25 -> V_44 . V_48 & V_77 ) {
int V_48 = 0 ;
if ( F_47 ( V_25 -> V_44 . V_56 , V_16 ) )
V_48 |= V_49 ;
if ( F_47 ( V_25 -> V_44 . V_56 , V_17 ) )
V_48 |= V_50 ;
V_48 &= V_28 -> V_48 ;
if ( V_48 & V_49 )
V_76 = V_78 | V_79 ;
else if ( V_48 & V_50 )
V_76 = V_28 -> V_48 & V_49 ?
V_79 : V_78 ;
} else {
V_76 = V_25 -> V_44 . V_48 & V_80 ;
}
V_28 -> V_48 &= ~ V_80 ;
V_28 -> V_48 |= V_76 ;
}
static const char * F_48 ( int V_48 )
{
switch ( V_48 & V_80 ) {
case V_78 | V_79 :
return L_24 ;
case V_78 :
return L_25 ;
case V_79 :
return L_26 ;
default:
return L_27 ;
}
}
static void F_49 ( struct V_81 * V_82 )
{
struct V_24 * V_25 = F_50 ( V_82 , struct V_24 , V_83 ) ;
struct V_27 V_84 ;
struct V_72 * V_73 = V_25 -> V_31 ;
F_51 ( & V_25 -> V_85 ) ;
if ( V_25 -> V_86 ) {
V_25 -> V_87 = false ;
V_84 . V_58 = false ;
} else if ( V_25 -> V_87 ) {
V_84 . V_58 = false ;
} else {
switch ( V_25 -> V_62 ) {
case V_20 :
V_84 = V_25 -> V_88 ;
F_46 ( V_25 , & V_84 ) ;
F_38 ( V_25 , & V_84 ) ;
break;
case V_21 :
F_44 ( V_25 , & V_84 ) ;
F_38 ( V_25 , & V_84 ) ;
break;
case V_22 :
F_43 ( V_25 , & V_84 ) ;
if ( V_25 -> V_89 ) {
bool V_90 = false ;
V_84 . V_58 = V_84 . V_58 &&
V_25 -> V_88 . V_58 ;
if ( V_25 -> V_88 . V_64 !=
V_84 . V_64 ) {
V_84 . V_64 = V_25 -> V_88 . V_64 ;
V_90 = true ;
}
if ( V_25 -> V_88 . V_58 || V_90 ) {
V_84 . V_48 |= V_25 -> V_88 . V_48 ;
F_46 ( V_25 , & V_84 ) ;
F_38 ( V_25 , & V_84 ) ;
}
}
break;
case V_23 :
F_43 ( V_25 , & V_84 ) ;
break;
}
}
if ( V_84 . V_58 != F_52 ( V_73 ) ) {
if ( ! V_84 . V_58 ) {
F_53 ( V_73 ) ;
V_25 -> V_29 -> V_91 ( V_73 , V_25 -> V_62 ) ;
F_54 ( V_73 , L_28 ) ;
} else {
V_25 -> V_29 -> V_92 ( V_73 , V_25 -> V_62 ,
V_25 -> V_89 ) ;
F_55 ( V_73 ) ;
F_54 ( V_73 ,
L_29 ,
F_40 ( V_84 . V_41 ) ,
F_41 ( V_84 . V_45 ) ,
F_48 ( V_84 . V_48 ) ) ;
}
}
if ( ! V_84 . V_58 && V_25 -> V_87 ) {
V_25 -> V_87 = false ;
F_56 ( V_93 , & V_25 -> V_83 ) ;
}
F_57 ( & V_25 -> V_85 ) ;
}
static void F_58 ( struct V_24 * V_25 )
{
if ( ! V_25 -> V_86 )
F_56 ( V_93 , & V_25 -> V_83 ) ;
}
static int F_59 ( struct V_24 * V_25 , struct V_33 * V_34 )
{
struct V_33 * V_94 ;
V_94 = F_60 ( V_34 , L_30 , 0 ) ;
if ( ! V_94 )
return 0 ;
V_25 -> V_95 = F_61 ( V_94 , V_25 -> V_31 , V_25 ,
& V_96 ) ;
if ( ! V_25 -> V_95 )
return - V_97 ;
return 0 ;
}
struct V_24 * F_62 ( struct V_72 * V_73 , struct V_33 * V_34 ,
T_3 V_98 , const struct V_99 * V_29 )
{
struct V_24 * V_25 ;
int V_42 ;
V_25 = F_63 ( sizeof( * V_25 ) , V_100 ) ;
if ( ! V_25 )
return F_25 ( - V_97 ) ;
F_64 ( & V_25 -> V_85 ) ;
F_65 ( & V_25 -> V_83 , F_49 ) ;
V_25 -> V_31 = V_73 ;
V_25 -> V_88 . V_64 = V_98 ;
V_25 -> V_101 = V_98 ;
V_25 -> V_102 = V_103 ;
V_25 -> V_44 . V_64 = V_98 ;
V_25 -> V_44 . V_48 = V_77 ;
V_25 -> V_44 . V_41 = V_104 ;
V_25 -> V_44 . V_45 = V_105 ;
V_25 -> V_29 = V_29 ;
F_33 ( V_106 , & V_25 -> V_86 ) ;
F_31 ( V_25 -> V_26 , V_2 ) ;
F_3 ( V_25 -> V_44 . V_56 , V_25 -> V_26 ) ;
F_18 ( V_25 , V_25 -> V_26 , & V_25 -> V_44 ) ;
V_42 = F_34 ( V_25 , V_34 ) ;
if ( V_42 < 0 ) {
F_66 ( V_25 ) ;
return F_25 ( V_42 ) ;
}
if ( V_25 -> V_62 == V_21 ) {
V_42 = F_19 ( V_25 , V_34 ) ;
if ( V_42 < 0 ) {
F_66 ( V_25 ) ;
return F_25 ( V_42 ) ;
}
}
V_42 = F_59 ( V_25 , V_34 ) ;
if ( V_42 < 0 ) {
F_66 ( V_25 ) ;
return F_25 ( V_42 ) ;
}
return V_25 ;
}
void F_67 ( struct V_24 * V_25 )
{
if ( V_25 -> V_95 )
F_68 ( V_25 -> V_95 ) ;
F_69 ( & V_25 -> V_83 ) ;
F_66 ( V_25 ) ;
}
void F_70 ( struct V_107 * V_89 , bool V_108 , bool V_109 )
{
struct V_24 * V_25 = V_89 -> V_24 ;
F_51 ( & V_25 -> V_85 ) ;
V_25 -> V_88 . V_41 = V_89 -> V_41 ;
V_25 -> V_88 . V_45 = V_89 -> V_45 ;
V_25 -> V_88 . V_48 = V_110 ;
if ( V_89 -> V_48 )
V_25 -> V_88 . V_48 |= V_49 ;
if ( V_89 -> V_111 )
V_25 -> V_88 . V_48 |= V_50 ;
V_25 -> V_88 . V_64 = V_89 -> V_64 ;
V_25 -> V_88 . V_58 = V_108 ;
F_57 ( & V_25 -> V_85 ) ;
F_58 ( V_25 ) ;
F_39 ( V_25 -> V_31 , L_31 , V_108 ? L_32 : L_33 ,
F_37 ( V_89 -> V_64 ) ,
F_40 ( V_89 -> V_41 ) ,
F_41 ( V_89 -> V_45 ) ) ;
}
static int F_71 ( struct V_24 * V_25 , struct V_107 * V_112 )
{
struct V_27 V_113 ;
F_14 ( V_26 ) ;
T_2 V_56 ;
int V_42 ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
F_72 ( V_26 , V_112 -> V_26 ) ;
F_72 ( V_113 . V_56 ,
V_112 -> V_56 ) ;
V_113 . V_64 = V_25 -> V_44 . V_64 ;
if ( F_47 ( V_26 , V_16 ) )
F_12 ( V_113 . V_56 , V_16 ) ;
if ( F_47 ( V_26 , V_17 ) )
F_12 ( V_113 . V_56 , V_17 ) ;
V_42 = F_18 ( V_25 , V_26 , & V_113 ) ;
if ( V_42 )
return V_42 ;
V_112 -> V_24 = V_25 ;
V_112 -> V_114 = F_70 ;
F_54 ( V_25 -> V_31 ,
L_34 , F_73 ( & V_112 -> V_115 . V_116 ) ,
V_112 -> V_117 -> V_118 ) ;
F_51 ( & V_112 -> V_119 ) ;
F_51 ( & V_25 -> V_85 ) ;
V_25 -> V_31 -> V_89 = V_112 ;
V_25 -> V_89 = V_112 ;
F_3 ( V_25 -> V_26 , V_26 ) ;
F_3 ( V_25 -> V_44 . V_56 , V_113 . V_56 ) ;
F_74 ( & V_56 , V_113 . V_56 ) ;
V_112 -> V_56 = V_56 ;
F_57 ( & V_25 -> V_85 ) ;
F_57 ( & V_112 -> V_119 ) ;
F_39 ( V_25 -> V_31 ,
L_35 ,
V_2 , V_25 -> V_26 ,
V_112 -> V_56 ) ;
F_75 ( V_112 ) ;
if ( V_112 -> V_120 > 0 )
F_76 ( V_112 ) ;
return 0 ;
}
int F_77 ( struct V_24 * V_25 , struct V_107 * V_112 )
{
int V_42 ;
V_42 = F_78 ( V_25 -> V_31 , V_112 , 0 , V_25 -> V_101 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_71 ( V_25 , V_112 ) ;
if ( V_42 )
F_79 ( V_112 ) ;
return V_42 ;
}
int F_80 ( struct V_24 * V_25 , struct V_33 * V_60 )
{
struct V_33 * V_121 ;
struct V_107 * V_122 ;
int V_42 ;
if ( V_25 -> V_62 == V_21 )
return 0 ;
V_121 = F_60 ( V_60 , L_36 , 0 ) ;
if ( ! V_121 )
V_121 = F_60 ( V_60 , L_1 , 0 ) ;
if ( ! V_121 )
V_121 = F_60 ( V_60 , L_37 , 0 ) ;
if ( ! V_121 ) {
if ( V_25 -> V_62 == V_20 ) {
F_28 ( V_25 -> V_31 , L_38 ) ;
return - V_123 ;
}
return 0 ;
}
V_122 = F_81 ( V_25 -> V_31 , V_121 , 0 , V_25 -> V_101 ) ;
F_26 ( V_121 ) ;
if ( ! V_122 )
return - V_123 ;
V_42 = F_71 ( V_25 , V_122 ) ;
if ( V_42 )
F_79 ( V_122 ) ;
return V_42 ;
}
void F_82 ( struct V_24 * V_25 )
{
struct V_107 * V_112 ;
F_83 ( ! F_84 () ) ;
V_112 = V_25 -> V_89 ;
if ( V_112 ) {
F_51 ( & V_112 -> V_119 ) ;
F_51 ( & V_25 -> V_85 ) ;
V_25 -> V_31 -> V_89 = NULL ;
V_25 -> V_89 = NULL ;
F_57 ( & V_25 -> V_85 ) ;
F_57 ( & V_112 -> V_119 ) ;
F_85 ( & V_25 -> V_83 ) ;
F_86 ( V_112 ) ;
}
}
void F_87 ( struct V_24 * V_25 , bool V_108 )
{
if ( ! V_108 )
V_25 -> V_87 = true ;
F_58 ( V_25 ) ;
F_39 ( V_25 -> V_31 , L_39 , V_108 ? L_32 : L_33 ) ;
}
void F_88 ( struct V_24 * V_25 )
{
F_83 ( ! F_84 () ) ;
F_54 ( V_25 -> V_31 , L_40 ,
F_16 ( V_25 -> V_62 ) ,
F_37 ( V_25 -> V_44 . V_64 ) ) ;
F_46 ( V_25 , & V_25 -> V_44 ) ;
F_38 ( V_25 , & V_25 -> V_44 ) ;
F_89 ( V_106 , & V_25 -> V_86 ) ;
F_58 ( V_25 ) ;
if ( V_25 -> V_95 )
F_90 ( V_25 -> V_95 ) ;
if ( V_25 -> V_89 )
F_91 ( V_25 -> V_89 ) ;
}
void F_92 ( struct V_24 * V_25 )
{
F_83 ( ! F_84 () ) ;
if ( V_25 -> V_89 )
F_93 ( V_25 -> V_89 ) ;
if ( V_25 -> V_95 )
F_94 ( V_25 -> V_95 ) ;
F_95 ( V_106 , & V_25 -> V_86 ) ;
F_85 ( & V_25 -> V_83 ) ;
}
void F_96 ( struct V_24 * V_25 , struct V_124 * V_125 )
{
F_83 ( ! F_84 () ) ;
V_125 -> V_26 = 0 ;
V_125 -> V_126 = 0 ;
if ( V_25 -> V_89 )
F_97 ( V_25 -> V_89 , V_125 ) ;
}
int F_98 ( struct V_24 * V_25 , struct V_124 * V_125 )
{
int V_42 = - V_127 ;
F_83 ( ! F_84 () ) ;
if ( V_25 -> V_89 )
V_42 = F_99 ( V_25 -> V_89 , V_125 ) ;
return V_42 ;
}
static void F_100 ( unsigned long * V_1 , const unsigned long * V_5 )
{
F_14 ( V_6 ) ;
F_1 ( V_6 ) ;
F_11 ( V_6 ) ;
F_5 ( V_1 , V_1 , V_6 ) ;
F_7 ( V_1 , V_1 , V_5 ) ;
}
static void F_101 ( const struct V_27 * V_28 ,
struct V_128 * V_129 )
{
F_100 ( V_129 -> V_130 . V_56 , V_28 -> V_56 ) ;
F_3 ( V_129 -> V_130 . V_74 , V_28 -> V_74 ) ;
V_129 -> V_131 . V_41 = V_28 -> V_41 ;
V_129 -> V_131 . V_45 = V_28 -> V_45 ;
V_129 -> V_131 . V_132 = V_28 -> V_63 ? V_133 :
V_134 ;
}
int F_102 ( struct V_24 * V_25 ,
struct V_128 * V_129 )
{
struct V_27 V_84 ;
F_83 ( ! F_84 () ) ;
if ( V_25 -> V_89 ) {
F_103 ( V_25 -> V_89 , V_129 ) ;
} else {
V_129 -> V_131 . V_135 = V_25 -> V_102 ;
}
F_3 ( V_129 -> V_130 . V_26 , V_25 -> V_26 ) ;
switch ( V_25 -> V_62 ) {
case V_21 :
F_44 ( V_25 , & V_84 ) ;
F_101 ( & V_84 , V_129 ) ;
break;
case V_22 :
if ( V_25 -> V_89 )
break;
case V_23 :
F_43 ( V_25 , & V_84 ) ;
F_101 ( & V_84 , V_129 ) ;
break;
}
return 0 ;
}
int F_104 ( struct V_24 * V_25 ,
const struct V_128 * V_129 )
{
struct V_128 V_136 ;
struct V_27 V_113 ;
int V_42 ;
F_83 ( ! F_84 () ) ;
if ( V_129 -> V_131 . V_132 != V_134 &&
V_129 -> V_131 . V_132 != V_133 )
return - V_32 ;
V_113 = V_25 -> V_44 ;
F_5 ( V_113 . V_56 , V_129 -> V_130 . V_56 ,
V_25 -> V_26 ) ;
if ( V_129 -> V_131 . V_132 == V_134 ) {
const struct V_36 * V_37 ;
V_37 = F_32 ( V_129 -> V_131 . V_41 , V_129 -> V_131 . V_45 ,
V_25 -> V_26 ,
V_2 , false ) ;
if ( ! V_37 )
return - V_32 ;
if ( V_25 -> V_62 == V_21 &&
( V_37 -> V_41 != V_25 -> V_44 . V_41 ||
V_37 -> V_45 != V_25 -> V_44 . V_45 ) )
return - V_32 ;
V_113 . V_41 = V_37 -> V_41 ;
V_113 . V_45 = V_37 -> V_45 ;
V_113 . V_63 = false ;
F_105 ( V_137 , V_113 . V_56 ) ;
} else {
if ( V_25 -> V_62 == V_21 )
return - V_32 ;
V_113 . V_41 = V_104 ;
V_113 . V_45 = V_105 ;
V_113 . V_63 = true ;
F_33 ( V_137 , V_113 . V_56 ) ;
}
if ( F_18 ( V_25 , V_25 -> V_26 , & V_113 ) )
return - V_32 ;
if ( V_113 . V_63 && F_13 ( V_113 . V_56 ) )
return - V_32 ;
V_136 = * V_129 ;
F_3 ( V_136 . V_130 . V_56 , V_113 . V_56 ) ;
V_136 . V_131 . V_41 = V_113 . V_41 ;
V_136 . V_131 . V_45 = V_113 . V_45 ;
if ( V_25 -> V_89 ) {
V_42 = F_106 ( V_25 -> V_89 , & V_136 ) ;
if ( V_42 )
return V_42 ;
}
F_51 ( & V_25 -> V_85 ) ;
F_3 ( V_25 -> V_44 . V_56 , V_136 . V_130 . V_56 ) ;
V_25 -> V_44 . V_41 = V_136 . V_131 . V_41 ;
V_25 -> V_44 . V_45 = V_136 . V_131 . V_45 ;
V_25 -> V_44 . V_63 = V_136 . V_131 . V_132 != V_134 ;
if ( ! F_107 ( V_106 , & V_25 -> V_86 ) ) {
F_38 ( V_25 , & V_25 -> V_44 ) ;
F_42 ( V_25 ) ;
}
F_57 ( & V_25 -> V_85 ) ;
return 0 ;
}
int F_108 ( struct V_24 * V_25 )
{
int V_42 = 0 ;
F_83 ( ! F_84 () ) ;
if ( V_25 -> V_89 )
V_42 = F_109 ( V_25 -> V_89 ) ;
F_42 ( V_25 ) ;
return V_42 ;
}
void F_110 ( struct V_24 * V_25 ,
struct V_138 * V_48 )
{
F_83 ( ! F_84 () ) ;
V_48 -> V_132 = ! ! ( V_25 -> V_44 . V_48 & V_77 ) ;
V_48 -> V_139 = ! ! ( V_25 -> V_44 . V_48 & V_79 ) ;
V_48 -> V_140 = ! ! ( V_25 -> V_44 . V_48 & V_78 ) ;
}
int F_111 ( struct V_24 * V_25 ,
struct V_138 * V_48 )
{
struct V_27 * V_113 = & V_25 -> V_44 ;
F_83 ( ! F_84 () ) ;
if ( ! F_47 ( V_25 -> V_26 , V_16 ) &&
! F_47 ( V_25 -> V_26 , V_17 ) )
return - V_127 ;
if ( ! F_47 ( V_25 -> V_26 , V_17 ) &&
! V_48 -> V_132 && V_48 -> V_139 != V_48 -> V_140 )
return - V_32 ;
V_113 -> V_48 &= ~ ( V_77 | V_80 ) ;
if ( V_48 -> V_132 )
V_113 -> V_48 |= V_77 ;
if ( V_48 -> V_139 )
V_113 -> V_48 |= V_79 ;
if ( V_48 -> V_140 )
V_113 -> V_48 |= V_78 ;
if ( ! F_107 ( V_106 , & V_25 -> V_86 ) ) {
switch ( V_25 -> V_62 ) {
case V_20 :
F_53 ( V_25 -> V_31 ) ;
F_58 ( V_25 ) ;
break;
case V_21 :
F_46 ( V_25 , V_113 ) ;
F_38 ( V_25 , V_113 ) ;
break;
case V_22 :
case V_23 :
F_38 ( V_25 , V_113 ) ;
F_42 ( V_25 ) ;
break;
}
}
return 0 ;
}
int F_112 ( struct V_24 * V_25 ,
struct V_141 * V_142 )
{
int V_42 = - V_127 ;
F_83 ( ! F_84 () ) ;
if ( V_25 -> V_95 )
V_42 = F_113 ( V_25 -> V_95 , V_142 ) ;
return V_42 ;
}
int F_114 ( struct V_24 * V_25 ,
struct V_143 * V_144 , T_4 * V_145 )
{
int V_42 = - V_127 ;
F_83 ( ! F_84 () ) ;
if ( V_25 -> V_95 )
V_42 = F_115 ( V_25 -> V_95 , V_144 , V_145 ) ;
return V_42 ;
}
int F_116 ( struct V_24 * V_25 , bool V_146 )
{
int V_42 = - V_147 ;
F_83 ( ! F_84 () ) ;
if ( V_25 -> V_89 )
V_42 = F_117 ( V_25 -> V_89 , V_146 ) ;
return V_42 ;
}
int F_118 ( struct V_24 * V_25 )
{
int V_42 = 0 ;
F_83 ( ! F_84 () ) ;
if ( V_25 -> V_89 )
V_42 = F_119 ( V_25 -> V_89 ) ;
return V_42 ;
}
int F_120 ( struct V_24 * V_25 , struct V_148 * V_149 )
{
int V_42 = - V_127 ;
F_83 ( ! F_84 () ) ;
if ( V_25 -> V_89 )
V_42 = F_121 ( V_25 -> V_89 , V_149 ) ;
return V_42 ;
}
int F_122 ( struct V_24 * V_25 , struct V_148 * V_149 )
{
int V_42 = - V_127 ;
F_83 ( ! F_84 () ) ;
if ( V_25 -> V_89 )
V_42 = F_123 ( V_25 -> V_89 , V_149 ) ;
return V_42 ;
}
static int F_124 ( struct V_72 * V_73 , unsigned int V_150 ,
struct V_27 * V_28 , bool V_151 )
{
struct V_152 V_153 ;
int V_154 ;
V_153 . V_58 = V_28 -> V_58 ;
V_153 . V_41 = V_28 -> V_41 ;
V_153 . V_45 = V_28 -> V_45 ;
V_153 . V_48 = V_28 -> V_48 & V_49 ;
V_153 . V_111 = V_28 -> V_48 & V_50 ;
V_154 = F_125 ( V_150 , & V_153 ) ;
if ( V_150 == V_155 ) {
if ( ! V_28 -> V_59 )
V_154 &= ~ V_156 ;
if ( ! V_151 )
V_154 &= ~ V_157 ;
}
return V_154 ;
}
static int F_126 ( struct V_24 * V_25 , unsigned int V_158 ,
unsigned int V_150 )
{
struct V_107 * V_89 = V_25 -> V_89 ;
int V_159 , V_160 ;
if ( F_127 ( V_158 ) ) {
V_159 = F_128 ( V_158 ) ;
V_160 = F_129 ( V_158 ) ;
V_160 = V_161 | V_160 << 16 | V_150 ;
} else if ( V_89 -> V_162 ) {
switch ( V_150 ) {
case V_163 :
case V_155 :
case V_164 :
case V_165 :
V_160 = F_130 ( V_89 -> V_166 . V_167 ) ;
break;
case V_168 :
case V_169 :
if ( ! ( V_89 -> V_166 . V_167 & V_170 ) )
return - V_32 ;
V_160 = V_171 ;
if ( V_150 == V_168 )
V_150 = V_172 ;
else
V_150 = V_173 ;
break;
default:
return - V_32 ;
}
V_159 = V_158 ;
V_160 = V_161 | V_160 << 16 | V_150 ;
} else {
V_159 = V_158 ;
V_160 = V_150 ;
}
return F_131 ( V_25 -> V_89 -> V_115 . V_174 , V_159 , V_160 ) ;
}
static int F_132 ( struct V_24 * V_25 , unsigned int V_158 ,
unsigned int V_150 , unsigned int V_154 )
{
struct V_107 * V_89 = V_25 -> V_89 ;
int V_159 , V_160 ;
if ( F_127 ( V_158 ) ) {
V_159 = F_128 ( V_158 ) ;
V_160 = F_129 ( V_158 ) ;
V_160 = V_161 | V_160 << 16 | V_150 ;
} else if ( V_89 -> V_162 ) {
switch ( V_150 ) {
case V_163 :
case V_155 :
case V_164 :
case V_165 :
V_160 = F_130 ( V_89 -> V_166 . V_167 ) ;
break;
case V_168 :
case V_169 :
if ( ! ( V_89 -> V_166 . V_167 & V_170 ) )
return - V_32 ;
V_160 = V_171 ;
if ( V_150 == V_168 )
V_150 = V_172 ;
else
V_150 = V_173 ;
break;
default:
return - V_32 ;
}
V_159 = V_158 ;
V_160 = V_161 | V_160 << 16 | V_150 ;
} else {
V_159 = V_158 ;
V_160 = V_150 ;
}
return F_133 ( V_89 -> V_115 . V_174 , V_159 , V_160 , V_154 ) ;
}
static int F_134 ( struct V_24 * V_25 , unsigned int V_158 ,
unsigned int V_150 )
{
struct V_27 V_28 ;
int V_154 = 0xffff ;
switch ( V_25 -> V_62 ) {
case V_21 :
if ( V_158 == 0 ) {
F_44 ( V_25 , & V_28 ) ;
V_154 = F_124 ( V_25 -> V_31 , V_150 , & V_28 ,
true ) ;
}
break;
case V_20 :
return - V_127 ;
case V_22 :
case V_23 :
if ( V_158 == 0 ) {
V_154 = F_43 ( V_25 , & V_28 ) ;
if ( V_154 < 0 )
return V_154 ;
V_154 = F_124 ( V_25 -> V_31 , V_150 , & V_28 ,
true ) ;
}
break;
}
return V_154 & 0xffff ;
}
static int F_135 ( struct V_24 * V_25 , unsigned int V_158 ,
unsigned int V_150 , unsigned int V_154 )
{
switch ( V_25 -> V_62 ) {
case V_21 :
break;
case V_20 :
return - V_127 ;
case V_22 :
case V_23 :
break;
}
return 0 ;
}
int F_136 ( struct V_24 * V_25 , struct V_175 * V_176 , int V_177 )
{
struct V_178 * V_179 = F_137 ( V_176 ) ;
int V_42 ;
F_83 ( ! F_84 () ) ;
if ( V_25 -> V_89 ) {
switch ( V_177 ) {
case V_180 :
V_179 -> V_158 = V_25 -> V_89 -> V_115 . V_181 ;
case V_182 :
V_42 = F_126 ( V_25 , V_179 -> V_158 , V_179 -> V_183 ) ;
if ( V_42 >= 0 ) {
V_179 -> V_184 = V_42 ;
V_42 = 0 ;
}
break;
case V_185 :
V_42 = F_132 ( V_25 , V_179 -> V_158 , V_179 -> V_183 ,
V_179 -> V_186 ) ;
break;
default:
V_42 = F_138 ( V_25 -> V_89 , V_176 , V_177 ) ;
break;
}
} else {
switch ( V_177 ) {
case V_180 :
V_179 -> V_158 = 0 ;
case V_182 :
V_42 = F_134 ( V_25 , V_179 -> V_158 , V_179 -> V_183 ) ;
if ( V_42 >= 0 ) {
V_179 -> V_184 = V_42 ;
V_42 = 0 ;
}
break;
case V_185 :
V_42 = F_135 ( V_25 , V_179 -> V_158 , V_179 -> V_183 ,
V_179 -> V_186 ) ;
break;
default:
V_42 = - V_127 ;
break;
}
}
return V_42 ;
}
static int F_139 ( void * V_187 ,
const struct V_188 * V_189 )
{
struct V_24 * V_25 = V_187 ;
F_14 ( V_190 ) = { 0 , } ;
struct V_27 V_113 ;
T_3 V_98 ;
int V_18 , V_42 = 0 ;
bool V_90 ;
T_4 V_135 ;
F_140 ( V_25 -> V_95 , V_189 , V_190 ) ;
V_135 = F_141 ( V_25 -> V_95 , V_189 , V_190 ) ;
V_98 = F_142 ( V_25 -> V_95 , V_189 ) ;
F_83 ( ! F_84 () ) ;
switch ( V_98 ) {
case V_65 :
V_18 = V_22 ;
break;
case V_66 :
V_18 = V_23 ;
break;
default:
return - V_32 ;
}
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
F_3 ( V_113 . V_56 , V_190 ) ;
V_113 . V_64 = V_98 ;
V_113 . V_41 = V_104 ;
V_113 . V_45 = V_105 ;
V_113 . V_48 = V_77 ;
V_113 . V_63 = V_25 -> V_44 . V_63 ;
V_42 = F_18 ( V_25 , V_190 , & V_113 ) ;
if ( V_42 ) {
F_28 ( V_25 -> V_31 , L_41 ,
F_16 ( V_18 ) , F_37 ( V_113 . V_64 ) ,
V_2 , V_190 , V_42 ) ;
return V_42 ;
}
F_39 ( V_25 -> V_31 , L_42 ,
F_16 ( V_18 ) , F_37 ( V_113 . V_64 ) ,
V_2 , V_190 ) ;
if ( V_18 == V_23 && V_25 -> V_89 )
return - V_32 ;
V_90 = ! F_143 ( V_25 -> V_26 , V_190 ,
V_2 ) ;
if ( V_90 ) {
F_3 ( V_25 -> V_26 , V_190 ) ;
F_3 ( V_25 -> V_44 . V_56 , V_113 . V_56 ) ;
}
if ( V_25 -> V_62 != V_18 ||
V_25 -> V_44 . V_64 != V_113 . V_64 ) {
V_25 -> V_44 . V_64 = V_113 . V_64 ;
V_25 -> V_62 = V_18 ;
V_90 = true ;
F_54 ( V_25 -> V_31 , L_43 ,
F_16 ( V_18 ) ,
F_37 ( V_113 . V_64 ) ) ;
}
V_25 -> V_102 = V_135 ;
if ( V_90 && ! F_107 ( V_106 ,
& V_25 -> V_86 ) )
F_38 ( V_25 , & V_25 -> V_44 ) ;
return V_42 ;
}
static void F_144 ( void * V_187 )
{
struct V_24 * V_25 = V_187 ;
F_83 ( ! F_84 () ) ;
F_95 ( V_191 , & V_25 -> V_86 ) ;
F_85 ( & V_25 -> V_83 ) ;
F_53 ( V_25 -> V_31 ) ;
}
static void F_145 ( void * V_187 )
{
struct V_24 * V_25 = V_187 ;
F_83 ( ! F_84 () ) ;
F_89 ( V_191 , & V_25 -> V_86 ) ;
F_58 ( V_25 ) ;
}
static int F_146 ( void * V_187 , struct V_107 * V_112 )
{
return F_77 ( V_187 , V_112 ) ;
}
static void F_147 ( void * V_187 )
{
F_82 ( V_187 ) ;
}
