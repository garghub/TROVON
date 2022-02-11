static struct V_1 *
F_1 ( struct V_2 * V_2 , struct V_3 * V_4 , T_1 V_5 ,
T_1 V_6 )
{
struct V_1 * V_7 ;
F_2 ( V_4 ) ;
V_7 = (struct V_1 * ) F_3 ( V_4 , sizeof( * V_7 ) ) ;
V_7 -> V_8 = 4 ;
V_7 -> V_9 = sizeof( * V_7 ) / 4 ;
V_7 -> V_10 = 0 ;
V_7 -> V_11 = 0 ;
V_7 -> V_12 = F_4 ( V_13 ) ;
V_7 -> V_14 = V_2 -> V_15 . V_16 ;
V_7 -> V_17 = V_18 ;
V_7 -> V_19 = 0 ;
V_7 -> V_5 = V_5 ;
V_7 -> V_6 = V_6 ;
return V_7 ;
}
static void
F_5 ( struct V_2 * V_2 ,
const struct V_3 * V_4 , struct V_3 * V_20 ,
struct V_21 * V_22 , enum V_23 V_24 ,
struct V_1 * V_25 , struct V_26 * V_27 ,
unsigned int V_28 )
{
V_27 -> V_19 = ~ F_6 ( V_28 , V_25 -> V_5 , V_25 -> V_6 , 0 ) ;
V_20 -> V_29 = V_30 ;
V_20 -> V_31 = ( unsigned char * ) V_27 - V_20 -> V_32 ;
V_20 -> V_33 = F_7 ( struct V_26 , V_19 ) ;
F_8 ( V_20 , F_9 ( V_4 ) ) ;
V_20 -> V_17 = F_4 ( V_34 ) ;
if ( F_10 ( V_2 , V_20 , V_35 ) )
goto V_36;
if ( V_22 ) {
V_20 -> V_22 = V_22 ;
V_20 -> V_37 = V_24 ;
F_11 ( V_22 ) ;
}
F_12 ( V_2 , V_20 -> V_38 , V_20 ) ;
return;
V_36:
F_13 ( V_20 ) ;
}
static void
F_14 ( struct V_2 * V_2 ,
const struct V_3 * V_4 , const struct V_26 * V_39 ,
const struct V_40 * V_41 )
{
struct V_3 * V_20 ;
struct V_1 * V_7 , * V_25 ;
struct V_26 * V_27 ;
unsigned int V_28 ;
T_2 V_42 = V_41 -> V_42 ;
V_7 = F_15 ( V_4 ) ;
V_28 = sizeof( * V_27 ) + F_16 ( V_41 ) ;
V_20 = F_17 ( sizeof( * V_25 ) + V_28 + V_43 ,
V_44 ) ;
if ( V_20 == NULL )
return;
F_18 ( V_20 , V_43 ) ;
V_25 = F_1 ( V_2 , V_20 , V_7 -> V_6 , V_7 -> V_5 ) ;
F_19 ( V_20 ) ;
V_27 = (struct V_26 * ) F_3 ( V_20 , V_28 ) ;
V_27 -> V_45 = V_39 -> V_46 ;
V_27 -> V_46 = V_39 -> V_45 ;
V_27 -> V_47 = F_20 ( F_21 ( V_7 , V_39 , & V_42 ) ) ;
V_27 -> V_48 = F_20 ( F_22 ( V_39 -> V_47 ) + 1 ) ;
F_23 ( V_27 ) = V_49 | V_50 ;
if ( V_41 -> V_51 & V_52 )
F_23 ( V_27 ) |= V_53 ;
V_27 -> V_54 = V_28 / 4 ;
V_27 -> V_55 = 0 ;
V_27 -> V_19 = 0 ;
V_27 -> V_56 = 0 ;
F_24 ( V_27 , V_41 ) ;
F_5 ( V_2 , V_4 , V_20 , V_4 -> V_22 , V_57 ,
V_25 , V_27 , V_28 ) ;
}
static void
F_25 ( struct V_2 * V_2 ,
const struct V_3 * V_4 , const struct V_26 * V_39 ,
const struct V_40 * V_41 , T_3 V_58 )
{
struct V_59 * V_60 = F_26 ( V_2 ) ;
struct V_3 * V_20 ;
struct V_1 * V_7 , * V_25 ;
struct V_26 * V_27 ;
unsigned int V_28 ;
V_7 = F_15 ( V_4 ) ;
V_28 = sizeof( * V_27 ) + F_16 ( V_41 ) ;
V_20 = F_17 ( sizeof( * V_25 ) + V_28 + V_43 ,
V_44 ) ;
if ( V_20 == NULL )
return;
F_18 ( V_20 , V_43 ) ;
V_25 = F_1 ( V_2 , V_20 , V_7 -> V_5 , V_7 -> V_6 ) ;
F_19 ( V_20 ) ;
V_27 = (struct V_26 * ) F_3 ( V_20 , V_28 ) ;
V_27 -> V_45 = V_39 -> V_45 ;
V_27 -> V_46 = V_39 -> V_46 ;
V_27 -> V_47 = F_20 ( V_58 - 1 ) ;
V_27 -> V_48 = F_20 ( F_22 ( V_39 -> V_48 ) - 1 ) ;
F_23 ( V_27 ) = V_49 ;
if ( V_41 -> V_51 & V_52 )
F_23 ( V_27 ) |= V_53 | V_61 ;
V_27 -> V_54 = V_28 / 4 ;
V_27 -> V_55 = V_39 -> V_55 ;
V_27 -> V_19 = 0 ;
V_27 -> V_56 = 0 ;
F_24 ( V_27 , V_41 ) ;
F_5 ( V_2 , V_4 , V_20 , & V_60 -> V_62 -> V_63 , V_64 ,
V_25 , V_27 , V_28 ) ;
}
static void
F_27 ( struct V_2 * V_2 ,
const struct V_65 * V_66 ,
const struct V_3 * V_4 , const struct V_26 * V_39 ,
const struct V_40 * V_41 )
{
struct V_3 * V_20 ;
struct V_1 * V_7 , * V_25 ;
struct V_26 * V_27 ;
unsigned int V_28 ;
V_7 = F_15 ( V_4 ) ;
V_28 = sizeof( * V_27 ) + F_16 ( V_41 ) ;
V_20 = F_17 ( sizeof( * V_25 ) + V_28 + V_43 ,
V_44 ) ;
if ( V_20 == NULL )
return;
F_18 ( V_20 , V_43 ) ;
V_25 = F_1 ( V_2 , V_20 , V_7 -> V_6 , V_7 -> V_5 ) ;
F_19 ( V_20 ) ;
V_27 = (struct V_26 * ) F_3 ( V_20 , V_28 ) ;
V_27 -> V_45 = V_39 -> V_46 ;
V_27 -> V_46 = V_39 -> V_45 ;
V_27 -> V_47 = F_20 ( F_22 ( V_39 -> V_48 ) ) ;
V_27 -> V_48 = F_20 ( F_22 ( V_39 -> V_47 ) + 1 ) ;
F_23 ( V_27 ) = V_50 ;
V_27 -> V_54 = V_28 / 4 ;
V_27 -> V_55 = F_4 ( V_66 -> V_67 [ V_68 ] . V_69 ) ;
V_27 -> V_19 = 0 ;
V_27 -> V_56 = 0 ;
F_24 ( V_27 , V_41 ) ;
F_5 ( V_2 , V_4 , V_20 , NULL , 0 , V_25 , V_27 , V_28 ) ;
}
static void
F_28 ( struct V_2 * V_2 ,
const struct V_3 * V_4 , const struct V_26 * V_39 ,
const struct V_40 * V_41 )
{
struct V_3 * V_20 ;
struct V_1 * V_7 , * V_25 ;
struct V_26 * V_27 ;
unsigned int V_28 ;
V_7 = F_15 ( V_4 ) ;
V_28 = sizeof( * V_27 ) + F_16 ( V_41 ) ;
V_20 = F_17 ( sizeof( * V_25 ) + V_28 + V_43 ,
V_44 ) ;
if ( V_20 == NULL )
return;
F_18 ( V_20 , V_43 ) ;
V_25 = F_1 ( V_2 , V_20 , V_7 -> V_5 , V_7 -> V_6 ) ;
F_19 ( V_20 ) ;
V_27 = (struct V_26 * ) F_3 ( V_20 , V_28 ) ;
V_27 -> V_45 = V_39 -> V_45 ;
V_27 -> V_46 = V_39 -> V_46 ;
V_27 -> V_47 = F_20 ( F_22 ( V_39 -> V_47 ) + 1 ) ;
V_27 -> V_48 = V_39 -> V_48 ;
F_23 ( V_27 ) = V_50 ;
V_27 -> V_54 = V_28 / 4 ;
V_27 -> V_55 = F_4 ( F_29 ( V_39 -> V_55 ) >> V_41 -> V_70 ) ;
V_27 -> V_19 = 0 ;
V_27 -> V_56 = 0 ;
F_24 ( V_27 , V_41 ) ;
F_5 ( V_2 , V_4 , V_20 , V_4 -> V_22 , V_57 ,
V_25 , V_27 , V_28 ) ;
}
static bool
F_30 ( struct V_2 * V_2 ,
const struct V_3 * V_4 , const struct V_26 * V_39 ,
struct V_40 * V_41 , T_3 V_58 )
{
struct V_59 * V_60 = F_26 ( V_2 ) ;
int V_42 ;
V_42 = F_31 ( F_15 ( V_4 ) , V_39 , F_22 ( V_39 -> V_48 ) - 1 ) ;
if ( V_42 == 0 ) {
F_32 ( V_60 -> V_71 -> V_72 ) ;
return false ;
}
F_32 ( V_60 -> V_71 -> V_73 ) ;
V_41 -> V_42 = V_42 ;
V_41 -> V_51 |= V_74 ;
if ( V_41 -> V_51 & V_75 )
F_33 ( V_41 ) ;
F_25 ( V_2 , V_4 , V_39 , V_41 , V_58 ) ;
return true ;
}
static unsigned int
F_34 ( struct V_3 * V_4 , const struct V_76 * V_77 )
{
const struct V_78 * V_79 = V_77 -> V_80 ;
struct V_2 * V_2 = V_77 -> V_2 ;
struct V_59 * V_60 = F_26 ( V_2 ) ;
struct V_40 V_41 = {} ;
struct V_26 * V_39 , V_81 ;
if ( F_35 ( V_4 , V_77 -> V_82 , V_77 -> V_83 , V_18 ) )
return V_84 ;
V_39 = F_36 ( V_4 , V_77 -> V_83 , sizeof( V_81 ) , & V_81 ) ;
if ( V_39 == NULL )
return V_84 ;
if ( ! F_37 ( V_4 , V_77 -> V_83 , V_39 , & V_41 ) )
return V_84 ;
if ( V_39 -> V_85 && ! ( V_39 -> V_86 || V_39 -> V_87 || V_39 -> V_88 ) ) {
F_32 ( V_60 -> V_71 -> V_89 ) ;
if ( V_39 -> V_90 && V_39 -> V_91 )
V_41 . V_51 |= V_52 ;
V_41 . V_51 &= V_79 -> V_51 ;
if ( V_41 . V_51 & V_75 )
F_38 ( V_79 , & V_41 ) ;
else
V_41 . V_51 &= ~ ( V_92 |
V_93 |
V_52 ) ;
F_14 ( V_2 , V_4 , V_39 , & V_41 ) ;
return V_84 ;
} else if ( V_39 -> V_86 && ! ( V_39 -> V_87 || V_39 -> V_88 || V_39 -> V_85 ) ) {
F_30 ( V_2 , V_4 , V_39 , & V_41 , F_22 ( V_39 -> V_47 ) ) ;
return V_84 ;
}
return V_94 ;
}
static unsigned int F_39 ( void * V_95 ,
struct V_3 * V_4 ,
const struct V_96 * V_97 )
{
struct V_2 * V_2 = V_97 -> V_2 ;
struct V_59 * V_60 = F_26 ( V_2 ) ;
enum V_23 V_24 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_40 V_41 = {} ;
const struct V_65 * V_66 ;
struct V_26 * V_39 , V_81 ;
unsigned int V_83 ;
V_99 = F_40 ( V_4 , & V_24 ) ;
if ( V_99 == NULL )
return V_102 ;
V_101 = F_41 ( V_99 ) ;
if ( V_101 == NULL )
return V_102 ;
if ( F_42 ( V_4 ) )
return V_102 ;
V_83 = F_43 ( V_4 ) ;
V_39 = F_36 ( V_4 , V_83 , sizeof( V_81 ) , & V_81 ) ;
if ( V_39 == NULL )
return V_84 ;
V_66 = & V_99 -> V_103 . V_104 ;
switch ( V_66 -> V_66 ) {
case V_105 :
if ( V_39 -> V_88 && ! F_44 ( V_106 , & V_99 -> V_107 ) ) {
F_45 ( V_99 , V_24 , V_101 -> V_108 -
F_22 ( V_39 -> V_47 ) + 1 ) ;
break;
}
if ( ! V_39 -> V_85 || V_39 -> V_86 ||
F_46 ( V_24 ) != V_68 )
break;
F_45 ( V_99 , V_24 , 0 ) ;
V_101 -> V_109 = 0 ;
F_32 ( V_60 -> V_71 -> V_110 ) ;
case V_111 :
if ( ! F_37 ( V_4 , V_83 , V_39 , & V_41 ) )
return V_84 ;
if ( ! V_39 -> V_85 && V_39 -> V_86 &&
F_46 ( V_24 ) == V_68 ) {
if ( F_30 ( V_2 , V_4 , V_39 , & V_41 ,
F_22 ( V_39 -> V_47 ) + 1 ) )
F_32 ( V_60 -> V_71 -> V_112 ) ;
return V_84 ;
}
V_101 -> V_108 = F_22 ( V_39 -> V_48 ) ;
if ( V_41 . V_51 & V_75 )
V_101 -> V_113 = V_41 . V_114 ;
break;
case V_115 :
if ( ! V_39 -> V_85 || ! V_39 -> V_86 )
break;
if ( ! F_37 ( V_4 , V_83 , V_39 , & V_41 ) )
return V_84 ;
if ( V_41 . V_51 & V_75 )
V_101 -> V_109 = V_41 . V_116 - V_101 -> V_113 ;
V_41 . V_51 &= ~ ( V_74 |
V_92 |
V_93 ) ;
F_47 ( V_41 . V_116 , V_41 . V_114 ) ;
F_27 ( V_2 , V_66 , V_4 , V_39 , & V_41 ) ;
F_45 ( V_99 , V_24 , V_101 -> V_108 - F_22 ( V_39 -> V_47 ) ) ;
F_47 ( V_41 . V_116 , V_41 . V_114 ) ;
F_28 ( V_2 , V_4 , V_39 , & V_41 ) ;
F_48 ( V_4 ) ;
return V_117 ;
default:
break;
}
F_49 ( V_4 , V_83 , V_39 , V_99 , V_24 , V_101 ) ;
return V_102 ;
}
static int F_50 ( const struct V_118 * V_77 )
{
const struct V_119 * V_120 = V_77 -> V_121 ;
if ( V_120 -> V_122 . V_103 != V_18 ||
V_120 -> V_122 . V_123 & V_124 )
return - V_125 ;
return F_51 ( V_77 -> V_126 ) ;
}
static void F_52 ( const struct V_127 * V_77 )
{
F_53 ( V_77 -> V_126 ) ;
}
static int T_4 F_54 ( void )
{
int V_128 ;
V_128 = F_55 ( V_129 ,
F_56 ( V_129 ) ) ;
if ( V_128 < 0 )
goto V_130;
V_128 = F_57 ( & V_131 ) ;
if ( V_128 < 0 )
goto V_132;
return 0 ;
V_132:
F_58 ( V_129 , F_56 ( V_129 ) ) ;
V_130:
return V_128 ;
}
static void T_5 F_59 ( void )
{
F_60 ( & V_131 ) ;
F_58 ( V_129 , F_56 ( V_129 ) ) ;
}
