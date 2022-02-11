static bool F_1 ( struct V_1 * V_2 )
{
return ! F_2 ( & V_2 -> V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_4 -> V_5 ( V_2 ) ;
}
static int F_4 ( struct V_6 * V_7 ,
struct V_1 * V_2 , T_1 V_8 )
{
if ( ! V_7 -> V_9 -> V_10 )
return - V_11 ;
return V_7 -> V_9 -> V_10 ( V_7 , V_8 ) ;
}
static bool F_5 ( struct V_6 * V_7 , struct V_1 * V_2 ,
T_1 V_12 , int V_13 )
{
T_1 V_14 ;
int V_15 = 0 ;
if ( ! V_7 -> V_9 )
return true ;
if ( ! F_1 ( V_2 ) ) {
V_12 = F_6 ( T_1 , V_12 , 1 ) ;
V_13 = 0 ;
}
V_14 = F_3 ( V_2 ) ;
if ( V_14 >= V_12 ) {
if ( ! V_12 && V_14 < V_13 )
F_4 ( V_7 , V_2 ,
V_13 - V_14 ) ;
return true ;
}
if ( V_13 )
V_15 = F_4 ( V_7 , V_2 ,
V_12 - V_14 ) ;
if ( V_15 <= 0 )
return false ;
if ( V_14 + V_15 >= V_12 )
return true ;
return false ;
}
T_2 F_7 ( struct V_16 * V_17 , char T_3 * V_2 ,
T_1 V_18 , T_4 * V_19 )
{
struct V_6 * V_7 = V_17 -> V_20 ;
struct V_1 * V_21 = V_7 -> V_22 ;
F_8 ( V_23 , V_24 ) ;
T_1 V_25 ;
T_1 V_12 ;
int V_26 = 0 ;
if ( ! V_7 -> V_9 )
return - V_11 ;
if ( ! V_21 || ! V_21 -> V_4 -> V_27 )
return - V_28 ;
V_25 = V_21 -> V_29 ;
if ( ! V_25 )
return 0 ;
if ( V_17 -> V_30 & V_31 )
V_12 = 0 ;
else
V_12 = F_6 ( T_1 , V_18 / V_25 , V_21 -> V_32 ) ;
F_9 ( & V_21 -> V_33 , & V_23 ) ;
do {
if ( ! V_7 -> V_9 ) {
V_26 = - V_11 ;
break;
}
if ( ! F_5 ( V_7 , V_21 , V_12 , V_18 / V_25 ) ) {
if ( F_10 ( V_34 ) ) {
V_26 = - V_35 ;
break;
}
F_11 ( & V_23 , V_36 ,
V_37 ) ;
continue;
}
V_26 = V_21 -> V_4 -> V_27 ( V_21 , V_18 , V_2 ) ;
if ( V_26 == 0 && ( V_17 -> V_30 & V_31 ) )
V_26 = - V_38 ;
} while ( V_26 == 0 );
F_12 ( & V_21 -> V_33 , & V_23 ) ;
return V_26 ;
}
unsigned int F_13 ( struct V_16 * V_17 ,
struct V_39 * V_23 )
{
struct V_6 * V_7 = V_17 -> V_20 ;
struct V_1 * V_21 = V_7 -> V_22 ;
if ( ! V_7 -> V_9 )
return 0 ;
F_14 ( V_17 , & V_21 -> V_33 , V_23 ) ;
if ( F_5 ( V_7 , V_21 , V_21 -> V_32 , 0 ) )
return V_40 | V_41 ;
return 0 ;
}
void F_15 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_22 )
return;
F_16 ( & V_7 -> V_22 -> V_33 ) ;
}
void F_17 ( struct V_1 * V_22 )
{
F_18 ( & V_22 -> V_42 ) ;
F_18 ( & V_22 -> V_3 ) ;
F_19 ( & V_22 -> V_33 ) ;
F_20 ( & V_22 -> V_43 ) ;
if ( ! V_22 -> V_32 )
V_22 -> V_32 = 1 ;
}
static T_2 F_21 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_2 )
{
return sprintf ( V_2 , L_1 , F_22 ( V_47 ) -> V_48 -> V_49 ) ;
}
static T_2 F_23 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_2 )
{
struct V_50 * V_51 = F_22 ( V_47 ) ;
T_5 type = V_51 -> V_48 -> V_52 . V_53 ;
if ( type == V_54 ) {
#ifdef F_24
type = V_55 ;
#else
type = V_56 ;
#endif
}
if ( V_51 -> V_48 -> V_52 . V_57 > 1 )
return sprintf ( V_2 , L_2 ,
V_58 [ type ] ,
V_51 -> V_48 -> V_52 . V_59 ,
V_51 -> V_48 -> V_52 . V_60 ,
V_51 -> V_48 -> V_52 . V_61 ,
V_51 -> V_48 -> V_52 . V_57 ,
V_51 -> V_48 -> V_52 . V_62 ) ;
else
return sprintf ( V_2 , L_3 ,
V_58 [ type ] ,
V_51 -> V_48 -> V_52 . V_59 ,
V_51 -> V_48 -> V_52 . V_60 ,
V_51 -> V_48 -> V_52 . V_61 ,
V_51 -> V_48 -> V_52 . V_62 ) ;
}
static T_2 F_25 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_2 )
{
int V_26 ;
struct V_6 * V_7 = F_26 ( V_45 ) ;
V_26 = ! ! F_27 ( F_22 ( V_47 ) -> V_63 ,
V_7 -> V_22 -> V_64 ) ;
return sprintf ( V_2 , L_4 , V_26 ) ;
}
static const unsigned long * F_28 ( const unsigned long * V_65 ,
unsigned int V_66 ,
const unsigned long * V_67 ,
bool V_68 )
{
if ( F_29 ( V_67 , V_66 ) )
return NULL ;
while ( * V_65 ) {
if ( V_68 ) {
if ( F_30 ( V_67 , V_65 , V_66 ) )
return V_65 ;
} else {
if ( F_31 ( V_67 , V_65 , V_66 ) )
return V_65 ;
}
V_65 += F_32 ( V_66 ) ;
}
return NULL ;
}
static bool F_33 ( struct V_6 * V_7 ,
const unsigned long * V_67 )
{
if ( ! V_7 -> V_69 -> V_70 )
return true ;
return V_7 -> V_69 -> V_70 ( V_7 , V_67 ) ;
}
static int F_34 ( struct V_6 * V_7 ,
struct V_1 * V_22 , int V_71 )
{
const unsigned long * V_67 ;
unsigned long * V_72 ;
V_72 = F_35 ( F_32 ( V_7 -> V_66 ) ,
sizeof( * V_72 ) ,
V_73 ) ;
if ( V_72 == NULL )
return - V_74 ;
if ( ! V_7 -> V_66 ) {
F_36 ( 1 , L_5 ) ;
goto V_75;
}
F_37 ( V_72 , V_22 -> V_64 , V_7 -> V_66 ) ;
F_38 ( V_71 , V_72 ) ;
if ( ! F_33 ( V_7 , V_72 ) )
goto V_75;
if ( V_7 -> V_76 ) {
V_67 = F_28 ( V_7 -> V_76 ,
V_7 -> V_66 ,
V_72 , false ) ;
if ( ! V_67 )
goto V_75;
}
F_37 ( V_22 -> V_64 , V_72 , V_7 -> V_66 ) ;
F_39 ( V_72 ) ;
return 0 ;
V_75:
F_39 ( V_72 ) ;
return - V_28 ;
}
static int F_40 ( struct V_1 * V_22 , int V_71 )
{
F_41 ( V_71 , V_22 -> V_64 ) ;
return 0 ;
}
static T_2 F_42 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
const char * V_2 ,
T_1 V_77 )
{
int V_26 ;
bool V_78 ;
struct V_6 * V_7 = F_26 ( V_45 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
struct V_50 * V_51 = F_22 ( V_47 ) ;
V_26 = F_43 ( V_2 , & V_78 ) ;
if ( V_26 < 0 )
return V_26 ;
F_44 ( & V_7 -> V_79 ) ;
if ( F_1 ( V_7 -> V_22 ) ) {
V_26 = - V_80 ;
goto V_81;
}
V_26 = F_45 ( V_7 , V_22 , V_51 -> V_63 ) ;
if ( V_26 < 0 )
goto V_81;
if ( ! V_78 && V_26 ) {
V_26 = F_40 ( V_22 , V_51 -> V_63 ) ;
if ( V_26 )
goto V_81;
} else if ( V_78 && ! V_26 ) {
V_26 = F_34 ( V_7 , V_22 , V_51 -> V_63 ) ;
if ( V_26 )
goto V_81;
}
V_81:
F_46 ( & V_7 -> V_79 ) ;
return V_26 < 0 ? V_26 : V_77 ;
}
static T_2 F_47 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_2 )
{
struct V_6 * V_7 = F_26 ( V_45 ) ;
return sprintf ( V_2 , L_4 , V_7 -> V_22 -> V_82 ) ;
}
static T_2 F_48 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
const char * V_2 ,
T_1 V_77 )
{
int V_26 ;
struct V_6 * V_7 = F_26 ( V_45 ) ;
bool V_78 ;
V_26 = F_43 ( V_2 , & V_78 ) ;
if ( V_26 < 0 )
return V_26 ;
F_44 ( & V_7 -> V_79 ) ;
if ( F_1 ( V_7 -> V_22 ) ) {
V_26 = - V_80 ;
goto V_81;
}
V_7 -> V_22 -> V_82 = V_78 ;
V_81:
F_46 ( & V_7 -> V_79 ) ;
return V_26 ? V_26 : V_77 ;
}
static int F_49 ( struct V_6 * V_7 ,
const struct V_83 * V_84 )
{
int V_26 , V_85 = 0 ;
struct V_1 * V_22 = V_7 -> V_22 ;
V_26 = F_50 ( L_6 ,
V_84 ,
& F_21 ,
NULL ,
0 ,
V_86 ,
& V_7 -> V_45 ,
& V_22 -> V_87 ) ;
if ( V_26 )
return V_26 ;
V_85 ++ ;
V_26 = F_50 ( L_7 ,
V_84 ,
& F_23 ,
NULL ,
0 ,
0 ,
& V_7 -> V_45 ,
& V_22 -> V_87 ) ;
if ( V_26 )
return V_26 ;
V_85 ++ ;
if ( V_84 -> type != V_88 )
V_26 = F_50 ( L_8 ,
V_84 ,
& F_25 ,
& F_42 ,
V_84 -> V_49 ,
0 ,
& V_7 -> V_45 ,
& V_22 -> V_87 ) ;
else
V_26 = F_50 ( L_8 ,
V_84 ,
& F_47 ,
& F_48 ,
V_84 -> V_49 ,
0 ,
& V_7 -> V_45 ,
& V_22 -> V_87 ) ;
if ( V_26 )
return V_26 ;
V_85 ++ ;
V_26 = V_85 ;
return V_26 ;
}
static T_2 F_51 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_2 )
{
struct V_6 * V_7 = F_26 ( V_45 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
return sprintf ( V_2 , L_4 , V_22 -> V_89 ) ;
}
static T_2 F_52 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
const char * V_2 , T_1 V_77 )
{
struct V_6 * V_7 = F_26 ( V_45 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
unsigned int V_90 ;
int V_26 ;
V_26 = F_53 ( V_2 , 10 , & V_90 ) ;
if ( V_26 )
return V_26 ;
if ( V_90 == V_22 -> V_89 )
return V_77 ;
F_44 ( & V_7 -> V_79 ) ;
if ( F_1 ( V_7 -> V_22 ) ) {
V_26 = - V_80 ;
} else {
V_22 -> V_4 -> V_91 ( V_22 , V_90 ) ;
V_26 = 0 ;
}
if ( V_26 )
goto V_92;
if ( V_22 -> V_89 && V_22 -> V_89 < V_22 -> V_32 )
V_22 -> V_32 = V_22 -> V_89 ;
V_92:
F_46 ( & V_7 -> V_79 ) ;
return V_26 ? V_26 : V_77 ;
}
static T_2 F_54 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_2 )
{
struct V_6 * V_7 = F_26 ( V_45 ) ;
return sprintf ( V_2 , L_4 , F_1 ( V_7 -> V_22 ) ) ;
}
static unsigned int F_55 ( struct V_6 * V_7 ,
unsigned int V_49 )
{
const struct V_83 * V_93 ;
unsigned int V_94 ;
V_93 = F_56 ( V_7 , V_49 ) ;
V_94 = V_93 -> V_52 . V_61 / 8 ;
if ( V_93 -> V_52 . V_57 > 1 )
V_94 *= V_93 -> V_52 . V_57 ;
return V_94 ;
}
static unsigned int F_57 ( struct V_6 * V_7 )
{
return F_55 ( V_7 ,
V_7 -> V_95 ) ;
}
static int F_58 ( struct V_6 * V_7 ,
const unsigned long * V_67 , bool V_96 )
{
unsigned V_94 = 0 ;
int V_89 , V_97 ;
F_59 (i, mask,
indio_dev->masklength) {
V_89 = F_55 ( V_7 , V_97 ) ;
V_94 = F_60 ( V_94 , V_89 ) ;
V_94 += V_89 ;
}
if ( V_96 ) {
V_89 = F_57 ( V_7 ) ;
V_94 = F_60 ( V_94 , V_89 ) ;
V_94 += V_89 ;
}
return V_94 ;
}
static void F_61 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
F_62 ( V_22 ) ;
F_63 ( & V_22 -> V_3 , & V_7 -> V_3 ) ;
}
static void F_64 ( struct V_1 * V_22 )
{
F_65 ( & V_22 -> V_3 ) ;
F_66 ( & V_22 -> V_33 ) ;
F_67 ( V_22 ) ;
}
static void F_68 ( struct V_6 * V_7 )
{
struct V_1 * V_22 , * V_98 ;
F_69 (buffer, _buffer,
&indio_dev->buffer_list, buffer_list)
F_64 ( V_22 ) ;
}
static int F_70 ( struct V_1 * V_22 ,
struct V_6 * V_7 )
{
if ( ! V_22 -> V_4 -> V_99 )
return 0 ;
return V_22 -> V_4 -> V_99 ( V_22 , V_7 ) ;
}
static int F_71 ( struct V_1 * V_22 ,
struct V_6 * V_7 )
{
if ( ! V_22 -> V_4 -> V_100 )
return 0 ;
return V_22 -> V_4 -> V_100 ( V_22 , V_7 ) ;
}
static void F_72 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
unsigned int V_94 ;
if ( ! V_22 -> V_4 -> V_101 )
return;
V_94 = F_58 ( V_7 , V_22 -> V_64 ,
V_22 -> V_82 ) ;
V_22 -> V_4 -> V_101 ( V_22 , V_94 ) ;
}
static int F_73 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
int V_26 ;
F_72 ( V_7 , V_22 ) ;
if ( V_22 -> V_4 -> V_102 ) {
V_26 = V_22 -> V_4 -> V_102 ( V_22 ) ;
if ( V_26 ) {
F_74 ( & V_7 -> V_45 ,
L_9 ,
V_26 ) ;
return V_26 ;
}
}
return 0 ;
}
static void F_75 ( struct V_6 * V_7 ,
const unsigned long * V_67 )
{
if ( ! V_7 -> V_76 )
F_39 ( V_67 ) ;
}
static int F_76 ( struct V_6 * V_7 ,
struct V_1 * V_103 , struct V_1 * V_104 ,
struct V_105 * V_106 )
{
unsigned long * V_107 ;
const unsigned long * V_64 ;
bool V_108 = false ;
struct V_1 * V_22 ;
bool V_82 ;
unsigned int V_109 ;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
V_106 -> V_32 = ~ 0 ;
if ( V_104 && ! V_103 &&
F_77 ( & V_7 -> V_3 ) )
return 0 ;
V_109 = V_7 -> V_109 ;
F_78 (buffer, &indio_dev->buffer_list, buffer_list) {
if ( V_22 == V_104 )
continue;
V_109 &= V_22 -> V_4 -> V_109 ;
V_106 -> V_32 = F_79 ( V_106 -> V_32 , V_22 -> V_32 ) ;
}
if ( V_103 ) {
V_109 &= V_103 -> V_4 -> V_109 ;
V_106 -> V_32 = F_79 ( V_106 -> V_32 ,
V_103 -> V_32 ) ;
}
if ( ( V_109 & V_110 ) && V_7 -> V_111 ) {
V_106 -> V_112 = V_110 ;
} else if ( V_109 & V_113 ) {
if ( V_103 && ! F_2 ( & V_7 -> V_3 ) )
return - V_28 ;
V_106 -> V_112 = V_113 ;
V_108 = true ;
} else if ( V_109 & V_114 ) {
V_106 -> V_112 = V_114 ;
} else {
if ( V_7 -> V_109 & V_110 )
F_74 ( & V_7 -> V_45 , L_10 ) ;
return - V_28 ;
}
V_107 = F_80 ( F_32 ( V_7 -> V_66 ) ,
sizeof( long ) , V_73 ) ;
if ( V_107 == NULL )
return - V_74 ;
V_82 = false ;
F_78 (buffer, &indio_dev->buffer_list, buffer_list) {
if ( V_22 == V_104 )
continue;
F_81 ( V_107 , V_107 , V_22 -> V_64 ,
V_7 -> V_66 ) ;
V_82 |= V_22 -> V_82 ;
}
if ( V_103 ) {
F_81 ( V_107 , V_107 ,
V_103 -> V_64 , V_7 -> V_66 ) ;
V_82 |= V_103 -> V_82 ;
}
if ( V_7 -> V_76 ) {
V_64 = F_28 ( V_7 -> V_76 ,
V_7 -> V_66 ,
V_107 ,
V_108 ) ;
F_39 ( V_107 ) ;
if ( V_64 == NULL )
return - V_28 ;
} else {
V_64 = V_107 ;
}
V_106 -> V_115 = F_58 ( V_7 ,
V_64 , V_82 ) ;
V_106 -> V_64 = V_64 ;
V_106 -> V_82 = V_82 ;
return 0 ;
}
static int F_82 ( struct V_6 * V_7 ,
struct V_105 * V_106 )
{
struct V_1 * V_22 ;
int V_26 ;
V_7 -> V_116 = V_106 -> V_64 ;
V_7 -> V_82 = V_106 -> V_82 ;
V_7 -> V_115 = V_106 -> V_115 ;
F_83 ( V_7 ) ;
if ( V_7 -> V_69 -> V_117 ) {
V_26 = V_7 -> V_69 -> V_117 ( V_7 ) ;
if ( V_26 ) {
F_74 ( & V_7 -> V_45 ,
L_11 , V_26 ) ;
goto V_118;
}
}
if ( V_7 -> V_9 -> V_119 ) {
V_26 = V_7 -> V_9
-> V_119 ( V_7 ,
V_7 -> V_116 ) ;
if ( V_26 < 0 ) {
F_74 ( & V_7 -> V_45 ,
L_12 ,
V_26 ) ;
goto V_120;
}
}
if ( V_7 -> V_9 -> V_121 )
V_7 -> V_9 -> V_121 ( V_7 ,
V_106 -> V_32 ) ;
F_78 (buffer, &indio_dev->buffer_list, buffer_list) {
V_26 = F_70 ( V_22 , V_7 ) ;
if ( V_26 )
goto V_122;
}
V_7 -> V_123 = V_106 -> V_112 ;
if ( V_7 -> V_69 -> V_124 ) {
V_26 = V_7 -> V_69 -> V_124 ( V_7 ) ;
if ( V_26 ) {
F_74 ( & V_7 -> V_45 ,
L_13 , V_26 ) ;
goto V_122;
}
}
return 0 ;
V_122:
F_84 (buffer, &indio_dev->buffer_list,
buffer_list)
F_71 ( V_22 , V_7 ) ;
V_120:
V_7 -> V_123 = V_125 ;
if ( V_7 -> V_69 -> V_126 )
V_7 -> V_69 -> V_126 ( V_7 ) ;
V_118:
V_7 -> V_116 = NULL ;
return V_26 ;
}
static int F_85 ( struct V_6 * V_7 )
{
struct V_1 * V_22 ;
int V_26 = 0 ;
int V_127 ;
if ( F_2 ( & V_7 -> V_3 ) )
return 0 ;
if ( V_7 -> V_69 -> V_128 ) {
V_127 = V_7 -> V_69 -> V_128 ( V_7 ) ;
if ( V_127 && ! V_26 )
V_26 = V_127 ;
}
F_78 (buffer, &indio_dev->buffer_list, buffer_list) {
V_127 = F_71 ( V_22 , V_7 ) ;
if ( V_127 && ! V_26 )
V_26 = V_127 ;
}
V_7 -> V_123 = V_125 ;
if ( V_7 -> V_69 -> V_126 ) {
V_127 = V_7 -> V_69 -> V_126 ( V_7 ) ;
if ( V_127 && ! V_26 )
V_26 = V_127 ;
}
F_75 ( V_7 , V_7 -> V_116 ) ;
V_7 -> V_116 = NULL ;
return V_26 ;
}
static int F_86 ( struct V_6 * V_7 ,
struct V_1 * V_103 ,
struct V_1 * V_104 )
{
struct V_105 V_129 ;
int V_26 ;
V_26 = F_76 ( V_7 , V_103 , V_104 ,
& V_129 ) ;
if ( V_26 )
return V_26 ;
if ( V_103 ) {
V_26 = F_73 ( V_7 , V_103 ) ;
if ( V_26 )
goto V_130;
}
V_26 = F_85 ( V_7 ) ;
if ( V_26 )
goto V_131;
if ( V_104 )
F_64 ( V_104 ) ;
if ( V_103 )
F_61 ( V_7 , V_103 ) ;
if ( F_2 ( & V_7 -> V_3 ) )
return 0 ;
V_26 = F_82 ( V_7 , & V_129 ) ;
if ( V_26 )
goto V_131;
return 0 ;
V_131:
F_68 ( V_7 ) ;
V_130:
F_75 ( V_7 , V_129 . V_64 ) ;
return V_26 ;
}
int F_87 ( struct V_6 * V_7 ,
struct V_1 * V_103 ,
struct V_1 * V_104 )
{
int V_26 ;
if ( V_103 == V_104 )
return 0 ;
F_44 ( & V_7 -> V_132 ) ;
F_44 ( & V_7 -> V_79 ) ;
if ( V_103 && F_1 ( V_103 ) )
V_103 = NULL ;
if ( V_104 && ! F_1 ( V_104 ) )
V_104 = NULL ;
if ( ! V_103 && ! V_104 ) {
V_26 = 0 ;
goto V_133;
}
if ( V_7 -> V_9 == NULL ) {
V_26 = - V_11 ;
goto V_133;
}
V_26 = F_86 ( V_7 , V_103 , V_104 ) ;
V_133:
F_46 ( & V_7 -> V_79 ) ;
F_46 ( & V_7 -> V_132 ) ;
return V_26 ;
}
void F_88 ( struct V_6 * V_7 )
{
F_85 ( V_7 ) ;
F_68 ( V_7 ) ;
}
static T_2 F_89 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
const char * V_2 ,
T_1 V_77 )
{
int V_26 ;
bool V_134 ;
struct V_6 * V_7 = F_26 ( V_45 ) ;
bool V_135 ;
V_26 = F_43 ( V_2 , & V_134 ) ;
if ( V_26 < 0 )
return V_26 ;
F_44 ( & V_7 -> V_79 ) ;
V_135 = F_1 ( V_7 -> V_22 ) ;
if ( V_135 == V_134 )
goto V_136;
if ( V_134 )
V_26 = F_86 ( V_7 ,
V_7 -> V_22 , NULL ) ;
else
V_26 = F_86 ( V_7 ,
NULL , V_7 -> V_22 ) ;
V_136:
F_46 ( & V_7 -> V_79 ) ;
return ( V_26 < 0 ) ? V_26 : V_77 ;
}
static T_2 F_90 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_2 )
{
struct V_6 * V_7 = F_26 ( V_45 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
return sprintf ( V_2 , L_1 , V_22 -> V_32 ) ;
}
static T_2 F_91 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
const char * V_2 ,
T_1 V_77 )
{
struct V_6 * V_7 = F_26 ( V_45 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
unsigned int V_90 ;
int V_26 ;
V_26 = F_53 ( V_2 , 10 , & V_90 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_90 )
return - V_28 ;
F_44 ( & V_7 -> V_79 ) ;
if ( V_90 > V_22 -> V_89 ) {
V_26 = - V_28 ;
goto V_92;
}
if ( F_1 ( V_7 -> V_22 ) ) {
V_26 = - V_80 ;
goto V_92;
}
V_22 -> V_32 = V_90 ;
V_92:
F_46 ( & V_7 -> V_79 ) ;
return V_26 ? V_26 : V_77 ;
}
int F_92 ( struct V_6 * V_7 )
{
struct V_50 * V_137 ;
struct V_138 * * V_47 ;
struct V_1 * V_22 = V_7 -> V_22 ;
int V_26 , V_97 , V_139 , V_85 , V_140 = 0 ;
const struct V_83 * V_141 ;
V_141 = V_7 -> V_141 ;
if ( V_141 ) {
int V_142 = V_7 -> V_66 ;
for ( V_97 = 0 ; V_97 < V_7 -> V_143 ; V_97 ++ )
V_142 = F_93 ( V_142 , V_141 [ V_97 ] . V_49 + 1 ) ;
V_7 -> V_66 = V_142 ;
}
if ( ! V_22 )
return 0 ;
V_85 = 0 ;
if ( V_22 -> V_144 ) {
while ( V_22 -> V_144 [ V_85 ] != NULL )
V_85 ++ ;
}
V_47 = F_80 ( V_85 + F_94 ( V_145 ) + 1 ,
sizeof( struct V_138 * ) , V_73 ) ;
if ( ! V_47 )
return - V_74 ;
memcpy ( V_47 , V_145 , sizeof( V_145 ) ) ;
if ( ! V_22 -> V_4 -> V_91 )
V_47 [ 0 ] = & V_146 . V_47 ;
if ( V_22 -> V_4 -> V_147 & V_148 )
V_47 [ 2 ] = & V_149 . V_47 ;
if ( V_22 -> V_144 )
memcpy ( & V_47 [ F_94 ( V_145 ) ] , V_22 -> V_144 ,
sizeof( struct V_138 * ) * V_85 ) ;
V_47 [ V_85 + F_94 ( V_145 ) ] = NULL ;
V_22 -> V_150 . V_151 = L_14 ;
V_22 -> V_150 . V_144 = V_47 ;
V_7 -> V_152 [ V_7 -> V_153 ++ ] = & V_22 -> V_150 ;
if ( V_22 -> V_154 != NULL ) {
V_47 = V_22 -> V_154 -> V_144 ;
while ( * V_47 ++ != NULL )
V_140 ++ ;
}
V_85 = V_140 ;
F_18 ( & V_22 -> V_87 ) ;
V_141 = V_7 -> V_141 ;
if ( V_141 ) {
for ( V_97 = 0 ; V_97 < V_7 -> V_143 ; V_97 ++ ) {
if ( V_141 [ V_97 ] . V_49 < 0 )
continue;
V_26 = F_49 ( V_7 ,
& V_141 [ V_97 ] ) ;
if ( V_26 < 0 )
goto V_155;
V_85 += V_26 ;
if ( V_141 [ V_97 ] . type == V_88 )
V_7 -> V_95 =
V_141 [ V_97 ] . V_49 ;
}
if ( V_7 -> V_66 && V_22 -> V_64 == NULL ) {
V_22 -> V_64 = F_80 ( F_32 ( V_7 -> V_66 ) ,
sizeof( * V_22 -> V_64 ) ,
V_73 ) ;
if ( V_22 -> V_64 == NULL ) {
V_26 = - V_74 ;
goto V_155;
}
}
}
V_22 -> V_156 . V_151 = V_157 ;
V_22 -> V_156 . V_144 = F_80 ( V_85 + 1 ,
sizeof( V_22 -> V_156 . V_144 [ 0 ] ) ,
V_73 ) ;
if ( V_22 -> V_156 . V_144 == NULL ) {
V_26 = - V_74 ;
goto V_158;
}
if ( V_22 -> V_154 )
memcpy ( V_22 -> V_156 . V_144 , V_22 -> V_154 ,
sizeof( V_22 -> V_156 . V_144 [ 0 ] ) * V_140 ) ;
V_139 = V_140 ;
F_78 (p, &buffer->scan_el_dev_attr_list, l)
V_22 -> V_156 . V_144 [ V_139 ++ ] = & V_137 -> V_159 . V_47 ;
V_7 -> V_152 [ V_7 -> V_153 ++ ] = & V_22 -> V_156 ;
return 0 ;
V_158:
F_39 ( V_22 -> V_64 ) ;
V_155:
F_95 ( & V_22 -> V_87 ) ;
F_39 ( V_7 -> V_22 -> V_150 . V_144 ) ;
return V_26 ;
}
void F_96 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_22 )
return;
F_39 ( V_7 -> V_22 -> V_64 ) ;
F_39 ( V_7 -> V_22 -> V_150 . V_144 ) ;
F_39 ( V_7 -> V_22 -> V_156 . V_144 ) ;
F_95 ( & V_7 -> V_22 -> V_87 ) ;
}
bool F_97 ( struct V_6 * V_7 ,
const unsigned long * V_67 )
{
return F_98 ( V_67 , V_7 -> V_66 ) == 1 ;
}
int F_45 ( struct V_6 * V_7 ,
struct V_1 * V_22 , int V_71 )
{
if ( V_71 > V_7 -> V_66 )
return - V_28 ;
if ( ! V_22 -> V_64 )
return 0 ;
return ! ! F_27 ( V_71 , V_22 -> V_64 ) ;
}
static const void * F_99 ( struct V_1 * V_22 ,
const void * V_160 )
{
struct V_161 * V_162 ;
if ( F_2 ( & V_22 -> V_42 ) )
return V_160 ;
F_78 (t, &buffer->demux_list, l)
memcpy ( V_22 -> V_163 + V_162 -> V_164 ,
V_160 + V_162 -> V_165 , V_162 -> V_89 ) ;
return V_22 -> V_163 ;
}
static int F_100 ( struct V_1 * V_22 , const void * V_166 )
{
const void * V_167 = F_99 ( V_22 , V_166 ) ;
int V_26 ;
V_26 = V_22 -> V_4 -> V_168 ( V_22 , V_167 ) ;
if ( V_26 )
return V_26 ;
F_101 ( & V_22 -> V_33 , V_40 | V_41 ) ;
return 0 ;
}
static void F_102 ( struct V_1 * V_22 )
{
struct V_161 * V_137 , * V_169 ;
F_69 (p, q, &buffer->demux_list, l) {
F_103 ( & V_137 -> V_170 ) ;
F_39 ( V_137 ) ;
}
}
int F_104 ( struct V_6 * V_7 , const void * V_166 )
{
int V_26 ;
struct V_1 * V_2 ;
F_78 (buf, &indio_dev->buffer_list, buffer_list) {
V_26 = F_100 ( V_2 , V_166 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return 0 ;
}
static int F_105 ( struct V_1 * V_22 ,
struct V_161 * * V_137 , unsigned int V_171 , unsigned int V_172 ,
unsigned int V_89 )
{
if ( * V_137 && ( * V_137 ) -> V_165 + ( * V_137 ) -> V_89 == V_171 &&
( * V_137 ) -> V_164 + ( * V_137 ) -> V_89 == V_172 ) {
( * V_137 ) -> V_89 += V_89 ;
} else {
* V_137 = F_106 ( sizeof( * * V_137 ) , V_73 ) ;
if ( * V_137 == NULL )
return - V_74 ;
( * V_137 ) -> V_165 = V_171 ;
( * V_137 ) -> V_164 = V_172 ;
( * V_137 ) -> V_89 = V_89 ;
F_107 ( & ( * V_137 ) -> V_170 , & V_22 -> V_42 ) ;
}
return 0 ;
}
static int F_108 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
int V_26 , V_173 = - 1 , V_174 , V_89 ;
unsigned V_171 = 0 , V_172 = 0 ;
struct V_161 * V_137 = NULL ;
F_102 ( V_22 ) ;
F_39 ( V_22 -> V_163 ) ;
V_22 -> V_163 = NULL ;
if ( F_30 ( V_7 -> V_116 ,
V_22 -> V_64 ,
V_7 -> V_66 ) )
return 0 ;
F_59 (out_ind,
buffer->scan_mask,
indio_dev->masklength) {
V_173 = F_109 ( V_7 -> V_116 ,
V_7 -> V_66 ,
V_173 + 1 ) ;
while ( V_173 != V_174 ) {
V_173 = F_109 ( V_7 -> V_116 ,
V_7 -> V_66 ,
V_173 + 1 ) ;
V_89 = F_55 ( V_7 , V_173 ) ;
V_171 = F_110 ( V_171 , V_89 ) + V_89 ;
}
V_89 = F_55 ( V_7 , V_173 ) ;
V_172 = F_110 ( V_172 , V_89 ) ;
V_171 = F_110 ( V_171 , V_89 ) ;
V_26 = F_105 ( V_22 , & V_137 , V_171 , V_172 , V_89 ) ;
if ( V_26 )
goto V_175;
V_172 += V_89 ;
V_171 += V_89 ;
}
if ( V_22 -> V_82 ) {
V_89 = F_57 ( V_7 ) ;
V_172 = F_110 ( V_172 , V_89 ) ;
V_171 = F_110 ( V_171 , V_89 ) ;
V_26 = F_105 ( V_22 , & V_137 , V_171 , V_172 , V_89 ) ;
if ( V_26 )
goto V_175;
V_172 += V_89 ;
V_171 += V_89 ;
}
V_22 -> V_163 = F_111 ( V_172 , V_73 ) ;
if ( V_22 -> V_163 == NULL ) {
V_26 = - V_74 ;
goto V_175;
}
return 0 ;
V_175:
F_102 ( V_22 ) ;
return V_26 ;
}
int F_83 ( struct V_6 * V_7 )
{
struct V_1 * V_22 ;
int V_26 ;
F_78 (buffer, &indio_dev->buffer_list, buffer_list) {
V_26 = F_108 ( V_7 , V_22 ) ;
if ( V_26 < 0 )
goto V_175;
}
return 0 ;
V_175:
F_78 (buffer, &indio_dev->buffer_list, buffer_list)
F_102 ( V_22 ) ;
return V_26 ;
}
static void F_112 ( struct V_176 * V_43 )
{
struct V_1 * V_22 = F_113 ( V_43 , struct V_1 , V_43 ) ;
V_22 -> V_4 -> V_177 ( V_22 ) ;
}
struct V_1 * F_62 ( struct V_1 * V_22 )
{
if ( V_22 )
F_114 ( & V_22 -> V_43 ) ;
return V_22 ;
}
void F_67 ( struct V_1 * V_22 )
{
if ( V_22 )
F_115 ( & V_22 -> V_43 , F_112 ) ;
}
