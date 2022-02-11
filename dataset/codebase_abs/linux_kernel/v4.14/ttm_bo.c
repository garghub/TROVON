static inline int F_1 ( const struct V_1 * V_2 ,
T_1 * V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 & V_6 ) ;
if ( F_3 ( ! V_4 ) )
return - V_7 ;
* V_3 = V_4 - 1 ;
return 0 ;
}
static void F_4 ( struct V_8 * V_9 , int V_3 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
struct V_12 V_13 = F_5 ( V_14 ) ;
F_6 ( L_1 , V_11 -> V_15 ) ;
F_6 ( L_2 , V_11 -> V_16 ) ;
F_6 ( L_3 , V_11 -> V_5 ) ;
F_6 ( L_4 , V_11 -> V_17 ) ;
F_6 ( L_5 , V_11 -> V_18 ) ;
F_6 ( L_6 , V_11 -> V_19 ) ;
F_6 ( L_7 , V_11 -> V_20 ) ;
if ( V_3 != V_21 )
(* V_11 -> V_22 -> V_23 )( V_11 , & V_13 ) ;
}
static void F_7 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
int V_28 , V_29 , V_3 ;
F_6 ( L_8 ,
V_25 , V_25 -> V_30 . V_31 , V_25 -> V_30 . V_18 >> 10 ,
V_25 -> V_30 . V_18 >> 20 ) ;
for ( V_28 = 0 ; V_28 < V_27 -> V_32 ; V_28 ++ ) {
V_29 = F_1 ( & V_27 -> V_27 [ V_28 ] ,
& V_3 ) ;
if ( V_29 )
return;
F_6 ( L_9 ,
V_28 , V_27 -> V_27 [ V_28 ] . V_5 , V_3 ) ;
F_4 ( V_25 -> V_9 , V_3 ) ;
}
}
static T_2 F_8 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_38 * V_39 =
F_9 ( V_34 , struct V_38 , V_34 ) ;
return snprintf ( V_37 , V_40 , L_10 ,
F_10 ( & V_39 -> V_41 ) ) ;
}
static inline T_1 F_11 ( unsigned type )
{
return 1 << ( type ) ;
}
static void F_12 ( struct V_42 * V_43 )
{
struct V_24 * V_25 =
F_9 ( V_43 , struct V_24 , V_43 ) ;
struct V_8 * V_9 = V_25 -> V_9 ;
T_3 V_44 = V_25 -> V_44 ;
F_13 ( F_14 ( & V_25 -> V_43 ) ) ;
F_13 ( F_14 ( & V_25 -> V_42 ) ) ;
F_13 ( F_10 ( & V_25 -> V_45 ) ) ;
F_13 ( V_25 -> V_30 . V_46 != NULL ) ;
F_13 ( ! F_15 ( & V_25 -> V_47 ) ) ;
F_13 ( ! F_15 ( & V_25 -> V_48 ) ) ;
F_16 ( V_25 -> V_49 ) ;
F_17 ( & V_25 -> V_39 -> V_41 ) ;
F_18 ( V_25 -> V_50 ) ;
if ( V_25 -> V_51 == & V_25 -> V_52 )
F_19 ( & V_25 -> V_52 ) ;
F_20 ( & V_25 -> V_53 ) ;
if ( V_25 -> V_54 )
V_25 -> V_54 ( V_25 ) ;
else {
F_21 ( V_25 ) ;
}
F_22 ( V_9 -> V_39 -> V_55 , V_44 ) ;
}
void F_23 ( struct V_24 * V_25 )
{
struct V_8 * V_9 = V_25 -> V_9 ;
struct V_10 * V_11 ;
F_24 ( & V_25 -> V_51 -> V_56 . V_57 ) ;
if ( ! ( V_25 -> V_30 . V_27 & V_58 ) ) {
F_13 ( ! F_15 ( & V_25 -> V_47 ) ) ;
V_11 = & V_9 -> V_11 [ V_25 -> V_30 . V_3 ] ;
F_25 ( & V_25 -> V_47 , & V_11 -> V_47 [ V_25 -> V_59 ] ) ;
F_26 ( & V_25 -> V_43 ) ;
if ( V_25 -> V_49 && ! ( V_25 -> V_49 -> V_60 & V_61 ) ) {
F_25 ( & V_25 -> V_62 ,
& V_25 -> V_39 -> V_63 [ V_25 -> V_59 ] ) ;
F_26 ( & V_25 -> V_43 ) ;
}
}
}
static void F_27 ( struct V_42 * V_43 )
{
F_28 () ;
}
void F_29 ( struct V_24 * V_25 )
{
if ( ! F_15 ( & V_25 -> V_62 ) ) {
F_30 ( & V_25 -> V_62 ) ;
F_31 ( & V_25 -> V_43 , F_27 ) ;
}
if ( ! F_15 ( & V_25 -> V_47 ) ) {
F_30 ( & V_25 -> V_47 ) ;
F_31 ( & V_25 -> V_43 , F_27 ) ;
}
}
void F_32 ( struct V_24 * V_25 )
{
F_33 ( & V_25 -> V_39 -> V_64 ) ;
F_29 ( V_25 ) ;
F_34 ( & V_25 -> V_39 -> V_64 ) ;
}
void F_35 ( struct V_24 * V_25 )
{
F_24 ( & V_25 -> V_51 -> V_56 . V_57 ) ;
F_29 ( V_25 ) ;
F_23 ( V_25 ) ;
}
static int F_36 ( struct V_24 * V_25 , bool V_65 )
{
struct V_8 * V_9 = V_25 -> V_9 ;
struct V_38 * V_39 = V_25 -> V_39 ;
int V_29 = 0 ;
T_1 V_60 = 0 ;
F_37 ( & V_25 -> V_66 ) ;
V_25 -> V_49 = NULL ;
if ( V_9 -> V_67 )
V_60 |= V_68 ;
switch ( V_25 -> type ) {
case V_69 :
if ( V_65 )
V_60 |= V_70 ;
case V_71 :
V_25 -> V_49 = V_9 -> V_72 -> V_73 ( V_9 , V_25 -> V_31 << V_74 ,
V_60 , V_39 -> V_75 ) ;
if ( F_3 ( V_25 -> V_49 == NULL ) )
V_29 = - V_76 ;
break;
case V_77 :
V_25 -> V_49 = V_9 -> V_72 -> V_73 ( V_9 , V_25 -> V_31 << V_74 ,
V_60 | V_61 ,
V_39 -> V_75 ) ;
if ( F_3 ( V_25 -> V_49 == NULL ) ) {
V_29 = - V_76 ;
break;
}
V_25 -> V_49 -> V_78 = V_25 -> V_78 ;
break;
default:
F_6 ( L_11 ) ;
V_29 = - V_7 ;
break;
}
return V_29 ;
}
static int F_38 ( struct V_24 * V_25 ,
struct V_79 * V_30 ,
bool V_80 , bool V_81 ,
bool V_82 )
{
struct V_8 * V_9 = V_25 -> V_9 ;
bool V_83 = F_39 ( V_9 , & V_25 -> V_30 ) ;
bool V_84 = F_39 ( V_9 , V_30 ) ;
struct V_10 * V_85 = & V_9 -> V_11 [ V_25 -> V_30 . V_3 ] ;
struct V_10 * V_86 = & V_9 -> V_11 [ V_30 -> V_3 ] ;
int V_29 = 0 ;
if ( V_83 || V_84 ||
( ( V_30 -> V_27 & V_25 -> V_30 . V_27 & V_87 ) == 0 ) ) {
V_29 = F_40 ( V_85 , true ) ;
if ( F_3 ( V_29 != 0 ) )
goto V_88;
F_41 ( V_25 ) ;
F_42 ( V_85 ) ;
}
if ( ! ( V_86 -> V_5 & V_89 ) ) {
if ( V_25 -> V_49 == NULL ) {
bool V_90 = ! ( V_85 -> V_5 & V_89 ) ;
V_29 = F_36 ( V_25 , V_90 ) ;
if ( V_29 )
goto V_88;
}
V_29 = F_43 ( V_25 -> V_49 , V_30 -> V_27 ) ;
if ( V_29 )
goto V_88;
if ( V_30 -> V_3 != V_21 ) {
V_29 = F_44 ( V_25 -> V_49 , V_30 ) ;
if ( V_29 )
goto V_88;
}
if ( V_25 -> V_30 . V_3 == V_21 ) {
if ( V_9 -> V_72 -> V_91 )
V_9 -> V_72 -> V_91 ( V_25 , V_80 , V_30 ) ;
V_25 -> V_30 = * V_30 ;
V_30 -> V_46 = NULL ;
goto V_92;
}
}
if ( V_9 -> V_72 -> V_91 )
V_9 -> V_72 -> V_91 ( V_25 , V_80 , V_30 ) ;
if ( ! ( V_85 -> V_5 & V_89 ) &&
! ( V_86 -> V_5 & V_89 ) )
V_29 = F_45 ( V_25 , V_81 , V_82 , V_30 ) ;
else if ( V_9 -> V_72 -> V_93 )
V_29 = V_9 -> V_72 -> V_93 ( V_25 , V_80 , V_81 ,
V_82 , V_30 ) ;
else
V_29 = F_46 ( V_25 , V_81 , V_82 , V_30 ) ;
if ( V_29 ) {
if ( V_9 -> V_72 -> V_91 ) {
struct V_79 V_94 = * V_30 ;
* V_30 = V_25 -> V_30 ;
V_25 -> V_30 = V_94 ;
V_9 -> V_72 -> V_91 ( V_25 , false , V_30 ) ;
V_25 -> V_30 = * V_30 ;
* V_30 = V_94 ;
}
goto V_88;
}
V_92:
if ( V_25 -> V_95 ) {
if ( V_9 -> V_72 -> V_96 ) {
V_29 = V_9 -> V_72 -> V_96 ( V_9 , V_25 -> V_30 . V_27 ) ;
if ( V_29 )
F_6 ( L_12 ) ;
}
V_25 -> V_95 = false ;
}
if ( V_25 -> V_30 . V_46 ) {
V_25 -> V_97 = ( V_25 -> V_30 . V_98 << V_74 ) +
V_9 -> V_11 [ V_25 -> V_30 . V_3 ] . V_17 ;
V_25 -> V_99 = V_25 -> V_30 . V_27 ;
} else
V_25 -> V_97 = 0 ;
return 0 ;
V_88:
V_86 = & V_9 -> V_11 [ V_25 -> V_30 . V_3 ] ;
if ( V_86 -> V_5 & V_89 ) {
F_16 ( V_25 -> V_49 ) ;
V_25 -> V_49 = NULL ;
}
return V_29 ;
}
static void F_47 ( struct V_24 * V_25 )
{
if ( V_25 -> V_9 -> V_72 -> V_91 )
V_25 -> V_9 -> V_72 -> V_91 ( V_25 , false , NULL ) ;
F_16 ( V_25 -> V_49 ) ;
V_25 -> V_49 = NULL ;
F_48 ( V_25 , & V_25 -> V_30 ) ;
F_49 ( & V_25 -> V_51 -> V_56 ) ;
}
static int F_50 ( struct V_24 * V_25 )
{
int V_100 ;
if ( V_25 -> V_51 == & V_25 -> V_52 )
return 0 ;
F_51 ( & V_25 -> V_52 ) ;
F_13 ( ! F_52 ( & V_25 -> V_52 ) ) ;
V_100 = F_53 ( & V_25 -> V_52 , V_25 -> V_51 ) ;
if ( V_100 ) {
F_54 ( & V_25 -> V_52 ) ;
F_19 ( & V_25 -> V_52 ) ;
}
return V_100 ;
}
static void F_55 ( struct V_24 * V_25 )
{
struct V_101 * V_102 ;
struct V_103 * V_104 ;
int V_28 ;
V_102 = F_56 ( & V_25 -> V_52 ) ;
V_104 = F_57 ( & V_25 -> V_52 ) ;
if ( V_104 && ! V_104 -> V_105 -> V_106 )
F_58 ( V_104 ) ;
for ( V_28 = 0 ; V_102 && V_28 < V_102 -> V_107 ; ++ V_28 ) {
V_104 = F_59 ( V_102 -> V_108 [ V_28 ] ,
F_60 ( V_25 -> V_51 ) ) ;
if ( ! V_104 -> V_105 -> V_106 )
F_58 ( V_104 ) ;
}
}
static void F_61 ( struct V_24 * V_25 )
{
struct V_8 * V_9 = V_25 -> V_9 ;
struct V_38 * V_39 = V_25 -> V_39 ;
int V_29 ;
F_33 ( & V_39 -> V_64 ) ;
V_29 = F_62 ( V_25 , false , true , NULL ) ;
if ( ! V_29 ) {
if ( ! F_63 ( V_25 , false , true ) ) {
F_29 ( V_25 ) ;
F_34 ( & V_39 -> V_64 ) ;
F_47 ( V_25 ) ;
return;
}
V_29 = F_50 ( V_25 ) ;
if ( V_29 ) {
F_34 ( & V_39 -> V_64 ) ;
F_63 ( V_25 , true , true ) ;
F_47 ( V_25 ) ;
return;
}
F_55 ( V_25 ) ;
if ( V_25 -> V_30 . V_27 & V_58 ) {
V_25 -> V_30 . V_27 &= ~ V_58 ;
F_23 ( V_25 ) ;
}
if ( V_25 -> V_51 != & V_25 -> V_52 )
F_54 ( & V_25 -> V_52 ) ;
F_64 ( V_25 ) ;
}
F_26 ( & V_25 -> V_43 ) ;
F_25 ( & V_25 -> V_48 , & V_9 -> V_48 ) ;
F_34 ( & V_39 -> V_64 ) ;
F_65 ( & V_9 -> V_109 ,
( ( V_110 / 100 ) < 1 ) ? 1 : V_110 / 100 ) ;
}
static int F_66 ( struct V_24 * V_25 ,
bool V_81 ,
bool V_82 )
{
struct V_38 * V_39 = V_25 -> V_39 ;
struct V_111 * V_51 ;
int V_29 ;
if ( F_3 ( F_15 ( & V_25 -> V_48 ) ) )
V_51 = V_25 -> V_51 ;
else
V_51 = & V_25 -> V_52 ;
if ( F_67 ( V_51 , true ) )
V_29 = 0 ;
else
V_29 = - V_112 ;
if ( V_29 && ! V_82 ) {
long V_113 ;
F_49 ( & V_25 -> V_51 -> V_56 ) ;
F_34 ( & V_39 -> V_64 ) ;
V_113 = F_68 ( V_51 , true ,
V_81 ,
30 * V_110 ) ;
if ( V_113 < 0 )
return V_113 ;
else if ( V_113 == 0 )
return - V_112 ;
F_33 ( & V_39 -> V_64 ) ;
V_29 = F_62 ( V_25 , false , true , NULL ) ;
if ( V_29 ) {
F_34 ( & V_39 -> V_64 ) ;
return 0 ;
}
}
if ( V_29 || F_3 ( F_15 ( & V_25 -> V_48 ) ) ) {
F_64 ( V_25 ) ;
F_34 ( & V_39 -> V_64 ) ;
return V_29 ;
}
F_29 ( V_25 ) ;
F_30 ( & V_25 -> V_48 ) ;
F_31 ( & V_25 -> V_43 , F_27 ) ;
F_34 ( & V_39 -> V_64 ) ;
F_47 ( V_25 ) ;
return 0 ;
}
static int F_69 ( struct V_8 * V_9 , bool V_114 )
{
struct V_38 * V_39 = V_9 -> V_39 ;
struct V_24 * V_115 = NULL ;
int V_29 = 0 ;
F_33 ( & V_39 -> V_64 ) ;
if ( F_15 ( & V_9 -> V_48 ) )
goto V_116;
V_115 = F_70 ( & V_9 -> V_48 ,
struct V_24 , V_48 ) ;
F_26 ( & V_115 -> V_43 ) ;
for (; ; ) {
struct V_24 * V_117 = NULL ;
if ( V_115 -> V_48 . V_118 != & V_9 -> V_48 ) {
V_117 = F_70 ( & V_115 -> V_48 ,
struct V_24 , V_48 ) ;
F_26 ( & V_117 -> V_43 ) ;
}
V_29 = F_62 ( V_115 , false , true , NULL ) ;
if ( V_114 && V_29 ) {
F_34 ( & V_39 -> V_64 ) ;
V_29 = F_62 ( V_115 , false , false , NULL ) ;
F_33 ( & V_39 -> V_64 ) ;
}
if ( ! V_29 )
V_29 = F_66 ( V_115 , false ,
! V_114 ) ;
else
F_34 ( & V_39 -> V_64 ) ;
F_31 ( & V_115 -> V_43 , F_12 ) ;
V_115 = V_117 ;
if ( V_29 || ! V_115 )
goto V_119;
F_33 ( & V_39 -> V_64 ) ;
if ( F_15 ( & V_115 -> V_48 ) )
break;
}
V_116:
F_34 ( & V_39 -> V_64 ) ;
V_119:
if ( V_115 )
F_31 ( & V_115 -> V_43 , F_12 ) ;
return V_29 ;
}
static void F_71 ( struct V_120 * V_121 )
{
struct V_8 * V_9 =
F_9 ( V_121 , struct V_8 , V_109 . V_121 ) ;
if ( F_69 ( V_9 , false ) ) {
F_65 ( & V_9 -> V_109 ,
( ( V_110 / 100 ) < 1 ) ? 1 : V_110 / 100 ) ;
}
}
static void F_72 ( struct V_42 * V_42 )
{
struct V_24 * V_25 =
F_9 ( V_42 , struct V_24 , V_42 ) ;
struct V_8 * V_9 = V_25 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_25 -> V_30 . V_3 ] ;
F_73 ( & V_9 -> V_122 , & V_25 -> V_123 ) ;
F_40 ( V_11 , false ) ;
F_74 ( V_25 ) ;
F_42 ( V_11 ) ;
F_61 ( V_25 ) ;
F_31 ( & V_25 -> V_43 , F_12 ) ;
}
void F_75 ( struct V_24 * * V_124 )
{
struct V_24 * V_25 = * V_124 ;
* V_124 = NULL ;
F_31 ( & V_25 -> V_42 , F_72 ) ;
}
int F_76 ( struct V_8 * V_9 )
{
return F_77 ( & V_9 -> V_109 ) ;
}
void F_78 ( struct V_8 * V_9 , int V_125 )
{
if ( V_125 )
F_65 ( & V_9 -> V_109 ,
( ( V_110 / 100 ) < 1 ) ? 1 : V_110 / 100 ) ;
}
static int F_79 ( struct V_24 * V_25 , bool V_81 ,
bool V_82 )
{
struct V_8 * V_9 = V_25 -> V_9 ;
struct V_79 V_126 ;
struct V_26 V_27 ;
int V_29 = 0 ;
F_24 ( & V_25 -> V_51 -> V_56 . V_57 ) ;
V_126 = V_25 -> V_30 ;
V_126 . V_46 = NULL ;
V_126 . V_127 . V_128 = false ;
V_126 . V_127 . V_129 = 0 ;
V_27 . V_32 = 0 ;
V_27 . V_130 = 0 ;
V_9 -> V_72 -> V_131 ( V_25 , & V_27 ) ;
V_29 = F_80 ( V_25 , & V_27 , & V_126 , V_81 ,
V_82 ) ;
if ( V_29 ) {
if ( V_29 != - V_132 ) {
F_6 ( L_13 ,
V_25 ) ;
F_7 ( V_25 , & V_27 ) ;
}
goto V_119;
}
V_29 = F_38 ( V_25 , & V_126 , true , V_81 ,
V_82 ) ;
if ( F_3 ( V_29 ) ) {
if ( V_29 != - V_132 )
F_6 ( L_14 ) ;
F_48 ( V_25 , & V_126 ) ;
goto V_119;
}
V_25 -> V_95 = true ;
V_119:
return V_29 ;
}
bool F_81 ( struct V_24 * V_25 ,
const struct V_1 * V_2 )
{
if ( V_2 -> V_133 >= ( V_25 -> V_30 . V_98 + V_25 -> V_30 . V_18 ) ||
( V_2 -> V_134 && V_2 -> V_134 <= V_25 -> V_30 . V_98 ) )
return false ;
return true ;
}
static int F_82 ( struct V_8 * V_9 ,
T_1 V_3 ,
const struct V_1 * V_2 ,
bool V_81 ,
bool V_82 )
{
struct V_38 * V_39 = V_9 -> V_39 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
struct V_24 * V_25 ;
int V_29 = - V_112 ;
unsigned V_28 ;
F_33 ( & V_39 -> V_64 ) ;
for ( V_28 = 0 ; V_28 < V_135 ; ++ V_28 ) {
F_83 (bo, &man->lru[i], lru) {
V_29 = F_62 ( V_25 , false , true , NULL ) ;
if ( V_29 )
continue;
if ( V_2 && ! V_9 -> V_72 -> V_136 ( V_25 ,
V_2 ) ) {
F_64 ( V_25 ) ;
V_29 = - V_112 ;
continue;
}
break;
}
if ( ! V_29 )
break;
}
if ( V_29 ) {
F_34 ( & V_39 -> V_64 ) ;
return V_29 ;
}
F_26 ( & V_25 -> V_43 ) ;
if ( ! F_15 ( & V_25 -> V_48 ) ) {
V_29 = F_66 ( V_25 , V_81 ,
V_82 ) ;
F_31 ( & V_25 -> V_43 , F_12 ) ;
return V_29 ;
}
F_29 ( V_25 ) ;
F_34 ( & V_39 -> V_64 ) ;
F_13 ( V_29 != 0 ) ;
V_29 = F_79 ( V_25 , V_81 , V_82 ) ;
F_84 ( V_25 ) ;
F_31 ( & V_25 -> V_43 , F_12 ) ;
return V_29 ;
}
void F_48 ( struct V_24 * V_25 , struct V_79 * V_30 )
{
struct V_10 * V_11 = & V_25 -> V_9 -> V_11 [ V_30 -> V_3 ] ;
if ( V_30 -> V_46 )
(* V_11 -> V_22 -> V_137 )( V_11 , V_30 ) ;
}
static int F_85 ( struct V_24 * V_25 ,
struct V_10 * V_11 ,
struct V_79 * V_30 )
{
struct V_103 * V_104 ;
int V_29 ;
F_33 ( & V_11 -> V_138 ) ;
V_104 = F_86 ( V_11 -> V_93 ) ;
F_34 ( & V_11 -> V_138 ) ;
if ( V_104 ) {
F_87 ( V_25 -> V_51 , V_104 ) ;
V_29 = F_88 ( V_25 -> V_51 ) ;
if ( F_3 ( V_29 ) )
return V_29 ;
F_18 ( V_25 -> V_50 ) ;
V_25 -> V_50 = V_104 ;
}
return 0 ;
}
static int F_89 ( struct V_24 * V_25 ,
T_1 V_3 ,
const struct V_1 * V_2 ,
struct V_79 * V_30 ,
bool V_81 ,
bool V_82 )
{
struct V_8 * V_9 = V_25 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
int V_29 ;
do {
V_29 = (* V_11 -> V_22 -> V_139 )( V_11 , V_25 , V_2 , V_30 ) ;
if ( F_3 ( V_29 != 0 ) )
return V_29 ;
if ( V_30 -> V_46 )
break;
V_29 = F_82 ( V_9 , V_3 , V_2 ,
V_81 , V_82 ) ;
if ( F_3 ( V_29 != 0 ) )
return V_29 ;
} while ( 1 );
V_30 -> V_3 = V_3 ;
return F_85 ( V_25 , V_11 , V_30 ) ;
}
static T_1 F_90 ( struct V_10 * V_11 ,
T_1 V_99 ,
T_1 V_140 )
{
T_1 V_141 = V_140 & V_87 ;
T_1 V_142 = V_140 & ~ V_87 ;
if ( ( V_99 & V_141 ) != 0 )
V_142 |= ( V_99 & V_141 ) ;
else if ( ( V_11 -> V_20 & V_141 ) != 0 )
V_142 |= V_11 -> V_20 ;
else if ( ( V_143 & V_141 ) != 0 )
V_142 |= V_143 ;
else if ( ( V_144 & V_141 ) != 0 )
V_142 |= V_144 ;
else if ( ( V_145 & V_141 ) != 0 )
V_142 |= V_145 ;
return V_142 ;
}
static bool F_91 ( struct V_10 * V_11 ,
T_1 V_3 ,
const struct V_1 * V_2 ,
T_1 * V_146 )
{
T_1 V_147 = F_11 ( V_3 ) ;
if ( ( V_147 & V_2 -> V_5 & V_6 ) == 0 )
return false ;
if ( ( V_2 -> V_5 & V_11 -> V_19 ) == 0 )
return false ;
V_147 |= ( V_2 -> V_5 & V_11 -> V_19 ) ;
* V_146 = V_147 ;
return true ;
}
int F_80 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
struct V_79 * V_30 ,
bool V_81 ,
bool V_82 )
{
struct V_8 * V_9 = V_25 -> V_9 ;
struct V_10 * V_11 ;
T_1 V_3 = V_21 ;
T_1 V_147 = 0 ;
bool V_148 = false ;
bool V_149 = false ;
bool V_150 = false ;
int V_28 , V_29 ;
V_29 = F_88 ( V_25 -> V_51 ) ;
if ( F_3 ( V_29 ) )
return V_29 ;
V_30 -> V_46 = NULL ;
for ( V_28 = 0 ; V_28 < V_27 -> V_32 ; ++ V_28 ) {
const struct V_1 * V_2 = & V_27 -> V_27 [ V_28 ] ;
V_29 = F_1 ( V_2 , & V_3 ) ;
if ( V_29 )
return V_29 ;
V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( ! V_11 -> V_15 || ! V_11 -> V_16 )
continue;
V_149 = F_91 ( V_11 , V_3 , V_2 ,
& V_147 ) ;
if ( ! V_149 )
continue;
V_148 = true ;
V_147 = F_90 ( V_11 , V_25 -> V_30 . V_27 ,
V_147 ) ;
F_92 ( & V_147 , V_2 -> V_5 ,
~ V_151 ) ;
if ( V_3 == V_21 )
break;
V_29 = (* V_11 -> V_22 -> V_139 )( V_11 , V_25 , V_2 , V_30 ) ;
if ( F_3 ( V_29 ) )
return V_29 ;
if ( V_30 -> V_46 ) {
V_29 = F_85 ( V_25 , V_11 , V_30 ) ;
if ( F_3 ( V_29 ) ) {
(* V_11 -> V_22 -> V_137 )( V_11 , V_30 ) ;
return V_29 ;
}
break;
}
}
if ( ( V_149 && ( V_3 == V_21 ) ) || V_30 -> V_46 ) {
V_30 -> V_3 = V_3 ;
V_30 -> V_27 = V_147 ;
return 0 ;
}
for ( V_28 = 0 ; V_28 < V_27 -> V_130 ; ++ V_28 ) {
const struct V_1 * V_2 = & V_27 -> V_152 [ V_28 ] ;
V_29 = F_1 ( V_2 , & V_3 ) ;
if ( V_29 )
return V_29 ;
V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( ! V_11 -> V_15 || ! V_11 -> V_16 )
continue;
if ( ! F_91 ( V_11 , V_3 , V_2 , & V_147 ) )
continue;
V_148 = true ;
V_147 = F_90 ( V_11 , V_25 -> V_30 . V_27 ,
V_147 ) ;
F_92 ( & V_147 , V_2 -> V_5 ,
~ V_151 ) ;
if ( V_3 == V_21 ) {
V_30 -> V_3 = V_3 ;
V_30 -> V_27 = V_147 ;
V_30 -> V_46 = NULL ;
return 0 ;
}
V_29 = F_89 ( V_25 , V_3 , V_2 , V_30 ,
V_81 , V_82 ) ;
if ( V_29 == 0 && V_30 -> V_46 ) {
V_30 -> V_27 = V_147 ;
return 0 ;
}
if ( V_29 == - V_132 )
V_150 = true ;
}
if ( ! V_148 ) {
F_6 ( V_14 L_15 ) ;
return - V_7 ;
}
return ( V_150 ) ? - V_132 : - V_76 ;
}
static int F_93 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
bool V_81 ,
bool V_82 )
{
int V_29 = 0 ;
struct V_79 V_30 ;
F_24 ( & V_25 -> V_51 -> V_56 . V_57 ) ;
V_30 . V_31 = V_25 -> V_31 ;
V_30 . V_18 = V_30 . V_31 << V_74 ;
V_30 . V_153 = V_25 -> V_30 . V_153 ;
V_30 . V_127 . V_128 = false ;
V_30 . V_127 . V_129 = 0 ;
V_29 = F_80 ( V_25 , V_27 , & V_30 ,
V_81 , V_82 ) ;
if ( V_29 )
goto V_116;
V_29 = F_38 ( V_25 , & V_30 , false ,
V_81 , V_82 ) ;
V_116:
if ( V_29 && V_30 . V_46 )
F_48 ( V_25 , & V_30 ) ;
return V_29 ;
}
static bool F_94 ( const struct V_1 * V_154 ,
unsigned V_32 ,
struct V_79 * V_30 ,
T_1 * V_155 )
{
unsigned V_28 ;
for ( V_28 = 0 ; V_28 < V_32 ; V_28 ++ ) {
const struct V_1 * V_156 = & V_154 [ V_28 ] ;
if ( V_30 -> V_46 && ( V_30 -> V_98 < V_156 -> V_133 ||
( V_156 -> V_134 != 0 && ( V_30 -> V_98 + V_30 -> V_31 ) > V_156 -> V_134 ) ) )
continue;
* V_155 = V_156 -> V_5 ;
if ( ( * V_155 & V_30 -> V_27 & V_87 ) &&
( * V_155 & V_30 -> V_27 & V_6 ) &&
( ! ( * V_155 & V_157 ) ||
( V_30 -> V_27 & V_157 ) ) )
return true ;
}
return false ;
}
bool F_95 ( struct V_26 * V_27 ,
struct V_79 * V_30 ,
T_1 * V_155 )
{
if ( F_94 ( V_27 -> V_27 , V_27 -> V_32 ,
V_30 , V_155 ) )
return true ;
if ( ( V_27 -> V_152 != V_27 -> V_27 ||
V_27 -> V_130 > V_27 -> V_32 ) &&
F_94 ( V_27 -> V_152 ,
V_27 -> V_130 ,
V_30 , V_155 ) )
return true ;
return false ;
}
int F_96 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
bool V_81 ,
bool V_82 )
{
int V_29 ;
T_1 V_155 ;
F_24 ( & V_25 -> V_51 -> V_56 . V_57 ) ;
if ( ! F_95 ( V_27 , & V_25 -> V_30 , & V_155 ) ) {
V_29 = F_93 ( V_25 , V_27 , V_81 ,
V_82 ) ;
if ( V_29 )
return V_29 ;
} else {
F_92 ( & V_25 -> V_30 . V_27 , V_155 ,
~ V_151 ) ;
}
if ( V_25 -> V_30 . V_3 == V_21 && V_25 -> V_49 == NULL ) {
V_29 = F_36 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
int F_97 ( struct V_8 * V_9 ,
struct V_24 * V_25 ,
unsigned long V_18 ,
enum V_158 type ,
struct V_26 * V_27 ,
T_1 V_153 ,
bool V_81 ,
struct V_159 * V_160 ,
T_3 V_44 ,
struct V_161 * V_78 ,
struct V_111 * V_51 ,
void (* V_54) ( struct V_24 * ) )
{
int V_29 = 0 ;
unsigned long V_31 ;
struct V_162 * V_55 = V_9 -> V_39 -> V_55 ;
bool V_163 ;
V_29 = F_98 ( V_55 , V_44 , false , false ) ;
if ( V_29 ) {
F_6 ( L_16 ) ;
if ( V_54 )
(* V_54)( V_25 ) ;
else
F_21 ( V_25 ) ;
return - V_76 ;
}
V_31 = ( V_18 + V_40 - 1 ) >> V_74 ;
if ( V_31 == 0 ) {
F_6 ( L_17 ) ;
if ( V_54 )
(* V_54)( V_25 ) ;
else
F_21 ( V_25 ) ;
F_22 ( V_55 , V_44 ) ;
return - V_7 ;
}
V_25 -> V_54 = V_54 ;
F_99 ( & V_25 -> V_42 ) ;
F_99 ( & V_25 -> V_43 ) ;
F_100 ( & V_25 -> V_45 , 0 ) ;
F_101 ( & V_25 -> V_47 ) ;
F_101 ( & V_25 -> V_48 ) ;
F_101 ( & V_25 -> V_62 ) ;
F_101 ( & V_25 -> V_164 ) ;
F_102 ( & V_25 -> V_53 ) ;
V_25 -> V_9 = V_9 ;
V_25 -> V_39 = V_9 -> V_39 ;
V_25 -> type = type ;
V_25 -> V_31 = V_31 ;
V_25 -> V_30 . V_18 = V_31 << V_74 ;
V_25 -> V_30 . V_3 = V_21 ;
V_25 -> V_30 . V_31 = V_25 -> V_31 ;
V_25 -> V_30 . V_46 = NULL ;
V_25 -> V_30 . V_153 = V_153 ;
V_25 -> V_30 . V_127 . V_128 = false ;
V_25 -> V_30 . V_127 . V_129 = 0 ;
V_25 -> V_50 = NULL ;
V_25 -> V_30 . V_27 = ( V_165 | V_143 ) ;
V_25 -> V_160 = V_160 ;
V_25 -> V_44 = V_44 ;
V_25 -> V_78 = V_78 ;
if ( V_51 ) {
V_25 -> V_51 = V_51 ;
F_24 ( & V_25 -> V_51 -> V_56 . V_57 ) ;
} else {
V_25 -> V_51 = & V_25 -> V_52 ;
F_51 ( & V_25 -> V_52 ) ;
}
F_103 ( & V_25 -> V_39 -> V_41 ) ;
F_104 ( & V_25 -> V_123 ) ;
V_25 -> V_59 = 0 ;
if ( V_25 -> type == V_69 ||
V_25 -> type == V_77 )
V_29 = F_105 ( & V_9 -> V_122 , & V_25 -> V_123 ,
V_25 -> V_30 . V_31 ) ;
if ( ! V_51 ) {
V_163 = F_106 ( & V_25 -> V_51 -> V_56 ) ;
F_107 ( ! V_163 ) ;
}
if ( F_108 ( ! V_29 ) )
V_29 = F_96 ( V_25 , V_27 , V_81 , false ) ;
if ( F_3 ( V_29 ) ) {
if ( ! V_51 )
F_84 ( V_25 ) ;
F_75 ( & V_25 ) ;
return V_29 ;
}
if ( V_51 && ! ( V_25 -> V_30 . V_27 & V_58 ) ) {
F_33 ( & V_25 -> V_39 -> V_64 ) ;
F_23 ( V_25 ) ;
F_34 ( & V_25 -> V_39 -> V_64 ) ;
}
return V_29 ;
}
int F_109 ( struct V_8 * V_9 ,
struct V_24 * V_25 ,
unsigned long V_18 ,
enum V_158 type ,
struct V_26 * V_27 ,
T_1 V_153 ,
bool V_81 ,
struct V_159 * V_160 ,
T_3 V_44 ,
struct V_161 * V_78 ,
struct V_111 * V_51 ,
void (* V_54) ( struct V_24 * ) )
{
int V_29 ;
V_29 = F_97 ( V_9 , V_25 , V_18 , type , V_27 ,
V_153 , V_81 ,
V_160 , V_44 ,
V_78 , V_51 , V_54 ) ;
if ( V_29 )
return V_29 ;
if ( ! V_51 )
F_84 ( V_25 ) ;
return 0 ;
}
T_3 F_110 ( struct V_8 * V_9 ,
unsigned long V_166 ,
unsigned V_167 )
{
unsigned V_168 = ( F_111 ( V_166 ) ) >> V_74 ;
T_3 V_18 = 0 ;
V_18 += F_112 ( V_167 ) ;
V_18 += F_112 ( V_168 * sizeof( void * ) ) ;
V_18 += F_112 ( sizeof( struct V_169 ) ) ;
return V_18 ;
}
T_3 F_113 ( struct V_8 * V_9 ,
unsigned long V_166 ,
unsigned V_167 )
{
unsigned V_168 = ( F_111 ( V_166 ) ) >> V_74 ;
T_3 V_18 = 0 ;
V_18 += F_112 ( V_167 ) ;
V_18 += F_112 ( V_168 * ( 2 * sizeof( void * ) + sizeof( V_170 ) ) ) ;
V_18 += F_112 ( sizeof( struct V_171 ) ) ;
return V_18 ;
}
int F_114 ( struct V_8 * V_9 ,
unsigned long V_18 ,
enum V_158 type ,
struct V_26 * V_27 ,
T_1 V_153 ,
bool V_81 ,
struct V_159 * V_160 ,
struct V_24 * * V_124 )
{
struct V_24 * V_25 ;
T_3 V_44 ;
int V_29 ;
V_25 = F_115 ( sizeof( * V_25 ) , V_172 ) ;
if ( F_3 ( V_25 == NULL ) )
return - V_76 ;
V_44 = F_110 ( V_9 , V_18 , sizeof( struct V_24 ) ) ;
V_29 = F_109 ( V_9 , V_25 , V_18 , type , V_27 , V_153 ,
V_81 , V_160 , V_44 ,
NULL , NULL , NULL ) ;
if ( F_108 ( V_29 == 0 ) )
* V_124 = V_25 ;
return V_29 ;
}
static int F_116 ( struct V_8 * V_9 ,
unsigned V_3 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
struct V_38 * V_39 = V_9 -> V_39 ;
struct V_103 * V_104 ;
int V_29 ;
unsigned V_28 ;
F_33 ( & V_39 -> V_64 ) ;
for ( V_28 = 0 ; V_28 < V_135 ; ++ V_28 ) {
while ( ! F_15 ( & V_11 -> V_47 [ V_28 ] ) ) {
F_34 ( & V_39 -> V_64 ) ;
V_29 = F_82 ( V_9 , V_3 , NULL , false , false ) ;
if ( V_29 )
return V_29 ;
F_33 ( & V_39 -> V_64 ) ;
}
}
F_34 ( & V_39 -> V_64 ) ;
F_33 ( & V_11 -> V_138 ) ;
V_104 = F_86 ( V_11 -> V_93 ) ;
F_34 ( & V_11 -> V_138 ) ;
if ( V_104 ) {
V_29 = F_117 ( V_104 , false ) ;
F_18 ( V_104 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
int F_118 ( struct V_8 * V_9 , unsigned V_3 )
{
struct V_10 * V_11 ;
int V_29 = - V_7 ;
if ( V_3 >= V_173 ) {
F_6 ( L_18 , V_3 ) ;
return V_29 ;
}
V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( ! V_11 -> V_15 ) {
F_6 ( L_19 ,
V_3 ) ;
return V_29 ;
}
V_11 -> V_16 = false ;
V_11 -> V_15 = false ;
V_29 = 0 ;
if ( V_3 > 0 ) {
V_29 = F_116 ( V_9 , V_3 ) ;
if ( V_29 ) {
F_6 ( L_20 ) ;
return V_29 ;
}
V_29 = (* V_11 -> V_22 -> V_174 )( V_11 ) ;
}
F_18 ( V_11 -> V_93 ) ;
V_11 -> V_93 = NULL ;
return V_29 ;
}
int F_119 ( struct V_8 * V_9 , unsigned V_3 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( V_3 == 0 || V_3 >= V_173 ) {
F_6 ( L_21 , V_3 ) ;
return - V_7 ;
}
if ( ! V_11 -> V_15 ) {
F_6 ( L_22 , V_3 ) ;
return 0 ;
}
return F_116 ( V_9 , V_3 ) ;
}
int F_120 ( struct V_8 * V_9 , unsigned type ,
unsigned long V_175 )
{
int V_29 ;
struct V_10 * V_11 ;
unsigned V_28 ;
F_13 ( type >= V_173 ) ;
V_11 = & V_9 -> V_11 [ type ] ;
F_13 ( V_11 -> V_15 ) ;
V_11 -> V_176 = true ;
V_11 -> V_177 = false ;
F_102 ( & V_11 -> V_178 ) ;
F_121 ( & V_11 -> V_138 ) ;
F_101 ( & V_11 -> V_164 ) ;
V_29 = V_9 -> V_72 -> V_179 ( V_9 , type , V_11 ) ;
if ( V_29 )
return V_29 ;
V_11 -> V_9 = V_9 ;
if ( type != V_21 ) {
V_29 = (* V_11 -> V_22 -> V_180 )( V_11 , V_175 ) ;
if ( V_29 )
return V_29 ;
}
V_11 -> V_15 = true ;
V_11 -> V_16 = true ;
V_11 -> V_18 = V_175 ;
for ( V_28 = 0 ; V_28 < V_135 ; ++ V_28 )
F_101 ( & V_11 -> V_47 [ V_28 ] ) ;
V_11 -> V_93 = NULL ;
return 0 ;
}
static void F_122 ( struct V_33 * V_34 )
{
struct V_38 * V_39 =
F_9 ( V_34 , struct V_38 , V_34 ) ;
F_123 ( V_39 -> V_55 , & V_39 -> V_181 ) ;
F_124 ( V_39 -> V_75 ) ;
F_21 ( V_39 ) ;
}
void F_125 ( struct V_182 * V_183 )
{
struct V_38 * V_39 = V_183 -> V_184 ;
F_126 ( & V_39 -> V_34 ) ;
F_127 ( & V_39 -> V_34 ) ;
}
int F_128 ( struct V_182 * V_183 )
{
struct V_185 * V_186 =
F_9 ( V_183 , struct V_185 , V_183 ) ;
struct V_38 * V_39 = V_183 -> V_184 ;
int V_29 ;
unsigned V_28 ;
F_102 ( & V_39 -> V_187 ) ;
F_121 ( & V_39 -> V_64 ) ;
V_39 -> V_55 = V_186 -> V_55 ;
V_39 -> V_75 = F_129 ( V_188 | V_189 ) ;
if ( F_3 ( V_39 -> V_75 == NULL ) ) {
V_29 = - V_76 ;
goto V_190;
}
for ( V_28 = 0 ; V_28 < V_135 ; ++ V_28 )
F_101 ( & V_39 -> V_63 [ V_28 ] ) ;
F_101 ( & V_39 -> V_191 ) ;
F_130 ( & V_39 -> V_181 , V_192 ) ;
V_29 = F_131 ( V_39 -> V_55 , & V_39 -> V_181 ) ;
if ( F_3 ( V_29 != 0 ) ) {
F_6 ( L_23 ) ;
goto V_193;
}
F_100 ( & V_39 -> V_41 , 0 ) ;
V_29 = F_132 (
& V_39 -> V_34 , & V_194 , F_133 () , L_24 ) ;
if ( F_3 ( V_29 != 0 ) )
F_127 ( & V_39 -> V_34 ) ;
return V_29 ;
V_193:
F_124 ( V_39 -> V_75 ) ;
V_190:
F_21 ( V_39 ) ;
return V_29 ;
}
int F_134 ( struct V_8 * V_9 )
{
int V_29 = 0 ;
unsigned V_28 = V_173 ;
struct V_10 * V_11 ;
struct V_38 * V_39 = V_9 -> V_39 ;
while ( V_28 -- ) {
V_11 = & V_9 -> V_11 [ V_28 ] ;
if ( V_11 -> V_15 ) {
V_11 -> V_16 = false ;
if ( ( V_28 != V_21 ) && F_118 ( V_9 , V_28 ) ) {
V_29 = - V_112 ;
F_6 ( L_25 ,
V_28 ) ;
}
V_11 -> V_15 = false ;
}
}
F_135 ( & V_39 -> V_187 ) ;
F_136 ( & V_9 -> V_191 ) ;
F_137 ( & V_39 -> V_187 ) ;
F_77 ( & V_9 -> V_109 ) ;
while ( F_69 ( V_9 , true ) )
;
F_33 ( & V_39 -> V_64 ) ;
if ( F_15 ( & V_9 -> V_48 ) )
F_138 ( L_26 ) ;
for ( V_28 = 0 ; V_28 < V_135 ; ++ V_28 )
if ( F_15 ( & V_9 -> V_11 [ 0 ] . V_47 [ 0 ] ) )
F_138 ( L_27 , V_28 ) ;
F_34 ( & V_39 -> V_64 ) ;
F_139 ( & V_9 -> V_122 ) ;
return V_29 ;
}
int F_140 ( struct V_8 * V_9 ,
struct V_38 * V_39 ,
struct V_195 * V_72 ,
struct V_196 * V_197 ,
T_4 V_198 ,
bool V_67 )
{
int V_29 = - V_7 ;
V_9 -> V_72 = V_72 ;
memset ( V_9 -> V_11 , 0 , sizeof( V_9 -> V_11 ) ) ;
V_29 = F_120 ( V_9 , V_21 , 0 ) ;
if ( F_3 ( V_29 != 0 ) )
goto V_199;
F_141 ( & V_9 -> V_122 , V_198 ,
0x10000000 ) ;
F_142 ( & V_9 -> V_109 , F_71 ) ;
F_101 ( & V_9 -> V_48 ) ;
V_9 -> V_200 = V_197 ;
V_9 -> V_39 = V_39 ;
V_9 -> V_67 = V_67 ;
F_135 ( & V_39 -> V_187 ) ;
F_25 ( & V_9 -> V_191 , & V_39 -> V_191 ) ;
F_137 ( & V_39 -> V_187 ) ;
return 0 ;
V_199:
return V_29 ;
}
bool F_39 ( struct V_8 * V_9 , struct V_79 * V_30 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_30 -> V_3 ] ;
if ( ! ( V_11 -> V_5 & V_89 ) ) {
if ( V_30 -> V_3 == V_21 )
return false ;
if ( V_11 -> V_5 & V_201 )
return false ;
if ( V_30 -> V_27 & V_143 )
return false ;
}
return true ;
}
void F_41 ( struct V_24 * V_25 )
{
struct V_8 * V_9 = V_25 -> V_9 ;
F_143 ( & V_25 -> V_123 , V_9 -> V_200 ) ;
F_74 ( V_25 ) ;
}
void F_144 ( struct V_24 * V_25 )
{
struct V_8 * V_9 = V_25 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_25 -> V_30 . V_3 ] ;
F_40 ( V_11 , false ) ;
F_41 ( V_25 ) ;
F_42 ( V_11 ) ;
}
int F_63 ( struct V_24 * V_25 ,
bool V_81 , bool V_202 )
{
long V_203 = 15 * V_110 ;
if ( V_202 ) {
if ( F_67 ( V_25 -> V_51 , true ) )
return 0 ;
else
return - V_112 ;
}
V_203 = F_68 ( V_25 -> V_51 , true ,
V_81 , V_203 ) ;
if ( V_203 < 0 )
return V_203 ;
if ( V_203 == 0 )
return - V_112 ;
F_145 ( V_25 -> V_51 , NULL ) ;
return 0 ;
}
int F_146 ( struct V_24 * V_25 , bool V_202 )
{
int V_29 = 0 ;
V_29 = F_147 ( V_25 , true , V_202 , NULL ) ;
if ( F_3 ( V_29 != 0 ) )
return V_29 ;
V_29 = F_63 ( V_25 , true , V_202 ) ;
if ( F_108 ( V_29 == 0 ) )
F_103 ( & V_25 -> V_45 ) ;
F_84 ( V_25 ) ;
return V_29 ;
}
void F_148 ( struct V_24 * V_25 )
{
F_17 ( & V_25 -> V_45 ) ;
}
static int V_192 ( struct V_204 * V_181 )
{
struct V_38 * V_39 =
F_9 ( V_181 , struct V_38 , V_181 ) ;
struct V_24 * V_25 ;
int V_29 = - V_112 ;
unsigned V_28 ;
F_33 ( & V_39 -> V_64 ) ;
for ( V_28 = 0 ; V_28 < V_135 ; ++ V_28 ) {
F_83 (bo, &glob->swap_lru[i], swap) {
V_29 = F_62 ( V_25 , false , true , NULL ) ;
if ( ! V_29 )
break;
}
if ( ! V_29 )
break;
}
if ( V_29 ) {
F_34 ( & V_39 -> V_64 ) ;
return V_29 ;
}
F_26 ( & V_25 -> V_43 ) ;
if ( ! F_15 ( & V_25 -> V_48 ) ) {
V_29 = F_66 ( V_25 , false , false ) ;
F_31 ( & V_25 -> V_43 , F_12 ) ;
return V_29 ;
}
F_29 ( V_25 ) ;
F_34 ( & V_39 -> V_64 ) ;
if ( V_25 -> V_30 . V_3 != V_21 ||
V_25 -> V_49 -> V_205 != V_206 ) {
struct V_79 V_126 ;
V_126 = V_25 -> V_30 ;
V_126 . V_46 = NULL ;
V_126 . V_27 = V_165 | V_143 ;
V_126 . V_3 = V_21 ;
V_29 = F_38 ( V_25 , & V_126 , true ,
false , false ) ;
if ( F_3 ( V_29 != 0 ) )
goto V_119;
}
V_29 = F_63 ( V_25 , false , false ) ;
if ( F_3 ( V_29 != 0 ) )
goto V_119;
F_144 ( V_25 ) ;
if ( V_25 -> V_9 -> V_72 -> V_207 )
V_25 -> V_9 -> V_72 -> V_207 ( V_25 ) ;
V_29 = F_149 ( V_25 -> V_49 , V_25 -> V_160 ) ;
V_119:
F_64 ( V_25 ) ;
F_31 ( & V_25 -> V_43 , F_12 ) ;
return V_29 ;
}
void F_150 ( struct V_8 * V_9 )
{
while ( V_192 ( & V_9 -> V_39 -> V_181 ) == 0 )
;
}
int F_151 ( struct V_24 * V_25 )
{
int V_29 ;
V_29 = F_152 ( & V_25 -> V_53 ) ;
if ( F_3 ( V_29 != 0 ) )
return - V_132 ;
if ( ! F_153 ( & V_25 -> V_51 -> V_56 ) )
goto V_116;
V_29 = F_62 ( V_25 , true , false , NULL ) ;
if ( F_3 ( V_29 != 0 ) )
goto V_116;
F_64 ( V_25 ) ;
V_116:
F_137 ( & V_25 -> V_53 ) ;
return V_29 ;
}
