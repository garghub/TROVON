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
void F_3 ( struct V_2 * V_3 , T_1 * V_13 )
{
struct V_14 * V_15 ;
int V_16 , V_17 ;
V_15 = F_4 ( V_3 ) ;
if ( V_15 -> V_18 )
V_15 -> V_18 ( V_15 , V_13 ) ;
else
* V_13 = 0 ;
V_16 = F_5 ( V_3 , & V_17 ) ;
if ( ! V_16 )
* V_13 = * V_13 && V_17 ;
V_3 -> V_19 = * V_13 ;
}
int F_6 ( struct V_2 * V_3 ,
T_2 * V_20 , T_3 * V_21 , T_2 * V_22 )
{
struct V_14 * V_15 ;
struct V_23 V_24 ;
V_15 = F_4 ( V_3 ) ;
if ( ! V_15 -> V_25 )
return - V_26 ;
V_15 -> V_25 ( V_15 , & V_24 ) ;
if ( V_20 )
* V_20 = V_24 . V_20 ;
if ( V_21 )
* V_21 = V_24 . V_21 ;
if ( V_22 )
* V_22 = V_24 . V_22 ;
return 0 ;
}
void F_7 ( struct V_2 * V_3 , int V_21 , int V_22 )
{
int V_16 ;
struct V_14 * V_15 ;
V_15 = (struct V_14 * ) ( V_3 -> V_27 . V_28 ) ;
V_3 -> V_21 = V_21 ;
V_3 -> V_29 = ! V_22 ;
V_15 -> V_1 = F_1 ( V_3 ) ;
if ( V_15 -> V_30 ) {
V_16 = V_15 -> V_30 ( V_15 ,
(enum V_31 ) V_21 , V_22 ) ;
if ( V_16 ) {
F_8 ( V_3 -> V_32 ,
L_1 ,
V_3 -> V_33 -> V_34 . V_35 ,
V_3 -> V_36 , V_16 ) ;
return;
}
}
}
static int F_9 ( struct V_2 * V_3 ,
T_2 V_37 , T_2 * V_38 )
{
T_2 V_39 ;
if ( V_3 -> V_33 -> V_40 <= V_41 ) {
if ( V_3 -> V_36 != V_42 ) {
F_8 ( V_3 -> V_32 ,
L_2 ,
V_3 -> V_33 -> V_34 . V_35 ,
V_3 -> V_36 , V_37 ) ;
return - V_43 ;
}
} else if ( V_3 -> V_33 -> V_40 < V_44 ) {
if ( V_3 -> V_36 >= V_42 ) {
F_8 ( V_3 -> V_32 ,
L_3 ,
V_3 -> V_33 -> V_34 . V_35 ,
V_3 -> V_36 , V_37 ) ;
return - V_43 ;
}
} else {
F_8 ( V_3 -> V_32 , L_4 ,
V_3 -> V_33 -> V_34 . V_35 , V_3 -> V_36 ) ;
return - V_43 ;
}
if ( V_37 >= V_3 -> V_33 -> V_45 [ 0 ] -> V_46 ) {
F_8 ( V_3 -> V_32 , L_2 ,
V_3 -> V_33 -> V_34 . V_35 , V_3 -> V_36 , V_37 ) ;
return - V_43 ;
}
switch ( V_3 -> V_33 -> V_40 ) {
case V_47 :
V_39 = 0 ;
break;
case V_48 :
V_39 = 0 ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
V_39 = V_37 ;
break;
default:
F_8 ( V_3 -> V_32 , L_4 ,
V_3 -> V_33 -> V_34 . V_35 , V_3 -> V_36 ) ;
return - V_43 ;
}
V_39 += V_61 ;
* V_38 = V_39 ;
return 0 ;
}
int F_10 ( struct V_2 * V_3 ,
T_1 V_37 , char * V_62 )
{
int V_16 ;
struct V_14 * V_15 = F_4 ( V_3 ) ;
struct V_63 * V_33 = V_3 -> V_33 ;
struct V_64 V_65 ;
struct V_66 * V_67 ;
V_67 = & V_3 -> V_68 [ V_37 ] ;
if ( ! F_11 ( V_33 ) ) {
memcpy ( V_65 . V_62 , V_62 , sizeof( V_65 . V_62 ) ) ;
V_65 . V_69 = V_67 -> V_70 ;
V_65 . V_71 = V_3 -> V_36 ;
V_16 = F_9 ( V_3 , ( T_2 ) V_37 ,
& V_65 . V_38 ) ;
if ( V_16 )
return V_16 ;
if ( ( V_67 -> V_72 != 0 ) &&
( memcmp ( V_67 -> V_62 ,
V_62 , sizeof( V_65 . V_62 ) ) != 0 ) ) {
V_16 = F_12 ( V_33 ,
V_67 -> V_70 ,
V_3 -> V_36 ,
V_67 -> V_62 ) ;
if ( V_16 )
return V_16 ;
}
V_16 = F_13 ( V_33 , & V_65 ) ;
if ( V_16 )
return V_16 ;
}
if ( ( V_15 -> V_73 ) && ( V_37 == 0 ) )
V_15 -> V_73 ( V_3 -> V_27 . V_28 , V_62 ) ;
memcpy ( V_67 -> V_62 , V_62 , sizeof( V_67 -> V_62 ) ) ;
V_67 -> V_72 = 1 ;
return 0 ;
}
int F_14 ( struct V_2 * V_3 ,
T_1 V_38 , char * V_62 , bool V_74 )
{
int V_16 ;
struct V_63 * V_33 = V_3 -> V_33 ;
struct V_64 V_65 ;
if ( ! F_11 ( V_33 ) && V_62 ) {
memcpy ( V_65 . V_62 , V_62 , sizeof( V_65 . V_62 ) ) ;
V_65 . V_69 = 0 ;
V_65 . V_71 = V_3 -> V_36 ;
V_65 . V_38 = V_38 ;
if ( ! V_74 )
V_16 = F_15 ( V_33 , & V_65 ) ;
else
V_16 = F_16 ( V_33 , & V_65 ) ;
if ( V_16 ) {
F_8 ( V_33 -> V_32 ,
L_5 ,
V_3 -> V_33 -> V_34 . V_35 ,
V_3 -> V_36 , V_16 ) ;
return V_16 ;
}
}
return 0 ;
}
int F_17 ( struct V_2 * V_3 , T_1 V_75 , char * V_28 )
{
struct V_66 * V_76 ;
struct V_63 * V_33 ;
T_1 V_16 ;
V_33 = V_3 -> V_33 ;
if ( V_75 < V_77 ) {
V_76 = & V_3 -> V_68 [ V_75 ] ;
} else {
F_8 ( V_3 -> V_32 ,
L_6 ,
V_3 -> V_33 -> V_34 . V_35 , V_3 -> V_36 , V_75 ) ;
return - V_43 ;
}
if ( V_33 ) {
V_16 = F_12 ( V_33 , V_76 -> V_70 ,
V_3 -> V_36 , V_76 -> V_62 ) ;
if ( V_16 )
return V_16 ;
if ( memcmp ( V_76 -> V_62 , V_28 , sizeof( V_76 -> V_62 ) ) == 0 )
V_76 -> V_72 = 0 ;
}
return 0 ;
}
static void F_18 ( struct V_78 * V_79 ,
struct V_2 * V_3 )
{
V_79 -> V_80 = ( void * ) V_3 -> V_80 ;
V_79 -> V_1 = F_2 ( V_3 ) ;
memcpy ( V_79 -> V_62 , V_3 -> V_68 [ 0 ] . V_62 ,
V_81 ) ;
V_79 -> V_36 = V_3 -> V_36 ;
V_79 -> V_32 = V_3 -> V_32 ;
}
static int F_19 ( struct V_2 * V_3 ,
T_1 V_38 , T_3 V_70 , bool V_74 )
{
int V_16 ;
struct V_63 * V_33 = V_3 -> V_33 ;
T_2 V_62 [ V_81 ]
= { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_64 V_65 ;
if ( V_3 -> V_82 == V_83 )
return 0 ;
if ( ! F_11 ( V_33 ) ) {
memcpy ( V_65 . V_62 , V_62 , sizeof( V_65 . V_62 ) ) ;
V_65 . V_69 = V_70 ;
V_65 . V_71 = V_3 -> V_36 ;
V_65 . V_38 = V_38 ;
if ( ! V_74 )
V_16 = F_15 ( V_33 , & V_65 ) ;
else
V_16 = F_16 ( V_33 , & V_65 ) ;
return V_16 ;
}
return 0 ;
}
int F_20 ( struct V_2 * V_3 , T_1 V_37 , bool V_74 )
{
int V_16 ;
struct V_63 * V_33 = V_3 -> V_33 ;
T_2 V_38 ;
T_2 V_62 [ V_81 ]
= { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_66 * V_84 ;
struct V_64 V_65 ;
if ( V_3 -> V_82 == V_83 )
return 0 ;
V_84 = & V_3 -> V_68 [ V_37 ] ;
if ( ! F_11 ( V_33 ) ) {
memcpy ( V_65 . V_62 , V_62 , sizeof( V_65 . V_62 ) ) ;
V_65 . V_69 = V_84 -> V_70 ;
V_65 . V_71 = V_3 -> V_36 ;
V_16 = F_9 ( V_3 , V_37 , & V_38 ) ;
if ( V_16 )
return V_16 ;
V_65 . V_38 = V_38 ;
if ( ! V_74 )
V_16 = F_15 ( V_33 , & V_65 ) ;
else
V_16 = F_16 ( V_33 , & V_65 ) ;
return V_16 ;
}
return 0 ;
}
void F_21 ( struct V_2 * V_3 )
{
struct V_14 * V_85 = F_4 ( V_3 ) ;
bool V_86 = F_22 ( V_3 -> V_33 -> V_87 ) ;
V_85 -> V_88 ( V_85 ) ;
if ( V_85 -> V_89 )
V_85 -> V_89 ( V_85 , V_3 -> V_90 ) ;
if ( V_85 -> V_91 )
V_85 -> V_91 ( V_85 , V_3 -> V_92 ) ;
if ( V_85 -> V_93 )
V_85 -> V_93 ( V_85 , 1 ) ;
if ( V_85 -> V_94 ) {
if ( V_3 -> V_82 == V_83 )
V_85 -> V_94 ( V_85 , ! V_86 , ! V_86 ) ;
else
V_85 -> V_94 ( V_85 , 0 , 1 ) ;
}
}
int F_23 ( struct V_2 * V_3 , T_1 V_95 )
{
struct V_14 * V_85 = F_4 ( V_3 ) ;
T_1 V_96 = V_3 -> V_33 -> V_96 ;
T_1 V_97 = V_95 + V_98 + V_99 + V_100 ;
T_1 V_90 = F_22 ( V_3 -> V_33 -> V_87 ) ?
V_101 : V_102 ;
if ( V_3 -> V_82 == V_83 )
V_90 = V_103 ;
if ( ( V_95 < V_104 ) || ( V_97 > V_90 ) ||
( V_97 > V_105 * V_96 ) )
return - V_43 ;
if ( ! V_85 -> V_89 )
return - V_106 ;
if ( V_97 < ( V_107 + V_99 + V_100 ) )
V_97 = ( V_107 + V_99 + V_100 ) ;
V_85 -> V_89 ( V_85 , V_97 ) ;
V_3 -> V_90 = V_97 ;
return 0 ;
}
void F_24 ( struct V_2 * V_3 )
{
struct V_14 * V_108 = F_4 ( V_3 ) ;
if ( V_108 -> V_109 == V_110 ) {
V_108 -> V_111 += 1 ;
return;
}
if ( V_108 -> V_112 ) {
V_108 -> V_112 ( V_3 -> V_27 . V_28 , V_113 ) ;
V_108 -> V_109 = V_110 ;
}
}
void F_25 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_4 ( V_3 ) ;
if ( V_15 -> V_111 > 0 ) {
V_15 -> V_111 -= 1 ;
if ( V_15 -> V_111 > 0 )
return;
}
if ( V_15 -> V_114 )
V_15 -> V_114 ( V_3 -> V_27 . V_28 ,
V_113 ) ;
V_15 -> V_109 = 0 ;
V_3 -> V_19 = 0 ;
F_26 ( V_3 ) ;
}
void F_27 ( struct V_2 * V_3 , T_1 * V_20 )
{
struct V_14 * V_15 = F_4 ( V_3 ) ;
if ( V_15 -> V_115 )
V_15 -> V_115 ( V_15 , V_20 ) ;
else
* V_20 = 0 ;
}
void F_28 ( struct V_2 * V_3 , T_1 * V_116 , T_1 * V_117 )
{
struct V_14 * V_15 = F_4 ( V_3 ) ;
if ( V_15 -> V_118 ) {
V_15 -> V_118 ( V_15 , V_116 , V_117 ) ;
} else {
* V_116 = 0 ;
* V_117 = 0 ;
}
}
int F_29 ( struct V_2 * V_3 , T_2 V_74 )
{
struct V_14 * V_15 = F_4 ( V_3 ) ;
if ( V_3 -> V_7 == V_119 && V_74 ) {
F_8 ( V_3 -> V_32 , L_7 ) ;
return - V_120 ;
}
if ( V_15 -> V_93 )
V_15 -> V_93 ( V_15 , V_74 ) ;
return 0 ;
}
int F_30 ( struct V_2 * V_3 , T_1 V_116 , T_1 V_117 )
{
struct V_14 * V_15 = F_4 ( V_3 ) ;
bool V_86 = F_22 ( V_3 -> V_33 -> V_87 ) ;
if ( V_3 -> V_82 == V_83 ) {
if ( V_86 && ( V_117 || V_116 ) ) {
F_8 ( V_3 -> V_32 , L_8 ) ;
return - V_43 ;
}
}
if ( V_15 -> V_94 )
V_15 -> V_94 ( V_15 , V_116 , V_117 ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 )
{
int V_16 ;
struct V_78 V_79 ;
struct V_14 * V_85 ;
F_32 ( V_3 ) ;
memset ( & V_79 , 0 , sizeof( struct V_78 ) ) ;
F_18 ( & V_79 , V_3 ) ;
if ( F_33 ( V_79 . V_1 ) < V_10 )
V_85 = (struct V_14 * ) F_34 ( V_3 , & V_79 ) ;
else
V_85 = (struct V_14 * ) F_35 ( V_3 , & V_79 ) ;
if ( ! V_85 )
return - V_121 ;
V_3 -> V_27 . V_28 = ( void * ) V_85 ;
F_21 ( V_3 ) ;
F_7 ( V_3 , V_3 -> V_21 , ! V_3 -> V_29 ) ;
V_16 = F_19 ( V_3 , V_3 -> V_36 , 0 , true ) ;
if ( V_16 )
goto V_122;
return 0 ;
V_122:
V_85 -> V_123 ( V_3 -> V_27 . V_28 ) ;
V_3 -> V_27 . V_28 = NULL ;
return V_16 ;
}
static int F_36 ( struct V_2 * V_3 )
{
struct V_124 * V_125 = V_3 -> V_32 -> V_126 ;
struct V_127 * V_128 ;
struct V_129 V_130 ;
T_1 V_16 ;
V_3 -> V_19 = false ;
V_3 -> V_29 = false ;
V_3 -> V_21 = V_131 [ V_3 -> V_7 ] ;
V_3 -> V_4 = V_3 -> V_21 ;
if ( V_3 -> V_7 == V_132 ) {
V_3 -> V_133 = V_134 ;
V_3 -> V_133 |= V_135 ;
} else if ( V_3 -> V_7 == V_119 ) {
V_3 -> V_133 = V_136 ;
V_3 -> V_133 |= V_137 ;
}
V_3 -> V_90 = V_138 ;
V_3 -> V_92 = V_139 ;
V_3 -> V_140 = V_3 -> V_36 ;
V_3 -> V_141 = 0 ;
if ( ! V_3 -> V_142 ) {
V_3 -> V_143 = F_37 ( V_125 , L_9 ,
V_3 -> V_36 ) ;
if ( V_3 -> V_143 )
F_38 ( V_3 -> V_32 , L_10 ,
V_3 -> V_36 , V_3 -> V_143 -> V_35 ) ;
return 0 ;
}
if ( ! F_39 ( V_3 -> V_142 ) )
return - V_43 ;
V_3 -> V_143 = F_37 ( F_40 ( V_3 -> V_142 ) ,
L_9 , 0 ) ;
if ( V_3 -> V_143 )
F_38 ( V_3 -> V_32 , L_10 ,
V_3 -> V_36 , V_3 -> V_143 -> V_35 ) ;
V_128 = F_41 (
F_37 ( F_40 ( V_3 -> V_142 ) ,
L_11 , 0 ) ) ;
if ( F_42 ( V_128 ) ) {
F_8 ( V_3 -> V_32 , L_12 ) ;
return - V_43 ;
}
V_3 -> V_144 = V_128 ;
V_16 = F_43 ( V_3 -> V_142 ,
L_13 ,
& V_3 -> V_140 ) ;
if ( V_16 ) {
F_38 ( V_3 -> V_32 ,
L_14 ,
V_3 -> V_36 ) ;
}
V_16 = F_43 ( V_3 -> V_142 ,
L_15 ,
& V_3 -> V_141 ) ;
if ( V_16 ) {
F_38 ( V_3 -> V_32 ,
L_16 ,
V_3 -> V_36 ) ;
}
V_16 = F_44 ( F_40 ( V_3 -> V_142 ) ,
L_17 , 1 , 0 , & V_130 ) ;
if ( V_16 ) {
F_38 ( V_3 -> V_32 , L_18 ,
V_3 -> V_36 ) ;
V_3 -> V_145 = NULL ;
} else {
V_128 = F_41 ( V_130 . V_125 ) ;
if ( F_42 ( V_128 ) ) {
F_38 ( V_3 -> V_32 , L_19 ) ;
V_3 -> V_145 = NULL ;
} else {
V_3 -> V_145 = V_128 ;
V_3 -> V_146 = V_130 . args [ 0 ] ;
}
}
return 0 ;
}
static int F_45 ( T_4 V_7 )
{
switch ( V_7 ) {
case V_132 :
return V_147 ;
case V_119 :
return V_148 ;
default:
return - V_43 ;
}
}
T_2 T_5 * F_46 ( struct V_63 * V_33 ,
struct V_2 * V_3 , T_1 V_149 )
{
T_2 T_5 * V_150 = V_33 -> V_151 ;
int V_36 = V_3 -> V_36 ;
if ( V_3 -> V_82 == V_152 )
return V_150 + 0x40000 + V_36 * 0x4000 -
V_149 * 0x20000 ;
else
return V_33 -> V_153 + 0x1000 ;
}
int F_47 ( struct V_63 * V_33 , struct V_2 * V_3 )
{
int V_16 ;
T_1 V_149 ;
V_3 -> V_33 = V_33 ;
V_3 -> V_32 = V_33 -> V_32 ;
V_3 -> V_154 = V_33 -> V_155 ;
V_3 -> V_156 = V_33 -> V_157 ;
V_3 -> V_17 = 0 ;
V_3 -> V_158 = 0 ;
V_3 -> V_159 = 0 ;
if ( ! F_11 ( V_33 ) )
V_3 -> V_82 = V_152 ;
else
V_3 -> V_82 = V_83 ;
V_3 -> V_7 = F_48 ( V_3 ) ;
V_16 = F_45 ( V_3 -> V_7 ) ;
if ( V_16 < 0 ) {
F_8 ( V_33 -> V_32 ,
L_20 ,
V_3 -> V_36 , V_16 ) ;
return V_16 ;
}
V_149 = ( T_1 ) V_16 ;
V_16 = F_36 ( V_3 ) ;
if ( V_16 )
return V_16 ;
F_26 ( V_3 ) ;
V_3 -> V_80 = F_46 ( V_33 , V_3 , V_149 ) ;
return 0 ;
}
static int F_49 ( struct V_63 * V_33 )
{
if ( F_11 ( V_33 ) )
return 1 ;
else
return V_42 ;
}
int F_50 ( struct V_63 * V_33 )
{
bool V_160 = false ;
int V_16 ;
T_1 V_161 ;
int V_162 = F_49 ( V_33 ) ;
struct V_2 * V_3 ;
struct V_163 * V_164 ;
F_51 (dsaf_dev->dev, child) {
V_16 = F_43 ( V_164 , L_21 , & V_161 ) ;
if ( V_16 ) {
F_8 ( V_33 -> V_32 ,
L_22 , V_16 ) ;
return V_16 ;
}
if ( V_161 >= V_162 ) {
F_8 ( V_33 -> V_32 ,
L_23 , V_161 ) ;
return - V_43 ;
}
V_3 = F_52 ( V_33 -> V_32 , sizeof( * V_3 ) ,
V_165 ) ;
if ( ! V_3 )
return - V_121 ;
V_3 -> V_142 = V_164 ;
V_3 -> V_36 = ( T_2 ) V_161 ;
V_33 -> V_3 [ V_161 ] = V_3 ;
V_160 = true ;
}
if ( ! V_160 ) {
for ( V_161 = 0 ; V_161 < V_162 ; V_161 ++ ) {
V_3 = F_52 ( V_33 -> V_32 , sizeof( * V_3 ) ,
V_165 ) ;
if ( ! V_3 )
return - V_121 ;
V_3 -> V_36 = V_161 ;
V_33 -> V_3 [ V_161 ] = V_3 ;
}
}
for ( V_161 = 0 ; V_161 < V_162 ; V_161 ++ ) {
V_3 = V_33 -> V_3 [ V_161 ] ;
if ( ! V_3 )
continue;
V_16 = F_47 ( V_33 , V_3 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_31 ( V_3 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
void F_53 ( struct V_63 * V_33 )
{
int V_166 ;
int V_162 = F_49 ( V_33 ) ;
for ( V_166 = 0 ; V_166 < V_162 ; V_166 ++ ) {
F_26 ( V_33 -> V_3 [ V_166 ] ) ;
V_33 -> V_3 [ V_166 ] = NULL ;
}
}
int F_54 ( struct V_2 * V_3 ,
enum V_167 V_168 , int V_169 )
{
int V_16 ;
struct V_14 * V_85 = F_4 ( V_3 ) ;
if ( V_85 -> V_170 )
V_16 = V_85 -> V_170 ( V_85 , V_168 , V_169 ) ;
else
V_16 = - V_120 ;
return V_16 ;
}
void F_55 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_4 ( V_3 ) ;
V_15 -> V_171 ( V_15 ) ;
}
void F_56 ( struct V_2 * V_3 , T_6 * V_172 )
{
struct V_14 * V_15 = F_4 ( V_3 ) ;
V_15 -> V_173 ( V_15 , V_172 ) ;
}
void F_57 ( struct V_2 * V_3 ,
int V_174 , T_2 * V_172 )
{
struct V_14 * V_15 = F_4 ( V_3 ) ;
V_15 -> V_175 ( V_174 , V_172 ) ;
}
int F_58 ( struct V_2 * V_3 , int V_174 )
{
struct V_14 * V_15 = F_4 ( V_3 ) ;
return V_15 -> V_176 ( V_174 ) ;
}
void F_59 ( struct V_2 * V_3 , T_2 V_169 )
{
struct V_14 * V_15 = F_4 ( V_3 ) ;
if ( V_15 -> V_177 )
V_15 -> V_177 ( V_15 , V_169 ) ;
}
int F_60 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_4 ( V_3 ) ;
return V_15 -> V_178 () ;
}
void F_61 ( struct V_2 * V_3 , void * V_172 )
{
struct V_14 * V_15 = F_4 ( V_3 ) ;
V_15 -> V_179 ( V_15 , V_172 ) ;
}
void F_62 ( struct V_2 * V_3 )
{
int V_180 = 0 ;
int V_181 , V_182 ;
V_181 = V_3 -> V_158 - V_3 -> V_183 . V_184 ;
V_182 = V_3 -> V_159 - V_3 -> V_183 . V_185 ;
if ( V_181 || V_182 )
V_180 = 1 ;
else
V_180 = 0 ;
V_3 -> V_158 = V_3 -> V_183 . V_184 ;
V_3 -> V_159 = V_3 -> V_183 . V_185 ;
F_63 ( V_3 , ( int ) V_3 -> V_19 ,
V_3 -> V_21 , V_180 ) ;
}
int F_64 ( struct V_2 * V_3 ,
enum V_186 V_187 )
{
if ( ! V_3 || ! V_3 -> V_145 )
return 0 ;
return F_65 ( V_3 , V_187 ) ;
}
