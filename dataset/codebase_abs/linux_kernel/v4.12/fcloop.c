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
struct V_69 * V_70 =
F_12 ( V_48 , struct V_69 , V_71 ) ;
V_70 -> V_72 -> V_55 ( V_70 -> V_72 ) ;
}
static void
F_23 ( struct V_47 * V_48 )
{
struct V_37 * V_73 =
F_12 ( V_48 , struct V_37 , V_48 ) ;
struct V_50 * V_51 = V_73 -> V_51 ;
struct V_74 * V_72 ;
F_24 ( & V_73 -> V_75 ) ;
V_72 = V_73 -> V_72 ;
F_25 ( & V_73 -> V_75 ) ;
if ( V_51 -> V_54 && V_72 ) {
V_72 -> V_56 = V_73 -> V_56 ;
V_72 -> V_55 ( V_72 ) ;
}
F_9 ( V_73 ) ;
}
static int
F_26 ( struct V_41 * V_42 ,
struct V_57 * V_54 ,
void * V_76 ,
struct V_74 * V_72 )
{
struct V_59 * V_60 = V_54 -> V_58 ;
struct V_69 * V_70 = V_72 -> V_58 ;
struct V_37 * V_73 ;
int V_9 = 0 ;
if ( ! V_60 -> V_61 )
return - V_62 ;
V_73 = F_27 ( sizeof( * V_73 ) , V_11 ) ;
if ( ! V_73 )
return - V_12 ;
V_70 -> V_72 = V_72 ;
V_70 -> V_73 = V_73 ;
F_18 ( & V_70 -> V_71 , F_22 ) ;
V_73 -> V_72 = V_72 ;
V_73 -> V_51 = V_60 -> V_61 -> V_58 ;
F_28 ( & V_73 -> V_75 ) ;
F_18 ( & V_73 -> V_48 , F_23 ) ;
V_9 = F_29 ( V_60 -> V_61 , & V_73 -> V_40 ,
V_72 -> V_77 , V_72 -> V_78 ) ;
return V_9 ;
}
static void
F_30 ( T_4 V_79 , struct V_80 * V_81 ,
struct V_80 * V_82 , T_5 V_83 , T_5 V_84 )
{
void * V_85 , * V_86 ;
T_5 V_87 , V_88 , V_89 ;
V_86 = F_31 ( V_82 ) ;
V_88 = V_82 -> V_84 ;
for ( ; V_83 ; ) {
V_89 = F_32 ( T_5 , V_83 , V_88 ) ;
V_83 -= V_89 ;
V_88 -= V_89 ;
if ( ! V_88 ) {
V_82 = F_33 ( V_82 ) ;
V_86 = F_31 ( V_82 ) ;
V_88 = V_82 -> V_84 ;
} else
V_86 += V_89 ;
}
V_85 = F_31 ( V_81 ) ;
V_87 = V_81 -> V_84 ;
for ( ; V_84 ; ) {
V_89 = F_32 ( T_5 , V_88 , V_87 ) ;
V_89 = F_32 ( T_5 , V_89 , V_84 ) ;
if ( V_79 == V_90 )
memcpy ( V_85 , V_86 , V_89 ) ;
else
memcpy ( V_86 , V_85 , V_89 ) ;
V_84 -= V_89 ;
V_88 -= V_89 ;
if ( ( ! V_88 ) && ( V_84 ) ) {
V_82 = F_33 ( V_82 ) ;
V_86 = F_31 ( V_82 ) ;
V_88 = V_82 -> V_84 ;
} else
V_86 += V_89 ;
V_87 -= V_89 ;
if ( ( ! V_87 ) && ( V_84 ) ) {
V_81 = F_33 ( V_81 ) ;
V_85 = F_31 ( V_81 ) ;
V_87 = V_81 -> V_84 ;
} else
V_85 += V_89 ;
}
}
static int
F_34 ( struct V_65 * V_91 ,
struct V_38 * V_39 )
{
struct V_37 * V_73 = F_13 ( V_39 ) ;
struct V_74 * V_72 ;
T_5 V_68 = 0 , V_92 = 0 ;
int V_93 = 0 , V_94 , V_95 ;
T_4 V_79 = V_39 -> V_79 ;
F_24 ( & V_73 -> V_75 ) ;
V_72 = V_73 -> V_72 ;
V_94 = V_73 -> V_94 ;
V_95 = V_73 -> V_95 ;
V_73 -> V_94 = true ;
F_25 ( & V_73 -> V_75 ) ;
if ( F_35 ( V_94 ) )
return - V_96 ;
if ( F_35 ( V_95 ) ) {
F_24 ( & V_73 -> V_75 ) ;
V_73 -> V_94 = false ;
F_25 ( & V_73 -> V_75 ) ;
V_39 -> V_97 = 0 ;
V_39 -> V_98 = - V_99 ;
V_39 -> V_55 ( V_39 ) ;
return 0 ;
}
switch ( V_79 ) {
case V_90 :
V_92 = V_39 -> V_100 ;
if ( V_72 ) {
F_30 ( V_79 , V_39 -> V_101 ,
V_72 -> V_102 , V_39 -> V_83 ,
V_92 ) ;
V_72 -> V_97 += V_92 ;
}
break;
case V_103 :
case V_104 :
V_92 = V_39 -> V_100 ;
if ( V_72 ) {
F_30 ( V_79 , V_39 -> V_101 ,
V_72 -> V_102 , V_39 -> V_83 ,
V_92 ) ;
V_72 -> V_97 += V_92 ;
}
if ( V_79 == V_103 )
break;
case V_105 :
if ( V_72 ) {
V_68 = ( ( V_72 -> V_68 < V_39 -> V_68 ) ?
V_72 -> V_68 : V_39 -> V_68 ) ;
memcpy ( V_72 -> V_66 , V_39 -> V_66 , V_68 ) ;
if ( V_68 < V_39 -> V_68 )
V_93 = - V_106 ;
V_72 -> V_107 = V_68 ;
V_72 -> V_56 = 0 ;
}
V_73 -> V_56 = 0 ;
break;
default:
V_93 = - V_16 ;
break;
}
F_24 ( & V_73 -> V_75 ) ;
V_73 -> V_94 = false ;
F_25 ( & V_73 -> V_75 ) ;
V_39 -> V_97 = V_92 ;
V_39 -> V_98 = V_93 ;
V_39 -> V_55 ( V_39 ) ;
return 0 ;
}
static void
F_36 ( struct V_65 * V_91 ,
struct V_38 * V_39 )
{
struct V_37 * V_73 = F_13 ( V_39 ) ;
int V_94 ;
F_24 ( & V_73 -> V_75 ) ;
V_94 = V_73 -> V_94 ;
V_73 -> V_95 = true ;
F_25 ( & V_73 -> V_75 ) ;
V_73 -> V_56 = V_108 ;
}
static void
F_37 ( struct V_65 * V_91 ,
struct V_38 * V_39 )
{
struct V_37 * V_73 = F_13 ( V_39 ) ;
F_19 ( & V_73 -> V_48 ) ;
}
static void
F_38 ( struct V_41 * V_42 ,
struct V_57 * V_54 ,
struct V_52 * V_53 )
{
}
static void
F_39 ( struct V_41 * V_42 ,
struct V_57 * V_54 ,
void * V_76 ,
struct V_74 * V_72 )
{
struct V_59 * V_60 = V_54 -> V_58 ;
struct V_69 * V_70 = V_72 -> V_58 ;
struct V_37 * V_73 = V_70 -> V_73 ;
if ( ! V_73 )
return;
if ( V_60 -> V_61 )
F_40 ( V_60 -> V_61 ,
& V_73 -> V_40 ) ;
F_24 ( & V_73 -> V_75 ) ;
V_70 -> V_73 = NULL ;
V_73 -> V_72 = NULL ;
F_25 ( & V_73 -> V_75 ) ;
V_72 -> V_56 = - V_99 ;
F_19 ( & V_70 -> V_71 ) ;
}
static void
F_41 ( struct V_41 * V_42 )
{
struct V_109 * V_110 = V_42 -> V_58 ;
F_42 ( & V_110 -> V_111 ) ;
}
static void
F_43 ( struct V_57 * V_54 )
{
struct V_59 * V_60 = V_54 -> V_58 ;
F_42 ( & V_60 -> V_112 -> V_113 ) ;
}
static void
F_44 ( struct V_65 * V_61 )
{
struct V_50 * V_51 = V_61 -> V_58 ;
F_42 ( & V_51 -> V_112 -> V_114 ) ;
}
static T_6
F_45 ( struct V_29 * V_30 , struct V_115 * V_116 ,
const char * V_3 , T_7 V_117 )
{
struct V_118 V_119 ;
struct V_1 * V_2 ;
struct V_41 * V_42 ;
struct V_109 * V_110 ;
int V_9 ;
V_2 = F_27 ( sizeof( * V_2 ) , V_11 ) ;
if ( ! V_2 )
return - V_12 ;
V_9 = F_1 ( V_2 , V_3 ) ;
if ( V_9 )
goto V_120;
if ( ( V_2 -> V_14 & V_121 ) != V_121 ) {
V_9 = - V_16 ;
goto V_120;
}
V_119 . V_122 = V_2 -> V_18 ;
V_119 . V_123 = V_2 -> V_20 ;
V_119 . V_124 = V_2 -> V_22 ;
V_119 . V_125 = V_2 -> V_24 ;
V_9 = F_46 ( & V_119 , & V_126 , NULL , & V_42 ) ;
if ( ! V_9 ) {
unsigned long V_127 ;
V_110 = V_42 -> V_58 ;
V_110 -> V_42 = V_42 ;
F_47 ( & V_110 -> V_128 ) ;
F_48 ( & V_129 , V_127 ) ;
F_49 ( & V_110 -> V_128 , & V_130 ) ;
F_50 ( & V_129 , V_127 ) ;
V_9 = V_117 ;
}
V_120:
F_9 ( V_2 ) ;
return V_9 ? V_9 : V_117 ;
}
static void
F_51 ( struct V_109 * V_110 )
{
F_52 ( & V_110 -> V_128 ) ;
}
static int
F_53 ( struct V_109 * V_110 )
{
int V_9 ;
F_54 ( & V_110 -> V_111 ) ;
V_9 = F_55 ( V_110 -> V_42 ) ;
F_56 ( & V_110 -> V_111 ) ;
return V_9 ;
}
static T_6
F_57 ( struct V_29 * V_30 , struct V_115 * V_116 ,
const char * V_3 , T_7 V_117 )
{
struct V_109 * V_131 , * V_110 = NULL ;
T_2 V_132 , V_133 ;
unsigned long V_127 ;
int V_9 ;
V_9 = F_10 ( V_30 , & V_132 , & V_133 , V_3 ) ;
if ( V_9 )
return V_9 ;
F_48 ( & V_129 , V_127 ) ;
F_58 (tlport, &fcloop_lports, lport_list) {
if ( V_131 -> V_42 -> V_122 == V_132 &&
V_131 -> V_42 -> V_123 == V_133 ) {
V_110 = V_131 ;
F_51 ( V_110 ) ;
break;
}
}
F_50 ( & V_129 , V_127 ) ;
if ( ! V_110 )
return - V_134 ;
V_9 = F_53 ( V_110 ) ;
return V_9 ? V_9 : V_117 ;
}
static void
F_59 ( struct V_135 * V_136 )
{
struct V_137 * V_112 =
F_12 ( V_136 , struct V_137 , V_136 ) ;
unsigned long V_127 ;
F_48 ( & V_129 , V_127 ) ;
F_52 ( & V_112 -> V_138 ) ;
F_50 ( & V_129 , V_127 ) ;
F_9 ( V_112 ) ;
}
static void
F_60 ( struct V_137 * V_112 )
{
F_61 ( & V_112 -> V_136 , F_59 ) ;
}
static int
F_62 ( struct V_137 * V_112 )
{
return F_63 ( & V_112 -> V_136 ) ;
}
static struct V_137 *
F_64 ( const char * V_3 , T_7 V_117 , bool V_54 )
{
struct V_137 * V_139 , * V_112 = NULL ;
struct V_109 * V_140 , * V_110 = NULL ;
struct V_1 * V_2 ;
unsigned long V_127 ;
T_5 V_141 = ( V_54 ) ? V_142 : V_143 ;
int V_9 ;
V_2 = F_27 ( sizeof( * V_2 ) , V_11 ) ;
if ( ! V_2 )
return NULL ;
V_9 = F_1 ( V_2 , V_3 ) ;
if ( V_9 )
goto V_120;
if ( ( V_2 -> V_14 & V_141 ) != V_141 ) {
V_9 = - V_16 ;
goto V_120;
}
V_139 = F_27 ( sizeof( * V_139 ) , V_11 ) ;
if ( ! V_139 )
goto V_120;
F_47 ( & V_139 -> V_138 ) ;
V_139 -> V_122 = V_2 -> V_18 ;
V_139 -> V_123 = V_2 -> V_20 ;
if ( V_2 -> V_14 & V_21 )
V_139 -> V_124 = V_2 -> V_22 ;
if ( V_2 -> V_14 & V_23 )
V_139 -> V_125 = V_2 -> V_24 ;
F_65 ( & V_139 -> V_136 ) ;
F_48 ( & V_129 , V_127 ) ;
F_58 (tmplport, &fcloop_lports, lport_list) {
if ( V_140 -> V_42 -> V_122 == V_2 -> V_18 &&
V_140 -> V_42 -> V_123 == V_2 -> V_20 )
goto V_144;
if ( V_140 -> V_42 -> V_122 == V_2 -> V_26 &&
V_140 -> V_42 -> V_123 == V_2 -> V_28 )
V_110 = V_140 ;
}
if ( V_54 ) {
if ( ! V_110 )
goto V_144;
V_139 -> V_110 = V_110 ;
}
F_58 (nport, &fcloop_nports, nport_list) {
if ( V_112 -> V_122 == V_2 -> V_18 &&
V_112 -> V_123 == V_2 -> V_20 ) {
if ( ( V_54 && V_112 -> V_60 ) ||
( ! V_54 && V_112 -> V_51 ) ) {
V_112 = NULL ;
goto V_144;
}
F_62 ( V_112 ) ;
F_50 ( & V_129 , V_127 ) ;
if ( V_54 )
V_112 -> V_110 = V_110 ;
if ( V_2 -> V_14 & V_21 )
V_112 -> V_124 = V_2 -> V_22 ;
if ( V_2 -> V_14 & V_23 )
V_112 -> V_125 = V_2 -> V_24 ;
goto V_145;
}
}
F_49 ( & V_139 -> V_138 , & V_146 ) ;
F_50 ( & V_129 , V_127 ) ;
F_9 ( V_2 ) ;
return V_139 ;
V_144:
F_50 ( & V_129 , V_127 ) ;
V_145:
F_9 ( V_139 ) ;
V_120:
F_9 ( V_2 ) ;
return V_112 ;
}
static T_6
F_66 ( struct V_29 * V_30 , struct V_115 * V_116 ,
const char * V_3 , T_7 V_117 )
{
struct V_57 * V_54 ;
struct V_137 * V_112 ;
struct V_59 * V_60 ;
struct V_118 V_119 ;
int V_9 ;
V_112 = F_64 ( V_3 , V_117 , true ) ;
if ( ! V_112 )
return - V_147 ;
V_119 . V_122 = V_112 -> V_122 ;
V_119 . V_123 = V_112 -> V_123 ;
V_119 . V_124 = V_112 -> V_124 ;
V_119 . V_125 = V_112 -> V_125 ;
V_9 = F_67 ( V_112 -> V_110 -> V_42 ,
& V_119 , & V_54 ) ;
if ( V_9 || ! V_54 ) {
F_60 ( V_112 ) ;
return V_9 ;
}
V_60 = V_54 -> V_58 ;
V_60 -> V_54 = V_54 ;
V_60 -> V_61 = ( V_112 -> V_51 ) ? V_112 -> V_51 -> V_61 : NULL ;
if ( V_112 -> V_51 ) {
V_112 -> V_51 -> V_54 = V_54 ;
V_112 -> V_51 -> V_110 = V_112 -> V_110 ;
}
V_60 -> V_112 = V_112 ;
V_60 -> V_110 = V_112 -> V_110 ;
V_112 -> V_60 = V_60 ;
return V_117 ;
}
static struct V_59 *
F_68 ( struct V_137 * V_112 )
{
struct V_59 * V_60 = V_112 -> V_60 ;
if ( V_60 && V_112 -> V_51 )
V_112 -> V_51 -> V_54 = NULL ;
V_112 -> V_60 = NULL ;
return V_60 ;
}
static int
F_69 ( struct V_137 * V_112 , struct V_59 * V_60 )
{
int V_9 ;
if ( ! V_60 )
return - V_96 ;
F_54 ( & V_112 -> V_113 ) ;
V_9 = F_70 ( V_60 -> V_54 ) ;
if ( V_9 )
return V_9 ;
F_56 ( & V_112 -> V_113 ) ;
F_60 ( V_112 ) ;
return V_9 ;
}
static T_6
F_71 ( struct V_29 * V_30 , struct V_115 * V_116 ,
const char * V_3 , T_7 V_117 )
{
struct V_137 * V_112 = NULL , * V_148 ;
static struct V_59 * V_60 ;
T_2 V_132 , V_133 ;
unsigned long V_127 ;
int V_9 ;
V_9 = F_10 ( V_30 , & V_132 , & V_133 , V_3 ) ;
if ( V_9 )
return V_9 ;
F_48 ( & V_129 , V_127 ) ;
F_58 (tmpport, &fcloop_nports, nport_list) {
if ( V_148 -> V_122 == V_132 &&
V_148 -> V_123 == V_133 && V_148 -> V_60 ) {
V_112 = V_148 ;
V_60 = F_68 ( V_112 ) ;
break;
}
}
F_50 ( & V_129 , V_127 ) ;
if ( ! V_112 )
return - V_134 ;
V_9 = F_69 ( V_112 , V_60 ) ;
return V_9 ? V_9 : V_117 ;
}
static T_6
F_72 ( struct V_29 * V_30 , struct V_115 * V_116 ,
const char * V_3 , T_7 V_117 )
{
struct V_65 * V_61 ;
struct V_137 * V_112 ;
struct V_50 * V_51 ;
struct V_149 V_150 ;
int V_9 ;
V_112 = F_64 ( V_3 , V_117 , false ) ;
if ( ! V_112 )
return - V_147 ;
V_150 . V_122 = V_112 -> V_122 ;
V_150 . V_123 = V_112 -> V_123 ;
V_150 . V_125 = V_112 -> V_125 ;
V_9 = F_73 ( & V_150 , & V_151 , NULL ,
& V_61 ) ;
if ( V_9 ) {
F_60 ( V_112 ) ;
return V_9 ;
}
V_51 = V_61 -> V_58 ;
V_51 -> V_61 = V_61 ;
V_51 -> V_54 = ( V_112 -> V_60 ) ? V_112 -> V_60 -> V_54 : NULL ;
if ( V_112 -> V_60 )
V_112 -> V_60 -> V_61 = V_61 ;
V_51 -> V_112 = V_112 ;
V_51 -> V_110 = V_112 -> V_110 ;
V_112 -> V_51 = V_51 ;
return V_117 ;
}
static struct V_50 *
F_74 ( struct V_137 * V_112 )
{
struct V_50 * V_51 = V_112 -> V_51 ;
if ( V_51 && V_112 -> V_60 )
V_112 -> V_60 -> V_61 = NULL ;
V_112 -> V_51 = NULL ;
return V_51 ;
}
static int
F_75 ( struct V_137 * V_112 , struct V_50 * V_51 )
{
int V_9 ;
if ( ! V_51 )
return - V_96 ;
F_54 ( & V_112 -> V_114 ) ;
V_9 = F_76 ( V_51 -> V_61 ) ;
if ( V_9 )
return V_9 ;
F_56 ( & V_112 -> V_114 ) ;
F_60 ( V_112 ) ;
return V_9 ;
}
static T_6
F_77 ( struct V_29 * V_30 , struct V_115 * V_116 ,
const char * V_3 , T_7 V_117 )
{
struct V_137 * V_112 = NULL , * V_148 ;
struct V_50 * V_51 ;
T_2 V_132 , V_133 ;
unsigned long V_127 ;
int V_9 ;
V_9 = F_10 ( V_30 , & V_132 , & V_133 , V_3 ) ;
if ( V_9 )
return V_9 ;
F_48 ( & V_129 , V_127 ) ;
F_58 (tmpport, &fcloop_nports, nport_list) {
if ( V_148 -> V_122 == V_132 &&
V_148 -> V_123 == V_133 && V_148 -> V_51 ) {
V_112 = V_148 ;
V_51 = F_74 ( V_112 ) ;
break;
}
}
F_50 ( & V_129 , V_127 ) ;
if ( ! V_112 )
return - V_134 ;
V_9 = F_75 ( V_112 , V_51 ) ;
return V_9 ? V_9 : V_117 ;
}
static int T_8 F_78 ( void )
{
int V_9 ;
V_152 = F_79 ( V_153 , L_3 ) ;
if ( F_80 ( V_152 ) ) {
F_81 ( L_4 ) ;
V_9 = F_82 ( V_152 ) ;
return V_9 ;
}
V_154 = F_83 (
V_152 , NULL , F_84 ( 0 , 0 ) , NULL ,
V_155 , L_5 ) ;
if ( F_80 ( V_154 ) ) {
F_81 ( L_6 ) ;
V_9 = F_82 ( V_154 ) ;
goto V_156;
}
F_85 ( V_154 ) ;
return 0 ;
V_156:
F_86 ( V_152 ) ;
return V_9 ;
}
static void T_9 F_87 ( void )
{
struct V_109 * V_110 ;
struct V_137 * V_112 ;
struct V_50 * V_51 ;
struct V_59 * V_60 ;
unsigned long V_127 ;
int V_9 ;
F_48 ( & V_129 , V_127 ) ;
for (; ; ) {
V_112 = F_88 ( & V_146 ,
F_89 ( * V_112 ) , V_138 ) ;
if ( ! V_112 )
break;
V_51 = F_74 ( V_112 ) ;
V_60 = F_68 ( V_112 ) ;
F_50 ( & V_129 , V_127 ) ;
V_9 = F_75 ( V_112 , V_51 ) ;
if ( V_9 )
F_8 ( L_7 , V_157 ) ;
V_9 = F_69 ( V_112 , V_60 ) ;
if ( V_9 )
F_8 ( L_8 , V_157 ) ;
F_48 ( & V_129 , V_127 ) ;
}
for (; ; ) {
V_110 = F_88 ( & V_130 ,
F_89 ( * V_110 ) , V_128 ) ;
if ( ! V_110 )
break;
F_51 ( V_110 ) ;
F_50 ( & V_129 , V_127 ) ;
V_9 = F_53 ( V_110 ) ;
if ( V_9 )
F_8 ( L_9 , V_157 ) ;
F_48 ( & V_129 , V_127 ) ;
}
F_50 ( & V_129 , V_127 ) ;
F_90 ( V_154 ) ;
F_91 ( V_152 , F_84 ( 0 , 0 ) ) ;
F_86 ( V_152 ) ;
}
