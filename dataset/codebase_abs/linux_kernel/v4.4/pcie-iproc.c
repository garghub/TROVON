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
static void T_1 * F_3 ( struct V_2 * V_3 ,
unsigned int V_9 ,
int V_10 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned V_11 = F_4 ( V_9 ) ;
unsigned V_12 = F_5 ( V_9 ) ;
unsigned V_13 = V_3 -> V_14 ;
T_2 V_15 ;
if ( V_13 == 0 ) {
if ( V_11 >= 1 )
return NULL ;
F_6 ( V_10 & V_16 ,
V_4 -> V_17 + V_18 ) ;
return ( V_4 -> V_17 + V_19 ) ;
}
if ( V_12 > 1 )
return NULL ;
V_15 = ( V_13 << V_20 ) |
( V_11 << V_21 ) |
( V_12 << V_22 ) |
( V_10 & V_23 ) |
( 1 & V_24 ) ;
F_6 ( V_15 , V_4 -> V_17 + V_25 ) ;
return ( V_4 -> V_17 + V_26 ) ;
}
static void F_7 ( struct V_1 * V_4 )
{
T_2 V_15 ;
V_15 = F_8 ( V_4 -> V_17 + V_27 ) ;
V_15 &= ~ V_28 & ~ V_29 &
~ V_30 ;
F_6 ( V_15 , V_4 -> V_17 + V_27 ) ;
F_9 ( 250 ) ;
V_15 |= V_30 ;
F_6 ( V_15 , V_4 -> V_17 + V_27 ) ;
F_10 ( 100 ) ;
}
static int F_11 ( struct V_1 * V_4 , struct V_2 * V_3 )
{
T_3 V_31 ;
T_2 V_32 , V_33 , V_15 ;
T_4 V_34 , V_35 ;
bool V_36 = false ;
V_15 = F_8 ( V_4 -> V_17 + V_37 ) ;
if ( ! ( V_15 & V_38 ) || ! ( V_15 & V_39 ) ) {
F_12 ( V_4 -> V_40 , L_1 ) ;
return - V_41 ;
}
F_13 ( V_3 , 0 , V_42 , & V_31 ) ;
if ( ( V_31 & 0x7f ) != V_43 ) {
F_12 ( V_4 -> V_40 , L_2 , V_31 ) ;
return - V_44 ;
}
#define F_14 0x43c
#define F_15 0xffff00
#define F_16 8
F_17 ( V_3 , 0 , F_14 , & V_33 ) ;
V_33 &= ~ F_15 ;
V_33 |= ( V_45 << F_16 ) ;
F_18 ( V_3 , 0 , F_14 , V_33 ) ;
V_34 = F_19 ( V_3 , 0 , V_46 ) ;
F_20 ( V_3 , 0 , V_34 + V_47 , & V_35 ) ;
if ( V_35 & V_48 )
V_36 = true ;
if ( ! V_36 ) {
#define F_21 0x0dc
#define F_22 0xf
#define F_23 0x2
#define F_24 0x1
F_17 ( V_3 , 0 ,
F_21 ,
& V_32 ) ;
if ( ( V_32 & F_22 ) ==
F_23 ) {
V_32 &= ~ F_22 ;
V_32 |= F_24 ;
F_18 ( V_3 , 0 ,
F_21 ,
V_32 ) ;
F_10 ( 100 ) ;
V_34 = F_19 ( V_3 , 0 , V_46 ) ;
F_20 ( V_3 , 0 , V_34 + V_47 ,
& V_35 ) ;
if ( V_35 & V_48 )
V_36 = true ;
}
}
F_25 ( V_4 -> V_40 , L_3 , V_36 ? L_4 : L_5 ) ;
return V_36 ? 0 : - V_41 ;
}
static void F_26 ( struct V_1 * V_4 )
{
F_6 ( V_49 , V_4 -> V_17 + V_50 ) ;
}
static int F_27 ( struct V_1 * V_4 , T_5 V_51 ,
T_5 V_52 , T_6 V_53 )
{
struct V_54 * V_55 = & V_4 -> V_55 ;
unsigned V_56 ;
T_5 V_57 = ( T_5 ) V_55 -> V_58 * V_59 ;
T_5 V_60 ;
if ( V_53 > V_57 ) {
F_12 ( V_4 -> V_40 ,
L_6 ,
& V_53 , V_57 ) ;
return - V_61 ;
}
F_28 ( V_53 , V_55 -> V_58 , & V_60 ) ;
if ( V_60 ) {
F_12 ( V_4 -> V_40 ,
L_7 ,
& V_53 , & V_55 -> V_58 ) ;
return - V_61 ;
}
if ( V_51 < V_55 -> V_62 ) {
F_12 ( V_4 -> V_40 ,
L_8 ,
& V_51 , & V_55 -> V_62 ) ;
return - V_61 ;
}
V_51 -= V_55 -> V_62 ;
for ( V_56 = 0 ; V_56 < V_59 ; V_56 ++ ) {
F_6 ( F_29 ( V_51 ) | V_63 |
( V_55 -> V_64 ? 1 : 0 ) , V_4 -> V_17 + F_30 ( V_56 ) ) ;
F_6 ( F_31 ( V_51 ) , V_4 -> V_17 + F_32 ( V_56 ) ) ;
F_6 ( F_29 ( V_52 ) , V_4 -> V_17 + F_33 ( V_56 ) ) ;
F_6 ( F_31 ( V_52 ) , V_4 -> V_17 + F_34 ( V_56 ) ) ;
V_53 -= V_55 -> V_58 ;
if ( V_53 == 0 )
break;
V_51 += V_55 -> V_58 ;
V_52 += V_55 -> V_58 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_4 ,
struct V_65 * V_66 )
{
struct V_67 * V_68 ;
int V_69 ;
F_36 (window, resources) {
struct V_70 * V_71 = V_68 -> V_71 ;
T_5 V_72 = F_37 ( V_71 ) ;
switch ( V_72 ) {
case V_73 :
case V_74 :
break;
case V_75 :
V_69 = F_27 ( V_4 , V_71 -> V_76 ,
V_71 -> V_76 - V_68 -> V_77 ,
F_38 ( V_71 ) ) ;
if ( V_69 )
return V_69 ;
break;
default:
F_12 ( V_4 -> V_40 , L_9 , V_71 ) ;
return - V_61 ;
}
}
return 0 ;
}
int F_39 ( struct V_1 * V_4 , struct V_65 * V_71 )
{
int V_69 ;
void * V_7 ;
struct V_2 * V_3 ;
if ( ! V_4 || ! V_4 -> V_40 || ! V_4 -> V_17 )
return - V_61 ;
V_69 = F_40 ( V_4 -> V_78 ) ;
if ( V_69 ) {
F_12 ( V_4 -> V_40 , L_10 ) ;
return V_69 ;
}
V_69 = F_41 ( V_4 -> V_78 ) ;
if ( V_69 ) {
F_12 ( V_4 -> V_40 , L_11 ) ;
goto V_79;
}
F_7 ( V_4 ) ;
if ( V_4 -> V_80 ) {
V_69 = F_35 ( V_4 , V_71 ) ;
if ( V_69 ) {
F_12 ( V_4 -> V_40 , L_12 ) ;
goto V_81;
}
}
#ifdef F_2
V_4 -> V_7 . V_8 = V_4 ;
V_7 = & V_4 -> V_7 ;
#else
V_7 = V_4 ;
#endif
V_3 = F_42 ( V_4 -> V_40 , 0 , & V_82 , V_7 , V_71 ) ;
if ( ! V_3 ) {
F_12 ( V_4 -> V_40 , L_13 ) ;
V_69 = - V_83 ;
goto V_81;
}
V_4 -> V_84 = V_3 ;
V_69 = F_11 ( V_4 , V_3 ) ;
if ( V_69 ) {
F_12 ( V_4 -> V_40 , L_14 ) ;
goto V_85;
}
F_26 ( V_4 ) ;
F_43 ( V_3 ) ;
F_44 ( V_3 ) ;
F_45 ( V_86 , V_4 -> V_87 ) ;
F_46 ( V_3 ) ;
return 0 ;
V_85:
F_47 ( V_3 ) ;
F_48 ( V_3 ) ;
V_81:
F_49 ( V_4 -> V_78 ) ;
V_79:
F_50 ( V_4 -> V_78 ) ;
return V_69 ;
}
int F_51 ( struct V_1 * V_4 )
{
F_47 ( V_4 -> V_84 ) ;
F_48 ( V_4 -> V_84 ) ;
F_49 ( V_4 -> V_78 ) ;
F_50 ( V_4 -> V_78 ) ;
return 0 ;
}
