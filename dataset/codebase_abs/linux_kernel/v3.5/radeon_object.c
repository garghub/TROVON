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
struct V_40 * V_41 , struct V_1 * * V_42 )
{
struct V_1 * V_2 ;
enum V_43 type ;
unsigned long V_44 = F_15 ( V_38 , V_45 ) >> V_46 ;
unsigned long V_47 = 0 ;
T_2 V_48 ;
int V_49 ;
V_37 = F_16 ( V_37 , V_45 ) ;
if ( F_17 ( V_12 -> V_50 . V_51 . V_52 == NULL ) ) {
V_12 -> V_50 . V_51 . V_52 = V_12 -> V_53 -> V_52 ;
}
if ( V_39 ) {
type = V_54 ;
} else if ( V_41 ) {
type = V_55 ;
} else {
type = V_56 ;
}
* V_42 = NULL ;
V_47 = F_18 ( V_12 -> V_57 . V_58 , V_12 -> V_57 . V_59 ) ;
if ( ( V_44 << V_46 ) >= V_47 ) {
F_19 ( V_60 L_1 ,
V_61 , __LINE__ , V_44 >> ( 20 - V_46 ) , V_47 >> 20 ) ;
return - V_62 ;
}
V_48 = F_20 ( & V_12 -> V_50 . V_51 , V_37 ,
sizeof( struct V_1 ) ) ;
V_63:
V_2 = F_21 ( sizeof( struct V_1 ) , V_64 ) ;
if ( V_2 == NULL )
return - V_62 ;
V_49 = F_22 ( V_12 -> V_53 , & V_2 -> V_15 , V_37 ) ;
if ( F_17 ( V_49 ) ) {
F_6 ( V_2 ) ;
return V_49 ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_15 . V_65 = NULL ;
V_2 -> V_66 = - 1 ;
F_23 ( & V_2 -> V_14 ) ;
F_23 ( & V_2 -> V_67 ) ;
F_13 ( V_2 , V_18 ) ;
F_3 ( & V_12 -> V_68 ) ;
V_49 = F_24 ( & V_12 -> V_50 . V_51 , & V_2 -> V_11 , V_37 , type ,
& V_2 -> V_20 , V_44 , 0 , ! V_39 , NULL ,
V_48 , V_41 , & F_7 ) ;
F_5 ( & V_12 -> V_68 ) ;
if ( F_17 ( V_49 != 0 ) ) {
if ( V_49 != - V_69 ) {
if ( V_18 == V_25 ) {
V_18 |= V_29 ;
goto V_63;
}
F_25 ( V_12 -> V_70 ,
L_2 ,
V_37 , V_18 ) ;
}
return V_49 ;
}
* V_42 = V_2 ;
F_26 ( V_2 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , void * * V_71 )
{
bool V_72 ;
int V_49 ;
if ( V_2 -> V_73 ) {
if ( V_71 ) {
* V_71 = V_2 -> V_73 ;
}
return 0 ;
}
V_49 = F_28 ( & V_2 -> V_11 , 0 , V_2 -> V_11 . V_74 , & V_2 -> V_75 ) ;
if ( V_49 ) {
return V_49 ;
}
V_2 -> V_73 = F_29 ( & V_2 -> V_75 , & V_72 ) ;
if ( V_71 ) {
* V_71 = V_2 -> V_73 ;
}
F_30 ( V_2 , 0 , 0 ) ;
return 0 ;
}
void F_31 ( struct V_1 * V_2 )
{
if ( V_2 -> V_73 == NULL )
return;
V_2 -> V_73 = NULL ;
F_30 ( V_2 , 0 , 0 ) ;
F_32 ( & V_2 -> V_75 ) ;
}
void F_33 ( struct V_1 * * V_2 )
{
struct V_10 * V_11 ;
struct V_36 * V_12 ;
if ( ( * V_2 ) == NULL )
return;
V_12 = ( * V_2 ) -> V_12 ;
V_11 = & ( ( * V_2 ) -> V_11 ) ;
F_3 ( & V_12 -> V_68 ) ;
F_34 ( & V_11 ) ;
F_5 ( & V_12 -> V_68 ) ;
if ( V_11 == NULL )
* V_2 = NULL ;
}
int F_35 ( struct V_1 * V_2 , T_1 V_18 , T_3 V_76 ,
T_3 * V_77 )
{
int V_49 , V_78 ;
if ( V_2 -> V_79 ) {
V_2 -> V_79 ++ ;
if ( V_77 )
* V_77 = F_36 ( V_2 ) ;
if ( V_76 != 0 ) {
T_3 V_80 ;
if ( V_18 == V_25 )
V_80 = V_2 -> V_12 -> V_57 . V_81 ;
else
V_80 = V_2 -> V_12 -> V_57 . V_82 ;
F_37 ( V_76 <
( F_36 ( V_2 ) - V_80 ) ) ;
}
return 0 ;
}
F_13 ( V_2 , V_18 ) ;
if ( V_18 == V_25 ) {
V_2 -> V_20 . V_22 = V_2 -> V_12 -> V_57 . V_58 >> V_46 ;
}
if ( V_76 ) {
T_3 V_22 = V_76 >> V_46 ;
if ( ! V_2 -> V_20 . V_22 )
V_2 -> V_20 . V_22 = V_2 -> V_12 -> V_57 . V_59 >> V_46 ;
if ( V_22 < V_2 -> V_20 . V_22 )
V_2 -> V_20 . V_22 = V_22 ;
}
for ( V_78 = 0 ; V_78 < V_2 -> V_20 . V_34 ; V_78 ++ )
V_2 -> V_23 [ V_78 ] |= V_83 ;
V_49 = F_38 ( & V_2 -> V_11 , & V_2 -> V_20 , false , false , false ) ;
if ( F_39 ( V_49 == 0 ) ) {
V_2 -> V_79 = 1 ;
if ( V_77 != NULL )
* V_77 = F_36 ( V_2 ) ;
}
if ( F_17 ( V_49 != 0 ) )
F_25 ( V_2 -> V_12 -> V_70 , L_3 , V_2 ) ;
return V_49 ;
}
int F_40 ( struct V_1 * V_2 , T_1 V_18 , T_3 * V_77 )
{
return F_35 ( V_2 , V_18 , 0 , V_77 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
int V_49 , V_78 ;
if ( ! V_2 -> V_79 ) {
F_42 ( V_2 -> V_12 -> V_70 , L_4 , V_2 ) ;
return 0 ;
}
V_2 -> V_79 -- ;
if ( V_2 -> V_79 )
return 0 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_20 . V_34 ; V_78 ++ )
V_2 -> V_23 [ V_78 ] &= ~ V_83 ;
V_49 = F_38 ( & V_2 -> V_11 , & V_2 -> V_20 , false , false , false ) ;
if ( F_17 ( V_49 != 0 ) )
F_25 ( V_2 -> V_12 -> V_70 , L_5 , V_2 ) ;
return V_49 ;
}
int F_43 ( struct V_36 * V_12 )
{
if ( 0 && ( V_12 -> V_84 & V_85 ) ) {
if ( V_12 -> V_57 . V_86 == false )
return 0 ;
}
return F_44 ( & V_12 -> V_50 . V_51 , V_87 ) ;
}
void F_45 ( struct V_36 * V_12 )
{
struct V_1 * V_2 , * V_88 ;
if ( F_46 ( & V_12 -> V_13 . V_89 ) ) {
return;
}
F_25 ( V_12 -> V_70 , L_6 ) ;
F_2 (bo, n, &rdev->gem.objects, list) {
F_3 ( & V_12 -> V_53 -> V_90 ) ;
F_25 ( V_12 -> V_70 , L_7 ,
& V_2 -> V_15 , V_2 , ( unsigned long ) V_2 -> V_15 . V_37 ,
* ( ( unsigned long * ) & V_2 -> V_15 . V_91 ) ) ;
F_3 ( & V_2 -> V_12 -> V_13 . V_7 ) ;
F_9 ( & V_2 -> V_14 ) ;
F_5 ( & V_2 -> V_12 -> V_13 . V_7 ) ;
F_47 ( & V_2 -> V_15 ) ;
F_5 ( & V_12 -> V_53 -> V_90 ) ;
}
}
int F_48 ( struct V_36 * V_12 )
{
V_12 -> V_57 . V_92 = F_49 ( V_12 -> V_57 . V_93 , V_12 -> V_57 . V_94 ,
V_95 , 1 ) ;
F_50 ( L_8 ,
V_12 -> V_57 . V_96 >> 20 ,
( unsigned long long ) V_12 -> V_57 . V_94 >> 20 ) ;
F_50 ( L_9 ,
V_12 -> V_57 . V_97 , V_12 -> V_57 . V_98 ? 'D' : 'S' ) ;
return F_51 ( V_12 ) ;
}
void F_52 ( struct V_36 * V_12 )
{
F_53 ( V_12 ) ;
}
void F_54 ( struct V_99 * V_100 ,
struct V_101 * V_102 )
{
if ( V_100 -> V_103 ) {
F_55 ( & V_100 -> V_104 . V_102 , V_102 ) ;
} else {
F_56 ( & V_100 -> V_104 . V_102 , V_102 ) ;
}
}
int F_57 ( struct V_101 * V_102 )
{
struct V_99 * V_100 ;
struct V_1 * V_2 ;
T_1 V_18 ;
int V_49 ;
V_49 = F_58 ( V_102 ) ;
if ( F_17 ( V_49 != 0 ) ) {
return V_49 ;
}
F_59 (lobj, head, tv.head) {
V_2 = V_100 -> V_2 ;
if ( ! V_2 -> V_79 ) {
V_18 = V_100 -> V_103 ? V_100 -> V_103 : V_100 -> V_105 ;
V_63:
F_13 ( V_2 , V_18 ) ;
V_49 = F_38 ( & V_2 -> V_11 , & V_2 -> V_20 ,
true , false , false ) ;
if ( F_17 ( V_49 ) ) {
if ( V_49 != - V_69 && V_18 == V_25 ) {
V_18 |= V_29 ;
goto V_63;
}
return V_49 ;
}
}
V_100 -> V_106 = F_36 ( V_2 ) ;
V_100 -> V_107 = V_2 -> V_107 ;
}
return 0 ;
}
int F_60 ( struct V_1 * V_2 ,
struct V_108 * V_109 )
{
return F_61 ( V_109 , & V_2 -> V_11 ) ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_36 * V_12 = V_2 -> V_12 ;
struct V_110 * V_111 ;
struct V_1 * V_112 ;
int V_113 ;
int V_78 ;
F_63 ( ! F_64 ( & V_2 -> V_11 . V_114 ) ) ;
if ( ! V_2 -> V_107 )
return 0 ;
if ( V_2 -> V_66 >= 0 ) {
V_111 = & V_12 -> V_115 [ V_2 -> V_66 ] ;
V_78 = V_2 -> V_66 ;
goto V_116;
}
V_113 = - 1 ;
for ( V_78 = 0 ; V_78 < V_117 ; V_78 ++ ) {
V_111 = & V_12 -> V_115 [ V_78 ] ;
if ( ! V_111 -> V_2 )
break;
V_112 = V_111 -> V_2 ;
if ( V_112 -> V_79 == 0 )
V_113 = V_78 ;
}
if ( V_78 == V_117 ) {
if ( V_113 == - 1 )
return - V_62 ;
V_111 = & V_12 -> V_115 [ V_113 ] ;
V_112 = V_111 -> V_2 ;
F_65 ( L_10 , V_113 , V_112 ) ;
F_66 ( & V_112 -> V_11 ) ;
V_112 -> V_66 = - 1 ;
V_78 = V_113 ;
}
V_2 -> V_66 = V_78 ;
V_111 -> V_2 = V_2 ;
V_116:
F_67 ( V_12 , V_78 , V_2 -> V_107 , V_2 -> V_118 ,
V_2 -> V_11 . V_119 . V_120 << V_46 ,
V_2 -> V_11 . V_74 << V_46 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_36 * V_12 = V_2 -> V_12 ;
struct V_110 * V_111 ;
if ( V_2 -> V_66 == - 1 )
return;
V_111 = & V_12 -> V_115 [ V_2 -> V_66 ] ;
F_68 ( V_12 , V_2 -> V_66 ) ;
V_111 -> V_2 = NULL ;
V_2 -> V_66 = - 1 ;
}
int F_69 ( struct V_1 * V_2 ,
T_4 V_107 , T_4 V_118 )
{
struct V_36 * V_12 = V_2 -> V_12 ;
int V_49 ;
if ( V_12 -> V_121 >= V_122 ) {
unsigned V_123 , V_124 , V_125 , V_126 , V_127 ;
V_123 = ( V_107 >> V_128 ) & V_129 ;
V_124 = ( V_107 >> V_130 ) & V_131 ;
V_125 = ( V_107 >> V_132 ) & V_133 ;
V_126 = ( V_107 >> V_134 ) & V_135 ;
V_127 = ( V_107 >> V_136 ) & V_137 ;
switch ( V_123 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_138 ;
}
switch ( V_124 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_138 ;
}
switch ( V_125 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_138 ;
}
if ( V_126 > 6 ) {
return - V_138 ;
}
if ( V_127 > 6 ) {
return - V_138 ;
}
}
V_49 = F_70 ( V_2 , false ) ;
if ( F_17 ( V_49 != 0 ) )
return V_49 ;
V_2 -> V_107 = V_107 ;
V_2 -> V_118 = V_118 ;
F_71 ( V_2 ) ;
return 0 ;
}
void F_72 ( struct V_1 * V_2 ,
T_4 * V_107 ,
T_4 * V_118 )
{
F_63 ( ! F_64 ( & V_2 -> V_11 . V_114 ) ) ;
if ( V_107 )
* V_107 = V_2 -> V_107 ;
if ( V_118 )
* V_118 = V_2 -> V_118 ;
}
int F_30 ( struct V_1 * V_2 , bool V_139 ,
bool V_140 )
{
F_63 ( ! F_64 ( & V_2 -> V_11 . V_114 ) ) ;
if ( ! ( V_2 -> V_107 & V_141 ) )
return 0 ;
if ( V_140 ) {
F_10 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_11 . V_119 . V_142 != V_87 ) {
if ( ! V_139 )
return 0 ;
if ( V_2 -> V_66 >= 0 )
F_10 ( V_2 ) ;
return 0 ;
}
if ( ( V_2 -> V_66 >= 0 ) && ! V_139 )
return 0 ;
return F_62 ( V_2 ) ;
}
void F_73 ( struct V_10 * V_2 ,
struct V_143 * V_119 )
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
unsigned long V_144 , V_37 ;
int V_49 ;
if ( ! F_12 ( V_2 ) )
return 0 ;
V_17 = F_8 ( V_2 , struct V_1 , V_11 ) ;
F_30 ( V_17 , 0 , 0 ) ;
V_12 = V_17 -> V_12 ;
if ( V_2 -> V_119 . V_142 == V_87 ) {
V_37 = V_2 -> V_119 . V_74 << V_46 ;
V_144 = V_2 -> V_119 . V_120 << V_46 ;
if ( ( V_144 + V_37 ) > V_12 -> V_57 . V_58 ) {
F_13 ( V_17 , V_25 ) ;
V_17 -> V_20 . V_22 = V_12 -> V_57 . V_58 >> V_46 ;
V_49 = F_38 ( V_2 , & V_17 -> V_20 , false , true , false ) ;
if ( F_17 ( V_49 != 0 ) )
return V_49 ;
V_144 = V_2 -> V_119 . V_120 << V_46 ;
if ( ( V_144 + V_37 ) > V_12 -> V_57 . V_58 )
return - V_138 ;
}
}
return 0 ;
}
int F_76 ( struct V_1 * V_2 , T_1 * V_142 , bool V_145 )
{
int V_49 ;
V_49 = F_77 ( & V_2 -> V_11 , true , V_145 , false , 0 ) ;
if ( F_17 ( V_49 != 0 ) )
return V_49 ;
F_78 ( & V_2 -> V_11 . V_51 -> V_146 ) ;
if ( V_142 )
* V_142 = V_2 -> V_11 . V_119 . V_142 ;
if ( V_2 -> V_11 . V_147 )
V_49 = F_79 ( & V_2 -> V_11 , true , true , V_145 ) ;
F_80 ( & V_2 -> V_11 . V_51 -> V_146 ) ;
F_81 ( & V_2 -> V_11 ) ;
return V_49 ;
}
int F_70 ( struct V_1 * V_2 , bool V_145 )
{
int V_49 ;
V_49 = F_77 ( & V_2 -> V_11 , true , V_145 , false , 0 ) ;
if ( F_17 ( V_49 != 0 ) ) {
if ( V_49 != - V_69 )
F_25 ( V_2 -> V_12 -> V_70 , L_11 , V_2 ) ;
return V_49 ;
}
return 0 ;
}
struct V_3 * V_3 ( struct V_1 * V_17 , struct V_148 * V_6 )
{
struct V_3 * V_4 ;
F_59 (bo_va, &rbo->va, bo_list) {
if ( V_4 -> V_6 == V_6 ) {
return V_4 ;
}
}
return NULL ;
}
