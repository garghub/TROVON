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
return F_20 ( & V_49 -> V_29 . V_54 , V_53 ) ;
}
static int F_21 ( struct V_2 * V_5 ,
struct V_55 * V_56 )
{
struct V_31 * V_32 = & V_5 -> V_32 [ V_56 -> V_57 ] ;
struct V_1 * V_58 = F_1 ( V_5 ) ;
V_56 -> V_59 . V_60 = NULL ;
V_56 -> V_59 . V_61 = 0 ;
V_56 -> V_59 . V_15 = V_56 -> V_62 << V_63 ;
V_56 -> V_59 . V_64 = 0 ;
V_56 -> V_59 . V_65 = false ;
if ( ! ( V_32 -> V_34 & V_35 ) )
return - V_46 ;
switch ( V_56 -> V_57 ) {
case V_33 :
return 0 ;
case V_40 :
V_56 -> V_59 . V_61 = V_56 -> V_66 << V_63 ;
V_56 -> V_59 . V_64 = F_22 ( V_58 -> V_67 -> V_68 , 0 ) ;
V_56 -> V_59 . V_65 = true ;
break;
default:
return - V_46 ;
break;
}
return 0 ;
}
static void F_23 ( struct V_2 * V_5 , struct V_55 * V_56 )
{
}
static int F_24 ( struct V_25 * V_28 ,
bool V_69 , bool V_70 ,
bool V_71 ,
struct V_55 * V_72 )
{
int V_11 ;
V_11 = F_25 ( V_28 , V_69 , V_71 , V_72 ) ;
return V_11 ;
}
static void F_26 ( struct V_73 * V_74 )
{
F_27 ( V_74 ) ;
F_14 ( V_74 ) ;
}
static struct V_73 * F_28 ( struct V_2 * V_5 ,
unsigned long V_15 , T_1 V_75 ,
struct V_76 * V_77 )
{
struct V_73 * V_74 ;
V_74 = F_29 ( sizeof( struct V_73 ) , V_78 ) ;
if ( V_74 == NULL )
return NULL ;
V_74 -> V_41 = & V_79 ;
if ( F_30 ( V_74 , V_5 , V_15 , V_75 , V_77 ) ) {
F_14 ( V_74 ) ;
return NULL ;
}
return V_74 ;
}
static int F_31 ( struct V_73 * V_4 )
{
return F_32 ( V_4 ) ;
}
static void F_33 ( struct V_73 * V_4 )
{
F_34 ( V_4 ) ;
}
int F_35 ( struct V_1 * V_58 )
{
int V_80 ;
struct V_81 * V_67 = V_58 -> V_67 ;
struct V_2 * V_5 = & V_58 -> V_4 . V_5 ;
V_80 = F_7 ( V_58 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_36 ( & V_58 -> V_4 . V_5 ,
V_58 -> V_4 . V_19 . V_7 . V_8 ,
& V_82 , V_83 ,
true ) ;
if ( V_80 ) {
F_9 ( L_5 , V_80 ) ;
return V_80 ;
}
V_80 = F_37 ( V_5 , V_40 , V_58 -> V_84 . V_85 >> V_63 ) ;
if ( V_80 ) {
F_9 ( L_6 , V_80 ) ;
return V_80 ;
}
V_58 -> V_86 = F_38 ( F_22 ( V_67 -> V_68 , 0 ) ,
F_39 ( V_67 -> V_68 , 0 ) ) ;
return 0 ;
}
void F_40 ( struct V_1 * V_58 )
{
F_41 ( & V_58 -> V_4 . V_5 ) ;
F_11 ( V_58 ) ;
F_42 ( V_58 -> V_86 ) ;
V_58 -> V_86 = 0 ;
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
int F_43 ( struct V_81 * V_67 , int V_15 , int V_96 ,
T_1 V_34 , struct V_27 * * V_97 )
{
struct V_1 * V_58 = V_67 -> V_98 ;
struct V_27 * V_49 ;
T_3 V_99 ;
int V_80 ;
V_49 = F_29 ( sizeof( struct V_27 ) , V_78 ) ;
if ( ! V_49 )
return - V_100 ;
V_80 = F_44 ( V_67 , & V_49 -> V_29 , V_15 ) ;
if ( V_80 ) {
F_14 ( V_49 ) ;
return V_80 ;
}
V_49 -> V_28 . V_5 = & V_58 -> V_4 . V_5 ;
V_49 -> V_28 . V_5 -> V_101 = V_67 -> V_101 ;
F_18 ( V_49 , V_93 | V_50 ) ;
V_99 = F_45 ( & V_58 -> V_4 . V_5 , V_15 ,
sizeof( struct V_27 ) ) ;
V_80 = F_46 ( & V_58 -> V_4 . V_5 , & V_49 -> V_28 , V_15 ,
V_102 , & V_49 -> V_51 ,
V_96 >> V_63 , false , NULL , V_99 ,
NULL , F_12 ) ;
if ( V_80 )
return V_80 ;
* V_97 = V_49 ;
return 0 ;
}
static inline T_4 F_47 ( struct V_27 * V_28 )
{
return V_28 -> V_28 . V_61 ;
}
int F_48 ( struct V_27 * V_28 , T_2 V_103 , T_4 * V_104 )
{
int V_105 , V_80 ;
if ( V_28 -> V_106 ) {
V_28 -> V_106 ++ ;
if ( V_104 )
* V_104 = F_47 ( V_28 ) ;
return 0 ;
}
F_18 ( V_28 , V_103 ) ;
for ( V_105 = 0 ; V_105 < V_28 -> V_51 . V_94 ; V_105 ++ )
V_28 -> V_91 [ V_105 ] |= V_107 ;
V_80 = F_49 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false ) ;
if ( V_80 )
return V_80 ;
V_28 -> V_106 = 1 ;
if ( V_104 )
* V_104 = F_47 ( V_28 ) ;
return 0 ;
}
int F_50 ( struct V_27 * V_28 )
{
int V_105 , V_80 ;
if ( ! V_28 -> V_106 ) {
F_9 ( L_7 , V_28 ) ;
return 0 ;
}
V_28 -> V_106 -- ;
if ( V_28 -> V_106 )
return 0 ;
for ( V_105 = 0 ; V_105 < V_28 -> V_51 . V_94 ; V_105 ++ )
V_28 -> V_91 [ V_105 ] &= ~ V_107 ;
V_80 = F_49 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false ) ;
if ( V_80 )
return V_80 ;
return 0 ;
}
int F_51 ( struct V_27 * V_28 )
{
int V_105 , V_80 ;
if ( ! V_28 -> V_106 ) {
F_9 ( L_7 , V_28 ) ;
return 0 ;
}
V_28 -> V_106 -- ;
if ( V_28 -> V_106 )
return 0 ;
if ( V_28 -> V_108 . V_109 )
F_52 ( & V_28 -> V_108 ) ;
F_18 ( V_28 , V_50 ) ;
for ( V_105 = 0 ; V_105 < V_28 -> V_51 . V_94 ; V_105 ++ )
V_28 -> V_91 [ V_105 ] |= V_107 ;
V_80 = F_49 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false ) ;
if ( V_80 ) {
F_9 ( L_8 ) ;
return V_80 ;
}
return 0 ;
}
int F_53 ( struct V_52 * V_53 , struct V_110 * V_111 )
{
struct V_112 * V_113 ;
struct V_1 * V_58 ;
if ( F_54 ( V_111 -> V_114 < V_83 ) )
return F_55 ( V_53 , V_111 ) ;
V_113 = V_53 -> V_115 ;
V_58 = V_113 -> V_116 -> V_67 -> V_98 ;
return F_56 ( V_53 , V_111 , & V_58 -> V_4 . V_5 ) ;
}
