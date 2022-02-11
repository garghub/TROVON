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
F_18 ( V_22 , V_2 , V_8 >> 4 ) ;
F_26 ( V_13 ) ;
}
static void F_27 ( struct V_12 * V_13 , int V_53 )
{
struct V_1 * V_2 = & V_13 -> V_16 ;
struct V_22 * V_22 = F_22 ( V_13 -> V_24 , struct V_22 , V_24 ) ;
struct V_54 * V_55 = F_23 ( V_22 -> V_55 ) ;
T_1 V_26 ;
int V_60 ;
V_60 = F_28 ( V_59 , V_55 -> V_56 ) ;
if ( ! V_60 && ( V_2 -> V_56 & V_58 ) )
return;
F_17 ( V_2 -> V_42 , V_26 ) ;
if ( V_60 ) {
F_25 ( V_61 , V_55 -> V_56 ) ;
F_20 ( V_22 , V_2 , V_26 ) ;
F_24 ( V_2 -> V_56 & V_57 ) ;
V_2 -> V_56 |= V_57 ;
}
if ( V_2 -> V_56 & V_58 )
return;
V_26 &= ~ V_22 -> V_62 ;
F_16 ( V_22 , V_13 , & V_26 ) ;
V_2 -> V_56 |= V_58 ;
}
static int F_29 ( struct V_12 * V_13 , int V_53 )
{
struct V_22 * V_22 = F_22 ( V_13 -> V_24 , struct V_22 , V_24 ) ;
struct V_54 * V_55 = F_23 ( V_22 -> V_55 ) ;
if ( F_30 ( V_63 , V_55 -> V_56 ) )
return - V_64 ;
V_13 -> V_16 . V_56 = V_58 | V_57 ;
V_55 -> V_13 = V_13 ;
if ( V_53 & V_65 )
F_21 ( V_13 , V_66 ) ;
return 0 ;
}
static void F_31 ( struct V_12 * V_13 , int V_53 )
{
struct V_22 * V_22 = F_22 ( V_13 -> V_24 , struct V_22 , V_24 ) ;
struct V_54 * V_55 = F_23 ( V_22 -> V_55 ) ;
if ( ! F_28 ( V_63 , V_55 -> V_56 ) )
return;
F_27 ( V_13 , V_67 ) ;
V_55 -> V_13 = NULL ;
F_26 ( V_13 ) ;
}
static void F_32 ( struct V_12 * V_13 ) { }
static int F_33 ( struct V_22 * V_22 , struct V_68 * V_69 )
{
struct V_54 * V_55 = F_23 ( V_22 -> V_55 ) ;
struct V_12 * V_13 = V_55 -> V_13 ;
struct V_1 * V_2 = & V_13 -> V_16 ;
struct V_70 V_71 ;
struct V_72 V_73 ;
struct V_68 V_74 ;
struct V_75 V_76 ;
int V_77 , V_78 , V_79 , V_80 , V_81 = 0 ;
unsigned int V_43 ;
T_1 * V_82 , * V_26 , V_8 ;
if ( ! F_34 ( V_59 , V_55 -> V_56 ) ) {
return F_28 ( V_61 , V_55 -> V_56 ) ? 1 : 0 ;
}
V_43 = V_2 -> V_42 ;
V_82 = V_76 . V_74 ;
F_17 ( V_43 , * V_82 ) ;
if ( ! ( * V_82 ++ & V_22 -> V_62 ) )
return 0 ;
V_26 = & V_76 . V_74 [ 0 ] ;
F_16 ( V_22 , V_13 , V_26 ) ;
F_35 ( & V_71 , 0 , V_2 -> V_11 ) ;
if ( ! F_13 ( V_22 , V_2 , & V_8 ) )
goto V_83;
V_76 . V_84 = V_48 ;
V_78 = 1 ;
V_77 = 1 ;
V_79 = ( V_22 == & V_25 && ( V_48 & V_85 ) ) ;
if ( V_13 -> V_27 . V_86 & V_87 )
V_80 = V_22 -> V_80 ;
else if ( V_79 )
V_80 = 2 ;
else
V_80 = 1 ;
do {
F_17 ( V_43 + V_77 , * V_82 ++ ) ;
V_78 ++ ;
V_77 = F_36 ( V_22 -> V_88 ,
V_22 -> V_80 ,
V_77 + 1 ) ;
} while ( V_77 < V_80 );
V_76 . V_78 = sizeof( T_1 ) * V_78 ;
V_74 = * V_69 ;
if ( V_79 && ( V_76 . V_74 [ 2 ] & V_89 ) ) {
V_74 . V_53 &= ~ V_90 ;
} else {
F_37 ( & V_74 , V_76 . V_74 [ 1 ] ) ;
V_74 . V_53 |= V_90 ;
}
if ( V_13 -> V_27 . V_86 & V_87 ) {
V_73 . V_78 = sizeof( V_91 ) + V_76 . V_78 ;
V_73 . V_71 = V_76 . V_71 ;
V_71 . V_73 = & V_73 ;
}
V_81 = F_38 ( V_13 , & V_71 , & V_74 ) ;
V_83:
if ( V_81 )
F_20 ( V_22 , V_2 , * V_26 ) ;
else
F_18 ( V_22 , V_2 , V_8 >> 4 ) ;
F_26 ( V_13 ) ;
return 1 ;
}
static int
F_39 ( unsigned int V_92 , struct V_68 * V_74 )
{
int V_93 = 0 ;
V_93 += F_33 ( & V_23 , V_74 ) ;
V_93 += F_33 ( & V_25 , V_74 ) ;
if ( V_93 )
F_40 ( V_94 ) ;
return V_93 ;
}
static T_3 int F_41 ( struct V_22 * V_22 , char * V_95 )
{
struct V_54 T_4 * V_55 ;
int V_36 ;
V_55 = F_42 ( struct V_54 ) ;
if ( ! V_55 )
return - V_96 ;
V_22 -> V_55 = V_55 ;
if ( V_22 -> V_97 [ 0 ] ) {
memset ( & V_22 -> V_98 , 0 , sizeof( V_22 -> V_98 ) ) ;
V_22 -> V_98 . V_95 = L_1 ;
V_22 -> V_98 . V_99 = V_22 -> V_97 ;
memset ( & V_22 -> V_100 , 0 , sizeof( V_22 -> V_100 ) ) ;
V_22 -> V_100 [ 0 ] = & V_22 -> V_98 ;
V_22 -> V_24 . V_100 = V_22 -> V_100 ;
}
V_36 = F_43 ( & V_22 -> V_24 , V_95 , - 1 ) ;
if ( V_36 ) {
V_22 -> V_55 = NULL ;
F_44 ( V_55 ) ;
}
return V_36 ;
}
static T_3 int F_45 ( void )
{
struct V_101 * * V_27 = V_102 ;
if ( ! V_48 )
return - V_103 ;
F_41 ( & V_23 , L_2 ) ;
if ( V_48 & V_104 ) {
V_25 . V_39 |= V_34 ;
* V_27 ++ = & V_105 . V_27 ;
}
F_41 ( & V_25 , L_3 ) ;
F_46 ( V_106 , F_39 , 0 , L_4 ) ;
F_47 ( V_107 L_5 , V_48 ) ;
return 0 ;
}
static T_3 int F_45 ( void ) { return 0 ; }
static T_3 V_91 F_48 ( void )
{
V_91 V_84 ;
unsigned int V_108 ;
if ( ! F_49 ( V_109 ) )
return 0 ;
V_108 = F_50 ( 0x80000000 ) ;
if ( V_108 < V_110 )
return V_111 ;
V_84 = F_50 ( V_110 ) ;
if ( ! ( V_84 & V_112 ) )
return V_111 ;
return V_84 ;
}
V_91 F_51 ( void )
{
return V_48 ;
}
static inline int F_52 ( int V_77 )
{
return ! F_53 ( V_77 , 0 , V_113 , 1 ) ;
}
static inline int F_54 ( int V_77 )
{
return ! F_53 ( V_77 , 0 , 0 , 1 ) ;
}
static inline int F_55 ( void )
{
int V_77 ;
T_1 V_114 ;
int V_115 = 0 ;
F_56 () ;
F_17 ( V_116 , V_114 ) ;
V_77 = V_114 & V_117 ;
if ( ! ( V_114 & V_118 ) ) {
F_57 ( V_119 L_6 ,
F_58 () , V_77 , V_116 , V_114 ) ;
goto V_83;
}
if ( ! F_52 ( V_77 ) ) {
F_57 ( V_119 L_7 ,
F_58 () , V_77 , V_116 , V_114 ) ;
goto V_83;
}
V_115 = 1 ;
V_83:
F_59 () ;
return V_115 ;
}
static int F_60 ( int V_120 )
{
struct V_121 * V_122 ;
int V_123 ;
V_91 V_124 = 0 ;
V_123 = 0 ;
V_122 = NULL ;
do {
V_122 = F_61 ( V_125 ,
V_126 ,
V_122 ) ;
if ( ! V_122 )
break;
++ V_123 ;
F_62 ( V_122 , V_127 , V_120
| V_118 ) ;
F_63 ( V_122 , V_127 , & V_124 ) ;
if ( V_124 != ( V_120 | V_118 ) ) {
F_64 ( V_122 ) ;
F_47 ( V_128 L_8
L_9 , V_124 ) ;
return - V_38 ;
}
} while ( 1 );
if ( ! V_123 ) {
F_47 ( V_128 L_10 ) ;
return - V_103 ;
}
return 0 ;
}
static int F_65 ( void )
{
int V_77 ;
int V_36 ;
F_56 () ;
for ( V_77 = 1 ; V_77 < V_129 ; V_77 ++ ) {
if ( F_52 ( V_77 ) )
break;
}
F_59 () ;
if ( V_77 == V_129 ) {
F_47 ( V_128 L_11 ) ;
return - V_130 ;
}
V_36 = F_60 ( V_77 ) ;
if ( V_36 )
goto V_83;
if ( ! F_55 () ) {
V_36 = - V_131 ;
goto V_83;
}
F_66 ( L_12 , V_77 ) ;
return 0 ;
V_83:
F_56 () ;
F_54 ( V_77 ) ;
F_59 () ;
return V_36 ;
}
static void F_67 ( void )
{
if ( V_132 . V_133 == 0x10 )
F_65 () ;
}
static inline int F_68 ( void )
{
T_1 V_114 ;
F_17 ( V_116 , V_114 ) ;
if ( ! ( V_114 & V_118 ) )
return - V_38 ;
return V_114 & V_117 ;
}
static void F_69 ( void * V_134 )
{
int V_77 ;
V_77 = F_68 () ;
if ( V_77 < 0 )
goto V_135;
if ( ! F_53 ( V_77 , 0 , V_113 , 0 ) )
return;
V_135:
F_70 ( L_13 ,
F_58 () ) ;
}
static void F_71 ( void * V_134 )
{
int V_77 ;
V_77 = F_68 () ;
if ( V_77 >= 0 )
F_53 ( V_77 , 0 , V_136 , 1 ) ;
}
static int F_72 ( void )
{
F_71 ( NULL ) ;
return 0 ;
}
static void F_73 ( void )
{
F_67 () ;
F_69 ( NULL ) ;
}
static void F_74 ( void )
{
F_75 ( & V_137 ) ;
}
static inline void F_74 ( void ) { }
static int
F_76 ( struct V_138 * V_139 , unsigned long V_140 , void * V_141 )
{
switch ( V_140 & ~ V_142 ) {
case V_143 :
F_69 ( NULL ) ;
break;
case V_144 :
F_71 ( NULL ) ;
break;
default:
break;
}
return V_145 ;
}
static T_3 int F_77 ( void )
{
V_91 V_84 ;
int V_36 = - V_38 ;
V_84 = F_48 () ;
if ( ! V_84 )
return - V_103 ;
F_67 () ;
if ( ! F_55 () )
goto V_83;
F_74 () ;
F_78 () ;
V_48 = V_84 ;
F_79 () ;
F_80 ( F_69 , NULL , 1 ) ;
F_81 ( F_76 ) ;
F_82 () ;
V_36 = F_45 () ;
V_83:
if ( V_36 )
F_57 ( L_14 , V_36 ) ;
return V_36 ;
}
