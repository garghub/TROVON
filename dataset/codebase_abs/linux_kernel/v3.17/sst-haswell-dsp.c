static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 V_12 ;
struct V_13 V_14 ;
int V_15 ;
void T_1 * V_16 ;
if ( V_6 -> type != V_17
&& V_6 -> type != V_18
&& V_6 -> type != V_19
&& V_6 -> type != V_20
&& V_6 -> type != V_21
&& V_6 -> type != V_22 )
return 0 ;
F_2 ( V_2 -> V_23 , L_1 ,
V_6 -> V_24 , V_6 -> V_25 ,
V_6 -> V_26 , V_6 -> type ) ;
F_2 ( V_2 -> V_23 , L_2 , V_6 -> V_27 ) ;
F_2 ( V_2 -> V_23 , L_3 ,
V_6 -> V_28 . V_29 , V_6 -> V_28 . V_30 ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_31 = V_6 -> type ;
V_14 . V_32 = V_6 -> V_27 ;
V_14 . V_33 . V_34 = V_6 -> V_28 . V_29 ;
V_14 . V_33 . type = V_35 ;
V_14 . V_33 . V_36 = V_37 ;
V_14 . V_38 . V_34 = V_6 -> V_28 . V_30 ;
V_14 . V_38 . type = V_35 ;
V_14 . V_38 . V_36 = V_39 ;
V_10 = F_3 ( V_4 , & V_14 , NULL ) ;
if ( V_10 == NULL )
return - V_40 ;
V_8 = ( void * ) V_6 + sizeof( * V_6 ) ;
for ( V_15 = 0 ; V_15 < V_6 -> V_26 ; V_15 ++ ) {
if ( V_8 -> V_34 <= 0 ) {
F_4 ( V_2 -> V_23 ,
L_4 , V_15 ) ;
F_5 ( V_10 ) ;
return - V_41 ;
}
switch ( V_8 -> type ) {
case V_42 :
V_16 = V_2 -> V_43 . V_44 ;
V_12 . V_45 =
V_8 -> V_46 + V_2 -> V_43 . V_47 ;
V_12 . type = V_48 ;
break;
case V_49 :
V_16 = V_2 -> V_43 . V_44 ;
V_12 . V_45 = V_8 -> V_46 ;
V_12 . type = V_35 ;
break;
default:
F_4 ( V_2 -> V_23 , L_5 ,
V_8 -> type , V_15 ) ;
F_5 ( V_10 ) ;
return - V_41 ;
}
V_12 . V_34 = V_8 -> V_34 ;
V_12 . V_36 = V_50 ;
V_12 . V_51 = ( void * ) V_8 + sizeof( * V_8 ) ;
V_12 . V_52 = V_12 . V_51 - V_4 -> V_53 ;
F_2 ( V_2 -> V_23 , L_6
L_7 ,
V_15 , V_8 -> type , V_8 -> V_34 , V_16 ,
V_8 -> V_46 ) ;
F_6 ( V_10 , & V_12 ) ;
V_8 = ( void * ) V_8 + sizeof( * V_8 ) + V_8 -> V_34 ;
}
return 0 ;
}
static int F_7 ( struct V_3 * V_3 )
{
struct V_54 * V_55 ;
struct V_9 * V_56 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = V_3 -> V_2 ;
struct V_57 * V_58 = V_3 -> V_59 ;
int V_60 , V_15 ;
V_55 = (struct V_54 * ) V_3 -> V_53 ;
if ( ( strncmp ( V_55 -> V_24 , V_61 , 4 ) != 0 ) ||
( V_3 -> V_34 != V_55 -> V_62 + sizeof( * V_55 ) ) ) {
F_4 ( V_2 -> V_23 , L_8 ) ;
return - V_41 ;
}
F_2 ( V_2 -> V_23 , L_9 ,
V_55 -> V_62 , V_55 -> V_63 ,
V_55 -> V_64 , sizeof( * V_55 ) ) ;
V_6 = ( void * ) V_3 -> V_53 + sizeof( * V_55 ) ;
for ( V_15 = 0 ; V_15 < V_55 -> V_63 ; V_15 ++ ) {
V_60 = F_1 ( V_2 , V_3 , V_6 ) ;
if ( V_60 < 0 ) {
F_4 ( V_2 -> V_23 , L_10 , V_15 ) ;
return V_60 ;
}
V_6 = ( void * ) V_6 + sizeof( * V_6 ) + V_6 -> V_25 ;
}
V_56 = F_8 ( V_2 ) ;
if ( V_56 == NULL )
return - V_40 ;
F_9 ( V_58 , V_56 ) ;
return 0 ;
}
static T_2 F_10 ( int V_65 , void * V_66 )
{
struct V_1 * V_67 = (struct V_1 * ) V_66 ;
T_3 V_68 ;
int V_60 = V_69 ;
F_11 ( & V_67 -> V_70 ) ;
V_68 = F_12 ( V_67 , V_71 ) ;
if ( V_68 & V_72 ) {
F_13 ( V_68 ,
F_12 ( V_67 , V_73 ) ) ;
F_14 ( V_67 , V_73 ,
V_74 , V_74 ) ;
V_60 = V_75 ;
}
if ( V_68 & V_76 ) {
F_15 ( V_68 ,
F_12 ( V_67 , V_73 ) ) ;
F_14 ( V_67 , V_73 ,
V_77 , V_77 ) ;
V_60 = V_75 ;
}
F_16 ( & V_67 -> V_70 ) ;
return V_60 ;
}
static void F_17 ( struct V_1 * V_67 )
{
F_14 ( V_67 , V_78 ,
V_79 | V_80 | V_81 , 0x0 ) ;
F_14 ( V_67 ,
V_78 , V_82 | V_83 ,
V_82 | F_18 ( 4 ) ) ;
F_14 ( V_67 , V_84 ,
V_85 | V_86 | V_87 ,
V_85 | V_86 | V_87 ) ;
F_14 ( V_67 , V_88 , V_89 ,
V_89 ) ;
F_14 ( V_67 , V_90 ,
F_19 ( 0xff ) | F_20 ( 0xff ) ,
F_19 ( 0xff ) | F_20 ( 0xff ) ) ;
F_21 ( 0x0 , V_67 -> V_43 . V_91 + V_92 ) ;
F_14 ( V_67 , V_78 , V_82 , 0x0 ) ;
}
static void F_22 ( struct V_1 * V_67 )
{
F_14 ( V_67 , V_78 ,
V_93 | V_82 , V_93 | V_82 ) ;
F_23 ( 10 ) ;
F_14 ( V_67 , V_78 ,
V_93 | V_82 , V_82 ) ;
}
static int F_24 ( struct V_1 * V_67 , struct V_94 * V_95 )
{
V_67 -> V_43 . V_96 = V_95 -> V_96 ;
V_67 -> V_43 . V_44 = F_25 ( V_95 -> V_96 , V_95 -> V_97 ) ;
if ( ! V_67 -> V_43 . V_44 )
return - V_98 ;
V_67 -> V_43 . V_91 = F_25 ( V_95 -> V_99 , V_95 -> V_100 ) ;
if ( ! V_67 -> V_43 . V_91 ) {
F_26 ( V_67 -> V_43 . V_44 ) ;
return - V_98 ;
}
V_67 -> V_43 . V_101 = V_67 -> V_43 . V_44 + V_67 -> V_43 . V_102 ;
return 0 ;
}
static T_3 F_27 ( struct V_103 * V_8 )
{
T_3 V_104 = 0 , V_105 = 0 , V_106 ;
struct V_1 * V_67 = V_8 -> V_2 ;
for ( V_106 = 0 ; V_106 < F_28 ( V_107 ) ; V_106 ++ ) {
if ( V_107 [ V_106 ] . V_108 == V_67 -> V_31 )
break;
}
if ( V_106 < F_28 ( V_107 ) ) {
switch ( V_8 -> type ) {
case V_35 :
V_105 = V_107 [ V_106 ] . V_109 ;
break;
case V_48 :
V_105 = V_107 [ V_106 ] . V_110 ;
break;
default:
V_105 = 0 ;
}
} else
V_105 = 0 ;
V_104 = 1 << ( V_8 -> V_106 + V_105 ) ;
return V_104 ;
}
static void F_29 ( struct V_103 * V_8 )
{
T_3 V_34 ;
T_4 V_111 [ 4 ] ;
struct V_1 * V_67 = V_8 -> V_2 ;
V_34 = V_8 -> V_34 > 4 ? 4 : V_8 -> V_34 ;
F_30 ( V_111 , V_67 -> V_43 . V_44 + V_8 -> V_45 , V_34 ) ;
}
static int F_31 ( struct V_103 * V_8 )
{
struct V_1 * V_67 = V_8 -> V_2 ;
T_3 V_104 , V_112 ;
if ( V_8 -> V_113 ++ > 0 )
return 0 ;
F_2 ( V_8 -> V_2 -> V_23 , L_11 ,
V_8 -> type , V_8 -> V_106 , V_8 -> V_45 ) ;
V_112 = F_32 ( V_67 -> V_43 . V_91 + V_114 ) ;
V_104 = F_27 ( V_8 ) ;
F_21 ( V_112 & ~ V_104 , V_67 -> V_43 . V_91 + V_114 ) ;
F_33 ( 10 ) ;
F_29 ( V_8 ) ;
return 0 ;
}
static int F_34 ( struct V_103 * V_8 )
{
struct V_1 * V_67 = V_8 -> V_2 ;
T_3 V_104 , V_112 ;
if ( -- V_8 -> V_113 > 0 )
return 0 ;
F_2 ( V_8 -> V_2 -> V_23 , L_12 ,
V_8 -> type , V_8 -> V_106 , V_8 -> V_45 ) ;
V_112 = F_32 ( V_67 -> V_43 . V_91 + V_114 ) ;
V_104 = F_27 ( V_8 ) ;
F_21 ( V_112 | V_104 , V_67 -> V_43 . V_91 + V_114 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_67 )
{
int V_115 = 10 ;
T_3 V_116 ;
V_116 = F_32 ( V_67 -> V_43 . V_91 + V_117 ) ;
F_21 ( V_116 & ~ 0x3 , V_67 -> V_43 . V_91 + V_117 ) ;
while ( V_115 -- ) {
V_116 = F_12 ( V_67 , V_78 ) ;
if ( V_116 != 0xffffffff )
return 0 ;
F_36 ( 1 ) ;
}
return - V_98 ;
}
static int F_37 ( struct V_1 * V_67 , struct V_94 * V_95 )
{
const struct V_118 * V_119 ;
struct V_120 * V_23 ;
int V_60 = - V_98 , V_121 , V_122 , V_123 ;
T_3 V_45 , V_34 ;
V_23 = V_67 -> V_124 ;
switch ( V_67 -> V_31 ) {
case V_125 :
V_119 = V_126 ;
V_123 = F_28 ( V_126 ) ;
V_67 -> V_43 . V_47 = V_127 ;
V_67 -> V_43 . V_102 = V_128 ;
break;
case V_129 :
V_119 = V_130 ;
V_123 = F_28 ( V_130 ) ;
V_67 -> V_43 . V_47 = V_131 ;
V_67 -> V_43 . V_102 = V_132 ;
break;
default:
F_4 ( V_23 , L_13 ) ;
return V_60 ;
}
V_60 = F_24 ( V_67 , V_95 ) ;
if ( V_60 < 0 ) {
F_4 ( V_23 , L_14 ) ;
return V_60 ;
}
V_60 = F_35 ( V_67 ) ;
if ( V_60 < 0 ) {
F_4 ( V_23 , L_15 ) ;
return V_60 ;
}
V_60 = F_38 ( V_23 , F_39 ( 31 ) ) ;
if ( V_60 )
return V_60 ;
F_14 ( V_67 , V_73 , 0x3 , 0x0 ) ;
F_14 ( V_67 , V_133 ,
( 0x3 | 0x1 << 16 | 0x3 << 21 ) , 0x0 ) ;
for ( V_121 = 0 ; V_121 < V_123 ; V_121 ++ ) {
V_45 = V_119 [ V_121 ] . V_134 ;
V_34 = ( V_119 [ V_121 ] . V_135 - V_119 [ V_121 ] . V_134 ) / V_119 [ V_121 ] . V_26 ;
for ( V_122 = 0 ; V_122 < V_119 [ V_121 ] . V_26 ; V_122 ++ ) {
F_40 ( V_67 , V_45 , V_34 ,
V_119 [ V_121 ] . type , & V_136 , V_122 , V_67 ) ;
V_45 += V_34 ;
}
}
F_21 ( 0xffffffff , V_67 -> V_43 . V_91 + V_114 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_67 )
{
F_42 ( V_67 ) ;
F_26 ( V_67 -> V_43 . V_44 ) ;
F_26 ( V_67 -> V_43 . V_91 ) ;
}
