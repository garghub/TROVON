static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_1 * V_6 ;
F_2 ( V_3 ) ;
V_6 = (struct V_1 * ) F_3 ( V_3 , sizeof( * V_6 ) ) ;
V_6 -> V_7 = 4 ;
V_6 -> V_8 = sizeof( * V_6 ) / 4 ;
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
V_6 -> V_11 = F_4 ( V_12 ) ;
V_6 -> V_13 = V_14 ;
V_6 -> V_15 = V_16 ;
V_6 -> V_17 = 0 ;
V_6 -> V_4 = V_4 ;
V_6 -> V_5 = V_5 ;
return V_6 ;
}
static void
F_5 ( const struct V_18 * V_19 ,
const struct V_2 * V_3 , struct V_2 * V_20 ,
struct V_21 * V_22 , enum V_23 V_24 ,
struct V_1 * V_25 , struct V_26 * V_27 ,
unsigned int V_28 )
{
struct V_29 * V_29 = F_6 ( V_19 -> V_30 ) ;
V_27 -> V_17 = ~ F_7 ( V_28 , V_25 -> V_4 , V_25 -> V_5 , 0 ) ;
V_20 -> V_31 = V_32 ;
V_20 -> V_33 = ( unsigned char * ) V_27 - V_20 -> V_34 ;
V_20 -> V_35 = F_8 ( struct V_26 , V_17 ) ;
F_9 ( V_20 , F_10 ( V_3 ) ) ;
V_20 -> V_15 = F_4 ( V_36 ) ;
if ( F_11 ( V_29 , V_20 , V_37 ) )
goto V_38;
if ( V_22 ) {
V_20 -> V_22 = V_22 ;
V_20 -> V_39 = V_24 ;
F_12 ( V_22 ) ;
}
F_13 ( V_29 , V_20 -> V_40 , V_20 ) ;
return;
V_38:
F_14 ( V_20 ) ;
}
static void
F_15 ( const struct V_18 * V_19 ,
const struct V_2 * V_3 , const struct V_26 * V_41 ,
const struct V_42 * V_43 )
{
struct V_2 * V_20 ;
struct V_1 * V_6 , * V_25 ;
struct V_26 * V_27 ;
unsigned int V_28 ;
T_2 V_44 = V_43 -> V_44 ;
V_6 = F_16 ( V_3 ) ;
V_28 = sizeof( * V_27 ) + F_17 ( V_43 ) ;
V_20 = F_18 ( sizeof( * V_25 ) + V_28 + V_45 ,
V_46 ) ;
if ( V_20 == NULL )
return;
F_19 ( V_20 , V_45 ) ;
V_25 = F_1 ( V_20 , V_6 -> V_5 , V_6 -> V_4 ) ;
F_20 ( V_20 ) ;
V_27 = (struct V_26 * ) F_3 ( V_20 , V_28 ) ;
V_27 -> V_47 = V_41 -> V_48 ;
V_27 -> V_48 = V_41 -> V_47 ;
V_27 -> V_49 = F_21 ( F_22 ( V_6 , V_41 , & V_44 ) ) ;
V_27 -> V_50 = F_21 ( F_23 ( V_41 -> V_49 ) + 1 ) ;
F_24 ( V_27 ) = V_51 | V_52 ;
if ( V_43 -> V_53 & V_54 )
F_24 ( V_27 ) |= V_55 ;
V_27 -> V_56 = V_28 / 4 ;
V_27 -> V_57 = 0 ;
V_27 -> V_17 = 0 ;
V_27 -> V_58 = 0 ;
F_25 ( V_27 , V_43 ) ;
F_5 ( V_19 , V_3 , V_20 , V_3 -> V_22 , V_59 ,
V_25 , V_27 , V_28 ) ;
}
static void
F_26 ( const struct V_18 * V_19 ,
const struct V_2 * V_3 , const struct V_26 * V_41 ,
const struct V_42 * V_43 , T_3 V_60 )
{
struct V_2 * V_20 ;
struct V_1 * V_6 , * V_25 ;
struct V_26 * V_27 ;
unsigned int V_28 ;
V_6 = F_16 ( V_3 ) ;
V_28 = sizeof( * V_27 ) + F_17 ( V_43 ) ;
V_20 = F_18 ( sizeof( * V_25 ) + V_28 + V_45 ,
V_46 ) ;
if ( V_20 == NULL )
return;
F_19 ( V_20 , V_45 ) ;
V_25 = F_1 ( V_20 , V_6 -> V_4 , V_6 -> V_5 ) ;
F_20 ( V_20 ) ;
V_27 = (struct V_26 * ) F_3 ( V_20 , V_28 ) ;
V_27 -> V_47 = V_41 -> V_47 ;
V_27 -> V_48 = V_41 -> V_48 ;
V_27 -> V_49 = F_21 ( V_60 - 1 ) ;
V_27 -> V_50 = F_21 ( F_23 ( V_41 -> V_50 ) - 1 ) ;
F_24 ( V_27 ) = V_51 ;
if ( V_43 -> V_53 & V_54 )
F_24 ( V_27 ) |= V_55 | V_61 ;
V_27 -> V_56 = V_28 / 4 ;
V_27 -> V_57 = V_41 -> V_57 ;
V_27 -> V_17 = 0 ;
V_27 -> V_58 = 0 ;
F_25 ( V_27 , V_43 ) ;
F_5 ( V_19 , V_3 , V_20 , & V_19 -> V_30 -> V_62 , V_63 ,
V_25 , V_27 , V_28 ) ;
}
static void
F_27 ( const struct V_18 * V_19 ,
const struct V_64 * V_65 ,
const struct V_2 * V_3 , const struct V_26 * V_41 ,
const struct V_42 * V_43 )
{
struct V_2 * V_20 ;
struct V_1 * V_6 , * V_25 ;
struct V_26 * V_27 ;
unsigned int V_28 ;
V_6 = F_16 ( V_3 ) ;
V_28 = sizeof( * V_27 ) + F_17 ( V_43 ) ;
V_20 = F_18 ( sizeof( * V_25 ) + V_28 + V_45 ,
V_46 ) ;
if ( V_20 == NULL )
return;
F_19 ( V_20 , V_45 ) ;
V_25 = F_1 ( V_20 , V_6 -> V_5 , V_6 -> V_4 ) ;
F_20 ( V_20 ) ;
V_27 = (struct V_26 * ) F_3 ( V_20 , V_28 ) ;
V_27 -> V_47 = V_41 -> V_48 ;
V_27 -> V_48 = V_41 -> V_47 ;
V_27 -> V_49 = F_21 ( F_23 ( V_41 -> V_50 ) ) ;
V_27 -> V_50 = F_21 ( F_23 ( V_41 -> V_49 ) + 1 ) ;
F_24 ( V_27 ) = V_52 ;
V_27 -> V_56 = V_28 / 4 ;
V_27 -> V_57 = F_4 ( V_65 -> V_66 [ V_67 ] . V_68 ) ;
V_27 -> V_17 = 0 ;
V_27 -> V_58 = 0 ;
F_25 ( V_27 , V_43 ) ;
F_5 ( V_19 , V_3 , V_20 , NULL , 0 , V_25 , V_27 , V_28 ) ;
}
static void
F_28 ( const struct V_18 * V_19 ,
const struct V_2 * V_3 , const struct V_26 * V_41 ,
const struct V_42 * V_43 )
{
struct V_2 * V_20 ;
struct V_1 * V_6 , * V_25 ;
struct V_26 * V_27 ;
unsigned int V_28 ;
V_6 = F_16 ( V_3 ) ;
V_28 = sizeof( * V_27 ) + F_17 ( V_43 ) ;
V_20 = F_18 ( sizeof( * V_25 ) + V_28 + V_45 ,
V_46 ) ;
if ( V_20 == NULL )
return;
F_19 ( V_20 , V_45 ) ;
V_25 = F_1 ( V_20 , V_6 -> V_4 , V_6 -> V_5 ) ;
F_20 ( V_20 ) ;
V_27 = (struct V_26 * ) F_3 ( V_20 , V_28 ) ;
V_27 -> V_47 = V_41 -> V_47 ;
V_27 -> V_48 = V_41 -> V_48 ;
V_27 -> V_49 = F_21 ( F_23 ( V_41 -> V_49 ) + 1 ) ;
V_27 -> V_50 = V_41 -> V_50 ;
F_24 ( V_27 ) = V_52 ;
V_27 -> V_56 = V_28 / 4 ;
V_27 -> V_57 = F_4 ( F_29 ( V_41 -> V_57 ) >> V_43 -> V_69 ) ;
V_27 -> V_17 = 0 ;
V_27 -> V_58 = 0 ;
F_25 ( V_27 , V_43 ) ;
F_5 ( V_19 , V_3 , V_20 , V_3 -> V_22 , V_59 ,
V_25 , V_27 , V_28 ) ;
}
static bool
F_30 ( const struct V_18 * V_19 ,
const struct V_2 * V_3 , const struct V_26 * V_41 ,
struct V_42 * V_43 , T_3 V_60 )
{
int V_44 ;
V_44 = F_31 ( F_16 ( V_3 ) , V_41 , F_23 ( V_41 -> V_50 ) - 1 ) ;
if ( V_44 == 0 ) {
F_32 ( V_19 -> V_70 -> V_71 ) ;
return false ;
}
F_32 ( V_19 -> V_70 -> V_72 ) ;
V_43 -> V_44 = V_44 ;
V_43 -> V_53 |= V_73 ;
if ( V_43 -> V_53 & V_74 )
F_33 ( V_43 ) ;
F_26 ( V_19 , V_3 , V_41 , V_43 , V_60 ) ;
return true ;
}
static unsigned int
F_34 ( struct V_2 * V_3 , const struct V_75 * V_76 )
{
const struct V_77 * V_78 = V_76 -> V_79 ;
struct V_18 * V_19 = F_35 ( V_76 -> V_29 ) ;
struct V_42 V_43 = {} ;
struct V_26 * V_41 , V_80 ;
if ( F_36 ( V_3 , V_76 -> V_81 , V_76 -> V_82 , V_16 ) )
return V_83 ;
V_41 = F_37 ( V_3 , V_76 -> V_82 , sizeof( V_80 ) , & V_80 ) ;
if ( V_41 == NULL )
return V_83 ;
if ( ! F_38 ( V_3 , V_76 -> V_82 , V_41 , & V_43 ) )
return V_83 ;
if ( V_41 -> V_84 && ! ( V_41 -> V_85 || V_41 -> V_86 || V_41 -> V_87 ) ) {
F_32 ( V_19 -> V_70 -> V_88 ) ;
if ( V_41 -> V_89 && V_41 -> V_90 )
V_43 . V_53 |= V_54 ;
V_43 . V_53 &= V_78 -> V_53 ;
if ( V_43 . V_53 & V_74 )
F_39 ( V_78 , & V_43 ) ;
else
V_43 . V_53 &= ~ ( V_91 |
V_92 |
V_54 ) ;
F_15 ( V_19 , V_3 , V_41 , & V_43 ) ;
return V_83 ;
} else if ( V_41 -> V_85 && ! ( V_41 -> V_86 || V_41 -> V_87 || V_41 -> V_84 ) ) {
F_30 ( V_19 , V_3 , V_41 , & V_43 , F_23 ( V_41 -> V_49 ) ) ;
return V_83 ;
}
return V_93 ;
}
static unsigned int F_40 ( void * V_94 ,
struct V_2 * V_3 ,
const struct V_95 * V_96 )
{
struct V_18 * V_19 = F_35 ( V_96 -> V_29 ) ;
enum V_23 V_24 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
struct V_42 V_43 = {} ;
const struct V_64 * V_65 ;
struct V_26 * V_41 , V_80 ;
unsigned int V_82 ;
V_98 = F_41 ( V_3 , & V_24 ) ;
if ( V_98 == NULL )
return V_101 ;
V_100 = F_42 ( V_98 ) ;
if ( V_100 == NULL )
return V_101 ;
if ( F_43 ( V_3 ) )
return V_101 ;
V_82 = F_44 ( V_3 ) ;
V_41 = F_37 ( V_3 , V_82 , sizeof( V_80 ) , & V_80 ) ;
if ( V_41 == NULL )
return V_83 ;
V_65 = & V_98 -> V_102 . V_103 ;
switch ( V_65 -> V_65 ) {
case V_104 :
if ( V_41 -> V_87 && ! F_45 ( V_105 , & V_98 -> V_106 ) ) {
F_46 ( V_98 , V_24 , V_100 -> V_107 -
F_23 ( V_41 -> V_49 ) + 1 ) ;
break;
}
if ( ! V_41 -> V_84 || V_41 -> V_85 ||
F_47 ( V_24 ) != V_67 )
break;
F_46 ( V_98 , V_24 , 0 ) ;
V_100 -> V_108 = 0 ;
F_32 ( V_19 -> V_70 -> V_109 ) ;
case V_110 :
if ( ! F_38 ( V_3 , V_82 , V_41 , & V_43 ) )
return V_83 ;
if ( ! V_41 -> V_84 && V_41 -> V_85 &&
F_47 ( V_24 ) == V_67 ) {
if ( F_30 ( V_19 , V_3 , V_41 , & V_43 ,
F_23 ( V_41 -> V_49 ) + 1 ) )
F_32 ( V_19 -> V_70 -> V_111 ) ;
return V_83 ;
}
V_100 -> V_107 = F_23 ( V_41 -> V_50 ) ;
if ( V_43 . V_53 & V_74 )
V_100 -> V_112 = V_43 . V_113 ;
break;
case V_114 :
if ( ! V_41 -> V_84 || ! V_41 -> V_85 )
break;
if ( ! F_38 ( V_3 , V_82 , V_41 , & V_43 ) )
return V_83 ;
if ( V_43 . V_53 & V_74 )
V_100 -> V_108 = V_43 . V_115 - V_100 -> V_112 ;
V_43 . V_53 &= ~ ( V_73 |
V_91 |
V_92 ) ;
F_48 ( V_43 . V_115 , V_43 . V_113 ) ;
F_27 ( V_19 , V_65 , V_3 , V_41 , & V_43 ) ;
F_46 ( V_98 , V_24 , V_100 -> V_107 - F_23 ( V_41 -> V_49 ) ) ;
F_48 ( V_43 . V_115 , V_43 . V_113 ) ;
F_28 ( V_19 , V_3 , V_41 , & V_43 ) ;
F_49 ( V_3 ) ;
return V_116 ;
default:
break;
}
F_50 ( V_3 , V_82 , V_41 , V_98 , V_24 , V_100 ) ;
return V_101 ;
}
static int F_51 ( const struct V_117 * V_76 )
{
const struct V_118 * V_119 = V_76 -> V_120 ;
if ( V_119 -> V_121 . V_102 != V_16 ||
V_119 -> V_121 . V_122 & V_123 )
return - V_124 ;
return F_52 ( V_76 -> V_125 ) ;
}
static void F_53 ( const struct V_126 * V_76 )
{
F_54 ( V_76 -> V_125 ) ;
}
static int T_4 F_55 ( void )
{
int V_127 ;
V_127 = F_56 ( V_128 ,
F_57 ( V_128 ) ) ;
if ( V_127 < 0 )
goto V_129;
V_127 = F_58 ( & V_130 ) ;
if ( V_127 < 0 )
goto V_131;
return 0 ;
V_131:
F_59 ( V_128 , F_57 ( V_128 ) ) ;
V_129:
return V_127 ;
}
static void T_5 F_60 ( void )
{
F_61 ( & V_130 ) ;
F_59 ( V_128 , F_57 ( V_128 ) ) ;
}
