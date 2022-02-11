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
F_5 ( L_1 , V_11 -> V_12 ) ;
F_5 ( L_2 , V_11 -> V_13 ) ;
F_5 ( L_3 , V_11 -> V_5 ) ;
F_5 ( L_4 , V_11 -> V_14 ) ;
F_5 ( L_5 , V_11 -> V_15 ) ;
F_5 ( L_6 , V_11 -> V_16 ) ;
F_5 ( L_7 , V_11 -> V_17 ) ;
if ( V_3 != V_18 )
(* V_11 -> V_19 -> V_20 )( V_11 , V_21 ) ;
}
static void F_6 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
int V_26 , V_27 , V_3 ;
F_5 ( L_8 ,
V_23 , V_23 -> V_28 . V_29 , V_23 -> V_28 . V_15 >> 10 ,
V_23 -> V_28 . V_15 >> 20 ) ;
for ( V_26 = 0 ; V_26 < V_25 -> V_30 ; V_26 ++ ) {
V_27 = F_1 ( & V_25 -> V_25 [ V_26 ] ,
& V_3 ) ;
if ( V_27 )
return;
F_5 ( L_9 ,
V_26 , V_25 -> V_25 [ V_26 ] . V_5 , V_3 ) ;
F_4 ( V_23 -> V_9 , V_3 ) ;
}
}
static T_2 F_7 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_35 )
{
struct V_36 * V_37 =
F_8 ( V_32 , struct V_36 , V_32 ) ;
return snprintf ( V_35 , V_38 , L_10 ,
( unsigned long ) F_9 ( & V_37 -> V_39 ) ) ;
}
static inline T_1 F_10 ( unsigned type )
{
return 1 << ( type ) ;
}
static void F_11 ( struct V_40 * V_41 )
{
struct V_22 * V_23 =
F_8 ( V_41 , struct V_22 , V_41 ) ;
struct V_8 * V_9 = V_23 -> V_9 ;
T_3 V_42 = V_23 -> V_42 ;
F_12 ( F_9 ( & V_23 -> V_41 . V_43 ) ) ;
F_12 ( F_9 ( & V_23 -> V_40 . V_43 ) ) ;
F_12 ( F_9 ( & V_23 -> V_44 ) ) ;
F_12 ( V_23 -> V_28 . V_45 != NULL ) ;
F_12 ( ! F_13 ( & V_23 -> V_46 ) ) ;
F_12 ( ! F_13 ( & V_23 -> V_47 ) ) ;
F_14 ( V_23 -> V_48 ) ;
F_15 ( & V_23 -> V_37 -> V_39 ) ;
F_16 ( V_23 -> V_49 ) ;
if ( V_23 -> V_50 == & V_23 -> V_51 )
F_17 ( & V_23 -> V_51 ) ;
F_18 ( & V_23 -> V_52 ) ;
if ( V_23 -> V_53 )
V_23 -> V_53 ( V_23 ) ;
else {
F_19 ( V_23 ) ;
}
F_20 ( V_9 -> V_37 -> V_54 , V_42 ) ;
}
void F_21 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
F_22 ( & V_23 -> V_50 -> V_55 . V_56 ) ;
if ( ! ( V_23 -> V_28 . V_25 & V_57 ) ) {
F_12 ( ! F_13 ( & V_23 -> V_46 ) ) ;
F_23 ( & V_23 -> V_46 , V_9 -> V_58 -> V_59 ( V_23 ) ) ;
F_24 ( & V_23 -> V_41 ) ;
if ( V_23 -> V_48 && ! ( V_23 -> V_48 -> V_60 & V_61 ) ) {
F_23 ( & V_23 -> V_62 , V_9 -> V_58 -> V_63 ( V_23 ) ) ;
F_24 ( & V_23 -> V_41 ) ;
}
}
}
int F_25 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
int V_64 = 0 ;
if ( V_9 -> V_58 -> V_65 )
V_9 -> V_58 -> V_65 ( V_23 ) ;
if ( ! F_13 ( & V_23 -> V_62 ) ) {
F_26 ( & V_23 -> V_62 ) ;
++ V_64 ;
}
if ( ! F_13 ( & V_23 -> V_46 ) ) {
F_26 ( & V_23 -> V_46 ) ;
++ V_64 ;
}
return V_64 ;
}
static void F_27 ( struct V_40 * V_41 )
{
F_28 () ;
}
void F_29 ( struct V_22 * V_23 , int V_66 ,
bool V_67 )
{
F_30 ( & V_23 -> V_41 , V_66 ,
( V_67 ) ? F_27 : F_11 ) ;
}
void F_31 ( struct V_22 * V_23 )
{
int V_64 ;
F_32 ( & V_23 -> V_37 -> V_68 ) ;
V_64 = F_25 ( V_23 ) ;
F_33 ( & V_23 -> V_37 -> V_68 ) ;
F_29 ( V_23 , V_64 , true ) ;
}
void F_34 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
int V_64 = 0 ;
F_22 ( & V_23 -> V_50 -> V_55 . V_56 ) ;
if ( V_9 -> V_58 -> V_65 )
V_9 -> V_58 -> V_65 ( V_23 ) ;
V_64 = F_25 ( V_23 ) ;
F_29 ( V_23 , V_64 , true ) ;
F_21 ( V_23 ) ;
}
struct V_69 * F_35 ( struct V_22 * V_23 )
{
return V_23 -> V_9 -> V_11 [ V_23 -> V_28 . V_3 ] . V_46 . V_70 ;
}
struct V_69 * F_36 ( struct V_22 * V_23 )
{
return V_23 -> V_37 -> V_71 . V_70 ;
}
static int F_37 ( struct V_22 * V_23 , bool V_72 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_36 * V_37 = V_23 -> V_37 ;
int V_27 = 0 ;
T_1 V_60 = 0 ;
F_38 ( & V_23 -> V_73 ) ;
V_23 -> V_48 = NULL ;
if ( V_9 -> V_74 )
V_60 |= V_75 ;
switch ( V_23 -> type ) {
case V_76 :
if ( V_72 )
V_60 |= V_77 ;
case V_78 :
V_23 -> V_48 = V_9 -> V_58 -> V_79 ( V_9 , V_23 -> V_29 << V_80 ,
V_60 , V_37 -> V_81 ) ;
if ( F_3 ( V_23 -> V_48 == NULL ) )
V_27 = - V_82 ;
break;
case V_83 :
V_23 -> V_48 = V_9 -> V_58 -> V_79 ( V_9 , V_23 -> V_29 << V_80 ,
V_60 | V_61 ,
V_37 -> V_81 ) ;
if ( F_3 ( V_23 -> V_48 == NULL ) ) {
V_27 = - V_82 ;
break;
}
V_23 -> V_48 -> V_84 = V_23 -> V_84 ;
break;
default:
F_5 ( L_11 ) ;
V_27 = - V_7 ;
break;
}
return V_27 ;
}
static int F_39 ( struct V_22 * V_23 ,
struct V_85 * V_28 ,
bool V_86 , bool V_87 ,
bool V_88 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
bool V_89 = F_40 ( V_9 , & V_23 -> V_28 ) ;
bool V_90 = F_40 ( V_9 , V_28 ) ;
struct V_10 * V_91 = & V_9 -> V_11 [ V_23 -> V_28 . V_3 ] ;
struct V_10 * V_92 = & V_9 -> V_11 [ V_28 -> V_3 ] ;
int V_27 = 0 ;
if ( V_89 || V_90 ||
( ( V_28 -> V_25 & V_23 -> V_28 . V_25 & V_93 ) == 0 ) ) {
V_27 = F_41 ( V_91 , true ) ;
if ( F_3 ( V_27 != 0 ) )
goto V_94;
F_42 ( V_23 ) ;
F_43 ( V_91 ) ;
}
if ( ! ( V_92 -> V_5 & V_95 ) ) {
if ( V_23 -> V_48 == NULL ) {
bool V_96 = ! ( V_91 -> V_5 & V_95 ) ;
V_27 = F_37 ( V_23 , V_96 ) ;
if ( V_27 )
goto V_94;
}
V_27 = F_44 ( V_23 -> V_48 , V_28 -> V_25 ) ;
if ( V_27 )
goto V_94;
if ( V_28 -> V_3 != V_18 ) {
V_27 = F_45 ( V_23 -> V_48 , V_28 ) ;
if ( V_27 )
goto V_94;
}
if ( V_23 -> V_28 . V_3 == V_18 ) {
if ( V_9 -> V_58 -> V_97 )
V_9 -> V_58 -> V_97 ( V_23 , V_28 ) ;
V_23 -> V_28 = * V_28 ;
V_28 -> V_45 = NULL ;
goto V_98;
}
}
if ( V_9 -> V_58 -> V_97 )
V_9 -> V_58 -> V_97 ( V_23 , V_28 ) ;
if ( ! ( V_91 -> V_5 & V_95 ) &&
! ( V_92 -> V_5 & V_95 ) )
V_27 = F_46 ( V_23 , V_87 , V_88 , V_28 ) ;
else if ( V_9 -> V_58 -> V_99 )
V_27 = V_9 -> V_58 -> V_99 ( V_23 , V_86 , V_87 ,
V_88 , V_28 ) ;
else
V_27 = F_47 ( V_23 , V_87 , V_88 , V_28 ) ;
if ( V_27 ) {
if ( V_9 -> V_58 -> V_97 ) {
struct V_85 V_100 = * V_28 ;
* V_28 = V_23 -> V_28 ;
V_23 -> V_28 = V_100 ;
V_9 -> V_58 -> V_97 ( V_23 , V_28 ) ;
V_23 -> V_28 = * V_28 ;
* V_28 = V_100 ;
}
goto V_94;
}
V_98:
if ( V_23 -> V_101 ) {
if ( V_9 -> V_58 -> V_102 ) {
V_27 = V_9 -> V_58 -> V_102 ( V_9 , V_23 -> V_28 . V_25 ) ;
if ( V_27 )
F_5 ( L_12 ) ;
}
V_23 -> V_101 = false ;
}
if ( V_23 -> V_28 . V_45 ) {
V_23 -> V_103 = ( V_23 -> V_28 . V_104 << V_80 ) +
V_9 -> V_11 [ V_23 -> V_28 . V_3 ] . V_14 ;
V_23 -> V_105 = V_23 -> V_28 . V_25 ;
} else
V_23 -> V_103 = 0 ;
return 0 ;
V_94:
V_92 = & V_9 -> V_11 [ V_23 -> V_28 . V_3 ] ;
if ( V_92 -> V_5 & V_95 ) {
F_14 ( V_23 -> V_48 ) ;
V_23 -> V_48 = NULL ;
}
return V_27 ;
}
static void F_48 ( struct V_22 * V_23 )
{
if ( V_23 -> V_9 -> V_58 -> V_97 )
V_23 -> V_9 -> V_58 -> V_97 ( V_23 , NULL ) ;
F_14 ( V_23 -> V_48 ) ;
V_23 -> V_48 = NULL ;
F_49 ( V_23 , & V_23 -> V_28 ) ;
F_50 ( & V_23 -> V_50 -> V_55 ) ;
}
static void F_51 ( struct V_22 * V_23 )
{
struct V_106 * V_107 ;
struct V_108 * V_109 ;
int V_26 ;
V_107 = F_52 ( V_23 -> V_50 ) ;
V_109 = F_53 ( V_23 -> V_50 ) ;
if ( V_109 && ! V_109 -> V_110 -> V_111 )
F_54 ( V_109 ) ;
for ( V_26 = 0 ; V_107 && V_26 < V_107 -> V_112 ; ++ V_26 ) {
V_109 = F_55 ( V_107 -> V_113 [ V_26 ] ,
F_56 ( V_23 -> V_50 ) ) ;
if ( ! V_109 -> V_110 -> V_111 )
F_54 ( V_109 ) ;
}
}
static void F_57 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_36 * V_37 = V_23 -> V_37 ;
int V_64 ;
int V_27 ;
F_32 ( & V_37 -> V_68 ) ;
V_27 = F_58 ( V_23 , false , true , NULL ) ;
if ( ! V_27 ) {
if ( ! F_59 ( V_23 , false , true ) ) {
V_64 = F_25 ( V_23 ) ;
F_33 ( & V_37 -> V_68 ) ;
F_48 ( V_23 ) ;
F_29 ( V_23 , V_64 , true ) ;
return;
} else
F_51 ( V_23 ) ;
if ( V_23 -> V_28 . V_25 & V_57 ) {
V_23 -> V_28 . V_25 &= ~ V_57 ;
F_21 ( V_23 ) ;
}
F_60 ( V_23 ) ;
}
F_24 ( & V_23 -> V_41 ) ;
F_61 ( & V_23 -> V_47 , & V_9 -> V_47 ) ;
F_33 ( & V_37 -> V_68 ) ;
F_62 ( & V_9 -> V_114 ,
( ( V_115 / 100 ) < 1 ) ? 1 : V_115 / 100 ) ;
}
static int F_63 ( struct V_22 * V_23 ,
bool V_87 ,
bool V_88 )
{
struct V_36 * V_37 = V_23 -> V_37 ;
int V_64 ;
int V_27 ;
V_27 = F_59 ( V_23 , false , true ) ;
if ( V_27 && ! V_88 ) {
long V_116 ;
F_50 ( & V_23 -> V_50 -> V_55 ) ;
F_33 ( & V_37 -> V_68 ) ;
V_116 = F_64 ( V_23 -> V_50 ,
true ,
V_87 ,
30 * V_115 ) ;
if ( V_116 < 0 )
return V_116 ;
else if ( V_116 == 0 )
return - V_117 ;
F_32 ( & V_37 -> V_68 ) ;
V_27 = F_58 ( V_23 , false , true , NULL ) ;
if ( V_27 ) {
F_33 ( & V_37 -> V_68 ) ;
return 0 ;
}
V_27 = F_59 ( V_23 , false , true ) ;
F_65 ( V_27 ) ;
}
if ( V_27 || F_3 ( F_13 ( & V_23 -> V_47 ) ) ) {
F_60 ( V_23 ) ;
F_33 ( & V_37 -> V_68 ) ;
return V_27 ;
}
V_64 = F_25 ( V_23 ) ;
F_26 ( & V_23 -> V_47 ) ;
++ V_64 ;
F_33 ( & V_37 -> V_68 ) ;
F_48 ( V_23 ) ;
F_29 ( V_23 , V_64 , true ) ;
return 0 ;
}
static int F_66 ( struct V_8 * V_9 , bool V_118 )
{
struct V_36 * V_37 = V_9 -> V_37 ;
struct V_22 * V_119 = NULL ;
int V_27 = 0 ;
F_32 ( & V_37 -> V_68 ) ;
if ( F_13 ( & V_9 -> V_47 ) )
goto V_120;
V_119 = F_67 ( & V_9 -> V_47 ,
struct V_22 , V_47 ) ;
F_24 ( & V_119 -> V_41 ) ;
for (; ; ) {
struct V_22 * V_121 = NULL ;
if ( V_119 -> V_47 . V_122 != & V_9 -> V_47 ) {
V_121 = F_67 ( & V_119 -> V_47 ,
struct V_22 , V_47 ) ;
F_24 ( & V_121 -> V_41 ) ;
}
V_27 = F_58 ( V_119 , false , true , NULL ) ;
if ( V_118 && V_27 ) {
F_33 ( & V_37 -> V_68 ) ;
V_27 = F_58 ( V_119 , false , false , NULL ) ;
F_32 ( & V_37 -> V_68 ) ;
}
if ( ! V_27 )
V_27 = F_63 ( V_119 , false ,
! V_118 ) ;
else
F_33 ( & V_37 -> V_68 ) ;
F_68 ( & V_119 -> V_41 , F_11 ) ;
V_119 = V_121 ;
if ( V_27 || ! V_119 )
goto V_123;
F_32 ( & V_37 -> V_68 ) ;
if ( F_13 ( & V_119 -> V_47 ) )
break;
}
V_120:
F_33 ( & V_37 -> V_68 ) ;
V_123:
if ( V_119 )
F_68 ( & V_119 -> V_41 , F_11 ) ;
return V_27 ;
}
static void F_69 ( struct V_124 * V_125 )
{
struct V_8 * V_9 =
F_8 ( V_125 , struct V_8 , V_114 . V_125 ) ;
if ( F_66 ( V_9 , false ) ) {
F_62 ( & V_9 -> V_114 ,
( ( V_115 / 100 ) < 1 ) ? 1 : V_115 / 100 ) ;
}
}
static void F_70 ( struct V_40 * V_40 )
{
struct V_22 * V_23 =
F_8 ( V_40 , struct V_22 , V_40 ) ;
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_23 -> V_28 . V_3 ] ;
F_71 ( & V_9 -> V_126 , & V_23 -> V_127 ) ;
F_41 ( V_11 , false ) ;
F_72 ( V_23 ) ;
F_43 ( V_11 ) ;
F_57 ( V_23 ) ;
F_68 ( & V_23 -> V_41 , F_11 ) ;
}
void F_73 ( struct V_22 * * V_128 )
{
struct V_22 * V_23 = * V_128 ;
* V_128 = NULL ;
F_68 ( & V_23 -> V_40 , F_70 ) ;
}
int F_74 ( struct V_8 * V_9 )
{
return F_75 ( & V_9 -> V_114 ) ;
}
void F_76 ( struct V_8 * V_9 , int V_129 )
{
if ( V_129 )
F_62 ( & V_9 -> V_114 ,
( ( V_115 / 100 ) < 1 ) ? 1 : V_115 / 100 ) ;
}
static int F_77 ( struct V_22 * V_23 , bool V_87 ,
bool V_88 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_85 V_130 ;
struct V_24 V_25 ;
int V_27 = 0 ;
F_22 ( & V_23 -> V_50 -> V_55 . V_56 ) ;
V_130 = V_23 -> V_28 ;
V_130 . V_45 = NULL ;
V_130 . V_131 . V_132 = false ;
V_130 . V_131 . V_133 = 0 ;
V_25 . V_30 = 0 ;
V_25 . V_134 = 0 ;
V_9 -> V_58 -> V_135 ( V_23 , & V_25 ) ;
V_27 = F_78 ( V_23 , & V_25 , & V_130 , V_87 ,
V_88 ) ;
if ( V_27 ) {
if ( V_27 != - V_136 ) {
F_5 ( L_13 ,
V_23 ) ;
F_6 ( V_23 , & V_25 ) ;
}
goto V_123;
}
V_27 = F_39 ( V_23 , & V_130 , true , V_87 ,
V_88 ) ;
if ( F_3 ( V_27 ) ) {
if ( V_27 != - V_136 )
F_5 ( L_14 ) ;
F_49 ( V_23 , & V_130 ) ;
goto V_123;
}
V_23 -> V_101 = true ;
V_123:
return V_27 ;
}
bool F_79 ( struct V_22 * V_23 ,
const struct V_1 * V_2 )
{
if ( V_2 -> V_137 >= ( V_23 -> V_28 . V_104 + V_23 -> V_28 . V_15 ) ||
( V_2 -> V_138 && V_2 -> V_138 <= V_23 -> V_28 . V_104 ) )
return false ;
return true ;
}
static int F_80 ( struct V_8 * V_9 ,
T_1 V_3 ,
const struct V_1 * V_2 ,
bool V_87 ,
bool V_88 )
{
struct V_36 * V_37 = V_9 -> V_37 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
struct V_22 * V_23 ;
int V_27 = - V_117 , V_64 ;
F_32 ( & V_37 -> V_68 ) ;
F_81 (bo, &man->lru, lru) {
V_27 = F_58 ( V_23 , false , true , NULL ) ;
if ( V_27 )
continue;
if ( V_2 && ! V_9 -> V_58 -> V_139 ( V_23 , V_2 ) ) {
F_60 ( V_23 ) ;
V_27 = - V_117 ;
continue;
}
break;
}
if ( V_27 ) {
F_33 ( & V_37 -> V_68 ) ;
return V_27 ;
}
F_24 ( & V_23 -> V_41 ) ;
if ( ! F_13 ( & V_23 -> V_47 ) ) {
V_27 = F_63 ( V_23 , V_87 ,
V_88 ) ;
F_68 ( & V_23 -> V_41 , F_11 ) ;
return V_27 ;
}
V_64 = F_25 ( V_23 ) ;
F_33 ( & V_37 -> V_68 ) ;
F_12 ( V_27 != 0 ) ;
F_29 ( V_23 , V_64 , true ) ;
V_27 = F_77 ( V_23 , V_87 , V_88 ) ;
F_82 ( V_23 ) ;
F_68 ( & V_23 -> V_41 , F_11 ) ;
return V_27 ;
}
void F_49 ( struct V_22 * V_23 , struct V_85 * V_28 )
{
struct V_10 * V_11 = & V_23 -> V_9 -> V_11 [ V_28 -> V_3 ] ;
if ( V_28 -> V_45 )
(* V_11 -> V_19 -> V_140 )( V_11 , V_28 ) ;
}
static int F_83 ( struct V_22 * V_23 ,
struct V_10 * V_11 ,
struct V_85 * V_28 )
{
struct V_108 * V_109 ;
int V_27 ;
F_32 ( & V_11 -> V_141 ) ;
V_109 = F_84 ( V_11 -> V_99 ) ;
F_33 ( & V_11 -> V_141 ) ;
if ( V_109 ) {
F_85 ( V_23 -> V_50 , V_109 ) ;
V_27 = F_86 ( V_23 -> V_50 ) ;
if ( F_3 ( V_27 ) )
return V_27 ;
F_16 ( V_23 -> V_49 ) ;
V_23 -> V_49 = V_109 ;
}
return 0 ;
}
static int F_87 ( struct V_22 * V_23 ,
T_1 V_3 ,
const struct V_1 * V_2 ,
struct V_85 * V_28 ,
bool V_87 ,
bool V_88 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
int V_27 ;
do {
V_27 = (* V_11 -> V_19 -> V_142 )( V_11 , V_23 , V_2 , V_28 ) ;
if ( F_3 ( V_27 != 0 ) )
return V_27 ;
if ( V_28 -> V_45 )
break;
V_27 = F_80 ( V_9 , V_3 , V_2 ,
V_87 , V_88 ) ;
if ( F_3 ( V_27 != 0 ) )
return V_27 ;
} while ( 1 );
V_28 -> V_3 = V_3 ;
return F_83 ( V_23 , V_11 , V_28 ) ;
}
static T_1 F_88 ( struct V_10 * V_11 ,
T_1 V_105 ,
T_1 V_143 )
{
T_1 V_144 = V_143 & V_93 ;
T_1 V_145 = V_143 & ~ V_93 ;
if ( ( V_105 & V_144 ) != 0 )
V_145 |= ( V_105 & V_144 ) ;
else if ( ( V_11 -> V_17 & V_144 ) != 0 )
V_145 |= V_11 -> V_17 ;
else if ( ( V_146 & V_144 ) != 0 )
V_145 |= V_146 ;
else if ( ( V_147 & V_144 ) != 0 )
V_145 |= V_147 ;
else if ( ( V_148 & V_144 ) != 0 )
V_145 |= V_148 ;
return V_145 ;
}
static bool F_89 ( struct V_10 * V_11 ,
T_1 V_3 ,
const struct V_1 * V_2 ,
T_1 * V_149 )
{
T_1 V_150 = F_10 ( V_3 ) ;
if ( ( V_150 & V_2 -> V_5 & V_6 ) == 0 )
return false ;
if ( ( V_2 -> V_5 & V_11 -> V_16 ) == 0 )
return false ;
V_150 |= ( V_2 -> V_5 & V_11 -> V_16 ) ;
* V_149 = V_150 ;
return true ;
}
int F_78 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_85 * V_28 ,
bool V_87 ,
bool V_88 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 ;
T_1 V_3 = V_18 ;
T_1 V_150 = 0 ;
bool V_151 = false ;
bool V_152 = false ;
bool V_153 = false ;
int V_26 , V_27 ;
V_27 = F_86 ( V_23 -> V_50 ) ;
if ( F_3 ( V_27 ) )
return V_27 ;
V_28 -> V_45 = NULL ;
for ( V_26 = 0 ; V_26 < V_25 -> V_30 ; ++ V_26 ) {
const struct V_1 * V_2 = & V_25 -> V_25 [ V_26 ] ;
V_27 = F_1 ( V_2 , & V_3 ) ;
if ( V_27 )
return V_27 ;
V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( ! V_11 -> V_12 || ! V_11 -> V_13 )
continue;
V_152 = F_89 ( V_11 , V_3 , V_2 ,
& V_150 ) ;
if ( ! V_152 )
continue;
V_151 = true ;
V_150 = F_88 ( V_11 , V_23 -> V_28 . V_25 ,
V_150 ) ;
F_90 ( & V_150 , V_2 -> V_5 ,
~ V_154 ) ;
if ( V_3 == V_18 )
break;
V_27 = (* V_11 -> V_19 -> V_142 )( V_11 , V_23 , V_2 , V_28 ) ;
if ( F_3 ( V_27 ) )
return V_27 ;
if ( V_28 -> V_45 ) {
V_27 = F_83 ( V_23 , V_11 , V_28 ) ;
if ( F_3 ( V_27 ) ) {
(* V_11 -> V_19 -> V_140 )( V_11 , V_28 ) ;
return V_27 ;
}
break;
}
}
if ( ( V_152 && ( V_3 == V_18 ) ) || V_28 -> V_45 ) {
V_28 -> V_3 = V_3 ;
V_28 -> V_25 = V_150 ;
return 0 ;
}
for ( V_26 = 0 ; V_26 < V_25 -> V_134 ; ++ V_26 ) {
const struct V_1 * V_2 = & V_25 -> V_155 [ V_26 ] ;
V_27 = F_1 ( V_2 , & V_3 ) ;
if ( V_27 )
return V_27 ;
V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( ! V_11 -> V_12 || ! V_11 -> V_13 )
continue;
if ( ! F_89 ( V_11 , V_3 , V_2 , & V_150 ) )
continue;
V_151 = true ;
V_150 = F_88 ( V_11 , V_23 -> V_28 . V_25 ,
V_150 ) ;
F_90 ( & V_150 , V_2 -> V_5 ,
~ V_154 ) ;
if ( V_3 == V_18 ) {
V_28 -> V_3 = V_3 ;
V_28 -> V_25 = V_150 ;
V_28 -> V_45 = NULL ;
return 0 ;
}
V_27 = F_87 ( V_23 , V_3 , V_2 , V_28 ,
V_87 , V_88 ) ;
if ( V_27 == 0 && V_28 -> V_45 ) {
V_28 -> V_25 = V_150 ;
return 0 ;
}
if ( V_27 == - V_136 )
V_153 = true ;
}
if ( ! V_151 ) {
F_91 (KERN_ERR TTM_PFX L_15 ) ;
return - V_7 ;
}
return ( V_153 ) ? - V_136 : - V_82 ;
}
static int F_92 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
bool V_87 ,
bool V_88 )
{
int V_27 = 0 ;
struct V_85 V_28 ;
F_22 ( & V_23 -> V_50 -> V_55 . V_56 ) ;
V_28 . V_29 = V_23 -> V_29 ;
V_28 . V_15 = V_28 . V_29 << V_80 ;
V_28 . V_156 = V_23 -> V_28 . V_156 ;
V_28 . V_131 . V_132 = false ;
V_28 . V_131 . V_133 = 0 ;
V_27 = F_78 ( V_23 , V_25 , & V_28 ,
V_87 , V_88 ) ;
if ( V_27 )
goto V_120;
V_27 = F_39 ( V_23 , & V_28 , false ,
V_87 , V_88 ) ;
V_120:
if ( V_27 && V_28 . V_45 )
F_49 ( V_23 , & V_28 ) ;
return V_27 ;
}
bool F_93 ( struct V_24 * V_25 ,
struct V_85 * V_28 ,
T_1 * V_157 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_25 -> V_30 ; V_26 ++ ) {
const struct V_1 * V_158 = & V_25 -> V_25 [ V_26 ] ;
if ( V_28 -> V_45 &&
( V_28 -> V_104 < V_158 -> V_137 ||
( V_158 -> V_138 != 0 && ( V_28 -> V_104 + V_28 -> V_29 ) > V_158 -> V_138 ) ) )
continue;
* V_157 = V_158 -> V_5 ;
if ( ( * V_157 & V_28 -> V_25 & V_93 ) &&
( * V_157 & V_28 -> V_25 & V_6 ) )
return true ;
}
for ( V_26 = 0 ; V_26 < V_25 -> V_134 ; V_26 ++ ) {
const struct V_1 * V_158 = & V_25 -> V_155 [ V_26 ] ;
if ( V_28 -> V_45 &&
( V_28 -> V_104 < V_158 -> V_137 ||
( V_158 -> V_138 != 0 && ( V_28 -> V_104 + V_28 -> V_29 ) > V_158 -> V_138 ) ) )
continue;
* V_157 = V_158 -> V_5 ;
if ( ( * V_157 & V_28 -> V_25 & V_93 ) &&
( * V_157 & V_28 -> V_25 & V_6 ) )
return true ;
}
return false ;
}
int F_94 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
bool V_87 ,
bool V_88 )
{
int V_27 ;
T_1 V_157 ;
F_22 ( & V_23 -> V_50 -> V_55 . V_56 ) ;
if ( ! F_93 ( V_25 , & V_23 -> V_28 , & V_157 ) ) {
V_27 = F_92 ( V_23 , V_25 , V_87 ,
V_88 ) ;
if ( V_27 )
return V_27 ;
} else {
F_90 ( & V_23 -> V_28 . V_25 , V_157 ,
~ V_154 ) ;
}
if ( V_23 -> V_28 . V_3 == V_18 && V_23 -> V_48 == NULL ) {
V_27 = F_37 ( V_23 , true ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
int F_95 ( struct V_8 * V_9 ,
struct V_22 * V_23 ,
unsigned long V_15 ,
enum V_159 type ,
struct V_24 * V_25 ,
T_1 V_156 ,
bool V_87 ,
struct V_160 * V_161 ,
T_3 V_42 ,
struct V_162 * V_84 ,
struct V_163 * V_50 ,
void (* V_53) ( struct V_22 * ) )
{
int V_27 = 0 ;
unsigned long V_29 ;
struct V_164 * V_54 = V_9 -> V_37 -> V_54 ;
bool V_165 ;
V_27 = F_96 ( V_54 , V_42 , false , false ) ;
if ( V_27 ) {
F_5 ( L_16 ) ;
if ( V_53 )
(* V_53)( V_23 ) ;
else
F_19 ( V_23 ) ;
return - V_82 ;
}
V_29 = ( V_15 + V_38 - 1 ) >> V_80 ;
if ( V_29 == 0 ) {
F_5 ( L_17 ) ;
if ( V_53 )
(* V_53)( V_23 ) ;
else
F_19 ( V_23 ) ;
F_20 ( V_54 , V_42 ) ;
return - V_7 ;
}
V_23 -> V_53 = V_53 ;
F_97 ( & V_23 -> V_40 ) ;
F_97 ( & V_23 -> V_41 ) ;
F_98 ( & V_23 -> V_44 , 0 ) ;
F_99 ( & V_23 -> V_46 ) ;
F_99 ( & V_23 -> V_47 ) ;
F_99 ( & V_23 -> V_62 ) ;
F_99 ( & V_23 -> V_166 ) ;
F_100 ( & V_23 -> V_52 ) ;
V_23 -> V_9 = V_9 ;
V_23 -> V_37 = V_9 -> V_37 ;
V_23 -> type = type ;
V_23 -> V_29 = V_29 ;
V_23 -> V_28 . V_15 = V_29 << V_80 ;
V_23 -> V_28 . V_3 = V_18 ;
V_23 -> V_28 . V_29 = V_23 -> V_29 ;
V_23 -> V_28 . V_45 = NULL ;
V_23 -> V_28 . V_156 = V_156 ;
V_23 -> V_28 . V_131 . V_132 = false ;
V_23 -> V_28 . V_131 . V_133 = 0 ;
V_23 -> V_49 = NULL ;
V_23 -> V_28 . V_25 = ( V_167 | V_146 ) ;
V_23 -> V_161 = V_161 ;
V_23 -> V_42 = V_42 ;
V_23 -> V_84 = V_84 ;
if ( V_50 ) {
V_23 -> V_50 = V_50 ;
F_22 ( & V_23 -> V_50 -> V_55 . V_56 ) ;
} else {
V_23 -> V_50 = & V_23 -> V_51 ;
F_101 ( & V_23 -> V_51 ) ;
}
F_102 ( & V_23 -> V_37 -> V_39 ) ;
F_103 ( & V_23 -> V_127 ) ;
if ( V_23 -> type == V_76 ||
V_23 -> type == V_83 )
V_27 = F_104 ( & V_9 -> V_126 , & V_23 -> V_127 ,
V_23 -> V_28 . V_29 ) ;
if ( ! V_50 ) {
V_165 = F_105 ( & V_23 -> V_50 -> V_55 ) ;
F_65 ( ! V_165 ) ;
}
if ( F_106 ( ! V_27 ) )
V_27 = F_94 ( V_23 , V_25 , V_87 , false ) ;
if ( ! V_50 ) {
F_82 ( V_23 ) ;
} else if ( ! ( V_23 -> V_28 . V_25 & V_57 ) ) {
F_32 ( & V_23 -> V_37 -> V_68 ) ;
F_21 ( V_23 ) ;
F_33 ( & V_23 -> V_37 -> V_68 ) ;
}
if ( F_3 ( V_27 ) )
F_73 ( & V_23 ) ;
return V_27 ;
}
T_3 F_107 ( struct V_8 * V_9 ,
unsigned long V_168 ,
unsigned V_169 )
{
unsigned V_170 = ( F_108 ( V_168 ) ) >> V_80 ;
T_3 V_15 = 0 ;
V_15 += F_109 ( V_169 ) ;
V_15 += F_109 ( V_170 * sizeof( void * ) ) ;
V_15 += F_109 ( sizeof( struct V_171 ) ) ;
return V_15 ;
}
T_3 F_110 ( struct V_8 * V_9 ,
unsigned long V_168 ,
unsigned V_169 )
{
unsigned V_170 = ( F_108 ( V_168 ) ) >> V_80 ;
T_3 V_15 = 0 ;
V_15 += F_109 ( V_169 ) ;
V_15 += F_109 ( V_170 * ( 2 * sizeof( void * ) + sizeof( V_172 ) ) ) ;
V_15 += F_109 ( sizeof( struct V_173 ) ) ;
return V_15 ;
}
int F_111 ( struct V_8 * V_9 ,
unsigned long V_15 ,
enum V_159 type ,
struct V_24 * V_25 ,
T_1 V_156 ,
bool V_87 ,
struct V_160 * V_161 ,
struct V_22 * * V_128 )
{
struct V_22 * V_23 ;
T_3 V_42 ;
int V_27 ;
V_23 = F_112 ( sizeof( * V_23 ) , V_174 ) ;
if ( F_3 ( V_23 == NULL ) )
return - V_82 ;
V_42 = F_107 ( V_9 , V_15 , sizeof( struct V_22 ) ) ;
V_27 = F_95 ( V_9 , V_23 , V_15 , type , V_25 , V_156 ,
V_87 , V_161 , V_42 ,
NULL , NULL , NULL ) ;
if ( F_106 ( V_27 == 0 ) )
* V_128 = V_23 ;
return V_27 ;
}
static int F_113 ( struct V_8 * V_9 ,
unsigned V_3 , bool V_175 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
struct V_36 * V_37 = V_9 -> V_37 ;
struct V_108 * V_109 ;
int V_27 ;
F_32 ( & V_37 -> V_68 ) ;
while ( ! F_13 ( & V_11 -> V_46 ) ) {
F_33 ( & V_37 -> V_68 ) ;
V_27 = F_80 ( V_9 , V_3 , NULL , false , false ) ;
if ( V_27 ) {
if ( V_175 ) {
return V_27 ;
} else {
F_5 ( L_18 ) ;
}
}
F_32 ( & V_37 -> V_68 ) ;
}
F_33 ( & V_37 -> V_68 ) ;
F_32 ( & V_11 -> V_141 ) ;
V_109 = F_84 ( V_11 -> V_99 ) ;
F_33 ( & V_11 -> V_141 ) ;
if ( V_109 ) {
V_27 = F_114 ( V_109 , false ) ;
F_16 ( V_109 ) ;
if ( V_27 ) {
if ( V_175 ) {
return V_27 ;
} else {
F_5 ( L_18 ) ;
}
}
}
return 0 ;
}
int F_115 ( struct V_8 * V_9 , unsigned V_3 )
{
struct V_10 * V_11 ;
int V_27 = - V_7 ;
if ( V_3 >= V_176 ) {
F_5 ( L_19 , V_3 ) ;
return V_27 ;
}
V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( ! V_11 -> V_12 ) {
F_5 ( L_20 ,
V_3 ) ;
return V_27 ;
}
F_16 ( V_11 -> V_99 ) ;
V_11 -> V_13 = false ;
V_11 -> V_12 = false ;
V_27 = 0 ;
if ( V_3 > 0 ) {
F_113 ( V_9 , V_3 , false ) ;
V_27 = (* V_11 -> V_19 -> V_177 )( V_11 ) ;
}
return V_27 ;
}
int F_116 ( struct V_8 * V_9 , unsigned V_3 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( V_3 == 0 || V_3 >= V_176 ) {
F_5 ( L_21 , V_3 ) ;
return - V_7 ;
}
if ( ! V_11 -> V_12 ) {
F_5 ( L_22 , V_3 ) ;
return 0 ;
}
return F_113 ( V_9 , V_3 , true ) ;
}
int F_117 ( struct V_8 * V_9 , unsigned type ,
unsigned long V_178 )
{
int V_27 = - V_7 ;
struct V_10 * V_11 ;
F_12 ( type >= V_176 ) ;
V_11 = & V_9 -> V_11 [ type ] ;
F_12 ( V_11 -> V_12 ) ;
V_11 -> V_179 = true ;
V_11 -> V_180 = false ;
F_100 ( & V_11 -> V_181 ) ;
F_118 ( & V_11 -> V_141 ) ;
F_99 ( & V_11 -> V_166 ) ;
V_27 = V_9 -> V_58 -> V_182 ( V_9 , type , V_11 ) ;
if ( V_27 )
return V_27 ;
V_11 -> V_9 = V_9 ;
V_27 = 0 ;
if ( type != V_18 ) {
V_27 = (* V_11 -> V_19 -> V_183 )( V_11 , V_178 ) ;
if ( V_27 )
return V_27 ;
}
V_11 -> V_12 = true ;
V_11 -> V_13 = true ;
V_11 -> V_15 = V_178 ;
F_99 ( & V_11 -> V_46 ) ;
V_11 -> V_99 = NULL ;
return 0 ;
}
static void F_119 ( struct V_31 * V_32 )
{
struct V_36 * V_37 =
F_8 ( V_32 , struct V_36 , V_32 ) ;
F_120 ( V_37 -> V_54 , & V_37 -> V_184 ) ;
F_121 ( V_37 -> V_81 ) ;
F_19 ( V_37 ) ;
}
void F_122 ( struct V_185 * V_186 )
{
struct V_36 * V_37 = V_186 -> V_187 ;
F_123 ( & V_37 -> V_32 ) ;
F_124 ( & V_37 -> V_32 ) ;
}
int F_125 ( struct V_185 * V_186 )
{
struct V_188 * V_189 =
F_8 ( V_186 , struct V_188 , V_186 ) ;
struct V_36 * V_37 = V_186 -> V_187 ;
int V_27 ;
F_100 ( & V_37 -> V_190 ) ;
F_118 ( & V_37 -> V_68 ) ;
V_37 -> V_54 = V_189 -> V_54 ;
V_37 -> V_81 = F_126 ( V_191 | V_192 ) ;
if ( F_3 ( V_37 -> V_81 == NULL ) ) {
V_27 = - V_82 ;
goto V_193;
}
F_99 ( & V_37 -> V_71 ) ;
F_99 ( & V_37 -> V_194 ) ;
F_127 ( & V_37 -> V_184 , V_195 ) ;
V_27 = F_128 ( V_37 -> V_54 , & V_37 -> V_184 ) ;
if ( F_3 ( V_27 != 0 ) ) {
F_5 ( L_23 ) ;
goto V_196;
}
F_98 ( & V_37 -> V_39 , 0 ) ;
V_27 = F_129 (
& V_37 -> V_32 , & V_197 , F_130 () , L_24 ) ;
if ( F_3 ( V_27 != 0 ) )
F_124 ( & V_37 -> V_32 ) ;
return V_27 ;
V_196:
F_121 ( V_37 -> V_81 ) ;
V_193:
F_19 ( V_37 ) ;
return V_27 ;
}
int F_131 ( struct V_8 * V_9 )
{
int V_27 = 0 ;
unsigned V_26 = V_176 ;
struct V_10 * V_11 ;
struct V_36 * V_37 = V_9 -> V_37 ;
while ( V_26 -- ) {
V_11 = & V_9 -> V_11 [ V_26 ] ;
if ( V_11 -> V_12 ) {
V_11 -> V_13 = false ;
if ( ( V_26 != V_18 ) && F_115 ( V_9 , V_26 ) ) {
V_27 = - V_117 ;
F_5 ( L_25 ,
V_26 ) ;
}
V_11 -> V_12 = false ;
}
}
F_132 ( & V_37 -> V_190 ) ;
F_133 ( & V_9 -> V_194 ) ;
F_134 ( & V_37 -> V_190 ) ;
F_75 ( & V_9 -> V_114 ) ;
while ( F_66 ( V_9 , true ) )
;
F_32 ( & V_37 -> V_68 ) ;
if ( F_13 ( & V_9 -> V_47 ) )
F_135 ( L_26 ) ;
if ( F_13 ( & V_9 -> V_11 [ 0 ] . V_46 ) )
F_135 ( L_27 ) ;
F_33 ( & V_37 -> V_68 ) ;
F_136 ( & V_9 -> V_126 ) ;
return V_27 ;
}
int F_137 ( struct V_8 * V_9 ,
struct V_36 * V_37 ,
struct V_198 * V_58 ,
struct V_199 * V_200 ,
T_4 V_201 ,
bool V_74 )
{
int V_27 = - V_7 ;
V_9 -> V_58 = V_58 ;
memset ( V_9 -> V_11 , 0 , sizeof( V_9 -> V_11 ) ) ;
V_27 = F_117 ( V_9 , V_18 , 0 ) ;
if ( F_3 ( V_27 != 0 ) )
goto V_202;
F_138 ( & V_9 -> V_126 , V_201 ,
0x10000000 ) ;
F_139 ( & V_9 -> V_114 , F_69 ) ;
F_99 ( & V_9 -> V_47 ) ;
V_9 -> V_203 = V_200 ;
V_9 -> V_37 = V_37 ;
V_9 -> V_74 = V_74 ;
F_132 ( & V_37 -> V_190 ) ;
F_61 ( & V_9 -> V_194 , & V_37 -> V_194 ) ;
F_134 ( & V_37 -> V_190 ) ;
return 0 ;
V_202:
return V_27 ;
}
bool F_40 ( struct V_8 * V_9 , struct V_85 * V_28 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_28 -> V_3 ] ;
if ( ! ( V_11 -> V_5 & V_95 ) ) {
if ( V_28 -> V_3 == V_18 )
return false ;
if ( V_11 -> V_5 & V_204 )
return false ;
if ( V_28 -> V_25 & V_146 )
return false ;
}
return true ;
}
void F_42 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
F_140 ( & V_23 -> V_127 , V_9 -> V_203 ) ;
F_72 ( V_23 ) ;
}
void F_141 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_23 -> V_28 . V_3 ] ;
F_41 ( V_11 , false ) ;
F_42 ( V_23 ) ;
F_43 ( V_11 ) ;
}
int F_59 ( struct V_22 * V_23 ,
bool V_87 , bool V_205 )
{
long V_206 = 15 * V_115 ;
if ( V_205 ) {
if ( F_142 ( V_23 -> V_50 , true ) )
return 0 ;
else
return - V_117 ;
}
V_206 = F_64 ( V_23 -> V_50 , true ,
V_87 , V_206 ) ;
if ( V_206 < 0 )
return V_206 ;
if ( V_206 == 0 )
return - V_117 ;
F_143 ( V_23 -> V_50 , NULL ) ;
return 0 ;
}
int F_144 ( struct V_22 * V_23 , bool V_205 )
{
int V_27 = 0 ;
V_27 = F_145 ( V_23 , true , V_205 , NULL ) ;
if ( F_3 ( V_27 != 0 ) )
return V_27 ;
V_27 = F_59 ( V_23 , true , V_205 ) ;
if ( F_106 ( V_27 == 0 ) )
F_102 ( & V_23 -> V_44 ) ;
F_82 ( V_23 ) ;
return V_27 ;
}
void F_146 ( struct V_22 * V_23 )
{
F_15 ( & V_23 -> V_44 ) ;
}
static int V_195 ( struct V_207 * V_184 )
{
struct V_36 * V_37 =
F_8 ( V_184 , struct V_36 , V_184 ) ;
struct V_22 * V_23 ;
int V_27 = - V_117 ;
int V_64 ;
T_1 V_208 = ( V_146 | V_167 ) ;
F_32 ( & V_37 -> V_68 ) ;
F_81 (bo, &glob->swap_lru, swap) {
V_27 = F_58 ( V_23 , false , true , NULL ) ;
if ( ! V_27 )
break;
}
if ( V_27 ) {
F_33 ( & V_37 -> V_68 ) ;
return V_27 ;
}
F_24 ( & V_23 -> V_41 ) ;
if ( ! F_13 ( & V_23 -> V_47 ) ) {
V_27 = F_63 ( V_23 , false , false ) ;
F_68 ( & V_23 -> V_41 , F_11 ) ;
return V_27 ;
}
V_64 = F_25 ( V_23 ) ;
F_33 ( & V_37 -> V_68 ) ;
F_29 ( V_23 , V_64 , true ) ;
if ( ( V_23 -> V_28 . V_25 & V_208 ) != V_208 ) {
struct V_85 V_130 ;
V_130 = V_23 -> V_28 ;
V_130 . V_45 = NULL ;
V_130 . V_25 = V_167 | V_146 ;
V_130 . V_3 = V_18 ;
V_27 = F_39 ( V_23 , & V_130 , true ,
false , false ) ;
if ( F_3 ( V_27 != 0 ) )
goto V_123;
}
V_27 = F_59 ( V_23 , false , false ) ;
if ( F_3 ( V_27 != 0 ) )
goto V_123;
F_141 ( V_23 ) ;
if ( V_23 -> V_9 -> V_58 -> V_209 )
V_23 -> V_9 -> V_58 -> V_209 ( V_23 ) ;
V_27 = F_147 ( V_23 -> V_48 , V_23 -> V_161 ) ;
V_123:
F_60 ( V_23 ) ;
F_68 ( & V_23 -> V_41 , F_11 ) ;
return V_27 ;
}
void F_148 ( struct V_8 * V_9 )
{
while ( V_195 ( & V_9 -> V_37 -> V_184 ) == 0 )
;
}
int F_149 ( struct V_22 * V_23 )
{
int V_27 ;
V_27 = F_150 ( & V_23 -> V_52 ) ;
if ( F_3 ( V_27 != 0 ) )
return - V_136 ;
if ( ! F_151 ( & V_23 -> V_50 -> V_55 ) )
goto V_120;
V_27 = F_58 ( V_23 , true , false , NULL ) ;
if ( F_3 ( V_27 != 0 ) )
goto V_120;
F_60 ( V_23 ) ;
V_120:
F_134 ( & V_23 -> V_52 ) ;
return V_27 ;
}
