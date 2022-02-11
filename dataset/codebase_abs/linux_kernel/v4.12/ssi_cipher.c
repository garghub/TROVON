static int F_1 ( struct V_1 * V_2 , T_1 V_3 ) {
switch ( V_2 -> V_4 ) {
case V_5 :
switch ( V_3 ) {
case V_6 :
case V_7 :
if ( F_2 ( ( V_2 -> V_8 != V_9 ) &&
( V_2 -> V_8 != V_10 ) &&
( V_2 -> V_8 != V_11 ) ) )
return 0 ;
break;
case V_12 :
return 0 ;
case ( V_7 * 2 ) :
case ( V_12 * 2 ) :
if ( F_2 ( ( V_2 -> V_8 == V_9 ) ||
( V_2 -> V_8 == V_10 ) ||
( V_2 -> V_8 == V_11 ) ) )
return 0 ;
break;
default:
break;
}
case V_13 :
if ( F_2 ( V_3 == V_14 ||
V_3 == V_15 ) )
return 0 ;
break;
#if V_16
case V_17 :
if ( F_2 ( V_3 == V_18 ) )
return 0 ;
break;
#endif
default:
break;
}
return - V_19 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ) {
switch ( V_2 -> V_4 ) {
case V_5 :
switch ( V_2 -> V_8 ) {
case V_9 :
if ( ( V_3 >= V_20 ) &&
( V_3 <= V_21 ) &&
F_4 ( V_3 , V_22 ) )
return 0 ;
break;
case V_23 :
if ( F_2 ( V_3 >= V_22 ) )
return 0 ;
break;
case V_24 :
case V_25 :
return 0 ;
case V_26 :
case V_27 :
case V_10 :
case V_11 :
if ( F_2 ( F_4 ( V_3 , V_22 ) ) )
return 0 ;
break;
default:
break;
}
break;
case V_13 :
if ( F_2 ( F_4 ( V_3 , V_28 ) ) )
return 0 ;
break;
#if V_16
case V_17 :
switch ( V_2 -> V_8 ) {
case V_29 :
if ( F_2 ( F_4 ( V_3 , V_30 ) ) )
return 0 ;
break;
case V_31 :
return 0 ;
default:
break;
}
break;
#endif
default:
break;
}
return - V_19 ;
}
static unsigned int F_5 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_6 ( V_33 -> V_36 , struct V_34 , V_37 ) ;
if ( ( V_35 -> V_37 . V_38 & V_39 ) == V_40 ) {
return V_35 -> V_37 . V_41 . V_42 ;
}
if ( ( V_35 -> V_37 . V_38 & V_39 ) == V_43 ) {
return V_35 -> V_37 . V_44 . V_42 ;
}
return 0 ;
}
static int F_7 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
struct V_37 * V_45 = V_33 -> V_36 ;
struct V_34 * V_35 =
F_6 ( V_45 , struct V_34 , V_37 ) ;
struct V_46 * V_47 ;
int V_48 = 0 ;
unsigned int V_49 = F_5 ( V_33 ) ;
F_9 ( L_1 , V_2 ,
F_10 ( V_33 ) ) ;
F_11 () ;
V_2 -> V_8 = V_35 -> V_8 ;
V_2 -> V_4 = V_35 -> V_4 ;
V_2 -> V_50 = V_35 -> V_50 ;
V_47 = & V_2 -> V_50 -> V_51 -> V_47 ;
V_2 -> V_52 . V_53 = F_12 ( V_49 , V_54 | V_55 ) ;
if ( ! V_2 -> V_52 . V_53 ) {
F_13 ( L_2 ) ;
V_48 = - V_56 ;
}
F_9 ( L_3 ,
V_2 -> V_52 . V_53 ) ;
V_2 -> V_52 . V_57 = F_14 ( V_47 , ( void * ) V_2 -> V_52 . V_53 ,
V_49 , V_58 ) ;
if ( F_15 ( V_47 , V_2 -> V_52 . V_57 ) ) {
F_13 ( L_4 ,
V_49 , V_2 -> V_52 . V_53 ) ;
return - V_56 ;
}
F_16 ( V_2 -> V_52 . V_57 , V_49 ) ;
F_9 ( L_5 ,
V_49 , V_2 -> V_52 . V_53 ,
( unsigned long long ) V_2 -> V_52 . V_57 ) ;
if ( V_2 -> V_8 == V_10 ) {
V_2 -> V_59 = F_17 ( L_6 , 0 , 0 ) ;
if ( F_18 ( V_2 -> V_59 ) ) {
F_13 ( L_7 ) ;
return F_19 ( V_2 -> V_59 ) ;
}
}
return V_48 ;
}
static void F_20 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
struct V_46 * V_47 = & V_2 -> V_50 -> V_51 -> V_47 ;
unsigned int V_49 = F_5 ( V_33 ) ;
F_9 ( L_8 ,
F_8 ( V_33 ) , F_10 ( V_33 ) ) ;
if ( V_2 -> V_8 == V_10 ) {
F_21 ( V_2 -> V_59 ) ;
V_2 -> V_59 = NULL ;
}
F_22 ( V_2 -> V_52 . V_57 ) ;
F_23 ( V_47 , V_2 -> V_52 . V_57 , V_49 ,
V_58 ) ;
F_9 ( L_9 ,
( unsigned long long ) V_2 -> V_52 . V_57 ) ;
F_24 ( V_2 -> V_52 . V_53 ) ;
F_9 ( L_10 , V_2 -> V_52 . V_53 ) ;
}
static int F_25 ( const T_2 * V_53 , unsigned int V_60 )
{
#ifdef F_26
T_3 * V_61 = ( T_3 * ) V_53 ;
if ( F_27 ( ( memcmp ( ( T_2 * ) V_61 -> V_62 , ( T_2 * ) V_61 -> V_63 , sizeof( V_61 -> V_62 ) ) == 0 ) ||
( memcmp ( ( T_2 * ) V_61 -> V_64 , ( T_2 * ) V_61 -> V_63 , sizeof( V_61 -> V_64 ) ) == 0 ) ) ) {
return - V_65 ;
}
#endif
return 0 ;
}
static int F_28 ( const T_2 * V_53 , unsigned int V_60 )
{
#ifdef F_26
int V_66 = V_60 >> 1 ;
if ( F_27 ( memcmp ( V_53 , & V_53 [ V_66 ] , V_66 ) == 0 ) ) {
return - V_65 ;
}
#endif
return 0 ;
}
static enum V_67 F_29 ( int V_68 )
{
switch ( V_68 ) {
case 0 :
return V_69 ;
case 1 :
return V_70 ;
case 2 :
return V_71 ;
case 3 :
return V_72 ;
}
return V_73 ;
}
static int F_30 ( struct V_32 * V_33 ,
const T_2 * V_53 ,
unsigned int V_60 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
struct V_46 * V_47 = & V_2 -> V_50 -> V_51 -> V_47 ;
T_4 V_74 [ V_75 ] ;
unsigned int V_49 = F_5 ( V_33 ) ;
V_76 ;
F_9 ( L_11 ,
V_2 , F_10 ( V_33 ) , V_60 ) ;
F_31 ( L_12 , ( V_77 * ) V_53 , V_60 ) ;
F_11 () ;
F_9 ( L_13 ) ;
F_32 () ;
#if V_16
if ( V_2 -> V_4 == V_17 ) {
V_60 -= 1 ;
}
#endif
if ( F_27 ( F_1 ( V_2 , V_60 ) != 0 ) ) {
F_13 ( L_14 , V_60 ) ;
F_33 ( V_33 , V_78 ) ;
return - V_19 ;
}
if ( F_34 ( V_33 ) ) {
struct V_79 * V_80 = (struct V_79 * ) V_53 ;
if ( F_27 ( V_2 -> V_4 != V_5 ) ) {
F_13 ( L_15 ) ;
return - V_19 ;
}
V_2 -> V_81 . V_82 = F_29 ( V_80 -> V_83 ) ;
if ( F_27 ( V_2 -> V_81 . V_82 == V_73 ) ) {
F_13 ( L_16 , V_80 -> V_83 ) ;
return - V_19 ;
}
if ( ( V_2 -> V_8 == V_9 ) ||
( V_2 -> V_8 == V_10 ) ||
( V_2 -> V_8 == V_11 ) ) {
if ( F_27 ( V_80 -> V_83 == V_80 -> V_84 ) ) {
F_13 ( L_17 , V_80 -> V_83 , V_80 -> V_84 ) ;
return - V_19 ;
}
V_2 -> V_81 . V_85 = F_29 ( V_80 -> V_84 ) ;
if ( F_27 ( V_2 -> V_81 . V_85 == V_73 ) ) {
F_13 ( L_18 , V_80 -> V_84 ) ;
return - V_19 ;
}
}
V_2 -> V_60 = V_60 ;
F_35 ( V_86 , V_87 ) ;
F_9 ( L_19 ) ;
return 0 ;
}
if ( V_2 -> V_4 == V_13 ) {
if ( F_27 ( ! F_36 ( V_74 , V_53 ) ) &&
( F_37 ( V_33 ) & V_88 ) ) {
V_33 -> V_89 |= V_90 ;
F_9 ( L_20 ) ;
return - V_19 ;
}
}
if ( ( V_2 -> V_8 == V_9 ) &&
F_28 ( V_53 , V_60 ) != 0 ) {
F_9 ( L_21 ) ;
return - V_19 ;
}
if ( ( V_2 -> V_4 == V_13 ) &&
( V_60 == V_14 ) &&
F_25 ( V_53 , V_60 ) != 0 ) {
F_9 ( L_22 ) ;
return - V_19 ;
}
F_35 ( V_86 , V_87 ) ;
F_32 () ;
F_22 ( V_2 -> V_52 . V_57 ) ;
F_38 ( V_47 , V_2 -> V_52 . V_57 ,
V_49 , V_58 ) ;
#if V_16
if ( V_2 -> V_4 == V_17 ) {
memcpy ( V_2 -> V_52 . V_53 , V_53 , V_18 ) ;
V_2 -> V_91 = V_53 [ V_18 ] ;
if ( V_2 -> V_91 < V_92 ||
V_2 -> V_91 > V_93 ) {
F_33 ( V_33 , V_78 ) ;
F_9 ( L_23 ) ;
return - V_19 ;
}
} else
#endif
{
memcpy ( V_2 -> V_52 . V_53 , V_53 , V_60 ) ;
if ( V_60 == 24 )
memset ( V_2 -> V_52 . V_53 + 24 , 0 , V_94 - 24 ) ;
if ( V_2 -> V_8 == V_10 ) {
int V_95 = V_60 >> 1 ;
int V_96 ;
F_39 ( V_97 , V_2 -> V_59 ) ;
V_97 -> V_33 = V_2 -> V_59 ;
V_96 = F_40 ( V_97 , V_2 -> V_52 . V_53 , V_95 , V_2 -> V_52 . V_53 + V_95 ) ;
if ( V_96 ) {
F_13 ( L_24 ) ;
return V_96 ;
}
}
}
F_41 ( V_47 , V_2 -> V_52 . V_57 ,
V_49 , V_58 ) ;
F_16 ( V_2 -> V_52 . V_57 , V_49 ) ;
V_2 -> V_60 = V_60 ;
F_35 ( V_86 , V_98 ) ;
F_9 ( L_25 ) ;
return 0 ;
}
static inline void
F_42 (
struct V_32 * V_33 ,
struct V_99 * V_100 ,
unsigned int V_101 ,
unsigned int V_102 ,
T_5 V_97 [] ,
unsigned int * V_103 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
int V_8 = V_2 -> V_8 ;
int V_4 = V_2 -> V_4 ;
int V_104 = V_100 -> V_105 . V_106 ;
T_6 V_57 = V_2 -> V_52 . V_57 ;
unsigned int V_95 = V_2 -> V_60 ;
T_6 V_107 = V_100 -> V_105 . V_107 ;
unsigned int V_108 = V_102 ;
struct V_34 * V_35 = F_6 ( V_33 -> V_36 , struct V_34 , V_37 ) ;
if ( ( V_35 -> V_37 . V_38 & V_109 ) == V_110 )
V_108 = 512 ;
if ( ( V_35 -> V_37 . V_38 & V_109 ) == V_111 )
V_108 = 4096 ;
switch ( V_8 ) {
case V_27 :
case V_23 :
case V_25 :
case V_24 :
F_43 ( & V_97 [ * V_103 ] ) ;
F_44 ( & V_97 [ * V_103 ] , V_112 ,
V_107 , V_101 ,
V_113 ) ;
F_45 ( & V_97 [ * V_103 ] , V_104 ) ;
F_46 ( & V_97 [ * V_103 ] , V_4 ) ;
F_47 ( & V_97 [ * V_103 ] , V_8 ) ;
if ( ( V_8 == V_25 ) ||
( V_8 == V_24 ) ) {
F_48 ( & V_97 [ * V_103 ] ,
V_114 ) ;
} else {
F_48 ( & V_97 [ * V_103 ] ,
V_115 ) ;
}
( * V_103 ) ++ ;
case V_26 :
F_43 ( & V_97 [ * V_103 ] ) ;
F_47 ( & V_97 [ * V_103 ] , V_8 ) ;
F_45 ( & V_97 [ * V_103 ] , V_104 ) ;
if ( V_4 == V_5 ) {
if ( F_34 ( V_33 ) ) {
F_49 ( & V_97 [ * V_103 ] , V_2 -> V_81 . V_82 ) ;
} else {
F_44 ( & V_97 [ * V_103 ] , V_112 ,
V_57 ,
( ( V_95 == 24 ) ? V_116 : V_95 ) ,
V_113 ) ;
}
F_50 ( & V_97 [ * V_103 ] , V_95 ) ;
} else {
F_44 ( & V_97 [ * V_103 ] , V_112 ,
V_57 , V_95 ,
V_113 ) ;
F_51 ( & V_97 [ * V_103 ] , V_95 ) ;
}
F_46 ( & V_97 [ * V_103 ] , V_4 ) ;
F_48 ( & V_97 [ * V_103 ] , V_117 ) ;
( * V_103 ) ++ ;
break;
case V_9 :
case V_10 :
case V_11 :
F_43 ( & V_97 [ * V_103 ] ) ;
F_47 ( & V_97 [ * V_103 ] , V_8 ) ;
F_45 ( & V_97 [ * V_103 ] , V_104 ) ;
if ( F_34 ( V_33 ) ) {
F_49 ( & V_97 [ * V_103 ] , V_2 -> V_81 . V_82 ) ;
} else {
F_44 ( & V_97 [ * V_103 ] , V_112 ,
V_57 , V_95 / 2 ,
V_113 ) ;
}
F_50 ( & V_97 [ * V_103 ] , V_95 / 2 ) ;
F_46 ( & V_97 [ * V_103 ] , V_4 ) ;
F_48 ( & V_97 [ * V_103 ] , V_117 ) ;
( * V_103 ) ++ ;
F_43 ( & V_97 [ * V_103 ] ) ;
F_47 ( & V_97 [ * V_103 ] , V_8 ) ;
F_45 ( & V_97 [ * V_103 ] , V_104 ) ;
if ( F_34 ( V_33 ) ) {
F_49 ( & V_97 [ * V_103 ] , V_2 -> V_81 . V_85 ) ;
} else {
F_44 ( & V_97 [ * V_103 ] , V_112 ,
( V_57 + V_95 / 2 ) , V_95 / 2 ,
V_113 ) ;
}
F_52 ( & V_97 [ * V_103 ] , V_108 ) ;
F_46 ( & V_97 [ * V_103 ] , V_118 ) ;
F_50 ( & V_97 [ * V_103 ] , V_95 / 2 ) ;
F_48 ( & V_97 [ * V_103 ] , V_119 ) ;
( * V_103 ) ++ ;
F_43 ( & V_97 [ * V_103 ] ) ;
F_48 ( & V_97 [ * V_103 ] , V_114 ) ;
F_47 ( & V_97 [ * V_103 ] , V_8 ) ;
F_45 ( & V_97 [ * V_103 ] , V_104 ) ;
F_50 ( & V_97 [ * V_103 ] , V_95 / 2 ) ;
F_46 ( & V_97 [ * V_103 ] , V_4 ) ;
F_44 ( & V_97 [ * V_103 ] , V_112 ,
V_107 , V_120 ,
V_113 ) ;
( * V_103 ) ++ ;
break;
default:
F_13 ( L_26 , V_8 ) ;
F_53 () ;
}
}
static inline void F_54 (
struct V_32 * V_33 ,
struct V_99 * V_100 ,
unsigned int V_101 ,
T_5 V_97 [] ,
unsigned int * V_103 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
int V_104 = V_100 -> V_105 . V_106 ;
F_43 ( & V_97 [ * V_103 ] ) ;
F_47 ( & V_97 [ * V_103 ] , V_2 -> V_8 ) ;
F_45 ( & V_97 [ * V_103 ] , V_104 ) ;
F_44 ( & V_97 [ * V_103 ] , V_112 , V_2 -> V_52 . V_57 ,
V_121 ,
V_113 ) ;
F_46 ( & V_97 [ * V_103 ] , V_2 -> V_4 ) ;
F_48 ( & V_97 [ * V_103 ] , V_117 ) ;
( * V_103 ) ++ ;
F_43 ( & V_97 [ * V_103 ] ) ;
F_44 ( & V_97 [ * V_103 ] , V_112 ,
( V_2 -> V_52 . V_57 +
V_121 ) ,
V_122 , V_113 ) ;
F_55 ( & V_97 [ * V_103 ] ,
V_2 -> V_91 ) ;
F_46 ( & V_97 [ * V_103 ] , V_2 -> V_4 ) ;
F_47 ( & V_97 [ * V_103 ] , V_2 -> V_8 ) ;
F_45 ( & V_97 [ * V_103 ] , V_104 ) ;
F_48 ( & V_97 [ * V_103 ] , V_115 ) ;
( * V_103 ) ++ ;
F_43 ( & V_97 [ * V_103 ] ) ;
F_44 ( & V_97 [ * V_103 ] , V_112 ,
V_100 -> V_105 . V_107 ,
V_101 , V_113 ) ;
F_45 ( & V_97 [ * V_103 ] , V_104 ) ;
F_46 ( & V_97 [ * V_103 ] , V_2 -> V_4 ) ;
F_47 ( & V_97 [ * V_103 ] , V_2 -> V_8 ) ;
F_48 ( & V_97 [ * V_103 ] , V_114 ) ;
( * V_103 ) ++ ;
}
static inline void
F_56 (
struct V_32 * V_33 ,
struct V_99 * V_100 ,
struct V_123 * V_124 , struct V_123 * V_125 ,
unsigned int V_102 ,
void * V_126 ,
T_5 V_97 [] ,
unsigned int * V_103 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
unsigned int V_4 = V_2 -> V_4 ;
switch ( V_2 -> V_4 ) {
case V_5 :
V_4 = V_127 ;
break;
case V_13 :
V_4 = V_128 ;
break;
#if V_16
case V_17 :
V_4 = V_129 ;
break;
#endif
default:
F_13 ( L_27 , V_4 ) ;
return;
}
if ( F_2 ( V_100 -> V_130 == V_131 ) ) {
F_9 ( L_28 ,
( unsigned long long ) F_57 ( V_125 ) ,
V_102 ) ;
F_9 ( L_28 ,
( unsigned long long ) F_57 ( V_124 ) ,
V_102 ) ;
F_43 ( & V_97 [ * V_103 ] ) ;
F_44 ( & V_97 [ * V_103 ] , V_112 ,
F_57 ( V_125 ) ,
V_102 , V_113 ) ;
F_58 ( & V_97 [ * V_103 ] ,
F_57 ( V_124 ) ,
V_102 ,
V_113 , ( V_126 == NULL ) ? 0 : 1 ) ;
if ( V_126 != NULL ) {
F_59 ( & V_97 [ * V_103 ] ) ;
}
F_46 ( & V_97 [ * V_103 ] , V_4 ) ;
( * V_103 ) ++ ;
} else {
F_9 ( L_29
L_30 ,
( unsigned long long ) V_100 -> V_132 . V_133 ,
V_100 -> V_132 . V_134 ,
( unsigned int ) V_2 -> V_50 -> V_135 ) ;
F_43 ( & V_97 [ * V_103 ] ) ;
F_44 ( & V_97 [ * V_103 ] , V_112 ,
V_100 -> V_132 . V_133 ,
V_100 -> V_132 . V_134 ,
V_113 ) ;
F_60 ( & V_97 [ * V_103 ] ,
V_2 -> V_50 -> V_135 ,
V_100 -> V_132 . V_134 ) ;
F_46 ( & V_97 [ * V_103 ] , V_136 ) ;
( * V_103 ) ++ ;
F_43 ( & V_97 [ * V_103 ] ) ;
F_44 ( & V_97 [ * V_103 ] , V_137 ,
V_2 -> V_50 -> V_135 ,
V_100 -> V_138 , V_113 ) ;
if ( V_100 -> V_139 == 0 ) {
F_9 ( L_31
L_32 ,
( unsigned int ) V_2 -> V_50 -> V_135 ,
( unsigned int ) V_2 -> V_50 -> V_135 ) ;
F_61 ( & V_97 [ * V_103 ] ,
V_2 -> V_50 -> V_135 ,
V_100 -> V_138 ,
V_113 , ( V_126 == NULL ) ? 0 : 1 ) ;
} else {
F_9 ( L_33
L_34 ,
( unsigned int ) V_2 -> V_50 -> V_135 ,
( unsigned int ) V_2 -> V_50 -> V_135 +
( T_1 ) V_140 *
V_100 -> V_141 ) ;
F_61 ( & V_97 [ * V_103 ] ,
( V_2 -> V_50 -> V_135 +
V_140 *
V_100 -> V_138 ) ,
V_100 -> V_142 , V_113 , ( V_126 == NULL ) ? 0 : 1 ) ;
}
if ( V_126 != NULL ) {
F_59 ( & V_97 [ * V_103 ] ) ;
}
F_46 ( & V_97 [ * V_103 ] , V_4 ) ;
( * V_103 ) ++ ;
}
}
static int F_62 ( struct V_46 * V_47 ,
struct V_1 * V_2 ,
struct V_99 * V_100 ,
struct V_123 * V_124 , struct V_123 * V_125 ,
void * V_143 ,
unsigned int V_101 ,
void * V_126 ,
void T_7 * V_144 )
{
int V_145 = 0 ;
T_1 V_146 ;
V_76 ;
F_32 () ;
F_63 ( V_47 , V_100 , V_101 , V_125 , V_124 ) ;
V_143 = V_100 -> V_147 ;
F_35 ( V_148 , V_149 ) ;
V_146 = V_2 -> V_50 -> V_146 ;
if( V_2 -> V_4 == V_136 && V_2 -> V_50 -> V_146 > 0 )
V_2 -> V_50 -> V_146 -- ;
if( V_126 ) {
F_64 ( V_126 , V_145 ) ;
return 0 ;
}
return V_145 ;
}
static int F_65 (
struct V_32 * V_33 ,
struct V_99 * V_100 ,
struct V_123 * V_124 , struct V_123 * V_125 ,
unsigned int V_102 ,
void * V_143 ,
unsigned int V_101 ,
void * V_126 ,
enum V_150 V_104 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
struct V_46 * V_47 = & V_2 -> V_50 -> V_51 -> V_47 ;
T_5 V_97 [ V_151 ] ;
struct V_152 V_153 = {} ;
int V_48 , V_154 = 0 , V_155 = 0 ;
V_76 ;
F_9 ( L_35 ,
( ( V_104 == V_156 ) ? L_36 : L_37 ) ,
V_126 , V_143 , V_102 ) ;
F_11 () ;
F_32 () ;
if ( F_27 ( F_3 ( V_2 , V_102 ) ) ) {
F_13 ( L_38 , V_102 ) ;
F_33 ( V_33 , V_157 ) ;
return - V_19 ;
}
if ( V_102 == 0 ) {
return 0 ;
}
if ( ( ( V_102 % V_22 ) == 0 ) && ( V_2 -> V_8 == V_23 ) ) {
V_2 -> V_8 = V_27 ;
V_155 = 1 ;
}
V_153 . V_158 = ( void * ) V_159 ;
V_153 . V_160 = ( void * ) V_126 ;
#ifdef F_66
V_153 . V_106 = ( V_104 == V_161 ) ?
V_162 : V_163 ;
#endif
V_100 -> V_105 . V_106 = V_104 ;
F_35 ( V_153 . V_106 , V_87 ) ;
F_32 () ;
V_48 = F_67 ( V_2 -> V_50 , V_100 , V_101 , V_102 , V_143 , V_125 , V_124 ) ;
if ( F_27 ( V_48 != 0 ) ) {
F_13 ( L_39 ) ;
goto V_164;
}
F_35 ( V_153 . V_106 , V_98 ) ;
F_32 () ;
#if V_16
if ( V_2 -> V_4 == V_17 ) {
F_54 ( V_33 ,
V_100 ,
V_101 ,
V_97 ,
& V_154 ) ;
} else
#endif
{
F_42 ( V_33 ,
V_100 ,
V_101 ,
V_102 ,
V_97 ,
& V_154 ) ;
}
F_56 ( V_33 ,
V_100 ,
V_124 , V_125 ,
V_102 ,
V_126 ,
V_97 , & V_154 ) ;
if ( V_100 -> V_165 == true ) {
V_153 . V_166 [ 0 ] = V_100 -> V_105 . V_107 ;
V_153 . V_167 = 1 ;
V_153 . V_168 = V_101 ;
}
F_35 ( V_153 . V_106 , V_169 ) ;
F_32 () ;
V_48 = F_68 ( V_2 -> V_50 , & V_153 , V_97 , V_154 , ( V_126 == NULL ) ? 0 : 1 ) ;
if( V_126 != NULL ) {
if ( F_27 ( V_48 != - V_170 ) ) {
F_63 ( V_47 , V_100 , V_101 , V_125 , V_124 ) ;
}
F_35 ( V_153 . V_106 , V_171 ) ;
} else {
if ( V_48 != 0 ) {
F_63 ( V_47 , V_100 , V_101 , V_125 , V_124 ) ;
F_35 ( V_153 . V_106 , V_171 ) ;
} else {
F_35 ( V_153 . V_106 , V_171 ) ;
V_48 = F_62 ( V_47 , V_2 , V_100 , V_124 , V_125 , V_143 , V_101 , NULL , V_2 -> V_50 -> V_144 ) ;
}
}
V_164:
if ( V_155 != 0 )
V_2 -> V_8 = V_23 ;
return V_48 ;
}
static void V_159 ( struct V_46 * V_47 , void * V_153 , void T_7 * V_144 )
{
struct V_172 * V_126 = (struct V_172 * ) V_153 ;
struct V_99 * V_100 = F_69 ( V_126 ) ;
struct V_173 * V_33 = F_70 ( V_126 ) ;
struct V_1 * V_2 = F_71 ( V_33 ) ;
unsigned int V_101 = F_72 ( V_33 ) ;
F_73 () ;
F_62 ( V_47 , V_2 , V_100 , V_126 -> V_124 , V_126 -> V_125 , V_126 -> V_143 , V_101 , V_126 , V_144 ) ;
}
static int F_74 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
V_2 -> V_174 = F_12 ( sizeof( struct V_99 ) , V_54 | V_55 ) ;
if ( ! V_2 -> V_174 ) {
F_13 ( L_40 ) ;
return - V_56 ;
}
F_9 ( L_41 ,
V_2 -> V_174 ) ;
return F_7 ( V_33 ) ;
}
static void F_75 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_8 ( V_33 ) ;
F_24 ( V_2 -> V_174 ) ;
F_9 ( L_42 , V_2 -> V_174 ) ;
F_20 ( V_33 ) ;
}
static int F_76 ( struct V_175 * V_97 ,
struct V_123 * V_124 , struct V_123 * V_125 ,
unsigned int V_102 )
{
struct V_176 * V_177 = V_97 -> V_33 ;
struct V_32 * V_33 = F_77 ( V_177 ) ;
struct V_1 * V_2 = F_8 ( V_33 ) ;
struct V_99 * V_100 = V_2 -> V_174 ;
unsigned int V_101 = F_78 ( V_177 ) ;
V_100 -> V_147 = V_97 -> V_143 ;
V_100 -> V_165 = false ;
return F_65 ( V_33 , V_100 , V_124 , V_125 , V_102 , V_97 -> V_143 , V_101 , NULL , V_156 ) ;
}
static int F_79 ( struct V_175 * V_97 ,
struct V_123 * V_124 , struct V_123 * V_125 ,
unsigned int V_102 )
{
struct V_176 * V_177 = V_97 -> V_33 ;
struct V_32 * V_33 = F_77 ( V_177 ) ;
struct V_1 * V_2 = F_8 ( V_33 ) ;
struct V_99 * V_100 = V_2 -> V_174 ;
unsigned int V_101 = F_78 ( V_177 ) ;
V_100 -> V_147 = V_97 -> V_143 ;
V_100 -> V_165 = false ;
return F_65 ( V_33 , V_100 , V_124 , V_125 , V_102 , V_97 -> V_143 , V_101 , NULL , V_161 ) ;
}
static int F_80 ( struct V_32 * V_33 )
{
struct V_178 * V_179 = & V_33 -> V_180 ;
V_179 -> V_181 = sizeof( struct V_99 ) ;
return F_7 ( V_33 ) ;
}
static int F_81 ( struct V_173 * V_33 ,
const T_2 * V_53 ,
unsigned int V_60 )
{
return F_30 ( F_82 ( V_33 ) , V_53 , V_60 ) ;
}
static int F_83 ( struct V_172 * V_182 )
{
struct V_173 * V_183 = F_70 ( V_182 ) ;
struct V_32 * V_33 = F_82 ( V_183 ) ;
struct V_99 * V_100 = F_69 ( V_182 ) ;
unsigned int V_101 = F_72 ( V_183 ) ;
V_100 -> V_147 = V_182 -> V_143 ;
V_100 -> V_165 = false ;
return F_65 ( V_33 , V_100 , V_182 -> V_124 , V_182 -> V_125 , V_182 -> V_102 , V_182 -> V_143 , V_101 , ( void * ) V_182 , V_156 ) ;
}
static int F_84 ( struct V_172 * V_182 )
{
struct V_173 * V_183 = F_70 ( V_182 ) ;
struct V_32 * V_33 = F_82 ( V_183 ) ;
struct V_99 * V_100 = F_69 ( V_182 ) ;
unsigned int V_101 = F_72 ( V_183 ) ;
V_100 -> V_147 = V_182 -> V_143 ;
V_100 -> V_165 = false ;
return F_65 ( V_33 , V_100 , V_182 -> V_124 , V_182 -> V_125 , V_182 -> V_102 , V_182 -> V_143 , V_101 , ( void * ) V_182 , V_161 ) ;
}
static
struct V_34 * F_85 ( struct V_184 * V_185 )
{
struct V_34 * V_186 ;
struct V_37 * V_45 ;
V_186 = F_86 ( sizeof( struct V_34 ) , V_54 ) ;
if ( ! V_186 ) {
F_13 ( L_43 ) ;
return F_87 ( - V_56 ) ;
}
V_45 = & V_186 -> V_37 ;
snprintf ( V_45 -> V_187 , V_188 , L_44 , V_185 -> V_189 ) ;
snprintf ( V_45 -> V_190 , V_188 , L_44 ,
V_185 -> V_191 ) ;
V_45 -> V_192 = V_193 ;
V_45 -> V_194 = V_195 ;
V_45 -> V_196 = V_185 -> V_197 ;
V_45 -> V_198 = 0 ;
V_45 -> V_199 = sizeof( struct V_1 ) ;
V_45 -> V_200 = V_185 -> V_201 ? F_74 : F_80 ;
V_45 -> V_202 = V_185 -> V_201 ? F_75 : F_20 ;
V_45 -> V_203 = V_185 -> V_201 ? & V_204 : & V_205 ;
if( V_185 -> V_201 ) {
V_45 -> V_44 = V_185 -> V_206 ;
V_45 -> V_38 = V_207 |
V_185 -> type ;
} else {
V_45 -> V_41 = V_185 -> V_208 ;
V_45 -> V_38 = V_209 | V_207 |
V_185 -> type ;
}
V_186 -> V_8 = V_185 -> V_8 ;
V_186 -> V_4 = V_185 -> V_4 ;
return V_186 ;
}
int F_88 ( struct V_210 * V_50 )
{
struct V_34 * V_186 , * V_211 ;
struct V_212 * V_213 =
V_50 -> V_213 ;
struct V_46 * V_47 ;
V_47 = & V_50 -> V_51 -> V_47 ;
if ( V_213 != NULL ) {
F_89 (t_alg, n,
&blkcipher_handle->blkcipher_alg_list,
entry) {
F_90 ( & V_186 -> V_37 ) ;
F_91 ( & V_186 -> V_214 ) ;
F_24 ( V_186 ) ;
}
F_24 ( V_213 ) ;
V_50 -> V_213 = NULL ;
}
return 0 ;
}
int F_92 ( struct V_210 * V_50 )
{
struct V_212 * V_215 ;
struct V_34 * V_186 ;
int V_48 = - V_56 ;
int V_45 ;
V_215 = F_12 ( sizeof( struct V_212 ) ,
V_54 ) ;
if ( V_215 == NULL )
return - V_56 ;
V_50 -> V_213 = V_215 ;
F_93 ( & V_215 -> V_216 ) ;
F_9 ( L_45 , F_94 ( V_217 ) ) ;
for ( V_45 = 0 ; V_45 < F_94 ( V_217 ) ; V_45 ++ ) {
F_9 ( L_46 , V_217 [ V_45 ] . V_191 ) ;
V_186 = F_85 ( & V_217 [ V_45 ] ) ;
if ( F_18 ( V_186 ) ) {
V_48 = F_19 ( V_186 ) ;
F_13 ( L_47 ,
V_217 [ V_45 ] . V_191 ) ;
goto V_218;
}
V_186 -> V_50 = V_50 ;
F_9 ( L_48 , V_217 [ V_45 ] . V_191 ) ;
V_48 = F_95 ( & V_186 -> V_37 ) ;
F_9 ( L_49 ,
V_186 -> V_37 . V_190 , V_48 ) ;
if ( F_27 ( V_48 != 0 ) ) {
F_13 ( L_50 ,
V_186 -> V_37 . V_190 ) ;
F_24 ( V_186 ) ;
goto V_218;
} else {
F_96 ( & V_186 -> V_214 ,
& V_215 -> V_216 ) ;
F_9 ( L_51 ,
V_186 -> V_37 . V_190 ) ;
}
}
return 0 ;
V_218:
F_88 ( V_50 ) ;
return V_48 ;
}
