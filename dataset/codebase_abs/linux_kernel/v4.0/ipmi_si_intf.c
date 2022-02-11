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
if ( ( V_9 -> V_46 && ! V_9 -> V_47 ) ||
V_9 -> V_61 )
V_58 |= V_62 ;
if ( V_9 -> V_59 &&
V_9 -> V_46 && ! V_9 -> V_47 )
V_58 |= V_63 ;
* V_57 = V_58 & ( V_63 | V_62 ) ;
return V_58 ;
}
static void F_26 ( struct V_9 * V_9 , bool V_57 )
{
T_1 V_64 = V_9 -> V_65 . V_66 ( & V_9 -> V_65 , V_67 ) ;
V_64 &= V_68 ;
if ( ( bool ) V_64 == V_57 )
return;
if ( V_57 )
V_9 -> V_65 . V_69 ( & V_9 -> V_65 , V_67 ,
V_68 ) ;
else
V_9 -> V_65 . V_69 ( & V_9 -> V_65 , V_67 , 0 ) ;
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
= V_9 -> V_26 -> V_70 (
V_9 -> V_28 ,
V_9 -> V_13 -> V_15 ,
V_71 ) ;
V_1 = V_9 -> V_13 ;
V_9 -> V_13 = NULL ;
F_6 ( V_9 , V_1 ) ;
break;
case V_72 :
{
unsigned char V_1 [ 4 ] ;
unsigned int V_73 ;
V_73 = V_9 -> V_26 -> V_70 ( V_9 -> V_28 , V_1 , 4 ) ;
if ( V_1 [ 2 ] != 0 ) {
V_9 -> V_32 = V_48 ;
} else if ( V_73 < 4 ) {
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
V_9 -> V_26 -> V_70 ( V_9 -> V_28 , V_1 , 3 ) ;
if ( V_1 [ 2 ] != 0 ) {
F_28 ( V_9 -> V_74 ,
L_4 , V_1 [ 2 ] ) ;
}
V_9 -> V_32 = V_48 ;
break;
}
case V_40 :
{
V_9 -> V_13 -> V_17
= V_9 -> V_26 -> V_70 (
V_9 -> V_28 ,
V_9 -> V_13 -> V_15 ,
V_71 ) ;
V_1 = V_9 -> V_13 ;
V_9 -> V_13 = NULL ;
if ( V_1 -> V_15 [ 2 ] != 0 ) {
V_1 -> V_75 ( V_1 ) ;
V_9 -> V_50 &= ~ V_53 ;
F_22 ( V_9 ) ;
} else {
F_23 ( V_9 , V_76 ) ;
F_22 ( V_9 ) ;
F_6 ( V_9 , V_1 ) ;
}
break;
}
case V_38 :
{
V_9 -> V_13 -> V_17
= V_9 -> V_26 -> V_70 (
V_9 -> V_28 ,
V_9 -> V_13 -> V_15 ,
V_71 ) ;
V_1 = V_9 -> V_13 ;
V_9 -> V_13 = NULL ;
if ( V_1 -> V_15 [ 2 ] != 0 ) {
V_1 -> V_75 ( V_1 ) ;
V_9 -> V_50 &= ~ V_52 ;
F_22 ( V_9 ) ;
} else {
F_23 ( V_9 , V_77 ) ;
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
V_9 -> V_26 -> V_70 ( V_9 -> V_28 , V_1 , 4 ) ;
if ( V_1 [ 2 ] != 0 ) {
F_28 ( V_9 -> V_74 ,
L_5 , V_1 [ 2 ] ) ;
F_28 ( V_9 -> V_74 ,
L_6 ) ;
V_9 -> V_32 = V_48 ;
break;
}
V_58 = F_25 ( V_9 , 0 , & V_57 ) ;
if ( V_9 -> V_78 == V_79 )
F_26 ( V_9 , V_57 ) ;
if ( V_58 != ( V_1 [ 3 ] & V_80 ) ) {
V_1 [ 0 ] = ( V_30 << 2 ) ;
V_1 [ 1 ] = V_81 ;
V_1 [ 2 ] = V_58 | ( V_1 [ 3 ] & ~ V_80 ) ;
V_9 -> V_26 -> V_27 (
V_9 -> V_28 , V_1 , 3 ) ;
V_9 -> V_32 = V_82 ;
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
case V_82 :
{
unsigned char V_1 [ 4 ] ;
V_9 -> V_26 -> V_70 ( V_9 -> V_28 , V_1 , 4 ) ;
if ( V_1 [ 2 ] != 0 )
F_28 ( V_9 -> V_74 ,
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
V_83:
V_18 = V_9 -> V_26 -> V_84 ( V_9 -> V_28 , time ) ;
time = 0 ;
while ( V_18 == V_24 )
V_18 = V_9 -> V_26 -> V_84 ( V_9 -> V_28 , 0 ) ;
if ( V_18 == V_85 ) {
F_23 ( V_9 , V_86 ) ;
F_27 ( V_9 ) ;
V_18 = V_9 -> V_26 -> V_84 ( V_9 -> V_28 , 0 ) ;
} else if ( V_18 == V_87 ) {
F_23 ( V_9 , V_88 ) ;
V_9 -> V_32 = V_48 ;
if ( V_9 -> V_13 != NULL ) {
F_9 ( V_9 , V_14 ) ;
}
V_18 = V_9 -> V_26 -> V_84 ( V_9 -> V_28 , 0 ) ;
}
if ( F_30 ( V_9 -> V_11 ) &&
( V_18 == V_89 || V_9 -> V_90 ) ) {
unsigned char V_1 [ 2 ] ;
if ( V_9 -> V_32 != V_48 ) {
V_9 -> V_90 = true ;
} else {
V_9 -> V_90 = false ;
F_23 ( V_9 , V_91 ) ;
V_1 [ 0 ] = ( V_30 << 2 ) ;
V_1 [ 1 ] = V_92 ;
V_9 -> V_26 -> V_27 (
V_9 -> V_28 , V_1 , 2 ) ;
V_9 -> V_32 = V_72 ;
goto V_83;
}
}
if ( V_18 == V_21 ) {
F_23 ( V_9 , V_93 ) ;
V_18 = F_10 ( V_9 ) ;
if ( V_18 != V_21 )
goto V_83;
}
if ( ( V_18 == V_21 )
&& ( F_31 ( & V_9 -> V_94 ) ) ) {
F_32 ( & V_9 -> V_94 , 0 ) ;
if ( V_9 -> V_59 || V_9 -> V_46 ) {
F_12 ( V_9 ) ;
} else {
V_9 -> V_13 = F_20 ( V_9 ) ;
if ( ! V_9 -> V_13 )
goto V_25;
F_15 ( V_9 ) ;
}
goto V_83;
}
V_25:
return V_18 ;
}
static void F_33 ( struct V_9 * V_9 )
{
if ( V_9 -> V_32 == V_48 && V_9 -> V_13 == NULL ) {
F_16 ( V_9 , V_43 + V_95 ) ;
if ( V_9 -> V_96 )
F_34 ( V_9 -> V_96 ) ;
F_10 ( V_9 ) ;
F_29 ( V_9 , 0 ) ;
}
}
static void F_35 ( void * V_97 ,
struct V_10 * V_1 )
{
struct V_9 * V_9 = V_97 ;
enum V_18 V_98 ;
unsigned long V_99 ;
F_1 ( L_8 ) ;
if ( V_9 -> V_100 ) {
V_9 -> V_13 = V_1 ;
V_9 -> V_20 = NULL ;
V_98 = F_29 ( V_9 , 0 ) ;
while ( V_98 != V_21 ) {
F_36 ( V_101 ) ;
V_98 = F_29 ( V_9 ,
V_101 ) ;
}
return;
}
F_37 ( & V_9 -> V_102 , V_99 ) ;
F_38 ( V_9 -> V_20 ) ;
V_9 -> V_20 = V_1 ;
F_33 ( V_9 ) ;
F_39 ( & V_9 -> V_102 , V_99 ) ;
}
static void F_40 ( void * V_97 , bool V_103 )
{
struct V_9 * V_9 = V_97 ;
enum V_18 V_98 ;
V_9 -> V_100 = V_103 ;
if ( V_103 ) {
V_98 = F_29 ( V_9 , 0 ) ;
while ( V_98 != V_21 ) {
F_36 ( V_101 ) ;
V_98 = F_29 ( V_9 ,
V_101 ) ;
}
}
}
static inline void F_41 ( struct V_2 * V_104 )
{
V_104 -> V_5 = - 1 ;
}
static inline int F_42 ( struct V_2 * V_104 )
{
return V_104 -> V_5 != - 1 ;
}
static inline int F_43 ( enum V_18 V_105 ,
const struct V_9 * V_9 ,
struct V_2 * V_106 )
{
unsigned int V_107 = 0 ;
if ( V_9 -> V_108 < V_109 )
V_107 = V_110 [ V_9 -> V_108 ] ;
if ( V_107 == 0 || V_105 != V_111 )
F_41 ( V_106 ) ;
else if ( ! F_42 ( V_106 ) ) {
F_2 ( V_106 ) ;
F_44 ( V_106 , V_107 * V_112 ) ;
} else {
struct V_2 V_113 ;
F_2 ( & V_113 ) ;
if ( F_45 ( F_46 ( & V_113 , V_106 ) > 0 ) ) {
F_41 ( V_106 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_47 ( void * V_16 )
{
struct V_9 * V_9 = V_16 ;
unsigned long V_99 ;
enum V_18 V_105 ;
struct V_2 V_106 ;
F_41 ( & V_106 ) ;
F_48 ( V_114 , V_115 ) ;
while ( ! F_49 () ) {
int V_116 ;
F_37 ( & ( V_9 -> V_102 ) , V_99 ) ;
V_105 = F_29 ( V_9 , 0 ) ;
if ( V_105 != V_21 && ! V_9 -> V_45 )
F_16 ( V_9 , V_43 + V_95 ) ;
F_39 ( & ( V_9 -> V_102 ) , V_99 ) ;
V_116 = F_43 ( V_105 , V_9 ,
& V_106 ) ;
if ( V_105 == V_24 )
;
else if ( V_105 == V_111 && V_116 )
F_50 () ;
else if ( V_105 == V_21 ) {
if ( F_31 ( & V_9 -> V_117 ) ) {
F_51 ( 100 ) ;
} else {
F_52 ( V_118 ) ;
F_50 () ;
}
} else
F_51 ( 1 ) ;
}
return 0 ;
}
static void F_53 ( void * V_97 )
{
struct V_9 * V_9 = V_97 ;
unsigned long V_99 = 0 ;
bool V_100 = V_9 -> V_100 ;
F_36 ( 10 ) ;
if ( ! V_100 )
F_37 ( & V_9 -> V_102 , V_99 ) ;
F_29 ( V_9 , 10 ) ;
if ( ! V_100 )
F_39 ( & V_9 -> V_102 , V_99 ) ;
}
static void F_54 ( void * V_97 )
{
struct V_9 * V_9 = V_97 ;
if ( ! V_9 -> V_119 )
return;
F_32 ( & V_9 -> V_94 , 1 ) ;
}
static void F_55 ( void * V_97 , bool V_120 )
{
struct V_9 * V_9 = V_97 ;
unsigned long V_99 ;
F_32 ( & V_9 -> V_117 , V_120 ) ;
F_37 ( & V_9 -> V_102 , V_99 ) ;
F_33 ( V_9 ) ;
F_39 ( & V_9 -> V_102 , V_99 ) ;
}
static void F_56 ( unsigned long V_16 )
{
struct V_9 * V_9 = (struct V_9 * ) V_16 ;
enum V_18 V_105 ;
unsigned long V_99 ;
unsigned long V_121 ;
long V_122 ;
long V_123 ;
F_37 ( & ( V_9 -> V_102 ) , V_99 ) ;
F_1 ( L_9 ) ;
V_121 = V_43 ;
V_122 = ( ( ( long ) V_121 - ( long ) V_9 -> V_42 )
* V_124 ) ;
V_105 = F_29 ( V_9 , V_122 ) ;
if ( ( V_9 -> V_46 ) && ( ! V_9 -> V_47 ) ) {
V_123 = V_43 + V_95 ;
F_23 ( V_9 , V_125 ) ;
goto V_126;
}
if ( V_105 == V_111 ) {
F_23 ( V_9 , V_127 ) ;
V_123 = V_43 + 1 ;
} else {
F_23 ( V_9 , V_125 ) ;
V_123 = V_43 + V_95 ;
}
V_126:
if ( V_105 != V_21 )
F_16 ( V_9 , V_123 ) ;
else
V_9 -> V_45 = false ;
F_39 ( & ( V_9 -> V_102 ) , V_99 ) ;
}
static T_2 F_57 ( int V_46 , void * V_16 )
{
struct V_9 * V_9 = V_16 ;
unsigned long V_99 ;
F_37 ( & ( V_9 -> V_102 ) , V_99 ) ;
F_23 ( V_9 , V_128 ) ;
F_1 ( L_10 ) ;
F_29 ( V_9 , 0 ) ;
F_39 ( & ( V_9 -> V_102 ) , V_99 ) ;
return V_129 ;
}
static T_2 F_58 ( int V_46 , void * V_16 )
{
struct V_9 * V_9 = V_16 ;
V_9 -> V_65 . V_69 ( & V_9 -> V_65 , V_67 ,
V_130
| V_68 ) ;
return F_57 ( V_46 , V_16 ) ;
}
static int F_59 ( void * V_97 ,
T_3 V_11 )
{
struct V_9 * V_131 = V_97 ;
int V_120 = 0 ;
V_131 -> V_11 = V_11 ;
if ( V_131 -> V_132 )
V_131 -> V_132 ( V_131 ) ;
F_60 ( & V_131 -> V_44 , F_56 , ( long ) V_131 ) ;
F_16 ( V_131 , V_43 + V_95 ) ;
if ( V_131 -> V_108 < V_133 )
V_120 = V_134 [ V_131 -> V_108 ] ;
else if ( ( V_131 -> V_78 != V_79 ) && ( ! V_131 -> V_46 ) )
V_120 = 1 ;
if ( V_120 ) {
V_131 -> V_96 = F_61 ( F_47 , V_131 ,
L_11 , V_131 -> V_108 ) ;
if ( F_62 ( V_131 -> V_96 ) ) {
F_63 ( V_131 -> V_74 , L_12
L_13
L_14 ,
F_64 ( V_131 -> V_96 ) ) ;
V_131 -> V_96 = NULL ;
}
}
return 0 ;
}
static int F_65 ( void * V_97 , struct V_135 * V_16 )
{
struct V_9 * V_136 = V_97 ;
V_16 -> V_137 = V_136 -> V_138 ;
V_16 -> V_74 = V_136 -> V_74 ;
V_16 -> V_139 = V_136 -> V_139 ;
F_66 ( V_136 -> V_74 ) ;
return 0 ;
}
static void F_67 ( void * V_97 , bool V_120 )
{
struct V_9 * V_9 = V_97 ;
if ( ! V_120 )
F_32 ( & V_9 -> V_94 , 0 ) ;
}
static void F_68 ( struct V_9 * V_140 )
{
if ( V_140 -> V_78 == V_79 )
V_140 -> V_65 . V_69 ( & V_140 -> V_65 , V_67 , 0 ) ;
F_69 ( V_140 -> V_46 , V_140 ) ;
}
static int F_70 ( struct V_9 * V_140 )
{
int V_19 ;
if ( ! V_140 -> V_46 )
return 0 ;
if ( V_140 -> V_78 == V_79 ) {
V_19 = F_71 ( V_140 -> V_46 ,
F_58 ,
V_141 ,
V_142 ,
V_140 ) ;
if ( ! V_19 )
V_140 -> V_65 . V_69 ( & V_140 -> V_65 , V_67 ,
V_68 ) ;
} else
V_19 = F_71 ( V_140 -> V_46 ,
F_57 ,
V_141 ,
V_142 ,
V_140 ) ;
if ( V_19 ) {
F_28 ( V_140 -> V_74 , L_15
L_16 ,
V_142 , V_140 -> V_46 ) ;
V_140 -> V_46 = 0 ;
} else {
V_140 -> V_143 = F_68 ;
F_72 ( V_140 -> V_74 , L_17 , V_140 -> V_46 ) ;
}
return V_19 ;
}
static unsigned char F_73 ( struct V_144 * V_65 , unsigned int V_145 )
{
unsigned int V_146 = V_65 -> V_147 ;
return F_74 ( V_146 + ( V_145 * V_65 -> V_148 ) ) ;
}
static void F_75 ( struct V_144 * V_65 , unsigned int V_145 ,
unsigned char V_149 )
{
unsigned int V_146 = V_65 -> V_147 ;
F_76 ( V_149 , V_146 + ( V_145 * V_65 -> V_148 ) ) ;
}
static unsigned char F_77 ( struct V_144 * V_65 , unsigned int V_145 )
{
unsigned int V_146 = V_65 -> V_147 ;
return ( F_78 ( V_146 + ( V_145 * V_65 -> V_148 ) ) >> V_65 -> V_150 ) & 0xff ;
}
static void F_79 ( struct V_144 * V_65 , unsigned int V_145 ,
unsigned char V_149 )
{
unsigned int V_146 = V_65 -> V_147 ;
F_80 ( V_149 << V_65 -> V_150 , V_146 + ( V_145 * V_65 -> V_148 ) ) ;
}
static unsigned char F_81 ( struct V_144 * V_65 , unsigned int V_145 )
{
unsigned int V_146 = V_65 -> V_147 ;
return ( F_82 ( V_146 + ( V_145 * V_65 -> V_148 ) ) >> V_65 -> V_150 ) & 0xff ;
}
static void F_83 ( struct V_144 * V_65 , unsigned int V_145 ,
unsigned char V_149 )
{
unsigned int V_146 = V_65 -> V_147 ;
F_84 ( V_149 << V_65 -> V_150 , V_146 + ( V_145 * V_65 -> V_148 ) ) ;
}
static void F_85 ( struct V_9 * V_140 )
{
unsigned int V_146 = V_140 -> V_65 . V_147 ;
int V_151 ;
if ( V_146 ) {
for ( V_151 = 0 ; V_151 < V_140 -> V_152 ; V_151 ++ )
F_86 ( V_146 + V_151 * V_140 -> V_65 . V_148 ,
V_140 -> V_65 . V_153 ) ;
}
}
static int F_87 ( struct V_9 * V_140 )
{
unsigned int V_146 = V_140 -> V_65 . V_147 ;
int V_151 ;
if ( ! V_146 )
return - V_154 ;
V_140 -> V_155 = F_85 ;
switch ( V_140 -> V_65 . V_153 ) {
case 1 :
V_140 -> V_65 . V_66 = F_73 ;
V_140 -> V_65 . V_69 = F_75 ;
break;
case 2 :
V_140 -> V_65 . V_66 = F_77 ;
V_140 -> V_65 . V_69 = F_79 ;
break;
case 4 :
V_140 -> V_65 . V_66 = F_81 ;
V_140 -> V_65 . V_69 = F_83 ;
break;
default:
F_28 ( V_140 -> V_74 , L_18 ,
V_140 -> V_65 . V_153 ) ;
return - V_156 ;
}
for ( V_151 = 0 ; V_151 < V_140 -> V_152 ; V_151 ++ ) {
if ( F_88 ( V_146 + V_151 * V_140 -> V_65 . V_148 ,
V_140 -> V_65 . V_153 , V_142 ) == NULL ) {
while ( V_151 -- ) {
F_86 ( V_146 + V_151 * V_140 -> V_65 . V_148 ,
V_140 -> V_65 . V_153 ) ;
}
return - V_157 ;
}
}
return 0 ;
}
static unsigned char F_89 ( struct V_144 * V_65 , unsigned int V_145 )
{
return F_90 ( ( V_65 -> V_146 ) + ( V_145 * V_65 -> V_148 ) ) ;
}
static void F_91 ( struct V_144 * V_65 , unsigned int V_145 ,
unsigned char V_149 )
{
F_92 ( V_149 , ( V_65 -> V_146 ) + ( V_145 * V_65 -> V_148 ) ) ;
}
static unsigned char F_93 ( struct V_144 * V_65 , unsigned int V_145 )
{
return ( F_94 ( ( V_65 -> V_146 ) + ( V_145 * V_65 -> V_148 ) ) >> V_65 -> V_150 )
& 0xff ;
}
static void F_95 ( struct V_144 * V_65 , unsigned int V_145 ,
unsigned char V_149 )
{
F_92 ( V_149 << V_65 -> V_150 , ( V_65 -> V_146 ) + ( V_145 * V_65 -> V_148 ) ) ;
}
static unsigned char F_96 ( struct V_144 * V_65 , unsigned int V_145 )
{
return ( F_97 ( ( V_65 -> V_146 ) + ( V_145 * V_65 -> V_148 ) ) >> V_65 -> V_150 )
& 0xff ;
}
static void F_98 ( struct V_144 * V_65 , unsigned int V_145 ,
unsigned char V_149 )
{
F_99 ( V_149 << V_65 -> V_150 , ( V_65 -> V_146 ) + ( V_145 * V_65 -> V_148 ) ) ;
}
static unsigned char F_100 ( struct V_144 * V_65 , unsigned int V_145 )
{
return ( F_101 ( ( V_65 -> V_146 ) + ( V_145 * V_65 -> V_148 ) ) >> V_65 -> V_150 )
& 0xff ;
}
static void F_102 ( struct V_144 * V_65 , unsigned int V_145 ,
unsigned char V_149 )
{
F_103 ( V_149 << V_65 -> V_150 , ( V_65 -> V_146 ) + ( V_145 * V_65 -> V_148 ) ) ;
}
static void F_104 ( struct V_9 * V_140 )
{
unsigned long V_146 = V_140 -> V_65 . V_147 ;
int V_158 ;
if ( V_140 -> V_65 . V_146 ) {
F_105 ( V_140 -> V_65 . V_146 ) ;
V_158 = ( ( V_140 -> V_152 * V_140 -> V_65 . V_148 )
- ( V_140 -> V_65 . V_148 - V_140 -> V_65 . V_153 ) ) ;
F_106 ( V_146 , V_158 ) ;
}
}
static int F_107 ( struct V_9 * V_140 )
{
unsigned long V_146 = V_140 -> V_65 . V_147 ;
int V_158 ;
if ( ! V_146 )
return - V_154 ;
V_140 -> V_155 = F_104 ;
switch ( V_140 -> V_65 . V_153 ) {
case 1 :
V_140 -> V_65 . V_66 = F_89 ;
V_140 -> V_65 . V_69 = F_91 ;
break;
case 2 :
V_140 -> V_65 . V_66 = F_93 ;
V_140 -> V_65 . V_69 = F_95 ;
break;
case 4 :
V_140 -> V_65 . V_66 = F_96 ;
V_140 -> V_65 . V_69 = F_98 ;
break;
#ifdef F_101
case 8 :
V_140 -> V_65 . V_66 = F_100 ;
V_140 -> V_65 . V_69 = F_102 ;
break;
#endif
default:
F_28 ( V_140 -> V_74 , L_18 ,
V_140 -> V_65 . V_153 ) ;
return - V_156 ;
}
V_158 = ( ( V_140 -> V_152 * V_140 -> V_65 . V_148 )
- ( V_140 -> V_65 . V_148 - V_140 -> V_65 . V_153 ) ) ;
if ( F_108 ( V_146 , V_158 , V_142 ) == NULL )
return - V_157 ;
V_140 -> V_65 . V_146 = F_109 ( V_146 , V_158 ) ;
if ( V_140 -> V_65 . V_146 == NULL ) {
F_106 ( V_146 , V_158 ) ;
return - V_157 ;
}
return 0 ;
}
static int F_110 ( struct V_159 * V_160 , int * V_161 , char * V_162 , char * * V_163 )
{
char * V_164 ;
int V_165 ;
V_164 = strchr ( * V_163 , ',' ) ;
if ( ! V_164 ) {
F_111 (KERN_WARNING PFX L_19 , name) ;
return - V_156 ;
}
* V_164 = '\0' ;
V_164 ++ ;
for ( V_165 = 0 ; V_160 [ V_165 ] . V_162 ; V_165 ++ ) {
if ( strcmp ( * V_163 , V_160 [ V_165 ] . V_162 ) == 0 ) {
* V_161 = V_160 [ V_165 ] . V_161 ;
* V_163 = V_164 ;
return 0 ;
}
}
F_111 (KERN_WARNING PFX L_20 , name, *curr) ;
return - V_156 ;
}
static int F_112 ( const char * V_163 , const char * V_166 ,
const char * V_162 , int * V_161 )
{
char * V_167 ;
if ( strcmp ( V_163 , V_162 ) == 0 ) {
if ( ! V_166 ) {
F_111 (KERN_WARNING PFX
L_21 ,
curr) ;
return - V_156 ;
}
* V_161 = F_113 ( V_166 , & V_167 , 0 ) ;
if ( ( * V_167 != '\0' ) || ( * V_166 == '\0' ) ) {
F_111 (KERN_WARNING PFX
L_22 ,
curr) ;
return - V_156 ;
}
return 1 ;
}
return 0 ;
}
static struct V_9 * F_114 ( void )
{
struct V_9 * V_140 = F_115 ( sizeof( * V_140 ) , V_168 ) ;
if ( V_140 )
F_116 ( & V_140 -> V_102 ) ;
return V_140 ;
}
static int F_117 ( const char * V_161 , struct V_169 * V_170 )
{
char * V_171 = F_118 ( V_161 , V_168 ) ;
int V_19 ;
char * V_172 , * V_163 , * V_164 , * V_167 , * V_173 ;
enum V_174 V_175 ;
enum V_78 V_78 ;
int V_176 ;
unsigned long V_146 ;
int V_148 ;
int V_153 ;
int V_150 ;
int V_46 ;
int V_177 ;
int V_178 ;
int V_73 ;
struct V_9 * V_140 ;
if ( ! V_171 )
return - V_179 ;
V_73 = strlen ( V_171 ) ;
V_178 = V_73 - 1 ;
while ( ( V_178 >= 0 ) && isspace ( V_171 [ V_178 ] ) ) {
V_171 [ V_178 ] = '\0' ;
V_178 -- ;
}
for ( V_163 = V_171 ; V_163 ; V_163 = V_172 ) {
V_148 = 1 ;
V_153 = 1 ;
V_150 = 0 ;
V_46 = 0 ;
V_177 = 0 ;
V_172 = strchr ( V_163 , ':' ) ;
if ( V_172 ) {
* V_172 = '\0' ;
V_172 ++ ;
}
V_19 = F_110 ( V_180 , & V_178 , L_23 , & V_163 ) ;
if ( V_19 )
break;
V_175 = V_178 ;
V_19 = F_110 ( V_181 , & V_178 , L_24 , & V_163 ) ;
if ( V_19 )
break;
V_78 = V_178 ;
V_19 = F_110 ( V_182 , & V_176 , L_25 , & V_163 ) ;
if ( V_19 )
break;
V_164 = strchr ( V_163 , ',' ) ;
if ( V_164 ) {
* V_164 = '\0' ;
V_164 ++ ;
}
V_146 = F_113 ( V_163 , & V_167 , 0 ) ;
if ( ( * V_167 != '\0' ) || ( * V_163 == '\0' ) ) {
F_111 (KERN_WARNING PFX L_26
L_27 , curr) ;
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
V_19 = F_112 ( V_163 , V_173 , L_28 , & V_148 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = F_112 ( V_163 , V_173 , L_29 , & V_153 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = F_112 ( V_163 , V_173 , L_30 , & V_150 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = F_112 ( V_163 , V_173 , L_31 , & V_46 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = F_112 ( V_163 , V_173 , L_32 , & V_177 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = - V_156 ;
F_111 (KERN_WARNING PFX
L_33 ,
curr) ;
goto V_25;
}
if ( V_175 == V_183 ) {
V_140 = F_114 () ;
if ( ! V_140 ) {
V_19 = - V_179 ;
goto V_25;
}
V_140 -> V_138 = V_184 ;
V_140 -> V_78 = V_78 ;
V_140 -> V_65 . V_147 = V_146 ;
V_140 -> V_65 . V_185 = V_176 ;
if ( V_176 == V_186 )
V_140 -> V_187 = F_107 ;
else
V_140 -> V_187 = F_87 ;
V_140 -> V_65 . V_146 = NULL ;
V_140 -> V_65 . V_148 = V_148 ;
if ( ! V_140 -> V_65 . V_148 )
V_140 -> V_65 . V_148 = V_188 ;
V_140 -> V_65 . V_153 = V_153 ;
if ( ! V_140 -> V_65 . V_153 )
V_140 -> V_65 . V_153 = V_188 ;
V_140 -> V_65 . V_150 = V_150 ;
V_140 -> V_46 = V_46 ;
if ( V_140 -> V_46 )
V_140 -> V_132 = F_70 ;
V_140 -> V_189 = V_177 ;
V_19 = F_119 ( V_140 ) ;
if ( V_19 ) {
F_120 ( V_140 ) ;
goto V_25;
}
V_19 = F_121 ( V_140 ) ;
if ( V_19 ) {
F_122 ( V_140 ) ;
goto V_25;
}
} else {
struct V_9 * V_190 , * V_191 ;
F_123 ( & V_192 ) ;
F_124 (e, tmp_e, &smi_infos, link) {
if ( V_190 -> V_65 . V_185 != V_176 )
continue;
if ( V_190 -> V_78 != V_78 )
continue;
if ( V_190 -> V_65 . V_147 == V_146 )
F_122 ( V_190 ) ;
}
F_125 ( & V_192 ) ;
}
}
V_19 = V_73 ;
V_25:
F_120 ( V_171 ) ;
return V_19 ;
}
static int F_126 ( void )
{
int V_193 = - V_154 ;
int V_165 ;
struct V_9 * V_140 ;
for ( V_165 = 0 ; V_165 < V_194 ; V_165 ++ ) {
if ( ! V_195 [ V_165 ] && ! V_196 [ V_165 ] )
continue;
V_140 = F_114 () ;
if ( ! V_140 )
return - V_179 ;
V_140 -> V_138 = V_197 ;
F_111 (KERN_INFO PFX L_34 ) ;
if ( ! V_78 [ V_165 ] || strcmp ( V_78 [ V_165 ] , L_35 ) == 0 ) {
V_140 -> V_78 = V_198 ;
} else if ( strcmp ( V_78 [ V_165 ] , L_36 ) == 0 ) {
V_140 -> V_78 = V_199 ;
} else if ( strcmp ( V_78 [ V_165 ] , L_37 ) == 0 ) {
V_140 -> V_78 = V_79 ;
} else {
F_111 (KERN_WARNING PFX L_38
L_39 ,
i, si_type[i]) ;
F_120 ( V_140 ) ;
continue;
}
if ( V_195 [ V_165 ] ) {
V_140 -> V_187 = F_87 ;
V_140 -> V_65 . V_147 = V_195 [ V_165 ] ;
V_140 -> V_65 . V_185 = V_200 ;
} else if ( V_196 [ V_165 ] ) {
V_140 -> V_187 = F_107 ;
V_140 -> V_65 . V_147 = V_196 [ V_165 ] ;
V_140 -> V_65 . V_185 = V_186 ;
} else {
F_111 (KERN_WARNING PFX L_38
L_40
L_41 , i) ;
F_120 ( V_140 ) ;
continue;
}
V_140 -> V_65 . V_146 = NULL ;
V_140 -> V_65 . V_148 = V_201 [ V_165 ] ;
if ( ! V_140 -> V_65 . V_148 )
V_140 -> V_65 . V_148 = V_188 ;
V_140 -> V_65 . V_153 = V_202 [ V_165 ] ;
if ( ! V_140 -> V_65 . V_153 )
V_140 -> V_65 . V_153 = V_188 ;
V_140 -> V_65 . V_150 = V_203 [ V_165 ] ;
V_140 -> V_46 = V_204 [ V_165 ] ;
if ( V_140 -> V_46 )
V_140 -> V_132 = F_70 ;
V_140 -> V_189 = V_205 [ V_165 ] ;
if ( ! F_119 ( V_140 ) ) {
if ( F_121 ( V_140 ) )
F_122 ( V_140 ) ;
V_193 = 0 ;
} else {
F_120 ( V_140 ) ;
}
}
return V_193 ;
}
static T_4 F_127 ( T_5 V_206 ,
T_4 V_207 , void * V_208 )
{
struct V_9 * V_9 = V_208 ;
unsigned long V_99 ;
F_37 ( & ( V_9 -> V_102 ) , V_99 ) ;
F_23 ( V_9 , V_128 ) ;
F_1 ( L_42 ) ;
F_29 ( V_9 , 0 ) ;
F_39 ( & ( V_9 -> V_102 ) , V_99 ) ;
return V_209 ;
}
static void F_128 ( struct V_9 * V_140 )
{
if ( ! V_140 -> V_46 )
return;
F_129 ( NULL , V_140 -> V_46 , & F_127 ) ;
}
static int F_130 ( struct V_9 * V_140 )
{
T_6 V_210 ;
if ( ! V_140 -> V_46 )
return 0 ;
V_210 = F_131 ( NULL ,
V_140 -> V_46 ,
V_211 ,
& F_127 ,
V_140 ) ;
if ( V_210 != V_212 ) {
F_28 ( V_140 -> V_74 , L_43
L_16 , V_142 , V_140 -> V_46 ) ;
V_140 -> V_46 = 0 ;
return - V_156 ;
} else {
V_140 -> V_143 = F_128 ;
F_72 ( V_140 -> V_74 , L_44 , V_140 -> V_46 ) ;
return 0 ;
}
}
static int F_132 ( struct V_213 * V_214 )
{
struct V_9 * V_140 ;
int V_19 ;
if ( V_214 -> V_215 != 1 ) {
F_111 (KERN_INFO PFX L_45 , spmi->IPMIlegacy) ;
return - V_154 ;
}
V_140 = F_114 () ;
if ( ! V_140 ) {
F_111 (KERN_ERR PFX L_46 ) ;
return - V_179 ;
}
V_140 -> V_138 = V_216 ;
F_111 (KERN_INFO PFX L_47 ) ;
switch ( V_214 -> V_217 ) {
case 1 :
V_140 -> V_78 = V_198 ;
break;
case 2 :
V_140 -> V_78 = V_199 ;
break;
case 3 :
V_140 -> V_78 = V_79 ;
break;
case 4 :
F_120 ( V_140 ) ;
return - V_157 ;
default:
F_111 (KERN_INFO PFX L_48 ,
spmi->InterfaceType) ;
F_120 ( V_140 ) ;
return - V_157 ;
}
if ( V_214 -> V_218 & 1 ) {
V_140 -> V_46 = V_214 -> V_219 ;
V_140 -> V_132 = F_130 ;
} else if ( V_214 -> V_218 & 2 ) {
V_140 -> V_46 = V_214 -> V_220 ;
V_140 -> V_132 = F_70 ;
} else {
V_140 -> V_46 = 0 ;
V_140 -> V_132 = NULL ;
}
if ( V_214 -> V_146 . V_221 ) {
V_140 -> V_65 . V_148 = V_214 -> V_146 . V_221 / 8 ;
} else {
V_140 -> V_65 . V_148 = V_188 ;
}
V_140 -> V_65 . V_153 = V_140 -> V_65 . V_148 ;
V_140 -> V_65 . V_150 = V_214 -> V_146 . V_222 ;
if ( V_214 -> V_146 . V_223 == V_224 ) {
V_140 -> V_187 = F_107 ;
V_140 -> V_65 . V_185 = V_186 ;
} else if ( V_214 -> V_146 . V_223 == V_225 ) {
V_140 -> V_187 = F_87 ;
V_140 -> V_65 . V_185 = V_200 ;
} else {
F_120 ( V_140 ) ;
F_111 (KERN_WARNING PFX L_49 ) ;
return - V_157 ;
}
V_140 -> V_65 . V_147 = V_214 -> V_146 . V_226 ;
F_133 ( L_50 ,
( V_140 -> V_65 . V_185 == V_200 ) ? L_51 : L_52 ,
V_140 -> V_65 . V_147 , V_140 -> V_65 . V_153 , V_140 -> V_65 . V_148 ,
V_140 -> V_46 ) ;
V_19 = F_119 ( V_140 ) ;
if ( V_19 )
F_120 ( V_140 ) ;
return V_19 ;
}
static void F_134 ( void )
{
T_6 V_210 ;
struct V_213 * V_214 ;
int V_165 ;
if ( V_227 )
return;
if ( V_228 )
return;
for ( V_165 = 0 ; ; V_165 ++ ) {
V_210 = F_135 ( V_229 , V_165 + 1 ,
(struct V_230 * * ) & V_214 ) ;
if ( V_210 != V_212 )
return;
F_132 ( V_214 ) ;
}
}
static int F_136 ( struct V_231 * V_74 ,
const struct V_232 * V_233 )
{
struct V_234 * V_235 ;
struct V_9 * V_140 ;
struct V_236 * V_237 , * V_238 ;
T_5 V_239 ;
T_6 V_210 ;
unsigned long long V_240 ;
int V_19 ;
V_235 = F_137 ( V_74 ) ;
if ( ! V_235 )
return - V_154 ;
V_140 = F_114 () ;
if ( ! V_140 )
return - V_179 ;
V_140 -> V_138 = V_241 ;
F_111 (KERN_INFO PFX L_53 ) ;
V_239 = V_235 -> V_239 ;
V_140 -> V_139 . V_242 . T_5 = V_239 ;
V_210 = F_138 ( V_239 , L_54 , NULL , & V_240 ) ;
if ( F_139 ( V_210 ) )
goto V_243;
switch ( V_240 ) {
case 1 :
V_140 -> V_78 = V_198 ;
break;
case 2 :
V_140 -> V_78 = V_199 ;
break;
case 3 :
V_140 -> V_78 = V_79 ;
break;
case 4 :
goto V_243;
default:
F_72 ( & V_74 -> V_74 , L_55 , V_240 ) ;
goto V_243;
}
V_237 = F_140 ( V_74 , V_244 , 0 ) ;
if ( V_237 ) {
V_140 -> V_187 = F_87 ;
V_140 -> V_65 . V_185 = V_200 ;
} else {
V_237 = F_140 ( V_74 , V_245 , 0 ) ;
if ( V_237 ) {
V_140 -> V_187 = F_107 ;
V_140 -> V_65 . V_185 = V_186 ;
}
}
if ( ! V_237 ) {
F_141 ( & V_74 -> V_74 , L_56 ) ;
goto V_243;
}
V_140 -> V_65 . V_147 = V_237 -> V_246 ;
V_140 -> V_65 . V_148 = V_188 ;
V_238 = F_140 ( V_74 ,
( V_140 -> V_65 . V_185 == V_200 ) ?
V_244 : V_245 ,
1 ) ;
if ( V_238 ) {
if ( V_238 -> V_246 > V_140 -> V_65 . V_147 )
V_140 -> V_65 . V_148 = V_238 -> V_246 - V_140 -> V_65 . V_147 ;
}
V_140 -> V_65 . V_153 = V_188 ;
V_140 -> V_65 . V_150 = 0 ;
V_210 = F_138 ( V_239 , L_57 , NULL , & V_240 ) ;
if ( F_142 ( V_210 ) ) {
V_140 -> V_46 = V_240 ;
V_140 -> V_132 = F_130 ;
} else if ( F_143 ( V_74 , 0 ) ) {
V_140 -> V_46 = F_144 ( V_74 , 0 ) ;
V_140 -> V_132 = F_70 ;
}
V_140 -> V_74 = & V_74 -> V_74 ;
F_145 ( V_74 , V_140 ) ;
F_72 ( V_140 -> V_74 , L_58 ,
V_237 , V_140 -> V_65 . V_153 , V_140 -> V_65 . V_148 ,
V_140 -> V_46 ) ;
V_19 = F_119 ( V_140 ) ;
if ( V_19 )
F_120 ( V_140 ) ;
return V_19 ;
V_243:
F_120 ( V_140 ) ;
return - V_156 ;
}
static void F_146 ( struct V_231 * V_74 )
{
struct V_9 * V_140 = F_147 ( V_74 ) ;
F_122 ( V_140 ) ;
}
static int F_148 ( const struct V_247 * V_248 ,
struct V_249 * V_250 )
{
const T_1 * V_16 = ( const T_1 * ) V_248 ;
unsigned long V_251 ;
T_1 V_252 ;
T_1 V_73 = V_248 -> V_253 ;
V_250 -> type = V_16 [ 4 ] ;
memcpy ( & V_251 , V_16 + 8 , sizeof( unsigned long ) ) ;
if ( V_73 >= 0x11 ) {
if ( V_251 & 1 ) {
V_251 &= 0xFFFE ;
V_250 -> V_176 = V_200 ;
} else
V_250 -> V_176 = V_186 ;
V_250 -> V_251 = V_251 | ( ( V_16 [ 0x10 ] & 0x10 ) >> 4 ) ;
V_250 -> V_46 = V_16 [ 0x11 ] ;
V_252 = ( V_16 [ 0x10 ] & 0xC0 ) >> 6 ;
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
return - V_157 ;
}
} else {
V_250 -> V_251 = V_251 & 0xfffe ;
V_250 -> V_176 = V_200 ;
V_250 -> V_145 = 1 ;
}
V_250 -> V_189 = V_16 [ 6 ] ;
return 0 ;
}
static void F_149 ( struct V_249 * V_254 )
{
struct V_9 * V_140 ;
V_140 = F_114 () ;
if ( ! V_140 ) {
F_111 (KERN_ERR PFX L_59 ) ;
return;
}
V_140 -> V_138 = V_255 ;
F_111 (KERN_INFO PFX L_60 ) ;
switch ( V_254 -> type ) {
case 0x01 :
V_140 -> V_78 = V_198 ;
break;
case 0x02 :
V_140 -> V_78 = V_199 ;
break;
case 0x03 :
V_140 -> V_78 = V_79 ;
break;
default:
F_120 ( V_140 ) ;
return;
}
switch ( V_254 -> V_176 ) {
case V_186 :
V_140 -> V_187 = F_107 ;
V_140 -> V_65 . V_185 = V_186 ;
break;
case V_200 :
V_140 -> V_187 = F_87 ;
V_140 -> V_65 . V_185 = V_200 ;
break;
default:
F_120 ( V_140 ) ;
F_111 (KERN_WARNING PFX L_61 ,
ipmi_data->addr_space) ;
return;
}
V_140 -> V_65 . V_147 = V_254 -> V_251 ;
V_140 -> V_65 . V_148 = V_254 -> V_145 ;
if ( ! V_140 -> V_65 . V_148 )
V_140 -> V_65 . V_148 = V_188 ;
V_140 -> V_65 . V_153 = V_188 ;
V_140 -> V_65 . V_150 = 0 ;
V_140 -> V_189 = V_254 -> V_189 ;
V_140 -> V_46 = V_254 -> V_46 ;
if ( V_140 -> V_46 )
V_140 -> V_132 = F_70 ;
F_133 ( L_62 ,
( V_140 -> V_65 . V_185 == V_200 ) ? L_51 : L_52 ,
V_140 -> V_65 . V_147 , V_140 -> V_65 . V_153 , V_140 -> V_65 . V_148 ,
V_140 -> V_46 ) ;
if ( F_119 ( V_140 ) )
F_120 ( V_140 ) ;
}
static void F_150 ( void )
{
const struct V_256 * V_74 = NULL ;
struct V_249 V_16 ;
int V_19 ;
while ( ( V_74 = F_151 ( V_257 , NULL , V_74 ) ) ) {
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_19 = F_148 ( ( const struct V_247 * ) V_74 -> V_258 ,
& V_16 ) ;
if ( ! V_19 )
F_149 ( & V_16 ) ;
}
}
static void F_152 ( struct V_9 * V_140 )
{
struct V_259 * V_260 = V_140 -> V_261 ;
F_153 ( V_260 ) ;
}
static int F_154 ( struct V_9 * V_140 )
{
if ( V_140 -> V_78 == V_198 ) {
unsigned char V_210 ;
int V_148 ;
V_140 -> V_65 . V_153 = V_262 ;
V_140 -> V_65 . V_150 = 0 ;
V_140 -> V_152 = 2 ;
V_140 -> V_26 = & V_263 ;
for ( V_148 = V_188 ; V_148 <= 16 ; ) {
V_140 -> V_65 . V_148 = V_148 ;
if ( V_140 -> V_187 ( V_140 ) ) {
F_141 ( V_140 -> V_74 ,
L_63 ) ;
return V_188 ;
}
V_140 -> V_65 . V_69 ( & V_140 -> V_65 , 1 , 0x10 ) ;
V_210 = V_140 -> V_65 . V_66 ( & V_140 -> V_65 , 1 ) ;
V_140 -> V_155 ( V_140 ) ;
if ( V_210 )
return V_148 ;
V_148 *= 4 ;
}
}
return V_188 ;
}
static int F_155 ( struct V_259 * V_260 ,
const struct V_264 * V_265 )
{
int V_19 ;
int V_266 = V_260 -> V_267 & V_268 ;
struct V_9 * V_140 ;
V_140 = F_114 () ;
if ( ! V_140 )
return - V_179 ;
V_140 -> V_138 = V_269 ;
F_72 ( & V_260 -> V_74 , L_64 ) ;
switch ( V_266 ) {
case V_270 :
V_140 -> V_78 = V_199 ;
break;
case V_271 :
V_140 -> V_78 = V_198 ;
break;
case V_272 :
V_140 -> V_78 = V_79 ;
break;
default:
F_120 ( V_140 ) ;
F_72 ( & V_260 -> V_74 , L_65 , V_266 ) ;
return - V_179 ;
}
V_19 = F_156 ( V_260 ) ;
if ( V_19 ) {
F_141 ( & V_260 -> V_74 , L_66 ) ;
F_120 ( V_140 ) ;
return V_19 ;
}
V_140 -> V_273 = F_152 ;
V_140 -> V_261 = V_260 ;
if ( F_157 ( V_260 , 0 ) & V_244 ) {
V_140 -> V_187 = F_87 ;
V_140 -> V_65 . V_185 = V_200 ;
} else {
V_140 -> V_187 = F_107 ;
V_140 -> V_65 . V_185 = V_186 ;
}
V_140 -> V_65 . V_147 = F_158 ( V_260 , 0 ) ;
V_140 -> V_65 . V_148 = F_154 ( V_140 ) ;
V_140 -> V_65 . V_153 = V_262 ;
V_140 -> V_65 . V_150 = 0 ;
V_140 -> V_46 = V_260 -> V_46 ;
if ( V_140 -> V_46 )
V_140 -> V_132 = F_70 ;
V_140 -> V_74 = & V_260 -> V_74 ;
F_159 ( V_260 , V_140 ) ;
F_72 ( & V_260 -> V_74 , L_58 ,
& V_260 -> V_236 [ 0 ] , V_140 -> V_65 . V_153 , V_140 -> V_65 . V_148 ,
V_140 -> V_46 ) ;
V_19 = F_119 ( V_140 ) ;
if ( V_19 ) {
F_120 ( V_140 ) ;
F_153 ( V_260 ) ;
}
return V_19 ;
}
static void F_160 ( struct V_259 * V_260 )
{
struct V_9 * V_140 = F_161 ( V_260 ) ;
F_122 ( V_140 ) ;
F_153 ( V_260 ) ;
}
static int F_162 ( struct V_274 * V_74 )
{
#ifdef F_163
const struct V_275 * V_276 ;
struct V_9 * V_140 ;
struct V_236 V_236 ;
const T_7 * V_153 , * V_148 , * V_150 ;
struct V_277 * V_278 = V_74 -> V_74 . V_279 ;
int V_193 ;
int V_280 ;
F_72 ( & V_74 -> V_74 , L_67 ) ;
V_276 = F_164 ( V_281 , & V_74 -> V_74 ) ;
if ( ! V_276 )
return - V_156 ;
if ( ! F_165 ( V_278 ) )
return - V_156 ;
V_193 = F_166 ( V_278 , 0 , & V_236 ) ;
if ( V_193 ) {
F_28 ( & V_74 -> V_74 , V_282 L_68 ) ;
return V_193 ;
}
V_153 = F_167 ( V_278 , L_69 , & V_280 ) ;
if ( V_153 && V_280 != 4 ) {
F_28 ( & V_74 -> V_74 , V_282 L_70 ) ;
return - V_156 ;
}
V_148 = F_167 ( V_278 , L_71 , & V_280 ) ;
if ( V_148 && V_280 != 4 ) {
F_28 ( & V_74 -> V_74 , V_282 L_72 ) ;
return - V_156 ;
}
V_150 = F_167 ( V_278 , L_73 , & V_280 ) ;
if ( V_150 && V_280 != 4 ) {
F_28 ( & V_74 -> V_74 , V_282 L_74 ) ;
return - V_156 ;
}
V_140 = F_114 () ;
if ( ! V_140 ) {
F_141 ( & V_74 -> V_74 ,
L_75 ) ;
return - V_179 ;
}
V_140 -> V_78 = (enum V_78 ) V_276 -> V_16 ;
V_140 -> V_138 = V_283 ;
V_140 -> V_132 = F_70 ;
if ( V_236 . V_99 & V_244 ) {
V_140 -> V_187 = F_87 ;
V_140 -> V_65 . V_185 = V_200 ;
} else {
V_140 -> V_187 = F_107 ;
V_140 -> V_65 . V_185 = V_186 ;
}
V_140 -> V_65 . V_147 = V_236 . V_246 ;
V_140 -> V_65 . V_153 = V_153 ? F_168 ( V_153 ) : V_262 ;
V_140 -> V_65 . V_148 = V_148 ? F_168 ( V_148 ) : V_188 ;
V_140 -> V_65 . V_150 = V_150 ? F_168 ( V_150 ) : 0 ;
V_140 -> V_46 = F_169 ( V_74 -> V_74 . V_279 , 0 ) ;
V_140 -> V_74 = & V_74 -> V_74 ;
F_170 ( & V_74 -> V_74 , L_76 ,
V_140 -> V_65 . V_147 , V_140 -> V_65 . V_153 , V_140 -> V_65 . V_148 ,
V_140 -> V_46 ) ;
F_171 ( & V_74 -> V_74 , V_140 ) ;
V_193 = F_119 ( V_140 ) ;
if ( V_193 ) {
F_120 ( V_140 ) ;
return V_193 ;
}
#endif
return 0 ;
}
static int F_172 ( struct V_274 * V_74 )
{
#ifdef F_163
F_122 ( F_173 ( & V_74 -> V_74 ) ) ;
#endif
return 0 ;
}
static int F_174 ( struct V_284 * V_74 )
{
struct V_9 * V_140 ;
int V_19 ;
V_140 = F_114 () ;
if ( ! V_140 ) {
F_141 ( & V_74 -> V_74 ,
L_77 ) ;
return - V_179 ;
}
V_140 -> V_78 = V_198 ;
V_140 -> V_138 = V_283 ;
V_140 -> V_187 = F_107 ;
V_140 -> V_65 . V_185 = V_186 ;
V_140 -> V_65 . V_147 = V_74 -> V_285 . V_246 ;
V_140 -> V_65 . V_153 = 1 ;
V_140 -> V_65 . V_148 = 1 ;
V_140 -> V_65 . V_150 = 0 ;
V_140 -> V_46 = 0 ;
V_140 -> V_132 = NULL ;
V_140 -> V_74 = & V_74 -> V_74 ;
F_170 ( & V_74 -> V_74 , L_78 , V_140 -> V_65 . V_147 ) ;
F_171 ( & V_74 -> V_74 , V_140 ) ;
V_19 = F_119 ( V_140 ) ;
if ( V_19 ) {
F_120 ( V_140 ) ;
return V_19 ;
}
return 0 ;
}
static int F_175 ( struct V_284 * V_74 )
{
F_122 ( F_173 ( & V_74 -> V_74 ) ) ;
return 0 ;
}
static int F_176 ( struct V_9 * V_9 )
{
enum V_18 V_105 ;
V_105 = V_9 -> V_26 -> V_84 ( V_9 -> V_28 , 0 ) ;
for (; ; ) {
if ( V_105 == V_111 ||
V_105 == V_286 ) {
F_177 ( 1 ) ;
V_105 = V_9 -> V_26 -> V_84 (
V_9 -> V_28 , F_178 ( 1 ) ) ;
} else if ( V_105 == V_24 ) {
V_105 = V_9 -> V_26 -> V_84 (
V_9 -> V_28 , 0 ) ;
} else
break;
}
if ( V_105 == V_87 )
return - V_154 ;
return 0 ;
}
static int F_179 ( struct V_9 * V_9 )
{
unsigned char V_1 [ 2 ] ;
unsigned char * V_287 ;
unsigned long V_288 ;
int V_19 = 0 ;
V_287 = F_180 ( V_71 , V_168 ) ;
if ( ! V_287 )
return - V_179 ;
V_1 [ 0 ] = V_30 << 2 ;
V_1 [ 1 ] = V_289 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 2 ) ;
V_19 = F_176 ( V_9 ) ;
if ( V_19 )
goto V_25;
V_288 = V_9 -> V_26 -> V_70 ( V_9 -> V_28 ,
V_287 , V_71 ) ;
V_19 = F_181 ( V_287 , V_288 , & V_9 -> V_290 ) ;
V_25:
F_120 ( V_287 ) ;
return V_19 ;
}
static void F_182 ( struct V_9 * V_9 )
{
unsigned char V_1 [ 3 ] ;
unsigned char * V_287 ;
unsigned long V_288 ;
int V_19 ;
V_287 = F_180 ( V_71 , V_168 ) ;
if ( ! V_287 ) {
F_111 (KERN_WARNING PFX L_79
L_80
L_81 ) ;
return;
}
V_1 [ 0 ] = V_30 << 2 ;
V_1 [ 1 ] = V_31 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 2 ) ;
V_19 = F_176 ( V_9 ) ;
if ( V_19 ) {
F_111 (KERN_WARNING PFX L_82
L_80
L_81 ) ;
goto V_25;
}
V_288 = V_9 -> V_26 -> V_70 ( V_9 -> V_28 ,
V_287 , V_71 ) ;
if ( V_288 < 4 ||
V_287 [ 0 ] != ( V_30 | 1 ) << 2 ||
V_287 [ 1 ] != V_31 ||
V_287 [ 2 ] != 0 ) {
F_111 (KERN_WARNING PFX L_83
L_84
L_81 ) ;
V_19 = - V_156 ;
goto V_25;
}
if ( ( V_287 [ 3 ] & V_62 ) == 0 )
goto V_25;
V_1 [ 0 ] = V_30 << 2 ;
V_1 [ 1 ] = V_81 ;
V_1 [ 2 ] = V_287 [ 3 ] & ~ V_62 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 3 ) ;
V_19 = F_176 ( V_9 ) ;
if ( V_19 ) {
F_111 (KERN_WARNING PFX L_85
L_80
L_81 ) ;
goto V_25;
}
V_288 = V_9 -> V_26 -> V_70 ( V_9 -> V_28 ,
V_287 , V_71 ) ;
if ( V_288 < 3 ||
V_287 [ 0 ] != ( V_30 | 1 ) << 2 ||
V_287 [ 1 ] != V_81 ) {
F_111 (KERN_WARNING PFX L_83
L_84
L_81 ) ;
V_19 = - V_156 ;
goto V_25;
}
if ( V_287 [ 2 ] != 0 ) {
F_111 (KERN_WARNING PFX L_86
L_87
L_88 ) ;
V_9 -> V_61 = true ;
}
V_25:
F_120 ( V_287 ) ;
}
static int F_183 ( struct V_9 * V_9 )
{
unsigned char V_1 [ 3 ] ;
unsigned char * V_287 ;
unsigned long V_288 ;
int V_19 = 0 ;
V_287 = F_180 ( V_71 , V_168 ) ;
if ( ! V_287 )
return - V_179 ;
V_1 [ 0 ] = V_30 << 2 ;
V_1 [ 1 ] = V_31 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 2 ) ;
V_19 = F_176 ( V_9 ) ;
if ( V_19 ) {
F_111 (KERN_WARNING PFX L_82
L_89
L_90 ) ;
goto V_25;
}
V_288 = V_9 -> V_26 -> V_70 ( V_9 -> V_28 ,
V_287 , V_71 ) ;
if ( V_288 < 4 ||
V_287 [ 0 ] != ( V_30 | 1 ) << 2 ||
V_287 [ 1 ] != V_31 ||
V_287 [ 2 ] != 0 ) {
F_111 (KERN_WARNING PFX L_83
L_91 ) ;
V_19 = - V_156 ;
goto V_25;
}
if ( V_287 [ 3 ] & V_60 ) {
V_9 -> V_59 = true ;
goto V_25;
}
V_1 [ 0 ] = V_30 << 2 ;
V_1 [ 1 ] = V_81 ;
V_1 [ 2 ] = V_287 [ 3 ] | V_60 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 3 ) ;
V_19 = F_176 ( V_9 ) ;
if ( V_19 ) {
F_111 (KERN_WARNING PFX L_85
L_92
L_90 ) ;
goto V_25;
}
V_288 = V_9 -> V_26 -> V_70 ( V_9 -> V_28 ,
V_287 , V_71 ) ;
if ( V_288 < 3 ||
V_287 [ 0 ] != ( V_30 | 1 ) << 2 ||
V_287 [ 1 ] != V_81 ) {
F_111 (KERN_WARNING PFX L_93
L_94 ) ;
V_19 = - V_156 ;
goto V_25;
}
if ( V_287 [ 2 ] != 0 )
V_19 = - V_291 ;
else
V_9 -> V_59 = true ;
V_25:
F_120 ( V_287 ) ;
return V_19 ;
}
static int F_184 ( struct V_292 * V_293 , void * V_160 )
{
struct V_9 * V_136 = V_293 -> V_294 ;
F_185 ( V_293 , L_95 , V_295 [ V_136 -> V_78 ] ) ;
return F_186 ( V_293 ) ;
}
static int F_187 ( struct V_296 * V_296 , struct V_297 * V_297 )
{
return F_188 ( V_297 , F_184 , F_189 ( V_296 ) ) ;
}
static int F_190 ( struct V_292 * V_293 , void * V_160 )
{
struct V_9 * V_136 = V_293 -> V_294 ;
F_185 ( V_293 , L_96 ,
V_136 -> V_46 && ! V_136 -> V_47 ) ;
F_185 ( V_293 , L_97 ,
F_191 ( V_136 , V_127 ) ) ;
F_185 ( V_293 , L_98 ,
F_191 ( V_136 , V_125 ) ) ;
F_185 ( V_293 , L_99 ,
F_191 ( V_136 , V_93 ) ) ;
F_185 ( V_293 , L_100 ,
F_191 ( V_136 , V_128 ) ) ;
F_185 ( V_293 , L_101 ,
F_191 ( V_136 , V_91 ) ) ;
F_185 ( V_293 , L_102 ,
F_191 ( V_136 , V_298 ) ) ;
F_185 ( V_293 , L_103 ,
F_191 ( V_136 , V_88 ) ) ;
F_185 ( V_293 , L_104 ,
F_191 ( V_136 , V_86 ) ) ;
F_185 ( V_293 , L_105 ,
F_191 ( V_136 , V_76 ) ) ;
F_185 ( V_293 , L_106 ,
F_191 ( V_136 , V_51 ) ) ;
F_185 ( V_293 , L_107 ,
F_191 ( V_136 , V_77 ) ) ;
return 0 ;
}
static int F_192 ( struct V_296 * V_296 , struct V_297 * V_297 )
{
return F_188 ( V_297 , F_190 , F_189 ( V_296 ) ) ;
}
static int F_193 ( struct V_292 * V_293 , void * V_160 )
{
struct V_9 * V_136 = V_293 -> V_294 ;
F_185 ( V_293 ,
L_108 ,
V_295 [ V_136 -> V_78 ] ,
V_299 [ V_136 -> V_65 . V_185 ] ,
V_136 -> V_65 . V_147 ,
V_136 -> V_65 . V_148 ,
V_136 -> V_65 . V_153 ,
V_136 -> V_65 . V_150 ,
V_136 -> V_46 ,
V_136 -> V_189 ) ;
return F_186 ( V_293 ) ;
}
static int F_194 ( struct V_296 * V_296 , struct V_297 * V_297 )
{
return F_188 ( V_297 , F_193 , F_189 ( V_296 ) ) ;
}
static int F_195 ( struct V_9 * V_9 )
{
V_9 -> V_50 = ( ( V_9 -> V_50 & ~ V_54 ) |
V_52 ) ;
return 1 ;
}
static void F_196 ( struct V_9 * V_9 )
{
struct V_300 * V_301 = & V_9 -> V_290 ;
if ( V_301 -> V_302 == V_303 ) {
if ( V_301 -> V_290 == V_304 &&
V_301 -> V_305 == V_306 &&
V_301 -> V_307 == V_308 ) {
V_9 -> V_55 =
F_195 ;
} else if ( F_197 ( V_301 ) < 1 ||
( F_197 ( V_301 ) == 1 &&
F_198 ( V_301 ) < 5 ) ) {
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
V_1 -> V_15 [ 2 ] = V_309 ;
V_1 -> V_17 = 3 ;
V_9 -> V_13 = NULL ;
F_6 ( V_9 , V_1 ) ;
}
static int F_200 ( struct V_6 * V_310 ,
unsigned long V_311 ,
void * V_312 )
{
struct V_9 * V_9 = V_312 ;
unsigned char * V_16 = V_9 -> V_13 -> V_16 ;
unsigned int V_313 = V_9 -> V_13 -> V_29 ;
if ( V_313 >= 8 &&
( V_16 [ 0 ] >> 2 ) == V_314 &&
V_16 [ 1 ] == V_315 &&
V_16 [ 7 ] == 0x3A ) {
F_199 ( V_9 ) ;
return V_316 ;
}
return V_317 ;
}
static void
F_201 ( struct V_9 * V_9 )
{
struct V_300 * V_301 = & V_9 -> V_290 ;
if ( V_301 -> V_302 == V_303 &&
V_9 -> V_78 == V_79 )
F_4 ( & V_318 ) ;
}
static void F_202 ( struct V_9 * V_9 )
{
F_196 ( V_9 ) ;
}
static void F_203 ( struct V_9 * V_9 )
{
F_201 ( V_9 ) ;
}
static inline void F_204 ( struct V_9 * V_9 )
{
if ( V_9 -> V_96 != NULL )
F_205 ( V_9 -> V_96 ) ;
if ( V_9 -> V_45 )
F_206 ( & V_9 -> V_44 ) ;
}
static void F_207 ( void )
{
struct V_9 * V_140 ;
int V_165 ;
for ( V_165 = 0 ; ; V_165 ++ ) {
if ( ! V_319 [ V_165 ] . V_320 )
break;
#ifdef F_208
if ( F_209 ( V_319 [ V_165 ] . V_320 ) )
continue;
#endif
V_140 = F_114 () ;
if ( ! V_140 )
return;
V_140 -> V_138 = V_321 ;
V_140 -> V_78 = V_319 [ V_165 ] . type ;
V_140 -> V_187 = F_87 ;
V_140 -> V_65 . V_147 = V_319 [ V_165 ] . V_320 ;
V_140 -> V_65 . V_185 = V_200 ;
V_140 -> V_65 . V_146 = NULL ;
V_140 -> V_65 . V_148 = V_188 ;
V_140 -> V_65 . V_153 = V_188 ;
V_140 -> V_65 . V_150 = 0 ;
if ( F_119 ( V_140 ) == 0 ) {
if ( ( F_121 ( V_140 ) ) == 0 ) {
F_111 (KERN_INFO PFX L_109
L_110 ,
si_to_str[info->si_type],
addr_space_to_str[info->io.addr_type],
info->io.addr_data) ;
} else
F_122 ( V_140 ) ;
} else {
F_120 ( V_140 ) ;
}
}
}
static int F_210 ( struct V_9 * V_140 )
{
struct V_9 * V_190 ;
F_211 (e, &smi_infos, link) {
if ( V_190 -> V_65 . V_185 != V_140 -> V_65 . V_185 )
continue;
if ( V_190 -> V_65 . V_147 == V_140 -> V_65 . V_147 )
return 0 ;
}
return 1 ;
}
static int F_119 ( struct V_9 * V_131 )
{
int V_19 = 0 ;
F_111 (KERN_INFO PFX L_111 ,
ipmi_addr_src_to_str(new_smi->addr_source),
si_to_str[new_smi->si_type]) ;
F_123 ( & V_192 ) ;
if ( ! F_210 ( V_131 ) ) {
F_111 ( V_322 L_112 ) ;
V_19 = - V_323 ;
goto V_324;
}
F_111 ( V_322 L_113 ) ;
V_131 -> V_11 = NULL ;
V_131 -> V_28 = NULL ;
V_131 -> V_26 = NULL ;
F_212 ( & V_131 -> V_325 , & V_326 ) ;
V_324:
F_125 ( & V_192 ) ;
return V_19 ;
}
static int F_121 ( struct V_9 * V_131 )
{
int V_19 = 0 ;
int V_165 ;
F_111 (KERN_INFO PFX L_114
L_115
L_116 ,
ipmi_addr_src_to_str(new_smi->addr_source),
si_to_str[new_smi->si_type],
addr_space_to_str[new_smi->io.addr_type],
new_smi->io.addr_data,
new_smi->slave_addr, new_smi->irq) ;
switch ( V_131 -> V_78 ) {
case V_198 :
V_131 -> V_26 = & V_263 ;
break;
case V_199 :
V_131 -> V_26 = & V_327 ;
break;
case V_79 :
V_131 -> V_26 = & V_328 ;
break;
default:
V_19 = - V_157 ;
goto V_324;
}
V_131 -> V_28 = F_180 ( V_131 -> V_26 -> V_313 () , V_168 ) ;
if ( ! V_131 -> V_28 ) {
F_111 (KERN_ERR PFX
L_117 ) ;
V_19 = - V_179 ;
goto V_324;
}
V_131 -> V_152 = V_131 -> V_26 -> V_329 ( V_131 -> V_28 ,
& V_131 -> V_65 ) ;
V_19 = V_131 -> V_187 ( V_131 ) ;
if ( V_19 ) {
F_111 (KERN_ERR PFX L_118 ) ;
goto V_324;
}
if ( V_131 -> V_26 -> V_330 ( V_131 -> V_28 ) ) {
if ( V_131 -> V_138 )
F_111 (KERN_INFO PFX L_119 ) ;
V_19 = - V_154 ;
goto V_324;
}
V_19 = F_179 ( V_131 ) ;
if ( V_19 ) {
if ( V_131 -> V_138 )
F_111 (KERN_INFO PFX L_120
L_121 ) ;
goto V_324;
}
F_182 ( V_131 ) ;
F_202 ( V_131 ) ;
F_203 ( V_131 ) ;
V_131 -> V_20 = NULL ;
V_131 -> V_13 = NULL ;
F_32 ( & V_131 -> V_94 , 0 ) ;
V_131 -> V_100 = false ;
for ( V_165 = 0 ; V_165 < V_331 ; V_165 ++ )
F_32 ( & V_131 -> V_332 [ V_165 ] , 0 ) ;
V_131 -> V_47 = true ;
F_32 ( & V_131 -> V_117 , 0 ) ;
V_131 -> V_108 = V_333 ;
V_333 ++ ;
V_19 = F_183 ( V_131 ) ;
if ( V_19 == 0 )
V_131 -> V_119 = true ;
F_13 ( V_131 ) ;
if ( V_131 -> V_46 ) {
V_131 -> V_47 = false ;
F_32 ( & V_131 -> V_94 , 1 ) ;
}
if ( ! V_131 -> V_74 ) {
V_131 -> V_260 = F_213 ( L_122 ,
V_131 -> V_108 ) ;
if ( ! V_131 -> V_260 ) {
F_111 (KERN_ERR PFX
L_123 ) ;
goto V_324;
}
V_131 -> V_74 = & V_131 -> V_260 -> V_74 ;
V_131 -> V_74 -> V_334 = & V_335 . V_334 ;
V_19 = F_214 ( V_131 -> V_260 ) ;
if ( V_19 ) {
F_111 (KERN_ERR PFX
L_124
L_125 ,
rv) ;
goto V_324;
}
V_131 -> V_336 = true ;
}
V_19 = F_215 ( & V_26 ,
V_131 ,
& V_131 -> V_290 ,
V_131 -> V_74 ,
V_131 -> V_189 ) ;
if ( V_19 ) {
F_141 ( V_131 -> V_74 , L_126 ,
V_19 ) ;
goto V_337;
}
V_19 = F_216 ( V_131 -> V_11 , L_127 ,
& V_338 ,
V_131 ) ;
if ( V_19 ) {
F_141 ( V_131 -> V_74 , L_128 , V_19 ) ;
goto V_337;
}
V_19 = F_216 ( V_131 -> V_11 , L_129 ,
& V_339 ,
V_131 ) ;
if ( V_19 ) {
F_141 ( V_131 -> V_74 , L_128 , V_19 ) ;
goto V_337;
}
V_19 = F_216 ( V_131 -> V_11 , L_130 ,
& V_340 ,
V_131 ) ;
if ( V_19 ) {
F_141 ( V_131 -> V_74 , L_128 , V_19 ) ;
goto V_337;
}
F_72 ( V_131 -> V_74 , L_131 ,
V_295 [ V_131 -> V_78 ] ) ;
return 0 ;
V_337:
F_204 ( V_131 ) ;
V_324:
V_131 -> V_47 = true ;
if ( V_131 -> V_11 ) {
T_3 V_11 = V_131 -> V_11 ;
V_131 -> V_11 = NULL ;
F_217 ( V_11 ) ;
}
if ( V_131 -> V_143 ) {
V_131 -> V_143 ( V_131 ) ;
V_131 -> V_143 = NULL ;
}
F_218 () ;
if ( V_131 -> V_28 ) {
if ( V_131 -> V_26 )
V_131 -> V_26 -> V_341 ( V_131 -> V_28 ) ;
F_120 ( V_131 -> V_28 ) ;
V_131 -> V_28 = NULL ;
}
if ( V_131 -> V_273 ) {
V_131 -> V_273 ( V_131 ) ;
V_131 -> V_273 = NULL ;
}
if ( V_131 -> V_155 ) {
V_131 -> V_155 ( V_131 ) ;
V_131 -> V_155 = NULL ;
}
if ( V_131 -> V_336 ) {
F_219 ( V_131 -> V_260 ) ;
V_131 -> V_336 = false ;
}
return V_19 ;
}
static int F_220 ( void )
{
int V_165 ;
char * V_171 ;
int V_19 ;
struct V_9 * V_190 ;
enum V_342 type = V_343 ;
if ( V_344 )
return 0 ;
V_344 = 1 ;
if ( V_345 ) {
V_19 = F_221 ( & V_335 ) ;
if ( V_19 ) {
F_111 (KERN_ERR PFX L_132
L_133 , rv) ;
return V_19 ;
}
}
V_171 = V_346 ;
if ( * V_171 != '\0' ) {
for ( V_165 = 0 ; ( V_165 < V_194 ) && ( * V_171 != '\0' ) ; V_165 ++ ) {
V_78 [ V_165 ] = V_171 ;
V_171 = strchr ( V_171 , ',' ) ;
if ( V_171 ) {
* V_171 = '\0' ;
V_171 ++ ;
} else {
break;
}
}
}
F_111 ( V_347 L_134 ) ;
if ( ! F_126 () )
return 0 ;
#ifdef F_222
if ( V_348 ) {
V_19 = F_223 ( & V_349 ) ;
if ( V_19 )
F_111 (KERN_ERR PFX L_132
L_135 , rv) ;
else
V_350 = true ;
}
#endif
#ifdef F_224
if ( V_351 ) {
F_225 ( & V_352 ) ;
V_353 = true ;
}
#endif
#ifdef F_226
if ( V_354 )
F_150 () ;
#endif
#ifdef F_224
if ( V_351 )
F_134 () ;
#endif
#ifdef F_227
F_228 ( & V_355 ) ;
V_356 = true ;
V_357 = 0 ;
#endif
F_123 ( & V_192 ) ;
F_211 (e, &smi_infos, link) {
if ( V_190 -> V_46 && ( ! type || V_190 -> V_138 == type ) ) {
if ( ! F_121 ( V_190 ) ) {
type = V_190 -> V_138 ;
}
}
}
if ( type ) {
F_125 ( & V_192 ) ;
return 0 ;
}
F_211 (e, &smi_infos, link) {
if ( ! V_190 -> V_46 && ( ! type || V_190 -> V_138 == type ) ) {
if ( ! F_121 ( V_190 ) ) {
type = V_190 -> V_138 ;
}
}
}
F_125 ( & V_192 ) ;
if ( type )
return 0 ;
if ( V_357 ) {
F_123 ( & V_192 ) ;
if ( F_229 ( & V_326 ) ) {
F_125 ( & V_192 ) ;
F_207 () ;
} else
F_125 ( & V_192 ) ;
}
F_123 ( & V_192 ) ;
if ( V_358 && F_229 ( & V_326 ) ) {
F_125 ( & V_192 ) ;
F_230 () ;
F_111 (KERN_WARNING PFX
L_136 ) ;
return - V_154 ;
} else {
F_125 ( & V_192 ) ;
return 0 ;
}
}
static void F_122 ( struct V_9 * V_359 )
{
int V_19 = 0 ;
if ( ! V_359 )
return;
if ( V_359 -> V_11 ) {
T_3 V_11 = V_359 -> V_11 ;
V_359 -> V_11 = NULL ;
V_19 = F_217 ( V_11 ) ;
if ( V_19 ) {
F_231 ( V_282 L_137 ,
V_19 ) ;
}
}
if ( V_359 -> V_74 )
F_171 ( V_359 -> V_74 , NULL ) ;
F_232 ( & V_359 -> V_325 ) ;
if ( V_359 -> V_143 )
V_359 -> V_143 ( V_359 ) ;
F_204 ( V_359 ) ;
while ( V_359 -> V_13 || ( V_359 -> V_32 != V_48 ) ) {
F_53 ( V_359 ) ;
F_177 ( 1 ) ;
}
F_18 ( V_359 ) ;
while ( V_359 -> V_13 || ( V_359 -> V_32 != V_48 ) ) {
F_53 ( V_359 ) ;
F_177 ( 1 ) ;
}
if ( V_359 -> V_26 )
V_359 -> V_26 -> V_341 ( V_359 -> V_28 ) ;
F_120 ( V_359 -> V_28 ) ;
if ( V_359 -> V_273 )
V_359 -> V_273 ( V_359 ) ;
if ( V_359 -> V_155 )
V_359 -> V_155 ( V_359 ) ;
if ( V_359 -> V_336 )
F_219 ( V_359 -> V_260 ) ;
F_120 ( V_359 ) ;
}
static void F_230 ( void )
{
struct V_9 * V_190 , * V_191 ;
if ( ! V_344 )
return;
#ifdef F_222
if ( V_350 )
F_233 ( & V_349 ) ;
#endif
#ifdef F_224
if ( V_353 )
F_234 ( & V_352 ) ;
#endif
#ifdef F_227
if ( V_356 )
F_235 ( & V_355 ) ;
#endif
F_236 ( & V_335 ) ;
F_123 ( & V_192 ) ;
F_124 (e, tmp_e, &smi_infos, link)
F_122 ( V_190 ) ;
F_125 ( & V_192 ) ;
}
