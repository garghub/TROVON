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
F_5 ( V_15 , L_1 ,
V_12 -> V_18 , V_11 -> V_17 ) ;
return;
}
if ( V_11 -> V_19 != sizeof( V_12 -> V_20 ) ) {
F_5 ( V_15 , L_2 ,
V_12 -> V_18 , V_11 -> V_19 ) ;
F_6 ( V_9 ) ;
} else {
struct V_21 * V_22 = V_11 -> V_23 ;
V_12 -> V_20 = * V_22 ;
}
}
static int F_7 ( struct V_2 * V_3 , const struct V_24 * V_25 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_3 -> V_16 -> V_15 ;
struct V_10 * V_11 = V_15 -> V_11 ;
int V_22 = - V_26 ;
T_1 V_27 = F_8 ( V_25 -> V_28 ) ;
T_1 V_29 = F_8 ( V_25 -> V_30 ) ;
T_1 V_31 = F_8 ( V_25 -> V_32 ) ;
switch ( ( V_25 -> V_33 << 8 ) | V_25 -> V_34 ) {
case ( ( V_35 | V_36 | V_37 ) << 8 )
| V_38 :
if ( V_31 != sizeof( struct V_21 )
|| V_27 != V_12 -> V_39 )
goto V_40;
V_22 = V_31 ;
V_15 -> V_41 -> V_42 -> V_13 = V_12 ;
V_11 -> V_43 = F_4 ;
break;
case ( ( V_44 | V_36 | V_37 ) << 8 )
| V_45 :
if ( V_27 != V_12 -> V_39 )
goto V_40;
V_22 = F_9 ( unsigned , V_31 ,
sizeof( struct V_21 ) ) ;
memcpy ( V_11 -> V_23 , & V_12 -> V_20 , V_22 ) ;
break;
case ( ( V_35 | V_36 | V_37 ) << 8 )
| V_46 :
if ( V_27 != V_12 -> V_39 )
goto V_40;
V_22 = 0 ;
V_12 -> V_47 = V_29 ;
break;
default:
V_40:
F_10 ( V_15 , L_3 ,
V_25 -> V_33 , V_25 -> V_34 ,
V_29 , V_27 , V_31 ) ;
}
if ( V_22 >= 0 ) {
F_5 ( V_15 , L_4 ,
V_12 -> V_18 , V_25 -> V_33 , V_25 -> V_34 ,
V_29 , V_27 , V_31 ) ;
V_11 -> V_48 = 0 ;
V_11 -> V_49 = V_22 ;
V_22 = F_11 ( V_15 -> V_41 -> V_42 , V_11 , V_50 ) ;
if ( V_22 < 0 )
ERROR ( V_15 , L_5 ,
V_12 -> V_18 , V_22 ) ;
}
return V_22 ;
}
static int F_12 ( struct V_2 * V_3 , unsigned V_51 , unsigned V_52 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_3 -> V_16 -> V_15 ;
if ( V_51 == V_12 -> V_39 ) {
if ( V_12 -> V_53 -> V_13 ) {
F_10 ( V_15 , L_6 , V_51 ) ;
F_13 ( V_12 -> V_53 ) ;
} else {
F_10 ( V_15 , L_7 , V_51 ) ;
if ( F_14 ( V_15 -> V_41 , V_3 , V_12 -> V_53 ) )
return - V_54 ;
}
F_15 ( V_12 -> V_53 ) ;
V_12 -> V_53 -> V_13 = V_12 ;
} else if ( V_51 == V_12 -> V_55 ) {
if ( V_12 -> V_4 . V_56 -> V_13 ) {
F_5 ( V_15 , L_8 , V_12 -> V_18 ) ;
F_16 ( & V_12 -> V_4 ) ;
}
if ( ! V_12 -> V_4 . V_56 -> V_57 || ! V_12 -> V_4 . V_58 -> V_57 ) {
F_5 ( V_15 , L_9 , V_12 -> V_18 ) ;
if ( F_14 ( V_15 -> V_41 , V_3 ,
V_12 -> V_4 . V_56 ) ||
F_14 ( V_15 -> V_41 , V_3 ,
V_12 -> V_4 . V_58 ) ) {
V_12 -> V_4 . V_56 -> V_57 = NULL ;
V_12 -> V_4 . V_58 -> V_57 = NULL ;
return - V_54 ;
}
}
F_17 ( & V_12 -> V_4 , V_12 -> V_18 ) ;
} else
return - V_54 ;
return 0 ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_3 -> V_16 -> V_15 ;
F_5 ( V_15 , L_10 , V_12 -> V_18 ) ;
F_16 ( & V_12 -> V_4 ) ;
F_13 ( V_12 -> V_53 ) ;
V_12 -> V_53 -> V_13 = NULL ;
}
static int F_19 ( struct V_1 * V_12 , T_2 type , T_1 V_22 ,
void * V_59 , unsigned V_49 )
{
struct V_8 * V_9 = V_12 -> V_53 ;
struct V_10 * V_11 ;
struct V_60 * V_53 ;
const unsigned V_61 = sizeof( * V_53 ) + V_49 ;
void * V_23 ;
int V_17 ;
V_11 = V_12 -> V_62 ;
V_12 -> V_62 = NULL ;
V_12 -> V_63 = false ;
V_11 -> V_49 = V_61 ;
V_53 = V_11 -> V_23 ;
V_23 = V_53 + 1 ;
V_53 -> V_64 = V_44 | V_36
| V_37 ;
V_53 -> V_65 = type ;
V_53 -> V_30 = F_20 ( V_22 ) ;
V_53 -> V_28 = F_20 ( V_12 -> V_39 ) ;
V_53 -> V_32 = F_20 ( V_49 ) ;
memcpy ( V_23 , V_59 , V_49 ) ;
F_21 ( & V_12 -> V_66 ) ;
V_17 = F_11 ( V_9 , V_11 , V_50 ) ;
F_22 ( & V_12 -> V_66 ) ;
if ( V_17 < 0 ) {
ERROR ( V_12 -> V_4 . V_5 . V_16 -> V_15 ,
L_11 ,
V_12 -> V_18 , V_17 ) ;
V_12 -> V_62 = V_11 ;
}
return V_17 ;
}
static int F_23 ( struct V_1 * V_12 )
{
struct V_14 * V_15 = V_12 -> V_4 . V_5 . V_16 -> V_15 ;
int V_17 ;
F_22 ( & V_12 -> V_66 ) ;
if ( V_12 -> V_62 ) {
F_5 ( V_15 , L_12 ,
V_12 -> V_18 , V_12 -> V_67 ) ;
V_17 = F_19 ( V_12 , V_68 ,
0 , & V_12 -> V_67 , sizeof( V_12 -> V_67 ) ) ;
} else {
V_12 -> V_63 = true ;
V_17 = 0 ;
}
F_21 ( & V_12 -> V_66 ) ;
return V_17 ;
}
static void F_24 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_1 * V_12 = V_11 -> V_69 ;
T_2 V_70 = false ;
F_22 ( & V_12 -> V_66 ) ;
if ( V_11 -> V_17 != - V_71 )
V_70 = V_12 -> V_63 ;
V_12 -> V_62 = V_11 ;
F_21 ( & V_12 -> V_66 ) ;
if ( V_70 )
F_23 ( V_12 ) ;
}
static void F_25 ( struct V_6 * V_4 )
{
struct V_1 * V_12 = F_3 ( V_4 ) ;
V_12 -> V_67 |= V_72 | V_73 ;
F_23 ( V_12 ) ;
}
static void F_26 ( struct V_6 * V_4 )
{
struct V_1 * V_12 = F_3 ( V_4 ) ;
V_12 -> V_67 &= ~ ( V_72 | V_73 ) ;
F_23 ( V_12 ) ;
}
static int F_27 ( struct V_6 * V_4 , int V_74 )
{
struct V_1 * V_12 = F_3 ( V_4 ) ;
T_1 V_75 ;
V_75 = V_12 -> V_67 ;
V_75 &= ~ V_76 ;
if ( V_74 )
V_75 |= V_76 ;
V_12 -> V_67 = V_75 ;
return F_23 ( V_12 ) ;
}
static int
F_28 ( struct V_77 * V_78 , struct V_2 * V_3 )
{
struct V_14 * V_15 = V_78 -> V_15 ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_79 * V_80 ;
int V_17 ;
struct V_8 * V_9 ;
V_80 = F_29 ( V_15 , V_81 ,
F_30 ( V_82 ) ) ;
if ( F_31 ( V_80 ) )
return F_32 ( V_80 ) ;
V_83 . V_84 = V_80 [ V_85 ] . V_86 ;
V_87 . V_84 = V_80 [ V_88 ] . V_86 ;
V_89 . V_90 = V_80 [ V_91 ] . V_86 ;
V_17 = F_33 ( V_78 , V_3 ) ;
if ( V_17 < 0 )
goto V_92;
V_12 -> V_39 = V_17 ;
V_89 . V_93 = V_17 ;
V_83 . V_94 = V_17 ;
V_95 . V_96 = V_17 ;
V_17 = F_33 ( V_78 , V_3 ) ;
if ( V_17 < 0 )
goto V_92;
V_12 -> V_55 = V_17 ;
V_87 . V_94 = V_17 ;
V_95 . V_97 = V_17 ;
V_98 . V_99 = V_17 ;
V_17 = - V_100 ;
V_9 = F_34 ( V_15 -> V_41 , & V_101 ) ;
if ( ! V_9 )
goto V_92;
V_12 -> V_4 . V_56 = V_9 ;
V_9 -> V_13 = V_15 ;
V_9 = F_34 ( V_15 -> V_41 , & V_102 ) ;
if ( ! V_9 )
goto V_92;
V_12 -> V_4 . V_58 = V_9 ;
V_9 -> V_13 = V_15 ;
V_9 = F_34 ( V_15 -> V_41 , & V_103 ) ;
if ( ! V_9 )
goto V_92;
V_12 -> V_53 = V_9 ;
V_9 -> V_13 = V_15 ;
V_12 -> V_62 = F_35 ( V_9 ,
sizeof( struct V_60 ) + 2 ,
V_104 ) ;
if ( ! V_12 -> V_62 )
goto V_92;
V_12 -> V_62 -> V_43 = F_24 ;
V_12 -> V_62 -> V_69 = V_12 ;
V_105 . V_106 = V_101 . V_106 ;
V_107 . V_106 = V_102 . V_106 ;
V_108 . V_106 =
V_103 . V_106 ;
V_109 . V_106 = V_101 . V_106 ;
V_110 . V_106 = V_102 . V_106 ;
V_17 = F_36 ( V_3 , V_111 , V_112 ,
V_113 ) ;
if ( V_17 )
goto V_92;
F_5 ( V_15 , L_13 ,
V_12 -> V_18 ,
F_37 ( V_78 -> V_15 -> V_41 ) ? L_14 :
F_38 ( V_78 -> V_15 -> V_41 ) ? L_15 : L_16 ,
V_12 -> V_4 . V_56 -> V_114 , V_12 -> V_4 . V_58 -> V_114 ,
V_12 -> V_53 -> V_114 ) ;
return 0 ;
V_92:
if ( V_12 -> V_62 )
F_39 ( V_12 -> V_53 , V_12 -> V_62 ) ;
if ( V_12 -> V_53 )
V_12 -> V_53 -> V_13 = NULL ;
if ( V_12 -> V_4 . V_58 )
V_12 -> V_4 . V_58 -> V_13 = NULL ;
if ( V_12 -> V_4 . V_56 )
V_12 -> V_4 . V_56 -> V_13 = NULL ;
ERROR ( V_15 , L_17 , V_3 -> V_114 , V_3 , V_17 ) ;
return V_17 ;
}
static struct V_1 * F_40 ( void )
{
struct V_1 * V_12 ;
V_12 = F_41 ( sizeof( * V_12 ) , V_104 ) ;
if ( ! V_12 )
return NULL ;
F_42 ( & V_12 -> V_66 ) ;
V_12 -> V_4 . V_115 = F_25 ;
V_12 -> V_4 . V_116 = F_26 ;
V_12 -> V_4 . V_117 = F_27 ;
V_12 -> V_4 . V_5 . V_114 = L_18 ;
V_12 -> V_4 . V_5 . V_118 = F_28 ;
V_12 -> V_4 . V_5 . V_119 = F_12 ;
V_12 -> V_4 . V_5 . V_120 = F_7 ;
V_12 -> V_4 . V_5 . V_121 = F_18 ;
return V_12 ;
}
static void
F_43 ( struct V_77 * V_78 , struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_44 ( V_3 ) ;
if ( V_12 -> V_62 )
F_39 ( V_12 -> V_53 , V_12 -> V_62 ) ;
F_45 ( V_12 ) ;
}
int F_46 ( struct V_77 * V_78 , T_2 V_18 )
{
struct V_1 * V_12 ;
int V_17 ;
V_12 = F_40 () ;
if ( ! V_12 )
return - V_122 ;
V_12 -> V_18 = V_18 ;
V_12 -> V_4 . V_5 . V_123 = F_43 ;
V_17 = F_47 ( V_78 , & V_12 -> V_4 . V_5 ) ;
if ( V_17 )
F_45 ( V_12 ) ;
return V_17 ;
}
static void F_48 ( struct V_77 * V_78 , struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
V_82 [ 0 ] . V_86 = 0 ;
F_44 ( V_3 ) ;
if ( V_12 -> V_62 )
F_39 ( V_12 -> V_53 , V_12 -> V_62 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_45 ( V_12 ) ;
}
static struct V_2 * F_50 ( struct V_124 * V_125 )
{
struct V_126 * V_127 ;
struct V_1 * V_12 ;
V_12 = F_40 () ;
if ( ! V_12 )
return F_51 ( - V_122 ) ;
V_127 = F_2 ( V_125 , struct V_126 , V_128 ) ;
V_12 -> V_18 = V_127 -> V_18 ;
V_12 -> V_4 . V_5 . V_123 = F_48 ;
V_12 -> V_4 . V_5 . V_129 = F_49 ;
return & V_12 -> V_4 . V_5 ;
}
static void F_52 ( struct V_124 * V_125 )
{
struct V_126 * V_127 ;
V_127 = F_2 ( V_125 , struct V_126 , V_128 ) ;
F_45 ( V_127 ) ;
}
static struct V_124 * F_53 ( void )
{
struct V_126 * V_127 ;
V_127 = F_41 ( sizeof( * V_127 ) , V_104 ) ;
if ( ! V_127 )
return F_51 ( - V_122 ) ;
V_127 -> V_128 . V_130 = F_52 ;
return & V_127 -> V_128 ;
}
