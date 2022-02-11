int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_3 , V_2 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_3 , V_2 ) ;
}
static void F_5 ( T_1 * V_4 , struct V_5 * V_6 ,
void (* F_6)( struct V_7 * ) , int V_8 )
{
struct V_7 * V_9 ;
if ( F_7 ( V_6 ) )
return;
do {
V_9 = F_8 ( V_6 -> V_10 , struct V_7 , V_11 ) ;
F_9 ( & V_9 -> V_11 ) ;
V_9 -> V_12 = V_8 ;
F_6 ( V_9 ) ;
} while ( ! F_7 ( V_6 ) );
if ( V_4 )
F_10 ( V_4 ) ;
}
static void
F_11 ( struct V_13 * V_14 )
{
F_12 ( V_15 ) ;
struct V_16 * V_17 =
F_13 ( V_14 , struct V_16 , V_18 . V_14 ) ;
void (* F_6)( struct V_7 * );
struct V_19 * V_19 ;
F_14 ( & V_17 -> V_20 ) ;
F_6 = V_17 -> V_21 -> F_6 ;
if ( V_17 -> V_22 == 0 ) {
F_15 ( & V_17 -> V_17 , & V_15 ) ;
V_17 -> V_23 = 0 ;
}
V_19 = F_16 ( V_17 -> V_19 ) ;
F_17 ( & V_17 -> V_20 ) ;
F_5 ( V_19 ? & F_18 ( V_19 -> V_24 ) -> V_4 : NULL ,
& V_15 , F_6 , - V_25 ) ;
F_19 ( V_19 ) ;
}
T_2 F_20 ( struct V_26 * V_27 , struct V_7 * V_9 ,
char T_3 * V_28 , T_4 V_29 )
{
char * V_30 = ( char * ) V_9 -> V_30 + V_9 -> V_31 ;
T_4 V_32 = F_21 ( V_9 -> V_33 - V_9 -> V_31 , V_29 ) ;
unsigned long V_34 ;
V_34 = F_22 ( V_28 , V_30 , V_32 ) ;
if ( V_34 == V_32 ) {
V_9 -> V_12 = - V_35 ;
return - V_35 ;
}
V_32 -= V_34 ;
V_9 -> V_31 += V_32 ;
V_9 -> V_12 = 0 ;
return V_32 ;
}
int
F_23 ( struct V_16 * V_17 , struct V_7 * V_9 )
{
int V_36 = - V_37 ;
struct V_19 * V_19 ;
F_14 ( & V_17 -> V_20 ) ;
if ( V_17 -> V_22 ) {
F_24 ( & V_9 -> V_11 , & V_17 -> V_17 ) ;
V_17 -> V_23 += V_9 -> V_33 ;
V_36 = 0 ;
} else if ( V_17 -> V_38 & V_39 ) {
if ( F_7 ( & V_17 -> V_17 ) )
F_25 ( V_40 ,
& V_17 -> V_18 ,
V_41 ) ;
F_24 ( & V_9 -> V_11 , & V_17 -> V_17 ) ;
V_17 -> V_23 += V_9 -> V_33 ;
V_36 = 0 ;
}
V_19 = F_16 ( V_17 -> V_19 ) ;
F_17 ( & V_17 -> V_20 ) ;
if ( V_19 ) {
F_10 ( & F_18 ( V_19 -> V_24 ) -> V_4 ) ;
F_19 ( V_19 ) ;
}
return V_36 ;
}
static inline void
F_26 ( struct V_42 * V_42 , void * V_43 )
{
F_18 ( V_42 ) -> V_43 = V_43 ;
}
static void
F_27 ( struct V_42 * V_42 )
{
struct V_16 * V_17 = F_18 ( V_42 ) -> V_17 ;
int V_44 ;
F_12 ( V_15 ) ;
F_28 ( & V_42 -> V_45 ) ;
F_14 ( & V_17 -> V_20 ) ;
V_44 = V_17 -> V_22 != 0 || V_17 -> V_46 != 0 ;
V_17 -> V_22 = 0 ;
F_15 ( & V_17 -> V_47 , & V_15 ) ;
F_15 ( & V_17 -> V_17 , & V_15 ) ;
V_17 -> V_23 = 0 ;
V_17 -> V_19 = NULL ;
F_17 ( & V_17 -> V_20 ) ;
F_5 ( & F_18 ( V_42 ) -> V_4 , & V_15 , V_17 -> V_21 -> F_6 , - V_37 ) ;
V_17 -> V_46 = 0 ;
if ( V_44 && V_17 -> V_21 -> V_48 )
V_17 -> V_21 -> V_48 ( V_42 ) ;
F_29 ( & V_17 -> V_18 ) ;
F_26 ( V_42 , NULL ) ;
F_18 ( V_42 ) -> V_17 = NULL ;
F_30 ( & V_42 -> V_45 ) ;
}
static struct V_42 *
F_31 ( struct V_49 * V_50 )
{
struct V_51 * V_52 ;
V_52 = (struct V_51 * ) F_32 ( V_53 , V_54 ) ;
if ( ! V_52 )
return NULL ;
return & V_52 -> V_55 ;
}
static void
F_33 ( struct V_56 * V_6 )
{
struct V_42 * V_42 = F_13 ( V_6 , struct V_42 , V_57 ) ;
F_34 ( V_53 , F_18 ( V_42 ) ) ;
}
static void
F_35 ( struct V_42 * V_42 )
{
F_36 ( & V_42 -> V_57 , F_33 ) ;
}
static int
F_37 ( struct V_42 * V_42 , struct V_26 * V_27 )
{
struct V_58 * V_58 = V_42 -> V_59 -> V_60 ;
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
struct V_16 * V_17 ;
int V_64 ;
int V_36 = - V_65 ;
F_28 ( & V_42 -> V_45 ) ;
V_62 -> V_66 = 1 ;
V_17 = F_18 ( V_42 ) -> V_17 ;
if ( V_17 == NULL )
goto V_67;
V_64 = V_17 -> V_22 == 0 && V_17 -> V_46 == 0 ;
if ( V_64 && V_17 -> V_21 -> V_68 ) {
V_36 = V_17 -> V_21 -> V_68 ( V_42 ) ;
if ( V_36 )
goto V_67;
}
if ( V_27 -> V_69 & V_70 )
V_17 -> V_22 ++ ;
if ( V_27 -> V_69 & V_71 )
V_17 -> V_46 ++ ;
V_36 = 0 ;
V_67:
F_30 ( & V_42 -> V_45 ) ;
return V_36 ;
}
static int
F_39 ( struct V_42 * V_42 , struct V_26 * V_27 )
{
struct V_16 * V_17 ;
struct V_7 * V_9 ;
int V_72 ;
F_28 ( & V_42 -> V_45 ) ;
V_17 = F_18 ( V_42 ) -> V_17 ;
if ( V_17 == NULL )
goto V_67;
V_9 = V_27 -> V_73 ;
if ( V_9 != NULL ) {
F_14 ( & V_17 -> V_20 ) ;
V_9 -> V_12 = - V_74 ;
F_9 ( & V_9 -> V_11 ) ;
F_17 ( & V_17 -> V_20 ) ;
V_17 -> V_21 -> F_6 ( V_9 ) ;
}
if ( V_27 -> V_69 & V_71 )
V_17 -> V_46 -- ;
if ( V_27 -> V_69 & V_70 ) {
V_17 -> V_22 -- ;
if ( V_17 -> V_22 == 0 ) {
F_12 ( V_15 ) ;
F_14 ( & V_17 -> V_20 ) ;
F_15 ( & V_17 -> V_17 , & V_15 ) ;
V_17 -> V_23 = 0 ;
F_17 ( & V_17 -> V_20 ) ;
F_5 ( & F_18 ( V_42 ) -> V_4 , & V_15 ,
V_17 -> V_21 -> F_6 , - V_74 ) ;
}
}
V_72 = V_17 -> V_46 == 0 && V_17 -> V_22 == 0 ;
if ( V_72 && V_17 -> V_21 -> V_48 )
V_17 -> V_21 -> V_48 ( V_42 ) ;
V_67:
F_30 ( & V_42 -> V_45 ) ;
return 0 ;
}
static T_2
F_40 ( struct V_26 * V_27 , char T_3 * V_75 , T_4 V_33 , T_5 * V_76 )
{
struct V_42 * V_42 = F_41 ( V_27 ) ;
struct V_16 * V_17 ;
struct V_7 * V_9 ;
int V_36 = 0 ;
F_28 ( & V_42 -> V_45 ) ;
V_17 = F_18 ( V_42 ) -> V_17 ;
if ( V_17 == NULL ) {
V_36 = - V_37 ;
goto V_77;
}
V_9 = V_27 -> V_73 ;
if ( V_9 == NULL ) {
F_14 ( & V_17 -> V_20 ) ;
if ( ! F_7 ( & V_17 -> V_17 ) ) {
V_9 = F_8 ( V_17 -> V_17 . V_10 ,
struct V_7 ,
V_11 ) ;
F_42 ( & V_9 -> V_11 , & V_17 -> V_47 ) ;
V_17 -> V_23 -= V_9 -> V_33 ;
V_27 -> V_73 = V_9 ;
V_9 -> V_31 = 0 ;
}
F_17 ( & V_17 -> V_20 ) ;
if ( V_9 == NULL )
goto V_77;
}
V_36 = V_17 -> V_21 -> V_78 ( V_27 , V_9 , V_75 , V_33 ) ;
if ( V_36 < 0 || V_9 -> V_33 == V_9 -> V_31 ) {
V_27 -> V_73 = NULL ;
F_14 ( & V_17 -> V_20 ) ;
F_9 ( & V_9 -> V_11 ) ;
F_17 ( & V_17 -> V_20 ) ;
V_17 -> V_21 -> F_6 ( V_9 ) ;
}
V_77:
F_30 ( & V_42 -> V_45 ) ;
return V_36 ;
}
static T_2
F_43 ( struct V_26 * V_27 , const char T_3 * V_75 , T_4 V_33 , T_5 * V_76 )
{
struct V_42 * V_42 = F_41 ( V_27 ) ;
int V_36 ;
F_28 ( & V_42 -> V_45 ) ;
V_36 = - V_37 ;
if ( F_18 ( V_42 ) -> V_17 != NULL )
V_36 = F_18 ( V_42 ) -> V_17 -> V_21 -> V_79 ( V_27 , V_75 , V_33 ) ;
F_30 ( & V_42 -> V_45 ) ;
return V_36 ;
}
static unsigned int
F_44 ( struct V_26 * V_27 , struct V_80 * V_81 )
{
struct V_42 * V_42 = F_41 ( V_27 ) ;
struct V_51 * V_52 = F_18 ( V_42 ) ;
unsigned int V_82 = V_83 | V_84 ;
F_45 ( V_27 , & V_52 -> V_4 , V_81 ) ;
F_28 ( & V_42 -> V_45 ) ;
if ( V_52 -> V_17 == NULL )
V_82 |= V_85 | V_86 ;
else if ( V_27 -> V_73 || ! F_7 ( & V_52 -> V_17 -> V_17 ) )
V_82 |= V_87 | V_88 ;
F_30 ( & V_42 -> V_45 ) ;
return V_82 ;
}
static long
F_46 ( struct V_26 * V_27 , unsigned int V_89 , unsigned long V_90 )
{
struct V_42 * V_42 = F_41 ( V_27 ) ;
struct V_16 * V_17 ;
int V_33 ;
switch ( V_89 ) {
case V_91 :
F_28 ( & V_42 -> V_45 ) ;
V_17 = F_18 ( V_42 ) -> V_17 ;
if ( V_17 == NULL ) {
F_30 ( & V_42 -> V_45 ) ;
return - V_37 ;
}
F_14 ( & V_17 -> V_20 ) ;
V_33 = V_17 -> V_23 ;
if ( V_27 -> V_73 ) {
struct V_7 * V_9 ;
V_9 = V_27 -> V_73 ;
V_33 += V_9 -> V_33 - V_9 -> V_31 ;
}
F_17 ( & V_17 -> V_20 ) ;
F_30 ( & V_42 -> V_45 ) ;
return F_47 ( V_33 , ( int T_3 * ) V_90 ) ;
default:
return - V_92 ;
}
}
static int
F_48 ( struct V_93 * V_94 , void * V_95 )
{
struct V_96 * V_97 = V_94 -> V_43 ;
F_49 () ;
F_50 ( V_94 , L_1 ,
F_51 ( V_97 -> V_98 ) -> V_99 ) ;
F_50 ( V_94 , L_2 , V_97 -> V_100 -> V_101 ,
V_97 -> V_102 , V_97 -> V_103 ) ;
F_50 ( V_94 , L_3 , F_52 ( V_97 , V_104 ) ) ;
F_50 ( V_94 , L_4 , F_52 ( V_97 , V_105 ) ) ;
F_50 ( V_94 , L_5 , F_52 ( V_97 , V_106 ) ) ;
F_53 () ;
return 0 ;
}
static int
F_54 ( struct V_42 * V_42 , struct V_26 * V_26 )
{
struct V_96 * V_97 = NULL ;
int V_107 = F_55 ( V_26 , F_48 , NULL ) ;
if ( ! V_107 ) {
struct V_93 * V_94 = V_26 -> V_73 ;
F_14 ( & V_26 -> V_108 . V_19 -> V_109 ) ;
if ( ! F_56 ( V_26 -> V_108 . V_19 ) )
V_97 = F_18 ( V_42 ) -> V_43 ;
if ( V_97 != NULL && F_57 ( & V_97 -> V_110 ) ) {
F_17 ( & V_26 -> V_108 . V_19 -> V_109 ) ;
V_94 -> V_43 = V_97 ;
} else {
F_17 ( & V_26 -> V_108 . V_19 -> V_109 ) ;
F_58 ( V_42 , V_26 ) ;
V_107 = - V_92 ;
}
}
return V_107 ;
}
static int
F_59 ( struct V_42 * V_42 , struct V_26 * V_26 )
{
struct V_93 * V_94 = V_26 -> V_73 ;
struct V_96 * V_97 = (struct V_96 * ) V_94 -> V_43 ;
if ( V_97 )
F_60 ( V_97 ) ;
return F_58 ( V_42 , V_26 ) ;
}
static int F_61 ( const struct V_19 * V_19 )
{
return 1 ;
}
static struct V_42 *
F_62 ( struct V_49 * V_50 , T_6 V_111 )
{
struct V_42 * V_42 = F_63 ( V_50 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_112 = F_64 () ;
V_42 -> V_113 = V_111 ;
V_42 -> V_114 = V_42 -> V_115 = V_42 -> V_116 = V_117 ;
switch ( V_111 & V_118 ) {
case V_119 :
V_42 -> V_120 = & V_121 ;
V_42 -> V_122 = & V_123 ;
F_65 ( V_42 ) ;
default:
break;
}
return V_42 ;
}
static int F_66 ( struct V_42 * V_124 , struct V_19 * V_19 ,
T_6 V_111 ,
const struct V_125 * V_120 ,
void * V_43 )
{
struct V_42 * V_42 ;
F_67 ( V_19 ) ;
V_42 = F_62 ( V_124 -> V_59 , V_111 ) ;
if ( ! V_42 )
goto V_126;
V_42 -> V_112 = F_68 ( V_124 -> V_59 , 100 ) ;
if ( V_120 )
V_42 -> V_120 = V_120 ;
if ( V_43 )
F_26 ( V_42 , V_43 ) ;
F_69 ( V_19 , V_42 ) ;
return 0 ;
V_126:
F_70 ( V_127 L_6 ,
__FILE__ , V_128 , V_19 -> V_129 . V_101 ) ;
F_19 ( V_19 ) ;
return - V_130 ;
}
static int F_71 ( struct V_42 * V_124 , struct V_19 * V_19 ,
T_6 V_111 ,
const struct V_125 * V_120 ,
void * V_43 )
{
int V_8 ;
V_8 = F_66 ( V_124 , V_19 , V_131 | V_111 , V_120 , V_43 ) ;
if ( V_8 )
return V_8 ;
F_72 ( V_124 , V_19 ) ;
return 0 ;
}
static int F_73 ( struct V_42 * V_124 , struct V_19 * V_19 ,
T_6 V_111 ,
const struct V_125 * V_120 ,
void * V_43 )
{
int V_8 ;
V_8 = F_66 ( V_124 , V_19 , V_119 | V_111 , V_120 , V_43 ) ;
if ( V_8 )
return V_8 ;
F_65 ( V_124 ) ;
F_74 ( V_124 , V_19 ) ;
return 0 ;
}
static void
F_75 ( struct V_16 * V_17 )
{
V_17 -> V_22 = 0 ;
V_17 -> V_46 = 0 ;
F_76 ( & V_17 -> V_47 ) ;
F_76 ( & V_17 -> V_132 ) ;
F_76 ( & V_17 -> V_17 ) ;
V_17 -> V_23 = 0 ;
F_77 ( & V_17 -> V_18 ,
F_11 ) ;
V_17 -> V_21 = NULL ;
F_78 ( & V_17 -> V_20 ) ;
V_17 -> V_19 = NULL ;
}
void F_79 ( struct V_16 * V_17 )
{
F_80 ( V_17 ) ;
}
struct V_16 * F_81 ( const struct V_133 * V_21 , int V_38 )
{
struct V_16 * V_17 ;
V_17 = F_82 ( sizeof( struct V_16 ) , V_54 ) ;
if ( ! V_17 )
return F_83 ( - V_130 ) ;
F_75 ( V_17 ) ;
V_17 -> V_21 = V_21 ;
V_17 -> V_38 = V_38 ;
return V_17 ;
}
static int F_84 ( struct V_42 * V_124 , struct V_19 * V_19 ,
T_6 V_111 ,
const struct V_125 * V_120 ,
void * V_43 ,
struct V_16 * V_17 )
{
struct V_51 * V_52 ;
int V_8 ;
V_8 = F_66 ( V_124 , V_19 , V_134 | V_111 , V_120 , V_43 ) ;
if ( V_8 )
return V_8 ;
V_52 = F_18 ( V_19 -> V_24 ) ;
V_52 -> V_43 = V_43 ;
V_52 -> V_17 = V_17 ;
F_72 ( V_124 , V_19 ) ;
return 0 ;
}
static int F_85 ( struct V_42 * V_124 , struct V_19 * V_19 )
{
int V_107 ;
F_16 ( V_19 ) ;
V_107 = F_86 ( V_124 , V_19 ) ;
F_87 ( V_19 ) ;
F_19 ( V_19 ) ;
return V_107 ;
}
int F_88 ( struct V_19 * V_19 )
{
struct V_19 * V_135 ;
struct V_42 * V_124 ;
int error ;
V_135 = F_89 ( V_19 ) ;
V_124 = V_135 -> V_24 ;
F_90 ( & V_124 -> V_45 , V_136 ) ;
error = F_85 ( V_124 , V_19 ) ;
F_30 ( & V_124 -> V_45 ) ;
F_19 ( V_135 ) ;
return error ;
}
static int F_91 ( struct V_42 * V_124 , struct V_19 * V_19 )
{
int V_107 ;
F_16 ( V_19 ) ;
V_107 = F_92 ( V_124 , V_19 ) ;
F_87 ( V_19 ) ;
F_19 ( V_19 ) ;
return V_107 ;
}
static int F_93 ( struct V_42 * V_124 , struct V_19 * V_19 )
{
struct V_42 * V_42 = V_19 -> V_24 ;
F_27 ( V_42 ) ;
return F_91 ( V_124 , V_19 ) ;
}
static struct V_19 * F_94 ( struct V_19 * V_135 ,
const char * V_101 )
{
struct V_137 V_138 = F_95 ( V_101 , strlen ( V_101 ) ) ;
struct V_19 * V_19 = F_96 ( V_135 , & V_138 ) ;
if ( ! V_19 ) {
V_19 = F_97 ( V_135 , & V_138 ) ;
if ( ! V_19 )
return F_83 ( - V_130 ) ;
}
if ( V_19 -> V_24 == NULL )
return V_19 ;
F_19 ( V_19 ) ;
return F_83 ( - V_139 ) ;
}
static void F_98 ( struct V_19 * V_135 ,
const struct V_140 * V_141 ,
int V_142 , int V_143 )
{
struct V_42 * V_124 = V_135 -> V_24 ;
struct V_19 * V_19 ;
struct V_137 V_101 ;
int V_144 ;
for ( V_144 = V_142 ; V_144 < V_143 ; V_144 ++ ) {
V_101 . V_101 = V_141 [ V_144 ] . V_101 ;
V_101 . V_33 = strlen ( V_141 [ V_144 ] . V_101 ) ;
V_19 = F_96 ( V_135 , & V_101 ) ;
if ( V_19 == NULL )
continue;
if ( V_19 -> V_24 == NULL )
goto V_10;
switch ( V_19 -> V_24 -> V_113 & V_118 ) {
default:
F_99 () ;
case V_131 :
F_91 ( V_124 , V_19 ) ;
break;
case V_119 :
F_85 ( V_124 , V_19 ) ;
}
V_10:
F_19 ( V_19 ) ;
}
}
static void F_100 ( struct V_19 * V_135 ,
const struct V_140 * V_141 ,
int V_142 , int V_143 )
{
struct V_42 * V_124 = V_135 -> V_24 ;
F_90 ( & V_124 -> V_45 , V_145 ) ;
F_98 ( V_135 , V_141 , V_142 , V_143 ) ;
F_30 ( & V_124 -> V_45 ) ;
}
static int F_101 ( struct V_19 * V_135 ,
const struct V_140 * V_141 ,
int V_142 , int V_143 ,
void * V_43 )
{
struct V_42 * V_124 = V_135 -> V_24 ;
struct V_19 * V_19 ;
int V_144 , V_8 ;
F_28 ( & V_124 -> V_45 ) ;
for ( V_144 = V_142 ; V_144 < V_143 ; V_144 ++ ) {
V_19 = F_94 ( V_135 , V_141 [ V_144 ] . V_101 ) ;
V_8 = F_102 ( V_19 ) ;
if ( F_103 ( V_19 ) )
goto V_146;
switch ( V_141 [ V_144 ] . V_111 & V_118 ) {
default:
F_99 () ;
case V_131 :
V_8 = F_71 ( V_124 , V_19 ,
V_141 [ V_144 ] . V_111 ,
V_141 [ V_144 ] . V_120 ,
V_43 ) ;
break;
case V_119 :
V_8 = F_73 ( V_124 , V_19 ,
V_141 [ V_144 ] . V_111 ,
NULL ,
V_43 ) ;
}
if ( V_8 != 0 )
goto V_146;
}
F_30 ( & V_124 -> V_45 ) ;
return 0 ;
V_146:
F_98 ( V_135 , V_141 , V_142 , V_143 ) ;
F_30 ( & V_124 -> V_45 ) ;
F_70 ( V_127 L_7 ,
__FILE__ , V_128 , V_135 -> V_129 . V_101 ) ;
return V_8 ;
}
static struct V_19 * F_104 ( struct V_19 * V_135 ,
const char * V_101 , T_6 V_111 , void * V_43 ,
int (* F_105)( struct V_19 * , void * ) , void * V_147 )
{
struct V_19 * V_19 ;
struct V_42 * V_124 = V_135 -> V_24 ;
int error ;
F_90 ( & V_124 -> V_45 , V_136 ) ;
V_19 = F_94 ( V_135 , V_101 ) ;
if ( F_103 ( V_19 ) )
goto V_67;
error = F_73 ( V_124 , V_19 , V_111 , NULL , V_43 ) ;
if ( error != 0 )
goto V_126;
if ( F_105 != NULL ) {
error = F_105 ( V_19 , V_147 ) ;
if ( error )
goto V_148;
}
V_67:
F_30 ( & V_124 -> V_45 ) ;
return V_19 ;
V_148:
F_85 ( V_124 , V_19 ) ;
V_126:
V_19 = F_83 ( error ) ;
goto V_67;
}
static int F_106 ( struct V_19 * V_19 ,
void (* F_107)( struct V_19 * ) )
{
struct V_19 * V_135 ;
struct V_42 * V_124 ;
int error ;
V_135 = F_89 ( V_19 ) ;
V_124 = V_135 -> V_24 ;
F_90 ( & V_124 -> V_45 , V_136 ) ;
if ( F_107 != NULL )
F_107 ( V_19 ) ;
error = F_85 ( V_124 , V_19 ) ;
F_30 ( & V_124 -> V_45 ) ;
F_19 ( V_135 ) ;
return error ;
}
struct V_19 * F_108 ( struct V_19 * V_135 , const char * V_101 ,
void * V_43 , struct V_16 * V_17 )
{
struct V_19 * V_19 ;
struct V_42 * V_124 = V_135 -> V_24 ;
T_6 V_149 = V_134 | V_150 | V_151 ;
int V_8 ;
if ( V_17 -> V_21 -> V_78 == NULL )
V_149 &= ~ V_152 ;
if ( V_17 -> V_21 -> V_79 == NULL )
V_149 &= ~ V_153 ;
F_90 ( & V_124 -> V_45 , V_136 ) ;
V_19 = F_94 ( V_135 , V_101 ) ;
if ( F_103 ( V_19 ) )
goto V_67;
V_8 = F_84 ( V_124 , V_19 , V_149 , & V_154 ,
V_43 , V_17 ) ;
if ( V_8 )
goto V_126;
V_67:
F_30 ( & V_124 -> V_45 ) ;
return V_19 ;
V_126:
V_19 = F_83 ( V_8 ) ;
F_70 ( V_127 L_8 ,
__FILE__ , V_128 , V_135 -> V_129 . V_101 , V_101 ,
V_8 ) ;
goto V_67;
}
int
F_109 ( struct V_19 * V_19 )
{
struct V_19 * V_135 ;
struct V_42 * V_124 ;
int error = 0 ;
V_135 = F_89 ( V_19 ) ;
V_124 = V_135 -> V_24 ;
F_90 ( & V_124 -> V_45 , V_136 ) ;
error = F_93 ( V_124 , V_19 ) ;
F_30 ( & V_124 -> V_45 ) ;
F_19 ( V_135 ) ;
return error ;
}
void F_110 ( struct V_155 * V_156 )
{
F_76 ( & V_156 -> V_157 ) ;
V_156 -> V_158 = NULL ;
}
void F_111 ( struct V_159 * V_160 ,
const struct V_161 * V_162 ,
void * V_163 )
{
F_76 ( & V_160 -> V_164 ) ;
V_160 -> V_162 = V_162 ;
V_160 -> V_163 = V_163 ;
}
static int
F_112 ( struct V_58 * V_58 ,
struct V_155 * V_156 ,
struct V_159 * V_160 )
{
int V_107 = 0 ;
if ( V_156 -> V_158 )
V_107 = V_160 -> V_162 -> V_165 ( V_156 -> V_158 , V_160 ) ;
if ( V_107 == 0 )
F_24 ( & V_160 -> V_164 , & V_156 -> V_157 ) ;
return V_107 ;
}
static void
F_113 ( struct V_58 * V_58 ,
struct V_155 * V_156 ,
struct V_159 * V_160 )
{
if ( V_156 -> V_158 )
V_160 -> V_162 -> V_166 ( V_156 -> V_158 , V_160 ) ;
F_9 ( & V_160 -> V_164 ) ;
}
int
F_114 ( struct V_58 * V_58 ,
struct V_155 * V_156 ,
struct V_159 * V_160 )
{
int V_107 = 0 ;
if ( F_7 ( & V_160 -> V_164 ) ) {
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
F_28 ( & V_62 -> V_167 ) ;
V_107 = F_112 ( V_58 , V_156 , V_160 ) ;
F_30 ( & V_62 -> V_167 ) ;
}
return V_107 ;
}
void
F_115 ( struct V_58 * V_58 ,
struct V_155 * V_156 ,
struct V_159 * V_160 )
{
if ( ! F_7 ( & V_160 -> V_164 ) ) {
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
F_28 ( & V_62 -> V_167 ) ;
F_113 ( V_58 , V_156 , V_160 ) ;
F_30 ( & V_62 -> V_167 ) ;
}
}
static void
F_116 ( struct V_155 * V_156 )
{
struct V_159 * V_160 ;
struct V_19 * V_124 = V_156 -> V_158 ;
F_117 (pdo, &pdh->pdh_entries, pdo_head)
V_160 -> V_162 -> V_165 ( V_124 , V_160 ) ;
}
static void
F_118 ( struct V_155 * V_156 )
{
struct V_159 * V_160 ;
struct V_19 * V_124 = V_156 -> V_158 ;
F_117 (pdo, &pdh->pdh_entries, pdo_head)
V_160 -> V_162 -> V_166 ( V_124 , V_160 ) ;
}
static int F_119 ( struct V_19 * V_19 , void * V_43 )
{
return F_101 ( V_19 ,
V_168 , V_169 , V_170 ,
V_43 ) ;
}
static void F_120 ( struct V_19 * V_19 )
{
F_100 ( V_19 , V_168 , V_169 , V_170 ) ;
}
struct V_19 * F_121 ( struct V_19 * V_19 ,
const char * V_101 ,
struct V_96 * V_171 )
{
struct V_19 * V_107 ;
V_107 = F_104 ( V_19 , V_101 , V_152 | V_172 , NULL ,
F_119 , V_171 ) ;
if ( ! F_103 ( V_107 ) ) {
V_171 -> V_173 . V_158 = V_107 ;
F_116 ( & V_171 -> V_173 ) ;
}
return V_107 ;
}
int F_122 ( struct V_96 * V_171 )
{
struct V_19 * V_19 = V_171 -> V_173 . V_158 ;
if ( V_19 == NULL )
return 0 ;
F_118 ( & V_171 -> V_173 ) ;
V_171 -> V_173 . V_158 = NULL ;
return F_106 ( V_19 , F_120 ) ;
}
static int F_123 ( struct V_19 * V_19 , void * V_43 )
{
return F_101 ( V_19 ,
V_174 , 0 , 3 ,
V_43 ) ;
}
static void F_124 ( struct V_19 * V_19 )
{
F_100 ( V_19 , V_174 , 0 , 3 ) ;
}
struct V_19 * F_125 ( struct V_19 * V_135 , const char * V_101 ,
T_6 V_149 , struct V_175 * V_176 )
{
return F_104 ( V_135 , V_101 , V_149 , NULL ,
F_123 , V_176 ) ;
}
void F_126 ( struct V_19 * V_19 )
{
F_106 ( V_19 , F_124 ) ;
}
struct V_19 * F_127 ( const struct V_49 * V_50 ,
const unsigned char * V_177 )
{
struct V_137 V_124 = F_95 ( V_177 , strlen ( V_177 ) ) ;
return F_96 ( V_50 -> V_178 , & V_124 ) ;
}
void F_128 ( struct V_58 * V_58 )
{
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
F_129 ( & V_62 -> V_167 ) ;
V_62 -> V_66 = 1 ;
V_62 -> V_179 = - 1 ;
}
struct V_49 * F_130 ( const struct V_58 * V_58 )
{
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
F_28 ( & V_62 -> V_167 ) ;
if ( V_62 -> V_180 )
return V_62 -> V_180 ;
F_30 ( & V_62 -> V_167 ) ;
return NULL ;
}
void F_131 ( const struct V_58 * V_58 )
{
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
F_132 ( V_62 -> V_180 == NULL ) ;
F_30 ( & V_62 -> V_167 ) ;
}
static int
F_133 ( struct V_49 * V_50 , void * V_30 , int V_181 )
{
struct V_42 * V_42 ;
struct V_19 * V_182 ;
struct V_58 * V_58 = V_30 ;
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
int V_8 ;
V_50 -> V_183 = V_184 ;
V_50 -> V_185 = V_186 ;
V_50 -> V_187 = V_188 ;
V_50 -> V_189 = & V_190 ;
V_50 -> V_191 = & V_192 ;
V_50 -> V_193 = 1 ;
V_42 = F_62 ( V_50 , V_119 | V_152 | V_172 ) ;
V_50 -> V_178 = V_182 = F_134 ( V_42 ) ;
if ( ! V_182 )
return - V_130 ;
if ( F_101 ( V_182 , V_141 , V_194 , V_195 , NULL ) )
return - V_130 ;
F_135 ( L_9 ,
V_58 , F_136 ( V_58 ) ) ;
F_28 ( & V_62 -> V_167 ) ;
V_62 -> V_180 = V_50 ;
V_8 = F_137 ( & V_3 ,
V_196 ,
V_50 ) ;
if ( V_8 )
goto V_197;
V_50 -> V_60 = F_138 ( V_58 ) ;
F_30 ( & V_62 -> V_167 ) ;
return 0 ;
V_197:
F_137 ( & V_3 ,
V_198 ,
V_50 ) ;
V_62 -> V_180 = NULL ;
F_98 ( V_182 , V_141 , V_194 , V_195 ) ;
F_30 ( & V_62 -> V_167 ) ;
return V_8 ;
}
static struct V_19 *
F_139 ( struct V_199 * V_200 ,
int V_38 , const char * V_201 , void * V_30 )
{
return F_140 ( V_200 , V_38 , V_202 -> V_203 -> V_204 , F_133 ) ;
}
static void F_141 ( struct V_49 * V_50 )
{
struct V_58 * V_58 = V_50 -> V_60 ;
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
F_28 ( & V_62 -> V_167 ) ;
if ( V_62 -> V_180 != V_50 ) {
F_30 ( & V_62 -> V_167 ) ;
goto V_67;
}
V_62 -> V_180 = NULL ;
F_135 ( L_10 ,
V_58 , F_136 ( V_58 ) ) ;
F_137 ( & V_3 ,
V_198 ,
V_50 ) ;
F_30 ( & V_62 -> V_167 ) ;
F_142 ( V_58 ) ;
V_67:
F_143 ( V_50 ) ;
}
static void
F_144 ( void * V_205 )
{
struct V_51 * V_52 = (struct V_51 * ) V_205 ;
F_145 ( & V_52 -> V_55 ) ;
V_52 -> V_43 = NULL ;
V_52 -> V_17 = NULL ;
F_146 ( & V_52 -> V_4 ) ;
}
int F_147 ( void )
{
int V_8 ;
V_53 = F_148 ( L_11 ,
sizeof( struct V_51 ) ,
0 , ( V_206 | V_207 |
V_208 ) ,
F_144 ) ;
if ( ! V_53 )
return - V_130 ;
V_8 = F_149 () ;
if ( V_8 )
goto V_209;
V_8 = F_150 ( & V_210 ) ;
if ( V_8 )
goto V_211;
return 0 ;
V_211:
F_151 () ;
V_209:
F_152 ( V_53 ) ;
return V_8 ;
}
void F_153 ( void )
{
F_151 () ;
F_152 ( V_53 ) ;
F_154 ( & V_210 ) ;
}
