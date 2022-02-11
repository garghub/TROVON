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
if ( ! ( V_6 -> V_8 -> V_2 -> V_16 . V_30 & V_31 ) ) {
V_27 -> V_32 = 0 ;
V_27 -> V_33 = 0 ;
return;
}
V_28 = F_7 ( V_6 -> V_8 -> V_2 , & V_29 , V_6 -> V_34 ) ;
if ( V_28 ) {
F_8 ( V_6 , L_4 ) ;
return;
}
if ( V_29 & V_35 )
V_27 -> V_32 = V_36 ;
else
V_27 -> V_32 = 0 ;
if ( V_29 & V_37 )
V_27 -> V_33 = V_36 ;
else
V_27 -> V_33 = 0 ;
}
static int F_9 ( struct V_1 * V_25 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_25 ) ;
T_2 V_29 = 0 ;
int V_28 = 0 ;
if ( ! ( V_6 -> V_8 -> V_2 -> V_16 . V_30 & V_31 ) )
return - V_38 ;
if ( V_27 -> V_32 & ~ V_36 )
return - V_39 ;
V_28 = F_7 ( V_6 -> V_8 -> V_2 , & V_29 , V_6 -> V_34 ) ;
if ( V_28 ) {
F_8 ( V_6 , L_5 ) ;
return V_28 ;
}
if ( V_27 -> V_33 & V_36 ) {
V_29 |= V_40 | V_37 |
V_35 ;
} else {
V_29 &= ~ ( V_37 | V_35 ) ;
V_29 |= V_40 ;
}
V_28 = F_10 ( V_6 -> V_8 -> V_2 , V_29 , V_6 -> V_34 ) ;
if ( V_28 )
F_8 ( V_6 , L_6 ) ;
return V_28 ;
}
static int F_11 ( struct V_1 * V_2 , int V_41 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_41 ) {
case V_42 :
return V_43 +
( V_6 -> V_44 + V_6 -> V_45 ) * 2 ;
case V_46 :
return V_47 - ! ( V_6 -> V_8 -> V_2 -> V_16 . V_30
& V_48 ) * 2 ;
default:
return - V_38 ;
}
}
static void F_12 ( struct V_1 * V_2 ,
struct V_49 * V_50 , T_3 * V_51 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_52 = 0 ;
int V_53 ;
F_13 ( & V_6 -> V_54 ) ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ )
V_51 [ V_52 ++ ] = ( ( unsigned long * ) & V_6 -> V_50 ) [ V_53 ] ;
for ( V_53 = 0 ; V_53 < V_56 ; V_53 ++ )
V_51 [ V_52 ++ ] = ( ( unsigned long * ) & V_6 -> V_57 ) [ V_53 ] ;
for ( V_53 = 0 ; V_53 < V_6 -> V_44 ; V_53 ++ ) {
V_51 [ V_52 ++ ] = V_6 -> V_58 [ V_53 ] . V_59 ;
V_51 [ V_52 ++ ] = V_6 -> V_58 [ V_53 ] . V_60 ;
}
for ( V_53 = 0 ; V_53 < V_6 -> V_45 ; V_53 ++ ) {
V_51 [ V_52 ++ ] = V_6 -> V_61 [ V_53 ] . V_59 ;
V_51 [ V_52 ++ ] = V_6 -> V_61 [ V_53 ] . V_60 ;
}
for ( V_53 = 0 ; V_53 < V_62 ; V_53 ++ )
V_51 [ V_52 ++ ] = ( ( unsigned long * ) & V_6 -> V_63 ) [ V_53 ] ;
F_14 ( & V_6 -> V_54 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_64 * V_65 , T_2 * V_66 )
{
F_16 ( V_2 , & V_65 -> V_30 , V_66 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
T_4 V_67 , T_5 * V_51 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_52 = 0 ;
int V_53 ;
switch ( V_67 ) {
case V_46 :
for ( V_53 = 0 ; V_53 < V_47 - 2 ; V_53 ++ )
strcpy ( V_51 + V_53 * V_68 , V_69 [ V_53 ] ) ;
if ( V_6 -> V_8 -> V_2 -> V_16 . V_30 & V_48 )
for (; V_53 < V_47 ; V_53 ++ )
strcpy ( V_51 + V_53 * V_68 , V_69 [ V_53 ] ) ;
break;
case V_42 :
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ )
strcpy ( V_51 + ( V_52 ++ ) * V_68 , V_70 [ V_53 ] ) ;
for ( V_53 = 0 ; V_53 < V_56 ; V_53 ++ )
strcpy ( V_51 + ( V_52 ++ ) * V_68 ,
V_70 [ V_53 + V_55 ] ) ;
for ( V_53 = 0 ; V_53 < V_6 -> V_44 ; V_53 ++ ) {
sprintf ( V_51 + ( V_52 ++ ) * V_68 ,
L_7 , V_53 ) ;
sprintf ( V_51 + ( V_52 ++ ) * V_68 ,
L_8 , V_53 ) ;
}
for ( V_53 = 0 ; V_53 < V_6 -> V_45 ; V_53 ++ ) {
sprintf ( V_51 + ( V_52 ++ ) * V_68 ,
L_9 , V_53 ) ;
sprintf ( V_51 + ( V_52 ++ ) * V_68 ,
L_10 , V_53 ) ;
}
for ( V_53 = 0 ; V_53 < V_62 ; V_53 ++ )
strcpy ( V_51 + ( V_52 ++ ) * V_68 ,
V_70 [ V_53 + V_55 + V_56 ] ) ;
break;
}
}
static int F_18 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_73 ;
V_72 -> V_74 = V_75 ;
V_72 -> V_32 = V_76 ;
V_72 -> V_77 = V_78 ;
if ( F_19 ( V_6 -> V_8 , V_6 -> V_34 ) )
return - V_79 ;
V_73 = V_6 -> V_80 . V_81 ;
if ( F_20 ( V_2 ) ) {
F_21 ( V_72 , V_6 -> V_80 . V_82 ) ;
V_72 -> V_83 = V_84 ;
} else {
F_21 ( V_72 , - 1 ) ;
V_72 -> V_83 = - 1 ;
}
if ( V_73 > 0 && V_73 <= 0xC ) {
V_72 -> V_34 = V_85 ;
V_72 -> V_86 = V_87 ;
V_72 -> V_32 |= V_88 ;
V_72 -> V_77 |= V_89 ;
} else if ( V_73 == 0x80 || V_73 == 0 ) {
V_72 -> V_34 = V_90 ;
V_72 -> V_86 = V_91 ;
V_72 -> V_32 |= V_92 ;
V_72 -> V_77 |= V_93 ;
} else {
V_72 -> V_34 = - 1 ;
V_72 -> V_86 = - 1 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
if ( ( V_72 -> V_74 == V_94 ) ||
( F_23 ( V_72 ) != V_95 ) ||
( V_72 -> V_83 != V_84 ) )
return - V_39 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_96 * V_97 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_97 -> V_98 = 0 ;
V_97 -> V_99 = 0 ;
V_97 -> V_100 = V_6 -> V_101 ;
V_97 -> V_102 = V_6 -> V_103 ;
V_97 -> V_104 = V_6 -> V_104 ;
V_97 -> V_105 = V_6 -> V_106 ;
V_97 -> V_107 = V_6 -> V_107 ;
V_97 -> V_108 = V_6 -> V_109 ;
V_97 -> V_110 = V_6 -> V_111 ;
V_97 -> V_112 = V_6 -> V_113 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_96 * V_97 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_28 , V_53 ;
V_6 -> V_103 = ( V_97 -> V_102 ==
V_114 ) ?
V_115 :
V_97 -> V_102 ;
V_6 -> V_101 = ( V_97 -> V_100 ==
V_114 ) ?
V_116 :
V_97 -> V_100 ;
V_6 -> V_104 = V_97 -> V_104 ;
V_6 -> V_106 = V_97 -> V_105 ;
V_6 -> V_107 = V_97 -> V_107 ;
V_6 -> V_109 = V_97 -> V_108 ;
V_6 -> V_111 = V_97 -> V_110 ;
V_6 -> V_113 = V_97 -> V_112 ;
V_6 -> V_117 = V_114 ;
if ( V_6 -> V_113 )
return 0 ;
for ( V_53 = 0 ; V_53 < V_6 -> V_45 ; V_53 ++ ) {
V_6 -> V_118 [ V_53 ] . V_119 = V_6 -> V_103 ;
V_6 -> V_118 [ V_53 ] . V_120 = V_6 -> V_101 ;
V_28 = F_26 ( V_6 , & V_6 -> V_118 [ V_53 ] ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 ;
V_6 -> V_123 -> V_124 = V_122 -> V_124 != 0 ;
V_6 -> V_123 -> V_125 = V_122 -> V_125 != 0 ;
V_28 = F_28 ( V_8 -> V_2 , V_6 -> V_34 ,
V_6 -> V_126 + V_127 ,
V_6 -> V_123 -> V_124 ,
V_6 -> V_123 -> V_128 ,
V_6 -> V_123 -> V_125 ,
V_6 -> V_123 -> V_129 ) ;
if ( V_28 )
F_8 ( V_6 , L_11 ) ;
return V_28 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_122 -> V_124 = V_6 -> V_123 -> V_124 ;
V_122 -> V_125 = V_6 -> V_123 -> V_125 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_132 , V_133 ;
int V_134 = 0 ;
int V_28 = 0 ;
if ( V_131 -> V_135 || V_131 -> V_136 )
return - V_39 ;
V_132 = F_31 ( V_131 -> V_137 ) ;
V_132 = F_32 ( T_1 , V_132 , V_138 ) ;
V_132 = F_33 ( T_1 , V_132 , V_139 ) ;
V_133 = F_31 ( V_131 -> V_140 ) ;
V_133 = F_32 ( T_1 , V_133 , V_141 ) ;
V_133 = F_33 ( T_1 , V_133 , V_142 ) ;
if ( V_132 == ( V_6 -> V_134 ? V_6 -> V_61 [ 0 ] . V_143 :
V_6 -> V_61 [ 0 ] . V_144 ) &&
V_133 == V_6 -> V_58 [ 0 ] . V_144 )
return 0 ;
F_34 ( & V_8 -> V_145 ) ;
if ( V_6 -> V_134 ) {
V_134 = 1 ;
F_35 ( V_2 ) ;
}
F_36 ( V_6 , true ) ;
V_6 -> V_123 -> V_146 = V_133 ;
V_6 -> V_123 -> V_147 = V_132 ;
V_28 = F_37 ( V_6 ) ;
if ( V_28 ) {
F_8 ( V_6 , L_12 ) ;
goto V_148;
}
if ( V_134 ) {
V_28 = F_38 ( V_2 ) ;
if ( V_28 )
F_8 ( V_6 , L_13 ) ;
}
V_148:
F_39 ( & V_8 -> V_145 ) ;
return V_28 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
memset ( V_131 , 0 , sizeof( * V_131 ) ) ;
V_131 -> V_149 = V_139 ;
V_131 -> V_150 = V_142 ;
V_131 -> V_137 = V_6 -> V_134 ?
V_6 -> V_61 [ 0 ] . V_143 : V_6 -> V_61 [ 0 ] . V_144 ;
V_131 -> V_140 = V_6 -> V_58 [ 0 ] . V_144 ;
}
