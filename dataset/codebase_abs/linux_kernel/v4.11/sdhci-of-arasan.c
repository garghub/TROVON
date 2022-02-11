static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
T_1 V_12 = V_4 -> V_12 ;
T_2 V_13 = V_4 -> V_13 ;
T_3 V_14 = V_4 -> V_14 ;
int V_15 ;
if ( V_14 < 0 )
return - V_16 ;
if ( V_9 -> V_17 -> V_18 )
V_15 = F_4 ( V_11 , V_12 ,
F_5 ( V_5 , F_6 ( V_13 , 0 ) ,
V_14 ) ) ;
else
V_15 = F_7 ( V_11 , V_12 ,
F_6 ( V_14 + V_13 , V_14 ) ,
V_5 << V_14 ) ;
if ( V_15 )
F_8 ( L_1 ,
F_9 ( V_2 -> V_19 ) , V_15 ) ;
return V_15 ;
}
static unsigned int F_10 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_20 = F_11 ( F_12 ( V_7 -> V_21 ) , 1000 ) ;
if ( V_2 -> V_22 & V_23 )
V_20 = F_11 ( V_20 , 1000 ) ;
return V_20 ;
}
static void F_13 ( struct V_1 * V_2 , unsigned int clock )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
bool V_24 = false ;
if ( ! F_14 ( V_9 -> V_25 ) ) {
if ( ! V_9 -> V_26 && clock <= V_27 ) {
F_15 ( V_2 , V_2 -> V_28 ) ;
F_16 ( & V_2 -> V_29 ) ;
F_17 ( V_9 -> V_25 ) ;
F_18 ( & V_2 -> V_29 ) ;
V_9 -> V_26 = true ;
} else if ( clock > V_27 ) {
V_24 = true ;
}
}
if ( V_24 && V_9 -> V_26 ) {
F_16 ( & V_2 -> V_29 ) ;
F_19 ( V_9 -> V_25 ) ;
F_18 ( & V_2 -> V_29 ) ;
V_9 -> V_26 = false ;
}
F_15 ( V_2 , clock ) ;
if ( V_24 ) {
F_16 ( & V_2 -> V_29 ) ;
F_17 ( V_9 -> V_25 ) ;
F_18 ( & V_2 -> V_29 ) ;
V_9 -> V_26 = true ;
}
}
static void F_20 ( struct V_30 * V_19 ,
struct V_31 * V_32 )
{
T_1 V_33 ;
struct V_1 * V_2 = F_21 ( V_19 ) ;
V_33 = F_22 ( V_2 -> V_34 + V_35 ) ;
if ( V_32 -> V_36 )
V_33 |= V_37 ;
else
V_33 &= ~ V_37 ;
F_23 ( V_33 , V_2 -> V_34 + V_35 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_4 V_38 )
{
T_4 V_39 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_25 ( V_2 , V_38 ) ;
if ( V_9 -> V_40 & V_41 ) {
V_39 = F_26 ( V_2 , V_42 ) ;
V_39 |= V_43 | V_44 ;
F_27 ( V_2 , V_39 , V_42 ) ;
}
}
static int F_28 ( struct V_30 * V_19 ,
struct V_31 * V_32 )
{
switch ( V_32 -> V_45 ) {
case V_46 :
return 0 ;
case V_47 :
case V_48 :
break;
}
return - V_16 ;
}
static int F_29 ( struct V_49 * V_50 )
{
struct V_51 * V_52 = F_30 ( V_50 ) ;
struct V_1 * V_2 = F_31 ( V_52 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_15 ;
V_15 = F_32 ( V_2 ) ;
if ( V_15 )
return V_15 ;
if ( ! F_14 ( V_9 -> V_25 ) && V_9 -> V_26 ) {
V_15 = F_19 ( V_9 -> V_25 ) ;
if ( V_15 ) {
F_33 ( V_50 , L_2 ) ;
F_34 ( V_2 ) ;
return V_15 ;
}
V_9 -> V_26 = false ;
}
F_35 ( V_7 -> V_21 ) ;
F_35 ( V_9 -> V_53 ) ;
return 0 ;
}
static int F_36 ( struct V_49 * V_50 )
{
struct V_51 * V_52 = F_30 ( V_50 ) ;
struct V_1 * V_2 = F_31 ( V_52 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_15 ;
V_15 = F_37 ( V_9 -> V_53 ) ;
if ( V_15 ) {
F_33 ( V_50 , L_3 ) ;
return V_15 ;
}
V_15 = F_37 ( V_7 -> V_21 ) ;
if ( V_15 ) {
F_33 ( V_50 , L_4 ) ;
return V_15 ;
}
if ( ! F_14 ( V_9 -> V_25 ) && V_2 -> V_19 -> V_54 ) {
V_15 = F_17 ( V_9 -> V_25 ) ;
if ( V_15 ) {
F_33 ( V_50 , L_5 ) ;
return V_15 ;
}
V_9 -> V_26 = true ;
}
return F_34 ( V_2 ) ;
}
static unsigned long F_38 ( struct V_55 * V_56 ,
unsigned long V_57 )
{
struct V_8 * V_9 =
F_39 ( V_56 , struct V_8 , V_58 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
return V_2 -> V_19 -> V_54 ;
}
static void F_40 ( struct V_1 * V_2 ,
T_1 V_59 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
const struct V_60 * V_17 =
V_9 -> V_17 ;
if ( ! V_17 )
return;
if ( ! V_9 -> V_11 ) {
F_8 ( L_6 ,
F_9 ( V_2 -> V_19 ) ) ;
return;
}
F_1 ( V_2 , & V_17 -> V_61 , V_59 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
const struct V_60 * V_17 =
V_9 -> V_17 ;
T_1 V_62 = F_42 ( F_12 ( V_7 -> V_21 ) , 1000000 ) ;
if ( ! V_17 )
return;
if ( ! V_9 -> V_11 ) {
F_8 ( L_6 ,
F_9 ( V_2 -> V_19 ) ) ;
return;
}
F_1 ( V_2 , & V_17 -> V_63 , V_62 ) ;
}
static int F_43 ( struct V_8 * V_9 ,
struct V_21 * V_64 ,
struct V_49 * V_50 )
{
struct V_65 * V_66 = V_50 -> V_67 ;
struct V_68 V_69 ;
const char * V_70 ;
int V_15 ;
if ( ! F_44 ( V_66 , L_7 , NULL ) )
return 0 ;
V_15 = F_45 ( V_66 , L_8 , 0 ,
& V_69 . V_71 ) ;
if ( V_15 ) {
F_33 ( V_50 , L_9 ) ;
return V_15 ;
}
V_70 = F_46 ( V_64 ) ;
V_69 . V_72 = & V_70 ;
V_69 . V_73 = 1 ;
V_69 . V_74 = V_75 ;
V_69 . V_76 = & V_77 ;
V_9 -> V_58 . V_78 = & V_69 ;
V_9 -> V_79 =
F_47 ( V_50 , & V_9 -> V_58 ) ;
V_9 -> V_58 . V_78 = NULL ;
V_15 = F_48 ( V_66 , V_80 ,
V_9 -> V_79 ) ;
if ( V_15 )
F_33 ( V_50 , L_10 ) ;
return V_15 ;
}
static void F_49 ( struct V_49 * V_50 )
{
struct V_65 * V_66 = V_50 -> V_67 ;
if ( ! F_44 ( V_66 , L_7 , NULL ) )
return;
F_50 ( V_50 -> V_67 ) ;
}
static int F_51 ( struct V_51 * V_52 )
{
int V_15 ;
const struct V_81 * V_82 ;
struct V_65 * V_83 ;
struct V_21 * V_64 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_65 * V_66 = V_52 -> V_50 . V_67 ;
V_2 = F_52 ( V_52 , & V_84 ,
sizeof( * V_9 ) ) ;
if ( F_14 ( V_2 ) )
return F_53 ( V_2 ) ;
V_7 = F_2 ( V_2 ) ;
V_9 = F_3 ( V_7 ) ;
V_9 -> V_2 = V_2 ;
V_82 = F_54 ( V_85 , V_52 -> V_50 . V_67 ) ;
V_9 -> V_17 = V_82 -> V_86 ;
V_83 = F_55 ( V_52 -> V_50 . V_67 , L_11 , 0 ) ;
if ( V_83 ) {
V_9 -> V_11 = F_56 ( V_83 ) ;
F_57 ( V_83 ) ;
if ( F_14 ( V_9 -> V_11 ) ) {
V_15 = F_53 ( V_9 -> V_11 ) ;
if ( V_15 != - V_87 )
F_33 ( & V_52 -> V_50 , L_12 ,
V_15 ) ;
goto V_88;
}
}
V_9 -> V_53 = F_58 ( & V_52 -> V_50 , L_13 ) ;
if ( F_14 ( V_9 -> V_53 ) ) {
F_33 ( & V_52 -> V_50 , L_14 ) ;
V_15 = F_53 ( V_9 -> V_53 ) ;
goto V_88;
}
V_64 = F_58 ( & V_52 -> V_50 , L_15 ) ;
if ( F_14 ( V_64 ) ) {
F_33 ( & V_52 -> V_50 , L_16 ) ;
V_15 = F_53 ( V_64 ) ;
goto V_88;
}
V_15 = F_59 ( V_9 -> V_53 ) ;
if ( V_15 ) {
F_33 ( & V_52 -> V_50 , L_17 ) ;
goto V_88;
}
V_15 = F_59 ( V_64 ) ;
if ( V_15 ) {
F_33 ( & V_52 -> V_50 , L_18 ) ;
goto V_89;
}
F_60 ( V_52 ) ;
if ( F_61 ( V_66 , L_19 ) )
V_9 -> V_40 |= V_41 ;
V_7 -> V_21 = V_64 ;
if ( F_62 ( V_52 -> V_50 . V_67 ,
L_20 ) )
F_40 ( V_2 , 0x0 ) ;
F_41 ( V_2 ) ;
V_15 = F_43 ( V_9 , V_64 , & V_52 -> V_50 ) ;
if ( V_15 )
goto V_90;
V_15 = F_63 ( V_2 -> V_19 ) ;
if ( V_15 ) {
F_33 ( & V_52 -> V_50 , L_21 , V_15 ) ;
goto V_91;
}
V_9 -> V_25 = F_64 ( - V_92 ) ;
if ( F_62 ( V_52 -> V_50 . V_67 ,
L_22 ) ) {
V_9 -> V_25 = F_65 ( & V_52 -> V_50 ,
L_23 ) ;
if ( F_14 ( V_9 -> V_25 ) ) {
V_15 = F_53 ( V_9 -> V_25 ) ;
F_33 ( & V_52 -> V_50 , L_24 ) ;
goto V_91;
}
V_15 = F_66 ( V_9 -> V_25 ) ;
if ( V_15 < 0 ) {
F_33 ( & V_52 -> V_50 , L_25 ) ;
goto V_91;
}
V_2 -> V_93 . V_94 =
F_20 ;
V_2 -> V_93 . V_95 =
F_28 ;
}
V_15 = F_67 ( V_2 ) ;
if ( V_15 )
goto V_96;
return 0 ;
V_96:
if ( ! F_14 ( V_9 -> V_25 ) )
F_68 ( V_9 -> V_25 ) ;
V_91:
F_49 ( & V_52 -> V_50 ) ;
V_90:
F_69 ( V_64 ) ;
V_89:
F_69 ( V_9 -> V_53 ) ;
V_88:
F_70 ( V_52 ) ;
return V_15 ;
}
static int F_71 ( struct V_51 * V_52 )
{
int V_15 ;
struct V_1 * V_2 = F_31 ( V_52 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_21 * V_53 = V_9 -> V_53 ;
if ( ! F_14 ( V_9 -> V_25 ) ) {
if ( V_9 -> V_26 )
F_19 ( V_9 -> V_25 ) ;
F_68 ( V_9 -> V_25 ) ;
}
F_49 ( & V_52 -> V_50 ) ;
V_15 = F_72 ( V_52 ) ;
F_69 ( V_53 ) ;
return V_15 ;
}
