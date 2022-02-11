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
if ( V_26 & ~ V_22 -> V_37 )
return - V_38 ;
if ( V_2 -> V_9 ) {
if ( V_26 & V_22 -> V_39 )
return - V_38 ;
if ( ! V_13 -> V_27 . V_40 && V_2 -> V_9 & 0x0f )
return - V_38 ;
V_2 -> V_9 &= ~ 0x0FULL ;
if ( ! V_2 -> V_9 )
V_2 -> V_9 = 0x10 ;
} else {
V_35 = V_26 & V_22 -> V_39 ;
V_26 &= ~ V_22 -> V_39 ;
V_13 -> V_27 . V_9 = V_35 << 4 ;
V_2 -> V_9 = V_13 -> V_27 . V_9 ;
}
if ( ! V_2 -> V_9 )
return - V_38 ;
V_2 -> V_11 = V_2 -> V_9 ;
F_4 ( & V_2 -> V_7 , V_2 -> V_9 ) ;
V_2 -> V_41 = V_22 -> V_42 ;
V_2 -> V_26 = V_26 ;
return 0 ;
}
static int F_12 ( struct V_22 * V_22 ,
struct V_1 * V_2 , T_1 * V_8 )
{
int V_10 ;
V_10 = F_1 ( V_2 , 1 << 4 , V_22 -> V_43 , V_8 ) ;
F_4 ( & V_2 -> V_20 , 0 ) ;
return V_10 ;
}
static T_1 F_13 ( T_1 V_26 )
{
return ( V_26 & V_44 ) >> 12 ;
}
static T_1 F_14 ( T_1 V_26 )
{
T_1 V_21 = 0 ;
if ( V_26 & V_45 )
V_21 += ( V_26 & V_46 ) << 4 ;
if ( V_47 & V_48 )
V_21 += ( V_26 & V_49 ) >> 32 ;
return V_21 ;
}
static void
F_15 ( struct V_22 * V_22 , struct V_12 * V_13 ,
T_1 * V_26 )
{
T_1 V_21 = V_22 -> V_50 ( * V_26 ) ;
while ( ! F_5 ( V_13 , V_21 , 64 ) ) {
F_16 ( V_13 -> V_16 . V_41 , * V_26 ) ;
V_21 = V_22 -> V_50 ( * V_26 ) ;
}
}
static inline void F_17 ( struct V_22 * V_22 ,
struct V_1 * V_2 , T_1 V_26 )
{
F_18 ( V_2 -> V_41 , V_2 -> V_26 | V_26 | V_22 -> V_51 ) ;
}
static inline void F_19 ( struct V_22 * V_22 ,
struct V_1 * V_2 , T_1 V_26 )
{
V_26 &= ~ V_22 -> V_39 ;
F_18 ( V_2 -> V_41 , V_26 ) ;
V_26 &= ~ V_22 -> V_51 ;
F_18 ( V_2 -> V_41 , V_26 ) ;
}
static void F_20 ( struct V_12 * V_13 , int V_52 )
{
struct V_1 * V_2 = & V_13 -> V_16 ;
struct V_22 * V_22 = F_21 ( V_13 -> V_24 , struct V_22 , V_24 ) ;
struct V_53 * V_54 = F_22 ( V_22 -> V_54 ) ;
T_1 V_8 ;
if ( F_23 ( ! ( V_2 -> V_55 & V_56 ) ) )
return;
F_23 ( ! ( V_2 -> V_55 & V_57 ) ) ;
V_2 -> V_55 = 0 ;
F_12 ( V_22 , V_2 , & V_8 ) ;
F_24 ( V_58 , V_54 -> V_55 ) ;
F_17 ( V_22 , V_2 , V_8 >> 4 ) ;
F_25 ( V_13 ) ;
}
static void F_26 ( struct V_12 * V_13 , int V_52 )
{
struct V_1 * V_2 = & V_13 -> V_16 ;
struct V_22 * V_22 = F_21 ( V_13 -> V_24 , struct V_22 , V_24 ) ;
struct V_53 * V_54 = F_22 ( V_22 -> V_54 ) ;
T_1 V_26 ;
int V_59 ;
V_59 = F_27 ( V_58 , V_54 -> V_55 ) ;
if ( ! V_59 && ( V_2 -> V_55 & V_57 ) )
return;
F_16 ( V_2 -> V_41 , V_26 ) ;
if ( V_59 ) {
F_24 ( V_60 , V_54 -> V_55 ) ;
F_19 ( V_22 , V_2 , V_26 ) ;
F_23 ( V_2 -> V_55 & V_56 ) ;
V_2 -> V_55 |= V_56 ;
}
if ( V_2 -> V_55 & V_57 )
return;
V_26 &= ~ V_22 -> V_61 ;
F_15 ( V_22 , V_13 , & V_26 ) ;
V_2 -> V_55 |= V_57 ;
}
static int F_28 ( struct V_12 * V_13 , int V_52 )
{
struct V_22 * V_22 = F_21 ( V_13 -> V_24 , struct V_22 , V_24 ) ;
struct V_53 * V_54 = F_22 ( V_22 -> V_54 ) ;
if ( F_29 ( V_62 , V_54 -> V_55 ) )
return - V_63 ;
V_13 -> V_16 . V_55 = V_57 | V_56 ;
V_54 -> V_13 = V_13 ;
if ( V_52 & V_64 )
F_20 ( V_13 , V_65 ) ;
return 0 ;
}
static void F_30 ( struct V_12 * V_13 , int V_52 )
{
struct V_22 * V_22 = F_21 ( V_13 -> V_24 , struct V_22 , V_24 ) ;
struct V_53 * V_54 = F_22 ( V_22 -> V_54 ) ;
if ( ! F_27 ( V_62 , V_54 -> V_55 ) )
return;
F_26 ( V_13 , V_66 ) ;
V_54 -> V_13 = NULL ;
F_25 ( V_13 ) ;
}
static void F_31 ( struct V_12 * V_13 ) { }
static int F_32 ( struct V_22 * V_22 , struct V_67 * V_68 )
{
struct V_53 * V_54 = F_22 ( V_22 -> V_54 ) ;
struct V_12 * V_13 = V_54 -> V_13 ;
struct V_1 * V_2 = & V_13 -> V_16 ;
struct V_69 V_70 ;
struct V_71 V_72 ;
struct V_67 V_73 ;
struct V_74 V_75 ;
int V_76 , V_77 , V_78 , V_79 , V_80 = 0 ;
unsigned int V_42 ;
T_1 * V_81 , * V_26 , V_8 ;
if ( ! F_33 ( V_58 , V_54 -> V_55 ) ) {
return F_27 ( V_60 , V_54 -> V_55 ) ? 1 : 0 ;
}
V_42 = V_2 -> V_41 ;
V_81 = V_75 . V_73 ;
F_16 ( V_42 , * V_81 ) ;
if ( ! ( * V_81 ++ & V_22 -> V_61 ) )
return 0 ;
V_26 = & V_75 . V_73 [ 0 ] ;
F_15 ( V_22 , V_13 , V_26 ) ;
F_34 ( & V_70 , 0 , V_2 -> V_11 ) ;
if ( ! F_12 ( V_22 , V_2 , & V_8 ) )
goto V_82;
V_75 . V_83 = V_47 ;
V_77 = 1 ;
V_76 = 1 ;
V_78 = ( V_22 == & V_25 && ( V_47 & V_84 ) ) ;
if ( V_13 -> V_27 . V_85 & V_86 )
V_79 = V_22 -> V_79 ;
else if ( V_78 )
V_79 = 2 ;
else
V_79 = 1 ;
do {
F_16 ( V_42 + V_76 , * V_81 ++ ) ;
V_77 ++ ;
V_76 = F_35 ( V_22 -> V_87 ,
V_22 -> V_79 ,
V_76 + 1 ) ;
} while ( V_76 < V_79 );
V_75 . V_77 = sizeof( T_1 ) * V_77 ;
V_73 = * V_68 ;
if ( V_78 && ( V_75 . V_73 [ 2 ] & V_88 ) ) {
V_73 . V_52 &= ~ V_89 ;
} else {
F_36 ( & V_73 , V_75 . V_73 [ 1 ] ) ;
V_73 . V_52 |= V_89 ;
}
if ( V_13 -> V_27 . V_85 & V_86 ) {
V_72 . V_77 = sizeof( V_90 ) + V_75 . V_77 ;
V_72 . V_70 = V_75 . V_70 ;
V_70 . V_72 = & V_72 ;
}
V_80 = F_37 ( V_13 , & V_70 , & V_73 ) ;
V_82:
if ( V_80 )
F_19 ( V_22 , V_2 , * V_26 ) ;
else
F_17 ( V_22 , V_2 , V_8 >> 4 ) ;
F_25 ( V_13 ) ;
return 1 ;
}
static int T_3
F_38 ( unsigned int V_91 , struct V_67 * V_73 )
{
int V_92 = 0 ;
V_92 += F_32 ( & V_23 , V_73 ) ;
V_92 += F_32 ( & V_25 , V_73 ) ;
if ( V_92 )
F_39 ( V_93 ) ;
return V_92 ;
}
static T_4 int F_40 ( struct V_22 * V_22 , char * V_94 )
{
struct V_53 T_5 * V_54 ;
int V_36 ;
V_54 = F_41 ( struct V_53 ) ;
if ( ! V_54 )
return - V_95 ;
V_22 -> V_54 = V_54 ;
V_36 = F_42 ( & V_22 -> V_24 , V_94 , - 1 ) ;
if ( V_36 ) {
V_22 -> V_54 = NULL ;
F_43 ( V_54 ) ;
}
return V_36 ;
}
static T_4 int F_44 ( void )
{
if ( ! V_47 )
return - V_96 ;
F_40 ( & V_23 , L_1 ) ;
if ( V_47 & V_97 )
V_25 . V_37 |= V_34 ;
F_40 ( & V_25 , L_2 ) ;
F_45 ( V_98 , F_38 , 0 , L_3 ) ;
F_46 ( V_99 L_4 , V_47 ) ;
return 0 ;
}
static T_4 int F_44 ( void ) { return 0 ; }
static T_4 V_90 F_47 ( void )
{
V_90 V_83 ;
unsigned int V_100 ;
if ( ! F_48 ( V_101 ) )
return 0 ;
V_100 = F_49 ( 0x80000000 ) ;
if ( V_100 < V_102 )
return V_103 ;
V_83 = F_49 ( V_102 ) ;
if ( ! ( V_83 & V_104 ) )
return V_103 ;
return V_83 ;
}
V_90 F_50 ( void )
{
return V_47 ;
}
static inline int F_51 ( int V_76 )
{
return ! F_52 ( V_76 , 0 , V_105 , 1 ) ;
}
static inline int F_53 ( int V_76 )
{
return ! F_52 ( V_76 , 0 , 0 , 1 ) ;
}
static inline int F_54 ( void )
{
int V_76 ;
T_1 V_106 ;
int V_107 = 0 ;
F_55 () ;
F_16 ( V_108 , V_106 ) ;
V_76 = V_106 & V_109 ;
if ( ! ( V_106 & V_110 ) ) {
F_56 ( V_111 L_5 ,
F_57 () , V_76 , V_108 , V_106 ) ;
goto V_82;
}
if ( ! F_51 ( V_76 ) ) {
F_56 ( V_111 L_6 ,
F_57 () , V_76 , V_108 , V_106 ) ;
goto V_82;
}
V_107 = 1 ;
V_82:
F_58 () ;
return V_107 ;
}
static int F_59 ( int V_112 )
{
struct V_113 * V_114 ;
int V_115 ;
V_90 V_116 = 0 ;
V_115 = 0 ;
V_114 = NULL ;
do {
V_114 = F_60 ( V_117 ,
V_118 ,
V_114 ) ;
if ( ! V_114 )
break;
++ V_115 ;
F_61 ( V_114 , V_119 , V_112
| V_110 ) ;
F_62 ( V_114 , V_119 , & V_116 ) ;
if ( V_116 != ( V_112 | V_110 ) ) {
F_63 ( V_114 ) ;
F_46 ( V_120 L_7
L_8 , V_116 ) ;
return - V_38 ;
}
} while ( 1 );
if ( ! V_115 ) {
F_46 ( V_120 L_9 ) ;
return - V_96 ;
}
return 0 ;
}
static int F_64 ( void )
{
int V_76 ;
int V_36 ;
F_55 () ;
for ( V_76 = 1 ; V_76 < V_121 ; V_76 ++ ) {
if ( F_51 ( V_76 ) )
break;
}
F_58 () ;
if ( V_76 == V_121 ) {
F_46 ( V_120 L_10 ) ;
return - V_122 ;
}
V_36 = F_59 ( V_76 ) ;
if ( V_36 )
goto V_82;
if ( ! F_54 () ) {
V_36 = - V_123 ;
goto V_82;
}
F_65 ( L_11 , V_76 ) ;
return 0 ;
V_82:
F_55 () ;
F_53 ( V_76 ) ;
F_58 () ;
return V_36 ;
}
static inline int F_66 ( void )
{
T_1 V_106 ;
F_16 ( V_108 , V_106 ) ;
if ( ! ( V_106 & V_110 ) )
return - V_38 ;
return V_106 & V_109 ;
}
static void F_67 ( void * V_124 )
{
int V_76 ;
V_76 = F_66 () ;
if ( V_76 < 0 )
goto V_125;
if ( ! F_52 ( V_76 , 0 , V_105 , 0 ) )
return;
V_125:
F_68 ( L_12 ,
F_57 () ) ;
}
static void F_69 ( void * V_124 )
{
int V_76 ;
V_76 = F_66 () ;
if ( V_76 >= 0 )
F_52 ( V_76 , 0 , V_126 , 1 ) ;
}
static int T_6
F_70 ( struct V_127 * V_128 , unsigned long V_129 , void * V_130 )
{
switch ( V_129 & ~ V_131 ) {
case V_132 :
F_67 ( NULL ) ;
break;
case V_133 :
F_69 ( NULL ) ;
break;
default:
break;
}
return V_134 ;
}
static T_4 int F_71 ( void )
{
V_90 V_83 ;
int V_36 = - V_38 ;
V_83 = F_47 () ;
if ( ! V_83 )
return - V_96 ;
if ( V_135 . V_136 == 0x10 )
F_64 () ;
if ( ! F_54 () )
goto V_82;
F_72 () ;
V_47 = V_83 ;
F_73 () ;
F_74 ( F_70 ) ;
F_75 ( F_67 , NULL , 1 ) ;
F_76 () ;
V_36 = F_44 () ;
V_82:
if ( V_36 )
F_56 ( L_13 , V_36 ) ;
return V_36 ;
}
