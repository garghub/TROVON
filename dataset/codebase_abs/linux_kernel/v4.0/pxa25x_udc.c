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
if ( ! V_19 || ! V_21 || V_19 -> V_26 == V_27
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
V_23 -> V_23 . V_21 = V_21 ;
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
if ( ! V_19 || ! V_23 -> V_23 . V_21 ) {
F_13 ( L_6 , V_31 ,
V_19 ? V_23 -> V_23 . V_26 : NULL ) ;
return - V_32 ;
}
F_17 ( V_48 ) ;
F_18 ( V_23 , - V_43 ) ;
F_14 ( V_19 ) ;
V_23 -> V_23 . V_21 = NULL ;
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
F_30 ( & V_23 -> V_23 , & V_52 -> V_52 ) ;
V_23 -> V_44 = V_44 ;
}
static inline void F_31 ( struct V_24 * V_25 )
{
V_25 -> V_59 = V_60 ;
}
static int
F_32 ( volatile T_3 * V_61 , struct V_51 * V_52 , unsigned V_62 )
{
T_4 * V_63 ;
unsigned V_58 , V_64 ;
V_63 = V_52 -> V_52 . V_63 + V_52 -> V_52 . V_57 ;
F_33 ( V_63 ) ;
V_58 = F_34 ( V_52 -> V_52 . V_58 - V_52 -> V_52 . V_57 , V_62 ) ;
V_52 -> V_52 . V_57 += V_58 ;
V_64 = V_58 ;
while ( F_29 ( V_64 -- ) )
* V_61 = * V_63 ++ ;
return V_58 ;
}
static int
F_35 ( struct V_22 * V_23 , struct V_51 * V_52 )
{
unsigned V_62 ;
V_62 = F_12 ( V_23 -> V_23 . V_21 ) ;
do {
unsigned V_64 ;
int V_65 , V_66 ;
V_64 = F_32 ( V_23 -> V_67 , V_52 , V_62 ) ;
if ( F_36 ( V_64 != V_62 ) )
V_65 = V_66 = 1 ;
else {
if ( F_29 ( V_52 -> V_52 . V_58 != V_52 -> V_52 . V_57 )
|| V_52 -> V_52 . V_68 )
V_65 = 0 ;
else
V_65 = 1 ;
V_66 = F_36 ( V_62 < V_23 -> V_30 ) ;
}
F_15 ( V_69 , L_9 ,
V_23 -> V_23 . V_26 , V_64 ,
V_65 ? L_10 : L_11 , V_66 ? L_12 : L_11 ,
V_52 -> V_52 . V_58 - V_52 -> V_52 . V_57 , V_52 ) ;
* V_23 -> V_70 = V_71 ;
if ( V_66 )
* V_23 -> V_70 = V_72 ;
if ( V_65 ) {
F_27 ( V_23 , V_52 , 0 ) ;
if ( F_25 ( & V_23 -> V_53 ) )
F_6 ( V_23 -> V_11 ) ;
return 1 ;
}
} while ( * V_23 -> V_70 & V_73 );
return 0 ;
}
static inline
void F_37 ( struct V_24 * V_25 , T_3 V_48 , const char * V_74 )
{
V_75 = V_48 | V_76 | V_77 ;
V_78 = V_79 ;
V_25 -> V_80 = 0 ;
F_15 ( V_69 , L_13 ,
V_31 , V_74 , V_75 , V_48 ) ;
}
static int
F_38 ( struct V_22 * V_23 , struct V_51 * V_52 )
{
unsigned V_64 ;
int V_66 ;
V_64 = F_32 ( & V_81 , V_52 , V_82 ) ;
V_23 -> V_25 -> V_83 . V_84 . V_85 += V_64 ;
V_66 = ( V_64 != V_82 ) ;
F_15 ( V_69 , L_14 , V_64 ,
V_52 -> V_52 . V_58 - V_52 -> V_52 . V_57 , V_52 ) ;
if ( F_36 ( V_66 ) ) {
if ( V_23 -> V_25 -> V_80 )
F_37 ( V_23 -> V_25 , V_86 , L_15 ) ;
else
V_75 = V_86 ;
V_64 = V_52 -> V_52 . V_58 ;
F_27 ( V_23 , V_52 , 0 ) ;
F_31 ( V_23 -> V_25 ) ;
#ifndef F_39
#if 1
if ( V_64 >= V_82 ) {
V_64 = 100 ;
do {
if ( ( V_75 & V_77 ) != 0 ) {
V_75 = V_77 ;
break;
}
V_64 -- ;
F_40 ( 1 ) ;
} while ( V_64 );
}
#endif
#endif
} else if ( V_23 -> V_25 -> V_80 )
F_37 ( V_23 -> V_25 , 0 , L_16 ) ;
return V_66 ;
}
static int
F_41 ( struct V_22 * V_23 , struct V_51 * V_52 )
{
for (; ; ) {
T_3 V_87 ;
T_4 * V_63 ;
unsigned V_88 , V_64 , V_66 ;
V_87 = * V_23 -> V_70 ;
if ( F_36 ( ( V_87 & V_89 ) == 0 ) )
break;
V_63 = V_52 -> V_52 . V_63 + V_52 -> V_52 . V_57 ;
F_42 ( V_63 ) ;
V_88 = V_52 -> V_52 . V_58 - V_52 -> V_52 . V_57 ;
if ( F_29 ( V_87 & V_90 ) ) {
V_64 = 1 + ( 0x0ff & * V_23 -> V_91 ) ;
V_52 -> V_52 . V_57 += F_34 ( V_64 , V_88 ) ;
} else
V_64 = 0 ;
V_66 = ( V_64 < V_23 -> V_23 . V_46 ) ;
F_15 ( V_69 , L_17 ,
V_23 -> V_23 . V_26 , V_87 , V_64 ,
V_66 ? L_12 : L_11 ,
V_52 , V_52 -> V_52 . V_57 , V_52 -> V_52 . V_58 ) ;
while ( F_29 ( V_64 -- != 0 ) ) {
T_4 V_92 = ( T_4 ) * V_23 -> V_67 ;
if ( F_36 ( V_88 == 0 ) ) {
if ( V_52 -> V_52 . V_55 != - V_93 )
F_13 ( L_18 ,
V_23 -> V_23 . V_26 , V_64 ) ;
V_52 -> V_52 . V_55 = - V_93 ;
} else {
* V_63 ++ = V_92 ;
V_88 -- ;
}
}
* V_23 -> V_70 = V_89 ;
if ( V_23 -> V_33 == V_94 ) {
if ( V_87 & V_95 )
V_52 -> V_52 . V_55 = - V_96 ;
V_66 = 1 ;
}
if ( V_66 || V_52 -> V_52 . V_57 == V_52 -> V_52 . V_58 ) {
F_27 ( V_23 , V_52 , 0 ) ;
if ( F_25 ( & V_23 -> V_53 ) )
F_6 ( V_23 -> V_11 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_43 ( struct V_22 * V_23 , struct V_51 * V_52 )
{
T_4 * V_63 , V_92 ;
unsigned V_88 ;
V_63 = V_52 -> V_52 . V_63 + V_52 -> V_52 . V_57 ;
V_88 = V_52 -> V_52 . V_58 - V_52 -> V_52 . V_57 ;
while ( V_75 & V_97 ) {
V_92 = ( T_4 ) V_81 ;
if ( F_36 ( V_88 == 0 ) ) {
if ( V_52 -> V_52 . V_55 != - V_93 )
F_13 ( L_19 , V_23 -> V_23 . V_26 ) ;
V_52 -> V_52 . V_55 = - V_93 ;
} else {
* V_63 ++ = V_92 ;
V_52 -> V_52 . V_57 ++ ;
V_88 -- ;
}
}
V_75 = V_77 | V_86 ;
if ( V_52 -> V_52 . V_57 >= V_52 -> V_52 . V_58 )
return 1 ;
return 0 ;
}
static int
F_44 ( struct V_18 * V_19 , struct V_49 * V_54 , T_2 V_50 )
{
struct V_51 * V_52 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
unsigned long V_48 ;
V_52 = F_11 ( V_54 , struct V_51 , V_52 ) ;
if ( F_36 ( ! V_54 || ! V_54 -> V_98 || ! V_54 -> V_63
|| ! F_25 ( & V_52 -> V_53 ) ) ) {
F_13 ( L_20 , V_31 ) ;
return - V_32 ;
}
V_23 = F_11 ( V_19 , struct V_22 , V_23 ) ;
if ( F_36 ( ! V_19 || ( ! V_23 -> V_23 . V_21 && V_23 -> V_23 . V_26 != V_27 ) ) ) {
F_13 ( L_21 , V_31 ) ;
return - V_32 ;
}
V_25 = V_23 -> V_25 ;
if ( F_36 ( ! V_25 -> V_39
|| V_25 -> V_40 . V_41 == V_42 ) ) {
F_13 ( L_4 , V_31 ) ;
return - V_43 ;
}
if ( F_36 ( V_23 -> V_33 == V_94
&& V_52 -> V_52 . V_58 > F_12 ( V_23 -> V_23 . V_21 ) ) )
return - V_99 ;
F_15 ( V_100 , L_22 ,
V_19 -> V_26 , V_54 , V_54 -> V_58 , V_54 -> V_63 ) ;
F_17 ( V_48 ) ;
V_54 -> V_55 = - V_56 ;
V_54 -> V_57 = 0 ;
if ( F_25 ( & V_23 -> V_53 ) && ! V_23 -> V_44 ) {
if ( V_23 -> V_23 . V_21 == NULL ) {
unsigned V_58 = V_54 -> V_58 ;
switch ( V_25 -> V_59 ) {
case V_101 :
V_25 -> V_83 . V_84 . V_102 ++ ;
if ( F_38 ( V_23 , V_52 ) )
V_52 = NULL ;
break;
case V_103 :
V_25 -> V_83 . V_104 . V_102 ++ ;
if ( V_25 -> V_105 ) {
F_15 ( V_47 , L_23 ,
V_25 -> V_106 ? L_11 : L_24 ) ;
if ( V_25 -> V_106 )
V_107 = V_108 | V_109
| V_110 ;
F_27 ( V_23 , V_52 , 0 ) ;
V_25 -> V_59 = V_111 ;
F_19 ( V_48 ) ;
return 0 ;
}
if ( V_25 -> V_80 )
F_37 ( V_25 , V_86 , L_25 ) ;
if ( V_58 == 0 || ( ( V_75 & V_97 ) != 0
&& F_43 ( V_23 , V_52 ) ) ) {
F_31 ( V_25 ) ;
F_27 ( V_23 , V_52 , 0 ) ;
V_52 = NULL ;
}
break;
default:
F_13 ( L_26 , V_25 -> V_59 ) ;
F_19 ( V_48 ) ;
return - V_112 ;
}
} else if ( ( V_23 -> V_11 & V_113 ) != 0 ) {
if ( ( * V_23 -> V_70 & V_73 ) != 0
&& F_35 ( V_23 , V_52 ) )
V_52 = NULL ;
} else if ( ( * V_23 -> V_70 & V_114 ) != 0
&& F_41 ( V_23 , V_52 ) ) {
V_52 = NULL ;
}
if ( F_29 ( V_52 && V_23 -> V_23 . V_21 ) )
F_5 ( V_23 -> V_11 ) ;
}
if ( F_29 ( V_52 != NULL ) )
F_45 ( & V_52 -> V_53 , & V_23 -> V_53 ) ;
F_19 ( V_48 ) ;
return 0 ;
}
static void F_18 ( struct V_22 * V_23 , int V_55 )
{
struct V_51 * V_52 ;
while ( ! F_25 ( & V_23 -> V_53 ) ) {
V_52 = F_46 ( V_23 -> V_53 . V_115 ,
struct V_51 ,
V_53 ) ;
F_27 ( V_23 , V_52 , V_55 ) ;
}
if ( V_23 -> V_23 . V_21 )
F_6 ( V_23 -> V_11 ) ;
}
static int F_47 ( struct V_18 * V_19 , struct V_49 * V_54 )
{
struct V_22 * V_23 ;
struct V_51 * V_52 ;
unsigned long V_48 ;
V_23 = F_11 ( V_19 , struct V_22 , V_23 ) ;
if ( ! V_19 || V_23 -> V_23 . V_26 == V_27 )
return - V_32 ;
F_17 ( V_48 ) ;
F_48 (req, &ep->queue, queue) {
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
static int F_49 ( struct V_18 * V_19 , int V_117 )
{
struct V_22 * V_23 ;
unsigned long V_48 ;
V_23 = F_11 ( V_19 , struct V_22 , V_23 ) ;
if ( F_36 ( ! V_19
|| ( ! V_23 -> V_23 . V_21 && V_23 -> V_23 . V_26 != V_27 ) )
|| V_23 -> V_33 == V_94 ) {
F_13 ( L_21 , V_31 ) ;
return - V_32 ;
}
if ( V_117 == 0 ) {
F_13 ( L_27 , V_19 -> V_26 ) ;
return - V_118 ;
}
F_17 ( V_48 ) ;
if ( ( V_23 -> V_11 & V_113 ) != 0
&& ( ( * V_23 -> V_70 & V_73 ) == 0
|| ! F_25 ( & V_23 -> V_53 ) ) ) {
F_19 ( V_48 ) ;
return - V_119 ;
}
* V_23 -> V_70 = V_120 | V_121 ;
if ( ! V_23 -> V_23 . V_21 ) {
F_50 ( V_23 -> V_25 ) ;
V_23 -> V_25 -> V_80 = 0 ;
V_23 -> V_25 -> V_59 = V_122 ;
} else {
unsigned V_123 ;
for ( V_123 = 0 ; V_123 < 1000 ; V_123 += 20 ) {
if ( * V_23 -> V_70 & V_124 )
break;
F_40 ( 20 ) ;
}
}
F_19 ( V_48 ) ;
F_15 ( V_47 , L_28 , V_19 -> V_26 ) ;
return 0 ;
}
static int F_51 ( struct V_18 * V_19 )
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
|| ( * V_23 -> V_70 & V_114 ) == 0 )
return 0 ;
else
return ( * V_23 -> V_91 & 0xfff ) + 1 ;
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
while ( ( ( * V_23 -> V_70 ) & V_90 ) != 0 )
( void ) * V_23 -> V_67 ;
return;
}
* V_23 -> V_70 = V_71 | V_121 | V_127
| ( V_23 -> V_33 == V_94
? 0 : V_124 ) ;
}
static int F_52 ( struct V_128 * V_129 )
{
return ( ( V_130 & 0x07 ) << 8 ) | ( V_131 & 0xff ) ;
}
static int F_53 ( struct V_128 * V_129 )
{
if ( ( V_75 & V_132 ) == 0 )
return - V_96 ;
F_7 ( V_133 ) ;
return 0 ;
}
static int F_54 ( struct V_24 * V_134 )
{
int V_135 = V_134 -> V_136 && V_134 -> F_54 && ! V_134 -> V_137 ;
F_13 ( L_29 , V_135 ? L_30 : L_31 ) ;
if ( V_135 ) {
if ( ! V_134 -> V_138 ) {
V_134 -> V_138 = 1 ;
F_55 ( V_134 -> V_139 ) ;
F_56 ( V_134 ) ;
}
} else {
if ( V_134 -> V_138 ) {
if ( V_134 -> V_40 . V_41 != V_42 ) {
F_13 ( L_32 , V_134 -> V_39
? V_134 -> V_39 -> V_39 . V_26
: L_33 ) ;
F_57 ( V_134 , V_134 -> V_39 ) ;
}
F_58 ( V_134 ) ;
F_59 ( V_134 -> V_139 ) ;
V_134 -> V_138 = 0 ;
}
}
return 0 ;
}
static int F_60 ( struct V_128 * V_129 , int V_135 )
{
struct V_24 * V_134 ;
V_134 = F_11 ( V_129 , struct V_24 , V_40 ) ;
V_134 -> V_136 = V_135 ;
F_13 ( L_34 , V_135 ? L_35 : L_31 ) ;
F_54 ( V_134 ) ;
return 0 ;
}
static int F_61 ( struct V_128 * V_129 , int V_135 )
{
struct V_24 * V_134 ;
V_134 = F_11 ( V_129 , struct V_24 , V_40 ) ;
if ( ! F_2 ( V_134 -> V_2 -> V_6 ) && ! V_134 -> V_2 -> V_7 )
return - V_126 ;
V_134 -> F_54 = ( V_135 != 0 ) ;
F_54 ( V_134 ) ;
return 0 ;
}
static int F_62 ( struct V_128 * V_129 , unsigned V_140 )
{
struct V_24 * V_134 ;
V_134 = F_11 ( V_129 , struct V_24 , V_40 ) ;
if ( ! F_63 ( V_134 -> V_141 ) )
return F_64 ( V_134 -> V_141 , V_140 ) ;
return - V_126 ;
}
static int
F_65 ( struct V_142 * V_143 , void * V_144 )
{
struct V_24 * V_25 = V_143 -> V_145 ;
unsigned long V_48 ;
int V_123 ;
T_3 V_146 ;
F_17 ( V_48 ) ;
F_66 (m, DRIVER_DESC L_36
L_37 ,
driver_name, DRIVER_VERSION SIZE_STR L_38 ,
dev->driver ? dev->driver->driver.name : L_39 ,
dev->gadget.speed == USB_SPEED_FULL ? L_40 : L_41 ) ;
F_66 ( V_143 ,
L_42 ,
V_13 , V_12 , V_147 , V_78 , V_130 , V_131 ) ;
V_146 = V_15 ;
F_66 ( V_143 ,
L_43 , V_146 ,
( V_146 & V_148 ) ? L_44 : L_11 ,
( V_146 & V_149 ) ? L_45 : L_11 ,
( V_146 & V_150 ) ? L_46 : L_11 ,
( V_146 & V_151 ) ? L_47 : L_11 ,
( V_146 & V_152 ) ? L_48 : L_11 ,
( V_146 & V_133 ) ? L_49 : L_11 ,
( V_146 & V_153 ) ? L_50 : L_11 ,
( V_146 & V_154 ) ? L_51 : L_11 ) ;
V_146 = V_75 ;
F_66 ( V_143 ,
L_52 , V_146 ,
( V_146 & V_76 ) ? L_53 : L_11 ,
( V_146 & V_97 ) ? L_54 : L_11 ,
( V_146 & V_155 ) ? L_55 : L_11 ,
( V_146 & V_156 ) ? L_56 : L_11 ,
( V_146 & V_132 ) ? L_57 : L_11 ,
( V_146 & V_157 ) ? L_58 : L_11 ,
( V_146 & V_86 ) ? L_59 : L_11 ,
( V_146 & V_77 ) ? L_60 : L_11 ) ;
if ( V_25 -> V_106 ) {
V_146 = V_107 ;
F_66 ( V_143 ,
L_61 , V_146 ,
( V_146 & V_108 ) ? L_62 : L_11 ,
( V_146 & V_109 ) ? L_63 : L_11 ) ;
}
if ( V_25 -> V_40 . V_41 != V_158 || ! V_25 -> V_39 )
goto F_27;
F_66 ( V_143 , L_64 ,
V_25 -> V_83 . V_84 . V_85 , V_25 -> V_83 . V_84 . V_102 ,
V_25 -> V_83 . V_104 . V_85 , V_25 -> V_83 . V_104 . V_102 ,
V_25 -> V_83 . V_159 ) ;
for ( V_123 = 0 ; V_123 < V_160 ; V_123 ++ ) {
struct V_22 * V_23 = & V_25 -> V_23 [ V_123 ] ;
struct V_51 * V_52 ;
if ( V_123 != 0 ) {
const struct V_20 * V_21 ;
V_21 = V_23 -> V_23 . V_21 ;
if ( ! V_21 )
continue;
V_146 = * V_25 -> V_23 [ V_123 ] . V_70 ;
F_66 ( V_143 ,
L_65 ,
V_23 -> V_23 . V_26 , F_12 ( V_21 ) ,
L_66 , V_146 , V_23 -> V_45 ) ;
} else
F_66 ( V_143 , L_67 ,
V_23 -> V_45 ) ;
if ( F_25 ( & V_23 -> V_53 ) ) {
F_66 ( V_143 , L_68 ) ;
continue;
}
F_48 (req, &ep->queue, queue) {
F_66 ( V_143 ,
L_69 ,
& V_52 -> V_52 , V_52 -> V_52 . V_57 ,
V_52 -> V_52 . V_58 , V_52 -> V_52 . V_63 ) ;
}
}
F_27:
F_19 ( V_48 ) ;
return 0 ;
}
static int
F_67 ( struct V_161 * V_161 , struct V_162 * V_162 )
{
return F_68 ( V_162 , F_65 , V_161 -> V_163 ) ;
}
static void F_58 ( struct V_24 * V_25 )
{
F_7 ( V_150 | V_148 ) ;
V_12 = V_13 = 0xff ;
V_130 = V_164 ;
F_1 () ;
F_8 ( V_154 ) ;
F_31 ( V_25 ) ;
V_25 -> V_40 . V_41 = V_42 ;
}
static void F_69 ( struct V_24 * V_25 )
{
T_3 V_123 ;
F_22 ( & V_25 -> V_40 . V_165 ) ;
F_22 ( & V_25 -> V_40 . V_166 -> V_165 ) ;
V_25 -> V_59 = V_60 ;
for ( V_123 = 0 ; V_123 < V_160 ; V_123 ++ ) {
struct V_22 * V_23 = & V_25 -> V_23 [ V_123 ] ;
if ( V_123 != 0 )
F_45 ( & V_23 -> V_23 . V_165 , & V_25 -> V_40 . V_165 ) ;
V_23 -> V_23 . V_21 = NULL ;
V_23 -> V_44 = 0 ;
F_22 ( & V_23 -> V_53 ) ;
V_23 -> V_45 = 0 ;
F_70 ( & V_23 -> V_23 , V_23 -> V_23 . V_46 ) ;
}
}
static void F_56 ( struct V_24 * V_25 )
{
F_8 ( V_154 ) ;
F_9 ( V_151 | V_152 ) ;
F_31 ( V_25 ) ;
V_25 -> V_40 . V_41 = V_42 ;
V_25 -> V_83 . V_159 = 0 ;
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
static int F_71 ( struct V_128 * V_170 ,
struct V_171 * V_39 )
{
struct V_24 * V_25 = F_72 ( V_170 ) ;
int V_172 ;
V_25 -> V_39 = V_39 ;
V_25 -> F_54 = 1 ;
if ( ! F_63 ( V_25 -> V_141 ) ) {
V_172 = F_73 ( V_25 -> V_141 -> V_173 ,
& V_25 -> V_40 ) ;
if ( V_172 )
goto V_174;
}
F_74 ( V_25 ) ;
return 0 ;
V_174:
return V_172 ;
}
static void
F_75 ( struct V_24 * V_25 , struct V_171 * V_39 )
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
F_76 ( & V_25 -> V_175 ) ;
if ( V_39 )
F_77 ( & V_25 -> V_40 , V_39 ) ;
F_69 ( V_25 ) ;
}
static void
F_57 ( struct V_24 * V_25 , struct V_171 * V_39 )
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
F_76 ( & V_25 -> V_175 ) ;
if ( V_39 )
V_39 -> V_176 ( & V_25 -> V_40 ) ;
F_69 ( V_25 ) ;
}
static int F_78 ( struct V_128 * V_170 )
{
struct V_24 * V_25 = F_72 ( V_170 ) ;
F_79 () ;
V_25 -> F_54 = 0 ;
F_57 ( V_25 , NULL ) ;
F_80 () ;
if ( ! F_63 ( V_25 -> V_141 ) )
( void ) F_73 ( V_25 -> V_141 -> V_173 , NULL ) ;
V_25 -> V_39 = NULL ;
F_74 ( V_25 ) ;
return 0 ;
}
static T_5
F_81 ( int V_177 , void * V_178 )
{
struct V_24 * V_25 = V_178 ;
int V_136 ;
V_25 -> V_83 . V_159 ++ ;
switch ( V_177 ) {
case V_179 :
V_136 = 1 ;
F_82 ( V_179 ) ;
F_83 ( V_180 ) ;
break;
case V_180 :
V_136 = 0 ;
F_82 ( V_180 ) ;
F_83 ( V_179 ) ;
break;
default:
return V_181 ;
}
F_60 ( & V_25 -> V_40 , V_136 ) ;
return V_182 ;
}
static inline void F_84 ( struct V_24 * V_25 )
{
unsigned V_123 ;
for ( V_123 = 1 ; V_123 < V_160 ; V_123 ++ )
F_18 ( & V_25 -> V_23 [ V_123 ] , - V_183 ) ;
}
static void F_85 ( unsigned long V_178 )
{
struct V_24 * V_25 = ( void * ) V_178 ;
F_79 () ;
if ( V_25 -> V_59 == V_122
&& ( V_75 & V_155 ) == 0
&& ( V_75 & V_156 ) == 0 ) {
V_75 = V_155 | V_157 ;
F_15 ( V_47 , L_70 ) ;
F_50 ( V_25 ) ;
}
F_80 () ;
}
static void F_86 ( struct V_24 * V_25 )
{
T_3 V_184 = V_75 ;
struct V_22 * V_23 = & V_25 -> V_23 [ 0 ] ;
struct V_51 * V_52 ;
union {
struct V_185 V_186 ;
T_4 V_187 [ 8 ] ;
T_3 V_188 [ 2 ] ;
} V_189 ;
if ( F_25 ( & V_23 -> V_53 ) )
V_52 = NULL ;
else
V_52 = F_46 ( V_23 -> V_53 . V_115 , struct V_51 , V_53 ) ;
if ( V_184 & V_156 ) {
F_18 ( V_23 , - V_190 ) ;
V_75 = V_156 ;
F_87 ( & V_25 -> V_175 ) ;
F_31 ( V_25 ) ;
}
if ( ( V_184 & V_76 ) != 0 && V_25 -> V_59 != V_60 ) {
F_18 ( V_23 , 0 ) ;
F_87 ( & V_25 -> V_175 ) ;
F_31 ( V_25 ) ;
}
switch ( V_25 -> V_59 ) {
case V_60 :
V_184 = V_75 ;
if ( F_29 ( ( V_184 & ( V_77 | V_76 | V_97 ) )
== ( V_77 | V_76 | V_97 ) ) ) {
int V_123 ;
F_18 ( V_23 , - V_191 ) ;
for ( V_123 = 0 ; V_123 < 8 ; V_123 ++ ) {
if ( F_36 ( ! ( V_75 & V_97 ) ) ) {
V_192:
F_13 ( L_71 , V_123 ) ;
goto V_193;
}
V_189 . V_187 [ V_123 ] = ( T_4 ) V_81 ;
}
if ( F_36 ( ( V_75 & V_97 ) != 0 ) )
goto V_192;
V_194:
F_15 ( V_47 , L_72 ,
V_189 . V_186 . V_195 , V_189 . V_186 . V_196 ,
F_88 ( V_189 . V_186 . V_197 ) ,
F_88 ( V_189 . V_186 . V_198 ) ,
F_88 ( V_189 . V_186 . V_199 ) ) ;
V_25 -> V_200 = ( V_189 . V_186 . V_195 & V_201 )
== V_202 ;
V_25 -> V_105 = 0 ;
V_25 -> V_80 = 1 ;
switch ( V_189 . V_186 . V_196 ) {
case V_203 :
if ( V_189 . V_186 . V_195 == V_204 ) {
V_205:
V_25 -> V_105 = 1 ;
F_84 ( V_25 ) ;
}
break;
case V_206 :
if ( V_189 . V_186 . V_195 == V_207 ) {
F_13 ( L_73 ,
F_88 ( V_189 . V_186 . V_198 ) ,
F_88 ( V_189 . V_186 . V_197 ) ) ;
goto V_205;
}
break;
case V_208 :
if ( V_189 . V_186 . V_195 == V_204 ) {
F_37 ( V_25 , 0 , L_74 ) ;
return;
}
break;
}
if ( V_189 . V_186 . V_195 & V_113 )
V_25 -> V_59 = V_101 ;
else
V_25 -> V_59 = V_103 ;
V_123 = V_25 -> V_39 -> V_209 ( & V_25 -> V_40 , & V_189 . V_186 ) ;
if ( V_123 < 0 ) {
if ( V_25 -> V_105 ) {
F_89 ( L_75 ,
V_189 . V_186 . V_196 , V_123 ) ;
return;
}
F_15 ( V_47 , L_76
L_77 , V_75 , V_123 ) ;
V_193:
F_37 ( V_25 , V_155 | V_157 , L_78 ) ;
F_50 ( V_25 ) ;
V_25 -> V_59 = V_122 ;
} else if ( V_25 -> V_80 ) {
if ( F_29 ( V_25 -> V_59 == V_101
|| V_25 -> V_200 || V_189 . V_186 . V_199 ) )
F_37 ( V_25 , 0 , L_79 ) ;
else
F_37 ( V_25 , V_86 , L_80 ) ;
}
return;
} else if ( F_29 ( ( V_184 & ( V_77 | V_76 ) )
== ( V_77 | V_76 ) ) ) {
unsigned V_123 ;
F_15 ( V_47 , L_81 ) ;
F_18 ( V_23 , - V_191 ) ;
for ( V_123 = 0 ; V_123 < 8 ; V_123 ++ )
V_189 . V_187 [ V_123 ] = ( T_4 ) V_81 ;
if ( ( V_189 . V_186 . V_195 & V_210 )
> V_211 )
goto V_193;
if ( V_189 . V_188 [ 0 ] == 0 && V_189 . V_188 [ 1 ] == 0 )
goto V_193;
goto V_194;
} else {
V_75 = V_184 & ( V_76 | V_77 ) ;
}
break;
case V_101 :
if ( V_184 & V_77 ) {
V_75 = V_77 | V_157 ;
F_15 ( V_47 , L_82 ) ;
if ( V_52 )
F_27 ( V_23 , V_52 , 0 ) ;
F_31 ( V_25 ) ;
} else {
if ( V_52 ) {
( void ) F_38 ( V_23 , V_52 ) ;
}
}
break;
case V_103 :
if ( V_184 & V_77 ) {
if ( V_52 ) {
if ( F_43 ( V_23 , V_52 ) )
F_27 ( V_23 , V_52 , 0 ) ;
}
} else {
F_15 ( V_47 , L_83 ) ;
if ( V_52 )
F_27 ( V_23 , V_52 , 0 ) ;
F_31 ( V_25 ) ;
}
break;
case V_111 :
if ( V_52 )
F_27 ( V_23 , V_52 , 0 ) ;
if ( V_184 & V_77 )
V_75 = V_77 ;
F_31 ( V_25 ) ;
break;
case V_122 :
V_75 = V_155 ;
break;
}
V_78 = V_79 ;
}
static void F_90 ( struct V_22 * V_23 )
{
struct V_51 * V_52 ;
int V_212 = V_23 -> V_11 & V_113 ;
int V_213 ;
T_3 V_87 , V_146 ;
do {
V_213 = 0 ;
if ( F_29 ( ! F_25 ( & V_23 -> V_53 ) ) )
V_52 = F_46 ( V_23 -> V_53 . V_115 ,
struct V_51 , V_53 ) ;
else
V_52 = NULL ;
V_87 = * V_23 -> V_70 ;
if ( F_36 ( V_212 ) ) {
V_146 = V_127 ;
if ( F_29 ( V_23 -> V_33 == V_34 ) )
V_146 |= V_124 ;
V_146 &= V_87 ;
if ( F_29 ( V_146 ) )
* V_23 -> V_70 = V_146 ;
if ( V_52 && F_29 ( ( V_87 & V_73 ) != 0 ) )
V_213 = F_35 ( V_23 , V_52 ) ;
} else {
if ( F_29 ( V_23 -> V_33 == V_34 ) )
V_146 = V_214 | V_215 ;
else
V_146 = V_95 | V_216 ;
V_146 &= V_87 ;
if ( F_29 ( V_146 ) )
* V_23 -> V_70 = V_146 ;
if ( F_29 ( V_52 ) ) {
V_213 = F_41 ( V_23 , V_52 ) ;
} else
F_6 ( V_23 -> V_11 ) ;
}
V_23 -> V_45 ++ ;
} while ( V_213 );
}
static T_5
F_91 ( int V_177 , void * V_178 )
{
struct V_24 * V_25 = V_178 ;
int V_217 ;
V_25 -> V_83 . V_159 ++ ;
do {
T_3 V_17 = V_15 ;
V_217 = 0 ;
if ( F_36 ( V_17 & V_151 ) ) {
F_9 ( V_151 ) ;
V_217 = 1 ;
F_15 ( V_47 , L_84 ) ;
if ( V_25 -> V_40 . V_41 != V_42
&& V_25 -> V_39
&& V_25 -> V_39 -> V_218 )
V_25 -> V_39 -> V_218 ( & V_25 -> V_40 ) ;
F_31 ( V_25 ) ;
}
if ( F_36 ( V_17 & V_152 ) ) {
F_9 ( V_152 ) ;
V_217 = 1 ;
F_15 ( V_47 , L_85 ) ;
if ( V_25 -> V_40 . V_41 != V_42
&& V_25 -> V_39
&& V_25 -> V_39 -> V_219 )
V_25 -> V_39 -> V_219 ( & V_25 -> V_40 ) ;
}
if ( F_36 ( V_17 & V_149 ) ) {
F_9 ( V_149 ) ;
V_217 = 1 ;
if ( ( V_15 & V_153 ) == 0 ) {
F_15 ( V_47 , L_86 ) ;
F_75 ( V_25 , V_25 -> V_39 ) ;
} else {
F_15 ( V_47 , L_87 ) ;
V_25 -> V_40 . V_41 = V_158 ;
memset ( & V_25 -> V_83 , 0 , sizeof V_25 -> V_83 ) ;
}
} else {
T_3 V_220 = V_78 & ~ V_12 ;
T_3 V_221 = V_147 & ~ V_13 ;
int V_123 ;
if ( F_36 ( ! V_220 && ! V_221 ) )
continue;
F_15 ( V_69 , L_88 , V_221 , V_220 ) ;
if ( V_220 & V_79 ) {
V_25 -> V_23 [ 0 ] . V_45 ++ ;
F_86 ( V_25 ) ;
V_217 = 1 ;
}
for ( V_123 = 0 ; V_123 < 8 ; V_123 ++ ) {
T_3 V_146 = 1 << V_123 ;
if ( V_123 && ( V_220 & V_146 ) ) {
F_90 ( & V_25 -> V_23 [ V_123 ] ) ;
V_78 |= V_146 ;
V_217 = 1 ;
}
#ifndef F_92
if ( V_221 & V_146 ) {
F_90 ( & V_25 -> V_23 [ V_123 + 8 ] ) ;
V_147 |= V_146 ;
V_217 = 1 ;
}
#endif
}
}
} while ( V_217 );
return V_182 ;
}
static void F_93 ( struct V_222 * V_25 )
{
F_13 ( L_89 , V_31 , F_94 ( V_25 ) ) ;
}
static int F_95 ( struct V_223 * V_224 )
{
struct V_24 * V_25 = & V_225 ;
int V_172 , V_177 ;
T_3 V_226 ;
F_96 ( L_90 , V_227 , V_228 ) ;
asm("mrc%? p15, 0, %0, c0, c0" : "=r" (chiprev));
if ( ( V_226 & V_229 ) != V_230 ) {
F_97 ( L_91 , V_227 ) ;
return - V_125 ;
}
switch ( V_226 & V_231 ) {
#if F_98 ( V_232 )
case V_233 :
V_25 -> V_106 = 1 ;
break;
case V_234 :
case V_235 :
case V_236 : case V_237 :
case V_238 : case V_239 :
case V_240 : case V_241 :
case V_242 : case V_243 :
break;
#elif F_98 ( F_39 )
case V_244 :
case V_245 :
case V_246 :
V_25 -> V_106 = 1 ;
break;
#endif
default:
F_97 ( L_92 ,
V_227 , V_226 ) ;
return - V_125 ;
}
V_177 = F_99 ( V_224 , 0 ) ;
if ( V_177 < 0 )
return - V_125 ;
V_25 -> V_139 = F_100 ( & V_224 -> V_25 , NULL ) ;
if ( F_101 ( V_25 -> V_139 ) )
return F_102 ( V_25 -> V_139 ) ;
F_103 ( L_93 , V_227 , V_177 ,
V_25 -> V_106 ? L_11 : L_94 ,
V_247 L_38
) ;
V_25 -> V_25 = & V_224 -> V_25 ;
V_25 -> V_2 = F_104 ( & V_224 -> V_25 ) ;
V_25 -> V_141 = F_105 ( & V_224 -> V_25 , V_248 ) ;
if ( F_2 ( V_25 -> V_2 -> V_6 ) ) {
V_172 = F_106 ( & V_224 -> V_25 , V_25 -> V_2 -> V_6 ,
L_95 ) ;
if ( V_172 ) {
F_107 ( & V_224 -> V_25 ,
L_96 ,
V_25 -> V_2 -> V_6 , V_172 ) ;
goto V_249;
}
F_108 ( V_25 -> V_2 -> V_6 , 0 ) ;
}
F_109 ( & V_25 -> V_175 ) ;
V_25 -> V_175 . V_250 = F_85 ;
V_25 -> V_175 . V_251 = ( unsigned long ) V_25 ;
V_3 = V_25 ;
F_110 ( V_224 , V_25 ) ;
F_58 ( V_25 ) ;
F_69 ( V_25 ) ;
V_25 -> V_136 = 0 ;
V_172 = F_111 ( & V_224 -> V_25 , V_177 , F_91 , 0 ,
V_227 , V_25 ) ;
if ( V_172 != 0 ) {
F_97 ( L_97 ,
V_227 , V_177 , V_172 ) ;
goto V_249;
}
V_25 -> V_252 = 1 ;
#ifdef F_112
if ( F_113 () ) {
V_172 = F_111 ( & V_224 -> V_25 , V_180 ,
F_81 , 0 , V_227 ,
V_25 ) ;
if ( V_172 != 0 ) {
F_97 ( L_98 ,
V_227 , V_180 , V_172 ) ;
goto V_249;
}
V_172 = F_111 ( & V_224 -> V_25 , V_179 ,
F_81 , 0 , V_227 ,
V_25 ) ;
if ( V_172 != 0 ) {
F_97 ( L_98 ,
V_227 , V_179 , V_172 ) ;
goto V_249;
}
} else
#endif
F_114 ( V_25 ) ;
V_172 = F_115 ( & V_224 -> V_25 , & V_25 -> V_40 ) ;
if ( ! V_172 )
return V_172 ;
F_116 ( V_25 ) ;
V_249:
if ( ! F_63 ( V_25 -> V_141 ) )
V_25 -> V_141 = NULL ;
return V_172 ;
}
static void F_117 ( struct V_223 * V_178 )
{
F_1 () ;
}
static int F_118 ( struct V_223 * V_224 )
{
struct V_24 * V_25 = F_119 ( V_224 ) ;
if ( V_25 -> V_39 )
return - V_253 ;
F_120 ( & V_25 -> V_40 ) ;
V_25 -> F_54 = 0 ;
F_54 ( V_25 ) ;
F_116 ( V_25 ) ;
if ( ! F_63 ( V_25 -> V_141 ) )
V_25 -> V_141 = NULL ;
V_3 = NULL ;
return 0 ;
}
static int F_121 ( struct V_223 * V_25 , T_6 V_254 )
{
struct V_24 * V_134 = F_119 ( V_25 ) ;
unsigned long V_48 ;
if ( ! F_2 ( V_134 -> V_2 -> V_6 ) && ! V_134 -> V_2 -> V_7 )
F_89 ( L_99 ) ;
V_134 -> V_137 = 1 ;
F_17 ( V_48 ) ;
F_54 ( V_134 ) ;
F_19 ( V_48 ) ;
return 0 ;
}
static int F_122 ( struct V_223 * V_25 )
{
struct V_24 * V_134 = F_119 ( V_25 ) ;
unsigned long V_48 ;
V_134 -> V_137 = 0 ;
F_17 ( V_48 ) ;
F_54 ( V_134 ) ;
F_19 ( V_48 ) ;
return 0 ;
}
