void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 V_4 = V_3 * V_5 ;
F_2 ( & V_2 -> V_6 -> V_7 ) ;
F_3 ( V_2 , V_8 , & V_4 , NULL ) ;
F_4 ( & V_2 -> V_6 -> V_7 ) ;
}
static int F_5 ( const T_2 V_9 )
{
int error = 0 ;
struct V_1 * V_10 ;
const T_3 V_11 = F_6 ( V_9 ) ;
if ( F_7 ( V_9 ) >= V_12 )
return - V_13 ;
if ( V_11 == 0 )
return 0 ;
F_8 () ;
V_10 = F_9 ( V_11 ) ;
if ( ! V_10 || ! ( F_10 ( V_9 ) ?
F_11 ( V_10 , V_14 ) : F_12 ( V_10 ) ) ) {
error = - V_13 ;
}
F_13 () ;
return error ;
}
static void F_14 ( struct V_15 * V_16 , T_1 V_17 )
{
int V_18 ;
T_1 V_19 , V_20 ;
if ( V_16 -> V_21 . V_22 . V_20 == 0 )
return;
if ( V_17 < V_16 -> V_21 . V_22 . V_23 )
return;
V_20 = V_16 -> V_21 . V_22 . V_20 ;
V_19 = V_17 + V_20 - V_16 -> V_21 . V_22 . V_23 ;
for ( V_18 = 0 ; V_20 < V_19 - V_20 ; V_18 ++ )
V_20 = V_20 << 1 ;
for (; V_18 >= 0 ; V_20 >>= 1 , V_18 -- ) {
if ( V_19 < V_20 )
continue;
V_16 -> V_21 . V_22 . V_23 += V_20 ;
V_16 -> V_24 += 1 << V_18 ;
V_19 -= V_20 ;
}
}
static inline int F_15 ( const struct V_25 * V_26 )
{
if ( ! V_26 -> V_27 && ! V_26 -> V_28 && ! V_26 -> V_29 )
return 1 ;
return 0 ;
}
static inline T_1 F_16 ( struct V_1 * V_10 )
{
T_1 V_27 , V_28 ;
V_25 ( V_10 , & V_27 , & V_28 ) ;
return V_27 + V_28 ;
}
static inline T_1 F_17 ( struct V_1 * V_10 )
{
T_1 V_27 , V_28 ;
V_25 ( V_10 , & V_27 , & V_28 ) ;
return V_27 ;
}
static int
F_18 ( const T_2 V_9 , struct V_30 * V_31 )
{
int error = F_5 ( V_9 ) ;
if ( ! error ) {
V_31 -> V_32 = 0 ;
V_31 -> V_33 = ( ( V_5 + V_34 - 1 ) / V_34 ) ;
if ( F_7 ( V_9 ) == V_35 ) {
V_31 -> V_33 = 1 ;
}
}
return error ;
}
static int
F_19 ( const T_2 V_9 , const struct V_30 * V_31 )
{
int error = F_5 ( V_9 ) ;
if ( error == 0 ) {
error = - V_36 ;
}
return error ;
}
static int F_20 ( const T_2 V_9 ,
struct V_1 * V_10 , T_1 * V_37 )
{
switch ( F_7 ( V_9 ) ) {
default:
return - V_13 ;
case V_8 :
* V_37 = F_16 ( V_10 ) ;
break;
case V_38 :
* V_37 = F_17 ( V_10 ) ;
break;
case V_35 :
* V_37 = F_21 ( V_10 ) ;
break;
}
return 0 ;
}
static inline void F_22 ( T_4 * V_26 , T_1 V_39 )
{
T_1 V_40 ;
V_41:
V_40 = F_23 ( V_26 ) ;
if ( V_39 > V_40 ) {
if ( F_24 ( V_26 , V_40 , V_39 ) != V_40 )
goto V_41;
}
}
static void F_25 ( struct V_42 * V_43 , struct V_25 * V_44 )
{
F_22 ( & V_43 -> V_27 , V_44 -> V_27 ) ;
F_22 ( & V_43 -> V_28 , V_44 -> V_28 ) ;
F_22 ( & V_43 -> V_29 , V_44 -> V_29 ) ;
}
static inline void F_26 ( struct V_25 * V_45 ,
struct V_42 * V_46 )
{
V_45 -> V_27 = F_23 ( & V_46 -> V_27 ) ;
V_45 -> V_28 = F_23 ( & V_46 -> V_28 ) ;
V_45 -> V_29 = F_23 ( & V_46 -> V_29 ) ;
}
void F_27 ( struct V_1 * V_47 , struct V_25 * V_45 )
{
struct F_27 * V_48 = & V_47 -> signal -> V_48 ;
struct V_25 V_44 ;
if ( ! F_28 ( V_48 -> V_49 ) ) {
F_29 ( V_47 , & V_44 ) ;
F_25 ( & V_48 -> V_43 , & V_44 ) ;
F_30 ( V_48 -> V_49 , true ) ;
}
F_26 ( V_45 , & V_48 -> V_43 ) ;
}
static int F_31 ( const T_2 V_9 ,
struct V_1 * V_10 ,
T_1 * V_37 )
{
struct V_25 V_26 ;
switch ( F_7 ( V_9 ) ) {
default:
return - V_13 ;
case V_8 :
F_29 ( V_10 , & V_26 ) ;
* V_37 = V_26 . V_27 + V_26 . V_28 ;
break;
case V_38 :
F_29 ( V_10 , & V_26 ) ;
* V_37 = V_26 . V_27 ;
break;
case V_35 :
F_29 ( V_10 , & V_26 ) ;
* V_37 = V_26 . V_29 ;
break;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_47 ,
const T_2 V_9 ,
struct V_30 * V_31 )
{
int V_50 = - V_13 ;
T_1 V_51 ;
if ( F_10 ( V_9 ) ) {
if ( F_11 ( V_47 , V_14 ) )
V_50 = F_20 ( V_9 , V_47 , & V_51 ) ;
} else {
if ( V_47 == V_14 || F_33 ( V_47 ) )
V_50 = F_31 ( V_9 , V_47 , & V_51 ) ;
}
if ( ! V_50 )
* V_31 = F_34 ( V_51 ) ;
return V_50 ;
}
static int F_35 ( const T_2 V_9 , struct V_30 * V_31 )
{
const T_3 V_11 = F_6 ( V_9 ) ;
int V_50 = - V_13 ;
if ( V_11 == 0 ) {
V_50 = F_32 ( V_14 , V_9 , V_31 ) ;
} else {
struct V_1 * V_10 ;
F_8 () ;
V_10 = F_9 ( V_11 ) ;
if ( V_10 )
V_50 = F_32 ( V_10 , V_9 , V_31 ) ;
F_13 () ;
}
return V_50 ;
}
static int F_36 ( struct V_15 * V_52 )
{
int V_53 = 0 ;
const T_3 V_11 = F_6 ( V_52 -> V_54 ) ;
struct V_1 * V_10 ;
if ( F_7 ( V_52 -> V_54 ) >= V_12 )
return - V_13 ;
F_37 ( & V_52 -> V_21 . V_22 . V_55 ) ;
F_8 () ;
if ( F_10 ( V_52 -> V_54 ) ) {
if ( V_11 == 0 ) {
V_10 = V_14 ;
} else {
V_10 = F_9 ( V_11 ) ;
if ( V_10 && ! F_11 ( V_10 , V_14 ) )
V_10 = NULL ;
}
} else {
if ( V_11 == 0 ) {
V_10 = V_14 -> V_56 ;
} else {
V_10 = F_9 ( V_11 ) ;
if ( V_10 && ! F_12 ( V_10 ) )
V_10 = NULL ;
}
}
V_52 -> V_21 . V_22 . V_2 = V_10 ;
if ( V_10 ) {
F_38 ( V_10 ) ;
} else {
V_53 = - V_13 ;
}
F_13 () ;
return V_53 ;
}
static int F_39 ( struct V_15 * V_16 )
{
int V_53 = 0 ;
unsigned long V_57 ;
struct V_58 * V_6 ;
struct V_1 * V_10 = V_16 -> V_21 . V_22 . V_2 ;
F_40 ( V_10 == NULL ) ;
V_6 = F_41 ( V_10 , & V_57 ) ;
if ( F_42 ( V_6 == NULL ) ) {
F_40 ( ! F_43 ( & V_16 -> V_21 . V_22 . V_55 ) ) ;
} else {
if ( V_16 -> V_21 . V_22 . V_59 )
V_53 = V_60 ;
else
F_44 ( & V_16 -> V_21 . V_22 . V_55 ) ;
F_45 ( V_10 , & V_57 ) ;
}
if ( ! V_53 )
F_46 ( V_10 ) ;
return V_53 ;
}
static void F_47 ( struct V_61 * V_62 )
{
struct V_63 * V_16 , * V_64 ;
F_48 (timer, next, head, entry)
F_49 ( & V_16 -> V_55 ) ;
}
static void F_50 ( struct V_61 * V_62 )
{
F_47 ( V_62 ) ;
F_47 ( ++ V_62 ) ;
F_47 ( ++ V_62 ) ;
}
void F_51 ( struct V_1 * V_47 )
{
F_50 ( V_47 -> V_65 ) ;
}
void F_52 ( struct V_1 * V_47 )
{
F_50 ( V_47 -> signal -> V_65 ) ;
}
static inline int F_53 ( T_1 V_23 , T_1 V_66 )
{
return V_23 == 0 || V_23 > V_66 ;
}
static void F_54 ( struct V_15 * V_16 )
{
struct V_1 * V_10 = V_16 -> V_21 . V_22 . V_2 ;
struct V_61 * V_62 , * V_67 ;
struct V_25 * V_68 ;
struct V_63 * const V_69 = & V_16 -> V_21 . V_22 ;
struct V_63 * V_64 ;
if ( F_10 ( V_16 -> V_54 ) ) {
V_62 = V_10 -> V_65 ;
V_68 = & V_10 -> V_68 ;
} else {
V_62 = V_10 -> signal -> V_65 ;
V_68 = & V_10 -> signal -> V_68 ;
}
V_62 += F_7 ( V_16 -> V_54 ) ;
V_67 = V_62 ;
F_55 (next, head, entry) {
if ( V_69 -> V_23 < V_64 -> V_23 )
break;
V_67 = & V_64 -> V_55 ;
}
F_56 ( & V_69 -> V_55 , V_67 ) ;
if ( V_67 == V_62 ) {
T_1 exp = V_69 -> V_23 ;
switch ( F_7 ( V_16 -> V_54 ) ) {
case V_8 :
if ( F_53 ( V_68 -> V_70 , exp ) )
V_68 -> V_70 = exp ;
break;
case V_38 :
if ( F_53 ( V_68 -> V_71 , exp ) )
V_68 -> V_71 = exp ;
break;
case V_35 :
if ( F_53 ( V_68 -> V_72 , exp ) )
V_68 -> V_72 = exp ;
break;
}
if ( F_10 ( V_16 -> V_54 ) )
F_57 ( V_10 , V_73 ) ;
else
F_58 ( V_10 -> signal , V_73 ) ;
}
}
static void F_59 ( struct V_15 * V_16 )
{
if ( ( V_16 -> V_74 & ~ V_75 ) == V_76 ) {
V_16 -> V_21 . V_22 . V_23 = 0 ;
} else if ( F_42 ( V_16 -> V_77 == NULL ) ) {
F_60 ( V_16 -> V_78 ) ;
V_16 -> V_21 . V_22 . V_23 = 0 ;
} else if ( V_16 -> V_21 . V_22 . V_20 == 0 ) {
F_61 ( V_16 , 0 ) ;
V_16 -> V_21 . V_22 . V_23 = 0 ;
} else if ( F_61 ( V_16 , ++ V_16 -> V_79 ) ) {
F_62 ( V_16 ) ;
}
}
static int F_63 ( const T_2 V_9 ,
struct V_1 * V_10 , T_1 * V_37 )
{
struct V_25 V_26 ;
F_27 ( V_10 , & V_26 ) ;
switch ( F_7 ( V_9 ) ) {
default:
return - V_13 ;
case V_8 :
* V_37 = V_26 . V_27 + V_26 . V_28 ;
break;
case V_38 :
* V_37 = V_26 . V_27 ;
break;
case V_35 :
* V_37 = V_26 . V_29 ;
break;
}
return 0 ;
}
static int F_64 ( struct V_15 * V_16 , int V_80 ,
struct V_81 * V_82 , struct V_81 * V_83 )
{
unsigned long V_57 ;
struct V_58 * V_6 ;
struct V_1 * V_10 = V_16 -> V_21 . V_22 . V_2 ;
T_1 V_84 , V_85 , V_86 , V_87 ;
int V_53 ;
F_40 ( V_10 == NULL ) ;
V_85 = F_65 ( & V_82 -> V_88 ) ;
V_6 = F_41 ( V_10 , & V_57 ) ;
if ( F_42 ( V_6 == NULL ) ) {
return - V_89 ;
}
F_40 ( ! F_66 () ) ;
V_53 = 0 ;
V_86 = V_16 -> V_21 . V_22 . V_20 ;
V_84 = V_16 -> V_21 . V_22 . V_23 ;
if ( F_42 ( V_16 -> V_21 . V_22 . V_59 ) ) {
V_16 -> V_21 . V_22 . V_59 = - 1 ;
V_53 = V_60 ;
} else
F_49 ( & V_16 -> V_21 . V_22 . V_55 ) ;
if ( F_10 ( V_16 -> V_54 ) ) {
F_20 ( V_16 -> V_54 , V_10 , & V_87 ) ;
} else {
F_63 ( V_16 -> V_54 , V_10 , & V_87 ) ;
}
if ( V_83 ) {
if ( V_84 == 0 ) {
V_83 -> V_88 . V_32 = 0 ;
V_83 -> V_88 . V_33 = 0 ;
} else {
F_14 ( V_16 , V_87 ) ;
if ( V_87 < V_16 -> V_21 . V_22 . V_23 ) {
V_84 = V_16 -> V_21 . V_22 . V_23 - V_87 ;
V_83 -> V_88 = F_34 ( V_84 ) ;
} else {
V_83 -> V_88 . V_33 = 1 ;
V_83 -> V_88 . V_32 = 0 ;
}
}
}
if ( F_42 ( V_53 ) ) {
F_45 ( V_10 , & V_57 ) ;
goto V_90;
}
if ( V_85 != 0 && ! ( V_80 & V_91 ) ) {
V_85 += V_87 ;
}
V_16 -> V_21 . V_22 . V_23 = V_85 ;
if ( V_85 != 0 && V_87 < V_85 ) {
F_54 ( V_16 ) ;
}
F_45 ( V_10 , & V_57 ) ;
V_16 -> V_21 . V_22 . V_20 = F_65 ( & V_82 -> V_92 ) ;
V_16 -> V_79 = ( V_16 -> V_79 + 2 ) &
~ V_93 ;
V_16 -> V_94 = 0 ;
V_16 -> V_24 = - 1 ;
if ( V_85 != 0 && ! ( V_87 < V_85 ) ) {
F_59 ( V_16 ) ;
}
V_53 = 0 ;
V_90:
if ( V_83 )
V_83 -> V_92 = F_34 ( V_86 ) ;
return V_53 ;
}
static void F_67 ( struct V_15 * V_16 , struct V_81 * V_95 )
{
T_1 V_17 ;
struct V_1 * V_10 = V_16 -> V_21 . V_22 . V_2 ;
F_40 ( V_10 == NULL ) ;
V_95 -> V_92 = F_34 ( V_16 -> V_21 . V_22 . V_20 ) ;
if ( V_16 -> V_21 . V_22 . V_23 == 0 ) {
V_95 -> V_88 . V_32 = V_95 -> V_88 . V_33 = 0 ;
return;
}
if ( F_10 ( V_16 -> V_54 ) ) {
F_20 ( V_16 -> V_54 , V_10 , & V_17 ) ;
} else {
struct V_58 * V_6 ;
unsigned long V_57 ;
V_6 = F_41 ( V_10 , & V_57 ) ;
if ( F_42 ( V_6 == NULL ) ) {
V_16 -> V_21 . V_22 . V_23 = 0 ;
V_95 -> V_88 = F_34 ( V_16 -> V_21 . V_22 . V_23 ) ;
return;
} else {
F_63 ( V_16 -> V_54 , V_10 , & V_17 ) ;
F_45 ( V_10 , & V_57 ) ;
}
}
if ( V_17 < V_16 -> V_21 . V_22 . V_23 ) {
V_95 -> V_88 = F_34 ( V_16 -> V_21 . V_22 . V_23 - V_17 ) ;
} else {
V_95 -> V_88 . V_33 = 1 ;
V_95 -> V_88 . V_32 = 0 ;
}
}
static unsigned long long
F_68 ( struct V_61 * V_96 ,
struct V_61 * V_59 ,
unsigned long long V_97 )
{
int V_98 = 20 ;
while ( ! F_43 ( V_96 ) ) {
struct V_63 * V_99 ;
V_99 = F_69 ( V_96 , struct V_63 , V_55 ) ;
if ( ! -- V_98 || V_97 < V_99 -> V_23 )
return V_99 -> V_23 ;
V_99 -> V_59 = 1 ;
F_70 ( & V_99 -> V_55 , V_59 ) ;
}
return 0 ;
}
static void F_71 ( struct V_1 * V_47 ,
struct V_61 * V_59 )
{
struct V_61 * V_96 = V_47 -> V_65 ;
struct V_100 * const V_101 = V_47 -> signal ;
struct V_25 * V_102 = & V_47 -> V_68 ;
T_1 V_23 ;
unsigned long V_103 ;
if ( F_15 ( & V_47 -> V_68 ) )
return;
V_23 = F_68 ( V_96 , V_59 , F_16 ( V_47 ) ) ;
V_102 -> V_70 = V_23 ;
V_23 = F_68 ( ++ V_96 , V_59 , F_17 ( V_47 ) ) ;
V_102 -> V_71 = V_23 ;
V_102 -> V_72 = F_68 ( ++ V_96 , V_59 ,
V_47 -> V_104 . V_29 ) ;
V_103 = F_28 ( V_101 -> V_105 [ V_106 ] . V_107 ) ;
if ( V_103 != V_108 ) {
unsigned long V_109 =
F_28 ( V_101 -> V_105 [ V_106 ] . V_110 ) ;
if ( V_109 != V_108 &&
V_47 -> V_111 . V_112 > F_72 ( V_109 , V_113 / V_34 ) ) {
F_73 ( V_114 , V_115 , V_47 ) ;
return;
}
if ( V_47 -> V_111 . V_112 > F_72 ( V_103 , V_113 / V_34 ) ) {
if ( V_103 < V_109 ) {
V_103 += V_113 ;
V_101 -> V_105 [ V_106 ] . V_107 = V_103 ;
}
F_74 ( V_116
L_1 ,
V_47 -> V_117 , F_75 ( V_47 ) ) ;
F_73 ( V_118 , V_115 , V_47 ) ;
}
}
if ( F_15 ( V_102 ) )
F_76 ( V_47 , V_73 ) ;
}
static inline void F_77 ( struct V_100 * V_101 )
{
struct F_27 * V_48 = & V_101 -> V_48 ;
F_30 ( V_48 -> V_49 , false ) ;
F_78 ( V_101 , V_73 ) ;
}
static void F_79 ( struct V_1 * V_47 , struct V_119 * V_21 ,
T_1 * V_23 , T_1 V_120 , int V_121 )
{
if ( ! V_21 -> V_23 )
return;
if ( V_120 >= V_21 -> V_23 ) {
if ( V_21 -> V_20 )
V_21 -> V_23 += V_21 -> V_20 ;
else
V_21 -> V_23 = 0 ;
F_80 ( V_121 == V_122 ?
V_123 : V_124 ,
V_47 -> signal -> V_125 , V_120 ) ;
F_73 ( V_121 , V_115 , V_47 ) ;
}
if ( V_21 -> V_23 && ( ! * V_23 || V_21 -> V_23 < * V_23 ) )
* V_23 = V_21 -> V_23 ;
}
static void F_81 ( struct V_1 * V_47 ,
struct V_61 * V_59 )
{
struct V_100 * const V_101 = V_47 -> signal ;
T_1 V_27 , V_126 , V_127 , V_128 ;
T_1 V_129 , V_130 ;
struct V_61 * V_96 = V_101 -> V_65 ;
struct V_25 V_26 ;
unsigned long V_103 ;
if ( ! F_28 ( V_47 -> signal -> V_48 . V_49 ) )
return;
V_101 -> V_48 . V_131 = true ;
F_27 ( V_47 , & V_26 ) ;
V_27 = V_26 . V_27 ;
V_126 = V_27 + V_26 . V_28 ;
V_129 = V_26 . V_29 ;
V_128 = F_68 ( V_96 , V_59 , V_126 ) ;
V_127 = F_68 ( ++ V_96 , V_59 , V_27 ) ;
V_130 = F_68 ( ++ V_96 , V_59 , V_129 ) ;
F_79 ( V_47 , & V_101 -> V_21 [ V_8 ] , & V_128 , V_126 ,
V_122 ) ;
F_79 ( V_47 , & V_101 -> V_21 [ V_38 ] , & V_127 , V_27 ,
V_132 ) ;
V_103 = F_28 ( V_101 -> V_105 [ V_133 ] . V_107 ) ;
if ( V_103 != V_108 ) {
unsigned long V_134 = F_82 ( V_126 , V_5 ) ;
unsigned long V_109 =
F_28 ( V_101 -> V_105 [ V_133 ] . V_110 ) ;
T_1 V_135 ;
if ( V_134 >= V_109 ) {
F_73 ( V_114 , V_115 , V_47 ) ;
return;
}
if ( V_134 >= V_103 ) {
F_73 ( V_118 , V_115 , V_47 ) ;
if ( V_103 < V_109 ) {
V_103 ++ ;
V_101 -> V_105 [ V_133 ] . V_107 = V_103 ;
}
}
V_135 = V_103 * V_5 ;
if ( ! V_128 || V_135 < V_128 )
V_128 = V_135 ;
}
V_101 -> V_68 . V_70 = V_128 ;
V_101 -> V_68 . V_71 = V_127 ;
V_101 -> V_68 . V_72 = V_130 ;
if ( F_15 ( & V_101 -> V_68 ) )
F_77 ( V_101 ) ;
V_101 -> V_48 . V_131 = false ;
}
void F_62 ( struct V_15 * V_16 )
{
struct V_58 * V_6 ;
unsigned long V_57 ;
struct V_1 * V_10 = V_16 -> V_21 . V_22 . V_2 ;
T_1 V_17 ;
F_40 ( V_10 == NULL ) ;
if ( F_10 ( V_16 -> V_54 ) ) {
F_20 ( V_16 -> V_54 , V_10 , & V_17 ) ;
F_14 ( V_16 , V_17 ) ;
if ( F_42 ( V_10 -> V_136 ) )
goto V_90;
V_6 = F_41 ( V_10 , & V_57 ) ;
if ( ! V_6 )
goto V_90;
} else {
V_6 = F_41 ( V_10 , & V_57 ) ;
if ( F_42 ( V_6 == NULL ) ) {
V_16 -> V_21 . V_22 . V_23 = 0 ;
goto V_90;
} else if ( F_42 ( V_10 -> V_136 ) && F_83 ( V_10 ) ) {
F_45 ( V_10 , & V_57 ) ;
goto V_90;
}
F_63 ( V_16 -> V_54 , V_10 , & V_17 ) ;
F_14 ( V_16 , V_17 ) ;
}
F_40 ( ! F_66 () ) ;
F_54 ( V_16 ) ;
F_45 ( V_10 , & V_57 ) ;
V_90:
V_16 -> V_94 = V_16 -> V_24 ;
V_16 -> V_24 = - 1 ;
++ V_16 -> V_79 ;
}
static inline int F_84 ( const struct V_25 * V_37 ,
const struct V_25 * V_23 )
{
if ( V_23 -> V_27 && V_37 -> V_27 >= V_23 -> V_27 )
return 1 ;
if ( V_23 -> V_28 && V_37 -> V_27 + V_37 -> V_28 >= V_23 -> V_28 )
return 1 ;
if ( V_23 -> V_29 != 0 &&
V_37 -> V_29 >= V_23 -> V_29 )
return 1 ;
return 0 ;
}
static inline int F_85 ( struct V_1 * V_47 )
{
struct V_100 * V_101 ;
if ( ! F_15 ( & V_47 -> V_68 ) ) {
struct V_25 V_137 ;
V_25 ( V_47 , & V_137 . V_27 , & V_137 . V_28 ) ;
V_137 . V_29 = V_47 -> V_104 . V_29 ;
if ( F_84 ( & V_137 , & V_47 -> V_68 ) )
return 1 ;
}
V_101 = V_47 -> signal ;
if ( F_28 ( V_101 -> V_48 . V_49 ) &&
! F_28 ( V_101 -> V_48 . V_131 ) ) {
struct V_25 V_138 ;
F_26 ( & V_138 , & V_101 -> V_48 . V_43 ) ;
if ( F_84 ( & V_138 , & V_101 -> V_68 ) )
return 1 ;
}
return 0 ;
}
void F_86 ( struct V_1 * V_47 )
{
F_87 ( V_59 ) ;
struct V_15 * V_16 , * V_64 ;
unsigned long V_57 ;
F_40 ( ! F_66 () ) ;
if ( ! F_85 ( V_47 ) )
return;
if ( ! F_41 ( V_47 , & V_57 ) )
return;
F_71 ( V_47 , & V_59 ) ;
F_81 ( V_47 , & V_59 ) ;
F_45 ( V_47 , & V_57 ) ;
F_48 (timer, next, &firing, it.cpu.entry) {
int V_139 ;
F_88 ( & V_16 -> V_140 ) ;
F_49 ( & V_16 -> V_21 . V_22 . V_55 ) ;
V_139 = V_16 -> V_21 . V_22 . V_59 ;
V_16 -> V_21 . V_22 . V_59 = 0 ;
if ( F_89 ( V_139 >= 0 ) )
F_59 ( V_16 ) ;
F_90 ( & V_16 -> V_140 ) ;
}
}
void F_3 ( struct V_1 * V_47 , unsigned int V_141 ,
T_1 * V_142 , T_1 * V_143 )
{
T_1 V_17 ;
F_40 ( V_141 == V_35 ) ;
F_63 ( V_141 , V_47 , & V_17 ) ;
if ( V_143 ) {
if ( * V_143 ) {
if ( * V_143 <= V_17 ) {
* V_143 = V_144 ;
} else {
* V_143 -= V_17 ;
}
}
if ( ! * V_142 )
return;
* V_142 += V_17 ;
}
switch ( V_141 ) {
case V_8 :
if ( F_53 ( V_47 -> signal -> V_68 . V_70 , * V_142 ) )
V_47 -> signal -> V_68 . V_70 = * V_142 ;
break;
case V_38 :
if ( F_53 ( V_47 -> signal -> V_68 . V_71 , * V_142 ) )
V_47 -> signal -> V_68 . V_71 = * V_142 ;
break;
}
F_58 ( V_47 -> signal , V_73 ) ;
}
static int F_91 ( const T_2 V_9 , int V_57 ,
struct V_30 * V_145 , struct V_81 * V_21 )
{
struct V_15 V_16 ;
int error ;
memset ( & V_16 , 0 , sizeof V_16 ) ;
F_92 ( & V_16 . V_140 ) ;
V_16 . V_54 = V_9 ;
V_16 . V_24 = - 1 ;
error = F_36 ( & V_16 ) ;
V_16 . V_78 = V_14 ;
if ( ! error ) {
static struct V_81 V_146 ;
memset ( V_21 , 0 , sizeof *V_21 ) ;
V_21 -> V_88 = * V_145 ;
F_2 ( & V_16 . V_140 ) ;
error = F_64 ( & V_16 , V_57 , V_21 , NULL ) ;
if ( error ) {
F_4 ( & V_16 . V_140 ) ;
return error ;
}
while ( ! F_93 ( V_14 ) ) {
if ( V_16 . V_21 . V_22 . V_23 == 0 ) {
F_39 ( & V_16 ) ;
F_4 ( & V_16 . V_140 ) ;
return 0 ;
}
F_94 ( V_147 ) ;
F_4 ( & V_16 . V_140 ) ;
F_95 () ;
F_2 ( & V_16 . V_140 ) ;
}
* V_145 = F_34 ( V_16 . V_21 . V_22 . V_23 ) ;
error = F_64 ( & V_16 , 0 , & V_146 , V_21 ) ;
if ( ! error ) {
F_39 ( & V_16 ) ;
}
F_4 ( & V_16 . V_140 ) ;
while ( error == V_60 ) {
F_2 ( & V_16 . V_140 ) ;
error = F_39 ( & V_16 ) ;
F_4 ( & V_16 . V_140 ) ;
}
if ( ( V_21 -> V_88 . V_32 | V_21 -> V_88 . V_33 ) == 0 ) {
return 0 ;
}
error = - V_148 ;
}
return error ;
}
static int F_96 ( const T_2 V_9 , int V_57 ,
struct V_30 * V_145 , struct V_30 T_5 * V_149 )
{
struct V_150 * V_150 = & V_14 -> V_150 ;
struct V_81 V_21 ;
int error ;
if ( F_10 ( V_9 ) &&
( F_6 ( V_9 ) == 0 ||
F_6 ( V_9 ) == V_14 -> V_11 ) )
return - V_13 ;
error = F_91 ( V_9 , V_57 , V_145 , & V_21 ) ;
if ( error == - V_148 ) {
if ( V_57 & V_91 )
return - V_151 ;
if ( V_149 && F_97 ( V_149 , & V_21 . V_88 , sizeof *V_149 ) )
return - V_152 ;
V_150 -> V_153 = V_154 ;
V_150 -> V_155 . V_156 = V_9 ;
V_150 -> V_155 . V_149 = V_149 ;
V_150 -> V_155 . V_23 = F_65 ( V_145 ) ;
}
return error ;
}
static long V_154 ( struct V_150 * V_150 )
{
T_2 V_9 = V_150 -> V_155 . V_156 ;
struct V_30 V_99 ;
struct V_81 V_21 ;
int error ;
V_99 = F_34 ( V_150 -> V_155 . V_23 ) ;
error = F_91 ( V_9 , V_91 , & V_99 , & V_21 ) ;
if ( error == - V_148 ) {
struct V_30 T_5 * V_149 = V_150 -> V_155 . V_149 ;
if ( V_149 && F_97 ( V_149 , & V_21 . V_88 , sizeof *V_149 ) )
return - V_152 ;
V_150 -> V_155 . V_23 = F_65 ( & V_99 ) ;
}
return error ;
}
static int F_98 ( const T_2 V_9 ,
struct V_30 * V_31 )
{
return F_18 ( V_157 , V_31 ) ;
}
static int F_99 ( const T_2 V_9 ,
struct V_30 * V_31 )
{
return F_35 ( V_157 , V_31 ) ;
}
static int F_100 ( struct V_15 * V_16 )
{
V_16 -> V_54 = V_157 ;
return F_36 ( V_16 ) ;
}
static int F_101 ( const T_2 V_9 , int V_57 ,
struct V_30 * V_145 ,
struct V_30 T_5 * V_149 )
{
return F_96 ( V_157 , V_57 , V_145 , V_149 ) ;
}
static long F_102 ( struct V_150 * V_150 )
{
return - V_13 ;
}
static int F_103 ( const T_2 V_9 ,
struct V_30 * V_31 )
{
return F_18 ( V_158 , V_31 ) ;
}
static int F_104 ( const T_2 V_9 ,
struct V_30 * V_31 )
{
return F_35 ( V_158 , V_31 ) ;
}
static int F_105 ( struct V_15 * V_16 )
{
V_16 -> V_54 = V_158 ;
return F_36 ( V_16 ) ;
}
static T_6 int F_106 ( void )
{
struct V_159 V_160 = {
. V_161 = F_98 ,
. V_162 = F_99 ,
. V_163 = F_100 ,
. V_164 = F_101 ,
. V_165 = F_102 ,
} ;
struct V_159 V_166 = {
. V_161 = F_103 ,
. V_162 = F_104 ,
. V_163 = F_105 ,
} ;
F_107 ( V_167 , & V_160 ) ;
F_107 ( V_168 , & V_166 ) ;
return 0 ;
}
