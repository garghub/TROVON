void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
if ( F_2 ( V_2 ) -> V_8 == 0 ) {
V_4 -> V_9 = V_10 ;
return;
}
V_7 = F_3 ( V_11 << 8 , NULL ) ;
while ( V_7 ) {
struct V_6 * V_12 = V_7 ;
if ( V_7 -> V_13 == V_14 ) {
unsigned short V_15 ;
V_15 = V_7 -> V_16 & V_17 ;
V_4 -> V_18 = V_15 ;
if ( V_15 == V_19 ) {
V_4 -> V_9 = V_20 ;
F_4 ( L_1 ) ;
F_5 ( ! F_6 ( V_2 ) ) ;
} else if ( V_15 == V_21 ) {
V_4 -> V_9 = V_22 ;
F_4 ( L_2 ) ;
F_5 ( ! ( F_7 ( V_2 ) || F_8 ( V_2 ) ) ) ;
} else if ( V_15 == V_23 ) {
V_4 -> V_9 = V_22 ;
F_4 ( L_3 ) ;
F_5 ( ! ( F_7 ( V_2 ) || F_8 ( V_2 ) ) ) ;
} else if ( V_15 == V_24 ) {
V_4 -> V_9 = V_25 ;
F_4 ( L_4 ) ;
F_5 ( ! F_9 ( V_2 ) ) ;
F_5 ( F_10 ( V_2 ) ) ;
} else if ( V_15 == V_26 ) {
V_4 -> V_9 = V_25 ;
F_4 ( L_5 ) ;
F_5 ( ! F_9 ( V_2 ) ) ;
F_5 ( ! F_10 ( V_2 ) ) ;
} else {
goto V_27;
}
F_11 ( V_7 ) ;
break;
}
V_27:
V_7 = F_3 ( V_11 << 8 , V_12 ) ;
F_11 ( V_12 ) ;
}
if ( ! V_7 )
F_4 ( L_6 ) ;
}
bool F_12 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) -> V_28 < 6 )
return 0 ;
if ( V_29 >= 0 )
return V_29 ;
#ifdef F_13
if ( F_2 ( V_2 ) -> V_28 == 6 && V_30 )
return false ;
#endif
return 1 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 ;
F_15 ( & V_4 -> V_33 ) ;
V_4 -> V_34 = V_35 ;
F_16 ( & V_4 -> V_33 ) ;
F_17 ( V_4 ) ;
F_18 ( V_2 , true ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 -> V_36 ) ;
if ( F_21 ( V_2 , V_37 ) ) {
int error ;
F_15 ( & V_2 -> V_38 ) ;
error = F_22 ( V_2 ) ;
F_16 ( & V_2 -> V_38 ) ;
if ( error ) {
F_23 ( & V_2 -> V_36 -> V_2 ,
L_7 ) ;
return error ;
}
F_24 ( & V_4 -> V_39 . V_40 ) ;
F_25 ( V_2 ) ;
V_4 -> V_41 = false ;
F_26 (crtc, &dev->mode_config.crtc_list, head)
V_4 -> V_42 . V_43 ( V_32 ) ;
F_27 ( V_2 ) ;
}
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
F_31 () ;
F_32 ( V_2 , V_44 ) ;
F_33 () ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 , T_1 V_45 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_35 ( L_8 , V_2 ) ;
F_35 ( L_9 ) ;
return - V_46 ;
}
if ( V_45 . V_47 == V_48 )
return 0 ;
if ( V_2 -> V_49 == V_50 )
return 0 ;
error = F_14 ( V_2 ) ;
if ( error )
return error ;
if ( V_45 . V_47 == V_51 ) {
F_36 ( V_2 -> V_36 ) ;
F_37 ( V_2 -> V_36 , V_52 ) ;
}
return 0 ;
}
void F_38 ( struct V_53 * V_54 )
{
struct V_3 * V_4 =
F_39 ( V_54 , struct V_3 ,
V_55 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_31 () ;
F_32 ( V_2 , V_56 ) ;
F_33 () ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_57 * V_58 = & V_2 -> V_58 ;
struct V_59 * V_60 ;
F_15 ( & V_58 -> V_61 ) ;
F_4 ( L_10 ) ;
F_26 (encoder, &mode_config->encoder_list, base.head)
if ( V_60 -> V_62 )
V_60 -> V_62 ( V_60 ) ;
F_16 ( & V_58 -> V_61 ) ;
F_41 ( V_2 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int error = 0 ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( F_21 ( V_2 , V_37 ) ) {
F_45 ( V_2 ) ;
F_15 ( & V_2 -> V_38 ) ;
error = F_46 ( V_2 ) ;
F_16 ( & V_2 -> V_38 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
F_50 ( V_2 , true ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
V_4 -> V_41 = true ;
F_40 ( V_2 ) ;
}
F_53 ( V_2 ) ;
if ( F_54 () ) {
F_32 ( V_2 , V_56 ) ;
F_33 () ;
} else {
F_55 ( & V_4 -> V_55 ) ;
}
F_56 ( V_4 ) ;
F_15 ( & V_4 -> V_33 ) ;
V_4 -> V_34 = V_63 ;
F_16 ( & V_4 -> V_33 ) ;
return error ;
}
static int F_57 ( struct V_1 * V_2 )
{
int error = 0 ;
F_58 ( V_2 ) ;
if ( F_21 ( V_2 , V_37 ) ) {
F_15 ( & V_2 -> V_38 ) ;
F_59 ( V_2 ) ;
F_16 ( & V_2 -> V_38 ) ;
} else if ( F_21 ( V_2 , V_37 ) )
F_60 ( V_2 ) ;
F_42 ( V_2 ) ;
return error ;
}
int F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_64 ;
if ( V_2 -> V_49 == V_50 )
return 0 ;
if ( F_62 ( V_2 -> V_36 ) )
return - V_65 ;
F_63 ( V_2 -> V_36 ) ;
F_58 ( V_2 ) ;
if ( F_21 ( V_2 , V_37 ) &&
! V_4 -> V_66 . V_67 ) {
F_15 ( & V_2 -> V_38 ) ;
F_59 ( V_2 ) ;
F_16 ( & V_2 -> V_38 ) ;
}
V_64 = F_42 ( V_2 ) ;
if ( V_64 )
return V_64 ;
F_64 ( V_2 ) ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 )
{
T_2 * V_4 = V_2 -> V_5 ;
bool V_68 ;
int V_64 ;
if ( ! V_69 )
return 0 ;
F_15 ( & V_2 -> V_38 ) ;
F_66 ( V_2 ) ;
V_68 = V_4 -> V_70 . V_71 != 0 ;
if ( ! V_68 && F_67 () - V_4 -> V_70 . V_72 < 5 ) {
F_35 ( L_11 ) ;
V_64 = - V_46 ;
} else {
V_64 = F_68 ( V_2 ) ;
if ( V_68 ) {
F_69 ( L_12 ) ;
V_4 -> V_70 . V_71 = 0 ;
if ( V_64 == - V_46 ) {
F_35 ( L_13
L_14 ) ;
V_64 = 0 ;
}
} else
V_4 -> V_70 . V_72 = F_67 () ;
}
if ( V_64 ) {
F_35 ( L_15 ) ;
F_16 ( & V_2 -> V_38 ) ;
return V_64 ;
}
if ( F_21 ( V_2 , V_37 ) ||
! V_4 -> V_73 . V_74 ) {
struct V_75 * V_76 ;
int V_77 ;
V_4 -> V_73 . V_74 = 0 ;
F_70 ( V_2 ) ;
F_71 (ring, dev_priv, i)
V_76 -> V_78 ( V_76 ) ;
F_72 ( V_2 ) ;
if ( V_4 -> V_79 . V_80 ) {
V_64 = V_4 -> V_79 . V_80 -> V_81 ( V_2 ) ;
if ( V_64 )
F_73 ( V_2 ) ;
}
F_16 ( & V_2 -> V_38 ) ;
F_25 ( V_2 ) ;
F_47 ( V_2 ) ;
F_52 ( V_2 ) ;
} else {
F_16 ( & V_2 -> V_38 ) ;
}
return 0 ;
}
static int F_74 ( struct V_6 * V_36 , const struct V_82 * V_83 )
{
struct V_84 * V_85 =
(struct V_84 * ) V_83 -> V_86 ;
if ( F_75 ( V_36 -> V_87 ) )
return - V_46 ;
if ( V_85 -> V_28 != 3 ) {
V_88 . V_89 &=
~ ( V_90 | V_91 ) ;
} else if ( ! V_92 ) {
F_35 ( L_16 ) ;
return - V_46 ;
}
return F_76 ( V_36 , V_83 , & V_88 ) ;
}
static void
F_77 ( struct V_6 * V_36 )
{
struct V_1 * V_2 = F_78 ( V_36 ) ;
F_79 ( V_2 ) ;
}
static int F_80 ( struct V_16 * V_2 )
{
struct V_6 * V_36 = F_81 ( V_2 ) ;
struct V_1 * V_93 = F_78 ( V_36 ) ;
int error ;
if ( ! V_93 || ! V_93 -> V_5 ) {
F_23 ( V_2 , L_9 ) ;
return - V_46 ;
}
if ( V_93 -> V_49 == V_50 )
return 0 ;
error = F_14 ( V_93 ) ;
if ( error )
return error ;
F_36 ( V_36 ) ;
F_37 ( V_36 , V_52 ) ;
return 0 ;
}
static int F_82 ( struct V_16 * V_2 )
{
struct V_6 * V_36 = F_81 ( V_2 ) ;
struct V_1 * V_93 = F_78 ( V_36 ) ;
return F_61 ( V_93 ) ;
}
static int F_83 ( struct V_16 * V_2 )
{
struct V_6 * V_36 = F_81 ( V_2 ) ;
struct V_1 * V_93 = F_78 ( V_36 ) ;
if ( ! V_93 || ! V_93 -> V_5 ) {
F_23 ( V_2 , L_9 ) ;
return - V_46 ;
}
return F_14 ( V_93 ) ;
}
static int F_84 ( struct V_16 * V_2 )
{
struct V_6 * V_36 = F_81 ( V_2 ) ;
struct V_1 * V_93 = F_78 ( V_36 ) ;
return F_57 ( V_93 ) ;
}
static int F_85 ( struct V_16 * V_2 )
{
struct V_6 * V_36 = F_81 ( V_2 ) ;
struct V_1 * V_93 = F_78 ( V_36 ) ;
return F_14 ( V_93 ) ;
}
static int T_3 F_86 ( void )
{
V_88 . V_94 = V_95 ;
#if F_87 ( V_96 )
if ( V_97 != 0 )
V_88 . V_89 |= V_37 ;
#endif
if ( V_97 == 1 )
V_88 . V_89 |= V_37 ;
#ifdef F_88
if ( F_89 () && V_97 == - 1 )
V_88 . V_89 &= ~ V_37 ;
#endif
if ( ! ( V_88 . V_89 & V_37 ) )
V_88 . V_98 = NULL ;
return F_90 ( & V_88 , & V_99 ) ;
}
static void T_4 F_91 ( void )
{
F_92 ( & V_88 , & V_99 ) ;
}
