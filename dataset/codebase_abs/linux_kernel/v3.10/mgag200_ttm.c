static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static int
F_3 ( struct V_6 * V_7 )
{
return F_4 ( V_7 -> V_8 ) ;
}
static void
F_5 ( struct V_6 * V_7 )
{
F_6 ( V_7 -> V_8 ) ;
}
static int F_7 ( struct V_1 * V_9 )
{
struct V_6 * V_10 ;
int V_11 ;
V_10 = & V_9 -> V_4 . V_12 ;
V_10 -> V_13 = V_14 ;
V_10 -> V_15 = sizeof( struct V_16 ) ;
V_10 -> V_17 = & F_3 ;
V_10 -> V_18 = & F_5 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_1
L_2 ) ;
return V_11 ;
}
V_9 -> V_4 . V_19 . V_20 =
V_9 -> V_4 . V_12 . V_8 ;
V_10 = & V_9 -> V_4 . V_19 . V_7 ;
V_10 -> V_13 = V_21 ;
V_10 -> V_15 = sizeof( struct V_22 ) ;
V_10 -> V_17 = & V_23 ;
V_10 -> V_18 = & V_24 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_3 ) ;
F_10 ( & V_9 -> V_4 . V_12 ) ;
return V_11 ;
}
return 0 ;
}
void
F_11 ( struct V_1 * V_9 )
{
if ( V_9 -> V_4 . V_12 . V_18 == NULL )
return;
F_10 ( & V_9 -> V_4 . V_19 . V_7 ) ;
F_10 ( & V_9 -> V_4 . V_12 ) ;
V_9 -> V_4 . V_12 . V_18 = NULL ;
}
static void F_12 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
V_28 = F_2 ( V_26 , struct V_27 , V_28 ) ;
F_13 ( & V_28 -> V_29 ) ;
F_14 ( V_28 ) ;
}
bool F_15 ( struct V_25 * V_28 )
{
if ( V_28 -> V_30 == & F_12 )
return true ;
return false ;
}
static int
F_16 ( struct V_2 * V_5 , T_1 type ,
struct V_31 * V_32 )
{
switch ( type ) {
case V_33 :
V_32 -> V_34 = V_35 ;
V_32 -> V_36 = V_37 ;
V_32 -> V_38 = V_39 ;
break;
case V_40 :
V_32 -> V_41 = & V_42 ;
V_32 -> V_34 = V_43 |
V_35 ;
V_32 -> V_36 = V_44 |
V_45 ;
V_32 -> V_38 = V_45 ;
break;
default:
F_9 ( L_4 , ( unsigned ) type ) ;
return - V_46 ;
}
return 0 ;
}
static void
F_17 ( struct V_25 * V_28 , struct V_47 * V_48 )
{
struct V_27 * V_49 = V_27 ( V_28 ) ;
if ( ! F_15 ( V_28 ) )
return;
F_18 ( V_49 , V_50 ) ;
* V_48 = V_49 -> V_51 ;
}
static int F_19 ( struct V_25 * V_28 , struct V_52 * V_53 )
{
return 0 ;
}
static int F_20 ( struct V_2 * V_5 ,
struct V_54 * V_55 )
{
struct V_31 * V_32 = & V_5 -> V_32 [ V_55 -> V_56 ] ;
struct V_1 * V_57 = F_1 ( V_5 ) ;
V_55 -> V_58 . V_59 = NULL ;
V_55 -> V_58 . V_60 = 0 ;
V_55 -> V_58 . V_15 = V_55 -> V_61 << V_62 ;
V_55 -> V_58 . V_63 = 0 ;
V_55 -> V_58 . V_64 = false ;
if ( ! ( V_32 -> V_34 & V_35 ) )
return - V_46 ;
switch ( V_55 -> V_56 ) {
case V_33 :
return 0 ;
case V_40 :
V_55 -> V_58 . V_60 = V_55 -> V_65 << V_62 ;
V_55 -> V_58 . V_63 = F_21 ( V_57 -> V_66 -> V_67 , 0 ) ;
V_55 -> V_58 . V_64 = true ;
break;
default:
return - V_46 ;
break;
}
return 0 ;
}
static void F_22 ( struct V_2 * V_5 , struct V_54 * V_55 )
{
}
static int F_23 ( struct V_25 * V_28 ,
bool V_68 , bool V_69 ,
bool V_70 ,
struct V_54 * V_71 )
{
int V_11 ;
V_11 = F_24 ( V_28 , V_68 , V_70 , V_71 ) ;
return V_11 ;
}
static void F_25 ( struct V_72 * V_73 )
{
F_26 ( V_73 ) ;
F_14 ( V_73 ) ;
}
struct V_72 * F_27 ( struct V_2 * V_5 ,
unsigned long V_15 , T_1 V_74 ,
struct V_75 * V_76 )
{
struct V_72 * V_73 ;
V_73 = F_28 ( sizeof( struct V_72 ) , V_77 ) ;
if ( V_73 == NULL )
return NULL ;
V_73 -> V_41 = & V_78 ;
if ( F_29 ( V_73 , V_5 , V_15 , V_74 , V_76 ) ) {
F_14 ( V_73 ) ;
return NULL ;
}
return V_73 ;
}
static int F_30 ( struct V_72 * V_4 )
{
return F_31 ( V_4 ) ;
}
static void F_32 ( struct V_72 * V_4 )
{
F_33 ( V_4 ) ;
}
int F_34 ( struct V_1 * V_57 )
{
int V_79 ;
struct V_80 * V_66 = V_57 -> V_66 ;
struct V_2 * V_5 = & V_57 -> V_4 . V_5 ;
V_79 = F_7 ( V_57 ) ;
if ( V_79 )
return V_79 ;
V_79 = F_35 ( & V_57 -> V_4 . V_5 ,
V_57 -> V_4 . V_19 . V_7 . V_8 ,
& V_81 , V_82 ,
true ) ;
if ( V_79 ) {
F_9 ( L_5 , V_79 ) ;
return V_79 ;
}
V_79 = F_36 ( V_5 , V_40 , V_57 -> V_83 . V_84 >> V_62 ) ;
if ( V_79 ) {
F_9 ( L_6 , V_79 ) ;
return V_79 ;
}
V_57 -> V_85 = F_37 ( F_21 ( V_66 -> V_67 , 0 ) ,
F_38 ( V_66 -> V_67 , 0 ) ,
V_86 ) ;
return 0 ;
}
void F_39 ( struct V_1 * V_57 )
{
struct V_80 * V_66 = V_57 -> V_66 ;
F_40 ( & V_57 -> V_4 . V_5 ) ;
F_11 ( V_57 ) ;
if ( V_57 -> V_85 >= 0 ) {
F_41 ( V_57 -> V_85 ,
F_21 ( V_66 -> V_67 , 0 ) ,
F_38 ( V_66 -> V_67 , 0 ) , V_86 ) ;
V_57 -> V_85 = - 1 ;
}
}
void F_18 ( struct V_27 * V_28 , int V_87 )
{
T_2 V_88 = 0 ;
V_28 -> V_51 . V_89 = 0 ;
V_28 -> V_51 . V_90 = 0 ;
V_28 -> V_51 . V_51 = V_28 -> V_91 ;
V_28 -> V_51 . V_92 = V_28 -> V_91 ;
if ( V_87 & V_93 )
V_28 -> V_91 [ V_88 ++ ] = V_45 | V_44 | V_93 ;
if ( V_87 & V_50 )
V_28 -> V_91 [ V_88 ++ ] = V_37 | V_50 ;
if ( ! V_88 )
V_28 -> V_91 [ V_88 ++ ] = V_37 | V_50 ;
V_28 -> V_51 . V_94 = V_88 ;
V_28 -> V_51 . V_95 = V_88 ;
}
int F_42 ( struct V_27 * V_28 , bool V_96 )
{
int V_79 ;
V_79 = F_43 ( & V_28 -> V_28 , true , V_96 , false , 0 ) ;
if ( V_79 ) {
if ( V_79 != - V_97 && V_79 != - V_98 )
F_9 ( L_7 , V_28 , V_79 ) ;
return V_79 ;
}
return 0 ;
}
void F_44 ( struct V_27 * V_28 )
{
F_45 ( & V_28 -> V_28 ) ;
}
int F_46 ( struct V_80 * V_66 , int V_15 , int V_99 ,
T_1 V_34 , struct V_27 * * V_100 )
{
struct V_1 * V_57 = V_66 -> V_101 ;
struct V_27 * V_49 ;
T_3 V_102 ;
int V_79 ;
V_49 = F_28 ( sizeof( struct V_27 ) , V_77 ) ;
if ( ! V_49 )
return - V_103 ;
V_79 = F_47 ( V_66 , & V_49 -> V_29 , V_15 ) ;
if ( V_79 ) {
F_14 ( V_49 ) ;
return V_79 ;
}
V_49 -> V_29 . V_104 = NULL ;
V_49 -> V_28 . V_5 = & V_57 -> V_4 . V_5 ;
F_18 ( V_49 , V_93 | V_50 ) ;
V_102 = F_48 ( & V_57 -> V_4 . V_5 , V_15 ,
sizeof( struct V_27 ) ) ;
V_79 = F_49 ( & V_57 -> V_4 . V_5 , & V_49 -> V_28 , V_15 ,
V_105 , & V_49 -> V_51 ,
V_99 >> V_62 , false , NULL , V_102 ,
NULL , F_12 ) ;
if ( V_79 )
return V_79 ;
* V_100 = V_49 ;
return 0 ;
}
static inline T_4 F_50 ( struct V_27 * V_28 )
{
return V_28 -> V_28 . V_60 ;
}
int F_51 ( struct V_27 * V_28 , T_2 V_106 , T_4 * V_107 )
{
int V_108 , V_79 ;
if ( V_28 -> V_109 ) {
V_28 -> V_109 ++ ;
if ( V_107 )
* V_107 = F_50 ( V_28 ) ;
}
F_18 ( V_28 , V_106 ) ;
for ( V_108 = 0 ; V_108 < V_28 -> V_51 . V_94 ; V_108 ++ )
V_28 -> V_91 [ V_108 ] |= V_110 ;
V_79 = F_52 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false ) ;
if ( V_79 )
return V_79 ;
V_28 -> V_109 = 1 ;
if ( V_107 )
* V_107 = F_50 ( V_28 ) ;
return 0 ;
}
int F_53 ( struct V_27 * V_28 )
{
int V_108 , V_79 ;
if ( ! V_28 -> V_109 ) {
F_9 ( L_8 , V_28 ) ;
return 0 ;
}
V_28 -> V_109 -- ;
if ( V_28 -> V_109 )
return 0 ;
for ( V_108 = 0 ; V_108 < V_28 -> V_51 . V_94 ; V_108 ++ )
V_28 -> V_91 [ V_108 ] &= ~ V_110 ;
V_79 = F_52 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false ) ;
if ( V_79 )
return V_79 ;
return 0 ;
}
int F_54 ( struct V_27 * V_28 )
{
int V_108 , V_79 ;
if ( ! V_28 -> V_109 ) {
F_9 ( L_8 , V_28 ) ;
return 0 ;
}
V_28 -> V_109 -- ;
if ( V_28 -> V_109 )
return 0 ;
if ( V_28 -> V_111 . V_112 )
F_55 ( & V_28 -> V_111 ) ;
F_18 ( V_28 , V_50 ) ;
for ( V_108 = 0 ; V_108 < V_28 -> V_51 . V_94 ; V_108 ++ )
V_28 -> V_91 [ V_108 ] |= V_110 ;
V_79 = F_52 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false ) ;
if ( V_79 ) {
F_9 ( L_9 ) ;
return V_79 ;
}
return 0 ;
}
int F_56 ( struct V_52 * V_53 , struct V_113 * V_114 )
{
struct V_115 * V_116 ;
struct V_1 * V_57 ;
if ( F_57 ( V_114 -> V_117 < V_82 ) )
return F_58 ( V_53 , V_114 ) ;
V_116 = V_53 -> V_118 ;
V_57 = V_116 -> V_119 -> V_66 -> V_101 ;
return F_59 ( V_53 , V_114 , & V_57 -> V_4 . V_5 ) ;
}
