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
} else if ( F_11 ( V_2 ) ) {
V_4 -> V_9 = V_25 ;
V_4 -> V_18 =
V_26 ;
F_4 ( L_5
L_6 ) ;
} else if ( V_15 == V_26 ) {
V_4 -> V_9 = V_25 ;
F_4 ( L_7 ) ;
F_5 ( ! F_9 ( V_2 ) ) ;
F_5 ( ! F_10 ( V_2 ) ) ;
} else {
goto V_27;
}
F_12 ( V_7 ) ;
break;
}
V_27:
V_7 = F_3 ( V_11 << 8 , V_12 ) ;
F_12 ( V_12 ) ;
}
if ( ! V_7 )
F_4 ( L_8 ) ;
}
bool F_13 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) -> V_28 < 6 )
return 0 ;
if ( F_14 ( V_2 ) ) {
F_5 ( ! V_29 ) ;
return 0 ;
}
if ( V_30 >= 0 )
return V_30 ;
#ifdef F_15
if ( F_2 ( V_2 ) -> V_28 == 6 && V_31 )
return false ;
#endif
return 1 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_32 * V_33 ;
F_17 ( & V_4 -> V_34 ) ;
V_4 -> V_35 = V_36 ;
F_18 ( & V_4 -> V_34 ) ;
F_19 ( V_4 ) ;
F_20 ( V_2 , true ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 -> V_37 ) ;
if ( F_23 ( V_2 , V_38 ) ) {
int error ;
error = F_24 ( V_2 ) ;
if ( error ) {
F_25 ( & V_2 -> V_37 -> V_2 ,
L_9 ) ;
return error ;
}
F_26 ( & V_4 -> V_39 . V_40 ) ;
F_27 ( V_2 ) ;
V_4 -> V_41 = false ;
F_17 ( & V_2 -> V_42 . V_43 ) ;
F_28 (crtc, &dev->mode_config.crtc_list, head)
V_4 -> V_44 . V_45 ( V_33 ) ;
F_18 ( & V_2 -> V_42 . V_43 ) ;
F_29 ( V_2 ) ;
}
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
F_33 () ;
F_34 ( V_2 , V_46 ) ;
F_35 () ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 , T_1 V_47 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_37 ( L_10 , V_2 ) ;
F_37 ( L_11 ) ;
return - V_48 ;
}
if ( V_47 . V_49 == V_50 )
return 0 ;
if ( V_2 -> V_51 == V_52 )
return 0 ;
error = F_16 ( V_2 ) ;
if ( error )
return error ;
if ( V_47 . V_49 == V_53 ) {
F_38 ( V_2 -> V_37 ) ;
F_39 ( V_2 -> V_37 , V_54 ) ;
}
return 0 ;
}
void F_40 ( struct V_55 * V_56 )
{
struct V_3 * V_4 =
F_41 ( V_56 , struct V_3 ,
V_57 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_33 () ;
F_34 ( V_2 , V_58 ) ;
F_35 () ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_59 * V_42 = & V_2 -> V_42 ;
struct V_60 * V_61 ;
F_17 ( & V_42 -> V_43 ) ;
F_4 ( L_12 ) ;
F_28 (encoder, &mode_config->encoder_list, base.head)
if ( V_61 -> V_62 )
V_61 -> V_62 ( V_61 ) ;
F_18 ( & V_42 -> V_43 ) ;
F_43 ( V_2 ) ;
}
static int F_44 ( struct V_1 * V_2 , bool V_63 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int error = 0 ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
if ( F_23 ( V_2 , V_38 ) &&
V_63 ) {
F_17 ( & V_2 -> V_64 ) ;
F_47 ( V_2 ) ;
F_18 ( & V_2 -> V_64 ) ;
}
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
if ( F_23 ( V_2 , V_38 ) ) {
F_51 ( V_2 ) ;
F_17 ( & V_2 -> V_64 ) ;
error = F_52 ( V_2 ) ;
F_18 ( & V_2 -> V_64 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 , true ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
V_4 -> V_41 = true ;
F_42 ( V_2 ) ;
}
F_60 ( V_2 ) ;
if ( F_61 () ) {
F_34 ( V_2 , V_58 ) ;
F_35 () ;
} else {
F_62 ( & V_4 -> V_57 ) ;
}
F_63 ( V_4 ) ;
F_17 ( & V_4 -> V_34 ) ;
V_4 -> V_35 = V_65 ;
F_18 ( & V_4 -> V_34 ) ;
return error ;
}
static int F_64 ( struct V_1 * V_2 )
{
if ( F_23 ( V_2 , V_38 ) )
F_65 ( V_2 ) ;
return F_44 ( V_2 , true ) ;
}
int F_66 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
if ( V_2 -> V_51 == V_52 )
return 0 ;
if ( F_67 ( V_2 -> V_37 ) )
return - V_67 ;
F_68 ( V_2 -> V_37 ) ;
V_66 = F_44 ( V_2 , ! V_4 -> V_68 . V_69 ) ;
if ( V_66 )
return V_66 ;
F_69 ( V_2 ) ;
return 0 ;
}
int F_70 ( struct V_1 * V_2 )
{
T_2 * V_4 = V_2 -> V_5 ;
bool V_70 ;
int V_66 ;
if ( ! V_71 )
return 0 ;
F_17 ( & V_2 -> V_64 ) ;
F_71 ( V_2 ) ;
V_70 = V_4 -> V_72 . V_73 != 0 ;
V_66 = F_72 ( V_2 ) ;
if ( V_70 ) {
F_73 ( L_13 ) ;
V_4 -> V_72 . V_73 = 0 ;
if ( V_66 == - V_48 ) {
F_37 ( L_14
L_15 ) ;
V_66 = 0 ;
}
}
if ( V_66 ) {
F_37 ( L_16 ) ;
F_18 ( & V_2 -> V_64 ) ;
return V_66 ;
}
if ( F_23 ( V_2 , V_38 ) ||
! V_4 -> V_74 . V_75 ) {
bool V_76 = V_4 -> V_76 ;
V_4 -> V_74 . V_75 = 0 ;
V_66 = F_52 ( V_2 ) ;
if ( ! V_76 && V_4 -> V_76 )
F_37 ( L_17 ) ;
F_18 ( & V_2 -> V_64 ) ;
if ( V_66 ) {
F_37 ( L_18 , V_66 ) ;
return V_66 ;
}
F_27 ( V_2 ) ;
F_53 ( V_2 ) ;
F_59 ( V_2 ) ;
} else {
F_18 ( & V_2 -> V_64 ) ;
}
return 0 ;
}
static int F_74 ( struct V_6 * V_37 , const struct V_77 * V_78 )
{
struct V_79 * V_80 =
(struct V_79 * ) V_78 -> V_81 ;
if ( F_75 ( V_80 ) && ! V_29 ) {
F_73 ( L_19
L_20 ) ;
return - V_48 ;
}
if ( F_76 ( V_37 -> V_82 ) )
return - V_48 ;
if ( V_80 -> V_28 != 3 ) {
V_83 . V_84 &=
~ ( V_85 | V_86 ) ;
} else if ( ! V_87 ) {
F_37 ( L_21 ) ;
return - V_48 ;
}
return F_77 ( V_37 , V_78 , & V_83 ) ;
}
static void
F_78 ( struct V_6 * V_37 )
{
struct V_1 * V_2 = F_79 ( V_37 ) ;
F_80 ( V_2 ) ;
}
static int F_81 ( struct V_16 * V_2 )
{
struct V_6 * V_37 = F_82 ( V_2 ) ;
struct V_1 * V_88 = F_79 ( V_37 ) ;
int error ;
if ( ! V_88 || ! V_88 -> V_5 ) {
F_25 ( V_2 , L_11 ) ;
return - V_48 ;
}
if ( V_88 -> V_51 == V_52 )
return 0 ;
error = F_16 ( V_88 ) ;
if ( error )
return error ;
F_38 ( V_37 ) ;
F_39 ( V_37 , V_54 ) ;
return 0 ;
}
static int F_83 ( struct V_16 * V_2 )
{
struct V_6 * V_37 = F_82 ( V_2 ) ;
struct V_1 * V_88 = F_79 ( V_37 ) ;
return F_66 ( V_88 ) ;
}
static int F_84 ( struct V_16 * V_2 )
{
struct V_6 * V_37 = F_82 ( V_2 ) ;
struct V_1 * V_88 = F_79 ( V_37 ) ;
if ( ! V_88 || ! V_88 -> V_5 ) {
F_25 ( V_2 , L_11 ) ;
return - V_48 ;
}
return F_16 ( V_88 ) ;
}
static int F_85 ( struct V_16 * V_2 )
{
struct V_6 * V_37 = F_82 ( V_2 ) ;
struct V_1 * V_88 = F_79 ( V_37 ) ;
return F_64 ( V_88 ) ;
}
static int F_86 ( struct V_16 * V_2 )
{
struct V_6 * V_37 = F_82 ( V_2 ) ;
struct V_1 * V_88 = F_79 ( V_37 ) ;
return F_16 ( V_88 ) ;
}
static int T_3 F_87 ( void )
{
V_83 . V_89 = V_90 ;
#if F_88 ( V_91 )
if ( V_92 != 0 )
V_83 . V_84 |= V_38 ;
#endif
if ( V_92 == 1 )
V_83 . V_84 |= V_38 ;
#ifdef F_89
if ( F_90 () && V_92 == - 1 )
V_83 . V_84 &= ~ V_38 ;
#endif
if ( ! ( V_83 . V_84 & V_38 ) )
V_83 . V_93 = NULL ;
return F_91 ( & V_83 , & V_94 ) ;
}
static void T_4 F_92 ( void )
{
F_93 ( & V_83 , & V_94 ) ;
}
