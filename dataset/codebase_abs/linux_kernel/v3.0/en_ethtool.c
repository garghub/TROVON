static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
strncpy ( V_4 -> V_9 , V_10 , 32 ) ;
strncpy ( V_4 -> V_11 , V_12 L_1 V_13 L_2 , 32 ) ;
sprintf ( V_4 -> V_14 , L_3 ,
( V_15 ) ( V_8 -> V_2 -> V_16 . V_17 >> 32 ) ,
( V_15 ) ( ( V_8 -> V_2 -> V_16 . V_17 >> 16 ) & 0xffff ) ,
( V_15 ) ( V_8 -> V_2 -> V_16 . V_17 & 0xffff ) ) ;
strncpy ( V_4 -> V_18 , F_3 ( V_8 -> V_2 -> V_19 ) , 32 ) ;
V_4 -> V_20 = 0 ;
V_4 -> V_21 = 0 ;
V_4 -> V_22 = 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
return ( (struct V_5 * ) F_2 ( V_2 ) ) -> V_23 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_24 )
{
( (struct V_5 * ) F_2 ( V_2 ) ) -> V_23 = V_24 ;
}
static void F_6 ( struct V_1 * V_25 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_25 ) ;
int V_28 = 0 ;
T_2 V_29 = 0 ;
if ( ! V_6 -> V_8 -> V_2 -> V_16 . V_27 ) {
V_27 -> V_30 = 0 ;
V_27 -> V_31 = 0 ;
return;
}
V_28 = F_7 ( V_6 -> V_8 -> V_2 , & V_29 , V_6 -> V_32 ) ;
if ( V_28 ) {
F_8 ( V_6 , L_4 ) ;
return;
}
if ( V_29 & V_33 )
V_27 -> V_30 = V_34 ;
else
V_27 -> V_30 = 0 ;
if ( V_29 & V_35 )
V_27 -> V_31 = V_34 ;
else
V_27 -> V_31 = 0 ;
}
static int F_9 ( struct V_1 * V_25 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_25 ) ;
T_2 V_29 = 0 ;
int V_28 = 0 ;
if ( ! V_6 -> V_8 -> V_2 -> V_16 . V_27 )
return - V_36 ;
if ( V_27 -> V_30 & ~ V_34 )
return - V_37 ;
V_28 = F_7 ( V_6 -> V_8 -> V_2 , & V_29 , V_6 -> V_32 ) ;
if ( V_28 ) {
F_8 ( V_6 , L_5 ) ;
return V_28 ;
}
if ( V_27 -> V_31 & V_34 ) {
V_29 |= V_38 | V_35 |
V_33 ;
} else {
V_29 &= ~ ( V_35 | V_33 ) ;
V_29 |= V_38 ;
}
V_28 = F_10 ( V_6 -> V_8 -> V_2 , V_29 , V_6 -> V_32 ) ;
if ( V_28 )
F_8 ( V_6 , L_6 ) ;
return V_28 ;
}
static int F_11 ( struct V_1 * V_2 , int V_39 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_39 ) {
case V_40 :
return V_41 +
( V_6 -> V_42 + V_6 -> V_43 ) * 2 ;
case V_44 :
return V_45 - ! ( V_6 -> V_8 -> V_2 -> V_16 . V_46 ) * 2 ;
default:
return - V_36 ;
}
}
static void F_12 ( struct V_1 * V_2 ,
struct V_47 * V_48 , T_3 * V_49 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_50 = 0 ;
int V_51 ;
F_13 ( & V_6 -> V_52 ) ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ )
V_49 [ V_50 ++ ] = ( ( unsigned long * ) & V_6 -> V_48 ) [ V_51 ] ;
for ( V_51 = 0 ; V_51 < V_54 ; V_51 ++ )
V_49 [ V_50 ++ ] = ( ( unsigned long * ) & V_6 -> V_55 ) [ V_51 ] ;
for ( V_51 = 0 ; V_51 < V_6 -> V_42 ; V_51 ++ ) {
V_49 [ V_50 ++ ] = V_6 -> V_56 [ V_51 ] . V_57 ;
V_49 [ V_50 ++ ] = V_6 -> V_56 [ V_51 ] . V_58 ;
}
for ( V_51 = 0 ; V_51 < V_6 -> V_43 ; V_51 ++ ) {
V_49 [ V_50 ++ ] = V_6 -> V_59 [ V_51 ] . V_57 ;
V_49 [ V_50 ++ ] = V_6 -> V_59 [ V_51 ] . V_58 ;
}
for ( V_51 = 0 ; V_51 < V_60 ; V_51 ++ )
V_49 [ V_50 ++ ] = ( ( unsigned long * ) & V_6 -> V_61 ) [ V_51 ] ;
F_14 ( & V_6 -> V_52 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_62 * V_63 , T_2 * V_64 )
{
F_16 ( V_2 , & V_63 -> V_65 , V_64 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
T_4 V_66 , T_5 * V_49 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_50 = 0 ;
int V_51 ;
switch ( V_66 ) {
case V_44 :
for ( V_51 = 0 ; V_51 < V_45 - 2 ; V_51 ++ )
strcpy ( V_49 + V_51 * V_67 , V_68 [ V_51 ] ) ;
if ( V_6 -> V_8 -> V_2 -> V_16 . V_46 )
for (; V_51 < V_45 ; V_51 ++ )
strcpy ( V_49 + V_51 * V_67 , V_68 [ V_51 ] ) ;
break;
case V_40 :
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ )
strcpy ( V_49 + ( V_50 ++ ) * V_67 , V_69 [ V_51 ] ) ;
for ( V_51 = 0 ; V_51 < V_54 ; V_51 ++ )
strcpy ( V_49 + ( V_50 ++ ) * V_67 ,
V_69 [ V_51 + V_53 ] ) ;
for ( V_51 = 0 ; V_51 < V_6 -> V_42 ; V_51 ++ ) {
sprintf ( V_49 + ( V_50 ++ ) * V_67 ,
L_7 , V_51 ) ;
sprintf ( V_49 + ( V_50 ++ ) * V_67 ,
L_8 , V_51 ) ;
}
for ( V_51 = 0 ; V_51 < V_6 -> V_43 ; V_51 ++ ) {
sprintf ( V_49 + ( V_50 ++ ) * V_67 ,
L_9 , V_51 ) ;
sprintf ( V_49 + ( V_50 ++ ) * V_67 ,
L_10 , V_51 ) ;
}
for ( V_51 = 0 ; V_51 < V_60 ; V_51 ++ )
strcpy ( V_49 + ( V_50 ++ ) * V_67 ,
V_69 [ V_51 + V_53 + V_54 ] ) ;
break;
}
}
static int F_18 ( struct V_1 * V_2 , struct V_70 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_72 ;
V_71 -> V_73 = V_74 ;
V_71 -> V_30 = V_75 ;
V_71 -> V_76 = V_77 ;
if ( F_19 ( V_6 -> V_8 , V_6 -> V_32 ) )
return - V_78 ;
V_72 = V_6 -> V_79 . V_80 ;
if ( F_20 ( V_2 ) ) {
F_21 ( V_71 , V_6 -> V_79 . V_81 ) ;
V_71 -> V_82 = V_83 ;
} else {
F_21 ( V_71 , - 1 ) ;
V_71 -> V_82 = - 1 ;
}
if ( V_72 > 0 && V_72 <= 0xC ) {
V_71 -> V_32 = V_84 ;
V_71 -> V_85 = V_86 ;
V_71 -> V_30 |= V_87 ;
V_71 -> V_76 |= V_88 ;
} else if ( V_72 == 0x80 || V_72 == 0 ) {
V_71 -> V_32 = V_89 ;
V_71 -> V_85 = V_90 ;
V_71 -> V_30 |= V_91 ;
V_71 -> V_76 |= V_92 ;
} else {
V_71 -> V_32 = - 1 ;
V_71 -> V_85 = - 1 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_70 * V_71 )
{
if ( ( V_71 -> V_73 == V_93 ) ||
( F_23 ( V_71 ) != V_94 ) ||
( V_71 -> V_82 != V_83 ) )
return - V_37 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_96 -> V_97 = 0 ;
V_96 -> V_98 = 0 ;
V_96 -> V_99 = V_6 -> V_100 ;
V_96 -> V_101 = V_6 -> V_102 ;
V_96 -> V_103 = V_6 -> V_103 ;
V_96 -> V_104 = V_6 -> V_105 ;
V_96 -> V_106 = V_6 -> V_106 ;
V_96 -> V_107 = V_6 -> V_108 ;
V_96 -> V_109 = V_6 -> V_110 ;
V_96 -> V_111 = V_6 -> V_112 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_28 , V_51 ;
V_6 -> V_102 = ( V_96 -> V_101 ==
V_113 ) ?
V_114 :
V_96 -> V_101 ;
V_6 -> V_100 = ( V_96 -> V_99 ==
V_113 ) ?
V_115 :
V_96 -> V_99 ;
V_6 -> V_103 = V_96 -> V_103 ;
V_6 -> V_105 = V_96 -> V_104 ;
V_6 -> V_106 = V_96 -> V_106 ;
V_6 -> V_108 = V_96 -> V_107 ;
V_6 -> V_110 = V_96 -> V_109 ;
V_6 -> V_112 = V_96 -> V_111 ;
V_6 -> V_116 = V_113 ;
if ( V_6 -> V_112 )
return 0 ;
for ( V_51 = 0 ; V_51 < V_6 -> V_43 ; V_51 ++ ) {
V_6 -> V_117 [ V_51 ] . V_118 = V_6 -> V_102 ;
V_6 -> V_117 [ V_51 ] . V_119 = V_6 -> V_100 ;
V_28 = F_26 ( V_6 , & V_6 -> V_117 [ V_51 ] ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 ;
V_6 -> V_122 -> V_123 = V_121 -> V_123 != 0 ;
V_6 -> V_122 -> V_124 = V_121 -> V_124 != 0 ;
V_28 = F_28 ( V_8 -> V_2 , V_6 -> V_32 ,
V_6 -> V_125 + V_126 ,
V_6 -> V_122 -> V_123 ,
V_6 -> V_122 -> V_127 ,
V_6 -> V_122 -> V_124 ,
V_6 -> V_122 -> V_128 ) ;
if ( V_28 )
F_8 ( V_6 , L_11 ) ;
return V_28 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_121 -> V_123 = V_6 -> V_122 -> V_123 ;
V_121 -> V_124 = V_6 -> V_122 -> V_124 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_131 , V_132 ;
int V_133 = 0 ;
int V_28 = 0 ;
if ( V_130 -> V_134 || V_130 -> V_135 )
return - V_37 ;
V_131 = F_31 ( V_130 -> V_136 ) ;
V_131 = F_32 ( T_1 , V_131 , V_137 ) ;
V_131 = F_33 ( T_1 , V_131 , V_138 ) ;
V_132 = F_31 ( V_130 -> V_139 ) ;
V_132 = F_32 ( T_1 , V_132 , V_140 ) ;
V_132 = F_33 ( T_1 , V_132 , V_141 ) ;
if ( V_131 == ( V_6 -> V_133 ? V_6 -> V_59 [ 0 ] . V_142 :
V_6 -> V_59 [ 0 ] . V_143 ) &&
V_132 == V_6 -> V_56 [ 0 ] . V_143 )
return 0 ;
F_34 ( & V_8 -> V_144 ) ;
if ( V_6 -> V_133 ) {
V_133 = 1 ;
F_35 ( V_2 ) ;
}
F_36 ( V_6 , true ) ;
V_6 -> V_122 -> V_145 = V_132 ;
V_6 -> V_122 -> V_146 = V_131 ;
V_28 = F_37 ( V_6 ) ;
if ( V_28 ) {
F_8 ( V_6 , L_12 ) ;
goto V_147;
}
if ( V_133 ) {
V_28 = F_38 ( V_2 ) ;
if ( V_28 )
F_8 ( V_6 , L_13 ) ;
}
V_147:
F_39 ( & V_8 -> V_144 ) ;
return V_28 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
memset ( V_130 , 0 , sizeof( * V_130 ) ) ;
V_130 -> V_148 = V_138 ;
V_130 -> V_149 = V_141 ;
V_130 -> V_136 = V_6 -> V_133 ?
V_6 -> V_59 [ 0 ] . V_142 : V_6 -> V_59 [ 0 ] . V_143 ;
V_130 -> V_139 = V_6 -> V_56 [ 0 ] . V_143 ;
}
