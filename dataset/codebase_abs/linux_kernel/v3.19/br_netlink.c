static inline T_1 F_1 ( void )
{
return F_2 ( 1 )
+ F_2 ( 2 )
+ F_2 ( 4 )
+ F_2 ( 1 )
+ F_2 ( 1 )
+ F_2 ( 1 )
+ F_2 ( 1 )
+ F_2 ( 1 )
+ F_2 ( 1 )
+ 0 ;
}
static inline T_1 F_3 ( void )
{
return F_4 ( sizeof( struct V_1 ) )
+ F_2 ( V_2 )
+ F_2 ( V_3 )
+ F_2 ( 4 )
+ F_2 ( 4 )
+ F_2 ( 4 )
+ F_2 ( 1 )
+ F_2 ( F_1 () ) ;
}
static int F_5 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
T_2 V_8 = ! ! ( V_7 -> V_9 & V_10 ) ;
if ( F_6 ( V_5 , V_11 , V_7 -> V_12 ) ||
F_7 ( V_5 , V_13 , V_7 -> V_14 ) ||
F_8 ( V_5 , V_15 , V_7 -> V_16 ) ||
F_6 ( V_5 , V_17 , V_8 ) ||
F_6 ( V_5 , V_18 , ! ! ( V_7 -> V_9 & V_19 ) ) ||
F_6 ( V_5 , V_20 , ! ! ( V_7 -> V_9 & V_21 ) ) ||
F_6 ( V_5 , V_22 , ! ! ( V_7 -> V_9 & V_23 ) ) ||
F_6 ( V_5 , V_24 , ! ! ( V_7 -> V_9 & V_25 ) ) ||
F_6 ( V_5 , V_26 , ! ! ( V_7 -> V_9 & V_27 ) ) ||
F_6 ( V_5 , V_28 , ! ! ( V_7 -> V_9 & V_29 ) ) )
return - V_30 ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 ,
const struct V_6 * V_31 ,
T_3 V_32 , T_3 V_33 , int V_34 , unsigned int V_9 ,
T_3 V_35 , const struct V_36 * V_37 )
{
const struct V_38 * V_39 ;
struct V_1 * V_40 ;
struct V_41 * V_42 ;
T_2 V_43 = F_10 ( V_37 ) ? V_37 -> V_43 : V_44 ;
if ( V_31 )
V_39 = V_31 -> V_39 ;
else
V_39 = F_11 ( V_37 ) ;
F_12 ( V_39 , L_1 ,
V_34 , V_37 -> V_45 , V_39 -> V_37 -> V_45 ) ;
V_42 = F_13 ( V_5 , V_32 , V_33 , V_34 , sizeof( * V_40 ) , V_9 ) ;
if ( V_42 == NULL )
return - V_30 ;
V_40 = F_14 ( V_42 ) ;
V_40 -> V_46 = V_47 ;
V_40 -> V_48 = 0 ;
V_40 -> V_49 = V_37 -> type ;
V_40 -> V_50 = V_37 -> V_51 ;
V_40 -> V_52 = F_15 ( V_37 ) ;
V_40 -> V_53 = 0 ;
if ( F_16 ( V_5 , V_54 , V_37 -> V_45 ) ||
F_8 ( V_5 , V_55 , V_39 -> V_37 -> V_51 ) ||
F_8 ( V_5 , V_56 , V_37 -> V_57 ) ||
F_6 ( V_5 , V_58 , V_43 ) ||
( V_37 -> V_59 &&
F_17 ( V_5 , V_60 , V_37 -> V_59 , V_37 -> V_61 ) ) ||
( V_37 -> V_51 != V_37 -> V_62 &&
F_8 ( V_5 , V_63 , V_37 -> V_62 ) ) )
goto V_64;
if ( V_34 == V_65 && V_31 ) {
struct V_66 * V_67
= F_18 ( V_5 , V_68 | V_69 ) ;
if ( V_67 == NULL || F_5 ( V_5 , V_31 ) < 0 )
goto V_64;
F_19 ( V_5 , V_67 ) ;
}
if ( V_35 & V_70 ) {
struct V_66 * V_71 ;
const struct V_72 * V_73 ;
struct V_74 V_75 ;
T_4 V_76 ;
T_4 V_77 ;
if ( V_31 )
V_73 = F_20 ( V_31 ) ;
else
V_73 = F_21 ( V_39 ) ;
if ( ! V_73 || F_22 ( V_73 -> V_78 , V_79 ) )
goto V_80;
V_71 = F_18 ( V_5 , V_81 ) ;
if ( ! V_71 )
goto V_64;
V_77 = F_23 ( V_73 ) ;
F_24 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_75 . V_76 = V_76 ;
V_75 . V_9 = 0 ;
if ( V_76 == V_77 )
V_75 . V_9 |= V_82 ;
if ( F_25 ( V_76 , V_73 -> V_83 ) )
V_75 . V_9 |= V_84 ;
if ( F_17 ( V_5 , V_85 ,
sizeof( V_75 ) , & V_75 ) )
goto V_64;
}
F_19 ( V_5 , V_71 ) ;
}
V_80:
return F_26 ( V_5 , V_42 ) ;
V_64:
F_27 ( V_5 , V_42 ) ;
return - V_30 ;
}
void F_28 ( int V_34 , struct V_6 * V_31 )
{
struct V_86 * V_86 ;
struct V_4 * V_5 ;
int V_87 = - V_88 ;
if ( ! V_31 )
return;
V_86 = F_29 ( V_31 -> V_37 ) ;
F_12 ( V_31 -> V_39 , L_2 ,
( unsigned int ) V_31 -> V_89 , V_31 -> V_37 -> V_45 , V_34 ) ;
V_5 = F_30 ( F_3 () , V_90 ) ;
if ( V_5 == NULL )
goto V_91;
V_87 = F_9 ( V_5 , V_31 , 0 , 0 , V_34 , 0 , 0 , V_31 -> V_37 ) ;
if ( V_87 < 0 ) {
F_31 ( V_87 == - V_30 ) ;
F_32 ( V_5 ) ;
goto V_91;
}
F_33 ( V_5 , V_86 , 0 , V_92 , NULL , V_90 ) ;
return;
V_91:
F_34 ( V_86 , V_92 , V_87 ) ;
}
int F_35 ( struct V_4 * V_5 , T_3 V_32 , T_3 V_33 ,
struct V_36 * V_37 , T_3 V_35 )
{
int V_87 = 0 ;
struct V_6 * V_31 = F_36 ( V_37 ) ;
if ( ! V_31 && ! ( V_35 & V_70 ) )
goto V_93;
V_87 = F_9 ( V_5 , V_31 , V_32 , V_33 , V_65 , V_94 ,
V_35 , V_37 ) ;
V_93:
return V_87 ;
}
static int F_37 ( struct V_38 * V_39 ,
struct V_6 * V_7 ,
struct V_66 * V_95 ,
int V_96 )
{
struct V_66 * V_97 [ V_98 + 1 ] ;
int V_87 = 0 ;
V_87 = F_38 ( V_97 , V_98 , V_95 , V_99 ) ;
if ( V_87 )
return V_87 ;
if ( V_97 [ V_85 ] ) {
struct V_74 * V_75 ;
V_75 = F_39 ( V_97 [ V_85 ] ) ;
if ( ! V_75 -> V_76 || V_75 -> V_76 >= V_100 )
return - V_101 ;
switch ( V_96 ) {
case V_102 :
if ( V_7 ) {
V_87 = F_40 ( V_7 , V_75 -> V_76 , V_75 -> V_9 ) ;
if ( V_87 )
break;
if ( V_75 -> V_9 & V_103 )
V_87 = F_41 ( V_7 -> V_39 , V_75 -> V_76 ,
V_75 -> V_9 ) ;
} else
V_87 = F_41 ( V_39 , V_75 -> V_76 , V_75 -> V_9 ) ;
break;
case V_104 :
if ( V_7 ) {
F_42 ( V_7 , V_75 -> V_76 ) ;
if ( V_75 -> V_9 & V_103 )
F_43 ( V_7 -> V_39 , V_75 -> V_76 ) ;
} else
F_43 ( V_39 , V_75 -> V_76 ) ;
break;
}
}
return V_87 ;
}
static int F_44 ( struct V_6 * V_7 , T_2 V_12 )
{
if ( V_12 > V_105 )
return - V_101 ;
if ( V_7 -> V_39 -> V_106 == V_107 )
return - V_108 ;
if ( ! F_10 ( V_7 -> V_37 ) ||
( ! F_45 ( V_7 -> V_37 ) && V_12 != V_109 ) )
return - V_110 ;
F_46 ( V_7 , V_12 ) ;
F_47 ( V_7 ) ;
F_48 ( V_7 -> V_39 ) ;
return 0 ;
}
static void F_49 ( struct V_6 * V_7 , struct V_66 * V_97 [] ,
int V_111 , unsigned long V_112 )
{
if ( V_97 [ V_111 ] ) {
T_2 V_113 = F_50 ( V_97 [ V_111 ] ) ;
if ( V_113 )
V_7 -> V_9 |= V_112 ;
else
V_7 -> V_9 &= ~ V_112 ;
}
}
static int F_51 ( struct V_6 * V_7 , struct V_66 * V_97 [] )
{
int V_87 ;
unsigned long V_114 = V_7 -> V_9 ;
F_49 ( V_7 , V_97 , V_17 , V_10 ) ;
F_49 ( V_7 , V_97 , V_18 , V_19 ) ;
F_49 ( V_7 , V_97 , V_22 , V_23 ) ;
F_49 ( V_7 , V_97 , V_20 , V_21 ) ;
F_49 ( V_7 , V_97 , V_24 , V_25 ) ;
F_49 ( V_7 , V_97 , V_26 , V_27 ) ;
F_49 ( V_7 , V_97 , V_28 , V_29 ) ;
if ( V_97 [ V_15 ] ) {
V_87 = F_52 ( V_7 , F_53 ( V_97 [ V_15 ] ) ) ;
if ( V_87 )
return V_87 ;
}
if ( V_97 [ V_13 ] ) {
V_87 = F_54 ( V_7 , F_55 ( V_97 [ V_13 ] ) ) ;
if ( V_87 )
return V_87 ;
}
if ( V_97 [ V_11 ] ) {
V_87 = F_44 ( V_7 , F_50 ( V_97 [ V_11 ] ) ) ;
if ( V_87 )
return V_87 ;
}
F_56 ( V_7 , V_114 ^ V_7 -> V_9 ) ;
return 0 ;
}
int F_57 ( struct V_36 * V_37 , struct V_41 * V_42 )
{
struct V_66 * V_115 ;
struct V_66 * V_116 ;
struct V_6 * V_7 ;
struct V_66 * V_97 [ V_117 + 1 ] ;
int V_87 = 0 ;
V_115 = F_58 ( V_42 , sizeof( struct V_1 ) , V_68 ) ;
V_116 = F_58 ( V_42 , sizeof( struct V_1 ) , V_81 ) ;
if ( ! V_115 && ! V_116 )
return 0 ;
V_7 = F_36 ( V_37 ) ;
if ( ! V_7 && ! V_116 )
return - V_101 ;
if ( V_7 && V_115 ) {
if ( V_115 -> V_118 & V_69 ) {
V_87 = F_38 ( V_97 , V_117 ,
V_115 , V_119 ) ;
if ( V_87 )
return V_87 ;
F_59 ( & V_7 -> V_39 -> V_120 ) ;
V_87 = F_51 ( V_7 , V_97 ) ;
F_60 ( & V_7 -> V_39 -> V_120 ) ;
} else {
if ( F_61 ( V_115 ) < sizeof( T_2 ) )
return - V_101 ;
F_59 ( & V_7 -> V_39 -> V_120 ) ;
V_87 = F_44 ( V_7 , F_50 ( V_115 ) ) ;
F_60 ( & V_7 -> V_39 -> V_120 ) ;
}
if ( V_87 )
goto V_93;
}
if ( V_116 ) {
V_87 = F_37 ( (struct V_38 * ) F_11 ( V_37 ) , V_7 ,
V_116 , V_102 ) ;
}
if ( V_87 == 0 )
F_28 ( V_65 , V_7 ) ;
V_93:
return V_87 ;
}
int F_62 ( struct V_36 * V_37 , struct V_41 * V_42 )
{
struct V_66 * V_116 ;
struct V_6 * V_7 ;
int V_87 ;
V_116 = F_58 ( V_42 , sizeof( struct V_1 ) , V_81 ) ;
if ( ! V_116 )
return 0 ;
V_7 = F_36 ( V_37 ) ;
if ( ! V_7 && ! ( V_37 -> V_121 & V_122 ) )
return - V_101 ;
V_87 = F_37 ( (struct V_38 * ) F_11 ( V_37 ) , V_7 ,
V_116 , V_104 ) ;
return V_87 ;
}
static int F_63 ( struct V_66 * V_97 [] , struct V_66 * V_123 [] )
{
if ( V_97 [ V_60 ] ) {
if ( F_61 ( V_97 [ V_60 ] ) != V_124 )
return - V_101 ;
if ( ! F_64 ( F_39 ( V_97 [ V_60 ] ) ) )
return - V_125 ;
}
return 0 ;
}
static int F_65 ( struct V_86 * V_126 , struct V_36 * V_37 ,
struct V_66 * V_97 [] , struct V_66 * V_123 [] )
{
struct V_38 * V_39 = F_11 ( V_37 ) ;
if ( V_97 [ V_60 ] ) {
F_59 ( & V_39 -> V_120 ) ;
F_66 ( V_39 , F_39 ( V_97 [ V_60 ] ) ) ;
F_60 ( & V_39 -> V_120 ) ;
}
return F_67 ( V_37 ) ;
}
static int F_68 ( struct V_36 * V_127 ,
struct V_36 * V_37 ,
struct V_66 * V_97 [] ,
struct V_66 * V_123 [] )
{
if ( ! V_123 )
return 0 ;
return F_51 ( F_36 ( V_37 ) , V_123 ) ;
}
static int F_69 ( struct V_4 * V_5 ,
const struct V_36 * V_127 ,
const struct V_36 * V_37 )
{
return F_5 ( V_5 , F_36 ( V_37 ) ) ;
}
static T_1 F_70 ( const struct V_36 * V_127 ,
const struct V_36 * V_37 )
{
return F_1 () ;
}
static int F_71 ( struct V_36 * V_127 , struct V_66 * V_97 [] ,
struct V_66 * V_123 [] )
{
struct V_38 * V_39 = F_11 ( V_127 ) ;
int V_87 ;
if ( ! V_123 )
return 0 ;
if ( V_123 [ V_128 ] ) {
V_87 = F_72 ( V_39 , F_53 ( V_123 [ V_128 ] ) ) ;
if ( V_87 )
return V_87 ;
}
if ( V_123 [ V_129 ] ) {
V_87 = F_73 ( V_39 , F_53 ( V_123 [ V_129 ] ) ) ;
if ( V_87 )
return V_87 ;
}
if ( V_123 [ V_130 ] ) {
V_87 = F_74 ( V_39 , F_53 ( V_123 [ V_130 ] ) ) ;
if ( V_87 )
return V_87 ;
}
return 0 ;
}
static T_1 F_75 ( const struct V_36 * V_127 )
{
return F_2 ( sizeof( T_3 ) ) +
F_2 ( sizeof( T_3 ) ) +
F_2 ( sizeof( T_3 ) ) +
0 ;
}
static int F_76 ( struct V_4 * V_5 , const struct V_36 * V_127 )
{
struct V_38 * V_39 = F_11 ( V_127 ) ;
T_3 V_131 = F_77 ( V_39 -> V_131 ) ;
T_3 V_132 = F_77 ( V_39 -> V_132 ) ;
T_3 V_133 = F_77 ( V_39 -> V_134 ) ;
if ( F_8 ( V_5 , V_128 , V_131 ) ||
F_8 ( V_5 , V_129 , V_132 ) ||
F_8 ( V_5 , V_130 , V_133 ) )
return - V_30 ;
return 0 ;
}
static T_1 F_78 ( const struct V_36 * V_37 )
{
struct V_72 * V_73 ;
if ( F_79 ( V_37 ) )
V_73 = F_20 ( F_36 ( V_37 ) ) ;
else if ( V_37 -> V_121 & V_122 )
V_73 = F_21 ( (struct V_38 * ) F_11 ( V_37 ) ) ;
else
return 0 ;
if ( ! V_73 )
return 0 ;
return V_73 -> V_135 * F_2 ( sizeof( struct V_74 ) ) ;
}
int T_5 F_80 ( void )
{
int V_87 ;
F_81 () ;
F_82 ( & V_136 ) ;
V_87 = F_83 ( & V_137 ) ;
if ( V_87 )
goto V_138;
return 0 ;
V_138:
F_84 ( & V_136 ) ;
F_85 () ;
return V_87 ;
}
void F_86 ( void )
{
F_85 () ;
F_84 ( & V_136 ) ;
F_87 ( & V_137 ) ;
}
