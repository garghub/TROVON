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
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_38 = V_39 ;
V_37 -> V_40 = 9 ;
V_37 -> V_41 = F_17 (
V_42 | V_43 ) ;
V_37 -> V_44 = V_31 ;
V_37 -> V_45 . V_46 . V_47 [ 0 ] = 0xff ;
V_37 -> V_45 . V_46 . V_47 [ 1 ] = 0xff ;
}
static int F_18 ( struct V_26 * V_27 , T_2 V_48 , T_2 V_49 ,
T_2 V_50 , char * V_28 , T_2 V_51 )
{
struct V_13 * V_52 ;
int V_29 = 0 ;
int V_15 ;
unsigned long V_17 ;
T_1 V_53 [ V_31 ] ;
if ( ! F_14 ( V_27 ) )
return - V_54 ;
F_5 ( L_8 , V_48 , V_49 ,
V_50 ) ;
if ( V_50 > V_31 )
F_19 ( L_9 , V_50 ) ;
V_15 = ( ( V_55 ) ( V_50 & 0x00ff ) ) - 1 ;
V_52 = F_13 ( V_27 ) ;
F_6 ( & V_52 -> V_18 , V_17 ) ;
if ( V_56 ) {
memcpy ( V_53 , V_52 -> V_19 ,
sizeof( V_53 ) ) ;
}
switch ( V_48 ) {
case V_57 :
F_5 ( L_10 ) ;
break;
case V_58 :
switch ( V_49 ) {
case V_59 :
if ( V_52 -> V_19 [ V_15 ] & V_60 ) {
V_52 -> V_61 = 1 ;
V_52 -> V_62 =
V_63 + F_20 ( 20 ) ;
}
break;
case V_64 :
F_5 (
L_11 ) ;
V_52 -> V_19 [ V_15 ] = 0 ;
V_52 -> V_61 = 0 ;
break;
case V_65 :
F_5 (
L_12 ) ;
switch ( V_52 -> V_10 [ V_15 ] . V_12 ) {
case V_22 :
V_52 -> V_19 [ V_15 ] |=
V_23 ;
break;
case V_24 :
V_52 -> V_19 [ V_15 ] |=
V_25 ;
break;
default:
break;
}
break;
default:
F_5 ( L_13 ,
V_49 ) ;
V_52 -> V_19 [ V_15 ] &= ~ ( 1 << V_49 ) ;
break;
}
break;
case V_66 :
F_5 ( L_14 ) ;
F_16 ( (struct V_36 * ) V_28 ) ;
break;
case V_67 :
F_5 ( L_15 ) ;
* ( V_68 * ) V_28 = F_21 ( 0 ) ;
break;
case V_69 :
F_5 ( L_16 , V_50 ) ;
if ( V_50 > V_31 || V_50 < 1 ) {
F_19 ( L_9 , V_50 ) ;
V_29 = - V_70 ;
}
if ( V_52 -> V_61 && F_22 ( V_63 , V_52 -> V_62 ) ) {
V_52 -> V_19 [ V_15 ] |=
( 1 << V_71 ) ;
V_52 -> V_19 [ V_15 ] &=
~ ( 1 << V_59 ) ;
V_52 -> V_61 = 0 ;
V_52 -> V_62 = 0 ;
}
if ( ( V_52 -> V_19 [ V_15 ] & ( 1 << V_72 ) ) !=
0 && F_22 ( V_63 , V_52 -> V_62 ) ) {
V_52 -> V_19 [ V_15 ] |=
( 1 << V_65 ) ;
V_52 -> V_19 [ V_15 ] &=
~ ( 1 << V_72 ) ;
V_52 -> V_62 = 0 ;
if ( V_52 -> V_10 [ V_15 ] . V_73 . V_16 ==
V_74 ) {
F_5 (
L_17 ,
V_15 ,
V_52 -> V_10 [ V_15 ] . V_73 . V_16 ) ;
V_52 -> V_19 [ V_15 ] |=
V_75 ;
}
}
( ( V_76 * ) V_28 ) [ 0 ] = F_17 ( V_52 -> V_19 [ V_15 ] ) ;
( ( V_76 * ) V_28 ) [ 1 ] =
F_17 ( V_52 -> V_19 [ V_15 ] >> 16 ) ;
F_5 ( L_18 , ( ( T_2 * ) V_28 ) [ 0 ] ,
( ( T_2 * ) V_28 ) [ 1 ] ) ;
break;
case V_77 :
F_5 ( L_19 ) ;
V_29 = - V_70 ;
break;
case V_78 :
switch ( V_49 ) {
case V_59 :
F_5 (
L_20 ) ;
break;
case V_72 :
F_5 (
L_21 ) ;
if ( V_52 -> V_19 [ V_15 ] & V_75 ) {
V_52 -> V_19 [ V_15 ] &=
~ ( V_75 |
V_25 |
V_23 ) ;
}
V_52 -> V_62 = V_63 + F_20 ( 50 ) ;
default:
F_5 ( L_22 ,
V_49 ) ;
V_52 -> V_19 [ V_15 ] |= ( 1 << V_49 ) ;
break;
}
break;
default:
F_19 ( L_23 ) ;
V_29 = - V_70 ;
}
if ( V_56 ) {
F_2 ( L_24 , V_15 ) ;
if ( V_15 >= 0 ) {
F_1 ( V_53 [ V_15 ] ,
V_52 -> V_19 [ V_15 ] ) ;
}
}
F_5 ( L_25 ) ;
F_7 ( & V_52 -> V_18 , V_17 ) ;
return V_29 ;
}
static struct V_9 * F_23 ( struct V_79 * V_80 )
{
struct V_81 * V_82 ;
struct V_26 * V_27 ;
struct V_13 * V_14 ;
int V_83 , V_15 ;
if ( ! V_80 )
return NULL ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ ) {
V_82 = * ( V_85 + V_83 ) ;
if ( V_82 == NULL )
continue;
V_27 = F_24 ( V_82 ) ;
if ( V_27 == NULL )
continue;
V_14 = F_13 ( V_27 ) ;
for ( V_15 = 0 ; V_15 < V_31 ; V_15 ++ ) {
if ( V_14 -> V_10 [ V_15 ] . V_80 == V_80 )
return & V_14 -> V_10 [ V_15 ] ;
}
}
return NULL ;
}
static void F_25 ( struct V_86 * V_86 )
{
struct V_9 * V_10 = F_23 ( V_86 -> V_87 ) ;
struct V_88 * V_89 ;
struct V_13 * V_14 ;
unsigned long V_17 ;
if ( ! V_10 ) {
F_19 ( L_26 ) ;
return;
}
V_14 = F_4 ( V_10 ) ;
V_89 = F_26 ( sizeof( struct V_88 ) , V_90 ) ;
if ( ! V_89 ) {
F_27 ( & V_10 -> V_73 , V_91 ) ;
return;
}
F_6 ( & V_10 -> V_92 , V_17 ) ;
V_89 -> V_93 = F_28 ( & V_14 -> V_93 ) ;
if ( V_89 -> V_93 == 0xffff )
F_29 ( & V_86 -> V_87 -> V_87 , L_27 ) ;
V_89 -> V_10 = V_10 ;
V_89 -> V_86 = V_86 ;
V_86 -> V_94 = ( void * ) V_89 ;
F_30 ( & V_89 -> V_95 , & V_10 -> V_96 ) ;
F_31 ( & V_10 -> V_97 ) ;
F_7 ( & V_10 -> V_92 , V_17 ) ;
}
static int F_32 ( struct V_26 * V_27 , struct V_86 * V_86 ,
T_3 V_98 )
{
struct V_13 * V_14 = F_13 ( V_27 ) ;
struct V_99 * V_87 = & V_86 -> V_87 -> V_87 ;
T_4 V_100 = V_86 -> V_87 -> V_100 ;
int V_101 = 0 ;
struct V_9 * V_10 ;
unsigned long V_17 ;
F_33 ( L_28 ,
V_27 , V_86 , V_98 ) ;
if ( V_100 > V_31 ) {
F_19 ( L_9 , V_100 ) ;
return - V_102 ;
}
V_10 = & V_14 -> V_10 [ V_100 - 1 ] ;
F_34 ( ! V_86 -> V_103 && V_86 -> V_104 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
if ( V_86 -> V_16 != - V_105 ) {
F_35 ( V_87 , L_29 , V_86 -> V_16 ) ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
return V_86 -> V_16 ;
}
F_36 ( & V_10 -> V_73 . V_18 ) ;
if ( V_10 -> V_73 . V_16 == V_106 ||
V_10 -> V_73 . V_16 == V_107 ) {
F_35 ( V_87 , L_30 , V_10 -> V_15 ) ;
F_37 ( & V_10 -> V_73 . V_18 ) ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
return - V_102 ;
}
F_37 ( & V_10 -> V_73 . V_18 ) ;
V_101 = F_38 ( V_27 , V_86 ) ;
if ( V_101 )
goto V_108;
if ( F_39 ( V_86 -> V_109 ) == 0 ) {
V_55 type = F_40 ( V_86 -> V_109 ) ;
struct V_110 * V_111 =
(struct V_110 * ) V_86 -> V_112 ;
if ( type != V_113 || ! V_111 ) {
F_35 ( V_87 , L_31 ) ;
V_101 = - V_114 ;
goto V_115;
}
switch ( V_111 -> V_116 ) {
case V_117 :
F_29 ( V_87 , L_32 ,
V_111 -> V_49 , V_10 -> V_15 ) ;
F_41 ( V_10 -> V_80 ) ;
V_10 -> V_80 = F_42 ( V_86 -> V_87 ) ;
F_36 ( & V_10 -> V_73 . V_18 ) ;
V_10 -> V_73 . V_16 = V_118 ;
F_37 ( & V_10 -> V_73 . V_18 ) ;
if ( V_86 -> V_16 == - V_105 ) {
V_86 -> V_16 = 0 ;
}
goto V_115;
case V_119 :
if ( V_111 -> V_49 == F_17 ( V_120 << 8 ) )
F_33 (
L_33 ) ;
F_41 ( V_10 -> V_80 ) ;
V_10 -> V_80 = F_42 ( V_86 -> V_87 ) ;
goto V_121;
default:
F_35 ( V_87 ,
L_34 ,
V_111 -> V_116 ,
V_111 -> V_49 ) ;
V_101 = - V_114 ;
goto V_115;
}
}
V_121:
F_25 ( V_86 ) ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
return 0 ;
V_115:
F_43 ( V_27 , V_86 ) ;
V_108:
F_7 ( & V_14 -> V_18 , V_17 ) ;
if ( ! V_101 )
F_44 ( V_27 , V_86 , V_86 -> V_16 ) ;
return V_101 ;
}
static int F_45 ( struct V_26 * V_27 , struct V_86 * V_86 , int V_16 )
{
struct V_13 * V_14 = F_13 ( V_27 ) ;
struct V_88 * V_89 ;
struct V_9 * V_10 ;
unsigned long V_17 ;
F_46 ( L_35 , V_86 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
V_89 = V_86 -> V_94 ;
if ( ! V_89 ) {
F_7 ( & V_14 -> V_18 , V_17 ) ;
return - V_122 ;
}
{
int V_101 = 0 ;
V_101 = F_47 ( V_27 , V_86 , V_16 ) ;
if ( V_101 ) {
F_7 ( & V_14 -> V_18 , V_17 ) ;
return V_101 ;
}
}
V_10 = V_89 -> V_10 ;
if ( ! V_10 -> V_73 . V_123 ) {
F_36 ( & V_10 -> V_92 ) ;
F_46 ( L_36 , V_10 ) ;
F_48 ( & V_89 -> V_95 ) ;
F_49 ( V_89 ) ;
V_86 -> V_94 = NULL ;
F_37 ( & V_10 -> V_92 ) ;
F_46 ( L_37 , V_86 ) ;
F_43 ( V_27 , V_86 ) ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
F_44 ( F_9 ( V_14 ) , V_86 , V_86 -> V_16 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
} else {
struct V_124 * V_125 ;
F_36 ( & V_10 -> V_92 ) ;
V_125 = F_26 ( sizeof( struct V_124 ) , V_90 ) ;
if ( ! V_125 ) {
F_37 ( & V_10 -> V_92 ) ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
F_27 ( & V_10 -> V_73 , V_91 ) ;
return - V_126 ;
}
V_125 -> V_93 = F_28 ( & V_14 -> V_93 ) ;
if ( V_125 -> V_93 == 0xffff )
F_46 ( L_27 ) ;
V_125 -> V_127 = V_89 -> V_93 ;
F_46 ( L_38 , V_10 ) ;
F_30 ( & V_125 -> V_95 , & V_10 -> V_128 ) ;
F_31 ( & V_10 -> V_97 ) ;
F_37 ( & V_10 -> V_92 ) ;
}
F_7 ( & V_14 -> V_18 , V_17 ) ;
F_33 ( L_39 ) ;
return 0 ;
}
static void F_50 ( struct V_9 * V_10 )
{
struct V_13 * V_14 = F_4 ( V_10 ) ;
struct V_26 * V_27 = F_9 ( V_14 ) ;
struct V_124 * V_125 , * V_129 ;
unsigned long V_17 ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
F_36 ( & V_10 -> V_92 ) ;
F_51 (unlink, tmp, &vdev->unlink_tx, list) {
F_46 ( L_40 , V_125 -> V_127 ) ;
F_48 ( & V_125 -> V_95 ) ;
F_49 ( V_125 ) ;
}
while ( ! F_52 ( & V_10 -> V_130 ) ) {
struct V_86 * V_86 ;
V_125 = F_53 ( & V_10 -> V_130 , struct V_124 ,
V_95 ) ;
F_46 ( L_41 , V_125 -> V_127 ) ;
V_86 = F_54 ( V_10 , V_125 -> V_127 ) ;
if ( ! V_86 ) {
F_46 ( L_42 ,
V_125 -> V_127 ) ;
F_48 ( & V_125 -> V_95 ) ;
F_49 ( V_125 ) ;
continue;
}
V_86 -> V_16 = - V_102 ;
F_43 ( V_27 , V_86 ) ;
F_48 ( & V_125 -> V_95 ) ;
F_37 ( & V_10 -> V_92 ) ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
F_44 ( V_27 , V_86 , V_86 -> V_16 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
F_36 ( & V_10 -> V_92 ) ;
F_49 ( V_125 ) ;
}
F_37 ( & V_10 -> V_92 ) ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
}
static void F_55 ( struct V_131 * V_73 )
{
struct V_9 * V_10 = F_56 ( V_73 , struct V_9 , V_73 ) ;
if ( V_73 -> V_123 ) {
F_2 ( L_43 , V_73 -> V_123 ) ;
F_57 ( V_73 -> V_123 , V_132 ) ;
}
if ( V_10 -> V_73 . V_133 ) {
F_58 ( V_10 -> V_73 . V_133 ) ;
V_10 -> V_73 . V_133 = NULL ;
}
if ( V_10 -> V_73 . V_134 ) {
F_58 ( V_10 -> V_73 . V_134 ) ;
V_10 -> V_73 . V_134 = NULL ;
}
F_46 ( L_44 ) ;
if ( V_10 -> V_73 . V_123 ) {
F_59 ( V_10 -> V_73 . V_123 ) ;
V_10 -> V_73 . V_123 = NULL ;
}
F_46 ( L_45 ) ;
F_50 ( V_10 ) ;
F_10 ( V_10 ) ;
F_46 ( L_46 ) ;
}
static void F_60 ( struct V_131 * V_73 )
{
struct V_9 * V_10 = F_56 ( V_73 , struct V_9 , V_73 ) ;
unsigned long V_17 ;
F_6 ( & V_73 -> V_18 , V_17 ) ;
V_10 -> V_12 = 0 ;
V_10 -> V_135 = 0 ;
F_41 ( V_10 -> V_80 ) ;
V_10 -> V_80 = NULL ;
if ( V_73 -> V_123 ) {
F_59 ( V_73 -> V_123 ) ;
V_73 -> V_123 = NULL ;
}
V_73 -> V_16 = V_106 ;
F_7 ( & V_73 -> V_18 , V_17 ) ;
}
static void F_61 ( struct V_131 * V_73 )
{
unsigned long V_17 ;
F_6 ( & V_73 -> V_18 , V_17 ) ;
V_73 -> V_16 = V_107 ;
F_7 ( & V_73 -> V_18 , V_17 ) ;
}
static void F_62 ( struct V_9 * V_10 )
{
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_73 . V_136 = V_137 ;
V_10 -> V_73 . V_16 = V_106 ;
F_63 ( & V_10 -> V_73 . V_18 ) ;
F_64 ( & V_10 -> V_138 ) ;
F_64 ( & V_10 -> V_96 ) ;
F_64 ( & V_10 -> V_128 ) ;
F_64 ( & V_10 -> V_130 ) ;
F_63 ( & V_10 -> V_92 ) ;
F_65 ( & V_10 -> V_97 ) ;
V_10 -> V_73 . V_139 . V_140 = F_55 ;
V_10 -> V_73 . V_139 . V_141 = F_60 ;
V_10 -> V_73 . V_139 . V_142 = F_61 ;
F_66 ( & V_10 -> V_73 ) ;
}
static int F_67 ( const char * V_143 )
{
char * V_144 ;
long V_145 ;
int V_101 ;
V_144 = strchr ( V_143 , '.' ) ;
if ( V_144 == NULL )
return 0 ;
V_101 = F_68 ( V_144 + 1 , 10 , & V_145 ) ;
if ( V_101 < 0 )
return V_101 ;
return V_145 ;
}
static int F_69 ( struct V_26 * V_27 )
{
struct V_13 * V_14 = F_13 ( V_27 ) ;
int V_146 , V_15 ;
int V_147 = 0 ;
F_33 ( L_47 ) ;
for ( V_15 = 0 ; V_15 < V_31 ; V_15 ++ ) {
struct V_9 * V_10 = & V_14 -> V_10 [ V_15 ] ;
F_62 ( V_10 ) ;
V_10 -> V_15 = V_15 ;
}
F_70 ( & V_14 -> V_93 , 0 ) ;
F_63 ( & V_14 -> V_18 ) ;
V_27 -> V_148 = 0 ;
V_27 -> V_149 = 1 ;
V_146 = F_67 ( F_71 ( V_27 ) ) ;
if ( V_146 < 0 ) {
F_19 ( L_48 , F_71 ( V_27 ) ) ;
return - V_114 ;
}
if ( V_146 == 0 ) {
V_147 = F_72 () ;
if ( V_147 ) {
F_19 ( L_49 ) ;
return V_147 ;
}
V_147 = F_73 ( & F_74 ( V_27 ) -> V_150 , & V_151 ) ;
if ( V_147 ) {
F_19 ( L_50 ) ;
F_75 () ;
return V_147 ;
}
F_46 ( L_51 , F_71 ( V_27 ) ) ;
}
return 0 ;
}
static void F_76 ( struct V_26 * V_27 )
{
struct V_13 * V_14 = F_13 ( V_27 ) ;
int V_146 , V_15 ;
F_33 ( L_52 ) ;
V_146 = F_67 ( F_71 ( V_27 ) ) ;
if ( V_146 == 0 ) {
F_77 ( & F_74 ( V_27 ) -> V_150 , & V_151 ) ;
F_75 () ;
}
for ( V_15 = 0 ; V_15 < V_31 ; V_15 ++ ) {
struct V_9 * V_10 = & V_14 -> V_10 [ V_15 ] ;
F_27 ( & V_10 -> V_73 , V_152 ) ;
F_78 ( & V_10 -> V_73 ) ;
}
}
static int F_79 ( struct V_26 * V_27 )
{
F_80 ( & V_27 -> V_153 . V_154 -> V_87 , L_53 ) ;
return 0 ;
}
static int F_81 ( struct V_26 * V_27 )
{
struct V_13 * V_14 = F_13 ( V_27 ) ;
unsigned long V_17 ;
F_82 ( & V_27 -> V_153 . V_154 -> V_87 , L_54 , V_155 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
V_27 -> V_34 = V_35 ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
return 0 ;
}
static int F_83 ( struct V_26 * V_27 )
{
struct V_13 * V_14 = F_13 ( V_27 ) ;
int V_156 = 0 ;
unsigned long V_17 ;
F_82 ( & V_27 -> V_153 . V_154 -> V_87 , L_54 , V_155 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
if ( ! F_14 ( V_27 ) )
V_156 = - V_157 ;
else
V_27 -> V_34 = V_158 ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
return V_156 ;
}
static int F_84 ( struct V_81 * V_82 )
{
struct V_26 * V_27 ;
int V_101 ;
F_33 ( L_55 , V_82 -> V_143 , V_82 -> V_146 ) ;
V_27 = F_85 ( & V_159 , & V_82 -> V_87 , F_86 ( & V_82 -> V_87 ) ) ;
if ( ! V_27 ) {
F_19 ( L_56 ) ;
return - V_126 ;
}
V_27 -> V_160 = 1 ;
V_101 = F_87 ( V_27 , 0 , 0 ) ;
if ( V_101 != 0 ) {
F_19 ( L_57 , V_101 ) ;
F_88 ( V_27 ) ;
return V_101 ;
}
F_33 ( L_58 ) ;
return 0 ;
}
static int F_89 ( struct V_81 * V_82 )
{
struct V_26 * V_27 ;
V_27 = F_24 ( V_82 ) ;
if ( ! V_27 )
return 0 ;
F_90 ( V_27 ) ;
F_88 ( V_27 ) ;
return 0 ;
}
static int F_91 ( struct V_81 * V_82 , T_5 V_34 )
{
struct V_26 * V_27 ;
struct V_13 * V_14 ;
int V_15 ;
int V_161 = 0 ;
int V_101 = 0 ;
unsigned long V_17 ;
V_27 = F_24 ( V_82 ) ;
if ( ! V_27 )
return 0 ;
V_14 = F_13 ( V_27 ) ;
F_6 ( & V_14 -> V_18 , V_17 ) ;
for ( V_15 = 0 ; V_15 < V_31 ; V_15 ++ )
if ( V_14 -> V_19 [ V_15 ] & V_20 )
V_161 += 1 ;
F_7 ( & V_14 -> V_18 , V_17 ) ;
if ( V_161 > 0 ) {
F_29 ( & V_82 -> V_87 ,
L_59 ,
V_161 , ( V_161 == 1 ? L_60 : L_61 ) ) ;
V_101 = - V_162 ;
} else {
F_29 ( & V_82 -> V_87 , L_62 ) ;
F_92 ( V_163 , & V_27 -> V_17 ) ;
}
return V_101 ;
}
static int F_93 ( struct V_81 * V_82 )
{
struct V_26 * V_27 ;
F_82 ( & V_82 -> V_87 , L_54 , V_155 ) ;
V_27 = F_24 ( V_82 ) ;
if ( ! V_27 )
return 0 ;
F_94 ( V_163 , & V_27 -> V_17 ) ;
F_8 ( V_27 ) ;
return 0 ;
}
static int F_95 ( int V_146 )
{
struct V_81 * V_82 ;
int V_164 ;
if ( V_146 == 0 )
V_164 = - 1 ;
else
V_164 = V_146 ;
V_82 = F_96 ( V_165 , V_164 , NULL , 0 ) ;
if ( F_97 ( V_82 ) )
return F_98 ( V_82 ) ;
* ( V_85 + V_146 ) = V_82 ;
return 0 ;
}
static void F_99 ( void )
{
struct V_81 * V_82 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_84 ; V_3 ++ ) {
V_82 = * ( V_85 + V_3 ) ;
if ( V_82 != NULL )
F_100 ( V_82 ) ;
* ( V_85 + V_3 ) = NULL ;
}
F_101 ( & V_166 . V_150 , V_165 ) ;
}
static int T_6 F_102 ( void )
{
int V_3 , V_101 ;
if ( F_103 () )
return - V_102 ;
if ( V_84 < 1 )
V_84 = 1 ;
V_85 = F_104 ( V_84 , sizeof( void * ) , V_167 ) ;
if ( V_85 == NULL )
return - V_126 ;
V_101 = F_105 ( & V_168 ) ;
if ( V_101 )
goto V_169;
for ( V_3 = 0 ; V_3 < V_84 ; V_3 ++ ) {
V_101 = F_95 ( V_3 ) ;
if ( V_101 )
goto V_170;
}
F_46 ( V_171 L_63 V_172 L_3 ) ;
return V_101 ;
V_170:
F_99 () ;
F_106 ( & V_168 ) ;
V_169:
F_49 ( V_85 ) ;
return V_101 ;
}
static void T_7 F_107 ( void )
{
F_99 () ;
F_106 ( & V_168 ) ;
F_49 ( V_85 ) ;
}
