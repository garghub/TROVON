static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static inline struct V_1 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_1 , V_4 ) ;
}
static void F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_1 * V_12 = V_9 -> V_13 ;
struct V_14 * V_15 = V_12 -> V_4 . V_5 . V_16 -> V_15 ;
if ( V_11 -> V_17 != 0 ) {
F_5 ( & V_15 -> V_18 -> V_19 , L_1 ,
V_12 -> V_20 , V_11 -> V_17 ) ;
return;
}
if ( V_11 -> V_21 != sizeof( V_12 -> V_22 ) ) {
F_5 ( & V_15 -> V_18 -> V_19 , L_2 ,
V_12 -> V_20 , V_11 -> V_21 ) ;
F_6 ( V_9 ) ;
} else {
struct V_23 * V_24 = V_11 -> V_25 ;
V_12 -> V_22 = * V_24 ;
}
}
static int F_7 ( struct V_2 * V_3 , const struct V_26 * V_27 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_3 -> V_16 -> V_15 ;
struct V_10 * V_11 = V_15 -> V_11 ;
int V_24 = - V_28 ;
T_1 V_29 = F_8 ( V_27 -> V_30 ) ;
T_1 V_31 = F_8 ( V_27 -> V_32 ) ;
T_1 V_33 = F_8 ( V_27 -> V_34 ) ;
switch ( ( V_27 -> V_35 << 8 ) | V_27 -> V_36 ) {
case ( ( V_37 | V_38 | V_39 ) << 8 )
| V_40 :
if ( V_33 != sizeof( struct V_23 )
|| V_29 != V_12 -> V_41 )
goto V_42;
V_24 = V_33 ;
V_15 -> V_18 -> V_43 -> V_13 = V_12 ;
V_11 -> V_44 = F_4 ;
break;
case ( ( V_45 | V_38 | V_39 ) << 8 )
| V_46 :
if ( V_29 != V_12 -> V_41 )
goto V_42;
V_24 = F_9 ( unsigned , V_33 ,
sizeof( struct V_23 ) ) ;
memcpy ( V_11 -> V_25 , & V_12 -> V_22 , V_24 ) ;
break;
case ( ( V_37 | V_38 | V_39 ) << 8 )
| V_47 :
if ( V_29 != V_12 -> V_41 )
goto V_42;
V_24 = 0 ;
V_12 -> V_48 = V_31 ;
break;
default:
V_42:
F_10 ( & V_15 -> V_18 -> V_19 ,
L_3 ,
V_27 -> V_35 , V_27 -> V_36 ,
V_31 , V_29 , V_33 ) ;
}
if ( V_24 >= 0 ) {
F_5 ( & V_15 -> V_18 -> V_19 ,
L_4 ,
V_12 -> V_20 , V_27 -> V_35 , V_27 -> V_36 ,
V_31 , V_29 , V_33 ) ;
V_11 -> V_49 = 0 ;
V_11 -> V_50 = V_24 ;
V_24 = F_11 ( V_15 -> V_18 -> V_43 , V_11 , V_51 ) ;
if ( V_24 < 0 )
ERROR ( V_15 , L_5 ,
V_12 -> V_20 , V_24 ) ;
}
return V_24 ;
}
static int F_12 ( struct V_2 * V_3 , unsigned V_52 , unsigned V_53 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_3 -> V_16 -> V_15 ;
if ( V_52 == V_12 -> V_41 ) {
F_10 ( & V_15 -> V_18 -> V_19 ,
L_6 , V_52 ) ;
F_13 ( V_12 -> V_54 ) ;
if ( ! V_12 -> V_54 -> V_55 )
if ( F_14 ( V_15 -> V_18 , V_3 , V_12 -> V_54 ) )
return - V_56 ;
F_15 ( V_12 -> V_54 ) ;
} else if ( V_52 == V_12 -> V_57 ) {
if ( V_12 -> V_54 -> V_58 ) {
F_5 ( & V_15 -> V_18 -> V_19 ,
L_7 , V_12 -> V_20 ) ;
F_16 ( & V_12 -> V_4 ) ;
}
if ( ! V_12 -> V_4 . V_59 -> V_55 || ! V_12 -> V_4 . V_60 -> V_55 ) {
F_5 ( & V_15 -> V_18 -> V_19 ,
L_8 , V_12 -> V_20 ) ;
if ( F_14 ( V_15 -> V_18 , V_3 ,
V_12 -> V_4 . V_59 ) ||
F_14 ( V_15 -> V_18 , V_3 ,
V_12 -> V_4 . V_60 ) ) {
V_12 -> V_4 . V_59 -> V_55 = NULL ;
V_12 -> V_4 . V_60 -> V_55 = NULL ;
return - V_56 ;
}
}
F_17 ( & V_12 -> V_4 , V_12 -> V_20 ) ;
} else
return - V_56 ;
return 0 ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_3 -> V_16 -> V_15 ;
F_5 ( & V_15 -> V_18 -> V_19 , L_9 , V_12 -> V_20 ) ;
F_16 ( & V_12 -> V_4 ) ;
F_13 ( V_12 -> V_54 ) ;
}
static int F_19 ( struct V_1 * V_12 , T_2 type , T_1 V_24 ,
void * V_61 , unsigned V_50 )
{
struct V_8 * V_9 = V_12 -> V_54 ;
struct V_10 * V_11 ;
struct V_62 * V_54 ;
const unsigned V_63 = sizeof( * V_54 ) + V_50 ;
void * V_25 ;
int V_17 ;
V_11 = V_12 -> V_64 ;
V_12 -> V_64 = NULL ;
V_12 -> V_65 = false ;
V_11 -> V_50 = V_63 ;
V_54 = V_11 -> V_25 ;
V_25 = V_54 + 1 ;
V_54 -> V_66 = V_45 | V_38
| V_39 ;
V_54 -> V_67 = type ;
V_54 -> V_32 = F_20 ( V_24 ) ;
V_54 -> V_30 = F_20 ( V_12 -> V_41 ) ;
V_54 -> V_34 = F_20 ( V_50 ) ;
memcpy ( V_25 , V_61 , V_50 ) ;
F_21 ( & V_12 -> V_68 ) ;
V_17 = F_11 ( V_9 , V_11 , V_51 ) ;
F_22 ( & V_12 -> V_68 ) ;
if ( V_17 < 0 ) {
ERROR ( V_12 -> V_4 . V_5 . V_16 -> V_15 ,
L_10 ,
V_12 -> V_20 , V_17 ) ;
V_12 -> V_64 = V_11 ;
}
return V_17 ;
}
static int F_23 ( struct V_1 * V_12 )
{
struct V_14 * V_15 = V_12 -> V_4 . V_5 . V_16 -> V_15 ;
int V_17 ;
F_22 ( & V_12 -> V_68 ) ;
if ( V_12 -> V_64 ) {
F_5 ( & V_15 -> V_18 -> V_19 , L_11 ,
V_12 -> V_20 , V_12 -> V_69 ) ;
V_17 = F_19 ( V_12 , V_70 ,
0 , & V_12 -> V_69 , sizeof( V_12 -> V_69 ) ) ;
} else {
V_12 -> V_65 = true ;
V_17 = 0 ;
}
F_21 ( & V_12 -> V_68 ) ;
return V_17 ;
}
static void F_24 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_1 * V_12 = V_11 -> V_71 ;
T_2 V_72 = false ;
F_22 ( & V_12 -> V_68 ) ;
if ( V_11 -> V_17 != - V_73 )
V_72 = V_12 -> V_65 ;
V_12 -> V_64 = V_11 ;
F_21 ( & V_12 -> V_68 ) ;
if ( V_72 )
F_23 ( V_12 ) ;
}
static void F_25 ( struct V_6 * V_4 )
{
struct V_1 * V_12 = F_3 ( V_4 ) ;
V_12 -> V_69 |= V_74 | V_75 ;
F_23 ( V_12 ) ;
}
static void F_26 ( struct V_6 * V_4 )
{
struct V_1 * V_12 = F_3 ( V_4 ) ;
V_12 -> V_69 &= ~ ( V_74 | V_75 ) ;
F_23 ( V_12 ) ;
}
static int F_27 ( struct V_6 * V_4 , int V_76 )
{
struct V_1 * V_12 = F_3 ( V_4 ) ;
T_1 V_77 ;
V_77 = V_12 -> V_69 ;
V_77 &= ~ V_78 ;
if ( V_76 )
V_77 |= V_78 ;
V_12 -> V_69 = V_77 ;
return F_23 ( V_12 ) ;
}
static int
F_28 ( struct V_79 * V_80 , struct V_2 * V_3 )
{
struct V_14 * V_15 = V_80 -> V_15 ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_81 * V_82 ;
int V_17 ;
struct V_8 * V_9 ;
V_82 = F_29 ( V_15 , V_83 ,
F_30 ( V_84 ) ) ;
if ( F_31 ( V_82 ) )
return F_32 ( V_82 ) ;
V_85 . V_86 = V_82 [ V_87 ] . V_88 ;
V_89 . V_86 = V_82 [ V_90 ] . V_88 ;
V_91 . V_92 = V_82 [ V_93 ] . V_88 ;
V_17 = F_33 ( V_80 , V_3 ) ;
if ( V_17 < 0 )
goto V_94;
V_12 -> V_41 = V_17 ;
V_91 . V_95 = V_17 ;
V_85 . V_96 = V_17 ;
V_97 . V_98 = V_17 ;
V_17 = F_33 ( V_80 , V_3 ) ;
if ( V_17 < 0 )
goto V_94;
V_12 -> V_57 = V_17 ;
V_89 . V_96 = V_17 ;
V_97 . V_99 = V_17 ;
V_100 . V_101 = V_17 ;
V_17 = - V_102 ;
V_9 = F_34 ( V_15 -> V_18 , & V_103 ) ;
if ( ! V_9 )
goto V_94;
V_12 -> V_4 . V_59 = V_9 ;
V_9 = F_34 ( V_15 -> V_18 , & V_104 ) ;
if ( ! V_9 )
goto V_94;
V_12 -> V_4 . V_60 = V_9 ;
V_9 = F_34 ( V_15 -> V_18 , & V_105 ) ;
if ( ! V_9 )
goto V_94;
V_12 -> V_54 = V_9 ;
V_12 -> V_64 = F_35 ( V_9 ,
sizeof( struct V_62 ) + 2 ,
V_106 ) ;
if ( ! V_12 -> V_64 )
goto V_94;
V_12 -> V_64 -> V_44 = F_24 ;
V_12 -> V_64 -> V_71 = V_12 ;
V_107 . V_108 = V_103 . V_108 ;
V_109 . V_108 = V_104 . V_108 ;
V_110 . V_108 =
V_105 . V_108 ;
V_111 . V_108 = V_103 . V_108 ;
V_112 . V_108 = V_104 . V_108 ;
V_17 = F_36 ( V_3 , V_113 , V_114 ,
V_115 ) ;
if ( V_17 )
goto V_94;
F_5 ( & V_15 -> V_18 -> V_19 ,
L_12 ,
V_12 -> V_20 ,
F_37 ( V_80 -> V_15 -> V_18 ) ? L_13 :
F_38 ( V_80 -> V_15 -> V_18 ) ? L_14 : L_15 ,
V_12 -> V_4 . V_59 -> V_116 , V_12 -> V_4 . V_60 -> V_116 ,
V_12 -> V_54 -> V_116 ) ;
return 0 ;
V_94:
if ( V_12 -> V_64 )
F_39 ( V_12 -> V_54 , V_12 -> V_64 ) ;
ERROR ( V_15 , L_16 , V_3 -> V_116 , V_3 , V_17 ) ;
return V_17 ;
}
static void F_40 ( struct V_79 * V_80 , struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
V_84 [ 0 ] . V_88 = 0 ;
F_41 ( V_3 ) ;
if ( V_12 -> V_64 )
F_39 ( V_12 -> V_54 , V_12 -> V_64 ) ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_43 ( V_12 ) ;
}
static struct V_2 * F_44 ( struct V_117 * V_118 )
{
struct V_119 * V_120 ;
struct V_1 * V_12 ;
V_12 = F_45 ( sizeof( * V_12 ) , V_106 ) ;
if ( ! V_12 )
return F_46 ( - V_121 ) ;
F_47 ( & V_12 -> V_68 ) ;
V_12 -> V_4 . V_122 = F_25 ;
V_12 -> V_4 . V_123 = F_26 ;
V_12 -> V_4 . V_124 = F_27 ;
V_12 -> V_4 . V_5 . V_116 = L_17 ;
V_12 -> V_4 . V_5 . V_125 = V_83 ;
V_12 -> V_4 . V_5 . V_126 = F_28 ;
V_12 -> V_4 . V_5 . V_127 = F_12 ;
V_12 -> V_4 . V_5 . V_128 = F_7 ;
V_12 -> V_4 . V_5 . V_129 = F_18 ;
V_120 = F_2 ( V_118 , struct V_119 , V_130 ) ;
V_12 -> V_20 = V_120 -> V_20 ;
V_12 -> V_4 . V_5 . V_131 = F_40 ;
V_12 -> V_4 . V_5 . V_132 = F_42 ;
return & V_12 -> V_4 . V_5 ;
}
static inline struct V_119 * F_48 ( struct V_133 * V_134 )
{
return F_2 ( F_49 ( V_134 ) , struct V_119 ,
V_130 . V_135 ) ;
}
static void F_50 ( struct V_133 * V_134 )
{
struct V_119 * V_120 = F_48 ( V_134 ) ;
F_51 ( & V_120 -> V_130 ) ;
}
static T_3 F_52 ( struct V_133 * V_134 , char * V_136 )
{
return sprintf ( V_136 , L_18 , F_48 ( V_134 ) -> V_20 ) ;
}
static void F_53 ( struct V_117 * V_118 )
{
struct V_119 * V_120 ;
V_120 = F_2 ( V_118 , struct V_119 , V_130 ) ;
F_54 ( V_120 -> V_20 ) ;
F_43 ( V_120 ) ;
}
static struct V_117 * F_55 ( void )
{
struct V_119 * V_120 ;
int V_137 ;
V_120 = F_45 ( sizeof( * V_120 ) , V_106 ) ;
if ( ! V_120 )
return F_46 ( - V_121 ) ;
V_120 -> V_130 . V_138 = F_53 ;
V_137 = F_56 ( & V_120 -> V_20 ) ;
if ( V_137 ) {
F_43 ( V_120 ) ;
return F_46 ( V_137 ) ;
}
F_57 ( & V_120 -> V_130 . V_135 , L_19 ,
& V_139 ) ;
return & V_120 -> V_130 ;
}
