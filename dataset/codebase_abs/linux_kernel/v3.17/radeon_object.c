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
V_23 -> V_27 . V_28 = 0 ;
V_23 -> V_27 . V_29 = 0 ;
V_23 -> V_27 . V_27 = V_23 -> V_30 ;
V_23 -> V_27 . V_31 = V_23 -> V_30 ;
if ( V_24 & V_32 )
V_23 -> V_30 [ V_25 ++ ] = V_33 | V_34 |
V_35 ;
if ( V_24 & V_36 ) {
if ( V_23 -> V_37 & V_38 ) {
V_23 -> V_30 [ V_25 ++ ] = V_34 | V_39 ;
} else if ( ( V_23 -> V_37 & V_40 ) ||
( V_23 -> V_6 -> V_37 & V_41 ) ) {
V_23 -> V_30 [ V_25 ++ ] = V_33 | V_34 |
V_39 ;
} else {
V_23 -> V_30 [ V_25 ++ ] = V_42 | V_39 ;
}
}
if ( V_24 & V_43 ) {
if ( V_23 -> V_37 & V_38 ) {
V_23 -> V_30 [ V_25 ++ ] = V_34 | V_44 ;
} else if ( ( V_23 -> V_37 & V_40 ) ||
V_23 -> V_6 -> V_37 & V_41 ) {
V_23 -> V_30 [ V_25 ++ ] = V_33 | V_34 |
V_44 ;
} else {
V_23 -> V_30 [ V_25 ++ ] = V_42 | V_44 ;
}
}
if ( ! V_25 )
V_23 -> V_30 [ V_25 ++ ] = V_45 | V_44 ;
V_23 -> V_27 . V_46 = V_25 ;
V_23 -> V_27 . V_47 = V_25 ;
if ( V_23 -> V_8 . V_16 . V_7 > 512 * 1024 ) {
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
V_23 -> V_30 [ V_26 ] |= V_48 ;
}
}
}
int F_16 ( struct V_5 * V_6 ,
unsigned long V_7 , int V_49 , bool V_50 , T_2 V_24 ,
T_2 V_37 , struct V_51 * V_52 , struct V_1 * * V_53 )
{
struct V_1 * V_2 ;
enum V_54 type ;
unsigned long V_55 = F_17 ( V_49 , V_56 ) >> V_10 ;
T_3 V_57 ;
int V_58 ;
V_7 = F_18 ( V_7 , V_56 ) ;
if ( V_50 ) {
type = V_59 ;
} else if ( V_52 ) {
type = V_60 ;
} else {
type = V_61 ;
}
* V_53 = NULL ;
V_57 = F_19 ( & V_6 -> V_62 . V_63 , V_7 ,
sizeof( struct V_1 ) ) ;
V_2 = F_20 ( sizeof( struct V_1 ) , V_64 ) ;
if ( V_2 == NULL )
return - V_65 ;
V_58 = F_21 ( V_6 -> V_66 , & V_2 -> V_21 , V_7 ) ;
if ( F_22 ( V_58 ) ) {
F_13 ( V_2 ) ;
return V_58 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_67 = - 1 ;
F_23 ( & V_2 -> V_19 ) ;
F_23 ( & V_2 -> V_20 ) ;
V_2 -> V_68 = V_24 & ( V_32 |
V_36 |
V_43 ) ;
V_2 -> V_37 = V_37 ;
if ( ! ( V_6 -> V_37 & V_69 ) )
V_2 -> V_37 &= ~ ( V_40 | V_38 ) ;
F_15 ( V_2 , V_24 ) ;
F_24 ( & V_6 -> V_70 . V_71 ) ;
V_58 = F_25 ( & V_6 -> V_62 . V_63 , & V_2 -> V_8 , V_7 , type ,
& V_2 -> V_27 , V_55 , ! V_50 , NULL ,
V_57 , V_52 , & F_4 ) ;
F_26 ( & V_6 -> V_70 . V_71 ) ;
if ( F_22 ( V_58 != 0 ) ) {
return V_58 ;
}
* V_53 = V_2 ;
F_27 ( V_2 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , void * * V_72 )
{
bool V_73 ;
int V_58 ;
if ( V_2 -> V_74 ) {
if ( V_72 ) {
* V_72 = V_2 -> V_74 ;
}
return 0 ;
}
V_58 = F_29 ( & V_2 -> V_8 , 0 , V_2 -> V_8 . V_9 , & V_2 -> V_75 ) ;
if ( V_58 ) {
return V_58 ;
}
V_2 -> V_74 = F_30 ( & V_2 -> V_75 , & V_73 ) ;
if ( V_72 ) {
* V_72 = V_2 -> V_74 ;
}
F_31 ( V_2 , 0 , 0 ) ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_74 == NULL )
return;
V_2 -> V_74 = NULL ;
F_31 ( V_2 , 0 , 0 ) ;
F_33 ( & V_2 -> V_75 ) ;
}
struct V_1 * F_34 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return NULL ;
F_35 ( & V_2 -> V_8 ) ;
return V_2 ;
}
void F_36 ( struct V_1 * * V_2 )
{
struct V_15 * V_8 ;
struct V_5 * V_6 ;
if ( ( * V_2 ) == NULL )
return;
V_6 = ( * V_2 ) -> V_6 ;
V_8 = & ( ( * V_2 ) -> V_8 ) ;
F_37 ( & V_8 ) ;
if ( V_8 == NULL )
* V_2 = NULL ;
}
int F_38 ( struct V_1 * V_2 , T_2 V_24 , T_1 V_76 ,
T_1 * V_77 )
{
int V_58 , V_26 ;
if ( V_2 -> V_78 ) {
V_2 -> V_78 ++ ;
if ( V_77 )
* V_77 = F_39 ( V_2 ) ;
if ( V_76 != 0 ) {
T_1 V_79 ;
if ( V_24 == V_32 )
V_79 = V_2 -> V_6 -> V_80 . V_81 ;
else
V_79 = V_2 -> V_6 -> V_80 . V_82 ;
F_40 ( V_76 <
( F_39 ( V_2 ) - V_79 ) ) ;
}
return 0 ;
}
F_15 ( V_2 , V_24 ) ;
if ( V_24 == V_32 ) {
V_2 -> V_27 . V_29 = V_2 -> V_6 -> V_80 . V_83 >> V_10 ;
}
if ( V_76 ) {
T_1 V_29 = V_76 >> V_10 ;
if ( ! V_2 -> V_27 . V_29 )
V_2 -> V_27 . V_29 = V_2 -> V_6 -> V_80 . V_84 >> V_10 ;
if ( V_29 < V_2 -> V_27 . V_29 )
V_2 -> V_27 . V_29 = V_29 ;
}
for ( V_26 = 0 ; V_26 < V_2 -> V_27 . V_46 ; V_26 ++ )
V_2 -> V_30 [ V_26 ] |= V_85 ;
V_58 = F_41 ( & V_2 -> V_8 , & V_2 -> V_27 , false , false ) ;
if ( F_42 ( V_58 == 0 ) ) {
V_2 -> V_78 = 1 ;
if ( V_77 != NULL )
* V_77 = F_39 ( V_2 ) ;
if ( V_24 == V_32 )
V_2 -> V_6 -> V_86 += F_43 ( V_2 ) ;
else
V_2 -> V_6 -> V_87 += F_43 ( V_2 ) ;
} else {
F_44 ( V_2 -> V_6 -> V_88 , L_1 , V_2 ) ;
}
return V_58 ;
}
int F_45 ( struct V_1 * V_2 , T_2 V_24 , T_1 * V_77 )
{
return F_38 ( V_2 , V_24 , 0 , V_77 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
int V_58 , V_26 ;
if ( ! V_2 -> V_78 ) {
F_47 ( V_2 -> V_6 -> V_88 , L_2 , V_2 ) ;
return 0 ;
}
V_2 -> V_78 -- ;
if ( V_2 -> V_78 )
return 0 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_27 . V_46 ; V_26 ++ )
V_2 -> V_30 [ V_26 ] &= ~ V_85 ;
V_58 = F_41 ( & V_2 -> V_8 , & V_2 -> V_27 , false , false ) ;
if ( F_42 ( V_58 == 0 ) ) {
if ( V_2 -> V_8 . V_16 . V_3 == V_13 )
V_2 -> V_6 -> V_86 -= F_43 ( V_2 ) ;
else
V_2 -> V_6 -> V_87 -= F_43 ( V_2 ) ;
} else {
F_44 ( V_2 -> V_6 -> V_88 , L_3 , V_2 ) ;
}
return V_58 ;
}
int F_48 ( struct V_5 * V_6 )
{
if ( 0 && ( V_6 -> V_37 & V_89 ) ) {
if ( V_6 -> V_80 . V_90 == false )
return 0 ;
}
return F_49 ( & V_6 -> V_62 . V_63 , V_13 ) ;
}
void F_50 ( struct V_5 * V_6 )
{
struct V_1 * V_2 , * V_91 ;
if ( F_11 ( & V_6 -> V_17 . V_92 ) ) {
return;
}
F_44 ( V_6 -> V_88 , L_4 ) ;
F_51 (bo, n, &rdev->gem.objects, list) {
F_6 ( & V_6 -> V_66 -> V_93 ) ;
F_44 ( V_6 -> V_88 , L_5 ,
& V_2 -> V_21 , V_2 , ( unsigned long ) V_2 -> V_21 . V_7 ,
* ( ( unsigned long * ) & V_2 -> V_21 . V_94 ) ) ;
F_6 ( & V_2 -> V_6 -> V_17 . V_18 ) ;
F_7 ( & V_2 -> V_19 ) ;
F_8 ( & V_2 -> V_6 -> V_17 . V_18 ) ;
F_52 ( & V_2 -> V_21 ) ;
F_8 ( & V_6 -> V_66 -> V_93 ) ;
}
}
int F_53 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_95 ) {
V_6 -> V_80 . V_96 = F_54 ( V_6 -> V_80 . V_97 ,
V_6 -> V_80 . V_98 ) ;
}
F_55 ( L_6 ,
V_6 -> V_80 . V_99 >> 20 ,
( unsigned long long ) V_6 -> V_80 . V_98 >> 20 ) ;
F_55 ( L_7 ,
V_6 -> V_80 . V_100 , V_6 -> V_80 . V_101 ? 'D' : 'S' ) ;
return F_56 ( V_6 ) ;
}
void F_57 ( struct V_5 * V_6 )
{
F_58 ( V_6 ) ;
F_59 ( V_6 -> V_80 . V_96 ) ;
}
static T_1 F_60 ( struct V_5 * V_6 )
{
T_1 V_102 = V_6 -> V_80 . V_102 ;
T_1 V_14 = F_61 ( & V_6 -> V_14 ) ;
T_1 V_103 = V_102 >> 1 ;
T_1 V_104 = V_14 >= V_103 ? 0 : V_103 - V_14 ;
T_1 V_105 = V_104 >> 1 ;
return F_62 ( V_105 , 1024 * 1024ull ) ;
}
int F_63 ( struct V_5 * V_6 ,
struct V_106 * V_107 ,
struct V_108 * V_109 , int V_110 )
{
struct V_111 * V_112 ;
struct V_1 * V_2 ;
int V_58 ;
T_1 V_113 = 0 , V_114 ;
T_1 V_105 = F_60 ( V_6 ) ;
V_58 = F_64 ( V_107 , V_109 ) ;
if ( F_22 ( V_58 != 0 ) ) {
return V_58 ;
}
F_65 (lobj, head, tv.head) {
V_2 = V_112 -> V_115 ;
if ( ! V_2 -> V_78 ) {
T_2 V_24 = V_112 -> V_116 ;
T_2 V_117 =
F_66 ( V_2 -> V_8 . V_16 . V_3 ) ;
if ( ( V_112 -> V_118 & V_117 ) != 0 &&
( V_24 & V_117 ) == 0 &&
V_113 > V_105 ) {
V_24 = V_117 ;
}
V_119:
F_15 ( V_2 , V_24 ) ;
if ( V_110 == V_120 )
F_67 ( V_2 ) ;
V_114 = F_61 ( & V_6 -> V_121 ) ;
V_58 = F_41 ( & V_2 -> V_8 , & V_2 -> V_27 , true , false ) ;
V_113 += F_61 ( & V_6 -> V_121 ) -
V_114 ;
if ( F_22 ( V_58 ) ) {
if ( V_58 != - V_122 &&
V_24 != V_112 -> V_118 ) {
V_24 = V_112 -> V_118 ;
goto V_119;
}
F_68 ( V_107 , V_109 ) ;
return V_58 ;
}
}
V_112 -> V_123 = F_39 ( V_2 ) ;
V_112 -> V_124 = V_2 -> V_124 ;
}
return 0 ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
return F_70 ( V_126 , & V_2 -> V_8 ) ;
}
int F_71 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_127 * V_128 ;
struct V_1 * V_129 ;
int V_130 ;
int V_26 ;
F_72 ( & V_2 -> V_8 . V_131 -> V_132 . V_133 ) ;
if ( ! V_2 -> V_124 )
return 0 ;
if ( V_2 -> V_67 >= 0 ) {
V_128 = & V_6 -> V_134 [ V_2 -> V_67 ] ;
V_26 = V_2 -> V_67 ;
goto V_135;
}
V_130 = - 1 ;
for ( V_26 = 0 ; V_26 < V_136 ; V_26 ++ ) {
V_128 = & V_6 -> V_134 [ V_26 ] ;
if ( ! V_128 -> V_2 )
break;
V_129 = V_128 -> V_2 ;
if ( V_129 -> V_78 == 0 )
V_130 = V_26 ;
}
if ( V_26 == V_136 ) {
if ( V_130 == - 1 )
return - V_65 ;
V_128 = & V_6 -> V_134 [ V_130 ] ;
V_129 = V_128 -> V_2 ;
F_73 ( L_8 , V_130 , V_129 ) ;
F_74 ( & V_129 -> V_8 ) ;
V_129 -> V_67 = - 1 ;
V_26 = V_130 ;
}
V_2 -> V_67 = V_26 ;
V_128 -> V_2 = V_2 ;
V_135:
F_75 ( V_6 , V_26 , V_2 -> V_124 , V_2 -> V_137 ,
V_2 -> V_8 . V_16 . V_138 << V_10 ,
V_2 -> V_8 . V_9 << V_10 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_127 * V_128 ;
if ( V_2 -> V_67 == - 1 )
return;
V_128 = & V_6 -> V_134 [ V_2 -> V_67 ] ;
F_76 ( V_6 , V_2 -> V_67 ) ;
V_128 -> V_2 = NULL ;
V_2 -> V_67 = - 1 ;
}
int F_77 ( struct V_1 * V_2 ,
T_4 V_124 , T_4 V_137 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_58 ;
if ( V_6 -> V_139 >= V_140 ) {
unsigned V_141 , V_142 , V_143 , V_144 , V_145 ;
V_141 = ( V_124 >> V_146 ) & V_147 ;
V_142 = ( V_124 >> V_148 ) & V_149 ;
V_143 = ( V_124 >> V_150 ) & V_151 ;
V_144 = ( V_124 >> V_152 ) & V_153 ;
V_145 = ( V_124 >> V_154 ) & V_155 ;
switch ( V_141 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_156 ;
}
switch ( V_142 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_156 ;
}
switch ( V_143 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_156 ;
}
if ( V_144 > 6 ) {
return - V_156 ;
}
if ( V_145 > 6 ) {
return - V_156 ;
}
}
V_58 = F_78 ( V_2 , false ) ;
if ( F_22 ( V_58 != 0 ) )
return V_58 ;
V_2 -> V_124 = V_124 ;
V_2 -> V_137 = V_137 ;
F_79 ( V_2 ) ;
return 0 ;
}
void F_80 ( struct V_1 * V_2 ,
T_4 * V_124 ,
T_4 * V_137 )
{
F_72 ( & V_2 -> V_8 . V_131 -> V_132 . V_133 ) ;
if ( V_124 )
* V_124 = V_2 -> V_124 ;
if ( V_137 )
* V_137 = V_2 -> V_137 ;
}
int F_31 ( struct V_1 * V_2 , bool V_157 ,
bool V_158 )
{
if ( ! V_158 )
F_72 ( & V_2 -> V_8 . V_131 -> V_132 . V_133 ) ;
if ( ! ( V_2 -> V_124 & V_159 ) )
return 0 ;
if ( V_158 ) {
F_9 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_8 . V_16 . V_3 != V_13 ) {
if ( ! V_157 )
return 0 ;
if ( V_2 -> V_67 >= 0 )
F_9 ( V_2 ) ;
return 0 ;
}
if ( ( V_2 -> V_67 >= 0 ) && ! V_157 )
return 0 ;
return F_71 ( V_2 ) ;
}
void F_81 ( struct V_15 * V_2 ,
struct V_160 * V_161 )
{
struct V_1 * V_23 ;
if ( ! F_14 ( V_2 ) )
return;
V_23 = F_5 ( V_2 , struct V_1 , V_8 ) ;
F_31 ( V_23 , 0 , 1 ) ;
F_82 ( V_23 -> V_6 , V_23 ) ;
if ( ! V_161 )
return;
F_1 ( V_23 , V_2 -> V_16 . V_3 , - 1 ) ;
F_1 ( V_23 , V_161 -> V_3 , 1 ) ;
}
int F_83 ( struct V_15 * V_2 )
{
struct V_5 * V_6 ;
struct V_1 * V_23 ;
unsigned long V_162 , V_7 ;
int V_58 ;
if ( ! F_14 ( V_2 ) )
return 0 ;
V_23 = F_5 ( V_2 , struct V_1 , V_8 ) ;
F_31 ( V_23 , 0 , 0 ) ;
V_6 = V_23 -> V_6 ;
if ( V_2 -> V_16 . V_3 != V_13 )
return 0 ;
V_7 = V_2 -> V_16 . V_9 << V_10 ;
V_162 = V_2 -> V_16 . V_138 << V_10 ;
if ( ( V_162 + V_7 ) <= V_6 -> V_80 . V_83 )
return 0 ;
F_15 ( V_23 , V_32 ) ;
V_23 -> V_27 . V_29 = V_6 -> V_80 . V_83 >> V_10 ;
V_58 = F_41 ( V_2 , & V_23 -> V_27 , false , false ) ;
if ( F_22 ( V_58 == - V_65 ) ) {
F_15 ( V_23 , V_36 ) ;
return F_41 ( V_2 , & V_23 -> V_27 , false , false ) ;
} else if ( F_22 ( V_58 != 0 ) ) {
return V_58 ;
}
V_162 = V_2 -> V_16 . V_138 << V_10 ;
if ( ( V_162 + V_7 ) > V_6 -> V_80 . V_83 )
return - V_156 ;
return 0 ;
}
int F_84 ( struct V_1 * V_2 , T_2 * V_3 , bool V_163 )
{
int V_58 ;
V_58 = F_85 ( & V_2 -> V_8 , true , V_163 , false , NULL ) ;
if ( F_22 ( V_58 != 0 ) )
return V_58 ;
F_86 ( & V_2 -> V_8 . V_63 -> V_164 ) ;
if ( V_3 )
* V_3 = V_2 -> V_8 . V_16 . V_3 ;
if ( V_2 -> V_8 . V_165 )
V_58 = F_87 ( & V_2 -> V_8 , true , true , V_163 ) ;
F_88 ( & V_2 -> V_8 . V_63 -> V_164 ) ;
F_89 ( & V_2 -> V_8 ) ;
return V_58 ;
}
