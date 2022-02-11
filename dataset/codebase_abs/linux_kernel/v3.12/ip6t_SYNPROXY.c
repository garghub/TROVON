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
if ( V_41 -> V_49 & V_72 )
F_38 ( V_41 ) ;
F_30 ( V_57 , V_3 , V_39 , V_41 , V_58 ) ;
return true ;
}
static unsigned int
F_39 ( struct V_2 * V_3 , const struct V_73 * V_74 )
{
const struct V_75 * V_76 = V_74 -> V_77 ;
struct V_56 * V_57 = F_40 ( F_41 ( V_74 -> V_78 ) ) ;
struct V_40 V_41 = {} ;
struct V_17 * V_39 , V_79 ;
if ( F_42 ( V_3 , V_74 -> V_80 , V_74 -> V_81 , V_10 ) )
return V_82 ;
V_39 = F_43 ( V_3 , V_74 -> V_81 , sizeof( V_79 ) , & V_79 ) ;
if ( V_39 == NULL )
return V_82 ;
if ( ! F_44 ( V_3 , V_74 -> V_81 , V_39 , & V_41 ) )
return V_82 ;
if ( V_39 -> V_83 && ! ( V_39 -> V_84 || V_39 -> V_85 || V_39 -> V_86 ) ) {
F_37 ( V_57 -> V_69 -> V_87 ) ;
if ( V_39 -> V_88 && V_39 -> V_89 )
V_41 . V_49 |= V_50 ;
V_41 . V_49 &= V_76 -> V_49 ;
if ( V_41 . V_49 & V_72 )
F_45 ( V_76 , & V_41 ) ;
else
V_41 . V_49 &= ~ ( V_90 |
V_91 |
V_50 ) ;
F_19 ( V_3 , V_39 , & V_41 ) ;
return V_82 ;
} else if ( V_39 -> V_84 && ! ( V_39 -> V_85 || V_39 -> V_86 || V_39 -> V_83 ) ) {
F_35 ( V_57 , V_3 , V_39 , & V_41 , F_27 ( V_39 -> V_45 ) ) ;
return V_82 ;
}
return V_92 ;
}
static unsigned int F_46 ( unsigned int V_80 ,
struct V_2 * V_3 ,
const struct V_93 * V_78 ,
const struct V_93 * V_94 ,
int (* F_47)( struct V_2 * ) )
{
struct V_56 * V_57 = F_40 ( F_41 ( V_78 ? : V_94 ) ) ;
enum V_14 V_15 ;
struct V_21 * V_95 ;
struct V_96 * V_97 ;
struct V_40 V_41 = {} ;
const struct V_63 * V_64 ;
struct V_17 * V_39 , V_79 ;
T_3 V_98 ;
T_4 V_9 ;
int V_81 ;
V_95 = F_48 ( V_3 , & V_15 ) ;
if ( V_95 == NULL )
return V_99 ;
V_97 = F_49 ( V_95 ) ;
if ( V_97 == NULL )
return V_99 ;
if ( F_50 ( V_3 ) )
return V_99 ;
V_9 = F_20 ( V_3 ) -> V_9 ;
V_81 = F_51 ( V_3 , sizeof( struct V_1 ) , & V_9 ,
& V_98 ) ;
if ( V_81 < 0 )
return V_99 ;
V_39 = F_43 ( V_3 , V_81 , sizeof( V_79 ) , & V_79 ) ;
if ( V_39 == NULL )
return V_82 ;
V_64 = & V_95 -> V_100 . V_101 ;
switch ( V_64 -> V_64 ) {
case V_102 :
if ( V_39 -> V_86 && ! F_52 ( V_103 , & V_95 -> V_104 ) ) {
F_53 ( V_95 , V_15 , V_97 -> V_105 -
F_27 ( V_39 -> V_45 ) + 1 ) ;
break;
}
if ( ! V_39 -> V_83 || V_39 -> V_84 ||
F_54 ( V_15 ) != V_66 )
break;
F_53 ( V_95 , V_15 , 0 ) ;
V_97 -> V_106 = 0 ;
F_37 ( V_57 -> V_69 -> V_107 ) ;
case V_108 :
if ( ! F_44 ( V_3 , V_81 , V_39 , & V_41 ) )
return V_82 ;
if ( ! V_39 -> V_83 && V_39 -> V_84 &&
F_54 ( V_15 ) == V_66 ) {
if ( F_35 ( V_57 , V_3 , V_39 , & V_41 ,
F_27 ( V_39 -> V_45 ) + 1 ) )
F_37 ( V_57 -> V_69 -> V_109 ) ;
return V_82 ;
}
V_97 -> V_105 = F_27 ( V_39 -> V_46 ) ;
if ( V_41 . V_49 & V_72 )
V_97 -> V_110 = V_41 . V_111 ;
break;
case V_112 :
if ( ! V_39 -> V_83 || ! V_39 -> V_84 )
break;
if ( ! F_44 ( V_3 , V_81 , V_39 , & V_41 ) )
return V_82 ;
if ( V_41 . V_49 & V_72 )
V_97 -> V_106 = V_41 . V_113 - V_97 -> V_110 ;
V_41 . V_49 &= ~ ( V_114 |
V_90 |
V_91 ) ;
F_55 ( V_41 . V_113 , V_41 . V_111 ) ;
F_31 ( V_57 , V_64 , V_3 , V_39 , & V_41 ) ;
F_53 ( V_95 , V_15 , V_97 -> V_105 - F_27 ( V_39 -> V_45 ) ) ;
F_55 ( V_41 . V_113 , V_41 . V_111 ) ;
F_33 ( V_57 , V_3 , V_39 , & V_41 ) ;
F_56 ( V_3 ) ;
return V_115 ;
default:
break;
}
F_57 ( V_3 , V_81 , V_39 , V_95 , V_15 , V_97 ) ;
return V_99 ;
}
static int F_58 ( const struct V_116 * V_74 )
{
const struct V_117 * V_118 = V_74 -> V_119 ;
if ( ! ( V_118 -> V_120 . V_121 & V_122 ) ||
V_118 -> V_120 . V_100 != V_10 ||
V_118 -> V_120 . V_123 & V_124 )
return - V_125 ;
return F_59 ( V_74 -> V_126 ) ;
}
static void F_60 ( const struct V_127 * V_74 )
{
F_61 ( V_74 -> V_126 ) ;
}
static int T_5 F_62 ( void )
{
int V_128 ;
V_128 = F_63 ( V_129 ,
F_64 ( V_129 ) ) ;
if ( V_128 < 0 )
goto V_130;
V_128 = F_65 ( & V_131 ) ;
if ( V_128 < 0 )
goto V_132;
return 0 ;
V_132:
F_66 ( V_129 , F_64 ( V_129 ) ) ;
V_130:
return V_128 ;
}
static void T_6 F_67 ( void )
{
F_68 ( & V_131 ) ;
F_66 ( V_129 , F_64 ( V_129 ) ) ;
}
