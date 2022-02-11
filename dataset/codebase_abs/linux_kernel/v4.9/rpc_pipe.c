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
F_5 ( V_19 ? & F_18 ( F_19 ( V_19 ) ) -> V_4 : NULL ,
& V_15 , F_6 , - V_24 ) ;
F_20 ( V_19 ) ;
}
T_2 F_21 ( struct V_25 * V_26 , struct V_7 * V_9 ,
char T_3 * V_27 , T_4 V_28 )
{
char * V_29 = ( char * ) V_9 -> V_29 + V_9 -> V_30 ;
T_4 V_31 = F_22 ( V_9 -> V_32 - V_9 -> V_30 , V_28 ) ;
unsigned long V_33 ;
V_33 = F_23 ( V_27 , V_29 , V_31 ) ;
if ( V_33 == V_31 ) {
V_9 -> V_12 = - V_34 ;
return - V_34 ;
}
V_31 -= V_33 ;
V_9 -> V_30 += V_31 ;
V_9 -> V_12 = 0 ;
return V_31 ;
}
int
F_24 ( struct V_16 * V_17 , struct V_7 * V_9 )
{
int V_35 = - V_36 ;
struct V_19 * V_19 ;
F_14 ( & V_17 -> V_20 ) ;
if ( V_17 -> V_22 ) {
F_25 ( & V_9 -> V_11 , & V_17 -> V_17 ) ;
V_17 -> V_23 += V_9 -> V_32 ;
V_35 = 0 ;
} else if ( V_17 -> V_37 & V_38 ) {
if ( F_7 ( & V_17 -> V_17 ) )
F_26 ( V_39 ,
& V_17 -> V_18 ,
V_40 ) ;
F_25 ( & V_9 -> V_11 , & V_17 -> V_17 ) ;
V_17 -> V_23 += V_9 -> V_32 ;
V_35 = 0 ;
}
V_19 = F_16 ( V_17 -> V_19 ) ;
F_17 ( & V_17 -> V_20 ) ;
if ( V_19 ) {
F_10 ( & F_18 ( F_19 ( V_19 ) ) -> V_4 ) ;
F_20 ( V_19 ) ;
}
return V_35 ;
}
static inline void
F_27 ( struct V_41 * V_41 , void * V_42 )
{
F_18 ( V_41 ) -> V_42 = V_42 ;
}
static void
F_28 ( struct V_41 * V_41 )
{
struct V_16 * V_17 = F_18 ( V_41 ) -> V_17 ;
int V_43 ;
F_12 ( V_15 ) ;
F_29 ( V_41 ) ;
F_14 ( & V_17 -> V_20 ) ;
V_43 = V_17 -> V_22 != 0 || V_17 -> V_44 != 0 ;
V_17 -> V_22 = 0 ;
F_15 ( & V_17 -> V_45 , & V_15 ) ;
F_15 ( & V_17 -> V_17 , & V_15 ) ;
V_17 -> V_23 = 0 ;
V_17 -> V_19 = NULL ;
F_17 ( & V_17 -> V_20 ) ;
F_5 ( & F_18 ( V_41 ) -> V_4 , & V_15 , V_17 -> V_21 -> F_6 , - V_36 ) ;
V_17 -> V_44 = 0 ;
if ( V_43 && V_17 -> V_21 -> V_46 )
V_17 -> V_21 -> V_46 ( V_41 ) ;
F_30 ( & V_17 -> V_18 ) ;
F_27 ( V_41 , NULL ) ;
F_18 ( V_41 ) -> V_17 = NULL ;
F_31 ( V_41 ) ;
}
static struct V_41 *
F_32 ( struct V_47 * V_48 )
{
struct V_49 * V_50 ;
V_50 = F_33 ( V_51 , V_52 ) ;
if ( ! V_50 )
return NULL ;
return & V_50 -> V_53 ;
}
static void
F_34 ( struct V_54 * V_6 )
{
struct V_41 * V_41 = F_13 ( V_6 , struct V_41 , V_55 ) ;
F_35 ( V_51 , F_18 ( V_41 ) ) ;
}
static void
F_36 ( struct V_41 * V_41 )
{
F_37 ( & V_41 -> V_55 , F_34 ) ;
}
static int
F_38 ( struct V_41 * V_41 , struct V_25 * V_26 )
{
struct V_16 * V_17 ;
int V_56 ;
int V_35 = - V_57 ;
F_29 ( V_41 ) ;
V_17 = F_18 ( V_41 ) -> V_17 ;
if ( V_17 == NULL )
goto V_58;
V_56 = V_17 -> V_22 == 0 && V_17 -> V_44 == 0 ;
if ( V_56 && V_17 -> V_21 -> V_59 ) {
V_35 = V_17 -> V_21 -> V_59 ( V_41 ) ;
if ( V_35 )
goto V_58;
}
if ( V_26 -> V_60 & V_61 )
V_17 -> V_22 ++ ;
if ( V_26 -> V_60 & V_62 )
V_17 -> V_44 ++ ;
V_35 = 0 ;
V_58:
F_31 ( V_41 ) ;
return V_35 ;
}
static int
F_39 ( struct V_41 * V_41 , struct V_25 * V_26 )
{
struct V_16 * V_17 ;
struct V_7 * V_9 ;
int V_63 ;
F_29 ( V_41 ) ;
V_17 = F_18 ( V_41 ) -> V_17 ;
if ( V_17 == NULL )
goto V_58;
V_9 = V_26 -> V_64 ;
if ( V_9 != NULL ) {
F_14 ( & V_17 -> V_20 ) ;
V_9 -> V_12 = - V_65 ;
F_9 ( & V_9 -> V_11 ) ;
F_17 ( & V_17 -> V_20 ) ;
V_17 -> V_21 -> F_6 ( V_9 ) ;
}
if ( V_26 -> V_60 & V_62 )
V_17 -> V_44 -- ;
if ( V_26 -> V_60 & V_61 ) {
V_17 -> V_22 -- ;
if ( V_17 -> V_22 == 0 ) {
F_12 ( V_15 ) ;
F_14 ( & V_17 -> V_20 ) ;
F_15 ( & V_17 -> V_17 , & V_15 ) ;
V_17 -> V_23 = 0 ;
F_17 ( & V_17 -> V_20 ) ;
F_5 ( & F_18 ( V_41 ) -> V_4 , & V_15 ,
V_17 -> V_21 -> F_6 , - V_65 ) ;
}
}
V_63 = V_17 -> V_44 == 0 && V_17 -> V_22 == 0 ;
if ( V_63 && V_17 -> V_21 -> V_46 )
V_17 -> V_21 -> V_46 ( V_41 ) ;
V_58:
F_31 ( V_41 ) ;
return 0 ;
}
static T_2
F_40 ( struct V_25 * V_26 , char T_3 * V_66 , T_4 V_32 , T_5 * V_67 )
{
struct V_41 * V_41 = F_41 ( V_26 ) ;
struct V_16 * V_17 ;
struct V_7 * V_9 ;
int V_35 = 0 ;
F_29 ( V_41 ) ;
V_17 = F_18 ( V_41 ) -> V_17 ;
if ( V_17 == NULL ) {
V_35 = - V_36 ;
goto V_68;
}
V_9 = V_26 -> V_64 ;
if ( V_9 == NULL ) {
F_14 ( & V_17 -> V_20 ) ;
if ( ! F_7 ( & V_17 -> V_17 ) ) {
V_9 = F_8 ( V_17 -> V_17 . V_10 ,
struct V_7 ,
V_11 ) ;
F_42 ( & V_9 -> V_11 , & V_17 -> V_45 ) ;
V_17 -> V_23 -= V_9 -> V_32 ;
V_26 -> V_64 = V_9 ;
V_9 -> V_30 = 0 ;
}
F_17 ( & V_17 -> V_20 ) ;
if ( V_9 == NULL )
goto V_68;
}
V_35 = V_17 -> V_21 -> V_69 ( V_26 , V_9 , V_66 , V_32 ) ;
if ( V_35 < 0 || V_9 -> V_32 == V_9 -> V_30 ) {
V_26 -> V_64 = NULL ;
F_14 ( & V_17 -> V_20 ) ;
F_9 ( & V_9 -> V_11 ) ;
F_17 ( & V_17 -> V_20 ) ;
V_17 -> V_21 -> F_6 ( V_9 ) ;
}
V_68:
F_31 ( V_41 ) ;
return V_35 ;
}
static T_2
F_43 ( struct V_25 * V_26 , const char T_3 * V_66 , T_4 V_32 , T_5 * V_67 )
{
struct V_41 * V_41 = F_41 ( V_26 ) ;
int V_35 ;
F_29 ( V_41 ) ;
V_35 = - V_36 ;
if ( F_18 ( V_41 ) -> V_17 != NULL )
V_35 = F_18 ( V_41 ) -> V_17 -> V_21 -> V_70 ( V_26 , V_66 , V_32 ) ;
F_31 ( V_41 ) ;
return V_35 ;
}
static unsigned int
F_44 ( struct V_25 * V_26 , struct V_71 * V_72 )
{
struct V_41 * V_41 = F_41 ( V_26 ) ;
struct V_49 * V_50 = F_18 ( V_41 ) ;
unsigned int V_73 = V_74 | V_75 ;
F_45 ( V_26 , & V_50 -> V_4 , V_72 ) ;
F_29 ( V_41 ) ;
if ( V_50 -> V_17 == NULL )
V_73 |= V_76 | V_77 ;
else if ( V_26 -> V_64 || ! F_7 ( & V_50 -> V_17 -> V_17 ) )
V_73 |= V_78 | V_79 ;
F_31 ( V_41 ) ;
return V_73 ;
}
static long
F_46 ( struct V_25 * V_26 , unsigned int V_80 , unsigned long V_81 )
{
struct V_41 * V_41 = F_41 ( V_26 ) ;
struct V_16 * V_17 ;
int V_32 ;
switch ( V_80 ) {
case V_82 :
F_29 ( V_41 ) ;
V_17 = F_18 ( V_41 ) -> V_17 ;
if ( V_17 == NULL ) {
F_31 ( V_41 ) ;
return - V_36 ;
}
F_14 ( & V_17 -> V_20 ) ;
V_32 = V_17 -> V_23 ;
if ( V_26 -> V_64 ) {
struct V_7 * V_9 ;
V_9 = V_26 -> V_64 ;
V_32 += V_9 -> V_32 - V_9 -> V_30 ;
}
F_17 ( & V_17 -> V_20 ) ;
F_31 ( V_41 ) ;
return F_47 ( V_32 , ( int T_3 * ) V_81 ) ;
default:
return - V_83 ;
}
}
static int
F_48 ( struct V_84 * V_85 , void * V_86 )
{
struct V_87 * V_88 = V_85 -> V_42 ;
F_49 () ;
F_50 ( V_85 , L_1 ,
F_51 ( V_88 -> V_89 ) -> V_90 ) ;
F_50 ( V_85 , L_2 , V_88 -> V_91 -> V_92 ,
V_88 -> V_93 , V_88 -> V_94 ) ;
F_50 ( V_85 , L_3 , F_52 ( V_88 , V_95 ) ) ;
F_50 ( V_85 , L_4 , F_52 ( V_88 , V_96 ) ) ;
F_50 ( V_85 , L_5 , F_52 ( V_88 , V_97 ) ) ;
F_53 () ;
return 0 ;
}
static int
F_54 ( struct V_41 * V_41 , struct V_25 * V_25 )
{
struct V_87 * V_88 = NULL ;
int V_98 = F_55 ( V_25 , F_48 , NULL ) ;
if ( ! V_98 ) {
struct V_84 * V_85 = V_25 -> V_64 ;
F_14 ( & V_25 -> V_99 . V_19 -> V_100 ) ;
if ( ! F_56 ( V_25 -> V_99 . V_19 ) )
V_88 = F_18 ( V_41 ) -> V_42 ;
if ( V_88 != NULL && F_57 ( & V_88 -> V_101 ) ) {
F_17 ( & V_25 -> V_99 . V_19 -> V_100 ) ;
V_85 -> V_42 = V_88 ;
} else {
F_17 ( & V_25 -> V_99 . V_19 -> V_100 ) ;
F_58 ( V_41 , V_25 ) ;
V_98 = - V_83 ;
}
}
return V_98 ;
}
static int
F_59 ( struct V_41 * V_41 , struct V_25 * V_25 )
{
struct V_84 * V_85 = V_25 -> V_64 ;
struct V_87 * V_88 = (struct V_87 * ) V_85 -> V_42 ;
if ( V_88 )
F_60 ( V_88 ) ;
return F_58 ( V_41 , V_25 ) ;
}
static struct V_41 *
F_61 ( struct V_47 * V_48 , T_6 V_102 )
{
struct V_41 * V_41 = F_62 ( V_48 ) ;
if ( ! V_41 )
return NULL ;
V_41 -> V_103 = F_63 () ;
V_41 -> V_104 = V_102 ;
V_41 -> V_105 = V_41 -> V_106 = V_41 -> V_107 = F_64 ( V_41 ) ;
switch ( V_102 & V_108 ) {
case V_109 :
V_41 -> V_110 = & V_111 ;
V_41 -> V_112 = & V_113 ;
F_65 ( V_41 ) ;
default:
break;
}
return V_41 ;
}
static int F_66 ( struct V_41 * V_114 , struct V_19 * V_19 ,
T_6 V_102 ,
const struct V_115 * V_110 ,
void * V_42 )
{
struct V_41 * V_41 ;
F_67 ( V_19 ) ;
V_41 = F_61 ( V_114 -> V_116 , V_102 ) ;
if ( ! V_41 )
goto V_117;
V_41 -> V_103 = F_68 ( V_114 -> V_116 , 100 ) ;
if ( V_110 )
V_41 -> V_110 = V_110 ;
if ( V_42 )
F_27 ( V_41 , V_42 ) ;
F_69 ( V_19 , V_41 ) ;
return 0 ;
V_117:
F_70 ( V_118 L_6 ,
__FILE__ , V_119 , V_19 ) ;
F_20 ( V_19 ) ;
return - V_120 ;
}
static int F_71 ( struct V_41 * V_114 , struct V_19 * V_19 ,
T_6 V_102 ,
const struct V_115 * V_110 ,
void * V_42 )
{
int V_8 ;
V_8 = F_66 ( V_114 , V_19 , V_121 | V_102 , V_110 , V_42 ) ;
if ( V_8 )
return V_8 ;
F_72 ( V_114 , V_19 ) ;
return 0 ;
}
static int F_73 ( struct V_41 * V_114 , struct V_19 * V_19 ,
T_6 V_102 ,
const struct V_115 * V_110 ,
void * V_42 )
{
int V_8 ;
V_8 = F_66 ( V_114 , V_19 , V_109 | V_102 , V_110 , V_42 ) ;
if ( V_8 )
return V_8 ;
F_65 ( V_114 ) ;
F_74 ( V_114 , V_19 ) ;
return 0 ;
}
static void
F_75 ( struct V_16 * V_17 )
{
V_17 -> V_22 = 0 ;
V_17 -> V_44 = 0 ;
F_76 ( & V_17 -> V_45 ) ;
F_76 ( & V_17 -> V_122 ) ;
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
struct V_16 * F_81 ( const struct V_123 * V_21 , int V_37 )
{
struct V_16 * V_17 ;
V_17 = F_82 ( sizeof( struct V_16 ) , V_52 ) ;
if ( ! V_17 )
return F_83 ( - V_120 ) ;
F_75 ( V_17 ) ;
V_17 -> V_21 = V_21 ;
V_17 -> V_37 = V_37 ;
return V_17 ;
}
static int F_84 ( struct V_41 * V_114 , struct V_19 * V_19 ,
T_6 V_102 ,
const struct V_115 * V_110 ,
void * V_42 ,
struct V_16 * V_17 )
{
struct V_49 * V_50 ;
int V_8 ;
V_8 = F_66 ( V_114 , V_19 , V_124 | V_102 , V_110 , V_42 ) ;
if ( V_8 )
return V_8 ;
V_50 = F_18 ( F_19 ( V_19 ) ) ;
V_50 -> V_42 = V_42 ;
V_50 -> V_17 = V_17 ;
F_72 ( V_114 , V_19 ) ;
return 0 ;
}
static int F_85 ( struct V_41 * V_114 , struct V_19 * V_19 )
{
int V_98 ;
F_16 ( V_19 ) ;
V_98 = F_86 ( V_114 , V_19 ) ;
F_87 ( V_19 ) ;
F_20 ( V_19 ) ;
return V_98 ;
}
int F_88 ( struct V_19 * V_19 )
{
struct V_19 * V_125 ;
struct V_41 * V_114 ;
int error ;
V_125 = F_89 ( V_19 ) ;
V_114 = F_19 ( V_125 ) ;
F_90 ( V_114 , V_126 ) ;
error = F_85 ( V_114 , V_19 ) ;
F_31 ( V_114 ) ;
F_20 ( V_125 ) ;
return error ;
}
static int F_91 ( struct V_41 * V_114 , struct V_19 * V_19 )
{
int V_98 ;
F_16 ( V_19 ) ;
V_98 = F_92 ( V_114 , V_19 ) ;
F_87 ( V_19 ) ;
F_20 ( V_19 ) ;
return V_98 ;
}
static int F_93 ( struct V_41 * V_114 , struct V_19 * V_19 )
{
struct V_41 * V_41 = F_19 ( V_19 ) ;
F_28 ( V_41 ) ;
return F_91 ( V_114 , V_19 ) ;
}
static struct V_19 * F_94 ( struct V_19 * V_125 ,
const char * V_92 )
{
struct V_127 V_128 = F_95 ( V_92 , strlen ( V_92 ) ) ;
struct V_19 * V_19 = F_96 ( V_125 , & V_128 ) ;
if ( ! V_19 ) {
V_19 = F_97 ( V_125 , & V_128 ) ;
if ( ! V_19 )
return F_83 ( - V_120 ) ;
}
if ( F_98 ( V_19 ) )
return V_19 ;
F_20 ( V_19 ) ;
return F_83 ( - V_129 ) ;
}
static void F_99 ( struct V_19 * V_125 ,
const struct V_130 * V_131 ,
int V_132 , int V_133 )
{
struct V_41 * V_114 = F_19 ( V_125 ) ;
struct V_19 * V_19 ;
struct V_127 V_92 ;
int V_134 ;
for ( V_134 = V_132 ; V_134 < V_133 ; V_134 ++ ) {
V_92 . V_92 = V_131 [ V_134 ] . V_92 ;
V_92 . V_32 = strlen ( V_131 [ V_134 ] . V_92 ) ;
V_19 = F_96 ( V_125 , & V_92 ) ;
if ( V_19 == NULL )
continue;
if ( F_98 ( V_19 ) )
goto V_10;
switch ( F_19 ( V_19 ) -> V_104 & V_108 ) {
default:
F_100 () ;
case V_121 :
F_91 ( V_114 , V_19 ) ;
break;
case V_109 :
F_85 ( V_114 , V_19 ) ;
}
V_10:
F_20 ( V_19 ) ;
}
}
static void F_101 ( struct V_19 * V_125 ,
const struct V_130 * V_131 ,
int V_132 , int V_133 )
{
struct V_41 * V_114 = F_19 ( V_125 ) ;
F_90 ( V_114 , V_135 ) ;
F_99 ( V_125 , V_131 , V_132 , V_133 ) ;
F_31 ( V_114 ) ;
}
static int F_102 ( struct V_19 * V_125 ,
const struct V_130 * V_131 ,
int V_132 , int V_133 ,
void * V_42 )
{
struct V_41 * V_114 = F_19 ( V_125 ) ;
struct V_19 * V_19 ;
int V_134 , V_8 ;
F_29 ( V_114 ) ;
for ( V_134 = V_132 ; V_134 < V_133 ; V_134 ++ ) {
V_19 = F_94 ( V_125 , V_131 [ V_134 ] . V_92 ) ;
V_8 = F_103 ( V_19 ) ;
if ( F_104 ( V_19 ) )
goto V_136;
switch ( V_131 [ V_134 ] . V_102 & V_108 ) {
default:
F_100 () ;
case V_121 :
V_8 = F_71 ( V_114 , V_19 ,
V_131 [ V_134 ] . V_102 ,
V_131 [ V_134 ] . V_110 ,
V_42 ) ;
break;
case V_109 :
V_8 = F_73 ( V_114 , V_19 ,
V_131 [ V_134 ] . V_102 ,
NULL ,
V_42 ) ;
}
if ( V_8 != 0 )
goto V_136;
}
F_31 ( V_114 ) ;
return 0 ;
V_136:
F_99 ( V_125 , V_131 , V_132 , V_133 ) ;
F_31 ( V_114 ) ;
F_70 ( V_118 L_7 ,
__FILE__ , V_119 , V_125 ) ;
return V_8 ;
}
static struct V_19 * F_105 ( struct V_19 * V_125 ,
const char * V_92 , T_6 V_102 , void * V_42 ,
int (* F_106)( struct V_19 * , void * ) , void * V_137 )
{
struct V_19 * V_19 ;
struct V_41 * V_114 = F_19 ( V_125 ) ;
int error ;
F_90 ( V_114 , V_126 ) ;
V_19 = F_94 ( V_125 , V_92 ) ;
if ( F_104 ( V_19 ) )
goto V_58;
error = F_73 ( V_114 , V_19 , V_102 , NULL , V_42 ) ;
if ( error != 0 )
goto V_117;
if ( F_106 != NULL ) {
error = F_106 ( V_19 , V_137 ) ;
if ( error )
goto V_138;
}
V_58:
F_31 ( V_114 ) ;
return V_19 ;
V_138:
F_85 ( V_114 , V_19 ) ;
V_117:
V_19 = F_83 ( error ) ;
goto V_58;
}
static int F_107 ( struct V_19 * V_19 ,
void (* F_108)( struct V_19 * ) )
{
struct V_19 * V_125 ;
struct V_41 * V_114 ;
int error ;
V_125 = F_89 ( V_19 ) ;
V_114 = F_19 ( V_125 ) ;
F_90 ( V_114 , V_126 ) ;
if ( F_108 != NULL )
F_108 ( V_19 ) ;
error = F_85 ( V_114 , V_19 ) ;
F_31 ( V_114 ) ;
F_20 ( V_125 ) ;
return error ;
}
struct V_19 * F_109 ( struct V_19 * V_125 , const char * V_92 ,
void * V_42 , struct V_16 * V_17 )
{
struct V_19 * V_19 ;
struct V_41 * V_114 = F_19 ( V_125 ) ;
T_6 V_139 = V_124 | V_140 | V_141 ;
int V_8 ;
if ( V_17 -> V_21 -> V_69 == NULL )
V_139 &= ~ V_142 ;
if ( V_17 -> V_21 -> V_70 == NULL )
V_139 &= ~ V_143 ;
F_90 ( V_114 , V_126 ) ;
V_19 = F_94 ( V_125 , V_92 ) ;
if ( F_104 ( V_19 ) )
goto V_58;
V_8 = F_84 ( V_114 , V_19 , V_139 , & V_144 ,
V_42 , V_17 ) ;
if ( V_8 )
goto V_117;
V_58:
F_31 ( V_114 ) ;
return V_19 ;
V_117:
V_19 = F_83 ( V_8 ) ;
F_70 ( V_118 L_8 ,
__FILE__ , V_119 , V_125 , V_92 ,
V_8 ) ;
goto V_58;
}
int
F_110 ( struct V_19 * V_19 )
{
struct V_19 * V_125 ;
struct V_41 * V_114 ;
int error = 0 ;
V_125 = F_89 ( V_19 ) ;
V_114 = F_19 ( V_125 ) ;
F_90 ( V_114 , V_126 ) ;
error = F_93 ( V_114 , V_19 ) ;
F_31 ( V_114 ) ;
F_20 ( V_125 ) ;
return error ;
}
void F_111 ( struct V_145 * V_146 )
{
F_76 ( & V_146 -> V_147 ) ;
V_146 -> V_148 = NULL ;
}
void F_112 ( struct V_149 * V_150 ,
const struct V_151 * V_152 ,
void * V_153 )
{
F_76 ( & V_150 -> V_154 ) ;
V_150 -> V_152 = V_152 ;
V_150 -> V_153 = V_153 ;
}
static int
F_113 ( struct V_155 * V_155 ,
struct V_145 * V_146 ,
struct V_149 * V_150 )
{
int V_98 = 0 ;
if ( V_146 -> V_148 )
V_98 = V_150 -> V_152 -> V_156 ( V_146 -> V_148 , V_150 ) ;
if ( V_98 == 0 )
F_25 ( & V_150 -> V_154 , & V_146 -> V_147 ) ;
return V_98 ;
}
static void
F_114 ( struct V_155 * V_155 ,
struct V_145 * V_146 ,
struct V_149 * V_150 )
{
if ( V_146 -> V_148 )
V_150 -> V_152 -> V_157 ( V_146 -> V_148 , V_150 ) ;
F_9 ( & V_150 -> V_154 ) ;
}
int
F_115 ( struct V_155 * V_155 ,
struct V_145 * V_146 ,
struct V_149 * V_150 )
{
int V_98 = 0 ;
if ( F_7 ( & V_150 -> V_154 ) ) {
struct V_158 * V_159 = F_116 ( V_155 , V_160 ) ;
F_117 ( & V_159 -> V_161 ) ;
V_98 = F_113 ( V_155 , V_146 , V_150 ) ;
F_118 ( & V_159 -> V_161 ) ;
}
return V_98 ;
}
void
F_119 ( struct V_155 * V_155 ,
struct V_145 * V_146 ,
struct V_149 * V_150 )
{
if ( ! F_7 ( & V_150 -> V_154 ) ) {
struct V_158 * V_159 = F_116 ( V_155 , V_160 ) ;
F_117 ( & V_159 -> V_161 ) ;
F_114 ( V_155 , V_146 , V_150 ) ;
F_118 ( & V_159 -> V_161 ) ;
}
}
static void
F_120 ( struct V_145 * V_146 )
{
struct V_149 * V_150 ;
struct V_19 * V_114 = V_146 -> V_148 ;
F_121 (pdo, &pdh->pdh_entries, pdo_head)
V_150 -> V_152 -> V_156 ( V_114 , V_150 ) ;
}
static void
F_122 ( struct V_145 * V_146 )
{
struct V_149 * V_150 ;
struct V_19 * V_114 = V_146 -> V_148 ;
F_121 (pdo, &pdh->pdh_entries, pdo_head)
V_150 -> V_152 -> V_157 ( V_114 , V_150 ) ;
}
static int F_123 ( struct V_19 * V_19 , void * V_42 )
{
return F_102 ( V_19 ,
V_162 , V_163 , V_164 ,
V_42 ) ;
}
static void F_124 ( struct V_19 * V_19 )
{
F_101 ( V_19 , V_162 , V_163 , V_164 ) ;
}
struct V_19 * F_125 ( struct V_19 * V_19 ,
const char * V_92 ,
struct V_87 * V_165 )
{
struct V_19 * V_98 ;
V_98 = F_105 ( V_19 , V_92 , V_142 | V_166 , NULL ,
F_123 , V_165 ) ;
if ( ! F_104 ( V_98 ) ) {
V_165 -> V_167 . V_148 = V_98 ;
F_120 ( & V_165 -> V_167 ) ;
}
return V_98 ;
}
int F_126 ( struct V_87 * V_165 )
{
struct V_19 * V_19 = V_165 -> V_167 . V_148 ;
if ( V_19 == NULL )
return 0 ;
F_122 ( & V_165 -> V_167 ) ;
V_165 -> V_167 . V_148 = NULL ;
return F_107 ( V_19 , F_124 ) ;
}
static int F_127 ( struct V_19 * V_19 , void * V_42 )
{
return F_102 ( V_19 ,
V_168 , 0 , 3 ,
V_42 ) ;
}
static void F_128 ( struct V_19 * V_19 )
{
F_101 ( V_19 , V_168 , 0 , 3 ) ;
}
struct V_19 * F_129 ( struct V_19 * V_125 , const char * V_92 ,
T_6 V_139 , struct V_169 * V_170 )
{
return F_105 ( V_125 , V_92 , V_139 , NULL ,
F_127 , V_170 ) ;
}
void F_130 ( struct V_19 * V_19 )
{
F_107 ( V_19 , F_128 ) ;
}
struct V_19 * F_131 ( const struct V_47 * V_48 ,
const unsigned char * V_171 )
{
struct V_127 V_114 = F_95 ( V_171 , strlen ( V_171 ) ) ;
return F_96 ( V_48 -> V_172 , & V_114 ) ;
}
int F_132 ( struct V_155 * V_155 )
{
struct V_158 * V_159 = F_116 ( V_155 , V_160 ) ;
V_159 -> V_173 = F_81 ( & V_174 , 0 ) ;
if ( F_104 ( V_159 -> V_173 ) )
return F_103 ( V_159 -> V_173 ) ;
F_133 ( & V_159 -> V_161 ) ;
V_159 -> V_175 = - 1 ;
return 0 ;
}
void F_134 ( struct V_155 * V_155 )
{
struct V_158 * V_159 = F_116 ( V_155 , V_160 ) ;
F_79 ( V_159 -> V_173 ) ;
}
struct V_47 * F_135 ( const struct V_155 * V_155 )
{
struct V_158 * V_159 = F_116 ( V_155 , V_160 ) ;
F_117 ( & V_159 -> V_161 ) ;
if ( V_159 -> V_176 )
return V_159 -> V_176 ;
F_118 ( & V_159 -> V_161 ) ;
return NULL ;
}
void F_136 ( const struct V_155 * V_155 )
{
struct V_158 * V_159 = F_116 ( V_155 , V_160 ) ;
F_137 ( V_159 -> V_176 == NULL ) ;
F_118 ( & V_159 -> V_161 ) ;
}
static T_2
F_138 ( struct V_25 * V_26 , const char T_3 * V_177 , T_4 V_32 )
{
return - V_83 ;
}
static int
F_139 ( struct V_84 * V_85 , void * V_86 )
{
F_50 ( V_85 , L_1 , F_140 () -> V_178 ) ;
F_50 ( V_85 , L_9 ) ;
F_50 ( V_85 , L_10 ) ;
F_50 ( V_85 , L_11 ) ;
F_50 ( V_85 , L_12 ) ;
return 0 ;
}
static int
F_141 ( struct V_41 * V_41 , struct V_25 * V_25 )
{
return F_55 ( V_25 , F_139 , NULL ) ;
}
static struct V_19 *
F_142 ( struct V_19 * V_179 , struct V_16 * V_180 )
{
int V_98 = 0 ;
struct V_19 * V_181 ;
struct V_19 * V_182 = NULL ;
struct V_19 * V_183 = NULL ;
struct V_127 V_128 = F_95 ( V_131 [ V_184 ] . V_92 ,
strlen ( V_131 [ V_184 ] . V_92 ) ) ;
V_181 = F_96 ( V_179 , & V_128 ) ;
if ( ! V_181 )
return F_83 ( - V_185 ) ;
V_98 = F_102 ( V_181 , V_186 , 0 , 1 , NULL ) ;
if ( V_98 ) {
V_183 = F_83 ( V_98 ) ;
goto V_58;
}
V_128 . V_92 = V_186 [ 0 ] . V_92 ;
V_128 . V_32 = strlen ( V_186 [ 0 ] . V_92 ) ;
V_182 = F_96 ( V_181 , & V_128 ) ;
if ( ! V_182 ) {
V_183 = F_83 ( - V_185 ) ;
goto V_58;
}
V_98 = F_102 ( V_182 , V_187 , 0 , 1 , NULL ) ;
if ( V_98 ) {
F_99 ( V_181 , V_186 , 0 , 1 ) ;
V_183 = F_83 ( V_98 ) ;
goto V_58;
}
V_183 = F_109 ( V_182 , L_13 , NULL , V_180 ) ;
if ( F_104 ( V_183 ) ) {
F_99 ( V_182 , V_187 , 0 , 1 ) ;
F_99 ( V_181 , V_186 , 0 , 1 ) ;
}
V_58:
F_20 ( V_182 ) ;
F_20 ( V_181 ) ;
return V_183 ;
}
static void
F_143 ( struct V_19 * V_183 )
{
struct V_19 * V_188 = V_183 -> V_189 ;
struct V_19 * V_190 = V_188 -> V_189 ;
F_93 ( F_19 ( V_188 ) , V_183 ) ;
F_99 ( V_188 , V_187 , 0 , 1 ) ;
F_99 ( V_190 , V_186 , 0 , 1 ) ;
F_20 ( V_183 ) ;
}
static int
F_144 ( struct V_47 * V_48 , void * V_29 , int V_191 )
{
struct V_41 * V_41 ;
struct V_19 * V_179 , * V_181 ;
struct V_155 * V_155 = F_145 ( V_48 -> V_192 ) ;
struct V_158 * V_159 = F_116 ( V_155 , V_160 ) ;
int V_8 ;
V_48 -> V_193 = V_194 ;
V_48 -> V_195 = V_196 ;
V_48 -> V_197 = V_198 ;
V_48 -> V_199 = & V_200 ;
V_48 -> V_201 = & V_202 ;
V_48 -> V_203 = 1 ;
V_41 = F_61 ( V_48 , V_109 | V_142 | V_166 ) ;
V_48 -> V_172 = V_179 = F_146 ( V_41 ) ;
if ( ! V_179 )
return - V_120 ;
if ( F_102 ( V_179 , V_131 , V_204 , V_205 , NULL ) )
return - V_120 ;
V_181 = F_142 ( V_179 , V_159 -> V_173 ) ;
if ( F_104 ( V_181 ) ) {
F_99 ( V_179 , V_131 , V_204 , V_205 ) ;
return F_103 ( V_181 ) ;
}
F_147 ( L_14 ,
V_155 , F_148 ( V_155 ) ) ;
F_117 ( & V_159 -> V_161 ) ;
V_159 -> V_176 = V_48 ;
V_8 = F_149 ( & V_3 ,
V_206 ,
V_48 ) ;
if ( V_8 )
goto V_207;
F_118 ( & V_159 -> V_161 ) ;
return 0 ;
V_207:
F_143 ( V_181 ) ;
F_149 ( & V_3 ,
V_208 ,
V_48 ) ;
V_159 -> V_176 = NULL ;
F_99 ( V_179 , V_131 , V_204 , V_205 ) ;
F_118 ( & V_159 -> V_161 ) ;
return V_8 ;
}
bool
F_150 ( struct V_155 * V_155 )
{
struct V_158 * V_159 = F_116 ( V_155 , V_160 ) ;
struct V_16 * V_17 = V_159 -> V_173 ;
return V_17 -> V_22 || V_17 -> V_44 ;
}
static struct V_19 *
F_151 ( struct V_209 * V_210 ,
int V_37 , const char * V_211 , void * V_29 )
{
struct V_155 * V_155 = V_212 -> V_213 -> V_214 ;
return F_152 ( V_210 , V_37 , V_29 , V_155 , V_155 -> V_215 , F_144 ) ;
}
static void F_153 ( struct V_47 * V_48 )
{
struct V_155 * V_155 = V_48 -> V_192 ;
struct V_158 * V_159 = F_116 ( V_155 , V_160 ) ;
F_117 ( & V_159 -> V_161 ) ;
if ( V_159 -> V_176 != V_48 ) {
F_118 ( & V_159 -> V_161 ) ;
goto V_58;
}
V_159 -> V_176 = NULL ;
F_147 ( L_15 ,
V_155 , F_148 ( V_155 ) ) ;
F_149 ( & V_3 ,
V_208 ,
V_48 ) ;
F_118 ( & V_159 -> V_161 ) ;
V_58:
F_154 ( V_48 ) ;
F_155 ( V_155 ) ;
}
static void
F_156 ( void * V_216 )
{
struct V_49 * V_50 = (struct V_49 * ) V_216 ;
F_157 ( & V_50 -> V_53 ) ;
V_50 -> V_42 = NULL ;
V_50 -> V_17 = NULL ;
F_158 ( & V_50 -> V_4 ) ;
}
int F_159 ( void )
{
int V_8 ;
V_51 = F_160 ( L_16 ,
sizeof( struct V_49 ) ,
0 , ( V_217 | V_218 |
V_219 | V_220 ) ,
F_156 ) ;
if ( ! V_51 )
return - V_120 ;
V_8 = F_161 () ;
if ( V_8 )
goto V_221;
V_8 = F_162 ( & V_222 ) ;
if ( V_8 )
goto V_223;
return 0 ;
V_223:
F_163 () ;
V_221:
F_164 ( V_51 ) ;
return V_8 ;
}
void F_165 ( void )
{
F_163 () ;
F_164 ( V_51 ) ;
F_166 ( & V_222 ) ;
}
