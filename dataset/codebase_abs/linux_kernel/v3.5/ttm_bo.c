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
F_7 ( & V_21 -> V_51 ) == 0 ) ;
} else {
F_18 ( V_21 -> V_50 , F_7 ( & V_21 -> V_51 ) == 0 ) ;
return 0 ;
}
}
void F_19 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 ;
F_10 ( ! F_7 ( & V_21 -> V_51 ) ) ;
if ( ! ( V_21 -> V_25 . V_23 & V_52 ) ) {
F_10 ( ! F_11 ( & V_21 -> V_44 ) ) ;
V_9 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
F_20 ( & V_21 -> V_44 , & V_9 -> V_44 ) ;
F_21 ( & V_21 -> V_38 ) ;
if ( V_21 -> V_46 != NULL ) {
F_20 ( & V_21 -> V_53 , & V_21 -> V_34 -> V_54 ) ;
F_21 ( & V_21 -> V_38 ) ;
}
}
}
int F_22 ( struct V_20 * V_21 )
{
int V_55 = 0 ;
if ( ! F_11 ( & V_21 -> V_53 ) ) {
F_23 ( & V_21 -> V_53 ) ;
++ V_55 ;
}
if ( ! F_11 ( & V_21 -> V_44 ) ) {
F_23 ( & V_21 -> V_44 ) ;
++ V_55 ;
}
return V_55 ;
}
int F_24 ( struct V_20 * V_21 ,
bool V_49 ,
bool V_56 , bool V_57 , T_1 V_58 )
{
struct V_33 * V_34 = V_21 -> V_34 ;
int V_24 ;
while ( F_25 ( F_26 ( & V_21 -> V_51 , 0 , 1 ) != 0 ) ) {
if ( V_57 && V_21 -> V_59 ) {
if ( F_25 ( V_58 == V_21 -> V_60 ) )
return - V_61 ;
if ( F_25 ( V_58 - V_21 -> V_60 < ( 1 << 31 ) ) )
return - V_62 ;
}
if ( V_56 )
return - V_63 ;
F_27 ( & V_34 -> V_64 ) ;
V_24 = F_16 ( V_21 , V_49 ) ;
F_28 ( & V_34 -> V_64 ) ;
if ( F_25 ( V_24 ) )
return V_24 ;
}
if ( V_57 ) {
if ( F_25 ( ( V_21 -> V_60 - V_58 < ( 1 << 31 ) )
|| ! V_21 -> V_59 ) )
F_29 ( & V_21 -> V_50 ) ;
V_21 -> V_60 = V_58 ;
V_21 -> V_59 = true ;
} else {
V_21 -> V_59 = false ;
}
return 0 ;
}
static void F_30 ( struct V_37 * V_38 )
{
F_31 () ;
}
void F_32 ( struct V_20 * V_21 , int V_65 ,
bool V_66 )
{
F_33 ( & V_21 -> V_38 , V_65 ,
( V_66 ) ? F_30 : F_9 ) ;
}
int F_34 ( struct V_20 * V_21 ,
bool V_49 ,
bool V_56 , bool V_57 , T_1 V_58 )
{
struct V_33 * V_34 = V_21 -> V_34 ;
int V_55 = 0 ;
int V_24 ;
F_28 ( & V_34 -> V_64 ) ;
V_24 = F_24 ( V_21 , V_49 , V_56 , V_57 ,
V_58 ) ;
if ( F_35 ( V_24 == 0 ) )
V_55 = F_22 ( V_21 ) ;
F_27 ( & V_34 -> V_64 ) ;
F_32 ( V_21 , V_55 , true ) ;
return V_24 ;
}
void F_36 ( struct V_20 * V_21 )
{
F_19 ( V_21 ) ;
F_37 ( & V_21 -> V_51 , 0 ) ;
F_29 ( & V_21 -> V_50 ) ;
}
void F_38 ( struct V_20 * V_21 )
{
struct V_33 * V_34 = V_21 -> V_34 ;
F_28 ( & V_34 -> V_64 ) ;
F_36 ( V_21 ) ;
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
if ( F_25 ( V_21 -> V_46 == NULL ) )
V_24 = - V_79 ;
break;
case V_80 :
V_21 -> V_46 = V_7 -> V_75 -> V_76 ( V_7 , V_21 -> V_26 << V_77 ,
V_68 | V_81 ,
V_34 -> V_78 ) ;
if ( F_25 ( V_21 -> V_46 == NULL ) ) {
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
bool V_85 , bool V_86 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
bool V_87 = F_42 ( V_7 , & V_21 -> V_25 ) ;
bool V_88 = F_42 ( V_7 , V_25 ) ;
struct V_8 * V_89 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
struct V_8 * V_90 = & V_7 -> V_9 [ V_25 -> V_2 ] ;
int V_24 = 0 ;
if ( V_87 || V_88 ||
( ( V_25 -> V_23 & V_21 -> V_25 . V_23 & V_91 ) == 0 ) ) {
V_24 = F_43 ( V_89 , true ) ;
if ( F_25 ( V_24 != 0 ) )
goto V_92;
F_44 ( V_21 ) ;
F_45 ( V_89 ) ;
}
if ( ! ( V_90 -> V_1 & V_93 ) ) {
if ( V_21 -> V_46 == NULL ) {
bool V_94 = ! ( V_89 -> V_1 & V_93 ) ;
V_24 = F_39 ( V_21 , V_94 ) ;
if ( V_24 )
goto V_92;
}
V_24 = F_46 ( V_21 -> V_46 , V_25 -> V_23 ) ;
if ( V_24 )
goto V_92;
if ( V_25 -> V_2 != V_16 ) {
V_24 = F_47 ( V_21 -> V_46 , V_25 ) ;
if ( V_24 )
goto V_92;
}
if ( V_21 -> V_25 . V_2 == V_16 ) {
if ( V_7 -> V_75 -> V_95 )
V_7 -> V_75 -> V_95 ( V_21 , V_25 ) ;
V_21 -> V_25 = * V_25 ;
V_25 -> V_43 = NULL ;
goto V_96;
}
}
if ( V_7 -> V_75 -> V_95 )
V_7 -> V_75 -> V_95 ( V_21 , V_25 ) ;
if ( ! ( V_89 -> V_1 & V_93 ) &&
! ( V_90 -> V_1 & V_93 ) )
V_24 = F_48 ( V_21 , V_84 , V_85 , V_86 , V_25 ) ;
else if ( V_7 -> V_75 -> V_97 )
V_24 = V_7 -> V_75 -> V_97 ( V_21 , V_84 , V_49 ,
V_85 , V_86 , V_25 ) ;
else
V_24 = F_49 ( V_21 , V_84 , V_85 , V_86 , V_25 ) ;
if ( V_24 ) {
if ( V_7 -> V_75 -> V_95 ) {
struct V_83 V_98 = * V_25 ;
* V_25 = V_21 -> V_25 ;
V_21 -> V_25 = V_98 ;
V_7 -> V_75 -> V_95 ( V_21 , V_25 ) ;
V_21 -> V_25 = * V_25 ;
}
goto V_92;
}
V_96:
if ( V_21 -> V_99 ) {
V_24 = V_7 -> V_75 -> V_100 ( V_7 , V_21 -> V_25 . V_23 ) ;
if ( V_24 )
F_3 ( L_12 ) ;
V_21 -> V_99 = false ;
}
if ( V_21 -> V_25 . V_43 ) {
V_21 -> V_101 = ( V_21 -> V_25 . V_102 << V_77 ) +
V_7 -> V_9 [ V_21 -> V_25 . V_2 ] . V_12 ;
V_21 -> V_103 = V_21 -> V_25 . V_23 ;
} else
V_21 -> V_101 = 0 ;
return 0 ;
V_92:
V_90 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
if ( ( V_90 -> V_1 & V_93 ) && V_21 -> V_46 ) {
F_50 ( V_21 -> V_46 ) ;
F_12 ( V_21 -> V_46 ) ;
V_21 -> V_46 = NULL ;
}
return V_24 ;
}
static void F_51 ( struct V_20 * V_21 )
{
if ( V_21 -> V_7 -> V_75 -> V_95 )
V_21 -> V_7 -> V_75 -> V_95 ( V_21 , NULL ) ;
if ( V_21 -> V_46 ) {
F_50 ( V_21 -> V_46 ) ;
F_12 ( V_21 -> V_46 ) ;
V_21 -> V_46 = NULL ;
}
F_52 ( V_21 , & V_21 -> V_25 ) ;
F_37 ( & V_21 -> V_51 , 0 ) ;
F_53 () ;
F_29 ( & V_21 -> V_50 ) ;
}
static void F_54 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_33 * V_34 = V_21 -> V_34 ;
struct V_104 * V_75 ;
void * V_42 = NULL ;
void * V_105 ;
int V_55 ;
int V_24 ;
F_28 ( & V_7 -> V_106 ) ;
( void ) F_55 ( V_21 , false , false , true ) ;
if ( ! V_21 -> V_42 ) {
F_28 ( & V_34 -> V_64 ) ;
V_24 = F_24 ( V_21 , false , true , false , 0 ) ;
if ( F_25 ( V_24 == - V_63 ) )
goto V_107;
F_27 ( & V_7 -> V_106 ) ;
V_55 = F_22 ( V_21 ) ;
F_27 ( & V_34 -> V_64 ) ;
F_51 ( V_21 ) ;
F_32 ( V_21 , V_55 , true ) ;
return;
} else {
F_28 ( & V_34 -> V_64 ) ;
}
V_107:
V_75 = V_7 -> V_75 ;
if ( V_21 -> V_42 )
V_42 = V_75 -> V_108 ( V_21 -> V_42 ) ;
V_105 = V_21 -> V_105 ;
F_21 ( & V_21 -> V_38 ) ;
F_20 ( & V_21 -> V_45 , & V_7 -> V_45 ) ;
F_27 ( & V_34 -> V_64 ) ;
F_27 ( & V_7 -> V_106 ) ;
if ( V_42 ) {
V_75 -> V_109 ( V_42 , V_105 ) ;
V_75 -> V_110 ( & V_42 ) ;
}
F_56 ( & V_7 -> V_111 ,
( ( V_112 / 100 ) < 1 ) ? 1 : V_112 / 100 ) ;
}
static int F_57 ( struct V_20 * V_21 ,
bool V_49 ,
bool V_85 ,
bool V_86 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_33 * V_34 = V_21 -> V_34 ;
int V_55 ;
int V_24 = 0 ;
V_113:
F_28 ( & V_7 -> V_106 ) ;
V_24 = F_55 ( V_21 , false , V_49 , V_86 ) ;
F_27 ( & V_7 -> V_106 ) ;
if ( F_25 ( V_24 != 0 ) )
return V_24 ;
F_28 ( & V_34 -> V_64 ) ;
if ( F_25 ( F_11 ( & V_21 -> V_45 ) ) ) {
F_27 ( & V_34 -> V_64 ) ;
return 0 ;
}
V_24 = F_24 ( V_21 , V_49 ,
V_85 , false , 0 ) ;
if ( F_25 ( V_24 != 0 ) ) {
F_27 ( & V_34 -> V_64 ) ;
return V_24 ;
}
if ( F_25 ( V_21 -> V_42 ) ) {
F_37 ( & V_21 -> V_51 , 0 ) ;
F_29 ( & V_21 -> V_50 ) ;
F_27 ( & V_34 -> V_64 ) ;
goto V_113;
}
V_55 = F_22 ( V_21 ) ;
F_23 ( & V_21 -> V_45 ) ;
++ V_55 ;
F_27 ( & V_34 -> V_64 ) ;
F_51 ( V_21 ) ;
F_32 ( V_21 , V_55 , true ) ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 , bool V_114 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
struct V_20 * V_115 = NULL ;
int V_24 = 0 ;
F_28 ( & V_34 -> V_64 ) ;
if ( F_11 ( & V_7 -> V_45 ) )
goto V_116;
V_115 = F_59 ( & V_7 -> V_45 ,
struct V_20 , V_45 ) ;
F_21 ( & V_115 -> V_38 ) ;
for (; ; ) {
struct V_20 * V_117 = NULL ;
if ( V_115 -> V_45 . V_118 != & V_7 -> V_45 ) {
V_117 = F_59 ( & V_115 -> V_45 ,
struct V_20 , V_45 ) ;
F_21 ( & V_117 -> V_38 ) ;
}
F_27 ( & V_34 -> V_64 ) ;
V_24 = F_57 ( V_115 , false , ! V_114 ,
! V_114 ) ;
F_60 ( & V_115 -> V_38 , F_9 ) ;
V_115 = V_117 ;
if ( V_24 || ! V_115 )
goto V_119;
F_28 ( & V_34 -> V_64 ) ;
if ( F_11 ( & V_115 -> V_45 ) )
break;
}
V_116:
F_27 ( & V_34 -> V_64 ) ;
V_119:
if ( V_115 )
F_60 ( & V_115 -> V_38 , F_9 ) ;
return V_24 ;
}
static void F_61 ( struct V_120 * V_121 )
{
struct V_6 * V_7 =
F_6 ( V_121 , struct V_6 , V_111 . V_121 ) ;
if ( F_58 ( V_7 , false ) ) {
F_56 ( & V_7 -> V_111 ,
( ( V_112 / 100 ) < 1 ) ? 1 : V_112 / 100 ) ;
}
}
static void F_62 ( struct V_37 * V_37 )
{
struct V_20 * V_21 =
F_6 ( V_37 , struct V_20 , V_37 ) ;
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
if ( F_35 ( V_21 -> V_122 != NULL ) ) {
F_63 ( & V_21 -> V_123 , & V_7 -> V_124 ) ;
F_64 ( V_21 -> V_122 ) ;
V_21 -> V_122 = NULL ;
}
F_65 ( & V_7 -> V_125 ) ;
F_43 ( V_9 , false ) ;
F_66 ( V_21 ) ;
F_45 ( V_9 ) ;
F_54 ( V_21 ) ;
F_60 ( & V_21 -> V_38 , F_9 ) ;
F_67 ( & V_7 -> V_125 ) ;
}
void F_68 ( struct V_20 * * V_126 )
{
struct V_20 * V_21 = * V_126 ;
struct V_6 * V_7 = V_21 -> V_7 ;
* V_126 = NULL ;
F_67 ( & V_7 -> V_125 ) ;
F_60 ( & V_21 -> V_37 , F_62 ) ;
F_65 ( & V_7 -> V_125 ) ;
}
int F_69 ( struct V_6 * V_7 )
{
return F_70 ( & V_7 -> V_111 ) ;
}
void F_71 ( struct V_6 * V_7 , int V_127 )
{
if ( V_127 )
F_56 ( & V_7 -> V_111 ,
( ( V_112 / 100 ) < 1 ) ? 1 : V_112 / 100 ) ;
}
static int F_72 ( struct V_20 * V_21 , bool V_49 ,
bool V_85 , bool V_86 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_83 V_128 ;
struct V_22 V_23 ;
int V_24 = 0 ;
F_28 ( & V_7 -> V_106 ) ;
V_24 = F_55 ( V_21 , false , V_49 , V_86 ) ;
F_27 ( & V_7 -> V_106 ) ;
if ( F_25 ( V_24 != 0 ) ) {
if ( V_24 != - V_129 ) {
F_3 ( L_13 ) ;
}
goto V_119;
}
F_10 ( ! F_7 ( & V_21 -> V_51 ) ) ;
V_128 = V_21 -> V_25 ;
V_128 . V_43 = NULL ;
V_128 . V_130 . V_131 = false ;
V_128 . V_130 . V_132 = 0 ;
V_23 . V_133 = 0 ;
V_23 . V_134 = 0 ;
V_23 . V_27 = 0 ;
V_23 . V_135 = 0 ;
V_7 -> V_75 -> V_136 ( V_21 , & V_23 ) ;
V_24 = F_73 ( V_21 , & V_23 , & V_128 , V_49 ,
V_85 , V_86 ) ;
if ( V_24 ) {
if ( V_24 != - V_129 ) {
F_3 ( L_14 ,
V_21 ) ;
F_4 ( V_21 , & V_23 ) ;
}
goto V_119;
}
V_24 = F_41 ( V_21 , & V_128 , true , V_49 ,
V_85 , V_86 ) ;
if ( V_24 ) {
if ( V_24 != - V_129 )
F_3 ( L_15 ) ;
F_52 ( V_21 , & V_128 ) ;
goto V_119;
}
V_21 -> V_99 = true ;
V_119:
return V_24 ;
}
static int F_74 ( struct V_6 * V_7 ,
T_1 V_2 ,
bool V_49 , bool V_85 ,
bool V_86 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
struct V_20 * V_21 ;
int V_24 , V_55 = 0 ;
V_113:
F_28 ( & V_34 -> V_64 ) ;
if ( F_11 ( & V_9 -> V_44 ) ) {
F_27 ( & V_34 -> V_64 ) ;
return - V_63 ;
}
V_21 = F_59 ( & V_9 -> V_44 , struct V_20 , V_44 ) ;
F_21 ( & V_21 -> V_38 ) ;
if ( ! F_11 ( & V_21 -> V_45 ) ) {
F_27 ( & V_34 -> V_64 ) ;
V_24 = F_57 ( V_21 , V_49 ,
V_85 , V_86 ) ;
F_60 ( & V_21 -> V_38 , F_9 ) ;
if ( F_35 ( V_24 == 0 || V_24 == - V_129 ) )
return V_24 ;
goto V_113;
}
V_24 = F_24 ( V_21 , false , V_85 , false , 0 ) ;
if ( F_25 ( V_24 == - V_63 ) ) {
F_27 ( & V_34 -> V_64 ) ;
if ( F_35 ( ! V_86 ) )
V_24 = F_16 ( V_21 , V_49 ) ;
F_60 ( & V_21 -> V_38 , F_9 ) ;
if ( F_25 ( V_24 != 0 ) )
return V_24 ;
goto V_113;
}
V_55 = F_22 ( V_21 ) ;
F_27 ( & V_34 -> V_64 ) ;
F_10 ( V_24 != 0 ) ;
F_32 ( V_21 , V_55 , true ) ;
V_24 = F_72 ( V_21 , V_49 , V_85 , V_86 ) ;
F_38 ( V_21 ) ;
F_60 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
void F_52 ( struct V_20 * V_21 , struct V_83 * V_25 )
{
struct V_8 * V_9 = & V_21 -> V_7 -> V_9 [ V_25 -> V_2 ] ;
if ( V_25 -> V_43 )
(* V_9 -> V_17 -> V_137 )( V_9 , V_25 ) ;
}
static int F_75 ( struct V_20 * V_21 ,
T_1 V_2 ,
struct V_22 * V_23 ,
struct V_83 * V_25 ,
bool V_49 ,
bool V_85 ,
bool V_86 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
int V_24 ;
do {
V_24 = (* V_9 -> V_17 -> V_138 )( V_9 , V_21 , V_23 , V_25 ) ;
if ( F_25 ( V_24 != 0 ) )
return V_24 ;
if ( V_25 -> V_43 )
break;
V_24 = F_74 ( V_7 , V_2 , V_49 ,
V_85 , V_86 ) ;
if ( F_25 ( V_24 != 0 ) )
return V_24 ;
} while ( 1 );
if ( V_25 -> V_43 == NULL )
return - V_79 ;
V_25 -> V_2 = V_2 ;
return 0 ;
}
static T_1 F_76 ( struct V_8 * V_9 ,
T_1 V_103 ,
T_1 V_139 )
{
T_1 V_140 = V_139 & V_91 ;
T_1 V_141 = V_139 & ~ V_91 ;
if ( ( V_103 & V_140 ) != 0 )
V_141 |= ( V_103 & V_140 ) ;
else if ( ( V_9 -> V_15 & V_140 ) != 0 )
V_141 |= V_9 -> V_15 ;
else if ( ( V_142 & V_140 ) != 0 )
V_141 |= V_142 ;
else if ( ( V_143 & V_140 ) != 0 )
V_141 |= V_143 ;
else if ( ( V_144 & V_140 ) != 0 )
V_141 |= V_144 ;
return V_141 ;
}
static bool F_77 ( struct V_8 * V_9 ,
T_1 V_2 ,
T_1 V_139 ,
T_1 * V_145 )
{
T_1 V_146 = F_8 ( V_2 ) ;
if ( ( V_146 & V_139 & V_147 ) == 0 )
return false ;
if ( ( V_139 & V_9 -> V_14 ) == 0 )
return false ;
V_146 |= ( V_139 & V_9 -> V_14 ) ;
* V_145 = V_146 ;
return true ;
}
int F_73 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_83 * V_25 ,
bool V_49 , bool V_85 ,
bool V_86 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 ;
T_1 V_2 = V_16 ;
T_1 V_146 = 0 ;
bool V_148 = false ;
bool V_149 = false ;
bool V_150 = false ;
int V_3 , V_24 ;
V_25 -> V_43 = NULL ;
for ( V_3 = 0 ; V_3 < V_23 -> V_27 ; ++ V_3 ) {
V_24 = F_1 ( V_23 -> V_23 [ V_3 ] ,
& V_2 ) ;
if ( V_24 )
return V_24 ;
V_9 = & V_7 -> V_9 [ V_2 ] ;
V_149 = F_77 ( V_9 ,
V_2 ,
V_23 -> V_23 [ V_3 ] ,
& V_146 ) ;
if ( ! V_149 )
continue;
V_146 = F_76 ( V_9 , V_21 -> V_25 . V_23 ,
V_146 ) ;
F_78 ( & V_146 , V_23 -> V_23 [ V_3 ] ,
~ V_151 ) ;
if ( V_2 == V_16 )
break;
if ( V_9 -> V_10 && V_9 -> V_11 ) {
V_148 = true ;
V_24 = (* V_9 -> V_17 -> V_138 )( V_9 , V_21 , V_23 , V_25 ) ;
if ( F_25 ( V_24 ) )
return V_24 ;
}
if ( V_25 -> V_43 )
break;
}
if ( ( V_149 && ( V_2 == V_16 ) ) || V_25 -> V_43 ) {
V_25 -> V_2 = V_2 ;
V_25 -> V_23 = V_146 ;
return 0 ;
}
if ( ! V_148 )
return - V_5 ;
for ( V_3 = 0 ; V_3 < V_23 -> V_135 ; ++ V_3 ) {
V_24 = F_1 ( V_23 -> V_152 [ V_3 ] ,
& V_2 ) ;
if ( V_24 )
return V_24 ;
V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( ! V_9 -> V_10 )
continue;
if ( ! F_77 ( V_9 ,
V_2 ,
V_23 -> V_152 [ V_3 ] ,
& V_146 ) )
continue;
V_146 = F_76 ( V_9 , V_21 -> V_25 . V_23 ,
V_146 ) ;
F_78 ( & V_146 , V_23 -> V_152 [ V_3 ] ,
~ V_151 ) ;
if ( V_2 == V_16 ) {
V_25 -> V_2 = V_2 ;
V_25 -> V_23 = V_146 ;
V_25 -> V_43 = NULL ;
return 0 ;
}
V_24 = F_75 ( V_21 , V_2 , V_23 , V_25 ,
V_49 , V_85 , V_86 ) ;
if ( V_24 == 0 && V_25 -> V_43 ) {
V_25 -> V_23 = V_146 ;
return 0 ;
}
if ( V_24 == - V_129 )
V_150 = true ;
}
V_24 = ( V_150 ) ? - V_129 : - V_79 ;
return V_24 ;
}
int F_79 ( struct V_20 * V_21 , bool V_56 )
{
if ( ( F_7 ( & V_21 -> V_41 ) > 0 ) && V_56 )
return - V_63 ;
return F_17 ( V_21 -> V_50 ,
F_7 ( & V_21 -> V_41 ) == 0 ) ;
}
int F_80 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
bool V_49 , bool V_85 ,
bool V_86 )
{
int V_24 = 0 ;
struct V_83 V_25 ;
struct V_6 * V_7 = V_21 -> V_7 ;
F_10 ( ! F_7 ( & V_21 -> V_51 ) ) ;
F_28 ( & V_7 -> V_106 ) ;
V_24 = F_55 ( V_21 , false , V_49 , V_86 ) ;
F_27 ( & V_7 -> V_106 ) ;
if ( V_24 )
return V_24 ;
V_25 . V_26 = V_21 -> V_26 ;
V_25 . V_13 = V_25 . V_26 << V_77 ;
V_25 . V_153 = V_21 -> V_25 . V_153 ;
V_25 . V_130 . V_131 = false ;
V_25 . V_130 . V_132 = 0 ;
V_24 = F_73 ( V_21 , V_23 , & V_25 , V_49 , V_85 , V_86 ) ;
if ( V_24 )
goto V_116;
V_24 = F_41 ( V_21 , & V_25 , false , V_49 , V_85 , V_86 ) ;
V_116:
if ( V_24 && V_25 . V_43 )
F_52 ( V_21 , & V_25 ) ;
return V_24 ;
}
static int F_81 ( struct V_22 * V_23 ,
struct V_83 * V_25 )
{
int V_3 ;
if ( V_25 -> V_43 && V_23 -> V_134 != 0 &&
( V_25 -> V_102 < V_23 -> V_133 ||
V_25 -> V_102 + V_25 -> V_26 > V_23 -> V_134 ) )
return - 1 ;
for ( V_3 = 0 ; V_3 < V_23 -> V_27 ; V_3 ++ ) {
if ( ( V_23 -> V_23 [ V_3 ] & V_25 -> V_23 &
V_91 ) &&
( V_23 -> V_23 [ V_3 ] & V_25 -> V_23 &
V_147 ) )
return V_3 ;
}
return - 1 ;
}
int F_82 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
bool V_49 , bool V_85 ,
bool V_86 )
{
int V_24 ;
F_10 ( ! F_7 ( & V_21 -> V_51 ) ) ;
if ( V_23 -> V_134 || V_23 -> V_133 )
if ( V_23 -> V_133 > V_23 -> V_134 ||
( V_23 -> V_134 - V_23 -> V_133 ) < V_21 -> V_26 )
return - V_5 ;
V_24 = F_81 ( V_23 , & V_21 -> V_25 ) ;
if ( V_24 < 0 ) {
V_24 = F_80 ( V_21 , V_23 , V_49 , V_85 , V_86 ) ;
if ( V_24 )
return V_24 ;
} else {
F_78 ( & V_21 -> V_25 . V_23 , V_23 -> V_23 [ V_24 ] ,
~ V_151 ) ;
}
if ( V_21 -> V_25 . V_2 == V_16 && V_21 -> V_46 == NULL ) {
V_24 = F_39 ( V_21 , true ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
int F_83 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
F_10 ( ( V_23 -> V_133 || V_23 -> V_134 ) &&
( V_21 -> V_25 . V_26 > ( V_23 -> V_134 - V_23 -> V_133 ) ) ) ;
return 0 ;
}
int F_84 ( struct V_6 * V_7 ,
struct V_20 * V_21 ,
unsigned long V_13 ,
enum V_154 type ,
struct V_22 * V_23 ,
T_1 V_153 ,
unsigned long V_155 ,
bool V_49 ,
struct V_156 * V_157 ,
T_3 V_39 ,
struct V_158 * V_82 ,
void (* V_47) ( struct V_20 * ) )
{
int V_24 = 0 ;
unsigned long V_26 ;
struct V_159 * V_48 = V_7 -> V_34 -> V_48 ;
V_24 = F_85 ( V_48 , V_39 , false , false ) ;
if ( V_24 ) {
F_3 ( L_16 ) ;
if ( V_47 )
(* V_47)( V_21 ) ;
else
F_14 ( V_21 ) ;
return - V_79 ;
}
V_13 += V_155 & ~ V_160 ;
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
F_86 ( & V_21 -> V_37 ) ;
F_86 ( & V_21 -> V_38 ) ;
F_37 ( & V_21 -> V_41 , 0 ) ;
F_37 ( & V_21 -> V_51 , 1 ) ;
F_87 ( & V_21 -> V_50 ) ;
F_88 ( & V_21 -> V_44 ) ;
F_88 ( & V_21 -> V_45 ) ;
F_88 ( & V_21 -> V_53 ) ;
F_88 ( & V_21 -> V_161 ) ;
V_21 -> V_7 = V_7 ;
V_21 -> V_34 = V_7 -> V_34 ;
V_21 -> type = type ;
V_21 -> V_26 = V_26 ;
V_21 -> V_25 . V_13 = V_26 << V_77 ;
V_21 -> V_25 . V_2 = V_16 ;
V_21 -> V_25 . V_26 = V_21 -> V_26 ;
V_21 -> V_25 . V_43 = NULL ;
V_21 -> V_25 . V_153 = V_153 ;
V_21 -> V_25 . V_130 . V_131 = false ;
V_21 -> V_25 . V_130 . V_132 = 0 ;
V_21 -> V_155 = V_155 & V_160 ;
V_21 -> V_162 = 0 ;
V_21 -> V_25 . V_23 = ( V_163 | V_142 ) ;
V_21 -> V_59 = false ;
V_21 -> V_157 = V_157 ;
V_21 -> V_39 = V_39 ;
V_21 -> V_82 = V_82 ;
F_89 ( & V_21 -> V_34 -> V_36 ) ;
V_24 = F_83 ( V_21 , V_23 ) ;
if ( F_25 ( V_24 != 0 ) )
goto V_92;
if ( V_21 -> type == V_72 ||
V_21 -> type == V_80 ) {
V_24 = F_90 ( V_21 ) ;
if ( V_24 )
goto V_92;
}
V_24 = F_82 ( V_21 , V_23 , V_49 , false , false ) ;
if ( V_24 )
goto V_92;
F_38 ( V_21 ) ;
return 0 ;
V_92:
F_38 ( V_21 ) ;
F_68 ( & V_21 ) ;
return V_24 ;
}
T_3 F_91 ( struct V_6 * V_7 ,
unsigned long V_164 ,
unsigned V_165 )
{
unsigned V_166 = ( F_92 ( V_164 ) ) >> V_77 ;
T_3 V_13 = 0 ;
V_13 += F_93 ( V_165 ) ;
V_13 += F_92 ( V_166 * sizeof( void * ) ) ;
V_13 += F_93 ( sizeof( struct V_167 ) ) ;
return V_13 ;
}
T_3 F_94 ( struct V_6 * V_7 ,
unsigned long V_164 ,
unsigned V_165 )
{
unsigned V_166 = ( F_92 ( V_164 ) ) >> V_77 ;
T_3 V_13 = 0 ;
V_13 += F_93 ( V_165 ) ;
V_13 += F_92 ( V_166 * sizeof( void * ) ) ;
V_13 += F_92 ( V_166 * sizeof( V_168 ) ) ;
V_13 += F_93 ( sizeof( struct V_169 ) ) ;
return V_13 ;
}
int F_95 ( struct V_6 * V_7 ,
unsigned long V_13 ,
enum V_154 type ,
struct V_22 * V_23 ,
T_1 V_153 ,
unsigned long V_155 ,
bool V_49 ,
struct V_156 * V_157 ,
struct V_20 * * V_126 )
{
struct V_20 * V_21 ;
T_3 V_39 ;
int V_24 ;
V_21 = F_96 ( sizeof( * V_21 ) , V_170 ) ;
if ( F_25 ( V_21 == NULL ) )
return - V_79 ;
V_39 = F_91 ( V_7 , V_13 , sizeof( struct V_20 ) ) ;
V_24 = F_84 ( V_7 , V_21 , V_13 , type , V_23 , V_153 ,
V_155 , V_49 ,
V_157 , V_39 , NULL , NULL ) ;
if ( F_35 ( V_24 == 0 ) )
* V_126 = V_21 ;
return V_24 ;
}
static int F_97 ( struct V_6 * V_7 ,
unsigned V_2 , bool V_171 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
struct V_33 * V_34 = V_7 -> V_34 ;
int V_24 ;
F_28 ( & V_34 -> V_64 ) ;
while ( ! F_11 ( & V_9 -> V_44 ) ) {
F_27 ( & V_34 -> V_64 ) ;
V_24 = F_74 ( V_7 , V_2 , false , false , false ) ;
if ( V_24 ) {
if ( V_171 ) {
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
int F_98 ( struct V_6 * V_7 , unsigned V_2 )
{
struct V_8 * V_9 ;
int V_24 = - V_5 ;
if ( V_2 >= V_172 ) {
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
F_97 ( V_7 , V_2 , false ) ;
V_24 = (* V_9 -> V_17 -> V_173 )( V_9 ) ;
}
return V_24 ;
}
int F_99 ( struct V_6 * V_7 , unsigned V_2 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( V_2 == 0 || V_2 >= V_172 ) {
F_3 ( L_21 , V_2 ) ;
return - V_5 ;
}
if ( ! V_9 -> V_10 ) {
F_3 ( L_22 , V_2 ) ;
return 0 ;
}
return F_97 ( V_7 , V_2 , true ) ;
}
int F_100 ( struct V_6 * V_7 , unsigned type ,
unsigned long V_174 )
{
int V_24 = - V_5 ;
struct V_8 * V_9 ;
F_10 ( type >= V_172 ) ;
V_9 = & V_7 -> V_9 [ type ] ;
F_10 ( V_9 -> V_10 ) ;
V_9 -> V_175 = true ;
V_9 -> V_176 = false ;
F_101 ( & V_9 -> V_177 ) ;
F_88 ( & V_9 -> V_161 ) ;
V_24 = V_7 -> V_75 -> V_178 ( V_7 , type , V_9 ) ;
if ( V_24 )
return V_24 ;
V_9 -> V_7 = V_7 ;
V_24 = 0 ;
if ( type != V_16 ) {
V_24 = (* V_9 -> V_17 -> V_179 )( V_9 , V_174 ) ;
if ( V_24 )
return V_24 ;
}
V_9 -> V_10 = true ;
V_9 -> V_11 = true ;
V_9 -> V_13 = V_174 ;
F_88 ( & V_9 -> V_44 ) ;
return 0 ;
}
static void F_102 ( struct V_28 * V_29 )
{
struct V_33 * V_34 =
F_6 ( V_29 , struct V_33 , V_29 ) ;
F_103 ( V_34 -> V_48 , & V_34 -> V_180 ) ;
F_104 ( V_34 -> V_78 ) ;
F_14 ( V_34 ) ;
}
void F_105 ( struct V_181 * V_182 )
{
struct V_33 * V_34 = V_182 -> V_183 ;
F_106 ( & V_34 -> V_29 ) ;
F_107 ( & V_34 -> V_29 ) ;
}
int F_108 ( struct V_181 * V_182 )
{
struct V_184 * V_185 =
F_6 ( V_182 , struct V_184 , V_182 ) ;
struct V_33 * V_34 = V_182 -> V_183 ;
int V_24 ;
F_101 ( & V_34 -> V_186 ) ;
F_109 ( & V_34 -> V_64 ) ;
V_34 -> V_48 = V_185 -> V_48 ;
V_34 -> V_78 = F_110 ( V_187 | V_188 ) ;
if ( F_25 ( V_34 -> V_78 == NULL ) ) {
V_24 = - V_79 ;
goto V_189;
}
F_88 ( & V_34 -> V_54 ) ;
F_88 ( & V_34 -> V_190 ) ;
F_111 ( & V_34 -> V_180 , V_191 ) ;
V_24 = F_112 ( V_34 -> V_48 , & V_34 -> V_180 ) ;
if ( F_25 ( V_24 != 0 ) ) {
F_3 ( L_23 ) ;
goto V_192;
}
F_37 ( & V_34 -> V_36 , 0 ) ;
V_24 = F_113 (
& V_34 -> V_29 , & V_193 , F_114 () , L_24 ) ;
if ( F_25 ( V_24 != 0 ) )
F_107 ( & V_34 -> V_29 ) ;
return V_24 ;
V_192:
F_104 ( V_34 -> V_78 ) ;
V_189:
F_14 ( V_34 ) ;
return V_24 ;
}
int F_115 ( struct V_6 * V_7 )
{
int V_24 = 0 ;
unsigned V_3 = V_172 ;
struct V_8 * V_9 ;
struct V_33 * V_34 = V_7 -> V_34 ;
while ( V_3 -- ) {
V_9 = & V_7 -> V_9 [ V_3 ] ;
if ( V_9 -> V_10 ) {
V_9 -> V_11 = false ;
if ( ( V_3 != V_16 ) && F_98 ( V_7 , V_3 ) ) {
V_24 = - V_63 ;
F_3 ( L_25 ,
V_3 ) ;
}
V_9 -> V_10 = false ;
}
}
F_116 ( & V_34 -> V_186 ) ;
F_117 ( & V_7 -> V_190 ) ;
F_118 ( & V_34 -> V_186 ) ;
F_70 ( & V_7 -> V_111 ) ;
while ( F_58 ( V_7 , true ) )
;
F_28 ( & V_34 -> V_64 ) ;
if ( F_11 ( & V_7 -> V_45 ) )
F_119 ( L_26 ) ;
if ( F_11 ( & V_7 -> V_9 [ 0 ] . V_44 ) )
F_119 ( L_27 ) ;
F_27 ( & V_34 -> V_64 ) ;
F_10 ( ! F_120 ( & V_7 -> V_194 ) ) ;
F_67 ( & V_7 -> V_125 ) ;
F_121 ( & V_7 -> V_194 ) ;
F_65 ( & V_7 -> V_125 ) ;
return V_24 ;
}
int F_122 ( struct V_6 * V_7 ,
struct V_33 * V_34 ,
struct V_104 * V_75 ,
T_4 V_195 ,
bool V_70 )
{
int V_24 = - V_5 ;
F_123 ( & V_7 -> V_125 ) ;
V_7 -> V_75 = V_75 ;
memset ( V_7 -> V_9 , 0 , sizeof( V_7 -> V_9 ) ) ;
V_24 = F_100 ( V_7 , V_16 , 0 ) ;
if ( F_25 ( V_24 != 0 ) )
goto V_196;
V_7 -> V_124 = V_197 ;
V_24 = F_124 ( & V_7 -> V_194 , V_195 , 0x10000000 ) ;
if ( F_25 ( V_24 != 0 ) )
goto V_198;
F_125 ( & V_7 -> V_111 , F_61 ) ;
V_7 -> V_199 = true ;
F_88 ( & V_7 -> V_45 ) ;
V_7 -> V_200 = NULL ;
V_7 -> V_34 = V_34 ;
V_7 -> V_70 = V_70 ;
V_7 -> V_60 = 0 ;
F_109 ( & V_7 -> V_106 ) ;
F_116 ( & V_34 -> V_186 ) ;
F_20 ( & V_7 -> V_190 , & V_34 -> V_190 ) ;
F_118 ( & V_34 -> V_186 ) ;
return 0 ;
V_198:
F_98 ( V_7 , 0 ) ;
V_196:
return V_24 ;
}
bool F_42 ( struct V_6 * V_7 , struct V_83 * V_25 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_25 -> V_2 ] ;
if ( ! ( V_9 -> V_1 & V_93 ) ) {
if ( V_25 -> V_2 == V_16 )
return false ;
if ( V_9 -> V_1 & V_201 )
return false ;
if ( V_25 -> V_23 & V_142 )
return false ;
}
return true ;
}
void F_44 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
T_5 V_101 = ( T_5 ) V_21 -> V_202 ;
T_5 V_203 = ( ( T_5 ) V_21 -> V_25 . V_26 ) << V_77 ;
if ( ! V_7 -> V_200 )
return;
F_126 ( V_7 -> V_200 , V_101 , V_203 , 1 ) ;
F_66 ( V_21 ) ;
}
void F_127 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_21 -> V_25 . V_2 ] ;
F_43 ( V_9 , false ) ;
F_44 ( V_21 ) ;
F_45 ( V_9 ) ;
}
static void F_128 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_204 * * V_205 = & V_7 -> V_124 . V_204 ;
struct V_204 * V_206 = NULL ;
struct V_20 * V_207 ;
unsigned long V_101 = V_21 -> V_122 -> V_102 ;
unsigned long V_208 ;
while ( * V_205 ) {
V_206 = * V_205 ;
V_207 = F_129 ( V_206 , struct V_20 , V_123 ) ;
V_208 = V_207 -> V_122 -> V_102 ;
if ( V_101 < V_208 )
V_205 = & V_206 -> V_209 ;
else if ( V_101 > V_208 )
V_205 = & V_206 -> V_210 ;
else
F_31 () ;
}
F_130 ( & V_21 -> V_123 , V_206 , V_205 ) ;
F_131 ( & V_21 -> V_123 , & V_7 -> V_124 ) ;
}
static int F_90 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
int V_24 ;
V_211:
V_24 = F_132 ( & V_7 -> V_194 ) ;
if ( F_25 ( V_24 != 0 ) )
return V_24 ;
F_67 ( & V_7 -> V_125 ) ;
V_21 -> V_122 = F_133 ( & V_7 -> V_194 ,
V_21 -> V_25 . V_26 , 0 , 0 ) ;
if ( F_25 ( V_21 -> V_122 == NULL ) ) {
V_24 = - V_79 ;
goto V_116;
}
V_21 -> V_122 = F_134 ( V_21 -> V_122 ,
V_21 -> V_25 . V_26 , 0 ) ;
if ( F_25 ( V_21 -> V_122 == NULL ) ) {
F_65 ( & V_7 -> V_125 ) ;
goto V_211;
}
F_128 ( V_21 ) ;
F_65 ( & V_7 -> V_125 ) ;
V_21 -> V_202 = ( ( T_4 ) V_21 -> V_122 -> V_102 ) << V_77 ;
return 0 ;
V_116:
F_65 ( & V_7 -> V_125 ) ;
return V_24 ;
}
int F_55 ( struct V_20 * V_21 ,
bool V_212 , bool V_49 , bool V_56 )
{
struct V_104 * V_75 = V_21 -> V_7 -> V_75 ;
struct V_6 * V_7 = V_21 -> V_7 ;
void * V_42 ;
void * V_105 ;
int V_24 = 0 ;
if ( F_35 ( V_21 -> V_42 == NULL ) )
return 0 ;
while ( V_21 -> V_42 ) {
if ( V_75 -> V_213 ( V_21 -> V_42 , V_21 -> V_105 ) ) {
void * V_214 = V_21 -> V_42 ;
V_21 -> V_42 = NULL ;
F_135 ( V_215 , & V_21 -> V_162 ) ;
F_27 ( & V_7 -> V_106 ) ;
V_75 -> V_110 ( & V_214 ) ;
F_28 ( & V_7 -> V_106 ) ;
continue;
}
if ( V_56 )
return - V_63 ;
V_42 = V_75 -> V_108 ( V_21 -> V_42 ) ;
V_105 = V_21 -> V_105 ;
F_27 ( & V_7 -> V_106 ) ;
V_24 = V_75 -> V_216 ( V_42 , V_105 ,
V_212 , V_49 ) ;
if ( F_25 ( V_24 != 0 ) ) {
V_75 -> V_110 ( & V_42 ) ;
F_28 ( & V_7 -> V_106 ) ;
return V_24 ;
}
F_28 ( & V_7 -> V_106 ) ;
if ( F_35 ( V_21 -> V_42 == V_42 &&
V_21 -> V_105 == V_105 ) ) {
void * V_214 = V_21 -> V_42 ;
V_21 -> V_42 = NULL ;
F_135 ( V_215 ,
& V_21 -> V_162 ) ;
F_27 ( & V_7 -> V_106 ) ;
V_75 -> V_110 ( & V_42 ) ;
V_75 -> V_110 ( & V_214 ) ;
F_28 ( & V_7 -> V_106 ) ;
} else {
F_27 ( & V_7 -> V_106 ) ;
V_75 -> V_110 ( & V_42 ) ;
F_28 ( & V_7 -> V_106 ) ;
}
}
return 0 ;
}
int F_136 ( struct V_20 * V_21 , bool V_56 )
{
struct V_6 * V_7 = V_21 -> V_7 ;
int V_24 = 0 ;
V_24 = F_34 ( V_21 , true , V_56 , false , 0 ) ;
if ( F_25 ( V_24 != 0 ) )
return V_24 ;
F_28 ( & V_7 -> V_106 ) ;
V_24 = F_55 ( V_21 , false , true , V_56 ) ;
F_27 ( & V_7 -> V_106 ) ;
if ( F_35 ( V_24 == 0 ) )
F_89 ( & V_21 -> V_41 ) ;
F_38 ( V_21 ) ;
return V_24 ;
}
void F_137 ( struct V_20 * V_21 )
{
if ( F_138 ( & V_21 -> V_41 ) )
F_29 ( & V_21 -> V_50 ) ;
}
static int V_191 ( struct V_217 * V_180 )
{
struct V_33 * V_34 =
F_6 ( V_180 , struct V_33 , V_180 ) ;
struct V_20 * V_21 ;
int V_24 = - V_63 ;
int V_55 ;
T_1 V_218 = ( V_142 | V_163 ) ;
F_28 ( & V_34 -> V_64 ) ;
while ( V_24 == - V_63 ) {
if ( F_25 ( F_11 ( & V_34 -> V_54 ) ) ) {
F_27 ( & V_34 -> V_64 ) ;
return - V_63 ;
}
V_21 = F_59 ( & V_34 -> V_54 ,
struct V_20 , V_53 ) ;
F_21 ( & V_21 -> V_38 ) ;
if ( ! F_11 ( & V_21 -> V_45 ) ) {
F_27 ( & V_34 -> V_64 ) ;
( void ) F_57 ( V_21 , false , false , false ) ;
F_60 ( & V_21 -> V_38 , F_9 ) ;
F_28 ( & V_34 -> V_64 ) ;
continue;
}
V_24 = F_24 ( V_21 , false , true , false , 0 ) ;
if ( F_25 ( V_24 == - V_63 ) ) {
F_27 ( & V_34 -> V_64 ) ;
F_16 ( V_21 , false ) ;
F_60 ( & V_21 -> V_38 , F_9 ) ;
F_28 ( & V_34 -> V_64 ) ;
}
}
F_10 ( V_24 != 0 ) ;
V_55 = F_22 ( V_21 ) ;
F_27 ( & V_34 -> V_64 ) ;
F_32 ( V_21 , V_55 , true ) ;
F_28 ( & V_21 -> V_7 -> V_106 ) ;
V_24 = F_55 ( V_21 , false , false , false ) ;
F_27 ( & V_21 -> V_7 -> V_106 ) ;
if ( F_25 ( V_24 != 0 ) )
goto V_119;
if ( ( V_21 -> V_25 . V_23 & V_218 ) != V_218 ) {
struct V_83 V_128 ;
V_128 = V_21 -> V_25 ;
V_128 . V_43 = NULL ;
V_128 . V_23 = V_163 | V_142 ;
V_128 . V_2 = V_16 ;
V_24 = F_41 ( V_21 , & V_128 , true ,
false , false , false ) ;
if ( F_25 ( V_24 != 0 ) )
goto V_119;
}
F_127 ( V_21 ) ;
if ( V_21 -> V_7 -> V_75 -> V_219 )
V_21 -> V_7 -> V_75 -> V_219 ( V_21 ) ;
V_24 = F_139 ( V_21 -> V_46 , V_21 -> V_157 ) ;
V_119:
F_37 ( & V_21 -> V_51 , 0 ) ;
F_29 ( & V_21 -> V_50 ) ;
F_60 ( & V_21 -> V_38 , F_9 ) ;
return V_24 ;
}
void F_140 ( struct V_6 * V_7 )
{
while ( V_191 ( & V_7 -> V_34 -> V_180 ) == 0 )
;
}
