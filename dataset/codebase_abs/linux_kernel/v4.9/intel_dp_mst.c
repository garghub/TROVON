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
V_4 -> V_23 = true ;
V_4 -> V_24 = false ;
V_17 = 24 ;
V_18 = F_3 ( V_13 -> V_25 ) ;
V_4 -> V_18 = V_18 ;
V_4 -> V_26 = 24 ;
V_4 -> V_27 = F_4 ( V_13 ) ;
V_16 = V_4 -> V_9 . V_16 ;
V_22 = F_5 ( V_21 -> V_28 , V_17 ) ;
V_4 -> V_29 = V_22 ;
V_19 = F_6 ( & V_13 -> V_30 , V_22 ) ;
F_7 ( V_17 , V_18 ,
V_21 -> V_28 ,
V_4 -> V_27 ,
& V_4 -> V_31 ) ;
V_4 -> V_31 . V_32 = V_19 ;
return true ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_33 ,
struct V_5 * V_34 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_35 * V_36 =
F_9 ( V_34 -> V_36 ) ;
int V_37 ;
F_10 ( L_1 , V_13 -> V_38 ) ;
F_11 ( & V_13 -> V_30 , V_36 -> V_39 ) ;
V_37 = F_12 ( & V_13 -> V_30 ) ;
if ( V_37 ) {
F_13 ( L_2 , V_37 ) ;
}
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_33 ,
struct V_5 * V_34 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_35 * V_36 =
F_9 ( V_34 -> V_36 ) ;
F_10 ( L_1 , V_13 -> V_38 ) ;
F_15 ( & V_13 -> V_30 ) ;
F_16 ( & V_13 -> V_30 ) ;
F_17 ( & V_13 -> V_30 , V_36 -> V_39 ) ;
V_13 -> V_38 -- ;
V_8 -> V_36 = NULL ;
if ( V_13 -> V_38 == 0 ) {
V_11 -> V_9 . V_40 ( & V_11 -> V_9 ,
NULL , NULL ) ;
F_18 ( V_13 , V_41 ) ;
}
}
static void F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_42 * V_43 = F_20 ( V_2 -> V_9 . V_44 ) ;
enum V_39 V_39 = V_11 -> V_39 ;
struct V_35 * V_36 =
F_9 ( V_6 -> V_36 ) ;
int V_37 ;
T_1 V_45 ;
int V_19 ;
V_36 -> V_2 = V_2 ;
V_8 -> V_36 = V_36 ;
F_10 ( L_1 , V_13 -> V_38 ) ;
if ( V_13 -> V_38 == 0 ) {
F_21 ( & V_11 -> V_9 ,
V_4 -> V_46 ) ;
F_22 ( & V_11 -> V_9 ) ;
F_23 ( V_13 ,
V_4 -> V_27 ,
V_4 -> V_18 ,
true ) ;
F_24 ( & V_11 -> V_9 ) ;
F_18 ( V_13 , V_47 ) ;
F_25 ( V_13 ) ;
F_26 ( V_13 ) ;
}
V_37 = F_27 ( & V_13 -> V_30 ,
V_36 -> V_39 ,
V_4 -> V_29 , & V_19 ) ;
if ( V_37 == false ) {
F_13 ( L_3 ) ;
return;
}
V_13 -> V_38 ++ ;
V_45 = F_28 ( F_29 ( V_39 ) ) ;
F_30 ( F_29 ( V_39 ) , V_45 ) ;
V_37 = F_12 ( & V_13 -> V_30 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_42 * V_43 = F_20 ( V_2 -> V_9 . V_44 ) ;
enum V_39 V_39 = V_11 -> V_39 ;
int V_37 ;
F_10 ( L_1 , V_13 -> V_38 ) ;
if ( F_32 ( V_43 ,
F_29 ( V_39 ) ,
V_48 ,
V_48 ,
1 ) )
F_13 ( L_4 ) ;
V_37 = F_15 ( & V_13 -> V_30 ) ;
V_37 = F_16 ( & V_13 -> V_30 ) ;
}
static bool F_33 ( struct V_1 * V_2 ,
enum V_49 * V_49 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
* V_49 = V_8 -> V_49 ;
if ( V_8 -> V_36 )
return true ;
return false ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_50 * V_51 = F_35 ( V_4 -> V_9 . V_51 ) ;
struct V_42 * V_43 = F_20 ( V_2 -> V_9 . V_44 ) ;
enum V_52 V_53 = V_4 -> V_53 ;
T_2 V_45 , V_54 = 0 ;
V_45 = F_28 ( F_36 ( V_53 ) ) ;
if ( V_45 & V_55 )
V_54 |= V_56 ;
else
V_54 |= V_57 ;
if ( V_45 & V_58 )
V_54 |= V_59 ;
else
V_54 |= V_60 ;
switch ( V_45 & V_61 ) {
case V_62 :
V_4 -> V_26 = 18 ;
break;
case V_63 :
V_4 -> V_26 = 24 ;
break;
case V_64 :
V_4 -> V_26 = 30 ;
break;
case V_65 :
V_4 -> V_26 = 36 ;
break;
default:
break;
}
V_4 -> V_9 . V_21 . V_54 |= V_54 ;
V_4 -> V_18 =
( ( V_45 & V_66 ) >> V_67 ) + 1 ;
F_37 ( V_51 , V_4 ) ;
F_38 ( & V_11 -> V_9 , V_4 ) ;
}
static int F_39 ( struct V_68 * V_36 )
{
struct V_35 * V_35 = F_9 ( V_36 ) ;
struct V_13 * V_13 = V_35 -> V_69 ;
struct V_70 * V_70 ;
int V_37 ;
if ( ! V_13 ) {
return F_40 ( V_36 , NULL ) ;
}
V_70 = F_41 ( V_36 , & V_13 -> V_30 , V_35 -> V_39 ) ;
V_37 = F_40 ( V_36 , V_70 ) ;
F_42 ( V_70 ) ;
return V_37 ;
}
static enum V_71
F_43 ( struct V_68 * V_36 , bool V_72 )
{
struct V_35 * V_35 = F_9 ( V_36 ) ;
struct V_13 * V_13 = V_35 -> V_69 ;
if ( ! V_13 )
return V_73 ;
return F_44 ( V_36 , & V_13 -> V_30 , V_35 -> V_39 ) ;
}
static int
F_45 ( struct V_68 * V_36 ,
struct V_74 * V_75 ,
T_3 V_76 )
{
return 0 ;
}
static void
F_46 ( struct V_68 * V_36 )
{
struct V_35 * V_35 = F_9 ( V_36 ) ;
if ( ! F_47 ( V_35 -> V_70 ) )
F_42 ( V_35 -> V_70 ) ;
F_48 ( V_36 ) ;
F_42 ( V_36 ) ;
}
static int F_49 ( struct V_68 * V_36 )
{
return F_39 ( V_36 ) ;
}
static enum V_77
F_50 ( struct V_68 * V_36 ,
struct V_20 * V_78 )
{
int V_79 = F_20 ( V_36 -> V_44 ) -> V_80 ;
if ( V_78 -> clock < 10000 )
return V_81 ;
if ( V_78 -> V_54 & V_82 )
return V_83 ;
if ( V_78 -> clock > V_79 )
return V_84 ;
return V_85 ;
}
static struct V_86 * F_51 ( struct V_68 * V_36 ,
struct V_5 * V_16 )
{
struct V_35 * V_35 = F_9 ( V_36 ) ;
struct V_13 * V_13 = V_35 -> V_69 ;
struct V_50 * V_51 = F_35 ( V_16 -> V_51 ) ;
if ( ! V_13 )
return NULL ;
return & V_13 -> V_87 [ V_51 -> V_49 ] -> V_9 . V_9 ;
}
static struct V_86 * F_52 ( struct V_68 * V_36 )
{
struct V_35 * V_35 = F_9 ( V_36 ) ;
struct V_13 * V_13 = V_35 -> V_69 ;
if ( ! V_13 )
return NULL ;
return & V_13 -> V_87 [ 0 ] -> V_9 . V_9 ;
}
static void F_53 ( struct V_86 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_54 ( V_2 ) ;
F_42 ( V_8 ) ;
}
static bool F_55 ( struct V_35 * V_36 )
{
if ( V_36 -> V_2 && V_36 -> V_9 . V_16 -> V_51 ) {
enum V_49 V_49 ;
if ( ! V_36 -> V_2 -> V_88 ( V_36 -> V_2 , & V_49 ) )
return false ;
return true ;
}
return false ;
}
static void F_56 ( struct V_35 * V_36 )
{
#ifdef F_57
struct V_42 * V_43 = F_20 ( V_36 -> V_9 . V_44 ) ;
if ( V_43 -> V_89 )
F_58 ( & V_43 -> V_89 -> V_90 ,
& V_36 -> V_9 ) ;
#endif
}
static void F_59 ( struct V_35 * V_36 )
{
#ifdef F_57
struct V_42 * V_43 = F_20 ( V_36 -> V_9 . V_44 ) ;
if ( V_43 -> V_89 )
F_60 ( & V_43 -> V_89 -> V_90 ,
& V_36 -> V_9 ) ;
#endif
}
static struct V_68 * F_61 ( struct V_91 * V_92 , struct V_93 * V_39 , const char * V_94 )
{
struct V_13 * V_13 = F_62 ( V_92 , struct V_13 , V_30 ) ;
struct V_10 * V_11 = F_63 ( V_13 ) ;
struct V_95 * V_44 = V_11 -> V_9 . V_9 . V_44 ;
struct V_35 * V_35 ;
struct V_68 * V_36 ;
int V_96 ;
V_35 = F_64 () ;
if ( ! V_35 )
return NULL ;
V_36 = & V_35 -> V_9 ;
F_65 ( V_44 , V_36 , & V_97 , V_98 ) ;
F_66 ( V_36 , & V_99 ) ;
V_35 -> V_88 = F_55 ;
V_35 -> V_69 = V_13 ;
V_35 -> V_39 = V_39 ;
for ( V_96 = V_100 ; V_96 <= V_101 ; V_96 ++ ) {
F_67 ( & V_35 -> V_9 ,
& V_13 -> V_87 [ V_96 ] -> V_9 . V_9 ) ;
}
F_68 ( V_13 , V_36 ) ;
F_69 ( & V_36 -> V_9 , V_44 -> V_102 . V_103 , 0 ) ;
F_69 ( & V_36 -> V_9 , V_44 -> V_102 . V_104 , 0 ) ;
F_70 ( V_36 , V_94 ) ;
return V_36 ;
}
static void F_71 ( struct V_68 * V_36 )
{
struct V_35 * V_35 = F_9 ( V_36 ) ;
struct V_95 * V_44 = V_36 -> V_44 ;
F_72 ( V_44 ) ;
F_56 ( V_35 ) ;
F_73 ( V_44 ) ;
F_74 ( & V_35 -> V_9 ) ;
}
static void F_75 ( struct V_91 * V_92 ,
struct V_68 * V_36 )
{
struct V_35 * V_35 = F_9 ( V_36 ) ;
struct V_95 * V_44 = V_36 -> V_44 ;
F_76 ( V_36 ) ;
F_72 ( V_44 ) ;
F_59 ( V_35 ) ;
V_35 -> V_69 = NULL ;
F_73 ( V_44 ) ;
F_77 ( & V_35 -> V_9 ) ;
F_10 ( L_5 ) ;
}
static void F_78 ( struct V_91 * V_92 )
{
struct V_13 * V_13 = F_62 ( V_92 , struct V_13 , V_30 ) ;
struct V_10 * V_11 = F_63 ( V_13 ) ;
struct V_95 * V_44 = V_11 -> V_9 . V_9 . V_44 ;
F_79 ( V_44 ) ;
}
static struct V_7 *
F_80 ( struct V_10 * V_11 , enum V_49 V_49 )
{
struct V_7 * V_8 ;
struct V_1 * V_1 ;
struct V_95 * V_44 = V_11 -> V_9 . V_9 . V_44 ;
V_8 = F_81 ( sizeof( * V_8 ) , V_105 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_49 = V_49 ;
V_1 = & V_8 -> V_9 ;
V_8 -> V_12 = V_11 ;
F_82 ( V_44 , & V_1 -> V_9 , & V_106 ,
V_107 , L_6 , F_83 ( V_49 ) ) ;
V_1 -> type = V_108 ;
V_1 -> V_109 = 0x7 ;
V_1 -> V_110 = 0 ;
V_1 -> V_111 = F_1 ;
V_1 -> V_112 = F_8 ;
V_1 -> V_40 = F_14 ;
V_1 -> V_113 = F_19 ;
V_1 -> V_114 = F_31 ;
V_1 -> V_88 = F_33 ;
V_1 -> V_115 = F_34 ;
return V_8 ;
}
static bool
F_84 ( struct V_10 * V_11 )
{
int V_96 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
for ( V_96 = V_100 ; V_96 <= V_101 ; V_96 ++ )
V_13 -> V_87 [ V_96 ] = F_80 ( V_11 , V_96 ) ;
return true ;
}
int
F_85 ( struct V_10 * V_11 , int V_116 )
{
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_95 * V_44 = V_11 -> V_9 . V_9 . V_44 ;
int V_37 ;
V_13 -> V_117 = true ;
V_13 -> V_30 . V_118 = & V_119 ;
F_84 ( V_11 ) ;
V_37 = F_86 ( & V_13 -> V_30 , V_44 -> V_44 , & V_13 -> V_120 , 16 , 3 , V_116 ) ;
if ( V_37 ) {
V_13 -> V_117 = false ;
return V_37 ;
}
return 0 ;
}
void
F_87 ( struct V_10 * V_11 )
{
struct V_13 * V_13 = & V_11 -> V_14 ;
if ( ! V_13 -> V_117 )
return;
F_88 ( & V_13 -> V_30 ) ;
}
