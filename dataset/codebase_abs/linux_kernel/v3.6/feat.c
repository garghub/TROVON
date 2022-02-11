static int F_1 ( struct V_1 * V_2 , T_1 V_3 , bool V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_7 = F_3 ( V_3 , V_2 , V_4 ) ;
if ( V_7 == NULL )
return - V_8 ;
if ( V_4 ) {
F_4 ( V_6 -> V_9 , V_2 ) ;
V_6 -> V_9 = V_7 ;
} else {
F_5 ( V_6 -> V_10 , V_2 ) ;
V_6 -> V_10 = V_7 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_11 , bool V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_4 ) {
V_6 -> V_12 = V_11 ;
F_7 ( V_2 , V_6 -> V_13 ) ;
} else {
V_6 -> V_14 = V_11 ;
F_8 ( V_2 , V_6 -> V_15 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_16 , bool V_4 )
{
if ( V_4 )
F_2 ( V_2 ) -> V_17 = V_16 ;
else
F_2 ( V_2 ) -> V_18 = V_16 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_19 , bool V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_4 ) {
if ( V_19 && V_6 -> V_20 == NULL ) {
V_6 -> V_20 = F_11 ( F_12 () ) ;
if ( V_6 -> V_20 == NULL )
return - V_8 ;
} else if ( ! V_19 ) {
F_13 ( V_6 -> V_20 ) ;
V_6 -> V_20 = NULL ;
}
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_19 , bool V_4 )
{
if ( ! V_4 )
F_2 ( V_2 ) -> V_21 = ( V_19 > 0 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_22 , bool V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_4 )
V_6 -> V_23 = V_22 ;
else {
if ( V_6 -> V_24 == 0 )
V_6 -> V_24 = V_22 ;
else if ( V_22 > V_6 -> V_24 )
F_16 ( L_1 ,
V_6 -> V_24 , ( V_25 ) V_22 ) ;
}
return 0 ;
}
static int F_17 ( V_25 V_26 )
{
if ( V_26 > V_27 && V_26 <= V_28 )
return V_26 - 1 ;
switch ( V_26 ) {
case V_29 :
return V_30 - 1 ;
}
return - 1 ;
}
static V_25 F_18 ( V_25 V_26 )
{
int V_31 = F_17 ( V_26 ) ;
if ( V_31 < 0 )
return V_32 ;
return V_33 [ V_31 ] . V_34 ;
}
static int F_19 ( V_25 V_26 )
{
int V_31 = F_17 ( V_26 ) ;
F_20 ( V_31 < 0 ) ;
return V_31 < 0 ? 0 : V_33 [ V_31 ] . V_35 ;
}
static const char * F_21 ( const V_25 V_36 )
{
static const char * const V_37 [] = {
[ V_27 ] = L_2 ,
[ V_38 ] = L_3 ,
[ V_39 ] = L_4 ,
[ V_40 ] = L_5 ,
[ V_41 ] = L_6 ,
[ V_42 ] = L_7 ,
[ V_43 ] = L_8 ,
[ V_44 ] = L_9 ,
[ V_45 ] = L_10 ,
[ V_28 ] = L_11 ,
} ;
if ( V_36 > V_28 && V_36 < V_46 )
return V_37 [ V_27 ] ;
if ( V_36 == V_29 )
return L_12 ;
if ( V_36 >= V_46 )
return L_13 ;
return V_37 [ V_36 ] ;
}
static const char * F_22 ( const V_25 V_47 )
{
switch ( V_47 ) {
case V_48 : return L_14 ;
case V_49 : return L_15 ;
case V_50 : return L_16 ;
case V_51 : return L_17 ;
}
return NULL ;
}
static void F_23 ( V_25 V_26 , T_2 const * V_52 )
{
V_25 V_53 , type = F_18 ( V_26 ) ;
if ( V_52 == NULL || ( type == V_54 && V_52 -> V_55 . V_56 == NULL ) )
F_24 ( L_18 ) ;
else if ( type == V_54 )
for ( V_53 = 0 ; V_53 < V_52 -> V_55 . V_57 ; V_53 ++ )
F_24 ( L_19 , V_53 ? L_20 : L_21 , V_52 -> V_55 . V_56 [ V_53 ] ) ;
else if ( type == V_58 )
F_24 ( L_22 , ( unsigned long long ) V_52 -> V_59 ) ;
else
F_24 ( L_23 , type ) ;
}
static void F_25 ( V_25 V_26 , V_25 * V_60 , V_25 V_57 )
{
V_25 type = F_18 ( V_26 ) ;
T_2 V_61 = { . V_55 . V_56 = V_60 , . V_55 . V_57 = V_57 } ;
if ( type == V_58 )
V_61 . V_59 = F_26 ( V_60 , V_57 ) ;
F_23 ( V_26 , & V_61 ) ;
}
static void F_27 ( struct V_62 const * V_63 )
{
F_28 ( L_24 , V_63 -> V_64 ? L_25 : L_26 ,
F_21 ( V_63 -> V_26 ) ) ;
F_23 ( V_63 -> V_26 , & V_63 -> V_52 ) ;
F_24 ( L_27 , V_65 [ V_63 -> V_66 ] ,
V_63 -> V_67 ? L_28 : L_21 ) ;
}
static int F_29 ( struct V_1 * V_2 , const int V_31 ,
const bool V_64 , T_2 const * V_61 )
{
bool V_4 ;
T_1 V_52 ;
if ( V_31 < 0 || V_31 >= V_30 )
return - 1 ;
if ( V_33 [ V_31 ] . V_68 == NULL )
return 0 ;
if ( V_61 == NULL ) {
V_52 = V_33 [ V_31 ] . V_35 ;
} else if ( V_33 [ V_31 ] . V_34 == V_54 ) {
if ( V_61 -> V_55 . V_56 == NULL ) {
F_30 ( L_29 , V_31 ) ;
V_52 = V_33 [ V_31 ] . V_35 ;
} else {
V_52 = V_61 -> V_55 . V_56 [ 0 ] ;
}
} else {
V_52 = V_61 -> V_59 ;
}
V_4 = ( V_64 == ( V_33 [ V_31 ] . V_69 == V_70 ) ) ;
F_28 ( L_30 , V_4 ? L_31 : L_32 ,
F_21 ( V_33 [ V_31 ] . V_26 ) ,
V_61 ? L_21 : L_33 , ( unsigned long long ) V_52 ) ;
return V_33 [ V_31 ] . V_68 ( V_2 , V_52 , V_4 ) ;
}
static int F_31 ( struct V_1 * V_2 , V_25 V_26 , bool V_71 ,
T_2 const * V_61 )
{
return F_29 ( V_2 , F_17 ( V_26 ) , V_71 , V_61 ) ;
}
static inline int F_32 ( V_25 V_26 )
{
return V_26 == V_38 || V_26 == V_39 ||
V_26 == V_40 ;
}
static int F_33 ( T_2 * V_61 , V_25 const * V_52 , V_25 V_57 )
{
V_61 -> V_55 . V_57 = V_57 ;
if ( V_61 -> V_55 . V_57 > 0 ) {
V_61 -> V_55 . V_56 = F_34 ( V_52 , V_57 , F_12 () ) ;
if ( V_61 -> V_55 . V_56 == NULL ) {
V_61 -> V_55 . V_57 = 0 ;
return - V_72 ;
}
}
return 0 ;
}
static void F_35 ( V_25 V_26 , T_2 * V_52 )
{
if ( F_36 ( V_52 == NULL ) )
return;
if ( F_18 ( V_26 ) == V_54 )
F_37 ( V_52 -> V_55 . V_56 ) ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
}
static struct V_62 *
F_38 ( struct V_62 const * V_73 )
{
struct V_62 * V_74 ;
V_25 type = F_18 ( V_73 -> V_26 ) ;
if ( type == V_32 )
return NULL ;
V_74 = F_34 ( V_73 , sizeof( struct V_62 ) , F_12 () ) ;
if ( V_74 == NULL )
return NULL ;
if ( type == V_54 && F_33 ( & V_74 -> V_52 ,
V_73 -> V_52 . V_55 . V_56 ,
V_73 -> V_52 . V_55 . V_57 ) ) {
F_37 ( V_74 ) ;
return NULL ;
}
return V_74 ;
}
static void F_39 ( struct V_62 * V_63 )
{
if ( V_63 != NULL ) {
F_35 ( V_63 -> V_26 , & V_63 -> V_52 ) ;
F_37 ( V_63 ) ;
}
}
static struct V_62 * F_40 ( struct V_75 * V_76 ,
V_25 V_26 , bool V_64 )
{
struct V_62 * V_63 ;
F_41 (entry, fn_list, node) {
if ( V_63 -> V_26 == V_26 && V_63 -> V_64 == V_64 )
return V_63 ;
else if ( V_63 -> V_26 > V_26 )
break;
}
return NULL ;
}
static struct V_62 *
F_42 ( struct V_75 * V_77 , V_25 V_36 , bool V_71 )
{
struct V_62 * V_63 ;
F_41 (entry, head, node)
if ( V_63 -> V_26 == V_36 && V_63 -> V_64 == V_71 ) {
F_35 ( V_63 -> V_26 , & V_63 -> V_52 ) ;
return V_63 ;
} else if ( V_63 -> V_26 > V_36 ) {
V_77 = & V_63 -> V_78 ;
break;
}
V_63 = F_43 ( sizeof( * V_63 ) , F_12 () ) ;
if ( V_63 != NULL ) {
V_63 -> V_26 = V_36 ;
V_63 -> V_64 = V_71 ;
F_44 ( & V_63 -> V_78 , V_77 ) ;
}
return V_63 ;
}
static int F_45 ( struct V_75 * V_76 , V_25 V_36 , V_25 V_71 ,
V_25 V_79 , T_2 * V_61 )
{
struct V_62 * V_74 = F_42 ( V_76 , V_36 , V_71 ) ;
if ( V_74 == NULL )
return - V_8 ;
V_74 -> V_26 = V_36 ;
V_74 -> V_64 = V_71 ;
V_74 -> V_66 = V_80 ;
V_74 -> V_67 = false ;
V_74 -> V_81 = false ;
V_74 -> V_52 = * V_61 ;
V_74 -> V_82 = V_79 ;
return 0 ;
}
static int F_46 ( struct V_75 * V_76 , V_25 V_36 , V_25 V_71 ,
T_2 * V_61 )
{
struct V_62 * V_74 = F_42 ( V_76 , V_36 , V_71 ) ;
if ( V_74 == NULL )
return V_83 ;
V_74 -> V_26 = V_36 ;
V_74 -> V_64 = V_71 ;
V_74 -> V_66 = V_84 ;
V_74 -> V_67 = true ;
V_74 -> V_81 = ( V_61 == NULL ) ;
V_74 -> V_52 . V_59 = 0 ;
if ( ! V_74 -> V_81 )
V_74 -> V_52 = * V_61 ;
V_74 -> V_82 = false ;
return 0 ;
}
static int F_47 ( struct V_75 * V_76 , V_25 V_36 , V_25 V_71 )
{
return F_46 ( V_76 , V_36 , V_71 , NULL ) ;
}
static inline void F_48 ( struct V_62 * V_63 )
{
F_49 ( & V_63 -> V_78 ) ;
F_39 ( V_63 ) ;
}
void F_50 ( struct V_75 * V_76 )
{
struct V_62 * V_63 , * V_85 ;
F_51 (entry, next, fn_list, node)
F_39 ( V_63 ) ;
F_52 ( V_76 ) ;
}
int F_53 ( struct V_75 const * V_86 , struct V_75 * V_87 )
{
struct V_62 * V_63 , * V_74 ;
F_52 ( V_87 ) ;
F_41 (entry, from, node) {
V_74 = F_38 ( V_63 ) ;
if ( V_74 == NULL )
goto V_88;
F_44 ( & V_74 -> V_78 , V_87 ) ;
}
return 0 ;
V_88:
F_50 ( V_87 ) ;
return - V_8 ;
}
static V_25 F_54 ( V_25 V_26 )
{
if ( V_26 == V_42 )
return 2 ;
if ( V_26 == V_40 )
return 6 ;
return 0 ;
}
static V_25 F_55 ( V_25 V_26 , T_1 V_52 )
{
switch ( V_26 ) {
case V_42 :
return V_52 <= V_89 ;
case V_40 :
return V_52 >= V_90 && V_52 <= V_91 ;
}
return 0 ;
}
static V_25 F_56 ( V_25 V_26 , V_25 V_52 )
{
switch ( V_26 ) {
case V_38 :
return V_52 == V_92 || V_52 == V_93 ;
case V_39 :
case V_41 :
case V_43 :
case V_44 :
case V_28 :
case V_29 :
return V_52 < 2 ;
case V_45 :
return V_52 < 16 ;
}
return 0 ;
}
static V_25 F_57 ( V_25 V_26 , V_25 const * V_94 , V_25 V_95 )
{
if ( V_94 == NULL || V_95 < 1 )
return 0 ;
while ( V_95 -- )
if ( ! F_56 ( V_26 , * V_94 ++ ) )
return 0 ;
return 1 ;
}
int F_58 ( struct V_5 * V_6 , struct V_96 * V_97 ,
struct V_98 * V_99 )
{
struct V_75 * V_100 = V_97 ? & V_97 -> V_101 : & V_6 -> V_102 ;
struct V_62 * V_103 , * V_85 ;
V_25 V_47 , type , V_57 , * V_104 , V_105 [ V_106 ] ;
bool V_107 ;
F_59 (pos, next, fn, node) {
V_47 = F_60 ( V_103 ) ;
type = F_18 ( V_103 -> V_26 ) ;
V_107 = false ;
if ( V_103 -> V_81 ) {
V_57 = 0 ;
V_104 = NULL ;
} else {
if ( type == V_54 ) {
V_57 = V_103 -> V_52 . V_55 . V_57 ;
V_104 = V_103 -> V_52 . V_55 . V_56 ;
V_107 = V_103 -> V_67 ;
} else if ( type == V_58 ) {
V_57 = F_54 ( V_103 -> V_26 ) ;
V_104 = V_105 ;
F_61 ( V_103 -> V_52 . V_59 , V_104 , V_57 ) ;
} else {
F_62 ( L_34 , V_103 -> V_26 ) ;
return - 1 ;
}
}
F_63 ( V_47 , V_103 -> V_26 , V_104 , V_57 , 0 ) ;
if ( F_64 ( V_99 , V_47 , V_103 -> V_26 , V_104 , V_57 , V_107 ) )
return - 1 ;
if ( V_103 -> V_82 && F_65 ( V_99 ) )
return - 1 ;
if ( V_99 -> V_2 -> V_108 == V_109 &&
( V_47 == V_51 || V_47 == V_49 ) ) {
F_48 ( V_103 ) ;
} else {
if ( V_103 -> V_66 == V_80 )
V_103 -> V_66 = V_110 ;
}
}
return 0 ;
}
static int F_66 ( struct V_75 * V_100 , V_25 V_36 ,
V_25 V_79 , T_1 V_111 )
{
T_2 V_61 = { . V_59 = V_111 } ;
if ( F_18 ( V_36 ) != V_58 ||
! F_55 ( V_36 , V_111 ) )
return - V_112 ;
if ( V_111 - ( T_1 ) F_19 ( V_36 ) == 0 )
return 0 ;
return F_45 ( V_100 , V_36 , 1 , V_79 , & V_61 ) ;
}
static int F_67 ( struct V_75 * V_100 , V_25 V_36 , V_25 V_64 ,
V_25 V_79 , V_25 const * V_113 , V_25 V_95 )
{
T_2 V_61 ;
if ( F_18 ( V_36 ) != V_54 ||
! F_57 ( V_36 , V_113 , V_95 ) )
return - V_112 ;
if ( V_36 == V_38 && ! F_68 ( V_113 , V_95 ) )
return - V_114 ;
if ( F_33 ( & V_61 , V_113 , V_95 ) )
return - V_8 ;
return F_45 ( V_100 , V_36 , V_64 , V_79 , & V_61 ) ;
}
int F_69 ( struct V_1 * V_2 , V_25 V_36 , V_25 V_64 ,
V_25 const * V_60 , V_25 V_57 )
{
if ( V_2 -> V_108 != V_115 )
return - V_116 ;
if ( F_18 ( V_36 ) != V_54 )
return - V_112 ;
return F_67 ( & F_2 ( V_2 ) -> V_102 , V_36 , V_64 ,
0 , V_60 , V_57 ) ;
}
T_1 F_70 ( struct V_1 * V_2 , V_25 V_36 )
{
if ( F_18 ( V_36 ) == V_58 ) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_62 * V_63 ;
V_63 = F_40 ( & V_6 -> V_102 , V_36 , 1 ) ;
if ( V_63 != NULL )
return V_63 -> V_52 . V_59 ;
switch ( V_36 ) {
case V_42 :
return V_6 -> V_18 ;
case V_40 :
return V_6 -> V_14 ;
}
}
F_62 ( L_35 , V_36 ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 , V_25 V_36 , T_1 V_111 )
{
struct V_75 * V_100 = & F_2 ( V_2 ) -> V_102 ;
T_2 V_61 = { . V_59 = V_111 } ;
struct V_62 * V_63 ;
if ( V_2 -> V_108 != V_109 && V_2 -> V_108 != V_117 )
return 0 ;
if ( F_18 ( V_36 ) != V_58 ||
! F_55 ( V_36 , V_111 ) )
return - V_112 ;
if ( V_111 == F_70 ( V_2 , V_36 ) )
return 0 ;
V_63 = F_40 ( V_100 , V_36 , 1 ) ;
if ( V_63 != NULL ) {
F_72 ( L_36 ,
( unsigned long long ) V_63 -> V_52 . V_59 ,
( unsigned long long ) V_111 ) ;
F_48 ( V_63 ) ;
}
F_73 ( V_2 ) ;
return F_45 ( V_100 , V_36 , 1 , 0 , & V_61 ) ;
}
static const struct V_118 * F_74 ( V_25 V_3 , bool V_64 )
{
static const struct V_118 V_119 [ 2 ] [ 2 ] = {
{
{
. V_120 = V_43 ,
. V_64 = true ,
. V_121 = true ,
. V_52 = 1
} ,
{ 0 , 0 , 0 , 0 }
} ,
{
{
. V_120 = V_43 ,
. V_64 = false ,
. V_121 = true ,
. V_52 = 1
} ,
{ 0 , 0 , 0 , 0 }
}
} ;
static const struct V_118 V_122 [ 2 ] [ 5 ] = {
{
{
. V_120 = V_43 ,
. V_64 = true ,
. V_121 = false ,
. V_52 = 0
} ,
{
. V_120 = V_29 ,
. V_64 = true ,
. V_121 = true ,
. V_52 = 1
} ,
{
. V_120 = V_44 ,
. V_64 = false ,
. V_121 = true ,
. V_52 = 1
} ,
{ 0 , 0 , 0 , 0 } ,
} ,
{
{
. V_120 = V_43 ,
. V_64 = false ,
. V_121 = false ,
. V_52 = 0
} ,
{
. V_120 = V_29 ,
. V_64 = false ,
. V_121 = true ,
. V_52 = 1
} ,
{
. V_120 = V_42 ,
. V_64 = true ,
. V_121 = false ,
. V_52 = 0
} ,
{
. V_120 = V_44 ,
. V_64 = true ,
. V_121 = false ,
. V_52 = 1
} ,
{ 0 , 0 , 0 , 0 }
}
} ;
switch ( V_3 ) {
case V_92 :
return V_119 [ V_64 ] ;
case V_93 :
return V_122 [ V_64 ] ;
default:
return NULL ;
}
}
static int F_75 ( struct V_75 * V_100 , V_25 V_123 , bool V_64 )
{
const struct V_118 * V_124 = F_74 ( V_123 , V_64 ) ;
int V_53 , V_125 = ( V_124 == NULL ) ;
for ( V_53 = 0 ; V_125 == 0 && V_124 [ V_53 ] . V_120 != V_27 ; V_53 ++ )
if ( F_18 ( V_124 [ V_53 ] . V_120 ) == V_54 )
V_125 = F_67 ( V_100 , V_124 [ V_53 ] . V_120 ,
V_124 [ V_53 ] . V_64 ,
V_124 [ V_53 ] . V_121 ,
& V_124 [ V_53 ] . V_52 , 1 ) ;
else
V_125 = F_66 ( V_100 , V_124 [ V_53 ] . V_120 ,
V_124 [ V_53 ] . V_121 ,
V_124 [ V_53 ] . V_52 ) ;
return V_125 ;
}
int F_76 ( struct V_5 * V_6 )
{
struct V_75 * V_100 = & V_6 -> V_102 ;
struct V_62 * V_63 ;
int V_53 = 2 , V_126 [ 2 ] = { - 1 , - 1 } ;
F_41 (entry, fn, node)
if ( V_63 -> V_26 == V_38 && V_63 -> V_52 . V_55 . V_57 == 1 )
V_126 [ V_63 -> V_64 ] = V_63 -> V_52 . V_55 . V_56 [ 0 ] ;
while ( V_53 -- )
if ( V_126 [ V_53 ] > 0 && F_75 ( V_100 , V_126 [ V_53 ] , V_53 ) )
return - 1 ;
F_77 ( V_100 ) ;
return 0 ;
}
int F_78 ( struct V_96 * V_97 )
{
struct V_75 * V_100 = & V_97 -> V_101 ;
struct V_62 * V_63 ;
V_25 V_64 , V_3 ;
for ( V_64 = 0 ; V_64 <= 1 ; V_64 ++ ) {
V_63 = F_40 ( V_100 , V_38 , V_64 ) ;
if ( V_63 != NULL && ! V_63 -> V_81 )
V_3 = V_63 -> V_52 . V_55 . V_56 [ 0 ] ;
else
V_3 = F_19 ( V_38 ) ;
if ( F_75 ( V_100 , V_3 , V_64 ) )
return - 1 ;
}
return 0 ;
}
static int F_79 ( V_25 * V_127 , V_25 V_128 , V_25 * V_129 , V_25 V_130 )
{
V_25 V_131 , V_132 ;
for ( V_132 = 0 ; V_132 < V_128 ; V_132 ++ )
for ( V_131 = 0 ; V_131 < V_130 ; V_131 ++ )
if ( V_127 [ V_132 ] == V_129 [ V_131 ] )
return V_127 [ V_132 ] ;
return - 1 ;
}
static V_25 F_80 ( V_25 V_133 , V_25 * V_134 , V_25 V_135 )
{
V_25 V_53 , V_136 = 0 ;
if ( V_134 != NULL ) {
for ( V_53 = 0 ; V_53 < V_135 ; V_53 ++ )
if ( V_134 [ V_53 ] == V_133 ) {
V_134 [ V_53 ] = V_134 [ 0 ] ;
V_136 ++ ;
}
if ( V_136 )
V_134 [ 0 ] = V_133 ;
}
return V_136 ;
}
static int F_81 ( T_2 * V_137 , V_25 * V_138 , V_25 V_57 ,
bool V_139 , bool V_140 )
{
int V_125 ;
if ( ! V_137 -> V_55 . V_56 || ! V_138 ) {
F_30 ( L_37 ) ;
return 0 ;
}
if ( V_139 )
V_125 = F_79 ( V_137 -> V_55 . V_56 , V_137 -> V_55 . V_57 , V_138 , V_57 ) ;
else
V_125 = F_79 ( V_138 , V_57 , V_137 -> V_55 . V_56 , V_137 -> V_55 . V_57 ) ;
if ( ! V_140 )
return V_125 ;
if ( V_125 < 0 )
return 0 ;
return F_80 ( V_125 , V_137 -> V_55 . V_56 , V_137 -> V_55 . V_57 ) ;
}
static V_25 F_82 ( struct V_75 * V_100 , V_25 V_121 , V_25 V_47 ,
V_25 V_36 , V_25 * V_52 , V_25 V_57 , const bool V_141 )
{
V_25 V_142 , type = F_18 ( V_36 ) ;
const bool V_71 = ( V_47 == V_50 ) ;
struct V_62 * V_63 ;
T_2 V_61 ;
if ( V_57 == 0 || type == V_32 )
goto V_143;
F_63 ( V_47 , V_36 , V_52 , V_57 , V_121 ) ;
if ( type == V_58 ) {
if ( V_71 || V_57 > sizeof( V_61 . V_59 ) )
goto V_143;
V_61 . V_59 = F_26 ( V_52 , V_57 ) ;
if ( ! F_55 ( V_36 , V_61 . V_59 ) )
goto V_143;
return F_46 ( V_100 , V_36 , V_71 , & V_61 ) ;
}
V_63 = F_40 ( V_100 , V_36 , V_71 ) ;
if ( V_63 == NULL ) {
if ( F_33 ( & V_61 , V_52 , 1 ) )
return V_83 ;
if ( V_57 > 1 && V_141 ) {
V_142 = F_19 ( V_36 ) ;
if ( F_79 ( & V_142 , 1 , V_52 , V_57 ) > - 1 )
V_61 . V_55 . V_56 [ 0 ] = V_142 ;
} else if ( ! F_56 ( V_36 , V_61 . V_55 . V_56 [ 0 ] ) ) {
F_37 ( V_61 . V_55 . V_56 ) ;
goto V_143;
}
if ( V_36 == V_38 && ! F_68 ( V_61 . V_55 . V_56 , 1 ) ) {
F_37 ( V_61 . V_55 . V_56 ) ;
goto V_144;
}
return F_46 ( V_100 , V_36 , V_71 , & V_61 ) ;
} else if ( V_63 -> V_66 == V_145 ) {
return 0 ;
}
if ( F_81 ( & V_63 -> V_52 , V_52 , V_57 , V_141 , true ) ) {
V_63 -> V_81 = false ;
} else if ( V_121 ) {
return V_146 ;
} else if ( V_63 -> V_66 == V_80 ) {
F_83 ( ! V_141 ) ;
V_142 = F_19 ( V_36 ) ;
if ( ! F_81 ( & V_63 -> V_52 , & V_142 , 1 , V_141 , true ) )
return V_147 ;
V_63 -> V_81 = true ;
}
V_63 -> V_67 = true ;
V_63 -> V_82 = false ;
V_63 -> V_66 = V_84 ;
return 0 ;
V_143:
if ( ! V_121 )
return F_47 ( V_100 , V_36 , V_71 ) ;
V_144:
return V_121 ? V_146
: V_147 ;
}
static V_25 F_84 ( struct V_75 * V_100 , V_25 V_121 , V_25 V_47 ,
V_25 V_36 , V_25 * V_52 , V_25 V_57 , const bool V_141 )
{
V_25 * V_148 , V_149 , type = F_18 ( V_36 ) ;
const bool V_71 = ( V_47 == V_51 ) ;
struct V_62 * V_63 = F_40 ( V_100 , V_36 , V_71 ) ;
F_63 ( V_47 , V_36 , V_52 , V_57 , V_121 ) ;
if ( V_63 == NULL ) {
if ( V_121 && type == V_32 )
return V_146 ;
if ( ! V_71 && type == V_58 )
goto V_150;
return 0 ;
}
if ( V_63 -> V_66 != V_110 )
return 0 ;
if ( V_57 == 0 ) {
if ( F_32 ( V_36 ) )
goto V_150;
F_48 ( V_63 ) ;
return 0 ;
}
if ( type == V_58 ) {
if ( V_57 > sizeof( V_63 -> V_52 . V_59 ) )
goto V_150;
if ( V_63 -> V_52 . V_59 == F_26 ( V_52 , V_57 ) )
goto V_151;
F_16 ( L_38 ) ;
goto V_150;
}
if ( ! F_56 ( V_36 , * V_52 ) )
goto V_150;
if ( V_57 == 1 ) {
V_148 = V_52 ;
V_149 = V_57 ;
} else {
V_148 = V_52 + 1 ;
V_149 = V_57 - 1 ;
}
if ( F_81 ( & V_63 -> V_52 , V_148 , V_149 , V_141 , 0 ) != * V_52 ) {
F_16 ( L_39 , * V_52 ) ;
return V_147 ;
}
V_63 -> V_52 . V_55 . V_56 [ 0 ] = * V_52 ;
V_151:
V_63 -> V_66 = V_84 ;
return 0 ;
V_150:
F_16 ( L_40 ) ;
return V_121 ? V_146
: V_147 ;
}
static V_25 F_85 ( struct V_1 * V_2 , V_25 V_79 , V_25 V_47 ,
V_25 V_36 , V_25 * V_52 , V_25 V_57 )
{
struct V_75 * V_100 = & F_2 ( V_2 ) -> V_102 ;
const bool V_71 = ( V_47 == V_51 ) ;
struct V_62 * V_63 ;
V_25 type = F_18 ( V_36 ) ;
T_2 V_61 ;
F_63 ( V_47 , V_36 , V_52 , V_57 , V_79 ) ;
if ( type == V_32 ) {
if ( V_71 && ! V_79 )
return 0 ;
goto V_152;
} else if ( type != V_58 ) {
return 0 ;
}
if ( V_57 == 0 || V_57 > sizeof( V_61 . V_59 ) )
goto V_152;
if ( V_47 == V_48 ) {
V_61 . V_59 = F_26 ( V_52 , V_57 ) ;
if ( ! F_55 ( V_36 , V_61 . V_59 ) )
goto V_152;
if ( F_46 ( V_100 , V_36 , V_71 , & V_61 ) ||
F_31 ( V_2 , V_36 , V_71 , & V_61 ) )
return V_83 ;
F_73 ( V_2 ) ;
} else if ( V_47 == V_51 ) {
V_63 = F_40 ( V_100 , V_36 , V_71 ) ;
if ( V_63 == NULL || V_63 -> V_66 != V_110 )
return 0 ;
V_61 . V_59 = F_26 ( V_52 , V_57 ) ;
if ( V_61 . V_59 != V_63 -> V_52 . V_59 )
return 0 ;
F_31 ( V_2 , V_36 , V_71 , & V_61 ) ;
F_48 ( V_63 ) ;
} else {
F_16 ( L_41 , V_47 ) ;
goto V_153;
}
return 0 ;
V_152:
if ( ! V_79 )
return F_47 ( V_100 , V_36 , V_71 ) ;
V_153:
return V_79 ? V_146
: V_147 ;
}
int F_86 ( struct V_1 * V_2 , struct V_96 * V_97 ,
V_25 V_79 , V_25 V_47 , V_25 V_36 , V_25 * V_52 , V_25 V_57 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_75 * V_100 = V_97 ? & V_97 -> V_101 : & V_6 -> V_102 ;
bool V_141 = false ;
switch ( V_2 -> V_108 ) {
case V_154 :
V_141 = true ;
case V_155 :
switch ( V_47 ) {
case V_48 :
case V_50 :
return F_82 ( V_100 , V_79 , V_47 , V_36 ,
V_52 , V_57 , V_141 ) ;
case V_51 :
case V_49 :
return F_84 ( V_100 , V_79 , V_47 , V_36 ,
V_52 , V_57 , V_141 ) ;
}
break;
case V_109 :
case V_117 :
return F_85 ( V_2 , V_79 , V_47 , V_36 ,
V_52 , V_57 ) ;
}
return 0 ;
}
int F_87 ( struct V_1 * V_2 )
{
struct V_75 * V_100 = & F_2 ( V_2 ) -> V_102 ;
V_25 V_156 = 1 , V_157 = 0 ;
int V_125 ;
struct {
V_25 * V_52 ;
V_25 V_57 ;
} V_158 , V_4 ;
V_125 = F_66 ( V_100 , V_40 , 0 ,
V_159 ) ;
if ( V_125 )
return V_125 ;
V_125 = F_67 ( V_100 , V_39 , true , true , & V_157 , 1 ) ;
if ( V_125 )
return V_125 ;
V_125 = F_67 ( V_100 , V_41 , true , true , & V_156 , 1 ) ;
if ( V_125 )
return V_125 ;
if ( F_88 ( & V_158 . V_52 , & V_158 . V_57 ) ||
F_88 ( & V_4 . V_52 , & V_4 . V_57 ) )
return - V_72 ;
if ( ! F_80 ( V_160 , V_158 . V_52 , V_158 . V_57 ) ||
! F_80 ( V_161 , V_4 . V_52 , V_4 . V_57 ) )
goto V_162;
V_125 = F_67 ( V_100 , V_38 , true , false , V_158 . V_52 , V_158 . V_57 ) ;
if ( V_125 )
goto V_162;
V_125 = F_67 ( V_100 , V_38 , false , false , V_4 . V_52 , V_4 . V_57 ) ;
V_162:
F_37 ( V_158 . V_52 ) ;
F_37 ( V_4 . V_52 ) ;
return V_125 ;
}
int F_89 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_62 * V_163 , * V_85 ;
int V_31 ;
T_2 * V_164 [ V_30 ] [ 2 ] = {
[ 0 ... V_30 - 1 ] = { NULL , NULL }
} ;
F_41 (cur, fn_list, node) {
if ( V_163 -> V_81 )
continue;
V_31 = F_17 ( V_163 -> V_26 ) ;
if ( V_31 < 0 ) {
F_62 ( L_42 , V_163 -> V_26 ) ;
goto V_165;
}
if ( V_163 -> V_66 != V_84 ) {
F_30 ( L_43 ,
V_163 -> V_64 ? L_25 : L_26 ,
F_21 ( V_163 -> V_26 ) ,
V_65 [ V_163 -> V_66 ] ) ;
goto V_165;
}
V_164 [ V_31 ] [ V_163 -> V_64 ] = & V_163 -> V_52 ;
}
for ( V_31 = V_30 ; -- V_31 >= 0 ; )
if ( F_29 ( V_2 , V_31 , 0 , V_164 [ V_31 ] [ 0 ] ) ||
F_29 ( V_2 , V_31 , 1 , V_164 [ V_31 ] [ 1 ] ) ) {
F_30 ( L_44 , V_31 ) ;
goto V_165;
}
F_51 (cur, next, fn_list, node)
if ( ! V_163 -> V_67 )
F_48 ( V_163 ) ;
F_72 ( L_45 ) ;
return 0 ;
V_165:
F_4 ( V_6 -> V_9 , V_2 ) ;
F_5 ( V_6 -> V_10 , V_2 ) ;
V_6 -> V_9 = V_6 -> V_10 = NULL ;
F_13 ( V_6 -> V_20 ) ;
V_6 -> V_20 = NULL ;
return - 1 ;
}
