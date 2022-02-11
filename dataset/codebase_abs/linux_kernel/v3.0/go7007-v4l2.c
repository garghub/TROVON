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
int V_12 = - V_13 ;
unsigned long V_14 ;
F_7 ( & V_10 -> V_15 ) ;
if ( V_10 -> V_16 ) {
V_10 -> V_16 = 0 ;
F_8 ( V_10 ) ;
F_9 ( & V_10 -> V_17 , V_14 ) ;
F_4 ( V_10 ) ;
F_10 ( & V_10 -> V_17 , V_14 ) ;
F_11 ( V_10 ) ;
V_12 = 0 ;
}
F_12 ( & V_10 -> V_15 ) ;
return 0 ;
}
static int F_13 ( struct V_18 * V_18 )
{
struct V_9 * V_10 = F_14 ( F_15 ( V_18 ) ) ;
struct V_19 * V_20 ;
if ( V_10 -> V_21 != V_22 )
return - V_23 ;
V_20 = F_16 ( sizeof( struct V_19 ) , V_24 ) ;
if ( V_20 == NULL )
return - V_25 ;
++ V_10 -> V_26 ;
V_20 -> V_10 = V_10 ;
F_17 ( & V_20 -> V_27 ) ;
V_20 -> V_28 = 0 ;
V_18 -> V_29 = V_20 ;
return 0 ;
}
static int F_18 ( struct V_18 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_29 ;
struct V_9 * V_10 = V_20 -> V_10 ;
if ( V_20 -> V_28 > 0 ) {
F_6 ( V_10 ) ;
V_10 -> V_30 = 0 ;
F_19 ( V_20 -> V_31 ) ;
V_20 -> V_28 = 0 ;
}
F_19 ( V_20 ) ;
if ( -- V_10 -> V_26 == 0 )
F_19 ( V_10 ) ;
V_18 -> V_29 = NULL ;
return 0 ;
}
static T_1 F_20 ( struct V_1 * V_2 , int V_32 )
{
T_2 * V_33 = F_21 ( V_2 -> V_8 [ 0 ] ) ;
switch ( V_32 ) {
case V_34 :
return V_35 ;
case V_36 :
switch ( ( V_33 [ V_2 -> V_37 + 4 ] >> 6 ) & 0x3 ) {
case 0 :
return V_35 ;
case 1 :
return V_38 ;
case 2 :
return V_39 ;
default:
return 0 ;
}
case V_40 :
case V_41 :
switch ( ( V_33 [ V_2 -> V_37 + 5 ] >> 3 ) & 0x7 ) {
case 1 :
return V_35 ;
case 2 :
return V_38 ;
case 3 :
return V_39 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_22 ( struct V_9 * V_10 , struct V_42 * V_43 , int V_44 )
{
int V_45 = 0 , V_46 = 0 ;
int V_47 , V_48 , V_3 ;
if ( V_43 != NULL && V_43 -> V_43 . V_49 . V_50 != V_51 &&
V_43 -> V_43 . V_49 . V_50 != V_52 &&
V_43 -> V_43 . V_49 . V_50 != V_53 )
return - V_13 ;
switch ( V_10 -> V_54 ) {
case V_55 :
V_46 = 720 ;
V_45 = 480 ;
break;
case V_56 :
V_46 = 720 ;
V_45 = 576 ;
break;
case V_57 :
V_46 = V_10 -> V_58 -> V_46 ;
V_45 = V_10 -> V_58 -> V_45 ;
break;
}
if ( V_43 == NULL ) {
V_47 = V_46 ;
V_48 = V_45 ;
} else if ( V_10 -> V_58 -> V_59 & V_60 ) {
if ( V_43 -> V_43 . V_49 . V_47 > V_46 )
V_47 = V_46 ;
else if ( V_43 -> V_43 . V_49 . V_47 < 144 )
V_47 = 144 ;
else
V_47 = V_43 -> V_43 . V_49 . V_47 & ~ 0x0f ;
if ( V_43 -> V_43 . V_49 . V_48 > V_45 )
V_48 = V_45 ;
else if ( V_43 -> V_43 . V_49 . V_48 < 96 )
V_48 = 96 ;
else
V_48 = V_43 -> V_43 . V_49 . V_48 & ~ 0x0f ;
} else {
int V_61 = V_43 -> V_43 . V_49 . V_47 * V_43 -> V_43 . V_49 . V_48 ;
int V_62 = V_46 * V_45 ;
if ( 64 * V_61 < 9 * V_62 ) {
V_47 = V_46 / 4 ;
V_48 = V_45 / 4 ;
} else if ( 64 * V_61 < 36 * V_62 ) {
V_47 = V_46 / 2 ;
V_48 = V_45 / 2 ;
} else {
V_47 = V_46 ;
V_48 = V_45 ;
}
V_47 &= ~ 0xf ;
V_48 &= ~ 0xf ;
}
if ( V_43 != NULL ) {
T_1 V_50 = V_43 -> V_43 . V_49 . V_50 ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
V_43 -> type = V_63 ;
V_43 -> V_43 . V_49 . V_47 = V_47 ;
V_43 -> V_43 . V_49 . V_48 = V_48 ;
V_43 -> V_43 . V_49 . V_50 = V_50 ;
V_43 -> V_43 . V_49 . V_64 = V_65 ;
V_43 -> V_43 . V_49 . V_66 = 0 ;
V_43 -> V_43 . V_49 . V_67 = V_68 ;
V_43 -> V_43 . V_49 . V_69 = V_70 ;
}
if ( V_44 )
return 0 ;
V_10 -> V_47 = V_47 ;
V_10 -> V_48 = V_48 ;
V_10 -> V_71 = V_10 -> V_58 -> V_72 ;
V_10 -> V_73 = V_10 -> V_58 -> V_74 ;
for ( V_3 = 0 ; V_3 < 4 ; ++ V_3 )
V_10 -> V_75 [ V_3 ] . V_76 = 0 ;
for ( V_3 = 0 ; V_3 < 1624 ; ++ V_3 )
V_10 -> V_77 [ V_3 ] = 0 ;
if ( V_10 -> V_58 -> V_59 & V_60 ) {
struct V_78 V_79 ;
V_79 . V_80 = V_81 ;
if ( V_43 != NULL )
V_79 . V_47 = V_43 -> V_43 . V_49 . V_47 ;
else
V_79 . V_47 = V_47 ;
if ( V_48 > V_45 / 2 ) {
V_79 . V_48 = V_48 / 2 ;
V_10 -> V_82 = 0 ;
} else {
V_79 . V_48 = V_48 ;
V_10 -> V_82 = 1 ;
}
F_23 ( & V_10 -> V_83 , V_84 , V_85 , & V_79 ) ;
} else {
if ( V_47 <= V_46 / 4 ) {
V_10 -> V_86 = 1 ;
V_10 -> V_82 = 1 ;
V_10 -> V_87 = 1 ;
} else if ( V_47 <= V_46 / 2 ) {
V_10 -> V_86 = 1 ;
V_10 -> V_82 = 1 ;
V_10 -> V_87 = 0 ;
} else {
V_10 -> V_86 = 0 ;
V_10 -> V_82 = 0 ;
V_10 -> V_87 = 0 ;
}
}
if ( V_43 == NULL )
return 0 ;
switch ( V_43 -> V_43 . V_49 . V_50 ) {
case V_52 :
if ( V_10 -> V_32 == V_40 ||
V_10 -> V_32 == V_41 ||
V_10 -> V_32 == V_36 )
break;
V_10 -> V_32 = V_40 ;
V_10 -> V_88 = 0 ;
V_10 -> V_89 = V_90 ;
V_10 -> V_91 = V_10 -> V_92 / 1000 ;
V_10 -> V_93 = 0 ;
V_10 -> V_94 = 1 ;
V_10 -> V_95 = 1 ;
V_10 -> V_96 = 1 ;
V_10 -> V_97 = 1 ;
V_10 -> V_98 = 0 ;
break;
case V_53 :
if ( V_10 -> V_32 == V_36 )
break;
V_10 -> V_32 = V_36 ;
V_10 -> V_88 = 0xf5 ;
V_10 -> V_89 = V_90 ;
V_10 -> V_91 = V_10 -> V_92 / 1000 ;
V_10 -> V_93 = 0 ;
V_10 -> V_94 = 1 ;
V_10 -> V_95 = 1 ;
V_10 -> V_96 = 1 ;
V_10 -> V_97 = 1 ;
V_10 -> V_98 = 0 ;
break;
case V_51 :
V_10 -> V_32 = V_34 ;
V_10 -> V_88 = 0 ;
V_10 -> V_89 = V_90 ;
V_10 -> V_91 = 0 ;
V_10 -> V_93 = 0 ;
V_10 -> V_94 = 0 ;
V_10 -> V_95 = 0 ;
V_10 -> V_96 = 0 ;
V_10 -> V_97 = 0 ;
V_10 -> V_98 = 0 ;
break;
}
return 0 ;
}
static int F_24 ( struct V_99 * V_100 )
{
static const T_1 V_101 [] = {
V_102 ,
V_103 ,
V_104 ,
V_105 ,
V_106 ,
V_107 ,
V_108 ,
0
} ;
static const T_1 * V_109 [] = {
V_101 ,
NULL
} ;
V_100 -> V_110 = F_25 ( V_109 , V_100 -> V_110 ) ;
switch ( V_100 -> V_110 ) {
case V_102 :
return F_26 ( V_100 , 0 , 0 , 0 , 0 ) ;
case V_103 :
return F_26 ( V_100 ,
V_111 ,
V_112 , 1 ,
V_112 ) ;
case V_104 :
return F_26 ( V_100 ,
V_113 ,
V_114 , 1 ,
V_115 ) ;
case V_105 :
return F_26 ( V_100 ,
V_116 ,
V_117 , 1 ,
V_116 ) ;
case V_106 :
return F_26 ( V_100 , 0 , 34 , 1 , 15 ) ;
case V_107 :
return F_26 ( V_100 , 0 , 1 , 1 , 0 ) ;
case V_108 :
return F_26 ( V_100 ,
64000 ,
10000000 , 1 ,
1500000 ) ;
default:
return - V_13 ;
}
return 0 ;
}
static int F_27 ( struct V_118 * V_100 , struct V_9 * V_10 )
{
if ( V_10 -> V_16 )
return - V_23 ;
switch ( V_100 -> V_110 ) {
case V_103 :
switch ( V_100 -> V_119 ) {
case V_111 :
V_10 -> V_32 = V_41 ;
V_10 -> V_120 = 9800000 ;
V_10 -> V_91 = 15 ;
V_10 -> V_88 = 0x48 ;
V_10 -> V_94 = 1 ;
V_10 -> V_95 = 0 ;
V_10 -> V_96 = 1 ;
V_10 -> V_97 = 1 ;
V_10 -> V_98 = 1 ;
break;
case V_112 :
break;
default:
return - V_13 ;
}
break;
case V_104 :
switch ( V_100 -> V_119 ) {
case V_113 :
V_10 -> V_32 = V_40 ;
V_10 -> V_88 = 0 ;
break;
case V_115 :
V_10 -> V_32 = V_41 ;
V_10 -> V_88 = 0x48 ;
break;
case V_114 :
V_10 -> V_32 = V_36 ;
V_10 -> V_88 = 0xf5 ;
break;
default:
return - V_13 ;
}
V_10 -> V_97 =
1 ;
V_10 -> V_95 = 0 ;
V_10 -> V_98 = 0 ;
break;
case V_105 :
if ( V_10 -> V_32 == V_34 )
return - V_13 ;
switch ( V_100 -> V_119 ) {
case V_116 :
V_10 -> V_89 = V_90 ;
break;
case V_121 :
V_10 -> V_89 = V_122 ;
break;
case V_117 :
V_10 -> V_89 = V_123 ;
break;
case V_124 :
default:
return - V_13 ;
}
break;
case V_106 :
if ( V_100 -> V_119 < 0 || V_100 -> V_119 > 34 )
return - V_13 ;
V_10 -> V_91 = V_100 -> V_119 ;
break;
case V_107 :
if ( V_100 -> V_119 != 0 && V_100 -> V_119 != 1 )
return - V_13 ;
V_10 -> V_94 = V_100 -> V_119 ;
break;
case V_108 :
if ( V_100 -> V_119 < 64000 || V_100 -> V_119 > 10000000 )
return - V_13 ;
V_10 -> V_120 = V_100 -> V_119 ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static int F_28 ( struct V_118 * V_100 , struct V_9 * V_10 )
{
switch ( V_100 -> V_110 ) {
case V_103 :
if ( V_10 -> V_98 )
V_100 -> V_119 = V_111 ;
else
V_100 -> V_119 = V_112 ;
break;
case V_104 :
switch ( V_10 -> V_32 ) {
case V_40 :
V_100 -> V_119 = V_113 ;
break;
case V_41 :
V_100 -> V_119 = V_115 ;
break;
case V_36 :
V_100 -> V_119 = V_114 ;
break;
default:
return - V_13 ;
}
break;
case V_105 :
switch ( V_10 -> V_89 ) {
case V_90 :
V_100 -> V_119 = V_116 ;
break;
case V_122 :
V_100 -> V_119 = V_121 ;
break;
case V_123 :
V_100 -> V_119 = V_117 ;
break;
default:
return - V_13 ;
}
break;
case V_106 :
V_100 -> V_119 = V_10 -> V_91 ;
break;
case V_107 :
V_100 -> V_119 = V_10 -> V_94 ;
break;
case V_108 :
V_100 -> V_119 = V_10 -> V_120 ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static int F_29 ( struct V_18 * V_18 , void * V_125 ,
struct V_126 * V_127 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
F_30 ( V_127 -> V_128 , L_1 , sizeof( V_127 -> V_128 ) ) ;
F_30 ( V_127 -> V_129 , V_10 -> V_130 , sizeof( V_127 -> V_129 ) ) ;
#if 0
strlcpy(cap->bus_info, dev_name(&dev->udev->dev), sizeof(cap->bus_info));
#endif
V_127 -> V_131 = F_31 ( 0 , 9 , 8 ) ;
V_127 -> V_132 = V_133 |
V_134 ;
if ( V_10 -> V_58 -> V_14 & V_135 )
V_127 -> V_132 |= V_136 ;
return 0 ;
}
static int F_32 ( struct V_18 * V_18 , void * V_125 ,
struct V_137 * V_43 )
{
char * V_138 = NULL ;
switch ( V_43 -> V_139 ) {
case 0 :
V_43 -> V_50 = V_51 ;
V_138 = L_2 ;
break;
case 1 :
V_43 -> V_50 = V_52 ;
V_138 = L_3 ;
break;
default:
return - V_13 ;
}
V_43 -> type = V_63 ;
V_43 -> V_14 = V_140 ;
strncpy ( V_43 -> V_141 , V_138 , sizeof( V_43 -> V_141 ) ) ;
return 0 ;
}
static int F_33 ( struct V_18 * V_18 , void * V_125 ,
struct V_42 * V_43 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
V_43 -> type = V_63 ;
V_43 -> V_43 . V_49 . V_47 = V_10 -> V_47 ;
V_43 -> V_43 . V_49 . V_48 = V_10 -> V_48 ;
V_43 -> V_43 . V_49 . V_50 = ( V_10 -> V_32 == V_34 ) ?
V_51 : V_52 ;
V_43 -> V_43 . V_49 . V_64 = V_65 ;
V_43 -> V_43 . V_49 . V_66 = 0 ;
V_43 -> V_43 . V_49 . V_67 = V_68 ;
V_43 -> V_43 . V_49 . V_69 = V_70 ;
return 0 ;
}
static int F_34 ( struct V_18 * V_18 , void * V_125 ,
struct V_42 * V_43 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
return F_22 ( V_10 , V_43 , 1 ) ;
}
static int F_35 ( struct V_18 * V_18 , void * V_125 ,
struct V_42 * V_43 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
if ( V_10 -> V_16 )
return - V_23 ;
return F_22 ( V_10 , V_43 , 0 ) ;
}
static int F_36 ( struct V_18 * V_18 , void * V_125 ,
struct V_142 * V_143 )
{
struct V_19 * V_20 = V_125 ;
struct V_9 * V_10 = V_20 -> V_10 ;
int V_12 = - V_23 ;
unsigned int V_144 , V_3 ;
if ( V_10 -> V_16 )
return V_12 ;
if ( V_143 -> type != V_63 ||
V_143 -> V_145 != V_146 )
return - V_13 ;
F_7 ( & V_20 -> V_27 ) ;
for ( V_3 = 0 ; V_3 < V_20 -> V_28 ; ++ V_3 )
if ( V_20 -> V_31 [ V_3 ] . V_147 > 0 )
goto V_148;
F_7 ( & V_10 -> V_15 ) ;
if ( V_10 -> V_30 > 0 && V_20 -> V_28 == 0 ) {
F_12 ( & V_10 -> V_15 ) ;
goto V_148;
}
if ( V_20 -> V_28 > 0 )
F_19 ( V_20 -> V_31 ) ;
V_12 = - V_25 ;
V_144 = V_143 -> V_144 ;
if ( V_144 > 0 ) {
if ( V_144 < 2 )
V_144 = 2 ;
if ( V_144 > 32 )
V_144 = 32 ;
V_20 -> V_31 = F_37 ( V_144 , sizeof( struct V_1 ) ,
V_24 ) ;
if ( ! V_20 -> V_31 ) {
F_12 ( & V_10 -> V_15 ) ;
goto V_148;
}
for ( V_3 = 0 ; V_3 < V_144 ; ++ V_3 ) {
V_20 -> V_31 [ V_3 ] . V_10 = V_10 ;
V_20 -> V_31 [ V_3 ] . V_139 = V_3 ;
V_20 -> V_31 [ V_3 ] . V_4 = V_5 ;
V_20 -> V_31 [ V_3 ] . V_147 = 0 ;
}
V_10 -> V_30 = 1 ;
} else {
V_10 -> V_30 = 0 ;
}
V_20 -> V_28 = V_144 ;
F_12 ( & V_10 -> V_15 ) ;
F_12 ( & V_20 -> V_27 ) ;
memset ( V_143 , 0 , sizeof( * V_143 ) ) ;
V_143 -> V_144 = V_144 ;
V_143 -> type = V_63 ;
V_143 -> V_145 = V_146 ;
return 0 ;
V_148:
F_12 ( & V_20 -> V_27 ) ;
return V_12 ;
}
static int F_38 ( struct V_18 * V_18 , void * V_125 ,
struct V_149 * V_150 )
{
struct V_19 * V_20 = V_125 ;
int V_12 = - V_13 ;
unsigned int V_139 ;
if ( V_150 -> type != V_63 )
return V_12 ;
V_139 = V_150 -> V_139 ;
F_7 ( & V_20 -> V_27 ) ;
if ( V_139 >= V_20 -> V_28 )
goto V_148;
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
V_150 -> V_139 = V_139 ;
V_150 -> type = V_63 ;
switch ( V_20 -> V_31 [ V_139 ] . V_4 ) {
case V_151 :
V_150 -> V_14 = V_152 ;
break;
case V_153 :
V_150 -> V_14 = V_154 ;
break;
default:
V_150 -> V_14 = 0 ;
}
if ( V_20 -> V_31 [ V_139 ] . V_147 )
V_150 -> V_14 |= V_155 ;
V_150 -> V_145 = V_146 ;
V_150 -> V_156 . V_157 = V_139 * V_68 ;
V_150 -> V_158 = V_68 ;
F_12 ( & V_20 -> V_27 ) ;
return 0 ;
V_148:
F_12 ( & V_20 -> V_27 ) ;
return V_12 ;
}
static int F_39 ( struct V_18 * V_18 , void * V_125 , struct V_149 * V_150 )
{
struct V_19 * V_20 = V_125 ;
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_1 * V_2 ;
unsigned long V_14 ;
int V_12 = - V_13 ;
int V_159 ;
if ( V_150 -> type != V_63 ||
V_150 -> V_145 != V_146 )
return V_12 ;
F_7 ( & V_20 -> V_27 ) ;
if ( V_150 -> V_139 < 0 || V_150 -> V_139 >= V_20 -> V_28 )
goto V_148;
V_2 = & V_20 -> V_31 [ V_150 -> V_139 ] ;
if ( ! V_2 -> V_147 )
goto V_148;
V_12 = - V_23 ;
if ( V_2 -> V_4 != V_5 )
goto V_148;
V_2 -> V_157 = V_2 -> V_160 & ~ V_161 ;
V_2 -> V_162 = 0 ;
V_2 -> V_37 = 0 ;
V_2 -> V_163 = 0 ;
if ( V_2 -> V_157 > 0 )
V_2 -> V_7 = V_164 + 1 ;
else
V_2 -> V_7 = V_164 ;
V_12 = - V_25 ;
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
F_9 ( & V_10 -> V_17 , V_14 ) ;
F_43 ( & V_2 -> V_6 , & V_10 -> V_6 ) ;
F_10 ( & V_10 -> V_17 , V_14 ) ;
F_12 ( & V_20 -> V_27 ) ;
return 0 ;
V_148:
F_12 ( & V_20 -> V_27 ) ;
return V_12 ;
}
static int F_44 ( struct V_18 * V_18 , void * V_125 , struct V_149 * V_150 )
{
struct V_19 * V_20 = V_125 ;
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_1 * V_2 ;
int V_12 = - V_13 ;
unsigned long V_14 ;
T_1 V_168 ;
F_45 ( V_169 ) ;
if ( V_150 -> type != V_63 )
return V_12 ;
if ( V_150 -> V_145 != V_146 )
return V_12 ;
F_7 ( & V_20 -> V_27 ) ;
if ( F_46 ( & V_10 -> V_6 ) )
goto V_148;
V_2 = F_47 ( V_10 -> V_6 . V_11 ,
struct V_1 , V_6 ) ;
V_12 = - V_170 ;
if ( V_2 -> V_4 != V_153 &&
! ( V_18 -> V_171 & V_172 ) ) {
for (; ; ) {
F_48 ( & V_10 -> V_173 , & V_169 ,
V_174 ) ;
if ( V_2 -> V_4 == V_153 )
break;
if ( F_49 ( V_165 ) ) {
V_12 = - V_175 ;
break;
}
F_50 () ;
}
F_51 ( & V_10 -> V_173 , & V_169 ) ;
}
if ( V_2 -> V_4 != V_153 )
goto V_148;
F_9 ( & V_10 -> V_17 , V_14 ) ;
F_1 ( V_2 ) ;
F_10 ( & V_10 -> V_17 , V_14 ) ;
V_168 = F_20 ( V_2 , V_10 -> V_32 ) ;
V_2 -> V_4 = V_5 ;
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
V_150 -> V_139 = V_2 -> V_139 ;
V_150 -> type = V_63 ;
V_150 -> V_162 = V_2 -> V_162 ;
V_150 -> V_14 = V_155 | V_168 ;
V_150 -> V_64 = V_65 ;
V_150 -> V_176 = V_2 -> V_176 ;
V_150 -> V_177 = V_2 -> V_178 ;
V_150 -> V_145 = V_146 ;
V_150 -> V_156 . V_157 = V_2 -> V_139 * V_68 ;
V_150 -> V_158 = V_68 ;
V_150 -> V_179 = V_2 -> V_163 ;
F_12 ( & V_20 -> V_27 ) ;
return 0 ;
V_148:
F_12 ( & V_20 -> V_27 ) ;
return V_12 ;
}
static int F_52 ( struct V_18 * V_18 , void * V_125 ,
enum V_180 type )
{
struct V_19 * V_20 = V_125 ;
struct V_9 * V_10 = V_20 -> V_10 ;
int V_12 = 0 ;
if ( type != V_63 )
return - V_13 ;
F_7 ( & V_20 -> V_27 ) ;
F_7 ( & V_10 -> V_15 ) ;
if ( ! V_10 -> V_16 ) {
V_10 -> V_16 = 1 ;
V_10 -> V_181 = 0 ;
V_10 -> V_182 = NULL ;
if ( F_53 ( V_10 ) < 0 )
V_12 = - V_183 ;
else
V_12 = 0 ;
}
F_12 ( & V_10 -> V_15 ) ;
F_12 ( & V_20 -> V_27 ) ;
return V_12 ;
}
static int F_54 ( struct V_18 * V_18 , void * V_125 ,
enum V_180 type )
{
struct V_19 * V_20 = V_125 ;
struct V_9 * V_10 = V_20 -> V_10 ;
if ( type != V_63 )
return - V_13 ;
F_7 ( & V_20 -> V_27 ) ;
F_6 ( V_10 ) ;
F_12 ( & V_20 -> V_27 ) ;
return 0 ;
}
static int F_55 ( struct V_18 * V_18 , void * V_125 ,
struct V_99 * V_184 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
int V_110 = V_184 -> V_110 ;
if ( 0 == F_23 ( & V_10 -> V_83 , V_185 , V_186 , V_184 ) )
return 0 ;
V_184 -> V_110 = V_110 ;
return F_24 ( V_184 ) ;
}
static int F_56 ( struct V_18 * V_18 , void * V_125 ,
struct V_118 * V_100 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
if ( 0 == F_23 ( & V_10 -> V_83 , V_185 , V_187 , V_100 ) )
return 0 ;
return F_28 ( V_100 , V_10 ) ;
}
static int F_57 ( struct V_18 * V_18 , void * V_125 ,
struct V_118 * V_100 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
if ( 0 == F_23 ( & V_10 -> V_83 , V_185 , V_188 , V_100 ) )
return 0 ;
return F_27 ( V_100 , V_10 ) ;
}
static int F_58 ( struct V_18 * V_189 , void * V_125 ,
struct V_190 * V_191 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
struct V_192 V_193 = {
. V_194 = 1001 * V_10 -> V_195 ,
. V_196 = V_10 -> V_92 ,
} ;
if ( V_191 -> type != V_63 )
return - V_13 ;
V_191 -> V_191 . V_197 . V_198 |= V_199 ;
V_191 -> V_191 . V_197 . V_193 = V_193 ;
return 0 ;
}
static int F_59 ( struct V_18 * V_189 , void * V_125 ,
struct V_190 * V_191 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
unsigned int V_200 , V_201 ;
if ( V_191 -> type != V_63 )
return - V_13 ;
if ( V_191 -> V_191 . V_197 . V_202 != 0 )
return - V_13 ;
V_200 = V_10 -> V_92 *
V_191 -> V_191 . V_197 . V_193 . V_194 ;
V_201 = 1001 * V_191 -> V_191 . V_197 . V_193 . V_196 ;
if ( V_200 != 0 && V_201 != 0 && V_200 > V_201 )
V_10 -> V_195 = ( V_200 + V_201 / 2 ) / V_201 ;
else
V_10 -> V_195 = 1 ;
return 0 ;
}
static int F_60 ( struct V_18 * V_189 , void * V_125 ,
struct V_203 * V_204 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
if ( ( V_10 -> V_58 -> V_14 & V_135 ) ||
( V_10 -> V_58 -> V_59 & V_205 ) )
return - V_13 ;
if ( V_204 -> V_139 > 0 )
return - V_13 ;
V_204 -> type = V_206 ;
V_204 -> V_207 . V_47 = V_10 -> V_58 -> V_46 ;
V_204 -> V_207 . V_48 = V_10 -> V_58 -> V_45 ;
return 0 ;
}
static int F_61 ( struct V_18 * V_189 , void * V_125 ,
struct V_208 * V_209 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
if ( ( V_10 -> V_58 -> V_14 & V_135 ) ||
( V_10 -> V_58 -> V_59 & V_205 ) )
return - V_13 ;
if ( V_209 -> V_139 > 0 )
return - V_13 ;
V_209 -> type = V_210 ;
V_209 -> V_207 . V_194 = 1001 ;
V_209 -> V_207 . V_196 = V_10 -> V_58 -> V_92 ;
return 0 ;
}
static int F_62 ( struct V_18 * V_18 , void * V_125 , T_3 * V_211 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
switch ( V_10 -> V_54 ) {
case V_55 :
* V_211 = V_212 ;
break;
case V_56 :
* V_211 = V_213 ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static int F_63 ( struct V_18 * V_18 , void * V_125 , T_3 * V_211 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
if ( V_10 -> V_16 )
return - V_23 ;
if ( ! ( V_10 -> V_58 -> V_59 & V_205 ) && * V_211 != 0 )
return - V_13 ;
if ( * V_211 == 0 )
return - V_13 ;
if ( ( V_10 -> V_58 -> V_14 & V_135 ) &&
V_10 -> V_214 == V_10 -> V_58 -> V_215 - 1 ) {
if ( ! V_10 -> V_216 )
return - V_183 ;
if ( F_23 ( & V_10 -> V_83 , V_185 , V_217 , * V_211 ) < 0 )
return - V_13 ;
}
if ( * V_211 & V_212 ) {
V_10 -> V_54 = V_55 ;
V_10 -> V_92 = 30000 ;
} else if ( * V_211 & V_213 ) {
V_10 -> V_54 = V_56 ;
V_10 -> V_92 = 25025 ;
} else if ( * V_211 & V_218 ) {
V_10 -> V_54 = V_56 ;
V_10 -> V_92 = 25025 ;
} else
return - V_13 ;
F_23 ( & V_10 -> V_83 , V_185 , V_217 , * V_211 ) ;
F_22 ( V_10 , NULL , 0 ) ;
return 0 ;
}
static int F_64 ( struct V_18 * V_18 , void * V_125 , T_3 * V_211 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
if ( ( V_10 -> V_58 -> V_14 & V_135 ) &&
V_10 -> V_214 == V_10 -> V_58 -> V_215 - 1 ) {
if ( ! V_10 -> V_216 )
return - V_183 ;
return F_23 ( & V_10 -> V_83 , V_84 , V_219 , V_211 ) ;
} else if ( V_10 -> V_58 -> V_59 & V_205 )
* V_211 = V_212 | V_213 | V_218 ;
else
* V_211 = 0 ;
return 0 ;
}
static int F_65 ( struct V_18 * V_18 , void * V_125 ,
struct V_220 * V_221 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
if ( V_221 -> V_139 >= V_10 -> V_58 -> V_215 )
return - V_13 ;
strncpy ( V_221 -> V_130 , V_10 -> V_58 -> V_222 [ V_221 -> V_139 ] . V_130 ,
sizeof( V_221 -> V_130 ) ) ;
if ( ( V_10 -> V_58 -> V_14 & V_135 ) &&
V_221 -> V_139 == V_10 -> V_58 -> V_215 - 1 )
V_221 -> type = V_223 ;
else
V_221 -> type = V_224 ;
V_221 -> V_225 = 0 ;
V_221 -> V_226 = 0 ;
if ( V_10 -> V_58 -> V_59 & V_205 )
V_221 -> V_211 = V_212 | V_213 |
V_218 ;
else
V_221 -> V_211 = 0 ;
return 0 ;
}
static int F_66 ( struct V_18 * V_18 , void * V_125 , unsigned int * V_214 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
* V_214 = V_10 -> V_214 ;
return 0 ;
}
static int F_67 ( struct V_18 * V_18 , void * V_125 , unsigned int V_214 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
if ( V_214 >= V_10 -> V_58 -> V_215 )
return - V_13 ;
if ( V_10 -> V_16 )
return - V_23 ;
V_10 -> V_214 = V_214 ;
return F_23 ( & V_10 -> V_83 , V_84 , V_227 , V_214 , 0 , 0 ) ;
}
static int F_68 ( struct V_18 * V_18 , void * V_125 ,
struct V_228 * V_229 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
if ( ! ( V_10 -> V_58 -> V_14 & V_135 ) )
return - V_13 ;
if ( V_229 -> V_139 != 0 )
return - V_13 ;
if ( ! V_10 -> V_216 )
return - V_183 ;
return F_23 ( & V_10 -> V_83 , V_226 , V_230 , V_229 ) ;
}
static int F_69 ( struct V_18 * V_18 , void * V_125 ,
struct V_228 * V_229 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
if ( ! ( V_10 -> V_58 -> V_14 & V_135 ) )
return - V_13 ;
if ( V_229 -> V_139 != 0 )
return - V_13 ;
if ( ! V_10 -> V_216 )
return - V_183 ;
switch ( V_10 -> V_231 ) {
case V_232 :
case V_233 :
if ( V_229 -> V_234 != V_235 )
return - V_13 ;
break;
}
return F_23 ( & V_10 -> V_83 , V_226 , V_236 , V_229 ) ;
}
static int F_70 ( struct V_18 * V_18 , void * V_125 ,
struct V_237 * V_33 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
if ( ! ( V_10 -> V_58 -> V_14 & V_135 ) )
return - V_13 ;
if ( ! V_10 -> V_216 )
return - V_183 ;
V_33 -> type = V_238 ;
return F_23 ( & V_10 -> V_83 , V_226 , V_239 , V_33 ) ;
}
static int F_71 ( struct V_18 * V_18 , void * V_125 ,
struct V_237 * V_33 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
if ( ! ( V_10 -> V_58 -> V_14 & V_135 ) )
return - V_13 ;
if ( ! V_10 -> V_216 )
return - V_183 ;
return F_23 ( & V_10 -> V_83 , V_226 , V_240 , V_33 ) ;
}
static int F_72 ( struct V_18 * V_18 , void * V_125 ,
struct V_241 * V_242 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
if ( V_242 -> type != V_63 )
return - V_13 ;
switch ( V_10 -> V_54 ) {
case V_55 :
V_242 -> V_243 . V_244 = 0 ;
V_242 -> V_243 . V_245 = 0 ;
V_242 -> V_243 . V_47 = 720 ;
V_242 -> V_243 . V_48 = 480 ;
V_242 -> V_246 . V_244 = 0 ;
V_242 -> V_246 . V_245 = 0 ;
V_242 -> V_246 . V_47 = 720 ;
V_242 -> V_246 . V_48 = 480 ;
break;
case V_56 :
V_242 -> V_243 . V_244 = 0 ;
V_242 -> V_243 . V_245 = 0 ;
V_242 -> V_243 . V_47 = 720 ;
V_242 -> V_243 . V_48 = 576 ;
V_242 -> V_246 . V_244 = 0 ;
V_242 -> V_246 . V_245 = 0 ;
V_242 -> V_246 . V_47 = 720 ;
V_242 -> V_246 . V_48 = 576 ;
break;
case V_57 :
V_242 -> V_243 . V_244 = 0 ;
V_242 -> V_243 . V_245 = 0 ;
V_242 -> V_243 . V_47 = V_10 -> V_58 -> V_46 ;
V_242 -> V_243 . V_48 = V_10 -> V_58 -> V_45 ;
V_242 -> V_246 . V_244 = 0 ;
V_242 -> V_246 . V_245 = 0 ;
V_242 -> V_246 . V_47 = V_10 -> V_58 -> V_46 ;
V_242 -> V_246 . V_48 = V_10 -> V_58 -> V_45 ;
break;
}
return 0 ;
}
static int F_73 ( struct V_18 * V_18 , void * V_125 , struct V_247 * V_248 )
{
struct V_9 * V_10 = ( (struct V_19 * ) V_125 ) -> V_10 ;
if ( V_248 -> type != V_63 )
return - V_13 ;
V_248 -> type = V_63 ;
switch ( V_10 -> V_54 ) {
case V_55 :
V_248 -> V_249 . V_244 = 0 ;
V_248 -> V_249 . V_245 = 0 ;
V_248 -> V_249 . V_47 = 720 ;
V_248 -> V_249 . V_48 = 480 ;
break;
case V_56 :
V_248 -> V_249 . V_244 = 0 ;
V_248 -> V_249 . V_245 = 0 ;
V_248 -> V_249 . V_47 = 720 ;
V_248 -> V_249 . V_48 = 576 ;
break;
case V_57 :
V_248 -> V_249 . V_244 = 0 ;
V_248 -> V_249 . V_245 = 0 ;
V_248 -> V_249 . V_47 = V_10 -> V_58 -> V_46 ;
V_248 -> V_249 . V_48 = V_10 -> V_58 -> V_45 ;
break;
}
return 0 ;
}
static int F_74 ( struct V_18 * V_18 , void * V_125 , struct V_247 * V_248 )
{
if ( V_248 -> type != V_63 )
return - V_13 ;
return 0 ;
}
static int F_75 ( struct V_18 * V_18 , void * V_125 ,
struct V_250 * V_251 )
{
memset ( V_251 , 0 , sizeof( * V_251 ) ) ;
V_251 -> V_252 = 50 ;
V_251 -> V_253 = V_254 |
V_255 ;
return 0 ;
}
static int F_76 ( struct V_18 * V_18 , void * V_125 ,
struct V_250 * V_251 )
{
if ( V_251 -> V_252 != 50 ||
V_251 -> V_253 != ( V_254 |
V_255 ) )
return - V_13 ;
return 0 ;
}
static T_4 F_77 ( struct V_18 * V_18 , char T_5 * V_256 ,
T_6 V_144 , T_7 * V_257 )
{
return - V_13 ;
}
static void F_78 ( struct V_258 * V_259 )
{
struct V_1 * V_2 = V_259 -> V_260 ;
++ V_2 -> V_147 ;
}
static void F_79 ( struct V_258 * V_259 )
{
struct V_1 * V_2 = V_259 -> V_260 ;
unsigned long V_14 ;
if ( -- V_2 -> V_147 == 0 ) {
F_9 ( & V_2 -> V_10 -> V_17 , V_14 ) ;
F_1 ( V_2 ) ;
F_10 ( & V_2 -> V_10 -> V_17 , V_14 ) ;
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
static int F_83 ( struct V_18 * V_18 , struct V_258 * V_259 )
{
struct V_19 * V_20 = V_18 -> V_29 ;
unsigned int V_139 ;
if ( V_20 -> V_10 -> V_21 != V_22 )
return - V_183 ;
if ( ! ( V_259 -> V_268 & V_269 ) )
return - V_13 ;
if ( V_259 -> V_270 - V_259 -> V_271 != V_68 )
return - V_13 ;
F_7 ( & V_20 -> V_27 ) ;
V_139 = V_259 -> V_272 / V_164 ;
if ( V_139 >= V_20 -> V_28 ) {
F_12 ( & V_20 -> V_27 ) ;
return - V_13 ;
}
if ( V_139 * V_164 != V_259 -> V_272 ) {
F_12 ( & V_20 -> V_27 ) ;
return - V_13 ;
}
if ( V_20 -> V_31 [ V_139 ] . V_147 > 0 ) {
F_12 ( & V_20 -> V_27 ) ;
return - V_23 ;
}
V_20 -> V_31 [ V_139 ] . V_147 = 1 ;
V_20 -> V_31 [ V_139 ] . V_160 = V_259 -> V_271 ;
V_259 -> V_273 = & V_274 ;
V_259 -> V_268 |= V_275 ;
V_259 -> V_268 &= ~ V_276 ;
V_259 -> V_260 = & V_20 -> V_31 [ V_139 ] ;
F_12 ( & V_20 -> V_27 ) ;
return 0 ;
}
static unsigned int F_84 ( struct V_18 * V_18 , T_8 * V_169 )
{
struct V_19 * V_20 = V_18 -> V_29 ;
struct V_1 * V_2 ;
if ( F_46 ( & V_20 -> V_10 -> V_6 ) )
return V_277 ;
V_2 = F_47 ( V_20 -> V_10 -> V_6 . V_11 , struct V_1 , V_6 ) ;
F_85 ( V_18 , & V_20 -> V_10 -> V_173 , V_169 ) ;
if ( V_2 -> V_4 == V_153 )
return V_278 | V_279 ;
return 0 ;
}
static void F_86 ( struct V_280 * V_281 )
{
struct V_9 * V_10 = F_14 ( V_281 ) ;
F_87 ( V_281 ) ;
if ( -- V_10 -> V_26 == 0 )
F_19 ( V_10 ) ;
}
int F_88 ( struct V_9 * V_10 )
{
int V_282 ;
V_10 -> V_283 = F_89 () ;
if ( V_10 -> V_283 == NULL )
return - V_25 ;
* V_10 -> V_283 = V_284 ;
V_10 -> V_283 -> V_285 = V_10 -> V_286 ;
V_282 = F_90 ( V_10 -> V_283 , V_287 , - 1 ) ;
if ( V_282 < 0 ) {
F_87 ( V_10 -> V_283 ) ;
V_10 -> V_283 = NULL ;
return V_282 ;
}
V_282 = F_91 ( V_10 -> V_286 , & V_10 -> V_83 ) ;
if ( V_282 < 0 ) {
F_87 ( V_10 -> V_283 ) ;
V_10 -> V_283 = NULL ;
return V_282 ;
}
F_92 ( V_10 -> V_283 , V_10 ) ;
++ V_10 -> V_26 ;
F_93 ( V_288 L_4 ,
V_10 -> V_283 -> V_130 , F_94 ( V_10 -> V_283 ) ) ;
return 0 ;
}
void F_95 ( struct V_9 * V_10 )
{
unsigned long V_14 ;
F_7 ( & V_10 -> V_15 ) ;
if ( V_10 -> V_16 ) {
V_10 -> V_16 = 0 ;
F_8 ( V_10 ) ;
F_9 ( & V_10 -> V_17 , V_14 ) ;
F_4 ( V_10 ) ;
F_10 ( & V_10 -> V_17 , V_14 ) ;
}
F_12 ( & V_10 -> V_15 ) ;
if ( V_10 -> V_283 )
F_96 ( V_10 -> V_283 ) ;
F_97 ( & V_10 -> V_83 ) ;
}
