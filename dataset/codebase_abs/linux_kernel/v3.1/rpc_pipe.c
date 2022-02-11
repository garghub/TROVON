static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void (* F_2)( struct V_5 * ) , int V_6 )
{
struct V_5 * V_7 ;
if ( F_3 ( V_4 ) )
return;
do {
V_7 = F_4 ( V_4 -> V_8 , struct V_5 , V_9 ) ;
F_5 ( & V_7 -> V_9 ) ;
V_7 -> V_10 = V_6 ;
F_2 ( V_7 ) ;
} while ( ! F_3 ( V_4 ) );
F_6 ( & V_2 -> V_11 ) ;
}
static void
F_7 ( struct V_12 * V_13 )
{
F_8 ( V_14 ) ;
struct V_1 * V_2 =
F_9 ( V_13 , struct V_1 , V_15 . V_13 ) ;
struct V_16 * V_16 = & V_2 -> V_17 ;
void (* F_2)( struct V_5 * );
F_10 ( & V_16 -> V_18 ) ;
if ( V_2 -> V_19 == NULL ) {
F_11 ( & V_16 -> V_18 ) ;
return;
}
F_2 = V_2 -> V_19 -> F_2 ;
if ( V_2 -> V_20 == 0 ) {
F_12 ( & V_2 -> V_21 , & V_14 ) ;
V_2 -> V_22 = 0 ;
}
F_11 ( & V_16 -> V_18 ) ;
F_1 ( V_2 , & V_14 , F_2 , - V_23 ) ;
}
int
F_13 ( struct V_16 * V_16 , struct V_5 * V_7 )
{
struct V_1 * V_2 = F_14 ( V_16 ) ;
int V_24 = - V_25 ;
F_10 ( & V_16 -> V_18 ) ;
if ( V_2 -> V_19 == NULL )
goto V_26;
if ( V_2 -> V_20 ) {
F_15 ( & V_7 -> V_9 , & V_2 -> V_21 ) ;
V_2 -> V_22 += V_7 -> V_27 ;
V_24 = 0 ;
} else if ( V_2 -> V_28 & V_29 ) {
if ( F_3 ( & V_2 -> V_21 ) )
F_16 ( V_30 ,
& V_2 -> V_15 ,
V_31 ) ;
F_15 ( & V_7 -> V_9 , & V_2 -> V_21 ) ;
V_2 -> V_22 += V_7 -> V_27 ;
V_24 = 0 ;
}
V_26:
F_11 ( & V_16 -> V_18 ) ;
F_6 ( & V_2 -> V_11 ) ;
return V_24 ;
}
static inline void
F_17 ( struct V_16 * V_16 , void * V_32 )
{
F_14 ( V_16 ) -> V_32 = V_32 ;
}
static void
F_18 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = F_14 ( V_16 ) ;
const struct V_33 * V_19 ;
int V_34 ;
F_19 ( & V_16 -> V_35 ) ;
V_19 = V_2 -> V_19 ;
if ( V_19 != NULL ) {
F_8 ( V_14 ) ;
F_10 ( & V_16 -> V_18 ) ;
V_34 = V_2 -> V_20 != 0 || V_2 -> V_36 != 0 ;
V_2 -> V_20 = 0 ;
F_12 ( & V_2 -> V_37 , & V_14 ) ;
F_12 ( & V_2 -> V_21 , & V_14 ) ;
V_2 -> V_22 = 0 ;
V_2 -> V_19 = NULL ;
F_11 ( & V_16 -> V_18 ) ;
F_1 ( V_2 , & V_14 , V_19 -> F_2 , - V_25 ) ;
V_2 -> V_36 = 0 ;
if ( V_34 && V_19 -> V_38 )
V_19 -> V_38 ( V_16 ) ;
F_20 ( & V_2 -> V_15 ) ;
}
F_17 ( V_16 , NULL ) ;
F_21 ( & V_16 -> V_35 ) ;
}
static struct V_16 *
F_22 ( struct V_39 * V_40 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_23 ( V_41 , V_42 ) ;
if ( ! V_2 )
return NULL ;
return & V_2 -> V_17 ;
}
static void
F_24 ( struct V_43 * V_4 )
{
struct V_16 * V_16 = F_9 ( V_4 , struct V_16 , V_44 ) ;
F_25 ( & V_16 -> V_45 ) ;
F_26 ( V_41 , F_14 ( V_16 ) ) ;
}
static void
F_27 ( struct V_16 * V_16 )
{
F_28 ( & V_16 -> V_44 , F_24 ) ;
}
static int
F_29 ( struct V_16 * V_16 , struct V_46 * V_47 )
{
struct V_1 * V_2 = F_14 ( V_16 ) ;
int V_48 ;
int V_24 = - V_49 ;
F_19 ( & V_16 -> V_35 ) ;
if ( V_2 -> V_19 == NULL )
goto V_26;
V_48 = V_2 -> V_20 == 0 && V_2 -> V_36 == 0 ;
if ( V_48 && V_2 -> V_19 -> V_50 ) {
V_24 = V_2 -> V_19 -> V_50 ( V_16 ) ;
if ( V_24 )
goto V_26;
}
if ( V_47 -> V_51 & V_52 )
V_2 -> V_20 ++ ;
if ( V_47 -> V_51 & V_53 )
V_2 -> V_36 ++ ;
V_24 = 0 ;
V_26:
F_21 ( & V_16 -> V_35 ) ;
return V_24 ;
}
static int
F_30 ( struct V_16 * V_16 , struct V_46 * V_47 )
{
struct V_1 * V_2 = F_14 ( V_16 ) ;
struct V_5 * V_7 ;
int V_54 ;
F_19 ( & V_16 -> V_35 ) ;
if ( V_2 -> V_19 == NULL )
goto V_26;
V_7 = V_47 -> V_55 ;
if ( V_7 != NULL ) {
F_10 ( & V_16 -> V_18 ) ;
V_7 -> V_10 = - V_56 ;
F_5 ( & V_7 -> V_9 ) ;
F_11 ( & V_16 -> V_18 ) ;
V_2 -> V_19 -> F_2 ( V_7 ) ;
}
if ( V_47 -> V_51 & V_53 )
V_2 -> V_36 -- ;
if ( V_47 -> V_51 & V_52 ) {
V_2 -> V_20 -- ;
if ( V_2 -> V_20 == 0 ) {
F_8 ( V_14 ) ;
F_10 ( & V_16 -> V_18 ) ;
F_12 ( & V_2 -> V_21 , & V_14 ) ;
V_2 -> V_22 = 0 ;
F_11 ( & V_16 -> V_18 ) ;
F_1 ( V_2 , & V_14 ,
V_2 -> V_19 -> F_2 , - V_56 ) ;
}
}
V_54 = V_2 -> V_36 == 0 && V_2 -> V_20 == 0 ;
if ( V_54 && V_2 -> V_19 -> V_38 )
V_2 -> V_19 -> V_38 ( V_16 ) ;
V_26:
F_21 ( & V_16 -> V_35 ) ;
return 0 ;
}
static T_1
F_31 ( struct V_46 * V_47 , char T_2 * V_57 , T_3 V_27 , T_4 * V_58 )
{
struct V_16 * V_16 = V_47 -> V_59 . V_60 -> V_61 ;
struct V_1 * V_2 = F_14 ( V_16 ) ;
struct V_5 * V_7 ;
int V_24 = 0 ;
F_19 ( & V_16 -> V_35 ) ;
if ( V_2 -> V_19 == NULL ) {
V_24 = - V_25 ;
goto V_62;
}
V_7 = V_47 -> V_55 ;
if ( V_7 == NULL ) {
F_10 ( & V_16 -> V_18 ) ;
if ( ! F_3 ( & V_2 -> V_21 ) ) {
V_7 = F_4 ( V_2 -> V_21 . V_8 ,
struct V_5 ,
V_9 ) ;
F_32 ( & V_7 -> V_9 , & V_2 -> V_37 ) ;
V_2 -> V_22 -= V_7 -> V_27 ;
V_47 -> V_55 = V_7 ;
V_7 -> V_63 = 0 ;
}
F_11 ( & V_16 -> V_18 ) ;
if ( V_7 == NULL )
goto V_62;
}
V_24 = V_2 -> V_19 -> V_64 ( V_47 , V_7 , V_57 , V_27 ) ;
if ( V_24 < 0 || V_7 -> V_27 == V_7 -> V_63 ) {
V_47 -> V_55 = NULL ;
F_10 ( & V_16 -> V_18 ) ;
F_5 ( & V_7 -> V_9 ) ;
F_11 ( & V_16 -> V_18 ) ;
V_2 -> V_19 -> F_2 ( V_7 ) ;
}
V_62:
F_21 ( & V_16 -> V_35 ) ;
return V_24 ;
}
static T_1
F_33 ( struct V_46 * V_47 , const char T_2 * V_57 , T_3 V_27 , T_4 * V_58 )
{
struct V_16 * V_16 = V_47 -> V_59 . V_60 -> V_61 ;
struct V_1 * V_2 = F_14 ( V_16 ) ;
int V_24 ;
F_19 ( & V_16 -> V_35 ) ;
V_24 = - V_25 ;
if ( V_2 -> V_19 != NULL )
V_24 = V_2 -> V_19 -> V_65 ( V_47 , V_57 , V_27 ) ;
F_21 ( & V_16 -> V_35 ) ;
return V_24 ;
}
static unsigned int
F_34 ( struct V_46 * V_47 , struct V_66 * V_67 )
{
struct V_1 * V_2 ;
unsigned int V_68 = 0 ;
V_2 = F_14 ( V_47 -> V_59 . V_60 -> V_61 ) ;
F_35 ( V_47 , & V_2 -> V_11 , V_67 ) ;
V_68 = V_69 | V_70 ;
if ( V_2 -> V_19 == NULL )
V_68 |= V_71 | V_72 ;
if ( V_47 -> V_55 || ! F_3 ( & V_2 -> V_21 ) )
V_68 |= V_73 | V_74 ;
return V_68 ;
}
static long
F_36 ( struct V_46 * V_47 , unsigned int V_75 , unsigned long V_76 )
{
struct V_16 * V_16 = V_47 -> V_59 . V_60 -> V_61 ;
struct V_1 * V_2 = F_14 ( V_16 ) ;
int V_27 ;
switch ( V_75 ) {
case V_77 :
F_10 ( & V_16 -> V_18 ) ;
if ( V_2 -> V_19 == NULL ) {
F_11 ( & V_16 -> V_18 ) ;
return - V_25 ;
}
V_27 = V_2 -> V_22 ;
if ( V_47 -> V_55 ) {
struct V_5 * V_7 ;
V_7 = V_47 -> V_55 ;
V_27 += V_7 -> V_27 - V_7 -> V_63 ;
}
F_11 ( & V_16 -> V_18 ) ;
return F_37 ( V_27 , ( int T_2 * ) V_76 ) ;
default:
return - V_78 ;
}
}
static int
F_38 ( struct V_79 * V_80 , void * V_81 )
{
struct V_82 * V_83 = V_80 -> V_32 ;
F_39 ( V_80 , L_1 , V_83 -> V_84 ) ;
F_39 ( V_80 , L_2 , V_83 -> V_85 ,
V_83 -> V_86 , V_83 -> V_87 ) ;
F_39 ( V_80 , L_3 , F_40 ( V_83 , V_88 ) ) ;
F_39 ( V_80 , L_4 , F_40 ( V_83 , V_89 ) ) ;
F_39 ( V_80 , L_5 , F_40 ( V_83 , V_90 ) ) ;
return 0 ;
}
static int
F_41 ( struct V_16 * V_16 , struct V_46 * V_46 )
{
struct V_82 * V_83 = NULL ;
int V_91 = F_42 ( V_46 , F_38 , NULL ) ;
if ( ! V_91 ) {
struct V_79 * V_80 = V_46 -> V_55 ;
F_10 ( & V_46 -> V_59 . V_60 -> V_92 ) ;
if ( ! F_43 ( V_46 -> V_59 . V_60 ) )
V_83 = F_14 ( V_16 ) -> V_32 ;
if ( V_83 != NULL && F_44 ( & V_83 -> V_93 ) ) {
F_11 ( & V_46 -> V_59 . V_60 -> V_92 ) ;
V_80 -> V_32 = V_83 ;
} else {
F_11 ( & V_46 -> V_59 . V_60 -> V_92 ) ;
F_45 ( V_16 , V_46 ) ;
V_91 = - V_78 ;
}
}
return V_91 ;
}
static int
F_46 ( struct V_16 * V_16 , struct V_46 * V_46 )
{
struct V_79 * V_80 = V_46 -> V_55 ;
struct V_82 * V_83 = (struct V_82 * ) V_80 -> V_32 ;
if ( V_83 )
F_47 ( V_83 ) ;
return F_45 ( V_16 , V_46 ) ;
}
struct V_94 * F_48 ( void )
{
int V_6 ;
V_6 = F_49 ( & V_95 , & V_96 , & V_97 ) ;
if ( V_6 != 0 )
return F_50 ( V_6 ) ;
return V_96 ;
}
void F_51 ( void )
{
F_52 ( & V_96 , & V_97 ) ;
}
static int F_53 ( const struct V_60 * V_60 )
{
return 1 ;
}
static struct V_16 *
F_54 ( struct V_39 * V_40 , T_5 V_98 )
{
struct V_16 * V_16 = F_55 ( V_40 ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_99 = F_56 () ;
V_16 -> V_100 = V_98 ;
V_16 -> V_101 = V_16 -> V_102 = V_16 -> V_103 = V_104 ;
switch ( V_98 & V_105 ) {
case V_106 :
V_16 -> V_107 = & V_108 ;
V_16 -> V_109 = & V_110 ;
F_57 ( V_16 ) ;
default:
break;
}
return V_16 ;
}
static int F_58 ( struct V_16 * V_111 , struct V_60 * V_60 ,
T_5 V_98 ,
const struct V_112 * V_107 ,
void * V_32 )
{
struct V_16 * V_16 ;
F_59 ( V_60 ) ;
V_16 = F_54 ( V_111 -> V_113 , V_98 ) ;
if ( ! V_16 )
goto V_114;
V_16 -> V_99 = F_60 ( V_111 -> V_113 , 100 ) ;
if ( V_107 )
V_16 -> V_107 = V_107 ;
if ( V_32 )
F_17 ( V_16 , V_32 ) ;
F_61 ( V_60 , V_16 ) ;
return 0 ;
V_114:
F_62 ( V_115 L_6 ,
__FILE__ , V_116 , V_60 -> V_117 . V_118 ) ;
F_63 ( V_60 ) ;
return - V_119 ;
}
static int F_64 ( struct V_16 * V_111 , struct V_60 * V_60 ,
T_5 V_98 ,
const struct V_112 * V_107 ,
void * V_32 )
{
int V_6 ;
V_6 = F_58 ( V_111 , V_60 , V_120 | V_98 , V_107 , V_32 ) ;
if ( V_6 )
return V_6 ;
F_65 ( V_111 , V_60 ) ;
return 0 ;
}
static int F_66 ( struct V_16 * V_111 , struct V_60 * V_60 ,
T_5 V_98 ,
const struct V_112 * V_107 ,
void * V_32 )
{
int V_6 ;
V_6 = F_58 ( V_111 , V_60 , V_106 | V_98 , V_107 , V_32 ) ;
if ( V_6 )
return V_6 ;
F_57 ( V_111 ) ;
F_67 ( V_111 , V_60 ) ;
return 0 ;
}
static int F_68 ( struct V_16 * V_111 , struct V_60 * V_60 ,
T_5 V_98 ,
const struct V_112 * V_107 ,
void * V_32 ,
const struct V_33 * V_19 ,
int V_28 )
{
struct V_1 * V_2 ;
int V_6 ;
V_6 = F_58 ( V_111 , V_60 , V_121 | V_98 , V_107 , V_32 ) ;
if ( V_6 )
return V_6 ;
V_2 = F_14 ( V_60 -> V_61 ) ;
V_2 -> V_122 = 1 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_19 = V_19 ;
F_65 ( V_111 , V_60 ) ;
return 0 ;
}
static int F_69 ( struct V_16 * V_111 , struct V_60 * V_60 )
{
int V_91 ;
F_70 ( V_60 ) ;
V_91 = F_71 ( V_111 , V_60 ) ;
F_72 ( V_60 ) ;
F_63 ( V_60 ) ;
return V_91 ;
}
static int F_73 ( struct V_16 * V_111 , struct V_60 * V_60 )
{
int V_91 ;
F_70 ( V_60 ) ;
V_91 = F_74 ( V_111 , V_60 ) ;
F_72 ( V_60 ) ;
F_63 ( V_60 ) ;
return V_91 ;
}
static int F_75 ( struct V_16 * V_111 , struct V_60 * V_60 )
{
struct V_16 * V_16 = V_60 -> V_61 ;
struct V_1 * V_2 = F_14 ( V_16 ) ;
V_2 -> V_122 -- ;
if ( V_2 -> V_122 != 0 )
return 0 ;
F_18 ( V_16 ) ;
return F_73 ( V_111 , V_60 ) ;
}
static struct V_60 * F_76 ( struct V_60 * V_123 ,
struct V_124 * V_118 )
{
struct V_60 * V_60 ;
V_60 = F_77 ( V_123 , V_118 ) ;
if ( ! V_60 ) {
V_60 = F_78 ( V_123 , V_118 ) ;
if ( ! V_60 ) {
V_60 = F_50 ( - V_119 ) ;
goto V_114;
}
}
if ( ! V_60 -> V_61 )
F_79 ( V_60 , & V_125 ) ;
V_114:
return V_60 ;
}
static struct V_60 * F_80 ( struct V_60 * V_123 ,
struct V_124 * V_118 )
{
struct V_60 * V_60 ;
V_60 = F_76 ( V_123 , V_118 ) ;
if ( F_81 ( V_60 ) )
return V_60 ;
if ( V_60 -> V_61 == NULL )
return V_60 ;
F_63 ( V_60 ) ;
return F_50 ( - V_126 ) ;
}
static void F_82 ( struct V_60 * V_123 ,
const struct V_127 * V_128 ,
int V_129 , int V_130 )
{
struct V_16 * V_111 = V_123 -> V_61 ;
struct V_60 * V_60 ;
struct V_124 V_118 ;
int V_131 ;
for ( V_131 = V_129 ; V_131 < V_130 ; V_131 ++ ) {
V_118 . V_118 = V_128 [ V_131 ] . V_118 ;
V_118 . V_27 = strlen ( V_128 [ V_131 ] . V_118 ) ;
V_118 . V_132 = F_83 ( V_118 . V_118 , V_118 . V_27 ) ;
V_60 = F_77 ( V_123 , & V_118 ) ;
if ( V_60 == NULL )
continue;
if ( V_60 -> V_61 == NULL )
goto V_8;
switch ( V_60 -> V_61 -> V_100 & V_105 ) {
default:
F_84 () ;
case V_120 :
F_73 ( V_111 , V_60 ) ;
break;
case V_106 :
F_69 ( V_111 , V_60 ) ;
}
V_8:
F_63 ( V_60 ) ;
}
}
static void F_85 ( struct V_60 * V_123 ,
const struct V_127 * V_128 ,
int V_129 , int V_130 )
{
struct V_16 * V_111 = V_123 -> V_61 ;
F_86 ( & V_111 -> V_35 , V_133 ) ;
F_82 ( V_123 , V_128 , V_129 , V_130 ) ;
F_21 ( & V_111 -> V_35 ) ;
}
static int F_87 ( struct V_60 * V_123 ,
const struct V_127 * V_128 ,
int V_129 , int V_130 ,
void * V_32 )
{
struct V_16 * V_111 = V_123 -> V_61 ;
struct V_60 * V_60 ;
int V_131 , V_6 ;
F_19 ( & V_111 -> V_35 ) ;
for ( V_131 = V_129 ; V_131 < V_130 ; V_131 ++ ) {
struct V_124 V_134 ;
V_134 . V_118 = V_128 [ V_131 ] . V_118 ;
V_134 . V_27 = strlen ( V_128 [ V_131 ] . V_118 ) ;
V_134 . V_132 = F_83 ( V_134 . V_118 , V_134 . V_27 ) ;
V_60 = F_80 ( V_123 , & V_134 ) ;
V_6 = F_88 ( V_60 ) ;
if ( F_81 ( V_60 ) )
goto V_135;
switch ( V_128 [ V_131 ] . V_98 & V_105 ) {
default:
F_84 () ;
case V_120 :
V_6 = F_64 ( V_111 , V_60 ,
V_128 [ V_131 ] . V_98 ,
V_128 [ V_131 ] . V_107 ,
V_32 ) ;
break;
case V_106 :
V_6 = F_66 ( V_111 , V_60 ,
V_128 [ V_131 ] . V_98 ,
NULL ,
V_32 ) ;
}
if ( V_6 != 0 )
goto V_135;
}
F_21 ( & V_111 -> V_35 ) ;
return 0 ;
V_135:
F_82 ( V_123 , V_128 , V_129 , V_130 ) ;
F_21 ( & V_111 -> V_35 ) ;
F_62 ( V_115 L_7 ,
__FILE__ , V_116 , V_123 -> V_117 . V_118 ) ;
return V_6 ;
}
static struct V_60 * F_89 ( struct V_60 * V_123 ,
struct V_124 * V_118 , T_5 V_98 , void * V_32 ,
int (* F_90)( struct V_60 * , void * ) , void * V_136 )
{
struct V_60 * V_60 ;
struct V_16 * V_111 = V_123 -> V_61 ;
int error ;
F_86 ( & V_111 -> V_35 , V_137 ) ;
V_60 = F_80 ( V_123 , V_118 ) ;
if ( F_81 ( V_60 ) )
goto V_26;
error = F_66 ( V_111 , V_60 , V_98 , NULL , V_32 ) ;
if ( error != 0 )
goto V_114;
if ( F_90 != NULL ) {
error = F_90 ( V_60 , V_136 ) ;
if ( error )
goto V_138;
}
V_26:
F_21 ( & V_111 -> V_35 ) ;
return V_60 ;
V_138:
F_69 ( V_111 , V_60 ) ;
V_114:
V_60 = F_50 ( error ) ;
goto V_26;
}
static int F_91 ( struct V_60 * V_60 ,
void (* F_92)( struct V_60 * ) )
{
struct V_60 * V_123 ;
struct V_16 * V_111 ;
int error ;
V_123 = F_93 ( V_60 ) ;
V_111 = V_123 -> V_61 ;
F_86 ( & V_111 -> V_35 , V_137 ) ;
if ( F_92 != NULL )
F_92 ( V_60 ) ;
error = F_69 ( V_111 , V_60 ) ;
F_21 ( & V_111 -> V_35 ) ;
F_63 ( V_123 ) ;
return error ;
}
struct V_60 * F_94 ( struct V_60 * V_123 , const char * V_118 ,
void * V_32 , const struct V_33 * V_19 ,
int V_28 )
{
struct V_60 * V_60 ;
struct V_16 * V_111 = V_123 -> V_61 ;
T_5 V_139 = V_121 | V_140 | V_141 ;
struct V_124 V_134 ;
int V_6 ;
if ( V_19 -> V_64 == NULL )
V_139 &= ~ V_142 ;
if ( V_19 -> V_65 == NULL )
V_139 &= ~ V_143 ;
V_134 . V_118 = V_118 ;
V_134 . V_27 = strlen ( V_118 ) ;
V_134 . V_132 = F_83 ( V_134 . V_118 , V_134 . V_27 ) ,
F_86 ( & V_111 -> V_35 , V_137 ) ;
V_60 = F_76 ( V_123 , & V_134 ) ;
if ( F_81 ( V_60 ) )
goto V_26;
if ( V_60 -> V_61 ) {
struct V_1 * V_2 = F_14 ( V_60 -> V_61 ) ;
if ( V_2 -> V_32 != V_32 ||
V_2 -> V_19 != V_19 ||
V_2 -> V_28 != V_28 ) {
F_63 ( V_60 ) ;
V_6 = - V_144 ;
goto V_114;
}
V_2 -> V_122 ++ ;
goto V_26;
}
V_6 = F_68 ( V_111 , V_60 , V_139 , & V_145 ,
V_32 , V_19 , V_28 ) ;
if ( V_6 )
goto V_114;
V_26:
F_21 ( & V_111 -> V_35 ) ;
return V_60 ;
V_114:
V_60 = F_50 ( V_6 ) ;
F_62 ( V_115 L_8 ,
__FILE__ , V_116 , V_123 -> V_117 . V_118 , V_118 ,
V_6 ) ;
goto V_26;
}
int
F_95 ( struct V_60 * V_60 )
{
struct V_60 * V_123 ;
struct V_16 * V_111 ;
int error = 0 ;
V_123 = F_93 ( V_60 ) ;
V_111 = V_123 -> V_61 ;
F_86 ( & V_111 -> V_35 , V_137 ) ;
error = F_75 ( V_111 , V_60 ) ;
F_21 ( & V_111 -> V_35 ) ;
F_63 ( V_123 ) ;
return error ;
}
static int F_96 ( struct V_60 * V_60 , void * V_32 )
{
return F_87 ( V_60 ,
V_146 , V_147 , V_148 ,
V_32 ) ;
}
static void F_97 ( struct V_60 * V_60 )
{
F_85 ( V_60 , V_146 , V_147 , V_148 ) ;
}
struct V_60 * F_98 ( struct V_60 * V_60 ,
struct V_124 * V_118 ,
struct V_82 * V_149 )
{
return F_89 ( V_60 , V_118 , V_142 | V_150 , NULL ,
F_96 , V_149 ) ;
}
int F_99 ( struct V_60 * V_60 )
{
return F_91 ( V_60 , F_97 ) ;
}
static int F_100 ( struct V_60 * V_60 , void * V_32 )
{
return F_87 ( V_60 ,
V_151 , 0 , 3 ,
V_32 ) ;
}
static void F_101 ( struct V_60 * V_60 )
{
F_85 ( V_60 , V_151 , 0 , 3 ) ;
}
struct V_60 * F_102 ( struct V_60 * V_123 , struct V_124 * V_118 ,
T_6 V_139 , struct V_152 * V_153 )
{
return F_89 ( V_123 , V_118 , V_139 , NULL ,
F_100 , V_153 ) ;
}
void F_103 ( struct V_60 * V_60 )
{
F_91 ( V_60 , F_101 ) ;
}
static int
F_104 ( struct V_39 * V_40 , void * V_154 , int V_155 )
{
struct V_16 * V_16 ;
struct V_60 * V_156 ;
V_40 -> V_157 = V_158 ;
V_40 -> V_159 = V_160 ;
V_40 -> V_161 = V_162 ;
V_40 -> V_163 = & V_164 ;
V_40 -> V_165 = 1 ;
V_16 = F_54 ( V_40 , V_106 | 0755 ) ;
if ( ! V_16 )
return - V_119 ;
V_40 -> V_166 = V_156 = F_105 ( V_16 ) ;
if ( ! V_156 ) {
F_106 ( V_16 ) ;
return - V_119 ;
}
if ( F_87 ( V_156 , V_128 , V_167 , V_168 , NULL ) )
return - V_119 ;
return 0 ;
}
static struct V_60 *
F_107 ( struct V_169 * V_170 ,
int V_28 , const char * V_171 , void * V_154 )
{
return F_108 ( V_170 , V_28 , V_154 , F_104 ) ;
}
static void
F_109 ( void * V_172 )
{
struct V_1 * V_2 = (struct V_1 * ) V_172 ;
F_110 ( & V_2 -> V_17 ) ;
V_2 -> V_32 = NULL ;
V_2 -> V_20 = 0 ;
V_2 -> V_36 = 0 ;
F_25 ( & V_2 -> V_37 ) ;
F_25 ( & V_2 -> V_173 ) ;
F_25 ( & V_2 -> V_21 ) ;
V_2 -> V_22 = 0 ;
F_111 ( & V_2 -> V_11 ) ;
F_112 ( & V_2 -> V_15 ,
F_7 ) ;
V_2 -> V_19 = NULL ;
}
int F_113 ( void )
{
int V_6 ;
V_41 = F_114 ( L_9 ,
sizeof( struct V_1 ) ,
0 , ( V_174 | V_175 |
V_176 ) ,
F_109 ) ;
if ( ! V_41 )
return - V_119 ;
V_6 = F_115 ( & V_95 ) ;
if ( V_6 ) {
F_116 ( V_41 ) ;
return V_6 ;
}
return 0 ;
}
void F_117 ( void )
{
F_116 ( V_41 ) ;
F_118 ( & V_95 ) ;
}
