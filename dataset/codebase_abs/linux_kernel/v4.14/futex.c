static int T_1 F_1 ( char * V_1 )
{
return F_2 ( & V_2 . V_3 , V_1 ) ;
}
static bool F_3 ( bool V_4 )
{
if ( V_2 . V_5 && ! V_4 )
return false ;
return F_4 ( & V_2 . V_3 , 1 ) ;
}
static int T_1 F_5 ( void )
{
T_2 V_6 = V_7 | V_8 | V_9 ;
struct V_10 * V_11 ;
V_11 = F_6 ( L_1 , NULL ,
& V_2 . V_3 ) ;
if ( F_7 ( V_11 ) )
return F_8 ( V_11 ) ;
if ( ! F_9 ( L_2 , V_6 , V_11 ,
& V_2 . V_5 ) ) {
F_10 ( V_11 ) ;
return - V_12 ;
}
return 0 ;
}
static inline bool F_3 ( bool V_4 )
{
return false ;
}
static inline void F_11 ( union V_13 * V_14 )
{
F_12 ( V_14 -> V_15 . V_16 ) ;
F_13 () ;
}
static inline void F_14 ( struct V_17 * V_18 )
{
#ifdef F_15
F_16 ( & V_18 -> V_19 ) ;
F_13 () ;
#endif
}
static inline void F_17 ( struct V_17 * V_18 )
{
#ifdef F_15
F_18 ( & V_18 -> V_19 ) ;
#endif
}
static inline int F_19 ( struct V_17 * V_18 )
{
#ifdef F_15
return F_20 ( & V_18 -> V_19 ) ;
#else
return 1 ;
#endif
}
static struct V_17 * F_21 ( union V_13 * V_14 )
{
T_3 V_20 = F_22 ( ( T_3 * ) & V_14 -> V_21 . V_22 ,
( sizeof( V_14 -> V_21 . V_22 ) + sizeof( V_14 -> V_21 . V_23 ) ) / 4 ,
V_14 -> V_21 . V_24 ) ;
return & V_25 [ V_20 & ( V_26 - 1 ) ] ;
}
static inline int F_23 ( union V_13 * V_27 , union V_13 * V_28 )
{
return ( V_27 && V_28
&& V_27 -> V_21 . V_22 == V_28 -> V_21 . V_22
&& V_27 -> V_21 . V_23 == V_28 -> V_21 . V_23
&& V_27 -> V_21 . V_24 == V_28 -> V_21 . V_24 ) ;
}
static void F_24 ( union V_13 * V_14 )
{
if ( ! V_14 -> V_21 . V_23 )
return;
if ( ! F_25 ( V_29 ) ) {
F_26 () ;
return;
}
switch ( V_14 -> V_21 . V_24 & ( V_30 | V_31 ) ) {
case V_30 :
F_27 ( V_14 -> V_32 . V_33 ) ;
break;
case V_31 :
F_11 ( V_14 ) ;
break;
default:
F_26 () ;
}
}
static void F_28 ( union V_13 * V_14 )
{
if ( ! V_14 -> V_21 . V_23 ) {
F_29 ( 1 ) ;
return;
}
if ( ! F_25 ( V_29 ) )
return;
switch ( V_14 -> V_21 . V_24 & ( V_30 | V_31 ) ) {
case V_30 :
F_30 ( V_14 -> V_32 . V_33 ) ;
break;
case V_31 :
F_31 ( V_14 -> V_15 . V_16 ) ;
break;
}
}
static int
F_32 ( T_3 T_4 * V_34 , int V_4 , union V_13 * V_14 , int V_35 )
{
unsigned long V_36 = ( unsigned long ) V_34 ;
struct V_37 * V_16 = V_38 -> V_16 ;
struct V_39 * V_39 , * V_40 ;
struct V_41 * V_42 ;
int V_43 , V_44 = 0 ;
V_14 -> V_21 . V_24 = V_36 % V_45 ;
if ( F_33 ( ( V_36 % sizeof( T_3 ) ) != 0 ) )
return - V_46 ;
V_36 -= V_14 -> V_21 . V_24 ;
if ( F_33 ( ! F_34 ( V_35 , V_34 , sizeof( T_3 ) ) ) )
return - V_47 ;
if ( F_33 ( F_3 ( V_4 ) ) )
return - V_47 ;
if ( ! V_4 ) {
V_14 -> V_15 . V_16 = V_16 ;
V_14 -> V_15 . V_36 = V_36 ;
F_24 ( V_14 ) ;
return 0 ;
}
V_48:
if ( F_33 ( F_3 ( V_4 ) ) )
return - V_47 ;
V_43 = F_35 ( V_36 , 1 , 1 , & V_39 ) ;
if ( V_43 == - V_47 && V_35 == V_49 ) {
V_43 = F_35 ( V_36 , 1 , 0 , & V_39 ) ;
V_44 = 1 ;
}
if ( V_43 < 0 )
return V_43 ;
else
V_43 = 0 ;
V_40 = V_39 ;
V_39 = F_36 ( V_39 ) ;
V_42 = F_37 ( V_39 -> V_42 ) ;
if ( F_33 ( ! V_42 ) ) {
int V_50 ;
F_38 ( V_39 ) ;
V_50 = F_39 ( V_39 ) || V_39 -> V_42 ;
F_40 ( V_39 ) ;
F_41 ( V_39 ) ;
if ( V_50 )
goto V_48;
return - V_47 ;
}
if ( F_42 ( V_39 ) ) {
if ( F_33 ( F_3 ( V_4 ) ) || V_44 ) {
V_43 = - V_47 ;
goto V_51;
}
V_14 -> V_21 . V_24 |= V_31 ;
V_14 -> V_15 . V_16 = V_16 ;
V_14 -> V_15 . V_36 = V_36 ;
F_24 ( V_14 ) ;
} else {
struct V_33 * V_33 ;
F_43 () ;
if ( F_37 ( V_39 -> V_42 ) != V_42 ) {
F_44 () ;
F_41 ( V_39 ) ;
goto V_48;
}
V_33 = F_37 ( V_42 -> V_52 ) ;
if ( ! V_33 ) {
F_44 () ;
F_41 ( V_39 ) ;
goto V_48;
}
if ( ! F_45 ( & V_33 -> V_53 ) ) {
F_44 () ;
F_41 ( V_39 ) ;
goto V_48;
}
if ( F_29 ( V_33 -> V_54 != V_42 ) ) {
V_43 = - V_47 ;
F_44 () ;
F_30 ( V_33 ) ;
goto V_51;
}
V_14 -> V_21 . V_24 |= V_30 ;
V_14 -> V_32 . V_33 = V_33 ;
V_14 -> V_32 . V_55 = F_46 ( V_40 ) ;
F_44 () ;
}
V_51:
F_41 ( V_39 ) ;
return V_43 ;
}
static inline void F_47 ( union V_13 * V_14 )
{
F_28 ( V_14 ) ;
}
static int F_48 ( T_3 T_4 * V_34 )
{
struct V_37 * V_16 = V_38 -> V_16 ;
int V_56 ;
F_49 ( & V_16 -> V_57 ) ;
V_56 = F_50 ( V_38 , V_16 , ( unsigned long ) V_34 ,
V_58 , NULL ) ;
F_51 ( & V_16 -> V_57 ) ;
return V_56 < 0 ? V_56 : 0 ;
}
static struct V_59 * F_52 ( struct V_17 * V_18 ,
union V_13 * V_14 )
{
struct V_59 * V_60 ;
F_53 (this, &hb->chain, list) {
if ( F_23 ( & V_60 -> V_14 , V_14 ) )
return V_60 ;
}
return NULL ;
}
static int F_54 ( T_3 * V_61 , T_3 T_4 * V_34 ,
T_3 V_62 , T_3 V_63 )
{
int V_56 ;
F_55 () ;
V_56 = F_56 ( V_61 , V_34 , V_62 , V_63 ) ;
F_57 () ;
return V_56 ;
}
static int F_58 ( T_3 * V_64 , T_3 T_4 * V_65 )
{
int V_56 ;
F_55 () ;
V_56 = F_59 ( * V_64 , V_65 ) ;
F_57 () ;
return V_56 ? - V_47 : 0 ;
}
static int F_60 ( void )
{
struct V_66 * V_67 ;
if ( F_61 ( V_38 -> V_68 ) )
return 0 ;
V_67 = F_62 ( sizeof( * V_67 ) , V_69 ) ;
if ( ! V_67 )
return - V_12 ;
F_63 ( & V_67 -> V_70 ) ;
V_67 -> V_71 = NULL ;
F_64 ( & V_67 -> V_72 , 1 ) ;
V_67 -> V_14 = V_73 ;
V_38 -> V_68 = V_67 ;
return 0 ;
}
static struct V_66 * F_65 ( void )
{
struct V_66 * V_67 = V_38 -> V_68 ;
F_66 ( ! V_67 ) ;
V_38 -> V_68 = NULL ;
return V_67 ;
}
static void F_67 ( struct V_66 * V_67 )
{
F_29 ( ! F_45 ( & V_67 -> V_72 ) ) ;
}
static void F_68 ( struct V_66 * V_67 )
{
if ( ! V_67 )
return;
if ( ! F_69 ( & V_67 -> V_72 ) )
return;
if ( V_67 -> V_71 ) {
struct V_74 * V_71 ;
F_70 ( & V_67 -> V_75 . V_76 ) ;
V_71 = V_67 -> V_71 ;
if ( V_71 ) {
F_71 ( & V_71 -> V_77 ) ;
F_72 ( & V_67 -> V_70 ) ;
F_73 ( & V_71 -> V_77 ) ;
}
F_74 ( & V_67 -> V_75 , V_71 ) ;
F_75 ( & V_67 -> V_75 . V_76 ) ;
}
if ( V_38 -> V_68 ) {
F_76 ( V_67 ) ;
} else {
V_67 -> V_71 = NULL ;
F_64 ( & V_67 -> V_72 , 1 ) ;
V_38 -> V_68 = V_67 ;
}
}
static struct V_74 * F_77 ( T_5 V_78 )
{
struct V_74 * V_79 ;
F_43 () ;
V_79 = F_78 ( V_78 ) ;
if ( V_79 )
F_79 ( V_79 ) ;
F_44 () ;
return V_79 ;
}
void F_80 ( struct V_74 * V_80 )
{
struct V_81 * V_82 , * V_83 = & V_80 -> V_84 ;
struct V_66 * V_67 ;
struct V_17 * V_18 ;
union V_13 V_14 = V_73 ;
if ( ! V_85 )
return;
F_70 ( & V_80 -> V_77 ) ;
while ( ! F_81 ( V_83 ) ) {
V_82 = V_83 -> V_82 ;
V_67 = F_82 ( V_82 , struct V_66 , V_70 ) ;
V_14 = V_67 -> V_14 ;
V_18 = F_21 ( & V_14 ) ;
if ( ! F_45 ( & V_67 -> V_72 ) ) {
F_75 ( & V_80 -> V_77 ) ;
F_83 () ;
F_70 ( & V_80 -> V_77 ) ;
continue;
}
F_75 ( & V_80 -> V_77 ) ;
F_84 ( & V_18 -> V_86 ) ;
F_70 ( & V_67 -> V_75 . V_76 ) ;
F_71 ( & V_80 -> V_77 ) ;
if ( V_83 -> V_82 != V_82 ) {
F_73 ( & V_67 -> V_75 . V_76 ) ;
F_85 ( & V_18 -> V_86 ) ;
F_68 ( V_67 ) ;
continue;
}
F_66 ( V_67 -> V_71 != V_80 ) ;
F_66 ( F_81 ( & V_67 -> V_70 ) ) ;
F_72 ( & V_67 -> V_70 ) ;
V_67 -> V_71 = NULL ;
F_73 ( & V_80 -> V_77 ) ;
F_75 ( & V_67 -> V_75 . V_76 ) ;
F_85 ( & V_18 -> V_86 ) ;
F_86 ( & V_67 -> V_75 ) ;
F_68 ( V_67 ) ;
F_70 ( & V_80 -> V_77 ) ;
}
F_75 ( & V_80 -> V_77 ) ;
}
static int F_87 ( T_3 T_4 * V_34 , T_3 V_62 ,
struct V_66 * V_67 ,
struct V_66 * * V_87 )
{
T_5 V_78 = V_62 & V_88 ;
T_3 V_89 ;
int V_56 ;
if ( F_33 ( ! V_67 ) )
return - V_46 ;
F_66 ( ! F_20 ( & V_67 -> V_72 ) ) ;
F_70 ( & V_67 -> V_75 . V_76 ) ;
if ( F_58 ( & V_89 , V_34 ) )
goto V_90;
if ( V_62 != V_89 )
goto V_91;
if ( V_62 & V_92 ) {
if ( ! V_67 -> V_71 ) {
if ( V_78 )
goto V_93;
goto V_94;
}
if ( ! V_78 )
goto V_94;
} else {
if ( ! V_67 -> V_71 )
goto V_93;
}
if ( V_78 != F_88 ( V_67 -> V_71 ) )
goto V_93;
V_94:
F_67 ( V_67 ) ;
F_75 ( & V_67 -> V_75 . V_76 ) ;
* V_87 = V_67 ;
return 0 ;
V_93:
V_56 = - V_46 ;
goto V_95;
V_91:
V_56 = - V_96 ;
goto V_95;
V_90:
V_56 = - V_47 ;
goto V_95;
V_95:
F_75 ( & V_67 -> V_75 . V_76 ) ;
return V_56 ;
}
static int F_89 ( T_3 V_62 , union V_13 * V_14 ,
struct V_66 * * V_87 )
{
T_5 V_78 = V_62 & V_88 ;
struct V_66 * V_67 ;
struct V_74 * V_79 ;
if ( ! V_78 )
return - V_97 ;
V_79 = F_77 ( V_78 ) ;
if ( ! V_79 )
return - V_97 ;
if ( F_33 ( V_79 -> V_98 & V_99 ) ) {
F_90 ( V_79 ) ;
return - V_100 ;
}
F_70 ( & V_79 -> V_77 ) ;
if ( F_33 ( V_79 -> V_98 & V_101 ) ) {
int V_56 = ( V_79 -> V_98 & V_102 ) ? - V_97 : - V_96 ;
F_75 ( & V_79 -> V_77 ) ;
F_90 ( V_79 ) ;
return V_56 ;
}
V_67 = F_65 () ;
F_91 ( & V_67 -> V_75 , V_79 ) ;
V_67 -> V_14 = * V_14 ;
F_66 ( ! F_81 ( & V_67 -> V_70 ) ) ;
F_92 ( & V_67 -> V_70 , & V_79 -> V_84 ) ;
V_67 -> V_71 = V_79 ;
F_75 ( & V_79 -> V_77 ) ;
F_90 ( V_79 ) ;
* V_87 = V_67 ;
return 0 ;
}
static int F_93 ( T_3 T_4 * V_34 , T_3 V_62 ,
struct V_17 * V_18 ,
union V_13 * V_14 , struct V_66 * * V_87 )
{
struct V_59 * V_103 = F_52 ( V_18 , V_14 ) ;
if ( V_103 )
return F_87 ( V_34 , V_62 , V_103 -> V_67 , V_87 ) ;
return F_89 ( V_62 , V_14 , V_87 ) ;
}
static int F_94 ( T_3 T_4 * V_34 , T_3 V_62 , T_3 V_63 )
{
T_3 V_104 ( V_61 ) ;
if ( F_33 ( F_3 ( true ) ) )
return - V_47 ;
if ( F_33 ( F_54 ( & V_61 , V_34 , V_62 , V_63 ) ) )
return - V_47 ;
return V_61 != V_62 ? - V_96 : 0 ;
}
static int F_95 ( T_3 T_4 * V_34 , struct V_17 * V_18 ,
union V_13 * V_14 ,
struct V_66 * * V_87 ,
struct V_74 * V_105 , int V_106 )
{
T_3 V_62 , V_63 , V_107 = F_88 ( V_105 ) ;
struct V_59 * V_103 ;
int V_56 ;
if ( F_58 ( & V_62 , V_34 ) )
return - V_47 ;
if ( F_33 ( F_3 ( true ) ) )
return - V_47 ;
if ( ( F_33 ( ( V_62 & V_88 ) == V_107 ) ) )
return - V_108 ;
if ( ( F_33 ( F_3 ( true ) ) ) )
return - V_108 ;
V_103 = F_52 ( V_18 , V_14 ) ;
if ( V_103 )
return F_87 ( V_34 , V_62 , V_103 -> V_67 , V_87 ) ;
if ( ! ( V_62 & V_88 ) ) {
V_63 = V_62 & V_92 ;
V_63 |= V_107 ;
if ( V_106 )
V_63 |= V_109 ;
V_56 = F_94 ( V_34 , V_62 , V_63 ) ;
return V_56 < 0 ? V_56 : 1 ;
}
V_63 = V_62 | V_109 ;
V_56 = F_94 ( V_34 , V_62 , V_63 ) ;
if ( V_56 )
return V_56 ;
return F_89 ( V_62 , V_14 , V_87 ) ;
}
static void F_96 ( struct V_59 * V_110 )
{
struct V_17 * V_18 ;
if ( F_97 ( ! V_110 -> V_111 || ! F_98 ( V_110 -> V_111 ) )
|| F_66 ( F_99 ( & V_110 -> V_70 ) ) )
return;
V_18 = F_100 ( V_110 -> V_111 , struct V_17 , V_86 ) ;
F_101 ( & V_110 -> V_70 , & V_18 -> V_112 ) ;
F_17 ( V_18 ) ;
}
static void F_102 ( struct V_113 * V_114 , struct V_59 * V_110 )
{
struct V_74 * V_79 = V_110 -> V_105 ;
if ( F_103 ( V_110 -> V_67 || V_110 -> V_115 , L_3 ) )
return;
F_104 ( V_114 , V_79 ) ;
F_96 ( V_110 ) ;
F_105 ( & V_110 -> V_111 , NULL ) ;
}
static int F_106 ( T_3 T_4 * V_34 , T_3 V_62 , struct V_66 * V_67 )
{
T_3 V_104 ( V_61 ) , V_63 ;
struct V_74 * V_116 ;
bool V_117 = false ;
F_107 ( V_114 ) ;
int V_56 = 0 ;
V_116 = F_108 ( & V_67 -> V_75 ) ;
if ( F_29 ( ! V_116 ) ) {
V_56 = - V_96 ;
goto V_118;
}
V_63 = V_109 | F_88 ( V_116 ) ;
if ( F_33 ( F_3 ( true ) ) )
V_56 = - V_47 ;
if ( F_54 ( & V_61 , V_34 , V_62 , V_63 ) ) {
V_56 = - V_47 ;
} else if ( V_61 != V_62 ) {
if ( ( V_88 & V_61 ) == V_62 )
V_56 = - V_96 ;
else
V_56 = - V_46 ;
}
if ( V_56 )
goto V_118;
F_71 ( & V_67 -> V_71 -> V_77 ) ;
F_66 ( F_81 ( & V_67 -> V_70 ) ) ;
F_72 ( & V_67 -> V_70 ) ;
F_73 ( & V_67 -> V_71 -> V_77 ) ;
F_71 ( & V_116 -> V_77 ) ;
F_66 ( ! F_81 ( & V_67 -> V_70 ) ) ;
F_92 ( & V_67 -> V_70 , & V_116 -> V_84 ) ;
V_67 -> V_71 = V_116 ;
F_73 ( & V_116 -> V_77 ) ;
V_117 = F_109 ( & V_67 -> V_75 , & V_114 ) ;
V_118:
F_75 ( & V_67 -> V_75 . V_76 ) ;
if ( V_117 )
F_110 ( & V_114 ) ;
return V_56 ;
}
static inline void
F_111 ( struct V_17 * V_119 , struct V_17 * V_120 )
{
if ( V_119 <= V_120 ) {
F_84 ( & V_119 -> V_86 ) ;
if ( V_119 < V_120 )
F_112 ( & V_120 -> V_86 , V_121 ) ;
} else {
F_84 ( & V_120 -> V_86 ) ;
F_112 ( & V_119 -> V_86 , V_121 ) ;
}
}
static inline void
F_113 ( struct V_17 * V_119 , struct V_17 * V_120 )
{
F_85 ( & V_119 -> V_86 ) ;
if ( V_119 != V_120 )
F_85 ( & V_120 -> V_86 ) ;
}
static int
F_114 ( T_3 T_4 * V_34 , unsigned int V_98 , int V_122 , T_3 V_123 )
{
struct V_17 * V_18 ;
struct V_59 * V_60 , * V_82 ;
union V_13 V_14 = V_73 ;
int V_56 ;
F_107 ( V_114 ) ;
if ( ! V_123 )
return - V_46 ;
V_56 = F_32 ( V_34 , V_98 & V_124 , & V_14 , V_49 ) ;
if ( F_33 ( V_56 != 0 ) )
goto V_51;
V_18 = F_21 ( & V_14 ) ;
if ( ! F_19 ( V_18 ) )
goto V_125;
F_84 ( & V_18 -> V_86 ) ;
F_115 (this, next, &hb->chain, list) {
if ( F_23 ( & V_60 -> V_14 , & V_14 ) ) {
if ( V_60 -> V_67 || V_60 -> V_115 ) {
V_56 = - V_46 ;
break;
}
if ( ! ( V_60 -> V_123 & V_123 ) )
continue;
F_102 ( & V_114 , V_60 ) ;
if ( ++ V_56 >= V_122 )
break;
}
}
F_85 ( & V_18 -> V_86 ) ;
F_116 ( & V_114 ) ;
V_125:
F_47 ( & V_14 ) ;
V_51:
return V_56 ;
}
static int F_117 ( unsigned int V_126 , T_3 T_4 * V_34 )
{
unsigned int V_127 = ( V_126 & 0x70000000 ) >> 28 ;
unsigned int V_128 = ( V_126 & 0x0f000000 ) >> 24 ;
int V_129 = F_118 ( ( V_126 & 0x00fff000 ) >> 12 , 12 ) ;
int V_130 = F_118 ( V_126 & 0x00000fff , 12 ) ;
int V_131 , V_56 ;
if ( V_126 & ( V_132 << 28 ) ) {
if ( V_129 < 0 || V_129 > 31 ) {
char V_133 [ sizeof( V_38 -> V_133 ) ] ;
F_119 ( L_4 ,
F_120 ( V_133 , V_38 ) , V_129 ) ;
V_129 &= 31 ;
}
V_129 = 1 << V_129 ;
}
if ( ! F_34 ( V_134 , V_34 , sizeof( T_3 ) ) )
return - V_47 ;
V_56 = F_121 ( V_127 , V_129 , & V_131 , V_34 ) ;
if ( V_56 )
return V_56 ;
switch ( V_128 ) {
case V_135 :
return V_131 == V_130 ;
case V_136 :
return V_131 != V_130 ;
case V_137 :
return V_131 < V_130 ;
case V_138 :
return V_131 >= V_130 ;
case V_139 :
return V_131 <= V_130 ;
case V_140 :
return V_131 > V_130 ;
default:
return - V_141 ;
}
}
static int
F_122 ( T_3 T_4 * V_142 , unsigned int V_98 , T_3 T_4 * V_143 ,
int V_122 , int V_144 , int V_127 )
{
union V_13 V_27 = V_73 , V_28 = V_73 ;
struct V_17 * V_119 , * V_120 ;
struct V_59 * V_60 , * V_82 ;
int V_56 , V_145 ;
F_107 ( V_114 ) ;
V_146:
V_56 = F_32 ( V_142 , V_98 & V_124 , & V_27 , V_49 ) ;
if ( F_33 ( V_56 != 0 ) )
goto V_51;
V_56 = F_32 ( V_143 , V_98 & V_124 , & V_28 , V_134 ) ;
if ( F_33 ( V_56 != 0 ) )
goto V_147;
V_119 = F_21 ( & V_27 ) ;
V_120 = F_21 ( & V_28 ) ;
V_148:
F_111 ( V_119 , V_120 ) ;
V_145 = F_117 ( V_127 , V_143 ) ;
if ( F_33 ( V_145 < 0 ) ) {
F_113 ( V_119 , V_120 ) ;
#ifndef V_29
V_56 = V_145 ;
goto V_149;
#endif
if ( F_33 ( V_145 != - V_47 ) ) {
V_56 = V_145 ;
goto V_149;
}
V_56 = F_48 ( V_143 ) ;
if ( V_56 )
goto V_149;
if ( ! ( V_98 & V_124 ) )
goto V_148;
F_47 ( & V_28 ) ;
F_47 ( & V_27 ) ;
goto V_146;
}
F_115 (this, next, &hb1->chain, list) {
if ( F_23 ( & V_60 -> V_14 , & V_27 ) ) {
if ( V_60 -> V_67 || V_60 -> V_115 ) {
V_56 = - V_46 ;
goto V_118;
}
F_102 ( & V_114 , V_60 ) ;
if ( ++ V_56 >= V_122 )
break;
}
}
if ( V_145 > 0 ) {
V_145 = 0 ;
F_115 (this, next, &hb2->chain, list) {
if ( F_23 ( & V_60 -> V_14 , & V_28 ) ) {
if ( V_60 -> V_67 || V_60 -> V_115 ) {
V_56 = - V_46 ;
goto V_118;
}
F_102 ( & V_114 , V_60 ) ;
if ( ++ V_145 >= V_144 )
break;
}
}
V_56 += V_145 ;
}
V_118:
F_113 ( V_119 , V_120 ) ;
F_116 ( & V_114 ) ;
V_149:
F_47 ( & V_28 ) ;
V_147:
F_47 ( & V_27 ) ;
V_51:
return V_56 ;
}
static inline
void F_123 ( struct V_59 * V_110 , struct V_17 * V_119 ,
struct V_17 * V_120 , union V_13 * V_28 )
{
if ( F_61 ( & V_119 -> V_112 != & V_120 -> V_112 ) ) {
F_101 ( & V_110 -> V_70 , & V_119 -> V_112 ) ;
F_17 ( V_119 ) ;
F_14 ( V_120 ) ;
F_124 ( & V_110 -> V_70 , & V_120 -> V_112 ) ;
V_110 -> V_111 = & V_120 -> V_86 ;
}
F_24 ( V_28 ) ;
V_110 -> V_14 = * V_28 ;
}
static inline
void F_125 ( struct V_59 * V_110 , union V_13 * V_14 ,
struct V_17 * V_18 )
{
F_24 ( V_14 ) ;
V_110 -> V_14 = * V_14 ;
F_96 ( V_110 ) ;
F_66 ( ! V_110 -> V_115 ) ;
V_110 -> V_115 = NULL ;
V_110 -> V_111 = & V_18 -> V_86 ;
F_126 ( V_110 -> V_105 , V_150 ) ;
}
static int F_127 ( T_3 T_4 * V_151 ,
struct V_17 * V_119 ,
struct V_17 * V_120 ,
union V_13 * V_27 , union V_13 * V_28 ,
struct V_66 * * V_87 , int V_106 )
{
struct V_59 * V_103 = NULL ;
T_3 V_61 ;
int V_56 , V_107 ;
if ( F_58 ( & V_61 , V_151 ) )
return - V_47 ;
if ( F_33 ( F_3 ( true ) ) )
return - V_47 ;
V_103 = F_52 ( V_119 , V_27 ) ;
if ( ! V_103 )
return 0 ;
if ( ! F_23 ( V_103 -> V_152 , V_28 ) )
return - V_46 ;
V_107 = F_88 ( V_103 -> V_105 ) ;
V_56 = F_95 ( V_151 , V_120 , V_28 , V_87 , V_103 -> V_105 ,
V_106 ) ;
if ( V_56 == 1 ) {
F_125 ( V_103 , V_28 , V_120 ) ;
return V_107 ;
}
return V_56 ;
}
static int F_128 ( T_3 T_4 * V_142 , unsigned int V_98 ,
T_3 T_4 * V_143 , int V_122 , int V_153 ,
T_3 * V_154 , int V_155 )
{
union V_13 V_27 = V_73 , V_28 = V_73 ;
int V_156 = 0 , V_157 = 0 , V_56 ;
struct V_66 * V_67 = NULL ;
struct V_17 * V_119 , * V_120 ;
struct V_59 * V_60 , * V_82 ;
F_107 ( V_114 ) ;
if ( ! F_25 ( V_158 ) && V_155 )
return - V_141 ;
if ( V_155 ) {
if ( V_142 == V_143 )
return - V_46 ;
if ( F_60 () )
return - V_12 ;
if ( V_122 != 1 )
return - V_46 ;
}
V_146:
V_56 = F_32 ( V_142 , V_98 & V_124 , & V_27 , V_49 ) ;
if ( F_33 ( V_56 != 0 ) )
goto V_51;
V_56 = F_32 ( V_143 , V_98 & V_124 , & V_28 ,
V_155 ? V_134 : V_49 ) ;
if ( F_33 ( V_56 != 0 ) )
goto V_147;
if ( V_155 && F_23 ( & V_27 , & V_28 ) ) {
V_56 = - V_46 ;
goto V_149;
}
V_119 = F_21 ( & V_27 ) ;
V_120 = F_21 ( & V_28 ) ;
V_148:
F_14 ( V_120 ) ;
F_111 ( V_119 , V_120 ) ;
if ( F_61 ( V_154 != NULL ) ) {
T_3 V_61 ;
V_56 = F_58 ( & V_61 , V_142 ) ;
if ( F_33 ( V_56 ) ) {
F_113 ( V_119 , V_120 ) ;
F_17 ( V_120 ) ;
V_56 = F_129 ( V_61 , V_142 ) ;
if ( V_56 )
goto V_149;
if ( ! ( V_98 & V_124 ) )
goto V_148;
F_47 ( & V_28 ) ;
F_47 ( & V_27 ) ;
goto V_146;
}
if ( V_61 != * V_154 ) {
V_56 = - V_96 ;
goto V_118;
}
}
if ( V_155 && ( V_157 - V_122 < V_153 ) ) {
V_56 = F_127 ( V_143 , V_119 , V_120 , & V_27 ,
& V_28 , & V_67 , V_153 ) ;
if ( V_56 > 0 ) {
F_66 ( V_67 ) ;
V_156 ++ ;
V_157 ++ ;
V_56 = F_93 ( V_143 , V_56 , V_120 , & V_28 , & V_67 ) ;
}
switch ( V_56 ) {
case 0 :
break;
case - V_47 :
F_113 ( V_119 , V_120 ) ;
F_17 ( V_120 ) ;
F_47 ( & V_28 ) ;
F_47 ( & V_27 ) ;
V_56 = F_48 ( V_143 ) ;
if ( ! V_56 )
goto V_146;
goto V_51;
case - V_96 :
F_113 ( V_119 , V_120 ) ;
F_17 ( V_120 ) ;
F_47 ( & V_28 ) ;
F_47 ( & V_27 ) ;
F_130 () ;
goto V_146;
default:
goto V_118;
}
}
F_115 (this, next, &hb1->chain, list) {
if ( V_157 - V_122 >= V_153 )
break;
if ( ! F_23 ( & V_60 -> V_14 , & V_27 ) )
continue;
if ( ( V_155 && ! V_60 -> V_115 ) ||
( ! V_155 && V_60 -> V_115 ) ||
V_60 -> V_67 ) {
V_56 = - V_46 ;
break;
}
if ( ++ V_157 <= V_122 && ! V_155 ) {
F_102 ( & V_114 , V_60 ) ;
continue;
}
if ( V_155 && ! F_23 ( V_60 -> V_152 , & V_28 ) ) {
V_56 = - V_46 ;
break;
}
if ( V_155 ) {
F_67 ( V_67 ) ;
V_60 -> V_67 = V_67 ;
V_56 = F_131 ( & V_67 -> V_75 ,
V_60 -> V_115 ,
V_60 -> V_105 ) ;
if ( V_56 == 1 ) {
F_125 ( V_60 , & V_28 , V_120 ) ;
V_156 ++ ;
continue;
} else if ( V_56 ) {
V_60 -> V_67 = NULL ;
F_68 ( V_67 ) ;
break;
}
}
F_123 ( V_60 , V_119 , V_120 , & V_28 ) ;
V_156 ++ ;
}
F_68 ( V_67 ) ;
V_118:
F_113 ( V_119 , V_120 ) ;
F_116 ( & V_114 ) ;
F_17 ( V_120 ) ;
while ( -- V_156 >= 0 )
F_28 ( & V_27 ) ;
V_149:
F_47 ( & V_28 ) ;
V_147:
F_47 ( & V_27 ) ;
V_51:
return V_56 ? V_56 : V_157 ;
}
static inline struct V_17 * F_132 ( struct V_59 * V_110 )
__acquires( &hb->lock
static inline void
F_133 ( struct V_17 * V_18 )
__releases( &hb->lock
static inline void F_134 ( struct V_59 * V_110 , struct V_17 * V_18 )
{
int V_159 ;
V_159 = F_135 ( V_38 -> V_160 , V_161 ) ;
F_136 ( & V_110 -> V_70 , V_159 ) ;
F_124 ( & V_110 -> V_70 , & V_18 -> V_112 ) ;
V_110 -> V_105 = V_38 ;
}
static inline void F_137 ( struct V_59 * V_110 , struct V_17 * V_18 )
__releases( &hb->lock
static int F_138 ( struct V_59 * V_110 )
{
T_6 * V_111 ;
int V_56 = 0 ;
V_146:
V_111 = F_37 ( V_110 -> V_111 ) ;
if ( V_111 != NULL ) {
F_84 ( V_111 ) ;
if ( F_33 ( V_111 != V_110 -> V_111 ) ) {
F_85 ( V_111 ) ;
goto V_146;
}
F_96 ( V_110 ) ;
F_139 ( V_110 -> V_67 ) ;
F_85 ( V_111 ) ;
V_56 = 1 ;
}
F_28 ( & V_110 -> V_14 ) ;
return V_56 ;
}
static void F_140 ( struct V_59 * V_110 )
__releases( V_110 -> V_111 )
{
F_96 ( V_110 ) ;
F_139 ( ! V_110 -> V_67 ) ;
F_68 ( V_110 -> V_67 ) ;
V_110 -> V_67 = NULL ;
F_85 ( V_110 -> V_111 ) ;
}
static int F_141 ( T_3 T_4 * V_34 , struct V_59 * V_110 ,
struct V_74 * V_162 )
{
T_3 V_163 = F_88 ( V_162 ) | V_109 ;
struct V_66 * V_67 = V_110 -> V_67 ;
T_3 V_62 , V_104 ( V_61 ) , V_63 ;
struct V_74 * V_164 ;
int V_56 ;
F_70 ( & V_67 -> V_75 . V_76 ) ;
V_164 = V_67 -> V_71 ;
if ( ! V_67 -> V_71 )
V_163 |= V_92 ;
V_146:
if ( F_58 ( & V_62 , V_34 ) )
goto V_165;
for (; ; ) {
V_63 = ( V_62 & V_92 ) | V_163 ;
if ( F_54 ( & V_61 , V_34 , V_62 , V_63 ) )
goto V_165;
if ( V_61 == V_62 )
break;
V_62 = V_61 ;
}
if ( V_67 -> V_71 != NULL ) {
F_71 ( & V_67 -> V_71 -> V_77 ) ;
F_66 ( F_81 ( & V_67 -> V_70 ) ) ;
F_72 ( & V_67 -> V_70 ) ;
F_73 ( & V_67 -> V_71 -> V_77 ) ;
}
V_67 -> V_71 = V_162 ;
F_71 ( & V_162 -> V_77 ) ;
F_66 ( ! F_81 ( & V_67 -> V_70 ) ) ;
F_92 ( & V_67 -> V_70 , & V_162 -> V_84 ) ;
F_73 ( & V_162 -> V_77 ) ;
F_75 ( & V_67 -> V_75 . V_76 ) ;
return 0 ;
V_165:
F_75 ( & V_67 -> V_75 . V_76 ) ;
F_85 ( V_110 -> V_111 ) ;
V_56 = F_48 ( V_34 ) ;
F_84 ( V_110 -> V_111 ) ;
F_70 ( & V_67 -> V_75 . V_76 ) ;
if ( V_67 -> V_71 != V_164 ) {
V_56 = 0 ;
goto V_118;
}
if ( V_56 )
goto V_118;
goto V_146;
V_118:
F_75 ( & V_67 -> V_75 . V_76 ) ;
return V_56 ;
}
static int F_142 ( T_3 T_4 * V_34 , struct V_59 * V_110 , int V_166 )
{
int V_56 = 0 ;
if ( V_166 ) {
if ( V_110 -> V_67 -> V_71 != V_38 )
V_56 = F_141 ( V_34 , V_110 , V_38 ) ;
goto V_51;
}
if ( F_143 ( & V_110 -> V_67 -> V_75 ) == V_38 ) {
F_144 ( V_167 L_5
L_6 , V_56 ,
V_110 -> V_67 -> V_75 . V_71 ,
V_110 -> V_67 -> V_71 ) ;
}
V_51:
return V_56 ? V_56 : V_166 ;
}
static void F_145 ( struct V_17 * V_18 , struct V_59 * V_110 ,
struct V_168 * V_169 )
{
F_146 ( V_170 ) ;
F_137 ( V_110 , V_18 ) ;
if ( V_169 )
F_147 ( & V_169 -> V_171 , V_172 ) ;
if ( F_61 ( ! F_99 ( & V_110 -> V_70 ) ) ) {
if ( ! V_169 || V_169 -> V_105 )
F_148 () ;
}
F_149 ( V_173 ) ;
}
static int F_150 ( T_3 T_4 * V_34 , T_3 V_174 , unsigned int V_98 ,
struct V_59 * V_110 , struct V_17 * * V_18 )
{
T_3 V_62 ;
int V_56 ;
V_146:
V_56 = F_32 ( V_34 , V_98 & V_124 , & V_110 -> V_14 , V_49 ) ;
if ( F_33 ( V_56 != 0 ) )
return V_56 ;
V_148:
* V_18 = F_132 ( V_110 ) ;
V_56 = F_58 ( & V_62 , V_34 ) ;
if ( V_56 ) {
F_133 ( * V_18 ) ;
V_56 = F_129 ( V_62 , V_34 ) ;
if ( V_56 )
goto V_51;
if ( ! ( V_98 & V_124 ) )
goto V_148;
F_47 ( & V_110 -> V_14 ) ;
goto V_146;
}
if ( V_62 != V_174 ) {
F_133 ( * V_18 ) ;
V_56 = - V_175 ;
}
V_51:
if ( V_56 )
F_47 ( & V_110 -> V_14 ) ;
return V_56 ;
}
static int F_151 ( T_3 T_4 * V_34 , unsigned int V_98 , T_3 V_174 ,
T_7 * V_176 , T_3 V_123 )
{
struct V_168 V_169 , * V_177 = NULL ;
struct V_178 * V_179 ;
struct V_17 * V_18 ;
struct V_59 V_110 = V_180 ;
int V_56 ;
if ( ! V_123 )
return - V_46 ;
V_110 . V_123 = V_123 ;
if ( V_176 ) {
V_177 = & V_169 ;
F_152 ( & V_177 -> V_171 , ( V_98 & V_181 ) ?
V_182 : V_183 ,
V_172 ) ;
F_153 ( V_177 , V_38 ) ;
F_154 ( & V_177 -> V_171 , * V_176 ,
V_38 -> V_184 ) ;
}
V_146:
V_56 = F_150 ( V_34 , V_174 , V_98 , & V_110 , & V_18 ) ;
if ( V_56 )
goto V_51;
F_145 ( V_18 , & V_110 , V_177 ) ;
V_56 = 0 ;
if ( ! F_138 ( & V_110 ) )
goto V_51;
V_56 = - V_185 ;
if ( V_177 && ! V_177 -> V_105 )
goto V_51;
if ( ! F_155 ( V_38 ) )
goto V_146;
V_56 = - V_186 ;
if ( ! V_176 )
goto V_51;
V_179 = & V_38 -> V_178 ;
V_179 -> V_187 = V_188 ;
V_179 -> V_189 . V_34 = V_34 ;
V_179 -> V_189 . V_174 = V_174 ;
V_179 -> V_189 . time = * V_176 ;
V_179 -> V_189 . V_123 = V_123 ;
V_179 -> V_189 . V_98 = V_98 | V_190 ;
V_56 = - V_191 ;
V_51:
if ( V_177 ) {
F_156 ( & V_177 -> V_171 ) ;
F_157 ( & V_177 -> V_171 ) ;
}
return V_56 ;
}
static long V_188 ( struct V_178 * V_179 )
{
T_3 T_4 * V_34 = V_179 -> V_189 . V_34 ;
T_7 V_192 , * V_193 = NULL ;
if ( V_179 -> V_189 . V_98 & V_190 ) {
V_192 = V_179 -> V_189 . time ;
V_193 = & V_192 ;
}
V_179 -> V_187 = V_194 ;
return ( long ) F_151 ( V_34 , V_179 -> V_189 . V_98 ,
V_179 -> V_189 . V_174 , V_193 , V_179 -> V_189 . V_123 ) ;
}
static int F_158 ( T_3 T_4 * V_34 , unsigned int V_98 ,
T_7 * time , int V_195 )
{
struct V_168 V_169 , * V_177 = NULL ;
struct V_66 * V_67 = NULL ;
struct V_196 V_115 ;
struct V_17 * V_18 ;
struct V_59 V_110 = V_180 ;
int V_197 , V_56 ;
if ( ! F_25 ( V_158 ) )
return - V_141 ;
if ( F_60 () )
return - V_12 ;
if ( time ) {
V_177 = & V_169 ;
F_152 ( & V_177 -> V_171 , V_182 ,
V_172 ) ;
F_153 ( V_177 , V_38 ) ;
F_159 ( & V_177 -> V_171 , * time ) ;
}
V_146:
V_56 = F_32 ( V_34 , V_98 & V_124 , & V_110 . V_14 , V_134 ) ;
if ( F_33 ( V_56 != 0 ) )
goto V_51;
V_148:
V_18 = F_132 ( & V_110 ) ;
V_56 = F_95 ( V_34 , V_18 , & V_110 . V_14 , & V_110 . V_67 , V_38 , 0 ) ;
if ( F_33 ( V_56 ) ) {
switch ( V_56 ) {
case 1 :
V_56 = 0 ;
goto V_198;
case - V_47 :
goto V_199;
case - V_96 :
F_133 ( V_18 ) ;
F_47 ( & V_110 . V_14 ) ;
F_130 () ;
goto V_146;
default:
goto V_198;
}
}
F_66 ( ! V_110 . V_67 ) ;
F_134 ( & V_110 , V_18 ) ;
if ( V_195 ) {
V_56 = F_160 ( & V_110 . V_67 -> V_75 ) ;
V_56 = V_56 ? 0 : - V_175 ;
goto V_200;
}
F_161 ( & V_115 ) ;
F_70 ( & V_110 . V_67 -> V_75 . V_76 ) ;
F_85 ( V_110 . V_111 ) ;
V_56 = F_162 ( & V_110 . V_67 -> V_75 , & V_115 , V_38 ) ;
F_75 ( & V_110 . V_67 -> V_75 . V_76 ) ;
if ( V_56 ) {
if ( V_56 == 1 )
V_56 = 0 ;
F_84 ( V_110 . V_111 ) ;
goto V_200;
}
if ( F_33 ( V_177 ) )
F_147 ( & V_177 -> V_171 , V_172 ) ;
V_56 = F_163 ( & V_110 . V_67 -> V_75 , V_177 , & V_115 ) ;
F_84 ( V_110 . V_111 ) ;
if ( V_56 && ! F_164 ( & V_110 . V_67 -> V_75 , & V_115 ) )
V_56 = 0 ;
V_200:
V_197 = F_142 ( V_34 , & V_110 , ! V_56 ) ;
if ( V_197 )
V_56 = ( V_197 < 0 ) ? V_197 : 0 ;
if ( V_56 && ( F_143 ( & V_110 . V_67 -> V_75 ) == V_38 ) ) {
V_67 = V_110 . V_67 ;
F_67 ( V_67 ) ;
}
F_140 ( & V_110 ) ;
if ( V_67 ) {
F_86 ( & V_67 -> V_75 ) ;
F_68 ( V_67 ) ;
}
goto V_125;
V_198:
F_133 ( V_18 ) ;
V_125:
F_47 ( & V_110 . V_14 ) ;
V_51:
if ( V_177 ) {
F_156 ( & V_177 -> V_171 ) ;
F_157 ( & V_177 -> V_171 ) ;
}
return V_56 != - V_201 ? V_56 : - V_202 ;
V_199:
F_133 ( V_18 ) ;
V_56 = F_48 ( V_34 ) ;
if ( V_56 )
goto V_125;
if ( ! ( V_98 & V_124 ) )
goto V_148;
F_47 ( & V_110 . V_14 ) ;
goto V_146;
}
static int F_165 ( T_3 T_4 * V_34 , unsigned int V_98 )
{
T_3 V_104 ( V_61 ) , V_62 , V_107 = F_88 ( V_38 ) ;
union V_13 V_14 = V_73 ;
struct V_17 * V_18 ;
struct V_59 * V_103 ;
int V_56 ;
if ( ! F_25 ( V_158 ) )
return - V_141 ;
V_146:
if ( F_129 ( V_62 , V_34 ) )
return - V_47 ;
if ( ( V_62 & V_88 ) != V_107 )
return - V_100 ;
V_56 = F_32 ( V_34 , V_98 & V_124 , & V_14 , V_134 ) ;
if ( V_56 )
return V_56 ;
V_18 = F_21 ( & V_14 ) ;
F_84 ( & V_18 -> V_86 ) ;
V_103 = F_52 ( V_18 , & V_14 ) ;
if ( V_103 ) {
struct V_66 * V_67 = V_103 -> V_67 ;
V_56 = - V_46 ;
if ( ! V_67 )
goto V_118;
if ( V_67 -> V_71 != V_38 )
goto V_118;
F_67 ( V_67 ) ;
F_70 ( & V_67 -> V_75 . V_76 ) ;
F_85 ( & V_18 -> V_86 ) ;
V_56 = F_106 ( V_34 , V_62 , V_67 ) ;
F_68 ( V_67 ) ;
if ( ! V_56 )
goto V_203;
if ( V_56 == - V_47 )
goto V_204;
if ( V_56 == - V_96 ) {
F_47 ( & V_14 ) ;
goto V_146;
}
goto V_203;
}
if ( F_54 ( & V_61 , V_34 , V_62 , 0 ) ) {
F_85 ( & V_18 -> V_86 ) ;
goto V_204;
}
V_56 = ( V_61 == V_62 ) ? 0 : - V_96 ;
V_118:
F_85 ( & V_18 -> V_86 ) ;
V_203:
F_47 ( & V_14 ) ;
return V_56 ;
V_204:
F_47 ( & V_14 ) ;
V_56 = F_48 ( V_34 ) ;
if ( ! V_56 )
goto V_146;
return V_56 ;
}
static inline
int F_166 ( struct V_17 * V_18 ,
struct V_59 * V_110 , union V_13 * V_28 ,
struct V_168 * V_169 )
{
int V_56 = 0 ;
if ( ! F_23 ( & V_110 -> V_14 , V_28 ) ) {
F_66 ( V_110 -> V_111 && ( & V_18 -> V_86 != V_110 -> V_111 ) ) ;
F_101 ( & V_110 -> V_70 , & V_18 -> V_112 ) ;
F_17 ( V_18 ) ;
V_56 = - V_175 ;
if ( V_169 && ! V_169 -> V_105 )
V_56 = - V_185 ;
else if ( F_155 ( V_38 ) )
V_56 = - V_202 ;
}
return V_56 ;
}
static int F_167 ( T_3 T_4 * V_34 , unsigned int V_98 ,
T_3 V_174 , T_7 * V_176 , T_3 V_123 ,
T_3 T_4 * V_143 )
{
struct V_168 V_169 , * V_177 = NULL ;
struct V_66 * V_67 = NULL ;
struct V_196 V_115 ;
struct V_17 * V_18 ;
union V_13 V_28 = V_73 ;
struct V_59 V_110 = V_180 ;
int V_197 , V_56 ;
if ( ! F_25 ( V_158 ) )
return - V_141 ;
if ( V_34 == V_143 )
return - V_46 ;
if ( ! V_123 )
return - V_46 ;
if ( V_176 ) {
V_177 = & V_169 ;
F_152 ( & V_177 -> V_171 , ( V_98 & V_181 ) ?
V_182 : V_183 ,
V_172 ) ;
F_153 ( V_177 , V_38 ) ;
F_154 ( & V_177 -> V_171 , * V_176 ,
V_38 -> V_184 ) ;
}
F_161 ( & V_115 ) ;
V_56 = F_32 ( V_143 , V_98 & V_124 , & V_28 , V_134 ) ;
if ( F_33 ( V_56 != 0 ) )
goto V_51;
V_110 . V_123 = V_123 ;
V_110 . V_115 = & V_115 ;
V_110 . V_152 = & V_28 ;
V_56 = F_150 ( V_34 , V_174 , V_98 , & V_110 , & V_18 ) ;
if ( V_56 )
goto V_205;
if ( F_23 ( & V_110 . V_14 , & V_28 ) ) {
F_133 ( V_18 ) ;
V_56 = - V_46 ;
goto V_149;
}
F_145 ( V_18 , & V_110 , V_177 ) ;
F_84 ( & V_18 -> V_86 ) ;
V_56 = F_166 ( V_18 , & V_110 , & V_28 , V_177 ) ;
F_85 ( & V_18 -> V_86 ) ;
if ( V_56 )
goto V_149;
if ( ! V_110 . V_115 ) {
if ( V_110 . V_67 && ( V_110 . V_67 -> V_71 != V_38 ) ) {
F_84 ( V_110 . V_111 ) ;
V_56 = F_141 ( V_143 , & V_110 , V_38 ) ;
if ( V_56 && F_143 ( & V_110 . V_67 -> V_75 ) == V_38 ) {
V_67 = V_110 . V_67 ;
F_67 ( V_67 ) ;
}
F_68 ( V_110 . V_67 ) ;
F_85 ( V_110 . V_111 ) ;
}
} else {
struct V_206 * V_75 ;
F_66 ( ! V_110 . V_67 ) ;
V_75 = & V_110 . V_67 -> V_75 ;
V_56 = F_163 ( V_75 , V_177 , & V_115 ) ;
F_84 ( V_110 . V_111 ) ;
if ( V_56 && ! F_164 ( V_75 , & V_115 ) )
V_56 = 0 ;
F_168 ( & V_115 ) ;
V_197 = F_142 ( V_143 , & V_110 , ! V_56 ) ;
if ( V_197 )
V_56 = ( V_197 < 0 ) ? V_197 : 0 ;
if ( V_56 && F_143 ( & V_110 . V_67 -> V_75 ) == V_38 ) {
V_67 = V_110 . V_67 ;
F_67 ( V_67 ) ;
}
F_140 ( & V_110 ) ;
}
if ( V_67 ) {
F_86 ( & V_67 -> V_75 ) ;
F_68 ( V_67 ) ;
}
if ( V_56 == - V_201 ) {
V_56 = - V_175 ;
}
V_149:
F_47 ( & V_110 . V_14 ) ;
V_205:
F_47 ( & V_28 ) ;
V_51:
if ( V_177 ) {
F_156 ( & V_177 -> V_171 ) ;
F_157 ( & V_177 -> V_171 ) ;
}
return V_56 ;
}
int F_169 ( T_3 T_4 * V_34 , struct V_74 * V_80 , int V_207 )
{
T_3 V_62 , V_104 ( V_208 ) , V_209 ;
V_146:
if ( F_129 ( V_62 , V_34 ) )
return - 1 ;
if ( ( V_62 & V_88 ) == F_88 ( V_80 ) ) {
V_209 = ( V_62 & V_109 ) | V_92 ;
if ( F_54 ( & V_208 , V_34 , V_62 , V_209 ) ) {
if ( F_48 ( V_34 ) )
return - 1 ;
goto V_146;
}
if ( V_208 != V_62 )
goto V_146;
if ( ! V_207 && ( V_62 & V_109 ) )
F_114 ( V_34 , 1 , 1 , V_210 ) ;
}
return 0 ;
}
static inline int F_170 ( struct V_211 T_4 * * V_212 ,
struct V_211 T_4 * T_4 * V_83 ,
unsigned int * V_207 )
{
unsigned long V_213 ;
if ( F_129 ( V_213 , ( unsigned long T_4 * ) V_83 ) )
return - V_47 ;
* V_212 = ( void T_4 * ) ( V_213 & ~ 1UL ) ;
* V_207 = V_213 & 1 ;
return 0 ;
}
void F_171 ( struct V_74 * V_80 )
{
struct V_214 T_4 * V_83 = V_80 -> V_211 ;
struct V_211 T_4 * V_212 , * V_215 , * V_216 ;
unsigned int V_217 = V_218 , V_207 , V_219 ;
unsigned int V_104 ( V_220 ) ;
unsigned long V_221 ;
int V_222 ;
if ( ! V_85 )
return;
if ( F_170 ( & V_212 , & V_83 -> V_70 . V_82 , & V_207 ) )
return;
if ( F_129 ( V_221 , & V_83 -> V_221 ) )
return;
if ( F_170 ( & V_216 , & V_83 -> V_223 , & V_219 ) )
return;
V_215 = NULL ;
while ( V_212 != & V_83 -> V_70 ) {
V_222 = F_170 ( & V_215 , & V_212 -> V_82 , & V_220 ) ;
if ( V_212 != V_216 )
if ( F_169 ( ( void T_4 * ) V_212 + V_221 ,
V_80 , V_207 ) )
return;
if ( V_222 )
return;
V_212 = V_215 ;
V_207 = V_220 ;
if ( ! -- V_217 )
break;
F_130 () ;
}
if ( V_216 )
F_169 ( ( void T_4 * ) V_216 + V_221 ,
V_80 , V_219 ) ;
}
long F_172 ( T_3 T_4 * V_34 , int V_127 , T_3 V_174 , T_7 * V_169 ,
T_3 T_4 * V_143 , T_3 V_224 , T_3 V_225 )
{
int V_226 = V_127 & V_227 ;
unsigned int V_98 = 0 ;
if ( ! ( V_127 & V_228 ) )
V_98 |= V_124 ;
if ( V_127 & V_229 ) {
V_98 |= V_181 ;
if ( V_226 != V_230 && V_226 != V_231 && \
V_226 != V_232 )
return - V_141 ;
}
switch ( V_226 ) {
case V_233 :
case V_234 :
case V_235 :
case V_232 :
case V_236 :
if ( ! V_85 )
return - V_141 ;
}
switch ( V_226 ) {
case V_230 :
V_225 = V_210 ;
case V_231 :
return F_151 ( V_34 , V_98 , V_174 , V_169 , V_225 ) ;
case V_237 :
V_225 = V_210 ;
case V_238 :
return F_114 ( V_34 , V_98 , V_174 , V_225 ) ;
case V_239 :
return F_128 ( V_34 , V_98 , V_143 , V_174 , V_224 , NULL , 0 ) ;
case V_240 :
return F_128 ( V_34 , V_98 , V_143 , V_174 , V_224 , & V_225 , 0 ) ;
case V_241 :
return F_122 ( V_34 , V_98 , V_143 , V_174 , V_224 , V_225 ) ;
case V_233 :
return F_158 ( V_34 , V_98 , V_169 , 0 ) ;
case V_234 :
return F_165 ( V_34 , V_98 ) ;
case V_235 :
return F_158 ( V_34 , V_98 , NULL , 1 ) ;
case V_232 :
V_225 = V_210 ;
return F_167 ( V_34 , V_98 , V_174 , V_169 , V_225 ,
V_143 ) ;
case V_236 :
return F_128 ( V_34 , V_98 , V_143 , V_174 , V_224 , & V_225 , 1 ) ;
}
return - V_141 ;
}
static void T_1 F_173 ( void )
{
#ifndef F_174
T_3 V_61 ;
if ( F_54 ( & V_61 , NULL , 0 , 0 ) == - V_47 )
V_85 = 1 ;
#endif
}
static int T_1 F_175 ( void )
{
unsigned int V_242 ;
unsigned long V_243 ;
#if V_244
V_26 = 16 ;
#else
V_26 = F_176 ( 256 * F_177 () ) ;
#endif
V_25 = F_178 ( L_7 , sizeof( * V_25 ) ,
V_26 , 0 ,
V_26 < 256 ? V_245 : 0 ,
& V_242 , NULL ,
V_26 , V_26 ) ;
V_26 = 1UL << V_242 ;
F_173 () ;
for ( V_243 = 0 ; V_243 < V_26 ; V_243 ++ ) {
F_64 ( & V_25 [ V_243 ] . V_19 , 0 ) ;
F_179 ( & V_25 [ V_243 ] . V_112 ) ;
F_180 ( & V_25 [ V_243 ] . V_86 ) ;
}
return 0 ;
}
