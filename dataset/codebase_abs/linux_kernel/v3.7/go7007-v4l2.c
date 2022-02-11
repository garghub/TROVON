static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 != V_5 ) {
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_4 = V_5 ;
}
if ( V_2 -> V_7 > 0 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; ++ V_3 )
F_3 ( V_2 -> V_8 [ V_3 ] ) ;
V_2 -> V_7 = 0 ;
}
}
static void F_4 ( struct V_9 * V_10 )
{
struct V_1 * V_2 , * V_11 ;
F_5 (gobuf, next, &go->stream, stream) {
F_1 ( V_2 ) ;
}
}
static int F_6 ( struct V_9 * V_10 )
{
unsigned long V_12 ;
F_7 ( & V_10 -> V_13 ) ;
if ( V_10 -> V_14 ) {
V_10 -> V_14 = 0 ;
F_8 ( V_10 ) ;
F_9 ( & V_10 -> V_15 , V_12 ) ;
F_4 ( V_10 ) ;
F_10 ( & V_10 -> V_15 , V_12 ) ;
F_11 ( V_10 ) ;
}
F_12 ( & V_10 -> V_13 ) ;
return 0 ;
}
static int F_13 ( struct V_16 * V_16 )
{
struct V_9 * V_10 = F_14 ( F_15 ( V_16 ) ) ;
struct V_17 * V_18 ;
if ( V_10 -> V_19 != V_20 )
return - V_21 ;
V_18 = F_16 ( sizeof( struct V_17 ) , V_22 ) ;
if ( V_18 == NULL )
return - V_23 ;
++ V_10 -> V_24 ;
V_18 -> V_10 = V_10 ;
F_17 ( & V_18 -> V_25 ) ;
V_18 -> V_26 = 0 ;
V_16 -> V_27 = V_18 ;
return 0 ;
}
static int F_18 ( struct V_16 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_27 ;
struct V_9 * V_10 = V_18 -> V_10 ;
if ( V_18 -> V_26 > 0 ) {
F_6 ( V_10 ) ;
V_10 -> V_28 = 0 ;
F_19 ( V_18 -> V_29 ) ;
V_18 -> V_26 = 0 ;
}
F_19 ( V_18 ) ;
if ( -- V_10 -> V_24 == 0 )
F_19 ( V_10 ) ;
V_16 -> V_27 = NULL ;
return 0 ;
}
static T_1 F_20 ( struct V_1 * V_2 , int V_30 )
{
T_2 * V_31 = F_21 ( V_2 -> V_8 [ 0 ] ) ;
switch ( V_30 ) {
case V_32 :
return V_33 ;
case V_34 :
switch ( ( V_31 [ V_2 -> V_35 + 4 ] >> 6 ) & 0x3 ) {
case 0 :
return V_33 ;
case 1 :
return V_36 ;
case 2 :
return V_37 ;
default:
return 0 ;
}
case V_38 :
case V_39 :
switch ( ( V_31 [ V_2 -> V_35 + 5 ] >> 3 ) & 0x7 ) {
case 1 :
return V_33 ;
case 2 :
return V_36 ;
case 3 :
return V_37 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_22 ( struct V_9 * V_10 , struct V_40 * V_41 , int V_42 )
{
int V_43 = 0 , V_44 = 0 ;
int V_45 , V_46 , V_3 ;
if ( V_41 != NULL && V_41 -> V_41 . V_47 . V_48 != V_49 &&
V_41 -> V_41 . V_47 . V_48 != V_50 &&
V_41 -> V_41 . V_47 . V_48 != V_51 )
return - V_52 ;
switch ( V_10 -> V_53 ) {
case V_54 :
V_44 = 720 ;
V_43 = 480 ;
break;
case V_55 :
V_44 = 720 ;
V_43 = 576 ;
break;
case V_56 :
V_44 = V_10 -> V_57 -> V_44 ;
V_43 = V_10 -> V_57 -> V_43 ;
break;
}
if ( V_41 == NULL ) {
V_45 = V_44 ;
V_46 = V_43 ;
} else if ( V_10 -> V_57 -> V_58 & V_59 ) {
if ( V_41 -> V_41 . V_47 . V_45 > V_44 )
V_45 = V_44 ;
else if ( V_41 -> V_41 . V_47 . V_45 < 144 )
V_45 = 144 ;
else
V_45 = V_41 -> V_41 . V_47 . V_45 & ~ 0x0f ;
if ( V_41 -> V_41 . V_47 . V_46 > V_43 )
V_46 = V_43 ;
else if ( V_41 -> V_41 . V_47 . V_46 < 96 )
V_46 = 96 ;
else
V_46 = V_41 -> V_41 . V_47 . V_46 & ~ 0x0f ;
} else {
int V_60 = V_41 -> V_41 . V_47 . V_45 * V_41 -> V_41 . V_47 . V_46 ;
int V_61 = V_44 * V_43 ;
if ( 64 * V_60 < 9 * V_61 ) {
V_45 = V_44 / 4 ;
V_46 = V_43 / 4 ;
} else if ( 64 * V_60 < 36 * V_61 ) {
V_45 = V_44 / 2 ;
V_46 = V_43 / 2 ;
} else {
V_45 = V_44 ;
V_46 = V_43 ;
}
V_45 &= ~ 0xf ;
V_46 &= ~ 0xf ;
}
if ( V_41 != NULL ) {
T_1 V_48 = V_41 -> V_41 . V_47 . V_48 ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> type = V_62 ;
V_41 -> V_41 . V_47 . V_45 = V_45 ;
V_41 -> V_41 . V_47 . V_46 = V_46 ;
V_41 -> V_41 . V_47 . V_48 = V_48 ;
V_41 -> V_41 . V_47 . V_63 = V_64 ;
V_41 -> V_41 . V_47 . V_65 = 0 ;
V_41 -> V_41 . V_47 . V_66 = V_67 ;
V_41 -> V_41 . V_47 . V_68 = V_69 ;
}
if ( V_42 )
return 0 ;
V_10 -> V_45 = V_45 ;
V_10 -> V_46 = V_46 ;
V_10 -> V_70 = V_10 -> V_57 -> V_71 ;
V_10 -> V_72 = V_10 -> V_57 -> V_73 ;
for ( V_3 = 0 ; V_3 < 4 ; ++ V_3 )
V_10 -> V_74 [ V_3 ] . V_75 = 0 ;
for ( V_3 = 0 ; V_3 < 1624 ; ++ V_3 )
V_10 -> V_76 [ V_3 ] = 0 ;
if ( V_10 -> V_57 -> V_58 & V_59 ) {
struct V_77 V_78 ;
V_78 . V_79 = V_80 ;
if ( V_41 != NULL )
V_78 . V_45 = V_41 -> V_41 . V_47 . V_45 ;
else
V_78 . V_45 = V_45 ;
if ( V_46 > V_43 / 2 ) {
V_78 . V_46 = V_46 / 2 ;
V_10 -> V_81 = 0 ;
} else {
V_78 . V_46 = V_46 ;
V_10 -> V_81 = 1 ;
}
F_23 ( & V_10 -> V_82 , V_83 , V_84 , & V_78 ) ;
} else {
if ( V_45 <= V_44 / 4 ) {
V_10 -> V_85 = 1 ;
V_10 -> V_81 = 1 ;
V_10 -> V_86 = 1 ;
} else if ( V_45 <= V_44 / 2 ) {
V_10 -> V_85 = 1 ;
V_10 -> V_81 = 1 ;
V_10 -> V_86 = 0 ;
} else {
V_10 -> V_85 = 0 ;
V_10 -> V_81 = 0 ;
V_10 -> V_86 = 0 ;
}
}
if ( V_41 == NULL )
return 0 ;
switch ( V_41 -> V_41 . V_47 . V_48 ) {
case V_50 :
if ( V_10 -> V_30 == V_38 ||
V_10 -> V_30 == V_39 ||
V_10 -> V_30 == V_34 )
break;
V_10 -> V_30 = V_38 ;
V_10 -> V_87 = 0 ;
V_10 -> V_88 = V_89 ;
V_10 -> V_90 = V_10 -> V_91 / 1000 ;
V_10 -> V_92 = 0 ;
V_10 -> V_93 = 1 ;
V_10 -> V_94 = 1 ;
V_10 -> V_95 = 1 ;
V_10 -> V_96 = 1 ;
V_10 -> V_97 = 0 ;
break;
case V_51 :
if ( V_10 -> V_30 == V_34 )
break;
V_10 -> V_30 = V_34 ;
V_10 -> V_87 = 0xf5 ;
V_10 -> V_88 = V_89 ;
V_10 -> V_90 = V_10 -> V_91 / 1000 ;
V_10 -> V_92 = 0 ;
V_10 -> V_93 = 1 ;
V_10 -> V_94 = 1 ;
V_10 -> V_95 = 1 ;
V_10 -> V_96 = 1 ;
V_10 -> V_97 = 0 ;
break;
case V_49 :
V_10 -> V_30 = V_32 ;
V_10 -> V_87 = 0 ;
V_10 -> V_88 = V_89 ;
V_10 -> V_90 = 0 ;
V_10 -> V_92 = 0 ;
V_10 -> V_93 = 0 ;
V_10 -> V_94 = 0 ;
V_10 -> V_95 = 0 ;
V_10 -> V_96 = 0 ;
V_10 -> V_97 = 0 ;
break;
}
return 0 ;
}
static int F_24 ( struct V_98 * V_99 )
{
static const T_1 V_100 [] = {
V_101 ,
V_102 ,
V_103 ,
V_104 ,
V_105 ,
V_106 ,
V_107 ,
0
} ;
static const T_1 * V_108 [] = {
V_100 ,
NULL
} ;
V_99 -> V_109 = F_25 ( V_108 , V_99 -> V_109 ) ;
switch ( V_99 -> V_109 ) {
case V_101 :
return F_26 ( V_99 , 0 , 0 , 0 , 0 ) ;
case V_102 :
return F_26 ( V_99 ,
V_110 ,
V_111 , 1 ,
V_111 ) ;
case V_103 :
return F_26 ( V_99 ,
V_112 ,
V_113 , 1 ,
V_114 ) ;
case V_104 :
return F_26 ( V_99 ,
V_115 ,
V_116 , 1 ,
V_115 ) ;
case V_105 :
return F_26 ( V_99 , 0 , 34 , 1 , 15 ) ;
case V_106 :
return F_26 ( V_99 , 0 , 1 , 1 , 0 ) ;
case V_107 :
return F_26 ( V_99 ,
64000 ,
10000000 , 1 ,
1500000 ) ;
default:
return - V_52 ;
}
return 0 ;
}
static int F_27 ( struct V_117 * V_99 , struct V_9 * V_10 )
{
if ( V_10 -> V_14 )
return - V_21 ;
switch ( V_99 -> V_109 ) {
case V_102 :
switch ( V_99 -> V_118 ) {
case V_110 :
V_10 -> V_30 = V_39 ;
V_10 -> V_119 = 9800000 ;
V_10 -> V_90 = 15 ;
V_10 -> V_87 = 0x48 ;
V_10 -> V_93 = 1 ;
V_10 -> V_94 = 0 ;
V_10 -> V_95 = 1 ;
V_10 -> V_96 = 1 ;
V_10 -> V_97 = 1 ;
break;
case V_111 :
break;
default:
return - V_52 ;
}
break;
case V_103 :
switch ( V_99 -> V_118 ) {
case V_112 :
V_10 -> V_30 = V_38 ;
V_10 -> V_87 = 0 ;
break;
case V_114 :
V_10 -> V_30 = V_39 ;
V_10 -> V_87 = 0x48 ;
break;
case V_113 :
V_10 -> V_30 = V_34 ;
V_10 -> V_87 = 0xf5 ;
break;
default:
return - V_52 ;
}
V_10 -> V_96 =
1 ;
V_10 -> V_94 = 0 ;
V_10 -> V_97 = 0 ;
break;
case V_104 :
if ( V_10 -> V_30 == V_32 )
return - V_52 ;
switch ( V_99 -> V_118 ) {
case V_115 :
V_10 -> V_88 = V_89 ;
break;
case V_120 :
V_10 -> V_88 = V_121 ;
break;
case V_116 :
V_10 -> V_88 = V_122 ;
break;
case V_123 :
default:
return - V_52 ;
}
break;
case V_105 :
if ( V_99 -> V_118 < 0 || V_99 -> V_118 > 34 )
return - V_52 ;
V_10 -> V_90 = V_99 -> V_118 ;
break;
case V_106 :
if ( V_99 -> V_118 != 0 && V_99 -> V_118 != 1 )
return - V_52 ;
V_10 -> V_93 = V_99 -> V_118 ;
break;
case V_107 :
if ( V_99 -> V_118 < 64000 || V_99 -> V_118 > 10000000 )
return - V_52 ;
V_10 -> V_119 = V_99 -> V_118 ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_28 ( struct V_117 * V_99 , struct V_9 * V_10 )
{
switch ( V_99 -> V_109 ) {
case V_102 :
if ( V_10 -> V_97 )
V_99 -> V_118 = V_110 ;
else
V_99 -> V_118 = V_111 ;
break;
case V_103 :
switch ( V_10 -> V_30 ) {
case V_38 :
V_99 -> V_118 = V_112 ;
break;
case V_39 :
V_99 -> V_118 = V_114 ;
break;
case V_34 :
V_99 -> V_118 = V_113 ;
break;
default:
return - V_52 ;
}
break;
case V_104 :
switch ( V_10 -> V_88 ) {
case V_89 :
V_99 -> V_118 = V_115 ;
break;
case V_121 :
V_99 -> V_118 = V_120 ;
break;
case V_122 :
V_99 -> V_118 = V_116 ;
break;
default:
return - V_52 ;
}
break;
case V_105 :
V_99 -> V_118 = V_10 -> V_90 ;
break;
case V_106 :
V_99 -> V_118 = V_10 -> V_93 ;
break;
case V_107 :
V_99 -> V_118 = V_10 -> V_119 ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_29 ( struct V_16 * V_16 , void * V_124 ,
struct V_125 * V_126 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
F_30 ( V_126 -> V_127 , L_1 , sizeof( V_126 -> V_127 ) ) ;
F_30 ( V_126 -> V_128 , V_10 -> V_129 , sizeof( V_126 -> V_128 ) ) ;
#if 0
strlcpy(cap->bus_info, dev_name(&dev->udev->dev), sizeof(cap->bus_info));
#endif
V_126 -> V_130 = F_31 ( 0 , 9 , 8 ) ;
V_126 -> V_131 = V_132 |
V_133 ;
if ( V_10 -> V_57 -> V_12 & V_134 )
V_126 -> V_131 |= V_135 ;
return 0 ;
}
static int F_32 ( struct V_16 * V_16 , void * V_124 ,
struct V_136 * V_41 )
{
char * V_137 = NULL ;
switch ( V_41 -> V_138 ) {
case 0 :
V_41 -> V_48 = V_49 ;
V_137 = L_2 ;
break;
case 1 :
V_41 -> V_48 = V_50 ;
V_137 = L_3 ;
break;
default:
return - V_52 ;
}
V_41 -> type = V_62 ;
V_41 -> V_12 = V_139 ;
strncpy ( V_41 -> V_140 , V_137 , sizeof( V_41 -> V_140 ) ) ;
return 0 ;
}
static int F_33 ( struct V_16 * V_16 , void * V_124 ,
struct V_40 * V_41 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
V_41 -> type = V_62 ;
V_41 -> V_41 . V_47 . V_45 = V_10 -> V_45 ;
V_41 -> V_41 . V_47 . V_46 = V_10 -> V_46 ;
V_41 -> V_41 . V_47 . V_48 = ( V_10 -> V_30 == V_32 ) ?
V_49 : V_50 ;
V_41 -> V_41 . V_47 . V_63 = V_64 ;
V_41 -> V_41 . V_47 . V_65 = 0 ;
V_41 -> V_41 . V_47 . V_66 = V_67 ;
V_41 -> V_41 . V_47 . V_68 = V_69 ;
return 0 ;
}
static int F_34 ( struct V_16 * V_16 , void * V_124 ,
struct V_40 * V_41 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
return F_22 ( V_10 , V_41 , 1 ) ;
}
static int F_35 ( struct V_16 * V_16 , void * V_124 ,
struct V_40 * V_41 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
if ( V_10 -> V_14 )
return - V_21 ;
return F_22 ( V_10 , V_41 , 0 ) ;
}
static int F_36 ( struct V_16 * V_16 , void * V_124 ,
struct V_141 * V_142 )
{
struct V_17 * V_18 = V_124 ;
struct V_9 * V_10 = V_18 -> V_10 ;
int V_143 = - V_21 ;
unsigned int V_144 , V_3 ;
if ( V_10 -> V_14 )
return V_143 ;
if ( V_142 -> type != V_62 ||
V_142 -> V_145 != V_146 )
return - V_52 ;
F_7 ( & V_18 -> V_25 ) ;
for ( V_3 = 0 ; V_3 < V_18 -> V_26 ; ++ V_3 )
if ( V_18 -> V_29 [ V_3 ] . V_147 > 0 )
goto V_148;
F_7 ( & V_10 -> V_13 ) ;
if ( V_10 -> V_28 > 0 && V_18 -> V_26 == 0 ) {
F_12 ( & V_10 -> V_13 ) ;
goto V_148;
}
if ( V_18 -> V_26 > 0 )
F_19 ( V_18 -> V_29 ) ;
V_143 = - V_23 ;
V_144 = V_142 -> V_144 ;
if ( V_144 > 0 ) {
if ( V_144 < 2 )
V_144 = 2 ;
if ( V_144 > 32 )
V_144 = 32 ;
V_18 -> V_29 = F_37 ( V_144 , sizeof( struct V_1 ) ,
V_22 ) ;
if ( ! V_18 -> V_29 ) {
F_12 ( & V_10 -> V_13 ) ;
goto V_148;
}
for ( V_3 = 0 ; V_3 < V_144 ; ++ V_3 ) {
V_18 -> V_29 [ V_3 ] . V_10 = V_10 ;
V_18 -> V_29 [ V_3 ] . V_138 = V_3 ;
V_18 -> V_29 [ V_3 ] . V_4 = V_5 ;
V_18 -> V_29 [ V_3 ] . V_147 = 0 ;
}
V_10 -> V_28 = 1 ;
} else {
V_10 -> V_28 = 0 ;
}
V_18 -> V_26 = V_144 ;
F_12 ( & V_10 -> V_13 ) ;
F_12 ( & V_18 -> V_25 ) ;
memset ( V_142 , 0 , sizeof( * V_142 ) ) ;
V_142 -> V_144 = V_144 ;
V_142 -> type = V_62 ;
V_142 -> V_145 = V_146 ;
return 0 ;
V_148:
F_12 ( & V_18 -> V_25 ) ;
return V_143 ;
}
static int F_38 ( struct V_16 * V_16 , void * V_124 ,
struct V_149 * V_150 )
{
struct V_17 * V_18 = V_124 ;
int V_143 = - V_52 ;
unsigned int V_138 ;
if ( V_150 -> type != V_62 )
return V_143 ;
V_138 = V_150 -> V_138 ;
F_7 ( & V_18 -> V_25 ) ;
if ( V_138 >= V_18 -> V_26 )
goto V_148;
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
V_150 -> V_138 = V_138 ;
V_150 -> type = V_62 ;
switch ( V_18 -> V_29 [ V_138 ] . V_4 ) {
case V_151 :
V_150 -> V_12 = V_152 ;
break;
case V_153 :
V_150 -> V_12 = V_154 ;
break;
default:
V_150 -> V_12 = 0 ;
}
if ( V_18 -> V_29 [ V_138 ] . V_147 )
V_150 -> V_12 |= V_155 ;
V_150 -> V_145 = V_146 ;
V_150 -> V_156 . V_157 = V_138 * V_67 ;
V_150 -> V_158 = V_67 ;
F_12 ( & V_18 -> V_25 ) ;
return 0 ;
V_148:
F_12 ( & V_18 -> V_25 ) ;
return V_143 ;
}
static int F_39 ( struct V_16 * V_16 , void * V_124 , struct V_149 * V_150 )
{
struct V_17 * V_18 = V_124 ;
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 ;
unsigned long V_12 ;
int V_143 = - V_52 ;
int V_159 ;
if ( V_150 -> type != V_62 ||
V_150 -> V_145 != V_146 )
return V_143 ;
F_7 ( & V_18 -> V_25 ) ;
if ( V_150 -> V_138 < 0 || V_150 -> V_138 >= V_18 -> V_26 )
goto V_148;
V_2 = & V_18 -> V_29 [ V_150 -> V_138 ] ;
if ( ! V_2 -> V_147 )
goto V_148;
V_143 = - V_21 ;
if ( V_2 -> V_4 != V_5 )
goto V_148;
V_2 -> V_157 = V_2 -> V_160 & ~ V_161 ;
V_2 -> V_162 = 0 ;
V_2 -> V_35 = 0 ;
V_2 -> V_163 = 0 ;
if ( V_2 -> V_157 > 0 )
V_2 -> V_7 = V_164 + 1 ;
else
V_2 -> V_7 = V_164 ;
V_143 = - V_23 ;
F_40 ( & V_165 -> V_166 -> V_167 ) ;
V_159 = F_41 ( V_165 , V_165 -> V_166 ,
V_2 -> V_160 & V_161 , V_2 -> V_7 ,
1 , 1 , V_2 -> V_8 , NULL ) ;
F_42 ( & V_165 -> V_166 -> V_167 ) ;
if ( V_159 != V_2 -> V_7 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_159 ; ++ V_3 )
F_3 ( V_2 -> V_8 [ V_3 ] ) ;
V_2 -> V_7 = 0 ;
goto V_148;
}
V_2 -> V_4 = V_151 ;
F_9 ( & V_10 -> V_15 , V_12 ) ;
F_43 ( & V_2 -> V_6 , & V_10 -> V_6 ) ;
F_10 ( & V_10 -> V_15 , V_12 ) ;
F_12 ( & V_18 -> V_25 ) ;
return 0 ;
V_148:
F_12 ( & V_18 -> V_25 ) ;
return V_143 ;
}
static int F_44 ( struct V_16 * V_16 , void * V_124 , struct V_149 * V_150 )
{
struct V_17 * V_18 = V_124 ;
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 ;
int V_143 = - V_52 ;
unsigned long V_12 ;
T_1 V_168 ;
F_45 ( V_169 ) ;
if ( V_150 -> type != V_62 )
return V_143 ;
if ( V_150 -> V_145 != V_146 )
return V_143 ;
F_7 ( & V_18 -> V_25 ) ;
if ( F_46 ( & V_10 -> V_6 ) )
goto V_148;
V_2 = F_47 ( V_10 -> V_6 . V_11 ,
struct V_1 , V_6 ) ;
V_143 = - V_170 ;
if ( V_2 -> V_4 != V_153 &&
! ( V_16 -> V_171 & V_172 ) ) {
for (; ; ) {
F_48 ( & V_10 -> V_173 , & V_169 ,
V_174 ) ;
if ( V_2 -> V_4 == V_153 )
break;
if ( F_49 ( V_165 ) ) {
V_143 = - V_175 ;
break;
}
F_50 () ;
}
F_51 ( & V_10 -> V_173 , & V_169 ) ;
}
if ( V_2 -> V_4 != V_153 )
goto V_148;
F_9 ( & V_10 -> V_15 , V_12 ) ;
F_1 ( V_2 ) ;
F_10 ( & V_10 -> V_15 , V_12 ) ;
V_168 = F_20 ( V_2 , V_10 -> V_30 ) ;
V_2 -> V_4 = V_5 ;
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
V_150 -> V_138 = V_2 -> V_138 ;
V_150 -> type = V_62 ;
V_150 -> V_162 = V_2 -> V_162 ;
V_150 -> V_12 = V_155 | V_168 ;
V_150 -> V_63 = V_64 ;
V_150 -> V_176 = V_2 -> V_176 ;
V_150 -> V_177 = V_2 -> V_178 ;
V_150 -> V_145 = V_146 ;
V_150 -> V_156 . V_157 = V_2 -> V_138 * V_67 ;
V_150 -> V_158 = V_67 ;
V_150 -> V_179 = V_2 -> V_163 ;
F_12 ( & V_18 -> V_25 ) ;
return 0 ;
V_148:
F_12 ( & V_18 -> V_25 ) ;
return V_143 ;
}
static int F_52 ( struct V_16 * V_16 , void * V_124 ,
enum V_180 type )
{
struct V_17 * V_18 = V_124 ;
struct V_9 * V_10 = V_18 -> V_10 ;
int V_143 = 0 ;
if ( type != V_62 )
return - V_52 ;
F_7 ( & V_18 -> V_25 ) ;
F_7 ( & V_10 -> V_13 ) ;
if ( ! V_10 -> V_14 ) {
V_10 -> V_14 = 1 ;
V_10 -> V_181 = 0 ;
V_10 -> V_182 = NULL ;
if ( F_53 ( V_10 ) < 0 )
V_143 = - V_183 ;
else
V_143 = 0 ;
}
F_12 ( & V_10 -> V_13 ) ;
F_12 ( & V_18 -> V_25 ) ;
return V_143 ;
}
static int F_54 ( struct V_16 * V_16 , void * V_124 ,
enum V_180 type )
{
struct V_17 * V_18 = V_124 ;
struct V_9 * V_10 = V_18 -> V_10 ;
if ( type != V_62 )
return - V_52 ;
F_7 ( & V_18 -> V_25 ) ;
F_6 ( V_10 ) ;
F_12 ( & V_18 -> V_25 ) ;
return 0 ;
}
static int F_55 ( struct V_16 * V_16 , void * V_124 ,
struct V_98 * V_184 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
int V_109 = V_184 -> V_109 ;
if ( 0 == F_23 ( & V_10 -> V_82 , V_185 , V_186 , V_184 ) )
return 0 ;
V_184 -> V_109 = V_109 ;
return F_24 ( V_184 ) ;
}
static int F_56 ( struct V_16 * V_16 , void * V_124 ,
struct V_117 * V_99 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
if ( 0 == F_23 ( & V_10 -> V_82 , V_185 , V_187 , V_99 ) )
return 0 ;
return F_28 ( V_99 , V_10 ) ;
}
static int F_57 ( struct V_16 * V_16 , void * V_124 ,
struct V_117 * V_99 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
if ( 0 == F_23 ( & V_10 -> V_82 , V_185 , V_188 , V_99 ) )
return 0 ;
return F_27 ( V_99 , V_10 ) ;
}
static int F_58 ( struct V_16 * V_189 , void * V_124 ,
struct V_190 * V_191 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
struct V_192 V_193 = {
. V_194 = 1001 * V_10 -> V_195 ,
. V_196 = V_10 -> V_91 ,
} ;
if ( V_191 -> type != V_62 )
return - V_52 ;
V_191 -> V_191 . V_197 . V_198 |= V_199 ;
V_191 -> V_191 . V_197 . V_193 = V_193 ;
return 0 ;
}
static int F_59 ( struct V_16 * V_189 , void * V_124 ,
struct V_190 * V_191 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
unsigned int V_200 , V_201 ;
if ( V_191 -> type != V_62 )
return - V_52 ;
if ( V_191 -> V_191 . V_197 . V_202 != 0 )
return - V_52 ;
V_200 = V_10 -> V_91 *
V_191 -> V_191 . V_197 . V_193 . V_194 ;
V_201 = 1001 * V_191 -> V_191 . V_197 . V_193 . V_196 ;
if ( V_200 != 0 && V_201 != 0 && V_200 > V_201 )
V_10 -> V_195 = ( V_200 + V_201 / 2 ) / V_201 ;
else
V_10 -> V_195 = 1 ;
return 0 ;
}
static int F_60 ( struct V_16 * V_189 , void * V_124 ,
struct V_203 * V_204 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
if ( ( V_10 -> V_57 -> V_12 & V_134 ) ||
( V_10 -> V_57 -> V_58 & V_205 ) )
return - V_52 ;
if ( V_204 -> V_138 > 0 )
return - V_52 ;
V_204 -> type = V_206 ;
V_204 -> V_207 . V_45 = V_10 -> V_57 -> V_44 ;
V_204 -> V_207 . V_46 = V_10 -> V_57 -> V_43 ;
return 0 ;
}
static int F_61 ( struct V_16 * V_189 , void * V_124 ,
struct V_208 * V_209 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
if ( ( V_10 -> V_57 -> V_12 & V_134 ) ||
( V_10 -> V_57 -> V_58 & V_205 ) )
return - V_52 ;
if ( V_209 -> V_138 > 0 )
return - V_52 ;
V_209 -> type = V_210 ;
V_209 -> V_207 . V_194 = 1001 ;
V_209 -> V_207 . V_196 = V_10 -> V_57 -> V_91 ;
return 0 ;
}
static int F_62 ( struct V_16 * V_16 , void * V_124 , T_3 * V_211 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
switch ( V_10 -> V_53 ) {
case V_54 :
* V_211 = V_212 ;
break;
case V_55 :
* V_211 = V_213 ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_63 ( struct V_16 * V_16 , void * V_124 , T_3 * V_211 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
if ( V_10 -> V_14 )
return - V_21 ;
if ( ! ( V_10 -> V_57 -> V_58 & V_205 ) && * V_211 != 0 )
return - V_52 ;
if ( * V_211 == 0 )
return - V_52 ;
if ( ( V_10 -> V_57 -> V_12 & V_134 ) &&
V_10 -> V_214 == V_10 -> V_57 -> V_215 - 1 ) {
if ( ! V_10 -> V_216 )
return - V_183 ;
if ( F_23 ( & V_10 -> V_82 , V_185 , V_217 , * V_211 ) < 0 )
return - V_52 ;
}
if ( * V_211 & V_212 ) {
V_10 -> V_53 = V_54 ;
V_10 -> V_91 = 30000 ;
} else if ( * V_211 & V_213 ) {
V_10 -> V_53 = V_55 ;
V_10 -> V_91 = 25025 ;
} else if ( * V_211 & V_218 ) {
V_10 -> V_53 = V_55 ;
V_10 -> V_91 = 25025 ;
} else
return - V_52 ;
F_23 ( & V_10 -> V_82 , V_185 , V_217 , * V_211 ) ;
F_22 ( V_10 , NULL , 0 ) ;
return 0 ;
}
static int F_64 ( struct V_16 * V_16 , void * V_124 , T_3 * V_211 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
if ( ( V_10 -> V_57 -> V_12 & V_134 ) &&
V_10 -> V_214 == V_10 -> V_57 -> V_215 - 1 ) {
if ( ! V_10 -> V_216 )
return - V_183 ;
return F_23 ( & V_10 -> V_82 , V_83 , V_219 , V_211 ) ;
} else if ( V_10 -> V_57 -> V_58 & V_205 )
* V_211 = V_212 | V_213 | V_218 ;
else
* V_211 = 0 ;
return 0 ;
}
static int F_65 ( struct V_16 * V_16 , void * V_124 ,
struct V_220 * V_221 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
if ( V_221 -> V_138 >= V_10 -> V_57 -> V_215 )
return - V_52 ;
strncpy ( V_221 -> V_129 , V_10 -> V_57 -> V_222 [ V_221 -> V_138 ] . V_129 ,
sizeof( V_221 -> V_129 ) ) ;
if ( ( V_10 -> V_57 -> V_12 & V_134 ) &&
V_221 -> V_138 == V_10 -> V_57 -> V_215 - 1 )
V_221 -> type = V_223 ;
else
V_221 -> type = V_224 ;
V_221 -> V_225 = 0 ;
V_221 -> V_226 = 0 ;
if ( V_10 -> V_57 -> V_58 & V_205 )
V_221 -> V_211 = V_212 | V_213 |
V_218 ;
else
V_221 -> V_211 = 0 ;
return 0 ;
}
static int F_66 ( struct V_16 * V_16 , void * V_124 , unsigned int * V_214 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
* V_214 = V_10 -> V_214 ;
return 0 ;
}
static int F_67 ( struct V_16 * V_16 , void * V_124 , unsigned int V_214 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
if ( V_214 >= V_10 -> V_57 -> V_215 )
return - V_52 ;
if ( V_10 -> V_14 )
return - V_21 ;
V_10 -> V_214 = V_214 ;
return F_23 ( & V_10 -> V_82 , V_83 , V_227 , V_214 , 0 , 0 ) ;
}
static int F_68 ( struct V_16 * V_16 , void * V_124 ,
struct V_228 * V_229 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
if ( ! ( V_10 -> V_57 -> V_12 & V_134 ) )
return - V_52 ;
if ( V_229 -> V_138 != 0 )
return - V_52 ;
if ( ! V_10 -> V_216 )
return - V_183 ;
return F_23 ( & V_10 -> V_82 , V_226 , V_230 , V_229 ) ;
}
static int F_69 ( struct V_16 * V_16 , void * V_124 ,
struct V_228 * V_229 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
if ( ! ( V_10 -> V_57 -> V_12 & V_134 ) )
return - V_52 ;
if ( V_229 -> V_138 != 0 )
return - V_52 ;
if ( ! V_10 -> V_216 )
return - V_183 ;
switch ( V_10 -> V_231 ) {
case V_232 :
case V_233 :
if ( V_229 -> V_234 != V_235 )
return - V_52 ;
break;
}
return F_23 ( & V_10 -> V_82 , V_226 , V_236 , V_229 ) ;
}
static int F_70 ( struct V_16 * V_16 , void * V_124 ,
struct V_237 * V_31 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
if ( ! ( V_10 -> V_57 -> V_12 & V_134 ) )
return - V_52 ;
if ( ! V_10 -> V_216 )
return - V_183 ;
V_31 -> type = V_238 ;
return F_23 ( & V_10 -> V_82 , V_226 , V_239 , V_31 ) ;
}
static int F_71 ( struct V_16 * V_16 , void * V_124 ,
struct V_237 * V_31 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
if ( ! ( V_10 -> V_57 -> V_12 & V_134 ) )
return - V_52 ;
if ( ! V_10 -> V_216 )
return - V_183 ;
return F_23 ( & V_10 -> V_82 , V_226 , V_240 , V_31 ) ;
}
static int F_72 ( struct V_16 * V_16 , void * V_124 ,
struct V_241 * V_242 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
if ( V_242 -> type != V_62 )
return - V_52 ;
switch ( V_10 -> V_53 ) {
case V_54 :
V_242 -> V_243 . V_244 = 0 ;
V_242 -> V_243 . V_245 = 0 ;
V_242 -> V_243 . V_45 = 720 ;
V_242 -> V_243 . V_46 = 480 ;
V_242 -> V_246 . V_244 = 0 ;
V_242 -> V_246 . V_245 = 0 ;
V_242 -> V_246 . V_45 = 720 ;
V_242 -> V_246 . V_46 = 480 ;
break;
case V_55 :
V_242 -> V_243 . V_244 = 0 ;
V_242 -> V_243 . V_245 = 0 ;
V_242 -> V_243 . V_45 = 720 ;
V_242 -> V_243 . V_46 = 576 ;
V_242 -> V_246 . V_244 = 0 ;
V_242 -> V_246 . V_245 = 0 ;
V_242 -> V_246 . V_45 = 720 ;
V_242 -> V_246 . V_46 = 576 ;
break;
case V_56 :
V_242 -> V_243 . V_244 = 0 ;
V_242 -> V_243 . V_245 = 0 ;
V_242 -> V_243 . V_45 = V_10 -> V_57 -> V_44 ;
V_242 -> V_243 . V_46 = V_10 -> V_57 -> V_43 ;
V_242 -> V_246 . V_244 = 0 ;
V_242 -> V_246 . V_245 = 0 ;
V_242 -> V_246 . V_45 = V_10 -> V_57 -> V_44 ;
V_242 -> V_246 . V_46 = V_10 -> V_57 -> V_43 ;
break;
}
return 0 ;
}
static int F_73 ( struct V_16 * V_16 , void * V_124 , struct V_247 * V_248 )
{
struct V_9 * V_10 = ( (struct V_17 * ) V_124 ) -> V_10 ;
if ( V_248 -> type != V_62 )
return - V_52 ;
V_248 -> type = V_62 ;
switch ( V_10 -> V_53 ) {
case V_54 :
V_248 -> V_249 . V_244 = 0 ;
V_248 -> V_249 . V_245 = 0 ;
V_248 -> V_249 . V_45 = 720 ;
V_248 -> V_249 . V_46 = 480 ;
break;
case V_55 :
V_248 -> V_249 . V_244 = 0 ;
V_248 -> V_249 . V_245 = 0 ;
V_248 -> V_249 . V_45 = 720 ;
V_248 -> V_249 . V_46 = 576 ;
break;
case V_56 :
V_248 -> V_249 . V_244 = 0 ;
V_248 -> V_249 . V_245 = 0 ;
V_248 -> V_249 . V_45 = V_10 -> V_57 -> V_44 ;
V_248 -> V_249 . V_46 = V_10 -> V_57 -> V_43 ;
break;
}
return 0 ;
}
static int F_74 ( struct V_16 * V_16 , void * V_124 , const struct V_247 * V_248 )
{
if ( V_248 -> type != V_62 )
return - V_52 ;
return 0 ;
}
static int F_75 ( struct V_16 * V_16 , void * V_124 ,
struct V_250 * V_251 )
{
memset ( V_251 , 0 , sizeof( * V_251 ) ) ;
V_251 -> V_252 = 50 ;
V_251 -> V_253 = V_254 |
V_255 ;
return 0 ;
}
static int F_76 ( struct V_16 * V_16 , void * V_124 ,
const struct V_250 * V_251 )
{
if ( V_251 -> V_252 != 50 ||
V_251 -> V_253 != ( V_254 |
V_255 ) )
return - V_52 ;
return 0 ;
}
static T_4 F_77 ( struct V_16 * V_16 , char T_5 * V_256 ,
T_6 V_144 , T_7 * V_257 )
{
return - V_52 ;
}
static void F_78 ( struct V_258 * V_259 )
{
struct V_1 * V_2 = V_259 -> V_260 ;
++ V_2 -> V_147 ;
}
static void F_79 ( struct V_258 * V_259 )
{
struct V_1 * V_2 = V_259 -> V_260 ;
unsigned long V_12 ;
if ( -- V_2 -> V_147 == 0 ) {
F_9 ( & V_2 -> V_10 -> V_15 , V_12 ) ;
F_1 ( V_2 ) ;
F_10 ( & V_2 -> V_10 -> V_15 , V_12 ) ;
}
}
static int F_80 ( struct V_258 * V_259 , struct V_261 * V_262 )
{
struct V_263 * V_263 ;
V_263 = F_81 ( V_264 | V_265 ) ;
if ( ! V_263 )
return V_266 ;
F_82 ( V_263 , ( unsigned long ) V_262 -> V_267 ) ;
V_262 -> V_263 = V_263 ;
return 0 ;
}
static int F_83 ( struct V_16 * V_16 , struct V_258 * V_259 )
{
struct V_17 * V_18 = V_16 -> V_27 ;
unsigned int V_138 ;
if ( V_18 -> V_10 -> V_19 != V_20 )
return - V_183 ;
if ( ! ( V_259 -> V_268 & V_269 ) )
return - V_52 ;
if ( V_259 -> V_270 - V_259 -> V_271 != V_67 )
return - V_52 ;
F_7 ( & V_18 -> V_25 ) ;
V_138 = V_259 -> V_272 / V_164 ;
if ( V_138 >= V_18 -> V_26 ) {
F_12 ( & V_18 -> V_25 ) ;
return - V_52 ;
}
if ( V_138 * V_164 != V_259 -> V_272 ) {
F_12 ( & V_18 -> V_25 ) ;
return - V_52 ;
}
if ( V_18 -> V_29 [ V_138 ] . V_147 > 0 ) {
F_12 ( & V_18 -> V_25 ) ;
return - V_21 ;
}
V_18 -> V_29 [ V_138 ] . V_147 = 1 ;
V_18 -> V_29 [ V_138 ] . V_160 = V_259 -> V_271 ;
V_259 -> V_273 = & V_274 ;
V_259 -> V_268 |= V_275 ;
V_259 -> V_268 &= ~ V_276 ;
V_259 -> V_260 = & V_18 -> V_29 [ V_138 ] ;
F_12 ( & V_18 -> V_25 ) ;
return 0 ;
}
static unsigned int F_84 ( struct V_16 * V_16 , T_8 * V_169 )
{
struct V_17 * V_18 = V_16 -> V_27 ;
struct V_1 * V_2 ;
if ( F_46 ( & V_18 -> V_10 -> V_6 ) )
return V_277 ;
V_2 = F_47 ( V_18 -> V_10 -> V_6 . V_11 , struct V_1 , V_6 ) ;
F_85 ( V_16 , & V_18 -> V_10 -> V_173 , V_169 ) ;
if ( V_2 -> V_4 == V_153 )
return V_278 | V_279 ;
return 0 ;
}
static void F_86 ( struct V_280 * V_281 )
{
struct V_9 * V_10 = F_14 ( V_281 ) ;
F_87 ( V_281 ) ;
if ( -- V_10 -> V_24 == 0 )
F_19 ( V_10 ) ;
}
int F_88 ( struct V_9 * V_10 )
{
int V_282 ;
V_10 -> V_283 = F_89 () ;
if ( V_10 -> V_283 == NULL )
return - V_23 ;
* V_10 -> V_283 = V_284 ;
V_10 -> V_283 -> V_285 = V_10 -> V_286 ;
V_282 = F_90 ( V_10 -> V_283 , V_287 , - 1 ) ;
if ( V_282 < 0 ) {
F_87 ( V_10 -> V_283 ) ;
V_10 -> V_283 = NULL ;
return V_282 ;
}
V_282 = F_91 ( V_10 -> V_286 , & V_10 -> V_82 ) ;
if ( V_282 < 0 ) {
F_87 ( V_10 -> V_283 ) ;
V_10 -> V_283 = NULL ;
return V_282 ;
}
F_92 ( V_10 -> V_283 , V_10 ) ;
++ V_10 -> V_24 ;
F_93 ( V_288 L_4 ,
V_10 -> V_283 -> V_129 , F_94 ( V_10 -> V_283 ) ) ;
return 0 ;
}
void F_95 ( struct V_9 * V_10 )
{
unsigned long V_12 ;
F_7 ( & V_10 -> V_13 ) ;
if ( V_10 -> V_14 ) {
V_10 -> V_14 = 0 ;
F_8 ( V_10 ) ;
F_9 ( & V_10 -> V_15 , V_12 ) ;
F_4 ( V_10 ) ;
F_10 ( & V_10 -> V_15 , V_12 ) ;
}
F_12 ( & V_10 -> V_13 ) ;
if ( V_10 -> V_283 )
F_96 ( V_10 -> V_283 ) ;
F_97 ( & V_10 -> V_82 ) ;
}
