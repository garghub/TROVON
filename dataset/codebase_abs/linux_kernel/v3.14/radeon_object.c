static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 (bo_va, tmp, &bo->va, bo_list) {
F_3 ( V_2 -> V_6 , V_4 ) ;
}
}
static void F_4 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_8 , struct V_1 , V_8 ) ;
F_6 ( & V_2 -> V_6 -> V_9 . V_10 ) ;
F_7 ( & V_2 -> V_11 ) ;
F_8 ( & V_2 -> V_6 -> V_9 . V_10 ) ;
F_9 ( V_2 ) ;
F_1 ( V_2 ) ;
F_10 ( & V_2 -> V_12 ) ;
F_11 ( V_2 ) ;
}
bool F_12 ( struct V_7 * V_2 )
{
if ( V_2 -> V_13 == & F_4 )
return true ;
return false ;
}
void F_13 ( struct V_1 * V_14 , T_1 V_15 )
{
T_1 V_16 = 0 ;
V_14 -> V_17 . V_18 = 0 ;
V_14 -> V_17 . V_19 = 0 ;
V_14 -> V_17 . V_17 = V_14 -> V_20 ;
V_14 -> V_17 . V_21 = V_14 -> V_20 ;
if ( V_15 & V_22 )
V_14 -> V_20 [ V_16 ++ ] = V_23 | V_24 |
V_25 ;
if ( V_15 & V_26 ) {
if ( V_14 -> V_6 -> V_27 & V_28 ) {
V_14 -> V_20 [ V_16 ++ ] = V_23 | V_29 ;
} else {
V_14 -> V_20 [ V_16 ++ ] = V_30 | V_29 ;
}
}
if ( V_15 & V_31 ) {
if ( V_14 -> V_6 -> V_27 & V_28 ) {
V_14 -> V_20 [ V_16 ++ ] = V_23 | V_32 ;
} else {
V_14 -> V_20 [ V_16 ++ ] = V_30 | V_32 ;
}
}
if ( ! V_16 )
V_14 -> V_20 [ V_16 ++ ] = V_33 | V_32 ;
V_14 -> V_17 . V_34 = V_16 ;
V_14 -> V_17 . V_35 = V_16 ;
}
int F_14 ( struct V_36 * V_6 ,
unsigned long V_37 , int V_38 , bool V_39 , T_1 V_15 ,
struct V_40 * V_41 , struct V_1 * * V_42 )
{
struct V_1 * V_2 ;
enum V_43 type ;
unsigned long V_44 = F_15 ( V_38 , V_45 ) >> V_46 ;
T_2 V_47 ;
int V_48 ;
V_37 = F_16 ( V_37 , V_45 ) ;
V_6 -> V_49 . V_50 . V_51 = V_6 -> V_52 -> V_51 ;
if ( V_39 ) {
type = V_53 ;
} else if ( V_41 ) {
type = V_54 ;
} else {
type = V_55 ;
}
* V_42 = NULL ;
V_47 = F_17 ( & V_6 -> V_49 . V_50 , V_37 ,
sizeof( struct V_1 ) ) ;
V_2 = F_18 ( sizeof( struct V_1 ) , V_56 ) ;
if ( V_2 == NULL )
return - V_57 ;
V_48 = F_19 ( V_6 -> V_52 , & V_2 -> V_12 , V_37 ) ;
if ( F_20 ( V_48 ) ) {
F_11 ( V_2 ) ;
return V_48 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_58 = - 1 ;
F_21 ( & V_2 -> V_11 ) ;
F_21 ( & V_2 -> V_59 ) ;
F_13 ( V_2 , V_15 ) ;
F_22 ( & V_6 -> V_60 . V_61 ) ;
V_48 = F_23 ( & V_6 -> V_49 . V_50 , & V_2 -> V_8 , V_37 , type ,
& V_2 -> V_17 , V_44 , ! V_39 , NULL ,
V_47 , V_41 , & F_4 ) ;
F_24 ( & V_6 -> V_60 . V_61 ) ;
if ( F_20 ( V_48 != 0 ) ) {
return V_48 ;
}
* V_42 = V_2 ;
F_25 ( V_2 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 , void * * V_62 )
{
bool V_63 ;
int V_48 ;
if ( V_2 -> V_64 ) {
if ( V_62 ) {
* V_62 = V_2 -> V_64 ;
}
return 0 ;
}
V_48 = F_27 ( & V_2 -> V_8 , 0 , V_2 -> V_8 . V_65 , & V_2 -> V_66 ) ;
if ( V_48 ) {
return V_48 ;
}
V_2 -> V_64 = F_28 ( & V_2 -> V_66 , & V_63 ) ;
if ( V_62 ) {
* V_62 = V_2 -> V_64 ;
}
F_29 ( V_2 , 0 , 0 ) ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_64 == NULL )
return;
V_2 -> V_64 = NULL ;
F_29 ( V_2 , 0 , 0 ) ;
F_31 ( & V_2 -> V_66 ) ;
}
void F_32 ( struct V_1 * * V_2 )
{
struct V_7 * V_8 ;
struct V_36 * V_6 ;
if ( ( * V_2 ) == NULL )
return;
V_6 = ( * V_2 ) -> V_6 ;
V_8 = & ( ( * V_2 ) -> V_8 ) ;
F_22 ( & V_6 -> V_60 . V_61 ) ;
F_33 ( & V_8 ) ;
F_24 ( & V_6 -> V_60 . V_61 ) ;
if ( V_8 == NULL )
* V_2 = NULL ;
}
int F_34 ( struct V_1 * V_2 , T_1 V_15 , T_3 V_67 ,
T_3 * V_68 )
{
int V_48 , V_69 ;
if ( V_2 -> V_70 ) {
V_2 -> V_70 ++ ;
if ( V_68 )
* V_68 = F_35 ( V_2 ) ;
if ( V_67 != 0 ) {
T_3 V_71 ;
if ( V_15 == V_22 )
V_71 = V_2 -> V_6 -> V_72 . V_73 ;
else
V_71 = V_2 -> V_6 -> V_72 . V_74 ;
F_36 ( V_67 <
( F_35 ( V_2 ) - V_71 ) ) ;
}
return 0 ;
}
F_13 ( V_2 , V_15 ) ;
if ( V_15 == V_22 ) {
V_2 -> V_17 . V_19 = V_2 -> V_6 -> V_72 . V_75 >> V_46 ;
}
if ( V_67 ) {
T_3 V_19 = V_67 >> V_46 ;
if ( ! V_2 -> V_17 . V_19 )
V_2 -> V_17 . V_19 = V_2 -> V_6 -> V_72 . V_76 >> V_46 ;
if ( V_19 < V_2 -> V_17 . V_19 )
V_2 -> V_17 . V_19 = V_19 ;
}
for ( V_69 = 0 ; V_69 < V_2 -> V_17 . V_34 ; V_69 ++ )
V_2 -> V_20 [ V_69 ] |= V_77 ;
V_48 = F_37 ( & V_2 -> V_8 , & V_2 -> V_17 , false , false ) ;
if ( F_38 ( V_48 == 0 ) ) {
V_2 -> V_70 = 1 ;
if ( V_68 != NULL )
* V_68 = F_35 ( V_2 ) ;
}
if ( F_20 ( V_48 != 0 ) )
F_39 ( V_2 -> V_6 -> V_78 , L_1 , V_2 ) ;
return V_48 ;
}
int F_40 ( struct V_1 * V_2 , T_1 V_15 , T_3 * V_68 )
{
return F_34 ( V_2 , V_15 , 0 , V_68 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
int V_48 , V_69 ;
if ( ! V_2 -> V_70 ) {
F_42 ( V_2 -> V_6 -> V_78 , L_2 , V_2 ) ;
return 0 ;
}
V_2 -> V_70 -- ;
if ( V_2 -> V_70 )
return 0 ;
for ( V_69 = 0 ; V_69 < V_2 -> V_17 . V_34 ; V_69 ++ )
V_2 -> V_20 [ V_69 ] &= ~ V_77 ;
V_48 = F_37 ( & V_2 -> V_8 , & V_2 -> V_17 , false , false ) ;
if ( F_20 ( V_48 != 0 ) )
F_39 ( V_2 -> V_6 -> V_78 , L_3 , V_2 ) ;
return V_48 ;
}
int F_43 ( struct V_36 * V_6 )
{
if ( 0 && ( V_6 -> V_27 & V_79 ) ) {
if ( V_6 -> V_72 . V_80 == false )
return 0 ;
}
return F_44 ( & V_6 -> V_49 . V_50 , V_81 ) ;
}
void F_45 ( struct V_36 * V_6 )
{
struct V_1 * V_2 , * V_82 ;
if ( F_46 ( & V_6 -> V_9 . V_83 ) ) {
return;
}
F_39 ( V_6 -> V_78 , L_4 ) ;
F_2 (bo, n, &rdev->gem.objects, list) {
F_6 ( & V_6 -> V_52 -> V_84 ) ;
F_39 ( V_6 -> V_78 , L_5 ,
& V_2 -> V_12 , V_2 , ( unsigned long ) V_2 -> V_12 . V_37 ,
* ( ( unsigned long * ) & V_2 -> V_12 . V_85 ) ) ;
F_6 ( & V_2 -> V_6 -> V_9 . V_10 ) ;
F_7 ( & V_2 -> V_11 ) ;
F_8 ( & V_2 -> V_6 -> V_9 . V_10 ) ;
F_47 ( & V_2 -> V_12 ) ;
F_8 ( & V_6 -> V_52 -> V_84 ) ;
}
}
int F_48 ( struct V_36 * V_6 )
{
if ( ! V_6 -> V_86 ) {
V_6 -> V_72 . V_87 = F_49 ( V_6 -> V_72 . V_88 ,
V_6 -> V_72 . V_89 ) ;
}
F_50 ( L_6 ,
V_6 -> V_72 . V_90 >> 20 ,
( unsigned long long ) V_6 -> V_72 . V_89 >> 20 ) ;
F_50 ( L_7 ,
V_6 -> V_72 . V_91 , V_6 -> V_72 . V_92 ? 'D' : 'S' ) ;
return F_51 ( V_6 ) ;
}
void F_52 ( struct V_36 * V_6 )
{
F_53 ( V_6 ) ;
F_54 ( V_6 -> V_72 . V_87 ) ;
}
void F_55 ( struct V_93 * V_94 ,
struct V_95 * V_96 )
{
if ( V_94 -> V_97 ) {
F_56 ( & V_94 -> V_98 . V_96 , V_96 ) ;
} else {
F_57 ( & V_94 -> V_98 . V_96 , V_96 ) ;
}
}
int F_58 ( struct V_99 * V_100 ,
struct V_95 * V_96 , int V_101 )
{
struct V_93 * V_94 ;
struct V_1 * V_2 ;
T_1 V_15 ;
int V_48 ;
V_48 = F_59 ( V_100 , V_96 ) ;
if ( F_20 ( V_48 != 0 ) ) {
return V_48 ;
}
F_60 (lobj, head, tv.head) {
V_2 = V_94 -> V_2 ;
if ( ! V_2 -> V_70 ) {
V_15 = V_94 -> V_15 ;
V_102:
F_13 ( V_2 , V_15 ) ;
if ( V_101 == V_103 )
F_61 ( V_2 ) ;
V_48 = F_37 ( & V_2 -> V_8 , & V_2 -> V_17 ,
true , false ) ;
if ( F_20 ( V_48 ) ) {
if ( V_48 != - V_104 && V_15 != V_94 -> V_105 ) {
V_15 = V_94 -> V_105 ;
goto V_102;
}
F_62 ( V_100 , V_96 ) ;
return V_48 ;
}
}
V_94 -> V_106 = F_35 ( V_2 ) ;
V_94 -> V_107 = V_2 -> V_107 ;
}
return 0 ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_108 * V_109 )
{
return F_64 ( V_109 , & V_2 -> V_8 ) ;
}
int F_65 ( struct V_1 * V_2 )
{
struct V_36 * V_6 = V_2 -> V_6 ;
struct V_110 * V_111 ;
struct V_1 * V_112 ;
int V_113 ;
int V_69 ;
F_66 ( & V_2 -> V_8 . V_114 -> V_115 . V_116 ) ;
if ( ! V_2 -> V_107 )
return 0 ;
if ( V_2 -> V_58 >= 0 ) {
V_111 = & V_6 -> V_117 [ V_2 -> V_58 ] ;
V_69 = V_2 -> V_58 ;
goto V_118;
}
V_113 = - 1 ;
for ( V_69 = 0 ; V_69 < V_119 ; V_69 ++ ) {
V_111 = & V_6 -> V_117 [ V_69 ] ;
if ( ! V_111 -> V_2 )
break;
V_112 = V_111 -> V_2 ;
if ( V_112 -> V_70 == 0 )
V_113 = V_69 ;
}
if ( V_69 == V_119 ) {
if ( V_113 == - 1 )
return - V_57 ;
V_111 = & V_6 -> V_117 [ V_113 ] ;
V_112 = V_111 -> V_2 ;
F_67 ( L_8 , V_113 , V_112 ) ;
F_68 ( & V_112 -> V_8 ) ;
V_112 -> V_58 = - 1 ;
V_69 = V_113 ;
}
V_2 -> V_58 = V_69 ;
V_111 -> V_2 = V_2 ;
V_118:
F_69 ( V_6 , V_69 , V_2 -> V_107 , V_2 -> V_120 ,
V_2 -> V_8 . V_121 . V_122 << V_46 ,
V_2 -> V_8 . V_65 << V_46 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_36 * V_6 = V_2 -> V_6 ;
struct V_110 * V_111 ;
if ( V_2 -> V_58 == - 1 )
return;
V_111 = & V_6 -> V_117 [ V_2 -> V_58 ] ;
F_70 ( V_6 , V_2 -> V_58 ) ;
V_111 -> V_2 = NULL ;
V_2 -> V_58 = - 1 ;
}
int F_71 ( struct V_1 * V_2 ,
T_4 V_107 , T_4 V_120 )
{
struct V_36 * V_6 = V_2 -> V_6 ;
int V_48 ;
if ( V_6 -> V_123 >= V_124 ) {
unsigned V_125 , V_126 , V_127 , V_128 , V_129 ;
V_125 = ( V_107 >> V_130 ) & V_131 ;
V_126 = ( V_107 >> V_132 ) & V_133 ;
V_127 = ( V_107 >> V_134 ) & V_135 ;
V_128 = ( V_107 >> V_136 ) & V_137 ;
V_129 = ( V_107 >> V_138 ) & V_139 ;
switch ( V_125 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_140 ;
}
switch ( V_126 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_140 ;
}
switch ( V_127 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_140 ;
}
if ( V_128 > 6 ) {
return - V_140 ;
}
if ( V_129 > 6 ) {
return - V_140 ;
}
}
V_48 = F_72 ( V_2 , false ) ;
if ( F_20 ( V_48 != 0 ) )
return V_48 ;
V_2 -> V_107 = V_107 ;
V_2 -> V_120 = V_120 ;
F_73 ( V_2 ) ;
return 0 ;
}
void F_74 ( struct V_1 * V_2 ,
T_4 * V_107 ,
T_4 * V_120 )
{
F_66 ( & V_2 -> V_8 . V_114 -> V_115 . V_116 ) ;
if ( V_107 )
* V_107 = V_2 -> V_107 ;
if ( V_120 )
* V_120 = V_2 -> V_120 ;
}
int F_29 ( struct V_1 * V_2 , bool V_141 ,
bool V_142 )
{
if ( ! V_142 )
F_66 ( & V_2 -> V_8 . V_114 -> V_115 . V_116 ) ;
if ( ! ( V_2 -> V_107 & V_143 ) )
return 0 ;
if ( V_142 ) {
F_9 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_8 . V_121 . V_144 != V_81 ) {
if ( ! V_141 )
return 0 ;
if ( V_2 -> V_58 >= 0 )
F_9 ( V_2 ) ;
return 0 ;
}
if ( ( V_2 -> V_58 >= 0 ) && ! V_141 )
return 0 ;
return F_65 ( V_2 ) ;
}
void F_75 ( struct V_7 * V_2 ,
struct V_145 * V_121 )
{
struct V_1 * V_14 ;
if ( ! F_12 ( V_2 ) )
return;
V_14 = F_5 ( V_2 , struct V_1 , V_8 ) ;
F_29 ( V_14 , 0 , 1 ) ;
F_76 ( V_14 -> V_6 , V_14 ) ;
}
int F_77 ( struct V_7 * V_2 )
{
struct V_36 * V_6 ;
struct V_1 * V_14 ;
unsigned long V_146 , V_37 ;
int V_48 ;
if ( ! F_12 ( V_2 ) )
return 0 ;
V_14 = F_5 ( V_2 , struct V_1 , V_8 ) ;
F_29 ( V_14 , 0 , 0 ) ;
V_6 = V_14 -> V_6 ;
if ( V_2 -> V_121 . V_144 == V_81 ) {
V_37 = V_2 -> V_121 . V_65 << V_46 ;
V_146 = V_2 -> V_121 . V_122 << V_46 ;
if ( ( V_146 + V_37 ) > V_6 -> V_72 . V_75 ) {
F_13 ( V_14 , V_22 ) ;
V_14 -> V_17 . V_19 = V_6 -> V_72 . V_75 >> V_46 ;
V_48 = F_37 ( V_2 , & V_14 -> V_17 , false , false ) ;
if ( F_20 ( V_48 != 0 ) )
return V_48 ;
V_146 = V_2 -> V_121 . V_122 << V_46 ;
if ( ( V_146 + V_37 ) > V_6 -> V_72 . V_75 )
return - V_140 ;
}
}
return 0 ;
}
int F_78 ( struct V_1 * V_2 , T_1 * V_144 , bool V_147 )
{
int V_48 ;
V_48 = F_79 ( & V_2 -> V_8 , true , V_147 , false , 0 ) ;
if ( F_20 ( V_48 != 0 ) )
return V_48 ;
F_80 ( & V_2 -> V_8 . V_50 -> V_148 ) ;
if ( V_144 )
* V_144 = V_2 -> V_8 . V_121 . V_144 ;
if ( V_2 -> V_8 . V_149 )
V_48 = F_81 ( & V_2 -> V_8 , true , true , V_147 ) ;
F_82 ( & V_2 -> V_8 . V_50 -> V_148 ) ;
F_83 ( & V_2 -> V_8 ) ;
return V_48 ;
}
