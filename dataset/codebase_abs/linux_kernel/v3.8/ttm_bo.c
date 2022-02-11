static inline int F_1 ( T_1 V_1 , T_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 <= V_4 ; V_3 ++ )
if ( V_1 & ( 1 << V_3 ) ) {
* V_2 = V_3 ;
return 0 ;
}
return - V_5 ;
}
static void F_2 ( struct V_6 * V_7 , int V_2 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
F_3 ( L_1 , V_9 -> V_10 ) ;
F_3 ( L_2 , V_9 -> V_11 ) ;
F_3 ( L_3 , V_9 -> V_1 ) ;
F_3 ( L_4 , V_9 -> V_12 ) ;
F_3 ( L_5 , V_9 -> V_13 ) ;
F_3 ( L_6 , V_9 -> V_14 ) ;
F_3 ( L_7 , V_9 -> V_15 ) ;
if ( V_2 != V_16 )
(* V_9 -> V_17 -> V_18 )( V_9 , V_19 ) ;
}
static void F_4 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
int V_3 , V_24 , V_2 ;
F_3 ( L_8 ,
V_21 , V_21 -> V_25 . V_26 , V_21 -> V_25 . V_13 >> 10 ,
V_21 -> V_25 . V_13 >> 20 ) ;
for ( V_3 = 0 ; V_3 < V_23 -> V_27 ; V_3 ++ ) {
V_24 = F_1 ( V_23 -> V_23 [ V_3 ] ,
& V_2 ) ;
if ( V_24 )
return;
F_3 ( L_9 ,
V_3 , V_23 -> V_23 [ V_3 ] , V_2 ) ;
F_2 ( V_21 -> V_7 , V_2 ) ;
}
}
static T_2 F_5 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
char * V_32 )
{
struct V_33 * V_34 =
F_6 ( V_29 , struct V_33 , V_29 ) ;
return snprintf ( V_32 , V_35 , L_10 ,
( unsigned long ) F_7 ( & V_34 -> V_36 ) ) ;
}
static inline T_1 F_8 ( unsigned type )
{
return 1 << ( type ) ;
}
static void F_9 ( struct V_37 * V_38 )
{
struct V_20 * V_21 =
F_6 ( V_38 , struct V_20 , V_38 ) ;
struct V_6 * V_7 = V_21 -> V_7 ;
T_3 V_39 = V_21 -> V_39 ;
F_10 ( F_7 ( & V_21 -> V_38 . V_40 ) ) ;
F_10 ( F_7 ( & V_21 -> V_37 . V_40 ) ) ;
F_10 ( F_7 ( & V_21 -> V_41 ) ) ;
F_10 ( V_21 -> V_42 != NULL ) ;
F_10 ( V_21 -> V_25 . V_43 != NULL ) ;
F_10 ( ! F_11 ( & V_21 -> V_44 ) ) ;
F_10 ( ! F_11 ( & V_21 -> V_45 ) ) ;
if ( V_21 -> V_46 )
F_12 ( V_21 -> V_46 ) ;
F_13 ( & V_21 -> V_34 -> V_36 ) ;
if ( V_21 -> V_47 )
V_21 -> V_47 ( V_21 ) ;
else {
F_14 ( V_21 ) ;
}
F_15 ( V_7 -> V_34 -> V_48 , V_39 ) ;
}
int F_16 ( struct V_20 * V_21 , bool V_49 )
{
if ( V_49 ) {
return F_17 ( V_21 -> V_50 ,
! F_18 ( V_21 ) ) ;
} else {
F_19 ( V_21 -> V_50 , ! F_18 ( V_21 ) ) ;
return 0 ;
}
}
void F_20 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 ;
F_10 ( ! F_18 ( V_21 ) ) ;
if ( ! ( V_21 -> V_25 . V_23 & V_51 ) ) {
F_10 ( ! F_11 ( & V_21 -> V_44 ) ) ;
V_9 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
F_21 ( & V_21 -> V_44 , & V_9 -> V_44 ) ;
F_22 ( & V_21 -> V_38 ) ;
if ( V_21 -> V_46 != NULL ) {
F_21 ( & V_21 -> V_52 , & V_21 -> V_34 -> V_53 ) ;
F_22 ( & V_21 -> V_38 ) ;
}
}
}
int F_23 ( struct V_20 * V_21 )
{
int V_54 = 0 ;
if ( ! F_11 ( & V_21 -> V_52 ) ) {
F_24 ( & V_21 -> V_52 ) ;
++ V_54 ;
}
if ( ! F_11 ( & V_21 -> V_44 ) ) {
F_24 ( & V_21 -> V_44 ) ;
++ V_54 ;
}
return V_54 ;
}
int F_25 ( struct V_20 * V_21 ,
bool V_49 ,
bool V_55 , bool V_56 , T_1 V_57 )
{
struct V_33 * V_34 = V_21 -> V_34 ;
int V_24 ;
while ( F_26 ( F_7 ( & V_21 -> V_58 ) != 0 ) ) {
if ( V_56 && V_21 -> V_59 ) {
if ( F_26 ( V_57 == V_21 -> V_60 ) )
return - V_61 ;
if ( F_26 ( V_57 - V_21 -> V_60 < ( 1 << 31 ) ) )
return - V_62 ;
}
if ( V_55 )
return - V_63 ;
F_27 ( & V_34 -> V_64 ) ;
V_24 = F_16 ( V_21 , V_49 ) ;
F_28 ( & V_34 -> V_64 ) ;
if ( F_26 ( V_24 ) )
return V_24 ;
}
F_29 ( & V_21 -> V_58 , 1 ) ;
if ( V_56 ) {
if ( F_26 ( ( V_21 -> V_60 - V_57 < ( 1 << 31 ) )
|| ! V_21 -> V_59 ) )
F_30 ( & V_21 -> V_50 ) ;
V_21 -> V_60 = V_57 ;
V_21 -> V_59 = true ;
} else {
V_21 -> V_59 = false ;
}
return 0 ;
}
static void F_31 ( struct V_37 * V_38 )
{
F_32 () ;
}
void F_33 ( struct V_20 * V_21 , int V_65 ,
bool V_66 )
{
F_34 ( & V_21 -> V_38 , V_65 ,
( V_66 ) ? F_31 : F_9 ) ;
}
int F_35 ( struct V_20 * V_21 ,
bool V_49 ,
bool V_55 , bool V_56 , T_1 V_57 )
{
struct V_33 * V_34 = V_21 -> V_34 ;
int V_54 = 0 ;
int V_24 ;
F_28 ( & V_34 -> V_64 ) ;
V_24 = F_25 ( V_21 , V_49 , V_55 , V_56 ,
V_57 ) ;
if ( F_36 ( V_24 == 0 ) )
V_54 = F_23 ( V_21 ) ;
F_27 ( & V_34 -> V_64 ) ;
F_33 ( V_21 , V_54 , true ) ;
return V_24 ;
}
void F_37 ( struct V_20 * V_21 )
{
F_20 ( V_21 ) ;
F_29 ( & V_21 -> V_58 , 0 ) ;
F_30 ( & V_21 -> V_50 ) ;
}
void F_38 ( struct V_20 * V_21 )
{
struct V_33 * V_34 = V_21 -> V_34 ;
F_28 ( & V_34 -> V_64 ) ;
F_37 ( V_21 ) ;
F_27 ( & V_34 -> V_64 ) ;
}
static int F_39 ( struct V_20 * V_21 , bool V_67 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_33 * V_34 = V_21 -> V_34 ;
int V_24 = 0 ;
T_1 V_68 = 0 ;
F_40 ( & V_21 -> V_69 ) ;
V_21 -> V_46 = NULL ;
if ( V_7 -> V_70 )
V_68 |= V_71 ;
switch ( V_21 -> type ) {
case V_72 :
if ( V_67 )
V_68 |= V_73 ;
case V_74 :
V_21 -> V_46 = V_7 -> V_75 -> V_76 ( V_7 , V_21 -> V_26 << V_77 ,
V_68 , V_34 -> V_78 ) ;
if ( F_26 ( V_21 -> V_46 == NULL ) )
V_24 = - V_79 ;
break;
case V_80 :
V_21 -> V_46 = V_7 -> V_75 -> V_76 ( V_7 , V_21 -> V_26 << V_77 ,
V_68 | V_81 ,
V_34 -> V_78 ) ;
if ( F_26 ( V_21 -> V_46 == NULL ) ) {
V_24 = - V_79 ;
break;
}
V_21 -> V_46 -> V_82 = V_21 -> V_82 ;
break;
default:
F_3 ( L_11 ) ;
V_24 = - V_5 ;
break;
}
return V_24 ;
}
static int F_41 ( struct V_20 * V_21 ,
struct V_83 * V_25 ,
bool V_84 , bool V_49 ,
bool V_85 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
bool V_86 = F_42 ( V_7 , & V_21 -> V_25 ) ;
bool V_87 = F_42 ( V_7 , V_25 ) ;
struct V_8 * V_88 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
struct V_8 * V_89 = & V_7 -> V_9 [ V_25 -> V_2 ] ;
int V_24 = 0 ;
if ( V_86 || V_87 ||
( ( V_25 -> V_23 & V_21 -> V_25 . V_23 & V_90 ) == 0 ) ) {
V_24 = F_43 ( V_88 , true ) ;
if ( F_26 ( V_24 != 0 ) )
goto V_91;
F_44 ( V_21 ) ;
F_45 ( V_88 ) ;
}
if ( ! ( V_89 -> V_1 & V_92 ) ) {
if ( V_21 -> V_46 == NULL ) {
bool V_93 = ! ( V_88 -> V_1 & V_92 ) ;
V_24 = F_39 ( V_21 , V_93 ) ;
if ( V_24 )
goto V_91;
}
V_24 = F_46 ( V_21 -> V_46 , V_25 -> V_23 ) ;
if ( V_24 )
goto V_91;
if ( V_25 -> V_2 != V_16 ) {
V_24 = F_47 ( V_21 -> V_46 , V_25 ) ;
if ( V_24 )
goto V_91;
}
if ( V_21 -> V_25 . V_2 == V_16 ) {
if ( V_7 -> V_75 -> V_94 )
V_7 -> V_75 -> V_94 ( V_21 , V_25 ) ;
V_21 -> V_25 = * V_25 ;
V_25 -> V_43 = NULL ;
goto V_95;
}
}
if ( V_7 -> V_75 -> V_94 )
V_7 -> V_75 -> V_94 ( V_21 , V_25 ) ;
if ( ! ( V_88 -> V_1 & V_92 ) &&
! ( V_89 -> V_1 & V_92 ) )
V_24 = F_48 ( V_21 , V_84 , V_85 , V_25 ) ;
else if ( V_7 -> V_75 -> V_96 )
V_24 = V_7 -> V_75 -> V_96 ( V_21 , V_84 , V_49 ,
V_85 , V_25 ) ;
else
V_24 = F_49 ( V_21 , V_84 , V_85 , V_25 ) ;
if ( V_24 ) {
if ( V_7 -> V_75 -> V_94 ) {
struct V_83 V_97 = * V_25 ;
* V_25 = V_21 -> V_25 ;
V_21 -> V_25 = V_97 ;
V_7 -> V_75 -> V_94 ( V_21 , V_25 ) ;
V_21 -> V_25 = * V_25 ;
* V_25 = V_97 ;
}
goto V_91;
}
V_95:
if ( V_21 -> V_98 ) {
V_24 = V_7 -> V_75 -> V_99 ( V_7 , V_21 -> V_25 . V_23 ) ;
if ( V_24 )
F_3 ( L_12 ) ;
V_21 -> V_98 = false ;
}
if ( V_21 -> V_25 . V_43 ) {
V_21 -> V_100 = ( V_21 -> V_25 . V_101 << V_77 ) +
V_7 -> V_9 [ V_21 -> V_25 . V_2 ] . V_12 ;
V_21 -> V_102 = V_21 -> V_25 . V_23 ;
} else
V_21 -> V_100 = 0 ;
return 0 ;
V_91:
V_89 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
if ( ( V_89 -> V_1 & V_92 ) && V_21 -> V_46 ) {
F_50 ( V_21 -> V_46 ) ;
F_12 ( V_21 -> V_46 ) ;
V_21 -> V_46 = NULL ;
}
return V_24 ;
}
static void F_51 ( struct V_20 * V_21 )
{
if ( V_21 -> V_7 -> V_75 -> V_94 )
V_21 -> V_7 -> V_75 -> V_94 ( V_21 , NULL ) ;
if ( V_21 -> V_46 ) {
F_50 ( V_21 -> V_46 ) ;
F_12 ( V_21 -> V_46 ) ;
V_21 -> V_46 = NULL ;
}
F_52 ( V_21 , & V_21 -> V_25 ) ;
F_29 ( & V_21 -> V_58 , 0 ) ;
F_30 ( & V_21 -> V_50 ) ;
F_53 () ;
}
static void F_54 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_33 * V_34 = V_21 -> V_34 ;
struct V_103 * V_75 = V_7 -> V_75 ;
void * V_42 = NULL ;
int V_54 ;
int V_24 ;
F_28 ( & V_34 -> V_64 ) ;
V_24 = F_25 ( V_21 , false , true , false , 0 ) ;
F_28 ( & V_7 -> V_104 ) ;
( void ) F_55 ( V_21 , false , false , true ) ;
if ( ! V_24 && ! V_21 -> V_42 ) {
F_27 ( & V_7 -> V_104 ) ;
V_54 = F_23 ( V_21 ) ;
F_27 ( & V_34 -> V_64 ) ;
F_51 ( V_21 ) ;
F_33 ( V_21 , V_54 , true ) ;
return;
}
if ( V_21 -> V_42 )
V_42 = V_75 -> V_105 ( V_21 -> V_42 ) ;
F_27 ( & V_7 -> V_104 ) ;
if ( ! V_24 ) {
F_29 ( & V_21 -> V_58 , 0 ) ;
F_30 ( & V_21 -> V_50 ) ;
}
F_22 ( & V_21 -> V_38 ) ;
F_21 ( & V_21 -> V_45 , & V_7 -> V_45 ) ;
F_27 ( & V_34 -> V_64 ) ;
if ( V_42 ) {
V_75 -> V_106 ( V_42 ) ;
V_75 -> V_107 ( & V_42 ) ;
}
F_56 ( & V_7 -> V_108 ,
( ( V_109 / 100 ) < 1 ) ? 1 : V_109 / 100 ) ;
}
static int F_57 ( struct V_20 * V_21 ,
bool V_49 ,
bool V_85 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_103 * V_75 = V_7 -> V_75 ;
struct V_33 * V_34 = V_21 -> V_34 ;
int V_54 ;
int V_24 ;
F_28 ( & V_7 -> V_104 ) ;
V_24 = F_55 ( V_21 , false , false , true ) ;
if ( V_24 && ! V_85 ) {
void * V_42 ;
V_42 = V_75 -> V_105 ( V_21 -> V_42 ) ;
F_27 ( & V_7 -> V_104 ) ;
F_29 ( & V_21 -> V_58 , 0 ) ;
F_30 ( & V_21 -> V_50 ) ;
F_27 ( & V_34 -> V_64 ) ;
V_24 = V_75 -> V_110 ( V_42 , false , V_49 ) ;
V_75 -> V_107 ( & V_42 ) ;
if ( V_24 )
return V_24 ;
F_28 ( & V_7 -> V_104 ) ;
V_24 = F_55 ( V_21 , false , false , true ) ;
F_58 ( V_24 ) ;
F_27 ( & V_7 -> V_104 ) ;
if ( V_24 )
return V_24 ;
F_28 ( & V_34 -> V_64 ) ;
V_24 = F_25 ( V_21 , false , true , false , 0 ) ;
if ( V_24 ) {
F_27 ( & V_34 -> V_64 ) ;
return 0 ;
}
} else
F_27 ( & V_7 -> V_104 ) ;
if ( V_24 || F_26 ( F_11 ( & V_21 -> V_45 ) ) ) {
F_29 ( & V_21 -> V_58 , 0 ) ;
F_30 ( & V_21 -> V_50 ) ;
F_27 ( & V_34 -> V_64 ) ;
return V_24 ;
}
V_54 = F_23 ( V_21 ) ;
F_24 ( & V_21 -> V_45 ) ;
++ V_54 ;
F_27 ( & V_34 -> V_64 ) ;
F_51 ( V_21 ) ;
F_33 ( V_21 , V_54 , true ) ;
return 0 ;
}
static int F_59 ( struct V_6 * V_7 , bool V_111 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
struct V_20 * V_112 = NULL ;
int V_24 = 0 ;
F_28 ( & V_34 -> V_64 ) ;
if ( F_11 ( & V_7 -> V_45 ) )
goto V_113;
V_112 = F_60 ( & V_7 -> V_45 ,
struct V_20 , V_45 ) ;
F_22 ( & V_112 -> V_38 ) ;
for (; ; ) {
struct V_20 * V_114 = NULL ;
if ( V_112 -> V_45 . V_115 != & V_7 -> V_45 ) {
V_114 = F_60 ( & V_112 -> V_45 ,
struct V_20 , V_45 ) ;
F_22 ( & V_114 -> V_38 ) ;
}
V_24 = F_25 ( V_112 , false , ! V_111 , false , 0 ) ;
if ( ! V_24 )
V_24 = F_57 ( V_112 , false ,
! V_111 ) ;
else
F_27 ( & V_34 -> V_64 ) ;
F_61 ( & V_112 -> V_38 , F_9 ) ;
V_112 = V_114 ;
if ( V_24 || ! V_112 )
goto V_116;
F_28 ( & V_34 -> V_64 ) ;
if ( F_11 ( & V_112 -> V_45 ) )
break;
}
V_113:
F_27 ( & V_34 -> V_64 ) ;
V_116:
if ( V_112 )
F_61 ( & V_112 -> V_38 , F_9 ) ;
return V_24 ;
}
static void F_62 ( struct V_117 * V_118 )
{
struct V_6 * V_7 =
F_6 ( V_118 , struct V_6 , V_108 . V_118 ) ;
if ( F_59 ( V_7 , false ) ) {
F_56 ( & V_7 -> V_108 ,
( ( V_109 / 100 ) < 1 ) ? 1 : V_109 / 100 ) ;
}
}
static void F_63 ( struct V_37 * V_37 )
{
struct V_20 * V_21 =
F_6 ( V_37 , struct V_20 , V_37 ) ;
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
F_64 ( & V_7 -> V_119 ) ;
if ( F_36 ( V_21 -> V_120 != NULL ) ) {
F_65 ( & V_21 -> V_121 , & V_7 -> V_122 ) ;
F_66 ( V_21 -> V_120 ) ;
V_21 -> V_120 = NULL ;
}
F_67 ( & V_7 -> V_119 ) ;
F_43 ( V_9 , false ) ;
F_68 ( V_21 ) ;
F_45 ( V_9 ) ;
F_54 ( V_21 ) ;
F_61 ( & V_21 -> V_38 , F_9 ) ;
}
void F_69 ( struct V_20 * * V_123 )
{
struct V_20 * V_21 = * V_123 ;
* V_123 = NULL ;
F_61 ( & V_21 -> V_37 , F_63 ) ;
}
int F_70 ( struct V_6 * V_7 )
{
return F_71 ( & V_7 -> V_108 ) ;
}
void F_72 ( struct V_6 * V_7 , int V_124 )
{
if ( V_124 )
F_56 ( & V_7 -> V_108 ,
( ( V_109 / 100 ) < 1 ) ? 1 : V_109 / 100 ) ;
}
static int F_73 ( struct V_20 * V_21 , bool V_49 ,
bool V_85 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_83 V_125 ;
struct V_22 V_23 ;
int V_24 = 0 ;
F_28 ( & V_7 -> V_104 ) ;
V_24 = F_55 ( V_21 , false , V_49 , V_85 ) ;
F_27 ( & V_7 -> V_104 ) ;
if ( F_26 ( V_24 != 0 ) ) {
if ( V_24 != - V_126 ) {
F_3 ( L_13 ) ;
}
goto V_116;
}
F_10 ( ! F_18 ( V_21 ) ) ;
V_125 = V_21 -> V_25 ;
V_125 . V_43 = NULL ;
V_125 . V_127 . V_128 = false ;
V_125 . V_127 . V_129 = 0 ;
V_23 . V_130 = 0 ;
V_23 . V_131 = 0 ;
V_23 . V_27 = 0 ;
V_23 . V_132 = 0 ;
V_7 -> V_75 -> V_133 ( V_21 , & V_23 ) ;
V_24 = F_74 ( V_21 , & V_23 , & V_125 , V_49 ,
V_85 ) ;
if ( V_24 ) {
if ( V_24 != - V_126 ) {
F_3 ( L_14 ,
V_21 ) ;
F_4 ( V_21 , & V_23 ) ;
}
goto V_116;
}
V_24 = F_41 ( V_21 , & V_125 , true , V_49 ,
V_85 ) ;
if ( V_24 ) {
if ( V_24 != - V_126 )
F_3 ( L_15 ) ;
F_52 ( V_21 , & V_125 ) ;
goto V_116;
}
V_21 -> V_98 = true ;
V_116:
return V_24 ;
}
static int F_75 ( struct V_6 * V_7 ,
T_1 V_2 ,
bool V_49 ,
bool V_85 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
struct V_20 * V_21 ;
int V_24 = - V_63 , V_54 ;
F_28 ( & V_34 -> V_64 ) ;
F_76 (bo, &man->lru, lru) {
V_24 = F_25 ( V_21 , false , true , false , 0 ) ;
if ( ! V_24 )
break;
}
if ( V_24 ) {
F_27 ( & V_34 -> V_64 ) ;
return V_24 ;
}
F_22 ( & V_21 -> V_38 ) ;
if ( ! F_11 ( & V_21 -> V_45 ) ) {
V_24 = F_57 ( V_21 , V_49 ,
V_85 ) ;
F_61 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
V_54 = F_23 ( V_21 ) ;
F_27 ( & V_34 -> V_64 ) ;
F_10 ( V_24 != 0 ) ;
F_33 ( V_21 , V_54 , true ) ;
V_24 = F_73 ( V_21 , V_49 , V_85 ) ;
F_38 ( V_21 ) ;
F_61 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
void F_52 ( struct V_20 * V_21 , struct V_83 * V_25 )
{
struct V_8 * V_9 = & V_21 -> V_7 -> V_9 [ V_25 -> V_2 ] ;
if ( V_25 -> V_43 )
(* V_9 -> V_17 -> V_134 )( V_9 , V_25 ) ;
}
static int F_77 ( struct V_20 * V_21 ,
T_1 V_2 ,
struct V_22 * V_23 ,
struct V_83 * V_25 ,
bool V_49 ,
bool V_85 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
int V_24 ;
do {
V_24 = (* V_9 -> V_17 -> V_135 )( V_9 , V_21 , V_23 , V_25 ) ;
if ( F_26 ( V_24 != 0 ) )
return V_24 ;
if ( V_25 -> V_43 )
break;
V_24 = F_75 ( V_7 , V_2 ,
V_49 , V_85 ) ;
if ( F_26 ( V_24 != 0 ) )
return V_24 ;
} while ( 1 );
if ( V_25 -> V_43 == NULL )
return - V_79 ;
V_25 -> V_2 = V_2 ;
return 0 ;
}
static T_1 F_78 ( struct V_8 * V_9 ,
T_1 V_102 ,
T_1 V_136 )
{
T_1 V_137 = V_136 & V_90 ;
T_1 V_138 = V_136 & ~ V_90 ;
if ( ( V_102 & V_137 ) != 0 )
V_138 |= ( V_102 & V_137 ) ;
else if ( ( V_9 -> V_15 & V_137 ) != 0 )
V_138 |= V_9 -> V_15 ;
else if ( ( V_139 & V_137 ) != 0 )
V_138 |= V_139 ;
else if ( ( V_140 & V_137 ) != 0 )
V_138 |= V_140 ;
else if ( ( V_141 & V_137 ) != 0 )
V_138 |= V_141 ;
return V_138 ;
}
static bool F_79 ( struct V_8 * V_9 ,
T_1 V_2 ,
T_1 V_136 ,
T_1 * V_142 )
{
T_1 V_143 = F_8 ( V_2 ) ;
if ( ( V_143 & V_136 & V_144 ) == 0 )
return false ;
if ( ( V_136 & V_9 -> V_14 ) == 0 )
return false ;
V_143 |= ( V_136 & V_9 -> V_14 ) ;
* V_142 = V_143 ;
return true ;
}
int F_74 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_83 * V_25 ,
bool V_49 ,
bool V_85 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 ;
T_1 V_2 = V_16 ;
T_1 V_143 = 0 ;
bool V_145 = false ;
bool V_146 = false ;
bool V_147 = false ;
int V_3 , V_24 ;
V_25 -> V_43 = NULL ;
for ( V_3 = 0 ; V_3 < V_23 -> V_27 ; ++ V_3 ) {
V_24 = F_1 ( V_23 -> V_23 [ V_3 ] ,
& V_2 ) ;
if ( V_24 )
return V_24 ;
V_9 = & V_7 -> V_9 [ V_2 ] ;
V_146 = F_79 ( V_9 ,
V_2 ,
V_23 -> V_23 [ V_3 ] ,
& V_143 ) ;
if ( ! V_146 )
continue;
V_143 = F_78 ( V_9 , V_21 -> V_25 . V_23 ,
V_143 ) ;
F_80 ( & V_143 , V_23 -> V_23 [ V_3 ] ,
~ V_148 ) ;
if ( V_2 == V_16 )
break;
if ( V_9 -> V_10 && V_9 -> V_11 ) {
V_145 = true ;
V_24 = (* V_9 -> V_17 -> V_135 )( V_9 , V_21 , V_23 , V_25 ) ;
if ( F_26 ( V_24 ) )
return V_24 ;
}
if ( V_25 -> V_43 )
break;
}
if ( ( V_146 && ( V_2 == V_16 ) ) || V_25 -> V_43 ) {
V_25 -> V_2 = V_2 ;
V_25 -> V_23 = V_143 ;
return 0 ;
}
if ( ! V_145 )
return - V_5 ;
for ( V_3 = 0 ; V_3 < V_23 -> V_132 ; ++ V_3 ) {
V_24 = F_1 ( V_23 -> V_149 [ V_3 ] ,
& V_2 ) ;
if ( V_24 )
return V_24 ;
V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( ! V_9 -> V_10 )
continue;
if ( ! F_79 ( V_9 ,
V_2 ,
V_23 -> V_149 [ V_3 ] ,
& V_143 ) )
continue;
V_143 = F_78 ( V_9 , V_21 -> V_25 . V_23 ,
V_143 ) ;
F_80 ( & V_143 , V_23 -> V_149 [ V_3 ] ,
~ V_148 ) ;
if ( V_2 == V_16 ) {
V_25 -> V_2 = V_2 ;
V_25 -> V_23 = V_143 ;
V_25 -> V_43 = NULL ;
return 0 ;
}
V_24 = F_77 ( V_21 , V_2 , V_23 , V_25 ,
V_49 , V_85 ) ;
if ( V_24 == 0 && V_25 -> V_43 ) {
V_25 -> V_23 = V_143 ;
return 0 ;
}
if ( V_24 == - V_126 )
V_147 = true ;
}
V_24 = ( V_147 ) ? - V_126 : - V_79 ;
return V_24 ;
}
int F_81 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
bool V_49 ,
bool V_85 )
{
int V_24 = 0 ;
struct V_83 V_25 ;
struct V_6 * V_7 = V_21 -> V_7 ;
F_10 ( ! F_18 ( V_21 ) ) ;
F_28 ( & V_7 -> V_104 ) ;
V_24 = F_55 ( V_21 , false , V_49 , V_85 ) ;
F_27 ( & V_7 -> V_104 ) ;
if ( V_24 )
return V_24 ;
V_25 . V_26 = V_21 -> V_26 ;
V_25 . V_13 = V_25 . V_26 << V_77 ;
V_25 . V_150 = V_21 -> V_25 . V_150 ;
V_25 . V_127 . V_128 = false ;
V_25 . V_127 . V_129 = 0 ;
V_24 = F_74 ( V_21 , V_23 , & V_25 ,
V_49 , V_85 ) ;
if ( V_24 )
goto V_113;
V_24 = F_41 ( V_21 , & V_25 , false ,
V_49 , V_85 ) ;
V_113:
if ( V_24 && V_25 . V_43 )
F_52 ( V_21 , & V_25 ) ;
return V_24 ;
}
static int F_82 ( struct V_22 * V_23 ,
struct V_83 * V_25 )
{
int V_3 ;
if ( V_25 -> V_43 && V_23 -> V_131 != 0 &&
( V_25 -> V_101 < V_23 -> V_130 ||
V_25 -> V_101 + V_25 -> V_26 > V_23 -> V_131 ) )
return - 1 ;
for ( V_3 = 0 ; V_3 < V_23 -> V_27 ; V_3 ++ ) {
if ( ( V_23 -> V_23 [ V_3 ] & V_25 -> V_23 &
V_90 ) &&
( V_23 -> V_23 [ V_3 ] & V_25 -> V_23 &
V_144 ) )
return V_3 ;
}
return - 1 ;
}
int F_83 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
bool V_49 ,
bool V_85 )
{
int V_24 ;
F_10 ( ! F_18 ( V_21 ) ) ;
if ( V_23 -> V_131 || V_23 -> V_130 )
if ( V_23 -> V_130 > V_23 -> V_131 ||
( V_23 -> V_131 - V_23 -> V_130 ) < V_21 -> V_26 )
return - V_5 ;
V_24 = F_82 ( V_23 , & V_21 -> V_25 ) ;
if ( V_24 < 0 ) {
V_24 = F_81 ( V_21 , V_23 , V_49 ,
V_85 ) ;
if ( V_24 )
return V_24 ;
} else {
F_80 ( & V_21 -> V_25 . V_23 , V_23 -> V_23 [ V_24 ] ,
~ V_148 ) ;
}
if ( V_21 -> V_25 . V_2 == V_16 && V_21 -> V_46 == NULL ) {
V_24 = F_39 ( V_21 , true ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
int F_84 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
F_10 ( ( V_23 -> V_130 || V_23 -> V_131 ) &&
( V_21 -> V_25 . V_26 > ( V_23 -> V_131 - V_23 -> V_130 ) ) ) ;
return 0 ;
}
int F_85 ( struct V_6 * V_7 ,
struct V_20 * V_21 ,
unsigned long V_13 ,
enum V_151 type ,
struct V_22 * V_23 ,
T_1 V_150 ,
bool V_49 ,
struct V_152 * V_153 ,
T_3 V_39 ,
struct V_154 * V_82 ,
void (* V_47) ( struct V_20 * ) )
{
int V_24 = 0 ;
unsigned long V_26 ;
struct V_155 * V_48 = V_7 -> V_34 -> V_48 ;
V_24 = F_86 ( V_48 , V_39 , false , false ) ;
if ( V_24 ) {
F_3 ( L_16 ) ;
if ( V_47 )
(* V_47)( V_21 ) ;
else
F_14 ( V_21 ) ;
return - V_79 ;
}
V_26 = ( V_13 + V_35 - 1 ) >> V_77 ;
if ( V_26 == 0 ) {
F_3 ( L_17 ) ;
if ( V_47 )
(* V_47)( V_21 ) ;
else
F_14 ( V_21 ) ;
F_15 ( V_48 , V_39 ) ;
return - V_5 ;
}
V_21 -> V_47 = V_47 ;
F_87 ( & V_21 -> V_37 ) ;
F_87 ( & V_21 -> V_38 ) ;
F_29 ( & V_21 -> V_41 , 0 ) ;
F_29 ( & V_21 -> V_58 , 1 ) ;
F_88 ( & V_21 -> V_50 ) ;
F_89 ( & V_21 -> V_44 ) ;
F_89 ( & V_21 -> V_45 ) ;
F_89 ( & V_21 -> V_52 ) ;
F_89 ( & V_21 -> V_156 ) ;
V_21 -> V_7 = V_7 ;
V_21 -> V_34 = V_7 -> V_34 ;
V_21 -> type = type ;
V_21 -> V_26 = V_26 ;
V_21 -> V_25 . V_13 = V_26 << V_77 ;
V_21 -> V_25 . V_2 = V_16 ;
V_21 -> V_25 . V_26 = V_21 -> V_26 ;
V_21 -> V_25 . V_43 = NULL ;
V_21 -> V_25 . V_150 = V_150 ;
V_21 -> V_25 . V_127 . V_128 = false ;
V_21 -> V_25 . V_127 . V_129 = 0 ;
V_21 -> V_157 = 0 ;
V_21 -> V_25 . V_23 = ( V_158 | V_139 ) ;
V_21 -> V_59 = false ;
V_21 -> V_153 = V_153 ;
V_21 -> V_39 = V_39 ;
V_21 -> V_82 = V_82 ;
F_90 ( & V_21 -> V_34 -> V_36 ) ;
V_24 = F_84 ( V_21 , V_23 ) ;
if ( F_26 ( V_24 != 0 ) )
goto V_91;
if ( V_21 -> type == V_72 ||
V_21 -> type == V_80 ) {
V_24 = F_91 ( V_21 ) ;
if ( V_24 )
goto V_91;
}
V_24 = F_83 ( V_21 , V_23 , V_49 , false ) ;
if ( V_24 )
goto V_91;
F_38 ( V_21 ) ;
return 0 ;
V_91:
F_38 ( V_21 ) ;
F_69 ( & V_21 ) ;
return V_24 ;
}
T_3 F_92 ( struct V_6 * V_7 ,
unsigned long V_159 ,
unsigned V_160 )
{
unsigned V_161 = ( F_93 ( V_159 ) ) >> V_77 ;
T_3 V_13 = 0 ;
V_13 += F_94 ( V_160 ) ;
V_13 += F_93 ( V_161 * sizeof( void * ) ) ;
V_13 += F_94 ( sizeof( struct V_162 ) ) ;
return V_13 ;
}
T_3 F_95 ( struct V_6 * V_7 ,
unsigned long V_159 ,
unsigned V_160 )
{
unsigned V_161 = ( F_93 ( V_159 ) ) >> V_77 ;
T_3 V_13 = 0 ;
V_13 += F_94 ( V_160 ) ;
V_13 += F_93 ( V_161 * sizeof( void * ) ) ;
V_13 += F_93 ( V_161 * sizeof( V_163 ) ) ;
V_13 += F_94 ( sizeof( struct V_164 ) ) ;
return V_13 ;
}
int F_96 ( struct V_6 * V_7 ,
unsigned long V_13 ,
enum V_151 type ,
struct V_22 * V_23 ,
T_1 V_150 ,
bool V_49 ,
struct V_152 * V_153 ,
struct V_20 * * V_123 )
{
struct V_20 * V_21 ;
T_3 V_39 ;
int V_24 ;
V_21 = F_97 ( sizeof( * V_21 ) , V_165 ) ;
if ( F_26 ( V_21 == NULL ) )
return - V_79 ;
V_39 = F_92 ( V_7 , V_13 , sizeof( struct V_20 ) ) ;
V_24 = F_85 ( V_7 , V_21 , V_13 , type , V_23 , V_150 ,
V_49 , V_153 , V_39 ,
NULL , NULL ) ;
if ( F_36 ( V_24 == 0 ) )
* V_123 = V_21 ;
return V_24 ;
}
static int F_98 ( struct V_6 * V_7 ,
unsigned V_2 , bool V_166 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
struct V_33 * V_34 = V_7 -> V_34 ;
int V_24 ;
F_28 ( & V_34 -> V_64 ) ;
while ( ! F_11 ( & V_9 -> V_44 ) ) {
F_27 ( & V_34 -> V_64 ) ;
V_24 = F_75 ( V_7 , V_2 , false , false ) ;
if ( V_24 ) {
if ( V_166 ) {
return V_24 ;
} else {
F_3 ( L_18 ) ;
}
}
F_28 ( & V_34 -> V_64 ) ;
}
F_27 ( & V_34 -> V_64 ) ;
return 0 ;
}
int F_99 ( struct V_6 * V_7 , unsigned V_2 )
{
struct V_8 * V_9 ;
int V_24 = - V_5 ;
if ( V_2 >= V_167 ) {
F_3 ( L_19 , V_2 ) ;
return V_24 ;
}
V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( ! V_9 -> V_10 ) {
F_3 ( L_20 ,
V_2 ) ;
return V_24 ;
}
V_9 -> V_11 = false ;
V_9 -> V_10 = false ;
V_24 = 0 ;
if ( V_2 > 0 ) {
F_98 ( V_7 , V_2 , false ) ;
V_24 = (* V_9 -> V_17 -> V_168 )( V_9 ) ;
}
return V_24 ;
}
int F_100 ( struct V_6 * V_7 , unsigned V_2 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( V_2 == 0 || V_2 >= V_167 ) {
F_3 ( L_21 , V_2 ) ;
return - V_5 ;
}
if ( ! V_9 -> V_10 ) {
F_3 ( L_22 , V_2 ) ;
return 0 ;
}
return F_98 ( V_7 , V_2 , true ) ;
}
int F_101 ( struct V_6 * V_7 , unsigned type ,
unsigned long V_169 )
{
int V_24 = - V_5 ;
struct V_8 * V_9 ;
F_10 ( type >= V_167 ) ;
V_9 = & V_7 -> V_9 [ type ] ;
F_10 ( V_9 -> V_10 ) ;
V_9 -> V_170 = true ;
V_9 -> V_171 = false ;
F_102 ( & V_9 -> V_172 ) ;
F_89 ( & V_9 -> V_156 ) ;
V_24 = V_7 -> V_75 -> V_173 ( V_7 , type , V_9 ) ;
if ( V_24 )
return V_24 ;
V_9 -> V_7 = V_7 ;
V_24 = 0 ;
if ( type != V_16 ) {
V_24 = (* V_9 -> V_17 -> V_174 )( V_9 , V_169 ) ;
if ( V_24 )
return V_24 ;
}
V_9 -> V_10 = true ;
V_9 -> V_11 = true ;
V_9 -> V_13 = V_169 ;
F_89 ( & V_9 -> V_44 ) ;
return 0 ;
}
static void F_103 ( struct V_28 * V_29 )
{
struct V_33 * V_34 =
F_6 ( V_29 , struct V_33 , V_29 ) ;
F_104 ( V_34 -> V_48 , & V_34 -> V_175 ) ;
F_105 ( V_34 -> V_78 ) ;
F_14 ( V_34 ) ;
}
void F_106 ( struct V_176 * V_177 )
{
struct V_33 * V_34 = V_177 -> V_178 ;
F_107 ( & V_34 -> V_29 ) ;
F_108 ( & V_34 -> V_29 ) ;
}
int F_109 ( struct V_176 * V_177 )
{
struct V_179 * V_180 =
F_6 ( V_177 , struct V_179 , V_177 ) ;
struct V_33 * V_34 = V_177 -> V_178 ;
int V_24 ;
F_102 ( & V_34 -> V_181 ) ;
F_110 ( & V_34 -> V_64 ) ;
V_34 -> V_48 = V_180 -> V_48 ;
V_34 -> V_78 = F_111 ( V_182 | V_183 ) ;
if ( F_26 ( V_34 -> V_78 == NULL ) ) {
V_24 = - V_79 ;
goto V_184;
}
F_89 ( & V_34 -> V_53 ) ;
F_89 ( & V_34 -> V_185 ) ;
F_112 ( & V_34 -> V_175 , V_186 ) ;
V_24 = F_113 ( V_34 -> V_48 , & V_34 -> V_175 ) ;
if ( F_26 ( V_24 != 0 ) ) {
F_3 ( L_23 ) ;
goto V_187;
}
F_29 ( & V_34 -> V_36 , 0 ) ;
V_24 = F_114 (
& V_34 -> V_29 , & V_188 , F_115 () , L_24 ) ;
if ( F_26 ( V_24 != 0 ) )
F_108 ( & V_34 -> V_29 ) ;
return V_24 ;
V_187:
F_105 ( V_34 -> V_78 ) ;
V_184:
F_14 ( V_34 ) ;
return V_24 ;
}
int F_116 ( struct V_6 * V_7 )
{
int V_24 = 0 ;
unsigned V_3 = V_167 ;
struct V_8 * V_9 ;
struct V_33 * V_34 = V_7 -> V_34 ;
while ( V_3 -- ) {
V_9 = & V_7 -> V_9 [ V_3 ] ;
if ( V_9 -> V_10 ) {
V_9 -> V_11 = false ;
if ( ( V_3 != V_16 ) && F_99 ( V_7 , V_3 ) ) {
V_24 = - V_63 ;
F_3 ( L_25 ,
V_3 ) ;
}
V_9 -> V_10 = false ;
}
}
F_117 ( & V_34 -> V_181 ) ;
F_118 ( & V_7 -> V_185 ) ;
F_119 ( & V_34 -> V_181 ) ;
F_71 ( & V_7 -> V_108 ) ;
while ( F_59 ( V_7 , true ) )
;
F_28 ( & V_34 -> V_64 ) ;
if ( F_11 ( & V_7 -> V_45 ) )
F_120 ( L_26 ) ;
if ( F_11 ( & V_7 -> V_9 [ 0 ] . V_44 ) )
F_120 ( L_27 ) ;
F_27 ( & V_34 -> V_64 ) ;
F_10 ( ! F_121 ( & V_7 -> V_189 ) ) ;
F_64 ( & V_7 -> V_119 ) ;
F_122 ( & V_7 -> V_189 ) ;
F_67 ( & V_7 -> V_119 ) ;
return V_24 ;
}
int F_123 ( struct V_6 * V_7 ,
struct V_33 * V_34 ,
struct V_103 * V_75 ,
T_4 V_190 ,
bool V_70 )
{
int V_24 = - V_5 ;
F_124 ( & V_7 -> V_119 ) ;
V_7 -> V_75 = V_75 ;
memset ( V_7 -> V_9 , 0 , sizeof( V_7 -> V_9 ) ) ;
V_24 = F_101 ( V_7 , V_16 , 0 ) ;
if ( F_26 ( V_24 != 0 ) )
goto V_191;
V_7 -> V_122 = V_192 ;
V_24 = F_125 ( & V_7 -> V_189 , V_190 , 0x10000000 ) ;
if ( F_26 ( V_24 != 0 ) )
goto V_193;
F_126 ( & V_7 -> V_108 , F_62 ) ;
F_89 ( & V_7 -> V_45 ) ;
V_7 -> V_194 = NULL ;
V_7 -> V_34 = V_34 ;
V_7 -> V_70 = V_70 ;
V_7 -> V_60 = 0 ;
F_110 ( & V_7 -> V_104 ) ;
F_117 ( & V_34 -> V_181 ) ;
F_21 ( & V_7 -> V_185 , & V_34 -> V_185 ) ;
F_119 ( & V_34 -> V_181 ) ;
return 0 ;
V_193:
F_99 ( V_7 , 0 ) ;
V_191:
return V_24 ;
}
bool F_42 ( struct V_6 * V_7 , struct V_83 * V_25 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_25 -> V_2 ] ;
if ( ! ( V_9 -> V_1 & V_92 ) ) {
if ( V_25 -> V_2 == V_16 )
return false ;
if ( V_9 -> V_1 & V_195 )
return false ;
if ( V_25 -> V_23 & V_139 )
return false ;
}
return true ;
}
void F_44 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
T_5 V_100 = ( T_5 ) V_21 -> V_196 ;
T_5 V_197 = ( ( T_5 ) V_21 -> V_25 . V_26 ) << V_77 ;
if ( ! V_7 -> V_194 )
return;
F_127 ( V_7 -> V_194 , V_100 , V_197 , 1 ) ;
F_68 ( V_21 ) ;
}
void F_128 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
F_43 ( V_9 , false ) ;
F_44 ( V_21 ) ;
F_45 ( V_9 ) ;
}
static void F_129 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_198 * * V_199 = & V_7 -> V_122 . V_198 ;
struct V_198 * V_200 = NULL ;
struct V_20 * V_201 ;
unsigned long V_100 = V_21 -> V_120 -> V_101 ;
unsigned long V_202 ;
while ( * V_199 ) {
V_200 = * V_199 ;
V_201 = F_130 ( V_200 , struct V_20 , V_121 ) ;
V_202 = V_201 -> V_120 -> V_101 ;
if ( V_100 < V_202 )
V_199 = & V_200 -> V_203 ;
else if ( V_100 > V_202 )
V_199 = & V_200 -> V_204 ;
else
F_32 () ;
}
F_131 ( & V_21 -> V_121 , V_200 , V_199 ) ;
F_132 ( & V_21 -> V_121 , & V_7 -> V_122 ) ;
}
static int F_91 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
int V_24 ;
V_205:
V_24 = F_133 ( & V_7 -> V_189 ) ;
if ( F_26 ( V_24 != 0 ) )
return V_24 ;
F_64 ( & V_7 -> V_119 ) ;
V_21 -> V_120 = F_134 ( & V_7 -> V_189 ,
V_21 -> V_25 . V_26 , 0 , 0 ) ;
if ( F_26 ( V_21 -> V_120 == NULL ) ) {
V_24 = - V_79 ;
goto V_113;
}
V_21 -> V_120 = F_135 ( V_21 -> V_120 ,
V_21 -> V_25 . V_26 , 0 ) ;
if ( F_26 ( V_21 -> V_120 == NULL ) ) {
F_67 ( & V_7 -> V_119 ) ;
goto V_205;
}
F_129 ( V_21 ) ;
F_67 ( & V_7 -> V_119 ) ;
V_21 -> V_196 = ( ( T_4 ) V_21 -> V_120 -> V_101 ) << V_77 ;
return 0 ;
V_113:
F_67 ( & V_7 -> V_119 ) ;
return V_24 ;
}
int F_55 ( struct V_20 * V_21 ,
bool V_206 , bool V_49 , bool V_55 )
{
struct V_103 * V_75 = V_21 -> V_7 -> V_75 ;
struct V_6 * V_7 = V_21 -> V_7 ;
void * V_42 ;
int V_24 = 0 ;
if ( F_36 ( V_21 -> V_42 == NULL ) )
return 0 ;
while ( V_21 -> V_42 ) {
if ( V_75 -> V_207 ( V_21 -> V_42 ) ) {
void * V_208 = V_21 -> V_42 ;
V_21 -> V_42 = NULL ;
F_136 ( V_209 , & V_21 -> V_157 ) ;
F_27 ( & V_7 -> V_104 ) ;
V_75 -> V_107 ( & V_208 ) ;
F_28 ( & V_7 -> V_104 ) ;
continue;
}
if ( V_55 )
return - V_63 ;
V_42 = V_75 -> V_105 ( V_21 -> V_42 ) ;
F_27 ( & V_7 -> V_104 ) ;
V_24 = V_75 -> V_110 ( V_42 ,
V_206 , V_49 ) ;
if ( F_26 ( V_24 != 0 ) ) {
V_75 -> V_107 ( & V_42 ) ;
F_28 ( & V_7 -> V_104 ) ;
return V_24 ;
}
F_28 ( & V_7 -> V_104 ) ;
if ( F_36 ( V_21 -> V_42 == V_42 ) ) {
void * V_208 = V_21 -> V_42 ;
V_21 -> V_42 = NULL ;
F_136 ( V_209 ,
& V_21 -> V_157 ) ;
F_27 ( & V_7 -> V_104 ) ;
V_75 -> V_107 ( & V_42 ) ;
V_75 -> V_107 ( & V_208 ) ;
F_28 ( & V_7 -> V_104 ) ;
} else {
F_27 ( & V_7 -> V_104 ) ;
V_75 -> V_107 ( & V_42 ) ;
F_28 ( & V_7 -> V_104 ) ;
}
}
return 0 ;
}
int F_137 ( struct V_20 * V_21 , bool V_55 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
int V_24 = 0 ;
V_24 = F_35 ( V_21 , true , V_55 , false , 0 ) ;
if ( F_26 ( V_24 != 0 ) )
return V_24 ;
F_28 ( & V_7 -> V_104 ) ;
V_24 = F_55 ( V_21 , false , true , V_55 ) ;
F_27 ( & V_7 -> V_104 ) ;
if ( F_36 ( V_24 == 0 ) )
F_90 ( & V_21 -> V_41 ) ;
F_38 ( V_21 ) ;
return V_24 ;
}
void F_138 ( struct V_20 * V_21 )
{
F_13 ( & V_21 -> V_41 ) ;
}
static int V_186 ( struct V_210 * V_175 )
{
struct V_33 * V_34 =
F_6 ( V_175 , struct V_33 , V_175 ) ;
struct V_20 * V_21 ;
int V_24 = - V_63 ;
int V_54 ;
T_1 V_211 = ( V_139 | V_158 ) ;
F_28 ( & V_34 -> V_64 ) ;
F_76 (bo, &glob->swap_lru, swap) {
V_24 = F_25 ( V_21 , false , true , false , 0 ) ;
if ( ! V_24 )
break;
}
if ( V_24 ) {
F_27 ( & V_34 -> V_64 ) ;
return V_24 ;
}
F_22 ( & V_21 -> V_38 ) ;
if ( ! F_11 ( & V_21 -> V_45 ) ) {
V_24 = F_57 ( V_21 , false , false ) ;
F_61 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
V_54 = F_23 ( V_21 ) ;
F_27 ( & V_34 -> V_64 ) ;
F_33 ( V_21 , V_54 , true ) ;
F_28 ( & V_21 -> V_7 -> V_104 ) ;
V_24 = F_55 ( V_21 , false , false , false ) ;
F_27 ( & V_21 -> V_7 -> V_104 ) ;
if ( F_26 ( V_24 != 0 ) )
goto V_116;
if ( ( V_21 -> V_25 . V_23 & V_211 ) != V_211 ) {
struct V_83 V_125 ;
V_125 = V_21 -> V_25 ;
V_125 . V_43 = NULL ;
V_125 . V_23 = V_158 | V_139 ;
V_125 . V_2 = V_16 ;
V_24 = F_41 ( V_21 , & V_125 , true ,
false , false ) ;
if ( F_26 ( V_24 != 0 ) )
goto V_116;
}
F_128 ( V_21 ) ;
if ( V_21 -> V_7 -> V_75 -> V_212 )
V_21 -> V_7 -> V_75 -> V_212 ( V_21 ) ;
V_24 = F_139 ( V_21 -> V_46 , V_21 -> V_153 ) ;
V_116:
F_29 ( & V_21 -> V_58 , 0 ) ;
F_30 ( & V_21 -> V_50 ) ;
F_61 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
void F_140 ( struct V_6 * V_7 )
{
while ( V_186 ( & V_7 -> V_34 -> V_175 ) == 0 )
;
}
