static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 [ 0 ] . V_4 == V_5 ;
}
static void F_2 ( struct V_6 * V_7 )
{
V_7 -> V_8 . V_3 [ 0 ] . V_4 = V_5 ;
}
static void F_3 ( struct V_6 * V_7 )
{
V_7 -> V_8 . V_3 [ 0 ] . V_4 = NULL ;
}
void F_4 ( struct V_9 * V_10 )
{
if ( ! V_10 )
return;
F_5 ( & V_10 -> V_11 ) ;
F_6 ( & V_10 -> V_12 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 . V_13 )
F_7 ( V_7 -> V_8 . V_13 ) ;
F_8 ( L_1 , V_7 -> V_8 . V_3 [ 0 ] . V_14 ) ;
}
static int F_9 ( const char * V_15 , int V_16 , const char * V_17 , int V_18 )
{
int V_19 ;
int V_20 ;
V_19 = V_16 ;
if ( V_19 > V_18 )
V_19 = V_18 ;
V_20 = memcmp ( V_15 , V_17 , V_19 ) ;
if ( V_20 == 0 )
V_20 = V_16 - V_18 ;
return V_20 ;
}
static struct V_3 * F_10 ( struct V_1 * * V_21 ,
struct V_6 * V_7 , const char * V_22 , int V_23 )
{
struct V_1 * V_2 ;
struct V_3 * V_24 ;
struct V_25 * V_26 = V_7 -> V_27 . V_25 ;
while ( V_26 )
{
struct V_28 * V_28 ;
const char * V_14 ;
int V_20 ;
V_28 = F_11 ( V_26 , struct V_28 , V_26 ) ;
V_2 = V_28 -> V_8 ;
V_24 = & V_2 -> V_3 [ V_28 - V_2 -> V_26 ] ;
V_14 = V_24 -> V_14 ;
V_20 = F_9 ( V_22 , V_23 , V_14 , strlen ( V_14 ) ) ;
if ( V_20 < 0 )
V_26 = V_26 -> V_29 ;
else if ( V_20 > 0 )
V_26 = V_26 -> V_30 ;
else {
* V_21 = V_2 ;
return V_24 ;
}
}
return NULL ;
}
static int F_12 ( struct V_1 * V_2 , struct V_3 * V_24 )
{
struct V_25 * V_26 = & V_2 -> V_26 [ V_24 - V_2 -> V_3 ] . V_26 ;
struct V_25 * * V_31 = & V_2 -> V_13 -> V_27 . V_25 ;
struct V_25 * V_13 = NULL ;
const char * V_22 = V_24 -> V_14 ;
int V_23 = strlen ( V_22 ) ;
while ( * V_31 ) {
struct V_1 * V_32 ;
struct V_3 * V_33 ;
struct V_28 * V_34 ;
const char * V_35 ;
int V_20 ;
V_13 = * V_31 ;
V_34 = F_11 ( V_13 , struct V_28 , V_26 ) ;
V_32 = V_34 -> V_8 ;
V_33 = & V_32 -> V_3 [ V_34 - V_32 -> V_26 ] ;
V_35 = V_33 -> V_14 ;
V_20 = F_9 ( V_22 , V_23 , V_35 , strlen ( V_35 ) ) ;
if ( V_20 < 0 )
V_31 = & ( * V_31 ) -> V_29 ;
else if ( V_20 > 0 )
V_31 = & ( * V_31 ) -> V_30 ;
else {
F_13 ( L_2 ) ;
F_7 ( V_2 -> V_13 ) ;
F_8 ( L_3 , V_24 -> V_14 ) ;
return - V_36 ;
}
}
F_14 ( V_26 , V_13 , V_31 ) ;
F_15 ( V_26 , & V_2 -> V_13 -> V_27 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , struct V_3 * V_24 )
{
struct V_25 * V_26 = & V_2 -> V_26 [ V_24 - V_2 -> V_3 ] . V_26 ;
F_17 ( V_26 , & V_2 -> V_13 -> V_27 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_37 * V_27 , struct V_38 * V_39 ,
struct V_28 * V_26 , struct V_3 * V_40 )
{
V_2 -> V_3 = V_40 ;
V_2 -> V_41 = V_40 ;
V_2 -> V_42 = 0 ;
V_2 -> V_43 = 1 ;
V_2 -> V_44 = 1 ;
V_2 -> V_45 = NULL ;
V_2 -> V_27 = V_27 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_13 = NULL ;
V_2 -> V_26 = V_26 ;
if ( V_26 ) {
struct V_3 * V_24 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ , V_26 ++ )
V_26 -> V_8 = V_2 ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_24 ;
for ( V_24 = V_2 -> V_3 ; V_24 -> V_14 ; V_24 ++ )
F_16 ( V_2 , V_24 ) ;
}
static int F_20 ( struct V_6 * V_7 , struct V_1 * V_8 )
{
struct V_3 * V_24 ;
int V_46 ;
if ( F_1 ( & V_7 -> V_8 ) )
return - V_47 ;
if ( V_8 -> V_3 == V_5 ) {
if ( ! F_21 ( & V_7 -> V_27 ) )
return - V_48 ;
F_2 ( V_7 ) ;
}
V_7 -> V_8 . V_44 ++ ;
V_8 -> V_13 = V_7 ;
V_46 = F_22 ( V_8 ) ;
if ( V_46 )
goto V_49;
for ( V_24 = V_8 -> V_3 ; V_24 -> V_14 ; V_24 ++ ) {
V_46 = F_12 ( V_8 , V_24 ) ;
if ( V_46 )
goto V_50;
}
return 0 ;
V_50:
F_19 ( V_8 ) ;
F_23 ( V_8 ) ;
V_49:
if ( V_8 -> V_3 == V_5 )
F_3 ( V_7 ) ;
V_8 -> V_13 = NULL ;
F_24 ( & V_7 -> V_8 ) ;
return V_46 ;
}
static int F_25 ( struct V_1 * V_31 )
{
if ( F_26 ( V_31 -> V_45 ) )
return 0 ;
V_31 -> V_42 ++ ;
return 1 ;
}
static void F_27 ( struct V_1 * V_31 )
{
if ( ! -- V_31 -> V_42 )
if ( F_26 ( V_31 -> V_45 ) )
F_28 ( V_31 -> V_45 ) ;
}
static void F_29 ( struct V_1 * V_31 )
{
if ( F_26 ( V_31 -> V_42 ) ) {
struct V_51 V_12 ;
F_30 ( & V_12 ) ;
V_31 -> V_45 = & V_12 ;
F_31 ( & V_52 ) ;
F_32 ( & V_12 ) ;
F_33 ( & V_52 ) ;
} else {
V_31 -> V_45 = F_34 ( - V_48 ) ;
}
F_19 ( V_31 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_33 ( & V_52 ) ;
V_2 -> V_43 ++ ;
F_31 ( & V_52 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_33 ( & V_52 ) ;
if ( ! -- V_2 -> V_43 )
F_37 ( V_2 , V_53 ) ;
F_31 ( & V_52 ) ;
}
static struct V_1 * F_38 ( struct V_1 * V_2 )
{
F_39 ( ! V_2 ) ;
F_33 ( & V_52 ) ;
if ( ! F_25 ( V_2 ) )
V_2 = F_34 ( - V_54 ) ;
F_31 ( & V_52 ) ;
return V_2 ;
}
static void F_40 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_33 ( & V_52 ) ;
F_27 ( V_2 ) ;
F_31 ( & V_52 ) ;
}
static struct V_38 *
F_41 ( struct V_37 * V_27 )
{
struct V_38 * V_39 = & V_27 -> V_55 ;
if ( V_27 -> V_56 )
V_39 = V_27 -> V_56 ( V_27 ) ;
return V_39 ;
}
static struct V_3 * F_42 ( struct V_1 * * V_21 ,
struct V_6 * V_7 ,
const char * V_22 , int V_23 )
{
struct V_1 * V_2 ;
struct V_3 * V_24 ;
F_33 ( & V_52 ) ;
V_24 = F_10 ( & V_2 , V_7 , V_22 , V_23 ) ;
if ( V_24 && F_25 ( V_2 ) )
* V_21 = V_2 ;
else
V_24 = NULL ;
F_31 ( & V_52 ) ;
return V_24 ;
}
static struct V_28 * F_43 ( struct V_25 * V_26 )
{
struct V_28 * V_28 ;
for (; V_26 ; V_26 = F_44 ( V_26 ) ) {
V_28 = F_11 ( V_26 , struct V_28 , V_26 ) ;
if ( F_25 ( V_28 -> V_8 ) )
return V_28 ;
}
return NULL ;
}
static void F_45 ( struct V_6 * V_7 ,
struct V_1 * * V_21 , struct V_3 * * V_57 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_24 = NULL ;
struct V_28 * V_28 ;
F_33 ( & V_52 ) ;
V_28 = F_43 ( F_46 ( & V_7 -> V_27 ) ) ;
F_31 ( & V_52 ) ;
if ( V_28 ) {
V_2 = V_28 -> V_8 ;
V_24 = & V_2 -> V_3 [ V_28 - V_2 -> V_26 ] ;
}
* V_21 = V_2 ;
* V_57 = V_24 ;
}
static void F_47 ( struct V_1 * * V_21 , struct V_3 * * V_57 )
{
struct V_1 * V_2 = * V_21 ;
struct V_3 * V_24 = * V_57 ;
struct V_28 * V_28 = & V_2 -> V_26 [ V_24 - V_2 -> V_3 ] ;
F_33 ( & V_52 ) ;
F_27 ( V_2 ) ;
V_28 = F_43 ( F_44 ( & V_28 -> V_26 ) ) ;
F_31 ( & V_52 ) ;
V_2 = NULL ;
if ( V_28 ) {
V_2 = V_28 -> V_8 ;
V_24 = & V_2 -> V_3 [ V_28 - V_2 -> V_26 ] ;
}
* V_21 = V_2 ;
* V_57 = V_24 ;
}
void F_48 ( struct V_37 * V_27 )
{
}
static int F_49 ( int V_58 , int V_59 )
{
if ( F_50 ( F_51 () , V_60 ) )
V_58 >>= 6 ;
else if ( F_52 ( V_61 ) )
V_58 >>= 3 ;
if ( ( V_59 & ~ V_58 & ( V_62 | V_63 | V_64 ) ) == 0 )
return 0 ;
return - V_65 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_3 * V_40 , int V_59 )
{
struct V_37 * V_27 = V_2 -> V_27 ;
int V_58 ;
if ( V_27 -> V_66 )
V_58 = V_27 -> V_66 ( V_2 , V_40 ) ;
else
V_58 = V_40 -> V_58 ;
return F_49 ( V_58 , V_59 ) ;
}
static struct V_67 * F_54 ( struct V_68 * V_69 ,
struct V_1 * V_2 , struct V_3 * V_40 )
{
struct V_37 * V_27 = V_2 -> V_27 ;
struct V_67 * V_67 ;
struct V_70 * V_71 ;
V_67 = F_55 ( V_69 ) ;
if ( ! V_67 )
goto V_72;
V_67 -> V_73 = F_56 () ;
F_35 ( V_2 ) ;
V_71 = F_57 ( V_67 ) ;
V_71 -> V_74 = V_2 ;
V_71 -> V_75 = V_40 ;
V_67 -> V_76 = V_67 -> V_77 = V_67 -> V_78 = F_58 ( V_67 ) ;
V_67 -> V_79 = V_40 -> V_58 ;
if ( ! F_59 ( V_40 -> V_58 ) ) {
V_67 -> V_79 |= V_80 ;
V_67 -> V_81 = & V_82 ;
V_67 -> V_83 = & V_84 ;
} else {
V_67 -> V_79 |= V_85 ;
V_67 -> V_81 = & V_86 ;
V_67 -> V_83 = & V_87 ;
if ( F_1 ( V_2 ) )
F_60 ( V_67 ) ;
}
if ( V_27 -> V_88 )
V_27 -> V_88 ( V_2 , V_40 , & V_67 -> V_89 , & V_67 -> V_90 ) ;
V_72:
return V_67 ;
}
static struct V_1 * F_61 ( struct V_67 * V_67 )
{
struct V_1 * V_2 = F_57 ( V_67 ) -> V_74 ;
if ( ! V_2 )
V_2 = & V_91 . V_55 . V_7 . V_8 ;
return F_38 ( V_2 ) ;
}
static struct V_92 * F_62 ( struct V_67 * V_7 , struct V_92 * V_92 ,
unsigned int V_93 )
{
struct V_1 * V_2 = F_61 ( V_7 ) ;
struct V_1 * V_94 = NULL ;
const struct V_95 * V_22 = & V_92 -> V_96 ;
struct V_3 * V_31 ;
struct V_67 * V_67 ;
struct V_92 * V_46 = F_34 ( - V_54 ) ;
struct V_6 * V_6 ;
int V_97 ;
if ( F_63 ( V_2 ) )
return F_64 ( V_2 ) ;
V_6 = F_65 ( V_2 , struct V_6 , V_8 ) ;
V_31 = F_42 ( & V_94 , V_6 , V_22 -> V_22 , V_22 -> V_98 ) ;
if ( ! V_31 )
goto V_72;
if ( F_66 ( V_31 -> V_58 ) ) {
V_97 = F_67 ( & V_94 , & V_31 ) ;
V_46 = F_34 ( V_97 ) ;
if ( V_97 )
goto V_72;
}
V_46 = F_34 ( - V_99 ) ;
V_67 = F_54 ( V_7 -> V_100 , V_94 ? V_94 : V_2 , V_31 ) ;
if ( ! V_67 )
goto V_72;
V_46 = NULL ;
F_68 ( V_92 , & V_101 ) ;
F_69 ( V_92 , V_67 ) ;
V_72:
if ( V_94 )
F_40 ( V_94 ) ;
F_40 ( V_2 ) ;
return V_46 ;
}
static T_1 F_70 ( struct V_102 * V_103 , void T_2 * V_104 ,
T_3 V_43 , T_4 * V_105 , int V_106 )
{
struct V_67 * V_67 = F_71 ( V_103 ) ;
struct V_1 * V_2 = F_61 ( V_67 ) ;
struct V_3 * V_40 = F_57 ( V_67 ) -> V_75 ;
T_1 error ;
T_3 V_107 ;
if ( F_63 ( V_2 ) )
return F_72 ( V_2 ) ;
error = - V_108 ;
if ( F_53 ( V_2 , V_40 , V_106 ? V_63 : V_62 ) )
goto V_72;
error = - V_48 ;
if ( ! V_40 -> V_109 )
goto V_72;
V_107 = V_43 ;
error = V_40 -> V_109 ( V_40 , V_106 , V_104 , & V_107 , V_105 ) ;
if ( ! error )
error = V_107 ;
V_72:
F_40 ( V_2 ) ;
return error ;
}
static T_1 F_73 ( struct V_102 * V_103 , char T_2 * V_104 ,
T_3 V_43 , T_4 * V_105 )
{
return F_70 ( V_103 , ( void T_2 * ) V_104 , V_43 , V_105 , 0 ) ;
}
static T_1 F_74 ( struct V_102 * V_103 , const char T_2 * V_104 ,
T_3 V_43 , T_4 * V_105 )
{
return F_70 ( V_103 , ( void T_2 * ) V_104 , V_43 , V_105 , 1 ) ;
}
static int F_75 ( struct V_67 * V_67 , struct V_102 * V_103 )
{
struct V_1 * V_2 = F_61 ( V_67 ) ;
struct V_3 * V_40 = F_57 ( V_67 ) -> V_75 ;
if ( F_63 ( V_2 ) )
return F_72 ( V_2 ) ;
if ( V_40 -> V_10 )
V_103 -> V_110 = F_76 ( V_40 -> V_10 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
static unsigned int F_77 ( struct V_102 * V_103 , T_5 * V_12 )
{
struct V_67 * V_67 = F_71 ( V_103 ) ;
struct V_1 * V_2 = F_61 ( V_67 ) ;
struct V_3 * V_40 = F_57 ( V_67 ) -> V_75 ;
unsigned int V_97 = V_111 ;
unsigned long V_11 ;
if ( F_63 ( V_2 ) )
return V_112 | V_113 ;
if ( ! V_40 -> V_109 )
goto V_72;
if ( ! V_40 -> V_10 )
goto V_72;
V_11 = ( unsigned long ) V_103 -> V_110 ;
F_78 ( V_103 , & V_40 -> V_10 -> V_12 , V_12 ) ;
if ( V_11 != F_79 ( & V_40 -> V_10 -> V_11 ) ) {
V_103 -> V_110 = F_76 ( V_40 -> V_10 ) ;
V_97 = V_114 | V_115 | V_112 | V_116 ;
}
V_72:
F_40 ( V_2 ) ;
return V_97 ;
}
static bool F_80 ( struct V_102 * V_102 ,
struct V_117 * V_118 ,
struct V_1 * V_2 ,
struct V_3 * V_40 )
{
struct V_92 * V_4 , * V_7 = V_102 -> V_119 . V_92 ;
struct V_67 * V_67 ;
struct V_95 V_120 ;
T_6 V_121 = 0 ;
unsigned type = V_122 ;
V_120 . V_22 = V_40 -> V_14 ;
V_120 . V_98 = strlen ( V_40 -> V_14 ) ;
V_120 . V_123 = F_81 ( V_7 , V_120 . V_22 , V_120 . V_98 ) ;
V_4 = F_82 ( V_7 , & V_120 ) ;
if ( ! V_4 ) {
F_83 ( V_124 ) ;
V_4 = F_84 ( V_7 , & V_120 , & V_124 ) ;
if ( F_63 ( V_4 ) )
return false ;
if ( F_85 ( V_4 ) ) {
V_67 = F_54 ( V_7 -> V_125 , V_2 , V_40 ) ;
if ( ! V_67 ) {
F_86 ( V_4 ) ;
F_87 ( V_4 ) ;
return false ;
}
F_68 ( V_4 , & V_101 ) ;
F_69 ( V_4 , V_67 ) ;
}
}
V_67 = F_88 ( V_4 ) ;
V_121 = V_67 -> V_73 ;
type = V_67 -> V_79 >> 12 ;
F_87 ( V_4 ) ;
return F_89 ( V_118 , V_120 . V_22 , V_120 . V_98 , V_121 , type ) ;
}
static bool F_90 ( struct V_102 * V_102 ,
struct V_117 * V_118 ,
struct V_1 * V_2 ,
struct V_3 * V_40 )
{
bool V_97 = true ;
V_2 = F_38 ( V_2 ) ;
if ( F_66 ( V_40 -> V_58 ) ) {
int V_46 = F_67 ( & V_2 , & V_40 ) ;
if ( V_46 )
goto V_72;
}
V_97 = F_80 ( V_102 , V_118 , V_2 , V_40 ) ;
V_72:
F_40 ( V_2 ) ;
return V_97 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_3 * V_40 ,
unsigned long * V_126 , struct V_102 * V_102 ,
struct V_117 * V_118 )
{
bool V_107 ;
if ( ( * V_126 ) ++ < V_118 -> V_126 )
return true ;
if ( F_26 ( F_66 ( V_40 -> V_58 ) ) )
V_107 = F_90 ( V_102 , V_118 , V_2 , V_40 ) ;
else
V_107 = F_80 ( V_102 , V_118 , V_2 , V_40 ) ;
if ( V_107 )
V_118 -> V_126 = * V_126 ;
return V_107 ;
}
static int F_92 ( struct V_102 * V_102 , struct V_117 * V_118 )
{
struct V_1 * V_2 = F_61 ( F_71 ( V_102 ) ) ;
struct V_1 * V_94 = NULL ;
struct V_3 * V_24 ;
struct V_6 * V_6 ;
unsigned long V_126 ;
if ( F_63 ( V_2 ) )
return F_72 ( V_2 ) ;
V_6 = F_65 ( V_2 , struct V_6 , V_8 ) ;
if ( ! F_93 ( V_102 , V_118 ) )
goto V_72;
V_126 = 2 ;
for ( F_45 ( V_6 , & V_94 , & V_24 ) ; V_94 ; F_47 ( & V_94 , & V_24 ) ) {
if ( ! F_91 ( V_94 , V_24 , & V_126 , V_102 , V_118 ) ) {
F_40 ( V_94 ) ;
break;
}
}
V_72:
F_40 ( V_2 ) ;
return 0 ;
}
static int F_94 ( struct V_67 * V_67 , int V_127 )
{
struct V_1 * V_2 ;
struct V_3 * V_40 ;
int error ;
if ( ( V_127 & V_64 ) && F_95 ( V_67 -> V_79 ) )
return - V_65 ;
V_2 = F_61 ( V_67 ) ;
if ( F_63 ( V_2 ) )
return F_72 ( V_2 ) ;
V_40 = F_57 ( V_67 ) -> V_75 ;
if ( ! V_40 )
error = V_127 & V_63 ? - V_65 : 0 ;
else
error = F_53 ( V_2 , V_40 , V_127 & ~ V_128 ) ;
F_40 ( V_2 ) ;
return error ;
}
static int F_96 ( struct V_92 * V_92 , struct V_129 * V_130 )
{
struct V_67 * V_67 = F_88 ( V_92 ) ;
int error ;
if ( V_130 -> V_131 & ( V_132 | V_133 | V_134 ) )
return - V_108 ;
error = F_97 ( V_92 , V_130 ) ;
if ( error )
return error ;
F_98 ( V_67 , V_130 ) ;
F_99 ( V_67 ) ;
return 0 ;
}
static int F_100 ( struct V_135 * V_136 , struct V_92 * V_92 , struct V_137 * V_138 )
{
struct V_67 * V_67 = F_88 ( V_92 ) ;
struct V_1 * V_2 = F_61 ( V_67 ) ;
struct V_3 * V_40 = F_57 ( V_67 ) -> V_75 ;
if ( F_63 ( V_2 ) )
return F_72 ( V_2 ) ;
F_101 ( V_67 , V_138 ) ;
if ( V_40 )
V_138 -> V_58 = ( V_138 -> V_58 & V_139 ) | V_40 -> V_58 ;
F_40 ( V_2 ) ;
return 0 ;
}
static int F_102 ( struct V_92 * V_92 , unsigned int V_93 )
{
if ( V_93 & V_140 )
return - V_141 ;
return ! F_57 ( F_88 ( V_92 ) ) -> V_74 -> V_45 ;
}
static int F_103 ( const struct V_92 * V_92 )
{
return ! ! F_57 ( F_88 ( V_92 ) ) -> V_74 -> V_45 ;
}
static int F_104 ( struct V_1 * V_31 )
{
struct V_38 * V_39 = V_31 -> V_39 ;
int V_107 ;
F_33 ( & V_52 ) ;
if ( V_31 -> V_45 )
V_107 = 0 ;
else if ( ! V_39 -> V_142 )
V_107 = 1 ;
else
V_107 = V_39 -> V_142 ( V_39 ) ;
F_31 ( & V_52 ) ;
return V_107 ;
}
static int F_105 ( const struct V_92 * V_92 ,
unsigned int V_98 , const char * V_143 , const struct V_95 * V_22 )
{
struct V_1 * V_2 ;
struct V_67 * V_67 ;
V_67 = F_106 ( V_92 ) ;
if ( ! V_67 )
return 1 ;
if ( V_22 -> V_98 != V_98 )
return 1 ;
if ( memcmp ( V_22 -> V_22 , V_143 , V_98 ) )
return 1 ;
V_2 = F_107 ( F_57 ( V_67 ) -> V_74 ) ;
return ! V_2 || ! F_104 ( V_2 ) ;
}
static struct V_6 * F_108 ( struct V_6 * V_7 ,
const char * V_22 , int V_23 )
{
struct V_1 * V_2 ;
struct V_3 * V_24 ;
V_24 = F_10 ( & V_2 , V_7 , V_22 , V_23 ) ;
if ( ! V_24 )
return F_34 ( - V_54 ) ;
if ( ! F_59 ( V_24 -> V_58 ) )
return F_34 ( - V_144 ) ;
return F_65 ( V_2 , struct V_6 , V_8 ) ;
}
static struct V_6 * F_109 ( struct V_38 * V_39 ,
const char * V_22 , int V_23 )
{
struct V_3 * V_40 ;
struct V_6 * V_145 ;
struct V_28 * V_26 ;
char * V_146 ;
V_145 = F_110 ( sizeof( * V_145 ) + sizeof( struct V_28 ) +
sizeof( struct V_3 ) * 2 + V_23 + 1 ,
V_147 ) ;
if ( ! V_145 )
return NULL ;
V_26 = (struct V_28 * ) ( V_145 + 1 ) ;
V_40 = (struct V_3 * ) ( V_26 + 1 ) ;
V_146 = ( char * ) ( V_40 + 2 ) ;
memcpy ( V_146 , V_22 , V_23 ) ;
V_146 [ V_23 ] = '\0' ;
V_40 [ 0 ] . V_14 = V_146 ;
V_40 [ 0 ] . V_58 = V_85 | V_148 | V_149 ;
F_18 ( & V_145 -> V_8 , V_39 -> V_7 . V_8 . V_27 , V_39 , V_26 , V_40 ) ;
return V_145 ;
}
static struct V_6 * F_111 ( struct V_6 * V_7 ,
const char * V_22 , int V_23 )
{
struct V_38 * V_39 = V_7 -> V_8 . V_39 ;
struct V_6 * V_150 , * V_145 = NULL ;
int V_46 ;
F_33 ( & V_52 ) ;
V_150 = F_108 ( V_7 , V_22 , V_23 ) ;
if ( ! F_63 ( V_150 ) )
goto V_151;
if ( F_72 ( V_150 ) != - V_54 )
goto V_152;
F_31 ( & V_52 ) ;
V_145 = F_109 ( V_39 , V_22 , V_23 ) ;
F_33 ( & V_52 ) ;
V_150 = F_34 ( - V_99 ) ;
if ( ! V_145 )
goto V_152;
V_150 = F_108 ( V_7 , V_22 , V_23 ) ;
if ( ! F_63 ( V_150 ) )
goto V_151;
if ( F_72 ( V_150 ) != - V_54 )
goto V_152;
V_46 = F_20 ( V_7 , & V_145 -> V_8 ) ;
V_150 = F_34 ( V_46 ) ;
if ( V_46 )
goto V_152;
V_150 = V_145 ;
V_151:
V_150 -> V_8 . V_44 ++ ;
V_152:
if ( F_63 ( V_150 ) ) {
F_13 ( L_4 ) ;
F_7 ( V_7 ) ;
F_8 ( L_5 ,
V_23 , V_23 , V_22 , F_72 ( V_150 ) ) ;
}
F_24 ( & V_7 -> V_8 ) ;
if ( V_145 )
F_24 ( & V_145 -> V_8 ) ;
F_31 ( & V_52 ) ;
return V_150 ;
}
static struct V_6 * F_112 ( struct V_38 * V_39 , struct V_6 * V_7 )
{
struct V_6 * V_13 ;
const char * V_14 ;
if ( ! V_7 -> V_8 . V_13 )
return & V_39 -> V_7 ;
V_13 = F_112 ( V_39 , V_7 -> V_8 . V_13 ) ;
if ( F_63 ( V_13 ) )
return V_13 ;
V_14 = V_7 -> V_8 . V_3 [ 0 ] . V_14 ;
return F_108 ( V_13 , V_14 , strlen ( V_14 ) ) ;
}
static int F_67 ( struct V_1 * * V_21 ,
struct V_3 * * V_57 )
{
struct V_1 * V_2 ;
struct V_37 * V_27 ;
struct V_38 * V_39 ;
struct V_3 * V_24 ;
struct V_6 * V_7 ;
int V_97 ;
V_97 = 0 ;
F_33 ( & V_52 ) ;
V_27 = ( * V_57 ) -> V_153 ;
V_39 = F_41 ( V_27 ) ;
V_7 = F_112 ( V_39 , ( * V_21 ) -> V_13 ) ;
if ( F_63 ( V_7 ) )
V_97 = F_72 ( V_7 ) ;
else {
const char * V_14 = ( * V_57 ) -> V_14 ;
V_2 = NULL ;
V_24 = F_10 ( & V_2 , V_7 , V_14 , strlen ( V_14 ) ) ;
V_97 = - V_54 ;
if ( V_24 && F_25 ( V_2 ) ) {
F_27 ( * V_21 ) ;
* V_21 = V_2 ;
* V_57 = V_24 ;
V_97 = 0 ;
}
}
F_31 ( & V_52 ) ;
return V_97 ;
}
static int F_113 ( const char * V_154 , struct V_3 * V_40 , char * V_155 , ... )
{
struct V_156 V_157 ;
T_7 args ;
va_start ( args , V_155 ) ;
V_157 . V_155 = V_155 ;
V_157 . V_158 = & args ;
F_13 ( L_6 ,
V_154 , V_40 -> V_14 , & V_157 ) ;
va_end ( args ) ;
return - V_48 ;
}
static int F_114 ( const char * V_154 , struct V_3 * V_40 )
{
int V_46 = 0 ;
for (; V_40 -> V_14 ; V_40 ++ ) {
if ( V_40 -> V_4 )
V_46 = F_113 ( V_154 , V_40 , L_7 ) ;
if ( ( V_40 -> V_109 == V_159 ) ||
( V_40 -> V_109 == V_160 ) ||
( V_40 -> V_109 == V_161 ) ||
( V_40 -> V_109 == V_162 ) ||
( V_40 -> V_109 == V_163 ) ||
( V_40 -> V_109 == V_164 ) ||
( V_40 -> V_109 == V_165 ) ||
( V_40 -> V_109 == V_166 ) ) {
if ( ! V_40 -> V_153 )
V_46 = F_113 ( V_154 , V_40 , L_8 ) ;
if ( ! V_40 -> V_167 )
V_46 = F_113 ( V_154 , V_40 , L_9 ) ;
}
if ( ! V_40 -> V_109 )
V_46 = F_113 ( V_154 , V_40 , L_10 ) ;
if ( ( V_40 -> V_58 & ( V_148 | V_168 ) ) != V_40 -> V_58 )
V_46 = F_113 ( V_154 , V_40 , L_11 ,
V_40 -> V_58 ) ;
}
return V_46 ;
}
static struct V_1 * F_115 ( struct V_6 * V_7 , struct V_3 * V_40 ,
struct V_37 * V_169 )
{
struct V_3 * V_170 , * V_24 , * V_171 ;
struct V_1 * V_172 ;
struct V_28 * V_26 ;
char * V_173 ;
int V_174 , V_175 ;
V_175 = 0 ;
V_174 = 0 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
V_174 ++ ;
V_175 += strlen ( V_24 -> V_14 ) + 1 ;
}
V_172 = F_110 ( sizeof( struct V_1 ) +
sizeof( struct V_28 ) * V_174 +
sizeof( struct V_3 ) * ( V_174 + 1 ) +
V_175 ,
V_147 ) ;
if ( ! V_172 )
return NULL ;
V_26 = (struct V_28 * ) ( V_172 + 1 ) ;
V_170 = (struct V_3 * ) ( V_26 + V_174 ) ;
V_173 = ( char * ) & V_170 [ V_174 + 1 ] ;
for ( V_171 = V_170 , V_24 = V_40 ; V_24 -> V_14 ; V_171 ++ , V_24 ++ ) {
int V_98 = strlen ( V_24 -> V_14 ) + 1 ;
memcpy ( V_173 , V_24 -> V_14 , V_98 ) ;
V_171 -> V_14 = V_173 ;
V_171 -> V_58 = V_176 | V_177 ;
V_171 -> V_153 = V_169 ;
V_173 += V_98 ;
}
F_18 ( V_172 , V_7 -> V_8 . V_27 , V_7 -> V_8 . V_39 , V_26 , V_170 ) ;
V_172 -> V_44 = V_174 ;
return V_172 ;
}
static bool F_116 ( struct V_6 * V_7 ,
struct V_3 * V_40 , struct V_37 * V_169 )
{
struct V_1 * V_2 ;
struct V_3 * V_24 , * V_171 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
const char * V_14 = V_24 -> V_14 ;
V_171 = F_10 ( & V_2 , V_7 , V_14 , strlen ( V_14 ) ) ;
if ( ! V_171 )
return false ;
if ( F_59 ( V_171 -> V_58 ) && F_59 ( V_24 -> V_58 ) )
continue;
if ( F_66 ( V_171 -> V_58 ) && ( V_171 -> V_153 == V_169 ) )
continue;
return false ;
}
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
const char * V_14 = V_24 -> V_14 ;
V_171 = F_10 ( & V_2 , V_7 , V_14 , strlen ( V_14 ) ) ;
V_2 -> V_44 ++ ;
}
return true ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_38 * V_178 = & V_91 . V_55 ;
struct V_6 * V_179 = NULL ;
struct V_1 * V_172 ;
int V_46 ;
if ( V_2 -> V_39 == V_178 )
return 0 ;
V_179 = F_112 ( V_178 , V_2 -> V_13 ) ;
if ( F_63 ( V_179 ) )
return 0 ;
if ( F_116 ( V_179 , V_2 -> V_3 , V_2 -> V_27 ) )
return 0 ;
V_179 -> V_8 . V_44 ++ ;
F_31 ( & V_52 ) ;
V_172 = F_115 ( V_179 , V_2 -> V_3 , V_2 -> V_27 ) ;
F_33 ( & V_52 ) ;
V_46 = - V_99 ;
if ( ! V_172 )
goto V_72;
V_46 = 0 ;
if ( F_116 ( V_179 , V_2 -> V_3 , V_2 -> V_27 ) ) {
F_117 ( V_172 ) ;
goto V_72;
}
V_46 = F_20 ( V_179 , V_172 ) ;
if ( V_46 )
F_117 ( V_172 ) ;
V_72:
F_24 ( & V_179 -> V_8 ) ;
return V_46 ;
}
struct V_1 * F_118 (
struct V_38 * V_39 ,
const char * V_154 , struct V_3 * V_40 )
{
struct V_37 * V_27 = V_39 -> V_7 . V_8 . V_27 ;
struct V_1 * V_8 ;
const char * V_22 , * V_180 ;
struct V_6 * V_7 ;
struct V_3 * V_24 ;
struct V_28 * V_26 ;
int V_174 = 0 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ )
V_174 ++ ;
V_8 = F_110 ( sizeof( struct V_1 ) +
sizeof( struct V_28 ) * V_174 , V_147 ) ;
if ( ! V_8 )
return NULL ;
V_26 = (struct V_28 * ) ( V_8 + 1 ) ;
F_18 ( V_8 , V_27 , V_39 , V_26 , V_40 ) ;
if ( F_114 ( V_154 , V_40 ) )
goto V_50;
F_33 ( & V_52 ) ;
V_7 = & V_39 -> V_7 ;
V_7 -> V_8 . V_44 ++ ;
F_31 ( & V_52 ) ;
for ( V_22 = V_154 ; V_22 ; V_22 = V_180 ) {
int V_23 ;
V_180 = strchr ( V_22 , '/' ) ;
if ( V_180 ) {
V_23 = V_180 - V_22 ;
V_180 ++ ;
} else {
V_23 = strlen ( V_22 ) ;
}
if ( V_23 == 0 )
continue;
V_7 = F_111 ( V_7 , V_22 , V_23 ) ;
if ( F_63 ( V_7 ) )
goto V_50;
}
F_33 ( & V_52 ) ;
if ( F_20 ( V_7 , V_8 ) )
goto V_181;
F_24 ( & V_7 -> V_8 ) ;
F_31 ( & V_52 ) ;
return V_8 ;
V_181:
F_24 ( & V_7 -> V_8 ) ;
F_31 ( & V_52 ) ;
V_50:
F_117 ( V_8 ) ;
F_119 () ;
return NULL ;
}
struct V_1 * F_120 ( const char * V_154 , struct V_3 * V_40 )
{
return F_118 ( & V_91 . V_55 ,
V_154 , V_40 ) ;
}
static char * F_121 ( const char * V_154 , char * V_126 , const char * V_22 )
{
int V_23 ;
V_23 = strlen ( V_22 ) ;
if ( ( ( V_126 - V_154 ) + V_23 + 2 ) >= V_182 )
return NULL ;
memcpy ( V_126 , V_22 , V_23 ) ;
V_126 [ V_23 ] = '/' ;
V_126 [ V_23 + 1 ] = '\0' ;
V_126 += V_23 + 1 ;
return V_126 ;
}
static int F_122 ( struct V_3 * V_40 )
{
int V_183 = 0 ;
int V_184 = 0 ;
struct V_3 * V_24 ;
if ( ! V_40 || ! V_40 -> V_14 )
return 1 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
if ( V_24 -> V_4 )
V_184 += F_122 ( V_24 -> V_4 ) ;
else
V_183 = 1 ;
}
return V_184 + V_183 ;
}
static int F_123 ( const char * V_154 , char * V_126 ,
struct V_1 * * * V_185 , struct V_38 * V_39 ,
struct V_3 * V_40 )
{
struct V_3 * V_41 = NULL ;
struct V_3 * V_24 , * V_186 ;
int V_187 = 0 ;
int V_188 = 0 ;
int V_46 = - V_99 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
if ( V_24 -> V_4 )
V_188 ++ ;
else
V_187 ++ ;
}
V_186 = V_40 ;
if ( V_188 && V_187 ) {
struct V_3 * V_145 ;
V_186 = F_110 ( sizeof( struct V_3 ) * ( V_187 + 1 ) ,
V_147 ) ;
if ( ! V_186 )
goto V_72;
V_41 = V_186 ;
for ( V_145 = V_186 , V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
if ( V_24 -> V_4 )
continue;
* V_145 = * V_24 ;
V_145 ++ ;
}
}
if ( V_187 || ! V_188 ) {
struct V_1 * V_8 ;
V_8 = F_118 ( V_39 , V_154 , V_186 ) ;
if ( ! V_8 ) {
F_117 ( V_41 ) ;
goto V_72;
}
V_8 -> V_41 = V_41 ;
* * V_185 = V_8 ;
( * V_185 ) ++ ;
}
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
char * V_189 ;
if ( ! V_24 -> V_4 )
continue;
V_46 = - V_190 ;
V_189 = F_121 ( V_154 , V_126 , V_24 -> V_14 ) ;
if ( ! V_189 )
goto V_72;
V_46 = F_123 ( V_154 , V_189 , V_185 ,
V_39 , V_24 -> V_4 ) ;
V_126 [ 0 ] = '\0' ;
if ( V_46 )
goto V_72;
}
V_46 = 0 ;
V_72:
return V_46 ;
}
struct V_1 * F_124 (
struct V_38 * V_39 ,
const struct V_191 * V_154 , struct V_3 * V_40 )
{
struct V_3 * V_41 = V_40 ;
int V_184 = F_122 ( V_40 ) ;
struct V_1 * V_8 = NULL , * * V_192 , * * V_185 ;
const struct V_191 * V_193 ;
char * V_194 , * V_126 ;
V_126 = V_194 = F_125 ( V_182 , V_147 ) ;
if ( ! V_194 )
return NULL ;
V_126 [ 0 ] = '\0' ;
for ( V_193 = V_154 ; V_193 -> V_14 ; V_193 ++ ) {
V_126 = F_121 ( V_194 , V_126 , V_193 -> V_14 ) ;
if ( ! V_126 )
goto V_72;
}
while ( V_40 -> V_14 && V_40 -> V_4 && ! V_40 [ 1 ] . V_14 ) {
V_126 = F_121 ( V_194 , V_126 , V_40 -> V_14 ) ;
if ( ! V_126 )
goto V_72;
V_40 = V_40 -> V_4 ;
}
if ( V_184 == 1 ) {
V_8 = F_118 ( V_39 , V_194 , V_40 ) ;
if ( V_8 )
V_8 -> V_41 = V_41 ;
} else {
V_8 = F_110 ( sizeof( * V_8 ) +
sizeof( * V_192 ) * V_184 , V_147 ) ;
if ( ! V_8 )
goto V_72;
V_192 = (struct V_1 * * ) ( V_8 + 1 ) ;
V_185 = V_192 ;
V_8 -> V_41 = V_41 ;
if ( F_123 ( V_194 , V_126 , & V_185 ,
V_39 , V_40 ) )
goto V_195;
}
V_72:
F_117 ( V_194 ) ;
return V_8 ;
V_195:
while ( V_185 > V_192 ) {
struct V_1 * V_196 = * ( -- V_185 ) ;
struct V_3 * V_40 = V_196 -> V_41 ;
F_126 ( V_196 ) ;
F_117 ( V_40 ) ;
}
F_117 ( V_8 ) ;
V_8 = NULL ;
goto V_72;
}
struct V_1 * F_127 ( const struct V_191 * V_154 ,
struct V_3 * V_40 )
{
return F_124 ( & V_91 . V_55 ,
V_154 , V_40 ) ;
}
struct V_1 * F_128 ( struct V_3 * V_40 )
{
static const struct V_191 V_197 [] = { {} } ;
return F_127 ( V_197 , V_40 ) ;
}
static void F_23 ( struct V_1 * V_8 )
{
struct V_38 * V_178 = & V_91 . V_55 ;
struct V_37 * V_27 = V_8 -> V_27 ;
struct V_6 * V_13 = V_8 -> V_13 ;
struct V_6 * V_179 ;
struct V_3 * V_24 ;
if ( V_8 -> V_39 == V_178 )
return;
V_179 = F_112 ( V_178 , V_13 ) ;
if ( F_63 ( V_179 ) )
return;
for ( V_24 = V_8 -> V_3 ; V_24 -> V_14 ; V_24 ++ ) {
struct V_1 * V_198 ;
struct V_3 * V_171 ;
const char * V_22 = V_24 -> V_14 ;
V_171 = F_10 ( & V_198 , V_179 , V_22 , strlen ( V_22 ) ) ;
if ( V_171 &&
( ( F_59 ( V_171 -> V_58 ) && F_59 ( V_24 -> V_58 ) ) ||
( F_66 ( V_171 -> V_58 ) && ( V_171 -> V_153 == V_27 ) ) ) ) {
F_24 ( V_198 ) ;
}
else {
F_13 ( L_12 ) ;
F_7 ( V_13 ) ;
F_8 ( L_3 , V_22 ) ;
}
}
}
static void F_24 ( struct V_1 * V_8 )
{
struct V_6 * V_13 = V_8 -> V_13 ;
if ( -- V_8 -> V_44 )
return;
F_23 ( V_8 ) ;
F_29 ( V_8 ) ;
if ( ! -- V_8 -> V_43 )
F_37 ( V_8 , V_53 ) ;
if ( V_13 )
F_24 ( & V_13 -> V_8 ) ;
}
void F_126 ( struct V_1 * V_8 )
{
int V_184 ;
F_129 () ;
if ( V_8 == NULL )
return;
V_184 = F_122 ( V_8 -> V_41 ) ;
if ( F_26 ( V_184 > 1 ) ) {
struct V_1 * * V_192 ;
int V_199 ;
V_192 = (struct V_1 * * ) ( V_8 + 1 ) ;
for ( V_199 = V_184 - 1 ; V_199 >= 0 ; V_199 -- ) {
struct V_1 * V_196 = V_192 [ V_199 ] ;
struct V_3 * V_40 = V_196 -> V_41 ;
F_126 ( V_196 ) ;
F_117 ( V_40 ) ;
}
F_117 ( V_8 ) ;
return;
}
F_33 ( & V_52 ) ;
F_24 ( V_8 ) ;
F_31 ( & V_52 ) ;
}
void F_130 ( struct V_38 * V_39 ,
struct V_37 * V_27 ,
int (* V_142)( struct V_38 * ) )
{
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_142 = V_142 ;
F_18 ( & V_39 -> V_7 . V_8 , V_27 , V_39 , NULL , V_200 ) ;
}
void F_131 ( struct V_38 * V_39 )
{
F_132 ( ! F_21 ( & V_39 -> V_7 . V_27 ) ) ;
}
int T_8 F_133 ( void )
{
struct V_201 * V_202 ;
V_202 = F_134 ( L_13 , NULL ) ;
V_202 -> V_203 = & V_86 ;
V_202 -> V_204 = & V_87 ;
V_202 -> V_205 = 0 ;
return F_135 () ;
}
