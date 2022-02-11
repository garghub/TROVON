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
struct V_1 * V_9 = F_1 ( V_5 ) ;
V_56 -> V_58 . V_59 = NULL ;
V_56 -> V_58 . V_60 = 0 ;
V_56 -> V_58 . V_15 = V_56 -> V_61 << V_62 ;
V_56 -> V_58 . V_63 = 0 ;
V_56 -> V_58 . V_64 = false ;
if ( ! ( V_32 -> V_34 & V_35 ) )
return - V_46 ;
switch ( V_56 -> V_57 ) {
case V_33 :
return 0 ;
case V_40 :
V_56 -> V_58 . V_60 = V_56 -> V_65 << V_62 ;
V_56 -> V_58 . V_63 = F_22 ( V_9 -> V_66 -> V_67 , 0 ) ;
V_56 -> V_58 . V_64 = true ;
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
static void F_24 ( struct V_68 * V_69 )
{
F_25 ( V_69 ) ;
F_14 ( V_69 ) ;
}
static struct V_68 * F_26 ( struct V_2 * V_5 ,
unsigned long V_15 , T_1 V_70 ,
struct V_71 * V_72 )
{
struct V_68 * V_69 ;
V_69 = F_27 ( sizeof( struct V_68 ) , V_73 ) ;
if ( V_69 == NULL )
return NULL ;
V_69 -> V_41 = & V_74 ;
if ( F_28 ( V_69 , V_5 , V_15 , V_70 , V_72 ) ) {
F_14 ( V_69 ) ;
return NULL ;
}
return V_69 ;
}
static int F_29 ( struct V_68 * V_4 )
{
return F_30 ( V_4 ) ;
}
static void F_31 ( struct V_68 * V_4 )
{
F_32 ( V_4 ) ;
}
int F_33 ( struct V_1 * V_9 )
{
int V_75 ;
struct V_76 * V_66 = V_9 -> V_66 ;
struct V_2 * V_5 = & V_9 -> V_4 . V_5 ;
V_75 = F_7 ( V_9 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_34 ( & V_9 -> V_4 . V_5 ,
V_9 -> V_4 . V_19 . V_7 . V_8 ,
& V_77 ,
V_66 -> V_78 -> V_79 ,
V_80 ,
true ) ;
if ( V_75 ) {
F_9 ( L_5 , V_75 ) ;
return V_75 ;
}
V_75 = F_35 ( V_5 , V_40 ,
V_9 -> V_81 . V_82 >> V_62 ) ;
if ( V_75 ) {
F_9 ( L_6 , V_75 ) ;
return V_75 ;
}
V_9 -> V_83 = F_36 ( F_22 ( V_66 -> V_67 , 0 ) ,
F_37 ( V_66 -> V_67 , 0 ) ) ;
V_9 -> V_84 = true ;
return 0 ;
}
void F_38 ( struct V_1 * V_9 )
{
if ( ! V_9 -> V_84 )
return;
F_39 ( & V_9 -> V_4 . V_5 ) ;
F_11 ( V_9 ) ;
F_40 ( V_9 -> V_83 ) ;
V_9 -> V_83 = 0 ;
}
void F_18 ( struct V_27 * V_28 , int V_85 )
{
T_2 V_86 = 0 ;
unsigned V_87 ;
V_28 -> V_51 . V_51 = V_28 -> V_88 ;
V_28 -> V_51 . V_89 = V_28 -> V_88 ;
if ( V_85 & V_90 )
V_28 -> V_88 [ V_86 ++ ] . V_34 = V_45 | V_44 | V_90 ;
if ( V_85 & V_50 )
V_28 -> V_88 [ V_86 ++ ] . V_34 = V_37 | V_50 ;
if ( ! V_86 )
V_28 -> V_88 [ V_86 ++ ] . V_34 = V_37 | V_50 ;
V_28 -> V_51 . V_91 = V_86 ;
V_28 -> V_51 . V_92 = V_86 ;
for ( V_87 = 0 ; V_87 < V_86 ; ++ V_87 ) {
V_28 -> V_88 [ V_87 ] . V_93 = 0 ;
V_28 -> V_88 [ V_87 ] . V_94 = 0 ;
}
}
int F_41 ( struct V_76 * V_66 , int V_15 , int V_95 ,
T_1 V_34 , struct V_27 * * V_96 )
{
struct V_1 * V_9 = V_66 -> V_97 ;
struct V_27 * V_49 ;
T_3 V_98 ;
int V_75 ;
V_49 = F_27 ( sizeof( struct V_27 ) , V_73 ) ;
if ( ! V_49 )
return - V_99 ;
V_75 = F_42 ( V_66 , & V_49 -> V_29 , V_15 ) ;
if ( V_75 ) {
F_14 ( V_49 ) ;
return V_75 ;
}
V_49 -> V_28 . V_5 = & V_9 -> V_4 . V_5 ;
F_18 ( V_49 , V_90 | V_50 ) ;
V_98 = F_43 ( & V_9 -> V_4 . V_5 , V_15 ,
sizeof( struct V_27 ) ) ;
V_75 = F_44 ( & V_9 -> V_4 . V_5 , & V_49 -> V_28 , V_15 ,
V_100 , & V_49 -> V_51 ,
V_95 >> V_62 , false , NULL , V_98 ,
NULL , NULL , F_12 ) ;
if ( V_75 )
return V_75 ;
* V_96 = V_49 ;
return 0 ;
}
static inline T_4 F_45 ( struct V_27 * V_28 )
{
return V_28 -> V_28 . V_60 ;
}
int F_46 ( struct V_27 * V_28 , T_2 V_101 , T_4 * V_102 )
{
int V_87 , V_75 ;
if ( V_28 -> V_103 ) {
V_28 -> V_103 ++ ;
if ( V_102 )
* V_102 = F_45 ( V_28 ) ;
}
F_18 ( V_28 , V_101 ) ;
for ( V_87 = 0 ; V_87 < V_28 -> V_51 . V_91 ; V_87 ++ )
V_28 -> V_88 [ V_87 ] . V_34 |= V_104 ;
V_75 = F_47 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false ) ;
if ( V_75 )
return V_75 ;
V_28 -> V_103 = 1 ;
if ( V_102 )
* V_102 = F_45 ( V_28 ) ;
return 0 ;
}
int F_48 ( struct V_27 * V_28 )
{
int V_87 , V_75 ;
if ( ! V_28 -> V_103 ) {
F_9 ( L_7 , V_28 ) ;
return 0 ;
}
V_28 -> V_103 -- ;
if ( V_28 -> V_103 )
return 0 ;
if ( V_28 -> V_105 . V_106 )
F_49 ( & V_28 -> V_105 ) ;
F_18 ( V_28 , V_50 ) ;
for ( V_87 = 0 ; V_87 < V_28 -> V_51 . V_91 ; V_87 ++ )
V_28 -> V_88 [ V_87 ] . V_34 |= V_104 ;
V_75 = F_47 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false ) ;
if ( V_75 ) {
F_9 ( L_8 ) ;
return V_75 ;
}
return 0 ;
}
int F_50 ( struct V_52 * V_53 , struct V_107 * V_108 )
{
struct V_109 * V_110 ;
struct V_1 * V_9 ;
if ( F_51 ( V_108 -> V_111 < V_80 ) )
return - V_46 ;
V_110 = V_53 -> V_112 ;
V_9 = V_110 -> V_113 -> V_66 -> V_97 ;
return F_52 ( V_53 , V_108 , & V_9 -> V_4 . V_5 ) ;
}
