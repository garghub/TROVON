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
static int F_16 ( struct V_20 * V_21 ,
bool V_49 )
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
int V_24 ;
while ( F_26 ( F_27 ( & V_21 -> V_58 , 1 ) != 0 ) ) {
if ( V_56 && V_21 -> V_59 ) {
if ( F_26 ( V_57 == V_21 -> V_60 ) )
return - V_61 ;
if ( F_26 ( V_57 - V_21 -> V_60 < ( 1 << 31 ) ) )
return - V_62 ;
}
if ( V_55 )
return - V_63 ;
V_24 = F_16 ( V_21 , V_49 ) ;
if ( F_26 ( V_24 ) )
return V_24 ;
}
if ( V_56 ) {
bool V_64 = false ;
if ( F_26 ( ( V_21 -> V_60 - V_57 < ( 1 << 31 ) )
|| ! V_21 -> V_59 ) )
V_64 = true ;
V_21 -> V_60 = V_57 ;
V_21 -> V_59 = true ;
if ( V_64 )
F_28 ( & V_21 -> V_50 ) ;
} else {
V_21 -> V_59 = false ;
}
return 0 ;
}
static void F_29 ( struct V_37 * V_38 )
{
F_30 () ;
}
void F_31 ( struct V_20 * V_21 , int V_65 ,
bool V_66 )
{
F_32 ( & V_21 -> V_38 , V_65 ,
( V_66 ) ? F_29 : F_9 ) ;
}
int F_33 ( struct V_20 * V_21 ,
bool V_49 ,
bool V_55 , bool V_56 , T_1 V_57 )
{
struct V_33 * V_34 = V_21 -> V_34 ;
int V_54 = 0 ;
int V_24 ;
V_24 = F_25 ( V_21 , V_49 , V_55 , V_56 ,
V_57 ) ;
if ( F_34 ( V_24 == 0 ) ) {
F_35 ( & V_34 -> V_67 ) ;
V_54 = F_23 ( V_21 ) ;
F_36 ( & V_34 -> V_67 ) ;
F_31 ( V_21 , V_54 , true ) ;
}
return V_24 ;
}
int F_37 ( struct V_20 * V_21 ,
bool V_49 , T_1 V_57 )
{
bool V_64 = false ;
int V_24 ;
while ( F_26 ( F_27 ( & V_21 -> V_58 , 1 ) != 0 ) ) {
F_38 ( V_21 -> V_59 && V_57 == V_21 -> V_60 ) ;
V_24 = F_16 ( V_21 , V_49 ) ;
if ( F_26 ( V_24 ) )
return V_24 ;
}
if ( ( V_21 -> V_60 - V_57 < ( 1 << 31 ) ) || ! V_21 -> V_59 )
V_64 = true ;
V_21 -> V_60 = V_57 ;
V_21 -> V_59 = true ;
if ( V_64 )
F_28 ( & V_21 -> V_50 ) ;
return 0 ;
}
int F_39 ( struct V_20 * V_21 ,
bool V_49 , T_1 V_57 )
{
struct V_33 * V_34 = V_21 -> V_34 ;
int V_54 , V_24 ;
V_24 = F_37 ( V_21 , V_49 , V_57 ) ;
if ( F_34 ( ! V_24 ) ) {
F_35 ( & V_34 -> V_67 ) ;
V_54 = F_23 ( V_21 ) ;
F_36 ( & V_34 -> V_67 ) ;
F_31 ( V_21 , V_54 , true ) ;
}
return V_24 ;
}
void F_40 ( struct V_20 * V_21 )
{
F_20 ( V_21 ) ;
F_41 ( & V_21 -> V_58 , 0 ) ;
F_28 ( & V_21 -> V_50 ) ;
}
void F_42 ( struct V_20 * V_21 )
{
struct V_33 * V_34 = V_21 -> V_34 ;
F_35 ( & V_34 -> V_67 ) ;
F_40 ( V_21 ) ;
F_36 ( & V_34 -> V_67 ) ;
}
static int F_43 ( struct V_20 * V_21 , bool V_68 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_33 * V_34 = V_21 -> V_34 ;
int V_24 = 0 ;
T_1 V_69 = 0 ;
F_44 ( & V_21 -> V_70 ) ;
V_21 -> V_46 = NULL ;
if ( V_7 -> V_71 )
V_69 |= V_72 ;
switch ( V_21 -> type ) {
case V_73 :
if ( V_68 )
V_69 |= V_74 ;
case V_75 :
V_21 -> V_46 = V_7 -> V_76 -> V_77 ( V_7 , V_21 -> V_26 << V_78 ,
V_69 , V_34 -> V_79 ) ;
if ( F_26 ( V_21 -> V_46 == NULL ) )
V_24 = - V_80 ;
break;
case V_81 :
V_21 -> V_46 = V_7 -> V_76 -> V_77 ( V_7 , V_21 -> V_26 << V_78 ,
V_69 | V_82 ,
V_34 -> V_79 ) ;
if ( F_26 ( V_21 -> V_46 == NULL ) ) {
V_24 = - V_80 ;
break;
}
V_21 -> V_46 -> V_83 = V_21 -> V_83 ;
break;
default:
F_3 ( L_11 ) ;
V_24 = - V_5 ;
break;
}
return V_24 ;
}
static int F_45 ( struct V_20 * V_21 ,
struct V_84 * V_25 ,
bool V_85 , bool V_49 ,
bool V_86 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
bool V_87 = F_46 ( V_7 , & V_21 -> V_25 ) ;
bool V_88 = F_46 ( V_7 , V_25 ) ;
struct V_8 * V_89 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
struct V_8 * V_90 = & V_7 -> V_9 [ V_25 -> V_2 ] ;
int V_24 = 0 ;
if ( V_87 || V_88 ||
( ( V_25 -> V_23 & V_21 -> V_25 . V_23 & V_91 ) == 0 ) ) {
V_24 = F_47 ( V_89 , true ) ;
if ( F_26 ( V_24 != 0 ) )
goto V_92;
F_48 ( V_21 ) ;
F_49 ( V_89 ) ;
}
if ( ! ( V_90 -> V_1 & V_93 ) ) {
if ( V_21 -> V_46 == NULL ) {
bool V_94 = ! ( V_89 -> V_1 & V_93 ) ;
V_24 = F_43 ( V_21 , V_94 ) ;
if ( V_24 )
goto V_92;
}
V_24 = F_50 ( V_21 -> V_46 , V_25 -> V_23 ) ;
if ( V_24 )
goto V_92;
if ( V_25 -> V_2 != V_16 ) {
V_24 = F_51 ( V_21 -> V_46 , V_25 ) ;
if ( V_24 )
goto V_92;
}
if ( V_21 -> V_25 . V_2 == V_16 ) {
if ( V_7 -> V_76 -> V_95 )
V_7 -> V_76 -> V_95 ( V_21 , V_25 ) ;
V_21 -> V_25 = * V_25 ;
V_25 -> V_43 = NULL ;
goto V_96;
}
}
if ( V_7 -> V_76 -> V_95 )
V_7 -> V_76 -> V_95 ( V_21 , V_25 ) ;
if ( ! ( V_89 -> V_1 & V_93 ) &&
! ( V_90 -> V_1 & V_93 ) )
V_24 = F_52 ( V_21 , V_85 , V_86 , V_25 ) ;
else if ( V_7 -> V_76 -> V_97 )
V_24 = V_7 -> V_76 -> V_97 ( V_21 , V_85 , V_49 ,
V_86 , V_25 ) ;
else
V_24 = F_53 ( V_21 , V_85 , V_86 , V_25 ) ;
if ( V_24 ) {
if ( V_7 -> V_76 -> V_95 ) {
struct V_84 V_98 = * V_25 ;
* V_25 = V_21 -> V_25 ;
V_21 -> V_25 = V_98 ;
V_7 -> V_76 -> V_95 ( V_21 , V_25 ) ;
V_21 -> V_25 = * V_25 ;
* V_25 = V_98 ;
}
goto V_92;
}
V_96:
if ( V_21 -> V_99 ) {
V_24 = V_7 -> V_76 -> V_100 ( V_7 , V_21 -> V_25 . V_23 ) ;
if ( V_24 )
F_3 ( L_12 ) ;
V_21 -> V_99 = false ;
}
if ( V_21 -> V_25 . V_43 ) {
V_21 -> V_101 = ( V_21 -> V_25 . V_102 << V_78 ) +
V_7 -> V_9 [ V_21 -> V_25 . V_2 ] . V_12 ;
V_21 -> V_103 = V_21 -> V_25 . V_23 ;
} else
V_21 -> V_101 = 0 ;
return 0 ;
V_92:
V_90 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
if ( ( V_90 -> V_1 & V_93 ) && V_21 -> V_46 ) {
F_54 ( V_21 -> V_46 ) ;
F_12 ( V_21 -> V_46 ) ;
V_21 -> V_46 = NULL ;
}
return V_24 ;
}
static void F_55 ( struct V_20 * V_21 )
{
if ( V_21 -> V_7 -> V_76 -> V_95 )
V_21 -> V_7 -> V_76 -> V_95 ( V_21 , NULL ) ;
if ( V_21 -> V_46 ) {
F_54 ( V_21 -> V_46 ) ;
F_12 ( V_21 -> V_46 ) ;
V_21 -> V_46 = NULL ;
}
F_56 ( V_21 , & V_21 -> V_25 ) ;
F_41 ( & V_21 -> V_58 , 0 ) ;
F_28 ( & V_21 -> V_50 ) ;
F_57 () ;
}
static void F_58 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_33 * V_34 = V_21 -> V_34 ;
struct V_104 * V_76 = V_7 -> V_76 ;
void * V_42 = NULL ;
int V_54 ;
int V_24 ;
F_35 ( & V_34 -> V_67 ) ;
V_24 = F_25 ( V_21 , false , true , false , 0 ) ;
F_35 ( & V_7 -> V_105 ) ;
( void ) F_59 ( V_21 , false , false , true ) ;
if ( ! V_24 && ! V_21 -> V_42 ) {
F_36 ( & V_7 -> V_105 ) ;
V_54 = F_23 ( V_21 ) ;
F_36 ( & V_34 -> V_67 ) ;
F_55 ( V_21 ) ;
F_31 ( V_21 , V_54 , true ) ;
return;
}
if ( V_21 -> V_42 )
V_42 = V_76 -> V_106 ( V_21 -> V_42 ) ;
F_36 ( & V_7 -> V_105 ) ;
if ( ! V_24 ) {
F_41 ( & V_21 -> V_58 , 0 ) ;
F_28 ( & V_21 -> V_50 ) ;
}
F_22 ( & V_21 -> V_38 ) ;
F_21 ( & V_21 -> V_45 , & V_7 -> V_45 ) ;
F_36 ( & V_34 -> V_67 ) ;
if ( V_42 ) {
V_76 -> V_107 ( V_42 ) ;
V_76 -> V_108 ( & V_42 ) ;
}
F_60 ( & V_7 -> V_109 ,
( ( V_110 / 100 ) < 1 ) ? 1 : V_110 / 100 ) ;
}
static int F_61 ( struct V_20 * V_21 ,
bool V_49 ,
bool V_86 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_104 * V_76 = V_7 -> V_76 ;
struct V_33 * V_34 = V_21 -> V_34 ;
int V_54 ;
int V_24 ;
F_35 ( & V_7 -> V_105 ) ;
V_24 = F_59 ( V_21 , false , false , true ) ;
if ( V_24 && ! V_86 ) {
void * V_42 ;
V_42 = V_76 -> V_106 ( V_21 -> V_42 ) ;
F_36 ( & V_7 -> V_105 ) ;
F_41 ( & V_21 -> V_58 , 0 ) ;
F_28 ( & V_21 -> V_50 ) ;
F_36 ( & V_34 -> V_67 ) ;
V_24 = V_76 -> V_111 ( V_42 , false , V_49 ) ;
V_76 -> V_108 ( & V_42 ) ;
if ( V_24 )
return V_24 ;
F_35 ( & V_7 -> V_105 ) ;
V_24 = F_59 ( V_21 , false , false , true ) ;
F_38 ( V_24 ) ;
F_36 ( & V_7 -> V_105 ) ;
if ( V_24 )
return V_24 ;
F_35 ( & V_34 -> V_67 ) ;
V_24 = F_25 ( V_21 , false , true , false , 0 ) ;
if ( V_24 ) {
F_36 ( & V_34 -> V_67 ) ;
return 0 ;
}
} else
F_36 ( & V_7 -> V_105 ) ;
if ( V_24 || F_26 ( F_11 ( & V_21 -> V_45 ) ) ) {
F_41 ( & V_21 -> V_58 , 0 ) ;
F_28 ( & V_21 -> V_50 ) ;
F_36 ( & V_34 -> V_67 ) ;
return V_24 ;
}
V_54 = F_23 ( V_21 ) ;
F_24 ( & V_21 -> V_45 ) ;
++ V_54 ;
F_36 ( & V_34 -> V_67 ) ;
F_55 ( V_21 ) ;
F_31 ( V_21 , V_54 , true ) ;
return 0 ;
}
static int F_62 ( struct V_6 * V_7 , bool V_112 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
struct V_20 * V_113 = NULL ;
int V_24 = 0 ;
F_35 ( & V_34 -> V_67 ) ;
if ( F_11 ( & V_7 -> V_45 ) )
goto V_114;
V_113 = F_63 ( & V_7 -> V_45 ,
struct V_20 , V_45 ) ;
F_22 ( & V_113 -> V_38 ) ;
for (; ; ) {
struct V_20 * V_115 = NULL ;
if ( V_113 -> V_45 . V_116 != & V_7 -> V_45 ) {
V_115 = F_63 ( & V_113 -> V_45 ,
struct V_20 , V_45 ) ;
F_22 ( & V_115 -> V_38 ) ;
}
V_24 = F_25 ( V_113 , false , true , false , 0 ) ;
if ( V_112 && V_24 ) {
F_36 ( & V_34 -> V_67 ) ;
V_24 = F_25 ( V_113 , false , false ,
false , 0 ) ;
F_35 ( & V_34 -> V_67 ) ;
}
if ( ! V_24 )
V_24 = F_61 ( V_113 , false ,
! V_112 ) ;
else
F_36 ( & V_34 -> V_67 ) ;
F_64 ( & V_113 -> V_38 , F_9 ) ;
V_113 = V_115 ;
if ( V_24 || ! V_113 )
goto V_117;
F_35 ( & V_34 -> V_67 ) ;
if ( F_11 ( & V_113 -> V_45 ) )
break;
}
V_114:
F_36 ( & V_34 -> V_67 ) ;
V_117:
if ( V_113 )
F_64 ( & V_113 -> V_38 , F_9 ) ;
return V_24 ;
}
static void F_65 ( struct V_118 * V_119 )
{
struct V_6 * V_7 =
F_6 ( V_119 , struct V_6 , V_109 . V_119 ) ;
if ( F_62 ( V_7 , false ) ) {
F_60 ( & V_7 -> V_109 ,
( ( V_110 / 100 ) < 1 ) ? 1 : V_110 / 100 ) ;
}
}
static void F_66 ( struct V_37 * V_37 )
{
struct V_20 * V_21 =
F_6 ( V_37 , struct V_20 , V_37 ) ;
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
F_67 ( & V_7 -> V_120 ) ;
if ( F_34 ( V_21 -> V_121 != NULL ) ) {
F_68 ( & V_21 -> V_122 , & V_7 -> V_123 ) ;
F_69 ( V_21 -> V_121 ) ;
V_21 -> V_121 = NULL ;
}
F_70 ( & V_7 -> V_120 ) ;
F_47 ( V_9 , false ) ;
F_71 ( V_21 ) ;
F_49 ( V_9 ) ;
F_58 ( V_21 ) ;
F_64 ( & V_21 -> V_38 , F_9 ) ;
}
void F_72 ( struct V_20 * * V_124 )
{
struct V_20 * V_21 = * V_124 ;
* V_124 = NULL ;
F_64 ( & V_21 -> V_37 , F_66 ) ;
}
int F_73 ( struct V_6 * V_7 )
{
return F_74 ( & V_7 -> V_109 ) ;
}
void F_75 ( struct V_6 * V_7 , int V_125 )
{
if ( V_125 )
F_60 ( & V_7 -> V_109 ,
( ( V_110 / 100 ) < 1 ) ? 1 : V_110 / 100 ) ;
}
static int F_76 ( struct V_20 * V_21 , bool V_49 ,
bool V_86 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_84 V_126 ;
struct V_22 V_23 ;
int V_24 = 0 ;
F_35 ( & V_7 -> V_105 ) ;
V_24 = F_59 ( V_21 , false , V_49 , V_86 ) ;
F_36 ( & V_7 -> V_105 ) ;
if ( F_26 ( V_24 != 0 ) ) {
if ( V_24 != - V_127 ) {
F_3 ( L_13 ) ;
}
goto V_117;
}
F_10 ( ! F_18 ( V_21 ) ) ;
V_126 = V_21 -> V_25 ;
V_126 . V_43 = NULL ;
V_126 . V_128 . V_129 = false ;
V_126 . V_128 . V_130 = 0 ;
V_23 . V_131 = 0 ;
V_23 . V_132 = 0 ;
V_23 . V_27 = 0 ;
V_23 . V_133 = 0 ;
V_7 -> V_76 -> V_134 ( V_21 , & V_23 ) ;
V_24 = F_77 ( V_21 , & V_23 , & V_126 , V_49 ,
V_86 ) ;
if ( V_24 ) {
if ( V_24 != - V_127 ) {
F_3 ( L_14 ,
V_21 ) ;
F_4 ( V_21 , & V_23 ) ;
}
goto V_117;
}
V_24 = F_45 ( V_21 , & V_126 , true , V_49 ,
V_86 ) ;
if ( V_24 ) {
if ( V_24 != - V_127 )
F_3 ( L_15 ) ;
F_56 ( V_21 , & V_126 ) ;
goto V_117;
}
V_21 -> V_99 = true ;
V_117:
return V_24 ;
}
static int F_78 ( struct V_6 * V_7 ,
T_1 V_2 ,
bool V_49 ,
bool V_86 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
struct V_20 * V_21 ;
int V_24 = - V_63 , V_54 ;
F_35 ( & V_34 -> V_67 ) ;
F_79 (bo, &man->lru, lru) {
V_24 = F_25 ( V_21 , false , true , false , 0 ) ;
if ( ! V_24 )
break;
}
if ( V_24 ) {
F_36 ( & V_34 -> V_67 ) ;
return V_24 ;
}
F_22 ( & V_21 -> V_38 ) ;
if ( ! F_11 ( & V_21 -> V_45 ) ) {
V_24 = F_61 ( V_21 , V_49 ,
V_86 ) ;
F_64 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
V_54 = F_23 ( V_21 ) ;
F_36 ( & V_34 -> V_67 ) ;
F_10 ( V_24 != 0 ) ;
F_31 ( V_21 , V_54 , true ) ;
V_24 = F_76 ( V_21 , V_49 , V_86 ) ;
F_42 ( V_21 ) ;
F_64 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
void F_56 ( struct V_20 * V_21 , struct V_84 * V_25 )
{
struct V_8 * V_9 = & V_21 -> V_7 -> V_9 [ V_25 -> V_2 ] ;
if ( V_25 -> V_43 )
(* V_9 -> V_17 -> V_135 )( V_9 , V_25 ) ;
}
static int F_80 ( struct V_20 * V_21 ,
T_1 V_2 ,
struct V_22 * V_23 ,
struct V_84 * V_25 ,
bool V_49 ,
bool V_86 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
int V_24 ;
do {
V_24 = (* V_9 -> V_17 -> V_136 )( V_9 , V_21 , V_23 , V_25 ) ;
if ( F_26 ( V_24 != 0 ) )
return V_24 ;
if ( V_25 -> V_43 )
break;
V_24 = F_78 ( V_7 , V_2 ,
V_49 , V_86 ) ;
if ( F_26 ( V_24 != 0 ) )
return V_24 ;
} while ( 1 );
if ( V_25 -> V_43 == NULL )
return - V_80 ;
V_25 -> V_2 = V_2 ;
return 0 ;
}
static T_1 F_81 ( struct V_8 * V_9 ,
T_1 V_103 ,
T_1 V_137 )
{
T_1 V_138 = V_137 & V_91 ;
T_1 V_139 = V_137 & ~ V_91 ;
if ( ( V_103 & V_138 ) != 0 )
V_139 |= ( V_103 & V_138 ) ;
else if ( ( V_9 -> V_15 & V_138 ) != 0 )
V_139 |= V_9 -> V_15 ;
else if ( ( V_140 & V_138 ) != 0 )
V_139 |= V_140 ;
else if ( ( V_141 & V_138 ) != 0 )
V_139 |= V_141 ;
else if ( ( V_142 & V_138 ) != 0 )
V_139 |= V_142 ;
return V_139 ;
}
static bool F_82 ( struct V_8 * V_9 ,
T_1 V_2 ,
T_1 V_137 ,
T_1 * V_143 )
{
T_1 V_144 = F_8 ( V_2 ) ;
if ( ( V_144 & V_137 & V_145 ) == 0 )
return false ;
if ( ( V_137 & V_9 -> V_14 ) == 0 )
return false ;
V_144 |= ( V_137 & V_9 -> V_14 ) ;
* V_143 = V_144 ;
return true ;
}
int F_77 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_84 * V_25 ,
bool V_49 ,
bool V_86 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 ;
T_1 V_2 = V_16 ;
T_1 V_144 = 0 ;
bool V_146 = false ;
bool V_147 = false ;
bool V_148 = false ;
int V_3 , V_24 ;
V_25 -> V_43 = NULL ;
for ( V_3 = 0 ; V_3 < V_23 -> V_27 ; ++ V_3 ) {
V_24 = F_1 ( V_23 -> V_23 [ V_3 ] ,
& V_2 ) ;
if ( V_24 )
return V_24 ;
V_9 = & V_7 -> V_9 [ V_2 ] ;
V_147 = F_82 ( V_9 ,
V_2 ,
V_23 -> V_23 [ V_3 ] ,
& V_144 ) ;
if ( ! V_147 )
continue;
V_144 = F_81 ( V_9 , V_21 -> V_25 . V_23 ,
V_144 ) ;
F_83 ( & V_144 , V_23 -> V_23 [ V_3 ] ,
~ V_149 ) ;
if ( V_2 == V_16 )
break;
if ( V_9 -> V_10 && V_9 -> V_11 ) {
V_146 = true ;
V_24 = (* V_9 -> V_17 -> V_136 )( V_9 , V_21 , V_23 , V_25 ) ;
if ( F_26 ( V_24 ) )
return V_24 ;
}
if ( V_25 -> V_43 )
break;
}
if ( ( V_147 && ( V_2 == V_16 ) ) || V_25 -> V_43 ) {
V_25 -> V_2 = V_2 ;
V_25 -> V_23 = V_144 ;
return 0 ;
}
if ( ! V_146 )
return - V_5 ;
for ( V_3 = 0 ; V_3 < V_23 -> V_133 ; ++ V_3 ) {
V_24 = F_1 ( V_23 -> V_150 [ V_3 ] ,
& V_2 ) ;
if ( V_24 )
return V_24 ;
V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( ! V_9 -> V_10 )
continue;
if ( ! F_82 ( V_9 ,
V_2 ,
V_23 -> V_150 [ V_3 ] ,
& V_144 ) )
continue;
V_144 = F_81 ( V_9 , V_21 -> V_25 . V_23 ,
V_144 ) ;
F_83 ( & V_144 , V_23 -> V_150 [ V_3 ] ,
~ V_149 ) ;
if ( V_2 == V_16 ) {
V_25 -> V_2 = V_2 ;
V_25 -> V_23 = V_144 ;
V_25 -> V_43 = NULL ;
return 0 ;
}
V_24 = F_80 ( V_21 , V_2 , V_23 , V_25 ,
V_49 , V_86 ) ;
if ( V_24 == 0 && V_25 -> V_43 ) {
V_25 -> V_23 = V_144 ;
return 0 ;
}
if ( V_24 == - V_127 )
V_148 = true ;
}
V_24 = ( V_148 ) ? - V_127 : - V_80 ;
return V_24 ;
}
int F_84 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
bool V_49 ,
bool V_86 )
{
int V_24 = 0 ;
struct V_84 V_25 ;
struct V_6 * V_7 = V_21 -> V_7 ;
F_10 ( ! F_18 ( V_21 ) ) ;
F_35 ( & V_7 -> V_105 ) ;
V_24 = F_59 ( V_21 , false , V_49 , V_86 ) ;
F_36 ( & V_7 -> V_105 ) ;
if ( V_24 )
return V_24 ;
V_25 . V_26 = V_21 -> V_26 ;
V_25 . V_13 = V_25 . V_26 << V_78 ;
V_25 . V_151 = V_21 -> V_25 . V_151 ;
V_25 . V_128 . V_129 = false ;
V_25 . V_128 . V_130 = 0 ;
V_24 = F_77 ( V_21 , V_23 , & V_25 ,
V_49 , V_86 ) ;
if ( V_24 )
goto V_114;
V_24 = F_45 ( V_21 , & V_25 , false ,
V_49 , V_86 ) ;
V_114:
if ( V_24 && V_25 . V_43 )
F_56 ( V_21 , & V_25 ) ;
return V_24 ;
}
static int F_85 ( struct V_22 * V_23 ,
struct V_84 * V_25 )
{
int V_3 ;
if ( V_25 -> V_43 && V_23 -> V_132 != 0 &&
( V_25 -> V_102 < V_23 -> V_131 ||
V_25 -> V_102 + V_25 -> V_26 > V_23 -> V_132 ) )
return - 1 ;
for ( V_3 = 0 ; V_3 < V_23 -> V_27 ; V_3 ++ ) {
if ( ( V_23 -> V_23 [ V_3 ] & V_25 -> V_23 &
V_91 ) &&
( V_23 -> V_23 [ V_3 ] & V_25 -> V_23 &
V_145 ) )
return V_3 ;
}
return - 1 ;
}
int F_86 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
bool V_49 ,
bool V_86 )
{
int V_24 ;
F_10 ( ! F_18 ( V_21 ) ) ;
if ( V_23 -> V_132 || V_23 -> V_131 )
if ( V_23 -> V_131 > V_23 -> V_132 ||
( V_23 -> V_132 - V_23 -> V_131 ) < V_21 -> V_26 )
return - V_5 ;
V_24 = F_85 ( V_23 , & V_21 -> V_25 ) ;
if ( V_24 < 0 ) {
V_24 = F_84 ( V_21 , V_23 , V_49 ,
V_86 ) ;
if ( V_24 )
return V_24 ;
} else {
F_83 ( & V_21 -> V_25 . V_23 , V_23 -> V_23 [ V_24 ] ,
~ V_149 ) ;
}
if ( V_21 -> V_25 . V_2 == V_16 && V_21 -> V_46 == NULL ) {
V_24 = F_43 ( V_21 , true ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
int F_87 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
F_10 ( ( V_23 -> V_131 || V_23 -> V_132 ) &&
( V_21 -> V_25 . V_26 > ( V_23 -> V_132 - V_23 -> V_131 ) ) ) ;
return 0 ;
}
int F_88 ( struct V_6 * V_7 ,
struct V_20 * V_21 ,
unsigned long V_13 ,
enum V_152 type ,
struct V_22 * V_23 ,
T_1 V_151 ,
bool V_49 ,
struct V_153 * V_154 ,
T_3 V_39 ,
struct V_155 * V_83 ,
void (* V_47) ( struct V_20 * ) )
{
int V_24 = 0 ;
unsigned long V_26 ;
struct V_156 * V_48 = V_7 -> V_34 -> V_48 ;
V_24 = F_89 ( V_48 , V_39 , false , false ) ;
if ( V_24 ) {
F_3 ( L_16 ) ;
if ( V_47 )
(* V_47)( V_21 ) ;
else
F_14 ( V_21 ) ;
return - V_80 ;
}
V_26 = ( V_13 + V_35 - 1 ) >> V_78 ;
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
F_90 ( & V_21 -> V_37 ) ;
F_90 ( & V_21 -> V_38 ) ;
F_41 ( & V_21 -> V_41 , 0 ) ;
F_41 ( & V_21 -> V_58 , 1 ) ;
F_91 ( & V_21 -> V_50 ) ;
F_92 ( & V_21 -> V_44 ) ;
F_92 ( & V_21 -> V_45 ) ;
F_92 ( & V_21 -> V_52 ) ;
F_92 ( & V_21 -> V_157 ) ;
V_21 -> V_7 = V_7 ;
V_21 -> V_34 = V_7 -> V_34 ;
V_21 -> type = type ;
V_21 -> V_26 = V_26 ;
V_21 -> V_25 . V_13 = V_26 << V_78 ;
V_21 -> V_25 . V_2 = V_16 ;
V_21 -> V_25 . V_26 = V_21 -> V_26 ;
V_21 -> V_25 . V_43 = NULL ;
V_21 -> V_25 . V_151 = V_151 ;
V_21 -> V_25 . V_128 . V_129 = false ;
V_21 -> V_25 . V_128 . V_130 = 0 ;
V_21 -> V_158 = 0 ;
V_21 -> V_25 . V_23 = ( V_159 | V_140 ) ;
V_21 -> V_59 = false ;
V_21 -> V_154 = V_154 ;
V_21 -> V_39 = V_39 ;
V_21 -> V_83 = V_83 ;
F_93 ( & V_21 -> V_34 -> V_36 ) ;
V_24 = F_87 ( V_21 , V_23 ) ;
if ( F_26 ( V_24 != 0 ) )
goto V_92;
if ( V_21 -> type == V_73 ||
V_21 -> type == V_81 ) {
V_24 = F_94 ( V_21 ) ;
if ( V_24 )
goto V_92;
}
V_24 = F_86 ( V_21 , V_23 , V_49 , false ) ;
if ( V_24 )
goto V_92;
F_42 ( V_21 ) ;
return 0 ;
V_92:
F_42 ( V_21 ) ;
F_72 ( & V_21 ) ;
return V_24 ;
}
T_3 F_95 ( struct V_6 * V_7 ,
unsigned long V_160 ,
unsigned V_161 )
{
unsigned V_162 = ( F_96 ( V_160 ) ) >> V_78 ;
T_3 V_13 = 0 ;
V_13 += F_97 ( V_161 ) ;
V_13 += F_96 ( V_162 * sizeof( void * ) ) ;
V_13 += F_97 ( sizeof( struct V_163 ) ) ;
return V_13 ;
}
T_3 F_98 ( struct V_6 * V_7 ,
unsigned long V_160 ,
unsigned V_161 )
{
unsigned V_162 = ( F_96 ( V_160 ) ) >> V_78 ;
T_3 V_13 = 0 ;
V_13 += F_97 ( V_161 ) ;
V_13 += F_96 ( V_162 * sizeof( void * ) ) ;
V_13 += F_96 ( V_162 * sizeof( V_164 ) ) ;
V_13 += F_97 ( sizeof( struct V_165 ) ) ;
return V_13 ;
}
int F_99 ( struct V_6 * V_7 ,
unsigned long V_13 ,
enum V_152 type ,
struct V_22 * V_23 ,
T_1 V_151 ,
bool V_49 ,
struct V_153 * V_154 ,
struct V_20 * * V_124 )
{
struct V_20 * V_21 ;
T_3 V_39 ;
int V_24 ;
V_21 = F_100 ( sizeof( * V_21 ) , V_166 ) ;
if ( F_26 ( V_21 == NULL ) )
return - V_80 ;
V_39 = F_95 ( V_7 , V_13 , sizeof( struct V_20 ) ) ;
V_24 = F_88 ( V_7 , V_21 , V_13 , type , V_23 , V_151 ,
V_49 , V_154 , V_39 ,
NULL , NULL ) ;
if ( F_34 ( V_24 == 0 ) )
* V_124 = V_21 ;
return V_24 ;
}
static int F_101 ( struct V_6 * V_7 ,
unsigned V_2 , bool V_167 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
struct V_33 * V_34 = V_7 -> V_34 ;
int V_24 ;
F_35 ( & V_34 -> V_67 ) ;
while ( ! F_11 ( & V_9 -> V_44 ) ) {
F_36 ( & V_34 -> V_67 ) ;
V_24 = F_78 ( V_7 , V_2 , false , false ) ;
if ( V_24 ) {
if ( V_167 ) {
return V_24 ;
} else {
F_3 ( L_18 ) ;
}
}
F_35 ( & V_34 -> V_67 ) ;
}
F_36 ( & V_34 -> V_67 ) ;
return 0 ;
}
int F_102 ( struct V_6 * V_7 , unsigned V_2 )
{
struct V_8 * V_9 ;
int V_24 = - V_5 ;
if ( V_2 >= V_168 ) {
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
F_101 ( V_7 , V_2 , false ) ;
V_24 = (* V_9 -> V_17 -> V_169 )( V_9 ) ;
}
return V_24 ;
}
int F_103 ( struct V_6 * V_7 , unsigned V_2 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( V_2 == 0 || V_2 >= V_168 ) {
F_3 ( L_21 , V_2 ) ;
return - V_5 ;
}
if ( ! V_9 -> V_10 ) {
F_3 ( L_22 , V_2 ) ;
return 0 ;
}
return F_101 ( V_7 , V_2 , true ) ;
}
int F_104 ( struct V_6 * V_7 , unsigned type ,
unsigned long V_170 )
{
int V_24 = - V_5 ;
struct V_8 * V_9 ;
F_10 ( type >= V_168 ) ;
V_9 = & V_7 -> V_9 [ type ] ;
F_10 ( V_9 -> V_10 ) ;
V_9 -> V_171 = true ;
V_9 -> V_172 = false ;
F_105 ( & V_9 -> V_173 ) ;
F_92 ( & V_9 -> V_157 ) ;
V_24 = V_7 -> V_76 -> V_174 ( V_7 , type , V_9 ) ;
if ( V_24 )
return V_24 ;
V_9 -> V_7 = V_7 ;
V_24 = 0 ;
if ( type != V_16 ) {
V_24 = (* V_9 -> V_17 -> V_175 )( V_9 , V_170 ) ;
if ( V_24 )
return V_24 ;
}
V_9 -> V_10 = true ;
V_9 -> V_11 = true ;
V_9 -> V_13 = V_170 ;
F_92 ( & V_9 -> V_44 ) ;
return 0 ;
}
static void F_106 ( struct V_28 * V_29 )
{
struct V_33 * V_34 =
F_6 ( V_29 , struct V_33 , V_29 ) ;
F_107 ( V_34 -> V_48 , & V_34 -> V_176 ) ;
F_108 ( V_34 -> V_79 ) ;
F_14 ( V_34 ) ;
}
void F_109 ( struct V_177 * V_178 )
{
struct V_33 * V_34 = V_178 -> V_179 ;
F_110 ( & V_34 -> V_29 ) ;
F_111 ( & V_34 -> V_29 ) ;
}
int F_112 ( struct V_177 * V_178 )
{
struct V_180 * V_181 =
F_6 ( V_178 , struct V_180 , V_178 ) ;
struct V_33 * V_34 = V_178 -> V_179 ;
int V_24 ;
F_105 ( & V_34 -> V_182 ) ;
F_113 ( & V_34 -> V_67 ) ;
V_34 -> V_48 = V_181 -> V_48 ;
V_34 -> V_79 = F_114 ( V_183 | V_184 ) ;
if ( F_26 ( V_34 -> V_79 == NULL ) ) {
V_24 = - V_80 ;
goto V_185;
}
F_92 ( & V_34 -> V_53 ) ;
F_92 ( & V_34 -> V_186 ) ;
F_115 ( & V_34 -> V_176 , V_187 ) ;
V_24 = F_116 ( V_34 -> V_48 , & V_34 -> V_176 ) ;
if ( F_26 ( V_24 != 0 ) ) {
F_3 ( L_23 ) ;
goto V_188;
}
F_41 ( & V_34 -> V_36 , 0 ) ;
V_24 = F_117 (
& V_34 -> V_29 , & V_189 , F_118 () , L_24 ) ;
if ( F_26 ( V_24 != 0 ) )
F_111 ( & V_34 -> V_29 ) ;
return V_24 ;
V_188:
F_108 ( V_34 -> V_79 ) ;
V_185:
F_14 ( V_34 ) ;
return V_24 ;
}
int F_119 ( struct V_6 * V_7 )
{
int V_24 = 0 ;
unsigned V_3 = V_168 ;
struct V_8 * V_9 ;
struct V_33 * V_34 = V_7 -> V_34 ;
while ( V_3 -- ) {
V_9 = & V_7 -> V_9 [ V_3 ] ;
if ( V_9 -> V_10 ) {
V_9 -> V_11 = false ;
if ( ( V_3 != V_16 ) && F_102 ( V_7 , V_3 ) ) {
V_24 = - V_63 ;
F_3 ( L_25 ,
V_3 ) ;
}
V_9 -> V_10 = false ;
}
}
F_120 ( & V_34 -> V_182 ) ;
F_121 ( & V_7 -> V_186 ) ;
F_122 ( & V_34 -> V_182 ) ;
F_74 ( & V_7 -> V_109 ) ;
while ( F_62 ( V_7 , true ) )
;
F_35 ( & V_34 -> V_67 ) ;
if ( F_11 ( & V_7 -> V_45 ) )
F_123 ( L_26 ) ;
if ( F_11 ( & V_7 -> V_9 [ 0 ] . V_44 ) )
F_123 ( L_27 ) ;
F_36 ( & V_34 -> V_67 ) ;
F_10 ( ! F_124 ( & V_7 -> V_190 ) ) ;
F_67 ( & V_7 -> V_120 ) ;
F_125 ( & V_7 -> V_190 ) ;
F_70 ( & V_7 -> V_120 ) ;
return V_24 ;
}
int F_126 ( struct V_6 * V_7 ,
struct V_33 * V_34 ,
struct V_104 * V_76 ,
T_4 V_191 ,
bool V_71 )
{
int V_24 = - V_5 ;
F_127 ( & V_7 -> V_120 ) ;
V_7 -> V_76 = V_76 ;
memset ( V_7 -> V_9 , 0 , sizeof( V_7 -> V_9 ) ) ;
V_24 = F_104 ( V_7 , V_16 , 0 ) ;
if ( F_26 ( V_24 != 0 ) )
goto V_192;
V_7 -> V_123 = V_193 ;
V_24 = F_128 ( & V_7 -> V_190 , V_191 , 0x10000000 ) ;
if ( F_26 ( V_24 != 0 ) )
goto V_194;
F_129 ( & V_7 -> V_109 , F_65 ) ;
F_92 ( & V_7 -> V_45 ) ;
V_7 -> V_195 = NULL ;
V_7 -> V_34 = V_34 ;
V_7 -> V_71 = V_71 ;
V_7 -> V_60 = 0 ;
F_113 ( & V_7 -> V_105 ) ;
F_120 ( & V_34 -> V_182 ) ;
F_21 ( & V_7 -> V_186 , & V_34 -> V_186 ) ;
F_122 ( & V_34 -> V_182 ) ;
return 0 ;
V_194:
F_102 ( V_7 , 0 ) ;
V_192:
return V_24 ;
}
bool F_46 ( struct V_6 * V_7 , struct V_84 * V_25 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_25 -> V_2 ] ;
if ( ! ( V_9 -> V_1 & V_93 ) ) {
if ( V_25 -> V_2 == V_16 )
return false ;
if ( V_9 -> V_1 & V_196 )
return false ;
if ( V_25 -> V_23 & V_140 )
return false ;
}
return true ;
}
void F_48 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
T_5 V_101 = ( T_5 ) V_21 -> V_197 ;
T_5 V_198 = ( ( T_5 ) V_21 -> V_25 . V_26 ) << V_78 ;
if ( ! V_7 -> V_195 )
return;
F_130 ( V_7 -> V_195 , V_101 , V_198 , 1 ) ;
F_71 ( V_21 ) ;
}
void F_131 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
F_47 ( V_9 , false ) ;
F_48 ( V_21 ) ;
F_49 ( V_9 ) ;
}
static void F_132 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_199 * * V_200 = & V_7 -> V_123 . V_199 ;
struct V_199 * V_201 = NULL ;
struct V_20 * V_202 ;
unsigned long V_101 = V_21 -> V_121 -> V_102 ;
unsigned long V_203 ;
while ( * V_200 ) {
V_201 = * V_200 ;
V_202 = F_133 ( V_201 , struct V_20 , V_122 ) ;
V_203 = V_202 -> V_121 -> V_102 ;
if ( V_101 < V_203 )
V_200 = & V_201 -> V_204 ;
else if ( V_101 > V_203 )
V_200 = & V_201 -> V_205 ;
else
F_30 () ;
}
F_134 ( & V_21 -> V_122 , V_201 , V_200 ) ;
F_135 ( & V_21 -> V_122 , & V_7 -> V_123 ) ;
}
static int F_94 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
int V_24 ;
V_206:
V_24 = F_136 ( & V_7 -> V_190 ) ;
if ( F_26 ( V_24 != 0 ) )
return V_24 ;
F_67 ( & V_7 -> V_120 ) ;
V_21 -> V_121 = F_137 ( & V_7 -> V_190 ,
V_21 -> V_25 . V_26 , 0 , 0 ) ;
if ( F_26 ( V_21 -> V_121 == NULL ) ) {
V_24 = - V_80 ;
goto V_114;
}
V_21 -> V_121 = F_138 ( V_21 -> V_121 ,
V_21 -> V_25 . V_26 , 0 ) ;
if ( F_26 ( V_21 -> V_121 == NULL ) ) {
F_70 ( & V_7 -> V_120 ) ;
goto V_206;
}
F_132 ( V_21 ) ;
F_70 ( & V_7 -> V_120 ) ;
V_21 -> V_197 = ( ( T_4 ) V_21 -> V_121 -> V_102 ) << V_78 ;
return 0 ;
V_114:
F_70 ( & V_7 -> V_120 ) ;
return V_24 ;
}
int F_59 ( struct V_20 * V_21 ,
bool V_207 , bool V_49 , bool V_55 )
{
struct V_104 * V_76 = V_21 -> V_7 -> V_76 ;
struct V_6 * V_7 = V_21 -> V_7 ;
void * V_42 ;
int V_24 = 0 ;
if ( F_34 ( V_21 -> V_42 == NULL ) )
return 0 ;
while ( V_21 -> V_42 ) {
if ( V_76 -> V_208 ( V_21 -> V_42 ) ) {
void * V_209 = V_21 -> V_42 ;
V_21 -> V_42 = NULL ;
F_139 ( V_210 , & V_21 -> V_158 ) ;
F_36 ( & V_7 -> V_105 ) ;
V_76 -> V_108 ( & V_209 ) ;
F_35 ( & V_7 -> V_105 ) ;
continue;
}
if ( V_55 )
return - V_63 ;
V_42 = V_76 -> V_106 ( V_21 -> V_42 ) ;
F_36 ( & V_7 -> V_105 ) ;
V_24 = V_76 -> V_111 ( V_42 ,
V_207 , V_49 ) ;
if ( F_26 ( V_24 != 0 ) ) {
V_76 -> V_108 ( & V_42 ) ;
F_35 ( & V_7 -> V_105 ) ;
return V_24 ;
}
F_35 ( & V_7 -> V_105 ) ;
if ( F_34 ( V_21 -> V_42 == V_42 ) ) {
void * V_209 = V_21 -> V_42 ;
V_21 -> V_42 = NULL ;
F_139 ( V_210 ,
& V_21 -> V_158 ) ;
F_36 ( & V_7 -> V_105 ) ;
V_76 -> V_108 ( & V_42 ) ;
V_76 -> V_108 ( & V_209 ) ;
F_35 ( & V_7 -> V_105 ) ;
} else {
F_36 ( & V_7 -> V_105 ) ;
V_76 -> V_108 ( & V_42 ) ;
F_35 ( & V_7 -> V_105 ) ;
}
}
return 0 ;
}
int F_140 ( struct V_20 * V_21 , bool V_55 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
int V_24 = 0 ;
V_24 = F_33 ( V_21 , true , V_55 , false , 0 ) ;
if ( F_26 ( V_24 != 0 ) )
return V_24 ;
F_35 ( & V_7 -> V_105 ) ;
V_24 = F_59 ( V_21 , false , true , V_55 ) ;
F_36 ( & V_7 -> V_105 ) ;
if ( F_34 ( V_24 == 0 ) )
F_93 ( & V_21 -> V_41 ) ;
F_42 ( V_21 ) ;
return V_24 ;
}
void F_141 ( struct V_20 * V_21 )
{
F_13 ( & V_21 -> V_41 ) ;
}
static int V_187 ( struct V_211 * V_176 )
{
struct V_33 * V_34 =
F_6 ( V_176 , struct V_33 , V_176 ) ;
struct V_20 * V_21 ;
int V_24 = - V_63 ;
int V_54 ;
T_1 V_212 = ( V_140 | V_159 ) ;
F_35 ( & V_34 -> V_67 ) ;
F_79 (bo, &glob->swap_lru, swap) {
V_24 = F_25 ( V_21 , false , true , false , 0 ) ;
if ( ! V_24 )
break;
}
if ( V_24 ) {
F_36 ( & V_34 -> V_67 ) ;
return V_24 ;
}
F_22 ( & V_21 -> V_38 ) ;
if ( ! F_11 ( & V_21 -> V_45 ) ) {
V_24 = F_61 ( V_21 , false , false ) ;
F_64 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
V_54 = F_23 ( V_21 ) ;
F_36 ( & V_34 -> V_67 ) ;
F_31 ( V_21 , V_54 , true ) ;
F_35 ( & V_21 -> V_7 -> V_105 ) ;
V_24 = F_59 ( V_21 , false , false , false ) ;
F_36 ( & V_21 -> V_7 -> V_105 ) ;
if ( F_26 ( V_24 != 0 ) )
goto V_117;
if ( ( V_21 -> V_25 . V_23 & V_212 ) != V_212 ) {
struct V_84 V_126 ;
V_126 = V_21 -> V_25 ;
V_126 . V_43 = NULL ;
V_126 . V_23 = V_159 | V_140 ;
V_126 . V_2 = V_16 ;
V_24 = F_45 ( V_21 , & V_126 , true ,
false , false ) ;
if ( F_26 ( V_24 != 0 ) )
goto V_117;
}
F_131 ( V_21 ) ;
if ( V_21 -> V_7 -> V_76 -> V_213 )
V_21 -> V_7 -> V_76 -> V_213 ( V_21 ) ;
V_24 = F_142 ( V_21 -> V_46 , V_21 -> V_154 ) ;
V_117:
F_41 ( & V_21 -> V_58 , 0 ) ;
F_28 ( & V_21 -> V_50 ) ;
F_64 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
void F_143 ( struct V_6 * V_7 )
{
while ( V_187 ( & V_7 -> V_34 -> V_176 ) == 0 )
;
}
