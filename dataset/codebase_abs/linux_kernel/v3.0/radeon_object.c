static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( & V_4 -> V_5 -> V_6 . V_7 ) ;
F_4 ( & V_4 -> V_8 ) ;
F_5 ( & V_4 -> V_5 -> V_6 . V_7 ) ;
F_6 ( V_4 ) ;
F_7 ( & V_4 -> V_9 ) ;
F_8 ( V_4 ) ;
}
bool F_9 ( struct V_1 * V_4 )
{
if ( V_4 -> V_10 == & F_1 )
return true ;
return false ;
}
void F_10 ( struct V_3 * V_11 , T_1 V_12 )
{
T_1 V_13 = 0 ;
V_11 -> V_14 . V_15 = 0 ;
V_11 -> V_14 . V_16 = 0 ;
V_11 -> V_14 . V_14 = V_11 -> V_17 ;
V_11 -> V_14 . V_18 = V_11 -> V_17 ;
if ( V_12 & V_19 )
V_11 -> V_17 [ V_13 ++ ] = V_20 | V_21 |
V_22 ;
if ( V_12 & V_23 )
V_11 -> V_17 [ V_13 ++ ] = V_24 | V_25 ;
if ( V_12 & V_26 )
V_11 -> V_17 [ V_13 ++ ] = V_24 | V_27 ;
if ( ! V_13 )
V_11 -> V_17 [ V_13 ++ ] = V_24 | V_27 ;
V_11 -> V_14 . V_28 = V_13 ;
V_11 -> V_14 . V_29 = V_13 ;
}
int F_11 ( struct V_30 * V_5 ,
unsigned long V_31 , int V_32 , bool V_33 , T_1 V_12 ,
struct V_3 * * V_34 )
{
struct V_3 * V_4 ;
enum V_35 type ;
unsigned long V_36 = F_12 ( V_32 , V_37 ) >> V_38 ;
unsigned long V_39 = 0 ;
int V_40 ;
V_31 = F_13 ( V_31 , V_37 ) ;
if ( F_14 ( V_5 -> V_41 . V_42 . V_43 == NULL ) ) {
V_5 -> V_41 . V_42 . V_43 = V_5 -> V_44 -> V_43 ;
}
if ( V_33 ) {
type = V_45 ;
} else {
type = V_46 ;
}
* V_34 = NULL ;
V_39 = F_15 ( V_5 -> V_47 . V_48 , V_5 -> V_47 . V_49 ) ;
if ( ( V_36 << V_38 ) >= V_39 ) {
F_16 ( V_50 L_1 ,
V_51 , __LINE__ , V_36 >> ( 20 - V_38 ) , V_39 >> 20 ) ;
return - V_52 ;
}
V_53:
V_4 = F_17 ( sizeof( struct V_3 ) , V_54 ) ;
if ( V_4 == NULL )
return - V_52 ;
V_40 = F_18 ( V_5 -> V_44 , & V_4 -> V_9 , V_31 ) ;
if ( F_14 ( V_40 ) ) {
F_8 ( V_4 ) ;
return V_40 ;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_9 . V_55 = NULL ;
V_4 -> V_56 = - 1 ;
F_19 ( & V_4 -> V_8 ) ;
F_10 ( V_4 , V_12 ) ;
F_3 ( & V_5 -> V_57 ) ;
V_40 = F_20 ( & V_5 -> V_41 . V_42 , & V_4 -> V_2 , V_31 , type ,
& V_4 -> V_14 , V_36 , 0 , ! V_33 , NULL , V_31 ,
& F_1 ) ;
F_5 ( & V_5 -> V_57 ) ;
if ( F_14 ( V_40 != 0 ) ) {
if ( V_40 != - V_58 ) {
if ( V_12 == V_19 ) {
V_12 |= V_23 ;
goto V_53;
}
F_21 ( V_5 -> V_59 ,
L_2 ,
V_31 , V_12 ) ;
}
return V_40 ;
}
* V_34 = V_4 ;
F_22 ( V_4 ) ;
return 0 ;
}
int F_23 ( struct V_3 * V_4 , void * * V_60 )
{
bool V_61 ;
int V_40 ;
if ( V_4 -> V_62 ) {
if ( V_60 ) {
* V_60 = V_4 -> V_62 ;
}
return 0 ;
}
V_40 = F_24 ( & V_4 -> V_2 , 0 , V_4 -> V_2 . V_63 , & V_4 -> V_64 ) ;
if ( V_40 ) {
return V_40 ;
}
V_4 -> V_62 = F_25 ( & V_4 -> V_64 , & V_61 ) ;
if ( V_60 ) {
* V_60 = V_4 -> V_62 ;
}
F_26 ( V_4 , 0 , 0 ) ;
return 0 ;
}
void F_27 ( struct V_3 * V_4 )
{
if ( V_4 -> V_62 == NULL )
return;
V_4 -> V_62 = NULL ;
F_26 ( V_4 , 0 , 0 ) ;
F_28 ( & V_4 -> V_64 ) ;
}
void F_29 ( struct V_3 * * V_4 )
{
struct V_1 * V_2 ;
struct V_30 * V_5 ;
if ( ( * V_4 ) == NULL )
return;
V_5 = ( * V_4 ) -> V_5 ;
V_2 = & ( ( * V_4 ) -> V_2 ) ;
F_3 ( & V_5 -> V_57 ) ;
F_30 ( & V_2 ) ;
F_5 ( & V_5 -> V_57 ) ;
if ( V_2 == NULL )
* V_4 = NULL ;
}
int F_31 ( struct V_3 * V_4 , T_1 V_12 , T_2 * V_65 )
{
int V_40 , V_66 ;
if ( V_4 -> V_67 ) {
V_4 -> V_67 ++ ;
if ( V_65 )
* V_65 = F_32 ( V_4 ) ;
return 0 ;
}
F_10 ( V_4 , V_12 ) ;
if ( V_12 == V_19 ) {
V_4 -> V_14 . V_16 = V_4 -> V_5 -> V_47 . V_48 >> V_38 ;
}
for ( V_66 = 0 ; V_66 < V_4 -> V_14 . V_28 ; V_66 ++ )
V_4 -> V_17 [ V_66 ] |= V_68 ;
V_40 = F_33 ( & V_4 -> V_2 , & V_4 -> V_14 , false , false , false ) ;
if ( F_34 ( V_40 == 0 ) ) {
V_4 -> V_67 = 1 ;
if ( V_65 != NULL )
* V_65 = F_32 ( V_4 ) ;
}
if ( F_14 ( V_40 != 0 ) )
F_21 ( V_4 -> V_5 -> V_59 , L_3 , V_4 ) ;
return V_40 ;
}
int F_35 ( struct V_3 * V_4 )
{
int V_40 , V_66 ;
if ( ! V_4 -> V_67 ) {
F_36 ( V_4 -> V_5 -> V_59 , L_4 , V_4 ) ;
return 0 ;
}
V_4 -> V_67 -- ;
if ( V_4 -> V_67 )
return 0 ;
for ( V_66 = 0 ; V_66 < V_4 -> V_14 . V_28 ; V_66 ++ )
V_4 -> V_17 [ V_66 ] &= ~ V_68 ;
V_40 = F_33 ( & V_4 -> V_2 , & V_4 -> V_14 , false , false , false ) ;
if ( F_14 ( V_40 != 0 ) )
F_21 ( V_4 -> V_5 -> V_59 , L_5 , V_4 ) ;
return V_40 ;
}
int F_37 ( struct V_30 * V_5 )
{
if ( 0 && ( V_5 -> V_69 & V_70 ) ) {
if ( V_5 -> V_47 . V_71 == false )
return 0 ;
}
return F_38 ( & V_5 -> V_41 . V_42 , V_72 ) ;
}
void F_39 ( struct V_30 * V_5 )
{
struct V_3 * V_4 , * V_73 ;
if ( F_40 ( & V_5 -> V_6 . V_74 ) ) {
return;
}
F_21 ( V_5 -> V_59 , L_6 ) ;
F_41 (bo, n, &rdev->gem.objects, list) {
F_3 ( & V_5 -> V_44 -> V_75 ) ;
F_21 ( V_5 -> V_59 , L_7 ,
& V_4 -> V_9 , V_4 , ( unsigned long ) V_4 -> V_9 . V_31 ,
* ( ( unsigned long * ) & V_4 -> V_9 . V_76 ) ) ;
F_3 ( & V_4 -> V_5 -> V_6 . V_7 ) ;
F_4 ( & V_4 -> V_8 ) ;
F_5 ( & V_4 -> V_5 -> V_6 . V_7 ) ;
F_42 ( & V_4 -> V_9 ) ;
F_5 ( & V_5 -> V_44 -> V_75 ) ;
}
}
int F_43 ( struct V_30 * V_5 )
{
V_5 -> V_47 . V_77 = F_44 ( V_5 -> V_47 . V_78 , V_5 -> V_47 . V_79 ,
V_80 , 1 ) ;
F_45 ( L_8 ,
V_5 -> V_47 . V_81 >> 20 ,
( unsigned long long ) V_5 -> V_47 . V_79 >> 20 ) ;
F_45 ( L_9 ,
V_5 -> V_47 . V_82 , V_5 -> V_47 . V_83 ? 'D' : 'S' ) ;
return F_46 ( V_5 ) ;
}
void F_47 ( struct V_30 * V_5 )
{
F_48 ( V_5 ) ;
}
void F_49 ( struct V_84 * V_85 ,
struct V_86 * V_87 )
{
if ( V_85 -> V_88 ) {
F_50 ( & V_85 -> V_89 . V_87 , V_87 ) ;
} else {
F_51 ( & V_85 -> V_89 . V_87 , V_87 ) ;
}
}
int F_52 ( struct V_86 * V_87 )
{
struct V_84 * V_85 ;
struct V_3 * V_4 ;
T_1 V_12 ;
int V_40 ;
V_40 = F_53 ( V_87 ) ;
if ( F_14 ( V_40 != 0 ) ) {
return V_40 ;
}
F_54 (lobj, head, tv.head) {
V_4 = V_85 -> V_4 ;
if ( ! V_4 -> V_67 ) {
V_12 = V_85 -> V_88 ? V_85 -> V_88 : V_85 -> V_90 ;
V_53:
F_10 ( V_4 , V_12 ) ;
V_40 = F_33 ( & V_4 -> V_2 , & V_4 -> V_14 ,
true , false , false ) ;
if ( F_14 ( V_40 ) ) {
if ( V_40 != - V_58 && V_12 == V_19 ) {
V_12 |= V_23 ;
goto V_53;
}
return V_40 ;
}
}
V_85 -> V_91 = F_32 ( V_4 ) ;
V_85 -> V_92 = V_4 -> V_92 ;
}
return 0 ;
}
int F_55 ( struct V_3 * V_4 ,
struct V_93 * V_94 )
{
return F_56 ( V_94 , & V_4 -> V_2 ) ;
}
int F_57 ( struct V_3 * V_4 )
{
struct V_30 * V_5 = V_4 -> V_5 ;
struct V_95 * V_96 ;
struct V_3 * V_97 ;
int V_98 ;
int V_66 ;
F_58 ( ! F_59 ( & V_4 -> V_2 . V_99 ) ) ;
if ( ! V_4 -> V_92 )
return 0 ;
if ( V_4 -> V_56 >= 0 ) {
V_96 = & V_5 -> V_100 [ V_4 -> V_56 ] ;
V_66 = V_4 -> V_56 ;
goto V_101;
}
V_98 = - 1 ;
for ( V_66 = 0 ; V_66 < V_102 ; V_66 ++ ) {
V_96 = & V_5 -> V_100 [ V_66 ] ;
if ( ! V_96 -> V_4 )
break;
V_97 = V_96 -> V_4 ;
if ( V_97 -> V_67 == 0 )
V_98 = V_66 ;
}
if ( V_66 == V_102 ) {
if ( V_98 == - 1 )
return - V_52 ;
V_96 = & V_5 -> V_100 [ V_98 ] ;
V_97 = V_96 -> V_4 ;
F_60 ( L_10 , V_98 , V_97 ) ;
F_61 ( & V_97 -> V_2 ) ;
V_97 -> V_56 = - 1 ;
V_66 = V_98 ;
}
V_4 -> V_56 = V_66 ;
V_96 -> V_4 = V_4 ;
V_101:
F_62 ( V_5 , V_66 , V_4 -> V_92 , V_4 -> V_103 ,
V_4 -> V_2 . V_104 . V_105 << V_38 ,
V_4 -> V_2 . V_63 << V_38 ) ;
return 0 ;
}
static void F_6 ( struct V_3 * V_4 )
{
struct V_30 * V_5 = V_4 -> V_5 ;
struct V_95 * V_96 ;
if ( V_4 -> V_56 == - 1 )
return;
V_96 = & V_5 -> V_100 [ V_4 -> V_56 ] ;
F_63 ( V_5 , V_4 -> V_56 ) ;
V_96 -> V_4 = NULL ;
V_4 -> V_56 = - 1 ;
}
int F_64 ( struct V_3 * V_4 ,
T_3 V_92 , T_3 V_103 )
{
int V_40 ;
V_40 = F_65 ( V_4 , false ) ;
if ( F_14 ( V_40 != 0 ) )
return V_40 ;
V_4 -> V_92 = V_92 ;
V_4 -> V_103 = V_103 ;
F_66 ( V_4 ) ;
return 0 ;
}
void F_67 ( struct V_3 * V_4 ,
T_3 * V_92 ,
T_3 * V_103 )
{
F_58 ( ! F_59 ( & V_4 -> V_2 . V_99 ) ) ;
if ( V_92 )
* V_92 = V_4 -> V_92 ;
if ( V_103 )
* V_103 = V_4 -> V_103 ;
}
int F_26 ( struct V_3 * V_4 , bool V_106 ,
bool V_107 )
{
F_58 ( ! F_59 ( & V_4 -> V_2 . V_99 ) ) ;
if ( ! ( V_4 -> V_92 & V_108 ) )
return 0 ;
if ( V_107 ) {
F_6 ( V_4 ) ;
return 0 ;
}
if ( V_4 -> V_2 . V_104 . V_109 != V_72 ) {
if ( ! V_106 )
return 0 ;
if ( V_4 -> V_56 >= 0 )
F_6 ( V_4 ) ;
return 0 ;
}
if ( ( V_4 -> V_56 >= 0 ) && ! V_106 )
return 0 ;
return F_57 ( V_4 ) ;
}
void F_68 ( struct V_1 * V_4 ,
struct V_110 * V_104 )
{
struct V_3 * V_11 ;
if ( ! F_9 ( V_4 ) )
return;
V_11 = F_2 ( V_4 , struct V_3 , V_2 ) ;
F_26 ( V_11 , 0 , 1 ) ;
}
int F_69 ( struct V_1 * V_4 )
{
struct V_30 * V_5 ;
struct V_3 * V_11 ;
unsigned long V_111 , V_31 ;
int V_40 ;
if ( ! F_9 ( V_4 ) )
return 0 ;
V_11 = F_2 ( V_4 , struct V_3 , V_2 ) ;
F_26 ( V_11 , 0 , 0 ) ;
V_5 = V_11 -> V_5 ;
if ( V_4 -> V_104 . V_109 == V_72 ) {
V_31 = V_4 -> V_104 . V_63 << V_38 ;
V_111 = V_4 -> V_104 . V_105 << V_38 ;
if ( ( V_111 + V_31 ) > V_5 -> V_47 . V_48 ) {
F_10 ( V_11 , V_19 ) ;
V_11 -> V_14 . V_16 = V_5 -> V_47 . V_48 >> V_38 ;
V_40 = F_33 ( V_4 , & V_11 -> V_14 , false , true , false ) ;
if ( F_14 ( V_40 != 0 ) )
return V_40 ;
V_111 = V_4 -> V_104 . V_105 << V_38 ;
if ( ( V_111 + V_31 ) > V_5 -> V_47 . V_48 )
return - V_112 ;
}
}
return 0 ;
}
