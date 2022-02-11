void F_1 ( char * V_1 )
{
struct V_2 V_3 ;
F_2 ( & V_3 ) ;
F_3 ( L_1 , V_1 , ( long long ) V_3 . V_4 , V_3 . V_5 ) ;
}
static int F_4 ( struct V_6 * V_7 )
{
return F_5 ( & V_8 , V_7 ) ;
}
static void F_6 ( struct V_9 * V_9 ,
struct V_10 * V_1 )
{
if ( V_9 -> V_11 )
F_7 ( V_9 -> V_11 , V_1 ) ;
else
F_8 ( V_1 ) ;
}
static void F_9 ( struct V_9 * V_9 , int V_12 )
{
struct V_10 * V_1 = V_9 -> V_13 ;
if ( V_12 < 0 || V_12 > V_14 )
V_12 = V_14 ;
V_1 -> V_15 [ 0 ] = V_1 -> V_16 [ 0 ] | 4 ;
V_1 -> V_15 [ 1 ] = V_1 -> V_16 [ 1 ] ;
V_1 -> V_15 [ 2 ] = V_12 ;
V_1 -> V_17 = 3 ;
V_9 -> V_13 = NULL ;
F_6 ( V_9 , V_1 ) ;
}
static enum V_18 F_10 ( struct V_9 * V_9 )
{
int V_19 ;
if ( ! V_9 -> V_20 ) {
V_9 -> V_13 = NULL ;
V_19 = V_21 ;
} else {
int V_22 ;
V_9 -> V_13 = V_9 -> V_20 ;
V_9 -> V_20 = NULL ;
F_1 ( L_2 ) ;
V_22 = F_11 ( & V_8 ,
0 , V_9 ) ;
if ( V_22 & V_23 ) {
V_19 = V_24 ;
goto V_25;
}
V_22 = V_9 -> V_26 -> V_27 (
V_9 -> V_28 ,
V_9 -> V_13 -> V_16 ,
V_9 -> V_13 -> V_29 ) ;
if ( V_22 )
F_9 ( V_9 , V_22 ) ;
V_19 = V_24 ;
}
V_25:
return V_19 ;
}
static void F_12 ( struct V_9 * V_9 )
{
unsigned char V_1 [ 2 ] ;
V_1 [ 0 ] = ( V_30 << 2 ) ;
V_1 [ 1 ] = V_31 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 2 ) ;
V_9 -> V_32 = V_33 ;
}
static void F_13 ( struct V_9 * V_9 )
{
unsigned char V_1 [ 3 ] ;
V_1 [ 0 ] = ( V_30 << 2 ) ;
V_1 [ 1 ] = V_34 ;
V_1 [ 2 ] = V_35 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 3 ) ;
V_9 -> V_32 = V_36 ;
}
static void F_14 ( struct V_9 * V_9 )
{
V_9 -> V_13 -> V_16 [ 0 ] = ( V_30 << 2 ) ;
V_9 -> V_13 -> V_16 [ 1 ] = V_37 ;
V_9 -> V_13 -> V_29 = 2 ;
V_9 -> V_26 -> V_27 (
V_9 -> V_28 ,
V_9 -> V_13 -> V_16 ,
V_9 -> V_13 -> V_29 ) ;
V_9 -> V_32 = V_38 ;
}
static void F_15 ( struct V_9 * V_9 )
{
V_9 -> V_13 -> V_16 [ 0 ] = ( V_30 << 2 ) ;
V_9 -> V_13 -> V_16 [ 1 ] = V_39 ;
V_9 -> V_13 -> V_29 = 2 ;
V_9 -> V_26 -> V_27 (
V_9 -> V_28 ,
V_9 -> V_13 -> V_16 ,
V_9 -> V_13 -> V_29 ) ;
V_9 -> V_32 = V_40 ;
}
static void F_16 ( struct V_9 * V_9 , unsigned long V_41 )
{
V_9 -> V_42 = V_43 ;
F_17 ( & V_9 -> V_44 , V_41 ) ;
V_9 -> V_45 = true ;
}
static inline bool F_18 ( struct V_9 * V_9 )
{
if ( ( V_9 -> V_46 ) && ( ! V_9 -> V_47 ) ) {
V_9 -> V_47 = true ;
F_12 ( V_9 ) ;
return true ;
}
return false ;
}
static inline bool F_19 ( struct V_9 * V_9 )
{
if ( ( V_9 -> V_46 ) && ( V_9 -> V_47 ) ) {
V_9 -> V_47 = false ;
F_12 ( V_9 ) ;
return true ;
}
return false ;
}
static struct V_10 * F_20 ( struct V_9 * V_9 )
{
struct V_10 * V_1 ;
V_1 = F_21 () ;
if ( ! V_1 ) {
if ( ! F_18 ( V_9 ) )
V_9 -> V_32 = V_48 ;
} else if ( F_19 ( V_9 ) ) {
F_8 ( V_1 ) ;
V_1 = NULL ;
}
return V_1 ;
}
static void F_22 ( struct V_9 * V_9 )
{
V_49:
if ( V_9 -> V_50 & V_35 ) {
F_23 ( V_9 , V_51 ) ;
F_13 ( V_9 ) ;
V_9 -> V_50 &= ~ V_35 ;
if ( V_9 -> V_11 )
F_24 ( V_9 -> V_11 ) ;
} else if ( V_9 -> V_50 & V_52 ) {
V_9 -> V_13 = F_20 ( V_9 ) ;
if ( ! V_9 -> V_13 )
return;
F_14 ( V_9 ) ;
} else if ( V_9 -> V_50 & V_53 ) {
V_9 -> V_13 = F_20 ( V_9 ) ;
if ( ! V_9 -> V_13 )
return;
F_15 ( V_9 ) ;
} else if ( V_9 -> V_50 & V_54 &&
V_9 -> V_55 ) {
if ( V_9 -> V_55 ( V_9 ) )
goto V_49;
} else
V_9 -> V_32 = V_48 ;
}
static T_1 F_25 ( struct V_9 * V_9 , T_1 V_56 ,
bool * V_57 )
{
T_1 V_58 = 0 ;
if ( V_9 -> V_59 )
V_58 |= V_60 ;
if ( ( ( V_9 -> V_46 && ! V_9 -> V_47 ) ||
V_9 -> V_61 ) &&
! V_9 -> V_62 )
V_58 |= V_63 ;
if ( V_9 -> V_59 &&
V_9 -> V_46 && ! V_9 -> V_47 &&
! V_9 -> V_62 )
V_58 |= V_64 ;
* V_57 = V_58 & ( V_64 | V_63 ) ;
return V_58 ;
}
static void F_26 ( struct V_9 * V_9 , bool V_57 )
{
T_1 V_65 = V_9 -> V_66 . V_67 ( & V_9 -> V_66 , V_68 ) ;
V_65 &= V_69 ;
if ( ( bool ) V_65 == V_57 )
return;
if ( V_57 )
V_9 -> V_66 . V_70 ( & V_9 -> V_66 , V_68 ,
V_69 ) ;
else
V_9 -> V_66 . V_70 ( & V_9 -> V_66 , V_68 , 0 ) ;
}
static void F_27 ( struct V_9 * V_9 )
{
struct V_10 * V_1 ;
F_1 ( L_3 ) ;
switch ( V_9 -> V_32 ) {
case V_48 :
if ( ! V_9 -> V_13 )
break;
V_9 -> V_13 -> V_17
= V_9 -> V_26 -> V_71 (
V_9 -> V_28 ,
V_9 -> V_13 -> V_15 ,
V_72 ) ;
V_1 = V_9 -> V_13 ;
V_9 -> V_13 = NULL ;
F_6 ( V_9 , V_1 ) ;
break;
case V_73 :
{
unsigned char V_1 [ 4 ] ;
unsigned int V_74 ;
V_74 = V_9 -> V_26 -> V_71 ( V_9 -> V_28 , V_1 , 4 ) ;
if ( V_1 [ 2 ] != 0 ) {
V_9 -> V_32 = V_48 ;
} else if ( V_74 < 4 ) {
V_9 -> V_32 = V_48 ;
} else {
V_9 -> V_50 = V_1 [ 3 ] ;
F_22 ( V_9 ) ;
}
break;
}
case V_36 :
{
unsigned char V_1 [ 3 ] ;
V_9 -> V_26 -> V_71 ( V_9 -> V_28 , V_1 , 3 ) ;
if ( V_1 [ 2 ] != 0 ) {
F_28 ( V_9 -> V_75 ,
L_4 , V_1 [ 2 ] ) ;
}
V_9 -> V_32 = V_48 ;
break;
}
case V_40 :
{
V_9 -> V_13 -> V_17
= V_9 -> V_26 -> V_71 (
V_9 -> V_28 ,
V_9 -> V_13 -> V_15 ,
V_72 ) ;
V_1 = V_9 -> V_13 ;
V_9 -> V_13 = NULL ;
if ( V_1 -> V_15 [ 2 ] != 0 ) {
V_1 -> V_76 ( V_1 ) ;
V_9 -> V_50 &= ~ V_53 ;
F_22 ( V_9 ) ;
} else {
F_23 ( V_9 , V_77 ) ;
F_22 ( V_9 ) ;
F_6 ( V_9 , V_1 ) ;
}
break;
}
case V_38 :
{
V_9 -> V_13 -> V_17
= V_9 -> V_26 -> V_71 (
V_9 -> V_28 ,
V_9 -> V_13 -> V_15 ,
V_72 ) ;
V_1 = V_9 -> V_13 ;
V_9 -> V_13 = NULL ;
if ( V_1 -> V_15 [ 2 ] != 0 ) {
V_1 -> V_76 ( V_1 ) ;
V_9 -> V_50 &= ~ V_52 ;
F_22 ( V_9 ) ;
} else {
F_23 ( V_9 , V_78 ) ;
F_22 ( V_9 ) ;
F_6 ( V_9 , V_1 ) ;
}
break;
}
case V_33 :
{
unsigned char V_1 [ 4 ] ;
T_1 V_58 ;
bool V_57 ;
V_9 -> V_26 -> V_71 ( V_9 -> V_28 , V_1 , 4 ) ;
if ( V_1 [ 2 ] != 0 ) {
F_28 ( V_9 -> V_75 ,
L_5 , V_1 [ 2 ] ) ;
F_28 ( V_9 -> V_75 ,
L_6 ) ;
V_9 -> V_32 = V_48 ;
break;
}
V_58 = F_25 ( V_9 , 0 , & V_57 ) ;
if ( V_9 -> V_79 == V_80 )
F_26 ( V_9 , V_57 ) ;
if ( V_58 != ( V_1 [ 3 ] & V_81 ) ) {
V_1 [ 0 ] = ( V_30 << 2 ) ;
V_1 [ 1 ] = V_82 ;
V_1 [ 2 ] = V_58 | ( V_1 [ 3 ] & ~ V_81 ) ;
V_9 -> V_26 -> V_27 (
V_9 -> V_28 , V_1 , 3 ) ;
V_9 -> V_32 = V_83 ;
} else if ( V_9 -> V_59 ) {
V_9 -> V_13 = F_21 () ;
if ( ! V_9 -> V_13 ) {
V_9 -> V_32 = V_48 ;
break;
}
F_14 ( V_9 ) ;
} else {
V_9 -> V_32 = V_48 ;
}
break;
}
case V_83 :
{
unsigned char V_1 [ 4 ] ;
V_9 -> V_26 -> V_71 ( V_9 -> V_28 , V_1 , 4 ) ;
if ( V_1 [ 2 ] != 0 )
F_28 ( V_9 -> V_75 ,
L_7 ,
V_1 [ 2 ] ) ;
if ( V_9 -> V_59 ) {
V_9 -> V_13 = F_21 () ;
if ( ! V_9 -> V_13 ) {
V_9 -> V_32 = V_48 ;
break;
}
F_14 ( V_9 ) ;
} else {
V_9 -> V_32 = V_48 ;
}
break;
}
}
}
static enum V_18 F_29 ( struct V_9 * V_9 ,
int time )
{
enum V_18 V_18 ;
V_84:
V_18 = V_9 -> V_26 -> V_85 ( V_9 -> V_28 , time ) ;
time = 0 ;
while ( V_18 == V_24 )
V_18 = V_9 -> V_26 -> V_85 ( V_9 -> V_28 , 0 ) ;
if ( V_18 == V_86 ) {
F_23 ( V_9 , V_87 ) ;
F_27 ( V_9 ) ;
V_18 = V_9 -> V_26 -> V_85 ( V_9 -> V_28 , 0 ) ;
} else if ( V_18 == V_88 ) {
F_23 ( V_9 , V_89 ) ;
V_9 -> V_32 = V_48 ;
if ( V_9 -> V_13 != NULL ) {
F_9 ( V_9 , V_14 ) ;
}
V_18 = V_9 -> V_26 -> V_85 ( V_9 -> V_28 , 0 ) ;
}
if ( F_30 ( V_9 -> V_11 ) &&
( V_18 == V_90 || V_9 -> V_91 ) ) {
unsigned char V_1 [ 2 ] ;
if ( V_9 -> V_32 != V_48 ) {
V_9 -> V_91 = true ;
} else {
V_9 -> V_91 = false ;
F_23 ( V_9 , V_92 ) ;
V_1 [ 0 ] = ( V_30 << 2 ) ;
V_1 [ 1 ] = V_93 ;
V_9 -> V_26 -> V_27 (
V_9 -> V_28 , V_1 , 2 ) ;
V_9 -> V_32 = V_73 ;
goto V_84;
}
}
if ( V_18 == V_21 ) {
F_23 ( V_9 , V_94 ) ;
V_18 = F_10 ( V_9 ) ;
if ( V_18 != V_21 )
goto V_84;
}
if ( ( V_18 == V_21 )
&& ( F_31 ( & V_9 -> V_95 ) ) ) {
F_32 ( & V_9 -> V_95 , 0 ) ;
if ( V_9 -> V_59 || V_9 -> V_46 ) {
F_12 ( V_9 ) ;
} else {
V_9 -> V_13 = F_20 ( V_9 ) ;
if ( ! V_9 -> V_13 )
goto V_25;
F_15 ( V_9 ) ;
}
goto V_84;
}
V_25:
return V_18 ;
}
static void F_33 ( struct V_9 * V_9 )
{
if ( V_9 -> V_32 == V_48 && V_9 -> V_13 == NULL ) {
F_16 ( V_9 , V_43 + V_96 ) ;
if ( V_9 -> V_97 )
F_34 ( V_9 -> V_97 ) ;
F_10 ( V_9 ) ;
F_29 ( V_9 , 0 ) ;
}
}
static void F_35 ( void * V_98 )
{
struct V_9 * V_9 = V_98 ;
enum V_18 V_99 ;
V_99 = F_29 ( V_9 , 0 ) ;
while ( V_99 != V_21 ) {
F_36 ( V_100 ) ;
V_99 = F_29 ( V_9 , V_100 ) ;
}
}
static void F_37 ( void * V_98 ,
struct V_10 * V_1 )
{
struct V_9 * V_9 = V_98 ;
unsigned long V_101 ;
F_1 ( L_8 ) ;
if ( V_9 -> V_102 ) {
V_9 -> V_20 = V_1 ;
return;
}
F_38 ( & V_9 -> V_103 , V_101 ) ;
F_39 ( V_9 -> V_20 ) ;
V_9 -> V_20 = V_1 ;
F_33 ( V_9 ) ;
F_40 ( & V_9 -> V_103 , V_101 ) ;
}
static void F_41 ( void * V_98 , bool V_104 )
{
struct V_9 * V_9 = V_98 ;
V_9 -> V_102 = V_104 ;
if ( V_104 )
F_35 ( V_9 ) ;
}
static inline void F_42 ( struct V_2 * V_105 )
{
V_105 -> V_5 = - 1 ;
}
static inline int F_43 ( struct V_2 * V_105 )
{
return V_105 -> V_5 != - 1 ;
}
static inline int F_44 ( enum V_18 V_106 ,
const struct V_9 * V_9 ,
struct V_2 * V_107 )
{
unsigned int V_108 = 0 ;
if ( V_9 -> V_109 < V_110 )
V_108 = V_111 [ V_9 -> V_109 ] ;
if ( V_108 == 0 || V_106 != V_112 )
F_42 ( V_107 ) ;
else if ( ! F_43 ( V_107 ) ) {
F_2 ( V_107 ) ;
F_45 ( V_107 , V_108 * V_113 ) ;
} else {
struct V_2 V_114 ;
F_2 ( & V_114 ) ;
if ( F_46 ( F_47 ( & V_114 , V_107 ) > 0 ) ) {
F_42 ( V_107 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_48 ( void * V_16 )
{
struct V_9 * V_9 = V_16 ;
unsigned long V_101 ;
enum V_18 V_106 ;
struct V_2 V_107 ;
F_42 ( & V_107 ) ;
F_49 ( V_115 , V_116 ) ;
while ( ! F_50 () ) {
int V_117 ;
F_38 ( & ( V_9 -> V_103 ) , V_101 ) ;
V_106 = F_29 ( V_9 , 0 ) ;
if ( V_106 != V_21 && ! V_9 -> V_45 )
F_16 ( V_9 , V_43 + V_96 ) ;
F_40 ( & ( V_9 -> V_103 ) , V_101 ) ;
V_117 = F_44 ( V_106 , V_9 ,
& V_107 ) ;
if ( V_106 == V_24 )
;
else if ( V_106 == V_112 && V_117 )
F_51 () ;
else if ( V_106 == V_21 ) {
if ( F_31 ( & V_9 -> V_118 ) ) {
F_52 ( 100 ) ;
} else {
F_53 ( V_119 ) ;
F_51 () ;
}
} else
F_52 ( 1 ) ;
}
return 0 ;
}
static void F_54 ( void * V_98 )
{
struct V_9 * V_9 = V_98 ;
unsigned long V_101 = 0 ;
bool V_102 = V_9 -> V_102 ;
F_36 ( 10 ) ;
if ( ! V_102 )
F_38 ( & V_9 -> V_103 , V_101 ) ;
F_29 ( V_9 , 10 ) ;
if ( ! V_102 )
F_40 ( & V_9 -> V_103 , V_101 ) ;
}
static void F_55 ( void * V_98 )
{
struct V_9 * V_9 = V_98 ;
if ( ! V_9 -> V_120 )
return;
F_32 ( & V_9 -> V_95 , 1 ) ;
}
static void F_56 ( void * V_98 , bool V_121 )
{
struct V_9 * V_9 = V_98 ;
unsigned long V_101 ;
F_32 ( & V_9 -> V_118 , V_121 ) ;
F_38 ( & V_9 -> V_103 , V_101 ) ;
F_33 ( V_9 ) ;
F_40 ( & V_9 -> V_103 , V_101 ) ;
}
static void F_57 ( unsigned long V_16 )
{
struct V_9 * V_9 = (struct V_9 * ) V_16 ;
enum V_18 V_106 ;
unsigned long V_101 ;
unsigned long V_122 ;
long V_123 ;
long V_124 ;
F_38 ( & ( V_9 -> V_103 ) , V_101 ) ;
F_1 ( L_9 ) ;
V_122 = V_43 ;
V_123 = ( ( ( long ) V_122 - ( long ) V_9 -> V_42 )
* V_125 ) ;
V_106 = F_29 ( V_9 , V_123 ) ;
if ( ( V_9 -> V_46 ) && ( ! V_9 -> V_47 ) ) {
V_124 = V_43 + V_96 ;
F_23 ( V_9 , V_126 ) ;
goto V_127;
}
if ( V_106 == V_112 ) {
F_23 ( V_9 , V_128 ) ;
V_124 = V_43 + 1 ;
} else {
F_23 ( V_9 , V_126 ) ;
V_124 = V_43 + V_96 ;
}
V_127:
if ( V_106 != V_21 )
F_16 ( V_9 , V_124 ) ;
else
V_9 -> V_45 = false ;
F_40 ( & ( V_9 -> V_103 ) , V_101 ) ;
}
static T_2 F_58 ( int V_46 , void * V_16 )
{
struct V_9 * V_9 = V_16 ;
unsigned long V_101 ;
F_38 ( & ( V_9 -> V_103 ) , V_101 ) ;
F_23 ( V_9 , V_129 ) ;
F_1 ( L_10 ) ;
F_29 ( V_9 , 0 ) ;
F_40 ( & ( V_9 -> V_103 ) , V_101 ) ;
return V_130 ;
}
static T_2 F_59 ( int V_46 , void * V_16 )
{
struct V_9 * V_9 = V_16 ;
V_9 -> V_66 . V_70 ( & V_9 -> V_66 , V_68 ,
V_131
| V_69 ) ;
return F_58 ( V_46 , V_16 ) ;
}
static int F_60 ( void * V_98 ,
T_3 V_11 )
{
struct V_9 * V_132 = V_98 ;
int V_121 = 0 ;
V_132 -> V_11 = V_11 ;
if ( V_132 -> V_133 )
V_132 -> V_133 ( V_132 ) ;
F_61 ( & V_132 -> V_44 , F_57 , ( long ) V_132 ) ;
F_16 ( V_132 , V_43 + V_96 ) ;
if ( V_132 -> V_109 < V_134 )
V_121 = V_135 [ V_132 -> V_109 ] ;
else if ( ( V_132 -> V_79 != V_80 ) && ( ! V_132 -> V_46 ) )
V_121 = 1 ;
if ( V_121 ) {
V_132 -> V_97 = F_62 ( F_48 , V_132 ,
L_11 , V_132 -> V_109 ) ;
if ( F_63 ( V_132 -> V_97 ) ) {
F_64 ( V_132 -> V_75 , L_12
L_13
L_14 ,
F_65 ( V_132 -> V_97 ) ) ;
V_132 -> V_97 = NULL ;
}
}
return 0 ;
}
static int F_66 ( void * V_98 , struct V_136 * V_16 )
{
struct V_9 * V_137 = V_98 ;
V_16 -> V_138 = V_137 -> V_139 ;
V_16 -> V_75 = V_137 -> V_75 ;
V_16 -> V_140 = V_137 -> V_140 ;
F_67 ( V_137 -> V_75 ) ;
return 0 ;
}
static void F_68 ( void * V_98 , bool V_121 )
{
struct V_9 * V_9 = V_98 ;
if ( ! V_121 )
F_32 ( & V_9 -> V_95 , 0 ) ;
}
static void F_69 ( struct V_9 * V_141 )
{
if ( V_141 -> V_79 == V_80 )
V_141 -> V_66 . V_70 ( & V_141 -> V_66 , V_68 , 0 ) ;
F_70 ( V_141 -> V_46 , V_141 ) ;
}
static int F_71 ( struct V_9 * V_141 )
{
int V_19 ;
if ( ! V_141 -> V_46 )
return 0 ;
if ( V_141 -> V_79 == V_80 ) {
V_19 = F_72 ( V_141 -> V_46 ,
F_59 ,
V_142 ,
V_143 ,
V_141 ) ;
if ( ! V_19 )
V_141 -> V_66 . V_70 ( & V_141 -> V_66 , V_68 ,
V_69 ) ;
} else
V_19 = F_72 ( V_141 -> V_46 ,
F_58 ,
V_142 ,
V_143 ,
V_141 ) ;
if ( V_19 ) {
F_28 ( V_141 -> V_75 , L_15
L_16 ,
V_143 , V_141 -> V_46 ) ;
V_141 -> V_46 = 0 ;
} else {
V_141 -> V_144 = F_69 ;
F_73 ( V_141 -> V_75 , L_17 , V_141 -> V_46 ) ;
}
return V_19 ;
}
static unsigned char F_74 ( const struct V_145 * V_66 , unsigned int V_146 )
{
unsigned int V_147 = V_66 -> V_148 ;
return F_75 ( V_147 + ( V_146 * V_66 -> V_149 ) ) ;
}
static void F_76 ( const struct V_145 * V_66 , unsigned int V_146 ,
unsigned char V_150 )
{
unsigned int V_147 = V_66 -> V_148 ;
F_77 ( V_150 , V_147 + ( V_146 * V_66 -> V_149 ) ) ;
}
static unsigned char F_78 ( const struct V_145 * V_66 , unsigned int V_146 )
{
unsigned int V_147 = V_66 -> V_148 ;
return ( F_79 ( V_147 + ( V_146 * V_66 -> V_149 ) ) >> V_66 -> V_151 ) & 0xff ;
}
static void F_80 ( const struct V_145 * V_66 , unsigned int V_146 ,
unsigned char V_150 )
{
unsigned int V_147 = V_66 -> V_148 ;
F_81 ( V_150 << V_66 -> V_151 , V_147 + ( V_146 * V_66 -> V_149 ) ) ;
}
static unsigned char F_82 ( const struct V_145 * V_66 , unsigned int V_146 )
{
unsigned int V_147 = V_66 -> V_148 ;
return ( F_83 ( V_147 + ( V_146 * V_66 -> V_149 ) ) >> V_66 -> V_151 ) & 0xff ;
}
static void F_84 ( const struct V_145 * V_66 , unsigned int V_146 ,
unsigned char V_150 )
{
unsigned int V_147 = V_66 -> V_148 ;
F_85 ( V_150 << V_66 -> V_151 , V_147 + ( V_146 * V_66 -> V_149 ) ) ;
}
static void F_86 ( struct V_9 * V_141 )
{
unsigned int V_147 = V_141 -> V_66 . V_148 ;
int V_152 ;
if ( V_147 ) {
for ( V_152 = 0 ; V_152 < V_141 -> V_153 ; V_152 ++ )
F_87 ( V_147 + V_152 * V_141 -> V_66 . V_149 ,
V_141 -> V_66 . V_154 ) ;
}
}
static int F_88 ( struct V_9 * V_141 )
{
unsigned int V_147 = V_141 -> V_66 . V_148 ;
int V_152 ;
if ( ! V_147 )
return - V_155 ;
V_141 -> V_156 = F_86 ;
switch ( V_141 -> V_66 . V_154 ) {
case 1 :
V_141 -> V_66 . V_67 = F_74 ;
V_141 -> V_66 . V_70 = F_76 ;
break;
case 2 :
V_141 -> V_66 . V_67 = F_78 ;
V_141 -> V_66 . V_70 = F_80 ;
break;
case 4 :
V_141 -> V_66 . V_67 = F_82 ;
V_141 -> V_66 . V_70 = F_84 ;
break;
default:
F_28 ( V_141 -> V_75 , L_18 ,
V_141 -> V_66 . V_154 ) ;
return - V_157 ;
}
for ( V_152 = 0 ; V_152 < V_141 -> V_153 ; V_152 ++ ) {
if ( F_89 ( V_147 + V_152 * V_141 -> V_66 . V_149 ,
V_141 -> V_66 . V_154 , V_143 ) == NULL ) {
while ( V_152 -- ) {
F_87 ( V_147 + V_152 * V_141 -> V_66 . V_149 ,
V_141 -> V_66 . V_154 ) ;
}
return - V_158 ;
}
}
return 0 ;
}
static unsigned char F_90 ( const struct V_145 * V_66 ,
unsigned int V_146 )
{
return F_91 ( ( V_66 -> V_147 ) + ( V_146 * V_66 -> V_149 ) ) ;
}
static void F_92 ( const struct V_145 * V_66 , unsigned int V_146 ,
unsigned char V_150 )
{
F_93 ( V_150 , ( V_66 -> V_147 ) + ( V_146 * V_66 -> V_149 ) ) ;
}
static unsigned char F_94 ( const struct V_145 * V_66 ,
unsigned int V_146 )
{
return ( F_95 ( ( V_66 -> V_147 ) + ( V_146 * V_66 -> V_149 ) ) >> V_66 -> V_151 )
& 0xff ;
}
static void F_96 ( const struct V_145 * V_66 , unsigned int V_146 ,
unsigned char V_150 )
{
F_93 ( V_150 << V_66 -> V_151 , ( V_66 -> V_147 ) + ( V_146 * V_66 -> V_149 ) ) ;
}
static unsigned char F_97 ( const struct V_145 * V_66 ,
unsigned int V_146 )
{
return ( F_98 ( ( V_66 -> V_147 ) + ( V_146 * V_66 -> V_149 ) ) >> V_66 -> V_151 )
& 0xff ;
}
static void F_99 ( const struct V_145 * V_66 , unsigned int V_146 ,
unsigned char V_150 )
{
F_100 ( V_150 << V_66 -> V_151 , ( V_66 -> V_147 ) + ( V_146 * V_66 -> V_149 ) ) ;
}
static unsigned char F_101 ( const struct V_145 * V_66 , unsigned int V_146 )
{
return ( F_102 ( ( V_66 -> V_147 ) + ( V_146 * V_66 -> V_149 ) ) >> V_66 -> V_151 )
& 0xff ;
}
static void F_103 ( const struct V_145 * V_66 , unsigned int V_146 ,
unsigned char V_150 )
{
F_104 ( V_150 << V_66 -> V_151 , ( V_66 -> V_147 ) + ( V_146 * V_66 -> V_149 ) ) ;
}
static void F_105 ( struct V_9 * V_141 )
{
unsigned long V_147 = V_141 -> V_66 . V_148 ;
int V_159 ;
if ( V_141 -> V_66 . V_147 ) {
F_106 ( V_141 -> V_66 . V_147 ) ;
V_159 = ( ( V_141 -> V_153 * V_141 -> V_66 . V_149 )
- ( V_141 -> V_66 . V_149 - V_141 -> V_66 . V_154 ) ) ;
F_107 ( V_147 , V_159 ) ;
}
}
static int F_108 ( struct V_9 * V_141 )
{
unsigned long V_147 = V_141 -> V_66 . V_148 ;
int V_159 ;
if ( ! V_147 )
return - V_155 ;
V_141 -> V_156 = F_105 ;
switch ( V_141 -> V_66 . V_154 ) {
case 1 :
V_141 -> V_66 . V_67 = F_90 ;
V_141 -> V_66 . V_70 = F_92 ;
break;
case 2 :
V_141 -> V_66 . V_67 = F_94 ;
V_141 -> V_66 . V_70 = F_96 ;
break;
case 4 :
V_141 -> V_66 . V_67 = F_97 ;
V_141 -> V_66 . V_70 = F_99 ;
break;
#ifdef F_102
case 8 :
V_141 -> V_66 . V_67 = F_101 ;
V_141 -> V_66 . V_70 = F_103 ;
break;
#endif
default:
F_28 ( V_141 -> V_75 , L_18 ,
V_141 -> V_66 . V_154 ) ;
return - V_157 ;
}
V_159 = ( ( V_141 -> V_153 * V_141 -> V_66 . V_149 )
- ( V_141 -> V_66 . V_149 - V_141 -> V_66 . V_154 ) ) ;
if ( F_109 ( V_147 , V_159 , V_143 ) == NULL )
return - V_158 ;
V_141 -> V_66 . V_147 = F_110 ( V_147 , V_159 ) ;
if ( V_141 -> V_66 . V_147 == NULL ) {
F_107 ( V_147 , V_159 ) ;
return - V_158 ;
}
return 0 ;
}
static int F_111 ( struct V_160 * V_161 , int * V_162 , char * V_163 , char * * V_164 )
{
char * V_165 ;
int V_166 ;
V_165 = strchr ( * V_164 , ',' ) ;
if ( ! V_165 ) {
F_112 (KERN_WARNING PFX L_19 , name) ;
return - V_157 ;
}
* V_165 = '\0' ;
V_165 ++ ;
for ( V_166 = 0 ; V_161 [ V_166 ] . V_163 ; V_166 ++ ) {
if ( strcmp ( * V_164 , V_161 [ V_166 ] . V_163 ) == 0 ) {
* V_162 = V_161 [ V_166 ] . V_162 ;
* V_164 = V_165 ;
return 0 ;
}
}
F_112 (KERN_WARNING PFX L_20 , name, *curr) ;
return - V_157 ;
}
static int F_113 ( const char * V_164 , const char * V_167 ,
const char * V_163 , int * V_162 )
{
char * V_168 ;
if ( strcmp ( V_164 , V_163 ) == 0 ) {
if ( ! V_167 ) {
F_112 (KERN_WARNING PFX
L_21 ,
curr) ;
return - V_157 ;
}
* V_162 = F_114 ( V_167 , & V_168 , 0 ) ;
if ( ( * V_168 != '\0' ) || ( * V_167 == '\0' ) ) {
F_112 (KERN_WARNING PFX
L_22 ,
curr) ;
return - V_157 ;
}
return 1 ;
}
return 0 ;
}
static struct V_9 * F_115 ( void )
{
struct V_9 * V_141 = F_116 ( sizeof( * V_141 ) , V_169 ) ;
if ( V_141 )
F_117 ( & V_141 -> V_103 ) ;
return V_141 ;
}
static int F_118 ( const char * V_162 , struct V_170 * V_171 )
{
char * V_172 = F_119 ( V_162 , V_169 ) ;
int V_19 ;
char * V_173 , * V_164 , * V_165 , * V_168 , * V_174 ;
enum V_175 V_176 ;
enum V_79 V_79 ;
int V_177 ;
unsigned long V_147 ;
int V_149 ;
int V_154 ;
int V_151 ;
int V_46 ;
int V_178 ;
int V_179 ;
int V_74 ;
struct V_9 * V_141 ;
if ( ! V_172 )
return - V_180 ;
V_74 = strlen ( V_172 ) ;
V_179 = V_74 - 1 ;
while ( ( V_179 >= 0 ) && isspace ( V_172 [ V_179 ] ) ) {
V_172 [ V_179 ] = '\0' ;
V_179 -- ;
}
for ( V_164 = V_172 ; V_164 ; V_164 = V_173 ) {
V_149 = 1 ;
V_154 = 1 ;
V_151 = 0 ;
V_46 = 0 ;
V_178 = 0 ;
V_173 = strchr ( V_164 , ':' ) ;
if ( V_173 ) {
* V_173 = '\0' ;
V_173 ++ ;
}
V_19 = F_111 ( V_181 , & V_179 , L_23 , & V_164 ) ;
if ( V_19 )
break;
V_176 = V_179 ;
V_19 = F_111 ( V_182 , & V_179 , L_24 , & V_164 ) ;
if ( V_19 )
break;
V_79 = V_179 ;
V_19 = F_111 ( V_183 , & V_177 , L_25 , & V_164 ) ;
if ( V_19 )
break;
V_165 = strchr ( V_164 , ',' ) ;
if ( V_165 ) {
* V_165 = '\0' ;
V_165 ++ ;
}
V_147 = F_114 ( V_164 , & V_168 , 0 ) ;
if ( ( * V_168 != '\0' ) || ( * V_164 == '\0' ) ) {
F_112 (KERN_WARNING PFX L_26
L_27 , curr) ;
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
V_19 = F_113 ( V_164 , V_174 , L_28 , & V_149 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = F_113 ( V_164 , V_174 , L_29 , & V_154 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = F_113 ( V_164 , V_174 , L_30 , & V_151 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = F_113 ( V_164 , V_174 , L_31 , & V_46 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = F_113 ( V_164 , V_174 , L_32 , & V_178 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = - V_157 ;
F_112 (KERN_WARNING PFX
L_33 ,
curr) ;
goto V_25;
}
if ( V_176 == V_184 ) {
V_141 = F_115 () ;
if ( ! V_141 ) {
V_19 = - V_180 ;
goto V_25;
}
V_141 -> V_139 = V_185 ;
V_141 -> V_79 = V_79 ;
V_141 -> V_66 . V_148 = V_147 ;
V_141 -> V_66 . V_186 = V_177 ;
if ( V_177 == V_187 )
V_141 -> V_188 = F_108 ;
else
V_141 -> V_188 = F_88 ;
V_141 -> V_66 . V_147 = NULL ;
V_141 -> V_66 . V_149 = V_149 ;
if ( ! V_141 -> V_66 . V_149 )
V_141 -> V_66 . V_149 = V_189 ;
V_141 -> V_66 . V_154 = V_154 ;
if ( ! V_141 -> V_66 . V_154 )
V_141 -> V_66 . V_154 = V_189 ;
V_141 -> V_66 . V_151 = V_151 ;
V_141 -> V_46 = V_46 ;
if ( V_141 -> V_46 )
V_141 -> V_133 = F_71 ;
V_141 -> V_190 = V_178 ;
V_19 = F_120 ( V_141 ) ;
if ( V_19 ) {
F_121 ( V_141 ) ;
goto V_25;
}
V_19 = F_122 ( V_141 ) ;
if ( V_19 ) {
F_123 ( V_141 ) ;
goto V_25;
}
} else {
struct V_9 * V_191 , * V_192 ;
F_124 ( & V_193 ) ;
F_125 (e, tmp_e, &smi_infos, link) {
if ( V_191 -> V_66 . V_186 != V_177 )
continue;
if ( V_191 -> V_79 != V_79 )
continue;
if ( V_191 -> V_66 . V_148 == V_147 )
F_123 ( V_191 ) ;
}
F_126 ( & V_193 ) ;
}
}
V_19 = V_74 ;
V_25:
F_121 ( V_172 ) ;
return V_19 ;
}
static int F_127 ( void )
{
int V_194 = - V_155 ;
int V_166 ;
struct V_9 * V_141 ;
for ( V_166 = 0 ; V_166 < V_195 ; V_166 ++ ) {
if ( ! V_196 [ V_166 ] && ! V_197 [ V_166 ] )
continue;
V_141 = F_115 () ;
if ( ! V_141 )
return - V_180 ;
V_141 -> V_139 = V_198 ;
F_112 (KERN_INFO PFX L_34 ) ;
if ( ! V_79 [ V_166 ] || strcmp ( V_79 [ V_166 ] , L_35 ) == 0 ) {
V_141 -> V_79 = V_199 ;
} else if ( strcmp ( V_79 [ V_166 ] , L_36 ) == 0 ) {
V_141 -> V_79 = V_200 ;
} else if ( strcmp ( V_79 [ V_166 ] , L_37 ) == 0 ) {
V_141 -> V_79 = V_80 ;
} else {
F_112 (KERN_WARNING PFX L_38
L_39 ,
i, si_type[i]) ;
F_121 ( V_141 ) ;
continue;
}
if ( V_196 [ V_166 ] ) {
V_141 -> V_188 = F_88 ;
V_141 -> V_66 . V_148 = V_196 [ V_166 ] ;
V_141 -> V_66 . V_186 = V_201 ;
} else if ( V_197 [ V_166 ] ) {
V_141 -> V_188 = F_108 ;
V_141 -> V_66 . V_148 = V_197 [ V_166 ] ;
V_141 -> V_66 . V_186 = V_187 ;
} else {
F_112 (KERN_WARNING PFX L_38
L_40
L_41 , i) ;
F_121 ( V_141 ) ;
continue;
}
V_141 -> V_66 . V_147 = NULL ;
V_141 -> V_66 . V_149 = V_202 [ V_166 ] ;
if ( ! V_141 -> V_66 . V_149 )
V_141 -> V_66 . V_149 = V_189 ;
V_141 -> V_66 . V_154 = V_203 [ V_166 ] ;
if ( ! V_141 -> V_66 . V_154 )
V_141 -> V_66 . V_154 = V_189 ;
V_141 -> V_66 . V_151 = V_204 [ V_166 ] ;
V_141 -> V_46 = V_205 [ V_166 ] ;
if ( V_141 -> V_46 )
V_141 -> V_133 = F_71 ;
V_141 -> V_190 = V_206 [ V_166 ] ;
if ( ! F_120 ( V_141 ) ) {
if ( F_122 ( V_141 ) )
F_123 ( V_141 ) ;
V_194 = 0 ;
} else {
F_121 ( V_141 ) ;
}
}
return V_194 ;
}
static T_4 F_128 ( T_5 V_207 ,
T_4 V_208 , void * V_209 )
{
struct V_9 * V_9 = V_209 ;
unsigned long V_101 ;
F_38 ( & ( V_9 -> V_103 ) , V_101 ) ;
F_23 ( V_9 , V_129 ) ;
F_1 ( L_42 ) ;
F_29 ( V_9 , 0 ) ;
F_40 ( & ( V_9 -> V_103 ) , V_101 ) ;
return V_210 ;
}
static void F_129 ( struct V_9 * V_141 )
{
if ( ! V_141 -> V_46 )
return;
F_130 ( NULL , V_141 -> V_46 , & F_128 ) ;
}
static int F_131 ( struct V_9 * V_141 )
{
T_6 V_211 ;
if ( ! V_141 -> V_46 )
return 0 ;
V_211 = F_132 ( NULL ,
V_141 -> V_46 ,
V_212 ,
& F_128 ,
V_141 ) ;
if ( V_211 != V_213 ) {
F_28 ( V_141 -> V_75 , L_43
L_16 , V_143 , V_141 -> V_46 ) ;
V_141 -> V_46 = 0 ;
return - V_157 ;
} else {
V_141 -> V_144 = F_129 ;
F_73 ( V_141 -> V_75 , L_44 , V_141 -> V_46 ) ;
return 0 ;
}
}
static int F_133 ( struct V_214 * V_215 )
{
struct V_9 * V_141 ;
int V_19 ;
if ( V_215 -> V_216 != 1 ) {
F_112 (KERN_INFO PFX L_45 , spmi->IPMIlegacy) ;
return - V_155 ;
}
V_141 = F_115 () ;
if ( ! V_141 ) {
F_112 (KERN_ERR PFX L_46 ) ;
return - V_180 ;
}
V_141 -> V_139 = V_217 ;
F_112 (KERN_INFO PFX L_47 ) ;
switch ( V_215 -> V_218 ) {
case 1 :
V_141 -> V_79 = V_199 ;
break;
case 2 :
V_141 -> V_79 = V_200 ;
break;
case 3 :
V_141 -> V_79 = V_80 ;
break;
case 4 :
F_121 ( V_141 ) ;
return - V_158 ;
default:
F_112 (KERN_INFO PFX L_48 ,
spmi->InterfaceType) ;
F_121 ( V_141 ) ;
return - V_158 ;
}
if ( V_215 -> V_219 & 1 ) {
V_141 -> V_46 = V_215 -> V_220 ;
V_141 -> V_133 = F_131 ;
} else if ( V_215 -> V_219 & 2 ) {
V_141 -> V_46 = V_215 -> V_221 ;
V_141 -> V_133 = F_71 ;
} else {
V_141 -> V_46 = 0 ;
V_141 -> V_133 = NULL ;
}
if ( V_215 -> V_147 . V_222 ) {
V_141 -> V_66 . V_149 = V_215 -> V_147 . V_222 / 8 ;
} else {
V_141 -> V_66 . V_149 = V_189 ;
}
V_141 -> V_66 . V_154 = V_141 -> V_66 . V_149 ;
V_141 -> V_66 . V_151 = V_215 -> V_147 . V_223 ;
if ( V_215 -> V_147 . V_224 == V_225 ) {
V_141 -> V_188 = F_108 ;
V_141 -> V_66 . V_186 = V_187 ;
} else if ( V_215 -> V_147 . V_224 == V_226 ) {
V_141 -> V_188 = F_88 ;
V_141 -> V_66 . V_186 = V_201 ;
} else {
F_121 ( V_141 ) ;
F_112 (KERN_WARNING PFX L_49 ) ;
return - V_158 ;
}
V_141 -> V_66 . V_148 = V_215 -> V_147 . V_227 ;
F_134 ( L_50 ,
( V_141 -> V_66 . V_186 == V_201 ) ? L_51 : L_52 ,
V_141 -> V_66 . V_148 , V_141 -> V_66 . V_154 , V_141 -> V_66 . V_149 ,
V_141 -> V_46 ) ;
V_19 = F_120 ( V_141 ) ;
if ( V_19 )
F_121 ( V_141 ) ;
return V_19 ;
}
static void F_135 ( void )
{
T_6 V_211 ;
struct V_214 * V_215 ;
int V_166 ;
if ( V_228 )
return;
if ( V_229 )
return;
for ( V_166 = 0 ; ; V_166 ++ ) {
V_211 = F_136 ( V_230 , V_166 + 1 ,
(struct V_231 * * ) & V_215 ) ;
if ( V_211 != V_213 )
return;
F_133 ( V_215 ) ;
}
}
static int F_137 ( const struct V_232 * V_233 ,
struct V_234 * V_235 )
{
const T_1 * V_16 = ( const T_1 * ) V_233 ;
unsigned long V_236 ;
T_1 V_237 ;
T_1 V_74 = V_233 -> V_238 ;
V_235 -> type = V_16 [ 4 ] ;
memcpy ( & V_236 , V_16 + 8 , sizeof( unsigned long ) ) ;
if ( V_74 >= 0x11 ) {
if ( V_236 & 1 ) {
V_236 &= 0xFFFE ;
V_235 -> V_177 = V_201 ;
} else
V_235 -> V_177 = V_187 ;
V_235 -> V_236 = V_236 | ( ( V_16 [ 0x10 ] & 0x10 ) >> 4 ) ;
V_235 -> V_46 = V_16 [ 0x11 ] ;
V_237 = ( V_16 [ 0x10 ] & 0xC0 ) >> 6 ;
switch ( V_237 ) {
case 0x00 :
V_235 -> V_146 = 1 ;
break;
case 0x01 :
V_235 -> V_146 = 4 ;
break;
case 0x02 :
V_235 -> V_146 = 16 ;
break;
default:
return - V_158 ;
}
} else {
V_235 -> V_236 = V_236 & 0xfffe ;
V_235 -> V_177 = V_201 ;
V_235 -> V_146 = 1 ;
}
V_235 -> V_190 = V_16 [ 6 ] ;
return 0 ;
}
static void F_138 ( struct V_234 * V_239 )
{
struct V_9 * V_141 ;
V_141 = F_115 () ;
if ( ! V_141 ) {
F_112 (KERN_ERR PFX L_53 ) ;
return;
}
V_141 -> V_139 = V_240 ;
F_112 (KERN_INFO PFX L_54 ) ;
switch ( V_239 -> type ) {
case 0x01 :
V_141 -> V_79 = V_199 ;
break;
case 0x02 :
V_141 -> V_79 = V_200 ;
break;
case 0x03 :
V_141 -> V_79 = V_80 ;
break;
default:
F_121 ( V_141 ) ;
return;
}
switch ( V_239 -> V_177 ) {
case V_187 :
V_141 -> V_188 = F_108 ;
V_141 -> V_66 . V_186 = V_187 ;
break;
case V_201 :
V_141 -> V_188 = F_88 ;
V_141 -> V_66 . V_186 = V_201 ;
break;
default:
F_121 ( V_141 ) ;
F_112 (KERN_WARNING PFX L_55 ,
ipmi_data->addr_space) ;
return;
}
V_141 -> V_66 . V_148 = V_239 -> V_236 ;
V_141 -> V_66 . V_149 = V_239 -> V_146 ;
if ( ! V_141 -> V_66 . V_149 )
V_141 -> V_66 . V_149 = V_189 ;
V_141 -> V_66 . V_154 = V_189 ;
V_141 -> V_66 . V_151 = 0 ;
V_141 -> V_190 = V_239 -> V_190 ;
V_141 -> V_46 = V_239 -> V_46 ;
if ( V_141 -> V_46 )
V_141 -> V_133 = F_71 ;
F_134 ( L_56 ,
( V_141 -> V_66 . V_186 == V_201 ) ? L_51 : L_52 ,
V_141 -> V_66 . V_148 , V_141 -> V_66 . V_154 , V_141 -> V_66 . V_149 ,
V_141 -> V_46 ) ;
if ( F_120 ( V_141 ) )
F_121 ( V_141 ) ;
}
static void F_139 ( void )
{
const struct V_241 * V_75 = NULL ;
struct V_234 V_16 ;
int V_19 ;
while ( ( V_75 = F_140 ( V_242 , NULL , V_75 ) ) ) {
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_19 = F_137 ( ( const struct V_232 * ) V_75 -> V_243 ,
& V_16 ) ;
if ( ! V_19 )
F_138 ( & V_16 ) ;
}
}
static void F_141 ( struct V_9 * V_141 )
{
struct V_244 * V_245 = V_141 -> V_246 ;
F_142 ( V_245 ) ;
}
static int F_143 ( struct V_9 * V_141 )
{
if ( V_141 -> V_79 == V_199 ) {
unsigned char V_211 ;
int V_149 ;
V_141 -> V_66 . V_154 = V_247 ;
V_141 -> V_66 . V_151 = 0 ;
V_141 -> V_153 = 2 ;
V_141 -> V_26 = & V_248 ;
for ( V_149 = V_189 ; V_149 <= 16 ; ) {
V_141 -> V_66 . V_149 = V_149 ;
if ( V_141 -> V_188 ( V_141 ) ) {
F_144 ( V_141 -> V_75 ,
L_57 ) ;
return V_189 ;
}
V_141 -> V_66 . V_70 ( & V_141 -> V_66 , 1 , 0x10 ) ;
V_211 = V_141 -> V_66 . V_67 ( & V_141 -> V_66 , 1 ) ;
V_141 -> V_156 ( V_141 ) ;
if ( V_211 )
return V_149 ;
V_149 *= 4 ;
}
}
return V_189 ;
}
static int F_145 ( struct V_244 * V_245 ,
const struct V_249 * V_250 )
{
int V_19 ;
int V_251 = V_245 -> V_252 & V_253 ;
struct V_9 * V_141 ;
V_141 = F_115 () ;
if ( ! V_141 )
return - V_180 ;
V_141 -> V_139 = V_254 ;
F_73 ( & V_245 -> V_75 , L_58 ) ;
switch ( V_251 ) {
case V_255 :
V_141 -> V_79 = V_200 ;
break;
case V_256 :
V_141 -> V_79 = V_199 ;
break;
case V_257 :
V_141 -> V_79 = V_80 ;
break;
default:
F_121 ( V_141 ) ;
F_73 ( & V_245 -> V_75 , L_59 , V_251 ) ;
return - V_180 ;
}
V_19 = F_146 ( V_245 ) ;
if ( V_19 ) {
F_144 ( & V_245 -> V_75 , L_60 ) ;
F_121 ( V_141 ) ;
return V_19 ;
}
V_141 -> V_258 = F_141 ;
V_141 -> V_246 = V_245 ;
if ( F_147 ( V_245 , 0 ) & V_259 ) {
V_141 -> V_188 = F_88 ;
V_141 -> V_66 . V_186 = V_201 ;
} else {
V_141 -> V_188 = F_108 ;
V_141 -> V_66 . V_186 = V_187 ;
}
V_141 -> V_66 . V_148 = F_148 ( V_245 , 0 ) ;
V_141 -> V_66 . V_149 = F_143 ( V_141 ) ;
V_141 -> V_66 . V_154 = V_247 ;
V_141 -> V_66 . V_151 = 0 ;
V_141 -> V_46 = V_245 -> V_46 ;
if ( V_141 -> V_46 )
V_141 -> V_133 = F_71 ;
V_141 -> V_75 = & V_245 -> V_75 ;
F_149 ( V_245 , V_141 ) ;
F_73 ( & V_245 -> V_75 , L_61 ,
& V_245 -> V_260 [ 0 ] , V_141 -> V_66 . V_154 , V_141 -> V_66 . V_149 ,
V_141 -> V_46 ) ;
V_19 = F_120 ( V_141 ) ;
if ( V_19 ) {
F_121 ( V_141 ) ;
F_142 ( V_245 ) ;
}
return V_19 ;
}
static void F_150 ( struct V_244 * V_245 )
{
struct V_9 * V_141 = F_151 ( V_245 ) ;
F_123 ( V_141 ) ;
F_142 ( V_245 ) ;
}
static int F_152 ( struct V_261 * V_75 )
{
const struct V_262 * V_263 ;
struct V_9 * V_141 ;
struct V_260 V_260 ;
const T_7 * V_154 , * V_149 , * V_151 ;
struct V_264 * V_265 = V_75 -> V_75 . V_266 ;
int V_194 ;
int V_267 ;
F_73 ( & V_75 -> V_75 , L_62 ) ;
V_263 = F_153 ( V_268 , & V_75 -> V_75 ) ;
if ( ! V_263 )
return - V_155 ;
if ( ! F_154 ( V_265 ) )
return - V_157 ;
V_194 = F_155 ( V_265 , 0 , & V_260 ) ;
if ( V_194 ) {
F_28 ( & V_75 -> V_75 , V_269 L_63 ) ;
return V_194 ;
}
V_154 = F_156 ( V_265 , L_64 , & V_267 ) ;
if ( V_154 && V_267 != 4 ) {
F_28 ( & V_75 -> V_75 , V_269 L_65 ) ;
return - V_157 ;
}
V_149 = F_156 ( V_265 , L_66 , & V_267 ) ;
if ( V_149 && V_267 != 4 ) {
F_28 ( & V_75 -> V_75 , V_269 L_67 ) ;
return - V_157 ;
}
V_151 = F_156 ( V_265 , L_68 , & V_267 ) ;
if ( V_151 && V_267 != 4 ) {
F_28 ( & V_75 -> V_75 , V_269 L_69 ) ;
return - V_157 ;
}
V_141 = F_115 () ;
if ( ! V_141 ) {
F_144 ( & V_75 -> V_75 ,
L_70 ) ;
return - V_180 ;
}
V_141 -> V_79 = (enum V_79 ) V_263 -> V_16 ;
V_141 -> V_139 = V_270 ;
V_141 -> V_133 = F_71 ;
if ( V_260 . V_101 & V_259 ) {
V_141 -> V_188 = F_88 ;
V_141 -> V_66 . V_186 = V_201 ;
} else {
V_141 -> V_188 = F_108 ;
V_141 -> V_66 . V_186 = V_187 ;
}
V_141 -> V_66 . V_148 = V_260 . V_271 ;
V_141 -> V_66 . V_154 = V_154 ? F_157 ( V_154 ) : V_247 ;
V_141 -> V_66 . V_149 = V_149 ? F_157 ( V_149 ) : V_189 ;
V_141 -> V_66 . V_151 = V_151 ? F_157 ( V_151 ) : 0 ;
V_141 -> V_46 = F_158 ( V_75 -> V_75 . V_266 , 0 ) ;
V_141 -> V_75 = & V_75 -> V_75 ;
F_159 ( & V_75 -> V_75 , L_71 ,
V_141 -> V_66 . V_148 , V_141 -> V_66 . V_154 , V_141 -> V_66 . V_149 ,
V_141 -> V_46 ) ;
F_160 ( & V_75 -> V_75 , V_141 ) ;
V_194 = F_120 ( V_141 ) ;
if ( V_194 ) {
F_121 ( V_141 ) ;
return V_194 ;
}
return 0 ;
}
static int F_152 ( struct V_261 * V_75 )
{
return - V_155 ;
}
static int F_161 ( struct V_261 * V_75 )
{
struct V_9 * V_141 ;
struct V_260 * V_272 , * V_273 ;
T_5 V_274 ;
T_6 V_211 ;
unsigned long long V_275 ;
int V_19 = - V_157 ;
V_274 = F_162 ( & V_75 -> V_75 ) ;
if ( ! V_274 )
return - V_155 ;
V_141 = F_115 () ;
if ( ! V_141 )
return - V_180 ;
V_141 -> V_139 = V_276 ;
F_73 ( & V_75 -> V_75 , V_269 L_72 ) ;
V_141 -> V_140 . V_277 . T_5 = V_274 ;
V_211 = F_163 ( V_274 , L_73 , NULL , & V_275 ) ;
if ( F_164 ( V_211 ) ) {
F_144 ( & V_75 -> V_75 , L_74 ) ;
goto V_278;
}
switch ( V_275 ) {
case 1 :
V_141 -> V_79 = V_199 ;
break;
case 2 :
V_141 -> V_79 = V_200 ;
break;
case 3 :
V_141 -> V_79 = V_80 ;
break;
case 4 :
V_19 = - V_155 ;
goto V_278;
default:
F_73 ( & V_75 -> V_75 , L_75 , V_275 ) ;
goto V_278;
}
V_272 = F_165 ( V_75 , V_259 , 0 ) ;
if ( V_272 ) {
V_141 -> V_188 = F_88 ;
V_141 -> V_66 . V_186 = V_201 ;
} else {
V_272 = F_165 ( V_75 , V_279 , 0 ) ;
if ( V_272 ) {
V_141 -> V_188 = F_108 ;
V_141 -> V_66 . V_186 = V_187 ;
}
}
if ( ! V_272 ) {
F_144 ( & V_75 -> V_75 , L_76 ) ;
goto V_278;
}
V_141 -> V_66 . V_148 = V_272 -> V_271 ;
V_141 -> V_66 . V_149 = V_189 ;
V_273 = F_165 ( V_75 ,
( V_141 -> V_66 . V_186 == V_201 ) ?
V_259 : V_279 ,
1 ) ;
if ( V_273 ) {
if ( V_273 -> V_271 > V_141 -> V_66 . V_148 )
V_141 -> V_66 . V_149 =
V_273 -> V_271 - V_141 -> V_66 . V_148 ;
}
V_141 -> V_66 . V_154 = V_189 ;
V_141 -> V_66 . V_151 = 0 ;
V_211 = F_163 ( V_274 , L_77 , NULL , & V_275 ) ;
if ( F_166 ( V_211 ) ) {
V_141 -> V_46 = V_275 ;
V_141 -> V_133 = F_131 ;
} else {
int V_46 = F_167 ( V_75 , 0 ) ;
if ( V_46 > 0 ) {
V_141 -> V_46 = V_46 ;
V_141 -> V_133 = F_71 ;
}
}
V_141 -> V_75 = & V_75 -> V_75 ;
F_168 ( V_75 , V_141 ) ;
F_73 ( V_141 -> V_75 , L_61 ,
V_272 , V_141 -> V_66 . V_154 , V_141 -> V_66 . V_149 ,
V_141 -> V_46 ) ;
V_19 = F_120 ( V_141 ) ;
if ( V_19 )
F_121 ( V_141 ) ;
return V_19 ;
V_278:
F_121 ( V_141 ) ;
return V_19 ;
}
static int F_161 ( struct V_261 * V_75 )
{
return - V_155 ;
}
static int F_169 ( struct V_261 * V_75 )
{
if ( F_152 ( V_75 ) == 0 )
return 0 ;
return F_161 ( V_75 ) ;
}
static int F_170 ( struct V_261 * V_75 )
{
struct V_9 * V_141 = F_171 ( & V_75 -> V_75 ) ;
F_123 ( V_141 ) ;
return 0 ;
}
static int F_172 ( struct V_280 * V_75 )
{
struct V_9 * V_141 ;
int V_19 ;
V_141 = F_115 () ;
if ( ! V_141 ) {
F_144 ( & V_75 -> V_75 ,
L_78 ) ;
return - V_180 ;
}
V_141 -> V_79 = V_199 ;
V_141 -> V_139 = V_270 ;
V_141 -> V_188 = F_108 ;
V_141 -> V_66 . V_186 = V_187 ;
V_141 -> V_66 . V_148 = V_75 -> V_281 . V_271 ;
V_141 -> V_66 . V_154 = 1 ;
V_141 -> V_66 . V_149 = 1 ;
V_141 -> V_66 . V_151 = 0 ;
V_141 -> V_46 = 0 ;
V_141 -> V_133 = NULL ;
V_141 -> V_75 = & V_75 -> V_75 ;
F_159 ( & V_75 -> V_75 , L_79 , V_141 -> V_66 . V_148 ) ;
F_160 ( & V_75 -> V_75 , V_141 ) ;
V_19 = F_120 ( V_141 ) ;
if ( V_19 ) {
F_121 ( V_141 ) ;
return V_19 ;
}
return 0 ;
}
static int F_173 ( struct V_280 * V_75 )
{
F_123 ( F_171 ( & V_75 -> V_75 ) ) ;
return 0 ;
}
static int F_174 ( struct V_9 * V_9 )
{
enum V_18 V_106 ;
V_106 = V_9 -> V_26 -> V_85 ( V_9 -> V_28 , 0 ) ;
for (; ; ) {
if ( V_106 == V_112 ||
V_106 == V_282 ) {
F_175 ( 1 ) ;
V_106 = V_9 -> V_26 -> V_85 (
V_9 -> V_28 , F_176 ( 1 ) ) ;
} else if ( V_106 == V_24 ) {
V_106 = V_9 -> V_26 -> V_85 (
V_9 -> V_28 , 0 ) ;
} else
break;
}
if ( V_106 == V_88 )
return - V_155 ;
return 0 ;
}
static int F_177 ( struct V_9 * V_9 )
{
unsigned char V_1 [ 2 ] ;
unsigned char * V_283 ;
unsigned long V_284 ;
int V_19 = 0 ;
V_283 = F_178 ( V_72 , V_169 ) ;
if ( ! V_283 )
return - V_180 ;
V_1 [ 0 ] = V_30 << 2 ;
V_1 [ 1 ] = V_285 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 2 ) ;
V_19 = F_174 ( V_9 ) ;
if ( V_19 )
goto V_25;
V_284 = V_9 -> V_26 -> V_71 ( V_9 -> V_28 ,
V_283 , V_72 ) ;
V_19 = F_179 ( V_283 , V_284 , & V_9 -> V_286 ) ;
V_25:
F_121 ( V_283 ) ;
return V_19 ;
}
static int F_180 ( struct V_9 * V_9 , T_1 * V_58 )
{
unsigned char V_1 [ 3 ] ;
unsigned char * V_283 ;
unsigned long V_284 ;
int V_19 ;
V_283 = F_178 ( V_72 , V_169 ) ;
if ( ! V_283 )
return - V_180 ;
V_1 [ 0 ] = V_30 << 2 ;
V_1 [ 1 ] = V_31 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 2 ) ;
V_19 = F_174 ( V_9 ) ;
if ( V_19 ) {
F_28 ( V_9 -> V_75 ,
L_80 ,
V_19 ) ;
goto V_25;
}
V_284 = V_9 -> V_26 -> V_71 ( V_9 -> V_28 ,
V_283 , V_72 ) ;
if ( V_284 < 4 ||
V_283 [ 0 ] != ( V_30 | 1 ) << 2 ||
V_283 [ 1 ] != V_31 ||
V_283 [ 2 ] != 0 ) {
F_28 ( V_9 -> V_75 ,
L_81 ,
V_284 , V_283 [ 0 ] , V_283 [ 1 ] , V_283 [ 2 ] ) ;
V_19 = - V_157 ;
goto V_25;
} else {
* V_58 = V_283 [ 3 ] ;
}
V_25:
F_121 ( V_283 ) ;
return V_19 ;
}
static int F_181 ( struct V_9 * V_9 , T_1 V_58 )
{
unsigned char V_1 [ 3 ] ;
unsigned char * V_283 ;
unsigned long V_284 ;
int V_19 ;
V_283 = F_178 ( V_72 , V_169 ) ;
if ( ! V_283 )
return - V_180 ;
V_1 [ 0 ] = V_30 << 2 ;
V_1 [ 1 ] = V_82 ;
V_1 [ 2 ] = V_58 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 3 ) ;
V_19 = F_174 ( V_9 ) ;
if ( V_19 ) {
F_28 ( V_9 -> V_75 ,
L_82 ,
V_19 ) ;
goto V_25;
}
V_284 = V_9 -> V_26 -> V_71 ( V_9 -> V_28 ,
V_283 , V_72 ) ;
if ( V_284 < 3 ||
V_283 [ 0 ] != ( V_30 | 1 ) << 2 ||
V_283 [ 1 ] != V_82 ) {
F_28 ( V_9 -> V_75 ,
L_83 ,
V_284 , V_283 [ 0 ] , V_283 [ 1 ] ) ;
V_19 = - V_157 ;
goto V_25;
}
if ( V_283 [ 2 ] != 0 )
V_19 = 1 ;
V_25:
F_121 ( V_283 ) ;
return V_19 ;
}
static void F_182 ( struct V_9 * V_9 )
{
T_1 V_58 = 0 ;
int V_19 ;
V_19 = F_180 ( V_9 , & V_58 ) ;
if ( ! V_19 ) {
if ( ( V_58 & V_63 ) == 0 )
return;
V_58 &= ~ V_63 ;
V_19 = F_181 ( V_9 , V_58 ) ;
}
if ( V_19 < 0 ) {
F_144 ( V_9 -> V_75 ,
L_84 , V_19 ) ;
return;
}
if ( V_19 ) {
F_28 ( V_9 -> V_75 ,
L_85 ) ;
V_9 -> V_61 = true ;
}
}
static void F_183 ( struct V_9 * V_9 )
{
T_1 V_58 = 0 ;
int V_19 ;
if ( ! V_9 -> V_46 )
return;
V_19 = F_180 ( V_9 , & V_58 ) ;
if ( ! V_19 ) {
V_58 |= V_63 ;
V_19 = F_181 ( V_9 , V_58 ) ;
}
if ( V_19 < 0 ) {
F_144 ( V_9 -> V_75 ,
L_86 , V_19 ) ;
return;
}
if ( V_19 ) {
F_28 ( V_9 -> V_75 ,
L_87 ) ;
V_9 -> V_61 = true ;
V_9 -> V_62 = true ;
}
}
static int F_184 ( struct V_9 * V_9 )
{
unsigned char V_1 [ 3 ] ;
unsigned char * V_283 ;
unsigned long V_284 ;
int V_19 = 0 ;
V_283 = F_178 ( V_72 , V_169 ) ;
if ( ! V_283 )
return - V_180 ;
V_1 [ 0 ] = V_30 << 2 ;
V_1 [ 1 ] = V_31 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 2 ) ;
V_19 = F_174 ( V_9 ) ;
if ( V_19 ) {
F_112 (KERN_WARNING PFX L_88
L_89
L_90 ) ;
goto V_25;
}
V_284 = V_9 -> V_26 -> V_71 ( V_9 -> V_28 ,
V_283 , V_72 ) ;
if ( V_284 < 4 ||
V_283 [ 0 ] != ( V_30 | 1 ) << 2 ||
V_283 [ 1 ] != V_31 ||
V_283 [ 2 ] != 0 ) {
F_112 (KERN_WARNING PFX L_91
L_92 ) ;
V_19 = - V_157 ;
goto V_25;
}
if ( V_283 [ 3 ] & V_60 ) {
V_9 -> V_59 = true ;
goto V_25;
}
V_1 [ 0 ] = V_30 << 2 ;
V_1 [ 1 ] = V_82 ;
V_1 [ 2 ] = V_283 [ 3 ] | V_60 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 3 ) ;
V_19 = F_174 ( V_9 ) ;
if ( V_19 ) {
F_112 (KERN_WARNING PFX L_93
L_94
L_90 ) ;
goto V_25;
}
V_284 = V_9 -> V_26 -> V_71 ( V_9 -> V_28 ,
V_283 , V_72 ) ;
if ( V_284 < 3 ||
V_283 [ 0 ] != ( V_30 | 1 ) << 2 ||
V_283 [ 1 ] != V_82 ) {
F_112 (KERN_WARNING PFX L_95
L_96 ) ;
V_19 = - V_157 ;
goto V_25;
}
if ( V_283 [ 2 ] != 0 )
V_19 = - V_287 ;
else
V_9 -> V_59 = true ;
V_25:
F_121 ( V_283 ) ;
return V_19 ;
}
static int F_185 ( struct V_288 * V_289 , void * V_161 )
{
struct V_9 * V_137 = V_289 -> V_290 ;
F_186 ( V_289 , L_97 , V_291 [ V_137 -> V_79 ] ) ;
return 0 ;
}
static int F_187 ( struct V_292 * V_292 , struct V_293 * V_293 )
{
return F_188 ( V_293 , F_185 , F_189 ( V_292 ) ) ;
}
static int F_190 ( struct V_288 * V_289 , void * V_161 )
{
struct V_9 * V_137 = V_289 -> V_290 ;
F_186 ( V_289 , L_98 ,
V_137 -> V_46 && ! V_137 -> V_47 ) ;
F_186 ( V_289 , L_99 ,
F_191 ( V_137 , V_128 ) ) ;
F_186 ( V_289 , L_100 ,
F_191 ( V_137 , V_126 ) ) ;
F_186 ( V_289 , L_101 ,
F_191 ( V_137 , V_94 ) ) ;
F_186 ( V_289 , L_102 ,
F_191 ( V_137 , V_129 ) ) ;
F_186 ( V_289 , L_103 ,
F_191 ( V_137 , V_92 ) ) ;
F_186 ( V_289 , L_104 ,
F_191 ( V_137 , V_294 ) ) ;
F_186 ( V_289 , L_105 ,
F_191 ( V_137 , V_89 ) ) ;
F_186 ( V_289 , L_106 ,
F_191 ( V_137 , V_87 ) ) ;
F_186 ( V_289 , L_107 ,
F_191 ( V_137 , V_77 ) ) ;
F_186 ( V_289 , L_108 ,
F_191 ( V_137 , V_51 ) ) ;
F_186 ( V_289 , L_109 ,
F_191 ( V_137 , V_78 ) ) ;
return 0 ;
}
static int F_192 ( struct V_292 * V_292 , struct V_293 * V_293 )
{
return F_188 ( V_293 , F_190 , F_189 ( V_292 ) ) ;
}
static int F_193 ( struct V_288 * V_289 , void * V_161 )
{
struct V_9 * V_137 = V_289 -> V_290 ;
F_186 ( V_289 ,
L_110 ,
V_291 [ V_137 -> V_79 ] ,
V_295 [ V_137 -> V_66 . V_186 ] ,
V_137 -> V_66 . V_148 ,
V_137 -> V_66 . V_149 ,
V_137 -> V_66 . V_154 ,
V_137 -> V_66 . V_151 ,
V_137 -> V_46 ,
V_137 -> V_190 ) ;
return 0 ;
}
static int F_194 ( struct V_292 * V_292 , struct V_293 * V_293 )
{
return F_188 ( V_293 , F_193 , F_189 ( V_292 ) ) ;
}
static int F_195 ( struct V_9 * V_9 )
{
V_9 -> V_50 = ( ( V_9 -> V_50 & ~ V_54 ) |
V_52 ) ;
return 1 ;
}
static void F_196 ( struct V_9 * V_9 )
{
struct V_296 * V_297 = & V_9 -> V_286 ;
if ( V_297 -> V_298 == V_299 ) {
if ( V_297 -> V_286 == V_300 &&
V_297 -> V_301 == V_302 &&
V_297 -> V_303 == V_304 ) {
V_9 -> V_55 =
F_195 ;
} else if ( F_197 ( V_297 ) < 1 ||
( F_197 ( V_297 ) == 1 &&
F_198 ( V_297 ) < 5 ) ) {
V_9 -> V_55 =
F_195 ;
}
}
}
static void F_199 ( struct V_9 * V_9 )
{
struct V_10 * V_1 = V_9 -> V_13 ;
V_1 -> V_15 [ 0 ] = V_1 -> V_16 [ 0 ] | 4 ;
V_1 -> V_15 [ 1 ] = V_1 -> V_16 [ 1 ] ;
V_1 -> V_15 [ 2 ] = V_305 ;
V_1 -> V_17 = 3 ;
V_9 -> V_13 = NULL ;
F_6 ( V_9 , V_1 ) ;
}
static int F_200 ( struct V_6 * V_306 ,
unsigned long V_307 ,
void * V_308 )
{
struct V_9 * V_9 = V_308 ;
unsigned char * V_16 = V_9 -> V_13 -> V_16 ;
unsigned int V_309 = V_9 -> V_13 -> V_29 ;
if ( V_309 >= 8 &&
( V_16 [ 0 ] >> 2 ) == V_310 &&
V_16 [ 1 ] == V_311 &&
V_16 [ 7 ] == 0x3A ) {
F_199 ( V_9 ) ;
return V_312 ;
}
return V_313 ;
}
static void
F_201 ( struct V_9 * V_9 )
{
struct V_296 * V_297 = & V_9 -> V_286 ;
if ( V_297 -> V_298 == V_299 &&
V_9 -> V_79 == V_80 )
F_4 ( & V_314 ) ;
}
static void F_202 ( struct V_9 * V_9 )
{
F_196 ( V_9 ) ;
}
static void F_203 ( struct V_9 * V_9 )
{
F_201 ( V_9 ) ;
}
static void F_204 ( struct V_9 * V_9 )
{
F_182 ( V_9 ) ;
F_183 ( V_9 ) ;
}
static inline void F_205 ( struct V_9 * V_9 )
{
if ( V_9 -> V_97 != NULL )
F_206 ( V_9 -> V_97 ) ;
if ( V_9 -> V_45 )
F_207 ( & V_9 -> V_44 ) ;
}
static void F_208 ( void )
{
struct V_9 * V_141 ;
int V_166 ;
for ( V_166 = 0 ; ; V_166 ++ ) {
if ( ! V_315 [ V_166 ] . V_316 )
break;
#ifdef F_209
if ( F_210 ( V_315 [ V_166 ] . V_316 ) )
continue;
#endif
V_141 = F_115 () ;
if ( ! V_141 )
return;
V_141 -> V_139 = V_317 ;
V_141 -> V_79 = V_315 [ V_166 ] . type ;
V_141 -> V_188 = F_88 ;
V_141 -> V_66 . V_148 = V_315 [ V_166 ] . V_316 ;
V_141 -> V_66 . V_186 = V_201 ;
V_141 -> V_66 . V_147 = NULL ;
V_141 -> V_66 . V_149 = V_189 ;
V_141 -> V_66 . V_154 = V_189 ;
V_141 -> V_66 . V_151 = 0 ;
if ( F_120 ( V_141 ) == 0 ) {
if ( ( F_122 ( V_141 ) ) == 0 ) {
F_112 (KERN_INFO PFX L_111
L_112 ,
si_to_str[info->si_type],
addr_space_to_str[info->io.addr_type],
info->io.addr_data) ;
} else
F_123 ( V_141 ) ;
} else {
F_121 ( V_141 ) ;
}
}
}
static int F_211 ( struct V_9 * V_141 )
{
struct V_9 * V_191 ;
F_212 (e, &smi_infos, link) {
if ( V_191 -> V_66 . V_186 != V_141 -> V_66 . V_186 )
continue;
if ( V_191 -> V_66 . V_148 == V_141 -> V_66 . V_148 )
return 0 ;
}
return 1 ;
}
static int F_120 ( struct V_9 * V_132 )
{
int V_19 = 0 ;
F_112 (KERN_INFO PFX L_113 ,
ipmi_addr_src_to_str(new_smi->addr_source),
si_to_str[new_smi->si_type]) ;
F_124 ( & V_193 ) ;
if ( ! F_211 ( V_132 ) ) {
F_112 ( V_318 L_114 ) ;
V_19 = - V_319 ;
goto V_320;
}
F_112 ( V_318 L_115 ) ;
V_132 -> V_11 = NULL ;
V_132 -> V_28 = NULL ;
V_132 -> V_26 = NULL ;
F_213 ( & V_132 -> V_321 , & V_322 ) ;
V_320:
F_126 ( & V_193 ) ;
return V_19 ;
}
static int F_122 ( struct V_9 * V_132 )
{
int V_19 = 0 ;
int V_166 ;
F_112 (KERN_INFO PFX L_116
L_117
L_118 ,
ipmi_addr_src_to_str(new_smi->addr_source),
si_to_str[new_smi->si_type],
addr_space_to_str[new_smi->io.addr_type],
new_smi->io.addr_data,
new_smi->slave_addr, new_smi->irq) ;
switch ( V_132 -> V_79 ) {
case V_199 :
V_132 -> V_26 = & V_248 ;
break;
case V_200 :
V_132 -> V_26 = & V_323 ;
break;
case V_80 :
V_132 -> V_26 = & V_324 ;
break;
default:
V_19 = - V_158 ;
goto V_320;
}
V_132 -> V_28 = F_178 ( V_132 -> V_26 -> V_309 () , V_169 ) ;
if ( ! V_132 -> V_28 ) {
F_112 (KERN_ERR PFX
L_119 ) ;
V_19 = - V_180 ;
goto V_320;
}
V_132 -> V_153 = V_132 -> V_26 -> V_325 ( V_132 -> V_28 ,
& V_132 -> V_66 ) ;
V_19 = V_132 -> V_188 ( V_132 ) ;
if ( V_19 ) {
F_112 (KERN_ERR PFX L_120 ) ;
goto V_320;
}
if ( V_132 -> V_26 -> V_326 ( V_132 -> V_28 ) ) {
if ( V_132 -> V_139 )
F_112 (KERN_INFO PFX L_121 ) ;
V_19 = - V_155 ;
goto V_320;
}
V_19 = F_177 ( V_132 ) ;
if ( V_19 ) {
if ( V_132 -> V_139 )
F_112 (KERN_INFO PFX L_122
L_123 ) ;
goto V_320;
}
F_202 ( V_132 ) ;
F_203 ( V_132 ) ;
F_204 ( V_132 ) ;
V_132 -> V_20 = NULL ;
V_132 -> V_13 = NULL ;
F_32 ( & V_132 -> V_95 , 0 ) ;
V_132 -> V_102 = false ;
for ( V_166 = 0 ; V_166 < V_327 ; V_166 ++ )
F_32 ( & V_132 -> V_328 [ V_166 ] , 0 ) ;
V_132 -> V_47 = true ;
F_32 ( & V_132 -> V_118 , 0 ) ;
V_132 -> V_109 = V_329 ;
V_329 ++ ;
V_19 = F_184 ( V_132 ) ;
if ( V_19 == 0 )
V_132 -> V_120 = true ;
F_13 ( V_132 ) ;
if ( V_132 -> V_46 ) {
V_132 -> V_47 = false ;
F_32 ( & V_132 -> V_95 , 1 ) ;
}
if ( ! V_132 -> V_75 ) {
V_132 -> V_245 = F_214 ( L_124 ,
V_132 -> V_109 ) ;
if ( ! V_132 -> V_245 ) {
F_112 (KERN_ERR PFX
L_125 ) ;
goto V_320;
}
V_132 -> V_75 = & V_132 -> V_245 -> V_75 ;
V_132 -> V_75 -> V_330 = & V_331 . V_330 ;
V_19 = F_215 ( V_132 -> V_245 ) ;
if ( V_19 ) {
F_112 (KERN_ERR PFX
L_126
L_127 ,
rv) ;
goto V_320;
}
V_132 -> V_332 = true ;
}
V_19 = F_216 ( & V_26 ,
V_132 ,
& V_132 -> V_286 ,
V_132 -> V_75 ,
V_132 -> V_190 ) ;
if ( V_19 ) {
F_144 ( V_132 -> V_75 , L_128 ,
V_19 ) ;
goto V_333;
}
V_19 = F_217 ( V_132 -> V_11 , L_129 ,
& V_334 ,
V_132 ) ;
if ( V_19 ) {
F_144 ( V_132 -> V_75 , L_130 , V_19 ) ;
goto V_333;
}
V_19 = F_217 ( V_132 -> V_11 , L_131 ,
& V_335 ,
V_132 ) ;
if ( V_19 ) {
F_144 ( V_132 -> V_75 , L_130 , V_19 ) ;
goto V_333;
}
V_19 = F_217 ( V_132 -> V_11 , L_132 ,
& V_336 ,
V_132 ) ;
if ( V_19 ) {
F_144 ( V_132 -> V_75 , L_130 , V_19 ) ;
goto V_333;
}
F_73 ( V_132 -> V_75 , L_133 ,
V_291 [ V_132 -> V_79 ] ) ;
return 0 ;
V_333:
F_205 ( V_132 ) ;
V_320:
V_132 -> V_47 = true ;
if ( V_132 -> V_11 ) {
T_3 V_11 = V_132 -> V_11 ;
V_132 -> V_11 = NULL ;
F_218 ( V_11 ) ;
}
if ( V_132 -> V_144 ) {
V_132 -> V_144 ( V_132 ) ;
V_132 -> V_144 = NULL ;
}
F_219 () ;
if ( V_132 -> V_28 ) {
if ( V_132 -> V_26 )
V_132 -> V_26 -> V_337 ( V_132 -> V_28 ) ;
F_121 ( V_132 -> V_28 ) ;
V_132 -> V_28 = NULL ;
}
if ( V_132 -> V_258 ) {
V_132 -> V_258 ( V_132 ) ;
V_132 -> V_258 = NULL ;
}
if ( V_132 -> V_156 ) {
V_132 -> V_156 ( V_132 ) ;
V_132 -> V_156 = NULL ;
}
if ( V_132 -> V_332 ) {
F_220 ( V_132 -> V_245 ) ;
V_132 -> V_332 = false ;
}
return V_19 ;
}
static int F_221 ( void )
{
int V_166 ;
char * V_172 ;
int V_19 ;
struct V_9 * V_191 ;
enum V_338 type = V_339 ;
if ( V_340 )
return 0 ;
V_340 = 1 ;
if ( V_341 ) {
V_19 = F_222 ( & V_331 ) ;
if ( V_19 ) {
F_112 (KERN_ERR PFX L_134
L_135 , rv) ;
return V_19 ;
}
}
V_172 = V_342 ;
if ( * V_172 != '\0' ) {
for ( V_166 = 0 ; ( V_166 < V_195 ) && ( * V_172 != '\0' ) ; V_166 ++ ) {
V_79 [ V_166 ] = V_172 ;
V_172 = strchr ( V_172 , ',' ) ;
if ( V_172 ) {
* V_172 = '\0' ;
V_172 ++ ;
} else {
break;
}
}
}
F_112 ( V_343 L_136 ) ;
if ( ! F_127 () )
return 0 ;
#ifdef F_223
if ( V_344 ) {
V_19 = F_224 ( & V_345 ) ;
if ( V_19 )
F_112 (KERN_ERR PFX L_134
L_137 , rv) ;
else
V_346 = true ;
}
#endif
#ifdef F_225
if ( V_347 )
F_139 () ;
#endif
#ifdef F_226
if ( V_348 )
F_135 () ;
#endif
#ifdef F_227
F_228 ( & V_349 ) ;
V_350 = true ;
V_351 = 0 ;
#endif
F_124 ( & V_193 ) ;
F_212 (e, &smi_infos, link) {
if ( V_191 -> V_46 && ( ! type || V_191 -> V_139 == type ) ) {
if ( ! F_122 ( V_191 ) ) {
type = V_191 -> V_139 ;
}
}
}
if ( type ) {
F_126 ( & V_193 ) ;
return 0 ;
}
F_212 (e, &smi_infos, link) {
if ( ! V_191 -> V_46 && ( ! type || V_191 -> V_139 == type ) ) {
if ( ! F_122 ( V_191 ) ) {
type = V_191 -> V_139 ;
}
}
}
F_126 ( & V_193 ) ;
if ( type )
return 0 ;
if ( V_351 ) {
F_124 ( & V_193 ) ;
if ( F_229 ( & V_322 ) ) {
F_126 ( & V_193 ) ;
F_208 () ;
} else
F_126 ( & V_193 ) ;
}
F_124 ( & V_193 ) ;
if ( V_352 && F_229 ( & V_322 ) ) {
F_126 ( & V_193 ) ;
F_230 () ;
F_112 (KERN_WARNING PFX
L_138 ) ;
return - V_155 ;
} else {
F_126 ( & V_193 ) ;
return 0 ;
}
}
static void F_123 ( struct V_9 * V_353 )
{
int V_19 = 0 ;
if ( ! V_353 )
return;
if ( V_353 -> V_11 ) {
T_3 V_11 = V_353 -> V_11 ;
V_353 -> V_11 = NULL ;
V_19 = F_218 ( V_11 ) ;
if ( V_19 ) {
F_231 ( V_269 L_139 ,
V_19 ) ;
}
}
if ( V_353 -> V_75 )
F_160 ( V_353 -> V_75 , NULL ) ;
F_232 ( & V_353 -> V_321 ) ;
if ( V_353 -> V_144 )
V_353 -> V_144 ( V_353 ) ;
F_205 ( V_353 ) ;
while ( V_353 -> V_13 || ( V_353 -> V_32 != V_48 ) ) {
F_54 ( V_353 ) ;
F_175 ( 1 ) ;
}
F_18 ( V_353 ) ;
while ( V_353 -> V_13 || ( V_353 -> V_32 != V_48 ) ) {
F_54 ( V_353 ) ;
F_175 ( 1 ) ;
}
if ( V_353 -> V_26 )
V_353 -> V_26 -> V_337 ( V_353 -> V_28 ) ;
F_121 ( V_353 -> V_28 ) ;
if ( V_353 -> V_258 )
V_353 -> V_258 ( V_353 ) ;
if ( V_353 -> V_156 )
V_353 -> V_156 ( V_353 ) ;
if ( V_353 -> V_332 )
F_220 ( V_353 -> V_245 ) ;
F_121 ( V_353 ) ;
}
static void F_230 ( void )
{
struct V_9 * V_191 , * V_192 ;
if ( ! V_340 )
return;
#ifdef F_223
if ( V_346 )
F_233 ( & V_345 ) ;
#endif
#ifdef F_227
if ( V_350 )
F_234 ( & V_349 ) ;
#endif
F_235 ( & V_331 ) ;
F_124 ( & V_193 ) ;
F_125 (e, tmp_e, &smi_infos, link)
F_123 ( V_191 ) ;
F_126 ( & V_193 ) ;
}
