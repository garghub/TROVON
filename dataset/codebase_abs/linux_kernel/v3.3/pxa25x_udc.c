static void F_1 ( void )
{
struct V_1 * V_2 = V_3 -> V_2 ;
int V_4 = V_2 -> V_5 ;
if ( F_2 ( V_2 -> V_6 ) )
F_3 ( V_2 -> V_6 , V_4 ) ;
else if ( V_2 -> V_7 )
V_2 -> V_7 ( V_8 ) ;
}
static void F_4 ( void )
{
struct V_1 * V_2 = V_3 -> V_2 ;
int V_9 = ! V_2 -> V_5 ;
if ( F_2 ( V_2 -> V_6 ) )
F_3 ( V_2 -> V_6 , V_9 ) ;
else if ( V_2 -> V_7 )
V_2 -> V_7 ( V_10 ) ;
}
static void F_5 ( int V_11 )
{
V_11 &= 0xf ;
if ( V_11 < 8 )
V_12 &= ~ ( 1 << V_11 ) ;
else {
V_11 -= 8 ;
V_13 &= ~ ( 1 << V_11 ) ;
}
}
static void F_6 ( int V_11 )
{
V_11 &= 0xf ;
if ( V_11 < 8 )
V_12 |= 1 << V_11 ;
else {
V_11 -= 8 ;
V_13 |= 1 << V_11 ;
}
}
static inline void F_7 ( int V_14 )
{
V_15 = ( V_15 & V_16 ) | ( V_14 & V_16 ) ;
}
static inline void F_8 ( int V_14 )
{
V_15 = ( V_15 & V_16 ) & ~ ( V_14 & V_16 ) ;
}
static inline void F_9 ( int V_14 )
{
T_1 V_17 = V_15 & V_16 ;
V_15 = V_17 | ( V_14 & ~ V_16 ) ;
}
static int F_10 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
V_23 = F_11 ( V_19 , struct V_22 , V_23 ) ;
if ( ! V_19 || ! V_21 || V_23 -> V_21 || V_19 -> V_26 == V_27
|| V_21 -> V_28 != V_29
|| V_23 -> V_11 != V_21 -> V_11
|| V_23 -> V_30 < F_12 ( V_21 ) ) {
F_13 ( L_1 , V_31 ) ;
return - V_32 ;
}
if ( V_23 -> V_33 != V_21 -> V_33
&& V_23 -> V_33 != V_34
&& V_21 -> V_33 != V_35 ) {
F_13 ( L_2 , V_31 , V_19 -> V_26 ) ;
return - V_32 ;
}
if ( ( V_21 -> V_33 == V_34
&& F_12 ( V_21 )
!= V_36 )
|| ! V_21 -> V_37 ) {
F_13 ( L_3 , V_31 , V_19 -> V_26 ) ;
return - V_38 ;
}
V_25 = V_23 -> V_25 ;
if ( ! V_25 -> V_39 || V_25 -> V_40 . V_41 == V_42 ) {
F_13 ( L_4 , V_31 ) ;
return - V_43 ;
}
V_23 -> V_21 = V_21 ;
V_23 -> V_44 = 0 ;
V_23 -> V_45 = 0 ;
V_23 -> V_23 . V_46 = F_12 ( V_21 ) ;
F_14 ( V_19 ) ;
F_15 ( V_47 , L_5 , V_19 -> V_26 ) ;
return 0 ;
}
static int F_16 ( struct V_18 * V_19 )
{
struct V_22 * V_23 ;
unsigned long V_48 ;
V_23 = F_11 ( V_19 , struct V_22 , V_23 ) ;
if ( ! V_19 || ! V_23 -> V_21 ) {
F_13 ( L_6 , V_31 ,
V_19 ? V_23 -> V_23 . V_26 : NULL ) ;
return - V_32 ;
}
F_17 ( V_48 ) ;
F_18 ( V_23 , - V_43 ) ;
F_14 ( V_19 ) ;
V_23 -> V_21 = NULL ;
V_23 -> V_44 = 1 ;
F_19 ( V_48 ) ;
F_15 ( V_47 , L_7 , V_19 -> V_26 ) ;
return 0 ;
}
static struct V_49 *
F_20 ( struct V_18 * V_19 , T_2 V_50 )
{
struct V_51 * V_52 ;
V_52 = F_21 ( sizeof( * V_52 ) , V_50 ) ;
if ( ! V_52 )
return NULL ;
F_22 ( & V_52 -> V_53 ) ;
return & V_52 -> V_52 ;
}
static void
F_23 ( struct V_18 * V_19 , struct V_49 * V_54 )
{
struct V_51 * V_52 ;
V_52 = F_11 ( V_54 , struct V_51 , V_52 ) ;
F_24 ( ! F_25 ( & V_52 -> V_53 ) ) ;
F_26 ( V_52 ) ;
}
static void F_27 ( struct V_22 * V_23 , struct V_51 * V_52 , int V_55 )
{
unsigned V_44 = V_23 -> V_44 ;
F_28 ( & V_52 -> V_53 ) ;
if ( F_29 ( V_52 -> V_52 . V_55 == - V_56 ) )
V_52 -> V_52 . V_55 = V_55 ;
else
V_55 = V_52 -> V_52 . V_55 ;
if ( V_55 && V_55 != - V_43 )
F_15 ( V_47 , L_8 ,
V_23 -> V_23 . V_26 , & V_52 -> V_52 , V_55 ,
V_52 -> V_52 . V_57 , V_52 -> V_52 . V_58 ) ;
V_23 -> V_44 = 1 ;
V_52 -> V_52 . V_59 ( & V_23 -> V_23 , & V_52 -> V_52 ) ;
V_23 -> V_44 = V_44 ;
}
static inline void F_30 ( struct V_24 * V_25 )
{
V_25 -> V_60 = V_61 ;
}
static int
F_31 ( volatile T_3 * V_62 , struct V_51 * V_52 , unsigned V_63 )
{
T_4 * V_64 ;
unsigned V_58 , V_65 ;
V_64 = V_52 -> V_52 . V_64 + V_52 -> V_52 . V_57 ;
F_32 ( V_64 ) ;
V_58 = F_33 ( V_52 -> V_52 . V_58 - V_52 -> V_52 . V_57 , V_63 ) ;
V_52 -> V_52 . V_57 += V_58 ;
V_65 = V_58 ;
while ( F_29 ( V_65 -- ) )
* V_62 = * V_64 ++ ;
return V_58 ;
}
static int
F_34 ( struct V_22 * V_23 , struct V_51 * V_52 )
{
unsigned V_63 ;
V_63 = F_12 ( V_23 -> V_21 ) ;
do {
unsigned V_65 ;
int V_66 , V_67 ;
V_65 = F_31 ( V_23 -> V_68 , V_52 , V_63 ) ;
if ( F_35 ( V_65 != V_63 ) )
V_66 = V_67 = 1 ;
else {
if ( F_29 ( V_52 -> V_52 . V_58 != V_52 -> V_52 . V_57 )
|| V_52 -> V_52 . V_69 )
V_66 = 0 ;
else
V_66 = 1 ;
V_67 = F_35 ( V_63 < V_23 -> V_30 ) ;
}
F_15 ( V_70 , L_9 ,
V_23 -> V_23 . V_26 , V_65 ,
V_66 ? L_10 : L_11 , V_67 ? L_12 : L_11 ,
V_52 -> V_52 . V_58 - V_52 -> V_52 . V_57 , V_52 ) ;
* V_23 -> V_71 = V_72 ;
if ( V_67 )
* V_23 -> V_71 = V_73 ;
if ( V_66 ) {
F_27 ( V_23 , V_52 , 0 ) ;
if ( F_25 ( & V_23 -> V_53 ) )
F_6 ( V_23 -> V_11 ) ;
return 1 ;
}
} while ( * V_23 -> V_71 & V_74 );
return 0 ;
}
static inline
void F_36 ( struct V_24 * V_25 , T_3 V_48 , const char * V_75 )
{
V_76 = V_48 | V_77 | V_78 ;
V_79 = V_80 ;
V_25 -> V_81 = 0 ;
F_15 ( V_70 , L_13 ,
V_31 , V_75 , V_76 , V_48 ) ;
}
static int
F_37 ( struct V_22 * V_23 , struct V_51 * V_52 )
{
unsigned V_65 ;
int V_67 ;
V_65 = F_31 ( & V_82 , V_52 , V_83 ) ;
V_23 -> V_25 -> V_84 . V_85 . V_86 += V_65 ;
V_67 = ( V_65 != V_83 ) ;
F_15 ( V_70 , L_14 , V_65 ,
V_52 -> V_52 . V_58 - V_52 -> V_52 . V_57 , V_52 ) ;
if ( F_35 ( V_67 ) ) {
if ( V_23 -> V_25 -> V_81 )
F_36 ( V_23 -> V_25 , V_87 , L_15 ) ;
else
V_76 = V_87 ;
V_65 = V_52 -> V_52 . V_58 ;
F_27 ( V_23 , V_52 , 0 ) ;
F_30 ( V_23 -> V_25 ) ;
#ifndef F_38
#if 1
if ( V_65 >= V_83 ) {
V_65 = 100 ;
do {
if ( ( V_76 & V_78 ) != 0 ) {
V_76 = V_78 ;
break;
}
V_65 -- ;
F_39 ( 1 ) ;
} while ( V_65 );
}
#endif
#endif
} else if ( V_23 -> V_25 -> V_81 )
F_36 ( V_23 -> V_25 , 0 , L_16 ) ;
return V_67 ;
}
static int
F_40 ( struct V_22 * V_23 , struct V_51 * V_52 )
{
for (; ; ) {
T_3 V_88 ;
T_4 * V_64 ;
unsigned V_89 , V_65 , V_67 ;
V_88 = * V_23 -> V_71 ;
if ( F_35 ( ( V_88 & V_90 ) == 0 ) )
break;
V_64 = V_52 -> V_52 . V_64 + V_52 -> V_52 . V_57 ;
F_41 ( V_64 ) ;
V_89 = V_52 -> V_52 . V_58 - V_52 -> V_52 . V_57 ;
if ( F_29 ( V_88 & V_91 ) ) {
V_65 = 1 + ( 0x0ff & * V_23 -> V_92 ) ;
V_52 -> V_52 . V_57 += F_33 ( V_65 , V_89 ) ;
} else
V_65 = 0 ;
V_67 = ( V_65 < V_23 -> V_23 . V_46 ) ;
F_15 ( V_70 , L_17 ,
V_23 -> V_23 . V_26 , V_88 , V_65 ,
V_67 ? L_12 : L_11 ,
V_52 , V_52 -> V_52 . V_57 , V_52 -> V_52 . V_58 ) ;
while ( F_29 ( V_65 -- != 0 ) ) {
T_4 V_93 = ( T_4 ) * V_23 -> V_68 ;
if ( F_35 ( V_89 == 0 ) ) {
if ( V_52 -> V_52 . V_55 != - V_94 )
F_13 ( L_18 ,
V_23 -> V_23 . V_26 , V_65 ) ;
V_52 -> V_52 . V_55 = - V_94 ;
} else {
* V_64 ++ = V_93 ;
V_89 -- ;
}
}
* V_23 -> V_71 = V_90 ;
if ( V_23 -> V_33 == V_95 ) {
if ( V_88 & V_96 )
V_52 -> V_52 . V_55 = - V_97 ;
V_67 = 1 ;
}
if ( V_67 || V_52 -> V_52 . V_57 == V_52 -> V_52 . V_58 ) {
F_27 ( V_23 , V_52 , 0 ) ;
if ( F_25 ( & V_23 -> V_53 ) )
F_6 ( V_23 -> V_11 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_42 ( struct V_22 * V_23 , struct V_51 * V_52 )
{
T_4 * V_64 , V_93 ;
unsigned V_89 ;
V_64 = V_52 -> V_52 . V_64 + V_52 -> V_52 . V_57 ;
V_89 = V_52 -> V_52 . V_58 - V_52 -> V_52 . V_57 ;
while ( V_76 & V_98 ) {
V_93 = ( T_4 ) V_82 ;
if ( F_35 ( V_89 == 0 ) ) {
if ( V_52 -> V_52 . V_55 != - V_94 )
F_13 ( L_19 , V_23 -> V_23 . V_26 ) ;
V_52 -> V_52 . V_55 = - V_94 ;
} else {
* V_64 ++ = V_93 ;
V_52 -> V_52 . V_57 ++ ;
V_89 -- ;
}
}
V_76 = V_78 | V_87 ;
if ( V_52 -> V_52 . V_57 >= V_52 -> V_52 . V_58 )
return 1 ;
return 0 ;
}
static int
F_43 ( struct V_18 * V_19 , struct V_49 * V_54 , T_2 V_50 )
{
struct V_51 * V_52 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
unsigned long V_48 ;
V_52 = F_11 ( V_54 , struct V_51 , V_52 ) ;
if ( F_35 ( ! V_54 || ! V_54 -> V_59 || ! V_54 -> V_64
|| ! F_25 ( & V_52 -> V_53 ) ) ) {
F_13 ( L_20 , V_31 ) ;
return - V_32 ;
}
V_23 = F_11 ( V_19 , struct V_22 , V_23 ) ;
if ( F_35 ( ! V_19 || ( ! V_23 -> V_21 && V_23 -> V_23 . V_26 != V_27 ) ) ) {
F_13 ( L_21 , V_31 ) ;
return - V_32 ;
}
V_25 = V_23 -> V_25 ;
if ( F_35 ( ! V_25 -> V_39
|| V_25 -> V_40 . V_41 == V_42 ) ) {
F_13 ( L_4 , V_31 ) ;
return - V_43 ;
}
if ( F_35 ( V_23 -> V_33 == V_95
&& V_52 -> V_52 . V_58 > F_12 ( V_23 -> V_21 ) ) )
return - V_99 ;
F_15 ( V_100 , L_22 ,
V_19 -> V_26 , V_54 , V_54 -> V_58 , V_54 -> V_64 ) ;
F_17 ( V_48 ) ;
V_54 -> V_55 = - V_56 ;
V_54 -> V_57 = 0 ;
if ( F_25 ( & V_23 -> V_53 ) && ! V_23 -> V_44 ) {
if ( V_23 -> V_21 == NULL ) {
unsigned V_58 = V_54 -> V_58 ;
switch ( V_25 -> V_60 ) {
case V_101 :
V_25 -> V_84 . V_85 . V_102 ++ ;
if ( F_37 ( V_23 , V_52 ) )
V_52 = NULL ;
break;
case V_103 :
V_25 -> V_84 . V_104 . V_102 ++ ;
if ( V_25 -> V_105 ) {
F_15 ( V_47 , L_23 ,
V_25 -> V_106 ? L_11 : L_24 ) ;
if ( V_25 -> V_106 )
V_107 = V_108 | V_109
| V_110 ;
F_27 ( V_23 , V_52 , 0 ) ;
V_25 -> V_60 = V_111 ;
F_19 ( V_48 ) ;
return 0 ;
}
if ( V_25 -> V_81 )
F_36 ( V_25 , V_87 , L_25 ) ;
if ( V_58 == 0 || ( ( V_76 & V_98 ) != 0
&& F_42 ( V_23 , V_52 ) ) ) {
F_30 ( V_25 ) ;
F_27 ( V_23 , V_52 , 0 ) ;
V_52 = NULL ;
}
break;
default:
F_13 ( L_26 , V_25 -> V_60 ) ;
F_19 ( V_48 ) ;
return - V_112 ;
}
} else if ( ( V_23 -> V_11 & V_113 ) != 0 ) {
if ( ( * V_23 -> V_71 & V_74 ) != 0
&& F_34 ( V_23 , V_52 ) )
V_52 = NULL ;
} else if ( ( * V_23 -> V_71 & V_114 ) != 0
&& F_40 ( V_23 , V_52 ) ) {
V_52 = NULL ;
}
if ( F_29 ( V_52 && V_23 -> V_21 ) )
F_5 ( V_23 -> V_11 ) ;
}
if ( F_29 ( V_52 != NULL ) )
F_44 ( & V_52 -> V_53 , & V_23 -> V_53 ) ;
F_19 ( V_48 ) ;
return 0 ;
}
static void F_18 ( struct V_22 * V_23 , int V_55 )
{
struct V_51 * V_52 ;
while ( ! F_25 ( & V_23 -> V_53 ) ) {
V_52 = F_45 ( V_23 -> V_53 . V_115 ,
struct V_51 ,
V_53 ) ;
F_27 ( V_23 , V_52 , V_55 ) ;
}
if ( V_23 -> V_21 )
F_6 ( V_23 -> V_11 ) ;
}
static int F_46 ( struct V_18 * V_19 , struct V_49 * V_54 )
{
struct V_22 * V_23 ;
struct V_51 * V_52 ;
unsigned long V_48 ;
V_23 = F_11 ( V_19 , struct V_22 , V_23 ) ;
if ( ! V_19 || V_23 -> V_23 . V_26 == V_27 )
return - V_32 ;
F_17 ( V_48 ) ;
F_47 (req, &ep->queue, queue) {
if ( & V_52 -> V_52 == V_54 )
break;
}
if ( & V_52 -> V_52 != V_54 ) {
F_19 ( V_48 ) ;
return - V_32 ;
}
F_27 ( V_23 , V_52 , - V_116 ) ;
F_19 ( V_48 ) ;
return 0 ;
}
static int F_48 ( struct V_18 * V_19 , int V_117 )
{
struct V_22 * V_23 ;
unsigned long V_48 ;
V_23 = F_11 ( V_19 , struct V_22 , V_23 ) ;
if ( F_35 ( ! V_19
|| ( ! V_23 -> V_21 && V_23 -> V_23 . V_26 != V_27 ) )
|| V_23 -> V_33 == V_95 ) {
F_13 ( L_21 , V_31 ) ;
return - V_32 ;
}
if ( V_117 == 0 ) {
F_13 ( L_27 , V_19 -> V_26 ) ;
return - V_118 ;
}
F_17 ( V_48 ) ;
if ( ( V_23 -> V_11 & V_113 ) != 0
&& ( ( * V_23 -> V_71 & V_74 ) == 0
|| ! F_25 ( & V_23 -> V_53 ) ) ) {
F_19 ( V_48 ) ;
return - V_119 ;
}
* V_23 -> V_71 = V_120 | V_121 ;
if ( ! V_23 -> V_21 ) {
F_49 ( V_23 -> V_25 ) ;
V_23 -> V_25 -> V_81 = 0 ;
V_23 -> V_25 -> V_60 = V_122 ;
} else {
unsigned V_123 ;
for ( V_123 = 0 ; V_123 < 1000 ; V_123 += 20 ) {
if ( * V_23 -> V_71 & V_124 )
break;
F_39 ( 20 ) ;
}
}
F_19 ( V_48 ) ;
F_15 ( V_47 , L_28 , V_19 -> V_26 ) ;
return 0 ;
}
static int F_50 ( struct V_18 * V_19 )
{
struct V_22 * V_23 ;
V_23 = F_11 ( V_19 , struct V_22 , V_23 ) ;
if ( ! V_19 ) {
F_13 ( L_21 , V_31 ) ;
return - V_125 ;
}
if ( ( V_23 -> V_11 & V_113 ) != 0 )
return - V_126 ;
if ( V_23 -> V_25 -> V_40 . V_41 == V_42
|| ( * V_23 -> V_71 & V_114 ) == 0 )
return 0 ;
else
return ( * V_23 -> V_92 & 0xfff ) + 1 ;
}
static void F_14 ( struct V_18 * V_19 )
{
struct V_22 * V_23 ;
V_23 = F_11 ( V_19 , struct V_22 , V_23 ) ;
if ( ! V_19 || V_23 -> V_23 . V_26 == V_27 || ! F_25 ( & V_23 -> V_53 ) ) {
F_13 ( L_21 , V_31 ) ;
return;
}
if ( ( V_23 -> V_11 & V_113 ) == 0 ) {
while ( ( ( * V_23 -> V_71 ) & V_91 ) != 0 )
( void ) * V_23 -> V_68 ;
return;
}
* V_23 -> V_71 = V_72 | V_121 | V_127
| ( V_23 -> V_33 == V_95
? 0 : V_124 ) ;
}
static int F_51 ( struct V_128 * V_129 )
{
return ( ( V_130 & 0x07 ) << 8 ) | ( V_131 & 0xff ) ;
}
static int F_52 ( struct V_128 * V_129 )
{
if ( ( V_76 & V_132 ) == 0 )
return - V_97 ;
F_7 ( V_133 ) ;
return 0 ;
}
static int F_53 ( struct V_24 * V_134 )
{
int V_135 = V_134 -> V_136 && V_134 -> F_53 && ! V_134 -> V_137 ;
F_13 ( L_29 , V_135 ? L_30 : L_31 ) ;
if ( V_135 ) {
if ( ! V_134 -> V_138 ) {
V_134 -> V_138 = 1 ;
F_54 ( V_134 -> V_139 ) ;
F_55 ( V_134 ) ;
}
} else {
if ( V_134 -> V_138 ) {
if ( V_134 -> V_40 . V_41 != V_42 ) {
F_13 ( L_32 , V_134 -> V_39
? V_134 -> V_39 -> V_39 . V_26
: L_33 ) ;
F_56 ( V_134 , V_134 -> V_39 ) ;
}
F_57 ( V_134 ) ;
F_58 ( V_134 -> V_139 ) ;
V_134 -> V_138 = 0 ;
}
}
return 0 ;
}
static int F_59 ( struct V_128 * V_129 , int V_135 )
{
struct V_24 * V_134 ;
V_134 = F_11 ( V_129 , struct V_24 , V_40 ) ;
V_134 -> V_136 = V_135 ;
F_13 ( L_34 , V_135 ? L_35 : L_31 ) ;
F_53 ( V_134 ) ;
return 0 ;
}
static int F_60 ( struct V_128 * V_129 , int V_135 )
{
struct V_24 * V_134 ;
V_134 = F_11 ( V_129 , struct V_24 , V_40 ) ;
if ( ! F_2 ( V_134 -> V_2 -> V_6 ) && ! V_134 -> V_2 -> V_7 )
return - V_126 ;
V_134 -> F_53 = ( V_135 != 0 ) ;
F_53 ( V_134 ) ;
return 0 ;
}
static int F_61 ( struct V_128 * V_129 , unsigned V_140 )
{
struct V_24 * V_134 ;
V_134 = F_11 ( V_129 , struct V_24 , V_40 ) ;
if ( V_134 -> V_141 )
return F_62 ( V_134 -> V_141 , V_140 ) ;
return - V_126 ;
}
static int
F_63 ( struct V_142 * V_143 , void * V_144 )
{
struct V_24 * V_25 = V_143 -> V_145 ;
unsigned long V_48 ;
int V_123 ;
T_3 V_146 ;
F_17 ( V_48 ) ;
F_64 (m, DRIVER_DESC L_36
L_37 ,
driver_name, DRIVER_VERSION SIZE_STR L_38 ,
dev->driver ? dev->driver->driver.name : L_39 ,
dev->gadget.speed == USB_SPEED_FULL ? L_40 : L_41 ) ;
F_64 ( V_143 ,
L_42 ,
V_13 , V_12 , V_147 , V_79 , V_130 , V_131 ) ;
V_146 = V_15 ;
F_64 ( V_143 ,
L_43 , V_146 ,
( V_146 & V_148 ) ? L_44 : L_11 ,
( V_146 & V_149 ) ? L_45 : L_11 ,
( V_146 & V_150 ) ? L_46 : L_11 ,
( V_146 & V_151 ) ? L_47 : L_11 ,
( V_146 & V_152 ) ? L_48 : L_11 ,
( V_146 & V_133 ) ? L_49 : L_11 ,
( V_146 & V_153 ) ? L_50 : L_11 ,
( V_146 & V_154 ) ? L_51 : L_11 ) ;
V_146 = V_76 ;
F_64 ( V_143 ,
L_52 , V_146 ,
( V_146 & V_77 ) ? L_53 : L_11 ,
( V_146 & V_98 ) ? L_54 : L_11 ,
( V_146 & V_155 ) ? L_55 : L_11 ,
( V_146 & V_156 ) ? L_56 : L_11 ,
( V_146 & V_132 ) ? L_57 : L_11 ,
( V_146 & V_157 ) ? L_58 : L_11 ,
( V_146 & V_87 ) ? L_59 : L_11 ,
( V_146 & V_78 ) ? L_60 : L_11 ) ;
if ( V_25 -> V_106 ) {
V_146 = V_107 ;
F_64 ( V_143 ,
L_61 , V_146 ,
( V_146 & V_108 ) ? L_62 : L_11 ,
( V_146 & V_109 ) ? L_63 : L_11 ) ;
}
if ( V_25 -> V_40 . V_41 != V_158 || ! V_25 -> V_39 )
goto F_27;
F_64 ( V_143 , L_64 ,
V_25 -> V_84 . V_85 . V_86 , V_25 -> V_84 . V_85 . V_102 ,
V_25 -> V_84 . V_104 . V_86 , V_25 -> V_84 . V_104 . V_102 ,
V_25 -> V_84 . V_159 ) ;
for ( V_123 = 0 ; V_123 < V_160 ; V_123 ++ ) {
struct V_22 * V_23 = & V_25 -> V_23 [ V_123 ] ;
struct V_51 * V_52 ;
if ( V_123 != 0 ) {
const struct V_20 * V_21 ;
V_21 = V_23 -> V_21 ;
if ( ! V_21 )
continue;
V_146 = * V_25 -> V_23 [ V_123 ] . V_71 ;
F_64 ( V_143 ,
L_65 ,
V_23 -> V_23 . V_26 , F_12 ( V_21 ) ,
L_66 , V_146 , V_23 -> V_45 ) ;
} else
F_64 ( V_143 , L_67 ,
V_23 -> V_45 ) ;
if ( F_25 ( & V_23 -> V_53 ) ) {
F_64 ( V_143 , L_68 ) ;
continue;
}
F_47 (req, &ep->queue, queue) {
F_64 ( V_143 ,
L_69 ,
& V_52 -> V_52 , V_52 -> V_52 . V_57 ,
V_52 -> V_52 . V_58 , V_52 -> V_52 . V_64 ) ;
}
}
F_27:
F_19 ( V_48 ) ;
return 0 ;
}
static int
F_65 ( struct V_161 * V_161 , struct V_162 * V_162 )
{
return F_66 ( V_162 , F_63 , V_161 -> V_163 ) ;
}
static void F_57 ( struct V_24 * V_25 )
{
F_7 ( V_150 | V_148 ) ;
V_12 = V_13 = 0xff ;
V_130 = V_164 ;
F_1 () ;
F_8 ( V_154 ) ;
F_30 ( V_25 ) ;
V_25 -> V_40 . V_41 = V_42 ;
}
static void F_67 ( struct V_24 * V_25 )
{
T_3 V_123 ;
F_22 ( & V_25 -> V_40 . V_165 ) ;
F_22 ( & V_25 -> V_40 . V_166 -> V_165 ) ;
V_25 -> V_60 = V_61 ;
for ( V_123 = 0 ; V_123 < V_160 ; V_123 ++ ) {
struct V_22 * V_23 = & V_25 -> V_23 [ V_123 ] ;
if ( V_123 != 0 )
F_44 ( & V_23 -> V_23 . V_165 , & V_25 -> V_40 . V_165 ) ;
V_23 -> V_21 = NULL ;
V_23 -> V_44 = 0 ;
F_22 ( & V_23 -> V_53 ) ;
V_23 -> V_45 = 0 ;
}
}
static void F_55 ( struct V_24 * V_25 )
{
F_8 ( V_154 ) ;
F_9 ( V_151 | V_152 ) ;
F_30 ( V_25 ) ;
V_25 -> V_40 . V_41 = V_42 ;
V_25 -> V_84 . V_159 = 0 ;
F_7 ( V_154 ) ;
if ( ! ( V_15 & V_153 ) )
F_9 ( V_149 ) ;
if ( V_25 -> V_106 ) {
V_107 = V_109 | V_110 ;
} else {
V_167 = 0x00 ;
V_168 = 0x00 ;
}
F_8 ( V_150 | V_148 ) ;
V_12 &= ~ V_169 ;
F_4 () ;
}
static int F_68 ( struct V_170 * V_39 ,
int (* F_69)( struct V_128 * ) )
{
struct V_24 * V_25 = V_3 ;
int V_171 ;
if ( ! V_39
|| V_39 -> V_172 < V_158
|| ! F_69
|| ! V_39 -> V_173
|| ! V_39 -> V_174 )
return - V_32 ;
if ( ! V_25 )
return - V_125 ;
if ( V_25 -> V_39 )
return - V_175 ;
V_25 -> V_39 = V_39 ;
V_25 -> V_40 . V_25 . V_39 = & V_39 -> V_39 ;
V_25 -> F_53 = 1 ;
V_171 = F_70 ( & V_25 -> V_40 . V_25 ) ;
if ( V_171 ) {
V_176:
V_25 -> V_39 = NULL ;
V_25 -> V_40 . V_25 . V_39 = NULL ;
return V_171 ;
}
V_171 = F_69 ( & V_25 -> V_40 ) ;
if ( V_171 ) {
F_13 ( L_70 ,
V_39 -> V_39 . V_26 , V_171 ) ;
F_71 ( & V_25 -> V_40 . V_25 ) ;
goto V_176;
}
F_13 ( L_71 , V_39 -> V_39 . V_26 ) ;
if ( V_25 -> V_141 ) {
V_171 = F_72 ( V_25 -> V_141 , & V_25 -> V_40 ) ;
if ( V_171 ) {
F_13 ( L_72 ) ;
if ( V_39 -> V_177 )
V_39 -> V_177 ( & V_25 -> V_40 ) ;
goto V_178;
}
}
F_53 ( V_25 ) ;
F_73 ( V_25 ) ;
return 0 ;
V_178:
return V_171 ;
}
static void
F_56 ( struct V_24 * V_25 , struct V_170 * V_39 )
{
int V_123 ;
if ( V_25 -> V_40 . V_41 == V_42 )
V_39 = NULL ;
V_25 -> V_40 . V_41 = V_42 ;
for ( V_123 = 0 ; V_123 < V_160 ; V_123 ++ ) {
struct V_22 * V_23 = & V_25 -> V_23 [ V_123 ] ;
V_23 -> V_44 = 1 ;
F_18 ( V_23 , - V_43 ) ;
}
F_74 ( & V_25 -> V_179 ) ;
if ( V_39 )
V_39 -> V_173 ( & V_25 -> V_40 ) ;
F_67 ( V_25 ) ;
}
static int F_75 ( struct V_170 * V_39 )
{
struct V_24 * V_25 = V_3 ;
if ( ! V_25 )
return - V_125 ;
if ( ! V_39 || V_39 != V_25 -> V_39 || ! V_39 -> V_177 )
return - V_32 ;
F_76 () ;
V_25 -> F_53 = 0 ;
F_53 ( V_25 ) ;
F_56 ( V_25 , V_39 ) ;
F_77 () ;
if ( V_25 -> V_141 )
( void ) F_72 ( V_25 -> V_141 , NULL ) ;
V_39 -> V_177 ( & V_25 -> V_40 ) ;
V_25 -> V_40 . V_25 . V_39 = NULL ;
V_25 -> V_39 = NULL ;
F_71 ( & V_25 -> V_40 . V_25 ) ;
F_13 ( L_73 , V_39 -> V_39 . V_26 ) ;
F_73 ( V_25 ) ;
return 0 ;
}
static T_5
F_78 ( int V_180 , void * V_181 )
{
struct V_24 * V_25 = V_181 ;
int V_136 ;
V_25 -> V_84 . V_159 ++ ;
switch ( V_180 ) {
case V_182 :
V_136 = 1 ;
F_79 ( V_182 ) ;
F_80 ( V_183 ) ;
break;
case V_183 :
V_136 = 0 ;
F_79 ( V_183 ) ;
F_80 ( V_182 ) ;
break;
default:
return V_184 ;
}
F_59 ( & V_25 -> V_40 , V_136 ) ;
return V_185 ;
}
static inline void F_81 ( struct V_24 * V_25 )
{
unsigned V_123 ;
for ( V_123 = 1 ; V_123 < V_160 ; V_123 ++ )
F_18 ( & V_25 -> V_23 [ V_123 ] , - V_186 ) ;
}
static void F_82 ( unsigned long V_181 )
{
struct V_24 * V_25 = ( void * ) V_181 ;
F_76 () ;
if ( V_25 -> V_60 == V_122
&& ( V_76 & V_155 ) == 0
&& ( V_76 & V_156 ) == 0 ) {
V_76 = V_155 | V_157 ;
F_15 ( V_47 , L_74 ) ;
F_49 ( V_25 ) ;
}
F_77 () ;
}
static void F_83 ( struct V_24 * V_25 )
{
T_3 V_187 = V_76 ;
struct V_22 * V_23 = & V_25 -> V_23 [ 0 ] ;
struct V_51 * V_52 ;
union {
struct V_188 V_189 ;
T_4 V_190 [ 8 ] ;
T_3 V_191 [ 2 ] ;
} V_192 ;
if ( F_25 ( & V_23 -> V_53 ) )
V_52 = NULL ;
else
V_52 = F_45 ( V_23 -> V_53 . V_115 , struct V_51 , V_53 ) ;
if ( V_187 & V_156 ) {
F_18 ( V_23 , - V_193 ) ;
V_76 = V_156 ;
F_84 ( & V_25 -> V_179 ) ;
F_30 ( V_25 ) ;
}
if ( ( V_187 & V_77 ) != 0 && V_25 -> V_60 != V_61 ) {
F_18 ( V_23 , 0 ) ;
F_84 ( & V_25 -> V_179 ) ;
F_30 ( V_25 ) ;
}
switch ( V_25 -> V_60 ) {
case V_61 :
V_187 = V_76 ;
if ( F_29 ( ( V_187 & ( V_78 | V_77 | V_98 ) )
== ( V_78 | V_77 | V_98 ) ) ) {
int V_123 ;
F_18 ( V_23 , - V_194 ) ;
for ( V_123 = 0 ; V_123 < 8 ; V_123 ++ ) {
if ( F_35 ( ! ( V_76 & V_98 ) ) ) {
V_195:
F_13 ( L_75 , V_123 ) ;
goto V_196;
}
V_192 . V_190 [ V_123 ] = ( T_4 ) V_82 ;
}
if ( F_35 ( ( V_76 & V_98 ) != 0 ) )
goto V_195;
V_197:
F_15 ( V_47 , L_76 ,
V_192 . V_189 . V_198 , V_192 . V_189 . V_199 ,
F_85 ( V_192 . V_189 . V_200 ) ,
F_85 ( V_192 . V_189 . V_201 ) ,
F_85 ( V_192 . V_189 . V_202 ) ) ;
V_25 -> V_203 = ( V_192 . V_189 . V_198 & V_204 )
== V_205 ;
V_25 -> V_105 = 0 ;
V_25 -> V_81 = 1 ;
switch ( V_192 . V_189 . V_199 ) {
case V_206 :
if ( V_192 . V_189 . V_198 == V_207 ) {
V_208:
V_25 -> V_105 = 1 ;
F_81 ( V_25 ) ;
}
break;
case V_209 :
if ( V_192 . V_189 . V_198 == V_210 ) {
F_13 ( L_77 ,
F_85 ( V_192 . V_189 . V_201 ) ,
F_85 ( V_192 . V_189 . V_200 ) ) ;
goto V_208;
}
break;
case V_211 :
if ( V_192 . V_189 . V_198 == V_207 ) {
F_36 ( V_25 , 0 , L_78 ) ;
return;
}
break;
}
if ( V_192 . V_189 . V_198 & V_113 )
V_25 -> V_60 = V_101 ;
else
V_25 -> V_60 = V_103 ;
V_123 = V_25 -> V_39 -> V_174 ( & V_25 -> V_40 , & V_192 . V_189 ) ;
if ( V_123 < 0 ) {
if ( V_25 -> V_105 ) {
F_86 ( L_79 ,
V_192 . V_189 . V_199 , V_123 ) ;
return;
}
F_15 ( V_47 , L_80
L_81 , V_76 , V_123 ) ;
V_196:
F_36 ( V_25 , V_155 | V_157 , L_82 ) ;
F_49 ( V_25 ) ;
V_25 -> V_60 = V_122 ;
} else if ( V_25 -> V_81 ) {
if ( F_29 ( V_25 -> V_60 == V_101
|| V_25 -> V_203 || V_192 . V_189 . V_202 ) )
F_36 ( V_25 , 0 , L_83 ) ;
else
F_36 ( V_25 , V_87 , L_84 ) ;
}
return;
} else if ( F_29 ( ( V_187 & ( V_78 | V_77 ) )
== ( V_78 | V_77 ) ) ) {
unsigned V_123 ;
F_15 ( V_47 , L_85 ) ;
F_18 ( V_23 , - V_194 ) ;
for ( V_123 = 0 ; V_123 < 8 ; V_123 ++ )
V_192 . V_190 [ V_123 ] = ( T_4 ) V_82 ;
if ( ( V_192 . V_189 . V_198 & V_212 )
> V_213 )
goto V_196;
if ( V_192 . V_191 [ 0 ] == 0 && V_192 . V_191 [ 1 ] == 0 )
goto V_196;
goto V_197;
} else {
V_76 = V_187 & ( V_77 | V_78 ) ;
}
break;
case V_101 :
if ( V_187 & V_78 ) {
V_76 = V_78 | V_157 ;
F_15 ( V_47 , L_86 ) ;
if ( V_52 )
F_27 ( V_23 , V_52 , 0 ) ;
F_30 ( V_25 ) ;
} else {
if ( V_52 ) {
( void ) F_37 ( V_23 , V_52 ) ;
}
}
break;
case V_103 :
if ( V_187 & V_78 ) {
if ( V_52 ) {
if ( F_42 ( V_23 , V_52 ) )
F_27 ( V_23 , V_52 , 0 ) ;
}
} else {
F_15 ( V_47 , L_87 ) ;
if ( V_52 )
F_27 ( V_23 , V_52 , 0 ) ;
F_30 ( V_25 ) ;
}
break;
case V_111 :
if ( V_52 )
F_27 ( V_23 , V_52 , 0 ) ;
if ( V_187 & V_78 )
V_76 = V_78 ;
F_30 ( V_25 ) ;
break;
case V_122 :
V_76 = V_155 ;
break;
}
V_79 = V_80 ;
}
static void F_87 ( struct V_22 * V_23 )
{
struct V_51 * V_52 ;
int V_214 = V_23 -> V_11 & V_113 ;
int V_215 ;
T_3 V_88 , V_146 ;
do {
V_215 = 0 ;
if ( F_29 ( ! F_25 ( & V_23 -> V_53 ) ) )
V_52 = F_45 ( V_23 -> V_53 . V_115 ,
struct V_51 , V_53 ) ;
else
V_52 = NULL ;
V_88 = * V_23 -> V_71 ;
if ( F_35 ( V_214 ) ) {
V_146 = V_127 ;
if ( F_29 ( V_23 -> V_33 == V_34 ) )
V_146 |= V_124 ;
V_146 &= V_88 ;
if ( F_29 ( V_146 ) )
* V_23 -> V_71 = V_146 ;
if ( V_52 && F_29 ( ( V_88 & V_74 ) != 0 ) )
V_215 = F_34 ( V_23 , V_52 ) ;
} else {
if ( F_29 ( V_23 -> V_33 == V_34 ) )
V_146 = V_216 | V_217 ;
else
V_146 = V_96 | V_218 ;
V_146 &= V_88 ;
if ( F_29 ( V_146 ) )
* V_23 -> V_71 = V_146 ;
if ( F_29 ( V_52 ) ) {
V_215 = F_40 ( V_23 , V_52 ) ;
} else
F_6 ( V_23 -> V_11 ) ;
}
V_23 -> V_45 ++ ;
} while ( V_215 );
}
static T_5
F_88 ( int V_180 , void * V_181 )
{
struct V_24 * V_25 = V_181 ;
int V_219 ;
V_25 -> V_84 . V_159 ++ ;
do {
T_3 V_17 = V_15 ;
V_219 = 0 ;
if ( F_35 ( V_17 & V_151 ) ) {
F_9 ( V_151 ) ;
V_219 = 1 ;
F_15 ( V_47 , L_88 ) ;
if ( V_25 -> V_40 . V_41 != V_42
&& V_25 -> V_39
&& V_25 -> V_39 -> V_220 )
V_25 -> V_39 -> V_220 ( & V_25 -> V_40 ) ;
F_30 ( V_25 ) ;
}
if ( F_35 ( V_17 & V_152 ) ) {
F_9 ( V_152 ) ;
V_219 = 1 ;
F_15 ( V_47 , L_89 ) ;
if ( V_25 -> V_40 . V_41 != V_42
&& V_25 -> V_39
&& V_25 -> V_39 -> V_221 )
V_25 -> V_39 -> V_221 ( & V_25 -> V_40 ) ;
}
if ( F_35 ( V_17 & V_149 ) ) {
F_9 ( V_149 ) ;
V_219 = 1 ;
if ( ( V_15 & V_153 ) == 0 ) {
F_15 ( V_47 , L_90 ) ;
F_56 ( V_25 , V_25 -> V_39 ) ;
} else {
F_15 ( V_47 , L_91 ) ;
V_25 -> V_40 . V_41 = V_158 ;
memset ( & V_25 -> V_84 , 0 , sizeof V_25 -> V_84 ) ;
}
} else {
T_3 V_222 = V_79 & ~ V_12 ;
T_3 V_223 = V_147 & ~ V_13 ;
int V_123 ;
if ( F_35 ( ! V_222 && ! V_223 ) )
continue;
F_15 ( V_70 , L_92 , V_223 , V_222 ) ;
if ( V_222 & V_80 ) {
V_25 -> V_23 [ 0 ] . V_45 ++ ;
F_83 ( V_25 ) ;
V_219 = 1 ;
}
for ( V_123 = 0 ; V_123 < 8 ; V_123 ++ ) {
T_3 V_146 = 1 << V_123 ;
if ( V_123 && ( V_222 & V_146 ) ) {
F_87 ( & V_25 -> V_23 [ V_123 ] ) ;
V_79 |= V_146 ;
V_219 = 1 ;
}
#ifndef F_89
if ( V_223 & V_146 ) {
F_87 ( & V_25 -> V_23 [ V_123 + 8 ] ) ;
V_147 |= V_146 ;
V_219 = 1 ;
}
#endif
}
}
} while ( V_219 );
return V_185 ;
}
static void F_90 ( struct V_224 * V_25 )
{
F_13 ( L_93 , V_31 , F_91 ( V_25 ) ) ;
}
static int T_6 F_92 ( struct V_225 * V_226 )
{
struct V_24 * V_25 = & V_227 ;
int V_171 , V_180 ;
T_3 V_228 ;
asm("mrc%? p15, 0, %0, c0, c0" : "=r" (chiprev));
if ( ( V_228 & V_229 ) != V_230 ) {
F_93 ( L_94 , V_231 ) ;
return - V_125 ;
}
switch ( V_228 & V_232 ) {
#if F_94 ( V_233 )
case V_234 :
V_25 -> V_106 = 1 ;
break;
case V_235 :
case V_236 :
case V_237 : case V_238 :
case V_239 : case V_240 :
case V_241 : case V_242 :
case V_243 : case V_244 :
break;
#elif F_94 ( F_38 )
case V_245 :
case V_246 :
case V_247 :
V_25 -> V_106 = 1 ;
break;
#endif
default:
F_93 ( L_95 ,
V_231 , V_228 ) ;
return - V_125 ;
}
V_180 = F_95 ( V_226 , 0 ) ;
if ( V_180 < 0 )
return - V_125 ;
V_25 -> V_139 = F_96 ( & V_226 -> V_25 , NULL ) ;
if ( F_97 ( V_25 -> V_139 ) ) {
V_171 = F_98 ( V_25 -> V_139 ) ;
goto V_248;
}
F_99 ( L_96 , V_231 , V_180 ,
V_25 -> V_106 ? L_11 : L_97 ,
V_249 L_38
) ;
V_25 -> V_25 = & V_226 -> V_25 ;
V_25 -> V_2 = V_226 -> V_25 . V_250 ;
V_25 -> V_141 = F_100 () ;
if ( F_2 ( V_25 -> V_2 -> V_6 ) ) {
if ( ( V_171 = F_101 ( V_25 -> V_2 -> V_6 ,
L_98 ) ) ) {
F_102 ( & V_226 -> V_25 ,
L_99 ,
V_25 -> V_2 -> V_6 , V_171 ) ;
goto V_251;
}
F_103 ( V_25 -> V_2 -> V_6 , 0 ) ;
}
F_104 ( & V_25 -> V_179 ) ;
V_25 -> V_179 . V_252 = F_82 ;
V_25 -> V_179 . V_253 = ( unsigned long ) V_25 ;
F_105 ( & V_25 -> V_40 . V_25 ) ;
V_25 -> V_40 . V_25 . V_254 = & V_226 -> V_25 ;
V_25 -> V_40 . V_25 . V_255 = V_226 -> V_25 . V_255 ;
V_3 = V_25 ;
F_106 ( V_226 , V_25 ) ;
F_57 ( V_25 ) ;
F_67 ( V_25 ) ;
V_25 -> V_136 = 0 ;
V_171 = F_107 ( V_180 , F_88 ,
0 , V_231 , V_25 ) ;
if ( V_171 != 0 ) {
F_93 ( L_100 ,
V_231 , V_180 , V_171 ) ;
goto V_256;
}
V_25 -> V_257 = 1 ;
#ifdef F_108
if ( F_109 () ) {
V_171 = F_107 ( V_183 ,
F_78 ,
V_258 ,
V_231 , V_25 ) ;
if ( V_171 != 0 ) {
F_93 ( L_101 ,
V_231 , V_183 , V_171 ) ;
goto V_259;
}
V_171 = F_107 ( V_182 ,
F_78 ,
V_258 ,
V_231 , V_25 ) ;
if ( V_171 != 0 ) {
F_93 ( L_101 ,
V_231 , V_182 , V_171 ) ;
goto V_260;
}
} else
#endif
F_110 ( V_25 ) ;
V_171 = F_111 ( & V_226 -> V_25 , & V_25 -> V_40 ) ;
if ( ! V_171 )
return V_171 ;
F_112 ( V_25 ) ;
#ifdef F_108
V_260:
F_113 ( V_183 , V_25 ) ;
V_259:
F_113 ( V_180 , V_25 ) ;
#endif
V_256:
if ( F_2 ( V_25 -> V_2 -> V_6 ) )
F_114 ( V_25 -> V_2 -> V_6 ) ;
V_251:
if ( V_25 -> V_141 ) {
F_115 ( V_25 -> V_141 ) ;
V_25 -> V_141 = NULL ;
}
F_116 ( V_25 -> V_139 ) ;
V_248:
return V_171 ;
}
static void F_117 ( struct V_225 * V_181 )
{
F_1 () ;
}
static int T_7 F_118 ( struct V_225 * V_226 )
{
struct V_24 * V_25 = F_119 ( V_226 ) ;
F_120 ( & V_25 -> V_40 ) ;
if ( V_25 -> V_39 )
return - V_175 ;
V_25 -> F_53 = 0 ;
F_53 ( V_25 ) ;
F_112 ( V_25 ) ;
if ( V_25 -> V_257 ) {
F_113 ( F_95 ( V_226 , 0 ) , V_25 ) ;
V_25 -> V_257 = 0 ;
}
#ifdef F_108
if ( F_109 () ) {
F_113 ( V_183 , V_25 ) ;
F_113 ( V_182 , V_25 ) ;
}
#endif
if ( F_2 ( V_25 -> V_2 -> V_6 ) )
F_114 ( V_25 -> V_2 -> V_6 ) ;
F_116 ( V_25 -> V_139 ) ;
if ( V_25 -> V_141 ) {
F_115 ( V_25 -> V_141 ) ;
V_25 -> V_141 = NULL ;
}
F_106 ( V_226 , NULL ) ;
V_3 = NULL ;
return 0 ;
}
static int F_121 ( struct V_225 * V_25 , T_8 V_261 )
{
struct V_24 * V_134 = F_119 ( V_25 ) ;
unsigned long V_48 ;
if ( ! F_2 ( V_134 -> V_2 -> V_6 ) && ! V_134 -> V_2 -> V_7 )
F_86 ( L_102 ) ;
V_134 -> V_137 = 1 ;
F_17 ( V_48 ) ;
F_53 ( V_134 ) ;
F_19 ( V_48 ) ;
return 0 ;
}
static int F_122 ( struct V_225 * V_25 )
{
struct V_24 * V_134 = F_119 ( V_25 ) ;
unsigned long V_48 ;
V_134 -> V_137 = 0 ;
F_17 ( V_48 ) ;
F_53 ( V_134 ) ;
F_19 ( V_48 ) ;
return 0 ;
}
static int T_6 F_123 ( void )
{
F_124 ( L_103 , V_231 , V_262 ) ;
return F_125 ( & V_263 , F_92 ) ;
}
static void T_7 F_126 ( void )
{
F_127 ( & V_263 ) ;
}
