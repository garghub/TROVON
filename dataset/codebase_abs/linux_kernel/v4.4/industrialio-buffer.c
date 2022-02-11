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
T_1 V_23 ;
T_1 V_12 ;
int V_24 ;
if ( ! V_7 -> V_9 )
return - V_11 ;
if ( ! V_21 || ! V_21 -> V_4 -> V_25 )
return - V_26 ;
V_23 = V_21 -> V_27 ;
if ( ! V_23 )
return 0 ;
if ( V_17 -> V_28 & V_29 )
V_12 = 0 ;
else
V_12 = F_6 ( T_1 , V_18 / V_23 , V_21 -> V_30 ) ;
do {
V_24 = F_8 ( V_21 -> V_31 ,
F_5 ( V_7 , V_21 , V_12 , V_18 / V_23 ) ) ;
if ( V_24 )
return V_24 ;
if ( ! V_7 -> V_9 )
return - V_11 ;
V_24 = V_21 -> V_4 -> V_25 ( V_21 , V_18 , V_2 ) ;
if ( V_24 == 0 && ( V_17 -> V_28 & V_29 ) )
V_24 = - V_32 ;
} while ( V_24 == 0 );
return V_24 ;
}
unsigned int F_9 ( struct V_16 * V_17 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 = V_17 -> V_20 ;
struct V_1 * V_21 = V_7 -> V_22 ;
if ( ! V_7 -> V_9 )
return 0 ;
F_10 ( V_17 , & V_21 -> V_31 , V_34 ) ;
if ( F_5 ( V_7 , V_21 , V_21 -> V_30 , 0 ) )
return V_35 | V_36 ;
return 0 ;
}
void F_11 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_22 )
return;
F_12 ( & V_7 -> V_22 -> V_31 ) ;
}
void F_13 ( struct V_1 * V_22 )
{
F_14 ( & V_22 -> V_37 ) ;
F_14 ( & V_22 -> V_3 ) ;
F_15 ( & V_22 -> V_31 ) ;
F_16 ( & V_22 -> V_38 ) ;
V_22 -> V_30 = 1 ;
}
static T_2 F_17 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
char * V_2 )
{
return sprintf ( V_2 , L_1 , F_18 ( V_42 ) -> V_43 -> V_44 ) ;
}
static T_2 F_19 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
char * V_2 )
{
struct V_45 * V_46 = F_18 ( V_42 ) ;
T_5 type = V_46 -> V_43 -> V_47 . V_48 ;
if ( type == V_49 ) {
#ifdef F_20
type = V_50 ;
#else
type = V_51 ;
#endif
}
if ( V_46 -> V_43 -> V_47 . V_52 > 1 )
return sprintf ( V_2 , L_2 ,
V_53 [ type ] ,
V_46 -> V_43 -> V_47 . V_54 ,
V_46 -> V_43 -> V_47 . V_55 ,
V_46 -> V_43 -> V_47 . V_56 ,
V_46 -> V_43 -> V_47 . V_52 ,
V_46 -> V_43 -> V_47 . V_57 ) ;
else
return sprintf ( V_2 , L_3 ,
V_53 [ type ] ,
V_46 -> V_43 -> V_47 . V_54 ,
V_46 -> V_43 -> V_47 . V_55 ,
V_46 -> V_43 -> V_47 . V_56 ,
V_46 -> V_43 -> V_47 . V_57 ) ;
}
static T_2 F_21 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
char * V_2 )
{
int V_24 ;
struct V_6 * V_7 = F_22 ( V_40 ) ;
V_24 = ! ! F_23 ( F_18 ( V_42 ) -> V_58 ,
V_7 -> V_22 -> V_59 ) ;
return sprintf ( V_2 , L_4 , V_24 ) ;
}
static const unsigned long * F_24 ( const unsigned long * V_60 ,
unsigned int V_61 ,
const unsigned long * V_62 ,
bool V_63 )
{
if ( F_25 ( V_62 , V_61 ) )
return NULL ;
while ( * V_60 ) {
if ( V_63 ) {
if ( F_26 ( V_62 , V_60 , V_61 ) )
return V_60 ;
} else {
if ( F_27 ( V_62 , V_60 , V_61 ) )
return V_60 ;
}
V_60 += F_28 ( V_61 ) ;
}
return NULL ;
}
static bool F_29 ( struct V_6 * V_7 ,
const unsigned long * V_62 )
{
if ( ! V_7 -> V_64 -> V_65 )
return true ;
return V_7 -> V_64 -> V_65 ( V_7 , V_62 ) ;
}
static int F_30 ( struct V_6 * V_7 ,
struct V_1 * V_22 , int V_66 )
{
const unsigned long * V_62 ;
unsigned long * V_67 ;
V_67 = F_31 ( sizeof( * V_67 ) *
F_28 ( V_7 -> V_61 ) ,
V_68 ) ;
if ( V_67 == NULL )
return - V_69 ;
if ( ! V_7 -> V_61 ) {
F_32 ( 1 , L_5 ) ;
goto V_70;
}
F_33 ( V_67 , V_22 -> V_59 , V_7 -> V_61 ) ;
F_34 ( V_66 , V_67 ) ;
if ( ! F_29 ( V_7 , V_67 ) )
goto V_70;
if ( V_7 -> V_71 ) {
V_62 = F_24 ( V_7 -> V_71 ,
V_7 -> V_61 ,
V_67 , false ) ;
if ( ! V_62 )
goto V_70;
}
F_33 ( V_22 -> V_59 , V_67 , V_7 -> V_61 ) ;
F_35 ( V_67 ) ;
return 0 ;
V_70:
F_35 ( V_67 ) ;
return - V_26 ;
}
static int F_36 ( struct V_1 * V_22 , int V_66 )
{
F_37 ( V_66 , V_22 -> V_59 ) ;
return 0 ;
}
static T_2 F_38 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
const char * V_2 ,
T_1 V_72 )
{
int V_24 ;
bool V_73 ;
struct V_6 * V_7 = F_22 ( V_40 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
struct V_45 * V_46 = F_18 ( V_42 ) ;
V_24 = F_39 ( V_2 , & V_73 ) ;
if ( V_24 < 0 )
return V_24 ;
F_40 ( & V_7 -> V_74 ) ;
if ( F_1 ( V_7 -> V_22 ) ) {
V_24 = - V_75 ;
goto V_76;
}
V_24 = F_41 ( V_7 , V_22 , V_46 -> V_58 ) ;
if ( V_24 < 0 )
goto V_76;
if ( ! V_73 && V_24 ) {
V_24 = F_36 ( V_22 , V_46 -> V_58 ) ;
if ( V_24 )
goto V_76;
} else if ( V_73 && ! V_24 ) {
V_24 = F_30 ( V_7 , V_22 , V_46 -> V_58 ) ;
if ( V_24 )
goto V_76;
}
V_76:
F_42 ( & V_7 -> V_74 ) ;
return V_24 < 0 ? V_24 : V_72 ;
}
static T_2 F_43 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
char * V_2 )
{
struct V_6 * V_7 = F_22 ( V_40 ) ;
return sprintf ( V_2 , L_4 , V_7 -> V_22 -> V_77 ) ;
}
static T_2 F_44 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
const char * V_2 ,
T_1 V_72 )
{
int V_24 ;
struct V_6 * V_7 = F_22 ( V_40 ) ;
bool V_73 ;
V_24 = F_39 ( V_2 , & V_73 ) ;
if ( V_24 < 0 )
return V_24 ;
F_40 ( & V_7 -> V_74 ) ;
if ( F_1 ( V_7 -> V_22 ) ) {
V_24 = - V_75 ;
goto V_76;
}
V_7 -> V_22 -> V_77 = V_73 ;
V_76:
F_42 ( & V_7 -> V_74 ) ;
return V_24 ? V_24 : V_72 ;
}
static int F_45 ( struct V_6 * V_7 ,
const struct V_78 * V_79 )
{
int V_24 , V_80 = 0 ;
struct V_1 * V_22 = V_7 -> V_22 ;
V_24 = F_46 ( L_6 ,
V_79 ,
& F_17 ,
NULL ,
0 ,
V_81 ,
& V_7 -> V_40 ,
& V_22 -> V_82 ) ;
if ( V_24 )
return V_24 ;
V_80 ++ ;
V_24 = F_46 ( L_7 ,
V_79 ,
& F_19 ,
NULL ,
0 ,
0 ,
& V_7 -> V_40 ,
& V_22 -> V_82 ) ;
if ( V_24 )
return V_24 ;
V_80 ++ ;
if ( V_79 -> type != V_83 )
V_24 = F_46 ( L_8 ,
V_79 ,
& F_21 ,
& F_38 ,
V_79 -> V_44 ,
0 ,
& V_7 -> V_40 ,
& V_22 -> V_82 ) ;
else
V_24 = F_46 ( L_8 ,
V_79 ,
& F_43 ,
& F_44 ,
V_79 -> V_44 ,
0 ,
& V_7 -> V_40 ,
& V_22 -> V_82 ) ;
if ( V_24 )
return V_24 ;
V_80 ++ ;
V_24 = V_80 ;
return V_24 ;
}
static T_2 F_47 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
char * V_2 )
{
struct V_6 * V_7 = F_22 ( V_40 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
return sprintf ( V_2 , L_4 , V_22 -> V_84 ) ;
}
static T_2 F_48 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
const char * V_2 , T_1 V_72 )
{
struct V_6 * V_7 = F_22 ( V_40 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
unsigned int V_85 ;
int V_24 ;
V_24 = F_49 ( V_2 , 10 , & V_85 ) ;
if ( V_24 )
return V_24 ;
if ( V_85 == V_22 -> V_84 )
return V_72 ;
F_40 ( & V_7 -> V_74 ) ;
if ( F_1 ( V_7 -> V_22 ) ) {
V_24 = - V_75 ;
} else {
V_22 -> V_4 -> V_86 ( V_22 , V_85 ) ;
V_24 = 0 ;
}
if ( V_24 )
goto V_87;
if ( V_22 -> V_84 && V_22 -> V_84 < V_22 -> V_30 )
V_22 -> V_30 = V_22 -> V_84 ;
V_87:
F_42 ( & V_7 -> V_74 ) ;
return V_24 ? V_24 : V_72 ;
}
static T_2 F_50 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
char * V_2 )
{
struct V_6 * V_7 = F_22 ( V_40 ) ;
return sprintf ( V_2 , L_4 , F_1 ( V_7 -> V_22 ) ) ;
}
static int F_51 ( struct V_6 * V_7 ,
const unsigned long * V_62 , bool V_88 )
{
const struct V_78 * V_89 ;
unsigned V_90 = 0 ;
int V_84 , V_91 ;
F_52 (i, mask,
indio_dev->masklength) {
V_89 = F_53 ( V_7 , V_91 ) ;
if ( V_89 -> V_47 . V_52 > 1 )
V_84 = V_89 -> V_47 . V_56 / 8 *
V_89 -> V_47 . V_52 ;
else
V_84 = V_89 -> V_47 . V_56 / 8 ;
V_90 = F_54 ( V_90 , V_84 ) ;
V_90 += V_84 ;
}
if ( V_88 ) {
V_89 = F_53 ( V_7 ,
V_7 -> V_92 ) ;
if ( V_89 -> V_47 . V_52 > 1 )
V_84 = V_89 -> V_47 . V_56 / 8 *
V_89 -> V_47 . V_52 ;
else
V_84 = V_89 -> V_47 . V_56 / 8 ;
V_90 = F_54 ( V_90 , V_84 ) ;
V_90 += V_84 ;
}
return V_90 ;
}
static void F_55 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
F_56 ( V_22 ) ;
F_57 ( & V_22 -> V_3 , & V_7 -> V_3 ) ;
}
static void F_58 ( struct V_1 * V_22 )
{
F_59 ( & V_22 -> V_3 ) ;
F_60 ( & V_22 -> V_31 ) ;
F_61 ( V_22 ) ;
}
static void F_62 ( struct V_6 * V_7 )
{
struct V_1 * V_22 , * V_93 ;
F_63 (buffer, _buffer,
&indio_dev->buffer_list, buffer_list)
F_58 ( V_22 ) ;
}
static void F_64 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
unsigned int V_90 ;
if ( ! V_22 -> V_4 -> V_94 )
return;
V_90 = F_51 ( V_7 , V_22 -> V_59 ,
V_22 -> V_77 ) ;
V_22 -> V_4 -> V_94 ( V_22 , V_90 ) ;
}
static int F_65 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
int V_24 ;
F_64 ( V_7 , V_22 ) ;
if ( V_22 -> V_4 -> V_95 ) {
V_24 = V_22 -> V_4 -> V_95 ( V_22 ) ;
if ( V_24 ) {
F_66 ( & V_7 -> V_40 ,
L_9 ,
V_24 ) ;
return V_24 ;
}
}
return 0 ;
}
static void F_67 ( struct V_6 * V_7 ,
const unsigned long * V_62 )
{
if ( ! V_7 -> V_71 )
F_35 ( V_62 ) ;
}
static int F_68 ( struct V_6 * V_7 ,
struct V_1 * V_96 , struct V_1 * V_97 ,
struct V_98 * V_99 )
{
unsigned long * V_100 ;
const unsigned long * V_59 ;
bool V_101 = false ;
struct V_1 * V_22 ;
bool V_77 ;
unsigned int V_102 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
if ( V_97 && ! V_96 &&
F_69 ( & V_7 -> V_3 ) )
return 0 ;
V_102 = V_7 -> V_102 ;
F_70 (buffer, &indio_dev->buffer_list, buffer_list) {
if ( V_22 == V_97 )
continue;
V_102 &= V_22 -> V_4 -> V_102 ;
}
if ( V_96 )
V_102 &= V_96 -> V_4 -> V_102 ;
if ( ( V_102 & V_103 ) && V_7 -> V_104 ) {
V_99 -> V_105 = V_103 ;
} else if ( V_102 & V_106 ) {
if ( V_96 && ! F_2 ( & V_7 -> V_3 ) )
return - V_26 ;
V_99 -> V_105 = V_106 ;
V_101 = true ;
} else if ( V_102 & V_107 ) {
V_99 -> V_105 = V_107 ;
} else {
if ( V_7 -> V_102 & V_103 )
F_66 ( & V_7 -> V_40 , L_10 ) ;
return - V_26 ;
}
V_100 = F_71 ( F_28 ( V_7 -> V_61 ) ,
sizeof( long ) , V_68 ) ;
if ( V_100 == NULL )
return - V_69 ;
V_77 = false ;
F_70 (buffer, &indio_dev->buffer_list, buffer_list) {
if ( V_22 == V_97 )
continue;
F_72 ( V_100 , V_100 , V_22 -> V_59 ,
V_7 -> V_61 ) ;
V_77 |= V_22 -> V_77 ;
}
if ( V_96 ) {
F_72 ( V_100 , V_100 ,
V_96 -> V_59 , V_7 -> V_61 ) ;
V_77 |= V_96 -> V_77 ;
}
if ( V_7 -> V_71 ) {
V_59 = F_24 ( V_7 -> V_71 ,
V_7 -> V_61 ,
V_100 ,
V_101 ) ;
F_35 ( V_100 ) ;
if ( V_59 == NULL )
return - V_26 ;
} else {
V_59 = V_100 ;
}
V_99 -> V_108 = F_51 ( V_7 ,
V_59 , V_77 ) ;
V_99 -> V_59 = V_59 ;
V_99 -> V_77 = V_77 ;
return 0 ;
}
static int F_73 ( struct V_6 * V_7 ,
struct V_98 * V_99 )
{
int V_24 ;
V_7 -> V_109 = V_99 -> V_59 ;
V_7 -> V_77 = V_99 -> V_77 ;
V_7 -> V_108 = V_99 -> V_108 ;
F_74 ( V_7 ) ;
if ( V_7 -> V_64 -> V_110 ) {
V_24 = V_7 -> V_64 -> V_110 ( V_7 ) ;
if ( V_24 ) {
F_66 ( & V_7 -> V_40 ,
L_11 , V_24 ) ;
goto V_111;
}
}
if ( V_7 -> V_9 -> V_112 ) {
V_24 = V_7 -> V_9
-> V_112 ( V_7 ,
V_7 -> V_109 ) ;
if ( V_24 < 0 ) {
F_66 ( & V_7 -> V_40 ,
L_12 ,
V_24 ) ;
goto V_113;
}
}
V_7 -> V_114 = V_99 -> V_105 ;
if ( V_7 -> V_64 -> V_115 ) {
V_24 = V_7 -> V_64 -> V_115 ( V_7 ) ;
if ( V_24 ) {
F_66 ( & V_7 -> V_40 ,
L_13 , V_24 ) ;
goto V_113;
}
}
return 0 ;
V_113:
V_7 -> V_114 = V_116 ;
if ( V_7 -> V_64 -> V_117 )
V_7 -> V_64 -> V_117 ( V_7 ) ;
V_111:
V_7 -> V_109 = NULL ;
return V_24 ;
}
static int F_75 ( struct V_6 * V_7 )
{
int V_24 = 0 ;
int V_118 ;
if ( F_2 ( & V_7 -> V_3 ) )
return 0 ;
if ( V_7 -> V_64 -> V_119 ) {
V_118 = V_7 -> V_64 -> V_119 ( V_7 ) ;
if ( V_118 && ! V_24 )
V_24 = V_118 ;
}
V_7 -> V_114 = V_116 ;
if ( V_7 -> V_64 -> V_117 ) {
V_118 = V_7 -> V_64 -> V_117 ( V_7 ) ;
if ( V_118 && ! V_24 )
V_24 = V_118 ;
}
F_67 ( V_7 , V_7 -> V_109 ) ;
V_7 -> V_109 = NULL ;
return V_24 ;
}
static int F_76 ( struct V_6 * V_7 ,
struct V_1 * V_96 ,
struct V_1 * V_97 )
{
struct V_98 V_120 ;
int V_24 ;
V_24 = F_68 ( V_7 , V_96 , V_97 ,
& V_120 ) ;
if ( V_24 )
return V_24 ;
if ( V_96 ) {
V_24 = F_65 ( V_7 , V_96 ) ;
if ( V_24 )
goto V_121;
}
V_24 = F_75 ( V_7 ) ;
if ( V_24 )
goto V_122;
if ( V_97 )
F_58 ( V_97 ) ;
if ( V_96 )
F_55 ( V_7 , V_96 ) ;
if ( F_2 ( & V_7 -> V_3 ) )
return 0 ;
V_24 = F_73 ( V_7 , & V_120 ) ;
if ( V_24 )
goto V_122;
return 0 ;
V_122:
F_62 ( V_7 ) ;
V_121:
F_67 ( V_7 , V_120 . V_59 ) ;
return V_24 ;
}
int F_77 ( struct V_6 * V_7 ,
struct V_1 * V_96 ,
struct V_1 * V_97 )
{
int V_24 ;
if ( V_96 == V_97 )
return 0 ;
F_40 ( & V_7 -> V_123 ) ;
F_40 ( & V_7 -> V_74 ) ;
if ( V_96 && F_1 ( V_96 ) )
V_96 = NULL ;
if ( V_97 && ! F_1 ( V_97 ) )
V_97 = NULL ;
if ( ! V_96 && ! V_97 ) {
V_24 = 0 ;
goto V_124;
}
if ( V_7 -> V_9 == NULL ) {
V_24 = - V_11 ;
goto V_124;
}
V_24 = F_76 ( V_7 , V_96 , V_97 ) ;
V_124:
F_42 ( & V_7 -> V_74 ) ;
F_42 ( & V_7 -> V_123 ) ;
return V_24 ;
}
void F_78 ( struct V_6 * V_7 )
{
F_75 ( V_7 ) ;
F_62 ( V_7 ) ;
}
static T_2 F_79 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
const char * V_2 ,
T_1 V_72 )
{
int V_24 ;
bool V_125 ;
struct V_6 * V_7 = F_22 ( V_40 ) ;
bool V_126 ;
V_24 = F_39 ( V_2 , & V_125 ) ;
if ( V_24 < 0 )
return V_24 ;
F_40 ( & V_7 -> V_74 ) ;
V_126 = F_1 ( V_7 -> V_22 ) ;
if ( V_126 == V_125 )
goto V_127;
if ( V_125 )
V_24 = F_76 ( V_7 ,
V_7 -> V_22 , NULL ) ;
else
V_24 = F_76 ( V_7 ,
NULL , V_7 -> V_22 ) ;
V_127:
F_42 ( & V_7 -> V_74 ) ;
return ( V_24 < 0 ) ? V_24 : V_72 ;
}
static T_2 F_80 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
char * V_2 )
{
struct V_6 * V_7 = F_22 ( V_40 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
return sprintf ( V_2 , L_1 , V_22 -> V_30 ) ;
}
static T_2 F_81 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
const char * V_2 ,
T_1 V_72 )
{
struct V_6 * V_7 = F_22 ( V_40 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
unsigned int V_85 ;
int V_24 ;
V_24 = F_49 ( V_2 , 10 , & V_85 ) ;
if ( V_24 )
return V_24 ;
if ( ! V_85 )
return - V_26 ;
F_40 ( & V_7 -> V_74 ) ;
if ( V_85 > V_22 -> V_84 ) {
V_24 = - V_26 ;
goto V_87;
}
if ( F_1 ( V_7 -> V_22 ) ) {
V_24 = - V_75 ;
goto V_87;
}
V_22 -> V_30 = V_85 ;
if ( V_7 -> V_9 -> V_128 )
V_7 -> V_9 -> V_128 ( V_7 , V_85 ) ;
V_87:
F_42 ( & V_7 -> V_74 ) ;
return V_24 ? V_24 : V_72 ;
}
int F_82 ( struct V_6 * V_7 )
{
struct V_45 * V_129 ;
struct V_130 * * V_42 ;
struct V_1 * V_22 = V_7 -> V_22 ;
int V_24 , V_91 , V_131 , V_80 , V_132 = 0 ;
const struct V_78 * V_133 ;
V_133 = V_7 -> V_133 ;
if ( V_133 ) {
int V_134 = V_7 -> V_61 ;
for ( V_91 = 0 ; V_91 < V_7 -> V_135 ; V_91 ++ )
V_134 = F_83 ( V_134 , V_133 [ V_91 ] . V_44 + 1 ) ;
V_7 -> V_61 = V_134 ;
}
if ( ! V_22 )
return 0 ;
V_80 = 0 ;
if ( V_22 -> V_136 ) {
while ( V_22 -> V_136 [ V_80 ] != NULL )
V_80 ++ ;
}
V_42 = F_71 ( V_80 + F_84 ( V_137 ) + 1 ,
sizeof( struct V_130 * ) , V_68 ) ;
if ( ! V_42 )
return - V_69 ;
memcpy ( V_42 , V_137 , sizeof( V_137 ) ) ;
if ( ! V_22 -> V_4 -> V_86 )
V_42 [ 0 ] = & V_138 . V_42 ;
if ( V_22 -> V_136 )
memcpy ( & V_42 [ F_84 ( V_137 ) ] , V_22 -> V_136 ,
sizeof( struct V_130 * ) * V_80 ) ;
V_42 [ V_80 + F_84 ( V_137 ) ] = NULL ;
V_22 -> V_139 . V_140 = L_14 ;
V_22 -> V_139 . V_136 = V_42 ;
V_7 -> V_141 [ V_7 -> V_142 ++ ] = & V_22 -> V_139 ;
if ( V_22 -> V_143 != NULL ) {
V_42 = V_22 -> V_143 -> V_136 ;
while ( * V_42 ++ != NULL )
V_132 ++ ;
}
V_80 = V_132 ;
F_14 ( & V_22 -> V_82 ) ;
V_133 = V_7 -> V_133 ;
if ( V_133 ) {
for ( V_91 = 0 ; V_91 < V_7 -> V_135 ; V_91 ++ ) {
if ( V_133 [ V_91 ] . V_44 < 0 )
continue;
V_24 = F_45 ( V_7 ,
& V_133 [ V_91 ] ) ;
if ( V_24 < 0 )
goto V_144;
V_80 += V_24 ;
if ( V_133 [ V_91 ] . type == V_83 )
V_7 -> V_92 =
V_133 [ V_91 ] . V_44 ;
}
if ( V_7 -> V_61 && V_22 -> V_59 == NULL ) {
V_22 -> V_59 = F_71 ( F_28 ( V_7 -> V_61 ) ,
sizeof( * V_22 -> V_59 ) ,
V_68 ) ;
if ( V_22 -> V_59 == NULL ) {
V_24 = - V_69 ;
goto V_144;
}
}
}
V_22 -> V_145 . V_140 = V_146 ;
V_22 -> V_145 . V_136 = F_71 ( V_80 + 1 ,
sizeof( V_22 -> V_145 . V_136 [ 0 ] ) ,
V_68 ) ;
if ( V_22 -> V_145 . V_136 == NULL ) {
V_24 = - V_69 ;
goto V_147;
}
if ( V_22 -> V_143 )
memcpy ( V_22 -> V_145 . V_136 , V_22 -> V_143 ,
sizeof( V_22 -> V_145 . V_136 [ 0 ] ) * V_132 ) ;
V_131 = V_132 ;
F_70 (p, &buffer->scan_el_dev_attr_list, l)
V_22 -> V_145 . V_136 [ V_131 ++ ] = & V_129 -> V_148 . V_42 ;
V_7 -> V_141 [ V_7 -> V_142 ++ ] = & V_22 -> V_145 ;
return 0 ;
V_147:
F_35 ( V_22 -> V_59 ) ;
V_144:
F_85 ( & V_22 -> V_82 ) ;
F_35 ( V_7 -> V_22 -> V_139 . V_136 ) ;
return V_24 ;
}
void F_86 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_22 )
return;
F_35 ( V_7 -> V_22 -> V_59 ) ;
F_35 ( V_7 -> V_22 -> V_139 . V_136 ) ;
F_35 ( V_7 -> V_22 -> V_145 . V_136 ) ;
F_85 ( & V_7 -> V_22 -> V_82 ) ;
}
bool F_87 ( struct V_6 * V_7 ,
const unsigned long * V_62 )
{
return F_88 ( V_62 , V_7 -> V_61 ) == 1 ;
}
int F_41 ( struct V_6 * V_7 ,
struct V_1 * V_22 , int V_66 )
{
if ( V_66 > V_7 -> V_61 )
return - V_26 ;
if ( ! V_22 -> V_59 )
return 0 ;
return ! ! F_23 ( V_66 , V_22 -> V_59 ) ;
}
static const void * F_89 ( struct V_1 * V_22 ,
const void * V_149 )
{
struct V_150 * V_151 ;
if ( F_2 ( & V_22 -> V_37 ) )
return V_149 ;
F_70 (t, &buffer->demux_list, l)
memcpy ( V_22 -> V_152 + V_151 -> V_153 ,
V_149 + V_151 -> V_154 , V_151 -> V_84 ) ;
return V_22 -> V_152 ;
}
static int F_90 ( struct V_1 * V_22 , const void * V_155 )
{
const void * V_156 = F_89 ( V_22 , V_155 ) ;
int V_24 ;
V_24 = V_22 -> V_4 -> V_157 ( V_22 , V_156 ) ;
if ( V_24 )
return V_24 ;
F_91 ( & V_22 -> V_31 , V_35 | V_36 ) ;
return 0 ;
}
static void F_92 ( struct V_1 * V_22 )
{
struct V_150 * V_129 , * V_158 ;
F_63 (p, q, &buffer->demux_list, l) {
F_93 ( & V_129 -> V_159 ) ;
F_35 ( V_129 ) ;
}
}
int F_94 ( struct V_6 * V_7 , const void * V_155 )
{
int V_24 ;
struct V_1 * V_2 ;
F_70 (buf, &indio_dev->buffer_list, buffer_list) {
V_24 = F_90 ( V_2 , V_155 ) ;
if ( V_24 < 0 )
return V_24 ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_22 ,
struct V_150 * * V_129 , unsigned int V_160 , unsigned int V_161 ,
unsigned int V_84 )
{
if ( * V_129 && ( * V_129 ) -> V_154 + ( * V_129 ) -> V_84 == V_160 &&
( * V_129 ) -> V_153 + ( * V_129 ) -> V_84 == V_161 ) {
( * V_129 ) -> V_84 += V_84 ;
} else {
* V_129 = F_31 ( sizeof( * * V_129 ) , V_68 ) ;
if ( * V_129 == NULL )
return - V_69 ;
( * V_129 ) -> V_154 = V_160 ;
( * V_129 ) -> V_153 = V_161 ;
( * V_129 ) -> V_84 = V_84 ;
F_96 ( & ( * V_129 ) -> V_159 , & V_22 -> V_37 ) ;
}
return 0 ;
}
static int F_97 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
const struct V_78 * V_89 ;
int V_24 , V_162 = - 1 , V_163 , V_84 ;
unsigned V_160 = 0 , V_161 = 0 ;
struct V_150 * V_129 = NULL ;
F_92 ( V_22 ) ;
F_35 ( V_22 -> V_152 ) ;
V_22 -> V_152 = NULL ;
if ( F_26 ( V_7 -> V_109 ,
V_22 -> V_59 ,
V_7 -> V_61 ) )
return 0 ;
F_52 (out_ind,
buffer->scan_mask,
indio_dev->masklength) {
V_162 = F_98 ( V_7 -> V_109 ,
V_7 -> V_61 ,
V_162 + 1 ) ;
while ( V_162 != V_163 ) {
V_162 = F_98 ( V_7 -> V_109 ,
V_7 -> V_61 ,
V_162 + 1 ) ;
V_89 = F_53 ( V_7 , V_162 ) ;
if ( V_89 -> V_47 . V_52 > 1 )
V_84 = V_89 -> V_47 . V_56 / 8 *
V_89 -> V_47 . V_52 ;
else
V_84 = V_89 -> V_47 . V_56 / 8 ;
V_160 = F_99 ( V_160 , V_84 ) + V_84 ;
}
V_89 = F_53 ( V_7 , V_162 ) ;
if ( V_89 -> V_47 . V_52 > 1 )
V_84 = V_89 -> V_47 . V_56 / 8 *
V_89 -> V_47 . V_52 ;
else
V_84 = V_89 -> V_47 . V_56 / 8 ;
V_161 = F_99 ( V_161 , V_84 ) ;
V_160 = F_99 ( V_160 , V_84 ) ;
V_24 = F_95 ( V_22 , & V_129 , V_160 , V_161 , V_84 ) ;
if ( V_24 )
goto V_164;
V_161 += V_84 ;
V_160 += V_84 ;
}
if ( V_22 -> V_77 ) {
V_89 = F_53 ( V_7 ,
V_7 -> V_92 ) ;
if ( V_89 -> V_47 . V_52 > 1 )
V_84 = V_89 -> V_47 . V_56 / 8 *
V_89 -> V_47 . V_52 ;
else
V_84 = V_89 -> V_47 . V_56 / 8 ;
V_161 = F_99 ( V_161 , V_84 ) ;
V_160 = F_99 ( V_160 , V_84 ) ;
V_24 = F_95 ( V_22 , & V_129 , V_160 , V_161 , V_84 ) ;
if ( V_24 )
goto V_164;
V_161 += V_84 ;
V_160 += V_84 ;
}
V_22 -> V_152 = F_100 ( V_161 , V_68 ) ;
if ( V_22 -> V_152 == NULL ) {
V_24 = - V_69 ;
goto V_164;
}
return 0 ;
V_164:
F_92 ( V_22 ) ;
return V_24 ;
}
int F_74 ( struct V_6 * V_7 )
{
struct V_1 * V_22 ;
int V_24 ;
F_70 (buffer, &indio_dev->buffer_list, buffer_list) {
V_24 = F_97 ( V_7 , V_22 ) ;
if ( V_24 < 0 )
goto V_164;
}
return 0 ;
V_164:
F_70 (buffer, &indio_dev->buffer_list, buffer_list)
F_92 ( V_22 ) ;
return V_24 ;
}
static void F_101 ( struct V_165 * V_38 )
{
struct V_1 * V_22 = F_102 ( V_38 , struct V_1 , V_38 ) ;
V_22 -> V_4 -> V_166 ( V_22 ) ;
}
struct V_1 * F_56 ( struct V_1 * V_22 )
{
if ( V_22 )
F_103 ( & V_22 -> V_38 ) ;
return V_22 ;
}
void F_61 ( struct V_1 * V_22 )
{
if ( V_22 )
F_104 ( & V_22 -> V_38 , F_101 ) ;
}
