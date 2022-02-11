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
if ( V_6 -> V_76 >= V_77 && V_6 -> V_76 <= V_78 )
V_2 -> V_31 &= ~ ( V_43 | V_41 ) ;
#ifdef F_24
V_2 -> V_31 &= ~ ( V_43 | V_41 ) ;
#elif F_25 ( V_79 ) && ! F_25 ( V_80 )
#warning Please enable CONFIG_MTRR and CONFIG_X86_PAT for better performance \
thanks to write-combining
if ( V_2 -> V_31 & V_43 )
F_26 ( L_1
L_2 ) ;
V_2 -> V_31 &= ~ ( V_43 | V_41 ) ;
#else
if ( ! F_27 () )
V_2 -> V_31 &= ~ V_43 ;
#endif
F_15 ( V_2 , V_24 ) ;
F_28 ( & V_6 -> V_81 . V_82 ) ;
V_64 = F_29 ( & V_6 -> V_68 . V_69 , & V_2 -> V_8 , V_7 , type ,
& V_2 -> V_27 , V_61 , ! V_54 , NULL ,
V_63 , V_56 , V_58 , & F_4 ) ;
F_30 ( & V_6 -> V_81 . V_82 ) ;
if ( F_22 ( V_64 != 0 ) ) {
return V_64 ;
}
* V_59 = V_2 ;
F_31 ( V_2 ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , void * * V_83 )
{
bool V_84 ;
int V_64 ;
if ( V_2 -> V_85 ) {
if ( V_83 ) {
* V_83 = V_2 -> V_85 ;
}
return 0 ;
}
V_64 = F_33 ( & V_2 -> V_8 , 0 , V_2 -> V_8 . V_9 , & V_2 -> V_86 ) ;
if ( V_64 ) {
return V_64 ;
}
V_2 -> V_85 = F_34 ( & V_2 -> V_86 , & V_84 ) ;
if ( V_83 ) {
* V_83 = V_2 -> V_85 ;
}
F_35 ( V_2 , 0 , 0 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_85 == NULL )
return;
V_2 -> V_85 = NULL ;
F_35 ( V_2 , 0 , 0 ) ;
F_37 ( & V_2 -> V_86 ) ;
}
struct V_1 * F_38 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return NULL ;
F_39 ( & V_2 -> V_8 ) ;
return V_2 ;
}
void F_40 ( struct V_1 * * V_2 )
{
struct V_15 * V_8 ;
struct V_5 * V_6 ;
if ( ( * V_2 ) == NULL )
return;
V_6 = ( * V_2 ) -> V_6 ;
V_8 = & ( ( * V_2 ) -> V_8 ) ;
F_41 ( & V_8 ) ;
if ( V_8 == NULL )
* V_2 = NULL ;
}
int F_42 ( struct V_1 * V_2 , T_2 V_24 , T_1 V_87 ,
T_1 * V_88 )
{
int V_64 , V_26 ;
if ( F_43 ( V_2 -> V_8 . V_89 ) )
return - V_90 ;
if ( V_2 -> V_91 ) {
V_2 -> V_91 ++ ;
if ( V_88 )
* V_88 = F_44 ( V_2 ) ;
if ( V_87 != 0 ) {
T_1 V_92 ;
if ( V_24 == V_30 )
V_92 = V_2 -> V_6 -> V_33 . V_93 ;
else
V_92 = V_2 -> V_6 -> V_33 . V_94 ;
F_45 ( V_87 <
( F_44 ( V_2 ) - V_92 ) ) ;
}
return 0 ;
}
F_15 ( V_2 , V_24 ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_27 . V_49 ; V_26 ++ ) {
if ( ( V_2 -> V_28 [ V_26 ] . V_31 & V_39 ) &&
! ( V_2 -> V_31 & V_32 ) &&
( ! V_87 || V_87 > V_2 -> V_6 -> V_33 . V_34 ) )
V_2 -> V_28 [ V_26 ] . V_52 =
V_2 -> V_6 -> V_33 . V_34 >> V_10 ;
else
V_2 -> V_28 [ V_26 ] . V_52 = V_87 >> V_10 ;
V_2 -> V_28 [ V_26 ] . V_31 |= V_95 ;
}
V_64 = F_46 ( & V_2 -> V_8 , & V_2 -> V_27 , false , false ) ;
if ( F_47 ( V_64 == 0 ) ) {
V_2 -> V_91 = 1 ;
if ( V_88 != NULL )
* V_88 = F_44 ( V_2 ) ;
if ( V_24 == V_30 )
V_2 -> V_6 -> V_96 += F_48 ( V_2 ) ;
else
V_2 -> V_6 -> V_97 += F_48 ( V_2 ) ;
} else {
F_49 ( V_2 -> V_6 -> V_98 , L_3 , V_2 ) ;
}
return V_64 ;
}
int F_50 ( struct V_1 * V_2 , T_2 V_24 , T_1 * V_88 )
{
return F_42 ( V_2 , V_24 , 0 , V_88 ) ;
}
int F_51 ( struct V_1 * V_2 )
{
int V_64 , V_26 ;
if ( ! V_2 -> V_91 ) {
F_52 ( V_2 -> V_6 -> V_98 , L_4 , V_2 ) ;
return 0 ;
}
V_2 -> V_91 -- ;
if ( V_2 -> V_91 )
return 0 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_27 . V_49 ; V_26 ++ ) {
V_2 -> V_28 [ V_26 ] . V_52 = 0 ;
V_2 -> V_28 [ V_26 ] . V_31 &= ~ V_95 ;
}
V_64 = F_46 ( & V_2 -> V_8 , & V_2 -> V_27 , false , false ) ;
if ( F_47 ( V_64 == 0 ) ) {
if ( V_2 -> V_8 . V_16 . V_3 == V_13 )
V_2 -> V_6 -> V_96 -= F_48 ( V_2 ) ;
else
V_2 -> V_6 -> V_97 -= F_48 ( V_2 ) ;
} else {
F_49 ( V_2 -> V_6 -> V_98 , L_5 , V_2 ) ;
}
return V_64 ;
}
int F_53 ( struct V_5 * V_6 )
{
if ( 0 && ( V_6 -> V_31 & V_99 ) ) {
if ( V_6 -> V_33 . V_100 == false )
return 0 ;
}
return F_54 ( & V_6 -> V_68 . V_69 , V_13 ) ;
}
void F_55 ( struct V_5 * V_6 )
{
struct V_1 * V_2 , * V_101 ;
if ( F_11 ( & V_6 -> V_17 . V_102 ) ) {
return;
}
F_49 ( V_6 -> V_98 , L_6 ) ;
F_56 (bo, n, &rdev->gem.objects, list) {
F_49 ( V_6 -> V_98 , L_7 ,
& V_2 -> V_21 , V_2 , ( unsigned long ) V_2 -> V_21 . V_7 ,
* ( ( unsigned long * ) & V_2 -> V_21 . V_103 ) ) ;
F_6 ( & V_2 -> V_6 -> V_17 . V_18 ) ;
F_7 ( & V_2 -> V_19 ) ;
F_8 ( & V_2 -> V_6 -> V_17 . V_18 ) ;
F_57 ( & V_2 -> V_21 ) ;
}
}
int F_58 ( struct V_5 * V_6 )
{
F_59 ( V_6 -> V_33 . V_104 ,
V_6 -> V_33 . V_105 ) ;
if ( ! V_6 -> V_106 ) {
V_6 -> V_33 . V_107 = F_60 ( V_6 -> V_33 . V_104 ,
V_6 -> V_33 . V_105 ) ;
}
F_61 ( L_8 ,
V_6 -> V_33 . V_108 >> 20 ,
( unsigned long long ) V_6 -> V_33 . V_105 >> 20 ) ;
F_61 ( L_9 ,
V_6 -> V_33 . V_109 , V_6 -> V_33 . V_110 ? 'D' : 'S' ) ;
return F_62 ( V_6 ) ;
}
void F_63 ( struct V_5 * V_6 )
{
F_64 ( V_6 ) ;
F_65 ( V_6 -> V_33 . V_107 ) ;
F_66 ( V_6 -> V_33 . V_104 , V_6 -> V_33 . V_105 ) ;
}
static T_1 F_67 ( struct V_5 * V_6 )
{
T_1 V_35 = V_6 -> V_33 . V_35 ;
T_1 V_14 = F_68 ( & V_6 -> V_14 ) ;
T_1 V_111 = V_35 >> 1 ;
T_1 V_112 = V_14 >= V_111 ? 0 : V_111 - V_14 ;
T_1 V_113 = V_112 >> 1 ;
return F_69 ( V_113 , 1024 * 1024ull ) ;
}
int F_70 ( struct V_5 * V_6 ,
struct V_114 * V_115 ,
struct V_116 * V_117 , int V_118 )
{
struct V_119 * V_120 ;
struct V_116 V_121 ;
int V_64 ;
T_1 V_122 = 0 , V_123 ;
T_1 V_113 = F_67 ( V_6 ) ;
F_23 ( & V_121 ) ;
V_64 = F_71 ( V_115 , V_117 , true , & V_121 ) ;
if ( F_22 ( V_64 != 0 ) ) {
return V_64 ;
}
F_72 (lobj, head, tv.head) {
struct V_1 * V_2 = V_120 -> V_124 ;
if ( ! V_2 -> V_91 ) {
T_2 V_24 = V_120 -> V_125 ;
T_2 V_126 = V_120 -> V_127 ;
T_2 V_128 =
F_73 ( V_2 -> V_8 . V_16 . V_3 ) ;
if ( ( V_126 & V_128 ) != 0 &&
( V_24 & V_128 ) == 0 &&
V_122 > V_113 ) {
V_24 = V_128 ;
}
V_129:
F_15 ( V_2 , V_24 ) ;
if ( V_118 == V_130 )
F_74 ( V_2 , V_126 ) ;
V_123 = F_68 ( & V_6 -> V_131 ) ;
V_64 = F_46 ( & V_2 -> V_8 , & V_2 -> V_27 , true , false ) ;
V_122 += F_68 ( & V_6 -> V_131 ) -
V_123 ;
if ( F_22 ( V_64 ) ) {
if ( V_64 != - V_132 &&
V_24 != V_120 -> V_127 ) {
V_24 = V_120 -> V_127 ;
goto V_129;
}
F_75 ( V_115 , V_117 ) ;
return V_64 ;
}
}
V_120 -> V_133 = F_44 ( V_2 ) ;
V_120 -> V_134 = V_2 -> V_134 ;
}
F_72 (lobj, &duplicates, tv.head) {
V_120 -> V_133 = F_44 ( V_120 -> V_124 ) ;
V_120 -> V_134 = V_120 -> V_124 -> V_134 ;
}
return 0 ;
}
int F_76 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_135 * V_136 ;
struct V_1 * V_137 ;
int V_138 ;
int V_26 ;
F_77 ( & V_2 -> V_8 . V_58 -> V_139 . V_140 ) ;
if ( ! V_2 -> V_134 )
return 0 ;
if ( V_2 -> V_73 >= 0 ) {
V_136 = & V_6 -> V_141 [ V_2 -> V_73 ] ;
V_26 = V_2 -> V_73 ;
goto V_142;
}
V_138 = - 1 ;
for ( V_26 = 0 ; V_26 < V_143 ; V_26 ++ ) {
V_136 = & V_6 -> V_141 [ V_26 ] ;
if ( ! V_136 -> V_2 )
break;
V_137 = V_136 -> V_2 ;
if ( V_137 -> V_91 == 0 )
V_138 = V_26 ;
}
if ( V_26 == V_143 ) {
if ( V_138 == - 1 )
return - V_71 ;
V_136 = & V_6 -> V_141 [ V_138 ] ;
V_137 = V_136 -> V_2 ;
F_78 ( L_10 , V_138 , V_137 ) ;
F_79 ( & V_137 -> V_8 ) ;
V_137 -> V_73 = - 1 ;
V_26 = V_138 ;
}
V_2 -> V_73 = V_26 ;
V_136 -> V_2 = V_2 ;
V_142:
F_80 ( V_6 , V_26 , V_2 -> V_134 , V_2 -> V_144 ,
V_2 -> V_8 . V_16 . V_145 << V_10 ,
V_2 -> V_8 . V_9 << V_10 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_135 * V_136 ;
if ( V_2 -> V_73 == - 1 )
return;
V_136 = & V_6 -> V_141 [ V_2 -> V_73 ] ;
F_81 ( V_6 , V_2 -> V_73 ) ;
V_136 -> V_2 = NULL ;
V_2 -> V_73 = - 1 ;
}
int F_82 ( struct V_1 * V_2 ,
T_4 V_134 , T_4 V_144 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_64 ;
if ( V_6 -> V_76 >= V_146 ) {
unsigned V_147 , V_148 , V_149 , V_150 , V_151 ;
V_147 = ( V_134 >> V_152 ) & V_153 ;
V_148 = ( V_134 >> V_154 ) & V_155 ;
V_149 = ( V_134 >> V_156 ) & V_157 ;
V_150 = ( V_134 >> V_158 ) & V_159 ;
V_151 = ( V_134 >> V_160 ) & V_161 ;
switch ( V_147 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_162 ;
}
switch ( V_148 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_162 ;
}
switch ( V_149 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_162 ;
}
if ( V_150 > 6 ) {
return - V_162 ;
}
if ( V_151 > 6 ) {
return - V_162 ;
}
}
V_64 = F_83 ( V_2 , false ) ;
if ( F_22 ( V_64 != 0 ) )
return V_64 ;
V_2 -> V_134 = V_134 ;
V_2 -> V_144 = V_144 ;
F_84 ( V_2 ) ;
return 0 ;
}
void F_85 ( struct V_1 * V_2 ,
T_4 * V_134 ,
T_4 * V_144 )
{
F_77 ( & V_2 -> V_8 . V_58 -> V_139 . V_140 ) ;
if ( V_134 )
* V_134 = V_2 -> V_134 ;
if ( V_144 )
* V_144 = V_2 -> V_144 ;
}
int F_35 ( struct V_1 * V_2 , bool V_163 ,
bool V_164 )
{
if ( ! V_164 )
F_77 ( & V_2 -> V_8 . V_58 -> V_139 . V_140 ) ;
if ( ! ( V_2 -> V_134 & V_165 ) )
return 0 ;
if ( V_164 ) {
F_9 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_8 . V_16 . V_3 != V_13 ) {
if ( ! V_163 )
return 0 ;
if ( V_2 -> V_73 >= 0 )
F_9 ( V_2 ) ;
return 0 ;
}
if ( ( V_2 -> V_73 >= 0 ) && ! V_163 )
return 0 ;
return F_76 ( V_2 ) ;
}
void F_86 ( struct V_15 * V_2 ,
bool V_166 ,
struct V_167 * V_168 )
{
struct V_1 * V_23 ;
if ( ! F_14 ( V_2 ) )
return;
V_23 = F_5 ( V_2 , struct V_1 , V_8 ) ;
F_35 ( V_23 , 0 , 1 ) ;
F_87 ( V_23 -> V_6 , V_23 ) ;
if ( ! V_168 )
return;
F_1 ( V_23 , V_2 -> V_16 . V_3 , - 1 ) ;
F_1 ( V_23 , V_168 -> V_3 , 1 ) ;
}
int F_88 ( struct V_15 * V_2 )
{
struct V_5 * V_6 ;
struct V_1 * V_23 ;
unsigned long V_169 , V_7 , V_52 ;
int V_26 , V_64 ;
if ( ! F_14 ( V_2 ) )
return 0 ;
V_23 = F_5 ( V_2 , struct V_1 , V_8 ) ;
F_35 ( V_23 , 0 , 0 ) ;
V_6 = V_23 -> V_6 ;
if ( V_2 -> V_16 . V_3 != V_13 )
return 0 ;
V_7 = V_2 -> V_16 . V_9 << V_10 ;
V_169 = V_2 -> V_16 . V_145 << V_10 ;
if ( ( V_169 + V_7 ) <= V_6 -> V_33 . V_34 )
return 0 ;
if ( V_23 -> V_91 > 0 )
return - V_162 ;
F_15 ( V_23 , V_30 ) ;
V_52 = V_6 -> V_33 . V_34 >> V_10 ;
for ( V_26 = 0 ; V_26 < V_23 -> V_27 . V_49 ; V_26 ++ ) {
if ( ( V_23 -> V_28 [ V_26 ] . V_31 & V_39 ) &&
( ! V_23 -> V_28 [ V_26 ] . V_52 || V_23 -> V_28 [ V_26 ] . V_52 > V_52 ) )
V_23 -> V_28 [ V_26 ] . V_52 = V_52 ;
}
V_64 = F_46 ( V_2 , & V_23 -> V_27 , false , false ) ;
if ( F_22 ( V_64 == - V_71 ) ) {
F_15 ( V_23 , V_40 ) ;
return F_46 ( V_2 , & V_23 -> V_27 , false , false ) ;
} else if ( F_22 ( V_64 != 0 ) ) {
return V_64 ;
}
V_169 = V_2 -> V_16 . V_145 << V_10 ;
if ( ( V_169 + V_7 ) > V_6 -> V_33 . V_34 )
return - V_162 ;
return 0 ;
}
int F_89 ( struct V_1 * V_2 , T_2 * V_3 , bool V_170 )
{
int V_64 ;
V_64 = F_90 ( & V_2 -> V_8 , true , V_170 , NULL ) ;
if ( F_22 ( V_64 != 0 ) )
return V_64 ;
if ( V_3 )
* V_3 = V_2 -> V_8 . V_16 . V_3 ;
V_64 = F_91 ( & V_2 -> V_8 , true , V_170 ) ;
F_92 ( & V_2 -> V_8 ) ;
return V_64 ;
}
void F_93 ( struct V_1 * V_2 , struct V_171 * V_172 ,
bool V_173 )
{
struct V_57 * V_58 = V_2 -> V_8 . V_58 ;
if ( V_173 )
F_94 ( V_58 , & V_172 -> V_140 ) ;
else
F_95 ( V_58 , & V_172 -> V_140 ) ;
}
