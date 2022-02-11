static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = 0 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
V_4 = F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_9 ) ;
if ( V_4 != V_10 )
break;
F_3 ( 1 ) ;
}
if ( V_4 != V_10 ) {
F_4 ( V_4 , & V_2 -> V_6 . V_7 . V_8 -> V_11 ) ;
F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_12 ) ;
return 0 ;
}
return - 1 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_6 ( V_2 , V_13 , V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_14 )
{
if ( V_14 & V_15 )
F_8 ( V_2 ,
V_14 & ~ V_15 ) ;
else
F_9 ( V_2 , V_14 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_4 ;
while ( ( V_4 = F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_11 ) ) !=
V_10 ) {
if ( V_4 & V_16 )
F_7 ( V_2 , V_4 ) ;
else {
struct V_17 T_2 * V_18 ;
V_18 = (struct V_17 T_2 * )
( ( char T_2 * ) V_2 -> V_6 . V_7 . V_8 + V_4 ) ;
if ( F_2 ( & V_18 -> V_19 ) & V_20 ) {
if ( F_2 ( & V_18 -> V_21 ) )
F_7 ( V_2 , V_4 ) ;
else
F_4 ( 1 , & V_18 -> V_21 ) ;
}
else
F_7 ( V_2 , V_4 ) ;
}
}
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_22 T_2 * V_8 = V_2 -> V_6 . V_7 . V_8 ;
void T_2 * V_23 = V_2 -> V_6 . V_7 . V_23 ;
T_1 V_24 ;
int V_25 = 0 ;
if ( V_23 && F_2 ( V_23 + 0x11C5C ) & 0xf )
F_4 ( 1 , V_23 + 0x11C60 ) ;
V_24 = F_2 ( & V_8 -> V_12 ) ;
if ( V_24 & V_26 ) {
T_1 V_27 = F_2 ( & V_8 -> V_28 ) ;
F_12 ( L_1 , V_27 ) ;
F_4 ( V_26 , & V_8 -> V_12 ) ;
F_13 ( V_2 , V_27 ) ;
V_25 = 1 ;
}
if ( V_24 & V_29 ) {
F_10 ( V_2 ) ;
V_25 = 1 ;
}
return V_25 ;
}
static T_3 F_14 ( struct V_30 T_2 * V_31 )
{
T_1 V_32 = F_2 ( & V_31 -> V_32 ) ;
T_1 V_33 = F_2 ( & V_31 -> V_33 ) ;
if ( V_32 != V_33 ) {
T_3 V_18 ;
F_15 ( & V_18 , & V_31 -> V_34 [ V_31 -> V_32 ] , 8 ) ;
V_32 ++ ;
if ( V_32 == V_35 )
V_32 = 0 ;
F_4 ( V_32 , & V_31 -> V_32 ) ;
return V_18 ;
} else
return 0 ;
}
static void F_16 ( T_3 V_18 , struct V_1 * V_2 )
{
T_1 V_36 = F_2 ( & V_2 -> V_6 . V_37 . V_31 -> V_36 ) ;
T_1 V_38 = V_36 + 1 ;
if ( V_38 == V_35 )
V_38 = 0 ;
F_17 ( & V_2 -> V_6 . V_37 . V_31 -> V_39 [ V_36 ] , & V_18 , 8 ) ;
F_4 ( V_38 , & V_2 -> V_6 . V_37 . V_31 -> V_36 ) ;
F_4 ( V_40 ,
& V_2 -> V_6 . V_37 . V_41 -> V_42 ) ;
}
static void F_18 ( struct V_1 * V_2 , T_3 V_14 )
{
T_1 V_43 = ( V_14 >> 5 ) & 0x7 ;
struct V_44 * V_4 ;
F_12 ( L_2 , V_14 ) ;
F_19 ( ( V_14 & V_45 ) == 0 ) ;
switch ( V_43 ) {
case V_46 :
case V_47 :
V_2 -> V_48 = 1 ;
break;
case V_49 :
V_4 = V_2 -> V_50 [ V_14 >> 8 ] . V_51 ;
if ( F_20 ( V_14 & V_52 ) )
V_4 -> V_53 . V_54 = F_21 ( V_55 ) ;
F_22 ( V_2 , V_14 >> 8 , V_4 ) ;
break;
default:
break;
}
}
static int F_23 ( struct V_1 * V_2 )
{
T_1 V_24 ;
int V_25 = 0 ;
V_24 = F_2 ( & V_2 -> V_6 . V_37 . V_41 -> V_56 ) ;
F_4 ( ~ V_24 , & V_2 -> V_6 . V_37 . V_41 -> V_56 ) ;
if ( V_24 & V_57 ) {
T_1 V_27 ;
V_27 = F_2 ( & V_2 -> V_6 . V_37 . V_31 -> V_58 ) ;
F_12 ( L_1 , V_27 ) ;
F_13 ( V_2 , V_27 ) ;
V_25 = 1 ;
}
if ( V_24 & V_59 ) {
T_3 V_14 ;
while ( ( V_14 = F_14 ( V_2 -> V_6 . V_37 . V_31 ) ) )
F_18 ( V_2 , V_14 ) ;
V_25 = 1 ;
}
return V_25 ;
}
static int F_24 ( struct V_1 * V_2 ,
void T_2 * V_60 , T_1 V_3 )
{
struct V_17 T_2 * V_4 = V_60 ;
T_1 V_5 ;
F_4 ( F_2 ( & V_4 -> V_19 ) | V_20 , & V_4 -> V_19 ) ;
F_4 ( 0 , & V_4 -> V_21 ) ;
F_4 ( ( unsigned long ) V_4 - ( unsigned long ) V_2 -> V_6 . V_7 . V_8 ,
& V_2 -> V_6 . V_7 . V_8 -> V_9 ) ;
F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_12 ) ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
F_11 ( V_2 ) ;
if ( F_2 ( & V_4 -> V_21 ) )
return 0 ;
F_3 ( 1 ) ;
}
return - 1 ;
}
static int F_25 ( struct V_1 * V_2 ,
T_1 V_61 , T_1 V_3 )
{
struct V_17 * V_62 = V_2 -> V_6 . V_37 . V_63 ;
T_1 V_5 ;
V_2 -> V_48 = 0 ;
V_62 -> V_19 |= F_21 ( V_20 ) ;
F_16 ( V_2 -> V_6 . V_37 . V_64 |
V_65 | V_61 , V_2 ) ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
F_23 ( V_2 ) ;
if ( V_2 -> V_48 )
return 0 ;
F_3 ( 1 ) ;
}
return - 1 ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_27 )
{
F_4 ( V_27 , & V_2 -> V_6 . V_7 . V_8 -> V_66 ) ;
F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_12 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_1 V_27 )
{
F_4 ( V_27 , & V_2 -> V_6 . V_37 . V_31 -> V_67 ) ;
F_4 ( V_68 , & V_2 -> V_6 . V_37 . V_41 -> V_42 ) ;
F_2 ( & V_2 -> V_6 . V_37 . V_41 -> V_42 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_27 , T_1 V_3 )
{
T_1 V_5 ;
V_2 -> V_48 = 0 ;
V_2 -> V_69 -> V_70 ( V_2 , V_27 ) ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
F_28 ( V_2 -> V_71 -> V_72 ) ;
V_2 -> V_69 -> V_73 ( V_2 ) ;
F_29 ( V_2 -> V_71 -> V_72 ) ;
if ( V_2 -> V_48 )
break;
F_3 ( 1 ) ;
}
return V_2 -> V_48 ? 0 : - 1 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_74 * V_75 )
{
T_1 V_76 ;
struct V_74 T_2 * V_4 ;
V_76 = F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_9 ) ;
if ( V_76 == V_10 )
return - 1 ;
V_4 = (struct V_74 T_2 * )
( ( unsigned long ) V_2 -> V_6 . V_7 . V_8 + V_76 ) ;
F_4 ( 0 , & V_4 -> V_53 . V_19 ) ;
F_4 ( V_46 , & V_4 -> V_53 . type ) ;
F_4 ( sizeof( struct V_74 ) , & V_4 -> V_53 . V_77 ) ;
F_4 ( V_78 , & V_4 -> V_53 . V_54 ) ;
if ( F_24 ( V_2 , V_4 , 20000 ) ) {
F_12 ( L_3 ) ;
return - 1 ;
}
F_15 ( V_75 , V_4 , sizeof( * V_75 ) ) ;
F_4 ( V_76 , & V_2 -> V_6 . V_7 . V_8 -> V_11 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_74 * V_75 )
{
struct V_74 * V_4 = V_2 -> V_6 . V_37 . V_63 ;
V_4 -> V_53 . V_19 = F_21 ( V_79 ) ;
V_4 -> V_53 . type = F_21 ( V_46 ) ;
V_4 -> V_53 . V_77 =
F_21 ( sizeof( struct V_74 ) ) ;
V_4 -> V_53 . V_54 = F_21 ( V_78 ) ;
V_4 -> V_53 . V_21 = F_21 ( V_46 << 5 ) ;
V_4 -> V_53 . V_80 = 0 ;
if ( F_25 ( V_2 , 0 , 20000 ) ) {
F_12 ( L_3 ) ;
return - 1 ;
}
memcpy ( V_75 , V_4 , sizeof( struct V_74 ) ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_81 * V_75 )
{
T_1 V_76 ;
struct V_81 T_2 * V_4 ;
V_76 = F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_9 ) ;
if ( V_76 == V_10 )
return - 1 ;
V_4 = (struct V_81 T_2 * )
( ( unsigned long ) V_2 -> V_6 . V_7 . V_8 + V_76 ) ;
F_17 ( ( V_82 T_2 * ) V_4 + sizeof( struct V_17 ) ,
( V_82 * ) V_75 + sizeof( struct V_17 ) ,
sizeof( struct V_81 ) -
sizeof( struct V_17 ) ) ;
F_4 ( 0 , & V_4 -> V_53 . V_19 ) ;
F_4 ( V_47 , & V_4 -> V_53 . type ) ;
F_4 ( sizeof( struct V_81 ) , & V_4 -> V_53 . V_77 ) ;
F_4 ( V_78 , & V_4 -> V_53 . V_54 ) ;
if ( F_24 ( V_2 , V_4 , 20000 ) ) {
F_12 ( L_4 ) ;
return - 1 ;
}
F_4 ( V_76 , & V_2 -> V_6 . V_7 . V_8 -> V_11 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_81 * V_75 )
{
struct V_81 * V_4 = V_2 -> V_6 . V_37 . V_63 ;
memcpy ( V_4 , V_75 , sizeof( struct V_81 ) ) ;
V_4 -> V_53 . V_19 = F_21 ( V_79 ) ;
V_4 -> V_53 . type = F_21 ( V_47 ) ;
V_4 -> V_53 . V_77 =
F_21 ( sizeof( struct V_81 ) ) ;
V_4 -> V_53 . V_54 = F_21 ( V_78 ) ;
V_4 -> V_53 . V_21 = F_21 ( V_47 << 5 ) ;
V_4 -> V_53 . V_80 = 0 ;
if ( F_25 ( V_2 , 0 , 20000 ) ) {
F_12 ( L_4 ) ;
return - 1 ;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_4 ( ~ ( V_29 | V_26 ) ,
& V_2 -> V_6 . V_7 . V_8 -> V_83 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_4 ( V_59 | V_57 ,
& V_2 -> V_6 . V_37 . V_41 -> V_83 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
V_2 -> V_69 -> V_84 ( V_2 ) ;
V_2 -> V_85 = 1 ;
if ( F_6 ( V_2 ,
V_86 , 5000 ) ) {
F_37 ( V_87 L_5 ,
V_2 -> V_71 -> V_88 ) ;
return - 1 ;
}
return 0 ;
}
static void T_2 * F_38 ( struct V_1 * V_2 , int V_89 )
{
T_1 V_90 , V_91 ;
void T_2 * V_92 ;
struct V_93 * V_94 = V_2 -> V_94 ;
if ( ! ( F_39 ( V_94 , V_89 ) & V_95 ) ) {
F_37 ( V_87 L_6 ,
V_2 -> V_71 -> V_88 ) ;
return NULL ;
}
V_90 = F_40 ( V_94 , V_89 ) ;
V_91 = F_41 ( V_94 , V_89 ) ;
V_92 = F_42 ( V_90 , V_91 ) ;
if ( ! V_92 ) {
F_37 ( V_87 L_7 ,
V_2 -> V_71 -> V_88 ) ;
return NULL ;
}
return V_92 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_93 * V_94 = V_2 -> V_94 ;
V_2 -> V_6 . V_7 . V_8 = F_38 ( V_2 , 0 ) ;
if ( V_2 -> V_6 . V_7 . V_8 == NULL )
return - 1 ;
if ( ( V_94 -> V_96 & 0xff00 ) == 0x4400 ) {
V_2 -> V_6 . V_7 . V_23 = V_2 -> V_6 . V_7 . V_8 ;
V_2 -> V_6 . V_7 . V_8 = F_38 ( V_2 , 2 ) ;
if ( V_2 -> V_6 . V_7 . V_8 == NULL ) {
F_44 ( V_2 -> V_6 . V_7 . V_23 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_7 . V_23 )
F_44 ( V_2 -> V_6 . V_7 . V_23 ) ;
F_44 ( V_2 -> V_6 . V_7 . V_8 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_37 . V_41 = F_38 ( V_2 , 0 ) ;
if ( V_2 -> V_6 . V_37 . V_41 == NULL )
return - 1 ;
V_2 -> V_6 . V_37 . V_31 = F_38 ( V_2 , 2 ) ;
if ( V_2 -> V_6 . V_37 . V_31 == NULL ) {
F_44 ( V_2 -> V_6 . V_37 . V_41 ) ;
return - 1 ;
}
return 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_44 ( V_2 -> V_6 . V_37 . V_41 ) ;
F_44 ( V_2 -> V_6 . V_37 . V_31 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_27 )
{
F_12 ( L_8 , V_27 ) ;
if ( V_27 == V_13 )
V_2 -> V_48 = 1 ;
if ( ! V_2 -> V_85 )
return;
if ( V_27 == V_97 ) {
F_48 ( & V_2 -> V_98 , 0 ) ;
F_49 ( & V_2 -> V_99 ) ;
}
else if ( V_27 <= V_100 )
V_2 -> V_48 = 1 ;
}
static struct V_101 * F_50 ( struct V_1 * V_2 )
{
struct V_101 * V_25 ;
F_12 ( L_9 , V_2 -> V_102 ) ;
V_25 = V_2 -> V_102 ;
if ( V_25 )
V_2 -> V_102 = V_25 -> V_103 ;
return V_25 ;
}
static void F_51 ( struct V_1 * V_2 , struct V_101 * V_4 )
{
F_12 ( L_10 , V_4 -> V_89 , V_4 ) ;
V_4 -> V_103 = V_2 -> V_102 ;
V_2 -> V_102 = V_4 ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_14 ,
struct V_44 * V_4 )
{
struct V_104 * V_105 ;
F_12 ( L_11
L_12 ,
V_4 , V_4 -> V_53 . type , V_4 -> V_53 . V_54 ,
V_4 -> V_53 . V_21 , V_14 ) ;
F_19 ( ! V_4 -> V_53 . V_54 ) ;
F_19 ( V_4 -> V_53 . type != F_21 ( V_49 ) ) ;
V_105 = V_2 -> V_50 [ V_14 ] . V_105 ;
if ( F_52 ( V_105 ) -> V_106 )
F_53 ( V_105 ) ;
switch ( F_54 ( V_4 -> V_53 . V_54 ) ) {
case V_55 :
F_55 ( V_105 ,
F_56 ( V_105 ) - F_54 ( V_4 -> V_107 ) ) ;
V_105 -> V_54 = ( V_108 << 16 ) ;
break;
case V_109 :
V_105 -> V_54 = ( V_110 << 16 ) ;
break;
case V_111 :
V_105 -> V_54 = ( V_112 << 16 ) ;
break;
case V_113 :
V_105 -> V_54 = ( V_114 << 16 ) ;
break;
case V_115 :
V_105 -> V_54 = ( V_116 << 16 ) ;
break;
case V_117 :
V_105 -> V_54 = ( V_118 << 16 ) ;
break;
case V_119 :
F_55 ( V_105 ,
F_56 ( V_105 ) - F_54 ( V_4 -> V_107 ) ) ;
V_105 -> V_54 = V_120 ;
memcpy ( V_105 -> V_121 , & V_4 -> V_122 ,
F_57 ( V_123 , V_124 ,
F_54 ( V_4 -> V_107 ) ) ) ;
break;
default:
V_105 -> V_54 = V_125 << 24 | V_118 << 16 ;
break;
}
F_12 ( L_13 , V_105 ) ;
V_105 -> V_126 ( V_105 ) ;
F_51 ( V_2 , & V_2 -> V_50 [ V_14 ] ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_127 )
{
struct V_44 * V_4 ;
T_1 V_14 ;
if ( V_2 -> V_128 ) {
V_14 = V_127 & ~ V_129 ;
V_4 = V_2 -> V_50 [ V_14 ] . V_51 ;
if ( F_20 ( V_127 & V_129 ) )
V_4 -> V_53 . V_54 = F_21 ( V_55 ) ;
} else {
V_14 = V_127 ;
V_4 = V_2 -> V_50 [ V_14 ] . V_51 ;
}
F_22 ( V_2 , V_14 , V_4 ) ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_17 T_2 * V_4 ;
struct V_130 T_2 * V_18 ;
struct V_131 * V_132 ;
V_4 = (struct V_17 T_2 * )
( ( unsigned long ) V_2 -> V_6 . V_7 . V_8 + V_14 ) ;
F_12 ( L_14
L_12 ,
V_4 , F_2 ( & V_4 -> type ) , F_2 ( & V_4 -> V_54 ) ,
F_2 ( & V_4 -> V_21 ) , V_14 ) ;
F_19 ( ! F_2 ( & V_4 -> V_54 ) ) ;
F_19 ( F_2 ( & V_4 -> type ) != V_133 ) ;
V_18 = (struct V_130 T_2 * ) V_4 ;
V_132 = (struct V_131 * ) ( unsigned long )
( F_2 ( & V_4 -> V_21 ) |
( ( T_3 ) F_2 ( & V_4 -> V_80 ) << 32 ) ) ;
if ( F_2 ( & V_4 -> V_54 ) == V_55 ) {
V_132 -> V_54 = V_134 ;
if ( V_132 -> V_135 )
F_15 ( V_132 -> V_136 ,
& V_18 -> V_137 [ ( F_2 ( & V_18 -> V_138 ) + 3 ) & ~ 3 ] ,
V_132 -> V_135 ) ;
if ( V_132 -> V_139 )
* V_132 -> V_139 = V_132 -> V_135 ;
}
else
V_132 -> V_54 = V_140 ;
V_132 -> V_141 ( V_132 ) ;
F_4 ( V_14 , & V_2 -> V_6 . V_7 . V_8 -> V_11 ) ;
}
static T_4 F_58 ( int V_142 , void * V_143 )
{
struct V_1 * V_2 = V_143 ;
int V_144 ;
unsigned long V_19 ;
F_59 ( V_2 -> V_71 -> V_72 , V_19 ) ;
V_144 = V_2 -> V_69 -> V_73 ( V_2 ) ;
F_60 ( V_2 -> V_71 -> V_72 , V_19 ) ;
return V_144 ;
}
static int F_61 ( struct V_104 * V_105 , struct V_145 * V_146 )
{
struct V_147 * V_71 = V_105 -> V_96 -> V_71 ;
struct V_1 * V_2 = (struct V_1 * ) V_71 -> V_148 ;
struct V_149 * V_150 ;
int V_151 , V_152 ;
V_152 = F_62 ( V_105 ) ;
F_19 ( V_152 < 0 ) ;
if ( ! V_152 )
return 0 ;
F_52 ( V_105 ) -> V_153 = V_152 ;
F_52 ( V_105 ) -> V_106 = 1 ;
F_19 ( F_52 ( V_105 ) -> V_153 > V_2 -> V_154 ) ;
F_63 (scp, sg, HPT_SCP(scp)->sgcnt, idx) {
V_146 [ V_151 ] . V_155 = F_64 ( F_65 ( V_150 ) ) ;
V_146 [ V_151 ] . V_77 = F_21 ( F_66 ( V_150 ) ) ;
V_146 [ V_151 ] . V_156 = ( V_151 == F_52 ( V_105 ) -> V_153 - 1 ) ?
F_21 ( 1 ) : 0 ;
}
return F_52 ( V_105 ) -> V_153 ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_101 * V_60 )
{
struct V_17 * V_62 = V_60 -> V_51 ;
V_62 -> V_21 = F_21 ( V_15 |
( T_1 ) V_60 -> V_89 ) ;
V_62 -> V_80 = 0 ;
if ( V_2 -> V_128 ) {
T_1 V_77 , V_61 ;
V_77 = F_54 ( V_62 -> V_77 ) ;
if ( V_77 < 256 )
V_61 = V_157 ;
else if ( V_77 < 512 )
V_61 = V_15 ;
else
V_61 = V_157 |
V_15 ;
F_4 ( V_60 -> V_158 | V_61 ,
& V_2 -> V_6 . V_7 . V_8 -> V_9 ) ;
} else
F_4 ( V_60 -> V_158 | V_15 ,
& V_2 -> V_6 . V_7 . V_8 -> V_9 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_101 * V_60 )
{
struct V_17 * V_62 = V_60 -> V_51 ;
T_1 V_77 , V_159 ;
V_62 -> V_21 = F_21 ( V_60 -> V_89 << 8 |
V_49 << 5 ) ;
V_62 -> V_80 = 0 ;
V_77 = F_54 ( V_62 -> V_77 ) ;
if ( V_77 <= 256 )
V_159 = 0 ;
else if ( V_77 <= 256 * 2 )
V_159 = 1 ;
else if ( V_77 <= 256 * 3 )
V_159 = 2 ;
else
V_159 = 3 ;
F_16 ( ( V_60 -> V_158 << 5 ) |
V_65 | V_159 , V_2 ) ;
}
static int F_69 ( struct V_104 * V_105 ,
void (* V_141)( struct V_104 * ) )
{
struct V_147 * V_71 = V_105 -> V_96 -> V_71 ;
struct V_1 * V_2 = (struct V_1 * ) V_71 -> V_148 ;
struct V_44 * V_4 ;
int V_160 = 0 ;
struct V_101 * V_60 ;
F_19 ( ! V_141 ) ;
V_105 -> V_126 = V_141 ;
V_60 = F_50 ( V_2 ) ;
if ( V_60 == NULL ) {
F_12 ( L_15 ) ;
return V_161 ;
}
V_60 -> V_105 = V_105 ;
F_12 ( L_16
L_17 ,
V_105 ,
V_71 -> V_88 , V_105 -> V_96 -> V_162 ,
V_105 -> V_96 -> V_163 , V_105 -> V_96 -> V_164 ,
( ( T_1 * ) V_105 -> V_165 ) [ 0 ] ,
( ( T_1 * ) V_105 -> V_165 ) [ 1 ] ,
( ( T_1 * ) V_105 -> V_165 ) [ 2 ] ,
V_60 -> V_89 , V_60 -> V_51 ) ;
V_105 -> V_54 = 0 ;
if ( V_105 -> V_96 -> V_162 || V_105 -> V_96 -> V_164 ||
V_105 -> V_96 -> V_163 > V_2 -> V_166 ) {
V_105 -> V_54 = V_110 << 16 ;
F_51 ( V_2 , V_60 ) ;
goto V_167;
}
V_4 = V_60 -> V_51 ;
V_160 = F_61 ( V_105 , V_4 -> V_122 ) ;
if ( ! V_160 )
F_52 ( V_105 ) -> V_106 = 0 ;
V_4 -> V_53 . V_19 = F_21 ( V_79 ) ;
V_4 -> V_53 . type = F_21 ( V_49 ) ;
V_4 -> V_53 . V_54 = F_21 ( V_78 ) ;
V_4 -> V_107 = F_21 ( F_56 ( V_105 ) ) ;
V_4 -> V_162 = V_105 -> V_96 -> V_162 ;
V_4 -> V_168 = V_105 -> V_96 -> V_163 ;
V_4 -> V_164 = V_105 -> V_96 -> V_164 ;
V_4 -> V_53 . V_77 = F_21 (
sizeof( struct V_44 )
- sizeof( struct V_145 )
+ V_160 * sizeof( struct V_145 ) ) ;
memcpy ( V_4 -> V_169 , V_105 -> V_165 , sizeof( V_4 -> V_169 ) ) ;
V_2 -> V_69 -> V_170 ( V_2 , V_60 ) ;
return 0 ;
V_167:
F_12 ( L_18 , V_105 ) ;
V_105 -> V_126 ( V_105 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
if ( F_71 ( & V_2 -> V_98 , 1 ) == 0 ) {
F_72 ( & V_2 -> V_171 ) ;
V_2 -> V_69 -> V_70 ( V_2 , V_97 ) ;
}
F_73 ( V_2 -> V_99 ,
F_74 ( & V_2 -> V_98 ) == 0 , 60 * V_172 ) ;
if ( F_74 ( & V_2 -> V_98 ) ) {
F_37 ( V_87 L_19 , V_2 -> V_71 -> V_88 ) ;
return - 1 ;
}
if ( F_6 ( V_2 ,
V_86 , 5000 ) ) {
F_12 ( L_5 ,
V_2 -> V_71 -> V_88 ) ;
}
return 0 ;
}
static int F_75 ( struct V_104 * V_105 )
{
struct V_147 * V_71 = V_105 -> V_96 -> V_71 ;
struct V_1 * V_2 = (struct V_1 * ) V_71 -> V_148 ;
F_37 ( V_173 L_20 ,
V_105 -> V_96 -> V_71 -> V_88 , V_105 -> V_96 -> V_162 ,
V_105 -> V_96 -> V_163 , V_105 ) ;
return F_70 ( V_2 ) ? V_174 : V_175 ;
}
static int F_76 ( struct V_176 * V_177 ,
int V_178 , int V_179 )
{
struct V_1 * V_2 = (struct V_1 * ) V_177 -> V_71 -> V_148 ;
if ( V_179 != V_180 )
return - V_181 ;
if ( V_178 > V_2 -> V_182 )
V_178 = V_2 -> V_182 ;
F_77 ( V_177 , V_183 , V_178 ) ;
return V_178 ;
}
static T_5 F_78 ( struct V_96 * V_184 ,
struct V_185 * V_186 , char * V_137 )
{
return snprintf ( V_137 , V_187 , L_21 , V_188 ) ;
}
static T_5 F_79 ( struct V_96 * V_184 ,
struct V_185 * V_186 , char * V_137 )
{
struct V_147 * V_71 = F_80 ( V_184 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_71 -> V_148 ;
return snprintf ( V_137 , V_187 , L_22 ,
V_2 -> V_189 >> 24 ,
( V_2 -> V_189 >> 16 ) & 0xff ,
( V_2 -> V_189 >> 8 ) & 0xff ,
V_2 -> V_189 & 0xff ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_37 . V_63 = F_82 ( & V_2 -> V_94 -> V_184 ,
0x800 , & V_2 -> V_6 . V_37 . V_64 , V_190 ) ;
if ( V_2 -> V_6 . V_37 . V_63 )
return 0 ;
else
return - 1 ;
}
static int F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_37 . V_63 ) {
F_84 ( & V_2 -> V_94 -> V_184 , 0x800 ,
V_2 -> V_6 . V_37 . V_63 , V_2 -> V_6 . V_37 . V_64 ) ;
return 0 ;
} else
return - 1 ;
}
static int T_6 F_85 ( struct V_93 * V_94 ,
const struct V_191 * V_163 )
{
struct V_147 * V_71 = NULL ;
struct V_1 * V_2 ;
struct V_192 * V_193 ;
struct V_74 V_194 ;
struct V_81 V_195 ;
T_7 V_196 ;
void * V_197 ;
T_1 V_198 , V_5 , V_199 ;
F_12 ( L_23 , V_94 ) ;
if ( F_86 ( V_94 ) ) {
F_37 ( V_87 L_24 ) ;
return - V_200 ;
}
F_37 ( V_201 L_25 ,
V_94 -> V_202 -> V_203 , V_94 -> V_204 >> 3 , V_94 -> V_204 & 7 ,
V_94 -> V_142 ) ;
F_87 ( V_94 ) ;
V_193 = (struct V_192 * ) V_163 -> V_205 ;
if ( F_88 ( V_94 , F_89 ( V_193 -> V_206 ) ) ) {
if ( F_88 ( V_94 , F_89 ( 32 ) ) ) {
F_37 ( V_87 L_26 ) ;
goto V_207;
}
}
if ( F_90 ( V_94 , V_208 ) ) {
F_37 ( V_87 L_27 ) ;
goto V_207;
}
V_71 = F_91 ( & V_209 , sizeof( struct V_1 ) ) ;
if ( ! V_71 ) {
F_37 ( V_87 L_28 ) ;
goto V_210;
}
V_2 = (struct V_1 * ) V_71 -> V_148 ;
V_2 -> V_69 = V_193 ;
V_2 -> V_94 = V_94 ;
V_2 -> V_71 = V_71 ;
V_2 -> V_85 = 0 ;
V_2 -> V_128 = 0 ;
F_48 ( & V_2 -> V_98 , 0 ) ;
F_48 ( & V_2 -> V_171 , 0 ) ;
F_92 ( & V_2 -> V_99 ) ;
F_92 ( & V_2 -> V_211 ) ;
V_71 -> V_212 = 1 ;
V_71 -> V_213 = 0 ;
V_71 -> V_214 = 0 ;
V_71 -> V_215 = 0 ;
V_71 -> V_142 = V_94 -> V_142 ;
if ( V_2 -> V_69 -> V_216 ( V_2 ) )
goto V_217;
if ( V_2 -> V_69 -> V_218 ( V_2 , 20000 ) ) {
F_37 ( V_87 L_29 ,
V_2 -> V_71 -> V_88 ) ;
goto V_219;
}
if ( V_2 -> V_69 -> V_220 ) {
if ( V_2 -> V_69 -> V_220 ( V_2 ) ) {
F_37 ( V_87 L_30 ,
V_2 -> V_71 -> V_88 ) ;
goto V_219;
}
}
if ( V_2 -> V_69 -> V_221 ( V_2 , & V_194 ) ) {
F_37 ( V_87 L_31 ,
V_2 -> V_71 -> V_88 ) ;
goto V_219;
}
V_2 -> V_182 = F_93 ( F_54 ( V_194 . V_182 ) ,
V_222 ) ;
V_2 -> V_166 = F_54 ( V_194 . V_166 ) ;
V_2 -> V_223 = F_54 ( V_194 . V_224 ) ;
V_2 -> V_154 = F_54 ( V_194 . V_225 ) ;
V_2 -> V_189 = F_54 ( V_194 . V_189 ) ;
V_2 -> V_226 = F_54 ( V_194 . V_226 ) ;
V_2 -> V_227 = F_54 ( V_194 . V_227 ) ;
if ( V_2 -> V_189 > 0x01020000 ||
V_2 -> V_226 > 0x01020000 )
V_2 -> V_128 = 1 ;
V_71 -> V_228 = F_54 ( V_194 . V_229 ) >> 9 ;
V_71 -> V_230 = F_54 ( V_194 . V_166 ) ;
V_71 -> V_231 = F_54 ( V_194 . V_225 ) ;
V_71 -> V_232 = F_54 ( V_194 . V_182 ) ;
V_71 -> V_233 = F_54 ( V_194 . V_182 ) ;
V_71 -> V_234 = 16 ;
V_199 = sizeof( struct V_44 )
+ sizeof( struct V_145 ) * ( V_2 -> V_154 - 1 ) ;
if ( ( V_199 & 0x1f ) != 0 )
V_199 = ( V_199 + 0x1f ) & ~ 0x1f ;
memset ( & V_195 , 0 , sizeof( struct V_81 ) ) ;
V_195 . V_235 = F_21 ( V_71 -> V_88 ) ;
V_195 . V_236 = F_94 ( V_71 -> V_88 ) ;
V_195 . V_237 = F_94 ( V_199 ) ;
if ( V_2 -> V_69 -> V_195 ( V_2 , & V_195 ) ) {
F_37 ( V_87 L_32 ,
V_2 -> V_71 -> V_88 ) ;
goto V_219;
}
F_95 ( V_94 , V_71 ) ;
if ( F_96 ( V_94 -> V_142 , F_58 , V_238 ,
V_208 , V_2 ) ) {
F_37 ( V_87 L_33 ,
V_2 -> V_71 -> V_88 , V_94 -> V_142 ) ;
goto V_219;
}
F_12 ( L_34 , V_199 , V_2 -> V_182 ) ;
V_2 -> V_199 = V_199 ;
V_197 = F_82 ( & V_94 -> V_184 ,
V_2 -> V_199 * V_2 -> V_182 + 0x20 ,
& V_196 , V_190 ) ;
if ( ! V_197 ) {
F_37 ( V_87 L_35 ,
V_2 -> V_71 -> V_88 ) ;
goto V_239;
}
V_2 -> V_240 = V_197 ;
V_2 -> V_241 = V_196 ;
if ( ( V_196 & 0x1f ) != 0 )
{
V_198 = ( ( V_196 + 0x1f ) & ~ 0x1f ) - V_196 ;
V_196 += V_198 ;
V_197 += V_198 ;
}
V_2 -> V_102 = V_197 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_182 ; V_5 ++ ) {
V_2 -> V_50 [ V_5 ] . V_103 = NULL ;
V_2 -> V_50 [ V_5 ] . V_51 = V_197 ;
V_2 -> V_50 [ V_5 ] . V_158 = V_196 >> 5 ;
V_2 -> V_50 [ V_5 ] . V_89 = V_5 ;
F_51 ( V_2 , & V_2 -> V_50 [ V_5 ] ) ;
V_197 = ( char * ) V_197 + V_2 -> V_199 ;
V_196 = V_196 + V_2 -> V_199 ;
}
if ( F_36 ( V_2 ) )
goto V_242;
if ( F_97 ( V_71 , & V_94 -> V_184 ) ) {
F_37 ( V_87 L_36 ,
V_2 -> V_71 -> V_88 ) ;
goto V_242;
}
F_98 ( V_71 ) ;
F_12 ( L_37 , V_2 -> V_71 -> V_88 ) ;
return 0 ;
V_242:
F_84 ( & V_2 -> V_94 -> V_184 ,
V_2 -> V_199 * V_2 -> V_182 + 0x20 ,
V_2 -> V_240 , V_2 -> V_241 ) ;
V_239:
F_99 ( V_2 -> V_94 -> V_142 , V_2 ) ;
V_219:
if ( V_2 -> V_69 -> V_243 )
V_2 -> V_69 -> V_243 ( V_2 ) ;
V_2 -> V_69 -> V_219 ( V_2 ) ;
V_217:
F_100 ( V_71 ) ;
V_210:
F_101 ( V_94 ) ;
V_207:
F_102 ( V_94 ) ;
F_12 ( L_38 , V_71 ? V_71 -> V_88 : 0 ) ;
return - V_200 ;
}
static void F_103 ( struct V_93 * V_94 )
{
struct V_147 * V_71 = F_104 ( V_94 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_71 -> V_148 ;
F_12 ( L_39 , V_2 ) ;
if ( F_6 ( V_2 , V_244 , 60000 ) )
F_37 ( V_87 L_40 ,
V_2 -> V_71 -> V_88 ) ;
V_2 -> V_69 -> V_245 ( V_2 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
T_1 V_246 ;
V_246 = F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_83 ) ;
F_4 ( V_246 |
V_26 | V_29 ,
& V_2 -> V_6 . V_7 . V_8 -> V_83 ) ;
F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_83 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
F_4 ( 0 , & V_2 -> V_6 . V_37 . V_41 -> V_83 ) ;
F_2 ( & V_2 -> V_6 . V_37 . V_41 -> V_83 ) ;
}
static void F_107 ( struct V_93 * V_94 )
{
struct V_147 * V_71 = F_104 ( V_94 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_71 -> V_148 ;
F_12 ( L_41 , V_2 -> V_71 -> V_88 ) ;
F_108 ( V_71 ) ;
F_103 ( V_94 ) ;
F_99 ( V_2 -> V_94 -> V_142 , V_2 ) ;
F_84 ( & V_2 -> V_94 -> V_184 ,
V_2 -> V_199 * V_2 -> V_182 + 0x20 ,
V_2 -> V_240 ,
V_2 -> V_241 ) ;
if ( V_2 -> V_69 -> V_243 )
V_2 -> V_69 -> V_243 ( V_2 ) ;
V_2 -> V_69 -> V_219 ( V_2 ) ;
F_101 ( V_2 -> V_94 ) ;
F_95 ( V_2 -> V_94 , NULL ) ;
F_102 ( V_2 -> V_94 ) ;
F_100 ( V_71 ) ;
}
static int T_8 F_109 ( void )
{
F_37 ( V_201 L_42 , V_247 , V_188 ) ;
return F_110 ( & V_248 ) ;
}
static void T_9 F_111 ( void )
{
F_112 ( & V_248 ) ;
}
