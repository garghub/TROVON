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
F_17 ( V_2 , true ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 -> V_36 ) ;
if ( F_20 ( V_2 , V_37 ) ) {
int error = F_21 ( V_2 ) ;
if ( error ) {
F_22 ( & V_2 -> V_36 -> V_2 ,
L_7 ) ;
return error ;
}
F_23 ( & V_4 -> V_38 . V_39 ) ;
F_24 ( V_2 ) ;
V_4 -> V_40 = false ;
F_25 (crtc, &dev->mode_config.crtc_list, head)
V_4 -> V_41 . V_42 ( V_32 ) ;
F_26 ( V_2 ) ;
}
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 () ;
F_30 ( V_2 , V_43 ) ;
F_31 () ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , T_1 V_44 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_33 ( L_8 , V_2 ) ;
F_33 ( L_9 ) ;
return - V_45 ;
}
if ( V_44 . V_46 == V_47 )
return 0 ;
if ( V_2 -> V_48 == V_49 )
return 0 ;
error = F_14 ( V_2 ) ;
if ( error )
return error ;
if ( V_44 . V_46 == V_50 ) {
F_34 ( V_2 -> V_36 ) ;
F_35 ( V_2 -> V_36 , V_51 ) ;
}
return 0 ;
}
void F_36 ( struct V_52 * V_53 )
{
struct V_3 * V_4 =
F_37 ( V_53 , struct V_3 ,
V_54 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_29 () ;
F_30 ( V_2 , V_55 ) ;
F_31 () ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = & V_2 -> V_57 ;
struct V_58 * V_59 ;
F_15 ( & V_57 -> V_60 ) ;
F_4 ( L_10 ) ;
F_25 (encoder, &mode_config->encoder_list, base.head)
if ( V_59 -> V_61 )
V_59 -> V_61 ( V_59 ) ;
F_16 ( & V_57 -> V_60 ) ;
F_39 ( V_2 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int error = 0 ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
if ( F_20 ( V_2 , V_37 ) ) {
F_43 ( V_2 ) ;
F_15 ( & V_2 -> V_62 ) ;
V_4 -> V_63 . V_64 = 0 ;
error = F_44 ( V_2 ) ;
F_16 ( & V_2 -> V_62 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 , true ) ;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
V_4 -> V_40 = true ;
F_38 ( V_2 ) ;
}
F_51 ( V_2 ) ;
if ( F_52 () ) {
F_30 ( V_2 , V_55 ) ;
F_31 () ;
} else {
F_53 ( & V_4 -> V_54 ) ;
}
F_15 ( & V_4 -> V_33 ) ;
V_4 -> V_34 = V_65 ;
F_16 ( & V_4 -> V_33 ) ;
return error ;
}
static int F_54 ( struct V_1 * V_2 )
{
int error = 0 ;
F_55 ( V_2 ) ;
if ( F_20 ( V_2 , V_37 ) ) {
F_15 ( & V_2 -> V_62 ) ;
F_56 ( V_2 ) ;
F_16 ( & V_2 -> V_62 ) ;
}
F_40 ( V_2 ) ;
return error ;
}
int F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
if ( V_2 -> V_48 == V_49 )
return 0 ;
if ( F_58 ( V_2 -> V_36 ) )
return - V_67 ;
F_59 ( V_2 -> V_36 ) ;
F_55 ( V_2 ) ;
if ( F_20 ( V_2 , V_37 ) &&
! V_4 -> V_68 . V_69 ) {
F_15 ( & V_2 -> V_62 ) ;
F_56 ( V_2 ) ;
F_16 ( & V_2 -> V_62 ) ;
}
V_66 = F_40 ( V_2 ) ;
if ( V_66 )
return V_66 ;
F_60 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_62 ( V_2 ) )
return - V_45 ;
F_63 ( V_70 , F_64 ( V_70 ) | V_71 ) ;
F_65 ( V_70 ) ;
if ( F_66 ( V_2 ) || F_67 ( V_2 ) ) {
F_63 ( V_72 ,
V_73 |
V_74 |
V_75 ) ;
F_65 ( V_72 ) ;
F_68 ( 1 ) ;
F_63 ( V_72 , 0 ) ;
F_65 ( V_72 ) ;
}
F_68 ( 1 ) ;
F_63 ( V_70 , F_64 ( V_70 ) & ~ V_71 ) ;
F_65 ( V_70 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
T_2 V_76 ;
F_70 ( V_2 -> V_36 , V_77 , & V_76 ) ;
return ( V_76 & V_78 ) == 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_66 ;
T_2 V_76 ;
F_70 ( V_2 -> V_36 , V_77 , & V_76 ) ;
F_72 ( V_2 -> V_36 , V_77 ,
V_76 | V_79 |
V_78 ) ;
V_66 = F_73 ( F_69 ( V_2 ) , 500 ) ;
if ( V_66 )
return V_66 ;
F_70 ( V_2 -> V_36 , V_77 , & V_76 ) ;
F_72 ( V_2 -> V_36 , V_77 ,
V_76 | V_80 |
V_78 ) ;
return F_73 ( F_69 ( V_2 ) , 500 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_76 ;
int V_66 ;
V_76 = F_64 ( V_81 + V_82 ) ;
V_76 &= ~ V_83 ;
F_63 ( V_81 + V_82 ,
V_76 | V_79 | V_78 ) ;
V_66 = F_73 ( F_64 ( V_81 + V_82 ) & 0x1 , 500 ) ;
if ( V_66 )
return V_66 ;
V_76 = F_64 ( V_81 + V_82 ) ;
V_76 &= ~ V_83 ;
F_63 ( V_81 + V_82 ,
V_76 | V_80 | V_78 ) ;
return F_73 ( F_64 ( V_81 + V_82 ) & 0x1 , 500 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_66 ;
unsigned long V_84 ;
F_76 ( & V_4 -> V_85 , V_84 ) ;
F_77 ( V_86 , V_87 ) ;
V_66 = F_73 ( ( F_78 ( V_86 ) & V_87 ) == 0 , 500 ) ;
if ( V_4 -> V_88 )
V_4 -> V_89 . V_90 ( V_4 ) ;
else
V_4 -> V_89 . V_91 ( V_4 ) ;
V_4 -> V_92 = F_78 ( V_93 ) ;
F_79 ( & V_4 -> V_85 , V_84 ) ;
return V_66 ;
}
int F_80 ( struct V_1 * V_2 )
{
switch ( F_2 ( V_2 ) -> V_28 ) {
case 7 :
case 6 : return F_75 ( V_2 ) ;
case 5 : return F_74 ( V_2 ) ;
case 4 : return F_71 ( V_2 ) ;
case 2 : return F_61 ( V_2 ) ;
default: return - V_45 ;
}
}
int F_81 ( struct V_1 * V_2 )
{
T_4 * V_4 = V_2 -> V_5 ;
bool V_94 ;
int V_66 ;
if ( ! V_95 )
return 0 ;
F_15 ( & V_2 -> V_62 ) ;
F_82 ( V_2 ) ;
V_94 = V_4 -> V_96 . V_97 != 0 ;
if ( ! V_94 && F_83 () - V_4 -> V_96 . V_98 < 5 ) {
F_33 ( L_11 ) ;
V_66 = - V_45 ;
} else {
V_66 = F_80 ( V_2 ) ;
if ( V_94 ) {
F_84 ( L_12 ) ;
V_4 -> V_96 . V_97 = 0 ;
if ( V_66 == - V_45 ) {
F_33 ( L_13
L_14 ) ;
V_66 = 0 ;
}
} else
V_4 -> V_96 . V_98 = F_83 () ;
}
if ( V_66 ) {
F_33 ( L_15 ) ;
F_16 ( & V_2 -> V_62 ) ;
return V_66 ;
}
if ( F_20 ( V_2 , V_37 ) ||
! V_4 -> V_63 . V_64 ) {
struct V_99 * V_100 ;
int V_101 ;
V_4 -> V_63 . V_64 = 0 ;
F_85 ( V_2 ) ;
F_86 (ring, dev_priv, i)
V_100 -> V_102 ( V_100 ) ;
F_87 ( V_2 ) ;
if ( V_4 -> V_63 . V_103 ) {
V_66 = V_4 -> V_63 . V_103 -> V_104 ( V_2 ) ;
if ( V_66 )
F_88 ( V_2 ) ;
}
F_16 ( & V_2 -> V_62 ) ;
F_24 ( V_2 ) ;
F_45 ( V_2 ) ;
F_50 ( V_2 ) ;
} else {
F_16 ( & V_2 -> V_62 ) ;
}
return 0 ;
}
static int F_89 ( struct V_6 * V_36 , const struct V_105 * V_106 )
{
struct V_107 * V_108 =
(struct V_107 * ) V_106 -> V_109 ;
if ( F_90 ( V_36 -> V_110 ) )
return - V_45 ;
if ( V_108 -> V_28 != 3 ) {
V_111 . V_112 &=
~ ( V_113 | V_114 ) ;
} else if ( ! V_115 ) {
F_33 ( L_16 ) ;
return - V_45 ;
}
return F_91 ( V_36 , V_106 , & V_111 ) ;
}
static void
F_92 ( struct V_6 * V_36 )
{
struct V_1 * V_2 = F_93 ( V_36 ) ;
F_94 ( V_2 ) ;
}
static int F_95 ( struct V_16 * V_2 )
{
struct V_6 * V_36 = F_96 ( V_2 ) ;
struct V_1 * V_116 = F_93 ( V_36 ) ;
int error ;
if ( ! V_116 || ! V_116 -> V_5 ) {
F_22 ( V_2 , L_9 ) ;
return - V_45 ;
}
if ( V_116 -> V_48 == V_49 )
return 0 ;
error = F_14 ( V_116 ) ;
if ( error )
return error ;
F_34 ( V_36 ) ;
F_35 ( V_36 , V_51 ) ;
return 0 ;
}
static int F_97 ( struct V_16 * V_2 )
{
struct V_6 * V_36 = F_96 ( V_2 ) ;
struct V_1 * V_116 = F_93 ( V_36 ) ;
return F_57 ( V_116 ) ;
}
static int F_98 ( struct V_16 * V_2 )
{
struct V_6 * V_36 = F_96 ( V_2 ) ;
struct V_1 * V_116 = F_93 ( V_36 ) ;
if ( ! V_116 || ! V_116 -> V_5 ) {
F_22 ( V_2 , L_9 ) ;
return - V_45 ;
}
return F_14 ( V_116 ) ;
}
static int F_99 ( struct V_16 * V_2 )
{
struct V_6 * V_36 = F_96 ( V_2 ) ;
struct V_1 * V_116 = F_93 ( V_36 ) ;
return F_54 ( V_116 ) ;
}
static int F_100 ( struct V_16 * V_2 )
{
struct V_6 * V_36 = F_96 ( V_2 ) ;
struct V_1 * V_116 = F_93 ( V_36 ) ;
return F_14 ( V_116 ) ;
}
static int T_5 F_101 ( void )
{
V_111 . V_117 = V_118 ;
#if F_102 ( V_119 )
if ( V_120 != 0 )
V_111 . V_112 |= V_37 ;
#endif
if ( V_120 == 1 )
V_111 . V_112 |= V_37 ;
#ifdef F_103
if ( F_104 () && V_120 == - 1 )
V_111 . V_112 &= ~ V_37 ;
#endif
if ( ! ( V_111 . V_112 & V_37 ) )
V_111 . V_121 = NULL ;
return F_105 ( & V_111 , & V_122 ) ;
}
static void T_6 F_106 ( void )
{
F_107 ( & V_111 , & V_122 ) ;
}
static void
F_108 ( struct V_3 * V_4 )
{
F_77 ( V_123 , 0 ) ;
}
static void
F_109 ( struct V_3 * V_4 , T_3 V_124 )
{
if ( F_110 ( V_4 -> V_2 ) &&
( F_78 ( V_125 ) & V_126 ) ) {
F_33 ( L_17 ,
V_124 ) ;
F_77 ( V_125 , V_126 ) ;
}
}
static void
F_111 ( struct V_3 * V_4 , T_3 V_124 )
{
if ( F_110 ( V_4 -> V_2 ) &&
( F_78 ( V_125 ) & V_126 ) ) {
F_33 ( L_18 , V_124 ) ;
F_77 ( V_125 , V_126 ) ;
}
}
int F_112 ( struct V_1 * V_2 ,
void * V_127 , struct V_128 * V_129 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_130 * V_124 = V_127 ;
struct V_131 const * V_132 = V_133 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < F_113 ( V_133 ) ; V_101 ++ , V_132 ++ ) {
if ( V_132 -> V_134 == V_124 -> V_134 &&
( 1 << F_2 ( V_2 ) -> V_28 & V_132 -> V_135 ) )
break;
}
if ( V_101 == F_113 ( V_133 ) )
return - V_136 ;
switch ( V_132 -> V_137 ) {
case 8 :
V_124 -> V_138 = F_114 ( V_124 -> V_134 ) ;
break;
case 4 :
V_124 -> V_138 = F_64 ( V_124 -> V_134 ) ;
break;
case 2 :
V_124 -> V_138 = F_115 ( V_124 -> V_134 ) ;
break;
case 1 :
V_124 -> V_138 = F_116 ( V_124 -> V_134 ) ;
break;
default:
F_5 ( 1 ) ;
return - V_136 ;
}
return 0 ;
}
