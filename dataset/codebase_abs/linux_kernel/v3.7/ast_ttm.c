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
struct V_1 * V_9 = F_1 ( V_5 ) ;
V_55 -> V_57 . V_58 = NULL ;
V_55 -> V_57 . V_59 = 0 ;
V_55 -> V_57 . V_15 = V_55 -> V_60 << V_61 ;
V_55 -> V_57 . V_62 = 0 ;
V_55 -> V_57 . V_63 = false ;
if ( ! ( V_32 -> V_34 & V_35 ) )
return - V_46 ;
switch ( V_55 -> V_56 ) {
case V_33 :
return 0 ;
case V_40 :
V_55 -> V_57 . V_59 = V_55 -> V_64 << V_61 ;
V_55 -> V_57 . V_62 = F_21 ( V_9 -> V_65 -> V_66 , 0 ) ;
V_55 -> V_57 . V_63 = true ;
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
bool V_67 , bool V_68 ,
bool V_69 , bool V_70 ,
struct V_54 * V_71 )
{
int V_11 ;
V_11 = F_24 ( V_28 , V_67 , V_69 , V_70 , V_71 ) ;
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
int F_34 ( struct V_1 * V_9 )
{
int V_79 ;
struct V_80 * V_65 = V_9 -> V_65 ;
struct V_2 * V_5 = & V_9 -> V_4 . V_5 ;
V_79 = F_7 ( V_9 ) ;
if ( V_79 )
return V_79 ;
V_79 = F_35 ( & V_9 -> V_4 . V_5 ,
V_9 -> V_4 . V_19 . V_7 . V_8 ,
& V_81 , V_82 ,
true ) ;
if ( V_79 ) {
F_9 ( L_5 , V_79 ) ;
return V_79 ;
}
V_79 = F_36 ( V_5 , V_40 ,
V_9 -> V_83 >> V_61 ) ;
if ( V_79 ) {
F_9 ( L_6 , V_79 ) ;
return V_79 ;
}
V_9 -> V_84 = F_37 ( F_21 ( V_65 -> V_66 , 0 ) ,
F_38 ( V_65 -> V_66 , 0 ) ,
V_85 ) ;
return 0 ;
}
void F_39 ( struct V_1 * V_9 )
{
struct V_80 * V_65 = V_9 -> V_65 ;
F_40 ( & V_9 -> V_4 . V_5 ) ;
F_11 ( V_9 ) ;
if ( V_9 -> V_84 >= 0 ) {
F_41 ( V_9 -> V_84 ,
F_21 ( V_65 -> V_66 , 0 ) ,
F_38 ( V_65 -> V_66 , 0 ) , V_85 ) ;
V_9 -> V_84 = - 1 ;
}
}
void F_18 ( struct V_27 * V_28 , int V_86 )
{
T_2 V_87 = 0 ;
V_28 -> V_51 . V_88 = 0 ;
V_28 -> V_51 . V_89 = 0 ;
V_28 -> V_51 . V_51 = V_28 -> V_90 ;
V_28 -> V_51 . V_91 = V_28 -> V_90 ;
if ( V_86 & V_92 )
V_28 -> V_90 [ V_87 ++ ] = V_45 | V_44 | V_92 ;
if ( V_86 & V_50 )
V_28 -> V_90 [ V_87 ++ ] = V_37 | V_50 ;
if ( ! V_87 )
V_28 -> V_90 [ V_87 ++ ] = V_37 | V_50 ;
V_28 -> V_51 . V_93 = V_87 ;
V_28 -> V_51 . V_94 = V_87 ;
}
int F_42 ( struct V_27 * V_28 , bool V_95 )
{
int V_79 ;
V_79 = F_43 ( & V_28 -> V_28 , true , V_95 , false , 0 ) ;
if ( V_79 ) {
if ( V_79 != - V_96 )
F_9 ( L_7 , V_28 ) ;
return V_79 ;
}
return 0 ;
}
void F_44 ( struct V_27 * V_28 )
{
F_45 ( & V_28 -> V_28 ) ;
}
int F_46 ( struct V_80 * V_65 , int V_15 , int V_97 ,
T_1 V_34 , struct V_27 * * V_98 )
{
struct V_1 * V_9 = V_65 -> V_99 ;
struct V_27 * V_49 ;
T_3 V_100 ;
int V_79 ;
V_49 = F_28 ( sizeof( struct V_27 ) , V_77 ) ;
if ( ! V_49 )
return - V_101 ;
V_79 = F_47 ( V_65 , & V_49 -> V_29 , V_15 ) ;
if ( V_79 ) {
F_14 ( V_49 ) ;
return V_79 ;
}
V_49 -> V_29 . V_102 = NULL ;
V_49 -> V_28 . V_5 = & V_9 -> V_4 . V_5 ;
F_18 ( V_49 , V_92 | V_50 ) ;
V_100 = F_48 ( & V_9 -> V_4 . V_5 , V_15 ,
sizeof( struct V_27 ) ) ;
V_79 = F_49 ( & V_9 -> V_4 . V_5 , & V_49 -> V_28 , V_15 ,
V_103 , & V_49 -> V_51 ,
V_97 >> V_61 , 0 , false , NULL , V_100 ,
NULL , F_12 ) ;
if ( V_79 )
return V_79 ;
* V_98 = V_49 ;
return 0 ;
}
static inline T_4 F_50 ( struct V_27 * V_28 )
{
return V_28 -> V_28 . V_59 ;
}
int F_51 ( struct V_27 * V_28 , T_2 V_104 , T_4 * V_105 )
{
int V_106 , V_79 ;
if ( V_28 -> V_107 ) {
V_28 -> V_107 ++ ;
if ( V_105 )
* V_105 = F_50 ( V_28 ) ;
}
F_18 ( V_28 , V_104 ) ;
for ( V_106 = 0 ; V_106 < V_28 -> V_51 . V_93 ; V_106 ++ )
V_28 -> V_90 [ V_106 ] |= V_108 ;
V_79 = F_52 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false , false ) ;
if ( V_79 )
return V_79 ;
V_28 -> V_107 = 1 ;
if ( V_105 )
* V_105 = F_50 ( V_28 ) ;
return 0 ;
}
int F_53 ( struct V_27 * V_28 )
{
int V_106 , V_79 ;
if ( ! V_28 -> V_107 ) {
F_9 ( L_8 , V_28 ) ;
return 0 ;
}
V_28 -> V_107 -- ;
if ( V_28 -> V_107 )
return 0 ;
for ( V_106 = 0 ; V_106 < V_28 -> V_51 . V_93 ; V_106 ++ )
V_28 -> V_90 [ V_106 ] &= ~ V_108 ;
V_79 = F_52 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false , false ) ;
if ( V_79 )
return V_79 ;
return 0 ;
}
int F_54 ( struct V_27 * V_28 )
{
int V_106 , V_79 ;
if ( ! V_28 -> V_107 ) {
F_9 ( L_8 , V_28 ) ;
return 0 ;
}
V_28 -> V_107 -- ;
if ( V_28 -> V_107 )
return 0 ;
if ( V_28 -> V_109 . V_110 )
F_55 ( & V_28 -> V_109 ) ;
F_18 ( V_28 , V_50 ) ;
for ( V_106 = 0 ; V_106 < V_28 -> V_51 . V_93 ; V_106 ++ )
V_28 -> V_90 [ V_106 ] |= V_108 ;
V_79 = F_52 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false , false ) ;
if ( V_79 ) {
F_9 ( L_9 ) ;
return V_79 ;
}
return 0 ;
}
int F_56 ( struct V_52 * V_53 , struct V_111 * V_112 )
{
struct V_113 * V_114 ;
struct V_1 * V_9 ;
if ( F_57 ( V_112 -> V_115 < V_82 ) )
return F_58 ( V_53 , V_112 ) ;
V_114 = V_53 -> V_116 ;
V_9 = V_114 -> V_117 -> V_65 -> V_99 ;
return F_59 ( V_53 , V_112 , & V_9 -> V_4 . V_5 ) ;
}
