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
static inline void F_5 ( struct V_11 * V_12 , T_1 V_13 , T_1 V_14 )
{
F_6 ( V_14 , V_12 -> V_15 + V_13 ) ;
}
static inline T_1 F_7 ( struct V_11 * V_12 , T_1 V_13 )
{
return F_8 ( V_12 -> V_15 + V_13 ) ;
}
static inline void F_5 ( struct V_11 * V_12 , T_1 V_13 , T_1 V_14 )
{
F_9 ( V_14 , V_12 -> V_15 + V_13 ) ;
}
static inline T_1 F_7 ( struct V_11 * V_12 , T_1 V_13 )
{
return F_10 ( V_12 -> V_15 + V_13 ) ;
}
static void F_11 ( struct V_16 * V_17 )
{
T_1 V_18 = V_17 -> V_18 & 0xf ;
if ( V_18 < 8 )
F_5 ( V_17 -> V_12 , V_19 , F_7 ( V_17 -> V_12 , V_19 ) &
~ ( 1 << V_18 ) ) ;
else {
V_18 -= 8 ;
F_5 ( V_17 -> V_12 , V_20 , F_7 ( V_17 -> V_12 , V_20 ) &
~ ( 1 << V_18 ) ) ;
}
}
static void F_12 ( struct V_16 * V_17 )
{
T_1 V_18 = V_17 -> V_18 & 0xf ;
if ( V_18 < 8 )
F_5 ( V_17 -> V_12 , V_19 , F_7 ( V_17 -> V_12 , V_19 ) |
( 1 << V_18 ) ) ;
else {
V_18 -= 8 ;
F_5 ( V_17 -> V_12 , V_20 , F_7 ( V_17 -> V_12 , V_20 ) |
( 1 << V_18 ) ) ;
}
}
static inline void F_13 ( struct V_11 * V_12 , int V_21 )
{
T_1 V_22 = F_7 ( V_12 , V_23 ) ;
F_5 ( V_12 , ( V_22 & V_24 ) | ( V_21 & V_24 ) , V_23 ) ;
}
static inline void F_14 ( struct V_11 * V_12 , int V_21 )
{
T_1 V_22 = F_7 ( V_12 , V_23 ) ;
F_5 ( V_12 , ( V_22 & V_24 ) & ~ ( V_21 & V_24 ) , V_23 ) ;
}
static inline void F_15 ( struct V_11 * V_12 , int V_21 )
{
T_1 V_22 = F_7 ( V_12 , V_23 ) & V_24 ;
F_5 ( V_12 , V_22 | ( V_21 & ~ V_24 ) , V_23 ) ;
}
static inline T_1 F_16 ( struct V_16 * V_17 )
{
return F_7 ( V_17 -> V_12 , V_17 -> V_25 ) ;
}
static inline void F_17 ( struct V_16 * V_17 , T_1 V_26 )
{
F_5 ( V_17 -> V_12 , V_26 , V_17 -> V_25 ) ;
}
static inline T_1 F_18 ( struct V_11 * V_12 )
{
return F_7 ( V_12 , V_27 ) ;
}
static inline void F_19 ( struct V_11 * V_12 , T_1 V_26 )
{
F_5 ( V_12 , V_26 , V_27 ) ;
}
static inline T_1 F_20 ( struct V_16 * V_17 )
{
return F_7 ( V_17 -> V_12 , V_17 -> V_28 ) ;
}
static inline void F_21 ( struct V_16 * V_17 , T_1 V_26 )
{
F_5 ( V_17 -> V_12 , V_26 , V_17 -> V_28 ) ;
}
static inline T_1 F_22 ( struct V_16 * V_17 )
{
return F_7 ( V_17 -> V_12 , V_17 -> V_29 ) ;
}
static int F_23 ( struct V_30 * V_31 ,
const struct V_32 * V_33 )
{
struct V_16 * V_17 ;
struct V_11 * V_12 ;
V_17 = F_24 ( V_31 , struct V_16 , V_17 ) ;
if ( ! V_31 || ! V_33 || V_31 -> V_34 == V_35
|| V_33 -> V_36 != V_37
|| V_17 -> V_18 != V_33 -> V_18
|| V_17 -> V_38 < F_25 ( V_33 ) ) {
F_26 ( L_1 , V_39 ) ;
return - V_40 ;
}
if ( V_17 -> V_41 != V_33 -> V_41
&& V_17 -> V_41 != V_42
&& V_33 -> V_41 != V_43 ) {
F_26 ( L_2 , V_39 , V_31 -> V_34 ) ;
return - V_40 ;
}
if ( ( V_33 -> V_41 == V_42
&& F_25 ( V_33 )
!= V_44 )
|| ! V_33 -> V_45 ) {
F_26 ( L_3 , V_39 , V_31 -> V_34 ) ;
return - V_46 ;
}
V_12 = V_17 -> V_12 ;
if ( ! V_12 -> V_47 || V_12 -> V_48 . V_49 == V_50 ) {
F_26 ( L_4 , V_39 ) ;
return - V_51 ;
}
V_17 -> V_17 . V_33 = V_33 ;
V_17 -> V_52 = 0 ;
V_17 -> V_53 = 0 ;
V_17 -> V_17 . V_54 = F_25 ( V_33 ) ;
F_27 ( V_31 ) ;
F_28 ( V_55 , L_5 , V_31 -> V_34 ) ;
return 0 ;
}
static int F_29 ( struct V_30 * V_31 )
{
struct V_16 * V_17 ;
unsigned long V_56 ;
V_17 = F_24 ( V_31 , struct V_16 , V_17 ) ;
if ( ! V_31 || ! V_17 -> V_17 . V_33 ) {
F_26 ( L_6 , V_39 ,
V_31 ? V_17 -> V_17 . V_34 : NULL ) ;
return - V_40 ;
}
F_30 ( V_56 ) ;
F_31 ( V_17 , - V_51 ) ;
F_27 ( V_31 ) ;
V_17 -> V_17 . V_33 = NULL ;
V_17 -> V_52 = 1 ;
F_32 ( V_56 ) ;
F_28 ( V_55 , L_7 , V_31 -> V_34 ) ;
return 0 ;
}
static struct V_57 *
F_33 ( struct V_30 * V_31 , T_2 V_58 )
{
struct V_59 * V_60 ;
V_60 = F_34 ( sizeof( * V_60 ) , V_58 ) ;
if ( ! V_60 )
return NULL ;
F_35 ( & V_60 -> V_61 ) ;
return & V_60 -> V_60 ;
}
static void
F_36 ( struct V_30 * V_31 , struct V_57 * V_62 )
{
struct V_59 * V_60 ;
V_60 = F_24 ( V_62 , struct V_59 , V_60 ) ;
F_37 ( ! F_38 ( & V_60 -> V_61 ) ) ;
F_39 ( V_60 ) ;
}
static void F_40 ( struct V_16 * V_17 , struct V_59 * V_60 , int V_63 )
{
unsigned V_52 = V_17 -> V_52 ;
F_41 ( & V_60 -> V_61 ) ;
if ( F_42 ( V_60 -> V_60 . V_63 == - V_64 ) )
V_60 -> V_60 . V_63 = V_63 ;
else
V_63 = V_60 -> V_60 . V_63 ;
if ( V_63 && V_63 != - V_51 )
F_28 ( V_55 , L_8 ,
V_17 -> V_17 . V_34 , & V_60 -> V_60 , V_63 ,
V_60 -> V_60 . V_65 , V_60 -> V_60 . V_66 ) ;
V_17 -> V_52 = 1 ;
F_43 ( & V_17 -> V_17 , & V_60 -> V_60 ) ;
V_17 -> V_52 = V_52 ;
}
static inline void F_44 ( struct V_11 * V_12 )
{
V_12 -> V_67 = V_68 ;
}
static int
F_45 ( struct V_16 * V_17 , struct V_59 * V_60 , unsigned V_69 )
{
T_3 * V_70 ;
unsigned V_66 , V_71 ;
V_70 = V_60 -> V_60 . V_70 + V_60 -> V_60 . V_65 ;
F_46 ( V_70 ) ;
V_66 = F_47 ( V_60 -> V_60 . V_66 - V_60 -> V_60 . V_65 , V_69 ) ;
V_60 -> V_60 . V_65 += V_66 ;
V_71 = V_66 ;
while ( F_42 ( V_71 -- ) )
F_21 ( V_17 , * V_70 ++ ) ;
return V_66 ;
}
static int
F_48 ( struct V_16 * V_17 , struct V_59 * V_60 )
{
unsigned V_69 ;
V_69 = F_25 ( V_17 -> V_17 . V_33 ) ;
do {
unsigned V_71 ;
int V_72 , V_73 ;
V_71 = F_45 ( V_17 , V_60 , V_69 ) ;
if ( F_49 ( V_71 != V_69 ) )
V_72 = V_73 = 1 ;
else {
if ( F_42 ( V_60 -> V_60 . V_66 != V_60 -> V_60 . V_65 )
|| V_60 -> V_60 . V_74 )
V_72 = 0 ;
else
V_72 = 1 ;
V_73 = F_49 ( V_69 < V_17 -> V_38 ) ;
}
F_28 ( V_75 , L_9 ,
V_17 -> V_17 . V_34 , V_71 ,
V_72 ? L_10 : L_11 , V_73 ? L_12 : L_11 ,
V_60 -> V_60 . V_66 - V_60 -> V_60 . V_65 , V_60 ) ;
F_17 ( V_17 , V_76 ) ;
if ( V_73 )
F_17 ( V_17 , V_77 ) ;
if ( V_72 ) {
F_40 ( V_17 , V_60 , 0 ) ;
if ( F_38 ( & V_17 -> V_61 ) )
F_12 ( V_17 ) ;
return 1 ;
}
} while ( F_16 ( V_17 ) & V_78 );
return 0 ;
}
static inline
void F_50 ( struct V_11 * V_12 , T_1 V_56 , const char * V_79 )
{
F_19 ( V_12 , V_56 | V_80 | V_81 ) ;
F_5 ( V_12 , V_82 , V_83 ) ;
V_12 -> V_84 = 0 ;
F_28 ( V_75 , L_13 ,
V_39 , V_79 , F_18 ( V_12 ) , V_56 ) ;
}
static int
F_51 ( struct V_16 * V_17 , struct V_59 * V_60 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
unsigned V_71 ;
int V_73 ;
V_71 = F_45 ( & V_12 -> V_17 [ 0 ] , V_60 , V_85 ) ;
V_17 -> V_12 -> V_86 . V_87 . V_88 += V_71 ;
V_73 = ( V_71 != V_85 ) ;
F_28 ( V_75 , L_14 , V_71 ,
V_60 -> V_60 . V_66 - V_60 -> V_60 . V_65 , V_60 ) ;
if ( F_49 ( V_73 ) ) {
if ( V_17 -> V_12 -> V_84 )
F_50 ( V_17 -> V_12 , V_89 , L_15 ) ;
else
F_19 ( V_12 , V_89 ) ;
V_71 = V_60 -> V_60 . V_66 ;
F_40 ( V_17 , V_60 , 0 ) ;
F_44 ( V_17 -> V_12 ) ;
#ifndef F_52
#if 1
if ( V_71 >= V_85 ) {
V_71 = 100 ;
do {
if ( ( F_18 ( V_12 ) & V_81 ) != 0 ) {
F_19 ( V_12 , V_81 ) ;
break;
}
V_71 -- ;
F_53 ( 1 ) ;
} while ( V_71 );
}
#endif
#endif
} else if ( V_17 -> V_12 -> V_84 )
F_50 ( V_17 -> V_12 , 0 , L_16 ) ;
return V_73 ;
}
static int
F_54 ( struct V_16 * V_17 , struct V_59 * V_60 )
{
for (; ; ) {
T_1 V_90 ;
T_3 * V_70 ;
unsigned V_91 , V_71 , V_73 ;
V_90 = F_16 ( V_17 ) ;
if ( F_49 ( ( V_90 & V_92 ) == 0 ) )
break;
V_70 = V_60 -> V_60 . V_70 + V_60 -> V_60 . V_65 ;
F_55 ( V_70 ) ;
V_91 = V_60 -> V_60 . V_66 - V_60 -> V_60 . V_65 ;
if ( F_42 ( V_90 & V_93 ) ) {
V_71 = 1 + ( 0x0ff & F_22 ( V_17 ) ) ;
V_60 -> V_60 . V_65 += F_47 ( V_71 , V_91 ) ;
} else
V_71 = 0 ;
V_73 = ( V_71 < V_17 -> V_17 . V_54 ) ;
F_28 ( V_75 , L_17 ,
V_17 -> V_17 . V_34 , V_90 , V_71 ,
V_73 ? L_12 : L_11 ,
V_60 , V_60 -> V_60 . V_65 , V_60 -> V_60 . V_66 ) ;
while ( F_42 ( V_71 -- != 0 ) ) {
T_3 V_94 = ( T_3 ) F_20 ( V_17 ) ;
if ( F_49 ( V_91 == 0 ) ) {
if ( V_60 -> V_60 . V_63 != - V_95 )
F_26 ( L_18 ,
V_17 -> V_17 . V_34 , V_71 ) ;
V_60 -> V_60 . V_63 = - V_95 ;
} else {
* V_70 ++ = V_94 ;
V_91 -- ;
}
}
F_17 ( V_17 , V_92 ) ;
if ( V_17 -> V_41 == V_96 ) {
if ( V_90 & V_97 )
V_60 -> V_60 . V_63 = - V_98 ;
V_73 = 1 ;
}
if ( V_73 || V_60 -> V_60 . V_65 == V_60 -> V_60 . V_66 ) {
F_40 ( V_17 , V_60 , 0 ) ;
if ( F_38 ( & V_17 -> V_61 ) )
F_12 ( V_17 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_56 ( struct V_16 * V_17 , struct V_59 * V_60 )
{
T_3 * V_70 , V_94 ;
unsigned V_91 ;
V_70 = V_60 -> V_60 . V_70 + V_60 -> V_60 . V_65 ;
V_91 = V_60 -> V_60 . V_66 - V_60 -> V_60 . V_65 ;
while ( F_16 ( V_17 ) & V_99 ) {
V_94 = ( T_3 ) V_100 ;
if ( F_49 ( V_91 == 0 ) ) {
if ( V_60 -> V_60 . V_63 != - V_95 )
F_26 ( L_19 , V_17 -> V_17 . V_34 ) ;
V_60 -> V_60 . V_63 = - V_95 ;
} else {
* V_70 ++ = V_94 ;
V_60 -> V_60 . V_65 ++ ;
V_91 -- ;
}
}
F_17 ( V_17 , V_81 | V_89 ) ;
if ( V_60 -> V_60 . V_65 >= V_60 -> V_60 . V_66 )
return 1 ;
return 0 ;
}
static int
F_57 ( struct V_30 * V_31 , struct V_57 * V_62 , T_2 V_58 )
{
struct V_59 * V_60 ;
struct V_16 * V_17 ;
struct V_11 * V_12 ;
unsigned long V_56 ;
V_60 = F_24 ( V_62 , struct V_59 , V_60 ) ;
if ( F_49 ( ! V_62 || ! V_62 -> V_101 || ! V_62 -> V_70
|| ! F_38 ( & V_60 -> V_61 ) ) ) {
F_26 ( L_20 , V_39 ) ;
return - V_40 ;
}
V_17 = F_24 ( V_31 , struct V_16 , V_17 ) ;
if ( F_49 ( ! V_31 || ( ! V_17 -> V_17 . V_33 && V_17 -> V_17 . V_34 != V_35 ) ) ) {
F_26 ( L_21 , V_39 ) ;
return - V_40 ;
}
V_12 = V_17 -> V_12 ;
if ( F_49 ( ! V_12 -> V_47
|| V_12 -> V_48 . V_49 == V_50 ) ) {
F_26 ( L_4 , V_39 ) ;
return - V_51 ;
}
if ( F_49 ( V_17 -> V_41 == V_96
&& V_60 -> V_60 . V_66 > F_25 ( V_17 -> V_17 . V_33 ) ) )
return - V_102 ;
F_28 ( V_103 , L_22 ,
V_31 -> V_34 , V_62 , V_62 -> V_66 , V_62 -> V_70 ) ;
F_30 ( V_56 ) ;
V_62 -> V_63 = - V_64 ;
V_62 -> V_65 = 0 ;
if ( F_38 ( & V_17 -> V_61 ) && ! V_17 -> V_52 ) {
if ( V_17 -> V_17 . V_33 == NULL ) {
unsigned V_66 = V_62 -> V_66 ;
switch ( V_12 -> V_67 ) {
case V_104 :
V_12 -> V_86 . V_87 . V_105 ++ ;
if ( F_51 ( V_17 , V_60 ) )
V_60 = NULL ;
break;
case V_106 :
V_12 -> V_86 . V_107 . V_105 ++ ;
if ( V_12 -> V_108 ) {
F_28 ( V_55 , L_23 ,
V_12 -> V_109 ? L_11 : L_24 ) ;
if ( V_12 -> V_109 )
F_5 ( V_12 , V_110 , V_111 |
V_112 | V_113 ) ;
F_40 ( V_17 , V_60 , 0 ) ;
V_12 -> V_67 = V_114 ;
F_32 ( V_56 ) ;
return 0 ;
}
if ( V_12 -> V_84 )
F_50 ( V_12 , V_89 , L_25 ) ;
if ( V_66 == 0 || ( ( F_18 ( V_12 ) & V_99 ) != 0
&& F_56 ( V_17 , V_60 ) ) ) {
F_44 ( V_12 ) ;
F_40 ( V_17 , V_60 , 0 ) ;
V_60 = NULL ;
}
break;
default:
F_26 ( L_26 , V_12 -> V_67 ) ;
F_32 ( V_56 ) ;
return - V_115 ;
}
} else if ( ( V_17 -> V_18 & V_116 ) != 0 ) {
if ( ( F_16 ( V_17 ) & V_78 ) != 0
&& F_48 ( V_17 , V_60 ) )
V_60 = NULL ;
} else if ( ( F_16 ( V_17 ) & V_117 ) != 0
&& F_54 ( V_17 , V_60 ) ) {
V_60 = NULL ;
}
if ( F_42 ( V_60 && V_17 -> V_17 . V_33 ) )
F_11 ( V_17 ) ;
}
if ( F_42 ( V_60 != NULL ) )
F_58 ( & V_60 -> V_61 , & V_17 -> V_61 ) ;
F_32 ( V_56 ) ;
return 0 ;
}
static void F_31 ( struct V_16 * V_17 , int V_63 )
{
struct V_59 * V_60 ;
while ( ! F_38 ( & V_17 -> V_61 ) ) {
V_60 = F_59 ( V_17 -> V_61 . V_118 ,
struct V_59 ,
V_61 ) ;
F_40 ( V_17 , V_60 , V_63 ) ;
}
if ( V_17 -> V_17 . V_33 )
F_12 ( V_17 ) ;
}
static int F_60 ( struct V_30 * V_31 , struct V_57 * V_62 )
{
struct V_16 * V_17 ;
struct V_59 * V_60 ;
unsigned long V_56 ;
V_17 = F_24 ( V_31 , struct V_16 , V_17 ) ;
if ( ! V_31 || V_17 -> V_17 . V_34 == V_35 )
return - V_40 ;
F_30 ( V_56 ) ;
F_61 (req, &ep->queue, queue) {
if ( & V_60 -> V_60 == V_62 )
break;
}
if ( & V_60 -> V_60 != V_62 ) {
F_32 ( V_56 ) ;
return - V_40 ;
}
F_40 ( V_17 , V_60 , - V_119 ) ;
F_32 ( V_56 ) ;
return 0 ;
}
static int F_62 ( struct V_30 * V_31 , int V_120 )
{
struct V_16 * V_17 ;
unsigned long V_56 ;
V_17 = F_24 ( V_31 , struct V_16 , V_17 ) ;
if ( F_49 ( ! V_31
|| ( ! V_17 -> V_17 . V_33 && V_17 -> V_17 . V_34 != V_35 ) )
|| V_17 -> V_41 == V_96 ) {
F_26 ( L_21 , V_39 ) ;
return - V_40 ;
}
if ( V_120 == 0 ) {
F_26 ( L_27 , V_31 -> V_34 ) ;
return - V_121 ;
}
F_30 ( V_56 ) ;
if ( ( V_17 -> V_18 & V_116 ) != 0
&& ( ( F_16 ( V_17 ) & V_78 ) == 0
|| ! F_38 ( & V_17 -> V_61 ) ) ) {
F_32 ( V_56 ) ;
return - V_122 ;
}
F_17 ( V_17 , V_123 | V_124 ) ;
if ( ! V_17 -> V_17 . V_33 ) {
F_63 ( V_17 -> V_12 ) ;
V_17 -> V_12 -> V_84 = 0 ;
V_17 -> V_12 -> V_67 = V_125 ;
} else {
unsigned V_126 ;
for ( V_126 = 0 ; V_126 < 1000 ; V_126 += 20 ) {
if ( F_16 ( V_17 ) & V_127 )
break;
F_53 ( 20 ) ;
}
}
F_32 ( V_56 ) ;
F_28 ( V_55 , L_28 , V_31 -> V_34 ) ;
return 0 ;
}
static int F_64 ( struct V_30 * V_31 )
{
struct V_16 * V_17 ;
V_17 = F_24 ( V_31 , struct V_16 , V_17 ) ;
if ( ! V_31 ) {
F_26 ( L_21 , V_39 ) ;
return - V_128 ;
}
if ( ( V_17 -> V_18 & V_116 ) != 0 )
return - V_129 ;
if ( V_17 -> V_12 -> V_48 . V_49 == V_50
|| ( F_16 ( V_17 ) & V_117 ) == 0 )
return 0 ;
else
return ( F_22 ( V_17 ) & 0xfff ) + 1 ;
}
static void F_27 ( struct V_30 * V_31 )
{
struct V_16 * V_17 ;
V_17 = F_24 ( V_31 , struct V_16 , V_17 ) ;
if ( ! V_31 || V_17 -> V_17 . V_34 == V_35 || ! F_38 ( & V_17 -> V_61 ) ) {
F_26 ( L_21 , V_39 ) ;
return;
}
if ( ( V_17 -> V_18 & V_116 ) == 0 ) {
while ( ( ( F_16 ( V_17 ) ) & V_93 ) != 0 )
( void ) F_20 ( V_17 ) ;
return;
}
F_17 ( V_17 , V_76 | V_124 | V_130
| ( V_17 -> V_41 == V_96
? 0 : V_127 ) ) ;
}
static int F_65 ( struct V_131 * V_132 )
{
struct V_11 * V_12 ;
V_12 = F_24 ( V_132 , struct V_11 , V_48 ) ;
return ( ( F_7 ( V_12 , V_133 ) & 0x07 ) << 8 ) |
( F_7 ( V_12 , V_134 ) & 0xff ) ;
}
static int F_66 ( struct V_131 * V_132 )
{
struct V_11 * V_135 ;
V_135 = F_24 ( V_132 , struct V_11 , V_48 ) ;
if ( ( F_18 ( V_135 ) & V_136 ) == 0 )
return - V_98 ;
F_13 ( V_135 , V_137 ) ;
return 0 ;
}
static int F_67 ( struct V_11 * V_135 )
{
int V_138 = V_135 -> V_139 && V_135 -> F_67 && ! V_135 -> V_140 ;
F_26 ( L_29 , V_138 ? L_30 : L_31 ) ;
if ( V_138 ) {
if ( ! V_135 -> V_141 ) {
V_135 -> V_141 = 1 ;
F_68 ( V_135 -> V_142 ) ;
F_69 ( V_135 ) ;
}
} else {
if ( V_135 -> V_141 ) {
if ( V_135 -> V_48 . V_49 != V_50 ) {
F_26 ( L_32 , V_135 -> V_47
? V_135 -> V_47 -> V_47 . V_34
: L_33 ) ;
F_70 ( V_135 , V_135 -> V_47 ) ;
}
F_71 ( V_135 ) ;
F_72 ( V_135 -> V_142 ) ;
V_135 -> V_141 = 0 ;
}
}
return 0 ;
}
static int F_73 ( struct V_131 * V_132 , int V_138 )
{
struct V_11 * V_135 ;
V_135 = F_24 ( V_132 , struct V_11 , V_48 ) ;
V_135 -> V_139 = V_138 ;
F_26 ( L_34 , V_138 ? L_35 : L_31 ) ;
F_67 ( V_135 ) ;
return 0 ;
}
static int F_74 ( struct V_131 * V_132 , int V_138 )
{
struct V_11 * V_135 ;
V_135 = F_24 ( V_132 , struct V_11 , V_48 ) ;
if ( ! F_2 ( V_135 -> V_2 -> V_6 ) && ! V_135 -> V_2 -> V_7 )
return - V_129 ;
V_135 -> F_67 = ( V_138 != 0 ) ;
F_67 ( V_135 ) ;
return 0 ;
}
static int F_75 ( struct V_131 * V_132 , unsigned V_143 )
{
struct V_11 * V_135 ;
V_135 = F_24 ( V_132 , struct V_11 , V_48 ) ;
if ( ! F_76 ( V_135 -> V_144 ) )
return F_77 ( V_135 -> V_144 , V_143 ) ;
return - V_129 ;
}
static int
F_78 ( struct V_145 * V_146 , void * V_147 )
{
struct V_11 * V_12 = V_146 -> V_148 ;
unsigned long V_56 ;
int V_126 ;
T_1 V_149 ;
F_30 ( V_56 ) ;
F_79 (m, DRIVER_DESC L_36
L_37 ,
driver_name, DRIVER_VERSION SIZE_STR L_38 ,
dev->driver ? dev->driver->driver.name : L_39 ,
dev->gadget.speed == USB_SPEED_FULL ? L_40 : L_41 ) ;
F_79 ( V_146 ,
L_42 ,
F_7 ( V_12 , V_20 ) , F_7 ( V_12 , V_19 ) ,
F_7 ( V_12 , V_150 ) , F_7 ( V_12 , V_82 ) ,
F_7 ( V_12 , V_133 ) , F_7 ( V_12 , V_134 ) ) ;
V_149 = F_7 ( V_12 , V_23 ) ;
F_79 ( V_146 ,
L_43 , V_149 ,
( V_149 & V_151 ) ? L_44 : L_11 ,
( V_149 & V_152 ) ? L_45 : L_11 ,
( V_149 & V_153 ) ? L_46 : L_11 ,
( V_149 & V_154 ) ? L_47 : L_11 ,
( V_149 & V_155 ) ? L_48 : L_11 ,
( V_149 & V_137 ) ? L_49 : L_11 ,
( V_149 & V_156 ) ? L_50 : L_11 ,
( V_149 & V_157 ) ? L_51 : L_11 ) ;
V_149 = F_18 ( V_12 ) ;
F_79 ( V_146 ,
L_52 , V_149 ,
( V_149 & V_80 ) ? L_53 : L_11 ,
( V_149 & V_99 ) ? L_54 : L_11 ,
( V_149 & V_158 ) ? L_55 : L_11 ,
( V_149 & V_159 ) ? L_56 : L_11 ,
( V_149 & V_136 ) ? L_57 : L_11 ,
( V_149 & V_160 ) ? L_58 : L_11 ,
( V_149 & V_89 ) ? L_59 : L_11 ,
( V_149 & V_81 ) ? L_60 : L_11 ) ;
if ( V_12 -> V_109 ) {
V_149 = F_7 ( V_12 , V_110 ) ;
F_79 ( V_146 ,
L_61 , V_149 ,
( V_149 & V_111 ) ? L_62 : L_11 ,
( V_149 & V_112 ) ? L_63 : L_11 ) ;
}
if ( V_12 -> V_48 . V_49 != V_161 || ! V_12 -> V_47 )
goto F_40;
F_79 ( V_146 , L_64 ,
V_12 -> V_86 . V_87 . V_88 , V_12 -> V_86 . V_87 . V_105 ,
V_12 -> V_86 . V_107 . V_88 , V_12 -> V_86 . V_107 . V_105 ,
V_12 -> V_86 . V_162 ) ;
for ( V_126 = 0 ; V_126 < V_163 ; V_126 ++ ) {
struct V_16 * V_17 = & V_12 -> V_17 [ V_126 ] ;
struct V_59 * V_60 ;
if ( V_126 != 0 ) {
const struct V_32 * V_33 ;
V_33 = V_17 -> V_17 . V_33 ;
if ( ! V_33 )
continue;
V_149 = F_16 ( & V_12 -> V_17 [ V_126 ] ) ;
F_79 ( V_146 ,
L_65 ,
V_17 -> V_17 . V_34 , F_25 ( V_33 ) ,
L_66 , V_149 , V_17 -> V_53 ) ;
} else
F_79 ( V_146 , L_67 ,
V_17 -> V_53 ) ;
if ( F_38 ( & V_17 -> V_61 ) ) {
F_79 ( V_146 , L_68 ) ;
continue;
}
F_61 (req, &ep->queue, queue) {
F_79 ( V_146 ,
L_69 ,
& V_60 -> V_60 , V_60 -> V_60 . V_65 ,
V_60 -> V_60 . V_66 , V_60 -> V_60 . V_70 ) ;
}
}
F_40:
F_32 ( V_56 ) ;
return 0 ;
}
static int
F_80 ( struct V_164 * V_164 , struct V_165 * V_165 )
{
return F_81 ( V_165 , F_78 , V_164 -> V_166 ) ;
}
static void F_71 ( struct V_11 * V_12 )
{
F_13 ( V_12 , V_153 | V_151 ) ;
F_5 ( V_12 , V_19 , 0xff ) ;
F_5 ( V_12 , V_20 , 0xff ) ;
F_5 ( V_12 , V_133 , V_167 ) ;
F_1 () ;
F_14 ( V_12 , V_157 ) ;
F_44 ( V_12 ) ;
V_12 -> V_48 . V_49 = V_50 ;
}
static void F_82 ( struct V_11 * V_12 )
{
T_1 V_126 ;
F_35 ( & V_12 -> V_48 . V_168 ) ;
F_35 ( & V_12 -> V_48 . V_169 -> V_168 ) ;
V_12 -> V_67 = V_68 ;
V_12 -> V_48 . V_170 = 1 ;
for ( V_126 = 0 ; V_126 < V_163 ; V_126 ++ ) {
struct V_16 * V_17 = & V_12 -> V_17 [ V_126 ] ;
if ( V_126 != 0 )
F_58 ( & V_17 -> V_17 . V_168 , & V_12 -> V_48 . V_168 ) ;
V_17 -> V_17 . V_33 = NULL ;
V_17 -> V_52 = 0 ;
F_35 ( & V_17 -> V_61 ) ;
V_17 -> V_53 = 0 ;
F_83 ( & V_17 -> V_17 , V_17 -> V_17 . V_54 ) ;
}
}
static void F_69 ( struct V_11 * V_12 )
{
F_14 ( V_12 , V_157 ) ;
F_15 ( V_12 , V_154 | V_155 ) ;
F_44 ( V_12 ) ;
V_12 -> V_48 . V_49 = V_50 ;
V_12 -> V_86 . V_162 = 0 ;
F_13 ( V_12 , V_157 ) ;
if ( ! ( F_7 ( V_12 , V_23 ) & V_156 ) )
F_15 ( V_12 , V_152 ) ;
if ( V_12 -> V_109 ) {
F_5 ( V_12 , V_110 , V_112 | V_113 ) ;
} else {
F_5 ( V_12 , V_171 , 0x00 ) ;
F_5 ( V_12 , V_172 , 0x00 ) ;
}
F_14 ( V_12 , V_153 | V_151 ) ;
F_5 ( V_12 , V_19 , F_7 ( V_12 , V_19 ) & ~ V_173 ) ;
F_4 () ;
}
static int F_84 ( struct V_131 * V_174 ,
struct V_175 * V_47 )
{
struct V_11 * V_12 = F_85 ( V_174 ) ;
int V_176 ;
V_12 -> V_47 = V_47 ;
V_12 -> F_67 = 1 ;
if ( ! F_76 ( V_12 -> V_144 ) ) {
V_176 = F_86 ( V_12 -> V_144 -> V_177 ,
& V_12 -> V_48 ) ;
if ( V_176 )
goto V_178;
}
F_87 ( V_12 ) ;
return 0 ;
V_178:
return V_176 ;
}
static void
F_88 ( struct V_11 * V_12 , struct V_175 * V_47 )
{
int V_126 ;
if ( V_12 -> V_48 . V_49 == V_50 )
V_47 = NULL ;
V_12 -> V_48 . V_49 = V_50 ;
for ( V_126 = 0 ; V_126 < V_163 ; V_126 ++ ) {
struct V_16 * V_17 = & V_12 -> V_17 [ V_126 ] ;
V_17 -> V_52 = 1 ;
F_31 ( V_17 , - V_51 ) ;
}
F_89 ( & V_12 -> V_179 ) ;
if ( V_47 )
F_90 ( & V_12 -> V_48 , V_47 ) ;
F_82 ( V_12 ) ;
}
static void
F_70 ( struct V_11 * V_12 , struct V_175 * V_47 )
{
int V_126 ;
if ( V_12 -> V_48 . V_49 == V_50 )
V_47 = NULL ;
V_12 -> V_48 . V_49 = V_50 ;
for ( V_126 = 0 ; V_126 < V_163 ; V_126 ++ ) {
struct V_16 * V_17 = & V_12 -> V_17 [ V_126 ] ;
V_17 -> V_52 = 1 ;
F_31 ( V_17 , - V_51 ) ;
}
F_89 ( & V_12 -> V_179 ) ;
if ( V_47 )
V_47 -> V_180 ( & V_12 -> V_48 ) ;
F_82 ( V_12 ) ;
}
static int F_91 ( struct V_131 * V_174 )
{
struct V_11 * V_12 = F_85 ( V_174 ) ;
F_92 () ;
V_12 -> F_67 = 0 ;
F_70 ( V_12 , NULL ) ;
F_93 () ;
if ( ! F_76 ( V_12 -> V_144 ) )
( void ) F_86 ( V_12 -> V_144 -> V_177 , NULL ) ;
V_12 -> V_47 = NULL ;
F_87 ( V_12 ) ;
return 0 ;
}
static T_4
F_94 ( int V_181 , void * V_182 )
{
struct V_11 * V_12 = V_182 ;
int V_139 ;
V_12 -> V_86 . V_162 ++ ;
switch ( V_181 ) {
case V_183 :
V_139 = 1 ;
F_95 ( V_183 ) ;
F_96 ( V_184 ) ;
break;
case V_184 :
V_139 = 0 ;
F_95 ( V_184 ) ;
F_96 ( V_183 ) ;
break;
default:
return V_185 ;
}
F_73 ( & V_12 -> V_48 , V_139 ) ;
return V_186 ;
}
static inline void F_97 ( struct V_11 * V_12 )
{
unsigned V_126 ;
for ( V_126 = 1 ; V_126 < V_163 ; V_126 ++ )
F_31 ( & V_12 -> V_17 [ V_126 ] , - V_187 ) ;
}
static void F_98 ( unsigned long V_182 )
{
struct V_11 * V_12 = ( void * ) V_182 ;
F_92 () ;
if ( V_12 -> V_67 == V_125
&& ( F_18 ( V_12 ) & V_158 ) == 0
&& ( F_18 ( V_12 ) & V_159 ) == 0 ) {
F_19 ( V_12 , V_158 | V_160 ) ;
F_28 ( V_55 , L_70 ) ;
F_63 ( V_12 ) ;
}
F_93 () ;
}
static void F_99 ( struct V_11 * V_12 )
{
T_1 V_188 = F_18 ( V_12 ) ;
struct V_16 * V_17 = & V_12 -> V_17 [ 0 ] ;
struct V_59 * V_60 ;
union {
struct V_189 V_190 ;
T_3 V_191 [ 8 ] ;
T_1 V_192 [ 2 ] ;
} V_193 ;
if ( F_38 ( & V_17 -> V_61 ) )
V_60 = NULL ;
else
V_60 = F_59 ( V_17 -> V_61 . V_118 , struct V_59 , V_61 ) ;
if ( V_188 & V_159 ) {
F_31 ( V_17 , - V_194 ) ;
F_19 ( V_12 , V_159 ) ;
F_100 ( & V_12 -> V_179 ) ;
F_44 ( V_12 ) ;
}
if ( ( V_188 & V_80 ) != 0 && V_12 -> V_67 != V_68 ) {
F_31 ( V_17 , 0 ) ;
F_100 ( & V_12 -> V_179 ) ;
F_44 ( V_12 ) ;
}
switch ( V_12 -> V_67 ) {
case V_68 :
V_188 = F_18 ( V_12 ) ;
if ( F_42 ( ( V_188 & ( V_81 | V_80 | V_99 ) )
== ( V_81 | V_80 | V_99 ) ) ) {
int V_126 ;
F_31 ( V_17 , - V_195 ) ;
for ( V_126 = 0 ; V_126 < 8 ; V_126 ++ ) {
if ( F_49 ( ! ( F_18 ( V_12 ) & V_99 ) ) ) {
V_196:
F_26 ( L_71 , V_126 ) ;
goto V_197;
}
V_193 . V_191 [ V_126 ] = ( T_3 ) V_100 ;
}
if ( F_49 ( ( F_18 ( V_12 ) & V_99 ) != 0 ) )
goto V_196;
V_198:
F_28 ( V_55 , L_72 ,
V_193 . V_190 . V_199 , V_193 . V_190 . V_200 ,
F_101 ( V_193 . V_190 . V_201 ) ,
F_101 ( V_193 . V_190 . V_202 ) ,
F_101 ( V_193 . V_190 . V_203 ) ) ;
V_12 -> V_204 = ( V_193 . V_190 . V_199 & V_205 )
== V_206 ;
V_12 -> V_108 = 0 ;
V_12 -> V_84 = 1 ;
switch ( V_193 . V_190 . V_200 ) {
case V_207 :
if ( V_193 . V_190 . V_199 == V_208 ) {
V_209:
V_12 -> V_108 = 1 ;
F_97 ( V_12 ) ;
}
break;
case V_210 :
if ( V_193 . V_190 . V_199 == V_211 ) {
F_26 ( L_73 ,
F_101 ( V_193 . V_190 . V_202 ) ,
F_101 ( V_193 . V_190 . V_201 ) ) ;
goto V_209;
}
break;
case V_212 :
if ( V_193 . V_190 . V_199 == V_208 ) {
F_50 ( V_12 , 0 , L_74 ) ;
return;
}
break;
}
if ( V_193 . V_190 . V_199 & V_116 )
V_12 -> V_67 = V_104 ;
else
V_12 -> V_67 = V_106 ;
V_126 = V_12 -> V_47 -> V_213 ( & V_12 -> V_48 , & V_193 . V_190 ) ;
if ( V_126 < 0 ) {
if ( V_12 -> V_108 ) {
F_102 ( L_75 ,
V_193 . V_190 . V_200 , V_126 ) ;
return;
}
F_28 ( V_55 , L_76
L_77 , F_18 ( V_12 ) , V_126 ) ;
V_197:
F_50 ( V_12 , V_158 | V_160 , L_78 ) ;
F_63 ( V_12 ) ;
V_12 -> V_67 = V_125 ;
} else if ( V_12 -> V_84 ) {
if ( F_42 ( V_12 -> V_67 == V_104
|| V_12 -> V_204 || V_193 . V_190 . V_203 ) )
F_50 ( V_12 , 0 , L_79 ) ;
else
F_50 ( V_12 , V_89 , L_80 ) ;
}
return;
} else if ( F_42 ( ( V_188 & ( V_81 | V_80 ) )
== ( V_81 | V_80 ) ) ) {
unsigned V_126 ;
F_28 ( V_55 , L_81 ) ;
F_31 ( V_17 , - V_195 ) ;
for ( V_126 = 0 ; V_126 < 8 ; V_126 ++ )
V_193 . V_191 [ V_126 ] = ( T_3 ) V_100 ;
if ( ( V_193 . V_190 . V_199 & V_214 )
> V_215 )
goto V_197;
if ( V_193 . V_192 [ 0 ] == 0 && V_193 . V_192 [ 1 ] == 0 )
goto V_197;
goto V_198;
} else {
F_19 ( V_12 , V_188 & ( V_80 | V_81 ) ) ;
}
break;
case V_104 :
if ( V_188 & V_81 ) {
F_19 ( V_12 , V_81 | V_160 ) ;
F_28 ( V_55 , L_82 ) ;
if ( V_60 )
F_40 ( V_17 , V_60 , 0 ) ;
F_44 ( V_12 ) ;
} else {
if ( V_60 ) {
( void ) F_51 ( V_17 , V_60 ) ;
}
}
break;
case V_106 :
if ( V_188 & V_81 ) {
if ( V_60 ) {
if ( F_56 ( V_17 , V_60 ) )
F_40 ( V_17 , V_60 , 0 ) ;
}
} else {
F_28 ( V_55 , L_83 ) ;
if ( V_60 )
F_40 ( V_17 , V_60 , 0 ) ;
F_44 ( V_12 ) ;
}
break;
case V_114 :
if ( V_60 )
F_40 ( V_17 , V_60 , 0 ) ;
if ( V_188 & V_81 )
F_19 ( V_12 , V_81 ) ;
F_44 ( V_12 ) ;
break;
case V_125 :
F_19 ( V_12 , V_158 ) ;
break;
}
F_5 ( V_12 , V_82 , V_83 ) ;
}
static void F_103 ( struct V_16 * V_17 )
{
struct V_59 * V_60 ;
int V_216 = V_17 -> V_18 & V_116 ;
int V_217 ;
T_1 V_90 , V_149 ;
do {
V_217 = 0 ;
if ( F_42 ( ! F_38 ( & V_17 -> V_61 ) ) )
V_60 = F_59 ( V_17 -> V_61 . V_118 ,
struct V_59 , V_61 ) ;
else
V_60 = NULL ;
V_90 = F_16 ( V_17 ) ;
if ( F_49 ( V_216 ) ) {
V_149 = V_130 ;
if ( F_42 ( V_17 -> V_41 == V_42 ) )
V_149 |= V_127 ;
V_149 &= V_90 ;
if ( F_42 ( V_149 ) )
F_17 ( V_17 , V_149 ) ;
if ( V_60 && F_42 ( ( V_90 & V_78 ) != 0 ) )
V_217 = F_48 ( V_17 , V_60 ) ;
} else {
if ( F_42 ( V_17 -> V_41 == V_42 ) )
V_149 = V_218 | V_219 ;
else
V_149 = V_97 | V_220 ;
V_149 &= V_90 ;
if ( F_42 ( V_149 ) )
F_17 ( V_17 , V_149 ) ;
if ( F_42 ( V_60 ) ) {
V_217 = F_54 ( V_17 , V_60 ) ;
} else
F_12 ( V_17 ) ;
}
V_17 -> V_53 ++ ;
} while ( V_217 );
}
static T_4
F_104 ( int V_181 , void * V_182 )
{
struct V_11 * V_12 = V_182 ;
int V_221 ;
V_12 -> V_86 . V_162 ++ ;
do {
T_1 V_22 = F_7 ( V_12 , V_23 ) ;
V_221 = 0 ;
if ( F_49 ( V_22 & V_154 ) ) {
F_15 ( V_12 , V_154 ) ;
V_221 = 1 ;
F_28 ( V_55 , L_84 ) ;
if ( V_12 -> V_48 . V_49 != V_50
&& V_12 -> V_47
&& V_12 -> V_47 -> V_222 )
V_12 -> V_47 -> V_222 ( & V_12 -> V_48 ) ;
F_44 ( V_12 ) ;
}
if ( F_49 ( V_22 & V_155 ) ) {
F_15 ( V_12 , V_155 ) ;
V_221 = 1 ;
F_28 ( V_55 , L_85 ) ;
if ( V_12 -> V_48 . V_49 != V_50
&& V_12 -> V_47
&& V_12 -> V_47 -> V_223 )
V_12 -> V_47 -> V_223 ( & V_12 -> V_48 ) ;
}
if ( F_49 ( V_22 & V_152 ) ) {
F_15 ( V_12 , V_152 ) ;
V_221 = 1 ;
if ( ( F_7 ( V_12 , V_23 ) & V_156 ) == 0 ) {
F_28 ( V_55 , L_86 ) ;
F_88 ( V_12 , V_12 -> V_47 ) ;
} else {
F_28 ( V_55 , L_87 ) ;
V_12 -> V_48 . V_49 = V_161 ;
memset ( & V_12 -> V_86 , 0 , sizeof V_12 -> V_86 ) ;
}
} else {
T_1 V_224 = F_7 ( V_12 , V_82 ) &
~ F_7 ( V_12 , V_19 ) ;
T_1 V_225 = F_7 ( V_12 , V_150 ) &
~ F_7 ( V_12 , V_20 ) ;
int V_126 ;
if ( F_49 ( ! V_224 && ! V_225 ) )
continue;
F_28 ( V_75 , L_88 , V_225 , V_224 ) ;
if ( V_224 & V_83 ) {
V_12 -> V_17 [ 0 ] . V_53 ++ ;
F_99 ( V_12 ) ;
V_221 = 1 ;
}
for ( V_126 = 0 ; V_126 < 8 ; V_126 ++ ) {
T_1 V_149 = 1 << V_126 ;
if ( V_126 && ( V_224 & V_149 ) ) {
F_103 ( & V_12 -> V_17 [ V_126 ] ) ;
F_5 ( V_12 , V_82 ,
F_7 ( V_12 , V_82 ) | V_149 ) ;
V_221 = 1 ;
}
#ifndef F_105
if ( V_225 & V_149 ) {
F_103 ( & V_12 -> V_17 [ V_126 + 8 ] ) ;
F_5 ( V_12 , V_150 ,
F_7 ( V_12 , V_150 ) | V_149 ) ;
V_221 = 1 ;
}
#endif
}
}
} while ( V_221 );
return V_186 ;
}
static void F_106 ( struct V_226 * V_12 )
{
F_26 ( L_89 , V_39 , F_107 ( V_12 ) ) ;
}
static int F_108 ( struct V_227 * V_228 )
{
struct V_11 * V_12 = & V_229 ;
int V_176 , V_181 ;
T_1 V_230 ;
struct V_231 * V_232 ;
F_109 ( L_90 , V_233 , V_234 ) ;
asm("mrc%? p15, 0, %0, c0, c0" : "=r" (chiprev));
if ( ( V_230 & V_235 ) != V_236 ) {
F_110 ( L_91 , V_233 ) ;
return - V_128 ;
}
switch ( V_230 & V_237 ) {
#if F_111 ( V_238 )
case V_239 :
V_12 -> V_109 = 1 ;
break;
case V_240 :
case V_241 :
case V_242 : case V_243 :
case V_244 : case V_245 :
case V_246 : case V_247 :
case V_248 : case V_249 :
break;
#elif F_111 ( F_52 )
case V_250 :
case V_251 :
case V_252 :
V_12 -> V_109 = 1 ;
break;
#endif
default:
F_110 ( L_92 ,
V_233 , V_230 ) ;
return - V_128 ;
}
V_181 = F_112 ( V_228 , 0 ) ;
if ( V_181 < 0 )
return - V_128 ;
V_232 = F_113 ( V_228 , V_253 , 0 ) ;
V_12 -> V_15 = F_114 ( & V_228 -> V_12 , V_232 ) ;
if ( F_115 ( V_12 -> V_15 ) )
return F_116 ( V_12 -> V_15 ) ;
V_12 -> V_142 = F_117 ( & V_228 -> V_12 , NULL ) ;
if ( F_115 ( V_12 -> V_142 ) )
return F_116 ( V_12 -> V_142 ) ;
F_118 ( L_93 , V_233 , V_181 ,
V_12 -> V_109 ? L_11 : L_94 ,
V_254 L_38
) ;
V_12 -> V_12 = & V_228 -> V_12 ;
V_12 -> V_2 = F_119 ( & V_228 -> V_12 ) ;
V_12 -> V_144 = F_120 ( & V_228 -> V_12 , V_255 ) ;
if ( F_2 ( V_12 -> V_2 -> V_6 ) ) {
V_176 = F_121 ( & V_228 -> V_12 , V_12 -> V_2 -> V_6 ,
L_95 ) ;
if ( V_176 ) {
F_122 ( & V_228 -> V_12 ,
L_96 ,
V_12 -> V_2 -> V_6 , V_176 ) ;
goto V_256;
}
F_123 ( V_12 -> V_2 -> V_6 , 0 ) ;
}
F_124 ( & V_12 -> V_179 ) ;
V_12 -> V_179 . V_257 = F_98 ;
V_12 -> V_179 . V_26 = ( unsigned long ) V_12 ;
V_3 = V_12 ;
F_125 ( V_228 , V_12 ) ;
F_71 ( V_12 ) ;
F_82 ( V_12 ) ;
V_12 -> V_139 = 0 ;
V_176 = F_126 ( & V_228 -> V_12 , V_181 , F_104 , 0 ,
V_233 , V_12 ) ;
if ( V_176 != 0 ) {
F_110 ( L_97 ,
V_233 , V_181 , V_176 ) ;
goto V_256;
}
V_12 -> V_258 = 1 ;
#ifdef F_127
if ( F_128 () ) {
V_176 = F_126 ( & V_228 -> V_12 , V_184 ,
F_94 , 0 , V_233 ,
V_12 ) ;
if ( V_176 != 0 ) {
F_110 ( L_98 ,
V_233 , V_184 , V_176 ) ;
goto V_256;
}
V_176 = F_126 ( & V_228 -> V_12 , V_183 ,
F_94 , 0 , V_233 ,
V_12 ) ;
if ( V_176 != 0 ) {
F_110 ( L_98 ,
V_233 , V_183 , V_176 ) ;
goto V_256;
}
} else
#endif
F_129 ( V_12 ) ;
V_176 = F_130 ( & V_228 -> V_12 , & V_12 -> V_48 ) ;
if ( ! V_176 )
return V_176 ;
F_131 ( V_12 ) ;
V_256:
if ( ! F_76 ( V_12 -> V_144 ) )
V_12 -> V_144 = NULL ;
return V_176 ;
}
static void F_132 ( struct V_227 * V_182 )
{
F_1 () ;
}
static int F_133 ( struct V_227 * V_228 )
{
struct V_11 * V_12 = F_134 ( V_228 ) ;
if ( V_12 -> V_47 )
return - V_259 ;
F_135 ( & V_12 -> V_48 ) ;
V_12 -> F_67 = 0 ;
F_67 ( V_12 ) ;
F_131 ( V_12 ) ;
if ( ! F_76 ( V_12 -> V_144 ) )
V_12 -> V_144 = NULL ;
V_3 = NULL ;
return 0 ;
}
static int F_136 ( struct V_227 * V_12 , T_5 V_260 )
{
struct V_11 * V_135 = F_134 ( V_12 ) ;
unsigned long V_56 ;
if ( ! F_2 ( V_135 -> V_2 -> V_6 ) && ! V_135 -> V_2 -> V_7 )
F_102 ( L_99 ) ;
V_135 -> V_140 = 1 ;
F_30 ( V_56 ) ;
F_67 ( V_135 ) ;
F_32 ( V_56 ) ;
return 0 ;
}
static int F_137 ( struct V_227 * V_12 )
{
struct V_11 * V_135 = F_134 ( V_12 ) ;
unsigned long V_56 ;
V_135 -> V_140 = 0 ;
F_30 ( V_56 ) ;
F_67 ( V_135 ) ;
F_32 ( V_56 ) ;
return 0 ;
}
