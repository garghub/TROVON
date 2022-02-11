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
static void
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
static bool F_15 ( struct V_25 * V_28 )
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
struct V_27 * V_49 = V_27 ( V_28 ) ;
return F_20 ( & V_49 -> V_29 . V_54 ,
V_53 -> V_55 ) ;
}
static int F_21 ( struct V_2 * V_5 ,
struct V_56 * V_57 )
{
struct V_31 * V_32 = & V_5 -> V_32 [ V_57 -> V_58 ] ;
struct V_1 * V_9 = F_1 ( V_5 ) ;
V_57 -> V_59 . V_60 = NULL ;
V_57 -> V_59 . V_61 = 0 ;
V_57 -> V_59 . V_15 = V_57 -> V_62 << V_63 ;
V_57 -> V_59 . V_64 = 0 ;
V_57 -> V_59 . V_65 = false ;
if ( ! ( V_32 -> V_34 & V_35 ) )
return - V_46 ;
switch ( V_57 -> V_58 ) {
case V_33 :
return 0 ;
case V_40 :
V_57 -> V_59 . V_61 = V_57 -> V_66 << V_63 ;
V_57 -> V_59 . V_64 = F_22 ( V_9 -> V_67 -> V_68 , 0 ) ;
V_57 -> V_59 . V_65 = true ;
break;
default:
return - V_46 ;
break;
}
return 0 ;
}
static void F_23 ( struct V_2 * V_5 , struct V_56 * V_57 )
{
}
static void F_24 ( struct V_69 * V_70 )
{
F_25 ( V_70 ) ;
F_14 ( V_70 ) ;
}
static struct V_69 * F_26 ( struct V_2 * V_5 ,
unsigned long V_15 , T_1 V_71 ,
struct V_72 * V_73 )
{
struct V_69 * V_70 ;
V_70 = F_27 ( sizeof( struct V_69 ) , V_74 ) ;
if ( V_70 == NULL )
return NULL ;
V_70 -> V_41 = & V_75 ;
if ( F_28 ( V_70 , V_5 , V_15 , V_71 , V_73 ) ) {
F_14 ( V_70 ) ;
return NULL ;
}
return V_70 ;
}
static int F_29 ( struct V_69 * V_4 )
{
return F_30 ( V_4 ) ;
}
static void F_31 ( struct V_69 * V_4 )
{
F_32 ( V_4 ) ;
}
int F_33 ( struct V_1 * V_9 )
{
int V_76 ;
struct V_77 * V_67 = V_9 -> V_67 ;
struct V_2 * V_5 = & V_9 -> V_4 . V_5 ;
V_76 = F_7 ( V_9 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_34 ( & V_9 -> V_4 . V_5 ,
V_9 -> V_4 . V_19 . V_7 . V_8 ,
& V_78 ,
V_67 -> V_79 -> V_80 ,
V_81 ,
true ) ;
if ( V_76 ) {
F_9 ( L_5 , V_76 ) ;
return V_76 ;
}
V_76 = F_35 ( V_5 , V_40 ,
V_9 -> V_82 >> V_63 ) ;
if ( V_76 ) {
F_9 ( L_6 , V_76 ) ;
return V_76 ;
}
F_36 ( F_22 ( V_67 -> V_68 , 0 ) ,
F_37 ( V_67 -> V_68 , 0 ) ) ;
V_9 -> V_83 = F_38 ( F_22 ( V_67 -> V_68 , 0 ) ,
F_37 ( V_67 -> V_68 , 0 ) ) ;
return 0 ;
}
void F_39 ( struct V_1 * V_9 )
{
struct V_77 * V_67 = V_9 -> V_67 ;
F_40 ( & V_9 -> V_4 . V_5 ) ;
F_11 ( V_9 ) ;
F_41 ( V_9 -> V_83 ) ;
F_42 ( F_22 ( V_67 -> V_68 , 0 ) ,
F_37 ( V_67 -> V_68 , 0 ) ) ;
}
void F_18 ( struct V_27 * V_28 , int V_84 )
{
T_2 V_85 = 0 ;
unsigned V_86 ;
V_28 -> V_51 . V_51 = V_28 -> V_87 ;
V_28 -> V_51 . V_88 = V_28 -> V_87 ;
if ( V_84 & V_89 )
V_28 -> V_87 [ V_85 ++ ] . V_34 = V_45 | V_44 | V_89 ;
if ( V_84 & V_50 )
V_28 -> V_87 [ V_85 ++ ] . V_34 = V_39 | V_50 ;
if ( ! V_85 )
V_28 -> V_87 [ V_85 ++ ] . V_34 = V_39 | V_50 ;
V_28 -> V_51 . V_90 = V_85 ;
V_28 -> V_51 . V_91 = V_85 ;
for ( V_86 = 0 ; V_86 < V_85 ; ++ V_86 ) {
V_28 -> V_87 [ V_86 ] . V_92 = 0 ;
V_28 -> V_87 [ V_86 ] . V_93 = 0 ;
}
}
int F_43 ( struct V_77 * V_67 , int V_15 , int V_94 ,
T_1 V_34 , struct V_27 * * V_95 )
{
struct V_1 * V_9 = V_67 -> V_96 ;
struct V_27 * V_49 ;
T_3 V_97 ;
int V_76 ;
V_49 = F_27 ( sizeof( struct V_27 ) , V_74 ) ;
if ( ! V_49 )
return - V_98 ;
V_76 = F_44 ( V_67 , & V_49 -> V_29 , V_15 ) ;
if ( V_76 ) {
F_14 ( V_49 ) ;
return V_76 ;
}
V_49 -> V_28 . V_5 = & V_9 -> V_4 . V_5 ;
F_18 ( V_49 , V_89 | V_50 ) ;
V_97 = F_45 ( & V_9 -> V_4 . V_5 , V_15 ,
sizeof( struct V_27 ) ) ;
V_76 = F_46 ( & V_9 -> V_4 . V_5 , & V_49 -> V_28 , V_15 ,
V_99 , & V_49 -> V_51 ,
V_94 >> V_63 , false , NULL , V_97 ,
NULL , NULL , F_12 ) ;
if ( V_76 )
return V_76 ;
* V_95 = V_49 ;
return 0 ;
}
static inline T_4 F_47 ( struct V_27 * V_28 )
{
return V_28 -> V_28 . V_61 ;
}
int F_48 ( struct V_27 * V_28 , T_2 V_100 , T_4 * V_101 )
{
int V_86 , V_76 ;
if ( V_28 -> V_102 ) {
V_28 -> V_102 ++ ;
if ( V_101 )
* V_101 = F_47 ( V_28 ) ;
}
F_18 ( V_28 , V_100 ) ;
for ( V_86 = 0 ; V_86 < V_28 -> V_51 . V_90 ; V_86 ++ )
V_28 -> V_87 [ V_86 ] . V_34 |= V_103 ;
V_76 = F_49 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false ) ;
if ( V_76 )
return V_76 ;
V_28 -> V_102 = 1 ;
if ( V_101 )
* V_101 = F_47 ( V_28 ) ;
return 0 ;
}
int F_50 ( struct V_27 * V_28 )
{
int V_86 , V_76 ;
if ( ! V_28 -> V_102 ) {
F_9 ( L_7 , V_28 ) ;
return 0 ;
}
V_28 -> V_102 -- ;
if ( V_28 -> V_102 )
return 0 ;
for ( V_86 = 0 ; V_86 < V_28 -> V_51 . V_90 ; V_86 ++ )
V_28 -> V_87 [ V_86 ] . V_34 &= ~ V_103 ;
V_76 = F_49 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false ) ;
if ( V_76 )
return V_76 ;
return 0 ;
}
int F_51 ( struct V_27 * V_28 )
{
int V_86 , V_76 ;
if ( ! V_28 -> V_102 ) {
F_9 ( L_7 , V_28 ) ;
return 0 ;
}
V_28 -> V_102 -- ;
if ( V_28 -> V_102 )
return 0 ;
if ( V_28 -> V_104 . V_105 )
F_52 ( & V_28 -> V_104 ) ;
F_18 ( V_28 , V_50 ) ;
for ( V_86 = 0 ; V_86 < V_28 -> V_51 . V_90 ; V_86 ++ )
V_28 -> V_87 [ V_86 ] . V_34 |= V_103 ;
V_76 = F_49 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false ) ;
if ( V_76 ) {
F_9 ( L_8 ) ;
return V_76 ;
}
return 0 ;
}
int F_53 ( struct V_52 * V_53 , struct V_106 * V_107 )
{
struct V_108 * V_109 ;
struct V_1 * V_9 ;
if ( F_54 ( V_107 -> V_110 < V_81 ) )
return - V_46 ;
V_109 = V_53 -> V_55 ;
V_9 = V_109 -> V_111 -> V_67 -> V_96 ;
return F_55 ( V_53 , V_107 , & V_9 -> V_4 . V_5 ) ;
}
