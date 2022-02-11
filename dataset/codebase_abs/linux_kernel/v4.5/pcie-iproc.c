static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
#ifdef F_2
struct V_5 * V_6 = V_3 -> V_7 ;
V_4 = V_6 -> V_8 ;
#else
V_4 = V_3 -> V_7 ;
#endif
return V_4 ;
}
static inline bool F_3 ( T_1 V_9 )
{
return ! ! ( V_9 == V_10 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_4 ,
enum V_11 V_12 )
{
return V_4 -> V_13 [ V_12 ] ;
}
static inline T_2 F_5 ( struct V_1 * V_4 ,
enum V_11 V_12 )
{
T_1 V_14 = F_4 ( V_4 , V_12 ) ;
if ( F_3 ( V_14 ) )
return 0 ;
return F_6 ( V_4 -> V_15 + V_14 ) ;
}
static inline void F_7 ( struct V_1 * V_4 ,
enum V_11 V_12 , T_2 V_16 )
{
T_1 V_14 = F_4 ( V_4 , V_12 ) ;
if ( F_3 ( V_14 ) )
return;
F_8 ( V_16 , V_4 -> V_15 + V_14 ) ;
}
static inline void F_9 ( struct V_1 * V_4 ,
enum V_11 V_12 ,
unsigned V_17 , T_2 V_16 )
{
T_1 V_14 = F_4 ( V_4 , V_12 ) ;
if ( F_3 ( V_14 ) )
return;
F_8 ( V_16 , V_4 -> V_15 + V_14 + ( V_17 * 8 ) ) ;
}
static void T_3 * F_10 ( struct V_2 * V_3 ,
unsigned int V_18 ,
int V_19 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned V_20 = F_11 ( V_18 ) ;
unsigned V_21 = F_12 ( V_18 ) ;
unsigned V_22 = V_3 -> V_23 ;
T_2 V_16 ;
T_1 V_14 ;
if ( V_22 == 0 ) {
if ( V_20 > 0 || V_21 > 0 )
return NULL ;
F_7 ( V_4 , V_24 ,
V_19 & V_25 ) ;
V_14 = F_4 ( V_4 , V_26 ) ;
if ( F_3 ( V_14 ) )
return NULL ;
else
return ( V_4 -> V_15 + V_14 ) ;
}
if ( V_4 -> type == V_27 )
if ( V_20 > 0 )
return NULL ;
V_16 = ( V_22 << V_28 ) |
( V_20 << V_29 ) |
( V_21 << V_30 ) |
( V_19 & V_31 ) |
( 1 & V_32 ) ;
F_7 ( V_4 , V_33 , V_16 ) ;
V_14 = F_4 ( V_4 , V_34 ) ;
if ( F_3 ( V_14 ) )
return NULL ;
else
return ( V_4 -> V_15 + V_14 ) ;
}
static void F_13 ( struct V_1 * V_4 )
{
T_2 V_16 ;
if ( V_4 -> type == V_27 ) {
V_16 = F_5 ( V_4 , V_35 ) ;
V_16 &= ~ V_36 ;
F_7 ( V_4 , V_35 , V_16 ) ;
F_14 ( 100 ) ;
V_16 |= V_36 ;
F_7 ( V_4 , V_35 , V_16 ) ;
F_14 ( 100 ) ;
return;
}
V_16 = F_5 ( V_4 , V_35 ) ;
V_16 &= ~ V_37 & ~ V_38 &
~ V_39 ;
F_7 ( V_4 , V_35 , V_16 ) ;
F_14 ( 250 ) ;
V_16 |= V_39 ;
F_7 ( V_4 , V_35 , V_16 ) ;
F_15 ( 100 ) ;
}
static int F_16 ( struct V_1 * V_4 , struct V_2 * V_3 )
{
T_4 V_40 ;
T_2 V_41 , V_42 , V_16 ;
T_1 V_43 , V_44 ;
bool V_45 = false ;
if ( V_4 -> type == V_27 )
return 0 ;
V_16 = F_5 ( V_4 , V_46 ) ;
if ( ! ( V_16 & V_47 ) || ! ( V_16 & V_48 ) ) {
F_17 ( V_4 -> V_49 , L_1 ) ;
return - V_50 ;
}
F_18 ( V_3 , 0 , V_51 , & V_40 ) ;
if ( ( V_40 & 0x7f ) != V_52 ) {
F_17 ( V_4 -> V_49 , L_2 , V_40 ) ;
return - V_53 ;
}
#define F_19 0x43c
#define F_20 0xffff00
#define F_21 8
F_22 ( V_3 , 0 , F_19 , & V_42 ) ;
V_42 &= ~ F_20 ;
V_42 |= ( V_54 << F_21 ) ;
F_23 ( V_3 , 0 , F_19 , V_42 ) ;
V_43 = F_24 ( V_3 , 0 , V_55 ) ;
F_25 ( V_3 , 0 , V_43 + V_56 , & V_44 ) ;
if ( V_44 & V_57 )
V_45 = true ;
if ( ! V_45 ) {
#define F_26 0x0dc
#define F_27 0xf
#define F_28 0x2
#define F_29 0x1
F_22 ( V_3 , 0 ,
F_26 ,
& V_41 ) ;
if ( ( V_41 & F_27 ) ==
F_28 ) {
V_41 &= ~ F_27 ;
V_41 |= F_29 ;
F_23 ( V_3 , 0 ,
F_26 ,
V_41 ) ;
F_15 ( 100 ) ;
V_43 = F_24 ( V_3 , 0 , V_55 ) ;
F_25 ( V_3 , 0 , V_43 + V_56 ,
& V_44 ) ;
if ( V_44 & V_57 )
V_45 = true ;
}
}
F_30 ( V_4 -> V_49 , L_3 , V_45 ? L_4 : L_5 ) ;
return V_45 ? 0 : - V_50 ;
}
static void F_31 ( struct V_1 * V_4 )
{
F_7 ( V_4 , V_58 , V_59 ) ;
}
static int F_32 ( struct V_1 * V_4 , T_5 V_60 ,
T_5 V_61 , T_6 V_62 )
{
struct V_63 * V_64 = & V_4 -> V_64 ;
unsigned V_65 ;
T_5 V_66 = ( T_5 ) V_64 -> V_67 * V_68 ;
T_5 V_69 ;
if ( V_62 > V_66 ) {
F_17 ( V_4 -> V_49 ,
L_6 ,
& V_62 , V_66 ) ;
return - V_70 ;
}
F_33 ( V_62 , V_64 -> V_67 , & V_69 ) ;
if ( V_69 ) {
F_17 ( V_4 -> V_49 ,
L_7 ,
& V_62 , & V_64 -> V_67 ) ;
return - V_70 ;
}
if ( V_60 < V_64 -> V_71 ) {
F_17 ( V_4 -> V_49 ,
L_8 ,
& V_60 , & V_64 -> V_71 ) ;
return - V_70 ;
}
V_60 -= V_64 -> V_71 ;
for ( V_65 = 0 ; V_65 < V_68 ; V_65 ++ ) {
F_9 ( V_4 , V_72 , V_65 ,
F_34 ( V_60 ) | V_73 |
( V_64 -> V_74 ? 1 : 0 ) ) ;
F_9 ( V_4 , V_75 , V_65 ,
F_35 ( V_60 ) ) ;
F_9 ( V_4 , V_76 , V_65 ,
F_34 ( V_61 ) ) ;
F_9 ( V_4 , V_77 , V_65 ,
F_35 ( V_61 ) ) ;
V_62 -= V_64 -> V_67 ;
if ( V_62 == 0 )
break;
V_60 += V_64 -> V_67 ;
V_61 += V_64 -> V_67 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_4 ,
struct V_78 * V_79 )
{
struct V_80 * V_17 ;
int V_81 ;
F_37 (window, resources) {
struct V_82 * V_83 = V_17 -> V_83 ;
T_5 V_84 = F_38 ( V_83 ) ;
switch ( V_84 ) {
case V_85 :
case V_86 :
break;
case V_87 :
V_81 = F_32 ( V_4 , V_83 -> V_88 ,
V_83 -> V_88 - V_17 -> V_14 ,
F_39 ( V_83 ) ) ;
if ( V_81 )
return V_81 ;
break;
default:
F_17 ( V_4 -> V_49 , L_9 , V_83 ) ;
return - V_70 ;
}
}
return 0 ;
}
static int F_40 ( struct V_1 * V_4 )
{
struct V_89 * V_90 ;
V_90 = F_41 ( V_4 -> V_49 -> V_91 , L_10 , 0 ) ;
if ( ! V_90 )
return - V_50 ;
return F_42 ( V_4 , V_90 ) ;
}
static void F_43 ( struct V_1 * V_4 )
{
F_44 ( V_4 ) ;
}
int F_45 ( struct V_1 * V_4 , struct V_78 * V_83 )
{
int V_81 ;
void * V_7 ;
struct V_2 * V_3 ;
if ( ! V_4 || ! V_4 -> V_49 || ! V_4 -> V_15 )
return - V_70 ;
V_81 = F_46 ( V_4 -> V_92 ) ;
if ( V_81 ) {
F_17 ( V_4 -> V_49 , L_11 ) ;
return V_81 ;
}
V_81 = F_47 ( V_4 -> V_92 ) ;
if ( V_81 ) {
F_17 ( V_4 -> V_49 , L_12 ) ;
goto V_93;
}
switch ( V_4 -> type ) {
case V_94 :
V_4 -> V_13 = V_95 ;
break;
case V_27 :
V_4 -> V_13 = V_96 ;
break;
default:
F_17 ( V_4 -> V_49 , L_13 ) ;
V_81 = - V_70 ;
goto V_97;
}
F_13 ( V_4 ) ;
if ( V_4 -> V_98 ) {
V_81 = F_36 ( V_4 , V_83 ) ;
if ( V_81 ) {
F_17 ( V_4 -> V_49 , L_14 ) ;
goto V_97;
}
}
#ifdef F_2
V_4 -> V_7 . V_8 = V_4 ;
V_7 = & V_4 -> V_7 ;
#else
V_7 = V_4 ;
#endif
V_3 = F_48 ( V_4 -> V_49 , 0 , & V_99 , V_7 , V_83 ) ;
if ( ! V_3 ) {
F_17 ( V_4 -> V_49 , L_15 ) ;
V_81 = - V_100 ;
goto V_97;
}
V_4 -> V_101 = V_3 ;
V_81 = F_16 ( V_4 , V_3 ) ;
if ( V_81 ) {
F_17 ( V_4 -> V_49 , L_16 ) ;
goto V_102;
}
F_31 ( V_4 ) ;
if ( F_49 ( V_103 ) )
if ( F_40 ( V_4 ) )
F_30 ( V_4 -> V_49 , L_17 ) ;
F_50 ( V_3 ) ;
F_51 ( V_3 ) ;
F_52 ( V_104 , V_4 -> V_105 ) ;
F_53 ( V_3 ) ;
return 0 ;
V_102:
F_54 ( V_3 ) ;
F_55 ( V_3 ) ;
V_97:
F_56 ( V_4 -> V_92 ) ;
V_93:
F_57 ( V_4 -> V_92 ) ;
return V_81 ;
}
int F_58 ( struct V_1 * V_4 )
{
F_54 ( V_4 -> V_101 ) ;
F_55 ( V_4 -> V_101 ) ;
F_43 ( V_4 ) ;
F_56 ( V_4 -> V_92 ) ;
F_57 ( V_4 -> V_92 ) ;
return 0 ;
}
