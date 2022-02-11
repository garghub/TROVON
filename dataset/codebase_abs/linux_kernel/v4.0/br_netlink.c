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
static int F_9 ( struct V_4 * V_5 , T_3 V_31 ,
T_3 V_32 , T_3 V_9 )
{
struct V_33 V_34 ;
if ( ( V_32 - V_31 ) > 0 ) {
V_34 . V_35 = V_31 ;
V_34 . V_9 = V_9 | V_36 ;
if ( F_10 ( V_5 , V_37 ,
sizeof( V_34 ) , & V_34 ) )
goto V_38;
V_34 . V_9 &= ~ V_36 ;
V_34 . V_35 = V_32 ;
V_34 . V_9 = V_9 | V_39 ;
if ( F_10 ( V_5 , V_37 ,
sizeof( V_34 ) , & V_34 ) )
goto V_38;
} else {
V_34 . V_35 = V_31 ;
V_34 . V_9 = V_9 ;
if ( F_10 ( V_5 , V_37 ,
sizeof( V_34 ) , & V_34 ) )
goto V_38;
}
return 0 ;
V_38:
return - V_30 ;
}
static int F_11 ( struct V_4 * V_5 ,
const struct V_40 * V_41 )
{
T_3 V_42 = 0 , V_43 = 0 ;
T_3 V_44 = 0 ;
T_3 V_45 , V_35 , V_9 ;
int V_46 = 0 ;
V_45 = F_12 ( V_41 ) ;
F_13 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_9 = 0 ;
if ( V_35 == V_45 )
V_9 |= V_47 ;
if ( F_14 ( V_35 , V_41 -> V_48 ) )
V_9 |= V_49 ;
if ( V_42 == 0 ) {
goto V_50;
} else if ( ( V_35 - V_43 ) == 1 &&
V_9 == V_44 ) {
V_43 = V_35 ;
continue;
} else {
V_46 = F_9 ( V_5 , V_42 ,
V_43 ,
V_44 ) ;
if ( V_46 )
return V_46 ;
}
V_50:
V_42 = V_35 ;
V_43 = V_35 ;
V_44 = V_9 ;
}
if ( V_42 != 0 ) {
V_46 = F_9 ( V_5 , V_42 ,
V_43 ,
V_44 ) ;
if ( V_46 )
return V_46 ;
}
return 0 ;
}
static int F_15 ( struct V_4 * V_5 ,
const struct V_40 * V_41 )
{
struct V_33 V_34 ;
T_3 V_45 , V_35 ;
V_45 = F_12 ( V_41 ) ;
F_13 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_34 . V_35 = V_35 ;
V_34 . V_9 = 0 ;
if ( V_35 == V_45 )
V_34 . V_9 |= V_47 ;
if ( F_14 ( V_35 , V_41 -> V_48 ) )
V_34 . V_9 |= V_49 ;
if ( F_10 ( V_5 , V_37 ,
sizeof( V_34 ) , & V_34 ) )
goto V_38;
}
return 0 ;
V_38:
return - V_30 ;
}
static int F_16 ( struct V_4 * V_5 ,
const struct V_6 * V_51 ,
T_4 V_52 , T_4 V_53 , int V_54 , unsigned int V_9 ,
T_4 V_55 , const struct V_56 * V_57 )
{
const struct V_58 * V_59 ;
struct V_1 * V_60 ;
struct V_61 * V_62 ;
T_2 V_63 = F_17 ( V_57 ) ? V_57 -> V_63 : V_64 ;
if ( V_51 )
V_59 = V_51 -> V_59 ;
else
V_59 = F_18 ( V_57 ) ;
F_19 ( V_59 , L_1 ,
V_54 , V_57 -> V_65 , V_59 -> V_57 -> V_65 ) ;
V_62 = F_20 ( V_5 , V_52 , V_53 , V_54 , sizeof( * V_60 ) , V_9 ) ;
if ( V_62 == NULL )
return - V_30 ;
V_60 = F_21 ( V_62 ) ;
V_60 -> V_66 = V_67 ;
V_60 -> V_68 = 0 ;
V_60 -> V_69 = V_57 -> type ;
V_60 -> V_70 = V_57 -> V_71 ;
V_60 -> V_72 = F_22 ( V_57 ) ;
V_60 -> V_73 = 0 ;
if ( F_23 ( V_5 , V_74 , V_57 -> V_65 ) ||
F_8 ( V_5 , V_75 , V_59 -> V_57 -> V_71 ) ||
F_8 ( V_5 , V_76 , V_57 -> V_77 ) ||
F_6 ( V_5 , V_78 , V_63 ) ||
( V_57 -> V_79 &&
F_10 ( V_5 , V_80 , V_57 -> V_79 , V_57 -> V_81 ) ) ||
( V_57 -> V_71 != V_57 -> V_82 &&
F_8 ( V_5 , V_83 , V_57 -> V_82 ) ) )
goto V_38;
if ( V_54 == V_84 && V_51 ) {
struct V_85 * V_86
= F_24 ( V_5 , V_87 | V_88 ) ;
if ( V_86 == NULL || F_5 ( V_5 , V_51 ) < 0 )
goto V_38;
F_25 ( V_5 , V_86 ) ;
}
if ( ( V_55 & V_89 ) ||
( V_55 & V_90 ) ) {
const struct V_40 * V_41 ;
struct V_85 * V_91 ;
int V_46 ;
if ( V_51 )
V_41 = F_26 ( V_51 ) ;
else
V_41 = F_27 ( V_59 ) ;
if ( ! V_41 || F_28 ( V_41 -> V_92 , V_93 ) )
goto V_94;
V_91 = F_24 ( V_5 , V_95 ) ;
if ( ! V_91 )
goto V_38;
if ( V_55 & V_90 )
V_46 = F_11 ( V_5 , V_41 ) ;
else
V_46 = F_15 ( V_5 , V_41 ) ;
if ( V_46 )
goto V_38;
F_25 ( V_5 , V_91 ) ;
}
V_94:
F_29 ( V_5 , V_62 ) ;
return 0 ;
V_38:
F_30 ( V_5 , V_62 ) ;
return - V_30 ;
}
void F_31 ( int V_54 , struct V_6 * V_51 )
{
struct V_96 * V_96 ;
struct V_4 * V_5 ;
int V_46 = - V_97 ;
if ( ! V_51 )
return;
V_96 = F_32 ( V_51 -> V_57 ) ;
F_19 ( V_51 -> V_59 , L_2 ,
( unsigned int ) V_51 -> V_98 , V_51 -> V_57 -> V_65 , V_54 ) ;
V_5 = F_33 ( F_3 () , V_99 ) ;
if ( V_5 == NULL )
goto V_100;
V_46 = F_16 ( V_5 , V_51 , 0 , 0 , V_54 , 0 , 0 , V_51 -> V_57 ) ;
if ( V_46 < 0 ) {
F_34 ( V_46 == - V_30 ) ;
F_35 ( V_5 ) ;
goto V_100;
}
F_36 ( V_5 , V_96 , 0 , V_101 , NULL , V_99 ) ;
return;
V_100:
F_37 ( V_96 , V_101 , V_46 ) ;
}
int F_38 ( struct V_4 * V_5 , T_4 V_52 , T_4 V_53 ,
struct V_56 * V_57 , T_4 V_55 )
{
struct V_6 * V_51 = F_39 ( V_57 ) ;
if ( ! V_51 && ! ( V_55 & V_89 ) &&
! ( V_55 & V_90 ) )
return 0 ;
return F_16 ( V_5 , V_51 , V_52 , V_53 , V_84 , V_102 ,
V_55 , V_57 ) ;
}
static int F_40 ( struct V_58 * V_59 , struct V_6 * V_7 ,
int V_103 , struct V_33 * V_34 )
{
int V_46 = 0 ;
switch ( V_103 ) {
case V_104 :
if ( V_7 ) {
V_46 = F_41 ( V_7 , V_34 -> V_35 , V_34 -> V_9 ) ;
if ( V_46 )
break;
if ( V_34 -> V_9 & V_105 )
V_46 = F_42 ( V_7 -> V_59 , V_34 -> V_35 ,
V_34 -> V_9 ) ;
} else {
V_46 = F_42 ( V_59 , V_34 -> V_35 , V_34 -> V_9 ) ;
}
break;
case V_106 :
if ( V_7 ) {
F_43 ( V_7 , V_34 -> V_35 ) ;
if ( V_34 -> V_9 & V_105 )
F_44 ( V_7 -> V_59 , V_34 -> V_35 ) ;
} else {
F_44 ( V_59 , V_34 -> V_35 ) ;
}
break;
}
return V_46 ;
}
static int F_45 ( struct V_58 * V_59 ,
struct V_6 * V_7 ,
struct V_85 * V_107 ,
int V_103 )
{
struct V_33 * V_108 = NULL ;
struct V_33 * V_34 = NULL ;
struct V_85 * V_109 ;
int V_46 = 0 ;
int V_110 ;
F_46 (attr, af_spec, rem) {
if ( F_47 ( V_109 ) != V_37 )
continue;
if ( F_48 ( V_109 ) != sizeof( struct V_33 ) )
return - V_111 ;
V_34 = F_49 ( V_109 ) ;
if ( V_34 -> V_9 & V_36 ) {
if ( V_108 )
return - V_111 ;
V_108 = V_34 ;
continue;
}
if ( V_108 ) {
struct V_33 V_112 ;
int V_113 ;
if ( ! ( V_34 -> V_9 & V_39 ) )
return - V_111 ;
if ( V_34 -> V_35 <= V_108 -> V_35 )
return - V_111 ;
memcpy ( & V_112 , V_108 ,
sizeof( struct V_33 ) ) ;
for ( V_113 = V_108 -> V_35 ; V_113 <= V_34 -> V_35 ; V_113 ++ ) {
V_112 . V_35 = V_113 ;
V_46 = F_40 ( V_59 , V_7 , V_103 , & V_112 ) ;
if ( V_46 )
break;
}
V_108 = NULL ;
} else {
V_46 = F_40 ( V_59 , V_7 , V_103 , V_34 ) ;
}
if ( V_46 )
break;
}
return V_46 ;
}
static int F_50 ( struct V_6 * V_7 , T_2 V_12 )
{
if ( V_12 > V_114 )
return - V_111 ;
if ( V_7 -> V_59 -> V_115 == V_116 )
return - V_117 ;
if ( ! F_17 ( V_7 -> V_57 ) ||
( ! F_51 ( V_7 -> V_57 ) && V_12 != V_118 ) )
return - V_119 ;
F_52 ( V_7 , V_12 ) ;
F_53 ( V_7 ) ;
F_54 ( V_7 -> V_59 ) ;
return 0 ;
}
static void F_55 ( struct V_6 * V_7 , struct V_85 * V_120 [] ,
int V_121 , unsigned long V_122 )
{
if ( V_120 [ V_121 ] ) {
T_2 V_123 = F_56 ( V_120 [ V_121 ] ) ;
if ( V_123 )
V_7 -> V_9 |= V_122 ;
else
V_7 -> V_9 &= ~ V_122 ;
}
}
static int F_57 ( struct V_6 * V_7 , struct V_85 * V_120 [] )
{
int V_46 ;
unsigned long V_124 = V_7 -> V_9 ;
F_55 ( V_7 , V_120 , V_17 , V_10 ) ;
F_55 ( V_7 , V_120 , V_18 , V_19 ) ;
F_55 ( V_7 , V_120 , V_22 , V_23 ) ;
F_55 ( V_7 , V_120 , V_20 , V_21 ) ;
F_55 ( V_7 , V_120 , V_24 , V_25 ) ;
F_55 ( V_7 , V_120 , V_26 , V_27 ) ;
F_55 ( V_7 , V_120 , V_28 , V_29 ) ;
if ( V_120 [ V_15 ] ) {
V_46 = F_58 ( V_7 , F_59 ( V_120 [ V_15 ] ) ) ;
if ( V_46 )
return V_46 ;
}
if ( V_120 [ V_13 ] ) {
V_46 = F_60 ( V_7 , F_61 ( V_120 [ V_13 ] ) ) ;
if ( V_46 )
return V_46 ;
}
if ( V_120 [ V_11 ] ) {
V_46 = F_50 ( V_7 , F_56 ( V_120 [ V_11 ] ) ) ;
if ( V_46 )
return V_46 ;
}
F_62 ( V_7 , V_124 ^ V_7 -> V_9 ) ;
return 0 ;
}
int F_63 ( struct V_56 * V_57 , struct V_61 * V_62 , T_3 V_9 )
{
struct V_85 * V_125 ;
struct V_85 * V_126 ;
struct V_6 * V_7 ;
struct V_85 * V_120 [ V_127 + 1 ] ;
int V_46 = 0 , V_128 = 0 ;
V_125 = F_64 ( V_62 , sizeof( struct V_1 ) , V_87 ) ;
V_126 = F_64 ( V_62 , sizeof( struct V_1 ) , V_95 ) ;
if ( ! V_125 && ! V_126 )
return 0 ;
V_7 = F_39 ( V_57 ) ;
if ( ! V_7 && ! V_126 )
return - V_111 ;
if ( V_7 && V_125 ) {
if ( V_125 -> F_47 & V_88 ) {
V_46 = F_65 ( V_120 , V_127 ,
V_125 , V_129 ) ;
if ( V_46 )
return V_46 ;
F_66 ( & V_7 -> V_59 -> V_130 ) ;
V_46 = F_57 ( V_7 , V_120 ) ;
F_67 ( & V_7 -> V_59 -> V_130 ) ;
} else {
if ( F_48 ( V_125 ) < sizeof( T_2 ) )
return - V_111 ;
F_66 ( & V_7 -> V_59 -> V_130 ) ;
V_46 = F_50 ( V_7 , F_56 ( V_125 ) ) ;
F_67 ( & V_7 -> V_59 -> V_130 ) ;
}
if ( V_46 )
goto V_131;
}
if ( V_126 ) {
V_46 = F_45 ( (struct V_58 * ) F_18 ( V_57 ) , V_7 ,
V_126 , V_104 ) ;
}
if ( V_7 && ! ( V_9 & V_132 ) ) {
V_128 = F_68 ( V_57 , V_62 ,
V_9 ) ;
if ( V_128 && V_128 != - V_133 )
F_69 ( V_7 -> V_59 , L_3 ,
( unsigned int ) V_7 -> V_98 , V_7 -> V_57 -> V_65 ) ;
}
if ( V_46 == 0 )
F_31 ( V_84 , V_7 ) ;
V_131:
return V_46 ;
}
int F_70 ( struct V_56 * V_57 , struct V_61 * V_62 , T_3 V_9 )
{
struct V_85 * V_126 ;
struct V_6 * V_7 ;
int V_46 = 0 , V_128 = 0 ;
V_126 = F_64 ( V_62 , sizeof( struct V_1 ) , V_95 ) ;
if ( ! V_126 )
return 0 ;
V_7 = F_39 ( V_57 ) ;
if ( ! V_7 && ! ( V_57 -> V_134 & V_135 ) )
return - V_111 ;
V_46 = F_45 ( (struct V_58 * ) F_18 ( V_57 ) , V_7 ,
V_126 , V_106 ) ;
if ( V_46 == 0 )
F_31 ( V_84 , V_7 ) ;
if ( V_7 && ! ( V_9 & V_132 ) ) {
V_128 = F_71 ( V_57 , V_62 ,
V_9 ) ;
if ( V_128 && V_128 != - V_133 )
F_69 ( V_7 -> V_59 , L_4 ,
( unsigned int ) V_7 -> V_98 , V_7 -> V_57 -> V_65 ) ;
}
return V_46 ;
}
static int F_72 ( struct V_85 * V_120 [] , struct V_85 * V_136 [] )
{
if ( V_120 [ V_80 ] ) {
if ( F_48 ( V_120 [ V_80 ] ) != V_137 )
return - V_111 ;
if ( ! F_73 ( F_49 ( V_120 [ V_80 ] ) ) )
return - V_138 ;
}
return 0 ;
}
static int F_74 ( struct V_96 * V_139 , struct V_56 * V_57 ,
struct V_85 * V_120 [] , struct V_85 * V_136 [] )
{
struct V_58 * V_59 = F_18 ( V_57 ) ;
if ( V_120 [ V_80 ] ) {
F_66 ( & V_59 -> V_130 ) ;
F_75 ( V_59 , F_49 ( V_120 [ V_80 ] ) ) ;
F_67 ( & V_59 -> V_130 ) ;
}
return F_76 ( V_57 ) ;
}
static int F_77 ( struct V_56 * V_140 ,
struct V_56 * V_57 ,
struct V_85 * V_120 [] ,
struct V_85 * V_136 [] )
{
if ( ! V_136 )
return 0 ;
return F_57 ( F_39 ( V_57 ) , V_136 ) ;
}
static int F_78 ( struct V_4 * V_5 ,
const struct V_56 * V_140 ,
const struct V_56 * V_57 )
{
return F_5 ( V_5 , F_39 ( V_57 ) ) ;
}
static T_1 F_79 ( const struct V_56 * V_140 ,
const struct V_56 * V_57 )
{
return F_1 () ;
}
static int F_80 ( struct V_56 * V_140 , struct V_85 * V_120 [] ,
struct V_85 * V_136 [] )
{
struct V_58 * V_59 = F_18 ( V_140 ) ;
int V_46 ;
if ( ! V_136 )
return 0 ;
if ( V_136 [ V_141 ] ) {
V_46 = F_81 ( V_59 , F_59 ( V_136 [ V_141 ] ) ) ;
if ( V_46 )
return V_46 ;
}
if ( V_136 [ V_142 ] ) {
V_46 = F_82 ( V_59 , F_59 ( V_136 [ V_142 ] ) ) ;
if ( V_46 )
return V_46 ;
}
if ( V_136 [ V_143 ] ) {
V_46 = F_83 ( V_59 , F_59 ( V_136 [ V_143 ] ) ) ;
if ( V_46 )
return V_46 ;
}
return 0 ;
}
static T_1 F_84 ( const struct V_56 * V_140 )
{
return F_2 ( sizeof( T_4 ) ) +
F_2 ( sizeof( T_4 ) ) +
F_2 ( sizeof( T_4 ) ) +
0 ;
}
static int F_85 ( struct V_4 * V_5 , const struct V_56 * V_140 )
{
struct V_58 * V_59 = F_18 ( V_140 ) ;
T_4 V_144 = F_86 ( V_59 -> V_144 ) ;
T_4 V_145 = F_86 ( V_59 -> V_145 ) ;
T_4 V_146 = F_86 ( V_59 -> V_147 ) ;
if ( F_8 ( V_5 , V_141 , V_144 ) ||
F_8 ( V_5 , V_142 , V_145 ) ||
F_8 ( V_5 , V_143 , V_146 ) )
return - V_30 ;
return 0 ;
}
static T_1 F_87 ( const struct V_56 * V_57 )
{
struct V_40 * V_41 ;
if ( F_88 ( V_57 ) )
V_41 = F_26 ( F_39 ( V_57 ) ) ;
else if ( V_57 -> V_134 & V_135 )
V_41 = F_27 ( (struct V_58 * ) F_18 ( V_57 ) ) ;
else
return 0 ;
if ( ! V_41 )
return 0 ;
return V_41 -> V_148 * F_2 ( sizeof( struct V_33 ) ) ;
}
int T_5 F_89 ( void )
{
int V_46 ;
F_90 () ;
F_91 ( & V_149 ) ;
V_46 = F_92 ( & V_150 ) ;
if ( V_46 )
goto V_151;
return 0 ;
V_151:
F_93 ( & V_149 ) ;
F_94 () ;
return V_46 ;
}
void F_95 ( void )
{
F_94 () ;
F_93 ( & V_149 ) ;
F_96 ( & V_150 ) ;
}
