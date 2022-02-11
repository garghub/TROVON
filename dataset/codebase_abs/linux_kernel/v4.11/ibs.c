static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 * V_5 )
{
T_2 V_6 = F_2 ( & V_2 -> V_7 ) ;
T_2 V_8 = V_2 -> V_9 ;
int V_10 = 0 ;
if ( F_3 ( V_6 <= - V_8 ) ) {
V_6 = V_8 ;
F_4 ( & V_2 -> V_7 , V_6 ) ;
V_2 -> V_11 = V_8 ;
V_10 = 1 ;
}
if ( F_3 ( V_6 < ( T_2 ) V_3 ) ) {
V_6 += V_8 ;
F_4 ( & V_2 -> V_7 , V_6 ) ;
V_2 -> V_11 = V_8 ;
V_10 = 1 ;
}
if ( V_6 > V_4 ) {
V_6 -= V_4 ;
if ( V_6 > V_4 )
V_6 = V_4 ;
else if ( V_6 < V_3 )
V_6 = V_3 ;
}
* V_5 = ( T_1 ) V_6 ;
return V_10 ;
}
static int
F_5 ( struct V_12 * V_13 , T_1 V_14 , int V_15 )
{
struct V_1 * V_2 = & V_13 -> V_16 ;
int V_17 = 64 - V_15 ;
T_1 V_18 ;
T_1 V_19 ;
V_18 = F_2 ( & V_2 -> V_20 ) ;
if ( F_6 ( & V_2 -> V_20 , V_18 ,
V_14 ) != V_18 )
return 0 ;
V_19 = ( V_14 << V_17 ) - ( V_18 << V_17 ) ;
V_19 >>= V_17 ;
F_7 ( V_19 , & V_13 -> V_21 ) ;
F_8 ( V_19 , & V_2 -> V_7 ) ;
return 1 ;
}
static struct V_22 * F_9 ( int type )
{
if ( V_23 . V_24 . type == type )
return & V_23 ;
if ( V_25 . V_24 . type == type )
return & V_25 ;
return NULL ;
}
static int F_10 ( struct V_12 * V_13 , T_1 * V_26 )
{
switch ( V_13 -> V_27 . V_28 ) {
case 0 :
return - V_29 ;
case 1 :
case 2 :
break;
default:
return - V_30 ;
}
switch ( V_13 -> V_27 . type ) {
case V_31 :
switch ( V_13 -> V_27 . V_26 ) {
case V_32 :
* V_26 = 0 ;
return 0 ;
}
break;
case V_33 :
switch ( V_13 -> V_27 . V_26 ) {
case 0x0076 :
* V_26 = 0 ;
return 0 ;
case 0x00C1 :
* V_26 = V_34 ;
return 0 ;
}
break;
default:
return - V_29 ;
}
return - V_30 ;
}
static int F_11 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_16 ;
struct V_22 * V_22 ;
T_1 V_35 , V_26 ;
int V_36 ;
V_22 = F_9 ( V_13 -> V_27 . type ) ;
if ( V_22 ) {
V_26 = V_13 -> V_27 . V_26 ;
} else {
V_22 = & V_25 ;
V_36 = F_10 ( V_13 , & V_26 ) ;
if ( V_36 )
return V_36 ;
}
if ( V_13 -> V_24 != & V_22 -> V_24 )
return - V_29 ;
if ( F_12 ( & V_13 -> V_27 ) & F_12 ( & V_37 ) )
return - V_38 ;
if ( V_26 & ~ V_22 -> V_39 )
return - V_38 ;
if ( V_2 -> V_9 ) {
if ( V_26 & V_22 -> V_40 )
return - V_38 ;
if ( ! V_13 -> V_27 . V_41 && V_2 -> V_9 & 0x0f )
return - V_38 ;
V_2 -> V_9 &= ~ 0x0FULL ;
if ( ! V_2 -> V_9 )
V_2 -> V_9 = 0x10 ;
} else {
V_35 = V_26 & V_22 -> V_40 ;
V_26 &= ~ V_22 -> V_40 ;
V_13 -> V_27 . V_9 = V_35 << 4 ;
V_2 -> V_9 = V_13 -> V_27 . V_9 ;
}
if ( ! V_2 -> V_9 )
return - V_38 ;
V_2 -> V_11 = V_2 -> V_9 ;
F_4 ( & V_2 -> V_7 , V_2 -> V_9 ) ;
V_2 -> V_42 = V_22 -> V_43 ;
V_2 -> V_26 = V_26 ;
return 0 ;
}
static int F_13 ( struct V_22 * V_22 ,
struct V_1 * V_2 , T_1 * V_8 )
{
int V_10 ;
V_10 = F_1 ( V_2 , 1 << 4 , V_22 -> V_44 , V_8 ) ;
F_4 ( & V_2 -> V_20 , 0 ) ;
return V_10 ;
}
static T_1 F_14 ( T_1 V_26 )
{
return ( V_26 & V_45 ) >> 12 ;
}
static T_1 F_15 ( T_1 V_26 )
{
T_1 V_21 = 0 ;
if ( V_26 & V_46 )
V_21 += ( V_26 & V_47 ) << 4 ;
if ( V_48 & V_49 )
V_21 += ( V_26 & V_50 ) >> 32 ;
return V_21 ;
}
static void
F_16 ( struct V_22 * V_22 , struct V_12 * V_13 ,
T_1 * V_26 )
{
T_1 V_21 = V_22 -> V_51 ( * V_26 ) ;
while ( ! F_5 ( V_13 , V_21 , 64 ) ) {
F_17 ( V_13 -> V_16 . V_42 , * V_26 ) ;
V_21 = V_22 -> V_51 ( * V_26 ) ;
}
}
static inline void F_18 ( struct V_22 * V_22 ,
struct V_1 * V_2 , T_1 V_26 )
{
F_19 ( V_2 -> V_42 , V_2 -> V_26 | V_26 | V_22 -> V_52 ) ;
}
static inline void F_20 ( struct V_22 * V_22 ,
struct V_1 * V_2 , T_1 V_26 )
{
V_26 &= ~ V_22 -> V_40 ;
F_19 ( V_2 -> V_42 , V_26 ) ;
V_26 &= ~ V_22 -> V_52 ;
F_19 ( V_2 -> V_42 , V_26 ) ;
}
static void F_21 ( struct V_12 * V_13 , int V_53 )
{
struct V_1 * V_2 = & V_13 -> V_16 ;
struct V_22 * V_22 = F_22 ( V_13 -> V_24 , struct V_22 , V_24 ) ;
struct V_54 * V_55 = F_23 ( V_22 -> V_55 ) ;
T_1 V_8 ;
if ( F_24 ( ! ( V_2 -> V_56 & V_57 ) ) )
return;
F_24 ( ! ( V_2 -> V_56 & V_58 ) ) ;
V_2 -> V_56 = 0 ;
F_13 ( V_22 , V_2 , & V_8 ) ;
F_25 ( V_59 , V_55 -> V_56 ) ;
F_26 ( V_60 , V_55 -> V_56 ) ;
F_18 ( V_22 , V_2 , V_8 >> 4 ) ;
F_27 ( V_13 ) ;
}
static void F_28 ( struct V_12 * V_13 , int V_53 )
{
struct V_1 * V_2 = & V_13 -> V_16 ;
struct V_22 * V_22 = F_22 ( V_13 -> V_24 , struct V_22 , V_24 ) ;
struct V_54 * V_55 = F_23 ( V_22 -> V_55 ) ;
T_1 V_26 ;
int V_61 ;
if ( F_29 ( V_60 , V_55 -> V_56 ) )
return;
V_61 = F_30 ( V_59 , V_55 -> V_56 ) ;
if ( ! V_61 && ( V_2 -> V_56 & V_58 ) )
return;
F_17 ( V_2 -> V_42 , V_26 ) ;
if ( V_61 ) {
F_25 ( V_62 , V_55 -> V_56 ) ;
F_20 ( V_22 , V_2 , V_26 ) ;
F_26 ( V_59 , V_55 -> V_56 ) ;
F_24 ( V_2 -> V_56 & V_57 ) ;
V_2 -> V_56 |= V_57 ;
}
if ( V_2 -> V_56 & V_58 )
return;
V_26 &= ~ V_22 -> V_63 ;
F_16 ( V_22 , V_13 , & V_26 ) ;
V_2 -> V_56 |= V_58 ;
}
static int F_31 ( struct V_12 * V_13 , int V_53 )
{
struct V_22 * V_22 = F_22 ( V_13 -> V_24 , struct V_22 , V_24 ) ;
struct V_54 * V_55 = F_23 ( V_22 -> V_55 ) ;
if ( F_29 ( V_64 , V_55 -> V_56 ) )
return - V_65 ;
V_13 -> V_16 . V_56 = V_58 | V_57 ;
V_55 -> V_13 = V_13 ;
if ( V_53 & V_66 )
F_21 ( V_13 , V_67 ) ;
return 0 ;
}
static void F_32 ( struct V_12 * V_13 , int V_53 )
{
struct V_22 * V_22 = F_22 ( V_13 -> V_24 , struct V_22 , V_24 ) ;
struct V_54 * V_55 = F_23 ( V_22 -> V_55 ) ;
if ( ! F_33 ( V_64 , V_55 -> V_56 ) )
return;
F_28 ( V_13 , V_68 ) ;
V_55 -> V_13 = NULL ;
F_27 ( V_13 ) ;
}
static void F_34 ( struct V_12 * V_13 ) { }
static int F_35 ( struct V_22 * V_22 , struct V_69 * V_70 )
{
struct V_54 * V_55 = F_23 ( V_22 -> V_55 ) ;
struct V_12 * V_13 = V_55 -> V_13 ;
struct V_1 * V_2 = & V_13 -> V_16 ;
struct V_71 V_72 ;
struct V_73 V_74 ;
struct V_69 V_75 ;
struct V_76 V_77 ;
int V_78 , V_79 , V_80 , V_81 , V_82 = 0 ;
unsigned int V_43 ;
T_1 * V_83 , * V_26 , V_8 ;
if ( ! F_30 ( V_59 , V_55 -> V_56 ) ) {
V_84:
if ( F_33 ( V_62 , V_55 -> V_56 ) )
return 1 ;
return 0 ;
}
V_43 = V_2 -> V_42 ;
V_83 = V_77 . V_75 ;
F_17 ( V_43 , * V_83 ) ;
if ( ! ( * V_83 ++ & V_22 -> V_63 ) )
goto V_84;
V_26 = & V_77 . V_75 [ 0 ] ;
F_16 ( V_22 , V_13 , V_26 ) ;
F_36 ( & V_72 , 0 , V_2 -> V_11 ) ;
if ( ! F_13 ( V_22 , V_2 , & V_8 ) )
goto V_85;
V_77 . V_86 = V_48 ;
V_79 = 1 ;
V_78 = 1 ;
V_80 = ( V_22 == & V_25 && ( V_48 & V_87 ) ) ;
if ( V_13 -> V_27 . V_88 & V_89 )
V_81 = V_22 -> V_81 ;
else if ( V_80 )
V_81 = 2 ;
else
V_81 = 1 ;
do {
F_17 ( V_43 + V_78 , * V_83 ++ ) ;
V_79 ++ ;
V_78 = F_37 ( V_22 -> V_90 ,
V_22 -> V_81 ,
V_78 + 1 ) ;
} while ( V_78 < V_81 );
if ( V_13 -> V_27 . V_88 & V_89 ) {
if ( V_48 & V_91 ) {
F_17 ( V_92 , * V_83 ++ ) ;
V_79 ++ ;
}
if ( V_48 & V_93 ) {
F_17 ( V_94 , * V_83 ++ ) ;
V_79 ++ ;
}
}
V_77 . V_79 = sizeof( T_1 ) * V_79 ;
V_75 = * V_70 ;
if ( V_80 && ( V_77 . V_75 [ 2 ] & V_95 ) ) {
V_75 . V_53 &= ~ V_96 ;
} else {
F_38 ( & V_75 , V_77 . V_75 [ 1 ] ) ;
V_75 . V_53 |= V_96 ;
}
if ( V_13 -> V_27 . V_88 & V_89 ) {
V_74 = (struct V_73 ) {
. V_97 = {
. V_79 = sizeof( V_98 ) + V_77 . V_79 ,
. V_72 = V_77 . V_72 ,
} ,
} ;
V_72 . V_74 = & V_74 ;
}
V_82 = F_39 ( V_13 , & V_72 , & V_75 ) ;
V_85:
if ( V_82 )
F_28 ( V_13 , 0 ) ;
else
F_18 ( V_22 , V_2 , V_8 >> 4 ) ;
F_27 ( V_13 ) ;
return 1 ;
}
static int
F_40 ( unsigned int V_99 , struct V_69 * V_75 )
{
T_1 V_100 = F_41 () ;
int V_101 = 0 ;
V_101 += F_35 ( & V_23 , V_75 ) ;
V_101 += F_35 ( & V_25 , V_75 ) ;
if ( V_101 )
F_42 ( V_102 ) ;
F_43 ( F_41 () - V_100 ) ;
return V_101 ;
}
static T_3 int F_44 ( struct V_22 * V_22 , char * V_103 )
{
struct V_54 T_4 * V_55 ;
int V_36 ;
V_55 = F_45 ( struct V_54 ) ;
if ( ! V_55 )
return - V_104 ;
V_22 -> V_55 = V_55 ;
if ( V_22 -> V_105 [ 0 ] ) {
memset ( & V_22 -> V_106 , 0 , sizeof( V_22 -> V_106 ) ) ;
V_22 -> V_106 . V_103 = L_1 ;
V_22 -> V_106 . V_107 = V_22 -> V_105 ;
memset ( & V_22 -> V_108 , 0 , sizeof( V_22 -> V_108 ) ) ;
V_22 -> V_108 [ 0 ] = & V_22 -> V_106 ;
V_22 -> V_24 . V_108 = V_22 -> V_108 ;
}
V_36 = F_46 ( & V_22 -> V_24 , V_103 , - 1 ) ;
if ( V_36 ) {
V_22 -> V_55 = NULL ;
F_47 ( V_55 ) ;
}
return V_36 ;
}
static T_3 void F_48 ( void )
{
struct V_109 * * V_27 = V_110 ;
F_44 ( & V_23 , L_2 ) ;
if ( V_48 & V_111 ) {
V_25 . V_39 |= V_34 ;
* V_27 ++ = & V_112 . V_27 ;
}
F_44 ( & V_25 , L_3 ) ;
F_49 ( V_113 , F_40 , 0 , L_4 ) ;
F_50 ( L_5 , V_48 ) ;
}
static T_3 void F_48 ( void ) { }
static T_3 V_98 F_51 ( void )
{
V_98 V_86 ;
unsigned int V_114 ;
if ( ! F_52 ( V_115 ) )
return 0 ;
V_114 = F_53 ( 0x80000000 ) ;
if ( V_114 < V_116 )
return V_117 ;
V_86 = F_53 ( V_116 ) ;
if ( ! ( V_86 & V_118 ) )
return V_117 ;
return V_86 ;
}
V_98 F_54 ( void )
{
return V_48 ;
}
static inline int F_55 ( int V_78 )
{
return ! F_56 ( V_78 , 0 , V_119 , 1 ) ;
}
static inline int F_57 ( int V_78 )
{
return ! F_56 ( V_78 , 0 , 0 , 1 ) ;
}
static inline int F_58 ( void )
{
int V_78 ;
T_1 V_120 ;
int V_121 = 0 ;
F_59 () ;
F_17 ( V_122 , V_120 ) ;
V_78 = V_120 & V_123 ;
if ( ! ( V_120 & V_124 ) ) {
F_60 ( V_125 L_6 ,
F_61 () , V_78 , V_122 , V_120 ) ;
goto V_85;
}
if ( ! F_55 ( V_78 ) ) {
F_60 ( V_125 L_7 ,
F_61 () , V_78 , V_122 , V_120 ) ;
goto V_85;
}
V_121 = 1 ;
V_85:
F_62 () ;
return V_121 ;
}
static int F_63 ( int V_126 )
{
struct V_127 * V_128 ;
int V_129 ;
V_98 V_130 = 0 ;
V_129 = 0 ;
V_128 = NULL ;
do {
V_128 = F_64 ( V_131 ,
V_132 ,
V_128 ) ;
if ( ! V_128 )
break;
++ V_129 ;
F_65 ( V_128 , V_133 , V_126
| V_124 ) ;
F_66 ( V_128 , V_133 , & V_130 ) ;
if ( V_130 != ( V_126 | V_124 ) ) {
F_67 ( V_128 ) ;
F_68 ( L_8 ,
V_130 ) ;
return - V_38 ;
}
} while ( 1 );
if ( ! V_129 ) {
F_68 ( L_9 ) ;
return - V_134 ;
}
return 0 ;
}
static void F_69 ( void )
{
int V_78 ;
int V_36 ;
F_59 () ;
for ( V_78 = 1 ; V_78 < V_135 ; V_78 ++ ) {
if ( F_55 ( V_78 ) )
break;
}
F_62 () ;
if ( V_78 == V_135 ) {
F_68 ( L_10 ) ;
return;
}
V_36 = F_63 ( V_78 ) ;
if ( V_36 )
goto V_85;
if ( ! F_58 () )
goto V_85;
F_50 ( L_11 , V_78 ) ;
return;
V_85:
F_59 () ;
F_57 ( V_78 ) ;
F_62 () ;
return;
}
static void F_70 ( void )
{
if ( V_136 . V_137 == 0x10 )
F_69 () ;
}
static inline int F_71 ( void )
{
T_1 V_120 ;
F_17 ( V_122 , V_120 ) ;
if ( ! ( V_120 & V_124 ) )
return - V_38 ;
return V_120 & V_123 ;
}
static void F_72 ( void )
{
int V_78 ;
V_78 = F_71 () ;
if ( V_78 < 0 )
goto V_138;
if ( ! F_56 ( V_78 , 0 , V_119 , 0 ) )
return;
V_138:
F_73 ( L_12 ,
F_61 () ) ;
}
static void F_74 ( void )
{
int V_78 ;
V_78 = F_71 () ;
if ( V_78 >= 0 )
F_56 ( V_78 , 0 , V_139 , 1 ) ;
}
static int F_75 ( unsigned int V_140 )
{
F_72 () ;
return 0 ;
}
static int F_76 ( void )
{
F_74 () ;
return 0 ;
}
static void F_77 ( void )
{
F_70 () ;
F_72 () ;
}
static void F_78 ( void )
{
F_79 ( & V_141 ) ;
}
static inline void F_78 ( void ) { }
static int F_80 ( unsigned int V_140 )
{
F_74 () ;
return 0 ;
}
static T_3 int F_81 ( void )
{
V_98 V_86 ;
V_86 = F_51 () ;
if ( ! V_86 )
return - V_134 ;
F_70 () ;
if ( ! F_58 () )
return - V_38 ;
F_78 () ;
V_48 = V_86 ;
F_82 () ;
F_83 ( V_142 ,
L_13 ,
F_75 ,
F_80 ) ;
F_48 () ;
return 0 ;
}
