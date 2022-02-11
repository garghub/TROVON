void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
if ( F_2 ( V_2 ) -> V_8 == 0 ) {
V_4 -> V_9 = V_10 ;
V_4 -> V_11 = 0 ;
return;
}
V_7 = F_3 ( V_12 << 8 , NULL ) ;
if ( V_7 ) {
if ( V_7 -> V_13 == V_14 ) {
unsigned short V_15 ;
V_15 = V_7 -> V_16 & V_17 ;
V_4 -> V_18 = V_15 ;
if ( V_15 == V_19 ) {
V_4 -> V_9 = V_20 ;
V_4 -> V_11 = 2 ;
F_4 ( L_1 ) ;
F_5 ( ! F_6 ( V_2 ) ) ;
} else if ( V_15 == V_21 ) {
V_4 -> V_9 = V_22 ;
V_4 -> V_11 = 2 ;
F_4 ( L_2 ) ;
F_5 ( ! ( F_7 ( V_2 ) || F_8 ( V_2 ) ) ) ;
} else if ( V_15 == V_23 ) {
V_4 -> V_9 = V_22 ;
V_4 -> V_11 = 2 ;
F_4 ( L_3 ) ;
F_5 ( ! ( F_7 ( V_2 ) || F_8 ( V_2 ) ) ) ;
} else if ( V_15 == V_24 ) {
V_4 -> V_9 = V_25 ;
V_4 -> V_11 = 0 ;
F_4 ( L_4 ) ;
F_5 ( ! F_9 ( V_2 ) ) ;
F_5 ( F_10 ( V_2 ) ) ;
} else if ( V_15 == V_26 ) {
V_4 -> V_9 = V_25 ;
V_4 -> V_11 = 0 ;
F_4 ( L_5 ) ;
F_5 ( ! F_9 ( V_2 ) ) ;
F_5 ( ! F_10 ( V_2 ) ) ;
}
F_11 ( V_4 -> V_11 > V_27 ) ;
}
F_12 ( V_7 ) ;
}
}
bool F_13 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) -> V_28 < 6 )
return 0 ;
if ( V_29 >= 0 )
return V_29 ;
#ifdef F_14
if ( F_2 ( V_2 ) -> V_28 == 6 && V_30 )
return false ;
#endif
return 1 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 ;
F_16 ( & V_4 -> V_33 ) ;
V_4 -> V_34 = V_35 ;
F_17 ( & V_4 -> V_33 ) ;
F_18 ( V_2 , true ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 -> V_36 ) ;
if ( F_21 ( V_2 , V_37 ) ) {
int error = F_22 ( V_2 ) ;
if ( error ) {
F_23 ( & V_2 -> V_36 -> V_2 ,
L_6 ) ;
return error ;
}
F_24 ( & V_4 -> V_38 . V_39 ) ;
F_25 ( V_2 ) ;
V_4 -> V_40 = false ;
F_26 (crtc, &dev->mode_config.crtc_list, head)
V_4 -> V_41 . V_42 ( V_32 ) ;
}
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 () ;
F_30 ( V_2 , 1 ) ;
F_31 () ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , T_1 V_43 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_33 ( L_7 , V_2 ) ;
F_33 ( L_8 ) ;
return - V_44 ;
}
if ( V_43 . V_45 == V_46 )
return 0 ;
if ( V_2 -> V_47 == V_48 )
return 0 ;
error = F_15 ( V_2 ) ;
if ( error )
return error ;
if ( V_43 . V_45 == V_49 ) {
F_34 ( V_2 -> V_36 ) ;
F_35 ( V_2 -> V_36 , V_50 ) ;
}
return 0 ;
}
void F_36 ( struct V_51 * V_52 )
{
struct V_3 * V_4 =
F_37 ( V_52 , struct V_3 ,
V_53 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_29 () ;
F_30 ( V_2 , 0 ) ;
F_31 () ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = & V_2 -> V_55 ;
struct V_56 * V_57 ;
F_16 ( & V_55 -> V_58 ) ;
F_4 ( L_9 ) ;
F_26 (encoder, &mode_config->encoder_list, base.head)
if ( V_57 -> V_59 )
V_57 -> V_59 ( V_57 ) ;
F_17 ( & V_55 -> V_58 ) ;
F_39 ( V_2 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int error = 0 ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
if ( F_21 ( V_2 , V_37 ) ) {
F_43 ( V_2 ) ;
F_16 ( & V_2 -> V_60 ) ;
V_4 -> V_61 . V_62 = 0 ;
error = F_44 ( V_2 ) ;
F_17 ( & V_2 -> V_60 ) ;
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
F_30 ( V_2 , 0 ) ;
F_31 () ;
} else {
F_53 ( & V_4 -> V_53 ) ;
}
F_16 ( & V_4 -> V_33 ) ;
V_4 -> V_34 = V_63 ;
F_17 ( & V_4 -> V_33 ) ;
return error ;
}
static int F_54 ( struct V_1 * V_2 )
{
int error = 0 ;
F_55 ( V_2 ) ;
if ( F_21 ( V_2 , V_37 ) ) {
F_16 ( & V_2 -> V_60 ) ;
F_56 ( V_2 ) ;
F_17 ( & V_2 -> V_60 ) ;
}
F_40 ( V_2 ) ;
return error ;
}
int F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_64 ;
if ( V_2 -> V_47 == V_48 )
return 0 ;
if ( F_58 ( V_2 -> V_36 ) )
return - V_65 ;
F_59 ( V_2 -> V_36 ) ;
F_55 ( V_2 ) ;
if ( F_21 ( V_2 , V_37 ) &&
! V_4 -> V_66 . V_67 ) {
F_16 ( & V_2 -> V_60 ) ;
F_56 ( V_2 ) ;
F_17 ( & V_2 -> V_60 ) ;
}
V_64 = F_40 ( V_2 ) ;
if ( V_64 )
return V_64 ;
F_60 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_62 ( V_2 ) )
return - V_44 ;
F_63 ( V_68 , F_64 ( V_68 ) | V_69 ) ;
F_65 ( V_68 ) ;
if ( F_66 ( V_2 ) || F_67 ( V_2 ) ) {
F_63 ( V_70 ,
V_71 |
V_72 |
V_73 ) ;
F_65 ( V_70 ) ;
F_68 ( 1 ) ;
F_63 ( V_70 , 0 ) ;
F_65 ( V_70 ) ;
}
F_68 ( 1 ) ;
F_63 ( V_68 , F_64 ( V_68 ) & ~ V_69 ) ;
F_65 ( V_68 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
T_2 V_74 ;
F_70 ( V_2 -> V_36 , V_75 , & V_74 ) ;
return ( V_74 & V_76 ) == 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_64 ;
T_2 V_74 ;
F_70 ( V_2 -> V_36 , V_75 , & V_74 ) ;
F_72 ( V_2 -> V_36 , V_75 ,
V_74 | V_77 |
V_76 ) ;
V_64 = F_73 ( F_69 ( V_2 ) , 500 ) ;
if ( V_64 )
return V_64 ;
F_70 ( V_2 -> V_36 , V_75 , & V_74 ) ;
F_72 ( V_2 -> V_36 , V_75 ,
V_74 | V_78 |
V_76 ) ;
return F_73 ( F_69 ( V_2 ) , 500 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_74 ;
int V_64 ;
V_74 = F_64 ( V_79 + V_80 ) ;
V_74 &= ~ V_81 ;
F_63 ( V_79 + V_80 ,
V_74 | V_77 | V_76 ) ;
V_64 = F_73 ( F_64 ( V_79 + V_80 ) & 0x1 , 500 ) ;
if ( V_64 )
return V_64 ;
V_74 = F_64 ( V_79 + V_80 ) ;
V_74 &= ~ V_81 ;
F_63 ( V_79 + V_80 ,
V_74 | V_78 | V_76 ) ;
return F_73 ( F_64 ( V_79 + V_80 ) & 0x1 , 500 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_64 ;
unsigned long V_82 ;
F_76 ( & V_4 -> V_83 , V_82 ) ;
F_77 ( V_84 , V_85 ) ;
V_64 = F_73 ( ( F_78 ( V_84 ) & V_85 ) == 0 , 500 ) ;
if ( V_4 -> V_86 )
V_4 -> V_87 . V_88 ( V_4 ) ;
else
V_4 -> V_87 . V_89 ( V_4 ) ;
V_4 -> V_90 = F_78 ( V_91 ) ;
F_79 ( & V_4 -> V_83 , V_82 ) ;
return V_64 ;
}
int F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_64 = - V_44 ;
switch ( F_2 ( V_2 ) -> V_28 ) {
case 7 :
case 6 :
V_64 = F_75 ( V_2 ) ;
break;
case 5 :
V_64 = F_74 ( V_2 ) ;
break;
case 4 :
V_64 = F_71 ( V_2 ) ;
break;
case 2 :
V_64 = F_61 ( V_2 ) ;
break;
}
if ( V_4 -> V_92 . V_93 ) {
F_81 ( L_10 ) ;
V_4 -> V_92 . V_93 = 0 ;
if ( V_64 == - V_44 ) {
F_33 ( L_11
L_12 ) ;
V_64 = 0 ;
}
}
return V_64 ;
}
int F_82 ( struct V_1 * V_2 )
{
T_4 * V_4 = V_2 -> V_5 ;
int V_64 ;
if ( ! V_94 )
return 0 ;
F_16 ( & V_2 -> V_60 ) ;
F_83 ( V_2 ) ;
V_64 = - V_44 ;
if ( F_84 () - V_4 -> V_92 . V_95 < 5 )
F_33 ( L_13 ) ;
else
V_64 = F_80 ( V_2 ) ;
V_4 -> V_92 . V_95 = F_84 () ;
if ( V_64 ) {
F_33 ( L_14 ) ;
F_17 ( & V_2 -> V_60 ) ;
return V_64 ;
}
if ( F_21 ( V_2 , V_37 ) ||
! V_4 -> V_61 . V_62 ) {
struct V_96 * V_97 ;
int V_98 ;
V_4 -> V_61 . V_62 = 0 ;
F_85 ( V_2 ) ;
F_86 (ring, dev_priv, i)
V_97 -> V_99 ( V_97 ) ;
F_87 ( V_2 ) ;
if ( V_4 -> V_61 . V_100 ) {
V_64 = V_4 -> V_61 . V_100 -> V_101 ( V_2 ) ;
if ( V_64 )
F_88 ( V_2 ) ;
}
F_17 ( & V_2 -> V_60 ) ;
F_25 ( V_2 ) ;
F_45 ( V_2 ) ;
F_50 ( V_2 ) ;
} else {
F_17 ( & V_2 -> V_60 ) ;
}
return 0 ;
}
static int F_89 ( struct V_6 * V_36 , const struct V_102 * V_103 )
{
struct V_104 * V_105 =
(struct V_104 * ) V_103 -> V_106 ;
if ( V_105 -> V_107 )
if( ! V_108 ) {
F_33 ( L_15 ) ;
return - V_44 ;
}
if ( F_90 ( V_36 -> V_109 ) )
return - V_44 ;
if ( V_105 -> V_28 != 3 ) {
V_110 . V_111 &=
~ ( V_112 | V_113 ) ;
} else if ( ! V_114 ) {
F_33 ( L_16 ) ;
return - V_44 ;
}
return F_91 ( V_36 , V_103 , & V_110 ) ;
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
struct V_1 * V_115 = F_93 ( V_36 ) ;
int error ;
if ( ! V_115 || ! V_115 -> V_5 ) {
F_23 ( V_2 , L_8 ) ;
return - V_44 ;
}
if ( V_115 -> V_47 == V_48 )
return 0 ;
error = F_15 ( V_115 ) ;
if ( error )
return error ;
F_34 ( V_36 ) ;
F_35 ( V_36 , V_50 ) ;
return 0 ;
}
static int F_97 ( struct V_16 * V_2 )
{
struct V_6 * V_36 = F_96 ( V_2 ) ;
struct V_1 * V_115 = F_93 ( V_36 ) ;
return F_57 ( V_115 ) ;
}
static int F_98 ( struct V_16 * V_2 )
{
struct V_6 * V_36 = F_96 ( V_2 ) ;
struct V_1 * V_115 = F_93 ( V_36 ) ;
if ( ! V_115 || ! V_115 -> V_5 ) {
F_23 ( V_2 , L_8 ) ;
return - V_44 ;
}
return F_15 ( V_115 ) ;
}
static int F_99 ( struct V_16 * V_2 )
{
struct V_6 * V_36 = F_96 ( V_2 ) ;
struct V_1 * V_115 = F_93 ( V_36 ) ;
return F_54 ( V_115 ) ;
}
static int F_100 ( struct V_16 * V_2 )
{
struct V_6 * V_36 = F_96 ( V_2 ) ;
struct V_1 * V_115 = F_93 ( V_36 ) ;
return F_15 ( V_115 ) ;
}
static int T_5 F_101 ( void )
{
V_110 . V_116 = V_117 ;
#if F_102 ( V_118 )
if ( V_119 != 0 )
V_110 . V_111 |= V_37 ;
#endif
if ( V_119 == 1 )
V_110 . V_111 |= V_37 ;
#ifdef F_103
if ( F_104 () && V_119 == - 1 )
V_110 . V_111 &= ~ V_37 ;
#endif
if ( ! ( V_110 . V_111 & V_37 ) )
V_110 . V_120 = NULL ;
return F_105 ( & V_110 , & V_121 ) ;
}
static void T_6 F_106 ( void )
{
F_107 ( & V_110 , & V_121 ) ;
}
static void
F_108 ( struct V_3 * V_4 )
{
F_77 ( V_122 , 0 ) ;
}
static void
F_109 ( struct V_3 * V_4 , T_3 V_123 )
{
if ( F_9 ( V_4 -> V_2 ) &&
( F_78 ( V_124 ) & V_125 ) ) {
F_33 ( L_17 ,
V_123 ) ;
F_77 ( V_124 , V_125 ) ;
}
}
static void
F_110 ( struct V_3 * V_4 , T_3 V_123 )
{
if ( F_9 ( V_4 -> V_2 ) &&
( F_78 ( V_124 ) & V_125 ) ) {
F_33 ( L_18 , V_123 ) ;
F_77 ( V_124 , V_125 ) ;
}
}
int F_111 ( struct V_1 * V_2 ,
void * V_126 , struct V_127 * V_128 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_129 * V_123 = V_126 ;
struct V_130 const * V_131 = V_132 ;
int V_98 ;
for ( V_98 = 0 ; V_98 < F_112 ( V_132 ) ; V_98 ++ , V_131 ++ ) {
if ( V_131 -> V_133 == V_123 -> V_133 &&
( 1 << F_2 ( V_2 ) -> V_28 & V_131 -> V_134 ) )
break;
}
if ( V_98 == F_112 ( V_132 ) )
return - V_135 ;
switch ( V_131 -> V_136 ) {
case 8 :
V_123 -> V_137 = F_113 ( V_123 -> V_133 ) ;
break;
case 4 :
V_123 -> V_137 = F_64 ( V_123 -> V_133 ) ;
break;
case 2 :
V_123 -> V_137 = F_114 ( V_123 -> V_133 ) ;
break;
case 1 :
V_123 -> V_137 = F_115 ( V_123 -> V_133 ) ;
break;
default:
F_5 ( 1 ) ;
return - V_135 ;
}
return 0 ;
}
