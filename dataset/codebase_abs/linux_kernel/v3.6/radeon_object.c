void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 (bo_va, tmp, &bo->va, bo_list) {
F_3 ( V_2 -> V_6 , V_4 -> V_7 , V_2 ) ;
}
}
static void F_4 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
F_6 ( & V_2 -> V_6 -> V_10 . V_11 ) ;
F_7 ( & V_2 -> V_12 ) ;
F_8 ( & V_2 -> V_6 -> V_10 . V_11 ) ;
F_9 ( V_2 ) ;
F_1 ( V_2 ) ;
F_10 ( & V_2 -> V_13 ) ;
F_11 ( V_2 ) ;
}
bool F_12 ( struct V_8 * V_2 )
{
if ( V_2 -> V_14 == & F_4 )
return true ;
return false ;
}
void F_13 ( struct V_1 * V_15 , T_1 V_16 )
{
T_1 V_17 = 0 ;
V_15 -> V_18 . V_19 = 0 ;
V_15 -> V_18 . V_20 = 0 ;
V_15 -> V_18 . V_18 = V_15 -> V_21 ;
V_15 -> V_18 . V_22 = V_15 -> V_21 ;
if ( V_16 & V_23 )
V_15 -> V_21 [ V_17 ++ ] = V_24 | V_25 |
V_26 ;
if ( V_16 & V_27 )
V_15 -> V_21 [ V_17 ++ ] = V_28 | V_29 ;
if ( V_16 & V_30 )
V_15 -> V_21 [ V_17 ++ ] = V_28 | V_31 ;
if ( ! V_17 )
V_15 -> V_21 [ V_17 ++ ] = V_28 | V_31 ;
V_15 -> V_18 . V_32 = V_17 ;
V_15 -> V_18 . V_33 = V_17 ;
}
int F_14 ( struct V_34 * V_6 ,
unsigned long V_35 , int V_36 , bool V_37 , T_1 V_16 ,
struct V_38 * V_39 , struct V_1 * * V_40 )
{
struct V_1 * V_2 ;
enum V_41 type ;
unsigned long V_42 = F_15 ( V_36 , V_43 ) >> V_44 ;
unsigned long V_45 = 0 ;
T_2 V_46 ;
int V_47 ;
V_35 = F_16 ( V_35 , V_43 ) ;
V_6 -> V_48 . V_49 . V_50 = V_6 -> V_51 -> V_50 ;
if ( V_37 ) {
type = V_52 ;
} else if ( V_39 ) {
type = V_53 ;
} else {
type = V_54 ;
}
* V_40 = NULL ;
V_45 = F_17 ( V_6 -> V_55 . V_56 , V_6 -> V_55 . V_57 ) ;
if ( ( V_42 << V_44 ) >= V_45 ) {
F_18 ( V_58 L_1 ,
V_59 , __LINE__ , V_42 >> ( 20 - V_44 ) , V_45 >> 20 ) ;
return - V_60 ;
}
V_46 = F_19 ( & V_6 -> V_48 . V_49 , V_35 ,
sizeof( struct V_1 ) ) ;
V_61:
V_2 = F_20 ( sizeof( struct V_1 ) , V_62 ) ;
if ( V_2 == NULL )
return - V_60 ;
V_47 = F_21 ( V_6 -> V_51 , & V_2 -> V_13 , V_35 ) ;
if ( F_22 ( V_47 ) ) {
F_11 ( V_2 ) ;
return V_47 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_13 . V_63 = NULL ;
V_2 -> V_64 = - 1 ;
F_23 ( & V_2 -> V_12 ) ;
F_23 ( & V_2 -> V_65 ) ;
F_13 ( V_2 , V_16 ) ;
F_24 ( & V_6 -> V_66 . V_67 ) ;
V_47 = F_25 ( & V_6 -> V_48 . V_49 , & V_2 -> V_9 , V_35 , type ,
& V_2 -> V_18 , V_42 , 0 , ! V_37 , NULL ,
V_46 , V_39 , & F_4 ) ;
F_26 ( & V_6 -> V_66 . V_67 ) ;
if ( F_22 ( V_47 != 0 ) ) {
if ( V_47 != - V_68 ) {
if ( V_16 == V_23 ) {
V_16 |= V_27 ;
goto V_61;
}
F_27 ( V_6 -> V_69 ,
L_2 ,
V_35 , V_16 ) ;
}
return V_47 ;
}
* V_40 = V_2 ;
F_28 ( V_2 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 , void * * V_70 )
{
bool V_71 ;
int V_47 ;
if ( V_2 -> V_72 ) {
if ( V_70 ) {
* V_70 = V_2 -> V_72 ;
}
return 0 ;
}
V_47 = F_30 ( & V_2 -> V_9 , 0 , V_2 -> V_9 . V_73 , & V_2 -> V_74 ) ;
if ( V_47 ) {
return V_47 ;
}
V_2 -> V_72 = F_31 ( & V_2 -> V_74 , & V_71 ) ;
if ( V_70 ) {
* V_70 = V_2 -> V_72 ;
}
F_32 ( V_2 , 0 , 0 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_72 == NULL )
return;
V_2 -> V_72 = NULL ;
F_32 ( V_2 , 0 , 0 ) ;
F_34 ( & V_2 -> V_74 ) ;
}
void F_35 ( struct V_1 * * V_2 )
{
struct V_8 * V_9 ;
struct V_34 * V_6 ;
if ( ( * V_2 ) == NULL )
return;
V_6 = ( * V_2 ) -> V_6 ;
V_9 = & ( ( * V_2 ) -> V_9 ) ;
F_24 ( & V_6 -> V_66 . V_67 ) ;
F_36 ( & V_9 ) ;
F_26 ( & V_6 -> V_66 . V_67 ) ;
if ( V_9 == NULL )
* V_2 = NULL ;
}
int F_37 ( struct V_1 * V_2 , T_1 V_16 , T_3 V_75 ,
T_3 * V_76 )
{
int V_47 , V_77 ;
if ( V_2 -> V_78 ) {
V_2 -> V_78 ++ ;
if ( V_76 )
* V_76 = F_38 ( V_2 ) ;
if ( V_75 != 0 ) {
T_3 V_79 ;
if ( V_16 == V_23 )
V_79 = V_2 -> V_6 -> V_55 . V_80 ;
else
V_79 = V_2 -> V_6 -> V_55 . V_81 ;
F_39 ( V_75 <
( F_38 ( V_2 ) - V_79 ) ) ;
}
return 0 ;
}
F_13 ( V_2 , V_16 ) ;
if ( V_16 == V_23 ) {
V_2 -> V_18 . V_20 = V_2 -> V_6 -> V_55 . V_56 >> V_44 ;
}
if ( V_75 ) {
T_3 V_20 = V_75 >> V_44 ;
if ( ! V_2 -> V_18 . V_20 )
V_2 -> V_18 . V_20 = V_2 -> V_6 -> V_55 . V_57 >> V_44 ;
if ( V_20 < V_2 -> V_18 . V_20 )
V_2 -> V_18 . V_20 = V_20 ;
}
for ( V_77 = 0 ; V_77 < V_2 -> V_18 . V_32 ; V_77 ++ )
V_2 -> V_21 [ V_77 ] |= V_82 ;
V_47 = F_40 ( & V_2 -> V_9 , & V_2 -> V_18 , false , false , false ) ;
if ( F_41 ( V_47 == 0 ) ) {
V_2 -> V_78 = 1 ;
if ( V_76 != NULL )
* V_76 = F_38 ( V_2 ) ;
}
if ( F_22 ( V_47 != 0 ) )
F_27 ( V_2 -> V_6 -> V_69 , L_3 , V_2 ) ;
return V_47 ;
}
int F_42 ( struct V_1 * V_2 , T_1 V_16 , T_3 * V_76 )
{
return F_37 ( V_2 , V_16 , 0 , V_76 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
int V_47 , V_77 ;
if ( ! V_2 -> V_78 ) {
F_44 ( V_2 -> V_6 -> V_69 , L_4 , V_2 ) ;
return 0 ;
}
V_2 -> V_78 -- ;
if ( V_2 -> V_78 )
return 0 ;
for ( V_77 = 0 ; V_77 < V_2 -> V_18 . V_32 ; V_77 ++ )
V_2 -> V_21 [ V_77 ] &= ~ V_82 ;
V_47 = F_40 ( & V_2 -> V_9 , & V_2 -> V_18 , false , false , false ) ;
if ( F_22 ( V_47 != 0 ) )
F_27 ( V_2 -> V_6 -> V_69 , L_5 , V_2 ) ;
return V_47 ;
}
int F_45 ( struct V_34 * V_6 )
{
if ( 0 && ( V_6 -> V_83 & V_84 ) ) {
if ( V_6 -> V_55 . V_85 == false )
return 0 ;
}
return F_46 ( & V_6 -> V_48 . V_49 , V_86 ) ;
}
void F_47 ( struct V_34 * V_6 )
{
struct V_1 * V_2 , * V_87 ;
if ( F_48 ( & V_6 -> V_10 . V_88 ) ) {
return;
}
F_27 ( V_6 -> V_69 , L_6 ) ;
F_2 (bo, n, &rdev->gem.objects, list) {
F_6 ( & V_6 -> V_51 -> V_89 ) ;
F_27 ( V_6 -> V_69 , L_7 ,
& V_2 -> V_13 , V_2 , ( unsigned long ) V_2 -> V_13 . V_35 ,
* ( ( unsigned long * ) & V_2 -> V_13 . V_90 ) ) ;
F_6 ( & V_2 -> V_6 -> V_10 . V_11 ) ;
F_7 ( & V_2 -> V_12 ) ;
F_8 ( & V_2 -> V_6 -> V_10 . V_11 ) ;
F_49 ( & V_2 -> V_13 ) ;
F_8 ( & V_6 -> V_51 -> V_89 ) ;
}
}
int F_50 ( struct V_34 * V_6 )
{
V_6 -> V_55 . V_91 = F_51 ( V_6 -> V_55 . V_92 , V_6 -> V_55 . V_93 ,
V_94 , 1 ) ;
F_52 ( L_8 ,
V_6 -> V_55 . V_95 >> 20 ,
( unsigned long long ) V_6 -> V_55 . V_93 >> 20 ) ;
F_52 ( L_9 ,
V_6 -> V_55 . V_96 , V_6 -> V_55 . V_97 ? 'D' : 'S' ) ;
return F_53 ( V_6 ) ;
}
void F_54 ( struct V_34 * V_6 )
{
F_55 ( V_6 ) ;
}
void F_56 ( struct V_98 * V_99 ,
struct V_100 * V_101 )
{
if ( V_99 -> V_102 ) {
F_57 ( & V_99 -> V_103 . V_101 , V_101 ) ;
} else {
F_58 ( & V_99 -> V_103 . V_101 , V_101 ) ;
}
}
int F_59 ( struct V_100 * V_101 )
{
struct V_98 * V_99 ;
struct V_1 * V_2 ;
T_1 V_16 ;
int V_47 ;
V_47 = F_60 ( V_101 ) ;
if ( F_22 ( V_47 != 0 ) ) {
return V_47 ;
}
F_61 (lobj, head, tv.head) {
V_2 = V_99 -> V_2 ;
if ( ! V_2 -> V_78 ) {
V_16 = V_99 -> V_102 ? V_99 -> V_102 : V_99 -> V_104 ;
V_61:
F_13 ( V_2 , V_16 ) ;
V_47 = F_40 ( & V_2 -> V_9 , & V_2 -> V_18 ,
true , false , false ) ;
if ( F_22 ( V_47 ) ) {
if ( V_47 != - V_68 && V_16 == V_23 ) {
V_16 |= V_27 ;
goto V_61;
}
return V_47 ;
}
}
V_99 -> V_105 = F_38 ( V_2 ) ;
V_99 -> V_106 = V_2 -> V_106 ;
}
return 0 ;
}
int F_62 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
return F_63 ( V_108 , & V_2 -> V_9 ) ;
}
int F_64 ( struct V_1 * V_2 )
{
struct V_34 * V_6 = V_2 -> V_6 ;
struct V_109 * V_110 ;
struct V_1 * V_111 ;
int V_112 ;
int V_77 ;
F_65 ( ! F_66 ( & V_2 -> V_9 . V_113 ) ) ;
if ( ! V_2 -> V_106 )
return 0 ;
if ( V_2 -> V_64 >= 0 ) {
V_110 = & V_6 -> V_114 [ V_2 -> V_64 ] ;
V_77 = V_2 -> V_64 ;
goto V_115;
}
V_112 = - 1 ;
for ( V_77 = 0 ; V_77 < V_116 ; V_77 ++ ) {
V_110 = & V_6 -> V_114 [ V_77 ] ;
if ( ! V_110 -> V_2 )
break;
V_111 = V_110 -> V_2 ;
if ( V_111 -> V_78 == 0 )
V_112 = V_77 ;
}
if ( V_77 == V_116 ) {
if ( V_112 == - 1 )
return - V_60 ;
V_110 = & V_6 -> V_114 [ V_112 ] ;
V_111 = V_110 -> V_2 ;
F_67 ( L_10 , V_112 , V_111 ) ;
F_68 ( & V_111 -> V_9 ) ;
V_111 -> V_64 = - 1 ;
V_77 = V_112 ;
}
V_2 -> V_64 = V_77 ;
V_110 -> V_2 = V_2 ;
V_115:
F_69 ( V_6 , V_77 , V_2 -> V_106 , V_2 -> V_117 ,
V_2 -> V_9 . V_118 . V_119 << V_44 ,
V_2 -> V_9 . V_73 << V_44 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_34 * V_6 = V_2 -> V_6 ;
struct V_109 * V_110 ;
if ( V_2 -> V_64 == - 1 )
return;
V_110 = & V_6 -> V_114 [ V_2 -> V_64 ] ;
F_70 ( V_6 , V_2 -> V_64 ) ;
V_110 -> V_2 = NULL ;
V_2 -> V_64 = - 1 ;
}
int F_71 ( struct V_1 * V_2 ,
T_4 V_106 , T_4 V_117 )
{
struct V_34 * V_6 = V_2 -> V_6 ;
int V_47 ;
if ( V_6 -> V_120 >= V_121 ) {
unsigned V_122 , V_123 , V_124 , V_125 , V_126 ;
V_122 = ( V_106 >> V_127 ) & V_128 ;
V_123 = ( V_106 >> V_129 ) & V_130 ;
V_124 = ( V_106 >> V_131 ) & V_132 ;
V_125 = ( V_106 >> V_133 ) & V_134 ;
V_126 = ( V_106 >> V_135 ) & V_136 ;
switch ( V_122 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_137 ;
}
switch ( V_123 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_137 ;
}
switch ( V_124 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_137 ;
}
if ( V_125 > 6 ) {
return - V_137 ;
}
if ( V_126 > 6 ) {
return - V_137 ;
}
}
V_47 = F_72 ( V_2 , false ) ;
if ( F_22 ( V_47 != 0 ) )
return V_47 ;
V_2 -> V_106 = V_106 ;
V_2 -> V_117 = V_117 ;
F_73 ( V_2 ) ;
return 0 ;
}
void F_74 ( struct V_1 * V_2 ,
T_4 * V_106 ,
T_4 * V_117 )
{
F_65 ( ! F_66 ( & V_2 -> V_9 . V_113 ) ) ;
if ( V_106 )
* V_106 = V_2 -> V_106 ;
if ( V_117 )
* V_117 = V_2 -> V_117 ;
}
int F_32 ( struct V_1 * V_2 , bool V_138 ,
bool V_139 )
{
F_65 ( ! F_66 ( & V_2 -> V_9 . V_113 ) ) ;
if ( ! ( V_2 -> V_106 & V_140 ) )
return 0 ;
if ( V_139 ) {
F_9 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_9 . V_118 . V_141 != V_86 ) {
if ( ! V_138 )
return 0 ;
if ( V_2 -> V_64 >= 0 )
F_9 ( V_2 ) ;
return 0 ;
}
if ( ( V_2 -> V_64 >= 0 ) && ! V_138 )
return 0 ;
return F_64 ( V_2 ) ;
}
void F_75 ( struct V_8 * V_2 ,
struct V_142 * V_118 )
{
struct V_1 * V_15 ;
if ( ! F_12 ( V_2 ) )
return;
V_15 = F_5 ( V_2 , struct V_1 , V_9 ) ;
F_32 ( V_15 , 0 , 1 ) ;
F_76 ( V_15 -> V_6 , V_15 ) ;
}
int F_77 ( struct V_8 * V_2 )
{
struct V_34 * V_6 ;
struct V_1 * V_15 ;
unsigned long V_143 , V_35 ;
int V_47 ;
if ( ! F_12 ( V_2 ) )
return 0 ;
V_15 = F_5 ( V_2 , struct V_1 , V_9 ) ;
F_32 ( V_15 , 0 , 0 ) ;
V_6 = V_15 -> V_6 ;
if ( V_2 -> V_118 . V_141 == V_86 ) {
V_35 = V_2 -> V_118 . V_73 << V_44 ;
V_143 = V_2 -> V_118 . V_119 << V_44 ;
if ( ( V_143 + V_35 ) > V_6 -> V_55 . V_56 ) {
F_13 ( V_15 , V_23 ) ;
V_15 -> V_18 . V_20 = V_6 -> V_55 . V_56 >> V_44 ;
V_47 = F_40 ( V_2 , & V_15 -> V_18 , false , true , false ) ;
if ( F_22 ( V_47 != 0 ) )
return V_47 ;
V_143 = V_2 -> V_118 . V_119 << V_44 ;
if ( ( V_143 + V_35 ) > V_6 -> V_55 . V_56 )
return - V_137 ;
}
}
return 0 ;
}
int F_78 ( struct V_1 * V_2 , T_1 * V_141 , bool V_144 )
{
int V_47 ;
V_47 = F_79 ( & V_2 -> V_9 , true , V_144 , false , 0 ) ;
if ( F_22 ( V_47 != 0 ) )
return V_47 ;
F_80 ( & V_2 -> V_9 . V_49 -> V_145 ) ;
if ( V_141 )
* V_141 = V_2 -> V_9 . V_118 . V_141 ;
if ( V_2 -> V_9 . V_146 )
V_47 = F_81 ( & V_2 -> V_9 , true , true , V_144 ) ;
F_82 ( & V_2 -> V_9 . V_49 -> V_145 ) ;
F_83 ( & V_2 -> V_9 ) ;
return V_47 ;
}
int F_72 ( struct V_1 * V_2 , bool V_144 )
{
int V_47 ;
V_47 = F_79 ( & V_2 -> V_9 , true , V_144 , false , 0 ) ;
if ( F_22 ( V_47 != 0 ) ) {
if ( V_47 != - V_68 )
F_27 ( V_2 -> V_6 -> V_69 , L_11 , V_2 ) ;
return V_47 ;
}
return 0 ;
}
struct V_3 * V_3 ( struct V_1 * V_15 , struct V_147 * V_7 )
{
struct V_3 * V_4 ;
F_61 (bo_va, &rbo->va, bo_list) {
if ( V_4 -> V_7 == V_7 ) {
return V_4 ;
}
}
return NULL ;
}
