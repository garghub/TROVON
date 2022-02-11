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
V_52 -> V_55 = & V_56 ;
F_37 ( & V_52 -> V_21 . V_22 . V_57 ) ;
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
V_10 = V_14 -> V_58 ;
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
unsigned long V_59 ;
struct V_60 * V_6 ;
struct V_1 * V_10 = V_16 -> V_21 . V_22 . V_2 ;
F_40 ( V_10 == NULL ) ;
V_6 = F_41 ( V_10 , & V_59 ) ;
if ( F_42 ( V_6 == NULL ) ) {
F_40 ( ! F_43 ( & V_16 -> V_21 . V_22 . V_57 ) ) ;
} else {
if ( V_16 -> V_21 . V_22 . V_61 )
V_53 = V_62 ;
else
F_44 ( & V_16 -> V_21 . V_22 . V_57 ) ;
F_45 ( V_10 , & V_59 ) ;
}
if ( ! V_53 )
F_46 ( V_10 ) ;
return V_53 ;
}
static void F_47 ( struct V_63 * V_64 )
{
struct V_65 * V_16 , * V_66 ;
F_48 (timer, next, head, entry)
F_49 ( & V_16 -> V_57 ) ;
}
static void F_50 ( struct V_63 * V_64 )
{
F_47 ( V_64 ) ;
F_47 ( ++ V_64 ) ;
F_47 ( ++ V_64 ) ;
}
void F_51 ( struct V_1 * V_47 )
{
F_50 ( V_47 -> V_67 ) ;
}
void F_52 ( struct V_1 * V_47 )
{
F_50 ( V_47 -> signal -> V_67 ) ;
}
static inline int F_53 ( T_1 V_23 , T_1 V_68 )
{
return V_23 == 0 || V_23 > V_68 ;
}
static void F_54 ( struct V_15 * V_16 )
{
struct V_1 * V_10 = V_16 -> V_21 . V_22 . V_2 ;
struct V_63 * V_64 , * V_69 ;
struct V_25 * V_70 ;
struct V_65 * const V_71 = & V_16 -> V_21 . V_22 ;
struct V_65 * V_66 ;
if ( F_10 ( V_16 -> V_54 ) ) {
V_64 = V_10 -> V_67 ;
V_70 = & V_10 -> V_70 ;
} else {
V_64 = V_10 -> signal -> V_67 ;
V_70 = & V_10 -> signal -> V_70 ;
}
V_64 += F_7 ( V_16 -> V_54 ) ;
V_69 = V_64 ;
F_55 (next, head, entry) {
if ( V_71 -> V_23 < V_66 -> V_23 )
break;
V_69 = & V_66 -> V_57 ;
}
F_56 ( & V_71 -> V_57 , V_69 ) ;
if ( V_69 == V_64 ) {
T_1 exp = V_71 -> V_23 ;
switch ( F_7 ( V_16 -> V_54 ) ) {
case V_8 :
if ( F_53 ( V_70 -> V_72 , exp ) )
V_70 -> V_72 = exp ;
break;
case V_38 :
if ( F_53 ( V_70 -> V_73 , exp ) )
V_70 -> V_73 = exp ;
break;
case V_35 :
if ( F_53 ( V_70 -> V_74 , exp ) )
V_70 -> V_74 = exp ;
break;
}
if ( F_10 ( V_16 -> V_54 ) )
F_57 ( V_10 , V_75 ) ;
else
F_58 ( V_10 -> signal , V_75 ) ;
}
}
static void F_59 ( struct V_15 * V_16 )
{
if ( ( V_16 -> V_76 & ~ V_77 ) == V_78 ) {
V_16 -> V_21 . V_22 . V_23 = 0 ;
} else if ( F_42 ( V_16 -> V_79 == NULL ) ) {
F_60 ( V_16 -> V_80 ) ;
V_16 -> V_21 . V_22 . V_23 = 0 ;
} else if ( V_16 -> V_21 . V_22 . V_20 == 0 ) {
F_61 ( V_16 , 0 ) ;
V_16 -> V_21 . V_22 . V_23 = 0 ;
} else if ( F_61 ( V_16 , ++ V_16 -> V_81 ) ) {
F_62 ( V_16 ) ;
++ V_16 -> V_81 ;
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
static int F_64 ( struct V_15 * V_16 , int V_82 ,
struct V_83 * V_84 , struct V_83 * V_85 )
{
unsigned long V_59 ;
struct V_60 * V_6 ;
struct V_1 * V_10 = V_16 -> V_21 . V_22 . V_2 ;
T_1 V_86 , V_87 , V_88 , V_89 ;
int V_53 ;
F_40 ( V_10 == NULL ) ;
V_87 = F_65 ( F_66 ( V_84 -> V_90 ) ) ;
V_6 = F_41 ( V_10 , & V_59 ) ;
if ( F_42 ( V_6 == NULL ) ) {
return - V_91 ;
}
F_40 ( ! F_67 () ) ;
V_53 = 0 ;
V_88 = V_16 -> V_21 . V_22 . V_20 ;
V_86 = V_16 -> V_21 . V_22 . V_23 ;
if ( F_42 ( V_16 -> V_21 . V_22 . V_61 ) ) {
V_16 -> V_21 . V_22 . V_61 = - 1 ;
V_53 = V_62 ;
} else
F_49 ( & V_16 -> V_21 . V_22 . V_57 ) ;
if ( F_10 ( V_16 -> V_54 ) ) {
F_20 ( V_16 -> V_54 , V_10 , & V_89 ) ;
} else {
F_63 ( V_16 -> V_54 , V_10 , & V_89 ) ;
}
if ( V_85 ) {
if ( V_86 == 0 ) {
V_85 -> V_90 . V_32 = 0 ;
V_85 -> V_90 . V_33 = 0 ;
} else {
F_14 ( V_16 , V_89 ) ;
if ( V_89 < V_16 -> V_21 . V_22 . V_23 ) {
V_86 = V_16 -> V_21 . V_22 . V_23 - V_89 ;
V_85 -> V_90 = F_34 ( V_86 ) ;
} else {
V_85 -> V_90 . V_33 = 1 ;
V_85 -> V_90 . V_32 = 0 ;
}
}
}
if ( F_42 ( V_53 ) ) {
F_45 ( V_10 , & V_59 ) ;
goto V_92;
}
if ( V_87 != 0 && ! ( V_82 & V_93 ) ) {
V_87 += V_89 ;
}
V_16 -> V_21 . V_22 . V_23 = V_87 ;
if ( V_87 != 0 && V_89 < V_87 ) {
F_54 ( V_16 ) ;
}
F_45 ( V_10 , & V_59 ) ;
V_16 -> V_21 . V_22 . V_20 = F_68 ( & V_84 -> V_94 ) ;
V_16 -> V_81 = ( V_16 -> V_81 + 2 ) &
~ V_95 ;
V_16 -> V_96 = 0 ;
V_16 -> V_24 = - 1 ;
if ( V_87 != 0 && ! ( V_89 < V_87 ) ) {
F_59 ( V_16 ) ;
}
V_53 = 0 ;
V_92:
if ( V_85 )
V_85 -> V_94 = F_34 ( V_88 ) ;
return V_53 ;
}
static void F_69 ( struct V_15 * V_16 , struct V_83 * V_97 )
{
T_1 V_17 ;
struct V_1 * V_10 = V_16 -> V_21 . V_22 . V_2 ;
F_40 ( V_10 == NULL ) ;
V_97 -> V_94 = F_34 ( V_16 -> V_21 . V_22 . V_20 ) ;
if ( ! V_16 -> V_21 . V_22 . V_23 )
return;
if ( F_10 ( V_16 -> V_54 ) ) {
F_20 ( V_16 -> V_54 , V_10 , & V_17 ) ;
} else {
struct V_60 * V_6 ;
unsigned long V_59 ;
V_6 = F_41 ( V_10 , & V_59 ) ;
if ( F_42 ( V_6 == NULL ) ) {
V_16 -> V_21 . V_22 . V_23 = 0 ;
return;
} else {
F_63 ( V_16 -> V_54 , V_10 , & V_17 ) ;
F_45 ( V_10 , & V_59 ) ;
}
}
if ( V_17 < V_16 -> V_21 . V_22 . V_23 ) {
V_97 -> V_90 = F_34 ( V_16 -> V_21 . V_22 . V_23 - V_17 ) ;
} else {
V_97 -> V_90 . V_33 = 1 ;
V_97 -> V_90 . V_32 = 0 ;
}
}
static unsigned long long
F_70 ( struct V_63 * V_98 ,
struct V_63 * V_61 ,
unsigned long long V_99 )
{
int V_100 = 20 ;
while ( ! F_43 ( V_98 ) ) {
struct V_65 * V_101 ;
V_101 = F_71 ( V_98 , struct V_65 , V_57 ) ;
if ( ! -- V_100 || V_99 < V_101 -> V_23 )
return V_101 -> V_23 ;
V_101 -> V_61 = 1 ;
F_72 ( & V_101 -> V_57 , V_61 ) ;
}
return 0 ;
}
static void F_73 ( struct V_1 * V_47 ,
struct V_63 * V_61 )
{
struct V_63 * V_98 = V_47 -> V_67 ;
struct V_102 * const V_103 = V_47 -> signal ;
struct V_25 * V_104 = & V_47 -> V_70 ;
T_1 V_23 ;
unsigned long V_105 ;
if ( F_15 ( & V_47 -> V_70 ) )
return;
V_23 = F_70 ( V_98 , V_61 , F_16 ( V_47 ) ) ;
V_104 -> V_72 = V_23 ;
V_23 = F_70 ( ++ V_98 , V_61 , F_17 ( V_47 ) ) ;
V_104 -> V_73 = V_23 ;
V_104 -> V_74 = F_70 ( ++ V_98 , V_61 ,
V_47 -> V_106 . V_29 ) ;
V_105 = F_28 ( V_103 -> V_107 [ V_108 ] . V_109 ) ;
if ( V_105 != V_110 ) {
unsigned long V_111 =
F_28 ( V_103 -> V_107 [ V_108 ] . V_112 ) ;
if ( V_111 != V_110 &&
V_47 -> V_113 . V_114 > F_74 ( V_111 , V_115 / V_34 ) ) {
if ( V_116 ) {
F_75 ( L_1 ,
V_47 -> V_117 , F_76 ( V_47 ) ) ;
}
F_77 ( V_118 , V_119 , V_47 ) ;
return;
}
if ( V_47 -> V_113 . V_114 > F_74 ( V_105 , V_115 / V_34 ) ) {
if ( V_105 < V_111 ) {
V_105 += V_115 ;
V_103 -> V_107 [ V_108 ] . V_109 = V_105 ;
}
if ( V_116 ) {
F_75 ( L_2 ,
V_47 -> V_117 , F_76 ( V_47 ) ) ;
}
F_77 ( V_120 , V_119 , V_47 ) ;
}
}
if ( F_15 ( V_104 ) )
F_78 ( V_47 , V_75 ) ;
}
static inline void F_79 ( struct V_102 * V_103 )
{
struct F_27 * V_48 = & V_103 -> V_48 ;
F_30 ( V_48 -> V_49 , false ) ;
F_80 ( V_103 , V_75 ) ;
}
static void F_81 ( struct V_1 * V_47 , struct V_121 * V_21 ,
T_1 * V_23 , T_1 V_122 , int V_123 )
{
if ( ! V_21 -> V_23 )
return;
if ( V_122 >= V_21 -> V_23 ) {
if ( V_21 -> V_20 )
V_21 -> V_23 += V_21 -> V_20 ;
else
V_21 -> V_23 = 0 ;
F_82 ( V_123 == V_124 ?
V_125 : V_126 ,
V_47 -> signal -> V_127 , V_122 ) ;
F_77 ( V_123 , V_119 , V_47 ) ;
}
if ( V_21 -> V_23 && ( ! * V_23 || V_21 -> V_23 < * V_23 ) )
* V_23 = V_21 -> V_23 ;
}
static void F_83 ( struct V_1 * V_47 ,
struct V_63 * V_61 )
{
struct V_102 * const V_103 = V_47 -> signal ;
T_1 V_27 , V_128 , V_129 , V_130 ;
T_1 V_131 , V_132 ;
struct V_63 * V_98 = V_103 -> V_67 ;
struct V_25 V_26 ;
unsigned long V_105 ;
if ( ! F_28 ( V_47 -> signal -> V_48 . V_49 ) )
return;
V_103 -> V_48 . V_133 = true ;
F_27 ( V_47 , & V_26 ) ;
V_27 = V_26 . V_27 ;
V_128 = V_27 + V_26 . V_28 ;
V_131 = V_26 . V_29 ;
V_130 = F_70 ( V_98 , V_61 , V_128 ) ;
V_129 = F_70 ( ++ V_98 , V_61 , V_27 ) ;
V_132 = F_70 ( ++ V_98 , V_61 , V_131 ) ;
F_81 ( V_47 , & V_103 -> V_21 [ V_8 ] , & V_130 , V_128 ,
V_124 ) ;
F_81 ( V_47 , & V_103 -> V_21 [ V_38 ] , & V_129 , V_27 ,
V_134 ) ;
V_105 = F_28 ( V_103 -> V_107 [ V_135 ] . V_109 ) ;
if ( V_105 != V_110 ) {
unsigned long V_136 = F_84 ( V_128 , V_5 ) ;
unsigned long V_111 =
F_28 ( V_103 -> V_107 [ V_135 ] . V_112 ) ;
T_1 V_137 ;
if ( V_136 >= V_111 ) {
if ( V_116 ) {
F_75 ( L_3 ,
V_47 -> V_117 , F_76 ( V_47 ) ) ;
}
F_77 ( V_118 , V_119 , V_47 ) ;
return;
}
if ( V_136 >= V_105 ) {
if ( V_116 ) {
F_75 ( L_4 ,
V_47 -> V_117 , F_76 ( V_47 ) ) ;
}
F_77 ( V_120 , V_119 , V_47 ) ;
if ( V_105 < V_111 ) {
V_105 ++ ;
V_103 -> V_107 [ V_135 ] . V_109 = V_105 ;
}
}
V_137 = V_105 * V_5 ;
if ( ! V_130 || V_137 < V_130 )
V_130 = V_137 ;
}
V_103 -> V_70 . V_72 = V_130 ;
V_103 -> V_70 . V_73 = V_129 ;
V_103 -> V_70 . V_74 = V_132 ;
if ( F_15 ( & V_103 -> V_70 ) )
F_79 ( V_103 ) ;
V_103 -> V_48 . V_133 = false ;
}
static void F_62 ( struct V_15 * V_16 )
{
struct V_60 * V_6 ;
unsigned long V_59 ;
struct V_1 * V_10 = V_16 -> V_21 . V_22 . V_2 ;
T_1 V_17 ;
F_40 ( V_10 == NULL ) ;
if ( F_10 ( V_16 -> V_54 ) ) {
F_20 ( V_16 -> V_54 , V_10 , & V_17 ) ;
F_14 ( V_16 , V_17 ) ;
if ( F_42 ( V_10 -> V_138 ) )
return;
V_6 = F_41 ( V_10 , & V_59 ) ;
if ( ! V_6 )
return;
} else {
V_6 = F_41 ( V_10 , & V_59 ) ;
if ( F_42 ( V_6 == NULL ) ) {
V_16 -> V_21 . V_22 . V_23 = 0 ;
return;
} else if ( F_42 ( V_10 -> V_138 ) && F_85 ( V_10 ) ) {
goto V_139;
}
F_63 ( V_16 -> V_54 , V_10 , & V_17 ) ;
F_14 ( V_16 , V_17 ) ;
}
F_40 ( ! F_67 () ) ;
F_54 ( V_16 ) ;
V_139:
F_45 ( V_10 , & V_59 ) ;
}
static inline int F_86 ( const struct V_25 * V_37 ,
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
static inline int F_87 ( struct V_1 * V_47 )
{
struct V_102 * V_103 ;
if ( ! F_15 ( & V_47 -> V_70 ) ) {
struct V_25 V_140 ;
V_25 ( V_47 , & V_140 . V_27 , & V_140 . V_28 ) ;
V_140 . V_29 = V_47 -> V_106 . V_29 ;
if ( F_86 ( & V_140 , & V_47 -> V_70 ) )
return 1 ;
}
V_103 = V_47 -> signal ;
if ( F_28 ( V_103 -> V_48 . V_49 ) &&
! F_28 ( V_103 -> V_48 . V_133 ) ) {
struct V_25 V_141 ;
F_26 ( & V_141 , & V_103 -> V_48 . V_43 ) ;
if ( F_86 ( & V_141 , & V_103 -> V_70 ) )
return 1 ;
}
return 0 ;
}
void F_88 ( struct V_1 * V_47 )
{
F_89 ( V_61 ) ;
struct V_15 * V_16 , * V_66 ;
unsigned long V_59 ;
F_40 ( ! F_67 () ) ;
if ( ! F_87 ( V_47 ) )
return;
if ( ! F_41 ( V_47 , & V_59 ) )
return;
F_73 ( V_47 , & V_61 ) ;
F_83 ( V_47 , & V_61 ) ;
F_45 ( V_47 , & V_59 ) ;
F_48 (timer, next, &firing, it.cpu.entry) {
int V_142 ;
F_90 ( & V_16 -> V_143 ) ;
F_49 ( & V_16 -> V_21 . V_22 . V_57 ) ;
V_142 = V_16 -> V_21 . V_22 . V_61 ;
V_16 -> V_21 . V_22 . V_61 = 0 ;
if ( F_91 ( V_142 >= 0 ) )
F_59 ( V_16 ) ;
F_92 ( & V_16 -> V_143 ) ;
}
}
void F_3 ( struct V_1 * V_47 , unsigned int V_144 ,
T_1 * V_145 , T_1 * V_146 )
{
T_1 V_17 ;
F_40 ( V_144 == V_35 ) ;
F_63 ( V_144 , V_47 , & V_17 ) ;
if ( V_146 ) {
if ( * V_146 ) {
if ( * V_146 <= V_17 ) {
* V_146 = V_147 ;
} else {
* V_146 -= V_17 ;
}
}
if ( ! * V_145 )
return;
* V_145 += V_17 ;
}
switch ( V_144 ) {
case V_8 :
if ( F_53 ( V_47 -> signal -> V_70 . V_72 , * V_145 ) )
V_47 -> signal -> V_70 . V_72 = * V_145 ;
break;
case V_38 :
if ( F_53 ( V_47 -> signal -> V_70 . V_73 , * V_145 ) )
V_47 -> signal -> V_70 . V_73 = * V_145 ;
break;
}
F_58 ( V_47 -> signal , V_75 ) ;
}
static int F_93 ( const T_2 V_9 , int V_59 ,
const struct V_30 * V_148 )
{
struct V_83 V_21 ;
struct V_15 V_16 ;
T_1 V_23 ;
int error ;
memset ( & V_16 , 0 , sizeof V_16 ) ;
F_94 ( & V_16 . V_143 ) ;
V_16 . V_54 = V_9 ;
V_16 . V_24 = - 1 ;
error = F_36 ( & V_16 ) ;
V_16 . V_80 = V_14 ;
if ( ! error ) {
static struct V_83 V_149 ;
struct V_150 * V_151 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_90 = * V_148 ;
F_2 ( & V_16 . V_143 ) ;
error = F_64 ( & V_16 , V_59 , & V_21 , NULL ) ;
if ( error ) {
F_4 ( & V_16 . V_143 ) ;
return error ;
}
while ( ! F_95 ( V_14 ) ) {
if ( V_16 . V_21 . V_22 . V_23 == 0 ) {
F_39 ( & V_16 ) ;
F_4 ( & V_16 . V_143 ) ;
return 0 ;
}
F_96 ( V_152 ) ;
F_4 ( & V_16 . V_143 ) ;
F_97 () ;
F_2 ( & V_16 . V_143 ) ;
}
V_23 = V_16 . V_21 . V_22 . V_23 ;
error = F_64 ( & V_16 , 0 , & V_149 , & V_21 ) ;
if ( ! error ) {
F_39 ( & V_16 ) ;
}
F_4 ( & V_16 . V_143 ) ;
while ( error == V_62 ) {
F_2 ( & V_16 . V_143 ) ;
error = F_39 ( & V_16 ) ;
F_4 ( & V_16 . V_143 ) ;
}
if ( ( V_21 . V_90 . V_32 | V_21 . V_90 . V_33 ) == 0 ) {
return 0 ;
}
error = - V_153 ;
V_151 = & V_14 -> V_150 ;
V_151 -> V_154 . V_23 = V_23 ;
if ( V_151 -> V_154 . type != V_155 )
error = F_98 ( V_151 , & V_21 . V_90 ) ;
}
return error ;
}
static int F_99 ( const T_2 V_9 , int V_59 ,
const struct V_30 * V_148 )
{
struct V_150 * V_150 = & V_14 -> V_150 ;
int error ;
if ( F_10 ( V_9 ) &&
( F_6 ( V_9 ) == 0 ||
F_6 ( V_9 ) == F_100 ( V_14 ) ) )
return - V_13 ;
error = F_93 ( V_9 , V_59 , V_148 ) ;
if ( error == - V_153 ) {
if ( V_59 & V_93 )
return - V_156 ;
V_150 -> V_157 = V_158 ;
V_150 -> V_154 . V_159 = V_9 ;
}
return error ;
}
static long V_158 ( struct V_150 * V_150 )
{
T_2 V_9 = V_150 -> V_154 . V_159 ;
struct V_30 V_101 ;
V_101 = F_34 ( V_150 -> V_154 . V_23 ) ;
return F_93 ( V_9 , V_93 , & V_101 ) ;
}
static int F_101 ( const T_2 V_9 ,
struct V_30 * V_31 )
{
return F_18 ( V_160 , V_31 ) ;
}
static int F_102 ( const T_2 V_9 ,
struct V_30 * V_31 )
{
return F_35 ( V_160 , V_31 ) ;
}
static int F_103 ( struct V_15 * V_16 )
{
V_16 -> V_54 = V_160 ;
return F_36 ( V_16 ) ;
}
static int F_104 ( const T_2 V_9 , int V_59 ,
const struct V_30 * V_148 )
{
return F_99 ( V_160 , V_59 , V_148 ) ;
}
static int F_105 ( const T_2 V_9 ,
struct V_30 * V_31 )
{
return F_18 ( V_161 , V_31 ) ;
}
static int F_106 ( const T_2 V_9 ,
struct V_30 * V_31 )
{
return F_35 ( V_161 , V_31 ) ;
}
static int F_107 ( struct V_15 * V_16 )
{
V_16 -> V_54 = V_161 ;
return F_36 ( V_16 ) ;
}
