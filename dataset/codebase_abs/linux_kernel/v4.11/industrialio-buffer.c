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
void F_21 ( struct V_1 * V_22 ,
const struct V_44 * * V_45 )
{
V_22 -> V_45 = V_45 ;
}
static T_2 F_22 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_2 )
{
return sprintf ( V_2 , L_1 , F_23 ( V_49 ) -> V_50 -> V_51 ) ;
}
static T_2 F_24 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_2 )
{
struct V_52 * V_53 = F_23 ( V_49 ) ;
T_5 type = V_53 -> V_50 -> V_54 . V_55 ;
if ( type == V_56 ) {
#ifdef F_25
type = V_57 ;
#else
type = V_58 ;
#endif
}
if ( V_53 -> V_50 -> V_54 . V_59 > 1 )
return sprintf ( V_2 , L_2 ,
V_60 [ type ] ,
V_53 -> V_50 -> V_54 . V_61 ,
V_53 -> V_50 -> V_54 . V_62 ,
V_53 -> V_50 -> V_54 . V_63 ,
V_53 -> V_50 -> V_54 . V_59 ,
V_53 -> V_50 -> V_54 . V_64 ) ;
else
return sprintf ( V_2 , L_3 ,
V_60 [ type ] ,
V_53 -> V_50 -> V_54 . V_61 ,
V_53 -> V_50 -> V_54 . V_62 ,
V_53 -> V_50 -> V_54 . V_63 ,
V_53 -> V_50 -> V_54 . V_64 ) ;
}
static T_2 F_26 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_2 )
{
int V_26 ;
struct V_6 * V_7 = F_27 ( V_47 ) ;
V_26 = ! ! F_28 ( F_23 ( V_49 ) -> V_65 ,
V_7 -> V_22 -> V_66 ) ;
return sprintf ( V_2 , L_4 , V_26 ) ;
}
static const unsigned long * F_29 ( const unsigned long * V_67 ,
unsigned int V_68 ,
const unsigned long * V_69 ,
bool V_70 )
{
if ( F_30 ( V_69 , V_68 ) )
return NULL ;
while ( * V_67 ) {
if ( V_70 ) {
if ( F_31 ( V_69 , V_67 , V_68 ) )
return V_67 ;
} else {
if ( F_32 ( V_69 , V_67 , V_68 ) )
return V_67 ;
}
V_67 += F_33 ( V_68 ) ;
}
return NULL ;
}
static bool F_34 ( struct V_6 * V_7 ,
const unsigned long * V_69 )
{
if ( ! V_7 -> V_71 -> V_72 )
return true ;
return V_7 -> V_71 -> V_72 ( V_7 , V_69 ) ;
}
static int F_35 ( struct V_6 * V_7 ,
struct V_1 * V_22 , int V_73 )
{
const unsigned long * V_69 ;
unsigned long * V_74 ;
V_74 = F_36 ( F_33 ( V_7 -> V_68 ) ,
sizeof( * V_74 ) ,
V_75 ) ;
if ( V_74 == NULL )
return - V_76 ;
if ( ! V_7 -> V_68 ) {
F_37 ( 1 , L_5 ) ;
goto V_77;
}
F_38 ( V_74 , V_22 -> V_66 , V_7 -> V_68 ) ;
F_39 ( V_73 , V_74 ) ;
if ( ! F_34 ( V_7 , V_74 ) )
goto V_77;
if ( V_7 -> V_78 ) {
V_69 = F_29 ( V_7 -> V_78 ,
V_7 -> V_68 ,
V_74 , false ) ;
if ( ! V_69 )
goto V_77;
}
F_38 ( V_22 -> V_66 , V_74 , V_7 -> V_68 ) ;
F_40 ( V_74 ) ;
return 0 ;
V_77:
F_40 ( V_74 ) ;
return - V_28 ;
}
static int F_41 ( struct V_1 * V_22 , int V_73 )
{
F_42 ( V_73 , V_22 -> V_66 ) ;
return 0 ;
}
static int F_43 ( struct V_6 * V_7 ,
struct V_1 * V_22 , int V_73 )
{
if ( V_73 > V_7 -> V_68 )
return - V_28 ;
if ( ! V_22 -> V_66 )
return 0 ;
return ! ! F_28 ( V_73 , V_22 -> V_66 ) ;
}
static T_2 F_44 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
const char * V_2 ,
T_1 V_79 )
{
int V_26 ;
bool V_80 ;
struct V_6 * V_7 = F_27 ( V_47 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
struct V_52 * V_53 = F_23 ( V_49 ) ;
V_26 = F_45 ( V_2 , & V_80 ) ;
if ( V_26 < 0 )
return V_26 ;
F_46 ( & V_7 -> V_81 ) ;
if ( F_1 ( V_7 -> V_22 ) ) {
V_26 = - V_82 ;
goto V_83;
}
V_26 = F_43 ( V_7 , V_22 , V_53 -> V_65 ) ;
if ( V_26 < 0 )
goto V_83;
if ( ! V_80 && V_26 ) {
V_26 = F_41 ( V_22 , V_53 -> V_65 ) ;
if ( V_26 )
goto V_83;
} else if ( V_80 && ! V_26 ) {
V_26 = F_35 ( V_7 , V_22 , V_53 -> V_65 ) ;
if ( V_26 )
goto V_83;
}
V_83:
F_47 ( & V_7 -> V_81 ) ;
return V_26 < 0 ? V_26 : V_79 ;
}
static T_2 F_48 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_2 )
{
struct V_6 * V_7 = F_27 ( V_47 ) ;
return sprintf ( V_2 , L_4 , V_7 -> V_22 -> V_84 ) ;
}
static T_2 F_49 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
const char * V_2 ,
T_1 V_79 )
{
int V_26 ;
struct V_6 * V_7 = F_27 ( V_47 ) ;
bool V_80 ;
V_26 = F_45 ( V_2 , & V_80 ) ;
if ( V_26 < 0 )
return V_26 ;
F_46 ( & V_7 -> V_81 ) ;
if ( F_1 ( V_7 -> V_22 ) ) {
V_26 = - V_82 ;
goto V_83;
}
V_7 -> V_22 -> V_84 = V_80 ;
V_83:
F_47 ( & V_7 -> V_81 ) ;
return V_26 ? V_26 : V_79 ;
}
static int F_50 ( struct V_6 * V_7 ,
const struct V_85 * V_86 )
{
int V_26 , V_87 = 0 ;
struct V_1 * V_22 = V_7 -> V_22 ;
V_26 = F_51 ( L_6 ,
V_86 ,
& F_22 ,
NULL ,
0 ,
V_88 ,
& V_7 -> V_47 ,
& V_22 -> V_89 ) ;
if ( V_26 )
return V_26 ;
V_87 ++ ;
V_26 = F_51 ( L_7 ,
V_86 ,
& F_24 ,
NULL ,
0 ,
0 ,
& V_7 -> V_47 ,
& V_22 -> V_89 ) ;
if ( V_26 )
return V_26 ;
V_87 ++ ;
if ( V_86 -> type != V_90 )
V_26 = F_51 ( L_8 ,
V_86 ,
& F_26 ,
& F_44 ,
V_86 -> V_51 ,
0 ,
& V_7 -> V_47 ,
& V_22 -> V_89 ) ;
else
V_26 = F_51 ( L_8 ,
V_86 ,
& F_48 ,
& F_49 ,
V_86 -> V_51 ,
0 ,
& V_7 -> V_47 ,
& V_22 -> V_89 ) ;
if ( V_26 )
return V_26 ;
V_87 ++ ;
V_26 = V_87 ;
return V_26 ;
}
static T_2 F_52 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_2 )
{
struct V_6 * V_7 = F_27 ( V_47 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
return sprintf ( V_2 , L_4 , V_22 -> V_91 ) ;
}
static T_2 F_53 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
const char * V_2 , T_1 V_79 )
{
struct V_6 * V_7 = F_27 ( V_47 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
unsigned int V_92 ;
int V_26 ;
V_26 = F_54 ( V_2 , 10 , & V_92 ) ;
if ( V_26 )
return V_26 ;
if ( V_92 == V_22 -> V_91 )
return V_79 ;
F_46 ( & V_7 -> V_81 ) ;
if ( F_1 ( V_7 -> V_22 ) ) {
V_26 = - V_82 ;
} else {
V_22 -> V_4 -> V_93 ( V_22 , V_92 ) ;
V_26 = 0 ;
}
if ( V_26 )
goto V_94;
if ( V_22 -> V_91 && V_22 -> V_91 < V_22 -> V_32 )
V_22 -> V_32 = V_22 -> V_91 ;
V_94:
F_47 ( & V_7 -> V_81 ) ;
return V_26 ? V_26 : V_79 ;
}
static T_2 F_55 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_2 )
{
struct V_6 * V_7 = F_27 ( V_47 ) ;
return sprintf ( V_2 , L_4 , F_1 ( V_7 -> V_22 ) ) ;
}
static unsigned int F_56 ( struct V_6 * V_7 ,
unsigned int V_51 )
{
const struct V_85 * V_95 ;
unsigned int V_96 ;
V_95 = F_57 ( V_7 , V_51 ) ;
V_96 = V_95 -> V_54 . V_63 / 8 ;
if ( V_95 -> V_54 . V_59 > 1 )
V_96 *= V_95 -> V_54 . V_59 ;
return V_96 ;
}
static unsigned int F_58 ( struct V_6 * V_7 )
{
return F_56 ( V_7 ,
V_7 -> V_97 ) ;
}
static int F_59 ( struct V_6 * V_7 ,
const unsigned long * V_69 , bool V_98 )
{
unsigned V_96 = 0 ;
int V_91 , V_99 ;
F_60 (i, mask,
indio_dev->masklength) {
V_91 = F_56 ( V_7 , V_99 ) ;
V_96 = F_61 ( V_96 , V_91 ) ;
V_96 += V_91 ;
}
if ( V_98 ) {
V_91 = F_58 ( V_7 ) ;
V_96 = F_61 ( V_96 , V_91 ) ;
V_96 += V_91 ;
}
return V_96 ;
}
static void F_62 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
F_63 ( V_22 ) ;
F_64 ( & V_22 -> V_3 , & V_7 -> V_3 ) ;
}
static void F_65 ( struct V_1 * V_22 )
{
F_66 ( & V_22 -> V_3 ) ;
F_67 ( & V_22 -> V_33 ) ;
F_68 ( V_22 ) ;
}
static void F_69 ( struct V_6 * V_7 )
{
struct V_1 * V_22 , * V_100 ;
F_70 (buffer, _buffer,
&indio_dev->buffer_list, buffer_list)
F_65 ( V_22 ) ;
}
static int F_71 ( struct V_1 * V_22 ,
struct V_6 * V_7 )
{
if ( ! V_22 -> V_4 -> V_101 )
return 0 ;
return V_22 -> V_4 -> V_101 ( V_22 , V_7 ) ;
}
static int F_72 ( struct V_1 * V_22 ,
struct V_6 * V_7 )
{
if ( ! V_22 -> V_4 -> V_102 )
return 0 ;
return V_22 -> V_4 -> V_102 ( V_22 , V_7 ) ;
}
static void F_73 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
unsigned int V_96 ;
if ( ! V_22 -> V_4 -> V_103 )
return;
V_96 = F_59 ( V_7 , V_22 -> V_66 ,
V_22 -> V_84 ) ;
V_22 -> V_4 -> V_103 ( V_22 , V_96 ) ;
}
static int F_74 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
int V_26 ;
F_73 ( V_7 , V_22 ) ;
if ( V_22 -> V_4 -> V_104 ) {
V_26 = V_22 -> V_4 -> V_104 ( V_22 ) ;
if ( V_26 ) {
F_75 ( & V_7 -> V_47 ,
L_9 ,
V_26 ) ;
return V_26 ;
}
}
return 0 ;
}
static void F_76 ( struct V_6 * V_7 ,
const unsigned long * V_69 )
{
if ( ! V_7 -> V_78 )
F_40 ( V_69 ) ;
}
static int F_77 ( struct V_6 * V_7 ,
struct V_1 * V_105 , struct V_1 * V_106 ,
struct V_107 * V_108 )
{
unsigned long * V_109 ;
const unsigned long * V_66 ;
bool V_110 = false ;
struct V_1 * V_22 ;
bool V_84 ;
unsigned int V_111 ;
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
V_108 -> V_32 = ~ 0 ;
if ( V_106 && ! V_105 &&
F_78 ( & V_7 -> V_3 ) )
return 0 ;
V_111 = V_7 -> V_111 ;
F_79 (buffer, &indio_dev->buffer_list, buffer_list) {
if ( V_22 == V_106 )
continue;
V_111 &= V_22 -> V_4 -> V_111 ;
V_108 -> V_32 = F_80 ( V_108 -> V_32 , V_22 -> V_32 ) ;
}
if ( V_105 ) {
V_111 &= V_105 -> V_4 -> V_111 ;
V_108 -> V_32 = F_80 ( V_108 -> V_32 ,
V_105 -> V_32 ) ;
}
if ( ( V_111 & V_112 ) && V_7 -> V_113 ) {
V_108 -> V_114 = V_112 ;
} else if ( V_111 & V_115 ) {
if ( V_105 && ! F_2 ( & V_7 -> V_3 ) )
return - V_28 ;
V_108 -> V_114 = V_115 ;
V_110 = true ;
} else if ( V_111 & V_116 ) {
V_108 -> V_114 = V_116 ;
} else {
if ( V_7 -> V_111 & V_112 )
F_75 ( & V_7 -> V_47 , L_10 ) ;
return - V_28 ;
}
V_109 = F_81 ( F_33 ( V_7 -> V_68 ) ,
sizeof( long ) , V_75 ) ;
if ( V_109 == NULL )
return - V_76 ;
V_84 = false ;
F_79 (buffer, &indio_dev->buffer_list, buffer_list) {
if ( V_22 == V_106 )
continue;
F_82 ( V_109 , V_109 , V_22 -> V_66 ,
V_7 -> V_68 ) ;
V_84 |= V_22 -> V_84 ;
}
if ( V_105 ) {
F_82 ( V_109 , V_109 ,
V_105 -> V_66 , V_7 -> V_68 ) ;
V_84 |= V_105 -> V_84 ;
}
if ( V_7 -> V_78 ) {
V_66 = F_29 ( V_7 -> V_78 ,
V_7 -> V_68 ,
V_109 ,
V_110 ) ;
F_40 ( V_109 ) ;
if ( V_66 == NULL )
return - V_28 ;
} else {
V_66 = V_109 ;
}
V_108 -> V_117 = F_59 ( V_7 ,
V_66 , V_84 ) ;
V_108 -> V_66 = V_66 ;
V_108 -> V_84 = V_84 ;
return 0 ;
}
static void F_83 ( struct V_1 * V_22 )
{
struct V_118 * V_119 , * V_120 ;
F_70 (p, q, &buffer->demux_list, l) {
F_84 ( & V_119 -> V_121 ) ;
F_40 ( V_119 ) ;
}
}
static int F_85 ( struct V_1 * V_22 ,
struct V_118 * * V_119 , unsigned int V_122 , unsigned int V_123 ,
unsigned int V_91 )
{
if ( * V_119 && ( * V_119 ) -> V_124 + ( * V_119 ) -> V_91 == V_122 &&
( * V_119 ) -> V_125 + ( * V_119 ) -> V_91 == V_123 ) {
( * V_119 ) -> V_91 += V_91 ;
} else {
* V_119 = F_86 ( sizeof( * * V_119 ) , V_75 ) ;
if ( * V_119 == NULL )
return - V_76 ;
( * V_119 ) -> V_124 = V_122 ;
( * V_119 ) -> V_125 = V_123 ;
( * V_119 ) -> V_91 = V_91 ;
F_87 ( & ( * V_119 ) -> V_121 , & V_22 -> V_42 ) ;
}
return 0 ;
}
static int F_88 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
int V_26 , V_126 = - 1 , V_127 , V_91 ;
unsigned V_122 = 0 , V_123 = 0 ;
struct V_118 * V_119 = NULL ;
F_83 ( V_22 ) ;
F_40 ( V_22 -> V_128 ) ;
V_22 -> V_128 = NULL ;
if ( F_31 ( V_7 -> V_129 ,
V_22 -> V_66 ,
V_7 -> V_68 ) )
return 0 ;
F_60 (out_ind,
buffer->scan_mask,
indio_dev->masklength) {
V_126 = F_89 ( V_7 -> V_129 ,
V_7 -> V_68 ,
V_126 + 1 ) ;
while ( V_126 != V_127 ) {
V_126 = F_89 ( V_7 -> V_129 ,
V_7 -> V_68 ,
V_126 + 1 ) ;
V_91 = F_56 ( V_7 , V_126 ) ;
V_122 = F_90 ( V_122 , V_91 ) + V_91 ;
}
V_91 = F_56 ( V_7 , V_126 ) ;
V_123 = F_90 ( V_123 , V_91 ) ;
V_122 = F_90 ( V_122 , V_91 ) ;
V_26 = F_85 ( V_22 , & V_119 , V_122 , V_123 , V_91 ) ;
if ( V_26 )
goto V_130;
V_123 += V_91 ;
V_122 += V_91 ;
}
if ( V_22 -> V_84 ) {
V_91 = F_58 ( V_7 ) ;
V_123 = F_90 ( V_123 , V_91 ) ;
V_122 = F_90 ( V_122 , V_91 ) ;
V_26 = F_85 ( V_22 , & V_119 , V_122 , V_123 , V_91 ) ;
if ( V_26 )
goto V_130;
V_123 += V_91 ;
V_122 += V_91 ;
}
V_22 -> V_128 = F_91 ( V_123 , V_75 ) ;
if ( V_22 -> V_128 == NULL ) {
V_26 = - V_76 ;
goto V_130;
}
return 0 ;
V_130:
F_83 ( V_22 ) ;
return V_26 ;
}
static int F_92 ( struct V_6 * V_7 )
{
struct V_1 * V_22 ;
int V_26 ;
F_79 (buffer, &indio_dev->buffer_list, buffer_list) {
V_26 = F_88 ( V_7 , V_22 ) ;
if ( V_26 < 0 )
goto V_130;
}
return 0 ;
V_130:
F_79 (buffer, &indio_dev->buffer_list, buffer_list)
F_83 ( V_22 ) ;
return V_26 ;
}
static int F_93 ( struct V_6 * V_7 ,
struct V_107 * V_108 )
{
struct V_1 * V_22 ;
int V_26 ;
V_7 -> V_129 = V_108 -> V_66 ;
V_7 -> V_84 = V_108 -> V_84 ;
V_7 -> V_117 = V_108 -> V_117 ;
F_92 ( V_7 ) ;
if ( V_7 -> V_71 -> V_131 ) {
V_26 = V_7 -> V_71 -> V_131 ( V_7 ) ;
if ( V_26 ) {
F_75 ( & V_7 -> V_47 ,
L_11 , V_26 ) ;
goto V_132;
}
}
if ( V_7 -> V_9 -> V_133 ) {
V_26 = V_7 -> V_9
-> V_133 ( V_7 ,
V_7 -> V_129 ) ;
if ( V_26 < 0 ) {
F_75 ( & V_7 -> V_47 ,
L_12 ,
V_26 ) ;
goto V_134;
}
}
if ( V_7 -> V_9 -> V_135 )
V_7 -> V_9 -> V_135 ( V_7 ,
V_108 -> V_32 ) ;
F_79 (buffer, &indio_dev->buffer_list, buffer_list) {
V_26 = F_71 ( V_22 , V_7 ) ;
if ( V_26 )
goto V_136;
}
V_7 -> V_137 = V_108 -> V_114 ;
if ( V_7 -> V_71 -> V_138 ) {
V_26 = V_7 -> V_71 -> V_138 ( V_7 ) ;
if ( V_26 ) {
F_75 ( & V_7 -> V_47 ,
L_13 , V_26 ) ;
goto V_136;
}
}
return 0 ;
V_136:
F_94 (buffer, &indio_dev->buffer_list,
buffer_list)
F_72 ( V_22 , V_7 ) ;
V_134:
V_7 -> V_137 = V_139 ;
if ( V_7 -> V_71 -> V_140 )
V_7 -> V_71 -> V_140 ( V_7 ) ;
V_132:
V_7 -> V_129 = NULL ;
return V_26 ;
}
static int F_95 ( struct V_6 * V_7 )
{
struct V_1 * V_22 ;
int V_26 = 0 ;
int V_141 ;
if ( F_2 ( & V_7 -> V_3 ) )
return 0 ;
if ( V_7 -> V_71 -> V_142 ) {
V_141 = V_7 -> V_71 -> V_142 ( V_7 ) ;
if ( V_141 && ! V_26 )
V_26 = V_141 ;
}
F_79 (buffer, &indio_dev->buffer_list, buffer_list) {
V_141 = F_72 ( V_22 , V_7 ) ;
if ( V_141 && ! V_26 )
V_26 = V_141 ;
}
V_7 -> V_137 = V_139 ;
if ( V_7 -> V_71 -> V_140 ) {
V_141 = V_7 -> V_71 -> V_140 ( V_7 ) ;
if ( V_141 && ! V_26 )
V_26 = V_141 ;
}
F_76 ( V_7 , V_7 -> V_129 ) ;
V_7 -> V_129 = NULL ;
return V_26 ;
}
static int F_96 ( struct V_6 * V_7 ,
struct V_1 * V_105 ,
struct V_1 * V_106 )
{
struct V_107 V_143 ;
int V_26 ;
V_26 = F_77 ( V_7 , V_105 , V_106 ,
& V_143 ) ;
if ( V_26 )
return V_26 ;
if ( V_105 ) {
V_26 = F_74 ( V_7 , V_105 ) ;
if ( V_26 )
goto V_144;
}
V_26 = F_95 ( V_7 ) ;
if ( V_26 )
goto V_145;
if ( V_106 )
F_65 ( V_106 ) ;
if ( V_105 )
F_62 ( V_7 , V_105 ) ;
if ( F_2 ( & V_7 -> V_3 ) )
return 0 ;
V_26 = F_93 ( V_7 , & V_143 ) ;
if ( V_26 )
goto V_145;
return 0 ;
V_145:
F_69 ( V_7 ) ;
V_144:
F_76 ( V_7 , V_143 . V_66 ) ;
return V_26 ;
}
int F_97 ( struct V_6 * V_7 ,
struct V_1 * V_105 ,
struct V_1 * V_106 )
{
int V_26 ;
if ( V_105 == V_106 )
return 0 ;
F_46 ( & V_7 -> V_146 ) ;
F_46 ( & V_7 -> V_81 ) ;
if ( V_105 && F_1 ( V_105 ) )
V_105 = NULL ;
if ( V_106 && ! F_1 ( V_106 ) )
V_106 = NULL ;
if ( ! V_105 && ! V_106 ) {
V_26 = 0 ;
goto V_147;
}
if ( V_7 -> V_9 == NULL ) {
V_26 = - V_11 ;
goto V_147;
}
V_26 = F_96 ( V_7 , V_105 , V_106 ) ;
V_147:
F_47 ( & V_7 -> V_81 ) ;
F_47 ( & V_7 -> V_146 ) ;
return V_26 ;
}
void F_98 ( struct V_6 * V_7 )
{
F_95 ( V_7 ) ;
F_69 ( V_7 ) ;
}
static T_2 F_99 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
const char * V_2 ,
T_1 V_79 )
{
int V_26 ;
bool V_148 ;
struct V_6 * V_7 = F_27 ( V_47 ) ;
bool V_149 ;
V_26 = F_45 ( V_2 , & V_148 ) ;
if ( V_26 < 0 )
return V_26 ;
F_46 ( & V_7 -> V_81 ) ;
V_149 = F_1 ( V_7 -> V_22 ) ;
if ( V_149 == V_148 )
goto V_150;
if ( V_148 )
V_26 = F_96 ( V_7 ,
V_7 -> V_22 , NULL ) ;
else
V_26 = F_96 ( V_7 ,
NULL , V_7 -> V_22 ) ;
V_150:
F_47 ( & V_7 -> V_81 ) ;
return ( V_26 < 0 ) ? V_26 : V_79 ;
}
static T_2 F_100 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_2 )
{
struct V_6 * V_7 = F_27 ( V_47 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
return sprintf ( V_2 , L_1 , V_22 -> V_32 ) ;
}
static T_2 F_101 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
const char * V_2 ,
T_1 V_79 )
{
struct V_6 * V_7 = F_27 ( V_47 ) ;
struct V_1 * V_22 = V_7 -> V_22 ;
unsigned int V_92 ;
int V_26 ;
V_26 = F_54 ( V_2 , 10 , & V_92 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_92 )
return - V_28 ;
F_46 ( & V_7 -> V_81 ) ;
if ( V_92 > V_22 -> V_91 ) {
V_26 = - V_28 ;
goto V_94;
}
if ( F_1 ( V_7 -> V_22 ) ) {
V_26 = - V_82 ;
goto V_94;
}
V_22 -> V_32 = V_92 ;
V_94:
F_47 ( & V_7 -> V_81 ) ;
return V_26 ? V_26 : V_79 ;
}
int F_102 ( struct V_6 * V_7 )
{
struct V_52 * V_119 ;
struct V_44 * * V_49 ;
struct V_1 * V_22 = V_7 -> V_22 ;
int V_26 , V_99 , V_151 , V_87 , V_152 = 0 ;
const struct V_85 * V_153 ;
V_153 = V_7 -> V_153 ;
if ( V_153 ) {
int V_154 = V_7 -> V_68 ;
for ( V_99 = 0 ; V_99 < V_7 -> V_155 ; V_99 ++ )
V_154 = F_103 ( V_154 , V_153 [ V_99 ] . V_51 + 1 ) ;
V_7 -> V_68 = V_154 ;
}
if ( ! V_22 )
return 0 ;
V_87 = 0 ;
if ( V_22 -> V_45 ) {
while ( V_22 -> V_45 [ V_87 ] != NULL )
V_87 ++ ;
}
V_49 = F_81 ( V_87 + F_104 ( V_156 ) + 1 ,
sizeof( struct V_44 * ) , V_75 ) ;
if ( ! V_49 )
return - V_76 ;
memcpy ( V_49 , V_156 , sizeof( V_156 ) ) ;
if ( ! V_22 -> V_4 -> V_93 )
V_49 [ 0 ] = & V_157 . V_49 ;
if ( V_22 -> V_4 -> V_158 & V_159 )
V_49 [ 2 ] = & V_160 . V_49 ;
if ( V_22 -> V_45 )
memcpy ( & V_49 [ F_104 ( V_156 ) ] , V_22 -> V_45 ,
sizeof( struct V_44 * ) * V_87 ) ;
V_49 [ V_87 + F_104 ( V_156 ) ] = NULL ;
V_22 -> V_161 . V_162 = L_14 ;
V_22 -> V_161 . V_45 = V_49 ;
V_7 -> V_163 [ V_7 -> V_164 ++ ] = & V_22 -> V_161 ;
if ( V_22 -> V_165 != NULL ) {
V_49 = V_22 -> V_165 -> V_45 ;
while ( * V_49 ++ != NULL )
V_152 ++ ;
}
V_87 = V_152 ;
F_18 ( & V_22 -> V_89 ) ;
V_153 = V_7 -> V_153 ;
if ( V_153 ) {
for ( V_99 = 0 ; V_99 < V_7 -> V_155 ; V_99 ++ ) {
if ( V_153 [ V_99 ] . V_51 < 0 )
continue;
V_26 = F_50 ( V_7 ,
& V_153 [ V_99 ] ) ;
if ( V_26 < 0 )
goto V_166;
V_87 += V_26 ;
if ( V_153 [ V_99 ] . type == V_90 )
V_7 -> V_97 =
V_153 [ V_99 ] . V_51 ;
}
if ( V_7 -> V_68 && V_22 -> V_66 == NULL ) {
V_22 -> V_66 = F_81 ( F_33 ( V_7 -> V_68 ) ,
sizeof( * V_22 -> V_66 ) ,
V_75 ) ;
if ( V_22 -> V_66 == NULL ) {
V_26 = - V_76 ;
goto V_166;
}
}
}
V_22 -> V_167 . V_162 = V_168 ;
V_22 -> V_167 . V_45 = F_81 ( V_87 + 1 ,
sizeof( V_22 -> V_167 . V_45 [ 0 ] ) ,
V_75 ) ;
if ( V_22 -> V_167 . V_45 == NULL ) {
V_26 = - V_76 ;
goto V_169;
}
if ( V_22 -> V_165 )
memcpy ( V_22 -> V_167 . V_45 , V_22 -> V_165 ,
sizeof( V_22 -> V_167 . V_45 [ 0 ] ) * V_152 ) ;
V_151 = V_152 ;
F_79 (p, &buffer->scan_el_dev_attr_list, l)
V_22 -> V_167 . V_45 [ V_151 ++ ] = & V_119 -> V_170 . V_49 ;
V_7 -> V_163 [ V_7 -> V_164 ++ ] = & V_22 -> V_167 ;
return 0 ;
V_169:
F_40 ( V_22 -> V_66 ) ;
V_166:
F_105 ( & V_22 -> V_89 ) ;
F_40 ( V_7 -> V_22 -> V_161 . V_45 ) ;
return V_26 ;
}
void F_106 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_22 )
return;
F_40 ( V_7 -> V_22 -> V_66 ) ;
F_40 ( V_7 -> V_22 -> V_161 . V_45 ) ;
F_40 ( V_7 -> V_22 -> V_167 . V_45 ) ;
F_105 ( & V_7 -> V_22 -> V_89 ) ;
}
bool F_107 ( struct V_6 * V_7 ,
const unsigned long * V_69 )
{
return F_108 ( V_69 , V_7 -> V_68 ) == 1 ;
}
static const void * F_109 ( struct V_1 * V_22 ,
const void * V_171 )
{
struct V_118 * V_172 ;
if ( F_2 ( & V_22 -> V_42 ) )
return V_171 ;
F_79 (t, &buffer->demux_list, l)
memcpy ( V_22 -> V_128 + V_172 -> V_125 ,
V_171 + V_172 -> V_124 , V_172 -> V_91 ) ;
return V_22 -> V_128 ;
}
static int F_110 ( struct V_1 * V_22 , const void * V_173 )
{
const void * V_174 = F_109 ( V_22 , V_173 ) ;
int V_26 ;
V_26 = V_22 -> V_4 -> V_175 ( V_22 , V_174 ) ;
if ( V_26 )
return V_26 ;
F_111 ( & V_22 -> V_33 , V_40 | V_41 ) ;
return 0 ;
}
int F_112 ( struct V_6 * V_7 , const void * V_173 )
{
int V_26 ;
struct V_1 * V_2 ;
F_79 (buf, &indio_dev->buffer_list, buffer_list) {
V_26 = F_110 ( V_2 , V_173 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return 0 ;
}
static void F_113 ( struct V_176 * V_43 )
{
struct V_1 * V_22 = F_114 ( V_43 , struct V_1 , V_43 ) ;
V_22 -> V_4 -> V_177 ( V_22 ) ;
}
struct V_1 * F_63 ( struct V_1 * V_22 )
{
if ( V_22 )
F_115 ( & V_22 -> V_43 ) ;
return V_22 ;
}
void F_68 ( struct V_1 * V_22 )
{
if ( V_22 )
F_116 ( & V_22 -> V_43 , F_113 ) ;
}
void F_117 ( struct V_6 * V_7 ,
struct V_1 * V_22 )
{
V_7 -> V_22 = F_63 ( V_22 ) ;
}
