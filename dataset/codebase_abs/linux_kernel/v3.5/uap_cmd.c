int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ) {
int V_7 ;
if ( ! V_6 -> V_8 ) {
V_4 -> V_9 = V_10 ;
V_4 -> V_11 = V_12 ;
V_4 -> V_13 . V_14 = 0 ;
V_2 -> V_15 . V_16 = 0 ;
V_2 -> V_15 . V_17 = 0 ;
V_2 -> V_15 . V_18 = 0 ;
return 0 ;
}
switch ( V_6 -> V_19 ) {
case V_20 :
V_4 -> V_21 = V_22 ;
break;
case V_23 :
V_4 -> V_21 = V_24 ;
break;
case V_25 :
V_4 -> V_21 = V_26 ;
break;
default:
V_4 -> V_21 = V_27 ;
break;
}
V_4 -> V_28 |= V_29 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_30 . V_31 ; V_7 ++ ) {
switch ( V_6 -> V_30 . V_32 [ V_7 ] ) {
case V_33 :
if ( V_6 -> V_30 . V_34 &
V_35 ) {
V_4 -> V_9 = V_36 ;
V_4 -> V_11 = V_37 ;
}
if ( V_6 -> V_30 . V_34 &
V_38 ) {
V_4 -> V_9 = V_39 ;
V_4 -> V_11 = V_37 ;
}
break;
case V_40 :
if ( V_6 -> V_30 . V_34 &
V_35 ) {
V_4 -> V_9 = V_36 ;
V_4 -> V_11 = V_41 ;
}
if ( V_6 -> V_30 . V_34 &
V_38 ) {
V_4 -> V_9 = V_39 ;
V_4 -> V_11 = V_41 ;
}
break;
default:
break;
}
}
for ( V_7 = 0 ; V_7 < V_6 -> V_30 . V_42 ; V_7 ++ ) {
switch ( V_6 -> V_30 . V_43 [ V_7 ] ) {
case V_44 :
case V_45 :
break;
case V_46 :
V_4 -> V_13 . V_47 = V_48 ;
break;
case V_49 :
V_4 -> V_13 . V_50 =
V_51 ;
default:
break;
}
}
switch ( V_6 -> V_30 . V_52 ) {
case V_44 :
case V_45 :
break;
case V_46 :
V_4 -> V_13 . V_53 = V_48 ;
break;
case V_49 :
V_4 -> V_13 . V_53 = V_51 ;
break;
default:
break;
}
return 0 ;
}
void F_2 ( struct V_3 * V_54 )
{
V_54 -> V_55 = 0x7F ;
V_54 -> V_56 = 0x7F ;
V_54 -> V_57 = 0x7F ;
V_54 -> V_58 = 0x7FFF ;
V_54 -> V_21 = 0x7F ;
V_54 -> V_59 = 0x7FFF ;
V_54 -> V_60 = 0x7FFF ;
V_54 -> V_61 = 0x7F ;
}
static int
F_3 ( T_1 * V_62 , void * V_63 , T_2 * V_64 )
{
struct V_65 * V_57 ;
struct V_66 * V_58 ;
struct V_67 * V_68 ;
struct V_69 * V_70 ;
struct V_71 * V_72 ;
struct V_73 * V_60 ;
struct V_74 * V_59 ;
struct V_75 * V_61 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_82 * V_19 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_3 * V_87 = V_63 ;
T_2 V_88 = * V_64 ;
if ( V_87 -> V_68 . V_89 ) {
V_68 = (struct V_67 * ) V_62 ;
V_68 -> V_62 . type = F_4 ( V_90 ) ;
V_68 -> V_62 . V_91 = F_4 ( ( T_2 ) V_87 -> V_68 . V_89 ) ;
memcpy ( V_68 -> V_68 , V_87 -> V_68 . V_68 , V_87 -> V_68 . V_89 ) ;
V_88 += sizeof( struct V_92 ) +
V_87 -> V_68 . V_89 ;
V_62 += sizeof( struct V_92 ) + V_87 -> V_68 . V_89 ;
V_70 = (struct V_69 * ) V_62 ;
V_70 -> V_62 . type = F_4 ( V_93 ) ;
V_70 -> V_62 . V_91 =
F_4 ( sizeof( V_70 -> V_94 ) ) ;
V_70 -> V_94 = V_87 -> V_55 ;
V_88 += sizeof( struct V_69 ) ;
V_62 += sizeof( struct V_69 ) ;
}
if ( V_87 -> V_95 && V_87 -> V_95 <= V_96 ) {
V_72 = (struct V_71 * ) V_62 ;
V_72 -> V_62 . type = F_4 ( V_97 ) ;
V_72 -> V_62 . V_91 =
F_4 ( sizeof( struct V_71 ) -
sizeof( struct V_92 ) ) ;
V_72 -> V_98 = V_87 -> V_99 ;
V_72 -> V_95 = V_87 -> V_95 ;
V_88 += sizeof( struct V_71 ) ;
V_62 += sizeof( struct V_71 ) ;
}
if ( V_87 -> V_58 >= V_100 &&
V_87 -> V_58 <= V_101 ) {
V_58 = (struct V_66 * ) V_62 ;
V_58 -> V_62 . type =
F_4 ( V_102 ) ;
V_58 -> V_62 . V_91 =
F_4 ( sizeof( struct V_66 ) -
sizeof( struct V_92 ) ) ;
V_58 -> V_103 = F_4 ( V_87 -> V_58 ) ;
V_88 += sizeof( struct V_66 ) ;
V_62 += sizeof( struct V_66 ) ;
}
if ( V_87 -> V_57 >= V_104 &&
V_87 -> V_57 <= V_105 ) {
V_57 = (struct V_65 * ) V_62 ;
V_57 -> V_62 . type = F_4 ( V_106 ) ;
V_57 -> V_62 . V_91 =
F_4 ( sizeof( struct V_65 ) -
sizeof( struct V_92 ) ) ;
V_57 -> V_103 = V_87 -> V_57 ;
V_88 += sizeof( struct V_65 ) ;
V_62 += sizeof( struct V_65 ) ;
}
if ( V_87 -> V_59 <= V_107 ) {
V_59 = (struct V_74 * ) V_62 ;
V_59 -> V_62 . type =
F_4 ( V_108 ) ;
V_59 -> V_62 . V_91 =
F_4 ( sizeof( struct V_74 ) -
sizeof( struct V_92 ) ) ;
V_59 -> V_109 = F_4 ( V_87 -> V_59 ) ;
V_88 += sizeof( struct V_73 ) ;
V_62 += sizeof( struct V_73 ) ;
}
if ( ( V_87 -> V_60 >= V_110 ) &&
( V_87 -> V_60 <= V_111 ) ) {
V_60 = (struct V_73 * ) V_62 ;
V_60 -> V_62 . type =
F_4 ( V_112 ) ;
V_60 -> V_62 . V_91 =
F_4 ( sizeof( struct V_73 ) -
sizeof( struct V_92 ) ) ;
V_60 -> V_113 = F_4 ( V_87 -> V_60 ) ;
V_88 += sizeof( struct V_73 ) ;
V_62 += sizeof( struct V_73 ) ;
}
if ( V_87 -> V_61 <= V_114 ) {
V_61 = (struct V_75 * ) V_62 ;
V_61 -> V_62 . type = F_4 ( V_115 ) ;
V_61 -> V_62 . V_91 =
F_4 ( sizeof( struct V_75 ) -
sizeof( struct V_92 ) ) ;
V_61 -> V_116 = ( T_1 ) V_87 -> V_61 ;
V_88 += sizeof( struct V_75 ) ;
V_62 += sizeof( struct V_75 ) ;
}
if ( ( V_87 -> V_9 & V_36 ) ||
( V_87 -> V_9 & V_39 ) ||
( V_87 -> V_9 & V_117 ) ) {
V_86 = (struct V_85 * ) V_62 ;
V_86 -> V_62 . type = F_4 ( V_118 ) ;
V_86 -> V_62 . V_91 =
F_4 ( sizeof( struct V_85 ) -
sizeof( struct V_92 ) ) ;
V_86 -> V_28 =
F_4 ( V_87 -> V_28 ) ;
V_86 -> V_11 = F_4 ( V_87 -> V_11 ) ;
V_88 += sizeof( struct V_85 ) ;
V_62 += sizeof( struct V_85 ) ;
if ( V_87 -> V_13 . V_47 &
V_119 ) {
V_77 = (struct V_76 * ) V_62 ;
V_77 -> V_62 . type =
F_4 ( V_120 ) ;
V_77 -> V_62 . V_91 = F_4 (
sizeof( struct V_76 ) -
sizeof( struct V_92 ) ) ;
V_77 -> V_121 = F_4 ( V_36 ) ;
V_77 -> V_122 =
V_87 -> V_13 . V_47 ;
V_88 += sizeof( struct V_76 ) ;
V_62 += sizeof( struct V_76 ) ;
}
if ( V_87 -> V_13 . V_50 &
V_119 ) {
V_77 = (struct V_76 * ) V_62 ;
V_77 -> V_62 . type = F_4 ( V_120 ) ;
V_77 -> V_62 . V_91 = F_4 (
sizeof( struct V_76 ) -
sizeof( struct V_92 ) ) ;
V_77 -> V_121 = F_4 ( V_39 ) ;
V_77 -> V_122 =
V_87 -> V_13 . V_50 ;
V_88 += sizeof( struct V_76 ) ;
V_62 += sizeof( struct V_76 ) ;
}
if ( V_87 -> V_13 . V_53 & V_119 ) {
V_79 = (struct V_78 * ) V_62 ;
V_79 -> V_62 . type = F_4 ( V_123 ) ;
V_79 -> V_62 . V_91 = F_4 (
sizeof( struct V_78 ) -
sizeof( struct V_92 ) ) ;
V_79 -> V_122 = V_87 -> V_13 . V_53 ;
V_88 += sizeof( struct V_78 ) ;
V_62 += sizeof( struct V_78 ) ;
}
if ( V_87 -> V_13 . V_14 ) {
V_84 = (struct V_83 * ) V_62 ;
V_84 -> V_62 . type =
F_4 ( V_124 ) ;
V_84 -> V_62 . V_91 =
F_4 ( V_87 -> V_13 . V_14 ) ;
memcpy ( V_84 -> V_84 ,
V_87 -> V_13 . V_84 ,
V_87 -> V_13 . V_14 ) ;
V_88 += sizeof( struct V_92 ) +
V_87 -> V_13 . V_14 ;
V_62 += sizeof( struct V_92 ) +
V_87 -> V_13 . V_14 ;
}
}
if ( ( V_87 -> V_21 <= V_24 ) ||
( V_87 -> V_21 == V_27 ) ) {
V_19 = (struct V_82 * ) V_62 ;
V_19 -> V_62 . type = F_4 ( V_125 ) ;
V_19 -> V_62 . V_91 =
F_4 ( sizeof( struct V_82 ) -
sizeof( struct V_92 ) ) ;
V_19 -> V_19 = ( T_1 ) V_87 -> V_21 ;
V_88 += sizeof( struct V_82 ) ;
V_62 += sizeof( struct V_82 ) ;
}
if ( V_87 -> V_9 ) {
V_81 = (struct V_80 * ) V_62 ;
V_81 -> V_62 . type =
F_4 ( V_126 ) ;
V_81 -> V_62 . V_91 =
F_4 ( sizeof( struct V_80 )
- sizeof( struct V_92 ) ) ;
V_81 -> V_121 = F_4 ( V_87 -> V_9 ) ;
V_88 += sizeof( struct V_80 ) ;
V_62 += sizeof( struct V_80 ) ;
}
* V_64 = V_88 ;
return 0 ;
}
static int F_5 ( T_1 * V_62 , void * V_63 , T_2 * V_127 )
{
struct V_128 * V_129 = V_63 ;
struct V_92 * V_130 = (struct V_92 * ) V_62 ;
if ( ! V_129 || ! V_129 -> V_91 || ! V_129 -> V_131 )
return - 1 ;
* V_127 += F_6 ( V_129 -> V_91 ) + sizeof( struct V_92 ) ;
V_130 -> type = F_4 ( V_132 ) ;
V_130 -> V_91 = V_129 -> V_91 ;
V_62 += sizeof( struct V_92 ) ;
memcpy ( V_62 , V_129 -> V_131 , F_6 ( V_129 -> V_91 ) ) ;
return 0 ;
}
static int
F_7 ( struct V_133 * V_134 , T_2 V_135 ,
T_3 type , void * V_63 )
{
T_1 * V_62 ;
T_2 V_88 , V_64 , V_127 ;
struct V_136 * V_137 ;
V_134 -> V_138 = F_4 ( V_139 ) ;
V_88 = ( T_2 ) ( sizeof( struct V_136 ) + V_140 ) ;
V_137 = (struct V_136 * ) & V_134 -> V_6 . V_141 ;
V_137 -> V_142 = F_4 ( V_135 ) ;
V_62 = V_137 -> V_62 ;
switch ( type ) {
case V_143 :
V_64 = V_88 ;
if ( F_3 ( V_62 , V_63 , & V_64 ) )
return - 1 ;
V_134 -> V_144 = F_4 ( V_64 ) ;
break;
case V_145 :
V_127 = V_88 ;
if ( F_5 ( V_62 , V_63 , & V_127 ) )
return - 1 ;
V_134 -> V_144 = F_4 ( V_127 ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
int F_8 ( struct V_1 * V_2 , T_2 V_146 ,
T_2 V_135 , T_3 type ,
void * V_147 , void * V_63 )
{
struct V_133 * V_134 = V_63 ;
switch ( V_146 ) {
case V_139 :
if ( F_7 ( V_134 , V_135 , type , V_147 ) )
return - 1 ;
break;
case V_148 :
case V_149 :
V_134 -> V_138 = F_4 ( V_146 ) ;
V_134 -> V_144 = F_4 ( V_140 ) ;
break;
default:
F_9 ( V_2 -> V_150 -> V_151 ,
L_1 , V_146 ) ;
return - 1 ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 , int V_95 )
{
struct V_3 * V_87 ;
struct V_152 * V_152 = V_2 -> V_153 -> V_152 ;
V_87 = F_11 ( sizeof( struct V_3 ) , V_154 ) ;
if ( ! V_87 )
return - V_155 ;
F_2 ( V_87 ) ;
V_87 -> V_99 = V_156 ;
V_87 -> V_95 = V_95 ;
if ( F_12 ( V_2 , V_139 ,
V_157 ,
V_143 , V_87 ) ) {
F_13 ( V_152 , L_2 ) ;
F_14 ( V_87 ) ;
return - 1 ;
}
F_14 ( V_87 ) ;
return 0 ;
}
