void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = NULL ;
if ( F_2 ( V_2 ) -> V_8 == 0 ) {
V_4 -> V_9 = V_10 ;
return;
}
while ( ( V_7 = F_3 ( V_11 << 8 , V_7 ) ) ) {
if ( V_7 -> V_12 == V_13 ) {
unsigned short V_14 = V_7 -> V_15 & V_16 ;
V_4 -> V_17 = V_14 ;
if ( V_14 == V_18 ) {
V_4 -> V_9 = V_19 ;
F_4 ( L_1 ) ;
F_5 ( ! F_6 ( V_2 ) ) ;
} else if ( V_14 == V_20 ) {
V_4 -> V_9 = V_21 ;
F_4 ( L_2 ) ;
F_5 ( ! ( F_7 ( V_2 ) || F_8 ( V_2 ) ) ) ;
} else if ( V_14 == V_22 ) {
V_4 -> V_9 = V_21 ;
F_4 ( L_3 ) ;
F_5 ( ! ( F_7 ( V_2 ) || F_8 ( V_2 ) ) ) ;
} else if ( V_14 == V_23 ) {
V_4 -> V_9 = V_24 ;
F_4 ( L_4 ) ;
F_5 ( ! F_9 ( V_2 ) ) ;
F_5 ( F_10 ( V_2 ) ) ;
} else if ( F_11 ( V_2 ) ) {
V_4 -> V_9 = V_24 ;
V_4 -> V_17 =
V_25 ;
F_4 ( L_5
L_6 ) ;
} else if ( V_14 == V_25 ) {
V_4 -> V_9 = V_24 ;
F_4 ( L_7 ) ;
F_5 ( ! F_9 ( V_2 ) ) ;
F_5 ( ! F_10 ( V_2 ) ) ;
} else
continue;
break;
}
}
if ( ! V_7 )
F_4 ( L_8 ) ;
F_12 ( V_7 ) ;
}
bool F_13 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) -> V_26 < 6 )
return false ;
if ( V_27 . V_28 >= 0 )
return V_27 . V_28 ;
if ( F_14 ( V_2 ) )
return false ;
#ifdef F_15
if ( F_2 ( V_2 ) -> V_26 == 6 && V_29 )
return false ;
#endif
return true ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_30 * V_31 ;
F_17 ( V_4 ) ;
F_18 ( & V_4 -> V_32 ) ;
V_4 -> V_33 = V_34 ;
F_19 ( & V_4 -> V_32 ) ;
F_20 ( V_4 , true ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 -> V_35 ) ;
if ( F_23 ( V_2 , V_36 ) ) {
int error ;
error = F_24 ( V_2 ) ;
if ( error ) {
F_25 ( & V_2 -> V_35 -> V_2 ,
L_9 ) ;
return error ;
}
F_26 ( & V_4 -> V_37 . V_38 ) ;
F_27 ( V_2 ) ;
V_4 -> V_39 = false ;
F_18 ( & V_2 -> V_40 . V_41 ) ;
F_28 (crtc, &dev->mode_config.crtc_list, head)
V_4 -> V_42 . V_43 ( V_31 ) ;
F_19 ( & V_2 -> V_40 . V_41 ) ;
F_29 ( V_2 ) ;
}
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
F_34 () ;
F_35 ( V_2 , V_44 ) ;
F_36 () ;
V_4 -> V_45 ++ ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 , T_1 V_46 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_38 ( L_10 , V_2 ) ;
F_38 ( L_11 ) ;
return - V_47 ;
}
if ( V_46 . V_48 == V_49 )
return 0 ;
if ( V_2 -> V_50 == V_51 )
return 0 ;
error = F_16 ( V_2 ) ;
if ( error )
return error ;
if ( V_46 . V_48 == V_52 ) {
F_39 ( V_2 -> V_35 ) ;
F_40 ( V_2 -> V_35 , V_53 ) ;
}
return 0 ;
}
void F_41 ( struct V_54 * V_55 )
{
struct V_3 * V_4 =
F_42 ( V_55 , struct V_3 ,
V_56 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_34 () ;
F_35 ( V_2 , V_57 ) ;
F_36 () ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_58 * V_40 = & V_2 -> V_40 ;
struct V_59 * V_60 ;
F_18 ( & V_40 -> V_41 ) ;
F_4 ( L_12 ) ;
F_28 (encoder, &mode_config->encoder_list, base.head)
if ( V_60 -> V_61 )
V_60 -> V_61 ( V_60 ) ;
F_19 ( & V_40 -> V_41 ) ;
F_44 ( V_2 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( V_4 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , bool V_62 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int error = 0 ;
if ( F_23 ( V_2 , V_36 ) &&
V_62 ) {
F_18 ( & V_2 -> V_63 ) ;
F_50 ( V_2 ) ;
F_19 ( & V_2 -> V_63 ) ;
}
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
if ( F_23 ( V_2 , V_36 ) ) {
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
F_18 ( & V_2 -> V_63 ) ;
error = F_55 ( V_2 ) ;
F_19 ( & V_2 -> V_63 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 , true ) ;
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
V_4 -> V_39 = true ;
F_43 ( V_2 ) ;
}
F_62 ( V_2 ) ;
if ( F_63 () ) {
F_35 ( V_2 , V_57 ) ;
F_36 () ;
} else {
F_64 ( & V_4 -> V_56 ) ;
}
F_18 ( & V_4 -> V_32 ) ;
V_4 -> V_33 = V_64 ;
F_19 ( & V_4 -> V_32 ) ;
F_65 ( V_4 ) ;
return error ;
}
static int F_66 ( struct V_1 * V_2 )
{
if ( F_23 ( V_2 , V_36 ) )
F_67 ( V_2 ) ;
return F_49 ( V_2 , true ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_50 == V_51 )
return 0 ;
if ( F_69 ( V_2 -> V_35 ) )
return - V_65 ;
F_70 ( V_2 -> V_35 ) ;
return F_45 ( V_2 ) ;
}
int F_71 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
V_66 = F_49 ( V_2 , ! V_4 -> V_67 . V_68 ) ;
if ( V_66 )
return V_66 ;
F_72 ( V_2 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
F_68 ( V_2 ) ;
F_71 ( V_2 ) ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
bool V_69 ;
int V_66 ;
if ( ! V_27 . V_70 )
return 0 ;
F_18 ( & V_2 -> V_63 ) ;
F_75 ( V_2 ) ;
V_69 = V_4 -> V_71 . V_72 != 0 ;
V_66 = F_76 ( V_2 ) ;
if ( V_69 ) {
F_77 ( L_13 ) ;
V_4 -> V_71 . V_72 = 0 ;
if ( V_66 == - V_47 ) {
F_77 ( L_14
L_15 ) ;
V_66 = 0 ;
}
}
if ( V_66 ) {
F_38 ( L_16 , V_66 ) ;
F_19 ( & V_2 -> V_63 ) ;
return V_66 ;
}
if ( F_23 ( V_2 , V_36 ) ||
! V_4 -> V_73 . V_74 ) {
V_4 -> V_73 . V_74 = 0 ;
V_66 = F_55 ( V_2 ) ;
F_19 ( & V_2 -> V_63 ) ;
if ( V_66 ) {
F_38 ( L_17 , V_66 ) ;
return V_66 ;
}
F_27 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_26 > 5 ) {
F_18 ( & V_2 -> V_63 ) ;
F_78 ( V_2 ) ;
F_19 ( & V_2 -> V_63 ) ;
}
F_61 ( V_2 ) ;
} else {
F_19 ( & V_2 -> V_63 ) ;
}
return 0 ;
}
static int F_79 ( struct V_6 * V_35 , const struct V_75 * V_76 )
{
struct V_77 * V_78 =
(struct V_77 * ) V_76 -> V_79 ;
if ( F_80 ( V_78 ) && ! V_27 . V_80 ) {
F_77 ( L_18
L_19 ) ;
return - V_47 ;
}
if ( F_81 ( V_35 -> V_81 ) )
return - V_47 ;
V_82 . V_83 &= ~ ( V_84 ) ;
return F_82 ( V_35 , V_76 , & V_82 ) ;
}
static void
F_83 ( struct V_6 * V_35 )
{
struct V_1 * V_2 = F_84 ( V_35 ) ;
F_85 ( V_2 ) ;
}
static int F_86 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_87 ( V_2 ) ;
struct V_1 * V_85 = F_84 ( V_35 ) ;
if ( ! V_85 || ! V_85 -> V_5 ) {
F_25 ( V_2 , L_11 ) ;
return - V_47 ;
}
if ( V_85 -> V_50 == V_51 )
return 0 ;
return F_16 ( V_85 ) ;
}
static int F_88 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_87 ( V_2 ) ;
struct V_1 * V_85 = F_84 ( V_35 ) ;
if ( V_85 -> V_50 == V_51 )
return 0 ;
F_39 ( V_35 ) ;
F_40 ( V_35 , V_53 ) ;
return 0 ;
}
static int F_89 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_87 ( V_2 ) ;
struct V_1 * V_85 = F_84 ( V_35 ) ;
return F_68 ( V_85 ) ;
}
static int F_90 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_87 ( V_2 ) ;
struct V_1 * V_85 = F_84 ( V_35 ) ;
return F_71 ( V_85 ) ;
}
static int F_91 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_87 ( V_2 ) ;
struct V_1 * V_85 = F_84 ( V_35 ) ;
if ( ! V_85 || ! V_85 -> V_5 ) {
F_25 ( V_2 , L_11 ) ;
return - V_47 ;
}
return F_16 ( V_85 ) ;
}
static int F_92 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_87 ( V_2 ) ;
struct V_1 * V_85 = F_84 ( V_35 ) ;
return F_45 ( V_85 ) ;
}
static int F_93 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_87 ( V_2 ) ;
struct V_1 * V_85 = F_84 ( V_35 ) ;
return F_66 ( V_85 ) ;
}
static int F_94 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_87 ( V_2 ) ;
struct V_1 * V_85 = F_84 ( V_35 ) ;
return F_16 ( V_85 ) ;
}
static int F_95 ( struct V_15 * V_15 )
{
struct V_6 * V_35 = F_87 ( V_15 ) ;
struct V_1 * V_2 = F_84 ( V_35 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( ! F_96 ( V_2 ) ) ;
F_97 ( V_4 ) ;
F_4 ( L_20 ) ;
if ( F_98 ( V_2 ) )
F_99 ( V_4 ) ;
F_100 ( V_4 ) ;
F_101 ( & V_4 -> V_71 . V_86 ) ;
V_4 -> V_87 . V_88 = true ;
F_102 ( V_2 , V_89 ) ;
F_4 ( L_21 ) ;
return 0 ;
}
static int F_103 ( struct V_15 * V_15 )
{
struct V_6 * V_35 = F_87 ( V_15 ) ;
struct V_1 * V_2 = F_84 ( V_35 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( ! F_96 ( V_2 ) ) ;
F_4 ( L_22 ) ;
F_102 ( V_2 , V_90 ) ;
V_4 -> V_87 . V_88 = false ;
if ( F_98 ( V_2 ) )
F_104 ( V_4 ) ;
F_4 ( L_23 ) ;
return 0 ;
}
static int T_2 F_105 ( void )
{
V_82 . V_91 = V_92 ;
#if F_106 ( V_93 )
if ( V_27 . V_94 != 0 )
V_82 . V_83 |= V_36 ;
#endif
if ( V_27 . V_94 == 1 )
V_82 . V_83 |= V_36 ;
#ifdef F_107
if ( F_108 () && V_27 . V_94 == - 1 )
V_82 . V_83 &= ~ V_36 ;
#endif
if ( ! ( V_82 . V_83 & V_36 ) ) {
V_82 . V_95 = NULL ;
#ifndef F_109
return 0 ;
#endif
}
return F_110 ( & V_82 , & V_96 ) ;
}
static void T_3 F_111 ( void )
{
#ifndef F_109
if ( ! ( V_82 . V_83 & V_36 ) )
return;
#endif
F_112 ( & V_82 , & V_96 ) ;
}
