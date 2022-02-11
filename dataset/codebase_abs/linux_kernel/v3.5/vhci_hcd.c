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
void F_9 ( int V_9 )
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
unsigned long V_12 ;
int V_27 = 0 ;
unsigned long * V_28 = ( unsigned long * ) V_24 ;
int V_9 ;
int V_29 = 0 ;
* V_28 = 0 ;
V_26 = F_11 ( V_23 ) ;
F_5 ( & V_26 -> V_14 , V_12 ) ;
if ( ! F_12 ( V_23 ) ) {
F_4 ( L_6 ) ;
goto V_30;
}
for ( V_9 = 0 ; V_9 < V_31 ; V_9 ++ ) {
if ( ( V_26 -> V_15 [ V_9 ] & V_32 ) ) {
F_4 ( L_7 , V_9 ) ;
* V_28 |= 1 << ( V_9 + 1 ) ;
V_29 = 1 ;
}
}
F_13 ( L_8 , V_29 ) ;
if ( V_23 -> V_33 == V_34 )
F_14 ( V_23 ) ;
if ( V_29 )
V_27 = 1 + ( V_31 / 8 ) ;
else
V_27 = 0 ;
V_30:
F_6 ( & V_26 -> V_14 , V_12 ) ;
return V_27 ;
}
static inline void F_15 ( struct V_35 * V_36 )
{
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_37 = 0x29 ;
V_36 -> V_38 = 9 ;
V_36 -> V_39 = ( V_40 V_41 )
( F_16 ( 0x0001 ) ) ;
V_36 -> V_42 = V_31 ;
V_36 -> V_43 . V_44 . V_45 [ 0 ] = 0xff ;
V_36 -> V_43 . V_44 . V_45 [ 1 ] = 0xff ;
}
static int F_17 ( struct V_22 * V_23 , T_2 V_46 , T_2 V_47 ,
T_2 V_48 , char * V_24 , T_2 V_49 )
{
struct V_25 * V_50 ;
int V_27 = 0 ;
unsigned long V_12 ;
int V_9 ;
T_1 V_51 [ V_31 ] ;
if ( ! F_12 ( V_23 ) )
return - V_52 ;
F_4 ( L_9 , V_46 , V_47 ,
V_48 ) ;
if ( V_48 > V_31 )
F_18 ( L_10 , V_48 ) ;
V_9 = ( ( V_53 ) ( V_48 & 0x00ff ) ) - 1 ;
V_50 = F_11 ( V_23 ) ;
F_5 ( & V_50 -> V_14 , V_12 ) ;
if ( V_54 ) {
memcpy ( V_51 , V_50 -> V_15 ,
sizeof( V_51 ) ) ;
}
switch ( V_46 ) {
case V_55 :
F_4 ( L_11 ) ;
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
F_4 ( L_12
L_13 ) ;
V_50 -> V_15 [ V_9 ] = 0 ;
V_50 -> V_59 = 0 ;
break;
case V_63 :
F_4 ( L_12
L_14 ) ;
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
F_4 ( L_15 ,
V_47 ) ;
V_50 -> V_15 [ V_9 ] &= ~ ( 1 << V_47 ) ;
break;
}
break;
case V_65 :
F_4 ( L_16 ) ;
F_15 ( (struct V_35 * ) V_24 ) ;
break;
case V_66 :
F_4 ( L_17 ) ;
* ( V_67 * ) V_24 = F_20 ( 0 ) ;
break;
case V_68 :
F_4 ( L_18 , V_48 ) ;
if ( V_48 > V_31 || V_48 < 1 ) {
F_18 ( L_10 , V_48 ) ;
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
F_4 ( L_19
L_20 ,
V_9 ,
V_50 -> V_64 [ V_9 ] . V_72 . V_73 ) ;
V_50 -> V_15 [ V_9 ] |=
V_75 ;
}
}
( ( T_2 * ) V_24 ) [ 0 ] = F_22 ( V_50 -> V_15 [ V_9 ] ) ;
( ( T_2 * ) V_24 ) [ 1 ] = F_22 ( V_50 -> V_15 [ V_9 ] >> 16 ) ;
F_4 ( L_21 , ( ( T_2 * ) V_24 ) [ 0 ] ,
( ( T_2 * ) V_24 ) [ 1 ] ) ;
break;
case V_76 :
F_4 ( L_22 ) ;
V_27 = - V_69 ;
break;
case V_77 :
switch ( V_47 ) {
case V_57 :
F_4 ( L_23
L_24 ) ;
break;
case V_71 :
F_4 ( L_23
L_25 ) ;
if ( V_50 -> V_15 [ V_9 ] & V_75 ) {
V_50 -> V_15 [ V_9 ] &=
~ ( V_75 |
V_21 |
V_19 ) ;
}
V_50 -> V_60 = V_61 + F_19 ( 50 ) ;
default:
F_4 ( L_26 ,
V_47 ) ;
V_50 -> V_15 [ V_9 ] |= ( 1 << V_47 ) ;
break;
}
break;
default:
F_18 ( L_27 ) ;
V_27 = - V_69 ;
}
if ( V_54 ) {
F_2 ( L_28 , V_9 ) ;
if ( V_9 >= 0 ) {
F_1 ( V_51 [ V_9 ] ,
V_50 -> V_15 [ V_9 ] ) ;
}
}
F_4 ( L_29 ) ;
F_6 ( & V_50 -> V_14 , V_12 ) ;
return V_27 ;
}
static struct V_78 * F_23 ( struct V_79 * V_80 )
{
int V_3 ;
if ( ! V_80 )
return NULL ;
for ( V_3 = 0 ; V_3 < V_31 ; V_3 ++ )
if ( V_13 -> V_64 [ V_3 ] . V_80 == V_80 )
return F_24 ( V_3 ) ;
return NULL ;
}
static void F_25 ( struct V_81 * V_81 )
{
struct V_78 * V_64 = F_23 ( V_81 -> V_82 ) ;
struct V_83 * V_84 ;
unsigned long V_85 ;
if ( ! V_64 ) {
F_18 ( L_30 ) ;
return;
}
V_84 = F_26 ( sizeof( struct V_83 ) , V_86 ) ;
F_5 ( & V_64 -> V_87 , V_85 ) ;
if ( ! V_84 ) {
F_27 ( & V_81 -> V_82 -> V_82 , L_31 ) ;
F_6 ( & V_64 -> V_87 , V_85 ) ;
F_28 ( & V_64 -> V_72 , V_88 ) ;
return;
}
V_84 -> V_89 = F_29 ( & V_13 -> V_89 ) ;
if ( V_84 -> V_89 == 0xffff )
F_30 ( & V_81 -> V_82 -> V_82 , L_32 ) ;
V_84 -> V_64 = V_64 ;
V_84 -> V_81 = V_81 ;
V_81 -> V_90 = ( void * ) V_84 ;
F_31 ( & V_84 -> V_91 , & V_64 -> V_92 ) ;
F_32 ( & V_64 -> V_93 ) ;
F_6 ( & V_64 -> V_87 , V_85 ) ;
}
static int F_33 ( struct V_22 * V_23 , struct V_81 * V_81 ,
T_3 V_94 )
{
struct V_95 * V_82 = & V_81 -> V_82 -> V_82 ;
int V_96 = 0 ;
unsigned long V_12 ;
struct V_78 * V_64 ;
F_34 ( L_33 ,
V_23 , V_81 , V_94 ) ;
F_35 ( ! V_81 -> V_97 && V_81 -> V_98 ) ;
F_5 ( & V_13 -> V_14 , V_12 ) ;
if ( V_81 -> V_73 != - V_99 ) {
F_27 ( V_82 , L_34 , V_81 -> V_73 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
return V_81 -> V_73 ;
}
V_64 = F_24 ( V_81 -> V_82 -> V_100 - 1 ) ;
F_36 ( & V_64 -> V_72 . V_14 ) ;
if ( V_64 -> V_72 . V_73 == V_101 ||
V_64 -> V_72 . V_73 == V_102 ) {
F_27 ( V_82 , L_35 , V_64 -> V_9 ) ;
F_37 ( & V_64 -> V_72 . V_14 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
return - V_103 ;
}
F_37 ( & V_64 -> V_72 . V_14 ) ;
V_96 = F_38 ( V_23 , V_81 ) ;
if ( V_96 )
goto V_104;
if ( F_39 ( V_81 -> V_105 ) == 0 ) {
V_53 type = F_40 ( V_81 -> V_105 ) ;
struct V_106 * V_107 =
(struct V_106 * ) V_81 -> V_108 ;
if ( type != V_109 || ! V_107 ) {
F_27 ( V_82 , L_36 ) ;
V_96 = - V_110 ;
goto V_111;
}
switch ( V_107 -> V_112 ) {
case V_113 :
F_30 ( V_82 , L_37 ,
V_107 -> V_47 , V_64 -> V_9 ) ;
if ( V_64 -> V_80 )
F_41 ( V_64 -> V_80 ) ;
V_64 -> V_80 = F_42 ( V_81 -> V_82 ) ;
F_36 ( & V_64 -> V_72 . V_14 ) ;
V_64 -> V_72 . V_73 = V_114 ;
F_37 ( & V_64 -> V_72 . V_14 ) ;
if ( V_81 -> V_73 == - V_99 ) {
V_81 -> V_73 = 0 ;
}
goto V_111;
case V_115 :
if ( V_107 -> V_47 == ( V_116 << 8 ) )
F_34 ( L_38
L_39
L_40 ) ;
if ( V_64 -> V_80 )
F_41 ( V_64 -> V_80 ) ;
V_64 -> V_80 = F_42 ( V_81 -> V_82 ) ;
goto V_117;
default:
F_27 ( V_82 , L_41
L_42 , V_107 -> V_112 ,
V_107 -> V_47 ) ;
V_96 = - V_110 ;
goto V_111;
}
}
V_117:
F_25 ( V_81 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
return 0 ;
V_111:
F_43 ( V_23 , V_81 ) ;
V_104:
F_6 ( & V_13 -> V_14 , V_12 ) ;
F_44 ( F_8 ( V_13 ) , V_81 , V_81 -> V_73 ) ;
return V_96 ;
}
static int F_45 ( struct V_22 * V_23 , struct V_81 * V_81 , int V_73 )
{
unsigned long V_12 ;
struct V_83 * V_84 ;
struct V_78 * V_64 ;
F_13 ( L_43 , V_81 ) ;
F_5 ( & V_13 -> V_14 , V_12 ) ;
V_84 = V_81 -> V_90 ;
if ( ! V_84 ) {
F_6 ( & V_13 -> V_14 , V_12 ) ;
return 0 ;
}
{
int V_96 = 0 ;
V_96 = F_46 ( V_23 , V_81 , V_73 ) ;
if ( V_96 ) {
F_6 ( & V_13 -> V_14 , V_12 ) ;
return V_96 ;
}
}
V_64 = V_84 -> V_64 ;
if ( ! V_64 -> V_72 . V_118 ) {
unsigned long V_119 ;
F_5 ( & V_64 -> V_87 , V_119 ) ;
F_13 ( L_44 , V_64 ) ;
F_47 ( & V_84 -> V_91 ) ;
F_48 ( V_84 ) ;
V_81 -> V_90 = NULL ;
F_6 ( & V_64 -> V_87 , V_119 ) ;
F_13 ( L_45 , V_81 ) ;
F_43 ( V_23 , V_81 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
F_44 ( F_8 ( V_13 ) , V_81 ,
V_81 -> V_73 ) ;
F_5 ( & V_13 -> V_14 , V_12 ) ;
} else {
unsigned long V_119 ;
struct V_120 * V_121 ;
F_5 ( & V_64 -> V_87 , V_119 ) ;
V_121 = F_26 ( sizeof( struct V_120 ) , V_86 ) ;
if ( ! V_121 ) {
F_18 ( L_46 ) ;
F_6 ( & V_64 -> V_87 , V_119 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
F_28 ( & V_64 -> V_72 , V_88 ) ;
return - V_122 ;
}
V_121 -> V_89 = F_29 ( & V_13 -> V_89 ) ;
if ( V_121 -> V_89 == 0xffff )
F_13 ( L_32 ) ;
V_121 -> V_123 = V_84 -> V_89 ;
F_13 ( L_47 , V_64 ) ;
F_31 ( & V_121 -> V_91 , & V_64 -> V_124 ) ;
F_32 ( & V_64 -> V_93 ) ;
F_6 ( & V_64 -> V_87 , V_119 ) ;
}
F_6 ( & V_13 -> V_14 , V_12 ) ;
F_34 ( L_48 ) ;
return 0 ;
}
static void F_49 ( struct V_78 * V_64 )
{
struct V_120 * V_121 , * V_125 ;
F_36 ( & V_64 -> V_87 ) ;
F_50 (unlink, tmp, &vdev->unlink_tx, list) {
F_13 ( L_49 , V_121 -> V_123 ) ;
F_47 ( & V_121 -> V_91 ) ;
F_48 ( V_121 ) ;
}
F_50 (unlink, tmp, &vdev->unlink_rx, list) {
struct V_81 * V_81 ;
F_13 ( L_50 , V_121 -> V_123 ) ;
V_81 = F_51 ( V_64 , V_121 -> V_123 ) ;
if ( ! V_81 ) {
F_13 ( L_51 ,
V_121 -> V_123 ) ;
F_47 ( & V_121 -> V_91 ) ;
F_48 ( V_121 ) ;
continue;
}
V_81 -> V_73 = - V_103 ;
F_36 ( & V_13 -> V_14 ) ;
F_43 ( F_8 ( V_13 ) , V_81 ) ;
F_37 ( & V_13 -> V_14 ) ;
F_44 ( F_8 ( V_13 ) , V_81 ,
V_81 -> V_73 ) ;
F_47 ( & V_121 -> V_91 ) ;
F_48 ( V_121 ) ;
}
F_37 ( & V_64 -> V_87 ) ;
}
static void F_52 ( struct V_126 * V_72 )
{
struct V_78 * V_64 = F_53 ( V_72 , struct V_78 , V_72 ) ;
if ( V_72 -> V_118 ) {
F_2 ( L_52 , V_72 -> V_118 ) ;
F_54 ( V_72 -> V_118 , V_127 ) ;
}
if ( V_64 -> V_72 . V_128 )
F_55 ( V_64 -> V_72 . V_128 ) ;
if ( V_64 -> V_72 . V_129 )
F_55 ( V_64 -> V_72 . V_129 ) ;
F_13 ( L_53 ) ;
if ( V_64 -> V_72 . V_118 != NULL ) {
F_56 ( V_64 -> V_72 . V_118 ) ;
V_64 -> V_72 . V_118 = NULL ;
}
F_13 ( L_54 ) ;
F_49 ( V_64 ) ;
F_9 ( V_64 -> V_9 ) ;
F_13 ( L_55 ) ;
}
static void F_57 ( struct V_126 * V_72 )
{
struct V_78 * V_64 = F_53 ( V_72 , struct V_78 , V_72 ) ;
F_36 ( & V_72 -> V_14 ) ;
V_64 -> V_11 = 0 ;
V_64 -> V_130 = 0 ;
if ( V_64 -> V_80 )
F_41 ( V_64 -> V_80 ) ;
V_64 -> V_80 = NULL ;
V_72 -> V_118 = NULL ;
V_72 -> V_73 = V_101 ;
F_37 ( & V_72 -> V_14 ) ;
}
static void F_58 ( struct V_126 * V_72 )
{
F_36 ( & V_72 -> V_14 ) ;
V_72 -> V_73 = V_102 ;
F_37 ( & V_72 -> V_14 ) ;
}
static void F_59 ( struct V_78 * V_64 )
{
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_64 -> V_72 . V_131 = V_132 ;
V_64 -> V_72 . V_73 = V_101 ;
F_60 ( & V_64 -> V_72 . V_14 ) ;
F_61 ( & V_64 -> V_133 ) ;
F_61 ( & V_64 -> V_92 ) ;
F_61 ( & V_64 -> V_124 ) ;
F_61 ( & V_64 -> V_134 ) ;
F_60 ( & V_64 -> V_87 ) ;
F_62 ( & V_64 -> V_93 ) ;
V_64 -> V_72 . V_135 . V_136 = F_52 ;
V_64 -> V_72 . V_135 . V_137 = F_57 ;
V_64 -> V_72 . V_135 . V_138 = F_58 ;
F_63 ( & V_64 -> V_72 ) ;
}
static int F_64 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_11 ( V_23 ) ;
int V_9 ;
int V_139 = 0 ;
F_34 ( L_56 ) ;
for ( V_9 = 0 ; V_9 < V_31 ; V_9 ++ ) {
struct V_78 * V_64 = & V_26 -> V_64 [ V_9 ] ;
F_59 ( V_64 ) ;
V_64 -> V_9 = V_9 ;
}
F_65 ( & V_26 -> V_89 , 0 ) ;
F_60 ( & V_26 -> V_14 ) ;
V_23 -> V_140 = 0 ;
V_23 -> V_33 = V_141 ;
V_23 -> V_142 = 1 ;
V_139 = F_66 ( & F_67 ( V_26 ) -> V_143 , & V_144 ) ;
if ( V_139 ) {
F_18 ( L_57 ) ;
return V_139 ;
}
return 0 ;
}
static void F_68 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_11 ( V_23 ) ;
int V_9 = 0 ;
F_34 ( L_58 ) ;
F_69 ( & F_67 ( V_26 ) -> V_143 , & V_144 ) ;
for ( V_9 = 0 ; V_9 < V_31 ; V_9 ++ ) {
struct V_78 * V_64 = & V_26 -> V_64 [ V_9 ] ;
F_28 ( & V_64 -> V_72 , V_145 ) ;
F_70 ( & V_64 -> V_72 ) ;
}
}
static int F_71 ( struct V_22 * V_23 )
{
F_18 ( L_59 ) ;
return 0 ;
}
static int F_72 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_11 ( V_23 ) ;
F_73 ( & V_23 -> V_146 . V_147 -> V_82 , L_60 , V_148 ) ;
F_74 ( & V_26 -> V_14 ) ;
V_23 -> V_33 = V_34 ;
F_75 ( & V_26 -> V_14 ) ;
return 0 ;
}
static int F_76 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_11 ( V_23 ) ;
int V_149 = 0 ;
F_73 ( & V_23 -> V_146 . V_147 -> V_82 , L_60 , V_148 ) ;
F_74 ( & V_26 -> V_14 ) ;
if ( ! F_12 ( V_23 ) ) {
V_149 = - V_150 ;
} else {
V_23 -> V_33 = V_141 ;
}
F_75 ( & V_26 -> V_14 ) ;
return V_149 ;
}
static int F_77 ( struct V_151 * V_152 )
{
struct V_22 * V_23 ;
int V_96 ;
F_34 ( L_61 , V_152 -> V_153 , V_152 -> V_154 ) ;
if ( V_152 -> V_82 . V_155 ) {
F_30 ( & V_152 -> V_82 , L_62 ) ;
return - V_110 ;
}
V_23 = F_78 ( & V_156 , & V_152 -> V_82 , F_79 ( & V_152 -> V_82 ) ) ;
if ( ! V_23 ) {
F_18 ( L_63 ) ;
return - V_122 ;
}
V_23 -> V_157 = 1 ;
V_13 = F_11 ( V_23 ) ;
V_96 = F_80 ( V_23 , 0 , 0 ) ;
if ( V_96 != 0 ) {
F_18 ( L_64 , V_96 ) ;
F_81 ( V_23 ) ;
V_13 = NULL ;
return V_96 ;
}
F_34 ( L_65 ) ;
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
static int F_85 ( struct V_151 * V_152 , T_4 V_33 )
{
struct V_22 * V_23 ;
int V_9 = 0 ;
int V_158 = 0 ;
int V_96 = 0 ;
V_23 = F_83 ( V_152 ) ;
F_36 ( & V_13 -> V_14 ) ;
for ( V_9 = 0 ; V_9 < V_31 ; V_9 ++ )
if ( V_13 -> V_15 [ V_9 ] &
V_16 )
V_158 += 1 ;
F_37 ( & V_13 -> V_14 ) ;
if ( V_158 > 0 ) {
F_30 ( & V_152 -> V_82 , L_66
L_67 , V_158 , ( V_158 == 1 ? L_68 : L_69 ) ) ;
V_96 = - V_159 ;
} else {
F_30 ( & V_152 -> V_82 , L_70 ) ;
F_86 ( V_160 , & V_23 -> V_12 ) ;
}
return V_96 ;
}
static int F_87 ( struct V_151 * V_152 )
{
struct V_22 * V_23 ;
F_73 ( & V_152 -> V_82 , L_60 , V_148 ) ;
V_23 = F_83 ( V_152 ) ;
F_88 ( V_160 , & V_23 -> V_12 ) ;
F_7 ( V_23 ) ;
return 0 ;
}
static void F_89 ( struct V_95 * V_82 )
{
return;
}
static int T_5 F_90 ( void )
{
int V_96 ;
if ( F_91 () )
return - V_103 ;
V_96 = F_92 ( & V_161 ) ;
if ( V_96 < 0 )
goto V_162;
V_96 = F_93 ( & V_163 ) ;
if ( V_96 < 0 )
goto V_164;
F_13 ( V_165 L_71 V_166 L_3 ) ;
return V_96 ;
V_164:
F_94 ( & V_161 ) ;
V_162:
return V_96 ;
}
static void T_6 F_95 ( void )
{
F_96 ( & V_163 ) ;
F_94 ( & V_161 ) ;
}
