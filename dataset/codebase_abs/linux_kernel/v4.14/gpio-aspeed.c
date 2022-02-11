static const struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 = F_2 ( V_2 ) ;
F_3 ( V_3 > F_4 ( V_4 ) ) ;
return & V_4 [ V_3 ] ;
}
static inline bool F_5 ( const struct V_5 * V_6 )
{
return ! ( V_6 -> V_7 || V_6 -> V_8 ) ;
}
static inline const struct V_5 * F_6 (
struct V_9 * V_10 , unsigned int V_2 )
{
const struct V_5 * V_6 = V_10 -> V_11 -> V_6 ;
while ( ! F_5 ( V_6 ) ) {
if ( V_6 -> V_3 == F_2 ( V_2 ) )
return V_6 ;
V_6 ++ ;
}
return NULL ;
}
static inline bool F_7 ( struct V_9 * V_10 , unsigned int V_2 )
{
const struct V_5 * V_6 = F_6 ( V_10 , V_2 ) ;
const struct V_1 * V_3 = F_1 ( V_2 ) ;
unsigned int V_12 = F_8 ( V_2 ) / 8 ;
return V_3 -> V_13 [ V_12 ] [ 0 ] != '\0' &&
( ! V_6 || ( ( V_6 -> V_7 | V_6 -> V_8 ) & F_9 ( V_2 ) ) ) ;
}
static inline bool F_10 ( struct V_9 * V_10 , unsigned int V_2 )
{
const struct V_5 * V_6 = F_6 ( V_10 , V_2 ) ;
return ! V_6 || ( V_6 -> V_7 & F_9 ( V_2 ) ) ;
}
static inline bool F_11 ( struct V_9 * V_10 , unsigned int V_2 )
{
const struct V_5 * V_6 = F_6 ( V_10 , V_2 ) ;
return ! V_6 || ( V_6 -> V_8 & F_9 ( V_2 ) ) ;
}
static void T_1 * F_12 ( struct V_9 * V_10 ,
const struct V_1 * V_3 ,
unsigned int V_14 )
{
return V_10 -> V_15 + V_3 -> V_16 + V_14 ;
}
static void T_1 * F_13 ( struct V_9 * V_10 ,
const struct V_1 * V_3 ,
unsigned int V_14 )
{
return V_10 -> V_15 + V_3 -> V_17 + V_14 ;
}
static int F_14 ( struct V_18 * V_19 , unsigned int V_2 )
{
struct V_9 * V_10 = F_15 ( V_19 ) ;
const struct V_1 * V_3 = F_1 ( V_2 ) ;
return ! ! ( F_16 ( F_12 ( V_10 , V_3 , V_20 ) )
& F_9 ( V_2 ) ) ;
}
static void F_17 ( struct V_18 * V_19 , unsigned int V_2 ,
int V_21 )
{
struct V_9 * V_10 = F_15 ( V_19 ) ;
const struct V_1 * V_3 = F_1 ( V_2 ) ;
void T_1 * V_22 ;
T_2 V_14 ;
V_22 = F_12 ( V_10 , V_3 , V_20 ) ;
V_14 = F_16 ( V_22 ) ;
if ( V_21 )
V_14 |= F_9 ( V_2 ) ;
else
V_14 &= ~ F_9 ( V_2 ) ;
F_18 ( V_14 , V_22 ) ;
}
static void F_19 ( struct V_18 * V_19 , unsigned int V_2 ,
int V_21 )
{
struct V_9 * V_10 = F_15 ( V_19 ) ;
unsigned long V_23 ;
F_20 ( & V_10 -> V_24 , V_23 ) ;
F_17 ( V_19 , V_2 , V_21 ) ;
F_21 ( & V_10 -> V_24 , V_23 ) ;
}
static int F_22 ( struct V_18 * V_19 , unsigned int V_2 )
{
struct V_9 * V_10 = F_15 ( V_19 ) ;
const struct V_1 * V_3 = F_1 ( V_2 ) ;
unsigned long V_23 ;
T_2 V_14 ;
if ( ! F_10 ( V_10 , V_2 ) )
return - V_25 ;
F_20 ( & V_10 -> V_24 , V_23 ) ;
V_14 = F_16 ( F_12 ( V_10 , V_3 , V_26 ) ) ;
F_18 ( V_14 & ~ F_9 ( V_2 ) , F_12 ( V_10 , V_3 , V_26 ) ) ;
F_21 ( & V_10 -> V_24 , V_23 ) ;
return 0 ;
}
static int F_23 ( struct V_18 * V_19 ,
unsigned int V_2 , int V_21 )
{
struct V_9 * V_10 = F_15 ( V_19 ) ;
const struct V_1 * V_3 = F_1 ( V_2 ) ;
unsigned long V_23 ;
T_2 V_14 ;
if ( ! F_11 ( V_10 , V_2 ) )
return - V_25 ;
F_20 ( & V_10 -> V_24 , V_23 ) ;
V_14 = F_16 ( F_12 ( V_10 , V_3 , V_26 ) ) ;
F_18 ( V_14 | F_9 ( V_2 ) , F_12 ( V_10 , V_3 , V_26 ) ) ;
F_17 ( V_19 , V_2 , V_21 ) ;
F_21 ( & V_10 -> V_24 , V_23 ) ;
return 0 ;
}
static int F_24 ( struct V_18 * V_19 , unsigned int V_2 )
{
struct V_9 * V_10 = F_15 ( V_19 ) ;
const struct V_1 * V_3 = F_1 ( V_2 ) ;
unsigned long V_23 ;
T_2 V_21 ;
if ( ! F_10 ( V_10 , V_2 ) )
return 0 ;
if ( ! F_11 ( V_10 , V_2 ) )
return 1 ;
F_20 ( & V_10 -> V_24 , V_23 ) ;
V_21 = F_16 ( F_12 ( V_10 , V_3 , V_26 ) ) & F_9 ( V_2 ) ;
F_21 ( & V_10 -> V_24 , V_23 ) ;
return ! V_21 ;
}
static inline int F_25 ( struct V_27 * V_28 ,
struct V_9 * * V_10 ,
const struct V_1 * * V_3 ,
T_2 * V_29 )
{
int V_2 ;
struct V_9 * V_30 ;
V_2 = F_26 ( V_28 ) ;
V_30 = F_27 ( V_28 ) ;
if ( ! F_28 ( V_30 , V_2 ) )
return - V_25 ;
* V_10 = V_30 ;
* V_3 = F_1 ( V_2 ) ;
* V_29 = F_9 ( V_2 ) ;
return 0 ;
}
static void F_29 ( struct V_27 * V_28 )
{
const struct V_1 * V_3 ;
struct V_9 * V_10 ;
unsigned long V_23 ;
void T_1 * V_31 ;
T_2 V_29 ;
int V_32 ;
V_32 = F_25 ( V_28 , & V_10 , & V_3 , & V_29 ) ;
if ( V_32 )
return;
V_31 = F_13 ( V_10 , V_3 , V_33 ) ;
F_20 ( & V_10 -> V_24 , V_23 ) ;
F_18 ( V_29 , V_31 ) ;
F_21 ( & V_10 -> V_24 , V_23 ) ;
}
static void F_30 ( struct V_27 * V_28 , bool V_34 )
{
const struct V_1 * V_3 ;
struct V_9 * V_10 ;
unsigned long V_23 ;
T_2 V_14 , V_29 ;
void T_1 * V_22 ;
int V_32 ;
V_32 = F_25 ( V_28 , & V_10 , & V_3 , & V_29 ) ;
if ( V_32 )
return;
V_22 = F_13 ( V_10 , V_3 , V_35 ) ;
F_20 ( & V_10 -> V_24 , V_23 ) ;
V_14 = F_16 ( V_22 ) ;
if ( V_34 )
V_14 |= V_29 ;
else
V_14 &= V_29 ;
F_18 ( V_14 , V_22 ) ;
F_21 ( & V_10 -> V_24 , V_23 ) ;
}
static void F_31 ( struct V_27 * V_28 )
{
F_30 ( V_28 , false ) ;
}
static void F_32 ( struct V_27 * V_28 )
{
F_30 ( V_28 , true ) ;
}
static int F_33 ( struct V_27 * V_28 , unsigned int type )
{
T_2 V_36 = 0 ;
T_2 V_37 = 0 ;
T_2 V_38 = 0 ;
T_2 V_29 , V_14 ;
const struct V_1 * V_3 ;
T_3 V_39 ;
struct V_9 * V_10 ;
unsigned long V_23 ;
void T_1 * V_22 ;
int V_32 ;
V_32 = F_25 ( V_28 , & V_10 , & V_3 , & V_29 ) ;
if ( V_32 )
return - V_40 ;
switch ( type & V_41 ) {
case V_42 :
V_38 |= V_29 ;
case V_43 :
V_36 |= V_29 ;
case V_44 :
V_39 = V_45 ;
break;
case V_46 :
V_36 |= V_29 ;
case V_47 :
V_37 |= V_29 ;
V_39 = V_48 ;
break;
default:
return - V_40 ;
}
F_20 ( & V_10 -> V_24 , V_23 ) ;
V_22 = F_13 ( V_10 , V_3 , V_49 ) ;
V_14 = F_16 ( V_22 ) ;
V_14 = ( V_14 & ~ V_29 ) | V_36 ;
F_18 ( V_14 , V_22 ) ;
V_22 = F_13 ( V_10 , V_3 , V_50 ) ;
V_14 = F_16 ( V_22 ) ;
V_14 = ( V_14 & ~ V_29 ) | V_37 ;
F_18 ( V_14 , V_22 ) ;
V_22 = F_13 ( V_10 , V_3 , V_51 ) ;
V_14 = F_16 ( V_22 ) ;
V_14 = ( V_14 & ~ V_29 ) | V_38 ;
F_18 ( V_14 , V_22 ) ;
F_21 ( & V_10 -> V_24 , V_23 ) ;
F_34 ( V_28 , V_39 ) ;
return 0 ;
}
static void F_35 ( struct V_52 * V_53 )
{
struct V_18 * V_19 = F_36 ( V_53 ) ;
struct V_54 * V_55 = F_37 ( V_53 ) ;
struct V_9 * V_56 = F_15 ( V_19 ) ;
unsigned int V_57 , V_58 , V_59 ;
unsigned long V_14 ;
F_38 ( V_55 , V_53 ) ;
for ( V_57 = 0 ; V_57 < F_4 ( V_4 ) ; V_57 ++ ) {
const struct V_1 * V_3 = & V_4 [ V_57 ] ;
V_14 = F_16 ( F_13 ( V_56 , V_3 , V_33 ) ) ;
F_39 (p, &reg, 32 ) {
V_59 = F_40 ( V_19 -> V_60 , V_57 * 32 + V_58 ) ;
F_41 ( V_59 ) ;
}
}
F_42 ( V_55 , V_53 ) ;
}
static void F_43 ( struct V_9 * V_10 )
{
const struct V_5 * V_6 = V_10 -> V_11 -> V_6 ;
while ( ! F_5 ( V_6 ) ) {
unsigned int V_2 ;
const unsigned long int V_7 = V_6 -> V_7 ;
F_44 (offset, &input, 32 ) {
unsigned int V_57 = V_6 -> V_3 * 32 + V_2 ;
if ( V_57 >= V_10 -> V_11 -> V_61 )
break;
F_45 ( V_57 , V_10 -> V_62 . V_63 ) ;
}
V_6 ++ ;
}
}
static int F_46 ( struct V_9 * V_10 ,
struct V_64 * V_65 )
{
int V_32 ;
V_32 = F_47 ( V_65 , 0 ) ;
if ( V_32 < 0 )
return V_32 ;
V_10 -> V_66 = V_32 ;
F_43 ( V_10 ) ;
V_32 = F_48 ( & V_10 -> V_62 , & V_67 ,
0 , V_68 , V_69 ) ;
if ( V_32 ) {
F_49 ( & V_65 -> V_70 , L_1 ) ;
return V_32 ;
}
F_50 ( & V_10 -> V_62 , & V_67 ,
V_10 -> V_66 , F_35 ) ;
return 0 ;
}
static int F_51 ( struct V_18 * V_62 , unsigned int V_2 )
{
if ( ! F_7 ( F_15 ( V_62 ) , V_2 ) )
return - V_71 ;
return F_52 ( V_62 -> V_15 + V_2 ) ;
}
static void F_53 ( struct V_18 * V_62 , unsigned int V_2 )
{
F_54 ( V_62 -> V_15 + V_2 ) ;
}
static inline void T_1 * F_55 ( struct V_9 * V_10 ,
const struct V_1 * V_3 ,
unsigned int V_14 )
{
return V_10 -> V_15 + V_3 -> V_72 + V_14 ;
}
static int F_56 ( struct V_9 * V_10 , unsigned long V_73 ,
T_2 * V_74 )
{
T_4 V_75 ;
T_4 V_76 ;
T_2 V_77 ;
V_75 = F_57 ( V_10 -> V_78 ) ;
if ( ! V_75 )
return - V_25 ;
V_76 = V_75 * V_73 ;
V_77 = F_58 ( V_76 , 1000000 ) ;
if ( V_76 >= V_79 )
return - V_80 ;
* V_74 = V_76 + ( ! ! V_77 ) ;
return 0 ;
}
static int F_59 ( struct V_9 * V_10 ,
unsigned int V_2 , unsigned int V_81 )
{
if ( F_60 ( V_10 -> V_82 [ V_2 ] != 0 ,
L_2 ,
V_2 , V_10 -> V_82 [ V_2 ] ) )
return - V_40 ;
if ( F_60 ( V_10 -> V_83 [ V_81 ] == V_84 ,
L_3 ) )
return - V_85 ;
V_10 -> V_82 [ V_2 ] = V_81 ;
V_10 -> V_83 [ V_81 ] ++ ;
return 0 ;
}
static int F_61 ( struct V_9 * V_10 ,
unsigned int V_2 )
{
if ( F_60 ( V_10 -> V_82 [ V_2 ] == 0 ,
L_4 , V_2 ) )
return - V_40 ;
if ( F_60 ( V_10 -> V_83 [ V_10 -> V_82 [ V_2 ] ] == 0 ,
L_5 ,
V_10 -> V_82 [ V_2 ] ) )
return - V_40 ;
V_10 -> V_83 [ V_10 -> V_82 [ V_2 ] ] -- ;
V_10 -> V_82 [ V_2 ] = 0 ;
return 0 ;
}
static inline bool F_62 ( struct V_9 * V_10 ,
unsigned int V_2 )
{
return V_10 -> V_82 [ V_2 ] > 0 ;
}
static void F_63 ( struct V_9 * V_10 , unsigned int V_2 ,
unsigned int V_81 )
{
const struct V_1 * V_3 = F_1 ( V_2 ) ;
const T_2 V_86 = F_9 ( V_2 ) ;
void T_1 * V_22 ;
T_2 V_21 ;
V_22 = F_55 ( V_10 , V_3 , V_87 ) ;
V_21 = F_16 ( V_22 ) ;
F_18 ( ( V_21 & ~ V_86 ) | F_64 ( V_81 , V_2 ) , V_22 ) ;
V_22 = F_55 ( V_10 , V_3 , V_88 ) ;
V_21 = F_16 ( V_22 ) ;
F_18 ( ( V_21 & ~ V_86 ) | F_65 ( V_81 , V_2 ) , V_22 ) ;
}
static int F_66 ( struct V_18 * V_62 , unsigned int V_2 ,
unsigned long V_73 )
{
struct V_9 * V_10 = F_15 ( V_62 ) ;
T_2 V_89 ;
unsigned long V_23 ;
int V_32 ;
int V_57 ;
if ( ! V_10 -> V_78 )
return - V_40 ;
V_32 = F_56 ( V_10 , V_73 , & V_89 ) ;
if ( V_32 < 0 ) {
F_67 ( V_62 -> V_90 , L_6 ,
V_73 , F_57 ( V_10 -> V_78 ) , V_32 ) ;
return V_32 ;
}
F_20 ( & V_10 -> V_24 , V_23 ) ;
if ( F_62 ( V_10 , V_2 ) ) {
V_32 = F_61 ( V_10 , V_2 ) ;
if ( V_32 < 0 )
goto V_91;
}
for ( V_57 = 1 ; V_57 < F_4 ( V_92 ) ; V_57 ++ ) {
T_2 V_74 ;
V_74 = F_16 ( V_10 -> V_15 + V_92 [ V_57 ] ) ;
if ( V_89 == V_74 )
break;
}
if ( V_57 == F_4 ( V_92 ) ) {
int V_93 ;
for ( V_93 = 1 ; V_93 < F_4 ( V_10 -> V_83 ) ; V_93 ++ ) {
if ( V_10 -> V_83 [ V_93 ] == 0 )
break;
}
if ( V_93 == F_4 ( V_10 -> V_83 ) ) {
F_67 ( V_62 -> V_90 ,
L_7 ,
V_73 ) ;
V_32 = - V_85 ;
F_63 ( V_10 , V_2 , 0 ) ;
goto V_91;
}
V_57 = V_93 ;
F_18 ( V_89 , V_10 -> V_15 + V_92 [ V_57 ] ) ;
}
if ( F_60 ( V_57 == 0 , L_8 ) ) {
V_32 = - V_40 ;
goto V_91;
}
F_59 ( V_10 , V_2 , V_57 ) ;
F_63 ( V_10 , V_2 , V_57 ) ;
V_91:
F_21 ( & V_10 -> V_24 , V_23 ) ;
return V_32 ;
}
static int F_68 ( struct V_18 * V_62 , unsigned int V_2 )
{
struct V_9 * V_10 = F_15 ( V_62 ) ;
unsigned long V_23 ;
int V_32 ;
F_20 ( & V_10 -> V_24 , V_23 ) ;
V_32 = F_61 ( V_10 , V_2 ) ;
if ( ! V_32 )
F_63 ( V_10 , V_2 , 0 ) ;
F_21 ( & V_10 -> V_24 , V_23 ) ;
return V_32 ;
}
static int F_69 ( struct V_18 * V_62 , unsigned int V_2 ,
unsigned long V_73 )
{
struct V_9 * V_10 = F_15 ( V_62 ) ;
if ( ! F_70 ( V_10 , V_2 ) )
return - V_25 ;
if ( V_73 )
return F_66 ( V_62 , V_2 , V_73 ) ;
return F_68 ( V_62 , V_2 ) ;
}
static int F_71 ( struct V_18 * V_62 , unsigned int V_2 ,
unsigned long V_11 )
{
unsigned long V_94 = F_72 ( V_11 ) ;
T_2 V_95 = F_73 ( V_11 ) ;
if ( V_94 == V_96 )
return F_69 ( V_62 , V_2 , V_95 ) ;
else if ( V_94 == V_97 ||
V_94 == V_98 ||
V_94 == V_99 )
return F_74 ( V_2 , V_11 ) ;
else if ( V_94 == V_100 ||
V_94 == V_101 )
return - V_25 ;
return - V_25 ;
}
static int T_5 F_75 ( struct V_64 * V_65 )
{
const struct V_102 * V_103 ;
struct V_9 * V_10 ;
struct V_104 * V_105 ;
int V_32 ;
V_10 = F_76 ( & V_65 -> V_70 , sizeof( * V_10 ) , V_106 ) ;
if ( ! V_10 )
return - V_107 ;
V_105 = F_77 ( V_65 , V_108 , 0 ) ;
V_10 -> V_15 = F_78 ( & V_65 -> V_70 , V_105 ) ;
if ( F_79 ( V_10 -> V_15 ) )
return F_80 ( V_10 -> V_15 ) ;
F_81 ( & V_10 -> V_24 ) ;
V_103 = F_82 ( V_109 , V_65 -> V_70 . V_110 ) ;
if ( ! V_103 )
return - V_40 ;
V_10 -> V_78 = F_83 ( V_65 -> V_70 . V_110 , 0 ) ;
if ( F_79 ( V_10 -> V_78 ) ) {
F_67 ( & V_65 -> V_70 ,
L_9 ) ;
V_10 -> V_78 = NULL ;
}
V_10 -> V_11 = V_103 -> V_56 ;
V_10 -> V_62 . V_90 = & V_65 -> V_70 ;
V_10 -> V_62 . V_111 = V_10 -> V_11 -> V_61 ;
V_10 -> V_62 . V_90 = & V_65 -> V_70 ;
V_10 -> V_62 . V_112 = F_22 ;
V_10 -> V_62 . V_113 = F_23 ;
V_10 -> V_62 . V_114 = F_24 ;
V_10 -> V_62 . V_115 = F_51 ;
V_10 -> V_62 . free = F_53 ;
V_10 -> V_62 . V_116 = F_14 ;
V_10 -> V_62 . V_34 = F_19 ;
V_10 -> V_62 . V_117 = F_71 ;
V_10 -> V_62 . V_118 = F_84 ( & V_65 -> V_70 ) ;
V_10 -> V_62 . V_15 = - 1 ;
V_10 -> V_62 . V_119 = true ;
V_32 = F_85 ( & V_65 -> V_70 , & V_10 -> V_62 , V_10 ) ;
if ( V_32 < 0 )
return V_32 ;
V_10 -> V_82 =
F_76 ( & V_65 -> V_70 , V_10 -> V_62 . V_111 , V_106 ) ;
return F_46 ( V_10 , V_65 ) ;
}
