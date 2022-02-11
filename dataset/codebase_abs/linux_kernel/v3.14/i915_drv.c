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
if ( F_14 ( V_2 ) ) {
F_5 ( ! V_27 ) ;
return false ;
}
if ( V_28 >= 0 )
return V_28 ;
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
F_20 ( V_4 ) ;
F_21 ( V_2 , true ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 -> V_35 ) ;
if ( F_24 ( V_2 , V_36 ) ) {
int error ;
error = F_25 ( V_2 ) ;
if ( error ) {
F_26 ( & V_2 -> V_35 -> V_2 ,
L_9 ) ;
return error ;
}
F_27 ( & V_4 -> V_37 . V_38 ) ;
F_28 ( V_2 ) ;
V_4 -> V_39 = false ;
F_18 ( & V_2 -> V_40 . V_41 ) ;
F_29 (crtc, &dev->mode_config.crtc_list, head)
V_4 -> V_42 . V_43 ( V_31 ) ;
F_19 ( & V_2 -> V_40 . V_41 ) ;
F_30 ( V_2 ) ;
}
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
F_34 () ;
F_35 ( V_2 , V_44 ) ;
F_36 () ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 , T_1 V_45 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_38 ( L_10 , V_2 ) ;
F_38 ( L_11 ) ;
return - V_46 ;
}
if ( V_45 . V_47 == V_48 )
return 0 ;
if ( V_2 -> V_49 == V_50 )
return 0 ;
error = F_16 ( V_2 ) ;
if ( error )
return error ;
if ( V_45 . V_47 == V_51 ) {
F_39 ( V_2 -> V_35 ) ;
F_40 ( V_2 -> V_35 , V_52 ) ;
}
return 0 ;
}
void F_41 ( struct V_53 * V_54 )
{
struct V_3 * V_4 =
F_42 ( V_54 , struct V_3 ,
V_55 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_34 () ;
F_35 ( V_2 , V_56 ) ;
F_36 () ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_57 * V_40 = & V_2 -> V_40 ;
struct V_58 * V_59 ;
F_18 ( & V_40 -> V_41 ) ;
F_4 ( L_12 ) ;
F_29 (encoder, &mode_config->encoder_list, base.head)
if ( V_59 -> V_60 )
V_59 -> V_60 ( V_59 ) ;
F_19 ( & V_40 -> V_41 ) ;
F_44 ( V_2 ) ;
}
static int F_45 ( struct V_1 * V_2 , bool V_61 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int error = 0 ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
if ( F_24 ( V_2 , V_36 ) &&
V_61 ) {
F_18 ( & V_2 -> V_62 ) ;
F_48 ( V_2 ) ;
F_19 ( & V_2 -> V_62 ) ;
}
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
if ( F_24 ( V_2 , V_36 ) ) {
F_52 ( V_2 ) ;
F_18 ( & V_2 -> V_62 ) ;
error = F_53 ( V_2 ) ;
F_19 ( & V_2 -> V_62 ) ;
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 , true ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
V_4 -> V_39 = true ;
F_43 ( V_2 ) ;
}
F_61 ( V_2 ) ;
if ( F_62 () ) {
F_35 ( V_2 , V_56 ) ;
F_36 () ;
} else {
F_63 ( & V_4 -> V_55 ) ;
}
F_64 ( V_4 ) ;
F_18 ( & V_4 -> V_32 ) ;
V_4 -> V_33 = V_63 ;
F_19 ( & V_4 -> V_32 ) ;
F_65 ( V_4 ) ;
return error ;
}
static int F_66 ( struct V_1 * V_2 )
{
if ( F_24 ( V_2 , V_36 ) )
F_67 ( V_2 ) ;
return F_45 ( V_2 , true ) ;
}
int F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_64 ;
if ( V_2 -> V_49 == V_50 )
return 0 ;
if ( F_69 ( V_2 -> V_35 ) )
return - V_65 ;
F_70 ( V_2 -> V_35 ) ;
V_64 = F_45 ( V_2 , ! V_4 -> V_66 . V_67 ) ;
if ( V_64 )
return V_64 ;
F_71 ( V_2 ) ;
return 0 ;
}
int F_72 ( struct V_1 * V_2 )
{
T_2 * V_4 = V_2 -> V_5 ;
bool V_68 ;
int V_64 ;
if ( ! V_69 )
return 0 ;
F_18 ( & V_2 -> V_62 ) ;
F_73 ( V_2 ) ;
V_68 = V_4 -> V_70 . V_71 != 0 ;
V_64 = F_74 ( V_2 ) ;
if ( V_68 ) {
F_75 ( L_13 ) ;
V_4 -> V_70 . V_71 = 0 ;
if ( V_64 == - V_46 ) {
F_75 ( L_14
L_15 ) ;
V_64 = 0 ;
}
}
if ( V_64 ) {
F_38 ( L_16 , V_64 ) ;
F_19 ( & V_2 -> V_62 ) ;
return V_64 ;
}
if ( F_24 ( V_2 , V_36 ) ||
! V_4 -> V_72 . V_73 ) {
V_4 -> V_72 . V_73 = 0 ;
V_64 = F_53 ( V_2 ) ;
F_19 ( & V_2 -> V_62 ) ;
if ( V_64 ) {
F_38 ( L_17 , V_64 ) ;
return V_64 ;
}
F_28 ( V_2 ) ;
F_54 ( V_2 ) ;
F_60 ( V_2 ) ;
} else {
F_19 ( & V_2 -> V_62 ) ;
}
return 0 ;
}
static int F_76 ( struct V_6 * V_35 , const struct V_74 * V_75 )
{
struct V_76 * V_77 =
(struct V_76 * ) V_75 -> V_78 ;
if ( F_77 ( V_77 ) && ! V_27 ) {
F_75 ( L_18
L_19 ) ;
return - V_46 ;
}
if ( F_78 ( V_35 -> V_79 ) )
return - V_46 ;
V_80 . V_81 &= ~ ( V_82 ) ;
return F_79 ( V_35 , V_75 , & V_80 ) ;
}
static void
F_80 ( struct V_6 * V_35 )
{
struct V_1 * V_2 = F_81 ( V_35 ) ;
F_82 ( V_2 ) ;
}
static int F_83 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_84 ( V_2 ) ;
struct V_1 * V_83 = F_81 ( V_35 ) ;
int error ;
if ( ! V_83 || ! V_83 -> V_5 ) {
F_26 ( V_2 , L_11 ) ;
return - V_46 ;
}
if ( V_83 -> V_49 == V_50 )
return 0 ;
error = F_16 ( V_83 ) ;
if ( error )
return error ;
F_39 ( V_35 ) ;
F_40 ( V_35 , V_52 ) ;
return 0 ;
}
static int F_85 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_84 ( V_2 ) ;
struct V_1 * V_83 = F_81 ( V_35 ) ;
return F_68 ( V_83 ) ;
}
static int F_86 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_84 ( V_2 ) ;
struct V_1 * V_83 = F_81 ( V_35 ) ;
if ( ! V_83 || ! V_83 -> V_5 ) {
F_26 ( V_2 , L_11 ) ;
return - V_46 ;
}
return F_16 ( V_83 ) ;
}
static int F_87 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_84 ( V_2 ) ;
struct V_1 * V_83 = F_81 ( V_35 ) ;
return F_66 ( V_83 ) ;
}
static int F_88 ( struct V_15 * V_2 )
{
struct V_6 * V_35 = F_84 ( V_2 ) ;
struct V_1 * V_83 = F_81 ( V_35 ) ;
return F_16 ( V_83 ) ;
}
static int F_89 ( struct V_15 * V_15 )
{
struct V_6 * V_35 = F_84 ( V_15 ) ;
struct V_1 * V_2 = F_81 ( V_35 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( ! F_90 ( V_2 ) ) ;
F_4 ( L_20 ) ;
F_91 ( V_4 ) ;
F_92 ( & V_4 -> V_70 . V_84 ) ;
V_4 -> V_85 . V_86 = true ;
F_93 ( V_2 , V_87 ) ;
return 0 ;
}
static int F_94 ( struct V_15 * V_15 )
{
struct V_6 * V_35 = F_84 ( V_15 ) ;
struct V_1 * V_2 = F_81 ( V_35 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( ! F_90 ( V_2 ) ) ;
F_4 ( L_21 ) ;
F_93 ( V_2 , V_88 ) ;
V_4 -> V_85 . V_86 = false ;
return 0 ;
}
static int T_3 F_95 ( void )
{
V_80 . V_89 = V_90 ;
#if F_96 ( V_91 )
if ( V_92 != 0 )
V_80 . V_81 |= V_36 ;
#endif
if ( V_92 == 1 )
V_80 . V_81 |= V_36 ;
#ifdef F_97
if ( F_98 () && V_92 == - 1 )
V_80 . V_81 &= ~ V_36 ;
#endif
if ( ! ( V_80 . V_81 & V_36 ) ) {
V_80 . V_93 = NULL ;
#ifndef F_99
return 0 ;
#endif
}
return F_100 ( & V_80 , & V_94 ) ;
}
static void T_4 F_101 ( void )
{
#ifndef F_99
if ( ! ( V_80 . V_81 & V_36 ) )
return;
#endif
F_102 ( & V_80 , & V_94 ) ;
}
