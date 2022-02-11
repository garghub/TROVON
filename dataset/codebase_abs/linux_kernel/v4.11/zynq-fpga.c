static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( const struct V_1 * V_2 ,
T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_6 )
{
F_1 ( V_2 , V_7 , ~ V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_8 ;
T_1 V_9 ;
bool V_10 ;
V_10 = V_2 -> V_11 == 0 ;
while ( V_2 -> V_12 ) {
if ( F_3 ( V_2 , V_13 ) & V_14 )
break;
V_8 = F_7 ( V_2 -> V_12 ) ;
V_9 = F_8 ( V_2 -> V_12 ) ;
if ( V_2 -> V_11 + 1 == V_2 -> V_15 ) {
V_8 |= V_16 ;
V_2 -> V_12 = NULL ;
} else {
V_2 -> V_12 = F_9 ( V_2 -> V_12 ) ;
V_2 -> V_11 ++ ;
}
F_1 ( V_2 , V_17 , V_8 ) ;
F_1 ( V_2 , V_18 , V_19 ) ;
F_1 ( V_2 , V_20 , V_9 / 4 ) ;
F_1 ( V_2 , V_21 , 0 ) ;
}
if ( V_10 && V_2 -> V_12 ) {
F_5 ( V_2 ,
V_22 | V_23 ) ;
} else if ( ! V_2 -> V_12 ) {
F_5 ( V_2 ,
V_24 | V_23 ) ;
}
}
static T_2 F_10 ( int V_25 , void * V_26 )
{
struct V_1 * V_2 = V_26 ;
T_1 V_27 ;
F_11 ( & V_2 -> V_28 ) ;
V_27 = F_3 ( V_2 , V_29 ) ;
if ( ! ( V_27 & V_23 ) &&
( V_27 & V_22 ) && V_2 -> V_12 ) {
F_1 ( V_2 , V_29 , V_22 ) ;
F_6 ( V_2 ) ;
F_12 ( & V_2 -> V_28 ) ;
return V_30 ;
}
F_12 ( & V_2 -> V_28 ) ;
F_5 ( V_2 , 0 ) ;
F_13 ( & V_2 -> V_31 ) ;
return V_30 ;
}
static bool F_14 ( const T_3 * V_32 , T_4 V_33 )
{
for (; V_33 >= 4 ; V_32 += 4 , V_33 -= 4 )
if ( V_32 [ 0 ] == 0x66 && V_32 [ 1 ] == 0x55 && V_32 [ 2 ] == 0x99 &&
V_32 [ 3 ] == 0xaa )
return true ;
return false ;
}
static int F_15 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
const char * V_32 , T_4 V_33 )
{
struct V_1 * V_2 ;
T_1 V_38 , V_39 ;
int V_40 ;
V_2 = V_35 -> V_2 ;
V_40 = F_16 ( V_2 -> V_41 ) ;
if ( V_40 )
return V_40 ;
if ( ! ( V_37 -> V_42 & V_43 ) ) {
if ( ! F_14 ( V_32 , V_33 ) ) {
F_17 ( & V_35 -> V_44 ,
L_1 ) ;
V_40 = - V_45 ;
goto V_46;
}
F_18 ( V_2 -> V_47 , V_48 ,
V_49 ) ;
F_18 ( V_2 -> V_47 , V_50 ,
V_51 ) ;
F_18 ( V_2 -> V_47 , V_50 ,
V_52 ) ;
V_38 = F_3 ( V_2 , V_53 ) ;
V_38 |= V_54 ;
F_1 ( V_2 , V_53 , V_38 ) ;
V_40 = F_19 ( V_2 , V_13 , V_39 ,
V_39 & V_55 ,
V_56 ,
V_57 ) ;
if ( V_40 ) {
F_17 ( & V_35 -> V_44 , L_2 ) ;
goto V_46;
}
V_38 = F_3 ( V_2 , V_53 ) ;
V_38 &= ~ V_54 ;
F_1 ( V_2 , V_53 , V_38 ) ;
V_40 = F_19 ( V_2 , V_13 , V_39 ,
! ( V_39 & V_55 ) ,
V_56 ,
V_57 ) ;
if ( V_40 ) {
F_17 ( & V_35 -> V_44 , L_3 ) ;
goto V_46;
}
V_38 = F_3 ( V_2 , V_53 ) ;
V_38 |= V_54 ;
F_1 ( V_2 , V_53 , V_38 ) ;
V_40 = F_19 ( V_2 , V_13 , V_39 ,
V_39 & V_55 ,
V_56 ,
V_57 ) ;
if ( V_40 ) {
F_17 ( & V_35 -> V_44 , L_2 ) ;
goto V_46;
}
}
V_38 = F_3 ( V_2 , V_53 ) ;
F_1 ( V_2 , V_53 ,
( V_58 | V_59 | V_38 ) ) ;
V_39 = F_3 ( V_2 , V_13 ) ;
if ( ( V_39 & V_14 ) ||
( V_39 & V_60 ) != V_60 ) {
F_17 ( & V_35 -> V_44 , L_4 ) ;
V_40 = - V_61 ;
goto V_46;
}
V_38 = F_3 ( V_2 , V_62 ) ;
F_1 ( V_2 , V_62 , ( ~ V_63 & V_38 ) ) ;
F_20 ( V_2 -> V_41 ) ;
return 0 ;
V_46:
F_20 ( V_2 -> V_41 ) ;
return V_40 ;
}
static int F_21 ( struct V_34 * V_35 , struct V_64 * V_65 )
{
struct V_1 * V_2 ;
const char * V_66 ;
int V_40 ;
T_1 V_27 ;
unsigned long V_67 ;
unsigned long V_42 ;
struct V_68 * V_69 ;
int V_70 ;
V_2 = V_35 -> V_2 ;
F_22 (sgt->sgl, sg, sgt->nents, i) {
if ( ( V_69 -> V_3 % 8 ) || ( V_69 -> V_71 % 4 ) ) {
F_17 ( & V_35 -> V_44 ,
L_5 ) ;
return - V_45 ;
}
}
V_2 -> V_15 =
F_23 ( V_35 -> V_44 . V_72 , V_65 -> V_73 , V_65 -> V_74 , V_75 ) ;
if ( V_2 -> V_15 == 0 ) {
F_17 ( & V_35 -> V_44 , L_6 ) ;
return - V_76 ;
}
V_40 = F_16 ( V_2 -> V_41 ) ;
if ( V_40 )
goto V_77;
F_1 ( V_2 , V_29 , V_78 ) ;
F_24 ( & V_2 -> V_31 ) ;
F_25 ( & V_2 -> V_28 , V_42 ) ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = V_65 -> V_73 ;
F_6 ( V_2 ) ;
F_26 ( & V_2 -> V_28 , V_42 ) ;
V_67 = F_27 ( & V_2 -> V_31 ,
F_28 ( V_79 ) ) ;
F_25 ( & V_2 -> V_28 , V_42 ) ;
F_5 ( V_2 , 0 ) ;
V_2 -> V_12 = NULL ;
F_26 ( & V_2 -> V_28 , V_42 ) ;
V_27 = F_3 ( V_2 , V_29 ) ;
F_1 ( V_2 , V_29 , V_78 ) ;
if ( V_27 & V_23 ) {
V_66 = L_7 ;
V_40 = - V_80 ;
goto V_81;
}
if ( V_2 -> V_12 ||
! ( ( V_27 & V_24 ) == V_24 ) ) {
if ( V_67 == 0 )
V_66 = L_8 ;
else
V_66 = L_9 ;
V_40 = - V_80 ;
goto V_81;
}
V_40 = 0 ;
goto V_82;
V_81:
F_17 ( & V_35 -> V_44 ,
L_10 ,
V_66 ,
V_27 ,
F_3 ( V_2 , V_53 ) ,
F_3 ( V_2 , V_83 ) ,
F_3 ( V_2 , V_7 ) ,
F_3 ( V_2 , V_13 ) ,
F_3 ( V_2 , V_62 ) ) ;
V_82:
F_20 ( V_2 -> V_41 ) ;
V_77:
F_29 ( V_35 -> V_44 . V_72 , V_65 -> V_73 , V_65 -> V_74 , V_75 ) ;
return V_40 ;
}
static int F_30 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
int V_40 ;
T_1 V_27 ;
V_40 = F_16 ( V_2 -> V_41 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_19 ( V_2 , V_29 , V_27 ,
V_27 & V_84 ,
V_56 ,
V_57 ) ;
F_20 ( V_2 -> V_41 ) ;
if ( V_40 )
return V_40 ;
if ( ! ( V_37 -> V_42 & V_43 ) ) {
F_18 ( V_2 -> V_47 , V_50 ,
V_85 ) ;
F_18 ( V_2 -> V_47 , V_48 ,
V_86 ) ;
}
return 0 ;
}
static enum V_87 F_31 ( struct V_34 * V_35 )
{
int V_40 ;
T_1 V_27 ;
struct V_1 * V_2 ;
V_2 = V_35 -> V_2 ;
V_40 = F_16 ( V_2 -> V_41 ) ;
if ( V_40 )
return V_88 ;
V_27 = F_3 ( V_2 , V_29 ) ;
F_20 ( V_2 -> V_41 ) ;
if ( V_27 & V_84 )
return V_89 ;
return V_88 ;
}
static int F_32 ( struct V_90 * V_91 )
{
struct V_92 * V_44 = & V_91 -> V_44 ;
struct V_1 * V_2 ;
struct V_93 * V_94 ;
int V_40 ;
V_2 = F_33 ( V_44 , sizeof( * V_2 ) , V_95 ) ;
if ( ! V_2 )
return - V_76 ;
F_34 ( & V_2 -> V_28 ) ;
V_94 = F_35 ( V_91 , V_96 , 0 ) ;
V_2 -> V_5 = F_36 ( V_44 , V_94 ) ;
if ( F_37 ( V_2 -> V_5 ) )
return F_38 ( V_2 -> V_5 ) ;
V_2 -> V_47 = F_39 ( V_44 -> V_97 ,
L_11 ) ;
if ( F_37 ( V_2 -> V_47 ) ) {
F_17 ( V_44 , L_12 ) ;
return F_38 ( V_2 -> V_47 ) ;
}
F_40 ( & V_2 -> V_31 ) ;
V_2 -> V_25 = F_41 ( V_91 , 0 ) ;
if ( V_2 -> V_25 < 0 ) {
F_17 ( V_44 , L_13 ) ;
return V_2 -> V_25 ;
}
V_2 -> V_41 = F_42 ( V_44 , L_14 ) ;
if ( F_37 ( V_2 -> V_41 ) ) {
F_17 ( V_44 , L_15 ) ;
return F_38 ( V_2 -> V_41 ) ;
}
V_40 = F_43 ( V_2 -> V_41 ) ;
if ( V_40 ) {
F_17 ( V_44 , L_16 ) ;
return V_40 ;
}
F_1 ( V_2 , V_98 , V_99 ) ;
F_5 ( V_2 , 0 ) ;
F_1 ( V_2 , V_29 , V_78 ) ;
V_40 = F_44 ( V_44 , V_2 -> V_25 , F_10 , 0 , F_45 ( V_44 ) ,
V_2 ) ;
if ( V_40 ) {
F_17 ( V_44 , L_17 ) ;
F_46 ( V_2 -> V_41 ) ;
return V_40 ;
}
F_20 ( V_2 -> V_41 ) ;
V_40 = F_47 ( V_44 , L_18 ,
& V_100 , V_2 ) ;
if ( V_40 ) {
F_17 ( V_44 , L_19 ) ;
F_48 ( V_2 -> V_41 ) ;
return V_40 ;
}
return 0 ;
}
static int F_49 ( struct V_90 * V_91 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
V_35 = F_50 ( V_91 ) ;
V_2 = V_35 -> V_2 ;
F_51 ( & V_91 -> V_44 ) ;
F_48 ( V_2 -> V_41 ) ;
return 0 ;
}
