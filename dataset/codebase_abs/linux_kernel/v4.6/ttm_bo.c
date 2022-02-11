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
struct V_10 * V_11 ;
F_19 ( & V_23 -> V_48 -> V_53 . V_54 ) ;
if ( ! ( V_23 -> V_27 . V_25 & V_55 ) ) {
F_10 ( ! F_11 ( & V_23 -> V_45 ) ) ;
V_11 = & V_9 -> V_11 [ V_23 -> V_27 . V_3 ] ;
F_20 ( & V_23 -> V_45 , & V_11 -> V_45 ) ;
F_21 ( & V_23 -> V_40 ) ;
if ( V_23 -> V_47 && ! ( V_23 -> V_47 -> V_56 & V_57 ) ) {
F_20 ( & V_23 -> V_58 , & V_23 -> V_36 -> V_59 ) ;
F_21 ( & V_23 -> V_40 ) ;
}
}
}
int F_22 ( struct V_22 * V_23 )
{
int V_60 = 0 ;
if ( ! F_11 ( & V_23 -> V_58 ) ) {
F_23 ( & V_23 -> V_58 ) ;
++ V_60 ;
}
if ( ! F_11 ( & V_23 -> V_45 ) ) {
F_23 ( & V_23 -> V_45 ) ;
++ V_60 ;
}
return V_60 ;
}
static void F_24 ( struct V_39 * V_40 )
{
F_25 () ;
}
void F_26 ( struct V_22 * V_23 , int V_61 ,
bool V_62 )
{
F_27 ( & V_23 -> V_40 , V_61 ,
( V_62 ) ? F_24 : F_9 ) ;
}
void F_28 ( struct V_22 * V_23 )
{
int V_60 ;
F_29 ( & V_23 -> V_36 -> V_63 ) ;
V_60 = F_22 ( V_23 ) ;
F_30 ( & V_23 -> V_36 -> V_63 ) ;
F_26 ( V_23 , V_60 , true ) ;
}
void F_31 ( struct V_22 * V_23 )
{
int V_60 = 0 ;
F_19 ( & V_23 -> V_48 -> V_53 . V_54 ) ;
V_60 = F_22 ( V_23 ) ;
F_26 ( V_23 , V_60 , true ) ;
F_18 ( V_23 ) ;
}
static int F_32 ( struct V_22 * V_23 , bool V_64 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_35 * V_36 = V_23 -> V_36 ;
int V_26 = 0 ;
T_1 V_56 = 0 ;
F_33 ( & V_23 -> V_65 ) ;
V_23 -> V_47 = NULL ;
if ( V_9 -> V_66 )
V_56 |= V_67 ;
switch ( V_23 -> type ) {
case V_68 :
if ( V_64 )
V_56 |= V_69 ;
case V_70 :
V_23 -> V_47 = V_9 -> V_71 -> V_72 ( V_9 , V_23 -> V_28 << V_73 ,
V_56 , V_36 -> V_74 ) ;
if ( F_34 ( V_23 -> V_47 == NULL ) )
V_26 = - V_75 ;
break;
case V_76 :
V_23 -> V_47 = V_9 -> V_71 -> V_72 ( V_9 , V_23 -> V_28 << V_73 ,
V_56 | V_57 ,
V_36 -> V_74 ) ;
if ( F_34 ( V_23 -> V_47 == NULL ) ) {
V_26 = - V_75 ;
break;
}
V_23 -> V_47 -> V_77 = V_23 -> V_77 ;
break;
default:
F_3 ( L_11 ) ;
V_26 = - V_7 ;
break;
}
return V_26 ;
}
static int F_35 ( struct V_22 * V_23 ,
struct V_78 * V_27 ,
bool V_79 , bool V_80 ,
bool V_81 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
bool V_82 = F_36 ( V_9 , & V_23 -> V_27 ) ;
bool V_83 = F_36 ( V_9 , V_27 ) ;
struct V_10 * V_84 = & V_9 -> V_11 [ V_23 -> V_27 . V_3 ] ;
struct V_10 * V_85 = & V_9 -> V_11 [ V_27 -> V_3 ] ;
int V_26 = 0 ;
if ( V_82 || V_83 ||
( ( V_27 -> V_25 & V_23 -> V_27 . V_25 & V_86 ) == 0 ) ) {
V_26 = F_37 ( V_84 , true ) ;
if ( F_34 ( V_26 != 0 ) )
goto V_87;
F_38 ( V_23 ) ;
F_39 ( V_84 ) ;
}
if ( ! ( V_85 -> V_6 & V_88 ) ) {
if ( V_23 -> V_47 == NULL ) {
bool V_89 = ! ( V_84 -> V_6 & V_88 ) ;
V_26 = F_32 ( V_23 , V_89 ) ;
if ( V_26 )
goto V_87;
}
V_26 = F_40 ( V_23 -> V_47 , V_27 -> V_25 ) ;
if ( V_26 )
goto V_87;
if ( V_27 -> V_3 != V_18 ) {
V_26 = F_41 ( V_23 -> V_47 , V_27 ) ;
if ( V_26 )
goto V_87;
}
if ( V_23 -> V_27 . V_3 == V_18 ) {
if ( V_9 -> V_71 -> V_90 )
V_9 -> V_71 -> V_90 ( V_23 , V_27 ) ;
V_23 -> V_27 = * V_27 ;
V_27 -> V_44 = NULL ;
goto V_91;
}
}
if ( V_9 -> V_71 -> V_90 )
V_9 -> V_71 -> V_90 ( V_23 , V_27 ) ;
if ( ! ( V_84 -> V_6 & V_88 ) &&
! ( V_85 -> V_6 & V_88 ) )
V_26 = F_42 ( V_23 , V_79 , V_81 , V_27 ) ;
else if ( V_9 -> V_71 -> V_92 )
V_26 = V_9 -> V_71 -> V_92 ( V_23 , V_79 , V_80 ,
V_81 , V_27 ) ;
else
V_26 = F_43 ( V_23 , V_79 , V_81 , V_27 ) ;
if ( V_26 ) {
if ( V_9 -> V_71 -> V_90 ) {
struct V_78 V_93 = * V_27 ;
* V_27 = V_23 -> V_27 ;
V_23 -> V_27 = V_93 ;
V_9 -> V_71 -> V_90 ( V_23 , V_27 ) ;
V_23 -> V_27 = * V_27 ;
* V_27 = V_93 ;
}
goto V_87;
}
V_91:
if ( V_23 -> V_94 ) {
if ( V_9 -> V_71 -> V_95 ) {
V_26 = V_9 -> V_71 -> V_95 ( V_9 , V_23 -> V_27 . V_25 ) ;
if ( V_26 )
F_3 ( L_12 ) ;
}
V_23 -> V_94 = false ;
}
if ( V_23 -> V_27 . V_44 ) {
V_23 -> V_96 = ( V_23 -> V_27 . V_97 << V_73 ) +
V_9 -> V_11 [ V_23 -> V_27 . V_3 ] . V_14 ;
V_23 -> V_98 = V_23 -> V_27 . V_25 ;
} else
V_23 -> V_96 = 0 ;
return 0 ;
V_87:
V_85 = & V_9 -> V_11 [ V_23 -> V_27 . V_3 ] ;
if ( ( V_85 -> V_6 & V_88 ) && V_23 -> V_47 ) {
F_44 ( V_23 -> V_47 ) ;
F_12 ( V_23 -> V_47 ) ;
V_23 -> V_47 = NULL ;
}
return V_26 ;
}
static void F_45 ( struct V_22 * V_23 )
{
if ( V_23 -> V_9 -> V_71 -> V_90 )
V_23 -> V_9 -> V_71 -> V_90 ( V_23 , NULL ) ;
if ( V_23 -> V_47 ) {
F_44 ( V_23 -> V_47 ) ;
F_12 ( V_23 -> V_47 ) ;
V_23 -> V_47 = NULL ;
}
F_46 ( V_23 , & V_23 -> V_27 ) ;
F_47 ( & V_23 -> V_48 -> V_53 ) ;
}
static void F_48 ( struct V_22 * V_23 )
{
struct V_99 * V_100 ;
struct V_101 * V_101 ;
int V_4 ;
V_100 = F_49 ( V_23 -> V_48 ) ;
V_101 = F_50 ( V_23 -> V_48 ) ;
if ( V_101 && ! V_101 -> V_102 -> V_103 )
F_51 ( V_101 ) ;
for ( V_4 = 0 ; V_100 && V_4 < V_100 -> V_104 ; ++ V_4 ) {
V_101 = F_52 ( V_100 -> V_105 [ V_4 ] ,
F_53 ( V_23 -> V_48 ) ) ;
if ( ! V_101 -> V_102 -> V_103 )
F_51 ( V_101 ) ;
}
}
static void F_54 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_35 * V_36 = V_23 -> V_36 ;
int V_60 ;
int V_26 ;
F_29 ( & V_36 -> V_63 ) ;
V_26 = F_55 ( V_23 , false , true , false , NULL ) ;
if ( ! V_26 ) {
if ( ! F_56 ( V_23 , false , false , true ) ) {
V_60 = F_22 ( V_23 ) ;
F_30 ( & V_36 -> V_63 ) ;
F_45 ( V_23 ) ;
F_26 ( V_23 , V_60 , true ) ;
return;
} else
F_48 ( V_23 ) ;
if ( V_23 -> V_27 . V_25 & V_55 ) {
V_23 -> V_27 . V_25 &= ~ V_55 ;
F_18 ( V_23 ) ;
}
F_57 ( V_23 ) ;
}
F_21 ( & V_23 -> V_40 ) ;
F_20 ( & V_23 -> V_46 , & V_9 -> V_46 ) ;
F_30 ( & V_36 -> V_63 ) ;
F_58 ( & V_9 -> V_106 ,
( ( V_107 / 100 ) < 1 ) ? 1 : V_107 / 100 ) ;
}
static int F_59 ( struct V_22 * V_23 ,
bool V_80 ,
bool V_81 )
{
struct V_35 * V_36 = V_23 -> V_36 ;
int V_60 ;
int V_26 ;
V_26 = F_56 ( V_23 , false , false , true ) ;
if ( V_26 && ! V_81 ) {
long V_108 ;
F_47 ( & V_23 -> V_48 -> V_53 ) ;
F_30 ( & V_36 -> V_63 ) ;
V_108 = F_60 ( V_23 -> V_48 ,
true ,
V_80 ,
30 * V_107 ) ;
if ( V_108 < 0 )
return V_108 ;
else if ( V_108 == 0 )
return - V_109 ;
F_29 ( & V_36 -> V_63 ) ;
V_26 = F_55 ( V_23 , false , true , false , NULL ) ;
if ( V_26 ) {
F_30 ( & V_36 -> V_63 ) ;
return 0 ;
}
V_26 = F_56 ( V_23 , false , false , true ) ;
F_61 ( V_26 ) ;
}
if ( V_26 || F_34 ( F_11 ( & V_23 -> V_46 ) ) ) {
F_57 ( V_23 ) ;
F_30 ( & V_36 -> V_63 ) ;
return V_26 ;
}
V_60 = F_22 ( V_23 ) ;
F_23 ( & V_23 -> V_46 ) ;
++ V_60 ;
F_30 ( & V_36 -> V_63 ) ;
F_45 ( V_23 ) ;
F_26 ( V_23 , V_60 , true ) ;
return 0 ;
}
static int F_62 ( struct V_8 * V_9 , bool V_110 )
{
struct V_35 * V_36 = V_9 -> V_36 ;
struct V_22 * V_111 = NULL ;
int V_26 = 0 ;
F_29 ( & V_36 -> V_63 ) ;
if ( F_11 ( & V_9 -> V_46 ) )
goto V_112;
V_111 = F_63 ( & V_9 -> V_46 ,
struct V_22 , V_46 ) ;
F_21 ( & V_111 -> V_40 ) ;
for (; ; ) {
struct V_22 * V_113 = NULL ;
if ( V_111 -> V_46 . V_114 != & V_9 -> V_46 ) {
V_113 = F_63 ( & V_111 -> V_46 ,
struct V_22 , V_46 ) ;
F_21 ( & V_113 -> V_40 ) ;
}
V_26 = F_55 ( V_111 , false , true , false , NULL ) ;
if ( V_110 && V_26 ) {
F_30 ( & V_36 -> V_63 ) ;
V_26 = F_55 ( V_111 , false , false ,
false , NULL ) ;
F_29 ( & V_36 -> V_63 ) ;
}
if ( ! V_26 )
V_26 = F_59 ( V_111 , false ,
! V_110 ) ;
else
F_30 ( & V_36 -> V_63 ) ;
F_64 ( & V_111 -> V_40 , F_9 ) ;
V_111 = V_113 ;
if ( V_26 || ! V_111 )
goto V_115;
F_29 ( & V_36 -> V_63 ) ;
if ( F_11 ( & V_111 -> V_46 ) )
break;
}
V_112:
F_30 ( & V_36 -> V_63 ) ;
V_115:
if ( V_111 )
F_64 ( & V_111 -> V_40 , F_9 ) ;
return V_26 ;
}
static void F_65 ( struct V_116 * V_117 )
{
struct V_8 * V_9 =
F_6 ( V_117 , struct V_8 , V_106 . V_117 ) ;
if ( F_62 ( V_9 , false ) ) {
F_58 ( & V_9 -> V_106 ,
( ( V_107 / 100 ) < 1 ) ? 1 : V_107 / 100 ) ;
}
}
static void F_66 ( struct V_39 * V_39 )
{
struct V_22 * V_23 =
F_6 ( V_39 , struct V_22 , V_39 ) ;
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_23 -> V_27 . V_3 ] ;
F_67 ( & V_9 -> V_118 , & V_23 -> V_119 ) ;
F_37 ( V_11 , false ) ;
F_68 ( V_23 ) ;
F_39 ( V_11 ) ;
F_54 ( V_23 ) ;
F_64 ( & V_23 -> V_40 , F_9 ) ;
}
void F_69 ( struct V_22 * * V_120 )
{
struct V_22 * V_23 = * V_120 ;
* V_120 = NULL ;
F_64 ( & V_23 -> V_39 , F_66 ) ;
}
int F_70 ( struct V_8 * V_9 )
{
return F_71 ( & V_9 -> V_106 ) ;
}
void F_72 ( struct V_8 * V_9 , int V_121 )
{
if ( V_121 )
F_58 ( & V_9 -> V_106 ,
( ( V_107 / 100 ) < 1 ) ? 1 : V_107 / 100 ) ;
}
static int F_73 ( struct V_22 * V_23 , bool V_80 ,
bool V_81 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_78 V_122 ;
struct V_24 V_25 ;
int V_26 = 0 ;
V_26 = F_56 ( V_23 , false , V_80 , V_81 ) ;
if ( F_34 ( V_26 != 0 ) ) {
if ( V_26 != - V_123 ) {
F_3 ( L_13 ) ;
}
goto V_115;
}
F_19 ( & V_23 -> V_48 -> V_53 . V_54 ) ;
V_122 = V_23 -> V_27 ;
V_122 . V_44 = NULL ;
V_122 . V_124 . V_125 = false ;
V_122 . V_124 . V_126 = 0 ;
V_25 . V_29 = 0 ;
V_25 . V_127 = 0 ;
V_9 -> V_71 -> V_128 ( V_23 , & V_25 ) ;
V_26 = F_74 ( V_23 , & V_25 , & V_122 , V_80 ,
V_81 ) ;
if ( V_26 ) {
if ( V_26 != - V_123 ) {
F_3 ( L_14 ,
V_23 ) ;
F_4 ( V_23 , & V_25 ) ;
}
goto V_115;
}
V_26 = F_35 ( V_23 , & V_122 , true , V_80 ,
V_81 ) ;
if ( V_26 ) {
if ( V_26 != - V_123 )
F_3 ( L_15 ) ;
F_46 ( V_23 , & V_122 ) ;
goto V_115;
}
V_23 -> V_94 = true ;
V_115:
return V_26 ;
}
static int F_75 ( struct V_8 * V_9 ,
T_1 V_3 ,
const struct V_1 * V_2 ,
bool V_80 ,
bool V_81 )
{
struct V_35 * V_36 = V_9 -> V_36 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
struct V_22 * V_23 ;
int V_26 = - V_109 , V_60 ;
F_29 ( & V_36 -> V_63 ) ;
F_76 (bo, &man->lru, lru) {
V_26 = F_55 ( V_23 , false , true , false , NULL ) ;
if ( ! V_26 ) {
if ( V_2 && ( V_2 -> V_129 || V_2 -> V_130 ) ) {
if ( V_2 -> V_129 >= ( V_23 -> V_27 . V_97 + V_23 -> V_27 . V_15 ) ||
( V_2 -> V_130 && V_2 -> V_130 <= V_23 -> V_27 . V_97 ) ) {
F_57 ( V_23 ) ;
V_26 = - V_109 ;
continue;
}
}
break;
}
}
if ( V_26 ) {
F_30 ( & V_36 -> V_63 ) ;
return V_26 ;
}
F_21 ( & V_23 -> V_40 ) ;
if ( ! F_11 ( & V_23 -> V_46 ) ) {
V_26 = F_59 ( V_23 , V_80 ,
V_81 ) ;
F_64 ( & V_23 -> V_40 , F_9 ) ;
return V_26 ;
}
V_60 = F_22 ( V_23 ) ;
F_30 ( & V_36 -> V_63 ) ;
F_10 ( V_26 != 0 ) ;
F_26 ( V_23 , V_60 , true ) ;
V_26 = F_73 ( V_23 , V_80 , V_81 ) ;
F_77 ( V_23 ) ;
F_64 ( & V_23 -> V_40 , F_9 ) ;
return V_26 ;
}
void F_46 ( struct V_22 * V_23 , struct V_78 * V_27 )
{
struct V_10 * V_11 = & V_23 -> V_9 -> V_11 [ V_27 -> V_3 ] ;
if ( V_27 -> V_44 )
(* V_11 -> V_19 -> V_131 )( V_11 , V_27 ) ;
}
static int F_78 ( struct V_22 * V_23 ,
T_1 V_3 ,
const struct V_1 * V_2 ,
struct V_78 * V_27 ,
bool V_80 ,
bool V_81 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
int V_26 ;
do {
V_26 = (* V_11 -> V_19 -> V_132 )( V_11 , V_23 , V_2 , V_27 ) ;
if ( F_34 ( V_26 != 0 ) )
return V_26 ;
if ( V_27 -> V_44 )
break;
V_26 = F_75 ( V_9 , V_3 , V_2 ,
V_80 , V_81 ) ;
if ( F_34 ( V_26 != 0 ) )
return V_26 ;
} while ( 1 );
if ( V_27 -> V_44 == NULL )
return - V_75 ;
V_27 -> V_3 = V_3 ;
return 0 ;
}
static T_1 F_79 ( struct V_10 * V_11 ,
T_1 V_98 ,
T_1 V_133 )
{
T_1 V_134 = V_133 & V_86 ;
T_1 V_135 = V_133 & ~ V_86 ;
if ( ( V_98 & V_134 ) != 0 )
V_135 |= ( V_98 & V_134 ) ;
else if ( ( V_11 -> V_17 & V_134 ) != 0 )
V_135 |= V_11 -> V_17 ;
else if ( ( V_136 & V_134 ) != 0 )
V_135 |= V_136 ;
else if ( ( V_137 & V_134 ) != 0 )
V_135 |= V_137 ;
else if ( ( V_138 & V_134 ) != 0 )
V_135 |= V_138 ;
return V_135 ;
}
static bool F_80 ( struct V_10 * V_11 ,
T_1 V_3 ,
const struct V_1 * V_2 ,
T_1 * V_139 )
{
T_1 V_140 = F_8 ( V_3 ) ;
if ( ( V_140 & V_2 -> V_6 & V_141 ) == 0 )
return false ;
if ( ( V_2 -> V_6 & V_11 -> V_16 ) == 0 )
return false ;
V_140 |= ( V_2 -> V_6 & V_11 -> V_16 ) ;
* V_139 = V_140 ;
return true ;
}
int F_74 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_78 * V_27 ,
bool V_80 ,
bool V_81 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 ;
T_1 V_3 = V_18 ;
T_1 V_140 = 0 ;
bool V_142 = false ;
bool V_143 = false ;
bool V_144 = false ;
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
V_143 = F_80 ( V_11 , V_3 , V_2 ,
& V_140 ) ;
if ( ! V_143 )
continue;
V_142 = true ;
V_140 = F_79 ( V_11 , V_23 -> V_27 . V_25 ,
V_140 ) ;
F_81 ( & V_140 , V_2 -> V_6 ,
~ V_145 ) ;
if ( V_3 == V_18 )
break;
V_26 = (* V_11 -> V_19 -> V_132 )( V_11 , V_23 , V_2 , V_27 ) ;
if ( F_34 ( V_26 ) )
return V_26 ;
if ( V_27 -> V_44 )
break;
}
if ( ( V_143 && ( V_3 == V_18 ) ) || V_27 -> V_44 ) {
V_27 -> V_3 = V_3 ;
V_27 -> V_25 = V_140 ;
return 0 ;
}
for ( V_4 = 0 ; V_4 < V_25 -> V_127 ; ++ V_4 ) {
const struct V_1 * V_2 = & V_25 -> V_146 [ V_4 ] ;
V_26 = F_1 ( V_2 , & V_3 ) ;
if ( V_26 )
return V_26 ;
V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( ! V_11 -> V_12 || ! V_11 -> V_13 )
continue;
if ( ! F_80 ( V_11 , V_3 , V_2 , & V_140 ) )
continue;
V_142 = true ;
V_140 = F_79 ( V_11 , V_23 -> V_27 . V_25 ,
V_140 ) ;
F_81 ( & V_140 , V_2 -> V_6 ,
~ V_145 ) ;
if ( V_3 == V_18 ) {
V_27 -> V_3 = V_3 ;
V_27 -> V_25 = V_140 ;
V_27 -> V_44 = NULL ;
return 0 ;
}
V_26 = F_78 ( V_23 , V_3 , V_2 , V_27 ,
V_80 , V_81 ) ;
if ( V_26 == 0 && V_27 -> V_44 ) {
V_27 -> V_25 = V_140 ;
return 0 ;
}
if ( V_26 == - V_123 )
V_144 = true ;
}
if ( ! V_142 ) {
F_82 (KERN_ERR TTM_PFX L_16 ) ;
return - V_7 ;
}
return ( V_144 ) ? - V_123 : - V_75 ;
}
static int F_83 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
bool V_80 ,
bool V_81 )
{
int V_26 = 0 ;
struct V_78 V_27 ;
F_19 ( & V_23 -> V_48 -> V_53 . V_54 ) ;
V_26 = F_56 ( V_23 , false , V_80 , V_81 ) ;
if ( V_26 )
return V_26 ;
V_27 . V_28 = V_23 -> V_28 ;
V_27 . V_15 = V_27 . V_28 << V_73 ;
V_27 . V_147 = V_23 -> V_27 . V_147 ;
V_27 . V_124 . V_125 = false ;
V_27 . V_124 . V_126 = 0 ;
V_26 = F_74 ( V_23 , V_25 , & V_27 ,
V_80 , V_81 ) ;
if ( V_26 )
goto V_112;
V_26 = F_35 ( V_23 , & V_27 , false ,
V_80 , V_81 ) ;
V_112:
if ( V_26 && V_27 . V_44 )
F_46 ( V_23 , & V_27 ) ;
return V_26 ;
}
static bool F_84 ( struct V_24 * V_25 ,
struct V_78 * V_27 ,
T_1 * V_148 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_25 -> V_29 ; V_4 ++ ) {
const struct V_1 * V_149 = & V_25 -> V_25 [ V_4 ] ;
if ( V_27 -> V_44 &&
( V_27 -> V_97 < V_149 -> V_129 ||
( V_149 -> V_130 != 0 && ( V_27 -> V_97 + V_27 -> V_28 ) > V_149 -> V_130 ) ) )
continue;
* V_148 = V_149 -> V_6 ;
if ( ( * V_148 & V_27 -> V_25 & V_86 ) &&
( * V_148 & V_27 -> V_25 & V_141 ) )
return true ;
}
for ( V_4 = 0 ; V_4 < V_25 -> V_127 ; V_4 ++ ) {
const struct V_1 * V_149 = & V_25 -> V_146 [ V_4 ] ;
if ( V_27 -> V_44 &&
( V_27 -> V_97 < V_149 -> V_129 ||
( V_149 -> V_130 != 0 && ( V_27 -> V_97 + V_27 -> V_28 ) > V_149 -> V_130 ) ) )
continue;
* V_148 = V_149 -> V_6 ;
if ( ( * V_148 & V_27 -> V_25 & V_86 ) &&
( * V_148 & V_27 -> V_25 & V_141 ) )
return true ;
}
return false ;
}
int F_85 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
bool V_80 ,
bool V_81 )
{
int V_26 ;
T_1 V_148 ;
F_19 ( & V_23 -> V_48 -> V_53 . V_54 ) ;
if ( ! F_84 ( V_25 , & V_23 -> V_27 , & V_148 ) ) {
V_26 = F_83 ( V_23 , V_25 , V_80 ,
V_81 ) ;
if ( V_26 )
return V_26 ;
} else {
F_81 ( & V_23 -> V_27 . V_25 , V_148 ,
~ V_145 ) ;
}
if ( V_23 -> V_27 . V_3 == V_18 && V_23 -> V_47 == NULL ) {
V_26 = F_32 ( V_23 , true ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
int F_86 ( struct V_8 * V_9 ,
struct V_22 * V_23 ,
unsigned long V_15 ,
enum V_150 type ,
struct V_24 * V_25 ,
T_1 V_147 ,
bool V_80 ,
struct V_151 * V_152 ,
T_3 V_41 ,
struct V_153 * V_77 ,
struct V_154 * V_48 ,
void (* V_51) ( struct V_22 * ) )
{
int V_26 = 0 ;
unsigned long V_28 ;
struct V_155 * V_52 = V_9 -> V_36 -> V_52 ;
bool V_156 ;
V_26 = F_87 ( V_52 , V_41 , false , false ) ;
if ( V_26 ) {
F_3 ( L_17 ) ;
if ( V_51 )
(* V_51)( V_23 ) ;
else
F_16 ( V_23 ) ;
return - V_75 ;
}
V_28 = ( V_15 + V_37 - 1 ) >> V_73 ;
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
F_88 ( & V_23 -> V_39 ) ;
F_88 ( & V_23 -> V_40 ) ;
F_89 ( & V_23 -> V_43 , 0 ) ;
F_90 ( & V_23 -> V_45 ) ;
F_90 ( & V_23 -> V_46 ) ;
F_90 ( & V_23 -> V_58 ) ;
F_90 ( & V_23 -> V_157 ) ;
F_91 ( & V_23 -> V_50 ) ;
V_23 -> V_9 = V_9 ;
V_23 -> V_36 = V_9 -> V_36 ;
V_23 -> type = type ;
V_23 -> V_28 = V_28 ;
V_23 -> V_27 . V_15 = V_28 << V_73 ;
V_23 -> V_27 . V_3 = V_18 ;
V_23 -> V_27 . V_28 = V_23 -> V_28 ;
V_23 -> V_27 . V_44 = NULL ;
V_23 -> V_27 . V_147 = V_147 ;
V_23 -> V_27 . V_124 . V_125 = false ;
V_23 -> V_27 . V_124 . V_126 = 0 ;
V_23 -> V_158 = 0 ;
V_23 -> V_27 . V_25 = ( V_159 | V_136 ) ;
V_23 -> V_152 = V_152 ;
V_23 -> V_41 = V_41 ;
V_23 -> V_77 = V_77 ;
if ( V_48 ) {
V_23 -> V_48 = V_48 ;
F_19 ( & V_23 -> V_48 -> V_53 . V_54 ) ;
} else {
V_23 -> V_48 = & V_23 -> V_49 ;
F_92 ( & V_23 -> V_49 ) ;
}
F_93 ( & V_23 -> V_36 -> V_38 ) ;
F_94 ( & V_23 -> V_119 ) ;
if ( V_23 -> type == V_68 ||
V_23 -> type == V_76 )
V_26 = F_95 ( & V_9 -> V_118 , & V_23 -> V_119 ,
V_23 -> V_27 . V_28 ) ;
if ( ! V_48 ) {
V_156 = F_96 ( & V_23 -> V_48 -> V_53 ) ;
F_61 ( ! V_156 ) ;
}
if ( F_97 ( ! V_26 ) )
V_26 = F_85 ( V_23 , V_25 , V_80 , false ) ;
if ( ! V_48 ) {
F_77 ( V_23 ) ;
} else if ( ! ( V_23 -> V_27 . V_25 & V_55 ) ) {
F_29 ( & V_23 -> V_36 -> V_63 ) ;
F_18 ( V_23 ) ;
F_30 ( & V_23 -> V_36 -> V_63 ) ;
}
if ( F_34 ( V_26 ) )
F_69 ( & V_23 ) ;
return V_26 ;
}
T_3 F_98 ( struct V_8 * V_9 ,
unsigned long V_160 ,
unsigned V_161 )
{
unsigned V_162 = ( F_99 ( V_160 ) ) >> V_73 ;
T_3 V_15 = 0 ;
V_15 += F_100 ( V_161 ) ;
V_15 += F_99 ( V_162 * sizeof( void * ) ) ;
V_15 += F_100 ( sizeof( struct V_163 ) ) ;
return V_15 ;
}
T_3 F_101 ( struct V_8 * V_9 ,
unsigned long V_160 ,
unsigned V_161 )
{
unsigned V_162 = ( F_99 ( V_160 ) ) >> V_73 ;
T_3 V_15 = 0 ;
V_15 += F_100 ( V_161 ) ;
V_15 += F_99 ( V_162 * sizeof( void * ) ) ;
V_15 += F_99 ( V_162 * sizeof( V_164 ) ) ;
V_15 += F_100 ( sizeof( struct V_165 ) ) ;
return V_15 ;
}
int F_102 ( struct V_8 * V_9 ,
unsigned long V_15 ,
enum V_150 type ,
struct V_24 * V_25 ,
T_1 V_147 ,
bool V_80 ,
struct V_151 * V_152 ,
struct V_22 * * V_120 )
{
struct V_22 * V_23 ;
T_3 V_41 ;
int V_26 ;
V_23 = F_103 ( sizeof( * V_23 ) , V_166 ) ;
if ( F_34 ( V_23 == NULL ) )
return - V_75 ;
V_41 = F_98 ( V_9 , V_15 , sizeof( struct V_22 ) ) ;
V_26 = F_86 ( V_9 , V_23 , V_15 , type , V_25 , V_147 ,
V_80 , V_152 , V_41 ,
NULL , NULL , NULL ) ;
if ( F_97 ( V_26 == 0 ) )
* V_120 = V_23 ;
return V_26 ;
}
static int F_104 ( struct V_8 * V_9 ,
unsigned V_3 , bool V_167 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
struct V_35 * V_36 = V_9 -> V_36 ;
int V_26 ;
F_29 ( & V_36 -> V_63 ) ;
while ( ! F_11 ( & V_11 -> V_45 ) ) {
F_30 ( & V_36 -> V_63 ) ;
V_26 = F_75 ( V_9 , V_3 , NULL , false , false ) ;
if ( V_26 ) {
if ( V_167 ) {
return V_26 ;
} else {
F_3 ( L_19 ) ;
}
}
F_29 ( & V_36 -> V_63 ) ;
}
F_30 ( & V_36 -> V_63 ) ;
return 0 ;
}
int F_105 ( struct V_8 * V_9 , unsigned V_3 )
{
struct V_10 * V_11 ;
int V_26 = - V_7 ;
if ( V_3 >= V_168 ) {
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
F_104 ( V_9 , V_3 , false ) ;
V_26 = (* V_11 -> V_19 -> V_169 )( V_11 ) ;
}
return V_26 ;
}
int F_106 ( struct V_8 * V_9 , unsigned V_3 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( V_3 == 0 || V_3 >= V_168 ) {
F_3 ( L_22 , V_3 ) ;
return - V_7 ;
}
if ( ! V_11 -> V_12 ) {
F_3 ( L_23 , V_3 ) ;
return 0 ;
}
return F_104 ( V_9 , V_3 , true ) ;
}
int F_107 ( struct V_8 * V_9 , unsigned type ,
unsigned long V_170 )
{
int V_26 = - V_7 ;
struct V_10 * V_11 ;
F_10 ( type >= V_168 ) ;
V_11 = & V_9 -> V_11 [ type ] ;
F_10 ( V_11 -> V_12 ) ;
V_11 -> V_171 = true ;
V_11 -> V_172 = false ;
F_91 ( & V_11 -> V_173 ) ;
F_90 ( & V_11 -> V_157 ) ;
V_26 = V_9 -> V_71 -> V_174 ( V_9 , type , V_11 ) ;
if ( V_26 )
return V_26 ;
V_11 -> V_9 = V_9 ;
V_26 = 0 ;
if ( type != V_18 ) {
V_26 = (* V_11 -> V_19 -> V_175 )( V_11 , V_170 ) ;
if ( V_26 )
return V_26 ;
}
V_11 -> V_12 = true ;
V_11 -> V_13 = true ;
V_11 -> V_15 = V_170 ;
F_90 ( & V_11 -> V_45 ) ;
return 0 ;
}
static void F_108 ( struct V_30 * V_31 )
{
struct V_35 * V_36 =
F_6 ( V_31 , struct V_35 , V_31 ) ;
F_109 ( V_36 -> V_52 , & V_36 -> V_176 ) ;
F_110 ( V_36 -> V_74 ) ;
F_16 ( V_36 ) ;
}
void F_111 ( struct V_177 * V_178 )
{
struct V_35 * V_36 = V_178 -> V_179 ;
F_112 ( & V_36 -> V_31 ) ;
F_113 ( & V_36 -> V_31 ) ;
}
int F_114 ( struct V_177 * V_178 )
{
struct V_180 * V_181 =
F_6 ( V_178 , struct V_180 , V_178 ) ;
struct V_35 * V_36 = V_178 -> V_179 ;
int V_26 ;
F_91 ( & V_36 -> V_182 ) ;
F_115 ( & V_36 -> V_63 ) ;
V_36 -> V_52 = V_181 -> V_52 ;
V_36 -> V_74 = F_116 ( V_183 | V_184 ) ;
if ( F_34 ( V_36 -> V_74 == NULL ) ) {
V_26 = - V_75 ;
goto V_185;
}
F_90 ( & V_36 -> V_59 ) ;
F_90 ( & V_36 -> V_186 ) ;
F_117 ( & V_36 -> V_176 , V_187 ) ;
V_26 = F_118 ( V_36 -> V_52 , & V_36 -> V_176 ) ;
if ( F_34 ( V_26 != 0 ) ) {
F_3 ( L_24 ) ;
goto V_188;
}
F_89 ( & V_36 -> V_38 , 0 ) ;
V_26 = F_119 (
& V_36 -> V_31 , & V_189 , F_120 () , L_25 ) ;
if ( F_34 ( V_26 != 0 ) )
F_113 ( & V_36 -> V_31 ) ;
return V_26 ;
V_188:
F_110 ( V_36 -> V_74 ) ;
V_185:
F_16 ( V_36 ) ;
return V_26 ;
}
int F_121 ( struct V_8 * V_9 )
{
int V_26 = 0 ;
unsigned V_4 = V_168 ;
struct V_10 * V_11 ;
struct V_35 * V_36 = V_9 -> V_36 ;
while ( V_4 -- ) {
V_11 = & V_9 -> V_11 [ V_4 ] ;
if ( V_11 -> V_12 ) {
V_11 -> V_13 = false ;
if ( ( V_4 != V_18 ) && F_105 ( V_9 , V_4 ) ) {
V_26 = - V_109 ;
F_3 ( L_26 ,
V_4 ) ;
}
V_11 -> V_12 = false ;
}
}
F_122 ( & V_36 -> V_182 ) ;
F_123 ( & V_9 -> V_186 ) ;
F_124 ( & V_36 -> V_182 ) ;
F_71 ( & V_9 -> V_106 ) ;
while ( F_62 ( V_9 , true ) )
;
F_29 ( & V_36 -> V_63 ) ;
if ( F_11 ( & V_9 -> V_46 ) )
F_125 ( L_27 ) ;
if ( F_11 ( & V_9 -> V_11 [ 0 ] . V_45 ) )
F_125 ( L_28 ) ;
F_30 ( & V_36 -> V_63 ) ;
F_126 ( & V_9 -> V_118 ) ;
return V_26 ;
}
int F_127 ( struct V_8 * V_9 ,
struct V_35 * V_36 ,
struct V_190 * V_71 ,
struct V_191 * V_192 ,
T_4 V_193 ,
bool V_66 )
{
int V_26 = - V_7 ;
V_9 -> V_71 = V_71 ;
memset ( V_9 -> V_11 , 0 , sizeof( V_9 -> V_11 ) ) ;
V_26 = F_107 ( V_9 , V_18 , 0 ) ;
if ( F_34 ( V_26 != 0 ) )
goto V_194;
F_128 ( & V_9 -> V_118 , V_193 ,
0x10000000 ) ;
F_129 ( & V_9 -> V_106 , F_65 ) ;
F_90 ( & V_9 -> V_46 ) ;
V_9 -> V_195 = V_192 ;
V_9 -> V_36 = V_36 ;
V_9 -> V_66 = V_66 ;
V_9 -> V_196 = 0 ;
F_122 ( & V_36 -> V_182 ) ;
F_20 ( & V_9 -> V_186 , & V_36 -> V_186 ) ;
F_124 ( & V_36 -> V_182 ) ;
return 0 ;
V_194:
return V_26 ;
}
bool F_36 ( struct V_8 * V_9 , struct V_78 * V_27 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_27 -> V_3 ] ;
if ( ! ( V_11 -> V_6 & V_88 ) ) {
if ( V_27 -> V_3 == V_18 )
return false ;
if ( V_11 -> V_6 & V_197 )
return false ;
if ( V_27 -> V_25 & V_136 )
return false ;
}
return true ;
}
void F_38 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
F_130 ( & V_23 -> V_119 , V_9 -> V_195 ) ;
F_68 ( V_23 ) ;
}
void F_131 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_23 -> V_27 . V_3 ] ;
F_37 ( V_11 , false ) ;
F_38 ( V_23 ) ;
F_39 ( V_11 ) ;
}
int F_56 ( struct V_22 * V_23 ,
bool V_198 , bool V_80 , bool V_199 )
{
struct V_99 * V_100 ;
struct V_154 * V_48 ;
struct V_101 * V_200 ;
long V_201 = 15 * V_107 ;
int V_4 ;
V_48 = V_23 -> V_48 ;
V_100 = F_49 ( V_48 ) ;
V_200 = F_50 ( V_48 ) ;
if ( V_200 ) {
if ( ! F_132 ( V_200 ) ) {
if ( V_199 )
return - V_109 ;
V_201 = F_133 ( V_200 ,
V_80 , V_201 ) ;
}
}
for ( V_4 = 0 ; V_100 && V_201 > 0 && V_4 < V_100 -> V_104 ; ++ V_4 ) {
struct V_101 * V_101 ;
V_101 = F_52 ( V_100 -> V_105 [ V_4 ] ,
F_53 ( V_48 ) ) ;
if ( ! F_132 ( V_101 ) ) {
if ( V_199 )
return - V_109 ;
V_201 = F_133 ( V_101 ,
V_80 , V_201 ) ;
}
}
if ( V_201 < 0 )
return V_201 ;
if ( V_201 == 0 )
return - V_109 ;
F_134 ( V_48 , NULL ) ;
F_135 ( V_202 , & V_23 -> V_158 ) ;
return 0 ;
}
int F_136 ( struct V_22 * V_23 , bool V_199 )
{
int V_26 = 0 ;
V_26 = F_137 ( V_23 , true , V_199 , false , NULL ) ;
if ( F_34 ( V_26 != 0 ) )
return V_26 ;
V_26 = F_56 ( V_23 , false , true , V_199 ) ;
if ( F_97 ( V_26 == 0 ) )
F_93 ( & V_23 -> V_43 ) ;
F_77 ( V_23 ) ;
return V_26 ;
}
void F_138 ( struct V_22 * V_23 )
{
F_13 ( & V_23 -> V_43 ) ;
}
static int V_187 ( struct V_203 * V_176 )
{
struct V_35 * V_36 =
F_6 ( V_176 , struct V_35 , V_176 ) ;
struct V_22 * V_23 ;
int V_26 = - V_109 ;
int V_60 ;
T_1 V_204 = ( V_136 | V_159 ) ;
F_29 ( & V_36 -> V_63 ) ;
F_76 (bo, &glob->swap_lru, swap) {
V_26 = F_55 ( V_23 , false , true , false , NULL ) ;
if ( ! V_26 )
break;
}
if ( V_26 ) {
F_30 ( & V_36 -> V_63 ) ;
return V_26 ;
}
F_21 ( & V_23 -> V_40 ) ;
if ( ! F_11 ( & V_23 -> V_46 ) ) {
V_26 = F_59 ( V_23 , false , false ) ;
F_64 ( & V_23 -> V_40 , F_9 ) ;
return V_26 ;
}
V_60 = F_22 ( V_23 ) ;
F_30 ( & V_36 -> V_63 ) ;
F_26 ( V_23 , V_60 , true ) ;
V_26 = F_56 ( V_23 , false , false , false ) ;
if ( F_34 ( V_26 != 0 ) )
goto V_115;
if ( ( V_23 -> V_27 . V_25 & V_204 ) != V_204 ) {
struct V_78 V_122 ;
V_122 = V_23 -> V_27 ;
V_122 . V_44 = NULL ;
V_122 . V_25 = V_159 | V_136 ;
V_122 . V_3 = V_18 ;
V_26 = F_35 ( V_23 , & V_122 , true ,
false , false ) ;
if ( F_34 ( V_26 != 0 ) )
goto V_115;
}
F_131 ( V_23 ) ;
if ( V_23 -> V_9 -> V_71 -> V_205 )
V_23 -> V_9 -> V_71 -> V_205 ( V_23 ) ;
V_26 = F_139 ( V_23 -> V_47 , V_23 -> V_152 ) ;
V_115:
F_57 ( V_23 ) ;
F_64 ( & V_23 -> V_40 , F_9 ) ;
return V_26 ;
}
void F_140 ( struct V_8 * V_9 )
{
while ( V_187 ( & V_9 -> V_36 -> V_176 ) == 0 )
;
}
int F_141 ( struct V_22 * V_23 )
{
int V_26 ;
V_26 = F_142 ( & V_23 -> V_50 ) ;
if ( F_34 ( V_26 != 0 ) )
return - V_123 ;
if ( ! F_143 ( & V_23 -> V_48 -> V_53 ) )
goto V_112;
V_26 = F_55 ( V_23 , true , false , false , NULL ) ;
if ( F_34 ( V_26 != 0 ) )
goto V_112;
F_57 ( V_23 ) ;
V_112:
F_124 ( & V_23 -> V_50 ) ;
return V_26 ;
}
