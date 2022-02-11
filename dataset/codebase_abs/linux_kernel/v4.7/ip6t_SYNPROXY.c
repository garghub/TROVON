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
struct V_2 * V_2 = V_77 -> V_2 ;
struct V_59 * V_60 = F_30 ( V_2 ) ;
struct V_42 V_43 = {} ;
struct V_20 * V_41 , V_81 ;
if ( F_40 ( V_4 , V_77 -> V_82 , V_77 -> V_83 , V_13 ) )
return V_84 ;
V_41 = F_41 ( V_4 , V_77 -> V_83 , sizeof( V_81 ) , & V_81 ) ;
if ( V_41 == NULL )
return V_84 ;
if ( ! F_42 ( V_4 , V_77 -> V_83 , V_41 , & V_43 ) )
return V_84 ;
if ( V_41 -> V_85 && ! ( V_41 -> V_86 || V_41 -> V_87 || V_41 -> V_88 ) ) {
F_37 ( V_60 -> V_71 -> V_89 ) ;
if ( V_41 -> V_90 && V_41 -> V_91 )
V_43 . V_51 |= V_52 ;
V_43 . V_51 &= V_79 -> V_51 ;
if ( V_43 . V_51 & V_75 )
F_43 ( V_79 , & V_43 ) ;
else
V_43 . V_51 &= ~ ( V_92 |
V_93 |
V_52 ) ;
F_18 ( V_2 , V_4 , V_41 , & V_43 ) ;
return V_84 ;
} else if ( V_41 -> V_86 && ! ( V_41 -> V_87 || V_41 -> V_88 || V_41 -> V_85 ) ) {
F_35 ( V_2 , V_4 , V_41 , & V_43 , F_26 ( V_41 -> V_47 ) ) ;
return V_84 ;
}
return V_94 ;
}
static unsigned int F_44 ( void * V_95 ,
struct V_3 * V_4 ,
const struct V_96 * V_97 )
{
struct V_2 * V_2 = V_97 -> V_2 ;
struct V_59 * V_60 = F_30 ( V_2 ) ;
enum V_17 V_18 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_42 V_43 = {} ;
const struct V_65 * V_66 ;
struct V_20 * V_41 , V_81 ;
T_3 V_102 ;
T_4 V_12 ;
int V_83 ;
V_99 = F_45 ( V_4 , & V_18 ) ;
if ( V_99 == NULL )
return V_103 ;
V_101 = F_46 ( V_99 ) ;
if ( V_101 == NULL )
return V_103 ;
if ( F_47 ( V_4 ) )
return V_103 ;
V_12 = F_19 ( V_4 ) -> V_12 ;
V_83 = F_48 ( V_4 , sizeof( struct V_1 ) , & V_12 ,
& V_102 ) ;
if ( V_83 < 0 )
return V_103 ;
V_41 = F_41 ( V_4 , V_83 , sizeof( V_81 ) , & V_81 ) ;
if ( V_41 == NULL )
return V_84 ;
V_66 = & V_99 -> V_104 . V_105 ;
switch ( V_66 -> V_66 ) {
case V_106 :
if ( V_41 -> V_88 && ! F_49 ( V_107 , & V_99 -> V_108 ) ) {
F_50 ( V_99 , V_18 , V_101 -> V_109 -
F_26 ( V_41 -> V_47 ) + 1 ) ;
break;
}
if ( ! V_41 -> V_85 || V_41 -> V_86 ||
F_51 ( V_18 ) != V_68 )
break;
F_50 ( V_99 , V_18 , 0 ) ;
V_101 -> V_110 = 0 ;
F_37 ( V_60 -> V_71 -> V_111 ) ;
case V_112 :
if ( ! F_42 ( V_4 , V_83 , V_41 , & V_43 ) )
return V_84 ;
if ( ! V_41 -> V_85 && V_41 -> V_86 &&
F_51 ( V_18 ) == V_68 ) {
if ( F_35 ( V_2 , V_4 , V_41 , & V_43 ,
F_26 ( V_41 -> V_47 ) + 1 ) )
F_37 ( V_60 -> V_71 -> V_113 ) ;
return V_84 ;
}
V_101 -> V_109 = F_26 ( V_41 -> V_48 ) ;
if ( V_43 . V_51 & V_75 )
V_101 -> V_114 = V_43 . V_115 ;
break;
case V_116 :
if ( ! V_41 -> V_85 || ! V_41 -> V_86 )
break;
if ( ! F_42 ( V_4 , V_83 , V_41 , & V_43 ) )
return V_84 ;
if ( V_43 . V_51 & V_75 )
V_101 -> V_110 = V_43 . V_117 - V_101 -> V_114 ;
V_43 . V_51 &= ~ ( V_74 |
V_92 |
V_93 ) ;
F_52 ( V_43 . V_117 , V_43 . V_115 ) ;
F_31 ( V_2 , V_66 , V_4 , V_41 , & V_43 ) ;
F_50 ( V_99 , V_18 , V_101 -> V_109 - F_26 ( V_41 -> V_47 ) ) ;
F_52 ( V_43 . V_117 , V_43 . V_115 ) ;
F_33 ( V_2 , V_4 , V_41 , & V_43 ) ;
F_53 ( V_4 ) ;
return V_118 ;
default:
break;
}
F_54 ( V_4 , V_83 , V_41 , V_99 , V_18 , V_101 ) ;
return V_103 ;
}
static int F_55 ( const struct V_119 * V_77 )
{
const struct V_120 * V_121 = V_77 -> V_122 ;
if ( ! ( V_121 -> V_10 . V_123 & V_124 ) ||
V_121 -> V_10 . V_104 != V_13 ||
V_121 -> V_10 . V_125 & V_126 )
return - V_127 ;
return F_56 ( V_77 -> V_128 ) ;
}
static void F_57 ( const struct V_129 * V_77 )
{
F_58 ( V_77 -> V_128 ) ;
}
static int T_5 F_59 ( void )
{
int V_130 ;
V_130 = F_60 ( V_131 ,
F_61 ( V_131 ) ) ;
if ( V_130 < 0 )
goto V_132;
V_130 = F_62 ( & V_133 ) ;
if ( V_130 < 0 )
goto V_134;
return 0 ;
V_134:
F_63 ( V_131 , F_61 ( V_131 ) ) ;
V_132:
return V_130 ;
}
static void T_6 F_64 ( void )
{
F_65 ( & V_133 ) ;
F_63 ( V_131 , F_61 ( V_131 ) ) ;
}
