static enum V_1 F_1 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_4 ) {
case V_5 :
return V_6 [ V_3 -> V_7 ] ;
case V_8 :
return V_9 [ V_3 -> V_7 ] ;
case V_10 :
return V_11 ;
default:
return V_12 ;
}
}
static enum V_1 F_2 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_4 ) {
case V_5 :
return V_6 [ V_3 -> V_7 ] ;
case V_8 :
return V_9 [ V_3 -> V_7 ] ;
case V_10 :
return V_11 ;
default:
return V_12 ;
}
}
int F_3 ( struct V_2 * V_3 , int * V_13 )
{
if ( ! V_3 -> V_14 )
return - V_15 ;
* V_13 = ! F_4 ( ( V_16 * ) V_3 -> V_14
+ V_17 ) ;
return 0 ;
}
void F_5 ( struct V_2 * V_3 , T_1 * V_18 )
{
struct V_19 * V_20 ;
int V_21 , V_13 ;
V_20 = F_6 ( V_3 ) ;
if ( V_20 -> V_22 )
V_20 -> V_22 ( V_20 , V_18 ) ;
else
* V_18 = 0 ;
V_21 = F_3 ( V_3 , & V_13 ) ;
if ( ! V_21 )
* V_18 = * V_18 && V_13 ;
V_3 -> V_23 = * V_18 ;
}
int F_7 ( struct V_2 * V_3 ,
V_16 * V_24 , T_2 * V_25 , V_16 * V_26 )
{
struct V_19 * V_20 ;
struct V_27 V_28 ;
V_20 = F_6 ( V_3 ) ;
if ( ! V_20 -> V_29 )
return - V_15 ;
V_20 -> V_29 ( V_20 , & V_28 ) ;
if ( V_24 )
* V_24 = V_28 . V_24 ;
if ( V_25 )
* V_25 = V_28 . V_25 ;
if ( V_26 )
* V_26 = V_28 . V_26 ;
return 0 ;
}
void F_8 ( struct V_2 * V_3 , int V_25 , int V_26 )
{
int V_21 ;
struct V_19 * V_20 ;
V_20 = (struct V_19 * ) ( V_3 -> V_30 . V_31 ) ;
V_3 -> V_25 = V_25 ;
V_3 -> V_32 = ! V_26 ;
V_20 -> V_1 = F_1 ( V_3 ) ;
if ( V_20 -> V_33 ) {
V_21 = V_20 -> V_33 ( V_20 ,
(enum V_34 ) V_25 , V_26 ) ;
if ( V_21 ) {
F_9 ( V_3 -> V_35 ,
L_1 ,
V_3 -> V_36 -> V_37 . V_38 ,
V_3 -> V_39 , V_21 ) ;
return;
}
}
}
static int F_10 ( struct V_2 * V_3 ,
V_16 V_40 , V_16 * V_41 )
{
V_16 V_42 ;
T_1 V_43 ;
if ( V_3 -> V_36 -> V_44 <= V_45 ) {
if ( V_3 -> V_39 != V_46 ) {
F_9 ( V_3 -> V_35 ,
L_2 ,
V_3 -> V_36 -> V_37 . V_38 ,
V_3 -> V_39 , V_40 ) ;
return - V_47 ;
}
} else if ( V_3 -> V_36 -> V_44 < V_48 ) {
if ( V_3 -> V_39 >= V_46 ) {
F_9 ( V_3 -> V_35 ,
L_3 ,
V_3 -> V_36 -> V_37 . V_38 ,
V_3 -> V_39 , V_40 ) ;
return - V_47 ;
}
} else {
F_9 ( V_3 -> V_35 , L_4 ,
V_3 -> V_36 -> V_37 . V_38 , V_3 -> V_39 ) ;
return - V_47 ;
}
V_43 = F_11 ( V_3 -> V_39 ) ;
if ( V_40 >= V_3 -> V_36 -> V_49 [ V_43 ] -> V_50 ) {
F_9 ( V_3 -> V_35 , L_2 ,
V_3 -> V_36 -> V_37 . V_38 , V_3 -> V_39 , V_40 ) ;
return - V_47 ;
}
switch ( V_3 -> V_36 -> V_44 ) {
case V_51 :
V_42 = 0 ;
break;
case V_52 :
V_42 = 0 ;
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
V_42 = V_40 ;
break;
default:
F_9 ( V_3 -> V_35 , L_4 ,
V_3 -> V_36 -> V_37 . V_38 , V_3 -> V_39 ) ;
return - V_47 ;
}
V_42 += V_65 ;
* V_41 = V_42 ;
return 0 ;
}
int F_12 ( struct V_2 * V_3 ,
T_1 V_40 , char * V_66 )
{
int V_21 ;
struct V_19 * V_20 = F_6 ( V_3 ) ;
struct V_67 * V_36 = V_3 -> V_36 ;
struct V_68 V_69 ;
struct V_70 * V_71 ;
V_71 = & V_3 -> V_72 [ V_40 ] ;
if ( V_36 ) {
memcpy ( V_69 . V_66 , V_66 , sizeof( V_69 . V_66 ) ) ;
V_69 . V_73 = V_71 -> V_74 ;
V_69 . V_75 = V_3 -> V_39 ;
V_21 = F_10 ( V_3 , ( V_16 ) V_40 ,
& V_69 . V_41 ) ;
if ( V_21 )
return V_21 ;
if ( ( V_71 -> V_76 != 0 ) &&
( memcmp ( V_71 -> V_66 ,
V_66 , sizeof( V_69 . V_66 ) ) != 0 ) ) {
V_21 = F_13 ( V_36 ,
V_71 -> V_74 ,
V_3 -> V_39 ,
V_71 -> V_66 ) ;
if ( V_21 )
return V_21 ;
}
V_21 = F_14 ( V_36 , & V_69 ) ;
if ( V_21 )
return V_21 ;
}
if ( ( V_20 -> V_77 ) && ( V_40 == 0 ) )
V_20 -> V_77 ( V_3 -> V_30 . V_31 , V_66 ) ;
memcpy ( V_71 -> V_66 , V_66 , sizeof( V_71 -> V_66 ) ) ;
V_71 -> V_76 = 1 ;
return 0 ;
}
int F_15 ( struct V_2 * V_3 ,
T_1 V_41 , char * V_66 , bool V_78 )
{
int V_21 ;
struct V_67 * V_36 = V_3 -> V_36 ;
struct V_68 V_69 ;
if ( V_36 && V_66 ) {
memcpy ( V_69 . V_66 , V_66 , sizeof( V_69 . V_66 ) ) ;
V_69 . V_73 = 0 ;
V_69 . V_75 = V_3 -> V_39 ;
V_69 . V_41 = V_41 ;
if ( ! V_78 )
V_21 = F_16 ( V_36 , & V_69 ) ;
else
V_21 = F_17 ( V_36 , & V_69 ) ;
if ( V_21 ) {
F_9 ( V_36 -> V_35 ,
L_5 ,
V_3 -> V_36 -> V_37 . V_38 ,
V_3 -> V_39 , V_21 ) ;
return V_21 ;
}
}
return 0 ;
}
int F_18 ( struct V_2 * V_3 , T_1 V_79 , char * V_31 )
{
struct V_70 * V_80 ;
struct V_67 * V_36 ;
T_1 V_21 ;
V_36 = V_3 -> V_36 ;
if ( V_79 < V_81 ) {
V_80 = & V_3 -> V_72 [ V_79 ] ;
} else {
F_9 ( V_3 -> V_35 ,
L_6 ,
V_3 -> V_36 -> V_37 . V_38 , V_3 -> V_39 , V_79 ) ;
return - V_47 ;
}
if ( V_36 ) {
V_21 = F_13 ( V_36 , V_80 -> V_74 ,
V_3 -> V_39 , V_80 -> V_66 ) ;
if ( V_21 )
return V_21 ;
if ( memcmp ( V_80 -> V_66 , V_31 , sizeof( V_80 -> V_66 ) ) == 0 )
V_80 -> V_76 = 0 ;
}
return 0 ;
}
static void F_19 ( struct V_82 * V_83 ,
struct V_2 * V_3 )
{
V_83 -> V_84 = ( void * ) V_3 -> V_84 ;
V_83 -> V_1 = F_2 ( V_3 ) ;
memcpy ( V_83 -> V_66 , V_3 -> V_72 [ 0 ] . V_66 ,
V_85 ) ;
V_83 -> V_39 = V_3 -> V_39 ;
V_83 -> V_35 = V_3 -> V_35 ;
}
static int F_20 ( struct V_2 * V_3 ,
T_1 V_41 , T_2 V_74 , bool V_78 )
{
int V_21 ;
struct V_67 * V_36 = V_3 -> V_36 ;
V_16 V_66 [ V_85 ]
= { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_68 V_69 ;
if ( V_3 -> V_86 == V_87 )
return 0 ;
if ( V_36 ) {
memcpy ( V_69 . V_66 , V_66 , sizeof( V_69 . V_66 ) ) ;
V_69 . V_73 = V_74 ;
V_69 . V_75 = V_3 -> V_39 ;
V_69 . V_41 = V_41 ;
if ( ! V_78 )
V_21 = F_16 ( V_36 , & V_69 ) ;
else
V_21 = F_17 ( V_36 , & V_69 ) ;
return V_21 ;
}
return 0 ;
}
int F_21 ( struct V_2 * V_3 , T_1 V_40 , bool V_78 )
{
int V_21 ;
struct V_67 * V_36 = V_3 -> V_36 ;
V_16 V_41 ;
V_16 V_66 [ V_85 ]
= { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_70 * V_88 ;
struct V_68 V_69 ;
if ( V_3 -> V_86 == V_87 )
return 0 ;
V_88 = & V_3 -> V_72 [ V_40 ] ;
if ( V_36 ) {
memcpy ( V_69 . V_66 , V_66 , sizeof( V_69 . V_66 ) ) ;
V_69 . V_73 = V_88 -> V_74 ;
V_69 . V_75 = V_3 -> V_39 ;
V_21 = F_10 ( V_3 , V_40 , & V_41 ) ;
if ( V_21 )
return V_21 ;
V_69 . V_41 = V_41 ;
if ( ! V_78 )
V_21 = F_16 ( V_36 , & V_69 ) ;
else
V_21 = F_17 ( V_36 , & V_69 ) ;
return V_21 ;
}
return 0 ;
}
void F_22 ( struct V_2 * V_3 )
{
struct V_19 * V_89 ;
V_89 = F_6 ( V_3 ) ;
V_89 -> V_90 ( V_89 ) ;
if ( V_89 -> V_91 )
V_89 -> V_91 ( V_89 , V_3 -> V_92 ) ;
if ( V_89 -> V_93 )
V_89 -> V_93 ( V_89 , V_3 -> V_94 ) ;
if ( V_89 -> V_95 )
V_89 -> V_95 ( V_89 , 1 ) ;
if ( V_89 -> V_96 ) {
if ( V_3 -> V_86 == V_87 )
V_89 -> V_96 ( V_89 , 0 , 0 ) ;
else
V_89 -> V_96 ( V_89 , 0 , 1 ) ;
}
}
int F_23 ( struct V_2 * V_3 , T_1 V_97 )
{
struct V_19 * V_89 = F_6 ( V_3 ) ;
T_1 V_98 = V_3 -> V_36 -> V_98 ;
T_1 V_99 = V_97 + V_100 + V_101 + V_102 ;
if ( ( V_97 < V_103 ) || ( V_99 > V_104 ) ||
( V_99 > V_105 * V_98 ) )
return - V_47 ;
if ( ! V_89 -> V_91 )
return - V_106 ;
if ( V_99 < ( V_107 + V_101 + V_102 ) )
V_99 = ( V_107 + V_101 + V_102 ) ;
V_89 -> V_91 ( V_89 , V_99 ) ;
V_3 -> V_92 = V_99 ;
return 0 ;
}
void F_24 ( struct V_2 * V_3 )
{
struct V_19 * V_108 = F_6 ( V_3 ) ;
if ( V_108 -> V_109 == V_110 ) {
V_108 -> V_111 += 1 ;
return;
}
if ( V_108 -> V_112 ) {
V_108 -> V_112 ( V_3 -> V_30 . V_31 , V_113 ) ;
V_108 -> V_109 = V_110 ;
}
}
void F_25 ( struct V_2 * V_3 )
{
struct V_19 * V_20 = F_6 ( V_3 ) ;
if ( V_20 -> V_111 > 0 ) {
V_20 -> V_111 -= 1 ;
if ( V_20 -> V_111 > 0 )
return;
}
if ( V_20 -> V_114 )
V_20 -> V_114 ( V_3 -> V_30 . V_31 ,
V_113 ) ;
V_20 -> V_109 = 0 ;
V_3 -> V_23 = 0 ;
F_26 ( V_3 ) ;
}
void F_27 ( struct V_2 * V_3 , T_1 * V_24 )
{
struct V_19 * V_20 = F_6 ( V_3 ) ;
if ( V_20 -> V_115 )
V_20 -> V_115 ( V_20 , V_24 ) ;
else
* V_24 = 0 ;
}
void F_28 ( struct V_2 * V_3 , T_1 * V_116 , T_1 * V_117 )
{
struct V_19 * V_20 = F_6 ( V_3 ) ;
if ( V_20 -> V_118 ) {
V_20 -> V_118 ( V_20 , V_116 , V_117 ) ;
} else {
* V_116 = 0 ;
* V_117 = 0 ;
}
if ( V_3 -> V_86 == V_119 )
* V_116 = 1 ;
}
int F_29 ( struct V_2 * V_3 , V_16 V_78 )
{
struct V_19 * V_20 = F_6 ( V_3 ) ;
if ( V_3 -> V_7 == V_120 && V_78 ) {
F_9 ( V_3 -> V_35 , L_7 ) ;
return - V_121 ;
}
if ( V_20 -> V_95 )
V_20 -> V_95 ( V_20 , V_78 ) ;
return 0 ;
}
int F_30 ( struct V_2 * V_3 , T_1 V_116 , T_1 V_117 )
{
struct V_19 * V_20 = F_6 ( V_3 ) ;
if ( V_3 -> V_86 == V_119 ) {
if ( ! V_116 ) {
F_9 ( V_3 -> V_35 , L_8 ) ;
return - V_47 ;
}
} else if ( V_3 -> V_86 == V_87 ) {
if ( V_117 || V_116 ) {
F_9 ( V_3 -> V_35 , L_9 ) ;
return - V_47 ;
}
} else {
F_9 ( V_3 -> V_35 , L_10 ) ;
return - V_47 ;
}
if ( V_20 -> V_96 )
V_20 -> V_96 ( V_20 , V_116 , V_117 ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 )
{
int V_21 ;
struct V_82 V_83 ;
struct V_19 * V_89 ;
F_32 ( V_3 ) ;
memset ( & V_83 , 0 , sizeof( struct V_82 ) ) ;
F_19 ( & V_83 , V_3 ) ;
if ( F_33 ( V_83 . V_1 ) < V_10 )
V_89 = (struct V_19 * ) F_34 ( V_3 , & V_83 ) ;
else
V_89 = (struct V_19 * ) F_35 ( V_3 , & V_83 ) ;
if ( ! V_89 )
return - V_122 ;
V_3 -> V_30 . V_31 = ( void * ) V_89 ;
F_22 ( V_3 ) ;
F_8 ( V_3 , V_3 -> V_25 , ! V_3 -> V_32 ) ;
V_21 = F_20 ( V_3 , V_3 -> V_39 , 0 , true ) ;
if ( V_21 )
goto V_123;
return 0 ;
V_123:
V_89 -> V_124 ( V_3 -> V_30 . V_31 ) ;
V_3 -> V_30 . V_31 = NULL ;
return V_21 ;
}
static void F_36 ( struct V_2 * V_3 ,
struct V_125 * V_126 , T_1 V_127 )
{
V_3 -> V_23 = false ;
V_3 -> V_32 = false ;
V_3 -> V_25 = V_128 [ V_3 -> V_7 ] ;
V_3 -> V_4 = V_3 -> V_25 ;
if ( V_3 -> V_7 == V_129 ) {
V_3 -> V_130 = V_131 ;
V_3 -> V_130 |= V_132 ;
} else if ( V_3 -> V_7 == V_120 ) {
V_3 -> V_130 = V_133 ;
V_3 -> V_130 |= V_134 ;
}
V_3 -> V_92 = V_135 ;
V_3 -> V_94 = V_136 ;
V_3 -> V_137 = F_37 ( V_126 , L_11 , V_3 -> V_39 ) ;
if ( V_3 -> V_137 )
F_38 ( V_3 -> V_35 , L_12 ,
V_3 -> V_39 , V_3 -> V_137 -> V_38 ) ;
}
static int F_39 ( T_3 V_7 )
{
switch ( V_7 ) {
case V_129 :
return V_138 ;
case V_120 :
return V_139 ;
default:
return - V_47 ;
}
}
V_16 T_4 * F_40 ( struct V_67 * V_36 ,
struct V_2 * V_3 , T_1 V_127 )
{
V_16 T_4 * V_140 = V_36 -> V_141 ;
int V_39 = V_3 -> V_39 ;
if ( V_3 -> V_86 == V_119 )
return V_140 + 0x40000 + V_39 * 0x4000 -
V_127 * 0x20000 ;
else
return V_3 -> V_142 + 0x1000
+ ( V_39 - V_143 ) * 0x100000 ;
}
int F_41 ( struct V_67 * V_36 , int V_144 )
{
int V_21 ;
T_1 V_127 ;
struct V_2 * V_3 = & V_36 -> V_3 [ V_144 ] ;
V_3 -> V_36 = V_36 ;
V_3 -> V_35 = V_36 -> V_35 ;
V_3 -> V_39 = V_144 ;
V_3 -> V_145 = V_36 -> V_146 ;
V_3 -> V_142 = V_36 -> V_147 ;
if ( V_36 -> V_148 &&
V_144 < V_143 ) {
V_3 -> V_14 = V_36 -> V_148 +
V_3 -> V_39 * V_149 ;
F_26 ( V_3 ) ;
}
V_3 -> V_13 = 0 ;
V_3 -> V_150 = 0 ;
V_3 -> V_151 = 0 ;
if ( V_144 < V_143 )
V_3 -> V_86 = V_119 ;
else
V_3 -> V_86 = V_87 ;
V_3 -> V_7 = F_42 ( V_3 ) ;
V_21 = F_39 ( V_3 -> V_7 ) ;
if ( V_21 < 0 ) {
F_9 ( V_36 -> V_35 ,
L_13 ,
V_3 -> V_39 , V_21 ) ;
return V_21 ;
}
V_127 = ( T_1 ) V_21 ;
F_36 ( V_3 , V_3 -> V_35 -> V_152 , V_127 ) ;
V_3 -> V_84 = F_40 ( V_36 , V_3 , V_127 ) ;
return 0 ;
}
int F_43 ( struct V_67 * V_36 )
{
int V_153 ;
int V_21 ;
T_5 V_154 ;
struct V_2 * V_3 ;
V_154 = sizeof( struct V_2 ) * V_46 ;
V_36 -> V_3 = F_44 ( V_36 -> V_35 , V_154 , V_155 ) ;
if ( ! V_36 -> V_3 )
return - V_122 ;
for ( V_153 = 0 ; V_153 < V_46 ; V_153 ++ ) {
V_21 = F_41 ( V_36 , V_153 ) ;
if ( V_21 )
goto V_156;
V_3 = & V_36 -> V_3 [ V_153 ] ;
V_21 = F_31 ( V_3 ) ;
if ( V_21 )
goto V_156;
}
return 0 ;
V_156:
V_36 -> V_3 = NULL ;
return V_21 ;
}
void F_45 ( struct V_67 * V_36 )
{
F_26 ( V_36 -> V_3 ) ;
V_36 -> V_3 = NULL ;
}
int F_46 ( struct V_2 * V_3 ,
enum V_157 V_158 , int V_159 )
{
int V_21 ;
struct V_19 * V_89 = F_6 ( V_3 ) ;
if ( V_89 -> V_160 )
V_21 = V_89 -> V_160 ( V_89 , V_158 , V_159 ) ;
else
V_21 = - V_121 ;
return V_21 ;
}
void F_47 ( struct V_2 * V_3 )
{
struct V_19 * V_20 = F_6 ( V_3 ) ;
V_20 -> V_161 ( V_20 ) ;
}
void F_48 ( struct V_2 * V_3 , T_6 * V_162 )
{
struct V_19 * V_20 = F_6 ( V_3 ) ;
V_20 -> V_163 ( V_20 , V_162 ) ;
}
void F_49 ( struct V_2 * V_3 ,
int V_164 , V_16 * V_162 )
{
struct V_19 * V_20 = F_6 ( V_3 ) ;
V_20 -> V_165 ( V_164 , V_162 ) ;
}
int F_50 ( struct V_2 * V_3 , int V_164 )
{
struct V_19 * V_20 = F_6 ( V_3 ) ;
return V_20 -> V_166 ( V_164 ) ;
}
int F_51 ( struct V_2 * V_3 )
{
struct V_19 * V_20 = F_6 ( V_3 ) ;
return V_20 -> V_167 () ;
}
void F_52 ( struct V_2 * V_3 , void * V_162 )
{
struct V_19 * V_20 = F_6 ( V_3 ) ;
V_20 -> V_168 ( V_20 , V_162 ) ;
}
void F_53 ( struct V_2 * V_3 )
{
int V_169 = 0 ;
int V_170 , V_171 ;
V_170 = V_3 -> V_150 - V_3 -> V_172 . V_173 ;
V_171 = V_3 -> V_151 - V_3 -> V_172 . V_174 ;
if ( V_170 || V_171 )
V_169 = 1 ;
else
V_169 = 0 ;
V_3 -> V_150 = V_3 -> V_172 . V_173 ;
V_3 -> V_151 = V_3 -> V_172 . V_174 ;
F_54 ( V_3 , ( int ) V_3 -> V_23 ,
V_3 -> V_25 , V_169 ) ;
}
int F_55 ( struct V_2 * V_3 ,
enum V_175 V_176 )
{
if ( ! V_3 || ! V_3 -> V_14 )
return 0 ;
return F_56 ( V_3 , V_176 ) ;
}
