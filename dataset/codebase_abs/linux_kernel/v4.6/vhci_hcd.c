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
unsigned long V_12 ;
F_4 ( L_4 , V_9 ) ;
F_5 ( & V_13 -> V_14 , V_12 ) ;
V_13 -> V_15 [ V_9 ] |= V_16
| ( 1 << V_17 ) ;
switch ( V_11 ) {
case V_18 :
V_13 -> V_15 [ V_9 ] |= V_19 ;
break;
case V_20 :
V_13 -> V_15 [ V_9 ] |= V_21 ;
break;
default:
break;
}
F_6 ( & V_13 -> V_14 , V_12 ) ;
F_7 ( F_8 ( V_13 ) ) ;
}
static void F_9 ( int V_9 )
{
unsigned long V_12 ;
F_4 ( L_5 , V_9 ) ;
F_5 ( & V_13 -> V_14 , V_12 ) ;
V_13 -> V_15 [ V_9 ] &= ~ V_16 ;
V_13 -> V_15 [ V_9 ] |=
( 1 << V_17 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
F_7 ( F_8 ( V_13 ) ) ;
}
static int F_10 ( struct V_22 * V_23 , char * V_24 )
{
struct V_25 * V_26 ;
int V_27 ;
int V_9 ;
int V_28 = 0 ;
unsigned long V_12 ;
V_27 = F_11 ( V_29 + 1 , 8 ) ;
memset ( V_24 , 0 , V_27 ) ;
V_26 = F_12 ( V_23 ) ;
F_5 ( & V_26 -> V_14 , V_12 ) ;
if ( ! F_13 ( V_23 ) ) {
F_4 ( L_6 ) ;
goto V_30;
}
for ( V_9 = 0 ; V_9 < V_29 ; V_9 ++ ) {
if ( ( V_26 -> V_15 [ V_9 ] & V_31 ) ) {
F_4 ( L_7 , V_9 ) ;
V_24 [ ( V_9 + 1 ) / 8 ] |= 1 << ( V_9 + 1 ) % 8 ;
V_28 = 1 ;
}
}
if ( ( V_23 -> V_32 == V_33 ) && ( V_28 == 1 ) )
F_14 ( V_23 ) ;
V_30:
F_6 ( & V_26 -> V_14 , V_12 ) ;
return V_28 ? V_27 : 0 ;
}
static inline void F_15 ( struct V_34 * V_35 )
{
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_36 = V_37 ;
V_35 -> V_38 = 9 ;
V_35 -> V_39 = F_16 (
V_40 | V_41 ) ;
V_35 -> V_42 = V_29 ;
V_35 -> V_43 . V_44 . V_45 [ 0 ] = 0xff ;
V_35 -> V_43 . V_44 . V_45 [ 1 ] = 0xff ;
}
static int F_17 ( struct V_22 * V_23 , T_2 V_46 , T_2 V_47 ,
T_2 V_48 , char * V_24 , T_2 V_49 )
{
struct V_25 * V_50 ;
int V_27 = 0 ;
int V_9 ;
unsigned long V_12 ;
T_1 V_51 [ V_29 ] ;
if ( ! F_13 ( V_23 ) )
return - V_52 ;
F_4 ( L_8 , V_46 , V_47 ,
V_48 ) ;
if ( V_48 > V_29 )
F_18 ( L_9 , V_48 ) ;
V_9 = ( ( V_53 ) ( V_48 & 0x00ff ) ) - 1 ;
V_50 = F_12 ( V_23 ) ;
F_5 ( & V_50 -> V_14 , V_12 ) ;
if ( V_54 ) {
memcpy ( V_51 , V_50 -> V_15 ,
sizeof( V_51 ) ) ;
}
switch ( V_46 ) {
case V_55 :
F_4 ( L_10 ) ;
break;
case V_56 :
switch ( V_47 ) {
case V_57 :
if ( V_50 -> V_15 [ V_9 ] & V_58 ) {
V_50 -> V_59 = 1 ;
V_50 -> V_60 =
V_61 + F_19 ( 20 ) ;
}
break;
case V_62 :
F_4 (
L_11 ) ;
V_50 -> V_15 [ V_9 ] = 0 ;
V_50 -> V_59 = 0 ;
break;
case V_63 :
F_4 (
L_12 ) ;
switch ( V_50 -> V_64 [ V_9 ] . V_11 ) {
case V_18 :
V_50 -> V_15 [ V_9 ] |=
V_19 ;
break;
case V_20 :
V_50 -> V_15 [ V_9 ] |=
V_21 ;
break;
default:
break;
}
default:
F_4 ( L_13 ,
V_47 ) ;
V_50 -> V_15 [ V_9 ] &= ~ ( 1 << V_47 ) ;
break;
}
break;
case V_65 :
F_4 ( L_14 ) ;
F_15 ( (struct V_34 * ) V_24 ) ;
break;
case V_66 :
F_4 ( L_15 ) ;
* ( V_67 * ) V_24 = F_20 ( 0 ) ;
break;
case V_68 :
F_4 ( L_16 , V_48 ) ;
if ( V_48 > V_29 || V_48 < 1 ) {
F_18 ( L_9 , V_48 ) ;
V_27 = - V_69 ;
}
if ( V_50 -> V_59 && F_21 ( V_61 , V_50 -> V_60 ) ) {
V_50 -> V_15 [ V_9 ] |=
( 1 << V_70 ) ;
V_50 -> V_15 [ V_9 ] &=
~ ( 1 << V_57 ) ;
V_50 -> V_59 = 0 ;
V_50 -> V_60 = 0 ;
}
if ( ( V_50 -> V_15 [ V_9 ] & ( 1 << V_71 ) ) !=
0 && F_21 ( V_61 , V_50 -> V_60 ) ) {
V_50 -> V_15 [ V_9 ] |=
( 1 << V_63 ) ;
V_50 -> V_15 [ V_9 ] &=
~ ( 1 << V_71 ) ;
V_50 -> V_60 = 0 ;
if ( V_50 -> V_64 [ V_9 ] . V_72 . V_73 ==
V_74 ) {
F_4 (
L_17 ,
V_9 ,
V_50 -> V_64 [ V_9 ] . V_72 . V_73 ) ;
V_50 -> V_15 [ V_9 ] |=
V_75 ;
}
}
( ( V_76 * ) V_24 ) [ 0 ] = F_16 ( V_50 -> V_15 [ V_9 ] ) ;
( ( V_76 * ) V_24 ) [ 1 ] =
F_16 ( V_50 -> V_15 [ V_9 ] >> 16 ) ;
F_4 ( L_18 , ( ( T_2 * ) V_24 ) [ 0 ] ,
( ( T_2 * ) V_24 ) [ 1 ] ) ;
break;
case V_77 :
F_4 ( L_19 ) ;
V_27 = - V_69 ;
break;
case V_78 :
switch ( V_47 ) {
case V_57 :
F_4 (
L_20 ) ;
break;
case V_71 :
F_4 (
L_21 ) ;
if ( V_50 -> V_15 [ V_9 ] & V_75 ) {
V_50 -> V_15 [ V_9 ] &=
~ ( V_75 |
V_21 |
V_19 ) ;
}
V_50 -> V_60 = V_61 + F_19 ( 50 ) ;
default:
F_4 ( L_22 ,
V_47 ) ;
V_50 -> V_15 [ V_9 ] |= ( 1 << V_47 ) ;
break;
}
break;
default:
F_18 ( L_23 ) ;
V_27 = - V_69 ;
}
if ( V_54 ) {
F_2 ( L_24 , V_9 ) ;
if ( V_9 >= 0 ) {
F_1 ( V_51 [ V_9 ] ,
V_50 -> V_15 [ V_9 ] ) ;
}
}
F_4 ( L_25 ) ;
F_6 ( & V_50 -> V_14 , V_12 ) ;
return V_27 ;
}
static struct V_79 * F_22 ( struct V_80 * V_81 )
{
int V_3 ;
if ( ! V_81 )
return NULL ;
for ( V_3 = 0 ; V_3 < V_29 ; V_3 ++ )
if ( V_13 -> V_64 [ V_3 ] . V_81 == V_81 )
return F_23 ( V_3 ) ;
return NULL ;
}
static void F_24 ( struct V_82 * V_82 )
{
struct V_79 * V_64 = F_22 ( V_82 -> V_83 ) ;
struct V_84 * V_85 ;
unsigned long V_12 ;
if ( ! V_64 ) {
F_18 ( L_26 ) ;
return;
}
V_85 = F_25 ( sizeof( struct V_84 ) , V_86 ) ;
if ( ! V_85 ) {
F_26 ( & V_64 -> V_72 , V_87 ) ;
return;
}
F_5 ( & V_64 -> V_88 , V_12 ) ;
V_85 -> V_89 = F_27 ( & V_13 -> V_89 ) ;
if ( V_85 -> V_89 == 0xffff )
F_28 ( & V_82 -> V_83 -> V_83 , L_27 ) ;
V_85 -> V_64 = V_64 ;
V_85 -> V_82 = V_82 ;
V_82 -> V_90 = ( void * ) V_85 ;
F_29 ( & V_85 -> V_91 , & V_64 -> V_92 ) ;
F_30 ( & V_64 -> V_93 ) ;
F_6 ( & V_64 -> V_88 , V_12 ) ;
}
static int F_31 ( struct V_22 * V_23 , struct V_82 * V_82 ,
T_3 V_94 )
{
struct V_95 * V_83 = & V_82 -> V_83 -> V_83 ;
int V_96 = 0 ;
struct V_79 * V_64 ;
unsigned long V_12 ;
F_32 ( L_28 ,
V_23 , V_82 , V_94 ) ;
F_33 ( ! V_82 -> V_97 && V_82 -> V_98 ) ;
F_5 ( & V_13 -> V_14 , V_12 ) ;
if ( V_82 -> V_73 != - V_99 ) {
F_34 ( V_83 , L_29 , V_82 -> V_73 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
return V_82 -> V_73 ;
}
V_64 = F_23 ( V_82 -> V_83 -> V_100 - 1 ) ;
F_35 ( & V_64 -> V_72 . V_14 ) ;
if ( V_64 -> V_72 . V_73 == V_101 ||
V_64 -> V_72 . V_73 == V_102 ) {
F_34 ( V_83 , L_30 , V_64 -> V_9 ) ;
F_36 ( & V_64 -> V_72 . V_14 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
return - V_103 ;
}
F_36 ( & V_64 -> V_72 . V_14 ) ;
V_96 = F_37 ( V_23 , V_82 ) ;
if ( V_96 )
goto V_104;
if ( F_38 ( V_82 -> V_105 ) == 0 ) {
V_53 type = F_39 ( V_82 -> V_105 ) ;
struct V_106 * V_107 =
(struct V_106 * ) V_82 -> V_108 ;
if ( type != V_109 || ! V_107 ) {
F_34 ( V_83 , L_31 ) ;
V_96 = - V_110 ;
goto V_111;
}
switch ( V_107 -> V_112 ) {
case V_113 :
F_28 ( V_83 , L_32 ,
V_107 -> V_47 , V_64 -> V_9 ) ;
F_40 ( V_64 -> V_81 ) ;
V_64 -> V_81 = F_41 ( V_82 -> V_83 ) ;
F_35 ( & V_64 -> V_72 . V_14 ) ;
V_64 -> V_72 . V_73 = V_114 ;
F_36 ( & V_64 -> V_72 . V_14 ) ;
if ( V_82 -> V_73 == - V_99 ) {
V_82 -> V_73 = 0 ;
}
goto V_111;
case V_115 :
if ( V_107 -> V_47 == F_16 ( V_116 << 8 ) )
F_32 (
L_33 ) ;
F_40 ( V_64 -> V_81 ) ;
V_64 -> V_81 = F_41 ( V_82 -> V_83 ) ;
goto V_117;
default:
F_34 ( V_83 ,
L_34 ,
V_107 -> V_112 ,
V_107 -> V_47 ) ;
V_96 = - V_110 ;
goto V_111;
}
}
V_117:
F_24 ( V_82 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
return 0 ;
V_111:
F_42 ( V_23 , V_82 ) ;
V_104:
F_6 ( & V_13 -> V_14 , V_12 ) ;
if ( ! V_96 )
F_43 ( F_8 ( V_13 ) ,
V_82 , V_82 -> V_73 ) ;
return V_96 ;
}
static int F_44 ( struct V_22 * V_23 , struct V_82 * V_82 , int V_73 )
{
struct V_84 * V_85 ;
struct V_79 * V_64 ;
unsigned long V_12 ;
F_45 ( L_35 , V_82 ) ;
F_5 ( & V_13 -> V_14 , V_12 ) ;
V_85 = V_82 -> V_90 ;
if ( ! V_85 ) {
F_6 ( & V_13 -> V_14 , V_12 ) ;
return - V_118 ;
}
{
int V_96 = 0 ;
V_96 = F_46 ( V_23 , V_82 , V_73 ) ;
if ( V_96 ) {
F_6 ( & V_13 -> V_14 , V_12 ) ;
return V_96 ;
}
}
V_64 = V_85 -> V_64 ;
if ( ! V_64 -> V_72 . V_119 ) {
F_35 ( & V_64 -> V_88 ) ;
F_45 ( L_36 , V_64 ) ;
F_47 ( & V_85 -> V_91 ) ;
F_48 ( V_85 ) ;
V_82 -> V_90 = NULL ;
F_36 ( & V_64 -> V_88 ) ;
F_45 ( L_37 , V_82 ) ;
F_42 ( V_23 , V_82 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
F_43 ( F_8 ( V_13 ) , V_82 ,
V_82 -> V_73 ) ;
F_5 ( & V_13 -> V_14 , V_12 ) ;
} else {
struct V_120 * V_121 ;
F_35 ( & V_64 -> V_88 ) ;
V_121 = F_25 ( sizeof( struct V_120 ) , V_86 ) ;
if ( ! V_121 ) {
F_36 ( & V_64 -> V_88 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
F_26 ( & V_64 -> V_72 , V_87 ) ;
return - V_122 ;
}
V_121 -> V_89 = F_27 ( & V_13 -> V_89 ) ;
if ( V_121 -> V_89 == 0xffff )
F_45 ( L_27 ) ;
V_121 -> V_123 = V_85 -> V_89 ;
F_45 ( L_38 , V_64 ) ;
F_29 ( & V_121 -> V_91 , & V_64 -> V_124 ) ;
F_30 ( & V_64 -> V_93 ) ;
F_36 ( & V_64 -> V_88 ) ;
}
F_6 ( & V_13 -> V_14 , V_12 ) ;
F_32 ( L_39 ) ;
return 0 ;
}
static void F_49 ( struct V_79 * V_64 )
{
struct V_120 * V_121 , * V_125 ;
unsigned long V_12 ;
F_5 ( & V_13 -> V_14 , V_12 ) ;
F_35 ( & V_64 -> V_88 ) ;
F_50 (unlink, tmp, &vdev->unlink_tx, list) {
F_45 ( L_40 , V_121 -> V_123 ) ;
F_47 ( & V_121 -> V_91 ) ;
F_48 ( V_121 ) ;
}
while ( ! F_51 ( & V_64 -> V_126 ) ) {
struct V_82 * V_82 ;
V_121 = F_52 ( & V_64 -> V_126 , struct V_120 ,
V_91 ) ;
F_45 ( L_41 , V_121 -> V_123 ) ;
V_82 = F_53 ( V_64 , V_121 -> V_123 ) ;
if ( ! V_82 ) {
F_45 ( L_42 ,
V_121 -> V_123 ) ;
F_47 ( & V_121 -> V_91 ) ;
F_48 ( V_121 ) ;
continue;
}
V_82 -> V_73 = - V_103 ;
F_42 ( F_8 ( V_13 ) , V_82 ) ;
F_47 ( & V_121 -> V_91 ) ;
F_36 ( & V_64 -> V_88 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
F_43 ( F_8 ( V_13 ) , V_82 ,
V_82 -> V_73 ) ;
F_5 ( & V_13 -> V_14 , V_12 ) ;
F_35 ( & V_64 -> V_88 ) ;
F_48 ( V_121 ) ;
}
F_36 ( & V_64 -> V_88 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
}
static void F_54 ( struct V_127 * V_72 )
{
struct V_79 * V_64 = F_55 ( V_72 , struct V_79 , V_72 ) ;
if ( V_72 -> V_119 ) {
F_2 ( L_43 , V_72 -> V_119 ) ;
F_56 ( V_72 -> V_119 , V_128 ) ;
}
if ( V_64 -> V_72 . V_129 ) {
F_57 ( V_64 -> V_72 . V_129 ) ;
V_64 -> V_72 . V_129 = NULL ;
}
if ( V_64 -> V_72 . V_130 ) {
F_57 ( V_64 -> V_72 . V_130 ) ;
V_64 -> V_72 . V_130 = NULL ;
}
F_45 ( L_44 ) ;
if ( V_64 -> V_72 . V_119 ) {
F_58 ( V_64 -> V_72 . V_119 ) ;
V_64 -> V_72 . V_119 = NULL ;
}
F_45 ( L_45 ) ;
F_49 ( V_64 ) ;
F_9 ( V_64 -> V_9 ) ;
F_45 ( L_46 ) ;
}
static void F_59 ( struct V_127 * V_72 )
{
struct V_79 * V_64 = F_55 ( V_72 , struct V_79 , V_72 ) ;
unsigned long V_12 ;
F_5 ( & V_72 -> V_14 , V_12 ) ;
V_64 -> V_11 = 0 ;
V_64 -> V_131 = 0 ;
F_40 ( V_64 -> V_81 ) ;
V_64 -> V_81 = NULL ;
if ( V_72 -> V_119 ) {
F_58 ( V_72 -> V_119 ) ;
V_72 -> V_119 = NULL ;
}
V_72 -> V_73 = V_101 ;
F_6 ( & V_72 -> V_14 , V_12 ) ;
}
static void F_60 ( struct V_127 * V_72 )
{
unsigned long V_12 ;
F_5 ( & V_72 -> V_14 , V_12 ) ;
V_72 -> V_73 = V_102 ;
F_6 ( & V_72 -> V_14 , V_12 ) ;
}
static void F_61 ( struct V_79 * V_64 )
{
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_64 -> V_72 . V_132 = V_133 ;
V_64 -> V_72 . V_73 = V_101 ;
F_62 ( & V_64 -> V_72 . V_14 ) ;
F_63 ( & V_64 -> V_134 ) ;
F_63 ( & V_64 -> V_92 ) ;
F_63 ( & V_64 -> V_124 ) ;
F_63 ( & V_64 -> V_126 ) ;
F_62 ( & V_64 -> V_88 ) ;
F_64 ( & V_64 -> V_93 ) ;
V_64 -> V_72 . V_135 . V_136 = F_54 ;
V_64 -> V_72 . V_135 . V_137 = F_59 ;
V_64 -> V_72 . V_135 . V_138 = F_60 ;
F_65 ( & V_64 -> V_72 ) ;
}
static int F_66 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_12 ( V_23 ) ;
int V_9 ;
int V_139 = 0 ;
F_32 ( L_47 ) ;
for ( V_9 = 0 ; V_9 < V_29 ; V_9 ++ ) {
struct V_79 * V_64 = & V_26 -> V_64 [ V_9 ] ;
F_61 ( V_64 ) ;
V_64 -> V_9 = V_9 ;
}
F_67 ( & V_26 -> V_89 , 0 ) ;
F_62 ( & V_26 -> V_14 ) ;
V_23 -> V_140 = 0 ;
V_23 -> V_141 = 1 ;
V_139 = F_68 ( & F_69 ( V_26 ) -> V_142 , & V_143 ) ;
if ( V_139 ) {
F_18 ( L_48 ) ;
return V_139 ;
}
return 0 ;
}
static void F_70 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_12 ( V_23 ) ;
int V_9 = 0 ;
F_32 ( L_49 ) ;
F_71 ( & F_69 ( V_26 ) -> V_142 , & V_143 ) ;
for ( V_9 = 0 ; V_9 < V_29 ; V_9 ++ ) {
struct V_79 * V_64 = & V_26 -> V_64 [ V_9 ] ;
F_26 ( & V_64 -> V_72 , V_144 ) ;
F_72 ( & V_64 -> V_72 ) ;
}
}
static int F_73 ( struct V_22 * V_23 )
{
F_18 ( L_50 ) ;
return 0 ;
}
static int F_74 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_12 ( V_23 ) ;
unsigned long V_12 ;
F_75 ( & V_23 -> V_145 . V_146 -> V_83 , L_51 , V_147 ) ;
F_5 ( & V_26 -> V_14 , V_12 ) ;
V_23 -> V_32 = V_33 ;
F_6 ( & V_26 -> V_14 , V_12 ) ;
return 0 ;
}
static int F_76 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_12 ( V_23 ) ;
int V_148 = 0 ;
unsigned long V_12 ;
F_75 ( & V_23 -> V_145 . V_146 -> V_83 , L_51 , V_147 ) ;
F_5 ( & V_26 -> V_14 , V_12 ) ;
if ( ! F_13 ( V_23 ) )
V_148 = - V_149 ;
else
V_23 -> V_32 = V_150 ;
F_6 ( & V_26 -> V_14 , V_12 ) ;
return V_148 ;
}
static int F_77 ( struct V_151 * V_152 )
{
struct V_22 * V_23 ;
int V_96 ;
F_32 ( L_52 , V_152 -> V_153 , V_152 -> V_154 ) ;
V_23 = F_78 ( & V_155 , & V_152 -> V_83 , F_79 ( & V_152 -> V_83 ) ) ;
if ( ! V_23 ) {
F_18 ( L_53 ) ;
return - V_122 ;
}
V_23 -> V_156 = 1 ;
V_13 = F_12 ( V_23 ) ;
V_96 = F_80 ( V_23 , 0 , 0 ) ;
if ( V_96 != 0 ) {
F_18 ( L_54 , V_96 ) ;
F_81 ( V_23 ) ;
V_13 = NULL ;
return V_96 ;
}
F_32 ( L_55 ) ;
return 0 ;
}
static int F_82 ( struct V_151 * V_152 )
{
struct V_22 * V_23 ;
V_23 = F_83 ( V_152 ) ;
if ( ! V_23 )
return 0 ;
F_84 ( V_23 ) ;
F_81 ( V_23 ) ;
V_13 = NULL ;
return 0 ;
}
static int F_85 ( struct V_151 * V_152 , T_4 V_32 )
{
struct V_22 * V_23 ;
int V_9 = 0 ;
int V_157 = 0 ;
int V_96 = 0 ;
unsigned long V_12 ;
V_23 = F_83 ( V_152 ) ;
F_5 ( & V_13 -> V_14 , V_12 ) ;
for ( V_9 = 0 ; V_9 < V_29 ; V_9 ++ )
if ( V_13 -> V_15 [ V_9 ] &
V_16 )
V_157 += 1 ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
if ( V_157 > 0 ) {
F_28 ( & V_152 -> V_83 ,
L_56 ,
V_157 , ( V_157 == 1 ? L_57 : L_58 ) ) ;
V_96 = - V_158 ;
} else {
F_28 ( & V_152 -> V_83 , L_59 ) ;
F_86 ( V_159 , & V_23 -> V_12 ) ;
}
return V_96 ;
}
static int F_87 ( struct V_151 * V_152 )
{
struct V_22 * V_23 ;
F_75 ( & V_152 -> V_83 , L_51 , V_147 ) ;
V_23 = F_83 ( V_152 ) ;
F_88 ( V_159 , & V_23 -> V_12 ) ;
F_7 ( V_23 ) ;
return 0 ;
}
static void F_89 ( struct V_95 * V_83 )
{
}
static int T_5 F_90 ( void )
{
int V_96 ;
if ( F_91 () )
return - V_103 ;
V_96 = F_92 ( & V_160 ) ;
if ( V_96 )
goto V_161;
V_96 = F_93 ( & V_162 ) ;
if ( V_96 )
goto V_163;
F_45 ( V_164 L_60 V_165 L_3 ) ;
return V_96 ;
V_163:
F_94 ( & V_160 ) ;
V_161:
return V_96 ;
}
static void T_6 F_95 ( void )
{
F_96 ( & V_162 ) ;
F_94 ( & V_160 ) ;
}
