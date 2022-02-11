static struct V_1 *
F_1 ( struct V_2 * V_3 , const struct V_4 * V_5 ,
const struct V_4 * V_6 )
{
struct V_1 * V_7 ;
F_2 ( V_3 ) ;
V_7 = (struct V_1 * ) F_3 ( V_3 , sizeof( * V_7 ) ) ;
F_4 ( V_7 , 0 , 0 ) ;
V_7 -> V_8 = 64 ;
V_7 -> V_9 = V_10 ;
V_7 -> V_5 = * V_5 ;
V_7 -> V_6 = * V_6 ;
return V_7 ;
}
static void
F_5 ( const struct V_11 * V_12 ,
const struct V_2 * V_3 , struct V_2 * V_13 ,
struct V_14 * V_15 , enum V_16 V_17 ,
struct V_1 * V_18 , struct V_19 * V_20 ,
unsigned int V_21 )
{
struct V_22 * V_22 = F_6 ( V_12 -> V_23 ) ;
struct V_24 * V_25 ;
struct V_26 V_27 ;
V_20 -> V_28 = ~ F_7 ( V_21 , & V_18 -> V_5 , & V_18 -> V_6 , 0 ) ;
V_13 -> V_29 = V_30 ;
V_13 -> V_31 = ( unsigned char * ) V_20 - V_13 -> V_32 ;
V_13 -> V_33 = F_8 ( struct V_19 , V_28 ) ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_34 = V_10 ;
V_27 . V_5 = V_18 -> V_5 ;
V_27 . V_6 = V_18 -> V_6 ;
V_27 . V_35 = V_20 -> V_36 ;
V_27 . V_37 = V_20 -> V_38 ;
F_9 ( (struct V_2 * ) V_3 , F_10 ( & V_27 ) ) ;
V_25 = F_11 ( V_22 , NULL , & V_27 ) ;
if ( V_25 == NULL || V_25 -> error ) {
F_12 ( V_25 ) ;
goto V_39;
}
V_25 = F_13 ( V_22 , V_25 , F_10 ( & V_27 ) , NULL , 0 ) ;
if ( F_14 ( V_25 ) )
goto V_39;
F_15 ( V_13 , V_25 ) ;
if ( V_15 ) {
V_13 -> V_15 = V_15 ;
V_13 -> V_40 = V_17 ;
F_16 ( V_15 ) ;
}
F_17 ( V_13 ) ;
return;
V_39:
F_18 ( V_13 ) ;
}
static void
F_19 ( const struct V_11 * V_12 ,
const struct V_2 * V_3 , const struct V_19 * V_41 ,
const struct V_42 * V_43 )
{
struct V_2 * V_13 ;
struct V_1 * V_7 , * V_18 ;
struct V_19 * V_20 ;
unsigned int V_21 ;
T_1 V_44 = V_43 -> V_44 ;
V_7 = F_20 ( V_3 ) ;
V_21 = sizeof( * V_20 ) + F_21 ( V_43 ) ;
V_13 = F_22 ( sizeof( * V_18 ) + V_21 + V_45 ,
V_46 ) ;
if ( V_13 == NULL )
return;
F_23 ( V_13 , V_45 ) ;
V_18 = F_1 ( V_13 , & V_7 -> V_6 , & V_7 -> V_5 ) ;
F_24 ( V_13 ) ;
V_20 = (struct V_19 * ) F_3 ( V_13 , V_21 ) ;
V_20 -> V_36 = V_41 -> V_38 ;
V_20 -> V_38 = V_41 -> V_36 ;
V_20 -> V_47 = F_25 ( F_26 ( V_7 , V_41 , & V_44 ) ) ;
V_20 -> V_48 = F_25 ( F_27 ( V_41 -> V_47 ) + 1 ) ;
F_28 ( V_20 ) = V_49 | V_50 ;
if ( V_43 -> V_51 & V_52 )
F_28 ( V_20 ) |= V_53 ;
V_20 -> V_54 = V_21 / 4 ;
V_20 -> V_55 = 0 ;
V_20 -> V_28 = 0 ;
V_20 -> V_56 = 0 ;
F_29 ( V_20 , V_43 ) ;
F_5 ( V_12 , V_3 , V_13 , V_3 -> V_15 , V_57 ,
V_18 , V_20 , V_21 ) ;
}
static void
F_30 ( const struct V_11 * V_12 ,
const struct V_2 * V_3 , const struct V_19 * V_41 ,
const struct V_42 * V_43 , T_2 V_58 )
{
struct V_2 * V_13 ;
struct V_1 * V_7 , * V_18 ;
struct V_19 * V_20 ;
unsigned int V_21 ;
V_7 = F_20 ( V_3 ) ;
V_21 = sizeof( * V_20 ) + F_21 ( V_43 ) ;
V_13 = F_22 ( sizeof( * V_18 ) + V_21 + V_45 ,
V_46 ) ;
if ( V_13 == NULL )
return;
F_23 ( V_13 , V_45 ) ;
V_18 = F_1 ( V_13 , & V_7 -> V_5 , & V_7 -> V_6 ) ;
F_24 ( V_13 ) ;
V_20 = (struct V_19 * ) F_3 ( V_13 , V_21 ) ;
V_20 -> V_36 = V_41 -> V_36 ;
V_20 -> V_38 = V_41 -> V_38 ;
V_20 -> V_47 = F_25 ( V_58 - 1 ) ;
V_20 -> V_48 = F_25 ( F_27 ( V_41 -> V_48 ) - 1 ) ;
F_28 ( V_20 ) = V_49 ;
if ( V_43 -> V_51 & V_52 )
F_28 ( V_20 ) |= V_53 | V_59 ;
V_20 -> V_54 = V_21 / 4 ;
V_20 -> V_55 = V_41 -> V_55 ;
V_20 -> V_28 = 0 ;
V_20 -> V_56 = 0 ;
F_29 ( V_20 , V_43 ) ;
F_5 ( V_12 , V_3 , V_13 , & V_12 -> V_23 -> V_60 , V_61 ,
V_18 , V_20 , V_21 ) ;
}
static void
F_31 ( const struct V_11 * V_12 ,
const struct V_62 * V_63 ,
const struct V_2 * V_3 , const struct V_19 * V_41 ,
const struct V_42 * V_43 )
{
struct V_2 * V_13 ;
struct V_1 * V_7 , * V_18 ;
struct V_19 * V_20 ;
unsigned int V_21 ;
V_7 = F_20 ( V_3 ) ;
V_21 = sizeof( * V_20 ) + F_21 ( V_43 ) ;
V_13 = F_22 ( sizeof( * V_18 ) + V_21 + V_45 ,
V_46 ) ;
if ( V_13 == NULL )
return;
F_23 ( V_13 , V_45 ) ;
V_18 = F_1 ( V_13 , & V_7 -> V_6 , & V_7 -> V_5 ) ;
F_24 ( V_13 ) ;
V_20 = (struct V_19 * ) F_3 ( V_13 , V_21 ) ;
V_20 -> V_36 = V_41 -> V_38 ;
V_20 -> V_38 = V_41 -> V_36 ;
V_20 -> V_47 = F_25 ( F_27 ( V_41 -> V_48 ) ) ;
V_20 -> V_48 = F_25 ( F_27 ( V_41 -> V_47 ) + 1 ) ;
F_28 ( V_20 ) = V_50 ;
V_20 -> V_54 = V_21 / 4 ;
V_20 -> V_55 = F_32 ( V_63 -> V_64 [ V_65 ] . V_66 ) ;
V_20 -> V_28 = 0 ;
V_20 -> V_56 = 0 ;
F_29 ( V_20 , V_43 ) ;
F_5 ( V_12 , V_3 , V_13 , NULL , 0 , V_18 , V_20 , V_21 ) ;
}
static void
F_33 ( const struct V_11 * V_12 ,
const struct V_2 * V_3 , const struct V_19 * V_41 ,
const struct V_42 * V_43 )
{
struct V_2 * V_13 ;
struct V_1 * V_7 , * V_18 ;
struct V_19 * V_20 ;
unsigned int V_21 ;
V_7 = F_20 ( V_3 ) ;
V_21 = sizeof( * V_20 ) + F_21 ( V_43 ) ;
V_13 = F_22 ( sizeof( * V_18 ) + V_21 + V_45 ,
V_46 ) ;
if ( V_13 == NULL )
return;
F_23 ( V_13 , V_45 ) ;
V_18 = F_1 ( V_13 , & V_7 -> V_5 , & V_7 -> V_6 ) ;
F_24 ( V_13 ) ;
V_20 = (struct V_19 * ) F_3 ( V_13 , V_21 ) ;
V_20 -> V_36 = V_41 -> V_36 ;
V_20 -> V_38 = V_41 -> V_38 ;
V_20 -> V_47 = F_25 ( F_27 ( V_41 -> V_47 ) + 1 ) ;
V_20 -> V_48 = V_41 -> V_48 ;
F_28 ( V_20 ) = V_50 ;
V_20 -> V_54 = V_21 / 4 ;
V_20 -> V_55 = F_32 ( F_34 ( V_41 -> V_55 ) >> V_43 -> V_67 ) ;
V_20 -> V_28 = 0 ;
V_20 -> V_56 = 0 ;
F_29 ( V_20 , V_43 ) ;
F_5 ( V_12 , V_3 , V_13 , V_3 -> V_15 , V_57 ,
V_18 , V_20 , V_21 ) ;
}
static bool
F_35 ( const struct V_11 * V_12 ,
const struct V_2 * V_3 , const struct V_19 * V_41 ,
struct V_42 * V_43 , T_2 V_58 )
{
int V_44 ;
V_44 = F_36 ( F_20 ( V_3 ) , V_41 , F_27 ( V_41 -> V_48 ) - 1 ) ;
if ( V_44 == 0 ) {
F_37 ( V_12 -> V_68 -> V_69 ) ;
return false ;
}
F_37 ( V_12 -> V_68 -> V_70 ) ;
V_43 -> V_44 = V_44 ;
V_43 -> V_51 |= V_71 ;
if ( V_43 -> V_51 & V_72 )
F_38 ( V_43 ) ;
F_30 ( V_12 , V_3 , V_41 , V_43 , V_58 ) ;
return true ;
}
static unsigned int
F_39 ( struct V_2 * V_3 , const struct V_73 * V_74 )
{
const struct V_75 * V_76 = V_74 -> V_77 ;
struct V_11 * V_12 = F_40 ( F_41 ( V_74 -> V_78 ) ) ;
struct V_42 V_43 = {} ;
struct V_19 * V_41 , V_79 ;
if ( F_42 ( V_3 , V_74 -> V_80 , V_74 -> V_81 , V_10 ) )
return V_82 ;
V_41 = F_43 ( V_3 , V_74 -> V_81 , sizeof( V_79 ) , & V_79 ) ;
if ( V_41 == NULL )
return V_82 ;
if ( ! F_44 ( V_3 , V_74 -> V_81 , V_41 , & V_43 ) )
return V_82 ;
if ( V_41 -> V_83 && ! ( V_41 -> V_84 || V_41 -> V_85 || V_41 -> V_86 ) ) {
F_37 ( V_12 -> V_68 -> V_87 ) ;
if ( V_41 -> V_88 && V_41 -> V_89 )
V_43 . V_51 |= V_52 ;
V_43 . V_51 &= V_76 -> V_51 ;
if ( V_43 . V_51 & V_72 )
F_45 ( V_76 , & V_43 ) ;
else
V_43 . V_51 &= ~ ( V_90 |
V_91 |
V_52 ) ;
F_19 ( V_12 , V_3 , V_41 , & V_43 ) ;
return V_82 ;
} else if ( V_41 -> V_84 && ! ( V_41 -> V_85 || V_41 -> V_86 || V_41 -> V_83 ) ) {
F_35 ( V_12 , V_3 , V_41 , & V_43 , F_27 ( V_41 -> V_47 ) ) ;
return V_82 ;
}
return V_92 ;
}
static unsigned int F_46 ( const struct V_93 * V_94 ,
struct V_2 * V_3 ,
const struct V_95 * V_96 )
{
struct V_11 * V_12 = F_40 ( F_41 ( V_96 -> V_78 ? : V_96 -> V_97 ) ) ;
enum V_16 V_17 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_42 V_43 = {} ;
const struct V_62 * V_63 ;
struct V_19 * V_41 , V_79 ;
T_3 V_102 ;
T_4 V_9 ;
int V_81 ;
V_99 = F_47 ( V_3 , & V_17 ) ;
if ( V_99 == NULL )
return V_103 ;
V_101 = F_48 ( V_99 ) ;
if ( V_101 == NULL )
return V_103 ;
if ( F_49 ( V_3 ) )
return V_103 ;
V_9 = F_20 ( V_3 ) -> V_9 ;
V_81 = F_50 ( V_3 , sizeof( struct V_1 ) , & V_9 ,
& V_102 ) ;
if ( V_81 < 0 )
return V_103 ;
V_41 = F_43 ( V_3 , V_81 , sizeof( V_79 ) , & V_79 ) ;
if ( V_41 == NULL )
return V_82 ;
V_63 = & V_99 -> V_104 . V_105 ;
switch ( V_63 -> V_63 ) {
case V_106 :
if ( V_41 -> V_86 && ! F_51 ( V_107 , & V_99 -> V_108 ) ) {
F_52 ( V_99 , V_17 , V_101 -> V_109 -
F_27 ( V_41 -> V_47 ) + 1 ) ;
break;
}
if ( ! V_41 -> V_83 || V_41 -> V_84 ||
F_53 ( V_17 ) != V_65 )
break;
F_52 ( V_99 , V_17 , 0 ) ;
V_101 -> V_110 = 0 ;
F_37 ( V_12 -> V_68 -> V_111 ) ;
case V_112 :
if ( ! F_44 ( V_3 , V_81 , V_41 , & V_43 ) )
return V_82 ;
if ( ! V_41 -> V_83 && V_41 -> V_84 &&
F_53 ( V_17 ) == V_65 ) {
if ( F_35 ( V_12 , V_3 , V_41 , & V_43 ,
F_27 ( V_41 -> V_47 ) + 1 ) )
F_37 ( V_12 -> V_68 -> V_113 ) ;
return V_82 ;
}
V_101 -> V_109 = F_27 ( V_41 -> V_48 ) ;
if ( V_43 . V_51 & V_72 )
V_101 -> V_114 = V_43 . V_115 ;
break;
case V_116 :
if ( ! V_41 -> V_83 || ! V_41 -> V_84 )
break;
if ( ! F_44 ( V_3 , V_81 , V_41 , & V_43 ) )
return V_82 ;
if ( V_43 . V_51 & V_72 )
V_101 -> V_110 = V_43 . V_117 - V_101 -> V_114 ;
V_43 . V_51 &= ~ ( V_71 |
V_90 |
V_91 ) ;
F_54 ( V_43 . V_117 , V_43 . V_115 ) ;
F_31 ( V_12 , V_63 , V_3 , V_41 , & V_43 ) ;
F_52 ( V_99 , V_17 , V_101 -> V_109 - F_27 ( V_41 -> V_47 ) ) ;
F_54 ( V_43 . V_117 , V_43 . V_115 ) ;
F_33 ( V_12 , V_3 , V_41 , & V_43 ) ;
F_55 ( V_3 ) ;
return V_118 ;
default:
break;
}
F_56 ( V_3 , V_81 , V_41 , V_99 , V_17 , V_101 ) ;
return V_103 ;
}
static int F_57 ( const struct V_119 * V_74 )
{
const struct V_120 * V_121 = V_74 -> V_122 ;
if ( ! ( V_121 -> V_123 . V_124 & V_125 ) ||
V_121 -> V_123 . V_104 != V_10 ||
V_121 -> V_123 . V_126 & V_127 )
return - V_128 ;
return F_58 ( V_74 -> V_129 ) ;
}
static void F_59 ( const struct V_130 * V_74 )
{
F_60 ( V_74 -> V_129 ) ;
}
static int T_5 F_61 ( void )
{
int V_131 ;
V_131 = F_62 ( V_132 ,
F_63 ( V_132 ) ) ;
if ( V_131 < 0 )
goto V_133;
V_131 = F_64 ( & V_134 ) ;
if ( V_131 < 0 )
goto V_135;
return 0 ;
V_135:
F_65 ( V_132 , F_63 ( V_132 ) ) ;
V_133:
return V_131 ;
}
static void T_6 F_66 ( void )
{
F_67 ( & V_134 ) ;
F_65 ( V_132 , F_63 ( V_132 ) ) ;
}
