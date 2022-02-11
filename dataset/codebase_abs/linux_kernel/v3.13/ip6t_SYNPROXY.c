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
F_5 ( const struct V_2 * V_3 , struct V_2 * V_11 ,
struct V_12 * V_13 , enum V_14 V_15 ,
struct V_1 * V_16 , struct V_17 * V_18 ,
unsigned int V_19 )
{
struct V_20 * V_20 = F_6 ( (struct V_21 * ) V_13 ) ;
struct V_22 * V_23 ;
struct V_24 V_25 ;
V_18 -> V_26 = ~ F_7 ( V_19 , & V_16 -> V_5 , & V_16 -> V_6 , 0 ) ;
V_11 -> V_27 = V_28 ;
V_11 -> V_29 = ( unsigned char * ) V_18 - V_11 -> V_30 ;
V_11 -> V_31 = F_8 ( struct V_17 , V_26 ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_32 = V_10 ;
V_25 . V_5 = V_16 -> V_5 ;
V_25 . V_6 = V_16 -> V_6 ;
V_25 . V_33 = V_18 -> V_34 ;
V_25 . V_35 = V_18 -> V_36 ;
F_9 ( (struct V_2 * ) V_3 , F_10 ( & V_25 ) ) ;
V_23 = F_11 ( V_20 , NULL , & V_25 ) ;
if ( V_23 == NULL || V_23 -> error ) {
F_12 ( V_23 ) ;
goto V_37;
}
V_23 = F_13 ( V_20 , V_23 , F_10 ( & V_25 ) , NULL , 0 ) ;
if ( F_14 ( V_23 ) )
goto V_37;
F_15 ( V_11 , V_23 ) ;
if ( V_13 ) {
V_11 -> V_13 = V_13 ;
V_11 -> V_38 = V_15 ;
F_16 ( V_13 ) ;
}
F_17 ( V_11 ) ;
return;
V_37:
F_18 ( V_11 ) ;
}
static void
F_19 ( const struct V_2 * V_3 , const struct V_17 * V_39 ,
const struct V_40 * V_41 )
{
struct V_2 * V_11 ;
struct V_1 * V_7 , * V_16 ;
struct V_17 * V_18 ;
unsigned int V_19 ;
T_1 V_42 = V_41 -> V_42 ;
V_7 = F_20 ( V_3 ) ;
V_19 = sizeof( * V_18 ) + F_21 ( V_41 ) ;
V_11 = F_22 ( sizeof( * V_16 ) + V_19 + V_43 ,
V_44 ) ;
if ( V_11 == NULL )
return;
F_23 ( V_11 , V_43 ) ;
V_16 = F_1 ( V_11 , & V_7 -> V_6 , & V_7 -> V_5 ) ;
F_24 ( V_11 ) ;
V_18 = (struct V_17 * ) F_3 ( V_11 , V_19 ) ;
V_18 -> V_34 = V_39 -> V_36 ;
V_18 -> V_36 = V_39 -> V_34 ;
V_18 -> V_45 = F_25 ( F_26 ( V_7 , V_39 , & V_42 ) ) ;
V_18 -> V_46 = F_25 ( F_27 ( V_39 -> V_45 ) + 1 ) ;
F_28 ( V_18 ) = V_47 | V_48 ;
if ( V_41 -> V_49 & V_50 )
F_28 ( V_18 ) |= V_51 ;
V_18 -> V_52 = V_19 / 4 ;
V_18 -> V_53 = 0 ;
V_18 -> V_26 = 0 ;
V_18 -> V_54 = 0 ;
F_29 ( V_18 , V_41 ) ;
F_5 ( V_3 , V_11 , V_3 -> V_13 , V_55 ,
V_16 , V_18 , V_19 ) ;
}
static void
F_30 ( const struct V_56 * V_57 ,
const struct V_2 * V_3 , const struct V_17 * V_39 ,
const struct V_40 * V_41 , T_2 V_58 )
{
struct V_2 * V_11 ;
struct V_1 * V_7 , * V_16 ;
struct V_17 * V_18 ;
unsigned int V_19 ;
V_7 = F_20 ( V_3 ) ;
V_19 = sizeof( * V_18 ) + F_21 ( V_41 ) ;
V_11 = F_22 ( sizeof( * V_16 ) + V_19 + V_43 ,
V_44 ) ;
if ( V_11 == NULL )
return;
F_23 ( V_11 , V_43 ) ;
V_16 = F_1 ( V_11 , & V_7 -> V_5 , & V_7 -> V_6 ) ;
F_24 ( V_11 ) ;
V_18 = (struct V_17 * ) F_3 ( V_11 , V_19 ) ;
V_18 -> V_34 = V_39 -> V_34 ;
V_18 -> V_36 = V_39 -> V_36 ;
V_18 -> V_45 = F_25 ( V_58 - 1 ) ;
V_18 -> V_46 = F_25 ( F_27 ( V_39 -> V_46 ) - 1 ) ;
F_28 ( V_18 ) = V_47 ;
if ( V_41 -> V_49 & V_50 )
F_28 ( V_18 ) |= V_51 | V_59 ;
V_18 -> V_52 = V_19 / 4 ;
V_18 -> V_53 = V_39 -> V_53 ;
V_18 -> V_26 = 0 ;
V_18 -> V_54 = 0 ;
F_29 ( V_18 , V_41 ) ;
F_5 ( V_3 , V_11 , & V_57 -> V_60 -> V_61 , V_62 ,
V_16 , V_18 , V_19 ) ;
}
static void
F_31 ( const struct V_56 * V_57 ,
const struct V_63 * V_64 ,
const struct V_2 * V_3 , const struct V_17 * V_39 ,
const struct V_40 * V_41 )
{
struct V_2 * V_11 ;
struct V_1 * V_7 , * V_16 ;
struct V_17 * V_18 ;
unsigned int V_19 ;
V_7 = F_20 ( V_3 ) ;
V_19 = sizeof( * V_18 ) + F_21 ( V_41 ) ;
V_11 = F_22 ( sizeof( * V_16 ) + V_19 + V_43 ,
V_44 ) ;
if ( V_11 == NULL )
return;
F_23 ( V_11 , V_43 ) ;
V_16 = F_1 ( V_11 , & V_7 -> V_6 , & V_7 -> V_5 ) ;
F_24 ( V_11 ) ;
V_18 = (struct V_17 * ) F_3 ( V_11 , V_19 ) ;
V_18 -> V_34 = V_39 -> V_36 ;
V_18 -> V_36 = V_39 -> V_34 ;
V_18 -> V_45 = F_25 ( F_27 ( V_39 -> V_46 ) ) ;
V_18 -> V_46 = F_25 ( F_27 ( V_39 -> V_45 ) + 1 ) ;
F_28 ( V_18 ) = V_48 ;
V_18 -> V_52 = V_19 / 4 ;
V_18 -> V_53 = F_32 ( V_64 -> V_65 [ V_66 ] . V_67 ) ;
V_18 -> V_26 = 0 ;
V_18 -> V_54 = 0 ;
F_29 ( V_18 , V_41 ) ;
F_5 ( V_3 , V_11 , NULL , 0 , V_16 , V_18 , V_19 ) ;
}
static void
F_33 ( const struct V_56 * V_57 ,
const struct V_2 * V_3 , const struct V_17 * V_39 ,
const struct V_40 * V_41 )
{
struct V_2 * V_11 ;
struct V_1 * V_7 , * V_16 ;
struct V_17 * V_18 ;
unsigned int V_19 ;
V_7 = F_20 ( V_3 ) ;
V_19 = sizeof( * V_18 ) + F_21 ( V_41 ) ;
V_11 = F_22 ( sizeof( * V_16 ) + V_19 + V_43 ,
V_44 ) ;
if ( V_11 == NULL )
return;
F_23 ( V_11 , V_43 ) ;
V_16 = F_1 ( V_11 , & V_7 -> V_5 , & V_7 -> V_6 ) ;
F_24 ( V_11 ) ;
V_18 = (struct V_17 * ) F_3 ( V_11 , V_19 ) ;
V_18 -> V_34 = V_39 -> V_34 ;
V_18 -> V_36 = V_39 -> V_36 ;
V_18 -> V_45 = F_25 ( F_27 ( V_39 -> V_45 ) + 1 ) ;
V_18 -> V_46 = V_39 -> V_46 ;
F_28 ( V_18 ) = V_48 ;
V_18 -> V_52 = V_19 / 4 ;
V_18 -> V_53 = F_34 ( F_32 ( V_39 -> V_53 ) >> V_41 -> V_68 ) ;
V_18 -> V_26 = 0 ;
V_18 -> V_54 = 0 ;
F_29 ( V_18 , V_41 ) ;
F_5 ( V_3 , V_11 , NULL , 0 , V_16 , V_18 , V_19 ) ;
}
static bool
F_35 ( const struct V_56 * V_57 ,
const struct V_2 * V_3 , const struct V_17 * V_39 ,
struct V_40 * V_41 , T_2 V_58 )
{
int V_42 ;
V_42 = F_36 ( F_20 ( V_3 ) , V_39 , F_27 ( V_39 -> V_46 ) - 1 ) ;
if ( V_42 == 0 ) {
F_37 ( V_57 -> V_69 -> V_70 ) ;
return false ;
}
F_37 ( V_57 -> V_69 -> V_71 ) ;
V_41 -> V_42 = V_42 ;
V_41 -> V_49 |= V_72 ;
if ( V_41 -> V_49 & V_73 )
F_38 ( V_41 ) ;
F_30 ( V_57 , V_3 , V_39 , V_41 , V_58 ) ;
return true ;
}
static unsigned int
F_39 ( struct V_2 * V_3 , const struct V_74 * V_75 )
{
const struct V_76 * V_77 = V_75 -> V_78 ;
struct V_56 * V_57 = F_40 ( F_41 ( V_75 -> V_79 ) ) ;
struct V_40 V_41 = {} ;
struct V_17 * V_39 , V_80 ;
if ( F_42 ( V_3 , V_75 -> V_81 , V_75 -> V_82 , V_10 ) )
return V_83 ;
V_39 = F_43 ( V_3 , V_75 -> V_82 , sizeof( V_80 ) , & V_80 ) ;
if ( V_39 == NULL )
return V_83 ;
if ( ! F_44 ( V_3 , V_75 -> V_82 , V_39 , & V_41 ) )
return V_83 ;
if ( V_39 -> V_84 && ! ( V_39 -> V_85 || V_39 -> V_86 || V_39 -> V_87 ) ) {
F_37 ( V_57 -> V_69 -> V_88 ) ;
if ( V_39 -> V_89 && V_39 -> V_90 )
V_41 . V_49 |= V_50 ;
V_41 . V_49 &= V_77 -> V_49 ;
if ( V_41 . V_49 & V_73 )
F_45 ( V_77 , & V_41 ) ;
else
V_41 . V_49 &= ~ ( V_91 |
V_92 |
V_50 ) ;
F_19 ( V_3 , V_39 , & V_41 ) ;
return V_83 ;
} else if ( V_39 -> V_85 && ! ( V_39 -> V_86 || V_39 -> V_87 || V_39 -> V_84 ) ) {
F_35 ( V_57 , V_3 , V_39 , & V_41 , F_27 ( V_39 -> V_45 ) ) ;
return V_83 ;
}
return V_93 ;
}
static unsigned int F_46 ( const struct V_94 * V_95 ,
struct V_2 * V_3 ,
const struct V_96 * V_79 ,
const struct V_96 * V_97 ,
int (* F_47)( struct V_2 * ) )
{
struct V_56 * V_57 = F_40 ( F_41 ( V_79 ? : V_97 ) ) ;
enum V_14 V_15 ;
struct V_21 * V_98 ;
struct V_99 * V_100 ;
struct V_40 V_41 = {} ;
const struct V_63 * V_64 ;
struct V_17 * V_39 , V_80 ;
T_3 V_101 ;
T_4 V_9 ;
int V_82 ;
V_98 = F_48 ( V_3 , & V_15 ) ;
if ( V_98 == NULL )
return V_102 ;
V_100 = F_49 ( V_98 ) ;
if ( V_100 == NULL )
return V_102 ;
if ( F_50 ( V_3 ) )
return V_102 ;
V_9 = F_20 ( V_3 ) -> V_9 ;
V_82 = F_51 ( V_3 , sizeof( struct V_1 ) , & V_9 ,
& V_101 ) ;
if ( V_82 < 0 )
return V_102 ;
V_39 = F_43 ( V_3 , V_82 , sizeof( V_80 ) , & V_80 ) ;
if ( V_39 == NULL )
return V_83 ;
V_64 = & V_98 -> V_103 . V_104 ;
switch ( V_64 -> V_64 ) {
case V_105 :
if ( V_39 -> V_87 && ! F_52 ( V_106 , & V_98 -> V_107 ) ) {
F_53 ( V_98 , V_15 , V_100 -> V_108 -
F_27 ( V_39 -> V_45 ) + 1 ) ;
break;
}
if ( ! V_39 -> V_84 || V_39 -> V_85 ||
F_54 ( V_15 ) != V_66 )
break;
F_53 ( V_98 , V_15 , 0 ) ;
V_100 -> V_109 = 0 ;
F_37 ( V_57 -> V_69 -> V_110 ) ;
case V_111 :
if ( ! F_44 ( V_3 , V_82 , V_39 , & V_41 ) )
return V_83 ;
if ( ! V_39 -> V_84 && V_39 -> V_85 &&
F_54 ( V_15 ) == V_66 ) {
if ( F_35 ( V_57 , V_3 , V_39 , & V_41 ,
F_27 ( V_39 -> V_45 ) + 1 ) )
F_37 ( V_57 -> V_69 -> V_112 ) ;
return V_83 ;
}
V_100 -> V_108 = F_27 ( V_39 -> V_46 ) ;
if ( V_41 . V_49 & V_73 )
V_100 -> V_113 = V_41 . V_114 ;
break;
case V_115 :
if ( ! V_39 -> V_84 || ! V_39 -> V_85 )
break;
if ( ! F_44 ( V_3 , V_82 , V_39 , & V_41 ) )
return V_83 ;
if ( V_41 . V_49 & V_73 )
V_100 -> V_109 = V_41 . V_116 - V_100 -> V_113 ;
V_41 . V_49 &= ~ ( V_72 |
V_91 |
V_92 ) ;
F_55 ( V_41 . V_116 , V_41 . V_114 ) ;
F_31 ( V_57 , V_64 , V_3 , V_39 , & V_41 ) ;
F_53 ( V_98 , V_15 , V_100 -> V_108 - F_27 ( V_39 -> V_45 ) ) ;
F_55 ( V_41 . V_116 , V_41 . V_114 ) ;
F_33 ( V_57 , V_3 , V_39 , & V_41 ) ;
F_56 ( V_3 ) ;
return V_117 ;
default:
break;
}
F_57 ( V_3 , V_82 , V_39 , V_98 , V_15 , V_100 ) ;
return V_102 ;
}
static int F_58 ( const struct V_118 * V_75 )
{
const struct V_119 * V_120 = V_75 -> V_121 ;
if ( ! ( V_120 -> V_122 . V_123 & V_124 ) ||
V_120 -> V_122 . V_103 != V_10 ||
V_120 -> V_122 . V_125 & V_126 )
return - V_127 ;
return F_59 ( V_75 -> V_128 ) ;
}
static void F_60 ( const struct V_129 * V_75 )
{
F_61 ( V_75 -> V_128 ) ;
}
static int T_5 F_62 ( void )
{
int V_130 ;
V_130 = F_63 ( V_131 ,
F_64 ( V_131 ) ) ;
if ( V_130 < 0 )
goto V_132;
V_130 = F_65 ( & V_133 ) ;
if ( V_130 < 0 )
goto V_134;
return 0 ;
V_134:
F_66 ( V_131 , F_64 ( V_131 ) ) ;
V_132:
return V_130 ;
}
static void T_6 F_67 ( void )
{
F_68 ( & V_133 ) ;
F_66 ( V_131 , F_64 ( V_131 ) ) ;
}
