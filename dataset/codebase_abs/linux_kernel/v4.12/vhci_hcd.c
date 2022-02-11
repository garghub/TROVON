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
void F_3 ( struct V_9 * V_10 , enum V_11 V_12 )
{
struct V_13 * V_14 = F_4 ( V_10 ) ;
int V_15 = V_10 -> V_15 ;
T_1 V_16 ;
unsigned long V_17 ;
F_5 ( L_4 , V_15 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
V_16 = V_14 -> V_19 [ V_15 ] ;
V_16 |= V_20 | ( 1 << V_21 ) ;
switch ( V_12 ) {
case V_22 :
V_16 |= V_23 ;
break;
case V_24 :
V_16 |= V_25 ;
break;
default:
break;
}
V_14 -> V_19 [ V_15 ] = V_16 ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
F_8 ( F_9 ( V_14 ) ) ;
}
static void F_10 ( struct V_9 * V_10 )
{
struct V_13 * V_14 = F_4 ( V_10 ) ;
int V_15 = V_10 -> V_15 ;
T_1 V_16 ;
unsigned long V_17 ;
F_5 ( L_5 , V_15 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
V_16 = V_14 -> V_19 [ V_15 ] ;
V_16 &= ~ V_20 ;
V_16 |= ( 1 << V_21 ) ;
V_14 -> V_19 [ V_15 ] = V_16 ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
F_8 ( F_9 ( V_14 ) ) ;
}
static int F_11 ( struct V_26 * V_27 , char * V_28 )
{
struct V_13 * V_14 ;
int V_29 ;
int V_15 ;
int V_30 = 0 ;
unsigned long V_17 ;
V_29 = F_12 ( V_31 + 1 , 8 ) ;
memset ( V_28 , 0 , V_29 ) ;
V_14 = F_13 ( V_27 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
if ( ! F_14 ( V_27 ) ) {
F_5 ( L_6 ) ;
goto V_32;
}
for ( V_15 = 0 ; V_15 < V_31 ; V_15 ++ ) {
if ( ( V_14 -> V_19 [ V_15 ] & V_33 ) ) {
F_5 ( L_7 , V_15 ) ;
V_28 [ ( V_15 + 1 ) / 8 ] |= 1 << ( V_15 + 1 ) % 8 ;
V_30 = 1 ;
}
}
if ( ( V_27 -> V_34 == V_35 ) && ( V_30 == 1 ) )
F_15 ( V_27 ) ;
V_32:
F_7 ( & V_14 -> V_18 , V_17 ) ;
return V_30 ? V_29 : 0 ;
}
static inline void F_16 ( struct V_36 * V_37 )
{
int V_38 ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_39 = V_40 ;
V_37 -> V_41 = F_17 (
V_42 | V_43 ) ;
V_37 -> V_44 = V_31 ;
F_18 ( V_31 > V_45 ) ;
V_38 = V_37 -> V_44 / 8 + 1 ;
V_37 -> V_46 = V_47 + 2 * V_38 ;
memset ( & V_37 -> V_48 . V_49 . V_50 [ 0 ] , 0 , V_38 ) ;
memset ( & V_37 -> V_48 . V_49 . V_50 [ V_38 ] , 0xff , V_38 ) ;
}
static int F_19 ( struct V_26 * V_27 , T_2 V_51 , T_2 V_52 ,
T_2 V_53 , char * V_28 , T_2 V_54 )
{
struct V_13 * V_55 ;
int V_29 = 0 ;
int V_15 ;
unsigned long V_17 ;
T_1 V_56 [ V_31 ] ;
if ( ! F_14 ( V_27 ) )
return - V_57 ;
F_5 ( L_8 , V_51 , V_52 ,
V_53 ) ;
if ( V_53 > V_31 )
F_20 ( L_9 , V_53 ) ;
V_15 = ( ( V_58 ) ( V_53 & 0x00ff ) ) - 1 ;
V_55 = F_13 ( V_27 ) ;
F_6 ( & V_55 -> V_18 , V_17 ) ;
if ( V_59 ) {
memcpy ( V_56 , V_55 -> V_19 ,
sizeof( V_56 ) ) ;
}
switch ( V_51 ) {
case V_60 :
F_5 ( L_10 ) ;
break;
case V_61 :
switch ( V_52 ) {
case V_62 :
if ( V_55 -> V_19 [ V_15 ] & V_63 ) {
V_55 -> V_64 = 1 ;
V_55 -> V_65 =
V_66 + F_21 ( 20 ) ;
}
break;
case V_67 :
F_5 (
L_11 ) ;
V_55 -> V_19 [ V_15 ] = 0 ;
V_55 -> V_64 = 0 ;
break;
case V_68 :
F_5 (
L_12 ) ;
switch ( V_55 -> V_10 [ V_15 ] . V_12 ) {
case V_22 :
V_55 -> V_19 [ V_15 ] |=
V_23 ;
break;
case V_24 :
V_55 -> V_19 [ V_15 ] |=
V_25 ;
break;
default:
break;
}
break;
default:
F_5 ( L_13 ,
V_52 ) ;
V_55 -> V_19 [ V_15 ] &= ~ ( 1 << V_52 ) ;
break;
}
break;
case V_69 :
F_5 ( L_14 ) ;
F_16 ( (struct V_36 * ) V_28 ) ;
break;
case V_70 :
F_5 ( L_15 ) ;
* ( V_71 * ) V_28 = F_22 ( 0 ) ;
break;
case V_72 :
F_5 ( L_16 , V_53 ) ;
if ( V_53 > V_31 || V_53 < 1 ) {
F_20 ( L_9 , V_53 ) ;
V_29 = - V_73 ;
}
if ( V_55 -> V_64 && F_23 ( V_66 , V_55 -> V_65 ) ) {
V_55 -> V_19 [ V_15 ] |=
( 1 << V_74 ) ;
V_55 -> V_19 [ V_15 ] &=
~ ( 1 << V_62 ) ;
V_55 -> V_64 = 0 ;
V_55 -> V_65 = 0 ;
}
if ( ( V_55 -> V_19 [ V_15 ] & ( 1 << V_75 ) ) !=
0 && F_23 ( V_66 , V_55 -> V_65 ) ) {
V_55 -> V_19 [ V_15 ] |=
( 1 << V_68 ) ;
V_55 -> V_19 [ V_15 ] &=
~ ( 1 << V_75 ) ;
V_55 -> V_65 = 0 ;
if ( V_55 -> V_10 [ V_15 ] . V_76 . V_16 ==
V_77 ) {
F_5 (
L_17 ,
V_15 ,
V_55 -> V_10 [ V_15 ] . V_76 . V_16 ) ;
V_55 -> V_19 [ V_15 ] |=
V_78 ;
}
}
( ( V_79 * ) V_28 ) [ 0 ] = F_17 ( V_55 -> V_19 [ V_15 ] ) ;
( ( V_79 * ) V_28 ) [ 1 ] =
F_17 ( V_55 -> V_19 [ V_15 ] >> 16 ) ;
F_5 ( L_18 , ( ( T_2 * ) V_28 ) [ 0 ] ,
( ( T_2 * ) V_28 ) [ 1 ] ) ;
break;
case V_80 :
F_5 ( L_19 ) ;
V_29 = - V_73 ;
break;
case V_81 :
switch ( V_52 ) {
case V_62 :
F_5 (
L_20 ) ;
break;
case V_75 :
F_5 (
L_21 ) ;
if ( V_55 -> V_19 [ V_15 ] & V_78 ) {
V_55 -> V_19 [ V_15 ] &=
~ ( V_78 |
V_25 |
V_23 ) ;
}
V_55 -> V_65 = V_66 + F_21 ( 50 ) ;
default:
F_5 ( L_22 ,
V_52 ) ;
V_55 -> V_19 [ V_15 ] |= ( 1 << V_52 ) ;
break;
}
break;
default:
F_20 ( L_23 ) ;
V_29 = - V_73 ;
}
if ( V_59 ) {
F_2 ( L_24 , V_15 ) ;
if ( V_15 >= 0 ) {
F_1 ( V_56 [ V_15 ] ,
V_55 -> V_19 [ V_15 ] ) ;
}
}
F_5 ( L_25 ) ;
F_7 ( & V_55 -> V_18 , V_17 ) ;
return V_29 ;
}
static void F_24 ( struct V_82 * V_82 , struct V_9 * V_10 )
{
struct V_83 * V_84 ;
struct V_13 * V_14 ;
unsigned long V_17 ;
if ( ! V_10 ) {
F_20 ( L_26 ) ;
return;
}
V_14 = F_4 ( V_10 ) ;
V_84 = F_25 ( sizeof( struct V_83 ) , V_85 ) ;
if ( ! V_84 ) {
F_26 ( & V_10 -> V_76 , V_86 ) ;
return;
}
F_6 ( & V_10 -> V_87 , V_17 ) ;
V_84 -> V_88 = F_27 ( & V_14 -> V_88 ) ;
if ( V_84 -> V_88 == 0xffff )
F_28 ( & V_82 -> V_89 -> V_89 , L_27 ) ;
V_84 -> V_10 = V_10 ;
V_84 -> V_82 = V_82 ;
V_82 -> V_90 = ( void * ) V_84 ;
F_29 ( & V_84 -> V_91 , & V_10 -> V_92 ) ;
F_30 ( & V_10 -> V_93 ) ;
F_7 ( & V_10 -> V_87 , V_17 ) ;
}
static int F_31 ( struct V_26 * V_27 , struct V_82 * V_82 ,
T_3 V_94 )
{
struct V_13 * V_14 = F_13 ( V_27 ) ;
struct V_95 * V_89 = & V_82 -> V_89 -> V_89 ;
T_4 V_96 = V_82 -> V_89 -> V_96 ;
int V_97 = 0 ;
struct V_9 * V_10 ;
unsigned long V_17 ;
F_32 ( L_28 ,
V_27 , V_82 , V_94 ) ;
if ( V_96 > V_31 ) {
F_20 ( L_9 , V_96 ) ;
return - V_98 ;
}
V_10 = & V_14 -> V_10 [ V_96 - 1 ] ;
F_33 ( ! V_82 -> V_99 && V_82 -> V_100 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
if ( V_82 -> V_16 != - V_101 ) {
F_34 ( V_89 , L_29 , V_82 -> V_16 ) ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
return V_82 -> V_16 ;
}
F_35 ( & V_10 -> V_76 . V_18 ) ;
if ( V_10 -> V_76 . V_16 == V_102 ||
V_10 -> V_76 . V_16 == V_103 ) {
F_34 ( V_89 , L_30 , V_10 -> V_15 ) ;
F_36 ( & V_10 -> V_76 . V_18 ) ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
return - V_98 ;
}
F_36 ( & V_10 -> V_76 . V_18 ) ;
V_97 = F_37 ( V_27 , V_82 ) ;
if ( V_97 )
goto V_104;
if ( F_38 ( V_82 -> V_105 ) == 0 ) {
V_58 type = F_39 ( V_82 -> V_105 ) ;
struct V_106 * V_107 =
(struct V_106 * ) V_82 -> V_108 ;
if ( type != V_109 || ! V_107 ) {
F_34 ( V_89 , L_31 ) ;
V_97 = - V_110 ;
goto V_111;
}
switch ( V_107 -> V_112 ) {
case V_113 :
F_28 ( V_89 , L_32 ,
V_107 -> V_52 , V_10 -> V_15 ) ;
F_40 ( V_10 -> V_114 ) ;
V_10 -> V_114 = F_41 ( V_82 -> V_89 ) ;
F_35 ( & V_10 -> V_76 . V_18 ) ;
V_10 -> V_76 . V_16 = V_115 ;
F_36 ( & V_10 -> V_76 . V_18 ) ;
if ( V_82 -> V_16 == - V_101 ) {
V_82 -> V_16 = 0 ;
}
goto V_111;
case V_116 :
if ( V_107 -> V_52 == F_17 ( V_117 << 8 ) )
F_32 (
L_33 ) ;
F_40 ( V_10 -> V_114 ) ;
V_10 -> V_114 = F_41 ( V_82 -> V_89 ) ;
goto V_118;
default:
F_34 ( V_89 ,
L_34 ,
V_107 -> V_112 ,
V_107 -> V_52 ) ;
V_97 = - V_110 ;
goto V_111;
}
}
V_118:
F_24 ( V_82 , V_10 ) ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
return 0 ;
V_111:
F_42 ( V_27 , V_82 ) ;
V_104:
F_7 ( & V_14 -> V_18 , V_17 ) ;
if ( ! V_97 )
F_43 ( V_27 , V_82 , V_82 -> V_16 ) ;
return V_97 ;
}
static int F_44 ( struct V_26 * V_27 , struct V_82 * V_82 , int V_16 )
{
struct V_13 * V_14 = F_13 ( V_27 ) ;
struct V_83 * V_84 ;
struct V_9 * V_10 ;
unsigned long V_17 ;
F_45 ( L_35 , V_82 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
V_84 = V_82 -> V_90 ;
if ( ! V_84 ) {
F_7 ( & V_14 -> V_18 , V_17 ) ;
return - V_119 ;
}
{
int V_97 = 0 ;
V_97 = F_46 ( V_27 , V_82 , V_16 ) ;
if ( V_97 ) {
F_7 ( & V_14 -> V_18 , V_17 ) ;
return V_97 ;
}
}
V_10 = V_84 -> V_10 ;
if ( ! V_10 -> V_76 . V_120 ) {
F_35 ( & V_10 -> V_87 ) ;
F_45 ( L_36 , V_10 ) ;
F_47 ( & V_84 -> V_91 ) ;
F_48 ( V_84 ) ;
V_82 -> V_90 = NULL ;
F_36 ( & V_10 -> V_87 ) ;
F_45 ( L_37 , V_82 ) ;
F_42 ( V_27 , V_82 ) ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
F_43 ( F_9 ( V_14 ) , V_82 , V_82 -> V_16 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
} else {
struct V_121 * V_122 ;
F_35 ( & V_10 -> V_87 ) ;
V_122 = F_25 ( sizeof( struct V_121 ) , V_85 ) ;
if ( ! V_122 ) {
F_36 ( & V_10 -> V_87 ) ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
F_26 ( & V_10 -> V_76 , V_86 ) ;
return - V_123 ;
}
V_122 -> V_88 = F_27 ( & V_14 -> V_88 ) ;
if ( V_122 -> V_88 == 0xffff )
F_45 ( L_27 ) ;
V_122 -> V_124 = V_84 -> V_88 ;
F_45 ( L_38 , V_10 ) ;
F_29 ( & V_122 -> V_91 , & V_10 -> V_125 ) ;
F_30 ( & V_10 -> V_93 ) ;
F_36 ( & V_10 -> V_87 ) ;
}
F_7 ( & V_14 -> V_18 , V_17 ) ;
F_32 ( L_39 ) ;
return 0 ;
}
static void F_49 ( struct V_9 * V_10 )
{
struct V_13 * V_14 = F_4 ( V_10 ) ;
struct V_26 * V_27 = F_9 ( V_14 ) ;
struct V_121 * V_122 , * V_126 ;
unsigned long V_17 ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
F_35 ( & V_10 -> V_87 ) ;
F_50 (unlink, tmp, &vdev->unlink_tx, list) {
F_45 ( L_40 , V_122 -> V_124 ) ;
F_47 ( & V_122 -> V_91 ) ;
F_48 ( V_122 ) ;
}
while ( ! F_51 ( & V_10 -> V_127 ) ) {
struct V_82 * V_82 ;
V_122 = F_52 ( & V_10 -> V_127 , struct V_121 ,
V_91 ) ;
F_45 ( L_41 , V_122 -> V_124 ) ;
V_82 = F_53 ( V_10 , V_122 -> V_124 ) ;
if ( ! V_82 ) {
F_45 ( L_42 ,
V_122 -> V_124 ) ;
F_47 ( & V_122 -> V_91 ) ;
F_48 ( V_122 ) ;
continue;
}
V_82 -> V_16 = - V_98 ;
F_42 ( V_27 , V_82 ) ;
F_47 ( & V_122 -> V_91 ) ;
F_36 ( & V_10 -> V_87 ) ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
F_43 ( V_27 , V_82 , V_82 -> V_16 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
F_35 ( & V_10 -> V_87 ) ;
F_48 ( V_122 ) ;
}
F_36 ( & V_10 -> V_87 ) ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
}
static void F_54 ( struct V_128 * V_76 )
{
struct V_9 * V_10 = F_55 ( V_76 , struct V_9 , V_76 ) ;
if ( V_76 -> V_120 ) {
F_2 ( L_43 , V_76 -> V_120 ) ;
F_56 ( V_76 -> V_120 , V_129 ) ;
}
if ( V_10 -> V_76 . V_130 ) {
F_57 ( V_10 -> V_76 . V_130 ) ;
V_10 -> V_76 . V_130 = NULL ;
}
if ( V_10 -> V_76 . V_131 ) {
F_57 ( V_10 -> V_76 . V_131 ) ;
V_10 -> V_76 . V_131 = NULL ;
}
F_45 ( L_44 ) ;
if ( V_10 -> V_76 . V_120 ) {
F_58 ( V_10 -> V_76 . V_120 ) ;
V_10 -> V_76 . V_120 = NULL ;
}
F_45 ( L_45 ) ;
F_49 ( V_10 ) ;
F_10 ( V_10 ) ;
F_45 ( L_46 ) ;
}
static void F_59 ( struct V_128 * V_76 )
{
struct V_9 * V_10 = F_55 ( V_76 , struct V_9 , V_76 ) ;
unsigned long V_17 ;
F_6 ( & V_76 -> V_18 , V_17 ) ;
V_10 -> V_12 = 0 ;
V_10 -> V_132 = 0 ;
F_40 ( V_10 -> V_114 ) ;
V_10 -> V_114 = NULL ;
if ( V_76 -> V_120 ) {
F_58 ( V_76 -> V_120 ) ;
V_76 -> V_120 = NULL ;
}
V_76 -> V_16 = V_102 ;
F_7 ( & V_76 -> V_18 , V_17 ) ;
}
static void F_60 ( struct V_128 * V_76 )
{
unsigned long V_17 ;
F_6 ( & V_76 -> V_18 , V_17 ) ;
V_76 -> V_16 = V_103 ;
F_7 ( & V_76 -> V_18 , V_17 ) ;
}
static void F_61 ( struct V_9 * V_10 )
{
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_76 . V_133 = V_134 ;
V_10 -> V_76 . V_16 = V_102 ;
F_62 ( & V_10 -> V_76 . V_18 ) ;
F_63 ( & V_10 -> V_135 ) ;
F_63 ( & V_10 -> V_92 ) ;
F_63 ( & V_10 -> V_125 ) ;
F_63 ( & V_10 -> V_127 ) ;
F_62 ( & V_10 -> V_87 ) ;
F_64 ( & V_10 -> V_93 ) ;
V_10 -> V_76 . V_136 . V_137 = F_54 ;
V_10 -> V_76 . V_136 . V_138 = F_59 ;
V_10 -> V_76 . V_136 . V_139 = F_60 ;
F_65 ( & V_10 -> V_76 ) ;
}
static int F_66 ( const char * V_140 )
{
char * V_141 ;
long V_142 ;
int V_97 ;
V_141 = strchr ( V_140 , '.' ) ;
if ( V_141 == NULL )
return 0 ;
V_97 = F_67 ( V_141 + 1 , 10 , & V_142 ) ;
if ( V_97 < 0 )
return V_97 ;
return V_142 ;
}
static int F_68 ( struct V_26 * V_27 )
{
struct V_13 * V_14 = F_13 ( V_27 ) ;
int V_143 , V_15 ;
int V_144 = 0 ;
F_32 ( L_47 ) ;
for ( V_15 = 0 ; V_15 < V_31 ; V_15 ++ ) {
struct V_9 * V_10 = & V_14 -> V_10 [ V_15 ] ;
F_61 ( V_10 ) ;
V_10 -> V_15 = V_15 ;
}
F_69 ( & V_14 -> V_88 , 0 ) ;
F_62 ( & V_14 -> V_18 ) ;
V_27 -> V_145 = 0 ;
V_27 -> V_146 = 1 ;
V_143 = F_66 ( F_70 ( V_27 ) ) ;
if ( V_143 < 0 ) {
F_20 ( L_48 , F_70 ( V_27 ) ) ;
return - V_110 ;
}
if ( V_143 == 0 ) {
V_144 = F_71 () ;
if ( V_144 ) {
F_20 ( L_49 ) ;
return V_144 ;
}
V_144 = F_72 ( & F_73 ( V_27 ) -> V_147 , & V_148 ) ;
if ( V_144 ) {
F_20 ( L_50 ) ;
F_74 () ;
return V_144 ;
}
F_45 ( L_51 , F_70 ( V_27 ) ) ;
}
return 0 ;
}
static void F_75 ( struct V_26 * V_27 )
{
struct V_13 * V_14 = F_13 ( V_27 ) ;
int V_143 , V_15 ;
F_32 ( L_52 ) ;
V_143 = F_66 ( F_70 ( V_27 ) ) ;
if ( V_143 == 0 ) {
F_76 ( & F_73 ( V_27 ) -> V_147 , & V_148 ) ;
F_74 () ;
}
for ( V_15 = 0 ; V_15 < V_31 ; V_15 ++ ) {
struct V_9 * V_10 = & V_14 -> V_10 [ V_15 ] ;
F_26 ( & V_10 -> V_76 , V_149 ) ;
F_77 ( & V_10 -> V_76 ) ;
}
}
static int F_78 ( struct V_26 * V_27 )
{
F_79 ( & V_27 -> V_150 . V_151 -> V_89 , L_53 ) ;
return 0 ;
}
static int F_80 ( struct V_26 * V_27 )
{
struct V_13 * V_14 = F_13 ( V_27 ) ;
unsigned long V_17 ;
F_81 ( & V_27 -> V_150 . V_151 -> V_89 , L_54 , V_152 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
V_27 -> V_34 = V_35 ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
return 0 ;
}
static int F_82 ( struct V_26 * V_27 )
{
struct V_13 * V_14 = F_13 ( V_27 ) ;
int V_153 = 0 ;
unsigned long V_17 ;
F_81 ( & V_27 -> V_150 . V_151 -> V_89 , L_54 , V_152 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
if ( ! F_14 ( V_27 ) )
V_153 = - V_154 ;
else
V_27 -> V_34 = V_155 ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
return V_153 ;
}
static int F_83 ( struct V_156 * V_157 )
{
struct V_26 * V_27 ;
int V_97 ;
F_32 ( L_55 , V_157 -> V_140 , V_157 -> V_143 ) ;
V_27 = F_84 ( & V_158 , & V_157 -> V_89 , F_85 ( & V_157 -> V_89 ) ) ;
if ( ! V_27 ) {
F_20 ( L_56 ) ;
return - V_123 ;
}
V_27 -> V_159 = 1 ;
V_97 = F_86 ( V_27 , 0 , 0 ) ;
if ( V_97 != 0 ) {
F_20 ( L_57 , V_97 ) ;
F_87 ( V_27 ) ;
return V_97 ;
}
F_32 ( L_58 ) ;
return 0 ;
}
static int F_88 ( struct V_156 * V_157 )
{
struct V_26 * V_27 ;
V_27 = F_89 ( V_157 ) ;
if ( ! V_27 )
return 0 ;
F_90 ( V_27 ) ;
F_87 ( V_27 ) ;
return 0 ;
}
static int F_91 ( struct V_156 * V_157 , T_5 V_34 )
{
struct V_26 * V_27 ;
struct V_13 * V_14 ;
int V_15 ;
int V_160 = 0 ;
int V_97 = 0 ;
unsigned long V_17 ;
V_27 = F_89 ( V_157 ) ;
if ( ! V_27 )
return 0 ;
V_14 = F_13 ( V_27 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
for ( V_15 = 0 ; V_15 < V_31 ; V_15 ++ )
if ( V_14 -> V_19 [ V_15 ] & V_20 )
V_160 += 1 ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
if ( V_160 > 0 ) {
F_28 ( & V_157 -> V_89 ,
L_59 ,
V_160 , ( V_160 == 1 ? L_60 : L_61 ) ) ;
V_97 = - V_161 ;
} else {
F_28 ( & V_157 -> V_89 , L_62 ) ;
F_92 ( V_162 , & V_27 -> V_17 ) ;
}
return V_97 ;
}
static int F_93 ( struct V_156 * V_157 )
{
struct V_26 * V_27 ;
F_81 ( & V_157 -> V_89 , L_54 , V_152 ) ;
V_27 = F_89 ( V_157 ) ;
if ( ! V_27 )
return 0 ;
F_94 ( V_162 , & V_27 -> V_17 ) ;
F_8 ( V_27 ) ;
return 0 ;
}
static int F_95 ( int V_143 )
{
struct V_156 * V_157 ;
int V_163 ;
if ( V_143 == 0 )
V_163 = - 1 ;
else
V_163 = V_143 ;
V_157 = F_96 ( V_164 , V_163 , NULL , 0 ) ;
if ( F_97 ( V_157 ) )
return F_98 ( V_157 ) ;
* ( V_165 + V_143 ) = V_157 ;
return 0 ;
}
static void F_99 ( void )
{
struct V_156 * V_157 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_166 ; V_3 ++ ) {
V_157 = * ( V_165 + V_3 ) ;
if ( V_157 != NULL )
F_100 ( V_157 ) ;
* ( V_165 + V_3 ) = NULL ;
}
F_101 ( & V_167 . V_147 , V_164 ) ;
}
static int T_6 F_102 ( void )
{
int V_3 , V_97 ;
if ( F_103 () )
return - V_98 ;
if ( V_166 < 1 )
V_166 = 1 ;
V_165 = F_104 ( V_166 , sizeof( void * ) , V_168 ) ;
if ( V_165 == NULL )
return - V_123 ;
V_97 = F_105 ( & V_169 ) ;
if ( V_97 )
goto V_170;
for ( V_3 = 0 ; V_3 < V_166 ; V_3 ++ ) {
V_97 = F_95 ( V_3 ) ;
if ( V_97 )
goto V_171;
}
F_45 ( V_172 L_63 V_173 L_3 ) ;
return V_97 ;
V_171:
F_99 () ;
F_106 ( & V_169 ) ;
V_170:
F_48 ( V_165 ) ;
return V_97 ;
}
static void T_7 F_107 ( void )
{
F_99 () ;
F_106 ( & V_169 ) ;
F_48 ( V_165 ) ;
}
