static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( F_2 ( ! V_6 -> V_7 ) )
return - V_8 ;
return V_2 -> V_9 . V_10 ( V_2 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_11 ,
unsigned int V_12 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 V_4 ;
T_1 * V_13 ;
T_2 V_14 [ 5 ] , V_15 ;
unsigned int V_16 , V_17 ;
int V_18 ;
V_14 [ 0 ] = ( ( V_11 >> 8 ) & 0xff ) << 1 ;
V_14 [ 1 ] = V_11 & 0xff ;
V_13 = ( T_1 * ) & V_14 [ 2 ] ;
* V_13 = F_4 ( V_12 ) ;
V_15 = 0 ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
V_15 += V_14 [ V_16 ] ;
if ( V_14 [ V_16 ] > V_15 )
V_15 ++ ;
}
V_14 [ 4 ] = ~ V_15 ;
V_17 = 1 ;
V_19:
V_4 . V_20 = V_21 ;
V_4 . V_22 = V_6 -> V_23 ;
V_4 . V_24 = sizeof( V_14 ) ;
V_4 . V_25 = V_14 ;
V_18 = F_1 ( V_2 , & V_4 ) ;
if ( V_18 ) {
if ( ( V_18 == - V_26 ) && V_17 -- )
goto V_19;
return V_18 ;
}
V_17 = 1 ;
V_27:
V_4 . V_20 = V_28 ;
V_4 . V_22 = V_6 -> V_23 ;
V_4 . V_24 = 1 ;
V_4 . V_25 = V_14 ;
V_18 = F_1 ( V_2 , & V_4 ) ;
if ( V_18 ) {
if ( ( V_18 == - V_26 ) && V_17 -- )
goto V_27;
return V_18 ;
}
if ( V_14 [ 0 ] != 0xff ) {
F_5 ( V_2 , V_29 , V_2 -> V_30 ,
L_1 ) ;
V_18 = - V_8 ;
}
return V_18 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_22 ,
void * V_12 , unsigned int V_31 )
{
struct V_3 V_4 ;
int V_17 , V_18 ;
V_17 = 1 ;
V_32:
V_4 . V_20 = V_21 ;
V_4 . V_22 = V_22 ;
V_4 . V_24 = V_31 ;
V_4 . V_25 = V_12 ;
V_18 = F_1 ( V_2 , & V_4 ) ;
if ( ( V_18 == - V_26 ) && V_17 -- )
goto V_32;
return V_18 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_22 ,
void * V_11 , unsigned int V_33 ,
void * V_12 , unsigned int V_31 )
{
struct V_3 V_4 ;
int V_17 , V_18 ;
V_17 = 1 ;
V_19:
V_4 . V_20 = V_21 ;
V_4 . V_22 = V_22 ;
V_4 . V_24 = V_33 ;
V_4 . V_25 = V_11 ;
V_18 = F_1 ( V_2 , & V_4 ) ;
if ( V_18 ) {
if ( ( V_18 == - V_26 ) && V_17 -- )
goto V_19;
return V_18 ;
}
V_17 = 1 ;
V_27:
V_4 . V_20 = V_28 ;
V_4 . V_22 = V_22 ;
V_4 . V_24 = V_31 ;
V_4 . V_25 = V_12 ;
V_18 = F_1 ( V_2 , & V_4 ) ;
if ( ( V_18 == - V_26 ) && V_17 -- )
goto V_27;
return V_18 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 V_4 ;
T_2 V_34 ;
if ( V_6 -> V_35 == V_36 )
return 0 ;
V_34 = 0 ;
V_4 . V_20 = V_21 ;
V_4 . V_22 = V_6 -> V_37 ;
V_4 . V_24 = sizeof( V_34 ) ;
V_4 . V_25 = & V_34 ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 V_4 ;
T_2 V_34 ;
if ( V_6 -> V_35 == V_36 )
return 0 ;
V_34 = 1 << V_6 -> V_38 ;
V_4 . V_20 = V_21 ;
V_4 . V_22 = V_6 -> V_37 ;
V_4 . V_24 = sizeof( V_34 ) ;
V_4 . V_25 = & V_34 ;
return F_1 ( V_2 , & V_4 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
V_6 -> V_7 = 0 ;
F_11 ( & V_39 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned long V_40 ;
unsigned int V_41 ;
if ( V_6 -> V_7 )
return 0 ;
F_13 ( & V_39 ) ;
F_14 ( V_2 , V_42 , V_43 ) ;
F_14 ( V_2 , V_44 , V_43 ) ;
V_41 = 0 ;
F_15 ( V_41 , V_42 , V_45 , V_6 -> V_46 ) ;
F_15 ( V_41 , V_42 , V_47 , 1 ) ;
V_40 = V_48 + ( 5 * V_49 ) ;
while ( F_16 ( V_48 , V_40 ) ) {
if ( F_17 ( V_2 , V_42 ) ||
F_17 ( V_2 , V_44 ) ) {
F_18 ( 100 , 200 ) ;
continue;
}
F_14 ( V_2 , V_42 , V_41 ) ;
F_14 ( V_2 , V_44 , V_41 ) ;
V_6 -> V_7 = 1 ;
return 0 ;
}
F_11 ( & V_39 ) ;
F_19 ( V_2 -> V_30 , L_2 ) ;
return - V_50 ;
}
static int F_20 ( struct V_1 * V_2 , int V_51 ,
int V_11 , T_3 V_12 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_11 & V_52 ) {
if ( V_6 -> V_53 != V_54 )
return - V_55 ;
} else {
if ( V_6 -> V_53 != V_56 )
return - V_55 ;
}
return V_2 -> V_57 . V_58 ( V_2 , V_51 , V_11 , V_12 ) ;
}
static int F_21 ( struct V_1 * V_2 , int V_11 , T_3 V_12 )
{
T_1 * V_59 ;
T_2 V_60 [ 3 ] ;
int V_18 ;
V_18 = F_9 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_60 [ 0 ] = V_11 & 0xff ;
V_59 = ( T_1 * ) & V_60 [ 1 ] ;
* V_59 = F_4 ( V_12 ) ;
V_18 = F_6 ( V_2 , V_61 ,
V_60 , sizeof( V_60 ) ) ;
F_8 ( V_2 ) ;
return V_18 ;
}
static int F_22 ( struct V_62 * V_63 , int V_51 , int V_11 , T_3 V_12 )
{
struct V_1 * V_2 = V_63 -> V_64 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_18 ;
V_18 = F_12 ( V_2 ) ;
if ( V_18 )
return V_18 ;
if ( V_6 -> V_65 == V_66 )
V_18 = F_21 ( V_2 , V_11 , V_12 ) ;
else if ( V_6 -> V_65 & V_67 )
V_18 = F_20 ( V_2 , V_51 , V_11 , V_12 ) ;
else
V_18 = - V_55 ;
F_10 ( V_2 ) ;
return V_18 ;
}
static int F_23 ( struct V_1 * V_2 , int V_51 ,
int V_11 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_11 & V_52 ) {
if ( V_6 -> V_53 != V_54 )
return - V_55 ;
} else {
if ( V_6 -> V_53 != V_56 )
return - V_55 ;
}
return V_2 -> V_57 . V_68 ( V_2 , V_51 , V_11 ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_11 )
{
T_1 V_59 ;
T_2 V_69 ;
int V_18 ;
V_18 = F_9 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_69 = V_11 ;
V_18 = F_7 ( V_2 , V_61 ,
& V_69 , sizeof( V_69 ) ,
& V_59 , sizeof( V_59 ) ) ;
if ( ! V_18 )
V_18 = F_25 ( V_59 ) ;
F_8 ( V_2 ) ;
return V_18 ;
}
static int F_26 ( struct V_62 * V_63 , int V_51 , int V_11 )
{
struct V_1 * V_2 = V_63 -> V_64 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_18 ;
V_18 = F_12 ( V_2 ) ;
if ( V_18 )
return V_18 ;
if ( V_6 -> V_65 == V_66 )
V_18 = F_24 ( V_2 , V_11 ) ;
else if ( V_6 -> V_65 & V_67 )
V_18 = F_23 ( V_2 , V_51 , V_11 ) ;
else
V_18 = - V_55 ;
F_10 ( V_2 ) ;
return V_18 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = & V_2 -> V_72 . V_71 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( ! V_6 -> V_73 && ! V_6 -> V_74 )
return;
F_28 ( V_71 ) ;
if ( V_6 -> V_73 ) {
V_2 -> V_72 . V_75 = V_76 ;
V_2 -> V_72 . V_77 = V_78 ;
V_2 -> V_72 . V_79 = V_80 ;
V_2 -> V_72 . V_81 = V_80 ;
F_29 ( V_71 , V_82 ) ;
F_29 ( V_71 , V_83 ) ;
F_29 ( V_71 , V_84 ) ;
F_29 ( V_71 , V_85 ) ;
F_29 ( V_71 , V_86 ) ;
F_30 ( V_71 , V_87 , V_71 , V_88 ) ;
return;
}
switch ( V_6 -> V_89 ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
V_2 -> V_72 . V_75 = V_76 ;
V_2 -> V_72 . V_77 = V_78 ;
V_2 -> V_72 . V_79 = V_80 ;
V_2 -> V_72 . V_81 = V_80 ;
F_29 ( V_71 , V_82 ) ;
F_29 ( V_71 , V_83 ) ;
F_29 ( V_71 , V_84 ) ;
if ( V_6 -> V_89 == V_90 ) {
if ( V_6 -> V_94 & V_95 )
F_29 ( V_71 , 100baseT_Full ) ;
if ( V_6 -> V_94 & V_96 )
F_29 ( V_71 , 1000baseT_Full ) ;
} else {
if ( V_6 -> V_94 & V_96 )
F_29 ( V_71 , 1000baseX_Full ) ;
}
break;
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
V_2 -> V_72 . V_75 = V_102 ;
V_2 -> V_72 . V_77 = V_103 ;
V_2 -> V_72 . V_79 = V_104 ;
V_2 -> V_72 . V_81 = V_104 ;
if ( V_6 -> V_94 & V_105 ) {
switch ( V_6 -> V_89 ) {
case V_97 :
F_29 ( V_71 , 10000baseSR_Full ) ;
break;
case V_98 :
F_29 ( V_71 , 10000baseLR_Full ) ;
break;
case V_99 :
F_29 ( V_71 , 10000baseLRM_Full ) ;
break;
case V_100 :
F_29 ( V_71 , 10000baseER_Full ) ;
break;
case V_101 :
F_29 ( V_71 , 10000baseCR_Full ) ;
break;
default:
break;
}
}
break;
default:
V_2 -> V_72 . V_75 = V_76 ;
V_2 -> V_72 . V_77 = V_78 ;
V_2 -> V_72 . V_79 = V_104 ;
V_2 -> V_72 . V_81 = V_104 ;
break;
}
switch ( V_6 -> V_89 ) {
case V_90 :
case V_93 :
case V_101 :
F_29 ( V_71 , V_85 ) ;
break;
default:
F_29 ( V_71 , V_86 ) ;
break;
}
F_30 ( V_71 , V_87 , V_71 , V_88 ) ;
}
static bool F_31 ( struct V_106 * V_107 ,
enum V_108 V_109 )
{
T_2 * V_89 , V_110 , V_111 ;
V_89 = V_107 -> V_112 ;
switch ( V_109 ) {
case V_113 :
V_110 = V_114 ;
V_111 = V_115 ;
break;
case V_116 :
V_110 = V_117 ;
V_111 = V_118 ;
break;
default:
return false ;
}
return ( ( V_89 [ V_119 ] >= V_110 ) &&
( V_89 [ V_119 ] <= V_111 ) ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_6 -> V_120 ) {
F_33 ( V_6 -> V_120 ) ;
F_34 ( V_6 -> V_120 ) ;
F_35 ( V_6 -> V_120 ) ;
V_6 -> V_120 = NULL ;
}
}
static bool F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned int V_121 = V_6 -> V_120 -> V_121 ;
if ( ( V_121 & 0xfffffff0 ) != 0x01ff0cc0 )
return false ;
F_37 ( V_6 -> V_120 , 0x16 , 0x0001 ) ;
F_37 ( V_6 -> V_120 , 0x00 , 0x9140 ) ;
F_37 ( V_6 -> V_120 , 0x16 , 0x0000 ) ;
F_37 ( V_6 -> V_120 , 0x1b , 0x9084 ) ;
F_37 ( V_6 -> V_120 , 0x09 , 0x0e00 ) ;
F_37 ( V_6 -> V_120 , 0x00 , 0x8140 ) ;
F_37 ( V_6 -> V_120 , 0x04 , 0x0d01 ) ;
F_37 ( V_6 -> V_120 , 0x00 , 0x9140 ) ;
V_6 -> V_120 -> V_88 = V_122 ;
V_6 -> V_120 -> V_88 |= V_123 | V_124 ;
V_6 -> V_120 -> V_87 = V_6 -> V_120 -> V_88 ;
F_5 ( V_2 , V_29 , V_2 -> V_30 ,
L_3 ) ;
return true ;
}
static void F_38 ( struct V_1 * V_2 )
{
if ( F_36 ( V_2 ) )
return;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = & V_2 -> V_72 . V_71 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_125 * V_120 ;
T_4 V_87 ;
int V_18 ;
if ( V_6 -> V_120 )
return 0 ;
if ( V_6 -> V_53 == V_126 )
return 0 ;
if ( ( V_6 -> V_127 == V_128 ) &&
! V_6 -> V_129 )
return 0 ;
V_18 = V_2 -> V_57 . V_130 ( V_2 , V_6 -> V_131 ,
V_6 -> V_53 ) ;
if ( V_18 ) {
F_19 ( V_2 -> V_30 ,
L_4 ,
V_6 -> V_131 , V_6 -> V_53 ) ;
return V_18 ;
}
V_120 = F_40 ( V_6 -> V_63 , V_6 -> V_131 ,
( V_6 -> V_53 == V_54 ) ) ;
if ( F_41 ( V_120 ) ) {
F_19 ( V_2 -> V_30 , L_5 ) ;
return - V_132 ;
}
F_5 ( V_2 , V_29 , V_2 -> V_30 , L_6 ,
V_120 -> V_121 ) ;
V_18 = F_42 ( V_120 ) ;
if ( V_18 ) {
F_19 ( V_2 -> V_30 , L_7 ) ;
F_35 ( V_120 ) ;
return V_18 ;
}
V_18 = F_43 ( V_2 -> V_30 , V_120 , V_120 -> V_133 ,
V_134 ) ;
if ( V_18 ) {
F_19 ( V_2 -> V_30 , L_8 ) ;
F_34 ( V_120 ) ;
F_35 ( V_120 ) ;
return V_18 ;
}
V_6 -> V_120 = V_120 ;
F_38 ( V_2 ) ;
F_44 ( & V_87 ,
V_71 -> V_135 . V_87 ) ;
V_120 -> V_87 &= V_87 ;
F_45 ( V_6 -> V_120 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_18 ;
if ( ! V_6 -> V_74 )
return;
V_6 -> V_129 = 0 ;
if ( V_6 -> V_89 != V_90 )
return;
V_18 = F_24 ( V_2 , V_136 ) ;
if ( V_18 < 0 )
return;
V_6 -> V_129 = 1 ;
}
static bool F_47 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_106 * V_107 = & V_6 -> V_107 ;
if ( memcmp ( & V_107 -> V_112 [ V_137 ] ,
V_138 , V_139 ) )
return false ;
if ( ! memcmp ( & V_107 -> V_112 [ V_140 ] ,
V_141 , V_142 ) ) {
V_6 -> V_89 = V_91 ;
V_6 -> V_143 = V_144 ;
V_6 -> V_109 = V_113 ;
if ( V_6 -> V_74 )
F_5 ( V_2 , V_29 , V_2 -> V_30 ,
L_9 ) ;
return true ;
}
return false ;
}
static bool F_48 ( struct V_1 * V_2 )
{
if ( F_47 ( V_2 ) )
return true ;
return false ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_106 * V_107 = & V_6 -> V_107 ;
T_2 * V_89 ;
V_89 = V_107 -> V_112 ;
if ( V_89 [ V_145 ] != V_146 )
return;
if ( V_89 [ V_147 ] != V_148 )
return;
if ( F_48 ( V_2 ) )
return;
if ( V_89 [ V_149 ] & V_150 ) {
V_6 -> V_143 = V_151 ;
V_6 -> V_152 = V_89 [ V_153 ] ;
} else {
V_6 -> V_143 = V_144 ;
}
if ( V_89 [ V_154 ] & V_155 )
V_6 -> V_89 = V_97 ;
else if ( V_89 [ V_154 ] & V_156 )
V_6 -> V_89 = V_98 ;
else if ( V_89 [ V_154 ] & V_157 )
V_6 -> V_89 = V_99 ;
else if ( V_89 [ V_154 ] & V_158 )
V_6 -> V_89 = V_100 ;
else if ( V_89 [ V_159 ] & V_160 )
V_6 -> V_89 = V_91 ;
else if ( V_89 [ V_159 ] & V_161 )
V_6 -> V_89 = V_92 ;
else if ( V_89 [ V_159 ] & V_162 )
V_6 -> V_89 = V_93 ;
else if ( V_89 [ V_159 ] & V_163 )
V_6 -> V_89 = V_90 ;
else if ( ( V_6 -> V_143 == V_151 ) &&
F_31 ( V_107 , V_116 ) )
V_6 -> V_89 = V_101 ;
switch ( V_6 -> V_89 ) {
case V_90 :
V_6 -> V_109 = V_164 ;
break;
case V_91 :
case V_92 :
case V_93 :
V_6 -> V_109 = V_113 ;
break;
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
V_6 -> V_109 = V_116 ;
break;
default:
break;
}
}
static void F_50 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
struct V_165 V_166 ;
char * V_167 = ( char * ) & V_166 ;
F_5 ( V_2 , V_29 , V_2 -> V_30 , L_10 ) ;
memcpy ( V_167 , & V_107 -> V_112 [ V_137 ] ,
V_139 ) ;
V_167 [ V_139 ] = '\0' ;
F_5 ( V_2 , V_29 , V_2 -> V_30 , L_11 ,
V_167 ) ;
memcpy ( V_167 , & V_107 -> V_112 [ V_140 ] ,
V_142 ) ;
V_167 [ V_142 ] = '\0' ;
F_5 ( V_2 , V_29 , V_2 -> V_30 , L_12 ,
V_167 ) ;
memcpy ( V_167 , & V_107 -> V_112 [ V_168 ] ,
V_169 ) ;
V_167 [ V_169 ] = '\0' ;
F_5 ( V_2 , V_29 , V_2 -> V_30 , L_13 ,
V_167 ) ;
memcpy ( V_167 , & V_107 -> V_170 [ V_171 ] ,
V_172 ) ;
V_167 [ V_172 ] = '\0' ;
F_5 ( V_2 , V_29 , V_2 -> V_30 , L_14 ,
V_167 ) ;
}
static bool F_51 ( T_2 V_173 , T_2 * V_25 , unsigned int V_24 )
{
T_2 V_174 ;
for ( V_174 = 0 ; V_24 ; V_25 ++ , V_24 -- )
V_174 += * V_25 ;
return ( V_174 == V_173 ) ? true : false ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_106 V_107 ;
T_2 V_175 ;
int V_18 ;
V_18 = F_9 ( V_2 ) ;
if ( V_18 ) {
F_53 ( V_2 -> V_176 , L_15 ,
F_54 ( V_2 -> V_30 ) ) ;
return V_18 ;
}
V_175 = 0 ;
V_18 = F_7 ( V_2 , V_177 ,
& V_175 , sizeof( V_175 ) ,
& V_107 , sizeof( V_107 ) ) ;
if ( V_18 ) {
F_53 ( V_2 -> V_176 , L_16 ,
F_54 ( V_2 -> V_30 ) ) ;
goto V_178;
}
if ( ! F_51 ( V_107 . V_112 [ V_179 ] ,
V_107 . V_112 ,
sizeof( V_107 . V_112 ) - 1 ) ) {
V_18 = - V_180 ;
goto V_178;
}
if ( ! F_51 ( V_107 . V_170 [ V_181 ] ,
V_107 . V_170 ,
sizeof( V_107 . V_170 ) - 1 ) ) {
V_18 = - V_180 ;
goto V_178;
}
if ( memcmp ( & V_6 -> V_107 , & V_107 , sizeof( V_107 ) ) ) {
V_6 -> V_74 = 1 ;
if ( F_55 ( V_2 ) )
F_50 ( V_2 , & V_107 ) ;
memcpy ( & V_6 -> V_107 , & V_107 , sizeof( V_107 ) ) ;
if ( V_107 . V_170 [ V_182 ] ) {
T_2 V_183 = V_107 . V_170 [ V_184 ] ;
if ( ! ( V_183 & V_185 ) )
V_6 -> V_186 = 1 ;
}
F_32 ( V_2 ) ;
} else {
V_6 -> V_74 = 0 ;
}
V_178:
F_8 ( V_2 ) ;
return V_18 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned int V_187 ;
T_2 V_188 , V_189 [ 2 ] ;
int V_18 ;
V_188 = 0 ;
V_18 = F_7 ( V_2 , V_6 -> V_190 ,
& V_188 , sizeof( V_188 ) ,
V_189 , sizeof( V_189 ) ) ;
if ( V_18 ) {
F_53 ( V_2 -> V_176 , L_17 ,
F_54 ( V_2 -> V_30 ) ) ;
return;
}
V_187 = ( V_189 [ 1 ] << 8 ) | V_189 [ 0 ] ;
if ( V_6 -> V_191 & V_192 ) {
V_6 -> V_73 = 0 ;
} else {
if ( ! ( V_187 & ( 1 << V_6 -> V_193 ) ) )
V_6 -> V_73 = 0 ;
}
if ( ! ( V_6 -> V_191 & V_194 ) &&
( V_187 & ( 1 << V_6 -> V_195 ) ) )
V_6 -> V_196 = 1 ;
if ( ! ( V_6 -> V_191 & V_197 ) &&
( V_187 & ( 1 << V_6 -> V_198 ) ) )
V_6 -> V_199 = 1 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_32 ( V_2 ) ;
V_6 -> V_73 = 1 ;
V_6 -> V_129 = 0 ;
memset ( & V_6 -> V_107 , 0 , sizeof( V_6 -> V_107 ) ) ;
}
static void F_58 ( struct V_5 * V_6 )
{
V_6 -> V_196 = 0 ;
V_6 -> V_199 = 0 ;
V_6 -> V_73 = 1 ;
V_6 -> V_186 = 0 ;
V_6 -> V_89 = V_200 ;
V_6 -> V_143 = V_201 ;
V_6 -> V_109 = V_202 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_18 ;
F_58 ( V_6 ) ;
V_18 = F_12 ( V_2 ) ;
if ( V_18 )
return;
F_56 ( V_2 ) ;
if ( V_6 -> V_73 ) {
F_57 ( V_2 ) ;
goto V_178;
}
V_18 = F_52 ( V_2 ) ;
if ( V_18 ) {
F_58 ( V_6 ) ;
F_57 ( V_2 ) ;
goto V_178;
}
F_49 ( V_2 ) ;
F_46 ( V_2 ) ;
V_178:
F_27 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = & V_2 -> V_72 . V_71 ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_3 V_203 = 0 , V_204 = 0 ;
T_2 V_205 ;
V_2 -> V_72 . V_206 = 0 ;
V_2 -> V_72 . V_207 = 0 ;
if ( ! V_6 -> V_120 )
return;
if ( V_6 -> V_120 -> V_87 & V_208 )
V_203 |= V_209 ;
if ( V_6 -> V_120 -> V_87 & V_210 )
V_203 |= V_211 ;
if ( V_6 -> V_120 -> V_212 ) {
F_61 ( V_71 , V_83 ) ;
V_204 |= V_213 ;
}
if ( V_6 -> V_120 -> V_214 ) {
F_61 ( V_71 , V_84 ) ;
V_204 |= V_215 ;
}
V_205 = F_62 ( V_203 , V_204 ) ;
if ( V_205 & V_216 )
V_2 -> V_72 . V_206 = 1 ;
if ( V_205 & V_217 )
V_2 -> V_72 . V_207 = 1 ;
}
static enum V_218 F_63 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = & V_2 -> V_72 . V_71 ;
enum V_218 V_219 ;
F_61 ( V_71 , V_82 ) ;
F_61 ( V_71 , V_85 ) ;
if ( V_2 -> V_72 . V_81 )
F_60 ( V_2 ) ;
switch ( V_2 -> V_220 & V_221 ) {
case V_222 :
if ( V_2 -> V_220 & V_223 ) {
F_61 ( V_71 , 100baseT_Full ) ;
V_219 = V_224 ;
} else {
F_61 ( V_71 , 100baseT_Half ) ;
V_219 = V_225 ;
}
break;
case V_226 :
if ( V_2 -> V_220 & V_223 ) {
F_61 ( V_71 , 1000baseT_Full ) ;
V_219 = V_227 ;
} else {
F_61 ( V_71 , 1000baseT_Half ) ;
V_219 = V_225 ;
}
break;
default:
V_219 = V_225 ;
}
return V_219 ;
}
static enum V_218 F_64 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = & V_2 -> V_72 . V_71 ;
enum V_218 V_219 ;
unsigned int V_228 , V_229 ;
F_61 ( V_71 , V_82 ) ;
F_61 ( V_71 , V_86 ) ;
V_228 = F_65 ( V_2 , V_230 , V_231 ) ;
V_229 = F_65 ( V_2 , V_230 , V_232 ) ;
if ( V_229 & 0x100 )
F_61 ( V_71 , V_83 ) ;
if ( V_229 & 0x80 )
F_61 ( V_71 , V_84 ) ;
if ( V_2 -> V_72 . V_81 ) {
V_2 -> V_72 . V_206 = 0 ;
V_2 -> V_72 . V_207 = 0 ;
if ( V_228 & V_229 & 0x100 ) {
V_2 -> V_72 . V_206 = 1 ;
V_2 -> V_72 . V_207 = 1 ;
} else if ( V_228 & V_229 & 0x80 ) {
if ( V_228 & 0x100 )
V_2 -> V_72 . V_207 = 1 ;
else if ( V_229 & 0x100 )
V_2 -> V_72 . V_206 = 1 ;
}
}
if ( V_229 & 0x20 )
F_61 ( V_71 , 1000baseX_Full ) ;
V_228 &= V_229 ;
V_219 = ( V_228 & 0x20 ) ? V_233 : V_225 ;
return V_219 ;
}
static enum V_218 F_66 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = & V_2 -> V_72 . V_71 ;
struct V_5 * V_6 = V_2 -> V_6 ;
enum V_218 V_219 ;
unsigned int V_228 , V_229 ;
F_61 ( V_71 , V_82 ) ;
F_61 ( V_71 , V_234 ) ;
if ( V_2 -> V_72 . V_81 )
F_60 ( V_2 ) ;
V_228 = F_65 ( V_2 , V_235 , V_236 + 1 ) ;
V_229 = F_65 ( V_2 , V_235 , V_237 + 1 ) ;
if ( V_229 & 0x80 )
F_61 ( V_71 , 10000baseKR_Full ) ;
if ( V_229 & 0x20 )
F_61 ( V_71 , 1000baseKX_Full ) ;
V_228 &= V_229 ;
if ( V_228 & 0x80 ) {
switch ( V_6 -> V_127 ) {
case V_238 :
V_219 = V_239 ;
break;
default:
V_219 = V_240 ;
break;
}
} else if ( V_228 & 0x20 ) {
switch ( V_6 -> V_127 ) {
case V_238 :
V_219 = V_241 ;
break;
case V_242 :
V_219 = V_233 ;
break;
case V_128 :
switch ( V_6 -> V_89 ) {
case V_90 :
if ( V_6 -> V_120 &&
( V_6 -> V_120 -> V_75 == V_243 ) )
V_219 = V_224 ;
else
V_219 = V_227 ;
break;
case V_91 :
case V_92 :
case V_93 :
default:
V_219 = V_233 ;
break;
}
break;
default:
if ( V_6 -> V_120 &&
( V_6 -> V_120 -> V_75 == V_243 ) )
V_219 = V_224 ;
else
V_219 = V_227 ;
break;
}
} else {
V_219 = V_225 ;
}
V_228 = F_65 ( V_2 , V_235 , V_236 + 2 ) ;
V_229 = F_65 ( V_2 , V_235 , V_237 + 2 ) ;
if ( V_229 & 0xc000 )
F_61 ( V_71 , 10000baseR_FEC ) ;
return V_219 ;
}
static enum V_218 F_67 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = & V_2 -> V_72 . V_71 ;
enum V_218 V_219 ;
unsigned int V_228 , V_229 ;
F_61 ( V_71 , V_82 ) ;
F_61 ( V_71 , V_234 ) ;
V_228 = F_65 ( V_2 , V_235 , V_236 ) ;
V_229 = F_65 ( V_2 , V_235 , V_237 ) ;
if ( V_229 & 0x400 )
F_61 ( V_71 , V_83 ) ;
if ( V_229 & 0x800 )
F_61 ( V_71 , V_84 ) ;
if ( V_2 -> V_72 . V_81 ) {
V_2 -> V_72 . V_206 = 0 ;
V_2 -> V_72 . V_207 = 0 ;
if ( V_228 & V_229 & 0x400 ) {
V_2 -> V_72 . V_206 = 1 ;
V_2 -> V_72 . V_207 = 1 ;
} else if ( V_228 & V_229 & 0x800 ) {
if ( V_228 & 0x400 )
V_2 -> V_72 . V_207 = 1 ;
else if ( V_229 & 0x400 )
V_2 -> V_72 . V_206 = 1 ;
}
}
V_228 = F_65 ( V_2 , V_235 , V_236 + 1 ) ;
V_229 = F_65 ( V_2 , V_235 , V_237 + 1 ) ;
if ( V_229 & 0x80 )
F_61 ( V_71 , 10000baseKR_Full ) ;
if ( V_229 & 0x20 )
F_61 ( V_71 , 1000baseKX_Full ) ;
V_228 &= V_229 ;
if ( V_228 & 0x80 )
V_219 = V_239 ;
else if ( V_228 & 0x20 )
V_219 = V_241 ;
else
V_219 = V_225 ;
V_228 = F_65 ( V_2 , V_235 , V_236 + 2 ) ;
V_229 = F_65 ( V_2 , V_235 , V_237 + 2 ) ;
if ( V_229 & 0xc000 )
F_61 ( V_71 , 10000baseR_FEC ) ;
return V_219 ;
}
static enum V_218 F_68 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_244 ) {
case V_245 :
return F_67 ( V_2 ) ;
case V_246 :
return F_66 ( V_2 ) ;
case V_247 :
return F_64 ( V_2 ) ;
case V_248 :
return F_63 ( V_2 ) ;
default:
return V_225 ;
}
}
static void F_69 ( struct V_1 * V_2 ,
struct V_70 * V_249 )
{
struct V_70 * V_250 = & V_2 -> V_72 . V_71 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_30 ( V_249 , V_87 , V_250 , V_87 ) ;
if ( ! V_6 -> V_251 )
return;
F_70 ( V_249 , 1000baseKX_Full ) ;
F_70 ( V_249 , 10000baseKR_Full ) ;
switch ( V_6 -> V_127 ) {
case V_238 :
F_71 ( V_249 , 10000baseKR_Full ) ;
break;
case V_252 :
F_71 ( V_249 , 1000baseKX_Full ) ;
break;
case V_253 :
case V_242 :
case V_254 :
F_71 ( V_249 , 1000baseKX_Full ) ;
break;
case V_255 :
if ( V_6 -> V_120 &&
( V_6 -> V_120 -> V_75 == V_102 ) )
F_71 ( V_249 , 10000baseKR_Full ) ;
else
F_71 ( V_249 , 1000baseKX_Full ) ;
break;
case V_256 :
F_71 ( V_249 , 10000baseKR_Full ) ;
break;
case V_128 :
switch ( V_6 -> V_89 ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
F_71 ( V_249 , 1000baseKX_Full ) ;
break;
default:
F_71 ( V_249 , 10000baseKR_Full ) ;
break;
}
break;
default:
F_71 ( V_249 , 10000baseKR_Full ) ;
break;
}
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = & V_2 -> V_72 . V_71 ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_4 V_87 ;
int V_18 ;
V_18 = F_39 ( V_2 ) ;
if ( V_18 )
return V_18 ;
if ( ! V_6 -> V_120 )
return 0 ;
F_44 ( & V_87 ,
V_71 -> V_135 . V_87 ) ;
V_6 -> V_120 -> V_79 = V_2 -> V_72 . V_79 ;
V_6 -> V_120 -> V_87 = V_6 -> V_120 -> V_88 &
V_87 ;
if ( V_2 -> V_72 . V_79 != V_80 ) {
V_6 -> V_120 -> V_75 = V_2 -> V_72 . V_75 ;
V_6 -> V_120 -> V_77 = V_2 -> V_72 . V_77 ;
}
V_18 = F_45 ( V_6 -> V_120 ) ;
return V_18 ;
}
static enum V_257 F_73 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_89 ) {
case V_90 :
return V_248 ;
case V_91 :
case V_92 :
case V_93 :
return V_247 ;
default:
return V_258 ;
}
}
static enum V_257 F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_6 -> V_251 )
return V_246 ;
switch ( V_6 -> V_127 ) {
case V_238 :
return V_245 ;
case V_252 :
return V_258 ;
case V_253 :
return V_248 ;
case V_242 :
return V_247 ;
case V_254 :
return V_248 ;
case V_255 :
return V_245 ;
case V_256 :
return V_258 ;
case V_128 :
return F_73 ( V_6 ) ;
default:
return V_258 ;
}
}
static int F_75 ( struct V_1 * V_2 ,
enum V_259 V_219 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_3 V_260 , V_13 ;
V_260 = V_261 + ( V_6 -> V_262 * 0x1000 ) ;
V_13 = ( T_3 ) V_219 ;
return V_2 -> V_57 . V_58 ( V_2 , V_6 -> V_23 ,
V_260 , V_13 ) ;
}
static int F_76 ( struct V_1 * V_2 ,
enum V_259 V_219 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned int V_260 ;
int V_18 ;
V_260 = V_261 + ( V_6 -> V_262 * 0x1000 ) ;
V_18 = F_3 ( V_2 , V_260 , V_219 ) ;
return V_18 ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
enum V_259 V_219 ;
int V_18 ;
if ( ! V_6 -> V_251 )
return;
V_219 = V_263 ;
if ( ( V_6 -> V_127 == V_128 ) &&
( V_6 -> V_89 != V_93 ) &&
( V_6 -> V_89 != V_101 ) )
V_219 = V_264 ;
V_18 = F_12 ( V_2 ) ;
if ( V_18 )
return;
if ( V_6 -> V_265 )
F_76 ( V_2 , V_219 ) ;
else
F_75 ( V_2 , V_219 ) ;
F_10 ( V_2 ) ;
}
static void F_78 ( struct V_1 * V_2 ,
unsigned int V_20 , unsigned int V_266 )
{
unsigned int V_267 = 0 ;
unsigned int V_268 ;
if ( F_79 ( V_2 , V_269 , V_270 ) )
F_5 ( V_2 , V_271 , V_2 -> V_30 ,
L_18 ) ;
F_15 ( V_267 , V_272 , V_273 , V_20 ) ;
F_15 ( V_267 , V_272 , V_274 , V_266 ) ;
F_14 ( V_2 , V_272 , V_267 ) ;
F_14 ( V_2 , V_275 , 0 ) ;
F_80 ( V_2 , V_276 , V_277 , 1 ) ;
V_268 = V_278 ;
while ( V_268 -- ) {
if ( ! F_79 ( V_2 , V_269 , V_270 ) )
return;
F_18 ( 1000 , 2000 ) ;
}
F_5 ( V_2 , V_271 , V_2 -> V_30 ,
L_19 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
F_78 ( V_2 , 5 , 0 ) ;
F_5 ( V_2 , V_271 , V_2 -> V_30 , L_20 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_78 ( V_2 , 0 , 0 ) ;
V_6 -> V_279 = V_225 ;
F_5 ( V_2 , V_271 , V_2 -> V_30 , L_21 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_77 ( V_2 ) ;
if ( V_6 -> V_143 != V_151 ) {
F_78 ( V_2 , 3 , 0 ) ;
} else {
if ( V_6 -> V_152 <= 1 )
F_78 ( V_2 , 3 , 1 ) ;
else if ( V_6 -> V_152 <= 3 )
F_78 ( V_2 , 3 , 2 ) ;
else
F_78 ( V_2 , 3 , 3 ) ;
}
V_6 -> V_279 = V_240 ;
F_5 ( V_2 , V_271 , V_2 -> V_30 , L_22 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_77 ( V_2 ) ;
F_78 ( V_2 , 1 , 3 ) ;
V_6 -> V_279 = V_233 ;
F_5 ( V_2 , V_271 , V_2 -> V_30 , L_23 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_77 ( V_2 ) ;
F_78 ( V_2 , 1 , 2 ) ;
V_6 -> V_279 = V_227 ;
F_5 ( V_2 , V_271 , V_2 -> V_30 , L_24 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_77 ( V_2 ) ;
F_78 ( V_2 , 1 , 1 ) ;
V_6 -> V_279 = V_224 ;
F_5 ( V_2 , V_271 , V_2 -> V_30 , L_25 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_77 ( V_2 ) ;
F_78 ( V_2 , 4 , 0 ) ;
V_6 -> V_279 = V_239 ;
F_5 ( V_2 , V_271 , V_2 -> V_30 , L_26 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_77 ( V_2 ) ;
F_78 ( V_2 , 2 , 0 ) ;
V_6 -> V_279 = V_280 ;
F_5 ( V_2 , V_271 , V_2 -> V_30 , L_27 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_77 ( V_2 ) ;
F_78 ( V_2 , 1 , 3 ) ;
V_6 -> V_279 = V_241 ;
F_5 ( V_2 , V_271 , V_2 -> V_30 , L_28 ) ;
}
static enum V_218 F_90 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
return V_6 -> V_279 ;
}
static enum V_218 F_91 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_6 -> V_127 != V_255 )
return F_90 ( V_2 ) ;
switch ( F_90 ( V_2 ) ) {
case V_224 :
case V_227 :
return V_239 ;
case V_239 :
default:
return V_227 ;
}
}
static enum V_218 F_92 ( struct V_1 * V_2 )
{
return V_280 ;
}
static enum V_218 F_93 ( struct V_1 * V_2 )
{
switch ( F_90 ( V_2 ) ) {
case V_241 :
return V_239 ;
case V_239 :
default:
return V_241 ;
}
}
static enum V_218 F_94 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
switch ( V_6 -> V_127 ) {
case V_238 :
return F_93 ( V_2 ) ;
case V_252 :
return F_92 ( V_2 ) ;
case V_253 :
case V_254 :
case V_255 :
return F_91 ( V_2 ) ;
case V_242 :
case V_256 :
case V_128 :
return F_90 ( V_2 ) ;
default:
return V_225 ;
}
}
static enum V_218 F_95 ( struct V_5 * V_6 ,
int V_75 )
{
switch ( V_75 ) {
case V_281 :
return V_233 ;
case V_102 :
return V_239 ;
default:
return V_225 ;
}
}
static enum V_218 F_96 ( struct V_5 * V_6 ,
int V_75 )
{
switch ( V_75 ) {
case V_243 :
return V_224 ;
case V_281 :
return V_227 ;
case V_282 :
return V_280 ;
case V_102 :
return V_239 ;
default:
return V_225 ;
}
}
static enum V_218 F_97 ( struct V_5 * V_6 ,
int V_75 )
{
switch ( V_75 ) {
case V_243 :
return V_224 ;
case V_281 :
if ( V_6 -> V_89 == V_90 )
return V_227 ;
else
return V_233 ;
case V_102 :
case V_76 :
return V_240 ;
default:
return V_225 ;
}
}
static enum V_218 F_98 ( int V_75 )
{
switch ( V_75 ) {
case V_282 :
return V_280 ;
default:
return V_225 ;
}
}
static enum V_218 F_99 ( int V_75 )
{
switch ( V_75 ) {
case V_281 :
return V_241 ;
case V_102 :
return V_239 ;
default:
return V_225 ;
}
}
static enum V_218 F_100 ( struct V_1 * V_2 ,
int V_75 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
switch ( V_6 -> V_127 ) {
case V_238 :
return F_99 ( V_75 ) ;
case V_252 :
return F_98 ( V_75 ) ;
case V_253 :
case V_254 :
case V_255 :
return F_96 ( V_6 , V_75 ) ;
case V_242 :
case V_256 :
return F_95 ( V_6 , V_75 ) ;
case V_128 :
return F_97 ( V_6 , V_75 ) ;
default:
return V_225 ;
}
}
static void F_101 ( struct V_1 * V_2 , enum V_218 V_219 )
{
switch ( V_219 ) {
case V_241 :
F_89 ( V_2 ) ;
break;
case V_280 :
F_88 ( V_2 ) ;
break;
case V_239 :
F_87 ( V_2 ) ;
break;
case V_224 :
F_86 ( V_2 ) ;
break;
case V_227 :
F_85 ( V_2 ) ;
break;
case V_233 :
F_84 ( V_2 ) ;
break;
case V_240 :
F_83 ( V_2 ) ;
break;
default:
break;
}
}
static bool F_102 ( struct V_1 * V_2 ,
enum V_218 V_219 , bool V_283 )
{
if ( V_2 -> V_72 . V_79 == V_80 ) {
return V_283 ;
} else {
enum V_218 V_279 ;
V_279 = F_100 ( V_2 , V_2 -> V_72 . V_75 ) ;
if ( V_279 == V_219 )
return true ;
}
return false ;
}
static bool F_103 ( struct V_1 * V_2 ,
enum V_218 V_219 )
{
struct V_70 * V_71 = & V_2 -> V_72 . V_71 ;
switch ( V_219 ) {
case V_233 :
return F_102 ( V_2 , V_219 ,
F_104 ( V_71 , 1000baseX_Full ) ) ;
case V_239 :
return F_102 ( V_2 , V_219 ,
F_104 ( V_71 , 10000baseKR_Full ) ) ;
default:
return false ;
}
}
static bool F_105 ( struct V_1 * V_2 ,
enum V_218 V_219 )
{
struct V_70 * V_71 = & V_2 -> V_72 . V_71 ;
switch ( V_219 ) {
case V_224 :
return F_102 ( V_2 , V_219 ,
F_104 ( V_71 , 100baseT_Full ) ) ;
case V_227 :
return F_102 ( V_2 , V_219 ,
F_104 ( V_71 , 1000baseT_Full ) ) ;
case V_280 :
return F_102 ( V_2 , V_219 ,
F_104 ( V_71 , 2500baseT_Full ) ) ;
case V_239 :
return F_102 ( V_2 , V_219 ,
F_104 ( V_71 , 10000baseT_Full ) ) ;
default:
return false ;
}
}
static bool F_106 ( struct V_1 * V_2 ,
enum V_218 V_219 )
{
struct V_70 * V_71 = & V_2 -> V_72 . V_71 ;
struct V_5 * V_6 = V_2 -> V_6 ;
switch ( V_219 ) {
case V_233 :
if ( V_6 -> V_89 == V_90 )
return false ;
return F_102 ( V_2 , V_219 ,
F_104 ( V_71 , 1000baseX_Full ) ) ;
case V_224 :
if ( V_6 -> V_89 != V_90 )
return false ;
return F_102 ( V_2 , V_219 ,
F_104 ( V_71 , 100baseT_Full ) ) ;
case V_227 :
if ( V_6 -> V_89 != V_90 )
return false ;
return F_102 ( V_2 , V_219 ,
F_104 ( V_71 , 1000baseT_Full ) ) ;
case V_240 :
if ( V_6 -> V_73 )
return true ;
return F_102 ( V_2 , V_219 ,
F_104 ( V_71 , 10000baseSR_Full ) ||
F_104 ( V_71 , 10000baseLR_Full ) ||
F_104 ( V_71 , 10000baseLRM_Full ) ||
F_104 ( V_71 , 10000baseER_Full ) ||
F_104 ( V_71 , 10000baseCR_Full ) ) ;
default:
return false ;
}
}
static bool F_107 ( struct V_1 * V_2 ,
enum V_218 V_219 )
{
struct V_70 * V_71 = & V_2 -> V_72 . V_71 ;
switch ( V_219 ) {
case V_280 :
return F_102 ( V_2 , V_219 ,
F_104 ( V_71 , 2500baseX_Full ) ) ;
default:
return false ;
}
}
static bool F_108 ( struct V_1 * V_2 ,
enum V_218 V_219 )
{
struct V_70 * V_71 = & V_2 -> V_72 . V_71 ;
switch ( V_219 ) {
case V_241 :
return F_102 ( V_2 , V_219 ,
F_104 ( V_71 , 1000baseKX_Full ) ) ;
case V_239 :
return F_102 ( V_2 , V_219 ,
F_104 ( V_71 , 10000baseKR_Full ) ) ;
default:
return false ;
}
}
static bool F_109 ( struct V_1 * V_2 , enum V_218 V_219 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
switch ( V_6 -> V_127 ) {
case V_238 :
return F_108 ( V_2 , V_219 ) ;
case V_252 :
return F_107 ( V_2 , V_219 ) ;
case V_253 :
case V_254 :
case V_255 :
return F_105 ( V_2 , V_219 ) ;
case V_242 :
case V_256 :
return F_103 ( V_2 , V_219 ) ;
case V_128 :
return F_106 ( V_2 , V_219 ) ;
default:
return false ;
}
}
static bool F_110 ( struct V_5 * V_6 ,
int V_75 )
{
switch ( V_75 ) {
case V_281 :
return ( V_6 -> V_127 == V_242 ) ;
case V_102 :
return ( V_6 -> V_127 == V_256 ) ;
default:
return false ;
}
}
static bool F_111 ( struct V_5 * V_6 ,
int V_75 )
{
switch ( V_75 ) {
case V_243 :
case V_281 :
return true ;
case V_282 :
return ( V_6 -> V_127 == V_254 ) ;
case V_102 :
return ( V_6 -> V_127 == V_255 ) ;
default:
return false ;
}
}
static bool F_112 ( struct V_5 * V_6 ,
int V_75 )
{
switch ( V_75 ) {
case V_243 :
return ( V_6 -> V_109 == V_164 ) ;
case V_281 :
return ( ( V_6 -> V_109 == V_164 ) ||
( V_6 -> V_109 == V_113 ) ) ;
case V_102 :
return ( V_6 -> V_109 == V_116 ) ;
default:
return false ;
}
}
static bool F_113 ( int V_75 )
{
switch ( V_75 ) {
case V_282 :
return true ;
default:
return false ;
}
}
static bool F_114 ( int V_75 )
{
switch ( V_75 ) {
case V_281 :
case V_102 :
return true ;
default:
return false ;
}
}
static bool F_115 ( struct V_1 * V_2 , int V_75 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
switch ( V_6 -> V_127 ) {
case V_238 :
return F_114 ( V_75 ) ;
case V_252 :
return F_113 ( V_75 ) ;
case V_253 :
case V_254 :
case V_255 :
return F_111 ( V_6 , V_75 ) ;
case V_242 :
case V_256 :
return F_110 ( V_6 , V_75 ) ;
case V_128 :
return F_112 ( V_6 , V_75 ) ;
default:
return false ;
}
}
static int F_116 ( struct V_1 * V_2 , int * V_284 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned int V_11 ;
int V_18 ;
* V_284 = 0 ;
if ( V_6 -> V_127 == V_128 ) {
F_59 ( V_2 ) ;
if ( V_6 -> V_74 ) {
* V_284 = 1 ;
return 0 ;
}
if ( V_6 -> V_73 || V_6 -> V_196 )
return 0 ;
}
if ( V_6 -> V_120 ) {
V_18 = F_117 ( V_6 -> V_120 ) ;
if ( V_18 < 0 )
return 0 ;
if ( ( V_2 -> V_72 . V_79 == V_80 ) &&
! F_118 ( V_6 -> V_120 ) )
return 0 ;
if ( ! V_6 -> V_120 -> V_271 )
return 0 ;
}
V_11 = F_65 ( V_2 , V_285 , V_286 ) ;
V_11 = F_65 ( V_2 , V_285 , V_286 ) ;
if ( V_11 & V_287 )
return 1 ;
if ( V_6 -> V_288 ++ ) {
V_6 -> V_288 = 0 ;
F_81 ( V_2 ) ;
}
return 0 ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned int V_11 ;
V_11 = F_17 ( V_2 , V_289 ) ;
V_6 -> V_190 = V_290 +
F_120 ( V_11 , V_289 , V_291 ) ;
V_6 -> V_191 = F_120 ( V_11 , V_289 , V_292 ) ;
V_6 -> V_195 = F_120 ( V_11 , V_289 ,
V_293 ) ;
V_6 -> V_198 = F_120 ( V_11 , V_289 ,
V_294 ) ;
V_6 -> V_193 = F_120 ( V_11 , V_289 ,
V_295 ) ;
V_6 -> V_296 = F_120 ( V_11 , V_289 ,
V_297 ) ;
if ( F_121 ( V_2 ) ) {
F_122 ( V_2 -> V_176 , L_29 ,
V_6 -> V_190 ) ;
F_122 ( V_2 -> V_176 , L_30 ,
V_6 -> V_191 ) ;
F_122 ( V_2 -> V_176 , L_31 ,
V_6 -> V_195 ) ;
F_122 ( V_2 -> V_176 , L_32 ,
V_6 -> V_198 ) ;
F_122 ( V_2 -> V_176 , L_33 ,
V_6 -> V_193 ) ;
F_122 ( V_2 -> V_176 , L_34 ,
V_6 -> V_296 ) ;
}
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned int V_11 , V_298 , V_299 ;
V_11 = F_17 ( V_2 , V_300 ) ;
V_298 = F_120 ( V_11 , V_300 , V_301 ) ;
V_299 = F_120 ( V_11 , V_300 , V_302 ) ;
if ( V_299 == V_303 )
return;
V_6 -> V_35 = V_304 ;
V_6 -> V_37 = ( V_298 << 2 ) + V_299 ;
V_6 -> V_38 = F_120 ( V_11 , V_300 , V_305 ) ;
if ( F_121 ( V_2 ) ) {
F_122 ( V_2 -> V_176 , L_35 ,
V_6 -> V_37 ) ;
F_122 ( V_2 -> V_176 , L_36 ,
V_6 -> V_38 ) ;
}
}
static void F_124 ( struct V_1 * V_2 )
{
F_123 ( V_2 ) ;
F_119 ( V_2 ) ;
}
static int F_125 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned int V_18 ;
V_18 = V_2 -> V_57 . V_306 ( V_2 , V_6 -> V_307 ) ;
if ( V_18 )
return V_18 ;
V_18 = V_2 -> V_57 . V_308 ( V_2 , V_6 -> V_307 ) ;
return V_18 ;
}
static int F_126 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_188 , V_189 [ 2 ] , V_309 [ 3 ] ;
int V_18 ;
V_188 = 2 ;
V_18 = F_7 ( V_2 , V_6 -> V_310 ,
& V_188 , sizeof( V_188 ) ,
V_189 , sizeof( V_189 ) ) ;
if ( V_18 )
return V_18 ;
V_309 [ 0 ] = 2 ;
V_309 [ 1 ] = V_189 [ 0 ] ;
V_309 [ 2 ] = V_189 [ 1 ] ;
if ( V_6 -> V_307 < 8 )
V_309 [ 1 ] |= ( 1 << ( V_6 -> V_307 % 8 ) ) ;
else
V_309 [ 2 ] |= ( 1 << ( V_6 -> V_307 % 8 ) ) ;
V_18 = F_6 ( V_2 , V_6 -> V_310 ,
V_309 , sizeof( V_309 ) ) ;
if ( V_18 )
return V_18 ;
if ( V_6 -> V_307 < 8 )
V_309 [ 1 ] &= ~ ( 1 << ( V_6 -> V_307 % 8 ) ) ;
else
V_309 [ 2 ] &= ~ ( 1 << ( V_6 -> V_307 % 8 ) ) ;
V_18 = F_6 ( V_2 , V_6 -> V_310 ,
V_309 , sizeof( V_309 ) ) ;
return V_18 ;
}
static int F_127 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_18 ;
if ( V_6 -> V_65 != V_67 )
return 0 ;
V_18 = F_12 ( V_2 ) ;
if ( V_18 )
return V_18 ;
if ( V_6 -> V_311 == V_312 )
V_18 = F_126 ( V_2 ) ;
else if ( V_6 -> V_311 == V_313 )
V_18 = F_125 ( V_2 ) ;
F_10 ( V_2 ) ;
return V_18 ;
}
static bool F_128 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_251 )
return false ;
if ( V_6 -> V_265 >= V_314 )
return true ;
switch ( V_6 -> V_315 ) {
case V_316 :
if ( V_6 -> V_262 > 3 )
return true ;
break;
case V_317 :
if ( V_6 -> V_262 > 1 )
return true ;
break;
default:
return true ;
}
return false ;
}
static int F_129 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned int V_11 ;
if ( V_6 -> V_65 != V_67 )
return 0 ;
V_11 = F_17 ( V_2 , V_289 ) ;
V_6 -> V_311 = F_120 ( V_11 , V_289 , V_318 ) ;
switch ( V_6 -> V_311 ) {
case V_319 :
case V_312 :
case V_313 :
break;
default:
F_130 ( V_2 -> V_176 , L_37 ,
V_6 -> V_311 ) ;
return - V_180 ;
}
if ( V_6 -> V_311 == V_312 ) {
V_6 -> V_310 = V_290 +
F_120 ( V_11 , V_289 ,
V_320 ) ;
V_6 -> V_307 = F_120 ( V_11 , V_289 ,
V_321 ) ;
} else if ( V_6 -> V_311 == V_313 ) {
V_6 -> V_307 = F_120 ( V_11 , V_289 ,
V_322 ) ;
}
return 0 ;
}
static bool F_131 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
switch ( V_6 -> V_127 ) {
case V_238 :
if ( ( V_6 -> V_94 & V_96 ) ||
( V_6 -> V_94 & V_105 ) )
return false ;
break;
case V_252 :
if ( V_6 -> V_94 & V_323 )
return false ;
break;
case V_253 :
if ( ( V_6 -> V_94 & V_95 ) ||
( V_6 -> V_94 & V_96 ) )
return false ;
break;
case V_242 :
if ( V_6 -> V_94 & V_96 )
return false ;
break;
case V_254 :
if ( ( V_6 -> V_94 & V_95 ) ||
( V_6 -> V_94 & V_96 ) ||
( V_6 -> V_94 & V_323 ) )
return false ;
break;
case V_255 :
if ( ( V_6 -> V_94 & V_95 ) ||
( V_6 -> V_94 & V_96 ) ||
( V_6 -> V_94 & V_105 ) )
return false ;
break;
case V_256 :
if ( V_6 -> V_94 & V_105 )
return false ;
break;
case V_128 :
if ( ( V_6 -> V_94 & V_95 ) ||
( V_6 -> V_94 & V_96 ) ||
( V_6 -> V_94 & V_105 ) )
return false ;
break;
default:
break;
}
return true ;
}
static bool F_132 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
switch ( V_6 -> V_127 ) {
case V_238 :
case V_252 :
if ( V_6 -> V_65 == V_324 )
return false ;
break;
case V_253 :
case V_242 :
case V_254 :
case V_255 :
case V_256 :
if ( V_6 -> V_65 == V_67 )
return false ;
break;
case V_128 :
if ( V_6 -> V_65 == V_66 )
return false ;
break;
default:
break;
}
return true ;
}
static bool F_133 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
V_11 = F_17 ( V_2 , V_325 ) ;
if ( ! F_120 ( V_11 , V_325 , V_326 ) )
return false ;
if ( ! F_120 ( V_11 , V_325 , V_327 ) )
return false ;
return true ;
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_32 ( V_2 ) ;
F_58 ( V_6 ) ;
F_57 ( V_2 ) ;
F_82 ( V_2 ) ;
V_2 -> V_9 . V_328 ( V_2 ) ;
}
static int F_135 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_18 ;
V_18 = V_2 -> V_9 . V_329 ( V_2 ) ;
if ( V_18 )
return V_18 ;
if ( V_6 -> V_251 && ! V_6 -> V_265 ) {
V_18 = V_2 -> V_57 . V_130 ( V_2 , V_6 -> V_23 ,
V_56 ) ;
if ( V_18 ) {
F_19 ( V_2 -> V_30 ,
L_38 ,
V_6 -> V_23 ) ;
return V_18 ;
}
}
F_101 ( V_2 , V_6 -> V_330 ) ;
switch ( V_6 -> V_127 ) {
case V_128 :
F_59 ( V_2 ) ;
break;
default:
break;
}
V_18 = F_39 ( V_2 ) ;
if ( V_18 )
goto V_331;
return 0 ;
V_331:
V_2 -> V_9 . V_328 ( V_2 ) ;
return V_18 ;
}
static int F_136 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
enum V_218 V_279 ;
int V_18 ;
V_279 = V_6 -> V_279 ;
F_82 ( V_2 ) ;
F_101 ( V_2 , V_279 ) ;
if ( ! V_6 -> V_120 )
return 0 ;
V_18 = F_127 ( V_2 ) ;
if ( V_18 )
return V_18 ;
return F_137 ( V_6 -> V_120 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_139 ( V_6 -> V_63 ) ;
}
static int F_140 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = & V_2 -> V_72 . V_71 ;
struct V_5 * V_6 ;
struct V_62 * V_63 ;
unsigned int V_11 ;
int V_18 ;
if ( ! F_133 ( V_2 ) ) {
F_141 ( V_2 -> V_176 , L_39 ) ;
return - V_132 ;
}
V_18 = V_2 -> V_9 . V_332 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_6 = F_142 ( V_2 -> V_176 , sizeof( * V_6 ) , V_333 ) ;
if ( ! V_6 )
return - V_334 ;
V_2 -> V_6 = V_6 ;
V_11 = F_17 ( V_2 , V_325 ) ;
V_6 -> V_127 = F_120 ( V_11 , V_325 , V_335 ) ;
V_6 -> V_46 = F_120 ( V_11 , V_325 , V_336 ) ;
V_6 -> V_94 = F_120 ( V_11 , V_325 , V_326 ) ;
V_6 -> V_65 = F_120 ( V_11 , V_325 , V_327 ) ;
V_6 -> V_131 = F_120 ( V_11 , V_325 , V_337 ) ;
if ( F_121 ( V_2 ) ) {
F_122 ( V_2 -> V_176 , L_40 , V_6 -> V_127 ) ;
F_122 ( V_2 -> V_176 , L_41 , V_6 -> V_46 ) ;
F_122 ( V_2 -> V_176 , L_42 , V_6 -> V_94 ) ;
F_122 ( V_2 -> V_176 , L_43 , V_6 -> V_65 ) ;
F_122 ( V_2 -> V_176 , L_44 , V_6 -> V_131 ) ;
}
V_11 = F_17 ( V_2 , V_300 ) ;
V_6 -> V_251 = F_120 ( V_11 , V_300 , V_338 ) ;
V_6 -> V_265 = F_120 ( V_11 , V_300 , V_339 ) ;
V_6 -> V_23 = F_120 ( V_11 , V_300 , V_340 ) ;
V_6 -> V_262 = F_120 ( V_11 , V_300 , V_341 ) ;
V_6 -> V_315 = F_120 ( V_11 , V_300 , V_342 ) ;
if ( V_6 -> V_251 && F_121 ( V_2 ) ) {
F_122 ( V_2 -> V_176 , L_45 ) ;
F_122 ( V_2 -> V_176 , L_46 , V_6 -> V_265 ) ;
F_122 ( V_2 -> V_176 , L_47 , V_6 -> V_23 ) ;
F_122 ( V_2 -> V_176 , L_48 , V_6 -> V_262 ) ;
F_122 ( V_2 -> V_176 , L_49 , V_6 -> V_315 ) ;
}
if ( F_132 ( V_2 ) ) {
F_130 ( V_2 -> V_176 , L_50 ,
V_6 -> V_127 , V_6 -> V_65 ) ;
return - V_180 ;
}
if ( F_131 ( V_2 ) ) {
F_130 ( V_2 -> V_176 , L_51 ,
V_6 -> V_127 , V_6 -> V_94 ) ;
return - V_180 ;
}
V_18 = F_129 ( V_2 ) ;
if ( V_18 )
return V_18 ;
if ( F_128 ( V_6 ) ) {
F_130 ( V_2 -> V_176 , L_52 ) ;
return - V_180 ;
}
V_2 -> V_343 = V_6 -> V_251 ;
V_6 -> V_279 = V_225 ;
F_28 ( V_71 ) ;
switch ( V_6 -> V_127 ) {
case V_238 :
F_29 ( V_71 , V_82 ) ;
F_29 ( V_71 , V_83 ) ;
F_29 ( V_71 , V_84 ) ;
F_29 ( V_71 , V_234 ) ;
if ( V_6 -> V_94 & V_96 ) {
F_29 ( V_71 , 1000baseKX_Full ) ;
V_6 -> V_330 = V_241 ;
}
if ( V_6 -> V_94 & V_105 ) {
F_29 ( V_71 , 10000baseKR_Full ) ;
if ( V_2 -> V_344 & V_345 )
F_29 ( V_71 , 10000baseR_FEC ) ;
V_6 -> V_330 = V_239 ;
}
V_6 -> V_53 = V_126 ;
break;
case V_252 :
F_29 ( V_71 , V_83 ) ;
F_29 ( V_71 , V_84 ) ;
F_29 ( V_71 , V_234 ) ;
F_29 ( V_71 , 2500baseX_Full ) ;
V_6 -> V_330 = V_280 ;
V_6 -> V_53 = V_126 ;
break;
case V_253 :
F_29 ( V_71 , V_82 ) ;
F_29 ( V_71 , V_83 ) ;
F_29 ( V_71 , V_84 ) ;
F_29 ( V_71 , V_85 ) ;
if ( V_6 -> V_94 & V_95 ) {
F_29 ( V_71 , 100baseT_Full ) ;
V_6 -> V_330 = V_224 ;
}
if ( V_6 -> V_94 & V_96 ) {
F_29 ( V_71 , 1000baseT_Full ) ;
V_6 -> V_330 = V_227 ;
}
V_6 -> V_53 = V_56 ;
break;
case V_242 :
F_29 ( V_71 , V_82 ) ;
F_29 ( V_71 , V_83 ) ;
F_29 ( V_71 , V_84 ) ;
F_29 ( V_71 , V_86 ) ;
F_29 ( V_71 , 1000baseX_Full ) ;
V_6 -> V_330 = V_233 ;
V_6 -> V_53 = V_56 ;
break;
case V_254 :
F_29 ( V_71 , V_82 ) ;
F_29 ( V_71 , V_83 ) ;
F_29 ( V_71 , V_84 ) ;
F_29 ( V_71 , V_85 ) ;
if ( V_6 -> V_94 & V_95 ) {
F_29 ( V_71 , 100baseT_Full ) ;
V_6 -> V_330 = V_224 ;
}
if ( V_6 -> V_94 & V_96 ) {
F_29 ( V_71 , 1000baseT_Full ) ;
V_6 -> V_330 = V_227 ;
}
if ( V_6 -> V_94 & V_323 ) {
F_29 ( V_71 , 2500baseT_Full ) ;
V_6 -> V_330 = V_280 ;
}
V_6 -> V_53 = V_54 ;
break;
case V_255 :
F_29 ( V_71 , V_82 ) ;
F_29 ( V_71 , V_83 ) ;
F_29 ( V_71 , V_84 ) ;
F_29 ( V_71 , V_85 ) ;
if ( V_6 -> V_94 & V_95 ) {
F_29 ( V_71 , 100baseT_Full ) ;
V_6 -> V_330 = V_224 ;
}
if ( V_6 -> V_94 & V_96 ) {
F_29 ( V_71 , 1000baseT_Full ) ;
V_6 -> V_330 = V_227 ;
}
if ( V_6 -> V_94 & V_105 ) {
F_29 ( V_71 , 10000baseT_Full ) ;
V_6 -> V_330 = V_239 ;
}
V_6 -> V_53 = V_54 ;
break;
case V_256 :
F_29 ( V_71 , V_82 ) ;
F_29 ( V_71 , V_83 ) ;
F_29 ( V_71 , V_84 ) ;
F_29 ( V_71 , V_86 ) ;
F_29 ( V_71 , 10000baseSR_Full ) ;
F_29 ( V_71 , 10000baseLR_Full ) ;
F_29 ( V_71 , 10000baseLRM_Full ) ;
F_29 ( V_71 , 10000baseER_Full ) ;
if ( V_2 -> V_344 & V_345 )
F_29 ( V_71 , 10000baseR_FEC ) ;
V_6 -> V_330 = V_240 ;
V_6 -> V_53 = V_126 ;
break;
case V_128 :
F_29 ( V_71 , V_82 ) ;
F_29 ( V_71 , V_83 ) ;
F_29 ( V_71 , V_84 ) ;
F_29 ( V_71 , V_85 ) ;
F_29 ( V_71 , V_86 ) ;
if ( V_6 -> V_94 & V_95 )
V_6 -> V_330 = V_224 ;
if ( V_6 -> V_94 & V_96 )
V_6 -> V_330 = V_227 ;
if ( V_6 -> V_94 & V_105 )
V_6 -> V_330 = V_240 ;
V_6 -> V_53 = V_56 ;
F_124 ( V_2 ) ;
break;
default:
return - V_180 ;
}
if ( F_121 ( V_2 ) )
F_122 ( V_2 -> V_176 , L_53 ,
V_346 ,
V_71 -> V_135 . V_88 ) ;
if ( ( V_6 -> V_65 & V_67 ) &&
( V_6 -> V_53 != V_126 ) ) {
V_18 = V_2 -> V_57 . V_130 ( V_2 , V_6 -> V_131 ,
V_6 -> V_53 ) ;
if ( V_18 ) {
F_130 ( V_2 -> V_176 ,
L_54 ,
V_6 -> V_131 , V_6 -> V_53 ) ;
return - V_180 ;
}
}
if ( V_6 -> V_251 && ! V_6 -> V_265 ) {
V_18 = V_2 -> V_57 . V_130 ( V_2 , V_6 -> V_23 ,
V_56 ) ;
if ( V_18 ) {
F_130 ( V_2 -> V_176 ,
L_38 ,
V_6 -> V_23 ) ;
return - V_180 ;
}
}
V_63 = F_143 ( V_2 -> V_176 ) ;
if ( ! V_63 ) {
F_130 ( V_2 -> V_176 , L_55 ) ;
return - V_334 ;
}
V_63 -> V_64 = V_2 ;
V_63 -> V_347 = L_56 ;
V_63 -> V_348 = F_26 ;
V_63 -> V_349 = F_22 ;
V_63 -> V_350 = V_2 -> V_176 ;
V_63 -> V_351 = ~ 0 ;
snprintf ( V_63 -> V_352 , sizeof( V_63 -> V_352 ) , L_57 , F_144 ( V_2 -> V_176 ) ) ;
V_18 = F_145 ( V_63 ) ;
if ( V_18 ) {
F_130 ( V_2 -> V_176 , L_58 ) ;
return V_18 ;
}
V_6 -> V_63 = V_63 ;
return 0 ;
}
void F_146 ( struct V_353 * V_354 )
{
struct V_355 * V_356 = & V_354 -> V_356 ;
V_356 -> V_357 = F_140 ;
V_356 -> exit = F_138 ;
V_356 -> V_358 = F_136 ;
V_356 -> V_359 = F_135 ;
V_356 -> V_360 = F_134 ;
V_356 -> V_361 = F_116 ;
V_356 -> V_362 = F_115 ;
V_356 -> V_363 = F_109 ;
V_356 -> V_364 = F_101 ;
V_356 -> V_365 = F_100 ;
V_356 -> V_366 = F_94 ;
V_356 -> V_279 = F_90 ;
V_356 -> V_244 = F_74 ;
V_356 -> V_367 = F_72 ;
V_356 -> V_368 = F_69 ;
V_356 -> V_369 = F_68 ;
}
