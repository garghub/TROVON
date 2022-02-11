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
F_19 ( V_9 ) ;
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
F_19 ( V_9 ) ;
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
F_115 ( V_170 L_19 , V_166 ) ;
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
F_115 ( V_170 L_20 , V_166 , * V_167 ) ;
return - V_159 ;
}
static int F_116 ( const char * V_167 , const char * V_171 ,
const char * V_166 , int * V_165 )
{
char * V_172 ;
if ( strcmp ( V_167 , V_166 ) == 0 ) {
if ( ! V_171 ) {
F_115 ( V_170 L_21 , V_167 ) ;
return - V_159 ;
}
* V_165 = F_117 ( V_171 , & V_172 , 0 ) ;
if ( ( * V_172 != '\0' ) || ( * V_171 == '\0' ) ) {
F_115 ( V_170 L_22 , V_167 ) ;
return - V_159 ;
}
return 1 ;
}
return 0 ;
}
static struct V_9 * F_118 ( void )
{
struct V_9 * V_143 = F_119 ( sizeof( * V_143 ) , V_173 ) ;
if ( V_143 )
F_120 ( & V_143 -> V_105 ) ;
return V_143 ;
}
static int F_121 ( const char * V_165 , struct V_174 * V_175 )
{
char * V_176 = F_122 ( V_165 , V_173 ) ;
int V_19 ;
char * V_177 , * V_167 , * V_168 , * V_172 , * V_178 ;
enum V_179 V_180 ;
enum V_83 V_83 ;
int V_181 ;
unsigned long V_149 ;
int V_151 ;
int V_156 ;
int V_153 ;
int V_50 ;
int V_182 ;
int V_183 ;
int V_78 ;
struct V_9 * V_143 ;
if ( ! V_176 )
return - V_184 ;
V_78 = strlen ( V_176 ) ;
V_183 = V_78 - 1 ;
while ( ( V_183 >= 0 ) && isspace ( V_176 [ V_183 ] ) ) {
V_176 [ V_183 ] = '\0' ;
V_183 -- ;
}
for ( V_167 = V_176 ; V_167 ; V_167 = V_177 ) {
V_151 = 1 ;
V_156 = 1 ;
V_153 = 0 ;
V_50 = 0 ;
V_182 = 0 ;
V_177 = strchr ( V_167 , ':' ) ;
if ( V_177 ) {
* V_177 = '\0' ;
V_177 ++ ;
}
V_19 = F_114 ( V_185 , & V_183 , L_23 , & V_167 ) ;
if ( V_19 )
break;
V_180 = V_183 ;
V_19 = F_114 ( V_186 , & V_183 , L_24 , & V_167 ) ;
if ( V_19 )
break;
V_83 = V_183 ;
V_19 = F_114 ( V_187 , & V_181 , L_25 , & V_167 ) ;
if ( V_19 )
break;
V_168 = strchr ( V_167 , ',' ) ;
if ( V_168 ) {
* V_168 = '\0' ;
V_168 ++ ;
}
V_149 = F_117 ( V_167 , & V_172 , 0 ) ;
if ( ( * V_172 != '\0' ) || ( * V_167 == '\0' ) ) {
F_115 ( V_170 L_26 , V_167 ) ;
break;
}
while ( V_168 ) {
V_167 = V_168 ;
V_168 = strchr ( V_167 , ',' ) ;
if ( V_168 ) {
* V_168 = '\0' ;
V_168 ++ ;
}
V_178 = strchr ( V_167 , '=' ) ;
if ( V_178 ) {
* V_178 = '\0' ;
V_178 ++ ;
}
V_19 = F_116 ( V_167 , V_178 , L_27 , & V_151 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = F_116 ( V_167 , V_178 , L_28 , & V_156 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = F_116 ( V_167 , V_178 , L_29 , & V_153 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = F_116 ( V_167 , V_178 , L_30 , & V_50 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = F_116 ( V_167 , V_178 , L_31 , & V_182 ) ;
if ( V_19 < 0 )
goto V_25;
else if ( V_19 )
continue;
V_19 = - V_159 ;
F_115 ( V_170 L_32 , V_167 ) ;
goto V_25;
}
if ( V_180 == V_188 ) {
V_143 = F_118 () ;
if ( ! V_143 ) {
V_19 = - V_184 ;
goto V_25;
}
V_143 -> V_141 = V_189 ;
V_143 -> V_83 = V_83 ;
V_143 -> V_70 . V_150 = V_149 ;
V_143 -> V_70 . V_190 = V_181 ;
if ( V_181 == V_191 )
V_143 -> V_192 = F_111 ;
else
V_143 -> V_192 = F_90 ;
V_143 -> V_70 . V_149 = NULL ;
V_143 -> V_70 . V_151 = V_151 ;
if ( ! V_143 -> V_70 . V_151 )
V_143 -> V_70 . V_151 = V_193 ;
V_143 -> V_70 . V_156 = V_156 ;
if ( ! V_143 -> V_70 . V_156 )
V_143 -> V_70 . V_156 = V_194 ;
V_143 -> V_70 . V_153 = V_153 ;
V_143 -> V_50 = V_50 ;
if ( V_143 -> V_50 )
V_143 -> V_135 = F_73 ;
V_143 -> V_195 = V_182 ;
V_19 = F_123 ( V_143 ) ;
if ( V_19 ) {
F_124 ( V_143 ) ;
goto V_25;
}
F_125 ( & V_196 ) ;
V_19 = F_126 ( V_143 ) ;
F_127 ( & V_196 ) ;
if ( V_19 ) {
F_128 ( V_143 ) ;
goto V_25;
}
} else {
struct V_9 * V_197 , * V_198 ;
F_125 ( & V_196 ) ;
F_129 (e, tmp_e, &smi_infos, link) {
if ( V_197 -> V_70 . V_190 != V_181 )
continue;
if ( V_197 -> V_83 != V_83 )
continue;
if ( V_197 -> V_70 . V_150 == V_149 )
F_128 ( V_197 ) ;
}
F_127 ( & V_196 ) ;
}
}
V_19 = V_78 ;
V_25:
F_124 ( V_176 ) ;
return V_19 ;
}
static int F_130 ( void )
{
int V_199 = - V_157 ;
int V_169 ;
struct V_9 * V_143 ;
for ( V_169 = 0 ; V_169 < V_200 ; V_169 ++ ) {
if ( ! V_201 [ V_169 ] && ! V_202 [ V_169 ] )
continue;
V_143 = F_118 () ;
if ( ! V_143 )
return - V_184 ;
V_143 -> V_141 = V_203 ;
F_131 ( V_170 L_33 ) ;
if ( ! V_83 [ V_169 ] || strcmp ( V_83 [ V_169 ] , L_34 ) == 0 ) {
V_143 -> V_83 = V_204 ;
} else if ( strcmp ( V_83 [ V_169 ] , L_35 ) == 0 ) {
V_143 -> V_83 = V_205 ;
} else if ( strcmp ( V_83 [ V_169 ] , L_36 ) == 0 ) {
V_143 -> V_83 = V_84 ;
} else {
F_115 ( V_170 L_37 ,
V_169 , V_83 [ V_169 ] ) ;
F_124 ( V_143 ) ;
continue;
}
if ( V_201 [ V_169 ] ) {
V_143 -> V_192 = F_90 ;
V_143 -> V_70 . V_150 = V_201 [ V_169 ] ;
V_143 -> V_70 . V_190 = V_206 ;
} else if ( V_202 [ V_169 ] ) {
V_143 -> V_192 = F_111 ;
V_143 -> V_70 . V_150 = V_202 [ V_169 ] ;
V_143 -> V_70 . V_190 = V_191 ;
} else {
F_115 ( V_170 L_38 ,
V_169 ) ;
F_124 ( V_143 ) ;
continue;
}
V_143 -> V_70 . V_149 = NULL ;
V_143 -> V_70 . V_151 = V_207 [ V_169 ] ;
if ( ! V_143 -> V_70 . V_151 )
V_143 -> V_70 . V_151 = V_193 ;
V_143 -> V_70 . V_156 = V_208 [ V_169 ] ;
if ( ! V_143 -> V_70 . V_156 )
V_143 -> V_70 . V_156 = V_194 ;
V_143 -> V_70 . V_153 = V_209 [ V_169 ] ;
V_143 -> V_50 = V_210 [ V_169 ] ;
if ( V_143 -> V_50 )
V_143 -> V_135 = F_73 ;
V_143 -> V_195 = V_211 [ V_169 ] ;
if ( ! F_123 ( V_143 ) ) {
F_125 ( & V_196 ) ;
if ( F_126 ( V_143 ) )
F_128 ( V_143 ) ;
F_127 ( & V_196 ) ;
V_199 = 0 ;
} else {
F_124 ( V_143 ) ;
}
}
return V_199 ;
}
static T_4 F_132 ( T_5 V_212 ,
T_4 V_213 , void * V_214 )
{
struct V_9 * V_9 = V_214 ;
unsigned long V_103 ;
F_40 ( & ( V_9 -> V_105 ) , V_103 ) ;
F_25 ( V_9 , V_131 ) ;
F_1 ( L_39 ) ;
F_31 ( V_9 , 0 ) ;
F_42 ( & ( V_9 -> V_105 ) , V_103 ) ;
return V_215 ;
}
static void F_133 ( struct V_9 * V_143 )
{
if ( ! V_143 -> V_50 )
return;
F_134 ( NULL , V_143 -> V_50 , & F_132 ) ;
}
static int F_135 ( struct V_9 * V_143 )
{
T_6 V_216 ;
if ( ! V_143 -> V_50 )
return 0 ;
V_216 = F_136 ( NULL ,
V_143 -> V_50 ,
V_217 ,
& F_132 ,
V_143 ) ;
if ( V_216 != V_218 ) {
F_30 ( V_143 -> V_79 , L_40
L_16 , V_145 , V_143 -> V_50 ) ;
V_143 -> V_50 = 0 ;
return - V_159 ;
} else {
V_143 -> V_146 = F_133 ;
F_75 ( V_143 -> V_79 , L_41 , V_143 -> V_50 ) ;
return 0 ;
}
}
static int F_137 ( struct V_219 * V_220 )
{
struct V_9 * V_143 ;
int V_19 ;
if ( V_220 -> V_221 != 1 ) {
F_131 ( V_170 L_42 , V_220 -> V_221 ) ;
return - V_157 ;
}
V_143 = F_118 () ;
if ( ! V_143 ) {
F_138 ( V_170 L_43 ) ;
return - V_184 ;
}
V_143 -> V_141 = V_222 ;
F_131 ( V_170 L_44 ) ;
switch ( V_220 -> V_223 ) {
case 1 :
V_143 -> V_83 = V_204 ;
break;
case 2 :
V_143 -> V_83 = V_205 ;
break;
case 3 :
V_143 -> V_83 = V_84 ;
break;
case 4 :
F_124 ( V_143 ) ;
return - V_160 ;
default:
F_131 ( V_170 L_45 ,
V_220 -> V_223 ) ;
F_124 ( V_143 ) ;
return - V_160 ;
}
if ( V_220 -> V_224 & 1 ) {
V_143 -> V_50 = V_220 -> V_225 ;
V_143 -> V_135 = F_135 ;
} else if ( V_220 -> V_224 & 2 ) {
V_143 -> V_50 = V_220 -> V_226 ;
V_143 -> V_135 = F_73 ;
} else {
V_143 -> V_50 = 0 ;
V_143 -> V_135 = NULL ;
}
if ( V_220 -> V_149 . V_227 ) {
V_143 -> V_70 . V_151 = V_220 -> V_149 . V_227 / 8 ;
} else {
V_143 -> V_70 . V_151 = V_193 ;
}
V_143 -> V_70 . V_156 = V_143 -> V_70 . V_151 ;
V_143 -> V_70 . V_153 = V_220 -> V_149 . V_228 ;
if ( V_220 -> V_149 . V_229 == V_230 ) {
V_143 -> V_192 = F_111 ;
V_143 -> V_70 . V_190 = V_191 ;
} else if ( V_220 -> V_149 . V_229 == V_231 ) {
V_143 -> V_192 = F_90 ;
V_143 -> V_70 . V_190 = V_206 ;
} else {
F_124 ( V_143 ) ;
F_115 ( V_170 L_46 ) ;
return - V_160 ;
}
V_143 -> V_70 . V_150 = V_220 -> V_149 . V_232 ;
F_131 ( L_47 ,
( V_143 -> V_70 . V_190 == V_206 ) ? L_48 : L_49 ,
V_143 -> V_70 . V_150 , V_143 -> V_70 . V_156 , V_143 -> V_70 . V_151 ,
V_143 -> V_50 ) ;
V_19 = F_123 ( V_143 ) ;
if ( V_19 )
F_124 ( V_143 ) ;
return V_19 ;
}
static void F_139 ( void )
{
T_6 V_216 ;
struct V_219 * V_220 ;
int V_169 ;
if ( V_233 )
return;
if ( V_234 )
return;
for ( V_169 = 0 ; ; V_169 ++ ) {
V_216 = F_140 ( V_235 , V_169 + 1 ,
(struct V_236 * * ) & V_220 ) ;
if ( V_216 != V_218 )
return;
F_137 ( V_220 ) ;
}
}
struct V_237 * F_141 ( struct V_238 * V_239 ,
struct V_9 * V_143 )
{
struct V_237 * V_240 , * V_241 ;
V_240 = F_142 ( V_239 , V_242 , 0 ) ;
if ( V_240 ) {
V_143 -> V_192 = F_90 ;
V_143 -> V_70 . V_190 = V_206 ;
} else {
V_240 = F_142 ( V_239 , V_243 , 0 ) ;
if ( V_240 ) {
V_143 -> V_192 = F_111 ;
V_143 -> V_70 . V_190 = V_191 ;
}
}
if ( ! V_240 ) {
F_143 ( & V_239 -> V_79 , L_50 ) ;
return NULL ;
}
V_143 -> V_70 . V_150 = V_240 -> V_244 ;
V_143 -> V_70 . V_151 = V_193 ;
V_241 = F_142 ( V_239 ,
( V_143 -> V_70 . V_190 == V_206 ) ?
V_242 : V_243 ,
1 ) ;
if ( V_241 ) {
if ( V_241 -> V_244 > V_143 -> V_70 . V_150 )
V_143 -> V_70 . V_151 =
V_241 -> V_244 - V_143 -> V_70 . V_150 ;
}
V_143 -> V_70 . V_156 = V_194 ;
V_143 -> V_70 . V_153 = 0 ;
return V_240 ;
}
static int F_144 ( struct V_238 * V_239 )
{
struct V_9 * V_143 ;
T_1 type , V_195 ;
int V_19 ;
if ( ! V_245 )
return - V_157 ;
V_19 = F_145 ( & V_239 -> V_79 , L_51 , & type ) ;
if ( V_19 )
return - V_157 ;
V_143 = F_118 () ;
if ( ! V_143 ) {
F_138 ( V_170 L_52 ) ;
return - V_184 ;
}
V_143 -> V_141 = V_246 ;
F_131 ( V_170 L_53 ) ;
switch ( type ) {
case V_247 :
V_143 -> V_83 = V_204 ;
break;
case V_248 :
V_143 -> V_83 = V_205 ;
break;
case V_249 :
V_143 -> V_83 = V_84 ;
break;
default:
F_124 ( V_143 ) ;
return - V_159 ;
}
if ( ! F_141 ( V_239 , V_143 ) ) {
V_19 = - V_159 ;
goto V_250;
}
V_19 = F_145 ( & V_239 -> V_79 , L_54 , & V_195 ) ;
if ( V_19 ) {
F_30 ( & V_239 -> V_79 , L_55 ) ;
V_143 -> V_195 = 0x20 ;
} else {
V_143 -> V_195 = V_195 ;
}
V_143 -> V_50 = F_146 ( V_239 , 0 ) ;
if ( V_143 -> V_50 > 0 )
V_143 -> V_135 = F_73 ;
else
V_143 -> V_50 = 0 ;
V_143 -> V_79 = & V_239 -> V_79 ;
F_131 ( L_56 ,
( V_143 -> V_70 . V_190 == V_206 ) ? L_48 : L_49 ,
V_143 -> V_70 . V_150 , V_143 -> V_70 . V_156 , V_143 -> V_70 . V_151 ,
V_143 -> V_50 ) ;
if ( F_123 ( V_143 ) )
F_124 ( V_143 ) ;
return 0 ;
V_250:
F_124 ( V_143 ) ;
return V_19 ;
}
static int F_144 ( struct V_238 * V_239 )
{
return - V_157 ;
}
static void F_147 ( struct V_9 * V_143 )
{
struct V_251 * V_239 = V_143 -> V_252 ;
F_148 ( V_239 ) ;
}
static int F_149 ( struct V_9 * V_143 )
{
if ( V_143 -> V_83 == V_204 ) {
unsigned char V_216 ;
int V_151 ;
V_143 -> V_70 . V_156 = V_194 ;
V_143 -> V_70 . V_153 = 0 ;
V_143 -> V_155 = 2 ;
V_143 -> V_26 = & V_253 ;
for ( V_151 = V_193 ; V_151 <= 16 ; ) {
V_143 -> V_70 . V_151 = V_151 ;
if ( V_143 -> V_192 ( V_143 ) ) {
F_143 ( V_143 -> V_79 ,
L_57 ) ;
return V_193 ;
}
V_143 -> V_70 . V_74 ( & V_143 -> V_70 , 1 , 0x10 ) ;
V_216 = V_143 -> V_70 . V_71 ( & V_143 -> V_70 , 1 ) ;
V_143 -> V_158 ( V_143 ) ;
if ( V_216 )
return V_151 ;
V_151 *= 4 ;
}
}
return V_193 ;
}
static int F_150 ( struct V_251 * V_239 ,
const struct V_254 * V_255 )
{
int V_19 ;
int V_256 = V_239 -> V_257 & V_258 ;
struct V_9 * V_143 ;
V_143 = F_118 () ;
if ( ! V_143 )
return - V_184 ;
V_143 -> V_141 = V_259 ;
F_75 ( & V_239 -> V_79 , L_58 ) ;
switch ( V_256 ) {
case V_260 :
V_143 -> V_83 = V_205 ;
break;
case V_261 :
V_143 -> V_83 = V_204 ;
break;
case V_262 :
V_143 -> V_83 = V_84 ;
break;
default:
F_124 ( V_143 ) ;
F_75 ( & V_239 -> V_79 , L_59 , V_256 ) ;
return - V_184 ;
}
V_19 = F_151 ( V_239 ) ;
if ( V_19 ) {
F_143 ( & V_239 -> V_79 , L_60 ) ;
F_124 ( V_143 ) ;
return V_19 ;
}
V_143 -> V_263 = F_147 ;
V_143 -> V_252 = V_239 ;
if ( F_152 ( V_239 , 0 ) & V_242 ) {
V_143 -> V_192 = F_90 ;
V_143 -> V_70 . V_190 = V_206 ;
} else {
V_143 -> V_192 = F_111 ;
V_143 -> V_70 . V_190 = V_191 ;
}
V_143 -> V_70 . V_150 = F_153 ( V_239 , 0 ) ;
V_143 -> V_70 . V_151 = F_149 ( V_143 ) ;
V_143 -> V_70 . V_156 = V_194 ;
V_143 -> V_70 . V_153 = 0 ;
V_143 -> V_50 = V_239 -> V_50 ;
if ( V_143 -> V_50 )
V_143 -> V_135 = F_73 ;
V_143 -> V_79 = & V_239 -> V_79 ;
F_154 ( V_239 , V_143 ) ;
F_75 ( & V_239 -> V_79 , L_61 ,
& V_239 -> V_237 [ 0 ] , V_143 -> V_70 . V_156 , V_143 -> V_70 . V_151 ,
V_143 -> V_50 ) ;
V_19 = F_123 ( V_143 ) ;
if ( V_19 ) {
F_124 ( V_143 ) ;
F_148 ( V_239 ) ;
}
return V_19 ;
}
static void F_155 ( struct V_251 * V_239 )
{
struct V_9 * V_143 = F_156 ( V_239 ) ;
F_128 ( V_143 ) ;
}
static int F_157 ( struct V_238 * V_79 )
{
const struct V_264 * V_265 ;
struct V_9 * V_143 ;
struct V_237 V_237 ;
const T_7 * V_156 , * V_151 , * V_153 ;
struct V_266 * V_267 = V_79 -> V_79 . V_268 ;
int V_199 ;
int V_269 ;
F_75 ( & V_79 -> V_79 , L_62 ) ;
V_265 = F_158 ( V_270 , & V_79 -> V_79 ) ;
if ( ! V_265 )
return - V_157 ;
if ( ! F_159 ( V_267 ) )
return - V_159 ;
V_199 = F_160 ( V_267 , 0 , & V_237 ) ;
if ( V_199 ) {
F_30 ( & V_79 -> V_79 , V_170 L_63 ) ;
return V_199 ;
}
V_156 = F_161 ( V_267 , L_64 , & V_269 ) ;
if ( V_156 && V_269 != 4 ) {
F_30 ( & V_79 -> V_79 , V_170 L_65 ) ;
return - V_159 ;
}
V_151 = F_161 ( V_267 , L_66 , & V_269 ) ;
if ( V_151 && V_269 != 4 ) {
F_30 ( & V_79 -> V_79 , V_170 L_67 ) ;
return - V_159 ;
}
V_153 = F_161 ( V_267 , L_68 , & V_269 ) ;
if ( V_153 && V_269 != 4 ) {
F_30 ( & V_79 -> V_79 , V_170 L_69 ) ;
return - V_159 ;
}
V_143 = F_118 () ;
if ( ! V_143 ) {
F_143 ( & V_79 -> V_79 ,
L_70 ) ;
return - V_184 ;
}
V_143 -> V_83 = (enum V_83 ) V_265 -> V_16 ;
V_143 -> V_141 = V_271 ;
V_143 -> V_135 = F_73 ;
if ( V_237 . V_103 & V_242 ) {
V_143 -> V_192 = F_90 ;
V_143 -> V_70 . V_190 = V_206 ;
} else {
V_143 -> V_192 = F_111 ;
V_143 -> V_70 . V_190 = V_191 ;
}
V_143 -> V_70 . V_150 = V_237 . V_244 ;
V_143 -> V_70 . V_156 = V_156 ? F_162 ( V_156 ) : V_194 ;
V_143 -> V_70 . V_151 = V_151 ? F_162 ( V_151 ) : V_193 ;
V_143 -> V_70 . V_153 = V_153 ? F_162 ( V_153 ) : 0 ;
V_143 -> V_50 = F_163 ( V_79 -> V_79 . V_268 , 0 ) ;
V_143 -> V_79 = & V_79 -> V_79 ;
F_164 ( & V_79 -> V_79 , L_71 ,
V_143 -> V_70 . V_150 , V_143 -> V_70 . V_156 , V_143 -> V_70 . V_151 ,
V_143 -> V_50 ) ;
F_165 ( & V_79 -> V_79 , V_143 ) ;
V_199 = F_123 ( V_143 ) ;
if ( V_199 ) {
F_124 ( V_143 ) ;
return V_199 ;
}
return 0 ;
}
static int F_157 ( struct V_238 * V_79 )
{
return - V_157 ;
}
static int F_166 ( struct V_9 * V_143 , int V_195 )
{
#ifdef F_167
if ( ! V_195 ) {
int type = - 1 ;
T_4 V_103 = V_242 ;
switch ( V_143 -> V_83 ) {
case V_204 :
type = V_247 ;
break;
case V_84 :
type = V_249 ;
break;
case V_205 :
type = V_248 ;
break;
}
if ( V_143 -> V_70 . V_190 == V_191 )
V_103 = V_243 ;
V_195 = F_168 ( type , V_103 ,
V_143 -> V_70 . V_150 ) ;
}
#endif
return V_195 ;
}
static int F_169 ( struct V_238 * V_79 )
{
struct V_9 * V_143 ;
T_5 V_272 ;
T_6 V_216 ;
unsigned long long V_273 ;
struct V_237 * V_240 ;
int V_19 = - V_159 ;
if ( ! V_274 )
return - V_157 ;
V_272 = F_170 ( & V_79 -> V_79 ) ;
if ( ! V_272 )
return - V_157 ;
V_143 = F_118 () ;
if ( ! V_143 )
return - V_184 ;
V_143 -> V_141 = V_275 ;
F_75 ( & V_79 -> V_79 , V_170 L_72 ) ;
V_143 -> V_142 . V_276 . T_5 = V_272 ;
V_216 = F_171 ( V_272 , L_73 , NULL , & V_273 ) ;
if ( F_172 ( V_216 ) ) {
F_143 ( & V_79 -> V_79 , L_74 ) ;
goto V_250;
}
switch ( V_273 ) {
case 1 :
V_143 -> V_83 = V_204 ;
break;
case 2 :
V_143 -> V_83 = V_205 ;
break;
case 3 :
V_143 -> V_83 = V_84 ;
break;
case 4 :
V_19 = - V_157 ;
goto V_250;
default:
F_75 ( & V_79 -> V_79 , L_75 , V_273 ) ;
goto V_250;
}
V_240 = F_141 ( V_79 , V_143 ) ;
if ( ! V_240 ) {
V_19 = - V_159 ;
goto V_250;
}
V_216 = F_171 ( V_272 , L_76 , NULL , & V_273 ) ;
if ( F_173 ( V_216 ) ) {
V_143 -> V_50 = V_273 ;
V_143 -> V_135 = F_135 ;
} else {
int V_50 = F_146 ( V_79 , 0 ) ;
if ( V_50 > 0 ) {
V_143 -> V_50 = V_50 ;
V_143 -> V_135 = F_73 ;
}
}
V_143 -> V_195 = F_166 ( V_143 , V_143 -> V_195 ) ;
V_143 -> V_79 = & V_79 -> V_79 ;
F_174 ( V_79 , V_143 ) ;
F_75 ( V_143 -> V_79 , L_61 ,
V_240 , V_143 -> V_70 . V_156 , V_143 -> V_70 . V_151 ,
V_143 -> V_50 ) ;
V_19 = F_123 ( V_143 ) ;
if ( V_19 )
F_124 ( V_143 ) ;
return V_19 ;
V_250:
F_124 ( V_143 ) ;
return V_19 ;
}
static int F_169 ( struct V_238 * V_79 )
{
return - V_157 ;
}
static int F_175 ( struct V_238 * V_79 )
{
if ( F_157 ( V_79 ) == 0 )
return 0 ;
if ( F_169 ( V_79 ) == 0 )
return 0 ;
return F_144 ( V_79 ) ;
}
static int F_176 ( struct V_238 * V_79 )
{
struct V_9 * V_143 = F_177 ( & V_79 -> V_79 ) ;
F_128 ( V_143 ) ;
return 0 ;
}
static int F_178 ( struct V_277 * V_79 )
{
struct V_9 * V_143 ;
int V_19 ;
V_143 = F_118 () ;
if ( ! V_143 ) {
F_143 ( & V_79 -> V_79 ,
L_77 ) ;
return - V_184 ;
}
V_143 -> V_83 = V_204 ;
V_143 -> V_141 = V_271 ;
V_143 -> V_192 = F_111 ;
V_143 -> V_70 . V_190 = V_191 ;
V_143 -> V_70 . V_150 = V_79 -> V_278 . V_244 ;
V_143 -> V_70 . V_156 = 1 ;
V_143 -> V_70 . V_151 = 1 ;
V_143 -> V_70 . V_153 = 0 ;
V_143 -> V_50 = 0 ;
V_143 -> V_135 = NULL ;
V_143 -> V_79 = & V_79 -> V_79 ;
F_164 ( & V_79 -> V_79 , L_78 , V_143 -> V_70 . V_150 ) ;
F_165 ( & V_79 -> V_79 , V_143 ) ;
V_19 = F_123 ( V_143 ) ;
if ( V_19 ) {
F_124 ( V_143 ) ;
return V_19 ;
}
return 0 ;
}
static int F_179 ( struct V_277 * V_79 )
{
F_128 ( F_177 ( & V_79 -> V_79 ) ) ;
return 0 ;
}
static int F_180 ( struct V_9 * V_9 )
{
enum V_18 V_108 ;
V_108 = V_9 -> V_26 -> V_89 ( V_9 -> V_28 , 0 ) ;
for (; ; ) {
if ( V_108 == V_114 ||
V_108 == V_279 ) {
F_181 ( 1 ) ;
V_108 = V_9 -> V_26 -> V_89 (
V_9 -> V_28 , F_182 ( 1 ) ) ;
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
static int F_183 ( struct V_9 * V_9 )
{
unsigned char V_1 [ 2 ] ;
unsigned char * V_280 ;
unsigned long V_281 ;
int V_19 = 0 ;
V_280 = F_184 ( V_76 , V_173 ) ;
if ( ! V_280 )
return - V_184 ;
V_1 [ 0 ] = V_39 << 2 ;
V_1 [ 1 ] = V_282 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 2 ) ;
V_19 = F_180 ( V_9 ) ;
if ( V_19 )
goto V_25;
V_281 = V_9 -> V_26 -> V_75 ( V_9 -> V_28 ,
V_280 , V_76 ) ;
V_19 = F_185 ( V_280 , V_281 , & V_9 -> V_283 ) ;
V_25:
F_124 ( V_280 ) ;
return V_19 ;
}
static int F_186 ( struct V_9 * V_9 , T_1 * V_62 )
{
unsigned char V_1 [ 3 ] ;
unsigned char * V_280 ;
unsigned long V_281 ;
int V_19 ;
V_280 = F_184 ( V_76 , V_173 ) ;
if ( ! V_280 )
return - V_184 ;
V_1 [ 0 ] = V_39 << 2 ;
V_1 [ 1 ] = V_40 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 2 ) ;
V_19 = F_180 ( V_9 ) ;
if ( V_19 ) {
F_30 ( V_9 -> V_79 ,
L_79 ,
V_19 ) ;
goto V_25;
}
V_281 = V_9 -> V_26 -> V_75 ( V_9 -> V_28 ,
V_280 , V_76 ) ;
if ( V_281 < 4 ||
V_280 [ 0 ] != ( V_39 | 1 ) << 2 ||
V_280 [ 1 ] != V_40 ||
V_280 [ 2 ] != 0 ) {
F_30 ( V_9 -> V_79 ,
L_80 ,
V_281 , V_280 [ 0 ] , V_280 [ 1 ] , V_280 [ 2 ] ) ;
V_19 = - V_159 ;
goto V_25;
} else {
* V_62 = V_280 [ 3 ] ;
}
V_25:
F_124 ( V_280 ) ;
return V_19 ;
}
static int F_187 ( struct V_9 * V_9 , T_1 V_62 )
{
unsigned char V_1 [ 3 ] ;
unsigned char * V_280 ;
unsigned long V_281 ;
int V_19 ;
V_280 = F_184 ( V_76 , V_173 ) ;
if ( ! V_280 )
return - V_184 ;
V_1 [ 0 ] = V_39 << 2 ;
V_1 [ 1 ] = V_86 ;
V_1 [ 2 ] = V_62 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 3 ) ;
V_19 = F_180 ( V_9 ) ;
if ( V_19 ) {
F_30 ( V_9 -> V_79 ,
L_81 ,
V_19 ) ;
goto V_25;
}
V_281 = V_9 -> V_26 -> V_75 ( V_9 -> V_28 ,
V_280 , V_76 ) ;
if ( V_281 < 3 ||
V_280 [ 0 ] != ( V_39 | 1 ) << 2 ||
V_280 [ 1 ] != V_86 ) {
F_30 ( V_9 -> V_79 ,
L_82 ,
V_281 , V_280 [ 0 ] , V_280 [ 1 ] ) ;
V_19 = - V_159 ;
goto V_25;
}
if ( V_280 [ 2 ] != 0 )
V_19 = 1 ;
V_25:
F_124 ( V_280 ) ;
return V_19 ;
}
static void F_188 ( struct V_9 * V_9 )
{
T_1 V_62 = 0 ;
int V_19 ;
V_19 = F_186 ( V_9 , & V_62 ) ;
if ( ! V_19 ) {
if ( ( V_62 & V_67 ) == 0 )
return;
V_62 &= ~ V_67 ;
V_19 = F_187 ( V_9 , V_62 ) ;
}
if ( V_19 < 0 ) {
F_143 ( V_9 -> V_79 ,
L_83 , V_19 ) ;
return;
}
if ( V_19 ) {
F_30 ( V_9 -> V_79 ,
L_84 ) ;
V_9 -> V_65 = true ;
}
}
static void F_189 ( struct V_9 * V_9 )
{
T_1 V_62 = 0 ;
int V_19 ;
if ( ! V_9 -> V_50 )
return;
V_19 = F_186 ( V_9 , & V_62 ) ;
if ( ! V_19 ) {
V_62 |= V_67 ;
V_19 = F_187 ( V_9 , V_62 ) ;
}
if ( V_19 < 0 ) {
F_143 ( V_9 -> V_79 ,
L_85 , V_19 ) ;
return;
}
if ( V_19 ) {
F_30 ( V_9 -> V_79 ,
L_86 ) ;
V_9 -> V_65 = true ;
V_9 -> V_66 = true ;
}
}
static int F_190 ( struct V_9 * V_9 )
{
unsigned char V_1 [ 3 ] ;
unsigned char * V_280 ;
unsigned long V_281 ;
int V_19 = 0 ;
V_280 = F_184 ( V_76 , V_173 ) ;
if ( ! V_280 )
return - V_184 ;
V_1 [ 0 ] = V_39 << 2 ;
V_1 [ 1 ] = V_40 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 2 ) ;
V_19 = F_180 ( V_9 ) ;
if ( V_19 ) {
F_115 ( V_170 L_87 ) ;
goto V_25;
}
V_281 = V_9 -> V_26 -> V_75 ( V_9 -> V_28 ,
V_280 , V_76 ) ;
if ( V_281 < 4 ||
V_280 [ 0 ] != ( V_39 | 1 ) << 2 ||
V_280 [ 1 ] != V_40 ||
V_280 [ 2 ] != 0 ) {
F_115 ( V_170 L_88 ) ;
V_19 = - V_159 ;
goto V_25;
}
if ( V_280 [ 3 ] & V_64 ) {
V_9 -> V_63 = true ;
goto V_25;
}
V_1 [ 0 ] = V_39 << 2 ;
V_1 [ 1 ] = V_86 ;
V_1 [ 2 ] = V_280 [ 3 ] | V_64 ;
V_9 -> V_26 -> V_27 ( V_9 -> V_28 , V_1 , 3 ) ;
V_19 = F_180 ( V_9 ) ;
if ( V_19 ) {
F_115 ( V_170 L_89 ) ;
goto V_25;
}
V_281 = V_9 -> V_26 -> V_75 ( V_9 -> V_28 ,
V_280 , V_76 ) ;
if ( V_281 < 3 ||
V_280 [ 0 ] != ( V_39 | 1 ) << 2 ||
V_280 [ 1 ] != V_86 ) {
F_115 ( V_170 L_90 ) ;
V_19 = - V_159 ;
goto V_25;
}
if ( V_280 [ 2 ] != 0 )
V_19 = - V_284 ;
else
V_9 -> V_63 = true ;
V_25:
F_124 ( V_280 ) ;
return V_19 ;
}
static int F_191 ( struct V_285 * V_286 , void * V_164 )
{
struct V_9 * V_139 = V_286 -> V_287 ;
F_192 ( V_286 , L_91 , V_288 [ V_139 -> V_83 ] ) ;
return 0 ;
}
static int F_193 ( struct V_289 * V_289 , struct V_290 * V_290 )
{
return F_194 ( V_290 , F_191 , F_195 ( V_289 ) ) ;
}
static int F_196 ( struct V_285 * V_286 , void * V_164 )
{
struct V_9 * V_139 = V_286 -> V_287 ;
F_192 ( V_286 , L_92 ,
V_139 -> V_50 && ! V_139 -> V_51 ) ;
F_192 ( V_286 , L_93 ,
F_197 ( V_139 , V_130 ) ) ;
F_192 ( V_286 , L_94 ,
F_197 ( V_139 , V_128 ) ) ;
F_192 ( V_286 , L_95 ,
F_197 ( V_139 , V_98 ) ) ;
F_192 ( V_286 , L_96 ,
F_197 ( V_139 , V_131 ) ) ;
F_192 ( V_286 , L_97 ,
F_197 ( V_139 , V_96 ) ) ;
F_192 ( V_286 , L_98 ,
F_197 ( V_139 , V_291 ) ) ;
F_192 ( V_286 , L_99 ,
F_197 ( V_139 , V_93 ) ) ;
F_192 ( V_286 , L_100 ,
F_197 ( V_139 , V_91 ) ) ;
F_192 ( V_286 , L_101 ,
F_197 ( V_139 , V_81 ) ) ;
F_192 ( V_286 , L_102 ,
F_197 ( V_139 , V_55 ) ) ;
F_192 ( V_286 , L_103 ,
F_197 ( V_139 , V_82 ) ) ;
return 0 ;
}
static int F_198 ( struct V_289 * V_289 , struct V_290 * V_290 )
{
return F_194 ( V_290 , F_196 , F_195 ( V_289 ) ) ;
}
static int F_199 ( struct V_285 * V_286 , void * V_164 )
{
struct V_9 * V_139 = V_286 -> V_287 ;
F_192 ( V_286 ,
L_104 ,
V_288 [ V_139 -> V_83 ] ,
V_292 [ V_139 -> V_70 . V_190 ] ,
V_139 -> V_70 . V_150 ,
V_139 -> V_70 . V_151 ,
V_139 -> V_70 . V_156 ,
V_139 -> V_70 . V_153 ,
V_139 -> V_50 ,
V_139 -> V_195 ) ;
return 0 ;
}
static int F_200 ( struct V_289 * V_289 , struct V_290 * V_290 )
{
return F_194 ( V_290 , F_199 , F_195 ( V_289 ) ) ;
}
static int F_201 ( struct V_9 * V_9 )
{
V_9 -> V_54 = ( ( V_9 -> V_54 & ~ V_58 ) |
V_56 ) ;
return 1 ;
}
static void F_202 ( struct V_9 * V_9 )
{
struct V_293 * V_294 = & V_9 -> V_283 ;
if ( V_294 -> V_295 == V_296 ) {
if ( V_294 -> V_283 == V_297 &&
V_294 -> V_298 == V_299 &&
V_294 -> V_300 == V_301 ) {
V_9 -> V_59 =
F_201 ;
} else if ( F_203 ( V_294 ) < 1 ||
( F_203 ( V_294 ) == 1 &&
F_204 ( V_294 ) < 5 ) ) {
V_9 -> V_59 =
F_201 ;
}
}
}
static void F_205 ( struct V_9 * V_9 )
{
struct V_10 * V_1 = V_9 -> V_13 ;
V_1 -> V_15 [ 0 ] = V_1 -> V_16 [ 0 ] | 4 ;
V_1 -> V_15 [ 1 ] = V_1 -> V_16 [ 1 ] ;
V_1 -> V_15 [ 2 ] = V_302 ;
V_1 -> V_17 = 3 ;
V_9 -> V_13 = NULL ;
F_6 ( V_9 , V_1 ) ;
}
static int F_206 ( struct V_6 * V_303 ,
unsigned long V_304 ,
void * V_305 )
{
struct V_9 * V_9 = V_305 ;
unsigned char * V_16 = V_9 -> V_13 -> V_16 ;
unsigned int V_35 = V_9 -> V_13 -> V_29 ;
if ( V_35 >= 8 &&
( V_16 [ 0 ] >> 2 ) == V_306 &&
V_16 [ 1 ] == V_307 &&
V_16 [ 7 ] == 0x3A ) {
F_205 ( V_9 ) ;
return V_308 ;
}
return V_309 ;
}
static void
F_207 ( struct V_9 * V_9 )
{
struct V_293 * V_294 = & V_9 -> V_283 ;
if ( V_294 -> V_295 == V_296 &&
V_9 -> V_83 == V_84 )
F_4 ( & V_310 ) ;
}
static void F_208 ( struct V_9 * V_9 )
{
F_202 ( V_9 ) ;
}
static void F_209 ( struct V_9 * V_9 )
{
F_207 ( V_9 ) ;
}
static void F_210 ( struct V_9 * V_9 )
{
F_188 ( V_9 ) ;
F_189 ( V_9 ) ;
}
static inline void F_211 ( struct V_9 * V_9 )
{
if ( V_9 -> V_37 != NULL )
F_212 ( V_9 -> V_37 ) ;
if ( V_9 -> V_34 )
F_213 ( & V_9 -> V_33 ) ;
}
static int F_214 ( struct V_9 * V_143 )
{
struct V_9 * V_197 ;
F_215 (e, &smi_infos, link) {
if ( V_197 -> V_70 . V_190 != V_143 -> V_70 . V_190 )
continue;
if ( V_197 -> V_70 . V_150 == V_143 -> V_70 . V_150 ) {
if ( V_143 -> V_195 && ! V_197 -> V_195 )
V_197 -> V_195 = V_143 -> V_195 ;
return 0 ;
}
}
return 1 ;
}
static int F_123 ( struct V_9 * V_134 )
{
int V_19 = 0 ;
F_125 ( & V_196 ) ;
if ( ! F_214 ( V_134 ) ) {
F_131 ( V_170 L_105 ,
F_216 ( V_134 -> V_141 ) ,
V_288 [ V_134 -> V_83 ] ) ;
V_19 = - V_311 ;
goto V_312;
}
F_131 ( V_170 L_106 ,
F_216 ( V_134 -> V_141 ) ,
V_288 [ V_134 -> V_83 ] ) ;
V_134 -> V_11 = NULL ;
V_134 -> V_28 = NULL ;
V_134 -> V_26 = NULL ;
F_217 ( & V_134 -> V_313 , & V_314 ) ;
V_312:
F_127 ( & V_196 ) ;
return V_19 ;
}
static int F_126 ( struct V_9 * V_134 )
{
int V_19 = 0 ;
int V_169 ;
char * V_315 = NULL ;
F_131 ( V_170 L_107 ,
F_216 ( V_134 -> V_141 ) ,
V_288 [ V_134 -> V_83 ] ,
V_292 [ V_134 -> V_70 . V_190 ] ,
V_134 -> V_70 . V_150 ,
V_134 -> V_195 , V_134 -> V_50 ) ;
switch ( V_134 -> V_83 ) {
case V_204 :
V_134 -> V_26 = & V_253 ;
break;
case V_205 :
V_134 -> V_26 = & V_316 ;
break;
case V_84 :
V_134 -> V_26 = & V_317 ;
break;
default:
V_19 = - V_160 ;
goto V_312;
}
V_134 -> V_111 = V_318 ;
if ( ! V_134 -> V_79 ) {
V_315 = F_218 ( V_173 , L_108 ,
V_134 -> V_111 ) ;
V_134 -> V_239 = F_219 ( L_109 ,
V_134 -> V_111 ) ;
if ( ! V_134 -> V_239 ) {
F_138 ( V_170 L_110 ) ;
goto V_312;
}
V_134 -> V_79 = & V_134 -> V_239 -> V_79 ;
V_134 -> V_79 -> V_319 = & V_320 . V_319 ;
V_134 -> V_79 -> V_315 = V_315 ;
}
V_134 -> V_28 = F_184 ( V_134 -> V_26 -> V_35 () , V_173 ) ;
if ( ! V_134 -> V_28 ) {
F_138 ( V_170 L_111 ) ;
V_19 = - V_184 ;
goto V_312;
}
V_134 -> V_155 = V_134 -> V_26 -> V_321 ( V_134 -> V_28 ,
& V_134 -> V_70 ) ;
V_19 = V_134 -> V_192 ( V_134 ) ;
if ( V_19 ) {
F_143 ( V_134 -> V_79 , L_112 ) ;
goto V_312;
}
if ( V_134 -> V_26 -> V_322 ( V_134 -> V_28 ) ) {
if ( V_134 -> V_141 )
F_143 ( V_134 -> V_79 , L_113 ) ;
V_19 = - V_157 ;
goto V_312;
}
V_19 = F_183 ( V_134 ) ;
if ( V_19 ) {
if ( V_134 -> V_141 )
F_143 ( V_134 -> V_79 , L_114 ) ;
goto V_312;
}
F_208 ( V_134 ) ;
F_209 ( V_134 ) ;
F_210 ( V_134 ) ;
V_134 -> V_20 = NULL ;
V_134 -> V_13 = NULL ;
F_34 ( & V_134 -> V_99 , 0 ) ;
V_134 -> V_104 = false ;
for ( V_169 = 0 ; V_169 < V_323 ; V_169 ++ )
F_34 ( & V_134 -> V_324 [ V_169 ] , 0 ) ;
V_134 -> V_51 = true ;
F_34 ( & V_134 -> V_120 , 0 ) ;
V_19 = F_190 ( V_134 ) ;
if ( V_19 == 0 )
V_134 -> V_122 = true ;
F_17 ( V_134 , false ) ;
if ( V_134 -> V_50 ) {
V_134 -> V_51 = false ;
F_34 ( & V_134 -> V_99 , 1 ) ;
}
if ( V_134 -> V_239 ) {
V_19 = F_220 ( V_134 -> V_239 ) ;
if ( V_19 ) {
F_143 ( V_134 -> V_79 ,
L_115 ,
V_19 ) ;
goto V_312;
}
V_134 -> V_325 = true ;
}
V_19 = F_221 ( & V_26 ,
V_134 ,
& V_134 -> V_283 ,
V_134 -> V_79 ,
V_134 -> V_195 ) ;
if ( V_19 ) {
F_143 ( V_134 -> V_79 , L_116 ,
V_19 ) ;
goto V_326;
}
V_19 = F_222 ( V_134 -> V_11 , L_117 ,
& V_327 ,
V_134 ) ;
if ( V_19 ) {
F_143 ( V_134 -> V_79 , L_118 , V_19 ) ;
goto V_326;
}
V_19 = F_222 ( V_134 -> V_11 , L_119 ,
& V_328 ,
V_134 ) ;
if ( V_19 ) {
F_143 ( V_134 -> V_79 , L_118 , V_19 ) ;
goto V_326;
}
V_19 = F_222 ( V_134 -> V_11 , L_120 ,
& V_329 ,
V_134 ) ;
if ( V_19 ) {
F_143 ( V_134 -> V_79 , L_118 , V_19 ) ;
goto V_326;
}
V_318 ++ ;
F_75 ( V_134 -> V_79 , L_121 ,
V_288 [ V_134 -> V_83 ] ) ;
F_223 ( V_134 -> V_79 -> V_315 != NULL ) ;
F_124 ( V_315 ) ;
return 0 ;
V_326:
F_211 ( V_134 ) ;
V_312:
V_134 -> V_51 = true ;
if ( V_134 -> V_11 ) {
T_3 V_11 = V_134 -> V_11 ;
V_134 -> V_11 = NULL ;
F_224 ( V_11 ) ;
}
if ( V_134 -> V_146 ) {
V_134 -> V_146 ( V_134 ) ;
V_134 -> V_146 = NULL ;
}
F_225 () ;
if ( V_134 -> V_28 ) {
if ( V_134 -> V_26 )
V_134 -> V_26 -> V_330 ( V_134 -> V_28 ) ;
F_124 ( V_134 -> V_28 ) ;
V_134 -> V_28 = NULL ;
}
if ( V_134 -> V_263 ) {
V_134 -> V_263 ( V_134 ) ;
V_134 -> V_263 = NULL ;
}
if ( V_134 -> V_158 ) {
V_134 -> V_158 ( V_134 ) ;
V_134 -> V_158 = NULL ;
}
if ( V_134 -> V_325 ) {
F_226 ( V_134 -> V_239 ) ;
V_134 -> V_325 = false ;
V_134 -> V_239 = NULL ;
} else if ( V_134 -> V_239 ) {
F_227 ( V_134 -> V_239 ) ;
V_134 -> V_239 = NULL ;
}
F_124 ( V_315 ) ;
return V_19 ;
}
static int F_228 ( void )
{
int V_169 ;
char * V_176 ;
int V_19 ;
struct V_9 * V_197 ;
enum V_331 type = V_332 ;
if ( V_333 )
return 0 ;
V_333 = 1 ;
if ( V_334 ) {
V_19 = F_229 ( & V_320 ) ;
if ( V_19 ) {
F_138 ( V_170 L_122 , V_19 ) ;
return V_19 ;
}
}
V_176 = V_335 ;
if ( * V_176 != '\0' ) {
for ( V_169 = 0 ; ( V_169 < V_200 ) && ( * V_176 != '\0' ) ; V_169 ++ ) {
V_83 [ V_169 ] = V_176 ;
V_176 = strchr ( V_176 , ',' ) ;
if ( V_176 ) {
* V_176 = '\0' ;
V_176 ++ ;
} else {
break;
}
}
}
F_131 ( L_123 ) ;
if ( ! F_130 () )
return 0 ;
#ifdef F_230
if ( V_336 ) {
V_19 = F_231 ( & V_337 ) ;
if ( V_19 )
F_138 ( V_170 L_124 , V_19 ) ;
else
V_338 = true ;
}
#endif
#ifdef F_232
if ( V_274 )
F_139 () ;
#endif
#ifdef F_233
F_234 ( & V_339 ) ;
V_340 = true ;
#endif
F_125 ( & V_196 ) ;
F_215 (e, &smi_infos, link) {
if ( V_197 -> V_50 && ( ! type || V_197 -> V_141 == type ) ) {
if ( ! F_126 ( V_197 ) ) {
type = V_197 -> V_141 ;
}
}
}
if ( type ) {
F_127 ( & V_196 ) ;
return 0 ;
}
F_215 (e, &smi_infos, link) {
if ( ! V_197 -> V_50 && ( ! type || V_197 -> V_141 == type ) ) {
if ( ! F_126 ( V_197 ) ) {
type = V_197 -> V_141 ;
}
}
}
F_127 ( & V_196 ) ;
if ( type )
return 0 ;
F_125 ( & V_196 ) ;
if ( V_341 && F_235 ( & V_314 ) ) {
F_127 ( & V_196 ) ;
F_236 () ;
F_115 ( V_170 L_125 ) ;
return - V_157 ;
} else {
F_127 ( & V_196 ) ;
return 0 ;
}
}
static void F_128 ( struct V_9 * V_342 )
{
int V_19 = 0 ;
if ( ! V_342 )
return;
if ( V_342 -> V_11 ) {
T_3 V_11 = V_342 -> V_11 ;
V_342 -> V_11 = NULL ;
V_19 = F_224 ( V_11 ) ;
if ( V_19 ) {
F_138 ( V_170 L_126 ,
V_19 ) ;
}
}
if ( V_342 -> V_79 )
F_165 ( V_342 -> V_79 , NULL ) ;
F_237 ( & V_342 -> V_313 ) ;
if ( V_342 -> V_146 )
V_342 -> V_146 ( V_342 ) ;
F_211 ( V_342 ) ;
while ( V_342 -> V_13 || ( V_342 -> V_41 != V_52 ) ) {
F_56 ( V_342 ) ;
F_181 ( 1 ) ;
}
F_20 ( V_342 , false ) ;
while ( V_342 -> V_13 || ( V_342 -> V_41 != V_52 ) ) {
F_56 ( V_342 ) ;
F_181 ( 1 ) ;
}
if ( V_342 -> V_26 )
V_342 -> V_26 -> V_330 ( V_342 -> V_28 ) ;
F_124 ( V_342 -> V_28 ) ;
if ( V_342 -> V_263 )
V_342 -> V_263 ( V_342 ) ;
if ( V_342 -> V_158 )
V_342 -> V_158 ( V_342 ) ;
if ( V_342 -> V_325 )
F_226 ( V_342 -> V_239 ) ;
F_124 ( V_342 ) ;
}
static void F_236 ( void )
{
struct V_9 * V_197 , * V_198 ;
if ( ! V_333 )
return;
#ifdef F_230
if ( V_338 )
F_238 ( & V_337 ) ;
#endif
#ifdef F_233
if ( V_340 )
F_239 ( & V_339 ) ;
#endif
F_240 ( & V_320 ) ;
F_125 ( & V_196 ) ;
F_129 (e, tmp_e, &smi_infos, link)
F_128 ( V_197 ) ;
F_127 ( & V_196 ) ;
}
