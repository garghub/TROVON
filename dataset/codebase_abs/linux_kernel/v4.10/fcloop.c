static int
F_1 ( struct V_1 * V_2 ,
const char * V_3 )
{
T_1 args [ V_4 ] ;
char * V_5 , * V_6 , * V_7 ;
int V_8 , V_9 = 0 ;
T_2 V_10 ;
V_5 = V_6 = F_2 ( V_3 , V_11 ) ;
if ( ! V_5 )
return - V_12 ;
while ( ( V_7 = F_3 ( & V_6 , L_1 ) ) != NULL ) {
if ( ! * V_7 )
continue;
V_8 = F_4 ( V_7 , V_13 , args ) ;
V_2 -> V_14 |= V_8 ;
switch ( V_8 ) {
case V_15 :
if ( F_5 ( args , & V_10 ) ) {
V_9 = - V_16 ;
goto V_17;
}
V_2 -> V_18 = V_10 ;
break;
case V_19 :
if ( F_5 ( args , & V_10 ) ) {
V_9 = - V_16 ;
goto V_17;
}
V_2 -> V_20 = V_10 ;
break;
case V_21 :
if ( F_6 ( args , & V_8 ) ) {
V_9 = - V_16 ;
goto V_17;
}
V_2 -> V_22 = V_8 ;
break;
case V_23 :
if ( F_7 ( args , & V_8 ) ) {
V_9 = - V_16 ;
goto V_17;
}
V_2 -> V_24 = V_8 ;
break;
case V_25 :
if ( F_5 ( args , & V_10 ) ) {
V_9 = - V_16 ;
goto V_17;
}
V_2 -> V_26 = V_10 ;
break;
case V_27 :
if ( F_5 ( args , & V_10 ) ) {
V_9 = - V_16 ;
goto V_17;
}
V_2 -> V_28 = V_10 ;
break;
default:
F_8 ( L_2 , V_7 ) ;
V_9 = - V_16 ;
goto V_17;
}
}
V_17:
F_9 ( V_5 ) ;
return V_9 ;
}
static int
F_10 ( struct V_29 * V_30 , T_2 * V_31 , T_2 * V_32 ,
const char * V_3 )
{
T_1 args [ V_4 ] ;
char * V_5 , * V_6 , * V_7 ;
int V_8 , V_9 = 0 ;
T_2 V_10 ;
* V_31 = - 1 ;
* V_32 = - 1 ;
V_5 = V_6 = F_2 ( V_3 , V_11 ) ;
if ( ! V_5 )
return - V_12 ;
while ( ( V_7 = F_3 ( & V_6 , L_1 ) ) != NULL ) {
if ( ! * V_7 )
continue;
V_8 = F_4 ( V_7 , V_13 , args ) ;
switch ( V_8 ) {
case V_15 :
if ( F_5 ( args , & V_10 ) ) {
V_9 = - V_16 ;
goto V_17;
}
* V_31 = V_10 ;
break;
case V_19 :
if ( F_5 ( args , & V_10 ) ) {
V_9 = - V_16 ;
goto V_17;
}
* V_32 = V_10 ;
break;
default:
F_8 ( L_2 , V_7 ) ;
V_9 = - V_16 ;
goto V_17;
}
}
V_17:
F_9 ( V_5 ) ;
if ( ! V_9 ) {
if ( * V_31 == - 1 )
return - V_16 ;
if ( * V_32 == - 1 )
return - V_16 ;
}
return V_9 ;
}
static inline struct V_33 *
F_11 ( struct V_34 * V_35 )
{
return F_12 ( V_35 , struct V_33 , V_36 ) ;
}
static inline struct V_37 *
F_13 ( struct V_38 * V_39 )
{
return F_12 ( V_39 , struct V_37 , V_40 ) ;
}
static int
F_14 ( struct V_41 * V_42 ,
unsigned int V_43 , T_3 V_44 ,
void * * V_45 )
{
* V_45 = V_42 ;
return 0 ;
}
static void
F_15 ( struct V_41 * V_42 ,
unsigned int V_46 , void * V_45 )
{
}
static void
F_16 ( struct V_47 * V_48 )
{
struct V_33 * V_49 =
F_12 ( V_48 , struct V_33 , V_48 ) ;
struct V_50 * V_51 = V_49 -> V_51 ;
struct V_52 * V_53 = V_49 -> V_53 ;
if ( V_51 -> V_54 )
V_53 -> V_55 ( V_53 , V_49 -> V_56 ) ;
}
static int
F_17 ( struct V_41 * V_42 ,
struct V_57 * V_54 ,
struct V_52 * V_53 )
{
struct V_33 * V_49 = V_53 -> V_58 ;
struct V_59 * V_60 = V_54 -> V_58 ;
int V_9 = 0 ;
V_49 -> V_53 = V_53 ;
F_18 ( & V_49 -> V_48 , F_16 ) ;
if ( ! V_60 -> V_61 ) {
V_49 -> V_56 = - V_62 ;
F_19 ( & V_49 -> V_48 ) ;
return V_9 ;
}
V_49 -> V_56 = 0 ;
V_49 -> V_51 = V_60 -> V_61 -> V_58 ;
V_9 = F_20 ( V_60 -> V_61 , & V_49 -> V_36 ,
V_53 -> V_63 , V_53 -> V_64 ) ;
return V_9 ;
}
static int
F_21 ( struct V_65 * V_51 ,
struct V_34 * V_35 )
{
struct V_33 * V_49 = F_11 ( V_35 ) ;
struct V_52 * V_53 = V_49 -> V_53 ;
memcpy ( V_53 -> V_66 , V_35 -> V_67 ,
( ( V_53 -> V_68 < V_35 -> V_68 ) ?
V_53 -> V_68 : V_35 -> V_68 ) ) ;
V_35 -> V_55 ( V_35 ) ;
F_19 ( & V_49 -> V_48 ) ;
return 0 ;
}
static void
F_22 ( struct V_47 * V_48 )
{
struct V_37 * V_69 =
F_12 ( V_48 , struct V_37 , V_48 ) ;
struct V_50 * V_51 = V_69 -> V_51 ;
struct V_70 * V_71 = V_69 -> V_71 ;
if ( V_51 -> V_54 ) {
V_71 -> V_56 = V_69 -> V_56 ;
V_71 -> V_55 ( V_71 ) ;
}
}
static int
F_23 ( struct V_41 * V_42 ,
struct V_57 * V_54 ,
void * V_72 ,
struct V_70 * V_71 )
{
struct V_37 * V_69 = V_71 -> V_58 ;
struct V_59 * V_60 = V_54 -> V_58 ;
int V_9 = 0 ;
F_18 ( & V_69 -> V_48 , F_22 ) ;
if ( ! V_60 -> V_61 ) {
V_69 -> V_56 = V_73 ;
F_19 ( & V_69 -> V_48 ) ;
return V_9 ;
}
V_69 -> V_71 = V_71 ;
V_69 -> V_51 = V_60 -> V_61 -> V_58 ;
V_9 = F_24 ( V_60 -> V_61 , & V_69 -> V_40 ,
V_71 -> V_74 , V_71 -> V_75 ) ;
return V_9 ;
}
static void
F_25 ( T_4 V_76 , struct V_77 * V_78 ,
struct V_77 * V_79 , T_5 V_80 , T_5 V_81 )
{
void * V_82 , * V_83 ;
T_5 V_84 , V_85 , V_86 ;
V_83 = F_26 ( V_79 ) ;
V_85 = V_79 -> V_81 ;
for ( ; V_80 ; ) {
V_86 = F_27 ( T_5 , V_80 , V_85 ) ;
V_80 -= V_86 ;
V_85 -= V_86 ;
if ( ! V_85 ) {
V_79 = F_28 ( V_79 ) ;
V_83 = F_26 ( V_79 ) ;
V_85 = V_79 -> V_81 ;
} else
V_83 += V_86 ;
}
V_82 = F_26 ( V_78 ) ;
V_84 = V_78 -> V_81 ;
for ( ; V_81 ; ) {
V_86 = F_27 ( T_5 , V_85 , V_84 ) ;
V_86 = F_27 ( T_5 , V_86 , V_81 ) ;
if ( V_76 == V_87 )
memcpy ( V_82 , V_83 , V_86 ) ;
else
memcpy ( V_83 , V_82 , V_86 ) ;
V_81 -= V_86 ;
V_85 -= V_86 ;
if ( ( ! V_85 ) && ( V_81 ) ) {
V_79 = F_28 ( V_79 ) ;
V_83 = F_26 ( V_79 ) ;
V_85 = V_79 -> V_81 ;
} else
V_83 += V_86 ;
V_84 -= V_86 ;
if ( ( ! V_84 ) && ( V_81 ) ) {
V_78 = F_28 ( V_78 ) ;
V_82 = F_26 ( V_78 ) ;
V_84 = V_78 -> V_81 ;
} else
V_82 += V_86 ;
}
}
static int
F_29 ( struct V_65 * V_88 ,
struct V_38 * V_39 )
{
struct V_37 * V_69 = F_13 ( V_39 ) ;
struct V_70 * V_71 = V_69 -> V_71 ;
T_5 V_68 = 0 , V_89 = 0 ;
int V_90 = 0 ;
T_4 V_76 = V_39 -> V_76 ;
switch ( V_76 ) {
case V_87 :
V_89 = V_39 -> V_91 ;
F_25 ( V_76 , V_39 -> V_92 , V_71 -> V_93 ,
V_39 -> V_80 , V_89 ) ;
V_71 -> V_94 += V_89 ;
break;
case V_95 :
case V_96 :
V_89 = V_39 -> V_91 ;
F_25 ( V_76 , V_39 -> V_92 , V_71 -> V_93 ,
V_39 -> V_80 , V_89 ) ;
V_71 -> V_94 += V_89 ;
if ( V_76 == V_95 )
break;
case V_97 :
V_68 = ( ( V_71 -> V_68 < V_39 -> V_68 ) ?
V_71 -> V_68 : V_39 -> V_68 ) ;
memcpy ( V_71 -> V_66 , V_39 -> V_66 , V_68 ) ;
if ( V_68 < V_39 -> V_68 )
V_90 = - V_98 ;
V_71 -> V_99 = V_68 ;
V_71 -> V_56 = 0 ;
V_69 -> V_56 = 0 ;
break;
case V_100 :
V_69 -> V_56 = V_101 ;
break;
default:
V_90 = - V_16 ;
break;
}
V_39 -> V_94 = V_89 ;
V_39 -> V_102 = V_90 ;
V_39 -> V_55 ( V_39 ) ;
if ( ( ! V_90 ) && ( V_76 == V_97 ||
V_76 == V_96 ||
V_76 == V_100 ) )
F_19 ( & V_69 -> V_48 ) ;
return 0 ;
}
static void
F_30 ( struct V_41 * V_42 ,
struct V_57 * V_54 ,
struct V_52 * V_53 )
{
}
static void
F_31 ( struct V_41 * V_42 ,
struct V_57 * V_54 ,
void * V_72 ,
struct V_70 * V_71 )
{
}
static void
F_32 ( struct V_41 * V_42 )
{
struct V_103 * V_104 = V_42 -> V_58 ;
F_33 ( & V_104 -> V_105 ) ;
}
static void
F_34 ( struct V_57 * V_54 )
{
struct V_59 * V_60 = V_54 -> V_58 ;
F_33 ( & V_60 -> V_106 -> V_107 ) ;
}
static void
F_35 ( struct V_65 * V_61 )
{
struct V_50 * V_51 = V_61 -> V_58 ;
F_33 ( & V_51 -> V_106 -> V_108 ) ;
}
static T_6
F_36 ( struct V_29 * V_30 , struct V_109 * V_110 ,
const char * V_3 , T_7 V_111 )
{
struct V_112 V_113 ;
struct V_1 * V_2 ;
struct V_41 * V_42 ;
struct V_103 * V_104 ;
int V_9 ;
V_2 = F_37 ( sizeof( * V_2 ) , V_11 ) ;
if ( ! V_2 )
return - V_12 ;
V_9 = F_1 ( V_2 , V_3 ) ;
if ( V_9 )
goto V_114;
if ( ( V_2 -> V_14 & V_115 ) != V_115 ) {
V_9 = - V_16 ;
goto V_114;
}
V_113 . V_116 = V_2 -> V_18 ;
V_113 . V_117 = V_2 -> V_20 ;
V_113 . V_118 = V_2 -> V_22 ;
V_113 . V_119 = V_2 -> V_24 ;
V_9 = F_38 ( & V_113 , & V_120 , NULL , & V_42 ) ;
if ( ! V_9 ) {
unsigned long V_121 ;
V_104 = V_42 -> V_58 ;
V_104 -> V_42 = V_42 ;
F_39 ( & V_104 -> V_122 ) ;
F_40 ( & V_123 , V_121 ) ;
F_41 ( & V_104 -> V_122 , & V_124 ) ;
F_42 ( & V_123 , V_121 ) ;
V_9 = V_111 ;
}
V_114:
F_9 ( V_2 ) ;
return V_9 ? V_9 : V_111 ;
}
static void
F_43 ( struct V_103 * V_104 )
{
F_44 ( & V_104 -> V_122 ) ;
}
static int
F_45 ( struct V_103 * V_104 )
{
int V_9 ;
F_46 ( & V_104 -> V_105 ) ;
V_9 = F_47 ( V_104 -> V_42 ) ;
F_48 ( & V_104 -> V_105 ) ;
return V_9 ;
}
static T_6
F_49 ( struct V_29 * V_30 , struct V_109 * V_110 ,
const char * V_3 , T_7 V_111 )
{
struct V_103 * V_125 , * V_104 = NULL ;
T_2 V_126 , V_127 ;
unsigned long V_121 ;
int V_9 ;
V_9 = F_10 ( V_30 , & V_126 , & V_127 , V_3 ) ;
if ( V_9 )
return V_9 ;
F_40 ( & V_123 , V_121 ) ;
F_50 (tlport, &fcloop_lports, lport_list) {
if ( V_125 -> V_42 -> V_116 == V_126 &&
V_125 -> V_42 -> V_117 == V_127 ) {
V_104 = V_125 ;
F_43 ( V_104 ) ;
break;
}
}
F_42 ( & V_123 , V_121 ) ;
if ( ! V_104 )
return - V_128 ;
V_9 = F_45 ( V_104 ) ;
return V_9 ? V_9 : V_111 ;
}
static void
F_51 ( struct V_129 * V_130 )
{
struct V_131 * V_106 =
F_12 ( V_130 , struct V_131 , V_130 ) ;
unsigned long V_121 ;
F_40 ( & V_123 , V_121 ) ;
F_44 ( & V_106 -> V_132 ) ;
F_42 ( & V_123 , V_121 ) ;
F_9 ( V_106 ) ;
}
static void
F_52 ( struct V_131 * V_106 )
{
F_53 ( & V_106 -> V_130 , F_51 ) ;
}
static int
F_54 ( struct V_131 * V_106 )
{
return F_55 ( & V_106 -> V_130 ) ;
}
static struct V_131 *
F_56 ( const char * V_3 , T_7 V_111 , bool V_54 )
{
struct V_131 * V_133 , * V_106 = NULL ;
struct V_103 * V_134 , * V_104 = NULL ;
struct V_1 * V_2 ;
unsigned long V_121 ;
T_5 V_135 = ( V_54 ) ? V_136 : V_137 ;
int V_9 ;
V_2 = F_37 ( sizeof( * V_2 ) , V_11 ) ;
if ( ! V_2 )
return NULL ;
V_9 = F_1 ( V_2 , V_3 ) ;
if ( V_9 )
goto V_114;
if ( ( V_2 -> V_14 & V_135 ) != V_135 ) {
V_9 = - V_16 ;
goto V_114;
}
V_133 = F_37 ( sizeof( * V_133 ) , V_11 ) ;
if ( ! V_133 )
goto V_114;
F_39 ( & V_133 -> V_132 ) ;
V_133 -> V_116 = V_2 -> V_18 ;
V_133 -> V_117 = V_2 -> V_20 ;
if ( V_2 -> V_14 & V_21 )
V_133 -> V_118 = V_2 -> V_22 ;
if ( V_2 -> V_14 & V_23 )
V_133 -> V_119 = V_2 -> V_24 ;
F_57 ( & V_133 -> V_130 ) ;
F_40 ( & V_123 , V_121 ) ;
F_50 (tmplport, &fcloop_lports, lport_list) {
if ( V_134 -> V_42 -> V_116 == V_2 -> V_18 &&
V_134 -> V_42 -> V_117 == V_2 -> V_20 )
goto V_138;
if ( V_134 -> V_42 -> V_116 == V_2 -> V_26 &&
V_134 -> V_42 -> V_117 == V_2 -> V_28 )
V_104 = V_134 ;
}
if ( V_54 ) {
if ( ! V_104 )
goto V_138;
V_133 -> V_104 = V_104 ;
}
F_50 (nport, &fcloop_nports, nport_list) {
if ( V_106 -> V_116 == V_2 -> V_18 &&
V_106 -> V_117 == V_2 -> V_20 ) {
if ( ( V_54 && V_106 -> V_60 ) ||
( ! V_54 && V_106 -> V_51 ) ) {
V_106 = NULL ;
goto V_138;
}
F_54 ( V_106 ) ;
F_42 ( & V_123 , V_121 ) ;
if ( V_54 )
V_106 -> V_104 = V_104 ;
if ( V_2 -> V_14 & V_21 )
V_106 -> V_118 = V_2 -> V_22 ;
if ( V_2 -> V_14 & V_23 )
V_106 -> V_119 = V_2 -> V_24 ;
goto V_139;
}
}
F_41 ( & V_133 -> V_132 , & V_140 ) ;
F_42 ( & V_123 , V_121 ) ;
F_9 ( V_2 ) ;
return V_133 ;
V_138:
F_42 ( & V_123 , V_121 ) ;
V_139:
F_9 ( V_133 ) ;
V_114:
F_9 ( V_2 ) ;
return V_106 ;
}
static T_6
F_58 ( struct V_29 * V_30 , struct V_109 * V_110 ,
const char * V_3 , T_7 V_111 )
{
struct V_57 * V_54 ;
struct V_131 * V_106 ;
struct V_59 * V_60 ;
struct V_112 V_113 ;
int V_9 ;
V_106 = F_56 ( V_3 , V_111 , true ) ;
if ( ! V_106 )
return - V_141 ;
V_113 . V_116 = V_106 -> V_116 ;
V_113 . V_117 = V_106 -> V_117 ;
V_113 . V_118 = V_106 -> V_118 ;
V_113 . V_119 = V_106 -> V_119 ;
V_9 = F_59 ( V_106 -> V_104 -> V_42 ,
& V_113 , & V_54 ) ;
if ( V_9 || ! V_54 ) {
F_52 ( V_106 ) ;
return V_9 ;
}
V_60 = V_54 -> V_58 ;
V_60 -> V_54 = V_54 ;
V_60 -> V_61 = ( V_106 -> V_51 ) ? V_106 -> V_51 -> V_61 : NULL ;
if ( V_106 -> V_51 ) {
V_106 -> V_51 -> V_54 = V_54 ;
V_106 -> V_51 -> V_104 = V_106 -> V_104 ;
}
V_60 -> V_106 = V_106 ;
V_60 -> V_104 = V_106 -> V_104 ;
V_106 -> V_60 = V_60 ;
return V_111 ;
}
static struct V_59 *
F_60 ( struct V_131 * V_106 )
{
struct V_59 * V_60 = V_106 -> V_60 ;
if ( V_60 && V_106 -> V_51 )
V_106 -> V_51 -> V_54 = NULL ;
V_106 -> V_60 = NULL ;
return V_60 ;
}
static int
F_61 ( struct V_131 * V_106 , struct V_59 * V_60 )
{
int V_9 ;
if ( ! V_60 )
return - V_142 ;
F_46 ( & V_106 -> V_107 ) ;
V_9 = F_62 ( V_60 -> V_54 ) ;
if ( V_9 )
return V_9 ;
F_48 ( & V_106 -> V_107 ) ;
F_52 ( V_106 ) ;
return V_9 ;
}
static T_6
F_63 ( struct V_29 * V_30 , struct V_109 * V_110 ,
const char * V_3 , T_7 V_111 )
{
struct V_131 * V_106 = NULL , * V_143 ;
static struct V_59 * V_60 ;
T_2 V_126 , V_127 ;
unsigned long V_121 ;
int V_9 ;
V_9 = F_10 ( V_30 , & V_126 , & V_127 , V_3 ) ;
if ( V_9 )
return V_9 ;
F_40 ( & V_123 , V_121 ) ;
F_50 (tmpport, &fcloop_nports, nport_list) {
if ( V_143 -> V_116 == V_126 &&
V_143 -> V_117 == V_127 && V_143 -> V_60 ) {
V_106 = V_143 ;
V_60 = F_60 ( V_106 ) ;
break;
}
}
F_42 ( & V_123 , V_121 ) ;
if ( ! V_106 )
return - V_128 ;
V_9 = F_61 ( V_106 , V_60 ) ;
return V_9 ? V_9 : V_111 ;
}
static T_6
F_64 ( struct V_29 * V_30 , struct V_109 * V_110 ,
const char * V_3 , T_7 V_111 )
{
struct V_65 * V_61 ;
struct V_131 * V_106 ;
struct V_50 * V_51 ;
struct V_144 V_145 ;
int V_9 ;
V_106 = F_56 ( V_3 , V_111 , false ) ;
if ( ! V_106 )
return - V_141 ;
V_145 . V_116 = V_106 -> V_116 ;
V_145 . V_117 = V_106 -> V_117 ;
V_145 . V_119 = V_106 -> V_119 ;
V_9 = F_65 ( & V_145 , & V_146 , NULL ,
& V_61 ) ;
if ( V_9 ) {
F_52 ( V_106 ) ;
return V_9 ;
}
V_51 = V_61 -> V_58 ;
V_51 -> V_61 = V_61 ;
V_51 -> V_54 = ( V_106 -> V_60 ) ? V_106 -> V_60 -> V_54 : NULL ;
if ( V_106 -> V_60 )
V_106 -> V_60 -> V_61 = V_61 ;
V_51 -> V_106 = V_106 ;
V_51 -> V_104 = V_106 -> V_104 ;
V_106 -> V_51 = V_51 ;
return V_111 ;
}
static struct V_50 *
F_66 ( struct V_131 * V_106 )
{
struct V_50 * V_51 = V_106 -> V_51 ;
if ( V_51 && V_106 -> V_60 )
V_106 -> V_60 -> V_61 = NULL ;
V_106 -> V_51 = NULL ;
return V_51 ;
}
static int
F_67 ( struct V_131 * V_106 , struct V_50 * V_51 )
{
int V_9 ;
if ( ! V_51 )
return - V_142 ;
F_46 ( & V_106 -> V_108 ) ;
V_9 = F_68 ( V_51 -> V_61 ) ;
if ( V_9 )
return V_9 ;
F_48 ( & V_106 -> V_108 ) ;
F_52 ( V_106 ) ;
return V_9 ;
}
static T_6
F_69 ( struct V_29 * V_30 , struct V_109 * V_110 ,
const char * V_3 , T_7 V_111 )
{
struct V_131 * V_106 = NULL , * V_143 ;
struct V_50 * V_51 ;
T_2 V_126 , V_127 ;
unsigned long V_121 ;
int V_9 ;
V_9 = F_10 ( V_30 , & V_126 , & V_127 , V_3 ) ;
if ( V_9 )
return V_9 ;
F_40 ( & V_123 , V_121 ) ;
F_50 (tmpport, &fcloop_nports, nport_list) {
if ( V_143 -> V_116 == V_126 &&
V_143 -> V_117 == V_127 && V_143 -> V_51 ) {
V_106 = V_143 ;
V_51 = F_66 ( V_106 ) ;
break;
}
}
F_42 ( & V_123 , V_121 ) ;
if ( ! V_106 )
return - V_128 ;
V_9 = F_67 ( V_106 , V_51 ) ;
return V_9 ? V_9 : V_111 ;
}
static int T_8 F_70 ( void )
{
int V_9 ;
V_147 = F_71 ( V_148 , L_3 ) ;
if ( F_72 ( V_147 ) ) {
F_73 ( L_4 ) ;
V_9 = F_74 ( V_147 ) ;
return V_9 ;
}
V_149 = F_75 (
V_147 , NULL , F_76 ( 0 , 0 ) , NULL ,
V_150 , L_5 ) ;
if ( F_72 ( V_149 ) ) {
F_73 ( L_6 ) ;
V_9 = F_74 ( V_149 ) ;
goto V_151;
}
F_77 ( V_149 ) ;
return 0 ;
V_151:
F_78 ( V_147 ) ;
return V_9 ;
}
static void T_9 F_79 ( void )
{
struct V_103 * V_104 ;
struct V_131 * V_106 ;
struct V_50 * V_51 ;
struct V_59 * V_60 ;
unsigned long V_121 ;
int V_9 ;
F_40 ( & V_123 , V_121 ) ;
for (; ; ) {
V_106 = F_80 ( & V_140 ,
F_81 ( * V_106 ) , V_132 ) ;
if ( ! V_106 )
break;
V_51 = F_66 ( V_106 ) ;
V_60 = F_60 ( V_106 ) ;
F_42 ( & V_123 , V_121 ) ;
V_9 = F_67 ( V_106 , V_51 ) ;
if ( V_9 )
F_8 ( L_7 , V_152 ) ;
V_9 = F_61 ( V_106 , V_60 ) ;
if ( V_9 )
F_8 ( L_8 , V_152 ) ;
F_40 ( & V_123 , V_121 ) ;
}
for (; ; ) {
V_104 = F_80 ( & V_124 ,
F_81 ( * V_104 ) , V_122 ) ;
if ( ! V_104 )
break;
F_43 ( V_104 ) ;
F_42 ( & V_123 , V_121 ) ;
V_9 = F_45 ( V_104 ) ;
if ( V_9 )
F_8 ( L_9 , V_152 ) ;
F_40 ( & V_123 , V_121 ) ;
}
F_42 ( & V_123 , V_121 ) ;
F_82 ( V_149 ) ;
F_83 ( V_147 , F_76 ( 0 , 0 ) ) ;
F_78 ( V_147 ) ;
}
