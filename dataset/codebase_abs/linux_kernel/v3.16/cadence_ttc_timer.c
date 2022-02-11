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
static void F_10 ( enum V_25 V_26 ,
struct V_23 * V_24 )
{
struct V_12 * V_13 = F_9 ( V_24 ) ;
struct V_1 * V_2 = & V_13 -> V_14 ;
T_1 V_4 ;
switch ( V_26 ) {
case V_27 :
F_1 ( V_2 , F_11 ( V_13 -> V_14 . V_28 ,
V_29 * V_30 ) ) ;
break;
case V_31 :
case V_32 :
case V_33 :
V_4 = F_2 ( V_2 -> V_5 +
V_6 ) ;
V_4 |= V_7 ;
F_3 ( V_4 ,
V_2 -> V_5 + V_6 ) ;
break;
case V_34 :
V_4 = F_2 ( V_2 -> V_5 +
V_6 ) ;
V_4 &= ~ V_7 ;
F_3 ( V_4 ,
V_2 -> V_5 + V_6 ) ;
break;
}
}
static int F_12 ( struct V_35 * V_36 ,
unsigned long V_37 , void * V_38 )
{
struct V_39 * V_40 = V_38 ;
struct V_1 * V_14 = F_13 ( V_36 ) ;
struct V_41 * V_42 = F_14 ( V_14 ,
struct V_41 , V_14 ) ;
switch ( V_37 ) {
case V_43 :
{
T_1 V_44 ;
unsigned long V_45 , V_46 , V_47 ;
if ( V_40 -> V_48 > V_40 -> V_49 ) {
V_45 = F_11 ( V_40 -> V_48 ,
V_40 -> V_49 ) ;
V_46 = V_40 -> V_49 ;
V_47 = V_40 -> V_48 ;
} else {
V_45 = F_11 ( V_40 -> V_49 ,
V_40 -> V_48 ) ;
V_46 = V_40 -> V_48 ;
V_47 = V_40 -> V_49 ;
}
if ( ! F_15 ( V_45 ) )
return V_50 ;
if ( abs ( V_47 - ( V_45 * V_46 ) ) > V_51 )
return V_50 ;
V_45 = F_16 ( V_45 ) ;
V_42 -> V_52 =
F_2 ( V_42 -> V_14 . V_5 +
V_53 ) ;
V_44 = ( V_42 -> V_52 &
V_54 ) >>
V_55 ;
if ( V_40 -> V_48 < V_40 -> V_49 )
V_44 -= V_45 ;
else
V_44 += V_45 ;
if ( V_44 & ~ ( V_54 >> V_55 ) )
return V_50 ;
V_42 -> V_56 = V_42 -> V_52 &
~ V_54 ;
V_42 -> V_56 |= V_44 << V_55 ;
if ( V_40 -> V_48 < V_40 -> V_49 )
return V_57 ;
F_3 ( V_42 -> V_56 ,
V_42 -> V_14 . V_5 + V_53 ) ;
break;
}
case V_58 :
if ( V_40 -> V_48 > V_40 -> V_49 )
return V_59 ;
F_3 ( V_42 -> V_56 ,
V_42 -> V_14 . V_5 + V_53 ) ;
break;
case V_60 :
if ( V_40 -> V_48 < V_40 -> V_49 )
return V_59 ;
F_3 ( V_42 -> V_52 ,
V_42 -> V_14 . V_5 + V_53 ) ;
default:
return V_57 ;
}
return V_57 ;
}
static void T_6 F_17 ( struct V_61 * V_61 , void T_7 * V_62 )
{
struct V_41 * V_42 ;
int V_63 ;
V_42 = F_18 ( sizeof( * V_42 ) , V_64 ) ;
if ( F_19 ( ! V_42 ) )
return;
V_42 -> V_14 . V_61 = V_61 ;
V_63 = F_20 ( V_42 -> V_14 . V_61 ) ;
if ( F_19 ( V_63 ) ) {
F_21 ( V_42 ) ;
return;
}
V_42 -> V_14 . V_28 = F_22 ( V_42 -> V_14 . V_61 ) ;
V_42 -> V_14 . V_65 . V_66 =
F_12 ;
V_42 -> V_14 . V_65 . V_67 = NULL ;
if ( F_23 ( V_42 -> V_14 . V_61 ,
& V_42 -> V_14 . V_65 ) )
F_24 ( L_1 ) ;
V_42 -> V_14 . V_5 = V_62 ;
V_42 -> V_20 . V_68 = L_2 ;
V_42 -> V_20 . V_69 = 200 ;
V_42 -> V_20 . V_70 = F_5 ;
V_42 -> V_20 . V_71 = F_25 ( 16 ) ;
V_42 -> V_20 . V_72 = V_73 ;
F_3 ( 0x0 , V_42 -> V_14 . V_5 + V_74 ) ;
F_3 ( V_75 | V_76 ,
V_42 -> V_14 . V_5 + V_53 ) ;
F_3 ( V_9 ,
V_42 -> V_14 . V_5 + V_6 ) ;
V_63 = F_26 ( & V_42 -> V_20 , V_42 -> V_14 . V_28 / V_29 ) ;
if ( F_19 ( V_63 ) ) {
F_21 ( V_42 ) ;
return;
}
V_22 = V_62 + V_21 ;
F_27 ( F_7 , 16 , V_42 -> V_14 . V_28 / V_29 ) ;
}
static int F_28 ( struct V_35 * V_36 ,
unsigned long V_37 , void * V_38 )
{
struct V_39 * V_40 = V_38 ;
struct V_1 * V_14 = F_13 ( V_36 ) ;
struct V_12 * V_77 = F_14 ( V_14 ,
struct V_12 , V_14 ) ;
switch ( V_37 ) {
case V_58 :
V_14 -> V_28 = V_40 -> V_48 ;
F_29 ( & V_77 -> V_16 , V_40 -> V_48 / V_29 ) ;
case V_43 :
case V_60 :
default:
return V_57 ;
}
}
static void T_6 F_30 ( struct V_61 * V_61 ,
void T_7 * V_62 , T_1 V_10 )
{
struct V_12 * V_77 ;
int V_63 ;
V_77 = F_18 ( sizeof( * V_77 ) , V_64 ) ;
if ( F_19 ( ! V_77 ) )
return;
V_77 -> V_14 . V_61 = V_61 ;
V_63 = F_20 ( V_77 -> V_14 . V_61 ) ;
if ( F_19 ( V_63 ) ) {
F_21 ( V_77 ) ;
return;
}
V_77 -> V_14 . V_65 . V_66 =
F_28 ;
V_77 -> V_14 . V_65 . V_67 = NULL ;
if ( F_23 ( V_77 -> V_14 . V_61 ,
& V_77 -> V_14 . V_65 ) )
F_24 ( L_1 ) ;
V_77 -> V_14 . V_28 = F_22 ( V_77 -> V_14 . V_61 ) ;
V_77 -> V_14 . V_5 = V_62 ;
V_77 -> V_16 . V_68 = L_3 ;
V_77 -> V_16 . V_78 = V_79 | V_80 ;
V_77 -> V_16 . V_81 = F_8 ;
V_77 -> V_16 . V_82 = F_10 ;
V_77 -> V_16 . V_69 = 200 ;
V_77 -> V_16 . V_10 = V_10 ;
V_77 -> V_16 . V_83 = V_84 ;
F_3 ( 0x23 , V_77 -> V_14 . V_5 + V_6 ) ;
F_3 ( V_75 | V_76 ,
V_77 -> V_14 . V_5 + V_53 ) ;
F_3 ( 0x1 , V_77 -> V_14 . V_5 + V_74 ) ;
V_63 = F_31 ( V_10 , F_4 ,
V_85 , V_77 -> V_16 . V_68 , V_77 ) ;
if ( F_19 ( V_63 ) ) {
F_21 ( V_77 ) ;
return;
}
F_32 ( & V_77 -> V_16 ,
V_77 -> V_14 . V_28 / V_29 , 1 , 0xfffe ) ;
}
static void T_6 F_33 ( struct V_86 * V_2 )
{
unsigned int V_10 ;
void T_7 * V_87 ;
struct V_61 * V_88 , * V_89 ;
static int V_90 ;
int V_91 ;
if ( V_90 )
return;
V_90 = 1 ;
V_87 = F_34 ( V_2 , 0 ) ;
if ( ! V_87 ) {
F_35 ( L_4 ) ;
F_36 () ;
}
V_10 = F_37 ( V_2 , 1 ) ;
if ( V_10 <= 0 ) {
F_35 ( L_5 ) ;
F_36 () ;
}
V_91 = F_2 ( V_87 + V_53 ) ;
V_91 = ! ! ( V_91 & V_92 ) ;
V_88 = F_38 ( V_2 , V_91 ) ;
if ( F_39 ( V_88 ) ) {
F_35 ( L_6 ) ;
F_36 () ;
}
V_91 = F_2 ( V_87 + 4 + V_53 ) ;
V_91 = ! ! ( V_91 & V_92 ) ;
V_89 = F_38 ( V_2 , V_91 ) ;
if ( F_39 ( V_89 ) ) {
F_35 ( L_6 ) ;
F_36 () ;
}
F_17 ( V_88 , V_87 ) ;
F_30 ( V_89 , V_87 + 4 , V_10 ) ;
F_40 ( L_7 , V_2 -> V_68 , V_87 , V_10 ) ;
}
