static inline struct V_1 * V_1 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) ;
}
static inline void T_1 * F_2 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = V_1 ( V_4 ) ;
return V_5 -> V_6 ;
}
static inline int F_3 ( struct V_2 * V_4 , T_2 V_7 )
{
return F_4 ( F_2 ( V_4 ) + ( V_7 << V_8 ) ) ;
}
static inline int F_5 ( struct V_2 * V_4 , T_2 V_7 ,
T_3 V_9 )
{
F_6 ( V_9 , F_2 ( V_4 ) + ( V_7 << V_8 ) ) ;
return 0 ;
}
static inline int F_7 ( struct V_2 * V_4 , T_2 V_7 , T_3 V_9 )
{
F_5 ( V_4 , V_7 , V_9 ) ;
F_8 () ;
return 0 ;
}
static int F_9 ( struct V_2 * V_4 , T_2 V_7 )
{
T_4 V_9 ;
V_9 = F_3 ( V_4 , V_7 ) << 8 ;
V_9 |= F_3 ( V_4 , V_7 + 1 ) ;
return V_9 ;
}
static int F_10 ( struct V_2 * V_4 , T_2 V_7 , T_4 V_9 )
{
F_5 ( V_4 , V_7 , V_9 >> 8 ) ;
F_5 ( V_4 , V_7 + 1 , V_9 ) ;
F_8 () ;
return 0 ;
}
static int F_11 ( struct V_2 * V_4 , T_2 V_7 , T_3 * V_10 ,
int V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ , V_7 ++ )
* V_10 ++ = F_3 ( V_4 , V_7 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_4 , T_2 V_7 ,
const T_3 * V_10 , int V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ , V_7 ++ )
F_5 ( V_4 , V_7 , * V_10 ++ ) ;
F_8 () ;
return 0 ;
}
static int F_13 ( struct V_2 * V_4 )
{
struct V_13 * V_14 = F_14 ( V_4 -> V_3 . V_15 ) ;
struct V_16 * V_17 = F_15 ( V_4 ) ;
struct V_1 * V_5 = V_1 ( V_4 ) ;
struct V_18 * V_19 ;
F_16 ( & V_5 -> V_20 ) ;
V_19 = F_17 ( V_14 , V_21 , 0 ) ;
V_5 -> V_6 = F_18 ( & V_14 -> V_3 , V_19 ) ;
if ( F_19 ( V_5 -> V_6 ) )
return F_20 ( V_5 -> V_6 ) ;
F_21 ( V_4 , L_1 , ( V_22 ) V_19 -> V_23 , V_17 -> V_24 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_4 , T_2 V_7 )
{
struct V_1 * V_5 = V_1 ( V_4 ) ;
unsigned long V_25 ;
T_3 V_9 ;
F_23 ( & V_5 -> V_20 , V_25 ) ;
F_10 ( V_4 , V_26 , V_7 ) ;
V_9 = F_3 ( V_4 , V_27 ) ;
F_24 ( & V_5 -> V_20 , V_25 ) ;
return V_9 ;
}
static int F_25 ( struct V_2 * V_4 , T_2 V_7 , T_3 V_9 )
{
struct V_1 * V_5 = V_1 ( V_4 ) ;
unsigned long V_25 ;
F_23 ( & V_5 -> V_20 , V_25 ) ;
F_10 ( V_4 , V_26 , V_7 ) ;
F_7 ( V_4 , V_27 , V_9 ) ;
F_24 ( & V_5 -> V_20 , V_25 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_4 , T_2 V_7 )
{
struct V_1 * V_5 = V_1 ( V_4 ) ;
unsigned long V_25 ;
T_4 V_9 ;
F_23 ( & V_5 -> V_20 , V_25 ) ;
F_10 ( V_4 , V_26 , V_7 ) ;
V_9 = F_3 ( V_4 , V_27 ) << 8 ;
V_9 |= F_3 ( V_4 , V_27 ) ;
F_24 ( & V_5 -> V_20 , V_25 ) ;
return V_9 ;
}
static int F_27 ( struct V_2 * V_4 , T_2 V_7 , T_4 V_9 )
{
struct V_1 * V_5 = V_1 ( V_4 ) ;
unsigned long V_25 ;
F_23 ( & V_5 -> V_20 , V_25 ) ;
F_10 ( V_4 , V_26 , V_7 ) ;
F_5 ( V_4 , V_27 , V_9 >> 8 ) ;
F_7 ( V_4 , V_27 , V_9 ) ;
F_24 ( & V_5 -> V_20 , V_25 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_4 , T_2 V_7 , T_3 * V_10 ,
int V_11 )
{
struct V_1 * V_5 = V_1 ( V_4 ) ;
unsigned long V_25 ;
int V_12 ;
F_23 ( & V_5 -> V_20 , V_25 ) ;
F_10 ( V_4 , V_26 , V_7 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
* V_10 ++ = F_3 ( V_4 , V_27 ) ;
F_8 () ;
F_24 ( & V_5 -> V_20 , V_25 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_4 , T_2 V_7 ,
const T_3 * V_10 , int V_11 )
{
struct V_1 * V_5 = V_1 ( V_4 ) ;
unsigned long V_25 ;
int V_12 ;
F_23 ( & V_5 -> V_20 , V_25 ) ;
F_10 ( V_4 , V_26 , V_7 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
F_5 ( V_4 , V_27 , * V_10 ++ ) ;
F_8 () ;
F_24 ( & V_5 -> V_20 , V_25 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_4 )
{
F_7 ( V_4 , V_28 , V_29 ) ;
F_31 ( 5 ) ;
F_7 ( V_4 , V_28 , V_30 | V_31 | V_32 ) ;
return 0 ;
}
static int F_32 ( struct V_16 * V_17 , T_2 V_7 )
{
return F_3 ( V_17 -> V_4 , V_7 ) ;
}
static int F_33 ( struct V_16 * V_17 , T_2 V_7 , T_3 V_9 )
{
return F_7 ( V_17 -> V_4 , V_7 , V_9 ) ;
}
static int F_34 ( struct V_16 * V_17 , T_2 V_7 )
{
return F_9 ( V_17 -> V_4 , V_7 ) ;
}
static int F_35 ( struct V_16 * V_17 , T_2 V_7 , T_4 V_9 )
{
return F_10 ( V_17 -> V_4 , V_7 , V_9 ) ;
}
static int F_36 ( struct V_16 * V_17 , T_2 V_7 , T_3 * V_10 , int V_11 )
{
return F_11 ( V_17 -> V_4 , V_7 , V_10 , V_11 ) ;
}
static int F_37 ( struct V_16 * V_17 , T_2 V_7 , const T_3 * V_10 ,
int V_11 )
{
return F_12 ( V_17 -> V_4 , V_7 , V_10 , V_11 ) ;
}
static int F_32 ( struct V_16 * V_17 , T_2 V_7 )
{
return F_22 ( V_17 -> V_4 , V_7 ) ;
}
static int F_33 ( struct V_16 * V_17 , T_2 V_7 , T_3 V_9 )
{
return F_25 ( V_17 -> V_4 , V_7 , V_9 ) ;
}
static int F_34 ( struct V_16 * V_17 , T_2 V_7 )
{
return F_26 ( V_17 -> V_4 , V_7 ) ;
}
static int F_35 ( struct V_16 * V_17 , T_2 V_7 , T_4 V_9 )
{
return F_27 ( V_17 -> V_4 , V_7 , V_9 ) ;
}
static int F_36 ( struct V_16 * V_17 , T_2 V_7 , T_3 * V_10 , int V_11 )
{
return F_28 ( V_17 -> V_4 , V_7 , V_10 , V_11 ) ;
}
static int F_37 ( struct V_16 * V_17 , T_2 V_7 , const T_3 * V_10 ,
int V_11 )
{
return F_29 ( V_17 -> V_4 , V_7 , V_10 , V_11 ) ;
}
static int F_32 ( struct V_16 * V_17 , T_2 V_7 )
{
return V_17 -> V_33 -> V_34 ( V_17 -> V_4 , V_7 ) ;
}
static int F_33 ( struct V_16 * V_17 , T_2 V_7 , T_3 V_9 )
{
return V_17 -> V_33 -> V_35 ( V_17 -> V_4 , V_7 , V_9 ) ;
}
static int F_34 ( struct V_16 * V_17 , T_2 V_7 )
{
return V_17 -> V_33 -> V_36 ( V_17 -> V_4 , V_7 ) ;
}
static int F_35 ( struct V_16 * V_17 , T_2 V_7 , T_4 V_9 )
{
return V_17 -> V_33 -> V_37 ( V_17 -> V_4 , V_7 , V_9 ) ;
}
static int F_36 ( struct V_16 * V_17 , T_2 V_7 , T_3 * V_10 , int V_11 )
{
return V_17 -> V_33 -> V_38 ( V_17 -> V_4 , V_7 , V_10 , V_11 ) ;
}
static int F_37 ( struct V_16 * V_17 , T_2 V_7 , const T_3 * V_10 ,
int V_11 )
{
return V_17 -> V_33 -> V_39 ( V_17 -> V_4 , V_7 , V_10 , V_11 ) ;
}
static int F_38 ( struct V_16 * V_17 , T_4 V_40 , T_3 * V_10 , int V_11 )
{
T_2 V_7 ;
int V_41 = 0 ;
int V_42 ;
const T_2 V_43 = V_17 -> V_44 ;
const T_4 V_45 = V_17 -> V_46 ;
V_40 %= V_45 ;
V_7 = V_43 + V_40 ;
if ( V_40 + V_11 > V_45 ) {
V_41 = ( V_40 + V_11 ) % V_45 ;
V_11 = V_45 - V_40 ;
}
V_42 = F_36 ( V_17 , V_7 , V_10 , V_11 ) ;
if ( V_42 || ! V_41 )
return V_42 ;
return F_36 ( V_17 , V_43 , V_10 + V_11 , V_41 ) ;
}
static int F_39 ( struct V_16 * V_17 , T_4 V_40 , const T_3 * V_10 ,
int V_11 )
{
T_2 V_7 ;
int V_42 ;
int V_41 = 0 ;
const T_2 V_43 = V_17 -> V_47 ;
const T_4 V_45 = V_17 -> V_48 ;
V_40 %= V_45 ;
V_7 = V_43 + V_40 ;
if ( V_40 + V_11 > V_45 ) {
V_41 = ( V_40 + V_11 ) % V_45 ;
V_11 = V_45 - V_40 ;
}
V_42 = F_37 ( V_17 , V_7 , V_10 , V_11 ) ;
if ( V_42 || ! V_41 )
return V_42 ;
return F_37 ( V_17 , V_43 , V_10 + V_11 , V_41 ) ;
}
static int F_40 ( struct V_16 * V_17 )
{
if ( V_17 -> V_33 -> V_49 )
return V_17 -> V_33 -> V_49 ( V_17 -> V_4 ) ;
F_33 ( V_17 , V_28 , V_29 ) ;
F_31 ( 5 ) ;
F_33 ( V_17 , V_28 , V_30 ) ;
return 0 ;
}
static int F_41 ( struct V_16 * V_17 , T_4 V_50 )
{
unsigned long V_51 ;
F_33 ( V_17 , F_42 ( V_17 ) , V_50 ) ;
V_51 = V_52 + F_43 ( 100 ) ;
while ( F_32 ( V_17 , F_42 ( V_17 ) ) != 0 ) {
if ( F_44 ( V_52 , V_51 ) )
return - V_53 ;
F_45 () ;
}
return 0 ;
}
static void F_46 ( struct V_16 * V_17 )
{
struct V_2 * V_4 = V_17 -> V_4 ;
F_37 ( V_17 , V_54 , V_4 -> V_55 , V_56 ) ;
}
static void F_47 ( struct V_16 * V_17 , T_3 V_57 )
{
T_2 V_58 ;
if ( V_17 -> V_33 -> V_59 == V_60 )
V_58 = V_61 ;
else
V_58 = V_62 ;
F_33 ( V_17 , V_58 , V_57 ) ;
}
static void F_48 ( struct V_16 * V_17 )
{
F_47 ( V_17 , V_63 ) ;
}
static void F_49 ( struct V_16 * V_17 )
{
F_47 ( V_17 , 0 ) ;
}
static void F_50 ( struct V_16 * V_17 )
{
F_33 ( V_17 , V_64 , 0x03 ) ;
F_33 ( V_17 , V_65 , 0x03 ) ;
}
static void F_51 ( struct V_16 * V_17 )
{
int V_12 ;
F_33 ( V_17 , F_52 ( 0 ) , 0x10 ) ;
F_33 ( V_17 , F_53 ( 0 ) , 0x10 ) ;
for ( V_12 = 1 ; V_12 < 8 ; V_12 ++ ) {
F_33 ( V_17 , F_52 ( V_12 ) , 0 ) ;
F_33 ( V_17 , F_53 ( V_12 ) , 0 ) ;
}
}
static void F_54 ( struct V_16 * V_17 )
{
int V_12 ;
F_33 ( V_17 , F_55 ( 0 ) , 0x10 ) ;
F_33 ( V_17 , F_56 ( 0 ) , 0x10 ) ;
for ( V_12 = 1 ; V_12 < 8 ; V_12 ++ ) {
F_33 ( V_17 , F_55 ( V_12 ) , 0 ) ;
F_33 ( V_17 , F_56 ( V_12 ) , 0 ) ;
}
}
static int F_57 ( struct V_16 * V_17 )
{
T_2 V_66 ;
F_40 ( V_17 ) ;
F_49 ( V_17 ) ;
F_46 ( V_17 ) ;
switch ( V_17 -> V_33 -> V_59 ) {
case V_67 :
F_50 ( V_17 ) ;
V_66 = V_68 ;
break;
case V_69 :
F_51 ( V_17 ) ;
V_66 = V_68 ;
break;
case V_60 :
F_54 ( V_17 ) ;
V_66 = V_70 ;
break;
default:
return - V_71 ;
}
if ( F_34 ( V_17 , V_66 ) != V_72 )
return - V_73 ;
return 0 ;
}
static void F_58 ( struct V_16 * V_17 )
{
T_3 V_74 = V_75 ;
if ( ! V_17 -> V_76 ) {
if ( V_17 -> V_33 -> V_59 == V_60 )
V_74 |= V_77 ;
else
V_74 |= V_78 ;
}
F_33 ( V_17 , F_59 ( V_17 ) , V_74 ) ;
F_41 ( V_17 , V_79 ) ;
F_48 ( V_17 ) ;
}
static void F_60 ( struct V_16 * V_17 )
{
F_49 ( V_17 ) ;
F_41 ( V_17 , V_80 ) ;
}
static void F_61 ( struct V_2 * V_4 ,
struct V_81 * V_82 )
{
F_62 ( V_82 -> V_83 , V_84 , sizeof( V_82 -> V_83 ) ) ;
F_62 ( V_82 -> V_85 , V_86 , sizeof( V_82 -> V_85 ) ) ;
F_62 ( V_82 -> V_87 , F_63 ( V_4 -> V_3 . V_15 ) ,
sizeof( V_82 -> V_87 ) ) ;
}
static T_2 F_64 ( struct V_2 * V_4 )
{
struct V_16 * V_17 = F_15 ( V_4 ) ;
if ( F_65 ( V_17 -> V_88 ) )
return ! ! F_66 ( V_17 -> V_88 ) ;
return 1 ;
}
static T_2 F_67 ( struct V_2 * V_4 )
{
struct V_16 * V_17 = F_15 ( V_4 ) ;
return V_17 -> V_89 ;
}
static void F_68 ( struct V_2 * V_4 , T_2 V_90 )
{
struct V_16 * V_17 = F_15 ( V_4 ) ;
V_17 -> V_89 = V_90 ;
}
static int F_69 ( struct V_2 * V_4 )
{
return V_91 + V_92 ;
}
static void F_70 ( struct V_2 * V_4 ,
struct V_93 * V_94 , void * V_10 )
{
struct V_16 * V_17 = F_15 ( V_4 ) ;
V_94 -> V_85 = 1 ;
F_36 ( V_17 , V_95 , V_10 , V_91 ) ;
V_10 += V_91 ;
F_36 ( V_17 , F_71 ( V_17 ) , V_10 , V_92 ) ;
}
static void F_72 ( struct V_2 * V_4 )
{
struct V_16 * V_17 = F_15 ( V_4 ) ;
F_73 ( V_4 ) ;
F_57 ( V_17 ) ;
F_58 ( V_17 ) ;
V_4 -> V_96 . V_97 ++ ;
F_74 ( V_4 ) ;
F_75 ( V_4 ) ;
}
static void F_76 ( struct V_98 * V_99 )
{
struct V_16 * V_17 = F_77 ( V_99 , struct V_16 ,
V_100 ) ;
F_72 ( V_17 -> V_4 ) ;
}
static void F_78 ( struct V_2 * V_4 )
{
struct V_16 * V_17 = F_15 ( V_4 ) ;
if ( V_17 -> V_33 -> V_101 )
F_79 ( & V_17 -> V_100 ) ;
else
F_72 ( V_4 ) ;
}
static void F_80 ( struct V_2 * V_4 , struct V_102 * V_103 )
{
struct V_16 * V_17 = F_15 ( V_4 ) ;
T_4 V_40 ;
V_40 = F_34 ( V_17 , F_81 ( V_17 ) ) ;
F_39 ( V_17 , V_40 , V_103 -> V_9 , V_103 -> V_11 ) ;
F_35 ( V_17 , F_81 ( V_17 ) , V_40 + V_103 -> V_11 ) ;
V_4 -> V_96 . V_104 += V_103 -> V_11 ;
V_4 -> V_96 . V_105 ++ ;
F_82 ( V_103 ) ;
F_41 ( V_17 , V_106 ) ;
}
static void F_83 ( struct V_98 * V_99 )
{
struct V_16 * V_17 = F_77 ( V_99 , struct V_16 ,
V_107 ) ;
struct V_102 * V_103 = V_17 -> V_108 ;
V_17 -> V_108 = NULL ;
if ( F_84 ( ! V_103 ) )
return;
F_80 ( V_17 -> V_4 , V_103 ) ;
}
static int F_85 ( struct V_102 * V_103 , struct V_2 * V_4 )
{
struct V_16 * V_17 = F_15 ( V_4 ) ;
F_73 ( V_4 ) ;
if ( V_17 -> V_33 -> V_101 ) {
F_84 ( V_17 -> V_108 ) ;
V_17 -> V_108 = V_103 ;
F_86 ( V_17 -> V_109 , & V_17 -> V_107 ) ;
} else {
F_80 ( V_4 , V_103 ) ;
}
return V_110 ;
}
static struct V_102 * F_87 ( struct V_2 * V_4 )
{
struct V_16 * V_17 = F_15 ( V_4 ) ;
struct V_102 * V_103 ;
T_4 V_111 ;
T_4 V_40 ;
T_3 V_112 [ 2 ] ;
T_4 V_113 = F_34 ( V_17 , F_88 ( V_17 ) ) ;
if ( V_113 == 0 )
return NULL ;
V_40 = F_34 ( V_17 , F_89 ( V_17 ) ) ;
F_38 ( V_17 , V_40 , V_112 , 2 ) ;
V_111 = F_90 ( V_112 ) - 2 ;
V_103 = F_91 ( V_4 , V_111 ) ;
if ( F_92 ( ! V_103 ) ) {
F_35 ( V_17 , F_89 ( V_17 ) , V_40 + V_113 ) ;
F_41 ( V_17 , V_114 ) ;
V_4 -> V_96 . V_115 ++ ;
return NULL ;
}
F_93 ( V_103 , V_111 ) ;
F_38 ( V_17 , V_40 + 2 , V_103 -> V_9 , V_111 ) ;
F_35 ( V_17 , F_89 ( V_17 ) , V_40 + 2 + V_111 ) ;
F_41 ( V_17 , V_114 ) ;
V_103 -> V_116 = F_94 ( V_103 , V_4 ) ;
V_4 -> V_96 . V_117 ++ ;
V_4 -> V_96 . V_118 += V_111 ;
return V_103 ;
}
static void F_95 ( struct V_98 * V_99 )
{
struct V_16 * V_17 = F_77 ( V_99 , struct V_16 ,
V_119 ) ;
struct V_102 * V_103 ;
while ( ( V_103 = F_87 ( V_17 -> V_4 ) ) )
F_96 ( V_103 ) ;
F_48 ( V_17 ) ;
}
static int F_97 ( struct V_120 * V_121 , int V_122 )
{
struct V_16 * V_17 = F_77 ( V_121 , struct V_16 , V_121 ) ;
int V_123 ;
for ( V_123 = 0 ; V_123 < V_122 ; V_123 ++ ) {
struct V_102 * V_103 = F_87 ( V_17 -> V_4 ) ;
if ( V_103 )
F_98 ( V_103 ) ;
else
break;
}
if ( V_123 < V_122 ) {
F_99 ( V_121 ) ;
F_48 ( V_17 ) ;
}
return V_123 ;
}
static T_5 F_100 ( int V_24 , void * V_124 )
{
struct V_2 * V_4 = V_124 ;
struct V_16 * V_17 = F_15 ( V_4 ) ;
int V_125 = F_32 ( V_17 , F_101 ( V_17 ) ) ;
if ( ! V_125 )
return V_126 ;
F_33 ( V_17 , F_101 ( V_17 ) , V_125 ) ;
if ( V_125 & V_127 ) {
F_102 ( V_17 , V_128 , V_4 , L_2 ) ;
F_75 ( V_4 ) ;
}
if ( V_125 & V_129 ) {
F_49 ( V_17 ) ;
if ( V_17 -> V_33 -> V_101 )
F_86 ( V_17 -> V_109 , & V_17 -> V_119 ) ;
else if ( F_103 ( & V_17 -> V_121 ) )
F_104 ( & V_17 -> V_121 ) ;
}
return V_130 ;
}
static T_5 F_105 ( int V_24 , void * V_124 )
{
struct V_2 * V_4 = V_124 ;
struct V_16 * V_17 = F_15 ( V_4 ) ;
if ( F_106 ( V_4 ) ) {
if ( F_66 ( V_17 -> V_88 ) != 0 ) {
F_107 ( V_17 , V_131 , V_4 , L_3 ) ;
F_108 ( V_4 ) ;
} else {
F_107 ( V_17 , V_131 , V_4 , L_4 ) ;
F_109 ( V_4 ) ;
}
}
return V_130 ;
}
static void F_110 ( struct V_98 * V_99 )
{
struct V_16 * V_17 = F_77 ( V_99 , struct V_16 ,
V_132 ) ;
F_58 ( V_17 ) ;
}
static void F_111 ( struct V_2 * V_4 )
{
struct V_16 * V_17 = F_15 ( V_4 ) ;
bool V_133 = ( V_4 -> V_25 & V_134 ) != 0 ;
if ( V_17 -> V_76 != V_133 ) {
V_17 -> V_76 = V_133 ;
if ( V_17 -> V_33 -> V_101 )
F_79 ( & V_17 -> V_132 ) ;
else
F_58 ( V_17 ) ;
}
}
static int F_112 ( struct V_2 * V_4 , void * V_7 )
{
struct V_16 * V_17 = F_15 ( V_4 ) ;
struct V_135 * V_136 = V_7 ;
if ( ! F_113 ( V_136 -> V_137 ) )
return - V_138 ;
memcpy ( V_4 -> V_55 , V_136 -> V_137 , V_56 ) ;
F_46 ( V_17 ) ;
return 0 ;
}
static int F_114 ( struct V_2 * V_4 )
{
struct V_16 * V_17 = F_15 ( V_4 ) ;
F_107 ( V_17 , V_139 , V_4 , L_5 ) ;
F_58 ( V_17 ) ;
F_115 ( & V_17 -> V_121 ) ;
F_116 ( V_4 ) ;
if ( ! F_65 ( V_17 -> V_88 ) ||
F_66 ( V_17 -> V_88 ) != 0 )
F_108 ( V_4 ) ;
return 0 ;
}
static int F_117 ( struct V_2 * V_4 )
{
struct V_16 * V_17 = F_15 ( V_4 ) ;
F_107 ( V_17 , V_140 , V_4 , L_6 ) ;
F_60 ( V_17 ) ;
F_109 ( V_4 ) ;
F_73 ( V_4 ) ;
F_118 ( & V_17 -> V_121 ) ;
return 0 ;
}
static int F_119 ( struct V_13 * V_14 )
{
struct V_141 * V_9 = F_120 ( & V_14 -> V_3 ) ;
const void * V_142 = NULL ;
struct V_18 * V_19 ;
const struct V_143 * V_33 ;
int V_24 ;
if ( V_9 && F_113 ( V_9 -> V_142 ) )
V_142 = V_9 -> V_142 ;
V_19 = F_17 ( V_14 , V_21 , 0 ) ;
if ( F_121 ( V_19 ) < V_144 )
V_33 = & V_145 ;
else
V_33 = & V_146 ;
V_24 = F_122 ( V_14 , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
return F_123 ( & V_14 -> V_3 , V_33 , sizeof( struct V_1 ) ,
V_142 , V_24 , V_9 ? V_9 -> V_88 : - V_71 ) ;
}
static int F_124 ( struct V_13 * V_14 )
{
return F_125 ( & V_14 -> V_3 ) ;
}
void * F_1 ( const struct V_2 * V_4 )
{
return F_15 ( V_4 ) +
F_126 ( sizeof( struct V_16 ) , V_147 ) ;
}
int F_123 ( struct V_148 * V_3 , const struct V_143 * V_33 ,
int V_149 , const void * V_142 , int V_24 ,
int V_88 )
{
struct V_16 * V_17 ;
struct V_2 * V_4 ;
int V_150 ;
T_6 V_151 ;
V_151 = sizeof( * V_17 ) ;
if ( V_149 ) {
V_151 = F_126 ( V_151 , V_147 ) ;
V_151 += V_149 ;
}
V_151 += V_147 - 1 ;
V_4 = F_127 ( V_151 ) ;
if ( ! V_4 )
return - V_152 ;
F_128 ( V_4 , V_3 ) ;
F_129 ( V_3 , V_4 ) ;
V_17 = F_15 ( V_4 ) ;
switch ( V_33 -> V_59 ) {
case V_67 :
V_17 -> V_153 = V_154 ;
V_17 -> V_47 = V_155 ;
V_17 -> V_48 = V_156 ;
V_17 -> V_44 = V_157 ;
V_17 -> V_46 = V_158 ;
break;
case V_69 :
V_17 -> V_153 = V_159 ;
V_17 -> V_47 = V_160 ;
V_17 -> V_48 = V_161 ;
V_17 -> V_44 = V_162 ;
V_17 -> V_46 = V_163 ;
break;
case V_60 :
V_17 -> V_153 = V_164 ;
V_17 -> V_47 = V_165 ;
V_17 -> V_48 = V_166 ;
V_17 -> V_44 = V_167 ;
V_17 -> V_46 = V_168 ;
break;
default:
V_150 = - V_71 ;
goto V_169;
}
V_17 -> V_4 = V_4 ;
V_17 -> V_33 = V_33 ;
V_17 -> V_24 = V_24 ;
V_17 -> V_88 = V_88 ;
V_4 -> V_170 = & V_171 ;
V_4 -> V_172 = & V_173 ;
F_130 ( V_4 , & V_17 -> V_121 , F_97 , 16 ) ;
V_4 -> V_174 |= V_175 ;
V_150 = F_131 ( V_4 ) ;
if ( V_150 < 0 )
goto V_169;
V_17 -> V_109 = F_132 ( F_133 ( V_4 ) , V_176 , 0 ) ;
if ( ! V_17 -> V_109 ) {
V_150 = - V_152 ;
goto V_177;
}
F_134 ( & V_17 -> V_119 , F_95 ) ;
F_134 ( & V_17 -> V_107 , F_83 ) ;
F_134 ( & V_17 -> V_132 , F_110 ) ;
F_134 ( & V_17 -> V_100 , F_76 ) ;
if ( V_142 )
memcpy ( V_4 -> V_55 , V_142 , V_56 ) ;
else
F_135 ( V_4 ) ;
if ( V_17 -> V_33 -> V_178 ) {
V_150 = V_17 -> V_33 -> V_178 ( V_17 -> V_4 ) ;
if ( V_150 )
goto V_179;
}
V_150 = F_57 ( V_17 ) ;
if ( V_150 )
goto V_179;
if ( V_33 -> V_101 ) {
V_150 = F_136 ( V_17 -> V_24 , NULL , F_100 ,
V_180 | V_181 ,
F_133 ( V_4 ) , V_4 ) ;
} else {
V_150 = F_137 ( V_17 -> V_24 , F_100 ,
V_180 , F_133 ( V_4 ) , V_4 ) ;
}
if ( V_150 )
goto V_179;
if ( F_65 ( V_17 -> V_88 ) ) {
char * V_182 = F_138 ( V_3 , 16 , V_183 ) ;
if ( ! V_182 ) {
V_150 = - V_152 ;
goto V_184;
}
snprintf ( V_182 , 16 , L_7 , F_133 ( V_4 ) ) ;
V_17 -> V_185 = F_139 ( V_17 -> V_88 ) ;
if ( F_140 ( V_17 -> V_185 , F_105 ,
V_186 |
V_187 ,
V_182 , V_17 -> V_4 ) < 0 )
V_17 -> V_88 = - V_71 ;
}
return 0 ;
V_184:
F_141 ( V_17 -> V_24 , V_4 ) ;
V_179:
F_142 ( V_17 -> V_109 ) ;
V_177:
F_143 ( V_4 ) ;
V_169:
F_144 ( V_4 ) ;
return V_150 ;
}
int F_125 ( struct V_148 * V_3 )
{
struct V_2 * V_4 = F_145 ( V_3 ) ;
struct V_16 * V_17 = F_15 ( V_4 ) ;
F_57 ( V_17 ) ;
F_141 ( V_17 -> V_24 , V_4 ) ;
if ( F_65 ( V_17 -> V_88 ) )
F_141 ( V_17 -> V_185 , V_4 ) ;
F_146 ( & V_17 -> V_132 ) ;
F_146 ( & V_17 -> V_100 ) ;
F_142 ( V_17 -> V_109 ) ;
F_143 ( V_4 ) ;
F_144 ( V_4 ) ;
return 0 ;
}
static int F_147 ( struct V_148 * V_3 )
{
struct V_2 * V_4 = F_145 ( V_3 ) ;
struct V_16 * V_17 = F_15 ( V_4 ) ;
if ( F_106 ( V_4 ) ) {
F_109 ( V_4 ) ;
F_148 ( V_4 ) ;
F_60 ( V_17 ) ;
}
return 0 ;
}
static int F_149 ( struct V_148 * V_3 )
{
struct V_2 * V_4 = F_145 ( V_3 ) ;
struct V_16 * V_17 = F_15 ( V_4 ) ;
if ( F_106 ( V_4 ) ) {
F_57 ( V_17 ) ;
F_58 ( V_17 ) ;
F_150 ( V_4 ) ;
if ( ! F_65 ( V_17 -> V_88 ) ||
F_66 ( V_17 -> V_88 ) != 0 )
F_108 ( V_4 ) ;
}
return 0 ;
}
