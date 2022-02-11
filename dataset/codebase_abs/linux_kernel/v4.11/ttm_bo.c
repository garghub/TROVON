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
F_12 ( F_13 ( & V_23 -> V_41 ) ) ;
F_12 ( F_13 ( & V_23 -> V_40 ) ) ;
F_12 ( F_9 ( & V_23 -> V_43 ) ) ;
F_12 ( V_23 -> V_28 . V_44 != NULL ) ;
F_12 ( ! F_14 ( & V_23 -> V_45 ) ) ;
F_12 ( ! F_14 ( & V_23 -> V_46 ) ) ;
F_15 ( V_23 -> V_47 ) ;
F_16 ( & V_23 -> V_37 -> V_39 ) ;
F_17 ( V_23 -> V_48 ) ;
if ( V_23 -> V_49 == & V_23 -> V_50 )
F_18 ( & V_23 -> V_50 ) ;
F_19 ( & V_23 -> V_51 ) ;
if ( V_23 -> V_52 )
V_23 -> V_52 ( V_23 ) ;
else {
F_20 ( V_23 ) ;
}
F_21 ( V_9 -> V_37 -> V_53 , V_42 ) ;
}
void F_22 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 ;
F_23 ( & V_23 -> V_49 -> V_54 . V_55 ) ;
if ( ! ( V_23 -> V_28 . V_25 & V_56 ) ) {
F_12 ( ! F_14 ( & V_23 -> V_45 ) ) ;
V_11 = & V_9 -> V_11 [ V_23 -> V_28 . V_3 ] ;
F_24 ( & V_23 -> V_45 , & V_11 -> V_45 [ V_23 -> V_57 ] ) ;
F_25 ( & V_23 -> V_41 ) ;
if ( V_23 -> V_47 && ! ( V_23 -> V_47 -> V_58 & V_59 ) ) {
F_24 ( & V_23 -> V_60 ,
& V_23 -> V_37 -> V_61 [ V_23 -> V_57 ] ) ;
F_25 ( & V_23 -> V_41 ) ;
}
}
}
static void F_26 ( struct V_40 * V_41 )
{
F_27 () ;
}
void F_28 ( struct V_22 * V_23 )
{
if ( ! F_14 ( & V_23 -> V_60 ) ) {
F_29 ( & V_23 -> V_60 ) ;
F_30 ( & V_23 -> V_41 , F_26 ) ;
}
if ( ! F_14 ( & V_23 -> V_45 ) ) {
F_29 ( & V_23 -> V_45 ) ;
F_30 ( & V_23 -> V_41 , F_26 ) ;
}
}
void F_31 ( struct V_22 * V_23 )
{
F_32 ( & V_23 -> V_37 -> V_62 ) ;
F_28 ( V_23 ) ;
F_33 ( & V_23 -> V_37 -> V_62 ) ;
}
void F_34 ( struct V_22 * V_23 )
{
F_23 ( & V_23 -> V_49 -> V_54 . V_55 ) ;
F_28 ( V_23 ) ;
F_22 ( V_23 ) ;
}
static int F_35 ( struct V_22 * V_23 , bool V_63 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_36 * V_37 = V_23 -> V_37 ;
int V_27 = 0 ;
T_1 V_58 = 0 ;
F_36 ( & V_23 -> V_64 ) ;
V_23 -> V_47 = NULL ;
if ( V_9 -> V_65 )
V_58 |= V_66 ;
switch ( V_23 -> type ) {
case V_67 :
if ( V_63 )
V_58 |= V_68 ;
case V_69 :
V_23 -> V_47 = V_9 -> V_70 -> V_71 ( V_9 , V_23 -> V_29 << V_72 ,
V_58 , V_37 -> V_73 ) ;
if ( F_3 ( V_23 -> V_47 == NULL ) )
V_27 = - V_74 ;
break;
case V_75 :
V_23 -> V_47 = V_9 -> V_70 -> V_71 ( V_9 , V_23 -> V_29 << V_72 ,
V_58 | V_59 ,
V_37 -> V_73 ) ;
if ( F_3 ( V_23 -> V_47 == NULL ) ) {
V_27 = - V_74 ;
break;
}
V_23 -> V_47 -> V_76 = V_23 -> V_76 ;
break;
default:
F_5 ( L_11 ) ;
V_27 = - V_7 ;
break;
}
return V_27 ;
}
static int F_37 ( struct V_22 * V_23 ,
struct V_77 * V_28 ,
bool V_78 , bool V_79 ,
bool V_80 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
bool V_81 = F_38 ( V_9 , & V_23 -> V_28 ) ;
bool V_82 = F_38 ( V_9 , V_28 ) ;
struct V_10 * V_83 = & V_9 -> V_11 [ V_23 -> V_28 . V_3 ] ;
struct V_10 * V_84 = & V_9 -> V_11 [ V_28 -> V_3 ] ;
int V_27 = 0 ;
if ( V_81 || V_82 ||
( ( V_28 -> V_25 & V_23 -> V_28 . V_25 & V_85 ) == 0 ) ) {
V_27 = F_39 ( V_83 , true ) ;
if ( F_3 ( V_27 != 0 ) )
goto V_86;
F_40 ( V_23 ) ;
F_41 ( V_83 ) ;
}
if ( ! ( V_84 -> V_5 & V_87 ) ) {
if ( V_23 -> V_47 == NULL ) {
bool V_88 = ! ( V_83 -> V_5 & V_87 ) ;
V_27 = F_35 ( V_23 , V_88 ) ;
if ( V_27 )
goto V_86;
}
V_27 = F_42 ( V_23 -> V_47 , V_28 -> V_25 ) ;
if ( V_27 )
goto V_86;
if ( V_28 -> V_3 != V_18 ) {
V_27 = F_43 ( V_23 -> V_47 , V_28 ) ;
if ( V_27 )
goto V_86;
}
if ( V_23 -> V_28 . V_3 == V_18 ) {
if ( V_9 -> V_70 -> V_89 )
V_9 -> V_70 -> V_89 ( V_23 , V_78 , V_28 ) ;
V_23 -> V_28 = * V_28 ;
V_28 -> V_44 = NULL ;
goto V_90;
}
}
if ( V_9 -> V_70 -> V_89 )
V_9 -> V_70 -> V_89 ( V_23 , V_78 , V_28 ) ;
if ( ! ( V_83 -> V_5 & V_87 ) &&
! ( V_84 -> V_5 & V_87 ) )
V_27 = F_44 ( V_23 , V_79 , V_80 , V_28 ) ;
else if ( V_9 -> V_70 -> V_91 )
V_27 = V_9 -> V_70 -> V_91 ( V_23 , V_78 , V_79 ,
V_80 , V_28 ) ;
else
V_27 = F_45 ( V_23 , V_79 , V_80 , V_28 ) ;
if ( V_27 ) {
if ( V_9 -> V_70 -> V_89 ) {
struct V_77 V_92 = * V_28 ;
* V_28 = V_23 -> V_28 ;
V_23 -> V_28 = V_92 ;
V_9 -> V_70 -> V_89 ( V_23 , false , V_28 ) ;
V_23 -> V_28 = * V_28 ;
* V_28 = V_92 ;
}
goto V_86;
}
V_90:
if ( V_23 -> V_93 ) {
if ( V_9 -> V_70 -> V_94 ) {
V_27 = V_9 -> V_70 -> V_94 ( V_9 , V_23 -> V_28 . V_25 ) ;
if ( V_27 )
F_5 ( L_12 ) ;
}
V_23 -> V_93 = false ;
}
if ( V_23 -> V_28 . V_44 ) {
V_23 -> V_95 = ( V_23 -> V_28 . V_96 << V_72 ) +
V_9 -> V_11 [ V_23 -> V_28 . V_3 ] . V_14 ;
V_23 -> V_97 = V_23 -> V_28 . V_25 ;
} else
V_23 -> V_95 = 0 ;
return 0 ;
V_86:
V_84 = & V_9 -> V_11 [ V_23 -> V_28 . V_3 ] ;
if ( V_84 -> V_5 & V_87 ) {
F_15 ( V_23 -> V_47 ) ;
V_23 -> V_47 = NULL ;
}
return V_27 ;
}
static void F_46 ( struct V_22 * V_23 )
{
if ( V_23 -> V_9 -> V_70 -> V_89 )
V_23 -> V_9 -> V_70 -> V_89 ( V_23 , false , NULL ) ;
F_15 ( V_23 -> V_47 ) ;
V_23 -> V_47 = NULL ;
F_47 ( V_23 , & V_23 -> V_28 ) ;
F_48 ( & V_23 -> V_49 -> V_54 ) ;
}
static void F_49 ( struct V_22 * V_23 )
{
struct V_98 * V_99 ;
struct V_100 * V_101 ;
int V_26 ;
V_99 = F_50 ( V_23 -> V_49 ) ;
V_101 = F_51 ( V_23 -> V_49 ) ;
if ( V_101 && ! V_101 -> V_102 -> V_103 )
F_52 ( V_101 ) ;
for ( V_26 = 0 ; V_99 && V_26 < V_99 -> V_104 ; ++ V_26 ) {
V_101 = F_53 ( V_99 -> V_105 [ V_26 ] ,
F_54 ( V_23 -> V_49 ) ) ;
if ( ! V_101 -> V_102 -> V_103 )
F_52 ( V_101 ) ;
}
}
static void F_55 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_36 * V_37 = V_23 -> V_37 ;
int V_27 ;
F_32 ( & V_37 -> V_62 ) ;
V_27 = F_56 ( V_23 , false , true , NULL ) ;
if ( ! V_27 ) {
if ( ! F_57 ( V_23 , false , true ) ) {
F_28 ( V_23 ) ;
F_33 ( & V_37 -> V_62 ) ;
F_46 ( V_23 ) ;
return;
} else
F_49 ( V_23 ) ;
if ( V_23 -> V_28 . V_25 & V_56 ) {
V_23 -> V_28 . V_25 &= ~ V_56 ;
F_22 ( V_23 ) ;
}
F_58 ( V_23 ) ;
}
F_25 ( & V_23 -> V_41 ) ;
F_24 ( & V_23 -> V_46 , & V_9 -> V_46 ) ;
F_33 ( & V_37 -> V_62 ) ;
F_59 ( & V_9 -> V_106 ,
( ( V_107 / 100 ) < 1 ) ? 1 : V_107 / 100 ) ;
}
static int F_60 ( struct V_22 * V_23 ,
bool V_79 ,
bool V_80 )
{
struct V_36 * V_37 = V_23 -> V_37 ;
int V_27 ;
V_27 = F_57 ( V_23 , false , true ) ;
if ( V_27 && ! V_80 ) {
long V_108 ;
F_48 ( & V_23 -> V_49 -> V_54 ) ;
F_33 ( & V_37 -> V_62 ) ;
V_108 = F_61 ( V_23 -> V_49 ,
true ,
V_79 ,
30 * V_107 ) ;
if ( V_108 < 0 )
return V_108 ;
else if ( V_108 == 0 )
return - V_109 ;
F_32 ( & V_37 -> V_62 ) ;
V_27 = F_56 ( V_23 , false , true , NULL ) ;
if ( V_27 ) {
F_33 ( & V_37 -> V_62 ) ;
return 0 ;
}
V_27 = F_57 ( V_23 , false , true ) ;
F_62 ( V_27 ) ;
}
if ( V_27 || F_3 ( F_14 ( & V_23 -> V_46 ) ) ) {
F_58 ( V_23 ) ;
F_33 ( & V_37 -> V_62 ) ;
return V_27 ;
}
F_28 ( V_23 ) ;
F_29 ( & V_23 -> V_46 ) ;
F_30 ( & V_23 -> V_41 , F_26 ) ;
F_33 ( & V_37 -> V_62 ) ;
F_46 ( V_23 ) ;
return 0 ;
}
static int F_63 ( struct V_8 * V_9 , bool V_110 )
{
struct V_36 * V_37 = V_9 -> V_37 ;
struct V_22 * V_111 = NULL ;
int V_27 = 0 ;
F_32 ( & V_37 -> V_62 ) ;
if ( F_14 ( & V_9 -> V_46 ) )
goto V_112;
V_111 = F_64 ( & V_9 -> V_46 ,
struct V_22 , V_46 ) ;
F_25 ( & V_111 -> V_41 ) ;
for (; ; ) {
struct V_22 * V_113 = NULL ;
if ( V_111 -> V_46 . V_114 != & V_9 -> V_46 ) {
V_113 = F_64 ( & V_111 -> V_46 ,
struct V_22 , V_46 ) ;
F_25 ( & V_113 -> V_41 ) ;
}
V_27 = F_56 ( V_111 , false , true , NULL ) ;
if ( V_110 && V_27 ) {
F_33 ( & V_37 -> V_62 ) ;
V_27 = F_56 ( V_111 , false , false , NULL ) ;
F_32 ( & V_37 -> V_62 ) ;
}
if ( ! V_27 )
V_27 = F_60 ( V_111 , false ,
! V_110 ) ;
else
F_33 ( & V_37 -> V_62 ) ;
F_30 ( & V_111 -> V_41 , F_11 ) ;
V_111 = V_113 ;
if ( V_27 || ! V_111 )
goto V_115;
F_32 ( & V_37 -> V_62 ) ;
if ( F_14 ( & V_111 -> V_46 ) )
break;
}
V_112:
F_33 ( & V_37 -> V_62 ) ;
V_115:
if ( V_111 )
F_30 ( & V_111 -> V_41 , F_11 ) ;
return V_27 ;
}
static void F_65 ( struct V_116 * V_117 )
{
struct V_8 * V_9 =
F_8 ( V_117 , struct V_8 , V_106 . V_117 ) ;
if ( F_63 ( V_9 , false ) ) {
F_59 ( & V_9 -> V_106 ,
( ( V_107 / 100 ) < 1 ) ? 1 : V_107 / 100 ) ;
}
}
static void F_66 ( struct V_40 * V_40 )
{
struct V_22 * V_23 =
F_8 ( V_40 , struct V_22 , V_40 ) ;
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_23 -> V_28 . V_3 ] ;
F_67 ( & V_9 -> V_118 , & V_23 -> V_119 ) ;
F_39 ( V_11 , false ) ;
F_68 ( V_23 ) ;
F_41 ( V_11 ) ;
F_55 ( V_23 ) ;
F_30 ( & V_23 -> V_41 , F_11 ) ;
}
void F_69 ( struct V_22 * * V_120 )
{
struct V_22 * V_23 = * V_120 ;
* V_120 = NULL ;
F_30 ( & V_23 -> V_40 , F_66 ) ;
}
int F_70 ( struct V_8 * V_9 )
{
return F_71 ( & V_9 -> V_106 ) ;
}
void F_72 ( struct V_8 * V_9 , int V_121 )
{
if ( V_121 )
F_59 ( & V_9 -> V_106 ,
( ( V_107 / 100 ) < 1 ) ? 1 : V_107 / 100 ) ;
}
static int F_73 ( struct V_22 * V_23 , bool V_79 ,
bool V_80 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_77 V_122 ;
struct V_24 V_25 ;
int V_27 = 0 ;
F_23 ( & V_23 -> V_49 -> V_54 . V_55 ) ;
V_122 = V_23 -> V_28 ;
V_122 . V_44 = NULL ;
V_122 . V_123 . V_124 = false ;
V_122 . V_123 . V_125 = 0 ;
V_25 . V_30 = 0 ;
V_25 . V_126 = 0 ;
V_9 -> V_70 -> V_127 ( V_23 , & V_25 ) ;
V_27 = F_74 ( V_23 , & V_25 , & V_122 , V_79 ,
V_80 ) ;
if ( V_27 ) {
if ( V_27 != - V_128 ) {
F_5 ( L_13 ,
V_23 ) ;
F_6 ( V_23 , & V_25 ) ;
}
goto V_115;
}
V_27 = F_37 ( V_23 , & V_122 , true , V_79 ,
V_80 ) ;
if ( F_3 ( V_27 ) ) {
if ( V_27 != - V_128 )
F_5 ( L_14 ) ;
F_47 ( V_23 , & V_122 ) ;
goto V_115;
}
V_23 -> V_93 = true ;
V_115:
return V_27 ;
}
bool F_75 ( struct V_22 * V_23 ,
const struct V_1 * V_2 )
{
if ( V_2 -> V_129 >= ( V_23 -> V_28 . V_96 + V_23 -> V_28 . V_15 ) ||
( V_2 -> V_130 && V_2 -> V_130 <= V_23 -> V_28 . V_96 ) )
return false ;
return true ;
}
static int F_76 ( struct V_8 * V_9 ,
T_1 V_3 ,
const struct V_1 * V_2 ,
bool V_79 ,
bool V_80 )
{
struct V_36 * V_37 = V_9 -> V_37 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
struct V_22 * V_23 ;
int V_27 = - V_109 ;
unsigned V_26 ;
F_32 ( & V_37 -> V_62 ) ;
for ( V_26 = 0 ; V_26 < V_131 ; ++ V_26 ) {
F_77 (bo, &man->lru[i], lru) {
V_27 = F_56 ( V_23 , false , true , NULL ) ;
if ( V_27 )
continue;
if ( V_2 && ! V_9 -> V_70 -> V_132 ( V_23 ,
V_2 ) ) {
F_58 ( V_23 ) ;
V_27 = - V_109 ;
continue;
}
break;
}
if ( ! V_27 )
break;
}
if ( V_27 ) {
F_33 ( & V_37 -> V_62 ) ;
return V_27 ;
}
F_25 ( & V_23 -> V_41 ) ;
if ( ! F_14 ( & V_23 -> V_46 ) ) {
V_27 = F_60 ( V_23 , V_79 ,
V_80 ) ;
F_30 ( & V_23 -> V_41 , F_11 ) ;
return V_27 ;
}
F_28 ( V_23 ) ;
F_33 ( & V_37 -> V_62 ) ;
F_12 ( V_27 != 0 ) ;
V_27 = F_73 ( V_23 , V_79 , V_80 ) ;
F_78 ( V_23 ) ;
F_30 ( & V_23 -> V_41 , F_11 ) ;
return V_27 ;
}
void F_47 ( struct V_22 * V_23 , struct V_77 * V_28 )
{
struct V_10 * V_11 = & V_23 -> V_9 -> V_11 [ V_28 -> V_3 ] ;
if ( V_28 -> V_44 )
(* V_11 -> V_19 -> V_133 )( V_11 , V_28 ) ;
}
static int F_79 ( struct V_22 * V_23 ,
struct V_10 * V_11 ,
struct V_77 * V_28 )
{
struct V_100 * V_101 ;
int V_27 ;
F_32 ( & V_11 -> V_134 ) ;
V_101 = F_80 ( V_11 -> V_91 ) ;
F_33 ( & V_11 -> V_134 ) ;
if ( V_101 ) {
F_81 ( V_23 -> V_49 , V_101 ) ;
V_27 = F_82 ( V_23 -> V_49 ) ;
if ( F_3 ( V_27 ) )
return V_27 ;
F_17 ( V_23 -> V_48 ) ;
V_23 -> V_48 = V_101 ;
}
return 0 ;
}
static int F_83 ( struct V_22 * V_23 ,
T_1 V_3 ,
const struct V_1 * V_2 ,
struct V_77 * V_28 ,
bool V_79 ,
bool V_80 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
int V_27 ;
do {
V_27 = (* V_11 -> V_19 -> V_135 )( V_11 , V_23 , V_2 , V_28 ) ;
if ( F_3 ( V_27 != 0 ) )
return V_27 ;
if ( V_28 -> V_44 )
break;
V_27 = F_76 ( V_9 , V_3 , V_2 ,
V_79 , V_80 ) ;
if ( F_3 ( V_27 != 0 ) )
return V_27 ;
} while ( 1 );
V_28 -> V_3 = V_3 ;
return F_79 ( V_23 , V_11 , V_28 ) ;
}
static T_1 F_84 ( struct V_10 * V_11 ,
T_1 V_97 ,
T_1 V_136 )
{
T_1 V_137 = V_136 & V_85 ;
T_1 V_138 = V_136 & ~ V_85 ;
if ( ( V_97 & V_137 ) != 0 )
V_138 |= ( V_97 & V_137 ) ;
else if ( ( V_11 -> V_17 & V_137 ) != 0 )
V_138 |= V_11 -> V_17 ;
else if ( ( V_139 & V_137 ) != 0 )
V_138 |= V_139 ;
else if ( ( V_140 & V_137 ) != 0 )
V_138 |= V_140 ;
else if ( ( V_141 & V_137 ) != 0 )
V_138 |= V_141 ;
return V_138 ;
}
static bool F_85 ( struct V_10 * V_11 ,
T_1 V_3 ,
const struct V_1 * V_2 ,
T_1 * V_142 )
{
T_1 V_143 = F_10 ( V_3 ) ;
if ( ( V_143 & V_2 -> V_5 & V_6 ) == 0 )
return false ;
if ( ( V_2 -> V_5 & V_11 -> V_16 ) == 0 )
return false ;
V_143 |= ( V_2 -> V_5 & V_11 -> V_16 ) ;
* V_142 = V_143 ;
return true ;
}
int F_74 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_77 * V_28 ,
bool V_79 ,
bool V_80 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 ;
T_1 V_3 = V_18 ;
T_1 V_143 = 0 ;
bool V_144 = false ;
bool V_145 = false ;
bool V_146 = false ;
int V_26 , V_27 ;
V_27 = F_82 ( V_23 -> V_49 ) ;
if ( F_3 ( V_27 ) )
return V_27 ;
V_28 -> V_44 = NULL ;
for ( V_26 = 0 ; V_26 < V_25 -> V_30 ; ++ V_26 ) {
const struct V_1 * V_2 = & V_25 -> V_25 [ V_26 ] ;
V_27 = F_1 ( V_2 , & V_3 ) ;
if ( V_27 )
return V_27 ;
V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( ! V_11 -> V_12 || ! V_11 -> V_13 )
continue;
V_145 = F_85 ( V_11 , V_3 , V_2 ,
& V_143 ) ;
if ( ! V_145 )
continue;
V_144 = true ;
V_143 = F_84 ( V_11 , V_23 -> V_28 . V_25 ,
V_143 ) ;
F_86 ( & V_143 , V_2 -> V_5 ,
~ V_147 ) ;
if ( V_3 == V_18 )
break;
V_27 = (* V_11 -> V_19 -> V_135 )( V_11 , V_23 , V_2 , V_28 ) ;
if ( F_3 ( V_27 ) )
return V_27 ;
if ( V_28 -> V_44 ) {
V_27 = F_79 ( V_23 , V_11 , V_28 ) ;
if ( F_3 ( V_27 ) ) {
(* V_11 -> V_19 -> V_133 )( V_11 , V_28 ) ;
return V_27 ;
}
break;
}
}
if ( ( V_145 && ( V_3 == V_18 ) ) || V_28 -> V_44 ) {
V_28 -> V_3 = V_3 ;
V_28 -> V_25 = V_143 ;
return 0 ;
}
for ( V_26 = 0 ; V_26 < V_25 -> V_126 ; ++ V_26 ) {
const struct V_1 * V_2 = & V_25 -> V_148 [ V_26 ] ;
V_27 = F_1 ( V_2 , & V_3 ) ;
if ( V_27 )
return V_27 ;
V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( ! V_11 -> V_12 || ! V_11 -> V_13 )
continue;
if ( ! F_85 ( V_11 , V_3 , V_2 , & V_143 ) )
continue;
V_144 = true ;
V_143 = F_84 ( V_11 , V_23 -> V_28 . V_25 ,
V_143 ) ;
F_86 ( & V_143 , V_2 -> V_5 ,
~ V_147 ) ;
if ( V_3 == V_18 ) {
V_28 -> V_3 = V_3 ;
V_28 -> V_25 = V_143 ;
V_28 -> V_44 = NULL ;
return 0 ;
}
V_27 = F_83 ( V_23 , V_3 , V_2 , V_28 ,
V_79 , V_80 ) ;
if ( V_27 == 0 && V_28 -> V_44 ) {
V_28 -> V_25 = V_143 ;
return 0 ;
}
if ( V_27 == - V_128 )
V_146 = true ;
}
if ( ! V_144 ) {
F_87 (KERN_ERR TTM_PFX L_15 ) ;
return - V_7 ;
}
return ( V_146 ) ? - V_128 : - V_74 ;
}
static int F_88 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
bool V_79 ,
bool V_80 )
{
int V_27 = 0 ;
struct V_77 V_28 ;
F_23 ( & V_23 -> V_49 -> V_54 . V_55 ) ;
V_28 . V_29 = V_23 -> V_29 ;
V_28 . V_15 = V_28 . V_29 << V_72 ;
V_28 . V_149 = V_23 -> V_28 . V_149 ;
V_28 . V_123 . V_124 = false ;
V_28 . V_123 . V_125 = 0 ;
V_27 = F_74 ( V_23 , V_25 , & V_28 ,
V_79 , V_80 ) ;
if ( V_27 )
goto V_112;
V_27 = F_37 ( V_23 , & V_28 , false ,
V_79 , V_80 ) ;
V_112:
if ( V_27 && V_28 . V_44 )
F_47 ( V_23 , & V_28 ) ;
return V_27 ;
}
bool F_89 ( struct V_24 * V_25 ,
struct V_77 * V_28 ,
T_1 * V_150 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_25 -> V_30 ; V_26 ++ ) {
const struct V_1 * V_151 = & V_25 -> V_25 [ V_26 ] ;
if ( V_28 -> V_44 &&
( V_28 -> V_96 < V_151 -> V_129 ||
( V_151 -> V_130 != 0 && ( V_28 -> V_96 + V_28 -> V_29 ) > V_151 -> V_130 ) ) )
continue;
* V_150 = V_151 -> V_5 ;
if ( ( * V_150 & V_28 -> V_25 & V_85 ) &&
( * V_150 & V_28 -> V_25 & V_6 ) )
return true ;
}
for ( V_26 = 0 ; V_26 < V_25 -> V_126 ; V_26 ++ ) {
const struct V_1 * V_151 = & V_25 -> V_148 [ V_26 ] ;
if ( V_28 -> V_44 &&
( V_28 -> V_96 < V_151 -> V_129 ||
( V_151 -> V_130 != 0 && ( V_28 -> V_96 + V_28 -> V_29 ) > V_151 -> V_130 ) ) )
continue;
* V_150 = V_151 -> V_5 ;
if ( ( * V_150 & V_28 -> V_25 & V_85 ) &&
( * V_150 & V_28 -> V_25 & V_6 ) )
return true ;
}
return false ;
}
int F_90 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
bool V_79 ,
bool V_80 )
{
int V_27 ;
T_1 V_150 ;
F_23 ( & V_23 -> V_49 -> V_54 . V_55 ) ;
if ( ! F_89 ( V_25 , & V_23 -> V_28 , & V_150 ) ) {
V_27 = F_88 ( V_23 , V_25 , V_79 ,
V_80 ) ;
if ( V_27 )
return V_27 ;
} else {
F_86 ( & V_23 -> V_28 . V_25 , V_150 ,
~ V_147 ) ;
}
if ( V_23 -> V_28 . V_3 == V_18 && V_23 -> V_47 == NULL ) {
V_27 = F_35 ( V_23 , true ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
int F_91 ( struct V_8 * V_9 ,
struct V_22 * V_23 ,
unsigned long V_15 ,
enum V_152 type ,
struct V_24 * V_25 ,
T_1 V_149 ,
bool V_79 ,
struct V_153 * V_154 ,
T_3 V_42 ,
struct V_155 * V_76 ,
struct V_156 * V_49 ,
void (* V_52) ( struct V_22 * ) )
{
int V_27 = 0 ;
unsigned long V_29 ;
struct V_157 * V_53 = V_9 -> V_37 -> V_53 ;
bool V_158 ;
V_27 = F_92 ( V_53 , V_42 , false , false ) ;
if ( V_27 ) {
F_5 ( L_16 ) ;
if ( V_52 )
(* V_52)( V_23 ) ;
else
F_20 ( V_23 ) ;
return - V_74 ;
}
V_29 = ( V_15 + V_38 - 1 ) >> V_72 ;
if ( V_29 == 0 ) {
F_5 ( L_17 ) ;
if ( V_52 )
(* V_52)( V_23 ) ;
else
F_20 ( V_23 ) ;
F_21 ( V_53 , V_42 ) ;
return - V_7 ;
}
V_23 -> V_52 = V_52 ;
F_93 ( & V_23 -> V_40 ) ;
F_93 ( & V_23 -> V_41 ) ;
F_94 ( & V_23 -> V_43 , 0 ) ;
F_95 ( & V_23 -> V_45 ) ;
F_95 ( & V_23 -> V_46 ) ;
F_95 ( & V_23 -> V_60 ) ;
F_95 ( & V_23 -> V_159 ) ;
F_96 ( & V_23 -> V_51 ) ;
V_23 -> V_9 = V_9 ;
V_23 -> V_37 = V_9 -> V_37 ;
V_23 -> type = type ;
V_23 -> V_29 = V_29 ;
V_23 -> V_28 . V_15 = V_29 << V_72 ;
V_23 -> V_28 . V_3 = V_18 ;
V_23 -> V_28 . V_29 = V_23 -> V_29 ;
V_23 -> V_28 . V_44 = NULL ;
V_23 -> V_28 . V_149 = V_149 ;
V_23 -> V_28 . V_123 . V_124 = false ;
V_23 -> V_28 . V_123 . V_125 = 0 ;
V_23 -> V_48 = NULL ;
V_23 -> V_28 . V_25 = ( V_160 | V_139 ) ;
V_23 -> V_154 = V_154 ;
V_23 -> V_42 = V_42 ;
V_23 -> V_76 = V_76 ;
if ( V_49 ) {
V_23 -> V_49 = V_49 ;
F_23 ( & V_23 -> V_49 -> V_54 . V_55 ) ;
} else {
V_23 -> V_49 = & V_23 -> V_50 ;
F_97 ( & V_23 -> V_50 ) ;
}
F_98 ( & V_23 -> V_37 -> V_39 ) ;
F_99 ( & V_23 -> V_119 ) ;
V_23 -> V_57 = 0 ;
if ( V_23 -> type == V_67 ||
V_23 -> type == V_75 )
V_27 = F_100 ( & V_9 -> V_118 , & V_23 -> V_119 ,
V_23 -> V_28 . V_29 ) ;
if ( ! V_49 ) {
V_158 = F_101 ( & V_23 -> V_49 -> V_54 ) ;
F_62 ( ! V_158 ) ;
}
if ( F_102 ( ! V_27 ) )
V_27 = F_90 ( V_23 , V_25 , V_79 , false ) ;
if ( ! V_49 ) {
F_78 ( V_23 ) ;
} else if ( ! ( V_23 -> V_28 . V_25 & V_56 ) ) {
F_32 ( & V_23 -> V_37 -> V_62 ) ;
F_22 ( V_23 ) ;
F_33 ( & V_23 -> V_37 -> V_62 ) ;
}
if ( F_3 ( V_27 ) )
F_69 ( & V_23 ) ;
return V_27 ;
}
T_3 F_103 ( struct V_8 * V_9 ,
unsigned long V_161 ,
unsigned V_162 )
{
unsigned V_163 = ( F_104 ( V_161 ) ) >> V_72 ;
T_3 V_15 = 0 ;
V_15 += F_105 ( V_162 ) ;
V_15 += F_105 ( V_163 * sizeof( void * ) ) ;
V_15 += F_105 ( sizeof( struct V_164 ) ) ;
return V_15 ;
}
T_3 F_106 ( struct V_8 * V_9 ,
unsigned long V_161 ,
unsigned V_162 )
{
unsigned V_163 = ( F_104 ( V_161 ) ) >> V_72 ;
T_3 V_15 = 0 ;
V_15 += F_105 ( V_162 ) ;
V_15 += F_105 ( V_163 * ( 2 * sizeof( void * ) + sizeof( V_165 ) ) ) ;
V_15 += F_105 ( sizeof( struct V_166 ) ) ;
return V_15 ;
}
int F_107 ( struct V_8 * V_9 ,
unsigned long V_15 ,
enum V_152 type ,
struct V_24 * V_25 ,
T_1 V_149 ,
bool V_79 ,
struct V_153 * V_154 ,
struct V_22 * * V_120 )
{
struct V_22 * V_23 ;
T_3 V_42 ;
int V_27 ;
V_23 = F_108 ( sizeof( * V_23 ) , V_167 ) ;
if ( F_3 ( V_23 == NULL ) )
return - V_74 ;
V_42 = F_103 ( V_9 , V_15 , sizeof( struct V_22 ) ) ;
V_27 = F_91 ( V_9 , V_23 , V_15 , type , V_25 , V_149 ,
V_79 , V_154 , V_42 ,
NULL , NULL , NULL ) ;
if ( F_102 ( V_27 == 0 ) )
* V_120 = V_23 ;
return V_27 ;
}
static int F_109 ( struct V_8 * V_9 ,
unsigned V_3 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
struct V_36 * V_37 = V_9 -> V_37 ;
struct V_100 * V_101 ;
int V_27 ;
unsigned V_26 ;
F_32 ( & V_37 -> V_62 ) ;
for ( V_26 = 0 ; V_26 < V_131 ; ++ V_26 ) {
while ( ! F_14 ( & V_11 -> V_45 [ V_26 ] ) ) {
F_33 ( & V_37 -> V_62 ) ;
V_27 = F_76 ( V_9 , V_3 , NULL , false , false ) ;
if ( V_27 )
return V_27 ;
F_32 ( & V_37 -> V_62 ) ;
}
}
F_33 ( & V_37 -> V_62 ) ;
F_32 ( & V_11 -> V_134 ) ;
V_101 = F_80 ( V_11 -> V_91 ) ;
F_33 ( & V_11 -> V_134 ) ;
if ( V_101 ) {
V_27 = F_110 ( V_101 , false ) ;
F_17 ( V_101 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
int F_111 ( struct V_8 * V_9 , unsigned V_3 )
{
struct V_10 * V_11 ;
int V_27 = - V_7 ;
if ( V_3 >= V_168 ) {
F_5 ( L_18 , V_3 ) ;
return V_27 ;
}
V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( ! V_11 -> V_12 ) {
F_5 ( L_19 ,
V_3 ) ;
return V_27 ;
}
F_17 ( V_11 -> V_91 ) ;
V_11 -> V_13 = false ;
V_11 -> V_12 = false ;
V_27 = 0 ;
if ( V_3 > 0 ) {
V_27 = F_109 ( V_9 , V_3 ) ;
if ( V_27 ) {
F_5 ( L_20 ) ;
return V_27 ;
}
V_27 = (* V_11 -> V_19 -> V_169 )( V_11 ) ;
}
return V_27 ;
}
int F_112 ( struct V_8 * V_9 , unsigned V_3 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( V_3 == 0 || V_3 >= V_168 ) {
F_5 ( L_21 , V_3 ) ;
return - V_7 ;
}
if ( ! V_11 -> V_12 ) {
F_5 ( L_22 , V_3 ) ;
return 0 ;
}
return F_109 ( V_9 , V_3 ) ;
}
int F_113 ( struct V_8 * V_9 , unsigned type ,
unsigned long V_170 )
{
int V_27 = - V_7 ;
struct V_10 * V_11 ;
unsigned V_26 ;
F_12 ( type >= V_168 ) ;
V_11 = & V_9 -> V_11 [ type ] ;
F_12 ( V_11 -> V_12 ) ;
V_11 -> V_171 = true ;
V_11 -> V_172 = false ;
F_96 ( & V_11 -> V_173 ) ;
F_114 ( & V_11 -> V_134 ) ;
F_95 ( & V_11 -> V_159 ) ;
V_27 = V_9 -> V_70 -> V_174 ( V_9 , type , V_11 ) ;
if ( V_27 )
return V_27 ;
V_11 -> V_9 = V_9 ;
V_27 = 0 ;
if ( type != V_18 ) {
V_27 = (* V_11 -> V_19 -> V_175 )( V_11 , V_170 ) ;
if ( V_27 )
return V_27 ;
}
V_11 -> V_12 = true ;
V_11 -> V_13 = true ;
V_11 -> V_15 = V_170 ;
for ( V_26 = 0 ; V_26 < V_131 ; ++ V_26 )
F_95 ( & V_11 -> V_45 [ V_26 ] ) ;
V_11 -> V_91 = NULL ;
return 0 ;
}
static void F_115 ( struct V_31 * V_32 )
{
struct V_36 * V_37 =
F_8 ( V_32 , struct V_36 , V_32 ) ;
F_116 ( V_37 -> V_53 , & V_37 -> V_176 ) ;
F_117 ( V_37 -> V_73 ) ;
F_20 ( V_37 ) ;
}
void F_118 ( struct V_177 * V_178 )
{
struct V_36 * V_37 = V_178 -> V_179 ;
F_119 ( & V_37 -> V_32 ) ;
F_120 ( & V_37 -> V_32 ) ;
}
int F_121 ( struct V_177 * V_178 )
{
struct V_180 * V_181 =
F_8 ( V_178 , struct V_180 , V_178 ) ;
struct V_36 * V_37 = V_178 -> V_179 ;
int V_27 ;
unsigned V_26 ;
F_96 ( & V_37 -> V_182 ) ;
F_114 ( & V_37 -> V_62 ) ;
V_37 -> V_53 = V_181 -> V_53 ;
V_37 -> V_73 = F_122 ( V_183 | V_184 ) ;
if ( F_3 ( V_37 -> V_73 == NULL ) ) {
V_27 = - V_74 ;
goto V_185;
}
for ( V_26 = 0 ; V_26 < V_131 ; ++ V_26 )
F_95 ( & V_37 -> V_61 [ V_26 ] ) ;
F_95 ( & V_37 -> V_186 ) ;
F_123 ( & V_37 -> V_176 , V_187 ) ;
V_27 = F_124 ( V_37 -> V_53 , & V_37 -> V_176 ) ;
if ( F_3 ( V_27 != 0 ) ) {
F_5 ( L_23 ) ;
goto V_188;
}
F_94 ( & V_37 -> V_39 , 0 ) ;
V_27 = F_125 (
& V_37 -> V_32 , & V_189 , F_126 () , L_24 ) ;
if ( F_3 ( V_27 != 0 ) )
F_120 ( & V_37 -> V_32 ) ;
return V_27 ;
V_188:
F_117 ( V_37 -> V_73 ) ;
V_185:
F_20 ( V_37 ) ;
return V_27 ;
}
int F_127 ( struct V_8 * V_9 )
{
int V_27 = 0 ;
unsigned V_26 = V_168 ;
struct V_10 * V_11 ;
struct V_36 * V_37 = V_9 -> V_37 ;
while ( V_26 -- ) {
V_11 = & V_9 -> V_11 [ V_26 ] ;
if ( V_11 -> V_12 ) {
V_11 -> V_13 = false ;
if ( ( V_26 != V_18 ) && F_111 ( V_9 , V_26 ) ) {
V_27 = - V_109 ;
F_5 ( L_25 ,
V_26 ) ;
}
V_11 -> V_12 = false ;
}
}
F_128 ( & V_37 -> V_182 ) ;
F_129 ( & V_9 -> V_186 ) ;
F_130 ( & V_37 -> V_182 ) ;
F_71 ( & V_9 -> V_106 ) ;
while ( F_63 ( V_9 , true ) )
;
F_32 ( & V_37 -> V_62 ) ;
if ( F_14 ( & V_9 -> V_46 ) )
F_131 ( L_26 ) ;
for ( V_26 = 0 ; V_26 < V_131 ; ++ V_26 )
if ( F_14 ( & V_9 -> V_11 [ 0 ] . V_45 [ 0 ] ) )
F_131 ( L_27 , V_26 ) ;
F_33 ( & V_37 -> V_62 ) ;
F_132 ( & V_9 -> V_118 ) ;
return V_27 ;
}
int F_133 ( struct V_8 * V_9 ,
struct V_36 * V_37 ,
struct V_190 * V_70 ,
struct V_191 * V_192 ,
T_4 V_193 ,
bool V_65 )
{
int V_27 = - V_7 ;
V_9 -> V_70 = V_70 ;
memset ( V_9 -> V_11 , 0 , sizeof( V_9 -> V_11 ) ) ;
V_27 = F_113 ( V_9 , V_18 , 0 ) ;
if ( F_3 ( V_27 != 0 ) )
goto V_194;
F_134 ( & V_9 -> V_118 , V_193 ,
0x10000000 ) ;
F_135 ( & V_9 -> V_106 , F_65 ) ;
F_95 ( & V_9 -> V_46 ) ;
V_9 -> V_195 = V_192 ;
V_9 -> V_37 = V_37 ;
V_9 -> V_65 = V_65 ;
F_128 ( & V_37 -> V_182 ) ;
F_24 ( & V_9 -> V_186 , & V_37 -> V_186 ) ;
F_130 ( & V_37 -> V_182 ) ;
return 0 ;
V_194:
return V_27 ;
}
bool F_38 ( struct V_8 * V_9 , struct V_77 * V_28 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_28 -> V_3 ] ;
if ( ! ( V_11 -> V_5 & V_87 ) ) {
if ( V_28 -> V_3 == V_18 )
return false ;
if ( V_11 -> V_5 & V_196 )
return false ;
if ( V_28 -> V_25 & V_139 )
return false ;
}
return true ;
}
void F_40 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
F_136 ( & V_23 -> V_119 , V_9 -> V_195 ) ;
F_68 ( V_23 ) ;
}
void F_137 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_23 -> V_28 . V_3 ] ;
F_39 ( V_11 , false ) ;
F_40 ( V_23 ) ;
F_41 ( V_11 ) ;
}
int F_57 ( struct V_22 * V_23 ,
bool V_79 , bool V_197 )
{
long V_198 = 15 * V_107 ;
if ( V_197 ) {
if ( F_138 ( V_23 -> V_49 , true ) )
return 0 ;
else
return - V_109 ;
}
V_198 = F_61 ( V_23 -> V_49 , true ,
V_79 , V_198 ) ;
if ( V_198 < 0 )
return V_198 ;
if ( V_198 == 0 )
return - V_109 ;
F_139 ( V_23 -> V_49 , NULL ) ;
return 0 ;
}
int F_140 ( struct V_22 * V_23 , bool V_197 )
{
int V_27 = 0 ;
V_27 = F_141 ( V_23 , true , V_197 , NULL ) ;
if ( F_3 ( V_27 != 0 ) )
return V_27 ;
V_27 = F_57 ( V_23 , true , V_197 ) ;
if ( F_102 ( V_27 == 0 ) )
F_98 ( & V_23 -> V_43 ) ;
F_78 ( V_23 ) ;
return V_27 ;
}
void F_142 ( struct V_22 * V_23 )
{
F_16 ( & V_23 -> V_43 ) ;
}
static int V_187 ( struct V_199 * V_176 )
{
struct V_36 * V_37 =
F_8 ( V_176 , struct V_36 , V_176 ) ;
struct V_22 * V_23 ;
int V_27 = - V_109 ;
unsigned V_26 ;
F_32 ( & V_37 -> V_62 ) ;
for ( V_26 = 0 ; V_26 < V_131 ; ++ V_26 ) {
F_77 (bo, &glob->swap_lru[i], swap) {
V_27 = F_56 ( V_23 , false , true , NULL ) ;
if ( ! V_27 )
break;
}
if ( ! V_27 )
break;
}
if ( V_27 ) {
F_33 ( & V_37 -> V_62 ) ;
return V_27 ;
}
F_25 ( & V_23 -> V_41 ) ;
if ( ! F_14 ( & V_23 -> V_46 ) ) {
V_27 = F_60 ( V_23 , false , false ) ;
F_30 ( & V_23 -> V_41 , F_11 ) ;
return V_27 ;
}
F_28 ( V_23 ) ;
F_33 ( & V_37 -> V_62 ) ;
if ( V_23 -> V_28 . V_3 != V_18 ||
V_23 -> V_47 -> V_200 != V_201 ) {
struct V_77 V_122 ;
V_122 = V_23 -> V_28 ;
V_122 . V_44 = NULL ;
V_122 . V_25 = V_160 | V_139 ;
V_122 . V_3 = V_18 ;
V_27 = F_37 ( V_23 , & V_122 , true ,
false , false ) ;
if ( F_3 ( V_27 != 0 ) )
goto V_115;
}
V_27 = F_57 ( V_23 , false , false ) ;
if ( F_3 ( V_27 != 0 ) )
goto V_115;
F_137 ( V_23 ) ;
if ( V_23 -> V_9 -> V_70 -> V_202 )
V_23 -> V_9 -> V_70 -> V_202 ( V_23 ) ;
V_27 = F_143 ( V_23 -> V_47 , V_23 -> V_154 ) ;
V_115:
F_58 ( V_23 ) ;
F_30 ( & V_23 -> V_41 , F_11 ) ;
return V_27 ;
}
void F_144 ( struct V_8 * V_9 )
{
while ( V_187 ( & V_9 -> V_37 -> V_176 ) == 0 )
;
}
int F_145 ( struct V_22 * V_23 )
{
int V_27 ;
V_27 = F_146 ( & V_23 -> V_51 ) ;
if ( F_3 ( V_27 != 0 ) )
return - V_128 ;
if ( ! F_147 ( & V_23 -> V_49 -> V_54 ) )
goto V_112;
V_27 = F_56 ( V_23 , true , false , NULL ) ;
if ( F_3 ( V_27 != 0 ) )
goto V_112;
F_58 ( V_23 ) ;
V_112:
F_130 ( & V_23 -> V_51 ) ;
return V_27 ;
}
