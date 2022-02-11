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
if ( V_21 -> V_47 == & V_21 -> V_48 )
F_14 ( & V_21 -> V_48 ) ;
if ( V_21 -> V_49 )
V_21 -> V_49 ( V_21 ) ;
else {
F_15 ( V_21 ) ;
}
F_16 ( V_7 -> V_34 -> V_50 , V_39 ) ;
}
void F_17 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 ;
F_18 ( & V_21 -> V_47 -> V_51 . V_52 ) ;
if ( ! ( V_21 -> V_25 . V_23 & V_53 ) ) {
F_10 ( ! F_11 ( & V_21 -> V_44 ) ) ;
V_9 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
F_19 ( & V_21 -> V_44 , & V_9 -> V_44 ) ;
F_20 ( & V_21 -> V_38 ) ;
if ( V_21 -> V_46 != NULL ) {
F_19 ( & V_21 -> V_54 , & V_21 -> V_34 -> V_55 ) ;
F_20 ( & V_21 -> V_38 ) ;
}
}
}
int F_21 ( struct V_20 * V_21 )
{
int V_56 = 0 ;
if ( ! F_11 ( & V_21 -> V_54 ) ) {
F_22 ( & V_21 -> V_54 ) ;
++ V_56 ;
}
if ( ! F_11 ( & V_21 -> V_44 ) ) {
F_22 ( & V_21 -> V_44 ) ;
++ V_56 ;
}
return V_56 ;
}
static void F_23 ( struct V_37 * V_38 )
{
F_24 () ;
}
void F_25 ( struct V_20 * V_21 , int V_57 ,
bool V_58 )
{
F_26 ( & V_21 -> V_38 , V_57 ,
( V_58 ) ? F_23 : F_9 ) ;
}
void F_27 ( struct V_20 * V_21 )
{
int V_56 ;
F_28 ( & V_21 -> V_34 -> V_59 ) ;
V_56 = F_21 ( V_21 ) ;
F_29 ( & V_21 -> V_34 -> V_59 ) ;
F_25 ( V_21 , V_56 , true ) ;
}
static int F_30 ( struct V_20 * V_21 , bool V_60 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_33 * V_34 = V_21 -> V_34 ;
int V_24 = 0 ;
T_1 V_61 = 0 ;
F_31 ( & V_21 -> V_62 ) ;
V_21 -> V_46 = NULL ;
if ( V_7 -> V_63 )
V_61 |= V_64 ;
switch ( V_21 -> type ) {
case V_65 :
if ( V_60 )
V_61 |= V_66 ;
case V_67 :
V_21 -> V_46 = V_7 -> V_68 -> V_69 ( V_7 , V_21 -> V_26 << V_70 ,
V_61 , V_34 -> V_71 ) ;
if ( F_32 ( V_21 -> V_46 == NULL ) )
V_24 = - V_72 ;
break;
case V_73 :
V_21 -> V_46 = V_7 -> V_68 -> V_69 ( V_7 , V_21 -> V_26 << V_70 ,
V_61 | V_74 ,
V_34 -> V_71 ) ;
if ( F_32 ( V_21 -> V_46 == NULL ) ) {
V_24 = - V_72 ;
break;
}
V_21 -> V_46 -> V_75 = V_21 -> V_75 ;
break;
default:
F_3 ( L_11 ) ;
V_24 = - V_5 ;
break;
}
return V_24 ;
}
static int F_33 ( struct V_20 * V_21 ,
struct V_76 * V_25 ,
bool V_77 , bool V_78 ,
bool V_79 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
bool V_80 = F_34 ( V_7 , & V_21 -> V_25 ) ;
bool V_81 = F_34 ( V_7 , V_25 ) ;
struct V_8 * V_82 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
struct V_8 * V_83 = & V_7 -> V_9 [ V_25 -> V_2 ] ;
int V_24 = 0 ;
if ( V_80 || V_81 ||
( ( V_25 -> V_23 & V_21 -> V_25 . V_23 & V_84 ) == 0 ) ) {
V_24 = F_35 ( V_82 , true ) ;
if ( F_32 ( V_24 != 0 ) )
goto V_85;
F_36 ( V_21 ) ;
F_37 ( V_82 ) ;
}
if ( ! ( V_83 -> V_1 & V_86 ) ) {
if ( V_21 -> V_46 == NULL ) {
bool V_87 = ! ( V_82 -> V_1 & V_86 ) ;
V_24 = F_30 ( V_21 , V_87 ) ;
if ( V_24 )
goto V_85;
}
V_24 = F_38 ( V_21 -> V_46 , V_25 -> V_23 ) ;
if ( V_24 )
goto V_85;
if ( V_25 -> V_2 != V_16 ) {
V_24 = F_39 ( V_21 -> V_46 , V_25 ) ;
if ( V_24 )
goto V_85;
}
if ( V_21 -> V_25 . V_2 == V_16 ) {
if ( V_7 -> V_68 -> V_88 )
V_7 -> V_68 -> V_88 ( V_21 , V_25 ) ;
V_21 -> V_25 = * V_25 ;
V_25 -> V_43 = NULL ;
goto V_89;
}
}
if ( V_7 -> V_68 -> V_88 )
V_7 -> V_68 -> V_88 ( V_21 , V_25 ) ;
if ( ! ( V_82 -> V_1 & V_86 ) &&
! ( V_83 -> V_1 & V_86 ) )
V_24 = F_40 ( V_21 , V_77 , V_79 , V_25 ) ;
else if ( V_7 -> V_68 -> V_90 )
V_24 = V_7 -> V_68 -> V_90 ( V_21 , V_77 , V_78 ,
V_79 , V_25 ) ;
else
V_24 = F_41 ( V_21 , V_77 , V_79 , V_25 ) ;
if ( V_24 ) {
if ( V_7 -> V_68 -> V_88 ) {
struct V_76 V_91 = * V_25 ;
* V_25 = V_21 -> V_25 ;
V_21 -> V_25 = V_91 ;
V_7 -> V_68 -> V_88 ( V_21 , V_25 ) ;
V_21 -> V_25 = * V_25 ;
* V_25 = V_91 ;
}
goto V_85;
}
V_89:
if ( V_21 -> V_92 ) {
V_24 = V_7 -> V_68 -> V_93 ( V_7 , V_21 -> V_25 . V_23 ) ;
if ( V_24 )
F_3 ( L_12 ) ;
V_21 -> V_92 = false ;
}
if ( V_21 -> V_25 . V_43 ) {
V_21 -> V_94 = ( V_21 -> V_25 . V_95 << V_70 ) +
V_7 -> V_9 [ V_21 -> V_25 . V_2 ] . V_12 ;
V_21 -> V_96 = V_21 -> V_25 . V_23 ;
} else
V_21 -> V_94 = 0 ;
return 0 ;
V_85:
V_83 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
if ( ( V_83 -> V_1 & V_86 ) && V_21 -> V_46 ) {
F_42 ( V_21 -> V_46 ) ;
F_12 ( V_21 -> V_46 ) ;
V_21 -> V_46 = NULL ;
}
return V_24 ;
}
static void F_43 ( struct V_20 * V_21 )
{
if ( V_21 -> V_7 -> V_68 -> V_88 )
V_21 -> V_7 -> V_68 -> V_88 ( V_21 , NULL ) ;
if ( V_21 -> V_46 ) {
F_42 ( V_21 -> V_46 ) ;
F_12 ( V_21 -> V_46 ) ;
V_21 -> V_46 = NULL ;
}
F_44 ( V_21 , & V_21 -> V_25 ) ;
F_45 ( & V_21 -> V_47 -> V_51 ) ;
}
static void F_46 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_33 * V_34 = V_21 -> V_34 ;
struct V_97 * V_68 = V_7 -> V_68 ;
void * V_42 = NULL ;
int V_56 ;
int V_24 ;
F_28 ( & V_34 -> V_59 ) ;
V_24 = F_47 ( V_21 , false , true , false , 0 ) ;
F_28 ( & V_7 -> V_98 ) ;
( void ) F_48 ( V_21 , false , false , true ) ;
if ( ! V_24 && ! V_21 -> V_42 ) {
F_29 ( & V_7 -> V_98 ) ;
V_56 = F_21 ( V_21 ) ;
F_29 ( & V_34 -> V_59 ) ;
F_43 ( V_21 ) ;
F_25 ( V_21 , V_56 , true ) ;
return;
}
if ( V_21 -> V_42 )
V_42 = V_68 -> V_99 ( V_21 -> V_42 ) ;
F_29 ( & V_7 -> V_98 ) ;
if ( ! V_24 )
F_45 ( & V_21 -> V_47 -> V_51 ) ;
F_20 ( & V_21 -> V_38 ) ;
F_19 ( & V_21 -> V_45 , & V_7 -> V_45 ) ;
F_29 ( & V_34 -> V_59 ) ;
if ( V_42 ) {
V_68 -> V_100 ( V_42 ) ;
V_68 -> V_101 ( & V_42 ) ;
}
F_49 ( & V_7 -> V_102 ,
( ( V_103 / 100 ) < 1 ) ? 1 : V_103 / 100 ) ;
}
static int F_50 ( struct V_20 * V_21 ,
bool V_78 ,
bool V_79 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_97 * V_68 = V_7 -> V_68 ;
struct V_33 * V_34 = V_21 -> V_34 ;
int V_56 ;
int V_24 ;
F_28 ( & V_7 -> V_98 ) ;
V_24 = F_48 ( V_21 , false , false , true ) ;
if ( V_24 && ! V_79 ) {
void * V_42 ;
V_42 = V_68 -> V_99 ( V_21 -> V_42 ) ;
F_29 ( & V_7 -> V_98 ) ;
F_45 ( & V_21 -> V_47 -> V_51 ) ;
F_29 ( & V_34 -> V_59 ) ;
V_24 = V_68 -> V_104 ( V_42 , false , V_78 ) ;
V_68 -> V_101 ( & V_42 ) ;
if ( V_24 )
return V_24 ;
F_28 ( & V_7 -> V_98 ) ;
V_24 = F_48 ( V_21 , false , false , true ) ;
F_51 ( V_24 ) ;
F_29 ( & V_7 -> V_98 ) ;
if ( V_24 )
return V_24 ;
F_28 ( & V_34 -> V_59 ) ;
V_24 = F_47 ( V_21 , false , true , false , 0 ) ;
if ( V_24 ) {
F_29 ( & V_34 -> V_59 ) ;
return 0 ;
}
} else
F_29 ( & V_7 -> V_98 ) ;
if ( V_24 || F_32 ( F_11 ( & V_21 -> V_45 ) ) ) {
F_45 ( & V_21 -> V_47 -> V_51 ) ;
F_29 ( & V_34 -> V_59 ) ;
return V_24 ;
}
V_56 = F_21 ( V_21 ) ;
F_22 ( & V_21 -> V_45 ) ;
++ V_56 ;
F_29 ( & V_34 -> V_59 ) ;
F_43 ( V_21 ) ;
F_25 ( V_21 , V_56 , true ) ;
return 0 ;
}
static int F_52 ( struct V_6 * V_7 , bool V_105 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
struct V_20 * V_106 = NULL ;
int V_24 = 0 ;
F_28 ( & V_34 -> V_59 ) ;
if ( F_11 ( & V_7 -> V_45 ) )
goto V_107;
V_106 = F_53 ( & V_7 -> V_45 ,
struct V_20 , V_45 ) ;
F_20 ( & V_106 -> V_38 ) ;
for (; ; ) {
struct V_20 * V_108 = NULL ;
if ( V_106 -> V_45 . V_109 != & V_7 -> V_45 ) {
V_108 = F_53 ( & V_106 -> V_45 ,
struct V_20 , V_45 ) ;
F_20 ( & V_108 -> V_38 ) ;
}
V_24 = F_47 ( V_106 , false , true , false , 0 ) ;
if ( V_105 && V_24 ) {
F_29 ( & V_34 -> V_59 ) ;
V_24 = F_47 ( V_106 , false , false ,
false , 0 ) ;
F_28 ( & V_34 -> V_59 ) ;
}
if ( ! V_24 )
V_24 = F_50 ( V_106 , false ,
! V_105 ) ;
else
F_29 ( & V_34 -> V_59 ) ;
F_54 ( & V_106 -> V_38 , F_9 ) ;
V_106 = V_108 ;
if ( V_24 || ! V_106 )
goto V_110;
F_28 ( & V_34 -> V_59 ) ;
if ( F_11 ( & V_106 -> V_45 ) )
break;
}
V_107:
F_29 ( & V_34 -> V_59 ) ;
V_110:
if ( V_106 )
F_54 ( & V_106 -> V_38 , F_9 ) ;
return V_24 ;
}
static void F_55 ( struct V_111 * V_112 )
{
struct V_6 * V_7 =
F_6 ( V_112 , struct V_6 , V_102 . V_112 ) ;
if ( F_52 ( V_7 , false ) ) {
F_49 ( & V_7 -> V_102 ,
( ( V_103 / 100 ) < 1 ) ? 1 : V_103 / 100 ) ;
}
}
static void F_56 ( struct V_37 * V_37 )
{
struct V_20 * V_21 =
F_6 ( V_37 , struct V_20 , V_37 ) ;
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
F_57 ( & V_7 -> V_113 ) ;
if ( F_58 ( V_21 -> V_114 != NULL ) ) {
F_59 ( & V_21 -> V_115 , & V_7 -> V_116 ) ;
F_60 ( V_21 -> V_114 ) ;
V_21 -> V_114 = NULL ;
}
F_61 ( & V_7 -> V_113 ) ;
F_35 ( V_9 , false ) ;
F_62 ( V_21 ) ;
F_37 ( V_9 ) ;
F_46 ( V_21 ) ;
F_54 ( & V_21 -> V_38 , F_9 ) ;
}
void F_63 ( struct V_20 * * V_117 )
{
struct V_20 * V_21 = * V_117 ;
* V_117 = NULL ;
F_54 ( & V_21 -> V_37 , F_56 ) ;
}
int F_64 ( struct V_6 * V_7 )
{
return F_65 ( & V_7 -> V_102 ) ;
}
void F_66 ( struct V_6 * V_7 , int V_118 )
{
if ( V_118 )
F_49 ( & V_7 -> V_102 ,
( ( V_103 / 100 ) < 1 ) ? 1 : V_103 / 100 ) ;
}
static int F_67 ( struct V_20 * V_21 , bool V_78 ,
bool V_79 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_76 V_119 ;
struct V_22 V_23 ;
int V_24 = 0 ;
F_28 ( & V_7 -> V_98 ) ;
V_24 = F_48 ( V_21 , false , V_78 , V_79 ) ;
F_29 ( & V_7 -> V_98 ) ;
if ( F_32 ( V_24 != 0 ) ) {
if ( V_24 != - V_120 ) {
F_3 ( L_13 ) ;
}
goto V_110;
}
F_18 ( & V_21 -> V_47 -> V_51 . V_52 ) ;
V_119 = V_21 -> V_25 ;
V_119 . V_43 = NULL ;
V_119 . V_121 . V_122 = false ;
V_119 . V_121 . V_123 = 0 ;
V_23 . V_124 = 0 ;
V_23 . V_125 = 0 ;
V_23 . V_27 = 0 ;
V_23 . V_126 = 0 ;
V_7 -> V_68 -> V_127 ( V_21 , & V_23 ) ;
V_24 = F_68 ( V_21 , & V_23 , & V_119 , V_78 ,
V_79 ) ;
if ( V_24 ) {
if ( V_24 != - V_120 ) {
F_3 ( L_14 ,
V_21 ) ;
F_4 ( V_21 , & V_23 ) ;
}
goto V_110;
}
V_24 = F_33 ( V_21 , & V_119 , true , V_78 ,
V_79 ) ;
if ( V_24 ) {
if ( V_24 != - V_120 )
F_3 ( L_15 ) ;
F_44 ( V_21 , & V_119 ) ;
goto V_110;
}
V_21 -> V_92 = true ;
V_110:
return V_24 ;
}
static int F_69 ( struct V_6 * V_7 ,
T_1 V_2 ,
bool V_78 ,
bool V_79 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
struct V_20 * V_21 ;
int V_24 = - V_128 , V_56 ;
F_28 ( & V_34 -> V_59 ) ;
F_70 (bo, &man->lru, lru) {
V_24 = F_47 ( V_21 , false , true , false , 0 ) ;
if ( ! V_24 )
break;
}
if ( V_24 ) {
F_29 ( & V_34 -> V_59 ) ;
return V_24 ;
}
F_20 ( & V_21 -> V_38 ) ;
if ( ! F_11 ( & V_21 -> V_45 ) ) {
V_24 = F_50 ( V_21 , V_78 ,
V_79 ) ;
F_54 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
V_56 = F_21 ( V_21 ) ;
F_29 ( & V_34 -> V_59 ) ;
F_10 ( V_24 != 0 ) ;
F_25 ( V_21 , V_56 , true ) ;
V_24 = F_67 ( V_21 , V_78 , V_79 ) ;
F_71 ( V_21 ) ;
F_54 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
void F_44 ( struct V_20 * V_21 , struct V_76 * V_25 )
{
struct V_8 * V_9 = & V_21 -> V_7 -> V_9 [ V_25 -> V_2 ] ;
if ( V_25 -> V_43 )
(* V_9 -> V_17 -> V_129 )( V_9 , V_25 ) ;
}
static int F_72 ( struct V_20 * V_21 ,
T_1 V_2 ,
struct V_22 * V_23 ,
struct V_76 * V_25 ,
bool V_78 ,
bool V_79 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
int V_24 ;
do {
V_24 = (* V_9 -> V_17 -> V_130 )( V_9 , V_21 , V_23 , V_25 ) ;
if ( F_32 ( V_24 != 0 ) )
return V_24 ;
if ( V_25 -> V_43 )
break;
V_24 = F_69 ( V_7 , V_2 ,
V_78 , V_79 ) ;
if ( F_32 ( V_24 != 0 ) )
return V_24 ;
} while ( 1 );
if ( V_25 -> V_43 == NULL )
return - V_72 ;
V_25 -> V_2 = V_2 ;
return 0 ;
}
static T_1 F_73 ( struct V_8 * V_9 ,
T_1 V_96 ,
T_1 V_131 )
{
T_1 V_132 = V_131 & V_84 ;
T_1 V_133 = V_131 & ~ V_84 ;
if ( ( V_96 & V_132 ) != 0 )
V_133 |= ( V_96 & V_132 ) ;
else if ( ( V_9 -> V_15 & V_132 ) != 0 )
V_133 |= V_9 -> V_15 ;
else if ( ( V_134 & V_132 ) != 0 )
V_133 |= V_134 ;
else if ( ( V_135 & V_132 ) != 0 )
V_133 |= V_135 ;
else if ( ( V_136 & V_132 ) != 0 )
V_133 |= V_136 ;
return V_133 ;
}
static bool F_74 ( struct V_8 * V_9 ,
T_1 V_2 ,
T_1 V_131 ,
T_1 * V_137 )
{
T_1 V_138 = F_8 ( V_2 ) ;
if ( ( V_138 & V_131 & V_139 ) == 0 )
return false ;
if ( ( V_131 & V_9 -> V_14 ) == 0 )
return false ;
V_138 |= ( V_131 & V_9 -> V_14 ) ;
* V_137 = V_138 ;
return true ;
}
int F_68 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_76 * V_25 ,
bool V_78 ,
bool V_79 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 ;
T_1 V_2 = V_16 ;
T_1 V_138 = 0 ;
bool V_140 = false ;
bool V_141 = false ;
bool V_142 = false ;
int V_3 , V_24 ;
V_25 -> V_43 = NULL ;
for ( V_3 = 0 ; V_3 < V_23 -> V_27 ; ++ V_3 ) {
V_24 = F_1 ( V_23 -> V_23 [ V_3 ] ,
& V_2 ) ;
if ( V_24 )
return V_24 ;
V_9 = & V_7 -> V_9 [ V_2 ] ;
V_141 = F_74 ( V_9 ,
V_2 ,
V_23 -> V_23 [ V_3 ] ,
& V_138 ) ;
if ( ! V_141 )
continue;
V_138 = F_73 ( V_9 , V_21 -> V_25 . V_23 ,
V_138 ) ;
F_75 ( & V_138 , V_23 -> V_23 [ V_3 ] ,
~ V_143 ) ;
if ( V_2 == V_16 )
break;
if ( V_9 -> V_10 && V_9 -> V_11 ) {
V_140 = true ;
V_24 = (* V_9 -> V_17 -> V_130 )( V_9 , V_21 , V_23 , V_25 ) ;
if ( F_32 ( V_24 ) )
return V_24 ;
}
if ( V_25 -> V_43 )
break;
}
if ( ( V_141 && ( V_2 == V_16 ) ) || V_25 -> V_43 ) {
V_25 -> V_2 = V_2 ;
V_25 -> V_23 = V_138 ;
return 0 ;
}
if ( ! V_140 )
return - V_5 ;
for ( V_3 = 0 ; V_3 < V_23 -> V_126 ; ++ V_3 ) {
V_24 = F_1 ( V_23 -> V_144 [ V_3 ] ,
& V_2 ) ;
if ( V_24 )
return V_24 ;
V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( ! V_9 -> V_10 )
continue;
if ( ! F_74 ( V_9 ,
V_2 ,
V_23 -> V_144 [ V_3 ] ,
& V_138 ) )
continue;
V_138 = F_73 ( V_9 , V_21 -> V_25 . V_23 ,
V_138 ) ;
F_75 ( & V_138 , V_23 -> V_144 [ V_3 ] ,
~ V_143 ) ;
if ( V_2 == V_16 ) {
V_25 -> V_2 = V_2 ;
V_25 -> V_23 = V_138 ;
V_25 -> V_43 = NULL ;
return 0 ;
}
V_24 = F_72 ( V_21 , V_2 , V_23 , V_25 ,
V_78 , V_79 ) ;
if ( V_24 == 0 && V_25 -> V_43 ) {
V_25 -> V_23 = V_138 ;
return 0 ;
}
if ( V_24 == - V_120 )
V_142 = true ;
}
V_24 = ( V_142 ) ? - V_120 : - V_72 ;
return V_24 ;
}
int F_76 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
bool V_78 ,
bool V_79 )
{
int V_24 = 0 ;
struct V_76 V_25 ;
struct V_6 * V_7 = V_21 -> V_7 ;
F_18 ( & V_21 -> V_47 -> V_51 . V_52 ) ;
F_28 ( & V_7 -> V_98 ) ;
V_24 = F_48 ( V_21 , false , V_78 , V_79 ) ;
F_29 ( & V_7 -> V_98 ) ;
if ( V_24 )
return V_24 ;
V_25 . V_26 = V_21 -> V_26 ;
V_25 . V_13 = V_25 . V_26 << V_70 ;
V_25 . V_145 = V_21 -> V_25 . V_145 ;
V_25 . V_121 . V_122 = false ;
V_25 . V_121 . V_123 = 0 ;
V_24 = F_68 ( V_21 , V_23 , & V_25 ,
V_78 , V_79 ) ;
if ( V_24 )
goto V_107;
V_24 = F_33 ( V_21 , & V_25 , false ,
V_78 , V_79 ) ;
V_107:
if ( V_24 && V_25 . V_43 )
F_44 ( V_21 , & V_25 ) ;
return V_24 ;
}
static int F_77 ( struct V_22 * V_23 ,
struct V_76 * V_25 )
{
int V_3 ;
if ( V_25 -> V_43 && V_23 -> V_125 != 0 &&
( V_25 -> V_95 < V_23 -> V_124 ||
V_25 -> V_95 + V_25 -> V_26 > V_23 -> V_125 ) )
return - 1 ;
for ( V_3 = 0 ; V_3 < V_23 -> V_27 ; V_3 ++ ) {
if ( ( V_23 -> V_23 [ V_3 ] & V_25 -> V_23 &
V_84 ) &&
( V_23 -> V_23 [ V_3 ] & V_25 -> V_23 &
V_139 ) )
return V_3 ;
}
return - 1 ;
}
int F_78 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
bool V_78 ,
bool V_79 )
{
int V_24 ;
F_18 ( & V_21 -> V_47 -> V_51 . V_52 ) ;
if ( V_23 -> V_125 || V_23 -> V_124 )
if ( V_23 -> V_124 > V_23 -> V_125 ||
( V_23 -> V_125 - V_23 -> V_124 ) < V_21 -> V_26 )
return - V_5 ;
V_24 = F_77 ( V_23 , & V_21 -> V_25 ) ;
if ( V_24 < 0 ) {
V_24 = F_76 ( V_21 , V_23 , V_78 ,
V_79 ) ;
if ( V_24 )
return V_24 ;
} else {
F_75 ( & V_21 -> V_25 . V_23 , V_23 -> V_23 [ V_24 ] ,
~ V_143 ) ;
}
if ( V_21 -> V_25 . V_2 == V_16 && V_21 -> V_46 == NULL ) {
V_24 = F_30 ( V_21 , true ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
int F_79 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
F_10 ( ( V_23 -> V_124 || V_23 -> V_125 ) &&
( V_21 -> V_25 . V_26 > ( V_23 -> V_125 - V_23 -> V_124 ) ) ) ;
return 0 ;
}
int F_80 ( struct V_6 * V_7 ,
struct V_20 * V_21 ,
unsigned long V_13 ,
enum V_146 type ,
struct V_22 * V_23 ,
T_1 V_145 ,
bool V_78 ,
struct V_147 * V_148 ,
T_3 V_39 ,
struct V_149 * V_75 ,
void (* V_49) ( struct V_20 * ) )
{
int V_24 = 0 ;
unsigned long V_26 ;
struct V_150 * V_50 = V_7 -> V_34 -> V_50 ;
bool V_151 ;
V_24 = F_81 ( V_50 , V_39 , false , false ) ;
if ( V_24 ) {
F_3 ( L_16 ) ;
if ( V_49 )
(* V_49)( V_21 ) ;
else
F_15 ( V_21 ) ;
return - V_72 ;
}
V_26 = ( V_13 + V_35 - 1 ) >> V_70 ;
if ( V_26 == 0 ) {
F_3 ( L_17 ) ;
if ( V_49 )
(* V_49)( V_21 ) ;
else
F_15 ( V_21 ) ;
F_16 ( V_50 , V_39 ) ;
return - V_5 ;
}
V_21 -> V_49 = V_49 ;
F_82 ( & V_21 -> V_37 ) ;
F_82 ( & V_21 -> V_38 ) ;
F_83 ( & V_21 -> V_41 , 0 ) ;
F_84 ( & V_21 -> V_44 ) ;
F_84 ( & V_21 -> V_45 ) ;
F_84 ( & V_21 -> V_54 ) ;
F_84 ( & V_21 -> V_152 ) ;
V_21 -> V_7 = V_7 ;
V_21 -> V_34 = V_7 -> V_34 ;
V_21 -> type = type ;
V_21 -> V_26 = V_26 ;
V_21 -> V_25 . V_13 = V_26 << V_70 ;
V_21 -> V_25 . V_2 = V_16 ;
V_21 -> V_25 . V_26 = V_21 -> V_26 ;
V_21 -> V_25 . V_43 = NULL ;
V_21 -> V_25 . V_145 = V_145 ;
V_21 -> V_25 . V_121 . V_122 = false ;
V_21 -> V_25 . V_121 . V_123 = 0 ;
V_21 -> V_153 = 0 ;
V_21 -> V_25 . V_23 = ( V_154 | V_134 ) ;
V_21 -> V_148 = V_148 ;
V_21 -> V_39 = V_39 ;
V_21 -> V_75 = V_75 ;
V_21 -> V_47 = & V_21 -> V_48 ;
F_85 ( V_21 -> V_47 ) ;
F_86 ( & V_21 -> V_34 -> V_36 ) ;
V_24 = F_79 ( V_21 , V_23 ) ;
if ( F_58 ( ! V_24 ) &&
( V_21 -> type == V_65 ||
V_21 -> type == V_73 ) )
V_24 = F_87 ( V_21 ) ;
V_151 = F_88 ( & V_21 -> V_47 -> V_51 ) ;
F_51 ( ! V_151 ) ;
if ( F_58 ( ! V_24 ) )
V_24 = F_78 ( V_21 , V_23 , V_78 , false ) ;
F_71 ( V_21 ) ;
if ( F_32 ( V_24 ) )
F_63 ( & V_21 ) ;
return V_24 ;
}
T_3 F_89 ( struct V_6 * V_7 ,
unsigned long V_155 ,
unsigned V_156 )
{
unsigned V_157 = ( F_90 ( V_155 ) ) >> V_70 ;
T_3 V_13 = 0 ;
V_13 += F_91 ( V_156 ) ;
V_13 += F_90 ( V_157 * sizeof( void * ) ) ;
V_13 += F_91 ( sizeof( struct V_158 ) ) ;
return V_13 ;
}
T_3 F_92 ( struct V_6 * V_7 ,
unsigned long V_155 ,
unsigned V_156 )
{
unsigned V_157 = ( F_90 ( V_155 ) ) >> V_70 ;
T_3 V_13 = 0 ;
V_13 += F_91 ( V_156 ) ;
V_13 += F_90 ( V_157 * sizeof( void * ) ) ;
V_13 += F_90 ( V_157 * sizeof( V_159 ) ) ;
V_13 += F_91 ( sizeof( struct V_160 ) ) ;
return V_13 ;
}
int F_93 ( struct V_6 * V_7 ,
unsigned long V_13 ,
enum V_146 type ,
struct V_22 * V_23 ,
T_1 V_145 ,
bool V_78 ,
struct V_147 * V_148 ,
struct V_20 * * V_117 )
{
struct V_20 * V_21 ;
T_3 V_39 ;
int V_24 ;
V_21 = F_94 ( sizeof( * V_21 ) , V_161 ) ;
if ( F_32 ( V_21 == NULL ) )
return - V_72 ;
V_39 = F_89 ( V_7 , V_13 , sizeof( struct V_20 ) ) ;
V_24 = F_80 ( V_7 , V_21 , V_13 , type , V_23 , V_145 ,
V_78 , V_148 , V_39 ,
NULL , NULL ) ;
if ( F_58 ( V_24 == 0 ) )
* V_117 = V_21 ;
return V_24 ;
}
static int F_95 ( struct V_6 * V_7 ,
unsigned V_2 , bool V_162 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
struct V_33 * V_34 = V_7 -> V_34 ;
int V_24 ;
F_28 ( & V_34 -> V_59 ) ;
while ( ! F_11 ( & V_9 -> V_44 ) ) {
F_29 ( & V_34 -> V_59 ) ;
V_24 = F_69 ( V_7 , V_2 , false , false ) ;
if ( V_24 ) {
if ( V_162 ) {
return V_24 ;
} else {
F_3 ( L_18 ) ;
}
}
F_28 ( & V_34 -> V_59 ) ;
}
F_29 ( & V_34 -> V_59 ) ;
return 0 ;
}
int F_96 ( struct V_6 * V_7 , unsigned V_2 )
{
struct V_8 * V_9 ;
int V_24 = - V_5 ;
if ( V_2 >= V_163 ) {
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
F_95 ( V_7 , V_2 , false ) ;
V_24 = (* V_9 -> V_17 -> V_164 )( V_9 ) ;
}
return V_24 ;
}
int F_97 ( struct V_6 * V_7 , unsigned V_2 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( V_2 == 0 || V_2 >= V_163 ) {
F_3 ( L_21 , V_2 ) ;
return - V_5 ;
}
if ( ! V_9 -> V_10 ) {
F_3 ( L_22 , V_2 ) ;
return 0 ;
}
return F_95 ( V_7 , V_2 , true ) ;
}
int F_98 ( struct V_6 * V_7 , unsigned type ,
unsigned long V_165 )
{
int V_24 = - V_5 ;
struct V_8 * V_9 ;
F_10 ( type >= V_163 ) ;
V_9 = & V_7 -> V_9 [ type ] ;
F_10 ( V_9 -> V_10 ) ;
V_9 -> V_166 = true ;
V_9 -> V_167 = false ;
F_99 ( & V_9 -> V_168 ) ;
F_84 ( & V_9 -> V_152 ) ;
V_24 = V_7 -> V_68 -> V_169 ( V_7 , type , V_9 ) ;
if ( V_24 )
return V_24 ;
V_9 -> V_7 = V_7 ;
V_24 = 0 ;
if ( type != V_16 ) {
V_24 = (* V_9 -> V_17 -> V_170 )( V_9 , V_165 ) ;
if ( V_24 )
return V_24 ;
}
V_9 -> V_10 = true ;
V_9 -> V_11 = true ;
V_9 -> V_13 = V_165 ;
F_84 ( & V_9 -> V_44 ) ;
return 0 ;
}
static void F_100 ( struct V_28 * V_29 )
{
struct V_33 * V_34 =
F_6 ( V_29 , struct V_33 , V_29 ) ;
F_101 ( V_34 -> V_50 , & V_34 -> V_171 ) ;
F_102 ( V_34 -> V_71 ) ;
F_15 ( V_34 ) ;
}
void F_103 ( struct V_172 * V_173 )
{
struct V_33 * V_34 = V_173 -> V_174 ;
F_104 ( & V_34 -> V_29 ) ;
F_105 ( & V_34 -> V_29 ) ;
}
int F_106 ( struct V_172 * V_173 )
{
struct V_175 * V_176 =
F_6 ( V_173 , struct V_175 , V_173 ) ;
struct V_33 * V_34 = V_173 -> V_174 ;
int V_24 ;
F_99 ( & V_34 -> V_177 ) ;
F_107 ( & V_34 -> V_59 ) ;
V_34 -> V_50 = V_176 -> V_50 ;
V_34 -> V_71 = F_108 ( V_178 | V_179 ) ;
if ( F_32 ( V_34 -> V_71 == NULL ) ) {
V_24 = - V_72 ;
goto V_180;
}
F_84 ( & V_34 -> V_55 ) ;
F_84 ( & V_34 -> V_181 ) ;
F_109 ( & V_34 -> V_171 , V_182 ) ;
V_24 = F_110 ( V_34 -> V_50 , & V_34 -> V_171 ) ;
if ( F_32 ( V_24 != 0 ) ) {
F_3 ( L_23 ) ;
goto V_183;
}
F_83 ( & V_34 -> V_36 , 0 ) ;
V_24 = F_111 (
& V_34 -> V_29 , & V_184 , F_112 () , L_24 ) ;
if ( F_32 ( V_24 != 0 ) )
F_105 ( & V_34 -> V_29 ) ;
return V_24 ;
V_183:
F_102 ( V_34 -> V_71 ) ;
V_180:
F_15 ( V_34 ) ;
return V_24 ;
}
int F_113 ( struct V_6 * V_7 )
{
int V_24 = 0 ;
unsigned V_3 = V_163 ;
struct V_8 * V_9 ;
struct V_33 * V_34 = V_7 -> V_34 ;
while ( V_3 -- ) {
V_9 = & V_7 -> V_9 [ V_3 ] ;
if ( V_9 -> V_10 ) {
V_9 -> V_11 = false ;
if ( ( V_3 != V_16 ) && F_96 ( V_7 , V_3 ) ) {
V_24 = - V_128 ;
F_3 ( L_25 ,
V_3 ) ;
}
V_9 -> V_10 = false ;
}
}
F_114 ( & V_34 -> V_177 ) ;
F_115 ( & V_7 -> V_181 ) ;
F_116 ( & V_34 -> V_177 ) ;
F_65 ( & V_7 -> V_102 ) ;
while ( F_52 ( V_7 , true ) )
;
F_28 ( & V_34 -> V_59 ) ;
if ( F_11 ( & V_7 -> V_45 ) )
F_117 ( L_26 ) ;
if ( F_11 ( & V_7 -> V_9 [ 0 ] . V_44 ) )
F_117 ( L_27 ) ;
F_29 ( & V_34 -> V_59 ) ;
F_10 ( ! F_118 ( & V_7 -> V_185 ) ) ;
F_57 ( & V_7 -> V_113 ) ;
F_119 ( & V_7 -> V_185 ) ;
F_61 ( & V_7 -> V_113 ) ;
return V_24 ;
}
int F_120 ( struct V_6 * V_7 ,
struct V_33 * V_34 ,
struct V_97 * V_68 ,
T_4 V_186 ,
bool V_63 )
{
int V_24 = - V_5 ;
F_121 ( & V_7 -> V_113 ) ;
V_7 -> V_68 = V_68 ;
memset ( V_7 -> V_9 , 0 , sizeof( V_7 -> V_9 ) ) ;
V_24 = F_98 ( V_7 , V_16 , 0 ) ;
if ( F_32 ( V_24 != 0 ) )
goto V_187;
V_7 -> V_116 = V_188 ;
F_122 ( & V_7 -> V_185 , V_186 , 0x10000000 ) ;
F_123 ( & V_7 -> V_102 , F_55 ) ;
F_84 ( & V_7 -> V_45 ) ;
V_7 -> V_189 = NULL ;
V_7 -> V_34 = V_34 ;
V_7 -> V_63 = V_63 ;
V_7 -> V_190 = 0 ;
F_107 ( & V_7 -> V_98 ) ;
F_114 ( & V_34 -> V_177 ) ;
F_19 ( & V_7 -> V_181 , & V_34 -> V_181 ) ;
F_116 ( & V_34 -> V_177 ) ;
return 0 ;
V_187:
return V_24 ;
}
bool F_34 ( struct V_6 * V_7 , struct V_76 * V_25 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_25 -> V_2 ] ;
if ( ! ( V_9 -> V_1 & V_86 ) ) {
if ( V_25 -> V_2 == V_16 )
return false ;
if ( V_9 -> V_1 & V_191 )
return false ;
if ( V_25 -> V_23 & V_134 )
return false ;
}
return true ;
}
void F_36 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
T_5 V_94 = ( T_5 ) V_21 -> V_192 ;
T_5 V_193 = ( ( T_5 ) V_21 -> V_25 . V_26 ) << V_70 ;
if ( ! V_7 -> V_189 )
return;
F_124 ( V_7 -> V_189 , V_94 , V_193 , 1 ) ;
F_62 ( V_21 ) ;
}
void F_125 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
F_35 ( V_9 , false ) ;
F_36 ( V_21 ) ;
F_37 ( V_9 ) ;
}
static void F_126 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_194 * * V_195 = & V_7 -> V_116 . V_194 ;
struct V_194 * V_196 = NULL ;
struct V_20 * V_197 ;
unsigned long V_94 = V_21 -> V_114 -> V_95 ;
unsigned long V_198 ;
while ( * V_195 ) {
V_196 = * V_195 ;
V_197 = F_127 ( V_196 , struct V_20 , V_115 ) ;
V_198 = V_197 -> V_114 -> V_95 ;
if ( V_94 < V_198 )
V_195 = & V_196 -> V_199 ;
else if ( V_94 > V_198 )
V_195 = & V_196 -> V_200 ;
else
F_24 () ;
}
F_128 ( & V_21 -> V_115 , V_196 , V_195 ) ;
F_129 ( & V_21 -> V_115 , & V_7 -> V_116 ) ;
}
static int F_87 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
int V_24 ;
V_201:
V_24 = F_130 ( & V_7 -> V_185 ) ;
if ( F_32 ( V_24 != 0 ) )
return V_24 ;
F_57 ( & V_7 -> V_113 ) ;
V_21 -> V_114 = F_131 ( & V_7 -> V_185 ,
V_21 -> V_25 . V_26 , 0 , 0 ) ;
if ( F_32 ( V_21 -> V_114 == NULL ) ) {
V_24 = - V_72 ;
goto V_107;
}
V_21 -> V_114 = F_132 ( V_21 -> V_114 ,
V_21 -> V_25 . V_26 , 0 ) ;
if ( F_32 ( V_21 -> V_114 == NULL ) ) {
F_61 ( & V_7 -> V_113 ) ;
goto V_201;
}
F_126 ( V_21 ) ;
F_61 ( & V_7 -> V_113 ) ;
V_21 -> V_192 = ( ( T_4 ) V_21 -> V_114 -> V_95 ) << V_70 ;
return 0 ;
V_107:
F_61 ( & V_7 -> V_113 ) ;
return V_24 ;
}
int F_48 ( struct V_20 * V_21 ,
bool V_202 , bool V_78 , bool V_203 )
{
struct V_97 * V_68 = V_21 -> V_7 -> V_68 ;
struct V_6 * V_7 = V_21 -> V_7 ;
void * V_42 ;
int V_24 = 0 ;
if ( F_58 ( V_21 -> V_42 == NULL ) )
return 0 ;
while ( V_21 -> V_42 ) {
if ( V_68 -> V_204 ( V_21 -> V_42 ) ) {
void * V_205 = V_21 -> V_42 ;
V_21 -> V_42 = NULL ;
F_133 ( V_206 , & V_21 -> V_153 ) ;
F_29 ( & V_7 -> V_98 ) ;
V_68 -> V_101 ( & V_205 ) ;
F_28 ( & V_7 -> V_98 ) ;
continue;
}
if ( V_203 )
return - V_128 ;
V_42 = V_68 -> V_99 ( V_21 -> V_42 ) ;
F_29 ( & V_7 -> V_98 ) ;
V_24 = V_68 -> V_104 ( V_42 ,
V_202 , V_78 ) ;
if ( F_32 ( V_24 != 0 ) ) {
V_68 -> V_101 ( & V_42 ) ;
F_28 ( & V_7 -> V_98 ) ;
return V_24 ;
}
F_28 ( & V_7 -> V_98 ) ;
if ( F_58 ( V_21 -> V_42 == V_42 ) ) {
void * V_205 = V_21 -> V_42 ;
V_21 -> V_42 = NULL ;
F_133 ( V_206 ,
& V_21 -> V_153 ) ;
F_29 ( & V_7 -> V_98 ) ;
V_68 -> V_101 ( & V_42 ) ;
V_68 -> V_101 ( & V_205 ) ;
F_28 ( & V_7 -> V_98 ) ;
} else {
F_29 ( & V_7 -> V_98 ) ;
V_68 -> V_101 ( & V_42 ) ;
F_28 ( & V_7 -> V_98 ) ;
}
}
return 0 ;
}
int F_134 ( struct V_20 * V_21 , bool V_203 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
int V_24 = 0 ;
V_24 = F_135 ( V_21 , true , V_203 , false , 0 ) ;
if ( F_32 ( V_24 != 0 ) )
return V_24 ;
F_28 ( & V_7 -> V_98 ) ;
V_24 = F_48 ( V_21 , false , true , V_203 ) ;
F_29 ( & V_7 -> V_98 ) ;
if ( F_58 ( V_24 == 0 ) )
F_86 ( & V_21 -> V_41 ) ;
F_71 ( V_21 ) ;
return V_24 ;
}
void F_136 ( struct V_20 * V_21 )
{
F_13 ( & V_21 -> V_41 ) ;
}
static int V_182 ( struct V_207 * V_171 )
{
struct V_33 * V_34 =
F_6 ( V_171 , struct V_33 , V_171 ) ;
struct V_20 * V_21 ;
int V_24 = - V_128 ;
int V_56 ;
T_1 V_208 = ( V_134 | V_154 ) ;
F_28 ( & V_34 -> V_59 ) ;
F_70 (bo, &glob->swap_lru, swap) {
V_24 = F_47 ( V_21 , false , true , false , 0 ) ;
if ( ! V_24 )
break;
}
if ( V_24 ) {
F_29 ( & V_34 -> V_59 ) ;
return V_24 ;
}
F_20 ( & V_21 -> V_38 ) ;
if ( ! F_11 ( & V_21 -> V_45 ) ) {
V_24 = F_50 ( V_21 , false , false ) ;
F_54 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
V_56 = F_21 ( V_21 ) ;
F_29 ( & V_34 -> V_59 ) ;
F_25 ( V_21 , V_56 , true ) ;
F_28 ( & V_21 -> V_7 -> V_98 ) ;
V_24 = F_48 ( V_21 , false , false , false ) ;
F_29 ( & V_21 -> V_7 -> V_98 ) ;
if ( F_32 ( V_24 != 0 ) )
goto V_110;
if ( ( V_21 -> V_25 . V_23 & V_208 ) != V_208 ) {
struct V_76 V_119 ;
V_119 = V_21 -> V_25 ;
V_119 . V_43 = NULL ;
V_119 . V_23 = V_154 | V_134 ;
V_119 . V_2 = V_16 ;
V_24 = F_33 ( V_21 , & V_119 , true ,
false , false ) ;
if ( F_32 ( V_24 != 0 ) )
goto V_110;
}
F_125 ( V_21 ) ;
if ( V_21 -> V_7 -> V_68 -> V_209 )
V_21 -> V_7 -> V_68 -> V_209 ( V_21 ) ;
V_24 = F_137 ( V_21 -> V_46 , V_21 -> V_148 ) ;
V_110:
F_45 ( & V_21 -> V_47 -> V_51 ) ;
F_54 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
void F_138 ( struct V_6 * V_7 )
{
while ( V_182 ( & V_7 -> V_34 -> V_171 ) == 0 )
;
}
