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
struct V_16 * V_17 ;
int V_58 ;
int V_36 = - V_59 ;
F_28 ( & V_42 -> V_45 ) ;
V_17 = F_18 ( V_42 ) -> V_17 ;
if ( V_17 == NULL )
goto V_60;
V_58 = V_17 -> V_22 == 0 && V_17 -> V_46 == 0 ;
if ( V_58 && V_17 -> V_21 -> V_61 ) {
V_36 = V_17 -> V_21 -> V_61 ( V_42 ) ;
if ( V_36 )
goto V_60;
}
if ( V_27 -> V_62 & V_63 )
V_17 -> V_22 ++ ;
if ( V_27 -> V_62 & V_64 )
V_17 -> V_46 ++ ;
V_36 = 0 ;
V_60:
F_30 ( & V_42 -> V_45 ) ;
return V_36 ;
}
static int
F_38 ( struct V_42 * V_42 , struct V_26 * V_27 )
{
struct V_16 * V_17 ;
struct V_7 * V_9 ;
int V_65 ;
F_28 ( & V_42 -> V_45 ) ;
V_17 = F_18 ( V_42 ) -> V_17 ;
if ( V_17 == NULL )
goto V_60;
V_9 = V_27 -> V_66 ;
if ( V_9 != NULL ) {
F_14 ( & V_17 -> V_20 ) ;
V_9 -> V_12 = - V_67 ;
F_9 ( & V_9 -> V_11 ) ;
F_17 ( & V_17 -> V_20 ) ;
V_17 -> V_21 -> F_6 ( V_9 ) ;
}
if ( V_27 -> V_62 & V_64 )
V_17 -> V_46 -- ;
if ( V_27 -> V_62 & V_63 ) {
V_17 -> V_22 -- ;
if ( V_17 -> V_22 == 0 ) {
F_12 ( V_15 ) ;
F_14 ( & V_17 -> V_20 ) ;
F_15 ( & V_17 -> V_17 , & V_15 ) ;
V_17 -> V_23 = 0 ;
F_17 ( & V_17 -> V_20 ) ;
F_5 ( & F_18 ( V_42 ) -> V_4 , & V_15 ,
V_17 -> V_21 -> F_6 , - V_67 ) ;
}
}
V_65 = V_17 -> V_46 == 0 && V_17 -> V_22 == 0 ;
if ( V_65 && V_17 -> V_21 -> V_48 )
V_17 -> V_21 -> V_48 ( V_42 ) ;
V_60:
F_30 ( & V_42 -> V_45 ) ;
return 0 ;
}
static T_2
F_39 ( struct V_26 * V_27 , char T_3 * V_68 , T_4 V_33 , T_5 * V_69 )
{
struct V_42 * V_42 = V_27 -> V_70 . V_19 -> V_24 ;
struct V_16 * V_17 ;
struct V_7 * V_9 ;
int V_36 = 0 ;
F_28 ( & V_42 -> V_45 ) ;
V_17 = F_18 ( V_42 ) -> V_17 ;
if ( V_17 == NULL ) {
V_36 = - V_37 ;
goto V_71;
}
V_9 = V_27 -> V_66 ;
if ( V_9 == NULL ) {
F_14 ( & V_17 -> V_20 ) ;
if ( ! F_7 ( & V_17 -> V_17 ) ) {
V_9 = F_8 ( V_17 -> V_17 . V_10 ,
struct V_7 ,
V_11 ) ;
F_40 ( & V_9 -> V_11 , & V_17 -> V_47 ) ;
V_17 -> V_23 -= V_9 -> V_33 ;
V_27 -> V_66 = V_9 ;
V_9 -> V_31 = 0 ;
}
F_17 ( & V_17 -> V_20 ) ;
if ( V_9 == NULL )
goto V_71;
}
V_36 = V_17 -> V_21 -> V_72 ( V_27 , V_9 , V_68 , V_33 ) ;
if ( V_36 < 0 || V_9 -> V_33 == V_9 -> V_31 ) {
V_27 -> V_66 = NULL ;
F_14 ( & V_17 -> V_20 ) ;
F_9 ( & V_9 -> V_11 ) ;
F_17 ( & V_17 -> V_20 ) ;
V_17 -> V_21 -> F_6 ( V_9 ) ;
}
V_71:
F_30 ( & V_42 -> V_45 ) ;
return V_36 ;
}
static T_2
F_41 ( struct V_26 * V_27 , const char T_3 * V_68 , T_4 V_33 , T_5 * V_69 )
{
struct V_42 * V_42 = V_27 -> V_70 . V_19 -> V_24 ;
int V_36 ;
F_28 ( & V_42 -> V_45 ) ;
V_36 = - V_37 ;
if ( F_18 ( V_42 ) -> V_17 != NULL )
V_36 = F_18 ( V_42 ) -> V_17 -> V_21 -> V_73 ( V_27 , V_68 , V_33 ) ;
F_30 ( & V_42 -> V_45 ) ;
return V_36 ;
}
static unsigned int
F_42 ( struct V_26 * V_27 , struct V_74 * V_75 )
{
struct V_42 * V_42 = V_27 -> V_70 . V_19 -> V_24 ;
struct V_51 * V_52 = F_18 ( V_42 ) ;
unsigned int V_76 = V_77 | V_78 ;
F_43 ( V_27 , & V_52 -> V_4 , V_75 ) ;
F_28 ( & V_42 -> V_45 ) ;
if ( V_52 -> V_17 == NULL )
V_76 |= V_79 | V_80 ;
else if ( V_27 -> V_66 || ! F_7 ( & V_52 -> V_17 -> V_17 ) )
V_76 |= V_81 | V_82 ;
F_30 ( & V_42 -> V_45 ) ;
return V_76 ;
}
static long
F_44 ( struct V_26 * V_27 , unsigned int V_83 , unsigned long V_84 )
{
struct V_42 * V_42 = V_27 -> V_70 . V_19 -> V_24 ;
struct V_16 * V_17 ;
int V_33 ;
switch ( V_83 ) {
case V_85 :
F_28 ( & V_42 -> V_45 ) ;
V_17 = F_18 ( V_42 ) -> V_17 ;
if ( V_17 == NULL ) {
F_30 ( & V_42 -> V_45 ) ;
return - V_37 ;
}
F_14 ( & V_17 -> V_20 ) ;
V_33 = V_17 -> V_23 ;
if ( V_27 -> V_66 ) {
struct V_7 * V_9 ;
V_9 = V_27 -> V_66 ;
V_33 += V_9 -> V_33 - V_9 -> V_31 ;
}
F_17 ( & V_17 -> V_20 ) ;
F_30 ( & V_42 -> V_45 ) ;
return F_45 ( V_33 , ( int T_3 * ) V_84 ) ;
default:
return - V_86 ;
}
}
static int
F_46 ( struct V_87 * V_88 , void * V_89 )
{
struct V_90 * V_91 = V_88 -> V_43 ;
F_47 () ;
F_48 ( V_88 , L_1 ,
F_49 ( V_91 -> V_92 ) -> V_93 ) ;
F_48 ( V_88 , L_2 , V_91 -> V_94 ,
V_91 -> V_95 , V_91 -> V_96 ) ;
F_48 ( V_88 , L_3 , F_50 ( V_91 , V_97 ) ) ;
F_48 ( V_88 , L_4 , F_50 ( V_91 , V_98 ) ) ;
F_48 ( V_88 , L_5 , F_50 ( V_91 , V_99 ) ) ;
F_51 () ;
return 0 ;
}
static int
F_52 ( struct V_42 * V_42 , struct V_26 * V_26 )
{
struct V_90 * V_91 = NULL ;
int V_100 = F_53 ( V_26 , F_46 , NULL ) ;
if ( ! V_100 ) {
struct V_87 * V_88 = V_26 -> V_66 ;
F_14 ( & V_26 -> V_70 . V_19 -> V_101 ) ;
if ( ! F_54 ( V_26 -> V_70 . V_19 ) )
V_91 = F_18 ( V_42 ) -> V_43 ;
if ( V_91 != NULL && F_55 ( & V_91 -> V_102 ) ) {
F_17 ( & V_26 -> V_70 . V_19 -> V_101 ) ;
V_88 -> V_43 = V_91 ;
} else {
F_17 ( & V_26 -> V_70 . V_19 -> V_101 ) ;
F_56 ( V_42 , V_26 ) ;
V_100 = - V_86 ;
}
}
return V_100 ;
}
static int
F_57 ( struct V_42 * V_42 , struct V_26 * V_26 )
{
struct V_87 * V_88 = V_26 -> V_66 ;
struct V_90 * V_91 = (struct V_90 * ) V_88 -> V_43 ;
if ( V_91 )
F_58 ( V_91 ) ;
return F_56 ( V_42 , V_26 ) ;
}
static int F_59 ( const struct V_19 * V_19 )
{
return 1 ;
}
static struct V_42 *
F_60 ( struct V_49 * V_50 , T_6 V_103 )
{
struct V_42 * V_42 = F_61 ( V_50 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_104 = F_62 () ;
V_42 -> V_105 = V_103 ;
V_42 -> V_106 = V_42 -> V_107 = V_42 -> V_108 = V_109 ;
switch ( V_103 & V_110 ) {
case V_111 :
V_42 -> V_112 = & V_113 ;
V_42 -> V_114 = & V_115 ;
F_63 ( V_42 ) ;
default:
break;
}
return V_42 ;
}
static int F_64 ( struct V_42 * V_116 , struct V_19 * V_19 ,
T_6 V_103 ,
const struct V_117 * V_112 ,
void * V_43 )
{
struct V_42 * V_42 ;
F_65 ( V_19 ) ;
V_42 = F_60 ( V_116 -> V_118 , V_103 ) ;
if ( ! V_42 )
goto V_119;
V_42 -> V_104 = F_66 ( V_116 -> V_118 , 100 ) ;
if ( V_112 )
V_42 -> V_112 = V_112 ;
if ( V_43 )
F_26 ( V_42 , V_43 ) ;
F_67 ( V_19 , V_42 ) ;
return 0 ;
V_119:
F_68 ( V_120 L_6 ,
__FILE__ , V_121 , V_19 -> V_122 . V_123 ) ;
F_19 ( V_19 ) ;
return - V_124 ;
}
static int F_69 ( struct V_42 * V_116 , struct V_19 * V_19 ,
T_6 V_103 ,
const struct V_117 * V_112 ,
void * V_43 )
{
int V_8 ;
V_8 = F_64 ( V_116 , V_19 , V_125 | V_103 , V_112 , V_43 ) ;
if ( V_8 )
return V_8 ;
F_70 ( V_116 , V_19 ) ;
return 0 ;
}
static int F_71 ( struct V_42 * V_116 , struct V_19 * V_19 ,
T_6 V_103 ,
const struct V_117 * V_112 ,
void * V_43 )
{
int V_8 ;
V_8 = F_64 ( V_116 , V_19 , V_111 | V_103 , V_112 , V_43 ) ;
if ( V_8 )
return V_8 ;
F_63 ( V_116 ) ;
F_72 ( V_116 , V_19 ) ;
return 0 ;
}
static void
F_73 ( struct V_16 * V_17 )
{
V_17 -> V_22 = 0 ;
V_17 -> V_46 = 0 ;
F_74 ( & V_17 -> V_47 ) ;
F_74 ( & V_17 -> V_126 ) ;
F_74 ( & V_17 -> V_17 ) ;
V_17 -> V_23 = 0 ;
F_75 ( & V_17 -> V_18 ,
F_11 ) ;
V_17 -> V_21 = NULL ;
F_76 ( & V_17 -> V_20 ) ;
V_17 -> V_19 = NULL ;
}
void F_77 ( struct V_16 * V_17 )
{
F_78 ( V_17 ) ;
}
struct V_16 * F_79 ( const struct V_127 * V_21 , int V_38 )
{
struct V_16 * V_17 ;
V_17 = F_80 ( sizeof( struct V_16 ) , V_54 ) ;
if ( ! V_17 )
return F_81 ( - V_124 ) ;
F_73 ( V_17 ) ;
V_17 -> V_21 = V_21 ;
V_17 -> V_38 = V_38 ;
return V_17 ;
}
static int F_82 ( struct V_42 * V_116 , struct V_19 * V_19 ,
T_6 V_103 ,
const struct V_117 * V_112 ,
void * V_43 ,
struct V_16 * V_17 )
{
struct V_51 * V_52 ;
int V_8 ;
V_8 = F_64 ( V_116 , V_19 , V_128 | V_103 , V_112 , V_43 ) ;
if ( V_8 )
return V_8 ;
V_52 = F_18 ( V_19 -> V_24 ) ;
V_52 -> V_43 = V_43 ;
V_52 -> V_17 = V_17 ;
F_70 ( V_116 , V_19 ) ;
return 0 ;
}
static int F_83 ( struct V_42 * V_116 , struct V_19 * V_19 )
{
int V_100 ;
F_16 ( V_19 ) ;
V_100 = F_84 ( V_116 , V_19 ) ;
F_85 ( V_19 ) ;
F_19 ( V_19 ) ;
return V_100 ;
}
int F_86 ( struct V_19 * V_19 )
{
struct V_19 * V_129 ;
struct V_42 * V_116 ;
int error ;
V_129 = F_87 ( V_19 ) ;
V_116 = V_129 -> V_24 ;
F_88 ( & V_116 -> V_45 , V_130 ) ;
error = F_83 ( V_116 , V_19 ) ;
F_30 ( & V_116 -> V_45 ) ;
F_19 ( V_129 ) ;
return error ;
}
static int F_89 ( struct V_42 * V_116 , struct V_19 * V_19 )
{
int V_100 ;
F_16 ( V_19 ) ;
V_100 = F_90 ( V_116 , V_19 ) ;
F_85 ( V_19 ) ;
F_19 ( V_19 ) ;
return V_100 ;
}
static int F_91 ( struct V_42 * V_116 , struct V_19 * V_19 )
{
struct V_42 * V_42 = V_19 -> V_24 ;
F_27 ( V_42 ) ;
return F_89 ( V_116 , V_19 ) ;
}
static struct V_19 * F_92 ( struct V_19 * V_129 ,
struct V_131 * V_123 )
{
struct V_19 * V_19 ;
V_19 = F_93 ( V_129 , V_123 ) ;
if ( ! V_19 ) {
V_19 = F_94 ( V_129 , V_123 ) ;
if ( ! V_19 )
return F_81 ( - V_124 ) ;
}
if ( V_19 -> V_24 == NULL ) {
F_95 ( V_19 , & V_132 ) ;
return V_19 ;
}
F_19 ( V_19 ) ;
return F_81 ( - V_133 ) ;
}
static void F_96 ( struct V_19 * V_129 ,
const struct V_134 * V_135 ,
int V_136 , int V_137 )
{
struct V_42 * V_116 = V_129 -> V_24 ;
struct V_19 * V_19 ;
struct V_131 V_123 ;
int V_138 ;
for ( V_138 = V_136 ; V_138 < V_137 ; V_138 ++ ) {
V_123 . V_123 = V_135 [ V_138 ] . V_123 ;
V_123 . V_33 = strlen ( V_135 [ V_138 ] . V_123 ) ;
V_123 . V_139 = F_97 ( V_123 . V_123 , V_123 . V_33 ) ;
V_19 = F_93 ( V_129 , & V_123 ) ;
if ( V_19 == NULL )
continue;
if ( V_19 -> V_24 == NULL )
goto V_10;
switch ( V_19 -> V_24 -> V_105 & V_110 ) {
default:
F_98 () ;
case V_125 :
F_89 ( V_116 , V_19 ) ;
break;
case V_111 :
F_83 ( V_116 , V_19 ) ;
}
V_10:
F_19 ( V_19 ) ;
}
}
static void F_99 ( struct V_19 * V_129 ,
const struct V_134 * V_135 ,
int V_136 , int V_137 )
{
struct V_42 * V_116 = V_129 -> V_24 ;
F_88 ( & V_116 -> V_45 , V_140 ) ;
F_96 ( V_129 , V_135 , V_136 , V_137 ) ;
F_30 ( & V_116 -> V_45 ) ;
}
static int F_100 ( struct V_19 * V_129 ,
const struct V_134 * V_135 ,
int V_136 , int V_137 ,
void * V_43 )
{
struct V_42 * V_116 = V_129 -> V_24 ;
struct V_19 * V_19 ;
int V_138 , V_8 ;
F_28 ( & V_116 -> V_45 ) ;
for ( V_138 = V_136 ; V_138 < V_137 ; V_138 ++ ) {
struct V_131 V_141 ;
V_141 . V_123 = V_135 [ V_138 ] . V_123 ;
V_141 . V_33 = strlen ( V_135 [ V_138 ] . V_123 ) ;
V_141 . V_139 = F_97 ( V_141 . V_123 , V_141 . V_33 ) ;
V_19 = F_92 ( V_129 , & V_141 ) ;
V_8 = F_101 ( V_19 ) ;
if ( F_102 ( V_19 ) )
goto V_142;
switch ( V_135 [ V_138 ] . V_103 & V_110 ) {
default:
F_98 () ;
case V_125 :
V_8 = F_69 ( V_116 , V_19 ,
V_135 [ V_138 ] . V_103 ,
V_135 [ V_138 ] . V_112 ,
V_43 ) ;
break;
case V_111 :
V_8 = F_71 ( V_116 , V_19 ,
V_135 [ V_138 ] . V_103 ,
NULL ,
V_43 ) ;
}
if ( V_8 != 0 )
goto V_142;
}
F_30 ( & V_116 -> V_45 ) ;
return 0 ;
V_142:
F_96 ( V_129 , V_135 , V_136 , V_137 ) ;
F_30 ( & V_116 -> V_45 ) ;
F_68 ( V_120 L_7 ,
__FILE__ , V_121 , V_129 -> V_122 . V_123 ) ;
return V_8 ;
}
static struct V_19 * F_103 ( struct V_19 * V_129 ,
struct V_131 * V_123 , T_6 V_103 , void * V_43 ,
int (* F_104)( struct V_19 * , void * ) , void * V_143 )
{
struct V_19 * V_19 ;
struct V_42 * V_116 = V_129 -> V_24 ;
int error ;
F_88 ( & V_116 -> V_45 , V_130 ) ;
V_19 = F_92 ( V_129 , V_123 ) ;
if ( F_102 ( V_19 ) )
goto V_60;
error = F_71 ( V_116 , V_19 , V_103 , NULL , V_43 ) ;
if ( error != 0 )
goto V_119;
if ( F_104 != NULL ) {
error = F_104 ( V_19 , V_143 ) ;
if ( error )
goto V_144;
}
V_60:
F_30 ( & V_116 -> V_45 ) ;
return V_19 ;
V_144:
F_83 ( V_116 , V_19 ) ;
V_119:
V_19 = F_81 ( error ) ;
goto V_60;
}
static int F_105 ( struct V_19 * V_19 ,
void (* F_106)( struct V_19 * ) )
{
struct V_19 * V_129 ;
struct V_42 * V_116 ;
int error ;
V_129 = F_87 ( V_19 ) ;
V_116 = V_129 -> V_24 ;
F_88 ( & V_116 -> V_45 , V_130 ) ;
if ( F_106 != NULL )
F_106 ( V_19 ) ;
error = F_83 ( V_116 , V_19 ) ;
F_30 ( & V_116 -> V_45 ) ;
F_19 ( V_129 ) ;
return error ;
}
struct V_19 * F_107 ( struct V_19 * V_129 , const char * V_123 ,
void * V_43 , struct V_16 * V_17 )
{
struct V_19 * V_19 ;
struct V_42 * V_116 = V_129 -> V_24 ;
T_6 V_145 = V_128 | V_146 | V_147 ;
struct V_131 V_141 ;
int V_8 ;
if ( V_17 -> V_21 -> V_72 == NULL )
V_145 &= ~ V_148 ;
if ( V_17 -> V_21 -> V_73 == NULL )
V_145 &= ~ V_149 ;
V_141 . V_123 = V_123 ;
V_141 . V_33 = strlen ( V_123 ) ;
V_141 . V_139 = F_97 ( V_141 . V_123 , V_141 . V_33 ) ,
F_88 ( & V_116 -> V_45 , V_130 ) ;
V_19 = F_92 ( V_129 , & V_141 ) ;
if ( F_102 ( V_19 ) )
goto V_60;
V_8 = F_82 ( V_116 , V_19 , V_145 , & V_150 ,
V_43 , V_17 ) ;
if ( V_8 )
goto V_119;
V_60:
F_30 ( & V_116 -> V_45 ) ;
return V_19 ;
V_119:
V_19 = F_81 ( V_8 ) ;
F_68 ( V_120 L_8 ,
__FILE__ , V_121 , V_129 -> V_122 . V_123 , V_123 ,
V_8 ) ;
goto V_60;
}
int
F_108 ( struct V_19 * V_19 )
{
struct V_19 * V_129 ;
struct V_42 * V_116 ;
int error = 0 ;
V_129 = F_87 ( V_19 ) ;
V_116 = V_129 -> V_24 ;
F_88 ( & V_116 -> V_45 , V_130 ) ;
error = F_91 ( V_116 , V_19 ) ;
F_30 ( & V_116 -> V_45 ) ;
F_19 ( V_129 ) ;
return error ;
}
static int F_109 ( struct V_19 * V_19 , void * V_43 )
{
return F_100 ( V_19 ,
V_151 , V_152 , V_153 ,
V_43 ) ;
}
static void F_110 ( struct V_19 * V_19 )
{
F_99 ( V_19 , V_151 , V_152 , V_153 ) ;
}
struct V_19 * F_111 ( struct V_19 * V_19 ,
struct V_131 * V_123 ,
struct V_90 * V_154 )
{
return F_103 ( V_19 , V_123 , V_148 | V_155 , NULL ,
F_109 , V_154 ) ;
}
int F_112 ( struct V_19 * V_19 )
{
return F_105 ( V_19 , F_110 ) ;
}
static int F_113 ( struct V_19 * V_19 , void * V_43 )
{
return F_100 ( V_19 ,
V_156 , 0 , 3 ,
V_43 ) ;
}
static void F_114 ( struct V_19 * V_19 )
{
F_99 ( V_19 , V_156 , 0 , 3 ) ;
}
struct V_19 * F_115 ( struct V_19 * V_129 , struct V_131 * V_123 ,
T_6 V_145 , struct V_157 * V_158 )
{
return F_103 ( V_129 , V_123 , V_145 , NULL ,
F_113 , V_158 ) ;
}
void F_116 ( struct V_19 * V_19 )
{
F_105 ( V_19 , F_114 ) ;
}
struct V_19 * F_117 ( const struct V_49 * V_50 ,
const unsigned char * V_159 )
{
struct V_131 V_116 = F_118 ( V_159 , strlen ( V_159 ) ) ;
V_116 . V_139 = F_97 ( V_116 . V_123 , V_116 . V_33 ) ;
return F_93 ( V_50 -> V_160 , & V_116 ) ;
}
void F_119 ( struct V_161 * V_161 )
{
struct V_162 * V_163 = F_120 ( V_161 , V_164 ) ;
F_121 ( & V_163 -> V_165 ) ;
}
struct V_49 * F_122 ( const struct V_161 * V_161 )
{
struct V_162 * V_163 = F_120 ( V_161 , V_164 ) ;
F_28 ( & V_163 -> V_165 ) ;
if ( V_163 -> V_166 )
return V_163 -> V_166 ;
F_30 ( & V_163 -> V_165 ) ;
return NULL ;
}
void F_123 ( const struct V_161 * V_161 )
{
struct V_162 * V_163 = F_120 ( V_161 , V_164 ) ;
F_124 ( V_163 -> V_166 == NULL ) ;
F_30 ( & V_163 -> V_165 ) ;
}
static int
F_125 ( struct V_49 * V_50 , void * V_30 , int V_167 )
{
struct V_42 * V_42 ;
struct V_19 * V_168 ;
struct V_161 * V_161 = V_30 ;
struct V_162 * V_163 = F_120 ( V_161 , V_164 ) ;
int V_8 ;
V_50 -> V_169 = V_170 ;
V_50 -> V_171 = V_172 ;
V_50 -> V_173 = V_174 ;
V_50 -> V_175 = & V_176 ;
V_50 -> V_177 = 1 ;
V_42 = F_60 ( V_50 , V_111 | V_148 | V_155 ) ;
V_50 -> V_160 = V_168 = F_126 ( V_42 ) ;
if ( ! V_168 )
return - V_124 ;
if ( F_100 ( V_168 , V_135 , V_178 , V_179 , NULL ) )
return - V_124 ;
F_127 ( L_9 ,
V_161 , F_128 ( V_161 ) ) ;
V_163 -> V_166 = V_50 ;
V_8 = F_129 ( & V_3 ,
V_180 ,
V_50 ) ;
if ( V_8 )
goto V_181;
V_50 -> V_182 = F_130 ( V_161 ) ;
return 0 ;
V_181:
F_129 ( & V_3 ,
V_183 ,
V_50 ) ;
V_163 -> V_166 = NULL ;
F_96 ( V_168 , V_135 , V_178 , V_179 ) ;
return V_8 ;
}
static struct V_19 *
F_131 ( struct V_184 * V_185 ,
int V_38 , const char * V_186 , void * V_30 )
{
return F_132 ( V_185 , V_38 , V_187 -> V_188 -> V_189 , F_125 ) ;
}
static void F_133 ( struct V_49 * V_50 )
{
struct V_161 * V_161 = V_50 -> V_182 ;
struct V_162 * V_163 = F_120 ( V_161 , V_164 ) ;
F_28 ( & V_163 -> V_165 ) ;
V_163 -> V_166 = NULL ;
F_30 ( & V_163 -> V_165 ) ;
F_134 ( V_161 ) ;
F_127 ( L_10 ,
V_161 , F_128 ( V_161 ) ) ;
F_129 ( & V_3 ,
V_183 ,
V_50 ) ;
F_135 ( V_50 ) ;
}
static void
F_136 ( void * V_190 )
{
struct V_51 * V_52 = (struct V_51 * ) V_190 ;
F_137 ( & V_52 -> V_55 ) ;
V_52 -> V_43 = NULL ;
V_52 -> V_17 = NULL ;
F_138 ( & V_52 -> V_4 ) ;
}
int F_139 ( void )
{
int V_8 ;
V_53 = F_140 ( L_11 ,
sizeof( struct V_51 ) ,
0 , ( V_191 | V_192 |
V_193 ) ,
F_136 ) ;
if ( ! V_53 )
return - V_124 ;
V_8 = F_141 () ;
if ( V_8 )
goto V_194;
V_8 = F_142 ( & V_195 ) ;
if ( V_8 )
goto V_196;
return 0 ;
V_196:
F_143 () ;
V_194:
F_144 ( V_53 ) ;
return V_8 ;
}
void F_145 ( void )
{
F_143 () ;
F_144 ( V_53 ) ;
F_146 ( & V_195 ) ;
}
