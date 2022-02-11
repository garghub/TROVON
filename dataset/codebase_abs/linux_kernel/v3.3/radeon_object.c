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
int F_35 ( struct V_1 * V_2 , T_1 V_18 , T_3 * V_73 )
{
int V_47 , V_74 ;
if ( V_2 -> V_75 ) {
V_2 -> V_75 ++ ;
if ( V_73 )
* V_73 = F_36 ( V_2 ) ;
return 0 ;
}
F_13 ( V_2 , V_18 ) ;
if ( V_18 == V_25 ) {
V_2 -> V_20 . V_22 = V_2 -> V_12 -> V_54 . V_55 >> V_44 ;
}
for ( V_74 = 0 ; V_74 < V_2 -> V_20 . V_34 ; V_74 ++ )
V_2 -> V_23 [ V_74 ] |= V_76 ;
V_47 = F_37 ( & V_2 -> V_11 , & V_2 -> V_20 , false , false , false ) ;
if ( F_38 ( V_47 == 0 ) ) {
V_2 -> V_75 = 1 ;
if ( V_73 != NULL )
* V_73 = F_36 ( V_2 ) ;
}
if ( F_17 ( V_47 != 0 ) )
F_25 ( V_2 -> V_12 -> V_67 , L_3 , V_2 ) ;
return V_47 ;
}
int F_39 ( struct V_1 * V_2 )
{
int V_47 , V_74 ;
if ( ! V_2 -> V_75 ) {
F_40 ( V_2 -> V_12 -> V_67 , L_4 , V_2 ) ;
return 0 ;
}
V_2 -> V_75 -- ;
if ( V_2 -> V_75 )
return 0 ;
for ( V_74 = 0 ; V_74 < V_2 -> V_20 . V_34 ; V_74 ++ )
V_2 -> V_23 [ V_74 ] &= ~ V_76 ;
V_47 = F_37 ( & V_2 -> V_11 , & V_2 -> V_20 , false , false , false ) ;
if ( F_17 ( V_47 != 0 ) )
F_25 ( V_2 -> V_12 -> V_67 , L_5 , V_2 ) ;
return V_47 ;
}
int F_41 ( struct V_36 * V_12 )
{
if ( 0 && ( V_12 -> V_77 & V_78 ) ) {
if ( V_12 -> V_54 . V_79 == false )
return 0 ;
}
return F_42 ( & V_12 -> V_48 . V_49 , V_80 ) ;
}
void F_43 ( struct V_36 * V_12 )
{
struct V_1 * V_2 , * V_81 ;
if ( F_44 ( & V_12 -> V_13 . V_82 ) ) {
return;
}
F_25 ( V_12 -> V_67 , L_6 ) ;
F_2 (bo, n, &rdev->gem.objects, list) {
F_3 ( & V_12 -> V_51 -> V_83 ) ;
F_25 ( V_12 -> V_67 , L_7 ,
& V_2 -> V_15 , V_2 , ( unsigned long ) V_2 -> V_15 . V_37 ,
* ( ( unsigned long * ) & V_2 -> V_15 . V_84 ) ) ;
F_3 ( & V_2 -> V_12 -> V_13 . V_7 ) ;
F_9 ( & V_2 -> V_14 ) ;
F_5 ( & V_2 -> V_12 -> V_13 . V_7 ) ;
F_45 ( & V_2 -> V_15 ) ;
F_5 ( & V_12 -> V_51 -> V_83 ) ;
}
}
int F_46 ( struct V_36 * V_12 )
{
V_12 -> V_54 . V_85 = F_47 ( V_12 -> V_54 . V_86 , V_12 -> V_54 . V_87 ,
V_88 , 1 ) ;
F_48 ( L_8 ,
V_12 -> V_54 . V_89 >> 20 ,
( unsigned long long ) V_12 -> V_54 . V_87 >> 20 ) ;
F_48 ( L_9 ,
V_12 -> V_54 . V_90 , V_12 -> V_54 . V_91 ? 'D' : 'S' ) ;
return F_49 ( V_12 ) ;
}
void F_50 ( struct V_36 * V_12 )
{
F_51 ( V_12 ) ;
}
void F_52 ( struct V_92 * V_93 ,
struct V_94 * V_95 )
{
if ( V_93 -> V_96 ) {
F_53 ( & V_93 -> V_97 . V_95 , V_95 ) ;
} else {
F_54 ( & V_93 -> V_97 . V_95 , V_95 ) ;
}
}
int F_55 ( struct V_94 * V_95 )
{
struct V_92 * V_93 ;
struct V_1 * V_2 ;
T_1 V_18 ;
int V_47 ;
V_47 = F_56 ( V_95 ) ;
if ( F_17 ( V_47 != 0 ) ) {
return V_47 ;
}
F_57 (lobj, head, tv.head) {
V_2 = V_93 -> V_2 ;
if ( ! V_2 -> V_75 ) {
V_18 = V_93 -> V_96 ? V_93 -> V_96 : V_93 -> V_98 ;
V_60:
F_13 ( V_2 , V_18 ) ;
V_47 = F_37 ( & V_2 -> V_11 , & V_2 -> V_20 ,
true , false , false ) ;
if ( F_17 ( V_47 ) ) {
if ( V_47 != - V_66 && V_18 == V_25 ) {
V_18 |= V_29 ;
goto V_60;
}
return V_47 ;
}
}
V_93 -> V_99 = F_36 ( V_2 ) ;
V_93 -> V_100 = V_2 -> V_100 ;
}
return 0 ;
}
int F_58 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
return F_59 ( V_102 , & V_2 -> V_11 ) ;
}
int F_60 ( struct V_1 * V_2 )
{
struct V_36 * V_12 = V_2 -> V_12 ;
struct V_103 * V_104 ;
struct V_1 * V_105 ;
int V_106 ;
int V_74 ;
F_61 ( ! F_62 ( & V_2 -> V_11 . V_107 ) ) ;
if ( ! V_2 -> V_100 )
return 0 ;
if ( V_2 -> V_63 >= 0 ) {
V_104 = & V_12 -> V_108 [ V_2 -> V_63 ] ;
V_74 = V_2 -> V_63 ;
goto V_109;
}
V_106 = - 1 ;
for ( V_74 = 0 ; V_74 < V_110 ; V_74 ++ ) {
V_104 = & V_12 -> V_108 [ V_74 ] ;
if ( ! V_104 -> V_2 )
break;
V_105 = V_104 -> V_2 ;
if ( V_105 -> V_75 == 0 )
V_106 = V_74 ;
}
if ( V_74 == V_110 ) {
if ( V_106 == - 1 )
return - V_59 ;
V_104 = & V_12 -> V_108 [ V_106 ] ;
V_105 = V_104 -> V_2 ;
F_63 ( L_10 , V_106 , V_105 ) ;
F_64 ( & V_105 -> V_11 ) ;
V_105 -> V_63 = - 1 ;
V_74 = V_106 ;
}
V_2 -> V_63 = V_74 ;
V_104 -> V_2 = V_2 ;
V_109:
F_65 ( V_12 , V_74 , V_2 -> V_100 , V_2 -> V_111 ,
V_2 -> V_11 . V_112 . V_113 << V_44 ,
V_2 -> V_11 . V_71 << V_44 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_36 * V_12 = V_2 -> V_12 ;
struct V_103 * V_104 ;
if ( V_2 -> V_63 == - 1 )
return;
V_104 = & V_12 -> V_108 [ V_2 -> V_63 ] ;
F_66 ( V_12 , V_2 -> V_63 ) ;
V_104 -> V_2 = NULL ;
V_2 -> V_63 = - 1 ;
}
int F_67 ( struct V_1 * V_2 ,
T_4 V_100 , T_4 V_111 )
{
int V_47 ;
V_47 = F_68 ( V_2 , false ) ;
if ( F_17 ( V_47 != 0 ) )
return V_47 ;
V_2 -> V_100 = V_100 ;
V_2 -> V_111 = V_111 ;
F_69 ( V_2 ) ;
return 0 ;
}
void F_70 ( struct V_1 * V_2 ,
T_4 * V_100 ,
T_4 * V_111 )
{
F_61 ( ! F_62 ( & V_2 -> V_11 . V_107 ) ) ;
if ( V_100 )
* V_100 = V_2 -> V_100 ;
if ( V_111 )
* V_111 = V_2 -> V_111 ;
}
int F_30 ( struct V_1 * V_2 , bool V_114 ,
bool V_115 )
{
F_61 ( ! F_62 ( & V_2 -> V_11 . V_107 ) ) ;
if ( ! ( V_2 -> V_100 & V_116 ) )
return 0 ;
if ( V_115 ) {
F_10 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_11 . V_112 . V_117 != V_80 ) {
if ( ! V_114 )
return 0 ;
if ( V_2 -> V_63 >= 0 )
F_10 ( V_2 ) ;
return 0 ;
}
if ( ( V_2 -> V_63 >= 0 ) && ! V_114 )
return 0 ;
return F_60 ( V_2 ) ;
}
void F_71 ( struct V_10 * V_2 ,
struct V_118 * V_112 )
{
struct V_1 * V_17 ;
if ( ! F_12 ( V_2 ) )
return;
V_17 = F_8 ( V_2 , struct V_1 , V_11 ) ;
F_30 ( V_17 , 0 , 1 ) ;
F_72 ( V_17 -> V_12 , V_17 ) ;
}
int F_73 ( struct V_10 * V_2 )
{
struct V_36 * V_12 ;
struct V_1 * V_17 ;
unsigned long V_119 , V_37 ;
int V_47 ;
if ( ! F_12 ( V_2 ) )
return 0 ;
V_17 = F_8 ( V_2 , struct V_1 , V_11 ) ;
F_30 ( V_17 , 0 , 0 ) ;
V_12 = V_17 -> V_12 ;
if ( V_2 -> V_112 . V_117 == V_80 ) {
V_37 = V_2 -> V_112 . V_71 << V_44 ;
V_119 = V_2 -> V_112 . V_113 << V_44 ;
if ( ( V_119 + V_37 ) > V_12 -> V_54 . V_55 ) {
F_13 ( V_17 , V_25 ) ;
V_17 -> V_20 . V_22 = V_12 -> V_54 . V_55 >> V_44 ;
V_47 = F_37 ( V_2 , & V_17 -> V_20 , false , true , false ) ;
if ( F_17 ( V_47 != 0 ) )
return V_47 ;
V_119 = V_2 -> V_112 . V_113 << V_44 ;
if ( ( V_119 + V_37 ) > V_12 -> V_54 . V_55 )
return - V_120 ;
}
}
return 0 ;
}
int F_74 ( struct V_1 * V_2 , T_1 * V_117 , bool V_121 )
{
int V_47 ;
V_47 = F_75 ( & V_2 -> V_11 , true , V_121 , false , 0 ) ;
if ( F_17 ( V_47 != 0 ) )
return V_47 ;
F_76 ( & V_2 -> V_11 . V_49 -> V_122 ) ;
if ( V_117 )
* V_117 = V_2 -> V_11 . V_112 . V_117 ;
if ( V_2 -> V_11 . V_123 )
V_47 = F_77 ( & V_2 -> V_11 , true , true , V_121 ) ;
F_78 ( & V_2 -> V_11 . V_49 -> V_122 ) ;
F_79 ( & V_2 -> V_11 ) ;
return V_47 ;
}
int F_68 ( struct V_1 * V_2 , bool V_121 )
{
int V_47 ;
V_47 = F_75 ( & V_2 -> V_11 , true , V_121 , false , 0 ) ;
if ( F_17 ( V_47 != 0 ) ) {
if ( V_47 != - V_66 )
F_25 ( V_2 -> V_12 -> V_67 , L_11 , V_2 ) ;
return V_47 ;
}
return 0 ;
}
struct V_3 * V_3 ( struct V_1 * V_17 , struct V_124 * V_6 )
{
struct V_3 * V_4 ;
F_57 (bo_va, &rbo->va, bo_list) {
if ( V_4 -> V_6 == V_6 ) {
return V_4 ;
}
}
return NULL ;
}
