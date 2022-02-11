static inline int F_1 ( const struct V_1 * V_2 ,
T_1 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 <= V_5 ; V_4 ++ )
if ( V_2 -> V_6 & ( 1 << V_4 ) ) {
* V_3 = V_4 ;
return 0 ;
}
return - V_7 ;
}
static void F_2 ( struct V_8 * V_9 , int V_3 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
F_3 ( L_1 , V_11 -> V_12 ) ;
F_3 ( L_2 , V_11 -> V_13 ) ;
F_3 ( L_3 , V_11 -> V_6 ) ;
F_3 ( L_4 , V_11 -> V_14 ) ;
F_3 ( L_5 , V_11 -> V_15 ) ;
F_3 ( L_6 , V_11 -> V_16 ) ;
F_3 ( L_7 , V_11 -> V_17 ) ;
if ( V_3 != V_18 )
(* V_11 -> V_19 -> V_20 )( V_11 , V_21 ) ;
}
static void F_4 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
int V_4 , V_26 , V_3 ;
F_3 ( L_8 ,
V_23 , V_23 -> V_27 . V_28 , V_23 -> V_27 . V_15 >> 10 ,
V_23 -> V_27 . V_15 >> 20 ) ;
for ( V_4 = 0 ; V_4 < V_25 -> V_29 ; V_4 ++ ) {
V_26 = F_1 ( & V_25 -> V_25 [ V_4 ] ,
& V_3 ) ;
if ( V_26 )
return;
F_3 ( L_9 ,
V_4 , V_25 -> V_25 [ V_4 ] . V_6 , V_3 ) ;
F_2 ( V_23 -> V_9 , V_3 ) ;
}
}
static T_2 F_5 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
char * V_34 )
{
struct V_35 * V_36 =
F_6 ( V_31 , struct V_35 , V_31 ) ;
return snprintf ( V_34 , V_37 , L_10 ,
( unsigned long ) F_7 ( & V_36 -> V_38 ) ) ;
}
static inline T_1 F_8 ( unsigned type )
{
return 1 << ( type ) ;
}
static void F_9 ( struct V_39 * V_40 )
{
struct V_22 * V_23 =
F_6 ( V_40 , struct V_22 , V_40 ) ;
struct V_8 * V_9 = V_23 -> V_9 ;
T_3 V_41 = V_23 -> V_41 ;
F_10 ( F_7 ( & V_23 -> V_40 . V_42 ) ) ;
F_10 ( F_7 ( & V_23 -> V_39 . V_42 ) ) ;
F_10 ( F_7 ( & V_23 -> V_43 ) ) ;
F_10 ( V_23 -> V_27 . V_44 != NULL ) ;
F_10 ( ! F_11 ( & V_23 -> V_45 ) ) ;
F_10 ( ! F_11 ( & V_23 -> V_46 ) ) ;
if ( V_23 -> V_47 )
F_12 ( V_23 -> V_47 ) ;
F_13 ( & V_23 -> V_36 -> V_38 ) ;
if ( V_23 -> V_48 == & V_23 -> V_49 )
F_14 ( & V_23 -> V_49 ) ;
F_15 ( & V_23 -> V_50 ) ;
if ( V_23 -> V_51 )
V_23 -> V_51 ( V_23 ) ;
else {
F_16 ( V_23 ) ;
}
F_17 ( V_9 -> V_36 -> V_52 , V_41 ) ;
}
void F_18 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
F_19 ( & V_23 -> V_48 -> V_53 . V_54 ) ;
if ( ! ( V_23 -> V_27 . V_25 & V_55 ) ) {
F_10 ( ! F_11 ( & V_23 -> V_45 ) ) ;
F_20 ( & V_23 -> V_45 , V_9 -> V_56 -> V_57 ( V_23 ) ) ;
F_21 ( & V_23 -> V_40 ) ;
if ( V_23 -> V_47 && ! ( V_23 -> V_47 -> V_58 & V_59 ) ) {
F_20 ( & V_23 -> V_60 , V_9 -> V_56 -> V_61 ( V_23 ) ) ;
F_21 ( & V_23 -> V_40 ) ;
}
}
}
int F_22 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
int V_62 = 0 ;
if ( V_9 -> V_56 -> V_63 )
V_9 -> V_56 -> V_63 ( V_23 ) ;
if ( ! F_11 ( & V_23 -> V_60 ) ) {
F_23 ( & V_23 -> V_60 ) ;
++ V_62 ;
}
if ( ! F_11 ( & V_23 -> V_45 ) ) {
F_23 ( & V_23 -> V_45 ) ;
++ V_62 ;
}
return V_62 ;
}
static void F_24 ( struct V_39 * V_40 )
{
F_25 () ;
}
void F_26 ( struct V_22 * V_23 , int V_64 ,
bool V_65 )
{
F_27 ( & V_23 -> V_40 , V_64 ,
( V_65 ) ? F_24 : F_9 ) ;
}
void F_28 ( struct V_22 * V_23 )
{
int V_62 ;
F_29 ( & V_23 -> V_36 -> V_66 ) ;
V_62 = F_22 ( V_23 ) ;
F_30 ( & V_23 -> V_36 -> V_66 ) ;
F_26 ( V_23 , V_62 , true ) ;
}
void F_31 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
int V_62 = 0 ;
F_19 ( & V_23 -> V_48 -> V_53 . V_54 ) ;
if ( V_9 -> V_56 -> V_63 )
V_9 -> V_56 -> V_63 ( V_23 ) ;
V_62 = F_22 ( V_23 ) ;
F_26 ( V_23 , V_62 , true ) ;
F_18 ( V_23 ) ;
}
struct V_67 * F_32 ( struct V_22 * V_23 )
{
return V_23 -> V_9 -> V_11 [ V_23 -> V_27 . V_3 ] . V_45 . V_68 ;
}
struct V_67 * F_33 ( struct V_22 * V_23 )
{
return V_23 -> V_36 -> V_69 . V_68 ;
}
static int F_34 ( struct V_22 * V_23 , bool V_70 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_35 * V_36 = V_23 -> V_36 ;
int V_26 = 0 ;
T_1 V_58 = 0 ;
F_35 ( & V_23 -> V_71 ) ;
V_23 -> V_47 = NULL ;
if ( V_9 -> V_72 )
V_58 |= V_73 ;
switch ( V_23 -> type ) {
case V_74 :
if ( V_70 )
V_58 |= V_75 ;
case V_76 :
V_23 -> V_47 = V_9 -> V_56 -> V_77 ( V_9 , V_23 -> V_28 << V_78 ,
V_58 , V_36 -> V_79 ) ;
if ( F_36 ( V_23 -> V_47 == NULL ) )
V_26 = - V_80 ;
break;
case V_81 :
V_23 -> V_47 = V_9 -> V_56 -> V_77 ( V_9 , V_23 -> V_28 << V_78 ,
V_58 | V_59 ,
V_36 -> V_79 ) ;
if ( F_36 ( V_23 -> V_47 == NULL ) ) {
V_26 = - V_80 ;
break;
}
V_23 -> V_47 -> V_82 = V_23 -> V_82 ;
break;
default:
F_3 ( L_11 ) ;
V_26 = - V_7 ;
break;
}
return V_26 ;
}
static int F_37 ( struct V_22 * V_23 ,
struct V_83 * V_27 ,
bool V_84 , bool V_85 ,
bool V_86 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
bool V_87 = F_38 ( V_9 , & V_23 -> V_27 ) ;
bool V_88 = F_38 ( V_9 , V_27 ) ;
struct V_10 * V_89 = & V_9 -> V_11 [ V_23 -> V_27 . V_3 ] ;
struct V_10 * V_90 = & V_9 -> V_11 [ V_27 -> V_3 ] ;
int V_26 = 0 ;
if ( V_87 || V_88 ||
( ( V_27 -> V_25 & V_23 -> V_27 . V_25 & V_91 ) == 0 ) ) {
V_26 = F_39 ( V_89 , true ) ;
if ( F_36 ( V_26 != 0 ) )
goto V_92;
F_40 ( V_23 ) ;
F_41 ( V_89 ) ;
}
if ( ! ( V_90 -> V_6 & V_93 ) ) {
if ( V_23 -> V_47 == NULL ) {
bool V_94 = ! ( V_89 -> V_6 & V_93 ) ;
V_26 = F_34 ( V_23 , V_94 ) ;
if ( V_26 )
goto V_92;
}
V_26 = F_42 ( V_23 -> V_47 , V_27 -> V_25 ) ;
if ( V_26 )
goto V_92;
if ( V_27 -> V_3 != V_18 ) {
V_26 = F_43 ( V_23 -> V_47 , V_27 ) ;
if ( V_26 )
goto V_92;
}
if ( V_23 -> V_27 . V_3 == V_18 ) {
if ( V_9 -> V_56 -> V_95 )
V_9 -> V_56 -> V_95 ( V_23 , V_27 ) ;
V_23 -> V_27 = * V_27 ;
V_27 -> V_44 = NULL ;
goto V_96;
}
}
if ( V_9 -> V_56 -> V_95 )
V_9 -> V_56 -> V_95 ( V_23 , V_27 ) ;
if ( ! ( V_89 -> V_6 & V_93 ) &&
! ( V_90 -> V_6 & V_93 ) )
V_26 = F_44 ( V_23 , V_84 , V_86 , V_27 ) ;
else if ( V_9 -> V_56 -> V_97 )
V_26 = V_9 -> V_56 -> V_97 ( V_23 , V_84 , V_85 ,
V_86 , V_27 ) ;
else
V_26 = F_45 ( V_23 , V_84 , V_86 , V_27 ) ;
if ( V_26 ) {
if ( V_9 -> V_56 -> V_95 ) {
struct V_83 V_98 = * V_27 ;
* V_27 = V_23 -> V_27 ;
V_23 -> V_27 = V_98 ;
V_9 -> V_56 -> V_95 ( V_23 , V_27 ) ;
V_23 -> V_27 = * V_27 ;
* V_27 = V_98 ;
}
goto V_92;
}
V_96:
if ( V_23 -> V_99 ) {
if ( V_9 -> V_56 -> V_100 ) {
V_26 = V_9 -> V_56 -> V_100 ( V_9 , V_23 -> V_27 . V_25 ) ;
if ( V_26 )
F_3 ( L_12 ) ;
}
V_23 -> V_99 = false ;
}
if ( V_23 -> V_27 . V_44 ) {
V_23 -> V_101 = ( V_23 -> V_27 . V_102 << V_78 ) +
V_9 -> V_11 [ V_23 -> V_27 . V_3 ] . V_14 ;
V_23 -> V_103 = V_23 -> V_27 . V_25 ;
} else
V_23 -> V_101 = 0 ;
return 0 ;
V_92:
V_90 = & V_9 -> V_11 [ V_23 -> V_27 . V_3 ] ;
if ( ( V_90 -> V_6 & V_93 ) && V_23 -> V_47 ) {
F_46 ( V_23 -> V_47 ) ;
F_12 ( V_23 -> V_47 ) ;
V_23 -> V_47 = NULL ;
}
return V_26 ;
}
static void F_47 ( struct V_22 * V_23 )
{
if ( V_23 -> V_9 -> V_56 -> V_95 )
V_23 -> V_9 -> V_56 -> V_95 ( V_23 , NULL ) ;
if ( V_23 -> V_47 ) {
F_46 ( V_23 -> V_47 ) ;
F_12 ( V_23 -> V_47 ) ;
V_23 -> V_47 = NULL ;
}
F_48 ( V_23 , & V_23 -> V_27 ) ;
F_49 ( & V_23 -> V_48 -> V_53 ) ;
}
static void F_50 ( struct V_22 * V_23 )
{
struct V_104 * V_105 ;
struct V_106 * V_106 ;
int V_4 ;
V_105 = F_51 ( V_23 -> V_48 ) ;
V_106 = F_52 ( V_23 -> V_48 ) ;
if ( V_106 && ! V_106 -> V_107 -> V_108 )
F_53 ( V_106 ) ;
for ( V_4 = 0 ; V_105 && V_4 < V_105 -> V_109 ; ++ V_4 ) {
V_106 = F_54 ( V_105 -> V_110 [ V_4 ] ,
F_55 ( V_23 -> V_48 ) ) ;
if ( ! V_106 -> V_107 -> V_108 )
F_53 ( V_106 ) ;
}
}
static void F_56 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_35 * V_36 = V_23 -> V_36 ;
int V_62 ;
int V_26 ;
F_29 ( & V_36 -> V_66 ) ;
V_26 = F_57 ( V_23 , false , true , NULL ) ;
if ( ! V_26 ) {
if ( ! F_58 ( V_23 , false , true ) ) {
V_62 = F_22 ( V_23 ) ;
F_30 ( & V_36 -> V_66 ) ;
F_47 ( V_23 ) ;
F_26 ( V_23 , V_62 , true ) ;
return;
} else
F_50 ( V_23 ) ;
if ( V_23 -> V_27 . V_25 & V_55 ) {
V_23 -> V_27 . V_25 &= ~ V_55 ;
F_18 ( V_23 ) ;
}
F_59 ( V_23 ) ;
}
F_21 ( & V_23 -> V_40 ) ;
F_60 ( & V_23 -> V_46 , & V_9 -> V_46 ) ;
F_30 ( & V_36 -> V_66 ) ;
F_61 ( & V_9 -> V_111 ,
( ( V_112 / 100 ) < 1 ) ? 1 : V_112 / 100 ) ;
}
static int F_62 ( struct V_22 * V_23 ,
bool V_85 ,
bool V_86 )
{
struct V_35 * V_36 = V_23 -> V_36 ;
int V_62 ;
int V_26 ;
V_26 = F_58 ( V_23 , false , true ) ;
if ( V_26 && ! V_86 ) {
long V_113 ;
F_49 ( & V_23 -> V_48 -> V_53 ) ;
F_30 ( & V_36 -> V_66 ) ;
V_113 = F_63 ( V_23 -> V_48 ,
true ,
V_85 ,
30 * V_112 ) ;
if ( V_113 < 0 )
return V_113 ;
else if ( V_113 == 0 )
return - V_114 ;
F_29 ( & V_36 -> V_66 ) ;
V_26 = F_57 ( V_23 , false , true , NULL ) ;
if ( V_26 ) {
F_30 ( & V_36 -> V_66 ) ;
return 0 ;
}
V_26 = F_58 ( V_23 , false , true ) ;
F_64 ( V_26 ) ;
}
if ( V_26 || F_36 ( F_11 ( & V_23 -> V_46 ) ) ) {
F_59 ( V_23 ) ;
F_30 ( & V_36 -> V_66 ) ;
return V_26 ;
}
V_62 = F_22 ( V_23 ) ;
F_23 ( & V_23 -> V_46 ) ;
++ V_62 ;
F_30 ( & V_36 -> V_66 ) ;
F_47 ( V_23 ) ;
F_26 ( V_23 , V_62 , true ) ;
return 0 ;
}
static int F_65 ( struct V_8 * V_9 , bool V_115 )
{
struct V_35 * V_36 = V_9 -> V_36 ;
struct V_22 * V_116 = NULL ;
int V_26 = 0 ;
F_29 ( & V_36 -> V_66 ) ;
if ( F_11 ( & V_9 -> V_46 ) )
goto V_117;
V_116 = F_66 ( & V_9 -> V_46 ,
struct V_22 , V_46 ) ;
F_21 ( & V_116 -> V_40 ) ;
for (; ; ) {
struct V_22 * V_118 = NULL ;
if ( V_116 -> V_46 . V_119 != & V_9 -> V_46 ) {
V_118 = F_66 ( & V_116 -> V_46 ,
struct V_22 , V_46 ) ;
F_21 ( & V_118 -> V_40 ) ;
}
V_26 = F_57 ( V_116 , false , true , NULL ) ;
if ( V_115 && V_26 ) {
F_30 ( & V_36 -> V_66 ) ;
V_26 = F_57 ( V_116 , false , false , NULL ) ;
F_29 ( & V_36 -> V_66 ) ;
}
if ( ! V_26 )
V_26 = F_62 ( V_116 , false ,
! V_115 ) ;
else
F_30 ( & V_36 -> V_66 ) ;
F_67 ( & V_116 -> V_40 , F_9 ) ;
V_116 = V_118 ;
if ( V_26 || ! V_116 )
goto V_120;
F_29 ( & V_36 -> V_66 ) ;
if ( F_11 ( & V_116 -> V_46 ) )
break;
}
V_117:
F_30 ( & V_36 -> V_66 ) ;
V_120:
if ( V_116 )
F_67 ( & V_116 -> V_40 , F_9 ) ;
return V_26 ;
}
static void F_68 ( struct V_121 * V_122 )
{
struct V_8 * V_9 =
F_6 ( V_122 , struct V_8 , V_111 . V_122 ) ;
if ( F_65 ( V_9 , false ) ) {
F_61 ( & V_9 -> V_111 ,
( ( V_112 / 100 ) < 1 ) ? 1 : V_112 / 100 ) ;
}
}
static void F_69 ( struct V_39 * V_39 )
{
struct V_22 * V_23 =
F_6 ( V_39 , struct V_22 , V_39 ) ;
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_23 -> V_27 . V_3 ] ;
F_70 ( & V_9 -> V_123 , & V_23 -> V_124 ) ;
F_39 ( V_11 , false ) ;
F_71 ( V_23 ) ;
F_41 ( V_11 ) ;
F_56 ( V_23 ) ;
F_67 ( & V_23 -> V_40 , F_9 ) ;
}
void F_72 ( struct V_22 * * V_125 )
{
struct V_22 * V_23 = * V_125 ;
* V_125 = NULL ;
F_67 ( & V_23 -> V_39 , F_69 ) ;
}
int F_73 ( struct V_8 * V_9 )
{
return F_74 ( & V_9 -> V_111 ) ;
}
void F_75 ( struct V_8 * V_9 , int V_126 )
{
if ( V_126 )
F_61 ( & V_9 -> V_111 ,
( ( V_112 / 100 ) < 1 ) ? 1 : V_112 / 100 ) ;
}
static int F_76 ( struct V_22 * V_23 , bool V_85 ,
bool V_86 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_83 V_127 ;
struct V_24 V_25 ;
int V_26 = 0 ;
V_26 = F_58 ( V_23 , V_85 , V_86 ) ;
if ( F_36 ( V_26 != 0 ) ) {
if ( V_26 != - V_128 ) {
F_3 ( L_13 ) ;
}
goto V_120;
}
F_19 ( & V_23 -> V_48 -> V_53 . V_54 ) ;
V_127 = V_23 -> V_27 ;
V_127 . V_44 = NULL ;
V_127 . V_129 . V_130 = false ;
V_127 . V_129 . V_131 = 0 ;
V_25 . V_29 = 0 ;
V_25 . V_132 = 0 ;
V_9 -> V_56 -> V_133 ( V_23 , & V_25 ) ;
V_26 = F_77 ( V_23 , & V_25 , & V_127 , V_85 ,
V_86 ) ;
if ( V_26 ) {
if ( V_26 != - V_128 ) {
F_3 ( L_14 ,
V_23 ) ;
F_4 ( V_23 , & V_25 ) ;
}
goto V_120;
}
V_26 = F_37 ( V_23 , & V_127 , true , V_85 ,
V_86 ) ;
if ( V_26 ) {
if ( V_26 != - V_128 )
F_3 ( L_15 ) ;
F_48 ( V_23 , & V_127 ) ;
goto V_120;
}
V_23 -> V_99 = true ;
V_120:
return V_26 ;
}
static int F_78 ( struct V_8 * V_9 ,
T_1 V_3 ,
const struct V_1 * V_2 ,
bool V_85 ,
bool V_86 )
{
struct V_35 * V_36 = V_9 -> V_36 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
struct V_22 * V_23 ;
int V_26 = - V_114 , V_62 ;
F_29 ( & V_36 -> V_66 ) ;
F_79 (bo, &man->lru, lru) {
V_26 = F_57 ( V_23 , false , true , NULL ) ;
if ( ! V_26 ) {
if ( V_2 && ( V_2 -> V_134 || V_2 -> V_135 ) ) {
if ( V_2 -> V_134 >= ( V_23 -> V_27 . V_102 + V_23 -> V_27 . V_15 ) ||
( V_2 -> V_135 && V_2 -> V_135 <= V_23 -> V_27 . V_102 ) ) {
F_59 ( V_23 ) ;
V_26 = - V_114 ;
continue;
}
}
break;
}
}
if ( V_26 ) {
F_30 ( & V_36 -> V_66 ) ;
return V_26 ;
}
F_21 ( & V_23 -> V_40 ) ;
if ( ! F_11 ( & V_23 -> V_46 ) ) {
V_26 = F_62 ( V_23 , V_85 ,
V_86 ) ;
F_67 ( & V_23 -> V_40 , F_9 ) ;
return V_26 ;
}
V_62 = F_22 ( V_23 ) ;
F_30 ( & V_36 -> V_66 ) ;
F_10 ( V_26 != 0 ) ;
F_26 ( V_23 , V_62 , true ) ;
V_26 = F_76 ( V_23 , V_85 , V_86 ) ;
F_80 ( V_23 ) ;
F_67 ( & V_23 -> V_40 , F_9 ) ;
return V_26 ;
}
void F_48 ( struct V_22 * V_23 , struct V_83 * V_27 )
{
struct V_10 * V_11 = & V_23 -> V_9 -> V_11 [ V_27 -> V_3 ] ;
if ( V_27 -> V_44 )
(* V_11 -> V_19 -> V_136 )( V_11 , V_27 ) ;
}
static int F_81 ( struct V_22 * V_23 ,
T_1 V_3 ,
const struct V_1 * V_2 ,
struct V_83 * V_27 ,
bool V_85 ,
bool V_86 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
int V_26 ;
do {
V_26 = (* V_11 -> V_19 -> V_137 )( V_11 , V_23 , V_2 , V_27 ) ;
if ( F_36 ( V_26 != 0 ) )
return V_26 ;
if ( V_27 -> V_44 )
break;
V_26 = F_78 ( V_9 , V_3 , V_2 ,
V_85 , V_86 ) ;
if ( F_36 ( V_26 != 0 ) )
return V_26 ;
} while ( 1 );
if ( V_27 -> V_44 == NULL )
return - V_80 ;
V_27 -> V_3 = V_3 ;
return 0 ;
}
static T_1 F_82 ( struct V_10 * V_11 ,
T_1 V_103 ,
T_1 V_138 )
{
T_1 V_139 = V_138 & V_91 ;
T_1 V_140 = V_138 & ~ V_91 ;
if ( ( V_103 & V_139 ) != 0 )
V_140 |= ( V_103 & V_139 ) ;
else if ( ( V_11 -> V_17 & V_139 ) != 0 )
V_140 |= V_11 -> V_17 ;
else if ( ( V_141 & V_139 ) != 0 )
V_140 |= V_141 ;
else if ( ( V_142 & V_139 ) != 0 )
V_140 |= V_142 ;
else if ( ( V_143 & V_139 ) != 0 )
V_140 |= V_143 ;
return V_140 ;
}
static bool F_83 ( struct V_10 * V_11 ,
T_1 V_3 ,
const struct V_1 * V_2 ,
T_1 * V_144 )
{
T_1 V_145 = F_8 ( V_3 ) ;
if ( ( V_145 & V_2 -> V_6 & V_146 ) == 0 )
return false ;
if ( ( V_2 -> V_6 & V_11 -> V_16 ) == 0 )
return false ;
V_145 |= ( V_2 -> V_6 & V_11 -> V_16 ) ;
* V_144 = V_145 ;
return true ;
}
int F_77 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_83 * V_27 ,
bool V_85 ,
bool V_86 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 ;
T_1 V_3 = V_18 ;
T_1 V_145 = 0 ;
bool V_147 = false ;
bool V_148 = false ;
bool V_149 = false ;
int V_4 , V_26 ;
V_27 -> V_44 = NULL ;
for ( V_4 = 0 ; V_4 < V_25 -> V_29 ; ++ V_4 ) {
const struct V_1 * V_2 = & V_25 -> V_25 [ V_4 ] ;
V_26 = F_1 ( V_2 , & V_3 ) ;
if ( V_26 )
return V_26 ;
V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( ! V_11 -> V_12 || ! V_11 -> V_13 )
continue;
V_148 = F_83 ( V_11 , V_3 , V_2 ,
& V_145 ) ;
if ( ! V_148 )
continue;
V_147 = true ;
V_145 = F_82 ( V_11 , V_23 -> V_27 . V_25 ,
V_145 ) ;
F_84 ( & V_145 , V_2 -> V_6 ,
~ V_150 ) ;
if ( V_3 == V_18 )
break;
V_26 = (* V_11 -> V_19 -> V_137 )( V_11 , V_23 , V_2 , V_27 ) ;
if ( F_36 ( V_26 ) )
return V_26 ;
if ( V_27 -> V_44 )
break;
}
if ( ( V_148 && ( V_3 == V_18 ) ) || V_27 -> V_44 ) {
V_27 -> V_3 = V_3 ;
V_27 -> V_25 = V_145 ;
return 0 ;
}
for ( V_4 = 0 ; V_4 < V_25 -> V_132 ; ++ V_4 ) {
const struct V_1 * V_2 = & V_25 -> V_151 [ V_4 ] ;
V_26 = F_1 ( V_2 , & V_3 ) ;
if ( V_26 )
return V_26 ;
V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( ! V_11 -> V_12 || ! V_11 -> V_13 )
continue;
if ( ! F_83 ( V_11 , V_3 , V_2 , & V_145 ) )
continue;
V_147 = true ;
V_145 = F_82 ( V_11 , V_23 -> V_27 . V_25 ,
V_145 ) ;
F_84 ( & V_145 , V_2 -> V_6 ,
~ V_150 ) ;
if ( V_3 == V_18 ) {
V_27 -> V_3 = V_3 ;
V_27 -> V_25 = V_145 ;
V_27 -> V_44 = NULL ;
return 0 ;
}
V_26 = F_81 ( V_23 , V_3 , V_2 , V_27 ,
V_85 , V_86 ) ;
if ( V_26 == 0 && V_27 -> V_44 ) {
V_27 -> V_25 = V_145 ;
return 0 ;
}
if ( V_26 == - V_128 )
V_149 = true ;
}
if ( ! V_147 ) {
F_85 (KERN_ERR TTM_PFX L_16 ) ;
return - V_7 ;
}
return ( V_149 ) ? - V_128 : - V_80 ;
}
static int F_86 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
bool V_85 ,
bool V_86 )
{
int V_26 = 0 ;
struct V_83 V_27 ;
F_19 ( & V_23 -> V_48 -> V_53 . V_54 ) ;
if ( V_23 -> V_27 . V_3 != V_18 || V_23 -> V_47 != NULL ) {
V_26 = F_58 ( V_23 , V_85 , V_86 ) ;
if ( V_26 )
return V_26 ;
}
V_27 . V_28 = V_23 -> V_28 ;
V_27 . V_15 = V_27 . V_28 << V_78 ;
V_27 . V_152 = V_23 -> V_27 . V_152 ;
V_27 . V_129 . V_130 = false ;
V_27 . V_129 . V_131 = 0 ;
V_26 = F_77 ( V_23 , V_25 , & V_27 ,
V_85 , V_86 ) ;
if ( V_26 )
goto V_117;
V_26 = F_37 ( V_23 , & V_27 , false ,
V_85 , V_86 ) ;
V_117:
if ( V_26 && V_27 . V_44 )
F_48 ( V_23 , & V_27 ) ;
return V_26 ;
}
bool F_87 ( struct V_24 * V_25 ,
struct V_83 * V_27 ,
T_1 * V_153 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_25 -> V_29 ; V_4 ++ ) {
const struct V_1 * V_154 = & V_25 -> V_25 [ V_4 ] ;
if ( V_27 -> V_44 &&
( V_27 -> V_102 < V_154 -> V_134 ||
( V_154 -> V_135 != 0 && ( V_27 -> V_102 + V_27 -> V_28 ) > V_154 -> V_135 ) ) )
continue;
* V_153 = V_154 -> V_6 ;
if ( ( * V_153 & V_27 -> V_25 & V_91 ) &&
( * V_153 & V_27 -> V_25 & V_146 ) )
return true ;
}
for ( V_4 = 0 ; V_4 < V_25 -> V_132 ; V_4 ++ ) {
const struct V_1 * V_154 = & V_25 -> V_151 [ V_4 ] ;
if ( V_27 -> V_44 &&
( V_27 -> V_102 < V_154 -> V_134 ||
( V_154 -> V_135 != 0 && ( V_27 -> V_102 + V_27 -> V_28 ) > V_154 -> V_135 ) ) )
continue;
* V_153 = V_154 -> V_6 ;
if ( ( * V_153 & V_27 -> V_25 & V_91 ) &&
( * V_153 & V_27 -> V_25 & V_146 ) )
return true ;
}
return false ;
}
int F_88 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
bool V_85 ,
bool V_86 )
{
int V_26 ;
T_1 V_153 ;
F_19 ( & V_23 -> V_48 -> V_53 . V_54 ) ;
if ( ! F_87 ( V_25 , & V_23 -> V_27 , & V_153 ) ) {
V_26 = F_86 ( V_23 , V_25 , V_85 ,
V_86 ) ;
if ( V_26 )
return V_26 ;
} else {
F_84 ( & V_23 -> V_27 . V_25 , V_153 ,
~ V_150 ) ;
}
if ( V_23 -> V_27 . V_3 == V_18 && V_23 -> V_47 == NULL ) {
V_26 = F_34 ( V_23 , true ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
int F_89 ( struct V_8 * V_9 ,
struct V_22 * V_23 ,
unsigned long V_15 ,
enum V_155 type ,
struct V_24 * V_25 ,
T_1 V_152 ,
bool V_85 ,
struct V_156 * V_157 ,
T_3 V_41 ,
struct V_158 * V_82 ,
struct V_159 * V_48 ,
void (* V_51) ( struct V_22 * ) )
{
int V_26 = 0 ;
unsigned long V_28 ;
struct V_160 * V_52 = V_9 -> V_36 -> V_52 ;
bool V_161 ;
V_26 = F_90 ( V_52 , V_41 , false , false ) ;
if ( V_26 ) {
F_3 ( L_17 ) ;
if ( V_51 )
(* V_51)( V_23 ) ;
else
F_16 ( V_23 ) ;
return - V_80 ;
}
V_28 = ( V_15 + V_37 - 1 ) >> V_78 ;
if ( V_28 == 0 ) {
F_3 ( L_18 ) ;
if ( V_51 )
(* V_51)( V_23 ) ;
else
F_16 ( V_23 ) ;
F_17 ( V_52 , V_41 ) ;
return - V_7 ;
}
V_23 -> V_51 = V_51 ;
F_91 ( & V_23 -> V_39 ) ;
F_91 ( & V_23 -> V_40 ) ;
F_92 ( & V_23 -> V_43 , 0 ) ;
F_93 ( & V_23 -> V_45 ) ;
F_93 ( & V_23 -> V_46 ) ;
F_93 ( & V_23 -> V_60 ) ;
F_93 ( & V_23 -> V_162 ) ;
F_94 ( & V_23 -> V_50 ) ;
V_23 -> V_9 = V_9 ;
V_23 -> V_36 = V_9 -> V_36 ;
V_23 -> type = type ;
V_23 -> V_28 = V_28 ;
V_23 -> V_27 . V_15 = V_28 << V_78 ;
V_23 -> V_27 . V_3 = V_18 ;
V_23 -> V_27 . V_28 = V_23 -> V_28 ;
V_23 -> V_27 . V_44 = NULL ;
V_23 -> V_27 . V_152 = V_152 ;
V_23 -> V_27 . V_129 . V_130 = false ;
V_23 -> V_27 . V_129 . V_131 = 0 ;
V_23 -> V_163 = 0 ;
V_23 -> V_27 . V_25 = ( V_164 | V_141 ) ;
V_23 -> V_157 = V_157 ;
V_23 -> V_41 = V_41 ;
V_23 -> V_82 = V_82 ;
if ( V_48 ) {
V_23 -> V_48 = V_48 ;
F_19 ( & V_23 -> V_48 -> V_53 . V_54 ) ;
} else {
V_23 -> V_48 = & V_23 -> V_49 ;
F_95 ( & V_23 -> V_49 ) ;
}
F_96 ( & V_23 -> V_36 -> V_38 ) ;
F_97 ( & V_23 -> V_124 ) ;
if ( V_23 -> type == V_74 ||
V_23 -> type == V_81 )
V_26 = F_98 ( & V_9 -> V_123 , & V_23 -> V_124 ,
V_23 -> V_27 . V_28 ) ;
if ( ! V_48 ) {
V_161 = F_99 ( & V_23 -> V_48 -> V_53 ) ;
F_64 ( ! V_161 ) ;
}
if ( F_100 ( ! V_26 ) )
V_26 = F_88 ( V_23 , V_25 , V_85 , false ) ;
if ( ! V_48 ) {
F_80 ( V_23 ) ;
} else if ( ! ( V_23 -> V_27 . V_25 & V_55 ) ) {
F_29 ( & V_23 -> V_36 -> V_66 ) ;
F_18 ( V_23 ) ;
F_30 ( & V_23 -> V_36 -> V_66 ) ;
}
if ( F_36 ( V_26 ) )
F_72 ( & V_23 ) ;
return V_26 ;
}
T_3 F_101 ( struct V_8 * V_9 ,
unsigned long V_165 ,
unsigned V_166 )
{
unsigned V_167 = ( F_102 ( V_165 ) ) >> V_78 ;
T_3 V_15 = 0 ;
V_15 += F_103 ( V_166 ) ;
V_15 += F_103 ( V_167 * sizeof( void * ) ) ;
V_15 += F_103 ( sizeof( struct V_168 ) ) ;
return V_15 ;
}
T_3 F_104 ( struct V_8 * V_9 ,
unsigned long V_165 ,
unsigned V_166 )
{
unsigned V_167 = ( F_102 ( V_165 ) ) >> V_78 ;
T_3 V_15 = 0 ;
V_15 += F_103 ( V_166 ) ;
V_15 += F_103 ( V_167 * ( 2 * sizeof( void * ) + sizeof( V_169 ) ) ) ;
V_15 += F_103 ( sizeof( struct V_170 ) ) ;
return V_15 ;
}
int F_105 ( struct V_8 * V_9 ,
unsigned long V_15 ,
enum V_155 type ,
struct V_24 * V_25 ,
T_1 V_152 ,
bool V_85 ,
struct V_156 * V_157 ,
struct V_22 * * V_125 )
{
struct V_22 * V_23 ;
T_3 V_41 ;
int V_26 ;
V_23 = F_106 ( sizeof( * V_23 ) , V_171 ) ;
if ( F_36 ( V_23 == NULL ) )
return - V_80 ;
V_41 = F_101 ( V_9 , V_15 , sizeof( struct V_22 ) ) ;
V_26 = F_89 ( V_9 , V_23 , V_15 , type , V_25 , V_152 ,
V_85 , V_157 , V_41 ,
NULL , NULL , NULL ) ;
if ( F_100 ( V_26 == 0 ) )
* V_125 = V_23 ;
return V_26 ;
}
static int F_107 ( struct V_8 * V_9 ,
unsigned V_3 , bool V_172 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
struct V_35 * V_36 = V_9 -> V_36 ;
int V_26 ;
F_29 ( & V_36 -> V_66 ) ;
while ( ! F_11 ( & V_11 -> V_45 ) ) {
F_30 ( & V_36 -> V_66 ) ;
V_26 = F_78 ( V_9 , V_3 , NULL , false , false ) ;
if ( V_26 ) {
if ( V_172 ) {
return V_26 ;
} else {
F_3 ( L_19 ) ;
}
}
F_29 ( & V_36 -> V_66 ) ;
}
F_30 ( & V_36 -> V_66 ) ;
return 0 ;
}
int F_108 ( struct V_8 * V_9 , unsigned V_3 )
{
struct V_10 * V_11 ;
int V_26 = - V_7 ;
if ( V_3 >= V_173 ) {
F_3 ( L_20 , V_3 ) ;
return V_26 ;
}
V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( ! V_11 -> V_12 ) {
F_3 ( L_21 ,
V_3 ) ;
return V_26 ;
}
V_11 -> V_13 = false ;
V_11 -> V_12 = false ;
V_26 = 0 ;
if ( V_3 > 0 ) {
F_107 ( V_9 , V_3 , false ) ;
V_26 = (* V_11 -> V_19 -> V_174 )( V_11 ) ;
}
return V_26 ;
}
int F_109 ( struct V_8 * V_9 , unsigned V_3 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( V_3 == 0 || V_3 >= V_173 ) {
F_3 ( L_22 , V_3 ) ;
return - V_7 ;
}
if ( ! V_11 -> V_12 ) {
F_3 ( L_23 , V_3 ) ;
return 0 ;
}
return F_107 ( V_9 , V_3 , true ) ;
}
int F_110 ( struct V_8 * V_9 , unsigned type ,
unsigned long V_175 )
{
int V_26 = - V_7 ;
struct V_10 * V_11 ;
F_10 ( type >= V_173 ) ;
V_11 = & V_9 -> V_11 [ type ] ;
F_10 ( V_11 -> V_12 ) ;
V_11 -> V_176 = true ;
V_11 -> V_177 = false ;
F_94 ( & V_11 -> V_178 ) ;
F_93 ( & V_11 -> V_162 ) ;
V_26 = V_9 -> V_56 -> V_179 ( V_9 , type , V_11 ) ;
if ( V_26 )
return V_26 ;
V_11 -> V_9 = V_9 ;
V_26 = 0 ;
if ( type != V_18 ) {
V_26 = (* V_11 -> V_19 -> V_180 )( V_11 , V_175 ) ;
if ( V_26 )
return V_26 ;
}
V_11 -> V_12 = true ;
V_11 -> V_13 = true ;
V_11 -> V_15 = V_175 ;
F_93 ( & V_11 -> V_45 ) ;
return 0 ;
}
static void F_111 ( struct V_30 * V_31 )
{
struct V_35 * V_36 =
F_6 ( V_31 , struct V_35 , V_31 ) ;
F_112 ( V_36 -> V_52 , & V_36 -> V_181 ) ;
F_113 ( V_36 -> V_79 ) ;
F_16 ( V_36 ) ;
}
void F_114 ( struct V_182 * V_183 )
{
struct V_35 * V_36 = V_183 -> V_184 ;
F_115 ( & V_36 -> V_31 ) ;
F_116 ( & V_36 -> V_31 ) ;
}
int F_117 ( struct V_182 * V_183 )
{
struct V_185 * V_186 =
F_6 ( V_183 , struct V_185 , V_183 ) ;
struct V_35 * V_36 = V_183 -> V_184 ;
int V_26 ;
F_94 ( & V_36 -> V_187 ) ;
F_118 ( & V_36 -> V_66 ) ;
V_36 -> V_52 = V_186 -> V_52 ;
V_36 -> V_79 = F_119 ( V_188 | V_189 ) ;
if ( F_36 ( V_36 -> V_79 == NULL ) ) {
V_26 = - V_80 ;
goto V_190;
}
F_93 ( & V_36 -> V_69 ) ;
F_93 ( & V_36 -> V_191 ) ;
F_120 ( & V_36 -> V_181 , V_192 ) ;
V_26 = F_121 ( V_36 -> V_52 , & V_36 -> V_181 ) ;
if ( F_36 ( V_26 != 0 ) ) {
F_3 ( L_24 ) ;
goto V_193;
}
F_92 ( & V_36 -> V_38 , 0 ) ;
V_26 = F_122 (
& V_36 -> V_31 , & V_194 , F_123 () , L_25 ) ;
if ( F_36 ( V_26 != 0 ) )
F_116 ( & V_36 -> V_31 ) ;
return V_26 ;
V_193:
F_113 ( V_36 -> V_79 ) ;
V_190:
F_16 ( V_36 ) ;
return V_26 ;
}
int F_124 ( struct V_8 * V_9 )
{
int V_26 = 0 ;
unsigned V_4 = V_173 ;
struct V_10 * V_11 ;
struct V_35 * V_36 = V_9 -> V_36 ;
while ( V_4 -- ) {
V_11 = & V_9 -> V_11 [ V_4 ] ;
if ( V_11 -> V_12 ) {
V_11 -> V_13 = false ;
if ( ( V_4 != V_18 ) && F_108 ( V_9 , V_4 ) ) {
V_26 = - V_114 ;
F_3 ( L_26 ,
V_4 ) ;
}
V_11 -> V_12 = false ;
}
}
F_125 ( & V_36 -> V_187 ) ;
F_126 ( & V_9 -> V_191 ) ;
F_127 ( & V_36 -> V_187 ) ;
F_74 ( & V_9 -> V_111 ) ;
while ( F_65 ( V_9 , true ) )
;
F_29 ( & V_36 -> V_66 ) ;
if ( F_11 ( & V_9 -> V_46 ) )
F_128 ( L_27 ) ;
if ( F_11 ( & V_9 -> V_11 [ 0 ] . V_45 ) )
F_128 ( L_28 ) ;
F_30 ( & V_36 -> V_66 ) ;
F_129 ( & V_9 -> V_123 ) ;
return V_26 ;
}
int F_130 ( struct V_8 * V_9 ,
struct V_35 * V_36 ,
struct V_195 * V_56 ,
struct V_196 * V_197 ,
T_4 V_198 ,
bool V_72 )
{
int V_26 = - V_7 ;
V_9 -> V_56 = V_56 ;
memset ( V_9 -> V_11 , 0 , sizeof( V_9 -> V_11 ) ) ;
V_26 = F_110 ( V_9 , V_18 , 0 ) ;
if ( F_36 ( V_26 != 0 ) )
goto V_199;
F_131 ( & V_9 -> V_123 , V_198 ,
0x10000000 ) ;
F_132 ( & V_9 -> V_111 , F_68 ) ;
F_93 ( & V_9 -> V_46 ) ;
V_9 -> V_200 = V_197 ;
V_9 -> V_36 = V_36 ;
V_9 -> V_72 = V_72 ;
F_125 ( & V_36 -> V_187 ) ;
F_60 ( & V_9 -> V_191 , & V_36 -> V_191 ) ;
F_127 ( & V_36 -> V_187 ) ;
return 0 ;
V_199:
return V_26 ;
}
bool F_38 ( struct V_8 * V_9 , struct V_83 * V_27 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_27 -> V_3 ] ;
if ( ! ( V_11 -> V_6 & V_93 ) ) {
if ( V_27 -> V_3 == V_18 )
return false ;
if ( V_11 -> V_6 & V_201 )
return false ;
if ( V_27 -> V_25 & V_141 )
return false ;
}
return true ;
}
void F_40 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
F_133 ( & V_23 -> V_124 , V_9 -> V_200 ) ;
F_71 ( V_23 ) ;
}
void F_134 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_23 -> V_27 . V_3 ] ;
F_39 ( V_11 , false ) ;
F_40 ( V_23 ) ;
F_41 ( V_11 ) ;
}
int F_58 ( struct V_22 * V_23 ,
bool V_85 , bool V_202 )
{
struct V_104 * V_105 ;
struct V_159 * V_48 ;
struct V_106 * V_203 ;
long V_204 = 15 * V_112 ;
int V_4 ;
V_48 = V_23 -> V_48 ;
V_105 = F_51 ( V_48 ) ;
V_203 = F_52 ( V_48 ) ;
if ( V_203 ) {
if ( ! F_135 ( V_203 ) ) {
if ( V_202 )
return - V_114 ;
V_204 = F_136 ( V_203 ,
V_85 , V_204 ) ;
}
}
for ( V_4 = 0 ; V_105 && V_204 > 0 && V_4 < V_105 -> V_109 ; ++ V_4 ) {
struct V_106 * V_106 ;
V_106 = F_54 ( V_105 -> V_110 [ V_4 ] ,
F_55 ( V_48 ) ) ;
if ( ! F_135 ( V_106 ) ) {
if ( V_202 )
return - V_114 ;
V_204 = F_136 ( V_106 ,
V_85 , V_204 ) ;
}
}
if ( V_204 < 0 )
return V_204 ;
if ( V_204 == 0 )
return - V_114 ;
F_137 ( V_48 , NULL ) ;
F_138 ( V_205 , & V_23 -> V_163 ) ;
return 0 ;
}
int F_139 ( struct V_22 * V_23 , bool V_202 )
{
int V_26 = 0 ;
V_26 = F_140 ( V_23 , true , V_202 , NULL ) ;
if ( F_36 ( V_26 != 0 ) )
return V_26 ;
V_26 = F_58 ( V_23 , true , V_202 ) ;
if ( F_100 ( V_26 == 0 ) )
F_96 ( & V_23 -> V_43 ) ;
F_80 ( V_23 ) ;
return V_26 ;
}
void F_141 ( struct V_22 * V_23 )
{
F_13 ( & V_23 -> V_43 ) ;
}
static int V_192 ( struct V_206 * V_181 )
{
struct V_35 * V_36 =
F_6 ( V_181 , struct V_35 , V_181 ) ;
struct V_22 * V_23 ;
int V_26 = - V_114 ;
int V_62 ;
T_1 V_207 = ( V_141 | V_164 ) ;
F_29 ( & V_36 -> V_66 ) ;
F_79 (bo, &glob->swap_lru, swap) {
V_26 = F_57 ( V_23 , false , true , NULL ) ;
if ( ! V_26 )
break;
}
if ( V_26 ) {
F_30 ( & V_36 -> V_66 ) ;
return V_26 ;
}
F_21 ( & V_23 -> V_40 ) ;
if ( ! F_11 ( & V_23 -> V_46 ) ) {
V_26 = F_62 ( V_23 , false , false ) ;
F_67 ( & V_23 -> V_40 , F_9 ) ;
return V_26 ;
}
V_62 = F_22 ( V_23 ) ;
F_30 ( & V_36 -> V_66 ) ;
F_26 ( V_23 , V_62 , true ) ;
V_26 = F_58 ( V_23 , false , false ) ;
if ( F_36 ( V_26 != 0 ) )
goto V_120;
if ( ( V_23 -> V_27 . V_25 & V_207 ) != V_207 ) {
struct V_83 V_127 ;
V_127 = V_23 -> V_27 ;
V_127 . V_44 = NULL ;
V_127 . V_25 = V_164 | V_141 ;
V_127 . V_3 = V_18 ;
V_26 = F_37 ( V_23 , & V_127 , true ,
false , false ) ;
if ( F_36 ( V_26 != 0 ) )
goto V_120;
}
F_134 ( V_23 ) ;
if ( V_23 -> V_9 -> V_56 -> V_208 )
V_23 -> V_9 -> V_56 -> V_208 ( V_23 ) ;
V_26 = F_142 ( V_23 -> V_47 , V_23 -> V_157 ) ;
V_120:
F_59 ( V_23 ) ;
F_67 ( & V_23 -> V_40 , F_9 ) ;
return V_26 ;
}
void F_143 ( struct V_8 * V_9 )
{
while ( V_192 ( & V_9 -> V_36 -> V_181 ) == 0 )
;
}
int F_144 ( struct V_22 * V_23 )
{
int V_26 ;
V_26 = F_145 ( & V_23 -> V_50 ) ;
if ( F_36 ( V_26 != 0 ) )
return - V_128 ;
if ( ! F_146 ( & V_23 -> V_48 -> V_53 ) )
goto V_117;
V_26 = F_57 ( V_23 , true , false , NULL ) ;
if ( F_36 ( V_26 != 0 ) )
goto V_117;
F_59 ( V_23 ) ;
V_117:
F_127 ( & V_23 -> V_50 ) ;
return V_26 ;
}
