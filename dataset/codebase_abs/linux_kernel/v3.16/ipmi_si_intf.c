static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_3 , V_2 ) ;
}
static void F_3 ( struct V_4 * V_4 ,
struct V_5 * V_6 )
{
F_4 ( V_4 -> V_7 , V_6 ) ;
}
static void F_5 ( struct V_4 * V_4 , int V_8 )
{
struct V_5 * V_6 = V_4 -> V_9 ;
if ( V_8 < 0 || V_8 > V_10 )
V_8 = V_10 ;
V_6 -> V_11 [ 0 ] = V_6 -> V_12 [ 0 ] | 4 ;
V_6 -> V_11 [ 1 ] = V_6 -> V_12 [ 1 ] ;
V_6 -> V_11 [ 2 ] = V_8 ;
V_6 -> V_13 = 3 ;
V_4 -> V_9 = NULL ;
F_3 ( V_4 , V_6 ) ;
}
static enum V_14 F_6 ( struct V_4 * V_4 )
{
int V_15 ;
struct V_16 * V_17 = NULL ;
#ifdef F_7
struct V_18 V_19 ;
#endif
if ( ! F_8 ( & ( V_4 -> V_20 ) ) ) {
V_17 = V_4 -> V_20 . V_21 ;
} else if ( ! F_8 ( & ( V_4 -> V_22 ) ) ) {
V_17 = V_4 -> V_22 . V_21 ;
}
if ( ! V_17 ) {
V_4 -> V_9 = NULL ;
V_15 = V_23 ;
} else {
int V_24 ;
F_9 ( V_17 ) ;
V_4 -> V_9 = F_10 ( V_17 ,
struct V_5 ,
V_25 ) ;
#ifdef F_7
F_11 ( & V_19 ) ;
F_12 ( V_26 L_1 , V_19 . V_27 , V_19 . V_28 ) ;
#endif
V_24 = F_13 ( & V_3 ,
0 , V_4 ) ;
if ( V_24 & V_29 ) {
V_15 = V_30 ;
goto V_31;
}
V_24 = V_4 -> V_32 -> V_33 (
V_4 -> V_34 ,
V_4 -> V_9 -> V_12 ,
V_4 -> V_9 -> V_35 ) ;
if ( V_24 )
F_5 ( V_4 , V_24 ) ;
V_15 = V_30 ;
}
V_31:
return V_15 ;
}
static void F_14 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 2 ] ;
V_6 [ 0 ] = ( V_36 << 2 ) ;
V_6 [ 1 ] = V_37 ;
V_4 -> V_32 -> V_33 ( V_4 -> V_34 , V_6 , 2 ) ;
V_4 -> V_38 = V_39 ;
}
static void F_15 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 2 ] ;
V_6 [ 0 ] = ( V_36 << 2 ) ;
V_6 [ 1 ] = V_37 ;
V_4 -> V_32 -> V_33 ( V_4 -> V_34 , V_6 , 2 ) ;
V_4 -> V_38 = V_40 ;
}
static void F_16 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 3 ] ;
V_6 [ 0 ] = ( V_36 << 2 ) ;
V_6 [ 1 ] = V_41 ;
V_6 [ 2 ] = V_42 ;
V_4 -> V_32 -> V_33 ( V_4 -> V_34 , V_6 , 3 ) ;
V_4 -> V_38 = V_43 ;
}
static void F_17 ( struct V_4 * V_4 , unsigned long V_44 )
{
V_4 -> V_45 = V_46 ;
F_18 ( & V_4 -> V_47 , V_44 ) ;
V_4 -> V_48 = true ;
}
static inline void F_19 ( struct V_4 * V_4 )
{
if ( ( V_4 -> V_49 ) && ( ! V_4 -> V_50 ) ) {
F_15 ( V_4 ) ;
V_4 -> V_50 = true ;
if ( ! F_20 ( & V_4 -> V_51 ) )
F_17 ( V_4 , V_46 + V_52 ) ;
}
}
static inline void F_21 ( struct V_4 * V_4 )
{
if ( ( V_4 -> V_49 ) && ( V_4 -> V_50 ) ) {
F_14 ( V_4 ) ;
V_4 -> V_50 = false ;
}
}
static void F_22 ( struct V_4 * V_4 )
{
V_53:
if ( V_4 -> V_54 & V_42 ) {
F_23 ( V_4 , V_55 ) ;
F_16 ( V_4 ) ;
V_4 -> V_54 &= ~ V_42 ;
F_24 ( V_4 -> V_7 ) ;
} else if ( V_4 -> V_54 & V_56 ) {
V_4 -> V_9 = F_25 () ;
if ( ! V_4 -> V_9 ) {
F_19 ( V_4 ) ;
V_4 -> V_38 = V_57 ;
return;
}
F_21 ( V_4 ) ;
V_4 -> V_9 -> V_12 [ 0 ] = ( V_36 << 2 ) ;
V_4 -> V_9 -> V_12 [ 1 ] = V_58 ;
V_4 -> V_9 -> V_35 = 2 ;
V_4 -> V_32 -> V_33 (
V_4 -> V_34 ,
V_4 -> V_9 -> V_12 ,
V_4 -> V_9 -> V_35 ) ;
V_4 -> V_38 = V_59 ;
} else if ( V_4 -> V_54 & V_60 ) {
V_4 -> V_9 = F_25 () ;
if ( ! V_4 -> V_9 ) {
F_19 ( V_4 ) ;
V_4 -> V_38 = V_57 ;
return;
}
F_21 ( V_4 ) ;
V_4 -> V_9 -> V_12 [ 0 ] = ( V_36 << 2 ) ;
V_4 -> V_9 -> V_12 [ 1 ] = V_61 ;
V_4 -> V_9 -> V_35 = 2 ;
V_4 -> V_32 -> V_33 (
V_4 -> V_34 ,
V_4 -> V_9 -> V_12 ,
V_4 -> V_9 -> V_35 ) ;
V_4 -> V_38 = V_62 ;
} else if ( V_4 -> V_54 & V_63 &&
V_4 -> V_64 ) {
if ( V_4 -> V_64 ( V_4 ) )
goto V_53;
} else
V_4 -> V_38 = V_57 ;
}
static void F_26 ( struct V_4 * V_4 )
{
struct V_5 * V_6 ;
#ifdef F_7
struct V_18 V_19 ;
F_11 ( & V_19 ) ;
F_12 ( V_26 L_2 , V_19 . V_27 , V_19 . V_28 ) ;
#endif
switch ( V_4 -> V_38 ) {
case V_57 :
if ( ! V_4 -> V_9 )
break;
V_4 -> V_9 -> V_13
= V_4 -> V_32 -> V_65 (
V_4 -> V_34 ,
V_4 -> V_9 -> V_11 ,
V_66 ) ;
V_6 = V_4 -> V_9 ;
V_4 -> V_9 = NULL ;
F_3 ( V_4 , V_6 ) ;
break;
case V_67 :
{
unsigned char V_6 [ 4 ] ;
unsigned int V_68 ;
V_68 = V_4 -> V_32 -> V_65 ( V_4 -> V_34 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 ) {
V_4 -> V_38 = V_57 ;
} else if ( V_68 < 4 ) {
V_4 -> V_38 = V_57 ;
} else {
V_4 -> V_54 = V_6 [ 3 ] ;
F_22 ( V_4 ) ;
}
break;
}
case V_43 :
case V_69 :
{
unsigned char V_6 [ 3 ] ;
V_4 -> V_32 -> V_65 ( V_4 -> V_34 , V_6 , 3 ) ;
if ( V_6 [ 2 ] != 0 ) {
F_27 ( V_4 -> V_70 ,
L_3 , V_6 [ 2 ] ) ;
}
if ( V_4 -> V_38 == V_69 )
F_14 ( V_4 ) ;
else
V_4 -> V_38 = V_57 ;
break;
}
case V_62 :
{
V_4 -> V_9 -> V_13
= V_4 -> V_32 -> V_65 (
V_4 -> V_34 ,
V_4 -> V_9 -> V_11 ,
V_66 ) ;
V_6 = V_4 -> V_9 ;
V_4 -> V_9 = NULL ;
if ( V_6 -> V_11 [ 2 ] != 0 ) {
V_6 -> V_71 ( V_6 ) ;
V_4 -> V_54 &= ~ V_60 ;
F_22 ( V_4 ) ;
} else {
F_23 ( V_4 , V_72 ) ;
F_22 ( V_4 ) ;
F_3 ( V_4 , V_6 ) ;
}
break;
}
case V_59 :
{
V_4 -> V_9 -> V_13
= V_4 -> V_32 -> V_65 (
V_4 -> V_34 ,
V_4 -> V_9 -> V_11 ,
V_66 ) ;
V_6 = V_4 -> V_9 ;
V_4 -> V_9 = NULL ;
if ( V_6 -> V_11 [ 2 ] != 0 ) {
V_6 -> V_71 ( V_6 ) ;
V_4 -> V_54 &= ~ V_56 ;
F_22 ( V_4 ) ;
} else {
F_23 ( V_4 , V_73 ) ;
F_22 ( V_4 ) ;
F_3 ( V_4 , V_6 ) ;
}
break;
}
case V_39 :
{
unsigned char V_6 [ 4 ] ;
V_4 -> V_32 -> V_65 ( V_4 -> V_34 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 ) {
F_27 ( V_4 -> V_70 ,
L_4 , V_6 [ 2 ] ) ;
F_27 ( V_4 -> V_70 ,
L_5 ) ;
V_4 -> V_38 = V_57 ;
} else {
V_6 [ 0 ] = ( V_36 << 2 ) ;
V_6 [ 1 ] = V_74 ;
V_6 [ 2 ] = ( V_6 [ 3 ] |
V_75 |
V_76 ) ;
V_4 -> V_32 -> V_33 (
V_4 -> V_34 , V_6 , 3 ) ;
V_4 -> V_38 = V_77 ;
}
break;
}
case V_77 :
{
unsigned char V_6 [ 4 ] ;
V_4 -> V_32 -> V_65 ( V_4 -> V_34 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 ) {
F_27 ( V_4 -> V_70 ,
L_6 , V_6 [ 2 ] ) ;
F_27 ( V_4 -> V_70 ,
L_5 ) ;
} else
V_4 -> V_50 = false ;
V_4 -> V_38 = V_57 ;
break;
}
case V_40 :
{
unsigned char V_6 [ 4 ] ;
V_4 -> V_32 -> V_65 ( V_4 -> V_34 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 ) {
F_27 ( V_4 -> V_70 , L_7
L_8 ) ;
V_4 -> V_38 = V_57 ;
} else {
V_6 [ 0 ] = ( V_36 << 2 ) ;
V_6 [ 1 ] = V_74 ;
V_6 [ 2 ] = ( V_6 [ 3 ] &
~ ( V_75 |
V_76 ) ) ;
V_4 -> V_32 -> V_33 (
V_4 -> V_34 , V_6 , 3 ) ;
V_4 -> V_38 = V_78 ;
}
break;
}
case V_78 :
{
unsigned char V_6 [ 4 ] ;
V_4 -> V_32 -> V_65 ( V_4 -> V_34 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 ) {
F_27 ( V_4 -> V_70 , L_7
L_9 ) ;
}
V_4 -> V_38 = V_57 ;
break;
}
}
}
static enum V_14 F_28 ( struct V_4 * V_4 ,
int time )
{
enum V_14 V_14 ;
V_79:
V_14 = V_4 -> V_32 -> V_80 ( V_4 -> V_34 , time ) ;
time = 0 ;
while ( V_14 == V_30 )
V_14 = V_4 -> V_32 -> V_80 ( V_4 -> V_34 , 0 ) ;
if ( V_14 == V_81 ) {
F_23 ( V_4 , V_82 ) ;
F_26 ( V_4 ) ;
V_14 = V_4 -> V_32 -> V_80 ( V_4 -> V_34 , 0 ) ;
} else if ( V_14 == V_83 ) {
F_23 ( V_4 , V_84 ) ;
V_4 -> V_38 = V_57 ;
if ( V_4 -> V_9 != NULL ) {
F_5 ( V_4 , V_10 ) ;
}
V_14 = V_4 -> V_32 -> V_80 ( V_4 -> V_34 , 0 ) ;
}
if ( F_29 ( V_4 -> V_7 ) && V_14 == V_85 ) {
unsigned char V_6 [ 2 ] ;
F_23 ( V_4 , V_86 ) ;
V_6 [ 0 ] = ( V_36 << 2 ) ;
V_6 [ 1 ] = V_87 ;
V_4 -> V_32 -> V_33 (
V_4 -> V_34 , V_6 , 2 ) ;
V_4 -> V_38 = V_67 ;
goto V_79;
}
if ( V_14 == V_23 ) {
F_23 ( V_4 , V_88 ) ;
V_14 = F_6 ( V_4 ) ;
if ( V_14 != V_23 )
goto V_79;
}
if ( ( V_14 == V_23 )
&& ( F_20 ( & V_4 -> V_89 ) ) ) {
F_30 ( & V_4 -> V_89 , 0 ) ;
V_4 -> V_9 = F_25 () ;
if ( ! V_4 -> V_9 )
goto V_31;
V_4 -> V_9 -> V_12 [ 0 ] = ( V_36 << 2 ) ;
V_4 -> V_9 -> V_12 [ 1 ] = V_61 ;
V_4 -> V_9 -> V_35 = 2 ;
V_4 -> V_32 -> V_33 (
V_4 -> V_34 ,
V_4 -> V_9 -> V_12 ,
V_4 -> V_9 -> V_35 ) ;
V_4 -> V_38 = V_62 ;
goto V_79;
}
V_31:
return V_14 ;
}
static void F_31 ( struct V_4 * V_4 )
{
if ( V_4 -> V_38 == V_57 && V_4 -> V_9 == NULL ) {
F_17 ( V_4 , V_46 + V_52 ) ;
if ( V_4 -> V_90 )
F_32 ( V_4 -> V_90 ) ;
F_6 ( V_4 ) ;
F_28 ( V_4 , 0 ) ;
}
}
static void F_33 ( void * V_91 ,
struct V_5 * V_6 ,
int V_92 )
{
struct V_4 * V_4 = V_91 ;
enum V_14 V_93 ;
unsigned long V_94 ;
#ifdef F_7
struct V_18 V_19 ;
#endif
if ( F_20 ( & V_4 -> V_51 ) ) {
V_6 -> V_11 [ 0 ] = V_6 -> V_12 [ 0 ] | 4 ;
V_6 -> V_11 [ 1 ] = V_6 -> V_12 [ 1 ] ;
V_6 -> V_11 [ 2 ] = V_10 ;
V_6 -> V_13 = 3 ;
F_3 ( V_4 , V_6 ) ;
return;
}
#ifdef F_7
F_11 ( & V_19 ) ;
F_12 ( L_10 , V_19 . V_27 , V_19 . V_28 ) ;
#endif
if ( V_4 -> V_95 ) {
F_34 ( & ( V_6 -> V_25 ) , & ( V_4 -> V_22 ) ) ;
V_93 = F_28 ( V_4 , 0 ) ;
while ( V_93 != V_23 ) {
F_35 ( V_96 ) ;
V_93 = F_28 ( V_4 ,
V_96 ) ;
}
return;
}
F_36 ( & V_4 -> V_97 , V_94 ) ;
if ( V_92 > 0 )
F_34 ( & V_6 -> V_25 , & V_4 -> V_20 ) ;
else
F_34 ( & V_6 -> V_25 , & V_4 -> V_22 ) ;
F_31 ( V_4 ) ;
F_37 ( & V_4 -> V_97 , V_94 ) ;
}
static void F_38 ( void * V_91 , bool V_98 )
{
struct V_4 * V_4 = V_91 ;
enum V_14 V_93 ;
V_4 -> V_95 = V_98 ;
if ( V_98 ) {
V_93 = F_28 ( V_4 , 0 ) ;
while ( V_93 != V_23 ) {
F_35 ( V_96 ) ;
V_93 = F_28 ( V_4 ,
V_96 ) ;
}
}
}
static inline void F_39 ( struct V_99 * V_100 )
{
V_100 -> V_101 = - 1 ;
}
static inline int F_40 ( struct V_99 * V_100 )
{
return V_100 -> V_101 != - 1 ;
}
static int F_41 ( enum V_14 V_102 ,
const struct V_4 * V_4 ,
struct V_99 * V_103 )
{
unsigned int V_104 = 0 ;
if ( V_4 -> V_105 < V_106 )
V_104 = V_107 [ V_4 -> V_105 ] ;
if ( V_104 == 0 || V_102 != V_108 )
F_39 ( V_103 ) ;
else if ( ! F_40 ( V_103 ) ) {
F_42 ( V_103 ) ;
F_43 ( V_103 , V_104 * V_109 ) ;
} else {
struct V_99 V_110 ;
F_42 ( & V_110 ) ;
if ( F_44 ( F_45 ( & V_110 , V_103 ) > 0 ) ) {
F_39 ( V_103 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_46 ( void * V_12 )
{
struct V_4 * V_4 = V_12 ;
unsigned long V_94 ;
enum V_14 V_102 ;
struct V_99 V_103 ;
F_39 ( & V_103 ) ;
F_47 ( V_111 , V_112 ) ;
while ( ! F_48 () ) {
int V_113 ;
F_36 ( & ( V_4 -> V_97 ) , V_94 ) ;
V_102 = F_28 ( V_4 , 0 ) ;
if ( V_102 != V_23 && ! V_4 -> V_48 )
F_17 ( V_4 , V_46 + V_52 ) ;
F_37 ( & ( V_4 -> V_97 ) , V_94 ) ;
V_113 = F_41 ( V_102 , V_4 ,
& V_103 ) ;
if ( V_102 == V_30 )
;
else if ( V_102 == V_108 && V_113 )
F_49 () ;
else if ( V_102 == V_23 ) {
if ( F_20 ( & V_4 -> V_114 ) ) {
F_50 ( 100 ) ;
} else {
F_51 ( V_115 ) ;
F_49 () ;
}
} else
F_50 ( 1 ) ;
}
return 0 ;
}
static void F_52 ( void * V_91 )
{
struct V_4 * V_4 = V_91 ;
unsigned long V_94 = 0 ;
bool V_95 = V_4 -> V_95 ;
F_35 ( 10 ) ;
if ( ! V_95 )
F_36 ( & V_4 -> V_97 , V_94 ) ;
F_28 ( V_4 , 10 ) ;
if ( ! V_95 )
F_37 ( & V_4 -> V_97 , V_94 ) ;
}
static void F_53 ( void * V_91 )
{
struct V_4 * V_4 = V_91 ;
if ( F_20 ( & V_4 -> V_51 ) ||
! V_4 -> V_116 )
return;
F_30 ( & V_4 -> V_89 , 1 ) ;
}
static void F_54 ( void * V_91 , bool V_117 )
{
struct V_4 * V_4 = V_91 ;
unsigned long V_94 ;
F_30 ( & V_4 -> V_114 , V_117 ) ;
F_36 ( & V_4 -> V_97 , V_94 ) ;
F_31 ( V_4 ) ;
F_37 ( & V_4 -> V_97 , V_94 ) ;
}
static void F_55 ( unsigned long V_12 )
{
struct V_4 * V_4 = (struct V_4 * ) V_12 ;
enum V_14 V_102 ;
unsigned long V_94 ;
unsigned long V_118 ;
long V_119 ;
long V_120 ;
#ifdef F_7
struct V_18 V_19 ;
#endif
F_36 ( & ( V_4 -> V_97 ) , V_94 ) ;
#ifdef F_7
F_11 ( & V_19 ) ;
F_12 ( V_26 L_11 , V_19 . V_27 , V_19 . V_28 ) ;
#endif
V_118 = V_46 ;
V_119 = ( ( ( long ) V_118 - ( long ) V_4 -> V_45 )
* V_121 ) ;
V_102 = F_28 ( V_4 , V_119 ) ;
if ( ( V_4 -> V_49 ) && ( ! V_4 -> V_50 ) ) {
V_120 = V_46 + V_52 ;
F_23 ( V_4 , V_122 ) ;
goto V_123;
}
if ( V_102 == V_108 ) {
F_23 ( V_4 , V_124 ) ;
V_120 = V_46 + 1 ;
} else {
F_23 ( V_4 , V_122 ) ;
V_120 = V_46 + V_52 ;
}
V_123:
if ( V_102 != V_23 )
F_17 ( V_4 , V_120 ) ;
else
V_4 -> V_48 = false ;
F_37 ( & ( V_4 -> V_97 ) , V_94 ) ;
}
static T_1 F_56 ( int V_49 , void * V_12 )
{
struct V_4 * V_4 = V_12 ;
unsigned long V_94 ;
#ifdef F_7
struct V_18 V_19 ;
#endif
F_36 ( & ( V_4 -> V_97 ) , V_94 ) ;
F_23 ( V_4 , V_125 ) ;
#ifdef F_7
F_11 ( & V_19 ) ;
F_12 ( V_26 L_12 , V_19 . V_27 , V_19 . V_28 ) ;
#endif
F_28 ( V_4 , 0 ) ;
F_37 ( & ( V_4 -> V_97 ) , V_94 ) ;
return V_126 ;
}
static T_1 F_57 ( int V_49 , void * V_12 )
{
struct V_4 * V_4 = V_12 ;
V_4 -> V_127 . V_128 ( & V_4 -> V_127 , V_129 ,
V_130
| V_131 ) ;
return F_56 ( V_49 , V_12 ) ;
}
static int F_58 ( void * V_91 ,
T_2 V_7 )
{
struct V_4 * V_132 = V_91 ;
int V_117 = 0 ;
V_132 -> V_7 = V_7 ;
if ( V_132 -> V_133 )
V_132 -> V_133 ( V_132 ) ;
F_59 ( & V_132 -> V_47 , F_55 , ( long ) V_132 ) ;
F_17 ( V_132 , V_46 + V_52 ) ;
if ( V_132 -> V_105 < V_134 )
V_117 = V_135 [ V_132 -> V_105 ] ;
else if ( ( V_132 -> V_136 != V_137 ) && ( ! V_132 -> V_49 ) )
V_117 = 1 ;
if ( V_117 ) {
V_132 -> V_90 = F_60 ( F_46 , V_132 ,
L_13 , V_132 -> V_105 ) ;
if ( F_61 ( V_132 -> V_90 ) ) {
F_62 ( V_132 -> V_70 , L_14
L_15
L_16 ,
F_63 ( V_132 -> V_90 ) ) ;
V_132 -> V_90 = NULL ;
}
}
return 0 ;
}
static int F_64 ( void * V_91 , struct V_138 * V_12 )
{
struct V_4 * V_139 = V_91 ;
V_12 -> V_140 = V_139 -> V_141 ;
V_12 -> V_70 = V_139 -> V_70 ;
V_12 -> V_142 = V_139 -> V_142 ;
F_65 ( V_139 -> V_70 ) ;
return 0 ;
}
static void F_66 ( void * V_91 , bool V_117 )
{
struct V_4 * V_4 = V_91 ;
if ( ! V_117 )
F_30 ( & V_4 -> V_89 , 0 ) ;
}
static void F_67 ( struct V_4 * V_143 )
{
if ( V_143 -> V_136 == V_137 )
V_143 -> V_127 . V_128 ( & V_143 -> V_127 , V_129 , 0 ) ;
F_68 ( V_143 -> V_49 , V_143 ) ;
}
static int F_69 ( struct V_4 * V_143 )
{
int V_15 ;
if ( ! V_143 -> V_49 )
return 0 ;
if ( V_143 -> V_136 == V_137 ) {
V_15 = F_70 ( V_143 -> V_49 ,
F_57 ,
V_144 ,
V_145 ,
V_143 ) ;
if ( ! V_15 )
V_143 -> V_127 . V_128 ( & V_143 -> V_127 , V_129 ,
V_131 ) ;
} else
V_15 = F_70 ( V_143 -> V_49 ,
F_56 ,
V_144 ,
V_145 ,
V_143 ) ;
if ( V_15 ) {
F_27 ( V_143 -> V_70 , L_17
L_18 ,
V_145 , V_143 -> V_49 ) ;
V_143 -> V_49 = 0 ;
} else {
V_143 -> V_146 = F_67 ;
F_71 ( V_143 -> V_70 , L_19 , V_143 -> V_49 ) ;
}
return V_15 ;
}
static unsigned char F_72 ( struct V_147 * V_127 , unsigned int V_148 )
{
unsigned int V_149 = V_127 -> V_150 ;
return F_73 ( V_149 + ( V_148 * V_127 -> V_151 ) ) ;
}
static void F_74 ( struct V_147 * V_127 , unsigned int V_148 ,
unsigned char V_152 )
{
unsigned int V_149 = V_127 -> V_150 ;
F_75 ( V_152 , V_149 + ( V_148 * V_127 -> V_151 ) ) ;
}
static unsigned char F_76 ( struct V_147 * V_127 , unsigned int V_148 )
{
unsigned int V_149 = V_127 -> V_150 ;
return ( F_77 ( V_149 + ( V_148 * V_127 -> V_151 ) ) >> V_127 -> V_153 ) & 0xff ;
}
static void F_78 ( struct V_147 * V_127 , unsigned int V_148 ,
unsigned char V_152 )
{
unsigned int V_149 = V_127 -> V_150 ;
F_79 ( V_152 << V_127 -> V_153 , V_149 + ( V_148 * V_127 -> V_151 ) ) ;
}
static unsigned char F_80 ( struct V_147 * V_127 , unsigned int V_148 )
{
unsigned int V_149 = V_127 -> V_150 ;
return ( F_81 ( V_149 + ( V_148 * V_127 -> V_151 ) ) >> V_127 -> V_153 ) & 0xff ;
}
static void F_82 ( struct V_147 * V_127 , unsigned int V_148 ,
unsigned char V_152 )
{
unsigned int V_149 = V_127 -> V_150 ;
F_83 ( V_152 << V_127 -> V_153 , V_149 + ( V_148 * V_127 -> V_151 ) ) ;
}
static void F_84 ( struct V_4 * V_143 )
{
unsigned int V_149 = V_143 -> V_127 . V_150 ;
int V_154 ;
if ( V_149 ) {
for ( V_154 = 0 ; V_154 < V_143 -> V_155 ; V_154 ++ )
F_85 ( V_149 + V_154 * V_143 -> V_127 . V_151 ,
V_143 -> V_127 . V_156 ) ;
}
}
static int F_86 ( struct V_4 * V_143 )
{
unsigned int V_149 = V_143 -> V_127 . V_150 ;
int V_154 ;
if ( ! V_149 )
return - V_157 ;
V_143 -> V_158 = F_84 ;
switch ( V_143 -> V_127 . V_156 ) {
case 1 :
V_143 -> V_127 . V_159 = F_72 ;
V_143 -> V_127 . V_128 = F_74 ;
break;
case 2 :
V_143 -> V_127 . V_159 = F_76 ;
V_143 -> V_127 . V_128 = F_78 ;
break;
case 4 :
V_143 -> V_127 . V_159 = F_80 ;
V_143 -> V_127 . V_128 = F_82 ;
break;
default:
F_27 ( V_143 -> V_70 , L_20 ,
V_143 -> V_127 . V_156 ) ;
return - V_160 ;
}
for ( V_154 = 0 ; V_154 < V_143 -> V_155 ; V_154 ++ ) {
if ( F_87 ( V_149 + V_154 * V_143 -> V_127 . V_151 ,
V_143 -> V_127 . V_156 , V_145 ) == NULL ) {
while ( V_154 -- ) {
F_85 ( V_149 + V_154 * V_143 -> V_127 . V_151 ,
V_143 -> V_127 . V_156 ) ;
}
return - V_161 ;
}
}
return 0 ;
}
static unsigned char F_88 ( struct V_147 * V_127 , unsigned int V_148 )
{
return F_89 ( ( V_127 -> V_149 ) + ( V_148 * V_127 -> V_151 ) ) ;
}
static void F_90 ( struct V_147 * V_127 , unsigned int V_148 ,
unsigned char V_152 )
{
F_91 ( V_152 , ( V_127 -> V_149 ) + ( V_148 * V_127 -> V_151 ) ) ;
}
static unsigned char F_92 ( struct V_147 * V_127 , unsigned int V_148 )
{
return ( F_93 ( ( V_127 -> V_149 ) + ( V_148 * V_127 -> V_151 ) ) >> V_127 -> V_153 )
& 0xff ;
}
static void F_94 ( struct V_147 * V_127 , unsigned int V_148 ,
unsigned char V_152 )
{
F_91 ( V_152 << V_127 -> V_153 , ( V_127 -> V_149 ) + ( V_148 * V_127 -> V_151 ) ) ;
}
static unsigned char F_95 ( struct V_147 * V_127 , unsigned int V_148 )
{
return ( F_96 ( ( V_127 -> V_149 ) + ( V_148 * V_127 -> V_151 ) ) >> V_127 -> V_153 )
& 0xff ;
}
static void F_97 ( struct V_147 * V_127 , unsigned int V_148 ,
unsigned char V_152 )
{
F_98 ( V_152 << V_127 -> V_153 , ( V_127 -> V_149 ) + ( V_148 * V_127 -> V_151 ) ) ;
}
static unsigned char F_99 ( struct V_147 * V_127 , unsigned int V_148 )
{
return ( F_100 ( ( V_127 -> V_149 ) + ( V_148 * V_127 -> V_151 ) ) >> V_127 -> V_153 )
& 0xff ;
}
static void F_101 ( struct V_147 * V_127 , unsigned int V_148 ,
unsigned char V_152 )
{
F_102 ( V_152 << V_127 -> V_153 , ( V_127 -> V_149 ) + ( V_148 * V_127 -> V_151 ) ) ;
}
static void F_103 ( struct V_4 * V_143 )
{
unsigned long V_149 = V_143 -> V_127 . V_150 ;
int V_162 ;
if ( V_143 -> V_127 . V_149 ) {
F_104 ( V_143 -> V_127 . V_149 ) ;
V_162 = ( ( V_143 -> V_155 * V_143 -> V_127 . V_151 )
- ( V_143 -> V_127 . V_151 - V_143 -> V_127 . V_156 ) ) ;
F_105 ( V_149 , V_162 ) ;
}
}
static int F_106 ( struct V_4 * V_143 )
{
unsigned long V_149 = V_143 -> V_127 . V_150 ;
int V_162 ;
if ( ! V_149 )
return - V_157 ;
V_143 -> V_158 = F_103 ;
switch ( V_143 -> V_127 . V_156 ) {
case 1 :
V_143 -> V_127 . V_159 = F_88 ;
V_143 -> V_127 . V_128 = F_90 ;
break;
case 2 :
V_143 -> V_127 . V_159 = F_92 ;
V_143 -> V_127 . V_128 = F_94 ;
break;
case 4 :
V_143 -> V_127 . V_159 = F_95 ;
V_143 -> V_127 . V_128 = F_97 ;
break;
#ifdef F_100
case 8 :
V_143 -> V_127 . V_159 = F_99 ;
V_143 -> V_127 . V_128 = F_101 ;
break;
#endif
default:
F_27 ( V_143 -> V_70 , L_20 ,
V_143 -> V_127 . V_156 ) ;
return - V_160 ;
}
V_162 = ( ( V_143 -> V_155 * V_143 -> V_127 . V_151 )
- ( V_143 -> V_127 . V_151 - V_143 -> V_127 . V_156 ) ) ;
if ( F_107 ( V_149 , V_162 , V_145 ) == NULL )
return - V_161 ;
V_143 -> V_127 . V_149 = F_108 ( V_149 , V_162 ) ;
if ( V_143 -> V_127 . V_149 == NULL ) {
F_105 ( V_149 , V_162 ) ;
return - V_161 ;
}
return 0 ;
}
static int F_109 ( struct V_163 * V_164 , int * V_165 , char * V_166 , char * * V_167 )
{
char * V_168 ;
int V_169 ;
V_168 = strchr ( * V_167 , ',' ) ;
if ( ! V_168 ) {
F_12 (KERN_WARNING PFX L_21 , name) ;
return - V_160 ;
}
* V_168 = '\0' ;
V_168 ++ ;
for ( V_169 = 0 ; V_170 [ V_169 ] . V_166 ; V_169 ++ ) {
if ( strcmp ( * V_167 , V_164 [ V_169 ] . V_166 ) == 0 ) {
* V_165 = V_164 [ V_169 ] . V_165 ;
* V_167 = V_168 ;
return 0 ;
}
}
F_12 (KERN_WARNING PFX L_22 , name, *curr) ;
return - V_160 ;
}
static int F_110 ( const char * V_167 , const char * V_171 ,
const char * V_166 , int * V_165 )
{
char * V_172 ;
if ( strcmp ( V_167 , V_166 ) == 0 ) {
if ( ! V_171 ) {
F_12 (KERN_WARNING PFX
L_23 ,
curr) ;
return - V_160 ;
}
* V_165 = F_111 ( V_171 , & V_172 , 0 ) ;
if ( ( * V_172 != '\0' ) || ( * V_171 == '\0' ) ) {
F_12 (KERN_WARNING PFX
L_24 ,
curr) ;
return - V_160 ;
}
return 1 ;
}
return 0 ;
}
static struct V_4 * F_112 ( void )
{
struct V_4 * V_143 = F_113 ( sizeof( * V_143 ) , V_173 ) ;
if ( V_143 )
F_114 ( & V_143 -> V_97 ) ;
return V_143 ;
}
static int F_115 ( const char * V_165 , struct V_174 * V_175 )
{
char * V_176 = F_116 ( V_165 , V_173 ) ;
int V_15 ;
char * V_21 , * V_167 , * V_168 , * V_172 , * V_177 ;
enum V_178 V_179 ;
enum V_136 V_136 ;
int V_180 ;
unsigned long V_149 ;
int V_151 ;
int V_156 ;
int V_153 ;
int V_49 ;
int V_181 ;
int V_182 ;
int V_68 ;
struct V_4 * V_143 ;
if ( ! V_176 )
return - V_183 ;
V_68 = strlen ( V_176 ) ;
V_182 = V_68 - 1 ;
while ( ( V_182 >= 0 ) && isspace ( V_176 [ V_182 ] ) ) {
V_176 [ V_182 ] = '\0' ;
V_182 -- ;
}
for ( V_167 = V_176 ; V_167 ; V_167 = V_21 ) {
V_151 = 1 ;
V_156 = 1 ;
V_153 = 0 ;
V_49 = 0 ;
V_181 = 0 ;
V_21 = strchr ( V_167 , ':' ) ;
if ( V_21 ) {
* V_21 = '\0' ;
V_21 ++ ;
}
V_15 = F_109 ( V_170 , & V_182 , L_25 , & V_167 ) ;
if ( V_15 )
break;
V_179 = V_182 ;
V_15 = F_109 ( V_184 , & V_182 , L_26 , & V_167 ) ;
if ( V_15 )
break;
V_136 = V_182 ;
V_15 = F_109 ( V_185 , & V_180 , L_27 , & V_167 ) ;
if ( V_15 )
break;
V_168 = strchr ( V_167 , ',' ) ;
if ( V_168 ) {
* V_168 = '\0' ;
V_168 ++ ;
}
V_149 = F_111 ( V_167 , & V_172 , 0 ) ;
if ( ( * V_172 != '\0' ) || ( * V_167 == '\0' ) ) {
F_12 (KERN_WARNING PFX L_28
L_29 , curr) ;
break;
}
while ( V_168 ) {
V_167 = V_168 ;
V_168 = strchr ( V_167 , ',' ) ;
if ( V_168 ) {
* V_168 = '\0' ;
V_168 ++ ;
}
V_177 = strchr ( V_167 , '=' ) ;
if ( V_177 ) {
* V_177 = '\0' ;
V_177 ++ ;
}
V_15 = F_110 ( V_167 , V_177 , L_30 , & V_151 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = F_110 ( V_167 , V_177 , L_31 , & V_156 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = F_110 ( V_167 , V_177 , L_32 , & V_153 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = F_110 ( V_167 , V_177 , L_33 , & V_49 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = F_110 ( V_167 , V_177 , L_34 , & V_181 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = - V_160 ;
F_12 (KERN_WARNING PFX
L_35 ,
curr) ;
goto V_31;
}
if ( V_179 == V_186 ) {
V_143 = F_112 () ;
if ( ! V_143 ) {
V_15 = - V_183 ;
goto V_31;
}
V_143 -> V_141 = V_187 ;
V_143 -> V_136 = V_136 ;
V_143 -> V_127 . V_150 = V_149 ;
V_143 -> V_127 . V_188 = V_180 ;
if ( V_180 == V_189 )
V_143 -> V_190 = F_106 ;
else
V_143 -> V_190 = F_86 ;
V_143 -> V_127 . V_149 = NULL ;
V_143 -> V_127 . V_151 = V_151 ;
if ( ! V_143 -> V_127 . V_151 )
V_143 -> V_127 . V_151 = V_191 ;
V_143 -> V_127 . V_156 = V_156 ;
if ( ! V_143 -> V_127 . V_156 )
V_143 -> V_127 . V_156 = V_191 ;
V_143 -> V_127 . V_153 = V_153 ;
V_143 -> V_49 = V_49 ;
if ( V_143 -> V_49 )
V_143 -> V_133 = F_69 ;
V_143 -> V_192 = V_181 ;
V_15 = F_117 ( V_143 ) ;
if ( V_15 ) {
F_118 ( V_143 ) ;
goto V_31;
}
V_15 = F_119 ( V_143 ) ;
if ( V_15 ) {
F_120 ( V_143 ) ;
goto V_31;
}
} else {
struct V_4 * V_193 , * V_194 ;
F_121 ( & V_195 ) ;
F_122 (e, tmp_e, &smi_infos, link) {
if ( V_193 -> V_127 . V_188 != V_180 )
continue;
if ( V_193 -> V_136 != V_136 )
continue;
if ( V_193 -> V_127 . V_150 == V_149 )
F_120 ( V_193 ) ;
}
F_123 ( & V_195 ) ;
}
}
V_15 = V_68 ;
V_31:
F_118 ( V_176 ) ;
return V_15 ;
}
static int F_124 ( void )
{
int V_196 = - V_157 ;
int V_169 ;
struct V_4 * V_143 ;
for ( V_169 = 0 ; V_169 < V_197 ; V_169 ++ ) {
if ( ! V_198 [ V_169 ] && ! V_199 [ V_169 ] )
continue;
V_143 = F_112 () ;
if ( ! V_143 )
return - V_183 ;
V_143 -> V_141 = V_200 ;
F_12 (KERN_INFO PFX L_36 ) ;
if ( ! V_136 [ V_169 ] || strcmp ( V_136 [ V_169 ] , L_37 ) == 0 ) {
V_143 -> V_136 = V_201 ;
} else if ( strcmp ( V_136 [ V_169 ] , L_38 ) == 0 ) {
V_143 -> V_136 = V_202 ;
} else if ( strcmp ( V_136 [ V_169 ] , L_39 ) == 0 ) {
V_143 -> V_136 = V_137 ;
} else {
F_12 (KERN_WARNING PFX L_40
L_41 ,
i, si_type[i]) ;
F_118 ( V_143 ) ;
continue;
}
if ( V_198 [ V_169 ] ) {
V_143 -> V_190 = F_86 ;
V_143 -> V_127 . V_150 = V_198 [ V_169 ] ;
V_143 -> V_127 . V_188 = V_203 ;
} else if ( V_199 [ V_169 ] ) {
V_143 -> V_190 = F_106 ;
V_143 -> V_127 . V_150 = V_199 [ V_169 ] ;
V_143 -> V_127 . V_188 = V_189 ;
} else {
F_12 (KERN_WARNING PFX L_40
L_42
L_43 , i) ;
F_118 ( V_143 ) ;
continue;
}
V_143 -> V_127 . V_149 = NULL ;
V_143 -> V_127 . V_151 = V_204 [ V_169 ] ;
if ( ! V_143 -> V_127 . V_151 )
V_143 -> V_127 . V_151 = V_191 ;
V_143 -> V_127 . V_156 = V_205 [ V_169 ] ;
if ( ! V_143 -> V_127 . V_156 )
V_143 -> V_127 . V_156 = V_191 ;
V_143 -> V_127 . V_153 = V_206 [ V_169 ] ;
V_143 -> V_49 = V_207 [ V_169 ] ;
if ( V_143 -> V_49 )
V_143 -> V_133 = F_69 ;
V_143 -> V_192 = V_208 [ V_169 ] ;
if ( ! F_117 ( V_143 ) ) {
if ( F_119 ( V_143 ) )
F_120 ( V_143 ) ;
V_196 = 0 ;
} else {
F_118 ( V_143 ) ;
}
}
return V_196 ;
}
static T_3 F_125 ( T_4 V_209 ,
T_3 V_210 , void * V_211 )
{
struct V_4 * V_4 = V_211 ;
unsigned long V_94 ;
#ifdef F_7
struct V_18 V_19 ;
#endif
F_36 ( & ( V_4 -> V_97 ) , V_94 ) ;
F_23 ( V_4 , V_125 ) ;
#ifdef F_7
F_11 ( & V_19 ) ;
F_12 ( L_44 , V_19 . V_27 , V_19 . V_28 ) ;
#endif
F_28 ( V_4 , 0 ) ;
F_37 ( & ( V_4 -> V_97 ) , V_94 ) ;
return V_212 ;
}
static void F_126 ( struct V_4 * V_143 )
{
if ( ! V_143 -> V_49 )
return;
F_127 ( NULL , V_143 -> V_49 , & F_125 ) ;
}
static int F_128 ( struct V_4 * V_143 )
{
T_5 V_213 ;
if ( ! V_143 -> V_49 )
return 0 ;
V_213 = F_129 ( NULL ,
V_143 -> V_49 ,
V_214 ,
& F_125 ,
V_143 ) ;
if ( V_213 != V_215 ) {
F_27 ( V_143 -> V_70 , L_45
L_18 , V_145 , V_143 -> V_49 ) ;
V_143 -> V_49 = 0 ;
return - V_160 ;
} else {
V_143 -> V_146 = F_126 ;
F_71 ( V_143 -> V_70 , L_46 , V_143 -> V_49 ) ;
return 0 ;
}
}
static int F_130 ( struct V_216 * V_217 )
{
struct V_4 * V_143 ;
int V_15 ;
if ( V_217 -> V_218 != 1 ) {
F_12 (KERN_INFO PFX L_47 , spmi->IPMIlegacy) ;
return - V_157 ;
}
V_143 = F_112 () ;
if ( ! V_143 ) {
F_12 (KERN_ERR PFX L_48 ) ;
return - V_183 ;
}
V_143 -> V_141 = V_219 ;
F_12 (KERN_INFO PFX L_49 ) ;
switch ( V_217 -> V_220 ) {
case 1 :
V_143 -> V_136 = V_201 ;
break;
case 2 :
V_143 -> V_136 = V_202 ;
break;
case 3 :
V_143 -> V_136 = V_137 ;
break;
default:
F_12 (KERN_INFO PFX L_50 ,
spmi->InterfaceType) ;
F_118 ( V_143 ) ;
return - V_161 ;
}
if ( V_217 -> V_221 & 1 ) {
V_143 -> V_49 = V_217 -> V_222 ;
V_143 -> V_133 = F_128 ;
} else if ( V_217 -> V_221 & 2 ) {
V_143 -> V_49 = V_217 -> V_223 ;
V_143 -> V_133 = F_69 ;
} else {
V_143 -> V_49 = 0 ;
V_143 -> V_133 = NULL ;
}
if ( V_217 -> V_149 . V_224 ) {
V_143 -> V_127 . V_151 = V_217 -> V_149 . V_224 / 8 ;
} else {
V_143 -> V_127 . V_151 = V_191 ;
}
V_143 -> V_127 . V_156 = V_143 -> V_127 . V_151 ;
V_143 -> V_127 . V_153 = V_217 -> V_149 . V_225 ;
if ( V_217 -> V_149 . V_226 == V_227 ) {
V_143 -> V_190 = F_106 ;
V_143 -> V_127 . V_188 = V_189 ;
} else if ( V_217 -> V_149 . V_226 == V_228 ) {
V_143 -> V_190 = F_86 ;
V_143 -> V_127 . V_188 = V_203 ;
} else {
F_118 ( V_143 ) ;
F_12 (KERN_WARNING PFX L_51 ) ;
return - V_161 ;
}
V_143 -> V_127 . V_150 = V_217 -> V_149 . V_229 ;
F_131 ( L_52 ,
( V_143 -> V_127 . V_188 == V_203 ) ? L_53 : L_54 ,
V_143 -> V_127 . V_150 , V_143 -> V_127 . V_156 , V_143 -> V_127 . V_151 ,
V_143 -> V_49 ) ;
V_15 = F_117 ( V_143 ) ;
if ( V_15 )
F_118 ( V_143 ) ;
return V_15 ;
}
static void F_132 ( void )
{
T_5 V_213 ;
struct V_216 * V_217 ;
int V_169 ;
if ( V_230 )
return;
if ( V_231 )
return;
for ( V_169 = 0 ; ; V_169 ++ ) {
V_213 = F_133 ( V_232 , V_169 + 1 ,
(struct V_233 * * ) & V_217 ) ;
if ( V_213 != V_215 )
return;
F_130 ( V_217 ) ;
}
}
static int F_134 ( struct V_234 * V_70 ,
const struct V_235 * V_236 )
{
struct V_237 * V_238 ;
struct V_4 * V_143 ;
struct V_239 * V_240 , * V_241 ;
T_4 V_242 ;
T_5 V_213 ;
unsigned long long V_243 ;
int V_15 ;
V_238 = F_135 ( V_70 ) ;
if ( ! V_238 )
return - V_157 ;
V_143 = F_112 () ;
if ( ! V_143 )
return - V_183 ;
V_143 -> V_141 = V_244 ;
F_12 (KERN_INFO PFX L_55 ) ;
V_242 = V_238 -> V_242 ;
V_143 -> V_142 . V_245 . T_4 = V_242 ;
V_213 = F_136 ( V_242 , L_56 , NULL , & V_243 ) ;
if ( F_137 ( V_213 ) )
goto V_246;
switch ( V_243 ) {
case 1 :
V_143 -> V_136 = V_201 ;
break;
case 2 :
V_143 -> V_136 = V_202 ;
break;
case 3 :
V_143 -> V_136 = V_137 ;
break;
default:
F_71 ( & V_70 -> V_70 , L_57 , V_243 ) ;
goto V_246;
}
V_240 = F_138 ( V_70 , V_247 , 0 ) ;
if ( V_240 ) {
V_143 -> V_190 = F_86 ;
V_143 -> V_127 . V_188 = V_203 ;
} else {
V_240 = F_138 ( V_70 , V_248 , 0 ) ;
if ( V_240 ) {
V_143 -> V_190 = F_106 ;
V_143 -> V_127 . V_188 = V_189 ;
}
}
if ( ! V_240 ) {
F_139 ( & V_70 -> V_70 , L_58 ) ;
goto V_246;
}
V_143 -> V_127 . V_150 = V_240 -> V_249 ;
V_143 -> V_127 . V_151 = V_191 ;
V_241 = F_138 ( V_70 ,
( V_143 -> V_127 . V_188 == V_203 ) ?
V_247 : V_248 ,
1 ) ;
if ( V_241 ) {
if ( V_241 -> V_249 > V_143 -> V_127 . V_150 )
V_143 -> V_127 . V_151 = V_241 -> V_249 - V_143 -> V_127 . V_150 ;
}
V_143 -> V_127 . V_156 = V_191 ;
V_143 -> V_127 . V_153 = 0 ;
V_213 = F_136 ( V_242 , L_59 , NULL , & V_243 ) ;
if ( F_140 ( V_213 ) ) {
V_143 -> V_49 = V_243 ;
V_143 -> V_133 = F_128 ;
} else if ( F_141 ( V_70 , 0 ) ) {
V_143 -> V_49 = F_142 ( V_70 , 0 ) ;
V_143 -> V_133 = F_69 ;
}
V_143 -> V_70 = & V_70 -> V_70 ;
F_143 ( V_70 , V_143 ) ;
F_71 ( V_143 -> V_70 , L_60 ,
V_240 , V_143 -> V_127 . V_156 , V_143 -> V_127 . V_151 ,
V_143 -> V_49 ) ;
V_15 = F_117 ( V_143 ) ;
if ( V_15 )
F_118 ( V_143 ) ;
return V_15 ;
V_246:
F_118 ( V_143 ) ;
return - V_160 ;
}
static void F_144 ( struct V_234 * V_70 )
{
struct V_4 * V_143 = F_145 ( V_70 ) ;
F_120 ( V_143 ) ;
}
static int F_146 ( const struct V_250 * V_251 ,
struct V_252 * V_253 )
{
const T_6 * V_12 = ( const T_6 * ) V_251 ;
unsigned long V_254 ;
T_6 V_255 ;
T_6 V_68 = V_251 -> V_256 ;
V_253 -> type = V_12 [ 4 ] ;
memcpy ( & V_254 , V_12 + 8 , sizeof( unsigned long ) ) ;
if ( V_68 >= 0x11 ) {
if ( V_254 & 1 ) {
V_254 &= 0xFFFE ;
V_253 -> V_180 = V_203 ;
} else
V_253 -> V_180 = V_189 ;
V_253 -> V_254 = V_254 | ( ( V_12 [ 0x10 ] & 0x10 ) >> 4 ) ;
V_253 -> V_49 = V_12 [ 0x11 ] ;
V_255 = ( V_12 [ 0x10 ] & 0xC0 ) >> 6 ;
switch ( V_255 ) {
case 0x00 :
V_253 -> V_148 = 1 ;
break;
case 0x01 :
V_253 -> V_148 = 4 ;
break;
case 0x02 :
V_253 -> V_148 = 16 ;
break;
default:
return - V_161 ;
}
} else {
V_253 -> V_254 = V_254 & 0xfffe ;
V_253 -> V_180 = V_203 ;
V_253 -> V_148 = 1 ;
}
V_253 -> V_192 = V_12 [ 6 ] ;
return 0 ;
}
static void F_147 ( struct V_252 * V_257 )
{
struct V_4 * V_143 ;
V_143 = F_112 () ;
if ( ! V_143 ) {
F_12 (KERN_ERR PFX L_61 ) ;
return;
}
V_143 -> V_141 = V_258 ;
F_12 (KERN_INFO PFX L_62 ) ;
switch ( V_257 -> type ) {
case 0x01 :
V_143 -> V_136 = V_201 ;
break;
case 0x02 :
V_143 -> V_136 = V_202 ;
break;
case 0x03 :
V_143 -> V_136 = V_137 ;
break;
default:
F_118 ( V_143 ) ;
return;
}
switch ( V_257 -> V_180 ) {
case V_189 :
V_143 -> V_190 = F_106 ;
V_143 -> V_127 . V_188 = V_189 ;
break;
case V_203 :
V_143 -> V_190 = F_86 ;
V_143 -> V_127 . V_188 = V_203 ;
break;
default:
F_118 ( V_143 ) ;
F_12 (KERN_WARNING PFX L_63 ,
ipmi_data->addr_space) ;
return;
}
V_143 -> V_127 . V_150 = V_257 -> V_254 ;
V_143 -> V_127 . V_151 = V_257 -> V_148 ;
if ( ! V_143 -> V_127 . V_151 )
V_143 -> V_127 . V_151 = V_191 ;
V_143 -> V_127 . V_156 = V_191 ;
V_143 -> V_127 . V_153 = 0 ;
V_143 -> V_192 = V_257 -> V_192 ;
V_143 -> V_49 = V_257 -> V_49 ;
if ( V_143 -> V_49 )
V_143 -> V_133 = F_69 ;
F_131 ( L_64 ,
( V_143 -> V_127 . V_188 == V_203 ) ? L_53 : L_54 ,
V_143 -> V_127 . V_150 , V_143 -> V_127 . V_156 , V_143 -> V_127 . V_151 ,
V_143 -> V_49 ) ;
if ( F_117 ( V_143 ) )
F_118 ( V_143 ) ;
}
static void F_148 ( void )
{
const struct V_259 * V_70 = NULL ;
struct V_252 V_12 ;
int V_15 ;
while ( ( V_70 = F_149 ( V_260 , NULL , V_70 ) ) ) {
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_15 = F_146 ( ( const struct V_250 * ) V_70 -> V_261 ,
& V_12 ) ;
if ( ! V_15 )
F_147 ( & V_12 ) ;
}
}
static void F_150 ( struct V_4 * V_143 )
{
struct V_262 * V_263 = V_143 -> V_264 ;
F_151 ( V_263 ) ;
}
static int F_152 ( struct V_4 * V_143 )
{
if ( V_143 -> V_136 == V_201 ) {
unsigned char V_213 ;
int V_151 ;
V_143 -> V_127 . V_156 = V_265 ;
V_143 -> V_127 . V_153 = 0 ;
V_143 -> V_155 = 2 ;
V_143 -> V_32 = & V_266 ;
for ( V_151 = V_191 ; V_151 <= 16 ; ) {
V_143 -> V_127 . V_151 = V_151 ;
if ( V_143 -> V_190 ( V_143 ) ) {
F_139 ( V_143 -> V_70 ,
L_65 ) ;
return V_191 ;
}
V_143 -> V_127 . V_128 ( & V_143 -> V_127 , 1 , 0x10 ) ;
V_213 = V_143 -> V_127 . V_159 ( & V_143 -> V_127 , 1 ) ;
V_143 -> V_158 ( V_143 ) ;
if ( V_213 )
return V_151 ;
V_151 *= 4 ;
}
}
return V_191 ;
}
static int F_153 ( struct V_262 * V_263 ,
const struct V_267 * V_268 )
{
int V_15 ;
int V_269 = V_263 -> V_270 & V_271 ;
struct V_4 * V_143 ;
V_143 = F_112 () ;
if ( ! V_143 )
return - V_183 ;
V_143 -> V_141 = V_272 ;
F_71 ( & V_263 -> V_70 , L_66 ) ;
switch ( V_269 ) {
case V_273 :
V_143 -> V_136 = V_202 ;
break;
case V_274 :
V_143 -> V_136 = V_201 ;
break;
case V_275 :
V_143 -> V_136 = V_137 ;
break;
default:
F_118 ( V_143 ) ;
F_71 ( & V_263 -> V_70 , L_67 , V_269 ) ;
return - V_183 ;
}
V_15 = F_154 ( V_263 ) ;
if ( V_15 ) {
F_139 ( & V_263 -> V_70 , L_68 ) ;
F_118 ( V_143 ) ;
return V_15 ;
}
V_143 -> V_276 = F_150 ;
V_143 -> V_264 = V_263 ;
if ( F_155 ( V_263 , 0 ) & V_247 ) {
V_143 -> V_190 = F_86 ;
V_143 -> V_127 . V_188 = V_203 ;
} else {
V_143 -> V_190 = F_106 ;
V_143 -> V_127 . V_188 = V_189 ;
}
V_143 -> V_127 . V_150 = F_156 ( V_263 , 0 ) ;
V_143 -> V_127 . V_151 = F_152 ( V_143 ) ;
V_143 -> V_127 . V_156 = V_265 ;
V_143 -> V_127 . V_153 = 0 ;
V_143 -> V_49 = V_263 -> V_49 ;
if ( V_143 -> V_49 )
V_143 -> V_133 = F_69 ;
V_143 -> V_70 = & V_263 -> V_70 ;
F_157 ( V_263 , V_143 ) ;
F_71 ( & V_263 -> V_70 , L_60 ,
& V_263 -> V_239 [ 0 ] , V_143 -> V_127 . V_156 , V_143 -> V_127 . V_151 ,
V_143 -> V_49 ) ;
V_15 = F_117 ( V_143 ) ;
if ( V_15 ) {
F_118 ( V_143 ) ;
F_151 ( V_263 ) ;
}
return V_15 ;
}
static void F_158 ( struct V_262 * V_263 )
{
struct V_4 * V_143 = F_159 ( V_263 ) ;
F_120 ( V_143 ) ;
F_151 ( V_263 ) ;
}
static int F_160 ( struct V_277 * V_70 )
{
#ifdef F_161
const struct V_278 * V_279 ;
struct V_4 * V_143 ;
struct V_239 V_239 ;
const T_7 * V_156 , * V_151 , * V_153 ;
struct V_280 * V_281 = V_70 -> V_70 . V_282 ;
int V_196 ;
int V_283 ;
F_71 ( & V_70 -> V_70 , L_69 ) ;
V_279 = F_162 ( V_284 , & V_70 -> V_70 ) ;
if ( ! V_279 )
return - V_160 ;
V_196 = F_163 ( V_281 , 0 , & V_239 ) ;
if ( V_196 ) {
F_27 ( & V_70 -> V_70 , V_285 L_70 ) ;
return V_196 ;
}
V_156 = F_164 ( V_281 , L_71 , & V_283 ) ;
if ( V_156 && V_283 != 4 ) {
F_27 ( & V_70 -> V_70 , V_285 L_72 ) ;
return - V_160 ;
}
V_151 = F_164 ( V_281 , L_73 , & V_283 ) ;
if ( V_151 && V_283 != 4 ) {
F_27 ( & V_70 -> V_70 , V_285 L_74 ) ;
return - V_160 ;
}
V_153 = F_164 ( V_281 , L_75 , & V_283 ) ;
if ( V_153 && V_283 != 4 ) {
F_27 ( & V_70 -> V_70 , V_285 L_76 ) ;
return - V_160 ;
}
V_143 = F_112 () ;
if ( ! V_143 ) {
F_139 ( & V_70 -> V_70 ,
L_77 ) ;
return - V_183 ;
}
V_143 -> V_136 = (enum V_136 ) V_279 -> V_12 ;
V_143 -> V_141 = V_286 ;
V_143 -> V_133 = F_69 ;
if ( V_239 . V_94 & V_247 ) {
V_143 -> V_190 = F_86 ;
V_143 -> V_127 . V_188 = V_203 ;
} else {
V_143 -> V_190 = F_106 ;
V_143 -> V_127 . V_188 = V_189 ;
}
V_143 -> V_127 . V_150 = V_239 . V_249 ;
V_143 -> V_127 . V_156 = V_156 ? F_165 ( V_156 ) : V_265 ;
V_143 -> V_127 . V_151 = V_151 ? F_165 ( V_151 ) : V_191 ;
V_143 -> V_127 . V_153 = V_153 ? F_165 ( V_153 ) : 0 ;
V_143 -> V_49 = F_166 ( V_70 -> V_70 . V_282 , 0 ) ;
V_143 -> V_70 = & V_70 -> V_70 ;
F_167 ( & V_70 -> V_70 , L_78 ,
V_143 -> V_127 . V_150 , V_143 -> V_127 . V_156 , V_143 -> V_127 . V_151 ,
V_143 -> V_49 ) ;
F_168 ( & V_70 -> V_70 , V_143 ) ;
V_196 = F_117 ( V_143 ) ;
if ( V_196 ) {
F_118 ( V_143 ) ;
return V_196 ;
}
#endif
return 0 ;
}
static int F_169 ( struct V_277 * V_70 )
{
#ifdef F_161
F_120 ( F_170 ( & V_70 -> V_70 ) ) ;
#endif
return 0 ;
}
static int F_171 ( struct V_287 * V_70 )
{
struct V_4 * V_143 ;
int V_15 ;
V_143 = F_112 () ;
if ( ! V_143 ) {
F_139 ( & V_70 -> V_70 ,
L_79 ) ;
return - V_183 ;
}
V_143 -> V_136 = V_201 ;
V_143 -> V_141 = V_286 ;
V_143 -> V_190 = F_106 ;
V_143 -> V_127 . V_188 = V_189 ;
V_143 -> V_127 . V_150 = V_70 -> V_288 . V_249 ;
V_143 -> V_127 . V_156 = 1 ;
V_143 -> V_127 . V_151 = 1 ;
V_143 -> V_127 . V_153 = 0 ;
V_143 -> V_49 = 0 ;
V_143 -> V_133 = NULL ;
V_143 -> V_70 = & V_70 -> V_70 ;
F_167 ( & V_70 -> V_70 , L_80 , V_143 -> V_127 . V_150 ) ;
F_168 ( & V_70 -> V_70 , V_143 ) ;
V_15 = F_117 ( V_143 ) ;
if ( V_15 ) {
F_118 ( V_143 ) ;
return V_15 ;
}
return 0 ;
}
static int F_172 ( struct V_287 * V_70 )
{
F_120 ( F_170 ( & V_70 -> V_70 ) ) ;
return 0 ;
}
static int F_173 ( struct V_4 * V_4 )
{
enum V_14 V_102 ;
V_102 = V_4 -> V_32 -> V_80 ( V_4 -> V_34 , 0 ) ;
for (; ; ) {
if ( V_102 == V_108 ||
V_102 == V_289 ) {
F_174 ( 1 ) ;
V_102 = V_4 -> V_32 -> V_80 (
V_4 -> V_34 , F_175 ( 1 ) ) ;
} else if ( V_102 == V_30 ) {
V_102 = V_4 -> V_32 -> V_80 (
V_4 -> V_34 , 0 ) ;
} else
break;
}
if ( V_102 == V_83 )
return - V_157 ;
return 0 ;
}
static int F_176 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 2 ] ;
unsigned char * V_290 ;
unsigned long V_291 ;
int V_15 = 0 ;
V_290 = F_177 ( V_66 , V_173 ) ;
if ( ! V_290 )
return - V_183 ;
V_6 [ 0 ] = V_36 << 2 ;
V_6 [ 1 ] = V_292 ;
V_4 -> V_32 -> V_33 ( V_4 -> V_34 , V_6 , 2 ) ;
V_15 = F_173 ( V_4 ) ;
if ( V_15 )
goto V_31;
V_291 = V_4 -> V_32 -> V_65 ( V_4 -> V_34 ,
V_290 , V_66 ) ;
V_15 = F_178 ( V_290 , V_291 , & V_4 -> V_293 ) ;
V_31:
F_118 ( V_290 ) ;
return V_15 ;
}
static int F_179 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 3 ] ;
unsigned char * V_290 ;
unsigned long V_291 ;
int V_15 = 0 ;
V_290 = F_177 ( V_66 , V_173 ) ;
if ( ! V_290 )
return - V_183 ;
V_6 [ 0 ] = V_36 << 2 ;
V_6 [ 1 ] = V_37 ;
V_4 -> V_32 -> V_33 ( V_4 -> V_34 , V_6 , 2 ) ;
V_15 = F_173 ( V_4 ) ;
if ( V_15 ) {
F_12 (KERN_WARNING PFX L_81
L_82
L_83 ) ;
goto V_31;
}
V_291 = V_4 -> V_32 -> V_65 ( V_4 -> V_34 ,
V_290 , V_66 ) ;
if ( V_291 < 4 ||
V_290 [ 0 ] != ( V_36 | 1 ) << 2 ||
V_290 [ 1 ] != V_37 ||
V_290 [ 2 ] != 0 ) {
F_12 (KERN_WARNING PFX L_84
L_85 ) ;
V_15 = - V_160 ;
goto V_31;
}
if ( V_290 [ 3 ] & V_294 )
goto V_31;
V_6 [ 0 ] = V_36 << 2 ;
V_6 [ 1 ] = V_74 ;
V_6 [ 2 ] = V_290 [ 3 ] | V_294 ;
V_4 -> V_32 -> V_33 ( V_4 -> V_34 , V_6 , 3 ) ;
V_15 = F_173 ( V_4 ) ;
if ( V_15 ) {
F_12 (KERN_WARNING PFX L_86
L_87
L_83 ) ;
goto V_31;
}
V_291 = V_4 -> V_32 -> V_65 ( V_4 -> V_34 ,
V_290 , V_66 ) ;
if ( V_291 < 3 ||
V_290 [ 0 ] != ( V_36 | 1 ) << 2 ||
V_290 [ 1 ] != V_74 ) {
F_12 (KERN_WARNING PFX L_88
L_89 ) ;
V_15 = - V_160 ;
goto V_31;
}
if ( V_290 [ 2 ] != 0 )
V_15 = - V_295 ;
V_31:
F_118 ( V_290 ) ;
return V_15 ;
}
static int F_180 ( struct V_296 * V_297 , void * V_164 )
{
struct V_4 * V_139 = V_297 -> V_298 ;
return F_181 ( V_297 , L_90 , V_299 [ V_139 -> V_136 ] ) ;
}
static int F_182 ( struct V_300 * V_300 , struct V_301 * V_301 )
{
return F_183 ( V_301 , F_180 , F_184 ( V_300 ) ) ;
}
static int F_185 ( struct V_296 * V_297 , void * V_164 )
{
struct V_4 * V_139 = V_297 -> V_298 ;
F_181 ( V_297 , L_91 ,
V_139 -> V_49 && ! V_139 -> V_50 ) ;
F_181 ( V_297 , L_92 ,
F_186 ( V_139 , V_124 ) ) ;
F_181 ( V_297 , L_93 ,
F_186 ( V_139 , V_122 ) ) ;
F_181 ( V_297 , L_94 ,
F_186 ( V_139 , V_88 ) ) ;
F_181 ( V_297 , L_95 ,
F_186 ( V_139 , V_125 ) ) ;
F_181 ( V_297 , L_96 ,
F_186 ( V_139 , V_86 ) ) ;
F_181 ( V_297 , L_97 ,
F_186 ( V_139 , V_302 ) ) ;
F_181 ( V_297 , L_98 ,
F_186 ( V_139 , V_84 ) ) ;
F_181 ( V_297 , L_99 ,
F_186 ( V_139 , V_82 ) ) ;
F_181 ( V_297 , L_100 ,
F_186 ( V_139 , V_72 ) ) ;
F_181 ( V_297 , L_101 ,
F_186 ( V_139 , V_55 ) ) ;
F_181 ( V_297 , L_102 ,
F_186 ( V_139 , V_73 ) ) ;
return 0 ;
}
static int F_187 ( struct V_300 * V_300 , struct V_301 * V_301 )
{
return F_183 ( V_301 , F_185 , F_184 ( V_300 ) ) ;
}
static int F_188 ( struct V_296 * V_297 , void * V_164 )
{
struct V_4 * V_139 = V_297 -> V_298 ;
return F_181 ( V_297 ,
L_103 ,
V_299 [ V_139 -> V_136 ] ,
V_303 [ V_139 -> V_127 . V_188 ] ,
V_139 -> V_127 . V_150 ,
V_139 -> V_127 . V_151 ,
V_139 -> V_127 . V_156 ,
V_139 -> V_127 . V_153 ,
V_139 -> V_49 ,
V_139 -> V_192 ) ;
}
static int F_189 ( struct V_300 * V_300 , struct V_301 * V_301 )
{
return F_183 ( V_301 , F_188 , F_184 ( V_300 ) ) ;
}
static int F_190 ( struct V_4 * V_4 )
{
V_4 -> V_54 = ( ( V_4 -> V_54 & ~ V_63 ) |
V_56 ) ;
return 1 ;
}
static void F_191 ( struct V_4 * V_4 )
{
struct V_304 * V_305 = & V_4 -> V_293 ;
if ( V_305 -> V_306 == V_307 ) {
if ( V_305 -> V_293 == V_308 &&
V_305 -> V_309 == V_310 &&
V_305 -> V_311 == V_312 ) {
V_4 -> V_64 =
F_190 ;
} else if ( F_192 ( V_305 ) < 1 ||
( F_192 ( V_305 ) == 1 &&
F_193 ( V_305 ) < 5 ) ) {
V_4 -> V_64 =
F_190 ;
}
}
}
static void F_194 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_9 ;
V_6 -> V_11 [ 0 ] = V_6 -> V_12 [ 0 ] | 4 ;
V_6 -> V_11 [ 1 ] = V_6 -> V_12 [ 1 ] ;
V_6 -> V_11 [ 2 ] = V_313 ;
V_6 -> V_13 = 3 ;
V_4 -> V_9 = NULL ;
F_3 ( V_4 , V_6 ) ;
}
static int F_195 ( struct V_1 * V_314 ,
unsigned long V_315 ,
void * V_316 )
{
struct V_4 * V_4 = V_316 ;
unsigned char * V_12 = V_4 -> V_9 -> V_12 ;
unsigned int V_317 = V_4 -> V_9 -> V_35 ;
if ( V_317 >= 8 &&
( V_12 [ 0 ] >> 2 ) == V_318 &&
V_12 [ 1 ] == V_319 &&
V_12 [ 7 ] == 0x3A ) {
F_194 ( V_4 ) ;
return V_320 ;
}
return V_321 ;
}
static void
F_196 ( struct V_4 * V_4 )
{
struct V_304 * V_305 = & V_4 -> V_293 ;
if ( V_305 -> V_306 == V_307 &&
V_4 -> V_136 == V_137 )
F_1 ( & V_322 ) ;
}
static void F_197 ( struct V_4 * V_4 )
{
F_191 ( V_4 ) ;
}
static void F_198 ( struct V_4 * V_4 )
{
F_196 ( V_4 ) ;
}
static inline void F_199 ( struct V_4 * V_4 )
{
if ( V_4 -> V_7 ) {
if ( V_4 -> V_90 != NULL )
F_200 ( V_4 -> V_90 ) ;
F_201 ( & V_4 -> V_47 ) ;
}
}
static void F_202 ( void )
{
struct V_4 * V_143 ;
int V_169 ;
for ( V_169 = 0 ; ; V_169 ++ ) {
if ( ! V_323 [ V_169 ] . V_324 )
break;
#ifdef F_203
if ( F_204 ( V_323 [ V_169 ] . V_324 ) )
continue;
#endif
V_143 = F_112 () ;
if ( ! V_143 )
return;
V_143 -> V_141 = V_325 ;
V_143 -> V_136 = V_323 [ V_169 ] . type ;
V_143 -> V_190 = F_86 ;
V_143 -> V_127 . V_150 = V_323 [ V_169 ] . V_324 ;
V_143 -> V_127 . V_188 = V_203 ;
V_143 -> V_127 . V_149 = NULL ;
V_143 -> V_127 . V_151 = V_191 ;
V_143 -> V_127 . V_156 = V_191 ;
V_143 -> V_127 . V_153 = 0 ;
if ( F_117 ( V_143 ) == 0 ) {
if ( ( F_119 ( V_143 ) ) == 0 ) {
F_12 (KERN_INFO PFX L_104
L_105 ,
si_to_str[info->si_type],
addr_space_to_str[info->io.addr_type],
info->io.addr_data) ;
} else
F_120 ( V_143 ) ;
} else {
F_118 ( V_143 ) ;
}
}
}
static int F_205 ( struct V_4 * V_143 )
{
struct V_4 * V_193 ;
F_206 (e, &smi_infos, link) {
if ( V_193 -> V_127 . V_188 != V_143 -> V_127 . V_188 )
continue;
if ( V_193 -> V_127 . V_150 == V_143 -> V_127 . V_150 )
return 0 ;
}
return 1 ;
}
static int F_117 ( struct V_4 * V_132 )
{
int V_15 = 0 ;
F_12 (KERN_INFO PFX L_106 ,
ipmi_addr_src_to_str[new_smi->addr_source],
si_to_str[new_smi->si_type]) ;
F_121 ( & V_195 ) ;
if ( ! F_205 ( V_132 ) ) {
F_12 ( V_326 L_107 ) ;
V_15 = - V_327 ;
goto V_328;
}
F_12 ( V_326 L_108 ) ;
V_132 -> V_7 = NULL ;
V_132 -> V_34 = NULL ;
V_132 -> V_32 = NULL ;
F_34 ( & V_132 -> V_25 , & V_329 ) ;
V_328:
F_123 ( & V_195 ) ;
return V_15 ;
}
static int F_119 ( struct V_4 * V_132 )
{
int V_15 = 0 ;
int V_169 ;
F_12 (KERN_INFO PFX L_109
L_110
L_111 ,
ipmi_addr_src_to_str[new_smi->addr_source],
si_to_str[new_smi->si_type],
addr_space_to_str[new_smi->io.addr_type],
new_smi->io.addr_data,
new_smi->slave_addr, new_smi->irq) ;
switch ( V_132 -> V_136 ) {
case V_201 :
V_132 -> V_32 = & V_266 ;
break;
case V_202 :
V_132 -> V_32 = & V_330 ;
break;
case V_137 :
V_132 -> V_32 = & V_331 ;
break;
default:
V_15 = - V_161 ;
goto V_328;
}
V_132 -> V_34 = F_177 ( V_132 -> V_32 -> V_317 () , V_173 ) ;
if ( ! V_132 -> V_34 ) {
F_12 (KERN_ERR PFX
L_112 ) ;
V_15 = - V_183 ;
goto V_328;
}
V_132 -> V_155 = V_132 -> V_32 -> V_332 ( V_132 -> V_34 ,
& V_132 -> V_127 ) ;
V_15 = V_132 -> V_190 ( V_132 ) ;
if ( V_15 ) {
F_12 (KERN_ERR PFX L_113 ) ;
goto V_328;
}
if ( V_132 -> V_32 -> V_333 ( V_132 -> V_34 ) ) {
if ( V_132 -> V_141 )
F_12 (KERN_INFO PFX L_114 ) ;
V_15 = - V_157 ;
goto V_328;
}
V_15 = F_176 ( V_132 ) ;
if ( V_15 ) {
if ( V_132 -> V_141 )
F_12 (KERN_INFO PFX L_115
L_116 ) ;
goto V_328;
}
F_197 ( V_132 ) ;
F_198 ( V_132 ) ;
F_207 ( & ( V_132 -> V_22 ) ) ;
F_207 ( & ( V_132 -> V_20 ) ) ;
V_132 -> V_9 = NULL ;
F_30 ( & V_132 -> V_89 , 0 ) ;
V_132 -> V_95 = false ;
for ( V_169 = 0 ; V_169 < V_334 ; V_169 ++ )
F_30 ( & V_132 -> V_335 [ V_169 ] , 0 ) ;
V_132 -> V_50 = true ;
F_30 ( & V_132 -> V_51 , 0 ) ;
F_30 ( & V_132 -> V_114 , 0 ) ;
V_132 -> V_105 = V_336 ;
V_336 ++ ;
V_15 = F_179 ( V_132 ) ;
if ( V_15 == 0 )
V_132 -> V_116 = true ;
F_16 ( V_132 ) ;
if ( V_132 -> V_49 )
V_132 -> V_38 = V_69 ;
if ( ! V_132 -> V_70 ) {
V_132 -> V_263 = F_208 ( L_117 ,
V_132 -> V_105 ) ;
if ( ! V_132 -> V_263 ) {
F_12 (KERN_ERR PFX
L_118 ) ;
goto V_328;
}
V_132 -> V_70 = & V_132 -> V_263 -> V_70 ;
V_132 -> V_70 -> V_337 = & V_338 . V_337 ;
V_15 = F_209 ( V_132 -> V_263 ) ;
if ( V_15 ) {
F_12 (KERN_ERR PFX
L_119
L_120 ,
rv) ;
goto V_328;
}
V_132 -> V_339 = true ;
}
V_15 = F_210 ( & V_32 ,
V_132 ,
& V_132 -> V_293 ,
V_132 -> V_70 ,
L_121 ,
V_132 -> V_192 ) ;
if ( V_15 ) {
F_139 ( V_132 -> V_70 , L_122 ,
V_15 ) ;
goto V_340;
}
V_15 = F_211 ( V_132 -> V_7 , L_123 ,
& V_341 ,
V_132 ) ;
if ( V_15 ) {
F_139 ( V_132 -> V_70 , L_124 , V_15 ) ;
goto V_340;
}
V_15 = F_211 ( V_132 -> V_7 , L_125 ,
& V_342 ,
V_132 ) ;
if ( V_15 ) {
F_139 ( V_132 -> V_70 , L_124 , V_15 ) ;
goto V_340;
}
V_15 = F_211 ( V_132 -> V_7 , L_126 ,
& V_343 ,
V_132 ) ;
if ( V_15 ) {
F_139 ( V_132 -> V_70 , L_124 , V_15 ) ;
goto V_340;
}
F_71 ( V_132 -> V_70 , L_127 ,
V_299 [ V_132 -> V_136 ] ) ;
return 0 ;
V_340:
F_212 ( & V_132 -> V_51 ) ;
F_199 ( V_132 ) ;
V_328:
V_132 -> V_50 = true ;
if ( V_132 -> V_7 ) {
F_213 ( V_132 -> V_7 ) ;
V_132 -> V_7 = NULL ;
}
if ( V_132 -> V_146 ) {
V_132 -> V_146 ( V_132 ) ;
V_132 -> V_146 = NULL ;
}
F_214 () ;
if ( V_132 -> V_34 ) {
if ( V_132 -> V_32 )
V_132 -> V_32 -> V_344 ( V_132 -> V_34 ) ;
F_118 ( V_132 -> V_34 ) ;
V_132 -> V_34 = NULL ;
}
if ( V_132 -> V_276 ) {
V_132 -> V_276 ( V_132 ) ;
V_132 -> V_276 = NULL ;
}
if ( V_132 -> V_158 ) {
V_132 -> V_158 ( V_132 ) ;
V_132 -> V_158 = NULL ;
}
if ( V_132 -> V_339 ) {
F_215 ( V_132 -> V_263 ) ;
V_132 -> V_339 = false ;
}
return V_15 ;
}
static int F_216 ( void )
{
int V_169 ;
char * V_176 ;
int V_15 ;
struct V_4 * V_193 ;
enum V_345 type = V_346 ;
if ( V_347 )
return 0 ;
V_347 = 1 ;
if ( V_348 ) {
V_15 = F_217 ( & V_338 ) ;
if ( V_15 ) {
F_12 (KERN_ERR PFX L_128
L_129 , rv) ;
return V_15 ;
}
}
V_176 = V_349 ;
if ( * V_176 != '\0' ) {
for ( V_169 = 0 ; ( V_169 < V_197 ) && ( * V_176 != '\0' ) ; V_169 ++ ) {
V_136 [ V_169 ] = V_176 ;
V_176 = strchr ( V_176 , ',' ) ;
if ( V_176 ) {
* V_176 = '\0' ;
V_176 ++ ;
} else {
break;
}
}
}
F_12 ( V_350 L_130 ) ;
if ( ! F_124 () )
return 0 ;
#ifdef F_218
if ( V_351 ) {
V_15 = F_219 ( & V_352 ) ;
if ( V_15 )
F_12 (KERN_ERR PFX L_128
L_131 , rv) ;
else
V_353 = true ;
}
#endif
#ifdef F_220
if ( V_354 ) {
F_221 ( & V_355 ) ;
V_356 = true ;
}
#endif
#ifdef F_222
if ( V_357 )
F_148 () ;
#endif
#ifdef F_220
if ( V_354 )
F_132 () ;
#endif
#ifdef F_223
F_224 ( & V_358 ) ;
V_359 = true ;
V_360 = 0 ;
#endif
F_121 ( & V_195 ) ;
F_206 (e, &smi_infos, link) {
if ( V_193 -> V_49 && ( ! type || V_193 -> V_141 == type ) ) {
if ( ! F_119 ( V_193 ) ) {
type = V_193 -> V_141 ;
}
}
}
if ( type ) {
F_123 ( & V_195 ) ;
return 0 ;
}
F_206 (e, &smi_infos, link) {
if ( ! V_193 -> V_49 && ( ! type || V_193 -> V_141 == type ) ) {
if ( ! F_119 ( V_193 ) ) {
type = V_193 -> V_141 ;
}
}
}
F_123 ( & V_195 ) ;
if ( type )
return 0 ;
if ( V_360 ) {
F_121 ( & V_195 ) ;
if ( F_8 ( & V_329 ) ) {
F_123 ( & V_195 ) ;
F_202 () ;
} else
F_123 ( & V_195 ) ;
}
F_121 ( & V_195 ) ;
if ( V_361 && F_8 ( & V_329 ) ) {
F_123 ( & V_195 ) ;
F_225 () ;
F_12 (KERN_WARNING PFX
L_132 ) ;
return - V_157 ;
} else {
F_123 ( & V_195 ) ;
return 0 ;
}
}
static void F_120 ( struct V_4 * V_362 )
{
int V_15 = 0 ;
unsigned long V_94 ;
if ( ! V_362 )
return;
F_9 ( & V_362 -> V_25 ) ;
F_212 ( & V_362 -> V_51 ) ;
F_199 ( V_362 ) ;
F_36 ( & V_362 -> V_97 , V_94 ) ;
while ( V_362 -> V_9 || ( V_362 -> V_38 != V_57 ) ) {
F_37 ( & V_362 -> V_97 , V_94 ) ;
F_52 ( V_362 ) ;
F_174 ( 1 ) ;
F_36 ( & V_362 -> V_97 , V_94 ) ;
}
F_19 ( V_362 ) ;
F_37 ( & V_362 -> V_97 , V_94 ) ;
while ( V_362 -> V_9 || ( V_362 -> V_38 != V_57 ) ) {
F_52 ( V_362 ) ;
F_174 ( 1 ) ;
}
if ( V_362 -> V_146 )
V_362 -> V_146 ( V_362 ) ;
while ( V_362 -> V_9 || ( V_362 -> V_38 != V_57 ) ) {
F_52 ( V_362 ) ;
F_174 ( 1 ) ;
}
if ( V_362 -> V_7 )
V_15 = F_213 ( V_362 -> V_7 ) ;
if ( V_15 ) {
F_12 (KERN_ERR PFX L_133 ,
rv) ;
}
if ( V_362 -> V_32 )
V_362 -> V_32 -> V_344 ( V_362 -> V_34 ) ;
F_118 ( V_362 -> V_34 ) ;
if ( V_362 -> V_276 )
V_362 -> V_276 ( V_362 ) ;
if ( V_362 -> V_158 )
V_362 -> V_158 ( V_362 ) ;
if ( V_362 -> V_339 )
F_215 ( V_362 -> V_263 ) ;
F_118 ( V_362 ) ;
}
static void F_225 ( void )
{
struct V_4 * V_193 , * V_194 ;
if ( ! V_347 )
return;
#ifdef F_218
if ( V_353 )
F_226 ( & V_352 ) ;
#endif
#ifdef F_220
if ( V_356 )
F_227 ( & V_355 ) ;
#endif
#ifdef F_223
if ( V_359 )
F_228 ( & V_358 ) ;
#endif
F_229 ( & V_338 ) ;
F_121 ( & V_195 ) ;
F_122 (e, tmp_e, &smi_infos, link)
F_120 ( V_193 ) ;
F_123 ( & V_195 ) ;
}
