static void F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_4 |= V_7 ;
F_3 ( V_4 , V_2 -> V_5 + V_6 ) ;
F_3 ( V_3 , V_2 -> V_5 + V_8 ) ;
V_4 |= V_9 ;
V_4 &= ~ V_7 ;
F_3 ( V_4 , V_2 -> V_5 + V_6 ) ;
}
static T_2 F_4 ( int V_10 , void * V_11 )
{
struct V_12 * V_13 = V_11 ;
struct V_1 * V_2 = & V_13 -> V_14 ;
F_2 ( V_2 -> V_5 + V_15 ) ;
V_13 -> V_16 . V_17 ( & V_13 -> V_16 ) ;
return V_18 ;
}
static T_3 F_5 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = & F_6 ( V_20 ) -> V_14 ;
return ( T_3 ) F_2 ( V_2 -> V_5 +
V_21 ) ;
}
static T_4 T_5 F_7 ( void )
{
return F_2 ( V_22 ) ;
}
static int F_8 ( unsigned long V_3 ,
struct V_23 * V_24 )
{
struct V_12 * V_13 = F_9 ( V_24 ) ;
struct V_1 * V_2 = & V_13 -> V_14 ;
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_10 ( struct V_23 * V_24 )
{
struct V_12 * V_13 = F_9 ( V_24 ) ;
struct V_1 * V_2 = & V_13 -> V_14 ;
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_4 |= V_7 ;
F_3 ( V_4 , V_2 -> V_5 + V_6 ) ;
return 0 ;
}
static int F_11 ( struct V_23 * V_24 )
{
struct V_12 * V_13 = F_9 ( V_24 ) ;
struct V_1 * V_2 = & V_13 -> V_14 ;
F_1 ( V_2 ,
F_12 ( V_13 -> V_14 . V_25 , V_26 * V_27 ) ) ;
return 0 ;
}
static int F_13 ( struct V_23 * V_24 )
{
struct V_12 * V_13 = F_9 ( V_24 ) ;
struct V_1 * V_2 = & V_13 -> V_14 ;
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_4 &= ~ V_7 ;
F_3 ( V_4 , V_2 -> V_5 + V_6 ) ;
return 0 ;
}
static int F_14 ( struct V_28 * V_29 ,
unsigned long V_30 , void * V_31 )
{
struct V_32 * V_33 = V_31 ;
struct V_1 * V_14 = F_15 ( V_29 ) ;
struct V_34 * V_35 = F_16 ( V_14 ,
struct V_34 , V_14 ) ;
switch ( V_30 ) {
case V_36 :
{
T_1 V_37 ;
unsigned long V_38 , V_39 , V_40 ;
if ( V_33 -> V_41 > V_33 -> V_42 ) {
V_38 = F_12 ( V_33 -> V_41 ,
V_33 -> V_42 ) ;
V_39 = V_33 -> V_42 ;
V_40 = V_33 -> V_41 ;
} else {
V_38 = F_12 ( V_33 -> V_42 ,
V_33 -> V_41 ) ;
V_39 = V_33 -> V_41 ;
V_40 = V_33 -> V_42 ;
}
if ( ! F_17 ( V_38 ) )
return V_43 ;
if ( abs ( V_40 - ( V_38 * V_39 ) ) > V_44 )
return V_43 ;
V_38 = F_18 ( V_38 ) ;
V_35 -> V_45 =
F_2 ( V_35 -> V_14 . V_5 +
V_46 ) ;
V_37 = ( V_35 -> V_45 &
V_47 ) >>
V_48 ;
if ( V_33 -> V_41 < V_33 -> V_42 )
V_37 -= V_38 ;
else
V_37 += V_38 ;
if ( V_37 & ~ ( V_47 >> V_48 ) )
return V_43 ;
V_35 -> V_49 = V_35 -> V_45 &
~ V_47 ;
V_35 -> V_49 |= V_37 << V_48 ;
if ( V_33 -> V_41 < V_33 -> V_42 )
return V_50 ;
F_3 ( V_35 -> V_49 ,
V_35 -> V_14 . V_5 + V_46 ) ;
break;
}
case V_51 :
if ( V_33 -> V_41 > V_33 -> V_42 )
return V_52 ;
F_3 ( V_35 -> V_49 ,
V_35 -> V_14 . V_5 + V_46 ) ;
break;
case V_53 :
if ( V_33 -> V_41 < V_33 -> V_42 )
return V_52 ;
F_3 ( V_35 -> V_45 ,
V_35 -> V_14 . V_5 + V_46 ) ;
default:
return V_50 ;
}
return V_50 ;
}
static int T_6 F_19 ( struct V_54 * V_54 , void T_7 * V_55 ,
T_1 V_56 )
{
struct V_34 * V_35 ;
int V_57 ;
V_35 = F_20 ( sizeof( * V_35 ) , V_58 ) ;
if ( ! V_35 )
return - V_59 ;
V_35 -> V_14 . V_54 = V_54 ;
V_57 = F_21 ( V_35 -> V_14 . V_54 ) ;
if ( V_57 ) {
F_22 ( V_35 ) ;
return V_57 ;
}
V_35 -> V_14 . V_25 = F_23 ( V_35 -> V_14 . V_54 ) ;
V_35 -> V_14 . V_60 . V_61 =
F_14 ;
V_35 -> V_14 . V_60 . V_62 = NULL ;
V_57 = F_24 ( V_35 -> V_14 . V_54 ,
& V_35 -> V_14 . V_60 ) ;
if ( V_57 )
F_25 ( L_1 ) ;
V_35 -> V_14 . V_5 = V_55 ;
V_35 -> V_20 . V_63 = L_2 ;
V_35 -> V_20 . V_64 = 200 ;
V_35 -> V_20 . V_65 = F_5 ;
V_35 -> V_20 . V_66 = F_26 ( V_56 ) ;
V_35 -> V_20 . V_67 = V_68 ;
F_3 ( 0x0 , V_35 -> V_14 . V_5 + V_69 ) ;
F_3 ( V_70 | V_71 ,
V_35 -> V_14 . V_5 + V_46 ) ;
F_3 ( V_9 ,
V_35 -> V_14 . V_5 + V_6 ) ;
V_57 = F_27 ( & V_35 -> V_20 , V_35 -> V_14 . V_25 / V_26 ) ;
if ( V_57 ) {
F_22 ( V_35 ) ;
return V_57 ;
}
V_22 = V_55 + V_21 ;
F_28 ( F_7 , V_56 ,
V_35 -> V_14 . V_25 / V_26 ) ;
return 0 ;
}
static int F_29 ( struct V_28 * V_29 ,
unsigned long V_30 , void * V_31 )
{
struct V_32 * V_33 = V_31 ;
struct V_1 * V_14 = F_15 ( V_29 ) ;
struct V_12 * V_72 = F_16 ( V_14 ,
struct V_12 , V_14 ) ;
switch ( V_30 ) {
case V_51 :
V_14 -> V_25 = V_33 -> V_41 ;
F_30 ( & V_72 -> V_16 , V_33 -> V_41 / V_26 ) ;
case V_36 :
case V_53 :
default:
return V_50 ;
}
}
static int T_6 F_31 ( struct V_54 * V_54 ,
void T_7 * V_55 , T_1 V_10 )
{
struct V_12 * V_72 ;
int V_57 ;
V_72 = F_20 ( sizeof( * V_72 ) , V_58 ) ;
if ( ! V_72 )
return - V_59 ;
V_72 -> V_14 . V_54 = V_54 ;
V_57 = F_21 ( V_72 -> V_14 . V_54 ) ;
if ( V_57 ) {
F_22 ( V_72 ) ;
return V_57 ;
}
V_72 -> V_14 . V_60 . V_61 =
F_29 ;
V_72 -> V_14 . V_60 . V_62 = NULL ;
V_57 = F_24 ( V_72 -> V_14 . V_54 ,
& V_72 -> V_14 . V_60 ) ;
if ( V_57 ) {
F_25 ( L_1 ) ;
return V_57 ;
}
V_72 -> V_14 . V_25 = F_23 ( V_72 -> V_14 . V_54 ) ;
V_72 -> V_14 . V_5 = V_55 ;
V_72 -> V_16 . V_63 = L_3 ;
V_72 -> V_16 . V_73 = V_74 | V_75 ;
V_72 -> V_16 . V_76 = F_8 ;
V_72 -> V_16 . V_77 = F_10 ;
V_72 -> V_16 . V_78 = F_11 ;
V_72 -> V_16 . V_79 = F_10 ;
V_72 -> V_16 . V_80 = F_13 ;
V_72 -> V_16 . V_64 = 200 ;
V_72 -> V_16 . V_10 = V_10 ;
V_72 -> V_16 . V_81 = V_82 ;
F_3 ( 0x23 , V_72 -> V_14 . V_5 + V_6 ) ;
F_3 ( V_70 | V_71 ,
V_72 -> V_14 . V_5 + V_46 ) ;
F_3 ( 0x1 , V_72 -> V_14 . V_5 + V_69 ) ;
V_57 = F_32 ( V_10 , F_4 ,
V_83 , V_72 -> V_16 . V_63 , V_72 ) ;
if ( V_57 ) {
F_22 ( V_72 ) ;
return V_57 ;
}
F_33 ( & V_72 -> V_16 ,
V_72 -> V_14 . V_25 / V_26 , 1 , 0xfffe ) ;
return 0 ;
}
static int T_6 F_34 ( struct V_84 * V_2 )
{
unsigned int V_10 ;
void T_7 * V_85 ;
struct V_54 * V_86 , * V_87 ;
static int V_88 ;
int V_89 , V_90 ;
T_1 V_56 = 16 ;
if ( V_88 )
return 0 ;
V_88 = 1 ;
V_85 = F_35 ( V_2 , 0 ) ;
if ( ! V_85 ) {
F_36 ( L_4 ) ;
return - V_91 ;
}
V_10 = F_37 ( V_2 , 1 ) ;
if ( V_10 <= 0 ) {
F_36 ( L_5 ) ;
return - V_92 ;
}
F_38 ( V_2 , L_6 , & V_56 ) ;
V_89 = F_2 ( V_85 + V_46 ) ;
V_89 = ! ! ( V_89 & V_93 ) ;
V_86 = F_39 ( V_2 , V_89 ) ;
if ( F_40 ( V_86 ) ) {
F_36 ( L_7 ) ;
return F_41 ( V_86 ) ;
}
V_89 = F_2 ( V_85 + 4 + V_46 ) ;
V_89 = ! ! ( V_89 & V_93 ) ;
V_87 = F_39 ( V_2 , V_89 ) ;
if ( F_40 ( V_87 ) ) {
F_36 ( L_7 ) ;
return F_41 ( V_87 ) ;
}
V_90 = F_19 ( V_86 , V_85 , V_56 ) ;
if ( V_90 )
return V_90 ;
V_90 = F_31 ( V_87 , V_85 + 4 , V_10 ) ;
if ( V_90 )
return V_90 ;
F_42 ( L_8 , V_2 -> V_63 , V_85 , V_10 ) ;
return 0 ;
}
