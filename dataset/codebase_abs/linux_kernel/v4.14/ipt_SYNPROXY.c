static struct V_1 *
F_1 ( struct V_2 * V_2 , struct V_3 * V_4 , T_1 V_5 ,
T_1 V_6 )
{
struct V_1 * V_7 ;
F_2 ( V_4 ) ;
V_7 = F_3 ( V_4 , sizeof( * V_7 ) ) ;
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
F_11 ( V_20 , (struct V_37 * ) V_22 , V_24 ) ;
F_12 ( V_22 ) ;
}
F_13 ( V_2 , V_20 -> V_38 , V_20 ) ;
return;
V_36:
F_14 ( V_20 ) ;
}
static void
F_15 ( struct V_2 * V_2 ,
const struct V_3 * V_4 , const struct V_26 * V_39 ,
const struct V_40 * V_41 )
{
struct V_3 * V_20 ;
struct V_1 * V_7 , * V_25 ;
struct V_26 * V_27 ;
unsigned int V_28 ;
T_2 V_42 = V_41 -> V_42 ;
V_7 = F_16 ( V_4 ) ;
V_28 = sizeof( * V_27 ) + F_17 ( V_41 ) ;
V_20 = F_18 ( sizeof( * V_25 ) + V_28 + V_43 ,
V_44 ) ;
if ( V_20 == NULL )
return;
F_19 ( V_20 , V_43 ) ;
V_25 = F_1 ( V_2 , V_20 , V_7 -> V_6 , V_7 -> V_5 ) ;
F_20 ( V_20 ) ;
V_27 = F_3 ( V_20 , V_28 ) ;
V_27 -> V_45 = V_39 -> V_46 ;
V_27 -> V_46 = V_39 -> V_45 ;
V_27 -> V_47 = F_21 ( F_22 ( V_7 , V_39 , & V_42 ) ) ;
V_27 -> V_48 = F_21 ( F_23 ( V_39 -> V_47 ) + 1 ) ;
F_24 ( V_27 ) = V_49 | V_50 ;
if ( V_41 -> V_51 & V_52 )
F_24 ( V_27 ) |= V_53 ;
V_27 -> V_54 = V_28 / 4 ;
V_27 -> V_55 = 0 ;
V_27 -> V_19 = 0 ;
V_27 -> V_56 = 0 ;
F_25 ( V_27 , V_41 ) ;
F_5 ( V_2 , V_4 , V_20 , F_26 ( V_4 ) ,
V_57 , V_25 , V_27 , V_28 ) ;
}
static void
F_27 ( struct V_2 * V_2 ,
const struct V_3 * V_4 , const struct V_26 * V_39 ,
const struct V_40 * V_41 , T_3 V_58 )
{
struct V_59 * V_60 = F_28 ( V_2 ) ;
struct V_3 * V_20 ;
struct V_1 * V_7 , * V_25 ;
struct V_26 * V_27 ;
unsigned int V_28 ;
V_7 = F_16 ( V_4 ) ;
V_28 = sizeof( * V_27 ) + F_17 ( V_41 ) ;
V_20 = F_18 ( sizeof( * V_25 ) + V_28 + V_43 ,
V_44 ) ;
if ( V_20 == NULL )
return;
F_19 ( V_20 , V_43 ) ;
V_25 = F_1 ( V_2 , V_20 , V_7 -> V_5 , V_7 -> V_6 ) ;
F_20 ( V_20 ) ;
V_27 = F_3 ( V_20 , V_28 ) ;
V_27 -> V_45 = V_39 -> V_45 ;
V_27 -> V_46 = V_39 -> V_46 ;
V_27 -> V_47 = F_21 ( V_58 - 1 ) ;
V_27 -> V_48 = F_21 ( F_23 ( V_39 -> V_48 ) - 1 ) ;
F_24 ( V_27 ) = V_49 ;
if ( V_41 -> V_51 & V_52 )
F_24 ( V_27 ) |= V_53 | V_61 ;
V_27 -> V_54 = V_28 / 4 ;
V_27 -> V_55 = V_39 -> V_55 ;
V_27 -> V_19 = 0 ;
V_27 -> V_56 = 0 ;
F_25 ( V_27 , V_41 ) ;
F_5 ( V_2 , V_4 , V_20 , & V_60 -> V_62 -> V_63 , V_64 ,
V_25 , V_27 , V_28 ) ;
}
static void
F_29 ( struct V_2 * V_2 ,
const struct V_65 * V_66 ,
const struct V_3 * V_4 , const struct V_26 * V_39 ,
const struct V_40 * V_41 )
{
struct V_3 * V_20 ;
struct V_1 * V_7 , * V_25 ;
struct V_26 * V_27 ;
unsigned int V_28 ;
V_7 = F_16 ( V_4 ) ;
V_28 = sizeof( * V_27 ) + F_17 ( V_41 ) ;
V_20 = F_18 ( sizeof( * V_25 ) + V_28 + V_43 ,
V_44 ) ;
if ( V_20 == NULL )
return;
F_19 ( V_20 , V_43 ) ;
V_25 = F_1 ( V_2 , V_20 , V_7 -> V_6 , V_7 -> V_5 ) ;
F_20 ( V_20 ) ;
V_27 = F_3 ( V_20 , V_28 ) ;
V_27 -> V_45 = V_39 -> V_46 ;
V_27 -> V_46 = V_39 -> V_45 ;
V_27 -> V_47 = F_21 ( F_23 ( V_39 -> V_48 ) ) ;
V_27 -> V_48 = F_21 ( F_23 ( V_39 -> V_47 ) + 1 ) ;
F_24 ( V_27 ) = V_50 ;
V_27 -> V_54 = V_28 / 4 ;
V_27 -> V_55 = F_4 ( V_66 -> V_67 [ V_68 ] . V_69 ) ;
V_27 -> V_19 = 0 ;
V_27 -> V_56 = 0 ;
F_25 ( V_27 , V_41 ) ;
F_5 ( V_2 , V_4 , V_20 , NULL , 0 , V_25 , V_27 , V_28 ) ;
}
static void
F_30 ( struct V_2 * V_2 ,
const struct V_3 * V_4 , const struct V_26 * V_39 ,
const struct V_40 * V_41 )
{
struct V_3 * V_20 ;
struct V_1 * V_7 , * V_25 ;
struct V_26 * V_27 ;
unsigned int V_28 ;
V_7 = F_16 ( V_4 ) ;
V_28 = sizeof( * V_27 ) + F_17 ( V_41 ) ;
V_20 = F_18 ( sizeof( * V_25 ) + V_28 + V_43 ,
V_44 ) ;
if ( V_20 == NULL )
return;
F_19 ( V_20 , V_43 ) ;
V_25 = F_1 ( V_2 , V_20 , V_7 -> V_5 , V_7 -> V_6 ) ;
F_20 ( V_20 ) ;
V_27 = F_3 ( V_20 , V_28 ) ;
V_27 -> V_45 = V_39 -> V_45 ;
V_27 -> V_46 = V_39 -> V_46 ;
V_27 -> V_47 = F_21 ( F_23 ( V_39 -> V_47 ) + 1 ) ;
V_27 -> V_48 = V_39 -> V_48 ;
F_24 ( V_27 ) = V_50 ;
V_27 -> V_54 = V_28 / 4 ;
V_27 -> V_55 = F_4 ( F_31 ( V_39 -> V_55 ) >> V_41 -> V_70 ) ;
V_27 -> V_19 = 0 ;
V_27 -> V_56 = 0 ;
F_25 ( V_27 , V_41 ) ;
F_5 ( V_2 , V_4 , V_20 , F_26 ( V_4 ) ,
V_57 , V_25 , V_27 , V_28 ) ;
}
static bool
F_32 ( struct V_2 * V_2 ,
const struct V_3 * V_4 , const struct V_26 * V_39 ,
struct V_40 * V_41 , T_3 V_58 )
{
struct V_59 * V_60 = F_28 ( V_2 ) ;
int V_42 ;
V_42 = F_33 ( F_16 ( V_4 ) , V_39 , F_23 ( V_39 -> V_48 ) - 1 ) ;
if ( V_42 == 0 ) {
F_34 ( V_60 -> V_71 -> V_72 ) ;
return false ;
}
F_34 ( V_60 -> V_71 -> V_73 ) ;
V_41 -> V_42 = V_42 ;
V_41 -> V_51 |= V_74 ;
if ( V_41 -> V_51 & V_75 )
F_35 ( V_41 ) ;
F_27 ( V_2 , V_4 , V_39 , V_41 , V_58 ) ;
return true ;
}
static unsigned int
F_36 ( struct V_3 * V_4 , const struct V_76 * V_77 )
{
const struct V_78 * V_79 = V_77 -> V_80 ;
struct V_2 * V_2 = F_37 ( V_77 ) ;
struct V_59 * V_60 = F_28 ( V_2 ) ;
struct V_40 V_41 = {} ;
struct V_26 * V_39 , V_81 ;
if ( F_38 ( V_4 , F_39 ( V_77 ) , V_77 -> V_82 , V_18 ) )
return V_83 ;
V_39 = F_40 ( V_4 , V_77 -> V_82 , sizeof( V_81 ) , & V_81 ) ;
if ( V_39 == NULL )
return V_83 ;
if ( ! F_41 ( V_4 , V_77 -> V_82 , V_39 , & V_41 ) )
return V_83 ;
if ( V_39 -> V_84 && ! ( V_39 -> V_85 || V_39 -> V_86 || V_39 -> V_87 ) ) {
F_34 ( V_60 -> V_71 -> V_88 ) ;
if ( V_39 -> V_89 && V_39 -> V_90 )
V_41 . V_51 |= V_52 ;
V_41 . V_51 &= V_79 -> V_51 ;
if ( V_41 . V_51 & V_75 )
F_42 ( V_79 , & V_41 ) ;
else
V_41 . V_51 &= ~ ( V_91 |
V_92 |
V_52 ) ;
F_15 ( V_2 , V_4 , V_39 , & V_41 ) ;
F_43 ( V_4 ) ;
return V_93 ;
} else if ( V_39 -> V_85 && ! ( V_39 -> V_86 || V_39 -> V_87 || V_39 -> V_84 ) ) {
if ( F_32 ( V_2 , V_4 , V_39 , & V_41 , F_23 ( V_39 -> V_47 ) ) ) {
F_43 ( V_4 ) ;
return V_93 ;
} else {
return V_83 ;
}
}
return V_94 ;
}
static unsigned int F_44 ( void * V_95 ,
struct V_3 * V_4 ,
const struct V_96 * V_97 )
{
struct V_2 * V_2 = V_97 -> V_2 ;
struct V_59 * V_60 = F_28 ( V_2 ) ;
enum V_23 V_24 ;
struct V_37 * V_98 ;
struct V_99 * V_100 ;
struct V_40 V_41 = {} ;
const struct V_65 * V_66 ;
struct V_26 * V_39 , V_81 ;
unsigned int V_82 ;
V_98 = F_45 ( V_4 , & V_24 ) ;
if ( V_98 == NULL )
return V_101 ;
V_100 = F_46 ( V_98 ) ;
if ( V_100 == NULL )
return V_101 ;
if ( F_47 ( V_4 ) ||
F_16 ( V_4 ) -> V_17 != V_18 )
return V_101 ;
V_82 = F_48 ( V_4 ) ;
V_39 = F_40 ( V_4 , V_82 , sizeof( V_81 ) , & V_81 ) ;
if ( V_39 == NULL )
return V_83 ;
V_66 = & V_98 -> V_102 . V_103 ;
switch ( V_66 -> V_66 ) {
case V_104 :
if ( V_39 -> V_87 && ! F_49 ( V_105 , & V_98 -> V_106 ) ) {
F_50 ( V_98 , V_24 , V_100 -> V_107 -
F_23 ( V_39 -> V_47 ) + 1 ) ;
break;
}
if ( ! V_39 -> V_84 || V_39 -> V_85 ||
F_51 ( V_24 ) != V_68 )
break;
F_50 ( V_98 , V_24 , 0 ) ;
V_100 -> V_108 = 0 ;
F_34 ( V_60 -> V_71 -> V_109 ) ;
case V_110 :
if ( ! F_41 ( V_4 , V_82 , V_39 , & V_41 ) )
return V_83 ;
if ( ! V_39 -> V_84 && V_39 -> V_85 &&
F_51 ( V_24 ) == V_68 ) {
if ( F_32 ( V_2 , V_4 , V_39 , & V_41 ,
F_23 ( V_39 -> V_47 ) + 1 ) ) {
F_34 ( V_60 -> V_71 -> V_111 ) ;
F_43 ( V_4 ) ;
return V_93 ;
} else {
return V_83 ;
}
}
V_100 -> V_107 = F_23 ( V_39 -> V_48 ) ;
if ( V_41 . V_51 & V_75 )
V_100 -> V_112 = V_41 . V_113 ;
break;
case V_114 :
if ( ! V_39 -> V_84 || ! V_39 -> V_85 )
break;
if ( ! F_41 ( V_4 , V_82 , V_39 , & V_41 ) )
return V_83 ;
if ( V_41 . V_51 & V_75 )
V_100 -> V_108 = V_41 . V_115 - V_100 -> V_112 ;
V_41 . V_51 &= ~ ( V_74 |
V_91 |
V_92 ) ;
F_52 ( V_41 . V_115 , V_41 . V_113 ) ;
F_29 ( V_2 , V_66 , V_4 , V_39 , & V_41 ) ;
F_50 ( V_98 , V_24 , V_100 -> V_107 - F_23 ( V_39 -> V_47 ) ) ;
F_52 ( V_41 . V_115 , V_41 . V_113 ) ;
F_30 ( V_2 , V_4 , V_39 , & V_41 ) ;
F_43 ( V_4 ) ;
return V_93 ;
default:
break;
}
F_53 ( V_4 , V_82 , V_39 , V_98 , V_24 , V_100 ) ;
return V_101 ;
}
static int F_54 ( const struct V_116 * V_77 )
{
struct V_59 * V_60 = F_28 ( V_77 -> V_2 ) ;
const struct V_117 * V_118 = V_77 -> V_119 ;
int V_120 ;
if ( V_118 -> V_121 . V_102 != V_18 ||
V_118 -> V_121 . V_122 & V_123 )
return - V_124 ;
V_120 = F_55 ( V_77 -> V_2 , V_77 -> V_125 ) ;
if ( V_120 )
return V_120 ;
if ( V_60 -> V_126 == 0 ) {
V_120 = F_56 ( V_77 -> V_2 , V_127 ,
F_57 ( V_127 ) ) ;
if ( V_120 ) {
F_58 ( V_77 -> V_2 , V_77 -> V_125 ) ;
return V_120 ;
}
}
V_60 -> V_126 ++ ;
return V_120 ;
}
static void F_59 ( const struct V_128 * V_77 )
{
struct V_59 * V_60 = F_28 ( V_77 -> V_2 ) ;
V_60 -> V_126 -- ;
if ( V_60 -> V_126 == 0 )
F_60 ( V_77 -> V_2 , V_127 ,
F_57 ( V_127 ) ) ;
F_58 ( V_77 -> V_2 , V_77 -> V_125 ) ;
}
static int T_4 F_61 ( void )
{
return F_62 ( & V_129 ) ;
}
static void T_5 F_63 ( void )
{
F_64 ( & V_129 ) ;
}
