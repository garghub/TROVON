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
static inline void F_17 ( struct V_4 * V_4 )
{
if ( ( V_4 -> V_44 ) && ( ! V_4 -> V_45 ) ) {
F_15 ( V_4 ) ;
V_4 -> V_45 = 1 ;
if ( ! F_18 ( & V_4 -> V_46 ) )
F_19 ( & V_4 -> V_47 ,
V_48 + V_49 ) ;
}
}
static inline void F_20 ( struct V_4 * V_4 )
{
if ( ( V_4 -> V_44 ) && ( V_4 -> V_45 ) ) {
F_14 ( V_4 ) ;
V_4 -> V_45 = 0 ;
}
}
static void F_21 ( struct V_4 * V_4 )
{
V_50:
if ( V_4 -> V_51 & V_42 ) {
F_22 ( V_4 , V_52 ) ;
F_16 ( V_4 ) ;
V_4 -> V_51 &= ~ V_42 ;
F_23 ( V_4 -> V_7 ) ;
} else if ( V_4 -> V_51 & V_53 ) {
V_4 -> V_9 = F_24 () ;
if ( ! V_4 -> V_9 ) {
F_17 ( V_4 ) ;
V_4 -> V_38 = V_54 ;
return;
}
F_20 ( V_4 ) ;
V_4 -> V_9 -> V_12 [ 0 ] = ( V_36 << 2 ) ;
V_4 -> V_9 -> V_12 [ 1 ] = V_55 ;
V_4 -> V_9 -> V_35 = 2 ;
V_4 -> V_32 -> V_33 (
V_4 -> V_34 ,
V_4 -> V_9 -> V_12 ,
V_4 -> V_9 -> V_35 ) ;
V_4 -> V_38 = V_56 ;
} else if ( V_4 -> V_51 & V_57 ) {
V_4 -> V_9 = F_24 () ;
if ( ! V_4 -> V_9 ) {
F_17 ( V_4 ) ;
V_4 -> V_38 = V_54 ;
return;
}
F_20 ( V_4 ) ;
V_4 -> V_9 -> V_12 [ 0 ] = ( V_36 << 2 ) ;
V_4 -> V_9 -> V_12 [ 1 ] = V_58 ;
V_4 -> V_9 -> V_35 = 2 ;
V_4 -> V_32 -> V_33 (
V_4 -> V_34 ,
V_4 -> V_9 -> V_12 ,
V_4 -> V_9 -> V_35 ) ;
V_4 -> V_38 = V_59 ;
} else if ( V_4 -> V_51 & V_60 &&
V_4 -> V_61 ) {
if ( V_4 -> V_61 ( V_4 ) )
goto V_50;
} else
V_4 -> V_38 = V_54 ;
}
static void F_25 ( struct V_4 * V_4 )
{
struct V_5 * V_6 ;
#ifdef F_7
struct V_18 V_19 ;
F_11 ( & V_19 ) ;
F_12 ( V_26 L_2 , V_19 . V_27 , V_19 . V_28 ) ;
#endif
switch ( V_4 -> V_38 ) {
case V_54 :
if ( ! V_4 -> V_9 )
break;
V_4 -> V_9 -> V_13
= V_4 -> V_32 -> V_62 (
V_4 -> V_34 ,
V_4 -> V_9 -> V_11 ,
V_63 ) ;
V_6 = V_4 -> V_9 ;
V_4 -> V_9 = NULL ;
F_3 ( V_4 , V_6 ) ;
break;
case V_64 :
{
unsigned char V_6 [ 4 ] ;
unsigned int V_65 ;
V_65 = V_4 -> V_32 -> V_62 ( V_4 -> V_34 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 ) {
V_4 -> V_38 = V_54 ;
} else if ( V_65 < 4 ) {
V_4 -> V_38 = V_54 ;
} else {
V_4 -> V_51 = V_6 [ 3 ] ;
F_21 ( V_4 ) ;
}
break;
}
case V_43 :
case V_66 :
{
unsigned char V_6 [ 3 ] ;
V_4 -> V_32 -> V_62 ( V_4 -> V_34 , V_6 , 3 ) ;
if ( V_6 [ 2 ] != 0 ) {
F_26 ( V_4 -> V_67 ,
L_3 , V_6 [ 2 ] ) ;
}
if ( V_4 -> V_38 == V_66 )
F_14 ( V_4 ) ;
else
V_4 -> V_38 = V_54 ;
break;
}
case V_59 :
{
V_4 -> V_9 -> V_13
= V_4 -> V_32 -> V_62 (
V_4 -> V_34 ,
V_4 -> V_9 -> V_11 ,
V_63 ) ;
V_6 = V_4 -> V_9 ;
V_4 -> V_9 = NULL ;
if ( V_6 -> V_11 [ 2 ] != 0 ) {
V_6 -> V_68 ( V_6 ) ;
V_4 -> V_51 &= ~ V_57 ;
F_21 ( V_4 ) ;
} else {
F_22 ( V_4 , V_69 ) ;
F_21 ( V_4 ) ;
F_3 ( V_4 , V_6 ) ;
}
break;
}
case V_56 :
{
V_4 -> V_9 -> V_13
= V_4 -> V_32 -> V_62 (
V_4 -> V_34 ,
V_4 -> V_9 -> V_11 ,
V_63 ) ;
V_6 = V_4 -> V_9 ;
V_4 -> V_9 = NULL ;
if ( V_6 -> V_11 [ 2 ] != 0 ) {
V_6 -> V_68 ( V_6 ) ;
V_4 -> V_51 &= ~ V_53 ;
F_21 ( V_4 ) ;
} else {
F_22 ( V_4 , V_70 ) ;
F_21 ( V_4 ) ;
F_3 ( V_4 , V_6 ) ;
}
break;
}
case V_39 :
{
unsigned char V_6 [ 4 ] ;
V_4 -> V_32 -> V_62 ( V_4 -> V_34 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 ) {
F_26 ( V_4 -> V_67 ,
L_4 , V_6 [ 2 ] ) ;
F_26 ( V_4 -> V_67 ,
L_5 ) ;
V_4 -> V_38 = V_54 ;
} else {
V_6 [ 0 ] = ( V_36 << 2 ) ;
V_6 [ 1 ] = V_71 ;
V_6 [ 2 ] = ( V_6 [ 3 ] |
V_72 |
V_73 ) ;
V_4 -> V_32 -> V_33 (
V_4 -> V_34 , V_6 , 3 ) ;
V_4 -> V_38 = V_74 ;
}
break;
}
case V_74 :
{
unsigned char V_6 [ 4 ] ;
V_4 -> V_32 -> V_62 ( V_4 -> V_34 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 ) {
F_26 ( V_4 -> V_67 ,
L_6 , V_6 [ 2 ] ) ;
F_26 ( V_4 -> V_67 ,
L_5 ) ;
} else
V_4 -> V_45 = 0 ;
V_4 -> V_38 = V_54 ;
break;
}
case V_40 :
{
unsigned char V_6 [ 4 ] ;
V_4 -> V_32 -> V_62 ( V_4 -> V_34 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 ) {
F_26 ( V_4 -> V_67 , L_7
L_8 ) ;
V_4 -> V_38 = V_54 ;
} else {
V_6 [ 0 ] = ( V_36 << 2 ) ;
V_6 [ 1 ] = V_71 ;
V_6 [ 2 ] = ( V_6 [ 3 ] &
~ ( V_72 |
V_73 ) ) ;
V_4 -> V_32 -> V_33 (
V_4 -> V_34 , V_6 , 3 ) ;
V_4 -> V_38 = V_75 ;
}
break;
}
case V_75 :
{
unsigned char V_6 [ 4 ] ;
V_4 -> V_32 -> V_62 ( V_4 -> V_34 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 ) {
F_26 ( V_4 -> V_67 , L_7
L_9 ) ;
}
V_4 -> V_38 = V_54 ;
break;
}
}
}
static enum V_14 F_27 ( struct V_4 * V_4 ,
int time )
{
enum V_14 V_14 ;
V_76:
V_14 = V_4 -> V_32 -> V_77 ( V_4 -> V_34 , time ) ;
time = 0 ;
while ( V_14 == V_30 )
V_14 = V_4 -> V_32 -> V_77 ( V_4 -> V_34 , 0 ) ;
if ( V_14 == V_78 ) {
F_22 ( V_4 , V_79 ) ;
F_25 ( V_4 ) ;
V_14 = V_4 -> V_32 -> V_77 ( V_4 -> V_34 , 0 ) ;
} else if ( V_14 == V_80 ) {
F_22 ( V_4 , V_81 ) ;
V_4 -> V_38 = V_54 ;
if ( V_4 -> V_9 != NULL ) {
F_5 ( V_4 , V_10 ) ;
}
V_14 = V_4 -> V_32 -> V_77 ( V_4 -> V_34 , 0 ) ;
}
if ( F_28 ( V_4 -> V_7 ) && V_14 == V_82 ) {
unsigned char V_6 [ 2 ] ;
F_22 ( V_4 , V_83 ) ;
V_6 [ 0 ] = ( V_36 << 2 ) ;
V_6 [ 1 ] = V_84 ;
V_4 -> V_32 -> V_33 (
V_4 -> V_34 , V_6 , 2 ) ;
V_4 -> V_38 = V_64 ;
goto V_76;
}
if ( V_14 == V_23 ) {
F_22 ( V_4 , V_85 ) ;
V_14 = F_6 ( V_4 ) ;
if ( V_14 != V_23 )
goto V_76;
}
if ( ( V_14 == V_23 )
&& ( F_18 ( & V_4 -> V_86 ) ) ) {
F_29 ( & V_4 -> V_86 , 0 ) ;
V_4 -> V_9 = F_24 () ;
if ( ! V_4 -> V_9 )
goto V_31;
V_4 -> V_9 -> V_12 [ 0 ] = ( V_36 << 2 ) ;
V_4 -> V_9 -> V_12 [ 1 ] = V_58 ;
V_4 -> V_9 -> V_35 = 2 ;
V_4 -> V_32 -> V_33 (
V_4 -> V_34 ,
V_4 -> V_9 -> V_12 ,
V_4 -> V_9 -> V_35 ) ;
V_4 -> V_38 = V_59 ;
goto V_76;
}
V_31:
return V_14 ;
}
static void F_30 ( void * V_87 ,
struct V_5 * V_6 ,
int V_88 )
{
struct V_4 * V_4 = V_87 ;
enum V_14 V_89 ;
unsigned long V_90 ;
#ifdef F_7
struct V_18 V_19 ;
#endif
if ( F_18 ( & V_4 -> V_46 ) ) {
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
if ( V_4 -> V_91 ) {
F_31 ( & ( V_6 -> V_25 ) , & ( V_4 -> V_22 ) ) ;
V_89 = F_27 ( V_4 , 0 ) ;
while ( V_89 != V_23 ) {
F_32 ( V_92 ) ;
V_89 = F_27 ( V_4 ,
V_92 ) ;
}
return;
}
F_33 ( & V_4 -> V_93 , V_90 ) ;
if ( V_88 > 0 )
F_31 ( & V_6 -> V_25 , & V_4 -> V_20 ) ;
else
F_31 ( & V_6 -> V_25 , & V_4 -> V_22 ) ;
if ( V_4 -> V_38 == V_54 && V_4 -> V_9 == NULL ) {
V_4 -> V_94 = V_48 ;
F_19 ( & V_4 -> V_47 , V_48 + V_49 ) ;
if ( V_4 -> V_95 )
F_34 ( V_4 -> V_95 ) ;
F_6 ( V_4 ) ;
F_27 ( V_4 , 0 ) ;
}
F_35 ( & V_4 -> V_93 , V_90 ) ;
}
static void F_36 ( void * V_87 , int V_96 )
{
struct V_4 * V_4 = V_87 ;
enum V_14 V_89 ;
V_4 -> V_91 = V_96 ;
if ( V_96 ) {
V_89 = F_27 ( V_4 , 0 ) ;
while ( V_89 != V_23 ) {
F_32 ( V_92 ) ;
V_89 = F_27 ( V_4 ,
V_92 ) ;
}
}
}
static inline void F_37 ( struct V_97 * V_98 )
{
V_98 -> V_99 = - 1 ;
}
static inline int F_38 ( struct V_97 * V_98 )
{
return V_98 -> V_99 != - 1 ;
}
static int F_39 ( enum V_14 V_100 ,
const struct V_4 * V_4 ,
struct V_97 * V_101 )
{
unsigned int V_102 = 0 ;
if ( V_4 -> V_103 < V_104 )
V_102 = V_105 [ V_4 -> V_103 ] ;
if ( V_102 == 0 || V_100 != V_106 )
F_37 ( V_101 ) ;
else if ( ! F_38 ( V_101 ) ) {
F_40 ( V_101 ) ;
F_41 ( V_101 , V_102 * V_107 ) ;
} else {
struct V_97 V_108 ;
F_40 ( & V_108 ) ;
if ( F_42 ( F_43 ( & V_108 , V_101 ) > 0 ) ) {
F_37 ( V_101 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_44 ( void * V_12 )
{
struct V_4 * V_4 = V_12 ;
unsigned long V_90 ;
enum V_14 V_100 ;
struct V_97 V_101 ;
F_37 ( & V_101 ) ;
F_45 ( V_109 , 19 ) ;
while ( ! F_46 () ) {
int V_110 ;
F_33 ( & ( V_4 -> V_93 ) , V_90 ) ;
V_100 = F_27 ( V_4 , 0 ) ;
F_35 ( & ( V_4 -> V_93 ) , V_90 ) ;
V_110 = F_39 ( V_100 , V_4 ,
& V_101 ) ;
if ( V_100 == V_30 )
;
else if ( V_100 == V_106 && V_110 )
F_47 () ;
else if ( V_100 == V_23 )
F_48 ( 100 ) ;
else
F_48 ( 1 ) ;
}
return 0 ;
}
static void F_49 ( void * V_87 )
{
struct V_4 * V_4 = V_87 ;
unsigned long V_90 = 0 ;
int V_91 = V_4 -> V_91 ;
F_32 ( 10 ) ;
if ( ! V_91 )
F_33 ( & V_4 -> V_93 , V_90 ) ;
F_27 ( V_4 , 10 ) ;
if ( ! V_91 )
F_35 ( & V_4 -> V_93 , V_90 ) ;
}
static void F_50 ( void * V_87 )
{
struct V_4 * V_4 = V_87 ;
if ( F_18 ( & V_4 -> V_46 ) ||
! V_4 -> V_111 )
return;
F_29 ( & V_4 -> V_86 , 1 ) ;
}
static void F_51 ( unsigned long V_12 )
{
struct V_4 * V_4 = (struct V_4 * ) V_12 ;
enum V_14 V_100 ;
unsigned long V_90 ;
unsigned long V_112 ;
long V_113 ;
long V_114 ;
#ifdef F_7
struct V_18 V_19 ;
#endif
F_33 ( & ( V_4 -> V_93 ) , V_90 ) ;
#ifdef F_7
F_11 ( & V_19 ) ;
F_12 ( V_26 L_11 , V_19 . V_27 , V_19 . V_28 ) ;
#endif
V_112 = V_48 ;
V_113 = ( ( ( long ) V_112 - ( long ) V_4 -> V_94 )
* V_115 ) ;
V_100 = F_27 ( V_4 , V_113 ) ;
F_35 ( & ( V_4 -> V_93 ) , V_90 ) ;
V_4 -> V_94 = V_112 ;
if ( ( V_4 -> V_44 ) && ( ! V_4 -> V_45 ) ) {
V_114 = V_48 + V_49 ;
F_22 ( V_4 , V_116 ) ;
goto V_117;
}
if ( V_100 == V_106 ) {
F_22 ( V_4 , V_118 ) ;
V_114 = V_48 + 1 ;
} else {
F_22 ( V_4 , V_116 ) ;
V_114 = V_48 + V_49 ;
}
V_117:
if ( V_100 != V_23 )
F_19 ( & ( V_4 -> V_47 ) , V_114 ) ;
}
static T_1 F_52 ( int V_44 , void * V_12 )
{
struct V_4 * V_4 = V_12 ;
unsigned long V_90 ;
#ifdef F_7
struct V_18 V_19 ;
#endif
F_33 ( & ( V_4 -> V_93 ) , V_90 ) ;
F_22 ( V_4 , V_119 ) ;
#ifdef F_7
F_11 ( & V_19 ) ;
F_12 ( V_26 L_12 , V_19 . V_27 , V_19 . V_28 ) ;
#endif
F_27 ( V_4 , 0 ) ;
F_35 ( & ( V_4 -> V_93 ) , V_90 ) ;
return V_120 ;
}
static T_1 F_53 ( int V_44 , void * V_12 )
{
struct V_4 * V_4 = V_12 ;
V_4 -> V_121 . V_122 ( & V_4 -> V_121 , V_123 ,
V_124
| V_125 ) ;
return F_52 ( V_44 , V_12 ) ;
}
static int F_54 ( void * V_87 ,
T_2 V_7 )
{
struct V_4 * V_126 = V_87 ;
int V_127 = 0 ;
V_126 -> V_7 = V_7 ;
if ( V_126 -> V_128 )
V_126 -> V_128 ( V_126 ) ;
F_55 ( & V_126 -> V_47 , F_51 , ( long ) V_126 ) ;
V_126 -> V_94 = V_48 ;
F_19 ( & V_126 -> V_47 , V_48 + V_49 ) ;
if ( V_126 -> V_103 < V_129 )
V_127 = V_130 [ V_126 -> V_103 ] ;
else if ( ( V_126 -> V_131 != V_132 ) && ( ! V_126 -> V_44 ) )
V_127 = 1 ;
if ( V_127 ) {
V_126 -> V_95 = F_56 ( F_44 , V_126 ,
L_13 , V_126 -> V_103 ) ;
if ( F_57 ( V_126 -> V_95 ) ) {
F_58 ( V_126 -> V_67 , L_14
L_15
L_16 ,
F_59 ( V_126 -> V_95 ) ) ;
V_126 -> V_95 = NULL ;
}
}
return 0 ;
}
static int F_60 ( void * V_87 , struct V_133 * V_12 )
{
struct V_4 * V_134 = V_87 ;
V_12 -> V_135 = V_134 -> V_136 ;
V_12 -> V_67 = V_134 -> V_67 ;
V_12 -> V_137 = V_134 -> V_137 ;
F_61 ( V_134 -> V_67 ) ;
return 0 ;
}
static void F_62 ( void * V_87 , int V_127 )
{
struct V_4 * V_4 = V_87 ;
if ( ! V_127 )
F_29 ( & V_4 -> V_86 , 0 ) ;
}
static void F_63 ( struct V_4 * V_138 )
{
if ( V_138 -> V_131 == V_132 )
V_138 -> V_121 . V_122 ( & V_138 -> V_121 , V_123 , 0 ) ;
F_64 ( V_138 -> V_44 , V_138 ) ;
}
static int F_65 ( struct V_4 * V_138 )
{
int V_15 ;
if ( ! V_138 -> V_44 )
return 0 ;
if ( V_138 -> V_131 == V_132 ) {
V_15 = F_66 ( V_138 -> V_44 ,
F_53 ,
V_139 | V_140 ,
V_141 ,
V_138 ) ;
if ( ! V_15 )
V_138 -> V_121 . V_122 ( & V_138 -> V_121 , V_123 ,
V_125 ) ;
} else
V_15 = F_66 ( V_138 -> V_44 ,
F_52 ,
V_139 | V_140 ,
V_141 ,
V_138 ) ;
if ( V_15 ) {
F_26 ( V_138 -> V_67 , L_17
L_18 ,
V_141 , V_138 -> V_44 ) ;
V_138 -> V_44 = 0 ;
} else {
V_138 -> V_142 = F_63 ;
F_67 ( V_138 -> V_67 , L_19 , V_138 -> V_44 ) ;
}
return V_15 ;
}
static unsigned char F_68 ( struct V_143 * V_121 , unsigned int V_144 )
{
unsigned int V_145 = V_121 -> V_146 ;
return F_69 ( V_145 + ( V_144 * V_121 -> V_147 ) ) ;
}
static void F_70 ( struct V_143 * V_121 , unsigned int V_144 ,
unsigned char V_148 )
{
unsigned int V_145 = V_121 -> V_146 ;
F_71 ( V_148 , V_145 + ( V_144 * V_121 -> V_147 ) ) ;
}
static unsigned char F_72 ( struct V_143 * V_121 , unsigned int V_144 )
{
unsigned int V_145 = V_121 -> V_146 ;
return ( F_73 ( V_145 + ( V_144 * V_121 -> V_147 ) ) >> V_121 -> V_149 ) & 0xff ;
}
static void F_74 ( struct V_143 * V_121 , unsigned int V_144 ,
unsigned char V_148 )
{
unsigned int V_145 = V_121 -> V_146 ;
F_75 ( V_148 << V_121 -> V_149 , V_145 + ( V_144 * V_121 -> V_147 ) ) ;
}
static unsigned char F_76 ( struct V_143 * V_121 , unsigned int V_144 )
{
unsigned int V_145 = V_121 -> V_146 ;
return ( F_77 ( V_145 + ( V_144 * V_121 -> V_147 ) ) >> V_121 -> V_149 ) & 0xff ;
}
static void F_78 ( struct V_143 * V_121 , unsigned int V_144 ,
unsigned char V_148 )
{
unsigned int V_145 = V_121 -> V_146 ;
F_79 ( V_148 << V_121 -> V_149 , V_145 + ( V_144 * V_121 -> V_147 ) ) ;
}
static void F_80 ( struct V_4 * V_138 )
{
unsigned int V_145 = V_138 -> V_121 . V_146 ;
int V_150 ;
if ( V_145 ) {
for ( V_150 = 0 ; V_150 < V_138 -> V_151 ; V_150 ++ )
F_81 ( V_145 + V_150 * V_138 -> V_121 . V_147 ,
V_138 -> V_121 . V_152 ) ;
}
}
static int F_82 ( struct V_4 * V_138 )
{
unsigned int V_145 = V_138 -> V_121 . V_146 ;
int V_150 ;
if ( ! V_145 )
return - V_153 ;
V_138 -> V_154 = F_80 ;
switch ( V_138 -> V_121 . V_152 ) {
case 1 :
V_138 -> V_121 . V_155 = F_68 ;
V_138 -> V_121 . V_122 = F_70 ;
break;
case 2 :
V_138 -> V_121 . V_155 = F_72 ;
V_138 -> V_121 . V_122 = F_74 ;
break;
case 4 :
V_138 -> V_121 . V_155 = F_76 ;
V_138 -> V_121 . V_122 = F_78 ;
break;
default:
F_26 ( V_138 -> V_67 , L_20 ,
V_138 -> V_121 . V_152 ) ;
return - V_156 ;
}
for ( V_150 = 0 ; V_150 < V_138 -> V_151 ; V_150 ++ ) {
if ( F_83 ( V_145 + V_150 * V_138 -> V_121 . V_147 ,
V_138 -> V_121 . V_152 , V_141 ) == NULL ) {
while ( V_150 -- ) {
F_81 ( V_145 + V_150 * V_138 -> V_121 . V_147 ,
V_138 -> V_121 . V_152 ) ;
}
return - V_157 ;
}
}
return 0 ;
}
static unsigned char F_84 ( struct V_143 * V_121 , unsigned int V_144 )
{
return F_85 ( ( V_121 -> V_145 ) + ( V_144 * V_121 -> V_147 ) ) ;
}
static void F_86 ( struct V_143 * V_121 , unsigned int V_144 ,
unsigned char V_148 )
{
F_87 ( V_148 , ( V_121 -> V_145 ) + ( V_144 * V_121 -> V_147 ) ) ;
}
static unsigned char F_88 ( struct V_143 * V_121 , unsigned int V_144 )
{
return ( F_89 ( ( V_121 -> V_145 ) + ( V_144 * V_121 -> V_147 ) ) >> V_121 -> V_149 )
& 0xff ;
}
static void F_90 ( struct V_143 * V_121 , unsigned int V_144 ,
unsigned char V_148 )
{
F_87 ( V_148 << V_121 -> V_149 , ( V_121 -> V_145 ) + ( V_144 * V_121 -> V_147 ) ) ;
}
static unsigned char F_91 ( struct V_143 * V_121 , unsigned int V_144 )
{
return ( F_92 ( ( V_121 -> V_145 ) + ( V_144 * V_121 -> V_147 ) ) >> V_121 -> V_149 )
& 0xff ;
}
static void F_93 ( struct V_143 * V_121 , unsigned int V_144 ,
unsigned char V_148 )
{
F_94 ( V_148 << V_121 -> V_149 , ( V_121 -> V_145 ) + ( V_144 * V_121 -> V_147 ) ) ;
}
static unsigned char F_95 ( struct V_143 * V_121 , unsigned int V_144 )
{
return ( F_96 ( ( V_121 -> V_145 ) + ( V_144 * V_121 -> V_147 ) ) >> V_121 -> V_149 )
& 0xff ;
}
static void F_97 ( struct V_143 * V_121 , unsigned int V_144 ,
unsigned char V_148 )
{
F_98 ( V_148 << V_121 -> V_149 , ( V_121 -> V_145 ) + ( V_144 * V_121 -> V_147 ) ) ;
}
static void F_99 ( struct V_4 * V_138 )
{
unsigned long V_145 = V_138 -> V_121 . V_146 ;
int V_158 ;
if ( V_138 -> V_121 . V_145 ) {
F_100 ( V_138 -> V_121 . V_145 ) ;
V_158 = ( ( V_138 -> V_151 * V_138 -> V_121 . V_147 )
- ( V_138 -> V_121 . V_147 - V_138 -> V_121 . V_152 ) ) ;
F_101 ( V_145 , V_158 ) ;
}
}
static int F_102 ( struct V_4 * V_138 )
{
unsigned long V_145 = V_138 -> V_121 . V_146 ;
int V_158 ;
if ( ! V_145 )
return - V_153 ;
V_138 -> V_154 = F_99 ;
switch ( V_138 -> V_121 . V_152 ) {
case 1 :
V_138 -> V_121 . V_155 = F_84 ;
V_138 -> V_121 . V_122 = F_86 ;
break;
case 2 :
V_138 -> V_121 . V_155 = F_88 ;
V_138 -> V_121 . V_122 = F_90 ;
break;
case 4 :
V_138 -> V_121 . V_155 = F_91 ;
V_138 -> V_121 . V_122 = F_93 ;
break;
#ifdef F_96
case 8 :
V_138 -> V_121 . V_155 = F_95 ;
V_138 -> V_121 . V_122 = F_97 ;
break;
#endif
default:
F_26 ( V_138 -> V_67 , L_20 ,
V_138 -> V_121 . V_152 ) ;
return - V_156 ;
}
V_158 = ( ( V_138 -> V_151 * V_138 -> V_121 . V_147 )
- ( V_138 -> V_121 . V_147 - V_138 -> V_121 . V_152 ) ) ;
if ( F_103 ( V_145 , V_158 , V_141 ) == NULL )
return - V_157 ;
V_138 -> V_121 . V_145 = F_104 ( V_145 , V_158 ) ;
if ( V_138 -> V_121 . V_145 == NULL ) {
F_101 ( V_145 , V_158 ) ;
return - V_157 ;
}
return 0 ;
}
static int F_105 ( struct V_159 * V_160 , int * V_161 , char * V_162 , char * * V_163 )
{
char * V_164 ;
int V_165 ;
V_164 = strchr ( * V_163 , ',' ) ;
if ( ! V_164 ) {
F_12 (KERN_WARNING PFX L_21 , name) ;
return - V_156 ;
}
* V_164 = '\0' ;
V_164 ++ ;
for ( V_165 = 0 ; V_166 [ V_165 ] . V_162 ; V_165 ++ ) {
if ( strcmp ( * V_163 , V_160 [ V_165 ] . V_162 ) == 0 ) {
* V_161 = V_160 [ V_165 ] . V_161 ;
* V_163 = V_164 ;
return 0 ;
}
}
F_12 (KERN_WARNING PFX L_22 , name, *curr) ;
return - V_156 ;
}
static int F_106 ( const char * V_163 , const char * V_167 ,
const char * V_162 , int * V_161 )
{
char * V_168 ;
if ( strcmp ( V_163 , V_162 ) == 0 ) {
if ( ! V_167 ) {
F_12 (KERN_WARNING PFX
L_23 ,
curr) ;
return - V_156 ;
}
* V_161 = F_107 ( V_167 , & V_168 , 0 ) ;
if ( ( * V_168 != '\0' ) || ( * V_167 == '\0' ) ) {
F_12 (KERN_WARNING PFX
L_24 ,
curr) ;
return - V_156 ;
}
return 1 ;
}
return 0 ;
}
static struct V_4 * F_108 ( void )
{
struct V_4 * V_138 = F_109 ( sizeof( * V_138 ) , V_169 ) ;
if ( V_138 )
F_110 ( & V_138 -> V_93 ) ;
return V_138 ;
}
static int F_111 ( const char * V_161 , struct V_170 * V_171 )
{
char * V_172 = F_112 ( V_161 , V_169 ) ;
int V_15 ;
char * V_21 , * V_163 , * V_164 , * V_168 , * V_173 ;
enum V_174 V_175 ;
enum V_131 V_131 ;
int V_176 ;
unsigned long V_145 ;
int V_147 ;
int V_152 ;
int V_149 ;
int V_44 ;
int V_177 ;
int V_178 ;
int V_65 ;
struct V_4 * V_138 ;
if ( ! V_172 )
return - V_179 ;
V_65 = strlen ( V_172 ) ;
V_178 = V_65 - 1 ;
while ( ( V_178 >= 0 ) && isspace ( V_172 [ V_178 ] ) ) {
V_172 [ V_178 ] = '\0' ;
V_178 -- ;
}
for ( V_163 = V_172 ; V_163 ; V_163 = V_21 ) {
V_147 = 1 ;
V_152 = 1 ;
V_149 = 0 ;
V_44 = 0 ;
V_177 = 0 ;
V_21 = strchr ( V_163 , ':' ) ;
if ( V_21 ) {
* V_21 = '\0' ;
V_21 ++ ;
}
V_15 = F_105 ( V_166 , & V_178 , L_25 , & V_163 ) ;
if ( V_15 )
break;
V_175 = V_178 ;
V_15 = F_105 ( V_180 , & V_178 , L_26 , & V_163 ) ;
if ( V_15 )
break;
V_131 = V_178 ;
V_15 = F_105 ( V_181 , & V_176 , L_27 , & V_163 ) ;
if ( V_15 )
break;
V_164 = strchr ( V_163 , ',' ) ;
if ( V_164 ) {
* V_164 = '\0' ;
V_164 ++ ;
}
V_145 = F_107 ( V_163 , & V_168 , 0 ) ;
if ( ( * V_168 != '\0' ) || ( * V_163 == '\0' ) ) {
F_12 (KERN_WARNING PFX L_28
L_29 , curr) ;
break;
}
while ( V_164 ) {
V_163 = V_164 ;
V_164 = strchr ( V_163 , ',' ) ;
if ( V_164 ) {
* V_164 = '\0' ;
V_164 ++ ;
}
V_173 = strchr ( V_163 , '=' ) ;
if ( V_173 ) {
* V_173 = '\0' ;
V_173 ++ ;
}
V_15 = F_106 ( V_163 , V_173 , L_30 , & V_147 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = F_106 ( V_163 , V_173 , L_31 , & V_152 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = F_106 ( V_163 , V_173 , L_32 , & V_149 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = F_106 ( V_163 , V_173 , L_33 , & V_44 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = F_106 ( V_163 , V_173 , L_34 , & V_177 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = - V_156 ;
F_12 (KERN_WARNING PFX
L_35 ,
curr) ;
goto V_31;
}
if ( V_175 == V_182 ) {
V_138 = F_108 () ;
if ( ! V_138 ) {
V_15 = - V_179 ;
goto V_31;
}
V_138 -> V_136 = V_183 ;
V_138 -> V_131 = V_131 ;
V_138 -> V_121 . V_146 = V_145 ;
V_138 -> V_121 . V_184 = V_176 ;
if ( V_176 == V_185 )
V_138 -> V_186 = F_102 ;
else
V_138 -> V_186 = F_82 ;
V_138 -> V_121 . V_145 = NULL ;
V_138 -> V_121 . V_147 = V_147 ;
if ( ! V_138 -> V_121 . V_147 )
V_138 -> V_121 . V_147 = V_187 ;
V_138 -> V_121 . V_152 = V_152 ;
if ( ! V_138 -> V_121 . V_152 )
V_138 -> V_121 . V_152 = V_187 ;
V_138 -> V_121 . V_149 = V_149 ;
V_138 -> V_44 = V_44 ;
if ( V_138 -> V_44 )
V_138 -> V_128 = F_65 ;
V_138 -> V_188 = V_177 ;
if ( ! F_113 ( V_138 ) ) {
if ( F_114 ( V_138 ) )
F_115 ( V_138 ) ;
} else {
F_116 ( V_138 ) ;
}
} else {
struct V_4 * V_189 , * V_190 ;
F_117 ( & V_191 ) ;
F_118 (e, tmp_e, &smi_infos, link) {
if ( V_189 -> V_121 . V_184 != V_176 )
continue;
if ( V_189 -> V_131 != V_131 )
continue;
if ( V_189 -> V_121 . V_146 == V_145 )
F_115 ( V_189 ) ;
}
F_119 ( & V_191 ) ;
}
}
V_15 = V_65 ;
V_31:
F_116 ( V_172 ) ;
return V_15 ;
}
static int F_120 ( void )
{
int V_192 = - V_153 ;
int V_165 ;
struct V_4 * V_138 ;
for ( V_165 = 0 ; V_165 < V_193 ; V_165 ++ ) {
if ( ! V_194 [ V_165 ] && ! V_195 [ V_165 ] )
continue;
V_138 = F_108 () ;
if ( ! V_138 )
return - V_179 ;
V_138 -> V_136 = V_196 ;
F_12 (KERN_INFO PFX L_36 ) ;
if ( ! V_131 [ V_165 ] || strcmp ( V_131 [ V_165 ] , L_37 ) == 0 ) {
V_138 -> V_131 = V_197 ;
} else if ( strcmp ( V_131 [ V_165 ] , L_38 ) == 0 ) {
V_138 -> V_131 = V_198 ;
} else if ( strcmp ( V_131 [ V_165 ] , L_39 ) == 0 ) {
V_138 -> V_131 = V_132 ;
} else {
F_12 (KERN_WARNING PFX L_40
L_41 ,
i, si_type[i]) ;
F_116 ( V_138 ) ;
continue;
}
if ( V_194 [ V_165 ] ) {
V_138 -> V_186 = F_82 ;
V_138 -> V_121 . V_146 = V_194 [ V_165 ] ;
V_138 -> V_121 . V_184 = V_199 ;
} else if ( V_195 [ V_165 ] ) {
V_138 -> V_186 = F_102 ;
V_138 -> V_121 . V_146 = V_195 [ V_165 ] ;
V_138 -> V_121 . V_184 = V_185 ;
} else {
F_12 (KERN_WARNING PFX L_40
L_42
L_43 , i) ;
F_116 ( V_138 ) ;
continue;
}
V_138 -> V_121 . V_145 = NULL ;
V_138 -> V_121 . V_147 = V_200 [ V_165 ] ;
if ( ! V_138 -> V_121 . V_147 )
V_138 -> V_121 . V_147 = V_187 ;
V_138 -> V_121 . V_152 = V_201 [ V_165 ] ;
if ( ! V_138 -> V_121 . V_152 )
V_138 -> V_121 . V_152 = V_187 ;
V_138 -> V_121 . V_149 = V_202 [ V_165 ] ;
V_138 -> V_44 = V_203 [ V_165 ] ;
if ( V_138 -> V_44 )
V_138 -> V_128 = F_65 ;
V_138 -> V_188 = V_204 [ V_165 ] ;
if ( ! F_113 ( V_138 ) ) {
if ( F_114 ( V_138 ) )
F_115 ( V_138 ) ;
V_192 = 0 ;
} else {
F_116 ( V_138 ) ;
}
}
return V_192 ;
}
static T_3 F_121 ( T_4 V_205 ,
T_3 V_206 , void * V_207 )
{
struct V_4 * V_4 = V_207 ;
unsigned long V_90 ;
#ifdef F_7
struct V_18 V_19 ;
#endif
F_33 ( & ( V_4 -> V_93 ) , V_90 ) ;
F_22 ( V_4 , V_119 ) ;
#ifdef F_7
F_11 ( & V_19 ) ;
F_12 ( L_44 , V_19 . V_27 , V_19 . V_28 ) ;
#endif
F_27 ( V_4 , 0 ) ;
F_35 ( & ( V_4 -> V_93 ) , V_90 ) ;
return V_208 ;
}
static void F_122 ( struct V_4 * V_138 )
{
if ( ! V_138 -> V_44 )
return;
F_123 ( NULL , V_138 -> V_44 , & F_121 ) ;
}
static int F_124 ( struct V_4 * V_138 )
{
T_5 V_209 ;
if ( ! V_138 -> V_44 )
return 0 ;
V_209 = F_125 ( NULL ,
V_138 -> V_44 ,
V_210 ,
& F_121 ,
V_138 ) ;
if ( V_209 != V_211 ) {
F_26 ( V_138 -> V_67 , L_45
L_18 , V_141 , V_138 -> V_44 ) ;
V_138 -> V_44 = 0 ;
return - V_156 ;
} else {
V_138 -> V_142 = F_122 ;
F_67 ( V_138 -> V_67 , L_46 , V_138 -> V_44 ) ;
return 0 ;
}
}
static int F_126 ( struct V_212 * V_213 )
{
struct V_4 * V_138 ;
if ( V_213 -> V_214 != 1 ) {
F_12 (KERN_INFO PFX L_47 , spmi->IPMIlegacy) ;
return - V_153 ;
}
V_138 = F_108 () ;
if ( ! V_138 ) {
F_12 (KERN_ERR PFX L_48 ) ;
return - V_179 ;
}
V_138 -> V_136 = V_215 ;
F_12 (KERN_INFO PFX L_49 ) ;
switch ( V_213 -> V_216 ) {
case 1 :
V_138 -> V_131 = V_197 ;
break;
case 2 :
V_138 -> V_131 = V_198 ;
break;
case 3 :
V_138 -> V_131 = V_132 ;
break;
default:
F_12 (KERN_INFO PFX L_50 ,
spmi->InterfaceType) ;
F_116 ( V_138 ) ;
return - V_157 ;
}
if ( V_213 -> V_217 & 1 ) {
V_138 -> V_44 = V_213 -> V_218 ;
V_138 -> V_128 = F_124 ;
} else if ( V_213 -> V_217 & 2 ) {
V_138 -> V_44 = V_213 -> V_219 ;
V_138 -> V_128 = F_65 ;
} else {
V_138 -> V_44 = 0 ;
V_138 -> V_128 = NULL ;
}
if ( V_213 -> V_145 . V_220 ) {
V_138 -> V_121 . V_147 = V_213 -> V_145 . V_220 / 8 ;
} else {
V_138 -> V_121 . V_147 = V_187 ;
}
V_138 -> V_121 . V_152 = V_138 -> V_121 . V_147 ;
V_138 -> V_121 . V_149 = V_213 -> V_145 . V_221 ;
if ( V_213 -> V_145 . V_222 == V_223 ) {
V_138 -> V_186 = F_102 ;
V_138 -> V_121 . V_184 = V_185 ;
} else if ( V_213 -> V_145 . V_222 == V_224 ) {
V_138 -> V_186 = F_82 ;
V_138 -> V_121 . V_184 = V_199 ;
} else {
F_116 ( V_138 ) ;
F_12 (KERN_WARNING PFX L_51 ) ;
return - V_157 ;
}
V_138 -> V_121 . V_146 = V_213 -> V_145 . V_225 ;
F_127 ( L_52 ,
( V_138 -> V_121 . V_184 == V_199 ) ? L_53 : L_54 ,
V_138 -> V_121 . V_146 , V_138 -> V_121 . V_152 , V_138 -> V_121 . V_147 ,
V_138 -> V_44 ) ;
if ( F_113 ( V_138 ) )
F_116 ( V_138 ) ;
return 0 ;
}
static void F_128 ( void )
{
T_5 V_209 ;
struct V_212 * V_213 ;
int V_165 ;
if ( V_226 )
return;
if ( V_227 )
return;
for ( V_165 = 0 ; ; V_165 ++ ) {
V_209 = F_129 ( V_228 , V_165 + 1 ,
(struct V_229 * * ) & V_213 ) ;
if ( V_209 != V_211 )
return;
F_126 ( V_213 ) ;
}
}
static int F_130 ( struct V_230 * V_67 ,
const struct V_231 * V_232 )
{
struct V_233 * V_234 ;
struct V_4 * V_138 ;
struct V_235 * V_236 , * V_237 ;
T_4 V_238 ;
T_5 V_209 ;
unsigned long long V_239 ;
V_234 = F_131 ( V_67 ) ;
if ( ! V_234 )
return - V_153 ;
V_138 = F_108 () ;
if ( ! V_138 )
return - V_179 ;
V_138 -> V_136 = V_240 ;
F_12 (KERN_INFO PFX L_55 ) ;
V_238 = V_234 -> V_238 ;
V_138 -> V_137 . V_241 . T_4 = V_238 ;
V_209 = F_132 ( V_238 , L_56 , NULL , & V_239 ) ;
if ( F_133 ( V_209 ) )
goto V_242;
switch ( V_239 ) {
case 1 :
V_138 -> V_131 = V_197 ;
break;
case 2 :
V_138 -> V_131 = V_198 ;
break;
case 3 :
V_138 -> V_131 = V_132 ;
break;
default:
F_67 ( & V_67 -> V_67 , L_57 , V_239 ) ;
goto V_242;
}
V_236 = F_134 ( V_67 , V_243 , 0 ) ;
if ( V_236 ) {
V_138 -> V_186 = F_82 ;
V_138 -> V_121 . V_184 = V_199 ;
} else {
V_236 = F_134 ( V_67 , V_244 , 0 ) ;
if ( V_236 ) {
V_138 -> V_186 = F_102 ;
V_138 -> V_121 . V_184 = V_185 ;
}
}
if ( ! V_236 ) {
F_135 ( & V_67 -> V_67 , L_58 ) ;
goto V_242;
}
V_138 -> V_121 . V_146 = V_236 -> V_245 ;
V_138 -> V_121 . V_147 = V_187 ;
V_237 = F_134 ( V_67 ,
( V_138 -> V_121 . V_184 == V_199 ) ?
V_243 : V_244 ,
1 ) ;
if ( V_237 ) {
if ( V_237 -> V_245 > V_138 -> V_121 . V_146 )
V_138 -> V_121 . V_147 = V_237 -> V_245 - V_138 -> V_121 . V_146 ;
}
V_138 -> V_121 . V_152 = V_187 ;
V_138 -> V_121 . V_149 = 0 ;
V_209 = F_132 ( V_238 , L_59 , NULL , & V_239 ) ;
if ( F_136 ( V_209 ) ) {
V_138 -> V_44 = V_239 ;
V_138 -> V_128 = F_124 ;
} else if ( F_137 ( V_67 , 0 ) ) {
V_138 -> V_44 = F_138 ( V_67 , 0 ) ;
V_138 -> V_128 = F_65 ;
}
V_138 -> V_67 = & V_67 -> V_67 ;
F_139 ( V_67 , V_138 ) ;
F_67 ( V_138 -> V_67 , L_60 ,
V_236 , V_138 -> V_121 . V_152 , V_138 -> V_121 . V_147 ,
V_138 -> V_44 ) ;
if ( F_113 ( V_138 ) )
goto V_242;
return 0 ;
V_242:
F_116 ( V_138 ) ;
return - V_156 ;
}
static void F_140 ( struct V_230 * V_67 )
{
struct V_4 * V_138 = F_141 ( V_67 ) ;
F_115 ( V_138 ) ;
}
static int F_142 ( const struct V_246 * V_247 ,
struct V_248 * V_249 )
{
const T_6 * V_12 = ( const T_6 * ) V_247 ;
unsigned long V_250 ;
T_6 V_251 ;
T_6 V_65 = V_247 -> V_252 ;
V_249 -> type = V_12 [ 4 ] ;
memcpy ( & V_250 , V_12 + 8 , sizeof( unsigned long ) ) ;
if ( V_65 >= 0x11 ) {
if ( V_250 & 1 ) {
V_250 &= 0xFFFE ;
V_249 -> V_176 = V_199 ;
} else
V_249 -> V_176 = V_185 ;
V_249 -> V_250 = V_250 | ( ( V_12 [ 0x10 ] & 0x10 ) >> 4 ) ;
V_249 -> V_44 = V_12 [ 0x11 ] ;
V_251 = ( V_12 [ 0x10 ] & 0xC0 ) >> 6 ;
switch ( V_251 ) {
case 0x00 :
V_249 -> V_144 = 1 ;
break;
case 0x01 :
V_249 -> V_144 = 4 ;
break;
case 0x02 :
V_249 -> V_144 = 16 ;
break;
default:
return - V_157 ;
}
} else {
V_249 -> V_250 = V_250 & 0xfffe ;
V_249 -> V_176 = V_199 ;
V_249 -> V_144 = 1 ;
}
V_249 -> V_188 = V_12 [ 6 ] ;
return 0 ;
}
static void F_143 ( struct V_248 * V_253 )
{
struct V_4 * V_138 ;
V_138 = F_108 () ;
if ( ! V_138 ) {
F_12 (KERN_ERR PFX L_61 ) ;
return;
}
V_138 -> V_136 = V_254 ;
F_12 (KERN_INFO PFX L_62 ) ;
switch ( V_253 -> type ) {
case 0x01 :
V_138 -> V_131 = V_197 ;
break;
case 0x02 :
V_138 -> V_131 = V_198 ;
break;
case 0x03 :
V_138 -> V_131 = V_132 ;
break;
default:
F_116 ( V_138 ) ;
return;
}
switch ( V_253 -> V_176 ) {
case V_185 :
V_138 -> V_186 = F_102 ;
V_138 -> V_121 . V_184 = V_185 ;
break;
case V_199 :
V_138 -> V_186 = F_82 ;
V_138 -> V_121 . V_184 = V_199 ;
break;
default:
F_116 ( V_138 ) ;
F_12 (KERN_WARNING PFX L_63 ,
ipmi_data->addr_space) ;
return;
}
V_138 -> V_121 . V_146 = V_253 -> V_250 ;
V_138 -> V_121 . V_147 = V_253 -> V_144 ;
if ( ! V_138 -> V_121 . V_147 )
V_138 -> V_121 . V_147 = V_187 ;
V_138 -> V_121 . V_152 = V_187 ;
V_138 -> V_121 . V_149 = 0 ;
V_138 -> V_188 = V_253 -> V_188 ;
V_138 -> V_44 = V_253 -> V_44 ;
if ( V_138 -> V_44 )
V_138 -> V_128 = F_65 ;
F_127 ( L_64 ,
( V_138 -> V_121 . V_184 == V_199 ) ? L_53 : L_54 ,
V_138 -> V_121 . V_146 , V_138 -> V_121 . V_152 , V_138 -> V_121 . V_147 ,
V_138 -> V_44 ) ;
if ( F_113 ( V_138 ) )
F_116 ( V_138 ) ;
}
static void F_144 ( void )
{
const struct V_255 * V_67 = NULL ;
struct V_248 V_12 ;
int V_15 ;
while ( ( V_67 = F_145 ( V_256 , NULL , V_67 ) ) ) {
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_15 = F_142 ( ( const struct V_246 * ) V_67 -> V_257 ,
& V_12 ) ;
if ( ! V_15 )
F_143 ( & V_12 ) ;
}
}
static void F_146 ( struct V_4 * V_138 )
{
struct V_258 * V_259 = V_138 -> V_260 ;
F_147 ( V_259 ) ;
}
static int F_148 ( struct V_4 * V_138 )
{
if ( V_138 -> V_131 == V_197 ) {
unsigned char V_209 ;
int V_147 ;
V_138 -> V_121 . V_152 = V_261 ;
V_138 -> V_121 . V_149 = 0 ;
V_138 -> V_151 = 2 ;
V_138 -> V_32 = & V_262 ;
for ( V_147 = V_187 ; V_147 <= 16 ; ) {
V_138 -> V_121 . V_147 = V_147 ;
if ( V_138 -> V_186 ( V_138 ) ) {
F_135 ( V_138 -> V_67 ,
L_65 ) ;
return V_187 ;
}
V_138 -> V_121 . V_122 ( & V_138 -> V_121 , 1 , 0x10 ) ;
V_209 = V_138 -> V_121 . V_155 ( & V_138 -> V_121 , 1 ) ;
V_138 -> V_154 ( V_138 ) ;
if ( V_209 )
return V_147 ;
V_147 *= 4 ;
}
}
return V_187 ;
}
static int F_149 ( struct V_258 * V_259 ,
const struct V_263 * V_264 )
{
int V_15 ;
int V_265 = V_259 -> V_266 & V_267 ;
struct V_4 * V_138 ;
V_138 = F_108 () ;
if ( ! V_138 )
return - V_179 ;
V_138 -> V_136 = V_268 ;
F_67 ( & V_259 -> V_67 , L_66 ) ;
switch ( V_265 ) {
case V_269 :
V_138 -> V_131 = V_198 ;
break;
case V_270 :
V_138 -> V_131 = V_197 ;
break;
case V_271 :
V_138 -> V_131 = V_132 ;
break;
default:
F_116 ( V_138 ) ;
F_67 ( & V_259 -> V_67 , L_67 , V_265 ) ;
return - V_179 ;
}
V_15 = F_150 ( V_259 ) ;
if ( V_15 ) {
F_135 ( & V_259 -> V_67 , L_68 ) ;
F_116 ( V_138 ) ;
return V_15 ;
}
V_138 -> V_272 = F_146 ;
V_138 -> V_260 = V_259 ;
if ( F_151 ( V_259 , 0 ) & V_243 ) {
V_138 -> V_186 = F_82 ;
V_138 -> V_121 . V_184 = V_199 ;
} else {
V_138 -> V_186 = F_102 ;
V_138 -> V_121 . V_184 = V_185 ;
}
V_138 -> V_121 . V_146 = F_152 ( V_259 , 0 ) ;
V_138 -> V_121 . V_147 = F_148 ( V_138 ) ;
V_138 -> V_121 . V_152 = V_261 ;
V_138 -> V_121 . V_149 = 0 ;
V_138 -> V_44 = V_259 -> V_44 ;
if ( V_138 -> V_44 )
V_138 -> V_128 = F_65 ;
V_138 -> V_67 = & V_259 -> V_67 ;
F_153 ( V_259 , V_138 ) ;
F_67 ( & V_259 -> V_67 , L_60 ,
& V_259 -> V_235 [ 0 ] , V_138 -> V_121 . V_152 , V_138 -> V_121 . V_147 ,
V_138 -> V_44 ) ;
if ( F_113 ( V_138 ) )
F_116 ( V_138 ) ;
return 0 ;
}
static void F_154 ( struct V_258 * V_259 )
{
struct V_4 * V_138 = F_155 ( V_259 ) ;
F_115 ( V_138 ) ;
}
static int F_156 ( struct V_273 * V_67 )
{
#ifdef F_157
const struct V_274 * V_275 ;
struct V_4 * V_138 ;
struct V_235 V_235 ;
const T_7 * V_152 , * V_147 , * V_149 ;
struct V_276 * V_277 = V_67 -> V_67 . V_278 ;
int V_192 ;
int V_279 ;
F_67 ( & V_67 -> V_67 , L_69 ) ;
V_275 = F_158 ( V_280 , & V_67 -> V_67 ) ;
if ( ! V_275 )
return - V_156 ;
V_192 = F_159 ( V_277 , 0 , & V_235 ) ;
if ( V_192 ) {
F_26 ( & V_67 -> V_67 , V_281 L_70 ) ;
return V_192 ;
}
V_152 = F_160 ( V_277 , L_71 , & V_279 ) ;
if ( V_152 && V_279 != 4 ) {
F_26 ( & V_67 -> V_67 , V_281 L_72 ) ;
return - V_156 ;
}
V_147 = F_160 ( V_277 , L_73 , & V_279 ) ;
if ( V_147 && V_279 != 4 ) {
F_26 ( & V_67 -> V_67 , V_281 L_74 ) ;
return - V_156 ;
}
V_149 = F_160 ( V_277 , L_75 , & V_279 ) ;
if ( V_149 && V_279 != 4 ) {
F_26 ( & V_67 -> V_67 , V_281 L_76 ) ;
return - V_156 ;
}
V_138 = F_108 () ;
if ( ! V_138 ) {
F_135 ( & V_67 -> V_67 ,
L_77 ) ;
return - V_179 ;
}
V_138 -> V_131 = (enum V_131 ) V_275 -> V_12 ;
V_138 -> V_136 = V_282 ;
V_138 -> V_128 = F_65 ;
if ( V_235 . V_90 & V_243 ) {
V_138 -> V_186 = F_82 ;
V_138 -> V_121 . V_184 = V_199 ;
} else {
V_138 -> V_186 = F_102 ;
V_138 -> V_121 . V_184 = V_185 ;
}
V_138 -> V_121 . V_146 = V_235 . V_245 ;
V_138 -> V_121 . V_152 = V_152 ? F_161 ( V_152 ) : V_261 ;
V_138 -> V_121 . V_147 = V_147 ? F_161 ( V_147 ) : V_187 ;
V_138 -> V_121 . V_149 = V_149 ? F_161 ( V_149 ) : 0 ;
V_138 -> V_44 = F_162 ( V_67 -> V_67 . V_278 , 0 ) ;
V_138 -> V_67 = & V_67 -> V_67 ;
F_163 ( & V_67 -> V_67 , L_78 ,
V_138 -> V_121 . V_146 , V_138 -> V_121 . V_152 , V_138 -> V_121 . V_147 ,
V_138 -> V_44 ) ;
F_164 ( & V_67 -> V_67 , V_138 ) ;
if ( F_113 ( V_138 ) ) {
F_116 ( V_138 ) ;
return - V_283 ;
}
#endif
return 0 ;
}
static int F_165 ( struct V_273 * V_67 )
{
#ifdef F_157
F_115 ( F_166 ( & V_67 -> V_67 ) ) ;
#endif
return 0 ;
}
static int F_167 ( struct V_284 * V_67 )
{
struct V_4 * V_138 ;
V_138 = F_108 () ;
if ( ! V_138 ) {
F_135 ( & V_67 -> V_67 ,
L_79 ) ;
return - V_179 ;
}
V_138 -> V_131 = V_197 ;
V_138 -> V_136 = V_282 ;
V_138 -> V_186 = F_102 ;
V_138 -> V_121 . V_184 = V_185 ;
V_138 -> V_121 . V_146 = V_67 -> V_285 . V_245 ;
V_138 -> V_121 . V_152 = 1 ;
V_138 -> V_121 . V_147 = 1 ;
V_138 -> V_121 . V_149 = 0 ;
V_138 -> V_44 = 0 ;
V_138 -> V_128 = NULL ;
V_138 -> V_67 = & V_67 -> V_67 ;
F_163 ( & V_67 -> V_67 , L_80 , V_138 -> V_121 . V_146 ) ;
F_164 ( & V_67 -> V_67 , V_138 ) ;
if ( F_113 ( V_138 ) ) {
F_116 ( V_138 ) ;
return - V_283 ;
}
return 0 ;
}
static int F_168 ( struct V_284 * V_67 )
{
F_115 ( F_166 ( & V_67 -> V_67 ) ) ;
return 0 ;
}
static int F_169 ( struct V_4 * V_4 )
{
enum V_14 V_100 ;
V_100 = V_4 -> V_32 -> V_77 ( V_4 -> V_34 , 0 ) ;
for (; ; ) {
if ( V_100 == V_106 ||
V_100 == V_286 ) {
F_170 ( 1 ) ;
V_100 = V_4 -> V_32 -> V_77 (
V_4 -> V_34 , 100 ) ;
} else if ( V_100 == V_30 ) {
V_100 = V_4 -> V_32 -> V_77 (
V_4 -> V_34 , 0 ) ;
} else
break;
}
if ( V_100 == V_80 )
return - V_153 ;
return 0 ;
}
static int F_171 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 2 ] ;
unsigned char * V_287 ;
unsigned long V_288 ;
int V_15 = 0 ;
V_287 = F_172 ( V_63 , V_169 ) ;
if ( ! V_287 )
return - V_179 ;
V_6 [ 0 ] = V_36 << 2 ;
V_6 [ 1 ] = V_289 ;
V_4 -> V_32 -> V_33 ( V_4 -> V_34 , V_6 , 2 ) ;
V_15 = F_169 ( V_4 ) ;
if ( V_15 )
goto V_31;
V_288 = V_4 -> V_32 -> V_62 ( V_4 -> V_34 ,
V_287 , V_63 ) ;
V_15 = F_173 ( V_287 , V_288 , & V_4 -> V_290 ) ;
V_31:
F_116 ( V_287 ) ;
return V_15 ;
}
static int F_174 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 3 ] ;
unsigned char * V_287 ;
unsigned long V_288 ;
int V_15 = 0 ;
V_287 = F_172 ( V_63 , V_169 ) ;
if ( ! V_287 )
return - V_179 ;
V_6 [ 0 ] = V_36 << 2 ;
V_6 [ 1 ] = V_37 ;
V_4 -> V_32 -> V_33 ( V_4 -> V_34 , V_6 , 2 ) ;
V_15 = F_169 ( V_4 ) ;
if ( V_15 ) {
F_12 (KERN_WARNING PFX L_81
L_82
L_83 ) ;
goto V_31;
}
V_288 = V_4 -> V_32 -> V_62 ( V_4 -> V_34 ,
V_287 , V_63 ) ;
if ( V_288 < 4 ||
V_287 [ 0 ] != ( V_36 | 1 ) << 2 ||
V_287 [ 1 ] != V_37 ||
V_287 [ 2 ] != 0 ) {
F_12 (KERN_WARNING PFX L_84
L_85 ) ;
V_15 = - V_156 ;
goto V_31;
}
if ( V_287 [ 3 ] & V_291 )
goto V_31;
V_6 [ 0 ] = V_36 << 2 ;
V_6 [ 1 ] = V_71 ;
V_6 [ 2 ] = V_287 [ 3 ] | V_291 ;
V_4 -> V_32 -> V_33 ( V_4 -> V_34 , V_6 , 3 ) ;
V_15 = F_169 ( V_4 ) ;
if ( V_15 ) {
F_12 (KERN_WARNING PFX L_86
L_87
L_83 ) ;
goto V_31;
}
V_288 = V_4 -> V_32 -> V_62 ( V_4 -> V_34 ,
V_287 , V_63 ) ;
if ( V_288 < 3 ||
V_287 [ 0 ] != ( V_36 | 1 ) << 2 ||
V_287 [ 1 ] != V_71 ) {
F_12 (KERN_WARNING PFX L_88
L_89 ) ;
V_15 = - V_156 ;
goto V_31;
}
if ( V_287 [ 2 ] != 0 )
V_15 = - V_292 ;
V_31:
F_116 ( V_287 ) ;
return V_15 ;
}
static int F_175 ( struct V_293 * V_294 , void * V_160 )
{
struct V_4 * V_134 = V_294 -> V_295 ;
return F_176 ( V_294 , L_90 , V_296 [ V_134 -> V_131 ] ) ;
}
static int F_177 ( struct V_297 * V_297 , struct V_298 * V_298 )
{
return F_178 ( V_298 , F_175 , F_179 ( V_297 ) ) ;
}
static int F_180 ( struct V_293 * V_294 , void * V_160 )
{
struct V_4 * V_134 = V_294 -> V_295 ;
F_176 ( V_294 , L_91 ,
V_134 -> V_44 && ! V_134 -> V_45 ) ;
F_176 ( V_294 , L_92 ,
F_181 ( V_134 , V_118 ) ) ;
F_176 ( V_294 , L_93 ,
F_181 ( V_134 , V_116 ) ) ;
F_176 ( V_294 , L_94 ,
F_181 ( V_134 , V_85 ) ) ;
F_176 ( V_294 , L_95 ,
F_181 ( V_134 , V_119 ) ) ;
F_176 ( V_294 , L_96 ,
F_181 ( V_134 , V_83 ) ) ;
F_176 ( V_294 , L_97 ,
F_181 ( V_134 , V_299 ) ) ;
F_176 ( V_294 , L_98 ,
F_181 ( V_134 , V_81 ) ) ;
F_176 ( V_294 , L_99 ,
F_181 ( V_134 , V_79 ) ) ;
F_176 ( V_294 , L_100 ,
F_181 ( V_134 , V_69 ) ) ;
F_176 ( V_294 , L_101 ,
F_181 ( V_134 , V_52 ) ) ;
F_176 ( V_294 , L_102 ,
F_181 ( V_134 , V_70 ) ) ;
return 0 ;
}
static int F_182 ( struct V_297 * V_297 , struct V_298 * V_298 )
{
return F_178 ( V_298 , F_180 , F_179 ( V_297 ) ) ;
}
static int F_183 ( struct V_293 * V_294 , void * V_160 )
{
struct V_4 * V_134 = V_294 -> V_295 ;
return F_176 ( V_294 ,
L_103 ,
V_296 [ V_134 -> V_131 ] ,
V_300 [ V_134 -> V_121 . V_184 ] ,
V_134 -> V_121 . V_146 ,
V_134 -> V_121 . V_147 ,
V_134 -> V_121 . V_152 ,
V_134 -> V_121 . V_149 ,
V_134 -> V_44 ,
V_134 -> V_188 ) ;
}
static int F_184 ( struct V_297 * V_297 , struct V_298 * V_298 )
{
return F_178 ( V_298 , F_183 , F_179 ( V_297 ) ) ;
}
static int F_185 ( struct V_4 * V_4 )
{
V_4 -> V_51 = ( ( V_4 -> V_51 & ~ V_60 ) |
V_53 ) ;
return 1 ;
}
static void F_186 ( struct V_4 * V_4 )
{
struct V_301 * V_302 = & V_4 -> V_290 ;
if ( V_302 -> V_303 == V_304 ) {
if ( V_302 -> V_290 == V_305 &&
V_302 -> V_306 == V_307 &&
V_302 -> V_308 == V_309 ) {
V_4 -> V_61 =
F_185 ;
} else if ( F_187 ( V_302 ) < 1 ||
( F_187 ( V_302 ) == 1 &&
F_188 ( V_302 ) < 5 ) ) {
V_4 -> V_61 =
F_185 ;
}
}
}
static void F_189 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_9 ;
V_6 -> V_11 [ 0 ] = V_6 -> V_12 [ 0 ] | 4 ;
V_6 -> V_11 [ 1 ] = V_6 -> V_12 [ 1 ] ;
V_6 -> V_11 [ 2 ] = V_310 ;
V_6 -> V_13 = 3 ;
V_4 -> V_9 = NULL ;
F_3 ( V_4 , V_6 ) ;
}
static int F_190 ( struct V_1 * V_311 ,
unsigned long V_312 ,
void * V_313 )
{
struct V_4 * V_4 = V_313 ;
unsigned char * V_12 = V_4 -> V_9 -> V_12 ;
unsigned int V_314 = V_4 -> V_9 -> V_35 ;
if ( V_314 >= 8 &&
( V_12 [ 0 ] >> 2 ) == V_315 &&
V_12 [ 1 ] == V_316 &&
V_12 [ 7 ] == 0x3A ) {
F_189 ( V_4 ) ;
return V_317 ;
}
return V_318 ;
}
static void
F_191 ( struct V_4 * V_4 )
{
struct V_301 * V_302 = & V_4 -> V_290 ;
if ( V_302 -> V_303 == V_304 &&
V_4 -> V_131 == V_132 )
F_1 ( & V_319 ) ;
}
static void F_192 ( struct V_4 * V_4 )
{
F_186 ( V_4 ) ;
}
static void F_193 ( struct V_4 * V_4 )
{
F_191 ( V_4 ) ;
}
static inline void F_194 ( struct V_4 * V_4 )
{
if ( V_4 -> V_7 ) {
if ( V_4 -> V_95 != NULL )
F_195 ( V_4 -> V_95 ) ;
F_196 ( & V_4 -> V_47 ) ;
}
}
static void F_197 ( void )
{
struct V_4 * V_138 ;
int V_165 ;
for ( V_165 = 0 ; ; V_165 ++ ) {
if ( ! V_320 [ V_165 ] . V_321 )
break;
#ifdef F_198
if ( F_199 ( V_320 [ V_165 ] . V_321 ) )
continue;
#endif
V_138 = F_108 () ;
if ( ! V_138 )
return;
V_138 -> V_136 = V_322 ;
V_138 -> V_131 = V_320 [ V_165 ] . type ;
V_138 -> V_186 = F_82 ;
V_138 -> V_121 . V_146 = V_320 [ V_165 ] . V_321 ;
V_138 -> V_121 . V_184 = V_199 ;
V_138 -> V_121 . V_145 = NULL ;
V_138 -> V_121 . V_147 = V_187 ;
V_138 -> V_121 . V_152 = V_187 ;
V_138 -> V_121 . V_149 = 0 ;
if ( F_113 ( V_138 ) == 0 ) {
if ( ( F_114 ( V_138 ) ) == 0 ) {
F_12 (KERN_INFO PFX L_104
L_105 ,
si_to_str[info->si_type],
addr_space_to_str[info->io.addr_type],
info->io.addr_data) ;
} else
F_115 ( V_138 ) ;
} else {
F_116 ( V_138 ) ;
}
}
}
static int F_200 ( struct V_4 * V_138 )
{
struct V_4 * V_189 ;
F_201 (e, &smi_infos, link) {
if ( V_189 -> V_121 . V_184 != V_138 -> V_121 . V_184 )
continue;
if ( V_189 -> V_121 . V_146 == V_138 -> V_121 . V_146 )
return 0 ;
}
return 1 ;
}
static int F_113 ( struct V_4 * V_126 )
{
int V_15 = 0 ;
F_12 (KERN_INFO PFX L_106 ,
ipmi_addr_src_to_str[new_smi->addr_source],
si_to_str[new_smi->si_type]) ;
F_117 ( & V_191 ) ;
if ( ! F_200 ( V_126 ) ) {
F_12 ( V_323 L_107 ) ;
V_15 = - V_283 ;
goto V_324;
}
F_12 ( V_323 L_108 ) ;
V_126 -> V_7 = NULL ;
V_126 -> V_34 = NULL ;
V_126 -> V_32 = NULL ;
F_31 ( & V_126 -> V_25 , & V_325 ) ;
V_324:
F_119 ( & V_191 ) ;
return V_15 ;
}
static int F_114 ( struct V_4 * V_126 )
{
int V_15 = 0 ;
int V_165 ;
F_12 (KERN_INFO PFX L_109
L_110
L_111 ,
ipmi_addr_src_to_str[new_smi->addr_source],
si_to_str[new_smi->si_type],
addr_space_to_str[new_smi->io.addr_type],
new_smi->io.addr_data,
new_smi->slave_addr, new_smi->irq) ;
switch ( V_126 -> V_131 ) {
case V_197 :
V_126 -> V_32 = & V_262 ;
break;
case V_198 :
V_126 -> V_32 = & V_326 ;
break;
case V_132 :
V_126 -> V_32 = & V_327 ;
break;
default:
V_15 = - V_157 ;
goto V_324;
}
V_126 -> V_34 = F_172 ( V_126 -> V_32 -> V_314 () , V_169 ) ;
if ( ! V_126 -> V_34 ) {
F_12 (KERN_ERR PFX
L_112 ) ;
V_15 = - V_179 ;
goto V_324;
}
V_126 -> V_151 = V_126 -> V_32 -> V_328 ( V_126 -> V_34 ,
& V_126 -> V_121 ) ;
V_15 = V_126 -> V_186 ( V_126 ) ;
if ( V_15 ) {
F_12 (KERN_ERR PFX L_113 ) ;
goto V_324;
}
if ( V_126 -> V_32 -> V_329 ( V_126 -> V_34 ) ) {
if ( V_126 -> V_136 )
F_12 (KERN_INFO PFX L_114 ) ;
V_15 = - V_153 ;
goto V_324;
}
V_15 = F_171 ( V_126 ) ;
if ( V_15 ) {
if ( V_126 -> V_136 )
F_12 (KERN_INFO PFX L_115
L_116 ) ;
goto V_324;
}
F_192 ( V_126 ) ;
F_193 ( V_126 ) ;
F_202 ( & ( V_126 -> V_22 ) ) ;
F_202 ( & ( V_126 -> V_20 ) ) ;
V_126 -> V_9 = NULL ;
F_29 ( & V_126 -> V_86 , 0 ) ;
V_126 -> V_91 = 0 ;
for ( V_165 = 0 ; V_165 < V_330 ; V_165 ++ )
F_29 ( & V_126 -> V_331 [ V_165 ] , 0 ) ;
V_126 -> V_45 = 1 ;
F_29 ( & V_126 -> V_46 , 0 ) ;
V_126 -> V_103 = V_332 ;
V_332 ++ ;
V_15 = F_174 ( V_126 ) ;
if ( V_15 == 0 )
V_126 -> V_111 = 1 ;
F_16 ( V_126 ) ;
if ( V_126 -> V_44 )
V_126 -> V_38 = V_66 ;
if ( ! V_126 -> V_67 ) {
V_126 -> V_259 = F_203 ( L_117 ,
V_126 -> V_103 ) ;
if ( ! V_126 -> V_259 ) {
F_12 (KERN_ERR PFX
L_118 ) ;
goto V_324;
}
V_126 -> V_67 = & V_126 -> V_259 -> V_67 ;
V_126 -> V_67 -> V_333 = & V_334 . V_333 ;
V_15 = F_204 ( V_126 -> V_259 ) ;
if ( V_15 ) {
F_12 (KERN_ERR PFX
L_119
L_120 ,
rv) ;
goto V_324;
}
V_126 -> V_335 = 1 ;
}
V_15 = F_205 ( & V_32 ,
V_126 ,
& V_126 -> V_290 ,
V_126 -> V_67 ,
L_121 ,
V_126 -> V_188 ) ;
if ( V_15 ) {
F_135 ( V_126 -> V_67 , L_122 ,
V_15 ) ;
goto V_336;
}
V_15 = F_206 ( V_126 -> V_7 , L_123 ,
& V_337 ,
V_126 ) ;
if ( V_15 ) {
F_135 ( V_126 -> V_67 , L_124 , V_15 ) ;
goto V_336;
}
V_15 = F_206 ( V_126 -> V_7 , L_125 ,
& V_338 ,
V_126 ) ;
if ( V_15 ) {
F_135 ( V_126 -> V_67 , L_124 , V_15 ) ;
goto V_336;
}
V_15 = F_206 ( V_126 -> V_7 , L_126 ,
& V_339 ,
V_126 ) ;
if ( V_15 ) {
F_135 ( V_126 -> V_67 , L_124 , V_15 ) ;
goto V_336;
}
F_67 ( V_126 -> V_67 , L_127 ,
V_296 [ V_126 -> V_131 ] ) ;
return 0 ;
V_336:
F_207 ( & V_126 -> V_46 ) ;
F_194 ( V_126 ) ;
V_324:
V_126 -> V_45 = 1 ;
if ( V_126 -> V_7 ) {
F_208 ( V_126 -> V_7 ) ;
V_126 -> V_7 = NULL ;
}
if ( V_126 -> V_142 ) {
V_126 -> V_142 ( V_126 ) ;
V_126 -> V_142 = NULL ;
}
F_209 () ;
if ( V_126 -> V_34 ) {
if ( V_126 -> V_32 )
V_126 -> V_32 -> V_340 ( V_126 -> V_34 ) ;
F_116 ( V_126 -> V_34 ) ;
V_126 -> V_34 = NULL ;
}
if ( V_126 -> V_272 ) {
V_126 -> V_272 ( V_126 ) ;
V_126 -> V_272 = NULL ;
}
if ( V_126 -> V_154 ) {
V_126 -> V_154 ( V_126 ) ;
V_126 -> V_154 = NULL ;
}
if ( V_126 -> V_335 ) {
F_210 ( V_126 -> V_259 ) ;
V_126 -> V_335 = 0 ;
}
return V_15 ;
}
static int F_211 ( void )
{
int V_165 ;
char * V_172 ;
int V_15 ;
struct V_4 * V_189 ;
enum V_341 type = V_342 ;
if ( V_343 )
return 0 ;
V_343 = 1 ;
if ( V_344 ) {
V_15 = F_212 ( & V_334 ) ;
if ( V_15 ) {
F_12 (KERN_ERR PFX L_128
L_129 , rv) ;
return V_15 ;
}
}
V_172 = V_345 ;
if ( * V_172 != '\0' ) {
for ( V_165 = 0 ; ( V_165 < V_193 ) && ( * V_172 != '\0' ) ; V_165 ++ ) {
V_131 [ V_165 ] = V_172 ;
V_172 = strchr ( V_172 , ',' ) ;
if ( V_172 ) {
* V_172 = '\0' ;
V_172 ++ ;
} else {
break;
}
}
}
F_12 ( V_346 L_130 ) ;
if ( ! F_120 () )
return 0 ;
#ifdef F_213
if ( V_347 ) {
V_15 = F_214 ( & V_348 ) ;
if ( V_15 )
F_12 (KERN_ERR PFX L_128
L_131 , rv) ;
else
V_349 = 1 ;
}
#endif
#ifdef F_215
if ( V_350 ) {
F_216 ( & V_351 ) ;
V_352 = 1 ;
}
#endif
#ifdef F_217
if ( V_353 )
F_144 () ;
#endif
#ifdef F_215
if ( V_350 )
F_128 () ;
#endif
#ifdef F_218
F_219 ( & V_354 ) ;
V_355 = 1 ;
V_356 = 0 ;
#endif
F_117 ( & V_191 ) ;
F_201 (e, &smi_infos, link) {
if ( V_189 -> V_44 && ( ! type || V_189 -> V_136 == type ) ) {
if ( ! F_114 ( V_189 ) ) {
type = V_189 -> V_136 ;
}
}
}
if ( type ) {
F_119 ( & V_191 ) ;
return 0 ;
}
F_201 (e, &smi_infos, link) {
if ( ! V_189 -> V_44 && ( ! type || V_189 -> V_136 == type ) ) {
if ( ! F_114 ( V_189 ) ) {
type = V_189 -> V_136 ;
}
}
}
F_119 ( & V_191 ) ;
if ( type )
return 0 ;
if ( V_356 ) {
F_117 ( & V_191 ) ;
if ( F_8 ( & V_325 ) ) {
F_119 ( & V_191 ) ;
F_197 () ;
} else
F_119 ( & V_191 ) ;
}
F_117 ( & V_191 ) ;
if ( V_357 && F_8 ( & V_325 ) ) {
F_119 ( & V_191 ) ;
F_220 () ;
F_12 (KERN_WARNING PFX
L_132 ) ;
return - V_153 ;
} else {
F_119 ( & V_191 ) ;
return 0 ;
}
}
static void F_115 ( struct V_4 * V_358 )
{
int V_15 = 0 ;
unsigned long V_90 ;
if ( ! V_358 )
return;
F_9 ( & V_358 -> V_25 ) ;
F_207 ( & V_358 -> V_46 ) ;
F_194 ( V_358 ) ;
F_33 ( & V_358 -> V_93 , V_90 ) ;
while ( V_358 -> V_9 || ( V_358 -> V_38 != V_54 ) ) {
F_35 ( & V_358 -> V_93 , V_90 ) ;
F_49 ( V_358 ) ;
F_170 ( 1 ) ;
F_33 ( & V_358 -> V_93 , V_90 ) ;
}
F_17 ( V_358 ) ;
F_35 ( & V_358 -> V_93 , V_90 ) ;
while ( V_358 -> V_9 || ( V_358 -> V_38 != V_54 ) ) {
F_49 ( V_358 ) ;
F_170 ( 1 ) ;
}
if ( V_358 -> V_142 )
V_358 -> V_142 ( V_358 ) ;
while ( V_358 -> V_9 || ( V_358 -> V_38 != V_54 ) ) {
F_49 ( V_358 ) ;
F_170 ( 1 ) ;
}
if ( V_358 -> V_7 )
V_15 = F_208 ( V_358 -> V_7 ) ;
if ( V_15 ) {
F_12 (KERN_ERR PFX L_133 ,
rv) ;
}
if ( V_358 -> V_32 )
V_358 -> V_32 -> V_340 ( V_358 -> V_34 ) ;
F_116 ( V_358 -> V_34 ) ;
if ( V_358 -> V_272 )
V_358 -> V_272 ( V_358 ) ;
if ( V_358 -> V_154 )
V_358 -> V_154 ( V_358 ) ;
if ( V_358 -> V_335 )
F_210 ( V_358 -> V_259 ) ;
F_116 ( V_358 ) ;
}
static void F_220 ( void )
{
struct V_4 * V_189 , * V_190 ;
if ( ! V_343 )
return;
#ifdef F_213
if ( V_349 )
F_221 ( & V_348 ) ;
#endif
#ifdef F_215
if ( V_352 )
F_222 ( & V_351 ) ;
#endif
#ifdef F_218
if ( V_355 )
F_223 ( & V_354 ) ;
#endif
F_224 ( & V_334 ) ;
F_117 ( & V_191 ) ;
F_118 (e, tmp_e, &smi_infos, link)
F_115 ( V_189 ) ;
F_119 ( & V_191 ) ;
}
