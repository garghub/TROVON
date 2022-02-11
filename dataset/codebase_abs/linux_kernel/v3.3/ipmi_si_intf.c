static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_3 , V_2 ) ;
}
static void F_3 ( struct V_4 * V_4 ,
struct V_5 * V_6 )
{
if ( V_4 -> V_7 ) {
F_4 ( V_4 -> V_8 , V_6 ) ;
} else {
F_5 ( & ( V_4 -> V_9 ) ) ;
F_4 ( V_4 -> V_8 , V_6 ) ;
F_6 ( & ( V_4 -> V_9 ) ) ;
}
}
static void F_7 ( struct V_4 * V_4 , int V_10 )
{
struct V_5 * V_6 = V_4 -> V_11 ;
if ( V_10 < 0 || V_10 > V_12 )
V_10 = V_12 ;
V_6 -> V_13 [ 0 ] = V_6 -> V_14 [ 0 ] | 4 ;
V_6 -> V_13 [ 1 ] = V_6 -> V_14 [ 1 ] ;
V_6 -> V_13 [ 2 ] = V_10 ;
V_6 -> V_15 = 3 ;
V_4 -> V_11 = NULL ;
F_3 ( V_4 , V_6 ) ;
}
static enum V_16 F_8 ( struct V_4 * V_4 )
{
int V_17 ;
struct V_18 * V_19 = NULL ;
#ifdef F_9
struct V_20 V_21 ;
#endif
if ( ! V_4 -> V_7 )
F_6 ( & ( V_4 -> V_22 ) ) ;
if ( ! F_10 ( & ( V_4 -> V_23 ) ) ) {
V_19 = V_4 -> V_23 . V_24 ;
} else if ( ! F_10 ( & ( V_4 -> V_25 ) ) ) {
V_19 = V_4 -> V_25 . V_24 ;
}
if ( ! V_19 ) {
V_4 -> V_11 = NULL ;
V_17 = V_26 ;
} else {
int V_27 ;
F_11 ( V_19 ) ;
V_4 -> V_11 = F_12 ( V_19 ,
struct V_5 ,
V_28 ) ;
#ifdef F_9
F_13 ( & V_21 ) ;
F_14 ( V_29 L_1 , V_21 . V_30 , V_21 . V_31 ) ;
#endif
V_27 = F_15 ( & V_3 ,
0 , V_4 ) ;
if ( V_27 & V_32 ) {
V_17 = V_33 ;
goto V_34;
}
V_27 = V_4 -> V_35 -> V_36 (
V_4 -> V_37 ,
V_4 -> V_11 -> V_14 ,
V_4 -> V_11 -> V_38 ) ;
if ( V_27 )
F_7 ( V_4 , V_27 ) ;
V_17 = V_33 ;
}
V_34:
if ( ! V_4 -> V_7 )
F_5 ( & ( V_4 -> V_22 ) ) ;
return V_17 ;
}
static void F_16 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 2 ] ;
V_6 [ 0 ] = ( V_39 << 2 ) ;
V_6 [ 1 ] = V_40 ;
V_4 -> V_35 -> V_36 ( V_4 -> V_37 , V_6 , 2 ) ;
V_4 -> V_41 = V_42 ;
}
static void F_17 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 2 ] ;
V_6 [ 0 ] = ( V_39 << 2 ) ;
V_6 [ 1 ] = V_40 ;
V_4 -> V_35 -> V_36 ( V_4 -> V_37 , V_6 , 2 ) ;
V_4 -> V_41 = V_43 ;
}
static void F_18 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 3 ] ;
V_6 [ 0 ] = ( V_39 << 2 ) ;
V_6 [ 1 ] = V_44 ;
V_6 [ 2 ] = V_45 ;
V_4 -> V_35 -> V_36 ( V_4 -> V_37 , V_6 , 3 ) ;
V_4 -> V_41 = V_46 ;
}
static inline void F_19 ( struct V_4 * V_4 )
{
if ( ( V_4 -> V_47 ) && ( ! V_4 -> V_48 ) ) {
F_17 ( V_4 ) ;
V_4 -> V_48 = 1 ;
if ( ! F_20 ( & V_4 -> V_49 ) )
F_21 ( & V_4 -> V_50 ,
V_51 + V_52 ) ;
}
}
static inline void F_22 ( struct V_4 * V_4 )
{
if ( ( V_4 -> V_47 ) && ( V_4 -> V_48 ) ) {
F_16 ( V_4 ) ;
V_4 -> V_48 = 0 ;
}
}
static void F_23 ( struct V_4 * V_4 )
{
V_53:
if ( V_4 -> V_54 & V_45 ) {
F_24 ( V_4 , V_55 ) ;
F_18 ( V_4 ) ;
V_4 -> V_54 &= ~ V_45 ;
F_5 ( & ( V_4 -> V_9 ) ) ;
F_25 ( V_4 -> V_8 ) ;
F_6 ( & ( V_4 -> V_9 ) ) ;
} else if ( V_4 -> V_54 & V_56 ) {
V_4 -> V_11 = F_26 () ;
if ( ! V_4 -> V_11 ) {
F_19 ( V_4 ) ;
V_4 -> V_41 = V_57 ;
return;
}
F_22 ( V_4 ) ;
V_4 -> V_11 -> V_14 [ 0 ] = ( V_39 << 2 ) ;
V_4 -> V_11 -> V_14 [ 1 ] = V_58 ;
V_4 -> V_11 -> V_38 = 2 ;
V_4 -> V_35 -> V_36 (
V_4 -> V_37 ,
V_4 -> V_11 -> V_14 ,
V_4 -> V_11 -> V_38 ) ;
V_4 -> V_41 = V_59 ;
} else if ( V_4 -> V_54 & V_60 ) {
V_4 -> V_11 = F_26 () ;
if ( ! V_4 -> V_11 ) {
F_19 ( V_4 ) ;
V_4 -> V_41 = V_57 ;
return;
}
F_22 ( V_4 ) ;
V_4 -> V_11 -> V_14 [ 0 ] = ( V_39 << 2 ) ;
V_4 -> V_11 -> V_14 [ 1 ] = V_61 ;
V_4 -> V_11 -> V_38 = 2 ;
V_4 -> V_35 -> V_36 (
V_4 -> V_37 ,
V_4 -> V_11 -> V_14 ,
V_4 -> V_11 -> V_38 ) ;
V_4 -> V_41 = V_62 ;
} else if ( V_4 -> V_54 & V_63 &&
V_4 -> V_64 ) {
if ( V_4 -> V_64 ( V_4 ) )
goto V_53;
} else
V_4 -> V_41 = V_57 ;
}
static void F_27 ( struct V_4 * V_4 )
{
struct V_5 * V_6 ;
#ifdef F_9
struct V_20 V_21 ;
F_13 ( & V_21 ) ;
F_14 ( V_29 L_2 , V_21 . V_30 , V_21 . V_31 ) ;
#endif
switch ( V_4 -> V_41 ) {
case V_57 :
if ( ! V_4 -> V_11 )
break;
V_4 -> V_11 -> V_15
= V_4 -> V_35 -> V_65 (
V_4 -> V_37 ,
V_4 -> V_11 -> V_13 ,
V_66 ) ;
V_6 = V_4 -> V_11 ;
V_4 -> V_11 = NULL ;
F_3 ( V_4 , V_6 ) ;
break;
case V_67 :
{
unsigned char V_6 [ 4 ] ;
unsigned int V_68 ;
V_68 = V_4 -> V_35 -> V_65 ( V_4 -> V_37 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 ) {
V_4 -> V_41 = V_57 ;
} else if ( V_68 < 4 ) {
V_4 -> V_41 = V_57 ;
} else {
V_4 -> V_54 = V_6 [ 3 ] ;
F_23 ( V_4 ) ;
}
break;
}
case V_46 :
case V_69 :
{
unsigned char V_6 [ 3 ] ;
V_4 -> V_35 -> V_65 ( V_4 -> V_37 , V_6 , 3 ) ;
if ( V_6 [ 2 ] != 0 ) {
F_28 ( V_4 -> V_70 ,
L_3 , V_6 [ 2 ] ) ;
}
if ( V_4 -> V_41 == V_69 )
F_16 ( V_4 ) ;
else
V_4 -> V_41 = V_57 ;
break;
}
case V_62 :
{
V_4 -> V_11 -> V_15
= V_4 -> V_35 -> V_65 (
V_4 -> V_37 ,
V_4 -> V_11 -> V_13 ,
V_66 ) ;
V_6 = V_4 -> V_11 ;
V_4 -> V_11 = NULL ;
if ( V_6 -> V_13 [ 2 ] != 0 ) {
V_6 -> V_71 ( V_6 ) ;
V_4 -> V_54 &= ~ V_60 ;
F_23 ( V_4 ) ;
} else {
F_24 ( V_4 , V_72 ) ;
F_23 ( V_4 ) ;
F_3 ( V_4 , V_6 ) ;
}
break;
}
case V_59 :
{
V_4 -> V_11 -> V_15
= V_4 -> V_35 -> V_65 (
V_4 -> V_37 ,
V_4 -> V_11 -> V_13 ,
V_66 ) ;
V_6 = V_4 -> V_11 ;
V_4 -> V_11 = NULL ;
if ( V_6 -> V_13 [ 2 ] != 0 ) {
V_6 -> V_71 ( V_6 ) ;
V_4 -> V_54 &= ~ V_56 ;
F_23 ( V_4 ) ;
} else {
F_24 ( V_4 , V_73 ) ;
F_23 ( V_4 ) ;
F_3 ( V_4 , V_6 ) ;
}
break;
}
case V_42 :
{
unsigned char V_6 [ 4 ] ;
V_4 -> V_35 -> V_65 ( V_4 -> V_37 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 ) {
F_28 ( V_4 -> V_70 , L_4
L_5 ) ;
V_4 -> V_41 = V_57 ;
} else {
V_6 [ 0 ] = ( V_39 << 2 ) ;
V_6 [ 1 ] = V_74 ;
V_6 [ 2 ] = ( V_6 [ 3 ] |
V_75 |
V_76 ) ;
V_4 -> V_35 -> V_36 (
V_4 -> V_37 , V_6 , 3 ) ;
V_4 -> V_41 = V_77 ;
}
break;
}
case V_77 :
{
unsigned char V_6 [ 4 ] ;
V_4 -> V_35 -> V_65 ( V_4 -> V_37 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 )
F_28 ( V_4 -> V_70 , L_4
L_6 ) ;
else
V_4 -> V_48 = 0 ;
V_4 -> V_41 = V_57 ;
break;
}
case V_43 :
{
unsigned char V_6 [ 4 ] ;
V_4 -> V_35 -> V_65 ( V_4 -> V_37 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 ) {
F_28 ( V_4 -> V_70 , L_7
L_8 ) ;
V_4 -> V_41 = V_57 ;
} else {
V_6 [ 0 ] = ( V_39 << 2 ) ;
V_6 [ 1 ] = V_74 ;
V_6 [ 2 ] = ( V_6 [ 3 ] &
~ ( V_75 |
V_76 ) ) ;
V_4 -> V_35 -> V_36 (
V_4 -> V_37 , V_6 , 3 ) ;
V_4 -> V_41 = V_78 ;
}
break;
}
case V_78 :
{
unsigned char V_6 [ 4 ] ;
V_4 -> V_35 -> V_65 ( V_4 -> V_37 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 ) {
F_28 ( V_4 -> V_70 , L_7
L_9 ) ;
}
V_4 -> V_41 = V_57 ;
break;
}
}
}
static enum V_16 F_29 ( struct V_4 * V_4 ,
int time )
{
enum V_16 V_16 ;
V_79:
V_16 = V_4 -> V_35 -> V_80 ( V_4 -> V_37 , time ) ;
time = 0 ;
while ( V_16 == V_33 )
V_16 = V_4 -> V_35 -> V_80 ( V_4 -> V_37 , 0 ) ;
if ( V_16 == V_81 ) {
F_24 ( V_4 , V_82 ) ;
F_27 ( V_4 ) ;
V_16 = V_4 -> V_35 -> V_80 ( V_4 -> V_37 , 0 ) ;
} else if ( V_16 == V_83 ) {
F_24 ( V_4 , V_84 ) ;
V_4 -> V_41 = V_57 ;
if ( V_4 -> V_11 != NULL ) {
F_7 ( V_4 , V_12 ) ;
}
V_16 = V_4 -> V_35 -> V_80 ( V_4 -> V_37 , 0 ) ;
}
if ( F_30 ( V_4 -> V_8 ) && V_16 == V_85 ) {
unsigned char V_6 [ 2 ] ;
F_24 ( V_4 , V_86 ) ;
V_6 [ 0 ] = ( V_39 << 2 ) ;
V_6 [ 1 ] = V_87 ;
V_4 -> V_35 -> V_36 (
V_4 -> V_37 , V_6 , 2 ) ;
V_4 -> V_41 = V_67 ;
goto V_79;
}
if ( V_16 == V_26 ) {
F_24 ( V_4 , V_88 ) ;
V_16 = F_8 ( V_4 ) ;
if ( V_16 != V_26 )
goto V_79;
}
if ( ( V_16 == V_26 )
&& ( F_20 ( & V_4 -> V_89 ) ) ) {
F_31 ( & V_4 -> V_89 , 0 ) ;
V_4 -> V_11 = F_26 () ;
if ( ! V_4 -> V_11 )
goto V_34;
V_4 -> V_11 -> V_14 [ 0 ] = ( V_39 << 2 ) ;
V_4 -> V_11 -> V_14 [ 1 ] = V_61 ;
V_4 -> V_11 -> V_38 = 2 ;
V_4 -> V_35 -> V_36 (
V_4 -> V_37 ,
V_4 -> V_11 -> V_14 ,
V_4 -> V_11 -> V_38 ) ;
V_4 -> V_41 = V_62 ;
goto V_79;
}
V_34:
return V_16 ;
}
static void F_32 ( void * V_90 ,
struct V_5 * V_6 ,
int V_91 )
{
struct V_4 * V_4 = V_90 ;
enum V_16 V_92 ;
unsigned long V_93 ;
#ifdef F_9
struct V_20 V_21 ;
#endif
if ( F_20 ( & V_4 -> V_49 ) ) {
V_6 -> V_13 [ 0 ] = V_6 -> V_14 [ 0 ] | 4 ;
V_6 -> V_13 [ 1 ] = V_6 -> V_14 [ 1 ] ;
V_6 -> V_13 [ 2 ] = V_12 ;
V_6 -> V_15 = 3 ;
F_3 ( V_4 , V_6 ) ;
return;
}
#ifdef F_9
F_13 ( & V_21 ) ;
F_14 ( L_10 , V_21 . V_30 , V_21 . V_31 ) ;
#endif
V_4 -> V_94 = V_51 ;
F_21 ( & V_4 -> V_50 , V_51 + V_52 ) ;
if ( V_4 -> V_95 )
F_33 ( V_4 -> V_95 ) ;
if ( V_4 -> V_7 ) {
F_34 ( & ( V_6 -> V_28 ) , & ( V_4 -> V_25 ) ) ;
V_92 = F_29 ( V_4 , 0 ) ;
while ( V_92 != V_26 ) {
F_35 ( V_96 ) ;
V_92 = F_29 ( V_4 ,
V_96 ) ;
}
return;
}
F_36 ( & V_4 -> V_22 , V_93 ) ;
if ( V_91 > 0 )
F_34 ( & V_6 -> V_28 , & V_4 -> V_23 ) ;
else
F_34 ( & V_6 -> V_28 , & V_4 -> V_25 ) ;
F_37 ( & V_4 -> V_22 , V_93 ) ;
F_36 ( & V_4 -> V_9 , V_93 ) ;
if ( V_4 -> V_41 == V_57 && V_4 -> V_11 == NULL )
F_8 ( V_4 ) ;
F_37 ( & V_4 -> V_9 , V_93 ) ;
}
static void F_38 ( void * V_90 , int V_97 )
{
struct V_4 * V_4 = V_90 ;
enum V_16 V_92 ;
V_4 -> V_7 = V_97 ;
if ( V_97 ) {
V_92 = F_29 ( V_4 , 0 ) ;
while ( V_92 != V_26 ) {
F_35 ( V_96 ) ;
V_92 = F_29 ( V_4 ,
V_96 ) ;
}
}
}
static inline void F_39 ( struct V_98 * V_99 )
{
V_99 -> V_100 = - 1 ;
}
static inline int F_40 ( struct V_98 * V_99 )
{
return V_99 -> V_100 != - 1 ;
}
static int F_41 ( enum V_16 V_101 ,
const struct V_4 * V_4 ,
struct V_98 * V_102 )
{
unsigned int V_103 = 0 ;
if ( V_4 -> V_104 < V_105 )
V_103 = V_106 [ V_4 -> V_104 ] ;
if ( V_103 == 0 || V_101 != V_107 )
F_39 ( V_102 ) ;
else if ( ! F_40 ( V_102 ) ) {
F_42 ( V_102 ) ;
F_43 ( V_102 , V_103 * V_108 ) ;
} else {
struct V_98 V_109 ;
F_42 ( & V_109 ) ;
if ( F_44 ( F_45 ( & V_109 , V_102 ) > 0 ) ) {
F_39 ( V_102 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_46 ( void * V_14 )
{
struct V_4 * V_4 = V_14 ;
unsigned long V_93 ;
enum V_16 V_101 ;
struct V_98 V_102 ;
F_39 ( & V_102 ) ;
F_47 ( V_110 , 19 ) ;
while ( ! F_48 () ) {
int V_111 ;
F_36 ( & ( V_4 -> V_9 ) , V_93 ) ;
V_101 = F_29 ( V_4 , 0 ) ;
F_37 ( & ( V_4 -> V_9 ) , V_93 ) ;
V_111 = F_41 ( V_101 , V_4 ,
& V_102 ) ;
if ( V_101 == V_33 )
;
else if ( V_101 == V_107 && V_111 )
F_49 () ;
else if ( V_101 == V_26 )
F_50 ( 100 ) ;
else
F_50 ( 1 ) ;
}
return 0 ;
}
static void F_51 ( void * V_90 )
{
struct V_4 * V_4 = V_90 ;
unsigned long V_93 ;
F_35 ( 10 ) ;
F_36 ( & V_4 -> V_9 , V_93 ) ;
F_29 ( V_4 , 10 ) ;
F_37 ( & V_4 -> V_9 , V_93 ) ;
}
static void F_52 ( void * V_90 )
{
struct V_4 * V_4 = V_90 ;
if ( F_20 ( & V_4 -> V_49 ) ||
! V_4 -> V_112 )
return;
F_31 ( & V_4 -> V_89 , 1 ) ;
}
static void F_53 ( unsigned long V_14 )
{
struct V_4 * V_4 = (struct V_4 * ) V_14 ;
enum V_16 V_101 ;
unsigned long V_93 ;
unsigned long V_113 ;
long V_114 ;
long V_115 ;
#ifdef F_9
struct V_20 V_21 ;
#endif
F_36 ( & ( V_4 -> V_9 ) , V_93 ) ;
#ifdef F_9
F_13 ( & V_21 ) ;
F_14 ( V_29 L_11 , V_21 . V_30 , V_21 . V_31 ) ;
#endif
V_113 = V_51 ;
V_114 = ( ( ( long ) V_113 - ( long ) V_4 -> V_94 )
* V_116 ) ;
V_101 = F_29 ( V_4 , V_114 ) ;
F_37 ( & ( V_4 -> V_9 ) , V_93 ) ;
V_4 -> V_94 = V_113 ;
if ( ( V_4 -> V_47 ) && ( ! V_4 -> V_48 ) ) {
V_115 = V_51 + V_52 ;
F_24 ( V_4 , V_117 ) ;
goto V_118;
}
if ( V_101 == V_107 ) {
F_24 ( V_4 , V_119 ) ;
V_115 = V_51 + 1 ;
} else {
F_24 ( V_4 , V_117 ) ;
V_115 = V_51 + V_52 ;
}
V_118:
if ( V_101 != V_26 )
F_21 ( & ( V_4 -> V_50 ) , V_115 ) ;
}
static T_1 F_54 ( int V_47 , void * V_14 )
{
struct V_4 * V_4 = V_14 ;
unsigned long V_93 ;
#ifdef F_9
struct V_20 V_21 ;
#endif
F_36 ( & ( V_4 -> V_9 ) , V_93 ) ;
F_24 ( V_4 , V_120 ) ;
#ifdef F_9
F_13 ( & V_21 ) ;
F_14 ( V_29 L_12 , V_21 . V_30 , V_21 . V_31 ) ;
#endif
F_29 ( V_4 , 0 ) ;
F_37 ( & ( V_4 -> V_9 ) , V_93 ) ;
return V_121 ;
}
static T_1 F_55 ( int V_47 , void * V_14 )
{
struct V_4 * V_4 = V_14 ;
V_4 -> V_122 . V_123 ( & V_4 -> V_122 , V_124 ,
V_125
| V_126 ) ;
return F_54 ( V_47 , V_14 ) ;
}
static int F_56 ( void * V_90 ,
T_2 V_8 )
{
struct V_4 * V_127 = V_90 ;
int V_128 = 0 ;
V_127 -> V_8 = V_8 ;
if ( V_127 -> V_129 )
V_127 -> V_129 ( V_127 ) ;
F_57 ( & V_127 -> V_50 , F_53 , ( long ) V_127 ) ;
V_127 -> V_94 = V_51 ;
F_21 ( & V_127 -> V_50 , V_51 + V_52 ) ;
if ( V_127 -> V_104 < V_130 )
V_128 = V_131 [ V_127 -> V_104 ] ;
else if ( ( V_127 -> V_132 != V_133 ) && ( ! V_127 -> V_47 ) )
V_128 = 1 ;
if ( V_128 ) {
V_127 -> V_95 = F_58 ( F_46 , V_127 ,
L_13 , V_127 -> V_104 ) ;
if ( F_59 ( V_127 -> V_95 ) ) {
F_60 ( V_127 -> V_70 , L_14
L_15
L_16 ,
F_61 ( V_127 -> V_95 ) ) ;
V_127 -> V_95 = NULL ;
}
}
return 0 ;
}
static int F_62 ( void * V_90 , struct V_134 * V_14 )
{
struct V_4 * V_135 = V_90 ;
V_14 -> V_136 = V_135 -> V_137 ;
V_14 -> V_70 = V_135 -> V_70 ;
V_14 -> V_138 = V_135 -> V_138 ;
F_63 ( V_135 -> V_70 ) ;
return 0 ;
}
static void F_64 ( void * V_90 , int V_128 )
{
struct V_4 * V_4 = V_90 ;
if ( ! V_128 )
F_31 ( & V_4 -> V_89 , 0 ) ;
}
static void F_65 ( struct V_4 * V_139 )
{
if ( V_139 -> V_132 == V_133 )
V_139 -> V_122 . V_123 ( & V_139 -> V_122 , V_124 , 0 ) ;
F_66 ( V_139 -> V_47 , V_139 ) ;
}
static int F_67 ( struct V_4 * V_139 )
{
int V_17 ;
if ( ! V_139 -> V_47 )
return 0 ;
if ( V_139 -> V_132 == V_133 ) {
V_17 = F_68 ( V_139 -> V_47 ,
F_55 ,
V_140 | V_141 ,
V_142 ,
V_139 ) ;
if ( ! V_17 )
V_139 -> V_122 . V_123 ( & V_139 -> V_122 , V_124 ,
V_126 ) ;
} else
V_17 = F_68 ( V_139 -> V_47 ,
F_54 ,
V_140 | V_141 ,
V_142 ,
V_139 ) ;
if ( V_17 ) {
F_28 ( V_139 -> V_70 , L_17
L_18 ,
V_142 , V_139 -> V_47 ) ;
V_139 -> V_47 = 0 ;
} else {
V_139 -> V_143 = F_65 ;
F_69 ( V_139 -> V_70 , L_19 , V_139 -> V_47 ) ;
}
return V_17 ;
}
static unsigned char F_70 ( struct V_144 * V_122 , unsigned int V_145 )
{
unsigned int V_146 = V_122 -> V_147 ;
return F_71 ( V_146 + ( V_145 * V_122 -> V_148 ) ) ;
}
static void F_72 ( struct V_144 * V_122 , unsigned int V_145 ,
unsigned char V_149 )
{
unsigned int V_146 = V_122 -> V_147 ;
F_73 ( V_149 , V_146 + ( V_145 * V_122 -> V_148 ) ) ;
}
static unsigned char F_74 ( struct V_144 * V_122 , unsigned int V_145 )
{
unsigned int V_146 = V_122 -> V_147 ;
return ( F_75 ( V_146 + ( V_145 * V_122 -> V_148 ) ) >> V_122 -> V_150 ) & 0xff ;
}
static void F_76 ( struct V_144 * V_122 , unsigned int V_145 ,
unsigned char V_149 )
{
unsigned int V_146 = V_122 -> V_147 ;
F_77 ( V_149 << V_122 -> V_150 , V_146 + ( V_145 * V_122 -> V_148 ) ) ;
}
static unsigned char F_78 ( struct V_144 * V_122 , unsigned int V_145 )
{
unsigned int V_146 = V_122 -> V_147 ;
return ( F_79 ( V_146 + ( V_145 * V_122 -> V_148 ) ) >> V_122 -> V_150 ) & 0xff ;
}
static void F_80 ( struct V_144 * V_122 , unsigned int V_145 ,
unsigned char V_149 )
{
unsigned int V_146 = V_122 -> V_147 ;
F_81 ( V_149 << V_122 -> V_150 , V_146 + ( V_145 * V_122 -> V_148 ) ) ;
}
static void F_82 ( struct V_4 * V_139 )
{
unsigned int V_146 = V_139 -> V_122 . V_147 ;
int V_151 ;
if ( V_146 ) {
for ( V_151 = 0 ; V_151 < V_139 -> V_152 ; V_151 ++ )
F_83 ( V_146 + V_151 * V_139 -> V_122 . V_148 ,
V_139 -> V_122 . V_153 ) ;
}
}
static int F_84 ( struct V_4 * V_139 )
{
unsigned int V_146 = V_139 -> V_122 . V_147 ;
int V_151 ;
if ( ! V_146 )
return - V_154 ;
V_139 -> V_155 = F_82 ;
switch ( V_139 -> V_122 . V_153 ) {
case 1 :
V_139 -> V_122 . V_156 = F_70 ;
V_139 -> V_122 . V_123 = F_72 ;
break;
case 2 :
V_139 -> V_122 . V_156 = F_74 ;
V_139 -> V_122 . V_123 = F_76 ;
break;
case 4 :
V_139 -> V_122 . V_156 = F_78 ;
V_139 -> V_122 . V_123 = F_80 ;
break;
default:
F_28 ( V_139 -> V_70 , L_20 ,
V_139 -> V_122 . V_153 ) ;
return - V_157 ;
}
for ( V_151 = 0 ; V_151 < V_139 -> V_152 ; V_151 ++ ) {
if ( F_85 ( V_146 + V_151 * V_139 -> V_122 . V_148 ,
V_139 -> V_122 . V_153 , V_142 ) == NULL ) {
while ( V_151 -- ) {
F_83 ( V_146 + V_151 * V_139 -> V_122 . V_148 ,
V_139 -> V_122 . V_153 ) ;
}
return - V_158 ;
}
}
return 0 ;
}
static unsigned char F_86 ( struct V_144 * V_122 , unsigned int V_145 )
{
return F_87 ( ( V_122 -> V_146 ) + ( V_145 * V_122 -> V_148 ) ) ;
}
static void F_88 ( struct V_144 * V_122 , unsigned int V_145 ,
unsigned char V_149 )
{
F_89 ( V_149 , ( V_122 -> V_146 ) + ( V_145 * V_122 -> V_148 ) ) ;
}
static unsigned char F_90 ( struct V_144 * V_122 , unsigned int V_145 )
{
return ( F_91 ( ( V_122 -> V_146 ) + ( V_145 * V_122 -> V_148 ) ) >> V_122 -> V_150 )
& 0xff ;
}
static void F_92 ( struct V_144 * V_122 , unsigned int V_145 ,
unsigned char V_149 )
{
F_89 ( V_149 << V_122 -> V_150 , ( V_122 -> V_146 ) + ( V_145 * V_122 -> V_148 ) ) ;
}
static unsigned char F_93 ( struct V_144 * V_122 , unsigned int V_145 )
{
return ( F_94 ( ( V_122 -> V_146 ) + ( V_145 * V_122 -> V_148 ) ) >> V_122 -> V_150 )
& 0xff ;
}
static void F_95 ( struct V_144 * V_122 , unsigned int V_145 ,
unsigned char V_149 )
{
F_96 ( V_149 << V_122 -> V_150 , ( V_122 -> V_146 ) + ( V_145 * V_122 -> V_148 ) ) ;
}
static unsigned char F_97 ( struct V_144 * V_122 , unsigned int V_145 )
{
return ( F_98 ( ( V_122 -> V_146 ) + ( V_145 * V_122 -> V_148 ) ) >> V_122 -> V_150 )
& 0xff ;
}
static void F_99 ( struct V_144 * V_122 , unsigned int V_145 ,
unsigned char V_149 )
{
F_100 ( V_149 << V_122 -> V_150 , ( V_122 -> V_146 ) + ( V_145 * V_122 -> V_148 ) ) ;
}
static void F_101 ( struct V_4 * V_139 )
{
unsigned long V_146 = V_139 -> V_122 . V_147 ;
int V_159 ;
if ( V_139 -> V_122 . V_146 ) {
F_102 ( V_139 -> V_122 . V_146 ) ;
V_159 = ( ( V_139 -> V_152 * V_139 -> V_122 . V_148 )
- ( V_139 -> V_122 . V_148 - V_139 -> V_122 . V_153 ) ) ;
F_103 ( V_146 , V_159 ) ;
}
}
static int F_104 ( struct V_4 * V_139 )
{
unsigned long V_146 = V_139 -> V_122 . V_147 ;
int V_159 ;
if ( ! V_146 )
return - V_154 ;
V_139 -> V_155 = F_101 ;
switch ( V_139 -> V_122 . V_153 ) {
case 1 :
V_139 -> V_122 . V_156 = F_86 ;
V_139 -> V_122 . V_123 = F_88 ;
break;
case 2 :
V_139 -> V_122 . V_156 = F_90 ;
V_139 -> V_122 . V_123 = F_92 ;
break;
case 4 :
V_139 -> V_122 . V_156 = F_93 ;
V_139 -> V_122 . V_123 = F_95 ;
break;
#ifdef F_98
case 8 :
V_139 -> V_122 . V_156 = F_97 ;
V_139 -> V_122 . V_123 = F_99 ;
break;
#endif
default:
F_28 ( V_139 -> V_70 , L_20 ,
V_139 -> V_122 . V_153 ) ;
return - V_157 ;
}
V_159 = ( ( V_139 -> V_152 * V_139 -> V_122 . V_148 )
- ( V_139 -> V_122 . V_148 - V_139 -> V_122 . V_153 ) ) ;
if ( F_105 ( V_146 , V_159 , V_142 ) == NULL )
return - V_158 ;
V_139 -> V_122 . V_146 = F_106 ( V_146 , V_159 ) ;
if ( V_139 -> V_122 . V_146 == NULL ) {
F_103 ( V_146 , V_159 ) ;
return - V_158 ;
}
return 0 ;
}
static int F_107 ( struct V_160 * V_161 , int * V_162 , char * V_163 , char * * V_164 )
{
char * V_165 ;
int V_166 ;
V_165 = strchr ( * V_164 , ',' ) ;
if ( ! V_165 ) {
F_14 (KERN_WARNING PFX L_21 , name) ;
return - V_157 ;
}
* V_165 = '\0' ;
V_165 ++ ;
for ( V_166 = 0 ; V_167 [ V_166 ] . V_163 ; V_166 ++ ) {
if ( strcmp ( * V_164 , V_161 [ V_166 ] . V_163 ) == 0 ) {
* V_162 = V_161 [ V_166 ] . V_162 ;
* V_164 = V_165 ;
return 0 ;
}
}
F_14 (KERN_WARNING PFX L_22 , name, *curr) ;
return - V_157 ;
}
static int F_108 ( const char * V_164 , const char * V_168 ,
const char * V_163 , int * V_162 )
{
char * V_169 ;
if ( strcmp ( V_164 , V_163 ) == 0 ) {
if ( ! V_168 ) {
F_14 (KERN_WARNING PFX
L_23 ,
curr) ;
return - V_157 ;
}
* V_162 = F_109 ( V_168 , & V_169 , 0 ) ;
if ( ( * V_169 != '\0' ) || ( * V_168 == '\0' ) ) {
F_14 (KERN_WARNING PFX
L_24 ,
curr) ;
return - V_157 ;
}
return 1 ;
}
return 0 ;
}
static struct V_4 * F_110 ( void )
{
struct V_4 * V_139 = F_111 ( sizeof( * V_139 ) , V_170 ) ;
if ( V_139 ) {
F_112 ( & V_139 -> V_9 ) ;
F_112 ( & V_139 -> V_22 ) ;
}
return V_139 ;
}
static int F_113 ( const char * V_162 , struct V_171 * V_172 )
{
char * V_173 = F_114 ( V_162 , V_170 ) ;
int V_17 ;
char * V_24 , * V_164 , * V_165 , * V_169 , * V_174 ;
enum V_175 V_176 ;
enum V_132 V_132 ;
int V_177 ;
unsigned long V_146 ;
int V_148 ;
int V_153 ;
int V_150 ;
int V_47 ;
int V_178 ;
int V_179 ;
int V_68 ;
struct V_4 * V_139 ;
if ( ! V_173 )
return - V_180 ;
V_68 = strlen ( V_173 ) ;
V_179 = V_68 - 1 ;
while ( ( V_179 >= 0 ) && isspace ( V_173 [ V_179 ] ) ) {
V_173 [ V_179 ] = '\0' ;
V_179 -- ;
}
for ( V_164 = V_173 ; V_164 ; V_164 = V_24 ) {
V_148 = 1 ;
V_153 = 1 ;
V_150 = 0 ;
V_47 = 0 ;
V_178 = 0 ;
V_24 = strchr ( V_164 , ':' ) ;
if ( V_24 ) {
* V_24 = '\0' ;
V_24 ++ ;
}
V_17 = F_107 ( V_167 , & V_179 , L_25 , & V_164 ) ;
if ( V_17 )
break;
V_176 = V_179 ;
V_17 = F_107 ( V_181 , & V_179 , L_26 , & V_164 ) ;
if ( V_17 )
break;
V_132 = V_179 ;
V_17 = F_107 ( V_182 , & V_177 , L_27 , & V_164 ) ;
if ( V_17 )
break;
V_165 = strchr ( V_164 , ',' ) ;
if ( V_165 ) {
* V_165 = '\0' ;
V_165 ++ ;
}
V_146 = F_109 ( V_164 , & V_169 , 0 ) ;
if ( ( * V_169 != '\0' ) || ( * V_164 == '\0' ) ) {
F_14 (KERN_WARNING PFX L_28
L_29 , curr) ;
break;
}
while ( V_165 ) {
V_164 = V_165 ;
V_165 = strchr ( V_164 , ',' ) ;
if ( V_165 ) {
* V_165 = '\0' ;
V_165 ++ ;
}
V_174 = strchr ( V_164 , '=' ) ;
if ( V_174 ) {
* V_174 = '\0' ;
V_174 ++ ;
}
V_17 = F_108 ( V_164 , V_174 , L_30 , & V_148 ) ;
if ( V_17 < 0 )
goto V_34;
else if ( V_17 )
continue;
V_17 = F_108 ( V_164 , V_174 , L_31 , & V_153 ) ;
if ( V_17 < 0 )
goto V_34;
else if ( V_17 )
continue;
V_17 = F_108 ( V_164 , V_174 , L_32 , & V_150 ) ;
if ( V_17 < 0 )
goto V_34;
else if ( V_17 )
continue;
V_17 = F_108 ( V_164 , V_174 , L_33 , & V_47 ) ;
if ( V_17 < 0 )
goto V_34;
else if ( V_17 )
continue;
V_17 = F_108 ( V_164 , V_174 , L_34 , & V_178 ) ;
if ( V_17 < 0 )
goto V_34;
else if ( V_17 )
continue;
V_17 = - V_157 ;
F_14 (KERN_WARNING PFX
L_35 ,
curr) ;
goto V_34;
}
if ( V_176 == V_183 ) {
V_139 = F_110 () ;
if ( ! V_139 ) {
V_17 = - V_180 ;
goto V_34;
}
V_139 -> V_137 = V_184 ;
V_139 -> V_132 = V_132 ;
V_139 -> V_122 . V_147 = V_146 ;
V_139 -> V_122 . V_185 = V_177 ;
if ( V_177 == V_186 )
V_139 -> V_187 = F_104 ;
else
V_139 -> V_187 = F_84 ;
V_139 -> V_122 . V_146 = NULL ;
V_139 -> V_122 . V_148 = V_148 ;
if ( ! V_139 -> V_122 . V_148 )
V_139 -> V_122 . V_148 = V_188 ;
V_139 -> V_122 . V_153 = V_153 ;
if ( ! V_139 -> V_122 . V_153 )
V_139 -> V_122 . V_153 = V_188 ;
V_139 -> V_122 . V_150 = V_150 ;
V_139 -> V_47 = V_47 ;
if ( V_139 -> V_47 )
V_139 -> V_129 = F_67 ;
V_139 -> V_189 = V_178 ;
if ( ! F_115 ( V_139 ) ) {
if ( F_116 ( V_139 ) )
F_117 ( V_139 ) ;
} else {
F_118 ( V_139 ) ;
}
} else {
struct V_4 * V_190 , * V_191 ;
F_119 ( & V_192 ) ;
F_120 (e, tmp_e, &smi_infos, link) {
if ( V_190 -> V_122 . V_185 != V_177 )
continue;
if ( V_190 -> V_132 != V_132 )
continue;
if ( V_190 -> V_122 . V_147 == V_146 )
F_117 ( V_190 ) ;
}
F_121 ( & V_192 ) ;
}
}
V_17 = V_68 ;
V_34:
F_118 ( V_173 ) ;
return V_17 ;
}
static int T_3 F_122 ( void )
{
int V_193 = - V_154 ;
int V_166 ;
struct V_4 * V_139 ;
for ( V_166 = 0 ; V_166 < V_194 ; V_166 ++ ) {
if ( ! V_195 [ V_166 ] && ! V_196 [ V_166 ] )
continue;
V_139 = F_110 () ;
if ( ! V_139 )
return - V_180 ;
V_139 -> V_137 = V_197 ;
F_14 (KERN_INFO PFX L_36 ) ;
if ( ! V_132 [ V_166 ] || strcmp ( V_132 [ V_166 ] , L_37 ) == 0 ) {
V_139 -> V_132 = V_198 ;
} else if ( strcmp ( V_132 [ V_166 ] , L_38 ) == 0 ) {
V_139 -> V_132 = V_199 ;
} else if ( strcmp ( V_132 [ V_166 ] , L_39 ) == 0 ) {
V_139 -> V_132 = V_133 ;
} else {
F_14 (KERN_WARNING PFX L_40
L_41 ,
i, si_type[i]) ;
F_118 ( V_139 ) ;
continue;
}
if ( V_195 [ V_166 ] ) {
V_139 -> V_187 = F_84 ;
V_139 -> V_122 . V_147 = V_195 [ V_166 ] ;
V_139 -> V_122 . V_185 = V_200 ;
} else if ( V_196 [ V_166 ] ) {
V_139 -> V_187 = F_104 ;
V_139 -> V_122 . V_147 = V_196 [ V_166 ] ;
V_139 -> V_122 . V_185 = V_186 ;
} else {
F_14 (KERN_WARNING PFX L_40
L_42
L_43 , i) ;
F_118 ( V_139 ) ;
continue;
}
V_139 -> V_122 . V_146 = NULL ;
V_139 -> V_122 . V_148 = V_201 [ V_166 ] ;
if ( ! V_139 -> V_122 . V_148 )
V_139 -> V_122 . V_148 = V_188 ;
V_139 -> V_122 . V_153 = V_202 [ V_166 ] ;
if ( ! V_139 -> V_122 . V_153 )
V_139 -> V_122 . V_153 = V_188 ;
V_139 -> V_122 . V_150 = V_203 [ V_166 ] ;
V_139 -> V_47 = V_204 [ V_166 ] ;
if ( V_139 -> V_47 )
V_139 -> V_129 = F_67 ;
V_139 -> V_189 = V_205 [ V_166 ] ;
if ( ! F_115 ( V_139 ) ) {
if ( F_116 ( V_139 ) )
F_117 ( V_139 ) ;
V_193 = 0 ;
} else {
F_118 ( V_139 ) ;
}
}
return V_193 ;
}
static T_4 F_123 ( T_5 V_206 ,
T_4 V_207 , void * V_208 )
{
struct V_4 * V_4 = V_208 ;
unsigned long V_93 ;
#ifdef F_9
struct V_20 V_21 ;
#endif
F_36 ( & ( V_4 -> V_9 ) , V_93 ) ;
F_24 ( V_4 , V_120 ) ;
#ifdef F_9
F_13 ( & V_21 ) ;
F_14 ( L_44 , V_21 . V_30 , V_21 . V_31 ) ;
#endif
F_29 ( V_4 , 0 ) ;
F_37 ( & ( V_4 -> V_9 ) , V_93 ) ;
return V_209 ;
}
static void F_124 ( struct V_4 * V_139 )
{
if ( ! V_139 -> V_47 )
return;
F_125 ( NULL , V_139 -> V_47 , & F_123 ) ;
}
static int F_126 ( struct V_4 * V_139 )
{
T_6 V_210 ;
if ( ! V_139 -> V_47 )
return 0 ;
V_210 = F_127 ( NULL ,
V_139 -> V_47 ,
V_211 ,
& F_123 ,
V_139 ) ;
if ( V_210 != V_212 ) {
F_28 ( V_139 -> V_70 , L_45
L_18 , V_142 , V_139 -> V_47 ) ;
V_139 -> V_47 = 0 ;
return - V_157 ;
} else {
V_139 -> V_143 = F_124 ;
F_69 ( V_139 -> V_70 , L_46 , V_139 -> V_47 ) ;
return 0 ;
}
}
static int T_3 F_128 ( struct V_213 * V_214 )
{
struct V_4 * V_139 ;
if ( V_214 -> V_215 != 1 ) {
F_14 (KERN_INFO PFX L_47 , spmi->IPMIlegacy) ;
return - V_154 ;
}
V_139 = F_110 () ;
if ( ! V_139 ) {
F_14 (KERN_ERR PFX L_48 ) ;
return - V_180 ;
}
V_139 -> V_137 = V_216 ;
F_14 (KERN_INFO PFX L_49 ) ;
switch ( V_214 -> V_217 ) {
case 1 :
V_139 -> V_132 = V_198 ;
break;
case 2 :
V_139 -> V_132 = V_199 ;
break;
case 3 :
V_139 -> V_132 = V_133 ;
break;
default:
F_14 (KERN_INFO PFX L_50 ,
spmi->InterfaceType) ;
F_118 ( V_139 ) ;
return - V_158 ;
}
if ( V_214 -> V_218 & 1 ) {
V_139 -> V_47 = V_214 -> V_219 ;
V_139 -> V_129 = F_126 ;
} else if ( V_214 -> V_218 & 2 ) {
V_139 -> V_47 = V_214 -> V_220 ;
V_139 -> V_129 = F_67 ;
} else {
V_139 -> V_47 = 0 ;
V_139 -> V_129 = NULL ;
}
if ( V_214 -> V_146 . V_221 ) {
V_139 -> V_122 . V_148 = V_214 -> V_146 . V_221 / 8 ;
} else {
V_139 -> V_122 . V_148 = V_188 ;
}
V_139 -> V_122 . V_153 = V_139 -> V_122 . V_148 ;
V_139 -> V_122 . V_150 = V_214 -> V_146 . V_222 ;
if ( V_214 -> V_146 . V_223 == V_224 ) {
V_139 -> V_187 = F_104 ;
V_139 -> V_122 . V_185 = V_186 ;
} else if ( V_214 -> V_146 . V_223 == V_225 ) {
V_139 -> V_187 = F_84 ;
V_139 -> V_122 . V_185 = V_200 ;
} else {
F_118 ( V_139 ) ;
F_14 (KERN_WARNING PFX L_51 ) ;
return - V_158 ;
}
V_139 -> V_122 . V_147 = V_214 -> V_146 . V_226 ;
F_129 ( L_52 ,
( V_139 -> V_122 . V_185 == V_200 ) ? L_53 : L_54 ,
V_139 -> V_122 . V_147 , V_139 -> V_122 . V_153 , V_139 -> V_122 . V_148 ,
V_139 -> V_47 ) ;
if ( F_115 ( V_139 ) )
F_118 ( V_139 ) ;
return 0 ;
}
static void T_3 F_130 ( void )
{
T_6 V_210 ;
struct V_213 * V_214 ;
int V_166 ;
if ( V_227 )
return;
if ( V_228 )
return;
for ( V_166 = 0 ; ; V_166 ++ ) {
V_210 = F_131 ( V_229 , V_166 + 1 ,
(struct V_230 * * ) & V_214 ) ;
if ( V_210 != V_212 )
return;
F_128 ( V_214 ) ;
}
}
static int T_3 F_132 ( struct V_231 * V_70 ,
const struct V_232 * V_233 )
{
struct V_234 * V_235 ;
struct V_4 * V_139 ;
struct V_236 * V_237 , * V_238 ;
T_5 V_239 ;
T_6 V_210 ;
unsigned long long V_240 ;
V_235 = F_133 ( V_70 ) ;
if ( ! V_235 )
return - V_154 ;
V_139 = F_110 () ;
if ( ! V_139 )
return - V_180 ;
V_139 -> V_137 = V_241 ;
F_14 (KERN_INFO PFX L_55 ) ;
V_239 = V_235 -> V_239 ;
V_139 -> V_138 . V_242 . T_5 = V_239 ;
V_210 = F_134 ( V_239 , L_56 , NULL , & V_240 ) ;
if ( F_135 ( V_210 ) )
goto V_243;
switch ( V_240 ) {
case 1 :
V_139 -> V_132 = V_198 ;
break;
case 2 :
V_139 -> V_132 = V_199 ;
break;
case 3 :
V_139 -> V_132 = V_133 ;
break;
default:
F_69 ( & V_70 -> V_70 , L_57 , V_240 ) ;
goto V_243;
}
V_237 = F_136 ( V_70 , V_244 , 0 ) ;
if ( V_237 ) {
V_139 -> V_187 = F_84 ;
V_139 -> V_122 . V_185 = V_200 ;
} else {
V_237 = F_136 ( V_70 , V_245 , 0 ) ;
if ( V_237 ) {
V_139 -> V_187 = F_104 ;
V_139 -> V_122 . V_185 = V_186 ;
}
}
if ( ! V_237 ) {
F_137 ( & V_70 -> V_70 , L_58 ) ;
goto V_243;
}
V_139 -> V_122 . V_147 = V_237 -> V_246 ;
V_139 -> V_122 . V_148 = V_188 ;
V_238 = F_136 ( V_70 ,
( V_139 -> V_122 . V_185 == V_200 ) ?
V_244 : V_245 ,
1 ) ;
if ( V_238 ) {
if ( V_238 -> V_246 > V_139 -> V_122 . V_147 )
V_139 -> V_122 . V_148 = V_238 -> V_246 - V_139 -> V_122 . V_147 ;
}
V_139 -> V_122 . V_153 = V_188 ;
V_139 -> V_122 . V_150 = 0 ;
V_210 = F_134 ( V_239 , L_59 , NULL , & V_240 ) ;
if ( F_138 ( V_210 ) ) {
V_139 -> V_47 = V_240 ;
V_139 -> V_129 = F_126 ;
} else if ( F_139 ( V_70 , 0 ) ) {
V_139 -> V_47 = F_140 ( V_70 , 0 ) ;
V_139 -> V_129 = F_67 ;
}
V_139 -> V_70 = & V_70 -> V_70 ;
F_141 ( V_70 , V_139 ) ;
F_69 ( V_139 -> V_70 , L_60 ,
V_237 , V_139 -> V_122 . V_153 , V_139 -> V_122 . V_148 ,
V_139 -> V_47 ) ;
if ( F_115 ( V_139 ) )
goto V_243;
return 0 ;
V_243:
F_118 ( V_139 ) ;
return - V_157 ;
}
static void T_7 F_142 ( struct V_231 * V_70 )
{
struct V_4 * V_139 = F_143 ( V_70 ) ;
F_117 ( V_139 ) ;
}
static int T_3 F_144 ( const struct V_247 * V_248 ,
struct V_249 * V_250 )
{
const T_8 * V_14 = ( const T_8 * ) V_248 ;
unsigned long V_251 ;
T_8 V_252 ;
T_8 V_68 = V_248 -> V_253 ;
V_250 -> type = V_14 [ 4 ] ;
memcpy ( & V_251 , V_14 + 8 , sizeof( unsigned long ) ) ;
if ( V_68 >= 0x11 ) {
if ( V_251 & 1 ) {
V_251 &= 0xFFFE ;
V_250 -> V_177 = V_200 ;
} else
V_250 -> V_177 = V_186 ;
V_250 -> V_251 = V_251 | ( ( V_14 [ 0x10 ] & 0x10 ) >> 4 ) ;
V_250 -> V_47 = V_14 [ 0x11 ] ;
V_252 = ( V_14 [ 0x10 ] & 0xC0 ) >> 6 ;
switch ( V_252 ) {
case 0x00 :
V_250 -> V_145 = 1 ;
break;
case 0x01 :
V_250 -> V_145 = 4 ;
break;
case 0x02 :
V_250 -> V_145 = 16 ;
break;
default:
return - V_158 ;
}
} else {
V_250 -> V_251 = V_251 & 0xfffe ;
V_250 -> V_177 = V_200 ;
V_250 -> V_145 = 1 ;
}
V_250 -> V_189 = V_14 [ 6 ] ;
return 0 ;
}
static void T_3 F_145 ( struct V_249 * V_254 )
{
struct V_4 * V_139 ;
V_139 = F_110 () ;
if ( ! V_139 ) {
F_14 (KERN_ERR PFX L_61 ) ;
return;
}
V_139 -> V_137 = V_255 ;
F_14 (KERN_INFO PFX L_62 ) ;
switch ( V_254 -> type ) {
case 0x01 :
V_139 -> V_132 = V_198 ;
break;
case 0x02 :
V_139 -> V_132 = V_199 ;
break;
case 0x03 :
V_139 -> V_132 = V_133 ;
break;
default:
F_118 ( V_139 ) ;
return;
}
switch ( V_254 -> V_177 ) {
case V_186 :
V_139 -> V_187 = F_104 ;
V_139 -> V_122 . V_185 = V_186 ;
break;
case V_200 :
V_139 -> V_187 = F_84 ;
V_139 -> V_122 . V_185 = V_200 ;
break;
default:
F_118 ( V_139 ) ;
F_14 (KERN_WARNING PFX L_63 ,
ipmi_data->addr_space) ;
return;
}
V_139 -> V_122 . V_147 = V_254 -> V_251 ;
V_139 -> V_122 . V_148 = V_254 -> V_145 ;
if ( ! V_139 -> V_122 . V_148 )
V_139 -> V_122 . V_148 = V_188 ;
V_139 -> V_122 . V_153 = V_188 ;
V_139 -> V_122 . V_150 = 0 ;
V_139 -> V_189 = V_254 -> V_189 ;
V_139 -> V_47 = V_254 -> V_47 ;
if ( V_139 -> V_47 )
V_139 -> V_129 = F_67 ;
F_129 ( L_64 ,
( V_139 -> V_122 . V_185 == V_200 ) ? L_53 : L_54 ,
V_139 -> V_122 . V_147 , V_139 -> V_122 . V_153 , V_139 -> V_122 . V_148 ,
V_139 -> V_47 ) ;
if ( F_115 ( V_139 ) )
F_118 ( V_139 ) ;
}
static void T_3 F_146 ( void )
{
const struct V_256 * V_70 = NULL ;
struct V_249 V_14 ;
int V_17 ;
while ( ( V_70 = F_147 ( V_257 , NULL , V_70 ) ) ) {
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_17 = F_144 ( ( const struct V_247 * ) V_70 -> V_258 ,
& V_14 ) ;
if ( ! V_17 )
F_145 ( & V_14 ) ;
}
}
static void F_148 ( struct V_4 * V_139 )
{
struct V_259 * V_260 = V_139 -> V_261 ;
F_149 ( V_260 ) ;
}
static int T_3 F_150 ( struct V_259 * V_260 ,
const struct V_262 * V_263 )
{
int V_17 ;
int V_264 = V_260 -> V_265 & V_266 ;
struct V_4 * V_139 ;
V_139 = F_110 () ;
if ( ! V_139 )
return - V_180 ;
V_139 -> V_137 = V_267 ;
F_69 ( & V_260 -> V_70 , L_65 ) ;
switch ( V_264 ) {
case V_268 :
V_139 -> V_132 = V_199 ;
break;
case V_269 :
V_139 -> V_132 = V_198 ;
break;
case V_270 :
V_139 -> V_132 = V_133 ;
break;
default:
F_118 ( V_139 ) ;
F_69 ( & V_260 -> V_70 , L_66 , V_264 ) ;
return - V_180 ;
}
V_17 = F_151 ( V_260 ) ;
if ( V_17 ) {
F_137 ( & V_260 -> V_70 , L_67 ) ;
F_118 ( V_139 ) ;
return V_17 ;
}
V_139 -> V_271 = F_148 ;
V_139 -> V_261 = V_260 ;
if ( F_152 ( V_260 , 0 ) & V_244 ) {
V_139 -> V_187 = F_84 ;
V_139 -> V_122 . V_185 = V_200 ;
} else {
V_139 -> V_187 = F_104 ;
V_139 -> V_122 . V_185 = V_186 ;
}
V_139 -> V_122 . V_147 = F_153 ( V_260 , 0 ) ;
V_139 -> V_122 . V_148 = V_188 ;
V_139 -> V_122 . V_153 = V_188 ;
V_139 -> V_122 . V_150 = 0 ;
V_139 -> V_47 = V_260 -> V_47 ;
if ( V_139 -> V_47 )
V_139 -> V_129 = F_67 ;
V_139 -> V_70 = & V_260 -> V_70 ;
F_154 ( V_260 , V_139 ) ;
F_69 ( & V_260 -> V_70 , L_60 ,
& V_260 -> V_236 [ 0 ] , V_139 -> V_122 . V_153 , V_139 -> V_122 . V_148 ,
V_139 -> V_47 ) ;
if ( F_115 ( V_139 ) )
F_118 ( V_139 ) ;
return 0 ;
}
static void T_7 F_155 ( struct V_259 * V_260 )
{
struct V_4 * V_139 = F_156 ( V_260 ) ;
F_117 ( V_139 ) ;
}
static int F_157 ( struct V_259 * V_260 , T_9 V_272 )
{
return 0 ;
}
static int F_158 ( struct V_259 * V_260 )
{
return 0 ;
}
static int T_3 F_159 ( struct V_273 * V_70 )
{
#ifdef F_160
const struct V_274 * V_275 ;
struct V_4 * V_139 ;
struct V_236 V_236 ;
const T_10 * V_153 , * V_148 , * V_150 ;
struct V_276 * V_277 = V_70 -> V_70 . V_278 ;
int V_193 ;
int V_279 ;
F_69 ( & V_70 -> V_70 , L_68 ) ;
V_275 = F_161 ( V_280 , & V_70 -> V_70 ) ;
if ( ! V_275 )
return - V_157 ;
V_193 = F_162 ( V_277 , 0 , & V_236 ) ;
if ( V_193 ) {
F_28 ( & V_70 -> V_70 , V_281 L_69 ) ;
return V_193 ;
}
V_153 = F_163 ( V_277 , L_70 , & V_279 ) ;
if ( V_153 && V_279 != 4 ) {
F_28 ( & V_70 -> V_70 , V_281 L_71 ) ;
return - V_157 ;
}
V_148 = F_163 ( V_277 , L_72 , & V_279 ) ;
if ( V_148 && V_279 != 4 ) {
F_28 ( & V_70 -> V_70 , V_281 L_73 ) ;
return - V_157 ;
}
V_150 = F_163 ( V_277 , L_74 , & V_279 ) ;
if ( V_150 && V_279 != 4 ) {
F_28 ( & V_70 -> V_70 , V_281 L_75 ) ;
return - V_157 ;
}
V_139 = F_110 () ;
if ( ! V_139 ) {
F_137 ( & V_70 -> V_70 ,
L_76 ) ;
return - V_180 ;
}
V_139 -> V_132 = (enum V_132 ) V_275 -> V_14 ;
V_139 -> V_137 = V_282 ;
V_139 -> V_129 = F_67 ;
if ( V_236 . V_93 & V_244 ) {
V_139 -> V_187 = F_84 ;
V_139 -> V_122 . V_185 = V_200 ;
} else {
V_139 -> V_187 = F_104 ;
V_139 -> V_122 . V_185 = V_186 ;
}
V_139 -> V_122 . V_147 = V_236 . V_246 ;
V_139 -> V_122 . V_153 = V_153 ? F_164 ( V_153 ) : V_283 ;
V_139 -> V_122 . V_148 = V_148 ? F_164 ( V_148 ) : V_188 ;
V_139 -> V_122 . V_150 = V_150 ? F_164 ( V_150 ) : 0 ;
V_139 -> V_47 = F_165 ( V_70 -> V_70 . V_278 , 0 ) ;
V_139 -> V_70 = & V_70 -> V_70 ;
F_166 ( & V_70 -> V_70 , L_77 ,
V_139 -> V_122 . V_147 , V_139 -> V_122 . V_153 , V_139 -> V_122 . V_148 ,
V_139 -> V_47 ) ;
F_167 ( & V_70 -> V_70 , V_139 ) ;
if ( F_115 ( V_139 ) ) {
F_118 ( V_139 ) ;
return - V_284 ;
}
#endif
return 0 ;
}
static int T_7 F_168 ( struct V_273 * V_70 )
{
#ifdef F_160
F_117 ( F_169 ( & V_70 -> V_70 ) ) ;
#endif
return 0 ;
}
static int F_170 ( struct V_4 * V_4 )
{
enum V_16 V_101 ;
V_101 = V_4 -> V_35 -> V_80 ( V_4 -> V_37 , 0 ) ;
for (; ; ) {
if ( V_101 == V_107 ||
V_101 == V_285 ) {
F_171 ( 1 ) ;
V_101 = V_4 -> V_35 -> V_80 (
V_4 -> V_37 , 100 ) ;
} else if ( V_101 == V_33 ) {
V_101 = V_4 -> V_35 -> V_80 (
V_4 -> V_37 , 0 ) ;
} else
break;
}
if ( V_101 == V_83 )
return - V_154 ;
return 0 ;
}
static int F_172 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 2 ] ;
unsigned char * V_286 ;
unsigned long V_287 ;
int V_17 = 0 ;
V_286 = F_173 ( V_66 , V_170 ) ;
if ( ! V_286 )
return - V_180 ;
V_6 [ 0 ] = V_39 << 2 ;
V_6 [ 1 ] = V_288 ;
V_4 -> V_35 -> V_36 ( V_4 -> V_37 , V_6 , 2 ) ;
V_17 = F_170 ( V_4 ) ;
if ( V_17 )
goto V_34;
V_287 = V_4 -> V_35 -> V_65 ( V_4 -> V_37 ,
V_286 , V_66 ) ;
V_17 = F_174 ( V_286 , V_287 , & V_4 -> V_289 ) ;
V_34:
F_118 ( V_286 ) ;
return V_17 ;
}
static int F_175 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 3 ] ;
unsigned char * V_286 ;
unsigned long V_287 ;
int V_17 = 0 ;
V_286 = F_173 ( V_66 , V_170 ) ;
if ( ! V_286 )
return - V_180 ;
V_6 [ 0 ] = V_39 << 2 ;
V_6 [ 1 ] = V_40 ;
V_4 -> V_35 -> V_36 ( V_4 -> V_37 , V_6 , 2 ) ;
V_17 = F_170 ( V_4 ) ;
if ( V_17 ) {
F_14 (KERN_WARNING PFX L_78
L_79
L_80 ) ;
goto V_34;
}
V_287 = V_4 -> V_35 -> V_65 ( V_4 -> V_37 ,
V_286 , V_66 ) ;
if ( V_287 < 4 ||
V_286 [ 0 ] != ( V_39 | 1 ) << 2 ||
V_286 [ 1 ] != V_40 ||
V_286 [ 2 ] != 0 ) {
F_14 (KERN_WARNING PFX L_81
L_82 ) ;
V_17 = - V_157 ;
goto V_34;
}
if ( V_286 [ 3 ] & V_290 )
goto V_34;
V_6 [ 0 ] = V_39 << 2 ;
V_6 [ 1 ] = V_74 ;
V_6 [ 2 ] = V_286 [ 3 ] | V_290 ;
V_4 -> V_35 -> V_36 ( V_4 -> V_37 , V_6 , 3 ) ;
V_17 = F_170 ( V_4 ) ;
if ( V_17 ) {
F_14 (KERN_WARNING PFX L_83
L_84
L_80 ) ;
goto V_34;
}
V_287 = V_4 -> V_35 -> V_65 ( V_4 -> V_37 ,
V_286 , V_66 ) ;
if ( V_287 < 3 ||
V_286 [ 0 ] != ( V_39 | 1 ) << 2 ||
V_286 [ 1 ] != V_74 ) {
F_14 (KERN_WARNING PFX L_85
L_86 ) ;
V_17 = - V_157 ;
goto V_34;
}
if ( V_286 [ 2 ] != 0 )
V_17 = - V_291 ;
V_34:
F_118 ( V_286 ) ;
return V_17 ;
}
static int F_176 ( struct V_292 * V_293 , void * V_161 )
{
struct V_4 * V_135 = V_293 -> V_294 ;
return F_177 ( V_293 , L_87 , V_295 [ V_135 -> V_132 ] ) ;
}
static int F_178 ( struct V_296 * V_296 , struct V_297 * V_297 )
{
return F_179 ( V_297 , F_176 , F_180 ( V_296 ) -> V_14 ) ;
}
static int F_181 ( struct V_292 * V_293 , void * V_161 )
{
struct V_4 * V_135 = V_293 -> V_294 ;
F_177 ( V_293 , L_88 ,
V_135 -> V_47 && ! V_135 -> V_48 ) ;
F_177 ( V_293 , L_89 ,
F_182 ( V_135 , V_119 ) ) ;
F_177 ( V_293 , L_90 ,
F_182 ( V_135 , V_117 ) ) ;
F_177 ( V_293 , L_91 ,
F_182 ( V_135 , V_88 ) ) ;
F_177 ( V_293 , L_92 ,
F_182 ( V_135 , V_120 ) ) ;
F_177 ( V_293 , L_93 ,
F_182 ( V_135 , V_86 ) ) ;
F_177 ( V_293 , L_94 ,
F_182 ( V_135 , V_298 ) ) ;
F_177 ( V_293 , L_95 ,
F_182 ( V_135 , V_84 ) ) ;
F_177 ( V_293 , L_96 ,
F_182 ( V_135 , V_82 ) ) ;
F_177 ( V_293 , L_97 ,
F_182 ( V_135 , V_72 ) ) ;
F_177 ( V_293 , L_98 ,
F_182 ( V_135 , V_55 ) ) ;
F_177 ( V_293 , L_99 ,
F_182 ( V_135 , V_73 ) ) ;
return 0 ;
}
static int F_183 ( struct V_296 * V_296 , struct V_297 * V_297 )
{
return F_179 ( V_297 , F_181 , F_180 ( V_296 ) -> V_14 ) ;
}
static int F_184 ( struct V_292 * V_293 , void * V_161 )
{
struct V_4 * V_135 = V_293 -> V_294 ;
return F_177 ( V_293 ,
L_100 ,
V_295 [ V_135 -> V_132 ] ,
V_299 [ V_135 -> V_122 . V_185 ] ,
V_135 -> V_122 . V_147 ,
V_135 -> V_122 . V_148 ,
V_135 -> V_122 . V_153 ,
V_135 -> V_122 . V_150 ,
V_135 -> V_47 ,
V_135 -> V_189 ) ;
}
static int F_185 ( struct V_296 * V_296 , struct V_297 * V_297 )
{
return F_179 ( V_297 , F_184 , F_180 ( V_296 ) -> V_14 ) ;
}
static int F_186 ( struct V_4 * V_4 )
{
V_4 -> V_54 = ( ( V_4 -> V_54 & ~ V_63 ) |
V_56 ) ;
return 1 ;
}
static void F_187 ( struct V_4 * V_4 )
{
struct V_300 * V_301 = & V_4 -> V_289 ;
if ( V_301 -> V_302 == V_303 ) {
if ( V_301 -> V_289 == V_304 &&
V_301 -> V_305 == V_306 &&
V_301 -> V_307 == V_308 ) {
V_4 -> V_64 =
F_186 ;
} else if ( F_188 ( V_301 ) < 1 ||
( F_188 ( V_301 ) == 1 &&
F_189 ( V_301 ) < 5 ) ) {
V_4 -> V_64 =
F_186 ;
}
}
}
static void F_190 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_11 ;
V_6 -> V_13 [ 0 ] = V_6 -> V_14 [ 0 ] | 4 ;
V_6 -> V_13 [ 1 ] = V_6 -> V_14 [ 1 ] ;
V_6 -> V_13 [ 2 ] = V_309 ;
V_6 -> V_15 = 3 ;
V_4 -> V_11 = NULL ;
F_3 ( V_4 , V_6 ) ;
}
static int F_191 ( struct V_1 * V_310 ,
unsigned long V_311 ,
void * V_312 )
{
struct V_4 * V_4 = V_312 ;
unsigned char * V_14 = V_4 -> V_11 -> V_14 ;
unsigned int V_313 = V_4 -> V_11 -> V_38 ;
if ( V_313 >= 8 &&
( V_14 [ 0 ] >> 2 ) == V_314 &&
V_14 [ 1 ] == V_315 &&
V_14 [ 7 ] == 0x3A ) {
F_190 ( V_4 ) ;
return V_316 ;
}
return V_317 ;
}
static void
F_192 ( struct V_4 * V_4 )
{
struct V_300 * V_301 = & V_4 -> V_289 ;
if ( V_301 -> V_302 == V_303 &&
V_4 -> V_132 == V_133 )
F_1 ( & V_318 ) ;
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
if ( V_4 -> V_8 ) {
if ( V_4 -> V_95 != NULL )
F_196 ( V_4 -> V_95 ) ;
F_197 ( & V_4 -> V_50 ) ;
}
}
static void T_3 F_198 ( void )
{
struct V_4 * V_139 ;
int V_166 ;
for ( V_166 = 0 ; ; V_166 ++ ) {
if ( ! V_319 [ V_166 ] . V_320 )
break;
#ifdef F_199
if ( F_200 ( V_319 [ V_166 ] . V_320 ) )
continue;
#endif
V_139 = F_110 () ;
if ( ! V_139 )
return;
V_139 -> V_137 = V_321 ;
V_139 -> V_132 = V_319 [ V_166 ] . type ;
V_139 -> V_187 = F_84 ;
V_139 -> V_122 . V_147 = V_319 [ V_166 ] . V_320 ;
V_139 -> V_122 . V_185 = V_200 ;
V_139 -> V_122 . V_146 = NULL ;
V_139 -> V_122 . V_148 = V_188 ;
V_139 -> V_122 . V_153 = V_188 ;
V_139 -> V_122 . V_150 = 0 ;
if ( F_115 ( V_139 ) == 0 ) {
if ( ( F_116 ( V_139 ) ) == 0 ) {
F_14 (KERN_INFO PFX L_101
L_102 ,
si_to_str[info->si_type],
addr_space_to_str[info->io.addr_type],
info->io.addr_data) ;
} else
F_117 ( V_139 ) ;
} else {
F_118 ( V_139 ) ;
}
}
}
static int F_201 ( struct V_4 * V_139 )
{
struct V_4 * V_190 ;
F_202 (e, &smi_infos, link) {
if ( V_190 -> V_122 . V_185 != V_139 -> V_122 . V_185 )
continue;
if ( V_190 -> V_122 . V_147 == V_139 -> V_122 . V_147 )
return 0 ;
}
return 1 ;
}
static int F_115 ( struct V_4 * V_127 )
{
int V_17 = 0 ;
F_14 (KERN_INFO PFX L_103 ,
ipmi_addr_src_to_str[new_smi->addr_source],
si_to_str[new_smi->si_type]) ;
F_119 ( & V_192 ) ;
if ( ! F_201 ( V_127 ) ) {
F_14 ( V_322 L_104 ) ;
V_17 = - V_284 ;
goto V_323;
}
F_14 ( V_322 L_105 ) ;
V_127 -> V_8 = NULL ;
V_127 -> V_37 = NULL ;
V_127 -> V_35 = NULL ;
F_34 ( & V_127 -> V_28 , & V_324 ) ;
V_323:
F_121 ( & V_192 ) ;
return V_17 ;
}
static int F_116 ( struct V_4 * V_127 )
{
int V_17 = 0 ;
int V_166 ;
F_14 (KERN_INFO PFX L_106
L_107
L_108 ,
ipmi_addr_src_to_str[new_smi->addr_source],
si_to_str[new_smi->si_type],
addr_space_to_str[new_smi->io.addr_type],
new_smi->io.addr_data,
new_smi->slave_addr, new_smi->irq) ;
switch ( V_127 -> V_132 ) {
case V_198 :
V_127 -> V_35 = & V_325 ;
break;
case V_199 :
V_127 -> V_35 = & V_326 ;
break;
case V_133 :
V_127 -> V_35 = & V_327 ;
break;
default:
V_17 = - V_158 ;
goto V_323;
}
V_127 -> V_37 = F_173 ( V_127 -> V_35 -> V_313 () , V_170 ) ;
if ( ! V_127 -> V_37 ) {
F_14 (KERN_ERR PFX
L_109 ) ;
V_17 = - V_180 ;
goto V_323;
}
V_127 -> V_152 = V_127 -> V_35 -> V_328 ( V_127 -> V_37 ,
& V_127 -> V_122 ) ;
V_17 = V_127 -> V_187 ( V_127 ) ;
if ( V_17 ) {
F_14 (KERN_ERR PFX L_110 ) ;
goto V_323;
}
if ( V_127 -> V_35 -> V_329 ( V_127 -> V_37 ) ) {
if ( V_127 -> V_137 )
F_14 (KERN_INFO PFX L_111 ) ;
V_17 = - V_154 ;
goto V_323;
}
V_17 = F_172 ( V_127 ) ;
if ( V_17 ) {
if ( V_127 -> V_137 )
F_14 (KERN_INFO PFX L_112
L_113 ) ;
goto V_323;
}
F_193 ( V_127 ) ;
F_194 ( V_127 ) ;
F_203 ( & ( V_127 -> V_25 ) ) ;
F_203 ( & ( V_127 -> V_23 ) ) ;
V_127 -> V_11 = NULL ;
F_31 ( & V_127 -> V_89 , 0 ) ;
V_127 -> V_7 = 0 ;
for ( V_166 = 0 ; V_166 < V_330 ; V_166 ++ )
F_31 ( & V_127 -> V_331 [ V_166 ] , 0 ) ;
V_127 -> V_48 = 1 ;
F_31 ( & V_127 -> V_49 , 0 ) ;
V_127 -> V_104 = V_332 ;
V_332 ++ ;
V_17 = F_175 ( V_127 ) ;
if ( V_17 == 0 )
V_127 -> V_112 = 1 ;
F_18 ( V_127 ) ;
if ( V_127 -> V_47 )
V_127 -> V_41 = V_69 ;
if ( ! V_127 -> V_70 ) {
V_127 -> V_260 = F_204 ( L_114 ,
V_127 -> V_104 ) ;
if ( ! V_127 -> V_260 ) {
F_14 (KERN_ERR PFX
L_115 ) ;
goto V_323;
}
V_127 -> V_70 = & V_127 -> V_260 -> V_70 ;
V_127 -> V_70 -> V_333 = & V_334 . V_333 ;
V_17 = F_205 ( V_127 -> V_260 ) ;
if ( V_17 ) {
F_14 (KERN_ERR PFX
L_116
L_117 ,
rv) ;
goto V_323;
}
V_127 -> V_335 = 1 ;
}
V_17 = F_206 ( & V_35 ,
V_127 ,
& V_127 -> V_289 ,
V_127 -> V_70 ,
L_118 ,
V_127 -> V_189 ) ;
if ( V_17 ) {
F_137 ( V_127 -> V_70 , L_119 ,
V_17 ) ;
goto V_336;
}
V_17 = F_207 ( V_127 -> V_8 , L_120 ,
& V_337 ,
V_127 ) ;
if ( V_17 ) {
F_137 ( V_127 -> V_70 , L_121 , V_17 ) ;
goto V_336;
}
V_17 = F_207 ( V_127 -> V_8 , L_122 ,
& V_338 ,
V_127 ) ;
if ( V_17 ) {
F_137 ( V_127 -> V_70 , L_121 , V_17 ) ;
goto V_336;
}
V_17 = F_207 ( V_127 -> V_8 , L_123 ,
& V_339 ,
V_127 ) ;
if ( V_17 ) {
F_137 ( V_127 -> V_70 , L_121 , V_17 ) ;
goto V_336;
}
F_69 ( V_127 -> V_70 , L_124 ,
V_295 [ V_127 -> V_132 ] ) ;
return 0 ;
V_336:
F_208 ( & V_127 -> V_49 ) ;
F_195 ( V_127 ) ;
V_323:
V_127 -> V_48 = 1 ;
if ( V_127 -> V_8 ) {
F_209 ( V_127 -> V_8 ) ;
V_127 -> V_8 = NULL ;
}
if ( V_127 -> V_143 ) {
V_127 -> V_143 ( V_127 ) ;
V_127 -> V_143 = NULL ;
}
F_210 () ;
if ( V_127 -> V_37 ) {
if ( V_127 -> V_35 )
V_127 -> V_35 -> V_340 ( V_127 -> V_37 ) ;
F_118 ( V_127 -> V_37 ) ;
V_127 -> V_37 = NULL ;
}
if ( V_127 -> V_271 ) {
V_127 -> V_271 ( V_127 ) ;
V_127 -> V_271 = NULL ;
}
if ( V_127 -> V_155 ) {
V_127 -> V_155 ( V_127 ) ;
V_127 -> V_155 = NULL ;
}
if ( V_127 -> V_335 ) {
F_211 ( V_127 -> V_260 ) ;
V_127 -> V_335 = 0 ;
}
return V_17 ;
}
static int T_3 F_212 ( void )
{
int V_166 ;
char * V_173 ;
int V_17 ;
struct V_4 * V_190 ;
enum V_341 type = V_342 ;
if ( V_343 )
return 0 ;
V_343 = 1 ;
V_17 = F_213 ( & V_334 ) ;
if ( V_17 ) {
F_14 (KERN_ERR PFX L_125 , rv) ;
return V_17 ;
}
V_173 = V_344 ;
if ( * V_173 != '\0' ) {
for ( V_166 = 0 ; ( V_166 < V_194 ) && ( * V_173 != '\0' ) ; V_166 ++ ) {
V_132 [ V_166 ] = V_173 ;
V_173 = strchr ( V_173 , ',' ) ;
if ( V_173 ) {
* V_173 = '\0' ;
V_173 ++ ;
} else {
break;
}
}
}
F_14 ( V_345 L_126 ) ;
if ( ! F_122 () )
return 0 ;
#ifdef F_214
V_17 = F_215 ( & V_346 ) ;
if ( V_17 )
F_14 (KERN_ERR PFX L_127 , rv) ;
else
V_347 = 1 ;
#endif
#ifdef F_216
F_217 ( & V_348 ) ;
V_349 = 1 ;
#endif
#ifdef F_218
F_146 () ;
#endif
#ifdef F_216
F_130 () ;
#endif
F_119 ( & V_192 ) ;
F_202 (e, &smi_infos, link) {
if ( V_190 -> V_47 && ( ! type || V_190 -> V_137 == type ) ) {
if ( ! F_116 ( V_190 ) ) {
type = V_190 -> V_137 ;
}
}
}
if ( type ) {
F_121 ( & V_192 ) ;
return 0 ;
}
F_202 (e, &smi_infos, link) {
if ( ! V_190 -> V_47 && ( ! type || V_190 -> V_137 == type ) ) {
if ( ! F_116 ( V_190 ) ) {
type = V_190 -> V_137 ;
}
}
}
F_121 ( & V_192 ) ;
if ( type )
return 0 ;
if ( V_350 ) {
F_119 ( & V_192 ) ;
if ( F_10 ( & V_324 ) ) {
F_121 ( & V_192 ) ;
F_198 () ;
} else
F_121 ( & V_192 ) ;
}
F_119 ( & V_192 ) ;
if ( V_351 && F_10 ( & V_324 ) ) {
F_121 ( & V_192 ) ;
F_219 () ;
F_14 (KERN_WARNING PFX
L_128 ) ;
return - V_154 ;
} else {
F_121 ( & V_192 ) ;
return 0 ;
}
}
static void F_117 ( struct V_4 * V_352 )
{
int V_17 = 0 ;
unsigned long V_93 ;
if ( ! V_352 )
return;
F_11 ( & V_352 -> V_28 ) ;
F_208 ( & V_352 -> V_49 ) ;
F_195 ( V_352 ) ;
F_36 ( & V_352 -> V_9 , V_93 ) ;
while ( V_352 -> V_11 || ( V_352 -> V_41 != V_57 ) ) {
F_37 ( & V_352 -> V_9 , V_93 ) ;
F_51 ( V_352 ) ;
F_171 ( 1 ) ;
F_36 ( & V_352 -> V_9 , V_93 ) ;
}
F_19 ( V_352 ) ;
F_37 ( & V_352 -> V_9 , V_93 ) ;
while ( V_352 -> V_11 || ( V_352 -> V_41 != V_57 ) ) {
F_51 ( V_352 ) ;
F_171 ( 1 ) ;
}
if ( V_352 -> V_143 )
V_352 -> V_143 ( V_352 ) ;
while ( V_352 -> V_11 || ( V_352 -> V_41 != V_57 ) ) {
F_51 ( V_352 ) ;
F_171 ( 1 ) ;
}
if ( V_352 -> V_8 )
V_17 = F_209 ( V_352 -> V_8 ) ;
if ( V_17 ) {
F_14 (KERN_ERR PFX L_129 ,
rv) ;
}
if ( V_352 -> V_35 )
V_352 -> V_35 -> V_340 ( V_352 -> V_37 ) ;
F_118 ( V_352 -> V_37 ) ;
if ( V_352 -> V_271 )
V_352 -> V_271 ( V_352 ) ;
if ( V_352 -> V_155 )
V_352 -> V_155 ( V_352 ) ;
if ( V_352 -> V_335 )
F_211 ( V_352 -> V_260 ) ;
F_118 ( V_352 ) ;
}
static void F_219 ( void )
{
struct V_4 * V_190 , * V_191 ;
if ( ! V_343 )
return;
#ifdef F_214
if ( V_347 )
F_220 ( & V_346 ) ;
#endif
#ifdef F_216
if ( V_349 )
F_221 ( & V_348 ) ;
#endif
F_222 ( & V_334 ) ;
F_119 ( & V_192 ) ;
F_120 (e, tmp_e, &smi_infos, link)
F_117 ( V_190 ) ;
F_121 ( & V_192 ) ;
}
