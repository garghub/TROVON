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
F_19 ( & V_2 -> V_46 ) ;
if ( V_26 ) {
struct V_3 * V_24 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ , V_26 ++ )
V_26 -> V_8 = V_2 ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_24 ;
for ( V_24 = V_2 -> V_3 ; V_24 -> V_14 ; V_24 ++ )
F_16 ( V_2 , V_24 ) ;
}
static int F_21 ( struct V_6 * V_7 , struct V_1 * V_8 )
{
struct V_3 * V_24 ;
int V_47 ;
if ( F_1 ( & V_7 -> V_8 ) )
return - V_48 ;
if ( V_8 -> V_3 == V_5 ) {
if ( ! F_22 ( & V_7 -> V_27 ) )
return - V_49 ;
F_2 ( V_7 ) ;
}
V_7 -> V_8 . V_44 ++ ;
V_8 -> V_13 = V_7 ;
V_47 = F_23 ( V_8 ) ;
if ( V_47 )
goto V_50;
for ( V_24 = V_8 -> V_3 ; V_24 -> V_14 ; V_24 ++ ) {
V_47 = F_12 ( V_8 , V_24 ) ;
if ( V_47 )
goto V_51;
}
return 0 ;
V_51:
F_20 ( V_8 ) ;
F_24 ( V_8 ) ;
V_50:
if ( V_8 -> V_3 == V_5 )
F_3 ( V_7 ) ;
V_8 -> V_13 = NULL ;
F_25 ( & V_7 -> V_8 ) ;
return V_47 ;
}
static int F_26 ( struct V_1 * V_31 )
{
if ( F_27 ( V_31 -> V_45 ) )
return 0 ;
V_31 -> V_42 ++ ;
return 1 ;
}
static void F_28 ( struct V_1 * V_31 )
{
if ( ! -- V_31 -> V_42 )
if ( F_27 ( V_31 -> V_45 ) )
F_29 ( V_31 -> V_45 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_52 * V_52 , * V_53 = NULL ;
struct V_54 * V_55 ;
F_31 () ;
F_32 (ei, &head->inodes, sysctl_inodes) {
V_52 = F_33 ( & V_55 -> V_56 ) ;
if ( V_52 ) {
F_34 () ;
F_35 ( V_53 ) ;
V_53 = V_52 ;
F_36 ( V_52 ) ;
F_31 () ;
}
}
F_34 () ;
F_35 ( V_53 ) ;
}
static void F_37 ( struct V_1 * V_31 )
{
if ( F_27 ( V_31 -> V_42 ) ) {
struct V_57 V_12 ;
F_38 ( & V_12 ) ;
V_31 -> V_45 = & V_12 ;
F_39 ( & V_58 ) ;
F_40 ( & V_12 ) ;
} else {
V_31 -> V_45 = F_41 ( - V_49 ) ;
F_39 ( & V_58 ) ;
}
F_30 ( V_31 ) ;
F_42 ( & V_58 ) ;
F_20 ( V_31 ) ;
}
static struct V_1 * F_43 ( struct V_1 * V_2 )
{
F_44 ( ! V_2 ) ;
F_42 ( & V_58 ) ;
if ( ! F_26 ( V_2 ) )
V_2 = F_41 ( - V_59 ) ;
F_39 ( & V_58 ) ;
return V_2 ;
}
static void F_45 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_42 ( & V_58 ) ;
F_28 ( V_2 ) ;
F_39 ( & V_58 ) ;
}
static struct V_38 *
F_46 ( struct V_37 * V_27 )
{
struct V_38 * V_39 = & V_27 -> V_60 ;
if ( V_27 -> V_61 )
V_39 = V_27 -> V_61 ( V_27 ) ;
return V_39 ;
}
static struct V_3 * F_47 ( struct V_1 * * V_21 ,
struct V_6 * V_7 ,
const char * V_22 , int V_23 )
{
struct V_1 * V_2 ;
struct V_3 * V_24 ;
F_42 ( & V_58 ) ;
V_24 = F_10 ( & V_2 , V_7 , V_22 , V_23 ) ;
if ( V_24 && F_26 ( V_2 ) )
* V_21 = V_2 ;
else
V_24 = NULL ;
F_39 ( & V_58 ) ;
return V_24 ;
}
static struct V_28 * F_48 ( struct V_25 * V_26 )
{
struct V_28 * V_28 ;
for (; V_26 ; V_26 = F_49 ( V_26 ) ) {
V_28 = F_11 ( V_26 , struct V_28 , V_26 ) ;
if ( F_26 ( V_28 -> V_8 ) )
return V_28 ;
}
return NULL ;
}
static void F_50 ( struct V_6 * V_7 ,
struct V_1 * * V_21 , struct V_3 * * V_62 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_24 = NULL ;
struct V_28 * V_28 ;
F_42 ( & V_58 ) ;
V_28 = F_48 ( F_51 ( & V_7 -> V_27 ) ) ;
F_39 ( & V_58 ) ;
if ( V_28 ) {
V_2 = V_28 -> V_8 ;
V_24 = & V_2 -> V_3 [ V_28 - V_2 -> V_26 ] ;
}
* V_21 = V_2 ;
* V_62 = V_24 ;
}
static void F_52 ( struct V_1 * * V_21 , struct V_3 * * V_62 )
{
struct V_1 * V_2 = * V_21 ;
struct V_3 * V_24 = * V_62 ;
struct V_28 * V_28 = & V_2 -> V_26 [ V_24 - V_2 -> V_3 ] ;
F_42 ( & V_58 ) ;
F_28 ( V_2 ) ;
V_28 = F_48 ( F_49 ( & V_28 -> V_26 ) ) ;
F_39 ( & V_58 ) ;
V_2 = NULL ;
if ( V_28 ) {
V_2 = V_28 -> V_8 ;
V_24 = & V_2 -> V_3 [ V_28 - V_2 -> V_26 ] ;
}
* V_21 = V_2 ;
* V_62 = V_24 ;
}
static int F_53 ( int V_63 , int V_64 )
{
if ( F_54 ( F_55 () , V_65 ) )
V_63 >>= 6 ;
else if ( F_56 ( V_66 ) )
V_63 >>= 3 ;
if ( ( V_64 & ~ V_63 & ( V_67 | V_68 | V_69 ) ) == 0 )
return 0 ;
return - V_70 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_3 * V_40 , int V_64 )
{
struct V_37 * V_27 = V_2 -> V_27 ;
int V_63 ;
if ( V_27 -> V_71 )
V_63 = V_27 -> V_71 ( V_2 , V_40 ) ;
else
V_63 = V_40 -> V_63 ;
return F_53 ( V_63 , V_64 ) ;
}
static struct V_52 * F_58 ( struct V_72 * V_73 ,
struct V_1 * V_2 , struct V_3 * V_40 )
{
struct V_37 * V_27 = V_2 -> V_27 ;
struct V_52 * V_52 ;
struct V_54 * V_55 ;
V_52 = F_59 ( V_73 ) ;
if ( ! V_52 )
goto V_74;
V_52 -> V_75 = F_60 () ;
V_55 = F_61 ( V_52 ) ;
F_42 ( & V_58 ) ;
if ( F_27 ( V_2 -> V_45 ) ) {
F_39 ( & V_58 ) ;
F_35 ( V_52 ) ;
V_52 = NULL ;
goto V_74;
}
V_55 -> V_76 = V_2 ;
V_55 -> V_77 = V_40 ;
F_62 ( & V_55 -> V_78 , & V_2 -> V_46 ) ;
V_2 -> V_43 ++ ;
F_39 ( & V_58 ) ;
V_52 -> V_79 = V_52 -> V_80 = V_52 -> V_81 = F_63 ( V_52 ) ;
V_52 -> V_82 = V_40 -> V_63 ;
if ( ! F_64 ( V_40 -> V_63 ) ) {
V_52 -> V_82 |= V_83 ;
V_52 -> V_84 = & V_85 ;
V_52 -> V_86 = & V_87 ;
} else {
V_52 -> V_82 |= V_88 ;
V_52 -> V_84 = & V_89 ;
V_52 -> V_86 = & V_90 ;
if ( F_1 ( V_2 ) )
F_65 ( V_52 ) ;
}
if ( V_27 -> V_91 )
V_27 -> V_91 ( V_2 , V_40 , & V_52 -> V_92 , & V_52 -> V_93 ) ;
V_74:
return V_52 ;
}
void F_66 ( struct V_52 * V_52 , struct V_1 * V_2 )
{
F_42 ( & V_58 ) ;
F_67 ( & F_61 ( V_52 ) -> V_78 ) ;
if ( ! -- V_2 -> V_43 )
F_68 ( V_2 , V_94 ) ;
F_39 ( & V_58 ) ;
}
static struct V_1 * F_69 ( struct V_52 * V_52 )
{
struct V_1 * V_2 = F_61 ( V_52 ) -> V_76 ;
if ( ! V_2 )
V_2 = & V_95 . V_60 . V_7 . V_8 ;
return F_43 ( V_2 ) ;
}
static struct V_96 * F_70 ( struct V_52 * V_7 , struct V_96 * V_96 ,
unsigned int V_97 )
{
struct V_1 * V_2 = F_69 ( V_7 ) ;
struct V_1 * V_98 = NULL ;
const struct V_99 * V_22 = & V_96 -> V_100 ;
struct V_3 * V_31 ;
struct V_52 * V_52 ;
struct V_96 * V_47 = F_41 ( - V_59 ) ;
struct V_6 * V_6 ;
int V_101 ;
if ( F_71 ( V_2 ) )
return F_72 ( V_2 ) ;
V_6 = F_73 ( V_2 , struct V_6 , V_8 ) ;
V_31 = F_47 ( & V_98 , V_6 , V_22 -> V_22 , V_22 -> V_102 ) ;
if ( ! V_31 )
goto V_74;
if ( F_74 ( V_31 -> V_63 ) ) {
V_101 = F_75 ( & V_98 , & V_31 ) ;
V_47 = F_41 ( V_101 ) ;
if ( V_101 )
goto V_74;
}
V_47 = F_41 ( - V_103 ) ;
V_52 = F_58 ( V_7 -> V_104 , V_98 ? V_98 : V_2 , V_31 ) ;
if ( ! V_52 )
goto V_74;
V_47 = NULL ;
F_76 ( V_96 , & V_105 ) ;
F_77 ( V_96 , V_52 ) ;
V_74:
if ( V_98 )
F_45 ( V_98 ) ;
F_45 ( V_2 ) ;
return V_47 ;
}
static T_1 F_78 ( struct V_106 * V_107 , void T_2 * V_108 ,
T_3 V_43 , T_4 * V_109 , int V_110 )
{
struct V_52 * V_52 = F_79 ( V_107 ) ;
struct V_1 * V_2 = F_69 ( V_52 ) ;
struct V_3 * V_40 = F_61 ( V_52 ) -> V_77 ;
T_1 error ;
T_3 V_111 ;
if ( F_71 ( V_2 ) )
return F_80 ( V_2 ) ;
error = - V_112 ;
if ( F_57 ( V_2 , V_40 , V_110 ? V_68 : V_67 ) )
goto V_74;
error = - V_49 ;
if ( ! V_40 -> V_113 )
goto V_74;
V_111 = V_43 ;
error = V_40 -> V_113 ( V_40 , V_110 , V_108 , & V_111 , V_109 ) ;
if ( ! error )
error = V_111 ;
V_74:
F_45 ( V_2 ) ;
return error ;
}
static T_1 F_81 ( struct V_106 * V_107 , char T_2 * V_108 ,
T_3 V_43 , T_4 * V_109 )
{
return F_78 ( V_107 , ( void T_2 * ) V_108 , V_43 , V_109 , 0 ) ;
}
static T_1 F_82 ( struct V_106 * V_107 , const char T_2 * V_108 ,
T_3 V_43 , T_4 * V_109 )
{
return F_78 ( V_107 , ( void T_2 * ) V_108 , V_43 , V_109 , 1 ) ;
}
static int F_83 ( struct V_52 * V_52 , struct V_106 * V_107 )
{
struct V_1 * V_2 = F_69 ( V_52 ) ;
struct V_3 * V_40 = F_61 ( V_52 ) -> V_77 ;
if ( F_71 ( V_2 ) )
return F_80 ( V_2 ) ;
if ( V_40 -> V_10 )
V_107 -> V_114 = F_84 ( V_40 -> V_10 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
static unsigned int F_85 ( struct V_106 * V_107 , T_5 * V_12 )
{
struct V_52 * V_52 = F_79 ( V_107 ) ;
struct V_1 * V_2 = F_69 ( V_52 ) ;
struct V_3 * V_40 = F_61 ( V_52 ) -> V_77 ;
unsigned int V_101 = V_115 ;
unsigned long V_11 ;
if ( F_71 ( V_2 ) )
return V_116 | V_117 ;
if ( ! V_40 -> V_113 )
goto V_74;
if ( ! V_40 -> V_10 )
goto V_74;
V_11 = ( unsigned long ) V_107 -> V_114 ;
F_86 ( V_107 , & V_40 -> V_10 -> V_12 , V_12 ) ;
if ( V_11 != F_87 ( & V_40 -> V_10 -> V_11 ) ) {
V_107 -> V_114 = F_84 ( V_40 -> V_10 ) ;
V_101 = V_118 | V_119 | V_116 | V_120 ;
}
V_74:
F_45 ( V_2 ) ;
return V_101 ;
}
static bool F_88 ( struct V_106 * V_106 ,
struct V_121 * V_122 ,
struct V_1 * V_2 ,
struct V_3 * V_40 )
{
struct V_96 * V_4 , * V_7 = V_106 -> V_123 . V_96 ;
struct V_52 * V_52 ;
struct V_99 V_124 ;
T_6 V_125 = 0 ;
unsigned type = V_126 ;
V_124 . V_22 = V_40 -> V_14 ;
V_124 . V_102 = strlen ( V_40 -> V_14 ) ;
V_124 . V_127 = F_89 ( V_7 , V_124 . V_22 , V_124 . V_102 ) ;
V_4 = F_90 ( V_7 , & V_124 ) ;
if ( ! V_4 ) {
F_91 ( V_128 ) ;
V_4 = F_92 ( V_7 , & V_124 , & V_128 ) ;
if ( F_71 ( V_4 ) )
return false ;
if ( F_93 ( V_4 ) ) {
V_52 = F_58 ( V_7 -> V_129 , V_2 , V_40 ) ;
if ( ! V_52 ) {
F_94 ( V_4 ) ;
F_95 ( V_4 ) ;
return false ;
}
F_76 ( V_4 , & V_105 ) ;
F_77 ( V_4 , V_52 ) ;
}
}
V_52 = F_96 ( V_4 ) ;
V_125 = V_52 -> V_75 ;
type = V_52 -> V_82 >> 12 ;
F_95 ( V_4 ) ;
return F_97 ( V_122 , V_124 . V_22 , V_124 . V_102 , V_125 , type ) ;
}
static bool F_98 ( struct V_106 * V_106 ,
struct V_121 * V_122 ,
struct V_1 * V_2 ,
struct V_3 * V_40 )
{
bool V_101 = true ;
V_2 = F_43 ( V_2 ) ;
if ( F_74 ( V_40 -> V_63 ) ) {
int V_47 = F_75 ( & V_2 , & V_40 ) ;
if ( V_47 )
goto V_74;
}
V_101 = F_88 ( V_106 , V_122 , V_2 , V_40 ) ;
V_74:
F_45 ( V_2 ) ;
return V_101 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_3 * V_40 ,
unsigned long * V_130 , struct V_106 * V_106 ,
struct V_121 * V_122 )
{
bool V_111 ;
if ( ( * V_130 ) ++ < V_122 -> V_130 )
return true ;
if ( F_27 ( F_74 ( V_40 -> V_63 ) ) )
V_111 = F_98 ( V_106 , V_122 , V_2 , V_40 ) ;
else
V_111 = F_88 ( V_106 , V_122 , V_2 , V_40 ) ;
if ( V_111 )
V_122 -> V_130 = * V_130 ;
return V_111 ;
}
static int F_100 ( struct V_106 * V_106 , struct V_121 * V_122 )
{
struct V_1 * V_2 = F_69 ( F_79 ( V_106 ) ) ;
struct V_1 * V_98 = NULL ;
struct V_3 * V_24 ;
struct V_6 * V_6 ;
unsigned long V_130 ;
if ( F_71 ( V_2 ) )
return F_80 ( V_2 ) ;
V_6 = F_73 ( V_2 , struct V_6 , V_8 ) ;
if ( ! F_101 ( V_106 , V_122 ) )
goto V_74;
V_130 = 2 ;
for ( F_50 ( V_6 , & V_98 , & V_24 ) ; V_98 ; F_52 ( & V_98 , & V_24 ) ) {
if ( ! F_99 ( V_98 , V_24 , & V_130 , V_106 , V_122 ) ) {
F_45 ( V_98 ) ;
break;
}
}
V_74:
F_45 ( V_2 ) ;
return 0 ;
}
static int F_102 ( struct V_52 * V_52 , int V_131 )
{
struct V_1 * V_2 ;
struct V_3 * V_40 ;
int error ;
if ( ( V_131 & V_69 ) && F_103 ( V_52 -> V_82 ) )
return - V_70 ;
V_2 = F_69 ( V_52 ) ;
if ( F_71 ( V_2 ) )
return F_80 ( V_2 ) ;
V_40 = F_61 ( V_52 ) -> V_77 ;
if ( ! V_40 )
error = V_131 & V_68 ? - V_70 : 0 ;
else
error = F_57 ( V_2 , V_40 , V_131 & ~ V_132 ) ;
F_45 ( V_2 ) ;
return error ;
}
static int F_104 ( struct V_96 * V_96 , struct V_133 * V_134 )
{
struct V_52 * V_52 = F_96 ( V_96 ) ;
int error ;
if ( V_134 -> V_135 & ( V_136 | V_137 | V_138 ) )
return - V_112 ;
error = F_105 ( V_96 , V_134 ) ;
if ( error )
return error ;
F_106 ( V_52 , V_134 ) ;
F_107 ( V_52 ) ;
return 0 ;
}
static int F_108 ( const struct V_139 * V_139 , struct V_140 * V_141 ,
T_7 V_142 , unsigned int V_143 )
{
struct V_52 * V_52 = F_96 ( V_139 -> V_96 ) ;
struct V_1 * V_2 = F_69 ( V_52 ) ;
struct V_3 * V_40 = F_61 ( V_52 ) -> V_77 ;
if ( F_71 ( V_2 ) )
return F_80 ( V_2 ) ;
F_109 ( V_52 , V_141 ) ;
if ( V_40 )
V_141 -> V_63 = ( V_141 -> V_63 & V_144 ) | V_40 -> V_63 ;
F_45 ( V_2 ) ;
return 0 ;
}
static int F_110 ( struct V_96 * V_96 , unsigned int V_97 )
{
if ( V_97 & V_145 )
return - V_146 ;
return ! F_61 ( F_96 ( V_96 ) ) -> V_76 -> V_45 ;
}
static int F_111 ( const struct V_96 * V_96 )
{
return ! ! F_61 ( F_96 ( V_96 ) ) -> V_76 -> V_45 ;
}
static int F_112 ( struct V_1 * V_31 )
{
struct V_38 * V_39 = V_31 -> V_39 ;
int V_111 ;
F_42 ( & V_58 ) ;
if ( V_31 -> V_45 )
V_111 = 0 ;
else if ( ! V_39 -> V_147 )
V_111 = 1 ;
else
V_111 = V_39 -> V_147 ( V_39 ) ;
F_39 ( & V_58 ) ;
return V_111 ;
}
static int F_113 ( const struct V_96 * V_96 ,
unsigned int V_102 , const char * V_148 , const struct V_99 * V_22 )
{
struct V_1 * V_2 ;
struct V_52 * V_52 ;
V_52 = F_114 ( V_96 ) ;
if ( ! V_52 )
return 1 ;
if ( V_22 -> V_102 != V_102 )
return 1 ;
if ( memcmp ( V_22 -> V_22 , V_148 , V_102 ) )
return 1 ;
V_2 = F_115 ( F_61 ( V_52 ) -> V_76 ) ;
return ! V_2 || ! F_112 ( V_2 ) ;
}
static struct V_6 * F_116 ( struct V_6 * V_7 ,
const char * V_22 , int V_23 )
{
struct V_1 * V_2 ;
struct V_3 * V_24 ;
V_24 = F_10 ( & V_2 , V_7 , V_22 , V_23 ) ;
if ( ! V_24 )
return F_41 ( - V_59 ) ;
if ( ! F_64 ( V_24 -> V_63 ) )
return F_41 ( - V_149 ) ;
return F_73 ( V_2 , struct V_6 , V_8 ) ;
}
static struct V_6 * F_117 ( struct V_38 * V_39 ,
const char * V_22 , int V_23 )
{
struct V_3 * V_40 ;
struct V_6 * V_150 ;
struct V_28 * V_26 ;
char * V_151 ;
V_150 = F_118 ( sizeof( * V_150 ) + sizeof( struct V_28 ) +
sizeof( struct V_3 ) * 2 + V_23 + 1 ,
V_152 ) ;
if ( ! V_150 )
return NULL ;
V_26 = (struct V_28 * ) ( V_150 + 1 ) ;
V_40 = (struct V_3 * ) ( V_26 + 1 ) ;
V_151 = ( char * ) ( V_40 + 2 ) ;
memcpy ( V_151 , V_22 , V_23 ) ;
V_151 [ V_23 ] = '\0' ;
V_40 [ 0 ] . V_14 = V_151 ;
V_40 [ 0 ] . V_63 = V_88 | V_153 | V_154 ;
F_18 ( & V_150 -> V_8 , V_39 -> V_7 . V_8 . V_27 , V_39 , V_26 , V_40 ) ;
return V_150 ;
}
static struct V_6 * F_119 ( struct V_6 * V_7 ,
const char * V_22 , int V_23 )
{
struct V_38 * V_39 = V_7 -> V_8 . V_39 ;
struct V_6 * V_155 , * V_150 = NULL ;
int V_47 ;
F_42 ( & V_58 ) ;
V_155 = F_116 ( V_7 , V_22 , V_23 ) ;
if ( ! F_71 ( V_155 ) )
goto V_156;
if ( F_80 ( V_155 ) != - V_59 )
goto V_157;
F_39 ( & V_58 ) ;
V_150 = F_117 ( V_39 , V_22 , V_23 ) ;
F_42 ( & V_58 ) ;
V_155 = F_41 ( - V_103 ) ;
if ( ! V_150 )
goto V_157;
V_155 = F_116 ( V_7 , V_22 , V_23 ) ;
if ( ! F_71 ( V_155 ) )
goto V_156;
if ( F_80 ( V_155 ) != - V_59 )
goto V_157;
V_47 = F_21 ( V_7 , & V_150 -> V_8 ) ;
V_155 = F_41 ( V_47 ) ;
if ( V_47 )
goto V_157;
V_155 = V_150 ;
V_156:
V_155 -> V_8 . V_44 ++ ;
V_157:
if ( F_71 ( V_155 ) ) {
F_13 ( L_4 ) ;
F_7 ( V_7 ) ;
F_8 ( L_5 ,
V_23 , V_23 , V_22 , F_80 ( V_155 ) ) ;
}
F_25 ( & V_7 -> V_8 ) ;
if ( V_150 )
F_25 ( & V_150 -> V_8 ) ;
F_39 ( & V_58 ) ;
return V_155 ;
}
static struct V_6 * F_120 ( struct V_38 * V_39 , struct V_6 * V_7 )
{
struct V_6 * V_13 ;
const char * V_14 ;
if ( ! V_7 -> V_8 . V_13 )
return & V_39 -> V_7 ;
V_13 = F_120 ( V_39 , V_7 -> V_8 . V_13 ) ;
if ( F_71 ( V_13 ) )
return V_13 ;
V_14 = V_7 -> V_8 . V_3 [ 0 ] . V_14 ;
return F_116 ( V_13 , V_14 , strlen ( V_14 ) ) ;
}
static int F_75 ( struct V_1 * * V_21 ,
struct V_3 * * V_62 )
{
struct V_1 * V_2 ;
struct V_37 * V_27 ;
struct V_38 * V_39 ;
struct V_3 * V_24 ;
struct V_6 * V_7 ;
int V_101 ;
V_101 = 0 ;
F_42 ( & V_58 ) ;
V_27 = ( * V_62 ) -> V_158 ;
V_39 = F_46 ( V_27 ) ;
V_7 = F_120 ( V_39 , ( * V_21 ) -> V_13 ) ;
if ( F_71 ( V_7 ) )
V_101 = F_80 ( V_7 ) ;
else {
const char * V_14 = ( * V_62 ) -> V_14 ;
V_2 = NULL ;
V_24 = F_10 ( & V_2 , V_7 , V_14 , strlen ( V_14 ) ) ;
V_101 = - V_59 ;
if ( V_24 && F_26 ( V_2 ) ) {
F_28 ( * V_21 ) ;
* V_21 = V_2 ;
* V_62 = V_24 ;
V_101 = 0 ;
}
}
F_39 ( & V_58 ) ;
return V_101 ;
}
static int F_121 ( const char * V_139 , struct V_3 * V_40 , char * V_159 , ... )
{
struct V_160 V_161 ;
T_8 args ;
va_start ( args , V_159 ) ;
V_161 . V_159 = V_159 ;
V_161 . V_162 = & args ;
F_13 ( L_6 ,
V_139 , V_40 -> V_14 , & V_161 ) ;
va_end ( args ) ;
return - V_49 ;
}
static int F_122 ( const char * V_139 , struct V_3 * V_40 )
{
int V_47 = 0 ;
for (; V_40 -> V_14 ; V_40 ++ ) {
if ( V_40 -> V_4 )
V_47 = F_121 ( V_139 , V_40 , L_7 ) ;
if ( ( V_40 -> V_113 == V_163 ) ||
( V_40 -> V_113 == V_164 ) ||
( V_40 -> V_113 == V_165 ) ||
( V_40 -> V_113 == V_166 ) ||
( V_40 -> V_113 == V_167 ) ||
( V_40 -> V_113 == V_168 ) ||
( V_40 -> V_113 == V_169 ) ||
( V_40 -> V_113 == V_170 ) ||
( V_40 -> V_113 == V_171 ) ) {
if ( ! V_40 -> V_158 )
V_47 = F_121 ( V_139 , V_40 , L_8 ) ;
if ( ! V_40 -> V_172 )
V_47 = F_121 ( V_139 , V_40 , L_9 ) ;
}
if ( ! V_40 -> V_113 )
V_47 = F_121 ( V_139 , V_40 , L_10 ) ;
if ( ( V_40 -> V_63 & ( V_153 | V_173 ) ) != V_40 -> V_63 )
V_47 = F_121 ( V_139 , V_40 , L_11 ,
V_40 -> V_63 ) ;
}
return V_47 ;
}
static struct V_1 * F_123 ( struct V_6 * V_7 , struct V_3 * V_40 ,
struct V_37 * V_174 )
{
struct V_3 * V_175 , * V_24 , * V_176 ;
struct V_1 * V_177 ;
struct V_28 * V_26 ;
char * V_178 ;
int V_179 , V_180 ;
V_180 = 0 ;
V_179 = 0 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
V_179 ++ ;
V_180 += strlen ( V_24 -> V_14 ) + 1 ;
}
V_177 = F_118 ( sizeof( struct V_1 ) +
sizeof( struct V_28 ) * V_179 +
sizeof( struct V_3 ) * ( V_179 + 1 ) +
V_180 ,
V_152 ) ;
if ( ! V_177 )
return NULL ;
V_26 = (struct V_28 * ) ( V_177 + 1 ) ;
V_175 = (struct V_3 * ) ( V_26 + V_179 ) ;
V_178 = ( char * ) & V_175 [ V_179 + 1 ] ;
for ( V_176 = V_175 , V_24 = V_40 ; V_24 -> V_14 ; V_176 ++ , V_24 ++ ) {
int V_102 = strlen ( V_24 -> V_14 ) + 1 ;
memcpy ( V_178 , V_24 -> V_14 , V_102 ) ;
V_176 -> V_14 = V_178 ;
V_176 -> V_63 = V_181 | V_182 ;
V_176 -> V_158 = V_174 ;
V_178 += V_102 ;
}
F_18 ( V_177 , V_7 -> V_8 . V_27 , V_7 -> V_8 . V_39 , V_26 , V_175 ) ;
V_177 -> V_44 = V_179 ;
return V_177 ;
}
static bool F_124 ( struct V_6 * V_7 ,
struct V_3 * V_40 , struct V_37 * V_174 )
{
struct V_1 * V_2 ;
struct V_3 * V_24 , * V_176 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
const char * V_14 = V_24 -> V_14 ;
V_176 = F_10 ( & V_2 , V_7 , V_14 , strlen ( V_14 ) ) ;
if ( ! V_176 )
return false ;
if ( F_64 ( V_176 -> V_63 ) && F_64 ( V_24 -> V_63 ) )
continue;
if ( F_74 ( V_176 -> V_63 ) && ( V_176 -> V_158 == V_174 ) )
continue;
return false ;
}
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
const char * V_14 = V_24 -> V_14 ;
V_176 = F_10 ( & V_2 , V_7 , V_14 , strlen ( V_14 ) ) ;
V_2 -> V_44 ++ ;
}
return true ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_38 * V_183 = & V_95 . V_60 ;
struct V_6 * V_184 = NULL ;
struct V_1 * V_177 ;
int V_47 ;
if ( V_2 -> V_39 == V_183 )
return 0 ;
V_184 = F_120 ( V_183 , V_2 -> V_13 ) ;
if ( F_71 ( V_184 ) )
return 0 ;
if ( F_124 ( V_184 , V_2 -> V_3 , V_2 -> V_27 ) )
return 0 ;
V_184 -> V_8 . V_44 ++ ;
F_39 ( & V_58 ) ;
V_177 = F_123 ( V_184 , V_2 -> V_3 , V_2 -> V_27 ) ;
F_42 ( & V_58 ) ;
V_47 = - V_103 ;
if ( ! V_177 )
goto V_74;
V_47 = 0 ;
if ( F_124 ( V_184 , V_2 -> V_3 , V_2 -> V_27 ) ) {
F_125 ( V_177 ) ;
goto V_74;
}
V_47 = F_21 ( V_184 , V_177 ) ;
if ( V_47 )
F_125 ( V_177 ) ;
V_74:
F_25 ( & V_184 -> V_8 ) ;
return V_47 ;
}
struct V_1 * F_126 (
struct V_38 * V_39 ,
const char * V_139 , struct V_3 * V_40 )
{
struct V_37 * V_27 = V_39 -> V_7 . V_8 . V_27 ;
struct V_1 * V_8 ;
const char * V_22 , * V_185 ;
struct V_6 * V_7 ;
struct V_3 * V_24 ;
struct V_28 * V_26 ;
int V_179 = 0 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ )
V_179 ++ ;
V_8 = F_118 ( sizeof( struct V_1 ) +
sizeof( struct V_28 ) * V_179 , V_152 ) ;
if ( ! V_8 )
return NULL ;
V_26 = (struct V_28 * ) ( V_8 + 1 ) ;
F_18 ( V_8 , V_27 , V_39 , V_26 , V_40 ) ;
if ( F_122 ( V_139 , V_40 ) )
goto V_51;
F_42 ( & V_58 ) ;
V_7 = & V_39 -> V_7 ;
V_7 -> V_8 . V_44 ++ ;
F_39 ( & V_58 ) ;
for ( V_22 = V_139 ; V_22 ; V_22 = V_185 ) {
int V_23 ;
V_185 = strchr ( V_22 , '/' ) ;
if ( V_185 ) {
V_23 = V_185 - V_22 ;
V_185 ++ ;
} else {
V_23 = strlen ( V_22 ) ;
}
if ( V_23 == 0 )
continue;
V_7 = F_119 ( V_7 , V_22 , V_23 ) ;
if ( F_71 ( V_7 ) )
goto V_51;
}
F_42 ( & V_58 ) ;
if ( F_21 ( V_7 , V_8 ) )
goto V_186;
F_25 ( & V_7 -> V_8 ) ;
F_39 ( & V_58 ) ;
return V_8 ;
V_186:
F_25 ( & V_7 -> V_8 ) ;
F_39 ( & V_58 ) ;
V_51:
F_125 ( V_8 ) ;
F_127 () ;
return NULL ;
}
struct V_1 * F_128 ( const char * V_139 , struct V_3 * V_40 )
{
return F_126 ( & V_95 . V_60 ,
V_139 , V_40 ) ;
}
static char * F_129 ( const char * V_139 , char * V_130 , const char * V_22 )
{
int V_23 ;
V_23 = strlen ( V_22 ) ;
if ( ( ( V_130 - V_139 ) + V_23 + 2 ) >= V_187 )
return NULL ;
memcpy ( V_130 , V_22 , V_23 ) ;
V_130 [ V_23 ] = '/' ;
V_130 [ V_23 + 1 ] = '\0' ;
V_130 += V_23 + 1 ;
return V_130 ;
}
static int F_130 ( struct V_3 * V_40 )
{
int V_188 = 0 ;
int V_189 = 0 ;
struct V_3 * V_24 ;
if ( ! V_40 || ! V_40 -> V_14 )
return 1 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
if ( V_24 -> V_4 )
V_189 += F_130 ( V_24 -> V_4 ) ;
else
V_188 = 1 ;
}
return V_189 + V_188 ;
}
static int F_131 ( const char * V_139 , char * V_130 ,
struct V_1 * * * V_190 , struct V_38 * V_39 ,
struct V_3 * V_40 )
{
struct V_3 * V_41 = NULL ;
struct V_3 * V_24 , * V_191 ;
int V_192 = 0 ;
int V_193 = 0 ;
int V_47 = - V_103 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
if ( V_24 -> V_4 )
V_193 ++ ;
else
V_192 ++ ;
}
V_191 = V_40 ;
if ( V_193 && V_192 ) {
struct V_3 * V_150 ;
V_191 = F_118 ( sizeof( struct V_3 ) * ( V_192 + 1 ) ,
V_152 ) ;
if ( ! V_191 )
goto V_74;
V_41 = V_191 ;
for ( V_150 = V_191 , V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
if ( V_24 -> V_4 )
continue;
* V_150 = * V_24 ;
V_150 ++ ;
}
}
if ( V_192 || ! V_193 ) {
struct V_1 * V_8 ;
V_8 = F_126 ( V_39 , V_139 , V_191 ) ;
if ( ! V_8 ) {
F_125 ( V_41 ) ;
goto V_74;
}
V_8 -> V_41 = V_41 ;
* * V_190 = V_8 ;
( * V_190 ) ++ ;
}
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
char * V_194 ;
if ( ! V_24 -> V_4 )
continue;
V_47 = - V_195 ;
V_194 = F_129 ( V_139 , V_130 , V_24 -> V_14 ) ;
if ( ! V_194 )
goto V_74;
V_47 = F_131 ( V_139 , V_194 , V_190 ,
V_39 , V_24 -> V_4 ) ;
V_130 [ 0 ] = '\0' ;
if ( V_47 )
goto V_74;
}
V_47 = 0 ;
V_74:
return V_47 ;
}
struct V_1 * F_132 (
struct V_38 * V_39 ,
const struct V_196 * V_139 , struct V_3 * V_40 )
{
struct V_3 * V_41 = V_40 ;
int V_189 = F_130 ( V_40 ) ;
struct V_1 * V_8 = NULL , * * V_197 , * * V_190 ;
const struct V_196 * V_198 ;
char * V_199 , * V_130 ;
V_130 = V_199 = F_133 ( V_187 , V_152 ) ;
if ( ! V_199 )
return NULL ;
V_130 [ 0 ] = '\0' ;
for ( V_198 = V_139 ; V_198 -> V_14 ; V_198 ++ ) {
V_130 = F_129 ( V_199 , V_130 , V_198 -> V_14 ) ;
if ( ! V_130 )
goto V_74;
}
while ( V_40 -> V_14 && V_40 -> V_4 && ! V_40 [ 1 ] . V_14 ) {
V_130 = F_129 ( V_199 , V_130 , V_40 -> V_14 ) ;
if ( ! V_130 )
goto V_74;
V_40 = V_40 -> V_4 ;
}
if ( V_189 == 1 ) {
V_8 = F_126 ( V_39 , V_199 , V_40 ) ;
if ( V_8 )
V_8 -> V_41 = V_41 ;
} else {
V_8 = F_118 ( sizeof( * V_8 ) +
sizeof( * V_197 ) * V_189 , V_152 ) ;
if ( ! V_8 )
goto V_74;
V_197 = (struct V_1 * * ) ( V_8 + 1 ) ;
V_190 = V_197 ;
V_8 -> V_41 = V_41 ;
if ( F_131 ( V_199 , V_130 , & V_190 ,
V_39 , V_40 ) )
goto V_200;
}
V_74:
F_125 ( V_199 ) ;
return V_8 ;
V_200:
while ( V_190 > V_197 ) {
struct V_1 * V_201 = * ( -- V_190 ) ;
struct V_3 * V_40 = V_201 -> V_41 ;
F_134 ( V_201 ) ;
F_125 ( V_40 ) ;
}
F_125 ( V_8 ) ;
V_8 = NULL ;
goto V_74;
}
struct V_1 * F_135 ( const struct V_196 * V_139 ,
struct V_3 * V_40 )
{
return F_132 ( & V_95 . V_60 ,
V_139 , V_40 ) ;
}
struct V_1 * F_136 ( struct V_3 * V_40 )
{
static const struct V_196 V_202 [] = { {} } ;
return F_135 ( V_202 , V_40 ) ;
}
static void F_24 ( struct V_1 * V_8 )
{
struct V_38 * V_183 = & V_95 . V_60 ;
struct V_37 * V_27 = V_8 -> V_27 ;
struct V_6 * V_13 = V_8 -> V_13 ;
struct V_6 * V_184 ;
struct V_3 * V_24 ;
if ( V_8 -> V_39 == V_183 )
return;
V_184 = F_120 ( V_183 , V_13 ) ;
if ( F_71 ( V_184 ) )
return;
for ( V_24 = V_8 -> V_3 ; V_24 -> V_14 ; V_24 ++ ) {
struct V_1 * V_203 ;
struct V_3 * V_176 ;
const char * V_22 = V_24 -> V_14 ;
V_176 = F_10 ( & V_203 , V_184 , V_22 , strlen ( V_22 ) ) ;
if ( V_176 &&
( ( F_64 ( V_176 -> V_63 ) && F_64 ( V_24 -> V_63 ) ) ||
( F_74 ( V_176 -> V_63 ) && ( V_176 -> V_158 == V_27 ) ) ) ) {
F_25 ( V_203 ) ;
}
else {
F_13 ( L_12 ) ;
F_7 ( V_13 ) ;
F_8 ( L_3 , V_22 ) ;
}
}
}
static void F_25 ( struct V_1 * V_8 )
{
struct V_6 * V_13 = V_8 -> V_13 ;
if ( -- V_8 -> V_44 )
return;
F_24 ( V_8 ) ;
F_37 ( V_8 ) ;
if ( ! -- V_8 -> V_43 )
F_68 ( V_8 , V_94 ) ;
if ( V_13 )
F_25 ( & V_13 -> V_8 ) ;
}
void F_134 ( struct V_1 * V_8 )
{
int V_189 ;
F_137 () ;
if ( V_8 == NULL )
return;
V_189 = F_130 ( V_8 -> V_41 ) ;
if ( F_27 ( V_189 > 1 ) ) {
struct V_1 * * V_197 ;
int V_204 ;
V_197 = (struct V_1 * * ) ( V_8 + 1 ) ;
for ( V_204 = V_189 - 1 ; V_204 >= 0 ; V_204 -- ) {
struct V_1 * V_201 = V_197 [ V_204 ] ;
struct V_3 * V_40 = V_201 -> V_41 ;
F_134 ( V_201 ) ;
F_125 ( V_40 ) ;
}
F_125 ( V_8 ) ;
return;
}
F_42 ( & V_58 ) ;
F_25 ( V_8 ) ;
F_39 ( & V_58 ) ;
}
void F_138 ( struct V_38 * V_39 ,
struct V_37 * V_27 ,
int (* V_147)( struct V_38 * ) )
{
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_147 = V_147 ;
F_18 ( & V_39 -> V_7 . V_8 , V_27 , V_39 , NULL , V_205 ) ;
}
void F_139 ( struct V_38 * V_39 )
{
F_140 ( ! F_22 ( & V_39 -> V_7 . V_27 ) ) ;
}
int T_9 F_141 ( void )
{
struct V_206 * V_207 ;
V_207 = F_142 ( L_13 , NULL ) ;
V_207 -> V_208 = & V_89 ;
V_207 -> V_209 = & V_90 ;
V_207 -> V_210 = 0 ;
return F_143 () ;
}
