static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_5 )
{
F_4 ( V_5 -> V_6 ,
V_7 ,
V_8 ,
V_9 ) ;
F_5 ( V_10 ) ;
F_4 ( V_5 -> V_6 ,
V_7 ,
V_8 ,
( V_9
| V_11 ) ) ;
if ( V_5 -> V_12 > 0x10 )
F_5 ( V_13 ) ;
else
F_6 ( V_14 ) ;
F_4 ( V_5 -> V_6 ,
V_7 ,
V_8 ,
0 ) ;
}
static void F_7 ( struct V_1 * V_5 , bool V_15 ,
bool V_16 )
{
T_1 V_17 ;
F_8 ( V_5 -> V_6 ,
V_18 ,
V_19 ,
& V_17 ) ;
if ( V_15 ) {
if ( V_16 )
V_17 |= V_20 ;
else
V_17 &= ~ V_20 ;
} else {
if ( V_16 )
V_17 |= V_21 ;
else
V_17 &= ~ V_21 ;
}
F_4 ( V_5 -> V_6 ,
V_18 ,
V_19 ,
V_17 ) ;
if ( V_16 )
F_3 ( V_5 ) ;
}
static int F_9 ( struct V_1 * V_5 )
{
T_1 V_22 ;
enum V_23 V_24 ;
void * V_25 = NULL ;
enum V_26 V_27 ;
F_8 ( V_5 -> V_6 ,
V_18 ,
V_28 ,
& V_22 ) ;
V_24 = ( V_22 >> 3 ) & 0x0F ;
switch ( V_24 ) {
case V_29 :
case V_30 :
case V_31 :
F_10 ( V_5 ) ;
F_11 ( V_5 ) ;
V_5 -> V_4 . V_32 = V_33 ;
V_5 -> V_4 . V_34 = false ;
V_5 -> V_35 = 0 ;
V_27 = V_36 ;
break;
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
if ( V_5 -> V_4 . V_43 ) {
F_12 ( V_5 ) ;
V_25 = V_5 -> V_4 . V_43 ;
}
V_27 = V_44 ;
break;
case V_45 :
if ( V_5 -> V_4 . V_46 ) {
F_13 ( V_5 ) ;
V_25 = V_5 -> V_4 . V_46 ;
}
V_5 -> V_4 . V_32 = V_47 ;
V_5 -> V_4 . V_34 = true ;
V_27 = V_48 ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
V_27 = V_55 ;
break;
}
F_14 ( & V_5 -> V_4 . V_56 , V_27 , V_25 ) ;
return 0 ;
}
static void F_15 ( struct V_57 * V_58 )
{
struct V_1 * V_5 = F_2 ( V_58 , struct V_1 ,
V_59 . V_58 ) ;
F_9 ( V_5 ) ;
}
static T_2 F_16 ( int V_60 , void * V_61 )
{
struct V_1 * V_5 = (struct V_1 * ) V_61 ;
F_17 ( & V_5 -> V_59 , V_5 -> V_62 ) ;
return V_63 ;
}
static T_2 F_18 ( int V_60 , void * V_61 )
{
struct V_1 * V_5 = (struct V_1 * ) V_61 ;
F_11 ( V_5 ) ;
F_17 ( & V_5 -> V_59 , V_5 -> V_62 ) ;
return V_63 ;
}
static T_2 F_19 ( int V_60 , void * V_61 )
{
struct V_1 * V_5 = (struct V_1 * ) V_61 ;
F_9 ( V_5 ) ;
return V_63 ;
}
static void F_20 ( struct V_57 * V_58 )
{
struct V_1 * V_5 = F_2 ( V_58 , struct V_1 ,
V_64 ) ;
if ( ! V_5 -> V_4 . V_46 )
F_10 ( V_5 ) ;
if ( ! V_5 -> V_4 . V_43 )
F_11 ( V_5 ) ;
}
static int F_21 ( struct V_2 * V_4 , unsigned V_65 )
{
struct V_1 * V_5 ;
if ( ! V_4 )
return - V_66 ;
V_5 = F_1 ( V_4 ) ;
V_5 -> V_35 = V_65 ;
if ( V_65 )
F_14 ( & V_5 -> V_4 . V_56 ,
V_67 , V_5 -> V_4 . V_43 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , int V_68 )
{
return 0 ;
}
static int F_23 ( struct V_2 * V_4 ,
struct V_69 * V_43 )
{
struct V_1 * V_5 ;
if ( ! V_4 )
return - V_66 ;
V_5 = F_1 ( V_4 ) ;
if ( ! V_43 ) {
V_5 -> V_4 . V_43 = NULL ;
F_24 ( & V_5 -> V_64 ) ;
} else {
V_5 -> V_4 . V_43 = V_43 ;
V_5 -> V_4 . V_32 = V_33 ;
F_17 ( & V_5 -> V_59 , V_5 -> V_62 ) ;
}
return 0 ;
}
static int F_25 ( struct V_2 * V_4 ,
struct V_70 * V_46 )
{
struct V_1 * V_5 ;
if ( ! V_4 )
return - V_66 ;
V_5 = F_1 ( V_4 ) ;
if ( ! V_46 ) {
V_5 -> V_4 . V_46 = NULL ;
F_24 ( & V_5 -> V_64 ) ;
} else {
V_5 -> V_4 . V_46 = V_46 ;
F_17 ( & V_5 -> V_59 , V_5 -> V_62 ) ;
}
return 0 ;
}
static void F_26 ( struct V_1 * V_5 )
{
if ( V_5 -> V_12 < 0x20 ) {
F_27 ( V_5 -> V_71 , V_5 ) ;
F_27 ( V_5 -> V_72 , V_5 ) ;
F_27 ( V_5 -> V_73 , V_5 ) ;
F_27 ( V_5 -> V_74 , V_5 ) ;
} else {
F_27 ( V_5 -> V_75 , V_5 ) ;
}
}
static int F_28 ( struct V_76 * V_77 ,
struct V_1 * V_5 )
{
int V_78 ;
V_5 -> V_71 = F_29 ( V_77 , L_1 ) ;
if ( V_5 -> V_71 < 0 ) {
F_30 ( & V_77 -> V_6 , L_2 ) ;
return V_5 -> V_71 ;
}
V_78 = F_31 ( V_5 -> V_71 , NULL ,
F_16 ,
V_79 | V_80 ,
L_3 , V_5 ) ;
if ( V_78 < 0 ) {
F_30 ( V_5 -> V_6 , L_4 ) ;
goto V_81;
}
V_5 -> V_72 = F_29 ( V_77 , L_5 ) ;
if ( V_5 -> V_72 < 0 ) {
F_30 ( & V_77 -> V_6 , L_6 ) ;
return V_5 -> V_72 ;
}
V_78 = F_31 ( V_5 -> V_72 , NULL ,
F_16 ,
V_79 | V_80 ,
L_7 , V_5 ) ;
if ( V_78 < 0 ) {
F_30 ( V_5 -> V_6 , L_8 ) ;
goto V_82;
}
V_5 -> V_73 = F_29 ( V_77 , L_9 ) ;
if ( V_5 -> V_73 < 0 ) {
F_30 ( & V_77 -> V_6 , L_10 ) ;
return V_5 -> V_73 ;
}
V_78 = F_31 ( V_5 -> V_73 , NULL ,
F_16 ,
V_79 | V_80 ,
L_11 , V_5 ) ;
if ( V_78 < 0 ) {
F_30 ( V_5 -> V_6 , L_12 ) ;
goto V_83;
}
V_5 -> V_74 = F_29 ( V_77 , L_13 ) ;
if ( V_5 -> V_74 < 0 ) {
F_30 ( & V_77 -> V_6 , L_14 ) ;
return V_5 -> V_74 ;
}
V_78 = F_31 ( V_5 -> V_74 , NULL ,
F_18 ,
V_79 | V_80 ,
L_15 , V_5 ) ;
if ( V_78 < 0 ) {
F_30 ( V_5 -> V_6 , L_16 ) ;
goto V_84;
}
return 0 ;
V_84:
F_27 ( V_5 -> V_73 , V_5 ) ;
V_83:
F_27 ( V_5 -> V_72 , V_5 ) ;
V_82:
F_27 ( V_5 -> V_71 , V_5 ) ;
V_81:
return V_78 ;
}
static int F_32 ( struct V_76 * V_77 ,
struct V_1 * V_5 )
{
int V_78 ;
V_5 -> V_75 = F_29 ( V_77 ,
L_17 ) ;
if ( V_5 -> V_75 < 0 ) {
F_30 ( & V_77 -> V_6 , L_18 ) ;
return V_5 -> V_75 ;
}
V_78 = F_31 ( V_5 -> V_75 , NULL ,
F_19 ,
V_79 | V_80 ,
L_19 , V_5 ) ;
if ( V_78 < 0 ) {
F_30 ( V_5 -> V_6 ,
L_20 ) ;
return V_78 ;
}
return 0 ;
}
static int T_3 F_33 ( struct V_76 * V_77 )
{
struct V_1 * V_5 ;
int V_78 ;
int V_12 ;
V_12 = F_34 ( & V_77 -> V_6 ) ;
if ( V_12 < 0 ) {
F_30 ( & V_77 -> V_6 , L_21 ) ;
return V_12 ;
} else if ( V_12 < 0x10 ) {
F_30 ( & V_77 -> V_6 , L_22 ) ;
return - V_66 ;
}
V_5 = F_35 ( sizeof *V_5 , V_85 ) ;
if ( ! V_5 )
return - V_86 ;
V_5 -> V_6 = & V_77 -> V_6 ;
V_5 -> V_12 = V_12 ;
V_5 -> V_4 . V_6 = V_5 -> V_6 ;
V_5 -> V_4 . V_87 = L_23 ;
V_5 -> V_4 . V_32 = V_88 ;
V_5 -> V_4 . V_89 = F_25 ;
V_5 -> V_4 . V_90 = F_23 ;
V_5 -> V_4 . V_91 = F_22 ;
V_5 -> V_4 . V_92 = F_21 ;
F_36 ( V_77 , V_5 ) ;
F_37 ( & V_5 -> V_4 . V_56 ) ;
F_38 ( & V_5 -> V_59 , F_15 ) ;
F_39 ( & V_5 -> V_64 , F_20 ) ;
if ( V_5 -> V_12 < 0x20 ) {
V_78 = F_28 ( V_77 , V_5 ) ;
V_5 -> V_62 = V_93 ;
} else {
V_78 = F_32 ( V_77 , V_5 ) ;
}
if ( V_78 < 0 )
goto V_81;
V_78 = F_40 ( & V_5 -> V_4 ) ;
if ( V_78 ) {
F_30 ( & V_77 -> V_6 , L_24 ) ;
goto V_82;
}
F_41 ( & V_77 -> V_6 , L_25 ) ;
return 0 ;
V_82:
F_26 ( V_5 ) ;
V_81:
F_42 ( V_5 ) ;
return V_78 ;
}
static int T_4 F_43 ( struct V_76 * V_77 )
{
struct V_1 * V_5 = F_44 ( V_77 ) ;
F_26 ( V_5 ) ;
F_45 ( & V_5 -> V_59 ) ;
F_46 ( & V_5 -> V_64 ) ;
F_40 ( NULL ) ;
F_10 ( V_5 ) ;
F_11 ( V_5 ) ;
F_36 ( V_77 , NULL ) ;
F_42 ( V_5 ) ;
return 0 ;
}
static int T_5 F_47 ( void )
{
return F_48 ( & V_94 ) ;
}
static void T_6 F_49 ( void )
{
F_50 ( & V_94 ) ;
}
