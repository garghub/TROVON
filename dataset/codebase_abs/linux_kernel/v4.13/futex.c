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
F_70 ( & V_67 -> V_71 -> V_74 ) ;
F_71 ( & V_67 -> V_70 ) ;
F_72 ( & V_67 -> V_71 -> V_74 ) ;
F_73 ( & V_67 -> V_75 , V_67 -> V_71 ) ;
}
if ( V_38 -> V_68 )
F_74 ( V_67 ) ;
else {
V_67 -> V_71 = NULL ;
F_64 ( & V_67 -> V_72 , 1 ) ;
V_38 -> V_68 = V_67 ;
}
}
static struct V_76 * F_75 ( T_5 V_77 )
{
struct V_76 * V_78 ;
F_43 () ;
V_78 = F_76 ( V_77 ) ;
if ( V_78 )
F_77 ( V_78 ) ;
F_44 () ;
return V_78 ;
}
void F_78 ( struct V_76 * V_79 )
{
struct V_80 * V_81 , * V_82 = & V_79 -> V_83 ;
struct V_66 * V_67 ;
struct V_17 * V_18 ;
union V_13 V_14 = V_73 ;
if ( ! V_84 )
return;
F_70 ( & V_79 -> V_74 ) ;
while ( ! F_79 ( V_82 ) ) {
V_81 = V_82 -> V_81 ;
V_67 = F_80 ( V_81 , struct V_66 , V_70 ) ;
V_14 = V_67 -> V_14 ;
V_18 = F_21 ( & V_14 ) ;
F_72 ( & V_79 -> V_74 ) ;
F_81 ( & V_18 -> V_85 ) ;
F_70 ( & V_79 -> V_74 ) ;
if ( V_82 -> V_81 != V_81 ) {
F_82 ( & V_18 -> V_85 ) ;
continue;
}
F_66 ( V_67 -> V_71 != V_79 ) ;
F_66 ( F_79 ( & V_67 -> V_70 ) ) ;
F_71 ( & V_67 -> V_70 ) ;
V_67 -> V_71 = NULL ;
F_72 ( & V_79 -> V_74 ) ;
F_67 ( V_67 ) ;
F_82 ( & V_18 -> V_85 ) ;
F_83 ( & V_67 -> V_75 ) ;
F_68 ( V_67 ) ;
F_70 ( & V_79 -> V_74 ) ;
}
F_72 ( & V_79 -> V_74 ) ;
}
static int F_84 ( T_3 T_4 * V_34 , T_3 V_62 ,
struct V_66 * V_67 ,
struct V_66 * * V_86 )
{
T_5 V_77 = V_62 & V_87 ;
T_3 V_88 ;
int V_56 ;
if ( F_33 ( ! V_67 ) )
return - V_46 ;
F_66 ( ! F_20 ( & V_67 -> V_72 ) ) ;
F_70 ( & V_67 -> V_75 . V_89 ) ;
if ( F_58 ( & V_88 , V_34 ) )
goto V_90;
if ( V_62 != V_88 )
goto V_91;
if ( V_62 & V_92 ) {
if ( ! V_67 -> V_71 ) {
if ( V_77 )
goto V_93;
goto V_94;
}
if ( ! V_77 )
goto V_94;
} else {
if ( ! V_67 -> V_71 )
goto V_93;
}
if ( V_77 != F_85 ( V_67 -> V_71 ) )
goto V_93;
V_94:
F_67 ( V_67 ) ;
F_72 ( & V_67 -> V_75 . V_89 ) ;
* V_86 = V_67 ;
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
F_72 ( & V_67 -> V_75 . V_89 ) ;
return V_56 ;
}
static int F_86 ( T_3 V_62 , union V_13 * V_14 ,
struct V_66 * * V_86 )
{
T_5 V_77 = V_62 & V_87 ;
struct V_66 * V_67 ;
struct V_76 * V_78 ;
if ( ! V_77 )
return - V_97 ;
V_78 = F_75 ( V_77 ) ;
if ( ! V_78 )
return - V_97 ;
if ( F_33 ( V_78 -> V_98 & V_99 ) ) {
F_87 ( V_78 ) ;
return - V_100 ;
}
F_70 ( & V_78 -> V_74 ) ;
if ( F_33 ( V_78 -> V_98 & V_101 ) ) {
int V_56 = ( V_78 -> V_98 & V_102 ) ? - V_97 : - V_96 ;
F_72 ( & V_78 -> V_74 ) ;
F_87 ( V_78 ) ;
return V_56 ;
}
V_67 = F_65 () ;
F_88 ( & V_67 -> V_75 , V_78 ) ;
V_67 -> V_14 = * V_14 ;
F_66 ( ! F_79 ( & V_67 -> V_70 ) ) ;
F_89 ( & V_67 -> V_70 , & V_78 -> V_83 ) ;
V_67 -> V_71 = V_78 ;
F_72 ( & V_78 -> V_74 ) ;
F_87 ( V_78 ) ;
* V_86 = V_67 ;
return 0 ;
}
static int F_90 ( T_3 T_4 * V_34 , T_3 V_62 ,
struct V_17 * V_18 ,
union V_13 * V_14 , struct V_66 * * V_86 )
{
struct V_59 * V_103 = F_52 ( V_18 , V_14 ) ;
if ( V_103 )
return F_84 ( V_34 , V_62 , V_103 -> V_67 , V_86 ) ;
return F_86 ( V_62 , V_14 , V_86 ) ;
}
static int F_91 ( T_3 T_4 * V_34 , T_3 V_62 , T_3 V_63 )
{
T_3 V_104 ( V_61 ) ;
if ( F_33 ( F_3 ( true ) ) )
return - V_47 ;
if ( F_33 ( F_54 ( & V_61 , V_34 , V_62 , V_63 ) ) )
return - V_47 ;
return V_61 != V_62 ? - V_96 : 0 ;
}
static int F_92 ( T_3 T_4 * V_34 , struct V_17 * V_18 ,
union V_13 * V_14 ,
struct V_66 * * V_86 ,
struct V_76 * V_105 , int V_106 )
{
T_3 V_62 , V_63 , V_107 = F_85 ( V_105 ) ;
struct V_59 * V_103 ;
int V_56 ;
if ( F_58 ( & V_62 , V_34 ) )
return - V_47 ;
if ( F_33 ( F_3 ( true ) ) )
return - V_47 ;
if ( ( F_33 ( ( V_62 & V_87 ) == V_107 ) ) )
return - V_108 ;
if ( ( F_33 ( F_3 ( true ) ) ) )
return - V_108 ;
V_103 = F_52 ( V_18 , V_14 ) ;
if ( V_103 )
return F_84 ( V_34 , V_62 , V_103 -> V_67 , V_86 ) ;
if ( ! ( V_62 & V_87 ) ) {
V_63 = V_62 & V_92 ;
V_63 |= V_107 ;
if ( V_106 )
V_63 |= V_109 ;
V_56 = F_91 ( V_34 , V_62 , V_63 ) ;
return V_56 < 0 ? V_56 : 1 ;
}
V_63 = V_62 | V_109 ;
V_56 = F_91 ( V_34 , V_62 , V_63 ) ;
if ( V_56 )
return V_56 ;
return F_86 ( V_62 , V_14 , V_86 ) ;
}
static void F_93 ( struct V_59 * V_110 )
{
struct V_17 * V_18 ;
if ( F_94 ( ! V_110 -> V_111 || ! F_95 ( V_110 -> V_111 ) )
|| F_66 ( F_96 ( & V_110 -> V_70 ) ) )
return;
V_18 = F_97 ( V_110 -> V_111 , struct V_17 , V_85 ) ;
F_98 ( & V_110 -> V_70 , & V_18 -> V_112 ) ;
F_17 ( V_18 ) ;
}
static void F_99 ( struct V_113 * V_114 , struct V_59 * V_110 )
{
struct V_76 * V_78 = V_110 -> V_105 ;
if ( F_100 ( V_110 -> V_67 || V_110 -> V_115 , L_3 ) )
return;
F_101 ( V_114 , V_78 ) ;
F_93 ( V_110 ) ;
F_102 ( & V_110 -> V_111 , NULL ) ;
}
static int F_103 ( T_3 T_4 * V_34 , T_3 V_62 , struct V_66 * V_67 )
{
T_3 V_104 ( V_61 ) , V_63 ;
struct V_76 * V_116 ;
bool V_117 = false ;
F_104 ( V_114 ) ;
int V_56 = 0 ;
V_116 = F_105 ( & V_67 -> V_75 ) ;
if ( F_29 ( ! V_116 ) ) {
V_56 = - V_96 ;
goto V_118;
}
V_63 = V_109 | F_85 ( V_116 ) ;
if ( F_33 ( F_3 ( true ) ) )
V_56 = - V_47 ;
if ( F_54 ( & V_61 , V_34 , V_62 , V_63 ) ) {
V_56 = - V_47 ;
} else if ( V_61 != V_62 ) {
if ( ( V_87 & V_61 ) == V_62 )
V_56 = - V_96 ;
else
V_56 = - V_46 ;
}
if ( V_56 )
goto V_118;
F_106 ( & V_67 -> V_71 -> V_74 ) ;
F_66 ( F_79 ( & V_67 -> V_70 ) ) ;
F_71 ( & V_67 -> V_70 ) ;
F_107 ( & V_67 -> V_71 -> V_74 ) ;
F_106 ( & V_116 -> V_74 ) ;
F_66 ( ! F_79 ( & V_67 -> V_70 ) ) ;
F_89 ( & V_67 -> V_70 , & V_116 -> V_83 ) ;
V_67 -> V_71 = V_116 ;
F_107 ( & V_116 -> V_74 ) ;
V_117 = F_108 ( & V_67 -> V_75 , & V_114 ) ;
V_118:
F_72 ( & V_67 -> V_75 . V_89 ) ;
if ( V_117 )
F_109 ( & V_114 ) ;
return V_56 ;
}
static inline void
F_110 ( struct V_17 * V_119 , struct V_17 * V_120 )
{
if ( V_119 <= V_120 ) {
F_81 ( & V_119 -> V_85 ) ;
if ( V_119 < V_120 )
F_111 ( & V_120 -> V_85 , V_121 ) ;
} else {
F_81 ( & V_120 -> V_85 ) ;
F_111 ( & V_119 -> V_85 , V_121 ) ;
}
}
static inline void
F_112 ( struct V_17 * V_119 , struct V_17 * V_120 )
{
F_82 ( & V_119 -> V_85 ) ;
if ( V_119 != V_120 )
F_82 ( & V_120 -> V_85 ) ;
}
static int
F_113 ( T_3 T_4 * V_34 , unsigned int V_98 , int V_122 , T_3 V_123 )
{
struct V_17 * V_18 ;
struct V_59 * V_60 , * V_81 ;
union V_13 V_14 = V_73 ;
int V_56 ;
F_104 ( V_114 ) ;
if ( ! V_123 )
return - V_46 ;
V_56 = F_32 ( V_34 , V_98 & V_124 , & V_14 , V_49 ) ;
if ( F_33 ( V_56 != 0 ) )
goto V_51;
V_18 = F_21 ( & V_14 ) ;
if ( ! F_19 ( V_18 ) )
goto V_125;
F_81 ( & V_18 -> V_85 ) ;
F_114 (this, next, &hb->chain, list) {
if ( F_23 ( & V_60 -> V_14 , & V_14 ) ) {
if ( V_60 -> V_67 || V_60 -> V_115 ) {
V_56 = - V_46 ;
break;
}
if ( ! ( V_60 -> V_123 & V_123 ) )
continue;
F_99 ( & V_114 , V_60 ) ;
if ( ++ V_56 >= V_122 )
break;
}
}
F_82 ( & V_18 -> V_85 ) ;
F_115 ( & V_114 ) ;
V_125:
F_47 ( & V_14 ) ;
V_51:
return V_56 ;
}
static int
F_116 ( T_3 T_4 * V_126 , unsigned int V_98 , T_3 T_4 * V_127 ,
int V_122 , int V_128 , int V_129 )
{
union V_13 V_27 = V_73 , V_28 = V_73 ;
struct V_17 * V_119 , * V_120 ;
struct V_59 * V_60 , * V_81 ;
int V_56 , V_130 ;
F_104 ( V_114 ) ;
V_131:
V_56 = F_32 ( V_126 , V_98 & V_124 , & V_27 , V_49 ) ;
if ( F_33 ( V_56 != 0 ) )
goto V_51;
V_56 = F_32 ( V_127 , V_98 & V_124 , & V_28 , V_132 ) ;
if ( F_33 ( V_56 != 0 ) )
goto V_133;
V_119 = F_21 ( & V_27 ) ;
V_120 = F_21 ( & V_28 ) ;
V_134:
F_110 ( V_119 , V_120 ) ;
V_130 = F_117 ( V_129 , V_127 ) ;
if ( F_33 ( V_130 < 0 ) ) {
F_112 ( V_119 , V_120 ) ;
#ifndef V_29
V_56 = V_130 ;
goto V_135;
#endif
if ( F_33 ( V_130 != - V_47 ) ) {
V_56 = V_130 ;
goto V_135;
}
V_56 = F_48 ( V_127 ) ;
if ( V_56 )
goto V_135;
if ( ! ( V_98 & V_124 ) )
goto V_134;
F_47 ( & V_28 ) ;
F_47 ( & V_27 ) ;
goto V_131;
}
F_114 (this, next, &hb1->chain, list) {
if ( F_23 ( & V_60 -> V_14 , & V_27 ) ) {
if ( V_60 -> V_67 || V_60 -> V_115 ) {
V_56 = - V_46 ;
goto V_118;
}
F_99 ( & V_114 , V_60 ) ;
if ( ++ V_56 >= V_122 )
break;
}
}
if ( V_130 > 0 ) {
V_130 = 0 ;
F_114 (this, next, &hb2->chain, list) {
if ( F_23 ( & V_60 -> V_14 , & V_28 ) ) {
if ( V_60 -> V_67 || V_60 -> V_115 ) {
V_56 = - V_46 ;
goto V_118;
}
F_99 ( & V_114 , V_60 ) ;
if ( ++ V_130 >= V_128 )
break;
}
}
V_56 += V_130 ;
}
V_118:
F_112 ( V_119 , V_120 ) ;
F_115 ( & V_114 ) ;
V_135:
F_47 ( & V_28 ) ;
V_133:
F_47 ( & V_27 ) ;
V_51:
return V_56 ;
}
static inline
void F_118 ( struct V_59 * V_110 , struct V_17 * V_119 ,
struct V_17 * V_120 , union V_13 * V_28 )
{
if ( F_61 ( & V_119 -> V_112 != & V_120 -> V_112 ) ) {
F_98 ( & V_110 -> V_70 , & V_119 -> V_112 ) ;
F_17 ( V_119 ) ;
F_14 ( V_120 ) ;
F_119 ( & V_110 -> V_70 , & V_120 -> V_112 ) ;
V_110 -> V_111 = & V_120 -> V_85 ;
}
F_24 ( V_28 ) ;
V_110 -> V_14 = * V_28 ;
}
static inline
void F_120 ( struct V_59 * V_110 , union V_13 * V_14 ,
struct V_17 * V_18 )
{
F_24 ( V_14 ) ;
V_110 -> V_14 = * V_14 ;
F_93 ( V_110 ) ;
F_66 ( ! V_110 -> V_115 ) ;
V_110 -> V_115 = NULL ;
V_110 -> V_111 = & V_18 -> V_85 ;
F_121 ( V_110 -> V_105 , V_136 ) ;
}
static int F_122 ( T_3 T_4 * V_137 ,
struct V_17 * V_119 ,
struct V_17 * V_120 ,
union V_13 * V_27 , union V_13 * V_28 ,
struct V_66 * * V_86 , int V_106 )
{
struct V_59 * V_103 = NULL ;
T_3 V_61 ;
int V_56 , V_107 ;
if ( F_58 ( & V_61 , V_137 ) )
return - V_47 ;
if ( F_33 ( F_3 ( true ) ) )
return - V_47 ;
V_103 = F_52 ( V_119 , V_27 ) ;
if ( ! V_103 )
return 0 ;
if ( ! F_23 ( V_103 -> V_138 , V_28 ) )
return - V_46 ;
V_107 = F_85 ( V_103 -> V_105 ) ;
V_56 = F_92 ( V_137 , V_120 , V_28 , V_86 , V_103 -> V_105 ,
V_106 ) ;
if ( V_56 == 1 ) {
F_120 ( V_103 , V_28 , V_120 ) ;
return V_107 ;
}
return V_56 ;
}
static int F_123 ( T_3 T_4 * V_126 , unsigned int V_98 ,
T_3 T_4 * V_127 , int V_122 , int V_139 ,
T_3 * V_140 , int V_141 )
{
union V_13 V_27 = V_73 , V_28 = V_73 ;
int V_142 = 0 , V_143 = 0 , V_56 ;
struct V_66 * V_67 = NULL ;
struct V_17 * V_119 , * V_120 ;
struct V_59 * V_60 , * V_81 ;
F_104 ( V_114 ) ;
if ( V_141 ) {
if ( V_126 == V_127 )
return - V_46 ;
if ( F_60 () )
return - V_12 ;
if ( V_122 != 1 )
return - V_46 ;
}
V_131:
V_56 = F_32 ( V_126 , V_98 & V_124 , & V_27 , V_49 ) ;
if ( F_33 ( V_56 != 0 ) )
goto V_51;
V_56 = F_32 ( V_127 , V_98 & V_124 , & V_28 ,
V_141 ? V_132 : V_49 ) ;
if ( F_33 ( V_56 != 0 ) )
goto V_133;
if ( V_141 && F_23 ( & V_27 , & V_28 ) ) {
V_56 = - V_46 ;
goto V_135;
}
V_119 = F_21 ( & V_27 ) ;
V_120 = F_21 ( & V_28 ) ;
V_134:
F_14 ( V_120 ) ;
F_110 ( V_119 , V_120 ) ;
if ( F_61 ( V_140 != NULL ) ) {
T_3 V_61 ;
V_56 = F_58 ( & V_61 , V_126 ) ;
if ( F_33 ( V_56 ) ) {
F_112 ( V_119 , V_120 ) ;
F_17 ( V_120 ) ;
V_56 = F_124 ( V_61 , V_126 ) ;
if ( V_56 )
goto V_135;
if ( ! ( V_98 & V_124 ) )
goto V_134;
F_47 ( & V_28 ) ;
F_47 ( & V_27 ) ;
goto V_131;
}
if ( V_61 != * V_140 ) {
V_56 = - V_96 ;
goto V_118;
}
}
if ( V_141 && ( V_143 - V_122 < V_139 ) ) {
V_56 = F_122 ( V_127 , V_119 , V_120 , & V_27 ,
& V_28 , & V_67 , V_139 ) ;
if ( V_56 > 0 ) {
F_66 ( V_67 ) ;
V_142 ++ ;
V_143 ++ ;
V_56 = F_90 ( V_127 , V_56 , V_120 , & V_28 , & V_67 ) ;
}
switch ( V_56 ) {
case 0 :
break;
case - V_47 :
F_112 ( V_119 , V_120 ) ;
F_17 ( V_120 ) ;
F_47 ( & V_28 ) ;
F_47 ( & V_27 ) ;
V_56 = F_48 ( V_127 ) ;
if ( ! V_56 )
goto V_131;
goto V_51;
case - V_96 :
F_112 ( V_119 , V_120 ) ;
F_17 ( V_120 ) ;
F_47 ( & V_28 ) ;
F_47 ( & V_27 ) ;
F_125 () ;
goto V_131;
default:
goto V_118;
}
}
F_114 (this, next, &hb1->chain, list) {
if ( V_143 - V_122 >= V_139 )
break;
if ( ! F_23 ( & V_60 -> V_14 , & V_27 ) )
continue;
if ( ( V_141 && ! V_60 -> V_115 ) ||
( ! V_141 && V_60 -> V_115 ) ||
V_60 -> V_67 ) {
V_56 = - V_46 ;
break;
}
if ( ++ V_143 <= V_122 && ! V_141 ) {
F_99 ( & V_114 , V_60 ) ;
continue;
}
if ( V_141 && ! F_23 ( V_60 -> V_138 , & V_28 ) ) {
V_56 = - V_46 ;
break;
}
if ( V_141 ) {
F_67 ( V_67 ) ;
V_60 -> V_67 = V_67 ;
V_56 = F_126 ( & V_67 -> V_75 ,
V_60 -> V_115 ,
V_60 -> V_105 ) ;
if ( V_56 == 1 ) {
F_120 ( V_60 , & V_28 , V_120 ) ;
V_142 ++ ;
continue;
} else if ( V_56 ) {
V_60 -> V_67 = NULL ;
F_68 ( V_67 ) ;
break;
}
}
F_118 ( V_60 , V_119 , V_120 , & V_28 ) ;
V_142 ++ ;
}
F_68 ( V_67 ) ;
V_118:
F_112 ( V_119 , V_120 ) ;
F_115 ( & V_114 ) ;
F_17 ( V_120 ) ;
while ( -- V_142 >= 0 )
F_28 ( & V_27 ) ;
V_135:
F_47 ( & V_28 ) ;
V_133:
F_47 ( & V_27 ) ;
V_51:
return V_56 ? V_56 : V_143 ;
}
static inline struct V_17 * F_127 ( struct V_59 * V_110 )
__acquires( &hb->lock
static inline void
F_128 ( struct V_17 * V_18 )
__releases( &hb->lock
static inline void F_129 ( struct V_59 * V_110 , struct V_17 * V_18 )
{
int V_144 ;
V_144 = F_130 ( V_38 -> V_145 , V_146 ) ;
F_131 ( & V_110 -> V_70 , V_144 ) ;
F_119 ( & V_110 -> V_70 , & V_18 -> V_112 ) ;
V_110 -> V_105 = V_38 ;
}
static inline void F_132 ( struct V_59 * V_110 , struct V_17 * V_18 )
__releases( &hb->lock
static int F_133 ( struct V_59 * V_110 )
{
T_6 * V_111 ;
int V_56 = 0 ;
V_131:
V_111 = F_37 ( V_110 -> V_111 ) ;
if ( V_111 != NULL ) {
F_81 ( V_111 ) ;
if ( F_33 ( V_111 != V_110 -> V_111 ) ) {
F_82 ( V_111 ) ;
goto V_131;
}
F_93 ( V_110 ) ;
F_134 ( V_110 -> V_67 ) ;
F_82 ( V_111 ) ;
V_56 = 1 ;
}
F_28 ( & V_110 -> V_14 ) ;
return V_56 ;
}
static void F_135 ( struct V_59 * V_110 )
__releases( V_110 -> V_111 )
{
F_93 ( V_110 ) ;
F_134 ( ! V_110 -> V_67 ) ;
F_68 ( V_110 -> V_67 ) ;
V_110 -> V_67 = NULL ;
F_82 ( V_110 -> V_111 ) ;
}
static int F_136 ( T_3 T_4 * V_34 , struct V_59 * V_110 ,
struct V_76 * V_147 )
{
T_3 V_148 = F_85 ( V_147 ) | V_109 ;
struct V_66 * V_67 = V_110 -> V_67 ;
T_3 V_62 , V_104 ( V_61 ) , V_63 ;
struct V_76 * V_149 ;
int V_56 ;
F_70 ( & V_67 -> V_75 . V_89 ) ;
V_149 = V_67 -> V_71 ;
if ( ! V_67 -> V_71 )
V_148 |= V_92 ;
V_131:
if ( F_58 ( & V_62 , V_34 ) )
goto V_150;
for (; ; ) {
V_63 = ( V_62 & V_92 ) | V_148 ;
if ( F_54 ( & V_61 , V_34 , V_62 , V_63 ) )
goto V_150;
if ( V_61 == V_62 )
break;
V_62 = V_61 ;
}
if ( V_67 -> V_71 != NULL ) {
F_106 ( & V_67 -> V_71 -> V_74 ) ;
F_66 ( F_79 ( & V_67 -> V_70 ) ) ;
F_71 ( & V_67 -> V_70 ) ;
F_107 ( & V_67 -> V_71 -> V_74 ) ;
}
V_67 -> V_71 = V_147 ;
F_106 ( & V_147 -> V_74 ) ;
F_66 ( ! F_79 ( & V_67 -> V_70 ) ) ;
F_89 ( & V_67 -> V_70 , & V_147 -> V_83 ) ;
F_107 ( & V_147 -> V_74 ) ;
F_72 ( & V_67 -> V_75 . V_89 ) ;
return 0 ;
V_150:
F_72 ( & V_67 -> V_75 . V_89 ) ;
F_82 ( V_110 -> V_111 ) ;
V_56 = F_48 ( V_34 ) ;
F_81 ( V_110 -> V_111 ) ;
F_70 ( & V_67 -> V_75 . V_89 ) ;
if ( V_67 -> V_71 != V_149 ) {
V_56 = 0 ;
goto V_118;
}
if ( V_56 )
goto V_118;
goto V_131;
V_118:
F_72 ( & V_67 -> V_75 . V_89 ) ;
return V_56 ;
}
static int F_137 ( T_3 T_4 * V_34 , struct V_59 * V_110 , int V_151 )
{
int V_56 = 0 ;
if ( V_151 ) {
if ( V_110 -> V_67 -> V_71 != V_38 )
V_56 = F_136 ( V_34 , V_110 , V_38 ) ;
goto V_51;
}
if ( F_138 ( & V_110 -> V_67 -> V_75 ) == V_38 ) {
F_139 ( V_152 L_4
L_5 , V_56 ,
V_110 -> V_67 -> V_75 . V_71 ,
V_110 -> V_67 -> V_71 ) ;
}
V_51:
return V_56 ? V_56 : V_151 ;
}
static void F_140 ( struct V_17 * V_18 , struct V_59 * V_110 ,
struct V_153 * V_154 )
{
F_141 ( V_155 ) ;
F_132 ( V_110 , V_18 ) ;
if ( V_154 )
F_142 ( & V_154 -> V_156 , V_157 ) ;
if ( F_61 ( ! F_96 ( & V_110 -> V_70 ) ) ) {
if ( ! V_154 || V_154 -> V_105 )
F_143 () ;
}
F_144 ( V_158 ) ;
}
static int F_145 ( T_3 T_4 * V_34 , T_3 V_159 , unsigned int V_98 ,
struct V_59 * V_110 , struct V_17 * * V_18 )
{
T_3 V_62 ;
int V_56 ;
V_131:
V_56 = F_32 ( V_34 , V_98 & V_124 , & V_110 -> V_14 , V_49 ) ;
if ( F_33 ( V_56 != 0 ) )
return V_56 ;
V_134:
* V_18 = F_127 ( V_110 ) ;
V_56 = F_58 ( & V_62 , V_34 ) ;
if ( V_56 ) {
F_128 ( * V_18 ) ;
V_56 = F_124 ( V_62 , V_34 ) ;
if ( V_56 )
goto V_51;
if ( ! ( V_98 & V_124 ) )
goto V_134;
F_47 ( & V_110 -> V_14 ) ;
goto V_131;
}
if ( V_62 != V_159 ) {
F_128 ( * V_18 ) ;
V_56 = - V_160 ;
}
V_51:
if ( V_56 )
F_47 ( & V_110 -> V_14 ) ;
return V_56 ;
}
static int F_146 ( T_3 T_4 * V_34 , unsigned int V_98 , T_3 V_159 ,
T_7 * V_161 , T_3 V_123 )
{
struct V_153 V_154 , * V_162 = NULL ;
struct V_163 * V_164 ;
struct V_17 * V_18 ;
struct V_59 V_110 = V_165 ;
int V_56 ;
if ( ! V_123 )
return - V_46 ;
V_110 . V_123 = V_123 ;
if ( V_161 ) {
V_162 = & V_154 ;
F_147 ( & V_162 -> V_156 , ( V_98 & V_166 ) ?
V_167 : V_168 ,
V_157 ) ;
F_148 ( V_162 , V_38 ) ;
F_149 ( & V_162 -> V_156 , * V_161 ,
V_38 -> V_169 ) ;
}
V_131:
V_56 = F_145 ( V_34 , V_159 , V_98 , & V_110 , & V_18 ) ;
if ( V_56 )
goto V_51;
F_140 ( V_18 , & V_110 , V_162 ) ;
V_56 = 0 ;
if ( ! F_133 ( & V_110 ) )
goto V_51;
V_56 = - V_170 ;
if ( V_162 && ! V_162 -> V_105 )
goto V_51;
if ( ! F_150 ( V_38 ) )
goto V_131;
V_56 = - V_171 ;
if ( ! V_161 )
goto V_51;
V_164 = & V_38 -> V_163 ;
V_164 -> V_172 = V_173 ;
V_164 -> V_174 . V_34 = V_34 ;
V_164 -> V_174 . V_159 = V_159 ;
V_164 -> V_174 . time = * V_161 ;
V_164 -> V_174 . V_123 = V_123 ;
V_164 -> V_174 . V_98 = V_98 | V_175 ;
V_56 = - V_176 ;
V_51:
if ( V_162 ) {
F_151 ( & V_162 -> V_156 ) ;
F_152 ( & V_162 -> V_156 ) ;
}
return V_56 ;
}
static long V_173 ( struct V_163 * V_164 )
{
T_3 T_4 * V_34 = V_164 -> V_174 . V_34 ;
T_7 V_177 , * V_178 = NULL ;
if ( V_164 -> V_174 . V_98 & V_175 ) {
V_177 = V_164 -> V_174 . time ;
V_178 = & V_177 ;
}
V_164 -> V_172 = V_179 ;
return ( long ) F_146 ( V_34 , V_164 -> V_174 . V_98 ,
V_164 -> V_174 . V_159 , V_178 , V_164 -> V_174 . V_123 ) ;
}
static int F_153 ( T_3 T_4 * V_34 , unsigned int V_98 ,
T_7 * time , int V_180 )
{
struct V_153 V_154 , * V_162 = NULL ;
struct V_66 * V_67 = NULL ;
struct V_181 V_115 ;
struct V_17 * V_18 ;
struct V_59 V_110 = V_165 ;
int V_182 , V_56 ;
if ( F_60 () )
return - V_12 ;
if ( time ) {
V_162 = & V_154 ;
F_147 ( & V_162 -> V_156 , V_167 ,
V_157 ) ;
F_148 ( V_162 , V_38 ) ;
F_154 ( & V_162 -> V_156 , * time ) ;
}
V_131:
V_56 = F_32 ( V_34 , V_98 & V_124 , & V_110 . V_14 , V_132 ) ;
if ( F_33 ( V_56 != 0 ) )
goto V_51;
V_134:
V_18 = F_127 ( & V_110 ) ;
V_56 = F_92 ( V_34 , V_18 , & V_110 . V_14 , & V_110 . V_67 , V_38 , 0 ) ;
if ( F_33 ( V_56 ) ) {
switch ( V_56 ) {
case 1 :
V_56 = 0 ;
goto V_183;
case - V_47 :
goto V_184;
case - V_96 :
F_128 ( V_18 ) ;
F_47 ( & V_110 . V_14 ) ;
F_125 () ;
goto V_131;
default:
goto V_183;
}
}
F_66 ( ! V_110 . V_67 ) ;
F_129 ( & V_110 , V_18 ) ;
if ( V_180 ) {
V_56 = F_155 ( & V_110 . V_67 -> V_75 ) ;
V_56 = V_56 ? 0 : - V_160 ;
goto V_185;
}
F_156 ( & V_115 ) ;
F_70 ( & V_110 . V_67 -> V_75 . V_89 ) ;
F_82 ( V_110 . V_111 ) ;
V_56 = F_157 ( & V_110 . V_67 -> V_75 , & V_115 , V_38 ) ;
F_72 ( & V_110 . V_67 -> V_75 . V_89 ) ;
if ( V_56 ) {
if ( V_56 == 1 )
V_56 = 0 ;
F_81 ( V_110 . V_111 ) ;
goto V_185;
}
if ( F_33 ( V_162 ) )
F_142 ( & V_162 -> V_156 , V_157 ) ;
V_56 = F_158 ( & V_110 . V_67 -> V_75 , V_162 , & V_115 ) ;
F_81 ( V_110 . V_111 ) ;
if ( V_56 && ! F_159 ( & V_110 . V_67 -> V_75 , & V_115 ) )
V_56 = 0 ;
V_185:
V_182 = F_137 ( V_34 , & V_110 , ! V_56 ) ;
if ( V_182 )
V_56 = ( V_182 < 0 ) ? V_182 : 0 ;
if ( V_56 && ( F_138 ( & V_110 . V_67 -> V_75 ) == V_38 ) ) {
V_67 = V_110 . V_67 ;
F_67 ( V_67 ) ;
}
F_135 ( & V_110 ) ;
if ( V_67 ) {
F_83 ( & V_67 -> V_75 ) ;
F_68 ( V_67 ) ;
}
goto V_125;
V_183:
F_128 ( V_18 ) ;
V_125:
F_47 ( & V_110 . V_14 ) ;
V_51:
if ( V_162 ) {
F_151 ( & V_162 -> V_156 ) ;
F_152 ( & V_162 -> V_156 ) ;
}
return V_56 != - V_186 ? V_56 : - V_187 ;
V_184:
F_128 ( V_18 ) ;
V_56 = F_48 ( V_34 ) ;
if ( V_56 )
goto V_125;
if ( ! ( V_98 & V_124 ) )
goto V_134;
F_47 ( & V_110 . V_14 ) ;
goto V_131;
}
static int F_160 ( T_3 T_4 * V_34 , unsigned int V_98 )
{
T_3 V_104 ( V_61 ) , V_62 , V_107 = F_85 ( V_38 ) ;
union V_13 V_14 = V_73 ;
struct V_17 * V_18 ;
struct V_59 * V_103 ;
int V_56 ;
V_131:
if ( F_124 ( V_62 , V_34 ) )
return - V_47 ;
if ( ( V_62 & V_87 ) != V_107 )
return - V_100 ;
V_56 = F_32 ( V_34 , V_98 & V_124 , & V_14 , V_132 ) ;
if ( V_56 )
return V_56 ;
V_18 = F_21 ( & V_14 ) ;
F_81 ( & V_18 -> V_85 ) ;
V_103 = F_52 ( V_18 , & V_14 ) ;
if ( V_103 ) {
struct V_66 * V_67 = V_103 -> V_67 ;
V_56 = - V_46 ;
if ( ! V_67 )
goto V_118;
if ( V_67 -> V_71 != V_38 )
goto V_118;
F_67 ( V_67 ) ;
F_70 ( & V_67 -> V_75 . V_89 ) ;
F_82 ( & V_18 -> V_85 ) ;
V_56 = F_103 ( V_34 , V_62 , V_67 ) ;
F_68 ( V_67 ) ;
if ( ! V_56 )
goto V_188;
if ( V_56 == - V_47 )
goto V_189;
if ( V_56 == - V_96 ) {
F_47 ( & V_14 ) ;
goto V_131;
}
goto V_188;
}
if ( F_54 ( & V_61 , V_34 , V_62 , 0 ) ) {
F_82 ( & V_18 -> V_85 ) ;
goto V_189;
}
V_56 = ( V_61 == V_62 ) ? 0 : - V_96 ;
V_118:
F_82 ( & V_18 -> V_85 ) ;
V_188:
F_47 ( & V_14 ) ;
return V_56 ;
V_189:
F_47 ( & V_14 ) ;
V_56 = F_48 ( V_34 ) ;
if ( ! V_56 )
goto V_131;
return V_56 ;
}
static inline
int F_161 ( struct V_17 * V_18 ,
struct V_59 * V_110 , union V_13 * V_28 ,
struct V_153 * V_154 )
{
int V_56 = 0 ;
if ( ! F_23 ( & V_110 -> V_14 , V_28 ) ) {
F_66 ( V_110 -> V_111 && ( & V_18 -> V_85 != V_110 -> V_111 ) ) ;
F_98 ( & V_110 -> V_70 , & V_18 -> V_112 ) ;
F_17 ( V_18 ) ;
V_56 = - V_160 ;
if ( V_154 && ! V_154 -> V_105 )
V_56 = - V_170 ;
else if ( F_150 ( V_38 ) )
V_56 = - V_187 ;
}
return V_56 ;
}
static int F_162 ( T_3 T_4 * V_34 , unsigned int V_98 ,
T_3 V_159 , T_7 * V_161 , T_3 V_123 ,
T_3 T_4 * V_127 )
{
struct V_153 V_154 , * V_162 = NULL ;
struct V_66 * V_67 = NULL ;
struct V_181 V_115 ;
struct V_17 * V_18 ;
union V_13 V_28 = V_73 ;
struct V_59 V_110 = V_165 ;
int V_182 , V_56 ;
if ( V_34 == V_127 )
return - V_46 ;
if ( ! V_123 )
return - V_46 ;
if ( V_161 ) {
V_162 = & V_154 ;
F_147 ( & V_162 -> V_156 , ( V_98 & V_166 ) ?
V_167 : V_168 ,
V_157 ) ;
F_148 ( V_162 , V_38 ) ;
F_149 ( & V_162 -> V_156 , * V_161 ,
V_38 -> V_169 ) ;
}
F_156 ( & V_115 ) ;
V_56 = F_32 ( V_127 , V_98 & V_124 , & V_28 , V_132 ) ;
if ( F_33 ( V_56 != 0 ) )
goto V_51;
V_110 . V_123 = V_123 ;
V_110 . V_115 = & V_115 ;
V_110 . V_138 = & V_28 ;
V_56 = F_145 ( V_34 , V_159 , V_98 , & V_110 , & V_18 ) ;
if ( V_56 )
goto V_190;
if ( F_23 ( & V_110 . V_14 , & V_28 ) ) {
F_128 ( V_18 ) ;
V_56 = - V_46 ;
goto V_135;
}
F_140 ( V_18 , & V_110 , V_162 ) ;
F_81 ( & V_18 -> V_85 ) ;
V_56 = F_161 ( V_18 , & V_110 , & V_28 , V_162 ) ;
F_82 ( & V_18 -> V_85 ) ;
if ( V_56 )
goto V_135;
if ( ! V_110 . V_115 ) {
if ( V_110 . V_67 && ( V_110 . V_67 -> V_71 != V_38 ) ) {
F_81 ( V_110 . V_111 ) ;
V_56 = F_136 ( V_127 , & V_110 , V_38 ) ;
if ( V_56 && F_138 ( & V_110 . V_67 -> V_75 ) == V_38 ) {
V_67 = V_110 . V_67 ;
F_67 ( V_67 ) ;
}
F_68 ( V_110 . V_67 ) ;
F_82 ( V_110 . V_111 ) ;
}
} else {
struct V_191 * V_75 ;
F_66 ( ! V_110 . V_67 ) ;
V_75 = & V_110 . V_67 -> V_75 ;
V_56 = F_158 ( V_75 , V_162 , & V_115 ) ;
F_81 ( V_110 . V_111 ) ;
if ( V_56 && ! F_159 ( V_75 , & V_115 ) )
V_56 = 0 ;
F_163 ( & V_115 ) ;
V_182 = F_137 ( V_127 , & V_110 , ! V_56 ) ;
if ( V_182 )
V_56 = ( V_182 < 0 ) ? V_182 : 0 ;
if ( V_56 && F_138 ( & V_110 . V_67 -> V_75 ) == V_38 ) {
V_67 = V_110 . V_67 ;
F_67 ( V_67 ) ;
}
F_135 ( & V_110 ) ;
}
if ( V_67 ) {
F_83 ( & V_67 -> V_75 ) ;
F_68 ( V_67 ) ;
}
if ( V_56 == - V_186 ) {
V_56 = - V_160 ;
}
V_135:
F_47 ( & V_110 . V_14 ) ;
V_190:
F_47 ( & V_28 ) ;
V_51:
if ( V_162 ) {
F_151 ( & V_162 -> V_156 ) ;
F_152 ( & V_162 -> V_156 ) ;
}
return V_56 ;
}
int F_164 ( T_3 T_4 * V_34 , struct V_76 * V_79 , int V_192 )
{
T_3 V_62 , V_104 ( V_193 ) , V_194 ;
V_131:
if ( F_124 ( V_62 , V_34 ) )
return - 1 ;
if ( ( V_62 & V_87 ) == F_85 ( V_79 ) ) {
V_194 = ( V_62 & V_109 ) | V_92 ;
if ( F_54 ( & V_193 , V_34 , V_62 , V_194 ) ) {
if ( F_48 ( V_34 ) )
return - 1 ;
goto V_131;
}
if ( V_193 != V_62 )
goto V_131;
if ( ! V_192 && ( V_62 & V_109 ) )
F_113 ( V_34 , 1 , 1 , V_195 ) ;
}
return 0 ;
}
static inline int F_165 ( struct V_196 T_4 * * V_197 ,
struct V_196 T_4 * T_4 * V_82 ,
unsigned int * V_192 )
{
unsigned long V_198 ;
if ( F_124 ( V_198 , ( unsigned long T_4 * ) V_82 ) )
return - V_47 ;
* V_197 = ( void T_4 * ) ( V_198 & ~ 1UL ) ;
* V_192 = V_198 & 1 ;
return 0 ;
}
void F_166 ( struct V_76 * V_79 )
{
struct V_199 T_4 * V_82 = V_79 -> V_196 ;
struct V_196 T_4 * V_197 , * V_200 , * V_201 ;
unsigned int V_202 = V_203 , V_192 , V_204 ;
unsigned int V_104 ( V_205 ) ;
unsigned long V_206 ;
int V_207 ;
if ( ! V_84 )
return;
if ( F_165 ( & V_197 , & V_82 -> V_70 . V_81 , & V_192 ) )
return;
if ( F_124 ( V_206 , & V_82 -> V_206 ) )
return;
if ( F_165 ( & V_201 , & V_82 -> V_208 , & V_204 ) )
return;
V_200 = NULL ;
while ( V_197 != & V_82 -> V_70 ) {
V_207 = F_165 ( & V_200 , & V_197 -> V_81 , & V_205 ) ;
if ( V_197 != V_201 )
if ( F_164 ( ( void T_4 * ) V_197 + V_206 ,
V_79 , V_192 ) )
return;
if ( V_207 )
return;
V_197 = V_200 ;
V_192 = V_205 ;
if ( ! -- V_202 )
break;
F_125 () ;
}
if ( V_201 )
F_164 ( ( void T_4 * ) V_201 + V_206 ,
V_79 , V_204 ) ;
}
long F_167 ( T_3 T_4 * V_34 , int V_129 , T_3 V_159 , T_7 * V_154 ,
T_3 T_4 * V_127 , T_3 V_209 , T_3 V_210 )
{
int V_211 = V_129 & V_212 ;
unsigned int V_98 = 0 ;
if ( ! ( V_129 & V_213 ) )
V_98 |= V_124 ;
if ( V_129 & V_214 ) {
V_98 |= V_166 ;
if ( V_211 != V_215 && V_211 != V_216 && \
V_211 != V_217 )
return - V_218 ;
}
switch ( V_211 ) {
case V_219 :
case V_220 :
case V_221 :
case V_217 :
case V_222 :
if ( ! V_84 )
return - V_218 ;
}
switch ( V_211 ) {
case V_215 :
V_210 = V_195 ;
case V_216 :
return F_146 ( V_34 , V_98 , V_159 , V_154 , V_210 ) ;
case V_223 :
V_210 = V_195 ;
case V_224 :
return F_113 ( V_34 , V_98 , V_159 , V_210 ) ;
case V_225 :
return F_123 ( V_34 , V_98 , V_127 , V_159 , V_209 , NULL , 0 ) ;
case V_226 :
return F_123 ( V_34 , V_98 , V_127 , V_159 , V_209 , & V_210 , 0 ) ;
case V_227 :
return F_116 ( V_34 , V_98 , V_127 , V_159 , V_209 , V_210 ) ;
case V_219 :
return F_153 ( V_34 , V_98 , V_154 , 0 ) ;
case V_220 :
return F_160 ( V_34 , V_98 ) ;
case V_221 :
return F_153 ( V_34 , V_98 , NULL , 1 ) ;
case V_217 :
V_210 = V_195 ;
return F_162 ( V_34 , V_98 , V_159 , V_154 , V_210 ,
V_127 ) ;
case V_222 :
return F_123 ( V_34 , V_98 , V_127 , V_159 , V_209 , & V_210 , 1 ) ;
}
return - V_218 ;
}
static void T_1 F_168 ( void )
{
#ifndef F_169
T_3 V_61 ;
if ( F_54 ( & V_61 , NULL , 0 , 0 ) == - V_47 )
V_84 = 1 ;
#endif
}
static int T_1 F_170 ( void )
{
unsigned int V_228 ;
unsigned long V_229 ;
#if V_230
V_26 = 16 ;
#else
V_26 = F_171 ( 256 * F_172 () ) ;
#endif
V_25 = F_173 ( L_6 , sizeof( * V_25 ) ,
V_26 , 0 ,
V_26 < 256 ? V_231 : 0 ,
& V_228 , NULL ,
V_26 , V_26 ) ;
V_26 = 1UL << V_228 ;
F_168 () ;
for ( V_229 = 0 ; V_229 < V_26 ; V_229 ++ ) {
F_64 ( & V_25 [ V_229 ] . V_19 , 0 ) ;
F_174 ( & V_25 [ V_229 ] . V_112 ) ;
F_175 ( & V_25 [ V_229 ] . V_85 ) ;
}
return 0 ;
}
