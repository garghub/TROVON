static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_15 * V_16 ;
int V_17 ;
int V_18 , V_19 ;
const struct V_20 * V_21 = & V_4 -> V_9 . V_21 ;
int V_22 ;
V_4 -> V_23 = false ;
V_17 = 24 ;
V_18 = F_3 ( V_13 -> V_24 ) ;
V_4 -> V_18 = V_18 ;
V_4 -> V_25 = 24 ;
V_4 -> V_26 = F_4 ( V_13 ) ;
V_16 = V_4 -> V_9 . V_16 ;
V_22 = F_5 ( V_21 -> V_27 , V_17 ) ;
V_4 -> V_28 = V_22 ;
V_19 = F_6 ( & V_13 -> V_29 , V_22 ) ;
F_7 ( V_17 , V_18 ,
V_21 -> V_27 ,
V_4 -> V_26 ,
& V_4 -> V_30 ) ;
V_4 -> V_30 . V_31 = V_19 ;
return true ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
struct V_5 * V_33 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_34 * V_35 =
F_9 ( V_33 -> V_35 ) ;
int V_36 ;
F_10 ( L_1 , V_13 -> V_37 ) ;
F_11 ( & V_13 -> V_29 , V_35 -> V_38 ) ;
V_36 = F_12 ( & V_13 -> V_29 ) ;
if ( V_36 ) {
F_13 ( L_2 , V_36 ) ;
}
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
struct V_5 * V_33 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_34 * V_35 =
F_9 ( V_33 -> V_35 ) ;
F_10 ( L_1 , V_13 -> V_37 ) ;
F_15 ( & V_13 -> V_29 ) ;
F_16 ( & V_13 -> V_29 ) ;
F_17 ( & V_13 -> V_29 , V_35 -> V_38 ) ;
V_13 -> V_37 -- ;
V_8 -> V_35 = NULL ;
if ( V_13 -> V_37 == 0 ) {
V_11 -> V_9 . V_39 ( & V_11 -> V_9 ,
NULL , NULL ) ;
F_18 ( V_13 , V_40 ) ;
}
}
static void F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_41 * V_42 = F_20 ( V_2 -> V_9 . V_43 ) ;
enum V_38 V_38 = V_11 -> V_38 ;
struct V_34 * V_35 =
F_9 ( V_6 -> V_35 ) ;
int V_36 ;
T_1 V_44 ;
int V_19 ;
V_35 -> V_2 = V_2 ;
V_8 -> V_35 = V_35 ;
F_10 ( L_1 , V_13 -> V_37 ) ;
if ( V_13 -> V_37 == 0 ) {
F_21 ( & V_11 -> V_9 ,
V_4 -> V_45 ) ;
F_22 ( & V_11 -> V_9 ) ;
F_23 ( V_13 ,
V_4 -> V_26 ,
V_4 -> V_18 ,
true ) ;
F_24 ( & V_11 -> V_9 ) ;
F_18 ( V_13 , V_46 ) ;
F_25 ( V_13 ) ;
F_26 ( V_13 ) ;
}
V_36 = F_27 ( & V_13 -> V_29 ,
V_35 -> V_38 ,
V_4 -> V_28 , & V_19 ) ;
if ( V_36 == false ) {
F_13 ( L_3 ) ;
return;
}
V_13 -> V_37 ++ ;
V_44 = F_28 ( F_29 ( V_38 ) ) ;
F_30 ( F_29 ( V_38 ) , V_44 ) ;
V_36 = F_12 ( & V_13 -> V_29 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_41 * V_42 = F_20 ( V_2 -> V_9 . V_43 ) ;
enum V_38 V_38 = V_11 -> V_38 ;
int V_36 ;
F_10 ( L_1 , V_13 -> V_37 ) ;
if ( F_32 ( V_42 ,
F_29 ( V_38 ) ,
V_47 ,
V_47 ,
1 ) )
F_13 ( L_4 ) ;
V_36 = F_15 ( & V_13 -> V_29 ) ;
V_36 = F_16 ( & V_13 -> V_29 ) ;
}
static bool F_33 ( struct V_1 * V_2 ,
enum V_48 * V_48 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
* V_48 = V_8 -> V_48 ;
if ( V_8 -> V_35 )
return true ;
return false ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_49 * V_50 = F_35 ( V_4 -> V_9 . V_50 ) ;
struct V_41 * V_42 = F_20 ( V_2 -> V_9 . V_43 ) ;
enum V_51 V_52 = V_4 -> V_52 ;
T_2 V_44 , V_53 = 0 ;
V_44 = F_28 ( F_36 ( V_52 ) ) ;
if ( V_44 & V_54 )
V_53 |= V_55 ;
else
V_53 |= V_56 ;
if ( V_44 & V_57 )
V_53 |= V_58 ;
else
V_53 |= V_59 ;
switch ( V_44 & V_60 ) {
case V_61 :
V_4 -> V_25 = 18 ;
break;
case V_62 :
V_4 -> V_25 = 24 ;
break;
case V_63 :
V_4 -> V_25 = 30 ;
break;
case V_64 :
V_4 -> V_25 = 36 ;
break;
default:
break;
}
V_4 -> V_9 . V_21 . V_53 |= V_53 ;
V_4 -> V_18 =
( ( V_44 & V_65 ) >> V_66 ) + 1 ;
F_37 ( V_50 , V_4 ) ;
F_38 ( & V_11 -> V_9 , V_4 ) ;
}
static int F_39 ( struct V_67 * V_35 )
{
struct V_34 * V_34 = F_9 ( V_35 ) ;
struct V_13 * V_13 = V_34 -> V_68 ;
struct V_69 * V_69 ;
int V_36 ;
if ( ! V_13 ) {
return F_40 ( V_35 , NULL ) ;
}
V_69 = F_41 ( V_35 , & V_13 -> V_29 , V_34 -> V_38 ) ;
V_36 = F_40 ( V_35 , V_69 ) ;
F_42 ( V_69 ) ;
return V_36 ;
}
static enum V_70
F_43 ( struct V_67 * V_35 , bool V_71 )
{
struct V_34 * V_34 = F_9 ( V_35 ) ;
struct V_13 * V_13 = V_34 -> V_68 ;
if ( ! V_13 )
return V_72 ;
return F_44 ( V_35 , & V_13 -> V_29 , V_34 -> V_38 ) ;
}
static int
F_45 ( struct V_67 * V_35 ,
struct V_73 * V_74 ,
T_3 V_75 )
{
return 0 ;
}
static void
F_46 ( struct V_67 * V_35 )
{
struct V_34 * V_34 = F_9 ( V_35 ) ;
if ( ! F_47 ( V_34 -> V_69 ) )
F_42 ( V_34 -> V_69 ) ;
F_48 ( V_35 ) ;
F_42 ( V_35 ) ;
}
static int F_49 ( struct V_67 * V_35 )
{
return F_39 ( V_35 ) ;
}
static enum V_76
F_50 ( struct V_67 * V_35 ,
struct V_20 * V_77 )
{
int V_78 = F_20 ( V_35 -> V_43 ) -> V_79 ;
if ( V_77 -> clock < 10000 )
return V_80 ;
if ( V_77 -> V_53 & V_81 )
return V_82 ;
if ( V_77 -> clock > V_78 )
return V_83 ;
return V_84 ;
}
static struct V_85 * F_51 ( struct V_67 * V_35 ,
struct V_5 * V_16 )
{
struct V_34 * V_34 = F_9 ( V_35 ) ;
struct V_13 * V_13 = V_34 -> V_68 ;
struct V_49 * V_50 = F_35 ( V_16 -> V_50 ) ;
if ( ! V_13 )
return NULL ;
return & V_13 -> V_86 [ V_50 -> V_48 ] -> V_9 . V_9 ;
}
static struct V_85 * F_52 ( struct V_67 * V_35 )
{
struct V_34 * V_34 = F_9 ( V_35 ) ;
struct V_13 * V_13 = V_34 -> V_68 ;
if ( ! V_13 )
return NULL ;
return & V_13 -> V_86 [ 0 ] -> V_9 . V_9 ;
}
static void F_53 ( struct V_85 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_54 ( V_2 ) ;
F_42 ( V_8 ) ;
}
static bool F_55 ( struct V_34 * V_35 )
{
if ( V_35 -> V_2 && V_35 -> V_9 . V_16 -> V_50 ) {
enum V_48 V_48 ;
if ( ! V_35 -> V_2 -> V_87 ( V_35 -> V_2 , & V_48 ) )
return false ;
return true ;
}
return false ;
}
static void F_56 ( struct V_34 * V_35 )
{
#ifdef F_57
struct V_41 * V_42 = F_20 ( V_35 -> V_9 . V_43 ) ;
if ( V_42 -> V_88 )
F_58 ( & V_42 -> V_88 -> V_89 ,
& V_35 -> V_9 ) ;
#endif
}
static void F_59 ( struct V_34 * V_35 )
{
#ifdef F_57
struct V_41 * V_42 = F_20 ( V_35 -> V_9 . V_43 ) ;
if ( V_42 -> V_88 )
F_60 ( & V_42 -> V_88 -> V_89 ,
& V_35 -> V_9 ) ;
#endif
}
static struct V_67 * F_61 ( struct V_90 * V_91 , struct V_92 * V_38 , const char * V_93 )
{
struct V_13 * V_13 = F_62 ( V_91 , struct V_13 , V_29 ) ;
struct V_10 * V_11 = F_63 ( V_13 ) ;
struct V_94 * V_43 = V_11 -> V_9 . V_9 . V_43 ;
struct V_34 * V_34 ;
struct V_67 * V_35 ;
int V_95 ;
V_34 = F_64 () ;
if ( ! V_34 )
return NULL ;
V_35 = & V_34 -> V_9 ;
F_65 ( V_43 , V_35 , & V_96 , V_97 ) ;
F_66 ( V_35 , & V_98 ) ;
V_34 -> V_87 = F_55 ;
V_34 -> V_68 = V_13 ;
V_34 -> V_38 = V_38 ;
for ( V_95 = V_99 ; V_95 <= V_100 ; V_95 ++ ) {
F_67 ( & V_34 -> V_9 ,
& V_13 -> V_86 [ V_95 ] -> V_9 . V_9 ) ;
}
F_68 ( V_13 , V_35 ) ;
F_69 ( & V_35 -> V_9 , V_43 -> V_101 . V_102 , 0 ) ;
F_69 ( & V_35 -> V_9 , V_43 -> V_101 . V_103 , 0 ) ;
F_70 ( V_35 , V_93 ) ;
return V_35 ;
}
static void F_71 ( struct V_67 * V_35 )
{
struct V_34 * V_34 = F_9 ( V_35 ) ;
struct V_94 * V_43 = V_35 -> V_43 ;
F_72 ( V_43 ) ;
F_56 ( V_34 ) ;
F_73 ( V_43 ) ;
F_74 ( & V_34 -> V_9 ) ;
}
static void F_75 ( struct V_90 * V_91 ,
struct V_67 * V_35 )
{
struct V_34 * V_34 = F_9 ( V_35 ) ;
struct V_94 * V_43 = V_35 -> V_43 ;
F_76 ( V_35 ) ;
F_72 ( V_43 ) ;
F_59 ( V_34 ) ;
V_34 -> V_68 = NULL ;
F_73 ( V_43 ) ;
F_77 ( & V_34 -> V_9 ) ;
F_10 ( L_5 ) ;
}
static void F_78 ( struct V_90 * V_91 )
{
struct V_13 * V_13 = F_62 ( V_91 , struct V_13 , V_29 ) ;
struct V_10 * V_11 = F_63 ( V_13 ) ;
struct V_94 * V_43 = V_11 -> V_9 . V_9 . V_43 ;
F_79 ( V_43 ) ;
}
static struct V_7 *
F_80 ( struct V_10 * V_11 , enum V_48 V_48 )
{
struct V_7 * V_8 ;
struct V_1 * V_1 ;
struct V_94 * V_43 = V_11 -> V_9 . V_9 . V_43 ;
V_8 = F_81 ( sizeof( * V_8 ) , V_104 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_48 = V_48 ;
V_1 = & V_8 -> V_9 ;
V_8 -> V_12 = V_11 ;
F_82 ( V_43 , & V_1 -> V_9 , & V_105 ,
V_106 , L_6 , F_83 ( V_48 ) ) ;
V_1 -> type = V_107 ;
V_1 -> V_38 = V_11 -> V_38 ;
V_1 -> V_108 = 0x7 ;
V_1 -> V_109 = 0 ;
V_1 -> V_110 = F_1 ;
V_1 -> V_111 = F_8 ;
V_1 -> V_39 = F_14 ;
V_1 -> V_112 = F_19 ;
V_1 -> V_113 = F_31 ;
V_1 -> V_87 = F_33 ;
V_1 -> V_114 = F_34 ;
return V_8 ;
}
static bool
F_84 ( struct V_10 * V_11 )
{
int V_95 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
for ( V_95 = V_99 ; V_95 <= V_100 ; V_95 ++ )
V_13 -> V_86 [ V_95 ] = F_80 ( V_11 , V_95 ) ;
return true ;
}
int
F_85 ( struct V_10 * V_11 , int V_115 )
{
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_94 * V_43 = V_11 -> V_9 . V_9 . V_43 ;
int V_36 ;
V_13 -> V_116 = true ;
V_13 -> V_29 . V_117 = & V_118 ;
F_84 ( V_11 ) ;
V_36 = F_86 ( & V_13 -> V_29 , V_43 -> V_43 , & V_13 -> V_119 , 16 , 3 , V_115 ) ;
if ( V_36 ) {
V_13 -> V_116 = false ;
return V_36 ;
}
return 0 ;
}
void
F_87 ( struct V_10 * V_11 )
{
struct V_13 * V_13 = & V_11 -> V_14 ;
if ( ! V_13 -> V_116 )
return;
F_88 ( & V_13 -> V_29 ) ;
}
