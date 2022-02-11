static void F_1 ( void )
{
F_2 ( L_1 , V_1 ) ;
}
static inline bool F_3 ( int V_2 )
{
if ( V_3 . V_4 )
return false ;
return ( V_2 == 4 ) ;
}
static const char * F_4 ( const struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case 0x00000413 :
return L_2 ;
case 0xc0000408 :
return L_3 ;
case 0xc0000409 :
return L_4 ;
default:
F_5 ( 1 , L_5 , V_6 -> V_7 ) ;
return L_6 ;
}
}
static bool F_6 ( unsigned int V_2 , T_1 V_8 )
{
if ( V_2 == 4 )
return true ;
return V_8 & F_7 ( 28 ) ;
}
static int F_8 ( struct V_5 * V_6 , int V_9 , T_1 V_10 , T_1 V_11 )
{
int V_12 = ( V_11 & V_13 ) >> 20 ;
if ( V_9 < 0 ) {
F_2 ( V_14 L_7
L_8 , V_6 -> V_15 ,
V_6 -> V_2 , V_6 -> V_16 , V_6 -> V_7 , V_11 , V_10 ) ;
return 0 ;
}
if ( V_9 != V_12 ) {
if ( V_3 . V_4 )
return 0 ;
F_2 ( V_14 L_9
L_8 ,
V_6 -> V_15 , V_9 , V_6 -> V_2 , V_6 -> V_16 , V_6 -> V_7 , V_11 , V_10 ) ;
return 0 ;
}
return 1 ;
}
static void F_9 ( void * V_17 )
{
struct V_18 * V_19 = V_17 ;
T_1 V_11 , V_10 ;
F_10 ( V_19 -> V_6 -> V_7 , V_10 , V_11 ) ;
if ( V_19 -> V_6 -> V_20 < ( V_11 & V_21 ) )
V_19 -> V_22 = 1 ;
if ( V_19 -> V_22 ) {
V_11 =
( V_11 & ~ ( V_23 | V_24 ) ) |
( V_21 - V_19 -> V_6 -> V_20 ) ;
} else if ( V_19 -> V_25 ) {
int V_26 = ( V_11 & V_21 ) +
( V_19 -> V_25 - V_19 -> V_6 -> V_20 ) ;
V_11 = ( V_11 & ~ V_23 ) |
( V_26 & V_21 ) ;
}
V_11 &= ~ V_27 ;
if ( ! V_19 -> V_6 -> V_28 )
goto V_29;
if ( V_19 -> V_30 ) {
if ( F_8 ( V_19 -> V_6 , V_19 -> V_31 , V_10 , V_11 ) ) {
V_11 &= ~ V_13 ;
V_11 |= V_19 -> V_31 << 20 ;
}
}
if ( V_19 -> V_6 -> V_32 )
V_11 |= V_33 ;
V_29:
V_11 |= V_34 ;
F_11 ( V_19 -> V_6 -> V_7 , V_10 , V_11 ) ;
}
static void F_12 ( struct V_5 * V_6 , int V_35 )
{
struct V_18 V_19 = {
. V_6 = V_6 ,
. V_30 = 1 ,
. V_31 = V_35 ,
} ;
V_6 -> V_20 = V_21 ;
F_9 ( & V_19 ) ;
}
static int F_13 ( int V_36 , int V_37 )
{
if ( V_36 < 0 && ! F_14 ( V_37 , V_38 ,
V_39 , 0 ) )
return V_37 ;
return V_36 ;
}
static int F_15 ( int V_36 , int V_37 )
{
if ( V_36 < 0 && ! F_14 ( V_37 , V_1 ,
V_39 , 0 ) )
return V_37 ;
return V_36 ;
}
static void F_16 ( struct V_40 * V_41 )
{
T_1 V_42 = 0 , V_43 = 0 ;
int V_44 = - 1 , V_45 ;
if ( F_17 ( V_46 , & V_42 , & V_43 ) )
return;
V_45 = ( V_42 & V_47 ) >> 4 ;
if ( ! ( V_42 & V_47 ) ) {
F_2 ( V_14 L_10 ) ;
V_45 = V_48 ;
V_42 = ( V_42 & ~ V_47 ) | ( V_48 << 4 ) ;
}
V_44 = F_15 ( V_44 , V_45 ) ;
if ( ( V_44 == V_45 ) &&
( V_49 != V_50 ) )
V_49 = V_50 ;
V_42 = ( V_42 & ~ V_51 ) | V_52 ;
F_11 ( V_46 , V_42 , V_43 ) ;
}
static T_1 F_18 ( T_1 V_53 , T_1 V_42 , T_1 V_43 ,
unsigned int V_2 , unsigned int V_16 )
{
T_1 V_54 = 0 , V_35 = 0 ;
if ( V_3 . V_4 ) {
if ( ! V_16 ) {
V_54 = F_19 ( V_2 ) ;
} else {
T_1 V_42 , V_43 ;
if ( F_17 ( F_20 ( V_2 ) , & V_42 , & V_43 ) )
return V_54 ;
if ( ! ( V_42 & V_55 ) )
return V_54 ;
if ( ! F_17 ( F_19 ( V_2 ) , & V_42 , & V_43 ) &&
( V_42 & V_56 ) )
V_54 = F_21 ( V_2 , V_16 - 1 ) ;
}
return V_54 ;
}
switch ( V_16 ) {
case 0 :
V_54 = V_57 . V_58 ( V_2 ) ;
break;
case 1 :
V_35 = ( ( V_42 & V_56 ) >> 21 ) ;
if ( V_35 )
V_54 = V_59 + V_35 ;
break;
default:
V_54 = ++ V_53 ;
}
return V_54 ;
}
static int
F_22 ( unsigned int V_2 , unsigned int V_16 , T_1 V_54 ,
int V_35 , T_1 V_60 )
{
unsigned int V_15 = F_23 () ;
T_1 V_61 , V_62 , V_63 ;
struct V_5 V_6 ;
int V_37 ;
if ( ! V_16 )
F_24 ( V_64 , V_15 ) |= ( 1 << V_2 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_15 = V_15 ;
V_6 . V_2 = V_2 ;
V_6 . V_16 = V_16 ;
V_6 . V_7 = V_54 ;
V_6 . V_28 = F_6 ( V_2 , V_60 ) ;
if ( ! V_6 . V_28 )
goto V_29;
V_6 . V_32 = 1 ;
if ( ! V_3 . V_4 ) {
V_37 = ( V_60 & V_13 ) >> 20 ;
goto V_65;
}
V_63 = F_20 ( V_2 ) ;
if ( ! F_17 ( V_63 , & V_61 , & V_62 ) ) {
V_62 |= F_7 ( 0 ) ;
V_62 &= ~ F_7 ( 2 ) ;
F_11 ( V_63 , V_61 , V_62 ) ;
}
if ( F_17 ( V_46 , & V_61 , & V_62 ) )
goto V_66;
V_37 = ( V_61 & V_67 ) >> 12 ;
V_65:
V_35 = F_13 ( V_35 , V_37 ) ;
if ( ( V_35 == V_37 ) && ( V_68 != V_69 ) )
V_68 = V_69 ;
V_29:
F_12 ( & V_6 , V_35 ) ;
V_66:
return V_35 ;
}
void F_25 ( struct V_40 * V_41 )
{
T_1 V_42 = 0 , V_43 = 0 , V_7 = 0 ;
unsigned int V_2 , V_16 ;
int V_35 = - 1 ;
for ( V_2 = 0 ; V_2 < V_70 . V_71 ; ++ V_2 ) {
for ( V_16 = 0 ; V_16 < V_72 ; ++ V_16 ) {
V_7 = F_18 ( V_7 , V_42 , V_43 , V_2 , V_16 ) ;
if ( ! V_7 )
break;
if ( F_17 ( V_7 , & V_42 , & V_43 ) )
break;
if ( ! ( V_43 & V_73 ) )
continue;
if ( ! ( V_43 & V_74 ) ||
( V_43 & V_75 ) )
continue;
V_35 = F_22 ( V_2 , V_16 , V_7 , V_35 , V_43 ) ;
}
}
if ( V_3 . V_76 )
F_16 ( V_41 ) ;
}
static void
F_26 ( unsigned int V_2 , bool V_77 , bool V_78 , T_2 V_58 )
{
T_1 V_79 = V_57 . V_80 ( V_2 ) ;
T_1 V_81 = V_57 . V_54 ( V_2 ) ;
struct V_82 V_83 ;
T_2 V_80 ;
F_27 ( V_77 && V_78 ) ;
if ( V_77 && V_3 . V_4 ) {
V_79 = F_28 ( V_2 ) ;
V_81 = F_29 ( V_2 ) ;
}
F_30 ( V_79 , V_80 ) ;
if ( ! ( V_80 & V_84 ) )
return;
F_31 ( & V_83 ) ;
V_83 . V_80 = V_80 ;
V_83 . V_2 = V_2 ;
if ( V_78 )
V_83 . V_58 = V_58 ;
if ( V_83 . V_80 & V_85 )
F_30 ( V_81 , V_83 . V_54 ) ;
F_32 ( & V_83 ) ;
F_33 ( V_79 , 0 ) ;
}
static inline void F_34 ( void )
{
F_35 ( V_86 ) ;
V_49 () ;
}
T_3 T_4 void F_36 ( void )
{
F_37 () ;
F_34 () ;
F_38 () ;
}
T_3 T_4 void F_39 ( void )
{
F_37 () ;
F_40 ( V_1 ) ;
F_34 () ;
F_41 ( V_1 ) ;
F_38 () ;
}
static void V_50 ( void )
{
unsigned int V_2 ;
T_1 V_79 ;
T_2 V_80 ;
for ( V_2 = 0 ; V_2 < V_70 . V_71 ; ++ V_2 ) {
V_79 = ( V_3 . V_4 ) ? F_28 ( V_2 )
: V_57 . V_80 ( V_2 ) ;
F_30 ( V_79 , V_80 ) ;
if ( ! ( V_80 & V_84 ) ||
! ( V_80 & V_87 ) )
continue;
F_26 ( V_2 , true , false , 0 ) ;
break;
}
}
static void V_69 ( void )
{
T_1 V_42 = 0 , V_43 = 0 , V_7 = 0 ;
int V_15 = F_23 () ;
unsigned int V_2 , V_16 ;
for ( V_2 = 0 ; V_2 < V_70 . V_71 ; ++ V_2 ) {
if ( ! ( F_24 ( V_64 , V_15 ) & ( 1 << V_2 ) ) )
continue;
for ( V_16 = 0 ; V_16 < V_72 ; ++ V_16 ) {
V_7 = F_18 ( V_7 , V_42 , V_43 , V_2 , V_16 ) ;
if ( ! V_7 )
break;
if ( F_17 ( V_7 , & V_42 , & V_43 ) )
break;
if ( ! ( V_43 & V_73 ) ) {
if ( V_16 )
continue;
else
break;
}
if ( ! ( V_43 & V_74 ) ||
( V_43 & V_75 ) )
continue;
if ( V_43 & V_24 )
goto log;
}
}
return;
log:
F_26 ( V_2 , false , true , ( ( T_2 ) V_43 << 32 ) | V_42 ) ;
}
static T_5
F_42 ( struct V_5 * V_6 , const char * V_88 , T_6 V_89 )
{
struct V_18 V_19 ;
unsigned long V_37 ;
if ( ! V_6 -> V_28 )
return - V_90 ;
if ( F_43 ( V_88 , 0 , & V_37 ) < 0 )
return - V_90 ;
V_6 -> V_32 = ! ! V_37 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_6 = V_6 ;
F_44 ( V_6 -> V_15 , F_9 , & V_19 , 1 ) ;
return V_89 ;
}
static T_5
F_45 ( struct V_5 * V_6 , const char * V_88 , T_6 V_89 )
{
struct V_18 V_19 ;
unsigned long V_37 ;
if ( F_43 ( V_88 , 0 , & V_37 ) < 0 )
return - V_90 ;
if ( V_37 > V_21 )
V_37 = V_21 ;
if ( V_37 < 1 )
V_37 = 1 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_25 = V_6 -> V_20 ;
V_6 -> V_20 = V_37 ;
V_19 . V_6 = V_6 ;
F_44 ( V_6 -> V_15 , F_9 , & V_19 , 1 ) ;
return V_89 ;
}
static T_5 F_46 ( struct V_5 * V_6 , char * V_88 )
{
T_1 V_10 , V_11 ;
F_47 ( V_6 -> V_15 , V_6 -> V_7 , & V_10 , & V_11 ) ;
return sprintf ( V_88 , L_11 , ( ( V_11 & V_21 ) -
( V_21 - V_6 -> V_20 ) ) ) ;
}
static T_5 F_48 ( struct V_91 * V_92 , struct V_93 * V_94 , char * V_88 )
{
struct V_5 * V_6 = F_49 ( V_92 ) ;
struct V_95 * V_96 = F_50 ( V_94 ) ;
T_5 V_97 ;
V_97 = V_96 -> F_48 ? V_96 -> F_48 ( V_6 , V_88 ) : - V_98 ;
return V_97 ;
}
static T_5 F_51 ( struct V_91 * V_92 , struct V_93 * V_94 ,
const char * V_88 , T_6 V_99 )
{
struct V_5 * V_6 = F_49 ( V_92 ) ;
struct V_95 * V_96 = F_50 ( V_94 ) ;
T_5 V_97 ;
V_97 = V_96 -> F_51 ? V_96 -> F_51 ( V_6 , V_88 , V_99 ) : - V_98 ;
return V_97 ;
}
static int F_52 ( unsigned int V_15 , unsigned int V_2 ,
unsigned int V_16 , T_1 V_7 )
{
struct V_5 * V_6 = NULL ;
T_1 V_42 , V_43 ;
int V_100 ;
if ( ( V_2 >= V_70 . V_71 ) || ( V_16 >= V_72 ) )
return 0 ;
if ( F_53 ( V_15 , V_7 , & V_42 , & V_43 ) )
return 0 ;
if ( ! ( V_43 & V_73 ) ) {
if ( V_16 )
goto V_101;
else
return 0 ;
}
if ( ! ( V_43 & V_74 ) ||
( V_43 & V_75 ) )
goto V_101;
V_6 = F_54 ( sizeof( struct V_5 ) , V_102 ) ;
if ( ! V_6 )
return - V_103 ;
V_6 -> V_16 = V_16 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_15 = V_15 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_32 = 0 ;
V_6 -> V_28 = F_6 ( V_2 , V_43 ) ;
V_6 -> V_20 = V_21 ;
if ( V_6 -> V_28 ) {
V_104 . V_105 [ 2 ] = & V_32 . V_94 ;
V_6 -> V_32 = 1 ;
} else {
V_104 . V_105 [ 2 ] = NULL ;
}
F_55 ( & V_6 -> V_106 ) ;
if ( F_24 ( V_107 , V_15 ) [ V_2 ] -> V_108 ) {
F_56 ( & V_6 -> V_106 ,
& F_24 ( V_107 , V_15 ) [ V_2 ] -> V_108 -> V_106 ) ;
} else {
F_24 ( V_107 , V_15 ) [ V_2 ] -> V_108 = V_6 ;
}
V_100 = F_57 ( & V_6 -> V_92 , & V_104 ,
F_24 ( V_107 , V_15 ) [ V_2 ] -> V_92 ,
( V_2 == 4 ? F_4 ( V_6 ) : V_109 [ V_2 ] ) ) ;
if ( V_100 )
goto V_110;
V_101:
V_7 = F_18 ( V_7 , V_42 , V_43 , V_2 , ++ V_16 ) ;
if ( ! V_7 )
return 0 ;
V_100 = F_52 ( V_15 , V_2 , V_16 , V_7 ) ;
if ( V_100 )
goto V_110;
if ( V_6 )
F_58 ( & V_6 -> V_92 , V_111 ) ;
return V_100 ;
V_110:
if ( V_6 ) {
F_59 ( & V_6 -> V_92 ) ;
F_60 ( & V_6 -> V_106 ) ;
F_61 ( V_6 ) ;
}
return V_100 ;
}
static int F_62 ( struct V_112 * V_6 )
{
struct V_113 * V_114 = & V_6 -> V_108 -> V_106 ;
struct V_5 * V_115 = NULL ;
struct V_5 * V_116 = NULL ;
int V_100 = 0 ;
V_100 = F_63 ( & V_6 -> V_108 -> V_92 , V_6 -> V_92 , V_6 -> V_108 -> V_92 . V_117 ) ;
if ( V_100 )
return V_100 ;
F_64 (pos, tmp, head, miscj) {
V_100 = F_63 ( & V_115 -> V_92 , V_6 -> V_92 , V_115 -> V_92 . V_117 ) ;
if ( V_100 ) {
F_65 (pos, tmp, head, miscj)
F_66 ( & V_115 -> V_92 ) ;
return V_100 ;
}
}
return V_100 ;
}
static int F_67 ( unsigned int V_15 , unsigned int V_2 )
{
struct V_118 * V_119 = F_24 ( V_120 , V_15 ) ;
struct V_121 * V_122 = NULL ;
struct V_112 * V_6 = NULL ;
const char * V_117 = V_109 [ V_2 ] ;
int V_100 = 0 ;
if ( F_3 ( V_2 ) ) {
V_122 = F_68 ( F_69 ( V_15 ) ) ;
if ( V_122 && V_122 -> V_123 ) {
V_6 = V_122 -> V_123 ;
V_100 = F_63 ( V_6 -> V_92 , & V_119 -> V_92 , V_117 ) ;
if ( V_100 )
goto V_66;
F_24 ( V_107 , V_15 ) [ V_2 ] = V_6 ;
F_70 ( & V_6 -> V_124 ) ;
V_100 = F_62 ( V_6 ) ;
goto V_66;
}
}
V_6 = F_54 ( sizeof( struct V_112 ) , V_102 ) ;
if ( ! V_6 ) {
V_100 = - V_103 ;
goto V_66;
}
V_6 -> V_92 = F_71 ( V_117 , & V_119 -> V_92 ) ;
if ( ! V_6 -> V_92 ) {
V_100 = - V_90 ;
goto V_110;
}
F_24 ( V_107 , V_15 ) [ V_2 ] = V_6 ;
if ( F_3 ( V_2 ) ) {
F_72 ( & V_6 -> V_124 , 1 ) ;
if ( V_122 ) {
F_73 ( V_122 -> V_123 ) ;
V_122 -> V_123 = V_6 ;
}
}
V_100 = F_52 ( V_15 , V_2 , 0 , F_74 ( V_2 ) ) ;
if ( ! V_100 )
goto V_66;
V_110:
F_61 ( V_6 ) ;
V_66:
return V_100 ;
}
static int F_75 ( unsigned int V_15 )
{
unsigned int V_2 ;
struct V_112 * * V_125 ;
int V_100 = 0 ;
V_125 = F_54 ( sizeof( struct V_112 * ) * V_70 . V_71 ,
V_102 ) ;
if ( ! V_125 )
return - V_103 ;
F_24 ( V_107 , V_15 ) = V_125 ;
for ( V_2 = 0 ; V_2 < V_70 . V_71 ; ++ V_2 ) {
if ( ! ( F_24 ( V_64 , V_15 ) & ( 1 << V_2 ) ) )
continue;
V_100 = F_67 ( V_15 , V_2 ) ;
if ( V_100 )
return V_100 ;
}
return V_100 ;
}
static void F_76 ( unsigned int V_15 ,
unsigned int V_2 )
{
struct V_5 * V_115 = NULL ;
struct V_5 * V_116 = NULL ;
struct V_112 * V_114 = F_24 ( V_107 , V_15 ) [ V_2 ] ;
if ( ! V_114 )
return;
F_64 (pos, tmp, &head->blocks->miscj, miscj) {
F_59 ( & V_115 -> V_92 ) ;
F_60 ( & V_115 -> V_106 ) ;
F_61 ( V_115 ) ;
}
F_61 ( F_24 ( V_107 , V_15 ) [ V_2 ] -> V_108 ) ;
F_24 ( V_107 , V_15 ) [ V_2 ] -> V_108 = NULL ;
}
static void F_77 ( struct V_112 * V_6 )
{
struct V_5 * V_115 = NULL ;
struct V_5 * V_116 = NULL ;
F_66 ( V_6 -> V_92 ) ;
F_64 (pos, tmp, &b->blocks->miscj, miscj)
F_66 ( & V_115 -> V_92 ) ;
}
static void F_78 ( unsigned int V_15 , int V_2 )
{
struct V_121 * V_122 ;
struct V_112 * V_6 ;
V_6 = F_24 ( V_107 , V_15 ) [ V_2 ] ;
if ( ! V_6 )
return;
if ( ! V_6 -> V_108 )
goto V_126;
if ( F_3 ( V_2 ) ) {
if ( ! F_79 ( & V_6 -> V_124 ) ) {
F_77 ( V_6 ) ;
F_24 ( V_107 , V_15 ) [ V_2 ] = NULL ;
return;
} else {
V_122 = F_68 ( F_69 ( V_15 ) ) ;
V_122 -> V_123 = NULL ;
}
}
F_76 ( V_15 , V_2 ) ;
V_126:
F_66 ( V_6 -> V_92 ) ;
F_59 ( V_6 -> V_92 ) ;
F_61 ( V_6 ) ;
F_24 ( V_107 , V_15 ) [ V_2 ] = NULL ;
}
static void F_80 ( unsigned int V_15 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_70 . V_71 ; ++ V_2 ) {
if ( ! ( F_24 ( V_64 , V_15 ) & ( 1 << V_2 ) ) )
continue;
F_78 ( V_15 , V_2 ) ;
}
F_61 ( F_24 ( V_107 , V_15 ) ) ;
}
static void
F_81 ( unsigned long V_127 , unsigned int V_15 )
{
switch ( V_127 ) {
case V_128 :
case V_129 :
F_75 ( V_15 ) ;
break;
case V_130 :
case V_131 :
F_80 ( V_15 ) ;
break;
default:
break;
}
}
static T_7 int F_82 ( void )
{
unsigned V_132 = 0 ;
F_83 (lcpu) {
int V_100 = F_75 ( V_132 ) ;
if ( V_100 )
return V_100 ;
}
V_133 = F_81 ;
return 0 ;
}
