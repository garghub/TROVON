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
T_1 div ;
unsigned long V_20 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
div = F_11 ( V_2 -> V_21 + V_22 ) ;
div = ( div & V_23 ) >> V_24 ;
V_20 = F_12 ( V_7 -> V_25 ) ;
V_20 /= 1 << ( V_26 + div ) ;
return V_20 ;
}
static void F_13 ( struct V_1 * V_2 , unsigned int clock )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
bool V_27 = false ;
if ( ! F_14 ( V_9 -> V_28 ) ) {
if ( ! V_9 -> V_29 && clock <= V_30 ) {
F_15 ( V_2 , V_2 -> V_31 ) ;
F_16 ( & V_2 -> V_32 ) ;
F_17 ( V_9 -> V_28 ) ;
F_18 ( & V_2 -> V_32 ) ;
V_9 -> V_29 = true ;
} else if ( clock > V_30 ) {
V_27 = true ;
}
}
if ( V_27 && V_9 -> V_29 ) {
F_16 ( & V_2 -> V_32 ) ;
F_19 ( V_9 -> V_28 ) ;
F_18 ( & V_2 -> V_32 ) ;
V_9 -> V_29 = false ;
}
F_15 ( V_2 , clock ) ;
if ( V_27 ) {
F_16 ( & V_2 -> V_32 ) ;
F_17 ( V_9 -> V_28 ) ;
F_18 ( & V_2 -> V_32 ) ;
V_9 -> V_29 = true ;
}
}
static void F_20 ( struct V_33 * V_19 ,
struct V_34 * V_35 )
{
T_1 V_36 ;
struct V_1 * V_2 = F_21 ( V_19 ) ;
V_36 = F_11 ( V_2 -> V_21 + V_37 ) ;
if ( V_35 -> V_38 )
V_36 |= V_39 ;
else
V_36 &= ~ V_39 ;
F_22 ( V_36 , V_2 -> V_21 + V_37 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_4 V_40 )
{
T_4 V_41 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_24 ( V_2 , V_40 ) ;
if ( V_9 -> V_42 & V_43 ) {
V_41 = F_25 ( V_2 , V_44 ) ;
V_41 |= V_45 | V_46 ;
F_26 ( V_2 , V_41 , V_44 ) ;
}
}
static int F_27 ( struct V_33 * V_19 ,
struct V_34 * V_35 )
{
switch ( V_35 -> V_47 ) {
case V_48 :
return 0 ;
case V_49 :
case V_50 :
break;
}
return - V_16 ;
}
static int F_28 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_29 ( V_52 ) ;
struct V_1 * V_2 = F_30 ( V_54 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_15 ;
V_15 = F_31 ( V_2 ) ;
if ( V_15 )
return V_15 ;
if ( ! F_14 ( V_9 -> V_28 ) && V_9 -> V_29 ) {
V_15 = F_19 ( V_9 -> V_28 ) ;
if ( V_15 ) {
F_32 ( V_52 , L_2 ) ;
F_33 ( V_2 ) ;
return V_15 ;
}
V_9 -> V_29 = false ;
}
F_34 ( V_7 -> V_25 ) ;
F_34 ( V_9 -> V_55 ) ;
return 0 ;
}
static int F_35 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_29 ( V_52 ) ;
struct V_1 * V_2 = F_30 ( V_54 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_15 ;
V_15 = F_36 ( V_9 -> V_55 ) ;
if ( V_15 ) {
F_32 ( V_52 , L_3 ) ;
return V_15 ;
}
V_15 = F_36 ( V_7 -> V_25 ) ;
if ( V_15 ) {
F_32 ( V_52 , L_4 ) ;
return V_15 ;
}
if ( ! F_14 ( V_9 -> V_28 ) && V_2 -> V_19 -> V_56 ) {
V_15 = F_17 ( V_9 -> V_28 ) ;
if ( V_15 ) {
F_32 ( V_52 , L_5 ) ;
return V_15 ;
}
V_9 -> V_29 = true ;
}
return F_33 ( V_2 ) ;
}
static unsigned long F_37 ( struct V_57 * V_58 ,
unsigned long V_59 )
{
struct V_8 * V_9 =
F_38 ( V_58 , struct V_8 , V_60 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
return V_2 -> V_19 -> V_56 ;
}
static void F_39 ( struct V_1 * V_2 ,
T_1 V_61 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
const struct V_62 * V_17 =
V_9 -> V_17 ;
if ( ! V_17 )
return;
if ( ! V_9 -> V_11 ) {
F_8 ( L_6 ,
F_9 ( V_2 -> V_19 ) ) ;
return;
}
F_1 ( V_2 , & V_17 -> V_63 , V_61 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
const struct V_62 * V_17 =
V_9 -> V_17 ;
T_1 V_64 = F_41 ( F_12 ( V_7 -> V_25 ) , 1000000 ) ;
if ( ! V_17 )
return;
if ( ! V_9 -> V_11 ) {
F_8 ( L_6 ,
F_9 ( V_2 -> V_19 ) ) ;
return;
}
F_1 ( V_2 , & V_17 -> V_65 , V_64 ) ;
}
static int F_42 ( struct V_8 * V_9 ,
struct V_25 * V_66 ,
struct V_51 * V_52 )
{
struct V_67 * V_68 = V_52 -> V_69 ;
struct V_70 V_71 ;
const char * V_72 ;
int V_15 ;
if ( ! F_43 ( V_68 , L_7 , NULL ) )
return 0 ;
V_15 = F_44 ( V_68 , L_8 , 0 ,
& V_71 . V_73 ) ;
if ( V_15 ) {
F_32 ( V_52 , L_9 ) ;
return V_15 ;
}
V_72 = F_45 ( V_66 ) ;
V_71 . V_74 = & V_72 ;
V_71 . V_75 = 1 ;
V_71 . V_76 = V_77 ;
V_71 . V_78 = & V_79 ;
V_9 -> V_60 . V_80 = & V_71 ;
V_9 -> V_81 =
F_46 ( V_52 , & V_9 -> V_60 ) ;
V_9 -> V_60 . V_80 = NULL ;
V_15 = F_47 ( V_68 , V_82 ,
V_9 -> V_81 ) ;
if ( V_15 )
F_32 ( V_52 , L_10 ) ;
return V_15 ;
}
static void F_48 ( struct V_51 * V_52 )
{
struct V_67 * V_68 = V_52 -> V_69 ;
if ( ! F_43 ( V_68 , L_7 , NULL ) )
return;
F_49 ( V_52 -> V_69 ) ;
}
static int F_50 ( struct V_53 * V_54 )
{
int V_15 ;
const struct V_83 * V_84 ;
struct V_67 * V_85 ;
struct V_25 * V_66 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_67 * V_68 = V_54 -> V_52 . V_69 ;
V_2 = F_51 ( V_54 , & V_86 ,
sizeof( * V_9 ) ) ;
if ( F_14 ( V_2 ) )
return F_52 ( V_2 ) ;
V_7 = F_2 ( V_2 ) ;
V_9 = F_3 ( V_7 ) ;
V_9 -> V_2 = V_2 ;
V_84 = F_53 ( V_87 , V_54 -> V_52 . V_69 ) ;
V_9 -> V_17 = V_84 -> V_88 ;
V_85 = F_54 ( V_54 -> V_52 . V_69 , L_11 , 0 ) ;
if ( V_85 ) {
V_9 -> V_11 = F_55 ( V_85 ) ;
F_56 ( V_85 ) ;
if ( F_14 ( V_9 -> V_11 ) ) {
V_15 = F_52 ( V_9 -> V_11 ) ;
if ( V_15 != - V_89 )
F_32 ( & V_54 -> V_52 , L_12 ,
V_15 ) ;
goto V_90;
}
}
V_9 -> V_55 = F_57 ( & V_54 -> V_52 , L_13 ) ;
if ( F_14 ( V_9 -> V_55 ) ) {
F_32 ( & V_54 -> V_52 , L_14 ) ;
V_15 = F_52 ( V_9 -> V_55 ) ;
goto V_90;
}
V_66 = F_57 ( & V_54 -> V_52 , L_15 ) ;
if ( F_14 ( V_66 ) ) {
F_32 ( & V_54 -> V_52 , L_16 ) ;
V_15 = F_52 ( V_66 ) ;
goto V_90;
}
V_15 = F_58 ( V_9 -> V_55 ) ;
if ( V_15 ) {
F_32 ( & V_54 -> V_52 , L_17 ) ;
goto V_90;
}
V_15 = F_58 ( V_66 ) ;
if ( V_15 ) {
F_32 ( & V_54 -> V_52 , L_18 ) ;
goto V_91;
}
F_59 ( V_54 ) ;
if ( F_60 ( V_68 , L_19 ) )
V_9 -> V_42 |= V_43 ;
V_7 -> V_25 = V_66 ;
if ( F_61 ( V_54 -> V_52 . V_69 ,
L_20 ) )
F_39 ( V_2 , 0x0 ) ;
F_40 ( V_2 ) ;
V_15 = F_42 ( V_9 , V_66 , & V_54 -> V_52 ) ;
if ( V_15 )
goto V_92;
V_15 = F_62 ( V_2 -> V_19 ) ;
if ( V_15 ) {
F_32 ( & V_54 -> V_52 , L_21 , V_15 ) ;
goto V_93;
}
V_9 -> V_28 = F_63 ( - V_94 ) ;
if ( F_61 ( V_54 -> V_52 . V_69 ,
L_22 ) ) {
V_9 -> V_28 = F_64 ( & V_54 -> V_52 ,
L_23 ) ;
if ( F_14 ( V_9 -> V_28 ) ) {
V_15 = F_52 ( V_9 -> V_28 ) ;
F_32 ( & V_54 -> V_52 , L_24 ) ;
goto V_93;
}
V_15 = F_65 ( V_9 -> V_28 ) ;
if ( V_15 < 0 ) {
F_32 ( & V_54 -> V_52 , L_25 ) ;
goto V_93;
}
V_2 -> V_95 . V_96 =
F_20 ;
V_2 -> V_95 . V_97 =
F_27 ;
}
V_15 = F_66 ( V_2 ) ;
if ( V_15 )
goto V_98;
return 0 ;
V_98:
if ( ! F_14 ( V_9 -> V_28 ) )
F_67 ( V_9 -> V_28 ) ;
V_93:
F_48 ( & V_54 -> V_52 ) ;
V_92:
F_68 ( V_66 ) ;
V_91:
F_68 ( V_9 -> V_55 ) ;
V_90:
F_69 ( V_54 ) ;
return V_15 ;
}
static int F_70 ( struct V_53 * V_54 )
{
int V_15 ;
struct V_1 * V_2 = F_30 ( V_54 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_25 * V_55 = V_9 -> V_55 ;
if ( ! F_14 ( V_9 -> V_28 ) ) {
if ( V_9 -> V_29 )
F_19 ( V_9 -> V_28 ) ;
F_67 ( V_9 -> V_28 ) ;
}
F_48 ( & V_54 -> V_52 ) ;
V_15 = F_71 ( V_54 ) ;
F_68 ( V_55 ) ;
return V_15 ;
}
