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
F_17 ( V_22 , V_13 -> V_41 , V_13 ) ;
return;
V_39:
F_18 ( V_13 ) ;
}
static void
F_19 ( const struct V_11 * V_12 ,
const struct V_2 * V_3 , const struct V_19 * V_42 ,
const struct V_43 * V_44 )
{
struct V_2 * V_13 ;
struct V_1 * V_7 , * V_18 ;
struct V_19 * V_20 ;
unsigned int V_21 ;
T_1 V_45 = V_44 -> V_45 ;
V_7 = F_20 ( V_3 ) ;
V_21 = sizeof( * V_20 ) + F_21 ( V_44 ) ;
V_13 = F_22 ( sizeof( * V_18 ) + V_21 + V_46 ,
V_47 ) ;
if ( V_13 == NULL )
return;
F_23 ( V_13 , V_46 ) ;
V_18 = F_1 ( V_13 , & V_7 -> V_6 , & V_7 -> V_5 ) ;
F_24 ( V_13 ) ;
V_20 = (struct V_19 * ) F_3 ( V_13 , V_21 ) ;
V_20 -> V_36 = V_42 -> V_38 ;
V_20 -> V_38 = V_42 -> V_36 ;
V_20 -> V_48 = F_25 ( F_26 ( V_7 , V_42 , & V_45 ) ) ;
V_20 -> V_49 = F_25 ( F_27 ( V_42 -> V_48 ) + 1 ) ;
F_28 ( V_20 ) = V_50 | V_51 ;
if ( V_44 -> V_52 & V_53 )
F_28 ( V_20 ) |= V_54 ;
V_20 -> V_55 = V_21 / 4 ;
V_20 -> V_56 = 0 ;
V_20 -> V_28 = 0 ;
V_20 -> V_57 = 0 ;
F_29 ( V_20 , V_44 ) ;
F_5 ( V_12 , V_3 , V_13 , V_3 -> V_15 , V_58 ,
V_18 , V_20 , V_21 ) ;
}
static void
F_30 ( const struct V_11 * V_12 ,
const struct V_2 * V_3 , const struct V_19 * V_42 ,
const struct V_43 * V_44 , T_2 V_59 )
{
struct V_2 * V_13 ;
struct V_1 * V_7 , * V_18 ;
struct V_19 * V_20 ;
unsigned int V_21 ;
V_7 = F_20 ( V_3 ) ;
V_21 = sizeof( * V_20 ) + F_21 ( V_44 ) ;
V_13 = F_22 ( sizeof( * V_18 ) + V_21 + V_46 ,
V_47 ) ;
if ( V_13 == NULL )
return;
F_23 ( V_13 , V_46 ) ;
V_18 = F_1 ( V_13 , & V_7 -> V_5 , & V_7 -> V_6 ) ;
F_24 ( V_13 ) ;
V_20 = (struct V_19 * ) F_3 ( V_13 , V_21 ) ;
V_20 -> V_36 = V_42 -> V_36 ;
V_20 -> V_38 = V_42 -> V_38 ;
V_20 -> V_48 = F_25 ( V_59 - 1 ) ;
V_20 -> V_49 = F_25 ( F_27 ( V_42 -> V_49 ) - 1 ) ;
F_28 ( V_20 ) = V_50 ;
if ( V_44 -> V_52 & V_53 )
F_28 ( V_20 ) |= V_54 | V_60 ;
V_20 -> V_55 = V_21 / 4 ;
V_20 -> V_56 = V_42 -> V_56 ;
V_20 -> V_28 = 0 ;
V_20 -> V_57 = 0 ;
F_29 ( V_20 , V_44 ) ;
F_5 ( V_12 , V_3 , V_13 , & V_12 -> V_23 -> V_61 , V_62 ,
V_18 , V_20 , V_21 ) ;
}
static void
F_31 ( const struct V_11 * V_12 ,
const struct V_63 * V_64 ,
const struct V_2 * V_3 , const struct V_19 * V_42 ,
const struct V_43 * V_44 )
{
struct V_2 * V_13 ;
struct V_1 * V_7 , * V_18 ;
struct V_19 * V_20 ;
unsigned int V_21 ;
V_7 = F_20 ( V_3 ) ;
V_21 = sizeof( * V_20 ) + F_21 ( V_44 ) ;
V_13 = F_22 ( sizeof( * V_18 ) + V_21 + V_46 ,
V_47 ) ;
if ( V_13 == NULL )
return;
F_23 ( V_13 , V_46 ) ;
V_18 = F_1 ( V_13 , & V_7 -> V_6 , & V_7 -> V_5 ) ;
F_24 ( V_13 ) ;
V_20 = (struct V_19 * ) F_3 ( V_13 , V_21 ) ;
V_20 -> V_36 = V_42 -> V_38 ;
V_20 -> V_38 = V_42 -> V_36 ;
V_20 -> V_48 = F_25 ( F_27 ( V_42 -> V_49 ) ) ;
V_20 -> V_49 = F_25 ( F_27 ( V_42 -> V_48 ) + 1 ) ;
F_28 ( V_20 ) = V_51 ;
V_20 -> V_55 = V_21 / 4 ;
V_20 -> V_56 = F_32 ( V_64 -> V_65 [ V_66 ] . V_67 ) ;
V_20 -> V_28 = 0 ;
V_20 -> V_57 = 0 ;
F_29 ( V_20 , V_44 ) ;
F_5 ( V_12 , V_3 , V_13 , NULL , 0 , V_18 , V_20 , V_21 ) ;
}
static void
F_33 ( const struct V_11 * V_12 ,
const struct V_2 * V_3 , const struct V_19 * V_42 ,
const struct V_43 * V_44 )
{
struct V_2 * V_13 ;
struct V_1 * V_7 , * V_18 ;
struct V_19 * V_20 ;
unsigned int V_21 ;
V_7 = F_20 ( V_3 ) ;
V_21 = sizeof( * V_20 ) + F_21 ( V_44 ) ;
V_13 = F_22 ( sizeof( * V_18 ) + V_21 + V_46 ,
V_47 ) ;
if ( V_13 == NULL )
return;
F_23 ( V_13 , V_46 ) ;
V_18 = F_1 ( V_13 , & V_7 -> V_5 , & V_7 -> V_6 ) ;
F_24 ( V_13 ) ;
V_20 = (struct V_19 * ) F_3 ( V_13 , V_21 ) ;
V_20 -> V_36 = V_42 -> V_36 ;
V_20 -> V_38 = V_42 -> V_38 ;
V_20 -> V_48 = F_25 ( F_27 ( V_42 -> V_48 ) + 1 ) ;
V_20 -> V_49 = V_42 -> V_49 ;
F_28 ( V_20 ) = V_51 ;
V_20 -> V_55 = V_21 / 4 ;
V_20 -> V_56 = F_32 ( F_34 ( V_42 -> V_56 ) >> V_44 -> V_68 ) ;
V_20 -> V_28 = 0 ;
V_20 -> V_57 = 0 ;
F_29 ( V_20 , V_44 ) ;
F_5 ( V_12 , V_3 , V_13 , V_3 -> V_15 , V_58 ,
V_18 , V_20 , V_21 ) ;
}
static bool
F_35 ( const struct V_11 * V_12 ,
const struct V_2 * V_3 , const struct V_19 * V_42 ,
struct V_43 * V_44 , T_2 V_59 )
{
int V_45 ;
V_45 = F_36 ( F_20 ( V_3 ) , V_42 , F_27 ( V_42 -> V_49 ) - 1 ) ;
if ( V_45 == 0 ) {
F_37 ( V_12 -> V_69 -> V_70 ) ;
return false ;
}
F_37 ( V_12 -> V_69 -> V_71 ) ;
V_44 -> V_45 = V_45 ;
V_44 -> V_52 |= V_72 ;
if ( V_44 -> V_52 & V_73 )
F_38 ( V_44 ) ;
F_30 ( V_12 , V_3 , V_42 , V_44 , V_59 ) ;
return true ;
}
static unsigned int
F_39 ( struct V_2 * V_3 , const struct V_74 * V_75 )
{
const struct V_76 * V_77 = V_75 -> V_78 ;
struct V_11 * V_12 = F_40 ( V_75 -> V_22 ) ;
struct V_43 V_44 = {} ;
struct V_19 * V_42 , V_79 ;
if ( F_41 ( V_3 , V_75 -> V_80 , V_75 -> V_81 , V_10 ) )
return V_82 ;
V_42 = F_42 ( V_3 , V_75 -> V_81 , sizeof( V_79 ) , & V_79 ) ;
if ( V_42 == NULL )
return V_82 ;
if ( ! F_43 ( V_3 , V_75 -> V_81 , V_42 , & V_44 ) )
return V_82 ;
if ( V_42 -> V_83 && ! ( V_42 -> V_84 || V_42 -> V_85 || V_42 -> V_86 ) ) {
F_37 ( V_12 -> V_69 -> V_87 ) ;
if ( V_42 -> V_88 && V_42 -> V_89 )
V_44 . V_52 |= V_53 ;
V_44 . V_52 &= V_77 -> V_52 ;
if ( V_44 . V_52 & V_73 )
F_44 ( V_77 , & V_44 ) ;
else
V_44 . V_52 &= ~ ( V_90 |
V_91 |
V_53 ) ;
F_19 ( V_12 , V_3 , V_42 , & V_44 ) ;
return V_82 ;
} else if ( V_42 -> V_84 && ! ( V_42 -> V_85 || V_42 -> V_86 || V_42 -> V_83 ) ) {
F_35 ( V_12 , V_3 , V_42 , & V_44 , F_27 ( V_42 -> V_48 ) ) ;
return V_82 ;
}
return V_92 ;
}
static unsigned int F_45 ( void * V_93 ,
struct V_2 * V_3 ,
const struct V_94 * V_95 )
{
struct V_11 * V_12 = F_40 ( V_95 -> V_22 ) ;
enum V_16 V_17 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
struct V_43 V_44 = {} ;
const struct V_63 * V_64 ;
struct V_19 * V_42 , V_79 ;
T_3 V_100 ;
T_4 V_9 ;
int V_81 ;
V_97 = F_46 ( V_3 , & V_17 ) ;
if ( V_97 == NULL )
return V_101 ;
V_99 = F_47 ( V_97 ) ;
if ( V_99 == NULL )
return V_101 ;
if ( F_48 ( V_3 ) )
return V_101 ;
V_9 = F_20 ( V_3 ) -> V_9 ;
V_81 = F_49 ( V_3 , sizeof( struct V_1 ) , & V_9 ,
& V_100 ) ;
if ( V_81 < 0 )
return V_101 ;
V_42 = F_42 ( V_3 , V_81 , sizeof( V_79 ) , & V_79 ) ;
if ( V_42 == NULL )
return V_82 ;
V_64 = & V_97 -> V_102 . V_103 ;
switch ( V_64 -> V_64 ) {
case V_104 :
if ( V_42 -> V_86 && ! F_50 ( V_105 , & V_97 -> V_106 ) ) {
F_51 ( V_97 , V_17 , V_99 -> V_107 -
F_27 ( V_42 -> V_48 ) + 1 ) ;
break;
}
if ( ! V_42 -> V_83 || V_42 -> V_84 ||
F_52 ( V_17 ) != V_66 )
break;
F_51 ( V_97 , V_17 , 0 ) ;
V_99 -> V_108 = 0 ;
F_37 ( V_12 -> V_69 -> V_109 ) ;
case V_110 :
if ( ! F_43 ( V_3 , V_81 , V_42 , & V_44 ) )
return V_82 ;
if ( ! V_42 -> V_83 && V_42 -> V_84 &&
F_52 ( V_17 ) == V_66 ) {
if ( F_35 ( V_12 , V_3 , V_42 , & V_44 ,
F_27 ( V_42 -> V_48 ) + 1 ) )
F_37 ( V_12 -> V_69 -> V_111 ) ;
return V_82 ;
}
V_99 -> V_107 = F_27 ( V_42 -> V_49 ) ;
if ( V_44 . V_52 & V_73 )
V_99 -> V_112 = V_44 . V_113 ;
break;
case V_114 :
if ( ! V_42 -> V_83 || ! V_42 -> V_84 )
break;
if ( ! F_43 ( V_3 , V_81 , V_42 , & V_44 ) )
return V_82 ;
if ( V_44 . V_52 & V_73 )
V_99 -> V_108 = V_44 . V_115 - V_99 -> V_112 ;
V_44 . V_52 &= ~ ( V_72 |
V_90 |
V_91 ) ;
F_53 ( V_44 . V_115 , V_44 . V_113 ) ;
F_31 ( V_12 , V_64 , V_3 , V_42 , & V_44 ) ;
F_51 ( V_97 , V_17 , V_99 -> V_107 - F_27 ( V_42 -> V_48 ) ) ;
F_53 ( V_44 . V_115 , V_44 . V_113 ) ;
F_33 ( V_12 , V_3 , V_42 , & V_44 ) ;
F_54 ( V_3 ) ;
return V_116 ;
default:
break;
}
F_55 ( V_3 , V_81 , V_42 , V_97 , V_17 , V_99 ) ;
return V_101 ;
}
static int F_56 ( const struct V_117 * V_75 )
{
const struct V_118 * V_119 = V_75 -> V_120 ;
if ( ! ( V_119 -> V_121 . V_122 & V_123 ) ||
V_119 -> V_121 . V_102 != V_10 ||
V_119 -> V_121 . V_124 & V_125 )
return - V_126 ;
return F_57 ( V_75 -> V_127 ) ;
}
static void F_58 ( const struct V_128 * V_75 )
{
F_59 ( V_75 -> V_127 ) ;
}
static int T_5 F_60 ( void )
{
int V_129 ;
V_129 = F_61 ( V_130 ,
F_62 ( V_130 ) ) ;
if ( V_129 < 0 )
goto V_131;
V_129 = F_63 ( & V_132 ) ;
if ( V_129 < 0 )
goto V_133;
return 0 ;
V_133:
F_64 ( V_130 , F_62 ( V_130 ) ) ;
V_131:
return V_129 ;
}
static void T_6 F_65 ( void )
{
F_66 ( & V_132 ) ;
F_64 ( V_130 , F_62 ( V_130 ) ) ;
}
