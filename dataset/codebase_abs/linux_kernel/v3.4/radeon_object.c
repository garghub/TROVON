void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 (bo_va, tmp, &bo->va, bo_list) {
F_3 ( & V_4 -> V_6 -> V_7 ) ;
F_4 ( & V_4 -> V_8 ) ;
F_5 ( & V_4 -> V_6 -> V_7 ) ;
F_4 ( & V_4 -> V_9 ) ;
F_6 ( V_4 ) ;
}
}
static void F_7 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_11 , struct V_1 , V_11 ) ;
F_3 ( & V_2 -> V_12 -> V_13 . V_7 ) ;
F_9 ( & V_2 -> V_14 ) ;
F_5 ( & V_2 -> V_12 -> V_13 . V_7 ) ;
F_10 ( V_2 ) ;
F_1 ( V_2 ) ;
F_11 ( & V_2 -> V_15 ) ;
F_6 ( V_2 ) ;
}
bool F_12 ( struct V_10 * V_2 )
{
if ( V_2 -> V_16 == & F_7 )
return true ;
return false ;
}
void F_13 ( struct V_1 * V_17 , T_1 V_18 )
{
T_1 V_19 = 0 ;
V_17 -> V_20 . V_21 = 0 ;
V_17 -> V_20 . V_22 = 0 ;
V_17 -> V_20 . V_20 = V_17 -> V_23 ;
V_17 -> V_20 . V_24 = V_17 -> V_23 ;
if ( V_18 & V_25 )
V_17 -> V_23 [ V_19 ++ ] = V_26 | V_27 |
V_28 ;
if ( V_18 & V_29 )
V_17 -> V_23 [ V_19 ++ ] = V_30 | V_31 ;
if ( V_18 & V_32 )
V_17 -> V_23 [ V_19 ++ ] = V_30 | V_33 ;
if ( ! V_19 )
V_17 -> V_23 [ V_19 ++ ] = V_30 | V_33 ;
V_17 -> V_20 . V_34 = V_19 ;
V_17 -> V_20 . V_35 = V_19 ;
}
int F_14 ( struct V_36 * V_12 ,
unsigned long V_37 , int V_38 , bool V_39 , T_1 V_18 ,
struct V_1 * * V_40 )
{
struct V_1 * V_2 ;
enum V_41 type ;
unsigned long V_42 = F_15 ( V_38 , V_43 ) >> V_44 ;
unsigned long V_45 = 0 ;
T_2 V_46 ;
int V_47 ;
V_37 = F_16 ( V_37 , V_43 ) ;
if ( F_17 ( V_12 -> V_48 . V_49 . V_50 == NULL ) ) {
V_12 -> V_48 . V_49 . V_50 = V_12 -> V_51 -> V_50 ;
}
if ( V_39 ) {
type = V_52 ;
} else {
type = V_53 ;
}
* V_40 = NULL ;
V_45 = F_18 ( V_12 -> V_54 . V_55 , V_12 -> V_54 . V_56 ) ;
if ( ( V_42 << V_44 ) >= V_45 ) {
F_19 ( V_57 L_1 ,
V_58 , __LINE__ , V_42 >> ( 20 - V_44 ) , V_45 >> 20 ) ;
return - V_59 ;
}
V_46 = F_20 ( & V_12 -> V_48 . V_49 , V_37 ,
sizeof( struct V_1 ) ) ;
V_60:
V_2 = F_21 ( sizeof( struct V_1 ) , V_61 ) ;
if ( V_2 == NULL )
return - V_59 ;
V_47 = F_22 ( V_12 -> V_51 , & V_2 -> V_15 , V_37 ) ;
if ( F_17 ( V_47 ) ) {
F_6 ( V_2 ) ;
return V_47 ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_15 . V_62 = NULL ;
V_2 -> V_63 = - 1 ;
F_23 ( & V_2 -> V_14 ) ;
F_23 ( & V_2 -> V_64 ) ;
F_13 ( V_2 , V_18 ) ;
F_3 ( & V_12 -> V_65 ) ;
V_47 = F_24 ( & V_12 -> V_48 . V_49 , & V_2 -> V_11 , V_37 , type ,
& V_2 -> V_20 , V_42 , 0 , ! V_39 , NULL ,
V_46 , & F_7 ) ;
F_5 ( & V_12 -> V_65 ) ;
if ( F_17 ( V_47 != 0 ) ) {
if ( V_47 != - V_66 ) {
if ( V_18 == V_25 ) {
V_18 |= V_29 ;
goto V_60;
}
F_25 ( V_12 -> V_67 ,
L_2 ,
V_37 , V_18 ) ;
}
return V_47 ;
}
* V_40 = V_2 ;
F_26 ( V_2 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , void * * V_68 )
{
bool V_69 ;
int V_47 ;
if ( V_2 -> V_70 ) {
if ( V_68 ) {
* V_68 = V_2 -> V_70 ;
}
return 0 ;
}
V_47 = F_28 ( & V_2 -> V_11 , 0 , V_2 -> V_11 . V_71 , & V_2 -> V_72 ) ;
if ( V_47 ) {
return V_47 ;
}
V_2 -> V_70 = F_29 ( & V_2 -> V_72 , & V_69 ) ;
if ( V_68 ) {
* V_68 = V_2 -> V_70 ;
}
F_30 ( V_2 , 0 , 0 ) ;
return 0 ;
}
void F_31 ( struct V_1 * V_2 )
{
if ( V_2 -> V_70 == NULL )
return;
V_2 -> V_70 = NULL ;
F_30 ( V_2 , 0 , 0 ) ;
F_32 ( & V_2 -> V_72 ) ;
}
void F_33 ( struct V_1 * * V_2 )
{
struct V_10 * V_11 ;
struct V_36 * V_12 ;
if ( ( * V_2 ) == NULL )
return;
V_12 = ( * V_2 ) -> V_12 ;
V_11 = & ( ( * V_2 ) -> V_11 ) ;
F_3 ( & V_12 -> V_65 ) ;
F_34 ( & V_11 ) ;
F_5 ( & V_12 -> V_65 ) ;
if ( V_11 == NULL )
* V_2 = NULL ;
}
int F_35 ( struct V_1 * V_2 , T_1 V_18 , T_3 V_73 ,
T_3 * V_74 )
{
int V_47 , V_75 ;
if ( V_2 -> V_76 ) {
V_2 -> V_76 ++ ;
if ( V_74 )
* V_74 = F_36 ( V_2 ) ;
if ( V_73 != 0 ) {
T_3 V_77 ;
if ( V_18 == V_25 )
V_77 = V_2 -> V_12 -> V_54 . V_78 ;
else
V_77 = V_2 -> V_12 -> V_54 . V_79 ;
F_37 ( V_73 <
( F_36 ( V_2 ) - V_77 ) ) ;
}
return 0 ;
}
F_13 ( V_2 , V_18 ) ;
if ( V_18 == V_25 ) {
V_2 -> V_20 . V_22 = V_2 -> V_12 -> V_54 . V_55 >> V_44 ;
}
if ( V_73 ) {
T_3 V_22 = V_73 >> V_44 ;
if ( ! V_2 -> V_20 . V_22 )
V_2 -> V_20 . V_22 = V_2 -> V_12 -> V_54 . V_56 >> V_44 ;
if ( V_22 < V_2 -> V_20 . V_22 )
V_2 -> V_20 . V_22 = V_22 ;
}
for ( V_75 = 0 ; V_75 < V_2 -> V_20 . V_34 ; V_75 ++ )
V_2 -> V_23 [ V_75 ] |= V_80 ;
V_47 = F_38 ( & V_2 -> V_11 , & V_2 -> V_20 , false , false , false ) ;
if ( F_39 ( V_47 == 0 ) ) {
V_2 -> V_76 = 1 ;
if ( V_74 != NULL )
* V_74 = F_36 ( V_2 ) ;
}
if ( F_17 ( V_47 != 0 ) )
F_25 ( V_2 -> V_12 -> V_67 , L_3 , V_2 ) ;
return V_47 ;
}
int F_40 ( struct V_1 * V_2 , T_1 V_18 , T_3 * V_74 )
{
return F_35 ( V_2 , V_18 , 0 , V_74 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
int V_47 , V_75 ;
if ( ! V_2 -> V_76 ) {
F_42 ( V_2 -> V_12 -> V_67 , L_4 , V_2 ) ;
return 0 ;
}
V_2 -> V_76 -- ;
if ( V_2 -> V_76 )
return 0 ;
for ( V_75 = 0 ; V_75 < V_2 -> V_20 . V_34 ; V_75 ++ )
V_2 -> V_23 [ V_75 ] &= ~ V_80 ;
V_47 = F_38 ( & V_2 -> V_11 , & V_2 -> V_20 , false , false , false ) ;
if ( F_17 ( V_47 != 0 ) )
F_25 ( V_2 -> V_12 -> V_67 , L_5 , V_2 ) ;
return V_47 ;
}
int F_43 ( struct V_36 * V_12 )
{
if ( 0 && ( V_12 -> V_81 & V_82 ) ) {
if ( V_12 -> V_54 . V_83 == false )
return 0 ;
}
return F_44 ( & V_12 -> V_48 . V_49 , V_84 ) ;
}
void F_45 ( struct V_36 * V_12 )
{
struct V_1 * V_2 , * V_85 ;
if ( F_46 ( & V_12 -> V_13 . V_86 ) ) {
return;
}
F_25 ( V_12 -> V_67 , L_6 ) ;
F_2 (bo, n, &rdev->gem.objects, list) {
F_3 ( & V_12 -> V_51 -> V_87 ) ;
F_25 ( V_12 -> V_67 , L_7 ,
& V_2 -> V_15 , V_2 , ( unsigned long ) V_2 -> V_15 . V_37 ,
* ( ( unsigned long * ) & V_2 -> V_15 . V_88 ) ) ;
F_3 ( & V_2 -> V_12 -> V_13 . V_7 ) ;
F_9 ( & V_2 -> V_14 ) ;
F_5 ( & V_2 -> V_12 -> V_13 . V_7 ) ;
F_47 ( & V_2 -> V_15 ) ;
F_5 ( & V_12 -> V_51 -> V_87 ) ;
}
}
int F_48 ( struct V_36 * V_12 )
{
V_12 -> V_54 . V_89 = F_49 ( V_12 -> V_54 . V_90 , V_12 -> V_54 . V_91 ,
V_92 , 1 ) ;
F_50 ( L_8 ,
V_12 -> V_54 . V_93 >> 20 ,
( unsigned long long ) V_12 -> V_54 . V_91 >> 20 ) ;
F_50 ( L_9 ,
V_12 -> V_54 . V_94 , V_12 -> V_54 . V_95 ? 'D' : 'S' ) ;
return F_51 ( V_12 ) ;
}
void F_52 ( struct V_36 * V_12 )
{
F_53 ( V_12 ) ;
}
void F_54 ( struct V_96 * V_97 ,
struct V_98 * V_99 )
{
if ( V_97 -> V_100 ) {
F_55 ( & V_97 -> V_101 . V_99 , V_99 ) ;
} else {
F_56 ( & V_97 -> V_101 . V_99 , V_99 ) ;
}
}
int F_57 ( struct V_98 * V_99 )
{
struct V_96 * V_97 ;
struct V_1 * V_2 ;
T_1 V_18 ;
int V_47 ;
V_47 = F_58 ( V_99 ) ;
if ( F_17 ( V_47 != 0 ) ) {
return V_47 ;
}
F_59 (lobj, head, tv.head) {
V_2 = V_97 -> V_2 ;
if ( ! V_2 -> V_76 ) {
V_18 = V_97 -> V_100 ? V_97 -> V_100 : V_97 -> V_102 ;
V_60:
F_13 ( V_2 , V_18 ) ;
V_47 = F_38 ( & V_2 -> V_11 , & V_2 -> V_20 ,
true , false , false ) ;
if ( F_17 ( V_47 ) ) {
if ( V_47 != - V_66 && V_18 == V_25 ) {
V_18 |= V_29 ;
goto V_60;
}
return V_47 ;
}
}
V_97 -> V_103 = F_36 ( V_2 ) ;
V_97 -> V_104 = V_2 -> V_104 ;
}
return 0 ;
}
int F_60 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
return F_61 ( V_106 , & V_2 -> V_11 ) ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_36 * V_12 = V_2 -> V_12 ;
struct V_107 * V_108 ;
struct V_1 * V_109 ;
int V_110 ;
int V_75 ;
F_63 ( ! F_64 ( & V_2 -> V_11 . V_111 ) ) ;
if ( ! V_2 -> V_104 )
return 0 ;
if ( V_2 -> V_63 >= 0 ) {
V_108 = & V_12 -> V_112 [ V_2 -> V_63 ] ;
V_75 = V_2 -> V_63 ;
goto V_113;
}
V_110 = - 1 ;
for ( V_75 = 0 ; V_75 < V_114 ; V_75 ++ ) {
V_108 = & V_12 -> V_112 [ V_75 ] ;
if ( ! V_108 -> V_2 )
break;
V_109 = V_108 -> V_2 ;
if ( V_109 -> V_76 == 0 )
V_110 = V_75 ;
}
if ( V_75 == V_114 ) {
if ( V_110 == - 1 )
return - V_59 ;
V_108 = & V_12 -> V_112 [ V_110 ] ;
V_109 = V_108 -> V_2 ;
F_65 ( L_10 , V_110 , V_109 ) ;
F_66 ( & V_109 -> V_11 ) ;
V_109 -> V_63 = - 1 ;
V_75 = V_110 ;
}
V_2 -> V_63 = V_75 ;
V_108 -> V_2 = V_2 ;
V_113:
F_67 ( V_12 , V_75 , V_2 -> V_104 , V_2 -> V_115 ,
V_2 -> V_11 . V_116 . V_117 << V_44 ,
V_2 -> V_11 . V_71 << V_44 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_36 * V_12 = V_2 -> V_12 ;
struct V_107 * V_108 ;
if ( V_2 -> V_63 == - 1 )
return;
V_108 = & V_12 -> V_112 [ V_2 -> V_63 ] ;
F_68 ( V_12 , V_2 -> V_63 ) ;
V_108 -> V_2 = NULL ;
V_2 -> V_63 = - 1 ;
}
int F_69 ( struct V_1 * V_2 ,
T_4 V_104 , T_4 V_115 )
{
struct V_36 * V_12 = V_2 -> V_12 ;
int V_47 ;
if ( V_12 -> V_118 >= V_119 ) {
unsigned V_120 , V_121 , V_122 , V_123 , V_124 ;
V_120 = ( V_104 >> V_125 ) & V_126 ;
V_121 = ( V_104 >> V_127 ) & V_128 ;
V_122 = ( V_104 >> V_129 ) & V_130 ;
V_123 = ( V_104 >> V_131 ) & V_132 ;
V_124 = ( V_104 >> V_133 ) & V_134 ;
switch ( V_120 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_135 ;
}
switch ( V_121 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_135 ;
}
switch ( V_122 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_135 ;
}
if ( V_123 > 6 ) {
return - V_135 ;
}
if ( V_124 > 6 ) {
return - V_135 ;
}
}
V_47 = F_70 ( V_2 , false ) ;
if ( F_17 ( V_47 != 0 ) )
return V_47 ;
V_2 -> V_104 = V_104 ;
V_2 -> V_115 = V_115 ;
F_71 ( V_2 ) ;
return 0 ;
}
void F_72 ( struct V_1 * V_2 ,
T_4 * V_104 ,
T_4 * V_115 )
{
F_63 ( ! F_64 ( & V_2 -> V_11 . V_111 ) ) ;
if ( V_104 )
* V_104 = V_2 -> V_104 ;
if ( V_115 )
* V_115 = V_2 -> V_115 ;
}
int F_30 ( struct V_1 * V_2 , bool V_136 ,
bool V_137 )
{
F_63 ( ! F_64 ( & V_2 -> V_11 . V_111 ) ) ;
if ( ! ( V_2 -> V_104 & V_138 ) )
return 0 ;
if ( V_137 ) {
F_10 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_11 . V_116 . V_139 != V_84 ) {
if ( ! V_136 )
return 0 ;
if ( V_2 -> V_63 >= 0 )
F_10 ( V_2 ) ;
return 0 ;
}
if ( ( V_2 -> V_63 >= 0 ) && ! V_136 )
return 0 ;
return F_62 ( V_2 ) ;
}
void F_73 ( struct V_10 * V_2 ,
struct V_140 * V_116 )
{
struct V_1 * V_17 ;
if ( ! F_12 ( V_2 ) )
return;
V_17 = F_8 ( V_2 , struct V_1 , V_11 ) ;
F_30 ( V_17 , 0 , 1 ) ;
F_74 ( V_17 -> V_12 , V_17 ) ;
}
int F_75 ( struct V_10 * V_2 )
{
struct V_36 * V_12 ;
struct V_1 * V_17 ;
unsigned long V_141 , V_37 ;
int V_47 ;
if ( ! F_12 ( V_2 ) )
return 0 ;
V_17 = F_8 ( V_2 , struct V_1 , V_11 ) ;
F_30 ( V_17 , 0 , 0 ) ;
V_12 = V_17 -> V_12 ;
if ( V_2 -> V_116 . V_139 == V_84 ) {
V_37 = V_2 -> V_116 . V_71 << V_44 ;
V_141 = V_2 -> V_116 . V_117 << V_44 ;
if ( ( V_141 + V_37 ) > V_12 -> V_54 . V_55 ) {
F_13 ( V_17 , V_25 ) ;
V_17 -> V_20 . V_22 = V_12 -> V_54 . V_55 >> V_44 ;
V_47 = F_38 ( V_2 , & V_17 -> V_20 , false , true , false ) ;
if ( F_17 ( V_47 != 0 ) )
return V_47 ;
V_141 = V_2 -> V_116 . V_117 << V_44 ;
if ( ( V_141 + V_37 ) > V_12 -> V_54 . V_55 )
return - V_135 ;
}
}
return 0 ;
}
int F_76 ( struct V_1 * V_2 , T_1 * V_139 , bool V_142 )
{
int V_47 ;
V_47 = F_77 ( & V_2 -> V_11 , true , V_142 , false , 0 ) ;
if ( F_17 ( V_47 != 0 ) )
return V_47 ;
F_78 ( & V_2 -> V_11 . V_49 -> V_143 ) ;
if ( V_139 )
* V_139 = V_2 -> V_11 . V_116 . V_139 ;
if ( V_2 -> V_11 . V_144 )
V_47 = F_79 ( & V_2 -> V_11 , true , true , V_142 ) ;
F_80 ( & V_2 -> V_11 . V_49 -> V_143 ) ;
F_81 ( & V_2 -> V_11 ) ;
return V_47 ;
}
int F_70 ( struct V_1 * V_2 , bool V_142 )
{
int V_47 ;
V_47 = F_77 ( & V_2 -> V_11 , true , V_142 , false , 0 ) ;
if ( F_17 ( V_47 != 0 ) ) {
if ( V_47 != - V_66 )
F_25 ( V_2 -> V_12 -> V_67 , L_11 , V_2 ) ;
return V_47 ;
}
return 0 ;
}
struct V_3 * V_3 ( struct V_1 * V_17 , struct V_145 * V_6 )
{
struct V_3 * V_4 ;
F_59 (bo_va, &rbo->va, bo_list) {
if ( V_4 -> V_6 == V_6 ) {
return V_4 ;
}
}
return NULL ;
}
