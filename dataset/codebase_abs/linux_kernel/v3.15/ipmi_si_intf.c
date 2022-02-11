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
F_47 ( V_111 , 19 ) ;
while ( ! F_48 () ) {
int V_112 ;
F_36 ( & ( V_4 -> V_97 ) , V_94 ) ;
V_102 = F_28 ( V_4 , 0 ) ;
if ( V_102 != V_23 && ! V_4 -> V_48 )
F_17 ( V_4 , V_46 + V_52 ) ;
F_37 ( & ( V_4 -> V_97 ) , V_94 ) ;
V_112 = F_41 ( V_102 , V_4 ,
& V_103 ) ;
if ( V_102 == V_30 )
;
else if ( V_102 == V_108 && V_112 )
F_49 () ;
else if ( V_102 == V_23 ) {
if ( F_20 ( & V_4 -> V_113 ) ) {
F_50 ( 100 ) ;
} else {
F_51 ( V_114 ) ;
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
! V_4 -> V_115 )
return;
F_30 ( & V_4 -> V_89 , 1 ) ;
}
static void F_54 ( void * V_91 , bool V_116 )
{
struct V_4 * V_4 = V_91 ;
unsigned long V_94 ;
F_30 ( & V_4 -> V_113 , V_116 ) ;
F_36 ( & V_4 -> V_97 , V_94 ) ;
F_31 ( V_4 ) ;
F_37 ( & V_4 -> V_97 , V_94 ) ;
}
static void F_55 ( unsigned long V_12 )
{
struct V_4 * V_4 = (struct V_4 * ) V_12 ;
enum V_14 V_102 ;
unsigned long V_94 ;
unsigned long V_117 ;
long V_118 ;
long V_119 ;
#ifdef F_7
struct V_18 V_19 ;
#endif
F_36 ( & ( V_4 -> V_97 ) , V_94 ) ;
#ifdef F_7
F_11 ( & V_19 ) ;
F_12 ( V_26 L_11 , V_19 . V_27 , V_19 . V_28 ) ;
#endif
V_117 = V_46 ;
V_118 = ( ( ( long ) V_117 - ( long ) V_4 -> V_45 )
* V_120 ) ;
V_102 = F_28 ( V_4 , V_118 ) ;
if ( ( V_4 -> V_49 ) && ( ! V_4 -> V_50 ) ) {
V_119 = V_46 + V_52 ;
F_23 ( V_4 , V_121 ) ;
goto V_122;
}
if ( V_102 == V_108 ) {
F_23 ( V_4 , V_123 ) ;
V_119 = V_46 + 1 ;
} else {
F_23 ( V_4 , V_121 ) ;
V_119 = V_46 + V_52 ;
}
V_122:
if ( V_102 != V_23 )
F_17 ( V_4 , V_119 ) ;
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
F_23 ( V_4 , V_124 ) ;
#ifdef F_7
F_11 ( & V_19 ) ;
F_12 ( V_26 L_12 , V_19 . V_27 , V_19 . V_28 ) ;
#endif
F_28 ( V_4 , 0 ) ;
F_37 ( & ( V_4 -> V_97 ) , V_94 ) ;
return V_125 ;
}
static T_1 F_57 ( int V_49 , void * V_12 )
{
struct V_4 * V_4 = V_12 ;
V_4 -> V_126 . V_127 ( & V_4 -> V_126 , V_128 ,
V_129
| V_130 ) ;
return F_56 ( V_49 , V_12 ) ;
}
static int F_58 ( void * V_91 ,
T_2 V_7 )
{
struct V_4 * V_131 = V_91 ;
int V_116 = 0 ;
V_131 -> V_7 = V_7 ;
if ( V_131 -> V_132 )
V_131 -> V_132 ( V_131 ) ;
F_59 ( & V_131 -> V_47 , F_55 , ( long ) V_131 ) ;
F_17 ( V_131 , V_46 + V_52 ) ;
if ( V_131 -> V_105 < V_133 )
V_116 = V_134 [ V_131 -> V_105 ] ;
else if ( ( V_131 -> V_135 != V_136 ) && ( ! V_131 -> V_49 ) )
V_116 = 1 ;
if ( V_116 ) {
V_131 -> V_90 = F_60 ( F_46 , V_131 ,
L_13 , V_131 -> V_105 ) ;
if ( F_61 ( V_131 -> V_90 ) ) {
F_62 ( V_131 -> V_70 , L_14
L_15
L_16 ,
F_63 ( V_131 -> V_90 ) ) ;
V_131 -> V_90 = NULL ;
}
}
return 0 ;
}
static int F_64 ( void * V_91 , struct V_137 * V_12 )
{
struct V_4 * V_138 = V_91 ;
V_12 -> V_139 = V_138 -> V_140 ;
V_12 -> V_70 = V_138 -> V_70 ;
V_12 -> V_141 = V_138 -> V_141 ;
F_65 ( V_138 -> V_70 ) ;
return 0 ;
}
static void F_66 ( void * V_91 , bool V_116 )
{
struct V_4 * V_4 = V_91 ;
if ( ! V_116 )
F_30 ( & V_4 -> V_89 , 0 ) ;
}
static void F_67 ( struct V_4 * V_142 )
{
if ( V_142 -> V_135 == V_136 )
V_142 -> V_126 . V_127 ( & V_142 -> V_126 , V_128 , 0 ) ;
F_68 ( V_142 -> V_49 , V_142 ) ;
}
static int F_69 ( struct V_4 * V_142 )
{
int V_15 ;
if ( ! V_142 -> V_49 )
return 0 ;
if ( V_142 -> V_135 == V_136 ) {
V_15 = F_70 ( V_142 -> V_49 ,
F_57 ,
V_143 ,
V_144 ,
V_142 ) ;
if ( ! V_15 )
V_142 -> V_126 . V_127 ( & V_142 -> V_126 , V_128 ,
V_130 ) ;
} else
V_15 = F_70 ( V_142 -> V_49 ,
F_56 ,
V_143 ,
V_144 ,
V_142 ) ;
if ( V_15 ) {
F_27 ( V_142 -> V_70 , L_17
L_18 ,
V_144 , V_142 -> V_49 ) ;
V_142 -> V_49 = 0 ;
} else {
V_142 -> V_145 = F_67 ;
F_71 ( V_142 -> V_70 , L_19 , V_142 -> V_49 ) ;
}
return V_15 ;
}
static unsigned char F_72 ( struct V_146 * V_126 , unsigned int V_147 )
{
unsigned int V_148 = V_126 -> V_149 ;
return F_73 ( V_148 + ( V_147 * V_126 -> V_150 ) ) ;
}
static void F_74 ( struct V_146 * V_126 , unsigned int V_147 ,
unsigned char V_151 )
{
unsigned int V_148 = V_126 -> V_149 ;
F_75 ( V_151 , V_148 + ( V_147 * V_126 -> V_150 ) ) ;
}
static unsigned char F_76 ( struct V_146 * V_126 , unsigned int V_147 )
{
unsigned int V_148 = V_126 -> V_149 ;
return ( F_77 ( V_148 + ( V_147 * V_126 -> V_150 ) ) >> V_126 -> V_152 ) & 0xff ;
}
static void F_78 ( struct V_146 * V_126 , unsigned int V_147 ,
unsigned char V_151 )
{
unsigned int V_148 = V_126 -> V_149 ;
F_79 ( V_151 << V_126 -> V_152 , V_148 + ( V_147 * V_126 -> V_150 ) ) ;
}
static unsigned char F_80 ( struct V_146 * V_126 , unsigned int V_147 )
{
unsigned int V_148 = V_126 -> V_149 ;
return ( F_81 ( V_148 + ( V_147 * V_126 -> V_150 ) ) >> V_126 -> V_152 ) & 0xff ;
}
static void F_82 ( struct V_146 * V_126 , unsigned int V_147 ,
unsigned char V_151 )
{
unsigned int V_148 = V_126 -> V_149 ;
F_83 ( V_151 << V_126 -> V_152 , V_148 + ( V_147 * V_126 -> V_150 ) ) ;
}
static void F_84 ( struct V_4 * V_142 )
{
unsigned int V_148 = V_142 -> V_126 . V_149 ;
int V_153 ;
if ( V_148 ) {
for ( V_153 = 0 ; V_153 < V_142 -> V_154 ; V_153 ++ )
F_85 ( V_148 + V_153 * V_142 -> V_126 . V_150 ,
V_142 -> V_126 . V_155 ) ;
}
}
static int F_86 ( struct V_4 * V_142 )
{
unsigned int V_148 = V_142 -> V_126 . V_149 ;
int V_153 ;
if ( ! V_148 )
return - V_156 ;
V_142 -> V_157 = F_84 ;
switch ( V_142 -> V_126 . V_155 ) {
case 1 :
V_142 -> V_126 . V_158 = F_72 ;
V_142 -> V_126 . V_127 = F_74 ;
break;
case 2 :
V_142 -> V_126 . V_158 = F_76 ;
V_142 -> V_126 . V_127 = F_78 ;
break;
case 4 :
V_142 -> V_126 . V_158 = F_80 ;
V_142 -> V_126 . V_127 = F_82 ;
break;
default:
F_27 ( V_142 -> V_70 , L_20 ,
V_142 -> V_126 . V_155 ) ;
return - V_159 ;
}
for ( V_153 = 0 ; V_153 < V_142 -> V_154 ; V_153 ++ ) {
if ( F_87 ( V_148 + V_153 * V_142 -> V_126 . V_150 ,
V_142 -> V_126 . V_155 , V_144 ) == NULL ) {
while ( V_153 -- ) {
F_85 ( V_148 + V_153 * V_142 -> V_126 . V_150 ,
V_142 -> V_126 . V_155 ) ;
}
return - V_160 ;
}
}
return 0 ;
}
static unsigned char F_88 ( struct V_146 * V_126 , unsigned int V_147 )
{
return F_89 ( ( V_126 -> V_148 ) + ( V_147 * V_126 -> V_150 ) ) ;
}
static void F_90 ( struct V_146 * V_126 , unsigned int V_147 ,
unsigned char V_151 )
{
F_91 ( V_151 , ( V_126 -> V_148 ) + ( V_147 * V_126 -> V_150 ) ) ;
}
static unsigned char F_92 ( struct V_146 * V_126 , unsigned int V_147 )
{
return ( F_93 ( ( V_126 -> V_148 ) + ( V_147 * V_126 -> V_150 ) ) >> V_126 -> V_152 )
& 0xff ;
}
static void F_94 ( struct V_146 * V_126 , unsigned int V_147 ,
unsigned char V_151 )
{
F_91 ( V_151 << V_126 -> V_152 , ( V_126 -> V_148 ) + ( V_147 * V_126 -> V_150 ) ) ;
}
static unsigned char F_95 ( struct V_146 * V_126 , unsigned int V_147 )
{
return ( F_96 ( ( V_126 -> V_148 ) + ( V_147 * V_126 -> V_150 ) ) >> V_126 -> V_152 )
& 0xff ;
}
static void F_97 ( struct V_146 * V_126 , unsigned int V_147 ,
unsigned char V_151 )
{
F_98 ( V_151 << V_126 -> V_152 , ( V_126 -> V_148 ) + ( V_147 * V_126 -> V_150 ) ) ;
}
static unsigned char F_99 ( struct V_146 * V_126 , unsigned int V_147 )
{
return ( F_100 ( ( V_126 -> V_148 ) + ( V_147 * V_126 -> V_150 ) ) >> V_126 -> V_152 )
& 0xff ;
}
static void F_101 ( struct V_146 * V_126 , unsigned int V_147 ,
unsigned char V_151 )
{
F_102 ( V_151 << V_126 -> V_152 , ( V_126 -> V_148 ) + ( V_147 * V_126 -> V_150 ) ) ;
}
static void F_103 ( struct V_4 * V_142 )
{
unsigned long V_148 = V_142 -> V_126 . V_149 ;
int V_161 ;
if ( V_142 -> V_126 . V_148 ) {
F_104 ( V_142 -> V_126 . V_148 ) ;
V_161 = ( ( V_142 -> V_154 * V_142 -> V_126 . V_150 )
- ( V_142 -> V_126 . V_150 - V_142 -> V_126 . V_155 ) ) ;
F_105 ( V_148 , V_161 ) ;
}
}
static int F_106 ( struct V_4 * V_142 )
{
unsigned long V_148 = V_142 -> V_126 . V_149 ;
int V_161 ;
if ( ! V_148 )
return - V_156 ;
V_142 -> V_157 = F_103 ;
switch ( V_142 -> V_126 . V_155 ) {
case 1 :
V_142 -> V_126 . V_158 = F_88 ;
V_142 -> V_126 . V_127 = F_90 ;
break;
case 2 :
V_142 -> V_126 . V_158 = F_92 ;
V_142 -> V_126 . V_127 = F_94 ;
break;
case 4 :
V_142 -> V_126 . V_158 = F_95 ;
V_142 -> V_126 . V_127 = F_97 ;
break;
#ifdef F_100
case 8 :
V_142 -> V_126 . V_158 = F_99 ;
V_142 -> V_126 . V_127 = F_101 ;
break;
#endif
default:
F_27 ( V_142 -> V_70 , L_20 ,
V_142 -> V_126 . V_155 ) ;
return - V_159 ;
}
V_161 = ( ( V_142 -> V_154 * V_142 -> V_126 . V_150 )
- ( V_142 -> V_126 . V_150 - V_142 -> V_126 . V_155 ) ) ;
if ( F_107 ( V_148 , V_161 , V_144 ) == NULL )
return - V_160 ;
V_142 -> V_126 . V_148 = F_108 ( V_148 , V_161 ) ;
if ( V_142 -> V_126 . V_148 == NULL ) {
F_105 ( V_148 , V_161 ) ;
return - V_160 ;
}
return 0 ;
}
static int F_109 ( struct V_162 * V_163 , int * V_164 , char * V_165 , char * * V_166 )
{
char * V_167 ;
int V_168 ;
V_167 = strchr ( * V_166 , ',' ) ;
if ( ! V_167 ) {
F_12 (KERN_WARNING PFX L_21 , name) ;
return - V_159 ;
}
* V_167 = '\0' ;
V_167 ++ ;
for ( V_168 = 0 ; V_169 [ V_168 ] . V_165 ; V_168 ++ ) {
if ( strcmp ( * V_166 , V_163 [ V_168 ] . V_165 ) == 0 ) {
* V_164 = V_163 [ V_168 ] . V_164 ;
* V_166 = V_167 ;
return 0 ;
}
}
F_12 (KERN_WARNING PFX L_22 , name, *curr) ;
return - V_159 ;
}
static int F_110 ( const char * V_166 , const char * V_170 ,
const char * V_165 , int * V_164 )
{
char * V_171 ;
if ( strcmp ( V_166 , V_165 ) == 0 ) {
if ( ! V_170 ) {
F_12 (KERN_WARNING PFX
L_23 ,
curr) ;
return - V_159 ;
}
* V_164 = F_111 ( V_170 , & V_171 , 0 ) ;
if ( ( * V_171 != '\0' ) || ( * V_170 == '\0' ) ) {
F_12 (KERN_WARNING PFX
L_24 ,
curr) ;
return - V_159 ;
}
return 1 ;
}
return 0 ;
}
static struct V_4 * F_112 ( void )
{
struct V_4 * V_142 = F_113 ( sizeof( * V_142 ) , V_172 ) ;
if ( V_142 )
F_114 ( & V_142 -> V_97 ) ;
return V_142 ;
}
static int F_115 ( const char * V_164 , struct V_173 * V_174 )
{
char * V_175 = F_116 ( V_164 , V_172 ) ;
int V_15 ;
char * V_21 , * V_166 , * V_167 , * V_171 , * V_176 ;
enum V_177 V_178 ;
enum V_135 V_135 ;
int V_179 ;
unsigned long V_148 ;
int V_150 ;
int V_155 ;
int V_152 ;
int V_49 ;
int V_180 ;
int V_181 ;
int V_68 ;
struct V_4 * V_142 ;
if ( ! V_175 )
return - V_182 ;
V_68 = strlen ( V_175 ) ;
V_181 = V_68 - 1 ;
while ( ( V_181 >= 0 ) && isspace ( V_175 [ V_181 ] ) ) {
V_175 [ V_181 ] = '\0' ;
V_181 -- ;
}
for ( V_166 = V_175 ; V_166 ; V_166 = V_21 ) {
V_150 = 1 ;
V_155 = 1 ;
V_152 = 0 ;
V_49 = 0 ;
V_180 = 0 ;
V_21 = strchr ( V_166 , ':' ) ;
if ( V_21 ) {
* V_21 = '\0' ;
V_21 ++ ;
}
V_15 = F_109 ( V_169 , & V_181 , L_25 , & V_166 ) ;
if ( V_15 )
break;
V_178 = V_181 ;
V_15 = F_109 ( V_183 , & V_181 , L_26 , & V_166 ) ;
if ( V_15 )
break;
V_135 = V_181 ;
V_15 = F_109 ( V_184 , & V_179 , L_27 , & V_166 ) ;
if ( V_15 )
break;
V_167 = strchr ( V_166 , ',' ) ;
if ( V_167 ) {
* V_167 = '\0' ;
V_167 ++ ;
}
V_148 = F_111 ( V_166 , & V_171 , 0 ) ;
if ( ( * V_171 != '\0' ) || ( * V_166 == '\0' ) ) {
F_12 (KERN_WARNING PFX L_28
L_29 , curr) ;
break;
}
while ( V_167 ) {
V_166 = V_167 ;
V_167 = strchr ( V_166 , ',' ) ;
if ( V_167 ) {
* V_167 = '\0' ;
V_167 ++ ;
}
V_176 = strchr ( V_166 , '=' ) ;
if ( V_176 ) {
* V_176 = '\0' ;
V_176 ++ ;
}
V_15 = F_110 ( V_166 , V_176 , L_30 , & V_150 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = F_110 ( V_166 , V_176 , L_31 , & V_155 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = F_110 ( V_166 , V_176 , L_32 , & V_152 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = F_110 ( V_166 , V_176 , L_33 , & V_49 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = F_110 ( V_166 , V_176 , L_34 , & V_180 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = - V_159 ;
F_12 (KERN_WARNING PFX
L_35 ,
curr) ;
goto V_31;
}
if ( V_178 == V_185 ) {
V_142 = F_112 () ;
if ( ! V_142 ) {
V_15 = - V_182 ;
goto V_31;
}
V_142 -> V_140 = V_186 ;
V_142 -> V_135 = V_135 ;
V_142 -> V_126 . V_149 = V_148 ;
V_142 -> V_126 . V_187 = V_179 ;
if ( V_179 == V_188 )
V_142 -> V_189 = F_106 ;
else
V_142 -> V_189 = F_86 ;
V_142 -> V_126 . V_148 = NULL ;
V_142 -> V_126 . V_150 = V_150 ;
if ( ! V_142 -> V_126 . V_150 )
V_142 -> V_126 . V_150 = V_190 ;
V_142 -> V_126 . V_155 = V_155 ;
if ( ! V_142 -> V_126 . V_155 )
V_142 -> V_126 . V_155 = V_190 ;
V_142 -> V_126 . V_152 = V_152 ;
V_142 -> V_49 = V_49 ;
if ( V_142 -> V_49 )
V_142 -> V_132 = F_69 ;
V_142 -> V_191 = V_180 ;
V_15 = F_117 ( V_142 ) ;
if ( V_15 ) {
F_118 ( V_142 ) ;
goto V_31;
}
V_15 = F_119 ( V_142 ) ;
if ( V_15 ) {
F_120 ( V_142 ) ;
goto V_31;
}
} else {
struct V_4 * V_192 , * V_193 ;
F_121 ( & V_194 ) ;
F_122 (e, tmp_e, &smi_infos, link) {
if ( V_192 -> V_126 . V_187 != V_179 )
continue;
if ( V_192 -> V_135 != V_135 )
continue;
if ( V_192 -> V_126 . V_149 == V_148 )
F_120 ( V_192 ) ;
}
F_123 ( & V_194 ) ;
}
}
V_15 = V_68 ;
V_31:
F_118 ( V_175 ) ;
return V_15 ;
}
static int F_124 ( void )
{
int V_195 = - V_156 ;
int V_168 ;
struct V_4 * V_142 ;
for ( V_168 = 0 ; V_168 < V_196 ; V_168 ++ ) {
if ( ! V_197 [ V_168 ] && ! V_198 [ V_168 ] )
continue;
V_142 = F_112 () ;
if ( ! V_142 )
return - V_182 ;
V_142 -> V_140 = V_199 ;
F_12 (KERN_INFO PFX L_36 ) ;
if ( ! V_135 [ V_168 ] || strcmp ( V_135 [ V_168 ] , L_37 ) == 0 ) {
V_142 -> V_135 = V_200 ;
} else if ( strcmp ( V_135 [ V_168 ] , L_38 ) == 0 ) {
V_142 -> V_135 = V_201 ;
} else if ( strcmp ( V_135 [ V_168 ] , L_39 ) == 0 ) {
V_142 -> V_135 = V_136 ;
} else {
F_12 (KERN_WARNING PFX L_40
L_41 ,
i, si_type[i]) ;
F_118 ( V_142 ) ;
continue;
}
if ( V_197 [ V_168 ] ) {
V_142 -> V_189 = F_86 ;
V_142 -> V_126 . V_149 = V_197 [ V_168 ] ;
V_142 -> V_126 . V_187 = V_202 ;
} else if ( V_198 [ V_168 ] ) {
V_142 -> V_189 = F_106 ;
V_142 -> V_126 . V_149 = V_198 [ V_168 ] ;
V_142 -> V_126 . V_187 = V_188 ;
} else {
F_12 (KERN_WARNING PFX L_40
L_42
L_43 , i) ;
F_118 ( V_142 ) ;
continue;
}
V_142 -> V_126 . V_148 = NULL ;
V_142 -> V_126 . V_150 = V_203 [ V_168 ] ;
if ( ! V_142 -> V_126 . V_150 )
V_142 -> V_126 . V_150 = V_190 ;
V_142 -> V_126 . V_155 = V_204 [ V_168 ] ;
if ( ! V_142 -> V_126 . V_155 )
V_142 -> V_126 . V_155 = V_190 ;
V_142 -> V_126 . V_152 = V_205 [ V_168 ] ;
V_142 -> V_49 = V_206 [ V_168 ] ;
if ( V_142 -> V_49 )
V_142 -> V_132 = F_69 ;
V_142 -> V_191 = V_207 [ V_168 ] ;
if ( ! F_117 ( V_142 ) ) {
if ( F_119 ( V_142 ) )
F_120 ( V_142 ) ;
V_195 = 0 ;
} else {
F_118 ( V_142 ) ;
}
}
return V_195 ;
}
static T_3 F_125 ( T_4 V_208 ,
T_3 V_209 , void * V_210 )
{
struct V_4 * V_4 = V_210 ;
unsigned long V_94 ;
#ifdef F_7
struct V_18 V_19 ;
#endif
F_36 ( & ( V_4 -> V_97 ) , V_94 ) ;
F_23 ( V_4 , V_124 ) ;
#ifdef F_7
F_11 ( & V_19 ) ;
F_12 ( L_44 , V_19 . V_27 , V_19 . V_28 ) ;
#endif
F_28 ( V_4 , 0 ) ;
F_37 ( & ( V_4 -> V_97 ) , V_94 ) ;
return V_211 ;
}
static void F_126 ( struct V_4 * V_142 )
{
if ( ! V_142 -> V_49 )
return;
F_127 ( NULL , V_142 -> V_49 , & F_125 ) ;
}
static int F_128 ( struct V_4 * V_142 )
{
T_5 V_212 ;
if ( ! V_142 -> V_49 )
return 0 ;
V_212 = F_129 ( NULL ,
V_142 -> V_49 ,
V_213 ,
& F_125 ,
V_142 ) ;
if ( V_212 != V_214 ) {
F_27 ( V_142 -> V_70 , L_45
L_18 , V_144 , V_142 -> V_49 ) ;
V_142 -> V_49 = 0 ;
return - V_159 ;
} else {
V_142 -> V_145 = F_126 ;
F_71 ( V_142 -> V_70 , L_46 , V_142 -> V_49 ) ;
return 0 ;
}
}
static int F_130 ( struct V_215 * V_216 )
{
struct V_4 * V_142 ;
int V_15 ;
if ( V_216 -> V_217 != 1 ) {
F_12 (KERN_INFO PFX L_47 , spmi->IPMIlegacy) ;
return - V_156 ;
}
V_142 = F_112 () ;
if ( ! V_142 ) {
F_12 (KERN_ERR PFX L_48 ) ;
return - V_182 ;
}
V_142 -> V_140 = V_218 ;
F_12 (KERN_INFO PFX L_49 ) ;
switch ( V_216 -> V_219 ) {
case 1 :
V_142 -> V_135 = V_200 ;
break;
case 2 :
V_142 -> V_135 = V_201 ;
break;
case 3 :
V_142 -> V_135 = V_136 ;
break;
default:
F_12 (KERN_INFO PFX L_50 ,
spmi->InterfaceType) ;
F_118 ( V_142 ) ;
return - V_160 ;
}
if ( V_216 -> V_220 & 1 ) {
V_142 -> V_49 = V_216 -> V_221 ;
V_142 -> V_132 = F_128 ;
} else if ( V_216 -> V_220 & 2 ) {
V_142 -> V_49 = V_216 -> V_222 ;
V_142 -> V_132 = F_69 ;
} else {
V_142 -> V_49 = 0 ;
V_142 -> V_132 = NULL ;
}
if ( V_216 -> V_148 . V_223 ) {
V_142 -> V_126 . V_150 = V_216 -> V_148 . V_223 / 8 ;
} else {
V_142 -> V_126 . V_150 = V_190 ;
}
V_142 -> V_126 . V_155 = V_142 -> V_126 . V_150 ;
V_142 -> V_126 . V_152 = V_216 -> V_148 . V_224 ;
if ( V_216 -> V_148 . V_225 == V_226 ) {
V_142 -> V_189 = F_106 ;
V_142 -> V_126 . V_187 = V_188 ;
} else if ( V_216 -> V_148 . V_225 == V_227 ) {
V_142 -> V_189 = F_86 ;
V_142 -> V_126 . V_187 = V_202 ;
} else {
F_118 ( V_142 ) ;
F_12 (KERN_WARNING PFX L_51 ) ;
return - V_160 ;
}
V_142 -> V_126 . V_149 = V_216 -> V_148 . V_228 ;
F_131 ( L_52 ,
( V_142 -> V_126 . V_187 == V_202 ) ? L_53 : L_54 ,
V_142 -> V_126 . V_149 , V_142 -> V_126 . V_155 , V_142 -> V_126 . V_150 ,
V_142 -> V_49 ) ;
V_15 = F_117 ( V_142 ) ;
if ( V_15 )
F_118 ( V_142 ) ;
return V_15 ;
}
static void F_132 ( void )
{
T_5 V_212 ;
struct V_215 * V_216 ;
int V_168 ;
if ( V_229 )
return;
if ( V_230 )
return;
for ( V_168 = 0 ; ; V_168 ++ ) {
V_212 = F_133 ( V_231 , V_168 + 1 ,
(struct V_232 * * ) & V_216 ) ;
if ( V_212 != V_214 )
return;
F_130 ( V_216 ) ;
}
}
static int F_134 ( struct V_233 * V_70 ,
const struct V_234 * V_235 )
{
struct V_236 * V_237 ;
struct V_4 * V_142 ;
struct V_238 * V_239 , * V_240 ;
T_4 V_241 ;
T_5 V_212 ;
unsigned long long V_242 ;
int V_15 ;
V_237 = F_135 ( V_70 ) ;
if ( ! V_237 )
return - V_156 ;
V_142 = F_112 () ;
if ( ! V_142 )
return - V_182 ;
V_142 -> V_140 = V_243 ;
F_12 (KERN_INFO PFX L_55 ) ;
V_241 = V_237 -> V_241 ;
V_142 -> V_141 . V_244 . T_4 = V_241 ;
V_212 = F_136 ( V_241 , L_56 , NULL , & V_242 ) ;
if ( F_137 ( V_212 ) )
goto V_245;
switch ( V_242 ) {
case 1 :
V_142 -> V_135 = V_200 ;
break;
case 2 :
V_142 -> V_135 = V_201 ;
break;
case 3 :
V_142 -> V_135 = V_136 ;
break;
default:
F_71 ( & V_70 -> V_70 , L_57 , V_242 ) ;
goto V_245;
}
V_239 = F_138 ( V_70 , V_246 , 0 ) ;
if ( V_239 ) {
V_142 -> V_189 = F_86 ;
V_142 -> V_126 . V_187 = V_202 ;
} else {
V_239 = F_138 ( V_70 , V_247 , 0 ) ;
if ( V_239 ) {
V_142 -> V_189 = F_106 ;
V_142 -> V_126 . V_187 = V_188 ;
}
}
if ( ! V_239 ) {
F_139 ( & V_70 -> V_70 , L_58 ) ;
goto V_245;
}
V_142 -> V_126 . V_149 = V_239 -> V_248 ;
V_142 -> V_126 . V_150 = V_190 ;
V_240 = F_138 ( V_70 ,
( V_142 -> V_126 . V_187 == V_202 ) ?
V_246 : V_247 ,
1 ) ;
if ( V_240 ) {
if ( V_240 -> V_248 > V_142 -> V_126 . V_149 )
V_142 -> V_126 . V_150 = V_240 -> V_248 - V_142 -> V_126 . V_149 ;
}
V_142 -> V_126 . V_155 = V_190 ;
V_142 -> V_126 . V_152 = 0 ;
V_212 = F_136 ( V_241 , L_59 , NULL , & V_242 ) ;
if ( F_140 ( V_212 ) ) {
V_142 -> V_49 = V_242 ;
V_142 -> V_132 = F_128 ;
} else if ( F_141 ( V_70 , 0 ) ) {
V_142 -> V_49 = F_142 ( V_70 , 0 ) ;
V_142 -> V_132 = F_69 ;
}
V_142 -> V_70 = & V_70 -> V_70 ;
F_143 ( V_70 , V_142 ) ;
F_71 ( V_142 -> V_70 , L_60 ,
V_239 , V_142 -> V_126 . V_155 , V_142 -> V_126 . V_150 ,
V_142 -> V_49 ) ;
V_15 = F_117 ( V_142 ) ;
if ( V_15 )
F_118 ( V_142 ) ;
return V_15 ;
V_245:
F_118 ( V_142 ) ;
return - V_159 ;
}
static void F_144 ( struct V_233 * V_70 )
{
struct V_4 * V_142 = F_145 ( V_70 ) ;
F_120 ( V_142 ) ;
}
static int F_146 ( const struct V_249 * V_250 ,
struct V_251 * V_252 )
{
const T_6 * V_12 = ( const T_6 * ) V_250 ;
unsigned long V_253 ;
T_6 V_254 ;
T_6 V_68 = V_250 -> V_255 ;
V_252 -> type = V_12 [ 4 ] ;
memcpy ( & V_253 , V_12 + 8 , sizeof( unsigned long ) ) ;
if ( V_68 >= 0x11 ) {
if ( V_253 & 1 ) {
V_253 &= 0xFFFE ;
V_252 -> V_179 = V_202 ;
} else
V_252 -> V_179 = V_188 ;
V_252 -> V_253 = V_253 | ( ( V_12 [ 0x10 ] & 0x10 ) >> 4 ) ;
V_252 -> V_49 = V_12 [ 0x11 ] ;
V_254 = ( V_12 [ 0x10 ] & 0xC0 ) >> 6 ;
switch ( V_254 ) {
case 0x00 :
V_252 -> V_147 = 1 ;
break;
case 0x01 :
V_252 -> V_147 = 4 ;
break;
case 0x02 :
V_252 -> V_147 = 16 ;
break;
default:
return - V_160 ;
}
} else {
V_252 -> V_253 = V_253 & 0xfffe ;
V_252 -> V_179 = V_202 ;
V_252 -> V_147 = 1 ;
}
V_252 -> V_191 = V_12 [ 6 ] ;
return 0 ;
}
static void F_147 ( struct V_251 * V_256 )
{
struct V_4 * V_142 ;
V_142 = F_112 () ;
if ( ! V_142 ) {
F_12 (KERN_ERR PFX L_61 ) ;
return;
}
V_142 -> V_140 = V_257 ;
F_12 (KERN_INFO PFX L_62 ) ;
switch ( V_256 -> type ) {
case 0x01 :
V_142 -> V_135 = V_200 ;
break;
case 0x02 :
V_142 -> V_135 = V_201 ;
break;
case 0x03 :
V_142 -> V_135 = V_136 ;
break;
default:
F_118 ( V_142 ) ;
return;
}
switch ( V_256 -> V_179 ) {
case V_188 :
V_142 -> V_189 = F_106 ;
V_142 -> V_126 . V_187 = V_188 ;
break;
case V_202 :
V_142 -> V_189 = F_86 ;
V_142 -> V_126 . V_187 = V_202 ;
break;
default:
F_118 ( V_142 ) ;
F_12 (KERN_WARNING PFX L_63 ,
ipmi_data->addr_space) ;
return;
}
V_142 -> V_126 . V_149 = V_256 -> V_253 ;
V_142 -> V_126 . V_150 = V_256 -> V_147 ;
if ( ! V_142 -> V_126 . V_150 )
V_142 -> V_126 . V_150 = V_190 ;
V_142 -> V_126 . V_155 = V_190 ;
V_142 -> V_126 . V_152 = 0 ;
V_142 -> V_191 = V_256 -> V_191 ;
V_142 -> V_49 = V_256 -> V_49 ;
if ( V_142 -> V_49 )
V_142 -> V_132 = F_69 ;
F_131 ( L_64 ,
( V_142 -> V_126 . V_187 == V_202 ) ? L_53 : L_54 ,
V_142 -> V_126 . V_149 , V_142 -> V_126 . V_155 , V_142 -> V_126 . V_150 ,
V_142 -> V_49 ) ;
if ( F_117 ( V_142 ) )
F_118 ( V_142 ) ;
}
static void F_148 ( void )
{
const struct V_258 * V_70 = NULL ;
struct V_251 V_12 ;
int V_15 ;
while ( ( V_70 = F_149 ( V_259 , NULL , V_70 ) ) ) {
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_15 = F_146 ( ( const struct V_249 * ) V_70 -> V_260 ,
& V_12 ) ;
if ( ! V_15 )
F_147 ( & V_12 ) ;
}
}
static void F_150 ( struct V_4 * V_142 )
{
struct V_261 * V_262 = V_142 -> V_263 ;
F_151 ( V_262 ) ;
}
static int F_152 ( struct V_4 * V_142 )
{
if ( V_142 -> V_135 == V_200 ) {
unsigned char V_212 ;
int V_150 ;
V_142 -> V_126 . V_155 = V_264 ;
V_142 -> V_126 . V_152 = 0 ;
V_142 -> V_154 = 2 ;
V_142 -> V_32 = & V_265 ;
for ( V_150 = V_190 ; V_150 <= 16 ; ) {
V_142 -> V_126 . V_150 = V_150 ;
if ( V_142 -> V_189 ( V_142 ) ) {
F_139 ( V_142 -> V_70 ,
L_65 ) ;
return V_190 ;
}
V_142 -> V_126 . V_127 ( & V_142 -> V_126 , 1 , 0x10 ) ;
V_212 = V_142 -> V_126 . V_158 ( & V_142 -> V_126 , 1 ) ;
V_142 -> V_157 ( V_142 ) ;
if ( V_212 )
return V_150 ;
V_150 *= 4 ;
}
}
return V_190 ;
}
static int F_153 ( struct V_261 * V_262 ,
const struct V_266 * V_267 )
{
int V_15 ;
int V_268 = V_262 -> V_269 & V_270 ;
struct V_4 * V_142 ;
V_142 = F_112 () ;
if ( ! V_142 )
return - V_182 ;
V_142 -> V_140 = V_271 ;
F_71 ( & V_262 -> V_70 , L_66 ) ;
switch ( V_268 ) {
case V_272 :
V_142 -> V_135 = V_201 ;
break;
case V_273 :
V_142 -> V_135 = V_200 ;
break;
case V_274 :
V_142 -> V_135 = V_136 ;
break;
default:
F_118 ( V_142 ) ;
F_71 ( & V_262 -> V_70 , L_67 , V_268 ) ;
return - V_182 ;
}
V_15 = F_154 ( V_262 ) ;
if ( V_15 ) {
F_139 ( & V_262 -> V_70 , L_68 ) ;
F_118 ( V_142 ) ;
return V_15 ;
}
V_142 -> V_275 = F_150 ;
V_142 -> V_263 = V_262 ;
if ( F_155 ( V_262 , 0 ) & V_246 ) {
V_142 -> V_189 = F_86 ;
V_142 -> V_126 . V_187 = V_202 ;
} else {
V_142 -> V_189 = F_106 ;
V_142 -> V_126 . V_187 = V_188 ;
}
V_142 -> V_126 . V_149 = F_156 ( V_262 , 0 ) ;
V_142 -> V_126 . V_150 = F_152 ( V_142 ) ;
V_142 -> V_126 . V_155 = V_264 ;
V_142 -> V_126 . V_152 = 0 ;
V_142 -> V_49 = V_262 -> V_49 ;
if ( V_142 -> V_49 )
V_142 -> V_132 = F_69 ;
V_142 -> V_70 = & V_262 -> V_70 ;
F_157 ( V_262 , V_142 ) ;
F_71 ( & V_262 -> V_70 , L_60 ,
& V_262 -> V_238 [ 0 ] , V_142 -> V_126 . V_155 , V_142 -> V_126 . V_150 ,
V_142 -> V_49 ) ;
V_15 = F_117 ( V_142 ) ;
if ( V_15 ) {
F_118 ( V_142 ) ;
F_151 ( V_262 ) ;
}
return V_15 ;
}
static void F_158 ( struct V_261 * V_262 )
{
struct V_4 * V_142 = F_159 ( V_262 ) ;
F_120 ( V_142 ) ;
F_151 ( V_262 ) ;
}
static int F_160 ( struct V_276 * V_70 )
{
#ifdef F_161
const struct V_277 * V_278 ;
struct V_4 * V_142 ;
struct V_238 V_238 ;
const T_7 * V_155 , * V_150 , * V_152 ;
struct V_279 * V_280 = V_70 -> V_70 . V_281 ;
int V_195 ;
int V_282 ;
F_71 ( & V_70 -> V_70 , L_69 ) ;
V_278 = F_162 ( V_283 , & V_70 -> V_70 ) ;
if ( ! V_278 )
return - V_159 ;
V_195 = F_163 ( V_280 , 0 , & V_238 ) ;
if ( V_195 ) {
F_27 ( & V_70 -> V_70 , V_284 L_70 ) ;
return V_195 ;
}
V_155 = F_164 ( V_280 , L_71 , & V_282 ) ;
if ( V_155 && V_282 != 4 ) {
F_27 ( & V_70 -> V_70 , V_284 L_72 ) ;
return - V_159 ;
}
V_150 = F_164 ( V_280 , L_73 , & V_282 ) ;
if ( V_150 && V_282 != 4 ) {
F_27 ( & V_70 -> V_70 , V_284 L_74 ) ;
return - V_159 ;
}
V_152 = F_164 ( V_280 , L_75 , & V_282 ) ;
if ( V_152 && V_282 != 4 ) {
F_27 ( & V_70 -> V_70 , V_284 L_76 ) ;
return - V_159 ;
}
V_142 = F_112 () ;
if ( ! V_142 ) {
F_139 ( & V_70 -> V_70 ,
L_77 ) ;
return - V_182 ;
}
V_142 -> V_135 = (enum V_135 ) V_278 -> V_12 ;
V_142 -> V_140 = V_285 ;
V_142 -> V_132 = F_69 ;
if ( V_238 . V_94 & V_246 ) {
V_142 -> V_189 = F_86 ;
V_142 -> V_126 . V_187 = V_202 ;
} else {
V_142 -> V_189 = F_106 ;
V_142 -> V_126 . V_187 = V_188 ;
}
V_142 -> V_126 . V_149 = V_238 . V_248 ;
V_142 -> V_126 . V_155 = V_155 ? F_165 ( V_155 ) : V_264 ;
V_142 -> V_126 . V_150 = V_150 ? F_165 ( V_150 ) : V_190 ;
V_142 -> V_126 . V_152 = V_152 ? F_165 ( V_152 ) : 0 ;
V_142 -> V_49 = F_166 ( V_70 -> V_70 . V_281 , 0 ) ;
V_142 -> V_70 = & V_70 -> V_70 ;
F_167 ( & V_70 -> V_70 , L_78 ,
V_142 -> V_126 . V_149 , V_142 -> V_126 . V_155 , V_142 -> V_126 . V_150 ,
V_142 -> V_49 ) ;
F_168 ( & V_70 -> V_70 , V_142 ) ;
V_195 = F_117 ( V_142 ) ;
if ( V_195 ) {
F_118 ( V_142 ) ;
return V_195 ;
}
#endif
return 0 ;
}
static int F_169 ( struct V_276 * V_70 )
{
#ifdef F_161
F_120 ( F_170 ( & V_70 -> V_70 ) ) ;
#endif
return 0 ;
}
static int F_171 ( struct V_286 * V_70 )
{
struct V_4 * V_142 ;
int V_15 ;
V_142 = F_112 () ;
if ( ! V_142 ) {
F_139 ( & V_70 -> V_70 ,
L_79 ) ;
return - V_182 ;
}
V_142 -> V_135 = V_200 ;
V_142 -> V_140 = V_285 ;
V_142 -> V_189 = F_106 ;
V_142 -> V_126 . V_187 = V_188 ;
V_142 -> V_126 . V_149 = V_70 -> V_287 . V_248 ;
V_142 -> V_126 . V_155 = 1 ;
V_142 -> V_126 . V_150 = 1 ;
V_142 -> V_126 . V_152 = 0 ;
V_142 -> V_49 = 0 ;
V_142 -> V_132 = NULL ;
V_142 -> V_70 = & V_70 -> V_70 ;
F_167 ( & V_70 -> V_70 , L_80 , V_142 -> V_126 . V_149 ) ;
F_168 ( & V_70 -> V_70 , V_142 ) ;
V_15 = F_117 ( V_142 ) ;
if ( V_15 ) {
F_118 ( V_142 ) ;
return V_15 ;
}
return 0 ;
}
static int F_172 ( struct V_286 * V_70 )
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
V_102 == V_288 ) {
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
return - V_156 ;
return 0 ;
}
static int F_176 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 2 ] ;
unsigned char * V_289 ;
unsigned long V_290 ;
int V_15 = 0 ;
V_289 = F_177 ( V_66 , V_172 ) ;
if ( ! V_289 )
return - V_182 ;
V_6 [ 0 ] = V_36 << 2 ;
V_6 [ 1 ] = V_291 ;
V_4 -> V_32 -> V_33 ( V_4 -> V_34 , V_6 , 2 ) ;
V_15 = F_173 ( V_4 ) ;
if ( V_15 )
goto V_31;
V_290 = V_4 -> V_32 -> V_65 ( V_4 -> V_34 ,
V_289 , V_66 ) ;
V_15 = F_178 ( V_289 , V_290 , & V_4 -> V_292 ) ;
V_31:
F_118 ( V_289 ) ;
return V_15 ;
}
static int F_179 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 3 ] ;
unsigned char * V_289 ;
unsigned long V_290 ;
int V_15 = 0 ;
V_289 = F_177 ( V_66 , V_172 ) ;
if ( ! V_289 )
return - V_182 ;
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
V_290 = V_4 -> V_32 -> V_65 ( V_4 -> V_34 ,
V_289 , V_66 ) ;
if ( V_290 < 4 ||
V_289 [ 0 ] != ( V_36 | 1 ) << 2 ||
V_289 [ 1 ] != V_37 ||
V_289 [ 2 ] != 0 ) {
F_12 (KERN_WARNING PFX L_84
L_85 ) ;
V_15 = - V_159 ;
goto V_31;
}
if ( V_289 [ 3 ] & V_293 )
goto V_31;
V_6 [ 0 ] = V_36 << 2 ;
V_6 [ 1 ] = V_74 ;
V_6 [ 2 ] = V_289 [ 3 ] | V_293 ;
V_4 -> V_32 -> V_33 ( V_4 -> V_34 , V_6 , 3 ) ;
V_15 = F_173 ( V_4 ) ;
if ( V_15 ) {
F_12 (KERN_WARNING PFX L_86
L_87
L_83 ) ;
goto V_31;
}
V_290 = V_4 -> V_32 -> V_65 ( V_4 -> V_34 ,
V_289 , V_66 ) ;
if ( V_290 < 3 ||
V_289 [ 0 ] != ( V_36 | 1 ) << 2 ||
V_289 [ 1 ] != V_74 ) {
F_12 (KERN_WARNING PFX L_88
L_89 ) ;
V_15 = - V_159 ;
goto V_31;
}
if ( V_289 [ 2 ] != 0 )
V_15 = - V_294 ;
V_31:
F_118 ( V_289 ) ;
return V_15 ;
}
static int F_180 ( struct V_295 * V_296 , void * V_163 )
{
struct V_4 * V_138 = V_296 -> V_297 ;
return F_181 ( V_296 , L_90 , V_298 [ V_138 -> V_135 ] ) ;
}
static int F_182 ( struct V_299 * V_299 , struct V_300 * V_300 )
{
return F_183 ( V_300 , F_180 , F_184 ( V_299 ) ) ;
}
static int F_185 ( struct V_295 * V_296 , void * V_163 )
{
struct V_4 * V_138 = V_296 -> V_297 ;
F_181 ( V_296 , L_91 ,
V_138 -> V_49 && ! V_138 -> V_50 ) ;
F_181 ( V_296 , L_92 ,
F_186 ( V_138 , V_123 ) ) ;
F_181 ( V_296 , L_93 ,
F_186 ( V_138 , V_121 ) ) ;
F_181 ( V_296 , L_94 ,
F_186 ( V_138 , V_88 ) ) ;
F_181 ( V_296 , L_95 ,
F_186 ( V_138 , V_124 ) ) ;
F_181 ( V_296 , L_96 ,
F_186 ( V_138 , V_86 ) ) ;
F_181 ( V_296 , L_97 ,
F_186 ( V_138 , V_301 ) ) ;
F_181 ( V_296 , L_98 ,
F_186 ( V_138 , V_84 ) ) ;
F_181 ( V_296 , L_99 ,
F_186 ( V_138 , V_82 ) ) ;
F_181 ( V_296 , L_100 ,
F_186 ( V_138 , V_72 ) ) ;
F_181 ( V_296 , L_101 ,
F_186 ( V_138 , V_55 ) ) ;
F_181 ( V_296 , L_102 ,
F_186 ( V_138 , V_73 ) ) ;
return 0 ;
}
static int F_187 ( struct V_299 * V_299 , struct V_300 * V_300 )
{
return F_183 ( V_300 , F_185 , F_184 ( V_299 ) ) ;
}
static int F_188 ( struct V_295 * V_296 , void * V_163 )
{
struct V_4 * V_138 = V_296 -> V_297 ;
return F_181 ( V_296 ,
L_103 ,
V_298 [ V_138 -> V_135 ] ,
V_302 [ V_138 -> V_126 . V_187 ] ,
V_138 -> V_126 . V_149 ,
V_138 -> V_126 . V_150 ,
V_138 -> V_126 . V_155 ,
V_138 -> V_126 . V_152 ,
V_138 -> V_49 ,
V_138 -> V_191 ) ;
}
static int F_189 ( struct V_299 * V_299 , struct V_300 * V_300 )
{
return F_183 ( V_300 , F_188 , F_184 ( V_299 ) ) ;
}
static int F_190 ( struct V_4 * V_4 )
{
V_4 -> V_54 = ( ( V_4 -> V_54 & ~ V_63 ) |
V_56 ) ;
return 1 ;
}
static void F_191 ( struct V_4 * V_4 )
{
struct V_303 * V_304 = & V_4 -> V_292 ;
if ( V_304 -> V_305 == V_306 ) {
if ( V_304 -> V_292 == V_307 &&
V_304 -> V_308 == V_309 &&
V_304 -> V_310 == V_311 ) {
V_4 -> V_64 =
F_190 ;
} else if ( F_192 ( V_304 ) < 1 ||
( F_192 ( V_304 ) == 1 &&
F_193 ( V_304 ) < 5 ) ) {
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
V_6 -> V_11 [ 2 ] = V_312 ;
V_6 -> V_13 = 3 ;
V_4 -> V_9 = NULL ;
F_3 ( V_4 , V_6 ) ;
}
static int F_195 ( struct V_1 * V_313 ,
unsigned long V_314 ,
void * V_315 )
{
struct V_4 * V_4 = V_315 ;
unsigned char * V_12 = V_4 -> V_9 -> V_12 ;
unsigned int V_316 = V_4 -> V_9 -> V_35 ;
if ( V_316 >= 8 &&
( V_12 [ 0 ] >> 2 ) == V_317 &&
V_12 [ 1 ] == V_318 &&
V_12 [ 7 ] == 0x3A ) {
F_194 ( V_4 ) ;
return V_319 ;
}
return V_320 ;
}
static void
F_196 ( struct V_4 * V_4 )
{
struct V_303 * V_304 = & V_4 -> V_292 ;
if ( V_304 -> V_305 == V_306 &&
V_4 -> V_135 == V_136 )
F_1 ( & V_321 ) ;
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
struct V_4 * V_142 ;
int V_168 ;
for ( V_168 = 0 ; ; V_168 ++ ) {
if ( ! V_322 [ V_168 ] . V_323 )
break;
#ifdef F_203
if ( F_204 ( V_322 [ V_168 ] . V_323 ) )
continue;
#endif
V_142 = F_112 () ;
if ( ! V_142 )
return;
V_142 -> V_140 = V_324 ;
V_142 -> V_135 = V_322 [ V_168 ] . type ;
V_142 -> V_189 = F_86 ;
V_142 -> V_126 . V_149 = V_322 [ V_168 ] . V_323 ;
V_142 -> V_126 . V_187 = V_202 ;
V_142 -> V_126 . V_148 = NULL ;
V_142 -> V_126 . V_150 = V_190 ;
V_142 -> V_126 . V_155 = V_190 ;
V_142 -> V_126 . V_152 = 0 ;
if ( F_117 ( V_142 ) == 0 ) {
if ( ( F_119 ( V_142 ) ) == 0 ) {
F_12 (KERN_INFO PFX L_104
L_105 ,
si_to_str[info->si_type],
addr_space_to_str[info->io.addr_type],
info->io.addr_data) ;
} else
F_120 ( V_142 ) ;
} else {
F_118 ( V_142 ) ;
}
}
}
static int F_205 ( struct V_4 * V_142 )
{
struct V_4 * V_192 ;
F_206 (e, &smi_infos, link) {
if ( V_192 -> V_126 . V_187 != V_142 -> V_126 . V_187 )
continue;
if ( V_192 -> V_126 . V_149 == V_142 -> V_126 . V_149 )
return 0 ;
}
return 1 ;
}
static int F_117 ( struct V_4 * V_131 )
{
int V_15 = 0 ;
F_12 (KERN_INFO PFX L_106 ,
ipmi_addr_src_to_str[new_smi->addr_source],
si_to_str[new_smi->si_type]) ;
F_121 ( & V_194 ) ;
if ( ! F_205 ( V_131 ) ) {
F_12 ( V_325 L_107 ) ;
V_15 = - V_326 ;
goto V_327;
}
F_12 ( V_325 L_108 ) ;
V_131 -> V_7 = NULL ;
V_131 -> V_34 = NULL ;
V_131 -> V_32 = NULL ;
F_34 ( & V_131 -> V_25 , & V_328 ) ;
V_327:
F_123 ( & V_194 ) ;
return V_15 ;
}
static int F_119 ( struct V_4 * V_131 )
{
int V_15 = 0 ;
int V_168 ;
F_12 (KERN_INFO PFX L_109
L_110
L_111 ,
ipmi_addr_src_to_str[new_smi->addr_source],
si_to_str[new_smi->si_type],
addr_space_to_str[new_smi->io.addr_type],
new_smi->io.addr_data,
new_smi->slave_addr, new_smi->irq) ;
switch ( V_131 -> V_135 ) {
case V_200 :
V_131 -> V_32 = & V_265 ;
break;
case V_201 :
V_131 -> V_32 = & V_329 ;
break;
case V_136 :
V_131 -> V_32 = & V_330 ;
break;
default:
V_15 = - V_160 ;
goto V_327;
}
V_131 -> V_34 = F_177 ( V_131 -> V_32 -> V_316 () , V_172 ) ;
if ( ! V_131 -> V_34 ) {
F_12 (KERN_ERR PFX
L_112 ) ;
V_15 = - V_182 ;
goto V_327;
}
V_131 -> V_154 = V_131 -> V_32 -> V_331 ( V_131 -> V_34 ,
& V_131 -> V_126 ) ;
V_15 = V_131 -> V_189 ( V_131 ) ;
if ( V_15 ) {
F_12 (KERN_ERR PFX L_113 ) ;
goto V_327;
}
if ( V_131 -> V_32 -> V_332 ( V_131 -> V_34 ) ) {
if ( V_131 -> V_140 )
F_12 (KERN_INFO PFX L_114 ) ;
V_15 = - V_156 ;
goto V_327;
}
V_15 = F_176 ( V_131 ) ;
if ( V_15 ) {
if ( V_131 -> V_140 )
F_12 (KERN_INFO PFX L_115
L_116 ) ;
goto V_327;
}
F_197 ( V_131 ) ;
F_198 ( V_131 ) ;
F_207 ( & ( V_131 -> V_22 ) ) ;
F_207 ( & ( V_131 -> V_20 ) ) ;
V_131 -> V_9 = NULL ;
F_30 ( & V_131 -> V_89 , 0 ) ;
V_131 -> V_95 = false ;
for ( V_168 = 0 ; V_168 < V_333 ; V_168 ++ )
F_30 ( & V_131 -> V_334 [ V_168 ] , 0 ) ;
V_131 -> V_50 = true ;
F_30 ( & V_131 -> V_51 , 0 ) ;
F_30 ( & V_131 -> V_113 , 0 ) ;
V_131 -> V_105 = V_335 ;
V_335 ++ ;
V_15 = F_179 ( V_131 ) ;
if ( V_15 == 0 )
V_131 -> V_115 = true ;
F_16 ( V_131 ) ;
if ( V_131 -> V_49 )
V_131 -> V_38 = V_69 ;
if ( ! V_131 -> V_70 ) {
V_131 -> V_262 = F_208 ( L_117 ,
V_131 -> V_105 ) ;
if ( ! V_131 -> V_262 ) {
F_12 (KERN_ERR PFX
L_118 ) ;
goto V_327;
}
V_131 -> V_70 = & V_131 -> V_262 -> V_70 ;
V_131 -> V_70 -> V_336 = & V_337 . V_336 ;
V_15 = F_209 ( V_131 -> V_262 ) ;
if ( V_15 ) {
F_12 (KERN_ERR PFX
L_119
L_120 ,
rv) ;
goto V_327;
}
V_131 -> V_338 = true ;
}
V_15 = F_210 ( & V_32 ,
V_131 ,
& V_131 -> V_292 ,
V_131 -> V_70 ,
L_121 ,
V_131 -> V_191 ) ;
if ( V_15 ) {
F_139 ( V_131 -> V_70 , L_122 ,
V_15 ) ;
goto V_339;
}
V_15 = F_211 ( V_131 -> V_7 , L_123 ,
& V_340 ,
V_131 ) ;
if ( V_15 ) {
F_139 ( V_131 -> V_70 , L_124 , V_15 ) ;
goto V_339;
}
V_15 = F_211 ( V_131 -> V_7 , L_125 ,
& V_341 ,
V_131 ) ;
if ( V_15 ) {
F_139 ( V_131 -> V_70 , L_124 , V_15 ) ;
goto V_339;
}
V_15 = F_211 ( V_131 -> V_7 , L_126 ,
& V_342 ,
V_131 ) ;
if ( V_15 ) {
F_139 ( V_131 -> V_70 , L_124 , V_15 ) ;
goto V_339;
}
F_71 ( V_131 -> V_70 , L_127 ,
V_298 [ V_131 -> V_135 ] ) ;
return 0 ;
V_339:
F_212 ( & V_131 -> V_51 ) ;
F_199 ( V_131 ) ;
V_327:
V_131 -> V_50 = true ;
if ( V_131 -> V_7 ) {
F_213 ( V_131 -> V_7 ) ;
V_131 -> V_7 = NULL ;
}
if ( V_131 -> V_145 ) {
V_131 -> V_145 ( V_131 ) ;
V_131 -> V_145 = NULL ;
}
F_214 () ;
if ( V_131 -> V_34 ) {
if ( V_131 -> V_32 )
V_131 -> V_32 -> V_343 ( V_131 -> V_34 ) ;
F_118 ( V_131 -> V_34 ) ;
V_131 -> V_34 = NULL ;
}
if ( V_131 -> V_275 ) {
V_131 -> V_275 ( V_131 ) ;
V_131 -> V_275 = NULL ;
}
if ( V_131 -> V_157 ) {
V_131 -> V_157 ( V_131 ) ;
V_131 -> V_157 = NULL ;
}
if ( V_131 -> V_338 ) {
F_215 ( V_131 -> V_262 ) ;
V_131 -> V_338 = false ;
}
return V_15 ;
}
static int F_216 ( void )
{
int V_168 ;
char * V_175 ;
int V_15 ;
struct V_4 * V_192 ;
enum V_344 type = V_345 ;
if ( V_346 )
return 0 ;
V_346 = 1 ;
if ( V_347 ) {
V_15 = F_217 ( & V_337 ) ;
if ( V_15 ) {
F_12 (KERN_ERR PFX L_128
L_129 , rv) ;
return V_15 ;
}
}
V_175 = V_348 ;
if ( * V_175 != '\0' ) {
for ( V_168 = 0 ; ( V_168 < V_196 ) && ( * V_175 != '\0' ) ; V_168 ++ ) {
V_135 [ V_168 ] = V_175 ;
V_175 = strchr ( V_175 , ',' ) ;
if ( V_175 ) {
* V_175 = '\0' ;
V_175 ++ ;
} else {
break;
}
}
}
F_12 ( V_349 L_130 ) ;
if ( ! F_124 () )
return 0 ;
#ifdef F_218
if ( V_350 ) {
V_15 = F_219 ( & V_351 ) ;
if ( V_15 )
F_12 (KERN_ERR PFX L_128
L_131 , rv) ;
else
V_352 = true ;
}
#endif
#ifdef F_220
if ( V_353 ) {
F_221 ( & V_354 ) ;
V_355 = true ;
}
#endif
#ifdef F_222
if ( V_356 )
F_148 () ;
#endif
#ifdef F_220
if ( V_353 )
F_132 () ;
#endif
#ifdef F_223
F_224 ( & V_357 ) ;
V_358 = true ;
V_359 = 0 ;
#endif
F_121 ( & V_194 ) ;
F_206 (e, &smi_infos, link) {
if ( V_192 -> V_49 && ( ! type || V_192 -> V_140 == type ) ) {
if ( ! F_119 ( V_192 ) ) {
type = V_192 -> V_140 ;
}
}
}
if ( type ) {
F_123 ( & V_194 ) ;
return 0 ;
}
F_206 (e, &smi_infos, link) {
if ( ! V_192 -> V_49 && ( ! type || V_192 -> V_140 == type ) ) {
if ( ! F_119 ( V_192 ) ) {
type = V_192 -> V_140 ;
}
}
}
F_123 ( & V_194 ) ;
if ( type )
return 0 ;
if ( V_359 ) {
F_121 ( & V_194 ) ;
if ( F_8 ( & V_328 ) ) {
F_123 ( & V_194 ) ;
F_202 () ;
} else
F_123 ( & V_194 ) ;
}
F_121 ( & V_194 ) ;
if ( V_360 && F_8 ( & V_328 ) ) {
F_123 ( & V_194 ) ;
F_225 () ;
F_12 (KERN_WARNING PFX
L_132 ) ;
return - V_156 ;
} else {
F_123 ( & V_194 ) ;
return 0 ;
}
}
static void F_120 ( struct V_4 * V_361 )
{
int V_15 = 0 ;
unsigned long V_94 ;
if ( ! V_361 )
return;
F_9 ( & V_361 -> V_25 ) ;
F_212 ( & V_361 -> V_51 ) ;
F_199 ( V_361 ) ;
F_36 ( & V_361 -> V_97 , V_94 ) ;
while ( V_361 -> V_9 || ( V_361 -> V_38 != V_57 ) ) {
F_37 ( & V_361 -> V_97 , V_94 ) ;
F_52 ( V_361 ) ;
F_174 ( 1 ) ;
F_36 ( & V_361 -> V_97 , V_94 ) ;
}
F_19 ( V_361 ) ;
F_37 ( & V_361 -> V_97 , V_94 ) ;
while ( V_361 -> V_9 || ( V_361 -> V_38 != V_57 ) ) {
F_52 ( V_361 ) ;
F_174 ( 1 ) ;
}
if ( V_361 -> V_145 )
V_361 -> V_145 ( V_361 ) ;
while ( V_361 -> V_9 || ( V_361 -> V_38 != V_57 ) ) {
F_52 ( V_361 ) ;
F_174 ( 1 ) ;
}
if ( V_361 -> V_7 )
V_15 = F_213 ( V_361 -> V_7 ) ;
if ( V_15 ) {
F_12 (KERN_ERR PFX L_133 ,
rv) ;
}
if ( V_361 -> V_32 )
V_361 -> V_32 -> V_343 ( V_361 -> V_34 ) ;
F_118 ( V_361 -> V_34 ) ;
if ( V_361 -> V_275 )
V_361 -> V_275 ( V_361 ) ;
if ( V_361 -> V_157 )
V_361 -> V_157 ( V_361 ) ;
if ( V_361 -> V_338 )
F_215 ( V_361 -> V_262 ) ;
F_118 ( V_361 ) ;
}
static void F_225 ( void )
{
struct V_4 * V_192 , * V_193 ;
if ( ! V_346 )
return;
#ifdef F_218
if ( V_352 )
F_226 ( & V_351 ) ;
#endif
#ifdef F_220
if ( V_355 )
F_227 ( & V_354 ) ;
#endif
#ifdef F_223
if ( V_358 )
F_228 ( & V_357 ) ;
#endif
F_229 ( & V_337 ) ;
F_121 ( & V_194 ) ;
F_122 (e, tmp_e, &smi_infos, link)
F_120 ( V_192 ) ;
F_123 ( & V_194 ) ;
}
