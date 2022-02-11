static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
T_2 V_6 ;
while ( ( V_2 -> V_7 ) &&
( F_1 ( V_2 , V_8 ) & V_9 ) ) {
V_6 = F_1 ( V_2 , V_10 ) ;
if ( V_2 -> V_11 )
* V_2 -> V_11 ++ = V_6 ;
V_2 -> V_7 -- ;
}
}
static inline void F_6 ( struct V_1 * V_2 )
{
T_2 V_6 ;
while ( ( V_2 -> V_12 ) &&
( F_1 ( V_2 , V_8 ) & V_13 ) ) {
V_6 = V_2 -> V_14 ? * V_2 -> V_14 ++ : 0 ;
F_3 ( V_2 , V_10 , V_6 ) ;
V_2 -> V_12 -- ;
}
}
static void F_7 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
T_1 V_17 = F_1 ( V_2 , V_8 ) ;
V_17 &= ~ ( V_18 |
V_19 |
V_20 ) ;
V_17 |= V_21 | V_22 ;
F_3 ( V_2 , V_8 , V_17 ) ;
}
static T_3 F_9 ( int V_23 , void * V_24 )
{
struct V_15 * V_16 = V_24 ;
struct V_1 * V_2 = F_8 ( V_16 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
if ( F_1 ( V_2 , V_8 ) & V_25 ) {
F_7 ( V_16 ) ;
F_10 ( & V_16 -> V_26 ) ;
}
return V_27 ;
}
static int F_11 ( struct V_15 * V_16 ,
struct V_28 * V_29 ,
struct V_30 * V_31 ,
T_1 V_17 ,
unsigned long V_32 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
unsigned long V_33 = V_34 + V_35 ;
F_3 ( V_2 , V_8 , V_17 | V_20 ) ;
while ( V_2 -> V_7 ) {
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> V_7 && F_12 ( V_34 , V_33 ) ) {
F_7 ( V_16 ) ;
return - V_36 ;
}
}
F_7 ( V_16 ) ;
return 0 ;
}
static int F_13 ( struct V_15 * V_16 ,
struct V_28 * V_29 ,
struct V_30 * V_31 ,
T_1 V_17 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
if ( F_14 ( V_29 -> V_37 ) ) {
F_3 ( V_2 , V_8 ,
V_17 | V_20 ) ;
F_6 ( V_2 ) ;
}
V_17 |= V_18 | V_19 | V_20 ;
F_3 ( V_2 , V_8 , V_17 ) ;
return 1 ;
}
static int F_15 ( struct V_15 * V_16 ,
struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
unsigned long V_38 , V_39 , V_40 ;
unsigned long V_41 , V_32 ;
T_1 V_17 = F_1 ( V_2 , V_8 ) ;
V_38 = V_31 -> V_42 ;
V_39 = F_16 ( V_2 -> V_43 ) ;
if ( V_38 >= V_39 / 2 ) {
V_40 = 2 ;
} else if ( V_38 ) {
V_40 = F_17 ( V_39 , V_38 ) ;
V_40 += ( V_40 % 2 ) ;
if ( V_40 >= 65536 )
V_40 = 0 ;
} else {
V_40 = 0 ;
}
V_41 = V_40 ? ( V_39 / V_40 ) : ( V_39 / 65536 ) ;
F_3 ( V_2 , V_44 , V_40 ) ;
if ( ( V_29 -> V_45 & V_46 ) && ( V_31 -> V_11 ) )
V_17 |= V_47 ;
if ( V_29 -> V_45 & V_48 )
V_17 |= V_49 ;
if ( V_29 -> V_45 & V_50 )
V_17 |= V_51 ;
if ( F_14 ( V_29 -> V_37 ) || ( V_29 -> V_45 & V_52 ) )
V_17 |= V_53 | V_54 ;
V_2 -> V_14 = V_31 -> V_14 ;
V_2 -> V_11 = V_31 -> V_11 ;
V_2 -> V_12 = V_31 -> V_55 ;
V_2 -> V_7 = V_31 -> V_55 ;
V_32 = V_31 -> V_55
* 9
* 1000000 / V_41 ;
if ( V_32 <= V_56 )
return F_11 ( V_16 , V_29 , V_31 ,
V_17 , V_32 ) ;
return F_13 ( V_16 , V_29 , V_31 , V_17 ) ;
}
static void F_18 ( struct V_15 * V_16 ,
struct V_57 * V_58 )
{
F_7 ( V_16 ) ;
}
static void F_19 ( struct V_28 * V_29 , bool V_59 )
{
struct V_15 * V_16 = V_29 -> V_16 ;
struct V_1 * V_2 = F_8 ( V_16 ) ;
T_1 V_17 = F_1 ( V_2 , V_8 ) ;
bool V_60 ;
V_60 = ( V_29 -> V_45 & V_61 ) ? V_59 : ! V_59 ;
if ( V_29 -> V_45 & V_61 ) {
V_17 |= V_62 ;
V_17 |= V_63 << V_29 -> V_64 ;
} else {
V_17 &= ~ V_62 ;
V_17 &= ~ ( V_63 << V_29 -> V_64 ) ;
}
if ( V_60 ) {
if ( V_29 -> V_45 & V_52 ) {
V_17 |= V_53 | V_54 ;
} else {
V_17 &= ~ ( V_53 | V_54 ) ;
V_17 |= V_29 -> V_64 ;
}
} else {
V_17 &= ~ V_62 ;
V_17 |= V_53 | V_54 ;
}
F_3 ( V_2 , V_8 , V_17 ) ;
}
static int F_20 ( struct V_65 * V_66 , void * V_67 )
{
return ! strcmp ( V_66 -> V_68 , V_67 ) ;
}
static int F_21 ( struct V_28 * V_29 )
{
int V_69 ;
struct V_65 * V_66 ;
if ( V_29 -> V_45 & V_52 )
return 0 ;
if ( F_14 ( V_29 -> V_37 ) )
return 0 ;
if ( V_29 -> V_64 > 1 ) {
F_22 ( & V_29 -> V_70 ,
L_1 ) ;
return - V_71 ;
}
V_66 = F_23 ( L_2 , F_20 ) ;
if ( ! V_66 )
return 0 ;
V_29 -> V_37 = V_66 -> V_72 + 8 - V_29 -> V_64 ;
F_24 ( & V_29 -> V_70 , L_3 ,
V_29 -> V_64 , V_29 -> V_37 ) ;
V_69 = F_25 ( V_29 -> V_37 ,
( V_29 -> V_45 & V_61 ) ? 0 : 1 ) ;
if ( V_69 ) {
F_22 ( & V_29 -> V_70 ,
L_4 ,
V_29 -> V_64 , V_29 -> V_37 , V_69 ) ;
return V_69 ;
}
F_26 ( V_29 -> V_37 , ( V_29 -> V_45 & V_61 ) ? 0 : 1 ) ;
return 0 ;
}
static int F_27 ( struct V_73 * V_74 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_75 * V_76 ;
int V_69 ;
V_16 = F_28 ( & V_74 -> V_70 , sizeof( * V_2 ) ) ;
if ( ! V_16 ) {
F_22 ( & V_74 -> V_70 , L_5 ) ;
return - V_77 ;
}
F_29 ( V_74 , V_16 ) ;
V_16 -> V_78 = V_79 ;
V_16 -> V_80 = F_30 ( 8 ) ;
V_16 -> V_81 = 3 ;
V_16 -> V_82 = F_21 ;
V_16 -> V_83 = F_19 ;
V_16 -> V_84 = F_15 ;
V_16 -> V_85 = F_18 ;
V_16 -> V_70 . V_86 = V_74 -> V_70 . V_86 ;
V_2 = F_8 ( V_16 ) ;
V_76 = F_31 ( V_74 , V_87 , 0 ) ;
V_2 -> V_4 = F_32 ( & V_74 -> V_70 , V_76 ) ;
if ( F_33 ( V_2 -> V_4 ) ) {
V_69 = F_34 ( V_2 -> V_4 ) ;
goto V_88;
}
V_2 -> V_43 = F_35 ( & V_74 -> V_70 , NULL ) ;
if ( F_33 ( V_2 -> V_43 ) ) {
V_69 = F_34 ( V_2 -> V_43 ) ;
F_22 ( & V_74 -> V_70 , L_6 , V_69 ) ;
goto V_88;
}
V_2 -> V_23 = F_36 ( V_74 -> V_70 . V_86 , 0 ) ;
if ( V_2 -> V_23 <= 0 ) {
F_22 ( & V_74 -> V_70 , L_7 , V_2 -> V_23 ) ;
V_69 = V_2 -> V_23 ? V_2 -> V_23 : - V_89 ;
goto V_88;
}
F_37 ( V_2 -> V_43 ) ;
V_69 = F_38 ( & V_74 -> V_70 , V_2 -> V_23 , F_9 , 0 ,
F_39 ( & V_74 -> V_70 ) , V_16 ) ;
if ( V_69 ) {
F_22 ( & V_74 -> V_70 , L_8 , V_69 ) ;
goto V_90;
}
F_3 ( V_2 , V_8 ,
V_21 | V_22 ) ;
V_69 = F_40 ( & V_74 -> V_70 , V_16 ) ;
if ( V_69 ) {
F_22 ( & V_74 -> V_70 , L_9 , V_69 ) ;
goto V_90;
}
return 0 ;
V_90:
F_41 ( V_2 -> V_43 ) ;
V_88:
F_42 ( V_16 ) ;
return V_69 ;
}
static int F_43 ( struct V_73 * V_74 )
{
struct V_15 * V_16 = F_44 ( V_74 ) ;
struct V_1 * V_2 = F_8 ( V_16 ) ;
F_3 ( V_2 , V_8 ,
V_21 | V_22 ) ;
F_41 ( V_2 -> V_43 ) ;
return 0 ;
}
