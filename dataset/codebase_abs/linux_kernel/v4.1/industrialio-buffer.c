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
const unsigned long * V_63 )
{
if ( F_25 ( V_63 , V_62 ) )
return NULL ;
while ( * V_61 ) {
if ( F_26 ( V_63 , V_61 , V_62 ) )
return V_61 ;
V_61 += F_27 ( V_62 ) ;
}
return NULL ;
}
static bool F_28 ( struct V_6 * V_7 ,
const unsigned long * V_63 )
{
if ( ! V_7 -> V_64 -> V_65 )
return true ;
return V_7 -> V_64 -> V_65 ( V_7 , V_63 ) ;
}
static int F_29 ( struct V_6 * V_7 ,
struct V_1 * V_22 , int V_66 )
{
const unsigned long * V_63 ;
unsigned long * V_67 ;
V_67 = F_30 ( sizeof( * V_67 ) *
F_27 ( V_7 -> V_62 ) ,
V_68 ) ;
if ( V_67 == NULL )
return - V_69 ;
if ( ! V_7 -> V_62 ) {
F_31 ( L_5 ) ;
goto V_70;
}
F_32 ( V_67 , V_22 -> V_60 , V_7 -> V_62 ) ;
F_33 ( V_66 , V_67 ) ;
if ( ! F_28 ( V_7 , V_67 ) )
goto V_70;
if ( V_7 -> V_71 ) {
V_63 = F_24 ( V_7 -> V_71 ,
V_7 -> V_62 ,
V_67 ) ;
if ( ! V_63 )
goto V_70;
}
F_32 ( V_22 -> V_60 , V_67 , V_7 -> V_62 ) ;
F_34 ( V_67 ) ;
return 0 ;
V_70:
F_34 ( V_67 ) ;
return - V_27 ;
}
static int F_35 ( struct V_1 * V_22 , int V_66 )
{
F_36 ( V_66 , V_22 -> V_60 ) ;
return 0 ;
}
static T_2 F_37 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_2 ,
T_1 V_72 )
{
int V_25 ;
bool V_73 ;
struct V_6 * V_7 = F_22 ( V_41 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
struct V_46 * V_47 = F_18 ( V_43 ) ;
V_25 = F_38 ( V_2 , & V_73 ) ;
if ( V_25 < 0 )
return V_25 ;
F_39 ( & V_7 -> V_74 ) ;
if ( F_1 ( V_7 -> V_22 ) ) {
V_25 = - V_75 ;
goto V_76;
}
V_25 = F_40 ( V_7 , V_22 , V_47 -> V_59 ) ;
if ( V_25 < 0 )
goto V_76;
if ( ! V_73 && V_25 ) {
V_25 = F_35 ( V_22 , V_47 -> V_59 ) ;
if ( V_25 )
goto V_76;
} else if ( V_73 && ! V_25 ) {
V_25 = F_29 ( V_7 , V_22 , V_47 -> V_59 ) ;
if ( V_25 )
goto V_76;
}
V_76:
F_41 ( & V_7 -> V_74 ) ;
return V_25 < 0 ? V_25 : V_72 ;
}
static T_2 F_42 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_2 )
{
struct V_6 * V_7 = F_22 ( V_41 ) ;
return sprintf ( V_2 , L_4 , V_7 -> V_22 -> V_77 ) ;
}
static T_2 F_43 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_2 ,
T_1 V_72 )
{
int V_25 ;
struct V_6 * V_7 = F_22 ( V_41 ) ;
bool V_73 ;
V_25 = F_38 ( V_2 , & V_73 ) ;
if ( V_25 < 0 )
return V_25 ;
F_39 ( & V_7 -> V_74 ) ;
if ( F_1 ( V_7 -> V_22 ) ) {
V_25 = - V_75 ;
goto V_76;
}
V_7 -> V_22 -> V_77 = V_73 ;
V_76:
F_41 ( & V_7 -> V_74 ) ;
return V_25 ? V_25 : V_72 ;
}
static int F_44 ( struct V_6 * V_7 ,
const struct V_78 * V_79 )
{
int V_25 , V_80 = 0 ;
struct V_1 * V_22 = V_7 -> V_22 ;
V_25 = F_45 ( L_6 ,
V_79 ,
& F_17 ,
NULL ,
0 ,
V_81 ,
& V_7 -> V_41 ,
& V_22 -> V_82 ) ;
if ( V_25 )
return V_25 ;
V_80 ++ ;
V_25 = F_45 ( L_7 ,
V_79 ,
& F_19 ,
NULL ,
0 ,
0 ,
& V_7 -> V_41 ,
& V_22 -> V_82 ) ;
if ( V_25 )
return V_25 ;
V_80 ++ ;
if ( V_79 -> type != V_83 )
V_25 = F_45 ( L_8 ,
V_79 ,
& F_21 ,
& F_37 ,
V_79 -> V_45 ,
0 ,
& V_7 -> V_41 ,
& V_22 -> V_82 ) ;
else
V_25 = F_45 ( L_8 ,
V_79 ,
& F_42 ,
& F_43 ,
V_79 -> V_45 ,
0 ,
& V_7 -> V_41 ,
& V_22 -> V_82 ) ;
if ( V_25 )
return V_25 ;
V_80 ++ ;
V_25 = V_80 ;
return V_25 ;
}
static T_2 F_46 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_2 )
{
struct V_6 * V_7 = F_22 ( V_41 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
return sprintf ( V_2 , L_4 , V_22 -> V_84 ) ;
}
static T_2 F_47 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_2 , T_1 V_72 )
{
struct V_6 * V_7 = F_22 ( V_41 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
unsigned int V_85 ;
int V_25 ;
V_25 = F_48 ( V_2 , 10 , & V_85 ) ;
if ( V_25 )
return V_25 ;
if ( V_85 == V_22 -> V_84 )
return V_72 ;
F_39 ( & V_7 -> V_74 ) ;
if ( F_1 ( V_7 -> V_22 ) ) {
V_25 = - V_75 ;
} else {
V_22 -> V_4 -> V_86 ( V_22 , V_85 ) ;
V_25 = 0 ;
}
if ( V_25 )
goto V_87;
if ( V_22 -> V_84 && V_22 -> V_84 < V_22 -> V_29 )
V_22 -> V_29 = V_22 -> V_84 ;
V_87:
F_41 ( & V_7 -> V_74 ) ;
return V_25 ? V_25 : V_72 ;
}
static T_2 F_49 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_2 )
{
struct V_6 * V_7 = F_22 ( V_41 ) ;
return sprintf ( V_2 , L_4 , F_1 ( V_7 -> V_22 ) ) ;
}
static int F_50 ( struct V_6 * V_7 ,
const unsigned long * V_63 , bool V_88 )
{
const struct V_78 * V_89 ;
unsigned V_90 = 0 ;
int V_84 , V_91 ;
F_51 (i, mask,
indio_dev->masklength) {
V_89 = F_52 ( V_7 , V_91 ) ;
if ( V_89 -> V_48 . V_53 > 1 )
V_84 = V_89 -> V_48 . V_57 / 8 *
V_89 -> V_48 . V_53 ;
else
V_84 = V_89 -> V_48 . V_57 / 8 ;
V_90 = F_53 ( V_90 , V_84 ) ;
V_90 += V_84 ;
}
if ( V_88 ) {
V_89 = F_52 ( V_7 ,
V_7 -> V_92 ) ;
if ( V_89 -> V_48 . V_53 > 1 )
V_84 = V_89 -> V_48 . V_57 / 8 *
V_89 -> V_48 . V_53 ;
else
V_84 = V_89 -> V_48 . V_57 / 8 ;
V_90 = F_53 ( V_90 , V_84 ) ;
V_90 += V_84 ;
}
return V_90 ;
}
static void F_54 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
F_55 ( V_22 ) ;
F_56 ( & V_22 -> V_3 , & V_7 -> V_3 ) ;
}
static void F_57 ( struct V_1 * V_22 )
{
F_58 ( & V_22 -> V_3 ) ;
F_59 ( & V_22 -> V_32 ) ;
F_60 ( V_22 ) ;
}
void F_61 ( struct V_6 * V_7 )
{
struct V_1 * V_22 , * V_93 ;
if ( F_2 ( & V_7 -> V_3 ) )
return;
if ( V_7 -> V_64 -> V_94 )
V_7 -> V_64 -> V_94 ( V_7 ) ;
F_62 (buffer, _buffer,
&indio_dev->buffer_list, buffer_list)
F_57 ( V_22 ) ;
V_7 -> V_95 = V_96 ;
if ( V_7 -> V_64 -> V_97 )
V_7 -> V_64 -> V_97 ( V_7 ) ;
if ( V_7 -> V_71 == NULL )
F_34 ( V_7 -> V_98 ) ;
}
static void F_63 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
unsigned int V_90 ;
if ( ! V_22 -> V_4 -> V_99 )
return;
V_90 = F_50 ( V_7 , V_22 -> V_60 ,
V_22 -> V_77 ) ;
V_22 -> V_4 -> V_99 ( V_22 , V_90 ) ;
}
static int F_64 ( struct V_6 * V_7 ,
struct V_1 * V_100 ,
struct V_1 * V_101 )
{
int V_25 ;
int V_102 = 0 ;
struct V_1 * V_22 ;
unsigned long * V_103 ;
const unsigned long * V_104 ;
if ( ! F_2 ( & V_7 -> V_3 ) ) {
if ( V_7 -> V_64 -> V_94 ) {
V_25 = V_7 -> V_64 -> V_94 ( V_7 ) ;
if ( V_25 )
return V_25 ;
}
V_7 -> V_95 = V_96 ;
if ( V_7 -> V_64 -> V_97 ) {
V_25 = V_7 -> V_64 -> V_97 ( V_7 ) ;
if ( V_25 )
return V_25 ;
}
}
V_104 = V_7 -> V_98 ;
if ( ! V_7 -> V_71 )
V_7 -> V_98 = NULL ;
if ( V_101 )
F_57 ( V_101 ) ;
if ( V_100 )
F_54 ( V_7 , V_100 ) ;
if ( F_2 ( & V_7 -> V_3 ) ) {
V_7 -> V_95 = V_96 ;
if ( V_7 -> V_71 == NULL )
F_34 ( V_104 ) ;
return 0 ;
}
V_103 = F_65 ( F_27 ( V_7 -> V_62 ) ,
sizeof( long ) , V_68 ) ;
if ( V_103 == NULL ) {
if ( V_7 -> V_71 == NULL )
F_34 ( V_104 ) ;
return - V_69 ;
}
V_7 -> V_77 = 0 ;
F_66 (buffer, &indio_dev->buffer_list, buffer_list) {
F_67 ( V_103 , V_103 , V_22 -> V_60 ,
V_7 -> V_62 ) ;
V_7 -> V_77 |= V_22 -> V_77 ;
}
if ( V_7 -> V_71 ) {
V_7 -> V_98 =
F_24 ( V_7 -> V_71 ,
V_7 -> V_62 ,
V_103 ) ;
if ( V_7 -> V_98 == NULL ) {
F_57 ( V_100 ) ;
if ( V_104 ) {
V_7 -> V_98 = V_104 ;
V_102 = - V_27 ;
}
else {
F_34 ( V_103 ) ;
V_25 = - V_27 ;
return V_25 ;
}
}
} else {
V_7 -> V_98 = V_103 ;
}
F_68 ( V_7 ) ;
if ( V_7 -> V_64 -> V_105 ) {
V_25 = V_7 -> V_64 -> V_105 ( V_7 ) ;
if ( V_25 ) {
F_69 ( V_106
L_9 , V_25 ) ;
goto V_107;
}
}
V_7 -> V_108 =
F_50 ( V_7 ,
V_7 -> V_98 ,
V_7 -> V_77 ) ;
F_66 (buffer, &indio_dev->buffer_list, buffer_list) {
F_63 ( V_7 , V_22 ) ;
if ( V_22 -> V_4 -> V_109 ) {
V_25 = V_22 -> V_4 -> V_109 ( V_22 ) ;
if ( V_25 ) {
F_69 ( V_110
L_10 , V_25 ) ;
goto V_111;
}
}
}
if ( V_7 -> V_9 -> V_112 ) {
V_25 = V_7 -> V_9
-> V_112 ( V_7 ,
V_7 -> V_98 ) ;
if ( V_25 < 0 ) {
F_69 ( V_110 L_11 , V_25 ) ;
goto V_111;
}
}
if ( ( V_7 -> V_113 & V_114 ) && V_7 -> V_115 ) {
V_7 -> V_95 = V_114 ;
} else if ( V_7 -> V_113 & V_116 ) {
V_7 -> V_95 = V_116 ;
} else if ( V_7 -> V_113 & V_117 ) {
V_7 -> V_95 = V_117 ;
} else {
if ( V_7 -> V_113 & V_114 )
F_70 ( L_12 ) ;
V_25 = - V_27 ;
goto V_111;
}
if ( V_7 -> V_64 -> V_118 ) {
V_25 = V_7 -> V_64 -> V_118 ( V_7 ) ;
if ( V_25 ) {
F_69 ( V_110
L_13 , V_25 ) ;
V_7 -> V_95 = V_96 ;
if ( V_7 -> V_64 -> V_97 )
V_7 -> V_64 -> V_97 ( V_7 ) ;
goto V_119;
}
}
if ( V_7 -> V_71 )
F_34 ( V_103 ) ;
else
F_34 ( V_104 ) ;
return V_102 ;
V_119:
V_7 -> V_95 = V_96 ;
V_111:
if ( V_7 -> V_64 -> V_97 )
V_7 -> V_64 -> V_97 ( V_7 ) ;
V_107:
if ( V_100 )
F_57 ( V_100 ) ;
V_7 -> V_98 = V_104 ;
F_34 ( V_103 ) ;
return V_25 ;
}
int F_71 ( struct V_6 * V_7 ,
struct V_1 * V_100 ,
struct V_1 * V_101 )
{
int V_25 ;
if ( V_100 == V_101 )
return 0 ;
F_39 ( & V_7 -> V_120 ) ;
F_39 ( & V_7 -> V_74 ) ;
if ( V_100 && F_1 ( V_100 ) )
V_100 = NULL ;
if ( V_101 && ! F_1 ( V_101 ) )
V_101 = NULL ;
if ( ! V_100 && ! V_101 ) {
V_25 = 0 ;
goto V_121;
}
if ( V_7 -> V_9 == NULL ) {
V_25 = - V_11 ;
goto V_121;
}
V_25 = F_64 ( V_7 , V_100 , V_101 ) ;
V_121:
F_41 ( & V_7 -> V_74 ) ;
F_41 ( & V_7 -> V_120 ) ;
return V_25 ;
}
static T_2 F_72 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_2 ,
T_1 V_72 )
{
int V_25 ;
bool V_122 ;
struct V_6 * V_7 = F_22 ( V_41 ) ;
bool V_123 ;
V_25 = F_38 ( V_2 , & V_122 ) ;
if ( V_25 < 0 )
return V_25 ;
F_39 ( & V_7 -> V_74 ) ;
V_123 = F_1 ( V_7 -> V_22 ) ;
if ( V_123 == V_122 )
goto V_124;
if ( V_122 )
V_25 = F_64 ( V_7 ,
V_7 -> V_22 , NULL ) ;
else
V_25 = F_64 ( V_7 ,
NULL , V_7 -> V_22 ) ;
if ( V_25 < 0 )
goto V_124;
V_124:
F_41 ( & V_7 -> V_74 ) ;
return ( V_25 < 0 ) ? V_25 : V_72 ;
}
static T_2 F_73 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_2 )
{
struct V_6 * V_7 = F_22 ( V_41 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
return sprintf ( V_2 , L_1 , V_22 -> V_29 ) ;
}
static T_2 F_74 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_2 ,
T_1 V_72 )
{
struct V_6 * V_7 = F_22 ( V_41 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
unsigned int V_85 ;
int V_25 ;
V_25 = F_48 ( V_2 , 10 , & V_85 ) ;
if ( V_25 )
return V_25 ;
if ( ! V_85 )
return - V_27 ;
F_39 ( & V_7 -> V_74 ) ;
if ( V_85 > V_22 -> V_84 ) {
V_25 = - V_27 ;
goto V_87;
}
if ( F_1 ( V_7 -> V_22 ) ) {
V_25 = - V_75 ;
goto V_87;
}
V_22 -> V_29 = V_85 ;
if ( V_7 -> V_9 -> V_125 )
V_7 -> V_9 -> V_125 ( V_7 , V_85 ) ;
V_87:
F_41 ( & V_7 -> V_74 ) ;
return V_25 ? V_25 : V_72 ;
}
int F_75 ( struct V_6 * V_7 )
{
struct V_46 * V_126 ;
struct V_127 * * V_43 ;
struct V_1 * V_22 = V_7 -> V_22 ;
int V_25 , V_91 , V_128 , V_80 , V_129 = 0 ;
const struct V_78 * V_130 ;
if ( ! V_22 )
return 0 ;
V_80 = 0 ;
if ( V_22 -> V_131 ) {
while ( V_22 -> V_131 [ V_80 ] != NULL )
V_80 ++ ;
}
V_43 = F_65 ( V_80 + F_76 ( V_132 ) + 1 ,
sizeof( struct V_127 * ) , V_68 ) ;
if ( ! V_43 )
return - V_69 ;
memcpy ( V_43 , V_132 , sizeof( V_132 ) ) ;
if ( ! V_22 -> V_4 -> V_86 )
V_43 [ 0 ] = & V_133 . V_43 ;
if ( V_22 -> V_131 )
memcpy ( & V_43 [ F_76 ( V_132 ) ] , V_22 -> V_131 ,
sizeof( struct V_127 * ) * V_80 ) ;
V_43 [ V_80 + F_76 ( V_132 ) ] = NULL ;
V_22 -> V_134 . V_135 = L_14 ;
V_22 -> V_134 . V_131 = V_43 ;
V_7 -> V_136 [ V_7 -> V_137 ++ ] = & V_22 -> V_134 ;
if ( V_22 -> V_138 != NULL ) {
V_43 = V_22 -> V_138 -> V_131 ;
while ( * V_43 ++ != NULL )
V_129 ++ ;
}
V_80 = V_129 ;
F_14 ( & V_22 -> V_82 ) ;
V_130 = V_7 -> V_130 ;
if ( V_130 ) {
for ( V_91 = 0 ; V_91 < V_7 -> V_139 ; V_91 ++ ) {
if ( V_130 [ V_91 ] . V_45 < 0 )
continue;
if ( V_130 [ V_91 ] . V_45 >
( int ) V_7 -> V_62 - 1 )
V_7 -> V_62
= V_130 [ V_91 ] . V_45 + 1 ;
V_25 = F_44 ( V_7 ,
& V_130 [ V_91 ] ) ;
if ( V_25 < 0 )
goto V_140;
V_80 += V_25 ;
if ( V_130 [ V_91 ] . type == V_83 )
V_7 -> V_92 =
V_130 [ V_91 ] . V_45 ;
}
if ( V_7 -> V_62 && V_22 -> V_60 == NULL ) {
V_22 -> V_60 = F_65 ( F_27 ( V_7 -> V_62 ) ,
sizeof( * V_22 -> V_60 ) ,
V_68 ) ;
if ( V_22 -> V_60 == NULL ) {
V_25 = - V_69 ;
goto V_140;
}
}
}
V_22 -> V_141 . V_135 = V_142 ;
V_22 -> V_141 . V_131 = F_65 ( V_80 + 1 ,
sizeof( V_22 -> V_141 . V_131 [ 0 ] ) ,
V_68 ) ;
if ( V_22 -> V_141 . V_131 == NULL ) {
V_25 = - V_69 ;
goto V_143;
}
if ( V_22 -> V_138 )
memcpy ( V_22 -> V_141 . V_131 , V_22 -> V_138 ,
sizeof( V_22 -> V_141 . V_131 [ 0 ] ) * V_129 ) ;
V_128 = V_129 ;
F_66 (p, &buffer->scan_el_dev_attr_list, l)
V_22 -> V_141 . V_131 [ V_128 ++ ] = & V_126 -> V_144 . V_43 ;
V_7 -> V_136 [ V_7 -> V_137 ++ ] = & V_22 -> V_141 ;
return 0 ;
V_143:
F_34 ( V_22 -> V_60 ) ;
V_140:
F_77 ( & V_22 -> V_82 ) ;
F_34 ( V_7 -> V_22 -> V_134 . V_131 ) ;
return V_25 ;
}
void F_78 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_22 )
return;
F_34 ( V_7 -> V_22 -> V_60 ) ;
F_34 ( V_7 -> V_22 -> V_134 . V_131 ) ;
F_34 ( V_7 -> V_22 -> V_141 . V_131 ) ;
F_77 ( & V_7 -> V_22 -> V_82 ) ;
}
bool F_79 ( struct V_6 * V_7 ,
const unsigned long * V_63 )
{
return F_80 ( V_63 , V_7 -> V_62 ) == 1 ;
}
int F_40 ( struct V_6 * V_7 ,
struct V_1 * V_22 , int V_66 )
{
if ( V_66 > V_7 -> V_62 )
return - V_27 ;
if ( ! V_22 -> V_60 )
return 0 ;
return ! ! F_23 ( V_66 , V_22 -> V_60 ) ;
}
static const void * F_81 ( struct V_1 * V_22 ,
const void * V_145 )
{
struct V_146 * V_147 ;
if ( F_2 ( & V_22 -> V_38 ) )
return V_145 ;
F_66 (t, &buffer->demux_list, l)
memcpy ( V_22 -> V_148 + V_147 -> V_149 ,
V_145 + V_147 -> V_150 , V_147 -> V_84 ) ;
return V_22 -> V_148 ;
}
static int F_82 ( struct V_1 * V_22 , const void * V_151 )
{
const void * V_152 = F_81 ( V_22 , V_151 ) ;
int V_25 ;
V_25 = V_22 -> V_4 -> V_153 ( V_22 , V_152 ) ;
if ( V_25 )
return V_25 ;
F_83 ( & V_22 -> V_32 , V_36 | V_37 ) ;
return 0 ;
}
static void F_84 ( struct V_1 * V_22 )
{
struct V_146 * V_126 , * V_154 ;
F_62 (p, q, &buffer->demux_list, l) {
F_85 ( & V_126 -> V_155 ) ;
F_34 ( V_126 ) ;
}
}
int F_86 ( struct V_6 * V_7 , const void * V_151 )
{
int V_25 ;
struct V_1 * V_2 ;
F_66 (buf, &indio_dev->buffer_list, buffer_list) {
V_25 = F_82 ( V_2 , V_151 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_87 ( struct V_1 * V_22 ,
struct V_146 * * V_126 , unsigned int V_156 , unsigned int V_157 ,
unsigned int V_84 )
{
if ( * V_126 && ( * V_126 ) -> V_150 + ( * V_126 ) -> V_84 == V_156 &&
( * V_126 ) -> V_149 + ( * V_126 ) -> V_84 == V_157 ) {
( * V_126 ) -> V_84 += V_84 ;
} else {
* V_126 = F_30 ( sizeof( * * V_126 ) , V_68 ) ;
if ( * V_126 == NULL )
return - V_69 ;
( * V_126 ) -> V_150 = V_156 ;
( * V_126 ) -> V_149 = V_157 ;
( * V_126 ) -> V_84 = V_84 ;
F_88 ( & ( * V_126 ) -> V_155 , & V_22 -> V_38 ) ;
}
return 0 ;
}
static int F_89 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
const struct V_78 * V_89 ;
int V_25 , V_158 = - 1 , V_159 , V_84 ;
unsigned V_156 = 0 , V_157 = 0 ;
struct V_146 * V_126 = NULL ;
F_84 ( V_22 ) ;
F_34 ( V_22 -> V_148 ) ;
V_22 -> V_148 = NULL ;
if ( F_90 ( V_7 -> V_98 ,
V_22 -> V_60 ,
V_7 -> V_62 ) )
return 0 ;
F_51 (out_ind,
buffer->scan_mask,
indio_dev->masklength) {
V_158 = F_91 ( V_7 -> V_98 ,
V_7 -> V_62 ,
V_158 + 1 ) ;
while ( V_158 != V_159 ) {
V_158 = F_91 ( V_7 -> V_98 ,
V_7 -> V_62 ,
V_158 + 1 ) ;
V_89 = F_52 ( V_7 , V_158 ) ;
if ( V_89 -> V_48 . V_53 > 1 )
V_84 = V_89 -> V_48 . V_57 / 8 *
V_89 -> V_48 . V_53 ;
else
V_84 = V_89 -> V_48 . V_57 / 8 ;
V_156 = F_92 ( V_156 , V_84 ) + V_84 ;
}
V_89 = F_52 ( V_7 , V_158 ) ;
if ( V_89 -> V_48 . V_53 > 1 )
V_84 = V_89 -> V_48 . V_57 / 8 *
V_89 -> V_48 . V_53 ;
else
V_84 = V_89 -> V_48 . V_57 / 8 ;
V_157 = F_92 ( V_157 , V_84 ) ;
V_156 = F_92 ( V_156 , V_84 ) ;
V_25 = F_87 ( V_22 , & V_126 , V_156 , V_157 , V_84 ) ;
if ( V_25 )
goto V_160;
V_157 += V_84 ;
V_156 += V_84 ;
}
if ( V_22 -> V_77 ) {
V_89 = F_52 ( V_7 ,
V_7 -> V_92 ) ;
if ( V_89 -> V_48 . V_53 > 1 )
V_84 = V_89 -> V_48 . V_57 / 8 *
V_89 -> V_48 . V_53 ;
else
V_84 = V_89 -> V_48 . V_57 / 8 ;
V_157 = F_92 ( V_157 , V_84 ) ;
V_156 = F_92 ( V_156 , V_84 ) ;
V_25 = F_87 ( V_22 , & V_126 , V_156 , V_157 , V_84 ) ;
if ( V_25 )
goto V_160;
V_157 += V_84 ;
V_156 += V_84 ;
}
V_22 -> V_148 = F_93 ( V_157 , V_68 ) ;
if ( V_22 -> V_148 == NULL ) {
V_25 = - V_69 ;
goto V_160;
}
return 0 ;
V_160:
F_84 ( V_22 ) ;
return V_25 ;
}
int F_68 ( struct V_6 * V_7 )
{
struct V_1 * V_22 ;
int V_25 ;
F_66 (buffer, &indio_dev->buffer_list, buffer_list) {
V_25 = F_89 ( V_7 , V_22 ) ;
if ( V_25 < 0 )
goto V_160;
}
return 0 ;
V_160:
F_66 (buffer, &indio_dev->buffer_list, buffer_list)
F_84 ( V_22 ) ;
return V_25 ;
}
static void F_94 ( struct V_161 * V_39 )
{
struct V_1 * V_22 = F_95 ( V_39 , struct V_1 , V_39 ) ;
V_22 -> V_4 -> V_162 ( V_22 ) ;
}
struct V_1 * F_55 ( struct V_1 * V_22 )
{
if ( V_22 )
F_96 ( & V_22 -> V_39 ) ;
return V_22 ;
}
void F_60 ( struct V_1 * V_22 )
{
if ( V_22 )
F_97 ( & V_22 -> V_39 , F_94 ) ;
}
