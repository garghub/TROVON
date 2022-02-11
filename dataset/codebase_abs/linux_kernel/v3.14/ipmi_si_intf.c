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
V_139 ,
V_140 ,
V_138 ) ;
if ( ! V_15 )
V_138 -> V_121 . V_122 ( & V_138 -> V_121 , V_123 ,
V_125 ) ;
} else
V_15 = F_66 ( V_138 -> V_44 ,
F_52 ,
V_139 ,
V_140 ,
V_138 ) ;
if ( V_15 ) {
F_26 ( V_138 -> V_67 , L_17
L_18 ,
V_140 , V_138 -> V_44 ) ;
V_138 -> V_44 = 0 ;
} else {
V_138 -> V_141 = F_63 ;
F_67 ( V_138 -> V_67 , L_19 , V_138 -> V_44 ) ;
}
return V_15 ;
}
static unsigned char F_68 ( struct V_142 * V_121 , unsigned int V_143 )
{
unsigned int V_144 = V_121 -> V_145 ;
return F_69 ( V_144 + ( V_143 * V_121 -> V_146 ) ) ;
}
static void F_70 ( struct V_142 * V_121 , unsigned int V_143 ,
unsigned char V_147 )
{
unsigned int V_144 = V_121 -> V_145 ;
F_71 ( V_147 , V_144 + ( V_143 * V_121 -> V_146 ) ) ;
}
static unsigned char F_72 ( struct V_142 * V_121 , unsigned int V_143 )
{
unsigned int V_144 = V_121 -> V_145 ;
return ( F_73 ( V_144 + ( V_143 * V_121 -> V_146 ) ) >> V_121 -> V_148 ) & 0xff ;
}
static void F_74 ( struct V_142 * V_121 , unsigned int V_143 ,
unsigned char V_147 )
{
unsigned int V_144 = V_121 -> V_145 ;
F_75 ( V_147 << V_121 -> V_148 , V_144 + ( V_143 * V_121 -> V_146 ) ) ;
}
static unsigned char F_76 ( struct V_142 * V_121 , unsigned int V_143 )
{
unsigned int V_144 = V_121 -> V_145 ;
return ( F_77 ( V_144 + ( V_143 * V_121 -> V_146 ) ) >> V_121 -> V_148 ) & 0xff ;
}
static void F_78 ( struct V_142 * V_121 , unsigned int V_143 ,
unsigned char V_147 )
{
unsigned int V_144 = V_121 -> V_145 ;
F_79 ( V_147 << V_121 -> V_148 , V_144 + ( V_143 * V_121 -> V_146 ) ) ;
}
static void F_80 ( struct V_4 * V_138 )
{
unsigned int V_144 = V_138 -> V_121 . V_145 ;
int V_149 ;
if ( V_144 ) {
for ( V_149 = 0 ; V_149 < V_138 -> V_150 ; V_149 ++ )
F_81 ( V_144 + V_149 * V_138 -> V_121 . V_146 ,
V_138 -> V_121 . V_151 ) ;
}
}
static int F_82 ( struct V_4 * V_138 )
{
unsigned int V_144 = V_138 -> V_121 . V_145 ;
int V_149 ;
if ( ! V_144 )
return - V_152 ;
V_138 -> V_153 = F_80 ;
switch ( V_138 -> V_121 . V_151 ) {
case 1 :
V_138 -> V_121 . V_154 = F_68 ;
V_138 -> V_121 . V_122 = F_70 ;
break;
case 2 :
V_138 -> V_121 . V_154 = F_72 ;
V_138 -> V_121 . V_122 = F_74 ;
break;
case 4 :
V_138 -> V_121 . V_154 = F_76 ;
V_138 -> V_121 . V_122 = F_78 ;
break;
default:
F_26 ( V_138 -> V_67 , L_20 ,
V_138 -> V_121 . V_151 ) ;
return - V_155 ;
}
for ( V_149 = 0 ; V_149 < V_138 -> V_150 ; V_149 ++ ) {
if ( F_83 ( V_144 + V_149 * V_138 -> V_121 . V_146 ,
V_138 -> V_121 . V_151 , V_140 ) == NULL ) {
while ( V_149 -- ) {
F_81 ( V_144 + V_149 * V_138 -> V_121 . V_146 ,
V_138 -> V_121 . V_151 ) ;
}
return - V_156 ;
}
}
return 0 ;
}
static unsigned char F_84 ( struct V_142 * V_121 , unsigned int V_143 )
{
return F_85 ( ( V_121 -> V_144 ) + ( V_143 * V_121 -> V_146 ) ) ;
}
static void F_86 ( struct V_142 * V_121 , unsigned int V_143 ,
unsigned char V_147 )
{
F_87 ( V_147 , ( V_121 -> V_144 ) + ( V_143 * V_121 -> V_146 ) ) ;
}
static unsigned char F_88 ( struct V_142 * V_121 , unsigned int V_143 )
{
return ( F_89 ( ( V_121 -> V_144 ) + ( V_143 * V_121 -> V_146 ) ) >> V_121 -> V_148 )
& 0xff ;
}
static void F_90 ( struct V_142 * V_121 , unsigned int V_143 ,
unsigned char V_147 )
{
F_87 ( V_147 << V_121 -> V_148 , ( V_121 -> V_144 ) + ( V_143 * V_121 -> V_146 ) ) ;
}
static unsigned char F_91 ( struct V_142 * V_121 , unsigned int V_143 )
{
return ( F_92 ( ( V_121 -> V_144 ) + ( V_143 * V_121 -> V_146 ) ) >> V_121 -> V_148 )
& 0xff ;
}
static void F_93 ( struct V_142 * V_121 , unsigned int V_143 ,
unsigned char V_147 )
{
F_94 ( V_147 << V_121 -> V_148 , ( V_121 -> V_144 ) + ( V_143 * V_121 -> V_146 ) ) ;
}
static unsigned char F_95 ( struct V_142 * V_121 , unsigned int V_143 )
{
return ( F_96 ( ( V_121 -> V_144 ) + ( V_143 * V_121 -> V_146 ) ) >> V_121 -> V_148 )
& 0xff ;
}
static void F_97 ( struct V_142 * V_121 , unsigned int V_143 ,
unsigned char V_147 )
{
F_98 ( V_147 << V_121 -> V_148 , ( V_121 -> V_144 ) + ( V_143 * V_121 -> V_146 ) ) ;
}
static void F_99 ( struct V_4 * V_138 )
{
unsigned long V_144 = V_138 -> V_121 . V_145 ;
int V_157 ;
if ( V_138 -> V_121 . V_144 ) {
F_100 ( V_138 -> V_121 . V_144 ) ;
V_157 = ( ( V_138 -> V_150 * V_138 -> V_121 . V_146 )
- ( V_138 -> V_121 . V_146 - V_138 -> V_121 . V_151 ) ) ;
F_101 ( V_144 , V_157 ) ;
}
}
static int F_102 ( struct V_4 * V_138 )
{
unsigned long V_144 = V_138 -> V_121 . V_145 ;
int V_157 ;
if ( ! V_144 )
return - V_152 ;
V_138 -> V_153 = F_99 ;
switch ( V_138 -> V_121 . V_151 ) {
case 1 :
V_138 -> V_121 . V_154 = F_84 ;
V_138 -> V_121 . V_122 = F_86 ;
break;
case 2 :
V_138 -> V_121 . V_154 = F_88 ;
V_138 -> V_121 . V_122 = F_90 ;
break;
case 4 :
V_138 -> V_121 . V_154 = F_91 ;
V_138 -> V_121 . V_122 = F_93 ;
break;
#ifdef F_96
case 8 :
V_138 -> V_121 . V_154 = F_95 ;
V_138 -> V_121 . V_122 = F_97 ;
break;
#endif
default:
F_26 ( V_138 -> V_67 , L_20 ,
V_138 -> V_121 . V_151 ) ;
return - V_155 ;
}
V_157 = ( ( V_138 -> V_150 * V_138 -> V_121 . V_146 )
- ( V_138 -> V_121 . V_146 - V_138 -> V_121 . V_151 ) ) ;
if ( F_103 ( V_144 , V_157 , V_140 ) == NULL )
return - V_156 ;
V_138 -> V_121 . V_144 = F_104 ( V_144 , V_157 ) ;
if ( V_138 -> V_121 . V_144 == NULL ) {
F_101 ( V_144 , V_157 ) ;
return - V_156 ;
}
return 0 ;
}
static int F_105 ( struct V_158 * V_159 , int * V_160 , char * V_161 , char * * V_162 )
{
char * V_163 ;
int V_164 ;
V_163 = strchr ( * V_162 , ',' ) ;
if ( ! V_163 ) {
F_12 (KERN_WARNING PFX L_21 , name) ;
return - V_155 ;
}
* V_163 = '\0' ;
V_163 ++ ;
for ( V_164 = 0 ; V_165 [ V_164 ] . V_161 ; V_164 ++ ) {
if ( strcmp ( * V_162 , V_159 [ V_164 ] . V_161 ) == 0 ) {
* V_160 = V_159 [ V_164 ] . V_160 ;
* V_162 = V_163 ;
return 0 ;
}
}
F_12 (KERN_WARNING PFX L_22 , name, *curr) ;
return - V_155 ;
}
static int F_106 ( const char * V_162 , const char * V_166 ,
const char * V_161 , int * V_160 )
{
char * V_167 ;
if ( strcmp ( V_162 , V_161 ) == 0 ) {
if ( ! V_166 ) {
F_12 (KERN_WARNING PFX
L_23 ,
curr) ;
return - V_155 ;
}
* V_160 = F_107 ( V_166 , & V_167 , 0 ) ;
if ( ( * V_167 != '\0' ) || ( * V_166 == '\0' ) ) {
F_12 (KERN_WARNING PFX
L_24 ,
curr) ;
return - V_155 ;
}
return 1 ;
}
return 0 ;
}
static struct V_4 * F_108 ( void )
{
struct V_4 * V_138 = F_109 ( sizeof( * V_138 ) , V_168 ) ;
if ( V_138 )
F_110 ( & V_138 -> V_93 ) ;
return V_138 ;
}
static int F_111 ( const char * V_160 , struct V_169 * V_170 )
{
char * V_171 = F_112 ( V_160 , V_168 ) ;
int V_15 ;
char * V_21 , * V_162 , * V_163 , * V_167 , * V_172 ;
enum V_173 V_174 ;
enum V_131 V_131 ;
int V_175 ;
unsigned long V_144 ;
int V_146 ;
int V_151 ;
int V_148 ;
int V_44 ;
int V_176 ;
int V_177 ;
int V_65 ;
struct V_4 * V_138 ;
if ( ! V_171 )
return - V_178 ;
V_65 = strlen ( V_171 ) ;
V_177 = V_65 - 1 ;
while ( ( V_177 >= 0 ) && isspace ( V_171 [ V_177 ] ) ) {
V_171 [ V_177 ] = '\0' ;
V_177 -- ;
}
for ( V_162 = V_171 ; V_162 ; V_162 = V_21 ) {
V_146 = 1 ;
V_151 = 1 ;
V_148 = 0 ;
V_44 = 0 ;
V_176 = 0 ;
V_21 = strchr ( V_162 , ':' ) ;
if ( V_21 ) {
* V_21 = '\0' ;
V_21 ++ ;
}
V_15 = F_105 ( V_165 , & V_177 , L_25 , & V_162 ) ;
if ( V_15 )
break;
V_174 = V_177 ;
V_15 = F_105 ( V_179 , & V_177 , L_26 , & V_162 ) ;
if ( V_15 )
break;
V_131 = V_177 ;
V_15 = F_105 ( V_180 , & V_175 , L_27 , & V_162 ) ;
if ( V_15 )
break;
V_163 = strchr ( V_162 , ',' ) ;
if ( V_163 ) {
* V_163 = '\0' ;
V_163 ++ ;
}
V_144 = F_107 ( V_162 , & V_167 , 0 ) ;
if ( ( * V_167 != '\0' ) || ( * V_162 == '\0' ) ) {
F_12 (KERN_WARNING PFX L_28
L_29 , curr) ;
break;
}
while ( V_163 ) {
V_162 = V_163 ;
V_163 = strchr ( V_162 , ',' ) ;
if ( V_163 ) {
* V_163 = '\0' ;
V_163 ++ ;
}
V_172 = strchr ( V_162 , '=' ) ;
if ( V_172 ) {
* V_172 = '\0' ;
V_172 ++ ;
}
V_15 = F_106 ( V_162 , V_172 , L_30 , & V_146 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = F_106 ( V_162 , V_172 , L_31 , & V_151 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = F_106 ( V_162 , V_172 , L_32 , & V_148 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = F_106 ( V_162 , V_172 , L_33 , & V_44 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = F_106 ( V_162 , V_172 , L_34 , & V_176 ) ;
if ( V_15 < 0 )
goto V_31;
else if ( V_15 )
continue;
V_15 = - V_155 ;
F_12 (KERN_WARNING PFX
L_35 ,
curr) ;
goto V_31;
}
if ( V_174 == V_181 ) {
V_138 = F_108 () ;
if ( ! V_138 ) {
V_15 = - V_178 ;
goto V_31;
}
V_138 -> V_136 = V_182 ;
V_138 -> V_131 = V_131 ;
V_138 -> V_121 . V_145 = V_144 ;
V_138 -> V_121 . V_183 = V_175 ;
if ( V_175 == V_184 )
V_138 -> V_185 = F_102 ;
else
V_138 -> V_185 = F_82 ;
V_138 -> V_121 . V_144 = NULL ;
V_138 -> V_121 . V_146 = V_146 ;
if ( ! V_138 -> V_121 . V_146 )
V_138 -> V_121 . V_146 = V_186 ;
V_138 -> V_121 . V_151 = V_151 ;
if ( ! V_138 -> V_121 . V_151 )
V_138 -> V_121 . V_151 = V_186 ;
V_138 -> V_121 . V_148 = V_148 ;
V_138 -> V_44 = V_44 ;
if ( V_138 -> V_44 )
V_138 -> V_128 = F_65 ;
V_138 -> V_187 = V_176 ;
V_15 = F_113 ( V_138 ) ;
if ( V_15 ) {
F_114 ( V_138 ) ;
goto V_31;
}
V_15 = F_115 ( V_138 ) ;
if ( V_15 ) {
F_116 ( V_138 ) ;
goto V_31;
}
} else {
struct V_4 * V_188 , * V_189 ;
F_117 ( & V_190 ) ;
F_118 (e, tmp_e, &smi_infos, link) {
if ( V_188 -> V_121 . V_183 != V_175 )
continue;
if ( V_188 -> V_131 != V_131 )
continue;
if ( V_188 -> V_121 . V_145 == V_144 )
F_116 ( V_188 ) ;
}
F_119 ( & V_190 ) ;
}
}
V_15 = V_65 ;
V_31:
F_114 ( V_171 ) ;
return V_15 ;
}
static int F_120 ( void )
{
int V_191 = - V_152 ;
int V_164 ;
struct V_4 * V_138 ;
for ( V_164 = 0 ; V_164 < V_192 ; V_164 ++ ) {
if ( ! V_193 [ V_164 ] && ! V_194 [ V_164 ] )
continue;
V_138 = F_108 () ;
if ( ! V_138 )
return - V_178 ;
V_138 -> V_136 = V_195 ;
F_12 (KERN_INFO PFX L_36 ) ;
if ( ! V_131 [ V_164 ] || strcmp ( V_131 [ V_164 ] , L_37 ) == 0 ) {
V_138 -> V_131 = V_196 ;
} else if ( strcmp ( V_131 [ V_164 ] , L_38 ) == 0 ) {
V_138 -> V_131 = V_197 ;
} else if ( strcmp ( V_131 [ V_164 ] , L_39 ) == 0 ) {
V_138 -> V_131 = V_132 ;
} else {
F_12 (KERN_WARNING PFX L_40
L_41 ,
i, si_type[i]) ;
F_114 ( V_138 ) ;
continue;
}
if ( V_193 [ V_164 ] ) {
V_138 -> V_185 = F_82 ;
V_138 -> V_121 . V_145 = V_193 [ V_164 ] ;
V_138 -> V_121 . V_183 = V_198 ;
} else if ( V_194 [ V_164 ] ) {
V_138 -> V_185 = F_102 ;
V_138 -> V_121 . V_145 = V_194 [ V_164 ] ;
V_138 -> V_121 . V_183 = V_184 ;
} else {
F_12 (KERN_WARNING PFX L_40
L_42
L_43 , i) ;
F_114 ( V_138 ) ;
continue;
}
V_138 -> V_121 . V_144 = NULL ;
V_138 -> V_121 . V_146 = V_199 [ V_164 ] ;
if ( ! V_138 -> V_121 . V_146 )
V_138 -> V_121 . V_146 = V_186 ;
V_138 -> V_121 . V_151 = V_200 [ V_164 ] ;
if ( ! V_138 -> V_121 . V_151 )
V_138 -> V_121 . V_151 = V_186 ;
V_138 -> V_121 . V_148 = V_201 [ V_164 ] ;
V_138 -> V_44 = V_202 [ V_164 ] ;
if ( V_138 -> V_44 )
V_138 -> V_128 = F_65 ;
V_138 -> V_187 = V_203 [ V_164 ] ;
if ( ! F_113 ( V_138 ) ) {
if ( F_115 ( V_138 ) )
F_116 ( V_138 ) ;
V_191 = 0 ;
} else {
F_114 ( V_138 ) ;
}
}
return V_191 ;
}
static T_3 F_121 ( T_4 V_204 ,
T_3 V_205 , void * V_206 )
{
struct V_4 * V_4 = V_206 ;
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
return V_207 ;
}
static void F_122 ( struct V_4 * V_138 )
{
if ( ! V_138 -> V_44 )
return;
F_123 ( NULL , V_138 -> V_44 , & F_121 ) ;
}
static int F_124 ( struct V_4 * V_138 )
{
T_5 V_208 ;
if ( ! V_138 -> V_44 )
return 0 ;
V_208 = F_125 ( NULL ,
V_138 -> V_44 ,
V_209 ,
& F_121 ,
V_138 ) ;
if ( V_208 != V_210 ) {
F_26 ( V_138 -> V_67 , L_45
L_18 , V_140 , V_138 -> V_44 ) ;
V_138 -> V_44 = 0 ;
return - V_155 ;
} else {
V_138 -> V_141 = F_122 ;
F_67 ( V_138 -> V_67 , L_46 , V_138 -> V_44 ) ;
return 0 ;
}
}
static int F_126 ( struct V_211 * V_212 )
{
struct V_4 * V_138 ;
int V_15 ;
if ( V_212 -> V_213 != 1 ) {
F_12 (KERN_INFO PFX L_47 , spmi->IPMIlegacy) ;
return - V_152 ;
}
V_138 = F_108 () ;
if ( ! V_138 ) {
F_12 (KERN_ERR PFX L_48 ) ;
return - V_178 ;
}
V_138 -> V_136 = V_214 ;
F_12 (KERN_INFO PFX L_49 ) ;
switch ( V_212 -> V_215 ) {
case 1 :
V_138 -> V_131 = V_196 ;
break;
case 2 :
V_138 -> V_131 = V_197 ;
break;
case 3 :
V_138 -> V_131 = V_132 ;
break;
default:
F_12 (KERN_INFO PFX L_50 ,
spmi->InterfaceType) ;
F_114 ( V_138 ) ;
return - V_156 ;
}
if ( V_212 -> V_216 & 1 ) {
V_138 -> V_44 = V_212 -> V_217 ;
V_138 -> V_128 = F_124 ;
} else if ( V_212 -> V_216 & 2 ) {
V_138 -> V_44 = V_212 -> V_218 ;
V_138 -> V_128 = F_65 ;
} else {
V_138 -> V_44 = 0 ;
V_138 -> V_128 = NULL ;
}
if ( V_212 -> V_144 . V_219 ) {
V_138 -> V_121 . V_146 = V_212 -> V_144 . V_219 / 8 ;
} else {
V_138 -> V_121 . V_146 = V_186 ;
}
V_138 -> V_121 . V_151 = V_138 -> V_121 . V_146 ;
V_138 -> V_121 . V_148 = V_212 -> V_144 . V_220 ;
if ( V_212 -> V_144 . V_221 == V_222 ) {
V_138 -> V_185 = F_102 ;
V_138 -> V_121 . V_183 = V_184 ;
} else if ( V_212 -> V_144 . V_221 == V_223 ) {
V_138 -> V_185 = F_82 ;
V_138 -> V_121 . V_183 = V_198 ;
} else {
F_114 ( V_138 ) ;
F_12 (KERN_WARNING PFX L_51 ) ;
return - V_156 ;
}
V_138 -> V_121 . V_145 = V_212 -> V_144 . V_224 ;
F_127 ( L_52 ,
( V_138 -> V_121 . V_183 == V_198 ) ? L_53 : L_54 ,
V_138 -> V_121 . V_145 , V_138 -> V_121 . V_151 , V_138 -> V_121 . V_146 ,
V_138 -> V_44 ) ;
V_15 = F_113 ( V_138 ) ;
if ( V_15 )
F_114 ( V_138 ) ;
return V_15 ;
}
static void F_128 ( void )
{
T_5 V_208 ;
struct V_211 * V_212 ;
int V_164 ;
if ( V_225 )
return;
if ( V_226 )
return;
for ( V_164 = 0 ; ; V_164 ++ ) {
V_208 = F_129 ( V_227 , V_164 + 1 ,
(struct V_228 * * ) & V_212 ) ;
if ( V_208 != V_210 )
return;
F_126 ( V_212 ) ;
}
}
static int F_130 ( struct V_229 * V_67 ,
const struct V_230 * V_231 )
{
struct V_232 * V_233 ;
struct V_4 * V_138 ;
struct V_234 * V_235 , * V_236 ;
T_4 V_237 ;
T_5 V_208 ;
unsigned long long V_238 ;
int V_15 ;
V_233 = F_131 ( V_67 ) ;
if ( ! V_233 )
return - V_152 ;
V_138 = F_108 () ;
if ( ! V_138 )
return - V_178 ;
V_138 -> V_136 = V_239 ;
F_12 (KERN_INFO PFX L_55 ) ;
V_237 = V_233 -> V_237 ;
V_138 -> V_137 . V_240 . T_4 = V_237 ;
V_208 = F_132 ( V_237 , L_56 , NULL , & V_238 ) ;
if ( F_133 ( V_208 ) )
goto V_241;
switch ( V_238 ) {
case 1 :
V_138 -> V_131 = V_196 ;
break;
case 2 :
V_138 -> V_131 = V_197 ;
break;
case 3 :
V_138 -> V_131 = V_132 ;
break;
default:
F_67 ( & V_67 -> V_67 , L_57 , V_238 ) ;
goto V_241;
}
V_235 = F_134 ( V_67 , V_242 , 0 ) ;
if ( V_235 ) {
V_138 -> V_185 = F_82 ;
V_138 -> V_121 . V_183 = V_198 ;
} else {
V_235 = F_134 ( V_67 , V_243 , 0 ) ;
if ( V_235 ) {
V_138 -> V_185 = F_102 ;
V_138 -> V_121 . V_183 = V_184 ;
}
}
if ( ! V_235 ) {
F_135 ( & V_67 -> V_67 , L_58 ) ;
goto V_241;
}
V_138 -> V_121 . V_145 = V_235 -> V_244 ;
V_138 -> V_121 . V_146 = V_186 ;
V_236 = F_134 ( V_67 ,
( V_138 -> V_121 . V_183 == V_198 ) ?
V_242 : V_243 ,
1 ) ;
if ( V_236 ) {
if ( V_236 -> V_244 > V_138 -> V_121 . V_145 )
V_138 -> V_121 . V_146 = V_236 -> V_244 - V_138 -> V_121 . V_145 ;
}
V_138 -> V_121 . V_151 = V_186 ;
V_138 -> V_121 . V_148 = 0 ;
V_208 = F_132 ( V_237 , L_59 , NULL , & V_238 ) ;
if ( F_136 ( V_208 ) ) {
V_138 -> V_44 = V_238 ;
V_138 -> V_128 = F_124 ;
} else if ( F_137 ( V_67 , 0 ) ) {
V_138 -> V_44 = F_138 ( V_67 , 0 ) ;
V_138 -> V_128 = F_65 ;
}
V_138 -> V_67 = & V_67 -> V_67 ;
F_139 ( V_67 , V_138 ) ;
F_67 ( V_138 -> V_67 , L_60 ,
V_235 , V_138 -> V_121 . V_151 , V_138 -> V_121 . V_146 ,
V_138 -> V_44 ) ;
V_15 = F_113 ( V_138 ) ;
if ( V_15 )
F_114 ( V_138 ) ;
return V_15 ;
V_241:
F_114 ( V_138 ) ;
return - V_155 ;
}
static void F_140 ( struct V_229 * V_67 )
{
struct V_4 * V_138 = F_141 ( V_67 ) ;
F_116 ( V_138 ) ;
}
static int F_142 ( const struct V_245 * V_246 ,
struct V_247 * V_248 )
{
const T_6 * V_12 = ( const T_6 * ) V_246 ;
unsigned long V_249 ;
T_6 V_250 ;
T_6 V_65 = V_246 -> V_251 ;
V_248 -> type = V_12 [ 4 ] ;
memcpy ( & V_249 , V_12 + 8 , sizeof( unsigned long ) ) ;
if ( V_65 >= 0x11 ) {
if ( V_249 & 1 ) {
V_249 &= 0xFFFE ;
V_248 -> V_175 = V_198 ;
} else
V_248 -> V_175 = V_184 ;
V_248 -> V_249 = V_249 | ( ( V_12 [ 0x10 ] & 0x10 ) >> 4 ) ;
V_248 -> V_44 = V_12 [ 0x11 ] ;
V_250 = ( V_12 [ 0x10 ] & 0xC0 ) >> 6 ;
switch ( V_250 ) {
case 0x00 :
V_248 -> V_143 = 1 ;
break;
case 0x01 :
V_248 -> V_143 = 4 ;
break;
case 0x02 :
V_248 -> V_143 = 16 ;
break;
default:
return - V_156 ;
}
} else {
V_248 -> V_249 = V_249 & 0xfffe ;
V_248 -> V_175 = V_198 ;
V_248 -> V_143 = 1 ;
}
V_248 -> V_187 = V_12 [ 6 ] ;
return 0 ;
}
static void F_143 ( struct V_247 * V_252 )
{
struct V_4 * V_138 ;
V_138 = F_108 () ;
if ( ! V_138 ) {
F_12 (KERN_ERR PFX L_61 ) ;
return;
}
V_138 -> V_136 = V_253 ;
F_12 (KERN_INFO PFX L_62 ) ;
switch ( V_252 -> type ) {
case 0x01 :
V_138 -> V_131 = V_196 ;
break;
case 0x02 :
V_138 -> V_131 = V_197 ;
break;
case 0x03 :
V_138 -> V_131 = V_132 ;
break;
default:
F_114 ( V_138 ) ;
return;
}
switch ( V_252 -> V_175 ) {
case V_184 :
V_138 -> V_185 = F_102 ;
V_138 -> V_121 . V_183 = V_184 ;
break;
case V_198 :
V_138 -> V_185 = F_82 ;
V_138 -> V_121 . V_183 = V_198 ;
break;
default:
F_114 ( V_138 ) ;
F_12 (KERN_WARNING PFX L_63 ,
ipmi_data->addr_space) ;
return;
}
V_138 -> V_121 . V_145 = V_252 -> V_249 ;
V_138 -> V_121 . V_146 = V_252 -> V_143 ;
if ( ! V_138 -> V_121 . V_146 )
V_138 -> V_121 . V_146 = V_186 ;
V_138 -> V_121 . V_151 = V_186 ;
V_138 -> V_121 . V_148 = 0 ;
V_138 -> V_187 = V_252 -> V_187 ;
V_138 -> V_44 = V_252 -> V_44 ;
if ( V_138 -> V_44 )
V_138 -> V_128 = F_65 ;
F_127 ( L_64 ,
( V_138 -> V_121 . V_183 == V_198 ) ? L_53 : L_54 ,
V_138 -> V_121 . V_145 , V_138 -> V_121 . V_151 , V_138 -> V_121 . V_146 ,
V_138 -> V_44 ) ;
if ( F_113 ( V_138 ) )
F_114 ( V_138 ) ;
}
static void F_144 ( void )
{
const struct V_254 * V_67 = NULL ;
struct V_247 V_12 ;
int V_15 ;
while ( ( V_67 = F_145 ( V_255 , NULL , V_67 ) ) ) {
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_15 = F_142 ( ( const struct V_245 * ) V_67 -> V_256 ,
& V_12 ) ;
if ( ! V_15 )
F_143 ( & V_12 ) ;
}
}
static void F_146 ( struct V_4 * V_138 )
{
struct V_257 * V_258 = V_138 -> V_259 ;
F_147 ( V_258 ) ;
}
static int F_148 ( struct V_4 * V_138 )
{
if ( V_138 -> V_131 == V_196 ) {
unsigned char V_208 ;
int V_146 ;
V_138 -> V_121 . V_151 = V_260 ;
V_138 -> V_121 . V_148 = 0 ;
V_138 -> V_150 = 2 ;
V_138 -> V_32 = & V_261 ;
for ( V_146 = V_186 ; V_146 <= 16 ; ) {
V_138 -> V_121 . V_146 = V_146 ;
if ( V_138 -> V_185 ( V_138 ) ) {
F_135 ( V_138 -> V_67 ,
L_65 ) ;
return V_186 ;
}
V_138 -> V_121 . V_122 ( & V_138 -> V_121 , 1 , 0x10 ) ;
V_208 = V_138 -> V_121 . V_154 ( & V_138 -> V_121 , 1 ) ;
V_138 -> V_153 ( V_138 ) ;
if ( V_208 )
return V_146 ;
V_146 *= 4 ;
}
}
return V_186 ;
}
static int F_149 ( struct V_257 * V_258 ,
const struct V_262 * V_263 )
{
int V_15 ;
int V_264 = V_258 -> V_265 & V_266 ;
struct V_4 * V_138 ;
V_138 = F_108 () ;
if ( ! V_138 )
return - V_178 ;
V_138 -> V_136 = V_267 ;
F_67 ( & V_258 -> V_67 , L_66 ) ;
switch ( V_264 ) {
case V_268 :
V_138 -> V_131 = V_197 ;
break;
case V_269 :
V_138 -> V_131 = V_196 ;
break;
case V_270 :
V_138 -> V_131 = V_132 ;
break;
default:
F_114 ( V_138 ) ;
F_67 ( & V_258 -> V_67 , L_67 , V_264 ) ;
return - V_178 ;
}
V_15 = F_150 ( V_258 ) ;
if ( V_15 ) {
F_135 ( & V_258 -> V_67 , L_68 ) ;
F_114 ( V_138 ) ;
return V_15 ;
}
V_138 -> V_271 = F_146 ;
V_138 -> V_259 = V_258 ;
if ( F_151 ( V_258 , 0 ) & V_242 ) {
V_138 -> V_185 = F_82 ;
V_138 -> V_121 . V_183 = V_198 ;
} else {
V_138 -> V_185 = F_102 ;
V_138 -> V_121 . V_183 = V_184 ;
}
V_138 -> V_121 . V_145 = F_152 ( V_258 , 0 ) ;
V_138 -> V_121 . V_146 = F_148 ( V_138 ) ;
V_138 -> V_121 . V_151 = V_260 ;
V_138 -> V_121 . V_148 = 0 ;
V_138 -> V_44 = V_258 -> V_44 ;
if ( V_138 -> V_44 )
V_138 -> V_128 = F_65 ;
V_138 -> V_67 = & V_258 -> V_67 ;
F_153 ( V_258 , V_138 ) ;
F_67 ( & V_258 -> V_67 , L_60 ,
& V_258 -> V_234 [ 0 ] , V_138 -> V_121 . V_151 , V_138 -> V_121 . V_146 ,
V_138 -> V_44 ) ;
V_15 = F_113 ( V_138 ) ;
if ( V_15 ) {
F_114 ( V_138 ) ;
F_147 ( V_258 ) ;
}
return V_15 ;
}
static void F_154 ( struct V_257 * V_258 )
{
struct V_4 * V_138 = F_155 ( V_258 ) ;
F_116 ( V_138 ) ;
F_147 ( V_258 ) ;
}
static int F_156 ( struct V_272 * V_67 )
{
#ifdef F_157
const struct V_273 * V_274 ;
struct V_4 * V_138 ;
struct V_234 V_234 ;
const T_7 * V_151 , * V_146 , * V_148 ;
struct V_275 * V_276 = V_67 -> V_67 . V_277 ;
int V_191 ;
int V_278 ;
F_67 ( & V_67 -> V_67 , L_69 ) ;
V_274 = F_158 ( V_279 , & V_67 -> V_67 ) ;
if ( ! V_274 )
return - V_155 ;
V_191 = F_159 ( V_276 , 0 , & V_234 ) ;
if ( V_191 ) {
F_26 ( & V_67 -> V_67 , V_280 L_70 ) ;
return V_191 ;
}
V_151 = F_160 ( V_276 , L_71 , & V_278 ) ;
if ( V_151 && V_278 != 4 ) {
F_26 ( & V_67 -> V_67 , V_280 L_72 ) ;
return - V_155 ;
}
V_146 = F_160 ( V_276 , L_73 , & V_278 ) ;
if ( V_146 && V_278 != 4 ) {
F_26 ( & V_67 -> V_67 , V_280 L_74 ) ;
return - V_155 ;
}
V_148 = F_160 ( V_276 , L_75 , & V_278 ) ;
if ( V_148 && V_278 != 4 ) {
F_26 ( & V_67 -> V_67 , V_280 L_76 ) ;
return - V_155 ;
}
V_138 = F_108 () ;
if ( ! V_138 ) {
F_135 ( & V_67 -> V_67 ,
L_77 ) ;
return - V_178 ;
}
V_138 -> V_131 = (enum V_131 ) V_274 -> V_12 ;
V_138 -> V_136 = V_281 ;
V_138 -> V_128 = F_65 ;
if ( V_234 . V_90 & V_242 ) {
V_138 -> V_185 = F_82 ;
V_138 -> V_121 . V_183 = V_198 ;
} else {
V_138 -> V_185 = F_102 ;
V_138 -> V_121 . V_183 = V_184 ;
}
V_138 -> V_121 . V_145 = V_234 . V_244 ;
V_138 -> V_121 . V_151 = V_151 ? F_161 ( V_151 ) : V_260 ;
V_138 -> V_121 . V_146 = V_146 ? F_161 ( V_146 ) : V_186 ;
V_138 -> V_121 . V_148 = V_148 ? F_161 ( V_148 ) : 0 ;
V_138 -> V_44 = F_162 ( V_67 -> V_67 . V_277 , 0 ) ;
V_138 -> V_67 = & V_67 -> V_67 ;
F_163 ( & V_67 -> V_67 , L_78 ,
V_138 -> V_121 . V_145 , V_138 -> V_121 . V_151 , V_138 -> V_121 . V_146 ,
V_138 -> V_44 ) ;
F_164 ( & V_67 -> V_67 , V_138 ) ;
V_191 = F_113 ( V_138 ) ;
if ( V_191 ) {
F_114 ( V_138 ) ;
return V_191 ;
}
#endif
return 0 ;
}
static int F_165 ( struct V_272 * V_67 )
{
#ifdef F_157
F_116 ( F_166 ( & V_67 -> V_67 ) ) ;
#endif
return 0 ;
}
static int F_167 ( struct V_282 * V_67 )
{
struct V_4 * V_138 ;
int V_15 ;
V_138 = F_108 () ;
if ( ! V_138 ) {
F_135 ( & V_67 -> V_67 ,
L_79 ) ;
return - V_178 ;
}
V_138 -> V_131 = V_196 ;
V_138 -> V_136 = V_281 ;
V_138 -> V_185 = F_102 ;
V_138 -> V_121 . V_183 = V_184 ;
V_138 -> V_121 . V_145 = V_67 -> V_283 . V_244 ;
V_138 -> V_121 . V_151 = 1 ;
V_138 -> V_121 . V_146 = 1 ;
V_138 -> V_121 . V_148 = 0 ;
V_138 -> V_44 = 0 ;
V_138 -> V_128 = NULL ;
V_138 -> V_67 = & V_67 -> V_67 ;
F_163 ( & V_67 -> V_67 , L_80 , V_138 -> V_121 . V_145 ) ;
F_164 ( & V_67 -> V_67 , V_138 ) ;
V_15 = F_113 ( V_138 ) ;
if ( V_15 ) {
F_114 ( V_138 ) ;
return V_15 ;
}
return 0 ;
}
static int F_168 ( struct V_282 * V_67 )
{
F_116 ( F_166 ( & V_67 -> V_67 ) ) ;
return 0 ;
}
static int F_169 ( struct V_4 * V_4 )
{
enum V_14 V_100 ;
V_100 = V_4 -> V_32 -> V_77 ( V_4 -> V_34 , 0 ) ;
for (; ; ) {
if ( V_100 == V_106 ||
V_100 == V_284 ) {
F_170 ( 1 ) ;
V_100 = V_4 -> V_32 -> V_77 (
V_4 -> V_34 , F_171 ( 1 ) ) ;
} else if ( V_100 == V_30 ) {
V_100 = V_4 -> V_32 -> V_77 (
V_4 -> V_34 , 0 ) ;
} else
break;
}
if ( V_100 == V_80 )
return - V_152 ;
return 0 ;
}
static int F_172 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 2 ] ;
unsigned char * V_285 ;
unsigned long V_286 ;
int V_15 = 0 ;
V_285 = F_173 ( V_63 , V_168 ) ;
if ( ! V_285 )
return - V_178 ;
V_6 [ 0 ] = V_36 << 2 ;
V_6 [ 1 ] = V_287 ;
V_4 -> V_32 -> V_33 ( V_4 -> V_34 , V_6 , 2 ) ;
V_15 = F_169 ( V_4 ) ;
if ( V_15 )
goto V_31;
V_286 = V_4 -> V_32 -> V_62 ( V_4 -> V_34 ,
V_285 , V_63 ) ;
V_15 = F_174 ( V_285 , V_286 , & V_4 -> V_288 ) ;
V_31:
F_114 ( V_285 ) ;
return V_15 ;
}
static int F_175 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 3 ] ;
unsigned char * V_285 ;
unsigned long V_286 ;
int V_15 = 0 ;
V_285 = F_173 ( V_63 , V_168 ) ;
if ( ! V_285 )
return - V_178 ;
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
V_286 = V_4 -> V_32 -> V_62 ( V_4 -> V_34 ,
V_285 , V_63 ) ;
if ( V_286 < 4 ||
V_285 [ 0 ] != ( V_36 | 1 ) << 2 ||
V_285 [ 1 ] != V_37 ||
V_285 [ 2 ] != 0 ) {
F_12 (KERN_WARNING PFX L_84
L_85 ) ;
V_15 = - V_155 ;
goto V_31;
}
if ( V_285 [ 3 ] & V_289 )
goto V_31;
V_6 [ 0 ] = V_36 << 2 ;
V_6 [ 1 ] = V_71 ;
V_6 [ 2 ] = V_285 [ 3 ] | V_289 ;
V_4 -> V_32 -> V_33 ( V_4 -> V_34 , V_6 , 3 ) ;
V_15 = F_169 ( V_4 ) ;
if ( V_15 ) {
F_12 (KERN_WARNING PFX L_86
L_87
L_83 ) ;
goto V_31;
}
V_286 = V_4 -> V_32 -> V_62 ( V_4 -> V_34 ,
V_285 , V_63 ) ;
if ( V_286 < 3 ||
V_285 [ 0 ] != ( V_36 | 1 ) << 2 ||
V_285 [ 1 ] != V_71 ) {
F_12 (KERN_WARNING PFX L_88
L_89 ) ;
V_15 = - V_155 ;
goto V_31;
}
if ( V_285 [ 2 ] != 0 )
V_15 = - V_290 ;
V_31:
F_114 ( V_285 ) ;
return V_15 ;
}
static int F_176 ( struct V_291 * V_292 , void * V_159 )
{
struct V_4 * V_134 = V_292 -> V_293 ;
return F_177 ( V_292 , L_90 , V_294 [ V_134 -> V_131 ] ) ;
}
static int F_178 ( struct V_295 * V_295 , struct V_296 * V_296 )
{
return F_179 ( V_296 , F_176 , F_180 ( V_295 ) ) ;
}
static int F_181 ( struct V_291 * V_292 , void * V_159 )
{
struct V_4 * V_134 = V_292 -> V_293 ;
F_177 ( V_292 , L_91 ,
V_134 -> V_44 && ! V_134 -> V_45 ) ;
F_177 ( V_292 , L_92 ,
F_182 ( V_134 , V_118 ) ) ;
F_177 ( V_292 , L_93 ,
F_182 ( V_134 , V_116 ) ) ;
F_177 ( V_292 , L_94 ,
F_182 ( V_134 , V_85 ) ) ;
F_177 ( V_292 , L_95 ,
F_182 ( V_134 , V_119 ) ) ;
F_177 ( V_292 , L_96 ,
F_182 ( V_134 , V_83 ) ) ;
F_177 ( V_292 , L_97 ,
F_182 ( V_134 , V_297 ) ) ;
F_177 ( V_292 , L_98 ,
F_182 ( V_134 , V_81 ) ) ;
F_177 ( V_292 , L_99 ,
F_182 ( V_134 , V_79 ) ) ;
F_177 ( V_292 , L_100 ,
F_182 ( V_134 , V_69 ) ) ;
F_177 ( V_292 , L_101 ,
F_182 ( V_134 , V_52 ) ) ;
F_177 ( V_292 , L_102 ,
F_182 ( V_134 , V_70 ) ) ;
return 0 ;
}
static int F_183 ( struct V_295 * V_295 , struct V_296 * V_296 )
{
return F_179 ( V_296 , F_181 , F_180 ( V_295 ) ) ;
}
static int F_184 ( struct V_291 * V_292 , void * V_159 )
{
struct V_4 * V_134 = V_292 -> V_293 ;
return F_177 ( V_292 ,
L_103 ,
V_294 [ V_134 -> V_131 ] ,
V_298 [ V_134 -> V_121 . V_183 ] ,
V_134 -> V_121 . V_145 ,
V_134 -> V_121 . V_146 ,
V_134 -> V_121 . V_151 ,
V_134 -> V_121 . V_148 ,
V_134 -> V_44 ,
V_134 -> V_187 ) ;
}
static int F_185 ( struct V_295 * V_295 , struct V_296 * V_296 )
{
return F_179 ( V_296 , F_184 , F_180 ( V_295 ) ) ;
}
static int F_186 ( struct V_4 * V_4 )
{
V_4 -> V_51 = ( ( V_4 -> V_51 & ~ V_60 ) |
V_53 ) ;
return 1 ;
}
static void F_187 ( struct V_4 * V_4 )
{
struct V_299 * V_300 = & V_4 -> V_288 ;
if ( V_300 -> V_301 == V_302 ) {
if ( V_300 -> V_288 == V_303 &&
V_300 -> V_304 == V_305 &&
V_300 -> V_306 == V_307 ) {
V_4 -> V_61 =
F_186 ;
} else if ( F_188 ( V_300 ) < 1 ||
( F_188 ( V_300 ) == 1 &&
F_189 ( V_300 ) < 5 ) ) {
V_4 -> V_61 =
F_186 ;
}
}
}
static void F_190 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_9 ;
V_6 -> V_11 [ 0 ] = V_6 -> V_12 [ 0 ] | 4 ;
V_6 -> V_11 [ 1 ] = V_6 -> V_12 [ 1 ] ;
V_6 -> V_11 [ 2 ] = V_308 ;
V_6 -> V_13 = 3 ;
V_4 -> V_9 = NULL ;
F_3 ( V_4 , V_6 ) ;
}
static int F_191 ( struct V_1 * V_309 ,
unsigned long V_310 ,
void * V_311 )
{
struct V_4 * V_4 = V_311 ;
unsigned char * V_12 = V_4 -> V_9 -> V_12 ;
unsigned int V_312 = V_4 -> V_9 -> V_35 ;
if ( V_312 >= 8 &&
( V_12 [ 0 ] >> 2 ) == V_313 &&
V_12 [ 1 ] == V_314 &&
V_12 [ 7 ] == 0x3A ) {
F_190 ( V_4 ) ;
return V_315 ;
}
return V_316 ;
}
static void
F_192 ( struct V_4 * V_4 )
{
struct V_299 * V_300 = & V_4 -> V_288 ;
if ( V_300 -> V_301 == V_302 &&
V_4 -> V_131 == V_132 )
F_1 ( & V_317 ) ;
}
static void F_193 ( struct V_4 * V_4 )
{
F_187 ( V_4 ) ;
}
static void F_194 ( struct V_4 * V_4 )
{
F_192 ( V_4 ) ;
}
static inline void F_195 ( struct V_4 * V_4 )
{
if ( V_4 -> V_7 ) {
if ( V_4 -> V_95 != NULL )
F_196 ( V_4 -> V_95 ) ;
F_197 ( & V_4 -> V_47 ) ;
}
}
static void F_198 ( void )
{
struct V_4 * V_138 ;
int V_164 ;
for ( V_164 = 0 ; ; V_164 ++ ) {
if ( ! V_318 [ V_164 ] . V_319 )
break;
#ifdef F_199
if ( F_200 ( V_318 [ V_164 ] . V_319 ) )
continue;
#endif
V_138 = F_108 () ;
if ( ! V_138 )
return;
V_138 -> V_136 = V_320 ;
V_138 -> V_131 = V_318 [ V_164 ] . type ;
V_138 -> V_185 = F_82 ;
V_138 -> V_121 . V_145 = V_318 [ V_164 ] . V_319 ;
V_138 -> V_121 . V_183 = V_198 ;
V_138 -> V_121 . V_144 = NULL ;
V_138 -> V_121 . V_146 = V_186 ;
V_138 -> V_121 . V_151 = V_186 ;
V_138 -> V_121 . V_148 = 0 ;
if ( F_113 ( V_138 ) == 0 ) {
if ( ( F_115 ( V_138 ) ) == 0 ) {
F_12 (KERN_INFO PFX L_104
L_105 ,
si_to_str[info->si_type],
addr_space_to_str[info->io.addr_type],
info->io.addr_data) ;
} else
F_116 ( V_138 ) ;
} else {
F_114 ( V_138 ) ;
}
}
}
static int F_201 ( struct V_4 * V_138 )
{
struct V_4 * V_188 ;
F_202 (e, &smi_infos, link) {
if ( V_188 -> V_121 . V_183 != V_138 -> V_121 . V_183 )
continue;
if ( V_188 -> V_121 . V_145 == V_138 -> V_121 . V_145 )
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
F_117 ( & V_190 ) ;
if ( ! F_201 ( V_126 ) ) {
F_12 ( V_321 L_107 ) ;
V_15 = - V_322 ;
goto V_323;
}
F_12 ( V_321 L_108 ) ;
V_126 -> V_7 = NULL ;
V_126 -> V_34 = NULL ;
V_126 -> V_32 = NULL ;
F_31 ( & V_126 -> V_25 , & V_324 ) ;
V_323:
F_119 ( & V_190 ) ;
return V_15 ;
}
static int F_115 ( struct V_4 * V_126 )
{
int V_15 = 0 ;
int V_164 ;
F_12 (KERN_INFO PFX L_109
L_110
L_111 ,
ipmi_addr_src_to_str[new_smi->addr_source],
si_to_str[new_smi->si_type],
addr_space_to_str[new_smi->io.addr_type],
new_smi->io.addr_data,
new_smi->slave_addr, new_smi->irq) ;
switch ( V_126 -> V_131 ) {
case V_196 :
V_126 -> V_32 = & V_261 ;
break;
case V_197 :
V_126 -> V_32 = & V_325 ;
break;
case V_132 :
V_126 -> V_32 = & V_326 ;
break;
default:
V_15 = - V_156 ;
goto V_323;
}
V_126 -> V_34 = F_173 ( V_126 -> V_32 -> V_312 () , V_168 ) ;
if ( ! V_126 -> V_34 ) {
F_12 (KERN_ERR PFX
L_112 ) ;
V_15 = - V_178 ;
goto V_323;
}
V_126 -> V_150 = V_126 -> V_32 -> V_327 ( V_126 -> V_34 ,
& V_126 -> V_121 ) ;
V_15 = V_126 -> V_185 ( V_126 ) ;
if ( V_15 ) {
F_12 (KERN_ERR PFX L_113 ) ;
goto V_323;
}
if ( V_126 -> V_32 -> V_328 ( V_126 -> V_34 ) ) {
if ( V_126 -> V_136 )
F_12 (KERN_INFO PFX L_114 ) ;
V_15 = - V_152 ;
goto V_323;
}
V_15 = F_172 ( V_126 ) ;
if ( V_15 ) {
if ( V_126 -> V_136 )
F_12 (KERN_INFO PFX L_115
L_116 ) ;
goto V_323;
}
F_193 ( V_126 ) ;
F_194 ( V_126 ) ;
F_203 ( & ( V_126 -> V_22 ) ) ;
F_203 ( & ( V_126 -> V_20 ) ) ;
V_126 -> V_9 = NULL ;
F_29 ( & V_126 -> V_86 , 0 ) ;
V_126 -> V_91 = 0 ;
for ( V_164 = 0 ; V_164 < V_329 ; V_164 ++ )
F_29 ( & V_126 -> V_330 [ V_164 ] , 0 ) ;
V_126 -> V_45 = 1 ;
F_29 ( & V_126 -> V_46 , 0 ) ;
V_126 -> V_103 = V_331 ;
V_331 ++ ;
V_15 = F_175 ( V_126 ) ;
if ( V_15 == 0 )
V_126 -> V_111 = 1 ;
F_16 ( V_126 ) ;
if ( V_126 -> V_44 )
V_126 -> V_38 = V_66 ;
if ( ! V_126 -> V_67 ) {
V_126 -> V_258 = F_204 ( L_117 ,
V_126 -> V_103 ) ;
if ( ! V_126 -> V_258 ) {
F_12 (KERN_ERR PFX
L_118 ) ;
goto V_323;
}
V_126 -> V_67 = & V_126 -> V_258 -> V_67 ;
V_126 -> V_67 -> V_332 = & V_333 . V_332 ;
V_15 = F_205 ( V_126 -> V_258 ) ;
if ( V_15 ) {
F_12 (KERN_ERR PFX
L_119
L_120 ,
rv) ;
goto V_323;
}
V_126 -> V_334 = 1 ;
}
V_15 = F_206 ( & V_32 ,
V_126 ,
& V_126 -> V_288 ,
V_126 -> V_67 ,
L_121 ,
V_126 -> V_187 ) ;
if ( V_15 ) {
F_135 ( V_126 -> V_67 , L_122 ,
V_15 ) ;
goto V_335;
}
V_15 = F_207 ( V_126 -> V_7 , L_123 ,
& V_336 ,
V_126 ) ;
if ( V_15 ) {
F_135 ( V_126 -> V_67 , L_124 , V_15 ) ;
goto V_335;
}
V_15 = F_207 ( V_126 -> V_7 , L_125 ,
& V_337 ,
V_126 ) ;
if ( V_15 ) {
F_135 ( V_126 -> V_67 , L_124 , V_15 ) ;
goto V_335;
}
V_15 = F_207 ( V_126 -> V_7 , L_126 ,
& V_338 ,
V_126 ) ;
if ( V_15 ) {
F_135 ( V_126 -> V_67 , L_124 , V_15 ) ;
goto V_335;
}
F_67 ( V_126 -> V_67 , L_127 ,
V_294 [ V_126 -> V_131 ] ) ;
return 0 ;
V_335:
F_208 ( & V_126 -> V_46 ) ;
F_195 ( V_126 ) ;
V_323:
V_126 -> V_45 = 1 ;
if ( V_126 -> V_7 ) {
F_209 ( V_126 -> V_7 ) ;
V_126 -> V_7 = NULL ;
}
if ( V_126 -> V_141 ) {
V_126 -> V_141 ( V_126 ) ;
V_126 -> V_141 = NULL ;
}
F_210 () ;
if ( V_126 -> V_34 ) {
if ( V_126 -> V_32 )
V_126 -> V_32 -> V_339 ( V_126 -> V_34 ) ;
F_114 ( V_126 -> V_34 ) ;
V_126 -> V_34 = NULL ;
}
if ( V_126 -> V_271 ) {
V_126 -> V_271 ( V_126 ) ;
V_126 -> V_271 = NULL ;
}
if ( V_126 -> V_153 ) {
V_126 -> V_153 ( V_126 ) ;
V_126 -> V_153 = NULL ;
}
if ( V_126 -> V_334 ) {
F_211 ( V_126 -> V_258 ) ;
V_126 -> V_334 = 0 ;
}
return V_15 ;
}
static int F_212 ( void )
{
int V_164 ;
char * V_171 ;
int V_15 ;
struct V_4 * V_188 ;
enum V_340 type = V_341 ;
if ( V_342 )
return 0 ;
V_342 = 1 ;
if ( V_343 ) {
V_15 = F_213 ( & V_333 ) ;
if ( V_15 ) {
F_12 (KERN_ERR PFX L_128
L_129 , rv) ;
return V_15 ;
}
}
V_171 = V_344 ;
if ( * V_171 != '\0' ) {
for ( V_164 = 0 ; ( V_164 < V_192 ) && ( * V_171 != '\0' ) ; V_164 ++ ) {
V_131 [ V_164 ] = V_171 ;
V_171 = strchr ( V_171 , ',' ) ;
if ( V_171 ) {
* V_171 = '\0' ;
V_171 ++ ;
} else {
break;
}
}
}
F_12 ( V_345 L_130 ) ;
if ( ! F_120 () )
return 0 ;
#ifdef F_214
if ( V_346 ) {
V_15 = F_215 ( & V_347 ) ;
if ( V_15 )
F_12 (KERN_ERR PFX L_128
L_131 , rv) ;
else
V_348 = 1 ;
}
#endif
#ifdef F_216
if ( V_349 ) {
F_217 ( & V_350 ) ;
V_351 = 1 ;
}
#endif
#ifdef F_218
if ( V_352 )
F_144 () ;
#endif
#ifdef F_216
if ( V_349 )
F_128 () ;
#endif
#ifdef F_219
F_220 ( & V_353 ) ;
V_354 = 1 ;
V_355 = 0 ;
#endif
F_117 ( & V_190 ) ;
F_202 (e, &smi_infos, link) {
if ( V_188 -> V_44 && ( ! type || V_188 -> V_136 == type ) ) {
if ( ! F_115 ( V_188 ) ) {
type = V_188 -> V_136 ;
}
}
}
if ( type ) {
F_119 ( & V_190 ) ;
return 0 ;
}
F_202 (e, &smi_infos, link) {
if ( ! V_188 -> V_44 && ( ! type || V_188 -> V_136 == type ) ) {
if ( ! F_115 ( V_188 ) ) {
type = V_188 -> V_136 ;
}
}
}
F_119 ( & V_190 ) ;
if ( type )
return 0 ;
if ( V_355 ) {
F_117 ( & V_190 ) ;
if ( F_8 ( & V_324 ) ) {
F_119 ( & V_190 ) ;
F_198 () ;
} else
F_119 ( & V_190 ) ;
}
F_117 ( & V_190 ) ;
if ( V_356 && F_8 ( & V_324 ) ) {
F_119 ( & V_190 ) ;
F_221 () ;
F_12 (KERN_WARNING PFX
L_132 ) ;
return - V_152 ;
} else {
F_119 ( & V_190 ) ;
return 0 ;
}
}
static void F_116 ( struct V_4 * V_357 )
{
int V_15 = 0 ;
unsigned long V_90 ;
if ( ! V_357 )
return;
F_9 ( & V_357 -> V_25 ) ;
F_208 ( & V_357 -> V_46 ) ;
F_195 ( V_357 ) ;
F_33 ( & V_357 -> V_93 , V_90 ) ;
while ( V_357 -> V_9 || ( V_357 -> V_38 != V_54 ) ) {
F_35 ( & V_357 -> V_93 , V_90 ) ;
F_49 ( V_357 ) ;
F_170 ( 1 ) ;
F_33 ( & V_357 -> V_93 , V_90 ) ;
}
F_17 ( V_357 ) ;
F_35 ( & V_357 -> V_93 , V_90 ) ;
while ( V_357 -> V_9 || ( V_357 -> V_38 != V_54 ) ) {
F_49 ( V_357 ) ;
F_170 ( 1 ) ;
}
if ( V_357 -> V_141 )
V_357 -> V_141 ( V_357 ) ;
while ( V_357 -> V_9 || ( V_357 -> V_38 != V_54 ) ) {
F_49 ( V_357 ) ;
F_170 ( 1 ) ;
}
if ( V_357 -> V_7 )
V_15 = F_209 ( V_357 -> V_7 ) ;
if ( V_15 ) {
F_12 (KERN_ERR PFX L_133 ,
rv) ;
}
if ( V_357 -> V_32 )
V_357 -> V_32 -> V_339 ( V_357 -> V_34 ) ;
F_114 ( V_357 -> V_34 ) ;
if ( V_357 -> V_271 )
V_357 -> V_271 ( V_357 ) ;
if ( V_357 -> V_153 )
V_357 -> V_153 ( V_357 ) ;
if ( V_357 -> V_334 )
F_211 ( V_357 -> V_258 ) ;
F_114 ( V_357 ) ;
}
static void F_221 ( void )
{
struct V_4 * V_188 , * V_189 ;
if ( ! V_342 )
return;
#ifdef F_214
if ( V_348 )
F_222 ( & V_347 ) ;
#endif
#ifdef F_216
if ( V_351 )
F_223 ( & V_350 ) ;
#endif
#ifdef F_219
if ( V_354 )
F_224 ( & V_353 ) ;
#endif
F_225 ( & V_333 ) ;
F_117 ( & V_190 ) ;
F_118 (e, tmp_e, &smi_infos, link)
F_116 ( V_188 ) ;
F_119 ( & V_190 ) ;
}
