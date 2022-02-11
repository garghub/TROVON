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
struct V_52 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_26 ;
struct V_56 * V_57 ;
F_31 () ;
for (; ; ) {
V_26 = F_32 ( & V_2 -> V_46 ) ;
if ( ! V_26 )
break;
V_54 = F_33 ( V_26 , struct V_53 , V_58 ) ;
F_34 ( & V_59 ) ;
F_35 ( & V_54 -> V_58 ) ;
F_36 ( & V_59 ) ;
V_52 = & V_54 -> V_60 ;
V_57 = V_52 -> V_61 ;
if ( ! F_37 ( & V_57 -> V_62 ) )
continue;
V_52 = F_38 ( V_52 ) ;
F_39 () ;
if ( F_27 ( ! V_52 ) ) {
F_40 ( V_57 ) ;
F_31 () ;
continue;
}
F_41 ( V_52 ) ;
F_42 ( V_52 ) ;
F_40 ( V_57 ) ;
F_31 () ;
}
F_39 () ;
}
static void F_43 ( struct V_1 * V_31 )
{
if ( F_27 ( V_31 -> V_42 ) ) {
struct V_63 V_12 ;
F_44 ( & V_12 ) ;
V_31 -> V_45 = & V_12 ;
F_36 ( & V_59 ) ;
F_45 ( & V_12 ) ;
} else {
V_31 -> V_45 = F_46 ( - V_49 ) ;
F_36 ( & V_59 ) ;
}
F_30 ( V_31 ) ;
F_34 ( & V_59 ) ;
F_20 ( V_31 ) ;
}
static struct V_1 * F_47 ( struct V_1 * V_2 )
{
F_48 ( ! V_2 ) ;
F_34 ( & V_59 ) ;
if ( ! F_26 ( V_2 ) )
V_2 = F_46 ( - V_64 ) ;
F_36 ( & V_59 ) ;
return V_2 ;
}
static void F_49 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_34 ( & V_59 ) ;
F_28 ( V_2 ) ;
F_36 ( & V_59 ) ;
}
static struct V_38 *
F_50 ( struct V_37 * V_27 )
{
struct V_38 * V_39 = & V_27 -> V_65 ;
if ( V_27 -> V_66 )
V_39 = V_27 -> V_66 ( V_27 ) ;
return V_39 ;
}
static struct V_3 * F_51 ( struct V_1 * * V_21 ,
struct V_6 * V_7 ,
const char * V_22 , int V_23 )
{
struct V_1 * V_2 ;
struct V_3 * V_24 ;
F_34 ( & V_59 ) ;
V_24 = F_10 ( & V_2 , V_7 , V_22 , V_23 ) ;
if ( V_24 && F_26 ( V_2 ) )
* V_21 = V_2 ;
else
V_24 = NULL ;
F_36 ( & V_59 ) ;
return V_24 ;
}
static struct V_28 * F_52 ( struct V_25 * V_26 )
{
struct V_28 * V_28 ;
for (; V_26 ; V_26 = F_53 ( V_26 ) ) {
V_28 = F_11 ( V_26 , struct V_28 , V_26 ) ;
if ( F_26 ( V_28 -> V_8 ) )
return V_28 ;
}
return NULL ;
}
static void F_54 ( struct V_6 * V_7 ,
struct V_1 * * V_21 , struct V_3 * * V_67 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_24 = NULL ;
struct V_28 * V_28 ;
F_34 ( & V_59 ) ;
V_28 = F_52 ( F_55 ( & V_7 -> V_27 ) ) ;
F_36 ( & V_59 ) ;
if ( V_28 ) {
V_2 = V_28 -> V_8 ;
V_24 = & V_2 -> V_3 [ V_28 - V_2 -> V_26 ] ;
}
* V_21 = V_2 ;
* V_67 = V_24 ;
}
static void F_56 ( struct V_1 * * V_21 , struct V_3 * * V_67 )
{
struct V_1 * V_2 = * V_21 ;
struct V_3 * V_24 = * V_67 ;
struct V_28 * V_28 = & V_2 -> V_26 [ V_24 - V_2 -> V_3 ] ;
F_34 ( & V_59 ) ;
F_28 ( V_2 ) ;
V_28 = F_52 ( F_53 ( & V_28 -> V_26 ) ) ;
F_36 ( & V_59 ) ;
V_2 = NULL ;
if ( V_28 ) {
V_2 = V_28 -> V_8 ;
V_24 = & V_2 -> V_3 [ V_28 - V_2 -> V_26 ] ;
}
* V_21 = V_2 ;
* V_67 = V_24 ;
}
static int F_57 ( int V_68 , int V_69 )
{
if ( F_58 ( F_59 () , V_70 ) )
V_68 >>= 6 ;
else if ( F_60 ( V_71 ) )
V_68 >>= 3 ;
if ( ( V_69 & ~ V_68 & ( V_72 | V_73 | V_74 ) ) == 0 )
return 0 ;
return - V_75 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_3 * V_40 , int V_69 )
{
struct V_37 * V_27 = V_2 -> V_27 ;
int V_68 ;
if ( V_27 -> V_76 )
V_68 = V_27 -> V_76 ( V_2 , V_40 ) ;
else
V_68 = V_40 -> V_68 ;
return F_57 ( V_68 , V_69 ) ;
}
static struct V_52 * F_62 ( struct V_56 * V_57 ,
struct V_1 * V_2 , struct V_3 * V_40 )
{
struct V_37 * V_27 = V_2 -> V_27 ;
struct V_52 * V_52 ;
struct V_53 * V_54 ;
V_52 = F_63 ( V_57 ) ;
if ( ! V_52 )
goto V_77;
V_52 -> V_78 = F_64 () ;
V_54 = F_65 ( V_52 ) ;
F_34 ( & V_59 ) ;
if ( F_27 ( V_2 -> V_45 ) ) {
F_36 ( & V_59 ) ;
F_42 ( V_52 ) ;
V_52 = NULL ;
goto V_77;
}
V_54 -> V_79 = V_2 ;
V_54 -> V_80 = V_40 ;
F_66 ( & V_54 -> V_58 , & V_2 -> V_46 ) ;
V_2 -> V_43 ++ ;
F_36 ( & V_59 ) ;
V_52 -> V_81 = V_52 -> V_82 = V_52 -> V_83 = F_67 ( V_52 ) ;
V_52 -> V_84 = V_40 -> V_68 ;
if ( ! F_68 ( V_40 -> V_68 ) ) {
V_52 -> V_84 |= V_85 ;
V_52 -> V_86 = & V_87 ;
V_52 -> V_88 = & V_89 ;
} else {
V_52 -> V_84 |= V_90 ;
V_52 -> V_86 = & V_91 ;
V_52 -> V_88 = & V_92 ;
if ( F_1 ( V_2 ) )
F_69 ( V_52 ) ;
}
if ( V_27 -> V_93 )
V_27 -> V_93 ( V_2 , V_40 , & V_52 -> V_94 , & V_52 -> V_95 ) ;
V_77:
return V_52 ;
}
void F_70 ( struct V_52 * V_52 , struct V_1 * V_2 )
{
F_34 ( & V_59 ) ;
F_35 ( & F_65 ( V_52 ) -> V_58 ) ;
if ( ! -- V_2 -> V_43 )
F_71 ( V_2 , V_96 ) ;
F_36 ( & V_59 ) ;
}
static struct V_1 * F_72 ( struct V_52 * V_52 )
{
struct V_1 * V_2 = F_65 ( V_52 ) -> V_79 ;
if ( ! V_2 )
V_2 = & V_97 . V_65 . V_7 . V_8 ;
return F_47 ( V_2 ) ;
}
static struct V_98 * F_73 ( struct V_52 * V_7 , struct V_98 * V_98 ,
unsigned int V_99 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
struct V_1 * V_100 = NULL ;
const struct V_101 * V_22 = & V_98 -> V_102 ;
struct V_3 * V_31 ;
struct V_52 * V_52 ;
struct V_98 * V_47 = F_46 ( - V_64 ) ;
struct V_6 * V_6 ;
int V_103 ;
if ( F_74 ( V_2 ) )
return F_75 ( V_2 ) ;
V_6 = F_76 ( V_2 , struct V_6 , V_8 ) ;
V_31 = F_51 ( & V_100 , V_6 , V_22 -> V_22 , V_22 -> V_104 ) ;
if ( ! V_31 )
goto V_77;
if ( F_77 ( V_31 -> V_68 ) ) {
V_103 = F_78 ( & V_100 , & V_31 ) ;
V_47 = F_46 ( V_103 ) ;
if ( V_103 )
goto V_77;
}
V_47 = F_46 ( - V_105 ) ;
V_52 = F_62 ( V_7 -> V_61 , V_100 ? V_100 : V_2 , V_31 ) ;
if ( ! V_52 )
goto V_77;
V_47 = NULL ;
F_79 ( V_98 , & V_106 ) ;
F_80 ( V_98 , V_52 ) ;
V_77:
if ( V_100 )
F_49 ( V_100 ) ;
F_49 ( V_2 ) ;
return V_47 ;
}
static T_1 F_81 ( struct V_107 * V_108 , void T_2 * V_109 ,
T_3 V_43 , T_4 * V_110 , int V_111 )
{
struct V_52 * V_52 = F_82 ( V_108 ) ;
struct V_1 * V_2 = F_72 ( V_52 ) ;
struct V_3 * V_40 = F_65 ( V_52 ) -> V_80 ;
T_1 error ;
T_3 V_112 ;
if ( F_74 ( V_2 ) )
return F_83 ( V_2 ) ;
error = - V_113 ;
if ( F_61 ( V_2 , V_40 , V_111 ? V_73 : V_72 ) )
goto V_77;
error = - V_49 ;
if ( ! V_40 -> V_114 )
goto V_77;
V_112 = V_43 ;
error = V_40 -> V_114 ( V_40 , V_111 , V_109 , & V_112 , V_110 ) ;
if ( ! error )
error = V_112 ;
V_77:
F_49 ( V_2 ) ;
return error ;
}
static T_1 F_84 ( struct V_107 * V_108 , char T_2 * V_109 ,
T_3 V_43 , T_4 * V_110 )
{
return F_81 ( V_108 , ( void T_2 * ) V_109 , V_43 , V_110 , 0 ) ;
}
static T_1 F_85 ( struct V_107 * V_108 , const char T_2 * V_109 ,
T_3 V_43 , T_4 * V_110 )
{
return F_81 ( V_108 , ( void T_2 * ) V_109 , V_43 , V_110 , 1 ) ;
}
static int F_86 ( struct V_52 * V_52 , struct V_107 * V_108 )
{
struct V_1 * V_2 = F_72 ( V_52 ) ;
struct V_3 * V_40 = F_65 ( V_52 ) -> V_80 ;
if ( F_74 ( V_2 ) )
return F_83 ( V_2 ) ;
if ( V_40 -> V_10 )
V_108 -> V_115 = F_87 ( V_40 -> V_10 ) ;
F_49 ( V_2 ) ;
return 0 ;
}
static unsigned int F_88 ( struct V_107 * V_108 , T_5 * V_12 )
{
struct V_52 * V_52 = F_82 ( V_108 ) ;
struct V_1 * V_2 = F_72 ( V_52 ) ;
struct V_3 * V_40 = F_65 ( V_52 ) -> V_80 ;
unsigned int V_103 = V_116 ;
unsigned long V_11 ;
if ( F_74 ( V_2 ) )
return V_117 | V_118 ;
if ( ! V_40 -> V_114 )
goto V_77;
if ( ! V_40 -> V_10 )
goto V_77;
V_11 = ( unsigned long ) V_108 -> V_115 ;
F_89 ( V_108 , & V_40 -> V_10 -> V_12 , V_12 ) ;
if ( V_11 != F_90 ( & V_40 -> V_10 -> V_11 ) ) {
V_108 -> V_115 = F_87 ( V_40 -> V_10 ) ;
V_103 = V_119 | V_120 | V_117 | V_121 ;
}
V_77:
F_49 ( V_2 ) ;
return V_103 ;
}
static bool F_91 ( struct V_107 * V_107 ,
struct V_122 * V_123 ,
struct V_1 * V_2 ,
struct V_3 * V_40 )
{
struct V_98 * V_4 , * V_7 = V_107 -> V_124 . V_98 ;
struct V_52 * V_52 ;
struct V_101 V_125 ;
T_6 V_126 = 0 ;
unsigned type = V_127 ;
V_125 . V_22 = V_40 -> V_14 ;
V_125 . V_104 = strlen ( V_40 -> V_14 ) ;
V_125 . V_128 = F_92 ( V_7 , V_125 . V_22 , V_125 . V_104 ) ;
V_4 = F_93 ( V_7 , & V_125 ) ;
if ( ! V_4 ) {
F_94 ( V_129 ) ;
V_4 = F_95 ( V_7 , & V_125 , & V_129 ) ;
if ( F_74 ( V_4 ) )
return false ;
if ( F_96 ( V_4 ) ) {
V_52 = F_62 ( V_7 -> V_130 , V_2 , V_40 ) ;
if ( ! V_52 ) {
F_97 ( V_4 ) ;
F_98 ( V_4 ) ;
return false ;
}
F_79 ( V_4 , & V_106 ) ;
F_80 ( V_4 , V_52 ) ;
}
}
V_52 = F_99 ( V_4 ) ;
V_126 = V_52 -> V_78 ;
type = V_52 -> V_84 >> 12 ;
F_98 ( V_4 ) ;
return F_100 ( V_123 , V_125 . V_22 , V_125 . V_104 , V_126 , type ) ;
}
static bool F_101 ( struct V_107 * V_107 ,
struct V_122 * V_123 ,
struct V_1 * V_2 ,
struct V_3 * V_40 )
{
bool V_103 = true ;
V_2 = F_47 ( V_2 ) ;
if ( F_77 ( V_40 -> V_68 ) ) {
int V_47 = F_78 ( & V_2 , & V_40 ) ;
if ( V_47 )
goto V_77;
}
V_103 = F_91 ( V_107 , V_123 , V_2 , V_40 ) ;
V_77:
F_49 ( V_2 ) ;
return V_103 ;
}
static int F_102 ( struct V_1 * V_2 , struct V_3 * V_40 ,
unsigned long * V_131 , struct V_107 * V_107 ,
struct V_122 * V_123 )
{
bool V_112 ;
if ( ( * V_131 ) ++ < V_123 -> V_131 )
return true ;
if ( F_27 ( F_77 ( V_40 -> V_68 ) ) )
V_112 = F_101 ( V_107 , V_123 , V_2 , V_40 ) ;
else
V_112 = F_91 ( V_107 , V_123 , V_2 , V_40 ) ;
if ( V_112 )
V_123 -> V_131 = * V_131 ;
return V_112 ;
}
static int F_103 ( struct V_107 * V_107 , struct V_122 * V_123 )
{
struct V_1 * V_2 = F_72 ( F_82 ( V_107 ) ) ;
struct V_1 * V_100 = NULL ;
struct V_3 * V_24 ;
struct V_6 * V_6 ;
unsigned long V_131 ;
if ( F_74 ( V_2 ) )
return F_83 ( V_2 ) ;
V_6 = F_76 ( V_2 , struct V_6 , V_8 ) ;
if ( ! F_104 ( V_107 , V_123 ) )
goto V_77;
V_131 = 2 ;
for ( F_54 ( V_6 , & V_100 , & V_24 ) ; V_100 ; F_56 ( & V_100 , & V_24 ) ) {
if ( ! F_102 ( V_100 , V_24 , & V_131 , V_107 , V_123 ) ) {
F_49 ( V_100 ) ;
break;
}
}
V_77:
F_49 ( V_2 ) ;
return 0 ;
}
static int F_105 ( struct V_52 * V_52 , int V_132 )
{
struct V_1 * V_2 ;
struct V_3 * V_40 ;
int error ;
if ( ( V_132 & V_74 ) && F_106 ( V_52 -> V_84 ) )
return - V_75 ;
V_2 = F_72 ( V_52 ) ;
if ( F_74 ( V_2 ) )
return F_83 ( V_2 ) ;
V_40 = F_65 ( V_52 ) -> V_80 ;
if ( ! V_40 )
error = V_132 & V_73 ? - V_75 : 0 ;
else
error = F_61 ( V_2 , V_40 , V_132 & ~ V_133 ) ;
F_49 ( V_2 ) ;
return error ;
}
static int F_107 ( struct V_98 * V_98 , struct V_134 * V_135 )
{
struct V_52 * V_52 = F_99 ( V_98 ) ;
int error ;
if ( V_135 -> V_136 & ( V_137 | V_138 | V_139 ) )
return - V_113 ;
error = F_108 ( V_98 , V_135 ) ;
if ( error )
return error ;
F_109 ( V_52 , V_135 ) ;
F_110 ( V_52 ) ;
return 0 ;
}
static int F_111 ( const struct V_140 * V_140 , struct V_141 * V_142 ,
T_7 V_143 , unsigned int V_144 )
{
struct V_52 * V_52 = F_99 ( V_140 -> V_98 ) ;
struct V_1 * V_2 = F_72 ( V_52 ) ;
struct V_3 * V_40 = F_65 ( V_52 ) -> V_80 ;
if ( F_74 ( V_2 ) )
return F_83 ( V_2 ) ;
F_112 ( V_52 , V_142 ) ;
if ( V_40 )
V_142 -> V_68 = ( V_142 -> V_68 & V_145 ) | V_40 -> V_68 ;
F_49 ( V_2 ) ;
return 0 ;
}
static int F_113 ( struct V_98 * V_98 , unsigned int V_99 )
{
if ( V_99 & V_146 )
return - V_147 ;
return ! F_65 ( F_99 ( V_98 ) ) -> V_79 -> V_45 ;
}
static int F_114 ( const struct V_98 * V_98 )
{
return ! ! F_65 ( F_99 ( V_98 ) ) -> V_79 -> V_45 ;
}
static int F_115 ( struct V_1 * V_31 )
{
struct V_38 * V_39 = V_31 -> V_39 ;
int V_112 ;
F_34 ( & V_59 ) ;
if ( V_31 -> V_45 )
V_112 = 0 ;
else if ( ! V_39 -> V_148 )
V_112 = 1 ;
else
V_112 = V_39 -> V_148 ( V_39 ) ;
F_36 ( & V_59 ) ;
return V_112 ;
}
static int F_116 ( const struct V_98 * V_98 ,
unsigned int V_104 , const char * V_149 , const struct V_101 * V_22 )
{
struct V_1 * V_2 ;
struct V_52 * V_52 ;
V_52 = F_117 ( V_98 ) ;
if ( ! V_52 )
return 1 ;
if ( V_22 -> V_104 != V_104 )
return 1 ;
if ( memcmp ( V_22 -> V_22 , V_149 , V_104 ) )
return 1 ;
V_2 = F_118 ( F_65 ( V_52 ) -> V_79 ) ;
return ! V_2 || ! F_115 ( V_2 ) ;
}
static struct V_6 * F_119 ( struct V_6 * V_7 ,
const char * V_22 , int V_23 )
{
struct V_1 * V_2 ;
struct V_3 * V_24 ;
V_24 = F_10 ( & V_2 , V_7 , V_22 , V_23 ) ;
if ( ! V_24 )
return F_46 ( - V_64 ) ;
if ( ! F_68 ( V_24 -> V_68 ) )
return F_46 ( - V_150 ) ;
return F_76 ( V_2 , struct V_6 , V_8 ) ;
}
static struct V_6 * F_120 ( struct V_38 * V_39 ,
const char * V_22 , int V_23 )
{
struct V_3 * V_40 ;
struct V_6 * V_151 ;
struct V_28 * V_26 ;
char * V_152 ;
V_151 = F_121 ( sizeof( * V_151 ) + sizeof( struct V_28 ) +
sizeof( struct V_3 ) * 2 + V_23 + 1 ,
V_153 ) ;
if ( ! V_151 )
return NULL ;
V_26 = (struct V_28 * ) ( V_151 + 1 ) ;
V_40 = (struct V_3 * ) ( V_26 + 1 ) ;
V_152 = ( char * ) ( V_40 + 2 ) ;
memcpy ( V_152 , V_22 , V_23 ) ;
V_152 [ V_23 ] = '\0' ;
V_40 [ 0 ] . V_14 = V_152 ;
V_40 [ 0 ] . V_68 = V_90 | V_154 | V_155 ;
F_18 ( & V_151 -> V_8 , V_39 -> V_7 . V_8 . V_27 , V_39 , V_26 , V_40 ) ;
return V_151 ;
}
static struct V_6 * F_122 ( struct V_6 * V_7 ,
const char * V_22 , int V_23 )
{
struct V_38 * V_39 = V_7 -> V_8 . V_39 ;
struct V_6 * V_156 , * V_151 = NULL ;
int V_47 ;
F_34 ( & V_59 ) ;
V_156 = F_119 ( V_7 , V_22 , V_23 ) ;
if ( ! F_74 ( V_156 ) )
goto V_157;
if ( F_83 ( V_156 ) != - V_64 )
goto V_158;
F_36 ( & V_59 ) ;
V_151 = F_120 ( V_39 , V_22 , V_23 ) ;
F_34 ( & V_59 ) ;
V_156 = F_46 ( - V_105 ) ;
if ( ! V_151 )
goto V_158;
V_156 = F_119 ( V_7 , V_22 , V_23 ) ;
if ( ! F_74 ( V_156 ) )
goto V_157;
if ( F_83 ( V_156 ) != - V_64 )
goto V_158;
V_47 = F_21 ( V_7 , & V_151 -> V_8 ) ;
V_156 = F_46 ( V_47 ) ;
if ( V_47 )
goto V_158;
V_156 = V_151 ;
V_157:
V_156 -> V_8 . V_44 ++ ;
V_158:
if ( F_74 ( V_156 ) ) {
F_13 ( L_4 ) ;
F_7 ( V_7 ) ;
F_8 ( L_5 ,
V_23 , V_23 , V_22 , F_83 ( V_156 ) ) ;
}
F_25 ( & V_7 -> V_8 ) ;
if ( V_151 )
F_25 ( & V_151 -> V_8 ) ;
F_36 ( & V_59 ) ;
return V_156 ;
}
static struct V_6 * F_123 ( struct V_38 * V_39 , struct V_6 * V_7 )
{
struct V_6 * V_13 ;
const char * V_14 ;
if ( ! V_7 -> V_8 . V_13 )
return & V_39 -> V_7 ;
V_13 = F_123 ( V_39 , V_7 -> V_8 . V_13 ) ;
if ( F_74 ( V_13 ) )
return V_13 ;
V_14 = V_7 -> V_8 . V_3 [ 0 ] . V_14 ;
return F_119 ( V_13 , V_14 , strlen ( V_14 ) ) ;
}
static int F_78 ( struct V_1 * * V_21 ,
struct V_3 * * V_67 )
{
struct V_1 * V_2 ;
struct V_37 * V_27 ;
struct V_38 * V_39 ;
struct V_3 * V_24 ;
struct V_6 * V_7 ;
int V_103 ;
V_103 = 0 ;
F_34 ( & V_59 ) ;
V_27 = ( * V_67 ) -> V_159 ;
V_39 = F_50 ( V_27 ) ;
V_7 = F_123 ( V_39 , ( * V_21 ) -> V_13 ) ;
if ( F_74 ( V_7 ) )
V_103 = F_83 ( V_7 ) ;
else {
const char * V_14 = ( * V_67 ) -> V_14 ;
V_2 = NULL ;
V_24 = F_10 ( & V_2 , V_7 , V_14 , strlen ( V_14 ) ) ;
V_103 = - V_64 ;
if ( V_24 && F_26 ( V_2 ) ) {
F_28 ( * V_21 ) ;
* V_21 = V_2 ;
* V_67 = V_24 ;
V_103 = 0 ;
}
}
F_36 ( & V_59 ) ;
return V_103 ;
}
static int F_124 ( const char * V_140 , struct V_3 * V_40 , char * V_160 , ... )
{
struct V_161 V_162 ;
T_8 args ;
va_start ( args , V_160 ) ;
V_162 . V_160 = V_160 ;
V_162 . V_163 = & args ;
F_13 ( L_6 ,
V_140 , V_40 -> V_14 , & V_162 ) ;
va_end ( args ) ;
return - V_49 ;
}
static int F_125 ( const char * V_140 , struct V_3 * V_40 )
{
int V_47 = 0 ;
if ( ( V_40 -> V_114 == V_164 ) ||
( V_40 -> V_114 == V_165 ) ) {
if ( V_40 -> V_166 != sizeof( unsigned int ) )
V_47 |= F_124 ( V_140 , V_40 , L_7 ) ;
}
return V_47 ;
}
static int F_126 ( const char * V_140 , struct V_3 * V_40 )
{
int V_47 = 0 ;
for (; V_40 -> V_14 ; V_40 ++ ) {
if ( V_40 -> V_4 )
V_47 |= F_124 ( V_140 , V_40 , L_8 ) ;
if ( ( V_40 -> V_114 == V_167 ) ||
( V_40 -> V_114 == V_168 ) ||
( V_40 -> V_114 == V_164 ) ||
( V_40 -> V_114 == V_165 ) ||
( V_40 -> V_114 == V_169 ) ||
( V_40 -> V_114 == V_170 ) ||
( V_40 -> V_114 == V_171 ) ||
( V_40 -> V_114 == V_172 ) ||
( V_40 -> V_114 == V_173 ) ||
( V_40 -> V_114 == V_174 ) ) {
if ( ! V_40 -> V_159 )
V_47 |= F_124 ( V_140 , V_40 , L_9 ) ;
if ( ! V_40 -> V_166 )
V_47 |= F_124 ( V_140 , V_40 , L_10 ) ;
else
V_47 |= F_125 ( V_140 , V_40 ) ;
}
if ( ! V_40 -> V_114 )
V_47 |= F_124 ( V_140 , V_40 , L_11 ) ;
if ( ( V_40 -> V_68 & ( V_154 | V_175 ) ) != V_40 -> V_68 )
V_47 |= F_124 ( V_140 , V_40 , L_12 ,
V_40 -> V_68 ) ;
}
return V_47 ;
}
static struct V_1 * F_127 ( struct V_6 * V_7 , struct V_3 * V_40 ,
struct V_37 * V_176 )
{
struct V_3 * V_177 , * V_24 , * V_178 ;
struct V_1 * V_179 ;
struct V_28 * V_26 ;
char * V_180 ;
int V_181 , V_182 ;
V_182 = 0 ;
V_181 = 0 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
V_181 ++ ;
V_182 += strlen ( V_24 -> V_14 ) + 1 ;
}
V_179 = F_121 ( sizeof( struct V_1 ) +
sizeof( struct V_28 ) * V_181 +
sizeof( struct V_3 ) * ( V_181 + 1 ) +
V_182 ,
V_153 ) ;
if ( ! V_179 )
return NULL ;
V_26 = (struct V_28 * ) ( V_179 + 1 ) ;
V_177 = (struct V_3 * ) ( V_26 + V_181 ) ;
V_180 = ( char * ) & V_177 [ V_181 + 1 ] ;
for ( V_178 = V_177 , V_24 = V_40 ; V_24 -> V_14 ; V_178 ++ , V_24 ++ ) {
int V_104 = strlen ( V_24 -> V_14 ) + 1 ;
memcpy ( V_180 , V_24 -> V_14 , V_104 ) ;
V_178 -> V_14 = V_180 ;
V_178 -> V_68 = V_183 | V_184 ;
V_178 -> V_159 = V_176 ;
V_180 += V_104 ;
}
F_18 ( V_179 , V_7 -> V_8 . V_27 , V_7 -> V_8 . V_39 , V_26 , V_177 ) ;
V_179 -> V_44 = V_181 ;
return V_179 ;
}
static bool F_128 ( struct V_6 * V_7 ,
struct V_3 * V_40 , struct V_37 * V_176 )
{
struct V_1 * V_2 ;
struct V_3 * V_24 , * V_178 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
const char * V_14 = V_24 -> V_14 ;
V_178 = F_10 ( & V_2 , V_7 , V_14 , strlen ( V_14 ) ) ;
if ( ! V_178 )
return false ;
if ( F_68 ( V_178 -> V_68 ) && F_68 ( V_24 -> V_68 ) )
continue;
if ( F_77 ( V_178 -> V_68 ) && ( V_178 -> V_159 == V_176 ) )
continue;
return false ;
}
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
const char * V_14 = V_24 -> V_14 ;
V_178 = F_10 ( & V_2 , V_7 , V_14 , strlen ( V_14 ) ) ;
V_2 -> V_44 ++ ;
}
return true ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_38 * V_185 = & V_97 . V_65 ;
struct V_6 * V_186 = NULL ;
struct V_1 * V_179 ;
int V_47 ;
if ( V_2 -> V_39 == V_185 )
return 0 ;
V_186 = F_123 ( V_185 , V_2 -> V_13 ) ;
if ( F_74 ( V_186 ) )
return 0 ;
if ( F_128 ( V_186 , V_2 -> V_3 , V_2 -> V_27 ) )
return 0 ;
V_186 -> V_8 . V_44 ++ ;
F_36 ( & V_59 ) ;
V_179 = F_127 ( V_186 , V_2 -> V_3 , V_2 -> V_27 ) ;
F_34 ( & V_59 ) ;
V_47 = - V_105 ;
if ( ! V_179 )
goto V_77;
V_47 = 0 ;
if ( F_128 ( V_186 , V_2 -> V_3 , V_2 -> V_27 ) ) {
F_129 ( V_179 ) ;
goto V_77;
}
V_47 = F_21 ( V_186 , V_179 ) ;
if ( V_47 )
F_129 ( V_179 ) ;
V_77:
F_25 ( & V_186 -> V_8 ) ;
return V_47 ;
}
struct V_1 * F_130 (
struct V_38 * V_39 ,
const char * V_140 , struct V_3 * V_40 )
{
struct V_37 * V_27 = V_39 -> V_7 . V_8 . V_27 ;
struct V_1 * V_8 ;
const char * V_22 , * V_187 ;
struct V_6 * V_7 ;
struct V_3 * V_24 ;
struct V_28 * V_26 ;
int V_181 = 0 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ )
V_181 ++ ;
V_8 = F_121 ( sizeof( struct V_1 ) +
sizeof( struct V_28 ) * V_181 , V_153 ) ;
if ( ! V_8 )
return NULL ;
V_26 = (struct V_28 * ) ( V_8 + 1 ) ;
F_18 ( V_8 , V_27 , V_39 , V_26 , V_40 ) ;
if ( F_126 ( V_140 , V_40 ) )
goto V_51;
F_34 ( & V_59 ) ;
V_7 = & V_39 -> V_7 ;
V_7 -> V_8 . V_44 ++ ;
F_36 ( & V_59 ) ;
for ( V_22 = V_140 ; V_22 ; V_22 = V_187 ) {
int V_23 ;
V_187 = strchr ( V_22 , '/' ) ;
if ( V_187 ) {
V_23 = V_187 - V_22 ;
V_187 ++ ;
} else {
V_23 = strlen ( V_22 ) ;
}
if ( V_23 == 0 )
continue;
V_7 = F_122 ( V_7 , V_22 , V_23 ) ;
if ( F_74 ( V_7 ) )
goto V_51;
}
F_34 ( & V_59 ) ;
if ( F_21 ( V_7 , V_8 ) )
goto V_188;
F_25 ( & V_7 -> V_8 ) ;
F_36 ( & V_59 ) ;
return V_8 ;
V_188:
F_25 ( & V_7 -> V_8 ) ;
F_36 ( & V_59 ) ;
V_51:
F_129 ( V_8 ) ;
F_131 () ;
return NULL ;
}
struct V_1 * F_132 ( const char * V_140 , struct V_3 * V_40 )
{
return F_130 ( & V_97 . V_65 ,
V_140 , V_40 ) ;
}
static char * F_133 ( const char * V_140 , char * V_131 , const char * V_22 )
{
int V_23 ;
V_23 = strlen ( V_22 ) ;
if ( ( ( V_131 - V_140 ) + V_23 + 2 ) >= V_189 )
return NULL ;
memcpy ( V_131 , V_22 , V_23 ) ;
V_131 [ V_23 ] = '/' ;
V_131 [ V_23 + 1 ] = '\0' ;
V_131 += V_23 + 1 ;
return V_131 ;
}
static int F_134 ( struct V_3 * V_40 )
{
int V_190 = 0 ;
int V_191 = 0 ;
struct V_3 * V_24 ;
if ( ! V_40 || ! V_40 -> V_14 )
return 1 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
if ( V_24 -> V_4 )
V_191 += F_134 ( V_24 -> V_4 ) ;
else
V_190 = 1 ;
}
return V_191 + V_190 ;
}
static int F_135 ( const char * V_140 , char * V_131 ,
struct V_1 * * * V_192 , struct V_38 * V_39 ,
struct V_3 * V_40 )
{
struct V_3 * V_41 = NULL ;
struct V_3 * V_24 , * V_193 ;
int V_194 = 0 ;
int V_195 = 0 ;
int V_47 = - V_105 ;
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
if ( V_24 -> V_4 )
V_195 ++ ;
else
V_194 ++ ;
}
V_193 = V_40 ;
if ( V_195 && V_194 ) {
struct V_3 * V_151 ;
V_193 = F_121 ( sizeof( struct V_3 ) * ( V_194 + 1 ) ,
V_153 ) ;
if ( ! V_193 )
goto V_77;
V_41 = V_193 ;
for ( V_151 = V_193 , V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
if ( V_24 -> V_4 )
continue;
* V_151 = * V_24 ;
V_151 ++ ;
}
}
if ( V_194 || ! V_195 ) {
struct V_1 * V_8 ;
V_8 = F_130 ( V_39 , V_140 , V_193 ) ;
if ( ! V_8 ) {
F_129 ( V_41 ) ;
goto V_77;
}
V_8 -> V_41 = V_41 ;
* * V_192 = V_8 ;
( * V_192 ) ++ ;
}
for ( V_24 = V_40 ; V_24 -> V_14 ; V_24 ++ ) {
char * V_196 ;
if ( ! V_24 -> V_4 )
continue;
V_47 = - V_197 ;
V_196 = F_133 ( V_140 , V_131 , V_24 -> V_14 ) ;
if ( ! V_196 )
goto V_77;
V_47 = F_135 ( V_140 , V_196 , V_192 ,
V_39 , V_24 -> V_4 ) ;
V_131 [ 0 ] = '\0' ;
if ( V_47 )
goto V_77;
}
V_47 = 0 ;
V_77:
return V_47 ;
}
struct V_1 * F_136 (
struct V_38 * V_39 ,
const struct V_198 * V_140 , struct V_3 * V_40 )
{
struct V_3 * V_41 = V_40 ;
int V_191 = F_134 ( V_40 ) ;
struct V_1 * V_8 = NULL , * * V_199 , * * V_192 ;
const struct V_198 * V_200 ;
char * V_201 , * V_131 ;
V_131 = V_201 = F_137 ( V_189 , V_153 ) ;
if ( ! V_201 )
return NULL ;
V_131 [ 0 ] = '\0' ;
for ( V_200 = V_140 ; V_200 -> V_14 ; V_200 ++ ) {
V_131 = F_133 ( V_201 , V_131 , V_200 -> V_14 ) ;
if ( ! V_131 )
goto V_77;
}
while ( V_40 -> V_14 && V_40 -> V_4 && ! V_40 [ 1 ] . V_14 ) {
V_131 = F_133 ( V_201 , V_131 , V_40 -> V_14 ) ;
if ( ! V_131 )
goto V_77;
V_40 = V_40 -> V_4 ;
}
if ( V_191 == 1 ) {
V_8 = F_130 ( V_39 , V_201 , V_40 ) ;
if ( V_8 )
V_8 -> V_41 = V_41 ;
} else {
V_8 = F_121 ( sizeof( * V_8 ) +
sizeof( * V_199 ) * V_191 , V_153 ) ;
if ( ! V_8 )
goto V_77;
V_199 = (struct V_1 * * ) ( V_8 + 1 ) ;
V_192 = V_199 ;
V_8 -> V_41 = V_41 ;
if ( F_135 ( V_201 , V_131 , & V_192 ,
V_39 , V_40 ) )
goto V_202;
}
V_77:
F_129 ( V_201 ) ;
return V_8 ;
V_202:
while ( V_192 > V_199 ) {
struct V_1 * V_203 = * ( -- V_192 ) ;
struct V_3 * V_40 = V_203 -> V_41 ;
F_138 ( V_203 ) ;
F_129 ( V_40 ) ;
}
F_129 ( V_8 ) ;
V_8 = NULL ;
goto V_77;
}
struct V_1 * F_139 ( const struct V_198 * V_140 ,
struct V_3 * V_40 )
{
return F_136 ( & V_97 . V_65 ,
V_140 , V_40 ) ;
}
struct V_1 * F_140 ( struct V_3 * V_40 )
{
static const struct V_198 V_204 [] = { {} } ;
return F_139 ( V_204 , V_40 ) ;
}
static void F_24 ( struct V_1 * V_8 )
{
struct V_38 * V_185 = & V_97 . V_65 ;
struct V_37 * V_27 = V_8 -> V_27 ;
struct V_6 * V_13 = V_8 -> V_13 ;
struct V_6 * V_186 ;
struct V_3 * V_24 ;
if ( V_8 -> V_39 == V_185 )
return;
V_186 = F_123 ( V_185 , V_13 ) ;
if ( F_74 ( V_186 ) )
return;
for ( V_24 = V_8 -> V_3 ; V_24 -> V_14 ; V_24 ++ ) {
struct V_1 * V_205 ;
struct V_3 * V_178 ;
const char * V_22 = V_24 -> V_14 ;
V_178 = F_10 ( & V_205 , V_186 , V_22 , strlen ( V_22 ) ) ;
if ( V_178 &&
( ( F_68 ( V_178 -> V_68 ) && F_68 ( V_24 -> V_68 ) ) ||
( F_77 ( V_178 -> V_68 ) && ( V_178 -> V_159 == V_27 ) ) ) ) {
F_25 ( V_205 ) ;
}
else {
F_13 ( L_13 ) ;
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
F_43 ( V_8 ) ;
if ( ! -- V_8 -> V_43 )
F_71 ( V_8 , V_96 ) ;
if ( V_13 )
F_25 ( & V_13 -> V_8 ) ;
}
void F_138 ( struct V_1 * V_8 )
{
int V_191 ;
F_141 () ;
if ( V_8 == NULL )
return;
V_191 = F_134 ( V_8 -> V_41 ) ;
if ( F_27 ( V_191 > 1 ) ) {
struct V_1 * * V_199 ;
int V_206 ;
V_199 = (struct V_1 * * ) ( V_8 + 1 ) ;
for ( V_206 = V_191 - 1 ; V_206 >= 0 ; V_206 -- ) {
struct V_1 * V_203 = V_199 [ V_206 ] ;
struct V_3 * V_40 = V_203 -> V_41 ;
F_138 ( V_203 ) ;
F_129 ( V_40 ) ;
}
F_129 ( V_8 ) ;
return;
}
F_34 ( & V_59 ) ;
F_25 ( V_8 ) ;
F_36 ( & V_59 ) ;
}
void F_142 ( struct V_38 * V_39 ,
struct V_37 * V_27 ,
int (* V_148)( struct V_38 * ) )
{
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_148 = V_148 ;
F_18 ( & V_39 -> V_7 . V_8 , V_27 , V_39 , NULL , V_207 ) ;
}
void F_143 ( struct V_38 * V_39 )
{
F_144 ( ! F_22 ( & V_39 -> V_7 . V_27 ) ) ;
}
int T_9 F_145 ( void )
{
struct V_208 * V_209 ;
V_209 = F_146 ( L_14 , NULL ) ;
V_209 -> V_210 = & V_91 ;
V_209 -> V_211 = & V_92 ;
V_209 -> V_212 = 0 ;
return F_147 () ;
}
