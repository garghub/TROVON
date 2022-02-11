static int F_1 ( const struct V_1 * V_2 ,
T_1 V_3 )
{
T_2 V_4 = 0 , V_5 = 0 ;
T_2 V_6 = 0 ;
T_2 V_7 , V_8 , V_9 ;
int V_10 = 0 ;
if ( V_3 & V_11 )
return V_2 -> V_10 ;
if ( ! ( V_3 & V_12 ) )
return 0 ;
V_7 = F_2 ( V_2 ) ;
F_3 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_9 = 0 ;
if ( V_8 == V_7 )
V_9 |= V_13 ;
if ( F_4 ( V_8 , V_2 -> V_14 ) )
V_9 |= V_15 ;
if ( V_4 == 0 ) {
goto V_16;
} else if ( ( V_8 - V_5 ) == 1 &&
V_9 == V_6 ) {
V_5 = V_8 ;
continue;
} else {
if ( ( V_5 - V_4 ) > 0 )
V_10 += 2 ;
else
V_10 += 1 ;
}
V_16:
V_4 = V_8 ;
V_5 = V_8 ;
V_6 = V_9 ;
}
if ( V_4 != 0 ) {
if ( ( V_5 - V_4 ) > 0 )
V_10 += 2 ;
else
V_10 += 1 ;
}
return V_10 ;
}
static T_3 F_5 ( const struct V_17 * V_18 ,
T_1 V_3 )
{
struct V_1 * V_2 ;
int V_19 ;
F_6 () ;
if ( F_7 ( V_18 ) )
V_2 = F_8 ( F_9 ( V_18 ) ) ;
else if ( V_18 -> V_20 & V_21 )
V_2 = F_10 ( (struct V_22 * ) F_11 ( V_18 ) ) ;
else
V_2 = NULL ;
if ( V_2 )
V_19 = F_1 ( V_2 , V_3 ) ;
else
V_19 = 0 ;
F_12 () ;
if ( ! V_19 )
return 0 ;
return V_19 * F_13 ( sizeof( struct V_23 ) ) ;
}
static inline T_3 F_14 ( void )
{
return F_13 ( 1 )
+ F_13 ( 2 )
+ F_13 ( 4 )
+ F_13 ( 1 )
+ F_13 ( 1 )
+ F_13 ( 1 )
+ F_13 ( 1 )
+ F_13 ( 1 )
+ F_13 ( 1 )
+ 0 ;
}
static inline T_3 F_15 ( struct V_17 * V_18 , T_1 V_3 )
{
return F_16 ( sizeof( struct V_24 ) )
+ F_13 ( V_25 )
+ F_13 ( V_26 )
+ F_13 ( 4 )
+ F_13 ( 4 )
+ F_13 ( 4 )
+ F_13 ( 1 )
+ F_13 ( F_14 () )
+ F_13 ( F_5 ( V_18 ,
V_3 ) ) ;
}
static int F_17 ( struct V_27 * V_28 ,
const struct V_29 * V_30 )
{
T_4 V_31 = ! ! ( V_30 -> V_9 & V_32 ) ;
if ( F_18 ( V_28 , V_33 , V_30 -> V_34 ) ||
F_19 ( V_28 , V_35 , V_30 -> V_36 ) ||
F_20 ( V_28 , V_37 , V_30 -> V_38 ) ||
F_18 ( V_28 , V_39 , V_31 ) ||
F_18 ( V_28 , V_40 , ! ! ( V_30 -> V_9 & V_41 ) ) ||
F_18 ( V_28 , V_42 , ! ! ( V_30 -> V_9 & V_43 ) ) ||
F_18 ( V_28 , V_44 , ! ! ( V_30 -> V_9 & V_45 ) ) ||
F_18 ( V_28 , V_46 , ! ! ( V_30 -> V_9 & V_47 ) ) ||
F_18 ( V_28 , V_48 , ! ! ( V_30 -> V_9 & V_49 ) ) ||
F_18 ( V_28 , V_50 , ! ! ( V_30 -> V_9 & V_51 ) ) ||
F_18 ( V_28 , V_52 ,
! ! ( V_30 -> V_9 & V_53 ) ) )
return - V_54 ;
return 0 ;
}
static int F_21 ( struct V_27 * V_28 , T_2 V_55 ,
T_2 V_56 , T_2 V_9 )
{
struct V_23 V_57 ;
if ( ( V_56 - V_55 ) > 0 ) {
V_57 . V_8 = V_55 ;
V_57 . V_9 = V_9 | V_58 ;
if ( F_22 ( V_28 , V_59 ,
sizeof( V_57 ) , & V_57 ) )
goto V_60;
V_57 . V_9 &= ~ V_58 ;
V_57 . V_8 = V_56 ;
V_57 . V_9 = V_9 | V_61 ;
if ( F_22 ( V_28 , V_59 ,
sizeof( V_57 ) , & V_57 ) )
goto V_60;
} else {
V_57 . V_8 = V_55 ;
V_57 . V_9 = V_9 ;
if ( F_22 ( V_28 , V_59 ,
sizeof( V_57 ) , & V_57 ) )
goto V_60;
}
return 0 ;
V_60:
return - V_54 ;
}
static int F_23 ( struct V_27 * V_28 ,
const struct V_1 * V_2 )
{
T_2 V_4 = 0 , V_5 = 0 ;
T_2 V_6 = 0 ;
T_2 V_7 , V_8 , V_9 ;
int V_62 = 0 ;
V_7 = F_2 ( V_2 ) ;
F_3 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_9 = 0 ;
if ( V_8 == V_7 )
V_9 |= V_13 ;
if ( F_4 ( V_8 , V_2 -> V_14 ) )
V_9 |= V_15 ;
if ( V_4 == 0 ) {
goto V_16;
} else if ( ( V_8 - V_5 ) == 1 &&
V_9 == V_6 ) {
V_5 = V_8 ;
continue;
} else {
V_62 = F_21 ( V_28 , V_4 ,
V_5 ,
V_6 ) ;
if ( V_62 )
return V_62 ;
}
V_16:
V_4 = V_8 ;
V_5 = V_8 ;
V_6 = V_9 ;
}
if ( V_4 != 0 ) {
V_62 = F_21 ( V_28 , V_4 ,
V_5 ,
V_6 ) ;
if ( V_62 )
return V_62 ;
}
return 0 ;
}
static int F_24 ( struct V_27 * V_28 ,
const struct V_1 * V_2 )
{
struct V_23 V_57 ;
T_2 V_7 , V_8 ;
V_7 = F_2 ( V_2 ) ;
F_3 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_57 . V_8 = V_8 ;
V_57 . V_9 = 0 ;
if ( V_8 == V_7 )
V_57 . V_9 |= V_13 ;
if ( F_4 ( V_8 , V_2 -> V_14 ) )
V_57 . V_9 |= V_15 ;
if ( F_22 ( V_28 , V_59 ,
sizeof( V_57 ) , & V_57 ) )
goto V_60;
}
return 0 ;
V_60:
return - V_54 ;
}
static int F_25 ( struct V_27 * V_28 ,
const struct V_29 * V_63 ,
T_1 V_64 , T_1 V_65 , int V_66 , unsigned int V_9 ,
T_1 V_3 , const struct V_17 * V_18 )
{
const struct V_22 * V_67 ;
struct V_24 * V_68 ;
struct V_69 * V_70 ;
T_4 V_71 = F_26 ( V_18 ) ? V_18 -> V_71 : V_72 ;
if ( V_63 )
V_67 = V_63 -> V_67 ;
else
V_67 = F_11 ( V_18 ) ;
F_27 ( V_67 , L_1 ,
V_66 , V_18 -> V_73 , V_67 -> V_18 -> V_73 ) ;
V_70 = F_28 ( V_28 , V_64 , V_65 , V_66 , sizeof( * V_68 ) , V_9 ) ;
if ( V_70 == NULL )
return - V_54 ;
V_68 = F_29 ( V_70 ) ;
V_68 -> V_74 = V_75 ;
V_68 -> V_76 = 0 ;
V_68 -> V_77 = V_18 -> type ;
V_68 -> V_78 = V_18 -> V_79 ;
V_68 -> V_80 = F_30 ( V_18 ) ;
V_68 -> V_81 = 0 ;
if ( F_31 ( V_28 , V_82 , V_18 -> V_73 ) ||
F_20 ( V_28 , V_83 , V_67 -> V_18 -> V_79 ) ||
F_20 ( V_28 , V_84 , V_18 -> V_85 ) ||
F_18 ( V_28 , V_86 , V_71 ) ||
( V_18 -> V_87 &&
F_22 ( V_28 , V_88 , V_18 -> V_87 , V_18 -> V_89 ) ) ||
( V_18 -> V_79 != F_32 ( V_18 ) &&
F_20 ( V_28 , V_90 , F_32 ( V_18 ) ) ) )
goto V_60;
if ( V_66 == V_91 && V_63 ) {
struct V_92 * V_93
= F_33 ( V_28 , V_94 | V_95 ) ;
if ( V_93 == NULL || F_17 ( V_28 , V_63 ) < 0 )
goto V_60;
F_34 ( V_28 , V_93 ) ;
}
if ( ( V_3 & V_11 ) ||
( V_3 & V_12 ) ) {
const struct V_1 * V_2 ;
struct V_92 * V_96 ;
int V_62 ;
if ( V_63 )
V_2 = F_8 ( V_63 ) ;
else
V_2 = F_10 ( V_67 ) ;
if ( ! V_2 || F_35 ( V_2 -> V_97 , V_98 ) )
goto V_99;
V_96 = F_33 ( V_28 , V_100 ) ;
if ( ! V_96 )
goto V_60;
if ( V_3 & V_12 )
V_62 = F_23 ( V_28 , V_2 ) ;
else
V_62 = F_24 ( V_28 , V_2 ) ;
if ( V_62 )
goto V_60;
F_34 ( V_28 , V_96 ) ;
}
V_99:
F_36 ( V_28 , V_70 ) ;
return 0 ;
V_60:
F_37 ( V_28 , V_70 ) ;
return - V_54 ;
}
void F_38 ( int V_66 , struct V_29 * V_63 )
{
struct V_101 * V_101 ;
struct V_27 * V_28 ;
int V_62 = - V_102 ;
T_1 V_103 = V_12 ;
if ( ! V_63 )
return;
V_101 = F_39 ( V_63 -> V_18 ) ;
F_27 ( V_63 -> V_67 , L_2 ,
( unsigned int ) V_63 -> V_104 , V_63 -> V_18 -> V_73 , V_66 ) ;
V_28 = F_40 ( F_15 ( V_63 -> V_18 , V_103 ) , V_105 ) ;
if ( V_28 == NULL )
goto V_106;
V_62 = F_25 ( V_28 , V_63 , 0 , 0 , V_66 , 0 , V_103 , V_63 -> V_18 ) ;
if ( V_62 < 0 ) {
F_41 ( V_62 == - V_54 ) ;
F_42 ( V_28 ) ;
goto V_106;
}
F_43 ( V_28 , V_101 , 0 , V_107 , NULL , V_105 ) ;
return;
V_106:
F_44 ( V_101 , V_107 , V_62 ) ;
}
int F_45 ( struct V_27 * V_28 , T_1 V_64 , T_1 V_65 ,
struct V_17 * V_18 , T_1 V_3 , int V_108 )
{
struct V_29 * V_63 = F_46 ( V_18 ) ;
if ( ! V_63 && ! ( V_3 & V_11 ) &&
! ( V_3 & V_12 ) )
return 0 ;
return F_25 ( V_28 , V_63 , V_64 , V_65 , V_91 , V_108 ,
V_3 , V_18 ) ;
}
static int F_47 ( struct V_22 * V_67 , struct V_29 * V_30 ,
int V_109 , struct V_23 * V_57 )
{
int V_62 = 0 ;
switch ( V_109 ) {
case V_110 :
if ( V_30 ) {
V_62 = F_48 ( V_30 , V_57 -> V_8 , V_57 -> V_9 ) ;
if ( V_62 )
break;
if ( V_57 -> V_9 & V_111 )
V_62 = F_49 ( V_30 -> V_67 , V_57 -> V_8 ,
V_57 -> V_9 ) ;
} else {
V_62 = F_49 ( V_67 , V_57 -> V_8 , V_57 -> V_9 ) ;
}
break;
case V_112 :
if ( V_30 ) {
F_50 ( V_30 , V_57 -> V_8 ) ;
if ( V_57 -> V_9 & V_111 )
F_51 ( V_30 -> V_67 , V_57 -> V_8 ) ;
} else {
F_51 ( V_67 , V_57 -> V_8 ) ;
}
break;
}
return V_62 ;
}
static int F_52 ( struct V_22 * V_67 ,
struct V_29 * V_30 ,
struct V_92 * V_113 ,
int V_109 )
{
struct V_23 * V_114 = NULL ;
struct V_23 * V_57 = NULL ;
struct V_92 * V_115 ;
int V_62 = 0 ;
int V_116 ;
F_53 (attr, af_spec, rem) {
if ( F_54 ( V_115 ) != V_59 )
continue;
if ( F_55 ( V_115 ) != sizeof( struct V_23 ) )
return - V_117 ;
V_57 = F_56 ( V_115 ) ;
if ( V_57 -> V_9 & V_58 ) {
if ( V_114 )
return - V_117 ;
V_114 = V_57 ;
continue;
}
if ( V_114 ) {
struct V_23 V_118 ;
int V_119 ;
if ( ! ( V_57 -> V_9 & V_61 ) )
return - V_117 ;
if ( V_57 -> V_8 <= V_114 -> V_8 )
return - V_117 ;
memcpy ( & V_118 , V_114 ,
sizeof( struct V_23 ) ) ;
for ( V_119 = V_114 -> V_8 ; V_119 <= V_57 -> V_8 ; V_119 ++ ) {
V_118 . V_8 = V_119 ;
V_62 = F_47 ( V_67 , V_30 , V_109 , & V_118 ) ;
if ( V_62 )
break;
}
V_114 = NULL ;
} else {
V_62 = F_47 ( V_67 , V_30 , V_109 , V_57 ) ;
}
if ( V_62 )
break;
}
return V_62 ;
}
static int F_57 ( struct V_29 * V_30 , T_4 V_34 )
{
if ( V_34 > V_120 )
return - V_117 ;
if ( V_30 -> V_67 -> V_121 == V_122 )
return - V_123 ;
if ( ! F_26 ( V_30 -> V_18 ) ||
( ! F_58 ( V_30 -> V_18 ) && V_34 != V_124 ) )
return - V_125 ;
F_59 ( V_30 , V_34 ) ;
F_60 ( V_30 ) ;
F_61 ( V_30 -> V_67 ) ;
return 0 ;
}
static void F_62 ( struct V_29 * V_30 , struct V_92 * V_126 [] ,
int V_127 , unsigned long V_128 )
{
if ( V_126 [ V_127 ] ) {
T_4 V_129 = F_63 ( V_126 [ V_127 ] ) ;
if ( V_129 )
V_30 -> V_9 |= V_128 ;
else
V_30 -> V_9 &= ~ V_128 ;
}
}
static int F_64 ( struct V_29 * V_30 , struct V_92 * V_126 [] )
{
int V_62 ;
unsigned long V_130 = V_30 -> V_9 ;
F_62 ( V_30 , V_126 , V_39 , V_32 ) ;
F_62 ( V_30 , V_126 , V_40 , V_41 ) ;
F_62 ( V_30 , V_126 , V_44 , V_45 ) ;
F_62 ( V_30 , V_126 , V_42 , V_43 ) ;
F_62 ( V_30 , V_126 , V_46 , V_47 ) ;
F_62 ( V_30 , V_126 , V_48 , V_49 ) ;
F_62 ( V_30 , V_126 , V_50 , V_51 ) ;
F_62 ( V_30 , V_126 , V_52 , V_53 ) ;
if ( V_126 [ V_37 ] ) {
V_62 = F_65 ( V_30 , F_66 ( V_126 [ V_37 ] ) ) ;
if ( V_62 )
return V_62 ;
}
if ( V_126 [ V_35 ] ) {
V_62 = F_67 ( V_30 , F_68 ( V_126 [ V_35 ] ) ) ;
if ( V_62 )
return V_62 ;
}
if ( V_126 [ V_33 ] ) {
V_62 = F_57 ( V_30 , F_63 ( V_126 [ V_33 ] ) ) ;
if ( V_62 )
return V_62 ;
}
F_69 ( V_30 , V_130 ^ V_30 -> V_9 ) ;
return 0 ;
}
int F_70 ( struct V_17 * V_18 , struct V_69 * V_70 , T_2 V_9 )
{
struct V_92 * V_131 ;
struct V_92 * V_132 ;
struct V_29 * V_30 ;
struct V_92 * V_126 [ V_133 + 1 ] ;
int V_62 = 0 , V_134 = 0 ;
V_131 = F_71 ( V_70 , sizeof( struct V_24 ) , V_94 ) ;
V_132 = F_71 ( V_70 , sizeof( struct V_24 ) , V_100 ) ;
if ( ! V_131 && ! V_132 )
return 0 ;
V_30 = F_46 ( V_18 ) ;
if ( ! V_30 && ! V_132 )
return - V_117 ;
if ( V_30 && V_131 ) {
if ( V_131 -> F_54 & V_95 ) {
V_62 = F_72 ( V_126 , V_133 ,
V_131 , V_135 ) ;
if ( V_62 )
return V_62 ;
F_73 ( & V_30 -> V_67 -> V_136 ) ;
V_62 = F_64 ( V_30 , V_126 ) ;
F_74 ( & V_30 -> V_67 -> V_136 ) ;
} else {
if ( F_55 ( V_131 ) < sizeof( T_4 ) )
return - V_117 ;
F_73 ( & V_30 -> V_67 -> V_136 ) ;
V_62 = F_57 ( V_30 , F_63 ( V_131 ) ) ;
F_74 ( & V_30 -> V_67 -> V_136 ) ;
}
if ( V_62 )
goto V_137;
}
if ( V_132 ) {
V_62 = F_52 ( (struct V_22 * ) F_11 ( V_18 ) , V_30 ,
V_132 , V_110 ) ;
}
if ( V_30 && ! ( V_9 & V_138 ) ) {
V_134 = F_75 ( V_18 , V_70 ,
V_9 ) ;
if ( V_134 && V_134 != - V_139 )
F_76 ( V_30 -> V_67 , L_3 ,
( unsigned int ) V_30 -> V_104 , V_30 -> V_18 -> V_73 ) ;
}
if ( V_62 == 0 )
F_38 ( V_91 , V_30 ) ;
V_137:
return V_62 ;
}
int F_77 ( struct V_17 * V_18 , struct V_69 * V_70 , T_2 V_9 )
{
struct V_92 * V_132 ;
struct V_29 * V_30 ;
int V_62 = 0 , V_134 = 0 ;
V_132 = F_71 ( V_70 , sizeof( struct V_24 ) , V_100 ) ;
if ( ! V_132 )
return 0 ;
V_30 = F_46 ( V_18 ) ;
if ( ! V_30 && ! ( V_18 -> V_20 & V_21 ) )
return - V_117 ;
V_62 = F_52 ( (struct V_22 * ) F_11 ( V_18 ) , V_30 ,
V_132 , V_112 ) ;
if ( V_62 == 0 )
F_38 ( V_91 , V_30 ) ;
if ( V_30 && ! ( V_9 & V_138 ) ) {
V_134 = F_78 ( V_18 , V_70 ,
V_9 ) ;
if ( V_134 && V_134 != - V_139 )
F_76 ( V_30 -> V_67 , L_4 ,
( unsigned int ) V_30 -> V_104 , V_30 -> V_18 -> V_73 ) ;
}
return V_62 ;
}
static int F_79 ( struct V_92 * V_126 [] , struct V_92 * V_140 [] )
{
if ( V_126 [ V_88 ] ) {
if ( F_55 ( V_126 [ V_88 ] ) != V_141 )
return - V_117 ;
if ( ! F_80 ( F_56 ( V_126 [ V_88 ] ) ) )
return - V_142 ;
}
return 0 ;
}
static int F_81 ( struct V_101 * V_143 , struct V_17 * V_18 ,
struct V_92 * V_126 [] , struct V_92 * V_140 [] )
{
struct V_22 * V_67 = F_11 ( V_18 ) ;
if ( V_126 [ V_88 ] ) {
F_73 ( & V_67 -> V_136 ) ;
F_82 ( V_67 , F_56 ( V_126 [ V_88 ] ) ) ;
F_74 ( & V_67 -> V_136 ) ;
}
return F_83 ( V_18 ) ;
}
static int F_84 ( struct V_17 * V_144 ,
struct V_17 * V_18 ,
struct V_92 * V_126 [] ,
struct V_92 * V_140 [] )
{
if ( ! V_140 )
return 0 ;
return F_64 ( F_46 ( V_18 ) , V_140 ) ;
}
static int F_85 ( struct V_27 * V_28 ,
const struct V_17 * V_144 ,
const struct V_17 * V_18 )
{
return F_17 ( V_28 , F_46 ( V_18 ) ) ;
}
static T_3 F_86 ( const struct V_17 * V_144 ,
const struct V_17 * V_18 )
{
return F_14 () ;
}
static int F_87 ( struct V_17 * V_144 , struct V_92 * V_126 [] ,
struct V_92 * V_140 [] )
{
struct V_22 * V_67 = F_11 ( V_144 ) ;
int V_62 ;
if ( ! V_140 )
return 0 ;
if ( V_140 [ V_145 ] ) {
V_62 = F_88 ( V_67 , F_66 ( V_140 [ V_145 ] ) ) ;
if ( V_62 )
return V_62 ;
}
if ( V_140 [ V_146 ] ) {
V_62 = F_89 ( V_67 , F_66 ( V_140 [ V_146 ] ) ) ;
if ( V_62 )
return V_62 ;
}
if ( V_140 [ V_147 ] ) {
V_62 = F_90 ( V_67 , F_66 ( V_140 [ V_147 ] ) ) ;
if ( V_62 )
return V_62 ;
}
if ( V_140 [ V_148 ] ) {
T_1 V_149 = F_66 ( V_140 [ V_148 ] ) ;
V_67 -> V_149 = F_91 ( V_149 ) ;
}
if ( V_140 [ V_150 ] ) {
T_1 V_121 = F_66 ( V_140 [ V_150 ] ) ;
F_92 ( V_67 , V_121 ) ;
}
if ( V_140 [ V_151 ] ) {
T_1 V_36 = F_68 ( V_140 [ V_151 ] ) ;
F_93 ( V_67 , V_36 ) ;
}
return 0 ;
}
static T_3 F_94 ( const struct V_17 * V_144 )
{
return F_13 ( sizeof( T_1 ) ) +
F_13 ( sizeof( T_1 ) ) +
F_13 ( sizeof( T_1 ) ) +
F_13 ( sizeof( T_1 ) ) +
F_13 ( sizeof( T_1 ) ) +
F_13 ( sizeof( T_2 ) ) +
0 ;
}
static int F_95 ( struct V_27 * V_28 , const struct V_17 * V_144 )
{
struct V_22 * V_67 = F_11 ( V_144 ) ;
T_1 V_152 = F_96 ( V_67 -> V_152 ) ;
T_1 V_153 = F_96 ( V_67 -> V_153 ) ;
T_1 V_154 = F_96 ( V_67 -> V_155 ) ;
T_1 V_149 = F_96 ( V_67 -> V_149 ) ;
T_1 V_121 = V_67 -> V_121 ;
T_2 V_36 = ( V_67 -> V_156 . V_157 [ 0 ] << 8 ) | V_67 -> V_156 . V_157 [ 1 ] ;
if ( F_20 ( V_28 , V_145 , V_152 ) ||
F_20 ( V_28 , V_146 , V_153 ) ||
F_20 ( V_28 , V_147 , V_154 ) ||
F_20 ( V_28 , V_148 , V_149 ) ||
F_20 ( V_28 , V_150 , V_121 ) ||
F_19 ( V_28 , V_151 , V_36 ) )
return - V_54 ;
return 0 ;
}
static T_3 F_97 ( const struct V_17 * V_18 )
{
struct V_1 * V_2 ;
if ( F_7 ( V_18 ) )
V_2 = F_8 ( F_46 ( V_18 ) ) ;
else if ( V_18 -> V_20 & V_21 )
V_2 = F_10 ( (struct V_22 * ) F_11 ( V_18 ) ) ;
else
return 0 ;
if ( ! V_2 )
return 0 ;
return V_2 -> V_10 * F_13 ( sizeof( struct V_23 ) ) ;
}
int T_5 F_98 ( void )
{
int V_62 ;
F_99 () ;
F_100 ( & V_158 ) ;
V_62 = F_101 ( & V_159 ) ;
if ( V_62 )
goto V_160;
return 0 ;
V_160:
F_102 ( & V_158 ) ;
F_103 () ;
return V_62 ;
}
void F_104 ( void )
{
F_103 () ;
F_102 ( & V_158 ) ;
F_105 ( & V_159 ) ;
}
