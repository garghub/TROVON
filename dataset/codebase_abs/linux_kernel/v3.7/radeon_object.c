void F_1 ( struct V_1 * V_2 )
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
if ( V_15 & V_26 )
V_14 -> V_20 [ V_16 ++ ] = V_27 | V_28 ;
if ( V_15 & V_29 )
V_14 -> V_20 [ V_16 ++ ] = V_27 | V_30 ;
if ( ! V_16 )
V_14 -> V_20 [ V_16 ++ ] = V_27 | V_30 ;
V_14 -> V_17 . V_31 = V_16 ;
V_14 -> V_17 . V_32 = V_16 ;
}
int F_14 ( struct V_33 * V_6 ,
unsigned long V_34 , int V_35 , bool V_36 , T_1 V_15 ,
struct V_37 * V_38 , struct V_1 * * V_39 )
{
struct V_1 * V_2 ;
enum V_40 type ;
unsigned long V_41 = F_15 ( V_35 , V_42 ) >> V_43 ;
T_2 V_44 ;
int V_45 ;
V_34 = F_16 ( V_34 , V_42 ) ;
V_6 -> V_46 . V_47 . V_48 = V_6 -> V_49 -> V_48 ;
if ( V_36 ) {
type = V_50 ;
} else if ( V_38 ) {
type = V_51 ;
} else {
type = V_52 ;
}
* V_39 = NULL ;
V_44 = F_17 ( & V_6 -> V_46 . V_47 , V_34 ,
sizeof( struct V_1 ) ) ;
V_2 = F_18 ( sizeof( struct V_1 ) , V_53 ) ;
if ( V_2 == NULL )
return - V_54 ;
V_45 = F_19 ( V_6 -> V_49 , & V_2 -> V_12 , V_34 ) ;
if ( F_20 ( V_45 ) ) {
F_11 ( V_2 ) ;
return V_45 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_12 . V_55 = NULL ;
V_2 -> V_56 = - 1 ;
F_21 ( & V_2 -> V_11 ) ;
F_21 ( & V_2 -> V_57 ) ;
F_13 ( V_2 , V_15 ) ;
F_22 ( & V_6 -> V_58 . V_59 ) ;
V_45 = F_23 ( & V_6 -> V_46 . V_47 , & V_2 -> V_8 , V_34 , type ,
& V_2 -> V_17 , V_41 , 0 , ! V_36 , NULL ,
V_44 , V_38 , & F_4 ) ;
F_24 ( & V_6 -> V_58 . V_59 ) ;
if ( F_20 ( V_45 != 0 ) ) {
return V_45 ;
}
* V_39 = V_2 ;
F_25 ( V_2 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 , void * * V_60 )
{
bool V_61 ;
int V_45 ;
if ( V_2 -> V_62 ) {
if ( V_60 ) {
* V_60 = V_2 -> V_62 ;
}
return 0 ;
}
V_45 = F_27 ( & V_2 -> V_8 , 0 , V_2 -> V_8 . V_63 , & V_2 -> V_64 ) ;
if ( V_45 ) {
return V_45 ;
}
V_2 -> V_62 = F_28 ( & V_2 -> V_64 , & V_61 ) ;
if ( V_60 ) {
* V_60 = V_2 -> V_62 ;
}
F_29 ( V_2 , 0 , 0 ) ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_62 == NULL )
return;
V_2 -> V_62 = NULL ;
F_29 ( V_2 , 0 , 0 ) ;
F_31 ( & V_2 -> V_64 ) ;
}
void F_32 ( struct V_1 * * V_2 )
{
struct V_7 * V_8 ;
struct V_33 * V_6 ;
if ( ( * V_2 ) == NULL )
return;
V_6 = ( * V_2 ) -> V_6 ;
V_8 = & ( ( * V_2 ) -> V_8 ) ;
F_22 ( & V_6 -> V_58 . V_59 ) ;
F_33 ( & V_8 ) ;
F_24 ( & V_6 -> V_58 . V_59 ) ;
if ( V_8 == NULL )
* V_2 = NULL ;
}
int F_34 ( struct V_1 * V_2 , T_1 V_15 , T_3 V_65 ,
T_3 * V_66 )
{
int V_45 , V_67 ;
if ( V_2 -> V_68 ) {
V_2 -> V_68 ++ ;
if ( V_66 )
* V_66 = F_35 ( V_2 ) ;
if ( V_65 != 0 ) {
T_3 V_69 ;
if ( V_15 == V_22 )
V_69 = V_2 -> V_6 -> V_70 . V_71 ;
else
V_69 = V_2 -> V_6 -> V_70 . V_72 ;
F_36 ( V_65 <
( F_35 ( V_2 ) - V_69 ) ) ;
}
return 0 ;
}
F_13 ( V_2 , V_15 ) ;
if ( V_15 == V_22 ) {
V_2 -> V_17 . V_19 = V_2 -> V_6 -> V_70 . V_73 >> V_43 ;
}
if ( V_65 ) {
T_3 V_19 = V_65 >> V_43 ;
if ( ! V_2 -> V_17 . V_19 )
V_2 -> V_17 . V_19 = V_2 -> V_6 -> V_70 . V_74 >> V_43 ;
if ( V_19 < V_2 -> V_17 . V_19 )
V_2 -> V_17 . V_19 = V_19 ;
}
for ( V_67 = 0 ; V_67 < V_2 -> V_17 . V_31 ; V_67 ++ )
V_2 -> V_20 [ V_67 ] |= V_75 ;
V_45 = F_37 ( & V_2 -> V_8 , & V_2 -> V_17 , false , false , false ) ;
if ( F_38 ( V_45 == 0 ) ) {
V_2 -> V_68 = 1 ;
if ( V_66 != NULL )
* V_66 = F_35 ( V_2 ) ;
}
if ( F_20 ( V_45 != 0 ) )
F_39 ( V_2 -> V_6 -> V_76 , L_1 , V_2 ) ;
return V_45 ;
}
int F_40 ( struct V_1 * V_2 , T_1 V_15 , T_3 * V_66 )
{
return F_34 ( V_2 , V_15 , 0 , V_66 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
int V_45 , V_67 ;
if ( ! V_2 -> V_68 ) {
F_42 ( V_2 -> V_6 -> V_76 , L_2 , V_2 ) ;
return 0 ;
}
V_2 -> V_68 -- ;
if ( V_2 -> V_68 )
return 0 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_17 . V_31 ; V_67 ++ )
V_2 -> V_20 [ V_67 ] &= ~ V_75 ;
V_45 = F_37 ( & V_2 -> V_8 , & V_2 -> V_17 , false , false , false ) ;
if ( F_20 ( V_45 != 0 ) )
F_39 ( V_2 -> V_6 -> V_76 , L_3 , V_2 ) ;
return V_45 ;
}
int F_43 ( struct V_33 * V_6 )
{
if ( 0 && ( V_6 -> V_77 & V_78 ) ) {
if ( V_6 -> V_70 . V_79 == false )
return 0 ;
}
return F_44 ( & V_6 -> V_46 . V_47 , V_80 ) ;
}
void F_45 ( struct V_33 * V_6 )
{
struct V_1 * V_2 , * V_81 ;
if ( F_46 ( & V_6 -> V_9 . V_82 ) ) {
return;
}
F_39 ( V_6 -> V_76 , L_4 ) ;
F_2 (bo, n, &rdev->gem.objects, list) {
F_6 ( & V_6 -> V_49 -> V_83 ) ;
F_39 ( V_6 -> V_76 , L_5 ,
& V_2 -> V_12 , V_2 , ( unsigned long ) V_2 -> V_12 . V_34 ,
* ( ( unsigned long * ) & V_2 -> V_12 . V_84 ) ) ;
F_6 ( & V_2 -> V_6 -> V_9 . V_10 ) ;
F_7 ( & V_2 -> V_11 ) ;
F_8 ( & V_2 -> V_6 -> V_9 . V_10 ) ;
F_47 ( & V_2 -> V_12 ) ;
F_8 ( & V_6 -> V_49 -> V_83 ) ;
}
}
int F_48 ( struct V_33 * V_6 )
{
V_6 -> V_70 . V_85 = F_49 ( V_6 -> V_70 . V_86 , V_6 -> V_70 . V_87 ,
V_88 , 1 ) ;
F_50 ( L_6 ,
V_6 -> V_70 . V_89 >> 20 ,
( unsigned long long ) V_6 -> V_70 . V_87 >> 20 ) ;
F_50 ( L_7 ,
V_6 -> V_70 . V_90 , V_6 -> V_70 . V_91 ? 'D' : 'S' ) ;
return F_51 ( V_6 ) ;
}
void F_52 ( struct V_33 * V_6 )
{
F_53 ( V_6 ) ;
}
void F_54 ( struct V_92 * V_93 ,
struct V_94 * V_95 )
{
if ( V_93 -> V_96 ) {
F_55 ( & V_93 -> V_97 . V_95 , V_95 ) ;
} else {
F_56 ( & V_93 -> V_97 . V_95 , V_95 ) ;
}
}
int F_57 ( struct V_94 * V_95 )
{
struct V_92 * V_93 ;
struct V_1 * V_2 ;
T_1 V_15 ;
int V_45 ;
V_45 = F_58 ( V_95 ) ;
if ( F_20 ( V_45 != 0 ) ) {
return V_45 ;
}
F_59 (lobj, head, tv.head) {
V_2 = V_93 -> V_2 ;
if ( ! V_2 -> V_68 ) {
V_15 = V_93 -> V_96 ? V_93 -> V_96 : V_93 -> V_98 ;
V_99:
F_13 ( V_2 , V_15 ) ;
V_45 = F_37 ( & V_2 -> V_8 , & V_2 -> V_17 ,
true , false , false ) ;
if ( F_20 ( V_45 ) ) {
if ( V_45 != - V_100 && V_15 == V_22 ) {
V_15 |= V_26 ;
goto V_99;
}
return V_45 ;
}
}
V_93 -> V_101 = F_35 ( V_2 ) ;
V_93 -> V_102 = V_2 -> V_102 ;
}
return 0 ;
}
int F_60 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
return F_61 ( V_104 , & V_2 -> V_8 ) ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_33 * V_6 = V_2 -> V_6 ;
struct V_105 * V_106 ;
struct V_1 * V_107 ;
int V_108 ;
int V_67 ;
F_63 ( ! F_64 ( & V_2 -> V_8 . V_109 ) ) ;
if ( ! V_2 -> V_102 )
return 0 ;
if ( V_2 -> V_56 >= 0 ) {
V_106 = & V_6 -> V_110 [ V_2 -> V_56 ] ;
V_67 = V_2 -> V_56 ;
goto V_111;
}
V_108 = - 1 ;
for ( V_67 = 0 ; V_67 < V_112 ; V_67 ++ ) {
V_106 = & V_6 -> V_110 [ V_67 ] ;
if ( ! V_106 -> V_2 )
break;
V_107 = V_106 -> V_2 ;
if ( V_107 -> V_68 == 0 )
V_108 = V_67 ;
}
if ( V_67 == V_112 ) {
if ( V_108 == - 1 )
return - V_54 ;
V_106 = & V_6 -> V_110 [ V_108 ] ;
V_107 = V_106 -> V_2 ;
F_65 ( L_8 , V_108 , V_107 ) ;
F_66 ( & V_107 -> V_8 ) ;
V_107 -> V_56 = - 1 ;
V_67 = V_108 ;
}
V_2 -> V_56 = V_67 ;
V_106 -> V_2 = V_2 ;
V_111:
F_67 ( V_6 , V_67 , V_2 -> V_102 , V_2 -> V_113 ,
V_2 -> V_8 . V_114 . V_115 << V_43 ,
V_2 -> V_8 . V_63 << V_43 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_33 * V_6 = V_2 -> V_6 ;
struct V_105 * V_106 ;
if ( V_2 -> V_56 == - 1 )
return;
V_106 = & V_6 -> V_110 [ V_2 -> V_56 ] ;
F_68 ( V_6 , V_2 -> V_56 ) ;
V_106 -> V_2 = NULL ;
V_2 -> V_56 = - 1 ;
}
int F_69 ( struct V_1 * V_2 ,
T_4 V_102 , T_4 V_113 )
{
struct V_33 * V_6 = V_2 -> V_6 ;
int V_45 ;
if ( V_6 -> V_116 >= V_117 ) {
unsigned V_118 , V_119 , V_120 , V_121 , V_122 ;
V_118 = ( V_102 >> V_123 ) & V_124 ;
V_119 = ( V_102 >> V_125 ) & V_126 ;
V_120 = ( V_102 >> V_127 ) & V_128 ;
V_121 = ( V_102 >> V_129 ) & V_130 ;
V_122 = ( V_102 >> V_131 ) & V_132 ;
switch ( V_118 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_133 ;
}
switch ( V_119 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_133 ;
}
switch ( V_120 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_133 ;
}
if ( V_121 > 6 ) {
return - V_133 ;
}
if ( V_122 > 6 ) {
return - V_133 ;
}
}
V_45 = F_70 ( V_2 , false ) ;
if ( F_20 ( V_45 != 0 ) )
return V_45 ;
V_2 -> V_102 = V_102 ;
V_2 -> V_113 = V_113 ;
F_71 ( V_2 ) ;
return 0 ;
}
void F_72 ( struct V_1 * V_2 ,
T_4 * V_102 ,
T_4 * V_113 )
{
F_63 ( ! F_64 ( & V_2 -> V_8 . V_109 ) ) ;
if ( V_102 )
* V_102 = V_2 -> V_102 ;
if ( V_113 )
* V_113 = V_2 -> V_113 ;
}
int F_29 ( struct V_1 * V_2 , bool V_134 ,
bool V_135 )
{
F_63 ( ! F_64 ( & V_2 -> V_8 . V_109 ) ) ;
if ( ! ( V_2 -> V_102 & V_136 ) )
return 0 ;
if ( V_135 ) {
F_9 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_8 . V_114 . V_137 != V_80 ) {
if ( ! V_134 )
return 0 ;
if ( V_2 -> V_56 >= 0 )
F_9 ( V_2 ) ;
return 0 ;
}
if ( ( V_2 -> V_56 >= 0 ) && ! V_134 )
return 0 ;
return F_62 ( V_2 ) ;
}
void F_73 ( struct V_7 * V_2 ,
struct V_138 * V_114 )
{
struct V_1 * V_14 ;
if ( ! F_12 ( V_2 ) )
return;
V_14 = F_5 ( V_2 , struct V_1 , V_8 ) ;
F_29 ( V_14 , 0 , 1 ) ;
F_74 ( V_14 -> V_6 , V_14 ) ;
}
int F_75 ( struct V_7 * V_2 )
{
struct V_33 * V_6 ;
struct V_1 * V_14 ;
unsigned long V_139 , V_34 ;
int V_45 ;
if ( ! F_12 ( V_2 ) )
return 0 ;
V_14 = F_5 ( V_2 , struct V_1 , V_8 ) ;
F_29 ( V_14 , 0 , 0 ) ;
V_6 = V_14 -> V_6 ;
if ( V_2 -> V_114 . V_137 == V_80 ) {
V_34 = V_2 -> V_114 . V_63 << V_43 ;
V_139 = V_2 -> V_114 . V_115 << V_43 ;
if ( ( V_139 + V_34 ) > V_6 -> V_70 . V_73 ) {
F_13 ( V_14 , V_22 ) ;
V_14 -> V_17 . V_19 = V_6 -> V_70 . V_73 >> V_43 ;
V_45 = F_37 ( V_2 , & V_14 -> V_17 , false , true , false ) ;
if ( F_20 ( V_45 != 0 ) )
return V_45 ;
V_139 = V_2 -> V_114 . V_115 << V_43 ;
if ( ( V_139 + V_34 ) > V_6 -> V_70 . V_73 )
return - V_133 ;
}
}
return 0 ;
}
int F_76 ( struct V_1 * V_2 , T_1 * V_137 , bool V_140 )
{
int V_45 ;
V_45 = F_77 ( & V_2 -> V_8 , true , V_140 , false , 0 ) ;
if ( F_20 ( V_45 != 0 ) )
return V_45 ;
F_78 ( & V_2 -> V_8 . V_47 -> V_141 ) ;
if ( V_137 )
* V_137 = V_2 -> V_8 . V_114 . V_137 ;
if ( V_2 -> V_8 . V_142 )
V_45 = F_79 ( & V_2 -> V_8 , true , true , V_140 ) ;
F_80 ( & V_2 -> V_8 . V_47 -> V_141 ) ;
F_81 ( & V_2 -> V_8 ) ;
return V_45 ;
}
int F_70 ( struct V_1 * V_2 , bool V_143 )
{
int V_45 ;
V_45 = F_77 ( & V_2 -> V_8 , ! V_143 , false , false , 0 ) ;
if ( F_20 ( V_45 != 0 ) ) {
if ( V_45 != - V_100 )
F_39 ( V_2 -> V_6 -> V_76 , L_9 , V_2 ) ;
return V_45 ;
}
return 0 ;
}
