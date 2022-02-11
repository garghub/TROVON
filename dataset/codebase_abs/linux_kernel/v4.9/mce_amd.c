static void F_1 ( void )
{
F_2 ( L_1 , V_1 ) ;
}
static void F_3 ( unsigned int V_2 )
{
unsigned int V_3 , V_4 , V_5 = F_4 () ;
struct V_6 * type ;
T_1 V_7 , V_8 ;
T_2 V_9 , V_10 ;
if ( V_5 )
return;
if ( F_5 ( V_5 , F_6 ( V_2 ) , & V_8 , & V_7 ) ) {
F_7 ( L_2 , V_2 ) ;
return;
}
V_9 = V_7 & V_11 ;
V_10 = ( V_7 & V_12 ) >> 16 ;
V_4 = F_8 ( V_9 , V_10 ) ;
for ( V_3 = 0 ; V_3 < F_9 ( V_13 ) ; V_3 ++ ) {
type = & V_13 [ V_3 ] ;
if ( V_4 == type -> V_4 ) {
V_14 [ V_2 ] . type = type ;
V_14 [ V_2 ] . V_15 = V_8 ;
break;
}
}
}
static inline bool F_10 ( int V_2 )
{
if ( V_16 . V_17 )
return false ;
return ( V_2 == 4 ) ;
}
static const char * F_11 ( const struct V_18 * V_19 )
{
switch ( V_19 -> V_20 ) {
case 0x00000413 :
return L_3 ;
case 0xc0000408 :
return L_4 ;
case 0xc0000409 :
return L_5 ;
default:
F_12 ( 1 , L_6 , V_19 -> V_20 ) ;
return L_7 ;
}
}
static bool F_13 ( unsigned int V_2 , T_1 V_21 )
{
if ( V_2 == 4 )
return true ;
return V_21 & F_14 ( 28 ) ;
}
static int F_15 ( struct V_18 * V_19 , int V_22 , T_1 V_23 , T_1 V_24 )
{
int V_25 = ( V_24 & V_26 ) >> 20 ;
if ( V_22 < 0 ) {
F_2 ( V_27 L_8
L_9 , V_19 -> V_5 ,
V_19 -> V_2 , V_19 -> V_28 , V_19 -> V_20 , V_24 , V_23 ) ;
return 0 ;
}
if ( V_22 != V_25 ) {
if ( V_16 . V_17 )
return 0 ;
F_2 ( V_27 L_10
L_9 ,
V_19 -> V_5 , V_22 , V_19 -> V_2 , V_19 -> V_28 , V_19 -> V_20 , V_24 , V_23 ) ;
return 0 ;
}
return 1 ;
}
static void F_16 ( void * V_29 )
{
struct V_30 * V_31 = V_29 ;
T_1 V_24 , V_23 ;
F_17 ( V_31 -> V_19 -> V_20 , V_23 , V_24 ) ;
if ( V_31 -> V_19 -> V_32 < ( V_24 & V_33 ) )
V_31 -> V_34 = 1 ;
if ( V_31 -> V_34 ) {
V_24 =
( V_24 & ~ ( V_35 | V_36 ) ) |
( V_33 - V_31 -> V_19 -> V_32 ) ;
} else if ( V_31 -> V_37 ) {
int V_38 = ( V_24 & V_33 ) +
( V_31 -> V_37 - V_31 -> V_19 -> V_32 ) ;
V_24 = ( V_24 & ~ V_35 ) |
( V_38 & V_33 ) ;
}
V_24 &= ~ V_39 ;
if ( ! V_31 -> V_19 -> V_40 )
goto V_41;
if ( V_31 -> V_42 ) {
if ( F_15 ( V_31 -> V_19 , V_31 -> V_43 , V_23 , V_24 ) ) {
V_24 &= ~ V_26 ;
V_24 |= V_31 -> V_43 << 20 ;
}
}
if ( V_31 -> V_19 -> V_44 )
V_24 |= V_45 ;
V_41:
V_24 |= V_46 ;
F_18 ( V_31 -> V_19 -> V_20 , V_23 , V_24 ) ;
}
static void F_19 ( struct V_18 * V_19 , int V_47 )
{
struct V_30 V_31 = {
. V_19 = V_19 ,
. V_42 = 1 ,
. V_43 = V_47 ,
} ;
V_19 -> V_32 = V_33 ;
F_16 ( & V_31 ) ;
}
static int F_20 ( int V_48 , int V_49 )
{
if ( V_48 < 0 && ! F_21 ( V_49 , V_50 ,
V_51 , 0 ) )
return V_49 ;
return V_48 ;
}
static int F_22 ( int V_48 , int V_49 )
{
if ( V_48 < 0 && ! F_21 ( V_49 , V_1 ,
V_51 , 0 ) )
return V_49 ;
return V_48 ;
}
static void F_23 ( struct V_52 * V_53 )
{
T_1 V_54 = 0 , V_7 = 0 ;
int V_55 = - 1 , V_56 ;
if ( F_24 ( V_57 , & V_54 , & V_7 ) )
return;
V_56 = ( V_54 & V_58 ) >> 4 ;
if ( ! ( V_54 & V_58 ) ) {
F_2 ( V_27 L_11 ) ;
V_56 = V_59 ;
V_54 = ( V_54 & ~ V_58 ) | ( V_59 << 4 ) ;
}
V_55 = F_22 ( V_55 , V_56 ) ;
if ( ( V_55 == V_56 ) &&
( V_60 != V_61 ) )
V_60 = V_61 ;
V_54 = ( V_54 & ~ V_62 ) | V_63 ;
F_18 ( V_57 , V_54 , V_7 ) ;
}
static T_1 F_25 ( unsigned int V_5 , T_1 V_64 , T_1 V_54 , T_1 V_7 ,
unsigned int V_2 , unsigned int V_28 )
{
T_1 V_65 = 0 , V_47 = 0 ;
if ( V_16 . V_17 ) {
if ( ! V_28 ) {
V_65 = F_26 ( V_2 ) ;
} else {
T_1 V_54 , V_7 ;
if ( F_5 ( V_5 , F_27 ( V_2 ) , & V_54 , & V_7 ) )
return V_65 ;
if ( ! ( V_54 & V_66 ) )
return V_65 ;
if ( ! F_5 ( V_5 , F_26 ( V_2 ) , & V_54 , & V_7 ) &&
( V_54 & V_67 ) )
V_65 = F_28 ( V_2 , V_28 - 1 ) ;
}
return V_65 ;
}
switch ( V_28 ) {
case 0 :
V_65 = V_68 . V_69 ( V_2 ) ;
break;
case 1 :
V_47 = ( ( V_54 & V_67 ) >> 21 ) ;
if ( V_47 )
V_65 = V_70 + V_47 ;
break;
default:
V_65 = ++ V_64 ;
}
return V_65 ;
}
static int
F_29 ( unsigned int V_2 , unsigned int V_28 , T_1 V_65 ,
int V_47 , T_1 V_71 )
{
unsigned int V_5 = F_4 () ;
T_1 V_72 , V_73 , V_74 ;
struct V_18 V_19 ;
int V_49 ;
if ( ! V_28 )
F_30 ( V_75 , V_5 ) |= ( 1 << V_2 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_5 = V_5 ;
V_19 . V_2 = V_2 ;
V_19 . V_28 = V_28 ;
V_19 . V_20 = V_65 ;
V_19 . V_40 = F_13 ( V_2 , V_71 ) ;
if ( ! V_19 . V_40 )
goto V_41;
V_19 . V_44 = 1 ;
if ( ! V_16 . V_17 ) {
V_49 = ( V_71 & V_26 ) >> 20 ;
goto V_76;
}
V_74 = F_27 ( V_2 ) ;
if ( ! F_24 ( V_74 , & V_72 , & V_73 ) ) {
V_73 |= F_14 ( 0 ) ;
V_73 &= ~ F_14 ( 2 ) ;
if ( ( V_72 & F_14 ( 5 ) ) && ! ( ( V_73 >> 5 ) & 0x3 ) )
V_73 |= F_14 ( 5 ) ;
F_18 ( V_74 , V_72 , V_73 ) ;
}
if ( F_24 ( V_57 , & V_72 , & V_73 ) )
goto V_77;
V_49 = ( V_72 & V_78 ) >> 12 ;
V_76:
V_47 = F_20 ( V_47 , V_49 ) ;
if ( ( V_47 == V_49 ) && ( V_79 != V_80 ) )
V_79 = V_80 ;
V_41:
F_19 ( & V_19 , V_47 ) ;
V_77:
return V_47 ;
}
void F_31 ( struct V_52 * V_53 )
{
T_1 V_54 = 0 , V_7 = 0 , V_20 = 0 ;
unsigned int V_2 , V_28 , V_5 = F_4 () ;
int V_47 = - 1 ;
for ( V_2 = 0 ; V_2 < V_81 . V_82 ; ++ V_2 ) {
if ( V_16 . V_17 )
F_3 ( V_2 ) ;
for ( V_28 = 0 ; V_28 < V_83 ; ++ V_28 ) {
V_20 = F_25 ( V_5 , V_20 , V_54 , V_7 , V_2 , V_28 ) ;
if ( ! V_20 )
break;
if ( F_24 ( V_20 , & V_54 , & V_7 ) )
break;
if ( ! ( V_7 & V_84 ) )
continue;
if ( ! ( V_7 & V_85 ) ||
( V_7 & V_86 ) )
continue;
V_47 = F_29 ( V_2 , V_28 , V_20 , V_47 , V_7 ) ;
}
}
if ( V_16 . V_87 )
F_23 ( V_53 ) ;
}
static void
F_32 ( unsigned int V_2 , bool V_88 , bool V_89 , T_3 V_69 )
{
T_1 V_90 = V_68 . V_91 ( V_2 ) ;
T_1 V_92 = V_68 . V_65 ( V_2 ) ;
struct V_93 V_94 ;
T_3 V_91 ;
F_33 ( V_88 && V_89 ) ;
if ( V_88 && V_16 . V_17 ) {
V_90 = F_34 ( V_2 ) ;
V_92 = F_35 ( V_2 ) ;
}
F_36 ( V_90 , V_91 ) ;
if ( ! ( V_91 & V_95 ) )
return;
F_37 ( & V_94 ) ;
V_94 . V_91 = V_91 ;
V_94 . V_2 = V_2 ;
if ( V_89 )
V_94 . V_69 = V_69 ;
if ( V_94 . V_91 & V_96 ) {
F_36 ( V_92 , V_94 . V_65 ) ;
if ( V_16 . V_17 ) {
T_4 V_97 = ( V_94 . V_65 >> 56 ) & 0x3f ;
V_94 . V_65 &= F_38 ( 55 , V_97 ) ;
}
}
if ( V_16 . V_17 ) {
F_36 ( F_6 ( V_2 ) , V_94 . V_98 ) ;
if ( V_94 . V_91 & V_99 )
F_36 ( F_39 ( V_2 ) , V_94 . V_100 ) ;
}
F_40 ( & V_94 ) ;
F_41 ( V_90 , 0 ) ;
}
static inline void F_42 ( void )
{
F_43 ( V_101 ) ;
V_60 () ;
}
T_5 T_6 void F_44 ( void )
{
F_45 () ;
F_42 () ;
F_46 () ;
}
T_5 T_6 void F_47 ( void )
{
F_45 () ;
F_48 ( V_1 ) ;
F_42 () ;
F_49 ( V_1 ) ;
F_46 () ;
}
static void V_61 ( void )
{
unsigned int V_2 ;
T_1 V_90 ;
T_3 V_91 ;
for ( V_2 = 0 ; V_2 < V_81 . V_82 ; ++ V_2 ) {
V_90 = ( V_16 . V_17 ) ? F_34 ( V_2 )
: V_68 . V_91 ( V_2 ) ;
F_36 ( V_90 , V_91 ) ;
if ( ! ( V_91 & V_95 ) ||
! ( V_91 & V_102 ) )
continue;
F_32 ( V_2 , true , false , 0 ) ;
break;
}
}
static void V_80 ( void )
{
T_1 V_54 = 0 , V_7 = 0 , V_20 = 0 ;
unsigned int V_2 , V_28 , V_5 = F_4 () ;
for ( V_2 = 0 ; V_2 < V_81 . V_82 ; ++ V_2 ) {
if ( ! ( F_30 ( V_75 , V_5 ) & ( 1 << V_2 ) ) )
continue;
for ( V_28 = 0 ; V_28 < V_83 ; ++ V_28 ) {
V_20 = F_25 ( V_5 , V_20 , V_54 , V_7 , V_2 , V_28 ) ;
if ( ! V_20 )
break;
if ( F_24 ( V_20 , & V_54 , & V_7 ) )
break;
if ( ! ( V_7 & V_84 ) ) {
if ( V_28 )
continue;
else
break;
}
if ( ! ( V_7 & V_85 ) ||
( V_7 & V_86 ) )
continue;
if ( V_7 & V_36 )
goto log;
}
}
return;
log:
F_32 ( V_2 , false , true , ( ( T_3 ) V_7 << 32 ) | V_54 ) ;
}
static T_7
F_50 ( struct V_18 * V_19 , const char * V_103 , T_8 V_104 )
{
struct V_30 V_31 ;
unsigned long V_49 ;
if ( ! V_19 -> V_40 )
return - V_105 ;
if ( F_51 ( V_103 , 0 , & V_49 ) < 0 )
return - V_105 ;
V_19 -> V_44 = ! ! V_49 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_19 = V_19 ;
F_52 ( V_19 -> V_5 , F_16 , & V_31 , 1 ) ;
return V_104 ;
}
static T_7
F_53 ( struct V_18 * V_19 , const char * V_103 , T_8 V_104 )
{
struct V_30 V_31 ;
unsigned long V_49 ;
if ( F_51 ( V_103 , 0 , & V_49 ) < 0 )
return - V_105 ;
if ( V_49 > V_33 )
V_49 = V_33 ;
if ( V_49 < 1 )
V_49 = 1 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_37 = V_19 -> V_32 ;
V_19 -> V_32 = V_49 ;
V_31 . V_19 = V_19 ;
F_52 ( V_19 -> V_5 , F_16 , & V_31 , 1 ) ;
return V_104 ;
}
static T_7 F_54 ( struct V_18 * V_19 , char * V_103 )
{
T_1 V_23 , V_24 ;
F_55 ( V_19 -> V_5 , V_19 -> V_20 , & V_23 , & V_24 ) ;
return sprintf ( V_103 , L_12 , ( ( V_24 & V_33 ) -
( V_33 - V_19 -> V_32 ) ) ) ;
}
static T_7 F_56 ( struct V_106 * V_107 , struct V_108 * V_109 , char * V_103 )
{
struct V_18 * V_19 = F_57 ( V_107 ) ;
struct V_110 * V_111 = F_58 ( V_109 ) ;
T_7 V_112 ;
V_112 = V_111 -> F_56 ? V_111 -> F_56 ( V_19 , V_103 ) : - V_113 ;
return V_112 ;
}
static T_7 F_59 ( struct V_106 * V_107 , struct V_108 * V_109 ,
const char * V_103 , T_8 V_114 )
{
struct V_18 * V_19 = F_57 ( V_107 ) ;
struct V_110 * V_111 = F_58 ( V_109 ) ;
T_7 V_112 ;
V_112 = V_111 -> F_59 ? V_111 -> F_59 ( V_19 , V_103 , V_114 ) : - V_113 ;
return V_112 ;
}
static const char * F_60 ( unsigned int V_2 , struct V_18 * V_19 )
{
unsigned int V_115 ;
if ( ! V_16 . V_17 ) {
if ( V_19 && V_2 == 4 )
return F_11 ( V_19 ) ;
return V_116 [ V_2 ] ;
}
if ( ! V_14 [ V_2 ] . type )
return NULL ;
V_115 = V_14 [ V_2 ] . type -> V_115 ;
if ( V_19 && V_115 == V_117 ) {
if ( V_19 -> V_28 < F_9 ( V_118 ) )
return V_118 [ V_19 -> V_28 ] ;
return NULL ;
}
snprintf ( V_119 , V_120 ,
L_13 , V_121 [ V_115 ] . V_122 ,
V_14 [ V_2 ] . V_15 ) ;
return V_119 ;
}
static int F_61 ( unsigned int V_5 , unsigned int V_2 ,
unsigned int V_28 , T_1 V_20 )
{
struct V_18 * V_19 = NULL ;
T_1 V_54 , V_7 ;
int V_123 ;
if ( ( V_2 >= V_81 . V_82 ) || ( V_28 >= V_83 ) )
return 0 ;
if ( F_5 ( V_5 , V_20 , & V_54 , & V_7 ) )
return 0 ;
if ( ! ( V_7 & V_84 ) ) {
if ( V_28 )
goto V_124;
else
return 0 ;
}
if ( ! ( V_7 & V_85 ) ||
( V_7 & V_86 ) )
goto V_124;
V_19 = F_62 ( sizeof( struct V_18 ) , V_125 ) ;
if ( ! V_19 )
return - V_126 ;
V_19 -> V_28 = V_28 ;
V_19 -> V_2 = V_2 ;
V_19 -> V_5 = V_5 ;
V_19 -> V_20 = V_20 ;
V_19 -> V_44 = 0 ;
V_19 -> V_40 = F_13 ( V_2 , V_7 ) ;
V_19 -> V_32 = V_33 ;
if ( V_19 -> V_40 ) {
V_127 . V_128 [ 2 ] = & V_44 . V_109 ;
V_19 -> V_44 = 1 ;
} else {
V_127 . V_128 [ 2 ] = NULL ;
}
F_63 ( & V_19 -> V_129 ) ;
if ( F_30 ( V_130 , V_5 ) [ V_2 ] -> V_131 ) {
F_64 ( & V_19 -> V_129 ,
& F_30 ( V_130 , V_5 ) [ V_2 ] -> V_131 -> V_129 ) ;
} else {
F_30 ( V_130 , V_5 ) [ V_2 ] -> V_131 = V_19 ;
}
V_123 = F_65 ( & V_19 -> V_107 , & V_127 ,
F_30 ( V_130 , V_5 ) [ V_2 ] -> V_107 ,
F_60 ( V_2 , V_19 ) ) ;
if ( V_123 )
goto V_132;
V_124:
V_20 = F_25 ( V_5 , V_20 , V_54 , V_7 , V_2 , ++ V_28 ) ;
if ( ! V_20 )
return 0 ;
V_123 = F_61 ( V_5 , V_2 , V_28 , V_20 ) ;
if ( V_123 )
goto V_132;
if ( V_19 )
F_66 ( & V_19 -> V_107 , V_133 ) ;
return V_123 ;
V_132:
if ( V_19 ) {
F_67 ( & V_19 -> V_107 ) ;
F_68 ( & V_19 -> V_129 ) ;
F_69 ( V_19 ) ;
}
return V_123 ;
}
static int F_70 ( struct V_134 * V_19 )
{
struct V_135 * V_136 = & V_19 -> V_131 -> V_129 ;
struct V_18 * V_137 = NULL ;
struct V_18 * V_138 = NULL ;
int V_123 = 0 ;
V_123 = F_71 ( & V_19 -> V_131 -> V_107 , V_19 -> V_107 , V_19 -> V_131 -> V_107 . V_122 ) ;
if ( V_123 )
return V_123 ;
F_72 (pos, tmp, head, miscj) {
V_123 = F_71 ( & V_137 -> V_107 , V_19 -> V_107 , V_137 -> V_107 . V_122 ) ;
if ( V_123 ) {
F_73 (pos, tmp, head, miscj)
F_74 ( & V_137 -> V_107 ) ;
return V_123 ;
}
}
return V_123 ;
}
static int F_75 ( unsigned int V_5 , unsigned int V_2 )
{
struct V_139 * V_140 = F_30 ( V_141 , V_5 ) ;
struct V_142 * V_143 = NULL ;
struct V_134 * V_19 = NULL ;
const char * V_122 = F_60 ( V_2 , NULL ) ;
int V_123 = 0 ;
if ( F_10 ( V_2 ) ) {
V_143 = F_76 ( F_77 ( V_5 ) ) ;
if ( V_143 && V_143 -> V_144 ) {
V_19 = V_143 -> V_144 ;
V_123 = F_71 ( V_19 -> V_107 , & V_140 -> V_107 , V_122 ) ;
if ( V_123 )
goto V_77;
F_30 ( V_130 , V_5 ) [ V_2 ] = V_19 ;
F_78 ( & V_19 -> V_145 ) ;
V_123 = F_70 ( V_19 ) ;
goto V_77;
}
}
V_19 = F_62 ( sizeof( struct V_134 ) , V_125 ) ;
if ( ! V_19 ) {
V_123 = - V_126 ;
goto V_77;
}
V_19 -> V_107 = F_79 ( V_122 , & V_140 -> V_107 ) ;
if ( ! V_19 -> V_107 ) {
V_123 = - V_105 ;
goto V_132;
}
F_30 ( V_130 , V_5 ) [ V_2 ] = V_19 ;
if ( F_10 ( V_2 ) ) {
F_80 ( & V_19 -> V_145 , 1 ) ;
if ( V_143 ) {
F_81 ( V_143 -> V_144 ) ;
V_143 -> V_144 = V_19 ;
}
}
V_123 = F_61 ( V_5 , V_2 , 0 , V_68 . V_69 ( V_2 ) ) ;
if ( ! V_123 )
goto V_77;
V_132:
F_69 ( V_19 ) ;
V_77:
return V_123 ;
}
static int F_82 ( unsigned int V_5 )
{
unsigned int V_2 ;
struct V_134 * * V_146 ;
int V_123 = 0 ;
V_146 = F_62 ( sizeof( struct V_134 * ) * V_81 . V_82 ,
V_125 ) ;
if ( ! V_146 )
return - V_126 ;
F_30 ( V_130 , V_5 ) = V_146 ;
for ( V_2 = 0 ; V_2 < V_81 . V_82 ; ++ V_2 ) {
if ( ! ( F_30 ( V_75 , V_5 ) & ( 1 << V_2 ) ) )
continue;
V_123 = F_75 ( V_5 , V_2 ) ;
if ( V_123 )
return V_123 ;
}
return V_123 ;
}
static void F_83 ( unsigned int V_5 ,
unsigned int V_2 )
{
struct V_18 * V_137 = NULL ;
struct V_18 * V_138 = NULL ;
struct V_134 * V_136 = F_30 ( V_130 , V_5 ) [ V_2 ] ;
if ( ! V_136 )
return;
F_72 (pos, tmp, &head->blocks->miscj, miscj) {
F_67 ( & V_137 -> V_107 ) ;
F_68 ( & V_137 -> V_129 ) ;
F_69 ( V_137 ) ;
}
F_69 ( F_30 ( V_130 , V_5 ) [ V_2 ] -> V_131 ) ;
F_30 ( V_130 , V_5 ) [ V_2 ] -> V_131 = NULL ;
}
static void F_84 ( struct V_134 * V_19 )
{
struct V_18 * V_137 = NULL ;
struct V_18 * V_138 = NULL ;
F_74 ( V_19 -> V_107 ) ;
F_72 (pos, tmp, &b->blocks->miscj, miscj)
F_74 ( & V_137 -> V_107 ) ;
}
static void F_85 ( unsigned int V_5 , int V_2 )
{
struct V_142 * V_143 ;
struct V_134 * V_19 ;
V_19 = F_30 ( V_130 , V_5 ) [ V_2 ] ;
if ( ! V_19 )
return;
if ( ! V_19 -> V_131 )
goto V_147;
if ( F_10 ( V_2 ) ) {
if ( ! F_86 ( & V_19 -> V_145 ) ) {
F_84 ( V_19 ) ;
F_30 ( V_130 , V_5 ) [ V_2 ] = NULL ;
return;
} else {
V_143 = F_76 ( F_77 ( V_5 ) ) ;
V_143 -> V_144 = NULL ;
}
}
F_83 ( V_5 , V_2 ) ;
V_147:
F_74 ( V_19 -> V_107 ) ;
F_67 ( V_19 -> V_107 ) ;
F_69 ( V_19 ) ;
F_30 ( V_130 , V_5 ) [ V_2 ] = NULL ;
}
static void F_87 ( unsigned int V_5 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_81 . V_82 ; ++ V_2 ) {
if ( ! ( F_30 ( V_75 , V_5 ) & ( 1 << V_2 ) ) )
continue;
F_85 ( V_5 , V_2 ) ;
}
F_69 ( F_30 ( V_130 , V_5 ) ) ;
}
static void
F_88 ( unsigned long V_148 , unsigned int V_5 )
{
switch ( V_148 ) {
case V_149 :
case V_150 :
F_82 ( V_5 ) ;
break;
case V_151 :
case V_152 :
F_87 ( V_5 ) ;
break;
default:
break;
}
}
static T_9 int F_89 ( void )
{
unsigned V_153 = 0 ;
F_90 (lcpu) {
int V_123 = F_82 ( V_153 ) ;
if ( V_123 )
return V_123 ;
}
V_154 = F_88 ;
return 0 ;
}
