static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
const struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 ;
const struct V_10 * V_11 ;
const int type = F_3 ( V_2 ) -> type ;
const int V_12 = F_3 ( V_2 ) -> V_12 ;
struct V_13 * V_14 ;
switch ( type ) {
default:
case V_15 :
return V_16 ;
case V_17 :
switch ( V_12 ) {
case V_18 :
case V_19 :
return V_16 ;
default:
break;
}
break;
case V_20 :
if ( V_12 != V_21 )
return V_16 ;
break;
case V_22 :
break;
}
if ( V_5 -> V_23 == F_4 ( V_24 ) )
V_9 = F_5 ( V_6 , V_25 ) ;
else
V_9 = F_5 ( V_6 , V_26 ) ;
V_11 = ( const struct V_10 * ) ( F_3 ( V_2 ) + 1 ) ;
V_14 = F_6 ( V_9 , V_2 -> V_7 -> V_27 , V_5 -> V_28 ,
V_11 -> V_29 , V_11 -> V_30 , V_5 -> V_31 ) ;
if ( V_14 == NULL )
return V_32 ;
if ( V_14 -> V_33 . V_11 . V_29 == 0 ||
F_7 ( V_14 -> V_33 . V_11 . V_29 ) )
return V_16 ;
if ( V_14 -> V_33 . V_11 . V_34 == 0 && type == V_20 )
return V_16 ;
if ( F_8 ( V_35 , V_14 -> V_36 + V_37 ) )
V_14 -> V_38 ++ ;
else
V_14 -> V_38 = 1 ;
V_14 -> V_36 = V_35 ;
return V_16 ;
}
static int F_9 ( struct V_1 * V_2 , const struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 ;
const struct V_10 * V_11 ;
struct V_13 * V_39 ;
if ( V_5 -> V_23 == F_4 ( V_24 ) )
V_9 = F_5 ( V_6 , V_25 ) ;
else
V_9 = F_5 ( V_6 , V_26 ) ;
V_11 = F_10 ( V_2 ) ;
V_39 = F_6 ( V_9 , V_2 -> V_7 -> V_27 , V_5 -> V_28 ,
V_11 -> V_30 , V_11 -> V_29 , V_5 -> V_31 ) ;
if ( V_39 ) {
F_11 ( V_2 ) ;
F_12 ( V_39 , V_2 , V_5 , V_40 ) ;
return V_16 ;
}
return V_32 ;
}
static void F_13 ( struct V_1 * V_2 , struct V_41 * V_7 ,
const struct V_10 * V_42 ,
T_2 V_23 )
{
struct V_13 * V_39 = F_14 ( V_7 ) ;
struct V_4 V_5 ;
V_5 . V_28 = V_39 -> V_33 . V_43 ;
V_5 . V_23 = V_23 ;
V_5 . V_31 = V_39 -> V_33 . V_44 ;
if ( V_39 -> V_33 . V_43 & V_45 )
V_39 -> V_46 ++ ;
V_5 . V_47 = F_15 ( V_39 -> V_46 ) ;
F_16 ( V_2 , & V_5 , V_39 -> V_48 ) ;
F_17 ( V_2 , V_7 , V_42 , V_42 -> V_49 ) ;
}
static T_3 F_18 ( struct V_1 * V_2 ,
struct V_41 * V_7 )
{
struct V_13 * V_39 = F_14 ( V_7 ) ;
const struct V_10 * V_42 ;
V_2 = F_19 ( V_2 , ! ! ( V_39 -> V_33 . V_43 & V_50 ) ) ;
if ( F_20 ( V_2 ) )
goto V_51;
if ( V_7 -> V_52 ) {
if ( F_21 ( V_2 , V_7 -> V_53 -
( V_39 -> V_48 + sizeof( struct V_10 ) ) ) )
goto V_54;
V_42 = ( const struct V_10 * ) V_2 -> V_55 ;
F_22 ( V_2 , V_39 -> V_48 + sizeof( struct V_10 ) ) ;
} else {
if ( F_21 ( V_2 , V_7 -> V_53 ) )
goto V_54;
V_42 = & V_39 -> V_33 . V_11 ;
}
F_13 ( V_2 , V_7 , V_42 , V_2 -> V_49 ) ;
return V_56 ;
V_54:
F_23 ( V_2 ) ;
V_51:
V_7 -> V_57 . V_58 ++ ;
return V_56 ;
}
static T_3 F_24 ( struct V_1 * V_2 ,
struct V_41 * V_7 )
{
struct V_13 * V_39 = F_14 ( V_7 ) ;
V_2 = F_19 ( V_2 , ! ! ( V_39 -> V_33 . V_43 & V_50 ) ) ;
if ( F_20 ( V_2 ) )
goto V_51;
if ( F_21 ( V_2 , V_7 -> V_53 ) )
goto V_54;
F_13 ( V_2 , V_7 , & V_39 -> V_33 . V_11 , F_4 ( V_24 ) ) ;
return V_56 ;
V_54:
F_23 ( V_2 ) ;
V_51:
V_7 -> V_57 . V_58 ++ ;
return V_56 ;
}
static int F_25 ( struct V_41 * V_7 ,
struct V_59 * V_60 , int V_61 )
{
int V_62 = 0 ;
struct V_63 V_64 ;
if ( F_26 ( & V_64 , V_60 -> V_65 . V_66 , sizeof( V_64 ) ) )
return - V_67 ;
if ( V_61 == V_68 || V_61 == V_69 ) {
if ( V_64 . V_11 . V_70 != 4 || V_64 . V_11 . V_49 != V_71 ||
V_64 . V_11 . V_72 != 5 || ( V_64 . V_11 . V_73 & F_4 ( ~ V_74 ) ) ||
( ( V_64 . V_75 | V_64 . V_43 ) & ( V_76 | V_77 ) ) )
return - V_78 ;
}
V_64 . V_75 = F_27 ( V_64 . V_75 ) ;
V_64 . V_43 = F_27 ( V_64 . V_43 ) ;
V_62 = F_28 ( V_7 , & V_64 , V_61 ) ;
if ( V_62 )
return V_62 ;
V_64 . V_75 = F_29 ( V_64 . V_75 ) ;
V_64 . V_43 = F_29 ( V_64 . V_43 ) ;
if ( F_30 ( V_60 -> V_65 . V_66 , & V_64 , sizeof( V_64 ) ) )
return - V_67 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_41 * V_7 ,
unsigned short type ,
const void * V_29 , const void * V_30 , unsigned int V_79 )
{
struct V_13 * V_14 = F_14 ( V_7 ) ;
struct V_10 * V_11 ;
struct V_80 * V_81 ;
V_11 = (struct V_10 * ) F_32 ( V_2 , V_14 -> V_48 + sizeof( * V_11 ) ) ;
V_81 = (struct V_80 * ) ( V_11 + 1 ) ;
V_81 -> V_28 = F_29 ( V_14 -> V_33 . V_43 ) ;
V_81 -> V_49 = F_4 ( type ) ;
memcpy ( V_11 , & V_14 -> V_33 . V_11 , sizeof( struct V_10 ) ) ;
if ( V_30 )
memcpy ( & V_11 -> V_30 , V_30 , 4 ) ;
if ( V_29 )
memcpy ( & V_11 -> V_29 , V_29 , 4 ) ;
if ( V_11 -> V_29 )
return V_14 -> V_48 + sizeof( * V_11 ) ;
return - ( V_14 -> V_48 + sizeof( * V_11 ) ) ;
}
static int F_33 ( const struct V_1 * V_2 , unsigned char * V_82 )
{
const struct V_10 * V_11 = ( const struct V_10 * ) F_34 ( V_2 ) ;
memcpy ( V_82 , & V_11 -> V_30 , 4 ) ;
return 4 ;
}
static int F_35 ( struct V_41 * V_7 )
{
struct V_13 * V_14 = F_14 ( V_7 ) ;
if ( F_7 ( V_14 -> V_33 . V_11 . V_29 ) ) {
struct V_83 V_84 ;
struct V_85 * V_86 ;
V_86 = F_36 ( V_14 -> V_6 , & V_84 ,
V_14 -> V_33 . V_11 . V_29 ,
V_14 -> V_33 . V_11 . V_30 ,
V_14 -> V_33 . V_44 ,
F_37 ( V_14 -> V_33 . V_11 . V_87 ) ,
V_14 -> V_33 . V_88 ) ;
if ( F_20 ( V_86 ) )
return - V_89 ;
V_7 = V_86 -> V_90 . V_7 ;
F_38 ( V_86 ) ;
if ( F_39 ( V_7 ) == NULL )
return - V_89 ;
V_14 -> V_91 = V_7 -> V_27 ;
F_40 ( F_39 ( V_7 ) , V_14 -> V_33 . V_11 . V_29 ) ;
}
return 0 ;
}
static int F_41 ( struct V_41 * V_7 )
{
struct V_13 * V_14 = F_14 ( V_7 ) ;
if ( F_7 ( V_14 -> V_33 . V_11 . V_29 ) && V_14 -> V_91 ) {
struct V_92 * V_93 ;
V_93 = F_42 ( V_14 -> V_6 , V_14 -> V_91 ) ;
if ( V_93 )
F_43 ( V_93 , V_14 -> V_33 . V_11 . V_29 ) ;
}
return 0 ;
}
static void F_44 ( struct V_41 * V_7 )
{
V_7 -> V_94 = & V_95 ;
V_7 -> type = V_96 ;
F_45 ( V_7 , V_26 ) ;
}
static void F_46 ( struct V_41 * V_7 )
{
struct V_13 * V_39 ;
V_39 = F_14 ( V_7 ) ;
V_39 -> V_48 = F_47 ( V_39 -> V_33 . V_43 ) ;
V_39 -> V_33 . V_11 . V_49 = V_71 ;
V_7 -> V_53 = V_97 + sizeof( struct V_10 ) + 4 ;
V_7 -> V_98 = V_99 - sizeof( struct V_10 ) - 4 ;
V_7 -> V_100 |= V_101 ;
V_7 -> V_102 |= V_101 ;
if ( ! ( V_39 -> V_33 . V_43 & V_45 ) ) {
V_7 -> V_100 |= V_103 ;
V_7 -> V_102 |= V_103 ;
V_7 -> V_100 |= V_104 ;
}
}
static int F_48 ( struct V_41 * V_7 )
{
struct V_13 * V_39 = F_14 ( V_7 ) ;
struct V_10 * V_11 = & V_39 -> V_33 . V_11 ;
F_46 ( V_7 ) ;
memcpy ( V_7 -> V_105 , & V_11 -> V_30 , 4 ) ;
memcpy ( V_7 -> V_106 , & V_11 -> V_29 , 4 ) ;
V_7 -> V_28 = V_107 ;
V_7 -> V_108 &= ~ V_109 ;
V_7 -> V_110 = 4 ;
if ( V_11 -> V_29 ) {
#ifdef F_49
if ( F_7 ( V_11 -> V_29 ) ) {
if ( ! V_11 -> V_30 )
return - V_78 ;
V_7 -> V_28 = V_111 ;
V_7 -> V_52 = & V_112 ;
}
#endif
} else
V_7 -> V_52 = & V_112 ;
return F_50 ( V_7 ) ;
}
static int T_4 F_51 ( struct V_6 * V_6 )
{
return F_52 ( V_6 , V_26 , & V_113 , NULL ) ;
}
static void T_5 F_53 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_5 ( V_6 , V_26 ) ;
F_54 ( V_9 , & V_113 ) ;
}
static int F_55 ( struct V_114 * V_115 [] , struct V_114 * V_55 [] )
{
T_2 V_28 ;
if ( ! V_55 )
return 0 ;
V_28 = 0 ;
if ( V_55 [ V_116 ] )
V_28 |= F_56 ( V_55 [ V_116 ] ) ;
if ( V_55 [ V_117 ] )
V_28 |= F_56 ( V_55 [ V_117 ] ) ;
if ( V_28 & ( V_76 | V_77 ) )
return - V_78 ;
return 0 ;
}
static int F_57 ( struct V_114 * V_115 [] , struct V_114 * V_55 [] )
{
T_6 V_29 ;
if ( V_115 [ V_118 ] ) {
if ( F_58 ( V_115 [ V_118 ] ) != V_119 )
return - V_78 ;
if ( ! F_59 ( F_60 ( V_115 [ V_118 ] ) ) )
return - V_89 ;
}
if ( ! V_55 )
goto V_51;
if ( V_55 [ V_120 ] ) {
memcpy ( & V_29 , F_60 ( V_55 [ V_120 ] ) , 4 ) ;
if ( ! V_29 )
return - V_78 ;
}
V_51:
return F_55 ( V_115 , V_55 ) ;
}
static void F_61 ( struct V_114 * V_55 [] , struct V_114 * V_115 [] ,
struct V_63 * V_33 )
{
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_11 . V_49 = V_71 ;
if ( ! V_55 )
return;
if ( V_55 [ V_121 ] )
V_33 -> V_88 = F_62 ( V_55 [ V_121 ] ) ;
if ( V_55 [ V_116 ] )
V_33 -> V_75 = F_27 ( F_56 ( V_55 [ V_116 ] ) ) ;
if ( V_55 [ V_117 ] )
V_33 -> V_43 = F_27 ( F_56 ( V_55 [ V_117 ] ) ) ;
if ( V_55 [ V_122 ] )
V_33 -> V_123 = F_63 ( V_55 [ V_122 ] ) ;
if ( V_55 [ V_124 ] )
V_33 -> V_44 = F_63 ( V_55 [ V_124 ] ) ;
if ( V_55 [ V_125 ] )
V_33 -> V_11 . V_30 = F_63 ( V_55 [ V_125 ] ) ;
if ( V_55 [ V_120 ] )
V_33 -> V_11 . V_29 = F_63 ( V_55 [ V_120 ] ) ;
if ( V_55 [ V_126 ] )
V_33 -> V_11 . V_34 = F_64 ( V_55 [ V_126 ] ) ;
if ( V_55 [ V_127 ] )
V_33 -> V_11 . V_87 = F_64 ( V_55 [ V_127 ] ) ;
if ( ! V_55 [ V_128 ] || F_64 ( V_55 [ V_128 ] ) )
V_33 -> V_11 . V_73 = F_4 ( V_74 ) ;
}
static int F_65 ( struct V_41 * V_7 )
{
F_46 ( V_7 ) ;
return F_50 ( V_7 ) ;
}
static void F_66 ( struct V_41 * V_7 )
{
F_67 ( V_7 ) ;
V_7 -> V_94 = & V_129 ;
V_7 -> V_108 |= V_130 ;
F_45 ( V_7 , V_25 ) ;
}
static int F_68 ( struct V_6 * V_131 , struct V_41 * V_7 ,
struct V_114 * V_115 [] , struct V_114 * V_55 [] )
{
struct V_63 V_64 ;
F_61 ( V_55 , V_115 , & V_64 ) ;
return F_69 ( V_7 , V_115 , & V_64 ) ;
}
static int F_70 ( struct V_41 * V_7 , struct V_114 * V_115 [] ,
struct V_114 * V_55 [] )
{
struct V_63 V_64 ;
F_61 ( V_55 , V_115 , & V_64 ) ;
return F_71 ( V_7 , V_115 , & V_64 ) ;
}
static T_7 F_72 ( const struct V_41 * V_7 )
{
return
F_73 ( 4 ) +
F_73 ( 2 ) +
F_73 ( 2 ) +
F_73 ( 4 ) +
F_73 ( 4 ) +
F_73 ( 4 ) +
F_73 ( 4 ) +
F_73 ( 1 ) +
F_73 ( 1 ) +
F_73 ( 1 ) +
0 ;
}
static int F_74 ( struct V_1 * V_2 , const struct V_41 * V_7 )
{
struct V_13 * V_14 = F_14 ( V_7 ) ;
struct V_63 * V_64 = & V_14 -> V_33 ;
if ( F_75 ( V_2 , V_121 , V_64 -> V_88 ) ||
F_76 ( V_2 , V_116 , F_29 ( V_64 -> V_75 ) ) ||
F_76 ( V_2 , V_117 , F_29 ( V_64 -> V_43 ) ) ||
F_77 ( V_2 , V_122 , V_64 -> V_123 ) ||
F_77 ( V_2 , V_124 , V_64 -> V_44 ) ||
F_77 ( V_2 , V_125 , V_64 -> V_11 . V_30 ) ||
F_77 ( V_2 , V_120 , V_64 -> V_11 . V_29 ) ||
F_78 ( V_2 , V_126 , V_64 -> V_11 . V_34 ) ||
F_78 ( V_2 , V_127 , V_64 -> V_11 . V_87 ) ||
F_78 ( V_2 , V_128 ,
! ! ( V_64 -> V_11 . V_73 & F_4 ( V_74 ) ) ) )
goto V_132;
return 0 ;
V_132:
return - V_133 ;
}
static int T_4 F_79 ( struct V_6 * V_6 )
{
return F_52 ( V_6 , V_25 , & V_134 , NULL ) ;
}
static void T_5 F_80 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_5 ( V_6 , V_25 ) ;
F_54 ( V_9 , & V_134 ) ;
}
static int T_8 F_81 ( void )
{
int V_62 ;
F_82 ( L_1 ) ;
V_62 = F_83 ( & V_135 ) ;
if ( V_62 < 0 )
return V_62 ;
V_62 = F_83 ( & V_136 ) ;
if ( V_62 < 0 )
goto V_137;
V_62 = F_84 ( & V_138 ) ;
if ( V_62 < 0 ) {
F_82 ( L_2 , V_139 ) ;
goto V_140;
}
V_62 = F_85 ( & V_113 ) ;
if ( V_62 < 0 )
goto V_141;
V_62 = F_85 ( & V_134 ) ;
if ( V_62 < 0 )
goto V_142;
return 0 ;
V_142:
F_86 ( & V_113 ) ;
V_141:
F_87 ( & V_138 ) ;
V_140:
F_88 ( & V_136 ) ;
V_137:
F_88 ( & V_135 ) ;
return V_62 ;
}
static void T_9 F_89 ( void )
{
F_86 ( & V_134 ) ;
F_86 ( & V_113 ) ;
F_87 ( & V_138 ) ;
F_88 ( & V_136 ) ;
F_88 ( & V_135 ) ;
}
