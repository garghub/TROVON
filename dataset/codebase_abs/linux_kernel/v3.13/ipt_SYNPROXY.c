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
F_5 ( const struct V_2 * V_3 , struct V_2 * V_18 ,
struct V_19 * V_20 , enum V_21 V_22 ,
struct V_1 * V_23 , struct V_24 * V_25 ,
unsigned int V_26 )
{
V_25 -> V_17 = ~ F_6 ( V_26 , V_23 -> V_4 , V_23 -> V_5 , 0 ) ;
V_18 -> V_27 = V_28 ;
V_18 -> V_29 = ( unsigned char * ) V_25 - V_18 -> V_30 ;
V_18 -> V_31 = F_7 ( struct V_24 , V_17 ) ;
F_8 ( V_18 , F_9 ( V_3 ) ) ;
V_18 -> V_15 = F_4 ( V_32 ) ;
if ( F_10 ( V_18 , V_33 ) )
goto V_34;
if ( V_20 ) {
V_18 -> V_20 = V_20 ;
V_18 -> V_35 = V_22 ;
F_11 ( V_20 ) ;
}
F_12 ( V_18 ) ;
return;
V_34:
F_13 ( V_18 ) ;
}
static void
F_14 ( const struct V_2 * V_3 , const struct V_24 * V_36 ,
const struct V_37 * V_38 )
{
struct V_2 * V_18 ;
struct V_1 * V_6 , * V_23 ;
struct V_24 * V_25 ;
unsigned int V_26 ;
T_2 V_39 = V_38 -> V_39 ;
V_6 = F_15 ( V_3 ) ;
V_26 = sizeof( * V_25 ) + F_16 ( V_38 ) ;
V_18 = F_17 ( sizeof( * V_23 ) + V_26 + V_40 ,
V_41 ) ;
if ( V_18 == NULL )
return;
F_18 ( V_18 , V_40 ) ;
V_23 = F_1 ( V_18 , V_6 -> V_5 , V_6 -> V_4 ) ;
F_19 ( V_18 ) ;
V_25 = (struct V_24 * ) F_3 ( V_18 , V_26 ) ;
V_25 -> V_42 = V_36 -> V_43 ;
V_25 -> V_43 = V_36 -> V_42 ;
V_25 -> V_44 = F_20 ( F_21 ( V_6 , V_36 , & V_39 ) ) ;
V_25 -> V_45 = F_20 ( F_22 ( V_36 -> V_44 ) + 1 ) ;
F_23 ( V_25 ) = V_46 | V_47 ;
if ( V_38 -> V_48 & V_49 )
F_23 ( V_25 ) |= V_50 ;
V_25 -> V_51 = V_26 / 4 ;
V_25 -> V_52 = 0 ;
V_25 -> V_17 = 0 ;
V_25 -> V_53 = 0 ;
F_24 ( V_25 , V_38 ) ;
F_5 ( V_3 , V_18 , V_3 -> V_20 , V_54 ,
V_23 , V_25 , V_26 ) ;
}
static void
F_25 ( const struct V_55 * V_56 ,
const struct V_2 * V_3 , const struct V_24 * V_36 ,
const struct V_37 * V_38 , T_1 V_57 )
{
struct V_2 * V_18 ;
struct V_1 * V_6 , * V_23 ;
struct V_24 * V_25 ;
unsigned int V_26 ;
V_6 = F_15 ( V_3 ) ;
V_26 = sizeof( * V_25 ) + F_16 ( V_38 ) ;
V_18 = F_17 ( sizeof( * V_23 ) + V_26 + V_40 ,
V_41 ) ;
if ( V_18 == NULL )
return;
F_18 ( V_18 , V_40 ) ;
V_23 = F_1 ( V_18 , V_6 -> V_4 , V_6 -> V_5 ) ;
F_19 ( V_18 ) ;
V_25 = (struct V_24 * ) F_3 ( V_18 , V_26 ) ;
V_25 -> V_42 = V_36 -> V_42 ;
V_25 -> V_43 = V_36 -> V_43 ;
V_25 -> V_44 = F_20 ( V_57 - 1 ) ;
V_25 -> V_45 = F_20 ( F_22 ( V_36 -> V_45 ) - 1 ) ;
F_23 ( V_25 ) = V_46 ;
if ( V_38 -> V_48 & V_49 )
F_23 ( V_25 ) |= V_50 | V_58 ;
V_25 -> V_51 = V_26 / 4 ;
V_25 -> V_52 = V_36 -> V_52 ;
V_25 -> V_17 = 0 ;
V_25 -> V_53 = 0 ;
F_24 ( V_25 , V_38 ) ;
F_5 ( V_3 , V_18 , & V_56 -> V_59 -> V_60 , V_61 ,
V_23 , V_25 , V_26 ) ;
}
static void
F_26 ( const struct V_55 * V_56 ,
const struct V_62 * V_63 ,
const struct V_2 * V_3 , const struct V_24 * V_36 ,
const struct V_37 * V_38 )
{
struct V_2 * V_18 ;
struct V_1 * V_6 , * V_23 ;
struct V_24 * V_25 ;
unsigned int V_26 ;
V_6 = F_15 ( V_3 ) ;
V_26 = sizeof( * V_25 ) + F_16 ( V_38 ) ;
V_18 = F_17 ( sizeof( * V_23 ) + V_26 + V_40 ,
V_41 ) ;
if ( V_18 == NULL )
return;
F_18 ( V_18 , V_40 ) ;
V_23 = F_1 ( V_18 , V_6 -> V_5 , V_6 -> V_4 ) ;
F_19 ( V_18 ) ;
V_25 = (struct V_24 * ) F_3 ( V_18 , V_26 ) ;
V_25 -> V_42 = V_36 -> V_43 ;
V_25 -> V_43 = V_36 -> V_42 ;
V_25 -> V_44 = F_20 ( F_22 ( V_36 -> V_45 ) ) ;
V_25 -> V_45 = F_20 ( F_22 ( V_36 -> V_44 ) + 1 ) ;
F_23 ( V_25 ) = V_47 ;
V_25 -> V_51 = V_26 / 4 ;
V_25 -> V_52 = F_4 ( V_63 -> V_64 [ V_65 ] . V_66 ) ;
V_25 -> V_17 = 0 ;
V_25 -> V_53 = 0 ;
F_24 ( V_25 , V_38 ) ;
F_5 ( V_3 , V_18 , NULL , 0 , V_23 , V_25 , V_26 ) ;
}
static void
F_27 ( const struct V_55 * V_56 ,
const struct V_2 * V_3 , const struct V_24 * V_36 ,
const struct V_37 * V_38 )
{
struct V_2 * V_18 ;
struct V_1 * V_6 , * V_23 ;
struct V_24 * V_25 ;
unsigned int V_26 ;
V_6 = F_15 ( V_3 ) ;
V_26 = sizeof( * V_25 ) + F_16 ( V_38 ) ;
V_18 = F_17 ( sizeof( * V_23 ) + V_26 + V_40 ,
V_41 ) ;
if ( V_18 == NULL )
return;
F_18 ( V_18 , V_40 ) ;
V_23 = F_1 ( V_18 , V_6 -> V_4 , V_6 -> V_5 ) ;
F_19 ( V_18 ) ;
V_25 = (struct V_24 * ) F_3 ( V_18 , V_26 ) ;
V_25 -> V_42 = V_36 -> V_42 ;
V_25 -> V_43 = V_36 -> V_43 ;
V_25 -> V_44 = F_20 ( F_22 ( V_36 -> V_44 ) + 1 ) ;
V_25 -> V_45 = V_36 -> V_45 ;
F_23 ( V_25 ) = V_47 ;
V_25 -> V_51 = V_26 / 4 ;
V_25 -> V_52 = F_28 ( F_4 ( V_36 -> V_52 ) >> V_38 -> V_67 ) ;
V_25 -> V_17 = 0 ;
V_25 -> V_53 = 0 ;
F_24 ( V_25 , V_38 ) ;
F_5 ( V_3 , V_18 , NULL , 0 , V_23 , V_25 , V_26 ) ;
}
static bool
F_29 ( const struct V_55 * V_56 ,
const struct V_2 * V_3 , const struct V_24 * V_36 ,
struct V_37 * V_38 , T_1 V_57 )
{
int V_39 ;
V_39 = F_30 ( F_15 ( V_3 ) , V_36 , F_22 ( V_36 -> V_45 ) - 1 ) ;
if ( V_39 == 0 ) {
F_31 ( V_56 -> V_68 -> V_69 ) ;
return false ;
}
F_31 ( V_56 -> V_68 -> V_70 ) ;
V_38 -> V_39 = V_39 ;
V_38 -> V_48 |= V_71 ;
if ( V_38 -> V_48 & V_72 )
F_32 ( V_38 ) ;
F_25 ( V_56 , V_3 , V_36 , V_38 , V_57 ) ;
return true ;
}
static unsigned int
F_33 ( struct V_2 * V_3 , const struct V_73 * V_74 )
{
const struct V_75 * V_76 = V_74 -> V_77 ;
struct V_55 * V_56 = F_34 ( F_35 ( V_74 -> V_78 ) ) ;
struct V_37 V_38 = {} ;
struct V_24 * V_36 , V_79 ;
if ( F_36 ( V_3 , V_74 -> V_80 , V_74 -> V_81 , V_16 ) )
return V_82 ;
V_36 = F_37 ( V_3 , V_74 -> V_81 , sizeof( V_79 ) , & V_79 ) ;
if ( V_36 == NULL )
return V_82 ;
if ( ! F_38 ( V_3 , V_74 -> V_81 , V_36 , & V_38 ) )
return V_82 ;
if ( V_36 -> V_83 && ! ( V_36 -> V_84 || V_36 -> V_85 || V_36 -> V_86 ) ) {
F_31 ( V_56 -> V_68 -> V_87 ) ;
if ( V_36 -> V_88 && V_36 -> V_89 )
V_38 . V_48 |= V_49 ;
V_38 . V_48 &= V_76 -> V_48 ;
if ( V_38 . V_48 & V_72 )
F_39 ( V_76 , & V_38 ) ;
else
V_38 . V_48 &= ~ ( V_90 |
V_91 |
V_49 ) ;
F_14 ( V_3 , V_36 , & V_38 ) ;
return V_82 ;
} else if ( V_36 -> V_84 && ! ( V_36 -> V_85 || V_36 -> V_86 || V_36 -> V_83 ) ) {
F_29 ( V_56 , V_3 , V_36 , & V_38 , F_22 ( V_36 -> V_44 ) ) ;
return V_82 ;
}
return V_92 ;
}
static unsigned int F_40 ( const struct V_93 * V_94 ,
struct V_2 * V_3 ,
const struct V_95 * V_78 ,
const struct V_95 * V_96 ,
int (* F_41)( struct V_2 * ) )
{
struct V_55 * V_56 = F_34 ( F_35 ( V_78 ? : V_96 ) ) ;
enum V_21 V_22 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
struct V_37 V_38 = {} ;
const struct V_62 * V_63 ;
struct V_24 * V_36 , V_79 ;
unsigned int V_81 ;
V_98 = F_42 ( V_3 , & V_22 ) ;
if ( V_98 == NULL )
return V_101 ;
V_100 = F_43 ( V_98 ) ;
if ( V_100 == NULL )
return V_101 ;
if ( F_44 ( V_3 ) )
return V_101 ;
V_81 = F_45 ( V_3 ) ;
V_36 = F_37 ( V_3 , V_81 , sizeof( V_79 ) , & V_79 ) ;
if ( V_36 == NULL )
return V_82 ;
V_63 = & V_98 -> V_102 . V_103 ;
switch ( V_63 -> V_63 ) {
case V_104 :
if ( V_36 -> V_86 && ! F_46 ( V_105 , & V_98 -> V_106 ) ) {
F_47 ( V_98 , V_22 , V_100 -> V_107 -
F_22 ( V_36 -> V_44 ) + 1 ) ;
break;
}
if ( ! V_36 -> V_83 || V_36 -> V_84 ||
F_48 ( V_22 ) != V_65 )
break;
F_47 ( V_98 , V_22 , 0 ) ;
V_100 -> V_108 = 0 ;
F_31 ( V_56 -> V_68 -> V_109 ) ;
case V_110 :
if ( ! F_38 ( V_3 , V_81 , V_36 , & V_38 ) )
return V_82 ;
if ( ! V_36 -> V_83 && V_36 -> V_84 &&
F_48 ( V_22 ) == V_65 ) {
if ( F_29 ( V_56 , V_3 , V_36 , & V_38 ,
F_22 ( V_36 -> V_44 ) + 1 ) )
F_31 ( V_56 -> V_68 -> V_111 ) ;
return V_82 ;
}
V_100 -> V_107 = F_22 ( V_36 -> V_45 ) ;
if ( V_38 . V_48 & V_72 )
V_100 -> V_112 = V_38 . V_113 ;
break;
case V_114 :
if ( ! V_36 -> V_83 || ! V_36 -> V_84 )
break;
if ( ! F_38 ( V_3 , V_81 , V_36 , & V_38 ) )
return V_82 ;
if ( V_38 . V_48 & V_72 )
V_100 -> V_108 = V_38 . V_115 - V_100 -> V_112 ;
V_38 . V_48 &= ~ ( V_71 |
V_90 |
V_91 ) ;
F_49 ( V_38 . V_115 , V_38 . V_113 ) ;
F_26 ( V_56 , V_63 , V_3 , V_36 , & V_38 ) ;
F_47 ( V_98 , V_22 , V_100 -> V_107 - F_22 ( V_36 -> V_44 ) ) ;
F_49 ( V_38 . V_115 , V_38 . V_113 ) ;
F_27 ( V_56 , V_3 , V_36 , & V_38 ) ;
F_50 ( V_3 ) ;
return V_116 ;
default:
break;
}
F_51 ( V_3 , V_81 , V_36 , V_98 , V_22 , V_100 ) ;
return V_101 ;
}
static int F_52 ( const struct V_117 * V_74 )
{
const struct V_118 * V_119 = V_74 -> V_120 ;
if ( V_119 -> V_121 . V_102 != V_16 ||
V_119 -> V_121 . V_122 & V_123 )
return - V_124 ;
return F_53 ( V_74 -> V_125 ) ;
}
static void F_54 ( const struct V_126 * V_74 )
{
F_55 ( V_74 -> V_125 ) ;
}
static int T_3 F_56 ( void )
{
int V_127 ;
V_127 = F_57 ( V_128 ,
F_58 ( V_128 ) ) ;
if ( V_127 < 0 )
goto V_129;
V_127 = F_59 ( & V_130 ) ;
if ( V_127 < 0 )
goto V_131;
return 0 ;
V_131:
F_60 ( V_128 , F_58 ( V_128 ) ) ;
V_129:
return V_127 ;
}
static void T_4 F_61 ( void )
{
F_62 ( & V_130 ) ;
F_60 ( V_128 , F_58 ( V_128 ) ) ;
}
