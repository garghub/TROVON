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
if ( V_12 -> V_54 -> V_13 ) {
F_10 ( & V_15 -> V_18 -> V_19 ,
L_6 , V_52 ) ;
F_13 ( V_12 -> V_54 ) ;
}
if ( ! V_12 -> V_54 -> V_55 )
if ( F_14 ( V_15 -> V_18 , V_3 , V_12 -> V_54 ) )
return - V_56 ;
F_15 ( V_12 -> V_54 ) ;
V_12 -> V_54 -> V_13 = V_12 ;
} else if ( V_52 == V_12 -> V_57 ) {
if ( V_12 -> V_4 . V_58 -> V_13 ) {
F_5 ( & V_15 -> V_18 -> V_19 ,
L_7 , V_12 -> V_20 ) ;
F_16 ( & V_12 -> V_4 ) ;
}
if ( ! V_12 -> V_4 . V_58 -> V_55 || ! V_12 -> V_4 . V_59 -> V_55 ) {
F_5 ( & V_15 -> V_18 -> V_19 ,
L_8 , V_12 -> V_20 ) ;
if ( F_14 ( V_15 -> V_18 , V_3 ,
V_12 -> V_4 . V_58 ) ||
F_14 ( V_15 -> V_18 , V_3 ,
V_12 -> V_4 . V_59 ) ) {
V_12 -> V_4 . V_58 -> V_55 = NULL ;
V_12 -> V_4 . V_59 -> V_55 = NULL ;
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
V_12 -> V_54 -> V_13 = NULL ;
}
static int F_19 ( struct V_1 * V_12 , T_2 type , T_1 V_24 ,
void * V_60 , unsigned V_50 )
{
struct V_8 * V_9 = V_12 -> V_54 ;
struct V_10 * V_11 ;
struct V_61 * V_54 ;
const unsigned V_62 = sizeof( * V_54 ) + V_50 ;
void * V_25 ;
int V_17 ;
V_11 = V_12 -> V_63 ;
V_12 -> V_63 = NULL ;
V_12 -> V_64 = false ;
V_11 -> V_50 = V_62 ;
V_54 = V_11 -> V_25 ;
V_25 = V_54 + 1 ;
V_54 -> V_65 = V_45 | V_38
| V_39 ;
V_54 -> V_66 = type ;
V_54 -> V_32 = F_20 ( V_24 ) ;
V_54 -> V_30 = F_20 ( V_12 -> V_41 ) ;
V_54 -> V_34 = F_20 ( V_50 ) ;
memcpy ( V_25 , V_60 , V_50 ) ;
F_21 ( & V_12 -> V_67 ) ;
V_17 = F_11 ( V_9 , V_11 , V_51 ) ;
F_22 ( & V_12 -> V_67 ) ;
if ( V_17 < 0 ) {
ERROR ( V_12 -> V_4 . V_5 . V_16 -> V_15 ,
L_10 ,
V_12 -> V_20 , V_17 ) ;
V_12 -> V_63 = V_11 ;
}
return V_17 ;
}
static int F_23 ( struct V_1 * V_12 )
{
struct V_14 * V_15 = V_12 -> V_4 . V_5 . V_16 -> V_15 ;
int V_17 ;
F_22 ( & V_12 -> V_67 ) ;
if ( V_12 -> V_63 ) {
F_5 ( & V_15 -> V_18 -> V_19 , L_11 ,
V_12 -> V_20 , V_12 -> V_68 ) ;
V_17 = F_19 ( V_12 , V_69 ,
0 , & V_12 -> V_68 , sizeof( V_12 -> V_68 ) ) ;
} else {
V_12 -> V_64 = true ;
V_17 = 0 ;
}
F_21 ( & V_12 -> V_67 ) ;
return V_17 ;
}
static void F_24 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_1 * V_12 = V_11 -> V_70 ;
T_2 V_71 = false ;
F_22 ( & V_12 -> V_67 ) ;
if ( V_11 -> V_17 != - V_72 )
V_71 = V_12 -> V_64 ;
V_12 -> V_63 = V_11 ;
F_21 ( & V_12 -> V_67 ) ;
if ( V_71 )
F_23 ( V_12 ) ;
}
static void F_25 ( struct V_6 * V_4 )
{
struct V_1 * V_12 = F_3 ( V_4 ) ;
V_12 -> V_68 |= V_73 | V_74 ;
F_23 ( V_12 ) ;
}
static void F_26 ( struct V_6 * V_4 )
{
struct V_1 * V_12 = F_3 ( V_4 ) ;
V_12 -> V_68 &= ~ ( V_73 | V_74 ) ;
F_23 ( V_12 ) ;
}
static int F_27 ( struct V_6 * V_4 , int V_75 )
{
struct V_1 * V_12 = F_3 ( V_4 ) ;
T_1 V_76 ;
V_76 = V_12 -> V_68 ;
V_76 &= ~ V_77 ;
if ( V_75 )
V_76 |= V_77 ;
V_12 -> V_68 = V_76 ;
return F_23 ( V_12 ) ;
}
static int
F_28 ( struct V_78 * V_79 , struct V_2 * V_3 )
{
struct V_14 * V_15 = V_79 -> V_15 ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_80 * V_81 ;
int V_17 ;
struct V_8 * V_9 ;
V_81 = F_29 ( V_15 , V_82 ,
F_30 ( V_83 ) ) ;
if ( F_31 ( V_81 ) )
return F_32 ( V_81 ) ;
V_84 . V_85 = V_81 [ V_86 ] . V_87 ;
V_88 . V_85 = V_81 [ V_89 ] . V_87 ;
V_90 . V_91 = V_81 [ V_92 ] . V_87 ;
V_17 = F_33 ( V_79 , V_3 ) ;
if ( V_17 < 0 )
goto V_93;
V_12 -> V_41 = V_17 ;
V_90 . V_94 = V_17 ;
V_84 . V_95 = V_17 ;
V_96 . V_97 = V_17 ;
V_17 = F_33 ( V_79 , V_3 ) ;
if ( V_17 < 0 )
goto V_93;
V_12 -> V_57 = V_17 ;
V_88 . V_95 = V_17 ;
V_96 . V_98 = V_17 ;
V_99 . V_100 = V_17 ;
V_17 = - V_101 ;
V_9 = F_34 ( V_15 -> V_18 , & V_102 ) ;
if ( ! V_9 )
goto V_93;
V_12 -> V_4 . V_58 = V_9 ;
V_9 -> V_13 = V_15 ;
V_9 = F_34 ( V_15 -> V_18 , & V_103 ) ;
if ( ! V_9 )
goto V_93;
V_12 -> V_4 . V_59 = V_9 ;
V_9 -> V_13 = V_15 ;
V_9 = F_34 ( V_15 -> V_18 , & V_104 ) ;
if ( ! V_9 )
goto V_93;
V_12 -> V_54 = V_9 ;
V_9 -> V_13 = V_15 ;
V_12 -> V_63 = F_35 ( V_9 ,
sizeof( struct V_61 ) + 2 ,
V_105 ) ;
if ( ! V_12 -> V_63 )
goto V_93;
V_12 -> V_63 -> V_44 = F_24 ;
V_12 -> V_63 -> V_70 = V_12 ;
V_106 . V_107 = V_102 . V_107 ;
V_108 . V_107 = V_103 . V_107 ;
V_109 . V_107 =
V_104 . V_107 ;
V_110 . V_107 = V_102 . V_107 ;
V_111 . V_107 = V_103 . V_107 ;
V_17 = F_36 ( V_3 , V_112 , V_113 ,
V_114 ) ;
if ( V_17 )
goto V_93;
F_5 ( & V_15 -> V_18 -> V_19 ,
L_12 ,
V_12 -> V_20 ,
F_37 ( V_79 -> V_15 -> V_18 ) ? L_13 :
F_38 ( V_79 -> V_15 -> V_18 ) ? L_14 : L_15 ,
V_12 -> V_4 . V_58 -> V_115 , V_12 -> V_4 . V_59 -> V_115 ,
V_12 -> V_54 -> V_115 ) ;
return 0 ;
V_93:
if ( V_12 -> V_63 )
F_39 ( V_12 -> V_54 , V_12 -> V_63 ) ;
if ( V_12 -> V_54 )
V_12 -> V_54 -> V_13 = NULL ;
if ( V_12 -> V_4 . V_59 )
V_12 -> V_4 . V_59 -> V_13 = NULL ;
if ( V_12 -> V_4 . V_58 )
V_12 -> V_4 . V_58 -> V_13 = NULL ;
ERROR ( V_15 , L_16 , V_3 -> V_115 , V_3 , V_17 ) ;
return V_17 ;
}
static void F_40 ( struct V_78 * V_79 , struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
V_83 [ 0 ] . V_87 = 0 ;
F_41 ( V_3 ) ;
if ( V_12 -> V_63 )
F_39 ( V_12 -> V_54 , V_12 -> V_63 ) ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_43 ( V_12 ) ;
}
static struct V_2 * F_44 ( struct V_116 * V_117 )
{
struct V_118 * V_119 ;
struct V_1 * V_12 ;
V_12 = F_45 ( sizeof( * V_12 ) , V_105 ) ;
if ( ! V_12 )
return F_46 ( - V_120 ) ;
F_47 ( & V_12 -> V_67 ) ;
V_12 -> V_4 . V_121 = F_25 ;
V_12 -> V_4 . V_122 = F_26 ;
V_12 -> V_4 . V_123 = F_27 ;
V_12 -> V_4 . V_5 . V_115 = L_17 ;
V_12 -> V_4 . V_5 . V_124 = V_82 ;
V_12 -> V_4 . V_5 . V_125 = F_28 ;
V_12 -> V_4 . V_5 . V_126 = F_12 ;
V_12 -> V_4 . V_5 . V_127 = F_7 ;
V_12 -> V_4 . V_5 . V_128 = F_18 ;
V_119 = F_2 ( V_117 , struct V_118 , V_129 ) ;
V_12 -> V_20 = V_119 -> V_20 ;
V_12 -> V_4 . V_5 . V_130 = F_40 ;
V_12 -> V_4 . V_5 . V_131 = F_42 ;
return & V_12 -> V_4 . V_5 ;
}
static inline struct V_118 * F_48 ( struct V_132 * V_133 )
{
return F_2 ( F_49 ( V_133 ) , struct V_118 ,
V_129 . V_134 ) ;
}
static T_3 F_50 ( struct V_132 * V_133 ,
struct V_135 * V_136 ,
char * V_137 )
{
struct V_118 * V_119 = F_48 ( V_133 ) ;
struct V_138 * V_139 =
F_2 ( V_136 , struct V_138 , V_136 ) ;
T_3 V_140 = 0 ;
if ( V_139 -> V_141 )
V_140 = V_139 -> V_141 ( V_119 , V_137 ) ;
return V_140 ;
}
static void F_51 ( struct V_132 * V_133 )
{
struct V_118 * V_119 = F_48 ( V_133 ) ;
F_52 ( & V_119 -> V_129 ) ;
}
static T_3 F_53 ( struct V_118 * V_119 , char * V_137 )
{
return sprintf ( V_137 , L_18 , V_119 -> V_20 ) ;
}
static void F_54 ( struct V_116 * V_117 )
{
struct V_118 * V_119 ;
V_119 = F_2 ( V_117 , struct V_118 , V_129 ) ;
F_55 ( V_119 -> V_20 ) ;
F_43 ( V_119 ) ;
}
static struct V_116 * F_56 ( void )
{
struct V_118 * V_119 ;
int V_140 ;
V_119 = F_45 ( sizeof( * V_119 ) , V_105 ) ;
if ( ! V_119 )
return F_46 ( - V_120 ) ;
V_119 -> V_129 . V_142 = F_54 ;
V_140 = F_57 ( & V_119 -> V_20 ) ;
if ( V_140 ) {
F_43 ( V_119 ) ;
return F_46 ( V_140 ) ;
}
F_58 ( & V_119 -> V_129 . V_134 , L_19 ,
& V_143 ) ;
return & V_119 -> V_129 ;
}
