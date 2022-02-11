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
if ( ! V_12 && ! V_14 && V_13 )
F_4 ( V_7 , V_2 , V_13 ) ;
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
T_1 V_12 = 0 ;
T_1 V_24 ;
int V_25 ;
if ( ! V_7 -> V_9 )
return - V_11 ;
if ( ! V_21 || ! V_21 -> V_4 -> V_26 )
return - V_27 ;
V_23 = V_21 -> V_28 ;
if ( ! V_23 )
return 0 ;
V_24 = F_6 ( T_1 , V_18 / V_23 , V_21 -> V_29 ) ;
if ( ! ( V_17 -> V_30 & V_31 ) )
V_12 = V_24 ;
do {
V_25 = F_8 ( V_21 -> V_32 ,
F_5 ( V_7 , V_21 , V_12 , V_24 ) ) ;
if ( V_25 )
return V_25 ;
if ( ! V_7 -> V_9 )
return - V_11 ;
V_25 = V_21 -> V_4 -> V_26 ( V_21 , V_18 , V_2 ) ;
if ( V_25 == 0 && ( V_17 -> V_30 & V_31 ) )
V_25 = - V_33 ;
} while ( V_25 == 0 );
return V_25 ;
}
unsigned int F_9 ( struct V_16 * V_17 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 = V_17 -> V_20 ;
struct V_1 * V_21 = V_7 -> V_22 ;
if ( ! V_7 -> V_9 )
return - V_11 ;
F_10 ( V_17 , & V_21 -> V_32 , V_35 ) ;
if ( F_5 ( V_7 , V_21 , V_21 -> V_29 , 0 ) )
return V_36 | V_37 ;
return 0 ;
}
void F_11 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_22 )
return;
F_12 ( & V_7 -> V_22 -> V_32 ) ;
}
void F_13 ( struct V_1 * V_22 )
{
F_14 ( & V_22 -> V_38 ) ;
F_14 ( & V_22 -> V_3 ) ;
F_15 ( & V_22 -> V_32 ) ;
F_16 ( & V_22 -> V_39 ) ;
V_22 -> V_29 = 1 ;
}
static T_2 F_17 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_2 )
{
return sprintf ( V_2 , L_1 , F_18 ( V_43 ) -> V_44 -> V_45 ) ;
}
static T_2 F_19 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_2 )
{
struct V_46 * V_47 = F_18 ( V_43 ) ;
T_5 type = V_47 -> V_44 -> V_48 . V_49 ;
if ( type == V_50 ) {
#ifdef F_20
type = V_51 ;
#else
type = V_52 ;
#endif
}
if ( V_47 -> V_44 -> V_48 . V_53 > 1 )
return sprintf ( V_2 , L_2 ,
V_54 [ type ] ,
V_47 -> V_44 -> V_48 . V_55 ,
V_47 -> V_44 -> V_48 . V_56 ,
V_47 -> V_44 -> V_48 . V_57 ,
V_47 -> V_44 -> V_48 . V_53 ,
V_47 -> V_44 -> V_48 . V_58 ) ;
else
return sprintf ( V_2 , L_3 ,
V_54 [ type ] ,
V_47 -> V_44 -> V_48 . V_55 ,
V_47 -> V_44 -> V_48 . V_56 ,
V_47 -> V_44 -> V_48 . V_57 ,
V_47 -> V_44 -> V_48 . V_58 ) ;
}
static T_2 F_21 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_2 )
{
int V_25 ;
struct V_6 * V_7 = F_22 ( V_41 ) ;
V_25 = ! ! F_23 ( F_18 ( V_43 ) -> V_59 ,
V_7 -> V_22 -> V_60 ) ;
return sprintf ( V_2 , L_4 , V_25 ) ;
}
static const unsigned long * F_24 ( const unsigned long * V_61 ,
unsigned int V_62 ,
const unsigned long * V_63 ,
bool V_64 )
{
if ( F_25 ( V_63 , V_62 ) )
return NULL ;
while ( * V_61 ) {
if ( V_64 ) {
if ( F_26 ( V_63 , V_61 , V_62 ) )
return V_61 ;
} else {
if ( F_27 ( V_63 , V_61 , V_62 ) )
return V_61 ;
}
V_61 += F_28 ( V_62 ) ;
}
return NULL ;
}
static bool F_29 ( struct V_6 * V_7 ,
const unsigned long * V_63 )
{
if ( ! V_7 -> V_65 -> V_66 )
return true ;
return V_7 -> V_65 -> V_66 ( V_7 , V_63 ) ;
}
static int F_30 ( struct V_6 * V_7 ,
struct V_1 * V_22 , int V_67 )
{
const unsigned long * V_63 ;
unsigned long * V_68 ;
V_68 = F_31 ( sizeof( * V_68 ) *
F_28 ( V_7 -> V_62 ) ,
V_69 ) ;
if ( V_68 == NULL )
return - V_70 ;
if ( ! V_7 -> V_62 ) {
F_32 ( L_5 ) ;
goto V_71;
}
F_33 ( V_68 , V_22 -> V_60 , V_7 -> V_62 ) ;
F_34 ( V_67 , V_68 ) ;
if ( ! F_29 ( V_7 , V_68 ) )
goto V_71;
if ( V_7 -> V_72 ) {
V_63 = F_24 ( V_7 -> V_72 ,
V_7 -> V_62 ,
V_68 , false ) ;
if ( ! V_63 )
goto V_71;
}
F_33 ( V_22 -> V_60 , V_68 , V_7 -> V_62 ) ;
F_35 ( V_68 ) ;
return 0 ;
V_71:
F_35 ( V_68 ) ;
return - V_27 ;
}
static int F_36 ( struct V_1 * V_22 , int V_67 )
{
F_37 ( V_67 , V_22 -> V_60 ) ;
return 0 ;
}
static T_2 F_38 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_2 ,
T_1 V_73 )
{
int V_25 ;
bool V_74 ;
struct V_6 * V_7 = F_22 ( V_41 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
struct V_46 * V_47 = F_18 ( V_43 ) ;
V_25 = F_39 ( V_2 , & V_74 ) ;
if ( V_25 < 0 )
return V_25 ;
F_40 ( & V_7 -> V_75 ) ;
if ( F_1 ( V_7 -> V_22 ) ) {
V_25 = - V_76 ;
goto V_77;
}
V_25 = F_41 ( V_7 , V_22 , V_47 -> V_59 ) ;
if ( V_25 < 0 )
goto V_77;
if ( ! V_74 && V_25 ) {
V_25 = F_36 ( V_22 , V_47 -> V_59 ) ;
if ( V_25 )
goto V_77;
} else if ( V_74 && ! V_25 ) {
V_25 = F_30 ( V_7 , V_22 , V_47 -> V_59 ) ;
if ( V_25 )
goto V_77;
}
V_77:
F_42 ( & V_7 -> V_75 ) ;
return V_25 < 0 ? V_25 : V_73 ;
}
static T_2 F_43 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_2 )
{
struct V_6 * V_7 = F_22 ( V_41 ) ;
return sprintf ( V_2 , L_4 , V_7 -> V_22 -> V_78 ) ;
}
static T_2 F_44 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_2 ,
T_1 V_73 )
{
int V_25 ;
struct V_6 * V_7 = F_22 ( V_41 ) ;
bool V_74 ;
V_25 = F_39 ( V_2 , & V_74 ) ;
if ( V_25 < 0 )
return V_25 ;
F_40 ( & V_7 -> V_75 ) ;
if ( F_1 ( V_7 -> V_22 ) ) {
V_25 = - V_76 ;
goto V_77;
}
V_7 -> V_22 -> V_78 = V_74 ;
V_77:
F_42 ( & V_7 -> V_75 ) ;
return V_25 ? V_25 : V_73 ;
}
static int F_45 ( struct V_6 * V_7 ,
const struct V_79 * V_80 )
{
int V_25 , V_81 = 0 ;
struct V_1 * V_22 = V_7 -> V_22 ;
V_25 = F_46 ( L_6 ,
V_80 ,
& F_17 ,
NULL ,
0 ,
V_82 ,
& V_7 -> V_41 ,
& V_22 -> V_83 ) ;
if ( V_25 )
return V_25 ;
V_81 ++ ;
V_25 = F_46 ( L_7 ,
V_80 ,
& F_19 ,
NULL ,
0 ,
0 ,
& V_7 -> V_41 ,
& V_22 -> V_83 ) ;
if ( V_25 )
return V_25 ;
V_81 ++ ;
if ( V_80 -> type != V_84 )
V_25 = F_46 ( L_8 ,
V_80 ,
& F_21 ,
& F_38 ,
V_80 -> V_45 ,
0 ,
& V_7 -> V_41 ,
& V_22 -> V_83 ) ;
else
V_25 = F_46 ( L_8 ,
V_80 ,
& F_43 ,
& F_44 ,
V_80 -> V_45 ,
0 ,
& V_7 -> V_41 ,
& V_22 -> V_83 ) ;
if ( V_25 )
return V_25 ;
V_81 ++ ;
V_25 = V_81 ;
return V_25 ;
}
static T_2 F_47 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_2 )
{
struct V_6 * V_7 = F_22 ( V_41 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
return sprintf ( V_2 , L_4 , V_22 -> V_85 ) ;
}
static T_2 F_48 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_2 , T_1 V_73 )
{
struct V_6 * V_7 = F_22 ( V_41 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
unsigned int V_86 ;
int V_25 ;
V_25 = F_49 ( V_2 , 10 , & V_86 ) ;
if ( V_25 )
return V_25 ;
if ( V_86 == V_22 -> V_85 )
return V_73 ;
F_40 ( & V_7 -> V_75 ) ;
if ( F_1 ( V_7 -> V_22 ) ) {
V_25 = - V_76 ;
} else {
V_22 -> V_4 -> V_87 ( V_22 , V_86 ) ;
V_25 = 0 ;
}
if ( V_25 )
goto V_88;
if ( V_22 -> V_85 && V_22 -> V_85 < V_22 -> V_29 )
V_22 -> V_29 = V_22 -> V_85 ;
V_88:
F_42 ( & V_7 -> V_75 ) ;
return V_25 ? V_25 : V_73 ;
}
static T_2 F_50 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_2 )
{
struct V_6 * V_7 = F_22 ( V_41 ) ;
return sprintf ( V_2 , L_4 , F_1 ( V_7 -> V_22 ) ) ;
}
static int F_51 ( struct V_6 * V_7 ,
const unsigned long * V_63 , bool V_89 )
{
const struct V_79 * V_90 ;
unsigned V_91 = 0 ;
int V_85 , V_92 ;
F_52 (i, mask,
indio_dev->masklength) {
V_90 = F_53 ( V_7 , V_92 ) ;
if ( V_90 -> V_48 . V_53 > 1 )
V_85 = V_90 -> V_48 . V_57 / 8 *
V_90 -> V_48 . V_53 ;
else
V_85 = V_90 -> V_48 . V_57 / 8 ;
V_91 = F_54 ( V_91 , V_85 ) ;
V_91 += V_85 ;
}
if ( V_89 ) {
V_90 = F_53 ( V_7 ,
V_7 -> V_93 ) ;
if ( V_90 -> V_48 . V_53 > 1 )
V_85 = V_90 -> V_48 . V_57 / 8 *
V_90 -> V_48 . V_53 ;
else
V_85 = V_90 -> V_48 . V_57 / 8 ;
V_91 = F_54 ( V_91 , V_85 ) ;
V_91 += V_85 ;
}
return V_91 ;
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
F_60 ( & V_22 -> V_32 ) ;
F_61 ( V_22 ) ;
}
static void F_62 ( struct V_6 * V_7 )
{
struct V_1 * V_22 , * V_94 ;
F_63 (buffer, _buffer,
&indio_dev->buffer_list, buffer_list)
F_58 ( V_22 ) ;
}
static void F_64 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
unsigned int V_91 ;
if ( ! V_22 -> V_4 -> V_95 )
return;
V_91 = F_51 ( V_7 , V_22 -> V_60 ,
V_22 -> V_78 ) ;
V_22 -> V_4 -> V_95 ( V_22 , V_91 ) ;
}
static int F_65 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
int V_25 ;
F_64 ( V_7 , V_22 ) ;
if ( V_22 -> V_4 -> V_96 ) {
V_25 = V_22 -> V_4 -> V_96 ( V_22 ) ;
if ( V_25 ) {
F_66 ( & V_7 -> V_41 ,
L_9 ,
V_25 ) ;
return V_25 ;
}
}
return 0 ;
}
static void F_67 ( struct V_6 * V_7 ,
const unsigned long * V_63 )
{
if ( ! V_7 -> V_72 )
F_35 ( V_63 ) ;
}
static int F_68 ( struct V_6 * V_7 ,
struct V_1 * V_97 , struct V_1 * V_98 ,
struct V_99 * V_100 )
{
unsigned long * V_101 ;
const unsigned long * V_60 ;
bool V_102 = false ;
struct V_1 * V_22 ;
bool V_78 ;
unsigned int V_103 ;
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
if ( V_98 && ! V_97 &&
F_69 ( & V_7 -> V_3 ) )
return 0 ;
V_103 = V_7 -> V_103 ;
F_70 (buffer, &indio_dev->buffer_list, buffer_list) {
if ( V_22 == V_98 )
continue;
V_103 &= V_22 -> V_4 -> V_103 ;
}
if ( V_97 )
V_103 &= V_97 -> V_4 -> V_103 ;
if ( ( V_103 & V_104 ) && V_7 -> V_105 ) {
V_100 -> V_106 = V_104 ;
} else if ( V_103 & V_107 ) {
if ( V_97 && ! F_2 ( & V_7 -> V_3 ) )
return - V_27 ;
V_100 -> V_106 = V_107 ;
V_102 = true ;
} else if ( V_103 & V_108 ) {
V_100 -> V_106 = V_108 ;
} else {
if ( V_7 -> V_103 & V_104 )
F_66 ( & V_7 -> V_41 , L_10 ) ;
return - V_27 ;
}
V_101 = F_71 ( F_28 ( V_7 -> V_62 ) ,
sizeof( long ) , V_69 ) ;
if ( V_101 == NULL )
return - V_70 ;
V_78 = false ;
F_70 (buffer, &indio_dev->buffer_list, buffer_list) {
if ( V_22 == V_98 )
continue;
F_72 ( V_101 , V_101 , V_22 -> V_60 ,
V_7 -> V_62 ) ;
V_78 |= V_22 -> V_78 ;
}
if ( V_97 ) {
F_72 ( V_101 , V_101 ,
V_97 -> V_60 , V_7 -> V_62 ) ;
V_78 |= V_97 -> V_78 ;
}
if ( V_7 -> V_72 ) {
V_60 = F_24 ( V_7 -> V_72 ,
V_7 -> V_62 ,
V_101 ,
V_102 ) ;
F_35 ( V_101 ) ;
if ( V_60 == NULL )
return - V_27 ;
} else {
V_60 = V_101 ;
}
V_100 -> V_109 = F_51 ( V_7 ,
V_60 , V_78 ) ;
V_100 -> V_60 = V_60 ;
V_100 -> V_78 = V_78 ;
return 0 ;
}
static int F_73 ( struct V_6 * V_7 ,
struct V_99 * V_100 )
{
int V_25 ;
V_7 -> V_110 = V_100 -> V_60 ;
V_7 -> V_78 = V_100 -> V_78 ;
V_7 -> V_109 = V_100 -> V_109 ;
F_74 ( V_7 ) ;
if ( V_7 -> V_65 -> V_111 ) {
V_25 = V_7 -> V_65 -> V_111 ( V_7 ) ;
if ( V_25 ) {
F_66 ( & V_7 -> V_41 ,
L_11 , V_25 ) ;
goto V_112;
}
}
if ( V_7 -> V_9 -> V_113 ) {
V_25 = V_7 -> V_9
-> V_113 ( V_7 ,
V_7 -> V_110 ) ;
if ( V_25 < 0 ) {
F_66 ( & V_7 -> V_41 ,
L_12 ,
V_25 ) ;
goto V_114;
}
}
V_7 -> V_115 = V_100 -> V_106 ;
if ( V_7 -> V_65 -> V_116 ) {
V_25 = V_7 -> V_65 -> V_116 ( V_7 ) ;
if ( V_25 ) {
F_66 ( & V_7 -> V_41 ,
L_13 , V_25 ) ;
goto V_114;
}
}
return 0 ;
V_114:
V_7 -> V_115 = V_117 ;
if ( V_7 -> V_65 -> V_118 )
V_7 -> V_65 -> V_118 ( V_7 ) ;
V_112:
V_7 -> V_110 = NULL ;
return V_25 ;
}
static int F_75 ( struct V_6 * V_7 )
{
int V_25 = 0 ;
int V_119 ;
if ( F_2 ( & V_7 -> V_3 ) )
return 0 ;
if ( V_7 -> V_65 -> V_120 ) {
V_119 = V_7 -> V_65 -> V_120 ( V_7 ) ;
if ( V_119 && ! V_25 )
V_25 = V_119 ;
}
V_7 -> V_115 = V_117 ;
if ( V_7 -> V_65 -> V_118 ) {
V_119 = V_7 -> V_65 -> V_118 ( V_7 ) ;
if ( V_119 && ! V_25 )
V_25 = V_119 ;
}
F_67 ( V_7 , V_7 -> V_110 ) ;
V_7 -> V_110 = NULL ;
return V_25 ;
}
static int F_76 ( struct V_6 * V_7 ,
struct V_1 * V_97 ,
struct V_1 * V_98 )
{
struct V_99 V_121 ;
int V_25 ;
V_25 = F_68 ( V_7 , V_97 , V_98 ,
& V_121 ) ;
if ( V_25 )
return V_25 ;
if ( V_97 ) {
V_25 = F_65 ( V_7 , V_97 ) ;
if ( V_25 )
goto V_122;
}
V_25 = F_75 ( V_7 ) ;
if ( V_25 )
goto V_123;
if ( V_98 )
F_58 ( V_98 ) ;
if ( V_97 )
F_55 ( V_7 , V_97 ) ;
if ( F_2 ( & V_7 -> V_3 ) )
return 0 ;
V_25 = F_73 ( V_7 , & V_121 ) ;
if ( V_25 )
goto V_123;
return 0 ;
V_123:
F_62 ( V_7 ) ;
V_122:
F_67 ( V_7 , V_121 . V_60 ) ;
return V_25 ;
}
int F_77 ( struct V_6 * V_7 ,
struct V_1 * V_97 ,
struct V_1 * V_98 )
{
int V_25 ;
if ( V_97 == V_98 )
return 0 ;
F_40 ( & V_7 -> V_124 ) ;
F_40 ( & V_7 -> V_75 ) ;
if ( V_97 && F_1 ( V_97 ) )
V_97 = NULL ;
if ( V_98 && ! F_1 ( V_98 ) )
V_98 = NULL ;
if ( ! V_97 && ! V_98 ) {
V_25 = 0 ;
goto V_125;
}
if ( V_7 -> V_9 == NULL ) {
V_25 = - V_11 ;
goto V_125;
}
V_25 = F_76 ( V_7 , V_97 , V_98 ) ;
V_125:
F_42 ( & V_7 -> V_75 ) ;
F_42 ( & V_7 -> V_124 ) ;
return V_25 ;
}
void F_78 ( struct V_6 * V_7 )
{
F_75 ( V_7 ) ;
F_62 ( V_7 ) ;
}
static T_2 F_79 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_2 ,
T_1 V_73 )
{
int V_25 ;
bool V_126 ;
struct V_6 * V_7 = F_22 ( V_41 ) ;
bool V_127 ;
V_25 = F_39 ( V_2 , & V_126 ) ;
if ( V_25 < 0 )
return V_25 ;
F_40 ( & V_7 -> V_75 ) ;
V_127 = F_1 ( V_7 -> V_22 ) ;
if ( V_127 == V_126 )
goto V_128;
if ( V_126 )
V_25 = F_76 ( V_7 ,
V_7 -> V_22 , NULL ) ;
else
V_25 = F_76 ( V_7 ,
NULL , V_7 -> V_22 ) ;
V_128:
F_42 ( & V_7 -> V_75 ) ;
return ( V_25 < 0 ) ? V_25 : V_73 ;
}
static T_2 F_80 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_2 )
{
struct V_6 * V_7 = F_22 ( V_41 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
return sprintf ( V_2 , L_1 , V_22 -> V_29 ) ;
}
static T_2 F_81 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_2 ,
T_1 V_73 )
{
struct V_6 * V_7 = F_22 ( V_41 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
unsigned int V_86 ;
int V_25 ;
V_25 = F_49 ( V_2 , 10 , & V_86 ) ;
if ( V_25 )
return V_25 ;
if ( ! V_86 )
return - V_27 ;
F_40 ( & V_7 -> V_75 ) ;
if ( V_86 > V_22 -> V_85 ) {
V_25 = - V_27 ;
goto V_88;
}
if ( F_1 ( V_7 -> V_22 ) ) {
V_25 = - V_76 ;
goto V_88;
}
V_22 -> V_29 = V_86 ;
if ( V_7 -> V_9 -> V_129 )
V_7 -> V_9 -> V_129 ( V_7 , V_86 ) ;
V_88:
F_42 ( & V_7 -> V_75 ) ;
return V_25 ? V_25 : V_73 ;
}
int F_82 ( struct V_6 * V_7 )
{
struct V_46 * V_130 ;
struct V_131 * * V_43 ;
struct V_1 * V_22 = V_7 -> V_22 ;
int V_25 , V_92 , V_132 , V_81 , V_133 = 0 ;
const struct V_79 * V_134 ;
V_134 = V_7 -> V_134 ;
if ( V_134 ) {
int V_135 = V_7 -> V_62 ;
for ( V_92 = 0 ; V_92 < V_7 -> V_136 ; V_92 ++ )
V_135 = F_83 ( V_135 , V_134 [ V_92 ] . V_45 + 1 ) ;
V_7 -> V_62 = V_135 ;
}
if ( ! V_22 )
return 0 ;
V_81 = 0 ;
if ( V_22 -> V_137 ) {
while ( V_22 -> V_137 [ V_81 ] != NULL )
V_81 ++ ;
}
V_43 = F_71 ( V_81 + F_84 ( V_138 ) + 1 ,
sizeof( struct V_131 * ) , V_69 ) ;
if ( ! V_43 )
return - V_70 ;
memcpy ( V_43 , V_138 , sizeof( V_138 ) ) ;
if ( ! V_22 -> V_4 -> V_87 )
V_43 [ 0 ] = & V_139 . V_43 ;
if ( V_22 -> V_137 )
memcpy ( & V_43 [ F_84 ( V_138 ) ] , V_22 -> V_137 ,
sizeof( struct V_131 * ) * V_81 ) ;
V_43 [ V_81 + F_84 ( V_138 ) ] = NULL ;
V_22 -> V_140 . V_141 = L_14 ;
V_22 -> V_140 . V_137 = V_43 ;
V_7 -> V_142 [ V_7 -> V_143 ++ ] = & V_22 -> V_140 ;
if ( V_22 -> V_144 != NULL ) {
V_43 = V_22 -> V_144 -> V_137 ;
while ( * V_43 ++ != NULL )
V_133 ++ ;
}
V_81 = V_133 ;
F_14 ( & V_22 -> V_83 ) ;
V_134 = V_7 -> V_134 ;
if ( V_134 ) {
for ( V_92 = 0 ; V_92 < V_7 -> V_136 ; V_92 ++ ) {
if ( V_134 [ V_92 ] . V_45 < 0 )
continue;
V_25 = F_45 ( V_7 ,
& V_134 [ V_92 ] ) ;
if ( V_25 < 0 )
goto V_145;
V_81 += V_25 ;
if ( V_134 [ V_92 ] . type == V_84 )
V_7 -> V_93 =
V_134 [ V_92 ] . V_45 ;
}
if ( V_7 -> V_62 && V_22 -> V_60 == NULL ) {
V_22 -> V_60 = F_71 ( F_28 ( V_7 -> V_62 ) ,
sizeof( * V_22 -> V_60 ) ,
V_69 ) ;
if ( V_22 -> V_60 == NULL ) {
V_25 = - V_70 ;
goto V_145;
}
}
}
V_22 -> V_146 . V_141 = V_147 ;
V_22 -> V_146 . V_137 = F_71 ( V_81 + 1 ,
sizeof( V_22 -> V_146 . V_137 [ 0 ] ) ,
V_69 ) ;
if ( V_22 -> V_146 . V_137 == NULL ) {
V_25 = - V_70 ;
goto V_148;
}
if ( V_22 -> V_144 )
memcpy ( V_22 -> V_146 . V_137 , V_22 -> V_144 ,
sizeof( V_22 -> V_146 . V_137 [ 0 ] ) * V_133 ) ;
V_132 = V_133 ;
F_70 (p, &buffer->scan_el_dev_attr_list, l)
V_22 -> V_146 . V_137 [ V_132 ++ ] = & V_130 -> V_149 . V_43 ;
V_7 -> V_142 [ V_7 -> V_143 ++ ] = & V_22 -> V_146 ;
return 0 ;
V_148:
F_35 ( V_22 -> V_60 ) ;
V_145:
F_85 ( & V_22 -> V_83 ) ;
F_35 ( V_7 -> V_22 -> V_140 . V_137 ) ;
return V_25 ;
}
void F_86 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_22 )
return;
F_35 ( V_7 -> V_22 -> V_60 ) ;
F_35 ( V_7 -> V_22 -> V_140 . V_137 ) ;
F_35 ( V_7 -> V_22 -> V_146 . V_137 ) ;
F_85 ( & V_7 -> V_22 -> V_83 ) ;
}
bool F_87 ( struct V_6 * V_7 ,
const unsigned long * V_63 )
{
return F_88 ( V_63 , V_7 -> V_62 ) == 1 ;
}
int F_41 ( struct V_6 * V_7 ,
struct V_1 * V_22 , int V_67 )
{
if ( V_67 > V_7 -> V_62 )
return - V_27 ;
if ( ! V_22 -> V_60 )
return 0 ;
return ! ! F_23 ( V_67 , V_22 -> V_60 ) ;
}
static const void * F_89 ( struct V_1 * V_22 ,
const void * V_150 )
{
struct V_151 * V_152 ;
if ( F_2 ( & V_22 -> V_38 ) )
return V_150 ;
F_70 (t, &buffer->demux_list, l)
memcpy ( V_22 -> V_153 + V_152 -> V_154 ,
V_150 + V_152 -> V_155 , V_152 -> V_85 ) ;
return V_22 -> V_153 ;
}
static int F_90 ( struct V_1 * V_22 , const void * V_156 )
{
const void * V_157 = F_89 ( V_22 , V_156 ) ;
int V_25 ;
V_25 = V_22 -> V_4 -> V_158 ( V_22 , V_157 ) ;
if ( V_25 )
return V_25 ;
F_91 ( & V_22 -> V_32 , V_36 | V_37 ) ;
return 0 ;
}
static void F_92 ( struct V_1 * V_22 )
{
struct V_151 * V_130 , * V_159 ;
F_63 (p, q, &buffer->demux_list, l) {
F_93 ( & V_130 -> V_160 ) ;
F_35 ( V_130 ) ;
}
}
int F_94 ( struct V_6 * V_7 , const void * V_156 )
{
int V_25 ;
struct V_1 * V_2 ;
F_70 (buf, &indio_dev->buffer_list, buffer_list) {
V_25 = F_90 ( V_2 , V_156 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_22 ,
struct V_151 * * V_130 , unsigned int V_161 , unsigned int V_162 ,
unsigned int V_85 )
{
if ( * V_130 && ( * V_130 ) -> V_155 + ( * V_130 ) -> V_85 == V_161 &&
( * V_130 ) -> V_154 + ( * V_130 ) -> V_85 == V_162 ) {
( * V_130 ) -> V_85 += V_85 ;
} else {
* V_130 = F_31 ( sizeof( * * V_130 ) , V_69 ) ;
if ( * V_130 == NULL )
return - V_70 ;
( * V_130 ) -> V_155 = V_161 ;
( * V_130 ) -> V_154 = V_162 ;
( * V_130 ) -> V_85 = V_85 ;
F_96 ( & ( * V_130 ) -> V_160 , & V_22 -> V_38 ) ;
}
return 0 ;
}
static int F_97 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
const struct V_79 * V_90 ;
int V_25 , V_163 = - 1 , V_164 , V_85 ;
unsigned V_161 = 0 , V_162 = 0 ;
struct V_151 * V_130 = NULL ;
F_92 ( V_22 ) ;
F_35 ( V_22 -> V_153 ) ;
V_22 -> V_153 = NULL ;
if ( F_26 ( V_7 -> V_110 ,
V_22 -> V_60 ,
V_7 -> V_62 ) )
return 0 ;
F_52 (out_ind,
buffer->scan_mask,
indio_dev->masklength) {
V_163 = F_98 ( V_7 -> V_110 ,
V_7 -> V_62 ,
V_163 + 1 ) ;
while ( V_163 != V_164 ) {
V_163 = F_98 ( V_7 -> V_110 ,
V_7 -> V_62 ,
V_163 + 1 ) ;
V_90 = F_53 ( V_7 , V_163 ) ;
if ( V_90 -> V_48 . V_53 > 1 )
V_85 = V_90 -> V_48 . V_57 / 8 *
V_90 -> V_48 . V_53 ;
else
V_85 = V_90 -> V_48 . V_57 / 8 ;
V_161 = F_99 ( V_161 , V_85 ) + V_85 ;
}
V_90 = F_53 ( V_7 , V_163 ) ;
if ( V_90 -> V_48 . V_53 > 1 )
V_85 = V_90 -> V_48 . V_57 / 8 *
V_90 -> V_48 . V_53 ;
else
V_85 = V_90 -> V_48 . V_57 / 8 ;
V_162 = F_99 ( V_162 , V_85 ) ;
V_161 = F_99 ( V_161 , V_85 ) ;
V_25 = F_95 ( V_22 , & V_130 , V_161 , V_162 , V_85 ) ;
if ( V_25 )
goto V_165;
V_162 += V_85 ;
V_161 += V_85 ;
}
if ( V_22 -> V_78 ) {
V_90 = F_53 ( V_7 ,
V_7 -> V_93 ) ;
if ( V_90 -> V_48 . V_53 > 1 )
V_85 = V_90 -> V_48 . V_57 / 8 *
V_90 -> V_48 . V_53 ;
else
V_85 = V_90 -> V_48 . V_57 / 8 ;
V_162 = F_99 ( V_162 , V_85 ) ;
V_161 = F_99 ( V_161 , V_85 ) ;
V_25 = F_95 ( V_22 , & V_130 , V_161 , V_162 , V_85 ) ;
if ( V_25 )
goto V_165;
V_162 += V_85 ;
V_161 += V_85 ;
}
V_22 -> V_153 = F_100 ( V_162 , V_69 ) ;
if ( V_22 -> V_153 == NULL ) {
V_25 = - V_70 ;
goto V_165;
}
return 0 ;
V_165:
F_92 ( V_22 ) ;
return V_25 ;
}
int F_74 ( struct V_6 * V_7 )
{
struct V_1 * V_22 ;
int V_25 ;
F_70 (buffer, &indio_dev->buffer_list, buffer_list) {
V_25 = F_97 ( V_7 , V_22 ) ;
if ( V_25 < 0 )
goto V_165;
}
return 0 ;
V_165:
F_70 (buffer, &indio_dev->buffer_list, buffer_list)
F_92 ( V_22 ) ;
return V_25 ;
}
static void F_101 ( struct V_166 * V_39 )
{
struct V_1 * V_22 = F_102 ( V_39 , struct V_1 , V_39 ) ;
V_22 -> V_4 -> V_167 ( V_22 ) ;
}
struct V_1 * F_56 ( struct V_1 * V_22 )
{
if ( V_22 )
F_103 ( & V_22 -> V_39 ) ;
return V_22 ;
}
void F_61 ( struct V_1 * V_22 )
{
if ( V_22 )
F_104 ( & V_22 -> V_39 , F_101 ) ;
}
