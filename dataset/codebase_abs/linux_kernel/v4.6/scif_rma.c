void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
F_2 ( & V_4 -> V_6 ) ;
F_3 ( & V_4 -> V_7 , V_8 , V_9 ,
V_10 ) ;
F_4 ( & V_4 -> V_11 ) ;
F_2 ( & V_4 -> V_12 ) ;
F_5 ( & V_4 -> V_13 ) ;
F_5 ( & V_4 -> V_14 ) ;
F_6 ( & V_4 -> V_15 , 0 ) ;
F_6 ( & V_4 -> V_16 , 0 ) ;
F_6 ( & V_4 -> V_17 , 0 ) ;
F_6 ( & V_4 -> V_18 , 0 ) ;
V_4 -> V_19 = 0 ;
V_4 -> V_20 = NULL ;
F_5 ( & V_4 -> V_21 ) ;
F_5 ( & V_4 -> V_22 ) ;
F_7 ( & V_4 -> V_23 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
F_9 ( & V_2 -> V_5 . V_6 ) ;
if ( F_10 ( & V_2 -> V_5 . V_13 ) &&
F_10 ( & V_2 -> V_5 . V_14 ) &&
F_10 ( & V_2 -> V_5 . V_21 ) &&
! F_11 ( & V_2 -> V_5 . V_15 ) &&
! F_11 ( & V_2 -> V_5 . V_16 ) &&
! F_11 ( & V_2 -> V_5 . V_18 ) )
V_24 = 1 ;
F_12 ( & V_2 -> V_5 . V_6 ) ;
return V_24 ;
}
static struct V_25 *
F_13 ( int V_26 , int V_27 )
{
struct V_25 * V_28 ;
F_14 () ;
V_28 = F_15 ( sizeof( * V_28 ) ) ;
if ( ! V_28 )
goto error;
V_28 -> V_29 = F_15 ( V_26 * sizeof( * V_28 -> V_29 ) ) ;
if ( ! V_28 -> V_29 )
goto V_30;
V_28 -> V_27 = V_27 ;
V_28 -> V_31 = V_32 ;
return V_28 ;
V_30:
F_16 ( V_28 , sizeof( * V_28 ) ) ;
error:
return NULL ;
}
static int F_17 ( struct V_25 * V_28 )
{
int V_33 ;
int V_34 = V_28 -> V_27 & V_35 ;
int V_36 = V_37 & V_28 -> V_38 ;
for ( V_33 = 0 ; V_33 < V_28 -> V_26 ; V_33 ++ ) {
if ( V_28 -> V_29 [ V_33 ] && ! V_36 ) {
if ( V_34 )
F_18 ( V_28 -> V_29 [ V_33 ] ) ;
F_19 ( V_28 -> V_29 [ V_33 ] ) ;
}
}
F_16 ( V_28 -> V_29 ,
V_28 -> V_26 * sizeof( * V_28 -> V_29 ) ) ;
F_16 ( V_28 , sizeof( * V_28 ) ) ;
return 0 ;
}
struct V_39 * F_20 ( struct V_1 * V_2 , int V_26 ,
T_1 V_40 , bool V_41 )
{
struct V_39 * V_42 ;
F_14 () ;
V_42 = F_15 ( sizeof( * V_42 ) ) ;
if ( ! V_42 )
goto error;
V_42 -> V_43 = F_15 ( V_26 * sizeof( * V_42 -> V_43 ) ) ;
if ( ! V_42 -> V_43 )
goto V_44;
V_42 -> V_45 = F_15 ( V_26 * sizeof( * V_42 -> V_45 ) ) ;
if ( ! V_42 -> V_45 )
goto V_44;
V_42 -> V_40 = V_40 ;
V_42 -> V_2 = ( V_46 ) V_2 ;
V_42 -> V_31 = V_32 ;
V_42 -> V_47 = V_48 ;
F_7 ( & V_42 -> V_49 ) ;
V_42 -> V_50 = V_48 ;
F_7 ( & V_42 -> V_51 ) ;
F_5 ( & V_42 -> V_52 ) ;
V_42 -> type = V_53 ;
V_42 -> V_41 = V_41 ;
return V_42 ;
V_44:
F_16 ( V_42 -> V_43 ,
V_26 * sizeof( * V_42 -> V_43 ) ) ;
F_16 ( V_42 , sizeof( * V_42 ) ) ;
error:
return NULL ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_39 * V_42 )
{
int V_54 ;
int V_26 = V_42 -> V_26 ;
struct V_55 * V_56 = & V_42 -> V_57 ;
struct V_58 V_59 ;
V_60:
V_54 = F_22 ( V_56 -> V_61 ,
V_56 -> V_62 != V_63 ,
V_64 ) ;
if ( ! V_54 && F_23 ( V_2 ) )
goto V_60;
F_9 ( & V_2 -> V_5 . V_6 ) ;
if ( V_56 -> V_62 == V_65 ) {
V_59 . V_66 = V_67 ;
V_59 . V_68 = V_2 -> V_69 ;
V_59 . V_70 [ 0 ] = V_2 -> V_71 ;
V_59 . V_70 [ 1 ] = V_42 -> V_57 . V_72 ;
V_59 . V_70 [ 2 ] = ( V_46 ) V_42 ;
V_59 . V_70 [ 3 ] = V_73 ;
F_24 ( V_2 -> V_74 , & V_59 ) ;
}
F_12 ( & V_2 -> V_5 . V_6 ) ;
F_25 ( V_2 , V_42 , V_42 -> V_40 ) ;
F_16 ( V_42 -> V_43 , V_26 * sizeof( * V_42 -> V_43 ) ) ;
F_16 ( V_42 -> V_45 , V_26 * sizeof( * V_42 -> V_45 ) ) ;
F_16 ( V_42 , sizeof( * V_42 ) ) ;
}
void F_26 ( struct V_75 * V_74 , struct V_39 * V_42 )
{
int V_33 ;
if ( F_27 () && ! F_28 ( V_74 ) ) {
if ( V_42 -> V_76 ) {
F_29 ( & V_74 -> V_77 -> V_78 ,
V_42 -> V_76 -> V_79 , V_42 -> V_76 -> V_80 ,
V_81 ) ;
F_30 ( V_42 -> V_76 ) ;
F_31 ( V_42 -> V_76 ) ;
V_42 -> V_76 = NULL ;
}
} else {
for ( V_33 = 0 ; V_33 < V_42 -> V_82 ; V_33 ++ ) {
if ( V_42 -> V_43 [ V_33 ] ) {
F_32 ( V_42 -> V_43 [ V_33 ] ,
V_74 ,
V_42 -> V_45 [ V_33 ] <<
V_83 ) ;
V_42 -> V_43 [ V_33 ] = 0x0 ;
}
}
}
}
static inline struct V_84 * F_33 ( void )
{
if ( V_85 )
return F_34 ( V_86 ) ;
return NULL ;
}
static inline void F_35 ( struct V_84 * V_87 )
{
if ( V_87 )
F_36 ( V_87 ) ;
}
static inline int
F_37 ( struct V_84 * V_87 ,
int V_26 , bool V_88 )
{
if ( ! V_87 || ! V_26 || ! V_85 )
return 0 ;
if ( V_88 ) {
if ( ! F_38 ( & V_87 -> V_89 ) ) {
F_39 ( V_90 . V_91 . V_92 ,
L_1 , V_93 , __LINE__ ) ;
return - 1 ;
}
} else {
F_40 ( & V_87 -> V_89 ) ;
}
V_87 -> V_94 -= V_26 ;
F_41 ( & V_87 -> V_89 ) ;
return 0 ;
}
static inline int F_42 ( struct V_84 * V_87 ,
int V_26 )
{
unsigned long V_95 , V_96 ;
if ( ! V_87 || ! V_26 || ! V_85 )
return 0 ;
V_95 = V_26 ;
V_95 += V_87 -> V_94 ;
V_96 = F_43 ( V_97 ) >> V_83 ;
if ( ( V_95 > V_96 ) && ! F_44 ( V_98 ) ) {
F_39 ( V_90 . V_91 . V_92 ,
L_2 ,
V_95 , V_96 ) ;
return - V_99 ;
}
V_87 -> V_94 = V_95 ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 , struct V_39 * V_42 )
{
int V_33 ;
struct V_25 * V_100 = V_42 -> V_100 ;
int V_26 = V_42 -> V_26 ;
F_14 () ;
if ( ! V_42 -> V_41 && V_42 -> V_87 ) {
F_37 ( V_42 -> V_87 , V_42 -> V_26 , 0 ) ;
F_35 ( V_42 -> V_87 ) ;
V_42 -> V_87 = NULL ;
}
F_25 ( V_2 , V_42 , V_42 -> V_40 ) ;
F_26 ( V_2 -> V_74 , V_42 ) ;
V_33 = F_46 ( 1 , & V_100 -> V_101 ) ;
if ( V_33 < 0 )
F_39 ( V_90 . V_91 . V_92 ,
L_3 ,
V_93 , __LINE__ , V_33 ) ;
if ( ! V_33 )
F_17 ( V_42 -> V_100 ) ;
F_16 ( V_42 -> V_43 , V_26 * sizeof( * V_42 -> V_43 ) ) ;
F_16 ( V_42 -> V_45 , V_26 * sizeof( * V_42 -> V_45 ) ) ;
V_42 -> V_31 = 0 ;
F_16 ( V_42 , sizeof( * V_42 ) ) ;
return 0 ;
}
static int F_47 ( struct V_75 * V_74 ,
struct V_39 * V_42 )
{
int V_102 , V_33 , V_54 = 0 ;
int V_26 = V_42 -> V_26 ;
bool V_103 , V_104 ;
F_14 () ;
V_54 = F_48 ( & V_42 -> V_105 ,
V_42 , V_74 , sizeof( * V_42 ) ) ;
if ( V_54 )
goto V_106;
V_42 -> V_107 = F_49 ( V_26 * V_8 ,
( ( 2 ) * 1024 * 1024 ) ) >> 21 ;
V_42 -> V_108 . V_109 =
F_50 ( & V_42 -> V_108 . V_40 ,
V_74 , V_42 -> V_107 *
sizeof( * V_42 -> V_108 . V_109 ) ,
V_110 | V_111 ) ;
if ( ! V_42 -> V_108 . V_109 ) {
V_54 = - V_99 ;
goto V_106;
}
V_42 -> V_112 . V_109 =
F_50 ( & V_42 -> V_112 . V_40 ,
V_74 , V_42 -> V_107 *
sizeof( * V_42 -> V_112 . V_109 ) ,
V_110 | V_111 ) ;
if ( ! V_42 -> V_112 . V_109 ) {
V_54 = - V_99 ;
goto V_106;
}
V_103 = F_51 ( & V_42 -> V_43 [ 0 ] ) ;
V_104 = F_51 ( & V_42 -> V_45 [ 0 ] ) ;
for ( V_102 = 0 , V_33 = 0 ; V_102 < V_26 ; V_102 += V_113 , V_33 ++ ) {
V_54 = F_52 ( & V_42 -> V_108 . V_109 [ V_33 ] ,
V_103 ?
F_53 ( & V_42 -> V_43 [ V_102 ] ) :
F_54 ( & V_42 -> V_43 [ V_102 ] ) ,
V_74 ) ;
if ( V_54 )
goto V_106;
V_54 = F_52 ( & V_42 -> V_112 . V_109 [ V_33 ] ,
V_103 ?
F_53 ( & V_42 -> V_45 [ V_102 ] ) :
F_54 ( & V_42 -> V_45 [ V_102 ] ) ,
V_74 ) ;
if ( V_54 )
goto V_106;
}
return 0 ;
V_106:
return V_54 ;
}
static void F_55 ( struct V_75 * V_74 ,
struct V_39 * V_42 )
{
int V_102 , V_33 ;
if ( V_42 -> V_107 ) {
struct V_114 * V_115 = & V_42 -> V_108 ;
struct V_114 * V_116 = & V_42 -> V_112 ;
for ( V_102 = 0 , V_33 = 0 ; V_102 < V_42 -> V_26 ;
V_102 += V_113 , V_33 ++ ) {
if ( V_115 -> V_109 && V_115 -> V_109 [ V_33 ] )
F_32 ( V_115 -> V_109 [ V_33 ] ,
V_74 ,
V_8 ) ;
if ( V_116 -> V_109 && V_116 -> V_109 [ V_33 ] )
F_32 ( V_116 -> V_109 [ V_33 ] ,
V_74 ,
V_8 ) ;
}
if ( V_115 -> V_109 )
F_56 ( V_115 -> V_109 , V_115 -> V_40 ,
V_74 , V_42 -> V_107 *
sizeof( * V_115 -> V_109 ) ) ;
if ( V_116 -> V_109 )
F_56 ( V_116 -> V_109 , V_116 -> V_40 ,
V_74 , V_42 -> V_107 *
sizeof( * V_116 -> V_109 ) ) ;
if ( V_42 -> V_105 )
F_32 ( V_42 -> V_105 ,
V_74 , sizeof( * V_42 ) ) ;
V_42 -> V_107 = 0 ;
}
}
static struct V_39 *
F_57 ( struct V_75 * V_117 , int V_26 )
{
struct V_39 * V_42 ;
F_14 () ;
V_42 = F_15 ( sizeof( * V_42 ) ) ;
if ( ! V_42 )
goto V_118;
V_42 -> V_31 = V_32 ;
V_42 -> V_26 = V_26 ;
V_42 -> V_43 = F_15 ( V_26 * sizeof( * V_42 -> V_43 ) ) ;
if ( ! V_42 -> V_43 )
goto V_106;
V_42 -> V_45 = F_15 ( V_26 *
sizeof( * V_42 -> V_45 ) ) ;
if ( ! V_42 -> V_45 )
goto V_106;
if ( F_47 ( V_117 , V_42 ) )
goto V_106;
V_42 -> type = V_119 ;
V_42 -> V_50 = V_48 ;
F_5 ( & V_42 -> V_52 ) ;
return V_42 ;
V_106:
F_58 ( V_42 ) ;
V_118:
return NULL ;
}
void
F_58 ( struct V_39 * V_42 )
{
F_16 ( V_42 -> V_43 , V_42 -> V_26 *
sizeof( * V_42 -> V_43 ) ) ;
F_16 ( V_42 -> V_45 , V_42 -> V_26 *
sizeof( * V_42 -> V_45 ) ) ;
V_42 -> V_31 = 0 ;
F_16 ( V_42 , sizeof( * V_42 ) ) ;
}
static int F_59 ( struct V_75 * V_74 ,
struct V_39 * V_42 )
{
struct V_120 * V_121 ;
int V_102 , V_54 ;
T_2 V_28 = V_42 -> V_100 ;
V_42 -> V_76 = F_60 ( sizeof( * V_42 -> V_76 ) , V_110 ) ;
if ( ! V_42 -> V_76 )
return - V_99 ;
V_54 = F_61 ( V_42 -> V_76 , V_42 -> V_26 , V_110 ) ;
if ( V_54 )
return V_54 ;
F_62 (window->st->sgl, sg, window->st->nents, i)
F_63 ( V_121 , V_28 -> V_29 [ V_102 ] , V_8 , 0x0 ) ;
V_54 = F_64 ( & V_74 -> V_77 -> V_78 , V_42 -> V_76 -> V_79 ,
V_42 -> V_76 -> V_80 , V_81 ) ;
if ( ! V_54 )
return - V_99 ;
V_121 = V_42 -> V_76 -> V_79 ;
for ( V_102 = 0 ; V_121 ; V_102 ++ ) {
T_3 V_122 ;
V_42 -> V_43 [ V_102 ] = F_65 ( V_121 ) ;
V_42 -> V_45 [ V_102 ] = F_66 ( V_121 ) >> V_83 ;
V_122 = F_65 ( V_121 ) + F_66 ( V_121 ) ;
while ( ( V_121 = F_67 ( V_121 ) ) && F_65 ( V_121 ) == V_122 ) {
V_42 -> V_45 [ V_102 ] +=
( F_66 ( V_121 ) >> V_83 ) ;
V_122 = V_42 -> V_43 [ V_102 ] +
F_66 ( V_121 ) ;
}
V_42 -> V_82 ++ ;
}
return 0 ;
}
int
F_68 ( struct V_75 * V_74 , struct V_39 * V_42 )
{
int V_102 , V_33 , V_123 , V_54 = 0 , V_124 ;
T_2 V_28 ;
T_4 V_125 , V_126 ;
F_14 () ;
V_28 = V_42 -> V_100 ;
if ( V_127 && ! F_28 ( V_74 ) )
return F_59 ( V_74 , V_42 ) ;
for ( V_102 = 0 , V_33 = 0 ; V_102 < V_42 -> V_26 ; V_102 += V_124 , V_33 ++ ) {
V_125 = F_69 ( V_28 -> V_29 [ V_102 ] ) ;
V_124 = 1 ;
for ( V_123 = V_102 + 1 ; V_123 < V_42 -> V_26 ; V_123 ++ ) {
V_126 = F_69 ( V_28 -> V_29 [ V_123 ] ) ;
if ( V_126 != ( V_125 + V_8 ) )
break;
V_125 = V_126 ;
V_124 ++ ;
}
V_42 -> V_45 [ V_33 ] = V_124 ;
V_42 -> V_82 ++ ;
if ( F_70 () ) {
V_54 = F_48 ( & V_42 -> V_43 [ V_33 ] ,
F_71 ( F_69 (
V_28 -> V_29 [ V_102 ] ) ) ,
V_74 ,
V_124 << V_83 ) ;
if ( V_54 )
return V_54 ;
} else {
V_42 -> V_43 [ V_33 ] = F_69 ( V_28 -> V_29 [ V_102 ] ) ;
}
}
return V_54 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_39 * V_42 )
{
struct V_58 V_59 ;
V_59 . V_66 = V_128 ;
V_59 . V_68 = V_2 -> V_69 ;
V_59 . V_70 [ 0 ] = V_42 -> V_57 . V_72 ;
V_59 . V_70 [ 1 ] = ( V_46 ) V_42 ;
return F_73 ( V_2 -> V_74 , & V_59 ) ;
}
int F_74 ( struct V_39 * V_42 )
{
int V_54 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_42 -> V_2 ;
bool V_129 = false ;
F_14 () ;
switch ( V_42 -> V_50 ) {
case V_48 :
{
V_42 -> V_50 = V_63 ;
V_129 = true ;
}
case V_63 :
{
F_75 ( V_42 , 1 ) ;
F_12 ( & V_2 -> V_5 . V_6 ) ;
if ( V_129 ) {
V_54 = F_72 ( V_2 , V_42 ) ;
if ( V_54 ) {
V_42 -> V_50 = V_65 ;
goto V_130;
}
} else {
F_9 ( & V_2 -> V_5 . V_6 ) ;
return - V_131 ;
}
V_60:
V_54 = F_22 ( V_42 -> V_51 ,
V_42 -> V_50 != V_63 ,
V_64 ) ;
if ( ! V_54 && F_23 ( V_2 ) )
goto V_60;
if ( ! V_54 ) {
V_54 = - V_132 ;
V_42 -> V_50 = V_65 ;
F_39 ( V_90 . V_91 . V_92 ,
L_4 , V_93 , __LINE__ , V_54 ) ;
}
if ( V_54 > 0 )
V_54 = 0 ;
V_130:
F_9 ( & V_2 -> V_5 . V_6 ) ;
F_76 ( V_42 , 1 ) ;
break;
}
case V_133 :
{
if ( ! F_23 ( V_2 ) ) {
V_54 = - V_132 ;
V_42 -> V_50 = V_65 ;
}
break;
}
case V_65 :
break;
default:
V_54 = - V_132 ;
}
if ( V_42 -> V_50 == V_65 && V_42 -> V_101 )
F_76 ( V_42 , V_42 -> V_26 ) ;
if ( ! V_42 -> V_101 ) {
F_77 ( & V_2 -> V_5 . V_15 ) ;
F_78 ( & V_42 -> V_52 ) ;
F_25 ( V_2 , V_42 , V_42 -> V_40 ) ;
F_12 ( & V_2 -> V_5 . V_6 ) ;
if ( ( ! ! ( V_42 -> V_100 -> V_38 & V_37 ) ) &&
F_23 ( V_2 ) ) {
F_79 ( V_2 -> V_74 -> V_77 ,
V_2 -> V_5 . V_20 ) ;
} else {
if ( ! F_37 ( V_42 -> V_87 ,
V_42 -> V_26 , 1 ) ) {
F_35 ( V_42 -> V_87 ) ;
V_42 -> V_87 = NULL ;
}
}
F_80 ( V_42 , & V_90 . V_4 ) ;
F_9 ( & V_2 -> V_5 . V_6 ) ;
}
return V_54 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_39 * V_42 )
{
struct V_58 V_59 ;
struct V_55 * V_56 = & V_42 -> V_57 ;
V_56 -> V_62 = V_63 ;
F_7 ( & V_56 -> V_61 ) ;
V_59 . V_66 = V_134 ;
V_59 . V_70 [ 1 ] = V_42 -> V_26 ;
V_59 . V_70 [ 2 ] = ( V_46 ) & V_42 -> V_57 ;
return F_24 ( V_2 -> V_74 , & V_59 ) ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_39 * V_42 )
{
struct V_58 V_59 ;
struct V_39 * V_135 ;
struct V_55 * V_56 = & V_42 -> V_57 ;
T_3 * V_136 , * V_137 , * V_112 , * V_138 ;
int V_102 = 0 , V_33 = 0 ;
int V_82 , V_139 ;
int V_140 , V_107 ;
int V_54 , V_141 ;
V_141 = F_68 ( V_2 -> V_74 , V_42 ) ;
if ( V_141 )
F_39 ( & V_2 -> V_74 -> V_77 -> V_78 ,
L_5 , V_93 , __LINE__ , V_141 ) ;
V_140 = V_42 -> V_82 ;
V_82 = V_42 -> V_82 ;
V_60:
V_54 = F_22 ( V_56 -> V_61 ,
V_56 -> V_62 != V_63 ,
V_64 ) ;
F_9 ( & V_2 -> V_5 . V_6 ) ;
F_12 ( & V_2 -> V_5 . V_6 ) ;
if ( ! V_54 && F_23 ( V_2 ) )
goto V_60;
if ( ! V_54 )
V_54 = - V_132 ;
if ( V_54 > 0 )
V_54 = 0 ;
else
return V_54 ;
if ( V_56 -> V_62 == V_133 )
return - V_99 ;
if ( V_141 ) {
F_39 ( & V_2 -> V_74 -> V_77 -> V_78 ,
L_4 , V_93 , __LINE__ , V_141 ) ;
V_59 . V_66 = V_67 ;
V_59 . V_68 = V_2 -> V_69 ;
V_59 . V_70 [ 0 ] = V_2 -> V_71 ;
V_59 . V_70 [ 1 ] = V_42 -> V_57 . V_72 ;
V_59 . V_70 [ 2 ] = ( V_46 ) V_42 ;
V_59 . V_70 [ 3 ] = V_73 ;
F_83 ( & V_2 -> V_142 ) ;
if ( V_2 -> V_62 == V_143 )
V_54 = F_24 ( V_2 -> V_74 , & V_59 ) ;
else
V_54 = - V_144 ;
F_84 ( & V_2 -> V_142 ) ;
return V_54 ;
}
V_135 = F_85 ( V_56 -> V_145 , sizeof( * V_42 ) ,
V_2 -> V_74 ) ;
V_107 = F_49 ( V_82 , V_113 )
>> F_86 ( V_113 ) ;
V_136 =
F_85 ( V_135 -> V_108 . V_40 ,
V_107 *
sizeof( * V_135 -> V_108 . V_109 ) ,
V_2 -> V_74 ) ;
V_112 =
F_85 ( V_135 -> V_112 . V_40 ,
V_107 *
sizeof( * V_135 -> V_112 . V_109 ) ,
V_2 -> V_74 ) ;
while ( V_140 ) {
V_139 = F_87 ( int , V_140 ,
( int ) V_113 ) ;
V_137 = F_85 ( V_136 [ V_33 ] ,
V_139 *
sizeof( * V_42 -> V_43 ) ,
V_2 -> V_74 ) ;
V_138 = F_85 ( V_112 [ V_33 ] ,
V_139 *
sizeof( * V_42 -> V_45 ) ,
V_2 -> V_74 ) ;
if ( F_70 () ) {
F_88 ( ( void V_146 V_147 * ) V_137 ,
& V_42 -> V_43 [ V_102 ] , V_139
* sizeof( * V_42 -> V_43 ) ) ;
F_88 ( ( void V_146 V_147 * ) V_138 ,
& V_42 -> V_45 [ V_102 ] , V_139
* sizeof( * V_42 -> V_45 ) ) ;
} else {
if ( F_89 ( V_2 -> V_74 ) ) {
int V_148 ;
T_3 V_43 ;
for ( V_148 = 0 ; V_148 < V_139 ; V_148 ++ ) {
V_43 = V_42 -> V_43 [ V_102 + V_148 ] +
V_2 -> V_74 -> V_149 ;
F_90 ( V_43 ,
( void V_146 V_147 * ) & V_137 [ V_148 ] ) ;
}
F_88 ( ( void V_146 V_147 * ) V_138 ,
& V_42 -> V_45 [ V_102 ] ,
V_139
* sizeof( * V_42 -> V_45 ) ) ;
} else {
F_88 ( ( void V_146 V_147 * ) V_137 ,
& V_42 -> V_43 [ V_102 ] ,
V_139 *
sizeof( * V_42 -> V_43 ) ) ;
F_88 ( ( void V_146 V_147 * ) V_138 ,
& V_42 -> V_45 [ V_102 ] ,
V_139 *
sizeof( * V_42 -> V_45 ) ) ;
}
}
V_140 -= V_139 ;
V_102 += V_139 ;
V_33 ++ ;
F_91 ( V_137 , V_139 *
sizeof( * V_42 -> V_43 ) , V_2 -> V_74 ) ;
F_91 ( V_138 , V_139 *
sizeof( * V_42 -> V_45 ) , V_2 -> V_74 ) ;
}
V_135 -> V_150 = ( V_46 ) V_42 ;
V_135 -> V_40 = V_42 -> V_40 ;
V_135 -> V_27 = V_42 -> V_27 ;
V_135 -> V_82 = V_82 ;
V_135 -> V_2 = V_2 -> V_71 ;
F_91 ( V_112 ,
V_107 *
sizeof( * V_135 -> V_112 . V_109 ) ,
V_2 -> V_74 ) ;
F_91 ( V_136 ,
V_107 *
sizeof( * V_135 -> V_108 . V_109 ) ,
V_2 -> V_74 ) ;
F_91 ( V_135 , sizeof( * V_135 ) , V_2 -> V_74 ) ;
V_42 -> V_150 = V_56 -> V_72 ;
return V_54 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_39 * V_42 )
{
int V_54 = 0 ;
struct V_58 V_59 ;
V_59 . V_68 = V_2 -> V_69 ;
V_59 . V_70 [ 0 ] = V_2 -> V_71 ;
V_59 . V_70 [ 1 ] = V_42 -> V_57 . V_72 ;
V_59 . V_70 [ 2 ] = ( V_46 ) V_42 ;
F_83 ( & V_2 -> V_142 ) ;
if ( V_2 -> V_62 == V_143 ) {
V_59 . V_66 = V_73 ;
V_42 -> V_47 = V_63 ;
V_54 = F_24 ( V_2 -> V_74 , & V_59 ) ;
F_84 ( & V_2 -> V_142 ) ;
if ( ! V_54 ) {
V_60:
V_54 = F_22 ( V_42 -> V_49 ,
V_42 -> V_47 !=
V_63 ,
V_64 ) ;
if ( ! V_54 && F_23 ( V_2 ) )
goto V_60;
V_54 = ! V_54 ? - V_132 : 0 ;
if ( V_42 -> V_47 == V_133 )
V_54 = - V_144 ;
}
} else {
V_59 . V_66 = V_67 ;
V_59 . V_70 [ 3 ] = V_73 ;
V_54 = F_24 ( V_2 -> V_74 , & V_59 ) ;
F_84 ( & V_2 -> V_142 ) ;
if ( ! V_54 )
V_54 = - V_144 ;
}
return V_54 ;
}
int F_93 ( struct V_1 * V_2 , int V_151 , T_1 V_40 ,
int V_45 , T_1 * V_152 )
{
T_1 V_153 ;
struct V_154 * V_155 ;
int V_54 = 0 ;
if ( V_151 & V_156 ) {
V_153 = F_94 ( V_40 ) ;
V_155 = F_95 ( & V_2 -> V_5 . V_7 , V_153 ,
V_153 + V_45 - 1 ) ;
if ( ! V_155 )
V_54 = - V_157 ;
} else {
V_155 = F_96 ( & V_2 -> V_5 . V_7 , V_45 ,
V_158 - 1 , 0 ) ;
if ( ! V_155 )
V_54 = - V_99 ;
}
if ( ! V_54 )
* V_152 = ( V_155 -> V_159 ) << V_83 ;
return V_54 ;
}
void F_25 ( struct V_1 * V_2 ,
struct V_39 * V_42 , T_1 V_40 )
{
if ( ( V_42 && ! V_42 -> V_160 ) || ! V_42 ) {
F_97 ( & V_2 -> V_5 . V_7 , V_40 >> V_83 ) ;
if ( V_42 )
V_42 -> V_160 = true ;
}
}
void F_98 ( struct V_75 * V_117 , struct V_58 * V_59 )
{
int V_54 ;
struct V_39 * V_42 = NULL ;
int V_26 = V_59 -> V_70 [ 1 ] ;
V_42 = F_57 ( V_117 , V_26 ) ;
if ( ! V_42 ) {
V_54 = - V_99 ;
goto error;
}
V_59 -> V_66 = V_161 ;
V_59 -> V_70 [ 0 ] = ( V_46 ) V_42 ;
V_59 -> V_70 [ 1 ] = V_42 -> V_105 ;
V_54 = F_73 ( V_117 , V_59 ) ;
if ( V_54 )
F_58 ( V_42 ) ;
return;
error:
F_39 ( & V_117 -> V_77 -> V_78 ,
L_6 ,
V_93 , __LINE__ , V_54 , V_42 , V_26 ) ;
V_59 -> V_66 = V_162 ;
F_73 ( V_117 , V_59 ) ;
}
void F_99 ( struct V_75 * V_117 , struct V_58 * V_59 )
{
struct V_55 * V_163 = (struct V_55 * ) V_59 -> V_70 [ 2 ] ;
struct V_39 * V_42 = F_100 ( V_163 , struct V_39 ,
V_57 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_42 -> V_2 ;
F_9 ( & V_2 -> V_5 . V_6 ) ;
V_163 -> V_72 = V_59 -> V_70 [ 0 ] ;
V_163 -> V_145 = V_59 -> V_70 [ 1 ] ;
if ( V_59 -> V_66 == V_161 )
V_163 -> V_62 = V_65 ;
else
V_163 -> V_62 = V_133 ;
F_101 ( & V_163 -> V_61 ) ;
F_12 ( & V_2 -> V_5 . V_6 ) ;
}
void F_102 ( struct V_75 * V_117 , struct V_58 * V_59 )
{
struct V_39 * V_42 = (struct V_39 * ) V_59 -> V_70 [ 1 ] ;
F_58 ( V_42 ) ;
}
static void
F_103 ( struct V_75 * V_78 , struct V_39 * V_42 )
{
int V_33 ;
struct V_164 * V_77 = V_78 -> V_77 ;
T_4 V_165 = 0 ;
if ( ! F_28 ( V_78 ) && V_42 -> type == V_119 &&
V_77 -> V_166 && ! V_77 -> V_167 )
V_165 = V_77 -> V_166 -> V_168 ;
else
return;
for ( V_33 = 0 ; V_33 < V_42 -> V_82 ; V_33 ++ ) {
if ( V_42 -> V_45 [ V_33 ] )
V_42 -> V_43 [ V_33 ] += V_165 ;
else
break;
}
}
void F_104 ( struct V_75 * V_117 , struct V_58 * V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 -> V_70 [ 0 ] ;
struct V_39 * V_42 =
(struct V_39 * ) V_59 -> V_70 [ 1 ] ;
F_9 ( & V_2 -> V_5 . V_6 ) ;
F_83 ( & V_2 -> V_142 ) ;
if ( V_2 -> V_62 == V_143 ) {
V_59 -> V_66 = V_169 ;
F_73 ( V_2 -> V_74 , V_59 ) ;
F_103 ( V_2 -> V_74 , V_42 ) ;
F_105 ( V_42 , & V_2 -> V_5 . V_14 ) ;
} else {
V_59 -> V_66 = V_170 ;
F_73 ( V_2 -> V_74 , V_59 ) ;
}
F_84 ( & V_2 -> V_142 ) ;
F_12 ( & V_2 -> V_5 . V_6 ) ;
F_55 ( V_2 -> V_74 , V_42 ) ;
if ( V_59 -> V_66 == V_170 )
F_58 ( V_42 ) ;
}
void F_106 ( struct V_75 * V_117 , struct V_58 * V_59 )
{
struct V_171 V_172 ;
struct V_39 * V_42 = NULL ;
struct V_39 * V_173 =
(struct V_39 * ) V_59 -> V_70 [ 0 ] ;
struct V_1 * V_2 ;
int V_174 = 0 ;
V_2 = (struct V_1 * ) V_173 -> V_2 ;
V_172 . V_175 = & V_42 ;
V_172 . V_40 = V_173 -> V_40 ;
V_172 . V_27 = 0 ;
V_172 . V_176 = V_173 -> V_26 << V_83 ;
V_172 . type = V_177 ;
V_172 . V_178 = & V_2 -> V_5 . V_14 ;
V_59 -> V_70 [ 0 ] = V_2 -> V_71 ;
F_9 ( & V_2 -> V_5 . V_6 ) ;
if ( F_107 ( & V_172 ) ) {
F_39 ( & V_117 -> V_77 -> V_78 ,
L_7 , V_93 , __LINE__ ) ;
V_59 -> V_66 = V_179 ;
goto error;
}
if ( V_42 ) {
if ( V_42 -> V_101 )
F_76 ( V_42 , V_42 -> V_26 ) ;
else
F_39 ( & V_117 -> V_77 -> V_78 ,
L_8 ,
V_93 , __LINE__ ) ;
V_42 -> V_50 = V_65 ;
if ( ! V_42 -> V_101 ) {
V_59 -> V_66 = V_179 ;
F_77 ( & V_2 -> V_5 . V_15 ) ;
V_2 -> V_5 . V_19 = 1 ;
F_78 ( & V_42 -> V_52 ) ;
V_174 = 1 ;
} else {
V_59 -> V_66 = V_180 ;
}
} else {
V_59 -> V_66 = V_179 ;
F_58 ( V_173 ) ;
}
error:
F_12 ( & V_2 -> V_5 . V_6 ) ;
if ( V_174 )
F_79 ( V_2 -> V_74 -> V_77 ,
V_2 -> V_5 . V_20 ) ;
F_73 ( V_2 -> V_74 , V_59 ) ;
if ( V_174 )
F_80 ( V_42 , & V_90 . V_4 ) ;
}
void F_108 ( struct V_75 * V_117 , struct V_58 * V_59 )
{
struct V_39 * V_42 =
(struct V_39 * ) V_59 -> V_70 [ 2 ] ;
struct V_1 * V_2 = (struct V_1 * ) V_42 -> V_2 ;
F_9 ( & V_2 -> V_5 . V_6 ) ;
V_42 -> V_47 = V_65 ;
F_101 ( & V_42 -> V_49 ) ;
F_12 ( & V_2 -> V_5 . V_6 ) ;
}
void F_109 ( struct V_75 * V_117 , struct V_58 * V_59 )
{
struct V_39 * V_42 =
(struct V_39 * ) V_59 -> V_70 [ 2 ] ;
struct V_1 * V_2 = (struct V_1 * ) V_42 -> V_2 ;
F_9 ( & V_2 -> V_5 . V_6 ) ;
V_42 -> V_47 = V_133 ;
F_101 ( & V_42 -> V_49 ) ;
F_12 ( & V_2 -> V_5 . V_6 ) ;
}
void F_110 ( struct V_75 * V_117 , struct V_58 * V_59 )
{
struct V_39 * V_42 =
(struct V_39 * ) V_59 -> V_70 [ 1 ] ;
struct V_1 * V_2 = (struct V_1 * ) V_42 -> V_2 ;
F_9 ( & V_2 -> V_5 . V_6 ) ;
V_42 -> V_50 = V_65 ;
F_101 ( & V_42 -> V_51 ) ;
F_12 ( & V_2 -> V_5 . V_6 ) ;
}
void F_111 ( struct V_75 * V_117 , struct V_58 * V_59 )
{
struct V_39 * V_42 =
(struct V_39 * ) V_59 -> V_70 [ 1 ] ;
struct V_1 * V_2 = (struct V_1 * ) V_42 -> V_2 ;
F_9 ( & V_2 -> V_5 . V_6 ) ;
V_42 -> V_50 = V_133 ;
F_101 ( & V_42 -> V_51 ) ;
F_12 ( & V_2 -> V_5 . V_6 ) ;
}
int F_112 ( void * V_181 , T_5 V_182 , int * V_183 ,
int V_38 , T_2 * V_29 )
{
struct V_25 * V_100 ;
int V_26 , V_54 = 0 , V_102 ;
bool V_184 = false ;
bool V_185 = false ;
int V_27 = * V_183 ;
int V_186 = 0 ;
struct V_84 * V_87 = NULL ;
if ( V_38 & ~ ( V_37 | V_187 ) )
return - V_188 ;
V_186 = ! ! ( V_38 & V_187 ) ;
if ( V_27 & ~ ( V_189 | V_35 ) )
return - V_188 ;
if ( ! V_182 ||
( F_49 ( ( V_46 ) V_181 , V_8 ) != ( V_46 ) V_181 ) ||
( F_49 ( ( V_46 ) V_182 , V_8 ) != ( V_46 ) V_182 ) )
return - V_188 ;
F_14 () ;
V_26 = V_182 >> V_83 ;
V_100 = F_13 ( V_26 , V_27 ) ;
if ( ! V_100 )
return - V_99 ;
if ( V_38 & V_37 ) {
if ( F_51 ( V_181 ) )
V_184 = true ;
for ( V_102 = 0 ; V_102 < V_26 ; V_102 ++ ) {
if ( V_184 )
V_100 -> V_29 [ V_102 ] =
F_53 ( V_181 + ( V_102 * V_8 ) ) ;
else
V_100 -> V_29 [ V_102 ] =
F_54 ( V_181 + ( V_102 * V_8 ) ) ;
}
V_100 -> V_26 = V_26 ;
V_100 -> V_38 = V_37 ;
} else {
if ( V_27 == V_189 )
V_185 = true ;
V_27 |= V_35 ;
V_60:
V_87 = V_86 -> V_87 ;
F_40 ( & V_87 -> V_89 ) ;
if ( V_186 ) {
V_54 = F_42 ( V_87 , V_26 ) ;
if ( V_54 ) {
F_41 ( & V_87 -> V_89 ) ;
V_100 -> V_26 = 0 ;
goto V_190;
}
}
V_100 -> V_26 = F_113 (
( V_46 ) V_181 ,
V_26 ,
! ! ( V_27 & V_35 ) ,
0 ,
V_100 -> V_29 ,
NULL ) ;
F_41 ( & V_87 -> V_89 ) ;
if ( V_26 != V_100 -> V_26 ) {
if ( V_185 ) {
if ( V_186 )
F_37 ( V_87 ,
V_26 , 0 ) ;
for ( V_102 = 0 ; V_102 < V_100 -> V_26 ; V_102 ++ ) {
if ( V_100 -> V_29 [ V_102 ] )
F_19 (
V_100 -> V_29 [ V_102 ] ) ;
}
V_27 &= ~ V_35 ;
V_185 = false ;
goto V_60;
}
}
V_100 -> V_38 = 0 ;
}
if ( V_100 -> V_26 < V_26 ) {
V_54 = - V_191 ;
V_100 -> V_26 = V_26 ;
goto V_192;
}
* V_183 = V_27 ;
F_6 ( & V_100 -> V_101 , 1 ) ;
* V_29 = V_100 ;
return V_54 ;
V_192:
if ( V_186 )
F_37 ( V_87 , V_26 , 0 ) ;
V_190:
V_100 -> V_26 = V_26 ;
F_17 ( V_100 ) ;
* V_29 = NULL ;
F_114 ( V_90 . V_91 . V_92 ,
L_9 , V_93 , __LINE__ , V_54 , V_182 ) ;
return V_54 ;
}
int F_115 ( void * V_181 , T_5 V_182 , int V_27 ,
int V_38 , T_2 * V_29 )
{
return F_112 ( V_181 , V_182 , & V_27 , V_38 , V_29 ) ;
}
int F_116 ( T_2 V_100 )
{
int V_54 = 0 , V_24 ;
if ( ! V_100 || V_32 != V_100 -> V_31 )
return - V_188 ;
V_24 = F_46 ( 1 , & V_100 -> V_101 ) ;
if ( V_24 < 0 ) {
F_39 ( V_90 . V_91 . V_92 ,
L_10 ,
V_93 , __LINE__ , V_24 ) ;
return - V_188 ;
}
if ( ! V_24 )
V_54 = F_17 ( V_100 ) ;
return V_54 ;
}
static inline void
F_117 ( struct V_39 * V_42 , struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_5 . V_6 ) ;
F_105 ( V_42 , & V_2 -> V_5 . V_13 ) ;
F_12 ( & V_2 -> V_5 . V_6 ) ;
}
T_6 F_118 ( T_7 V_193 ,
T_2 V_100 ,
T_6 V_40 , int V_38 )
{
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
T_1 V_194 ;
struct V_39 * V_42 ;
int V_54 ;
T_5 V_182 ;
struct V_195 * V_196 ;
if ( V_38 & ~ V_156 )
return - V_188 ;
V_182 = V_100 -> V_26 << V_83 ;
if ( ( V_38 & V_156 ) &&
( ( F_49 ( V_40 , V_8 ) != V_40 ) ||
( V_40 < 0 ) ||
( V_182 > V_197 - V_40 ) ) )
return - V_188 ;
F_14 () ;
V_54 = F_119 ( V_2 ) ;
if ( V_54 )
return V_54 ;
if ( ! F_120 ( & V_100 -> V_101 , 1 , 0 ) )
return - V_188 ;
V_54 = F_93 ( V_2 , V_38 , V_40 ,
V_182 , & V_194 ) ;
if ( V_54 ) {
F_121 ( 1 , & V_100 -> V_101 ) ;
return V_54 ;
}
V_42 = F_20 ( V_2 , V_100 -> V_26 ,
V_194 , false ) ;
if ( ! V_42 ) {
F_121 ( 1 , & V_100 -> V_101 ) ;
F_25 ( V_2 , NULL , V_194 ) ;
return - V_99 ;
}
V_42 -> V_100 = V_100 ;
V_42 -> V_26 = V_100 -> V_26 ;
V_42 -> V_27 = V_100 -> V_27 ;
V_196 = F_122 ( V_2 -> V_74 ) ;
if ( F_123 ( V_196 ) ) {
V_54 = F_124 ( V_196 ) ;
F_45 ( V_2 , V_42 ) ;
return V_54 ;
}
V_54 = F_81 ( V_2 , V_42 ) ;
if ( V_54 ) {
F_39 ( & V_2 -> V_74 -> V_77 -> V_78 ,
L_4 , V_93 , __LINE__ , V_54 ) ;
goto V_190;
}
V_54 = F_82 ( V_2 , V_42 ) ;
if ( V_54 ) {
F_39 ( & V_2 -> V_74 -> V_77 -> V_78 ,
L_4 , V_93 , __LINE__ , V_54 ) ;
goto V_190;
}
V_54 = F_92 ( V_2 , V_42 ) ;
if ( V_54 ) {
F_39 ( & V_2 -> V_74 -> V_77 -> V_78 ,
L_4 , V_93 , __LINE__ , V_54 ) ;
goto V_190;
}
F_125 ( V_196 ) ;
F_117 ( V_42 , V_2 ) ;
return V_194 ;
V_190:
F_45 ( V_2 , V_42 ) ;
F_125 ( V_196 ) ;
F_39 ( & V_2 -> V_74 -> V_77 -> V_78 ,
L_4 , V_93 , __LINE__ , V_54 ) ;
return V_54 ;
}
T_6 F_126 ( T_7 V_193 , void * V_181 , T_5 V_182 , T_6 V_40 ,
int V_27 , int V_38 )
{
T_2 V_100 ;
T_6 V_54 ;
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
T_1 V_194 ;
struct V_39 * V_42 ;
struct V_84 * V_87 = NULL ;
struct V_195 * V_196 ;
F_114 ( V_90 . V_91 . V_92 ,
L_11 ,
V_193 , V_181 , V_182 , V_40 , V_27 , V_38 ) ;
if ( V_38 & ~ ( V_156 | V_37 ) )
return - V_188 ;
if ( ( V_38 & V_156 ) &&
( ( F_49 ( V_40 , V_8 ) != V_40 ) ||
( V_40 < 0 ) ||
( V_182 > V_197 - V_40 ) ) )
return - V_188 ;
if ( V_27 & ~ ( V_189 | V_35 ) )
return - V_188 ;
if ( ! V_182 || ( F_49 ( ( V_46 ) V_181 , V_8 ) != ( V_46 ) V_181 ) ||
( F_49 ( V_182 , V_8 ) != V_182 ) )
return - V_188 ;
F_14 () ;
V_54 = F_119 ( V_2 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_93 ( V_2 , V_38 , V_40 ,
V_182 >> V_83 , & V_194 ) ;
if ( V_54 )
return V_54 ;
V_196 = F_122 ( V_2 -> V_74 ) ;
if ( F_123 ( V_196 ) ) {
V_54 = F_124 ( V_196 ) ;
F_25 ( V_2 , NULL , V_194 ) ;
return V_54 ;
}
V_42 = F_20 ( V_2 , V_182 >> V_83 ,
V_194 , false ) ;
if ( ! V_42 ) {
F_25 ( V_2 , NULL , V_194 ) ;
F_125 ( V_196 ) ;
return - V_99 ;
}
V_42 -> V_26 = V_182 >> V_83 ;
V_54 = F_81 ( V_2 , V_42 ) ;
if ( V_54 ) {
F_21 ( V_2 , V_42 ) ;
F_125 ( V_196 ) ;
return V_54 ;
}
if ( ! ( V_38 & V_37 ) ) {
V_87 = F_33 () ;
V_38 |= V_187 ;
}
V_54 = F_112 ( V_181 , V_182 , & V_27 ,
V_38 & ( V_37 | V_187 ) ,
& V_100 ) ;
if ( V_54 ) {
F_21 ( V_2 , V_42 ) ;
F_35 ( V_87 ) ;
goto error;
}
V_42 -> V_100 = V_100 ;
V_42 -> V_27 = V_100 -> V_27 ;
V_42 -> V_87 = V_87 ;
V_54 = F_82 ( V_2 , V_42 ) ;
if ( V_54 ) {
F_39 ( & V_2 -> V_74 -> V_77 -> V_78 ,
L_12 , V_93 , __LINE__ , V_54 ) ;
goto V_190;
}
V_54 = F_92 ( V_2 , V_42 ) ;
if ( V_54 ) {
F_39 ( & V_2 -> V_74 -> V_77 -> V_78 ,
L_12 , V_93 , __LINE__ , V_54 ) ;
goto V_190;
}
F_125 ( V_196 ) ;
F_117 ( V_42 , V_2 ) ;
F_114 ( & V_2 -> V_74 -> V_77 -> V_78 ,
L_13 ,
V_193 , V_181 , V_182 , V_194 ) ;
return V_194 ;
V_190:
F_45 ( V_2 , V_42 ) ;
error:
F_125 ( V_196 ) ;
F_39 ( & V_2 -> V_74 -> V_77 -> V_78 ,
L_12 , V_93 , __LINE__ , V_54 ) ;
return V_54 ;
}
int
F_127 ( T_7 V_193 , T_6 V_40 , T_5 V_182 )
{
struct V_1 * V_2 = (struct V_1 * ) V_193 ;
struct V_39 * V_42 = NULL ;
struct V_171 V_172 ;
int V_26 , V_54 ;
struct V_195 * V_196 ;
F_114 ( V_90 . V_91 . V_92 ,
L_14 ,
V_2 , V_40 , V_182 ) ;
if ( ! V_182 ||
( F_49 ( ( V_46 ) V_182 , V_8 ) != ( V_46 ) V_182 ) )
return - V_188 ;
if ( ( F_49 ( V_40 , V_8 ) != V_40 ) ||
( V_40 < 0 ) ||
( V_182 > V_197 - V_40 ) )
return - V_188 ;
V_54 = F_119 ( V_2 ) ;
if ( V_54 )
return V_54 ;
F_14 () ;
V_26 = V_182 >> V_83 ;
V_172 . V_175 = & V_42 ;
V_172 . V_40 = V_40 ;
V_172 . V_27 = 0 ;
V_172 . V_176 = V_182 ;
V_172 . type = V_177 ;
V_172 . V_178 = & V_2 -> V_5 . V_13 ;
V_196 = F_122 ( V_2 -> V_74 ) ;
if ( F_123 ( V_196 ) ) {
V_54 = F_124 ( V_196 ) ;
return V_54 ;
}
F_9 ( & V_2 -> V_5 . V_6 ) ;
V_54 = F_107 ( & V_172 ) ;
if ( V_54 ) {
F_39 ( & V_2 -> V_74 -> V_77 -> V_78 ,
L_4 , V_93 , __LINE__ , V_54 ) ;
goto error;
}
V_54 = F_128 ( V_42 , V_40 , V_26 ) ;
if ( V_54 )
F_39 ( & V_2 -> V_74 -> V_77 -> V_78 ,
L_4 , V_93 , __LINE__ , V_54 ) ;
error:
F_12 ( & V_2 -> V_5 . V_6 ) ;
F_125 ( V_196 ) ;
return V_54 ;
}
