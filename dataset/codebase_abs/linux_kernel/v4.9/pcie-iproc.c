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
struct V_40 * V_41 = V_4 -> V_41 ;
T_4 V_42 ;
T_2 V_43 , V_44 , V_16 ;
T_1 V_45 = V_46 , V_47 ;
bool V_48 = false ;
if ( V_4 -> type == V_27 )
return 0 ;
V_16 = F_5 ( V_4 , V_49 ) ;
if ( ! ( V_16 & V_50 ) || ! ( V_16 & V_51 ) ) {
F_17 ( V_41 , L_1 ) ;
return - V_52 ;
}
F_18 ( V_3 , 0 , V_53 , & V_42 ) ;
if ( ( V_42 & 0x7f ) != V_54 ) {
F_17 ( V_41 , L_2 , V_42 ) ;
return - V_55 ;
}
#define F_19 0x43c
#define F_20 0xffff00
#define F_21 8
F_22 ( V_3 , 0 , F_19 , & V_44 ) ;
V_44 &= ~ F_20 ;
V_44 |= ( V_56 << F_21 ) ;
F_23 ( V_3 , 0 , F_19 , V_44 ) ;
F_24 ( V_3 , 0 , V_45 + V_57 , & V_47 ) ;
if ( V_47 & V_58 )
V_48 = true ;
if ( ! V_48 ) {
#define F_25 0xf
#define F_26 0x2
#define F_27 0x1
F_22 ( V_3 , 0 ,
V_45 + V_59 ,
& V_43 ) ;
if ( ( V_43 & F_25 ) ==
F_26 ) {
V_43 &= ~ F_25 ;
V_43 |= F_27 ;
F_23 ( V_3 , 0 ,
V_45 + V_59 ,
V_43 ) ;
F_15 ( 100 ) ;
F_24 ( V_3 , 0 , V_45 + V_57 ,
& V_47 ) ;
if ( V_47 & V_58 )
V_48 = true ;
}
}
F_28 ( V_41 , L_3 , V_48 ? L_4 : L_5 ) ;
return V_48 ? 0 : - V_52 ;
}
static void F_29 ( struct V_1 * V_4 )
{
F_7 ( V_4 , V_60 , V_61 ) ;
}
static int F_30 ( struct V_1 * V_4 , T_5 V_62 ,
T_5 V_63 , T_6 V_64 )
{
struct V_65 * V_66 = & V_4 -> V_66 ;
struct V_40 * V_41 = V_4 -> V_41 ;
unsigned V_67 ;
T_5 V_68 = ( T_5 ) V_66 -> V_69 * V_70 ;
T_5 V_71 ;
if ( V_64 > V_68 ) {
F_17 ( V_41 ,
L_6 ,
& V_64 , V_68 ) ;
return - V_72 ;
}
F_31 ( V_64 , V_66 -> V_69 , & V_71 ) ;
if ( V_71 ) {
F_17 ( V_41 ,
L_7 ,
& V_64 , & V_66 -> V_69 ) ;
return - V_72 ;
}
if ( V_62 < V_66 -> V_73 ) {
F_17 ( V_41 , L_8 ,
& V_62 , & V_66 -> V_73 ) ;
return - V_72 ;
}
V_62 -= V_66 -> V_73 ;
for ( V_67 = 0 ; V_67 < V_70 ; V_67 ++ ) {
F_9 ( V_4 , V_74 , V_67 ,
F_32 ( V_62 ) | V_75 |
( V_66 -> V_76 ? 1 : 0 ) ) ;
F_9 ( V_4 , V_77 , V_67 ,
F_33 ( V_62 ) ) ;
F_9 ( V_4 , V_78 , V_67 ,
F_32 ( V_63 ) ) ;
F_9 ( V_4 , V_79 , V_67 ,
F_33 ( V_63 ) ) ;
V_64 -= V_66 -> V_69 ;
if ( V_64 == 0 )
break;
V_62 += V_66 -> V_69 ;
V_63 += V_66 -> V_69 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_4 ,
struct V_80 * V_81 )
{
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_82 * V_17 ;
int V_83 ;
F_35 (window, resources) {
struct V_84 * V_85 = V_17 -> V_85 ;
T_5 V_86 = F_36 ( V_85 ) ;
switch ( V_86 ) {
case V_87 :
case V_88 :
break;
case V_89 :
V_83 = F_30 ( V_4 , V_85 -> V_90 ,
V_85 -> V_90 - V_17 -> V_14 ,
F_37 ( V_85 ) ) ;
if ( V_83 )
return V_83 ;
break;
default:
F_17 ( V_41 , L_9 , V_85 ) ;
return - V_72 ;
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_4 )
{
struct V_91 * V_92 ;
V_92 = F_39 ( V_4 -> V_41 -> V_93 , L_10 , 0 ) ;
if ( ! V_92 )
return - V_52 ;
return F_40 ( V_4 , V_92 ) ;
}
static void F_41 ( struct V_1 * V_4 )
{
F_42 ( V_4 ) ;
}
int F_43 ( struct V_1 * V_4 , struct V_80 * V_85 )
{
struct V_40 * V_41 ;
int V_83 ;
void * V_7 ;
struct V_2 * V_3 ;
V_41 = V_4 -> V_41 ;
V_83 = F_44 ( V_41 , V_85 ) ;
if ( V_83 )
return V_83 ;
V_83 = F_45 ( V_4 -> V_94 ) ;
if ( V_83 ) {
F_17 ( V_41 , L_11 ) ;
return V_83 ;
}
V_83 = F_46 ( V_4 -> V_94 ) ;
if ( V_83 ) {
F_17 ( V_41 , L_12 ) ;
goto V_95;
}
switch ( V_4 -> type ) {
case V_96 :
V_4 -> V_13 = V_97 ;
break;
case V_27 :
V_4 -> V_13 = V_98 ;
break;
default:
F_17 ( V_41 , L_13 ) ;
V_83 = - V_72 ;
goto V_99;
}
F_13 ( V_4 ) ;
if ( V_4 -> V_100 ) {
V_83 = F_34 ( V_4 , V_85 ) ;
if ( V_83 ) {
F_17 ( V_41 , L_14 ) ;
goto V_99;
}
}
#ifdef F_2
V_4 -> V_7 . V_8 = V_4 ;
V_7 = & V_4 -> V_7 ;
#else
V_7 = V_4 ;
#endif
V_3 = F_47 ( V_41 , 0 , & V_101 , V_7 , V_85 ) ;
if ( ! V_3 ) {
F_17 ( V_41 , L_15 ) ;
V_83 = - V_102 ;
goto V_99;
}
V_4 -> V_103 = V_3 ;
V_83 = F_16 ( V_4 , V_3 ) ;
if ( V_83 ) {
F_17 ( V_41 , L_16 ) ;
goto V_104;
}
F_29 ( V_4 ) ;
if ( F_48 ( V_105 ) )
if ( F_38 ( V_4 ) )
F_28 ( V_41 , L_17 ) ;
F_49 ( V_3 ) ;
F_50 ( V_3 ) ;
F_51 ( V_106 , V_4 -> V_107 ) ;
F_52 ( V_3 ) ;
return 0 ;
V_104:
F_53 ( V_3 ) ;
F_54 ( V_3 ) ;
V_99:
F_55 ( V_4 -> V_94 ) ;
V_95:
F_56 ( V_4 -> V_94 ) ;
return V_83 ;
}
int F_57 ( struct V_1 * V_4 )
{
F_53 ( V_4 -> V_103 ) ;
F_54 ( V_4 -> V_103 ) ;
F_41 ( V_4 ) ;
F_55 ( V_4 -> V_94 ) ;
F_56 ( V_4 -> V_94 ) ;
return 0 ;
}
