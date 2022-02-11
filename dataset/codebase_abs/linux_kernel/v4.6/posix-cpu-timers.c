void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 V_4 = F_2 ( V_3 ) ;
F_3 ( & V_2 -> V_5 -> V_6 ) ;
F_4 ( V_2 , V_7 , & V_4 , NULL ) ;
F_5 ( & V_2 -> V_5 -> V_6 ) ;
}
static int F_6 ( const T_2 V_8 )
{
int error = 0 ;
struct V_1 * V_9 ;
const T_3 V_10 = F_7 ( V_8 ) ;
if ( F_8 ( V_8 ) >= V_11 )
return - V_12 ;
if ( V_10 == 0 )
return 0 ;
F_9 () ;
V_9 = F_10 ( V_10 ) ;
if ( ! V_9 || ! ( F_11 ( V_8 ) ?
F_12 ( V_9 , V_13 ) : F_13 ( V_9 ) ) ) {
error = - V_12 ;
}
F_14 () ;
return error ;
}
static inline unsigned long long
F_15 ( const T_2 V_8 , const struct V_14 * V_15 )
{
unsigned long long V_16 ;
V_16 = 0 ;
if ( F_8 ( V_8 ) == V_17 ) {
V_16 = ( unsigned long long ) V_15 -> V_18 * V_19 + V_15 -> V_20 ;
} else {
V_16 = F_16 ( F_17 ( V_15 ) ) ;
}
return V_16 ;
}
static void F_18 ( const T_2 V_8 ,
unsigned long long V_21 ,
struct V_14 * V_15 )
{
if ( F_8 ( V_8 ) == V_17 )
* V_15 = F_19 ( V_21 ) ;
else
F_20 ( ( V_22 T_1 ) V_21 , V_15 ) ;
}
static void F_21 ( struct V_23 * V_24 ,
unsigned long long V_25 )
{
int V_26 ;
unsigned long long V_27 , V_28 ;
if ( V_24 -> V_29 . V_30 . V_28 == 0 )
return;
if ( V_25 < V_24 -> V_29 . V_30 . V_21 )
return;
V_28 = V_24 -> V_29 . V_30 . V_28 ;
V_27 = V_25 + V_28 - V_24 -> V_29 . V_30 . V_21 ;
for ( V_26 = 0 ; V_28 < V_27 - V_28 ; V_26 ++ )
V_28 = V_28 << 1 ;
for (; V_26 >= 0 ; V_28 >>= 1 , V_26 -- ) {
if ( V_27 < V_28 )
continue;
V_24 -> V_29 . V_30 . V_21 += V_28 ;
V_24 -> V_31 += 1 << V_26 ;
V_27 -= V_28 ;
}
}
static inline int F_22 ( const struct V_32 * V_4 )
{
if ( ! V_4 -> V_33 && ! V_4 -> V_34 && ! V_4 -> V_35 )
return 1 ;
return 0 ;
}
static inline unsigned long long F_23 ( struct V_1 * V_9 )
{
T_1 V_33 , V_34 ;
V_32 ( V_9 , & V_33 , & V_34 ) ;
return F_16 ( V_33 + V_34 ) ;
}
static inline unsigned long long F_24 ( struct V_1 * V_9 )
{
T_1 V_33 ;
V_32 ( V_9 , & V_33 , NULL ) ;
return F_16 ( V_33 ) ;
}
static int
F_25 ( const T_2 V_8 , struct V_14 * V_15 )
{
int error = F_6 ( V_8 ) ;
if ( ! error ) {
V_15 -> V_18 = 0 ;
V_15 -> V_20 = ( ( V_19 + V_36 - 1 ) / V_36 ) ;
if ( F_8 ( V_8 ) == V_17 ) {
V_15 -> V_20 = 1 ;
}
}
return error ;
}
static int
F_26 ( const T_2 V_8 , const struct V_14 * V_15 )
{
int error = F_6 ( V_8 ) ;
if ( error == 0 ) {
error = - V_37 ;
}
return error ;
}
static int F_27 ( const T_2 V_8 , struct V_1 * V_9 ,
unsigned long long * V_38 )
{
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
* V_38 = F_23 ( V_9 ) ;
break;
case V_39 :
* V_38 = F_24 ( V_9 ) ;
break;
case V_17 :
* V_38 = F_28 ( V_9 ) ;
break;
}
return 0 ;
}
static inline void F_29 ( T_4 * V_4 , T_5 V_40 )
{
T_5 V_41 ;
V_42:
V_41 = F_30 ( V_4 ) ;
if ( V_40 > V_41 ) {
if ( F_31 ( V_4 , V_41 , V_40 ) != V_41 )
goto V_42;
}
}
static void F_32 ( struct V_43 * V_44 , struct V_32 * V_45 )
{
F_29 ( & V_44 -> V_33 , V_45 -> V_33 ) ;
F_29 ( & V_44 -> V_34 , V_45 -> V_34 ) ;
F_29 ( & V_44 -> V_35 , V_45 -> V_35 ) ;
}
static inline void F_33 ( struct V_32 * V_46 ,
struct V_43 * V_47 )
{
V_46 -> V_33 = F_30 ( & V_47 -> V_33 ) ;
V_46 -> V_34 = F_30 ( & V_47 -> V_34 ) ;
V_46 -> V_35 = F_30 ( & V_47 -> V_35 ) ;
}
void F_34 ( struct V_1 * V_48 , struct V_32 * V_46 )
{
struct F_34 * V_49 = & V_48 -> signal -> V_49 ;
struct V_32 V_45 ;
if ( ! F_35 ( V_49 -> V_50 ) ) {
F_36 ( V_48 , & V_45 ) ;
F_32 ( & V_49 -> V_44 , & V_45 ) ;
F_37 ( V_49 -> V_50 , true ) ;
}
F_33 ( V_46 , & V_49 -> V_44 ) ;
}
static int F_38 ( const T_2 V_8 ,
struct V_1 * V_9 ,
unsigned long long * V_38 )
{
struct V_32 V_4 ;
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
F_36 ( V_9 , & V_4 ) ;
* V_38 = F_16 ( V_4 . V_33 + V_4 . V_34 ) ;
break;
case V_39 :
F_36 ( V_9 , & V_4 ) ;
* V_38 = F_16 ( V_4 . V_33 ) ;
break;
case V_17 :
F_36 ( V_9 , & V_4 ) ;
* V_38 = V_4 . V_35 ;
break;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_48 ,
const T_2 V_8 ,
struct V_14 * V_15 )
{
int V_51 = - V_12 ;
unsigned long long V_52 ;
if ( F_11 ( V_8 ) ) {
if ( F_12 ( V_48 , V_13 ) )
V_51 = F_27 ( V_8 , V_48 , & V_52 ) ;
} else {
if ( V_48 == V_13 || F_40 ( V_48 ) )
V_51 = F_38 ( V_8 , V_48 , & V_52 ) ;
}
if ( ! V_51 )
F_18 ( V_8 , V_52 , V_15 ) ;
return V_51 ;
}
static int F_41 ( const T_2 V_8 , struct V_14 * V_15 )
{
const T_3 V_10 = F_7 ( V_8 ) ;
int V_51 = - V_12 ;
if ( V_10 == 0 ) {
V_51 = F_39 ( V_13 , V_8 , V_15 ) ;
} else {
struct V_1 * V_9 ;
F_9 () ;
V_9 = F_10 ( V_10 ) ;
if ( V_9 )
V_51 = F_39 ( V_9 , V_8 , V_15 ) ;
F_14 () ;
}
return V_51 ;
}
static int F_42 ( struct V_23 * V_53 )
{
int V_16 = 0 ;
const T_3 V_10 = F_7 ( V_53 -> V_54 ) ;
struct V_1 * V_9 ;
if ( F_8 ( V_53 -> V_54 ) >= V_11 )
return - V_12 ;
F_43 ( & V_53 -> V_29 . V_30 . V_55 ) ;
F_9 () ;
if ( F_11 ( V_53 -> V_54 ) ) {
if ( V_10 == 0 ) {
V_9 = V_13 ;
} else {
V_9 = F_10 ( V_10 ) ;
if ( V_9 && ! F_12 ( V_9 , V_13 ) )
V_9 = NULL ;
}
} else {
if ( V_10 == 0 ) {
V_9 = V_13 -> V_56 ;
} else {
V_9 = F_10 ( V_10 ) ;
if ( V_9 && ! F_13 ( V_9 ) )
V_9 = NULL ;
}
}
V_53 -> V_29 . V_30 . V_2 = V_9 ;
if ( V_9 ) {
F_44 ( V_9 ) ;
} else {
V_16 = - V_12 ;
}
F_14 () ;
return V_16 ;
}
static int F_45 ( struct V_23 * V_24 )
{
int V_16 = 0 ;
unsigned long V_57 ;
struct V_58 * V_5 ;
struct V_1 * V_9 = V_24 -> V_29 . V_30 . V_2 ;
F_46 ( V_9 == NULL ) ;
V_5 = F_47 ( V_9 , & V_57 ) ;
if ( F_48 ( V_5 == NULL ) ) {
F_46 ( ! F_49 ( & V_24 -> V_29 . V_30 . V_55 ) ) ;
} else {
if ( V_24 -> V_29 . V_30 . V_59 )
V_16 = V_60 ;
else
F_50 ( & V_24 -> V_29 . V_30 . V_55 ) ;
F_51 ( V_9 , & V_57 ) ;
}
if ( ! V_16 )
F_52 ( V_9 ) ;
return V_16 ;
}
static void F_53 ( struct V_61 * V_62 )
{
struct V_63 * V_24 , * V_64 ;
F_54 (timer, next, head, entry)
F_55 ( & V_24 -> V_55 ) ;
}
static void F_56 ( struct V_61 * V_62 )
{
F_53 ( V_62 ) ;
F_53 ( ++ V_62 ) ;
F_53 ( ++ V_62 ) ;
}
void F_57 ( struct V_1 * V_48 )
{
F_58 ( ( const void * ) & V_48 -> V_65 . V_35 ,
sizeof( unsigned long long ) ) ;
F_56 ( V_48 -> V_66 ) ;
}
void F_59 ( struct V_1 * V_48 )
{
F_56 ( V_48 -> signal -> V_66 ) ;
}
static inline int F_60 ( T_1 V_21 , T_1 V_67 )
{
return V_21 == 0 || V_21 > V_67 ;
}
static void F_61 ( struct V_23 * V_24 )
{
struct V_1 * V_9 = V_24 -> V_29 . V_30 . V_2 ;
struct V_61 * V_62 , * V_68 ;
struct V_32 * V_69 ;
struct V_63 * const V_70 = & V_24 -> V_29 . V_30 ;
struct V_63 * V_64 ;
if ( F_11 ( V_24 -> V_54 ) ) {
V_62 = V_9 -> V_66 ;
V_69 = & V_9 -> V_69 ;
} else {
V_62 = V_9 -> signal -> V_66 ;
V_69 = & V_9 -> signal -> V_69 ;
}
V_62 += F_8 ( V_24 -> V_54 ) ;
V_68 = V_62 ;
F_62 (next, head, entry) {
if ( V_70 -> V_21 < V_64 -> V_21 )
break;
V_68 = & V_64 -> V_55 ;
}
F_63 ( & V_70 -> V_55 , V_68 ) ;
if ( V_68 == V_62 ) {
unsigned long long exp = V_70 -> V_21 ;
switch ( F_8 ( V_24 -> V_54 ) ) {
case V_7 :
if ( F_60 ( V_69 -> V_71 , F_64 ( exp ) ) )
V_69 -> V_71 = F_64 ( exp ) ;
break;
case V_39 :
if ( F_60 ( V_69 -> V_72 , F_64 ( exp ) ) )
V_69 -> V_72 = F_64 ( exp ) ;
break;
case V_17 :
if ( V_69 -> V_73 == 0 ||
V_69 -> V_73 > exp )
V_69 -> V_73 = exp ;
break;
}
if ( F_11 ( V_24 -> V_54 ) )
F_65 ( V_9 , V_74 ) ;
else
F_66 ( V_9 -> signal , V_74 ) ;
}
}
static void F_67 ( struct V_23 * V_24 )
{
if ( ( V_24 -> V_75 & ~ V_76 ) == V_77 ) {
V_24 -> V_29 . V_30 . V_21 = 0 ;
} else if ( F_48 ( V_24 -> V_78 == NULL ) ) {
F_68 ( V_24 -> V_79 ) ;
V_24 -> V_29 . V_30 . V_21 = 0 ;
} else if ( V_24 -> V_29 . V_30 . V_28 == 0 ) {
F_69 ( V_24 , 0 ) ;
V_24 -> V_29 . V_30 . V_21 = 0 ;
} else if ( F_69 ( V_24 , ++ V_24 -> V_80 ) ) {
F_70 ( V_24 ) ;
}
}
static int F_71 ( const T_2 V_8 ,
struct V_1 * V_9 ,
unsigned long long * V_38 )
{
struct V_32 V_4 ;
F_34 ( V_9 , & V_4 ) ;
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
* V_38 = F_16 ( V_4 . V_33 + V_4 . V_34 ) ;
break;
case V_39 :
* V_38 = F_16 ( V_4 . V_33 ) ;
break;
case V_17 :
* V_38 = V_4 . V_35 ;
break;
}
return 0 ;
}
static int F_72 ( struct V_23 * V_24 , int V_81 ,
struct V_82 * V_83 , struct V_82 * V_84 )
{
unsigned long V_57 ;
struct V_58 * V_5 ;
struct V_1 * V_9 = V_24 -> V_29 . V_30 . V_2 ;
unsigned long long V_85 , V_86 , V_87 , V_88 ;
int V_16 ;
F_46 ( V_9 == NULL ) ;
V_86 = F_15 ( V_24 -> V_54 , & V_83 -> V_89 ) ;
V_5 = F_47 ( V_9 , & V_57 ) ;
if ( F_48 ( V_5 == NULL ) ) {
return - V_90 ;
}
F_46 ( ! F_73 () ) ;
V_16 = 0 ;
V_87 = V_24 -> V_29 . V_30 . V_28 ;
V_85 = V_24 -> V_29 . V_30 . V_21 ;
if ( F_48 ( V_24 -> V_29 . V_30 . V_59 ) ) {
V_24 -> V_29 . V_30 . V_59 = - 1 ;
V_16 = V_60 ;
} else
F_55 ( & V_24 -> V_29 . V_30 . V_55 ) ;
if ( F_11 ( V_24 -> V_54 ) ) {
F_27 ( V_24 -> V_54 , V_9 , & V_88 ) ;
} else {
F_71 ( V_24 -> V_54 , V_9 , & V_88 ) ;
}
if ( V_84 ) {
if ( V_85 == 0 ) {
V_84 -> V_89 . V_18 = 0 ;
V_84 -> V_89 . V_20 = 0 ;
} else {
F_21 ( V_24 , V_88 ) ;
if ( V_88 < V_24 -> V_29 . V_30 . V_21 ) {
V_85 = V_24 -> V_29 . V_30 . V_21 - V_88 ;
F_18 ( V_24 -> V_54 ,
V_85 ,
& V_84 -> V_89 ) ;
} else {
V_84 -> V_89 . V_20 = 1 ;
V_84 -> V_89 . V_18 = 0 ;
}
}
}
if ( F_48 ( V_16 ) ) {
F_51 ( V_9 , & V_57 ) ;
goto V_91;
}
if ( V_86 != 0 && ! ( V_81 & V_92 ) ) {
V_86 += V_88 ;
}
V_24 -> V_29 . V_30 . V_21 = V_86 ;
if ( V_86 != 0 && V_88 < V_86 ) {
F_61 ( V_24 ) ;
}
F_51 ( V_9 , & V_57 ) ;
V_24 -> V_29 . V_30 . V_28 = F_15 ( V_24 -> V_54 ,
& V_83 -> V_93 ) ;
V_24 -> V_80 = ( V_24 -> V_80 + 2 ) &
~ V_94 ;
V_24 -> V_95 = 0 ;
V_24 -> V_31 = - 1 ;
if ( V_86 != 0 && ! ( V_88 < V_86 ) ) {
F_67 ( V_24 ) ;
}
V_16 = 0 ;
V_91:
if ( V_84 ) {
F_18 ( V_24 -> V_54 ,
V_87 , & V_84 -> V_93 ) ;
}
return V_16 ;
}
static void F_74 ( struct V_23 * V_24 , struct V_82 * V_96 )
{
unsigned long long V_25 ;
struct V_1 * V_9 = V_24 -> V_29 . V_30 . V_2 ;
F_46 ( V_9 == NULL ) ;
F_18 ( V_24 -> V_54 ,
V_24 -> V_29 . V_30 . V_28 , & V_96 -> V_93 ) ;
if ( V_24 -> V_29 . V_30 . V_21 == 0 ) {
V_96 -> V_89 . V_18 = V_96 -> V_89 . V_20 = 0 ;
return;
}
if ( F_11 ( V_24 -> V_54 ) ) {
F_27 ( V_24 -> V_54 , V_9 , & V_25 ) ;
} else {
struct V_58 * V_5 ;
unsigned long V_57 ;
V_5 = F_47 ( V_9 , & V_57 ) ;
if ( F_48 ( V_5 == NULL ) ) {
V_24 -> V_29 . V_30 . V_21 = 0 ;
F_18 ( V_24 -> V_54 , V_24 -> V_29 . V_30 . V_21 ,
& V_96 -> V_89 ) ;
} else {
F_71 ( V_24 -> V_54 , V_9 , & V_25 ) ;
F_51 ( V_9 , & V_57 ) ;
}
}
if ( V_25 < V_24 -> V_29 . V_30 . V_21 ) {
F_18 ( V_24 -> V_54 ,
V_24 -> V_29 . V_30 . V_21 - V_25 ,
& V_96 -> V_89 ) ;
} else {
V_96 -> V_89 . V_20 = 1 ;
V_96 -> V_89 . V_18 = 0 ;
}
}
static unsigned long long
F_75 ( struct V_61 * V_97 ,
struct V_61 * V_59 ,
unsigned long long V_98 )
{
int V_99 = 20 ;
while ( ! F_49 ( V_97 ) ) {
struct V_63 * V_100 ;
V_100 = F_76 ( V_97 , struct V_63 , V_55 ) ;
if ( ! -- V_99 || V_98 < V_100 -> V_21 )
return V_100 -> V_21 ;
V_100 -> V_59 = 1 ;
F_77 ( & V_100 -> V_55 , V_59 ) ;
}
return 0 ;
}
static void F_78 ( struct V_1 * V_48 ,
struct V_61 * V_59 )
{
struct V_61 * V_97 = V_48 -> V_66 ;
struct V_101 * const V_102 = V_48 -> signal ;
struct V_32 * V_103 = & V_48 -> V_69 ;
unsigned long long V_21 ;
unsigned long V_104 ;
if ( F_22 ( & V_48 -> V_69 ) )
return;
V_21 = F_75 ( V_97 , V_59 , F_23 ( V_48 ) ) ;
V_103 -> V_71 = F_64 ( V_21 ) ;
V_21 = F_75 ( ++ V_97 , V_59 , F_24 ( V_48 ) ) ;
V_103 -> V_72 = F_64 ( V_21 ) ;
V_103 -> V_73 = F_75 ( ++ V_97 , V_59 ,
V_48 -> V_65 . V_35 ) ;
V_104 = F_35 ( V_102 -> V_105 [ V_106 ] . V_107 ) ;
if ( V_104 != V_108 ) {
unsigned long V_109 =
F_35 ( V_102 -> V_105 [ V_106 ] . V_110 ) ;
if ( V_109 != V_108 &&
V_48 -> V_111 . V_112 > F_79 ( V_109 , V_113 / V_36 ) ) {
F_80 ( V_114 , V_115 , V_48 ) ;
return;
}
if ( V_48 -> V_111 . V_112 > F_79 ( V_104 , V_113 / V_36 ) ) {
if ( V_104 < V_109 ) {
V_104 += V_113 ;
V_102 -> V_105 [ V_106 ] . V_107 = V_104 ;
}
F_81 ( V_116
L_1 ,
V_48 -> V_117 , F_82 ( V_48 ) ) ;
F_80 ( V_118 , V_115 , V_48 ) ;
}
}
if ( F_22 ( V_103 ) )
F_83 ( V_48 , V_74 ) ;
}
static inline void F_84 ( struct V_101 * V_102 )
{
struct F_34 * V_49 = & V_102 -> V_49 ;
F_37 ( V_49 -> V_50 , false ) ;
F_85 ( V_102 , V_74 ) ;
}
static void F_86 ( struct V_1 * V_48 , struct V_119 * V_29 ,
unsigned long long * V_21 ,
unsigned long long V_120 , int V_121 )
{
if ( ! V_29 -> V_21 )
return;
if ( V_120 >= V_29 -> V_21 ) {
if ( V_29 -> V_28 ) {
V_29 -> V_21 += V_29 -> V_28 ;
V_29 -> error += V_29 -> V_122 ;
if ( V_29 -> error >= V_123 ) {
V_29 -> V_21 -= V_124 ;
V_29 -> error -= V_123 ;
}
} else {
V_29 -> V_21 = 0 ;
}
F_87 ( V_121 == V_125 ?
V_126 : V_127 ,
V_48 -> signal -> V_128 , V_120 ) ;
F_80 ( V_121 , V_115 , V_48 ) ;
}
if ( V_29 -> V_21 && ( ! * V_21 || V_29 -> V_21 < * V_21 ) ) {
* V_21 = V_29 -> V_21 ;
}
}
static void F_88 ( struct V_1 * V_48 ,
struct V_61 * V_59 )
{
struct V_101 * const V_102 = V_48 -> signal ;
unsigned long long V_33 , V_129 , V_130 , V_131 ;
unsigned long long V_132 , V_133 ;
struct V_61 * V_97 = V_102 -> V_66 ;
struct V_32 V_4 ;
unsigned long V_104 ;
if ( ! F_35 ( V_48 -> signal -> V_49 . V_50 ) )
return;
V_102 -> V_49 . V_134 = true ;
F_34 ( V_48 , & V_4 ) ;
V_33 = F_16 ( V_4 . V_33 ) ;
V_129 = V_33 + F_16 ( V_4 . V_34 ) ;
V_132 = V_4 . V_35 ;
V_131 = F_75 ( V_97 , V_59 , V_129 ) ;
V_130 = F_75 ( ++ V_97 , V_59 , V_33 ) ;
V_133 = F_75 ( ++ V_97 , V_59 , V_132 ) ;
F_86 ( V_48 , & V_102 -> V_29 [ V_7 ] , & V_131 , V_129 ,
V_125 ) ;
F_86 ( V_48 , & V_102 -> V_29 [ V_39 ] , & V_130 , V_33 ,
V_135 ) ;
V_104 = F_35 ( V_102 -> V_105 [ V_136 ] . V_107 ) ;
if ( V_104 != V_108 ) {
unsigned long V_137 = F_89 ( V_129 ) ;
unsigned long V_109 =
F_35 ( V_102 -> V_105 [ V_136 ] . V_110 ) ;
T_1 V_138 ;
if ( V_137 >= V_109 ) {
F_80 ( V_114 , V_115 , V_48 ) ;
return;
}
if ( V_137 >= V_104 ) {
F_80 ( V_118 , V_115 , V_48 ) ;
if ( V_104 < V_109 ) {
V_104 ++ ;
V_102 -> V_105 [ V_136 ] . V_107 = V_104 ;
}
}
V_138 = F_2 ( V_104 ) ;
if ( ! V_131 || V_138 < V_131 ) {
V_131 = V_138 ;
}
}
V_102 -> V_69 . V_71 = F_64 ( V_131 ) ;
V_102 -> V_69 . V_72 = F_64 ( V_130 ) ;
V_102 -> V_69 . V_73 = V_133 ;
if ( F_22 ( & V_102 -> V_69 ) )
F_84 ( V_102 ) ;
V_102 -> V_49 . V_134 = false ;
}
void F_70 ( struct V_23 * V_24 )
{
struct V_58 * V_5 ;
unsigned long V_57 ;
struct V_1 * V_9 = V_24 -> V_29 . V_30 . V_2 ;
unsigned long long V_25 ;
F_46 ( V_9 == NULL ) ;
if ( F_11 ( V_24 -> V_54 ) ) {
F_27 ( V_24 -> V_54 , V_9 , & V_25 ) ;
F_21 ( V_24 , V_25 ) ;
if ( F_48 ( V_9 -> V_139 ) )
goto V_91;
V_5 = F_47 ( V_9 , & V_57 ) ;
if ( ! V_5 )
goto V_91;
} else {
V_5 = F_47 ( V_9 , & V_57 ) ;
if ( F_48 ( V_5 == NULL ) ) {
V_24 -> V_29 . V_30 . V_21 = 0 ;
goto V_91;
} else if ( F_48 ( V_9 -> V_139 ) && F_90 ( V_9 ) ) {
F_51 ( V_9 , & V_57 ) ;
goto V_91;
}
F_71 ( V_24 -> V_54 , V_9 , & V_25 ) ;
F_21 ( V_24 , V_25 ) ;
}
F_46 ( ! F_73 () ) ;
F_61 ( V_24 ) ;
F_51 ( V_9 , & V_57 ) ;
V_91:
V_24 -> V_95 = V_24 -> V_31 ;
V_24 -> V_31 = - 1 ;
++ V_24 -> V_80 ;
}
static inline int F_91 ( const struct V_32 * V_38 ,
const struct V_32 * V_21 )
{
if ( V_21 -> V_33 && V_38 -> V_33 >= V_21 -> V_33 )
return 1 ;
if ( V_21 -> V_34 && V_38 -> V_33 + V_38 -> V_34 >= V_21 -> V_34 )
return 1 ;
if ( V_21 -> V_35 != 0 &&
V_38 -> V_35 >= V_21 -> V_35 )
return 1 ;
return 0 ;
}
static inline int F_92 ( struct V_1 * V_48 )
{
struct V_101 * V_102 ;
if ( ! F_22 ( & V_48 -> V_69 ) ) {
struct V_32 V_140 ;
V_32 ( V_48 , & V_140 . V_33 , & V_140 . V_34 ) ;
V_140 . V_35 = V_48 -> V_65 . V_35 ;
if ( F_91 ( & V_140 , & V_48 -> V_69 ) )
return 1 ;
}
V_102 = V_48 -> signal ;
if ( F_35 ( V_102 -> V_49 . V_50 ) &&
! F_35 ( V_102 -> V_49 . V_134 ) ) {
struct V_32 V_141 ;
F_33 ( & V_141 , & V_102 -> V_49 . V_44 ) ;
if ( F_91 ( & V_141 , & V_102 -> V_69 ) )
return 1 ;
}
return 0 ;
}
void F_93 ( struct V_1 * V_48 )
{
F_94 ( V_59 ) ;
struct V_23 * V_24 , * V_64 ;
unsigned long V_57 ;
F_46 ( ! F_73 () ) ;
if ( ! F_92 ( V_48 ) )
return;
if ( ! F_47 ( V_48 , & V_57 ) )
return;
F_78 ( V_48 , & V_59 ) ;
F_88 ( V_48 , & V_59 ) ;
F_51 ( V_48 , & V_57 ) ;
F_54 (timer, next, &firing, it.cpu.entry) {
int V_142 ;
F_95 ( & V_24 -> V_143 ) ;
F_55 ( & V_24 -> V_29 . V_30 . V_55 ) ;
V_142 = V_24 -> V_29 . V_30 . V_59 ;
V_24 -> V_29 . V_30 . V_59 = 0 ;
if ( F_96 ( V_142 >= 0 ) )
F_67 ( V_24 ) ;
F_97 ( & V_24 -> V_143 ) ;
}
}
void F_4 ( struct V_1 * V_48 , unsigned int V_144 ,
T_1 * V_145 , T_1 * V_146 )
{
unsigned long long V_25 ;
F_46 ( V_144 == V_17 ) ;
F_71 ( V_144 , V_48 , & V_25 ) ;
if ( V_146 ) {
if ( * V_146 ) {
if ( * V_146 <= V_25 ) {
* V_146 = V_124 ;
} else {
* V_146 -= V_25 ;
}
}
if ( ! * V_145 )
return;
* V_145 += V_25 ;
}
switch ( V_144 ) {
case V_7 :
if ( F_60 ( V_48 -> signal -> V_69 . V_71 , * V_145 ) )
V_48 -> signal -> V_69 . V_71 = * V_145 ;
break;
case V_39 :
if ( F_60 ( V_48 -> signal -> V_69 . V_72 , * V_145 ) )
V_48 -> signal -> V_69 . V_72 = * V_145 ;
break;
}
F_66 ( V_48 -> signal , V_74 ) ;
}
static int F_98 ( const T_2 V_8 , int V_57 ,
struct V_14 * V_147 , struct V_82 * V_29 )
{
struct V_23 V_24 ;
int error ;
memset ( & V_24 , 0 , sizeof V_24 ) ;
F_99 ( & V_24 . V_143 ) ;
V_24 . V_54 = V_8 ;
V_24 . V_31 = - 1 ;
error = F_42 ( & V_24 ) ;
V_24 . V_79 = V_13 ;
if ( ! error ) {
static struct V_82 V_148 ;
memset ( V_29 , 0 , sizeof *V_29 ) ;
V_29 -> V_89 = * V_147 ;
F_3 ( & V_24 . V_143 ) ;
error = F_72 ( & V_24 , V_57 , V_29 , NULL ) ;
if ( error ) {
F_5 ( & V_24 . V_143 ) ;
return error ;
}
while ( ! F_100 ( V_13 ) ) {
if ( V_24 . V_29 . V_30 . V_21 == 0 ) {
F_45 ( & V_24 ) ;
F_5 ( & V_24 . V_143 ) ;
return 0 ;
}
F_101 ( V_149 ) ;
F_5 ( & V_24 . V_143 ) ;
F_102 () ;
F_3 ( & V_24 . V_143 ) ;
}
F_18 ( V_8 , V_24 . V_29 . V_30 . V_21 , V_147 ) ;
error = F_72 ( & V_24 , 0 , & V_148 , V_29 ) ;
if ( ! error ) {
F_45 ( & V_24 ) ;
}
F_5 ( & V_24 . V_143 ) ;
while ( error == V_60 ) {
F_3 ( & V_24 . V_143 ) ;
error = F_45 ( & V_24 ) ;
F_5 ( & V_24 . V_143 ) ;
}
if ( ( V_29 -> V_89 . V_18 | V_29 -> V_89 . V_20 ) == 0 ) {
return 0 ;
}
error = - V_150 ;
}
return error ;
}
static int F_103 ( const T_2 V_8 , int V_57 ,
struct V_14 * V_147 , struct V_14 T_6 * V_151 )
{
struct V_152 * V_152 = & V_13 -> V_152 ;
struct V_82 V_29 ;
int error ;
if ( F_11 ( V_8 ) &&
( F_7 ( V_8 ) == 0 ||
F_7 ( V_8 ) == V_13 -> V_10 ) )
return - V_12 ;
error = F_98 ( V_8 , V_57 , V_147 , & V_29 ) ;
if ( error == - V_150 ) {
if ( V_57 & V_92 )
return - V_153 ;
if ( V_151 && F_104 ( V_151 , & V_29 . V_89 , sizeof *V_151 ) )
return - V_154 ;
V_152 -> V_155 = V_156 ;
V_152 -> V_157 . V_158 = V_8 ;
V_152 -> V_157 . V_151 = V_151 ;
V_152 -> V_157 . V_21 = F_105 ( V_147 ) ;
}
return error ;
}
static long V_156 ( struct V_152 * V_152 )
{
T_2 V_8 = V_152 -> V_157 . V_158 ;
struct V_14 V_100 ;
struct V_82 V_29 ;
int error ;
V_100 = F_19 ( V_152 -> V_157 . V_21 ) ;
error = F_98 ( V_8 , V_92 , & V_100 , & V_29 ) ;
if ( error == - V_150 ) {
struct V_14 T_6 * V_151 = V_152 -> V_157 . V_151 ;
if ( V_151 && F_104 ( V_151 , & V_29 . V_89 , sizeof *V_151 ) )
return - V_154 ;
V_152 -> V_157 . V_21 = F_105 ( & V_100 ) ;
}
return error ;
}
static int F_106 ( const T_2 V_8 ,
struct V_14 * V_15 )
{
return F_25 ( V_159 , V_15 ) ;
}
static int F_107 ( const T_2 V_8 ,
struct V_14 * V_15 )
{
return F_41 ( V_159 , V_15 ) ;
}
static int F_108 ( struct V_23 * V_24 )
{
V_24 -> V_54 = V_159 ;
return F_42 ( V_24 ) ;
}
static int F_109 ( const T_2 V_8 , int V_57 ,
struct V_14 * V_147 ,
struct V_14 T_6 * V_151 )
{
return F_103 ( V_159 , V_57 , V_147 , V_151 ) ;
}
static long F_110 ( struct V_152 * V_152 )
{
return - V_12 ;
}
static int F_111 ( const T_2 V_8 ,
struct V_14 * V_15 )
{
return F_25 ( V_160 , V_15 ) ;
}
static int F_112 ( const T_2 V_8 ,
struct V_14 * V_15 )
{
return F_41 ( V_160 , V_15 ) ;
}
static int F_113 ( struct V_23 * V_24 )
{
V_24 -> V_54 = V_160 ;
return F_42 ( V_24 ) ;
}
static T_7 int F_114 ( void )
{
struct V_161 V_162 = {
. V_163 = F_106 ,
. V_164 = F_107 ,
. V_165 = F_108 ,
. V_166 = F_109 ,
. V_167 = F_110 ,
} ;
struct V_161 V_168 = {
. V_163 = F_111 ,
. V_164 = F_112 ,
. V_165 = F_113 ,
} ;
struct V_14 V_169 ;
F_115 ( V_170 , & V_162 ) ;
F_115 ( V_171 , & V_168 ) ;
F_20 ( V_124 , & V_169 ) ;
V_123 = V_169 . V_20 ;
F_116 ( V_169 . V_18 != 0 ) ;
return 0 ;
}
