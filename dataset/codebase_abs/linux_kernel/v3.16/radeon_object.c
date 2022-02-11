static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 (bo_va, tmp, &bo->va, bo_list) {
F_3 ( V_2 -> V_6 , V_4 ) ;
}
}
static void F_4 ( struct V_1 * V_2 ,
unsigned V_7 , int V_8 )
{
struct V_9 * V_6 = V_2 -> V_6 ;
T_1 V_10 = ( T_1 ) V_2 -> V_11 . V_12 << V_13 ;
switch ( V_7 ) {
case V_14 :
if ( V_8 > 0 )
F_5 ( V_10 , & V_6 -> V_15 ) ;
else
F_6 ( V_10 , & V_6 -> V_15 ) ;
break;
case V_16 :
if ( V_8 > 0 )
F_5 ( V_10 , & V_6 -> V_17 ) ;
else
F_6 ( V_10 , & V_6 -> V_17 ) ;
break;
}
}
static void F_7 ( struct V_18 * V_11 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_11 , struct V_1 , V_11 ) ;
F_4 ( V_2 , V_2 -> V_11 . V_19 . V_7 , - 1 ) ;
F_9 ( & V_2 -> V_6 -> V_20 . V_21 ) ;
F_10 ( & V_2 -> V_22 ) ;
F_11 ( & V_2 -> V_6 -> V_20 . V_21 ) ;
F_12 ( V_2 ) ;
F_1 ( V_2 ) ;
F_13 ( & V_2 -> V_23 ) ;
F_14 ( V_2 ) ;
}
bool F_15 ( struct V_18 * V_2 )
{
if ( V_2 -> V_24 == & F_7 )
return true ;
return false ;
}
void F_16 ( struct V_1 * V_25 , T_2 V_26 )
{
T_2 V_27 = 0 , V_28 ;
V_25 -> V_29 . V_30 = 0 ;
V_25 -> V_29 . V_31 = 0 ;
V_25 -> V_29 . V_29 = V_25 -> V_32 ;
V_25 -> V_29 . V_33 = V_25 -> V_32 ;
if ( V_26 & V_34 )
V_25 -> V_32 [ V_27 ++ ] = V_35 | V_36 |
V_37 ;
if ( V_26 & V_38 ) {
if ( V_25 -> V_6 -> V_39 & V_40 ) {
V_25 -> V_32 [ V_27 ++ ] = V_35 | V_41 ;
} else {
V_25 -> V_32 [ V_27 ++ ] = V_42 | V_41 ;
}
}
if ( V_26 & V_43 ) {
if ( V_25 -> V_6 -> V_39 & V_40 ) {
V_25 -> V_32 [ V_27 ++ ] = V_35 | V_44 ;
} else {
V_25 -> V_32 [ V_27 ++ ] = V_42 | V_44 ;
}
}
if ( ! V_27 )
V_25 -> V_32 [ V_27 ++ ] = V_45 | V_44 ;
V_25 -> V_29 . V_46 = V_27 ;
V_25 -> V_29 . V_47 = V_27 ;
if ( V_25 -> V_11 . V_19 . V_10 > 512 * 1024 ) {
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ ) {
V_25 -> V_32 [ V_28 ] |= V_48 ;
}
}
}
int F_17 ( struct V_9 * V_6 ,
unsigned long V_10 , int V_49 , bool V_50 , T_2 V_26 ,
struct V_51 * V_52 , struct V_1 * * V_53 )
{
struct V_1 * V_2 ;
enum V_54 type ;
unsigned long V_55 = F_18 ( V_49 , V_56 ) >> V_13 ;
T_3 V_57 ;
int V_58 ;
V_10 = F_19 ( V_10 , V_56 ) ;
if ( V_50 ) {
type = V_59 ;
} else if ( V_52 ) {
type = V_60 ;
} else {
type = V_61 ;
}
* V_53 = NULL ;
V_57 = F_20 ( & V_6 -> V_62 . V_63 , V_10 ,
sizeof( struct V_1 ) ) ;
V_2 = F_21 ( sizeof( struct V_1 ) , V_64 ) ;
if ( V_2 == NULL )
return - V_65 ;
V_58 = F_22 ( V_6 -> V_66 , & V_2 -> V_23 , V_10 ) ;
if ( F_23 ( V_58 ) ) {
F_14 ( V_2 ) ;
return V_58 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_67 = - 1 ;
F_24 ( & V_2 -> V_22 ) ;
F_24 ( & V_2 -> V_68 ) ;
V_2 -> V_69 = V_26 & ( V_34 |
V_38 |
V_43 ) ;
F_16 ( V_2 , V_26 ) ;
F_25 ( & V_6 -> V_70 . V_71 ) ;
V_58 = F_26 ( & V_6 -> V_62 . V_63 , & V_2 -> V_11 , V_10 , type ,
& V_2 -> V_29 , V_55 , ! V_50 , NULL ,
V_57 , V_52 , & F_7 ) ;
F_27 ( & V_6 -> V_70 . V_71 ) ;
if ( F_23 ( V_58 != 0 ) ) {
return V_58 ;
}
* V_53 = V_2 ;
F_28 ( V_2 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 , void * * V_72 )
{
bool V_73 ;
int V_58 ;
if ( V_2 -> V_74 ) {
if ( V_72 ) {
* V_72 = V_2 -> V_74 ;
}
return 0 ;
}
V_58 = F_30 ( & V_2 -> V_11 , 0 , V_2 -> V_11 . V_12 , & V_2 -> V_75 ) ;
if ( V_58 ) {
return V_58 ;
}
V_2 -> V_74 = F_31 ( & V_2 -> V_75 , & V_73 ) ;
if ( V_72 ) {
* V_72 = V_2 -> V_74 ;
}
F_32 ( V_2 , 0 , 0 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_74 == NULL )
return;
V_2 -> V_74 = NULL ;
F_32 ( V_2 , 0 , 0 ) ;
F_34 ( & V_2 -> V_75 ) ;
}
void F_35 ( struct V_1 * * V_2 )
{
struct V_18 * V_11 ;
struct V_9 * V_6 ;
if ( ( * V_2 ) == NULL )
return;
V_6 = ( * V_2 ) -> V_6 ;
V_11 = & ( ( * V_2 ) -> V_11 ) ;
F_25 ( & V_6 -> V_70 . V_71 ) ;
F_36 ( & V_11 ) ;
F_27 ( & V_6 -> V_70 . V_71 ) ;
if ( V_11 == NULL )
* V_2 = NULL ;
}
int F_37 ( struct V_1 * V_2 , T_2 V_26 , T_1 V_76 ,
T_1 * V_77 )
{
int V_58 , V_28 ;
if ( V_2 -> V_78 ) {
V_2 -> V_78 ++ ;
if ( V_77 )
* V_77 = F_38 ( V_2 ) ;
if ( V_76 != 0 ) {
T_1 V_79 ;
if ( V_26 == V_34 )
V_79 = V_2 -> V_6 -> V_80 . V_81 ;
else
V_79 = V_2 -> V_6 -> V_80 . V_82 ;
F_39 ( V_76 <
( F_38 ( V_2 ) - V_79 ) ) ;
}
return 0 ;
}
F_16 ( V_2 , V_26 ) ;
if ( V_26 == V_34 ) {
V_2 -> V_29 . V_31 = V_2 -> V_6 -> V_80 . V_83 >> V_13 ;
}
if ( V_76 ) {
T_1 V_31 = V_76 >> V_13 ;
if ( ! V_2 -> V_29 . V_31 )
V_2 -> V_29 . V_31 = V_2 -> V_6 -> V_80 . V_84 >> V_13 ;
if ( V_31 < V_2 -> V_29 . V_31 )
V_2 -> V_29 . V_31 = V_31 ;
}
for ( V_28 = 0 ; V_28 < V_2 -> V_29 . V_46 ; V_28 ++ )
V_2 -> V_32 [ V_28 ] |= V_85 ;
V_58 = F_40 ( & V_2 -> V_11 , & V_2 -> V_29 , false , false ) ;
if ( F_41 ( V_58 == 0 ) ) {
V_2 -> V_78 = 1 ;
if ( V_77 != NULL )
* V_77 = F_38 ( V_2 ) ;
}
if ( F_23 ( V_58 != 0 ) )
F_42 ( V_2 -> V_6 -> V_86 , L_1 , V_2 ) ;
return V_58 ;
}
int F_43 ( struct V_1 * V_2 , T_2 V_26 , T_1 * V_77 )
{
return F_37 ( V_2 , V_26 , 0 , V_77 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_58 , V_28 ;
if ( ! V_2 -> V_78 ) {
F_45 ( V_2 -> V_6 -> V_86 , L_2 , V_2 ) ;
return 0 ;
}
V_2 -> V_78 -- ;
if ( V_2 -> V_78 )
return 0 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_29 . V_46 ; V_28 ++ )
V_2 -> V_32 [ V_28 ] &= ~ V_85 ;
V_58 = F_40 ( & V_2 -> V_11 , & V_2 -> V_29 , false , false ) ;
if ( F_23 ( V_58 != 0 ) )
F_42 ( V_2 -> V_6 -> V_86 , L_3 , V_2 ) ;
return V_58 ;
}
int F_46 ( struct V_9 * V_6 )
{
if ( 0 && ( V_6 -> V_39 & V_87 ) ) {
if ( V_6 -> V_80 . V_88 == false )
return 0 ;
}
return F_47 ( & V_6 -> V_62 . V_63 , V_16 ) ;
}
void F_48 ( struct V_9 * V_6 )
{
struct V_1 * V_2 , * V_89 ;
if ( F_49 ( & V_6 -> V_20 . V_90 ) ) {
return;
}
F_42 ( V_6 -> V_86 , L_4 ) ;
F_2 (bo, n, &rdev->gem.objects, list) {
F_9 ( & V_6 -> V_66 -> V_91 ) ;
F_42 ( V_6 -> V_86 , L_5 ,
& V_2 -> V_23 , V_2 , ( unsigned long ) V_2 -> V_23 . V_10 ,
* ( ( unsigned long * ) & V_2 -> V_23 . V_92 ) ) ;
F_9 ( & V_2 -> V_6 -> V_20 . V_21 ) ;
F_10 ( & V_2 -> V_22 ) ;
F_11 ( & V_2 -> V_6 -> V_20 . V_21 ) ;
F_50 ( & V_2 -> V_23 ) ;
F_11 ( & V_6 -> V_66 -> V_91 ) ;
}
}
int F_51 ( struct V_9 * V_6 )
{
if ( ! V_6 -> V_93 ) {
V_6 -> V_80 . V_94 = F_52 ( V_6 -> V_80 . V_95 ,
V_6 -> V_80 . V_96 ) ;
}
F_53 ( L_6 ,
V_6 -> V_80 . V_97 >> 20 ,
( unsigned long long ) V_6 -> V_80 . V_96 >> 20 ) ;
F_53 ( L_7 ,
V_6 -> V_80 . V_98 , V_6 -> V_80 . V_99 ? 'D' : 'S' ) ;
return F_54 ( V_6 ) ;
}
void F_55 ( struct V_9 * V_6 )
{
F_56 ( V_6 ) ;
F_57 ( V_6 -> V_80 . V_94 ) ;
}
static T_1 F_58 ( struct V_9 * V_6 )
{
T_1 V_100 = V_6 -> V_80 . V_100 ;
T_1 V_17 = F_59 ( & V_6 -> V_17 ) ;
T_1 V_101 = V_100 >> 1 ;
T_1 V_102 = V_17 >= V_101 ? 0 : V_101 - V_17 ;
T_1 V_103 = V_102 >> 1 ;
return F_60 ( V_103 , 1024 * 1024ull ) ;
}
int F_61 ( struct V_9 * V_6 ,
struct V_104 * V_105 ,
struct V_106 * V_107 , int V_108 )
{
struct V_109 * V_110 ;
struct V_1 * V_2 ;
int V_58 ;
T_1 V_111 = 0 , V_112 ;
T_1 V_103 = F_58 ( V_6 ) ;
V_58 = F_62 ( V_105 , V_107 ) ;
if ( F_23 ( V_58 != 0 ) ) {
return V_58 ;
}
F_63 (lobj, head, tv.head) {
V_2 = V_110 -> V_113 ;
if ( ! V_2 -> V_78 ) {
T_2 V_26 = V_110 -> V_114 ;
T_2 V_115 =
F_64 ( V_2 -> V_11 . V_19 . V_7 ) ;
if ( ( V_110 -> V_116 & V_115 ) != 0 &&
( V_26 & V_115 ) == 0 &&
V_111 > V_103 ) {
V_26 = V_115 ;
}
V_117:
F_16 ( V_2 , V_26 ) ;
if ( V_108 == V_118 )
F_65 ( V_2 ) ;
V_112 = F_59 ( & V_6 -> V_119 ) ;
V_58 = F_40 ( & V_2 -> V_11 , & V_2 -> V_29 , true , false ) ;
V_111 += F_59 ( & V_6 -> V_119 ) -
V_112 ;
if ( F_23 ( V_58 ) ) {
if ( V_58 != - V_120 &&
V_26 != V_110 -> V_116 ) {
V_26 = V_110 -> V_116 ;
goto V_117;
}
F_66 ( V_105 , V_107 ) ;
return V_58 ;
}
}
V_110 -> V_121 = F_38 ( V_2 ) ;
V_110 -> V_122 = V_2 -> V_122 ;
}
return 0 ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_123 * V_124 )
{
return F_68 ( V_124 , & V_2 -> V_11 ) ;
}
int F_69 ( struct V_1 * V_2 )
{
struct V_9 * V_6 = V_2 -> V_6 ;
struct V_125 * V_126 ;
struct V_1 * V_127 ;
int V_128 ;
int V_28 ;
F_70 ( & V_2 -> V_11 . V_129 -> V_130 . V_131 ) ;
if ( ! V_2 -> V_122 )
return 0 ;
if ( V_2 -> V_67 >= 0 ) {
V_126 = & V_6 -> V_132 [ V_2 -> V_67 ] ;
V_28 = V_2 -> V_67 ;
goto V_133;
}
V_128 = - 1 ;
for ( V_28 = 0 ; V_28 < V_134 ; V_28 ++ ) {
V_126 = & V_6 -> V_132 [ V_28 ] ;
if ( ! V_126 -> V_2 )
break;
V_127 = V_126 -> V_2 ;
if ( V_127 -> V_78 == 0 )
V_128 = V_28 ;
}
if ( V_28 == V_134 ) {
if ( V_128 == - 1 )
return - V_65 ;
V_126 = & V_6 -> V_132 [ V_128 ] ;
V_127 = V_126 -> V_2 ;
F_71 ( L_8 , V_128 , V_127 ) ;
F_72 ( & V_127 -> V_11 ) ;
V_127 -> V_67 = - 1 ;
V_28 = V_128 ;
}
V_2 -> V_67 = V_28 ;
V_126 -> V_2 = V_2 ;
V_133:
F_73 ( V_6 , V_28 , V_2 -> V_122 , V_2 -> V_135 ,
V_2 -> V_11 . V_19 . V_136 << V_13 ,
V_2 -> V_11 . V_12 << V_13 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_6 = V_2 -> V_6 ;
struct V_125 * V_126 ;
if ( V_2 -> V_67 == - 1 )
return;
V_126 = & V_6 -> V_132 [ V_2 -> V_67 ] ;
F_74 ( V_6 , V_2 -> V_67 ) ;
V_126 -> V_2 = NULL ;
V_2 -> V_67 = - 1 ;
}
int F_75 ( struct V_1 * V_2 ,
T_4 V_122 , T_4 V_135 )
{
struct V_9 * V_6 = V_2 -> V_6 ;
int V_58 ;
if ( V_6 -> V_137 >= V_138 ) {
unsigned V_139 , V_140 , V_141 , V_142 , V_143 ;
V_139 = ( V_122 >> V_144 ) & V_145 ;
V_140 = ( V_122 >> V_146 ) & V_147 ;
V_141 = ( V_122 >> V_148 ) & V_149 ;
V_142 = ( V_122 >> V_150 ) & V_151 ;
V_143 = ( V_122 >> V_152 ) & V_153 ;
switch ( V_139 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_154 ;
}
switch ( V_140 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_154 ;
}
switch ( V_141 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_154 ;
}
if ( V_142 > 6 ) {
return - V_154 ;
}
if ( V_143 > 6 ) {
return - V_154 ;
}
}
V_58 = F_76 ( V_2 , false ) ;
if ( F_23 ( V_58 != 0 ) )
return V_58 ;
V_2 -> V_122 = V_122 ;
V_2 -> V_135 = V_135 ;
F_77 ( V_2 ) ;
return 0 ;
}
void F_78 ( struct V_1 * V_2 ,
T_4 * V_122 ,
T_4 * V_135 )
{
F_70 ( & V_2 -> V_11 . V_129 -> V_130 . V_131 ) ;
if ( V_122 )
* V_122 = V_2 -> V_122 ;
if ( V_135 )
* V_135 = V_2 -> V_135 ;
}
int F_32 ( struct V_1 * V_2 , bool V_155 ,
bool V_156 )
{
if ( ! V_156 )
F_70 ( & V_2 -> V_11 . V_129 -> V_130 . V_131 ) ;
if ( ! ( V_2 -> V_122 & V_157 ) )
return 0 ;
if ( V_156 ) {
F_12 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_11 . V_19 . V_7 != V_16 ) {
if ( ! V_155 )
return 0 ;
if ( V_2 -> V_67 >= 0 )
F_12 ( V_2 ) ;
return 0 ;
}
if ( ( V_2 -> V_67 >= 0 ) && ! V_155 )
return 0 ;
return F_69 ( V_2 ) ;
}
void F_79 ( struct V_18 * V_2 ,
struct V_158 * V_159 )
{
struct V_1 * V_25 ;
if ( ! F_15 ( V_2 ) )
return;
V_25 = F_8 ( V_2 , struct V_1 , V_11 ) ;
F_32 ( V_25 , 0 , 1 ) ;
F_80 ( V_25 -> V_6 , V_25 ) ;
if ( ! V_159 )
return;
F_4 ( V_25 , V_2 -> V_19 . V_7 , - 1 ) ;
F_4 ( V_25 , V_159 -> V_7 , 1 ) ;
}
int F_81 ( struct V_18 * V_2 )
{
struct V_9 * V_6 ;
struct V_1 * V_25 ;
unsigned long V_160 , V_10 ;
int V_58 ;
if ( ! F_15 ( V_2 ) )
return 0 ;
V_25 = F_8 ( V_2 , struct V_1 , V_11 ) ;
F_32 ( V_25 , 0 , 0 ) ;
V_6 = V_25 -> V_6 ;
if ( V_2 -> V_19 . V_7 != V_16 )
return 0 ;
V_10 = V_2 -> V_19 . V_12 << V_13 ;
V_160 = V_2 -> V_19 . V_136 << V_13 ;
if ( ( V_160 + V_10 ) <= V_6 -> V_80 . V_83 )
return 0 ;
F_16 ( V_25 , V_34 ) ;
V_25 -> V_29 . V_31 = V_6 -> V_80 . V_83 >> V_13 ;
V_58 = F_40 ( V_2 , & V_25 -> V_29 , false , false ) ;
if ( F_23 ( V_58 == - V_65 ) ) {
F_16 ( V_25 , V_38 ) ;
return F_40 ( V_2 , & V_25 -> V_29 , false , false ) ;
} else if ( F_23 ( V_58 != 0 ) ) {
return V_58 ;
}
V_160 = V_2 -> V_19 . V_136 << V_13 ;
if ( ( V_160 + V_10 ) > V_6 -> V_80 . V_83 )
return - V_154 ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 , T_2 * V_7 , bool V_161 )
{
int V_58 ;
V_58 = F_83 ( & V_2 -> V_11 , true , V_161 , false , NULL ) ;
if ( F_23 ( V_58 != 0 ) )
return V_58 ;
F_84 ( & V_2 -> V_11 . V_63 -> V_162 ) ;
if ( V_7 )
* V_7 = V_2 -> V_11 . V_19 . V_7 ;
if ( V_2 -> V_11 . V_163 )
V_58 = F_85 ( & V_2 -> V_11 , true , true , V_161 ) ;
F_86 ( & V_2 -> V_11 . V_63 -> V_162 ) ;
F_87 ( & V_2 -> V_11 ) ;
return V_58 ;
}
