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
static void F_29 ( struct V_32 * V_40 , struct V_32 * V_41 )
{
if ( V_41 -> V_33 > V_40 -> V_33 )
V_40 -> V_33 = V_41 -> V_33 ;
if ( V_41 -> V_34 > V_40 -> V_34 )
V_40 -> V_34 = V_41 -> V_34 ;
if ( V_41 -> V_35 > V_40 -> V_35 )
V_40 -> V_35 = V_41 -> V_35 ;
}
void F_30 ( struct V_1 * V_42 , struct V_32 * V_43 )
{
struct F_30 * V_44 = & V_42 -> signal -> V_44 ;
struct V_32 V_45 ;
unsigned long V_46 ;
if ( ! V_44 -> V_47 ) {
F_31 ( V_42 , & V_45 ) ;
F_32 ( & V_44 -> V_48 , V_46 ) ;
V_44 -> V_47 = 1 ;
F_29 ( & V_44 -> V_4 , & V_45 ) ;
} else
F_32 ( & V_44 -> V_48 , V_46 ) ;
* V_43 = V_44 -> V_4 ;
F_33 ( & V_44 -> V_48 , V_46 ) ;
}
static int F_34 ( const T_2 V_8 ,
struct V_1 * V_9 ,
unsigned long long * V_38 )
{
struct V_32 V_4 ;
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
F_31 ( V_9 , & V_4 ) ;
* V_38 = F_16 ( V_4 . V_33 + V_4 . V_34 ) ;
break;
case V_39 :
F_31 ( V_9 , & V_4 ) ;
* V_38 = F_16 ( V_4 . V_33 ) ;
break;
case V_17 :
F_31 ( V_9 , & V_4 ) ;
* V_38 = V_4 . V_35 ;
break;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_42 ,
const T_2 V_8 ,
struct V_14 * V_15 )
{
int V_49 = - V_12 ;
unsigned long long V_50 ;
if ( F_11 ( V_8 ) ) {
if ( F_12 ( V_42 , V_13 ) )
V_49 = F_27 ( V_8 , V_42 , & V_50 ) ;
} else {
unsigned long V_46 ;
struct V_51 * V_5 ;
V_5 = F_36 ( V_42 , & V_46 ) ;
if ( ! V_5 )
return V_49 ;
if ( V_42 == V_13 || F_37 ( V_42 ) )
V_49 = F_34 ( V_8 , V_42 , & V_50 ) ;
F_38 ( V_42 , & V_46 ) ;
}
if ( ! V_49 )
F_18 ( V_8 , V_50 , V_15 ) ;
return V_49 ;
}
static int F_39 ( const T_2 V_8 , struct V_14 * V_15 )
{
const T_3 V_10 = F_7 ( V_8 ) ;
int V_49 = - V_12 ;
if ( V_10 == 0 ) {
V_49 = F_35 ( V_13 , V_8 , V_15 ) ;
} else {
struct V_1 * V_9 ;
F_9 () ;
V_9 = F_10 ( V_10 ) ;
if ( V_9 )
V_49 = F_35 ( V_9 , V_8 , V_15 ) ;
F_14 () ;
}
return V_49 ;
}
static int F_40 ( struct V_23 * V_52 )
{
int V_16 = 0 ;
const T_3 V_10 = F_7 ( V_52 -> V_53 ) ;
struct V_1 * V_9 ;
if ( F_8 ( V_52 -> V_53 ) >= V_11 )
return - V_12 ;
F_41 ( & V_52 -> V_29 . V_30 . V_54 ) ;
F_9 () ;
if ( F_11 ( V_52 -> V_53 ) ) {
if ( V_10 == 0 ) {
V_9 = V_13 ;
} else {
V_9 = F_10 ( V_10 ) ;
if ( V_9 && ! F_12 ( V_9 , V_13 ) )
V_9 = NULL ;
}
} else {
if ( V_10 == 0 ) {
V_9 = V_13 -> V_55 ;
} else {
V_9 = F_10 ( V_10 ) ;
if ( V_9 && ! F_13 ( V_9 ) )
V_9 = NULL ;
}
}
V_52 -> V_29 . V_30 . V_2 = V_9 ;
if ( V_9 ) {
F_42 ( V_9 ) ;
} else {
V_16 = - V_12 ;
}
F_14 () ;
return V_16 ;
}
static int F_43 ( struct V_23 * V_24 )
{
int V_16 = 0 ;
unsigned long V_46 ;
struct V_51 * V_5 ;
struct V_1 * V_9 = V_24 -> V_29 . V_30 . V_2 ;
F_44 ( V_9 == NULL ) ;
V_5 = F_36 ( V_9 , & V_46 ) ;
if ( F_45 ( V_5 == NULL ) ) {
F_44 ( ! F_46 ( & V_24 -> V_29 . V_30 . V_54 ) ) ;
} else {
if ( V_24 -> V_29 . V_30 . V_56 )
V_16 = V_57 ;
else
F_47 ( & V_24 -> V_29 . V_30 . V_54 ) ;
F_38 ( V_9 , & V_46 ) ;
}
if ( ! V_16 )
F_48 ( V_9 ) ;
return V_16 ;
}
static void F_49 ( struct V_58 * V_59 )
{
struct V_60 * V_24 , * V_61 ;
F_50 (timer, next, head, entry)
F_51 ( & V_24 -> V_54 ) ;
}
static void F_52 ( struct V_58 * V_59 )
{
F_49 ( V_59 ) ;
F_49 ( ++ V_59 ) ;
F_49 ( ++ V_59 ) ;
}
void F_53 ( struct V_1 * V_42 )
{
F_54 ( ( const void * ) & V_42 -> V_62 . V_35 ,
sizeof( unsigned long long ) ) ;
F_52 ( V_42 -> V_63 ) ;
}
void F_55 ( struct V_1 * V_42 )
{
F_52 ( V_42 -> signal -> V_63 ) ;
}
static inline int F_56 ( T_1 V_21 , T_1 V_64 )
{
return V_21 == 0 || V_21 > V_64 ;
}
static void F_57 ( struct V_23 * V_24 )
{
struct V_1 * V_9 = V_24 -> V_29 . V_30 . V_2 ;
struct V_58 * V_59 , * V_65 ;
struct V_32 * V_66 ;
struct V_60 * const V_67 = & V_24 -> V_29 . V_30 ;
struct V_60 * V_61 ;
if ( F_11 ( V_24 -> V_53 ) ) {
V_59 = V_9 -> V_63 ;
V_66 = & V_9 -> V_66 ;
} else {
V_59 = V_9 -> signal -> V_63 ;
V_66 = & V_9 -> signal -> V_66 ;
}
V_59 += F_8 ( V_24 -> V_53 ) ;
V_65 = V_59 ;
F_58 (next, head, entry) {
if ( V_67 -> V_21 < V_61 -> V_21 )
break;
V_65 = & V_61 -> V_54 ;
}
F_59 ( & V_67 -> V_54 , V_65 ) ;
if ( V_65 == V_59 ) {
unsigned long long exp = V_67 -> V_21 ;
switch ( F_8 ( V_24 -> V_53 ) ) {
case V_7 :
if ( F_56 ( V_66 -> V_68 , F_60 ( exp ) ) )
V_66 -> V_68 = F_60 ( exp ) ;
break;
case V_39 :
if ( F_56 ( V_66 -> V_69 , F_60 ( exp ) ) )
V_66 -> V_69 = F_60 ( exp ) ;
break;
case V_17 :
if ( V_66 -> V_70 == 0 ||
V_66 -> V_70 > exp )
V_66 -> V_70 = exp ;
break;
}
}
}
static void F_61 ( struct V_23 * V_24 )
{
if ( ( V_24 -> V_71 & ~ V_72 ) == V_73 ) {
V_24 -> V_29 . V_30 . V_21 = 0 ;
} else if ( F_45 ( V_24 -> V_74 == NULL ) ) {
F_62 ( V_24 -> V_75 ) ;
V_24 -> V_29 . V_30 . V_21 = 0 ;
} else if ( V_24 -> V_29 . V_30 . V_28 == 0 ) {
F_63 ( V_24 , 0 ) ;
V_24 -> V_29 . V_30 . V_21 = 0 ;
} else if ( F_63 ( V_24 , ++ V_24 -> V_76 ) ) {
F_64 ( V_24 ) ;
}
}
static int F_65 ( const T_2 V_8 ,
struct V_1 * V_9 ,
unsigned long long * V_38 )
{
struct V_32 V_4 ;
F_30 ( V_9 , & V_4 ) ;
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
* V_38 = V_4 . V_35 + F_66 ( V_9 ) ;
break;
}
return 0 ;
}
static void F_67 ( struct V_77 * V_78 )
{
F_68 () ;
}
static void F_69 ( void )
{
if ( F_70 () )
F_71 ( & V_79 ) ;
}
bool F_72 ( struct V_1 * V_42 )
{
if ( ! F_22 ( & V_42 -> V_66 ) )
return false ;
if ( V_42 -> signal -> V_44 . V_47 )
return false ;
return true ;
}
static inline void F_69 ( void ) { }
static int F_73 ( struct V_23 * V_24 , int V_80 ,
struct V_81 * V_82 , struct V_81 * V_83 )
{
unsigned long V_46 ;
struct V_51 * V_5 ;
struct V_1 * V_9 = V_24 -> V_29 . V_30 . V_2 ;
unsigned long long V_84 , V_85 , V_86 , V_87 ;
int V_16 ;
F_44 ( V_9 == NULL ) ;
V_85 = F_15 ( V_24 -> V_53 , & V_82 -> V_88 ) ;
V_5 = F_36 ( V_9 , & V_46 ) ;
if ( F_45 ( V_5 == NULL ) ) {
return - V_89 ;
}
F_44 ( ! F_74 () ) ;
V_16 = 0 ;
V_86 = V_24 -> V_29 . V_30 . V_28 ;
V_84 = V_24 -> V_29 . V_30 . V_21 ;
if ( F_45 ( V_24 -> V_29 . V_30 . V_56 ) ) {
V_24 -> V_29 . V_30 . V_56 = - 1 ;
V_16 = V_57 ;
} else
F_51 ( & V_24 -> V_29 . V_30 . V_54 ) ;
if ( F_11 ( V_24 -> V_53 ) ) {
F_27 ( V_24 -> V_53 , V_9 , & V_87 ) ;
} else {
F_65 ( V_24 -> V_53 , V_9 , & V_87 ) ;
}
if ( V_83 ) {
if ( V_84 == 0 ) {
V_83 -> V_88 . V_18 = 0 ;
V_83 -> V_88 . V_20 = 0 ;
} else {
F_21 ( V_24 , V_87 ) ;
if ( V_87 < V_24 -> V_29 . V_30 . V_21 ) {
V_84 = V_24 -> V_29 . V_30 . V_21 - V_87 ;
F_18 ( V_24 -> V_53 ,
V_84 ,
& V_83 -> V_88 ) ;
} else {
V_83 -> V_88 . V_20 = 1 ;
V_83 -> V_88 . V_18 = 0 ;
}
}
}
if ( F_45 ( V_16 ) ) {
F_38 ( V_9 , & V_46 ) ;
goto V_90;
}
if ( V_85 != 0 && ! ( V_80 & V_91 ) ) {
V_85 += V_87 ;
}
V_24 -> V_29 . V_30 . V_21 = V_85 ;
if ( V_85 != 0 && V_87 < V_85 ) {
F_57 ( V_24 ) ;
}
F_38 ( V_9 , & V_46 ) ;
V_24 -> V_29 . V_30 . V_28 = F_15 ( V_24 -> V_53 ,
& V_82 -> V_92 ) ;
V_24 -> V_76 = ( V_24 -> V_76 + 2 ) &
~ V_93 ;
V_24 -> V_94 = 0 ;
V_24 -> V_31 = - 1 ;
if ( V_85 != 0 && ! ( V_87 < V_85 ) ) {
F_61 ( V_24 ) ;
}
V_16 = 0 ;
V_90:
if ( V_83 ) {
F_18 ( V_24 -> V_53 ,
V_86 , & V_83 -> V_92 ) ;
}
if ( ! V_16 )
F_69 () ;
return V_16 ;
}
static void F_75 ( struct V_23 * V_24 , struct V_81 * V_95 )
{
unsigned long long V_25 ;
struct V_1 * V_9 = V_24 -> V_29 . V_30 . V_2 ;
F_44 ( V_9 == NULL ) ;
F_18 ( V_24 -> V_53 ,
V_24 -> V_29 . V_30 . V_28 , & V_95 -> V_92 ) ;
if ( V_24 -> V_29 . V_30 . V_21 == 0 ) {
V_95 -> V_88 . V_18 = V_95 -> V_88 . V_20 = 0 ;
return;
}
if ( F_11 ( V_24 -> V_53 ) ) {
F_27 ( V_24 -> V_53 , V_9 , & V_25 ) ;
} else {
struct V_51 * V_5 ;
unsigned long V_46 ;
V_5 = F_36 ( V_9 , & V_46 ) ;
if ( F_45 ( V_5 == NULL ) ) {
V_24 -> V_29 . V_30 . V_21 = 0 ;
F_18 ( V_24 -> V_53 , V_24 -> V_29 . V_30 . V_21 ,
& V_95 -> V_88 ) ;
} else {
F_65 ( V_24 -> V_53 , V_9 , & V_25 ) ;
F_38 ( V_9 , & V_46 ) ;
}
}
if ( V_25 < V_24 -> V_29 . V_30 . V_21 ) {
F_18 ( V_24 -> V_53 ,
V_24 -> V_29 . V_30 . V_21 - V_25 ,
& V_95 -> V_88 ) ;
} else {
V_95 -> V_88 . V_20 = 1 ;
V_95 -> V_88 . V_18 = 0 ;
}
}
static unsigned long long
F_76 ( struct V_58 * V_96 ,
struct V_58 * V_56 ,
unsigned long long V_97 )
{
int V_98 = 20 ;
while ( ! F_46 ( V_96 ) ) {
struct V_60 * V_99 ;
V_99 = F_77 ( V_96 , struct V_60 , V_54 ) ;
if ( ! -- V_98 || V_97 < V_99 -> V_21 )
return V_99 -> V_21 ;
V_99 -> V_56 = 1 ;
F_78 ( & V_99 -> V_54 , V_56 ) ;
}
return 0 ;
}
static void F_79 ( struct V_1 * V_42 ,
struct V_58 * V_56 )
{
struct V_58 * V_96 = V_42 -> V_63 ;
struct V_100 * const V_101 = V_42 -> signal ;
struct V_32 * V_102 = & V_42 -> V_66 ;
unsigned long long V_21 ;
unsigned long V_103 ;
V_21 = F_76 ( V_96 , V_56 , F_23 ( V_42 ) ) ;
V_102 -> V_68 = F_60 ( V_21 ) ;
V_21 = F_76 ( ++ V_96 , V_56 , F_24 ( V_42 ) ) ;
V_102 -> V_69 = F_60 ( V_21 ) ;
V_102 -> V_70 = F_76 ( ++ V_96 , V_56 ,
V_42 -> V_62 . V_35 ) ;
V_103 = F_80 ( V_101 -> V_104 [ V_105 ] . V_106 ) ;
if ( V_103 != V_107 ) {
unsigned long V_108 =
F_80 ( V_101 -> V_104 [ V_105 ] . V_109 ) ;
if ( V_108 != V_107 &&
V_42 -> V_110 . V_111 > F_81 ( V_108 , V_112 / V_36 ) ) {
F_82 ( V_113 , V_114 , V_42 ) ;
return;
}
if ( V_42 -> V_110 . V_111 > F_81 ( V_103 , V_112 / V_36 ) ) {
if ( V_103 < V_108 ) {
V_103 += V_112 ;
V_101 -> V_104 [ V_105 ] . V_106 = V_103 ;
}
F_83 ( V_115
L_1 ,
V_42 -> V_116 , F_84 ( V_42 ) ) ;
F_82 ( V_117 , V_114 , V_42 ) ;
}
}
}
static void F_85 ( struct V_100 * V_101 )
{
struct F_30 * V_44 = & V_101 -> V_44 ;
unsigned long V_46 ;
F_32 ( & V_44 -> V_48 , V_46 ) ;
V_44 -> V_47 = 0 ;
F_33 ( & V_44 -> V_48 , V_46 ) ;
}
static void F_86 ( struct V_1 * V_42 , struct V_118 * V_29 ,
unsigned long long * V_21 ,
unsigned long long V_119 , int V_120 )
{
if ( ! V_29 -> V_21 )
return;
if ( V_119 >= V_29 -> V_21 ) {
if ( V_29 -> V_28 ) {
V_29 -> V_21 += V_29 -> V_28 ;
V_29 -> error += V_29 -> V_121 ;
if ( V_29 -> error >= V_122 ) {
V_29 -> V_21 -= V_123 ;
V_29 -> error -= V_122 ;
}
} else {
V_29 -> V_21 = 0 ;
}
F_87 ( V_120 == V_124 ?
V_125 : V_126 ,
V_42 -> signal -> V_127 , V_119 ) ;
F_82 ( V_120 , V_114 , V_42 ) ;
}
if ( V_29 -> V_21 && ( ! * V_21 || V_29 -> V_21 < * V_21 ) ) {
* V_21 = V_29 -> V_21 ;
}
}
static void F_88 ( struct V_1 * V_42 ,
struct V_58 * V_56 )
{
struct V_100 * const V_101 = V_42 -> signal ;
unsigned long long V_33 , V_128 , V_129 , V_130 ;
unsigned long long V_131 , V_132 ;
struct V_58 * V_96 = V_101 -> V_63 ;
struct V_32 V_4 ;
unsigned long V_103 ;
F_30 ( V_42 , & V_4 ) ;
V_33 = F_16 ( V_4 . V_33 ) ;
V_128 = V_33 + F_16 ( V_4 . V_34 ) ;
V_131 = V_4 . V_35 ;
V_130 = F_76 ( V_96 , V_56 , V_128 ) ;
V_129 = F_76 ( ++ V_96 , V_56 , V_33 ) ;
V_132 = F_76 ( ++ V_96 , V_56 , V_131 ) ;
F_86 ( V_42 , & V_101 -> V_29 [ V_7 ] , & V_130 , V_128 ,
V_124 ) ;
F_86 ( V_42 , & V_101 -> V_29 [ V_39 ] , & V_129 , V_33 ,
V_133 ) ;
V_103 = F_80 ( V_101 -> V_104 [ V_134 ] . V_106 ) ;
if ( V_103 != V_107 ) {
unsigned long V_135 = F_89 ( V_128 ) ;
unsigned long V_108 =
F_80 ( V_101 -> V_104 [ V_134 ] . V_109 ) ;
T_1 V_136 ;
if ( V_135 >= V_108 ) {
F_82 ( V_113 , V_114 , V_42 ) ;
return;
}
if ( V_135 >= V_103 ) {
F_82 ( V_117 , V_114 , V_42 ) ;
if ( V_103 < V_108 ) {
V_103 ++ ;
V_101 -> V_104 [ V_134 ] . V_106 = V_103 ;
}
}
V_136 = F_2 ( V_103 ) ;
if ( ! V_130 || V_136 < V_130 ) {
V_130 = V_136 ;
}
}
V_101 -> V_66 . V_68 = F_60 ( V_130 ) ;
V_101 -> V_66 . V_69 = F_60 ( V_129 ) ;
V_101 -> V_66 . V_70 = V_132 ;
if ( F_22 ( & V_101 -> V_66 ) )
F_85 ( V_101 ) ;
}
void F_64 ( struct V_23 * V_24 )
{
struct V_51 * V_5 ;
unsigned long V_46 ;
struct V_1 * V_9 = V_24 -> V_29 . V_30 . V_2 ;
unsigned long long V_25 ;
F_44 ( V_9 == NULL ) ;
if ( F_11 ( V_24 -> V_53 ) ) {
F_27 ( V_24 -> V_53 , V_9 , & V_25 ) ;
F_21 ( V_24 , V_25 ) ;
if ( F_45 ( V_9 -> V_137 ) )
goto V_90;
V_5 = F_36 ( V_9 , & V_46 ) ;
if ( ! V_5 )
goto V_90;
} else {
V_5 = F_36 ( V_9 , & V_46 ) ;
if ( F_45 ( V_5 == NULL ) ) {
V_24 -> V_29 . V_30 . V_21 = 0 ;
goto V_90;
} else if ( F_45 ( V_9 -> V_137 ) && F_90 ( V_9 ) ) {
F_38 ( V_9 , & V_46 ) ;
goto V_90;
}
F_65 ( V_24 -> V_53 , V_9 , & V_25 ) ;
F_21 ( V_24 , V_25 ) ;
}
F_44 ( ! F_74 () ) ;
F_57 ( V_24 ) ;
F_38 ( V_9 , & V_46 ) ;
F_69 () ;
V_90:
V_24 -> V_94 = V_24 -> V_31 ;
V_24 -> V_31 = - 1 ;
++ V_24 -> V_76 ;
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
static inline int F_92 ( struct V_1 * V_42 )
{
struct V_100 * V_101 ;
T_1 V_33 , V_34 ;
V_32 ( V_42 , & V_33 , & V_34 ) ;
if ( ! F_22 ( & V_42 -> V_66 ) ) {
struct V_32 V_138 = {
. V_33 = V_33 ,
. V_34 = V_34 ,
. V_35 = V_42 -> V_62 . V_35
} ;
if ( F_91 ( & V_138 , & V_42 -> V_66 ) )
return 1 ;
}
V_101 = V_42 -> signal ;
if ( V_101 -> V_44 . V_47 ) {
struct V_32 V_139 ;
F_93 ( & V_101 -> V_44 . V_48 ) ;
V_139 = V_101 -> V_44 . V_4 ;
F_94 ( & V_101 -> V_44 . V_48 ) ;
if ( F_91 ( & V_139 , & V_101 -> V_66 ) )
return 1 ;
}
return 0 ;
}
void F_95 ( struct V_1 * V_42 )
{
F_96 ( V_56 ) ;
struct V_23 * V_24 , * V_61 ;
unsigned long V_46 ;
F_44 ( ! F_74 () ) ;
if ( ! F_92 ( V_42 ) )
return;
if ( ! F_36 ( V_42 , & V_46 ) )
return;
F_79 ( V_42 , & V_56 ) ;
if ( V_42 -> signal -> V_44 . V_47 )
F_88 ( V_42 , & V_56 ) ;
F_38 ( V_42 , & V_46 ) ;
F_50 (timer, next, &firing, it.cpu.entry) {
int V_140 ;
F_97 ( & V_24 -> V_141 ) ;
F_51 ( & V_24 -> V_29 . V_30 . V_54 ) ;
V_140 = V_24 -> V_29 . V_30 . V_56 ;
V_24 -> V_29 . V_30 . V_56 = 0 ;
if ( F_98 ( V_140 >= 0 ) )
F_61 ( V_24 ) ;
F_99 ( & V_24 -> V_141 ) ;
}
}
void F_4 ( struct V_1 * V_42 , unsigned int V_142 ,
T_1 * V_143 , T_1 * V_144 )
{
unsigned long long V_25 ;
F_44 ( V_142 == V_17 ) ;
F_65 ( V_142 , V_42 , & V_25 ) ;
if ( V_144 ) {
if ( * V_144 ) {
if ( * V_144 <= V_25 ) {
* V_144 = V_123 ;
} else {
* V_144 -= V_25 ;
}
}
if ( ! * V_143 )
goto V_90;
* V_143 += V_25 ;
}
switch ( V_142 ) {
case V_7 :
if ( F_56 ( V_42 -> signal -> V_66 . V_68 , * V_143 ) )
V_42 -> signal -> V_66 . V_68 = * V_143 ;
break;
case V_39 :
if ( F_56 ( V_42 -> signal -> V_66 . V_69 , * V_143 ) )
V_42 -> signal -> V_66 . V_69 = * V_143 ;
break;
}
V_90:
F_69 () ;
}
static int F_100 ( const T_2 V_8 , int V_46 ,
struct V_14 * V_145 , struct V_81 * V_29 )
{
struct V_23 V_24 ;
int error ;
memset ( & V_24 , 0 , sizeof V_24 ) ;
F_101 ( & V_24 . V_141 ) ;
V_24 . V_53 = V_8 ;
V_24 . V_31 = - 1 ;
error = F_40 ( & V_24 ) ;
V_24 . V_75 = V_13 ;
if ( ! error ) {
static struct V_81 V_146 ;
memset ( V_29 , 0 , sizeof *V_29 ) ;
V_29 -> V_88 = * V_145 ;
F_3 ( & V_24 . V_141 ) ;
error = F_73 ( & V_24 , V_46 , V_29 , NULL ) ;
if ( error ) {
F_5 ( & V_24 . V_141 ) ;
return error ;
}
while ( ! F_102 ( V_13 ) ) {
if ( V_24 . V_29 . V_30 . V_21 == 0 ) {
F_43 ( & V_24 ) ;
F_5 ( & V_24 . V_141 ) ;
return 0 ;
}
F_103 ( V_147 ) ;
F_5 ( & V_24 . V_141 ) ;
F_104 () ;
F_3 ( & V_24 . V_141 ) ;
}
F_18 ( V_8 , V_24 . V_29 . V_30 . V_21 , V_145 ) ;
error = F_73 ( & V_24 , 0 , & V_146 , V_29 ) ;
if ( ! error ) {
F_43 ( & V_24 ) ;
}
F_5 ( & V_24 . V_141 ) ;
while ( error == V_57 ) {
F_3 ( & V_24 . V_141 ) ;
error = F_43 ( & V_24 ) ;
F_5 ( & V_24 . V_141 ) ;
}
if ( ( V_29 -> V_88 . V_18 | V_29 -> V_88 . V_20 ) == 0 ) {
return 0 ;
}
error = - V_148 ;
}
return error ;
}
static int F_105 ( const T_2 V_8 , int V_46 ,
struct V_14 * V_145 , struct V_14 T_4 * V_149 )
{
struct V_150 * V_150 =
& F_106 () -> V_150 ;
struct V_81 V_29 ;
int error ;
if ( F_11 ( V_8 ) &&
( F_7 ( V_8 ) == 0 ||
F_7 ( V_8 ) == V_13 -> V_10 ) )
return - V_12 ;
error = F_100 ( V_8 , V_46 , V_145 , & V_29 ) ;
if ( error == - V_148 ) {
if ( V_46 & V_91 )
return - V_151 ;
if ( V_149 && F_107 ( V_149 , & V_29 . V_88 , sizeof *V_149 ) )
return - V_152 ;
V_150 -> V_153 = V_154 ;
V_150 -> V_155 . V_156 = V_8 ;
V_150 -> V_155 . V_149 = V_149 ;
V_150 -> V_155 . V_21 = F_108 ( V_145 ) ;
}
return error ;
}
static long V_154 ( struct V_150 * V_150 )
{
T_2 V_8 = V_150 -> V_155 . V_156 ;
struct V_14 V_99 ;
struct V_81 V_29 ;
int error ;
V_99 = F_19 ( V_150 -> V_155 . V_21 ) ;
error = F_100 ( V_8 , V_91 , & V_99 , & V_29 ) ;
if ( error == - V_148 ) {
struct V_14 T_4 * V_149 = V_150 -> V_155 . V_149 ;
if ( V_149 && F_107 ( V_149 , & V_29 . V_88 , sizeof *V_149 ) )
return - V_152 ;
V_150 -> V_155 . V_21 = F_108 ( & V_99 ) ;
}
return error ;
}
static int F_109 ( const T_2 V_8 ,
struct V_14 * V_15 )
{
return F_25 ( V_157 , V_15 ) ;
}
static int F_110 ( const T_2 V_8 ,
struct V_14 * V_15 )
{
return F_39 ( V_157 , V_15 ) ;
}
static int F_111 ( struct V_23 * V_24 )
{
V_24 -> V_53 = V_157 ;
return F_40 ( V_24 ) ;
}
static int F_112 ( const T_2 V_8 , int V_46 ,
struct V_14 * V_145 ,
struct V_14 T_4 * V_149 )
{
return F_105 ( V_157 , V_46 , V_145 , V_149 ) ;
}
static long F_113 ( struct V_150 * V_150 )
{
return - V_12 ;
}
static int F_114 ( const T_2 V_8 ,
struct V_14 * V_15 )
{
return F_25 ( V_158 , V_15 ) ;
}
static int F_115 ( const T_2 V_8 ,
struct V_14 * V_15 )
{
return F_39 ( V_158 , V_15 ) ;
}
static int F_116 ( struct V_23 * V_24 )
{
V_24 -> V_53 = V_158 ;
return F_40 ( V_24 ) ;
}
static T_5 int F_117 ( void )
{
struct V_159 V_160 = {
. V_161 = F_109 ,
. V_162 = F_110 ,
. V_163 = F_111 ,
. V_164 = F_112 ,
. V_165 = F_113 ,
} ;
struct V_159 V_166 = {
. V_161 = F_114 ,
. V_162 = F_115 ,
. V_163 = F_116 ,
} ;
struct V_14 V_167 ;
F_118 ( V_168 , & V_160 ) ;
F_118 ( V_169 , & V_166 ) ;
F_20 ( V_123 , & V_167 ) ;
V_122 = V_167 . V_20 ;
F_119 ( V_167 . V_18 != 0 ) ;
return 0 ;
}
