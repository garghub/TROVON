int F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_7 ;
switch ( V_3 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
V_4 |= V_3 << 1 ;
break;
default:
return - V_13 ;
}
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_14 ) ;
return F_5 ( V_4 ) ;
}
int F_6 ( struct V_1 * V_2 , enum V_15 V_16 )
{
int V_17 = 10000 ;
T_1 V_4 ;
if ( V_2 -> V_18 >= V_19 ) {
while ( -- V_17 ) {
V_4 = F_2 ( V_2 -> V_5 , V_14 ) ;
if ( V_4 & V_20 )
F_7 ( 5 ) ;
else
break;
}
if ( V_17 <= 0 )
return - V_21 ;
}
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_22 ;
V_4 |= F_8 ( V_16 ) ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
if ( V_2 -> V_18 >= V_19 )
return 0 ;
V_17 = 10000 ;
while ( -- V_17 ) {
V_4 = F_2 ( V_2 -> V_5 , V_14 ) ;
if ( F_5 ( V_4 ) == V_16 )
return 0 ;
F_7 ( 5 ) ;
}
return - V_21 ;
}
static void F_9 ( T_2 * V_23 )
{
( * V_23 ) ++ ;
if ( * V_23 == ( V_24 - 1 ) )
* V_23 = 0 ;
}
static void F_10 ( struct V_25 * V_26 )
{
F_9 ( & V_26 -> V_27 ) ;
}
static void F_11 ( struct V_25 * V_26 )
{
F_9 ( & V_26 -> V_28 ) ;
}
void F_12 ( struct V_25 * V_26 , struct V_29 * V_30 ,
int V_31 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
V_30 -> V_32 = false ;
F_13 ( & V_30 -> V_33 ) ;
V_30 -> V_34 = 0 ;
if ( V_30 -> V_35 . V_31 == - V_36 )
V_30 -> V_35 . V_31 = V_31 ;
if ( V_30 -> V_37 )
F_14 ( V_2 -> V_38 ,
& V_30 -> V_35 , V_30 -> V_39 ) ;
V_30 -> V_37 = NULL ;
F_15 ( V_30 ) ;
F_16 ( & V_2 -> V_40 ) ;
F_17 ( & V_26 -> V_41 , & V_30 -> V_35 ) ;
F_18 ( & V_2 -> V_40 ) ;
if ( V_26 -> V_42 > 1 )
F_19 ( V_2 -> V_43 ) ;
}
int F_20 ( struct V_1 * V_2 , unsigned V_44 , T_1 V_45 )
{
T_1 V_46 = 500 ;
int V_31 = 0 ;
int V_47 = 0 ;
T_1 V_4 ;
F_3 ( V_2 -> V_5 , V_48 , V_45 ) ;
F_3 ( V_2 -> V_5 , V_49 , V_44 | V_50 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , V_49 ) ;
if ( ! ( V_4 & V_50 ) ) {
V_31 = F_21 ( V_4 ) ;
if ( V_31 )
V_47 = - V_13 ;
break;
}
} while ( -- V_46 );
if ( ! V_46 ) {
V_47 = - V_21 ;
V_31 = - V_21 ;
}
F_22 ( V_44 , V_45 , V_31 ) ;
return V_47 ;
}
int F_23 ( struct V_25 * V_26 , unsigned V_44 ,
struct V_51 * V_52 )
{
const struct V_53 * V_54 = V_26 -> V_41 . V_54 ;
struct V_1 * V_2 = V_26 -> V_2 ;
T_1 V_46 = 500 ;
T_1 V_4 ;
int V_55 = 0 ;
int V_56 = false ;
int V_47 = - V_13 ;
if ( V_2 -> V_57 . V_58 <= V_59 ) {
V_4 = F_2 ( V_2 -> V_5 , F_24 ( 0 ) ) ;
if ( F_25 ( V_4 & V_60 ) ) {
V_56 = true ;
V_4 &= ~ V_60 ;
F_3 ( V_2 -> V_5 , F_24 ( 0 ) , V_4 ) ;
}
}
if ( F_26 ( V_44 ) == V_61 ) {
int V_62 ;
V_62 = ( V_2 -> V_63 == V_64 ||
V_2 -> V_63 == V_65 ||
V_2 -> V_63 == V_66 ) ;
if ( F_25 ( V_62 ) ) {
V_47 = F_27 ( V_2 ) ;
F_28 ( V_2 -> V_43 , V_47 , L_1 ,
V_47 ) ;
}
}
F_3 ( V_26 -> V_5 , V_67 , V_52 -> V_68 ) ;
F_3 ( V_26 -> V_5 , V_69 , V_52 -> V_70 ) ;
F_3 ( V_26 -> V_5 , V_71 , V_52 -> V_72 ) ;
if ( F_26 ( V_44 ) == V_73 &&
! F_29 ( V_54 ) )
V_44 &= ~ ( V_74 | V_75 ) ;
else
V_44 |= V_75 ;
F_3 ( V_26 -> V_5 , V_76 , V_44 ) ;
do {
V_4 = F_2 ( V_26 -> V_5 , V_76 ) ;
if ( ! ( V_4 & V_75 ) ) {
V_55 = F_30 ( V_4 ) ;
switch ( V_55 ) {
case 0 :
V_47 = 0 ;
break;
case V_77 :
V_47 = - V_13 ;
break;
case V_78 :
V_47 = - V_79 ;
break;
default:
F_31 ( V_2 -> V_43 , L_2 ) ;
}
break;
}
} while ( -- V_46 );
if ( V_46 == 0 ) {
V_47 = - V_21 ;
V_55 = - V_21 ;
}
F_32 ( V_26 , V_44 , V_52 , V_55 ) ;
if ( V_47 == 0 ) {
switch ( F_26 ( V_44 ) ) {
case V_61 :
V_26 -> V_80 |= V_81 ;
break;
case V_82 :
V_26 -> V_80 &= ~ V_81 ;
break;
default:
break;
}
}
if ( F_25 ( V_56 ) ) {
V_4 = F_2 ( V_2 -> V_5 , F_24 ( 0 ) ) ;
V_4 |= V_60 ;
F_3 ( V_2 -> V_5 , F_24 ( 0 ) , V_4 ) ;
}
return V_47 ;
}
static int F_33 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_51 V_52 ;
T_1 V_44 = V_83 ;
if ( V_26 -> V_39 && ( V_2 -> V_18 >= V_84 ) &&
( V_2 -> V_57 . V_58 >= V_85 ) )
V_44 |= V_86 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
return F_23 ( V_26 , V_44 , & V_52 ) ;
}
static T_3 F_34 ( struct V_25 * V_26 ,
struct V_87 * V_37 )
{
T_1 V_88 = ( char * ) V_37 - ( char * ) V_26 -> V_89 ;
return V_26 -> V_90 + V_88 ;
}
static int F_35 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
if ( V_26 -> V_89 )
return 0 ;
V_26 -> V_89 = F_36 ( V_2 -> V_38 ,
sizeof( struct V_87 ) * V_24 ,
& V_26 -> V_90 , V_91 ) ;
if ( ! V_26 -> V_89 ) {
F_37 ( V_26 -> V_2 -> V_43 , L_3 ,
V_26 -> V_92 ) ;
return - V_93 ;
}
return 0 ;
}
static void F_38 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
F_39 ( V_2 -> V_38 , sizeof( struct V_87 ) * V_24 ,
V_26 -> V_89 , V_26 -> V_90 ) ;
V_26 -> V_89 = NULL ;
V_26 -> V_90 = 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_51 V_52 ;
T_1 V_44 ;
int V_94 ;
int V_47 ;
if ( V_26 -> V_42 )
return 0 ;
memset ( & V_52 , 0x00 , sizeof( V_52 ) ) ;
V_44 = V_95 ;
V_47 = F_23 ( V_26 , V_44 , & V_52 ) ;
if ( V_47 )
return V_47 ;
for ( V_94 = 0 ; V_94 < V_96 ; V_94 ++ ) {
struct V_25 * V_26 = V_2 -> V_97 [ V_94 ] ;
if ( ! V_26 )
continue;
V_47 = F_41 ( V_2 , V_26 ) ;
if ( V_47 )
return V_47 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_25 * V_26 ,
bool V_98 , bool V_99 )
{
const struct V_100 * V_101 ;
const struct V_53 * V_54 ;
struct V_51 V_52 ;
if ( F_28 ( V_2 -> V_43 , V_98 && V_99 ,
L_4 ) )
return - V_13 ;
V_101 = V_26 -> V_41 . V_101 ;
V_54 = V_26 -> V_41 . V_54 ;
memset ( & V_52 , 0x00 , sizeof( V_52 ) ) ;
V_52 . V_68 = F_43 ( F_44 ( V_54 ) )
| F_45 ( F_46 ( V_54 ) ) ;
if ( V_2 -> V_57 . V_58 >= V_85 ) {
T_1 V_102 = V_26 -> V_41 . V_103 ;
V_52 . V_68 |= F_47 ( V_102 - 1 ) ;
}
if ( V_98 ) {
V_52 . V_68 |= V_104 ;
} else if ( V_99 ) {
V_52 . V_68 |= V_105 ;
V_52 . V_72 |= V_26 -> V_106 ;
} else {
V_52 . V_68 |= V_107 ;
}
if ( F_48 ( V_54 ) )
V_52 . V_70 = V_108 ;
if ( V_26 -> V_42 <= 1 || F_29 ( V_54 ) )
V_52 . V_70 |= V_109 ;
if ( F_49 ( V_101 ) && F_50 ( V_54 ) ) {
V_52 . V_70 |= V_110
| V_111 ;
V_26 -> V_112 = true ;
}
if ( ! F_48 ( V_54 ) )
V_52 . V_70 |= V_113 ;
V_52 . V_70 |= F_51 ( V_26 -> V_42 ) ;
if ( V_26 -> V_39 )
V_52 . V_68 |= F_52 ( V_26 -> V_42 >> 1 ) ;
if ( V_54 -> V_114 ) {
V_52 . V_70 |= F_53 ( V_54 -> V_114 - 1 ) ;
V_26 -> V_115 = 1 << ( V_54 -> V_114 - 1 ) ;
}
return F_23 ( V_26 , V_116 , & V_52 ) ;
}
static int F_41 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_51 V_52 ;
memset ( & V_52 , 0x00 , sizeof( V_52 ) ) ;
V_52 . V_68 = F_54 ( 1 ) ;
return F_23 ( V_26 , V_117 ,
& V_52 ) ;
}
static int F_55 ( struct V_25 * V_26 ,
bool V_98 , bool V_99 )
{
const struct V_53 * V_54 = V_26 -> V_41 . V_54 ;
struct V_1 * V_2 = V_26 -> V_2 ;
T_1 V_4 ;
int V_47 ;
if ( ! ( V_26 -> V_80 & V_118 ) ) {
V_47 = F_40 ( V_2 , V_26 ) ;
if ( V_47 )
return V_47 ;
}
V_47 = F_42 ( V_2 , V_26 , V_98 , V_99 ) ;
if ( V_47 )
return V_47 ;
if ( ! ( V_26 -> V_80 & V_118 ) ) {
struct V_87 * V_119 ;
struct V_87 * V_120 ;
V_26 -> type = F_44 ( V_54 ) ;
V_26 -> V_80 |= V_118 ;
V_26 -> V_80 &= ~ V_121 ;
V_4 = F_2 ( V_2 -> V_5 , V_122 ) ;
V_4 |= F_56 ( V_26 -> V_42 ) ;
F_3 ( V_2 -> V_5 , V_122 , V_4 ) ;
F_57 ( & V_26 -> V_123 ) ;
if ( F_48 ( V_54 ) )
goto V_124;
V_26 -> V_28 = 0 ;
V_26 -> V_27 = 0 ;
memset ( V_26 -> V_89 , 0 ,
sizeof( struct V_87 ) * V_24 ) ;
V_119 = & V_26 -> V_89 [ 0 ] ;
V_120 = & V_26 -> V_89 [ V_24 - 1 ] ;
V_120 -> V_125 = F_58 ( F_34 ( V_26 , V_119 ) ) ;
V_120 -> V_126 = F_59 ( F_34 ( V_26 , V_119 ) ) ;
V_120 -> V_127 |= V_128 ;
V_120 -> V_127 |= V_129 ;
}
if ( F_50 ( V_54 ) ) {
struct V_51 V_52 ;
struct V_87 * V_37 ;
T_3 V_130 ;
T_1 V_44 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_37 = & V_26 -> V_89 [ 0 ] ;
V_130 = F_34 ( V_26 , V_37 ) ;
V_52 . V_68 = F_59 ( V_130 ) ;
V_52 . V_70 = F_58 ( V_130 ) ;
V_44 = V_61 ;
V_47 = F_23 ( V_26 , V_44 , & V_52 ) ;
if ( V_47 < 0 )
return V_47 ;
V_26 -> V_80 |= V_131 ;
V_26 -> V_132 = F_60 ( V_26 ) ;
F_61 ( ! V_26 -> V_132 ) ;
}
V_124:
F_62 ( V_26 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_29 * V_30 ;
F_64 ( V_2 , V_26 -> V_42 , true ) ;
while ( ! F_65 ( & V_26 -> V_133 ) ) {
V_30 = F_66 ( & V_26 -> V_133 ) ;
F_12 ( V_26 , V_30 , - V_134 ) ;
}
while ( ! F_65 ( & V_26 -> V_135 ) ) {
V_30 = F_66 ( & V_26 -> V_135 ) ;
F_12 ( V_26 , V_30 , - V_134 ) ;
}
}
static int F_67 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
T_1 V_4 ;
F_68 ( V_26 ) ;
F_63 ( V_2 , V_26 ) ;
if ( V_26 -> V_80 & V_136 )
F_69 ( V_26 , 0 , false ) ;
V_4 = F_2 ( V_2 -> V_5 , V_122 ) ;
V_4 &= ~ F_56 ( V_26 -> V_42 ) ;
F_3 ( V_2 -> V_5 , V_122 , V_4 ) ;
V_26 -> V_112 = false ;
V_26 -> type = 0 ;
V_26 -> V_80 &= V_121 ;
if ( V_26 -> V_42 > 1 ) {
V_26 -> V_41 . V_101 = NULL ;
V_26 -> V_41 . V_54 = NULL ;
}
return 0 ;
}
static int F_70 ( struct V_137 * V_138 ,
const struct V_53 * V_54 )
{
return - V_13 ;
}
static int F_71 ( struct V_137 * V_138 )
{
return - V_13 ;
}
static int F_72 ( struct V_137 * V_138 ,
const struct V_53 * V_54 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
unsigned long V_80 ;
int V_47 ;
if ( ! V_138 || ! V_54 || V_54 -> V_139 != V_140 ) {
F_73 ( L_5 ) ;
return - V_13 ;
}
if ( ! V_54 -> V_141 ) {
F_73 ( L_6 ) ;
return - V_13 ;
}
V_26 = F_74 ( V_138 ) ;
V_2 = V_26 -> V_2 ;
if ( F_28 ( V_2 -> V_43 , V_26 -> V_80 & V_118 ,
L_7 ,
V_26 -> V_92 ) )
return 0 ;
F_75 ( & V_2 -> V_40 , V_80 ) ;
V_47 = F_55 ( V_26 , false , false ) ;
F_76 ( & V_2 -> V_40 , V_80 ) ;
return V_47 ;
}
static int F_77 ( struct V_137 * V_138 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
unsigned long V_80 ;
int V_47 ;
if ( ! V_138 ) {
F_73 ( L_5 ) ;
return - V_13 ;
}
V_26 = F_74 ( V_138 ) ;
V_2 = V_26 -> V_2 ;
if ( F_28 ( V_2 -> V_43 , ! ( V_26 -> V_80 & V_118 ) ,
L_8 ,
V_26 -> V_92 ) )
return 0 ;
F_75 ( & V_2 -> V_40 , V_80 ) ;
V_47 = F_67 ( V_26 ) ;
F_76 ( & V_2 -> V_40 , V_80 ) ;
return V_47 ;
}
static struct V_142 * F_78 ( struct V_137 * V_138 ,
T_4 V_143 )
{
struct V_29 * V_30 ;
struct V_25 * V_26 = F_74 ( V_138 ) ;
V_30 = F_79 ( sizeof( * V_30 ) , V_143 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_144 = V_26 -> V_42 ;
V_30 -> V_26 = V_26 ;
V_26 -> V_145 ++ ;
F_80 ( V_30 ) ;
return & V_30 -> V_35 ;
}
static void F_81 ( struct V_137 * V_138 ,
struct V_142 * V_35 )
{
struct V_29 * V_30 = F_82 ( V_35 ) ;
struct V_25 * V_26 = F_74 ( V_138 ) ;
V_26 -> V_145 -- ;
F_83 ( V_30 ) ;
F_84 ( V_30 ) ;
}
static void F_85 ( struct V_25 * V_26 , struct V_87 * V_37 ,
T_3 V_146 , unsigned V_147 , unsigned V_148 , unsigned V_149 ,
unsigned V_150 , unsigned V_151 , unsigned V_152 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_153 * V_57 = & V_2 -> V_57 ;
enum V_154 V_58 = V_57 -> V_58 ;
F_10 ( V_26 ) ;
V_37 -> V_155 = F_86 ( V_147 ) ;
V_37 -> V_125 = F_58 ( V_146 ) ;
V_37 -> V_126 = F_59 ( V_146 ) ;
switch ( F_44 ( V_26 -> V_41 . V_54 ) ) {
case V_156 :
V_37 -> V_127 = V_157 ;
break;
case V_158 :
if ( ! V_149 ) {
V_37 -> V_127 = V_159 ;
if ( V_58 == V_59 ) {
struct V_137 * V_138 = & V_26 -> V_41 ;
unsigned int V_160 = V_138 -> V_160 - 1 ;
unsigned int V_161 = F_46 ( V_138 -> V_54 ) ;
if ( V_147 <= ( 2 * V_161 ) )
V_160 -- ;
if ( V_147 <= V_161 )
V_160 -- ;
V_37 -> V_155 |= F_87 ( V_160 ) ;
}
} else {
V_37 -> V_127 = V_162 ;
}
V_37 -> V_127 |= V_163 ;
break;
case V_164 :
case V_165 :
V_37 -> V_127 = V_166 ;
break;
default:
F_31 ( V_2 -> V_43 , L_9 ,
F_44 ( V_26 -> V_41 . V_54 ) ) ;
}
if ( F_88 ( V_26 -> V_41 . V_54 ) ) {
V_37 -> V_127 |= V_167 ;
if ( V_151 )
V_37 -> V_127 |= V_163 ;
}
if ( ( ! V_152 && ! V_148 ) ||
( F_89 ( V_26 ) == 0 ) )
V_37 -> V_127 |= V_168 ;
if ( V_148 )
V_37 -> V_127 |= V_169 ;
if ( F_50 ( V_26 -> V_41 . V_54 ) && V_26 -> V_112 )
V_37 -> V_127 |= F_90 ( V_150 ) ;
V_37 -> V_127 |= V_129 ;
F_91 ( V_26 , V_37 ) ;
}
static void F_92 ( struct V_25 * V_26 ,
struct V_29 * V_30 , unsigned V_148 , unsigned V_149 )
{
struct V_87 * V_37 ;
unsigned V_147 = V_30 -> V_35 . V_147 ;
unsigned V_150 = V_30 -> V_35 . V_150 ;
unsigned V_151 = V_30 -> V_35 . V_151 ;
unsigned V_152 = V_30 -> V_35 . V_152 ;
T_3 V_146 = V_30 -> V_35 . V_146 ;
V_37 = & V_26 -> V_89 [ V_26 -> V_27 ] ;
if ( ! V_30 -> V_37 ) {
F_93 ( V_30 ) ;
V_30 -> V_37 = V_37 ;
V_30 -> V_130 = F_34 ( V_26 , V_37 ) ;
V_26 -> V_170 ++ ;
}
F_85 ( V_26 , V_37 , V_146 , V_147 , V_148 , V_149 ,
V_150 , V_151 , V_152 ) ;
}
static struct V_87 * F_94 ( struct V_25 * V_26 , T_2 V_23 )
{
T_2 V_171 = V_23 ;
if ( ! V_171 )
V_171 = V_24 - 1 ;
return & V_26 -> V_89 [ V_171 - 1 ] ;
}
static T_1 F_89 ( struct V_25 * V_26 )
{
struct V_87 * V_171 ;
T_2 V_172 ;
if ( V_26 -> V_27 == V_26 -> V_28 ) {
V_171 = F_94 ( V_26 , V_26 -> V_27 ) ;
if ( V_171 -> V_127 & V_129 )
return 0 ;
return V_24 - 1 ;
}
V_172 = V_26 -> V_28 - V_26 -> V_27 ;
V_172 &= ( V_24 - 1 ) ;
if ( V_26 -> V_28 < V_26 -> V_27 )
V_172 -- ;
return V_172 ;
}
static void F_95 ( struct V_25 * V_26 ,
struct V_29 * V_30 )
{
struct V_173 * V_174 = V_30 -> V_174 ;
struct V_173 * V_175 ;
int V_94 ;
F_96 (sg, s, req->num_pending_sgs, i) {
unsigned int V_147 = V_30 -> V_35 . V_147 ;
unsigned int V_161 = F_46 ( V_26 -> V_41 . V_54 ) ;
unsigned int V_176 = V_147 % V_161 ;
unsigned V_148 = true ;
if ( F_97 ( V_175 ) )
V_148 = false ;
if ( V_176 && F_88 ( V_26 -> V_41 . V_54 ) && ! V_148 ) {
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_87 * V_37 ;
V_30 -> V_177 = true ;
F_92 ( V_26 , V_30 , true , V_94 ) ;
V_37 = & V_26 -> V_89 [ V_26 -> V_27 ] ;
F_85 ( V_26 , V_37 , V_2 -> V_178 ,
V_161 - V_176 , false , 0 ,
V_30 -> V_35 . V_150 ,
V_30 -> V_35 . V_151 ,
V_30 -> V_35 . V_152 ) ;
} else {
F_92 ( V_26 , V_30 , V_148 , V_94 ) ;
}
if ( ! F_89 ( V_26 ) )
break;
}
}
static void F_98 ( struct V_25 * V_26 ,
struct V_29 * V_30 )
{
unsigned int V_147 = V_30 -> V_35 . V_147 ;
unsigned int V_161 = F_46 ( V_26 -> V_41 . V_54 ) ;
unsigned int V_176 = V_147 % V_161 ;
if ( V_176 && F_88 ( V_26 -> V_41 . V_54 ) ) {
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_87 * V_37 ;
V_30 -> V_177 = true ;
F_92 ( V_26 , V_30 , true , 0 ) ;
V_37 = & V_26 -> V_89 [ V_26 -> V_27 ] ;
F_85 ( V_26 , V_37 , V_2 -> V_178 , V_161 - V_176 ,
false , 0 , V_30 -> V_35 . V_150 ,
V_30 -> V_35 . V_151 ,
V_30 -> V_35 . V_152 ) ;
} else if ( V_30 -> V_35 . V_179 && V_30 -> V_35 . V_147 &&
( F_99 ( V_30 -> V_35 . V_147 , V_26 -> V_41 . V_180 ) ) ) {
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_87 * V_37 ;
V_30 -> V_179 = true ;
F_92 ( V_26 , V_30 , true , 0 ) ;
V_37 = & V_26 -> V_89 [ V_26 -> V_27 ] ;
F_85 ( V_26 , V_37 , V_2 -> V_178 , 0 ,
false , 0 , V_30 -> V_35 . V_150 ,
V_30 -> V_35 . V_151 ,
V_30 -> V_35 . V_152 ) ;
} else {
F_92 ( V_26 , V_30 , false , 0 ) ;
}
}
static void F_100 ( struct V_25 * V_26 )
{
struct V_29 * V_30 , * V_181 ;
F_101 ( V_24 ) ;
if ( ! F_89 ( V_26 ) )
return;
F_102 (req, &dep->started_list, list) {
if ( V_30 -> V_182 > 0 )
F_95 ( V_26 , V_30 ) ;
if ( ! F_89 ( V_26 ) )
return;
}
F_103 (req, n, &dep->pending_list, list) {
struct V_1 * V_2 = V_26 -> V_2 ;
int V_47 ;
V_47 = F_104 ( V_2 -> V_38 , & V_30 -> V_35 ,
V_26 -> V_39 ) ;
if ( V_47 )
return;
V_30 -> V_174 = V_30 -> V_35 . V_174 ;
V_30 -> V_182 = V_30 -> V_35 . V_183 ;
if ( V_30 -> V_182 > 0 )
F_95 ( V_26 , V_30 ) ;
else
F_98 ( V_26 , V_30 ) ;
if ( ! F_89 ( V_26 ) )
return;
}
}
static int F_105 ( struct V_25 * V_26 , T_5 V_184 )
{
struct V_51 V_52 ;
struct V_29 * V_30 ;
int V_185 ;
int V_47 ;
T_1 V_44 ;
V_185 = ! ( V_26 -> V_80 & V_131 ) ;
F_100 ( V_26 ) ;
V_30 = F_66 ( & V_26 -> V_133 ) ;
if ( ! V_30 ) {
V_26 -> V_80 |= V_186 ;
return 0 ;
}
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
if ( V_185 ) {
V_52 . V_68 = F_59 ( V_30 -> V_130 ) ;
V_52 . V_70 = F_58 ( V_30 -> V_130 ) ;
V_44 = V_61 |
F_106 ( V_184 ) ;
} else {
V_44 = V_73 |
F_106 ( V_26 -> V_132 ) ;
}
V_47 = F_23 ( V_26 , V_44 , & V_52 ) ;
if ( V_47 < 0 ) {
if ( V_30 -> V_37 )
memset ( V_30 -> V_37 , 0 , sizeof( struct V_87 ) ) ;
V_26 -> V_170 -- ;
F_12 ( V_26 , V_30 , V_47 ) ;
return V_47 ;
}
V_26 -> V_80 |= V_131 ;
if ( V_185 ) {
V_26 -> V_132 = F_60 ( V_26 ) ;
F_61 ( ! V_26 -> V_132 ) ;
}
return 0 ;
}
static int F_107 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_14 ) ;
return F_108 ( V_4 ) ;
}
static void F_109 ( struct V_1 * V_2 ,
struct V_25 * V_26 , T_1 V_187 )
{
T_1 V_188 ;
if ( F_65 ( & V_26 -> V_135 ) ) {
F_110 ( V_2 -> V_43 , L_10 ,
V_26 -> V_92 ) ;
V_26 -> V_80 |= V_186 ;
return;
}
V_188 = V_187 + F_111 ( T_1 , 4 , V_26 -> V_115 ) ;
F_105 ( V_26 , V_188 ) ;
}
static void F_112 ( struct V_1 * V_2 ,
struct V_25 * V_26 , const struct V_189 * V_190 )
{
T_1 V_187 , V_191 ;
V_191 = ~ ( V_26 -> V_115 - 1 ) ;
V_187 = V_190 -> V_192 & V_191 ;
F_109 ( V_2 , V_26 , V_187 ) ;
}
static int F_113 ( struct V_25 * V_26 , struct V_29 * V_30 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
int V_47 = 0 ;
if ( ! V_26 -> V_41 . V_54 ) {
F_37 ( V_2 -> V_43 , L_11 ,
V_26 -> V_92 ) ;
return - V_134 ;
}
if ( F_114 ( V_30 -> V_26 != V_26 , L_12 ,
& V_30 -> V_35 , V_30 -> V_26 -> V_92 ) )
return - V_13 ;
F_115 ( V_2 -> V_43 ) ;
V_30 -> V_35 . V_193 = 0 ;
V_30 -> V_35 . V_31 = - V_36 ;
V_30 -> V_39 = V_26 -> V_39 ;
V_30 -> V_144 = V_26 -> V_42 ;
F_116 ( V_30 ) ;
F_117 ( & V_30 -> V_33 , & V_26 -> V_135 ) ;
if ( F_29 ( V_26 -> V_41 . V_54 ) ) {
if ( ( V_26 -> V_80 & V_186 ) ) {
if ( V_26 -> V_80 & V_81 ) {
F_64 ( V_2 , V_26 -> V_42 , true ) ;
V_26 -> V_80 = V_118 ;
} else {
T_1 V_187 ;
V_187 = F_107 ( V_2 ) ;
F_109 ( V_2 , V_26 , V_187 ) ;
V_26 -> V_80 &= ~ V_186 ;
}
return 0 ;
}
if ( ( V_26 -> V_80 & V_131 ) &&
! ( V_26 -> V_80 & V_194 ) ) {
F_61 ( ! V_26 -> V_132 ) ;
V_47 = F_105 ( V_26 ,
V_26 -> V_132 ) ;
}
goto V_124;
}
if ( ! F_89 ( V_26 ) )
return 0 ;
V_47 = F_105 ( V_26 , 0 ) ;
V_124:
if ( V_47 == - V_195 )
V_47 = 0 ;
return V_47 ;
}
static int F_118 ( struct V_137 * V_138 , struct V_142 * V_35 ,
T_4 V_143 )
{
struct V_29 * V_30 = F_82 ( V_35 ) ;
struct V_25 * V_26 = F_74 ( V_138 ) ;
struct V_1 * V_2 = V_26 -> V_2 ;
unsigned long V_80 ;
int V_47 ;
F_75 ( & V_2 -> V_40 , V_80 ) ;
V_47 = F_113 ( V_26 , V_30 ) ;
F_76 ( & V_2 -> V_40 , V_80 ) ;
return V_47 ;
}
static int F_119 ( struct V_137 * V_138 ,
struct V_142 * V_35 )
{
struct V_29 * V_30 = F_82 ( V_35 ) ;
struct V_29 * V_196 = NULL ;
struct V_25 * V_26 = F_74 ( V_138 ) ;
struct V_1 * V_2 = V_26 -> V_2 ;
unsigned long V_80 ;
int V_47 = 0 ;
F_120 ( V_30 ) ;
F_75 ( & V_2 -> V_40 , V_80 ) ;
F_102 (r, &dep->pending_list, list) {
if ( V_196 == V_30 )
break;
}
if ( V_196 != V_30 ) {
F_102 (r, &dep->started_list, list) {
if ( V_196 == V_30 )
break;
}
if ( V_196 == V_30 ) {
F_64 ( V_2 , V_26 -> V_42 , true ) ;
F_121 ( V_26 -> V_123 ,
! ( V_26 -> V_80 & V_121 ) ,
V_2 -> V_40 ) ;
if ( ! V_196 -> V_37 )
goto V_197;
if ( V_196 -> V_182 ) {
struct V_87 * V_37 ;
int V_94 = 0 ;
for ( V_94 = 0 ; V_94 < V_196 -> V_182 ; V_94 ++ ) {
V_37 = V_196 -> V_37 + V_94 ;
V_37 -> V_127 &= ~ V_129 ;
F_11 ( V_26 ) ;
}
if ( V_196 -> V_177 || V_196 -> V_179 ) {
V_37 = V_196 -> V_37 + V_196 -> V_182 + 1 ;
V_37 -> V_127 &= ~ V_129 ;
F_11 ( V_26 ) ;
}
} else {
struct V_87 * V_37 = V_196 -> V_37 ;
V_37 -> V_127 &= ~ V_129 ;
F_11 ( V_26 ) ;
if ( V_196 -> V_177 || V_196 -> V_179 ) {
V_37 = V_196 -> V_37 + 1 ;
V_37 -> V_127 &= ~ V_129 ;
F_11 ( V_26 ) ;
}
}
goto V_197;
}
F_37 ( V_2 -> V_43 , L_13 ,
V_35 , V_138 -> V_92 ) ;
V_47 = - V_13 ;
goto V_198;
}
V_197:
V_26 -> V_170 -- ;
F_12 ( V_26 , V_30 , - V_199 ) ;
V_198:
F_76 ( & V_2 -> V_40 , V_80 ) ;
return V_47 ;
}
int F_69 ( struct V_25 * V_26 , int V_200 , int V_201 )
{
struct V_51 V_52 ;
struct V_1 * V_2 = V_26 -> V_2 ;
int V_47 ;
if ( F_29 ( V_26 -> V_41 . V_54 ) ) {
F_37 ( V_2 -> V_43 , L_14 , V_26 -> V_92 ) ;
return - V_13 ;
}
memset ( & V_52 , 0x00 , sizeof( V_52 ) ) ;
if ( V_200 ) {
struct V_87 * V_37 ;
unsigned V_202 ;
unsigned V_32 ;
if ( V_26 -> V_80 & V_136 )
return 0 ;
if ( V_26 -> V_42 > 1 )
V_37 = F_94 ( V_26 , V_26 -> V_27 ) ;
else
V_37 = & V_2 -> V_203 [ V_26 -> V_27 ] ;
V_202 = V_37 -> V_127 & V_129 ;
V_32 = ! F_65 ( & V_26 -> V_133 ) ;
if ( ! V_201 && ( ( V_26 -> V_39 && V_202 ) ||
( ! V_26 -> V_39 && V_32 ) ) ) {
return - V_79 ;
}
V_47 = F_23 ( V_26 , V_204 ,
& V_52 ) ;
if ( V_47 )
F_37 ( V_2 -> V_43 , L_15 ,
V_26 -> V_92 ) ;
else
V_26 -> V_80 |= V_136 ;
} else {
if ( ! ( V_26 -> V_80 & V_136 ) )
return 0 ;
V_47 = F_33 ( V_26 ) ;
if ( V_47 )
F_37 ( V_2 -> V_43 , L_16 ,
V_26 -> V_92 ) ;
else
V_26 -> V_80 &= ~ ( V_136 | V_205 ) ;
}
return V_47 ;
}
static int F_122 ( struct V_137 * V_138 , int V_200 )
{
struct V_25 * V_26 = F_74 ( V_138 ) ;
struct V_1 * V_2 = V_26 -> V_2 ;
unsigned long V_80 ;
int V_47 ;
F_75 ( & V_2 -> V_40 , V_80 ) ;
V_47 = F_69 ( V_26 , V_200 , false ) ;
F_76 ( & V_2 -> V_40 , V_80 ) ;
return V_47 ;
}
static int F_123 ( struct V_137 * V_138 )
{
struct V_25 * V_26 = F_74 ( V_138 ) ;
struct V_1 * V_2 = V_26 -> V_2 ;
unsigned long V_80 ;
int V_47 ;
F_75 ( & V_2 -> V_40 , V_80 ) ;
V_26 -> V_80 |= V_205 ;
if ( V_26 -> V_42 == 0 || V_26 -> V_42 == 1 )
V_47 = F_124 ( V_138 , 1 ) ;
else
V_47 = F_69 ( V_26 , 1 , false ) ;
F_76 ( & V_2 -> V_40 , V_80 ) ;
return V_47 ;
}
static int F_125 ( struct V_153 * V_206 )
{
struct V_1 * V_2 = F_126 ( V_206 ) ;
return F_107 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_17 ;
int V_47 ;
T_1 V_4 ;
T_2 V_63 ;
T_2 V_58 ;
V_4 = F_2 ( V_2 -> V_5 , V_14 ) ;
V_58 = V_4 & V_207 ;
if ( ( V_58 == V_208 ) ||
( V_58 == V_209 ) )
return 0 ;
V_63 = F_5 ( V_4 ) ;
switch ( V_63 ) {
case V_210 :
case V_66 :
break;
default:
return - V_13 ;
}
V_47 = F_6 ( V_2 , V_211 ) ;
if ( V_47 < 0 ) {
F_37 ( V_2 -> V_43 , L_17 ) ;
return V_47 ;
}
if ( V_2 -> V_18 < V_19 ) {
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_22 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
}
V_17 = 20000 ;
while ( V_17 -- ) {
V_4 = F_2 ( V_2 -> V_5 , V_14 ) ;
if ( F_5 ( V_4 ) == V_212 )
break;
}
if ( F_5 ( V_4 ) != V_212 ) {
F_37 ( V_2 -> V_43 , L_18 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_127 ( struct V_153 * V_206 )
{
struct V_1 * V_2 = F_126 ( V_206 ) ;
unsigned long V_80 ;
int V_47 ;
F_75 ( & V_2 -> V_40 , V_80 ) ;
V_47 = F_27 ( V_2 ) ;
F_76 ( & V_2 -> V_40 , V_80 ) ;
return V_47 ;
}
static int F_128 ( struct V_153 * V_206 ,
int V_213 )
{
struct V_1 * V_2 = F_126 ( V_206 ) ;
unsigned long V_80 ;
F_75 ( & V_2 -> V_40 , V_80 ) ;
V_206 -> V_213 = ! ! V_213 ;
F_76 ( & V_2 -> V_40 , V_80 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 , int V_214 , int V_215 )
{
T_1 V_4 ;
T_1 V_46 = 500 ;
if ( F_130 ( V_2 -> V_43 ) )
return 0 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
if ( V_214 ) {
if ( V_2 -> V_18 <= V_216 ) {
V_4 &= ~ V_217 ;
V_4 |= V_218 ;
}
if ( V_2 -> V_18 >= V_19 )
V_4 &= ~ V_219 ;
V_4 |= V_220 ;
if ( V_2 -> V_221 )
V_4 |= V_219 ;
V_2 -> V_222 = true ;
} else {
V_4 &= ~ V_220 ;
if ( V_2 -> V_221 && ! V_215 )
V_4 &= ~ V_219 ;
V_2 -> V_222 = false ;
}
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
do {
V_4 = F_2 ( V_2 -> V_5 , V_14 ) ;
V_4 &= V_223 ;
} while ( -- V_46 && ! ( ! V_214 ^ ! V_4 ) );
if ( ! V_46 )
return - V_21 ;
return 0 ;
}
static int F_131 ( struct V_153 * V_206 , int V_214 )
{
struct V_1 * V_2 = F_126 ( V_206 ) ;
unsigned long V_80 ;
int V_47 ;
V_214 = ! ! V_214 ;
if ( ! V_214 && V_2 -> V_224 != V_225 ) {
F_132 ( & V_2 -> V_226 ) ;
V_47 = F_133 ( & V_2 -> V_226 ,
F_134 ( V_227 ) ) ;
if ( V_47 == 0 ) {
F_37 ( V_2 -> V_43 , L_19 ) ;
return - V_21 ;
}
}
F_75 ( & V_2 -> V_40 , V_80 ) ;
V_47 = F_129 ( V_2 , V_214 , false ) ;
F_76 ( & V_2 -> V_40 , V_80 ) ;
return V_47 ;
}
static void F_135 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = ( V_228 |
V_229 |
V_230 |
V_231 |
V_232 |
V_233 |
V_234 |
V_235 ) ;
if ( V_2 -> V_18 < V_236 )
V_4 |= V_237 ;
F_3 ( V_2 -> V_5 , V_238 , V_4 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_5 , V_238 , 0x00 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
T_1 V_239 ;
T_1 V_240 ;
T_1 V_241 ;
T_1 V_4 ;
V_239 = F_138 ( V_2 -> V_242 . V_243 ) ;
V_240 = F_139 ( V_2 -> V_242 . V_244 ) ;
V_241 = ( ( V_239 * V_240 / 8 ) - 24 - 16 ) / 1024 ;
V_241 = F_140 ( T_1 , V_241 , 16 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_245 ) ;
V_4 &= ~ V_246 ;
V_4 |= V_241 << V_247 ;
F_3 ( V_2 -> V_5 , V_245 , V_4 ) ;
}
static int F_141 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
int V_47 = 0 ;
T_1 V_4 ;
if ( V_2 -> V_248 ) {
F_3 ( V_2 -> V_5 , F_142 ( 0 ) , V_2 -> V_248 ) ;
F_3 ( V_2 -> V_5 , F_143 ( 0 ) , V_249 ) ;
} else if ( F_144 ( V_2 ) ) {
F_3 ( V_2 -> V_5 , F_142 ( 0 ) , 0 ) ;
}
V_4 = F_2 ( V_2 -> V_5 , V_250 ) ;
V_4 &= ~ V_251 ;
F_3 ( V_2 -> V_5 , V_250 , V_4 ) ;
F_137 ( V_2 ) ;
V_252 . V_141 = F_145 ( 512 ) ;
V_26 = V_2 -> V_97 [ 0 ] ;
V_47 = F_55 ( V_26 , false , false ) ;
if ( V_47 ) {
F_37 ( V_2 -> V_43 , L_20 , V_26 -> V_92 ) ;
goto V_253;
}
V_26 = V_2 -> V_97 [ 1 ] ;
V_47 = F_55 ( V_26 , false , false ) ;
if ( V_47 ) {
F_37 ( V_2 -> V_43 , L_20 , V_26 -> V_92 ) ;
goto V_254;
}
V_2 -> V_224 = V_225 ;
F_146 ( V_2 ) ;
F_135 ( V_2 ) ;
return 0 ;
V_254:
F_67 ( V_2 -> V_97 [ 0 ] ) ;
V_253:
return V_47 ;
}
static int F_147 ( struct V_153 * V_206 ,
struct V_255 * V_256 )
{
struct V_1 * V_2 = F_126 ( V_206 ) ;
unsigned long V_80 ;
int V_47 = 0 ;
int V_257 ;
V_257 = V_2 -> V_258 ;
V_47 = F_148 ( V_257 , V_259 , V_260 ,
V_261 , L_21 , V_2 -> V_262 ) ;
if ( V_47 ) {
F_37 ( V_2 -> V_43 , L_22 ,
V_257 , V_47 ) ;
goto V_253;
}
F_75 ( & V_2 -> V_40 , V_80 ) ;
if ( V_2 -> V_263 ) {
F_37 ( V_2 -> V_43 , L_23 ,
V_2 -> V_57 . V_92 ,
V_2 -> V_263 -> V_256 . V_92 ) ;
V_47 = - V_195 ;
goto V_254;
}
V_2 -> V_263 = V_256 ;
if ( F_149 ( V_2 -> V_43 ) )
F_141 ( V_2 ) ;
F_76 ( & V_2 -> V_40 , V_80 ) ;
return 0 ;
V_254:
F_76 ( & V_2 -> V_40 , V_80 ) ;
F_150 ( V_257 , V_2 ) ;
V_253:
return V_47 ;
}
static void F_151 ( struct V_1 * V_2 )
{
F_136 ( V_2 ) ;
F_67 ( V_2 -> V_97 [ 0 ] ) ;
F_67 ( V_2 -> V_97 [ 1 ] ) ;
}
static int F_152 ( struct V_153 * V_206 )
{
struct V_1 * V_2 = F_126 ( V_206 ) ;
unsigned long V_80 ;
int V_144 ;
F_75 ( & V_2 -> V_40 , V_80 ) ;
if ( F_130 ( V_2 -> V_43 ) )
goto V_124;
F_151 ( V_2 ) ;
for ( V_144 = 2 ; V_144 < V_96 ; V_144 ++ ) {
struct V_25 * V_26 = V_2 -> V_97 [ V_144 ] ;
if ( ! V_26 )
continue;
if ( ! ( V_26 -> V_80 & V_121 ) )
continue;
F_121 ( V_26 -> V_123 ,
! ( V_26 -> V_80 & V_121 ) ,
V_2 -> V_40 ) ;
}
V_124:
V_2 -> V_263 = NULL ;
F_76 ( & V_2 -> V_40 , V_80 ) ;
F_150 ( V_2 -> V_258 , V_2 -> V_262 ) ;
return 0 ;
}
static void F_153 ( struct V_153 * V_206 ,
enum V_154 V_58 )
{
struct V_1 * V_2 = F_126 ( V_206 ) ;
unsigned long V_80 ;
T_1 V_4 ;
F_75 ( & V_2 -> V_40 , V_80 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_245 ) ;
V_4 &= ~ ( V_264 ) ;
if ( V_2 -> V_18 < V_265 ) {
V_4 |= V_266 ;
} else {
switch ( V_58 ) {
case V_267 :
V_4 |= V_268 ;
break;
case V_269 :
V_4 |= V_270 ;
break;
case V_59 :
V_4 |= V_271 ;
break;
case V_85 :
V_4 |= V_266 ;
break;
case V_272 :
V_4 |= V_273 ;
break;
default:
F_37 ( V_2 -> V_43 , L_24 , V_58 ) ;
if ( V_2 -> V_18 & V_274 )
V_4 |= V_273 ;
else
V_4 |= V_266 ;
}
}
F_3 ( V_2 -> V_5 , V_245 , V_4 ) ;
F_76 ( & V_2 -> V_40 , V_80 ) ;
}
static int F_154 ( struct V_1 * V_2 , T_2 V_275 )
{
struct V_25 * V_26 ;
T_2 V_144 ;
F_155 ( & V_2 -> V_57 . V_276 ) ;
for ( V_144 = 0 ; V_144 < V_275 ; V_144 ++ ) {
bool V_39 = V_144 & 1 ;
T_2 V_277 = V_144 >> 1 ;
V_26 = F_79 ( sizeof( * V_26 ) , V_91 ) ;
if ( ! V_26 )
return - V_93 ;
V_26 -> V_2 = V_2 ;
V_26 -> V_42 = V_144 ;
V_26 -> V_39 = V_39 ;
V_26 -> V_5 = V_2 -> V_5 + F_156 ( V_144 ) ;
V_2 -> V_97 [ V_144 ] = V_26 ;
snprintf ( V_26 -> V_92 , sizeof( V_26 -> V_92 ) , L_25 , V_277 ,
V_39 ? L_26 : L_27 ) ;
V_26 -> V_41 . V_92 = V_26 -> V_92 ;
if ( ! ( V_26 -> V_42 > 1 ) ) {
V_26 -> V_41 . V_54 = & V_252 ;
V_26 -> V_41 . V_101 = NULL ;
}
F_157 ( & V_26 -> V_40 ) ;
if ( V_277 == 0 ) {
F_158 ( & V_26 -> V_41 , 512 ) ;
V_26 -> V_41 . V_103 = 1 ;
V_26 -> V_41 . V_278 = & V_279 ;
if ( ! V_39 )
V_2 -> V_57 . V_280 = & V_26 -> V_41 ;
} else if ( V_39 ) {
int V_240 ;
int V_281 ;
int V_155 ;
int V_47 ;
V_240 = F_159 ( V_2 -> V_242 . V_244 ) ;
V_240 /= 8 ;
V_155 = F_2 ( V_2 -> V_5 , F_160 ( V_277 ) ) ;
V_155 = F_161 ( V_155 ) ;
V_155 *= V_240 ;
V_281 = V_155 / 1024 ;
if ( V_281 == 0 )
V_281 = 1 ;
V_155 -= V_240 * ( V_281 + 1 ) ;
V_155 /= V_281 ;
F_158 ( & V_26 -> V_41 , V_155 ) ;
V_26 -> V_41 . V_282 = 15 ;
V_26 -> V_41 . V_278 = & V_283 ;
F_117 ( & V_26 -> V_41 . V_276 ,
& V_2 -> V_57 . V_276 ) ;
V_47 = F_35 ( V_26 ) ;
if ( V_47 )
return V_47 ;
} else {
int V_47 ;
F_158 ( & V_26 -> V_41 , 1024 ) ;
V_26 -> V_41 . V_282 = 15 ;
V_26 -> V_41 . V_278 = & V_283 ;
F_117 ( & V_26 -> V_41 . V_276 ,
& V_2 -> V_57 . V_276 ) ;
V_47 = F_35 ( V_26 ) ;
if ( V_47 )
return V_47 ;
}
if ( V_277 == 0 ) {
V_26 -> V_41 . V_284 . V_285 = true ;
} else {
V_26 -> V_41 . V_284 . V_286 = true ;
V_26 -> V_41 . V_284 . V_287 = true ;
V_26 -> V_41 . V_284 . V_288 = true ;
}
V_26 -> V_41 . V_284 . V_289 = V_39 ;
V_26 -> V_41 . V_284 . V_290 = ! V_39 ;
F_155 ( & V_26 -> V_135 ) ;
F_155 ( & V_26 -> V_133 ) ;
}
return 0 ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
T_2 V_144 ;
for ( V_144 = 0 ; V_144 < V_96 ; V_144 ++ ) {
V_26 = V_2 -> V_97 [ V_144 ] ;
if ( ! V_26 )
continue;
if ( V_144 != 0 && V_144 != 1 ) {
F_38 ( V_26 ) ;
F_13 ( & V_26 -> V_41 . V_276 ) ;
}
F_84 ( V_26 ) ;
}
}
static int F_163 ( struct V_1 * V_2 , struct V_25 * V_26 ,
struct V_29 * V_30 , struct V_87 * V_37 ,
const struct V_189 * V_190 , int V_31 ,
int V_148 )
{
unsigned int V_291 ;
unsigned int V_292 = 0 ;
unsigned int V_293 ;
F_11 ( V_26 ) ;
if ( V_30 -> V_37 == V_37 )
V_26 -> V_170 -- ;
F_164 ( V_26 , V_37 ) ;
if ( V_148 && ( V_37 -> V_127 & V_129 ) )
V_37 -> V_127 &= ~ V_129 ;
if ( ( V_30 -> V_179 || V_30 -> V_177 ) && ( V_37 -> V_127 & V_129 ) ) {
V_37 -> V_127 &= ~ V_129 ;
return 1 ;
}
V_291 = V_37 -> V_155 & V_294 ;
V_30 -> V_34 += V_291 ;
if ( ( V_37 -> V_127 & V_129 ) && V_31 != - V_134 )
return 1 ;
if ( V_26 -> V_39 ) {
if ( V_291 ) {
V_293 = F_165 ( V_37 -> V_155 ) ;
if ( V_293 == V_295 ) {
V_26 -> V_80 |= V_194 ;
} else {
F_37 ( V_2 -> V_43 , L_28 ,
V_26 -> V_92 ) ;
V_31 = - V_199 ;
}
} else {
V_26 -> V_80 &= ~ V_194 ;
}
} else {
if ( V_291 && ( V_190 -> V_31 & V_296 ) )
V_292 = 1 ;
}
if ( V_292 && ! V_148 )
return 1 ;
if ( ( V_190 -> V_31 & V_297 ) &&
( V_37 -> V_127 & V_168 ) )
return 1 ;
return 0 ;
}
static int F_166 ( struct V_1 * V_2 , struct V_25 * V_26 ,
const struct V_189 * V_190 , int V_31 )
{
struct V_29 * V_30 , * V_181 ;
struct V_87 * V_37 ;
bool V_298 = false ;
int V_47 = 0 ;
F_103 (req, n, &dep->started_list, list) {
unsigned V_147 ;
int V_148 ;
V_147 = V_30 -> V_35 . V_147 ;
V_148 = V_30 -> V_182 > 0 ;
if ( V_148 ) {
struct V_173 * V_174 = V_30 -> V_174 ;
struct V_173 * V_175 ;
unsigned int V_299 = V_30 -> V_182 ;
unsigned int V_94 ;
F_96 (sg, s, pending, i) {
V_37 = & V_26 -> V_89 [ V_26 -> V_28 ] ;
if ( V_37 -> V_127 & V_129 )
break;
V_30 -> V_174 = F_167 ( V_175 ) ;
V_30 -> V_182 -- ;
V_47 = F_163 ( V_2 , V_26 , V_30 , V_37 ,
V_190 , V_31 , V_148 ) ;
if ( V_47 )
break;
}
} else {
V_37 = & V_26 -> V_89 [ V_26 -> V_28 ] ;
V_47 = F_163 ( V_2 , V_26 , V_30 , V_37 ,
V_190 , V_31 , V_148 ) ;
}
if ( V_30 -> V_177 || V_30 -> V_179 ) {
V_37 = & V_26 -> V_89 [ V_26 -> V_28 ] ;
V_47 = F_163 ( V_2 , V_26 , V_30 , V_37 ,
V_190 , V_31 , false ) ;
V_30 -> V_177 = false ;
V_30 -> V_179 = false ;
}
V_30 -> V_35 . V_193 = V_147 - V_30 -> V_34 ;
if ( ( V_30 -> V_35 . V_193 < V_147 ) && V_30 -> V_182 )
return F_105 ( V_26 , 0 ) ;
F_12 ( V_26 , V_30 , V_31 ) ;
if ( V_47 ) {
if ( ( V_190 -> V_31 & V_297 ) &&
( V_37 -> V_127 & V_168 ) )
V_298 = true ;
break;
}
}
if ( ! V_26 -> V_41 . V_54 )
return 1 ;
if ( F_29 ( V_26 -> V_41 . V_54 ) &&
F_65 ( & V_26 -> V_133 ) ) {
if ( F_65 ( & V_26 -> V_135 ) ) {
V_26 -> V_80 = V_186 ;
} else {
F_64 ( V_2 , V_26 -> V_42 , true ) ;
V_26 -> V_80 = V_118 ;
}
return 1 ;
}
if ( F_29 ( V_26 -> V_41 . V_54 ) && V_298 )
return 0 ;
return 1 ;
}
static void F_168 ( struct V_1 * V_2 ,
struct V_25 * V_26 , const struct V_189 * V_190 )
{
unsigned V_31 = 0 ;
int V_300 ;
T_1 V_301 ;
V_301 = ( V_190 -> V_302 == V_303 ) ;
if ( V_190 -> V_31 & V_304 )
V_31 = - V_199 ;
V_300 = F_166 ( V_2 , V_26 , V_190 , V_31 ) ;
if ( V_300 && ( ! V_26 -> V_41 . V_54 || V_301 ||
F_29 ( V_26 -> V_41 . V_54 ) ) )
V_26 -> V_80 &= ~ V_131 ;
if ( V_2 -> V_18 < V_305 ) {
T_1 V_4 ;
int V_94 ;
for ( V_94 = 0 ; V_94 < V_96 ; V_94 ++ ) {
V_26 = V_2 -> V_97 [ V_94 ] ;
if ( ! ( V_26 -> V_80 & V_118 ) )
continue;
if ( ! F_65 ( & V_26 -> V_133 ) )
return;
}
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 |= V_2 -> V_306 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_2 -> V_306 = 0 ;
}
if ( ! V_26 -> V_41 . V_54 )
return;
if ( ! F_29 ( V_26 -> V_41 . V_54 ) ) {
int V_47 ;
V_47 = F_105 ( V_26 , 0 ) ;
if ( ! V_47 || V_47 == - V_195 )
return;
}
}
static void F_169 ( struct V_1 * V_2 ,
const struct V_189 * V_190 )
{
struct V_25 * V_26 ;
T_2 V_144 = V_190 -> V_307 ;
T_2 V_44 ;
V_26 = V_2 -> V_97 [ V_144 ] ;
if ( ! ( V_26 -> V_80 & V_118 ) ) {
if ( ! ( V_26 -> V_80 & V_121 ) )
return;
if ( V_190 -> V_302 != V_308 )
return;
}
if ( V_144 == 0 || V_144 == 1 ) {
F_170 ( V_2 , V_190 ) ;
return;
}
switch ( V_190 -> V_302 ) {
case V_303 :
V_26 -> V_132 = 0 ;
if ( F_29 ( V_26 -> V_41 . V_54 ) ) {
F_37 ( V_2 -> V_43 , L_29 ) ;
return;
}
F_168 ( V_2 , V_26 , V_190 ) ;
break;
case V_309 :
F_168 ( V_2 , V_26 , V_190 ) ;
break;
case V_310 :
if ( F_29 ( V_26 -> V_41 . V_54 ) ) {
F_112 ( V_2 , V_26 , V_190 ) ;
} else {
int V_47 ;
V_47 = F_105 ( V_26 , 0 ) ;
if ( ! V_47 || V_47 == - V_195 )
return;
}
break;
case V_311 :
if ( ! F_50 ( V_26 -> V_41 . V_54 ) ) {
F_37 ( V_2 -> V_43 , L_30 ,
V_26 -> V_92 ) ;
return;
}
break;
case V_308 :
V_44 = F_171 ( V_190 -> V_192 ) ;
if ( V_44 == V_82 ) {
V_26 -> V_80 &= ~ V_121 ;
F_172 ( & V_26 -> V_123 ) ;
}
break;
case V_312 :
break;
}
}
static void F_173 ( struct V_1 * V_2 )
{
if ( V_2 -> V_263 && V_2 -> V_263 -> V_313 ) {
F_16 ( & V_2 -> V_40 ) ;
V_2 -> V_263 -> V_313 ( & V_2 -> V_57 ) ;
F_18 ( & V_2 -> V_40 ) ;
}
}
static void F_174 ( struct V_1 * V_2 )
{
if ( V_2 -> V_263 && V_2 -> V_263 -> V_215 ) {
F_16 ( & V_2 -> V_40 ) ;
V_2 -> V_263 -> V_215 ( & V_2 -> V_57 ) ;
F_18 ( & V_2 -> V_40 ) ;
}
}
static void F_175 ( struct V_1 * V_2 )
{
if ( V_2 -> V_263 && V_2 -> V_263 -> V_314 ) {
F_16 ( & V_2 -> V_40 ) ;
V_2 -> V_263 -> V_314 ( & V_2 -> V_57 ) ;
F_18 ( & V_2 -> V_40 ) ;
}
}
static void F_176 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_263 )
return;
if ( V_2 -> V_57 . V_58 != V_315 ) {
F_16 ( & V_2 -> V_40 ) ;
F_177 ( & V_2 -> V_57 , V_2 -> V_263 ) ;
F_18 ( & V_2 -> V_40 ) ;
}
}
static void F_64 ( struct V_1 * V_2 , T_1 V_144 , bool V_316 )
{
struct V_25 * V_26 ;
struct V_51 V_52 ;
T_1 V_44 ;
int V_47 ;
V_26 = V_2 -> V_97 [ V_144 ] ;
if ( ( V_26 -> V_80 & V_121 ) ||
! V_26 -> V_132 )
return;
V_44 = V_82 ;
V_44 |= V_316 ? V_317 : 0 ;
V_44 |= V_74 ;
V_44 |= F_106 ( V_26 -> V_132 ) ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_47 = F_23 ( V_26 , V_44 , & V_52 ) ;
F_61 ( V_47 ) ;
V_26 -> V_132 = 0 ;
V_26 -> V_80 &= ~ V_131 ;
if ( F_178 ( V_2 ) || V_2 -> V_18 < V_318 ) {
V_26 -> V_80 |= V_121 ;
F_7 ( 100 ) ;
}
}
static void F_179 ( struct V_1 * V_2 )
{
T_1 V_144 ;
for ( V_144 = 1 ; V_144 < V_96 ; V_144 ++ ) {
struct V_25 * V_26 ;
int V_47 ;
V_26 = V_2 -> V_97 [ V_144 ] ;
if ( ! V_26 )
continue;
if ( ! ( V_26 -> V_80 & V_136 ) )
continue;
V_26 -> V_80 &= ~ V_136 ;
V_47 = F_33 ( V_26 ) ;
F_61 ( V_47 ) ;
}
}
static void F_180 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_319 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_4 &= ~ V_320 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
F_173 ( V_2 ) ;
V_2 -> V_57 . V_58 = V_315 ;
V_2 -> V_321 = false ;
F_181 ( & V_2 -> V_57 , V_322 ) ;
V_2 -> V_323 = false ;
}
static void F_182 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_2 -> V_323 = true ;
if ( V_2 -> V_18 < V_324 ) {
if ( V_2 -> V_321 )
F_180 ( V_2 ) ;
}
F_176 ( V_2 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_7 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
V_2 -> V_325 = false ;
F_179 ( V_2 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_245 ) ;
V_4 &= ~ ( V_326 ) ;
F_3 ( V_2 -> V_5 , V_245 , V_4 ) ;
}
static void F_183 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
int V_47 ;
T_1 V_4 ;
T_2 V_58 ;
V_4 = F_2 ( V_2 -> V_5 , V_14 ) ;
V_58 = V_4 & V_207 ;
V_2 -> V_58 = V_58 ;
switch ( V_58 ) {
case V_209 :
V_252 . V_141 = F_145 ( 512 ) ;
V_2 -> V_57 . V_280 -> V_180 = 512 ;
V_2 -> V_57 . V_58 = V_272 ;
break;
case V_208 :
if ( V_2 -> V_18 < V_327 )
F_182 ( V_2 ) ;
V_252 . V_141 = F_145 ( 512 ) ;
V_2 -> V_57 . V_280 -> V_180 = 512 ;
V_2 -> V_57 . V_58 = V_85 ;
break;
case V_328 :
V_252 . V_141 = F_145 ( 64 ) ;
V_2 -> V_57 . V_280 -> V_180 = 64 ;
V_2 -> V_57 . V_58 = V_59 ;
break;
case V_329 :
V_252 . V_141 = F_145 ( 64 ) ;
V_2 -> V_57 . V_280 -> V_180 = 64 ;
V_2 -> V_57 . V_58 = V_269 ;
break;
case V_330 :
V_252 . V_141 = F_145 ( 8 ) ;
V_2 -> V_57 . V_280 -> V_180 = 8 ;
V_2 -> V_57 . V_58 = V_267 ;
break;
}
if ( ( V_2 -> V_18 > V_19 ) &&
( V_58 != V_208 ) &&
( V_58 != V_209 ) ) {
V_4 = F_2 ( V_2 -> V_5 , V_245 ) ;
V_4 |= V_331 ;
F_3 ( V_2 -> V_5 , V_245 , V_4 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ ( V_332 | V_333 ) ;
V_4 |= F_184 ( V_2 -> V_334 ) ;
F_185 ( V_2 -> V_18 < V_335
&& V_2 -> V_336 ,
L_31 ) ;
if ( V_2 -> V_336 && V_2 -> V_18 >= V_335 )
V_4 |= F_186 ( V_2 -> V_337 ) ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_4 &= ~ V_332 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
}
V_26 = V_2 -> V_97 [ 0 ] ;
V_47 = F_55 ( V_26 , true , false ) ;
if ( V_47 ) {
F_37 ( V_2 -> V_43 , L_20 , V_26 -> V_92 ) ;
return;
}
V_26 = V_2 -> V_97 [ 1 ] ;
V_47 = F_55 ( V_26 , true , false ) ;
if ( V_47 ) {
F_37 ( V_2 -> V_43 , L_20 , V_26 -> V_92 ) ;
return;
}
}
static void F_187 ( struct V_1 * V_2 )
{
if ( V_2 -> V_263 && V_2 -> V_263 -> V_314 ) {
F_16 ( & V_2 -> V_40 ) ;
V_2 -> V_263 -> V_314 ( & V_2 -> V_57 ) ;
F_18 ( & V_2 -> V_40 ) ;
}
}
static void F_188 ( struct V_1 * V_2 ,
unsigned int V_338 )
{
enum V_15 V_339 = V_338 & V_340 ;
unsigned int V_341 ;
V_341 = F_189 ( V_2 -> V_242 . V_342 ) ;
if ( ( V_2 -> V_18 < V_236 ) &&
( V_341 != V_343 ) ) {
if ( ( V_2 -> V_63 == V_66 ) &&
( V_339 == V_344 ) ) {
return;
}
}
if ( V_2 -> V_18 < V_305 ) {
if ( V_339 == V_212 ) {
T_1 V_306 ;
T_1 V_4 ;
switch ( V_2 -> V_63 ) {
case V_64 :
case V_65 :
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_306 = V_4 & ( V_320
| V_345
| V_319
| V_346 ) ;
if ( ! V_2 -> V_306 )
V_2 -> V_306 = V_4 & V_306 ;
V_4 &= ~ V_306 ;
F_3 ( V_2 -> V_5 , V_6 , V_4 ) ;
break;
default:
break;
}
}
}
switch ( V_339 ) {
case V_64 :
if ( V_2 -> V_58 == V_85 )
F_174 ( V_2 ) ;
break;
case V_65 :
case V_66 :
F_174 ( V_2 ) ;
break;
case V_344 :
F_175 ( V_2 ) ;
break;
default:
break;
}
V_2 -> V_63 = V_339 ;
}
static void F_190 ( struct V_1 * V_2 ,
unsigned int V_338 )
{
enum V_15 V_339 = V_338 & V_340 ;
if ( V_2 -> V_63 != V_339 && V_339 == V_66 )
F_174 ( V_2 ) ;
V_2 -> V_63 = V_339 ;
}
static void F_191 ( struct V_1 * V_2 ,
unsigned int V_338 )
{
unsigned int V_347 = V_338 & F_192 ( 4 ) ;
if ( V_347 ^ ( V_2 -> V_58 == V_85 ) )
return;
}
static void F_193 ( struct V_1 * V_2 ,
const struct V_348 * V_190 )
{
switch ( V_190 -> type ) {
case V_349 :
F_180 ( V_2 ) ;
break;
case V_350 :
F_182 ( V_2 ) ;
break;
case V_351 :
F_183 ( V_2 ) ;
break;
case V_352 :
F_187 ( V_2 ) ;
break;
case V_353 :
if ( F_28 ( V_2 -> V_43 , ! V_2 -> V_221 ,
L_32 ) )
break;
F_191 ( V_2 , V_190 -> V_354 ) ;
break;
case V_355 :
F_188 ( V_2 , V_190 -> V_354 ) ;
break;
case V_356 :
if ( V_2 -> V_18 >= V_357 ) {
if ( V_2 -> V_57 . V_16 >= V_358 )
F_190 ( V_2 ,
V_190 -> V_354 ) ;
}
break;
case V_359 :
case V_360 :
case V_361 :
case V_362 :
break;
default:
F_31 ( V_2 -> V_43 , L_33 , V_190 -> type ) ;
}
}
static void F_194 ( struct V_1 * V_2 ,
const union V_363 * V_190 )
{
F_195 ( V_190 -> V_364 , V_2 ) ;
if ( ! V_190 -> type . V_365 )
F_169 ( V_2 , & V_190 -> V_366 ) ;
else if ( V_190 -> type . type == V_367 )
F_193 ( V_2 , & V_190 -> V_368 ) ;
else
F_37 ( V_2 -> V_43 , L_34 , V_190 -> V_364 ) ;
}
static T_6 F_196 ( struct V_369 * V_370 )
{
struct V_1 * V_2 = V_370 -> V_2 ;
T_6 V_47 = V_371 ;
int V_372 ;
T_1 V_4 ;
V_372 = V_370 -> V_291 ;
if ( ! ( V_370 -> V_80 & V_373 ) )
return V_371 ;
while ( V_372 > 0 ) {
union V_363 V_190 ;
V_190 . V_364 = * ( T_1 * ) ( V_370 -> V_374 + V_370 -> V_375 ) ;
F_194 ( V_2 , & V_190 ) ;
V_370 -> V_375 = ( V_370 -> V_375 + 4 ) % V_370 -> V_147 ;
V_372 -= 4 ;
}
V_370 -> V_291 = 0 ;
V_370 -> V_80 &= ~ V_373 ;
V_47 = V_376 ;
V_4 = F_2 ( V_2 -> V_5 , F_197 ( 0 ) ) ;
V_4 &= ~ V_377 ;
F_3 ( V_2 -> V_5 , F_197 ( 0 ) , V_4 ) ;
if ( V_2 -> V_248 ) {
F_3 ( V_2 -> V_5 , F_143 ( 0 ) , V_249 ) ;
F_3 ( V_2 -> V_5 , F_142 ( 0 ) , V_2 -> V_248 ) ;
}
return V_47 ;
}
static T_6 V_260 ( int V_257 , void * V_378 )
{
struct V_369 * V_370 = V_378 ;
struct V_1 * V_2 = V_370 -> V_2 ;
unsigned long V_80 ;
T_6 V_47 = V_371 ;
F_75 ( & V_2 -> V_40 , V_80 ) ;
V_47 = F_196 ( V_370 ) ;
F_76 ( & V_2 -> V_40 , V_80 ) ;
return V_47 ;
}
static T_6 F_198 ( struct V_369 * V_370 )
{
struct V_1 * V_2 = V_370 -> V_2 ;
T_1 V_379 ;
T_1 V_291 ;
T_1 V_4 ;
if ( F_130 ( V_2 -> V_43 ) ) {
F_115 ( V_2 -> V_43 ) ;
F_199 ( V_2 -> V_258 ) ;
V_2 -> V_380 = true ;
return V_376 ;
}
if ( V_370 -> V_80 & V_373 )
return V_376 ;
V_291 = F_2 ( V_2 -> V_5 , F_143 ( 0 ) ) ;
V_291 &= V_381 ;
if ( ! V_291 )
return V_371 ;
V_370 -> V_291 = V_291 ;
V_370 -> V_80 |= V_373 ;
V_4 = F_2 ( V_2 -> V_5 , F_197 ( 0 ) ) ;
V_4 |= V_377 ;
F_3 ( V_2 -> V_5 , F_197 ( 0 ) , V_4 ) ;
V_379 = F_200 ( V_291 , V_370 -> V_147 - V_370 -> V_375 ) ;
memcpy ( V_370 -> V_374 + V_370 -> V_375 , V_370 -> V_382 + V_370 -> V_375 , V_379 ) ;
if ( V_379 < V_291 )
memcpy ( V_370 -> V_374 , V_370 -> V_382 , V_291 - V_379 ) ;
F_3 ( V_2 -> V_5 , F_143 ( 0 ) , V_291 ) ;
return V_383 ;
}
static T_6 V_259 ( int V_257 , void * V_378 )
{
struct V_369 * V_370 = V_378 ;
return F_198 ( V_370 ) ;
}
static int F_201 ( struct V_1 * V_2 )
{
struct V_384 * V_385 = F_202 ( V_2 -> V_43 ) ;
int V_257 ;
V_257 = F_203 ( V_385 , L_35 ) ;
if ( V_257 > 0 )
goto V_124;
if ( V_257 == - V_386 )
goto V_124;
V_257 = F_203 ( V_385 , L_36 ) ;
if ( V_257 > 0 )
goto V_124;
if ( V_257 == - V_386 )
goto V_124;
V_257 = F_204 ( V_385 , 0 ) ;
if ( V_257 > 0 )
goto V_124;
if ( V_257 != - V_386 )
F_37 ( V_2 -> V_43 , L_37 ) ;
if ( ! V_257 )
V_257 = - V_13 ;
V_124:
return V_257 ;
}
int F_205 ( struct V_1 * V_2 )
{
int V_47 ;
int V_257 ;
V_257 = F_201 ( V_2 ) ;
if ( V_257 < 0 ) {
V_47 = V_257 ;
goto V_253;
}
V_2 -> V_258 = V_257 ;
V_2 -> V_203 = F_36 ( V_2 -> V_38 ,
sizeof( * V_2 -> V_203 ) * 2 ,
& V_2 -> V_387 , V_91 ) ;
if ( ! V_2 -> V_203 ) {
F_37 ( V_2 -> V_43 , L_38 ) ;
V_47 = - V_93 ;
goto V_253;
}
V_2 -> V_388 = F_79 ( V_389 , V_91 ) ;
if ( ! V_2 -> V_388 ) {
V_47 = - V_93 ;
goto V_254;
}
V_2 -> V_390 = F_36 ( V_2 -> V_38 , V_391 ,
& V_2 -> V_178 , V_91 ) ;
if ( ! V_2 -> V_390 ) {
V_47 = - V_93 ;
goto V_392;
}
F_206 ( & V_2 -> V_226 ) ;
V_2 -> V_57 . V_278 = & V_393 ;
V_2 -> V_57 . V_58 = V_315 ;
V_2 -> V_57 . V_394 = true ;
V_2 -> V_57 . V_92 = L_39 ;
V_2 -> V_57 . V_395 = V_2 -> V_396 == V_397 ;
if ( V_2 -> V_18 < V_265 )
F_110 ( V_2 -> V_43 , L_40 ,
V_2 -> V_18 ) ;
V_2 -> V_57 . V_398 = V_2 -> V_399 ;
V_47 = F_154 ( V_2 , V_2 -> V_400 ) ;
if ( V_47 )
goto V_401;
V_47 = F_207 ( V_2 -> V_43 , & V_2 -> V_57 ) ;
if ( V_47 ) {
F_37 ( V_2 -> V_43 , L_41 ) ;
goto V_402;
}
return 0 ;
V_402:
F_162 ( V_2 ) ;
V_401:
F_39 ( V_2 -> V_38 , V_391 , V_2 -> V_390 ,
V_2 -> V_178 ) ;
V_392:
F_84 ( V_2 -> V_388 ) ;
V_254:
F_39 ( V_2 -> V_38 , sizeof( * V_2 -> V_203 ) * 2 ,
V_2 -> V_203 , V_2 -> V_387 ) ;
V_253:
return V_47 ;
}
void F_208 ( struct V_1 * V_2 )
{
F_209 ( & V_2 -> V_57 ) ;
F_162 ( V_2 ) ;
F_39 ( V_2 -> V_38 , V_391 , V_2 -> V_390 ,
V_2 -> V_178 ) ;
F_84 ( V_2 -> V_388 ) ;
F_39 ( V_2 -> V_38 , sizeof( * V_2 -> V_203 ) * 2 ,
V_2 -> V_203 , V_2 -> V_387 ) ;
}
int F_210 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_263 )
return 0 ;
F_129 ( V_2 , false , false ) ;
F_173 ( V_2 ) ;
F_151 ( V_2 ) ;
return 0 ;
}
int F_211 ( struct V_1 * V_2 )
{
int V_47 ;
if ( ! V_2 -> V_263 )
return 0 ;
V_47 = F_141 ( V_2 ) ;
if ( V_47 < 0 )
goto V_253;
V_47 = F_129 ( V_2 , true , false ) ;
if ( V_47 < 0 )
goto V_254;
return 0 ;
V_254:
F_151 ( V_2 ) ;
V_253:
return V_47 ;
}
void F_212 ( struct V_1 * V_2 )
{
if ( V_2 -> V_380 ) {
V_259 ( V_2 -> V_258 , V_2 -> V_262 ) ;
V_2 -> V_380 = false ;
F_213 ( V_2 -> V_258 ) ;
}
}
