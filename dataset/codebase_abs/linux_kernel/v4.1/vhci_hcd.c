static void F_1 ( T_1 V_1 , T_1 V_2 )
{
int V_3 = 0 ;
T_1 V_4 = 1 ;
F_2 ( L_1 , V_1 , V_2 ) ;
while ( V_4 ) {
T_1 V_5 = V_1 & V_4 ;
T_1 V_6 = V_2 & V_4 ;
char V_7 ;
if ( ! V_5 && V_6 )
V_7 = '+' ;
else if ( V_5 && ! V_6 )
V_7 = '-' ;
else
V_7 = ' ' ;
if ( V_5 || V_6 )
F_2 ( L_2 , V_7 , V_8 [ V_3 ] ) ;
V_4 <<= 1 ;
V_3 ++ ;
}
F_2 ( L_3 ) ;
}
void F_3 ( int V_9 , enum V_10 V_11 )
{
F_4 ( L_4 , V_9 ) ;
F_5 ( & V_12 -> V_13 ) ;
V_12 -> V_14 [ V_9 ] |= V_15
| ( 1 << V_16 ) ;
switch ( V_11 ) {
case V_17 :
V_12 -> V_14 [ V_9 ] |= V_18 ;
break;
case V_19 :
V_12 -> V_14 [ V_9 ] |= V_20 ;
break;
default:
break;
}
F_6 ( & V_12 -> V_13 ) ;
F_7 ( F_8 ( V_12 ) ) ;
}
static void F_9 ( int V_9 )
{
F_4 ( L_5 , V_9 ) ;
F_5 ( & V_12 -> V_13 ) ;
V_12 -> V_14 [ V_9 ] &= ~ V_15 ;
V_12 -> V_14 [ V_9 ] |=
( 1 << V_16 ) ;
F_6 ( & V_12 -> V_13 ) ;
F_7 ( F_8 ( V_12 ) ) ;
}
static int F_10 ( struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_25 ;
int V_26 ;
int V_9 ;
int V_27 = 0 ;
V_26 = F_11 ( V_28 + 1 , 8 ) ;
memset ( V_23 , 0 , V_26 ) ;
V_25 = F_12 ( V_22 ) ;
F_5 ( & V_25 -> V_13 ) ;
if ( ! F_13 ( V_22 ) ) {
F_4 ( L_6 ) ;
goto V_29;
}
for ( V_9 = 0 ; V_9 < V_28 ; V_9 ++ ) {
if ( ( V_25 -> V_14 [ V_9 ] & V_30 ) ) {
F_4 ( L_7 , V_9 ) ;
V_23 [ ( V_9 + 1 ) / 8 ] |= 1 << ( V_9 + 1 ) % 8 ;
V_27 = 1 ;
}
}
if ( ( V_22 -> V_31 == V_32 ) && ( V_27 == 1 ) )
F_14 ( V_22 ) ;
V_29:
F_6 ( & V_25 -> V_13 ) ;
return V_27 ? V_26 : 0 ;
}
static inline void F_15 ( struct V_33 * V_34 )
{
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_35 = V_36 ;
V_34 -> V_37 = 9 ;
V_34 -> V_38 = F_16 (
V_39 | V_40 ) ;
V_34 -> V_41 = V_28 ;
V_34 -> V_42 . V_43 . V_44 [ 0 ] = 0xff ;
V_34 -> V_42 . V_43 . V_44 [ 1 ] = 0xff ;
}
static int F_17 ( struct V_21 * V_22 , T_2 V_45 , T_2 V_46 ,
T_2 V_47 , char * V_23 , T_2 V_48 )
{
struct V_24 * V_49 ;
int V_26 = 0 ;
int V_9 ;
T_1 V_50 [ V_28 ] ;
if ( ! F_13 ( V_22 ) )
return - V_51 ;
F_4 ( L_8 , V_45 , V_46 ,
V_47 ) ;
if ( V_47 > V_28 )
F_18 ( L_9 , V_47 ) ;
V_9 = ( ( V_52 ) ( V_47 & 0x00ff ) ) - 1 ;
V_49 = F_12 ( V_22 ) ;
F_5 ( & V_49 -> V_13 ) ;
if ( V_53 ) {
memcpy ( V_50 , V_49 -> V_14 ,
sizeof( V_50 ) ) ;
}
switch ( V_45 ) {
case V_54 :
F_4 ( L_10 ) ;
break;
case V_55 :
switch ( V_46 ) {
case V_56 :
if ( V_49 -> V_14 [ V_9 ] & V_57 ) {
V_49 -> V_58 = 1 ;
V_49 -> V_59 =
V_60 + F_19 ( 20 ) ;
}
break;
case V_61 :
F_4 (
L_11 ) ;
V_49 -> V_14 [ V_9 ] = 0 ;
V_49 -> V_58 = 0 ;
break;
case V_62 :
F_4 (
L_12 ) ;
switch ( V_49 -> V_63 [ V_9 ] . V_11 ) {
case V_17 :
V_49 -> V_14 [ V_9 ] |=
V_18 ;
break;
case V_19 :
V_49 -> V_14 [ V_9 ] |=
V_20 ;
break;
default:
break;
}
default:
F_4 ( L_13 ,
V_46 ) ;
V_49 -> V_14 [ V_9 ] &= ~ ( 1 << V_46 ) ;
break;
}
break;
case V_64 :
F_4 ( L_14 ) ;
F_15 ( (struct V_33 * ) V_23 ) ;
break;
case V_65 :
F_4 ( L_15 ) ;
* ( V_66 * ) V_23 = F_20 ( 0 ) ;
break;
case V_67 :
F_4 ( L_16 , V_47 ) ;
if ( V_47 > V_28 || V_47 < 1 ) {
F_18 ( L_9 , V_47 ) ;
V_26 = - V_68 ;
}
if ( V_49 -> V_58 && F_21 ( V_60 , V_49 -> V_59 ) ) {
V_49 -> V_14 [ V_9 ] |=
( 1 << V_69 ) ;
V_49 -> V_14 [ V_9 ] &=
~ ( 1 << V_56 ) ;
V_49 -> V_58 = 0 ;
V_49 -> V_59 = 0 ;
}
if ( ( V_49 -> V_14 [ V_9 ] & ( 1 << V_70 ) ) !=
0 && F_21 ( V_60 , V_49 -> V_59 ) ) {
V_49 -> V_14 [ V_9 ] |=
( 1 << V_62 ) ;
V_49 -> V_14 [ V_9 ] &=
~ ( 1 << V_70 ) ;
V_49 -> V_59 = 0 ;
if ( V_49 -> V_63 [ V_9 ] . V_71 . V_72 ==
V_73 ) {
F_4 (
L_17 ,
V_9 ,
V_49 -> V_63 [ V_9 ] . V_71 . V_72 ) ;
V_49 -> V_14 [ V_9 ] |=
V_74 ;
}
}
( ( V_75 * ) V_23 ) [ 0 ] = F_22 ( V_49 -> V_14 [ V_9 ] ) ;
( ( V_75 * ) V_23 ) [ 1 ] =
F_22 ( V_49 -> V_14 [ V_9 ] >> 16 ) ;
F_4 ( L_18 , ( ( T_2 * ) V_23 ) [ 0 ] ,
( ( T_2 * ) V_23 ) [ 1 ] ) ;
break;
case V_76 :
F_4 ( L_19 ) ;
V_26 = - V_68 ;
break;
case V_77 :
switch ( V_46 ) {
case V_56 :
F_4 (
L_20 ) ;
break;
case V_70 :
F_4 (
L_21 ) ;
if ( V_49 -> V_14 [ V_9 ] & V_74 ) {
V_49 -> V_14 [ V_9 ] &=
~ ( V_74 |
V_20 |
V_18 ) ;
}
V_49 -> V_59 = V_60 + F_19 ( 50 ) ;
default:
F_4 ( L_22 ,
V_46 ) ;
V_49 -> V_14 [ V_9 ] |= ( 1 << V_46 ) ;
break;
}
break;
default:
F_18 ( L_23 ) ;
V_26 = - V_68 ;
}
if ( V_53 ) {
F_2 ( L_24 , V_9 ) ;
if ( V_9 >= 0 ) {
F_1 ( V_50 [ V_9 ] ,
V_49 -> V_14 [ V_9 ] ) ;
}
}
F_4 ( L_25 ) ;
F_6 ( & V_49 -> V_13 ) ;
return V_26 ;
}
static struct V_78 * F_23 ( struct V_79 * V_80 )
{
int V_3 ;
if ( ! V_80 )
return NULL ;
for ( V_3 = 0 ; V_3 < V_28 ; V_3 ++ )
if ( V_12 -> V_63 [ V_3 ] . V_80 == V_80 )
return F_24 ( V_3 ) ;
return NULL ;
}
static void F_25 ( struct V_81 * V_81 )
{
struct V_78 * V_63 = F_23 ( V_81 -> V_82 ) ;
struct V_83 * V_84 ;
if ( ! V_63 ) {
F_18 ( L_26 ) ;
return;
}
V_84 = F_26 ( sizeof( struct V_83 ) , V_85 ) ;
if ( ! V_84 ) {
F_27 ( & V_63 -> V_71 , V_86 ) ;
return;
}
F_5 ( & V_63 -> V_87 ) ;
V_84 -> V_88 = F_28 ( & V_12 -> V_88 ) ;
if ( V_84 -> V_88 == 0xffff )
F_29 ( & V_81 -> V_82 -> V_82 , L_27 ) ;
V_84 -> V_63 = V_63 ;
V_84 -> V_81 = V_81 ;
V_81 -> V_89 = ( void * ) V_84 ;
F_30 ( & V_84 -> V_90 , & V_63 -> V_91 ) ;
F_31 ( & V_63 -> V_92 ) ;
F_6 ( & V_63 -> V_87 ) ;
}
static int F_32 ( struct V_21 * V_22 , struct V_81 * V_81 ,
T_3 V_93 )
{
struct V_94 * V_82 = & V_81 -> V_82 -> V_82 ;
int V_95 = 0 ;
struct V_78 * V_63 ;
F_33 ( L_28 ,
V_22 , V_81 , V_93 ) ;
F_34 ( ! V_81 -> V_96 && V_81 -> V_97 ) ;
F_5 ( & V_12 -> V_13 ) ;
if ( V_81 -> V_72 != - V_98 ) {
F_35 ( V_82 , L_29 , V_81 -> V_72 ) ;
F_6 ( & V_12 -> V_13 ) ;
return V_81 -> V_72 ;
}
V_63 = F_24 ( V_81 -> V_82 -> V_99 - 1 ) ;
F_5 ( & V_63 -> V_71 . V_13 ) ;
if ( V_63 -> V_71 . V_72 == V_100 ||
V_63 -> V_71 . V_72 == V_101 ) {
F_35 ( V_82 , L_30 , V_63 -> V_9 ) ;
F_6 ( & V_63 -> V_71 . V_13 ) ;
F_6 ( & V_12 -> V_13 ) ;
return - V_102 ;
}
F_6 ( & V_63 -> V_71 . V_13 ) ;
V_95 = F_36 ( V_22 , V_81 ) ;
if ( V_95 )
goto V_103;
if ( F_37 ( V_81 -> V_104 ) == 0 ) {
V_52 type = F_38 ( V_81 -> V_104 ) ;
struct V_105 * V_106 =
(struct V_105 * ) V_81 -> V_107 ;
if ( type != V_108 || ! V_106 ) {
F_35 ( V_82 , L_31 ) ;
V_95 = - V_109 ;
goto V_110;
}
switch ( V_106 -> V_111 ) {
case V_112 :
F_29 ( V_82 , L_32 ,
V_106 -> V_46 , V_63 -> V_9 ) ;
F_39 ( V_63 -> V_80 ) ;
V_63 -> V_80 = F_40 ( V_81 -> V_82 ) ;
F_5 ( & V_63 -> V_71 . V_13 ) ;
V_63 -> V_71 . V_72 = V_113 ;
F_6 ( & V_63 -> V_71 . V_13 ) ;
if ( V_81 -> V_72 == - V_98 ) {
V_81 -> V_72 = 0 ;
}
goto V_110;
case V_114 :
if ( V_106 -> V_46 == F_22 ( V_115 << 8 ) )
F_33 (
L_33 ) ;
F_39 ( V_63 -> V_80 ) ;
V_63 -> V_80 = F_40 ( V_81 -> V_82 ) ;
goto V_116;
default:
F_35 ( V_82 ,
L_34 ,
V_106 -> V_111 ,
V_106 -> V_46 ) ;
V_95 = - V_109 ;
goto V_110;
}
}
V_116:
F_25 ( V_81 ) ;
F_6 ( & V_12 -> V_13 ) ;
return 0 ;
V_110:
F_41 ( V_22 , V_81 ) ;
V_103:
F_6 ( & V_12 -> V_13 ) ;
F_42 ( F_8 ( V_12 ) , V_81 , V_81 -> V_72 ) ;
return V_95 ;
}
static int F_43 ( struct V_21 * V_22 , struct V_81 * V_81 , int V_72 )
{
struct V_83 * V_84 ;
struct V_78 * V_63 ;
F_44 ( L_35 , V_81 ) ;
F_5 ( & V_12 -> V_13 ) ;
V_84 = V_81 -> V_89 ;
if ( ! V_84 ) {
F_6 ( & V_12 -> V_13 ) ;
return 0 ;
}
{
int V_95 = 0 ;
V_95 = F_45 ( V_22 , V_81 , V_72 ) ;
if ( V_95 ) {
F_6 ( & V_12 -> V_13 ) ;
return V_95 ;
}
}
V_63 = V_84 -> V_63 ;
if ( ! V_63 -> V_71 . V_117 ) {
F_5 ( & V_63 -> V_87 ) ;
F_44 ( L_36 , V_63 ) ;
F_46 ( & V_84 -> V_90 ) ;
F_47 ( V_84 ) ;
V_81 -> V_89 = NULL ;
F_6 ( & V_63 -> V_87 ) ;
F_44 ( L_37 , V_81 ) ;
F_41 ( V_22 , V_81 ) ;
F_6 ( & V_12 -> V_13 ) ;
F_42 ( F_8 ( V_12 ) , V_81 ,
V_81 -> V_72 ) ;
F_5 ( & V_12 -> V_13 ) ;
} else {
struct V_118 * V_119 ;
F_5 ( & V_63 -> V_87 ) ;
V_119 = F_26 ( sizeof( struct V_118 ) , V_85 ) ;
if ( ! V_119 ) {
F_6 ( & V_63 -> V_87 ) ;
F_6 ( & V_12 -> V_13 ) ;
F_27 ( & V_63 -> V_71 , V_86 ) ;
return - V_120 ;
}
V_119 -> V_88 = F_28 ( & V_12 -> V_88 ) ;
if ( V_119 -> V_88 == 0xffff )
F_44 ( L_27 ) ;
V_119 -> V_121 = V_84 -> V_88 ;
F_44 ( L_38 , V_63 ) ;
F_30 ( & V_119 -> V_90 , & V_63 -> V_122 ) ;
F_31 ( & V_63 -> V_92 ) ;
F_6 ( & V_63 -> V_87 ) ;
}
F_6 ( & V_12 -> V_13 ) ;
F_33 ( L_39 ) ;
return 0 ;
}
static void F_48 ( struct V_78 * V_63 )
{
struct V_118 * V_119 , * V_123 ;
F_5 ( & V_12 -> V_13 ) ;
F_5 ( & V_63 -> V_87 ) ;
F_49 (unlink, tmp, &vdev->unlink_tx, list) {
F_44 ( L_40 , V_119 -> V_121 ) ;
F_46 ( & V_119 -> V_90 ) ;
F_47 ( V_119 ) ;
}
while ( ! F_50 ( & V_63 -> V_124 ) ) {
struct V_81 * V_81 ;
V_119 = F_51 ( & V_63 -> V_124 , struct V_118 ,
V_90 ) ;
F_44 ( L_41 , V_119 -> V_121 ) ;
V_81 = F_52 ( V_63 , V_119 -> V_121 ) ;
if ( ! V_81 ) {
F_44 ( L_42 ,
V_119 -> V_121 ) ;
F_46 ( & V_119 -> V_90 ) ;
F_47 ( V_119 ) ;
continue;
}
V_81 -> V_72 = - V_102 ;
F_41 ( F_8 ( V_12 ) , V_81 ) ;
F_46 ( & V_119 -> V_90 ) ;
F_6 ( & V_63 -> V_87 ) ;
F_6 ( & V_12 -> V_13 ) ;
F_42 ( F_8 ( V_12 ) , V_81 ,
V_81 -> V_72 ) ;
F_5 ( & V_12 -> V_13 ) ;
F_5 ( & V_63 -> V_87 ) ;
F_47 ( V_119 ) ;
}
F_6 ( & V_63 -> V_87 ) ;
F_6 ( & V_12 -> V_13 ) ;
}
static void F_53 ( struct V_125 * V_71 )
{
struct V_78 * V_63 = F_54 ( V_71 , struct V_78 , V_71 ) ;
if ( V_71 -> V_117 ) {
F_2 ( L_43 , V_71 -> V_117 ) ;
F_55 ( V_71 -> V_117 , V_126 ) ;
}
if ( V_63 -> V_71 . V_127 ) {
F_56 ( V_63 -> V_71 . V_127 ) ;
V_63 -> V_71 . V_127 = NULL ;
}
if ( V_63 -> V_71 . V_128 ) {
F_56 ( V_63 -> V_71 . V_128 ) ;
V_63 -> V_71 . V_128 = NULL ;
}
F_44 ( L_44 ) ;
if ( V_63 -> V_71 . V_117 ) {
F_57 ( V_63 -> V_71 . V_117 ) ;
V_63 -> V_71 . V_117 = NULL ;
}
F_44 ( L_45 ) ;
F_48 ( V_63 ) ;
F_9 ( V_63 -> V_9 ) ;
F_44 ( L_46 ) ;
}
static void F_58 ( struct V_125 * V_71 )
{
struct V_78 * V_63 = F_54 ( V_71 , struct V_78 , V_71 ) ;
F_5 ( & V_71 -> V_13 ) ;
V_63 -> V_11 = 0 ;
V_63 -> V_129 = 0 ;
F_39 ( V_63 -> V_80 ) ;
V_63 -> V_80 = NULL ;
if ( V_71 -> V_117 ) {
F_57 ( V_71 -> V_117 ) ;
V_71 -> V_117 = NULL ;
}
V_71 -> V_72 = V_100 ;
F_6 ( & V_71 -> V_13 ) ;
}
static void F_59 ( struct V_125 * V_71 )
{
F_5 ( & V_71 -> V_13 ) ;
V_71 -> V_72 = V_101 ;
F_6 ( & V_71 -> V_13 ) ;
}
static void F_60 ( struct V_78 * V_63 )
{
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_71 . V_130 = V_131 ;
V_63 -> V_71 . V_72 = V_100 ;
F_61 ( & V_63 -> V_71 . V_13 ) ;
F_62 ( & V_63 -> V_132 ) ;
F_62 ( & V_63 -> V_91 ) ;
F_62 ( & V_63 -> V_122 ) ;
F_62 ( & V_63 -> V_124 ) ;
F_61 ( & V_63 -> V_87 ) ;
F_63 ( & V_63 -> V_92 ) ;
V_63 -> V_71 . V_133 . V_134 = F_53 ;
V_63 -> V_71 . V_133 . V_135 = F_58 ;
V_63 -> V_71 . V_133 . V_136 = F_59 ;
F_64 ( & V_63 -> V_71 ) ;
}
static int F_65 ( struct V_21 * V_22 )
{
struct V_24 * V_25 = F_12 ( V_22 ) ;
int V_9 ;
int V_137 = 0 ;
F_33 ( L_47 ) ;
for ( V_9 = 0 ; V_9 < V_28 ; V_9 ++ ) {
struct V_78 * V_63 = & V_25 -> V_63 [ V_9 ] ;
F_60 ( V_63 ) ;
V_63 -> V_9 = V_9 ;
}
F_66 ( & V_25 -> V_88 , 0 ) ;
F_61 ( & V_25 -> V_13 ) ;
V_22 -> V_138 = 0 ;
V_22 -> V_139 = 1 ;
V_137 = F_67 ( & F_68 ( V_25 ) -> V_140 , & V_141 ) ;
if ( V_137 ) {
F_18 ( L_48 ) ;
return V_137 ;
}
return 0 ;
}
static void F_69 ( struct V_21 * V_22 )
{
struct V_24 * V_25 = F_12 ( V_22 ) ;
int V_9 = 0 ;
F_33 ( L_49 ) ;
F_70 ( & F_68 ( V_25 ) -> V_140 , & V_141 ) ;
for ( V_9 = 0 ; V_9 < V_28 ; V_9 ++ ) {
struct V_78 * V_63 = & V_25 -> V_63 [ V_9 ] ;
F_27 ( & V_63 -> V_71 , V_142 ) ;
F_71 ( & V_63 -> V_71 ) ;
}
}
static int F_72 ( struct V_21 * V_22 )
{
F_18 ( L_50 ) ;
return 0 ;
}
static int F_73 ( struct V_21 * V_22 )
{
struct V_24 * V_25 = F_12 ( V_22 ) ;
F_74 ( & V_22 -> V_143 . V_144 -> V_82 , L_51 , V_145 ) ;
F_5 ( & V_25 -> V_13 ) ;
V_22 -> V_31 = V_32 ;
F_6 ( & V_25 -> V_13 ) ;
return 0 ;
}
static int F_75 ( struct V_21 * V_22 )
{
struct V_24 * V_25 = F_12 ( V_22 ) ;
int V_146 = 0 ;
F_74 ( & V_22 -> V_143 . V_144 -> V_82 , L_51 , V_145 ) ;
F_5 ( & V_25 -> V_13 ) ;
if ( ! F_13 ( V_22 ) )
V_146 = - V_147 ;
else
V_22 -> V_31 = V_148 ;
F_6 ( & V_25 -> V_13 ) ;
return V_146 ;
}
static int F_76 ( struct V_149 * V_150 )
{
struct V_21 * V_22 ;
int V_95 ;
F_33 ( L_52 , V_150 -> V_151 , V_150 -> V_152 ) ;
V_22 = F_77 ( & V_153 , & V_150 -> V_82 , F_78 ( & V_150 -> V_82 ) ) ;
if ( ! V_22 ) {
F_18 ( L_53 ) ;
return - V_120 ;
}
V_22 -> V_154 = 1 ;
V_12 = F_12 ( V_22 ) ;
V_95 = F_79 ( V_22 , 0 , 0 ) ;
if ( V_95 != 0 ) {
F_18 ( L_54 , V_95 ) ;
F_80 ( V_22 ) ;
V_12 = NULL ;
return V_95 ;
}
F_33 ( L_55 ) ;
return 0 ;
}
static int F_81 ( struct V_149 * V_150 )
{
struct V_21 * V_22 ;
V_22 = F_82 ( V_150 ) ;
if ( ! V_22 )
return 0 ;
F_83 ( V_22 ) ;
F_80 ( V_22 ) ;
V_12 = NULL ;
return 0 ;
}
static int F_84 ( struct V_149 * V_150 , T_4 V_31 )
{
struct V_21 * V_22 ;
int V_9 = 0 ;
int V_155 = 0 ;
int V_95 = 0 ;
V_22 = F_82 ( V_150 ) ;
F_5 ( & V_12 -> V_13 ) ;
for ( V_9 = 0 ; V_9 < V_28 ; V_9 ++ )
if ( V_12 -> V_14 [ V_9 ] &
V_15 )
V_155 += 1 ;
F_6 ( & V_12 -> V_13 ) ;
if ( V_155 > 0 ) {
F_29 ( & V_150 -> V_82 ,
L_56 ,
V_155 , ( V_155 == 1 ? L_57 : L_58 ) ) ;
V_95 = - V_156 ;
} else {
F_29 ( & V_150 -> V_82 , L_59 ) ;
F_85 ( V_157 , & V_22 -> V_158 ) ;
}
return V_95 ;
}
static int F_86 ( struct V_149 * V_150 )
{
struct V_21 * V_22 ;
F_74 ( & V_150 -> V_82 , L_51 , V_145 ) ;
V_22 = F_82 ( V_150 ) ;
F_87 ( V_157 , & V_22 -> V_158 ) ;
F_7 ( V_22 ) ;
return 0 ;
}
static void F_88 ( struct V_94 * V_82 )
{
}
static int T_5 F_89 ( void )
{
int V_95 ;
if ( F_90 () )
return - V_102 ;
V_95 = F_91 ( & V_159 ) ;
if ( V_95 )
goto V_160;
V_95 = F_92 ( & V_161 ) ;
if ( V_95 )
goto V_162;
F_44 ( V_163 L_60 V_164 L_3 ) ;
return V_95 ;
V_162:
F_93 ( & V_159 ) ;
V_160:
return V_95 ;
}
static void T_6 F_94 ( void )
{
F_95 ( & V_161 ) ;
F_93 ( & V_159 ) ;
}
