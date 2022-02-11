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
static void F_12 ( struct V_9 * V_9 , unsigned long V_30 )
{
V_9 -> V_31 = V_32 ;
F_13 ( & V_9 -> V_33 , V_30 ) ;
V_9 -> V_34 = true ;
}
static void F_14 ( struct V_9 * V_9 , unsigned char * V_1 ,
unsigned int V_35 )
{
F_12 ( V_9 , V_32 + V_36 ) ;
if ( V_9 -> V_37 )
F_15 ( V_9 -> V_37 ) ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , V_35 ) ;
}
static void F_16 ( struct V_9 * V_9 , bool V_38 )
{
unsigned char V_1 [ 2 ] ;
V_1 [ 0 ] = ( V_39 << 2 ) ;
V_1 [ 1 ] = V_40 ;
if ( V_38 )
F_14 ( V_9 , V_1 , 2 ) ;
else
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 2 ) ;
V_9 -> V_41 = V_42 ;
}
static void F_17 ( struct V_9 * V_9 , bool V_38 )
{
unsigned char V_1 [ 3 ] ;
V_1 [ 0 ] = ( V_39 << 2 ) ;
V_1 [ 1 ] = V_43 ;
V_1 [ 2 ] = V_44 ;
if ( V_38 )
F_14 ( V_9 , V_1 , 3 ) ;
else
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 3 ) ;
V_9 -> V_41 = V_45 ;
}
static void F_18 ( struct V_9 * V_9 )
{
V_9 -> V_13 -> V_16 [ 0 ] = ( V_39 << 2 ) ;
V_9 -> V_13 -> V_16 [ 1 ] = V_46 ;
V_9 -> V_13 -> V_29 = 2 ;
F_14 ( V_9 , V_9 -> V_13 -> V_16 ,
V_9 -> V_13 -> V_29 ) ;
V_9 -> V_41 = V_47 ;
}
static void F_19 ( struct V_9 * V_9 )
{
V_9 -> V_13 -> V_16 [ 0 ] = ( V_39 << 2 ) ;
V_9 -> V_13 -> V_16 [ 1 ] = V_48 ;
V_9 -> V_13 -> V_29 = 2 ;
F_14 ( V_9 , V_9 -> V_13 -> V_16 ,
V_9 -> V_13 -> V_29 ) ;
V_9 -> V_41 = V_49 ;
}
static inline bool F_20 ( struct V_9 * V_9 , bool V_38 )
{
if ( ( V_9 -> V_50 ) && ( ! V_9 -> V_51 ) ) {
V_9 -> V_51 = true ;
F_16 ( V_9 , V_38 ) ;
return true ;
}
return false ;
}
static inline bool F_21 ( struct V_9 * V_9 )
{
if ( ( V_9 -> V_50 ) && ( V_9 -> V_51 ) ) {
V_9 -> V_51 = false ;
F_16 ( V_9 , true ) ;
return true ;
}
return false ;
}
static struct V_10 * F_22 ( struct V_9 * V_9 )
{
struct V_10 * V_1 ;
V_1 = F_23 () ;
if ( ! V_1 ) {
if ( ! F_20 ( V_9 , true ) )
V_9 -> V_41 = V_52 ;
} else if ( F_21 ( V_9 ) ) {
F_8 ( V_1 ) ;
V_1 = NULL ;
}
return V_1 ;
}
static void F_24 ( struct V_9 * V_9 )
{
V_53:
if ( V_9 -> V_54 & V_44 ) {
F_25 ( V_9 , V_55 ) ;
F_17 ( V_9 , true ) ;
V_9 -> V_54 &= ~ V_44 ;
if ( V_9 -> V_11 )
F_26 ( V_9 -> V_11 ) ;
} else if ( V_9 -> V_54 & V_56 ) {
V_9 -> V_13 = F_22 ( V_9 ) ;
if ( ! V_9 -> V_13 )
return;
F_18 ( V_9 ) ;
} else if ( V_9 -> V_54 & V_57 ) {
V_9 -> V_13 = F_22 ( V_9 ) ;
if ( ! V_9 -> V_13 )
return;
F_19 ( V_9 ) ;
} else if ( V_9 -> V_54 & V_58 &&
V_9 -> V_59 ) {
if ( V_9 -> V_59 ( V_9 ) )
goto V_53;
} else
V_9 -> V_41 = V_52 ;
}
static T_1 F_27 ( struct V_9 * V_9 , T_1 V_60 ,
bool * V_61 )
{
T_1 V_62 = 0 ;
if ( V_9 -> V_63 )
V_62 |= V_64 ;
if ( ( ( V_9 -> V_50 && ! V_9 -> V_51 ) ||
V_9 -> V_65 ) &&
! V_9 -> V_66 )
V_62 |= V_67 ;
if ( V_9 -> V_63 &&
V_9 -> V_50 && ! V_9 -> V_51 &&
! V_9 -> V_66 )
V_62 |= V_68 ;
* V_61 = V_62 & ( V_68 | V_67 ) ;
return V_62 ;
}
static void F_28 ( struct V_9 * V_9 , bool V_61 )
{
T_1 V_69 = V_9 -> V_70 . V_71 ( & V_9 -> V_70 , V_72 ) ;
V_69 &= V_73 ;
if ( ( bool ) V_69 == V_61 )
return;
if ( V_61 )
V_9 -> V_70 . V_74 ( & V_9 -> V_70 , V_72 ,
V_73 ) ;
else
V_9 -> V_70 . V_74 ( & V_9 -> V_70 , V_72 , 0 ) ;
}
static void F_29 ( struct V_9 * V_9 )
{
struct V_10 * V_1 ;
F_1 ( L_3 ) ;
switch ( V_9 -> V_41 ) {
case V_52 :
if ( ! V_9 -> V_13 )
break;
V_9 -> V_13 -> V_17
= V_9 -> V_26 -> V_75 (
V_9 -> V_28 ,
V_9 -> V_13 -> V_15 ,
V_76 ) ;
V_1 = V_9 -> V_13 ;
V_9 -> V_13 = NULL ;
F_6 ( V_9 , V_1 ) ;
break;
case V_77 :
{
unsigned char V_1 [ 4 ] ;
unsigned int V_78 ;
V_78 = V_9 -> V_26 -> V_75 ( V_9 -> V_28 , V_1 , 4 ) ;
if ( V_1 [ 2 ] != 0 ) {
V_9 -> V_41 = V_52 ;
} else if ( V_78 < 4 ) {
V_9 -> V_41 = V_52 ;
} else {
V_9 -> V_54 = V_1 [ 3 ] ;
F_24 ( V_9 ) ;
}
break;
}
case V_45 :
{
unsigned char V_1 [ 3 ] ;
V_9 -> V_26 -> V_75 ( V_9 -> V_28 , V_1 , 3 ) ;
if ( V_1 [ 2 ] != 0 ) {
F_30 ( V_9 -> V_79 ,
L_4 , V_1 [ 2 ] ) ;
}
V_9 -> V_41 = V_52 ;
break;
}
case V_49 :
{
V_9 -> V_13 -> V_17
= V_9 -> V_26 -> V_75 (
V_9 -> V_28 ,
V_9 -> V_13 -> V_15 ,
V_76 ) ;
V_1 = V_9 -> V_13 ;
V_9 -> V_13 = NULL ;
if ( V_1 -> V_15 [ 2 ] != 0 ) {
V_1 -> V_80 ( V_1 ) ;
V_9 -> V_54 &= ~ V_57 ;
F_24 ( V_9 ) ;
} else {
F_25 ( V_9 , V_81 ) ;
F_24 ( V_9 ) ;
F_6 ( V_9 , V_1 ) ;
}
break;
}
case V_47 :
{
V_9 -> V_13 -> V_17
= V_9 -> V_26 -> V_75 (
V_9 -> V_28 ,
V_9 -> V_13 -> V_15 ,
V_76 ) ;
V_1 = V_9 -> V_13 ;
V_9 -> V_13 = NULL ;
if ( V_1 -> V_15 [ 2 ] != 0 ) {
V_1 -> V_80 ( V_1 ) ;
V_9 -> V_54 &= ~ V_56 ;
F_24 ( V_9 ) ;
} else {
F_25 ( V_9 , V_82 ) ;
F_24 ( V_9 ) ;
F_6 ( V_9 , V_1 ) ;
}
break;
}
case V_42 :
{
unsigned char V_1 [ 4 ] ;
T_1 V_62 ;
bool V_61 ;
V_9 -> V_26 -> V_75 ( V_9 -> V_28 , V_1 , 4 ) ;
if ( V_1 [ 2 ] != 0 ) {
F_30 ( V_9 -> V_79 ,
L_5 , V_1 [ 2 ] ) ;
F_30 ( V_9 -> V_79 ,
L_6 ) ;
V_9 -> V_41 = V_52 ;
break;
}
V_62 = F_27 ( V_9 , 0 , & V_61 ) ;
if ( V_9 -> V_83 == V_84 )
F_28 ( V_9 , V_61 ) ;
if ( V_62 != ( V_1 [ 3 ] & V_85 ) ) {
V_1 [ 0 ] = ( V_39 << 2 ) ;
V_1 [ 1 ] = V_86 ;
V_1 [ 2 ] = V_62 | ( V_1 [ 3 ] & ~ V_85 ) ;
V_9 -> V_26 -> V_27 (
V_9 -> V_28 , V_1 , 3 ) ;
V_9 -> V_41 = V_87 ;
} else if ( V_9 -> V_63 ) {
V_9 -> V_13 = F_23 () ;
if ( ! V_9 -> V_13 ) {
V_9 -> V_41 = V_52 ;
break;
}
F_18 ( V_9 ) ;
} else {
V_9 -> V_41 = V_52 ;
}
break;
}
case V_87 :
{
unsigned char V_1 [ 4 ] ;
V_9 -> V_26 -> V_75 ( V_9 -> V_28 , V_1 , 4 ) ;
if ( V_1 [ 2 ] != 0 )
F_30 ( V_9 -> V_79 ,
L_7 ,
V_1 [ 2 ] ) ;
if ( V_9 -> V_63 ) {
V_9 -> V_13 = F_23 () ;
if ( ! V_9 -> V_13 ) {
V_9 -> V_41 = V_52 ;
break;
}
F_18 ( V_9 ) ;
} else {
V_9 -> V_41 = V_52 ;
}
break;
}
}
}
static enum V_18 F_31 ( struct V_9 * V_9 ,
int time )
{
enum V_18 V_18 ;
V_88:
V_18 = V_9 -> V_26 -> V_89 ( V_9 -> V_28 , time ) ;
time = 0 ;
while ( V_18 == V_24 )
V_18 = V_9 -> V_26 -> V_89 ( V_9 -> V_28 , 0 ) ;
if ( V_18 == V_90 ) {
F_25 ( V_9 , V_91 ) ;
F_29 ( V_9 ) ;
goto V_88;
} else if ( V_18 == V_92 ) {
F_25 ( V_9 , V_93 ) ;
V_9 -> V_41 = V_52 ;
if ( V_9 -> V_13 != NULL ) {
F_9 ( V_9 , V_14 ) ;
}
goto V_88;
}
if ( F_32 ( V_9 -> V_11 ) &&
( V_18 == V_94 || V_9 -> V_95 ) ) {
unsigned char V_1 [ 2 ] ;
if ( V_9 -> V_41 != V_52 ) {
V_9 -> V_95 = true ;
} else {
V_9 -> V_95 = false ;
F_25 ( V_9 , V_96 ) ;
V_1 [ 0 ] = ( V_39 << 2 ) ;
V_1 [ 1 ] = V_97 ;
F_14 ( V_9 , V_1 , 2 ) ;
V_9 -> V_41 = V_77 ;
goto V_88;
}
}
if ( V_18 == V_21 ) {
F_25 ( V_9 , V_98 ) ;
V_18 = F_10 ( V_9 ) ;
if ( V_18 != V_21 )
goto V_88;
}
if ( ( V_18 == V_21 )
&& ( F_33 ( & V_9 -> V_99 ) ) ) {
F_34 ( & V_9 -> V_99 , 0 ) ;
if ( V_9 -> V_63 || V_9 -> V_50 ) {
F_16 ( V_9 , true ) ;
} else {
V_9 -> V_13 = F_22 ( V_9 ) ;
if ( ! V_9 -> V_13 )
goto V_25;
F_19 ( V_9 ) ;
}
goto V_88;
}
if ( V_18 == V_21 && V_9 -> V_34 ) {
if ( F_35 ( & V_9 -> V_33 ) )
V_9 -> V_34 = false ;
}
V_25:
return V_18 ;
}
static void F_36 ( struct V_9 * V_9 )
{
if ( V_9 -> V_41 == V_52 && V_9 -> V_13 == NULL ) {
F_12 ( V_9 , V_32 + V_36 ) ;
if ( V_9 -> V_37 )
F_15 ( V_9 -> V_37 ) ;
F_10 ( V_9 ) ;
F_31 ( V_9 , 0 ) ;
}
}
static void F_37 ( void * V_100 )
{
struct V_9 * V_9 = V_100 ;
enum V_18 V_101 ;
V_101 = F_31 ( V_9 , 0 ) ;
while ( V_101 != V_21 ) {
F_38 ( V_102 ) ;
V_101 = F_31 ( V_9 , V_102 ) ;
}
}
static void F_39 ( void * V_100 ,
struct V_10 * V_1 )
{
struct V_9 * V_9 = V_100 ;
unsigned long V_103 ;
F_1 ( L_8 ) ;
if ( V_9 -> V_104 ) {
V_9 -> V_20 = V_1 ;
return;
}
F_40 ( & V_9 -> V_105 , V_103 ) ;
F_41 ( V_9 -> V_20 ) ;
V_9 -> V_20 = V_1 ;
F_36 ( V_9 ) ;
F_42 ( & V_9 -> V_105 , V_103 ) ;
}
static void F_43 ( void * V_100 , bool V_106 )
{
struct V_9 * V_9 = V_100 ;
V_9 -> V_104 = V_106 ;
if ( V_106 )
F_37 ( V_9 ) ;
}
static inline void F_44 ( struct V_2 * V_107 )
{
V_107 -> V_5 = - 1 ;
}
static inline int F_45 ( struct V_2 * V_107 )
{
return V_107 -> V_5 != - 1 ;
}
static inline int F_46 ( enum V_18 V_108 ,
const struct V_9 * V_9 ,
struct V_2 * V_109 )
{
unsigned int V_110 = 0 ;
if ( V_9 -> V_111 < V_112 )
V_110 = V_113 [ V_9 -> V_111 ] ;
if ( V_110 == 0 || V_108 != V_114 )
F_44 ( V_109 ) ;
else if ( ! F_45 ( V_109 ) ) {
F_2 ( V_109 ) ;
F_47 ( V_109 , V_110 * V_115 ) ;
} else {
struct V_2 V_116 ;
F_2 ( & V_116 ) ;
if ( F_48 ( F_49 ( & V_116 , V_109 ) > 0 ) ) {
F_44 ( V_109 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_50 ( void * V_16 )
{
struct V_9 * V_9 = V_16 ;
unsigned long V_103 ;
enum V_18 V_108 ;
struct V_2 V_109 ;
F_44 ( & V_109 ) ;
F_51 ( V_117 , V_118 ) ;
while ( ! F_52 () ) {
int V_119 ;
F_40 ( & ( V_9 -> V_105 ) , V_103 ) ;
V_108 = F_31 ( V_9 , 0 ) ;
if ( V_108 != V_21 && ! V_9 -> V_34 )
F_12 ( V_9 , V_32 + V_36 ) ;
F_42 ( & ( V_9 -> V_105 ) , V_103 ) ;
V_119 = F_46 ( V_108 , V_9 ,
& V_109 ) ;
if ( V_108 == V_24 )
;
else if ( V_108 == V_114 && V_119 )
F_53 () ;
else if ( V_108 == V_21 ) {
if ( F_33 ( & V_9 -> V_120 ) ) {
F_54 ( 100 ) ;
} else {
F_55 ( V_121 ) ;
F_53 () ;
}
} else
F_54 ( 1 ) ;
}
return 0 ;
}
static void F_56 ( void * V_100 )
{
struct V_9 * V_9 = V_100 ;
unsigned long V_103 = 0 ;
bool V_104 = V_9 -> V_104 ;
F_38 ( 10 ) ;
if ( ! V_104 )
F_40 ( & V_9 -> V_105 , V_103 ) ;
F_31 ( V_9 , 10 ) ;
if ( ! V_104 )
F_42 ( & V_9 -> V_105 , V_103 ) ;
}
static void F_57 ( void * V_100 )
{
struct V_9 * V_9 = V_100 ;
if ( ! V_9 -> V_122 )
return;
F_34 ( & V_9 -> V_99 , 1 ) ;
}
static void F_58 ( void * V_100 , bool V_123 )
{
struct V_9 * V_9 = V_100 ;
unsigned long V_103 ;
F_34 ( & V_9 -> V_120 , V_123 ) ;
F_40 ( & V_9 -> V_105 , V_103 ) ;
F_36 ( V_9 ) ;
F_42 ( & V_9 -> V_105 , V_103 ) ;
}
static void F_59 ( unsigned long V_16 )
{
struct V_9 * V_9 = (struct V_9 * ) V_16 ;
enum V_18 V_108 ;
unsigned long V_103 ;
unsigned long V_124 ;
long V_125 ;
long V_126 ;
F_40 ( & ( V_9 -> V_105 ) , V_103 ) ;
F_1 ( L_9 ) ;
V_124 = V_32 ;
V_125 = ( ( ( long ) V_124 - ( long ) V_9 -> V_31 )
* V_127 ) ;
V_108 = F_31 ( V_9 , V_125 ) ;
if ( ( V_9 -> V_50 ) && ( ! V_9 -> V_51 ) ) {
V_126 = V_32 + V_36 ;
F_25 ( V_9 , V_128 ) ;
goto V_129;
}
if ( V_108 == V_114 ) {
F_25 ( V_9 , V_130 ) ;
V_126 = V_32 + 1 ;
} else {
F_25 ( V_9 , V_128 ) ;
V_126 = V_32 + V_36 ;
}
V_129:
if ( V_108 != V_21 )
F_12 ( V_9 , V_126 ) ;
else
V_9 -> V_34 = false ;
F_42 ( & ( V_9 -> V_105 ) , V_103 ) ;
}
static T_2 F_60 ( int V_50 , void * V_16 )
{
struct V_9 * V_9 = V_16 ;
unsigned long V_103 ;
F_40 ( & ( V_9 -> V_105 ) , V_103 ) ;
F_25 ( V_9 , V_131 ) ;
F_1 ( L_10 ) ;
F_31 ( V_9 , 0 ) ;
F_42 ( & ( V_9 -> V_105 ) , V_103 ) ;
return V_132 ;
}
static T_2 F_61 ( int V_50 , void * V_16 )
{
struct V_9 * V_9 = V_16 ;
V_9 -> V_70 . V_74 ( & V_9 -> V_70 , V_72 ,
V_133
| V_73 ) ;
return F_60 ( V_50 , V_16 ) ;
}
static int F_62 ( void * V_100 ,
T_3 V_11 )
{
struct V_9 * V_134 = V_100 ;
int V_123 = 0 ;
V_134 -> V_11 = V_11 ;
F_63 ( & V_134 -> V_33 , F_59 , ( long ) V_134 ) ;
F_12 ( V_134 , V_32 + V_36 ) ;
if ( V_134 -> V_135 )
V_134 -> V_135 ( V_134 ) ;
if ( V_134 -> V_111 < V_136 )
V_123 = V_137 [ V_134 -> V_111 ] ;
else if ( ( V_134 -> V_83 != V_84 ) && ( ! V_134 -> V_50 ) )
V_123 = 1 ;
if ( V_123 ) {
V_134 -> V_37 = F_64 ( F_50 , V_134 ,
L_11 , V_134 -> V_111 ) ;
if ( F_65 ( V_134 -> V_37 ) ) {
F_66 ( V_134 -> V_79 , L_12
L_13
L_14 ,
F_67 ( V_134 -> V_37 ) ) ;
V_134 -> V_37 = NULL ;
}
}
return 0 ;
}
static int F_68 ( void * V_100 , struct V_138 * V_16 )
{
struct V_9 * V_139 = V_100 ;
V_16 -> V_140 = V_139 -> V_141 ;
V_16 -> V_79 = V_139 -> V_79 ;
V_16 -> V_142 = V_139 -> V_142 ;
F_69 ( V_139 -> V_79 ) ;
return 0 ;
}
static void F_70 ( void * V_100 , bool V_123 )
{
struct V_9 * V_9 = V_100 ;
if ( ! V_123 )
F_34 ( & V_9 -> V_99 , 0 ) ;
}
static void F_71 ( struct V_9 * V_143 )
{
if ( V_143 -> V_83 == V_84 )
V_143 -> V_70 . V_74 ( & V_143 -> V_70 , V_72 , 0 ) ;
F_72 ( V_143 -> V_50 , V_143 ) ;
}
static int F_73 ( struct V_9 * V_143 )
{
int V_19 ;
if ( ! V_143 -> V_50 )
return 0 ;
if ( V_143 -> V_83 == V_84 ) {
V_19 = F_74 ( V_143 -> V_50 ,
F_61 ,
V_144 ,
V_145 ,
V_143 ) ;
if ( ! V_19 )
V_143 -> V_70 . V_74 ( & V_143 -> V_70 , V_72 ,
V_73 ) ;
} else
V_19 = F_74 ( V_143 -> V_50 ,
F_60 ,
V_144 ,
V_145 ,
V_143 ) ;
if ( V_19 ) {
F_30 ( V_143 -> V_79 , L_15
L_16 ,
V_145 , V_143 -> V_50 ) ;
V_143 -> V_50 = 0 ;
} else {
V_143 -> V_146 = F_71 ;
F_75 ( V_143 -> V_79 , L_17 , V_143 -> V_50 ) ;
}
return V_19 ;
}
static unsigned char F_76 ( const struct V_147 * V_70 , unsigned int V_148 )
{
unsigned int V_149 = V_70 -> V_150 ;
return F_77 ( V_149 + ( V_148 * V_70 -> V_151 ) ) ;
}
static void F_78 ( const struct V_147 * V_70 , unsigned int V_148 ,
unsigned char V_152 )
{
unsigned int V_149 = V_70 -> V_150 ;
F_79 ( V_152 , V_149 + ( V_148 * V_70 -> V_151 ) ) ;
}
static unsigned char F_80 ( const struct V_147 * V_70 , unsigned int V_148 )
{
unsigned int V_149 = V_70 -> V_150 ;
return ( F_81 ( V_149 + ( V_148 * V_70 -> V_151 ) ) >> V_70 -> V_153 ) & 0xff ;
}
static void F_82 ( const struct V_147 * V_70 , unsigned int V_148 ,
unsigned char V_152 )
{
unsigned int V_149 = V_70 -> V_150 ;
F_83 ( V_152 << V_70 -> V_153 , V_149 + ( V_148 * V_70 -> V_151 ) ) ;
}
static unsigned char F_84 ( const struct V_147 * V_70 , unsigned int V_148 )
{
unsigned int V_149 = V_70 -> V_150 ;
return ( F_85 ( V_149 + ( V_148 * V_70 -> V_151 ) ) >> V_70 -> V_153 ) & 0xff ;
}
static void F_86 ( const struct V_147 * V_70 , unsigned int V_148 ,
unsigned char V_152 )
{
unsigned int V_149 = V_70 -> V_150 ;
F_87 ( V_152 << V_70 -> V_153 , V_149 + ( V_148 * V_70 -> V_151 ) ) ;
}
static void F_88 ( struct V_9 * V_143 )
{
unsigned int V_149 = V_143 -> V_70 . V_150 ;
int V_154 ;
if ( V_149 ) {
for ( V_154 = 0 ; V_154 < V_143 -> V_155 ; V_154 ++ )
F_89 ( V_149 + V_154 * V_143 -> V_70 . V_151 ,
V_143 -> V_70 . V_156 ) ;
}
}
static int F_90 ( struct V_9 * V_143 )
{
unsigned int V_149 = V_143 -> V_70 . V_150 ;
int V_154 ;
if ( ! V_149 )
return - V_157 ;
V_143 -> V_158 = F_88 ;
switch ( V_143 -> V_70 . V_156 ) {
case 1 :
V_143 -> V_70 . V_71 = F_76 ;
V_143 -> V_70 . V_74 = F_78 ;
break;
case 2 :
V_143 -> V_70 . V_71 = F_80 ;
V_143 -> V_70 . V_74 = F_82 ;
break;
case 4 :
V_143 -> V_70 . V_71 = F_84 ;
V_143 -> V_70 . V_74 = F_86 ;
break;
default:
F_30 ( V_143 -> V_79 , L_18 ,
V_143 -> V_70 . V_156 ) ;
return - V_159 ;
}
for ( V_154 = 0 ; V_154 < V_143 -> V_155 ; V_154 ++ ) {
if ( F_91 ( V_149 + V_154 * V_143 -> V_70 . V_151 ,
V_143 -> V_70 . V_156 , V_145 ) == NULL ) {
while ( V_154 -- )
F_89 ( V_149 + V_154 * V_143 -> V_70 . V_151 ,
V_143 -> V_70 . V_156 ) ;
return - V_160 ;
}
}
return 0 ;
}
static unsigned char F_92 ( const struct V_147 * V_70 ,
unsigned int V_148 )
{
return F_93 ( ( V_70 -> V_149 ) + ( V_148 * V_70 -> V_151 ) ) ;
}
static void F_94 ( const struct V_147 * V_70 , unsigned int V_148 ,
unsigned char V_152 )
{
F_95 ( V_152 , ( V_70 -> V_149 ) + ( V_148 * V_70 -> V_151 ) ) ;
}
static unsigned char F_96 ( const struct V_147 * V_70 ,
unsigned int V_148 )
{
return ( F_97 ( ( V_70 -> V_149 ) + ( V_148 * V_70 -> V_151 ) ) >> V_70 -> V_153 )
& 0xff ;
}
static void F_98 ( const struct V_147 * V_70 , unsigned int V_148 ,
unsigned char V_152 )
{
F_95 ( V_152 << V_70 -> V_153 , ( V_70 -> V_149 ) + ( V_148 * V_70 -> V_151 ) ) ;
}
static unsigned char F_99 ( const struct V_147 * V_70 ,
unsigned int V_148 )
{
return ( F_100 ( ( V_70 -> V_149 ) + ( V_148 * V_70 -> V_151 ) ) >> V_70 -> V_153 )
& 0xff ;
}
static void F_101 ( const struct V_147 * V_70 , unsigned int V_148 ,
unsigned char V_152 )
{
F_102 ( V_152 << V_70 -> V_153 , ( V_70 -> V_149 ) + ( V_148 * V_70 -> V_151 ) ) ;
}
static unsigned char F_103 ( const struct V_147 * V_70 , unsigned int V_148 )
{
return ( F_104 ( ( V_70 -> V_149 ) + ( V_148 * V_70 -> V_151 ) ) >> V_70 -> V_153 )
& 0xff ;
}
static void F_105 ( const struct V_147 * V_70 , unsigned int V_148 ,
unsigned char V_152 )
{
F_106 ( V_152 << V_70 -> V_153 , ( V_70 -> V_149 ) + ( V_148 * V_70 -> V_151 ) ) ;
}
static void F_107 ( struct V_9 * V_143 , int V_161 )
{
unsigned long V_149 = V_143 -> V_70 . V_150 ;
int V_154 ;
for ( V_154 = 0 ; V_154 < V_161 ; V_154 ++ )
F_108 ( V_149 + V_154 * V_143 -> V_70 . V_151 ,
V_143 -> V_70 . V_156 ) ;
}
static void F_109 ( struct V_9 * V_143 )
{
if ( V_143 -> V_70 . V_149 ) {
F_110 ( V_143 -> V_70 . V_149 ) ;
F_107 ( V_143 , V_143 -> V_155 ) ;
}
}
static int F_111 ( struct V_9 * V_143 )
{
unsigned long V_149 = V_143 -> V_70 . V_150 ;
int V_162 , V_154 ;
if ( ! V_149 )
return - V_157 ;
V_143 -> V_158 = F_109 ;
switch ( V_143 -> V_70 . V_156 ) {
case 1 :
V_143 -> V_70 . V_71 = F_92 ;
V_143 -> V_70 . V_74 = F_94 ;
break;
case 2 :
V_143 -> V_70 . V_71 = F_96 ;
V_143 -> V_70 . V_74 = F_98 ;
break;
case 4 :
V_143 -> V_70 . V_71 = F_99 ;
V_143 -> V_70 . V_74 = F_101 ;
break;
#ifdef F_104
case 8 :
V_143 -> V_70 . V_71 = F_103 ;
V_143 -> V_70 . V_74 = F_105 ;
break;
#endif
default:
F_30 ( V_143 -> V_79 , L_18 ,
V_143 -> V_70 . V_156 ) ;
return - V_159 ;
}
for ( V_154 = 0 ; V_154 < V_143 -> V_155 ; V_154 ++ ) {
if ( F_112 ( V_149 + V_154 * V_143 -> V_70 . V_151 ,
V_143 -> V_70 . V_156 , V_145 ) == NULL ) {
F_107 ( V_143 , V_154 ) ;
return - V_160 ;
}
}
V_162 = ( ( V_143 -> V_155 * V_143 -> V_70 . V_151 )
- ( V_143 -> V_70 . V_151 - V_143 -> V_70 . V_156 ) ) ;
V_143 -> V_70 . V_149 = F_113 ( V_149 , V_162 ) ;
if ( V_143 -> V_70 . V_149 == NULL ) {
F_107 ( V_143 , V_143 -> V_155 ) ;
return - V_160 ;
}
return 0 ;
}
static int F_114 ( const struct V_163 * V_164 , int * V_165 , char * V_166 ,
char * * V_167 )
{
char * V_168 ;
int V_169 ;
V_168 = strchr ( * V_167 , ',' ) ;
if ( ! V_168 ) {
F_115 (KERN_WARNING PFX L_19 , name) ;
return - V_159 ;
}
* V_168 = '\0' ;
V_168 ++ ;
for ( V_169 = 0 ; V_164 [ V_169 ] . V_166 ; V_169 ++ ) {
if ( strcmp ( * V_167 , V_164 [ V_169 ] . V_166 ) == 0 ) {
* V_165 = V_164 [ V_169 ] . V_165 ;
* V_167 = V_168 ;
return 0 ;
}
}
F_115 (KERN_WARNING PFX L_20 , name, *curr) ;
return - V_159 ;
}
static int F_116 ( const char * V_167 , const char * V_170 ,
const char * V_166 , int * V_165 )
{
char * V_171 ;
if ( strcmp ( V_167 , V_166 ) == 0 ) {
if ( ! V_170 ) {
F_115 (KERN_WARNING PFX
L_21 ,
curr) ;
return - V_159 ;
}
* V_165 = F_117 ( V_170 , & V_171 , 0 ) ;
if ( ( * V_171 != '\0' ) || ( * V_170 == '\0' ) ) {
F_115 (KERN_WARNING PFX
L_22 ,
curr) ;
return - V_159 ;
}
return 1 ;
}
return 0 ;
}
static struct V_9 * F_118 ( void )
{
struct V_9 * V_143 = F_119 ( sizeof( * V_143 ) , V_172 ) ;
if ( V_143 )
F_120 ( & V_143 -> V_105 ) ;
return V_143 ;
}
static int F_121 ( const char * V_165 , struct V_173 * V_174 )
{
char * V_175 = F_122 ( V_165 , V_172 ) ;
int V_19 ;
char * V_176 , * V_167 , * V_168 , * V_171 , * V_177 ;
enum V_178 V_179 ;
enum V_83 V_83 ;
int V_180 ;
unsigned long V_149 ;
int V_151 ;
int V_156 ;
int V_153 ;
int V_50 ;
int V_181 ;
int V_182 ;
int V_78 ;
struct V_9 * V_143 ;
if ( ! V_175 )
return - V_183 ;
V_78 = strlen ( V_175 ) ;
V_182 = V_78 - 1 ;
while ( ( V_182 >= 0 ) && isspace ( V_175 [ V_182 ] ) ) {
V_175 [ V_182 ] = '\0' ;
V_182 -- ;
}
for ( V_167 = V_175 ; V_167 ; V_167 = V_176 ) {
V_151 = 1 ;
V_156 = 1 ;
V_153 = 0 ;
V_50 = 0 ;
V_181 = 0 ;
V_176 = strchr ( V_167 , ':' ) ;
if ( V_176 ) {
* V_176 = '\0' ;
V_176 ++ ;
}
V_19 = F_114 ( V_184 , & V_182 , L_23 , & V_167 ) ;
if ( V_19 )
break;
V_179 = V_182 ;
V_19 = F_114 ( V_185 , & V_182 , L_24 , & V_167 ) ;
if ( V_19 )
break;
V_83 = V_182 ;
V_19 = F_114 ( V_186 , & V_180 , L_25 , & V_167 ) ;
if ( V_19 )
break;
V_168 = strchr ( V_167 , ',' ) ;
if ( V_168 ) {
* V_168 = '\0' ;
V_168 ++ ;
}
V_149 = F_117 ( V_167 , & V_171 , 0 ) ;
if ( ( * V_171 != '\0' ) || ( * V_167 == '\0' ) ) {
F_115 (KERN_WARNING PFX L_26
L_27 , curr) ;
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
V_19 = F_116 ( V_167 , V_177 , L_28 , & V_151 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = F_116 ( V_167 , V_177 , L_29 , & V_156 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = F_116 ( V_167 , V_177 , L_30 , & V_153 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = F_116 ( V_167 , V_177 , L_31 , & V_50 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = F_116 ( V_167 , V_177 , L_32 , & V_181 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = - V_159 ;
F_115 (KERN_WARNING PFX
L_33 ,
curr) ;
goto V_25;
}
if ( V_179 == V_187 ) {
V_143 = F_118 () ;
if ( ! V_143 ) {
V_19 = - V_183 ;
goto V_25;
}
V_143 -> V_141 = V_188 ;
V_143 -> V_83 = V_83 ;
V_143 -> V_70 . V_150 = V_149 ;
V_143 -> V_70 . V_189 = V_180 ;
if ( V_180 == V_190 )
V_143 -> V_191 = F_111 ;
else
V_143 -> V_191 = F_90 ;
V_143 -> V_70 . V_149 = NULL ;
V_143 -> V_70 . V_151 = V_151 ;
if ( ! V_143 -> V_70 . V_151 )
V_143 -> V_70 . V_151 = V_192 ;
V_143 -> V_70 . V_156 = V_156 ;
if ( ! V_143 -> V_70 . V_156 )
V_143 -> V_70 . V_156 = V_192 ;
V_143 -> V_70 . V_153 = V_153 ;
V_143 -> V_50 = V_50 ;
if ( V_143 -> V_50 )
V_143 -> V_135 = F_73 ;
V_143 -> V_193 = V_181 ;
V_19 = F_123 ( V_143 ) ;
if ( V_19 ) {
F_124 ( V_143 ) ;
goto V_25;
}
V_19 = F_125 ( V_143 ) ;
if ( V_19 ) {
F_126 ( V_143 ) ;
goto V_25;
}
} else {
struct V_9 * V_194 , * V_195 ;
F_127 ( & V_196 ) ;
F_128 (e, tmp_e, &smi_infos, link) {
if ( V_194 -> V_70 . V_189 != V_180 )
continue;
if ( V_194 -> V_83 != V_83 )
continue;
if ( V_194 -> V_70 . V_150 == V_149 )
F_126 ( V_194 ) ;
}
F_129 ( & V_196 ) ;
}
}
V_19 = V_78 ;
V_25:
F_124 ( V_175 ) ;
return V_19 ;
}
static int F_130 ( void )
{
int V_197 = - V_157 ;
int V_169 ;
struct V_9 * V_143 ;
for ( V_169 = 0 ; V_169 < V_198 ; V_169 ++ ) {
if ( ! V_199 [ V_169 ] && ! V_200 [ V_169 ] )
continue;
V_143 = F_118 () ;
if ( ! V_143 )
return - V_183 ;
V_143 -> V_141 = V_201 ;
F_115 (KERN_INFO PFX L_34 ) ;
if ( ! V_83 [ V_169 ] || strcmp ( V_83 [ V_169 ] , L_35 ) == 0 ) {
V_143 -> V_83 = V_202 ;
} else if ( strcmp ( V_83 [ V_169 ] , L_36 ) == 0 ) {
V_143 -> V_83 = V_203 ;
} else if ( strcmp ( V_83 [ V_169 ] , L_37 ) == 0 ) {
V_143 -> V_83 = V_84 ;
} else {
F_115 (KERN_WARNING PFX L_38
L_39 ,
i, si_type[i]) ;
F_124 ( V_143 ) ;
continue;
}
if ( V_199 [ V_169 ] ) {
V_143 -> V_191 = F_90 ;
V_143 -> V_70 . V_150 = V_199 [ V_169 ] ;
V_143 -> V_70 . V_189 = V_204 ;
} else if ( V_200 [ V_169 ] ) {
V_143 -> V_191 = F_111 ;
V_143 -> V_70 . V_150 = V_200 [ V_169 ] ;
V_143 -> V_70 . V_189 = V_190 ;
} else {
F_115 (KERN_WARNING PFX L_38
L_40
L_41 , i) ;
F_124 ( V_143 ) ;
continue;
}
V_143 -> V_70 . V_149 = NULL ;
V_143 -> V_70 . V_151 = V_205 [ V_169 ] ;
if ( ! V_143 -> V_70 . V_151 )
V_143 -> V_70 . V_151 = V_192 ;
V_143 -> V_70 . V_156 = V_206 [ V_169 ] ;
if ( ! V_143 -> V_70 . V_156 )
V_143 -> V_70 . V_156 = V_192 ;
V_143 -> V_70 . V_153 = V_207 [ V_169 ] ;
V_143 -> V_50 = V_208 [ V_169 ] ;
if ( V_143 -> V_50 )
V_143 -> V_135 = F_73 ;
V_143 -> V_193 = V_209 [ V_169 ] ;
if ( ! F_123 ( V_143 ) ) {
if ( F_125 ( V_143 ) )
F_126 ( V_143 ) ;
V_197 = 0 ;
} else {
F_124 ( V_143 ) ;
}
}
return V_197 ;
}
static T_4 F_131 ( T_5 V_210 ,
T_4 V_211 , void * V_212 )
{
struct V_9 * V_9 = V_212 ;
unsigned long V_103 ;
F_40 ( & ( V_9 -> V_105 ) , V_103 ) ;
F_25 ( V_9 , V_131 ) ;
F_1 ( L_42 ) ;
F_31 ( V_9 , 0 ) ;
F_42 ( & ( V_9 -> V_105 ) , V_103 ) ;
return V_213 ;
}
static void F_132 ( struct V_9 * V_143 )
{
if ( ! V_143 -> V_50 )
return;
F_133 ( NULL , V_143 -> V_50 , & F_131 ) ;
}
static int F_134 ( struct V_9 * V_143 )
{
T_6 V_214 ;
if ( ! V_143 -> V_50 )
return 0 ;
V_214 = F_135 ( NULL ,
V_143 -> V_50 ,
V_215 ,
& F_131 ,
V_143 ) ;
if ( V_214 != V_216 ) {
F_30 ( V_143 -> V_79 , L_43
L_16 , V_145 , V_143 -> V_50 ) ;
V_143 -> V_50 = 0 ;
return - V_159 ;
} else {
V_143 -> V_146 = F_132 ;
F_75 ( V_143 -> V_79 , L_44 , V_143 -> V_50 ) ;
return 0 ;
}
}
static int F_136 ( struct V_217 * V_218 )
{
struct V_9 * V_143 ;
int V_19 ;
if ( V_218 -> V_219 != 1 ) {
F_115 (KERN_INFO PFX L_45 , spmi->IPMIlegacy) ;
return - V_157 ;
}
V_143 = F_118 () ;
if ( ! V_143 ) {
F_115 (KERN_ERR PFX L_46 ) ;
return - V_183 ;
}
V_143 -> V_141 = V_220 ;
F_115 (KERN_INFO PFX L_47 ) ;
switch ( V_218 -> V_221 ) {
case 1 :
V_143 -> V_83 = V_202 ;
break;
case 2 :
V_143 -> V_83 = V_203 ;
break;
case 3 :
V_143 -> V_83 = V_84 ;
break;
case 4 :
F_124 ( V_143 ) ;
return - V_160 ;
default:
F_115 (KERN_INFO PFX L_48 ,
spmi->InterfaceType) ;
F_124 ( V_143 ) ;
return - V_160 ;
}
if ( V_218 -> V_222 & 1 ) {
V_143 -> V_50 = V_218 -> V_223 ;
V_143 -> V_135 = F_134 ;
} else if ( V_218 -> V_222 & 2 ) {
V_143 -> V_50 = V_218 -> V_224 ;
V_143 -> V_135 = F_73 ;
} else {
V_143 -> V_50 = 0 ;
V_143 -> V_135 = NULL ;
}
if ( V_218 -> V_149 . V_225 ) {
V_143 -> V_70 . V_151 = V_218 -> V_149 . V_225 / 8 ;
} else {
V_143 -> V_70 . V_151 = V_192 ;
}
V_143 -> V_70 . V_156 = V_143 -> V_70 . V_151 ;
V_143 -> V_70 . V_153 = V_218 -> V_149 . V_226 ;
if ( V_218 -> V_149 . V_227 == V_228 ) {
V_143 -> V_191 = F_111 ;
V_143 -> V_70 . V_189 = V_190 ;
} else if ( V_218 -> V_149 . V_227 == V_229 ) {
V_143 -> V_191 = F_90 ;
V_143 -> V_70 . V_189 = V_204 ;
} else {
F_124 ( V_143 ) ;
F_115 (KERN_WARNING PFX L_49 ) ;
return - V_160 ;
}
V_143 -> V_70 . V_150 = V_218 -> V_149 . V_230 ;
F_137 ( L_50 ,
( V_143 -> V_70 . V_189 == V_204 ) ? L_51 : L_52 ,
V_143 -> V_70 . V_150 , V_143 -> V_70 . V_156 , V_143 -> V_70 . V_151 ,
V_143 -> V_50 ) ;
V_19 = F_123 ( V_143 ) ;
if ( V_19 )
F_124 ( V_143 ) ;
return V_19 ;
}
static void F_138 ( void )
{
T_6 V_214 ;
struct V_217 * V_218 ;
int V_169 ;
if ( V_231 )
return;
if ( V_232 )
return;
for ( V_169 = 0 ; ; V_169 ++ ) {
V_214 = F_139 ( V_233 , V_169 + 1 ,
(struct V_234 * * ) & V_218 ) ;
if ( V_214 != V_216 )
return;
F_136 ( V_218 ) ;
}
}
static int F_140 ( const struct V_235 * V_236 ,
struct V_237 * V_238 )
{
const T_1 * V_16 = ( const T_1 * ) V_236 ;
unsigned long V_239 ;
T_1 V_240 ;
T_1 V_78 = V_236 -> V_241 ;
V_238 -> type = V_16 [ 4 ] ;
memcpy ( & V_239 , V_16 + 8 , sizeof( unsigned long ) ) ;
if ( V_78 >= 0x11 ) {
if ( V_239 & 1 ) {
V_239 &= 0xFFFE ;
V_238 -> V_180 = V_204 ;
} else
V_238 -> V_180 = V_190 ;
V_238 -> V_239 = V_239 | ( ( V_16 [ 0x10 ] & 0x10 ) >> 4 ) ;
V_238 -> V_50 = V_16 [ 0x11 ] ;
V_240 = ( V_16 [ 0x10 ] & 0xC0 ) >> 6 ;
switch ( V_240 ) {
case 0x00 :
V_238 -> V_148 = 1 ;
break;
case 0x01 :
V_238 -> V_148 = 4 ;
break;
case 0x02 :
V_238 -> V_148 = 16 ;
break;
default:
return - V_160 ;
}
} else {
V_238 -> V_239 = V_239 & 0xfffe ;
V_238 -> V_180 = V_204 ;
V_238 -> V_148 = 1 ;
}
V_238 -> V_193 = V_16 [ 6 ] ;
return 0 ;
}
static void F_141 ( struct V_237 * V_242 )
{
struct V_9 * V_143 ;
V_143 = F_118 () ;
if ( ! V_143 ) {
F_115 (KERN_ERR PFX L_53 ) ;
return;
}
V_143 -> V_141 = V_243 ;
F_115 (KERN_INFO PFX L_54 ) ;
switch ( V_242 -> type ) {
case 0x01 :
V_143 -> V_83 = V_202 ;
break;
case 0x02 :
V_143 -> V_83 = V_203 ;
break;
case 0x03 :
V_143 -> V_83 = V_84 ;
break;
default:
F_124 ( V_143 ) ;
return;
}
switch ( V_242 -> V_180 ) {
case V_190 :
V_143 -> V_191 = F_111 ;
V_143 -> V_70 . V_189 = V_190 ;
break;
case V_204 :
V_143 -> V_191 = F_90 ;
V_143 -> V_70 . V_189 = V_204 ;
break;
default:
F_124 ( V_143 ) ;
F_115 (KERN_WARNING PFX L_55 ,
ipmi_data->addr_space) ;
return;
}
V_143 -> V_70 . V_150 = V_242 -> V_239 ;
V_143 -> V_70 . V_151 = V_242 -> V_148 ;
if ( ! V_143 -> V_70 . V_151 )
V_143 -> V_70 . V_151 = V_192 ;
V_143 -> V_70 . V_156 = V_192 ;
V_143 -> V_70 . V_153 = 0 ;
V_143 -> V_193 = V_242 -> V_193 ;
V_143 -> V_50 = V_242 -> V_50 ;
if ( V_143 -> V_50 )
V_143 -> V_135 = F_73 ;
F_137 ( L_56 ,
( V_143 -> V_70 . V_189 == V_204 ) ? L_51 : L_52 ,
V_143 -> V_70 . V_150 , V_143 -> V_70 . V_156 , V_143 -> V_70 . V_151 ,
V_143 -> V_50 ) ;
if ( F_123 ( V_143 ) )
F_124 ( V_143 ) ;
}
static void F_142 ( void )
{
const struct V_244 * V_79 = NULL ;
struct V_237 V_16 ;
int V_19 ;
while ( ( V_79 = F_143 ( V_245 , NULL , V_79 ) ) ) {
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_19 = F_140 ( ( const struct V_235 * ) V_79 -> V_246 ,
& V_16 ) ;
if ( ! V_19 )
F_141 ( & V_16 ) ;
}
}
static void F_144 ( struct V_9 * V_143 )
{
struct V_247 * V_248 = V_143 -> V_249 ;
F_145 ( V_248 ) ;
}
static int F_146 ( struct V_9 * V_143 )
{
if ( V_143 -> V_83 == V_202 ) {
unsigned char V_214 ;
int V_151 ;
V_143 -> V_70 . V_156 = V_250 ;
V_143 -> V_70 . V_153 = 0 ;
V_143 -> V_155 = 2 ;
V_143 -> V_26 = & V_251 ;
for ( V_151 = V_192 ; V_151 <= 16 ; ) {
V_143 -> V_70 . V_151 = V_151 ;
if ( V_143 -> V_191 ( V_143 ) ) {
F_147 ( V_143 -> V_79 ,
L_57 ) ;
return V_192 ;
}
V_143 -> V_70 . V_74 ( & V_143 -> V_70 , 1 , 0x10 ) ;
V_214 = V_143 -> V_70 . V_71 ( & V_143 -> V_70 , 1 ) ;
V_143 -> V_158 ( V_143 ) ;
if ( V_214 )
return V_151 ;
V_151 *= 4 ;
}
}
return V_192 ;
}
static int F_148 ( struct V_247 * V_248 ,
const struct V_252 * V_253 )
{
int V_19 ;
int V_254 = V_248 -> V_255 & V_256 ;
struct V_9 * V_143 ;
V_143 = F_118 () ;
if ( ! V_143 )
return - V_183 ;
V_143 -> V_141 = V_257 ;
F_75 ( & V_248 -> V_79 , L_58 ) ;
switch ( V_254 ) {
case V_258 :
V_143 -> V_83 = V_203 ;
break;
case V_259 :
V_143 -> V_83 = V_202 ;
break;
case V_260 :
V_143 -> V_83 = V_84 ;
break;
default:
F_124 ( V_143 ) ;
F_75 ( & V_248 -> V_79 , L_59 , V_254 ) ;
return - V_183 ;
}
V_19 = F_149 ( V_248 ) ;
if ( V_19 ) {
F_147 ( & V_248 -> V_79 , L_60 ) ;
F_124 ( V_143 ) ;
return V_19 ;
}
V_143 -> V_261 = F_144 ;
V_143 -> V_249 = V_248 ;
if ( F_150 ( V_248 , 0 ) & V_262 ) {
V_143 -> V_191 = F_90 ;
V_143 -> V_70 . V_189 = V_204 ;
} else {
V_143 -> V_191 = F_111 ;
V_143 -> V_70 . V_189 = V_190 ;
}
V_143 -> V_70 . V_150 = F_151 ( V_248 , 0 ) ;
V_143 -> V_70 . V_151 = F_146 ( V_143 ) ;
V_143 -> V_70 . V_156 = V_250 ;
V_143 -> V_70 . V_153 = 0 ;
V_143 -> V_50 = V_248 -> V_50 ;
if ( V_143 -> V_50 )
V_143 -> V_135 = F_73 ;
V_143 -> V_79 = & V_248 -> V_79 ;
F_152 ( V_248 , V_143 ) ;
F_75 ( & V_248 -> V_79 , L_61 ,
& V_248 -> V_263 [ 0 ] , V_143 -> V_70 . V_156 , V_143 -> V_70 . V_151 ,
V_143 -> V_50 ) ;
V_19 = F_123 ( V_143 ) ;
if ( V_19 ) {
F_124 ( V_143 ) ;
F_145 ( V_248 ) ;
}
return V_19 ;
}
static void F_153 ( struct V_247 * V_248 )
{
struct V_9 * V_143 = F_154 ( V_248 ) ;
F_126 ( V_143 ) ;
}
static int F_155 ( struct V_264 * V_79 )
{
const struct V_265 * V_266 ;
struct V_9 * V_143 ;
struct V_263 V_263 ;
const T_7 * V_156 , * V_151 , * V_153 ;
struct V_267 * V_268 = V_79 -> V_79 . V_269 ;
int V_197 ;
int V_270 ;
F_75 ( & V_79 -> V_79 , L_62 ) ;
V_266 = F_156 ( V_271 , & V_79 -> V_79 ) ;
if ( ! V_266 )
return - V_157 ;
if ( ! F_157 ( V_268 ) )
return - V_159 ;
V_197 = F_158 ( V_268 , 0 , & V_263 ) ;
if ( V_197 ) {
F_30 ( & V_79 -> V_79 , V_272 L_63 ) ;
return V_197 ;
}
V_156 = F_159 ( V_268 , L_64 , & V_270 ) ;
if ( V_156 && V_270 != 4 ) {
F_30 ( & V_79 -> V_79 , V_272 L_65 ) ;
return - V_159 ;
}
V_151 = F_159 ( V_268 , L_66 , & V_270 ) ;
if ( V_151 && V_270 != 4 ) {
F_30 ( & V_79 -> V_79 , V_272 L_67 ) ;
return - V_159 ;
}
V_153 = F_159 ( V_268 , L_68 , & V_270 ) ;
if ( V_153 && V_270 != 4 ) {
F_30 ( & V_79 -> V_79 , V_272 L_69 ) ;
return - V_159 ;
}
V_143 = F_118 () ;
if ( ! V_143 ) {
F_147 ( & V_79 -> V_79 ,
L_70 ) ;
return - V_183 ;
}
V_143 -> V_83 = (enum V_83 ) V_266 -> V_16 ;
V_143 -> V_141 = V_273 ;
V_143 -> V_135 = F_73 ;
if ( V_263 . V_103 & V_262 ) {
V_143 -> V_191 = F_90 ;
V_143 -> V_70 . V_189 = V_204 ;
} else {
V_143 -> V_191 = F_111 ;
V_143 -> V_70 . V_189 = V_190 ;
}
V_143 -> V_70 . V_150 = V_263 . V_274 ;
V_143 -> V_70 . V_156 = V_156 ? F_160 ( V_156 ) : V_250 ;
V_143 -> V_70 . V_151 = V_151 ? F_160 ( V_151 ) : V_192 ;
V_143 -> V_70 . V_153 = V_153 ? F_160 ( V_153 ) : 0 ;
V_143 -> V_50 = F_161 ( V_79 -> V_79 . V_269 , 0 ) ;
V_143 -> V_79 = & V_79 -> V_79 ;
F_162 ( & V_79 -> V_79 , L_71 ,
V_143 -> V_70 . V_150 , V_143 -> V_70 . V_156 , V_143 -> V_70 . V_151 ,
V_143 -> V_50 ) ;
F_163 ( & V_79 -> V_79 , V_143 ) ;
V_197 = F_123 ( V_143 ) ;
if ( V_197 ) {
F_124 ( V_143 ) ;
return V_197 ;
}
return 0 ;
}
static int F_155 ( struct V_264 * V_79 )
{
return - V_157 ;
}
static int F_164 ( struct V_264 * V_79 )
{
struct V_9 * V_143 ;
struct V_263 * V_275 , * V_276 ;
T_5 V_277 ;
T_6 V_214 ;
unsigned long long V_278 ;
int V_19 = - V_159 ;
if ( ! V_279 )
return 0 ;
V_277 = F_165 ( & V_79 -> V_79 ) ;
if ( ! V_277 )
return - V_157 ;
V_143 = F_118 () ;
if ( ! V_143 )
return - V_183 ;
V_143 -> V_141 = V_280 ;
F_75 ( & V_79 -> V_79 , V_272 L_72 ) ;
V_143 -> V_142 . V_281 . T_5 = V_277 ;
V_214 = F_166 ( V_277 , L_73 , NULL , & V_278 ) ;
if ( F_167 ( V_214 ) ) {
F_147 ( & V_79 -> V_79 , L_74 ) ;
goto V_282;
}
switch ( V_278 ) {
case 1 :
V_143 -> V_83 = V_202 ;
break;
case 2 :
V_143 -> V_83 = V_203 ;
break;
case 3 :
V_143 -> V_83 = V_84 ;
break;
case 4 :
V_19 = - V_157 ;
goto V_282;
default:
F_75 ( & V_79 -> V_79 , L_75 , V_278 ) ;
goto V_282;
}
V_275 = F_168 ( V_79 , V_262 , 0 ) ;
if ( V_275 ) {
V_143 -> V_191 = F_90 ;
V_143 -> V_70 . V_189 = V_204 ;
} else {
V_275 = F_168 ( V_79 , V_283 , 0 ) ;
if ( V_275 ) {
V_143 -> V_191 = F_111 ;
V_143 -> V_70 . V_189 = V_190 ;
}
}
if ( ! V_275 ) {
F_147 ( & V_79 -> V_79 , L_76 ) ;
goto V_282;
}
V_143 -> V_70 . V_150 = V_275 -> V_274 ;
V_143 -> V_70 . V_151 = V_192 ;
V_276 = F_168 ( V_79 ,
( V_143 -> V_70 . V_189 == V_204 ) ?
V_262 : V_283 ,
1 ) ;
if ( V_276 ) {
if ( V_276 -> V_274 > V_143 -> V_70 . V_150 )
V_143 -> V_70 . V_151 =
V_276 -> V_274 - V_143 -> V_70 . V_150 ;
}
V_143 -> V_70 . V_156 = V_192 ;
V_143 -> V_70 . V_153 = 0 ;
V_214 = F_166 ( V_277 , L_77 , NULL , & V_278 ) ;
if ( F_169 ( V_214 ) ) {
V_143 -> V_50 = V_278 ;
V_143 -> V_135 = F_134 ;
} else {
int V_50 = F_170 ( V_79 , 0 ) ;
if ( V_50 > 0 ) {
V_143 -> V_50 = V_50 ;
V_143 -> V_135 = F_73 ;
}
}
V_143 -> V_79 = & V_79 -> V_79 ;
F_171 ( V_79 , V_143 ) ;
F_75 ( V_143 -> V_79 , L_61 ,
V_275 , V_143 -> V_70 . V_156 , V_143 -> V_70 . V_151 ,
V_143 -> V_50 ) ;
V_19 = F_123 ( V_143 ) ;
if ( V_19 )
F_124 ( V_143 ) ;
return V_19 ;
V_282:
F_124 ( V_143 ) ;
return V_19 ;
}
static int F_164 ( struct V_264 * V_79 )
{
return - V_157 ;
}
static int F_172 ( struct V_264 * V_79 )
{
if ( F_155 ( V_79 ) == 0 )
return 0 ;
return F_164 ( V_79 ) ;
}
static int F_173 ( struct V_264 * V_79 )
{
struct V_9 * V_143 = F_174 ( & V_79 -> V_79 ) ;
F_126 ( V_143 ) ;
return 0 ;
}
static int F_175 ( struct V_284 * V_79 )
{
struct V_9 * V_143 ;
int V_19 ;
V_143 = F_118 () ;
if ( ! V_143 ) {
F_147 ( & V_79 -> V_79 ,
L_78 ) ;
return - V_183 ;
}
V_143 -> V_83 = V_202 ;
V_143 -> V_141 = V_273 ;
V_143 -> V_191 = F_111 ;
V_143 -> V_70 . V_189 = V_190 ;
V_143 -> V_70 . V_150 = V_79 -> V_285 . V_274 ;
V_143 -> V_70 . V_156 = 1 ;
V_143 -> V_70 . V_151 = 1 ;
V_143 -> V_70 . V_153 = 0 ;
V_143 -> V_50 = 0 ;
V_143 -> V_135 = NULL ;
V_143 -> V_79 = & V_79 -> V_79 ;
F_162 ( & V_79 -> V_79 , L_79 , V_143 -> V_70 . V_150 ) ;
F_163 ( & V_79 -> V_79 , V_143 ) ;
V_19 = F_123 ( V_143 ) ;
if ( V_19 ) {
F_124 ( V_143 ) ;
return V_19 ;
}
return 0 ;
}
static int F_176 ( struct V_284 * V_79 )
{
F_126 ( F_174 ( & V_79 -> V_79 ) ) ;
return 0 ;
}
static int F_177 ( struct V_9 * V_9 )
{
enum V_18 V_108 ;
V_108 = V_9 -> V_26 -> V_89 ( V_9 -> V_28 , 0 ) ;
for (; ; ) {
if ( V_108 == V_114 ||
V_108 == V_286 ) {
F_178 ( 1 ) ;
V_108 = V_9 -> V_26 -> V_89 (
V_9 -> V_28 , F_179 ( 1 ) ) ;
} else if ( V_108 == V_24 ) {
V_108 = V_9 -> V_26 -> V_89 (
V_9 -> V_28 , 0 ) ;
} else
break;
}
if ( V_108 == V_92 )
return - V_157 ;
return 0 ;
}
static int F_180 ( struct V_9 * V_9 )
{
unsigned char V_1 [ 2 ] ;
unsigned char * V_287 ;
unsigned long V_288 ;
int V_19 = 0 ;
V_287 = F_181 ( V_76 , V_172 ) ;
if ( ! V_287 )
return - V_183 ;
V_1 [ 0 ] = V_39 << 2 ;
V_1 [ 1 ] = V_289 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 2 ) ;
V_19 = F_177 ( V_9 ) ;
if ( V_19 )
goto V_25;
V_288 = V_9 -> V_26 -> V_75 ( V_9 -> V_28 ,
V_287 , V_76 ) ;
V_19 = F_182 ( V_287 , V_288 , & V_9 -> V_290 ) ;
V_25:
F_124 ( V_287 ) ;
return V_19 ;
}
static int F_183 ( struct V_9 * V_9 , T_1 * V_62 )
{
unsigned char V_1 [ 3 ] ;
unsigned char * V_287 ;
unsigned long V_288 ;
int V_19 ;
V_287 = F_181 ( V_76 , V_172 ) ;
if ( ! V_287 )
return - V_183 ;
V_1 [ 0 ] = V_39 << 2 ;
V_1 [ 1 ] = V_40 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 2 ) ;
V_19 = F_177 ( V_9 ) ;
if ( V_19 ) {
F_30 ( V_9 -> V_79 ,
L_80 ,
V_19 ) ;
goto V_25;
}
V_288 = V_9 -> V_26 -> V_75 ( V_9 -> V_28 ,
V_287 , V_76 ) ;
if ( V_288 < 4 ||
V_287 [ 0 ] != ( V_39 | 1 ) << 2 ||
V_287 [ 1 ] != V_40 ||
V_287 [ 2 ] != 0 ) {
F_30 ( V_9 -> V_79 ,
L_81 ,
V_288 , V_287 [ 0 ] , V_287 [ 1 ] , V_287 [ 2 ] ) ;
V_19 = - V_159 ;
goto V_25;
} else {
* V_62 = V_287 [ 3 ] ;
}
V_25:
F_124 ( V_287 ) ;
return V_19 ;
}
static int F_184 ( struct V_9 * V_9 , T_1 V_62 )
{
unsigned char V_1 [ 3 ] ;
unsigned char * V_287 ;
unsigned long V_288 ;
int V_19 ;
V_287 = F_181 ( V_76 , V_172 ) ;
if ( ! V_287 )
return - V_183 ;
V_1 [ 0 ] = V_39 << 2 ;
V_1 [ 1 ] = V_86 ;
V_1 [ 2 ] = V_62 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 3 ) ;
V_19 = F_177 ( V_9 ) ;
if ( V_19 ) {
F_30 ( V_9 -> V_79 ,
L_82 ,
V_19 ) ;
goto V_25;
}
V_288 = V_9 -> V_26 -> V_75 ( V_9 -> V_28 ,
V_287 , V_76 ) ;
if ( V_288 < 3 ||
V_287 [ 0 ] != ( V_39 | 1 ) << 2 ||
V_287 [ 1 ] != V_86 ) {
F_30 ( V_9 -> V_79 ,
L_83 ,
V_288 , V_287 [ 0 ] , V_287 [ 1 ] ) ;
V_19 = - V_159 ;
goto V_25;
}
if ( V_287 [ 2 ] != 0 )
V_19 = 1 ;
V_25:
F_124 ( V_287 ) ;
return V_19 ;
}
static void F_185 ( struct V_9 * V_9 )
{
T_1 V_62 = 0 ;
int V_19 ;
V_19 = F_183 ( V_9 , & V_62 ) ;
if ( ! V_19 ) {
if ( ( V_62 & V_67 ) == 0 )
return;
V_62 &= ~ V_67 ;
V_19 = F_184 ( V_9 , V_62 ) ;
}
if ( V_19 < 0 ) {
F_147 ( V_9 -> V_79 ,
L_84 , V_19 ) ;
return;
}
if ( V_19 ) {
F_30 ( V_9 -> V_79 ,
L_85 ) ;
V_9 -> V_65 = true ;
}
}
static void F_186 ( struct V_9 * V_9 )
{
T_1 V_62 = 0 ;
int V_19 ;
if ( ! V_9 -> V_50 )
return;
V_19 = F_183 ( V_9 , & V_62 ) ;
if ( ! V_19 ) {
V_62 |= V_67 ;
V_19 = F_184 ( V_9 , V_62 ) ;
}
if ( V_19 < 0 ) {
F_147 ( V_9 -> V_79 ,
L_86 , V_19 ) ;
return;
}
if ( V_19 ) {
F_30 ( V_9 -> V_79 ,
L_87 ) ;
V_9 -> V_65 = true ;
V_9 -> V_66 = true ;
}
}
static int F_187 ( struct V_9 * V_9 )
{
unsigned char V_1 [ 3 ] ;
unsigned char * V_287 ;
unsigned long V_288 ;
int V_19 = 0 ;
V_287 = F_181 ( V_76 , V_172 ) ;
if ( ! V_287 )
return - V_183 ;
V_1 [ 0 ] = V_39 << 2 ;
V_1 [ 1 ] = V_40 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 2 ) ;
V_19 = F_177 ( V_9 ) ;
if ( V_19 ) {
F_115 (KERN_WARNING PFX L_88
L_89
L_90 ) ;
goto V_25;
}
V_288 = V_9 -> V_26 -> V_75 ( V_9 -> V_28 ,
V_287 , V_76 ) ;
if ( V_288 < 4 ||
V_287 [ 0 ] != ( V_39 | 1 ) << 2 ||
V_287 [ 1 ] != V_40 ||
V_287 [ 2 ] != 0 ) {
F_115 (KERN_WARNING PFX L_91
L_92 ) ;
V_19 = - V_159 ;
goto V_25;
}
if ( V_287 [ 3 ] & V_64 ) {
V_9 -> V_63 = true ;
goto V_25;
}
V_1 [ 0 ] = V_39 << 2 ;
V_1 [ 1 ] = V_86 ;
V_1 [ 2 ] = V_287 [ 3 ] | V_64 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 3 ) ;
V_19 = F_177 ( V_9 ) ;
if ( V_19 ) {
F_115 (KERN_WARNING PFX L_93
L_94
L_90 ) ;
goto V_25;
}
V_288 = V_9 -> V_26 -> V_75 ( V_9 -> V_28 ,
V_287 , V_76 ) ;
if ( V_288 < 3 ||
V_287 [ 0 ] != ( V_39 | 1 ) << 2 ||
V_287 [ 1 ] != V_86 ) {
F_115 (KERN_WARNING PFX L_95
L_96 ) ;
V_19 = - V_159 ;
goto V_25;
}
if ( V_287 [ 2 ] != 0 )
V_19 = - V_291 ;
else
V_9 -> V_63 = true ;
V_25:
F_124 ( V_287 ) ;
return V_19 ;
}
static int F_188 ( struct V_292 * V_293 , void * V_164 )
{
struct V_9 * V_139 = V_293 -> V_294 ;
F_189 ( V_293 , L_97 , V_295 [ V_139 -> V_83 ] ) ;
return 0 ;
}
static int F_190 ( struct V_296 * V_296 , struct V_297 * V_297 )
{
return F_191 ( V_297 , F_188 , F_192 ( V_296 ) ) ;
}
static int F_193 ( struct V_292 * V_293 , void * V_164 )
{
struct V_9 * V_139 = V_293 -> V_294 ;
F_189 ( V_293 , L_98 ,
V_139 -> V_50 && ! V_139 -> V_51 ) ;
F_189 ( V_293 , L_99 ,
F_194 ( V_139 , V_130 ) ) ;
F_189 ( V_293 , L_100 ,
F_194 ( V_139 , V_128 ) ) ;
F_189 ( V_293 , L_101 ,
F_194 ( V_139 , V_98 ) ) ;
F_189 ( V_293 , L_102 ,
F_194 ( V_139 , V_131 ) ) ;
F_189 ( V_293 , L_103 ,
F_194 ( V_139 , V_96 ) ) ;
F_189 ( V_293 , L_104 ,
F_194 ( V_139 , V_298 ) ) ;
F_189 ( V_293 , L_105 ,
F_194 ( V_139 , V_93 ) ) ;
F_189 ( V_293 , L_106 ,
F_194 ( V_139 , V_91 ) ) ;
F_189 ( V_293 , L_107 ,
F_194 ( V_139 , V_81 ) ) ;
F_189 ( V_293 , L_108 ,
F_194 ( V_139 , V_55 ) ) ;
F_189 ( V_293 , L_109 ,
F_194 ( V_139 , V_82 ) ) ;
return 0 ;
}
static int F_195 ( struct V_296 * V_296 , struct V_297 * V_297 )
{
return F_191 ( V_297 , F_193 , F_192 ( V_296 ) ) ;
}
static int F_196 ( struct V_292 * V_293 , void * V_164 )
{
struct V_9 * V_139 = V_293 -> V_294 ;
F_189 ( V_293 ,
L_110 ,
V_295 [ V_139 -> V_83 ] ,
V_299 [ V_139 -> V_70 . V_189 ] ,
V_139 -> V_70 . V_150 ,
V_139 -> V_70 . V_151 ,
V_139 -> V_70 . V_156 ,
V_139 -> V_70 . V_153 ,
V_139 -> V_50 ,
V_139 -> V_193 ) ;
return 0 ;
}
static int F_197 ( struct V_296 * V_296 , struct V_297 * V_297 )
{
return F_191 ( V_297 , F_196 , F_192 ( V_296 ) ) ;
}
static int F_198 ( struct V_9 * V_9 )
{
V_9 -> V_54 = ( ( V_9 -> V_54 & ~ V_58 ) |
V_56 ) ;
return 1 ;
}
static void F_199 ( struct V_9 * V_9 )
{
struct V_300 * V_301 = & V_9 -> V_290 ;
if ( V_301 -> V_302 == V_303 ) {
if ( V_301 -> V_290 == V_304 &&
V_301 -> V_305 == V_306 &&
V_301 -> V_307 == V_308 ) {
V_9 -> V_59 =
F_198 ;
} else if ( F_200 ( V_301 ) < 1 ||
( F_200 ( V_301 ) == 1 &&
F_201 ( V_301 ) < 5 ) ) {
V_9 -> V_59 =
F_198 ;
}
}
}
static void F_202 ( struct V_9 * V_9 )
{
struct V_10 * V_1 = V_9 -> V_13 ;
V_1 -> V_15 [ 0 ] = V_1 -> V_16 [ 0 ] | 4 ;
V_1 -> V_15 [ 1 ] = V_1 -> V_16 [ 1 ] ;
V_1 -> V_15 [ 2 ] = V_309 ;
V_1 -> V_17 = 3 ;
V_9 -> V_13 = NULL ;
F_6 ( V_9 , V_1 ) ;
}
static int F_203 ( struct V_6 * V_310 ,
unsigned long V_311 ,
void * V_312 )
{
struct V_9 * V_9 = V_312 ;
unsigned char * V_16 = V_9 -> V_13 -> V_16 ;
unsigned int V_35 = V_9 -> V_13 -> V_29 ;
if ( V_35 >= 8 &&
( V_16 [ 0 ] >> 2 ) == V_313 &&
V_16 [ 1 ] == V_314 &&
V_16 [ 7 ] == 0x3A ) {
F_202 ( V_9 ) ;
return V_315 ;
}
return V_316 ;
}
static void
F_204 ( struct V_9 * V_9 )
{
struct V_300 * V_301 = & V_9 -> V_290 ;
if ( V_301 -> V_302 == V_303 &&
V_9 -> V_83 == V_84 )
F_4 ( & V_317 ) ;
}
static void F_205 ( struct V_9 * V_9 )
{
F_199 ( V_9 ) ;
}
static void F_206 ( struct V_9 * V_9 )
{
F_204 ( V_9 ) ;
}
static void F_207 ( struct V_9 * V_9 )
{
F_185 ( V_9 ) ;
F_186 ( V_9 ) ;
}
static inline void F_208 ( struct V_9 * V_9 )
{
if ( V_9 -> V_37 != NULL )
F_209 ( V_9 -> V_37 ) ;
if ( V_9 -> V_34 )
F_210 ( & V_9 -> V_33 ) ;
}
static int F_211 ( struct V_9 * V_143 )
{
struct V_9 * V_194 ;
F_212 (e, &smi_infos, link) {
if ( V_194 -> V_70 . V_189 != V_143 -> V_70 . V_189 )
continue;
if ( V_194 -> V_70 . V_150 == V_143 -> V_70 . V_150 )
return 0 ;
}
return 1 ;
}
static int F_123 ( struct V_9 * V_134 )
{
int V_19 = 0 ;
F_115 (KERN_INFO PFX L_111 ,
ipmi_addr_src_to_str(new_smi->addr_source),
si_to_str[new_smi->si_type]) ;
F_127 ( & V_196 ) ;
if ( ! F_211 ( V_134 ) ) {
F_115 ( V_318 L_112 ) ;
V_19 = - V_319 ;
goto V_320;
}
F_115 ( V_318 L_113 ) ;
V_134 -> V_11 = NULL ;
V_134 -> V_28 = NULL ;
V_134 -> V_26 = NULL ;
F_213 ( & V_134 -> V_321 , & V_322 ) ;
V_320:
F_129 ( & V_196 ) ;
return V_19 ;
}
static int F_125 ( struct V_9 * V_134 )
{
int V_19 = 0 ;
int V_169 ;
F_115 (KERN_INFO PFX L_114
L_115
L_116 ,
ipmi_addr_src_to_str(new_smi->addr_source),
si_to_str[new_smi->si_type],
addr_space_to_str[new_smi->io.addr_type],
new_smi->io.addr_data,
new_smi->slave_addr, new_smi->irq) ;
switch ( V_134 -> V_83 ) {
case V_202 :
V_134 -> V_26 = & V_251 ;
break;
case V_203 :
V_134 -> V_26 = & V_323 ;
break;
case V_84 :
V_134 -> V_26 = & V_324 ;
break;
default:
V_19 = - V_160 ;
goto V_320;
}
V_134 -> V_28 = F_181 ( V_134 -> V_26 -> V_35 () , V_172 ) ;
if ( ! V_134 -> V_28 ) {
F_115 (KERN_ERR PFX
L_117 ) ;
V_19 = - V_183 ;
goto V_320;
}
V_134 -> V_155 = V_134 -> V_26 -> V_325 ( V_134 -> V_28 ,
& V_134 -> V_70 ) ;
V_19 = V_134 -> V_191 ( V_134 ) ;
if ( V_19 ) {
F_115 (KERN_ERR PFX L_118 ) ;
goto V_320;
}
if ( V_134 -> V_26 -> V_326 ( V_134 -> V_28 ) ) {
if ( V_134 -> V_141 )
F_115 (KERN_INFO PFX L_119 ) ;
V_19 = - V_157 ;
goto V_320;
}
V_19 = F_180 ( V_134 ) ;
if ( V_19 ) {
if ( V_134 -> V_141 )
F_115 (KERN_INFO PFX L_120
L_121 ) ;
goto V_320;
}
F_205 ( V_134 ) ;
F_206 ( V_134 ) ;
F_207 ( V_134 ) ;
V_134 -> V_20 = NULL ;
V_134 -> V_13 = NULL ;
F_34 ( & V_134 -> V_99 , 0 ) ;
V_134 -> V_104 = false ;
for ( V_169 = 0 ; V_169 < V_327 ; V_169 ++ )
F_34 ( & V_134 -> V_328 [ V_169 ] , 0 ) ;
V_134 -> V_51 = true ;
F_34 ( & V_134 -> V_120 , 0 ) ;
V_134 -> V_111 = V_329 ;
V_329 ++ ;
V_19 = F_187 ( V_134 ) ;
if ( V_19 == 0 )
V_134 -> V_122 = true ;
F_17 ( V_134 , false ) ;
if ( V_134 -> V_50 ) {
V_134 -> V_51 = false ;
F_34 ( & V_134 -> V_99 , 1 ) ;
}
if ( ! V_134 -> V_79 ) {
V_134 -> V_248 = F_214 ( L_122 ,
V_134 -> V_111 ) ;
if ( ! V_134 -> V_248 ) {
F_115 (KERN_ERR PFX
L_123 ) ;
goto V_320;
}
V_134 -> V_79 = & V_134 -> V_248 -> V_79 ;
V_134 -> V_79 -> V_330 = & V_331 . V_330 ;
V_19 = F_215 ( V_134 -> V_248 ) ;
if ( V_19 ) {
F_115 (KERN_ERR PFX
L_124
L_125 ,
rv) ;
goto V_320;
}
V_134 -> V_332 = true ;
}
V_19 = F_216 ( & V_26 ,
V_134 ,
& V_134 -> V_290 ,
V_134 -> V_79 ,
V_134 -> V_193 ) ;
if ( V_19 ) {
F_147 ( V_134 -> V_79 , L_126 ,
V_19 ) ;
goto V_333;
}
V_19 = F_217 ( V_134 -> V_11 , L_127 ,
& V_334 ,
V_134 ) ;
if ( V_19 ) {
F_147 ( V_134 -> V_79 , L_128 , V_19 ) ;
goto V_333;
}
V_19 = F_217 ( V_134 -> V_11 , L_129 ,
& V_335 ,
V_134 ) ;
if ( V_19 ) {
F_147 ( V_134 -> V_79 , L_128 , V_19 ) ;
goto V_333;
}
V_19 = F_217 ( V_134 -> V_11 , L_130 ,
& V_336 ,
V_134 ) ;
if ( V_19 ) {
F_147 ( V_134 -> V_79 , L_128 , V_19 ) ;
goto V_333;
}
F_75 ( V_134 -> V_79 , L_131 ,
V_295 [ V_134 -> V_83 ] ) ;
return 0 ;
V_333:
F_208 ( V_134 ) ;
V_320:
V_134 -> V_51 = true ;
if ( V_134 -> V_11 ) {
T_3 V_11 = V_134 -> V_11 ;
V_134 -> V_11 = NULL ;
F_218 ( V_11 ) ;
}
if ( V_134 -> V_146 ) {
V_134 -> V_146 ( V_134 ) ;
V_134 -> V_146 = NULL ;
}
F_219 () ;
if ( V_134 -> V_28 ) {
if ( V_134 -> V_26 )
V_134 -> V_26 -> V_337 ( V_134 -> V_28 ) ;
F_124 ( V_134 -> V_28 ) ;
V_134 -> V_28 = NULL ;
}
if ( V_134 -> V_261 ) {
V_134 -> V_261 ( V_134 ) ;
V_134 -> V_261 = NULL ;
}
if ( V_134 -> V_158 ) {
V_134 -> V_158 ( V_134 ) ;
V_134 -> V_158 = NULL ;
}
if ( V_134 -> V_332 ) {
F_220 ( V_134 -> V_248 ) ;
V_134 -> V_332 = false ;
}
return V_19 ;
}
static int F_221 ( void )
{
int V_169 ;
char * V_175 ;
int V_19 ;
struct V_9 * V_194 ;
enum V_338 type = V_339 ;
if ( V_340 )
return 0 ;
V_340 = 1 ;
if ( V_341 ) {
V_19 = F_222 ( & V_331 ) ;
if ( V_19 ) {
F_115 (KERN_ERR PFX L_132
L_133 , rv) ;
return V_19 ;
}
}
V_175 = V_342 ;
if ( * V_175 != '\0' ) {
for ( V_169 = 0 ; ( V_169 < V_198 ) && ( * V_175 != '\0' ) ; V_169 ++ ) {
V_83 [ V_169 ] = V_175 ;
V_175 = strchr ( V_175 , ',' ) ;
if ( V_175 ) {
* V_175 = '\0' ;
V_175 ++ ;
} else {
break;
}
}
}
F_115 ( V_343 L_134 ) ;
if ( ! F_130 () )
return 0 ;
#ifdef F_223
if ( V_344 ) {
V_19 = F_224 ( & V_345 ) ;
if ( V_19 )
F_115 (KERN_ERR PFX L_132
L_135 , rv) ;
else
V_346 = true ;
}
#endif
#ifdef F_225
if ( V_347 )
F_142 () ;
#endif
#ifdef F_226
if ( V_279 )
F_138 () ;
#endif
#ifdef F_227
F_228 ( & V_348 ) ;
V_349 = true ;
#endif
F_127 ( & V_196 ) ;
F_212 (e, &smi_infos, link) {
if ( V_194 -> V_50 && ( ! type || V_194 -> V_141 == type ) ) {
if ( ! F_125 ( V_194 ) ) {
type = V_194 -> V_141 ;
}
}
}
if ( type ) {
F_129 ( & V_196 ) ;
return 0 ;
}
F_212 (e, &smi_infos, link) {
if ( ! V_194 -> V_50 && ( ! type || V_194 -> V_141 == type ) ) {
if ( ! F_125 ( V_194 ) ) {
type = V_194 -> V_141 ;
}
}
}
F_129 ( & V_196 ) ;
if ( type )
return 0 ;
F_127 ( & V_196 ) ;
if ( V_350 && F_229 ( & V_322 ) ) {
F_129 ( & V_196 ) ;
F_230 () ;
F_115 (KERN_WARNING PFX
L_136 ) ;
return - V_157 ;
} else {
F_129 ( & V_196 ) ;
return 0 ;
}
}
static void F_126 ( struct V_9 * V_351 )
{
int V_19 = 0 ;
if ( ! V_351 )
return;
if ( V_351 -> V_11 ) {
T_3 V_11 = V_351 -> V_11 ;
V_351 -> V_11 = NULL ;
V_19 = F_218 ( V_11 ) ;
if ( V_19 ) {
F_231 ( V_272 L_137 ,
V_19 ) ;
}
}
if ( V_351 -> V_79 )
F_163 ( V_351 -> V_79 , NULL ) ;
F_232 ( & V_351 -> V_321 ) ;
if ( V_351 -> V_146 )
V_351 -> V_146 ( V_351 ) ;
F_208 ( V_351 ) ;
while ( V_351 -> V_13 || ( V_351 -> V_41 != V_52 ) ) {
F_56 ( V_351 ) ;
F_178 ( 1 ) ;
}
F_20 ( V_351 , false ) ;
while ( V_351 -> V_13 || ( V_351 -> V_41 != V_52 ) ) {
F_56 ( V_351 ) ;
F_178 ( 1 ) ;
}
if ( V_351 -> V_26 )
V_351 -> V_26 -> V_337 ( V_351 -> V_28 ) ;
F_124 ( V_351 -> V_28 ) ;
if ( V_351 -> V_261 )
V_351 -> V_261 ( V_351 ) ;
if ( V_351 -> V_158 )
V_351 -> V_158 ( V_351 ) ;
if ( V_351 -> V_332 )
F_220 ( V_351 -> V_248 ) ;
F_124 ( V_351 ) ;
}
static void F_230 ( void )
{
struct V_9 * V_194 , * V_195 ;
if ( ! V_340 )
return;
#ifdef F_223
if ( V_346 )
F_233 ( & V_345 ) ;
#endif
#ifdef F_227
if ( V_349 )
F_234 ( & V_348 ) ;
#endif
F_235 ( & V_331 ) ;
F_127 ( & V_196 ) ;
F_128 (e, tmp_e, &smi_infos, link)
F_126 ( V_194 ) ;
F_129 ( & V_196 ) ;
}
