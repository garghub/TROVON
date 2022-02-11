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
F_6 ( & V_2 -> V_6 -> V_17 . V_18 ) ;
F_7 ( & V_2 -> V_19 ) ;
F_8 ( & V_2 -> V_6 -> V_17 . V_18 ) ;
F_9 ( V_2 ) ;
F_10 ( ! F_11 ( & V_2 -> V_20 ) ) ;
F_12 ( & V_2 -> V_21 ) ;
F_13 ( V_2 ) ;
}
bool F_14 ( struct V_15 * V_2 )
{
if ( V_2 -> V_22 == & F_4 )
return true ;
return false ;
}
void F_15 ( struct V_1 * V_23 , T_2 V_24 )
{
T_2 V_25 = 0 , V_26 ;
V_23 -> V_27 . V_27 = V_23 -> V_28 ;
V_23 -> V_27 . V_29 = V_23 -> V_28 ;
if ( V_24 & V_30 ) {
if ( ( V_23 -> V_31 & V_32 ) &&
V_23 -> V_6 -> V_33 . V_34 < V_23 -> V_6 -> V_33 . V_35 ) {
V_23 -> V_28 [ V_25 ] . V_36 =
V_23 -> V_6 -> V_33 . V_34 >> V_10 ;
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_37 |
V_38 |
V_39 ;
}
V_23 -> V_28 [ V_25 ] . V_36 = 0 ;
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_37 |
V_38 |
V_39 ;
}
if ( V_24 & V_40 ) {
if ( V_23 -> V_31 & V_41 ) {
V_23 -> V_28 [ V_25 ] . V_36 = 0 ;
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_38 |
V_42 ;
} else if ( ( V_23 -> V_31 & V_43 ) ||
( V_23 -> V_6 -> V_31 & V_44 ) ) {
V_23 -> V_28 [ V_25 ] . V_36 = 0 ;
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_37 |
V_38 |
V_42 ;
} else {
V_23 -> V_28 [ V_25 ] . V_36 = 0 ;
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_45 |
V_42 ;
}
}
if ( V_24 & V_46 ) {
if ( V_23 -> V_31 & V_41 ) {
V_23 -> V_28 [ V_25 ] . V_36 = 0 ;
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_38 |
V_47 ;
} else if ( ( V_23 -> V_31 & V_43 ) ||
V_23 -> V_6 -> V_31 & V_44 ) {
V_23 -> V_28 [ V_25 ] . V_36 = 0 ;
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_37 |
V_38 |
V_47 ;
} else {
V_23 -> V_28 [ V_25 ] . V_36 = 0 ;
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_45 |
V_47 ;
}
}
if ( ! V_25 ) {
V_23 -> V_28 [ V_25 ] . V_36 = 0 ;
V_23 -> V_28 [ V_25 ++ ] . V_31 = V_48 |
V_47 ;
}
V_23 -> V_27 . V_49 = V_25 ;
V_23 -> V_27 . V_50 = V_25 ;
for ( V_26 = 0 ; V_26 < V_25 ; ++ V_26 ) {
if ( ( V_23 -> V_31 & V_51 ) &&
( V_23 -> V_28 [ V_26 ] . V_31 & V_39 ) &&
! V_23 -> V_28 [ V_26 ] . V_36 )
V_23 -> V_28 [ V_26 ] . V_52 =
V_23 -> V_6 -> V_33 . V_34 >> V_10 ;
else
V_23 -> V_28 [ V_26 ] . V_52 = 0 ;
}
}
int F_16 ( struct V_5 * V_6 ,
unsigned long V_7 , int V_53 , bool V_54 ,
T_2 V_24 , T_2 V_31 , struct V_55 * V_56 ,
struct V_57 * V_58 ,
struct V_1 * * V_59 )
{
struct V_1 * V_2 ;
enum V_60 type ;
unsigned long V_61 = F_17 ( V_53 , V_62 ) >> V_10 ;
T_3 V_63 ;
int V_64 ;
V_7 = F_18 ( V_7 , V_62 ) ;
if ( V_54 ) {
type = V_65 ;
} else if ( V_56 ) {
type = V_66 ;
} else {
type = V_67 ;
}
* V_59 = NULL ;
V_63 = F_19 ( & V_6 -> V_68 . V_69 , V_7 ,
sizeof( struct V_1 ) ) ;
V_2 = F_20 ( sizeof( struct V_1 ) , V_70 ) ;
if ( V_2 == NULL )
return - V_71 ;
V_64 = F_21 ( V_6 -> V_72 , & V_2 -> V_21 , V_7 ) ;
if ( F_22 ( V_64 ) ) {
F_13 ( V_2 ) ;
return V_64 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_73 = - 1 ;
F_23 ( & V_2 -> V_19 ) ;
F_23 ( & V_2 -> V_20 ) ;
V_2 -> V_74 = V_24 & ( V_30 |
V_40 |
V_46 ) ;
V_2 -> V_31 = V_31 ;
if ( ! ( V_6 -> V_31 & V_75 ) )
V_2 -> V_31 &= ~ ( V_43 | V_41 ) ;
#ifdef F_24
V_2 -> V_31 &= ~ V_43 ;
#elif F_25 ( V_76 ) && ! F_25 ( V_77 )
#warning Please enable CONFIG_MTRR and CONFIG_X86_PAT for better performance \
thanks to write-combining
F_26 ( L_1
L_2 ) ;
V_2 -> V_31 &= ~ V_43 ;
#endif
F_15 ( V_2 , V_24 ) ;
F_27 ( & V_6 -> V_78 . V_79 ) ;
V_64 = F_28 ( & V_6 -> V_68 . V_69 , & V_2 -> V_8 , V_7 , type ,
& V_2 -> V_27 , V_61 , ! V_54 , NULL ,
V_63 , V_56 , V_58 , & F_4 ) ;
F_29 ( & V_6 -> V_78 . V_79 ) ;
if ( F_22 ( V_64 != 0 ) ) {
return V_64 ;
}
* V_59 = V_2 ;
F_30 ( V_2 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , void * * V_80 )
{
bool V_81 ;
int V_64 ;
if ( V_2 -> V_82 ) {
if ( V_80 ) {
* V_80 = V_2 -> V_82 ;
}
return 0 ;
}
V_64 = F_32 ( & V_2 -> V_8 , 0 , V_2 -> V_8 . V_9 , & V_2 -> V_83 ) ;
if ( V_64 ) {
return V_64 ;
}
V_2 -> V_82 = F_33 ( & V_2 -> V_83 , & V_81 ) ;
if ( V_80 ) {
* V_80 = V_2 -> V_82 ;
}
F_34 ( V_2 , 0 , 0 ) ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_82 == NULL )
return;
V_2 -> V_82 = NULL ;
F_34 ( V_2 , 0 , 0 ) ;
F_36 ( & V_2 -> V_83 ) ;
}
struct V_1 * F_37 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return NULL ;
F_38 ( & V_2 -> V_8 ) ;
return V_2 ;
}
void F_39 ( struct V_1 * * V_2 )
{
struct V_15 * V_8 ;
struct V_5 * V_6 ;
if ( ( * V_2 ) == NULL )
return;
V_6 = ( * V_2 ) -> V_6 ;
V_8 = & ( ( * V_2 ) -> V_8 ) ;
F_40 ( & V_8 ) ;
if ( V_8 == NULL )
* V_2 = NULL ;
}
int F_41 ( struct V_1 * V_2 , T_2 V_24 , T_1 V_84 ,
T_1 * V_85 )
{
int V_64 , V_26 ;
if ( F_42 ( V_2 -> V_8 . V_86 ) )
return - V_87 ;
if ( V_2 -> V_88 ) {
V_2 -> V_88 ++ ;
if ( V_85 )
* V_85 = F_43 ( V_2 ) ;
if ( V_84 != 0 ) {
T_1 V_89 ;
if ( V_24 == V_30 )
V_89 = V_2 -> V_6 -> V_33 . V_90 ;
else
V_89 = V_2 -> V_6 -> V_33 . V_91 ;
F_44 ( V_84 <
( F_43 ( V_2 ) - V_89 ) ) ;
}
return 0 ;
}
F_15 ( V_2 , V_24 ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_27 . V_49 ; V_26 ++ ) {
if ( ( V_2 -> V_28 [ V_26 ] . V_31 & V_39 ) &&
! ( V_2 -> V_31 & V_32 ) &&
( ! V_84 || V_84 > V_2 -> V_6 -> V_33 . V_34 ) )
V_2 -> V_28 [ V_26 ] . V_52 =
V_2 -> V_6 -> V_33 . V_34 >> V_10 ;
else
V_2 -> V_28 [ V_26 ] . V_52 = V_84 >> V_10 ;
V_2 -> V_28 [ V_26 ] . V_31 |= V_92 ;
}
V_64 = F_45 ( & V_2 -> V_8 , & V_2 -> V_27 , false , false ) ;
if ( F_46 ( V_64 == 0 ) ) {
V_2 -> V_88 = 1 ;
if ( V_85 != NULL )
* V_85 = F_43 ( V_2 ) ;
if ( V_24 == V_30 )
V_2 -> V_6 -> V_93 += F_47 ( V_2 ) ;
else
V_2 -> V_6 -> V_94 += F_47 ( V_2 ) ;
} else {
F_48 ( V_2 -> V_6 -> V_95 , L_3 , V_2 ) ;
}
return V_64 ;
}
int F_49 ( struct V_1 * V_2 , T_2 V_24 , T_1 * V_85 )
{
return F_41 ( V_2 , V_24 , 0 , V_85 ) ;
}
int F_50 ( struct V_1 * V_2 )
{
int V_64 , V_26 ;
if ( ! V_2 -> V_88 ) {
F_51 ( V_2 -> V_6 -> V_95 , L_4 , V_2 ) ;
return 0 ;
}
V_2 -> V_88 -- ;
if ( V_2 -> V_88 )
return 0 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_27 . V_49 ; V_26 ++ ) {
V_2 -> V_28 [ V_26 ] . V_52 = 0 ;
V_2 -> V_28 [ V_26 ] . V_31 &= ~ V_92 ;
}
V_64 = F_45 ( & V_2 -> V_8 , & V_2 -> V_27 , false , false ) ;
if ( F_46 ( V_64 == 0 ) ) {
if ( V_2 -> V_8 . V_16 . V_3 == V_13 )
V_2 -> V_6 -> V_93 -= F_47 ( V_2 ) ;
else
V_2 -> V_6 -> V_94 -= F_47 ( V_2 ) ;
} else {
F_48 ( V_2 -> V_6 -> V_95 , L_5 , V_2 ) ;
}
return V_64 ;
}
int F_52 ( struct V_5 * V_6 )
{
if ( 0 && ( V_6 -> V_31 & V_96 ) ) {
if ( V_6 -> V_33 . V_97 == false )
return 0 ;
}
return F_53 ( & V_6 -> V_68 . V_69 , V_13 ) ;
}
void F_54 ( struct V_5 * V_6 )
{
struct V_1 * V_2 , * V_98 ;
if ( F_11 ( & V_6 -> V_17 . V_99 ) ) {
return;
}
F_48 ( V_6 -> V_95 , L_6 ) ;
F_55 (bo, n, &rdev->gem.objects, list) {
F_48 ( V_6 -> V_95 , L_7 ,
& V_2 -> V_21 , V_2 , ( unsigned long ) V_2 -> V_21 . V_7 ,
* ( ( unsigned long * ) & V_2 -> V_21 . V_100 ) ) ;
F_6 ( & V_2 -> V_6 -> V_17 . V_18 ) ;
F_7 ( & V_2 -> V_19 ) ;
F_8 ( & V_2 -> V_6 -> V_17 . V_18 ) ;
F_56 ( & V_2 -> V_21 ) ;
}
}
int F_57 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_101 ) {
V_6 -> V_33 . V_102 = F_58 ( V_6 -> V_33 . V_103 ,
V_6 -> V_33 . V_104 ) ;
}
F_59 ( L_8 ,
V_6 -> V_33 . V_105 >> 20 ,
( unsigned long long ) V_6 -> V_33 . V_104 >> 20 ) ;
F_59 ( L_9 ,
V_6 -> V_33 . V_106 , V_6 -> V_33 . V_107 ? 'D' : 'S' ) ;
return F_60 ( V_6 ) ;
}
void F_61 ( struct V_5 * V_6 )
{
F_62 ( V_6 ) ;
F_63 ( V_6 -> V_33 . V_102 ) ;
}
static T_1 F_64 ( struct V_5 * V_6 )
{
T_1 V_35 = V_6 -> V_33 . V_35 ;
T_1 V_14 = F_65 ( & V_6 -> V_14 ) ;
T_1 V_108 = V_35 >> 1 ;
T_1 V_109 = V_14 >= V_108 ? 0 : V_108 - V_14 ;
T_1 V_110 = V_109 >> 1 ;
return F_66 ( V_110 , 1024 * 1024ull ) ;
}
int F_67 ( struct V_5 * V_6 ,
struct V_111 * V_112 ,
struct V_113 * V_114 , int V_115 )
{
struct V_116 * V_117 ;
struct V_113 V_118 ;
int V_64 ;
T_1 V_119 = 0 , V_120 ;
T_1 V_110 = F_64 ( V_6 ) ;
F_23 ( & V_118 ) ;
V_64 = F_68 ( V_112 , V_114 , true , & V_118 ) ;
if ( F_22 ( V_64 != 0 ) ) {
return V_64 ;
}
F_69 (lobj, head, tv.head) {
struct V_1 * V_2 = V_117 -> V_121 ;
if ( ! V_2 -> V_88 ) {
T_2 V_24 = V_117 -> V_122 ;
T_2 V_123 = V_117 -> V_124 ;
T_2 V_125 =
F_70 ( V_2 -> V_8 . V_16 . V_3 ) ;
if ( ( V_123 & V_125 ) != 0 &&
( V_24 & V_125 ) == 0 &&
V_119 > V_110 ) {
V_24 = V_125 ;
}
V_126:
F_15 ( V_2 , V_24 ) ;
if ( V_115 == V_127 )
F_71 ( V_2 , V_123 ) ;
V_120 = F_65 ( & V_6 -> V_128 ) ;
V_64 = F_45 ( & V_2 -> V_8 , & V_2 -> V_27 , true , false ) ;
V_119 += F_65 ( & V_6 -> V_128 ) -
V_120 ;
if ( F_22 ( V_64 ) ) {
if ( V_64 != - V_129 &&
V_24 != V_117 -> V_124 ) {
V_24 = V_117 -> V_124 ;
goto V_126;
}
F_72 ( V_112 , V_114 ) ;
return V_64 ;
}
}
V_117 -> V_130 = F_43 ( V_2 ) ;
V_117 -> V_131 = V_2 -> V_131 ;
}
F_69 (lobj, &duplicates, tv.head) {
V_117 -> V_130 = F_43 ( V_117 -> V_121 ) ;
V_117 -> V_131 = V_117 -> V_121 -> V_131 ;
}
return 0 ;
}
int F_73 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_132 * V_133 ;
struct V_1 * V_134 ;
int V_135 ;
int V_26 ;
F_74 ( & V_2 -> V_8 . V_58 -> V_136 . V_137 ) ;
if ( ! V_2 -> V_131 )
return 0 ;
if ( V_2 -> V_73 >= 0 ) {
V_133 = & V_6 -> V_138 [ V_2 -> V_73 ] ;
V_26 = V_2 -> V_73 ;
goto V_139;
}
V_135 = - 1 ;
for ( V_26 = 0 ; V_26 < V_140 ; V_26 ++ ) {
V_133 = & V_6 -> V_138 [ V_26 ] ;
if ( ! V_133 -> V_2 )
break;
V_134 = V_133 -> V_2 ;
if ( V_134 -> V_88 == 0 )
V_135 = V_26 ;
}
if ( V_26 == V_140 ) {
if ( V_135 == - 1 )
return - V_71 ;
V_133 = & V_6 -> V_138 [ V_135 ] ;
V_134 = V_133 -> V_2 ;
F_75 ( L_10 , V_135 , V_134 ) ;
F_76 ( & V_134 -> V_8 ) ;
V_134 -> V_73 = - 1 ;
V_26 = V_135 ;
}
V_2 -> V_73 = V_26 ;
V_133 -> V_2 = V_2 ;
V_139:
F_77 ( V_6 , V_26 , V_2 -> V_131 , V_2 -> V_141 ,
V_2 -> V_8 . V_16 . V_142 << V_10 ,
V_2 -> V_8 . V_9 << V_10 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_132 * V_133 ;
if ( V_2 -> V_73 == - 1 )
return;
V_133 = & V_6 -> V_138 [ V_2 -> V_73 ] ;
F_78 ( V_6 , V_2 -> V_73 ) ;
V_133 -> V_2 = NULL ;
V_2 -> V_73 = - 1 ;
}
int F_79 ( struct V_1 * V_2 ,
T_4 V_131 , T_4 V_141 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_64 ;
if ( V_6 -> V_143 >= V_144 ) {
unsigned V_145 , V_146 , V_147 , V_148 , V_149 ;
V_145 = ( V_131 >> V_150 ) & V_151 ;
V_146 = ( V_131 >> V_152 ) & V_153 ;
V_147 = ( V_131 >> V_154 ) & V_155 ;
V_148 = ( V_131 >> V_156 ) & V_157 ;
V_149 = ( V_131 >> V_158 ) & V_159 ;
switch ( V_145 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_160 ;
}
switch ( V_146 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_160 ;
}
switch ( V_147 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_160 ;
}
if ( V_148 > 6 ) {
return - V_160 ;
}
if ( V_149 > 6 ) {
return - V_160 ;
}
}
V_64 = F_80 ( V_2 , false ) ;
if ( F_22 ( V_64 != 0 ) )
return V_64 ;
V_2 -> V_131 = V_131 ;
V_2 -> V_141 = V_141 ;
F_81 ( V_2 ) ;
return 0 ;
}
void F_82 ( struct V_1 * V_2 ,
T_4 * V_131 ,
T_4 * V_141 )
{
F_74 ( & V_2 -> V_8 . V_58 -> V_136 . V_137 ) ;
if ( V_131 )
* V_131 = V_2 -> V_131 ;
if ( V_141 )
* V_141 = V_2 -> V_141 ;
}
int F_34 ( struct V_1 * V_2 , bool V_161 ,
bool V_162 )
{
if ( ! V_162 )
F_74 ( & V_2 -> V_8 . V_58 -> V_136 . V_137 ) ;
if ( ! ( V_2 -> V_131 & V_163 ) )
return 0 ;
if ( V_162 ) {
F_9 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_8 . V_16 . V_3 != V_13 ) {
if ( ! V_161 )
return 0 ;
if ( V_2 -> V_73 >= 0 )
F_9 ( V_2 ) ;
return 0 ;
}
if ( ( V_2 -> V_73 >= 0 ) && ! V_161 )
return 0 ;
return F_73 ( V_2 ) ;
}
void F_83 ( struct V_15 * V_2 ,
struct V_164 * V_165 )
{
struct V_1 * V_23 ;
if ( ! F_14 ( V_2 ) )
return;
V_23 = F_5 ( V_2 , struct V_1 , V_8 ) ;
F_34 ( V_23 , 0 , 1 ) ;
F_84 ( V_23 -> V_6 , V_23 ) ;
if ( ! V_165 )
return;
F_1 ( V_23 , V_2 -> V_16 . V_3 , - 1 ) ;
F_1 ( V_23 , V_165 -> V_3 , 1 ) ;
}
int F_85 ( struct V_15 * V_2 )
{
struct V_5 * V_6 ;
struct V_1 * V_23 ;
unsigned long V_166 , V_7 , V_52 ;
int V_26 , V_64 ;
if ( ! F_14 ( V_2 ) )
return 0 ;
V_23 = F_5 ( V_2 , struct V_1 , V_8 ) ;
F_34 ( V_23 , 0 , 0 ) ;
V_6 = V_23 -> V_6 ;
if ( V_2 -> V_16 . V_3 != V_13 )
return 0 ;
V_7 = V_2 -> V_16 . V_9 << V_10 ;
V_166 = V_2 -> V_16 . V_142 << V_10 ;
if ( ( V_166 + V_7 ) <= V_6 -> V_33 . V_34 )
return 0 ;
F_15 ( V_23 , V_30 ) ;
V_52 = V_6 -> V_33 . V_34 >> V_10 ;
for ( V_26 = 0 ; V_26 < V_23 -> V_27 . V_49 ; V_26 ++ ) {
if ( ( V_23 -> V_28 [ V_26 ] . V_31 & V_39 ) &&
( ! V_23 -> V_28 [ V_26 ] . V_52 || V_23 -> V_28 [ V_26 ] . V_52 > V_52 ) )
V_23 -> V_28 [ V_26 ] . V_52 = V_52 ;
}
V_64 = F_45 ( V_2 , & V_23 -> V_27 , false , false ) ;
if ( F_22 ( V_64 == - V_71 ) ) {
F_15 ( V_23 , V_40 ) ;
return F_45 ( V_2 , & V_23 -> V_27 , false , false ) ;
} else if ( F_22 ( V_64 != 0 ) ) {
return V_64 ;
}
V_166 = V_2 -> V_16 . V_142 << V_10 ;
if ( ( V_166 + V_7 ) > V_6 -> V_33 . V_34 )
return - V_160 ;
return 0 ;
}
int F_86 ( struct V_1 * V_2 , T_2 * V_3 , bool V_167 )
{
int V_64 ;
V_64 = F_87 ( & V_2 -> V_8 , true , V_167 , false , NULL ) ;
if ( F_22 ( V_64 != 0 ) )
return V_64 ;
if ( V_3 )
* V_3 = V_2 -> V_8 . V_16 . V_3 ;
V_64 = F_88 ( & V_2 -> V_8 , true , true , V_167 ) ;
F_89 ( & V_2 -> V_8 ) ;
return V_64 ;
}
void F_90 ( struct V_1 * V_2 , struct V_168 * V_169 ,
bool V_170 )
{
struct V_57 * V_58 = V_2 -> V_8 . V_58 ;
if ( V_170 )
F_91 ( V_58 , & V_169 -> V_137 ) ;
else
F_92 ( V_58 , & V_169 -> V_137 ) ;
}
