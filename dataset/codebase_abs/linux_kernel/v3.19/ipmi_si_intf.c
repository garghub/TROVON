static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_3 , V_2 ) ;
}
static void F_3 ( struct V_4 * V_4 ,
struct V_5 * V_6 )
{
if ( V_4 -> V_7 )
F_4 ( V_4 -> V_7 , V_6 ) ;
else
F_5 ( V_6 ) ;
}
static void F_6 ( struct V_4 * V_4 , int V_8 )
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
static enum V_14 F_7 ( struct V_4 * V_4 )
{
int V_15 ;
#ifdef F_8
struct V_16 V_17 ;
#endif
if ( ! V_4 -> V_18 ) {
V_4 -> V_9 = NULL ;
V_15 = V_19 ;
} else {
int V_20 ;
V_4 -> V_9 = V_4 -> V_18 ;
V_4 -> V_18 = NULL ;
#ifdef F_8
F_9 ( & V_17 ) ;
F_10 ( V_21 L_1 , V_17 . V_22 , V_17 . V_23 ) ;
#endif
V_20 = F_11 ( & V_3 ,
0 , V_4 ) ;
if ( V_20 & V_24 ) {
V_15 = V_25 ;
goto V_26;
}
V_20 = V_4 -> V_27 -> V_28 (
V_4 -> V_29 ,
V_4 -> V_9 -> V_12 ,
V_4 -> V_9 -> V_30 ) ;
if ( V_20 )
F_6 ( V_4 , V_20 ) ;
V_15 = V_25 ;
}
V_26:
return V_15 ;
}
static void F_12 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 2 ] ;
V_6 [ 0 ] = ( V_31 << 2 ) ;
V_6 [ 1 ] = V_32 ;
V_4 -> V_27 -> V_28 ( V_4 -> V_29 , V_6 , 2 ) ;
V_4 -> V_33 = V_34 ;
}
static void F_13 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 3 ] ;
V_6 [ 0 ] = ( V_31 << 2 ) ;
V_6 [ 1 ] = V_35 ;
V_6 [ 2 ] = V_36 ;
V_4 -> V_27 -> V_28 ( V_4 -> V_29 , V_6 , 3 ) ;
V_4 -> V_33 = V_37 ;
}
static void F_14 ( struct V_4 * V_4 )
{
V_4 -> V_9 -> V_12 [ 0 ] = ( V_31 << 2 ) ;
V_4 -> V_9 -> V_12 [ 1 ] = V_38 ;
V_4 -> V_9 -> V_30 = 2 ;
V_4 -> V_27 -> V_28 (
V_4 -> V_29 ,
V_4 -> V_9 -> V_12 ,
V_4 -> V_9 -> V_30 ) ;
V_4 -> V_33 = V_39 ;
}
static void F_15 ( struct V_4 * V_4 )
{
V_4 -> V_9 -> V_12 [ 0 ] = ( V_31 << 2 ) ;
V_4 -> V_9 -> V_12 [ 1 ] = V_40 ;
V_4 -> V_9 -> V_30 = 2 ;
V_4 -> V_27 -> V_28 (
V_4 -> V_29 ,
V_4 -> V_9 -> V_12 ,
V_4 -> V_9 -> V_30 ) ;
V_4 -> V_33 = V_41 ;
}
static void F_16 ( struct V_4 * V_4 , unsigned long V_42 )
{
V_4 -> V_43 = V_44 ;
F_17 ( & V_4 -> V_45 , V_42 ) ;
V_4 -> V_46 = true ;
}
static inline bool F_18 ( struct V_4 * V_4 )
{
if ( ( V_4 -> V_47 ) && ( ! V_4 -> V_48 ) ) {
V_4 -> V_48 = true ;
F_12 ( V_4 ) ;
return true ;
}
return false ;
}
static inline bool F_19 ( struct V_4 * V_4 )
{
if ( ( V_4 -> V_47 ) && ( V_4 -> V_48 ) ) {
V_4 -> V_48 = false ;
F_12 ( V_4 ) ;
return true ;
}
return false ;
}
static struct V_5 * F_20 ( struct V_4 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_21 () ;
if ( ! V_6 ) {
if ( ! F_18 ( V_4 ) )
V_4 -> V_33 = V_49 ;
} else if ( F_19 ( V_4 ) ) {
F_5 ( V_6 ) ;
V_6 = NULL ;
}
return V_6 ;
}
static void F_22 ( struct V_4 * V_4 )
{
V_50:
if ( V_4 -> V_51 & V_36 ) {
F_23 ( V_4 , V_52 ) ;
F_13 ( V_4 ) ;
V_4 -> V_51 &= ~ V_36 ;
if ( V_4 -> V_7 )
F_24 ( V_4 -> V_7 ) ;
} else if ( V_4 -> V_51 & V_53 ) {
V_4 -> V_9 = F_20 ( V_4 ) ;
if ( ! V_4 -> V_9 )
return;
F_14 ( V_4 ) ;
} else if ( V_4 -> V_51 & V_54 ) {
V_4 -> V_9 = F_20 ( V_4 ) ;
if ( ! V_4 -> V_9 )
return;
F_15 ( V_4 ) ;
} else if ( V_4 -> V_51 & V_55 &&
V_4 -> V_56 ) {
if ( V_4 -> V_56 ( V_4 ) )
goto V_50;
} else
V_4 -> V_33 = V_49 ;
}
static T_1 F_25 ( struct V_4 * V_4 , T_1 V_57 ,
bool * V_58 )
{
T_1 V_59 = 0 ;
if ( V_4 -> V_60 )
V_59 |= V_61 ;
else
V_59 &= ~ V_61 ;
if ( V_4 -> V_47 && ! V_4 -> V_48 )
V_59 |= V_62 ;
else
V_59 &= ~ V_62 ;
if ( V_4 -> V_60 &&
V_4 -> V_47 && ! V_4 -> V_48 )
V_59 |= V_63 ;
else
V_59 &= ~ V_63 ;
* V_58 = V_59 & ( V_63 | V_62 ) ;
return V_59 ;
}
static void F_26 ( struct V_4 * V_4 , bool V_58 )
{
T_1 V_64 = V_4 -> V_65 . V_66 ( & V_4 -> V_65 , V_67 ) ;
V_64 &= V_68 ;
if ( ( bool ) V_64 == V_58 )
return;
if ( V_58 )
V_4 -> V_65 . V_69 ( & V_4 -> V_65 , V_67 ,
V_68 ) ;
else
V_4 -> V_65 . V_69 ( & V_4 -> V_65 , V_67 , 0 ) ;
}
static void F_27 ( struct V_4 * V_4 )
{
struct V_5 * V_6 ;
#ifdef F_8
struct V_16 V_17 ;
F_9 ( & V_17 ) ;
F_10 ( V_21 L_2 , V_17 . V_22 , V_17 . V_23 ) ;
#endif
switch ( V_4 -> V_33 ) {
case V_49 :
if ( ! V_4 -> V_9 )
break;
V_4 -> V_9 -> V_13
= V_4 -> V_27 -> V_70 (
V_4 -> V_29 ,
V_4 -> V_9 -> V_11 ,
V_71 ) ;
V_6 = V_4 -> V_9 ;
V_4 -> V_9 = NULL ;
F_3 ( V_4 , V_6 ) ;
break;
case V_72 :
{
unsigned char V_6 [ 4 ] ;
unsigned int V_73 ;
V_73 = V_4 -> V_27 -> V_70 ( V_4 -> V_29 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 ) {
V_4 -> V_33 = V_49 ;
} else if ( V_73 < 4 ) {
V_4 -> V_33 = V_49 ;
} else {
V_4 -> V_51 = V_6 [ 3 ] ;
F_22 ( V_4 ) ;
}
break;
}
case V_37 :
{
unsigned char V_6 [ 3 ] ;
V_4 -> V_27 -> V_70 ( V_4 -> V_29 , V_6 , 3 ) ;
if ( V_6 [ 2 ] != 0 ) {
F_28 ( V_4 -> V_74 ,
L_3 , V_6 [ 2 ] ) ;
}
V_4 -> V_33 = V_49 ;
break;
}
case V_41 :
{
V_4 -> V_9 -> V_13
= V_4 -> V_27 -> V_70 (
V_4 -> V_29 ,
V_4 -> V_9 -> V_11 ,
V_71 ) ;
V_6 = V_4 -> V_9 ;
V_4 -> V_9 = NULL ;
if ( V_6 -> V_11 [ 2 ] != 0 ) {
V_6 -> V_75 ( V_6 ) ;
V_4 -> V_51 &= ~ V_54 ;
F_22 ( V_4 ) ;
} else {
F_23 ( V_4 , V_76 ) ;
F_22 ( V_4 ) ;
F_3 ( V_4 , V_6 ) ;
}
break;
}
case V_39 :
{
V_4 -> V_9 -> V_13
= V_4 -> V_27 -> V_70 (
V_4 -> V_29 ,
V_4 -> V_9 -> V_11 ,
V_71 ) ;
V_6 = V_4 -> V_9 ;
V_4 -> V_9 = NULL ;
if ( V_6 -> V_11 [ 2 ] != 0 ) {
V_6 -> V_75 ( V_6 ) ;
V_4 -> V_51 &= ~ V_53 ;
F_22 ( V_4 ) ;
} else {
F_23 ( V_4 , V_77 ) ;
F_22 ( V_4 ) ;
F_3 ( V_4 , V_6 ) ;
}
break;
}
case V_34 :
{
unsigned char V_6 [ 4 ] ;
T_1 V_59 ;
bool V_58 ;
V_4 -> V_27 -> V_70 ( V_4 -> V_29 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 ) {
F_28 ( V_4 -> V_74 ,
L_4 , V_6 [ 2 ] ) ;
F_28 ( V_4 -> V_74 ,
L_5 ) ;
V_4 -> V_33 = V_49 ;
break;
}
V_59 = F_25 ( V_4 , 0 , & V_58 ) ;
if ( V_4 -> V_78 == V_79 )
F_26 ( V_4 , V_58 ) ;
if ( V_59 != ( V_6 [ 3 ] & V_80 ) ) {
V_6 [ 0 ] = ( V_31 << 2 ) ;
V_6 [ 1 ] = V_81 ;
V_6 [ 2 ] = V_59 | ( V_6 [ 3 ] & ~ V_80 ) ;
V_4 -> V_27 -> V_28 (
V_4 -> V_29 , V_6 , 3 ) ;
V_4 -> V_33 = V_82 ;
} else if ( V_4 -> V_60 ) {
V_4 -> V_9 = F_21 () ;
if ( ! V_4 -> V_9 ) {
V_4 -> V_33 = V_49 ;
break;
}
F_14 ( V_4 ) ;
} else {
V_4 -> V_33 = V_49 ;
}
break;
}
case V_82 :
{
unsigned char V_6 [ 4 ] ;
V_4 -> V_27 -> V_70 ( V_4 -> V_29 , V_6 , 4 ) ;
if ( V_6 [ 2 ] != 0 )
F_28 ( V_4 -> V_74 ,
L_6 ,
V_6 [ 2 ] ) ;
if ( V_4 -> V_60 ) {
V_4 -> V_9 = F_21 () ;
if ( ! V_4 -> V_9 ) {
V_4 -> V_33 = V_49 ;
break;
}
F_14 ( V_4 ) ;
} else {
V_4 -> V_33 = V_49 ;
}
break;
}
}
}
static enum V_14 F_29 ( struct V_4 * V_4 ,
int time )
{
enum V_14 V_14 ;
V_83:
V_14 = V_4 -> V_27 -> V_84 ( V_4 -> V_29 , time ) ;
time = 0 ;
while ( V_14 == V_25 )
V_14 = V_4 -> V_27 -> V_84 ( V_4 -> V_29 , 0 ) ;
if ( V_14 == V_85 ) {
F_23 ( V_4 , V_86 ) ;
F_27 ( V_4 ) ;
V_14 = V_4 -> V_27 -> V_84 ( V_4 -> V_29 , 0 ) ;
} else if ( V_14 == V_87 ) {
F_23 ( V_4 , V_88 ) ;
V_4 -> V_33 = V_49 ;
if ( V_4 -> V_9 != NULL ) {
F_6 ( V_4 , V_10 ) ;
}
V_14 = V_4 -> V_27 -> V_84 ( V_4 -> V_29 , 0 ) ;
}
if ( F_30 ( V_4 -> V_7 ) &&
( V_14 == V_89 || V_4 -> V_90 ) ) {
unsigned char V_6 [ 2 ] ;
if ( V_4 -> V_33 != V_49 ) {
V_4 -> V_90 = true ;
} else {
V_4 -> V_90 = false ;
F_23 ( V_4 , V_91 ) ;
V_6 [ 0 ] = ( V_31 << 2 ) ;
V_6 [ 1 ] = V_92 ;
V_4 -> V_27 -> V_28 (
V_4 -> V_29 , V_6 , 2 ) ;
V_4 -> V_33 = V_72 ;
goto V_83;
}
}
if ( V_14 == V_19 ) {
F_23 ( V_4 , V_93 ) ;
V_14 = F_7 ( V_4 ) ;
if ( V_14 != V_19 )
goto V_83;
}
if ( ( V_14 == V_19 )
&& ( F_31 ( & V_4 -> V_94 ) ) ) {
F_32 ( & V_4 -> V_94 , 0 ) ;
if ( V_4 -> V_60 || V_4 -> V_47 ) {
F_12 ( V_4 ) ;
} else {
V_4 -> V_9 = F_20 ( V_4 ) ;
if ( ! V_4 -> V_9 )
goto V_26;
F_15 ( V_4 ) ;
}
goto V_83;
}
V_26:
return V_14 ;
}
static void F_33 ( struct V_4 * V_4 )
{
if ( V_4 -> V_33 == V_49 && V_4 -> V_9 == NULL ) {
F_16 ( V_4 , V_44 + V_95 ) ;
if ( V_4 -> V_96 )
F_34 ( V_4 -> V_96 ) ;
F_7 ( V_4 ) ;
F_29 ( V_4 , 0 ) ;
}
}
static void F_35 ( void * V_97 ,
struct V_5 * V_6 )
{
struct V_4 * V_4 = V_97 ;
enum V_14 V_98 ;
unsigned long V_99 ;
#ifdef F_8
struct V_16 V_17 ;
#endif
F_36 ( V_4 -> V_18 ) ;
V_4 -> V_18 = V_6 ;
#ifdef F_8
F_9 ( & V_17 ) ;
F_10 ( L_7 , V_17 . V_22 , V_17 . V_23 ) ;
#endif
if ( V_4 -> V_100 ) {
V_4 -> V_9 = V_4 -> V_18 ;
V_4 -> V_18 = NULL ;
V_98 = F_29 ( V_4 , 0 ) ;
while ( V_98 != V_19 ) {
F_37 ( V_101 ) ;
V_98 = F_29 ( V_4 ,
V_101 ) ;
}
return;
}
F_38 ( & V_4 -> V_102 , V_99 ) ;
F_33 ( V_4 ) ;
F_39 ( & V_4 -> V_102 , V_99 ) ;
}
static void F_40 ( void * V_97 , bool V_103 )
{
struct V_4 * V_4 = V_97 ;
enum V_14 V_98 ;
V_4 -> V_100 = V_103 ;
if ( V_103 ) {
V_98 = F_29 ( V_4 , 0 ) ;
while ( V_98 != V_19 ) {
F_37 ( V_101 ) ;
V_98 = F_29 ( V_4 ,
V_101 ) ;
}
}
}
static inline void F_41 ( struct V_104 * V_105 )
{
V_105 -> V_106 = - 1 ;
}
static inline int F_42 ( struct V_104 * V_105 )
{
return V_105 -> V_106 != - 1 ;
}
static inline int F_43 ( enum V_14 V_107 ,
const struct V_4 * V_4 ,
struct V_104 * V_108 )
{
unsigned int V_109 = 0 ;
if ( V_4 -> V_110 < V_111 )
V_109 = V_112 [ V_4 -> V_110 ] ;
if ( V_109 == 0 || V_107 != V_113 )
F_41 ( V_108 ) ;
else if ( ! F_42 ( V_108 ) ) {
F_44 ( V_108 ) ;
F_45 ( V_108 , V_109 * V_114 ) ;
} else {
struct V_104 V_115 ;
F_44 ( & V_115 ) ;
if ( F_46 ( F_47 ( & V_115 , V_108 ) > 0 ) ) {
F_41 ( V_108 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_48 ( void * V_12 )
{
struct V_4 * V_4 = V_12 ;
unsigned long V_99 ;
enum V_14 V_107 ;
struct V_104 V_108 ;
F_41 ( & V_108 ) ;
F_49 ( V_116 , V_117 ) ;
while ( ! F_50 () ) {
int V_118 ;
F_38 ( & ( V_4 -> V_102 ) , V_99 ) ;
V_107 = F_29 ( V_4 , 0 ) ;
if ( V_107 != V_19 && ! V_4 -> V_46 )
F_16 ( V_4 , V_44 + V_95 ) ;
F_39 ( & ( V_4 -> V_102 ) , V_99 ) ;
V_118 = F_43 ( V_107 , V_4 ,
& V_108 ) ;
if ( V_107 == V_25 )
;
else if ( V_107 == V_113 && V_118 )
F_51 () ;
else if ( V_107 == V_19 ) {
if ( F_31 ( & V_4 -> V_119 ) ) {
F_52 ( 100 ) ;
} else {
F_53 ( V_120 ) ;
F_51 () ;
}
} else
F_52 ( 1 ) ;
}
return 0 ;
}
static void F_54 ( void * V_97 )
{
struct V_4 * V_4 = V_97 ;
unsigned long V_99 = 0 ;
bool V_100 = V_4 -> V_100 ;
F_37 ( 10 ) ;
if ( ! V_100 )
F_38 ( & V_4 -> V_102 , V_99 ) ;
F_29 ( V_4 , 10 ) ;
if ( ! V_100 )
F_39 ( & V_4 -> V_102 , V_99 ) ;
}
static void F_55 ( void * V_97 )
{
struct V_4 * V_4 = V_97 ;
if ( ! V_4 -> V_121 )
return;
F_32 ( & V_4 -> V_94 , 1 ) ;
}
static void F_56 ( void * V_97 , bool V_122 )
{
struct V_4 * V_4 = V_97 ;
unsigned long V_99 ;
F_32 ( & V_4 -> V_119 , V_122 ) ;
F_38 ( & V_4 -> V_102 , V_99 ) ;
F_33 ( V_4 ) ;
F_39 ( & V_4 -> V_102 , V_99 ) ;
}
static void F_57 ( unsigned long V_12 )
{
struct V_4 * V_4 = (struct V_4 * ) V_12 ;
enum V_14 V_107 ;
unsigned long V_99 ;
unsigned long V_123 ;
long V_124 ;
long V_125 ;
#ifdef F_8
struct V_16 V_17 ;
#endif
F_38 ( & ( V_4 -> V_102 ) , V_99 ) ;
#ifdef F_8
F_9 ( & V_17 ) ;
F_10 ( V_21 L_8 , V_17 . V_22 , V_17 . V_23 ) ;
#endif
V_123 = V_44 ;
V_124 = ( ( ( long ) V_123 - ( long ) V_4 -> V_43 )
* V_126 ) ;
V_107 = F_29 ( V_4 , V_124 ) ;
if ( ( V_4 -> V_47 ) && ( ! V_4 -> V_48 ) ) {
V_125 = V_44 + V_95 ;
F_23 ( V_4 , V_127 ) ;
goto V_128;
}
if ( V_107 == V_113 ) {
F_23 ( V_4 , V_129 ) ;
V_125 = V_44 + 1 ;
} else {
F_23 ( V_4 , V_127 ) ;
V_125 = V_44 + V_95 ;
}
V_128:
if ( V_107 != V_19 )
F_16 ( V_4 , V_125 ) ;
else
V_4 -> V_46 = false ;
F_39 ( & ( V_4 -> V_102 ) , V_99 ) ;
}
static T_2 F_58 ( int V_47 , void * V_12 )
{
struct V_4 * V_4 = V_12 ;
unsigned long V_99 ;
#ifdef F_8
struct V_16 V_17 ;
#endif
F_38 ( & ( V_4 -> V_102 ) , V_99 ) ;
F_23 ( V_4 , V_130 ) ;
#ifdef F_8
F_9 ( & V_17 ) ;
F_10 ( V_21 L_9 , V_17 . V_22 , V_17 . V_23 ) ;
#endif
F_29 ( V_4 , 0 ) ;
F_39 ( & ( V_4 -> V_102 ) , V_99 ) ;
return V_131 ;
}
static T_2 F_59 ( int V_47 , void * V_12 )
{
struct V_4 * V_4 = V_12 ;
V_4 -> V_65 . V_69 ( & V_4 -> V_65 , V_67 ,
V_132
| V_68 ) ;
return F_58 ( V_47 , V_12 ) ;
}
static int F_60 ( void * V_97 ,
T_3 V_7 )
{
struct V_4 * V_133 = V_97 ;
int V_122 = 0 ;
V_133 -> V_7 = V_7 ;
if ( V_133 -> V_134 )
V_133 -> V_134 ( V_133 ) ;
F_61 ( & V_133 -> V_45 , F_57 , ( long ) V_133 ) ;
F_16 ( V_133 , V_44 + V_95 ) ;
if ( V_133 -> V_110 < V_135 )
V_122 = V_136 [ V_133 -> V_110 ] ;
else if ( ( V_133 -> V_78 != V_79 ) && ( ! V_133 -> V_47 ) )
V_122 = 1 ;
if ( V_122 ) {
V_133 -> V_96 = F_62 ( F_48 , V_133 ,
L_10 , V_133 -> V_110 ) ;
if ( F_63 ( V_133 -> V_96 ) ) {
F_64 ( V_133 -> V_74 , L_11
L_12
L_13 ,
F_65 ( V_133 -> V_96 ) ) ;
V_133 -> V_96 = NULL ;
}
}
return 0 ;
}
static int F_66 ( void * V_97 , struct V_137 * V_12 )
{
struct V_4 * V_138 = V_97 ;
V_12 -> V_139 = V_138 -> V_140 ;
V_12 -> V_74 = V_138 -> V_74 ;
V_12 -> V_141 = V_138 -> V_141 ;
F_67 ( V_138 -> V_74 ) ;
return 0 ;
}
static void F_68 ( void * V_97 , bool V_122 )
{
struct V_4 * V_4 = V_97 ;
if ( ! V_122 )
F_32 ( & V_4 -> V_94 , 0 ) ;
}
static void F_69 ( struct V_4 * V_142 )
{
if ( V_142 -> V_78 == V_79 )
V_142 -> V_65 . V_69 ( & V_142 -> V_65 , V_67 , 0 ) ;
F_70 ( V_142 -> V_47 , V_142 ) ;
}
static int F_71 ( struct V_4 * V_142 )
{
int V_15 ;
if ( ! V_142 -> V_47 )
return 0 ;
if ( V_142 -> V_78 == V_79 ) {
V_15 = F_72 ( V_142 -> V_47 ,
F_59 ,
V_143 ,
V_144 ,
V_142 ) ;
if ( ! V_15 )
V_142 -> V_65 . V_69 ( & V_142 -> V_65 , V_67 ,
V_68 ) ;
} else
V_15 = F_72 ( V_142 -> V_47 ,
F_58 ,
V_143 ,
V_144 ,
V_142 ) ;
if ( V_15 ) {
F_28 ( V_142 -> V_74 , L_14
L_15 ,
V_144 , V_142 -> V_47 ) ;
V_142 -> V_47 = 0 ;
} else {
V_142 -> V_145 = F_69 ;
F_73 ( V_142 -> V_74 , L_16 , V_142 -> V_47 ) ;
}
return V_15 ;
}
static unsigned char F_74 ( struct V_146 * V_65 , unsigned int V_147 )
{
unsigned int V_148 = V_65 -> V_149 ;
return F_75 ( V_148 + ( V_147 * V_65 -> V_150 ) ) ;
}
static void F_76 ( struct V_146 * V_65 , unsigned int V_147 ,
unsigned char V_151 )
{
unsigned int V_148 = V_65 -> V_149 ;
F_77 ( V_151 , V_148 + ( V_147 * V_65 -> V_150 ) ) ;
}
static unsigned char F_78 ( struct V_146 * V_65 , unsigned int V_147 )
{
unsigned int V_148 = V_65 -> V_149 ;
return ( F_79 ( V_148 + ( V_147 * V_65 -> V_150 ) ) >> V_65 -> V_152 ) & 0xff ;
}
static void F_80 ( struct V_146 * V_65 , unsigned int V_147 ,
unsigned char V_151 )
{
unsigned int V_148 = V_65 -> V_149 ;
F_81 ( V_151 << V_65 -> V_152 , V_148 + ( V_147 * V_65 -> V_150 ) ) ;
}
static unsigned char F_82 ( struct V_146 * V_65 , unsigned int V_147 )
{
unsigned int V_148 = V_65 -> V_149 ;
return ( F_83 ( V_148 + ( V_147 * V_65 -> V_150 ) ) >> V_65 -> V_152 ) & 0xff ;
}
static void F_84 ( struct V_146 * V_65 , unsigned int V_147 ,
unsigned char V_151 )
{
unsigned int V_148 = V_65 -> V_149 ;
F_85 ( V_151 << V_65 -> V_152 , V_148 + ( V_147 * V_65 -> V_150 ) ) ;
}
static void F_86 ( struct V_4 * V_142 )
{
unsigned int V_148 = V_142 -> V_65 . V_149 ;
int V_153 ;
if ( V_148 ) {
for ( V_153 = 0 ; V_153 < V_142 -> V_154 ; V_153 ++ )
F_87 ( V_148 + V_153 * V_142 -> V_65 . V_150 ,
V_142 -> V_65 . V_155 ) ;
}
}
static int F_88 ( struct V_4 * V_142 )
{
unsigned int V_148 = V_142 -> V_65 . V_149 ;
int V_153 ;
if ( ! V_148 )
return - V_156 ;
V_142 -> V_157 = F_86 ;
switch ( V_142 -> V_65 . V_155 ) {
case 1 :
V_142 -> V_65 . V_66 = F_74 ;
V_142 -> V_65 . V_69 = F_76 ;
break;
case 2 :
V_142 -> V_65 . V_66 = F_78 ;
V_142 -> V_65 . V_69 = F_80 ;
break;
case 4 :
V_142 -> V_65 . V_66 = F_82 ;
V_142 -> V_65 . V_69 = F_84 ;
break;
default:
F_28 ( V_142 -> V_74 , L_17 ,
V_142 -> V_65 . V_155 ) ;
return - V_158 ;
}
for ( V_153 = 0 ; V_153 < V_142 -> V_154 ; V_153 ++ ) {
if ( F_89 ( V_148 + V_153 * V_142 -> V_65 . V_150 ,
V_142 -> V_65 . V_155 , V_144 ) == NULL ) {
while ( V_153 -- ) {
F_87 ( V_148 + V_153 * V_142 -> V_65 . V_150 ,
V_142 -> V_65 . V_155 ) ;
}
return - V_159 ;
}
}
return 0 ;
}
static unsigned char F_90 ( struct V_146 * V_65 , unsigned int V_147 )
{
return F_91 ( ( V_65 -> V_148 ) + ( V_147 * V_65 -> V_150 ) ) ;
}
static void F_92 ( struct V_146 * V_65 , unsigned int V_147 ,
unsigned char V_151 )
{
F_93 ( V_151 , ( V_65 -> V_148 ) + ( V_147 * V_65 -> V_150 ) ) ;
}
static unsigned char F_94 ( struct V_146 * V_65 , unsigned int V_147 )
{
return ( F_95 ( ( V_65 -> V_148 ) + ( V_147 * V_65 -> V_150 ) ) >> V_65 -> V_152 )
& 0xff ;
}
static void F_96 ( struct V_146 * V_65 , unsigned int V_147 ,
unsigned char V_151 )
{
F_93 ( V_151 << V_65 -> V_152 , ( V_65 -> V_148 ) + ( V_147 * V_65 -> V_150 ) ) ;
}
static unsigned char F_97 ( struct V_146 * V_65 , unsigned int V_147 )
{
return ( F_98 ( ( V_65 -> V_148 ) + ( V_147 * V_65 -> V_150 ) ) >> V_65 -> V_152 )
& 0xff ;
}
static void F_99 ( struct V_146 * V_65 , unsigned int V_147 ,
unsigned char V_151 )
{
F_100 ( V_151 << V_65 -> V_152 , ( V_65 -> V_148 ) + ( V_147 * V_65 -> V_150 ) ) ;
}
static unsigned char F_101 ( struct V_146 * V_65 , unsigned int V_147 )
{
return ( F_102 ( ( V_65 -> V_148 ) + ( V_147 * V_65 -> V_150 ) ) >> V_65 -> V_152 )
& 0xff ;
}
static void F_103 ( struct V_146 * V_65 , unsigned int V_147 ,
unsigned char V_151 )
{
F_104 ( V_151 << V_65 -> V_152 , ( V_65 -> V_148 ) + ( V_147 * V_65 -> V_150 ) ) ;
}
static void F_105 ( struct V_4 * V_142 )
{
unsigned long V_148 = V_142 -> V_65 . V_149 ;
int V_160 ;
if ( V_142 -> V_65 . V_148 ) {
F_106 ( V_142 -> V_65 . V_148 ) ;
V_160 = ( ( V_142 -> V_154 * V_142 -> V_65 . V_150 )
- ( V_142 -> V_65 . V_150 - V_142 -> V_65 . V_155 ) ) ;
F_107 ( V_148 , V_160 ) ;
}
}
static int F_108 ( struct V_4 * V_142 )
{
unsigned long V_148 = V_142 -> V_65 . V_149 ;
int V_160 ;
if ( ! V_148 )
return - V_156 ;
V_142 -> V_157 = F_105 ;
switch ( V_142 -> V_65 . V_155 ) {
case 1 :
V_142 -> V_65 . V_66 = F_90 ;
V_142 -> V_65 . V_69 = F_92 ;
break;
case 2 :
V_142 -> V_65 . V_66 = F_94 ;
V_142 -> V_65 . V_69 = F_96 ;
break;
case 4 :
V_142 -> V_65 . V_66 = F_97 ;
V_142 -> V_65 . V_69 = F_99 ;
break;
#ifdef F_102
case 8 :
V_142 -> V_65 . V_66 = F_101 ;
V_142 -> V_65 . V_69 = F_103 ;
break;
#endif
default:
F_28 ( V_142 -> V_74 , L_17 ,
V_142 -> V_65 . V_155 ) ;
return - V_158 ;
}
V_160 = ( ( V_142 -> V_154 * V_142 -> V_65 . V_150 )
- ( V_142 -> V_65 . V_150 - V_142 -> V_65 . V_155 ) ) ;
if ( F_109 ( V_148 , V_160 , V_144 ) == NULL )
return - V_159 ;
V_142 -> V_65 . V_148 = F_110 ( V_148 , V_160 ) ;
if ( V_142 -> V_65 . V_148 == NULL ) {
F_107 ( V_148 , V_160 ) ;
return - V_159 ;
}
return 0 ;
}
static int F_111 ( struct V_161 * V_162 , int * V_163 , char * V_164 , char * * V_165 )
{
char * V_166 ;
int V_167 ;
V_166 = strchr ( * V_165 , ',' ) ;
if ( ! V_166 ) {
F_10 (KERN_WARNING PFX L_18 , name) ;
return - V_158 ;
}
* V_166 = '\0' ;
V_166 ++ ;
for ( V_167 = 0 ; V_162 [ V_167 ] . V_164 ; V_167 ++ ) {
if ( strcmp ( * V_165 , V_162 [ V_167 ] . V_164 ) == 0 ) {
* V_163 = V_162 [ V_167 ] . V_163 ;
* V_165 = V_166 ;
return 0 ;
}
}
F_10 (KERN_WARNING PFX L_19 , name, *curr) ;
return - V_158 ;
}
static int F_112 ( const char * V_165 , const char * V_168 ,
const char * V_164 , int * V_163 )
{
char * V_169 ;
if ( strcmp ( V_165 , V_164 ) == 0 ) {
if ( ! V_168 ) {
F_10 (KERN_WARNING PFX
L_20 ,
curr) ;
return - V_158 ;
}
* V_163 = F_113 ( V_168 , & V_169 , 0 ) ;
if ( ( * V_169 != '\0' ) || ( * V_168 == '\0' ) ) {
F_10 (KERN_WARNING PFX
L_21 ,
curr) ;
return - V_158 ;
}
return 1 ;
}
return 0 ;
}
static struct V_4 * F_114 ( void )
{
struct V_4 * V_142 = F_115 ( sizeof( * V_142 ) , V_170 ) ;
if ( V_142 )
F_116 ( & V_142 -> V_102 ) ;
return V_142 ;
}
static int F_117 ( const char * V_163 , struct V_171 * V_172 )
{
char * V_173 = F_118 ( V_163 , V_170 ) ;
int V_15 ;
char * V_174 , * V_165 , * V_166 , * V_169 , * V_175 ;
enum V_176 V_177 ;
enum V_78 V_78 ;
int V_178 ;
unsigned long V_148 ;
int V_150 ;
int V_155 ;
int V_152 ;
int V_47 ;
int V_179 ;
int V_180 ;
int V_73 ;
struct V_4 * V_142 ;
if ( ! V_173 )
return - V_181 ;
V_73 = strlen ( V_173 ) ;
V_180 = V_73 - 1 ;
while ( ( V_180 >= 0 ) && isspace ( V_173 [ V_180 ] ) ) {
V_173 [ V_180 ] = '\0' ;
V_180 -- ;
}
for ( V_165 = V_173 ; V_165 ; V_165 = V_174 ) {
V_150 = 1 ;
V_155 = 1 ;
V_152 = 0 ;
V_47 = 0 ;
V_179 = 0 ;
V_174 = strchr ( V_165 , ':' ) ;
if ( V_174 ) {
* V_174 = '\0' ;
V_174 ++ ;
}
V_15 = F_111 ( V_182 , & V_180 , L_22 , & V_165 ) ;
if ( V_15 )
break;
V_177 = V_180 ;
V_15 = F_111 ( V_183 , & V_180 , L_23 , & V_165 ) ;
if ( V_15 )
break;
V_78 = V_180 ;
V_15 = F_111 ( V_184 , & V_178 , L_24 , & V_165 ) ;
if ( V_15 )
break;
V_166 = strchr ( V_165 , ',' ) ;
if ( V_166 ) {
* V_166 = '\0' ;
V_166 ++ ;
}
V_148 = F_113 ( V_165 , & V_169 , 0 ) ;
if ( ( * V_169 != '\0' ) || ( * V_165 == '\0' ) ) {
F_10 (KERN_WARNING PFX L_25
L_26 , curr) ;
break;
}
while ( V_166 ) {
V_165 = V_166 ;
V_166 = strchr ( V_165 , ',' ) ;
if ( V_166 ) {
* V_166 = '\0' ;
V_166 ++ ;
}
V_175 = strchr ( V_165 , '=' ) ;
if ( V_175 ) {
* V_175 = '\0' ;
V_175 ++ ;
}
V_15 = F_112 ( V_165 , V_175 , L_27 , & V_150 ) ;
if ( V_15 < 0 )
goto V_26;
else if ( V_15 )
continue;
V_15 = F_112 ( V_165 , V_175 , L_28 , & V_155 ) ;
if ( V_15 < 0 )
goto V_26;
else if ( V_15 )
continue;
V_15 = F_112 ( V_165 , V_175 , L_29 , & V_152 ) ;
if ( V_15 < 0 )
goto V_26;
else if ( V_15 )
continue;
V_15 = F_112 ( V_165 , V_175 , L_30 , & V_47 ) ;
if ( V_15 < 0 )
goto V_26;
else if ( V_15 )
continue;
V_15 = F_112 ( V_165 , V_175 , L_31 , & V_179 ) ;
if ( V_15 < 0 )
goto V_26;
else if ( V_15 )
continue;
V_15 = - V_158 ;
F_10 (KERN_WARNING PFX
L_32 ,
curr) ;
goto V_26;
}
if ( V_177 == V_185 ) {
V_142 = F_114 () ;
if ( ! V_142 ) {
V_15 = - V_181 ;
goto V_26;
}
V_142 -> V_140 = V_186 ;
V_142 -> V_78 = V_78 ;
V_142 -> V_65 . V_149 = V_148 ;
V_142 -> V_65 . V_187 = V_178 ;
if ( V_178 == V_188 )
V_142 -> V_189 = F_108 ;
else
V_142 -> V_189 = F_88 ;
V_142 -> V_65 . V_148 = NULL ;
V_142 -> V_65 . V_150 = V_150 ;
if ( ! V_142 -> V_65 . V_150 )
V_142 -> V_65 . V_150 = V_190 ;
V_142 -> V_65 . V_155 = V_155 ;
if ( ! V_142 -> V_65 . V_155 )
V_142 -> V_65 . V_155 = V_190 ;
V_142 -> V_65 . V_152 = V_152 ;
V_142 -> V_47 = V_47 ;
if ( V_142 -> V_47 )
V_142 -> V_134 = F_71 ;
V_142 -> V_191 = V_179 ;
V_15 = F_119 ( V_142 ) ;
if ( V_15 ) {
F_120 ( V_142 ) ;
goto V_26;
}
V_15 = F_121 ( V_142 ) ;
if ( V_15 ) {
F_122 ( V_142 ) ;
goto V_26;
}
} else {
struct V_4 * V_192 , * V_193 ;
F_123 ( & V_194 ) ;
F_124 (e, tmp_e, &smi_infos, link) {
if ( V_192 -> V_65 . V_187 != V_178 )
continue;
if ( V_192 -> V_78 != V_78 )
continue;
if ( V_192 -> V_65 . V_149 == V_148 )
F_122 ( V_192 ) ;
}
F_125 ( & V_194 ) ;
}
}
V_15 = V_73 ;
V_26:
F_120 ( V_173 ) ;
return V_15 ;
}
static int F_126 ( void )
{
int V_195 = - V_156 ;
int V_167 ;
struct V_4 * V_142 ;
for ( V_167 = 0 ; V_167 < V_196 ; V_167 ++ ) {
if ( ! V_197 [ V_167 ] && ! V_198 [ V_167 ] )
continue;
V_142 = F_114 () ;
if ( ! V_142 )
return - V_181 ;
V_142 -> V_140 = V_199 ;
F_10 (KERN_INFO PFX L_33 ) ;
if ( ! V_78 [ V_167 ] || strcmp ( V_78 [ V_167 ] , L_34 ) == 0 ) {
V_142 -> V_78 = V_200 ;
} else if ( strcmp ( V_78 [ V_167 ] , L_35 ) == 0 ) {
V_142 -> V_78 = V_201 ;
} else if ( strcmp ( V_78 [ V_167 ] , L_36 ) == 0 ) {
V_142 -> V_78 = V_79 ;
} else {
F_10 (KERN_WARNING PFX L_37
L_38 ,
i, si_type[i]) ;
F_120 ( V_142 ) ;
continue;
}
if ( V_197 [ V_167 ] ) {
V_142 -> V_189 = F_88 ;
V_142 -> V_65 . V_149 = V_197 [ V_167 ] ;
V_142 -> V_65 . V_187 = V_202 ;
} else if ( V_198 [ V_167 ] ) {
V_142 -> V_189 = F_108 ;
V_142 -> V_65 . V_149 = V_198 [ V_167 ] ;
V_142 -> V_65 . V_187 = V_188 ;
} else {
F_10 (KERN_WARNING PFX L_37
L_39
L_40 , i) ;
F_120 ( V_142 ) ;
continue;
}
V_142 -> V_65 . V_148 = NULL ;
V_142 -> V_65 . V_150 = V_203 [ V_167 ] ;
if ( ! V_142 -> V_65 . V_150 )
V_142 -> V_65 . V_150 = V_190 ;
V_142 -> V_65 . V_155 = V_204 [ V_167 ] ;
if ( ! V_142 -> V_65 . V_155 )
V_142 -> V_65 . V_155 = V_190 ;
V_142 -> V_65 . V_152 = V_205 [ V_167 ] ;
V_142 -> V_47 = V_206 [ V_167 ] ;
if ( V_142 -> V_47 )
V_142 -> V_134 = F_71 ;
V_142 -> V_191 = V_207 [ V_167 ] ;
if ( ! F_119 ( V_142 ) ) {
if ( F_121 ( V_142 ) )
F_122 ( V_142 ) ;
V_195 = 0 ;
} else {
F_120 ( V_142 ) ;
}
}
return V_195 ;
}
static T_4 F_127 ( T_5 V_208 ,
T_4 V_209 , void * V_210 )
{
struct V_4 * V_4 = V_210 ;
unsigned long V_99 ;
#ifdef F_8
struct V_16 V_17 ;
#endif
F_38 ( & ( V_4 -> V_102 ) , V_99 ) ;
F_23 ( V_4 , V_130 ) ;
#ifdef F_8
F_9 ( & V_17 ) ;
F_10 ( L_41 , V_17 . V_22 , V_17 . V_23 ) ;
#endif
F_29 ( V_4 , 0 ) ;
F_39 ( & ( V_4 -> V_102 ) , V_99 ) ;
return V_211 ;
}
static void F_128 ( struct V_4 * V_142 )
{
if ( ! V_142 -> V_47 )
return;
F_129 ( NULL , V_142 -> V_47 , & F_127 ) ;
}
static int F_130 ( struct V_4 * V_142 )
{
T_6 V_212 ;
if ( ! V_142 -> V_47 )
return 0 ;
V_212 = F_131 ( NULL ,
V_142 -> V_47 ,
V_213 ,
& F_127 ,
V_142 ) ;
if ( V_212 != V_214 ) {
F_28 ( V_142 -> V_74 , L_42
L_15 , V_144 , V_142 -> V_47 ) ;
V_142 -> V_47 = 0 ;
return - V_158 ;
} else {
V_142 -> V_145 = F_128 ;
F_73 ( V_142 -> V_74 , L_43 , V_142 -> V_47 ) ;
return 0 ;
}
}
static int F_132 ( struct V_215 * V_216 )
{
struct V_4 * V_142 ;
int V_15 ;
if ( V_216 -> V_217 != 1 ) {
F_10 (KERN_INFO PFX L_44 , spmi->IPMIlegacy) ;
return - V_156 ;
}
V_142 = F_114 () ;
if ( ! V_142 ) {
F_10 (KERN_ERR PFX L_45 ) ;
return - V_181 ;
}
V_142 -> V_140 = V_218 ;
F_10 (KERN_INFO PFX L_46 ) ;
switch ( V_216 -> V_219 ) {
case 1 :
V_142 -> V_78 = V_200 ;
break;
case 2 :
V_142 -> V_78 = V_201 ;
break;
case 3 :
V_142 -> V_78 = V_79 ;
break;
case 4 :
F_120 ( V_142 ) ;
return - V_159 ;
default:
F_10 (KERN_INFO PFX L_47 ,
spmi->InterfaceType) ;
F_120 ( V_142 ) ;
return - V_159 ;
}
if ( V_216 -> V_220 & 1 ) {
V_142 -> V_47 = V_216 -> V_221 ;
V_142 -> V_134 = F_130 ;
} else if ( V_216 -> V_220 & 2 ) {
V_142 -> V_47 = V_216 -> V_222 ;
V_142 -> V_134 = F_71 ;
} else {
V_142 -> V_47 = 0 ;
V_142 -> V_134 = NULL ;
}
if ( V_216 -> V_148 . V_223 ) {
V_142 -> V_65 . V_150 = V_216 -> V_148 . V_223 / 8 ;
} else {
V_142 -> V_65 . V_150 = V_190 ;
}
V_142 -> V_65 . V_155 = V_142 -> V_65 . V_150 ;
V_142 -> V_65 . V_152 = V_216 -> V_148 . V_224 ;
if ( V_216 -> V_148 . V_225 == V_226 ) {
V_142 -> V_189 = F_108 ;
V_142 -> V_65 . V_187 = V_188 ;
} else if ( V_216 -> V_148 . V_225 == V_227 ) {
V_142 -> V_189 = F_88 ;
V_142 -> V_65 . V_187 = V_202 ;
} else {
F_120 ( V_142 ) ;
F_10 (KERN_WARNING PFX L_48 ) ;
return - V_159 ;
}
V_142 -> V_65 . V_149 = V_216 -> V_148 . V_228 ;
F_133 ( L_49 ,
( V_142 -> V_65 . V_187 == V_202 ) ? L_50 : L_51 ,
V_142 -> V_65 . V_149 , V_142 -> V_65 . V_155 , V_142 -> V_65 . V_150 ,
V_142 -> V_47 ) ;
V_15 = F_119 ( V_142 ) ;
if ( V_15 )
F_120 ( V_142 ) ;
return V_15 ;
}
static void F_134 ( void )
{
T_6 V_212 ;
struct V_215 * V_216 ;
int V_167 ;
if ( V_229 )
return;
if ( V_230 )
return;
for ( V_167 = 0 ; ; V_167 ++ ) {
V_212 = F_135 ( V_231 , V_167 + 1 ,
(struct V_232 * * ) & V_216 ) ;
if ( V_212 != V_214 )
return;
F_132 ( V_216 ) ;
}
}
static int F_136 ( struct V_233 * V_74 ,
const struct V_234 * V_235 )
{
struct V_236 * V_237 ;
struct V_4 * V_142 ;
struct V_238 * V_239 , * V_240 ;
T_5 V_241 ;
T_6 V_212 ;
unsigned long long V_242 ;
int V_15 ;
V_237 = F_137 ( V_74 ) ;
if ( ! V_237 )
return - V_156 ;
V_142 = F_114 () ;
if ( ! V_142 )
return - V_181 ;
V_142 -> V_140 = V_243 ;
F_10 (KERN_INFO PFX L_52 ) ;
V_241 = V_237 -> V_241 ;
V_142 -> V_141 . V_244 . T_5 = V_241 ;
V_212 = F_138 ( V_241 , L_53 , NULL , & V_242 ) ;
if ( F_139 ( V_212 ) )
goto V_245;
switch ( V_242 ) {
case 1 :
V_142 -> V_78 = V_200 ;
break;
case 2 :
V_142 -> V_78 = V_201 ;
break;
case 3 :
V_142 -> V_78 = V_79 ;
break;
case 4 :
goto V_245;
default:
F_73 ( & V_74 -> V_74 , L_54 , V_242 ) ;
goto V_245;
}
V_239 = F_140 ( V_74 , V_246 , 0 ) ;
if ( V_239 ) {
V_142 -> V_189 = F_88 ;
V_142 -> V_65 . V_187 = V_202 ;
} else {
V_239 = F_140 ( V_74 , V_247 , 0 ) ;
if ( V_239 ) {
V_142 -> V_189 = F_108 ;
V_142 -> V_65 . V_187 = V_188 ;
}
}
if ( ! V_239 ) {
F_141 ( & V_74 -> V_74 , L_55 ) ;
goto V_245;
}
V_142 -> V_65 . V_149 = V_239 -> V_248 ;
V_142 -> V_65 . V_150 = V_190 ;
V_240 = F_140 ( V_74 ,
( V_142 -> V_65 . V_187 == V_202 ) ?
V_246 : V_247 ,
1 ) ;
if ( V_240 ) {
if ( V_240 -> V_248 > V_142 -> V_65 . V_149 )
V_142 -> V_65 . V_150 = V_240 -> V_248 - V_142 -> V_65 . V_149 ;
}
V_142 -> V_65 . V_155 = V_190 ;
V_142 -> V_65 . V_152 = 0 ;
V_212 = F_138 ( V_241 , L_56 , NULL , & V_242 ) ;
if ( F_142 ( V_212 ) ) {
V_142 -> V_47 = V_242 ;
V_142 -> V_134 = F_130 ;
} else if ( F_143 ( V_74 , 0 ) ) {
V_142 -> V_47 = F_144 ( V_74 , 0 ) ;
V_142 -> V_134 = F_71 ;
}
V_142 -> V_74 = & V_74 -> V_74 ;
F_145 ( V_74 , V_142 ) ;
F_73 ( V_142 -> V_74 , L_57 ,
V_239 , V_142 -> V_65 . V_155 , V_142 -> V_65 . V_150 ,
V_142 -> V_47 ) ;
V_15 = F_119 ( V_142 ) ;
if ( V_15 )
F_120 ( V_142 ) ;
return V_15 ;
V_245:
F_120 ( V_142 ) ;
return - V_158 ;
}
static void F_146 ( struct V_233 * V_74 )
{
struct V_4 * V_142 = F_147 ( V_74 ) ;
F_122 ( V_142 ) ;
}
static int F_148 ( const struct V_249 * V_250 ,
struct V_251 * V_252 )
{
const T_1 * V_12 = ( const T_1 * ) V_250 ;
unsigned long V_253 ;
T_1 V_254 ;
T_1 V_73 = V_250 -> V_255 ;
V_252 -> type = V_12 [ 4 ] ;
memcpy ( & V_253 , V_12 + 8 , sizeof( unsigned long ) ) ;
if ( V_73 >= 0x11 ) {
if ( V_253 & 1 ) {
V_253 &= 0xFFFE ;
V_252 -> V_178 = V_202 ;
} else
V_252 -> V_178 = V_188 ;
V_252 -> V_253 = V_253 | ( ( V_12 [ 0x10 ] & 0x10 ) >> 4 ) ;
V_252 -> V_47 = V_12 [ 0x11 ] ;
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
return - V_159 ;
}
} else {
V_252 -> V_253 = V_253 & 0xfffe ;
V_252 -> V_178 = V_202 ;
V_252 -> V_147 = 1 ;
}
V_252 -> V_191 = V_12 [ 6 ] ;
return 0 ;
}
static void F_149 ( struct V_251 * V_256 )
{
struct V_4 * V_142 ;
V_142 = F_114 () ;
if ( ! V_142 ) {
F_10 (KERN_ERR PFX L_58 ) ;
return;
}
V_142 -> V_140 = V_257 ;
F_10 (KERN_INFO PFX L_59 ) ;
switch ( V_256 -> type ) {
case 0x01 :
V_142 -> V_78 = V_200 ;
break;
case 0x02 :
V_142 -> V_78 = V_201 ;
break;
case 0x03 :
V_142 -> V_78 = V_79 ;
break;
default:
F_120 ( V_142 ) ;
return;
}
switch ( V_256 -> V_178 ) {
case V_188 :
V_142 -> V_189 = F_108 ;
V_142 -> V_65 . V_187 = V_188 ;
break;
case V_202 :
V_142 -> V_189 = F_88 ;
V_142 -> V_65 . V_187 = V_202 ;
break;
default:
F_120 ( V_142 ) ;
F_10 (KERN_WARNING PFX L_60 ,
ipmi_data->addr_space) ;
return;
}
V_142 -> V_65 . V_149 = V_256 -> V_253 ;
V_142 -> V_65 . V_150 = V_256 -> V_147 ;
if ( ! V_142 -> V_65 . V_150 )
V_142 -> V_65 . V_150 = V_190 ;
V_142 -> V_65 . V_155 = V_190 ;
V_142 -> V_65 . V_152 = 0 ;
V_142 -> V_191 = V_256 -> V_191 ;
V_142 -> V_47 = V_256 -> V_47 ;
if ( V_142 -> V_47 )
V_142 -> V_134 = F_71 ;
F_133 ( L_61 ,
( V_142 -> V_65 . V_187 == V_202 ) ? L_50 : L_51 ,
V_142 -> V_65 . V_149 , V_142 -> V_65 . V_155 , V_142 -> V_65 . V_150 ,
V_142 -> V_47 ) ;
if ( F_119 ( V_142 ) )
F_120 ( V_142 ) ;
}
static void F_150 ( void )
{
const struct V_258 * V_74 = NULL ;
struct V_251 V_12 ;
int V_15 ;
while ( ( V_74 = F_151 ( V_259 , NULL , V_74 ) ) ) {
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_15 = F_148 ( ( const struct V_249 * ) V_74 -> V_260 ,
& V_12 ) ;
if ( ! V_15 )
F_149 ( & V_12 ) ;
}
}
static void F_152 ( struct V_4 * V_142 )
{
struct V_261 * V_262 = V_142 -> V_263 ;
F_153 ( V_262 ) ;
}
static int F_154 ( struct V_4 * V_142 )
{
if ( V_142 -> V_78 == V_200 ) {
unsigned char V_212 ;
int V_150 ;
V_142 -> V_65 . V_155 = V_264 ;
V_142 -> V_65 . V_152 = 0 ;
V_142 -> V_154 = 2 ;
V_142 -> V_27 = & V_265 ;
for ( V_150 = V_190 ; V_150 <= 16 ; ) {
V_142 -> V_65 . V_150 = V_150 ;
if ( V_142 -> V_189 ( V_142 ) ) {
F_141 ( V_142 -> V_74 ,
L_62 ) ;
return V_190 ;
}
V_142 -> V_65 . V_69 ( & V_142 -> V_65 , 1 , 0x10 ) ;
V_212 = V_142 -> V_65 . V_66 ( & V_142 -> V_65 , 1 ) ;
V_142 -> V_157 ( V_142 ) ;
if ( V_212 )
return V_150 ;
V_150 *= 4 ;
}
}
return V_190 ;
}
static int F_155 ( struct V_261 * V_262 ,
const struct V_266 * V_267 )
{
int V_15 ;
int V_268 = V_262 -> V_269 & V_270 ;
struct V_4 * V_142 ;
V_142 = F_114 () ;
if ( ! V_142 )
return - V_181 ;
V_142 -> V_140 = V_271 ;
F_73 ( & V_262 -> V_74 , L_63 ) ;
switch ( V_268 ) {
case V_272 :
V_142 -> V_78 = V_201 ;
break;
case V_273 :
V_142 -> V_78 = V_200 ;
break;
case V_274 :
V_142 -> V_78 = V_79 ;
break;
default:
F_120 ( V_142 ) ;
F_73 ( & V_262 -> V_74 , L_64 , V_268 ) ;
return - V_181 ;
}
V_15 = F_156 ( V_262 ) ;
if ( V_15 ) {
F_141 ( & V_262 -> V_74 , L_65 ) ;
F_120 ( V_142 ) ;
return V_15 ;
}
V_142 -> V_275 = F_152 ;
V_142 -> V_263 = V_262 ;
if ( F_157 ( V_262 , 0 ) & V_246 ) {
V_142 -> V_189 = F_88 ;
V_142 -> V_65 . V_187 = V_202 ;
} else {
V_142 -> V_189 = F_108 ;
V_142 -> V_65 . V_187 = V_188 ;
}
V_142 -> V_65 . V_149 = F_158 ( V_262 , 0 ) ;
V_142 -> V_65 . V_150 = F_154 ( V_142 ) ;
V_142 -> V_65 . V_155 = V_264 ;
V_142 -> V_65 . V_152 = 0 ;
V_142 -> V_47 = V_262 -> V_47 ;
if ( V_142 -> V_47 )
V_142 -> V_134 = F_71 ;
V_142 -> V_74 = & V_262 -> V_74 ;
F_159 ( V_262 , V_142 ) ;
F_73 ( & V_262 -> V_74 , L_57 ,
& V_262 -> V_238 [ 0 ] , V_142 -> V_65 . V_155 , V_142 -> V_65 . V_150 ,
V_142 -> V_47 ) ;
V_15 = F_119 ( V_142 ) ;
if ( V_15 ) {
F_120 ( V_142 ) ;
F_153 ( V_262 ) ;
}
return V_15 ;
}
static void F_160 ( struct V_261 * V_262 )
{
struct V_4 * V_142 = F_161 ( V_262 ) ;
F_122 ( V_142 ) ;
F_153 ( V_262 ) ;
}
static int F_162 ( struct V_276 * V_74 )
{
#ifdef F_163
const struct V_277 * V_278 ;
struct V_4 * V_142 ;
struct V_238 V_238 ;
const T_7 * V_155 , * V_150 , * V_152 ;
struct V_279 * V_280 = V_74 -> V_74 . V_281 ;
int V_195 ;
int V_282 ;
F_73 ( & V_74 -> V_74 , L_66 ) ;
V_278 = F_164 ( V_283 , & V_74 -> V_74 ) ;
if ( ! V_278 )
return - V_158 ;
if ( ! F_165 ( V_280 ) )
return - V_158 ;
V_195 = F_166 ( V_280 , 0 , & V_238 ) ;
if ( V_195 ) {
F_28 ( & V_74 -> V_74 , V_284 L_67 ) ;
return V_195 ;
}
V_155 = F_167 ( V_280 , L_68 , & V_282 ) ;
if ( V_155 && V_282 != 4 ) {
F_28 ( & V_74 -> V_74 , V_284 L_69 ) ;
return - V_158 ;
}
V_150 = F_167 ( V_280 , L_70 , & V_282 ) ;
if ( V_150 && V_282 != 4 ) {
F_28 ( & V_74 -> V_74 , V_284 L_71 ) ;
return - V_158 ;
}
V_152 = F_167 ( V_280 , L_72 , & V_282 ) ;
if ( V_152 && V_282 != 4 ) {
F_28 ( & V_74 -> V_74 , V_284 L_73 ) ;
return - V_158 ;
}
V_142 = F_114 () ;
if ( ! V_142 ) {
F_141 ( & V_74 -> V_74 ,
L_74 ) ;
return - V_181 ;
}
V_142 -> V_78 = (enum V_78 ) V_278 -> V_12 ;
V_142 -> V_140 = V_285 ;
V_142 -> V_134 = F_71 ;
if ( V_238 . V_99 & V_246 ) {
V_142 -> V_189 = F_88 ;
V_142 -> V_65 . V_187 = V_202 ;
} else {
V_142 -> V_189 = F_108 ;
V_142 -> V_65 . V_187 = V_188 ;
}
V_142 -> V_65 . V_149 = V_238 . V_248 ;
V_142 -> V_65 . V_155 = V_155 ? F_168 ( V_155 ) : V_264 ;
V_142 -> V_65 . V_150 = V_150 ? F_168 ( V_150 ) : V_190 ;
V_142 -> V_65 . V_152 = V_152 ? F_168 ( V_152 ) : 0 ;
V_142 -> V_47 = F_169 ( V_74 -> V_74 . V_281 , 0 ) ;
V_142 -> V_74 = & V_74 -> V_74 ;
F_170 ( & V_74 -> V_74 , L_75 ,
V_142 -> V_65 . V_149 , V_142 -> V_65 . V_155 , V_142 -> V_65 . V_150 ,
V_142 -> V_47 ) ;
F_171 ( & V_74 -> V_74 , V_142 ) ;
V_195 = F_119 ( V_142 ) ;
if ( V_195 ) {
F_120 ( V_142 ) ;
return V_195 ;
}
#endif
return 0 ;
}
static int F_172 ( struct V_276 * V_74 )
{
#ifdef F_163
F_122 ( F_173 ( & V_74 -> V_74 ) ) ;
#endif
return 0 ;
}
static int F_174 ( struct V_286 * V_74 )
{
struct V_4 * V_142 ;
int V_15 ;
V_142 = F_114 () ;
if ( ! V_142 ) {
F_141 ( & V_74 -> V_74 ,
L_76 ) ;
return - V_181 ;
}
V_142 -> V_78 = V_200 ;
V_142 -> V_140 = V_285 ;
V_142 -> V_189 = F_108 ;
V_142 -> V_65 . V_187 = V_188 ;
V_142 -> V_65 . V_149 = V_74 -> V_287 . V_248 ;
V_142 -> V_65 . V_155 = 1 ;
V_142 -> V_65 . V_150 = 1 ;
V_142 -> V_65 . V_152 = 0 ;
V_142 -> V_47 = 0 ;
V_142 -> V_134 = NULL ;
V_142 -> V_74 = & V_74 -> V_74 ;
F_170 ( & V_74 -> V_74 , L_77 , V_142 -> V_65 . V_149 ) ;
F_171 ( & V_74 -> V_74 , V_142 ) ;
V_15 = F_119 ( V_142 ) ;
if ( V_15 ) {
F_120 ( V_142 ) ;
return V_15 ;
}
return 0 ;
}
static int F_175 ( struct V_286 * V_74 )
{
F_122 ( F_173 ( & V_74 -> V_74 ) ) ;
return 0 ;
}
static int F_176 ( struct V_4 * V_4 )
{
enum V_14 V_107 ;
V_107 = V_4 -> V_27 -> V_84 ( V_4 -> V_29 , 0 ) ;
for (; ; ) {
if ( V_107 == V_113 ||
V_107 == V_288 ) {
F_177 ( 1 ) ;
V_107 = V_4 -> V_27 -> V_84 (
V_4 -> V_29 , F_178 ( 1 ) ) ;
} else if ( V_107 == V_25 ) {
V_107 = V_4 -> V_27 -> V_84 (
V_4 -> V_29 , 0 ) ;
} else
break;
}
if ( V_107 == V_87 )
return - V_156 ;
return 0 ;
}
static int F_179 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 2 ] ;
unsigned char * V_289 ;
unsigned long V_290 ;
int V_15 = 0 ;
V_289 = F_180 ( V_71 , V_170 ) ;
if ( ! V_289 )
return - V_181 ;
V_6 [ 0 ] = V_31 << 2 ;
V_6 [ 1 ] = V_291 ;
V_4 -> V_27 -> V_28 ( V_4 -> V_29 , V_6 , 2 ) ;
V_15 = F_176 ( V_4 ) ;
if ( V_15 )
goto V_26;
V_290 = V_4 -> V_27 -> V_70 ( V_4 -> V_29 ,
V_289 , V_71 ) ;
V_15 = F_181 ( V_289 , V_290 , & V_4 -> V_292 ) ;
V_26:
F_120 ( V_289 ) ;
return V_15 ;
}
static int F_182 ( struct V_4 * V_4 )
{
unsigned char V_6 [ 3 ] ;
unsigned char * V_289 ;
unsigned long V_290 ;
int V_15 = 0 ;
V_289 = F_180 ( V_71 , V_170 ) ;
if ( ! V_289 )
return - V_181 ;
V_6 [ 0 ] = V_31 << 2 ;
V_6 [ 1 ] = V_32 ;
V_4 -> V_27 -> V_28 ( V_4 -> V_29 , V_6 , 2 ) ;
V_15 = F_176 ( V_4 ) ;
if ( V_15 ) {
F_10 (KERN_WARNING PFX L_78
L_79
L_80 ) ;
goto V_26;
}
V_290 = V_4 -> V_27 -> V_70 ( V_4 -> V_29 ,
V_289 , V_71 ) ;
if ( V_290 < 4 ||
V_289 [ 0 ] != ( V_31 | 1 ) << 2 ||
V_289 [ 1 ] != V_32 ||
V_289 [ 2 ] != 0 ) {
F_10 (KERN_WARNING PFX L_81
L_82 ) ;
V_15 = - V_158 ;
goto V_26;
}
if ( V_289 [ 3 ] & V_61 ) {
V_4 -> V_60 = true ;
goto V_26;
}
V_6 [ 0 ] = V_31 << 2 ;
V_6 [ 1 ] = V_81 ;
V_6 [ 2 ] = V_289 [ 3 ] | V_61 ;
V_4 -> V_27 -> V_28 ( V_4 -> V_29 , V_6 , 3 ) ;
V_15 = F_176 ( V_4 ) ;
if ( V_15 ) {
F_10 (KERN_WARNING PFX L_83
L_84
L_80 ) ;
goto V_26;
}
V_290 = V_4 -> V_27 -> V_70 ( V_4 -> V_29 ,
V_289 , V_71 ) ;
if ( V_290 < 3 ||
V_289 [ 0 ] != ( V_31 | 1 ) << 2 ||
V_289 [ 1 ] != V_81 ) {
F_10 (KERN_WARNING PFX L_85
L_86 ) ;
V_15 = - V_158 ;
goto V_26;
}
if ( V_289 [ 2 ] != 0 )
V_15 = - V_293 ;
else
V_4 -> V_60 = true ;
V_26:
F_120 ( V_289 ) ;
return V_15 ;
}
static int F_183 ( struct V_294 * V_295 , void * V_162 )
{
struct V_4 * V_138 = V_295 -> V_296 ;
return F_184 ( V_295 , L_87 , V_297 [ V_138 -> V_78 ] ) ;
}
static int F_185 ( struct V_298 * V_298 , struct V_299 * V_299 )
{
return F_186 ( V_299 , F_183 , F_187 ( V_298 ) ) ;
}
static int F_188 ( struct V_294 * V_295 , void * V_162 )
{
struct V_4 * V_138 = V_295 -> V_296 ;
F_184 ( V_295 , L_88 ,
V_138 -> V_47 && ! V_138 -> V_48 ) ;
F_184 ( V_295 , L_89 ,
F_189 ( V_138 , V_129 ) ) ;
F_184 ( V_295 , L_90 ,
F_189 ( V_138 , V_127 ) ) ;
F_184 ( V_295 , L_91 ,
F_189 ( V_138 , V_93 ) ) ;
F_184 ( V_295 , L_92 ,
F_189 ( V_138 , V_130 ) ) ;
F_184 ( V_295 , L_93 ,
F_189 ( V_138 , V_91 ) ) ;
F_184 ( V_295 , L_94 ,
F_189 ( V_138 , V_300 ) ) ;
F_184 ( V_295 , L_95 ,
F_189 ( V_138 , V_88 ) ) ;
F_184 ( V_295 , L_96 ,
F_189 ( V_138 , V_86 ) ) ;
F_184 ( V_295 , L_97 ,
F_189 ( V_138 , V_76 ) ) ;
F_184 ( V_295 , L_98 ,
F_189 ( V_138 , V_52 ) ) ;
F_184 ( V_295 , L_99 ,
F_189 ( V_138 , V_77 ) ) ;
return 0 ;
}
static int F_190 ( struct V_298 * V_298 , struct V_299 * V_299 )
{
return F_186 ( V_299 , F_188 , F_187 ( V_298 ) ) ;
}
static int F_191 ( struct V_294 * V_295 , void * V_162 )
{
struct V_4 * V_138 = V_295 -> V_296 ;
return F_184 ( V_295 ,
L_100 ,
V_297 [ V_138 -> V_78 ] ,
V_301 [ V_138 -> V_65 . V_187 ] ,
V_138 -> V_65 . V_149 ,
V_138 -> V_65 . V_150 ,
V_138 -> V_65 . V_155 ,
V_138 -> V_65 . V_152 ,
V_138 -> V_47 ,
V_138 -> V_191 ) ;
}
static int F_192 ( struct V_298 * V_298 , struct V_299 * V_299 )
{
return F_186 ( V_299 , F_191 , F_187 ( V_298 ) ) ;
}
static int F_193 ( struct V_4 * V_4 )
{
V_4 -> V_51 = ( ( V_4 -> V_51 & ~ V_55 ) |
V_53 ) ;
return 1 ;
}
static void F_194 ( struct V_4 * V_4 )
{
struct V_302 * V_303 = & V_4 -> V_292 ;
if ( V_303 -> V_304 == V_305 ) {
if ( V_303 -> V_292 == V_306 &&
V_303 -> V_307 == V_308 &&
V_303 -> V_309 == V_310 ) {
V_4 -> V_56 =
F_193 ;
} else if ( F_195 ( V_303 ) < 1 ||
( F_195 ( V_303 ) == 1 &&
F_196 ( V_303 ) < 5 ) ) {
V_4 -> V_56 =
F_193 ;
}
}
}
static void F_197 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_9 ;
V_6 -> V_11 [ 0 ] = V_6 -> V_12 [ 0 ] | 4 ;
V_6 -> V_11 [ 1 ] = V_6 -> V_12 [ 1 ] ;
V_6 -> V_11 [ 2 ] = V_311 ;
V_6 -> V_13 = 3 ;
V_4 -> V_9 = NULL ;
F_3 ( V_4 , V_6 ) ;
}
static int F_198 ( struct V_1 * V_312 ,
unsigned long V_313 ,
void * V_314 )
{
struct V_4 * V_4 = V_314 ;
unsigned char * V_12 = V_4 -> V_9 -> V_12 ;
unsigned int V_315 = V_4 -> V_9 -> V_30 ;
if ( V_315 >= 8 &&
( V_12 [ 0 ] >> 2 ) == V_316 &&
V_12 [ 1 ] == V_317 &&
V_12 [ 7 ] == 0x3A ) {
F_197 ( V_4 ) ;
return V_318 ;
}
return V_319 ;
}
static void
F_199 ( struct V_4 * V_4 )
{
struct V_302 * V_303 = & V_4 -> V_292 ;
if ( V_303 -> V_304 == V_305 &&
V_4 -> V_78 == V_79 )
F_1 ( & V_320 ) ;
}
static void F_200 ( struct V_4 * V_4 )
{
F_194 ( V_4 ) ;
}
static void F_201 ( struct V_4 * V_4 )
{
F_199 ( V_4 ) ;
}
static inline void F_202 ( struct V_4 * V_4 )
{
if ( V_4 -> V_96 != NULL )
F_203 ( V_4 -> V_96 ) ;
if ( V_4 -> V_46 )
F_204 ( & V_4 -> V_45 ) ;
}
static void F_205 ( void )
{
struct V_4 * V_142 ;
int V_167 ;
for ( V_167 = 0 ; ; V_167 ++ ) {
if ( ! V_321 [ V_167 ] . V_322 )
break;
#ifdef F_206
if ( F_207 ( V_321 [ V_167 ] . V_322 ) )
continue;
#endif
V_142 = F_114 () ;
if ( ! V_142 )
return;
V_142 -> V_140 = V_323 ;
V_142 -> V_78 = V_321 [ V_167 ] . type ;
V_142 -> V_189 = F_88 ;
V_142 -> V_65 . V_149 = V_321 [ V_167 ] . V_322 ;
V_142 -> V_65 . V_187 = V_202 ;
V_142 -> V_65 . V_148 = NULL ;
V_142 -> V_65 . V_150 = V_190 ;
V_142 -> V_65 . V_155 = V_190 ;
V_142 -> V_65 . V_152 = 0 ;
if ( F_119 ( V_142 ) == 0 ) {
if ( ( F_121 ( V_142 ) ) == 0 ) {
F_10 (KERN_INFO PFX L_101
L_102 ,
si_to_str[info->si_type],
addr_space_to_str[info->io.addr_type],
info->io.addr_data) ;
} else
F_122 ( V_142 ) ;
} else {
F_120 ( V_142 ) ;
}
}
}
static int F_208 ( struct V_4 * V_142 )
{
struct V_4 * V_192 ;
F_209 (e, &smi_infos, link) {
if ( V_192 -> V_65 . V_187 != V_142 -> V_65 . V_187 )
continue;
if ( V_192 -> V_65 . V_149 == V_142 -> V_65 . V_149 )
return 0 ;
}
return 1 ;
}
static int F_119 ( struct V_4 * V_133 )
{
int V_15 = 0 ;
F_10 (KERN_INFO PFX L_103 ,
ipmi_addr_src_to_str(new_smi->addr_source),
si_to_str[new_smi->si_type]) ;
F_123 ( & V_194 ) ;
if ( ! F_208 ( V_133 ) ) {
F_10 ( V_324 L_104 ) ;
V_15 = - V_325 ;
goto V_326;
}
F_10 ( V_324 L_105 ) ;
V_133 -> V_7 = NULL ;
V_133 -> V_29 = NULL ;
V_133 -> V_27 = NULL ;
F_210 ( & V_133 -> V_327 , & V_328 ) ;
V_326:
F_125 ( & V_194 ) ;
return V_15 ;
}
static int F_121 ( struct V_4 * V_133 )
{
int V_15 = 0 ;
int V_167 ;
F_10 (KERN_INFO PFX L_106
L_107
L_108 ,
ipmi_addr_src_to_str(new_smi->addr_source),
si_to_str[new_smi->si_type],
addr_space_to_str[new_smi->io.addr_type],
new_smi->io.addr_data,
new_smi->slave_addr, new_smi->irq) ;
switch ( V_133 -> V_78 ) {
case V_200 :
V_133 -> V_27 = & V_265 ;
break;
case V_201 :
V_133 -> V_27 = & V_329 ;
break;
case V_79 :
V_133 -> V_27 = & V_330 ;
break;
default:
V_15 = - V_159 ;
goto V_326;
}
V_133 -> V_29 = F_180 ( V_133 -> V_27 -> V_315 () , V_170 ) ;
if ( ! V_133 -> V_29 ) {
F_10 (KERN_ERR PFX
L_109 ) ;
V_15 = - V_181 ;
goto V_326;
}
V_133 -> V_154 = V_133 -> V_27 -> V_331 ( V_133 -> V_29 ,
& V_133 -> V_65 ) ;
V_15 = V_133 -> V_189 ( V_133 ) ;
if ( V_15 ) {
F_10 (KERN_ERR PFX L_110 ) ;
goto V_326;
}
if ( V_133 -> V_27 -> V_332 ( V_133 -> V_29 ) ) {
if ( V_133 -> V_140 )
F_10 (KERN_INFO PFX L_111 ) ;
V_15 = - V_156 ;
goto V_326;
}
V_15 = F_179 ( V_133 ) ;
if ( V_15 ) {
if ( V_133 -> V_140 )
F_10 (KERN_INFO PFX L_112
L_113 ) ;
goto V_326;
}
F_200 ( V_133 ) ;
F_201 ( V_133 ) ;
V_133 -> V_18 = NULL ;
V_133 -> V_9 = NULL ;
F_32 ( & V_133 -> V_94 , 0 ) ;
V_133 -> V_100 = false ;
for ( V_167 = 0 ; V_167 < V_333 ; V_167 ++ )
F_32 ( & V_133 -> V_334 [ V_167 ] , 0 ) ;
V_133 -> V_48 = true ;
F_32 ( & V_133 -> V_119 , 0 ) ;
V_133 -> V_110 = V_335 ;
V_335 ++ ;
V_15 = F_182 ( V_133 ) ;
if ( V_15 == 0 )
V_133 -> V_121 = true ;
F_13 ( V_133 ) ;
if ( V_133 -> V_47 ) {
V_133 -> V_48 = false ;
F_32 ( & V_133 -> V_94 , 1 ) ;
}
if ( ! V_133 -> V_74 ) {
V_133 -> V_262 = F_211 ( L_114 ,
V_133 -> V_110 ) ;
if ( ! V_133 -> V_262 ) {
F_10 (KERN_ERR PFX
L_115 ) ;
goto V_326;
}
V_133 -> V_74 = & V_133 -> V_262 -> V_74 ;
V_133 -> V_74 -> V_336 = & V_337 . V_336 ;
V_15 = F_212 ( V_133 -> V_262 ) ;
if ( V_15 ) {
F_10 (KERN_ERR PFX
L_116
L_117 ,
rv) ;
goto V_326;
}
V_133 -> V_338 = true ;
}
V_15 = F_213 ( & V_27 ,
V_133 ,
& V_133 -> V_292 ,
V_133 -> V_74 ,
V_133 -> V_191 ) ;
if ( V_15 ) {
F_141 ( V_133 -> V_74 , L_118 ,
V_15 ) ;
goto V_339;
}
V_15 = F_214 ( V_133 -> V_7 , L_119 ,
& V_340 ,
V_133 ) ;
if ( V_15 ) {
F_141 ( V_133 -> V_74 , L_120 , V_15 ) ;
goto V_339;
}
V_15 = F_214 ( V_133 -> V_7 , L_121 ,
& V_341 ,
V_133 ) ;
if ( V_15 ) {
F_141 ( V_133 -> V_74 , L_120 , V_15 ) ;
goto V_339;
}
V_15 = F_214 ( V_133 -> V_7 , L_122 ,
& V_342 ,
V_133 ) ;
if ( V_15 ) {
F_141 ( V_133 -> V_74 , L_120 , V_15 ) ;
goto V_339;
}
F_73 ( V_133 -> V_74 , L_123 ,
V_297 [ V_133 -> V_78 ] ) ;
return 0 ;
V_339:
F_202 ( V_133 ) ;
V_326:
V_133 -> V_48 = true ;
if ( V_133 -> V_7 ) {
T_3 V_7 = V_133 -> V_7 ;
V_133 -> V_7 = NULL ;
F_215 ( V_7 ) ;
}
if ( V_133 -> V_145 ) {
V_133 -> V_145 ( V_133 ) ;
V_133 -> V_145 = NULL ;
}
F_216 () ;
if ( V_133 -> V_29 ) {
if ( V_133 -> V_27 )
V_133 -> V_27 -> V_343 ( V_133 -> V_29 ) ;
F_120 ( V_133 -> V_29 ) ;
V_133 -> V_29 = NULL ;
}
if ( V_133 -> V_275 ) {
V_133 -> V_275 ( V_133 ) ;
V_133 -> V_275 = NULL ;
}
if ( V_133 -> V_157 ) {
V_133 -> V_157 ( V_133 ) ;
V_133 -> V_157 = NULL ;
}
if ( V_133 -> V_338 ) {
F_217 ( V_133 -> V_262 ) ;
V_133 -> V_338 = false ;
}
return V_15 ;
}
static int F_218 ( void )
{
int V_167 ;
char * V_173 ;
int V_15 ;
struct V_4 * V_192 ;
enum V_344 type = V_345 ;
if ( V_346 )
return 0 ;
V_346 = 1 ;
if ( V_347 ) {
V_15 = F_219 ( & V_337 ) ;
if ( V_15 ) {
F_10 (KERN_ERR PFX L_124
L_125 , rv) ;
return V_15 ;
}
}
V_173 = V_348 ;
if ( * V_173 != '\0' ) {
for ( V_167 = 0 ; ( V_167 < V_196 ) && ( * V_173 != '\0' ) ; V_167 ++ ) {
V_78 [ V_167 ] = V_173 ;
V_173 = strchr ( V_173 , ',' ) ;
if ( V_173 ) {
* V_173 = '\0' ;
V_173 ++ ;
} else {
break;
}
}
}
F_10 ( V_349 L_126 ) ;
if ( ! F_126 () )
return 0 ;
#ifdef F_220
if ( V_350 ) {
V_15 = F_221 ( & V_351 ) ;
if ( V_15 )
F_10 (KERN_ERR PFX L_124
L_127 , rv) ;
else
V_352 = true ;
}
#endif
#ifdef F_222
if ( V_353 ) {
F_223 ( & V_354 ) ;
V_355 = true ;
}
#endif
#ifdef F_224
if ( V_356 )
F_150 () ;
#endif
#ifdef F_222
if ( V_353 )
F_134 () ;
#endif
#ifdef F_225
F_226 ( & V_357 ) ;
V_358 = true ;
V_359 = 0 ;
#endif
F_123 ( & V_194 ) ;
F_209 (e, &smi_infos, link) {
if ( V_192 -> V_47 && ( ! type || V_192 -> V_140 == type ) ) {
if ( ! F_121 ( V_192 ) ) {
type = V_192 -> V_140 ;
}
}
}
if ( type ) {
F_125 ( & V_194 ) ;
return 0 ;
}
F_209 (e, &smi_infos, link) {
if ( ! V_192 -> V_47 && ( ! type || V_192 -> V_140 == type ) ) {
if ( ! F_121 ( V_192 ) ) {
type = V_192 -> V_140 ;
}
}
}
F_125 ( & V_194 ) ;
if ( type )
return 0 ;
if ( V_359 ) {
F_123 ( & V_194 ) ;
if ( F_227 ( & V_328 ) ) {
F_125 ( & V_194 ) ;
F_205 () ;
} else
F_125 ( & V_194 ) ;
}
F_123 ( & V_194 ) ;
if ( V_360 && F_227 ( & V_328 ) ) {
F_125 ( & V_194 ) ;
F_228 () ;
F_10 (KERN_WARNING PFX
L_128 ) ;
return - V_156 ;
} else {
F_125 ( & V_194 ) ;
return 0 ;
}
}
static void F_122 ( struct V_4 * V_361 )
{
int V_15 = 0 ;
if ( ! V_361 )
return;
if ( V_361 -> V_7 ) {
T_3 V_7 = V_361 -> V_7 ;
V_361 -> V_7 = NULL ;
V_15 = F_215 ( V_7 ) ;
if ( V_15 ) {
F_229 ( V_284 L_129 ,
V_15 ) ;
}
}
if ( V_361 -> V_74 )
F_171 ( V_361 -> V_74 , NULL ) ;
F_230 ( & V_361 -> V_327 ) ;
if ( V_361 -> V_145 )
V_361 -> V_145 ( V_361 ) ;
F_202 ( V_361 ) ;
while ( V_361 -> V_9 || ( V_361 -> V_33 != V_49 ) ) {
F_54 ( V_361 ) ;
F_177 ( 1 ) ;
}
F_18 ( V_361 ) ;
while ( V_361 -> V_9 || ( V_361 -> V_33 != V_49 ) ) {
F_54 ( V_361 ) ;
F_177 ( 1 ) ;
}
if ( V_361 -> V_27 )
V_361 -> V_27 -> V_343 ( V_361 -> V_29 ) ;
F_120 ( V_361 -> V_29 ) ;
if ( V_361 -> V_275 )
V_361 -> V_275 ( V_361 ) ;
if ( V_361 -> V_157 )
V_361 -> V_157 ( V_361 ) ;
if ( V_361 -> V_338 )
F_217 ( V_361 -> V_262 ) ;
F_120 ( V_361 ) ;
}
static void F_228 ( void )
{
struct V_4 * V_192 , * V_193 ;
if ( ! V_346 )
return;
#ifdef F_220
if ( V_352 )
F_231 ( & V_351 ) ;
#endif
#ifdef F_222
if ( V_355 )
F_232 ( & V_354 ) ;
#endif
#ifdef F_225
if ( V_358 )
F_233 ( & V_357 ) ;
#endif
F_234 ( & V_337 ) ;
F_123 ( & V_194 ) ;
F_124 (e, tmp_e, &smi_infos, link)
F_122 ( V_192 ) ;
F_125 ( & V_194 ) ;
}
