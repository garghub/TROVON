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
F_15 ( & V_21 -> V_49 ) ;
if ( V_21 -> V_50 )
V_21 -> V_50 ( V_21 ) ;
else {
F_16 ( V_21 ) ;
}
F_17 ( V_7 -> V_34 -> V_51 , V_39 ) ;
}
void F_18 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 ;
F_19 ( & V_21 -> V_47 -> V_52 . V_53 ) ;
if ( ! ( V_21 -> V_25 . V_23 & V_54 ) ) {
F_10 ( ! F_11 ( & V_21 -> V_44 ) ) ;
V_9 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
F_20 ( & V_21 -> V_44 , & V_9 -> V_44 ) ;
F_21 ( & V_21 -> V_38 ) ;
if ( V_21 -> V_46 != NULL ) {
F_20 ( & V_21 -> V_55 , & V_21 -> V_34 -> V_56 ) ;
F_21 ( & V_21 -> V_38 ) ;
}
}
}
int F_22 ( struct V_20 * V_21 )
{
int V_57 = 0 ;
if ( ! F_11 ( & V_21 -> V_55 ) ) {
F_23 ( & V_21 -> V_55 ) ;
++ V_57 ;
}
if ( ! F_11 ( & V_21 -> V_44 ) ) {
F_23 ( & V_21 -> V_44 ) ;
++ V_57 ;
}
return V_57 ;
}
static void F_24 ( struct V_37 * V_38 )
{
F_25 () ;
}
void F_26 ( struct V_20 * V_21 , int V_58 ,
bool V_59 )
{
F_27 ( & V_21 -> V_38 , V_58 ,
( V_59 ) ? F_24 : F_9 ) ;
}
void F_28 ( struct V_20 * V_21 )
{
int V_57 ;
F_29 ( & V_21 -> V_34 -> V_60 ) ;
V_57 = F_22 ( V_21 ) ;
F_30 ( & V_21 -> V_34 -> V_60 ) ;
F_26 ( V_21 , V_57 , true ) ;
}
static int F_31 ( struct V_20 * V_21 , bool V_61 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_33 * V_34 = V_21 -> V_34 ;
int V_24 = 0 ;
T_1 V_62 = 0 ;
F_32 ( & V_21 -> V_63 ) ;
V_21 -> V_46 = NULL ;
if ( V_7 -> V_64 )
V_62 |= V_65 ;
switch ( V_21 -> type ) {
case V_66 :
if ( V_61 )
V_62 |= V_67 ;
case V_68 :
V_21 -> V_46 = V_7 -> V_69 -> V_70 ( V_7 , V_21 -> V_26 << V_71 ,
V_62 , V_34 -> V_72 ) ;
if ( F_33 ( V_21 -> V_46 == NULL ) )
V_24 = - V_73 ;
break;
case V_74 :
V_21 -> V_46 = V_7 -> V_69 -> V_70 ( V_7 , V_21 -> V_26 << V_71 ,
V_62 | V_75 ,
V_34 -> V_72 ) ;
if ( F_33 ( V_21 -> V_46 == NULL ) ) {
V_24 = - V_73 ;
break;
}
V_21 -> V_46 -> V_76 = V_21 -> V_76 ;
break;
default:
F_3 ( L_11 ) ;
V_24 = - V_5 ;
break;
}
return V_24 ;
}
static int F_34 ( struct V_20 * V_21 ,
struct V_77 * V_25 ,
bool V_78 , bool V_79 ,
bool V_80 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
bool V_81 = F_35 ( V_7 , & V_21 -> V_25 ) ;
bool V_82 = F_35 ( V_7 , V_25 ) ;
struct V_8 * V_83 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
struct V_8 * V_84 = & V_7 -> V_9 [ V_25 -> V_2 ] ;
int V_24 = 0 ;
if ( V_81 || V_82 ||
( ( V_25 -> V_23 & V_21 -> V_25 . V_23 & V_85 ) == 0 ) ) {
V_24 = F_36 ( V_83 , true ) ;
if ( F_33 ( V_24 != 0 ) )
goto V_86;
F_37 ( V_21 ) ;
F_38 ( V_83 ) ;
}
if ( ! ( V_84 -> V_1 & V_87 ) ) {
if ( V_21 -> V_46 == NULL ) {
bool V_88 = ! ( V_83 -> V_1 & V_87 ) ;
V_24 = F_31 ( V_21 , V_88 ) ;
if ( V_24 )
goto V_86;
}
V_24 = F_39 ( V_21 -> V_46 , V_25 -> V_23 ) ;
if ( V_24 )
goto V_86;
if ( V_25 -> V_2 != V_16 ) {
V_24 = F_40 ( V_21 -> V_46 , V_25 ) ;
if ( V_24 )
goto V_86;
}
if ( V_21 -> V_25 . V_2 == V_16 ) {
if ( V_7 -> V_69 -> V_89 )
V_7 -> V_69 -> V_89 ( V_21 , V_25 ) ;
V_21 -> V_25 = * V_25 ;
V_25 -> V_43 = NULL ;
goto V_90;
}
}
if ( V_7 -> V_69 -> V_89 )
V_7 -> V_69 -> V_89 ( V_21 , V_25 ) ;
if ( ! ( V_83 -> V_1 & V_87 ) &&
! ( V_84 -> V_1 & V_87 ) )
V_24 = F_41 ( V_21 , V_78 , V_80 , V_25 ) ;
else if ( V_7 -> V_69 -> V_91 )
V_24 = V_7 -> V_69 -> V_91 ( V_21 , V_78 , V_79 ,
V_80 , V_25 ) ;
else
V_24 = F_42 ( V_21 , V_78 , V_80 , V_25 ) ;
if ( V_24 ) {
if ( V_7 -> V_69 -> V_89 ) {
struct V_77 V_92 = * V_25 ;
* V_25 = V_21 -> V_25 ;
V_21 -> V_25 = V_92 ;
V_7 -> V_69 -> V_89 ( V_21 , V_25 ) ;
V_21 -> V_25 = * V_25 ;
* V_25 = V_92 ;
}
goto V_86;
}
V_90:
if ( V_21 -> V_93 ) {
V_24 = V_7 -> V_69 -> V_94 ( V_7 , V_21 -> V_25 . V_23 ) ;
if ( V_24 )
F_3 ( L_12 ) ;
V_21 -> V_93 = false ;
}
if ( V_21 -> V_25 . V_43 ) {
V_21 -> V_95 = ( V_21 -> V_25 . V_96 << V_71 ) +
V_7 -> V_9 [ V_21 -> V_25 . V_2 ] . V_12 ;
V_21 -> V_97 = V_21 -> V_25 . V_23 ;
} else
V_21 -> V_95 = 0 ;
return 0 ;
V_86:
V_84 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
if ( ( V_84 -> V_1 & V_87 ) && V_21 -> V_46 ) {
F_43 ( V_21 -> V_46 ) ;
F_12 ( V_21 -> V_46 ) ;
V_21 -> V_46 = NULL ;
}
return V_24 ;
}
static void F_44 ( struct V_20 * V_21 )
{
if ( V_21 -> V_7 -> V_69 -> V_89 )
V_21 -> V_7 -> V_69 -> V_89 ( V_21 , NULL ) ;
if ( V_21 -> V_46 ) {
F_43 ( V_21 -> V_46 ) ;
F_12 ( V_21 -> V_46 ) ;
V_21 -> V_46 = NULL ;
}
F_45 ( V_21 , & V_21 -> V_25 ) ;
F_46 ( & V_21 -> V_47 -> V_52 ) ;
}
static void F_47 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_33 * V_34 = V_21 -> V_34 ;
struct V_98 * V_69 = V_7 -> V_69 ;
void * V_42 = NULL ;
int V_57 ;
int V_24 ;
F_29 ( & V_34 -> V_60 ) ;
V_24 = F_48 ( V_21 , false , true , false , 0 ) ;
F_29 ( & V_7 -> V_99 ) ;
( void ) F_49 ( V_21 , false , false , true ) ;
if ( ! V_24 && ! V_21 -> V_42 ) {
F_30 ( & V_7 -> V_99 ) ;
V_57 = F_22 ( V_21 ) ;
F_30 ( & V_34 -> V_60 ) ;
F_44 ( V_21 ) ;
F_26 ( V_21 , V_57 , true ) ;
return;
}
if ( V_21 -> V_42 )
V_42 = V_69 -> V_100 ( V_21 -> V_42 ) ;
F_30 ( & V_7 -> V_99 ) ;
if ( ! V_24 ) {
if ( V_21 -> V_25 . V_23 & V_54 ) {
V_21 -> V_25 . V_23 &= ~ V_54 ;
F_18 ( V_21 ) ;
}
F_46 ( & V_21 -> V_47 -> V_52 ) ;
}
F_21 ( & V_21 -> V_38 ) ;
F_20 ( & V_21 -> V_45 , & V_7 -> V_45 ) ;
F_30 ( & V_34 -> V_60 ) ;
if ( V_42 ) {
V_69 -> V_101 ( V_42 ) ;
V_69 -> V_102 ( & V_42 ) ;
}
F_50 ( & V_7 -> V_103 ,
( ( V_104 / 100 ) < 1 ) ? 1 : V_104 / 100 ) ;
}
static int F_51 ( struct V_20 * V_21 ,
bool V_79 ,
bool V_80 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_98 * V_69 = V_7 -> V_69 ;
struct V_33 * V_34 = V_21 -> V_34 ;
int V_57 ;
int V_24 ;
F_29 ( & V_7 -> V_99 ) ;
V_24 = F_49 ( V_21 , false , false , true ) ;
if ( V_24 && ! V_80 ) {
void * V_42 ;
V_42 = V_69 -> V_100 ( V_21 -> V_42 ) ;
F_30 ( & V_7 -> V_99 ) ;
F_46 ( & V_21 -> V_47 -> V_52 ) ;
F_30 ( & V_34 -> V_60 ) ;
V_24 = V_69 -> V_105 ( V_42 , false , V_79 ) ;
V_69 -> V_102 ( & V_42 ) ;
if ( V_24 )
return V_24 ;
F_29 ( & V_7 -> V_99 ) ;
V_24 = F_49 ( V_21 , false , false , true ) ;
F_52 ( V_24 ) ;
F_30 ( & V_7 -> V_99 ) ;
if ( V_24 )
return V_24 ;
F_29 ( & V_34 -> V_60 ) ;
V_24 = F_48 ( V_21 , false , true , false , 0 ) ;
if ( V_24 ) {
F_30 ( & V_34 -> V_60 ) ;
return 0 ;
}
} else
F_30 ( & V_7 -> V_99 ) ;
if ( V_24 || F_33 ( F_11 ( & V_21 -> V_45 ) ) ) {
F_46 ( & V_21 -> V_47 -> V_52 ) ;
F_30 ( & V_34 -> V_60 ) ;
return V_24 ;
}
V_57 = F_22 ( V_21 ) ;
F_23 ( & V_21 -> V_45 ) ;
++ V_57 ;
F_30 ( & V_34 -> V_60 ) ;
F_44 ( V_21 ) ;
F_26 ( V_21 , V_57 , true ) ;
return 0 ;
}
static int F_53 ( struct V_6 * V_7 , bool V_106 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
struct V_20 * V_107 = NULL ;
int V_24 = 0 ;
F_29 ( & V_34 -> V_60 ) ;
if ( F_11 ( & V_7 -> V_45 ) )
goto V_108;
V_107 = F_54 ( & V_7 -> V_45 ,
struct V_20 , V_45 ) ;
F_21 ( & V_107 -> V_38 ) ;
for (; ; ) {
struct V_20 * V_109 = NULL ;
if ( V_107 -> V_45 . V_110 != & V_7 -> V_45 ) {
V_109 = F_54 ( & V_107 -> V_45 ,
struct V_20 , V_45 ) ;
F_21 ( & V_109 -> V_38 ) ;
}
V_24 = F_48 ( V_107 , false , true , false , 0 ) ;
if ( V_106 && V_24 ) {
F_30 ( & V_34 -> V_60 ) ;
V_24 = F_48 ( V_107 , false , false ,
false , 0 ) ;
F_29 ( & V_34 -> V_60 ) ;
}
if ( ! V_24 )
V_24 = F_51 ( V_107 , false ,
! V_106 ) ;
else
F_30 ( & V_34 -> V_60 ) ;
F_55 ( & V_107 -> V_38 , F_9 ) ;
V_107 = V_109 ;
if ( V_24 || ! V_107 )
goto V_111;
F_29 ( & V_34 -> V_60 ) ;
if ( F_11 ( & V_107 -> V_45 ) )
break;
}
V_108:
F_30 ( & V_34 -> V_60 ) ;
V_111:
if ( V_107 )
F_55 ( & V_107 -> V_38 , F_9 ) ;
return V_24 ;
}
static void F_56 ( struct V_112 * V_113 )
{
struct V_6 * V_7 =
F_6 ( V_113 , struct V_6 , V_103 . V_113 ) ;
if ( F_53 ( V_7 , false ) ) {
F_50 ( & V_7 -> V_103 ,
( ( V_104 / 100 ) < 1 ) ? 1 : V_104 / 100 ) ;
}
}
static void F_57 ( struct V_37 * V_37 )
{
struct V_20 * V_21 =
F_6 ( V_37 , struct V_20 , V_37 ) ;
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
F_58 ( & V_7 -> V_114 , & V_21 -> V_115 ) ;
F_36 ( V_9 , false ) ;
F_59 ( V_21 ) ;
F_38 ( V_9 ) ;
F_47 ( V_21 ) ;
F_55 ( & V_21 -> V_38 , F_9 ) ;
}
void F_60 ( struct V_20 * * V_116 )
{
struct V_20 * V_21 = * V_116 ;
* V_116 = NULL ;
F_55 ( & V_21 -> V_37 , F_57 ) ;
}
int F_61 ( struct V_6 * V_7 )
{
return F_62 ( & V_7 -> V_103 ) ;
}
void F_63 ( struct V_6 * V_7 , int V_117 )
{
if ( V_117 )
F_50 ( & V_7 -> V_103 ,
( ( V_104 / 100 ) < 1 ) ? 1 : V_104 / 100 ) ;
}
static int F_64 ( struct V_20 * V_21 , bool V_79 ,
bool V_80 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_77 V_118 ;
struct V_22 V_23 ;
int V_24 = 0 ;
F_29 ( & V_7 -> V_99 ) ;
V_24 = F_49 ( V_21 , false , V_79 , V_80 ) ;
F_30 ( & V_7 -> V_99 ) ;
if ( F_33 ( V_24 != 0 ) ) {
if ( V_24 != - V_119 ) {
F_3 ( L_13 ) ;
}
goto V_111;
}
F_19 ( & V_21 -> V_47 -> V_52 . V_53 ) ;
V_118 = V_21 -> V_25 ;
V_118 . V_43 = NULL ;
V_118 . V_120 . V_121 = false ;
V_118 . V_120 . V_122 = 0 ;
V_23 . V_123 = 0 ;
V_23 . V_124 = 0 ;
V_23 . V_27 = 0 ;
V_23 . V_125 = 0 ;
V_7 -> V_69 -> V_126 ( V_21 , & V_23 ) ;
V_24 = F_65 ( V_21 , & V_23 , & V_118 , V_79 ,
V_80 ) ;
if ( V_24 ) {
if ( V_24 != - V_119 ) {
F_3 ( L_14 ,
V_21 ) ;
F_4 ( V_21 , & V_23 ) ;
}
goto V_111;
}
V_24 = F_34 ( V_21 , & V_118 , true , V_79 ,
V_80 ) ;
if ( V_24 ) {
if ( V_24 != - V_119 )
F_3 ( L_15 ) ;
F_45 ( V_21 , & V_118 ) ;
goto V_111;
}
V_21 -> V_93 = true ;
V_111:
return V_24 ;
}
static int F_66 ( struct V_6 * V_7 ,
T_1 V_2 ,
bool V_79 ,
bool V_80 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
struct V_20 * V_21 ;
int V_24 = - V_127 , V_57 ;
F_29 ( & V_34 -> V_60 ) ;
F_67 (bo, &man->lru, lru) {
V_24 = F_48 ( V_21 , false , true , false , 0 ) ;
if ( ! V_24 )
break;
}
if ( V_24 ) {
F_30 ( & V_34 -> V_60 ) ;
return V_24 ;
}
F_21 ( & V_21 -> V_38 ) ;
if ( ! F_11 ( & V_21 -> V_45 ) ) {
V_24 = F_51 ( V_21 , V_79 ,
V_80 ) ;
F_55 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
V_57 = F_22 ( V_21 ) ;
F_30 ( & V_34 -> V_60 ) ;
F_10 ( V_24 != 0 ) ;
F_26 ( V_21 , V_57 , true ) ;
V_24 = F_64 ( V_21 , V_79 , V_80 ) ;
F_68 ( V_21 ) ;
F_55 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
void F_45 ( struct V_20 * V_21 , struct V_77 * V_25 )
{
struct V_8 * V_9 = & V_21 -> V_7 -> V_9 [ V_25 -> V_2 ] ;
if ( V_25 -> V_43 )
(* V_9 -> V_17 -> V_128 )( V_9 , V_25 ) ;
}
static int F_69 ( struct V_20 * V_21 ,
T_1 V_2 ,
struct V_22 * V_23 ,
struct V_77 * V_25 ,
bool V_79 ,
bool V_80 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
int V_24 ;
do {
V_24 = (* V_9 -> V_17 -> V_129 )( V_9 , V_21 , V_23 , V_25 ) ;
if ( F_33 ( V_24 != 0 ) )
return V_24 ;
if ( V_25 -> V_43 )
break;
V_24 = F_66 ( V_7 , V_2 ,
V_79 , V_80 ) ;
if ( F_33 ( V_24 != 0 ) )
return V_24 ;
} while ( 1 );
if ( V_25 -> V_43 == NULL )
return - V_73 ;
V_25 -> V_2 = V_2 ;
return 0 ;
}
static T_1 F_70 ( struct V_8 * V_9 ,
T_1 V_97 ,
T_1 V_130 )
{
T_1 V_131 = V_130 & V_85 ;
T_1 V_132 = V_130 & ~ V_85 ;
if ( ( V_97 & V_131 ) != 0 )
V_132 |= ( V_97 & V_131 ) ;
else if ( ( V_9 -> V_15 & V_131 ) != 0 )
V_132 |= V_9 -> V_15 ;
else if ( ( V_133 & V_131 ) != 0 )
V_132 |= V_133 ;
else if ( ( V_134 & V_131 ) != 0 )
V_132 |= V_134 ;
else if ( ( V_135 & V_131 ) != 0 )
V_132 |= V_135 ;
return V_132 ;
}
static bool F_71 ( struct V_8 * V_9 ,
T_1 V_2 ,
T_1 V_130 ,
T_1 * V_136 )
{
T_1 V_137 = F_8 ( V_2 ) ;
if ( ( V_137 & V_130 & V_138 ) == 0 )
return false ;
if ( ( V_130 & V_9 -> V_14 ) == 0 )
return false ;
V_137 |= ( V_130 & V_9 -> V_14 ) ;
* V_136 = V_137 ;
return true ;
}
int F_65 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_77 * V_25 ,
bool V_79 ,
bool V_80 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 ;
T_1 V_2 = V_16 ;
T_1 V_137 = 0 ;
bool V_139 = false ;
bool V_140 = false ;
bool V_141 = false ;
int V_3 , V_24 ;
V_25 -> V_43 = NULL ;
for ( V_3 = 0 ; V_3 < V_23 -> V_27 ; ++ V_3 ) {
V_24 = F_1 ( V_23 -> V_23 [ V_3 ] ,
& V_2 ) ;
if ( V_24 )
return V_24 ;
V_9 = & V_7 -> V_9 [ V_2 ] ;
V_140 = F_71 ( V_9 ,
V_2 ,
V_23 -> V_23 [ V_3 ] ,
& V_137 ) ;
if ( ! V_140 )
continue;
V_137 = F_70 ( V_9 , V_21 -> V_25 . V_23 ,
V_137 ) ;
F_72 ( & V_137 , V_23 -> V_23 [ V_3 ] ,
~ V_142 ) ;
if ( V_2 == V_16 )
break;
if ( V_9 -> V_10 && V_9 -> V_11 ) {
V_139 = true ;
V_24 = (* V_9 -> V_17 -> V_129 )( V_9 , V_21 , V_23 , V_25 ) ;
if ( F_33 ( V_24 ) )
return V_24 ;
}
if ( V_25 -> V_43 )
break;
}
if ( ( V_140 && ( V_2 == V_16 ) ) || V_25 -> V_43 ) {
V_25 -> V_2 = V_2 ;
V_25 -> V_23 = V_137 ;
return 0 ;
}
if ( ! V_139 )
return - V_5 ;
for ( V_3 = 0 ; V_3 < V_23 -> V_125 ; ++ V_3 ) {
V_24 = F_1 ( V_23 -> V_143 [ V_3 ] ,
& V_2 ) ;
if ( V_24 )
return V_24 ;
V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( ! V_9 -> V_10 )
continue;
if ( ! F_71 ( V_9 ,
V_2 ,
V_23 -> V_143 [ V_3 ] ,
& V_137 ) )
continue;
V_137 = F_70 ( V_9 , V_21 -> V_25 . V_23 ,
V_137 ) ;
F_72 ( & V_137 , V_23 -> V_143 [ V_3 ] ,
~ V_142 ) ;
if ( V_2 == V_16 ) {
V_25 -> V_2 = V_2 ;
V_25 -> V_23 = V_137 ;
V_25 -> V_43 = NULL ;
return 0 ;
}
V_24 = F_69 ( V_21 , V_2 , V_23 , V_25 ,
V_79 , V_80 ) ;
if ( V_24 == 0 && V_25 -> V_43 ) {
V_25 -> V_23 = V_137 ;
return 0 ;
}
if ( V_24 == - V_119 )
V_141 = true ;
}
V_24 = ( V_141 ) ? - V_119 : - V_73 ;
return V_24 ;
}
int F_73 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
bool V_79 ,
bool V_80 )
{
int V_24 = 0 ;
struct V_77 V_25 ;
struct V_6 * V_7 = V_21 -> V_7 ;
F_19 ( & V_21 -> V_47 -> V_52 . V_53 ) ;
F_29 ( & V_7 -> V_99 ) ;
V_24 = F_49 ( V_21 , false , V_79 , V_80 ) ;
F_30 ( & V_7 -> V_99 ) ;
if ( V_24 )
return V_24 ;
V_25 . V_26 = V_21 -> V_26 ;
V_25 . V_13 = V_25 . V_26 << V_71 ;
V_25 . V_144 = V_21 -> V_25 . V_144 ;
V_25 . V_120 . V_121 = false ;
V_25 . V_120 . V_122 = 0 ;
V_24 = F_65 ( V_21 , V_23 , & V_25 ,
V_79 , V_80 ) ;
if ( V_24 )
goto V_108;
V_24 = F_34 ( V_21 , & V_25 , false ,
V_79 , V_80 ) ;
V_108:
if ( V_24 && V_25 . V_43 )
F_45 ( V_21 , & V_25 ) ;
return V_24 ;
}
static bool F_74 ( struct V_22 * V_23 ,
struct V_77 * V_25 ,
T_1 * V_145 )
{
int V_3 ;
if ( V_25 -> V_43 && V_23 -> V_124 != 0 &&
( V_25 -> V_96 < V_23 -> V_123 ||
V_25 -> V_96 + V_25 -> V_26 > V_23 -> V_124 ) )
return false ;
for ( V_3 = 0 ; V_3 < V_23 -> V_27 ; V_3 ++ ) {
* V_145 = V_23 -> V_23 [ V_3 ] ;
if ( ( * V_145 & V_25 -> V_23 & V_85 ) &&
( * V_145 & V_25 -> V_23 & V_138 ) )
return true ;
}
for ( V_3 = 0 ; V_3 < V_23 -> V_125 ; V_3 ++ ) {
* V_145 = V_23 -> V_143 [ V_3 ] ;
if ( ( * V_145 & V_25 -> V_23 & V_85 ) &&
( * V_145 & V_25 -> V_23 & V_138 ) )
return true ;
}
return false ;
}
int F_75 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
bool V_79 ,
bool V_80 )
{
int V_24 ;
T_1 V_145 ;
F_19 ( & V_21 -> V_47 -> V_52 . V_53 ) ;
if ( V_23 -> V_124 || V_23 -> V_123 )
if ( V_23 -> V_123 > V_23 -> V_124 ||
( V_23 -> V_124 - V_23 -> V_123 ) < V_21 -> V_26 )
return - V_5 ;
if ( ! F_74 ( V_23 , & V_21 -> V_25 , & V_145 ) ) {
V_24 = F_73 ( V_21 , V_23 , V_79 ,
V_80 ) ;
if ( V_24 )
return V_24 ;
} else {
F_72 ( & V_21 -> V_25 . V_23 , V_145 ,
~ V_142 ) ;
}
if ( V_21 -> V_25 . V_2 == V_16 && V_21 -> V_46 == NULL ) {
V_24 = F_31 ( V_21 , true ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
int F_76 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
F_10 ( ( V_23 -> V_123 || V_23 -> V_124 ) &&
( V_21 -> V_25 . V_26 > ( V_23 -> V_124 - V_23 -> V_123 ) ) ) ;
return 0 ;
}
int F_77 ( struct V_6 * V_7 ,
struct V_20 * V_21 ,
unsigned long V_13 ,
enum V_146 type ,
struct V_22 * V_23 ,
T_1 V_144 ,
bool V_79 ,
struct V_147 * V_148 ,
T_3 V_39 ,
struct V_149 * V_76 ,
void (* V_50) ( struct V_20 * ) )
{
int V_24 = 0 ;
unsigned long V_26 ;
struct V_150 * V_51 = V_7 -> V_34 -> V_51 ;
bool V_151 ;
V_24 = F_78 ( V_51 , V_39 , false , false ) ;
if ( V_24 ) {
F_3 ( L_16 ) ;
if ( V_50 )
(* V_50)( V_21 ) ;
else
F_16 ( V_21 ) ;
return - V_73 ;
}
V_26 = ( V_13 + V_35 - 1 ) >> V_71 ;
if ( V_26 == 0 ) {
F_3 ( L_17 ) ;
if ( V_50 )
(* V_50)( V_21 ) ;
else
F_16 ( V_21 ) ;
F_17 ( V_51 , V_39 ) ;
return - V_5 ;
}
V_21 -> V_50 = V_50 ;
F_79 ( & V_21 -> V_37 ) ;
F_79 ( & V_21 -> V_38 ) ;
F_80 ( & V_21 -> V_41 , 0 ) ;
F_81 ( & V_21 -> V_44 ) ;
F_81 ( & V_21 -> V_45 ) ;
F_81 ( & V_21 -> V_55 ) ;
F_81 ( & V_21 -> V_152 ) ;
F_82 ( & V_21 -> V_49 ) ;
V_21 -> V_7 = V_7 ;
V_21 -> V_34 = V_7 -> V_34 ;
V_21 -> type = type ;
V_21 -> V_26 = V_26 ;
V_21 -> V_25 . V_13 = V_26 << V_71 ;
V_21 -> V_25 . V_2 = V_16 ;
V_21 -> V_25 . V_26 = V_21 -> V_26 ;
V_21 -> V_25 . V_43 = NULL ;
V_21 -> V_25 . V_144 = V_144 ;
V_21 -> V_25 . V_120 . V_121 = false ;
V_21 -> V_25 . V_120 . V_122 = 0 ;
V_21 -> V_153 = 0 ;
V_21 -> V_25 . V_23 = ( V_154 | V_133 ) ;
V_21 -> V_148 = V_148 ;
V_21 -> V_39 = V_39 ;
V_21 -> V_76 = V_76 ;
V_21 -> V_47 = & V_21 -> V_48 ;
F_83 ( V_21 -> V_47 ) ;
F_84 ( & V_21 -> V_34 -> V_36 ) ;
F_85 ( & V_21 -> V_115 ) ;
V_24 = F_76 ( V_21 , V_23 ) ;
if ( F_86 ( ! V_24 ) &&
( V_21 -> type == V_66 ||
V_21 -> type == V_74 ) )
V_24 = F_87 ( & V_7 -> V_114 , & V_21 -> V_115 ,
V_21 -> V_25 . V_26 ) ;
V_151 = F_88 ( & V_21 -> V_47 -> V_52 ) ;
F_52 ( ! V_151 ) ;
if ( F_86 ( ! V_24 ) )
V_24 = F_75 ( V_21 , V_23 , V_79 , false ) ;
F_68 ( V_21 ) ;
if ( F_33 ( V_24 ) )
F_60 ( & V_21 ) ;
return V_24 ;
}
T_3 F_89 ( struct V_6 * V_7 ,
unsigned long V_155 ,
unsigned V_156 )
{
unsigned V_157 = ( F_90 ( V_155 ) ) >> V_71 ;
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
unsigned V_157 = ( F_90 ( V_155 ) ) >> V_71 ;
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
T_1 V_144 ,
bool V_79 ,
struct V_147 * V_148 ,
struct V_20 * * V_116 )
{
struct V_20 * V_21 ;
T_3 V_39 ;
int V_24 ;
V_21 = F_94 ( sizeof( * V_21 ) , V_161 ) ;
if ( F_33 ( V_21 == NULL ) )
return - V_73 ;
V_39 = F_89 ( V_7 , V_13 , sizeof( struct V_20 ) ) ;
V_24 = F_77 ( V_7 , V_21 , V_13 , type , V_23 , V_144 ,
V_79 , V_148 , V_39 ,
NULL , NULL ) ;
if ( F_86 ( V_24 == 0 ) )
* V_116 = V_21 ;
return V_24 ;
}
static int F_95 ( struct V_6 * V_7 ,
unsigned V_2 , bool V_162 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
struct V_33 * V_34 = V_7 -> V_34 ;
int V_24 ;
F_29 ( & V_34 -> V_60 ) ;
while ( ! F_11 ( & V_9 -> V_44 ) ) {
F_30 ( & V_34 -> V_60 ) ;
V_24 = F_66 ( V_7 , V_2 , false , false ) ;
if ( V_24 ) {
if ( V_162 ) {
return V_24 ;
} else {
F_3 ( L_18 ) ;
}
}
F_29 ( & V_34 -> V_60 ) ;
}
F_30 ( & V_34 -> V_60 ) ;
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
F_82 ( & V_9 -> V_168 ) ;
F_81 ( & V_9 -> V_152 ) ;
V_24 = V_7 -> V_69 -> V_169 ( V_7 , type , V_9 ) ;
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
F_81 ( & V_9 -> V_44 ) ;
return 0 ;
}
static void F_99 ( struct V_28 * V_29 )
{
struct V_33 * V_34 =
F_6 ( V_29 , struct V_33 , V_29 ) ;
F_100 ( V_34 -> V_51 , & V_34 -> V_171 ) ;
F_101 ( V_34 -> V_72 ) ;
F_16 ( V_34 ) ;
}
void F_102 ( struct V_172 * V_173 )
{
struct V_33 * V_34 = V_173 -> V_174 ;
F_103 ( & V_34 -> V_29 ) ;
F_104 ( & V_34 -> V_29 ) ;
}
int F_105 ( struct V_172 * V_173 )
{
struct V_175 * V_176 =
F_6 ( V_173 , struct V_175 , V_173 ) ;
struct V_33 * V_34 = V_173 -> V_174 ;
int V_24 ;
F_82 ( & V_34 -> V_177 ) ;
F_106 ( & V_34 -> V_60 ) ;
V_34 -> V_51 = V_176 -> V_51 ;
V_34 -> V_72 = F_107 ( V_178 | V_179 ) ;
if ( F_33 ( V_34 -> V_72 == NULL ) ) {
V_24 = - V_73 ;
goto V_180;
}
F_81 ( & V_34 -> V_56 ) ;
F_81 ( & V_34 -> V_181 ) ;
F_108 ( & V_34 -> V_171 , V_182 ) ;
V_24 = F_109 ( V_34 -> V_51 , & V_34 -> V_171 ) ;
if ( F_33 ( V_24 != 0 ) ) {
F_3 ( L_23 ) ;
goto V_183;
}
F_80 ( & V_34 -> V_36 , 0 ) ;
V_24 = F_110 (
& V_34 -> V_29 , & V_184 , F_111 () , L_24 ) ;
if ( F_33 ( V_24 != 0 ) )
F_104 ( & V_34 -> V_29 ) ;
return V_24 ;
V_183:
F_101 ( V_34 -> V_72 ) ;
V_180:
F_16 ( V_34 ) ;
return V_24 ;
}
int F_112 ( struct V_6 * V_7 )
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
V_24 = - V_127 ;
F_3 ( L_25 ,
V_3 ) ;
}
V_9 -> V_10 = false ;
}
}
F_113 ( & V_34 -> V_177 ) ;
F_114 ( & V_7 -> V_181 ) ;
F_115 ( & V_34 -> V_177 ) ;
F_62 ( & V_7 -> V_103 ) ;
while ( F_53 ( V_7 , true ) )
;
F_29 ( & V_34 -> V_60 ) ;
if ( F_11 ( & V_7 -> V_45 ) )
F_116 ( L_26 ) ;
if ( F_11 ( & V_7 -> V_9 [ 0 ] . V_44 ) )
F_116 ( L_27 ) ;
F_30 ( & V_34 -> V_60 ) ;
F_117 ( & V_7 -> V_114 ) ;
return V_24 ;
}
int F_118 ( struct V_6 * V_7 ,
struct V_33 * V_34 ,
struct V_98 * V_69 ,
T_4 V_185 ,
bool V_64 )
{
int V_24 = - V_5 ;
V_7 -> V_69 = V_69 ;
memset ( V_7 -> V_9 , 0 , sizeof( V_7 -> V_9 ) ) ;
V_24 = F_98 ( V_7 , V_16 , 0 ) ;
if ( F_33 ( V_24 != 0 ) )
goto V_186;
F_119 ( & V_7 -> V_114 , V_185 ,
0x10000000 ) ;
F_120 ( & V_7 -> V_103 , F_56 ) ;
F_81 ( & V_7 -> V_45 ) ;
V_7 -> V_187 = NULL ;
V_7 -> V_34 = V_34 ;
V_7 -> V_64 = V_64 ;
V_7 -> V_188 = 0 ;
F_106 ( & V_7 -> V_99 ) ;
F_113 ( & V_34 -> V_177 ) ;
F_20 ( & V_7 -> V_181 , & V_34 -> V_181 ) ;
F_115 ( & V_34 -> V_177 ) ;
return 0 ;
V_186:
return V_24 ;
}
bool F_35 ( struct V_6 * V_7 , struct V_77 * V_25 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_25 -> V_2 ] ;
if ( ! ( V_9 -> V_1 & V_87 ) ) {
if ( V_25 -> V_2 == V_16 )
return false ;
if ( V_9 -> V_1 & V_189 )
return false ;
if ( V_25 -> V_23 & V_133 )
return false ;
}
return true ;
}
void F_37 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
F_121 ( & V_21 -> V_115 , V_7 -> V_187 ) ;
F_59 ( V_21 ) ;
}
void F_122 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
F_36 ( V_9 , false ) ;
F_37 ( V_21 ) ;
F_38 ( V_9 ) ;
}
int F_49 ( struct V_20 * V_21 ,
bool V_190 , bool V_79 , bool V_191 )
{
struct V_98 * V_69 = V_21 -> V_7 -> V_69 ;
struct V_6 * V_7 = V_21 -> V_7 ;
void * V_42 ;
int V_24 = 0 ;
if ( F_86 ( V_21 -> V_42 == NULL ) )
return 0 ;
while ( V_21 -> V_42 ) {
if ( V_69 -> V_192 ( V_21 -> V_42 ) ) {
void * V_193 = V_21 -> V_42 ;
V_21 -> V_42 = NULL ;
F_123 ( V_194 , & V_21 -> V_153 ) ;
F_30 ( & V_7 -> V_99 ) ;
V_69 -> V_102 ( & V_193 ) ;
F_29 ( & V_7 -> V_99 ) ;
continue;
}
if ( V_191 )
return - V_127 ;
V_42 = V_69 -> V_100 ( V_21 -> V_42 ) ;
F_30 ( & V_7 -> V_99 ) ;
V_24 = V_69 -> V_105 ( V_42 ,
V_190 , V_79 ) ;
if ( F_33 ( V_24 != 0 ) ) {
V_69 -> V_102 ( & V_42 ) ;
F_29 ( & V_7 -> V_99 ) ;
return V_24 ;
}
F_29 ( & V_7 -> V_99 ) ;
if ( F_86 ( V_21 -> V_42 == V_42 ) ) {
void * V_193 = V_21 -> V_42 ;
V_21 -> V_42 = NULL ;
F_123 ( V_194 ,
& V_21 -> V_153 ) ;
F_30 ( & V_7 -> V_99 ) ;
V_69 -> V_102 ( & V_42 ) ;
V_69 -> V_102 ( & V_193 ) ;
F_29 ( & V_7 -> V_99 ) ;
} else {
F_30 ( & V_7 -> V_99 ) ;
V_69 -> V_102 ( & V_42 ) ;
F_29 ( & V_7 -> V_99 ) ;
}
}
return 0 ;
}
int F_124 ( struct V_20 * V_21 , bool V_191 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
int V_24 = 0 ;
V_24 = F_125 ( V_21 , true , V_191 , false , 0 ) ;
if ( F_33 ( V_24 != 0 ) )
return V_24 ;
F_29 ( & V_7 -> V_99 ) ;
V_24 = F_49 ( V_21 , false , true , V_191 ) ;
F_30 ( & V_7 -> V_99 ) ;
if ( F_86 ( V_24 == 0 ) )
F_84 ( & V_21 -> V_41 ) ;
F_68 ( V_21 ) ;
return V_24 ;
}
void F_126 ( struct V_20 * V_21 )
{
F_13 ( & V_21 -> V_41 ) ;
}
static int V_182 ( struct V_195 * V_171 )
{
struct V_33 * V_34 =
F_6 ( V_171 , struct V_33 , V_171 ) ;
struct V_20 * V_21 ;
int V_24 = - V_127 ;
int V_57 ;
T_1 V_196 = ( V_133 | V_154 ) ;
F_29 ( & V_34 -> V_60 ) ;
F_67 (bo, &glob->swap_lru, swap) {
V_24 = F_48 ( V_21 , false , true , false , 0 ) ;
if ( ! V_24 )
break;
}
if ( V_24 ) {
F_30 ( & V_34 -> V_60 ) ;
return V_24 ;
}
F_21 ( & V_21 -> V_38 ) ;
if ( ! F_11 ( & V_21 -> V_45 ) ) {
V_24 = F_51 ( V_21 , false , false ) ;
F_55 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
V_57 = F_22 ( V_21 ) ;
F_30 ( & V_34 -> V_60 ) ;
F_26 ( V_21 , V_57 , true ) ;
F_29 ( & V_21 -> V_7 -> V_99 ) ;
V_24 = F_49 ( V_21 , false , false , false ) ;
F_30 ( & V_21 -> V_7 -> V_99 ) ;
if ( F_33 ( V_24 != 0 ) )
goto V_111;
if ( ( V_21 -> V_25 . V_23 & V_196 ) != V_196 ) {
struct V_77 V_118 ;
V_118 = V_21 -> V_25 ;
V_118 . V_43 = NULL ;
V_118 . V_23 = V_154 | V_133 ;
V_118 . V_2 = V_16 ;
V_24 = F_34 ( V_21 , & V_118 , true ,
false , false ) ;
if ( F_33 ( V_24 != 0 ) )
goto V_111;
}
F_122 ( V_21 ) ;
if ( V_21 -> V_7 -> V_69 -> V_197 )
V_21 -> V_7 -> V_69 -> V_197 ( V_21 ) ;
V_24 = F_127 ( V_21 -> V_46 , V_21 -> V_148 ) ;
V_111:
F_46 ( & V_21 -> V_47 -> V_52 ) ;
F_55 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
void F_128 ( struct V_6 * V_7 )
{
while ( V_182 ( & V_7 -> V_34 -> V_171 ) == 0 )
;
}
int F_129 ( struct V_20 * V_21 )
{
int V_24 ;
V_24 = F_130 ( & V_21 -> V_49 ) ;
if ( F_33 ( V_24 != 0 ) )
return - V_119 ;
if ( ! F_131 ( & V_21 -> V_47 -> V_52 ) )
goto V_108;
V_24 = F_48 ( V_21 , true , false , false , NULL ) ;
if ( F_33 ( V_24 != 0 ) )
goto V_108;
F_46 ( & V_21 -> V_47 -> V_52 ) ;
V_108:
F_115 ( & V_21 -> V_49 ) ;
return V_24 ;
}
