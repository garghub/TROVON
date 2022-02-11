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
unsigned long V_12 ;
int V_27 ;
int V_9 ;
int V_28 = 0 ;
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
F_14 ( L_8 , V_28 ) ;
if ( ( V_23 -> V_32 == V_33 ) && ( V_28 == 1 ) )
F_15 ( V_23 ) ;
V_30:
F_6 ( & V_26 -> V_14 , V_12 ) ;
return V_28 ? V_27 : 0 ;
}
static inline void F_16 ( struct V_34 * V_35 )
{
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_36 = 0x29 ;
V_35 -> V_37 = 9 ;
V_35 -> V_38 = ( V_39 V_40 )
( F_17 ( 0x0001 ) ) ;
V_35 -> V_41 = V_29 ;
V_35 -> V_42 . V_43 . V_44 [ 0 ] = 0xff ;
V_35 -> V_42 . V_43 . V_44 [ 1 ] = 0xff ;
}
static int F_18 ( struct V_22 * V_23 , T_2 V_45 , T_2 V_46 ,
T_2 V_47 , char * V_24 , T_2 V_48 )
{
struct V_25 * V_49 ;
int V_27 = 0 ;
unsigned long V_12 ;
int V_9 ;
T_1 V_50 [ V_29 ] ;
if ( ! F_13 ( V_23 ) )
return - V_51 ;
F_4 ( L_9 , V_45 , V_46 ,
V_47 ) ;
if ( V_47 > V_29 )
F_19 ( L_10 , V_47 ) ;
V_9 = ( ( V_52 ) ( V_47 & 0x00ff ) ) - 1 ;
V_49 = F_12 ( V_23 ) ;
F_5 ( & V_49 -> V_14 , V_12 ) ;
if ( V_53 ) {
memcpy ( V_50 , V_49 -> V_15 ,
sizeof( V_50 ) ) ;
}
switch ( V_45 ) {
case V_54 :
F_4 ( L_11 ) ;
break;
case V_55 :
switch ( V_46 ) {
case V_56 :
if ( V_49 -> V_15 [ V_9 ] & V_57 ) {
V_49 -> V_58 = 1 ;
V_49 -> V_59 =
V_60 + F_20 ( 20 ) ;
}
break;
case V_61 :
F_4 ( L_12
L_13 ) ;
V_49 -> V_15 [ V_9 ] = 0 ;
V_49 -> V_58 = 0 ;
break;
case V_62 :
F_4 ( L_12
L_14 ) ;
switch ( V_49 -> V_63 [ V_9 ] . V_11 ) {
case V_18 :
V_49 -> V_15 [ V_9 ] |=
V_19 ;
break;
case V_20 :
V_49 -> V_15 [ V_9 ] |=
V_21 ;
break;
default:
break;
}
default:
F_4 ( L_15 ,
V_46 ) ;
V_49 -> V_15 [ V_9 ] &= ~ ( 1 << V_46 ) ;
break;
}
break;
case V_64 :
F_4 ( L_16 ) ;
F_16 ( (struct V_34 * ) V_24 ) ;
break;
case V_65 :
F_4 ( L_17 ) ;
* ( V_66 * ) V_24 = F_21 ( 0 ) ;
break;
case V_67 :
F_4 ( L_18 , V_47 ) ;
if ( V_47 > V_29 || V_47 < 1 ) {
F_19 ( L_10 , V_47 ) ;
V_27 = - V_68 ;
}
if ( V_49 -> V_58 && F_22 ( V_60 , V_49 -> V_59 ) ) {
V_49 -> V_15 [ V_9 ] |=
( 1 << V_69 ) ;
V_49 -> V_15 [ V_9 ] &=
~ ( 1 << V_56 ) ;
V_49 -> V_58 = 0 ;
V_49 -> V_59 = 0 ;
}
if ( ( V_49 -> V_15 [ V_9 ] & ( 1 << V_70 ) ) !=
0 && F_22 ( V_60 , V_49 -> V_59 ) ) {
V_49 -> V_15 [ V_9 ] |=
( 1 << V_62 ) ;
V_49 -> V_15 [ V_9 ] &=
~ ( 1 << V_70 ) ;
V_49 -> V_59 = 0 ;
if ( V_49 -> V_63 [ V_9 ] . V_71 . V_72 ==
V_73 ) {
F_4 ( L_19
L_20 ,
V_9 ,
V_49 -> V_63 [ V_9 ] . V_71 . V_72 ) ;
V_49 -> V_15 [ V_9 ] |=
V_74 ;
}
}
( ( T_2 * ) V_24 ) [ 0 ] = F_23 ( V_49 -> V_15 [ V_9 ] ) ;
( ( T_2 * ) V_24 ) [ 1 ] = F_23 ( V_49 -> V_15 [ V_9 ] >> 16 ) ;
F_4 ( L_21 , ( ( T_2 * ) V_24 ) [ 0 ] ,
( ( T_2 * ) V_24 ) [ 1 ] ) ;
break;
case V_75 :
F_4 ( L_22 ) ;
V_27 = - V_68 ;
break;
case V_76 :
switch ( V_46 ) {
case V_56 :
F_4 ( L_23
L_24 ) ;
break;
case V_70 :
F_4 ( L_23
L_25 ) ;
if ( V_49 -> V_15 [ V_9 ] & V_74 ) {
V_49 -> V_15 [ V_9 ] &=
~ ( V_74 |
V_21 |
V_19 ) ;
}
V_49 -> V_59 = V_60 + F_20 ( 50 ) ;
default:
F_4 ( L_26 ,
V_46 ) ;
V_49 -> V_15 [ V_9 ] |= ( 1 << V_46 ) ;
break;
}
break;
default:
F_19 ( L_27 ) ;
V_27 = - V_68 ;
}
if ( V_53 ) {
F_2 ( L_28 , V_9 ) ;
if ( V_9 >= 0 ) {
F_1 ( V_50 [ V_9 ] ,
V_49 -> V_15 [ V_9 ] ) ;
}
}
F_4 ( L_29 ) ;
F_6 ( & V_49 -> V_14 , V_12 ) ;
return V_27 ;
}
static struct V_77 * F_24 ( struct V_78 * V_79 )
{
int V_3 ;
if ( ! V_79 )
return NULL ;
for ( V_3 = 0 ; V_3 < V_29 ; V_3 ++ )
if ( V_13 -> V_63 [ V_3 ] . V_79 == V_79 )
return F_25 ( V_3 ) ;
return NULL ;
}
static void F_26 ( struct V_80 * V_80 )
{
struct V_77 * V_63 = F_24 ( V_80 -> V_81 ) ;
struct V_82 * V_83 ;
unsigned long V_84 ;
if ( ! V_63 ) {
F_19 ( L_30 ) ;
return;
}
V_83 = F_27 ( sizeof( struct V_82 ) , V_85 ) ;
F_5 ( & V_63 -> V_86 , V_84 ) ;
if ( ! V_83 ) {
F_28 ( & V_80 -> V_81 -> V_81 , L_31 ) ;
F_6 ( & V_63 -> V_86 , V_84 ) ;
F_29 ( & V_63 -> V_71 , V_87 ) ;
return;
}
V_83 -> V_88 = F_30 ( & V_13 -> V_88 ) ;
if ( V_83 -> V_88 == 0xffff )
F_31 ( & V_80 -> V_81 -> V_81 , L_32 ) ;
V_83 -> V_63 = V_63 ;
V_83 -> V_80 = V_80 ;
V_80 -> V_89 = ( void * ) V_83 ;
F_32 ( & V_83 -> V_90 , & V_63 -> V_91 ) ;
F_33 ( & V_63 -> V_92 ) ;
F_6 ( & V_63 -> V_86 , V_84 ) ;
}
static int F_34 ( struct V_22 * V_23 , struct V_80 * V_80 ,
T_3 V_93 )
{
struct V_94 * V_81 = & V_80 -> V_81 -> V_81 ;
int V_95 = 0 ;
unsigned long V_12 ;
struct V_77 * V_63 ;
F_35 ( L_33 ,
V_23 , V_80 , V_93 ) ;
F_36 ( ! V_80 -> V_96 && V_80 -> V_97 ) ;
F_5 ( & V_13 -> V_14 , V_12 ) ;
if ( V_80 -> V_72 != - V_98 ) {
F_28 ( V_81 , L_34 , V_80 -> V_72 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
return V_80 -> V_72 ;
}
V_63 = F_25 ( V_80 -> V_81 -> V_99 - 1 ) ;
F_37 ( & V_63 -> V_71 . V_14 ) ;
if ( V_63 -> V_71 . V_72 == V_100 ||
V_63 -> V_71 . V_72 == V_101 ) {
F_28 ( V_81 , L_35 , V_63 -> V_9 ) ;
F_38 ( & V_63 -> V_71 . V_14 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
return - V_102 ;
}
F_38 ( & V_63 -> V_71 . V_14 ) ;
V_95 = F_39 ( V_23 , V_80 ) ;
if ( V_95 )
goto V_103;
if ( F_40 ( V_80 -> V_104 ) == 0 ) {
V_52 type = F_41 ( V_80 -> V_104 ) ;
struct V_105 * V_106 =
(struct V_105 * ) V_80 -> V_107 ;
if ( type != V_108 || ! V_106 ) {
F_28 ( V_81 , L_36 ) ;
V_95 = - V_109 ;
goto V_110;
}
switch ( V_106 -> V_111 ) {
case V_112 :
F_31 ( V_81 , L_37 ,
V_106 -> V_46 , V_63 -> V_9 ) ;
if ( V_63 -> V_79 )
F_42 ( V_63 -> V_79 ) ;
V_63 -> V_79 = F_43 ( V_80 -> V_81 ) ;
F_37 ( & V_63 -> V_71 . V_14 ) ;
V_63 -> V_71 . V_72 = V_113 ;
F_38 ( & V_63 -> V_71 . V_14 ) ;
if ( V_80 -> V_72 == - V_98 ) {
V_80 -> V_72 = 0 ;
}
goto V_110;
case V_114 :
if ( V_106 -> V_46 == ( V_115 << 8 ) )
F_35 ( L_38
L_39
L_40 ) ;
if ( V_63 -> V_79 )
F_42 ( V_63 -> V_79 ) ;
V_63 -> V_79 = F_43 ( V_80 -> V_81 ) ;
goto V_116;
default:
F_28 ( V_81 , L_41
L_42 , V_106 -> V_111 ,
V_106 -> V_46 ) ;
V_95 = - V_109 ;
goto V_110;
}
}
V_116:
F_26 ( V_80 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
return 0 ;
V_110:
F_44 ( V_23 , V_80 ) ;
V_103:
F_6 ( & V_13 -> V_14 , V_12 ) ;
F_45 ( F_8 ( V_13 ) , V_80 , V_80 -> V_72 ) ;
return V_95 ;
}
static int F_46 ( struct V_22 * V_23 , struct V_80 * V_80 , int V_72 )
{
unsigned long V_12 ;
struct V_82 * V_83 ;
struct V_77 * V_63 ;
F_14 ( L_43 , V_80 ) ;
F_5 ( & V_13 -> V_14 , V_12 ) ;
V_83 = V_80 -> V_89 ;
if ( ! V_83 ) {
F_6 ( & V_13 -> V_14 , V_12 ) ;
return 0 ;
}
{
int V_95 = 0 ;
V_95 = F_47 ( V_23 , V_80 , V_72 ) ;
if ( V_95 ) {
F_6 ( & V_13 -> V_14 , V_12 ) ;
return V_95 ;
}
}
V_63 = V_83 -> V_63 ;
if ( ! V_63 -> V_71 . V_117 ) {
unsigned long V_118 ;
F_5 ( & V_63 -> V_86 , V_118 ) ;
F_14 ( L_44 , V_63 ) ;
F_48 ( & V_83 -> V_90 ) ;
F_49 ( V_83 ) ;
V_80 -> V_89 = NULL ;
F_6 ( & V_63 -> V_86 , V_118 ) ;
F_14 ( L_45 , V_80 ) ;
F_44 ( V_23 , V_80 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
F_45 ( F_8 ( V_13 ) , V_80 ,
V_80 -> V_72 ) ;
F_5 ( & V_13 -> V_14 , V_12 ) ;
} else {
unsigned long V_118 ;
struct V_119 * V_120 ;
F_5 ( & V_63 -> V_86 , V_118 ) ;
V_120 = F_27 ( sizeof( struct V_119 ) , V_85 ) ;
if ( ! V_120 ) {
F_19 ( L_46 ) ;
F_6 ( & V_63 -> V_86 , V_118 ) ;
F_6 ( & V_13 -> V_14 , V_12 ) ;
F_29 ( & V_63 -> V_71 , V_87 ) ;
return - V_121 ;
}
V_120 -> V_88 = F_30 ( & V_13 -> V_88 ) ;
if ( V_120 -> V_88 == 0xffff )
F_14 ( L_32 ) ;
V_120 -> V_122 = V_83 -> V_88 ;
F_14 ( L_47 , V_63 ) ;
F_32 ( & V_120 -> V_90 , & V_63 -> V_123 ) ;
F_33 ( & V_63 -> V_92 ) ;
F_6 ( & V_63 -> V_86 , V_118 ) ;
}
F_6 ( & V_13 -> V_14 , V_12 ) ;
F_35 ( L_48 ) ;
return 0 ;
}
static void F_50 ( struct V_77 * V_63 )
{
struct V_119 * V_120 , * V_124 ;
F_37 ( & V_13 -> V_14 ) ;
F_37 ( & V_63 -> V_86 ) ;
F_51 (unlink, tmp, &vdev->unlink_tx, list) {
F_14 ( L_49 , V_120 -> V_122 ) ;
F_48 ( & V_120 -> V_90 ) ;
F_49 ( V_120 ) ;
}
while ( ! F_52 ( & V_63 -> V_125 ) ) {
struct V_80 * V_80 ;
V_120 = F_53 ( & V_63 -> V_125 , struct V_119 ,
V_90 ) ;
F_14 ( L_50 , V_120 -> V_122 ) ;
V_80 = F_54 ( V_63 , V_120 -> V_122 ) ;
if ( ! V_80 ) {
F_14 ( L_51 ,
V_120 -> V_122 ) ;
F_48 ( & V_120 -> V_90 ) ;
F_49 ( V_120 ) ;
continue;
}
V_80 -> V_72 = - V_102 ;
F_44 ( F_8 ( V_13 ) , V_80 ) ;
F_48 ( & V_120 -> V_90 ) ;
F_38 ( & V_63 -> V_86 ) ;
F_38 ( & V_13 -> V_14 ) ;
F_45 ( F_8 ( V_13 ) , V_80 ,
V_80 -> V_72 ) ;
F_37 ( & V_13 -> V_14 ) ;
F_37 ( & V_63 -> V_86 ) ;
F_49 ( V_120 ) ;
}
F_38 ( & V_63 -> V_86 ) ;
F_38 ( & V_13 -> V_14 ) ;
}
static void F_55 ( struct V_126 * V_71 )
{
struct V_77 * V_63 = F_56 ( V_71 , struct V_77 , V_71 ) ;
if ( V_71 -> V_117 ) {
F_2 ( L_52 , V_71 -> V_117 ) ;
F_57 ( V_71 -> V_117 , V_127 ) ;
}
if ( V_63 -> V_71 . V_128 ) {
F_58 ( V_63 -> V_71 . V_128 ) ;
V_63 -> V_71 . V_128 = NULL ;
}
if ( V_63 -> V_71 . V_129 ) {
F_58 ( V_63 -> V_71 . V_129 ) ;
V_63 -> V_71 . V_129 = NULL ;
}
F_14 ( L_53 ) ;
if ( V_63 -> V_71 . V_117 ) {
F_59 ( V_63 -> V_71 . V_117 -> V_130 ) ;
V_63 -> V_71 . V_117 = NULL ;
}
F_14 ( L_54 ) ;
F_50 ( V_63 ) ;
F_9 ( V_63 -> V_9 ) ;
F_14 ( L_55 ) ;
}
static void F_60 ( struct V_126 * V_71 )
{
struct V_77 * V_63 = F_56 ( V_71 , struct V_77 , V_71 ) ;
F_37 ( & V_71 -> V_14 ) ;
V_63 -> V_11 = 0 ;
V_63 -> V_131 = 0 ;
if ( V_63 -> V_79 )
F_42 ( V_63 -> V_79 ) ;
V_63 -> V_79 = NULL ;
if ( V_71 -> V_117 ) {
F_59 ( V_71 -> V_117 -> V_130 ) ;
V_71 -> V_117 = NULL ;
}
V_71 -> V_72 = V_100 ;
F_38 ( & V_71 -> V_14 ) ;
}
static void F_61 ( struct V_126 * V_71 )
{
F_37 ( & V_71 -> V_14 ) ;
V_71 -> V_72 = V_101 ;
F_38 ( & V_71 -> V_14 ) ;
}
static void F_62 ( struct V_77 * V_63 )
{
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_71 . V_132 = V_133 ;
V_63 -> V_71 . V_72 = V_100 ;
F_63 ( & V_63 -> V_71 . V_14 ) ;
F_64 ( & V_63 -> V_134 ) ;
F_64 ( & V_63 -> V_91 ) ;
F_64 ( & V_63 -> V_123 ) ;
F_64 ( & V_63 -> V_125 ) ;
F_63 ( & V_63 -> V_86 ) ;
F_65 ( & V_63 -> V_92 ) ;
V_63 -> V_71 . V_135 . V_136 = F_55 ;
V_63 -> V_71 . V_135 . V_137 = F_60 ;
V_63 -> V_71 . V_135 . V_138 = F_61 ;
F_66 ( & V_63 -> V_71 ) ;
}
static int F_67 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_12 ( V_23 ) ;
int V_9 ;
int V_139 = 0 ;
F_35 ( L_56 ) ;
for ( V_9 = 0 ; V_9 < V_29 ; V_9 ++ ) {
struct V_77 * V_63 = & V_26 -> V_63 [ V_9 ] ;
F_62 ( V_63 ) ;
V_63 -> V_9 = V_9 ;
}
F_68 ( & V_26 -> V_88 , 0 ) ;
F_63 ( & V_26 -> V_14 ) ;
V_23 -> V_140 = 0 ;
V_23 -> V_141 = 1 ;
V_139 = F_69 ( & F_70 ( V_26 ) -> V_142 , & V_143 ) ;
if ( V_139 ) {
F_19 ( L_57 ) ;
return V_139 ;
}
return 0 ;
}
static void F_71 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_12 ( V_23 ) ;
int V_9 = 0 ;
F_35 ( L_58 ) ;
F_72 ( & F_70 ( V_26 ) -> V_142 , & V_143 ) ;
for ( V_9 = 0 ; V_9 < V_29 ; V_9 ++ ) {
struct V_77 * V_63 = & V_26 -> V_63 [ V_9 ] ;
F_29 ( & V_63 -> V_71 , V_144 ) ;
F_73 ( & V_63 -> V_71 ) ;
}
}
static int F_74 ( struct V_22 * V_23 )
{
F_19 ( L_59 ) ;
return 0 ;
}
static int F_75 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_12 ( V_23 ) ;
F_76 ( & V_23 -> V_145 . V_146 -> V_81 , L_60 , V_147 ) ;
F_77 ( & V_26 -> V_14 ) ;
V_23 -> V_32 = V_33 ;
F_78 ( & V_26 -> V_14 ) ;
return 0 ;
}
static int F_79 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_12 ( V_23 ) ;
int V_148 = 0 ;
F_76 ( & V_23 -> V_145 . V_146 -> V_81 , L_60 , V_147 ) ;
F_77 ( & V_26 -> V_14 ) ;
if ( ! F_13 ( V_23 ) ) {
V_148 = - V_149 ;
} else {
V_23 -> V_32 = V_150 ;
}
F_78 ( & V_26 -> V_14 ) ;
return V_148 ;
}
static int F_80 ( struct V_151 * V_152 )
{
struct V_22 * V_23 ;
int V_95 ;
F_35 ( L_61 , V_152 -> V_153 , V_152 -> V_154 ) ;
if ( V_152 -> V_81 . V_155 ) {
F_31 ( & V_152 -> V_81 , L_62 ) ;
return - V_109 ;
}
V_23 = F_81 ( & V_156 , & V_152 -> V_81 , F_82 ( & V_152 -> V_81 ) ) ;
if ( ! V_23 ) {
F_19 ( L_63 ) ;
return - V_121 ;
}
V_23 -> V_157 = 1 ;
V_13 = F_12 ( V_23 ) ;
V_95 = F_83 ( V_23 , 0 , 0 ) ;
if ( V_95 != 0 ) {
F_19 ( L_64 , V_95 ) ;
F_84 ( V_23 ) ;
V_13 = NULL ;
return V_95 ;
}
F_35 ( L_65 ) ;
return 0 ;
}
static int F_85 ( struct V_151 * V_152 )
{
struct V_22 * V_23 ;
V_23 = F_86 ( V_152 ) ;
if ( ! V_23 )
return 0 ;
F_87 ( V_23 ) ;
F_84 ( V_23 ) ;
V_13 = NULL ;
return 0 ;
}
static int F_88 ( struct V_151 * V_152 , T_4 V_32 )
{
struct V_22 * V_23 ;
int V_9 = 0 ;
int V_158 = 0 ;
int V_95 = 0 ;
V_23 = F_86 ( V_152 ) ;
F_37 ( & V_13 -> V_14 ) ;
for ( V_9 = 0 ; V_9 < V_29 ; V_9 ++ )
if ( V_13 -> V_15 [ V_9 ] &
V_16 )
V_158 += 1 ;
F_38 ( & V_13 -> V_14 ) ;
if ( V_158 > 0 ) {
F_31 ( & V_152 -> V_81 , L_66
L_67 , V_158 , ( V_158 == 1 ? L_68 : L_69 ) ) ;
V_95 = - V_159 ;
} else {
F_31 ( & V_152 -> V_81 , L_70 ) ;
F_89 ( V_160 , & V_23 -> V_12 ) ;
}
return V_95 ;
}
static int F_90 ( struct V_151 * V_152 )
{
struct V_22 * V_23 ;
F_76 ( & V_152 -> V_81 , L_60 , V_147 ) ;
V_23 = F_86 ( V_152 ) ;
F_91 ( V_160 , & V_23 -> V_12 ) ;
F_7 ( V_23 ) ;
return 0 ;
}
static void F_92 ( struct V_94 * V_81 )
{
return;
}
static int T_5 F_93 ( void )
{
int V_95 ;
if ( F_94 () )
return - V_102 ;
V_95 = F_95 ( & V_161 ) ;
if ( V_95 < 0 )
goto V_162;
V_95 = F_96 ( & V_163 ) ;
if ( V_95 < 0 )
goto V_164;
F_14 ( V_165 L_71 V_166 L_3 ) ;
return V_95 ;
V_164:
F_97 ( & V_161 ) ;
V_162:
return V_95 ;
}
static void T_6 F_98 ( void )
{
F_99 ( & V_163 ) ;
F_97 ( & V_161 ) ;
}
