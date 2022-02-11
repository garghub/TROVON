void
F_1 (
struct V_1 * V_1 ,
int * V_2 ,
int * V_3 )
{
struct V_4 * V_5 , * V_6 ;
* V_2 = * V_3 = 0 ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) )
( * V_3 ) = 1 ;
else if ( F_4 ( V_5 ) )
( * V_2 ) = 1 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
}
struct V_8 *
F_5 (
struct V_9 * V_9 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( F_7 ( V_11 ) )
return V_13 -> V_15 -> V_16 ;
else
return V_13 -> V_17 -> V_16 ;
}
struct V_18 *
F_8 (
struct V_9 * V_9 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( F_7 ( V_11 ) )
return V_13 -> V_15 -> V_19 ;
else
return V_13 -> V_17 -> V_19 ;
}
static void
F_9 (
struct V_9 * V_9 ,
struct V_20 * V_21 ,
int error )
{
struct V_4 * V_6 = F_2 ( V_21 -> V_22 ) , * V_5 = V_6 ;
bool V_23 = false ;
unsigned int V_24 = 0 ;
unsigned long V_25 ;
ASSERT ( V_21 -> V_26 < V_27 ) ;
ASSERT ( ( V_21 -> V_26 & ( F_10 ( V_9 ) - 1 ) ) == 0 ) ;
ASSERT ( V_21 -> V_26 + V_21 -> V_28 <= V_27 ) ;
ASSERT ( ( V_21 -> V_28 & ( F_10 ( V_9 ) - 1 ) ) == 0 ) ;
F_11 ( V_25 ) ;
F_12 ( V_29 , & V_6 -> V_30 ) ;
do {
if ( V_24 >= V_21 -> V_26 &&
V_24 < V_21 -> V_26 + V_21 -> V_28 ) {
ASSERT ( F_13 ( V_5 ) ) ;
ASSERT ( V_5 -> V_31 == NULL ) ;
if ( error ) {
F_14 ( V_5 ) ;
F_15 ( V_5 ) ;
F_16 ( V_21 -> V_22 ) ;
} else {
F_17 ( V_5 ) ;
}
F_18 ( V_5 ) ;
F_19 ( V_5 ) ;
} else if ( F_13 ( V_5 ) ) {
ASSERT ( F_20 ( V_5 ) ) ;
V_23 = true ;
}
V_24 += V_5 -> V_32 ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_21 ( V_29 , & V_6 -> V_30 ) ;
F_22 ( V_25 ) ;
if ( ! V_23 )
F_23 ( V_21 -> V_22 ) ;
}
STATIC void
F_24 (
struct V_33 * V_34 ,
int error )
{
struct V_9 * V_9 = V_34 -> V_35 ;
struct V_36 * V_36 = & V_34 -> V_37 ;
struct V_36 * V_38 = V_34 -> V_39 , * V_40 ;
T_1 V_41 = V_36 -> V_42 . V_43 ;
bool V_44 = F_25 ( V_36 , V_45 ) ;
for ( V_36 = & V_34 -> V_37 ; V_36 ; V_36 = V_40 ) {
struct V_20 * V_21 ;
int V_46 ;
if ( V_36 == V_38 )
V_40 = NULL ;
else
V_40 = V_36 -> V_47 ;
F_26 (bvec, bio, i)
F_9 ( V_9 , V_21 , error ) ;
F_27 ( V_36 ) ;
}
if ( F_28 ( error && ! V_44 ) ) {
F_29 ( F_6 ( V_9 ) -> V_14 ,
L_1 , V_41 ) ;
}
}
static inline bool F_30 ( struct V_33 * V_34 )
{
return V_34 -> V_48 + V_34 -> V_49 >
F_6 ( V_34 -> V_35 ) -> V_50 . V_51 ;
}
STATIC int
F_31 (
struct V_33 * V_34 )
{
struct V_12 * V_13 = F_6 ( V_34 -> V_35 ) -> V_14 ;
struct V_52 * V_53 ;
int error ;
error = F_32 ( V_13 , & F_33 ( V_13 ) -> V_54 , 0 , 0 , 0 , & V_53 ) ;
if ( error )
return error ;
V_34 -> V_55 = V_53 ;
F_34 ( V_34 -> V_35 -> V_56 , V_57 ) ;
F_35 ( & V_53 -> V_58 , V_59 ) ;
return 0 ;
}
STATIC int
F_36 (
struct V_10 * V_11 ,
struct V_52 * V_53 ,
T_2 V_60 ,
T_3 V_61 )
{
T_4 V_62 ;
F_37 ( V_11 , V_63 ) ;
V_62 = F_38 ( V_11 , V_60 + V_61 ) ;
if ( ! V_62 ) {
F_39 ( V_11 , V_63 ) ;
F_40 ( V_53 ) ;
return 0 ;
}
F_41 ( V_11 , V_60 , V_61 ) ;
V_11 -> V_50 . V_51 = V_62 ;
F_42 ( V_53 , V_11 , V_63 ) ;
F_43 ( V_53 , V_11 , V_64 ) ;
return F_44 ( V_53 ) ;
}
int
F_45 (
struct V_10 * V_11 ,
T_2 V_60 ,
T_3 V_61 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_52 * V_53 ;
int error ;
error = F_32 ( V_13 , & F_33 ( V_13 ) -> V_54 , 0 , 0 , 0 , & V_53 ) ;
if ( error )
return error ;
return F_36 ( V_11 , V_53 , V_60 , V_61 ) ;
}
STATIC int
F_46 (
struct V_33 * V_34 ,
int error )
{
struct V_10 * V_11 = F_6 ( V_34 -> V_35 ) ;
struct V_52 * V_53 = V_34 -> V_55 ;
F_47 ( & V_53 -> V_58 , V_59 ) ;
F_48 ( F_49 ( V_11 ) -> V_56 , V_57 ) ;
if ( error ) {
F_40 ( V_53 ) ;
return error ;
}
return F_36 ( V_11 , V_53 , V_34 -> V_48 , V_34 -> V_49 ) ;
}
STATIC void
F_50 (
struct V_65 * V_66 )
{
struct V_33 * V_34 =
F_51 ( V_66 , struct V_33 , V_67 ) ;
struct V_10 * V_11 = F_6 ( V_34 -> V_35 ) ;
T_2 V_60 = V_34 -> V_48 ;
T_3 V_61 = V_34 -> V_49 ;
int error ;
if ( F_52 ( V_11 -> V_14 ) ) {
error = - V_68 ;
goto V_69;
}
error = F_53 ( V_34 -> V_39 -> V_70 ) ;
if ( F_28 ( error ) ) {
switch ( V_34 -> V_71 ) {
case V_72 :
F_54 ( V_11 , V_60 , V_61 , true ) ;
break;
}
goto V_69;
}
switch ( V_34 -> V_71 ) {
case V_72 :
error = F_55 ( V_11 , V_60 , V_61 ) ;
break;
case V_73 :
error = F_56 ( V_11 , V_60 , V_61 , false ) ;
break;
default:
ASSERT ( ! F_30 ( V_34 ) || V_34 -> V_55 ) ;
break;
}
V_69:
if ( V_34 -> V_55 )
error = F_46 ( V_34 , error ) ;
F_24 ( V_34 , error ) ;
}
STATIC void
F_57 (
struct V_36 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_47 ;
struct V_12 * V_13 = F_6 ( V_34 -> V_35 ) -> V_14 ;
if ( V_34 -> V_71 == V_73 || V_34 -> V_71 == V_72 )
F_58 ( V_13 -> V_74 , & V_34 -> V_67 ) ;
else if ( V_34 -> V_55 )
F_58 ( V_13 -> V_75 , & V_34 -> V_67 ) ;
else
F_24 ( V_34 , F_53 ( V_36 -> V_70 ) ) ;
}
STATIC int
F_59 (
struct V_9 * V_9 ,
T_5 V_60 ,
struct V_76 * V_77 ,
int type )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_6 V_78 = F_10 ( V_9 ) ;
T_7 V_79 , V_80 ;
int error = 0 ;
int V_81 = V_82 ;
int V_83 = 1 ;
if ( F_52 ( V_13 ) )
return - V_68 ;
ASSERT ( type != V_72 ) ;
if ( type == V_73 )
V_81 |= V_84 ;
F_37 ( V_11 , V_85 ) ;
ASSERT ( V_11 -> V_50 . V_86 != V_87 ||
( V_11 -> V_88 . V_89 & V_90 ) ) ;
ASSERT ( V_60 <= V_13 -> V_91 -> V_92 ) ;
if ( V_60 + V_78 > V_13 -> V_91 -> V_92 )
V_78 = V_13 -> V_91 -> V_92 - V_60 ;
V_80 = F_60 ( V_13 , ( V_93 ) V_60 + V_78 ) ;
V_79 = F_61 ( V_13 , V_60 ) ;
error = F_62 ( V_11 , V_79 , V_80 - V_79 ,
V_77 , & V_83 , V_81 ) ;
if ( V_83 && type == V_94 )
F_63 ( V_11 , V_79 , V_77 ) ;
F_39 ( V_11 , V_85 ) ;
if ( error )
return error ;
if ( type == V_95 &&
( ! V_83 || F_64 ( V_77 -> V_96 ) ) ) {
error = F_65 ( V_11 , V_97 , V_60 ,
V_77 ) ;
if ( ! error )
F_66 ( V_11 , V_60 , V_78 , type , V_77 ) ;
return error ;
}
#ifdef F_67
if ( type == V_73 ) {
ASSERT ( V_83 ) ;
ASSERT ( V_77 -> V_96 != V_98 ) ;
ASSERT ( V_77 -> V_96 != V_99 ) ;
}
#endif
if ( V_83 )
F_68 ( V_11 , V_60 , V_78 , type , V_77 ) ;
return 0 ;
}
STATIC bool
F_69 (
struct V_9 * V_9 ,
struct V_76 * V_77 ,
T_2 V_60 )
{
V_60 >>= V_9 -> V_100 ;
F_70 ( V_77 , F_6 ( V_9 ) ) ;
return V_60 >= V_77 -> V_101 &&
V_60 < V_77 -> V_101 + V_77 -> V_102 ;
}
STATIC void
F_71 (
struct V_4 * V_5 )
{
ASSERT ( F_72 ( V_5 ) ) ;
ASSERT ( F_20 ( V_5 ) ) ;
ASSERT ( ! F_4 ( V_5 ) ) ;
ASSERT ( ! F_3 ( V_5 ) ) ;
V_5 -> V_31 = NULL ;
F_73 ( V_5 ) ;
F_17 ( V_5 ) ;
F_74 ( V_5 ) ;
}
STATIC void
F_75 (
struct V_1 * V_1 ,
int V_103 )
{
ASSERT ( F_76 ( V_1 ) ) ;
ASSERT ( ! F_77 ( V_1 ) ) ;
if ( V_103 ) {
F_78 ( V_1 ) ;
F_79 ( V_1 ) ;
} else
F_80 ( V_1 ) ;
F_81 ( V_1 ) ;
}
static inline int F_82 ( struct V_36 * V_36 , struct V_4 * V_5 )
{
return F_83 ( V_36 , V_5 -> V_104 , V_5 -> V_32 , F_84 ( V_5 ) ) ;
}
STATIC int
F_85 (
struct V_105 * V_106 ,
struct V_33 * V_34 ,
int V_107 )
{
if ( ! V_107 && V_34 -> V_71 == V_72 ) {
V_107 = F_86 ( F_6 ( V_34 -> V_35 ) ,
V_34 -> V_48 , V_34 -> V_49 ) ;
}
if ( ! V_107 &&
V_34 -> V_71 != V_73 &&
F_30 ( V_34 ) &&
! V_34 -> V_55 )
V_107 = F_31 ( V_34 ) ;
V_34 -> V_39 -> V_47 = V_34 ;
V_34 -> V_39 -> V_108 = F_57 ;
V_34 -> V_39 -> V_109 = V_110 | F_87 ( V_106 ) ;
if ( V_107 ) {
V_34 -> V_39 -> V_70 = F_88 ( V_107 ) ;
F_89 ( V_34 -> V_39 ) ;
return V_107 ;
}
V_34 -> V_39 -> V_111 = V_34 -> V_35 -> V_112 ;
F_90 ( V_34 -> V_39 ) ;
return 0 ;
}
static void
F_91 (
struct V_36 * V_36 ,
struct V_4 * V_5 )
{
V_36 -> V_42 . V_43 = V_5 -> V_113 * ( V_5 -> V_32 >> 9 ) ;
F_92 ( V_36 , V_5 -> V_114 ) ;
}
static struct V_33 *
F_93 (
struct V_9 * V_9 ,
unsigned int type ,
T_2 V_60 ,
struct V_4 * V_5 )
{
struct V_33 * V_34 ;
struct V_36 * V_36 ;
V_36 = F_94 ( V_115 , V_116 , V_117 ) ;
F_91 ( V_36 , V_5 ) ;
V_34 = F_51 ( V_36 , struct V_33 , V_37 ) ;
F_95 ( & V_34 -> V_118 ) ;
V_34 -> V_71 = type ;
V_34 -> V_35 = V_9 ;
V_34 -> V_49 = 0 ;
V_34 -> V_48 = V_60 ;
F_96 ( & V_34 -> V_67 , F_50 ) ;
V_34 -> V_55 = NULL ;
V_34 -> V_39 = V_36 ;
return V_34 ;
}
static void
F_97 (
struct V_33 * V_34 ,
struct V_105 * V_106 ,
struct V_4 * V_5 )
{
struct V_36 * V_119 ;
V_119 = F_98 ( V_115 , V_116 ) ;
F_91 ( V_119 , V_5 ) ;
F_99 ( V_34 -> V_39 , V_119 ) ;
F_100 ( V_34 -> V_39 ) ;
V_34 -> V_39 -> V_109 = V_110 | F_87 ( V_106 ) ;
V_34 -> V_39 -> V_111 = V_34 -> V_35 -> V_112 ;
F_90 ( V_34 -> V_39 ) ;
V_34 -> V_39 = V_119 ;
}
STATIC void
F_101 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
T_2 V_60 ,
struct V_120 * V_121 ,
struct V_105 * V_106 ,
struct V_122 * V_123 )
{
if ( ! V_121 -> V_34 || V_121 -> V_71 != V_121 -> V_34 -> V_71 ||
V_5 -> V_113 != V_121 -> V_124 + 1 ||
V_60 != V_121 -> V_34 -> V_48 + V_121 -> V_34 -> V_49 ) {
if ( V_121 -> V_34 )
F_102 ( & V_121 -> V_34 -> V_118 , V_123 ) ;
V_121 -> V_34 = F_93 ( V_9 , V_121 -> V_71 , V_60 , V_5 ) ;
}
while ( F_82 ( V_121 -> V_34 -> V_39 , V_5 ) != V_5 -> V_32 )
F_97 ( V_121 -> V_34 , V_106 , V_5 ) ;
V_121 -> V_34 -> V_49 += V_5 -> V_32 ;
V_121 -> V_124 = V_5 -> V_113 ;
F_71 ( V_5 ) ;
}
STATIC void
F_103 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_76 * V_77 ,
T_2 V_60 )
{
T_8 V_125 ;
struct V_12 * V_126 = F_6 ( V_9 ) -> V_14 ;
T_2 V_127 = F_104 ( V_126 , V_77 -> V_101 ) ;
T_9 V_128 = F_105 ( F_6 ( V_9 ) , V_77 -> V_96 ) ;
ASSERT ( V_77 -> V_96 != V_98 ) ;
ASSERT ( V_77 -> V_96 != V_99 ) ;
V_125 = ( V_128 >> ( V_9 -> V_100 - V_129 ) ) +
( ( V_60 - V_127 ) >> V_9 -> V_100 ) ;
ASSERT ( V_125 || F_7 ( F_6 ( V_9 ) ) ) ;
V_5 -> V_113 = V_125 ;
F_106 ( V_5 ) ;
}
STATIC void
F_107 (
struct V_9 * V_9 ,
struct V_4 * V_5 ,
struct V_76 * V_77 ,
T_2 V_60 )
{
ASSERT ( V_77 -> V_96 != V_98 ) ;
ASSERT ( V_77 -> V_96 != V_99 ) ;
F_103 ( V_9 , V_5 , V_77 , V_60 ) ;
F_106 ( V_5 ) ;
F_108 ( V_5 ) ;
F_109 ( V_5 ) ;
}
STATIC bool
F_110 (
struct V_1 * V_1 ,
unsigned int type ,
bool V_130 )
{
struct V_4 * V_5 ;
struct V_4 * V_6 ;
if ( F_77 ( V_1 ) )
return false ;
if ( ! V_1 -> V_131 )
return false ;
if ( ! F_111 ( V_1 ) )
return false ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
if ( F_3 ( V_5 ) ) {
if ( type == V_73 )
return true ;
} else if ( F_4 ( V_5 ) ) {
if ( type == V_95 )
return true ;
} else if ( F_112 ( V_5 ) && F_72 ( V_5 ) ) {
if ( type == V_94 )
return true ;
}
if ( ! V_130 )
break;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
return false ;
}
STATIC void
F_113 (
struct V_1 * V_1 ,
unsigned int V_60 ,
unsigned int V_132 )
{
F_114 ( V_1 -> V_131 -> V_133 , V_1 , V_60 ,
V_132 ) ;
if ( V_60 == 0 && V_132 >= V_27 )
F_115 ( V_1 ) ;
F_116 ( V_1 , V_60 , V_132 ) ;
}
STATIC void
F_117 (
struct V_1 * V_1 )
{
struct V_9 * V_9 = V_1 -> V_131 -> V_133 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_4 * V_5 , * V_6 ;
T_5 V_60 = F_118 ( V_1 ) ;
if ( ! F_110 ( V_1 , V_95 , true ) )
goto V_134;
if ( F_52 ( V_11 -> V_14 ) )
goto V_134;
F_119 ( V_11 -> V_14 ,
L_2 ,
V_1 , V_11 -> V_135 , V_60 ) ;
F_37 ( V_11 , V_63 ) ;
V_5 = V_6 = F_2 ( V_1 ) ;
do {
int error ;
T_7 V_136 ;
if ( ! F_4 ( V_5 ) )
goto V_137;
V_136 = F_61 ( V_11 -> V_14 , V_60 ) ;
error = F_120 ( V_11 , V_136 , 1 ) ;
if ( error ) {
if ( ! F_52 ( V_11 -> V_14 ) ) {
F_119 ( V_11 -> V_14 ,
L_3 ) ;
}
break;
}
V_137:
V_60 += F_10 ( V_9 ) ;
} while ( ( V_5 = V_5 -> V_7 ) != V_6 );
F_39 ( V_11 , V_63 ) ;
V_134:
F_113 ( V_1 , 0 , V_27 ) ;
return;
}
static int
F_121 (
struct V_120 * V_121 ,
struct V_9 * V_9 ,
T_5 V_60 ,
unsigned int * V_138 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_76 V_77 ;
bool V_139 = false ;
int error ;
if ( V_121 -> V_71 == V_72 ) {
V_121 -> V_140 = F_69 ( V_9 , & V_121 -> V_77 , V_60 ) ;
if ( V_121 -> V_140 ) {
* V_138 = V_72 ;
return 0 ;
}
}
F_37 ( V_11 , V_85 ) ;
V_139 = F_122 ( V_11 , V_60 , & V_77 ) ;
F_39 ( V_11 , V_85 ) ;
if ( ! V_139 )
return 0 ;
if ( F_64 ( V_77 . V_96 ) ) {
error = F_65 ( V_11 , V_141 , V_60 ,
& V_77 ) ;
if ( error )
return error ;
}
V_121 -> V_71 = * V_138 = V_72 ;
V_121 -> V_140 = true ;
V_121 -> V_77 = V_77 ;
return 0 ;
}
static int
F_123 (
struct V_120 * V_121 ,
struct V_105 * V_106 ,
struct V_9 * V_9 ,
struct V_1 * V_1 ,
T_5 V_60 ,
T_10 V_142 )
{
F_124 ( V_143 ) ;
struct V_33 * V_34 , * V_40 ;
struct V_4 * V_5 , * V_6 ;
T_6 V_144 = F_10 ( V_9 ) ;
int error = 0 ;
int V_78 = 0 ;
int V_145 = 1 ;
unsigned int V_138 ;
V_5 = V_6 = F_2 ( V_1 ) ;
V_60 = F_118 ( V_1 ) ;
do {
if ( V_60 >= V_142 )
break;
if ( ! F_125 ( V_5 ) )
V_145 = 0 ;
if ( ! F_72 ( V_5 ) && F_125 ( V_5 ) ) {
V_121 -> V_140 = false ;
continue;
}
if ( F_3 ( V_5 ) )
V_138 = V_73 ;
else if ( F_4 ( V_5 ) )
V_138 = V_95 ;
else if ( F_125 ( V_5 ) )
V_138 = V_94 ;
else {
if ( F_126 ( V_1 ) )
ASSERT ( F_72 ( V_5 ) ) ;
V_121 -> V_140 = false ;
continue;
}
if ( F_127 ( F_6 ( V_9 ) ) ) {
error = F_121 ( V_121 , V_9 , V_60 , & V_138 ) ;
if ( error )
goto V_146;
}
if ( V_121 -> V_71 != V_138 ) {
V_121 -> V_71 = V_138 ;
V_121 -> V_140 = false ;
}
if ( V_121 -> V_140 )
V_121 -> V_140 = F_69 ( V_9 , & V_121 -> V_77 ,
V_60 ) ;
if ( ! V_121 -> V_140 ) {
error = F_59 ( V_9 , V_60 , & V_121 -> V_77 ,
V_121 -> V_71 ) ;
if ( error )
goto V_146;
V_121 -> V_140 = F_69 ( V_9 , & V_121 -> V_77 ,
V_60 ) ;
}
if ( V_121 -> V_140 ) {
F_128 ( V_5 ) ;
if ( V_121 -> V_71 != V_94 )
F_107 ( V_9 , V_5 , & V_121 -> V_77 , V_60 ) ;
F_101 ( V_9 , V_5 , V_60 , V_121 , V_106 , & V_143 ) ;
V_78 ++ ;
}
} while ( V_60 += V_144 , ( ( V_5 = V_5 -> V_7 ) != V_6 ) );
if ( V_145 && V_5 == V_6 )
F_129 ( V_1 ) ;
ASSERT ( V_121 -> V_34 || F_130 ( & V_143 ) ) ;
V_146:
if ( V_78 ) {
F_75 ( V_1 , ! error ) ;
F_131 (ioend, next, &submit_list, io_list) {
int V_147 ;
F_132 ( & V_34 -> V_118 ) ;
V_147 = F_85 ( V_106 , V_34 , error ) ;
if ( V_147 && ! error )
error = V_147 ;
}
} else if ( error ) {
F_117 ( V_1 ) ;
F_133 ( V_1 ) ;
F_81 ( V_1 ) ;
} else {
F_75 ( V_1 , 1 ) ;
F_23 ( V_1 ) ;
}
F_134 ( V_1 -> V_131 , error ) ;
return error ;
}
STATIC int
F_135 (
struct V_1 * V_1 ,
struct V_105 * V_106 ,
void * V_148 )
{
struct V_120 * V_121 = V_148 ;
struct V_9 * V_9 = V_1 -> V_131 -> V_133 ;
T_5 V_60 ;
T_10 V_142 ;
T_11 V_149 ;
F_136 ( V_9 , V_1 , 0 , 0 ) ;
ASSERT ( F_111 ( V_1 ) ) ;
if ( F_137 ( ( V_150 -> V_25 & ( V_151 | V_152 ) ) ==
V_151 ) )
goto V_153;
if ( F_137 ( V_150 -> V_25 & V_59 ) )
goto V_153;
V_60 = F_138 ( V_9 ) ;
V_149 = V_60 >> V_154 ;
if ( V_1 -> V_155 < V_149 )
V_142 = ( T_2 ) ( V_1 -> V_155 + 1 ) << V_154 ;
else {
unsigned V_156 = V_60 & ( V_27 - 1 ) ;
if ( V_1 -> V_155 > V_149 ||
( V_1 -> V_155 == V_149 && V_156 == 0 ) )
goto V_153;
F_139 ( V_1 , V_156 , V_27 ) ;
V_142 = V_60 ;
}
return F_123 ( V_121 , V_106 , V_9 , V_1 , V_60 , V_142 ) ;
V_153:
F_140 ( V_106 , V_1 ) ;
F_81 ( V_1 ) ;
return 0 ;
}
STATIC int
F_141 (
struct V_1 * V_1 ,
struct V_105 * V_106 )
{
struct V_120 V_121 = {
. V_71 = V_157 ,
} ;
int V_158 ;
V_158 = F_135 ( V_1 , V_106 , & V_121 ) ;
if ( V_121 . V_34 )
V_158 = F_85 ( V_106 , V_121 . V_34 , V_158 ) ;
return V_158 ;
}
STATIC int
F_142 (
struct V_159 * V_131 ,
struct V_105 * V_106 )
{
struct V_120 V_121 = {
. V_71 = V_157 ,
} ;
int V_158 ;
F_143 ( F_6 ( V_131 -> V_133 ) , V_160 ) ;
if ( F_144 ( V_131 ) )
return F_145 ( V_131 ,
F_5 ( V_131 -> V_133 ) , V_106 ) ;
V_158 = F_146 ( V_131 , V_106 , F_135 , & V_121 ) ;
if ( V_121 . V_34 )
V_158 = F_85 ( V_106 , V_121 . V_34 , V_158 ) ;
return V_158 ;
}
STATIC int
F_147 (
struct V_1 * V_1 ,
T_12 V_161 )
{
int V_2 , V_3 ;
F_148 ( V_1 -> V_131 -> V_133 , V_1 , 0 , 0 ) ;
if ( F_149 ( V_1 ) )
return 0 ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( F_137 ( V_2 ) )
return 0 ;
if ( F_137 ( V_3 ) )
return 0 ;
return F_150 ( V_1 ) ;
}
static void
F_151 (
struct V_9 * V_9 ,
T_8 V_162 ,
struct V_4 * V_163 ,
struct V_76 * V_77 ,
T_2 V_60 ,
T_6 V_61 )
{
T_2 V_164 ;
V_164 = V_77 -> V_101 + V_77 -> V_102 - V_162 ;
V_164 <<= V_9 -> V_100 ;
ASSERT ( V_164 > 0 ) ;
if ( V_164 > V_61 )
V_164 = V_61 ;
if ( V_60 < F_138 ( V_9 ) &&
V_60 + V_164 >= F_138 ( V_9 ) ) {
V_164 = F_152 ( F_138 ( V_9 ) - V_60 ,
F_10 ( V_9 ) ) ;
}
if ( V_164 > V_165 )
V_164 = V_165 ;
V_163 -> V_32 = V_164 ;
}
static int
F_153 (
struct V_9 * V_9 ,
T_8 V_162 ,
struct V_4 * V_163 ,
int V_166 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_7 V_79 , V_80 ;
int error = 0 ;
int V_167 = 0 ;
struct V_76 V_77 ;
int V_83 = 1 ;
T_2 V_60 ;
T_6 V_61 ;
F_154 ( V_166 ) ;
if ( F_52 ( V_13 ) )
return - V_68 ;
V_60 = ( T_2 ) V_162 << V_9 -> V_100 ;
ASSERT ( V_163 -> V_32 >= F_10 ( V_9 ) ) ;
V_61 = V_163 -> V_32 ;
if ( V_60 >= F_138 ( V_9 ) )
return 0 ;
V_167 = F_155 ( V_11 ) ;
ASSERT ( V_60 <= V_13 -> V_91 -> V_92 ) ;
if ( V_60 + V_61 > V_13 -> V_91 -> V_92 )
V_61 = V_13 -> V_91 -> V_92 - V_60 ;
V_80 = F_60 ( V_13 , ( V_93 ) V_60 + V_61 ) ;
V_79 = F_61 ( V_13 , V_60 ) ;
error = F_62 ( V_11 , V_79 , V_80 - V_79 ,
& V_77 , & V_83 , V_82 ) ;
if ( error )
goto V_168;
if ( V_83 ) {
F_156 ( V_11 , V_60 , V_61 ,
V_77 . V_169 == V_170 ?
V_73 : V_94 , & V_77 ) ;
F_39 ( V_11 , V_167 ) ;
} else {
F_157 ( V_11 , V_60 , V_61 ) ;
goto V_168;
}
F_151 ( V_9 , V_162 , V_163 , & V_77 , V_60 , V_61 ) ;
if ( F_158 ( & V_77 ) )
F_103 ( V_9 , V_163 , & V_77 , V_60 ) ;
V_163 -> V_114 = F_5 ( V_9 ) ;
return 0 ;
V_168:
F_39 ( V_11 , V_167 ) ;
return error ;
}
STATIC T_6
F_159 (
struct V_171 * V_172 ,
struct V_173 * V_174 )
{
return - V_175 ;
}
STATIC T_8
F_160 (
struct V_159 * V_131 ,
T_8 V_176 )
{
struct V_9 * V_9 = (struct V_9 * ) V_131 -> V_133 ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
F_161 ( F_6 ( V_9 ) ) ;
if ( F_127 ( V_11 ) || F_7 ( V_11 ) )
return 0 ;
F_162 ( V_131 ) ;
return F_163 ( V_131 , V_176 , F_153 ) ;
}
STATIC int
F_164 (
struct V_177 * V_178 ,
struct V_1 * V_1 )
{
F_165 ( V_1 -> V_131 -> V_133 , 1 ) ;
return F_166 ( V_1 , F_153 ) ;
}
STATIC int
F_167 (
struct V_177 * V_178 ,
struct V_159 * V_131 ,
struct V_122 * V_179 ,
unsigned V_180 )
{
F_168 ( V_131 -> V_133 , V_180 ) ;
return F_169 ( V_131 , V_179 , V_180 , F_153 ) ;
}
STATIC int
F_170 (
struct V_1 * V_1 )
{
struct V_159 * V_131 = V_1 -> V_131 ;
struct V_9 * V_9 = V_131 -> V_133 ;
T_5 V_142 ;
T_5 V_60 ;
int V_181 ;
if ( F_28 ( ! V_131 ) )
return ! F_171 ( V_1 ) ;
V_142 = F_138 ( V_9 ) ;
V_60 = F_118 ( V_1 ) ;
F_172 ( & V_131 -> V_182 ) ;
if ( F_111 ( V_1 ) ) {
struct V_4 * V_6 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_6 ;
do {
if ( V_60 < V_142 )
F_173 ( V_5 ) ;
V_5 = V_5 -> V_7 ;
V_60 += F_10 ( V_9 ) ;
} while ( V_5 != V_6 );
}
F_174 ( V_1 ) ;
V_181 = ! F_171 ( V_1 ) ;
F_175 ( & V_131 -> V_182 ) ;
if ( V_181 ) {
unsigned long V_25 ;
F_176 ( & V_131 -> V_183 , V_25 ) ;
if ( V_1 -> V_131 ) {
F_137 ( ! F_126 ( V_1 ) ) ;
F_177 ( V_1 , V_131 ) ;
F_178 ( & V_131 -> V_184 ,
F_179 ( V_1 ) , V_185 ) ;
}
F_180 ( & V_131 -> V_183 , V_25 ) ;
}
F_181 ( V_1 ) ;
if ( V_181 )
F_182 ( V_131 -> V_133 , V_186 ) ;
return V_181 ;
}
