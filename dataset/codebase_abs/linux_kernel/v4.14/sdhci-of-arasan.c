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
static void F_10 ( struct V_1 * V_2 , unsigned int clock )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
bool V_20 = false ;
if ( ! F_11 ( V_9 -> V_21 ) ) {
if ( ! V_9 -> V_22 && clock <= V_23 ) {
F_12 ( V_2 , V_2 -> V_24 ) ;
F_13 ( V_9 -> V_21 ) ;
V_9 -> V_22 = true ;
} else if ( clock > V_23 ) {
V_20 = true ;
}
}
if ( V_20 && V_9 -> V_22 ) {
F_14 ( V_9 -> V_21 ) ;
V_9 -> V_22 = false ;
}
F_12 ( V_2 , clock ) ;
if ( V_20 ) {
F_13 ( V_9 -> V_21 ) ;
V_9 -> V_22 = true ;
}
}
static void F_15 ( struct V_25 * V_19 ,
struct V_26 * V_27 )
{
T_1 V_28 ;
struct V_1 * V_2 = F_16 ( V_19 ) ;
V_28 = F_17 ( V_2 , V_29 ) ;
if ( V_27 -> V_30 )
V_28 |= V_31 ;
else
V_28 &= ~ V_31 ;
F_18 ( V_2 , V_28 , V_29 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_4 V_32 )
{
T_4 V_33 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_20 ( V_2 , V_32 ) ;
if ( V_9 -> V_34 & V_35 ) {
V_33 = F_21 ( V_2 , V_36 ) ;
V_33 |= V_37 | V_38 ;
F_22 ( V_2 , V_33 , V_36 ) ;
}
}
static int F_23 ( struct V_25 * V_19 ,
struct V_26 * V_27 )
{
switch ( V_27 -> V_39 ) {
case V_40 :
return 0 ;
case V_41 :
case V_42 :
break;
}
return - V_16 ;
}
static int F_24 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = F_25 ( V_44 ) ;
struct V_1 * V_2 = F_26 ( V_46 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_15 ;
if ( V_2 -> V_47 != V_48 )
F_27 ( V_2 -> V_19 ) ;
V_15 = F_28 ( V_2 ) ;
if ( V_15 )
return V_15 ;
if ( ! F_11 ( V_9 -> V_21 ) && V_9 -> V_22 ) {
V_15 = F_14 ( V_9 -> V_21 ) ;
if ( V_15 ) {
F_29 ( V_44 , L_2 ) ;
F_30 ( V_2 ) ;
return V_15 ;
}
V_9 -> V_22 = false ;
}
F_31 ( V_7 -> V_49 ) ;
F_31 ( V_9 -> V_50 ) ;
return 0 ;
}
static int F_32 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = F_25 ( V_44 ) ;
struct V_1 * V_2 = F_26 ( V_46 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_15 ;
V_15 = F_33 ( V_9 -> V_50 ) ;
if ( V_15 ) {
F_29 ( V_44 , L_3 ) ;
return V_15 ;
}
V_15 = F_33 ( V_7 -> V_49 ) ;
if ( V_15 ) {
F_29 ( V_44 , L_4 ) ;
return V_15 ;
}
if ( ! F_11 ( V_9 -> V_21 ) && V_2 -> V_19 -> V_51 ) {
V_15 = F_13 ( V_9 -> V_21 ) ;
if ( V_15 ) {
F_29 ( V_44 , L_5 ) ;
return V_15 ;
}
V_9 -> V_22 = true ;
}
return F_30 ( V_2 ) ;
}
static unsigned long F_34 ( struct V_52 * V_53 ,
unsigned long V_54 )
{
struct V_8 * V_9 =
F_35 ( V_53 , struct V_8 , V_55 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
return V_2 -> V_19 -> V_51 ;
}
static void F_36 ( struct V_1 * V_2 ,
T_1 V_56 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
const struct V_57 * V_17 =
V_9 -> V_17 ;
if ( ! V_17 )
return;
if ( ! V_9 -> V_11 ) {
F_8 ( L_6 ,
F_9 ( V_2 -> V_19 ) ) ;
return;
}
F_1 ( V_2 , & V_17 -> V_58 , V_56 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
const struct V_57 * V_17 =
V_9 -> V_17 ;
T_1 V_59 = F_38 ( F_39 ( V_7 -> V_49 ) , 1000000 ) ;
if ( ! V_17 )
return;
if ( ! V_9 -> V_11 ) {
F_8 ( L_6 ,
F_9 ( V_2 -> V_19 ) ) ;
return;
}
F_1 ( V_2 , & V_17 -> V_60 , V_59 ) ;
}
static int F_40 ( struct V_8 * V_9 ,
struct V_49 * V_61 ,
struct V_43 * V_44 )
{
struct V_62 * V_63 = V_44 -> V_64 ;
struct V_65 V_66 ;
const char * V_67 ;
int V_15 ;
if ( ! F_41 ( V_63 , L_7 , NULL ) )
return 0 ;
V_15 = F_42 ( V_63 , L_8 , 0 ,
& V_66 . V_68 ) ;
if ( V_15 ) {
F_29 ( V_44 , L_9 ) ;
return V_15 ;
}
V_67 = F_43 ( V_61 ) ;
V_66 . V_69 = & V_67 ;
V_66 . V_70 = 1 ;
V_66 . V_71 = V_72 ;
V_66 . V_73 = & V_74 ;
V_9 -> V_55 . V_75 = & V_66 ;
V_9 -> V_76 =
F_44 ( V_44 , & V_9 -> V_55 ) ;
V_9 -> V_55 . V_75 = NULL ;
V_15 = F_45 ( V_63 , V_77 ,
V_9 -> V_76 ) ;
if ( V_15 )
F_29 ( V_44 , L_10 ) ;
return V_15 ;
}
static void F_46 ( struct V_43 * V_44 )
{
struct V_62 * V_63 = V_44 -> V_64 ;
if ( ! F_41 ( V_63 , L_7 , NULL ) )
return;
F_47 ( V_44 -> V_64 ) ;
}
static int F_48 ( struct V_45 * V_46 )
{
int V_15 ;
const struct V_78 * V_79 ;
struct V_62 * V_80 ;
struct V_49 * V_61 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_62 * V_63 = V_46 -> V_44 . V_64 ;
V_2 = F_49 ( V_46 , & V_81 ,
sizeof( * V_9 ) ) ;
if ( F_11 ( V_2 ) )
return F_50 ( V_2 ) ;
V_7 = F_2 ( V_2 ) ;
V_9 = F_3 ( V_7 ) ;
V_9 -> V_2 = V_2 ;
V_79 = F_51 ( V_82 , V_46 -> V_44 . V_64 ) ;
V_9 -> V_17 = V_79 -> V_83 ;
V_80 = F_52 ( V_46 -> V_44 . V_64 , L_11 , 0 ) ;
if ( V_80 ) {
V_9 -> V_11 = F_53 ( V_80 ) ;
F_54 ( V_80 ) ;
if ( F_11 ( V_9 -> V_11 ) ) {
V_15 = F_50 ( V_9 -> V_11 ) ;
if ( V_15 != - V_84 )
F_29 ( & V_46 -> V_44 , L_12 ,
V_15 ) ;
goto V_85;
}
}
V_9 -> V_50 = F_55 ( & V_46 -> V_44 , L_13 ) ;
if ( F_11 ( V_9 -> V_50 ) ) {
F_29 ( & V_46 -> V_44 , L_14 ) ;
V_15 = F_50 ( V_9 -> V_50 ) ;
goto V_85;
}
V_61 = F_55 ( & V_46 -> V_44 , L_15 ) ;
if ( F_11 ( V_61 ) ) {
F_29 ( & V_46 -> V_44 , L_16 ) ;
V_15 = F_50 ( V_61 ) ;
goto V_85;
}
V_15 = F_56 ( V_9 -> V_50 ) ;
if ( V_15 ) {
F_29 ( & V_46 -> V_44 , L_17 ) ;
goto V_85;
}
V_15 = F_56 ( V_61 ) ;
if ( V_15 ) {
F_29 ( & V_46 -> V_44 , L_18 ) ;
goto V_86;
}
F_57 ( V_46 ) ;
if ( F_58 ( V_63 , L_19 ) )
V_9 -> V_34 |= V_35 ;
V_7 -> V_49 = V_61 ;
if ( F_59 ( V_46 -> V_44 . V_64 ,
L_20 ) )
F_36 ( V_2 , 0x0 ) ;
F_37 ( V_2 ) ;
V_15 = F_40 ( V_9 , V_61 , & V_46 -> V_44 ) ;
if ( V_15 )
goto V_87;
V_15 = F_60 ( V_2 -> V_19 ) ;
if ( V_15 ) {
F_29 ( & V_46 -> V_44 , L_21 , V_15 ) ;
goto V_88;
}
V_9 -> V_21 = F_61 ( - V_89 ) ;
if ( F_59 ( V_46 -> V_44 . V_64 ,
L_22 ) ) {
V_9 -> V_21 = F_62 ( & V_46 -> V_44 ,
L_23 ) ;
if ( F_11 ( V_9 -> V_21 ) ) {
V_15 = F_50 ( V_9 -> V_21 ) ;
F_29 ( & V_46 -> V_44 , L_24 ) ;
goto V_88;
}
V_15 = F_63 ( V_9 -> V_21 ) ;
if ( V_15 < 0 ) {
F_29 ( & V_46 -> V_44 , L_25 ) ;
goto V_88;
}
V_2 -> V_90 . V_91 =
F_15 ;
V_2 -> V_90 . V_92 =
F_23 ;
}
V_15 = F_64 ( V_2 ) ;
if ( V_15 )
goto V_93;
return 0 ;
V_93:
if ( ! F_11 ( V_9 -> V_21 ) )
F_65 ( V_9 -> V_21 ) ;
V_88:
F_46 ( & V_46 -> V_44 ) ;
V_87:
F_66 ( V_61 ) ;
V_86:
F_66 ( V_9 -> V_50 ) ;
V_85:
F_67 ( V_46 ) ;
return V_15 ;
}
static int F_68 ( struct V_45 * V_46 )
{
int V_15 ;
struct V_1 * V_2 = F_26 ( V_46 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_49 * V_50 = V_9 -> V_50 ;
if ( ! F_11 ( V_9 -> V_21 ) ) {
if ( V_9 -> V_22 )
F_14 ( V_9 -> V_21 ) ;
F_65 ( V_9 -> V_21 ) ;
}
F_46 ( & V_46 -> V_44 ) ;
V_15 = F_69 ( V_46 ) ;
F_66 ( V_50 ) ;
return V_15 ;
}
