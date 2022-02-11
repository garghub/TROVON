static struct V_1 *
F_1 ( struct V_2 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 )
{
struct V_1 * V_8 ;
F_2 ( V_4 ) ;
V_8 = (struct V_1 * ) F_3 ( V_4 , sizeof( * V_8 ) ) ;
F_4 ( V_8 , 0 , 0 ) ;
V_8 -> V_9 = V_2 -> V_10 . V_11 -> V_9 ;
V_8 -> V_12 = V_13 ;
V_8 -> V_6 = * V_6 ;
V_8 -> V_7 = * V_7 ;
return V_8 ;
}
static void
F_5 ( struct V_2 * V_2 ,
const struct V_3 * V_4 , struct V_3 * V_14 ,
struct V_15 * V_16 , enum V_17 V_18 ,
struct V_1 * V_19 , struct V_20 * V_21 ,
unsigned int V_22 )
{
struct V_23 * V_24 ;
struct V_25 V_26 ;
V_21 -> V_27 = ~ F_6 ( V_22 , & V_19 -> V_6 , & V_19 -> V_7 , 0 ) ;
V_14 -> V_28 = V_29 ;
V_14 -> V_30 = ( unsigned char * ) V_21 - V_14 -> V_31 ;
V_14 -> V_32 = F_7 ( struct V_20 , V_27 ) ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_33 = V_13 ;
V_26 . V_6 = V_19 -> V_6 ;
V_26 . V_7 = V_19 -> V_7 ;
V_26 . V_34 = V_21 -> V_35 ;
V_26 . V_36 = V_21 -> V_37 ;
F_8 ( (struct V_3 * ) V_4 , F_9 ( & V_26 ) ) ;
V_24 = F_10 ( V_2 , NULL , & V_26 ) ;
if ( V_24 -> error ) {
F_11 ( V_24 ) ;
goto V_38;
}
V_24 = F_12 ( V_2 , V_24 , F_9 ( & V_26 ) , NULL , 0 ) ;
if ( F_13 ( V_24 ) )
goto V_38;
F_14 ( V_14 , V_24 ) ;
if ( V_16 ) {
V_14 -> V_16 = V_16 ;
V_14 -> V_39 = V_18 ;
F_15 ( V_16 ) ;
}
F_16 ( V_2 , V_14 -> V_40 , V_14 ) ;
return;
V_38:
F_17 ( V_14 ) ;
}
static void
F_18 ( struct V_2 * V_2 ,
const struct V_3 * V_4 , const struct V_20 * V_41 ,
const struct V_42 * V_43 )
{
struct V_3 * V_14 ;
struct V_1 * V_8 , * V_19 ;
struct V_20 * V_21 ;
unsigned int V_22 ;
T_1 V_44 = V_43 -> V_44 ;
V_8 = F_19 ( V_4 ) ;
V_22 = sizeof( * V_21 ) + F_20 ( V_43 ) ;
V_14 = F_21 ( sizeof( * V_19 ) + V_22 + V_45 ,
V_46 ) ;
if ( V_14 == NULL )
return;
F_22 ( V_14 , V_45 ) ;
V_19 = F_1 ( V_2 , V_14 , & V_8 -> V_7 , & V_8 -> V_6 ) ;
F_23 ( V_14 ) ;
V_21 = (struct V_20 * ) F_3 ( V_14 , V_22 ) ;
V_21 -> V_35 = V_41 -> V_37 ;
V_21 -> V_37 = V_41 -> V_35 ;
V_21 -> V_47 = F_24 ( F_25 ( V_8 , V_41 , & V_44 ) ) ;
V_21 -> V_48 = F_24 ( F_26 ( V_41 -> V_47 ) + 1 ) ;
F_27 ( V_21 ) = V_49 | V_50 ;
if ( V_43 -> V_51 & V_52 )
F_27 ( V_21 ) |= V_53 ;
V_21 -> V_54 = V_22 / 4 ;
V_21 -> V_55 = 0 ;
V_21 -> V_27 = 0 ;
V_21 -> V_56 = 0 ;
F_28 ( V_21 , V_43 ) ;
F_5 ( V_2 , V_4 , V_14 , V_4 -> V_16 , V_57 ,
V_19 , V_21 , V_22 ) ;
}
static void
F_29 ( struct V_2 * V_2 ,
const struct V_3 * V_4 , const struct V_20 * V_41 ,
const struct V_42 * V_43 , T_2 V_58 )
{
struct V_59 * V_60 = F_30 ( V_2 ) ;
struct V_3 * V_14 ;
struct V_1 * V_8 , * V_19 ;
struct V_20 * V_21 ;
unsigned int V_22 ;
V_8 = F_19 ( V_4 ) ;
V_22 = sizeof( * V_21 ) + F_20 ( V_43 ) ;
V_14 = F_21 ( sizeof( * V_19 ) + V_22 + V_45 ,
V_46 ) ;
if ( V_14 == NULL )
return;
F_22 ( V_14 , V_45 ) ;
V_19 = F_1 ( V_2 , V_14 , & V_8 -> V_6 , & V_8 -> V_7 ) ;
F_23 ( V_14 ) ;
V_21 = (struct V_20 * ) F_3 ( V_14 , V_22 ) ;
V_21 -> V_35 = V_41 -> V_35 ;
V_21 -> V_37 = V_41 -> V_37 ;
V_21 -> V_47 = F_24 ( V_58 - 1 ) ;
V_21 -> V_48 = F_24 ( F_26 ( V_41 -> V_48 ) - 1 ) ;
F_27 ( V_21 ) = V_49 ;
if ( V_43 -> V_51 & V_52 )
F_27 ( V_21 ) |= V_53 | V_61 ;
V_21 -> V_54 = V_22 / 4 ;
V_21 -> V_55 = V_41 -> V_55 ;
V_21 -> V_27 = 0 ;
V_21 -> V_56 = 0 ;
F_28 ( V_21 , V_43 ) ;
F_5 ( V_2 , V_4 , V_14 , & V_60 -> V_62 -> V_63 , V_64 ,
V_19 , V_21 , V_22 ) ;
}
static void
F_31 ( struct V_2 * V_2 ,
const struct V_65 * V_66 ,
const struct V_3 * V_4 , const struct V_20 * V_41 ,
const struct V_42 * V_43 )
{
struct V_3 * V_14 ;
struct V_1 * V_8 , * V_19 ;
struct V_20 * V_21 ;
unsigned int V_22 ;
V_8 = F_19 ( V_4 ) ;
V_22 = sizeof( * V_21 ) + F_20 ( V_43 ) ;
V_14 = F_21 ( sizeof( * V_19 ) + V_22 + V_45 ,
V_46 ) ;
if ( V_14 == NULL )
return;
F_22 ( V_14 , V_45 ) ;
V_19 = F_1 ( V_2 , V_14 , & V_8 -> V_7 , & V_8 -> V_6 ) ;
F_23 ( V_14 ) ;
V_21 = (struct V_20 * ) F_3 ( V_14 , V_22 ) ;
V_21 -> V_35 = V_41 -> V_37 ;
V_21 -> V_37 = V_41 -> V_35 ;
V_21 -> V_47 = F_24 ( F_26 ( V_41 -> V_48 ) ) ;
V_21 -> V_48 = F_24 ( F_26 ( V_41 -> V_47 ) + 1 ) ;
F_27 ( V_21 ) = V_50 ;
V_21 -> V_54 = V_22 / 4 ;
V_21 -> V_55 = F_32 ( V_66 -> V_67 [ V_68 ] . V_69 ) ;
V_21 -> V_27 = 0 ;
V_21 -> V_56 = 0 ;
F_28 ( V_21 , V_43 ) ;
F_5 ( V_2 , V_4 , V_14 , NULL , 0 , V_19 , V_21 , V_22 ) ;
}
static void
F_33 ( struct V_2 * V_2 ,
const struct V_3 * V_4 , const struct V_20 * V_41 ,
const struct V_42 * V_43 )
{
struct V_3 * V_14 ;
struct V_1 * V_8 , * V_19 ;
struct V_20 * V_21 ;
unsigned int V_22 ;
V_8 = F_19 ( V_4 ) ;
V_22 = sizeof( * V_21 ) + F_20 ( V_43 ) ;
V_14 = F_21 ( sizeof( * V_19 ) + V_22 + V_45 ,
V_46 ) ;
if ( V_14 == NULL )
return;
F_22 ( V_14 , V_45 ) ;
V_19 = F_1 ( V_2 , V_14 , & V_8 -> V_6 , & V_8 -> V_7 ) ;
F_23 ( V_14 ) ;
V_21 = (struct V_20 * ) F_3 ( V_14 , V_22 ) ;
V_21 -> V_35 = V_41 -> V_35 ;
V_21 -> V_37 = V_41 -> V_37 ;
V_21 -> V_47 = F_24 ( F_26 ( V_41 -> V_47 ) + 1 ) ;
V_21 -> V_48 = V_41 -> V_48 ;
F_27 ( V_21 ) = V_50 ;
V_21 -> V_54 = V_22 / 4 ;
V_21 -> V_55 = F_32 ( F_34 ( V_41 -> V_55 ) >> V_43 -> V_70 ) ;
V_21 -> V_27 = 0 ;
V_21 -> V_56 = 0 ;
F_28 ( V_21 , V_43 ) ;
F_5 ( V_2 , V_4 , V_14 , V_4 -> V_16 , V_57 ,
V_19 , V_21 , V_22 ) ;
}
static bool
F_35 ( struct V_2 * V_2 ,
const struct V_3 * V_4 , const struct V_20 * V_41 ,
struct V_42 * V_43 , T_2 V_58 )
{
struct V_59 * V_60 = F_30 ( V_2 ) ;
int V_44 ;
V_44 = F_36 ( F_19 ( V_4 ) , V_41 , F_26 ( V_41 -> V_48 ) - 1 ) ;
if ( V_44 == 0 ) {
F_37 ( V_60 -> V_71 -> V_72 ) ;
return false ;
}
F_37 ( V_60 -> V_71 -> V_73 ) ;
V_43 -> V_44 = V_44 ;
V_43 -> V_51 |= V_74 ;
if ( V_43 -> V_51 & V_75 )
F_38 ( V_43 ) ;
F_29 ( V_2 , V_4 , V_41 , V_43 , V_58 ) ;
return true ;
}
static unsigned int
F_39 ( struct V_3 * V_4 , const struct V_76 * V_77 )
{
const struct V_78 * V_79 = V_77 -> V_80 ;
struct V_2 * V_2 = F_40 ( V_77 ) ;
struct V_59 * V_60 = F_30 ( V_2 ) ;
struct V_42 V_43 = {} ;
struct V_20 * V_41 , V_81 ;
if ( F_41 ( V_4 , F_42 ( V_77 ) , V_77 -> V_82 , V_13 ) )
return V_83 ;
V_41 = F_43 ( V_4 , V_77 -> V_82 , sizeof( V_81 ) , & V_81 ) ;
if ( V_41 == NULL )
return V_83 ;
if ( ! F_44 ( V_4 , V_77 -> V_82 , V_41 , & V_43 ) )
return V_83 ;
if ( V_41 -> V_84 && ! ( V_41 -> V_85 || V_41 -> V_86 || V_41 -> V_87 ) ) {
F_37 ( V_60 -> V_71 -> V_88 ) ;
if ( V_41 -> V_89 && V_41 -> V_90 )
V_43 . V_51 |= V_52 ;
V_43 . V_51 &= V_79 -> V_51 ;
if ( V_43 . V_51 & V_75 )
F_45 ( V_79 , & V_43 ) ;
else
V_43 . V_51 &= ~ ( V_91 |
V_92 |
V_52 ) ;
F_18 ( V_2 , V_4 , V_41 , & V_43 ) ;
return V_83 ;
} else if ( V_41 -> V_85 && ! ( V_41 -> V_86 || V_41 -> V_87 || V_41 -> V_84 ) ) {
F_35 ( V_2 , V_4 , V_41 , & V_43 , F_26 ( V_41 -> V_47 ) ) ;
return V_83 ;
}
return V_93 ;
}
static unsigned int F_46 ( void * V_94 ,
struct V_3 * V_4 ,
const struct V_95 * V_96 )
{
struct V_2 * V_2 = V_96 -> V_2 ;
struct V_59 * V_60 = F_30 ( V_2 ) ;
enum V_17 V_18 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
struct V_42 V_43 = {} ;
const struct V_65 * V_66 ;
struct V_20 * V_41 , V_81 ;
T_3 V_101 ;
T_4 V_12 ;
int V_82 ;
V_98 = F_47 ( V_4 , & V_18 ) ;
if ( V_98 == NULL )
return V_102 ;
V_100 = F_48 ( V_98 ) ;
if ( V_100 == NULL )
return V_102 ;
if ( F_49 ( V_4 ) )
return V_102 ;
V_12 = F_19 ( V_4 ) -> V_12 ;
V_82 = F_50 ( V_4 , sizeof( struct V_1 ) , & V_12 ,
& V_101 ) ;
if ( V_82 < 0 )
return V_102 ;
V_41 = F_43 ( V_4 , V_82 , sizeof( V_81 ) , & V_81 ) ;
if ( V_41 == NULL )
return V_83 ;
V_66 = & V_98 -> V_103 . V_104 ;
switch ( V_66 -> V_66 ) {
case V_105 :
if ( V_41 -> V_87 && ! F_51 ( V_106 , & V_98 -> V_107 ) ) {
F_52 ( V_98 , V_18 , V_100 -> V_108 -
F_26 ( V_41 -> V_47 ) + 1 ) ;
break;
}
if ( ! V_41 -> V_84 || V_41 -> V_85 ||
F_53 ( V_18 ) != V_68 )
break;
F_52 ( V_98 , V_18 , 0 ) ;
V_100 -> V_109 = 0 ;
F_37 ( V_60 -> V_71 -> V_110 ) ;
case V_111 :
if ( ! F_44 ( V_4 , V_82 , V_41 , & V_43 ) )
return V_83 ;
if ( ! V_41 -> V_84 && V_41 -> V_85 &&
F_53 ( V_18 ) == V_68 ) {
if ( F_35 ( V_2 , V_4 , V_41 , & V_43 ,
F_26 ( V_41 -> V_47 ) + 1 ) )
F_37 ( V_60 -> V_71 -> V_112 ) ;
return V_83 ;
}
V_100 -> V_108 = F_26 ( V_41 -> V_48 ) ;
if ( V_43 . V_51 & V_75 )
V_100 -> V_113 = V_43 . V_114 ;
break;
case V_115 :
if ( ! V_41 -> V_84 || ! V_41 -> V_85 )
break;
if ( ! F_44 ( V_4 , V_82 , V_41 , & V_43 ) )
return V_83 ;
if ( V_43 . V_51 & V_75 )
V_100 -> V_109 = V_43 . V_116 - V_100 -> V_113 ;
V_43 . V_51 &= ~ ( V_74 |
V_91 |
V_92 ) ;
F_54 ( V_43 . V_116 , V_43 . V_114 ) ;
F_31 ( V_2 , V_66 , V_4 , V_41 , & V_43 ) ;
F_52 ( V_98 , V_18 , V_100 -> V_108 - F_26 ( V_41 -> V_47 ) ) ;
F_54 ( V_43 . V_116 , V_43 . V_114 ) ;
F_33 ( V_2 , V_4 , V_41 , & V_43 ) ;
F_55 ( V_4 ) ;
return V_117 ;
default:
break;
}
F_56 ( V_4 , V_82 , V_41 , V_98 , V_18 , V_100 ) ;
return V_102 ;
}
static int F_57 ( const struct V_118 * V_77 )
{
const struct V_119 * V_120 = V_77 -> V_121 ;
if ( ! ( V_120 -> V_10 . V_122 & V_123 ) ||
V_120 -> V_10 . V_103 != V_13 ||
V_120 -> V_10 . V_124 & V_125 )
return - V_126 ;
return F_58 ( V_77 -> V_2 , V_77 -> V_127 ) ;
}
static void F_59 ( const struct V_128 * V_77 )
{
F_60 ( V_77 -> V_2 , V_77 -> V_127 ) ;
}
static int T_5 F_61 ( void )
{
int V_129 ;
V_129 = F_62 ( V_130 ,
F_63 ( V_130 ) ) ;
if ( V_129 < 0 )
goto V_131;
V_129 = F_64 ( & V_132 ) ;
if ( V_129 < 0 )
goto V_133;
return 0 ;
V_133:
F_65 ( V_130 , F_63 ( V_130 ) ) ;
V_131:
return V_129 ;
}
static void T_6 F_66 ( void )
{
F_67 ( & V_132 ) ;
F_65 ( V_130 , F_63 ( V_130 ) ) ;
}
