static void F_1 ( struct V_1 * V_2 ,
unsigned V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_7 = ( T_1 ) V_2 -> V_8 . V_9 << V_10 ;
switch ( V_3 ) {
case V_11 :
if ( V_4 > 0 )
F_2 ( V_7 , & V_6 -> V_12 ) ;
else
F_3 ( V_7 , & V_6 -> V_12 ) ;
break;
case V_13 :
if ( V_4 > 0 )
F_2 ( V_7 , & V_6 -> V_14 ) ;
else
F_3 ( V_7 , & V_6 -> V_14 ) ;
break;
}
}
static void F_4 ( struct V_15 * V_8 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_8 , struct V_1 , V_8 ) ;
F_1 ( V_2 , V_2 -> V_8 . V_16 . V_3 , - 1 ) ;
F_6 ( V_2 ) ;
F_7 ( & V_2 -> V_6 -> V_17 . V_18 ) ;
F_8 ( & V_2 -> V_19 ) ;
F_9 ( & V_2 -> V_6 -> V_17 . V_18 ) ;
F_10 ( V_2 ) ;
F_11 ( ! F_12 ( & V_2 -> V_20 ) ) ;
F_13 ( & V_2 -> V_21 ) ;
F_14 ( V_2 ) ;
}
bool F_15 ( struct V_15 * V_2 )
{
if ( V_2 -> V_22 == & F_4 )
return true ;
return false ;
}
void F_16 ( struct V_1 * V_23 , T_2 V_24 )
{
T_2 V_25 = 0 , V_26 ;
V_23 -> V_27 . V_27 = V_23 -> V_28 ;
V_23 -> V_27 . V_29 = V_23 -> V_28 ;
if ( V_24 & V_30 )
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_32 |
V_33 |
V_34 ;
if ( V_24 & V_35 ) {
if ( V_23 -> V_31 & V_36 ) {
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_33 |
V_37 ;
} else if ( ( V_23 -> V_31 & V_38 ) ||
( V_23 -> V_6 -> V_31 & V_39 ) ) {
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_32 |
V_33 |
V_37 ;
} else {
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_40 |
V_37 ;
}
}
if ( V_24 & V_41 ) {
if ( V_23 -> V_31 & V_36 ) {
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_33 |
V_42 ;
} else if ( ( V_23 -> V_31 & V_38 ) ||
V_23 -> V_6 -> V_31 & V_39 ) {
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_32 |
V_33 |
V_42 ;
} else {
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_40 |
V_42 ;
}
}
if ( ! V_25 )
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_43 |
V_42 ;
V_23 -> V_27 . V_44 = V_25 ;
V_23 -> V_27 . V_45 = V_25 ;
for ( V_26 = 0 ; V_26 < V_25 ; ++ V_26 ) {
V_23 -> V_28 [ V_26 ] . V_46 = 0 ;
if ( ( V_23 -> V_31 & V_47 ) &&
( V_23 -> V_28 [ V_26 ] . V_31 & V_34 ) )
V_23 -> V_28 [ V_26 ] . V_48 =
V_23 -> V_6 -> V_49 . V_50 >> V_10 ;
else
V_23 -> V_28 [ V_26 ] . V_48 = 0 ;
}
if ( ! ( ( V_23 -> V_31 & V_47 ) &&
( V_23 -> V_28 [ V_26 ] . V_31 & V_34 ) ) &&
V_23 -> V_8 . V_16 . V_7 > 512 * 1024 ) {
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
V_23 -> V_28 [ V_26 ] . V_31 |= V_51 ;
}
}
}
int F_17 ( struct V_5 * V_6 ,
unsigned long V_7 , int V_52 , bool V_53 ,
T_2 V_24 , T_2 V_31 , struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_1 * * V_58 )
{
struct V_1 * V_2 ;
enum V_59 type ;
unsigned long V_60 = F_18 ( V_52 , V_61 ) >> V_10 ;
T_3 V_62 ;
int V_63 ;
V_7 = F_19 ( V_7 , V_61 ) ;
if ( V_53 ) {
type = V_64 ;
} else if ( V_55 ) {
type = V_65 ;
} else {
type = V_66 ;
}
* V_58 = NULL ;
V_62 = F_20 ( & V_6 -> V_67 . V_68 , V_7 ,
sizeof( struct V_1 ) ) ;
V_2 = F_21 ( sizeof( struct V_1 ) , V_69 ) ;
if ( V_2 == NULL )
return - V_70 ;
V_63 = F_22 ( V_6 -> V_71 , & V_2 -> V_21 , V_7 ) ;
if ( F_23 ( V_63 ) ) {
F_14 ( V_2 ) ;
return V_63 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_72 = - 1 ;
F_24 ( & V_2 -> V_19 ) ;
F_24 ( & V_2 -> V_20 ) ;
V_2 -> V_73 = V_24 & ( V_30 |
V_35 |
V_41 ) ;
V_2 -> V_31 = V_31 ;
if ( ! ( V_6 -> V_31 & V_74 ) )
V_2 -> V_31 &= ~ ( V_38 | V_36 ) ;
#ifdef F_25
V_2 -> V_31 &= ~ V_38 ;
#endif
F_16 ( V_2 , V_24 ) ;
F_26 ( & V_6 -> V_75 . V_76 ) ;
V_63 = F_27 ( & V_6 -> V_67 . V_68 , & V_2 -> V_8 , V_7 , type ,
& V_2 -> V_27 , V_60 , ! V_53 , NULL ,
V_62 , V_55 , V_57 , & F_4 ) ;
F_28 ( & V_6 -> V_75 . V_76 ) ;
if ( F_23 ( V_63 != 0 ) ) {
return V_63 ;
}
* V_58 = V_2 ;
F_29 ( V_2 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 , void * * V_77 )
{
bool V_78 ;
int V_63 ;
if ( V_2 -> V_79 ) {
if ( V_77 ) {
* V_77 = V_2 -> V_79 ;
}
return 0 ;
}
V_63 = F_31 ( & V_2 -> V_8 , 0 , V_2 -> V_8 . V_9 , & V_2 -> V_80 ) ;
if ( V_63 ) {
return V_63 ;
}
V_2 -> V_79 = F_32 ( & V_2 -> V_80 , & V_78 ) ;
if ( V_77 ) {
* V_77 = V_2 -> V_79 ;
}
F_33 ( V_2 , 0 , 0 ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 == NULL )
return;
V_2 -> V_79 = NULL ;
F_33 ( V_2 , 0 , 0 ) ;
F_35 ( & V_2 -> V_80 ) ;
}
struct V_1 * F_36 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return NULL ;
F_37 ( & V_2 -> V_8 ) ;
return V_2 ;
}
void F_38 ( struct V_1 * * V_2 )
{
struct V_15 * V_8 ;
struct V_5 * V_6 ;
if ( ( * V_2 ) == NULL )
return;
V_6 = ( * V_2 ) -> V_6 ;
V_8 = & ( ( * V_2 ) -> V_8 ) ;
F_39 ( & V_8 ) ;
if ( V_8 == NULL )
* V_2 = NULL ;
}
int F_40 ( struct V_1 * V_2 , T_2 V_24 , T_1 V_81 ,
T_1 * V_82 )
{
int V_63 , V_26 ;
if ( F_41 ( V_2 -> V_8 . V_83 ) )
return - V_84 ;
if ( V_2 -> V_85 ) {
V_2 -> V_85 ++ ;
if ( V_82 )
* V_82 = F_42 ( V_2 ) ;
if ( V_81 != 0 ) {
T_1 V_86 ;
if ( V_24 == V_30 )
V_86 = V_2 -> V_6 -> V_49 . V_87 ;
else
V_86 = V_2 -> V_6 -> V_49 . V_88 ;
F_43 ( V_81 <
( F_42 ( V_2 ) - V_86 ) ) ;
}
return 0 ;
}
F_16 ( V_2 , V_24 ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_27 . V_44 ; V_26 ++ ) {
if ( ( V_2 -> V_28 [ V_26 ] . V_31 & V_34 ) &&
! ( V_2 -> V_31 & V_89 ) &&
( ! V_81 || V_81 > V_2 -> V_6 -> V_49 . V_50 ) )
V_2 -> V_28 [ V_26 ] . V_48 =
V_2 -> V_6 -> V_49 . V_50 >> V_10 ;
else
V_2 -> V_28 [ V_26 ] . V_48 = V_81 >> V_10 ;
V_2 -> V_28 [ V_26 ] . V_31 |= V_90 ;
}
V_63 = F_44 ( & V_2 -> V_8 , & V_2 -> V_27 , false , false ) ;
if ( F_45 ( V_63 == 0 ) ) {
V_2 -> V_85 = 1 ;
if ( V_82 != NULL )
* V_82 = F_42 ( V_2 ) ;
if ( V_24 == V_30 )
V_2 -> V_6 -> V_91 += F_46 ( V_2 ) ;
else
V_2 -> V_6 -> V_92 += F_46 ( V_2 ) ;
} else {
F_47 ( V_2 -> V_6 -> V_93 , L_1 , V_2 ) ;
}
return V_63 ;
}
int F_48 ( struct V_1 * V_2 , T_2 V_24 , T_1 * V_82 )
{
return F_40 ( V_2 , V_24 , 0 , V_82 ) ;
}
int F_49 ( struct V_1 * V_2 )
{
int V_63 , V_26 ;
if ( ! V_2 -> V_85 ) {
F_50 ( V_2 -> V_6 -> V_93 , L_2 , V_2 ) ;
return 0 ;
}
V_2 -> V_85 -- ;
if ( V_2 -> V_85 )
return 0 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_27 . V_44 ; V_26 ++ ) {
V_2 -> V_28 [ V_26 ] . V_48 = 0 ;
V_2 -> V_28 [ V_26 ] . V_31 &= ~ V_90 ;
}
V_63 = F_44 ( & V_2 -> V_8 , & V_2 -> V_27 , false , false ) ;
if ( F_45 ( V_63 == 0 ) ) {
if ( V_2 -> V_8 . V_16 . V_3 == V_13 )
V_2 -> V_6 -> V_91 -= F_46 ( V_2 ) ;
else
V_2 -> V_6 -> V_92 -= F_46 ( V_2 ) ;
} else {
F_47 ( V_2 -> V_6 -> V_93 , L_3 , V_2 ) ;
}
return V_63 ;
}
int F_51 ( struct V_5 * V_6 )
{
if ( 0 && ( V_6 -> V_31 & V_94 ) ) {
if ( V_6 -> V_49 . V_95 == false )
return 0 ;
}
return F_52 ( & V_6 -> V_67 . V_68 , V_13 ) ;
}
void F_53 ( struct V_5 * V_6 )
{
struct V_1 * V_2 , * V_96 ;
if ( F_12 ( & V_6 -> V_17 . V_97 ) ) {
return;
}
F_47 ( V_6 -> V_93 , L_4 ) ;
F_54 (bo, n, &rdev->gem.objects, list) {
F_7 ( & V_6 -> V_71 -> V_98 ) ;
F_47 ( V_6 -> V_93 , L_5 ,
& V_2 -> V_21 , V_2 , ( unsigned long ) V_2 -> V_21 . V_7 ,
* ( ( unsigned long * ) & V_2 -> V_21 . V_99 ) ) ;
F_7 ( & V_2 -> V_6 -> V_17 . V_18 ) ;
F_8 ( & V_2 -> V_19 ) ;
F_9 ( & V_2 -> V_6 -> V_17 . V_18 ) ;
F_55 ( & V_2 -> V_21 ) ;
F_9 ( & V_6 -> V_71 -> V_98 ) ;
}
}
int F_56 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_100 ) {
V_6 -> V_49 . V_101 = F_57 ( V_6 -> V_49 . V_102 ,
V_6 -> V_49 . V_103 ) ;
}
F_58 ( L_6 ,
V_6 -> V_49 . V_104 >> 20 ,
( unsigned long long ) V_6 -> V_49 . V_103 >> 20 ) ;
F_58 ( L_7 ,
V_6 -> V_49 . V_105 , V_6 -> V_49 . V_106 ? 'D' : 'S' ) ;
return F_59 ( V_6 ) ;
}
void F_60 ( struct V_5 * V_6 )
{
F_61 ( V_6 ) ;
F_62 ( V_6 -> V_49 . V_101 ) ;
}
static T_1 F_63 ( struct V_5 * V_6 )
{
T_1 V_107 = V_6 -> V_49 . V_107 ;
T_1 V_14 = F_64 ( & V_6 -> V_14 ) ;
T_1 V_108 = V_107 >> 1 ;
T_1 V_109 = V_14 >= V_108 ? 0 : V_108 - V_14 ;
T_1 V_110 = V_109 >> 1 ;
return F_65 ( V_110 , 1024 * 1024ull ) ;
}
int F_66 ( struct V_5 * V_6 ,
struct V_111 * V_112 ,
struct V_113 * V_114 , int V_115 )
{
struct V_116 * V_117 ;
struct V_1 * V_2 ;
int V_63 ;
T_1 V_118 = 0 , V_119 ;
T_1 V_110 = F_63 ( V_6 ) ;
V_63 = F_67 ( V_112 , V_114 , true ) ;
if ( F_23 ( V_63 != 0 ) ) {
return V_63 ;
}
F_68 (lobj, head, tv.head) {
V_2 = V_117 -> V_120 ;
if ( ! V_2 -> V_85 ) {
T_2 V_24 = V_117 -> V_121 ;
T_2 V_122 = V_117 -> V_123 ;
T_2 V_124 =
F_69 ( V_2 -> V_8 . V_16 . V_3 ) ;
if ( ( V_122 & V_124 ) != 0 &&
( V_24 & V_124 ) == 0 &&
V_118 > V_110 ) {
V_24 = V_124 ;
}
V_125:
F_16 ( V_2 , V_24 ) ;
if ( V_115 == V_126 )
F_70 ( V_2 , V_122 ) ;
V_119 = F_64 ( & V_6 -> V_127 ) ;
V_63 = F_44 ( & V_2 -> V_8 , & V_2 -> V_27 , true , false ) ;
V_118 += F_64 ( & V_6 -> V_127 ) -
V_119 ;
if ( F_23 ( V_63 ) ) {
if ( V_63 != - V_128 &&
V_24 != V_117 -> V_123 ) {
V_24 = V_117 -> V_123 ;
goto V_125;
}
F_71 ( V_112 , V_114 ) ;
return V_63 ;
}
}
V_117 -> V_129 = F_42 ( V_2 ) ;
V_117 -> V_130 = V_2 -> V_130 ;
}
return 0 ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
return F_73 ( V_132 , & V_2 -> V_8 ) ;
}
int F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_133 * V_134 ;
struct V_1 * V_135 ;
int V_136 ;
int V_26 ;
F_75 ( & V_2 -> V_8 . V_57 -> V_137 . V_138 ) ;
if ( ! V_2 -> V_130 )
return 0 ;
if ( V_2 -> V_72 >= 0 ) {
V_134 = & V_6 -> V_139 [ V_2 -> V_72 ] ;
V_26 = V_2 -> V_72 ;
goto V_140;
}
V_136 = - 1 ;
for ( V_26 = 0 ; V_26 < V_141 ; V_26 ++ ) {
V_134 = & V_6 -> V_139 [ V_26 ] ;
if ( ! V_134 -> V_2 )
break;
V_135 = V_134 -> V_2 ;
if ( V_135 -> V_85 == 0 )
V_136 = V_26 ;
}
if ( V_26 == V_141 ) {
if ( V_136 == - 1 )
return - V_70 ;
V_134 = & V_6 -> V_139 [ V_136 ] ;
V_135 = V_134 -> V_2 ;
F_76 ( L_8 , V_136 , V_135 ) ;
F_77 ( & V_135 -> V_8 ) ;
V_135 -> V_72 = - 1 ;
V_26 = V_136 ;
}
V_2 -> V_72 = V_26 ;
V_134 -> V_2 = V_2 ;
V_140:
F_78 ( V_6 , V_26 , V_2 -> V_130 , V_2 -> V_142 ,
V_2 -> V_8 . V_16 . V_143 << V_10 ,
V_2 -> V_8 . V_9 << V_10 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_133 * V_134 ;
if ( V_2 -> V_72 == - 1 )
return;
V_134 = & V_6 -> V_139 [ V_2 -> V_72 ] ;
F_79 ( V_6 , V_2 -> V_72 ) ;
V_134 -> V_2 = NULL ;
V_2 -> V_72 = - 1 ;
}
int F_80 ( struct V_1 * V_2 ,
T_4 V_130 , T_4 V_142 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_63 ;
if ( V_6 -> V_144 >= V_145 ) {
unsigned V_146 , V_147 , V_148 , V_149 , V_150 ;
V_146 = ( V_130 >> V_151 ) & V_152 ;
V_147 = ( V_130 >> V_153 ) & V_154 ;
V_148 = ( V_130 >> V_155 ) & V_156 ;
V_149 = ( V_130 >> V_157 ) & V_158 ;
V_150 = ( V_130 >> V_159 ) & V_160 ;
switch ( V_146 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_161 ;
}
switch ( V_147 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_161 ;
}
switch ( V_148 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_161 ;
}
if ( V_149 > 6 ) {
return - V_161 ;
}
if ( V_150 > 6 ) {
return - V_161 ;
}
}
V_63 = F_81 ( V_2 , false ) ;
if ( F_23 ( V_63 != 0 ) )
return V_63 ;
V_2 -> V_130 = V_130 ;
V_2 -> V_142 = V_142 ;
F_82 ( V_2 ) ;
return 0 ;
}
void F_83 ( struct V_1 * V_2 ,
T_4 * V_130 ,
T_4 * V_142 )
{
F_75 ( & V_2 -> V_8 . V_57 -> V_137 . V_138 ) ;
if ( V_130 )
* V_130 = V_2 -> V_130 ;
if ( V_142 )
* V_142 = V_2 -> V_142 ;
}
int F_33 ( struct V_1 * V_2 , bool V_162 ,
bool V_163 )
{
if ( ! V_163 )
F_75 ( & V_2 -> V_8 . V_57 -> V_137 . V_138 ) ;
if ( ! ( V_2 -> V_130 & V_164 ) )
return 0 ;
if ( V_163 ) {
F_10 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_8 . V_16 . V_3 != V_13 ) {
if ( ! V_162 )
return 0 ;
if ( V_2 -> V_72 >= 0 )
F_10 ( V_2 ) ;
return 0 ;
}
if ( ( V_2 -> V_72 >= 0 ) && ! V_162 )
return 0 ;
return F_74 ( V_2 ) ;
}
void F_84 ( struct V_15 * V_2 ,
struct V_165 * V_166 )
{
struct V_1 * V_23 ;
if ( ! F_15 ( V_2 ) )
return;
V_23 = F_5 ( V_2 , struct V_1 , V_8 ) ;
F_33 ( V_23 , 0 , 1 ) ;
F_85 ( V_23 -> V_6 , V_23 ) ;
if ( ! V_166 )
return;
F_1 ( V_23 , V_2 -> V_16 . V_3 , - 1 ) ;
F_1 ( V_23 , V_166 -> V_3 , 1 ) ;
}
int F_86 ( struct V_15 * V_2 )
{
struct V_5 * V_6 ;
struct V_1 * V_23 ;
unsigned long V_167 , V_7 ;
int V_63 ;
if ( ! F_15 ( V_2 ) )
return 0 ;
V_23 = F_5 ( V_2 , struct V_1 , V_8 ) ;
F_33 ( V_23 , 0 , 0 ) ;
V_6 = V_23 -> V_6 ;
if ( V_2 -> V_16 . V_3 != V_13 )
return 0 ;
V_7 = V_2 -> V_16 . V_9 << V_10 ;
V_167 = V_2 -> V_16 . V_143 << V_10 ;
if ( ( V_167 + V_7 ) <= V_6 -> V_49 . V_50 )
return 0 ;
F_16 ( V_23 , V_30 ) ;
V_23 -> V_28 [ 0 ] . V_48 = V_6 -> V_49 . V_50 >> V_10 ;
V_63 = F_44 ( V_2 , & V_23 -> V_27 , false , false ) ;
if ( F_23 ( V_63 == - V_70 ) ) {
F_16 ( V_23 , V_35 ) ;
return F_44 ( V_2 , & V_23 -> V_27 , false , false ) ;
} else if ( F_23 ( V_63 != 0 ) ) {
return V_63 ;
}
V_167 = V_2 -> V_16 . V_143 << V_10 ;
if ( ( V_167 + V_7 ) > V_6 -> V_49 . V_50 )
return - V_161 ;
return 0 ;
}
int F_87 ( struct V_1 * V_2 , T_2 * V_3 , bool V_168 )
{
int V_63 ;
V_63 = F_88 ( & V_2 -> V_8 , true , V_168 , false , NULL ) ;
if ( F_23 ( V_63 != 0 ) )
return V_63 ;
if ( V_3 )
* V_3 = V_2 -> V_8 . V_16 . V_3 ;
V_63 = F_89 ( & V_2 -> V_8 , true , true , V_168 ) ;
F_90 ( & V_2 -> V_8 ) ;
return V_63 ;
}
